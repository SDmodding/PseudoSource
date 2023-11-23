// File Line: 21
// RVA: 0xEDB9E0
void __fastcall OSuite::ZHttpRequestClientCBWrapper::Call(OSuite::ZHttpRequestClientCBWrapper *this)
{
  void *v2; // rdi
  OSuite::ZObjectAccessor *v3; // rax
  char v4; // al
  OSuite::IHttpRequest *m_pHttpRequest; // rcx
  bool v6; // zf
  OSuite::ZObjectVtbl *vfptr; // rax
  OSuite::ZObjectAccessor *v8; // rax

  v2 = (void *)((__int64 (__fastcall *)(OSuite::IHttpRequest *))this->m_pHttpRequest->vfptr[32].__vecDelDtor)(this->m_pHttpRequest);
  v3 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::AccessObject(v3, v2);
  if ( !this->m_pHttpRequest->vfptr[17].__vecDelDtor(this->m_pHttpRequest, 2132i64) )
  {
    v4 = (char)this->OSuite::ManagedCallback::OSuite::ICallback<void,void>::vfptr[1].Clone(this);
    m_pHttpRequest = this->m_pHttpRequest;
    this->m_bReturnCode = v4;
    v6 = v4 == 0;
    vfptr = m_pHttpRequest->vfptr;
    if ( v6 )
    {
      vfptr[37].__vecDelDtor(m_pHttpRequest, 256u);
      this->m_pHttpRequest->vfptr[40].__vecDelDtor(this->m_pHttpRequest, this->m_onFailureHttpError);
    }
    else
    {
      vfptr[37].__vecDelDtor(m_pHttpRequest, this->m_onSucessState);
    }
  }
  v8 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::ReleaseObject(v8, v2);
}

// File Line: 49
// RVA: 0xEDB9B0
void __fastcall OSuite::ZOnStartedHttpRequest::ZOnStartedHttpRequest(
        OSuite::ZOnStartedHttpRequest *this,
        OSuite::IHttpRequest *pHttpRequest)
{
  this->m_pHttpRequest = pHttpRequest;
  this->m_onSucessState = ASYNCHSTATE_CONNECTION;
  this->OSuite::ZHttpRequestClientCBWrapper::OSuite::ManagedCallback::OSuite::ICallback<void,void>::vfptr = (OSuite::ICallback<void,void>Vtbl *)&OSuite::ZOnStartedHttpRequest::`vftable{for `OSuite::ICallback<void,void>};
  this->m_onFailureHttpError = HTTPERROR_ABORTED;
  this->OSuite::ZHttpRequestClientCBWrapper::OSuite::ManagedCallback::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOnStartedHttpRequest::`vftable{for `OSuite::ZObject};
  this->m_bReturnCode = 0;
}

// File Line: 53
// RVA: 0xEDBC70
char __fastcall OSuite::ZOnStartedHttpRequest::InternalCall(OSuite::ZOnStartedHttpRequest *this)
{
  OSuite::IHttpRequest *m_pHttpRequest; // rbx
  __int64 v4; // rax
  char v5[16]; // [rsp+20h] [rbp-28h] BYREF
  char v6[24]; // [rsp+30h] [rbp-18h] BYREF

  if ( *(_OWORD *)this->m_pHttpRequest->OSuite::ZHttpRequestClientCBWrapper::vfptr[1].__vecDelDtor(
                    this->m_pHttpRequest,
                    v5) == 0i64 )
    return 1;
  m_pHttpRequest = this->m_pHttpRequest;
  v4 = (__int64)m_pHttpRequest->vfptr[1].__vecDelDtor(m_pHttpRequest, (unsigned int)v6);
  return (*(__int64 (__fastcall **)(_QWORD, OSuite::IHttpRequest *))(v4 + 8))(*(_QWORD *)v4, m_pHttpRequest);
}

