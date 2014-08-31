

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for wmsproxy.idl:
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

#ifndef __wmsproxy_h__
#define __wmsproxy_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IWMSProxyContext_FWD_DEFINED__
#define __IWMSProxyContext_FWD_DEFINED__
typedef interface IWMSProxyContext IWMSProxyContext;
#endif 	/* __IWMSProxyContext_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "wmscontext.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_wmsproxy_0000 */
/* [local] */ 

//*****************************************************************************
//
// Microsoft Windows Media
// Copyright (C) Microsoft Corporation. All rights reserved.
//
// Automatically generated by Midl from wmsproxy.idl
//
// DO NOT EDIT THIS FILE.
//
//*****************************************************************************
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

EXTERN_GUID( IID_IWMSProxyContext,        0x2E34AB85,0x0D3D,0x11d2,0x9E,0xEE,0x00,0x60,0x97,0xD2,0xD7,0xCF );


extern RPC_IF_HANDLE __MIDL_itf_wmsproxy_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wmsproxy_0000_v0_0_s_ifspec;

#ifndef __IWMSProxyContext_INTERFACE_DEFINED__
#define __IWMSProxyContext_INTERFACE_DEFINED__

/* interface IWMSProxyContext */
/* [helpstring][version][uuid][unique][object] */ 


EXTERN_C const IID IID_IWMSProxyContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2E34AB85-0D3D-11d2-9EEE-006097D2D7CF")
    IWMSProxyContext : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE FindProxyForURL( 
            /* [in] */ IWMSContext *pUserContext,
            /* [in] */ BSTR bstrUrl,
            /* [out] */ BSTR *pbstrProxyServer,
            /* [out] */ DWORD *pdwProxyPort) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCredentials( 
            /* [in] */ IWMSContext *pUserContext,
            /* [in] */ BSTR bstrRealm,
            /* [in] */ BSTR bstrUrl,
            /* [out] */ BSTR *pbstrName,
            /* [out] */ BSTR *pbstrPassword) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWMSProxyContextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMSProxyContext * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMSProxyContext * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMSProxyContext * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *FindProxyForURL )( 
            IWMSProxyContext * This,
            /* [in] */ IWMSContext *pUserContext,
            /* [in] */ BSTR bstrUrl,
            /* [out] */ BSTR *pbstrProxyServer,
            /* [out] */ DWORD *pdwProxyPort);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCredentials )( 
            IWMSProxyContext * This,
            /* [in] */ IWMSContext *pUserContext,
            /* [in] */ BSTR bstrRealm,
            /* [in] */ BSTR bstrUrl,
            /* [out] */ BSTR *pbstrName,
            /* [out] */ BSTR *pbstrPassword);
        
        END_INTERFACE
    } IWMSProxyContextVtbl;

    interface IWMSProxyContext
    {
        CONST_VTBL struct IWMSProxyContextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMSProxyContext_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWMSProxyContext_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWMSProxyContext_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWMSProxyContext_FindProxyForURL(This,pUserContext,bstrUrl,pbstrProxyServer,pdwProxyPort)	\
    (This)->lpVtbl -> FindProxyForURL(This,pUserContext,bstrUrl,pbstrProxyServer,pdwProxyPort)

#define IWMSProxyContext_GetCredentials(This,pUserContext,bstrRealm,bstrUrl,pbstrName,pbstrPassword)	\
    (This)->lpVtbl -> GetCredentials(This,pUserContext,bstrRealm,bstrUrl,pbstrName,pbstrPassword)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSProxyContext_FindProxyForURL_Proxy( 
    IWMSProxyContext * This,
    /* [in] */ IWMSContext *pUserContext,
    /* [in] */ BSTR bstrUrl,
    /* [out] */ BSTR *pbstrProxyServer,
    /* [out] */ DWORD *pdwProxyPort);


void __RPC_STUB IWMSProxyContext_FindProxyForURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSProxyContext_GetCredentials_Proxy( 
    IWMSProxyContext * This,
    /* [in] */ IWMSContext *pUserContext,
    /* [in] */ BSTR bstrRealm,
    /* [in] */ BSTR bstrUrl,
    /* [out] */ BSTR *pbstrName,
    /* [out] */ BSTR *pbstrPassword);


void __RPC_STUB IWMSProxyContext_GetCredentials_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWMSProxyContext_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


