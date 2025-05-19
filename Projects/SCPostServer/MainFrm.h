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
#include "NsDB.h"
#include "HF04Thread.h"
#include "FbiDioThread.h"
#include <map>
//---------------------------------------------------------------------------
class TSCPostForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
    TImageList *il16;
    TTrayIcon *TrayIcon;
    TPopupMenu *PopupMenu;
    TMenuItem *AD43851;
    TMenuItem *N1;
    TMenuItem *ExitItem;
    TClientSocket *ClientSocket;
    TTimer *SocketReopenTimer;
    TTimer *ThreadCreateTimer;
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
private:	// ���[�U�[�錾
    int place_id_;
    AnsiString notify_sound_;

	////////////////////////////// �v�ʊ֘A
    Currency cur_weight_;
    Currency old_weight_;
    int weighing_border_;
    enum WIStatus {wsStable, wsUnstable, wsOther} cur_wi_status_;

	bool on_weighing_;          			// �v�ʒ����ۂ�
	bool reversed_;  			            // �t�}�����ꂽ��
	bool on_error_;  			            // �v�ʃG���[���������ۂ�
	bool on_printing_;			            // ��������ǂ���
	bool limit_over_;			            // �ߐύڂ��ǂ���
	bool on_wait_exit_;		                // �ގԑ҂����ǂ���
    bool wi_error_;

	void __fastcall OnEnterWeighing(int tag);
	void __fastcall OnExitWeighing(int tag);

    ////////////////////////////// FBIDIO �֘A
    HANDLE fbi_handle_;
    Channels out_channels_;
    TFbiDioThread *dio_thread_;
    int last_card_no_;

    void __fastcall OnDIOStatus(TMessage& message);
    void __fastcall OnDIOInput(TMessage& message);

    void __fastcall OnConfirmButtonDown();
    void __fastcall OnResetButtonDown();
    void __fastcall OnCallButtonDown();

    ////////////////////////////// RFID �ʐM�֘A
   	THF04Thread *rfid_thread_;
    bool rfid_error_;

	void __fastcall OnRFIDAborted(TMessage& message);
	void __fastcall OnRFIDStatus(TMessage& message);
	void __fastcall OnRFIDCard(TMessage& message);
    void __fastcall OnRFIDTimeout(TMessage& message);

    ////////////////////////////// MessageMap
BEGIN_MESSAGE_MAP
	MESSAGE_HANDLER(DIOM_STATUS, TMessage, OnDIOStatus);
	MESSAGE_HANDLER(DIOM_INPUT, TMessage, OnDIOInput);

	MESSAGE_HANDLER(RFIDM_ABORTED, TMessage, OnRFIDAborted);
	MESSAGE_HANDLER(RFIDM_STATUS, TMessage, OnRFIDStatus);
	MESSAGE_HANDLER(RFIDM_CARD, TMessage, OnRFIDCard);
    MESSAGE_HANDLER(RFIDM_TIMEOUT, TMessage, OnRFIDTimeout);
END_MESSAGE_MAP(TForm)

public:		// ���[�U�[�錾
    __fastcall TSCPostForm(TComponent* Owner);

	void __fastcall PrintKeiryoData(int tag, int keiryo_id);
    void __fastcall PrintCopy(int keiryo_id);
    void __fastcall ForceWeighing(int tag);

    void __fastcall UpdateWeighingState();
};
//---------------------------------------------------------------------------
extern PACKAGE TSCPostForm *SCPostForm;
//---------------------------------------------------------------------------
#endif
