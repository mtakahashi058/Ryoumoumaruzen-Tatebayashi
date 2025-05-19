/** StateConst.h
 *      ��ԑJ�ڂ̂��߂̒萔��`
 *      �A�v���P�[�V�������Ƃɒ�`����K�v������
 */

#ifndef StateConst_H_
#define StateConst_H_

#include "NsDB.h"

#include <vector>

namespace State {
    enum StateID {
        Idle,                   /* �v�ʑҋ@                  */
        WaitCard,               /* �J�[�h�҂�                */
        InputCarNo,             /* �Ԕԓ���                  */

        SelectToku,             /* ���Ӑ�I��                */
        SelectItem1,            /* ����1�I��                 */
        SelectItem2,            /* ����2�I��                 */
        ConfirmFirstWeight,     /* ���d�ʊm�F                */

        SelectMeig,             /* �i�ڑI��                  */
        ConfirmWeighing,        /* �v�ʊm�F                  */
        
		ConfirmContinuation,    /* �p���m�F                  */
        ConfirmPrint,           /* �󎚊m�F                  */
        
        WaitExit,               /* �~�ԑ҂�                  */

        Error,
        none = -1
        };
#if 0
    OLD:
    enum StateID {
        Idle,                   /* �v�ʑҋ@                  */
        WaitCard,               /* �J�[�h�҂�                */
        InputCarNo,             /* �Ԕԓ���                  */
        SelectItem1,            /* ����1�I��                 */
        SelectItem2,            /* ����2�I��                 */
        ConfirmFirstWeight,     /* ���d�ʊm�F                */

        SelectItem3,            /* ����3�I��                 */
        ConfirmWeighing,        /* �v�ʊm�F                  */

		ConfirmContinuation,    /* �p���m�F                  */
        ConfirmPrint,           /* �󎚊m�F                  */

        WaitExit,               /* �~�ԑ҂�                  */

        Error,
        none = -1
        };
#endif
}

namespace Event {
    // Event ID
    enum EventID {
        EnterWeighing,          /* �v�ʊJ�n                  */
        ExitWeighing,           /* �v�ʏI��                  */
        Card,                   /* RFID �J�[�h�ǂݎ��       */
        
		//CarNoInput,             /* �Ԕԓ���                  */
		//Item1Select,            /* ����1�I��                 */
        //Item2Select,            /* ����2�I��                 */
        
		//Confirm,                /* �m�F                      */
		//Cancel,                 /* ���                      */
		//Continue,               /* �p��                      */
		//Complete,               /* ����                      */

        //Print,                  /* ��                      */

        Error                   /* ����: �G���[�ʒm          */
    };
}

namespace State {
	// State Event ID
	enum EventID {
		ForceWeighingEnabled,	/* �����v�ʎg�p���     */
		None
	};
};

class NsIni;
extern NsIni INI;

#endif  //StateConst_H_
