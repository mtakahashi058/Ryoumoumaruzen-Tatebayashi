//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "LaserSlipPrintM_GenkinFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLaserSlipPrintM_GenkinForm *LaserSlipPrintM_GenkinForm;
//---------------------------------------------------------------------------
__fastcall TLaserSlipPrintM_GenkinForm::TLaserSlipPrintM_GenkinForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool __fastcall TLaserSlipPrintM_GenkinForm::Print(int keiryo_id, bool hide_time)
{
    // Labelコンポーネント初期設定
    MeisaiNoLabel1[0] = MeisaiNoLabel11;
    MeisaiNoLabel1[1] = MeisaiNoLabel21;
    MeisaiNoLabel1[2] = MeisaiNoLabel31;
    MeisaiNoLabel1[3] = MeisaiNoLabel41;
    MeisaiNoLabel1[4] = MeisaiNoLabel51;
    MeisaiNoLabel1[5] = MeisaiNoLabel61;

    MeisaiNoLabel2[0] = MeisaiNoLabel12;
    MeisaiNoLabel2[1] = MeisaiNoLabel22;
    MeisaiNoLabel2[2] = MeisaiNoLabel32;
    MeisaiNoLabel2[3] = MeisaiNoLabel42;
    MeisaiNoLabel2[4] = MeisaiNoLabel52;
    MeisaiNoLabel2[5] = MeisaiNoLabel62;

    MeisaiNoLabel3[0] = MeisaiNoLabel13;
    MeisaiNoLabel3[1] = MeisaiNoLabel23;
    MeisaiNoLabel3[2] = MeisaiNoLabel33;
    MeisaiNoLabel3[3] = MeisaiNoLabel43;
    MeisaiNoLabel3[4] = MeisaiNoLabel53;
    MeisaiNoLabel3[5] = MeisaiNoLabel63;

    HinNameLabel1[0] = HinNameLabel11;
    HinNameLabel1[1] = HinNameLabel21;
    HinNameLabel1[2] = HinNameLabel31;
    HinNameLabel1[3] = HinNameLabel41;
    HinNameLabel1[4] = HinNameLabel51;
    HinNameLabel1[5] = HinNameLabel61;

    HinNameLabel2[0] = HinNameLabel12;
    HinNameLabel2[1] = HinNameLabel22;
    HinNameLabel2[2] = HinNameLabel32;
    HinNameLabel2[3] = HinNameLabel42;
    HinNameLabel2[4] = HinNameLabel52;
    HinNameLabel2[5] = HinNameLabel62;

    HinNameLabel3[0] = HinNameLabel13;
    HinNameLabel3[1] = HinNameLabel23;
    HinNameLabel3[2] = HinNameLabel33;
    HinNameLabel3[3] = HinNameLabel43;
    HinNameLabel3[4] = HinNameLabel53;
    HinNameLabel3[5] = HinNameLabel63;

    GrossWeightLabel1[0] = GrossWeightLabel11;
    GrossWeightLabel1[1] = GrossWeightLabel21;
    GrossWeightLabel1[2] = GrossWeightLabel31;
    GrossWeightLabel1[3] = GrossWeightLabel41;
    GrossWeightLabel1[4] = GrossWeightLabel51;
    GrossWeightLabel1[5] = GrossWeightLabel61;

    GrossWeightLabel2[0] = GrossWeightLabel12;
    GrossWeightLabel2[1] = GrossWeightLabel22;
    GrossWeightLabel2[2] = GrossWeightLabel32;
    GrossWeightLabel2[3] = GrossWeightLabel42;
    GrossWeightLabel2[4] = GrossWeightLabel52;
    GrossWeightLabel2[5] = GrossWeightLabel62;

    GrossWeightLabel3[0] = GrossWeightLabel13;
    GrossWeightLabel3[1] = GrossWeightLabel23;
    GrossWeightLabel3[2] = GrossWeightLabel33;
    GrossWeightLabel3[3] = GrossWeightLabel43;
    GrossWeightLabel3[4] = GrossWeightLabel53;
    GrossWeightLabel3[5] = GrossWeightLabel63;

    EmptyWeightLabel1[0] = EmptyWeightLabel11;
    EmptyWeightLabel1[1] = EmptyWeightLabel21;
    EmptyWeightLabel1[2] = EmptyWeightLabel31;
    EmptyWeightLabel1[3] = EmptyWeightLabel41;
    EmptyWeightLabel1[4] = EmptyWeightLabel51;
    EmptyWeightLabel1[5] = EmptyWeightLabel61;

    EmptyWeightLabel2[0] = EmptyWeightLabel12;
    EmptyWeightLabel2[1] = EmptyWeightLabel22;
    EmptyWeightLabel2[2] = EmptyWeightLabel32;
    EmptyWeightLabel2[3] = EmptyWeightLabel42;
    EmptyWeightLabel2[4] = EmptyWeightLabel52;
    EmptyWeightLabel2[5] = EmptyWeightLabel62;

    EmptyWeightLabel3[0] = EmptyWeightLabel13;
    EmptyWeightLabel3[1] = EmptyWeightLabel23;
    EmptyWeightLabel3[2] = EmptyWeightLabel33;
    EmptyWeightLabel3[3] = EmptyWeightLabel43;
    EmptyWeightLabel3[4] = EmptyWeightLabel53;
    EmptyWeightLabel3[5] = EmptyWeightLabel63;

    ReducLabel1[0] = ReducLabel11;
    ReducLabel1[1] = ReducLabel21;
    ReducLabel1[2] = ReducLabel31;
    ReducLabel1[3] = ReducLabel41;
    ReducLabel1[4] = ReducLabel51;
    ReducLabel1[5] = ReducLabel61;

    ReducLabel2[0] = ReducLabel12;
    ReducLabel2[1] = ReducLabel22;
    ReducLabel2[2] = ReducLabel32;
    ReducLabel2[3] = ReducLabel42;
    ReducLabel2[4] = ReducLabel52;
    ReducLabel2[5] = ReducLabel62;

    ReducLabel3[0] = ReducLabel13;
    ReducLabel3[1] = ReducLabel23;
    ReducLabel3[2] = ReducLabel33;
    ReducLabel3[3] = ReducLabel43;
    ReducLabel3[4] = ReducLabel53;
    ReducLabel3[5] = ReducLabel63;

    NetWeightLabel1[0] = NetWeightLabel11;
    NetWeightLabel1[1] = NetWeightLabel21;
    NetWeightLabel1[2] = NetWeightLabel31;
    NetWeightLabel1[3] = NetWeightLabel41;
    NetWeightLabel1[4] = NetWeightLabel51;
    NetWeightLabel1[5] = NetWeightLabel61;

    NetWeightLabel2[0] = NetWeightLabel12;
    NetWeightLabel2[1] = NetWeightLabel22;
    NetWeightLabel2[2] = NetWeightLabel32;
    NetWeightLabel2[3] = NetWeightLabel42;
    NetWeightLabel2[4] = NetWeightLabel52;
    NetWeightLabel2[5] = NetWeightLabel62;

    NetWeightLabel3[0] = NetWeightLabel13;
    NetWeightLabel3[1] = NetWeightLabel23;
    NetWeightLabel3[2] = NetWeightLabel33;
    NetWeightLabel3[3] = NetWeightLabel43;
    NetWeightLabel3[4] = NetWeightLabel53;
    NetWeightLabel3[5] = NetWeightLabel63;

    SuryoLabel1[0] = SuryoLabel11;
    SuryoLabel1[1] = SuryoLabel21;
    SuryoLabel1[2] = SuryoLabel31;
    SuryoLabel1[3] = SuryoLabel41;
    SuryoLabel1[4] = SuryoLabel51;
    SuryoLabel1[5] = SuryoLabel61;

    SuryoLabel2[0] = SuryoLabel12;
    SuryoLabel2[1] = SuryoLabel22;
    SuryoLabel2[2] = SuryoLabel32;
    SuryoLabel2[3] = SuryoLabel42;
    SuryoLabel2[4] = SuryoLabel52;
    SuryoLabel2[5] = SuryoLabel62;

    SuryoLabel3[0] = SuryoLabel13;
    SuryoLabel3[1] = SuryoLabel23;
    SuryoLabel3[2] = SuryoLabel33;
    SuryoLabel3[3] = SuryoLabel43;
    SuryoLabel3[4] = SuryoLabel53;
    SuryoLabel3[5] = SuryoLabel63;

    TaniLabel1[0] = TaniLabel11;
    TaniLabel1[1] = TaniLabel21;
    TaniLabel1[2] = TaniLabel31;
    TaniLabel1[3] = TaniLabel41;
    TaniLabel1[4] = TaniLabel51;
    TaniLabel1[5] = TaniLabel61;

    TaniLabel2[0] = TaniLabel12;
    TaniLabel2[1] = TaniLabel22;
    TaniLabel2[2] = TaniLabel32;
    TaniLabel2[3] = TaniLabel42;
    TaniLabel2[4] = TaniLabel52;
    TaniLabel2[5] = TaniLabel62;

    TaniLabel3[0] = TaniLabel13;
    TaniLabel3[1] = TaniLabel23;
    TaniLabel3[2] = TaniLabel33;
    TaniLabel3[3] = TaniLabel43;
    TaniLabel3[4] = TaniLabel53;
    TaniLabel3[5] = TaniLabel63;

    TankaLabel1[0] = TankaLabel11;
    TankaLabel1[1] = TankaLabel21;
    TankaLabel1[2] = TankaLabel31;
    TankaLabel1[3] = TankaLabel41;
    TankaLabel1[4] = TankaLabel51;
    TankaLabel1[5] = TankaLabel61;

    TankaLabel2[0] = TankaLabel12;
    TankaLabel2[1] = TankaLabel22;
    TankaLabel2[2] = TankaLabel32;
    TankaLabel2[3] = TankaLabel42;
    TankaLabel2[4] = TankaLabel52;
    TankaLabel2[5] = TankaLabel62;

    TankaLabel3[0] = TankaLabel13;
    TankaLabel3[1] = TankaLabel23;
    TankaLabel3[2] = TankaLabel33;
    TankaLabel3[3] = TankaLabel43;
    TankaLabel3[4] = TankaLabel53;
    TankaLabel3[5] = TankaLabel63;

    MoneyLabel1[0] = MoneyLabel11;
    MoneyLabel1[1] = MoneyLabel21;
    MoneyLabel1[2] = MoneyLabel31;
    MoneyLabel1[3] = MoneyLabel41;
    MoneyLabel1[4] = MoneyLabel51;
    MoneyLabel1[5] = MoneyLabel61;

    MoneyLabel2[0] = MoneyLabel12;
    MoneyLabel2[1] = MoneyLabel22;
    MoneyLabel2[2] = MoneyLabel32;
    MoneyLabel2[3] = MoneyLabel42;
    MoneyLabel2[4] = MoneyLabel52;
    MoneyLabel2[5] = MoneyLabel62;

    MoneyLabel3[0] = MoneyLabel13;
    MoneyLabel3[1] = MoneyLabel23;
    MoneyLabel3[2] = MoneyLabel33;
    MoneyLabel3[3] = MoneyLabel43;
    MoneyLabel3[4] = MoneyLabel53;
    MoneyLabel3[5] = MoneyLabel63;

    BikouLabel[0] = BikouLabel1;
    BikouLabel[1] = BikouLabel2;
    BikouLabel[2] = BikouLabel3;

    TotalNetTitleLabel[0] = TotalNetTitleLabel1;
    TotalNetTitleLabel[1] = TotalNetTitleLabel2;
    TotalNetTitleLabel[2] = TotalNetTitleLabel3;

    TotalNetLabel[0] = TotalNetLabel1;
    TotalNetLabel[1] = TotalNetLabel2;
    TotalNetLabel[2] = TotalNetLabel3;

    SumMoneyTitleLabel[0] = SumMoneyTitleLabel1;
    SumMoneyTitleLabel[1] = SumMoneyTitleLabel2;
    SumMoneyTitleLabel[2] = SumMoneyTitleLabel3;

    SumMoneyLabel[0] = SumMoneyLabel1;
    SumMoneyLabel[1] = SumMoneyLabel2;
    SumMoneyLabel[2] = SumMoneyLabel3;

    TaxTitleLabel[0] = TaxTitleLabel1;
    TaxTitleLabel[1] = TaxTitleLabel2;
    TaxTitleLabel[2] = TaxTitleLabel3;

    TaxLabel[0] = TaxLabel1;
    TaxLabel[1] = TaxLabel2;
    TaxLabel[2] = TaxLabel3;

    TotalMoneyTitleLabel[0] = TotalMoneyTitleLabel1;
    TotalMoneyTitleLabel[1] = TotalMoneyTitleLabel2;
    TotalMoneyTitleLabel[2] = TotalMoneyTitleLabel3;

    TotalMoneyLabel[0] = TotalMoneyLabel1;
    TotalMoneyLabel[1] = TotalMoneyLabel2;
    TotalMoneyLabel[2] = TotalMoneyLabel3;

	//////////////////////////////////////////////////
	///// 項目名の設定
    if (!ToBit(DM->CFG["得意先マスタ使用区分"])){
        TokuTitleLabel1->Caption = AnsiString();
        TokuTitleLabel2->Caption = AnsiString();
        TokuTitleLabel3->Caption = AnsiString();
        TokuisakiShape1->Enabled = false;
        TokuisakiShape2->Enabled = false;
        TokuisakiShape3->Enabled = false;
    }else{
        TokuisakiShape1->Enabled = true;
        TokuisakiShape2->Enabled = true;
        TokuisakiShape3->Enabled = true;
        TokuTitleLabel1->Caption = ToString(DM->CFG["得意先マスタ名称"]);
        TokuTitleLabel2->Caption = TokuTitleLabel1->Caption;
        TokuTitleLabel3->Caption = TokuTitleLabel1->Caption;
    }

    if (!ToBit(DM->CFG["項目1マスタ使用区分"])){
        ItemTitleLabel11->Caption = AnsiString();
        ItemTitleLabel12->Caption = AnsiString();
        ItemTitleLabel13->Caption = AnsiString();
        Item1Shape1->Enabled      = false;
        Item1Shape2->Enabled      = false;
        Item1Shape3->Enabled      = false;
    }else{
        Item1Shape1->Enabled      = true;
        Item1Shape2->Enabled      = true;
        Item1Shape3->Enabled      = true;
        ItemTitleLabel11->Caption = ToString(DM->CFG["項目1マスタ名称"]);
        ItemTitleLabel12->Caption = ItemTitleLabel11->Caption;
        ItemTitleLabel13->Caption = ItemTitleLabel11->Caption;
    }

    if (!ToBit(DM->CFG["項目1マスタ使用区分"])){
        ItemTitleLabel21->Caption = AnsiString();
        ItemTitleLabel22->Caption = AnsiString();
        ItemTitleLabel23->Caption = AnsiString();
        Item2Shape1->Enabled      = false;
        Item2Shape2->Enabled      = false;
        Item2Shape3->Enabled      = false;
    }else{
        Item2Shape1->Enabled      = true;
        Item2Shape2->Enabled      = true;
        Item2Shape3->Enabled      = true;
        ItemTitleLabel21->Caption = ToString(DM->CFG["項目2マスタ名称"]);
        ItemTitleLabel22->Caption = ItemTitleLabel21->Caption;
        ItemTitleLabel23->Caption = ItemTitleLabel21->Caption;
    }

    if (!ToBit(DM->CFG["品目マスタ使用区分"])){
        HinTitleLabel1->Caption = AnsiString();
        HinTitleLabel2->Caption = AnsiString();
        HinTitleLabel3->Caption = AnsiString();
    }else{
        HinTitleLabel1->Caption = ToString(DM->CFG["品目マスタ名称"]);
        HinTitleLabel2->Caption = HinTitleLabel1->Caption;
        HinTitleLabel3->Caption = HinTitleLabel1->Caption;
    }
	//Coord1Label->Caption = ToString(DM->CFG["調整名称"]);
	//Coord2Label->Caption = Coord1Label->Caption;
	//Coord3Label->Caption = Coord1Label->Caption;

    if (!ToBit(DM->CFG["調整使用区分"]) && !ToBit(DM->CFG["重量引き使用区分"])){
        ReducTitleLabel1->Caption = AnsiString();
        ReducTitleLabel2->Caption = AnsiString();
        ReducTitleLabel3->Caption = AnsiString();
    }else{
        ReducTitleLabel1->Caption = ToString(DM->CFG["重量引き名称"]);
        ReducTitleLabel2->Caption = ReducTitleLabel1->Caption;
        ReducTitleLabel3->Caption = ReducTitleLabel1->Caption;
    }

	if (!ToBit(DM->CFG["単価使用区分"])){
        SuryoTitleLabel1->Enabled = false;
        SuryoTitleLabel2->Enabled = false;
        SuryoTitleLabel3->Enabled = false;
	}else{
        SuryoTitleLabel1->Enabled = true;
        SuryoTitleLabel2->Enabled = true;
        SuryoTitleLabel3->Enabled = true;
/*
        TankaTitleLabel1->Enabled = true;
        TankaTitleLabel2->Enabled = true;
        TankaTitleLabel3->Enabled = true;
        MoneyTitleLabel1->Enabled = true;
        MoneyTitleLabel2->Enabled = true;
        MoneyTitleLabel3->Enabled = true;
*/
	}
/*
	//////////////////////////////////////////////////
	///// 時間の印字設定
    GTime1DBText->Enabled = !hide_time;
    GTime2DBText->Enabled = !hide_time;
    GTime3DBText->Enabled = !hide_time;
    TTime1DBText->Enabled = !hide_time;
    TTime2DBText->Enabled = !hide_time;
    TTime3DBText->Enabled = !hide_time;
*/

    int date, slip_no, place_id;
    AnsiString time;
    date     = ToInt(DM->DBI.Lookup("D_計量", "計量ID", keiryo_id, "計量日"));
    slip_no  = ToInt(DM->DBI.Lookup("D_計量", "計量ID", keiryo_id, "伝票No"));
    place_id = ToInt(DM->DBI.Lookup("D_計量", "計量ID", keiryo_id, "拠点ID"));

    NsRecordSet time_set;
    AnsiString sql, time_sql;
	slip_set_.clear();
	sql = " SELECT"
		  "     *"
		  " FROM"
		  "     V_計量"
		  " WHERE"
		  "     計量日 = " + IntToStr(date) +
		  " AND"
		  "     伝票No = " + IntToStr(slip_no) +
		  " AND"
		  "     拠点ID = " + IntToStr(place_id) +
		  " ORDER BY"
		  "     行No";
	if (!DM->DBI.GetRecordSet(sql, slip_set_)){
		Application->MessageBox("印字する計量データがありません", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

    time_sql = " SELECT"
               "    SUBSTRING(CONVERT(VARCHAR, 計量日時2, 108), 1, 5) AS 時間"
               " FROM"
               "    D_計量"
               " WHERE"
               "    計量日 = " + IntToStr(date) +
               " AND"
               "    伝票No = " + IntToStr(slip_no) +
               " AND"
               "    拠点ID = " + IntToStr(place_id) +
               " ORDER BY"
               "    行No DESC";
    if (!DM->DBI.GetRecordSet(time_sql, time_set)){
		Application->MessageBox("印字する計量データ(時間)の取得に失敗しました", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
    }
    time = ToString(SET_TOP(time_set)["時間"]);

	//////////////////////////////////////////////////
	///// 伝票情報の取得と設定

	int print_info_id = DM->GetPrintInfo(keiryo_id);
	if (!print_info_id){
		Application->MessageBox("伝票情報が設定されていません", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}
    sql = AnsiString();
	NsRecordSet set;
	sql = "SELECT * FROM M_伝票情報 WHERE 伝票情報ID = " + IntToStr(print_info_id);
	if (!DM->DBI.GetRecordSet(sql, set)){
		Application->MessageBox("伝票情報が無効です", Caption.c_str(), MB_OK | MB_ICONWARNING);
		return false;
	}

    int div = ToInt(SET_TOP(slip_set_)["搬入出区分"]);
	if (div == 1){ // 搬入
		TitleLabel1->Caption = ToString(SET_TOP(set)["入庫伝票タイトル1"]);
		TitleLabel2->Caption = ToString(SET_TOP(set)["入庫伝票タイトル2"]);
		TitleLabel3->Caption = ToString(SET_TOP(set)["入庫伝票タイトル3"]);
        GrossWeightTitleLabel1->Caption = "総重量";
        GrossWeightTitleLabel2->Caption = "総重量";
        GrossWeightTitleLabel3->Caption = "総重量";
        EmptyWeightTitleLabel1->Caption = "空車重量";
        EmptyWeightTitleLabel2->Caption = "空車重量";
        EmptyWeightTitleLabel3->Caption = "空車重量";
	}else{         // 搬出
		TitleLabel1->Caption = ToString(SET_TOP(set)["出庫伝票タイトル1"]);
		TitleLabel2->Caption = ToString(SET_TOP(set)["出庫伝票タイトル2"]);
		TitleLabel3->Caption = ToString(SET_TOP(set)["出庫伝票タイトル3"]);
        GrossWeightTitleLabel1->Caption = "空車重量";
        GrossWeightTitleLabel2->Caption = "空車重量";
        GrossWeightTitleLabel3->Caption = "空車重量";
        EmptyWeightTitleLabel1->Caption = "総重量";
        EmptyWeightTitleLabel2->Caption = "総重量";
        EmptyWeightTitleLabel3->Caption = "総重量";
	}

    //QRCover1->Height = Title1Label->Caption.IsEmpty() ? 861 : 1;
    //QRCover2->Height = Title2Label->Caption.IsEmpty() ? 861 : 1;
    //QRCover3->Height = Title3Label->Caption.IsEmpty() ? 861 : 1;
    QRCover1->Width = TitleLabel1->Caption.IsEmpty() ? 900 : 1;
    QRCover2->Width = TitleLabel2->Caption.IsEmpty() ? 900 : 1;
    QRCover3->Width = TitleLabel3->Caption.IsEmpty() ? 900 : 1;

    CompanyLabel1->Caption = ToString(SET_TOP(set)["会社名"]);
    CompanyLabel2->Caption = CompanyLabel1->Caption;
    CompanyLabel3->Caption = CompanyLabel1->Caption;
    InfoLabel11->Caption   = ToString(SET_TOP(set)["会社情報1"]);
    InfoLabel12->Caption   = InfoLabel11->Caption;
    InfoLabel13->Caption   = InfoLabel11->Caption;
    InfoLabel21->Caption   = ToString(SET_TOP(set)["会社情報2"]);
    InfoLabel22->Caption   = InfoLabel21->Caption;
    InfoLabel23->Caption   = InfoLabel21->Caption;
    InfoLabel31->Caption   = ToString(SET_TOP(set)["会社情報3"]);
    InfoLabel32->Caption   = InfoLabel31->Caption;
    InfoLabel33->Caption   = InfoLabel31->Caption;
    InfoLabel41->Caption   = ToString(SET_TOP(set)["会社情報4"]);
    InfoLabel42->Caption   = InfoLabel41->Caption;
    InfoLabel43->Caption   = InfoLabel41->Caption;

    DateLabel1->Caption    = FormatFloat("0000/00/00", date);
    DateLabel2->Caption    = FormatFloat("0000/00/00", date);
    DateLabel3->Caption    = FormatFloat("0000/00/00", date);

    // 時間印字設定
    if (!hide_time){
        TimeTitleLabel1->Enabled = true;
        TimeTitleLabel2->Enabled = true;
        TimeTitleLabel3->Enabled = true;
        TimeLabel1->Enabled      = true;
        TimeLabel2->Enabled      = true;
        TimeLabel3->Enabled      = true;
        TimeLabel1->Caption      = time;
        TimeLabel2->Caption      = time;
        TimeLabel3->Caption      = time;
    }else{
        TimeTitleLabel1->Enabled = false;
        TimeTitleLabel2->Enabled = false;
        TimeTitleLabel3->Enabled = false;
        TimeLabel1->Enabled      = false;
        TimeLabel2->Enabled      = false;
        TimeLabel3->Enabled      = false;
    }

    SlipNoLabel1->Caption  = slip_no;
    SlipNoLabel2->Caption  = slip_no;
    SlipNoLabel3->Caption  = slip_no;
    CarNoLabel1->Caption   = ToString(SET_TOP(slip_set_)["車番"]);
    CarNoLabel2->Caption   = ToString(SET_TOP(slip_set_)["車番"]);
    CarNoLabel3->Caption   = ToString(SET_TOP(slip_set_)["車番"]);

    if (!ToBit(DM->CFG["得意先マスタ使用区分"])){
        TokuNameLabel1->Caption = AnsiString();
        TokuNameLabel2->Caption = AnsiString();
        TokuNameLabel3->Caption = AnsiString();
	}else{
		TokuNameLabel1->Caption = ToString(SET_TOP(slip_set_)["得意先名称"]);
		TokuNameLabel2->Caption = ToString(SET_TOP(slip_set_)["得意先名称"]);
		TokuNameLabel3->Caption = ToString(SET_TOP(slip_set_)["得意先名称"]);
//        TokuNameLabel1->Caption = ToString(SET_TOP(slip_set_)["得意先マスタ名称"]);
//        TokuNameLabel2->Caption = ToString(SET_TOP(slip_set_)["得意先マスタ名称"]);
//        TokuNameLabel3->Caption = ToString(SET_TOP(slip_set_)["得意先マスタ名称"]);
    }

    if (!ToBit(DM->CFG["項目1マスタ使用区分"])){
        ItemNameLabel11->Caption = AnsiString();
        ItemNameLabel12->Caption = AnsiString();
        ItemNameLabel13->Caption = AnsiString();
    }else{
        ItemNameLabel11->Caption = ToString(SET_TOP(slip_set_)["項目1マスタ名称"]);
        ItemNameLabel12->Caption = ToString(SET_TOP(slip_set_)["項目1マスタ名称"]);
        ItemNameLabel13->Caption = ToString(SET_TOP(slip_set_)["項目1マスタ名称"]);
    }

    if (!ToBit(DM->CFG["項目1マスタ使用区分"])){
        ItemNameLabel21->Caption = AnsiString();
        ItemNameLabel22->Caption = AnsiString();
        ItemNameLabel23->Caption = AnsiString();
    }else{
        ItemNameLabel21->Caption = ToString(SET_TOP(slip_set_)["項目2マスタ名称"]);
        ItemNameLabel22->Caption = ToString(SET_TOP(slip_set_)["項目2マスタ名称"]);
        ItemNameLabel23->Caption = ToString(SET_TOP(slip_set_)["項目2マスタ名称"]);
    }

    // 拠点出力はとりあえず、無しの方向で
    //KyotenLabel1->Caption  = ToString(DM->DBI.Lookup("M_拠点", "拠点コード", DM->INI["Place::Code"], "拠点名称"));
    //KyotenLabel2->Caption  = ToString(DM->DBI.Lookup("M_拠点", "拠点コード", DM->INI["Place::Code"], "拠点名称"));
    //KyotenLabel3->Caption  = ToString(DM->DBI.Lookup("M_拠点", "拠点コード", DM->INI["Place::Code"], "拠点名称"));

    // 金額印字区分
    //bool kingaku_print1_, kingaku_print2_, kingaku_print3_;
    if (IsNull(SET_TOP(set)["金額印字区分1"]))
        kingaku_print1_ = true;
    else
        kingaku_print1_ = ToBit(SET_TOP(set)["金額印字区分1"]);
    if (IsNull(SET_TOP(set)["金額印字区分2"]))
        kingaku_print2_ = true;
    else
        kingaku_print2_ = ToBit(SET_TOP(set)["金額印字区分2"]);
    if (IsNull(SET_TOP(set)["金額印字区分3"]))
        kingaku_print3_ = true;
    else
        kingaku_print3_ = ToBit(SET_TOP(set)["金額印字区分3"]);

    SetDataLabel();

	if (!SetPrinter(QuickRep, ToString(DM->INI["Printer::Slip"]))){
		Application->MessageBox("伝票発行用に指定されたプリンタが見つかりません。通常使うプリンタを使用します",
					Caption.c_str(), MB_OK | MB_ICONINFORMATION);
	}

	//QuickRep->Preview();
	QuickRep->Print();

	return true;
}
//---------------------------------------------------------------------------
void __fastcall TLaserSlipPrintM_GenkinForm::SetDataLabel()
{
    // 明細ラベルクリア
    for (int i = 0; i < 6; i++){
        MeisaiNoLabel1[i]->Enabled    = true;
        MeisaiNoLabel2[i]->Enabled    = true;
        MeisaiNoLabel3[i]->Enabled    = true;
        HinNameLabel1[i]->Enabled     = true;
        HinNameLabel2[i]->Enabled     = true;
        HinNameLabel3[i]->Enabled     = true;
        GrossWeightLabel1[i]->Enabled = true;
        GrossWeightLabel2[i]->Enabled = true;
        GrossWeightLabel3[i]->Enabled = true;
        EmptyWeightLabel1[i]->Enabled = true;
        EmptyWeightLabel2[i]->Enabled = true;
        EmptyWeightLabel3[i]->Enabled = true;
        ReducLabel1[i]->Enabled       = true;
        ReducLabel2[i]->Enabled       = true;
        ReducLabel3[i]->Enabled       = true;
        NetWeightLabel1[i]->Enabled   = true;
        NetWeightLabel2[i]->Enabled   = true;
        NetWeightLabel3[i]->Enabled   = true;
        SuryoLabel1[i]->Enabled       = true;
        SuryoLabel2[i]->Enabled       = true;
        SuryoLabel3[i]->Enabled       = true;
        TaniLabel1[i]->Enabled        = true;
        TaniLabel2[i]->Enabled        = true;
        TaniLabel3[i]->Enabled        = true;
        TankaLabel1[i]->Enabled       = true;
        TankaLabel2[i]->Enabled       = true;
        TankaLabel3[i]->Enabled       = true;
        MoneyLabel1[i]->Enabled       = true;
        MoneyLabel2[i]->Enabled       = true;
        MoneyLabel3[i]->Enabled       = true;

        MeisaiNoLabel1[i]->Caption    = AnsiString();
        MeisaiNoLabel2[i]->Caption    = AnsiString();
        MeisaiNoLabel3[i]->Caption    = AnsiString();
        HinNameLabel1[i]->Caption     = AnsiString();
        HinNameLabel2[i]->Caption     = AnsiString();
        HinNameLabel3[i]->Caption     = AnsiString();
        GrossWeightLabel1[i]->Caption = AnsiString();
        GrossWeightLabel2[i]->Caption = AnsiString();
        GrossWeightLabel3[i]->Caption = AnsiString();
        EmptyWeightLabel1[i]->Caption = AnsiString();
        EmptyWeightLabel2[i]->Caption = AnsiString();
        EmptyWeightLabel3[i]->Caption = AnsiString();
        ReducLabel1[i]->Caption       = AnsiString();
        ReducLabel2[i]->Caption       = AnsiString();
        ReducLabel3[i]->Caption       = AnsiString();
        NetWeightLabel1[i]->Caption   = AnsiString();
        NetWeightLabel2[i]->Caption   = AnsiString();
        NetWeightLabel3[i]->Caption   = AnsiString();
        SuryoLabel1[i]->Caption       = AnsiString();
        SuryoLabel2[i]->Caption       = AnsiString();
        SuryoLabel3[i]->Caption       = AnsiString();
        TaniLabel1[i]->Caption        = AnsiString();
        TaniLabel2[i]->Caption        = AnsiString();
        TaniLabel3[i]->Caption        = AnsiString();
        TankaLabel1[i]->Caption       = AnsiString();
        TankaLabel2[i]->Caption       = AnsiString();
        TankaLabel3[i]->Caption       = AnsiString();
        MoneyLabel1[i]->Caption       = AnsiString();
        MoneyLabel2[i]->Caption       = AnsiString();
        MoneyLabel3[i]->Caption       = AnsiString();
    }

    // 合計ラベルクリア
    for (int i = 0; i < 3; i++){
        BikouLabel[i]->Enabled           = true;
        TotalNetTitleLabel[i]->Enabled   = true;
        TotalNetLabel[i]->Enabled        = true;
        SumMoneyTitleLabel[i]->Enabled   = true;
        SumMoneyLabel[i]->Enabled        = true;
        TaxTitleLabel[i]->Enabled        = true;
        TaxLabel[i]->Enabled             = true;
        TotalMoneyTitleLabel[i]->Enabled = true;
        TotalMoneyLabel[i]->Enabled      = true;

        BikouLabel[i]->Caption      = AnsiString();
        TotalNetLabel[i]->Caption   = AnsiString();
        SumMoneyLabel[i]->Caption   = AnsiString();
        TaxLabel[i]->Caption        = AnsiString();
        TotalMoneyLabel[i]->Caption = AnsiString();
    }

    // 明細ラベルセット
    int total_net_weight = 0;
    Currency sum_money   = 0;
    Currency sum_tax     = 0;
    int coord, reduc;
    for (unsigned int i = 0; i < slip_set_.size(); i++){
        MeisaiNoLabel1[i]->Caption = ToInt(slip_set_[i]["行No"]);
        MeisaiNoLabel2[i]->Caption = ToInt(slip_set_[i]["行No"]);
        MeisaiNoLabel3[i]->Caption = ToInt(slip_set_[i]["行No"]);
        HinNameLabel1[i]->Caption  = ToString(slip_set_[i]["品目略称"]);
        HinNameLabel2[i]->Caption  = ToString(slip_set_[i]["品目略称"]);
        HinNameLabel3[i]->Caption  = ToString(slip_set_[i]["品目略称"]);

        GrossWeightLabel1[i]->Caption  = FormatFloat("#,##0kg", ToInt(slip_set_[i]["1回目重量"]));
        GrossWeightLabel2[i]->Caption  = FormatFloat("#,##0kg", ToInt(slip_set_[i]["1回目重量"]));
        GrossWeightLabel3[i]->Caption  = FormatFloat("#,##0kg", ToInt(slip_set_[i]["1回目重量"]));
        EmptyWeightLabel1[i]->Caption  = FormatFloat("#,##0kg", ToInt(slip_set_[i]["2回目重量"]));
        EmptyWeightLabel2[i]->Caption  = FormatFloat("#,##0kg", ToInt(slip_set_[i]["2回目重量"]));
        EmptyWeightLabel3[i]->Caption  = FormatFloat("#,##0kg", ToInt(slip_set_[i]["2回目重量"]));
        NetWeightLabel1[i]->Caption    = FormatFloat("#,##0kg", ToInt(slip_set_[i]["正味重量"]));
        NetWeightLabel2[i]->Caption    = FormatFloat("#,##0kg", ToInt(slip_set_[i]["正味重量"]));
        NetWeightLabel3[i]->Caption    = FormatFloat("#,##0kg", ToInt(slip_set_[i]["正味重量"]));
        total_net_weight              += ToInt(slip_set_[i]["正味重量"]);

        coord = ToInt(slip_set_[i]["調整重量"]);
        reduc = ToInt(slip_set_[i]["重量引き"]);
        if (coord != 0 || reduc != 0){
            ReducLabel1[i]->Caption = FormatFloat("#,##0kg", coord + reduc);
            ReducLabel2[i]->Caption = FormatFloat("#,##0kg", coord + reduc);
            ReducLabel3[i]->Caption = FormatFloat("#,##0kg", coord + reduc);
        }else{
            ReducLabel1[i]->Enabled = false;
            ReducLabel2[i]->Enabled = false;
            ReducLabel3[i]->Enabled = false;
        }

        if (ToCurrency(slip_set_[i]["数量"]) == 0 || !ToBit(DM->CFG["単価使用区分"])){
            SuryoLabel1[i]->Enabled = false;
            SuryoLabel2[i]->Enabled = false;
            SuryoLabel3[i]->Enabled = false;
        }else if (ToInt(slip_set_[i]["単位ID"]) == 3){
            // 単位がkgの場合は整数のみ表示
            SuryoLabel1[i]->Caption = FormatFloat("#,##0", ToCurrency(slip_set_[i]["数量"]));
            SuryoLabel2[i]->Caption = FormatFloat("#,##0", ToCurrency(slip_set_[i]["数量"]));
            SuryoLabel3[i]->Caption = FormatFloat("#,##0", ToCurrency(slip_set_[i]["数量"]));
        }else if (ToInt(DM->CFG["換算端数処理桁数"]) == -1){
            SuryoLabel1[i]->Caption = FormatFloat("#,##0.0", ToCurrency(slip_set_[i]["数量"]));
            SuryoLabel2[i]->Caption = FormatFloat("#,##0.0", ToCurrency(slip_set_[i]["数量"]));
            SuryoLabel3[i]->Caption = FormatFloat("#,##0.0", ToCurrency(slip_set_[i]["数量"]));
        }else if (ToInt(DM->CFG["換算端数処理桁数"]) == -2){
            SuryoLabel1[i]->Caption = FormatFloat("#,##0.00", ToCurrency(slip_set_[i]["数量"]));
            SuryoLabel2[i]->Caption = FormatFloat("#,##0.00", ToCurrency(slip_set_[i]["数量"]));
            SuryoLabel3[i]->Caption = FormatFloat("#,##0.00", ToCurrency(slip_set_[i]["数量"]));
        }else{
            SuryoLabel1[i]->Caption = FormatFloat("#,###.###", ToCurrency(slip_set_[i]["数量"]));
            SuryoLabel2[i]->Caption = FormatFloat("#,###.###", ToCurrency(slip_set_[i]["数量"]));
            SuryoLabel3[i]->Caption = FormatFloat("#,###.###", ToCurrency(slip_set_[i]["数量"]));
        }

        if (ToCurrency(slip_set_[i]["数量"]) == 0 || !ToBit(DM->CFG["単価使用区分"])){
            TaniLabel1[i]->Enabled = false;
            TaniLabel2[i]->Enabled = false;
            TaniLabel3[i]->Enabled = false;
        }else{
            TaniLabel1[i]->Caption = ToString(slip_set_[i]["単位マスタ名称"]);
            TaniLabel2[i]->Caption = ToString(slip_set_[i]["単位マスタ名称"]);
            TaniLabel3[i]->Caption = ToString(slip_set_[i]["単位マスタ名称"]);
        }

        TankaLabel1[i]->Enabled = kingaku_print1_;
        TankaLabel2[i]->Enabled = kingaku_print2_;
        TankaLabel3[i]->Enabled = kingaku_print3_;
        MoneyLabel1[i]->Enabled = kingaku_print1_;
        MoneyLabel2[i]->Enabled = kingaku_print2_;
        MoneyLabel3[i]->Enabled = kingaku_print3_;

        if (kingaku_print1_){
            TankaLabel1[i]->Caption  = FormatFloat("\\#,##0.###", ToCurrency(slip_set_[i]["単価"]));
            MoneyLabel1[i]->Caption  = FormatFloat("\\#,##0", ToInt(slip_set_[i]["金額"]));
        }
        if (kingaku_print2_){
            TankaLabel2[i]->Caption  = FormatFloat("\\#,##0.###", ToCurrency(slip_set_[i]["単価"]));
            MoneyLabel2[i]->Caption  = FormatFloat("\\#,##0", ToInt(slip_set_[i]["金額"]));
        }
        if (kingaku_print3_){
            TankaLabel3[i]->Caption  = FormatFloat("\\#,##0.###", ToCurrency(slip_set_[i]["単価"]));
            MoneyLabel3[i]->Caption  = FormatFloat("\\#,##0", ToInt(slip_set_[i]["金額"]));
        }
        if (kingaku_print1_ || kingaku_print2_ || kingaku_print3_){
			sum_money += ToInt(slip_set_[i]["金額"]);
			if (ToString(DM->CFG["多段時消費税計算区分"]).ToIntDef(1) == 1)
				sum_tax = ToCurrency(slip_set_[i]["伝票消費税額"]);
			else if (ToString(DM->CFG["多段時消費税計算区分"]).ToIntDef(1) == 2)
				sum_tax += ToCurrency(slip_set_[i]["消費税額"]);
			else
				sum_tax = 0;
		}
    }

    // 金額タイトル出力
    TankaTitleLabel1->Enabled = kingaku_print1_;
    TankaTitleLabel2->Enabled = kingaku_print2_;
    TankaTitleLabel3->Enabled = kingaku_print3_;
    MoneyTitleLabel1->Enabled = kingaku_print1_;
    MoneyTitleLabel2->Enabled = kingaku_print2_;
    MoneyTitleLabel3->Enabled = kingaku_print3_;
    // 合計ラベル
    int tax_fraction = -1;
    if (!IsNull(DM->DBI.Lookup("M_得意先", "得意先ID", ToInt(SET_TOP(slip_set_)["得意先ID"]), "消費税端数処理区分")))
        tax_fraction = ToInt(DM->DBI.Lookup("M_得意先", "得意先ID", ToInt(SET_TOP(slip_set_)["得意先ID"]), "消費税端数処理区分"));
    if (tax_fraction == -1)
        tax_fraction = ToInt(DM->CFG["消費税端数処理区分"]);

    //Currency tax_rate = DM->GetSalesTax(ToInt(SET_TOP(slip_set_)["計量日"]));
    //int tax           = ExtendedRound(sum_money * tax_rate, 0, tax_fraction);
    bool kingaku_print_[3];
    kingaku_print_[0] = kingaku_print1_;
    kingaku_print_[1] = kingaku_print2_;
    kingaku_print_[2] = kingaku_print3_;
    for (int i = 0; i < 3; i++){
        BikouLabel[i]->Caption = ToString(SET_TOP(slip_set_)["備考"]);

        if (total_net_weight == 0)
            TotalNetLabel[i]->Enabled = false;
        else
            TotalNetLabel[i]->Caption = FormatFloat("#,##0kg", total_net_weight);

        SumMoneyTitleLabel[i]->Enabled   = kingaku_print_[i];
        SumMoneyLabel[i]->Enabled        = kingaku_print_[i];
        TaxTitleLabel[i]->Enabled        = kingaku_print_[i];
        TaxLabel[i]->Enabled             = kingaku_print_[i];
        TotalMoneyTitleLabel[i]->Enabled = kingaku_print_[i];
        TotalMoneyLabel[i]->Enabled      = kingaku_print_[i];

        if (kingaku_print_[i]){
            SumMoneyLabel[i]->Caption   = FormatFloat("\\#,##0", sum_money);
            TaxLabel[i]->Caption        = FormatFloat("\\#,##0", sum_tax);
            TotalMoneyLabel[i]->Caption = FormatFloat("\\#,##0", sum_money + sum_tax);
        }
    }
}
//---------------------------------------------------------------------------

