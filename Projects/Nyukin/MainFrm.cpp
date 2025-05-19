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
		Application->MessageBox(("�f�[�^�x�[�X�ڑ��Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_OK | MB_ICONHAND);
		Close();
	}

	if (!ToInt(DM->DBI.Lookup("M_���_", "���_�R�[�h", ToInt(DM->INI["Place::Code"]), "���_ID", ""))){
		Application->MessageBox("���_�}�X�^���ݒ肳��Ă��܂���B�v�ʑO�ɐݒ肵�Ă�������",
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
		Application->MessageBox("�f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}
	if (DetailForm->ShowModalWithId(DM->Q_Itiran->FieldByName("����ID")->AsInteger) != mrOk)
		return;
	ApplyButton->Click();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action3Execute(TObject *Sender)
{
	if (DM->Q_Itiran->Bof && DM->Q_Itiran->Eof){
		Application->MessageBox("�f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	if (Application->MessageBox("�폜���܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	NsFieldSet fields, keys;
	try{
		DM->ADOConnection->BeginTrans();

		keys << NsField("����ID", DM->Q_Itiran->FieldByName("����ID")->AsInteger);
		DM->DBI.Delete("D_����", keys);

		DM->ADOConnection->CommitTrans();
	}catch (Exception &e){
		DM->ADOConnection->RollbackTrans();
		Application->MessageBox(("�폜�Ɏ��s���܂���\r\n" + e.Message).c_str(),
			this->Caption.c_str(), MB_YESNO | MB_ICONHAND);
		return;
	}

	Application->MessageBox("�폜���܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
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
		Application->MessageBox("�f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	if (Application->MessageBox("������܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	AnsiString range = AnsiString();
	if (FromDatePicker->Checked)
		range = DateToStr(FromDatePicker->Date);
	range += " �` ";

	if (ToDatePicker->Checked)
		range += DateToStr(ToDatePicker->Date);

	if (!FromDatePicker->Checked && !ToDatePicker->Checked)
		QRForm->RangeLabel->Caption = "�o�͔͈́F�S��";
	else
		QRForm->RangeLabel->Caption = "�o�͔͈́F" + range;

	QRForm->QuickRep->Print();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action10Execute(TObject *Sender)
{
	if (DM->Q_Itiran->Bof && DM->Q_Itiran->Eof){
		Application->MessageBox("�f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	AnsiString range = AnsiString();
	if (FromDatePicker->Checked)
		range = DateToStr(FromDatePicker->Date);
	range += " �` ";

	if (ToDatePicker->Checked)
		range += DateToStr(ToDatePicker->Date);

	if (!FromDatePicker->Checked && !ToDatePicker->Checked)
		QRForm->RangeLabel->Caption = "�o�͔͈́F�S��";
	else
		QRForm->RangeLabel->Caption = "�o�͔͈́F" + range;

	QRForm->QuickRep->Preview();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Action11Execute(TObject *Sender)
{
	if (DM->Q_Itiran->Bof && DM->Q_Itiran->Eof){
		Application->MessageBox("�f�[�^������܂���", this->Caption.c_str(), MB_OK | MB_ICONWARNING);
		return;
	}

	if (Application->MessageBox("�o�͂��܂����H", this->Caption.c_str(), MB_YESNO | MB_ICONQUESTION) == IDNO)
		return;

	std::auto_ptr<TStringList> records(new TStringList());
	Table2Str(DM->Q_Itiran, records.get(), true);
	SaveDialog->FileName = "�����f�[�^_" + Date().FormatString("yyyymmdd") + ".csv";
	if (SaveDialog->Execute()){
		records->SaveToFile(SaveDialog->FileName);
		Application->MessageBox("�������܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	}else{
		Application->MessageBox("�L�����Z������܂���", this->Caption.c_str(), MB_OK | MB_ICONINFORMATION);
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
	SeikyusakiNameEdit->Text = ToString(DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", SeikyusakiCodeEdit->Text.ToIntDef(0), "���Ӑ於��", ""));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SeikyusakiSearchButtonClick(TObject *Sender)
{
	SearchForm->based_sql        = "SELECT ���Ӑ�R�[�h, ���Ӑ於��, ���Ӑ�J�i FROM M_���Ӑ� WHERE ���Ӑ�ID = ������ID AND �g�p�敪 = 1";
	SearchForm->orderby_sql      = "ORDER BY ���Ӑ�R�[�h";
	SearchForm->table_name       = "M_���Ӑ�";
	SearchForm->list_->CommaText = "���Ӑ�R�[�h,���Ӑ於��,���Ӑ�J�i";

	if (SearchForm->ShowModal() != mrOk)
		return;
	SeikyusakiCodeEdit->Text = SearchForm->Query->FieldByName("���Ӑ�R�[�h")->AsInteger;
	SeikyusakiCodeEdit->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::KyotenCodeEditChange(TObject *Sender)
{
	if (KyotenCodeEdit->Text == ""){
		KyotenNameEdit->Text = AnsiString();
		return;
	}
	KyotenNameEdit->Text = ToString(DM->DBI.Lookup("M_���_", "���_�R�[�h", KyotenCodeEdit->Text.ToIntDef(0), "���_����", ""));
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::KyotenSearchButtonClick(TObject *Sender)
{
	SearchForm->based_sql        = " SELECT ���_�R�[�h, ���_���� FROM M_���_";
	SearchForm->orderby_sql      = " ORDER BY ���_�R�[�h";
	SearchForm->table_name       = "M_���_";
	SearchForm->list_->CommaText = "���_�R�[�h,���_����";

	if (SearchForm->ShowModal() != mrOk)
		return;
	KyotenCodeEdit->Text = SearchForm->Query->FieldByName("���_�R�[�h")->AsInteger;
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
		where += " ������ >= " + FromDatePicker->Date.FormatString("yyyymmdd");
	}

	if (ToDatePicker->Checked){
		if (where != "")
			where += " AND";
		else
			where += " WHERE";
		where += " ������ <= " + ToDatePicker->Date.FormatString("yyyymmdd");
	}

	if (SeikyusakiCodeEdit->Text != ""){
		if (where != "")
			where += " AND";
		else
			where += " WHERE";
		where += " ������R�[�h = " + SeikyusakiCodeEdit->Text;
	}

	if (KyotenCodeEdit->Text != ""){
		if (where != "")
			where += " AND";
		else
			where += " WHERE";
		where += " ���_�R�[�h = " + KyotenCodeEdit->Text;
	}

	AnsiString sql = DM->GetItiranQuery(where);
	if (OrderComboBox->ItemIndex == 0)
		sql = sql + " ORDER BY ���_�R�[�h, �`�[No";
	else if (OrderComboBox->ItemIndex == 1)
		sql = sql + " ORDER BY ������, ������R�[�h, ���_�R�[�h, �`�[No";
	else
		sql = sql + " ORDER BY ������R�[�h, ������, ���_�R�[�h, �`�[No";

	DM->Q_Itiran->Close();
	DM->Q_Itiran->SQL->Text = sql;
	DM->Q_Itiran->Open();

	StatusBar->SimpleText = "  ���ݕ\������Ă��錏���F" + IntToStr(DM->Q_Itiran->RecordCount) + "��";
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

