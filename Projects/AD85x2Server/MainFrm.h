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
#include "DisplayFrm.h"
#include "AD4385Thread.h"
#include <map>
//---------------------------------------------------------------------------
enum ScaleID {ScaleA = 0, ScaleB};
const int SCALE_COUNT = 2;
//---------------------------------------------------------------------------
class TAD4385PostForm : public TForm
{
__published:	// IDE �Ǘ��̃R���|�[�l���g
    TImageList *il16;
    TTrayIcon *TrayIcon;
    TPopupMenu *PopupMenu;
    TMenuItem *AD43851;
    TMenuItem *N1;
    TMenuItem *ExitItem;
    TClientSocket *ClientSocket1;
    TTimer *SocketReopenTimer;
    TTimer *ThreadCreateTimer;
    TClientSocket *ClientSocket2;
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
    Currency cur_weight_[SCALE_COUNT];
    Currency old_weight_[SCALE_COUNT];
    int weighing_border_;
    enum WIStatus {wsStable, wsUnstable, wsOther} cur_wi_status_[SCALE_COUNT];

	bool on_weighing_[SCALE_COUNT]; 		// �v�ʒ����ۂ�
	bool reversed_[SCALE_COUNT];            // �t�}�����ꂽ��
	bool on_error_[SCALE_COUNT];            // �v�ʃG���[���������ۂ�
	bool on_printing_[SCALE_COUNT];         // ��������ǂ���
	bool limit_over_[SCALE_COUNT];          // �ߐύڂ��ǂ���
	bool on_wait_exit_[SCALE_COUNT];        // �ގԑ҂����ǂ���

	void __fastcall OnEnterWeighing(int tag);
	void __fastcall OnExitWeighing(int tag);

	////////////////////////////// AD4385 �ʐM�֘A
    TAD4385Thread *thread_[SCALE_COUNT];
    AnsiString post_name_[SCALE_COUNT];
	AD4385StartInfo ad85_info_[SCALE_COUNT];    // AD4385 �����ݒ�
    int top_margin_[SCALE_COUNT];
	int display_weight_[SCALE_COUNT];			// �\���d��
	unsigned int thread_id_[SCALE_COUNT];		// �X���b�hID
	AD4385Warning ad85_warning_[SCALE_COUNT];	// AD4385 ����̌x�����
	AD4385Status ad85_status_[SCALE_COUNT];		// AD4385 ����̃X�e�[�^�X���
	AD4385Params ad85_params_[SCALE_COUNT];     // AD4385 �ւ̎w��
    TDisplayForm *ScaleForm_[SCALE_COUNT];

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

public:		// ���[�U�[�錾
    __fastcall TAD4385PostForm(TComponent* Owner);

	void __fastcall OnAD4385Warning(int tag);
	void __fastcall OnAD4385Event(int tag);
	void __fastcall PrintKeiryoData(int tag, int keiryo_id);
    void __fastcall PrintCopy(int keiryo_id);
	void __fastcall ForceWeighing(int tag);
};
//---------------------------------------------------------------------------
extern PACKAGE TAD4385PostForm *AD4385PostForm;
//---------------------------------------------------------------------------
#endif
