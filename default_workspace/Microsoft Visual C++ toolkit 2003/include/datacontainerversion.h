

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for datacontainerversion.idl:
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

#ifndef __datacontainerversion_h__
#define __datacontainerversion_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IWMSDataContainerVersion_FWD_DEFINED__
#define __IWMSDataContainerVersion_FWD_DEFINED__
typedef interface IWMSDataContainerVersion IWMSDataContainerVersion;
#endif 	/* __IWMSDataContainerVersion_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_datacontainerversion_0000 */
/* [local] */ 

//*****************************************************************************
//
// Microsoft Windows Media
// Copyright (C) Microsoft Corporation. All rights reserved.
//
// Automatically generated by Midl from datacontainerversion.idl
//
// DO NOT EDIT THIS FILE.
//
//*****************************************************************************
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
EXTERN_GUID( IID_IWMSDataContainerVersion, 0x3AE75C14,0x2B3A,0x11d2,0x9E,0xF7,0x00,0x60,0x97,0xD2,0xD7,0xCF );
typedef /* [public] */ 
enum WMS_DATA_CONTAINER_VERSION_CACHE_FLAGS
    {	WMS_DATA_CONTAINER_VERSION_ALLOW_PROXY_CACHING	= 0x1,
	WMS_DATA_CONTAINER_VERSION_ALLOW_PLAYER_CACHING	= 0x2,
	WMS_DATA_CONTAINER_VERSION_ALLOW_STREAM_SPLITTING	= 0x4
    } 	WMS_DATA_CONTAINER_VERSION_CACHE_FLAGS;



extern RPC_IF_HANDLE __MIDL_itf_datacontainerversion_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_datacontainerversion_0000_v0_0_s_ifspec;

#ifndef __IWMSDataContainerVersion_INTERFACE_DEFINED__
#define __IWMSDataContainerVersion_INTERFACE_DEFINED__

/* interface IWMSDataContainerVersion */
/* [helpstring][version][uuid][unique][object] */ 


