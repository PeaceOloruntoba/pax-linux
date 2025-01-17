
/*********************************************************************************
NAME
    global.h - 

DESCRIPTION


REFERENCE

MODIFICATION SHEET:
    MODIFIED   (YYYY.MM.DD)
    shengjx     2006.09.12      - created
*********************************************************************************/

/*********************************************************************************
1.01.0000 init Kim.L
1.01.0001 fixed bugs 488-498, 502-504
1.01.0002 fixed bugs 505-508
1.01.0003 modified some details, fix bugs 511-513
1.01.0004 added BLUETOOTH & WIFI
1.01.0005 added Arabic
1.01.0006 fixed a bug of information page
1.01.0007 fixed bug
1.01.0008 fixed bug
1.01.0009 fixed bugs
1.02.0001 sync with Prolin version 1.03.0001 on CTLS feature
*********************************************************************************/

/*App*/
/*********************************************************************************

*********************************************************************************/


/*********************************************************************************
Warning
This source files are for template use only.
If you want to use it as a proto-type of a specific project,
do not directly modify on it.
*********************************************************************************/


#ifndef _GLOBAL_H
#define _GLOBAL_H

/*********************************************************************************
Please check below macro definition before compile
*********************************************************************************/
// Removed all Pxx by Kim_LinHB 2014-4-4
//#define _Sxx_
//#define _SP30_
//#define _Dxxx_	//add D2xx Serial hdadd
#define _Sxxx_	// Added by Kim_LinHB 2014-4-4

// Added by Kim_LinHB 2014-08-14 v1.01.0003
#ifdef _Dxxx_
//#define _MIPS_
#endif

#ifdef _Sxx_
#define _TERMTYPE_	"_Sxx" 
#elif defined(_SP30_)
#define _TERMTYPE_	"_SP30"
#elif defined(_Dxxx_)
	#ifdef _MIPS_
	#define _TERMTYPE_	"_MIPS"
	#else
	#define _TERMTYPE_	"_Dxxx"
	#endif
#elif defined(_Sxxx_)
#define _TERMTYPE_	"_Sxxx"
#endif
//Add End




/*********************************************************************************
Set to correct macro before compile
*********************************************************************************/
//#define APP_MANAGER_VER	// When build this app as manager, should enable this macro
#define ALLOW_NO_TMS		// allow init default, without TMS. but TMS still available
#define ENABLE_EMV			// Link EMV lib into the application.
#define EMV_TEST_VERSION	// use hard coded emv parameters for EMV test. Valid only when ENABLE_EMV defined
//#define APP_DEBUG			// debug mode
//#define FUN2_READ_ONLY	// Allow operator to modify FUNCTION 2.
#define ENABLE_CONTLESS   // Contactless card support (CLSS)

/*********************************************************************************
Application attribute
*********************************************************************************/
#define APP_NAME		"XPRESSPOS"
#define EDCAPP_AID		"PGENMER01"
// Modified by Kim_LinHB 2014-4-4
#define EDC_VER_PUB		    "2.1"			// Public version number
//#define EDC_VER_INTERN	    "2.0"		// Extend version number. should be same as EDC_VER_INTERN's heading.
// Added by Kim 20150120
//#define EDC_BASE_VER_INTERN     "2.00.00"   // EDC version, please do not modify

/*********************************************************************************
Features of specific area
*********************************************************************************/

#define AREA_HK
//#define AREA_Arabia		// support Arabia

