/** BitField.h: ビット演算が苦手な人のためのヘルパ共用体集
  *
  *     @author a_oshima(ビット演算が苦手)
  */

#ifndef BitField_H_
#define BitField_H_

#include <map>

union BF8{
    unsigned char val;
    struct {
        bool ch1  : 1;
        bool ch2  : 1;
        bool ch3  : 1;
        bool ch4  : 1;
        bool ch5  : 1;
        bool ch6  : 1;
        bool ch7  : 1;
        bool ch8  : 1;
    } channels;
};

union BF16{
    unsigned short val;
    struct {
        bool ch1  : 1;
        bool ch2  : 1;
        bool ch3  : 1;
        bool ch4  : 1;
        bool ch5  : 1;
        bool ch6  : 1;
        bool ch7  : 1;
        bool ch8  : 1;
        bool ch9  : 1;
        bool ch10 : 1;
        bool ch11 : 1;
        bool ch12 : 1;
        bool ch13 : 1;
        bool ch14 : 1;
        bool ch15 : 1;
        bool ch16 : 1;
    } channels;
};

union BF32{
    unsigned int val;
    struct {
        bool ch1  : 1;
        bool ch2  : 1;
        bool ch3  : 1;
        bool ch4  : 1;
        bool ch5  : 1;
        bool ch6  : 1;
        bool ch7  : 1;
        bool ch8  : 1;
        bool ch9  : 1;
        bool ch10 : 1;
        bool ch11 : 1;
        bool ch12 : 1;
        bool ch13 : 1;
        bool ch14 : 1;
        bool ch15 : 1;
        bool ch16 : 1;
        bool ch17 : 1;
        bool ch18 : 1;
        bool ch19 : 1;
        bool ch20 : 1;
        bool ch21 : 1;
        bool ch22 : 1;
        bool ch23 : 1;
        bool ch24 : 1;
        bool ch25 : 1;
        bool ch26 : 1;
        bool ch27 : 1;
        bool ch28 : 1;
        bool ch29 : 1;
        bool ch30 : 1;
        bool ch31 : 1;
        bool ch32 : 1;
    } channels;
};

// 添字は 1 ～
enum CH_STATUS {chOn = 1, chOff = 0, chNull = -1};
class Channels {
    typedef std::map<int, CH_STATUS> ChannelTable;
public:
    Channels(int size){
        for (int i = 0; i < size + 1; i++)
            table_[i] = chNull;
    }
    
    Channels(BYTE val){
        BF8 bf;
        bf.val = val;
        table_[1] = bf.channels.ch1 ? chOn : chOff;
        table_[2] = bf.channels.ch2 ? chOn : chOff;
        table_[3] = bf.channels.ch3 ? chOn : chOff;
        table_[4] = bf.channels.ch4 ? chOn : chOff;
        table_[5] = bf.channels.ch5 ? chOn : chOff;
        table_[6] = bf.channels.ch6 ? chOn : chOff;
        table_[7] = bf.channels.ch7 ? chOn : chOff;
        table_[8] = bf.channels.ch8 ? chOn : chOff;
    }

    Channels(WORD val){
        BF16 bf;
        bf.val = val;
        table_[1]  = bf.channels.ch1  ? chOn : chOff;
        table_[2]  = bf.channels.ch2  ? chOn : chOff;
        table_[3]  = bf.channels.ch3  ? chOn : chOff;
        table_[4]  = bf.channels.ch4  ? chOn : chOff;
        table_[5]  = bf.channels.ch5  ? chOn : chOff;
        table_[6]  = bf.channels.ch6  ? chOn : chOff;
        table_[7]  = bf.channels.ch7  ? chOn : chOff;
        table_[8]  = bf.channels.ch8  ? chOn : chOff;
        table_[9]  = bf.channels.ch9  ? chOn : chOff;
        table_[10] = bf.channels.ch10 ? chOn : chOff;
        table_[11] = bf.channels.ch11 ? chOn : chOff;
        table_[12] = bf.channels.ch12 ? chOn : chOff;
        table_[13] = bf.channels.ch13 ? chOn : chOff;
        table_[14] = bf.channels.ch14 ? chOn : chOff;
        table_[15] = bf.channels.ch15 ? chOn : chOff;
        table_[16] = bf.channels.ch16 ? chOn : chOff;
    }

