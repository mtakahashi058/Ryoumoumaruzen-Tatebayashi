//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "LaserSlipPrintM_KakeFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TLaserSlipPrintM_KakeForm *LaserSlipPrintM_KakeForm;
//---------------------------------------------------------------------------
__fastcall TLaserSlipPrintM_KakeForm::TLaserSlipPrintM_KakeForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
bool __fastcall TLaserSlipPrintM_KakeForm::Print(int keiryo_id, bool hide_time)
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

    BikouLabel[0] = BikouLabel1;
    BikouLabel[1] = BikouLabel2;
    BikouLabel[2] = BikouLabel3;

    TotalNetLabel[0] = TotalNetLabel1;
    TotalNetLabel[1] = TotalNetLabel2;
    TotalNetLabel[2] = TotalNetLabel3;

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
        TokuTitleLabel1->Caption = ToString(DM->CFG["得意先マスタ名称"]);
        TokuTitleLabel2->Caption = TokuTitleLabel1->Caption;
        TokuTitleLabel3->Caption = TokuTitleLabel1->Caption;
        TokuisakiShape1->Enabled = true;
        TokuisakiShape2->Enabled = true;
        TokuisakiShape3->Enabled = true;
    }

    if (!ToBit(DM->CFG["項目1マスタ使用区分"])){
        ItemTitleLabel11->Caption = AnsiString();
        ItemTitleLabel12->Caption = AnsiString();
        ItemTitleLabel13->Caption = AnsiString();
        Item1Shape1->Enabled      = false;
        Item1Shape2->Enabled      = false;
        Item1Shape3->Enabled      = false;
    }else{
        ItemTitleLabel11->Caption = ToString(DM->CFG["項目1マスタ名称"]);
        ItemTitleLabel12->Caption = ItemTitleLabel11->Caption;
        ItemTitleLabel13->Caption = ItemTitleLabel11->Caption;
        Item1Shape1->Enabled      = true;
        Item1Shape2->Enabled      = true;
        Item1Shape3->Enabled      = true;
    }

    if (!ToBit(DM->CFG["項目2マスタ使用区分"])){
        ItemTitleLabel21->Caption = AnsiString();
        ItemTitleLabel22->Caption = AnsiString();
        ItemTitleLabel23->Caption = AnsiString();
        Item2Shape1->Enabled      = false;
        Item2Shape2->Enabled      = false;
        Item2Shape3->Enabled      = false;
    }else{
        ItemTitleLabel21->Caption = ToString(DM->CFG["項目2マスタ名称"]);
        ItemTitleLabel22->Caption = ItemTitleLabel21->Caption;
        ItemTitleLabel23->Caption = ItemTitleLabel21->Caption;
        Item2Shape1->Enabled      = true;
        Item2Shape2->Enabled      = true;
        Item2Shape3->Enabled      = true;
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
        SuryoTitleLabel1->Caption = AnsiString();
        SuryoTitleLabel2->Caption = AnsiString();
        SuryoTitleLabel3->Caption = AnsiString();
    }else{
        SuryoTitleLabel1->Caption = "数量";
        SuryoTitleLabel2->Caption = SuryoTitleLabel1->Caption;
        SuryoTitleLabel3->Caption = SuryoTitleLabel1->Caption;
    }

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
//		TokuNameLabel1->Caption = ToString(SET_TOP(slip_set_)["得意先マスタ名称"]);
//		TokuNameLabel2->Caption = ToString(SET_TOP(slip_set_)["得意先マスタ名称"]);
//		TokuNameLabel3->Caption = ToString(SET_TOP(slip_set_)["得意先マスタ名称"]);
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

    if (!ToBit(DM->CFG["項目2マスタ使用区分"])){
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
void __fastcall TLaserSlipPrintM_KakeForm::SetDataLabel()
{
    // 明細ラベルクリア
    for (int i = 0; i < 6; i++){
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
    }

    // 合計ラベルクリア
    for (int i = 0; i < 3; i++){
        BikouLabel[i]->Caption    = AnsiString();
        TotalNetLabel[i]->Caption = AnsiString();
    }

    // 明細ラベルセット
    int total_net_weight = 0;
    Currency coord, reduc;
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
            ReducLabel1[i]->Caption = AnsiString();
            ReducLabel2[i]->Caption = AnsiString();
            ReducLabel3[i]->Caption = AnsiString();
        }

        if (ToCurrency(slip_set_[i]["数量"]) == 0 || !ToBit(DM->CFG["単価使用区分"])){
            SuryoLabel1[i]->Caption = AnsiString();
            SuryoLabel2[i]->Caption = AnsiString();
            SuryoLabel3[i]->Caption = AnsiString();
        }else if (ToInt(slip_set_[i]["単位ID"]) == 3){
            // 単位がkgの場合は整数表示のみ
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
            TaniLabel1[i]->Caption = AnsiString();
            TaniLabel2[i]->Caption = AnsiString();
            TaniLabel3[i]->Caption = AnsiString();
        }else{
            TaniLabel1[i]->Caption = ToString(slip_set_[i]["単位マスタ名称"]);
            TaniLabel2[i]->Caption = ToString(slip_set_[i]["単位マスタ名称"]);
            TaniLabel3[i]->Caption = ToString(slip_set_[i]["単位マスタ名称"]);
        }
    }

    // 合計ラベル
    for (int i = 0; i < 3; i++){
        BikouLabel[i]->Caption = ToString(SET_TOP(slip_set_)["備考"]);

        if (total_net_weight == 0)
            TotalNetLabel[i]->Caption = AnsiString();
        else
            TotalNetLabel[i]->Caption = FormatFloat("#,##0kg", total_net_weight);
    }
}
//---------------------------------------------------------------------------
