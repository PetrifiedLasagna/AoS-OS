

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for wmsdatapath.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __wmsdatapath_h__
#define __wmsdatapath_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IWMSPacketStreamer_FWD_DEFINED__
#define __IWMSPacketStreamer_FWD_DEFINED__
typedef interface IWMSPacketStreamer IWMSPacketStreamer;
#endif 	/* __IWMSPacketStreamer_FWD_DEFINED__ */


#ifndef __IWMSPacketStreamerCallback_FWD_DEFINED__
#define __IWMSPacketStreamerCallback_FWD_DEFINED__
typedef interface IWMSPacketStreamerCallback IWMSPacketStreamerCallback;
#endif 	/* __IWMSPacketStreamerCallback_FWD_DEFINED__ */


#ifndef __IWMSPacketStreamDataContainer_FWD_DEFINED__
#define __IWMSPacketStreamDataContainer_FWD_DEFINED__
typedef interface IWMSPacketStreamDataContainer IWMSPacketStreamDataContainer;
#endif 	/* __IWMSPacketStreamDataContainer_FWD_DEFINED__ */


#ifndef __IWMSPushSource_FWD_DEFINED__
#define __IWMSPushSource_FWD_DEFINED__
typedef interface IWMSPushSource IWMSPushSource;
#endif 	/* __IWMSPushSource_FWD_DEFINED__ */


#ifndef __IWMSPushSourceCallback_FWD_DEFINED__
#define __IWMSPushSourceCallback_FWD_DEFINED__
typedef interface IWMSPushSourceCallback IWMSPushSourceCallback;
#endif 	/* __IWMSPushSourceCallback_FWD_DEFINED__ */


#ifndef __IWMSPushSink_FWD_DEFINED__
#define __IWMSPushSink_FWD_DEFINED__
typedef interface IWMSPushSink IWMSPushSink;
#endif 	/* __IWMSPushSink_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "nsscore.h"
#include "DataContainer.h"
#include "StreamDescription.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_wmsdatapath_0000 */
/* [local] */ 

//*****************************************************************************
//
// Microsoft Windows Media
// Copyright (C) Microsoft Corporation. All rights reserved.
//
// Automatically generated by Midl from wmsdatapath.idl
//
// DO NOT EDIT THIS FILE.
//
//*****************************************************************************






EXTERN_GUID( IID_IWMSPacketStreamer, 0x72527A81,0x1119,0x11d2,0x9E,0xEE,0x00,0x60,0x97,0xD2,0xD7,0xCF );
EXTERN_GUID( IID_IWMSPacketStreamerCallback, 0x72527A82,0x1119,0x11d2,0x9E,0xEE,0x00,0x60,0x97,0xD2,0xD7,0xCF );
EXTERN_GUID( IID_IWMSPushSource, 0x0B840593,0x115C,0x11d2,0x9E,0xEE,0x00,0x60,0x97,0xD2,0xD7,0xCF );
EXTERN_GUID( IID_IWMSPushSourceCallback, 0xead035e4, 0xbe4a, 0x4a7a, 0xbc, 0x19, 0x5b, 0xb, 0x9e, 0x9, 0xd7, 0x4c );
EXTERN_GUID( IID_IWMSPushSink, 0x0B840594,0x115C,0x11d2,0x9E,0xEE,0x00,0x60,0x97,0xD2,0xD7,0xCF );
EXTERN_GUID( IID_IWMSPacketStreamDataContainer, 0xb1b6039, 0x572c, 0x11d2, 0x9e, 0xff, 0x0, 0x60, 0x97, 0xd2, 0xd7, 0xcf );
typedef /* [public] */ 
enum WMS_SEEK_AND_PLAY_TYPE
    {	WMSPlayFromCurrentPosition	= 0,
	WMSSeekToIFrameAndPlay	= WMSPlayFromCurrentPosition + 1,
	WMSSeekToPositionAndPlay	= WMSSeekToIFrameAndPlay + 1
    } 	WMS_SEEK_AND_PLAY_TYPE;

#define WMS_SEEK_TO_IFRAME           0x0001


extern RPC_IF_HANDLE __MIDL_itf_wmsdatapath_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wmsdatapath_0000_v0_0_s_ifspec;

#ifndef __IWMSPacketStreamer_INTERFACE_DEFINED__
#define __IWMSPacketStreamer_INTERFACE_DEFINED__

/* interface IWMSPacketStreamer */
/* [helpstring][version][uuid][unique][object] */ 


