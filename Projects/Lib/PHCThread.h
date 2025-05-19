//---------------------------------------------------------------------------
/**
 *  PATLITE PHC�pthread
 */
//---------------------------------------------------------------------------
#ifndef PHCThreadH
#define PHCThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <set>
//---------------------------------------------------------------------------
/** TPHCThread �̎g�p���@
  *
  * [�S�_ON]
  *     PHC_OCTET octet;
  *     octet.ch = 0xff;    // �S�_
  *     PostThreadMessage(PHCThread->ThreadID, PHCM_COMMAND, (WPARAM)true, (LPARAM)octet.ch);
  *
  * [�S�_OFF]
  *     PHC_OCTET octet;
  *     octet.ch = 0xff;    // �S�_
  *     PostThreadMessage(PHCThread->ThreadID, PHCM_COMMAND, (WPARAM)false, (LPARAM)octet.ch);
  *
  * [�w��ON]
  *     PHC_OCTET octet;
  *     octet.ch = 0;
  *     octet << 0 << 2 << 3;       // �ړ_0, 2, 3 �̂ݎw��
  *     PostThreadMessage(PHCThread->ThreadID, PHCM_COMMAND, (WPARAM)true, (LPARAM)octet.ch);
  *
  * [�w��OFF]
  *     PHC_OCTET octet;
  *     octet.ch = 0;
  *     octet << 0 << 2 << 3;       // �ړ_0, 2, 3 �̂ݎw��
  *     PostThreadMessage(PHCThread->ThreadID, PHCM_COMMAND, (WPARAM)false, (LPARAM)octet.ch);
  */
//---------------------------------------------------------------------------
#ifndef PHCM_TOP
#define PHCM_TOP        (WM_APP + 0x2FF)
#endif  //WIM_TOP

/** �ʐM�pMessageID **/

#define PHCM_STATUS     (PHCM_TOP + 1)
/** PHCM_STATUS     �ʐM��Ԓʒm
 *  WPARAM: unsigned int thread_id
 *  LPARAM: LPCSTR
 *  Thread -> Owner
 */

#define PHCM_ABORTED        (PHCM_TOP + 2)
/** PHCM_ABORTED    �ʐM�ُ�I���ʒm
 *  WPARAM: unsigned int thread_id
 *  LPARAM: none
 *  Thread -> Owner
 */

#define PHCM_COMMAND        (PHCM_TOP + 3)
/** PHCM_COMMAND    �ʐM����
 *  WPARAM: bool on
 *  LPARAM: char ch (cast to PHC_OCTET)
 *  Owner -> Thread
 */
struct PHCCommInfo{
    int port;
    AnsiString def;
    HANDLE owner;
};
//---------------------------------------------------------------------------
union PHC_OCTET{
    char ch;
    struct{
        char b0:1;
        char b1:1;
        char b2:1;
        char b3:1;
        char b4:1;
        char b5:1;
        char b6:1;
        char b7:1;
    } b;
};
PHC_OCTET& operator<<(PHC_OCTET& octet, int bit);
//---------------------------------------------------------------------------
class TPHCThread : public TThread
{
private:
    PHCCommInfo info_;
    std::string generateCommand(bool done, char ch);
protected:
    void __fastcall Execute();
public:
    __fastcall TPHCThread(bool CreateSuspended, const PHCCommInfo& info);
};
//---------------------------------------------------------------------------
#endif
