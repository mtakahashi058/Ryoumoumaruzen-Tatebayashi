/*
* カード構造及びスマートカードI/Oインターフェース定義ヘッダ
*/

#include <vcl.h>
#pragma hdrstop
#include "CardStruct.h"

CardImage::CardImage(){
    clear();
}

void __fastcall CardImage::clear(){
    card_id = 0;
}

// 内部私用構造体定義
struct HeaderPage{
    char b0;
    char b1;
    char b2;
    char b4;
};

// int == 4byte
struct DataPage {
    int a;
};

void __fastcall CardImage::GetHeaderPage(LPBYTE bytes){
    HeaderPage page;
    page.b0 = 'N';
    page.b1 = 'K';
    page.b2 = 'S';
    page.b3 = 'W';

    ZeroMemory(bytes, 4);
    MoveMemory(bytes, (LPBYTE)&page, 4);
};

void __fastcall CardImage::GetDataPage1(LPBYTE bytes){
    DataPage page;
    // page
    page.a = 0;
}

// Ultralight 書込み
void __fastcall WriteImageToSmartCard(SmartCard *card, CardImage *image){
    BYTE sw1, sw2;
    DWORD err;
    AnsiString err_text;
    BYTE data[20];
    BYTE page;

    // page指定 from page 4
    page = 0x04;

    image->GetHeaderPage(data);
    if (!card->WritePage(sw1, sw2, page, data)) {
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ページ書込に失敗(" + err_text + ") PAGE: " + BytesToHexString(&block, 1, 0x00));
    }

    if (!IsSucceeded(sw1))
        throw Exceptoin("ICカードエラー: ページ書込に失敗 PAGE: " + BytesToHexString(&page, 1, 0x00));

    page = 0x05;

    image->GetDataPage1(data);
    if (!card->WritePage(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ページ書込に失敗(" + err_text + ") PAGE: " + BytesToHexString(&block, 1, 0x00));
    }

    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ページ書込に失敗 PAGE: " + BytesToHexString(&page, 1, 0x00));
}

void __fastcall ReadImageFromSmartCard(SmartCard *card, CardImage *image){
    BYTE sw1, sw2;
    DWORD err;
    AnsiString err_text;
    BYTE data[20];
    BYTE page;

    HeaderPage header_page;
    DataPage data_page1;

    AnsiString read_image;

    page = 0x04;
    if (!card->ReadPage(sw1, sw2, page, data)) {
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ページ読込に失敗(" + err_text + ") PAGE: " + BytesToHexString(&page, 1, 0x00));
    }

    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー：ページ読込に失敗 PAGE: " + BytesToHexString(&page, 1, 0x00));

    page = 0x05;
    ZeroMemory(data, sizeof(data));
    if (!card->ReadPage(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: パージ読込に失敗(" + err_text + ") PAGE: " + BytesToHexString(&page, 1, 0x00));
    }

    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ページ読込に失敗 PAGE: " + BytesToHexString(&page, 1, 0x00));
    data_page1 = *((DataPage *)data);

    image->clear();
    if (header_page.b0 == 'N' && header_page.b1 == 'K' && header_page.b2 == 'S' && header_page.b3 == 'W')
        image->card_key_valid = true;
}