EXTERN_C const IID IID_IWMSDataContainerVersion;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3AE75C14-2B3A-11d2-9EF7-006097D2D7CF")
    IWMSDataContainerVersion : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetLastModifiedTime( 
            /* [out] */ DATE *pdateLastModifiedTime) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetLastModifiedTime( 
            /* [in] */ DATE dateLastModifiedTime) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetExpirationTime( 
            /* [out] */ DATE *pdateExpirationTime) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetExpirationTime( 
            /* [in] */ DATE dateExpirationTime) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetCacheFlags( 
            /* [out] */ long *plFlags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetCacheFlags( 
            /* [in] */ long lFlags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetContentSize( 
            /* [out] */ long *plContentSizeLow,
            /* [out] */ long *plContentSizeHigh) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetContentSize( 
            /* [in] */ long lContentSizeLow,
            /* [in] */ long lContentSizeHigh) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetEntityTagCount( 
            /* [out] */ long *plNumEntityTags) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetEntityTag( 
            /* [in] */ long lTagNum,
            /* [out] */ BSTR *pszEntityTag) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetEntityTag( 
            /* [in] */ BSTR szEntityTag) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Compare( 
            /* [in] */ IWMSDataContainerVersion *pVersion,
            /* [out] */ VARIANT_BOOL *pvfEqual) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWMSDataContainerVersionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWMSDataContainerVersion * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWMSDataContainerVersion * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWMSDataContainerVersion * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetLastModifiedTime )( 
            IWMSDataContainerVersion * This,
            /* [out] */ DATE *pdateLastModifiedTime);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetLastModifiedTime )( 
            IWMSDataContainerVersion * This,
            /* [in] */ DATE dateLastModifiedTime);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetExpirationTime )( 
            IWMSDataContainerVersion * This,
            /* [out] */ DATE *pdateExpirationTime);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetExpirationTime )( 
            IWMSDataContainerVersion * This,
            /* [in] */ DATE dateExpirationTime);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetCacheFlags )( 
            IWMSDataContainerVersion * This,
            /* [out] */ long *plFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetCacheFlags )( 
            IWMSDataContainerVersion * This,
            /* [in] */ long lFlags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetContentSize )( 
            IWMSDataContainerVersion * This,
            /* [out] */ long *plContentSizeLow,
            /* [out] */ long *plContentSizeHigh);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetContentSize )( 
            IWMSDataContainerVersion * This,
            /* [in] */ long lContentSizeLow,
            /* [in] */ long lContentSizeHigh);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEntityTagCount )( 
            IWMSDataContainerVersion * This,
            /* [out] */ long *plNumEntityTags);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEntityTag )( 
            IWMSDataContainerVersion * This,
            /* [in] */ long lTagNum,
            /* [out] */ BSTR *pszEntityTag);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetEntityTag )( 
            IWMSDataContainerVersion * This,
            /* [in] */ BSTR szEntityTag);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Compare )( 
            IWMSDataContainerVersion * This,
            /* [in] */ IWMSDataContainerVersion *pVersion,
            /* [out] */ VARIANT_BOOL *pvfEqual);
        
        END_INTERFACE
    } IWMSDataContainerVersionVtbl;

    interface IWMSDataContainerVersion
    {
        CONST_VTBL struct IWMSDataContainerVersionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWMSDataContainerVersion_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWMSDataContainerVersion_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWMSDataContainerVersion_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWMSDataContainerVersion_GetLastModifiedTime(This,pdateLastModifiedTime)	\
    (This)->lpVtbl -> GetLastModifiedTime(This,pdateLastModifiedTime)

#define IWMSDataContainerVersion_SetLastModifiedTime(This,dateLastModifiedTime)	\
    (This)->lpVtbl -> SetLastModifiedTime(This,dateLastModifiedTime)

#define IWMSDataContainerVersion_GetExpirationTime(This,pdateExpirationTime)	\
    (This)->lpVtbl -> GetExpirationTime(This,pdateExpirationTime)

#define IWMSDataContainerVersion_SetExpirationTime(This,dateExpirationTime)	\
    (This)->lpVtbl -> SetExpirationTime(This,dateExpirationTime)

#define IWMSDataContainerVersion_GetCacheFlags(This,plFlags)	\
    (This)->lpVtbl -> GetCacheFlags(This,plFlags)

#define IWMSDataContainerVersion_SetCacheFlags(This,lFlags)	\
    (This)->lpVtbl -> SetCacheFlags(This,lFlags)

#define IWMSDataContainerVersion_GetContentSize(This,plContentSizeLow,plContentSizeHigh)	\
    (This)->lpVtbl -> GetContentSize(This,plContentSizeLow,plContentSizeHigh)

#define IWMSDataContainerVersion_SetContentSize(This,lContentSizeLow,lContentSizeHigh)	\
    (This)->lpVtbl -> SetContentSize(This,lContentSizeLow,lContentSizeHigh)

#define IWMSDataContainerVersion_GetEntityTagCount(This,plNumEntityTags)	\
    (This)->lpVtbl -> GetEntityTagCount(This,plNumEntityTags)

#define IWMSDataContainerVersion_GetEntityTag(This,lTagNum,pszEntityTag)	\
    (This)->lpVtbl -> GetEntityTag(This,lTagNum,pszEntityTag)

#define IWMSDataContainerVersion_SetEntityTag(This,szEntityTag)	\
    (This)->lpVtbl -> SetEntityTag(This,szEntityTag)

#define IWMSDataContainerVersion_Compare(This,pVersion,pvfEqual)	\
    (This)->lpVtbl -> Compare(This,pVersion,pvfEqual)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSDataContainerVersion_GetLastModifiedTime_Proxy( 
    IWMSDataContainerVersion * This,
    /* [out] */ DATE *pdateLastModifiedTime);


void __RPC_STUB IWMSDataContainerVersion_GetLastModifiedTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSDataContainerVersion_SetLastModifiedTime_Proxy( 
    IWMSDataContainerVersion * This,
    /* [in] */ DATE dateLastModifiedTime);


void __RPC_STUB IWMSDataContainerVersion_SetLastModifiedTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSDataContainerVersion_GetExpirationTime_Proxy( 
    IWMSDataContainerVersion * This,
    /* [out] */ DATE *pdateExpirationTime);


void __RPC_STUB IWMSDataContainerVersion_GetExpirationTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSDataContainerVersion_SetExpirationTime_Proxy( 
    IWMSDataContainerVersion * This,
    /* [in] */ DATE dateExpirationTime);


void __RPC_STUB IWMSDataContainerVersion_SetExpirationTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSDataContainerVersion_GetCacheFlags_Proxy( 
    IWMSDataContainerVersion * This,
    /* [out] */ long *plFlags);


void __RPC_STUB IWMSDataContainerVersion_GetCacheFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSDataContainerVersion_SetCacheFlags_Proxy( 
    IWMSDataContainerVersion * This,
    /* [in] */ long lFlags);


void __RPC_STUB IWMSDataContainerVersion_SetCacheFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSDataContainerVersion_GetContentSize_Proxy( 
    IWMSDataContainerVersion * This,
    /* [out] */ long *plContentSizeLow,
    /* [out] */ long *plContentSizeHigh);


void __RPC_STUB IWMSDataContainerVersion_GetContentSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSDataContainerVersion_SetContentSize_Proxy( 
    IWMSDataContainerVersion * This,
    /* [in] */ long lContentSizeLow,
    /* [in] */ long lContentSizeHigh);


void __RPC_STUB IWMSDataContainerVersion_SetContentSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSDataContainerVersion_GetEntityTagCount_Proxy( 
    IWMSDataContainerVersion * This,
    /* [out] */ long *plNumEntityTags);


void __RPC_STUB IWMSDataContainerVersion_GetEntityTagCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSDataContainerVersion_GetEntityTag_Proxy( 
    IWMSDataContainerVersion * This,
    /* [in] */ long lTagNum,
    /* [out] */ BSTR *pszEntityTag);


void __RPC_STUB IWMSDataContainerVersion_GetEntityTag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSDataContainerVersion_SetEntityTag_Proxy( 
    IWMSDataContainerVersion * This,
    /* [in] */ BSTR szEntityTag);


void __RPC_STUB IWMSDataContainerVersion_SetEntityTag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IWMSDataContainerVersion_Compare_Proxy( 
    IWMSDataContainerVersion * This,
    /* [in] */ IWMSDataContainerVersion *pVersion,
    /* [out] */ VARIANT_BOOL *pvfEqual);


void __RPC_STUB IWMSDataContainerVersion_Compare_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWMSDataContainerVersion_INTERFACE_DEFINED__ */


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


