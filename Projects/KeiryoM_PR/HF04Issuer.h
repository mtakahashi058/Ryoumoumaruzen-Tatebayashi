/**
  * HF04Issuer.h: RFID HF04 Issue Class Header
  *
  *     @author a_oshima
  */

#ifndef HF04Issuer_H_
#define HF04Issuer_H_

#include <string>

/** RFID 用例外クラス
  */
class ERFIDError : public Exception {
public:
	__fastcall ERFIDError(const AnsiString Msg) : Exception(Msg) { }
};

class HF04Issuer{
public:
    HF04Issuer(int port);
    virtual ~HF04Issuer();

    void IssueCard(int card_no);
        // failed: throw Exception
protected:
    bool FormatMessage(std::string& msg);
    AnsiString BytesToHexString(LPBYTE bytes, int size, char sep);

    int port_;
    OVERLAPPED o_write_, o_read_, o_event_;
};

#endif  //HF04Issuer_H_
