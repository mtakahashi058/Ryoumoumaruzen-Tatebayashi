//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AD4385Thread.h"
#include "utility.h"
#include <fstream>
#include "MainFrm.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

// ���ӁF�قȂ�X���b�h�����L���� VCL �̃��\�b�h/�֐�/�v���p�e�B��
//       �ʂ̃X���b�h�̒����爵���ꍇ�C�r�������̖�肪�������܂��B
//
//       ���C���X���b�h�̏��L����I�u�W�F�N�g�ɑ΂��Ă� Synchronize
//       ���\�b�h���g�������ł��܂��B���̃I�u�W�F�N�g���Q�Ƃ��邽��
//       �̃��\�b�h���X���b�h�N���X�ɒǉ����CSynchronize ���\�b�h��
//       �����Ƃ��ēn���܂��B
//
//       ���Ƃ��� UpdateCaption ���ȉ��̂悤�ɒ�`���A
//
//      void __fastcall TAD4385Thread::UpdateCaption()
//      {
//        Form1->Caption = "�X���b�h���珑�������܂���";
//      }
//
//       Execute ���\�b�h�̒��� Synchronize ���\�b�h�ɓn�����ƂŃ��C
//       ���X���b�h�����L���� Form1 �� Caption �v���p�e�B�����S�ɕ�
//       �X�ł��܂��B
//
//      Synchronize(UpdateCaption);
//
//---------------------------------------------------------------------------
#define NOCARD  (1)
const int COMM_BUFF_SIZE = 200;
//---------------------------------------------------------------------------
__fastcall TAD4385Thread::TAD4385Thread(bool CreateSuspended, const AD4385StartInfo& start_info, int top_margin)
    : TThread(CreateSuspended), start_info_(start_info), ad4385('A'), cur_weight_(0), top_margin_(top_margin)
{
}
//---------------------------------------------------------------------------
bool __fastcall TAD4385Thread::receiveUntilEot()
{
    char read_buff[COMM_BUFF_SIZE + 1];
    E85Status s;
    std::string buff;
    while (1){
        if (Terminated)
            return false;
        Sleep(100);

        try{
            s = ad4385.receiveText(read_buff);
        }catch(AD85Exception& e){
            if (!Terminated){
                start_info_.warning->is_fatal = true;
                start_info_.warning->message = "����|�X�g�X�e�[�^�X���擾�ł��܂���";
                Synchronize(CallAD4385WarningHandler);
                return false;
            }
        }catch(CComm::CommCtrlException& e){
            if (!Terminated){
                start_info_.warning->is_fatal = false;
                start_info_.warning->message = e.GetMessage();
                Synchronize(CallAD4385WarningHandler);
                return false;
            }
        }
        status_array_.push_back(s);

        buff = read_buff;

        if (s == esEos){
            break;
        }else if (s == esCard){
            // �J�[�h���L�[�����\���̂ɃZ�b�g
            card_key_info_.card.str_id    = (buff.substr(3, 8));
            card_key_info_.card.item1 = ackl::fromString<int>(buff.substr(11, 5));
            card_key_info_.card.item2 = ackl::fromString<int>(buff.substr(16, 5));
            card_key_info_.card.item3 = ackl::fromString<int>(buff.substr(21, 5));
            card_key_info_.card.item4 = ackl::fromString<int>(buff.substr(26, 5));

            if (buff.size() >= 50){
                card_key_info_.key.id     = ackl::fromString<int>(buff.substr(21, 7));
                card_key_info_.key.item1  = ackl::fromString<int>(buff.substr(28, 7));
                card_key_info_.key.item2  = ackl::fromString<int>(buff.substr(35, 7));
                card_key_info_.key.item3  = ackl::fromString<int>(buff.substr(42, 7));
                card_key_info_.key.item4  = ackl::fromString<int>(buff.substr(49, 7));
            }
        }else if (s == esNm){
            // ���̑��M�v�����\���̂ɃZ�b�g
            required_info_.item_no   = ackl::fromString<int>(buff.substr(2, 1));
            required_info_.item_code = ackl::fromString<int>(buff.substr(3, 5));
        }
    }
    return true;
}
//---------------------------------------------------------------------------
void __fastcall TAD4385Thread::Execute()
{
    if (!ad4385.open(start_info_.port, start_info_.def.c_str())){
        start_info_.warning->is_fatal = true;
        start_info_.warning->message = "COM�|�[�g���I�[�v���ł��܂���";
        Synchronize(CallAD4385WarningHandler);

        PostMessage(start_info_.owner, UM_AD4385_ABORTED, ThreadID, start_info_.tag);
        return;
    }

    *(start_info_.thread_id) = ThreadID;

    MSG msg;
    AD4385Params *params;
    char param_buff[20];

    bool first = true;
    old_relay_.channel_a = false;
    old_relay_.channel_b = false;

    while (!Terminated){
        if (!receiveUntilEot()){
            // AD4385�X�e�[�^�X�̎�M�Ɏ��s�����ꍇ
            Sleep(500);
            first = true;
            continue;
        }

        try{
            cur_weight_ = *(start_info_.display_weight);
            if (cur_weight_ < 0) cur_weight_ * -1;
            if (cur_weight_ <= 99999 && !first){
                wsprintf(param_buff, "%7d", cur_weight_);
                if (!ad4385.displayWeight(param_buff))
                    throw Exception("�ʐM�G���[(W)");
            }
        }catch(AD85Exception& e){
            start_info_.warning->is_fatal = false;
            start_info_.warning->message = e.what();
            Synchronize(CallAD4385WarningHandler);
            continue;
        }catch(CComm::CommCtrlException& e){
            start_info_.warning->is_fatal = false;
            start_info_.warning->message = e.GetMessage();
            Synchronize(CallAD4385WarningHandler);
            continue;
        }catch(Exception& e){
            start_info_.warning->is_fatal = false;
            start_info_.warning->message = e.Message;
            Synchronize(CallAD4385WarningHandler);
            continue;
        }

        if (first){
            try{
                //if (!ad4385.setDisplay(true))
                //    throw Exception("�ʐM�G���[(D)");
                if (!ad4385.setLamp(false, false, false))
                    throw Exception("�ʐM�G���[(L)");
                if (!ad4385.setRelay(old_relay_.channel_a, old_relay_.channel_b))
                    throw Exception("�ʐM�G���[(R)");
                first = false;

                start_info_.warning->is_fatal = false;
                start_info_.warning->message = "�ʐM���J�n���܂���";
                Synchronize(CallAD4385WarningHandler);
            }catch(AD85Exception& e){
                start_info_.warning->is_fatal = false;
                start_info_.warning->message = e.what();
                Synchronize(CallAD4385WarningHandler);
                continue;
            }catch(CComm::CommCtrlException& e){
                start_info_.warning->is_fatal = false;
                start_info_.warning->message = e.GetMessage();
                Synchronize(CallAD4385WarningHandler);
                continue;
            }catch(Exception& e){
                start_info_.warning->is_fatal = false;
                start_info_.warning->message = e.Message;
                Synchronize(CallAD4385WarningHandler);
                continue;
            }
        }

        for (unsigned int i = 0; i < status_array_.size(); i++){
            switch (status_array_[i]){
            case esCard:
                start_info_.status->event = evCard;
                start_info_.status->card_key_info = card_key_info_;

                Synchronize(CallAD4385EventHandler);
                break;
            case esCardReverse:
                start_info_.status->event = evCardReverse;

                Synchronize(CallAD4385EventHandler);
                break;
            case esCardOut:
                start_info_.status->event = evCardOut;

                Synchronize(CallAD4385EventHandler);
                break;
            case esPowerOn:
                start_info_.status->event = evPowerOn;

                Synchronize(CallAD4385EventHandler);
                break;
            case esPowerNg:
                start_info_.status->event = evPowerNg;

                Synchronize(CallAD4385EventHandler);
                break;
            case esPrinterAbnormal:
                start_info_.status->event = evPrinterAbnormal;

                Synchronize(CallAD4385EventHandler);
                break;
            case esPaperExist:
                start_info_.status->event = evPaperExist;

                Synchronize(CallAD4385EventHandler);
                break;
            case esNoPaper:
                start_info_.status->event = evNoPaper;

                Synchronize(CallAD4385EventHandler);
                break;
            case esPrintAck:
                start_info_.status->event = evPrintAck;

                Synchronize(CallAD4385EventHandler);
                break;
            case esEos:
                break;
            case esOther:
                break;
            case esKa:
                start_info_.status->event = evKeiryo;

                Synchronize(CallAD4385EventHandler);
                break;
            case esNm:
                start_info_.status->event = evNm;
                start_info_.status->required_info = &required_info_;

                Synchronize(CallAD4385EventHandler);
                
                ad4385.displayText(required_info_.reply.c_str());
                break;
            }
        }

        status_array_.clear();

        // ���b�Z�[�W�̎擾
        while (PeekMessage(&msg, 0, UM_AD4385_COMMAND, UM_AD4385_COMMAND, PM_REMOVE)){

            receiveUntilEot();

            try{
                params = (AD4385Params *)msg.lParam;
                switch ((AD4385Command)msg.wParam){
                case cmRestart:
                    if (!ad4385.restart())
                        throw Exception("���X�^�[�g�Ɏ��s���܂���");
                    break;
                case cmLamp:
                    if (!ad4385.setLamp(params->lamp.insert, params->lamp.complete, params->lamp.error))
                        throw Exception("�����v����Ɏ��s���܂���");
                    break;
                case cmKey:
                    if (!ad4385.setKey(params->key))
                        throw Exception("�e���L�[�������Ɏ��s���܂���");
                    break;
                case cmDisplay:
                    if (!ad4385.setDisplay(params->display))
                        throw Exception("�f�B�X�v���C�������Ɏ��s���܂���");
                    break;
                case cmWeight:
                    /** ���̂܂܂ł́A�d�ʕ\���R�}���h�̑Ή��̃E�F�C�g���傫�����邩������Ȃ��̂ŁB */
                    /*
                    wsprintf(param_buff, "%7d", params->weight);
                    if (!ad4385.displayWeight(param_buff))
                        throw Exception("�d�ʒl�\���Ɏ��s���܂���");
                    cur_weight = params->weight;
                    */
                    /* �g��Ȃ��悤�ɂ���: setCurrentWeight(params->weight); */
                    break;
                case cmRelay:
                    old_relay_ = params->relay;
                    if (!ad4385.setRelay(params->relay.channel_a, params->relay.channel_b))
                        throw Exception("�����[����Ɏ��s���܂���");
                    break;
                case cmPrint:
                    {
                        if (top_margin_)
                            //if (!ad4385.setTopMargin(top_margin_ - 5,top_margin_ + 5)) // �Œ�_20190117
                            if (!ad4385.setMargin16())
                                throw Exception("�}�[�W���̐ݒ�Ɏ��s���܂���");
                        Sleep(500);
                        receiveUntilEot();

                        PrintImage image(params->image);

                        for (unsigned int i = 0; i < image.size(); i++){
                            if (image[i] == "END"){
                                if (!ad4385.printText("\r\n"))
                                    throw Exception("�`�[�̈󎚂Ɏ��s���܂���");
                            }else{

                                if (!ad4385.printText(image[i].c_str()))
                                    throw Exception("�`�[�̈󎚂Ɏ��s���܂���");

                            }
                        }
                    }
                    break;
                case cmPrint2:
                    {
                        if (top_margin_)
                            if (!ad4385.setTopMargin(top_margin_ + 5,top_margin_ + 10)) // �Œ�_20190117
                                throw Exception("�}�[�W���̐ݒ�Ɏ��s���܂���");
                        Sleep(500);
                        receiveUntilEot();

                        PrintImage image(params->image);

                        for (unsigned int i = 2; i < image.size(); i++){
                            if (image[i] == "END"){
                                if (!ad4385.printText("\r\n"))
                                    throw Exception("�`�[�̈󎚂Ɏ��s���܂���");
                            }else{

                                if (!ad4385.printText(image[i].c_str()))
                                    throw Exception("�`�[�̈󎚂Ɏ��s���܂���");

                            }
                        }
                    }

                    break;
                case cmPrintMoveDot:
                    if (!ad4385.moveDot(params->dot_size))
                        throw Exception("�󎚃h�b�g�����Ɏ��s���܂���");
                    break;
                case cmBeep:
                    wsprintf(param_buff, "%02d", params->beep_len);
                    if (!ad4385.beep(param_buff))
                        throw Exception("BEEP�o�͂Ɏ��s���܂���");
                    break;
                }
            }catch(AD85Exception& e){
                start_info_.warning->is_fatal = false;
                start_info_.warning->message = e.what();
                Synchronize(CallAD4385WarningHandler);
            }catch(CComm::CommCtrlException& e){
                start_info_.warning->is_fatal = false;
                start_info_.warning->message = e.GetMessage();
                Synchronize(CallAD4385WarningHandler);
            }catch(Exception& e){
                start_info_.warning->is_fatal = false;
                start_info_.warning->message = e.Message;
                Synchronize(CallAD4385WarningHandler);
            }
        }
    }
    try{
        receiveUntilEot();
        ad4385.displayWeight("       ");
        ad4385.setLamp(false, false, false);
        ad4385.setKey(false);
        ad4385.setRelay(false, false);
    }catch(...){}
}
//---------------------------------------------------------------------------
void __fastcall TAD4385Thread::CallAD4385WarningHandler()
{
    AD4385PostForm->OnAD4385Warning(start_info_.tag);
}
//---------------------------------------------------------------------------
void __fastcall TAD4385Thread::CallAD4385EventHandler()
{
    AD4385PostForm->OnAD4385Event(start_info_.tag);
}
//---------------------------------------------------------------------------

