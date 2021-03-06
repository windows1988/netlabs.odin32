/* $Id: ole.h,v 1.6 2001-04-26 19:23:31 sandervl Exp $ */
/*
 *	ole.h	-	Declarations for OLESVR and OLECLI
 */

#ifndef __WINE_OLE_H
#define __WINE_OLE_H

#include "wingdi.h" /* LOGPALETTE */

/* FIXME: we need to include wtypes.h mainly, it seems, because we need BSTR. 
 * Normally none of the APIs in ole.h depend on it. It is most likey that they should 
 * be moved to ole2.h (which includes objbase.h and thus wtypes.h) or some other 
 * OLE include
 */
#include "wtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* object types */
#define OT_LINK		1
#define OT_EMBEDDED	2
#define OT_STATIC	3

/* activate verbs */
#define OLEVERB_PRIMARY	0

typedef enum
{
    OLE_OK,
    OLE_WAIT_FOR_RELEASE,
    OLE_BUSY,
    OLE_ERROR_PROTECT_ONLY,
    OLE_ERROR_MEMORY,
    OLE_ERROR_STREAM,
    OLE_ERROR_STATIC,
    OLE_ERROR_BLANK,
    OLE_ERROR_DRAW,
    OLE_ERROR_METAFILE,
    OLE_ERROR_ABORT,
    OLE_ERROR_CLIPBOARD,
    OLE_ERROR_FORMAT,
    OLE_ERROR_OBJECT,
    OLE_ERROR_OPTION,
    OLE_ERROR_PROTOCOL,
    OLE_ERROR_ADDRESS,
    OLE_ERROR_NOT_EQUAL,
    OLE_ERROR_HANDLE,
    OLE_ERROR_GENERIC,
    OLE_ERROR_CLASS,
    OLE_ERROR_SYNTAX,
    OLE_ERROR_DATATYPE,
    OLE_ERROR_PALETTE,
    OLE_ERROR_NOT_LINK,
    OLE_ERROR_NOT_EMPTY,
    OLE_ERROR_SIZE,
    OLE_ERROR_DRIVE,
    OLE_ERROR_NETWORK,
    OLE_ERROR_NAME,
    OLE_ERROR_TEMPLATE,
    OLE_ERROR_NEW,
    OLE_ERROR_EDIT,
    OLE_ERROR_OPEN,
    OLE_ERROR_NOT_OPEN,
    OLE_ERROR_LAUNCH,
    OLE_ERROR_COMM,
    OLE_ERROR_TERMINATE,
    OLE_ERROR_COMMAND,
    OLE_ERROR_SHOW,
    OLE_ERROR_DOVERB,
    OLE_ERROR_ADVISE_NATIVE,
    OLE_ERROR_ADVISE_PICT,
    OLE_ERROR_ADVISE_RENAME,
    OLE_ERROR_POKE_NATIVE,
    OLE_ERROR_REQUEST_NATIVE,
    OLE_ERROR_REQUEST_PICT,
    OLE_ERROR_SERVER_BLOCKED,
    OLE_ERROR_REGISTRATION,
    OLE_ERROR_ALREADY_REGISTERED,
    OLE_ERROR_TASK,
    OLE_ERROR_OUTOFDATE,
    OLE_ERROR_CANT_UPDATE_CLIENT,
    OLE_ERROR_UPDATE,
    OLE_ERROR_SETDATA_FORMAT,
    OLE_ERROR_STATIC_FROM_OTHER_OS,
    OLE_WARN_DELETE_DATA = 1000
} OLESTATUS;

typedef enum {
	OLE_SERVER_MULTI,
	OLE_SERVER_SINGLE
} OLE_SERVER_USE;

typedef enum {
	OLE_CHANGED,
	OLE_SAVED,
	OLE_CLOSED,
	OLE_RENAMED,
	OLE_QUERY_PAINT,
	OLE_RELEASE,
	OLE_QUERY_RETRY
} OLE_NOTIFICATION;

typedef enum {
	olerender_none,
	olerender_draw,
	olerender_format
} OLEOPT_RENDER;

typedef enum {
	oleupdate_always,
	oleupdate_onsave,
	oleupdate_oncall,
	oleupdate_onclose
} OLEOPT_UPDATE;

typedef	LONG	LHSERVER;
typedef LONG	LHSERVERDOC;
typedef LONG	LHCLIENTDOC;
typedef LONG	OLECLIPFORMAT;/* dunno about this type, please change/add */
typedef OLEOPT_UPDATE*	LPOLEOPT_UPDATE;

