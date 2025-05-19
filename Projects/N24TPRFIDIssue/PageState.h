/** PageState.h
 *
 */

#ifndef PageState_H_
#define PageState_H_

#include <vector>
#include "state.h"

//---------------------------------------------------------------------------
// ��ԑJ�ڂ̃g���K�C�x���g
enum {
	evAdminCards,		/* �Ǘ��p�J�[�h���s���[�h */
    evTokuSelect,       /* ���Ӑ�I��             */
    evMeigSelect,       /* �i�ڑI��               */
	evItem1Select,		/* ����1�I��			  */
	evItem2Select,		/* ����2�I��			  */
	evCarNoInput,		/* �ԗ����� 			  */
	evConfirm,			/* ���e�m�F 			  */
	evWrite,			/* �J�[�h��������		  */
	evBack,				/* ����i�߂�j 		  */
	evNone				/* �����C�x���g 		  */
};

/**
 *	��ԃN���X
 */

// �A�v���P�[�V�����p���N���X
class PageState : public ackl::State{
protected:
    static int        toku_id_;
    static AnsiString toku_name_;
    static int        meig_id_;
    static AnsiString meig_name_;
	static int        item1_id_;
	static AnsiString item1_name_;
	static int        item2_id_;
	static AnsiString item2_name_;
	static int        car_no_;
    static int        car_id_;
    static bool       add_car_;
public:
    int GetTokuID()  {return toku_id_;}
    int GetMeigID()  {return meig_id_;}
	int GetItem1ID() {return item1_id_;}
	int GetItem2ID() {return item2_id_;}
	int GetCarNo()   {return car_no_;}
    int GetCarID()   {return car_id_;}
    bool IsNewCar()  {return add_car_;}
};

// �X�^�[�g�A�b�v���
class StartUpState : public PageState{};

// ���Ӑ�I�����
class SelectTokuState : public PageState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);

	TButton *kana_buttons_[10];
	TButton *buttons_[15];
	int current_top_;
	int enable_cnt_;
	AnsiString kana1_;
	AnsiString kana2_;
public:
	void Initialize();
	void SetupButtons(int start_no);
	void SetKana(const AnsiString& kana1, const AnsiString& kana2)
		{kana1_ = kana1; kana2_ = kana2;}
	int GetCurrentTop()
		{return current_top_;}
	int GetEnabledButtons()
		{return enable_cnt_;}
};

// �i�ڑI�����
class SelectMeigState : public PageState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);

	TButton *kana_buttons_[10];
	TButton *buttons_[15];
	int current_top_;
	int enable_cnt_;
	AnsiString kana1_;
	AnsiString kana2_;
public:
	void Initialize();
	void SetupButtons(int start_no);
	void SetKana(const AnsiString& kana1, const AnsiString& kana2)
		{kana1_ = kana1; kana2_ = kana2;}
	int GetCurrentTop()
		{return current_top_;}
	int GetEnabledButtons()
		{return enable_cnt_;}
};

// ����1�I�����
class SelectItem1State : public PageState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);

	TButton *kana_buttons_[10];
	TButton *buttons_[15];
	int current_top_;
	int enable_cnt_;
	AnsiString kana1_;
	AnsiString kana2_;
public:
	void Initialize();
	void SetupButtons(int start_no);
	void SetKana(const AnsiString& kana1, const AnsiString& kana2)
		{kana1_ = kana1; kana2_ = kana2;}
	int GetCurrentTop()
		{return current_top_;}
	int GetEnabledButtons()
		{return enable_cnt_;}
};

// ����2�I�����
class SelectItem2State : public PageState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);

	TButton *kana_buttons_[10];
	TButton *buttons_[15];
	int current_top_;
	int enable_cnt_;
	AnsiString kana1_;
	AnsiString kana2_;
public:
	void Initialize();
	void SetupButtons(int start_no);
	void SetKana(const AnsiString& kana1, const AnsiString& kana2)
		{kana1_ = kana1; kana2_ = kana2;}
	int GetCurrentTop()
		{return current_top_;}
	int GetEnabledButtons()
		{return enable_cnt_;}
};

// �ԗ����͏��
class InputCarNoState : public PageState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);
public:
};

// �m�F���
class ConfirmState : public PageState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);
};

// �J�[�h���s��Ԋ��N���X
class RFIDIssueState: public PageState{
};

// �������
class IssueState : public RFIDIssueState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);
};

// �Ǘ��������
class AdminIssueState : public RFIDIssueState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);
};

extern StartUpState stateStartup;
extern SelectTokuState stateSelectToku;
extern SelectMeigState stateSelectMeig;
extern SelectItem1State stateSelectItem1;
extern SelectItem2State stateSelectItem2;
extern InputCarNoState stateInputCarNo;
extern ConfirmState stateConfirm;
extern IssueState stateIssue;
extern AdminIssueState stateAdminIssue;

#endif	//PageState_H_
