//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrm.h"
#include <memory>
#include <fstream>
#include <StrUtils.hpp>
#include "DMFrm.h"
#include "nsoftfunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
	///////////////////////////////////////////////
	// �f�[�^�x�[�X�ɐڑ�

	if (!DM->Init())
		Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RefButtonClick(TObject *Sender)
{
    if (!OpenDialog->Execute())
        return;

    FileEdit->Text = OpenDialog->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ConvertID(const AnsiString& file)
{
    std::ifstream ifs(file.c_str());
    std::auto_ptr<TStringList> RecList(new TStringList());
    std::string buff;

    NsFieldSet fields;

    TDateTime now(Now());

    while (std::getline(ifs, buff)){
        RecList->Clear();
        RecList->CommaText = buff.c_str();

        fields.clear();
        fields << NsField("[�Ԕ�]",       RecList->Strings[0].ToIntDef(0))
               << NsField("[�ԗ�����]",   RecList->Strings[0])
               << NsField("[��ԏd��]",   RecList->Strings[5].ToIntDef(0))
               << NsField("[�ԗ����d��]", RecList->Strings[6].ToIntDef(0))
               << NsField("[�J�[�h�ԍ�]", RecList->Strings[0].ToIntDef(0))
               << NsField("[���Ӑ�ID]",   DM->DBI.Lookup("M_���Ӑ�", "���Ӑ�R�[�h", RecList->Strings[2].ToIntDef(0), "���Ӑ�ID"))
               << NsField("[����1ID]",    DM->DBI.Lookup("M_����1",  "����1�R�[�h",  RecList->Strings[3].ToIntDef(0), "����1ID"))
               << NsField("[����2ID]",    DM->DBI.Lookup("M_����2",  "����2�R�[�h",  RecList->Strings[4].ToIntDef(0), "����2ID"))
               << NsField("[�i��ID]",     DM->DBI.Lookup("M_�i��",   "�i�ڃR�[�h",   RecList->Strings[1].ToIntDef(0), "�i��ID"))
               << NsField("[�g�p�敪]",   1)
               << NsField("[�X�V����]",   now)
               << NsField("[�쐬����]",   now);

        DM->DBI.Insert("M_�ԗ�", fields);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ConvertItem(const AnsiString& file, int no)
{
    AnsiString item;
    if (no == 1){
        item = "���Ӑ�";
    }else if (no == 2){
        item = "����1";
    }else if (no == 3){
        item = "����2";
    }else if (no == 4){
        item = "�i��";
    }

    std::ifstream ifs(file.c_str());
    std::auto_ptr<TStringList> RecList(new TStringList());
    std::string buff;

    NsFieldSet fields;

    TDateTime now(Now());

    while (std::getline(ifs, buff)){
        RecList->Clear();
        RecList->CommaText = buff.c_str();

        fields.clear();
        fields << NsField("[" + item + "�R�[�h]",       RecList->Strings[0].ToIntDef(0))
               << NsField("[" + item + "����]",         RecList->Strings[1])
               << NsField("[" + item + "����]",         RecList->Strings[1].SubString(1, 20))
               << NsField("[�g�p�敪]",   1)
               << NsField("[�X�V����]",   now)
               << NsField("[�쐬����]",   now);

        DM->DBI.Insert("M_" + item, fields);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CnvButtonClick(TObject *Sender)
{
    CnvButton->Enabled = false;

    try{
        if (MasterGroup->ItemIndex == 0)
            ConvertID(FileEdit->Text);
        else
            ConvertItem(FileEdit->Text, MasterGroup->ItemIndex);

        Application->MessageBox("�������������܂���", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
    }catch(Exception& e){
        AnsiString msg = "�����Ɏ��s���܂��� - " + e.Message;
        Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
    }

    CnvButton->Enabled = true;
}
//---------------------------------------------------------------------------

