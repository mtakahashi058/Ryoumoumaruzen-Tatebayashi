/**
 *  AD4385用 カード構造及びスマートカードI/Oインターフェース定義ヘッダ 
 */

#include "SmartCard.h"

#ifndef CardStruct_H_
#define CardStruct_H_

struct CardImage {
    CardImage();

    void __fastcall clear();

    int card_id;    // カードID

    void __fastcall GetHeaderBlock(LPBYTE);
    void __fastcall GetDataPage1(LPBYTE bytes);
    void __fastcall GetDataPage2(LPBYTE bytes);
    void __fastcall GetDataPage3(LPBYTE bytes);
};

// CardImage 書込み
void __fastcall WriteImageToSmartCard(SmartCard *card, CardImage *image);

// CardImage 読込
void __fastcall ReadImageFromSmartCard(SmartCard *card, CardImage *image);

// カード消去 (ただしデータブロックのみ)
void __fastcall ClearSmartCard(SmartCard *card);
// CardImageをShowMessage
void __fastcall DumpCardImage(CardImage *image);


#endif //CardStruct_H_
 
