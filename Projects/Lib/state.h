/**
 * state.h: 状態遷移クラスヘッダー
 *
 *	@author		ack(akio)
 *	@history	2001/12/03 作成
 *			2001/12/05 STL(map)使用
 *			2002/09/05 名前空間の変更及び表記上の修正
 *
 *	@description
 *	class State:
 *		状態遷移を実現するための基底クラス
 *	[eod]
 */

#ifndef _State_H_
#define _State_H_

#include <map>

// ackl: original namespace
namespace ackl{
	class State;

	// 遷移に伴うアクション
	typedef void (*StateAction)(State *from, void *arg);

	// 状態遷移管理クラス
	struct StateControl{
		//-----------------------------------------------------------------------------------
		// StateControl:			デフォルトコンストラクタ
		StateControl()
			:to(NULL), action(NULL) {}
		//-----------------------------------------------------------------------------------
		// StateControl:			引数付きコンストラクタ
		//	(in)	State *t			遷移先
		//	(in)	StateAction act			遷移に伴うアクション
		StateControl(State *t, StateAction act)
			:to(t), action(act) {}

		State *to;		// 遷移先
		StateAction action;	// 遷移に伴うアクション
	};

	// イベントIDをキーとしたmap
	typedef std::map<int, StateControl> StateMap;

	// 状態クラス
	class State{
		StateMap controller_;	// 状態遷移管理オブジェクト
	protected:
		//-----------------------------------------------------------------------------------
		// onEnter:				状態がアクティブになったときに発生する
		//	(in)	viod *arg:			transit時のデータ
		virtual void onEnter(void *arg) {}
		//-----------------------------------------------------------------------------------
		// onExit:				状態がアクティブでなくなったときに発生する
		//	(in)	viod *arg:			transit時のデータ
		virtual void onExit(void *arg) {}
		//-----------------------------------------------------------------------------------
		// onEvent:				イベントが起きたときに発生する
		//	(in)	int event			イベントID
		//	(in)	viod *arg:			transit時のデータ
		//	(out)	int				処理後のイベントID
		virtual int onEvent(int event, void *arg)
			{return event;}
		//-----------------------------------------------------------------------------------
		// onDefault:				遷移対象外のイベントが起きたときに発生する
		//	int event				イベントID
		//	viod *arg:				transit時のデータ
		virtual void onDefault(int event, void *arg) {}
		//-----------------------------------------------------------------------------------
		// getMap:				管理オブジェクトの取得
		//	(out)	const StateMap&			管理オブジェクト
		const StateMap& getMap() {return controller_;}
	public:
		//-----------------------------------------------------------------------------------
		// State:				コンストラクタ
		State() {}
		//-----------------------------------------------------------------------------------
		// ~State:				デストラクタ
		virtual ~State() {}

		//-----------------------------------------------------------------------------------
		// connectEvent:		イベントと遷移先、アクションの割り当て
		//	(in)	int event			イベントID
		//	(in)	State *to			遷移先
		//	(in)	StateAction action		遷移時のアクション
		//	(out)	State *				Eventに既に割り当てられていた遷移先
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
		// disconnectEvent:		イベント割り当ての解除
		//	(in)	int event			解除するイベントID
		//	(out)	State *				解除された遷移先
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
		// transit:			状態遷移
		//	(in)	int event			発生したイベントID
		//	(in)	void *arg			発生に伴うデータ
		//	(out)	State *				遷移先
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
