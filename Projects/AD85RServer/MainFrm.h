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
#include "AD4385Thread.h"
#include "HF04Thread.h"
#include <map>
//---------------------------------------------------------------------------
class TAD4385RPostForm : public TForm
{
__published:    // IDE �Ǘ��̃R���|�[�l���g
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
private:    // ���[�U�[�錾
    int place_id_;
    AnsiString notify_sound_;

    ////////////////////////////// �v�ʊ֘A
    Currency cur_weight_;
    Currency old_weight_;
    int weighing_border_;
    enum WIStatus {wsStable, wsUnstable, wsOther} cur_wi_status_;

    bool on_weighing_;                      // �v�ʒ����ۂ�
    bool reversed_;                         // �t�}�����ꂽ��
    bool on_error_;                         // �v�ʃG���[���������ۂ�
    bool on_printing_;                      // ��������ǂ���
    bool limit_over_;                       // �ߐύڂ��ǂ���
    bool on_wait_exit_;                     // �ގԑ҂����ǂ���

    void __fastcall OnEnterWeighing(int tag);
    void __fastcall OnExitWeighing(int tag);

    ////////////////////////////// RFID �ʐM�֘A
    THF04Thread *rfid_thread_;

    void __fastcall OnRFIDAborted(TMessage& message);
    void __fastcall OnRFIDStatus(TMessage& message);
    void __fastcall OnRFIDCard(TMessage& message);

    ////////////////////////////// AD4385 �ʐM�֘A
    TAD4385Thread *thread_;
    AD4385StartInfo ad85_info_;                 // AD4385 �����ݒ�
    int top_margin_;
    int display_weight_;                        // �\���d��
    unsigned int thread_id_;                    // �X���b�hID
    AD4385Warning ad85_warning_;                // AD4385 ����̌x�����
    AD4385Status ad85_status_;                  // AD4385 ����̃X�e�[�^�X���
    AD4385Params ad85_params_;                  // AD4385 �ւ̎w��
    AD85ItemTable ad85_items_;                  // AD4385 ����̍��ړ���

    bool __fastcall IsThreadActive(int tag);
    void __fastcall CreatePrintImage(PrintImage& image, NsRecord& record);
    void __fastcall OnAD4385CardInsert(int tag, const AD4385CardKeyInfo& info);
    void __fastcall OnAD4385CardReverse(int tag);
    void __fastcall OnAD4385CardOut(int tag);
    void __fastcall OnAD4385PowerOn(int tag);
    void __fastcall OnAD4385PowerNg(int tag);
    void __fastcall OnAD4385PrinterAbnormal(int tag);
    void __fastcall OnAD4385PaperExist(int tag);
    void __fastcall OnAD4385NoPaper(int tag);
    void __fastcall OnAD4385PrintAck(int tag);
    void __fastcall OnAD4385Keiryo(int tag);
    void __fastcall OnAD4385NameRequired(int tag, AD4385RequiredInfo *info);
    void __fastcall UMAD4385Aborted(TMessage& message);

    ////////////////////////////// MessageMap
BEGIN_MESSAGE_MAP
    MESSAGE_HANDLER(RFIDM_ABORTED, TMessage, OnRFIDAborted);
    MESSAGE_HANDLER(RFIDM_STATUS, TMessage, OnRFIDStatus);
    MESSAGE_HANDLER(RFIDM_CARD, TMessage, OnRFIDCard);
    MESSAGE_HANDLER(UM_AD4385_ABORTED, TMessage, UMAD4385Aborted)
END_MESSAGE_MAP(TForm)

public:     // ���[�U�[�錾
    __fastcall TAD4385RPostForm(TComponent* Owner);

    void __fastcall OnAD4385Warning(int tag);
    void __fastcall OnAD4385Event(int tag);
    void __fastcall PrintKeiryoData(int tag, int keiryo_id);
    void __fastcall PrintCopy(int keiryo_id);
    void __fastcall ForceWeighing(int tag);
};
//---------------------------------------------------------------------------
extern PACKAGE TAD4385RPostForm *AD4385RPostForm;
//---------------------------------------------------------------------------
#endif
