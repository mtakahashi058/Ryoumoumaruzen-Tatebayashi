//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "DetailFrm.h"
#include "QRItiranFrm.h"
#include "SearchFrm.h"
#include "MainFrm.h"
#include <StrUtils.hpp>
#include <SysUtils.hpp>
#include <fstream.h>
#include <memory>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma resource "*.dfm"
TMainForm *MainForm;
AnsiString GRID_CONFIG = "売掛DMグリッド配置.txt";
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	Application->OnMessage = this->MessageProc;
}
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

	ClearButton->OnClick(NULL);
	DBGrid->SetFocus();

	StatusBar->Font->Size = 11;

	if (ParamCount() < 1)
		return;

	FromDatePicker->Date = IntToDate(ParamStr(1).ToIntDef(DateToInt(Date())));
	ToDatePicker->Date   = IntToDate(ParamStr(1).ToIntDef(DateToInt(Date())));
	ApplyButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action1Execute(TObject *Sender)
{
	if (DetailForm->ShowModalWithID(0) != mrOk)
		return;
	ApplyButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action2Execute(TObject *Sender)
{
	if (DetailForm->ShowModalWithID(DM->Q_Itiran->FieldByName("売掛ID")->AsInteger) != mrOk)
		return;
	ApplyButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action3Execute(TObject *Sender)
{
	if (DM->Q_Itiran->Bof && DM->Q_Itiran->Eof){
		Application->MessageBox("データがありません", this->Caption.c_str(), MB_YESNO | MB_ICONWARNING);
		return;
	}

	if (Application->MessageBox("現在選択されているデータを削除しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	try{
		DM->ADOConnection->BeginTrans();

		NsFieldSet keys;
		keys << NsField("売掛ID", DM->Q_Itiran->FieldByName("売掛ID")->AsInteger);

		DM->DBI.Delete("D_売掛", keys);

		DM->ADOConnection->CommitTrans();
	}catch (Exception &e){
		DM->ADOConnection->RollbackTrans();
		Application->MessageBox(("削除出来ませんでした\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return;
	}

	Application->MessageBox("削除しました", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	ApplyButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action4Execute(TObject *Sender)
{
	if (ActiveControl == TokuisakiCodeEdit || ActiveControl == TokuisakiNameEdit)
		TokuisakiSearchButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action5Execute(TObject *Sender)
{
	// 指定フォーマットCSVファイルから取込
	if (!OpenDialog->Execute())
		return;

	AnsiString file_name = OpenDialog->FileName;

	if (!FileExists(file_name)){
		Application->MessageBox("指定されたファイルがありません", this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return;
	}

	std::ifstream ifs(file_name.c_str());
	std::string buff;
	NsFieldSet fields;
	NsRecordSet set;
	AnsiString sql = AnsiString();
	int id = 0, i_count = 0, u_count = 0;

	std::auto_ptr<TStringList> records(new TStringList());

	std::getline(ifs, buff); // 1行目読み飛ばし

	try{
		DM->ADOConnection->BeginTrans();

		while (std::getline(ifs, buff)){
			records->CommaText = buff.c_str();

			sql = "SELECT 売掛ID FROM V_売掛 WHERE 締切日 = " + records->Strings[0] + " AND 得意先コード = " + records->Strings[1];
			set.clear();
			if (DM->DBI.GetRecordSet(sql, set))
				id = ToInt(set[0]["売掛ID"]);
			else
				id = 0;

			fields.clear();
			fields << NsField("[締切日]",       records->Strings[0].ToIntDef(0))
				   << NsField("[請求先ID]",     ToInt(DM->DBI.Lookup("M_得意先", "得意先コード", records->Strings[1].ToIntDef(0), "得意先ID", "")))
				   << NsField("[前月残高]",     StrToCurrDef(records->Strings[2], 0))
				   << NsField("[当月入金額]",   StrToCurrDef(records->Strings[3], 0))
				   << NsField("[当月調整額]",   StrToCurrDef(records->Strings[4], 0))
				   << NsField("[当月繰越額]",   StrToCurrDef(records->Strings[5], 0))
				   << NsField("[当月売上額]",   StrToCurrDef(records->Strings[6], 0))
				   << NsField("[当月消費税額]", StrToCurrDef(records->Strings[7], 0))
				   << NsField("[当月残高]",     StrToCurrDef(records->Strings[8], 0))
				   << NsField("[更新日時]",     Now());

			if (!id){
				fields << NsField("[作成日時]", Now());
				DM->DBI.Insert("D_売掛", fields);
				i_count++;
			}else{
				DM->DBI.Update("D_売掛", "売掛ID", id, fields);
				u_count++;
			}
		}

		DM->ADOConnection->CommitTrans();
	}catch (Exception &e){
		DM->ADOConnection->RollbackTrans();
		Application->MessageBox(("データ取込に失敗しました\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return;
	}

	AnsiString msg = "データ取込が完了しました。取込結果は下記の通りです。\r\n追加：" + IntToStr(i_count) + "件\r\n上書き：" + IntToStr(u_count) + "件";
	Application->MessageBox(msg.c_str(), this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);

	ApplyButton->OnClick(NULL);
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

	if (Application->MessageBox("請求一覧表を印刷しますか？", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	QRItiranForm->QuickRep->Print();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action10Execute(TObject *Sender)
{
	if (DM->Q_Itiran->Bof && DM->Q_Itiran->Eof){
		Application->MessageBox("データがありません", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}
	QRItiranForm->QuickRep->Preview();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action11Execute(TObject *Sender)
{
	TADOQuery *query;
	query = DM->Q_Itiran;

	if (query->Bof && query->Eof){
		Application->MessageBox("データがありません", "出力処理", MB_OK | MB_ICONINFORMATION);
		return;
	}

	if (Application->MessageBox("出力しますか？", "出力", MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	query->First();

	// タイトル名＋出力範囲
	std::auto_ptr<TStringList> records(new TStringList());

	records->Append("売掛一覧,出力範囲：" + GetRange());

	Table2Str(query, records.get(), true);
	SaveDialog->FileName = "売掛一覧表_" + Date().FormatString("yyyymmdd") + ".csv";
	if (SaveDialog->Execute())
		records->SaveToFile(SaveDialog->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action12Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FromDatePickerEnter(TObject *Sender)
{
	Action4->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FromDatePickerExit(TObject *Sender)
{
	Action4->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TokuisakiCodeEditChange(TObject *Sender)
{
	if (TokuisakiCodeEdit->Text == ""){
		TokuisakiNameEdit->Text = AnsiString();
		return;
	}
	TokuisakiNameEdit->Text = DM->DBI.Lookup("M_得意先", "得意先コード", TokuisakiCodeEdit->Text.ToIntDef(0), "得意先名称", "使用区分 = 1 AND 得意先ID = 請求先ID");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TokuisakiSearchButtonClick(TObject *Sender)
{
	SearchForm->based_sql = " SELECT 得意先コード, 得意先名称, 得意先カナ FROM M_得意先 WHERE 使用区分 = 1 AND 得意先ID = 請求先ID";
	SearchForm->orderby_sql = " ORDER BY 得意先コード";
	SearchForm->table_name = "M_得意先";
	SearchForm->list_->CommaText = "得意先コード,得意先名称,得意先カナ";

	if (SearchForm->ShowModal() != mrOk)
		return;
	TokuisakiCodeEdit->Text = SearchForm->Query->FieldByName("得意先コード")->AsInteger;
	TokuisakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PriorButtonClick(TObject *Sender)
{
	FromDatePicker->Date = IncMonth(FromDatePicker->Date, -1);
	ToDatePicker->Date   = GetLastDate(FromDatePicker->Date);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NextButtonClick(TObject *Sender)
{
	FromDatePicker->Date = IncMonth(FromDatePicker->Date, 1);
	ToDatePicker->Date   = GetLastDate(FromDatePicker->Date);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ApplyButtonClick(TObject *Sender)
{
	AnsiString where = "";

	if (SimebiEdit->Text != ""){
		if (where != "")
			where += " AND";
		where = " 締日 = " + SimebiEdit->Text;
	}

	if (FromDatePicker->Checked){
		if (where != "")
			where += " AND";
		where += " 締切日 >= " + FromDatePicker->Date.FormatString("yyyymmdd");
	}

	if (ToDatePicker->Checked){
		if (where != "")
			where += " AND";
		where += " 締切日 <= " + ToDatePicker->Date.FormatString("yyyymmdd");
	}

	if (TokuisakiCodeEdit->Text != ""){
		if (where != "")
			where += " AND";
		where += " 得意先コード = " + TokuisakiCodeEdit->Text;
	}

	if (!ViewZeroCheckBox->Checked){
		if (where != "")
			where += " AND";
		where += " (前月残高 <> 0 OR 当月入金額 <> 0 OR 当月売上額 <> 0)";
	}

	if (where != "")
		where = " WHERE " + where;

	DM->Q_Itiran->Close();
	DM->Q_Itiran->SQL->Text = AnsiReplaceStr(DM->GetBaseQuery(), "$WHERE$", where);
	DM->Q_Itiran->Open();

	QRItiranForm->lblRange->Caption = GetRange();

	StatusBar->SimpleText = "  現在表示中のデータ：" + FormatFloat("#,##0件", DM->Q_Itiran->RecordCount);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ClearButtonClick(TObject *Sender)
{
	SimebiEdit->Text = AnsiString();
	FromDatePicker->Date = GetFirstDate(IncMonth(Date(), -1));
	ToDatePicker->Date = GetLastDate(IncMonth(Date(), -1));
	TokuisakiCodeEdit->Text = AnsiString();

	ApplyButton->OnClick(NULL);
	DBGrid->SetFocus();
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
// 売掛一覧表の出力範囲を返す
AnsiString __fastcall TMainForm::GetRange()
{
	AnsiString asRange = "";
	if (SimebiEdit->Text != "")
		asRange = "締日：" + SimebiEdit->Text;
	if (FromDatePicker->Checked && ToDatePicker->Checked)
		asRange += "　締切日：" + DateToStr(FromDatePicker->Date) + " ～ " + DateToStr(ToDatePicker->Date);
	else if (FromDatePicker->Checked && !ToDatePicker->Checked)
		asRange += "　締切日：" + DateToStr(FromDatePicker->Date) + " ～ ";
	else if (!FromDatePicker->Checked && ToDatePicker->Checked)
		asRange += "　締切日： ～ " + DateToStr(ToDatePicker->Date);
	if (TokuisakiCodeEdit->Text != "")
		asRange += "　請求先：" + ToString(DM->DBI.Lookup("M_得意先", "得意先コード", TokuisakiCodeEdit->Text.ToIntDef(0), "得意先名称", "使用区分 = 1"));

	return asRange;
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
// 表幅初期化ボタン
void __fastcall TMainForm::GridClearButtonClick(TObject *Sender)
{
	if (Application->MessageBox("表幅を初期化しますか？", "表幅初期化", MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;
	AnsiString file = ExtractFilePath(Application->ExeName) + GRID_CONFIG;
	if (FileExists(file))
		DeleteFile(file);
	Application->MessageBox("プログラムを再起動して下さい", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	grid_cleared_ = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (!grid_cleared_)
		DBGrid->Columns->SaveToFile(ExtractFilePath(Application->ExeName) + GRID_CONFIG); // 保存するファイル名をフルパスで指定
}
//---------------------------------------------------------------------------

