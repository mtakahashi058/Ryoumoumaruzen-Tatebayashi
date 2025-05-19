//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "trayicon.h"
#include <ImgList.hpp>
#include <Menus.hpp>
#include <ScktComp.hpp>
#include <ExtCtrls.hpp>
#include <map>
#include "NsDB.h"
#include "HF04Thread.h"
#include "NP3411Thread.h"
#include "F0399.h"
#include "ioMirrorThread.h"
//---------------------------------------------------------------------------
class TEtherPostForm : public TForm
{
__published:	// IDE 管理のコンポーネント
    TImageList *il16;
    TTrayIcon *TrayIcon;
    TPopupMenu *PopupMenu;
    TMenuItem *AD43851;
    TMenuItem *N1;
    TMenuItem *ExitItem;
    TClientSocket *ClientSocket;
    TTimer *SocketReopenTimer;
    TTimer *ThreadCreateTimer;
	TTimer *BuzzerSwitchTimer;
    void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall ExitItemClick(TObject *Sender);
    void __fastcall SocketReopenTimerTimer(TObject *Sender);
    void __fastcall ClientSocketError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
    void __fastcall ClientSocketRead(TObject *Sender,
          TCustomWinSocket *Socket);
    void __fastcall ThreadCreateTimerTimer(TObject *Sender);
	void __fastcall BuzzerSwitchTimerTimer(TObject *Sender);
private:	// ユーザー宣言
    int place_id_;
    AnsiString notify_sound_;

	void __fastcall OnEndSession(TMessage& message);

	////////////////////////////// 計量関連
    Currency cur_weight_;
    Currency old_weight_;
    int weighing_border_;
    enum WIStatus {wsStable, wsUnstable, wsOther} cur_wi_status_;

	bool on_weighing_;          			// 計量中か否か
	bool reversed_;  			            // 逆挿入されたか
	bool on_error_;  			            // 計量エラー発生中か否か
	bool on_printing_;			            // 印刷中かどうか
	bool limit_over_;			            // 過積載かどうか
	bool on_wait_exit_;		                // 退車待ちかどうか
    bool wi_error_;

	void __fastcall OnEnterWeighing();
	void __fastcall OnExitWeighing();
	void __fastcall PostWeighing();
	void __fastcall OnConfirmButton();
	void __fastcall OnResetButton();

	////////////////////////////// NP3411関連
	TNP3411Thread *printer_thread_;
    CfgInfo cfginfo_;
    NsRecordSet keiryo_set_;
    NsRecordSet print_set_;

	void __fastcall UMNiiAborted(TMessage& message);
	void __fastcall UMNiiStatus(TMessage& message);
	void __fastcall UMNiiReboot(TMessage& message);

	////////////////////////////// 7セグ関連
	F0399 indicator_;

	////////////////////////////// ioMirror 関連
	TioMirrorThread *io_thread_;

	void __fastcall OnIOAborted(TMessage& message);
	void __fastcall OnIOStatus(TMessage& message);
	void __fastcall OnIOInput(TMessage& message);

	bool ready_sw_;
	bool card_sw_;
	bool exit_sw_;
	bool overload_sw_;
	bool buzzer_sw_;
	void __fastcall OutputCh();

	////////////////////////////// RFID 通信関連
	THF04Thread *rfid_thread_;
	bool rfid_error_;
	int last_card_no_;

	void __fastcall OnRFIDAborted(TMessage& message);
	void __fastcall OnRFIDStatus(TMessage& message);
	void __fastcall OnRFIDCard(TMessage& message);
	void __fastcall OnRFIDTimeout(TMessage& message);

	////////////////////////////// MessageMap
BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(WM_ENDSESSION,  TMessage, OnEndSession);

	MESSAGE_HANDLER(UM_NII_ABORTED, TMessage, UMNiiAborted);
	MESSAGE_HANDLER(UM_NII_STATUS,  TMessage, UMNiiStatus);
	MESSAGE_HANDLER(UM_NII_REBOOT,  TMessage, UMNiiReboot);

	MESSAGE_HANDLER(RFIDM_ABORTED,  TMessage, OnRFIDAborted);
	MESSAGE_HANDLER(RFIDM_STATUS,   TMessage, OnRFIDStatus);
	MESSAGE_HANDLER(RFIDM_CARD,     TMessage, OnRFIDCard);
	MESSAGE_HANDLER(RFIDM_TIMEOUT,  TMessage, OnRFIDTimeout);

	MESSAGE_HANDLER(DIOM_ABORTED,  TMessage, OnIOAborted);
	MESSAGE_HANDLER(DIOM_STATUS,   TMessage, OnIOStatus);
	MESSAGE_HANDLER(DIOM_INPUT,    TMessage, OnIOInput);
END_MESSAGE_MAP(TForm)

public:		// ユーザー宣言
	__fastcall TEtherPostForm(TComponent* Owner);

	void __fastcall PrintKeiryoData(int keiryo_id);
	void __fastcall PrintCopy(int keiryo_id);
	void __fastcall ForceWeighing();

    void __fastcall UpdateWeighingState();
};
//---------------------------------------------------------------------------
extern PACKAGE TEtherPostForm *EtherPostForm;
//---------------------------------------------------------------------------
#endif
