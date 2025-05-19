/** CardStruct.cpp
 *      カード構造及びスマートカードI/Oインターフェース定義ヘッダ
 */

#include <vcl.h>
#include <string>
#include <stdio.h>
#pragma hdrstop
#include "CardStruct.h"

CardImage::CardImage(){
    clear();
}

void __fastcall CardImage::clear(){
    card_id       = 0;
    keiryo_date   = 0;
    keiryo_time1  = 0;
    keiryo_kbn_id = 0;
    car_no        = 0;
    toku_id       = 0;
    item1_id      = 0;
    item2_id      = 0;
    hin_id        = 0;
    // 85用
    sharyo_id     = "";

    card_key_valid   = false;
    system_key_valid = false;
}

// 内部使用構造体定義
struct HeaderBlock {
    char b0;
    char b1;
    char b2;
    char b3;
    char b4;
    char b5;
    char b6;
    char b7;
    char b8;
    char b9;
    char b10;
    char b11;
    int card_id;
};

struct CarNoBlock {
    char b0;
    char b1;
    char b2;
    char b3;
    char b4;
    char b5; 
};

struct HeaderBlock_ultra {
    char b0;
    char b1;
    char b2;
    char b3;
};

struct DataBlock {
    int a;
    int b;
    int c;
    int d;
};

struct DataBlock_ultra {
    int card_id;
};

struct DataBlock_id {
    char id[4];
};

static void ReverseArray(DataBlock_id& block){

    char arr[4] = {0};
    char tmp;

    for (int i = 0; i < 2; i++){
        char tmp = block.id[i];
        block.id[i] = block.id[4 - i -1];
        block.id[4 - i -1] = tmp;
    }
}

void __fastcall CardImage::GetHeaderBlock(LPBYTE bytes){
    HeaderBlock block;
    block.b0      = 'N';
    block.b1      = 'K';
    block.b2      = 'S';
    block.b3      = 'W';
    block.b4      = 'D';
    block.b5      = 'S';
    block.b6      = 'W';
    block.b7      = 'S';
    block.b8      = 'M';
    block.b9      = 'C';
    block.b10     = 'R';
    block.b11     = 'D';
    block.card_id = card_id;

    ZeroMemory(bytes, 16);
    MoveMemory(bytes, (LPBYTE)&block, 16);
}

void __fastcall CardImage::GetHeaderBlock_ultra(LPBYTE bytes, int set_no){
    HeaderBlock_ultra block;
/*
    if (set_no ==1){
        block.b0 = 'N';
        block.b1 = 'K';
        block.b2 = 'S';
        block.b3 = 'W';
    }else if (set_no ==2){
        block.b0 = 'D';
        block.b1 = 'S';
        block.b2 = 'W';
        block.b3 = 'S';
    }else if (set_no == 3){
        block.b0 = 'M';
        block.b1 = 'C';
        block.b2 = 'R';
        block.b3 = 'D';

    }
*/

    ZeroMemory(bytes, 4);
    MoveMemory(bytes, (LPBYTE)&block, 4);
}

void __fastcall CardImage::GetCarNoFrontBlock_ultra(LPBYTE bytes)
{
    HeaderBlock_ultra block;

    char a[4];

    sprintf(a, "%4d", card_id);
    std::string str(a);

    block.b0 = a[0];
    block.b1 = a[1];
    block.b2 = a[2];
    block.b3 = a[3];

    ZeroMemory(bytes, 4);
    MoveMemory(bytes, (LPBYTE)&block, 4);


}

void __fastcall CardImage::GetCarNoBackBlock_ultra(LPBYTE bytes)
{
    HeaderBlock_ultra block;

    char b[8];

    sprintf(b, "%-8d", card_id);

    block.b0 = b[4];
    block.b1 = b[5];
    block.b2 = b[6];
    block.b3 = b[7];

    ZeroMemory(bytes, 4);
    MoveMemory(bytes, (LPBYTE)&block, 4);
}

void __fastcall CardImage::GetDataBlock_ultra(LPBYTE bytes){
    DataBlock_ultra block;
    block.card_id = card_id;


    ZeroMemory(bytes, 4);
    MoveMemory(bytes, (LPBYTE)&block, 16);
}

void __fastcall CardImage::GetTokuDataBlock(LPBYTE bytes){
    DataBlock_id block;

    char b[8];

//    int a = 1234;

    memcpy(block.id, &toku_id, 4);
    ReverseArray(block);

    ZeroMemory(bytes, 4);
    MoveMemory(bytes, (LPBYTE)&block, 4);
}

void __fastcall CardImage::GetItem1DataBlock(LPBYTE bytes){
    DataBlock_id block;

    memcpy(block.id, &item1_id, 4);
    ReverseArray(block);

    ZeroMemory(bytes, 4);
    MoveMemory(bytes, (LPBYTE)&block, 4);
}

