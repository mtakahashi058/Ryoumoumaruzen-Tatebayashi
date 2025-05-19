/** CardStruct.h
 *      �J�[�h�\���y�уX�}�[�g�J�[�hI/O�C���^�[�t�F�[�X��`�w�b�_
 */

#include "SmartCard.h"

#ifndef CardStruct_H_
#define CardStruct_H_

struct CardImage {
    CardImage();

    void __fastcall clear();

    int card_id;            // �J�[�hID

    int keiryo_date;        // �v�ʓ�    [yyyymmdd]
    int keiryo_time1;       // �v�ʎ���1 [hhnn]
    int keiryo_kbn_id;      // �v�ʋ敪ID
    int car_no;             // �Ԕ�
    int toku_id;
    int item1_id;
    int item2_id;
    int hin_id;
    // AD4385�p
    char* sharyo_id;

    void __fastcall GetHeaderBlock(LPBYTE bytes);
    void __fastcall GetHeaderBlockForUltra(LPBYTE bytes);
    void __fastcall GetDataBlock1(LPBYTE bytes);
    void __fastcall GetDataBlock2(LPBYTE bytes);
    void __fastcall GetDataBlock3(LPBYTE bytes);
    void __fastcall GetDataBlock4(LPBYTE bytes);
    void __fastcall GetDataBlock5(LPBYTE bytes);

    void __fastcall GetHeaderBlock_ultra(LPBYTE bytes, int set_no);
    void __fastcall GetDataBlock_ultra(LPBYTE bytes);
    void __fastcall GetTokuDataBlock(LPBYTE bytes);
    void __fastcall GetItem1DataBlock(LPBYTE bytes);
    void __fastcall GetItem2DataBlock(LPBYTE bytes);
    void __fastcall GetHinDataBlock(LPBYTE bytes);
    void __fastcall GetCarNoFrontBlock_ultra(LPBYTE bytes);
    void __fastcall GetCarNoBackBlock_ultra(LPBYTE bytes);

    bool card_key_valid;    // �J�[�h�L�[�L�����iRead���ɃZ�b�g�����j
    bool system_key_valid;  // �V�X�e���L�[�L�����iRead���ɃZ�b�g�����j
};

// CardImage ��������
void __fastcall WriteImageToSmartCard(SmartCard *card, CardImage *image);
// CardImage ���� SCPOST�p
void __fastcall WriteImageToSmartCard_ultra(SmartCard *card, CardImage *image);
// test ultralight ������
void __fastcall WriteUltraImage(SmartCard *card, CardImage *image);

// CardImage �ǂݍ���
void __fastcall ReadImageFromSmartCard(SmartCard *card, CardImage *image);
void __fastcall ReadImageFromSmartCard_ultra(SmartCard *card, CardImage *image);

// �J�[�h�����i�������f�[�^�u���b�N�̂݁j
void __fastcall ClearSmartCard(SmartCard *card);
// CardImage �� ShowMessage
void __fastcall DumpCardImage(CardImage *image);

#endif  //CardStruct_H_