typedef enum {
	OLE_NONE,	/* none */
	OLE_DELETE,	/* delete object */
	OLE_LNKPASTE,	/* link paste */
	OLE_EMBPASTE,	/* paste(and update) */
	OLE_SHOW,
	OLE_RUN,
	OLE_ACTIVATE,
	OLE_UPDATE,
	OLE_CLOSE,
	OLE_RECONNECT,
	OLE_SETUPDATEOPTIONS,
	OLE_SERVERRUNLAUNCH,	/* unlaunch (terminate?) server */
	OLE_LOADFROMSTREAM,	/* (auto reconnect) */
	OLE_SETDATA,		/* OleSetData */
	OLE_REQUESTDATA,	/* OleRequestData */
	OLE_OTHER,
	OLE_CREATE,
	OLE_CREATEFROMTEMPLATE,
	OLE_CREATELINKFROMFILE,
	OLE_COPYFROMLNK,
	OLE_CREATREFROMFILE,
	OLE_CREATEINVISIBLE
} OLE_RELEASE_METHOD;

typedef struct _OLETARGETDEVICE {
	UINT16	otdDeviceNameOffset;
	UINT16	otdDriverNameOffset;
	UINT16	otdPortNameOffset;
	UINT16	otdExtDevmodeOffset;
	UINT16	otdExtDevmodeSize;
	UINT16	otdEnvironmentOffset;
	UINT16	otdEnvironmentSize;
	BYTE	otdData[1];
	/* ... */
} OLETARGETDEVICE;
typedef struct _OLESTREAM* LPOLESTREAM;
typedef struct _OLESTREAMVTBL {
	DWORD	(* CALLBACK Get)(LPOLESTREAM,LPSTR,DWORD);
	DWORD	(* CALLBACK Put)(LPOLESTREAM,LPSTR,DWORD);
} OLESTREAMVTBL;
typedef OLESTREAMVTBL*	LPOLESTREAMVTBL;
typedef struct _OLESTREAM {
	LPOLESTREAMVTBL	lpstbl;
} OLESTREAM;
typedef struct _OLESERVERDOC*	LPOLESERVERDOC;
typedef struct _OLEOBJECT*    LPOLEOBJECT;
typedef struct _OLECLIENT*    LPOLECLIENT;
typedef struct _OLESERVERDOCVTBL {
	OLESTATUS	(* CALLBACK Save)(LPOLESERVERDOC);
	OLESTATUS	(* CALLBACK Close)(LPOLESERVERDOC);
	OLESTATUS	(* CALLBACK SetHostNames)(LPOLESERVERDOC,LPCOLESTR16,LPCOLESTR16);
	OLESTATUS	(* CALLBACK SetDocDimensions)(LPOLESERVERDOC,LPRECT16);
#ifdef __WINE__
/* GetObject is a WINELIB_NAME macro so it cannot be used in Wine itself */
	OLESTATUS	(* CALLBACK pGetObject)(LPOLESERVERDOC,LPCOLESTR16,LPOLEOBJECT*,LPOLECLIENT);
#else
	OLESTATUS	(* CALLBACK GetObject)(LPOLESERVERDOC,LPCOLESTR16,LPOLEOBJECT*,LPOLECLIENT);
#endif
	OLESTATUS	(* CALLBACK Release)(LPOLESERVERDOC);
	OLESTATUS	(* CALLBACK SetColorScheme)(LPOLESERVERDOC,LPLOGPALETTE);
	OLESTATUS	(* CALLBACK Execute)(LPOLESERVERDOC,HGLOBAL16);
} OLESERVERDOCVTBL;
typedef OLESERVERDOCVTBL*	LPOLESERVERDOCVTBL;
typedef struct _OLESERVERDOC {
	LPOLESERVERDOCVTBL	lpvtbl;
	/* server provided state info */
} OLESERVERDOC;

