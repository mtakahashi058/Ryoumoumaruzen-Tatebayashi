/** CardStruct.h
 *      カード構造及びスマートカードI/Oインターフェース定義ヘッダ
 */

#include "SmartCard.h"

#ifndef CardStruct_H_
#define CardStruct_H_

struct CardImage {
    CardImage();

    void __fastcall clear();

    int card_id;            // カードID

    int keiryo_date;        // 計量日    [yyyymmdd]
    int keiryo_time1;       // 計量時間1 [hhnn]
    int keiryo_kbn_id;      // 計量区分ID
    int car_no;             // 車番
    int toku_id;
    int item1_id;
    int item2_id;
    int hin_id;
    // AD4385用
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

    bool card_key_valid;    // カードキー有効性（Read時にセットされる）
    bool system_key_valid;  // システムキー有効性（Read時にセットされる）
};

// CardImage 書き込み
void __fastcall WriteImageToSmartCard(SmartCard *card, CardImage *image);
// CardImage 書込 SCPOST用
void __fastcall WriteImageToSmartCard_ultra(SmartCard *card, CardImage *image);
// test ultralight 書込み
void __fastcall WriteUltraImage(SmartCard *card, CardImage *image);

// CardImage 読み込み
void __fastcall ReadImageFromSmartCard(SmartCard *card, CardImage *image);
void __fastcall ReadImageFromSmartCard_ultra(SmartCard *card, CardImage *image);

// カード消去（ただしデータブロックのみ）
void __fastcall ClearSmartCard(SmartCard *card);
// CardImage を ShowMessage
void __fastcall DumpCardImage(CardImage *image);

#endif  //CardStruct_H_