// File Line: 62
// RVA: 0xEDB924
void __fastcall OSuite::ZOnDataAvailableHttpRequest::ZOnDataAvailableHttpRequest(
        OSuite::ZOnDataAvailableHttpRequest *this,
        OSuite::IHttpRequest *pHttpRequest)
{
  this->m_pHttpRequest = pHttpRequest;
  this->m_onSucessState = ASYNCHSTATE_RECEIVE;
  this->OSuite::ZHttpRequestClientCBWrapper::OSuite::ManagedCallback::OSuite::ICallback<void,void>::vfptr = (OSuite::ICallback<void,void>Vtbl *)&OSuite::ZOnDataAvailableHttpRequest::`vftable{for `OSuite::ICallback<void,void>};
  this->m_onFailureHttpError = HTTPERROR_DATARECEIVEFAILED;
  this->OSuite::ZHttpRequestClientCBWrapper::OSuite::ManagedCallback::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOnStartedHttpRequest::`vftable{for `OSuite::ZObject};
  this->m_bReturnCode = 0;
}

// File Line: 66
// RVA: 0xEDBA7C
char __fastcall OSuite::ZOnDataAvailableHttpRequest::InternalCall(OSuite::ZOnDataAvailableHttpRequest *this)
{
  __int64 v3; // rax
  __int64 v4; // rax
  OSuite::IHttpRequest *m_pHttpRequest; // rdi
  __int64 v6; // rbx
  __int64 v7; // rax
  char v8[16]; // [rsp+20h] [rbp-28h] BYREF
  char v9[24]; // [rsp+30h] [rbp-18h] BYREF

  if ( *(_OWORD *)this->m_pHttpRequest->OSuite::ZHttpRequestClientCBWrapper::vfptr[2].__vecDelDtor(
                    this->m_pHttpRequest,
                    v8) == 0i64 )
    return 1;
  v3 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))this->m_pHttpRequest->OSuite::ZHttpRequestClientCBWrapper::vfptr[33].__vecDelDtor)(this->m_pHttpRequest);
  v4 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v3 + 64i64))(v3);
  m_pHttpRequest = this->m_pHttpRequest;
  v6 = v4;
  v7 = (__int64)m_pHttpRequest->vfptr[2].__vecDelDtor(m_pHttpRequest, (unsigned int)v9);
  return (*(__int64 (__fastcall **)(_QWORD, OSuite::IHttpRequest *, __int64))(v7 + 8))(
           *(_QWORD *)v7,
           m_pHttpRequest,
           v6);
}

// File Line: 76
// RVA: 0xEDB954
void __fastcall OSuite::ZOnDataNeededHttpRequest::ZOnDataNeededHttpRequest(
        OSuite::ZOnDataNeededHttpRequest *this,
        OSuite::IHttpRequest *pHttpRequest)
{
  this->m_pHttpRequest = pHttpRequest;
  this->m_onSucessState = ASYNCHSTATE_SEND;
  this->OSuite::ZHttpRequestClientCBWrapper::OSuite::ManagedCallback::OSuite::ICallback<void,void>::vfptr = (OSuite::ICallback<void,void>Vtbl *)&OSuite::ZOnDataNeededHttpRequest::`vftable{for `OSuite::ICallback<void,void>};
  this->m_onFailureHttpError = HTTPERROR_DATASENDFAILED;
  this->OSuite::ZHttpRequestClientCBWrapper::OSuite::ManagedCallback::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOnStartedHttpRequest::`vftable{for `OSuite::ZObject};
  this->m_bReturnCode = 0;
}

// File Line: 81
// RVA: 0xEDBAF0
char __fastcall OSuite::ZOnDataNeededHttpRequest::InternalCall(OSuite::ZOnDataNeededHttpRequest *this)
{
  __int64 v3; // rax
  OSuite::IHttpRequest *m_pHttpRequest; // rdi
  __int64 v5; // rbx
  __int64 v6; // rax
  char v7[16]; // [rsp+20h] [rbp-28h] BYREF
  char v8[24]; // [rsp+30h] [rbp-18h] BYREF

  if ( *(_OWORD *)this->m_pHttpRequest->OSuite::ZHttpRequestClientCBWrapper::vfptr[3].__vecDelDtor(
                    this->m_pHttpRequest,
                    v7) == 0i64 )
    return 1;
  v3 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))this->m_pHttpRequest->OSuite::ZHttpRequestClientCBWrapper::vfptr[21].__vecDelDtor)(this->m_pHttpRequest);
  m_pHttpRequest = this->m_pHttpRequest;
  v5 = v3;
  v6 = (__int64)m_pHttpRequest->vfptr[3].__vecDelDtor(m_pHttpRequest, (unsigned int)v8);
  return (*(__int64 (__fastcall **)(_QWORD, OSuite::IHttpRequest *, __int64))(v6 + 8))(
           *(_QWORD *)v6,
           m_pHttpRequest,
           v5);
}

