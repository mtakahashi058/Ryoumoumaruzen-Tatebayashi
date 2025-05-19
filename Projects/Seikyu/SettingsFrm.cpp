//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DMFrm.h"
#include "SettingsFrm.h"
#include "SeikyushoTateFrm.h"
#include "SeikyushoYokoFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma link "StrCGrid"
#pragma resource "*.dfm"
TSettingsForm *SettingsForm;
//---------------------------------------------------------------------------
__fastcall TSettingsForm::TSettingsForm(TComponent* Owner)
	: TForm(Owner)
{
	is_set = false;
	is_value_set = false;
}
//---------------------------------------------------------------------------
void __fastcall TSettingsForm::FormShow(TObject *Sender)
{
	if (!is_set){
		KomokuListGrid->Cells[1][0] = "項目";
		KomokuListGrid->Cells[2][0] = "計";
		KomokuListGrid->Cells[3][0] = "改";
		KomokuListGrid->Cells[4][0] = "順";

		for (int i = 1; i < KomokuListGrid->RowCount; i++){
			KomokuListGrid->Cells[0][i] = IntToStr(i);
			KomokuListGrid->CellAlignments[2][i] = taCenter;
			KomokuListGrid->CellAlignments[3][i] = taCenter;
			KomokuListGrid->CellAlignments[4][i] = taCenter;
		}

		PasswordEdit->Text = AnsiString();

		is_set = true;
	}

	if (!is_value_set)
		GetValueFromDB();
	SetValueToForm();
}
//---------------------------------------------------------------------------
// データベースから設定値を取得
void __fastcall TSettingsForm::GetValueFromDB()
{
	shamei		= ToString(DM->config_["請求書社名"]);
	seikyumoto[0]	= ToString(DM->config_["請求元情報01"]);
	seikyumoto[1]	= ToString(DM->config_["請求元情報02"]);
	seikyumoto[2]	= ToString(DM->config_["請求元情報03"]);
	seikyumoto[3]	= ToString(DM->config_["請求元情報04"]);
	seikyumoto[4]	= ToString(DM->config_["請求元情報05"]);
	seikyumoto[5]	= ToString(DM->config_["請求元情報06"]);
	seikyumoto[6]	= ToString(DM->config_["請求元情報07"]);
	seikyumoto[7]	= ToString(DM->config_["請求元情報08"]);
	kagami[0]	= ToString(DM->config_["請求書鑑01"]);
	kagami[1]	= ToString(DM->config_["請求書鑑02"]);
	kagami[2]	= ToString(DM->config_["請求書鑑03"]);
	kagami[3]	= ToString(DM->config_["請求書鑑04"]);
	kagami[4]	= ToString(DM->config_["請求書鑑05"]);
	kagami[5]	= ToString(DM->config_["請求書鑑06"]);
	kagami[6]	= ToString(DM->config_["請求書鑑07"]);
	mei_title[0]	= ToString(DM->config_["請求書明細タイトル01"]);
	mei_title[1]	= ToString(DM->config_["請求書明細タイトル02"]);
	mei_title[2]	= ToString(DM->config_["請求書明細タイトル03"]);
	mei_title[3]	= ToString(DM->config_["請求書明細タイトル04"]);
	mei_title[4]	= ToString(DM->config_["請求書明細タイトル05"]);
	mei_title[5]	= ToString(DM->config_["請求書明細タイトル06"]);
	mei_title[6]	= ToString(DM->config_["請求書明細タイトル07"]);
	message[0]	= ToString(DM->config_["請求書メッセージ上"]);
	message[1]	= ToString(DM->config_["請求書メッセージ中"]);
	message[2]	= ToString(DM->config_["請求書メッセージ下"]);
	orderby		= ToString(DM->config_["請求書表示順"]);
	shokei		= ToString(DM->config_["請求書小計"]);
	newpage		= ToString(DM->config_["請求書改頁"]);
	desc		= ToString(DM->config_["請求書昇降"]);
	orientation	= ToString(DM->config_["請求書縦横"]);
	output_nyukin	= ToString(DM->config_["請求書入金明細出力"]);
	output_total	= ToString(DM->config_["請求書総合計出力"]);
	biko_komoku	= ToString(DM->config_["請求書備考表示項目"]);
	bgcolor		= TColor(ToInt(DM->config_["請求書背景色"]));
	txcolor		= TColor(ToInt(DM->config_["請求書文字色"]));

	is_value_set = true;
}
//---------------------------------------------------------------------------
// 設定値をデータベースに保存
bool __fastcall TSettingsForm::SetValueToDB()
{
	try{
		DM->ADOConnection->BeginTrans();

		PostSettings("請求書社名", shamei);
		PostSettings("請求元情報01", seikyumoto[0]);
		PostSettings("請求元情報02", seikyumoto[1]);
		PostSettings("請求元情報03", seikyumoto[2]);
		PostSettings("請求元情報04", seikyumoto[3]);
		PostSettings("請求元情報05", seikyumoto[4]);
		PostSettings("請求元情報06", seikyumoto[5]);
		PostSettings("請求元情報07", seikyumoto[6]);
		PostSettings("請求元情報08", seikyumoto[7]);
		PostSettings("請求書鑑01", kagami[0]);
		PostSettings("請求書鑑02", kagami[1]);
		PostSettings("請求書鑑03", kagami[2]);
		PostSettings("請求書鑑04", kagami[3]);
		PostSettings("請求書鑑05", kagami[4]);
		PostSettings("請求書鑑06", kagami[5]);
		PostSettings("請求書鑑07", kagami[6]);
		PostSettings("請求書明細タイトル01", mei_title[0]);
		PostSettings("請求書明細タイトル02", mei_title[1]);
		PostSettings("請求書明細タイトル03", mei_title[2]);
		PostSettings("請求書明細タイトル04", mei_title[3]);
		PostSettings("請求書明細タイトル05", mei_title[4]);
		PostSettings("請求書明細タイトル06", mei_title[5]);
		PostSettings("請求書明細タイトル07", mei_title[6]);
		PostSettings("請求書メッセージ上", message[0]);
		PostSettings("請求書メッセージ中", message[1]);
		PostSettings("請求書メッセージ下", message[2]);
		PostSettings("請求書表示順", orderby);
		PostSettings("請求書小計", shokei);
		PostSettings("請求書改頁", newpage);
		PostSettings("請求書昇降", desc);
		PostSettings("請求書縦横", orientation);
		PostSettings("請求書入金明細出力", output_nyukin);
		PostSettings("請求書総合計出力", output_total);
		PostSettings("請求書備考表示項目", biko_komoku);
		PostSettings("請求書背景色", bgcolor);
		PostSettings("請求書文字色", txcolor);

		DM->ADOConnection->CommitTrans();

	}catch (Exception& e){
		DM->ADOConnection->RollbackTrans();
		Application->MessageBox(("登録に失敗しました。\r\n" + e.Message).c_str(), "設定保存", MB_OK | MB_ICONSTOP);
		return false;
	}

	return true;
}
//---------------------------------------------------------------------------
// 設定値をデータベースへ登録
void __fastcall TSettingsForm::PostSettings(AnsiString fname, AnsiString value)
{
	NsFieldSet keys, fields;
	keys	<< NsField("設定名", fname);
	fields	<< NsField("設定値", value);
	DM->DBI.Update("M_制御", keys, fields);
}
//---------------------------------------------------------------------------
// 設定変更フォームから設定値を取得
void __fastcall TSettingsForm::GetValueFromForm()
{
	shamei		= ShameiEdit->Text;
	seikyumoto[0]	= SeikyumotoEdit01->Text;
	seikyumoto[1]	= SeikyumotoEdit02->Text;
	seikyumoto[2]	= SeikyumotoEdit03->Text;
	seikyumoto[3]	= SeikyumotoEdit04->Text;
	seikyumoto[4]	= SeikyumotoEdit05->Text;
	seikyumoto[5]	= SeikyumotoEdit06->Text;
	seikyumoto[6]	= SeikyumotoEdit07->Text;
	seikyumoto[7]	= SeikyumotoEdit08->Text;
	kagami[0]	= KagamiName1Edit->Text;
	kagami[1]	= KagamiName2Edit->Text;
	kagami[2]	= KagamiName3Edit->Text;
	kagami[3]	= KagamiName4Edit->Text;
	kagami[4]	= KagamiName5Edit->Text;
	kagami[5]	= KagamiName6Edit->Text;
	kagami[6]	= KagamiName7Edit->Text;
	mei_title[0]	= DateTitleEdit->Text;
	mei_title[1]	= HinTitleEdit->Text;
	mei_title[2]	= SuryoTitleEdit->Text;
	mei_title[3]	= TaniTitleEdit->Text;
	mei_title[4]	= TankaTitleEdit->Text;
	mei_title[5]	= KingakuTitleEdit->Text;
	mei_title[6]	= BikoTitleEdit->Text;
	message[0]	= UpperMessageEdit->Text;
	message[1]	= MiddleMessageEdit->Text;
	message[2]	= LowerMessageEdit->Text;

	std::auto_ptr<TStringList> orderby_list(new TStringList());
	std::auto_ptr<TStringList> shokei_list(new TStringList());
	std::auto_ptr<TStringList> newpage_list(new TStringList());
	std::auto_ptr<TStringList> desc_list(new TStringList());

	for (int i = 1; i < KomokuListGrid->RowCount; i++){
		orderby_list->Add(KomokuListGrid->Cells[5][i]);
		shokei_list->Add( KomokuListGrid->Cells[2][i] == "●" ? 1 : 0);
		newpage_list->Add(KomokuListGrid->Cells[3][i] == "●" ? 1 : 0);
		desc_list->Add(   KomokuListGrid->Cells[4][i] == "●" ? 1 : 0);
	}

	orderby = orderby_list->CommaText;
	shokei  = shokei_list->CommaText;
	newpage = newpage_list->CommaText;
	desc    = desc_list->CommaText;

	orientation	= MukiRadio->ItemIndex + 1;
	output_nyukin	= NyukinRadio->ItemIndex + 1;
	output_total	= TotalRadio->ItemIndex + 1;
	biko_komoku	= BikoItemComboBox->Items->Strings[BikoItemComboBox->ItemIndex].SubString(1, 2).ToIntDef(14);
	bgcolor		= ColorPanel1->Color;
	txcolor		= KagamiName1Edit->Font->Color;
}
//---------------------------------------------------------------------------
// スペースを除く
AnsiString __fastcall TSettingsForm::RemoveSpace(AnsiString buff)
{
	buff = AnsiReplaceStr(buff, " ", "");
	buff = AnsiReplaceStr(buff, "　", "");
	return buff;
}
//---------------------------------------------------------------------------
// 項目番号からフィールド名を返す
AnsiString __fastcall TSettingsForm::GetKomokuName(AnsiString mode, int komoku_id)
{
	int mno;
	if (mode == "display")
		mno = 1;
	else if (mode == "komoku")
		mno = 2;
	else if (mode == "code")
		mno = 3;
	else if (mode == "name")
		mno = 4;
	else{
		Application->MessageBox("設定値がセットされていません（SettingForm->GetKomokuName）", "設定", MB_OK | MB_ICONSTOP);
		return AnsiString();
	}

	int id = mno * 100 + komoku_id;

	switch (id){
	/* 表示用 */
	case 101 :	return "請求先";
	case 102 :	return "売上入金区分";
	case 103 :	return "得意先";
	case 104 :	return "取引日";
	case 105 :	return "伝票No";
	case 106 :	return "行No";
	case 107 :	return "拠点";
	case 108 :	return "品目分類";
	case 109 :	return "品目";
	case 110 :	return "項目1";
	case 111 :	return "項目2";
	case 112 :	return "車両";
	case 113 :	return "単位";
	case 114 :	return "備考";
	case 115 :	return "明細備考";
	/* フィールド名 */
	case 201 :	return "請求先";
	case 202 :	return "売上入金区分";
	case 203 :	return RemoveSpace(DM->config_["得意先マスタ名称"]);
	case 204 :	return "取引日";
	case 205 :	return "伝票No";
	case 206 :	return "行No";
	case 207 :	return "拠点";
	case 208 :	return "品目分類";
	case 209 :	return RemoveSpace(DM->config_["品目マスタ名称"]);
	case 210 :	return RemoveSpace(DM->config_["項目1マスタ名称"]);
	case 211 :	return RemoveSpace(DM->config_["項目2マスタ名称"]);
	case 212 :	return "車両";
	case 213 :	return "単位";
	case 214 :	return "備考";
	case 215 :	return "明細備考";
	/* コード名 */
	case 301 :	return "請求先コード";
	case 302 :	return "売上入金区分";
	case 303 :	return "得意先コード";
	case 304 :	return "取引日";
	case 305 :	return "伝票No";
	case 306 :	return "行No";
	case 307 :	return "拠点ID";
	case 308 :	return "品目分類コード";
	case 309 :	return "品目コード";
	case 310 :	return "項目1コード";
	case 311 :	return "項目2コード";
	case 312 :	return "車番";
	case 313 :	return "単位コード";
	case 314 :	return "備考";
	case 315 :	return "明細備考";
	/* 名称 */
	case 401 :	return "請求先名称";
	case 402 :	return "売上入金区分名称";
	case 403 :	return "得意先名称";
	case 404 :	return "取引日";
	case 405 :	return "伝票No";
	case 406 :	return "行No";
	case 407 :	return "拠点名称";
	case 408 :	return "品目分類名称";
	case 409 :	return "品目名称";
	case 410 :	return "項目1名称";
	case 411 :	return "項目2名称";
	case 412 :	return "車番";
	case 413 :	return "単位名称";
	case 414 :	return "備考";
	case 415 :	return "明細備考";
	default :	return AnsiString();
	}
}
//---------------------------------------------------------------------------
// 設定値を設定変更フォームに適用
void __fastcall TSettingsForm::SetValueToForm()
{
	ShameiEdit->Text = shamei;
	SeikyumotoEdit01->Text = seikyumoto[0];
	SeikyumotoEdit02->Text = seikyumoto[1];
	SeikyumotoEdit03->Text = seikyumoto[2];
	SeikyumotoEdit04->Text = seikyumoto[3];
	SeikyumotoEdit05->Text = seikyumoto[4];
	SeikyumotoEdit06->Text = seikyumoto[5];
	SeikyumotoEdit07->Text = seikyumoto[6];
	SeikyumotoEdit08->Text = seikyumoto[7];
	KagamiName1Edit->Text = kagami[0];
	KagamiName2Edit->Text = kagami[1];
	KagamiName3Edit->Text = kagami[2];
	KagamiName4Edit->Text = kagami[3];
	KagamiName5Edit->Text = kagami[4];
	KagamiName6Edit->Text = kagami[5];
	KagamiName7Edit->Text = kagami[6];
	DateTitleEdit->Text    = mei_title[0];
	HinTitleEdit->Text     = mei_title[1];
	SuryoTitleEdit->Text   = mei_title[2];
	TaniTitleEdit->Text    = mei_title[3];
	TankaTitleEdit->Text   = mei_title[4];
	KingakuTitleEdit->Text = mei_title[5];
	BikoTitleEdit->Text    = mei_title[6];
	UpperMessageEdit->Text	= message[0];
	MiddleMessageEdit->Text	= message[1];
	LowerMessageEdit->Text	= message[2];

	std::auto_ptr<TStringList> orderby_list(new TStringList());
	std::auto_ptr<TStringList> shokei_list(new TStringList());
	std::auto_ptr<TStringList> newpage_list(new TStringList());
	std::auto_ptr<TStringList> desc_list(new TStringList());

	orderby_list->CommaText = orderby;
	shokei_list->CommaText  = shokei;
	newpage_list->CommaText = newpage;
	desc_list->CommaText    = desc;

	for (int i = 0; i < orderby_list->Count; i++){
		KomokuListGrid->Cells[1][i + 1] = GetKomokuName("display", orderby_list->Strings[i].ToIntDef(0));
		KomokuListGrid->Cells[2][i + 1] = shokei_list->Strings[i].ToIntDef(0)  == 0 ? "" : "●";
		KomokuListGrid->Cells[3][i + 1] = newpage_list->Strings[i].ToIntDef(0) == 0 ? "" : "●";
		KomokuListGrid->Cells[4][i + 1] = desc_list->Strings[i].ToIntDef(0)    == 0 ? "" : "●";
		KomokuListGrid->Cells[5][i + 1] = orderby_list->Strings[i];
	}

	MukiRadio->ItemIndex = orientation == 1 ? 0 : 1;
	NyukinRadio->ItemIndex = output_nyukin == 1 ? 0 : 1;
	TotalRadio->ItemIndex = output_total == 1 ? 0 : 1;
	BikoItemComboBox->ItemIndex = biko_komoku.ToIntDef(14) - 1;
	ColorPanel->Color  = bgcolor;
	ColorPanel1->Color = bgcolor;
	ColorPanel2->Color = bgcolor;
	ColorPanel3->Color = bgcolor;
	KagamiName1Edit->Color = bgcolor;
	KagamiName2Edit->Color = bgcolor;
	KagamiName3Edit->Color = bgcolor;
	KagamiName4Edit->Color = bgcolor;
	KagamiName5Edit->Color = bgcolor;
	KagamiName6Edit->Color = bgcolor;
	KagamiName7Edit->Color = bgcolor;
	DateTitleEdit->Color   = bgcolor;
	HinTitleEdit->Color    = bgcolor;
	SuryoTitleEdit->Color  = bgcolor;
	TaniTitleEdit->Color   = bgcolor;
	TankaTitleEdit->Color  = bgcolor;
	KingakuTitleEdit->Color = bgcolor;
	BikoTitleEdit->Color   = bgcolor;
	TitleLabel->Font->Color      = txcolor;
	KagamiName1Edit->Font->Color = txcolor;
	KagamiName2Edit->Font->Color = txcolor;
	KagamiName3Edit->Font->Color = txcolor;
	KagamiName4Edit->Font->Color = txcolor;
	KagamiName5Edit->Font->Color = txcolor;
	KagamiName6Edit->Font->Color = txcolor;
	KagamiName7Edit->Font->Color = txcolor;
	DateTitleEdit->Font->Color   = txcolor;
	HinTitleEdit->Font->Color    = txcolor;
	SuryoTitleEdit->Font->Color  = txcolor;
	TaniTitleEdit->Font->Color   = txcolor;
	TankaTitleEdit->Font->Color  = txcolor;
	KingakuTitleEdit->Font->Color = txcolor;
	BikoTitleEdit->Font->Color   = txcolor;
}
//---------------------------------------------------------------------------
// 設定値を請求書へ反映
void __fastcall TSettingsForm::SetSeikyusho()
{
	// データベースより設定値をロード
	GetValueFromDB();

	std::auto_ptr<TStringList> orderby_list(new TStringList());
	std::auto_ptr<TStringList> shokei_list(new TStringList());
	std::auto_ptr<TStringList> newpage_list(new TStringList());
	std::auto_ptr<TStringList> desc_list(new TStringList());
	std::auto_ptr<TStringList> sql_orderby_list(new TStringList());

	orderby_list->CommaText = orderby;
	shokei_list->CommaText  = shokei;
	newpage_list->CommaText = newpage;
	desc_list->CommaText    = desc;

	std::auto_ptr<TStringList> expression_list(new TStringList());
	expression_list->Add("請求先コード");
	AnsiString sql_expression;	// 改頁用フィールドを作成

	if (orientation == "1"){	// 請求書＝縦
		report_form	= SeikyushoTateForm;
		report		= SeikyushoTateForm->QuickRep;
		title_label	= SeikyushoTateForm->TitleLabel;
		date_label	= SeikyushoTateForm->DateLabel;
		seikyusaki_label= SeikyushoTateForm->SeikyusakiLabel;

		SeikyushoTateForm->GroupHeaderSeikyu->ForceNewPage = true;	// 請求先で改頁をデフォルト

		SeikyushoTateForm->ShameiLabel->Caption = shamei;
		SeikyushoTateForm->SeikyumotoLabel01->Caption = seikyumoto[0];
		SeikyushoTateForm->SeikyumotoLabel02->Caption = seikyumoto[1];
		SeikyushoTateForm->SeikyumotoLabel03->Caption = seikyumoto[2];
		SeikyushoTateForm->SeikyumotoLabel04->Caption = seikyumoto[3];
		SeikyushoTateForm->SeikyumotoLabel05->Caption = seikyumoto[4];
		SeikyushoTateForm->SeikyumotoLabel06->Caption = seikyumoto[5];
		SeikyushoTateForm->SeikyumotoLabel07->Caption = seikyumoto[6];
		SeikyushoTateForm->SeikyumotoLabel08->Caption = seikyumoto[7];
		SeikyushoTateForm->KagamiLabel01->Caption = kagami[0];
		SeikyushoTateForm->KagamiLabel02->Caption = kagami[1];
		SeikyushoTateForm->KagamiLabel03->Caption = kagami[2];
		SeikyushoTateForm->KagamiLabel04->Caption = kagami[3];
		SeikyushoTateForm->KagamiLabel05->Caption = kagami[4];
		SeikyushoTateForm->KagamiLabel06->Caption = kagami[5];
		SeikyushoTateForm->KagamiLabel07->Caption = kagami[6];
		SeikyushoTateForm->MeiTitleLabel01->Caption = mei_title[0];
		SeikyushoTateForm->MeiTitleLabel02->Caption = mei_title[1];
		SeikyushoTateForm->MeiTitleLabel03->Caption = mei_title[2];
		SeikyushoTateForm->MeiTitleLabel04->Caption = mei_title[3];
		SeikyushoTateForm->MeiTitleLabel05->Caption = mei_title[4];
		SeikyushoTateForm->MeiTitleLabel06->Caption = mei_title[5];
		SeikyushoTateForm->MeiTitleLabel07->Caption = mei_title[6];
		SeikyushoTateForm->MeiTitleLabel01_->Caption = mei_title[0];
		SeikyushoTateForm->MeiTitleLabel02_->Caption = mei_title[1];
		SeikyushoTateForm->MeiTitleLabel03_->Caption = mei_title[2];
		SeikyushoTateForm->MeiTitleLabel04_->Caption = mei_title[3];
		SeikyushoTateForm->MeiTitleLabel05_->Caption = mei_title[4];
		SeikyushoTateForm->MeiTitleLabel06_->Caption = mei_title[5];
		SeikyushoTateForm->MeiTitleLabel07_->Caption = mei_title[6];
		SeikyushoTateForm->Message1Label->Caption = message[0];
		SeikyushoTateForm->Message2Label->Caption = message[1];
		SeikyushoTateForm->Message3Label->Caption = message[2];

		// 小計用グループの [Enabled] をリセット
		SeikyushoTateForm->GroupHeader1->Enabled = false;
		SeikyushoTateForm->GroupHeader2->Enabled = false;
		SeikyushoTateForm->GroupHeader3->Enabled = false;
		SeikyushoTateForm->GroupHeader4->Enabled = false;
		SeikyushoTateForm->GroupHeader5->Enabled = false;
		SeikyushoTateForm->GroupFooter1->Enabled = false;
		SeikyushoTateForm->GroupFooter2->Enabled = false;
		SeikyushoTateForm->GroupFooter3->Enabled = false;
		SeikyushoTateForm->GroupFooter4->Enabled = false;
		SeikyushoTateForm->GroupFooter5->Enabled = false;

		// 小計
		int shokei_count = 0;
		for (int i = 0; i < orderby_list->Count; i++){
			// ORDER BY & 昇降
			if (desc_list->Strings[i].ToIntDef(0) == 0)
				sql_orderby_list->Add(GetKomokuName("code", orderby_list->Strings[i].ToIntDef(0)));
			else
				sql_orderby_list->Add(GetKomokuName("code", orderby_list->Strings[i].ToIntDef(0)) + " DESC");
			// 小計
			if (shokei_list->Strings[i].ToIntDef(0) == 1){
				shokei_count++;
				if (shokei_count == 1){
					SeikyushoTateForm->GroupHeader1->Enabled = true;
					SeikyushoTateForm->GroupHeader1->Expression = "Q_Seikyu.G1";
					expression_list->Add(GetKomokuName("code", orderby_list->Strings[i].ToIntDef(0)));
					sql_expression += GetExpressionSql(expression_list->CommaText, "G1");
					SeikyushoTateForm->GroupHeader1->ForceNewPage = newpage_list->Strings[i].ToIntDef(0) == 1 ? true : false;
					SeikyushoTateForm->GroupFooter1->Enabled = true;
					SeikyushoTateForm->name1   = GetKomokuName("name",   orderby_list->Strings[i].ToIntDef(0));
					SeikyushoTateForm->komoku1 = GetKomokuName("komoku", orderby_list->Strings[i].ToIntDef(0));

				}else if (shokei_count == 2){
					SeikyushoTateForm->GroupHeader2->Enabled = true;
					SeikyushoTateForm->GroupHeader2->Expression = "Q_Seikyu.G2";
					expression_list->Add(GetKomokuName("code", orderby_list->Strings[i].ToIntDef(0)));
					sql_expression += GetExpressionSql(expression_list->CommaText, "G2");
					SeikyushoTateForm->GroupHeader2->ForceNewPage = newpage_list->Strings[i].ToIntDef(0) == 1 ? true : false;
					SeikyushoTateForm->GroupFooter2->Enabled = true;
					SeikyushoTateForm->name2   = GetKomokuName("name",   orderby_list->Strings[i].ToIntDef(0));
					SeikyushoTateForm->komoku2 = GetKomokuName("komoku", orderby_list->Strings[i].ToIntDef(0));

				}else if (shokei_count == 3){
					SeikyushoTateForm->GroupHeader3->Enabled = true;
					SeikyushoTateForm->GroupHeader3->Expression = "Q_Seikyu.G3";
					expression_list->Add(GetKomokuName("code", orderby_list->Strings[i].ToIntDef(0)));
					sql_expression += GetExpressionSql(expression_list->CommaText, "G3");
					SeikyushoTateForm->GroupHeader3->ForceNewPage = newpage_list->Strings[i].ToIntDef(0) == 1 ? true : false;
					SeikyushoTateForm->GroupFooter3->Enabled = true;
					SeikyushoTateForm->name3   = GetKomokuName("name",   orderby_list->Strings[i].ToIntDef(0));
					SeikyushoTateForm->komoku3 = GetKomokuName("komoku", orderby_list->Strings[i].ToIntDef(0));

				}else if (shokei_count == 4){
					SeikyushoTateForm->GroupHeader4->Enabled = true;
					SeikyushoTateForm->GroupHeader3->Expression = "Q_Seikyu.G4";
					expression_list->Add(GetKomokuName("code", orderby_list->Strings[i].ToIntDef(0)));
					sql_expression += GetExpressionSql(expression_list->CommaText, "G4");
					SeikyushoTateForm->GroupHeader4->ForceNewPage = newpage_list->Strings[i].ToIntDef(0) == 1 ? true : false;
					SeikyushoTateForm->GroupFooter4->Enabled = true;
					SeikyushoTateForm->name4   = GetKomokuName("name",   orderby_list->Strings[i].ToIntDef(0));
					SeikyushoTateForm->komoku4 = GetKomokuName("komoku", orderby_list->Strings[i].ToIntDef(0));

				}else if (shokei_count == 5){
					SeikyushoTateForm->GroupHeader5->Enabled = true;
					SeikyushoTateForm->GroupHeader3->Expression = "Q_Seikyu.G5";
					expression_list->Add(GetKomokuName("code", orderby_list->Strings[i].ToIntDef(0)));
					sql_expression += GetExpressionSql(expression_list->CommaText, "G5");
					SeikyushoTateForm->GroupHeader5->ForceNewPage = newpage_list->Strings[i].ToIntDef(0) == 1 ? true : false;
					SeikyushoTateForm->GroupFooter5->Enabled = true;
					SeikyushoTateForm->name5   = GetKomokuName("name",   orderby_list->Strings[i].ToIntDef(0));
					SeikyushoTateForm->komoku5 = GetKomokuName("komoku", orderby_list->Strings[i].ToIntDef(0));
				}
			}
		}

		// 改頁はグループの下位のみにする
		if (SeikyushoTateForm->GroupHeader5->ForceNewPage){
			SeikyushoTateForm->GroupHeaderSeikyu->ForceNewPage = false;
			SeikyushoTateForm->GroupHeaderSeikyu->Enabled = false;
			SeikyushoTateForm->GroupHeader1->ForceNewPage = false;
			SeikyushoTateForm->GroupHeader1->Enabled = false;
			SeikyushoTateForm->GroupHeader2->ForceNewPage = false;
			SeikyushoTateForm->GroupHeader2->Enabled = false;
			SeikyushoTateForm->GroupHeader3->ForceNewPage = false;
			SeikyushoTateForm->GroupHeader3->Enabled = false;
			SeikyushoTateForm->GroupHeader4->ForceNewPage = false;
			SeikyushoTateForm->GroupHeader4->Enabled = false;

		}else if (SeikyushoTateForm->GroupHeader4->ForceNewPage){
			SeikyushoTateForm->GroupHeaderSeikyu->ForceNewPage = false;
			SeikyushoTateForm->GroupHeaderSeikyu->Enabled = false;
			SeikyushoTateForm->GroupHeader1->ForceNewPage = false;
			SeikyushoTateForm->GroupHeader1->Enabled = false;
			SeikyushoTateForm->GroupHeader2->ForceNewPage = false;
			SeikyushoTateForm->GroupHeader2->Enabled = false;
			SeikyushoTateForm->GroupHeader3->ForceNewPage = false;
			SeikyushoTateForm->GroupHeader3->Enabled = false;

		}else if (SeikyushoTateForm->GroupHeader3->ForceNewPage){
			SeikyushoTateForm->GroupHeaderSeikyu->ForceNewPage = false;
			SeikyushoTateForm->GroupHeaderSeikyu->Enabled = false;
			SeikyushoTateForm->GroupHeader1->ForceNewPage = false;
			SeikyushoTateForm->GroupHeader1->Enabled = false;
			SeikyushoTateForm->GroupHeader2->ForceNewPage = false;
			SeikyushoTateForm->GroupHeader2->Enabled = false;

		}else if (SeikyushoTateForm->GroupHeader2->ForceNewPage){
			SeikyushoTateForm->GroupHeaderSeikyu->ForceNewPage = false;
			SeikyushoTateForm->GroupHeaderSeikyu->Enabled = false;
			SeikyushoTateForm->GroupHeader1->ForceNewPage = false;
			SeikyushoTateForm->GroupHeader1->Enabled = false;

		}else if (SeikyushoTateForm->GroupHeader1->ForceNewPage){
			SeikyushoTateForm->GroupHeaderSeikyu->ForceNewPage = false;
			SeikyushoTateForm->GroupHeaderSeikyu->Enabled = false;
		}
/*		if (SeikyushoTateForm->GroupHeaderSeikyu->ForceNewPage)
			ShowMessage("seikyu: " + SeikyushoTateForm->GroupHeaderSeikyu->Expression);
		if (SeikyushoTateForm->GroupHeader1->ForceNewPage)
			ShowMessage("g1: " + SeikyushoTateForm->GroupHeader1->Expression);
		if (SeikyushoTateForm->GroupHeader2->ForceNewPage)
			ShowMessage("g2: " + SeikyushoTateForm->GroupHeader2->Expression);
		if (SeikyushoTateForm->GroupHeader3->ForceNewPage)
			ShowMessage("g3: " + SeikyushoTateForm->GroupHeader3->Expression);
		if (SeikyushoTateForm->GroupHeader4->ForceNewPage)
			ShowMessage("g4: " + SeikyushoTateForm->GroupHeader4->Expression);
		if (SeikyushoTateForm->GroupHeader5->ForceNewPage)
			ShowMessage("g5: " + SeikyushoTateForm->GroupHeader5->Expression);
*/
		// 総合計出力
		SeikyushoTateForm->div_total = output_total.ToIntDef(2) == 1 ? true : false;
		// 備考表示項目
		SeikyushoTateForm->QRDBTextBiko->DataField = GetKomokuName("name", biko_komoku.ToIntDef(14));
		// 背景色
		SeikyushoTateForm->ColorShape->Brush->Color  = bgcolor;
		SeikyushoTateForm->ColorShape1->Brush->Color = bgcolor;
		SeikyushoTateForm->ColorShape2->Brush->Color = bgcolor;
		SeikyushoTateForm->ColorShape3->Brush->Color = bgcolor;
		SeikyushoTateForm->ColorShape3_->Brush->Color = bgcolor;
		SeikyushoTateForm->ColorShape4->Brush->Color = bgcolor;
		// 文字色
		SeikyushoTateForm->TitleLabel->Font->Color    = txcolor;
		SeikyushoTateForm->KagamiLabel01->Font->Color = txcolor;
		SeikyushoTateForm->KagamiLabel02->Font->Color = txcolor;
		SeikyushoTateForm->KagamiLabel03->Font->Color = txcolor;
		SeikyushoTateForm->KagamiLabel04->Font->Color = txcolor;
		SeikyushoTateForm->KagamiLabel05->Font->Color = txcolor;
		SeikyushoTateForm->KagamiLabel06->Font->Color = txcolor;
		SeikyushoTateForm->KagamiLabel07->Font->Color = txcolor;
		SeikyushoTateForm->MeiTitleLabel01->Font->Color = txcolor;
		SeikyushoTateForm->MeiTitleLabel02->Font->Color = txcolor;
		SeikyushoTateForm->MeiTitleLabel03->Font->Color = txcolor;
		SeikyushoTateForm->MeiTitleLabel04->Font->Color = txcolor;
		SeikyushoTateForm->MeiTitleLabel05->Font->Color = txcolor;
		SeikyushoTateForm->MeiTitleLabel06->Font->Color = txcolor;
		SeikyushoTateForm->MeiTitleLabel07->Font->Color = txcolor;
		SeikyushoTateForm->MeiTitleLabel01_->Font->Color = txcolor;
		SeikyushoTateForm->MeiTitleLabel02_->Font->Color = txcolor;
		SeikyushoTateForm->MeiTitleLabel03_->Font->Color = txcolor;
		SeikyushoTateForm->MeiTitleLabel04_->Font->Color = txcolor;
		SeikyushoTateForm->MeiTitleLabel05_->Font->Color = txcolor;
		SeikyushoTateForm->MeiTitleLabel06_->Font->Color = txcolor;
		SeikyushoTateForm->MeiTitleLabel07_->Font->Color = txcolor;

	}else{		// 請求書＝横

		report_form	= SeikyushoYokoForm;
		report		= SeikyushoYokoForm->QuickRep;
		title_label	= SeikyushoYokoForm->TitleLabel;
		date_label	= SeikyushoYokoForm->DateLabel;
		seikyusaki_label= SeikyushoYokoForm->SeikyusakiLabel;

		SeikyushoYokoForm->GroupHeaderSeikyu->ForceNewPage = true;	// 請求先で改頁をデフォルト

		SeikyushoYokoForm->ShameiLabel->Caption = shamei;
		SeikyushoYokoForm->SeikyumotoLabel01->Caption = seikyumoto[0];
		SeikyushoYokoForm->SeikyumotoLabel02->Caption = seikyumoto[1];
		SeikyushoYokoForm->SeikyumotoLabel03->Caption = seikyumoto[2];
		SeikyushoYokoForm->SeikyumotoLabel04->Caption = seikyumoto[3];
		SeikyushoYokoForm->SeikyumotoLabel05->Caption = seikyumoto[4];
		SeikyushoYokoForm->SeikyumotoLabel06->Caption = seikyumoto[5];
		SeikyushoYokoForm->SeikyumotoLabel07->Caption = seikyumoto[6];
		SeikyushoYokoForm->SeikyumotoLabel08->Caption = seikyumoto[7];
		SeikyushoYokoForm->KagamiLabel01->Caption = kagami[0];
		SeikyushoYokoForm->KagamiLabel02->Caption = kagami[1];
		SeikyushoYokoForm->KagamiLabel03->Caption = kagami[2];
		SeikyushoYokoForm->KagamiLabel04->Caption = kagami[3];
		SeikyushoYokoForm->KagamiLabel05->Caption = kagami[4];
		SeikyushoYokoForm->KagamiLabel06->Caption = kagami[5];
		SeikyushoYokoForm->KagamiLabel07->Caption = kagami[6];
		SeikyushoYokoForm->MeiTitleLabel01->Caption = mei_title[0];
		SeikyushoYokoForm->MeiTitleLabel02->Caption = mei_title[1];
		SeikyushoYokoForm->MeiTitleLabel03->Caption = mei_title[2];
		SeikyushoYokoForm->MeiTitleLabel04->Caption = mei_title[3];
		SeikyushoYokoForm->MeiTitleLabel05->Caption = mei_title[4];
		SeikyushoYokoForm->MeiTitleLabel06->Caption = mei_title[5];
		SeikyushoYokoForm->MeiTitleLabel07->Caption = mei_title[6];
		SeikyushoYokoForm->Message1Label->Caption = message[0];
		SeikyushoYokoForm->Message2Label->Caption = message[1];
		SeikyushoYokoForm->Message3Label->Caption = message[2];

		// 小計用グループの [Enabled] をリセット
		SeikyushoYokoForm->GroupHeader1->Enabled = false;
		SeikyushoYokoForm->GroupHeader2->Enabled = false;
		SeikyushoYokoForm->GroupHeader3->Enabled = false;
		SeikyushoYokoForm->GroupHeader4->Enabled = false;
		SeikyushoYokoForm->GroupHeader5->Enabled = false;
		SeikyushoYokoForm->GroupFooter1->Enabled = false;
		SeikyushoYokoForm->GroupFooter2->Enabled = false;
		SeikyushoYokoForm->GroupFooter3->Enabled = false;
		SeikyushoYokoForm->GroupFooter4->Enabled = false;
		SeikyushoYokoForm->GroupFooter5->Enabled = false;

		// 小計
		int shokei_count = 0;
		for (int i = 0; i < orderby_list->Count; i++){
			// ORDER BY & 昇降
			if (desc_list->Strings[i].ToIntDef(0) == 0)
				sql_orderby_list->Add(GetKomokuName("code", orderby_list->Strings[i].ToIntDef(0)));
			else
				sql_orderby_list->Add(GetKomokuName("code", orderby_list->Strings[i].ToIntDef(0)) + " DESC");
			// 小計
			if (shokei_list->Strings[i].ToIntDef(0) == 1){
				shokei_count++;
				if (shokei_count == 1){
					SeikyushoYokoForm->GroupHeader1->Enabled = true;
					SeikyushoYokoForm->GroupHeader1->Expression = "Q_Seikyu.G1";
					expression_list->Add(GetKomokuName("code", orderby_list->Strings[i].ToIntDef(0)));
					sql_expression += GetExpressionSql(expression_list->CommaText, "G1");
					SeikyushoYokoForm->GroupHeader1->ForceNewPage = newpage_list->Strings[i].ToIntDef(0) == 1 ? true : false;
					SeikyushoYokoForm->GroupFooter1->Enabled = true;
					SeikyushoYokoForm->name1   = GetKomokuName("name",   orderby_list->Strings[i].ToIntDef(0));
					SeikyushoYokoForm->komoku1 = GetKomokuName("komoku", orderby_list->Strings[i].ToIntDef(0));

				}else if (shokei_count == 2){
					SeikyushoYokoForm->GroupHeader2->Enabled = true;
					SeikyushoYokoForm->GroupHeader2->Expression = "Q_Seikyu.G2";
					expression_list->Add(GetKomokuName("code", orderby_list->Strings[i].ToIntDef(0)));
					sql_expression += GetExpressionSql(expression_list->CommaText, "G2");
					SeikyushoYokoForm->GroupHeader2->ForceNewPage = newpage_list->Strings[i].ToIntDef(0) == 1 ? true : false;
					SeikyushoYokoForm->GroupFooter2->Enabled = true;
					SeikyushoYokoForm->name2   = GetKomokuName("name",   orderby_list->Strings[i].ToIntDef(0));
					SeikyushoYokoForm->komoku2 = GetKomokuName("komoku", orderby_list->Strings[i].ToIntDef(0));

				}else if (shokei_count == 3){
					SeikyushoYokoForm->GroupHeader3->Enabled = true;
					SeikyushoYokoForm->GroupHeader3->Expression = "Q_Seikyu.G3";
					expression_list->Add(GetKomokuName("code", orderby_list->Strings[i].ToIntDef(0)));
					sql_expression += GetExpressionSql(expression_list->CommaText, "G3");
					SeikyushoYokoForm->GroupHeader3->ForceNewPage = newpage_list->Strings[i].ToIntDef(0) == 1 ? true : false;
					SeikyushoYokoForm->GroupFooter3->Enabled = true;
					SeikyushoYokoForm->name3   = GetKomokuName("name",   orderby_list->Strings[i].ToIntDef(0));
					SeikyushoYokoForm->komoku3 = GetKomokuName("komoku", orderby_list->Strings[i].ToIntDef(0));

				}else if (shokei_count == 4){
					SeikyushoYokoForm->GroupHeader4->Enabled = true;
					SeikyushoYokoForm->GroupHeader3->Expression = "Q_Seikyu.G4";
					expression_list->Add(GetKomokuName("code", orderby_list->Strings[i].ToIntDef(0)));
					sql_expression += GetExpressionSql(expression_list->CommaText, "G4");
					SeikyushoYokoForm->GroupHeader4->ForceNewPage = newpage_list->Strings[i].ToIntDef(0) == 1 ? true : false;
					SeikyushoYokoForm->GroupFooter4->Enabled = true;
					SeikyushoYokoForm->name4   = GetKomokuName("name",   orderby_list->Strings[i].ToIntDef(0));
					SeikyushoYokoForm->komoku4 = GetKomokuName("komoku", orderby_list->Strings[i].ToIntDef(0));

				}else if (shokei_count == 5){
					SeikyushoYokoForm->GroupHeader5->Enabled = true;
					SeikyushoYokoForm->GroupHeader3->Expression = "Q_Seikyu.G5";
					expression_list->Add(GetKomokuName("code", orderby_list->Strings[i].ToIntDef(0)));
					sql_expression += GetExpressionSql(expression_list->CommaText, "G5");
					SeikyushoYokoForm->GroupHeader5->ForceNewPage = newpage_list->Strings[i].ToIntDef(0) == 1 ? true : false;
					SeikyushoYokoForm->GroupFooter5->Enabled = true;
					SeikyushoYokoForm->name5   = GetKomokuName("name",   orderby_list->Strings[i].ToIntDef(0));
					SeikyushoYokoForm->komoku5 = GetKomokuName("komoku", orderby_list->Strings[i].ToIntDef(0));
				}
			}
		}

		// 改頁はグループの下位のみにする
		if (SeikyushoYokoForm->GroupHeader5->ForceNewPage){
			SeikyushoYokoForm->GroupHeaderSeikyu->ForceNewPage = false;
			SeikyushoYokoForm->GroupHeaderSeikyu->Enabled = false;
			SeikyushoYokoForm->GroupHeader1->ForceNewPage = false;
			SeikyushoYokoForm->GroupHeader1->Enabled = false;
			SeikyushoYokoForm->GroupHeader2->ForceNewPage = false;
			SeikyushoYokoForm->GroupHeader2->Enabled = false;
			SeikyushoYokoForm->GroupHeader3->ForceNewPage = false;
			SeikyushoYokoForm->GroupHeader3->Enabled = false;
			SeikyushoYokoForm->GroupHeader4->ForceNewPage = false;
			SeikyushoYokoForm->GroupHeader4->Enabled = false;

		}else if (SeikyushoYokoForm->GroupHeader4->ForceNewPage){
			SeikyushoYokoForm->GroupHeaderSeikyu->ForceNewPage = false;
			SeikyushoYokoForm->GroupHeaderSeikyu->Enabled = false;
			SeikyushoYokoForm->GroupHeader1->ForceNewPage = false;
			SeikyushoYokoForm->GroupHeader1->Enabled = false;
			SeikyushoYokoForm->GroupHeader2->ForceNewPage = false;
			SeikyushoYokoForm->GroupHeader2->Enabled = false;
			SeikyushoYokoForm->GroupHeader3->ForceNewPage = false;
			SeikyushoYokoForm->GroupHeader3->Enabled = false;

		}else if (SeikyushoYokoForm->GroupHeader3->ForceNewPage){
			SeikyushoYokoForm->GroupHeaderSeikyu->ForceNewPage = false;
			SeikyushoYokoForm->GroupHeaderSeikyu->Enabled = false;
			SeikyushoYokoForm->GroupHeader1->ForceNewPage = false;
			SeikyushoYokoForm->GroupHeader1->Enabled = false;
			SeikyushoYokoForm->GroupHeader2->ForceNewPage = false;
			SeikyushoYokoForm->GroupHeader2->Enabled = false;

		}else if (SeikyushoYokoForm->GroupHeader2->ForceNewPage){
			SeikyushoYokoForm->GroupHeaderSeikyu->ForceNewPage = false;
			SeikyushoYokoForm->GroupHeaderSeikyu->Enabled = false;
			SeikyushoYokoForm->GroupHeader1->ForceNewPage = false;
			SeikyushoYokoForm->GroupHeader1->Enabled = false;

		}else if (SeikyushoYokoForm->GroupHeader1->ForceNewPage){
			SeikyushoYokoForm->GroupHeaderSeikyu->ForceNewPage = false;
			SeikyushoYokoForm->GroupHeaderSeikyu->Enabled = false;
		}
/*		if (SeikyushoYokoForm->GroupHeaderSeikyu->ForceNewPage)
			ShowMessage("seikyu: " + SeikyushoYokoForm->GroupHeaderSeikyu->Expression);
		if (SeikyushoYokoForm->GroupHeader1->ForceNewPage)
			ShowMessage("g1: " + SeikyushoYokoForm->GroupHeader1->Expression);
		if (SeikyushoYokoForm->GroupHeader2->ForceNewPage)
			ShowMessage("g2: " + SeikyushoYokoForm->GroupHeader2->Expression);
		if (SeikyushoYokoForm->GroupHeader3->ForceNewPage)
			ShowMessage("g3: " + SeikyushoYokoForm->GroupHeader3->Expression);
		if (SeikyushoYokoForm->GroupHeader4->ForceNewPage)
			ShowMessage("g4: " + SeikyushoYokoForm->GroupHeader4->Expression);
		if (SeikyushoYokoForm->GroupHeader5->ForceNewPage)
			ShowMessage("g5: " + SeikyushoYokoForm->GroupHeader5->Expression);
*/
		// 総合計出力
		SeikyushoYokoForm->div_total = output_total.ToIntDef(2) == 1 ? true : false;
		// 備考表示項目
		SeikyushoYokoForm->QRDBTextBiko->DataField = GetKomokuName("name", biko_komoku.ToIntDef(14));
		// 背景色
		SeikyushoYokoForm->ColorShape->Brush->Color  = bgcolor;
		SeikyushoYokoForm->ColorShape1->Brush->Color = bgcolor;
		SeikyushoYokoForm->ColorShape2->Brush->Color = bgcolor;
		SeikyushoYokoForm->ColorShape3->Brush->Color = bgcolor;
		// 文字色
		SeikyushoYokoForm->TitleLabel->Font->Color    = txcolor;
		SeikyushoYokoForm->KagamiLabel01->Font->Color = txcolor;
		SeikyushoYokoForm->KagamiLabel02->Font->Color = txcolor;
		SeikyushoYokoForm->KagamiLabel03->Font->Color = txcolor;
		SeikyushoYokoForm->KagamiLabel04->Font->Color = txcolor;
		SeikyushoYokoForm->KagamiLabel05->Font->Color = txcolor;
		SeikyushoYokoForm->KagamiLabel06->Font->Color = txcolor;
		SeikyushoYokoForm->KagamiLabel07->Font->Color = txcolor;
		SeikyushoYokoForm->MeiTitleLabel01->Font->Color = txcolor;
		SeikyushoYokoForm->MeiTitleLabel02->Font->Color = txcolor;
		SeikyushoYokoForm->MeiTitleLabel03->Font->Color = txcolor;
		SeikyushoYokoForm->MeiTitleLabel04->Font->Color = txcolor;
		SeikyushoYokoForm->MeiTitleLabel05->Font->Color = txcolor;
		SeikyushoYokoForm->MeiTitleLabel06->Font->Color = txcolor;
		SeikyushoYokoForm->MeiTitleLabel07->Font->Color = txcolor;
	}

	// 改頁用のフィールドを作成する
	if (sql_expression.Pos("G1") == 0)
		sql_expression += "'' AS G1, ";
	if (sql_expression.Pos("G2") == 0)
		sql_expression += "'' AS G2, ";
	if (sql_expression.Pos("G3") == 0)
		sql_expression += "'' AS G3, ";
	if (sql_expression.Pos("G4") == 0)
		sql_expression += "'' AS G4, ";
	if (sql_expression.Pos("G5") == 0)
		sql_expression += "'' AS G5, ";
	DM->Q_Seikyu->SQL->Strings[62] = "\t" + sql_expression;

	// ORDER BY (最終行－１行目にあるという前提）
	AnsiString buff = sql_orderby_list->CommaText;
	buff = AnsiReplaceStr(buff, "\"", "");		// 自動付加されたダブルクォーテーションを削除
	DM->Q_Seikyu->SQL->Strings[DM->Q_Seikyu->SQL->Count - 2] = buff;

	// 入金明細表示区分
	if (output_nyukin.ToIntDef(1) == 1){	// 出力する
		DM->Q_Seikyu->SQL->Strings[234] = "		入金日 BETWEEN @DATE_FROM AND @DATE_TO";
	}else{					// 出力しない
		DM->Q_Seikyu->SQL->Strings[234] = "		入金日 BETWEEN 99999999 AND 99999999";
	}
}
//---------------------------------------------------------------------------
// グループの「Expression」に設定するクエリを作成
AnsiString __fastcall TSettingsForm::GetExpressionSql(AnsiString list, AnsiString komoku_name)
{
	std::auto_ptr<TStringList> str_list(new TStringList());
	str_list->CommaText = list;

	AnsiString sql = AnsiString();
	for (int i = 0; i < str_list->Count; i++){
		if (sql != AnsiString())
			sql += " + ";
		sql += "RIGHT('00000' + CAST(" + str_list->Strings[i] + " AS VARCHAR), 5)";
	}
	sql += " AS " + komoku_name + ", ";
	return sql;
}
//---------------------------------------------------------------------------
// 設定保存ボタン
void __fastcall TSettingsForm::SaveButtonClick(TObject *Sender)
{
	GetValueFromForm();
	if (!SetValueToDB())
		return;
	DM->config_.Load(&DM->DBI);
	SetSeikyusho();
	
	Application->MessageBox("保存しました", "設定保存", MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
// 背景色変更ボタン
void __fastcall TSettingsForm::BgColorButtonClick(TObject *Sender)
{
	ColorDialog->Color = ColorPanel1->Color;
	ColorDialog->Execute();
	ColorPanel->Color  = ColorDialog->Color;
	ColorPanel1->Color = ColorDialog->Color;
	ColorPanel2->Color = ColorDialog->Color;
	ColorPanel3->Color = ColorDialog->Color;
	KagamiName1Edit->Color = ColorDialog->Color;
	KagamiName2Edit->Color = ColorDialog->Color;
	KagamiName3Edit->Color = ColorDialog->Color;
	KagamiName4Edit->Color = ColorDialog->Color;
	KagamiName5Edit->Color = ColorDialog->Color;
	KagamiName6Edit->Color = ColorDialog->Color;
	KagamiName7Edit->Color = ColorDialog->Color;
	DateTitleEdit->Color   = ColorDialog->Color;
	HinTitleEdit->Color    = ColorDialog->Color;
	SuryoTitleEdit->Color  = ColorDialog->Color;
	TaniTitleEdit->Color   = ColorDialog->Color;
	TankaTitleEdit->Color  = ColorDialog->Color;
	KingakuTitleEdit->Color = ColorDialog->Color;
	BikoTitleEdit->Color   = ColorDialog->Color;
}
//---------------------------------------------------------------------------
// 文字色変更
void __fastcall TSettingsForm::TxColorButtonClick(TObject *Sender)
{
	ColorDialog->Color = KagamiName1Edit->Font->Color;
	ColorDialog->Execute();
	TitleLabel->Font->Color = ColorDialog->Color;
	KagamiName1Edit->Font->Color = ColorDialog->Color;
	KagamiName2Edit->Font->Color = ColorDialog->Color;
	KagamiName3Edit->Font->Color = ColorDialog->Color;
	KagamiName4Edit->Font->Color = ColorDialog->Color;
	KagamiName5Edit->Font->Color = ColorDialog->Color;
	KagamiName6Edit->Font->Color = ColorDialog->Color;
	KagamiName7Edit->Font->Color = ColorDialog->Color;
	DateTitleEdit->Font->Color   = ColorDialog->Color;
	HinTitleEdit->Font->Color    = ColorDialog->Color;
	SuryoTitleEdit->Font->Color  = ColorDialog->Color;
	TaniTitleEdit->Font->Color   = ColorDialog->Color;
	TankaTitleEdit->Font->Color  = ColorDialog->Color;
	KingakuTitleEdit->Font->Color = ColorDialog->Color;
	BikoTitleEdit->Font->Color   = ColorDialog->Color;
}
//---------------------------------------------------------------------------
// 項目ダブルクリック（小計／改頁／昇降編集）
void __fastcall TSettingsForm::KomokuListGridDblClick(TObject *Sender)
{
	if (KomokuListGrid->Col < 2)
		return;
	if (KomokuListGrid->Cells[KomokuListGrid->Col][KomokuListGrid->Row] == AnsiString())
		KomokuListGrid->Cells[KomokuListGrid->Col][KomokuListGrid->Row] = "●";
	else
		KomokuListGrid->Cells[KomokuListGrid->Col][KomokuListGrid->Row] = AnsiString();
}
//---------------------------------------------------------------------------
// 表示順上下ボタン
void __fastcall TSettingsForm::UpButtonClick(TObject *Sender)
{
	int row, nrow;
	row = KomokuListGrid->Row;
	if ((TButton *)Sender == UpButton)
		nrow = row - 1;
	else
		nrow = row + 1;

	if (nrow < 1 || nrow >= KomokuListGrid->RowCount)
		return;

	// 現在の行の内容を保持
	AnsiString buff1, buff2, buff3, buff4, buff5;
	buff1 = KomokuListGrid->Cells[1][row];
	buff2 = KomokuListGrid->Cells[2][row];
	buff3 = KomokuListGrid->Cells[3][row];
	buff4 = KomokuListGrid->Cells[4][row];
	buff5 = KomokuListGrid->Cells[5][row];
	// 移動先の内容を現在行にコピー
	KomokuListGrid->Cells[1][row] = KomokuListGrid->Cells[1][nrow];
	KomokuListGrid->Cells[2][row] = KomokuListGrid->Cells[2][nrow];
	KomokuListGrid->Cells[3][row] = KomokuListGrid->Cells[3][nrow];
	KomokuListGrid->Cells[4][row] = KomokuListGrid->Cells[4][nrow];
	KomokuListGrid->Cells[5][row] = KomokuListGrid->Cells[5][nrow];
	// 移動先の行に保持した内容を貼りつけ
	KomokuListGrid->Cells[1][nrow] = buff1;
	KomokuListGrid->Cells[2][nrow] = buff2;
	KomokuListGrid->Cells[3][nrow] = buff3;
	KomokuListGrid->Cells[4][nrow] = buff4;
	KomokuListGrid->Cells[5][nrow] = buff5;

	KomokuListGrid->Row = nrow;
}
//---------------------------------------------------------------------------
// パスワード->OnKeyDown
void __fastcall TSettingsForm::PasswordEditKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN)
		KomokuDispPanel->OnClick(NULL);
}
//---------------------------------------------------------------------------
// 項目設定用パスワード表示ボタン
void __fastcall TSettingsForm::KomokuDispPanelClick(TObject *Sender)
{
	if (PasswordEdit->Text == "nsoft"){
		GroupBoxKomoku->Visible = true;
	}else{
		PasswordEdit->Text = AnsiString();
		PasswordEdit->SetFocus();
	}
}
//---------------------------------------------------------------------------

