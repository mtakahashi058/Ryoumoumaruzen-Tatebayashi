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
    AD4385 ad4385;                          // AD4385�I�u�W�F�N�g

    AD4385StartInfo start_info_;            // AD4385�ʐM���

    AD4385CardKeyInfo card_key_info_;       // �����p�J�[�h�L�[���
    AD4385RequiredInfo required_info_;      // �����p���O�v�����
    
    std::vector<E85Status> status_array_;   // AD4385�X�e�[�^�X�z��

    bool __fastcall receiveUntilEot();  // AD4385�X�e�[�^�X����M
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
