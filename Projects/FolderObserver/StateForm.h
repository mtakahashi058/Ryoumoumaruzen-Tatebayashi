/** StateForm.h
 *      状態遷移用管理クラス定義
 */

#ifndef StateForm_H_
#define StateForm_H_

#include <Forms.hpp>
#include <Types.hpp>
#include <map>
#include <vector>
#include "StateConst.h"

class AbstractStateForm : public TForm {
public:
	__fastcall AbstractStateForm(TComponent* Owner);
	virtual __fastcall ~AbstractStateForm();

	virtual void __fastcall OnEvent(Event::EventID event, void *param) = 0;
	virtual void __fastcall OnEnter() = 0;
	virtual void __fastcall OnExit() = 0;
};

typedef std::map<AnsiString, Variant> Stash;

typedef void __fastcall (__closure *TStatusEvent)(const AnsiString& message);
typedef void __fastcall (__closure *TLogEvent)(const AnsiString& message);
typedef void __fastcall (__closure *TStateEvent)(State::EventID event, void *param);
typedef void __fastcall (__closure *TPatliteEvent)(bool cmpl, bool err);

class StateFormManager {
	typedef std::map<State::StateID, AbstractStateForm *> StateFormCollection;
public:
	StateFormManager();
	~StateFormManager();

	void AddStateForm(State::StateID state, AbstractStateForm *form);
	void RemoveStateForm(State::StateID state);

	void Initialize(const TRect& form_rect,
    	TStatusEvent status_handler, TStateEvent event_handler,
        TLogEvent log_handler, TPatliteEvent patlite_handler);

	////////////////////////////////////////////////////////////////////////////////////////////////
	// 管理用イベント通知メソッド
	void Broadcast(Event::EventID event, void *param = 0);
	void NotifyEvent(Event::EventID event, void *param = 0);
	////////////////////////////////////////////////////////////////////////////////////////////////

	AbstractStateForm *Transit(State::StateID state);

	State::StateID GetCurrentStateID();
	AbstractStateForm *GetCurrentStateForm();

	void ActivateForm(AbstractStateForm *form);
	void HideForm(AbstractStateForm *form);

	////////////////////////////////////////////////////////////////////////////////////////////////
	// StateForm からの情報通知メソッド
	void __fastcall SendStatus(const AnsiString& message);
	void __fastcall SendEvent(State::EventID event, void *param);
	void __fastcall AddLog(const AnsiString& message);
    void __fastcall PatliteAlert(bool complete, bool error);
	////////////////////////////////////////////////////////////////////////////////////////////////

	Variant __fastcall Stashed(const AnsiString& key);
	void __fastcall CheckStash();

    NsRecord car_rec;
    NsRecord remained_rec;
	Stash stash;
private:
	StateFormCollection state_forms_;
	AbstractStateForm *current_form_;
	State::StateID current_state_;
	TStatusEvent status_handler_;
	TStateEvent event_handler_;
	TLogEvent log_handler_;
    TPatliteEvent patlite_handler_;
};

extern StateFormManager SFM;

typedef std::vector<State::StateID> StateFlowVector;

extern StateFlowVector SF;

State::StateID NextState(State::StateID state);
State::StateID PrevState(State::StateID state);

#endif  //StateForm_H_