EXTERN_C const IID IID_IWMSPacketStreamer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("72527A81-1119-11d2-9EEE-006097D2D7CF")
    IWMSPacketStreamer : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetStreamInfo( 
            /* [in] */ IWMSPacketStreamerCallback *pCallback,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SelectStream( 
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ IWMSStreamSwitchDescriptionList *pStreamSwitchDescList,
            /* [in] */ IWMSPacketStreamerCallback *pCallback,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Seek( 
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ DWORD dwOffsetType,
            /* [in] */ QWORD qwOffset,
            /* [in] */ DWORD dwFlags,
            /* [in] */ IWMSPacketStreamerCallback *pCallback,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ChangeStreamFormat( 
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ IWMSPacketStreamerCallback *pCallback,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Interrupt( 
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ DWORD dwOptions,
            /* [in] */ IWMSPacketStreamerCallback *pCallback,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DoExtendedCommand( 
            /* [in] */ LPWSTR szCommandName,
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ IWMSPacketStreamerCallback *pCallback,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Shutdown( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWMSPacketStreamerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMSPacketStreamer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMSPacketStreamer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMSPacketStreamer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetStreamInfo )( 
            IWMSPacketStreamer * This,
            /* [in] */ IWMSPacketStreamerCallback *pCallback,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SelectStream )( 
            IWMSPacketStreamer * This,
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ IWMSStreamSwitchDescriptionList *pStreamSwitchDescList,
            /* [in] */ IWMSPacketStreamerCallback *pCallback,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Seek )( 
            IWMSPacketStreamer * This,
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ DWORD dwOffsetType,
            /* [in] */ QWORD qwOffset,
            /* [in] */ DWORD dwFlags,
            /* [in] */ IWMSPacketStreamerCallback *pCallback,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ChangeStreamFormat )( 
            IWMSPacketStreamer * This,
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ IWMSPacketStreamerCallback *pCallback,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Interrupt )( 
            IWMSPacketStreamer * This,
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ DWORD dwOptions,
            /* [in] */ IWMSPacketStreamerCallback *pCallback,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DoExtendedCommand )( 
            IWMSPacketStreamer * This,
            /* [in] */ LPWSTR szCommandName,
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ IWMSPacketStreamerCallback *pCallback,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Shutdown )( 
            IWMSPacketStreamer * This);
        
        END_INTERFACE
    } IWMSPacketStreamerVtbl;

    interface IWMSPacketStreamer
    {
        CONST_VTBL struct IWMSPacketStreamerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMSPacketStreamer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWMSPacketStreamer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWMSPacketStreamer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWMSPacketStreamer_GetStreamInfo(This,pCallback,qwContext)	\
    (This)->lpVtbl -> GetStreamInfo(This,pCallback,qwContext)

#define IWMSPacketStreamer_SelectStream(This,pCommand,pStreamSwitchDescList,pCallback,qwContext)	\
    (This)->lpVtbl -> SelectStream(This,pCommand,pStreamSwitchDescList,pCallback,qwContext)

#define IWMSPacketStreamer_Seek(This,pCommand,dwOffsetType,qwOffset,dwFlags,pCallback,qwContext)	\
    (This)->lpVtbl -> Seek(This,pCommand,dwOffsetType,qwOffset,dwFlags,pCallback,qwContext)

#define IWMSPacketStreamer_ChangeStreamFormat(This,pCommand,pCallback,qwContext)	\
    (This)->lpVtbl -> ChangeStreamFormat(This,pCommand,pCallback,qwContext)

#define IWMSPacketStreamer_Interrupt(This,pCommand,dwOptions,pCallback,qwContext)	\
    (This)->lpVtbl -> Interrupt(This,pCommand,dwOptions,pCallback,qwContext)

#define IWMSPacketStreamer_DoExtendedCommand(This,szCommandName,pCommand,pCallback,qwContext)	\
    (This)->lpVtbl -> DoExtendedCommand(This,szCommandName,pCommand,pCallback,qwContext)

#define IWMSPacketStreamer_Shutdown(This)	\
    (This)->lpVtbl -> Shutdown(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPacketStreamer_GetStreamInfo_Proxy( 
    IWMSPacketStreamer * This,
    /* [in] */ IWMSPacketStreamerCallback *pCallback,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPacketStreamer_GetStreamInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPacketStreamer_SelectStream_Proxy( 
    IWMSPacketStreamer * This,
    /* [in] */ IWMSCommandContext *pCommand,
    /* [in] */ IWMSStreamSwitchDescriptionList *pStreamSwitchDescList,
    /* [in] */ IWMSPacketStreamerCallback *pCallback,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPacketStreamer_SelectStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPacketStreamer_Seek_Proxy( 
    IWMSPacketStreamer * This,
    /* [in] */ IWMSCommandContext *pCommand,
    /* [in] */ DWORD dwOffsetType,
    /* [in] */ QWORD qwOffset,
    /* [in] */ DWORD dwFlags,
    /* [in] */ IWMSPacketStreamerCallback *pCallback,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPacketStreamer_Seek_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPacketStreamer_ChangeStreamFormat_Proxy( 
    IWMSPacketStreamer * This,
    /* [in] */ IWMSCommandContext *pCommand,
    /* [in] */ IWMSPacketStreamerCallback *pCallback,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPacketStreamer_ChangeStreamFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPacketStreamer_Interrupt_Proxy( 
    IWMSPacketStreamer * This,
    /* [in] */ IWMSCommandContext *pCommand,
    /* [in] */ DWORD dwOptions,
    /* [in] */ IWMSPacketStreamerCallback *pCallback,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPacketStreamer_Interrupt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPacketStreamer_DoExtendedCommand_Proxy( 
    IWMSPacketStreamer * This,
    /* [in] */ LPWSTR szCommandName,
    /* [in] */ IWMSCommandContext *pCommand,
    /* [in] */ IWMSPacketStreamerCallback *pCallback,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPacketStreamer_DoExtendedCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPacketStreamer_Shutdown_Proxy( 
    IWMSPacketStreamer * This);


void __RPC_STUB IWMSPacketStreamer_Shutdown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWMSPacketStreamer_INTERFACE_DEFINED__ */


#ifndef __IWMSPacketStreamerCallback_INTERFACE_DEFINED__
#define __IWMSPacketStreamerCallback_INTERFACE_DEFINED__

/* interface IWMSPacketStreamerCallback */
/* [helpstring][version][uuid][unique][object] */ 


EXTERN_C const IID IID_IWMSPacketStreamerCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("72527A82-1119-11d2-9EEE-006097D2D7CF")
    IWMSPacketStreamerCallback : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnGetStreamInfo( 
            /* [in] */ HRESULT hr,
            /* [in] */ IWMSStreamHeaderList *pHeaderList,
            /* [in] */ IWMSContentDescriptionList *pContentDescription,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnSeek( 
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwActualPosition,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnSelectStream( 
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnChangeStreamFormat( 
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnInterrupt( 
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnDoExtendedCommand( 
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwContext) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWMSPacketStreamerCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMSPacketStreamerCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMSPacketStreamerCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMSPacketStreamerCallback * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnGetStreamInfo )( 
            IWMSPacketStreamerCallback * This,
            /* [in] */ HRESULT hr,
            /* [in] */ IWMSStreamHeaderList *pHeaderList,
            /* [in] */ IWMSContentDescriptionList *pContentDescription,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnSeek )( 
            IWMSPacketStreamerCallback * This,
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwActualPosition,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnSelectStream )( 
            IWMSPacketStreamerCallback * This,
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnChangeStreamFormat )( 
            IWMSPacketStreamerCallback * This,
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnInterrupt )( 
            IWMSPacketStreamerCallback * This,
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnDoExtendedCommand )( 
            IWMSPacketStreamerCallback * This,
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwContext);
        
        END_INTERFACE
    } IWMSPacketStreamerCallbackVtbl;

    interface IWMSPacketStreamerCallback
    {
        CONST_VTBL struct IWMSPacketStreamerCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMSPacketStreamerCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWMSPacketStreamerCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWMSPacketStreamerCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWMSPacketStreamerCallback_OnGetStreamInfo(This,hr,pHeaderList,pContentDescription,qwContext)	\
    (This)->lpVtbl -> OnGetStreamInfo(This,hr,pHeaderList,pContentDescription,qwContext)

#define IWMSPacketStreamerCallback_OnSeek(This,hr,qwActualPosition,qwContext)	\
    (This)->lpVtbl -> OnSeek(This,hr,qwActualPosition,qwContext)

#define IWMSPacketStreamerCallback_OnSelectStream(This,hr,qwContext)	\
    (This)->lpVtbl -> OnSelectStream(This,hr,qwContext)

#define IWMSPacketStreamerCallback_OnChangeStreamFormat(This,hr,qwContext)	\
    (This)->lpVtbl -> OnChangeStreamFormat(This,hr,qwContext)

#define IWMSPacketStreamerCallback_OnInterrupt(This,hr,qwContext)	\
    (This)->lpVtbl -> OnInterrupt(This,hr,qwContext)

#define IWMSPacketStreamerCallback_OnDoExtendedCommand(This,hr,qwContext)	\
    (This)->lpVtbl -> OnDoExtendedCommand(This,hr,qwContext)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPacketStreamerCallback_OnGetStreamInfo_Proxy( 
    IWMSPacketStreamerCallback * This,
    /* [in] */ HRESULT hr,
    /* [in] */ IWMSStreamHeaderList *pHeaderList,
    /* [in] */ IWMSContentDescriptionList *pContentDescription,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPacketStreamerCallback_OnGetStreamInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPacketStreamerCallback_OnSeek_Proxy( 
    IWMSPacketStreamerCallback * This,
    /* [in] */ HRESULT hr,
    /* [in] */ QWORD qwActualPosition,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPacketStreamerCallback_OnSeek_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPacketStreamerCallback_OnSelectStream_Proxy( 
    IWMSPacketStreamerCallback * This,
    /* [in] */ HRESULT hr,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPacketStreamerCallback_OnSelectStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPacketStreamerCallback_OnChangeStreamFormat_Proxy( 
    IWMSPacketStreamerCallback * This,
    /* [in] */ HRESULT hr,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPacketStreamerCallback_OnChangeStreamFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPacketStreamerCallback_OnInterrupt_Proxy( 
    IWMSPacketStreamerCallback * This,
    /* [in] */ HRESULT hr,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPacketStreamerCallback_OnInterrupt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPacketStreamerCallback_OnDoExtendedCommand_Proxy( 
    IWMSPacketStreamerCallback * This,
    /* [in] */ HRESULT hr,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPacketStreamerCallback_OnDoExtendedCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWMSPacketStreamerCallback_INTERFACE_DEFINED__ */


#ifndef __IWMSPacketStreamDataContainer_INTERFACE_DEFINED__
#define __IWMSPacketStreamDataContainer_INTERFACE_DEFINED__

/* interface IWMSPacketStreamDataContainer */
/* [helpstring][version][uuid][unique][object] */ 


EXTERN_C const IID IID_IWMSPacketStreamDataContainer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0B1B6039-572C-11d2-9EFF-006097D2D7CF")
    IWMSPacketStreamDataContainer : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetStreamSignalHandler( 
            /* [in] */ IWMSStreamSignalHandler *pStreamSignalHandler) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetMaxPacketSize( 
            /* [out] */ DWORD *pdwMaxPacketSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWMSPacketStreamDataContainerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMSPacketStreamDataContainer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMSPacketStreamDataContainer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMSPacketStreamDataContainer * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetStreamSignalHandler )( 
            IWMSPacketStreamDataContainer * This,
            /* [in] */ IWMSStreamSignalHandler *pStreamSignalHandler);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetMaxPacketSize )( 
            IWMSPacketStreamDataContainer * This,
            /* [out] */ DWORD *pdwMaxPacketSize);
        
        END_INTERFACE
    } IWMSPacketStreamDataContainerVtbl;

    interface IWMSPacketStreamDataContainer
    {
        CONST_VTBL struct IWMSPacketStreamDataContainerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMSPacketStreamDataContainer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWMSPacketStreamDataContainer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWMSPacketStreamDataContainer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWMSPacketStreamDataContainer_SetStreamSignalHandler(This,pStreamSignalHandler)	\
    (This)->lpVtbl -> SetStreamSignalHandler(This,pStreamSignalHandler)

#define IWMSPacketStreamDataContainer_GetMaxPacketSize(This,pdwMaxPacketSize)	\
    (This)->lpVtbl -> GetMaxPacketSize(This,pdwMaxPacketSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPacketStreamDataContainer_SetStreamSignalHandler_Proxy( 
    IWMSPacketStreamDataContainer * This,
    /* [in] */ IWMSStreamSignalHandler *pStreamSignalHandler);


void __RPC_STUB IWMSPacketStreamDataContainer_SetStreamSignalHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPacketStreamDataContainer_GetMaxPacketSize_Proxy( 
    IWMSPacketStreamDataContainer * This,
    /* [out] */ DWORD *pdwMaxPacketSize);


void __RPC_STUB IWMSPacketStreamDataContainer_GetMaxPacketSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWMSPacketStreamDataContainer_INTERFACE_DEFINED__ */


#ifndef __IWMSPushSource_INTERFACE_DEFINED__
#define __IWMSPushSource_INTERFACE_DEFINED__

/* interface IWMSPushSource */
/* [helpstring][version][uuid][unique][object] */ 


EXTERN_C const IID IID_IWMSPushSource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0B840593-115C-11d2-9EEE-006097D2D7CF")
    IWMSPushSource : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ConnectSink( 
            /* [in] */ IWMSPushSink *pDataOutput) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DisconnectSink( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StartPushing( 
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ double dblRate,
            /* [in] */ IWMSPushSourceCallback *pCallback,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE StopPushing( 
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ IWMSPushSourceCallback *pCallback,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE PausePushing( 
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ IWMSPushSourceCallback *pCallback,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ResendPacket( 
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ DWORD dwPacketNum,
            /* [in] */ DWORD dwStreamNum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWMSPushSourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMSPushSource * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMSPushSource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMSPushSource * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ConnectSink )( 
            IWMSPushSource * This,
            /* [in] */ IWMSPushSink *pDataOutput);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DisconnectSink )( 
            IWMSPushSource * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StartPushing )( 
            IWMSPushSource * This,
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ double dblRate,
            /* [in] */ IWMSPushSourceCallback *pCallback,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *StopPushing )( 
            IWMSPushSource * This,
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ IWMSPushSourceCallback *pCallback,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *PausePushing )( 
            IWMSPushSource * This,
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ IWMSPushSourceCallback *pCallback,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ResendPacket )( 
            IWMSPushSource * This,
            /* [in] */ IWMSCommandContext *pCommand,
            /* [in] */ DWORD dwPacketNum,
            /* [in] */ DWORD dwStreamNum);
        
        END_INTERFACE
    } IWMSPushSourceVtbl;

    interface IWMSPushSource
    {
        CONST_VTBL struct IWMSPushSourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMSPushSource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWMSPushSource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWMSPushSource_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWMSPushSource_ConnectSink(This,pDataOutput)	\
    (This)->lpVtbl -> ConnectSink(This,pDataOutput)

#define IWMSPushSource_DisconnectSink(This)	\
    (This)->lpVtbl -> DisconnectSink(This)

#define IWMSPushSource_StartPushing(This,pCommand,dblRate,pCallback,qwContext)	\
    (This)->lpVtbl -> StartPushing(This,pCommand,dblRate,pCallback,qwContext)

#define IWMSPushSource_StopPushing(This,pCommand,pCallback,qwContext)	\
    (This)->lpVtbl -> StopPushing(This,pCommand,pCallback,qwContext)

#define IWMSPushSource_PausePushing(This,pCommand,pCallback,qwContext)	\
    (This)->lpVtbl -> PausePushing(This,pCommand,pCallback,qwContext)

#define IWMSPushSource_ResendPacket(This,pCommand,dwPacketNum,dwStreamNum)	\
    (This)->lpVtbl -> ResendPacket(This,pCommand,dwPacketNum,dwStreamNum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPushSource_ConnectSink_Proxy( 
    IWMSPushSource * This,
    /* [in] */ IWMSPushSink *pDataOutput);


void __RPC_STUB IWMSPushSource_ConnectSink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPushSource_DisconnectSink_Proxy( 
    IWMSPushSource * This);


void __RPC_STUB IWMSPushSource_DisconnectSink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPushSource_StartPushing_Proxy( 
    IWMSPushSource * This,
    /* [in] */ IWMSCommandContext *pCommand,
    /* [in] */ double dblRate,
    /* [in] */ IWMSPushSourceCallback *pCallback,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPushSource_StartPushing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPushSource_StopPushing_Proxy( 
    IWMSPushSource * This,
    /* [in] */ IWMSCommandContext *pCommand,
    /* [in] */ IWMSPushSourceCallback *pCallback,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPushSource_StopPushing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPushSource_PausePushing_Proxy( 
    IWMSPushSource * This,
    /* [in] */ IWMSCommandContext *pCommand,
    /* [in] */ IWMSPushSourceCallback *pCallback,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPushSource_PausePushing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPushSource_ResendPacket_Proxy( 
    IWMSPushSource * This,
    /* [in] */ IWMSCommandContext *pCommand,
    /* [in] */ DWORD dwPacketNum,
    /* [in] */ DWORD dwStreamNum);


void __RPC_STUB IWMSPushSource_ResendPacket_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWMSPushSource_INTERFACE_DEFINED__ */


#ifndef __IWMSPushSourceCallback_INTERFACE_DEFINED__
#define __IWMSPushSourceCallback_INTERFACE_DEFINED__

/* interface IWMSPushSourceCallback */
/* [helpstring][version][uuid][unique][object] */ 


EXTERN_C const IID IID_IWMSPushSourceCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EAD035E4-BE4A-4a7a-BC19-5B0B9E09D74C")
    IWMSPushSourceCallback : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnStartPushing( 
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnStopPushing( 
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwContext) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OnPausePushing( 
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwContext) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWMSPushSourceCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMSPushSourceCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMSPushSourceCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMSPushSourceCallback * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnStartPushing )( 
            IWMSPushSourceCallback * This,
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnStopPushing )( 
            IWMSPushSourceCallback * This,
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwContext);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *OnPausePushing )( 
            IWMSPushSourceCallback * This,
            /* [in] */ HRESULT hr,
            /* [in] */ QWORD qwContext);
        
        END_INTERFACE
    } IWMSPushSourceCallbackVtbl;

    interface IWMSPushSourceCallback
    {
        CONST_VTBL struct IWMSPushSourceCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMSPushSourceCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWMSPushSourceCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWMSPushSourceCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWMSPushSourceCallback_OnStartPushing(This,hr,qwContext)	\
    (This)->lpVtbl -> OnStartPushing(This,hr,qwContext)

#define IWMSPushSourceCallback_OnStopPushing(This,hr,qwContext)	\
    (This)->lpVtbl -> OnStopPushing(This,hr,qwContext)

#define IWMSPushSourceCallback_OnPausePushing(This,hr,qwContext)	\
    (This)->lpVtbl -> OnPausePushing(This,hr,qwContext)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPushSourceCallback_OnStartPushing_Proxy( 
    IWMSPushSourceCallback * This,
    /* [in] */ HRESULT hr,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPushSourceCallback_OnStartPushing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPushSourceCallback_OnStopPushing_Proxy( 
    IWMSPushSourceCallback * This,
    /* [in] */ HRESULT hr,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPushSourceCallback_OnStopPushing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPushSourceCallback_OnPausePushing_Proxy( 
    IWMSPushSourceCallback * This,
    /* [in] */ HRESULT hr,
    /* [in] */ QWORD qwContext);


void __RPC_STUB IWMSPushSourceCallback_OnPausePushing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWMSPushSourceCallback_INTERFACE_DEFINED__ */


#ifndef __IWMSPushSink_INTERFACE_DEFINED__
#define __IWMSPushSink_INTERFACE_DEFINED__

/* interface IWMSPushSink */
/* [helpstring][version][uuid][unique][object] */ 


EXTERN_C const IID IID_IWMSPushSink;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0B840594-115C-11d2-9EEE-006097D2D7CF")
    IWMSPushSink : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ConnectSource( 
            /* [in] */ IWMSPushSource *pDataInput) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DisconnectSource( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ProcessPackets( 
            /* [in] */ IWMSPacketList *pPacketList) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWMSPushSinkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMSPushSink * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMSPushSink * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMSPushSink * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ConnectSource )( 
            IWMSPushSink * This,
            /* [in] */ IWMSPushSource *pDataInput);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *DisconnectSource )( 
            IWMSPushSink * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ProcessPackets )( 
            IWMSPushSink * This,
            /* [in] */ IWMSPacketList *pPacketList);
        
        END_INTERFACE
    } IWMSPushSinkVtbl;

    interface IWMSPushSink
    {
        CONST_VTBL struct IWMSPushSinkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMSPushSink_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWMSPushSink_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWMSPushSink_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWMSPushSink_ConnectSource(This,pDataInput)	\
    (This)->lpVtbl -> ConnectSource(This,pDataInput)

#define IWMSPushSink_DisconnectSource(This)	\
    (This)->lpVtbl -> DisconnectSource(This)

#define IWMSPushSink_ProcessPackets(This,pPacketList)	\
    (This)->lpVtbl -> ProcessPackets(This,pPacketList)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPushSink_ConnectSource_Proxy( 
    IWMSPushSink * This,
    /* [in] */ IWMSPushSource *pDataInput);


void __RPC_STUB IWMSPushSink_ConnectSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPushSink_DisconnectSource_Proxy( 
    IWMSPushSink * This);


void __RPC_STUB IWMSPushSink_DisconnectSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSPushSink_ProcessPackets_Proxy( 
    IWMSPushSink * This,
    /* [in] */ IWMSPacketList *pPacketList);


void __RPC_STUB IWMSPushSink_ProcessPackets_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWMSPushSink_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