/*********************************************************************************
EMV terminal capability
*********************************************************************************/
#define EMV_CAPABILITY	"\xE0\xF8\xC8"
//	9F33 - Terminal Capabilities Length = 03
//		Byte 1 Bit 8 Manual key entry 
//		Byte 1 Bit 7 Magnetic stripe 
//		Byte 1 Bit 6 IC with contacts 
//		Byte 2 Bit 8 Plaintext PIN for offline ICC verification 
//		Byte 2 Bit 7 Enciphered PIN for online verification 
//		Byte 2 Bit 6 Signature (paper) 
//		Byte 2 Bit 5 Enciphered PIN for offline ICC verification 
//		Byte 2 Bit 4 No CVM Required 
//		Byte 3 Bit 8 Offline static data authentication 
//		Byte 3 Bit 7 Offline dynamic data authentication 
//		Byte 3 Bit 6 Card capture 
//		Byte 3 Bit 4 Combined DDA/AC Generation 

/*********************************************************************************
Below macro definitions are related to machine/application feature.
DO NOT modify them unless machine feature is changed.
Warning: DO NOT manually enable/disable below macros. they're determined automatically.
*********************************************************************************/

// for setting Byte aligned in GCC
#if defined(_WIN32) || defined(_WINDOWS)
	#define PACK_STRUCT
#else
	#define PACK_STRUCT		__attribute__((packed))
#endif

#include <String.h>
#include "Stdarg.h"

// Please add your customized header files here.
#include "posapi.h"
#include "appLib.h"

#ifdef ENABLE_EMV
#include "emvlib.h"		// Recommend to link to external file, not copying it into source folder.
						// Use project--settings--c/c++--category=preprocessor--additional include directories
#endif

#ifdef _MIPS_
#include "bluetooth_MIPS.h"
#endif
#include "GUI.h"
#include "commlib.h"
#include "util.h"
#include "pack8583.h"
#include "st8583.h"
#include "initpos.h"
#include "setup.h"
#include "fileoper.h"
#include "tranproc.h"
#ifdef ENABLE_CONTLESS
#include "ClssProc.h"
#endif
#include "checkopt.h"
#include "commproc.h"
#include "print.h"
#include "pedpinpad.h"
#include "cpinpad.h"
#include "MultiApp.h"
#include "lng.h"
#include "MultiApp.h"
#include "mlogo.h"

#ifdef AREA_Arabia
#include "arabic_farsi_api.h"
#endif

#ifdef ENABLE_EMV
#include "emvproc.h"
#include "emvtest.h"
#endif

#include "CL_common.h"
#ifdef ENABLE_CONTLESS
#include "CLEntryApi.h"
#include "ClssApi_WAVE.h"
#include "ClssApi_MC.h"
#include "ClssApi_PBOC.h"
#include "ClssApi_AE.h"			//added by kevinliu 2015/10/16
#include "ClssApi_JCB.h"
#include "ClssApi_DPAS.h"		//added by Gillian 2015/12/1
#include "ProcTrans.h"
#endif

#include "WlExt.h"
#include "HttpApi.h"

#include "SxxCom.h" // Modified by Kim_LinHB 2014-4-4 always need it
#include "sslapi.h"
#include "SxxComSSL.h"

#include "debug.h"
#include "xDefs.h"
#include "Logger.h"
#include "xIsoDef.h"
#include "stdbool.h"

#define LEN_TCP_PACKAGE 2
#define LEN_MSG_HEADER 5
#define LEN_WORK_KEY	16
// Below IDs should be customized according to your project
#define MASTER_KEY_ID	    1
#define DEF_PIN_KEY_ID	    1		// default PIN key ID (if not assign)
#define GENERAL_MKEY_ID     2       // Used for getting EMV offline plain PIN
#define GENERAL_WKEY_ID     2       // Used for getting EMV offline plain PIN
#define DEF_DATA_KEY_ID     3
#define MAC_KEY_ID		    10

// Card slot number for customer.
#define ICC_USER		0

#define MAX_EVENTBUF_SIZE		4096

// Password type
enum {PWD_BANK, PWD_TERM, PWD_MERCHANT, PWD_VOID, PWD_REFUND, PWD_ADJUST, PWD_SETTLE, PWD_MAX};