void __fastcall CardImage::GetItem2DataBlock(LPBYTE bytes){
    DataBlock_id block;

    memcpy(block.id, &item2_id, 4);
    ReverseArray(block);

    ZeroMemory(bytes, 4);
    MoveMemory(bytes, (LPBYTE)&block, 4);
}

void __fastcall CardImage::GetHinDataBlock(LPBYTE bytes){
    DataBlock_id block;

    memcpy(block.id, &hin_id, 4);
    ReverseArray(block);

    ZeroMemory(bytes, 4);

    MoveMemory(bytes, (LPBYTE)&block, 4);
}

void __fastcall CardImage::GetDataBlock1(LPBYTE bytes){
    DataBlock block;
    block.a = keiryo_date;
    block.b = keiryo_time1;
    block.c = keiryo_kbn_id;
    block.d = car_no;

    ZeroMemory(bytes, 16);
    MoveMemory(bytes, (LPBYTE)&block, 16);
}

void __fastcall CardImage::GetDataBlock2(LPBYTE bytes){
    DataBlock block;
/*    block.a = torihiki_id;
    block.b = dainou_id;
    block.c = unsou_id;
    block.d = meigara_id;
*/
    ZeroMemory(bytes, 16);
    MoveMemory(bytes, (LPBYTE)&block, 16);
}

void __fastcall CardImage::GetDataBlock3(LPBYTE bytes){
    DataBlock block;
/*
    block.a = kosuu;
    block.b = okiba_id;
    block.c = kensyu_id;
    block.d = suibun_ritu;
*/
    ZeroMemory(bytes, 16);
    MoveMemory(bytes, (LPBYTE)&block, 16);
}

void __fastcall CardImage::GetDataBlock4(LPBYTE bytes){
    DataBlock block;
/*
    block.a = suibun_ryo;
    block.b = fujun_ritu;
    block.c = fujun_ryo;
    block.d = gross_weight;
*/
    ZeroMemory(bytes, 16);
    MoveMemory(bytes, (LPBYTE)&block, 16);
}

void __fastcall CardImage::GetDataBlock5(LPBYTE bytes){
    DataBlock block;
/*
    block.a = kosuu2;
    block.b = okiba_id2;
    block.c = 0;
    block.d = 0;
*/
    ZeroMemory(bytes, 16);
    MoveMemory(bytes, (LPBYTE)&block, 16);
}

// Ultra用
void __fastcall WriteUltraImage(SmartCard *card, CardImage *image){
    BYTE sw1, sw2;
    BYTE key[6];
    DWORD err;
    AnsiString err_text;
    BYTE data[20];
    BYTE block;

    // 認証回避

    block = 0x04;

    image->GetHeaderBlock(data);
    if (!card->WriteBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック書込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック書込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));
