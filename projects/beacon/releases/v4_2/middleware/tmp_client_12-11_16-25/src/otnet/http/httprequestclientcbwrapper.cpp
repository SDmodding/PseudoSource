// File Line: 21
// RVA: 0xEDB9E0
void __fastcall OSuite::ZHttpRequestClientCBWrapper::Call(OSuite::ZHttpRequestClientCBWrapper *this)
{
  OSuite::ZHttpRequestClientCBWrapper *v1; // rbx
  void *v2; // rdi
  OSuite::ZObjectAccessor *v3; // rax
  char v4; // al
  OSuite::IHttpRequest *v5; // rcx
  bool v6; // zf
  OSuite::ZObjectVtbl *v7; // rax
  OSuite::ZObjectAccessor *v8; // rax

  v1 = this;
  v2 = (void *)((__int64 (*)(void))this->m_pHttpRequest->vfptr[32].__vecDelDtor)();
  v3 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::AccessObject(v3, v2);
  if ( !(unsigned __int8)v1->m_pHttpRequest->vfptr[17].__vecDelDtor(
                           (OSuite::ZObject *)&v1->m_pHttpRequest->vfptr,
                           2132u) )
  {
    v4 = (__int64)v1->vfptr[1].Clone((OSuite::ICallback<void,void> *)&v1->vfptr);
    v5 = v1->m_pHttpRequest;
    v1->m_bReturnCode = v4;
    v6 = v4 == 0;
    v7 = v5->vfptr;
    if ( v6 )
    {
      v7[37].__vecDelDtor((OSuite::ZObject *)&v5->vfptr, 256u);
      v1->m_pHttpRequest->vfptr[40].__vecDelDtor((OSuite::ZObject *)v1->m_pHttpRequest, v1->m_onFailureHttpError);
    }
    else
    {
      v7[37].__vecDelDtor((OSuite::ZObject *)&v5->vfptr, v1->m_onSucessState);
    }
  }
  v8 = OSuite::TSingleton<OSuite::ZObjectAccessor>::Object();
  OSuite::ZObjectAccessor::ReleaseObject(v8, v2);
}

// File Line: 49
// RVA: 0xEDB9B0
void __fastcall OSuite::ZOnStartedHttpRequest::ZOnStartedHttpRequest(OSuite::ZOnStartedHttpRequest *this, OSuite::IHttpRequest *pHttpRequest)
{
  this->m_pHttpRequest = pHttpRequest;
  this->m_onSucessState = 2;
  this->vfptr = (OSuite::ICallback<void,void>Vtbl *)&OSuite::ZOnStartedHttpRequest::`vftable'{for `OSuite::ICallback<void,void>'};
  this->m_onFailureHttpError = 11;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOnStartedHttpRequest::`vftable'{for `OSuite::ZObject'};
  this->m_bReturnCode = 0;
}

// File Line: 53
// RVA: 0xEDBC70
char __fastcall OSuite::ZOnStartedHttpRequest::InternalCall(OSuite::ZOnStartedHttpRequest *this)
{
  OSuite::ZOnStartedHttpRequest *v1; // rbx
  _QWORD *v2; // rax
  OSuite::IHttpRequest *v4; // rbx
  __int64 v5; // rax
  char v6; // [rsp+20h] [rbp-28h]
  char v7; // [rsp+30h] [rbp-18h]

  v1 = this;
  v2 = (_QWORD *)this->m_pHttpRequest->vfptr[1].__vecDelDtor((OSuite::ZObject *)this->m_pHttpRequest, (unsigned int)&v6);
  if ( !*v2 && !v2[1] )
    return 1;
  v4 = v1->m_pHttpRequest;
  v5 = (__int64)v4->vfptr[1].__vecDelDtor((OSuite::ZObject *)&v4->vfptr, (unsigned int)&v7);
  return (*(__int64 (__fastcall **)(_QWORD, OSuite::IHttpRequest *))(v5 + 8))(*(_QWORD *)v5, v4);
}