// Permission Level
// for example, if editing a parameter require PM_MEDIUM, then when ucPermission==PM_LOW, user cannot modify it.
enum {PM_LOW, PM_MEDIUM, PM_HIGH, PM_DISABLE};

// PED type
enum {PED_INT_PCI, PED_EXT_PP, PED_EXT_PCI};

// Machine type defined in GetTermInfo().

#define _TERMINAL_S80_		7  
#define _TERMINAL_SP30_		8  
#define _TERMINAL_S60_		9
#define _TERMINAL_S90_		10
#define _TERMINAL_D200_		15
#define _TERMINAL_D210_		16
#define _TERMINAL_S300_		20
#define _TERMINAL_S800_		21
#define _TERMINAL_S900_		22
#define _TERMINAL_S500_		24		//added by Kevin Liu 20160613 bug847

#define BT_RET_ERROR_CONNECTED -5
#define MAX_WiFiApp				20


// event of swiping/inserting card
#define NO_SWIPE_INSERT		0x00	// no such event
#define CARD_SWIPED			0x01	// swiped card
#define CARD_INSERTED		0x02	// inserted card
#define CARD_KEYIN			0x04	// enter card NO. manually
#define CARD_TAPPED			0x08	// Tap card

#define SKIP_DETECT_ICC		0x20	// skip detecting an event of inserting card // avoid removing card too fast[12/12/2006 Tommy]
#define FALLBACK_SWIPE		0x40	// swipe card(FALLBACK)
#define SKIP_CHECK_ICC		0x80	// skip checking service code

#define APPMSG_SYNC				11	// for sending messages from main application to a common application

#define EDC_ECR_MSG				1231
#define EDCAPP_LOADDOWNPARA		1232
#define EDCAPP_GETPARA			1233
#define EDCAPP_AUTOUPDATE		1235

#define EVENT_GET_NAME			0x2001
#define EVENT_GET_NAME_OK		0x2002

// limits for the system
#define MAX_PLAN 				24
#define MAX_ACQ					16
#define MAX_ISSUER				32
#define MAX_CARD				128
#define MAX_DESCRIPTOR			10
#define MAX_CARDBIN_NUM			800
#define MAX_CARDBIN_ISSUER		250
#define MAX_CARBIN_NAME_LEN		30
#define LEN_MAX_AD_DATA			4000
#define MAX_TRANLOG				400		// must <65535
#define MAX_ERR_LOG				10		// # of EMV error transactions, adjust as needed
#define MAX_ISSUER_CARD_RANGE	2		//added by Kevinliu 20160530

#define USER_OPER_TIMEOUT		60		// time out of UI

#define ACQ_ALL					0xFF	// all Acquirers
#define INV_ACQ_KEY				0xFF	// invalid acquirer key
#define INV_ISSUER_KEY			0xFF	// invalid issuer key

// RFU
#define ECR_NONE        0
#define ECR_BEGIN       1
#define ECR_SUCCEED     2
#define ECR_REJECT      3


// EDC options (enable to set on Protims)
#define EDC_DATE_FORMAT				0x0040
#define EDC_PRINT_TIME				0x0020
#define EDC_TIP_PROCESS				0x0004
#define EDC_NUM_PRINT_HIGH			0x0180
#define EDC_NUM_PRINT_LOW			0x0140
#define EDC_USE_PRINTER				0x0102
#define EDC_ENABLE_INSTALMENT		0X0280
#define EDC_AUTH_PREAUTH			0x0220
#define EDC_CASH_PROCESS			0x0210
#define EDC_ECR_ENABLE				0x0208
#define EDC_NOT_ADJUST_PWD			0x0320
#define EDC_NOT_MANUAL_PWD			0x0310
#define EDC_NOT_SETTLE_PWD			0x0308
#define EDC_NOT_REFUND_PWD			0x0304
#define EDC_NOT_VOID_PWD			0x0302
#define EDC_NOT_KEYBOARD_LOCKED		0x0301
#define EDC_SELECT_ACQ_FOR_CARD		0x0480
#define EDC_ENABLE_DCC				0x0440 
#define EDC_REFERRAL_DIAL			0x0410
#define EDC_LONG_SLIP				0x0408
#define EDC_AUTH_PAN_MASKING		0x0404
#define EDC_FREE_PRINT				0X0402

