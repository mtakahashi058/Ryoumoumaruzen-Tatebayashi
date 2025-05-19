//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SettingsFrm.h"
#include <IniFiles.hpp>
#include <memory>
#include "nsoftfunc.h"
#include "NsIni.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CEdit"
#pragma link "CSPIN"
#pragma resource "*.dfm"
TSettingsForm *SettingsForm;
NsIni INI;
//---------------------------------------------------------------------------
__fastcall TSettingsForm::TSettingsForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSettingsForm::FormShow(TObject *Sender)
{
    PageControl->ActivePage = KeiryoSheet;

	DM->Init();

	// プリンタの列挙
	SlipPrinterCombo->Text = AnsiString();
	SlipPrinterCombo->Items->Clear();
	ReportPrinterCombo->Text = AnsiString();
	ReportPrinterCombo->Items->Clear();
	for (int i = 0; i < Printer()->Printers->Count; i++){
		SlipPrinterCombo->Items->Append(Printer()->Printers->Strings[i]);
		ReportPrinterCombo->Items->Append(Printer()->Printers->Strings[i]);
	}

	///// 拠点設定
	PlaceCombo->Items->Clear();
	if (!DM->DBI.GetRecordSet("SELECT 拠点ID, 拠点コード, 拠点名称 FROM M_拠点", kyoten_set_)){
		Application->MessageBox("拠点マスタが設定されていません。計量前に設定してください",
								Caption.c_str(), MB_OK | MB_ICONWARNING);
		PostMessage(Handle, WM_CLOSE, 0, 0);
		return;
	}
	int default_index = 0;
	int place_code    = ToInt(DM->INI["Place::Code"]);
	for (unsigned int i = 0; i < kyoten_set_.size(); i++){
		PlaceCombo->Items->Append(ToString(kyoten_set_[i]["拠点名称"]));
		if (ToInt(kyoten_set_[i]["拠点コード"]) == place_code)
			default_index = i;
	}
	PlaceCombo->ItemIndex = default_index;

	///// 通信設定
	AnsiString wi_type = ToString(DM->INI["Weight::Type"]);
	if (wi_type == "S9500")
		WICombo->ItemIndex = 0;
	else if (wi_type == "C9500")
		WICombo->ItemIndex = 1;
	else if (wi_type == "S4401")
		WICombo->ItemIndex = 2;
	else if (wi_type == "C4401")
		WICombo->ItemIndex = 3;
	else if (wi_type == "F720")
		WICombo->ItemIndex = 4;
	else if (wi_type == "F701")
		WICombo->ItemIndex = 5;
	else if (wi_type == "RoadMeter")
		WICombo->ItemIndex = 6;
	else if (wi_type == "MU790")
		WICombo->ItemIndex = 7;
	else if (wi_type == "Y700A")
		WICombo->ItemIndex = 8;
	else if (wi_type == "EDP1700")
		WICombo->ItemIndex = 9;
	else if (wi_type == "ADHV")
		WICombo->ItemIndex = 10;
	else if (wi_type == "SKLD2000")
		WICombo->ItemIndex = 11;
	else if (wi_type == "CKLD2000")
		WICombo->ItemIndex = 12;
    else if (wi_type == "SDI750")
        WICombo->ItemIndex = 13;
    else if (wi_type == "SDIPC275")
        WICombo->ItemIndex = 14;
    else if (wi_type == "CCSD904")
        WICombo->ItemIndex = 15;
    else if (wi_type == "SCL9500")
        WICombo->ItemIndex = 16;

	ComPortEdit->Value       = ToInt(DM->INI["Weight::Port"]);
	ComDefEdit->Text         = ToString(DM->INI["Weight::Def"]);
	WIServerPortEdit->Text   = ToInt(DM->INI["Weight::TCPPort"]);

	///// WIClient 設定
	WIServerEdit->Text       = ToString(DM->INI["Weighing::WIServer"]);
	WIConnectPortEdit->Text  = ToInt(DM->INI["Weighing::WIPort"]);
	AlermWeightEdit->Text    = ToInt(DM->INI["Weighing::SoundBorder"]);
	SoundFileEdit->Text      = ToString(DM->INI["Weighing::SoundFile"]);

	///// 印刷設定
	SlipPrinterCombo->Text   = ToString(DM->INI["Printer::Slip"]);
	SlipLeftMarginEdit->Text = ToString(DM->INI["Printer::SlipLeft"]);
	SlipTopMarginEdit->Text  = ToString(DM->INI["Printer::SlipTop"]);
    int bin                  = ToInt(DM->INI["Printer::SlipOutputBin"]);
    if (bin < 0 || bin > 13)
        bin = 0;
    SlipBinCombo->ItemIndex  = bin;
	ReportPrinterCombo->Text = ToString(DM->INI["Printer::Report"]);

    ///// AD4385 設定
    AD85PortEdit->Value      = ToInt(DM->INI["AD4385::Port"]);
    AD85DefEdit->Text        = ToString(DM->INI["AD4385::Def"]);
    AD85BorderEdit->Text     = ToInt(DM->INI["AD4385::Border"]);
    NotifySoundEdit->Text    = ToString(DM->INI["AD4385::NotifySound"]);

    ///// バッチ取り込み設定
    BatchPortEdit->Value     = ToInt(DM->INI["Batch::Port"]);
    BatchDefEdit->Text       = ToString(DM->INI["Batch::Def"]);

    ///// RFID 設定
    DeskRFIDPortEdit->Value  = ToInt(DM->INI["RFID::DeskCommPort"]);
    BoxRFIDPortEdit->Value   = ToInt(DM->INI["RFID::WeighingCommPort"]);
}
//---------------------------------------------------------------------------
void __fastcall TSettingsForm::FormClose(TObject *Sender,
	  TCloseAction &Action)
{
	//
}
//---------------------------------------------------------------------------
void __fastcall TSettingsForm::CancelButtonClick(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
void __fastcall TSettingsForm::SaveButtonClick(TObject *Sender)
{
	// INI ファイルのバックアップ
	AnsiString src = ExtractFilePath(Application->ExeName) + "settings.ini";
	AnsiString dst = src + "." +  Now().FormatString("yyyymmddhhnnss");
	CopyFile(src.c_str(), dst.c_str(), true);

	///// 拠点設定
	int place_code = 0;
	if (PlaceCombo->ItemIndex >= 0){
		place_code = ToInt(kyoten_set_[PlaceCombo->ItemIndex]["拠点コード"]);
	}
	DM->INI["Place::Code"] = place_code;

	///// 通信設定
	AnsiString wi_type;
	if (WICombo->ItemIndex == 0)
		wi_type = "S9500";
	else if (WICombo->ItemIndex == 1)
		wi_type = "C9500";
	else if (WICombo->ItemIndex == 2)
		wi_type = "S4401";
	else if (WICombo->ItemIndex == 3)
		wi_type = "C4401";
	else if (WICombo->ItemIndex == 4)
		wi_type = "F720";
	else if (WICombo->ItemIndex == 5)
		wi_type = "F701";
	else if (WICombo->ItemIndex == 6)
		wi_type = "RoadMeter";
	else if (WICombo->ItemIndex == 7)
		wi_type = "MU790";
	else if (WICombo->ItemIndex == 8)
		wi_type = "Y700A";
	else if (WICombo->ItemIndex == 9)
		wi_type = "EDP1700";
	else if (WICombo->ItemIndex == 10)
		wi_type = "ADHV";
	else if (WICombo->ItemIndex == 11)
		wi_type = "SKLD2000";
	else if (WICombo->ItemIndex == 12)
		wi_type = "CKLD2000";
	else if (WICombo->ItemIndex == 13)
		wi_type = "SDI750";
	else if (WICombo->ItemIndex == 14)
		wi_type = "SDIPC275";
    else if (WICombo->ItemIndex == 15)
        wi_type = "CCSD904";
    else if (WICombo->ItemIndex == 16)
        wi_type = "SCL9500";

	DM->INI["Weight::Type"] = wi_type;

	DM->INI["Weight::Port"]    = ComPortEdit->Value;
	DM->INI["Weight::Def"]     = ComDefEdit->Text;
	DM->INI["Weight::TCPPort"] = WIServerPortEdit->Text;

	///// WIClient 設定
	DM->INI["Weighing::WIServer"]    = WIServerEdit->Text;
	DM->INI["Weighing::WIPort"]      = WIConnectPortEdit->Text;
	DM->INI["Weighing::SoundBorder"] = AlermWeightEdit->Text;
	DM->INI["Weighing::SoundFile"]   = SoundFileEdit->Text;

	///// 印刷設定
	DM->INI["Printer::Slip"]          = SlipPrinterCombo->Text;
	DM->INI["Printer::SlipLeft"]      = SlipLeftMarginEdit->Text;
	DM->INI["Printer::SlipTop"]       = SlipTopMarginEdit->Text;
    DM->INI["Printer::SlipOutputBin"] = SlipBinCombo->ItemIndex;
	DM->INI["Printer::Report"]        = ReportPrinterCombo->Text;

    ///// AD4385 設定
    DM->INI["AD4385::Port"]        = AD85PortEdit->Value;
    DM->INI["AD4385::Def"]         = AD85DefEdit->Text;
    DM->INI["AD4385::Border"]      = AD85BorderEdit->Text;
    DM->INI["AD4385::NotifySound"] = NotifySoundEdit->Text;

    ///// バッチ取り込み設定
    DM->INI["Batch::Port"]         = BatchPortEdit->Value;
    DM->INI["Batch::Def"]          = BatchDefEdit->Text;

    ///// RFID 設定
    DM->INI["RFID::DeskCommPort"]     = DeskRFIDPortEdit->Value;
    DM->INI["RFID::WeighingCommPort"] = BoxRFIDPortEdit->Value;

    DM->INI.Save();

	Application->MessageBox("設定を保存しました", Caption.c_str(), MB_OK | MB_ICONINFORMATION);
}
//---------------------------------------------------------------------------
void __fastcall TSettingsForm::SoundRefButtonClick(TObject *Sender)
{
	OpenDialog->FileName = SoundFileEdit->Text;
	if (!OpenDialog->Execute())
		return;
	SoundFileEdit->Text = OpenDialog->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TSettingsForm::NotifySoundRefButtonClick(TObject *Sender)
{
	OpenDialog->FileName = NotifySoundEdit->Text;
	if (!OpenDialog->Execute())
		return;
	NotifySoundEdit->Text = OpenDialog->FileName;
}
//---------------------------------------------------------------------------

