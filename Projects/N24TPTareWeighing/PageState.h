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
	evCard,				/* カード読み取り		  */
	evRepealTare,		/* 空車情報の取り消し     */
	evWeighTare,		/* 空車重量の計量		  */
	evWeighConfirm,		/* 空車重量警告確認		  */
	evWarning,			/* 警告表示				  */
	evComplete,			/* 制御（完了）			  */
	evBack,				/* 制御（戻る） 		  */
	evNone				/* 無効イベント 		  */
};

/**
 *	状態クラス
 */

// アプリケーション用基底クラス
class PageState : public ackl::State{
protected:
	static int car_id_;
	static int car_no_;
public:
};

// スタートアップ状態
class StartUpState : public PageState{};

// カード待機状態
class WaitCardState : public PageState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);
public:
};

// 処理選択状態
class SelectModeState : public PageState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);
public:
};

// 空車計量状態
class WeighTareState : public PageState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);
public:
};

// 完了状態
class CompleteState : public PageState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);
public:
};

extern StartUpState stateStartup;
extern SelectModeState stateSelectMode;
extern WaitCardState stateWaitCard;
extern WeighTareState stateWeighTare;
extern CompleteState stateComplete;

#endif	//PageState_H_