    Channels(DWORD val){
        BF32 bf;
        bf.val = val;
        table_[1]  = bf.channels.ch1  ? chOn : chOff;
        table_[2]  = bf.channels.ch2  ? chOn : chOff;
        table_[3]  = bf.channels.ch3  ? chOn : chOff;
        table_[4]  = bf.channels.ch4  ? chOn : chOff;
        table_[5]  = bf.channels.ch5  ? chOn : chOff;
        table_[6]  = bf.channels.ch6  ? chOn : chOff;
        table_[7]  = bf.channels.ch7  ? chOn : chOff;
        table_[8]  = bf.channels.ch8  ? chOn : chOff;
        table_[9]  = bf.channels.ch9  ? chOn : chOff;
        table_[10] = bf.channels.ch10 ? chOn : chOff;
        table_[11] = bf.channels.ch11 ? chOn : chOff;
        table_[12] = bf.channels.ch12 ? chOn : chOff;
        table_[13] = bf.channels.ch13 ? chOn : chOff;
        table_[14] = bf.channels.ch14 ? chOn : chOff;
        table_[15] = bf.channels.ch15 ? chOn : chOff;
        table_[16] = bf.channels.ch16 ? chOn : chOff;
        table_[17] = bf.channels.ch17 ? chOn : chOff;
        table_[18] = bf.channels.ch18 ? chOn : chOff;
        table_[19] = bf.channels.ch19 ? chOn : chOff;
        table_[20] = bf.channels.ch20 ? chOn : chOff;
        table_[21] = bf.channels.ch21 ? chOn : chOff;
        table_[22] = bf.channels.ch22 ? chOn : chOff;
        table_[23] = bf.channels.ch23 ? chOn : chOff;
        table_[24] = bf.channels.ch24 ? chOn : chOff;
        table_[25] = bf.channels.ch25 ? chOn : chOff;
        table_[26] = bf.channels.ch26 ? chOn : chOff;
        table_[27] = bf.channels.ch27 ? chOn : chOff;
        table_[28] = bf.channels.ch28 ? chOn : chOff;
        table_[29] = bf.channels.ch29 ? chOn : chOff;
        table_[30] = bf.channels.ch30 ? chOn : chOff;
        table_[31] = bf.channels.ch31 ? chOn : chOff;
        table_[32] = bf.channels.ch32 ? chOn : chOff;
    }

    virtual ~Channels(){}

    CH_STATUS& operator[](int index) {
        /*
        if (index < 1)
            throw Exception("Channels は 1 以上の添字のみ有効です");
        */

        return table_[index];
    }
    CH_STATUS operator[](int index) const {
        /*
        if (index < 1)
            throw Exception("Channels は 1 以上の添字のみ有効です");
        */

        ChannelTable::const_iterator i = table_.find(index);
        if (i == table_.end())
            return chNull;
        return i->second;
    }

    void SetByte(BYTE val){
        BF8 bf;
        bf.val = val;
        table_[1] = bf.channels.ch1 ? chOn : chOff;
        table_[2] = bf.channels.ch2 ? chOn : chOff;
        table_[3] = bf.channels.ch3 ? chOn : chOff;
        table_[4] = bf.channels.ch4 ? chOn : chOff;
        table_[5] = bf.channels.ch5 ? chOn : chOff;
        table_[6] = bf.channels.ch6 ? chOn : chOff;
        table_[7] = bf.channels.ch7 ? chOn : chOff;
        table_[8] = bf.channels.ch8 ? chOn : chOff;
   }

    void SetWord(WORD val){
        BF16 bf;
        bf.val = val;
        table_[1]  = bf.channels.ch1  ? chOn : chOff;
        table_[2]  = bf.channels.ch2  ? chOn : chOff;
        table_[3]  = bf.channels.ch3  ? chOn : chOff;
        table_[4]  = bf.channels.ch4  ? chOn : chOff;
        table_[5]  = bf.channels.ch5  ? chOn : chOff;
        table_[6]  = bf.channels.ch6  ? chOn : chOff;
        table_[7]  = bf.channels.ch7  ? chOn : chOff;
        table_[8]  = bf.channels.ch8  ? chOn : chOff;
        table_[9]  = bf.channels.ch9  ? chOn : chOff;
        table_[10] = bf.channels.ch10 ? chOn : chOff;
        table_[11] = bf.channels.ch11 ? chOn : chOff;
        table_[12] = bf.channels.ch12 ? chOn : chOff;
        table_[13] = bf.channels.ch13 ? chOn : chOff;
        table_[14] = bf.channels.ch14 ? chOn : chOff;
        table_[15] = bf.channels.ch15 ? chOn : chOff;
        table_[16] = bf.channels.ch16 ? chOn : chOff;
    }