#define EDC_REFERRAL_DIAL_aaaa			EDC_REFERRAL_DIAL


// EDC extended options (disable to set on Protims, MUST be set on POS)
// ...

// issuer options(enable to set on Protims)
#define ISSUER_EN_ADJUST				0x0080
#define ISSUER_EN_DISCRIPTOR 			0x0040
#define ISSUER_EN_VOICE_REFERRAL		0x0020
#define ISSUER_EN_OFFLINE				0x0010
#define ISSUER_EN_EXPIRY				0x0008
#define ISSUER_EN_MANUAL				0x0004
#define ISSUER_EN_PIN					0x0002
#define ISSUER_EN_ACCOUNT_SELECTION		0x0001
#define ISSUER_NO_PREAUTH				0x0180
#define ISSUER_NO_REFUND				0x0140
#define ISSUER_CHECK_EXPIRY_OFFLINE		0x0110
#define ISSUER_CAPTURE_TXN				0x0108
#define ISSUER_EN_PRINT					0x0104
#define ISSUER_ROC_INPUT_REQ			0x0102
#define ISSUER_CHKPAN_MOD10				0x0101
#define ISSUER_CHKPAN_MOD11				0x0280
#define ISSUER_CHECK_EXPIRY				0x0210
#define ISSUER_AUTH_CODE				0x0208
#define ALLOW_EXTEND_PAY				0x0204
#define ISSUER_ADDTIONAL_DATA			0x0202
#define ISSUER_NO_VOID					0x0201
#define ISSUER_SECURITY_MANUL			0x0380
#define ISSUER_SECURITY_SWIPE			0x0340
#define ISSUER_MASK_EXPIRY				0x0302
#define ISSUER_EN_BALANCE				0x0301
#define ISSUER_EN_EMVPIN_BYPASS			ISSUER_EN_BALANCE	// or use other option instead, as long as it is not in used.

// acquirer options(enable to set on Protims)
#define ACQ_VISA_CHOICE						0x0080
#define ACQ_PRINT_AUDIT_TRAIL				0x0040
#define ACQ_EXPRESS_PAYMENT_PROMPT			0x0020
#define ACQ_DISABLE_BUSINESS_DATE			0x0010
#define ACQ_IGNORE_HOST_TIME				0x0008
#define ACQ_REQ_OPEN_SUSPEND_BATCH			0x0004
#define ACQ_CLEAR_BATCH						0x0002
#define ACQ_AMEX_SPECIFIC_FEATURE			0x0001
#define ACQ_PRINT_AUTH_CODE					0x0120
#define ACQ_DISABLE_TRICK_FEED				0x0110
#define ACQ_BLOCK_AUTH_FOR_OFFLINE			0x0108
#define ACQ_USE_TRACK3						0x0104
#define ACQ_NOT_PRINT_RRN					0x0102
#define ACQ_ADDTIONAL_PROMPT				0x0101
#define ACQ_CITYBANK_INSTALMENT_FEATURE		0x0240
#define ACQ_DBS_FEATURE						0x0220
#define ACQ_BOC_INSTALMENT_FEATURE			0x0210
#define ACQ_ONLINE_VOID						0x0208
#define ACQ_ONLINE_REFUND					0x0204
#define ACQ_AIR_TICKET						0x0201
#define ACQ_EMV_FEATURE						0x0202
#define ACQ_ASK_CVV2						0x0380

// Support right-to-left language
#define LANGCONFIG glSysParam.stEdcInfo.stLangCfg.szDispName


