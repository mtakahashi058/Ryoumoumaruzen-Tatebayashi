/**
  * SmartCard.h: SmartCard Control Class (for ACR122 on VCL)
  *
  *     @author a_oshima
  *     @description
  *         MIFARE with T1 Protocol only
  *     @history
  *                 2009-11-25  作成
  */

#ifndef SmartCard_H_
#define SmartCard_H_

#include <winscard.h>
#include <map>

class SCBytes {
public:
    SCBytes() : bytes_(0), size_(0) {}
    SCBytes(int size){
        bytes_ = new BYTE[size];
        size_ = size;
        ZeroMemory(bytes_, size_);
    }
    SCBytes(LPBYTE bytes, int size){
        bytes_ = new BYTE[size];
        size_ = size;
        CopyMemory(bytes_, bytes, size);
    }
    SCBytes(const SCBytes& bytes){
        size_ = bytes.size_;
        bytes_ = new BYTE[size_];
        CopyMemory(bytes_, bytes.bytes_, size_);
    }
    virtual ~SCBytes(){
        if (bytes_)
            delete[] bytes_;
    }

    SCBytes& operator=(const SCBytes& bytes){
        if (bytes_)
            delete[] bytes_;

        size_ = bytes.size_;
        bytes_ = new BYTE[size_];
        CopyMemory(bytes_, bytes.bytes_, size_);
        return *this;
    }
    LPCBYTE operator()() const {
        return bytes_;
    }
    LPBYTE operator()() {
        return bytes_;
    }
    int size() const {
        return size_;
    }
protected:
    LPBYTE bytes_;
    int size_;
};

class SmartCard;

class SmartCardService {
public:
    typedef std::map<int, AnsiString> Readers;

    SmartCardService();
    virtual ~SmartCardService();
    
    bool Establish();
    bool EnumReaders(Readers& readers);

    void SetReader(AnsiString reader);

    bool GetStatusChange(DWORD& event, DWORD cur_state = SCARD_STATE_UNAWARE, DWORD timeout = 0);

    bool ConnectCard(SmartCard *smart_card);

    DWORD GetLastError(DWORD& err, AnsiString& text);

    static bool CheckService();

    static AnsiString BytesToHexString(LPBYTE bytes, int size, char sep = ' ');
    static bool HexStringToBytes(LPCSTR src, LPBYTE bytes /** src の半分程度の BYTE 配列 **/);

protected:
    SCARDCONTEXT context_;
    AnsiString reader_;
    long last_result_;
};

class SmartCard {
public:
    enum AuthKeyType {TypeA, TypeB};

    SmartCard();
    SmartCard(SCARDHANDLE handle);
    virtual ~SmartCard();

    void Assign(SCARDHANDLE handle);
    void Disconnect();

    bool Transmit(LPBYTE cmd, DWORD size, SCBytes& res, DWORD& res_size);

    bool BeginTransaction();
    bool EndTransaction(DWORD disposition = SCARD_LEAVE_CARD);

    bool LoadKey(BYTE& sw1, BYTE& sw2, LPBYTE key, BYTE number = 0x00);   /** key: 6octet **/
    bool Authenticate(BYTE& sw1, BYTE& sw2, BYTE block, AuthKeyType type, BYTE key_number = 0x00);
    bool ReadBlock(BYTE& sw1, BYTE& sw2, BYTE block, LPBYTE data);  /** data: 16octet memory **/
    bool ReadPage(BYTE& sw1, BYTE& sw2, BYTE block, LPBYTE data);   /** data:  4octed memory **/
    bool ReadUltraBlock(BYTE block, LPBYTE data);
    bool WriteBlock(BYTE& sw1, BYTE& sw2, BYTE block, LPBYTE data); /** data: 16octet memory **/
    bool WritePage(BYTE& sw1, BYTE& sw2, BYTE page, LPBYTE data);   /** data:  4octet memory **/
    bool WriteUltraBlock(BYTE& sw1, BYTE& sw2, BYTE block, LPBYTE data);

    bool GetATR(LPBYTE buff);   /** buff: 32octet memory **/

    DWORD GetLastError(DWORD& err, AnsiString& text);

    static void GenerateCommand(BYTE CLA, BYTE INS, BYTE P1, BYTE P2, BYTE Lc, LPBYTE data, int data_len, LPBYTE *cmd, int& size);
    static int ParseResponse(LPBYTE res, int size, BYTE& sw1, BYTE& sw2);

    /** Block Helper Member (for MIFARE 1K/4K) **/
    static bool IsAvailableBlock(BYTE block);
protected:
    SCARDHANDLE handle_;
    long last_result_;
};

// helper
bool IsSucceeded(BYTE sw1);
AnsiString BytesToHexString(LPBYTE bytes, int size, char sep = ' ');
bool HexStringToBytes(LPCSTR src, LPBYTE bytes /** src の半分程度の BYTE 配列 **/);
AnsiString GetErrorText(DWORD err);
bool CompareBytes(const LPBYTE p1, const LPBYTE p2, int size);
AnsiString GetSwitchValueForLog(BYTE sw1, BYTE sw2);

#endif  // SmartCard_H_
