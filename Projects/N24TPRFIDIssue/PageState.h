/** PageState.h
 *
 */

#ifndef PageState_H_
#define PageState_H_

#include <vector>
#include "state.h"

//---------------------------------------------------------------------------
// 状態遷移のトリガイベント
enum {
	evAdminCards,		/* 管理用カード発行モード */
    evTokuSelect,       /* 得意先選択             */
    evMeigSelect,       /* 品目選択               */
	evItem1Select,		/* 項目1選択			  */
	evItem2Select,		/* 項目2選択			  */
	evCarNoInput,		/* 車両入力 			  */
	evConfirm,			/* 内容確認 			  */
	evWrite,			/* カード書き込み		  */
	evBack,				/* 制御（戻る） 		  */
	evNone				/* 無効イベント 		  */
};

/**
 *	状態クラス
 */

// アプリケーション用基底クラス
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

// スタートアップ状態
class StartUpState : public PageState{};

// 得意先選択状態
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

// 品目選択状態
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

// 項目1選択状態
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

// 項目2選択状態
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

// 車両入力状態
class InputCarNoState : public PageState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);
public:
};

// 確認状態
class ConfirmState : public PageState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);
};

// カード発行状態基底クラス
class RFIDIssueState: public PageState{
};

// 書込状態
class IssueState : public RFIDIssueState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);
};

// 管理書込状態
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
