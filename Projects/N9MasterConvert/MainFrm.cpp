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
	// データベースに接続

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
        fields << NsField("[車番]",       RecList->Strings[0].ToIntDef(0))
               << NsField("[車両名称]",   RecList->Strings[0])
               << NsField("[空車重量]",   RecList->Strings[5].ToIntDef(0))
               << NsField("[車両総重量]", RecList->Strings[6].ToIntDef(0))
               << NsField("[カード番号]", RecList->Strings[0].ToIntDef(0))
               << NsField("[得意先ID]",   DM->DBI.Lookup("M_得意先", "得意先コード", RecList->Strings[2].ToIntDef(0), "得意先ID"))
               << NsField("[項目1ID]",    DM->DBI.Lookup("M_項目1",  "項目1コード",  RecList->Strings[3].ToIntDef(0), "項目1ID"))
               << NsField("[項目2ID]",    DM->DBI.Lookup("M_項目2",  "項目2コード",  RecList->Strings[4].ToIntDef(0), "項目2ID"))
               << NsField("[品目ID]",     DM->DBI.Lookup("M_品目",   "品目コード",   RecList->Strings[1].ToIntDef(0), "品目ID"))
               << NsField("[使用区分]",   1)
               << NsField("[更新日時]",   now)
               << NsField("[作成日時]",   now);

        DM->DBI.Insert("M_車両", fields);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ConvertItem(const AnsiString& file, int no)
{
    AnsiString item;
    if (no == 1){
        item = "得意先";
    }else if (no == 2){
        item = "項目1";
    }else if (no == 3){
        item = "項目2";
    }else if (no == 4){
        item = "品目";
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
        fields << NsField("[" + item + "コード]",       RecList->Strings[0].ToIntDef(0))
               << NsField("[" + item + "名称]",         RecList->Strings[1])
               << NsField("[" + item + "略称]",         RecList->Strings[1].SubString(1, 20))
               << NsField("[使用区分]",   1)
               << NsField("[更新日時]",   now)
               << NsField("[作成日時]",   now);

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

        Application->MessageBox("処理が完了しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
    }catch(Exception& e){
        AnsiString msg = "処理に失敗しました - " + e.Message;
        Application->MessageBox(msg.c_str(), Caption.c_str(), MB_OK | MB_ICONWARNING);
    }

    CnvButton->Enabled = true;
}
//---------------------------------------------------------------------------

