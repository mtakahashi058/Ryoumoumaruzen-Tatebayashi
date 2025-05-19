/** n24tp.cpp
 *
 */
#include <vcl.h>
#pragma hdrstop
#include "n24tp.h"
#include "DMFrm.h"

int N24TP::terminal_id;
int N24TP::place_id;
N24TP::KanaTable N24TP::Kana;

bool __fastcall N24TP::SetPlace(int place_code){
    AnsiString sql = "SELECT ���_ID FROM M_���_ WHERE ���_�R�[�h = " + IntToStr(place_code);
    NsRecordSet set;
    if (!DM->DBI.GetRecordSet(sql, set))
        return false;
    place_id = ToInt(SET_TOP(set)["���_ID"]);
    return true;
}

N24TP::KanaTable::KanaTable(){
	kana_table_[0][0] = "�";
	kana_table_[0][1] = "�";
	kana_table_[0][2] = "�";
	kana_table_[0][3] = "�";
	kana_table_[0][4] = "�";
	kana_table_[1][0] = "�";
	kana_table_[1][1] = "�";
	kana_table_[1][2] = "�";
	kana_table_[1][3] = "�";
	kana_table_[1][4] = "�";
	kana_table_[2][0] = "�";
	kana_table_[2][1] = "�";
	kana_table_[2][2] = "�";
	kana_table_[2][3] = "�";
	kana_table_[2][4] = "�";
	kana_table_[3][0] = "�";
	kana_table_[3][1] = "�";
	kana_table_[3][2] = "�";
	kana_table_[3][3] = "�";
	kana_table_[3][4] = "�";
	kana_table_[4][0] = "�";
	kana_table_[4][1] = "�";
	kana_table_[4][2] = "�";
	kana_table_[4][3] = "�";
	kana_table_[4][4] = "�";
	kana_table_[5][0] = "�";
	kana_table_[5][1] = "�";
	kana_table_[5][2] = "�";
	kana_table_[5][3] = "�";
	kana_table_[5][4] = "�";
	kana_table_[6][0] = "�";
	kana_table_[6][1] = "�";
	kana_table_[6][2] = "�";
	kana_table_[6][3] = "�";
	kana_table_[6][4] = "�";
	kana_table_[7][0] = "�";
	kana_table_[7][1] = AnsiString();
	kana_table_[7][2] = "�";
	kana_table_[7][3] = AnsiString();
	kana_table_[7][4] = "�";
	kana_table_[8][0] = "�";
	kana_table_[8][1] = "�";
	kana_table_[8][2] = "�";
	kana_table_[8][3] = "�";
	kana_table_[8][4] = "�";
	kana_table_[9][0] = "�";
	kana_table_[9][1] = AnsiString();
	kana_table_[9][2] = "�";
	kana_table_[9][3] = AnsiString();
	kana_table_[9][4] = "�";
}

N24TP::KanaTable::~KanaTable(){
}

AnsiString N24TP::KanaTable::operator()(int line){
	return kana_table_[line][0];
}

AnsiString N24TP::KanaTable::operator()(int line, int ch_no){
	return kana_table_[line][ch_no];
}

int N24TP::KanaTable::SearchLine(const AnsiString& kana){
	for (KanaLineTable::iterator i = kana_table_.begin(); i != kana_table_.end(); i++)
		for (KanaCharTable::iterator j = i->second.begin(); j != i->second.end(); j++)
			if (j->second == kana)
				return i->first;
	return -1;
}