typedef struct _OLESERVER*	LPOLESERVER;
typedef struct _OLESERVERVTBL {
	OLESTATUS	(* CALLBACK Open)(LPOLESERVER,LHSERVERDOC,LPCOLESTR16,LPOLESERVERDOC *);
	OLESTATUS	(* CALLBACK Create)(LPOLESERVER,LHSERVERDOC,LPCOLESTR16,LPCOLESTR16,LPOLESERVERDOC*);
	OLESTATUS	(* CALLBACK CreateFromTemplate)(LPOLESERVER,LHSERVERDOC,LPCOLESTR16,LPCOLESTR16,LPCOLESTR16,LPOLESERVERDOC *);
	OLESTATUS	(* CALLBACK Edit)(LPOLESERVER,LHSERVERDOC,LPCOLESTR16,LPCOLESTR16,LPOLESERVERDOC *);
	OLESTATUS	(* CALLBACK Exit)(LPOLESERVER);
	OLESTATUS	(* CALLBACK Release)(LPOLESERVER); 
	OLESTATUS	(* CALLBACK Execute)(LPOLESERVER); 
} OLESERVERVTBL; 
typedef OLESERVERVTBL	*LPOLESERVERVTBL;
typedef struct _OLESERVER {
	LPOLESERVERVTBL	lpvtbl;
	/* server specific data */
} OLESERVER;
typedef struct _OLECLIENTVTBL {
	int (* CALLBACK CallBack)(LPOLECLIENT,OLE_NOTIFICATION,LPOLEOBJECT);
} OLECLIENTVTBL;
typedef OLECLIENTVTBL	*LPOLECLIENTVTBL;

typedef struct _OLECLIENT {
	LPOLECLIENTVTBL	lpvtbl;
	/* client data... */
} OLECLIENT;

typedef struct _OLEOBJECTVTBL {
        void *  	(* CALLBACK QueryProtocol)(LPOLEOBJECT,LPCOLESTR16);
	OLESTATUS	(* CALLBACK Release)(LPOLEOBJECT);
	OLESTATUS	(* CALLBACK Show)(LPOLEOBJECT,BOOL16);
	OLESTATUS	(* CALLBACK DoVerb)(LPOLEOBJECT,UINT16,BOOL16,BOOL16);
	OLESTATUS	(* CALLBACK GetData)(LPOLEOBJECT,OLECLIPFORMAT,HANDLE16 *);
	OLESTATUS	(* CALLBACK SetData)(LPOLEOBJECT,OLECLIPFORMAT,HANDLE16);
	OLESTATUS	(* CALLBACK SetTargetDevice)(LPOLEOBJECT,HGLOBAL16);
	OLESTATUS	(* CALLBACK SetBounds)(LPOLEOBJECT,LPRECT16);
	OLESTATUS	(* CALLBACK EnumFormats)(LPOLEOBJECT,OLECLIPFORMAT);
	OLESTATUS	(* CALLBACK SetColorScheme)(LPOLEOBJECT,LPLOGPALETTE);
	OLESTATUS	(* CALLBACK Delete)(LPOLEOBJECT);
	OLESTATUS	(* CALLBACK SetHostNames)(LPOLEOBJECT,LPCOLESTR16,LPCOLESTR16);
	OLESTATUS	(* CALLBACK SaveToStream)(LPOLEOBJECT,LPOLESTREAM);
	OLESTATUS	(* CALLBACK Clone)(LPOLEOBJECT,LPOLECLIENT,LHCLIENTDOC,LPCOLESTR16,LPOLEOBJECT *);
	OLESTATUS	(* CALLBACK CopyFromLink)(LPOLEOBJECT,LPOLECLIENT,LHCLIENTDOC,LPCOLESTR16,LPOLEOBJECT *);
	OLESTATUS	(* CALLBACK Equal)(LPOLEOBJECT,LPOLEOBJECT);
	OLESTATUS	(* CALLBACK CopyToClipBoard)(LPOLEOBJECT);
	OLESTATUS	(* CALLBACK Draw)(LPOLEOBJECT,HDC16,LPRECT16,LPRECT16,HDC16);
	OLESTATUS	(* CALLBACK Activate)(LPOLEOBJECT,UINT16,BOOL16,BOOL16,HWND16,LPRECT16);
	OLESTATUS	(* CALLBACK Execute)(LPOLEOBJECT,HGLOBAL16,UINT16);
	OLESTATUS	(* CALLBACK Close)(LPOLEOBJECT);
	OLESTATUS	(* CALLBACK Update)(LPOLEOBJECT);
	OLESTATUS	(* CALLBACK Reconnect)(LPOLEOBJECT);
	OLESTATUS	(* CALLBACK ObjectConvert)(LPOLEOBJECT,LPCOLESTR16,LPOLECLIENT,LHCLIENTDOC,LPCOLESTR16,LPOLEOBJECT*);
	OLESTATUS	(* CALLBACK GetLinkUpdateOptions)(LPOLEOBJECT,LPOLEOPT_UPDATE);
	OLESTATUS	(* CALLBACK SetLinkUpdateOptions)(LPOLEOBJECT,OLEOPT_UPDATE);
	OLESTATUS	(* CALLBACK Rename)(LPOLEOBJECT,LPCOLESTR16);
	OLESTATUS	(* CALLBACK QueryName)(LPOLEOBJECT,LPSTR,LPUINT16);
	OLESTATUS	(* CALLBACK QueryType)(LPOLEOBJECT,LPLONG);
	OLESTATUS	(* CALLBACK QueryBounds)(LPOLEOBJECT,LPRECT16);
	OLESTATUS	(* CALLBACK QuerySize)(LPOLEOBJECT,LPDWORD);
	OLESTATUS	(* CALLBACK QueryOpen)(LPOLEOBJECT);
	OLESTATUS	(* CALLBACK QueryOutOfDate)(LPOLEOBJECT);
	OLESTATUS	(* CALLBACK QueryReleaseStatus)(LPOLEOBJECT);
	OLESTATUS	(* CALLBACK QueryReleaseError)(LPOLEOBJECT);
	OLE_RELEASE_METHOD (* CALLBACK QueryReleaseMethod)(LPOLEOBJECT);
	OLESTATUS	(* CALLBACK RequestData)(LPOLEOBJECT,OLECLIPFORMAT);
	OLESTATUS	(* CALLBACK ObjectLong)(LPOLEOBJECT,UINT16,LPLONG);
} OLEOBJECTVTBL;
typedef OLEOBJECTVTBL*	LPOLEOBJECTVTBL;

