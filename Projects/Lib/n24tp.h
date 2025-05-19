// n24tp.h

#ifndef N24TP_H_
#define N24TP_H_

#include <map>

namespace N24TP {

const AnsiString INI_NAME     = "n24tp.ini";
const AnsiString SOUNDS_INI   = "sounds.ini";

extern int place_id;
bool __fastcall SetPlace(int place_code);


extern int terminal_id;

const int ADMIN_CARD_NO    = 99999999;
const int SET_ZERO_CARD_NO = 90000002;
const int CLR_ZERO_CARD_NO = 90000003;

enum {Move_In = 1, Move_Out = 2, Move_None = 0};

// カナ検索用テーブル
class KanaTable {
	typedef std::map<int, AnsiString> KanaCharTable;
	typedef std::map<int, KanaCharTable> KanaLineTable;
public:
	KanaTable();
	virtual ~KanaTable();

	AnsiString operator()(int line);
	AnsiString operator()(int line, int ch_no);

	int SearchLine(const AnsiString& kana);
private:
	KanaLineTable kana_table_;
};

extern KanaTable Kana;

};

#define UM_CONTROL_ZERO     (WM_APP + 0x01)
/* Set Zero
 * WPARAM: bool set     true: set zero / false: clear zero
 * LPARAM: none
 * destination: SysMenu::TMenuForm
 */

#endif  //N-24TP_H_