    void SetDWord(DWORD val){
        BF32 bf;
        bf.val = val;
        table_[1]  = bf.channels.ch1  ? chOn : chOff;
        table_[2]  = bf.channels.ch2  ? chOn : chOff;
        table_[3]  = bf.channels.ch3  ? chOn : chOff;
        table_[4]  = bf.channels.ch4  ? chOn : chOff;
        table_[5]  = bf.channels.ch5  ? chOn : chOff;
        table_[6]  = bf.channels.ch6  ? chOn : chOff;
        table_[7]  = bf.channels.ch7  ? chOn : chOff;
        table_[8]  = bf.channels.ch8  ? chOn : chOff;
        table_[9]  = bf.channels.ch9  ? chOn : chOff;
        table_[10] = bf.channels.ch10 ? chOn : chOff;
        table_[11] = bf.channels.ch11 ? chOn : chOff;
        table_[12] = bf.channels.ch12 ? chOn : chOff;
        table_[13] = bf.channels.ch13 ? chOn : chOff;
        table_[14] = bf.channels.ch14 ? chOn : chOff;
        table_[15] = bf.channels.ch15 ? chOn : chOff;
        table_[16] = bf.channels.ch16 ? chOn : chOff;
        table_[17] = bf.channels.ch17 ? chOn : chOff;
        table_[18] = bf.channels.ch18 ? chOn : chOff;
        table_[19] = bf.channels.ch19 ? chOn : chOff;
        table_[20] = bf.channels.ch20 ? chOn : chOff;
        table_[21] = bf.channels.ch21 ? chOn : chOff;
        table_[22] = bf.channels.ch22 ? chOn : chOff;
        table_[23] = bf.channels.ch23 ? chOn : chOff;
        table_[24] = bf.channels.ch24 ? chOn : chOff;
        table_[25] = bf.channels.ch25 ? chOn : chOff;
        table_[26] = bf.channels.ch26 ? chOn : chOff;
        table_[27] = bf.channels.ch27 ? chOn : chOff;
        table_[28] = bf.channels.ch28 ? chOn : chOff;
        table_[29] = bf.channels.ch29 ? chOn : chOff;
        table_[30] = bf.channels.ch30 ? chOn : chOff;
        table_[31] = bf.channels.ch31 ? chOn : chOff;
        table_[32] = bf.channels.ch32 ? chOn : chOff;
    }

    BYTE GetByteImage() const {
        ChannelTable::const_iterator it;

        BF8 bf;
        bf.val = 0;
        if ((it = table_.find(1)) != table_.end())
            bf.channels.ch1 = it->second == chOn;
        if ((it = table_.find(2)) != table_.end())
            bf.channels.ch2 = it->second == chOn;
        if ((it = table_.find(3)) != table_.end())
            bf.channels.ch3 = it->second == chOn;
        if ((it = table_.find(4)) != table_.end())
            bf.channels.ch4 = it->second == chOn;
        if ((it = table_.find(5)) != table_.end())
            bf.channels.ch5 = it->second == chOn;
        if ((it = table_.find(6)) != table_.end())
            bf.channels.ch6 = it->second == chOn;
        if ((it = table_.find(7)) != table_.end())
            bf.channels.ch7 = it->second == chOn;
        if ((it = table_.find(8)) != table_.end())
            bf.channels.ch8 = it->second == chOn;
        return bf.val;
    }

    WORD GetWordImage() const {
        ChannelTable::const_iterator it;

        BF16 bf;
        bf.val = 0;
        if ((it = table_.find(1)) != table_.end())
            bf.channels.ch1 = it->second == chOn;
        if ((it = table_.find(2)) != table_.end())
            bf.channels.ch2 = it->second == chOn;
        if ((it = table_.find(3)) != table_.end())
            bf.channels.ch3 = it->second == chOn;
        if ((it = table_.find(4)) != table_.end())
            bf.channels.ch4 = it->second == chOn;
        if ((it = table_.find(5)) != table_.end())
            bf.channels.ch5 = it->second == chOn;
        if ((it = table_.find(6)) != table_.end())
            bf.channels.ch6 = it->second == chOn;
        if ((it = table_.find(7)) != table_.end())
            bf.channels.ch7 = it->second == chOn;
        if ((it = table_.find(8)) != table_.end())
            bf.channels.ch8 = it->second == chOn;
        if ((it = table_.find(9)) != table_.end())
            bf.channels.ch9 = it->second == chOn;
        if ((it = table_.find(10)) != table_.end())
            bf.channels.ch10 = it->second == chOn;
        if ((it = table_.find(11)) != table_.end())
            bf.channels.ch11 = it->second == chOn;
        if ((it = table_.find(12)) != table_.end())
            bf.channels.ch12 = it->second == chOn;
        if ((it = table_.find(13)) != table_.end())
            bf.channels.ch13 = it->second == chOn;
        if ((it = table_.find(14)) != table_.end())
            bf.channels.ch14 = it->second == chOn;
        if ((it = table_.find(15)) != table_.end())
            bf.channels.ch15 = it->second == chOn;
        if ((it = table_.find(16)) != table_.end())
            bf.channels.ch16 = it->second == chOn;
        return bf.val;
    }

