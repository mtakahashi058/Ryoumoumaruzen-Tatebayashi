//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NP3411Thread.h"
#include "nsoftfunc.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

// ���ӁF�قȂ�X���b�h�����L���� VCL �̃��\�b�h/�֐�/�v���p�e�B��
//       �ʂ̃X���b�h�̒����爵���ꍇ�C�r�������̖�肪�������܂��B
//
//       ���C���X���b�h�̏��L����I�u�W�F�N�g�ɑ΂��Ă� Synchronize
//       ���\�b�h���g�������ł��܂��B���̃I�u�W�F�N�g���Q�Ƃ��邽��
//       �̃��\�b�h���X���b�h�N���X�ɒǉ����CSynchronize ���\�b�h��
//       �����Ƃ��ēn���܂��B
//
//       ���Ƃ��� UpdateCaption ���ȉ��̂悤�ɒ�`���A
//
//      void __fastcall TNP3411Thread::UpdateCaption()
//      {
//        Form1->Caption = "�X���b�h���珑�������܂���";
//      }
//
//       Execute ���\�b�h�̒��� Synchronize ���\�b�h�ɓn�����ƂŃ��C
//       ���X���b�h�����L���� Form1 �� Caption �v���p�e�B�����S�ɕ�
//       �X�ł��܂��B
//
//      Synchronize(UpdateCaption);
//
//---------------------------------------------------------------------------
__fastcall TNP3411Thread::TNP3411Thread(bool CreateSuspended, int port, const AnsiString& def,HWND owner, const CfgInfo& info, int copy)
	: TThread(CreateSuspended), port_(port), def_(def), owner_(owner), copy_(copy),cfginfo_(info)
{
}
//---------------------------------------------------------------------------
void __fastcall TNP3411Thread::SetPrintImage(NsRecordSet set, NsRecordSet print_set, int copy_no, LineBuff& line_buff)
{
    AnsiString titles[3];
    AnsiString footers[5];

    //int keiryo_id = ToInt(SET_TOP(set)["�v��ID"]);

    int div = ToInt(SET_TOP(print_set)["�����o�敪"]);

	if (div == 1){
		titles[0] = ToString(SET_TOP(print_set)["���ɓ`�[�^�C�g��1"]);
		titles[1] = ToString(SET_TOP(print_set)["���ɓ`�[�^�C�g��2"]);
		titles[2] = ToString(SET_TOP(print_set)["���ɓ`�[�^�C�g��3"]);
	}else{
		titles[0] = ToString(SET_TOP(print_set)["�o�ɓ`�[�^�C�g��1"]);
		titles[1] = ToString(SET_TOP(print_set)["�o�ɓ`�[�^�C�g��2"]);
		titles[2] = ToString(SET_TOP(print_set)["�o�ɓ`�[�^�C�g��3"]);
	}
	footers[0] = ToString(SET_TOP(print_set)["��Ж�"]);
	footers[1] = ToString(SET_TOP(print_set)["��Џ��1"]);
    footers[2] = ToString(SET_TOP(print_set)["��Џ��2"]);
	footers[3] = ToString(SET_TOP(print_set)["��Џ��3"]);
	footers[4] = ToString(SET_TOP(print_set)["��Џ��4"]);


    char buff[512];
    int no    = ToInt(SET_TOP(set)["�`�[No"]);
    int date  = ToInt(SET_TOP(set)["�v�ʓ�"]);
    int y     = ToInt(SET_TOP(set)["�N"]);
    int m     = ToInt(SET_TOP(set)["��"]);
    int d     = ToInt(SET_TOP(set)["��"]);

    int gross = ToInt(SET_TOP(set)["1��ڏd��"]);
    int tare  = ToInt(SET_TOP(set)["2��ڏd��"]);
    int net   = ToInt(SET_TOP(set)["�����d��"]);
    if (tare > gross)
        std::swap(gross, tare);

    int time1 = 0;
    int time2 = 0;
    int time;
    try{
        time1 = TDateTime(SET_TOP(set)["�v�ʓ���1"]).FormatString("hhnn").ToInt();
    }catch(...){}
    try{
        time2 = TDateTime(SET_TOP(set)["�v�ʓ���2"]).FormatString("hhnn").ToInt();
    }catch(...){}
    time = std::max(time1, time2);

    line_buff.push_back("\x1b\x33\x10");
    line_buff.push_back("\n");
    line_buff.push_back("\x1c\x21\x0C");
    line_buff.push_back("\n");
    //line_buff.push_back("�@�@�@�v �� �� �� ��\n\n");
    line_buff.push_back(titles[copy_no].c_str());
    line_buff.push_back("\x1c\x21\x10");
    line_buff.push_back("\n");

    line_buff.push_back("������������������������������������������������\n");

    //line_buff.push_back("���N �� �����X�X�X�X�N�X�X���X�X���@�@99:99�@ ��\n");
    wsprintf(buff, "���N �� ����%8s�N%4s��%4s���@ No.%5d ��\n",
                Han2Zen(IntToStr(y)).SubString(1, 8).c_str(),
                Han2Zen(IntToStr(m)).SubString(1, 4).c_str(),
                Han2Zen(IntToStr(d)).SubString(1, 4).c_str(),
                no);
    line_buff.push_back(buff);
    line_buff.push_back("������������������������������������������������\n");

    //line_buff.push_back("���ԗ��ԍ���99999 �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n");
    wsprintf(buff, "���ԗ��ԍ���%6s�@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n",
                ToString(SET_TOP(set)["�Ԕ�"]).SubString(1, 6).c_str());
    line_buff.push_back(buff);
    line_buff.push_back("������������������������������������������������\n");

    if (cfginfo_.use_toku){
	    //line_buff.push_back("���� �� �愫99999 �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n");
    	wsprintf(buff, "��%-8s��%5d �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n",
	    			cfginfo_.customer.c_str(),
    	            ToString(SET_TOP(set)["���Ӑ�R�[�h"]).SubString(1, 5).ToIntDef(0));
	    line_buff.push_back(buff);
	    //line_buff.push_back("���@�@�@�@���������������������������������@�l��\n");
	    wsprintf(buff, "���@�@�@�@��%-30s�@�l��\n",
	                AnsiSubString(ToString(SET_TOP(set)["���Ӑ於��"]), 1, 30).c_str());
	    line_buff.push_back(buff);
	    line_buff.push_back("������������������������������������������������\n");
    }

    if (cfginfo_.use_items){
	    //line_buff.push_back("�� �i�@�� ��9999�@������������������������������\n");
    	wsprintf(buff, "��%-8s��%4d�@%-28s��\n",
    				cfginfo_.items.c_str(),
            	    ToString(SET_TOP(set)["�i�ڃR�[�h"]).SubString(1, 4).ToIntDef(0),
                	AnsiSubString(ToString(SET_TOP(set)["�i�ږ���"]), 1, 28).c_str());
	    line_buff.push_back(buff);
    	line_buff.push_back("������������������������������������������������\n");
    }

    if (cfginfo_.use_item1){
	    //line_buff.push_back("���� �� �l��99999 �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n");
    	wsprintf(buff, "��%-8s��%5d �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n",
	    			cfginfo_.item1.c_str(),
    	            ToString(SET_TOP(set)["����1�R�[�h"]).SubString(1, 5).ToIntDef(0));
	    line_buff.push_back(buff);
	    //line_buff.push_back("���@�@�@�@��������������������������������������\n");
    	wsprintf(buff, "���@�@�@�@��%-34s��\n",
	                AnsiSubString(ToString(SET_TOP(set)["����1����"]), 1, 34).c_str());
	    line_buff.push_back(buff);
    	line_buff.push_back("������������������������������������������������\n");
    }

    if (cfginfo_.use_item2){
	    //line_buff.push_back("���[�����ꄫ99999 �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n");
    	wsprintf(buff, "��%-8s��%5d �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n",
	    			cfginfo_.item2.c_str(),
    	            ToString(SET_TOP(set)["����2�R�[�h"]).SubString(1, 5).ToIntDef(0));
	    line_buff.push_back(buff);
	    //line_buff.push_back("���@�@�@�@��������������������������������������\n");
    	wsprintf(buff, "���@�@�@�@��%-34s��\n",
	                AnsiSubString(ToString(SET_TOP(set)["����2����"]), 1, 34).c_str());
	    line_buff.push_back(buff);
    	line_buff.push_back("������������������������������������������������\n");
    }

    //line_buff.push_back("���� �d �ʄ��@�X�X�C�X�X�X�����@���󄫁@�@�@�@��\n");
	wsprintf(buff, "���� �d �ʄ��@�@�@�@%12s�����@�@�@�@�@��\n",
				Han2Zen(FormatFloat("###,##0", gross)).SubString(1, 12).c_str());
	line_buff.push_back(buff);
	line_buff.push_back("������������������������������������������������\n");

	//line_buff.push_back("����ԏd�ʄ��@�X�X�C�X�X�X�����@���̄��@�@�@�@��\n");
	wsprintf(buff, "����ԏd�ʄ��@�@�@�@%12s�����@�@�@�@�@��\n",
				Han2Zen(FormatFloat("###,##0", tare)).SubString(1, 12).c_str());
	line_buff.push_back(buff);
	line_buff.push_back("������������������������������������������������\n");

	//line_buff.push_back("�������d�ʄ��@�X�X�C�X�X�X�����@���󄫁@�@�@�@��\n");
    wsprintf(buff, "�������d�ʄ��@�@�@�@%12s�����@ %5s�@��\n",
                Han2Zen(FormatFloat("###,##0", net)).SubString(1, 12).c_str(),
                FormatFloat("00':'00", time).c_str());
    line_buff.push_back(buff);
    line_buff.push_back("������������������������������������������������\n\n");

    line_buff.push_back("�@�@�@�@�@��L�̒ʂ�v�ʐ\���グ�܂��B�@�@�@�@�@\n\n\n");
    line_buff.push_back("\x1c\x21\x04\n");
    wsprintf(buff, "%s\n", footers[0].c_str());
    line_buff.push_back(buff);
    line_buff.push_back("\x1c\x21\x10\n");
    wsprintf(buff, "%s\n", footers[1].c_str());
    line_buff.push_back(buff);
    wsprintf(buff, "%s\n", footers[2].c_str());
    line_buff.push_back(buff);
    wsprintf(buff, "%s\n", footers[3].c_str());
    line_buff.push_back(buff);
    wsprintf(buff, "%s\n", footers[4].c_str());
    line_buff.push_back(buff);
	line_buff.push_back("\n\n\n\n\n\n\n\n\n");

}
//---------------------------------------------------------------------------
void __fastcall TNP3411Thread::CreatePrintImage(int keiryo_id, int copy_no, LineBuff& line_buff)
{
	AnsiString toku_label  = DM->TrimSpace(ToString(DM->CFG["���Ӑ�}�X�^����"]));
    AnsiString meig_label  = DM->TrimSpace(ToString(DM->CFG["�i�ڃ}�X�^����"]));
    AnsiString item1_label = DM->TrimSpace(ToString(DM->CFG["����1�}�X�^����"]));
    AnsiString item2_label = DM->TrimSpace(ToString(DM->CFG["����2�}�X�^����"]));
    bool use_toku  = ToBit(DM->CFG["���Ӑ�}�X�^�g�p�敪"]);
    bool use_meig  = ToBit(DM->CFG["�i�ڃ}�X�^�g�p�敪"]);
    bool use_item1 = ToBit(DM->CFG["����1�}�X�^�g�p�敪"]);
    bool use_item2 = ToBit(DM->CFG["����2�}�X�^�g�p�敪"]);

    NsRecordSet set;
	AnsiString sql;

	int print_info_id = DM->GetPrintInfo(keiryo_id);
    //int print_info_id = 0;
	if (!print_info_id){
    	DM->Log("�`�[���s", "�`�[��񂪐ݒ肳��Ă��܂���", 2);
		return;
	}
	NsRecordSet print_set;
	sql = "SELECT * FROM M_�`�[��� WHERE �`�[���ID = " + IntToStr(print_info_id);
	if (!DM->DBI.GetRecordSet(sql, set)){
		DM->Log("�`�[���s", "�`�[��񂪖����ł�", 2);
		return;
	}


    AnsiString titles[3];
    AnsiString footers[5];

    int keiryo_setid = ToInt(SET_TOP(set)["�v��ID"]);



    if (keiryo_setid != keiryo_id){
        return;
    }

	int div = ToInt(SET_TOP(set)["�����o�敪"]);
	if (div == 1){
		titles[0] = ToString(SET_TOP(set)["���ɓ`�[�^�C�g��1"]);
		titles[1] = ToString(SET_TOP(set)["���ɓ`�[�^�C�g��2"]);
		titles[2] = ToString(SET_TOP(set)["���ɓ`�[�^�C�g��3"]);
	}else{
		titles[0] = ToString(SET_TOP(set)["�o�ɓ`�[�^�C�g��1"]);
		titles[1] = ToString(SET_TOP(set)["�o�ɓ`�[�^�C�g��2"]);
		titles[2] = ToString(SET_TOP(set)["�o�ɓ`�[�^�C�g��3"]);
	}
	footers[0] = ToString(SET_TOP(set)["��Ж�"]);
	footers[1] = ToString(SET_TOP(set)["��Џ��1"]);
    footers[2] = ToString(SET_TOP(set)["��Џ��2"]);
	footers[3] = ToString(SET_TOP(set)["��Џ��3"]);
	footers[4] = ToString(SET_TOP(set)["��Џ��4"]);

    sql = " SELECT * FROM V_�v�� WHERE �v��ID = " + IntToStr(keiryo_id);
    if (!DM->DBI.GetRecordSet(sql, set)){
    	DM->Log("�`�[���s", "�󎚃f�[�^���s���ł�", 2);
        return;
    }

    char buff[512];
    int no    = ToInt(SET_TOP(set)["�`�[No"]);
    int date  = ToInt(SET_TOP(set)["�v�ʓ�"]);
    int y     = ToInt(SET_TOP(set)["�N"]);
    int m     = ToInt(SET_TOP(set)["��"]);
    int d     = ToInt(SET_TOP(set)["��"]);

    int gross = ToInt(SET_TOP(set)["1��ڏd��"]);
    int tare  = ToInt(SET_TOP(set)["2��ڏd��"]);
    int net   = ToInt(SET_TOP(set)["�����d��"]);
    if (tare > gross)
        std::swap(gross, tare);

    int time1 = 0;
    int time2 = 0;
    int time;
    try{
        time1 = TDateTime(SET_TOP(set)["�v�ʓ���1"]).FormatString("hhnn").ToInt();
    }catch(...){}
    try{
        time2 = TDateTime(SET_TOP(set)["�v�ʓ���2"]).FormatString("hhnn").ToInt();
    }catch(...){}
    time = std::max(time1, time2);

    line_buff.push_back("\x1b\x33\x10");
    line_buff.push_back("\n");
    line_buff.push_back("\x1c\x21\x0C");
    line_buff.push_back("\n");
    //line_buff.push_back("�@�@�@�v �� �� �� ��\n\n");
    line_buff.push_back(titles[copy_no].c_str());
    line_buff.push_back("\x1c\x21\x10");
    line_buff.push_back("\n");

    line_buff.push_back("������������������������������������������������\n");

    //line_buff.push_back("���N �� �����X�X�X�X�N�X�X���X�X���@�@99:99�@ ��\n");
    wsprintf(buff, "���N �� ����%8s�N%4s��%4s���@ No.%5d ��\n",
                Han2Zen(IntToStr(y)).SubString(1, 8).c_str(),
                Han2Zen(IntToStr(m)).SubString(1, 4).c_str(),
                Han2Zen(IntToStr(d)).SubString(1, 4).c_str(),
                no);
    line_buff.push_back(buff);
    line_buff.push_back("������������������������������������������������\n");

    //line_buff.push_back("���ԗ��ԍ���99999 �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n");
    wsprintf(buff, "���ԗ��ԍ���%6s�@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n",
                ToString(SET_TOP(set)["�Ԕ�"]).SubString(1, 6).c_str());
    line_buff.push_back(buff);
    line_buff.push_back("������������������������������������������������\n");

    if (cfginfo_.use_toku){
	    //line_buff.push_back("���� �� �愫99999 �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n");
    	wsprintf(buff, "��%-8s��%5d �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n",
	    			cfginfo_.customer.c_str(),
    	            ToString(SET_TOP(set)["���Ӑ�R�[�h"]).SubString(1, 5).ToIntDef(0));
	    line_buff.push_back(buff);
	    //line_buff.push_back("���@�@�@�@���������������������������������@�l��\n");
	    wsprintf(buff, "���@�@�@�@��%-30s�@�l��\n",
	                AnsiSubString(ToString(SET_TOP(set)["���Ӑ於��"]), 1, 30).c_str());
	    line_buff.push_back(buff);
	    line_buff.push_back("������������������������������������������������\n");
    }

    if (cfginfo_.use_items){
	    //line_buff.push_back("�� �i�@�� ��9999�@������������������������������\n");
    	wsprintf(buff, "��%-8s��%4d�@%-28s��\n",
    				cfginfo_.items.c_str(),
            	    ToString(SET_TOP(set)["�i�ڃR�[�h"]).SubString(1, 4).ToIntDef(0),
                	AnsiSubString(ToString(SET_TOP(set)["�i�ږ���"]), 1, 28).c_str());
	    line_buff.push_back(buff);
    	line_buff.push_back("������������������������������������������������\n");
    }

    if (cfginfo_.use_item1){
	    //line_buff.push_back("���� �� �l��99999 �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n");
    	wsprintf(buff, "��%-8s��%5d �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n",
	    			cfginfo_.item1.c_str(),
    	            ToString(SET_TOP(set)["����1�R�[�h"]).SubString(1, 5).ToIntDef(0));
	    line_buff.push_back(buff);
	    //line_buff.push_back("���@�@�@�@��������������������������������������\n");
    	wsprintf(buff, "���@�@�@�@��%-34s��\n",
	                AnsiSubString(ToString(SET_TOP(set)["����1����"]), 1, 34).c_str());
	    line_buff.push_back(buff);
    	line_buff.push_back("������������������������������������������������\n");
    }

    if (cfginfo_.use_item2){
	    //line_buff.push_back("���[�����ꄫ99999 �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n");
    	wsprintf(buff, "��%-8s��%5d �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n",
	    			cfginfo_.item2.c_str(),
    	            ToString(SET_TOP(set)["����2�R�[�h"]).SubString(1, 5).ToIntDef(0));
	    line_buff.push_back(buff);
	    //line_buff.push_back("���@�@�@�@��������������������������������������\n");
    	wsprintf(buff, "���@�@�@�@��%-34s��\n",
	                AnsiSubString(ToString(SET_TOP(set)["����2����"]), 1, 34).c_str());
	    line_buff.push_back(buff);
    	line_buff.push_back("������������������������������������������������\n");
    }

    //line_buff.push_back("���� �d �ʄ��@�X�X�C�X�X�X�����@���󄫁@�@�@�@��\n");
	wsprintf(buff, "���� �d �ʄ��@�@�@�@%12s�����@�@�@�@�@��\n",
				Han2Zen(FormatFloat("###,##0", gross)).SubString(1, 12).c_str());
	line_buff.push_back(buff);
	line_buff.push_back("������������������������������������������������\n");

	//line_buff.push_back("����ԏd�ʄ��@�X�X�C�X�X�X�����@���̄��@�@�@�@��\n");
	wsprintf(buff, "����ԏd�ʄ��@�@�@�@%12s�����@�@�@�@�@��\n",
				Han2Zen(FormatFloat("###,##0", tare)).SubString(1, 12).c_str());
	line_buff.push_back(buff);
	line_buff.push_back("������������������������������������������������\n");

	//line_buff.push_back("�������d�ʄ��@�X�X�C�X�X�X�����@���󄫁@�@�@�@��\n");
    wsprintf(buff, "�������d�ʄ��@�@�@�@%12s�����@ %5s�@��\n",
                Han2Zen(FormatFloat("###,##0", net)).SubString(1, 12).c_str(),
                FormatFloat("00':'00", time).c_str());
    line_buff.push_back(buff);
    line_buff.push_back("������������������������������������������������\n\n");

    line_buff.push_back("�@�@�@�@�@��L�̒ʂ�v�ʐ\���グ�܂��B�@�@�@�@�@\n\n\n");
    line_buff.push_back("\x1c\x21\x04\n");
    wsprintf(buff, "%s\n", footers[0].c_str());
    line_buff.push_back(buff);
    line_buff.push_back("\x1c\x21\x10\n");
    wsprintf(buff, "%s\n", footers[1].c_str());
    line_buff.push_back(buff);
    wsprintf(buff, "%s\n", footers[2].c_str());
    line_buff.push_back(buff);
    wsprintf(buff, "%s\n", footers[3].c_str());
    line_buff.push_back(buff);
    wsprintf(buff, "%s\n", footers[4].c_str());
    line_buff.push_back(buff);
	line_buff.push_back("\n\n\n\n\n\n\n\n\n");

#if 0
    line_buff.push_back("\x1b\x33\x10");
    line_buff.push_back("\n");
    line_buff.push_back("\x1c\x21\x0C");
    line_buff.push_back("\n");
    line_buff.push_back("�@�@�@�v �� �� �� ��\n\n");
    line_buff.push_back("\x1c\x21\x10");
    line_buff.push_back("\n");
    line_buff.push_back("������������������������������������������������\n");
    line_buff.push_back("���N �� �����X�X�X�X�N�X�X���X�X���@�@99:99�@ ��\n");
	line_buff.push_back("������������������������������������������������\n");
    line_buff.push_back("���o�^�ԍ���12345678�@�@�@�@�@�@�@�@�@�@�@�@�@��\n");
    line_buff.push_back("������������������������������������������������\n");
    line_buff.push_back("���� �� �愫99999 �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n");
    line_buff.push_back("���@�@�@�@���������������������������������@�l��\n");
    line_buff.push_back("������������������������������������������������\n");
    line_buff.push_back("���ԗ��ԍ���99999 �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n");
    line_buff.push_back("������������������������������������������������\n");
    line_buff.push_back("���� �� �l��99999 �@�@�@�@�@�@�@�@�@�@�@�@�@�@��\n");
    line_buff.push_back("���@�@�@�@��������������������������������������\n");
    line_buff.push_back("������������������������������������������������\n");
    line_buff.push_back("���[�����ꄫ 999�@������������������������������\n");
    line_buff.push_back("������������������������������������������������\n");
    line_buff.push_back("�� �i�@�� ��9999�@������������������������������\n");
    line_buff.push_back("������������������������������������������������\n");
    line_buff.push_back("���� �d �ʄ��@�X�X�C�X�X�X�����@���󄫁@�@�@�@��\n");
    line_buff.push_back("�����������������������������������@���@�@�@�@��\n");
    line_buff.push_back("����ԏd�ʄ��@�X�X�C�X�X�X�����@���̄��@�@�@�@��\n");
    line_buff.push_back("�����������������������������������@���@�@�@�@��\n");
    line_buff.push_back("�������d�ʄ��@�X�X�C�X�X�X�����@���󄫁@�@�@�@��\n");
    line_buff.push_back("������������������������������������������������\n\n");
    line_buff.push_back("�@�@�@�@�@��L�̒ʂ�v�ʐ\���グ�܂��B�@�@�@�@�@\n\n\n");
    line_buff.push_back("\x1c\x21\x04\n");
    line_buff.push_back("�@�@�񓿐ΎY�������\n");
    line_buff.push_back("\x1c\x21\x10\n");
    line_buff.push_back("�@�@�@�@�@��ʌ����ʌS�_�쒬������47-2�@�@�@�@�@\n");
    line_buff.push_back("�@�@�@�@�@�@�@TEL (0495) 77-2072�@�@�@�@�@�@�@�@\n");
	line_buff.push_back("\n\n\n\n\n\n\n\n\n\n\n");
#endif
}
//---------------------------------------------------------------------------
void __fastcall TNP3411Thread::Execute()
{
    ackl::OverlappedComm comm;

    // �V���A���|�[�g�̏�����
    if (!comm.open(port_)){
        status_ = NiiStatus(true, 0, "�ʐM�|�[�g���I�[�v���ł��܂���");
        SendMessage(owner_, UM_NII_STATUS, ThreadID, (LPARAM)&status_);
        PostMessage(owner_, UM_NII_ABORTED, ThreadID, 0);
        return;
    }
    try{
        DCB dcb;
        COMMTIMEOUTS timeouts;

        ZeroMemory(&dcb, sizeof(DCB));

        if (!comm.getState(&dcb))
            throw std::runtime_error("getState");

        if (!comm.buildDCB(def_.c_str(), &dcb))
            throw std::runtime_error("buildDCB");

        dcb.fNull = false;
        if (!comm.setState(&dcb))
            throw std::runtime_error("setState");

        timeouts.ReadIntervalTimeout = MAXDWORD;
        timeouts.ReadTotalTimeoutMultiplier = 0;
        timeouts.ReadTotalTimeoutConstant = 0;
        timeouts.WriteTotalTimeoutMultiplier = 0;
        timeouts.WriteTotalTimeoutConstant = 0;
        if (!comm.setTimeouts(&timeouts))
            throw std::runtime_error("setTimeouts");
    }catch(std::runtime_error& e){
        status_ = NiiStatus(true, 0, "�ʐM�|�[�g�̏������Ɏ��s���܂���");
        SendMessage(owner_, UM_NII_STATUS, ThreadID, (LPARAM)&status_);
        PostMessage(owner_, UM_NII_ABORTED, ThreadID, 0);
        return;
    }

    OVERLAPPED o_read;
    OVERLAPPED o_write;
    COMSTAT stat;
    DWORD event;
    DWORD transfer;
    DWORD error;
    DWORD size;
    std::string buff;
    std::string err_buff;
    unsigned int buff_size;
    std::vector<std::string> line_buff;
	bool need_reboot = false;
	AnsiString title;

    ZeroMemory(&o_write, sizeof(OVERLAPPED));
    ZeroMemory(&o_read, sizeof(OVERLAPPED));
    o_write.hEvent = CreateEvent(NULL, true, false, NULL);
    o_read.hEvent = CreateEvent(NULL, true, false, NULL);

    MSG msg;
    char stat_buff[10];
    char cmd_reset[]  = "\x11";
    char cmd_status[] = "**";
    cmd_status[0] = 0x1b;
    cmd_status[1] = 0x76;
    char cmd_partial[] = "\x1b\x6e";      // partial b

    bool printed = false;

    // �\�t�g���Z�b�g
    size = 0;
    comm.write(cmd_reset, 1, &size, &o_write);
    comm.getOverlappedResult(&o_write, &transfer, true);

    while (!Terminated){
        Sleep(200);
        try{
            while (PeekMessage(&msg, 0, UM_NII_PRINT, UM_NII_PRINT, PM_REMOVE)){
                try{
					for (int page = 0; page < copy_; page++){
						line_buff.clear();
						//CreatePrintImage(msg.wParam, page, line_buff);
                        NsRecordSet* pKeiryoset = (NsRecordSet*)msg.wParam;
                        NsRecordSet* pPrintset  = (NsRecordSet*)msg.lParam;
                        SetPrintImage(pKeiryoset[0], pPrintset[0], page, line_buff);

						for (unsigned int i = 0; i < line_buff.size(); i++){
							comm.write(line_buff[i], &size, &o_write);
            	            comm.getOverlappedResult(&o_write, &transfer, true);
	                    }

						buff = cmd_partial;
						comm.write(buff, &size, &o_write);
						comm.getOverlappedResult(&o_write, &transfer, true);
					}
					Sleep(2000);

//                    buff = cmd_partial;
//                    comm.write(buff, &size, &o_write);
//                    comm.getOverlappedResult(&o_write, &transfer, true);
//                    Sleep(2000);

                    printed = true;
                }catch(Exception& e){
                    status_ = NiiStatus(false, -1, AnsiString("�󎚗�O - ") + e.Message);
                    SendMessage(owner_, UM_NII_STATUS, ThreadID, (LPARAM)&status_);
                }catch(...){
                    status_ = NiiStatus(false, -1, "�����O");
                    SendMessage(owner_, UM_NII_STATUS, ThreadID, (LPARAM)&status_);
                }
            }
        }catch(Exception& e){
            ::MessageBeep(MB_ICONHAND);
            need_reboot = true;
            goto finalize;
        }catch(...){
            ::MessageBeep(MB_ICONHAND);
            need_reboot = true;
            goto finalize;
        }

        if (!printed)
            continue;

        size = 0;
        comm.write(cmd_status, 2, &size, &o_write);
        comm.getOverlappedResult(&o_write, &transfer, true);

        // �X�e�[�^�X�ԓ��҂�
        for (int i = 0; i < 100; i++){
            if (Terminated)
                break;

            //Sleep(200);
            comm.clearError(&error, &stat);
            if (stat.cbInQue > 0)
                break;
        }
        
        if (Terminated)
            break;

        if (stat.cbInQue == 0){
            status_ = NiiStatus(false, -2, "�v�����^�X�e�[�^�X���擾�ł��܂���");
            SendMessage(owner_, UM_NII_STATUS, ThreadID, (LPARAM)&status_);
            comm.purge();
            continue;
        }

        size = 0;
        ZeroMemory(stat_buff, sizeof(stat_buff));
        comm.read(stat_buff, 1, &size, &o_read);
        comm.getOverlappedResult(&o_read, &transfer, false);

        if (WaitForSingleObject(o_read.hEvent, 1000) == WAIT_TIMEOUT){
            //need_reboot = true;
            //goto finalize;
        }

        status_ = NiiStatus(int(stat_buff[0]));
        SendMessage(owner_, UM_NII_STATUS, ThreadID, (LPARAM)&status_);
    }

finalize:
    comm.close();

    CloseHandle(o_write.hEvent);
    CloseHandle(o_read.hEvent);

    if (need_reboot && !Terminated)
        PostMessage(owner_, UM_NII_REBOOT, ThreadID, 0);
}
//---------------------------------------------------------------------------