typedef struct _OLEOBJECT {
	LPOLEOBJECTVTBL	lpvtbl;
} OLEOBJECT;


OLESTATUS WINAPI OleRegisterServer16(LPCSTR,LPOLESERVER,LHSERVER *,HINSTANCE16,OLE_SERVER_USE);
OLESTATUS WINAPI OleUnblockServer16(LHSERVER,BOOL16 *);
OLESTATUS WINAPI OleRegisterServerDoc16(LHSERVER,LPCSTR,LPOLESERVERDOC,LHSERVERDOC *);
OLESTATUS WINAPI OleRegisterClientDoc16(LPCSTR,LPCSTR,LONG,LHCLIENTDOC *);
OLESTATUS WINAPI OleRenameClientDoc16(LHCLIENTDOC,LPCSTR);
OLESTATUS WINAPI OleRevokeServerDoc16(LHSERVERDOC);
OLESTATUS WINAPI OleRevokeClientDoc16(LHCLIENTDOC);
OLESTATUS WINAPI OleRevokeServer16(LHSERVER);
OLESTATUS WINAPI OleRevertClientDoc16(LHCLIENTDOC hServerDoc);
OLESTATUS WINAPI OleEnumObjects16(LHCLIENTDOC hServerDoc, SEGPTR data);
OLESTATUS WINAPI OleCreateLinkFromClip16(
	LPCSTR name, LPOLECLIENT olecli, LHCLIENTDOC hclientdoc, LPCSTR xname,
	LPOLEOBJECT *lpoleob, UINT16 render, UINT16 clipformat);
OLESTATUS WINAPI OleQueryLinkFromClip16(LPCSTR name, UINT16 render, UINT16 clipformat);
OLESTATUS WINAPI OleQueryCreateFromClip16(LPCSTR name, UINT16 render, UINT16 clipformat);
OLESTATUS WINAPI OleQueryType16(LPOLEOBJECT oleob,  SEGPTR xlong);
OLESTATUS WINAPI OleCreateFromClip16(
	LPCSTR name, LPOLECLIENT olecli, LHCLIENTDOC hclientdoc, LPCSTR xname,
	LPOLEOBJECT *lpoleob, UINT16 render, UINT16 clipformat);

/* com functions */
void WINAPI CoFreeUnusedLibraries(void);
HINSTANCE WINAPI CoLoadLibrary(LPOLESTR lpszLibName, BOOL bAutoFree);
void WINAPI CoFreeUnusedLibraries(void);
void WINAPI CoFreeAllLibraries(void);

#ifdef __cplusplus
} /*extern*/
#endif

#endif  /* __WINE_OLE_H */
