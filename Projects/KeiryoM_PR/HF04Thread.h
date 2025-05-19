//---------------------------------------------------------------------------

#ifndef HF04ThreadH
#define HF04ThreadH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include "ocomm.h"
//---------------------------------------------------------------------------
#ifndef	RFIDM_TOP
#define	RFIDM_TOP		    (WM_APP + 0x1F)
#endif	//RFIDM_TOP

#define	RFIDM_STATUS		(RFIDM_TOP + 1)
/** RFIDM_STATUS		��Ԓʒm
 *  WPARAM: bool is_fatal
 *  LPARAM: LPCSTR message
 *  destination: owner
 */

#define	RFIDM_ABORTED		(RFIDM_TOP + 2)
/** RFIDM_ABORTED		�ُ�I���ʒm
 *  WPARAM: none
 *  LPARAM: none
 *  destination: owner
 */

#define	RFIDM_CARD		    (RFIDM_TOP + 3)
/** RFIDM_CARD		�J�[�h�ʒm
 *  WPARAM: bool valid_card
 *  LPARAM: valid_card  -> int card_no
 *          !valid_card -> LPCSTR reason
 *  destination: owner
 */

#define RFIDM_ISSUE         (RFIDM_TOP + 4)
/** RFIDM_ISSUE     �J�[�h���s����
 *  WPARAM: HWND result notify target
 *  LPARAM: int card_no
 *  destination: thread
 */

#define RFIDM_ISS_COMP      (RFIDM_TOP + 5)
/** RFIDM_ISSUE     �J�[�h���s�����ʒm
 *  WPARAM: none
 *  LPARAM: none
 *  destination: result notify target
 */

#define RFIDM_ISS_FAIL      (RFIDM_TOP + 6)
/** RFIDM_ISSUE     �J�[�h���s���s�ʒm
 *  WPARAM: none
 *  LPARAM: none
 *  destination: result notify target
 */

#define RFIDM_TIMEOUT       (RFIDM_TOP + 7)
/** RFID_TIMEOUT    �J�[�h�ʐM�^�C���A�E�g
 *  WPARAM: bool timeouted -> true: timeouted / false: not timeouted
 *  LPARAM: none
 * destination: owner
 */
//---------------------------------------------------------------------------
class THF04Thread : public TThread
{
private:
protected:
    int port_;
    AnsiString def_;
    HWND owner_;

    ackl::OverlappedComm comm_;
    OVERLAPPED o_write, o_read, o_event;

    void __fastcall Execute();
    bool __fastcall FormatMessage(std::string& msg);
	void __fastcall IssueCard(HWND callback_wnd, int card_no);

    AnsiString BytesToHexString(LPBYTE bytes, int size, char sep = ' ');
    bool HexStringToBytes(LPCSTR src, LPBYTE bytes /** src �̔������x�� BYTE �z�� **/);
public:
    __fastcall THF04Thread(bool CreateSuspended, HWND owner, int port, const AnsiString& def = "38400,N,8,1");
};
//---------------------------------------------------------------------------
#endif
