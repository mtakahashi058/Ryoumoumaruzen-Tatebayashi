#include "StateForm.h"

StateFormManager SFM;
StateFlowVector SF;

__fastcall AbstractStateForm::AbstractStateForm(TComponent* Owner)
	: TForm(Owner) {
}

__fastcall AbstractStateForm::~AbstractStateForm(){
}

StateFormManager::StateFormManager()
	: current_form_(0), current_state_(State::none), status_handler_(0), event_handler_(0), log_handler_(0) {
}

StateFormManager::~StateFormManager(){
}

void StateFormManager::AddStateForm(State::StateID state, AbstractStateForm *form){
	state_forms_[state] = form;
}

void StateFormManager::RemoveStateForm(State::StateID state){
	state_forms_.erase(state);
}

void StateFormManager::Initialize(const TRect& form_rect, TStatusEvent status_handler, TStateEvent event_handler, TLogEvent log_handler, TPatliteEvent patlite_handler){
	long style;

	status_handler_  = status_handler;
	event_handler_   = event_handler;
	log_handler_     = log_handler;
    patlite_handler_ = patlite_handler;

	for (StateFormCollection::iterator i = state_forms_.begin(); i != state_forms_.end(); i++){

		i->second->Top    = form_rect.Top;
		i->second->Left   = form_rect.Left;
		i->second->Width  = form_rect.Width();
		i->second->Height = form_rect.Height();

/*
		i->second->Top    = 0;
		i->second->Left   = 0;
		i->second->Width  = form_rect.Width();
		i->second->Height = form_rect.Height();
*/

		style = GetWindowLong(i->second->Handle, GWL_STYLE);
		if (style & WS_CAPTION){
			style &= ~WS_CAPTION;
			SetWindowLong(i->second->Handle, GWL_STYLE, style);
		}

		HideForm(i->second);
	}
}

void StateFormManager::Broadcast(Event::EventID event, void *param){
	AbstractStateForm *form;
	for (StateFormCollection::iterator i = state_forms_.begin(); i != state_forms_.end(); i++){
		if (i->second)
			i->second->OnEvent(event, param);
	}
}

void StateFormManager::NotifyEvent(Event::EventID event, void *param){
	if (current_form_)
		current_form_->OnEvent(event, param);
}

AbstractStateForm *StateFormManager::Transit(State::StateID state){
	AbstractStateForm *next_form = state_forms_[state];
	if (!next_form)
		return 0;

	if (current_form_){
		current_form_->OnExit();
		HideForm(current_form_);
	}

	current_form_ = next_form;
	current_state_ = state;

	ActivateForm(current_form_);
	next_form->OnEnter();

	return current_form_;
}

State::StateID StateFormManager::GetCurrentStateID(){
	return current_state_;
}

AbstractStateForm *StateFormManager::GetCurrentStateForm(){
    return current_form_;
}

void StateFormManager::ActivateForm(AbstractStateForm *form){
    ShowWindow(form->Handle, SW_SHOW);
	SetForegroundWindow(form->Handle);
}

void StateFormManager::HideForm(AbstractStateForm *form){
	ShowWindow(form->Handle, SW_HIDE);
}

void __fastcall StateFormManager::SendStatus(const AnsiString& message){
	if (status_handler_)
		status_handler_(message);
}

void __fastcall StateFormManager::SendEvent(State::EventID event, void *param){
	if (event_handler_)
		event_handler_(event, param);
}

void __fastcall StateFormManager::AddLog(const AnsiString& message){
	if (log_handler_)
		log_handler_(message);
}

void __fastcall StateFormManager::PatliteAlert(bool complete, bool error){
	if (patlite_handler_)
    	patlite_handler_(complete, error);
}

Variant __fastcall StateFormManager::Stashed(const AnsiString& key){
	Stash::iterator it = stash.find(key);
	if (it == stash.end())
		throw Exception("Žw’è‚³‚ê‚½ƒL[€–Ú‚Í‘¶Ý‚µ‚Ü‚¹‚ñ");
	return it->second;
}

void __fastcall StateFormManager::CheckStash(){
	AnsiString message;
	for (Stash::iterator it = stash.begin(); it != stash.end(); it++){
		message = it->first + "=" + AnsiString(it->second);
		::MessageBox(0, message.c_str(), "Stash Check", MB_OK);
	}
}

State::StateID NextState(State::StateID state){
	StateFlowVector::iterator i = std::find(SF.begin(), SF.end(), state);
	if (i == SF.end())
		return State::none;
	if (i + 1 == SF.end())
		return State::none;
	return *(i + 1);
}

State::StateID PrevState(State::StateID state){
	StateFlowVector::reverse_iterator i = std::find(SF.rbegin(), SF.rend(), state);
	if (i == SF.rend())
		return State::none;
	if (i + 1 == SF.rend())
		return State::none;
	return *(i + 1);
}