// File Line: 62
// RVA: 0xEDB924
void __fastcall OSuite::ZOnDataAvailableHttpRequest::ZOnDataAvailableHttpRequest(OSuite::ZOnDataAvailableHttpRequest *this, OSuite::IHttpRequest *pHttpRequest)
{
  this->m_pHttpRequest = pHttpRequest;
  this->m_onSucessState = 32;
  this->vfptr = (OSuite::ICallback<void,void>Vtbl *)&OSuite::ZOnDataAvailableHttpRequest::`vftable'{for `OSuite::ICallback<void,void>'};
  this->m_onFailureHttpError = 5;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOnStartedHttpRequest::`vftable'{for `OSuite::ZObject'};
  this->m_bReturnCode = 0;
}

// File Line: 66
// RVA: 0xEDBA7C
char __fastcall OSuite::ZOnDataAvailableHttpRequest::InternalCall(OSuite::ZOnDataAvailableHttpRequest *this)
{
  OSuite::ZOnDataAvailableHttpRequest *v1; // rdi
  _QWORD *v2; // rax
  __int64 v4; // rax
  __int64 v5; // rax
  OSuite::IHttpRequest *v6; // rdi
  __int64 v7; // rbx
  __int64 v8; // rax
  char v9; // [rsp+20h] [rbp-28h]
  char v10; // [rsp+30h] [rbp-18h]

  v1 = this;
  v2 = (_QWORD *)this->m_pHttpRequest->vfptr[2].__vecDelDtor((OSuite::ZObject *)this->m_pHttpRequest, (unsigned int)&v9);
  if ( !*v2 && !v2[1] )
    return 1;
  v4 = ((__int64 (*)(void))v1->m_pHttpRequest->vfptr[33].__vecDelDtor)();
  v5 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 64i64))(v4);
  v6 = v1->m_pHttpRequest;
  v7 = v5;
  v8 = (__int64)v6->vfptr[2].__vecDelDtor((OSuite::ZObject *)&v6->vfptr, (unsigned int)&v10);
  return (*(__int64 (__fastcall **)(_QWORD, OSuite::IHttpRequest *, __int64))(v8 + 8))(*(_QWORD *)v8, v6, v7);
}

// File Line: 76
// RVA: 0xEDB954
void __fastcall OSuite::ZOnDataNeededHttpRequest::ZOnDataNeededHttpRequest(OSuite::ZOnDataNeededHttpRequest *this, OSuite::IHttpRequest *pHttpRequest)
{
  this->m_pHttpRequest = pHttpRequest;
  this->m_onSucessState = 8;
  this->vfptr = (OSuite::ICallback<void,void>Vtbl *)&OSuite::ZOnDataNeededHttpRequest::`vftable'{for `OSuite::ICallback<void,void>'};
  this->m_onFailureHttpError = 4;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOnStartedHttpRequest::`vftable'{for `OSuite::ZObject'};
  this->m_bReturnCode = 0;
}

// File Line: 81
// RVA: 0xEDBAF0
char __fastcall OSuite::ZOnDataNeededHttpRequest::InternalCall(OSuite::ZOnDataNeededHttpRequest *this)
{
  OSuite::ZOnDataNeededHttpRequest *v1; // rdi
  _QWORD *v2; // rax
  __int64 v4; // rax
  OSuite::IHttpRequest *v5; // rdi
  __int64 v6; // rbx
  __int64 v7; // rax
  char v8; // [rsp+20h] [rbp-28h]
  char v9; // [rsp+30h] [rbp-18h]

  v1 = this;
  v2 = (_QWORD *)this->m_pHttpRequest->vfptr[3].__vecDelDtor((OSuite::ZObject *)this->m_pHttpRequest, (unsigned int)&v8);
  if ( !*v2 && !v2[1] )
    return 1;
  v4 = ((__int64 (*)(void))v1->m_pHttpRequest->vfptr[21].__vecDelDtor)();
  v5 = v1->m_pHttpRequest;
  v6 = v4;
  v7 = (__int64)v5->vfptr[3].__vecDelDtor((OSuite::ZObject *)&v5->vfptr, (unsigned int)&v9);
  return (*(__int64 (__fastcall **)(_QWORD, OSuite::IHttpRequest *, __int64))(v7 + 8))(*(_QWORD *)v7, v5, v6);
}

