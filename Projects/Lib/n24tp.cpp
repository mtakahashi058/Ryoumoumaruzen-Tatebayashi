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
    AnsiString sql = "SELECT 拠点ID FROM M_拠点 WHERE 拠点コード = " + IntToStr(place_code);
    NsRecordSet set;
    if (!DM->DBI.GetRecordSet(sql, set))
        return false;
    place_id = ToInt(SET_TOP(set)["拠点ID"]);
    return true;
}

N24TP::KanaTable::KanaTable(){
	kana_table_[0][0] = "ｱ";
	kana_table_[0][1] = "ｲ";
	kana_table_[0][2] = "ｳ";
	kana_table_[0][3] = "ｴ";
	kana_table_[0][4] = "ｵ";
	kana_table_[1][0] = "ｶ";
	kana_table_[1][1] = "ｷ";
	kana_table_[1][2] = "ｸ";
	kana_table_[1][3] = "ｹ";
	kana_table_[1][4] = "ｺ";
	kana_table_[2][0] = "ｻ";
	kana_table_[2][1] = "ｼ";
	kana_table_[2][2] = "ｽ";
	kana_table_[2][3] = "ｾ";
	kana_table_[2][4] = "ｿ";
	kana_table_[3][0] = "ﾀ";
	kana_table_[3][1] = "ﾁ";
	kana_table_[3][2] = "ﾂ";
	kana_table_[3][3] = "ﾃ";
	kana_table_[3][4] = "ﾄ";
	kana_table_[4][0] = "ﾅ";
	kana_table_[4][1] = "ﾆ";
	kana_table_[4][2] = "ﾇ";
	kana_table_[4][3] = "ﾈ";
	kana_table_[4][4] = "ﾉ";
	kana_table_[5][0] = "ﾊ";
	kana_table_[5][1] = "ﾋ";
	kana_table_[5][2] = "ﾌ";
	kana_table_[5][3] = "ﾍ";
	kana_table_[5][4] = "ﾎ";
	kana_table_[6][0] = "ﾏ";
	kana_table_[6][1] = "ﾐ";
	kana_table_[6][2] = "ﾑ";
	kana_table_[6][3] = "ﾒ";
	kana_table_[6][4] = "ﾓ";
	kana_table_[7][0] = "ﾔ";
	kana_table_[7][1] = AnsiString();
	kana_table_[7][2] = "ﾕ";
	kana_table_[7][3] = AnsiString();
	kana_table_[7][4] = "ﾖ";
	kana_table_[8][0] = "ﾗ";
	kana_table_[8][1] = "ﾘ";
	kana_table_[8][2] = "ﾙ";
	kana_table_[8][3] = "ﾚ";
	kana_table_[8][4] = "ﾛ";
	kana_table_[9][0] = "ﾜ";
	kana_table_[9][1] = AnsiString();
	kana_table_[9][2] = "ｦ";
	kana_table_[9][3] = AnsiString();
	kana_table_[9][4] = "ﾝ";
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

