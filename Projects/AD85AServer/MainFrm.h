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
#include <map>
//---------------------------------------------------------------------------
class TAD4385PostForm : public TForm
{
__published:    // IDE 管理のコンポーネント
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
private:    // ユーザー宣言
    int place_id_;
    AnsiString notify_sound_;

    ////////////////////////////// 計量関連
    Currency cur_weight_;
    Currency old_weight_;
    int weighing_border_;
    enum WIStatus {wsStable, wsUnstable, wsOther} cur_wi_status_;

    bool on_weighing_;                      // 計量中か否か
    bool reversed_;                         // 逆挿入されたか
    bool on_error_;                         // 計量エラー発生中か否か
    bool on_printing_;                      // 印刷中かどうか
    bool limit_over_;                       // 過積載かどうか
    bool on_wait_exit_;                     // 退車待ちかどうか

    void __fastcall OnEnterWeighing(int tag);
    void __fastcall OnExitWeighing(int tag);

    ////////////////////////////// AD4385 通信関連
    TAD4385Thread *thread_;
    AD4385StartInfo ad85_info_;                 // AD4385 初期設定
    int top_margin_;
    int display_weight_;                        // 表示重量
    unsigned int thread_id_;                    // スレッドID
    AD4385Warning ad85_warning_;                // AD4385 からの警告情報
    AD4385Status ad85_status_;                  // AD4385 からのステータス情報
    AD4385Params ad85_params_;                  // AD4385 への指示

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
BEGIN_MESSAGE_MAP
    VCL_MESSAGE_HANDLER(UM_AD4385_ABORTED, TMessage, UMAD4385Aborted)
END_MESSAGE_MAP(TForm)

public:     // ユーザー宣言
    __fastcall TAD4385PostForm(TComponent* Owner);

    void __fastcall OnAD4385Warning(int tag);
    void __fastcall OnAD4385Event(int tag);
    void __fastcall PrintKeiryoData(int tag, int keiryo_id);
    void __fastcall PrintKeiryoData(int tag, int keiryo_id, bool plan);
    void __fastcall PrintCopy(int keiryo_id);
    void __fastcall ForceWeighing(int tag);
};
//---------------------------------------------------------------------------
extern PACKAGE TAD4385PostForm *AD4385PostForm;
//---------------------------------------------------------------------------
#endif