// File Line: 91
// RVA: 0xEDB984
void __fastcall OSuite::ZOnFinishedHttpRequest::ZOnFinishedHttpRequest(
        OSuite::ZOnFinishedHttpRequest *this,
        OSuite::IHttpRequest *pHttpRequest)
{
  this->m_onFailureHttpError = HTTPERROR_OK;
  this->m_pHttpRequest = pHttpRequest;
  this->OSuite::ZHttpRequestClientCBWrapper::OSuite::ManagedCallback::OSuite::ICallback<void,void>::vfptr = (OSuite::ICallback<void,void>Vtbl *)&OSuite::ZOnFinishedHttpRequest::`vftable{for `OSuite::ICallback<void,void>};
  this->m_onSucessState = ASYNCHSTATE_LYMBO;
  this->OSuite::ZHttpRequestClientCBWrapper::OSuite::ManagedCallback::OSuite::ZObject::vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOnStartedHttpRequest::`vftable{for `OSuite::ZObject};
  this->m_bReturnCode = 0;
}

// File Line: 95
// RVA: 0xEDBB5C
char __fastcall OSuite::ZOnFinishedHttpRequest::InternalCall(OSuite::ZOnFinishedHttpRequest *this)
{
  OSuite::ZUrl *v2; // rdi
  OSuite::ZUsageTrackingManager *v3; // rbx
  OSuite::ZString *TicketData; // rax
  const char *v5; // rax
  OSuite::ZObjectVtbl *v6; // r14
  OSuite::ZString *Path; // rax
  const char *v8; // rsi
  OSuite::IHttpRequest *m_pHttpRequest; // rdi
  unsigned __int64 v10; // rbx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rax
  unsigned int v13; // eax
  OSuite::IHttpRequest *v14; // rdi
  unsigned int v15; // ebx
  __int64 v16; // rax
  char v18[24]; // [rsp+20h] [rbp-18h] BYREF

  v2 = (OSuite::ZUrl *)((__int64 (__fastcall *)(OSuite::IHttpRequest *))this->m_pHttpRequest->OSuite::ZHttpRequestClientCBWrapper::vfptr[34].__vecDelDtor)(this->m_pHttpRequest);
  if ( ((unsigned __int8 (__fastcall *)(OSuite::IHttpRequest *))this->m_pHttpRequest->OSuite::ZHttpRequestClientCBWrapper::vfptr[35].__vecDelDtor)(this->m_pHttpRequest) )
  {
    v3 = OSuite::TSingleton<OSuite::ZUsageTrackingManager>::Object();
    TicketData = OSuite::IOnlineAuthentication::GetTicketData(v2);
    v5 = OSuite::ZString::c_str(TicketData);
    v6 = OSuite::ZUsageTrackingManager::GetForHost(v3, v5);
    if ( v6 )
    {
      Path = OSuite::ZUrl::GetPath(v2);
      v8 = OSuite::ZString::c_str(Path);
      m_pHttpRequest = this->m_pHttpRequest;
      v10 = ((__int64 (*)(void))m_pHttpRequest->vfptr[25].__vecDelDtor)();
      v11 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))m_pHttpRequest->vfptr[26].__vecDelDtor)(m_pHttpRequest);
      OSuite::ZUsageTracker::Record((OSuite::ZUsageTracker *)v6, v8, v11, v10);
    }
  }
  v12 = this->m_pHttpRequest->OSuite::ZHttpRequestClientCBWrapper::vfptr[4].__vecDelDtor(this->m_pHttpRequest, v18);
  if ( *v12 || v12[1] )
  {
    v13 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))this->m_pHttpRequest->OSuite::ZHttpRequestClientCBWrapper::vfptr[28].__vecDelDtor)(this->m_pHttpRequest);
    v14 = this->m_pHttpRequest;
    v15 = v13;
    v16 = (__int64)v14->vfptr[4].__vecDelDtor(v14, (unsigned int)v18);
    (*(void (__fastcall **)(_QWORD, OSuite::IHttpRequest *, _QWORD))(v16 + 8))(*(_QWORD *)v16, v14, v15);
  }
  return 1;
}