    DWORD GetDwordImage() const {
        ChannelTable::const_iterator it;

        BF32 bf;
        bf.val = 0;
        if ((it = table_.find(1)) != table_.end())
            bf.channels.ch1 = it->second == chOn;
        if ((it = table_.find(2)) != table_.end())
            bf.channels.ch2 = it->second == chOn;
        if ((it = table_.find(3)) != table_.end())
            bf.channels.ch3 = it->second == chOn;
        if ((it = table_.find(4)) != table_.end())
            bf.channels.ch4 = it->second == chOn;
        if ((it = table_.find(5)) != table_.end())
            bf.channels.ch5 = it->second == chOn;
        if ((it = table_.find(6)) != table_.end())
            bf.channels.ch6 = it->second == chOn;
        if ((it = table_.find(7)) != table_.end())
            bf.channels.ch7 = it->second == chOn;
        if ((it = table_.find(8)) != table_.end())
            bf.channels.ch8 = it->second == chOn;
        if ((it = table_.find(9)) != table_.end())
            bf.channels.ch9 = it->second == chOn;
        if ((it = table_.find(10)) != table_.end())
            bf.channels.ch10 = it->second == chOn;
        if ((it = table_.find(11)) != table_.end())
            bf.channels.ch11 = it->second == chOn;
        if ((it = table_.find(12)) != table_.end())
            bf.channels.ch12 = it->second == chOn;
        if ((it = table_.find(13)) != table_.end())
            bf.channels.ch13 = it->second == chOn;
        if ((it = table_.find(14)) != table_.end())
            bf.channels.ch14 = it->second == chOn;
        if ((it = table_.find(15)) != table_.end())
            bf.channels.ch15 = it->second == chOn;
        if ((it = table_.find(16)) != table_.end())
            bf.channels.ch16 = it->second == chOn;
        if ((it = table_.find(17)) != table_.end())
            bf.channels.ch17 = it->second == chOn;
        if ((it = table_.find(18)) != table_.end())
            bf.channels.ch18 = it->second == chOn;
        if ((it = table_.find(19)) != table_.end())
            bf.channels.ch19 = it->second == chOn;
        if ((it = table_.find(20)) != table_.end())
            bf.channels.ch20 = it->second == chOn;
        if ((it = table_.find(21)) != table_.end())
            bf.channels.ch21 = it->second == chOn;
        if ((it = table_.find(22)) != table_.end())
            bf.channels.ch22 = it->second == chOn;
        if ((it = table_.find(23)) != table_.end())
            bf.channels.ch23 = it->second == chOn;
        if ((it = table_.find(24)) != table_.end())
            bf.channels.ch24 = it->second == chOn;
        if ((it = table_.find(25)) != table_.end())
            bf.channels.ch25 = it->second == chOn;
        if ((it = table_.find(26)) != table_.end())
            bf.channels.ch26 = it->second == chOn;
        if ((it = table_.find(27)) != table_.end())
            bf.channels.ch27 = it->second == chOn;
        if ((it = table_.find(28)) != table_.end())
            bf.channels.ch28 = it->second == chOn;
        if ((it = table_.find(29)) != table_.end())
            bf.channels.ch29 = it->second == chOn;
        if ((it = table_.find(30)) != table_.end())
            bf.channels.ch30 = it->second == chOn;
        if ((it = table_.find(31)) != table_.end())
            bf.channels.ch31 = it->second == chOn;
        if ((it = table_.find(32)) != table_.end())
            bf.channels.ch32 = it->second == chOn;
        return bf.val;
    }
protected:
    ChannelTable table_;
};

#endif  //BitField_H_
