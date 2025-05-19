//---------------------------------------------------------------------------

#ifndef CardIssueFrmH
#define CardIssueFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
#include "HF04Issuer.h"
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "CEdit.h"
//---------------------------------------------------------------------------
// かな検索テーブル
typedef std::map<int, AnsiString> KanaOnTable;
typedef std::map<int, KanaOnTable> KanaTable;
//---------------------------------------------------------------------------
namespace ackl{
	class State;
};
//---------------------------------------------------------------------------
class TCardIssueForm : public TForm
{
__published:	// IDE 管理のコンポーネント
	TPanel *TitlePanel;
	TPanel *BottomPanel;
	TButton *CloseButton;
	TPanel *ClientPanel;
	TButton *BackButton;
	TPageControl *PageControl;
	TTabSheet *CarNoSheet;
	TPanel *Panel1;
	TTabSheet *Item1Sheet;
	TPanel *Item1TitlePanel;
	TTabSheet *ConfirmSheet;
	TPanel *Panel4;
	TPanel *CardNoConfirmPanel;
	TBevel *Bevel2;
    TPanel *TokuConfirmTitlePanel;
	TBevel *Bevel3;
	TPanel *CarNoPanel;
    TPanel *TokuPanel;
	TTabSheet *IssueSheet;
	TPanel *Panel10;
	TButton *Item11Button;
	TButton *Item12Button;
	TButton *Item13Button;
	TButton *Item14Button;
	TButton *Item15Button;
	TButton *Item16Button;
	TButton *Item17Button;
	TButton *Item18Button;
	TButton *Item19Button;
	TButton *Item110Button;
	TButton *Item111Button;
	TButton *Item112Button;
	TButton *Item113Button;
	TButton *Item114Button;
	TButton *Item115Button;
	TButton *Item1ScrollUpButton;
	TButton *Item1ScrollDownButton;
	TButton *WriteButton;
	TButton *AdminCardIssueButton;
	TTabSheet *AdminIssueSheet;
	TButton *AdminIssueButton;
	TPanel *Panel3;
	TMemo *CardIssueStatus;
	TMemo *AdminCardIssueStatus;
	TTimer *ActivateTimer;
	TButton *ContentsConfirmButton;
	TButton *AnonyCarNoButton;
	TButton *AnonyItem1Button;
	TButton *Item1Kana1Button;
	TButton *Item1Kana2Button;
	TButton *Item1Kana3Button;
	TButton *Item1Kana4Button;
	TButton *Item1Kana5Button;
	TButton *Item1Kana6Button;
	TButton *Item1Kana7Button;
	TButton *Item1Kana8Button;
	TButton *Item1Kana9Button;
	TButton *Item1Kana10Button;
	TButton *Item1KanaBackButton;
    TPanel *MeigConfirmTitlePanel;
	TBevel *Bevel4;
    TPanel *MeigPanel;
	TCobEdit *CarNoInputEdit;
    TButton *CarNoSelectButton;
	TPanel *CarNoInputPanel;
	TButton *Input7Button;
	TButton *Input8Button;
	TButton *Input9Button;
	TButton *Input4Button;
	TButton *Input5Button;
	TButton *Input6Button;
	TButton *Input1Button;
	TButton *Input2Button;
	TButton *Input3Button;
	TButton *Input0Button;
	TButton *InputBackButton;
	TButton *InputClearButton;
	TTabSheet *Item2Sheet;
	TButton *Item21Button;
	TButton *Item22Button;
	TButton *Item23Button;
	TButton *Item24Button;
	TButton *Item25Button;
	TButton *Item26Button;
	TButton *Item27Button;
	TButton *Item28Button;
	TButton *Item29Button;
	TButton *Item210Button;
	TButton *Item211Button;
	TButton *Item212Button;
	TButton *Item213Button;
	TButton *Item214Button;
	TButton *Item215Button;
	TButton *Item2ScrollUpButton;
	TButton *Item2ScrollDownButton;
	TPanel *Item2TitlePanel;
	TButton *Item2Kana1Button;
	TButton *Item2Kana2Button;
	TButton *Item2Kana3Button;
	TButton *Item2Kana4Button;
	TButton *Item2Kana5Button;
	TButton *Item2Kana6Button;
	TButton *Item2Kana7Button;
	TButton *Item2Kana8Button;
	TButton *Item2Kana9Button;
	TButton *Item2Kana10Button;
	TButton *Item2KanaBackButton;
	TButton *AnonyItem2Button;
	TButton *ZeroSetIssueButton;
	TButton *ZeroCancelIssueButton;
    TTabSheet *TokuSheet;
    TButton *Toku1Button;
    TButton *Toku2Button;
    TButton *Toku3Button;
    TButton *Toku4Button;
    TButton *Toku5Button;
    TButton *Toku6Button;
    TButton *Toku7Button;
    TButton *Toku8Button;
    TButton *Toku9Button;
    TButton *Toku10Button;
    TButton *Toku11Button;
    TButton *Toku12Button;
    TButton *Toku13Button;
    TButton *Toku14Button;
    TButton *Toku15Button;
    TButton *TokuScrollUpButton;
    TButton *TokuScrollDownButton;
    TPanel *TokuTitlePanel;
    TButton *TokuKana1Button;
    TButton *TokuKana2Button;
    TButton *TokuKana3Button;
    TButton *TokuKana4Button;
    TButton *TokuKana5Button;
    TButton *TokuKana6Button;
    TButton *TokuKana7Button;
    TButton *TokuKana8Button;
    TButton *TokuKana9Button;
    TButton *TokuKana10Button;
    TButton *TokuKanaBackButton;
    TButton *AnonyTokuButton;
    TPanel *Item1ConfirmTitlePanel;
	TBevel *Bevel1;
    TPanel *Item1Panel;
    TTabSheet *MeigSheet;
    TButton *Meig1Button;
    TButton *Meig2Button;
    TButton *Meig3Button;
    TButton *Meig4Button;
    TButton *Meig5Button;
    TButton *Meig6Button;
    TButton *Meig7Button;
    TButton *Meig8Button;
    TButton *Meig9Button;
    TButton *Meig10Button;
    TButton *Meig11Button;
    TButton *Meig12Button;
    TButton *Meig13Button;
    TButton *Meig14Button;
    TButton *Meig15Button;
    TButton *MeigScrollUpButton;
    TButton *MeigScrollDownButton;
    TPanel *MeigTitlePanel;
    TButton *MeigKana1Button;
    TButton *MeigKana2Button;
    TButton *MeigKana3Button;
    TButton *MeigKana4Button;
    TButton *MeigKana5Button;
    TButton *MeigKana6Button;
    TButton *MeigKana7Button;
    TButton *MeigKana8Button;
    TButton *MeigKana9Button;
    TButton *MeigKana10Button;
    TButton *MeigKanaBackButton;
    TButton *AnonyMeigButton;
    TPanel *Item2ConfirmTitlePanel;
    TBevel *Bevel5;
    TPanel *Item2Panel;
    TADOQuery *Q_Syaryo;
    TDataSource *ds;
    TDBGrid *DBGrid1;
    TButton *CarNoAddButton;
    TIntegerField *Q_SyaryoDSDesigner;
    TStringField *Q_SyaryoDSDesigner2;
    TBCDField *Q_SyaryoDSDesigner3;
    TBCDField *Q_SyaryoDSDesigner4;
    TBCDField *Q_SyaryoDSDesigner5;
    TIntegerField *Q_SyaryoID;
	void __fastcall CloseButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall BackButtonClick(TObject *Sender);
	void __fastcall WriteButtonClick(TObject *Sender);
	void __fastcall Item1ScrollUpButtonClick(TObject *Sender);
	void __fastcall Item1ScrollDownButtonClick(TObject *Sender);
	void __fastcall Item11ButtonClick(TObject *Sender);
	void __fastcall AdminCardIssueButtonClick(TObject *Sender);
	void __fastcall ActivateTimerTimer(TObject *Sender);
	void __fastcall ContentsConfirmButtonClick(TObject *Sender);
	void __fastcall AnonyCarNoButtonClick(TObject *Sender);
	void __fastcall AnonyItem1ButtonClick(TObject *Sender);
	void __fastcall Item1Kana1ButtonClick(TObject *Sender);
	void __fastcall CarNoSelectButtonClick(TObject *Sender);
	void __fastcall Item21ButtonClick(TObject *Sender);
	void __fastcall Item2ScrollUpButtonClick(TObject *Sender);
	void __fastcall Item2ScrollDownButtonClick(TObject *Sender);
	void __fastcall Input7ButtonClick(TObject *Sender);
	void __fastcall Item2Kana1ButtonClick(TObject *Sender);
	void __fastcall AnonyItem2ButtonClick(TObject *Sender);
	void __fastcall TokuScrollUpButtonClick(TObject *Sender);
	void __fastcall TokuScrollDownButtonClick(TObject *Sender);
	void __fastcall Toku1ButtonClick(TObject *Sender);
	void __fastcall AnonyTokuButtonClick(TObject *Sender);
	void __fastcall TokuKana1ButtonClick(TObject *Sender);
    void __fastcall MeigScrollUpButtonClick(TObject *Sender);
    void __fastcall MeigScrollDownButtonClick(TObject *Sender);
    void __fastcall Meig1ButtonClick(TObject *Sender);
    void __fastcall AnonyMeigButtonClick(TObject *Sender);
    void __fastcall MeigKana1ButtonClick(TObject *Sender);
    void __fastcall CarNoInputEditChange(TObject *Sender);
    void __fastcall CarNoAddButtonClick(TObject *Sender);
private:	// ユーザー宣言
	void __fastcall IssueCard(int card_no);
	
	ackl::State *current_state_;
    int rfid_port_;

//-- kana table -------------------------------------------------------------
	KanaTable kana_table_;
	void __fastcall InitKanaTable();
	int __fastcall SearchLineIndex(const AnsiString& kana);
public:		// ユーザー宣言
	__fastcall TCardIssueForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCardIssueForm *CardIssueForm;
//---------------------------------------------------------------------------
#endif