/*
*/
    block = 0x05;
    //image->GetDataBlock1(data);
    image->GetHeaderBlock(data);
    if (!card->WriteBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック書込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック書込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    block = 0x06;
    image->GetDataBlock2(data);
    if (!card->WriteBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック書込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック書込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    // block = 0x07はトレーラブロックなので除外

    block = 0x08;

    image->GetDataBlock3(data);
    if (!card->WriteBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック書込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック書込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    block = 0x09;
    image->GetDataBlock4(data);
    if (!card->WriteBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック書込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック書込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    block = 0x0a;
    image->GetDataBlock5(data);
    if (!card->WriteBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック書込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック書込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));
}

void __fastcall WriteImageToSmartCard_ultra(SmartCard *card, CardImage *image){
    BYTE sw1, sw2;
    DWORD err_dword;
    AnsiString err_text;
    BYTE data[4];
    BYTE block;

    block = 0x04;
    //image->GetHeaderBlock_ultra(data, 1);
    image->GetCarNoFrontBlock_ultra(data);
    if (!card->WritePage(sw1, sw2, block, data)){
        card->GetLastError(err_dword, err_text);
        throw Exception("ICカードエラー: ページ書込みに失敗 (" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: BLOCK書き込みに失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    block = 0x05;
    //image->GetHeaderBlock_ultra(data, 2);
    image->GetCarNoBackBlock_ultra(data);
    if (!card->WritePage(sw1, sw2, block, data)){
        card->GetLastError(err_dword, err_text);
        throw Exception("ICカードエラー: ページ書込みに失敗 (" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: BLOCK書き込みに失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    block = 0x06;
    //image->GetHeaderBlock_ultra(data, 3);
    image->GetTokuDataBlock(data);
    if (!card->WritePage(sw1, sw2, block, data)){
        card->GetLastError(err_dword, err_text);
        throw Exception("ICカードエラー: ページ書込みに失敗 (" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: BLOCK書き込みに失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    block = 0x07;
    //image->GetDataBlock_ultra(data);
    image->GetHinDataBlock(data);
    if (!card->WritePage(sw1, sw2, block, data)){
        card->GetLastError(err_dword, err_text);
        throw Exception("ICカードエラー: ページ書込みに失敗 (" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: BLOCK書き込みに失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    block = 0x08;
    //image->GetDataBlock_ultra(data);
    image->GetItem1DataBlock(data);
    if (!card->WritePage(sw1, sw2, block, data)){
        card->GetLastError(err_dword, err_text);
        throw Exception("ICカードエラー: ページ書込みに失敗 (" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: BLOCK書き込みに失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    block = 0x09;
    //image->GetDataBlock_ultra(data);
    image->GetItem2DataBlock(data);
    if (!card->WritePage(sw1, sw2, block, data)){
        card->GetLastError(err_dword, err_text);
        throw Exception("ICカードエラー: ページ書込みに失敗 (" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: BLOCK書き込みに失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

}

void __fastcall WriteImageToSmartCard(SmartCard *card, CardImage *image){
    BYTE sw1, sw2;
    BYTE key[6];
    DWORD err;
    AnsiString err_text;
    BYTE data[20];
    BYTE block;

    block = 0x04;
    if (!card->Authenticate(sw1, sw2, block, SmartCard::TypeA)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: IC認証に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: IC認証に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    // BYTE data[20]
    image->GetHeaderBlock(data);
    if (!card->WriteBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック書込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック書込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    block = 0x05;
    image->GetDataBlock1(data);
    if (!card->WriteBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック書込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック書込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    block = 0x06;
    image->GetDataBlock2(data);
    if (!card->WriteBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック書込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック書込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    // block = 0x07はトレーラブロックなので除外

    block = 0x08;
    if (!card->Authenticate(sw1, sw2, block, SmartCard::TypeA)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: IC認証に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: IC認証に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    image->GetDataBlock3(data);
    if (!card->WriteBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック書込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック書込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    block = 0x09;
    image->GetDataBlock4(data);
    if (!card->WriteBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック書込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック書込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    block = 0x0a;
    image->GetDataBlock5(data);
    if (!card->WriteBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック書込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック書込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));



}

void __fastcall ReadImageFromSmartCard(SmartCard *card, CardImage *image){
    BYTE sw1, sw2;
    DWORD err;
    AnsiString err_text;
    BYTE data[20];
    BYTE block;

    HeaderBlock header_block;
    DataBlock   data_block1,
                data_block2,
                data_block3,
                data_block4,
                data_block5;

    AnsiString read_image;

    block = 0x04;
    if (!card->Authenticate(sw1, sw2, block, SmartCard::TypeA)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: IC認証に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: IC認証に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    ZeroMemory(data, sizeof(data));
    if (!card->ReadBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック読込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック読込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));
    header_block = *((HeaderBlock *)data);

    block =0x05;
    ZeroMemory(data, sizeof(data));
    if (!card->ReadBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック読込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック読込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));
    data_block1 = *((DataBlock *)data);

    block =0x06;
    ZeroMemory(data, sizeof(data));
    if (!card->ReadBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック読込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック読込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));
    data_block2 = *((DataBlock *)data);

    block =0x08;
    if (!card->Authenticate(sw1, sw2, block, SmartCard::TypeA)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: IC認証に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: IC認証に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

    ZeroMemory(data, sizeof(data));

    if (!card->ReadBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック読込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック読込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));
    data_block3 = *((DataBlock *)data);

    block =0x09;
    ZeroMemory(data, sizeof(data));
    if (!card->ReadBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック読込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック読込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));
    data_block4 = *((DataBlock *)data);

    block =0x0a;
    ZeroMemory(data, sizeof(data));
    if (!card->ReadBlock(sw1, sw2, block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック読込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }
    if (!IsSucceeded(sw1))
        throw Exception("ICカードエラー: ブロック読込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));
    data_block5 = *((DataBlock *)data);

    image->clear();
    if (header_block.b0 == 'N' && header_block.b1 == 'K' && header_block.b2 == 'S' && header_block.b3 == 'W')
        image->card_key_valid = true;
    if (header_block.b4 == 'D' && header_block.b5 == 'S' && header_block.b6 == 'W' && header_block.b7 == 'S'
            && header_block.b8 == 'M' && header_block.b9 == 'C' && header_block.b10 == 'R' && header_block.b11 == 'D')
        image->system_key_valid = true;

    image->card_id       = header_block.card_id;
    image->keiryo_date   = data_block1.a;
    image->keiryo_time1  = data_block1.b;
    image->keiryo_kbn_id = data_block1.c;
    image->car_no        = data_block1.d;
/*
    image->torihiki_id   = data_block2.a;
    image->dainou_id     = data_block2.b;
    image->unsou_id      = data_block2.c;
    image->meigara_id    = data_block2.d;
    image->kosuu         = data_block3.a;
    image->okiba_id      = data_block3.b;
    image->kensyu_id     = data_block3.c;
    image->suibun_ritu   = data_block3.d;
    image->suibun_ryo    = data_block4.a;
    image->fujun_ritu    = data_block4.b;
    image->fujun_ryo     = data_block4.c;
    image->gross_weight  = data_block4.d;
    image->kosuu2        = data_block5.a;
    image->okiba_id2     = data_block5.b;
*/
}

void __fastcall ReadImageFromSmartCard_ultra(SmartCard *card, CardImage *image){
    BYTE sw1, sw2;
    DWORD err;
    AnsiString err_text;
    BYTE data[6];
    BYTE block;

    HeaderBlock header_block;
    DataBlock   data_block1,
                data_block2,
                data_block3,
                data_block4,
                data_block5;

    AnsiString read_image;

    block = 0x04;

    ZeroMemory(data, sizeof(data));
    if (!card->ReadUltraBlock(block, data)){
        card->GetLastError(err, err_text);
        throw Exception("ICカードエラー: ブロック読込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
    }

    AnsiString tmp_card_string = AnsiString((char*)data);

    // TODO 処理を再考の余地あり
    //tmp_card_string = StringReplace(tmp_card_string, " ", "", TReplaceFlags() << rfReplaceAll);
    tmp_card_string = tmp_card_string.Trim();

    image->system_key_valid = true;

    //image->card_id = tmp_card_string.SubString(1, 6).ToIntDef(0);
    image->card_id = tmp_card_string.ToIntDef(0);

}


void __fastcall ClearSmartCard(SmartCard *card){
    BYTE sw1, sw2;
    BYTE key[6];
    DWORD err;
    AnsiString err_text;
    BYTE data[20];

    int block_no;
    int block_count = 5;

    int write_count = 0;
    for (BYTE block = 0x05; write_count < block_count; block++){
        if (!SmartCard::IsAvailableBlock(block))
            continue;

        block_no = block % 4;

        if (block_no == 0 || block == 0x05){
            if (!card->Authenticate(sw1, sw2, block, SmartCard::TypeA)){
                card->GetLastError(err, err_text);
                throw Exception("ICカードエラー: IC認証に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
            }
            if (!IsSucceeded(sw1))
                throw Exception("ICカードエラー: IC認証に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));
        }

        ZeroMemory(data, sizeof(data));
        if (!card->WriteBlock(sw1, sw2, block, data)){
            card->GetLastError(err, err_text);
            throw Exception("ICカードエラー: ブロック書込に失敗(" + err_text + ") BLOCK: " + BytesToHexString(&block, 1, 0x00));
        }
        if (!IsSucceeded(sw1))
            throw Exception("ICカードエラー: ブロック書込に失敗 BLOCK: " + BytesToHexString(&block, 1, 0x00));

        write_count++;
    }
}

void __fastcall DumpCardImage(CardImage *image){
    ShowMessage("カードID: " + IntToStr(image->card_id));
    ShowMessage("計量日: " + IntToStr(image->keiryo_date));
    ShowMessage("計量時間1: " + IntToStr(image->keiryo_time1));
    ShowMessage("計量区分ID: " + IntToStr(image->keiryo_kbn_id));
    ShowMessage("車番: " + IntToStr(image->car_no));
/*
    ShowMessage("取引先ID: " + IntToStr(image->torihiki_id));
    ShowMessage("代納業者ID: " + IntToStr(image->dainou_id));
    ShowMessage("運送業者ID: " + IntToStr(image->unsou_id));
    ShowMessage("銘柄ID: " + IntToStr(image->meigara_id));
    ShowMessage("個数: " + IntToStr(image->kosuu));
    ShowMessage("置場ID: " + IntToStr(image->okiba_id));
    ShowMessage("検収員ID: " + IntToStr(image->kensyu_id));
    ShowMessage("水分率: " + IntToStr(image->suibun_ritu));
    ShowMessage("水分量: " + IntToStr(image->suibun_ryo));
    ShowMessage("不純物率: " + IntToStr(image->fujun_ritu));
    ShowMessage("不純物量: " + IntToStr(image->fujun_ryo));
    ShowMessage("総重量: " + IntToStr(image->gross_weight));
    ShowMessage("個数2: " + IntToStr(image->kosuu2));
    ShowMessage("置場ID2: " + IntToStr(image->okiba_id2));
*/
}
