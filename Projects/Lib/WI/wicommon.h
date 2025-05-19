// wicommon.h:	�w���v�����C���^�[�t�F�[�X�p�w�b�_�[

#ifndef _WICommonH_
#define _WICommonH_

#ifndef	WIM_TOP
#define	WIM_TOP			(WM_APP + 0xFF)
#endif	//WIM_TOP

/** �ʐM�pMessageID **/

#define	WIM_STATUS		(WIM_TOP + 1)
/** WIM_STATUS		�ʐM��Ԓʒm
 *  WPARAM: unsigned int thread_id
 *  LPARAM: WICommStatus *status
 *  destination: owner
 */

#define	WIM_ABORTED		(WIM_TOP + 2)
/** WIM_ABORTED		�ʐM�ُ�I���ʒm
 *  WPARAM: unsigned int thread_id
 *  LPARAM: none
 *  destination: owner
 */

#define	WIM_WEIGHT		(WIM_TOP + 3)
/** WIM_WEIGHT		�d�ʒʒm
 *  WPARAM: unsigned int thread_id
 *  LPARAM: const WIWeight *weight
 *  destination: owner
 */

#define WIM_ZEROSET		(WIM_TOP + 4)
/** WIM_ZEROSET		�[���ݒ薽��
 *	WPARAM: none
 *	LPARAM: none
 *	destination: thread
 */

#define WIM_CANCELZERO		(WIM_TOP + 5)
/** WIM_CANCELZERO	�[���ݒ�L�����Z������
 *	WPARAM: none
 *	LPARAM: none
 *	destination: thread
 */

/** �f�[�^�����p�\���̒�` **/

/** �X�e�[�^�X�ʒm�\���� **/
struct WICommStatus{
	bool is_fatal;
	AnsiString message;
};

/** �d�ʒʒm�\���� **/
struct WIWeight{
	enum {wiStable, wiUnstable, wiOverload} status;
	Currency weight;
};

/** �ʐM�ݒ�\���� **/
struct WICommInfo{
	int port;
	AnsiString def;
	HANDLE owner;
};

/** SocketClient�p�\���� **/
struct WITcpInfo{
    AnsiString addr;
    int port;
    HANDLE owner;
};

#endif //_WICommonH_