// transaction config
typedef struct _tagTRAN_CONFIG
{
	uchar	szLabel[16+1];		// label of transaction type
	uchar	szTxMsgID[4+1];	// message type of transaction message
	uchar	szProcCode[6+1];	// processing code

#define PRN_RECEIPT			0x80
#define WRT_RECORD			0x40
#define IN_SALE_TOTAL		0x20
#define IN_REFUND_TOTAL	0x10
#define VOID_ALLOW			0x08
#define NEED_REVERSAL		0x04
#define ACT_INC_TRACE		0x02
#define NO_ACT				0x00
	uchar	ucTranAct;		// features requested
}TRAN_CONFIG;


typedef struct _tagHOST_ERR_MSG
{
	uchar	szRspCode[2+1];		// response code from host
	uchar	szMsg[40+1];		    // Modified by Kim_LinHB 2014-6-7 from 16 to 40 v1.01.0000
}HOST_ERR_MSG;

typedef struct _tagTERM_ERR_MSG
{
	int		iErrCode;
	uchar	szMsg[16+1];
}TERM_ERR_MSG;

// transaction log
#define	MAX_GET_DESC		4
typedef struct _tagTRAN_LOG
{
	short	ucTranType;					    // current transaction type
	uchar	ucOrgTranType;				// original transaction type
	uchar   ucAccountType;
	uchar	szPan[19+1];				        // card NO.
	uchar	szExpDate[4+1];				// expiry date
	uchar	szAmount[12+1];				// transaction amount
	uchar	szInitialAmount[12+1];		// initial transaction amount
	uchar	szOtherAmount[12+1];			// tip amount
	uchar	szOrgAmount[12+1];			// original transaction amount
	uchar	szFrnAmount[12+1];			// foreign currency amount
	uchar	szDateTime[14+1];			// YYYYMMDDhhmmss
	uchar	szRRN[13+1];				    // RRN, system ref. no
	uchar	ucAcqKey;					        // acquirer id
	uchar	ucIssuerKey;				        // issuer id
//	uchar	szProcCode[6+1];			    // field 3 processing code
	uchar	szCondCode[2+1];			// field 25
	uchar	ucDescTotal;				        // total # of Descriptor
	uchar	szDescriptor[MAX_GET_DESC+1];
	uchar	szRspCode[2+1];				// response code
	uchar	szResponseReason[50];
	uchar	szHolderName[26+1];
	uchar	szAddlPrompt[20+1];
	uchar	szAuthCode[6+1];
	uchar	ucInstalment;
	CURRENCY_CONFIG	stTranCurrency;
	CURRENCY_CONFIG	stHolderCurrency;

	// EMV related data
	uchar	bPanSeqOK;					// TRUE: PAN Seq read OK
	uchar	ucPanSeqNo;
	uchar	sAppCrypto[8];
	uchar	sTVR[5];
	uchar	sTSI[2];
	uchar	sATC[2];
	uchar	szAppLabel[16+1];
	uchar	szAppPreferName[16+1];
	uchar	ucAidLen;
	uchar	sAID[16];
	uchar	szOriginalForwdInstCode[11 + 1];
	ushort	uiIccDataLen;
	uchar	sIccData[LEN_ICC_DATA];
	ushort	uiField56Len;
	uchar	sField56[LEN_ICC_DATA2];
	uchar szEchoField59[255+1];
//	uchar	szEcrRef[10+1];

#define MODE_NO_INPUT			    0x0000
#define MODE_MANUAL_INPUT		0x0001	// enter card NO. manually
#define MODE_SWIPE_INPUT		    0x0002	// swipe a normal magnetic card
#define MODE_CHIP_INPUT			    0x0004	// insert an EMV card
#define MODE_FALLBACK_SWIPE		0x0008	// swipe an EMV card
#define MODE_PIN_INPUT			    0x0010	// online PIN input
#define MODE_OFF_PIN			        0x0020	// for AMEX
#define MODE_SECURITYCODE		0x0040	// CVV/4DBC entered
#define MODE_CONTACTLESS		    0x0080	// contactless card
#define MODE_FALLBACK_MANUAL	0x0100	// no need for now
	ushort	uiEntryMode;				// input mode, for calculating field 22

	ulong	ulInvoiceNo;			    // invoice NO.
	ulong	ulSTAN;					// S.T.A.N.
	ulong	ulOrgSTAN;				// original S.T.A.N. 

	uchar	szOrgDateTime[14 + 1];			//Original Date YYYYMMDDhhmmss
	uchar	szOrgRRN[13 + 1];				    // RRN, system ref. no

#define TS_OK			            0x00000000		// txn accepted
#define TS_NOSEND		        0x00000001		// txn not sent to host
#define TS_ADJ			            0x00000002		// txn adjusted
#define TS_REVD			        0x00000004		// txn reversed (reserved)
#define TS_VOID			        0x00000008		// txn voided
#define TS_CHANGE_APPV	0x00000010		// replace Approval Code, reserved
#define TS_FLOOR_LIMIT	    0x00000020		// transaction amount is lower than Floor Limit
#define TS_OFFLINE_SEND	0x00000040		//
#define TS_NOT_UPLOAD	    0x00000080		// don't need to upload(controlled by NOSEND/ADJ flag)
#define TS_NEED_TC		    0x00000100		// need to upload TCTC
#define TS_ON_LINE            0x00000200
#define TS_CHKSIGNED       0x00000400
#define TS_PRNERR             0x00000800
#define TS_ALL_LOG		       0xFFFFFFFF
	uint    	uiStatus;				// transaction status bug 801 802
    uchar   szLastCustomerPhoneNo[50];
    uchar    szSignPath[16];
	uchar notified;
	uchar CVMResult[12];
}TRAN_LOG;


