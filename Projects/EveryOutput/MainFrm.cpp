//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainFrm.h"
#include "NsVar.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner), DBI(ADOConnection)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	INI.Load(ExtractFilePath(Application->ExeName) + "settings.ini");

	try{
		if (ADOConnection->Connected)
			ADOConnection->Close();
		ADOConnection->ConnectionString = "FILE NAME=" + ToString(INI["ADO::UDL"]);
		ADOConnection->Open();

	}catch(Exception& e){
		Application->MessageBox(("�f�[�^�x�[�X�ڑ��Ɏ��s���܂��� - [�v�ʃf�[�^�s�x�o��]\r\n" + e.Message).c_str(), "�G���[", MB_OK | MB_ICONSTOP);
		Close();
        return;
	}

    local_path_				= ToString(INI["Output::LocalPath"]);
    delete_local_file_		= ToInt(INI["Output::DeleteLocalFile"]) == 1 ? true : false;
    copy_file_				= ToInt(INI["Output::Copy"]) == 1 ? true : false;
    copy_path_				= ToString(INI["Output::CopyPath"]);
    output_keiryo_			= ToInt(INI["Output::Keiryo"]) == 1 ? true : false;
    output_tran_    		= ToInt(INI["Output::Tran"]) == 1 ? true : false;
	OutputTimer->Interval 	= ToInt(INI["Output::interval"]);
    mode_					= ToString(INI["Output::mode"]).ToIntDef(1);	// mode = 1 :: �v�ʌ��ʂ��|�X�g�������� �^ mode = 2 :: �`�[���s���߂����������|�X�g

    // �f�B���N�g���`�F�b�N
    if (!DirectoryExists(local_path_)){
        if (!CreateDirectory(local_path_.c_str(), 0)){
            Application->MessageBox("���[�J���o�̓p�X��ݒ肵�Ă�������", "�v�ʃf�[�^�s�x�o��", MB_OK | MB_ICONSTOP);
            Close();
        }
    }

    if (copy_file_){
	    if (!DirectoryExists(copy_path_)){
    	    if (!CreateDirectory(copy_path_.c_str(), 0)){
        	    Application->MessageBox("�o�̓p�X��ݒ肵�Ă�������", "�v�ʃf�[�^�s�x�o��", MB_OK | MB_ICONSTOP);
            	Close();
            }
        }
    }

    // "�o�͋敪"�t�B�[���h�`�F�b�N
    std::auto_ptr<TStringList> fields(new TStringList());
	ADOConnection->GetFieldNames("D_�v��", fields.get());
    if (fields->IndexOf("�o�͋敪") == -1){
    	if (Application->MessageBox("[D_�v��]��[�o�͋敪]������܂���\r\n�쐬���Ă�낵���ł����H\r\n��������I������ƃv���O�������I�����܂�", "�v�ʃf�[�^�s�x�o��", MB_YESNO | MB_ICONEXCLAMATION) != IDYES){
			OutputTimer->Enabled = false;
        	CloseTimer->Enabled  = true;;
            return;
        }
    	DBI.Execute("ALTER TABLE D_�v�� ADD �o�͋敪 int NOT NULL default 0");
    }

    fields->Clear();
	ADOConnection->GetFieldNames("D_���", fields.get());
    if (fields->IndexOf("�o�͋敪") == -1){
    	DBI.Execute("ALTER TABLE D_��� ADD �o�͋敪 int NOT NULL default 0");
    }

    if (!CloseTimer->Enabled)
		OutputTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::OutputTimerTimer(TObject *Sender)
{
	OutputTimer->Enabled = false;

    AnsiString sql;
    NsRecordSet set;
    std::ofstream ofs;
    TDateTime now = Now();
    std::auto_ptr<TStringList> fields(new TStringList());
    std::auto_ptr<TStringList> record(new TStringList());
    std::auto_ptr<TStringList> id_list(new TStringList());
    Variant var;
    AnsiString val;
    AnsiString local_file, copy_file;

    INI.Reload();

    // �v�ʃf�[�^
    if (output_keiryo_){

        // �v�ʃf�[�^�擾
        set.clear();
        if (mode_ == 1){
    	    // �t�B�[���h��
            ADOConnection->GetFieldNames("D_�v��", fields.get());

			sql = 	"SELECT * FROM D_�v�� WHERE �����敪 = 1 AND �o�͋敪 = 0";	// �o�͋敪 0:���o�́i�|�X�g���������j

        }else{
    	    // �t�B�[���h��
            fields->CommaText="�v��ID,���_ID,�v�ʓ�,�`�[No,�sNo,�Ԕ�,���Ӑ�R�[�h,���Ӑ旪��,����1�R�[�h,����1����,����2�R�[�h,����2����,�i�ڃR�[�h,�i�ڗ���,1��ڏd��,2��ڏd��,�����d��,�v�ʓ���2,�����o�敪";

			sql = 	"SELECT	�v��ID, ���_ID, �v�ʓ�, �`�[No, �sNo, �Ԕ�, ���Ӑ�R�[�h, ���Ӑ旪��, ����1�R�[�h, ����1����, ����2�R�[�h, ����2����, �i�ڃR�[�h, �i�ڗ���, [1��ڏd��], [2��ڏd��], �����d��, �v�ʓ���2, �����o�敪 "
            		"FROM	V_�v�� "
            		"WHERE	�����敪 = 1 AND �v��ID IN (SELECT �v��ID FROM D_�v�� WHERE �o�͋敪 = 2)";
                    // �o�͋敪 2:�`�[���s�i���������|�X�g�j
        }

        if (!DBI.GetRecordSet(sql, set)){
			OutputTimer->Enabled = true;
        	return;
        }

        if (mode_ == 1){
	        local_file = local_path_ + "\\D_�v��-" + now.FormatString("yyyymmddhhnnss") + ".CSV";
    	    copy_file  = copy_path_  + "\\D_�v��-" + now.FormatString("yyyymmddhhnnss") + ".CSV";
        }else{
	        local_file = local_path_ + "\\W_�`�[-" + now.FormatString("yyyymmddhhnnss") + ".CSV";
    	    copy_file  = copy_path_  + "\\W_�`�[-" + now.FormatString("yyyymmddhhnnss") + ".CSV";
        }
        ofs.open(local_file.c_str());

        // �^�C�g���o�� ���o�͂��Ȃ��悤�ɏC�� 12/11
		//ofs << fields->CommaText.c_str() << std::endl;

        // �f�[�^�o��
		id_list->Clear();
        for (unsigned int row = 0; row < set.size(); row++){
            record->Clear();
           	id_list->Add(ToString(set[row]["�v��ID"]));	// �v��ID��ǉ�
			for (int i = 0; i < fields->Count; i++){
                var = set[row][fields->Strings[i]];
                if (var.IsNull())
                    val = "@NULL@";
       	        else
           	        val = ToString(var);
            	record->Append(val);
    	    }
			ofs << record->CommaText.c_str() << std::endl;
        }
        ofs.close();

        // �o�͍ς݂ɐݒ�
        DBI.Execute("UPDATE D_�v�� SET �o�͋敪 = 1 WHERE �v��ID IN ("+ id_list->CommaText +")");

        // ���[�J���o�̓p�X���o�̓p�X
        if (copy_file_)
			CopyFile(local_file.c_str(), copy_file.c_str(), false);

        // ���[�J���t�@�C�����폜
        if (delete_local_file_)
        	DeleteFile(local_file);
    }

   	// ����f�[�^�o��
    if (output_tran_ && mode_ == 1){
    	// �t�B�[���h��
        ADOConnection->GetFieldNames("D_���", fields.get());

        // ����f�[�^�擾
        set.clear();
		sql = "SELECT * FROM D_��� WHERE �����敪 = 1 AND �o�͋敪 = 0";
        if (!DBI.GetRecordSet(sql, set)){
			OutputTimer->Enabled = true;
        	return;
        }

        local_file = local_path_ + "\\D_���-" + now.FormatString("yyyymmddhhnnss") + ".CSV";
        copy_file  = copy_path_  + "\\D_���-" + now.FormatString("yyyymmddhhnnss") + ".CSV";
        ofs.open(local_file.c_str());

        // �^�C�g���o�� ���o�͂��Ȃ��悤�ɏC�� 12/11
		//ofs << fields->CommaText.c_str() << std::endl;

        // �f�[�^�o��
        id_list->Clear();
        for (unsigned int row = 0; row < set.size(); row++){
            record->Clear();
           	id_list->Add(ToString(set[row]["���ID"]));	// ���ID��ǉ�
			for (int i = 0; i < fields->Count; i++){
                var = set[row][fields->Strings[i]];
                if (var.IsNull())
                    val = "@NULL@";
       	        else
           	        val = ToString(var);
            	record->Append(val);
    	    }
			ofs << record->CommaText.c_str() << std::endl;
        }
        ofs.close();

        // �o�͍ς݂ɐݒ�
        DBI.Execute("UPDATE D_��� SET �o�͋敪 = 1 WHERE ���ID IN ("+ id_list->CommaText +")");

        // ���[�J���o�̓p�X���o�̓p�X
        if (copy_file_)
			CopyFile(local_file.c_str(), copy_file.c_str(), false);

        // ���[�J���t�@�C�����폜
        if (delete_local_file_)
        	DeleteFile(local_file);
    }

	OutputTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ExitItemClick(TObject *Sender)
{
    if (Application->MessageBox("�v�ʃf�[�^�s�x�o�͂��I�����܂����H", Caption.c_str(), MB_YESNO | MB_ICONWARNING | MB_TOPMOST) == IDYES)
        Close();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::CloseTimerTimer(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

