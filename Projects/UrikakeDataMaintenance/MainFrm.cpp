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
AnsiString GRID_CONFIG = "���|DM�O���b�h�z�u.txt";
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
		Application->MessageBox(("�f�[�^�x�[�X�ڑ��Ɏ��s���܂���\r\n" + e.Message).c_str(),
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
	if (DetailForm->ShowModalWithID(DM->Q_Itiran->FieldByName("���|ID")->AsInteger) != mrOk)
		return;
	ApplyButton->OnClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action3Execute(TObject *Sender)
{
	if (DM->Q_Itiran->Bof && DM->Q_Itiran->Eof){
		Application->MessageBox("�f�[�^������܂���", this->Caption.c_str(), MB_YESNO | MB_ICONWARNING);
		return;
	}

	if (Application->MessageBox("���ݑI������Ă���f�[�^���폜���܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	try{
		DM->ADOConnection->BeginTrans();

		NsFieldSet keys;
		keys << NsField("���|ID", DM->Q_Itiran->FieldByName("���|ID")->AsInteger);

		DM->DBI.Delete("D_���|", keys);

		DM->ADOConnection->CommitTrans();
	}catch (Exception &e){
		DM->ADOConnection->RollbackTrans();
		Application->MessageBox(("�폜�o���܂���ł���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return;
	}

	Application->MessageBox("�폜���܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
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
	// �w��t�H�[�}�b�gCSV�t�@�C������捞
	if (!OpenDialog->Execute())
		return;

	AnsiString file_name = OpenDialog->FileName;

	if (!FileExists(file_name)){
		Application->MessageBox("�w�肳�ꂽ�t�@�C��������܂���", this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return;
	}

	std::ifstream ifs(file_name.c_str());
	std::string buff;
	NsFieldSet fields;
	NsRecordSet set;
	AnsiString sql = AnsiString();
	int id = 0, i_count = 0, u_count = 0;

	std::auto_ptr<TStringList> records(new TStringList());

	std::getline(ifs, buff); // 1�s�ړǂݔ�΂�

	try{
		DM->ADOConnection->BeginTrans();

		while (std::getline(ifs, buff)){
			records->CommaText = buff.c_str();

			sql = "SELECT ���|ID FROM V_���| WHERE ���ؓ� = " + records->Strings[0] + " AND ���Ӑ�R�[�h = " + records->Strings[1];
			set.clear();
			if (DM->DBI.GetRecordSet(sql, set))
				id = ToInt(set[0]["���|ID"]);
			else
				id = 0;

			fields.clear();
			fields << NsField("[���ؓ�]",       records->Strings[0].ToIntDef(0))
				   << NsField("[������ID]",     ToInt(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", records->Strings[1].ToIntDef(0), "���Ӑ�ID", "")))
				   << NsField("[�O���c��]",     StrToCurrDef(records->Strings[2], 0))
				   << NsField("[���������z]",   StrToCurrDef(records->Strings[3], 0))
				   << NsField("[���������z]",   StrToCurrDef(records->Strings[4], 0))
				   << NsField("[�����J�z�z]",   StrToCurrDef(records->Strings[5], 0))
				   << NsField("[��������z]",   StrToCurrDef(records->Strings[6], 0))
				   << NsField("[��������Ŋz]", StrToCurrDef(records->Strings[7], 0))
				   << NsField("[�����c��]",     StrToCurrDef(records->Strings[8], 0))
				   << NsField("[�X�V����]",     Now());

			if (!id){
				fields << NsField("[�쐬����]", Now());
				DM->DBI.Insert("D_���|", fields);
				i_count++;
			}else{
				DM->DBI.Update("D_���|", "���|ID", id, fields);
				u_count++;
			}
		}

		DM->ADOConnection->CommitTrans();
	}catch (Exception &e){
		DM->ADOConnection->RollbackTrans();
		Application->MessageBox(("�f�[�^�捞�Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		return;
	}

	AnsiString msg = "�f�[�^�捞���������܂����B�捞���ʂ͉��L�̒ʂ�ł��B\r\n�ǉ��F" + IntToStr(i_count) + "��\r\n�㏑���F" + IntToStr(u_count) + "��";
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
		Application->MessageBox("�f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	if (Application->MessageBox("�����ꗗ�\��������܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	QRItiranForm->QuickRep->Print();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action10Execute(TObject *Sender)
{
	if (DM->Q_Itiran->Bof && DM->Q_Itiran->Eof){
		Application->MessageBox("�f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
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
		Application->MessageBox("�f�[�^������܂���", "�o�͏���", MB_OK | MB_ICONINFORMATION);
		return;
	}

	if (Application->MessageBox("�o�͂��܂����H", "�o��", MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	query->First();

	// �^�C�g�����{�o�͔͈�
	std::auto_ptr<TStringList> records(new TStringList());

	records->Append("���|�ꗗ,�o�͔͈́F" + GetRange());

	Table2Str(query, records.get(), true);
	SaveDialog->FileName = "���|�ꗗ�\_" + Date().FormatString("yyyymmdd") + ".csv";
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
	TokuisakiNameEdit->Text = DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuisakiCodeEdit->Text.ToIntDef(0), "���Ӑ於��", "�g�p�敪 = 1 AND ���Ӑ�ID = ������ID");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TokuisakiSearchButtonClick(TObject *Sender)
{
	SearchForm->based_sql = " SELECT ���Ӑ�R�[�h, ���Ӑ於��, ���Ӑ�J�i FROM M_���Ӑ� WHERE �g�p�敪 = 1 AND ���Ӑ�ID = ������ID";
	SearchForm->orderby_sql = " ORDER BY ���Ӑ�R�[�h";
	SearchForm->table_name = "M_���Ӑ�";
	SearchForm->list_->CommaText = "���Ӑ�R�[�h,���Ӑ於��,���Ӑ�J�i";

	if (SearchForm->ShowModal() != mrOk)
		return;
	TokuisakiCodeEdit->Text = SearchForm->Query->FieldByName("���Ӑ�R�[�h")->AsInteger;
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
		where = " ���� = " + SimebiEdit->Text;
	}

	if (FromDatePicker->Checked){
		if (where != "")
			where += " AND";
		where += " ���ؓ� >= " + FromDatePicker->Date.FormatString("yyyymmdd");
	}

	if (ToDatePicker->Checked){
		if (where != "")
			where += " AND";
		where += " ���ؓ� <= " + ToDatePicker->Date.FormatString("yyyymmdd");
	}

	if (TokuisakiCodeEdit->Text != ""){
		if (where != "")
			where += " AND";
		where += " ���Ӑ�R�[�h = " + TokuisakiCodeEdit->Text;
	}

	if (!ViewZeroCheckBox->Checked){
		if (where != "")
			where += " AND";
		where += " (�O���c�� <> 0 OR ���������z <> 0 OR ��������z <> 0)";
	}

	if (where != "")
		where = " WHERE " + where;

	DM->Q_Itiran->Close();
	DM->Q_Itiran->SQL->Text = AnsiReplaceStr(DM->GetBaseQuery(), "$WHERE$", where);
	DM->Q_Itiran->Open();

	QRItiranForm->lblRange->Caption = GetRange();

	StatusBar->SimpleText = "  ���ݕ\�����̃f�[�^�F" + FormatFloat("#,##0��", DM->Q_Itiran->RecordCount);
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
// ���|�ꗗ�\�̏o�͔͈͂�Ԃ�
AnsiString __fastcall TMainForm::GetRange()
{
	AnsiString asRange = "";
	if (SimebiEdit->Text != "")
		asRange = "�����F" + SimebiEdit->Text;
	if (FromDatePicker->Checked && ToDatePicker->Checked)
		asRange += "�@���ؓ��F" + DateToStr(FromDatePicker->Date) + " �` " + DateToStr(ToDatePicker->Date);
	else if (FromDatePicker->Checked && !ToDatePicker->Checked)
		asRange += "�@���ؓ��F" + DateToStr(FromDatePicker->Date) + " �` ";
	else if (!FromDatePicker->Checked && ToDatePicker->Checked)
		asRange += "�@���ؓ��F �` " + DateToStr(ToDatePicker->Date);
	if (TokuisakiCodeEdit->Text != "")
		asRange += "�@������F" + ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", TokuisakiCodeEdit->Text.ToIntDef(0), "���Ӑ於��", "�g�p�敪 = 1"));

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
// �\���������{�^��
void __fastcall TMainForm::GridClearButtonClick(TObject *Sender)
{
	if (Application->MessageBox("�\�������������܂����H", "�\��������", MB_YESNO | MB_ICONQUESTION) != IDYES)
		return;
	AnsiString file = ExtractFilePath(Application->ExeName) + GRID_CONFIG;
	if (FileExists(file))
		DeleteFile(file);
	Application->MessageBox("�v���O�������ċN�����ĉ�����", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	grid_cleared_ = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    if (!grid_cleared_)
		DBGrid->Columns->SaveToFile(ExtractFilePath(Application->ExeName) + GRID_CONFIG); // �ۑ�����t�@�C�������t���p�X�Ŏw��
}
//---------------------------------------------------------------------------