// transaction processing information, unnecessary to store into file system.
typedef struct _tagSYS_PROC_INFO
{
	TRAN_LOG	stTranLog;
	uchar		szTrack1[79+1];
	uchar		szTrack2[40+1];
	uchar		szTrack3[107+1];

	// need more data elements, please according to transaction processing requirements
	uchar		bIsFallBack;
#define ST_OFFLINE		0
#define ST_ONLINE_FAIL	1
#define ST_ONLINE_APPV	2
	uchar		ucOnlineStatus;			// extension of "bIsOnlineTxn"
	uchar		bIsFirstGAC;			// is it the first Generate AC
	uchar		ucEcrCtrl;				// ECR flag(RFU)
	uchar		bExpiryError;			// TRUE: card expiry date is wrong
	uchar		szSecurityCode[4+1];	// CVV2/4DBC
//	uchar		bPinEnter;				// did the PIN entered
	uchar		sPinBlock[8];			// PIN block (RFU)
	uchar		bAutoDownFlag;
	uchar		szSettleMsg[30+1];		// settlement messages(for display/receipt etc.)
	ushort		uiRecNo;				// original transaction record id(for VOID)
	int			iFallbackErrCode;		// reason of causing fallback(for AMEX)
	STISO8583	stSendPack;				// backup of sending message 
	uchar		sResponseIcc[255];
	int			uiResponseIccLen;
	uchar		szAdditionalAmtF54[120 + 1];
	char szPaymentInformation[999 + 1];
}SYS_PROC_INFO;

// reverse data
typedef struct _tagREVERSAL_INFO
{
	uchar			bNeedReversal;		// TRUE: need to be reversed, FALSE: don't need to be reversed
	STISO8583		stRevPack;			// original request package
	ushort			uiEntryMode;		// entry mode
}REVERSAL_INFO;

// communication data
#define	LEN_MAX_COMM_DATA	1024
typedef struct _tagCOMM_DATA
{
	ushort		uiLength;
	uchar		sContent[LEN_MAX_COMM_DATA+LEN_MSG_HEADER]; //data + header
}COMM_DATA;

