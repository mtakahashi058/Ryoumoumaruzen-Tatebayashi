// common.h:	�X���b�h�ԒʐM�y�ю�n�f�[�^�p�w�b�_�[

#ifndef _CommonH_
#define _CommonH_

#include <string>
#include <vector>

/** �ʐM�pMessageID **/

#ifndef	AD85M_TOP
#define	AD85M_TOP			(WM_APP + 0x1FF)
#endif	//AD85M_TOP


#define UM_AD4385_ABORTED		(AD85M_TOP + 1)
/** UM_ABORTED		�����ُ�I���ʒm
  * WPARAM: unsigned int ThreadID
  * LPARAM: int tag
  * destination: MainForm
  */

#define UM_AD4385_COMMAND		(AD85M_TOP + 2)
/** UM_AD4385_COMMAND	AD4385�R�}���h�ʒm
 *  WPARAM: AD4385Command command
 *  LPARAM: AD4385Params *params;
 */

/** AD4385 �X�e�[�^�X�^�C�v�񋓌^ **/
/** ��: AD4385.h���ɒ�`����Ă���E85Status�Ƃ͓����I�ɕʂł���
  * MainForm�Ƃ̃��b�Z�[�W�ʐM�ɗ��p�����
  */
enum AD4385Event{
	evCard,				/* �J�[�h�}��
						 *	PARAM: AD4385CardKeyInfo
						 */
	evCardReverse,		/* �J�[�h�t�}�� */
	evCardOut,			/* �J�[�h�������� */
	evPowerOn,			/* �p���[�I���i�Z���t�e�X�gOK�j */
	evPowerNg,			/* �p���[�I���i�Z���t�e�X�gNG�j */
	evPrinterAbnormal,	/* �󎚕s�� */
	evPaperExist,		/* ������ */
	evNoPaper,			/* ���Ȃ� */
	evPrintAck,			/* �󎚐���I�� */
	evKeiryo,			/* �v�ʊJ�n */
	evNm				/* ���̑��M�v��
						 *	PARAM: AD4385RequiredInfo
						 */
	};

/** AD4385 �J�[�h���L�[���\����(�C�x���g�p�����[�^) **/
struct AD4385CardKeyInfo{
	struct CardInfo{
		std::string str_id;
		int item1;
		int item2;
		int item3;
		int item4;
	} card;
	struct KeyInfo{
		int id;
		int item1;
		int item2;
		int item3;
		int item4;
	} key;
};

/** AD4385 ���̗v�����\����(�C�x���g�p�����[�^) **/
struct AD4385RequiredInfo{
	int item_no;
	int item_code;
	std::string reply;
};

/** AD4385 �R�}���h�^�C�v�񋓌^ **/
enum AD4385Command{
	cmRestart,		/* ���X�^�[�g�R�}���h */
	cmLamp,			/* �����v�w��R�}���h
				 *	PARAM: AD4385Lamp
				 */
	cmKey,			/* �L�[�{�[�h�ؑփR�}���h
				 *	PARAM: bool
				 */
	cmDisplay,		/* �f�B�X�v���C�ؑփR�}���h
				 *	PARAM: bool
				 */
	cmWeight,		/* �d�ʒl
				 *	PARAM: int(0�`9999999)
				 */
	cmRelay,		/* �����[�R�}���h
				 *	PARAM: AD4385Relay
				 */
	cmPrint,		/* �󎚃R�}���h
				 *	PARAM: Denpyou
				 */
				 
	cmPrint2,	 /* �󎚃R�}���h
					PARAM: Denpyou2
				 */
	cmPrintMoveDot,		/* �󎚃h�b�g�ړ��R�}���h
				 *	PARAM: int(0�`999)
				 */
	cmBeep,			/* BEEP�R�}���h
				 *	PARAM: int(0�`99)
				 */
};

/** AD4385 �����v�w����(�R�}���h�p�����[�^) **/
struct AD4385Lamp{
	AD4385Lamp(){}
	AD4385Lamp(bool i, bool c, bool e)
		: insert(i), complete(c), error(e) {}
	bool insert;
	bool complete;
	bool error;
};

/** AD4385 �����[�w����(�R�}���h�p�����[�^) **/
struct AD4385Relay{
	AD4385Relay(){}
	AD4385Relay(bool a, bool b)
		: channel_a(a), channel_b(b) {}
	bool channel_a;
	bool channel_b;
};

//////////////////////////////////////// �C���^�[�t�F�[�X

/** �x���ʒm�p�\���� **/
struct AD4385Warning{
	bool is_fatal;
	AnsiString message;
};

/** AD4385 ���\���� **/
struct AD4385Status{
	AD4385Event event;
	AD4385CardKeyInfo card_key_info;
	AD4385RequiredInfo *required_info;
};

/** AD4385 �����ݒ� **/
struct AD4385StartInfo{
	int port;
	std::string def;
	HWND owner;
	int tag;
	int *display_weight;
	AD4385Warning *warning;
	AD4385Status *status;
	unsigned int *thread_id;
};

typedef std::vector<std::string> PrintImage;

/** AD4385 �R�}���h�p�����[�^�Ǘ��\���� **/
struct AD4385Params{
	AD4385Lamp lamp;
	bool key;
	bool display;
	int weight;
	AD4385Relay relay;
	int dot_size;
	int beep_len;
	PrintImage image;
};

#endif //_CommonH_
