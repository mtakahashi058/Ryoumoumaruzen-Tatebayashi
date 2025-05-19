//---------------------------------------------------------------------------

#ifndef AD4385ThreadH
#define AD4385ThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <string>
#include <vector>
#include "ad85def.h"
#include "AD4385.h"
//---------------------------------------------------------------------------
class TAD4385Thread : public TThread
{
private:
    AD4385 ad4385;                          // AD4385オブジェクト

    AD4385StartInfo start_info_;            // AD4385通信情報

    AD4385CardKeyInfo card_key_info_;       // 内部用カードキー情報
    AD4385RequiredInfo required_info_;      // 内部用名前要求情報
    
    std::vector<E85Status> status_array_;   // AD4385ステータス配列

    bool __fastcall receiveUntilEot();  // AD4385ステータスを受信
protected:
    void __fastcall Execute();

    void __fastcall CallAD4385WarningHandler();
    void __fastcall CallAD4385EventHandler();

    int cur_weight_;
    AD4385Relay old_relay_;
    int top_margin_;
public:
    __fastcall TAD4385Thread(bool CreateSuspended, const AD4385StartInfo& start_info, int top_margin);
};
//---------------------------------------------------------------------------
#endif
