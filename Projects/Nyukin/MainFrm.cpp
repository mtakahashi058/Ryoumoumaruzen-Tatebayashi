//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "DetailFrm.h"
#include "SearchFrm.h"
#include "QRFrm.h"
#include "MainFrm.h"
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	Application->OnMessage = this->MessageProc;
}
//---------------------------------------------------------------------------
/**
 *	Implementation of Form Event
 */
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
	if (DM->ADOConnection->Connected)
		DM->ADOConnection->Connected = false;

	try{
		DM->ADOConnection->Connected = true;
	}catch (Exception &e){
		Application->MessageBox(("データベース接続に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		Close();
	}

	if (!ToInt(DM->DBI.Lookup("M_拠点", "拠点コード", ToInt(DM->INI["Place::Code"]), "拠点ID", ""))){
		Application->MessageBox("拠点マスタが設定されていません。計量前に設定してください",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		Close();
	}

	ClearButton->Click();

	SetPrinter(QRForm->QuickRep, ToString(DM->INI["Printer::Report"]));
	StatusBar->Font->Size = 11;
}
//---------------------------------------------------------------------------
/**
 *	Implementation of Action Event
 */
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action1Execute(TObject *Sender)
{
	if (DetailForm->ShowModalWithId(0) != mrOk)
		return;
	ApplyButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action2Execute(TObject *Sender)
{
	if (DM->Q_Itiran->Bof && DM->Q_Itiran->Eof){
		Application->MessageBox("データがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}
	if (DetailForm->ShowModalWithId(DM->Q_Itiran->FieldByName("入金ID")->AsInteger) != mrOk)
		return;
	ApplyButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action3Execute(TObject *Sender)
{
	if (DM->Q_Itiran->Bof && DM->Q_Itiran->Eof){
		Application->MessageBox("データがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	if (Application->MessageBox("削除しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	NsFieldSet fields, keys;
	try{
		DM->ADOConnection->BeginTrans();

		keys << NsField("入金ID", DM->Q_Itiran->FieldByName("入金ID")->AsInteger);
		DM->DBI.Delete("D_入金", keys);

		DM->ADOConnection->CommitTrans();
	}catch (Exception &e){
		DM->ADOConnection->RollbackTrans();
		Application->MessageBox(("削除に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_YESNO | MB_ICONHAND);
		return;
	}

	Application->MessageBox("削除しました", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	ApplyButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == SeikyusakiCodeEdit || ActiveControl == SeikyusakiNameEdit)
		SeikyusakiSearchButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action5Execute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action6Execute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action7Execute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action8Execute(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action9Execute(TObject *Sender)
{
	if (DM->Q_Itiran->Bof && DM->Q_Itiran->Eof){
		Application->MessageBox("データがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	if (Application->MessageBox("印刷しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	AnsiString range = AnsiString();
	if (FromDatePicker->Checked)
		range = DateToStr(FromDatePicker->Date);
	range += " ～ ";

	if (ToDatePicker->Checked)
		range += DateToStr(ToDatePicker->Date);

	if (!FromDatePicker->Checked && !ToDatePicker->Checked)
		QRForm->RangeLabel->Caption = "出力範囲：全て";
	else
		QRForm->RangeLabel->Caption = "出力範囲：" + range;

	QRForm->QuickRep->Print();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action10Execute(TObject *Sender)
{
	if (DM->Q_Itiran->Bof && DM->Q_Itiran->Eof){
		Application->MessageBox("データがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	AnsiString range = AnsiString();
	if (FromDatePicker->Checked)
		range = DateToStr(FromDatePicker->Date);
	range += " ～ ";

	if (ToDatePicker->Checked)
		range += DateToStr(ToDatePicker->Date);

	if (!FromDatePicker->Checked && !ToDatePicker->Checked)
		QRForm->RangeLabel->Caption = "出力範囲：全て";
	else
		QRForm->RangeLabel->Caption = "出力範囲：" + range;

	QRForm->QuickRep->Preview();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action11Execute(TObject *Sender)
{
	if (DM->Q_Itiran->Bof && DM->Q_Itiran->Eof){
		Application->MessageBox("データがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	if (Application->MessageBox("出力しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	std::auto_ptr<TStringList> records(new TStringList());
	Table2Str(DM->Q_Itiran, records.get(), true);
	SaveDialog->FileName = "入金データ_" + Date().FormatString("yyyymmdd") + ".csv";
	if (SaveDialog->Execute()){
		records->SaveToFile(SaveDialog->FileName);
		Application->MessageBox("完了しました", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	}else{
		Application->MessageBox("キャンセルされました", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
/**
 *	Implementation of Component Event
 */
//---------------------------------------------------------------------------
void __fastcall TMainForm::SeikyusakiCodeEditChange(TObject *Sender)
{
	if (SeikyusakiCodeEdit->Text == ""){
		SeikyusakiNameEdit->Text = AnsiString();
		return;
	}
	SeikyusakiNameEdit->Text = ToString(DM->DBI.Lookup("M_得意先", "得意先コード", SeikyusakiCodeEdit->Text.ToIntDef(0), "得意先名称", ""));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SeikyusakiSearchButtonClick(TObject *Sender)
{
	SearchForm->based_sql        = "SELECT 得意先コード, 得意先名称, 得意先カナ FROM M_得意先 WHERE 得意先ID = 請求先ID AND 使用区分 = 1";
	SearchForm->orderby_sql      = "ORDER BY 得意先コード";
	SearchForm->table_name       = "M_得意先";
	SearchForm->list_->CommaText = "得意先コード,得意先名称,得意先カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;
	SeikyusakiCodeEdit->Text = SearchForm->Query->FieldByName("得意先コード")->AsInteger;
	SeikyusakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::KyotenCodeEditChange(TObject *Sender)
{
	if (KyotenCodeEdit->Text == ""){
		KyotenNameEdit->Text = AnsiString();
		return;
	}
	KyotenNameEdit->Text = ToString(DM->DBI.Lookup("M_拠点", "拠点コード", KyotenCodeEdit->Text.ToIntDef(0), "拠点名称", ""));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::KyotenSearchButtonClick(TObject *Sender)
{
	SearchForm->based_sql        = " SELECT 拠点コード, 拠点名称 FROM M_拠点";
	SearchForm->orderby_sql      = " ORDER BY 拠点コード";
	SearchForm->table_name       = "M_拠点";
	SearchForm->list_->CommaText = "拠点コード,拠点名称";

	if (SearchForm->ShowModal() != mrOk)
		return;
	KyotenCodeEdit->Text = SearchForm->Query->FieldByName("拠点コード")->AsInteger;
	KyotenCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ApplyButtonClick(TObject *Sender)
{
	AnsiString where = AnsiString();
	if (FromDatePicker->Checked){
		if (where != "")
			where += " AND";
		else
			where += " WHERE";
		where += " 入金日 >= " + FromDatePicker->Date.FormatString("yyyymmdd");
	}

	if (ToDatePicker->Checked){
		if (where != "")
			where += " AND";
		else
			where += " WHERE";
		where += " 入金日 <= " + ToDatePicker->Date.FormatString("yyyymmdd");
	}

	if (SeikyusakiCodeEdit->Text != ""){
		if (where != "")
			where += " AND";
		else
			where += " WHERE";
		where += " 請求先コード = " + SeikyusakiCodeEdit->Text;
	}

	if (KyotenCodeEdit->Text != ""){
		if (where != "")
			where += " AND";
		else
			where += " WHERE";
		where += " 拠点コード = " + KyotenCodeEdit->Text;
	}

	AnsiString sql = DM->GetItiranQuery(where);
	if (OrderComboBox->ItemIndex == 0)
		sql = sql + " ORDER BY 拠点コード, 伝票No";
	else if (OrderComboBox->ItemIndex == 1)
		sql = sql + " ORDER BY 入金日, 請求先コード, 拠点コード, 伝票No";
	else
		sql = sql + " ORDER BY 請求先コード, 入金日, 拠点コード, 伝票No";

	DM->Q_Itiran->Close();
	DM->Q_Itiran->SQL->Text = sql;
	DM->Q_Itiran->Open();

	StatusBar->SimpleText = "  現在表示されている件数：" + IntToStr(DM->Q_Itiran->RecordCount) + "件";
	DBGrid->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClearButtonClick(TObject *Sender)
{
	FromDatePicker->Date     = GetFirstDate(Date());
	FromDatePicker->Checked  = true;
	ToDatePicker->Date       = GetLastDate(Date());
	ToDatePicker->Checked    = true;
	SeikyusakiCodeEdit->Text = AnsiString();
	KyotenCodeEdit->Text     = AnsiString();

	ApplyButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DBGridDblClick(TObject *Sender)
{
	Action2->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DBGridKeyDown(TObject *Sender, WORD &Key,
	  TShiftState Shift)
{
	if (Key != VK_RETURN)
		return;
	Action2->Execute();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MessageProc(tagMSG &Msg, bool &Handled)
{
	switch(Msg.message){
		case WM_MOUSEWHEEL:
		if(Msg.hwnd == DBGrid->Handle){
			if((short)HIWORD(Msg.wParam) > 0){
				DBGrid->DataSource->DataSet->Prior();
			}else{
				DBGrid->DataSource->DataSet->Next();
			}
			Handled = true;
		}else if(Msg.hwnd == SearchForm->DBGrid->Handle){
			if((short)HIWORD(Msg.wParam) > 0){
				SearchForm->DBGrid->DataSource->DataSet->Prior();
			}else{
				SearchForm->DBGrid->DataSource->DataSet->Next();
			}
			Handled = true;
		}
		break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriorButton_Click(TObject *Sender)
{
	ShiftDate(FromDatePicker, ToDatePicker, -1);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NextButton_Click(TObject *Sender)
{
	ShiftDate(FromDatePicker, ToDatePicker, 1);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DBGridDrawColumnCell(TObject *Sender,
	  const TRect &Rect, int DataCol, TColumn *Column,
	  TGridDrawState State)
{
	if (((TDBGrid *)Sender)->SelectedRows->CurrentRowSelected)
		;
	else if ((State.Empty() || ActiveControl != ((TDBGrid *)Sender)) && ((TDBGrid *)Sender)->DataSource->DataSet->RecNo % 2 == 0)
		((TDBGrid *)Sender)->Canvas->Brush->Color = TColor(0x00EBEBEB);

	((TDBGrid *)Sender)->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------

