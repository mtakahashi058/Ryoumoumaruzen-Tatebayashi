//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NP3411Thread.h"
#include "nsoftfunc.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

// 注意：異なるスレッドが所有する VCL のメソッド/関数/プロパティを
//       別のスレッドの中から扱う場合，排他処理の問題が発生します。
//
//       メインスレッドの所有するオブジェクトに対しては Synchronize
//       メソッドを使う事ができます。他のオブジェクトを参照するため
//       のメソッドをスレッドクラスに追加し，Synchronize メソッドの
//       引数として渡します。
//
//       たとえば UpdateCaption を以下のように定義し、
//
//      void __fastcall TNP3411Thread::UpdateCaption()
//      {
//        Form1->Caption = "スレッドから書き換えました";
//      }
//
//       Execute メソッドの中で Synchronize メソッドに渡すことでメイ
//       ンスレッドが所有する Form1 の Caption プロパティを安全に変
//       更できます。
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

    //int keiryo_id = ToInt(SET_TOP(set)["計量ID"]);

    int div = ToInt(SET_TOP(print_set)["搬入出区分"]);

	if (div == 1){
		titles[0] = ToString(SET_TOP(print_set)["入庫伝票タイトル1"]);
		titles[1] = ToString(SET_TOP(print_set)["入庫伝票タイトル2"]);
		titles[2] = ToString(SET_TOP(print_set)["入庫伝票タイトル3"]);
	}else{
		titles[0] = ToString(SET_TOP(print_set)["出庫伝票タイトル1"]);
		titles[1] = ToString(SET_TOP(print_set)["出庫伝票タイトル2"]);
		titles[2] = ToString(SET_TOP(print_set)["出庫伝票タイトル3"]);
	}
	footers[0] = ToString(SET_TOP(print_set)["会社名"]);
	footers[1] = ToString(SET_TOP(print_set)["会社情報1"]);
    footers[2] = ToString(SET_TOP(print_set)["会社情報2"]);
	footers[3] = ToString(SET_TOP(print_set)["会社情報3"]);
	footers[4] = ToString(SET_TOP(print_set)["会社情報4"]);


    char buff[512];
    int no    = ToInt(SET_TOP(set)["伝票No"]);
    int date  = ToInt(SET_TOP(set)["計量日"]);
    int y     = ToInt(SET_TOP(set)["年"]);
    int m     = ToInt(SET_TOP(set)["月"]);
    int d     = ToInt(SET_TOP(set)["日"]);

    int gross = ToInt(SET_TOP(set)["1回目重量"]);
    int tare  = ToInt(SET_TOP(set)["2回目重量"]);
    int net   = ToInt(SET_TOP(set)["正味重量"]);
    if (tare > gross)
        std::swap(gross, tare);

    int time1 = 0;
    int time2 = 0;
    int time;
    try{
        time1 = TDateTime(SET_TOP(set)["計量日時1"]).FormatString("hhnn").ToInt();
    }catch(...){}
    try{
        time2 = TDateTime(SET_TOP(set)["計量日時2"]).FormatString("hhnn").ToInt();
    }catch(...){}
    time = std::max(time1, time2);

    line_buff.push_back("\x1b\x33\x10");
    line_buff.push_back("\n");
    line_buff.push_back("\x1c\x21\x0C");
    line_buff.push_back("\n");
    //line_buff.push_back("　　　計 量 証 明 書\n\n");
    line_buff.push_back(titles[copy_no].c_str());
    line_buff.push_back("\x1c\x21\x10");
    line_buff.push_back("\n");

    line_buff.push_back("┏━━━━┳━━━━━━━━━━━━━━━━━┓\n");

    //line_buff.push_back("┃年 月 日┃９９９９年９９月９９日　　99:99　 ┃\n");
    wsprintf(buff, "┃年 月 日┃%8s年%4s月%4s日　 No.%5d ┃\n",
                Han2Zen(IntToStr(y)).SubString(1, 8).c_str(),
                Han2Zen(IntToStr(m)).SubString(1, 4).c_str(),
                Han2Zen(IntToStr(d)).SubString(1, 4).c_str(),
                no);
    line_buff.push_back(buff);
    line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");

    //line_buff.push_back("┃車両番号┃99999 　　　　　　　　　　　　　　┃\n");
    wsprintf(buff, "┃車両番号┃%6s　　　　　　　　　　　　　　┃\n",
                ToString(SET_TOP(set)["車番"]).SubString(1, 6).c_str());
    line_buff.push_back(buff);
    line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");

    if (cfginfo_.use_toku){
	    //line_buff.push_back("┃得 意 先┃99999 　　　　　　　　　　　　　　┃\n");
    	wsprintf(buff, "┃%-8s┃%5d 　　　　　　　　　　　　　　┃\n",
	    			cfginfo_.customer.c_str(),
    	            ToString(SET_TOP(set)["得意先コード"]).SubString(1, 5).ToIntDef(0));
	    line_buff.push_back(buff);
	    //line_buff.push_back("┃　　　　┃あいうえおかきくけこさしすせそ　様┃\n");
	    wsprintf(buff, "┃　　　　┃%-30s　様┃\n",
	                AnsiSubString(ToString(SET_TOP(set)["得意先名称"]), 1, 30).c_str());
	    line_buff.push_back(buff);
	    line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");
    }

    if (cfginfo_.use_items){
	    //line_buff.push_back("┃ 品　名 ┃9999　あいうえおかきくけこさしすせ┃\n");
    	wsprintf(buff, "┃%-8s┃%4d　%-28s┃\n",
    				cfginfo_.items.c_str(),
            	    ToString(SET_TOP(set)["品目コード"]).SubString(1, 4).ToIntDef(0),
                	AnsiSubString(ToString(SET_TOP(set)["品目名称"]), 1, 28).c_str());
	    line_buff.push_back(buff);
    	line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");
    }

    if (cfginfo_.use_item1){
	    //line_buff.push_back("┃買 受 人┃99999 　　　　　　　　　　　　　　┃\n");
    	wsprintf(buff, "┃%-8s┃%5d 　　　　　　　　　　　　　　┃\n",
	    			cfginfo_.item1.c_str(),
    	            ToString(SET_TOP(set)["項目1コード"]).SubString(1, 5).ToIntDef(0));
	    line_buff.push_back(buff);
	    //line_buff.push_back("┃　　　　┃あいうえおかきくけこさしすせそたち┃\n");
    	wsprintf(buff, "┃　　　　┃%-34s┃\n",
	                AnsiSubString(ToString(SET_TOP(set)["項目1名称"]), 1, 34).c_str());
	    line_buff.push_back(buff);
    	line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");
    }

    if (cfginfo_.use_item2){
	    //line_buff.push_back("┃納入現場┃99999 　　　　　　　　　　　　　　┃\n");
    	wsprintf(buff, "┃%-8s┃%5d 　　　　　　　　　　　　　　┃\n",
	    			cfginfo_.item2.c_str(),
    	            ToString(SET_TOP(set)["項目2コード"]).SubString(1, 5).ToIntDef(0));
	    line_buff.push_back(buff);
	    //line_buff.push_back("┃　　　　┃あいうえおかきくけこさしすせそたち┃\n");
    	wsprintf(buff, "┃　　　　┃%-34s┃\n",
	                AnsiSubString(ToString(SET_TOP(set)["項目2名称"]), 1, 34).c_str());
	    line_buff.push_back(buff);
    	line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");
    }

    //line_buff.push_back("┃総 重 量┃　９９，９９９ｋｇ　┃受┃　　　　┃\n");
	wsprintf(buff, "┃総 重 量┃　　　　%12sｋｇ　　　　　┃\n",
				Han2Zen(FormatFloat("###,##0", gross)).SubString(1, 12).c_str());
	line_buff.push_back(buff);
	line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");

	//line_buff.push_back("┃空車重量┃　９９，９９９ｋｇ　┃領┃　　　　┃\n");
	wsprintf(buff, "┃空車重量┃　　　　%12sｋｇ　　　　　┃\n",
				Han2Zen(FormatFloat("###,##0", tare)).SubString(1, 12).c_str());
	line_buff.push_back(buff);
	line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");

	//line_buff.push_back("┃正味重量┃　９９，９９９ｋｇ　┃印┃　　　　┃\n");
    wsprintf(buff, "┃正味重量┃　　　　%12sｋｇ　 %5s　┃\n",
                Han2Zen(FormatFloat("###,##0", net)).SubString(1, 12).c_str(),
                FormatFloat("00':'00", time).c_str());
    line_buff.push_back(buff);
    line_buff.push_back("┗━━━━┻━━━━━━━━━━━━━━━━━┛\n\n");

    line_buff.push_back("　　　　　上記の通り計量申し上げます。　　　　　\n\n\n");
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
	AnsiString toku_label  = DM->TrimSpace(ToString(DM->CFG["得意先マスタ名称"]));
    AnsiString meig_label  = DM->TrimSpace(ToString(DM->CFG["品目マスタ名称"]));
    AnsiString item1_label = DM->TrimSpace(ToString(DM->CFG["項目1マスタ名称"]));
    AnsiString item2_label = DM->TrimSpace(ToString(DM->CFG["項目2マスタ名称"]));
    bool use_toku  = ToBit(DM->CFG["得意先マスタ使用区分"]);
    bool use_meig  = ToBit(DM->CFG["品目マスタ使用区分"]);
    bool use_item1 = ToBit(DM->CFG["項目1マスタ使用区分"]);
    bool use_item2 = ToBit(DM->CFG["項目2マスタ使用区分"]);

    NsRecordSet set;
	AnsiString sql;

	int print_info_id = DM->GetPrintInfo(keiryo_id);
    //int print_info_id = 0;
	if (!print_info_id){
    	DM->Log("伝票発行", "伝票情報が設定されていません", 2);
		return;
	}
	NsRecordSet print_set;
	sql = "SELECT * FROM M_伝票情報 WHERE 伝票情報ID = " + IntToStr(print_info_id);
	if (!DM->DBI.GetRecordSet(sql, set)){
		DM->Log("伝票発行", "伝票情報が無効です", 2);
		return;
	}


    AnsiString titles[3];
    AnsiString footers[5];

    int keiryo_setid = ToInt(SET_TOP(set)["計量ID"]);



    if (keiryo_setid != keiryo_id){
        return;
    }

	int div = ToInt(SET_TOP(set)["搬入出区分"]);
	if (div == 1){
		titles[0] = ToString(SET_TOP(set)["入庫伝票タイトル1"]);
		titles[1] = ToString(SET_TOP(set)["入庫伝票タイトル2"]);
		titles[2] = ToString(SET_TOP(set)["入庫伝票タイトル3"]);
	}else{
		titles[0] = ToString(SET_TOP(set)["出庫伝票タイトル1"]);
		titles[1] = ToString(SET_TOP(set)["出庫伝票タイトル2"]);
		titles[2] = ToString(SET_TOP(set)["出庫伝票タイトル3"]);
	}
	footers[0] = ToString(SET_TOP(set)["会社名"]);
	footers[1] = ToString(SET_TOP(set)["会社情報1"]);
    footers[2] = ToString(SET_TOP(set)["会社情報2"]);
	footers[3] = ToString(SET_TOP(set)["会社情報3"]);
	footers[4] = ToString(SET_TOP(set)["会社情報4"]);

    sql = " SELECT * FROM V_計量 WHERE 計量ID = " + IntToStr(keiryo_id);
    if (!DM->DBI.GetRecordSet(sql, set)){
    	DM->Log("伝票発行", "印字データが不明です", 2);
        return;
    }

    char buff[512];
    int no    = ToInt(SET_TOP(set)["伝票No"]);
    int date  = ToInt(SET_TOP(set)["計量日"]);
    int y     = ToInt(SET_TOP(set)["年"]);
    int m     = ToInt(SET_TOP(set)["月"]);
    int d     = ToInt(SET_TOP(set)["日"]);

    int gross = ToInt(SET_TOP(set)["1回目重量"]);
    int tare  = ToInt(SET_TOP(set)["2回目重量"]);
    int net   = ToInt(SET_TOP(set)["正味重量"]);
    if (tare > gross)
        std::swap(gross, tare);

    int time1 = 0;
    int time2 = 0;
    int time;
    try{
        time1 = TDateTime(SET_TOP(set)["計量日時1"]).FormatString("hhnn").ToInt();
    }catch(...){}
    try{
        time2 = TDateTime(SET_TOP(set)["計量日時2"]).FormatString("hhnn").ToInt();
    }catch(...){}
    time = std::max(time1, time2);

    line_buff.push_back("\x1b\x33\x10");
    line_buff.push_back("\n");
    line_buff.push_back("\x1c\x21\x0C");
    line_buff.push_back("\n");
    //line_buff.push_back("　　　計 量 証 明 書\n\n");
    line_buff.push_back(titles[copy_no].c_str());
    line_buff.push_back("\x1c\x21\x10");
    line_buff.push_back("\n");

    line_buff.push_back("┏━━━━┳━━━━━━━━━━━━━━━━━┓\n");

    //line_buff.push_back("┃年 月 日┃９９９９年９９月９９日　　99:99　 ┃\n");
    wsprintf(buff, "┃年 月 日┃%8s年%4s月%4s日　 No.%5d ┃\n",
                Han2Zen(IntToStr(y)).SubString(1, 8).c_str(),
                Han2Zen(IntToStr(m)).SubString(1, 4).c_str(),
                Han2Zen(IntToStr(d)).SubString(1, 4).c_str(),
                no);
    line_buff.push_back(buff);
    line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");

    //line_buff.push_back("┃車両番号┃99999 　　　　　　　　　　　　　　┃\n");
    wsprintf(buff, "┃車両番号┃%6s　　　　　　　　　　　　　　┃\n",
                ToString(SET_TOP(set)["車番"]).SubString(1, 6).c_str());
    line_buff.push_back(buff);
    line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");

    if (cfginfo_.use_toku){
	    //line_buff.push_back("┃得 意 先┃99999 　　　　　　　　　　　　　　┃\n");
    	wsprintf(buff, "┃%-8s┃%5d 　　　　　　　　　　　　　　┃\n",
	    			cfginfo_.customer.c_str(),
    	            ToString(SET_TOP(set)["得意先コード"]).SubString(1, 5).ToIntDef(0));
	    line_buff.push_back(buff);
	    //line_buff.push_back("┃　　　　┃あいうえおかきくけこさしすせそ　様┃\n");
	    wsprintf(buff, "┃　　　　┃%-30s　様┃\n",
	                AnsiSubString(ToString(SET_TOP(set)["得意先名称"]), 1, 30).c_str());
	    line_buff.push_back(buff);
	    line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");
    }

    if (cfginfo_.use_items){
	    //line_buff.push_back("┃ 品　名 ┃9999　あいうえおかきくけこさしすせ┃\n");
    	wsprintf(buff, "┃%-8s┃%4d　%-28s┃\n",
    				cfginfo_.items.c_str(),
            	    ToString(SET_TOP(set)["品目コード"]).SubString(1, 4).ToIntDef(0),
                	AnsiSubString(ToString(SET_TOP(set)["品目名称"]), 1, 28).c_str());
	    line_buff.push_back(buff);
    	line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");
    }

    if (cfginfo_.use_item1){
	    //line_buff.push_back("┃買 受 人┃99999 　　　　　　　　　　　　　　┃\n");
    	wsprintf(buff, "┃%-8s┃%5d 　　　　　　　　　　　　　　┃\n",
	    			cfginfo_.item1.c_str(),
    	            ToString(SET_TOP(set)["項目1コード"]).SubString(1, 5).ToIntDef(0));
	    line_buff.push_back(buff);
	    //line_buff.push_back("┃　　　　┃あいうえおかきくけこさしすせそたち┃\n");
    	wsprintf(buff, "┃　　　　┃%-34s┃\n",
	                AnsiSubString(ToString(SET_TOP(set)["項目1名称"]), 1, 34).c_str());
	    line_buff.push_back(buff);
    	line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");
    }

    if (cfginfo_.use_item2){
	    //line_buff.push_back("┃納入現場┃99999 　　　　　　　　　　　　　　┃\n");
    	wsprintf(buff, "┃%-8s┃%5d 　　　　　　　　　　　　　　┃\n",
	    			cfginfo_.item2.c_str(),
    	            ToString(SET_TOP(set)["項目2コード"]).SubString(1, 5).ToIntDef(0));
	    line_buff.push_back(buff);
	    //line_buff.push_back("┃　　　　┃あいうえおかきくけこさしすせそたち┃\n");
    	wsprintf(buff, "┃　　　　┃%-34s┃\n",
	                AnsiSubString(ToString(SET_TOP(set)["項目2名称"]), 1, 34).c_str());
	    line_buff.push_back(buff);
    	line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");
    }

    //line_buff.push_back("┃総 重 量┃　９９，９９９ｋｇ　┃受┃　　　　┃\n");
	wsprintf(buff, "┃総 重 量┃　　　　%12sｋｇ　　　　　┃\n",
				Han2Zen(FormatFloat("###,##0", gross)).SubString(1, 12).c_str());
	line_buff.push_back(buff);
	line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");

	//line_buff.push_back("┃空車重量┃　９９，９９９ｋｇ　┃領┃　　　　┃\n");
	wsprintf(buff, "┃空車重量┃　　　　%12sｋｇ　　　　　┃\n",
				Han2Zen(FormatFloat("###,##0", tare)).SubString(1, 12).c_str());
	line_buff.push_back(buff);
	line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");

	//line_buff.push_back("┃正味重量┃　９９，９９９ｋｇ　┃印┃　　　　┃\n");
    wsprintf(buff, "┃正味重量┃　　　　%12sｋｇ　 %5s　┃\n",
                Han2Zen(FormatFloat("###,##0", net)).SubString(1, 12).c_str(),
                FormatFloat("00':'00", time).c_str());
    line_buff.push_back(buff);
    line_buff.push_back("┗━━━━┻━━━━━━━━━━━━━━━━━┛\n\n");

    line_buff.push_back("　　　　　上記の通り計量申し上げます。　　　　　\n\n\n");
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
    line_buff.push_back("　　　計 量 証 明 書\n\n");
    line_buff.push_back("\x1c\x21\x10");
    line_buff.push_back("\n");
    line_buff.push_back("┏━━━━┳━━━━━━━━━━━━━━━━━┓\n");
    line_buff.push_back("┃年 月 日┃９９９９年９９月９９日　　99:99　 ┃\n");
	line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");
    line_buff.push_back("┃登録番号┃12345678　　　　　　　　　　　　　┃\n");
    line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");
    line_buff.push_back("┃得 意 先┃99999 　　　　　　　　　　　　　　┃\n");
    line_buff.push_back("┃　　　　┃あいうえおかきくけこさしすせそ　様┃\n");
    line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");
    line_buff.push_back("┃車両番号┃99999 　　　　　　　　　　　　　　┃\n");
    line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");
    line_buff.push_back("┃買 受 人┃99999 　　　　　　　　　　　　　　┃\n");
    line_buff.push_back("┃　　　　┃あいうえおかきくけこさしすせそたち┃\n");
    line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");
    line_buff.push_back("┃納入現場┃ 999　あいうえおかきくけこさしすせ┃\n");
    line_buff.push_back("┣━━━━╋━━━━━━━━━━━━━━━━━┫\n");
    line_buff.push_back("┃ 品　名 ┃9999　あいうえおかきくけこさしすせ┃\n");
    line_buff.push_back("┣━━━━╋━━━━━━━━━━┳━┳━━━━┫\n");
    line_buff.push_back("┃総 重 量┃　９９，９９９ｋｇ　┃受┃　　　　┃\n");
    line_buff.push_back("┣━━━━╋━━━━━━━━━━┫　┃　　　　┃\n");
    line_buff.push_back("┃空車重量┃　９９，９９９ｋｇ　┃領┃　　　　┃\n");
    line_buff.push_back("┣━━━━╋━━━━━━━━━━┫　┃　　　　┃\n");
    line_buff.push_back("┃正味重量┃　９９，９９９ｋｇ　┃印┃　　　　┃\n");
    line_buff.push_back("┗━━━━┻━━━━━━━━━━┻━┻━━━━┛\n\n");
    line_buff.push_back("　　　　　上記の通り計量申し上げます。　　　　　\n\n\n");
    line_buff.push_back("\x1c\x21\x04\n");
    line_buff.push_back("　　報徳石産株式会社\n");
    line_buff.push_back("\x1c\x21\x10\n");
    line_buff.push_back("　　　　　埼玉県児玉郡神川町元阿保47-2　　　　　\n");
    line_buff.push_back("　　　　　　　TEL (0495) 77-2072　　　　　　　　\n");
	line_buff.push_back("\n\n\n\n\n\n\n\n\n\n\n");
#endif
}
//---------------------------------------------------------------------------
void __fastcall TNP3411Thread::Execute()
{
    ackl::OverlappedComm comm;

    // シリアルポートの初期化
    if (!comm.open(port_)){
        status_ = NiiStatus(true, 0, "通信ポートがオープンできません");
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
        status_ = NiiStatus(true, 0, "通信ポートの初期化に失敗しました");
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

    // ソフトリセット
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
                    status_ = NiiStatus(false, -1, AnsiString("印字例外 - ") + e.Message);
                    SendMessage(owner_, UM_NII_STATUS, ThreadID, (LPARAM)&status_);
                }catch(...){
                    status_ = NiiStatus(false, -1, "言語例外");
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

        // ステータス返答待ち
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
            status_ = NiiStatus(false, -2, "プリンタステータスが取得できません");
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





