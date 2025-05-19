/**
 * state.h: ��ԑJ�ڃN���X�w�b�_�[
 *
 *	@author		ack(akio)
 *	@history	2001/12/03 �쐬
 *			2001/12/05 STL(map)�g�p
 *			2002/09/05 ���O��Ԃ̕ύX�y�ѕ\�L��̏C��
 *
 *	@description
 *	class State:
 *		��ԑJ�ڂ��������邽�߂̊��N���X
 *	[eod]
 */

#ifndef _State_H_
#define _State_H_

#include <map>

// ackl: original namespace
namespace ackl{
	class State;

	// �J�ڂɔ����A�N�V����
	typedef void (*StateAction)(State *from, void *arg);

	// ��ԑJ�ڊǗ��N���X
	struct StateControl{
		//-----------------------------------------------------------------------------------
		// StateControl:			�f�t�H���g�R���X�g���N�^
		StateControl()
			:to(NULL), action(NULL) {}
		//-----------------------------------------------------------------------------------
		// StateControl:			�����t���R���X�g���N�^
		//	(in)	State *t			�J�ڐ�
		//	(in)	StateAction act			�J�ڂɔ����A�N�V����
		StateControl(State *t, StateAction act)
			:to(t), action(act) {}

		State *to;		// �J�ڐ�
		StateAction action;	// �J�ڂɔ����A�N�V����
	};

	// �C�x���gID���L�[�Ƃ���map
	typedef std::map<int, StateControl> StateMap;

	// ��ԃN���X
	class State{
		StateMap controller_;	// ��ԑJ�ڊǗ��I�u�W�F�N�g
	protected:
		//-----------------------------------------------------------------------------------
		// onEnter:				��Ԃ��A�N�e�B�u�ɂȂ����Ƃ��ɔ�������
		//	(in)	viod *arg:			transit���̃f�[�^
		virtual void onEnter(void *arg) {}
		//-----------------------------------------------------------------------------------
		// onExit:				��Ԃ��A�N�e�B�u�łȂ��Ȃ����Ƃ��ɔ�������
		//	(in)	viod *arg:			transit���̃f�[�^
		virtual void onExit(void *arg) {}
		//-----------------------------------------------------------------------------------
		// onEvent:				�C�x���g���N�����Ƃ��ɔ�������
		//	(in)	int event			�C�x���gID
		//	(in)	viod *arg:			transit���̃f�[�^
		//	(out)	int				������̃C�x���gID
		virtual int onEvent(int event, void *arg)
			{return event;}
		//-----------------------------------------------------------------------------------
		// onDefault:				�J�ڑΏۊO�̃C�x���g���N�����Ƃ��ɔ�������
		//	int event				�C�x���gID
		//	viod *arg:				transit���̃f�[�^
		virtual void onDefault(int event, void *arg) {}
		//-----------------------------------------------------------------------------------
		// getMap:				�Ǘ��I�u�W�F�N�g�̎擾
		//	(out)	const StateMap&			�Ǘ��I�u�W�F�N�g
		const StateMap& getMap() {return controller_;}
	public:
		//-----------------------------------------------------------------------------------
		// State:				�R���X�g���N�^
		State() {}
		//-----------------------------------------------------------------------------------
		// ~State:				�f�X�g���N�^
		virtual ~State() {}

		//-----------------------------------------------------------------------------------
		// connectEvent:		�C�x���g�ƑJ�ڐ�A�A�N�V�����̊��蓖��
		//	(in)	int event			�C�x���gID
		//	(in)	State *to			�J�ڐ�
		//	(in)	StateAction action		�J�ڎ��̃A�N�V����
		//	(out)	State *				Event�Ɋ��Ɋ��蓖�Ă��Ă����J�ڐ�
		State *connectEvent(int event, State *to, StateAction action = 0){
			State *r = 0;
			StateMap::iterator it = controller_.find(event);
			if (it != controller_.end()){
				r = it->second.to;
				controller_.erase(it);
			}
			controller_[event] = StateControl(to, action);
			return r;
		}
		//-----------------------------------------------------------------------------------
		// disconnectEvent:		�C�x���g���蓖�Ẳ���
		//	(in)	int event			��������C�x���gID
		//	(out)	State *				�������ꂽ�J�ڐ�
		State *disconnectEvent(int event){
			State *p;

			StateMap::iterator it = controller_.find(event);
			if (it != controller_.end()){
				p = it->second.to;
				controller_.erase(it);
			}else
				p = NULL;
			return p;
		}

		//-----------------------------------------------------------------------------------
		// transit:			��ԑJ��
		//	(in)	int event			���������C�x���gID
		//	(in)	void *arg			�����ɔ����f�[�^
		//	(out)	State *				�J�ڐ�
		State *transit(int event, void *arg = 0){
			int outset = event;
			StateMap::iterator it = controller_.find(onEvent(event, arg));
			if (it == controller_.end()){
				onDefault(event, arg);
				return this;
			}else{
				onExit(arg);
				if (it->second.action) (*it->second.action)(this, arg);
				if (event != outset){
					StateMap::iterator it_tmp = controller_.find(outset);
					if (it_tmp != controller_.end())
						it = it_tmp;
				}
				it->second.to->onEnter(arg);
				return it->second.to;
			}
		}
	};

};	// namespace ackl

#endif	//_State_H_
