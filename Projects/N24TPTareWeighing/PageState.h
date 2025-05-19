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
	evCard,				/* �J�[�h�ǂݎ��		  */
	evRepealTare,		/* ��ԏ��̎�����     */
	evWeighTare,		/* ��ԏd�ʂ̌v��		  */
	evWeighConfirm,		/* ��ԏd�ʌx���m�F		  */
	evWarning,			/* �x���\��				  */
	evComplete,			/* ����i�����j			  */
	evBack,				/* ����i�߂�j 		  */
	evNone				/* �����C�x���g 		  */
};

/**
 *	��ԃN���X
 */

// �A�v���P�[�V�����p���N���X
class PageState : public ackl::State{
protected:
	static int car_id_;
	static int car_no_;
public:
};

// �X�^�[�g�A�b�v���
class StartUpState : public PageState{};

// �J�[�h�ҋ@���
class WaitCardState : public PageState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);
public:
};

// �����I�����
class SelectModeState : public PageState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);
public:
};

// ��Ԍv�ʏ��
class WeighTareState : public PageState{
	void onEnter(void *v);
	void onExit(void *v);
	int onEvent(int event, void *arg);
public:
};

// �������
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