// transactions summary record
typedef struct _tagTOTAL_INFO
{
	ushort		uiSaleCnt;
	ushort		uiTipCnt;
	ushort		uiRefundCnt;
	ushort		uiVoidSaleCnt;
	ushort		uiVoidRefundCnt;

	uchar		szSaleAmt[12+1];	// base amount + tip amount
	uchar		szTipAmt[12+1];
	uchar		szRefundAmt[12+1];
	uchar		szVoidSaleAmt[12+1];
	uchar		szVoidRefundAmt[12+1];
}TOTAL_INFO;

// reprint settlement information
typedef struct _tagREPRN_STL_INFO
{
	uchar		bValid[MAX_ACQ];
	uchar		szSettleMsg[MAX_ACQ][30];
	ulong		ulBatchNo[MAX_ACQ];
	ulong		ulSOC[MAX_ACQ];
	TOTAL_INFO	stAcqTotal[MAX_ACQ];
	TOTAL_INFO	stIssTotal[MAX_ACQ][MAX_ISSUER];
}REPRN_STL_INFO;

typedef struct _tagWRITE_INFO
{
#define SAVE_NONEED		0
#define SAVE_NEW		1
#define SAVE_UPDATE		2
	uchar		bNeedSave;		// TRUE: should save stTranLog
	uchar		ucAcqIndex;		// acquirer index, must < 255
	ushort		uiRecNo;		// record # of stTranLog
	TRAN_LOG	stTranLog;		// txn information to save
}WRITE_INFO;

// control config, it is stored in file system, and it may be modified during each transaction.
enum {S_RESET, S_SET, S_LOAD, S_INS, S_OUT, S_USE ,S_PENDING, S_CLR_LOG};
typedef struct _tagSYS_CONTROL
{
	ulong			ulSTAN;			// current terminal S.T.A.N.
	ulong			ulInvoiceNo;	// current invoice NO.
	ushort			uiLastRecNo;	// record index NO. of the last transaction
	ushort			uiErrLogNo;		// EMV error record index NO.
	WRITE_INFO		stWriteInfo;	// information for saving txn log

#define LEN_SYSCTRL_BASE	((int)OFFSET(SYS_CONTROL, stRevInfo))
	REVERSAL_INFO	stRevInfo[MAX_ACQ];		// reverse information

#define LEN_SYSCTRL_NORMAL	((int)OFFSET(SYS_CONTROL, stRePrnStlInfo))
	REPRN_STL_INFO	stRePrnStlInfo;

}SYS_CONTROL;


typedef struct PosParams {
	char terminalId[8 + 1];
	char merchantId[15 + 1];
	char merchantName[50 + 1];
	char merchantLocation[50 + 1];
	char slipHeader[50 + 1];
	char slipFooter[50 + 1];
	char username[30];
	char password[30];
	char institutionCode[30];
	char consultantCode[20 + 1];
	char operatorPin[10 + 1];
	char supervisorPin[10 + 1];
	char adminPass[10 + 1];
	CURRENCY_CONFIG currency;
	LANG_CONFIG	stLangCfg;

	IP_ADDR tmsIp;
	char tmsUrl[100];
	bool tmsProtocolFlag;


	//IP_ADDR switchIp;
	char switchHostName[50 + 1];
	char hostZMK[ASCII_KEY_SIZE + 1];
	char hostSessionKey[ASCII_KEY_SIZE + 1];
	NibssTerminalParameter nibssParams;
	unsigned short requestTimeOutSec;
	unsigned short callHomeTimeMinutes;
	char approvedReceiptCount;
	char declinedReceiptCount;

	unsigned long sequenceNo;
	unsigned long batchNo;
	unsigned long tranRecordCount;


#define _comPSTNPara	commConfig.stPSTNPara
#define _comModemPara	commConfig.stPSTNPara.stPara
#define _comRS232Para	commConfig.stRS232Para
#define _comTcpIpPara	commConfig.stTcpIpPara
#define _comWirlessPara	commConfig.stWirlessPara
#define _comWifiPara		commConfig.stWifiPara			// hdadd
#define _comBlueToothPara	commConfig.stBlueToothPara	// hdadd
	COMM_CONFIG commConfig;

	uchar	ucPedMode;				// Current using PED (SxxPED/PP/ExtSxxPED)
	uchar	ucIsPrepped;

	//PayAttitude Cofing
	IP_ADDR payAttitudeIp;
	char payAttitudeZmk[32 + 1];
	char payAttitudeSessionKey[32 + 1];
	bool payAttitudeProtocolFlag;
	bool isPayAttitudeEnabled;
	bool isAccountSelectionEnabled;
} PosParams;


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern PosParams		glPosParams;
//extern SYS_PARAM		glSysParam, glSysParamBak;		// sys config parameters
extern SYS_CONTROL		glSysCtrl;		// sys control parameters
extern SYS_PROC_INFO	glProcInfo;		// transaction processing information

