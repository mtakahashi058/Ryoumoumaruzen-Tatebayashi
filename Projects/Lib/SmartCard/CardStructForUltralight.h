/**
 *  AD4385�p �J�[�h�\���y�уX�}�[�g�J�[�hI/O�C���^�[�t�F�[�X��`�w�b�_ 
 */

#include "SmartCard.h"

#ifndef CardStruct_H_
#define CardStruct_H_

struct CardImage {
    CardImage();

    void __fastcall clear();

    int card_id;    // �J�[�hID

    void __fastcall GetHeaderBlock(LPBYTE);
    void __fastcall GetDataPage1(LPBYTE bytes);
    void __fastcall GetDataPage2(LPBYTE bytes);
    void __fastcall GetDataPage3(LPBYTE bytes);
};

// CardImage ������
void __fastcall WriteImageToSmartCard(SmartCard *card, CardImage *image);

// CardImage �Ǎ�
void __fastcall ReadImageFromSmartCard(SmartCard *card, CardImage *image);

// �J�[�h���� (�������f�[�^�u���b�N�̂�)
void __fastcall ClearSmartCard(SmartCard *card);
// CardImage��ShowMessage
void __fastcall DumpCardImage(CardImage *image);


#endif //CardStruct_H_
 