// File Line: 91
// RVA: 0xEDB984
void __fastcall OSuite::ZOnFinishedHttpRequest::ZOnFinishedHttpRequest(OSuite::ZOnFinishedHttpRequest *this, OSuite::IHttpRequest *pHttpRequest)
{
  this->m_onFailureHttpError = 0;
  this->m_pHttpRequest = pHttpRequest;
  this->vfptr = (OSuite::ICallback<void,void>Vtbl *)&OSuite::ZOnFinishedHttpRequest::`vftable'{for `OSuite::ICallback<void,void>'};
  this->m_onSucessState = 1024;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZOnStartedHttpRequest::`vftable'{for `OSuite::ZObject'};
  this->m_bReturnCode = 0;
}

// File Line: 95
// RVA: 0xEDBB5C
char __fastcall OSuite::ZOnFinishedHttpRequest::InternalCall(OSuite::ZOnFinishedHttpRequest *this)
{
  OSuite::ZOnFinishedHttpRequest *v1; // rbp
  OSuite::ZUrl *v2; // rdi
  OSuite::ZUsageTrackingManager *v3; // rbx
  OSuite::ZString *v4; // rax
  const char *v5; // rax
  OSuite::ZObjectVtbl *v6; // r14
  OSuite::ZString *v7; // rax
  const char *v8; // rsi
  OSuite::IHttpRequest *v9; // rdi
  unsigned __int64 v10; // rbx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rax
  unsigned int v13; // eax
  OSuite::IHttpRequest *v14; // rdi
  unsigned int v15; // ebx
  __int64 v16; // rax
  char v18; // [rsp+20h] [rbp-18h]

  v1 = this;
  v2 = (OSuite::ZUrl *)((__int64 (*)(void))this->m_pHttpRequest->vfptr[34].__vecDelDtor)();
  if ( ((unsigned __int8 (*)(void))v1->m_pHttpRequest->vfptr[35].__vecDelDtor)() )
  {
    v3 = OSuite::TSingleton<OSuite::ZUsageTrackingManager>::Object();
    v4 = OSuite::IOnlineAuthentication::GetTicketData(v2);
    v5 = OSuite::ZString::c_str(v4);
    v6 = OSuite::ZUsageTrackingManager::GetForHost(v3, v5);
    if ( v6 )
    {
      v7 = OSuite::ZUrl::GetPath(v2);
      v8 = OSuite::ZString::c_str(v7);
      v9 = v1->m_pHttpRequest;
      v10 = ((__int64 (*)(void))v1->m_pHttpRequest->vfptr[25].__vecDelDtor)();
      v11 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v9->vfptr[26].__vecDelDtor)(v9);
      OSuite::ZUsageTracker::Record((OSuite::ZUsageTracker *)v6, v8, v11, v10);
    }
  }
  v12 = (_QWORD *)v1->m_pHttpRequest->vfptr[4].__vecDelDtor(
                    (OSuite::ZObject *)&v1->m_pHttpRequest->vfptr,
                    (unsigned int)&v18);
  if ( *v12 || v12[1] )
  {
    v13 = ((__int64 (*)(void))v1->m_pHttpRequest->vfptr[28].__vecDelDtor)();
    v14 = v1->m_pHttpRequest;
    v15 = v13;
    v16 = (__int64)v14->vfptr[4].__vecDelDtor((OSuite::ZObject *)&v1->m_pHttpRequest->vfptr, (unsigned int)&v18);
    (*(void (__fastcall **)(_QWORD, OSuite::IHttpRequest *, _QWORD))(v16 + 8))(*(_QWORD *)v16, v14, v15);
  }
  return 1;
}