extern COMM_DATA		glSendData, glRecvData;		// communication data
extern STISO8583		glSendPack;		// transaction sending package
extern STISO8583		glRecvPack;		// transaction receiving package 

extern COMM_CONFIG		glCommCfg;		// current communication config

#ifdef ENABLE_EMV
extern EMV_PARAM		glEmvParam;
extern EMV_STATUS		glEmvStatus;
#endif

extern const LANG_CONFIG glLangList[];
extern const CURRENCY_CONFIG glCurrency[];
extern TRAN_CONFIG		glTranConfig[];

extern HOST_ERR_MSG		glHostErrMsg[];
extern TERM_ERR_MSG		glTermErrMsg[];
// Added by Kim_LinHB 2014-4-4
#ifdef AREA_Arabia
extern unsigned int gl_AR_FONT_ID;
#endif

// Added by Kim_LinHB 2014-5-31
extern GUI_TEXT_ATTR gl_stTitleAttr;
extern GUI_TEXT_ATTR gl_stLeftAttr;
extern GUI_TEXT_ATTR gl_stCenterAttr;
extern GUI_TEXT_ATTR gl_stCenterAttrAlt;
extern GUI_TEXT_ATTR gl_stRightAttr;
extern unsigned char gl_szCurrTitle[50];
// Add End

// Added by Kim_LinHB 2014-8-8 v1.01.0002
extern ST_FONT gl_Font_Def[3];

extern char *strstr(const char *, const char *);
//extern int vsprintf(char *buffer, const char *format, va_list argptr);

// Added by Kim_LinHB 2014-08-22 v1.01.0004
extern int  SetBTParam(ST_BT_CONFIG *pstParam);
extern void SyncBTParam(ST_BT_CONFIG *pstDst, const ST_BT_CONFIG *pstSrc);
extern unsigned char IsBtOpened(void);

extern int GetIpLocalWifiSettings(void *pstParam);
extern int SetWiFiApp(void* pstParam);
extern void SyncWifiParam(void *pstDst, const void *pstSrc);
extern void DispWifiErrorMsg( int Ret);

extern void resetTransactionData();
extern int startEmvTransaction(ushort ucEntryMode, int ucTranType, char amount[12 + 1], char otherAmount[12 + 1]);
extern void showCommError(int ret);
extern void* notificationHandler(void* arg);
extern void resetCallHomeTimer();

//extern int readDevice(Device* device);
//extern int saveDevice(Device* device);


enum {
	CUSTOMER_COPY, MERCHANT_COPY, EOD_FULL_COPY, EOD_TOTAL_COPY, CLOSE_BATCH_COPY,
};


#define logd LOG_PRINTF
#define TIMER_CALLHOME      3
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif	// _GLOBAL_H

// end of file

