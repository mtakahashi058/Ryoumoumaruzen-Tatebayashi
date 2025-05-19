//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "QRLabelFrm.h"
#include "MainFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
	// データベース接続
	DM->ADOConnection->Connected = false;
	try{
		DM->ADOConnection->Connected = true;
		DM->Q_List->Open();
	}catch (Exception& e){
		Application->MessageBox("データベース接続に失敗しました。", "エラー", MB_OK | MB_ICONSTOP);
		Application->MessageBox(e.Message.c_str(), "エラー", MB_OK | MB_ICONSTOP);
		Close();
	}

	TokuList = new TStringList();

	// 外部プログラムからパラメータ呼出
	if (ParamCount() > 0)
		TokuList->CommaText = ParamStr(1);

	CheckListBox->Items->Clear();
	while (!DM->Q_List->Eof){
		CheckListBox->Items->Append(DM->Q_List->FieldByName("固定長コード名称")->AsString);
		if (TokuList->IndexOf(DM->Q_List->FieldByName("コード")->AsString) != -1)	// パラメータとして渡された中に該当コードがあったらチェックを入れる
			CheckListBox->Checked[CheckListBox->Items->Count - 1] = true;
		DM->Q_List->Next();
	}

	cedtCode->Text = "";
	cedtCode->SetFocus();
}
//---------------------------------------------------------------------------
// 印刷
void __fastcall TMainForm::btnPrintClick(TObject *Sender)
{
	if (!SetRange())
		return;
	if (Application->MessageBox("ラベル用紙をセットして下さい\r\n準備ができたら「OK」を押して下さい", "ラベル印刷", MB_OKCANCEL | MB_ICONINFORMATION) != IDOK)
		return;
	QRLabelForm->QuickRep->Print();
}
//---------------------------------------------------------------------------
// プレビュー
void __fastcall TMainForm::btnPreviewClick(TObject *Sender)
{
	if (!SetRange())
		return;
	QRLabelForm->QuickRep->Preview();
}
//---------------------------------------------------------------------------
// 一時テーブルをセット
bool __fastcall TMainForm::SetRange()
{
	QRLabelForm->Q_Label->Close();

	// 一時テーブル削除
	try{
		DM->DBI.Execute("DROP TABLE #LABEL");
	}catch (...){
	}

	// 一時テーブルを作成
	if (TokuList->CommaText == AnsiString()){
		Application->MessageBox("出力する得意先を選択してください", Caption.c_str(), MB_OK | MB_ICONEXCLAMATION);
		return false;
	}
	DM->Q_CreateLabel->SQL->Strings[12] = "	得意先コード IN (" + TokuList->CommaText + ")";
	DM->Q_CreateLabel->ExecSQL();

	// 印字開始位置
	int add_cnt = cbRetu->ItemIndex * 7 + cbGyo->ItemIndex;
	for (int i = 0; i < add_cnt; i++)
		DM->DBI.Execute("INSERT INTO #LABEL VALUES(0, NULL, NULL, NULL, NULL, NULL)"); 

	QRLabelForm->Q_Label->Open();

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::btnCloseClick(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------
// チェックリストボックス->OnClick
void __fastcall TMainForm::CheckListBoxClick(TObject *Sender)
{
	if (CheckListBox->Checked[CheckListBox->ItemIndex])
		TokuList->Append(CheckListBox->Items->Strings[CheckListBox->ItemIndex].SubString(1, 5).Trim());
	else{
		try{
			TokuList->Delete(TokuList->IndexOf(CheckListBox->Items->Strings[CheckListBox->ItemIndex].SubString(1, 5).Trim()));
		}catch (...){
		}
	}
}
//---------------------------------------------------------------------------
// すべて選択
void __fastcall TMainForm::btnAllClick(TObject *Sender)
{
	for (int i = 0; i < CheckListBox->Items->Count; i++)
		CheckListBox->Checked[i] = true;

	TokuList->Clear();
	DM->Q_List->First();
	while (!DM->Q_List->Eof){
		TokuList->Append(DM->Q_List->FieldByName("コード")->AsString);
		DM->Q_List->Next();
	}
}
//---------------------------------------------------------------------------
// すべて選択解除
void __fastcall TMainForm::btnNoneClick(TObject *Sender)
{
	for (int i = 0; i < CheckListBox->Items->Count; i++)
		CheckListBox->Checked[i] = false;

	TokuList->Clear();
}
//---------------------------------------------------------------------------
// コード入力
void __fastcall TMainForm::cedtCodeKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;

	if (!DM->Q_List->Locate("コード", cedtCode->Text.ToIntDef(0), TLocateOptions())){
		cedtCode->SetFocus();
		return;
	}
	CheckListBox->ItemIndex = CheckListBox->Items->IndexOf(DM->Q_List->FieldByName("固定長コード名称")->AsString);
	CheckListBox->Checked[CheckListBox->ItemIndex] = true;
	CheckListBox->OnClick(CheckListBox);

	cedtCode->Text = AnsiString();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key == VK_F9)
		btnPrint->OnClick(NULL);
	else if (Key == VK_F10)
		btnPreview->OnClick(NULL);
	else if (Key == VK_F12)
		btnClose->OnClick(NULL);
}
//---------------------------------------------------------------------------

