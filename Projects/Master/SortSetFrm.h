//---------------------------------------------------------------------------

#ifndef SortSetFrmH
#define SortSetFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
#include <map>
typedef std::map<int, AnsiString> ItemMap;
//---------------------------------------------------------------------------
class TSortSetForm : public TForm
{
__published:	// IDE 管理のコンポーネント
    TButton *SetButton;
    TButton *CloseButton;
    TStatusBar *StatusBar;
    TGroupBox *ItemSetGroupBox;
    TPanel *SeikyushoPrintPanel;
    TPanel *Panel1;
    TLabel *Label1;
    TComboBox *SortComboBox1;
    TComboBox *ItemComboBox1;
    TPanel *Panel2;
    TLabel *Label2;
    TComboBox *SortComboBox2;
    TComboBox *ItemComboBox2;
    TLabel *Label3;
    TComboBox *SortComboBox3;
    TComboBox *ItemComboBox3;
    TPanel *F5Panel;
    TPanel *F12Panel;
    TActionList *ActionList;
    TAction *Action5;
    TAction *Action12;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall Action5Execute(TObject *Sender);
    void __fastcall Action12Execute(TObject *Sender);
	void __fastcall SeikyushoPrintPanelEnter(TObject *Sender);
	void __fastcall SeikyushoPrintPanelExit(TObject *Sender);
private:	// ユーザー宣言
public:		// ユーザー宣言
    __fastcall TSortSetForm(TComponent* Owner);

    TDBGrid *grid_;
    ItemMap fields_map_;
    AnsiString item1, item2, item3, orderby_sql;
    bool desc1, desc2, desc3;
};
//---------------------------------------------------------------------------
extern PACKAGE TSortSetForm *SortSetForm;
//---------------------------------------------------------------------------
#endif
