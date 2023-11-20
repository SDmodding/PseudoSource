// File Line: 23
// RVA: 0xED5394
void __fastcall OSuite::ZInternalAtomEntryDelegate::ZInternalAtomEntryDelegate(OSuite::ZInternalAtomEntryDelegate *this, OSuite::ZAtomEntry *pAtomEntry, OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *progressDelegate, OSuite::SCallbackData *status)
{
  OSuite::ZAtomEntry *v4; // rsi
  OSuite::ZInternalAtomEntryDelegate *v5; // r14
  OSuite::ZUrl *v6; // rcx
  OSuite::SCallbackData *v7; // rbx
  OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *v8; // rdi

  v4 = pAtomEntry;
  v5 = this;
  this->vfptr = (OSuite::ICallback<void,void>Vtbl *)&OSuite::ZInternalAtomEntryDelegate::`vftable{for `OSuite::ICallback<void,void>};
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZInternalAtomEntryDelegate::`vftable{for `OSuite::ZObject};
  v6 = &this->m_Status.URL;
  v6[-1].m_urlParameters.m_arrayParameters.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)status->Status;
  v7 = status;
  v6[-1].m_nPort = status->eEvent;
  v8 = progressDelegate;
  OSuite::ZUrl::ZUrl(v6, &status->URL);
  OSuite::TList<OSuite::OSError>::TList<OSuite::OSError>(&v5->m_Status.OSErrors, &v7->OSErrors);
  v5->m_delegate.m_Closure.m_pthis = 0i64;
  v5->m_delegate.m_Closure.m_pFunction = 0i64;
  v5->m_delegate.m_Closure.m_pFunction = v8->m_Closure.m_pFunction;
  v5->m_delegate.m_Closure.m_pthis = v8->m_Closure.m_pthis;
  v5->m_pAtomEntry = v4;
}

// File Line: 28
// RVA: 0xED5654
void __fastcall OSuite::ZInternalAtomEntryDelegate::Call(OSuite::ZInternalAtomEntryDelegate *this)
{
  ((void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *, OSuite::SCallbackData *))this->m_delegate.m_Closure.m_pFunction)(
    this->m_delegate.m_Closure.m_pthis,
    &this->m_Status);
}

// File Line: 32
// RVA: 0x15D8B24
__int64 dynamic_initializer_for__OSuite::ZAtomEntry::s_nClassId__()
{
  __int64 result; // rax

  result = OSuite::ZAtomBase::GenerateClassId();
  OSuite::ZAtomEntry::s_nClassId = result;
  return result;
}

// File Line: 37
// RVA: 0xED5440
void __fastcall OSuite::MimeUploadRequest::~MimeUploadRequest(OSuite::MimeUploadRequest *this)
{
  OSuite::MimeUploadRequest *v1; // rbx
  bool v2; // zf
  OSuite::IReader *v3; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::MimeUploadRequest::`vftable;
  OSuite::ZMimeMultipartEntity::~ZMimeMultipartEntity(&this->m_mime);
  v2 = v1->m_readerOwnership == 0;
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomEntry::UploadRequest::`vftable;
  if ( !v2 )
  {
    v3 = v1->m_pAttachment;
    if ( v3 )
      v3->vfptr->__vecDelDtor(v3, 1u);
  }
  OSuite::ZUtf8Buffer::~ZUtf8Buffer((OSuite::ZStringBuilder *)&v1->m_entrycontent);
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomEntry::Request::`vftable;
  OSuite::SCallbackData::~SCallbackData(&v1->m_CbData);
}

// File Line: 48
// RVA: 0xED52C8
void __fastcall OSuite::ZAtomEntry::ZAtomEntry(OSuite::ZAtomEntry *this, OSuite::ZUrl *sFeedUrl)
{
  OSuite::ZUrl *v2; // rdi
  OSuite::ZAtomEntry *v3; // rsi
  int v4; // eax
  OSuite::ZString *v5; // rax
  OSuite::ZString result; // [rsp+20h] [rbp-28h]

  v2 = sFeedUrl;
  v3 = this;
  OSuite::ZAtomBase::ZAtomBase((OSuite::ZAtomBase *)&this->vfptr);
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomEntry::`vftable;
  OSuite::ZMutex::ZMutex(&v3->m_currentRequestMutex);
  OSuite::ZString::ZString(&v3->m_ETag);
  OSuite::ZString::ZString(&v3->m_sContentUrl);
  OSuite::ZString::ZString(&v3->m_sSummary);
  OSuite::ZString::ZString(&v3->m_sContent);
  OSuite::ZUrl::ToString(v2, &v3->m_sFeedURL, 0);
  v3->m_eState = 0;
  v3->m_pCurrentRequest = 0i64;
  v4 = OSuite::ZString::LastIndexOf(&v3->m_sFeedURL, 47);
  v5 = OSuite::ZString::Slice(&v3->m_sFeedURL, &result, 0i64, v4 + 1);
  OSuite::ZString::operator=(&v3->m_sBaseURL, v5);
  OSuite::ZString::~ZString(&result);
}

// File Line: 55
// RVA: 0xED54AC
void __fastcall OSuite::ZAtomEntry::~ZAtomEntry(OSuite::ZAtomEntry *this)
{
  OSuite::ZAtomEntry *v1; // rbx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZAtomEntry::`vftable;
  OSuite::ZAtomEntry::AbortCurrentOperation(this);
  OSuite::ZString::~ZString(&v1->m_sFeedURL);
  OSuite::ZString::~ZString(&v1->m_sContent);
  OSuite::ZString::~ZString(&v1->m_sSummary);
  OSuite::ZString::~ZString(&v1->m_sContentUrl);
  OSuite::ZString::~ZString(&v1->m_ETag);
  OSuite::ZMutex::~ZMutex(&v1->m_currentRequestMutex);
  OSuite::ZAtomBase::~ZAtomBase((OSuite::ZAtomBase *)&v1->vfptr);
}

// File Line: 105
// RVA: 0xED5680
bool __fastcall OSuite::ZAtomEntry::HasConcurrency(OSuite::ZAtomEntry *this)
{
  return OSuite::ZString::Count(&this->m_ETag) != 0;
}

// File Line: 112
// RVA: 0xED5678
OSuite::ZString *__fastcall OSuite::ZAtomEntry::Concurrency(OSuite::ZAtomEntry *this)
{
  return &this->m_ETag;
}

// File Line: 119
// RVA: 0xED6158
void __fastcall OSuite::ZAtomEntry::SetConcurrency(OSuite::ZAtomEntry *this, OSuite::ZString *concurrencyTag)
{
  OSuite::ZString::operator=(&this->m_ETag, concurrencyTag);
}

// File Line: 132
// RVA: 0xED60C0
void __fastcall OSuite::ZAtomEntry::PostTo(OSuite::ZAtomEntry *this, OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *callback, OSuite::IReader *pAttachment)
{
  OSuite::ZAtomEntry *v3; // rdi
  OSuite::IReader *v4; // rbp
  OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *v5; // rsi
  OSuite::ZAtomEntry::UploadRequest *v6; // rax
  OSuite::ZAtomEntry::UploadRequest *v7; // rbx

  v3 = this;
  this->m_eState = 3;
  v4 = pAttachment;
  v5 = callback;
  v6 = (OSuite::ZAtomEntry::UploadRequest *)OSuite::ZObject::operator new(0x190ui64);
  v7 = v6;
  if ( v6 )
  {
    OSuite::ZAtomEntry::UploadRequest::UploadRequest(v6, v4, 0i64);
    v7->vfptr = (OSuite::ZObjectVtbl *)&OSuite::MimeUploadRequest::`vftable;
    OSuite::ZMimeMultipartEntity::ZMimeMultipartEntity((OSuite::ZMimeMultipartEntity *)&v7[1]);
  }
  else
  {
    v7 = 0i64;
  }
  v7->m_clientCallback.m_Closure.m_pFunction = v5->m_Closure.m_pFunction;
  v7->m_clientCallback.m_Closure.m_pthis = v5->m_Closure.m_pthis;
  v3->vfptr[8].__vecDelDtor((OSuite::ZObject *)&v3->vfptr, (unsigned int)v7);
}

// File Line: 143
// RVA: 0xED6164
void __fastcall OSuite::ZAtomEntry::Update(OSuite::ZAtomEntry *this, OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *callback, OSuite::IReader *pAttachment)
{
  OSuite::ZAtomEntry *v3; // rbx
  OSuite::IReader *v4; // rsi
  OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *v5; // rdi
  OSuite::ZAtomEntry::UploadRequest *v6; // rax
  __int64 v7; // rdx
  __int64 v8; // rax

  v3 = this;
  this->m_eState = 3;
  v4 = pAttachment;
  v5 = callback;
  v6 = (OSuite::ZAtomEntry::UploadRequest *)OSuite::ZObject::operator new(0x170ui64);
  v7 = 0i64;
  if ( v6 )
  {
    OSuite::ZAtomEntry::UploadRequest::UploadRequest(v6, v4, 0i64);
    v7 = v8;
  }
  *(_QWORD *)(v7 + 288) = v5->m_Closure.m_pFunction;
  *(_QWORD *)(v7 + 280) = v5->m_Closure.m_pthis;
  ((void (__fastcall *)(OSuite::ZAtomEntry *))v3->vfptr[7].__vecDelDtor)(v3);
}

// File Line: 164
// RVA: 0xED55E8
void __fastcall OSuite::ZAtomEntry::AbortCurrentOperation(OSuite::ZAtomEntry *this)
{
  OSuite::IHttpRequest *v1; // rdi
  OSuite::ZAtomEntry *v2; // rbx
  OSuite::ZHttpManager *v3; // rax
  void (__fastcall ***v4)(_QWORD, signed __int64); // rax

  v1 = this->m_pCurrentRequest;
  v2 = this;
  if ( v1 )
  {
    v3 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
    if ( OSuite::ZHttpRequestManager::ShutdownHttpRequest(v3->m_httpRequestManager, v1) )
    {
      v4 = (void (__fastcall ***)(_QWORD, signed __int64))((__int64 (__fastcall *)(OSuite::IHttpRequest *))v1->vfptr[30].__vecDelDtor)(v1);
      if ( v4 )
        (**v4)(v4, 1i64);
    }
  }
  v2->m_pCurrentRequest = 0i64;
  v2->m_eState = 1;
}

// File Line: 179
// RVA: 0xED604C
bool __fastcall OSuite::ZAtomEntry::ParseError(OSuite::ZAtomEntry *this, OSuite::SHttpStatus *pStatus, OSuite::IHttpRequest *pHttpRequest)
{
  OSuite::IHttpRequest *v3; // rsi
  OSuite::SHttpStatus *v4; // rdi
  OSuite::ZAtomEntry *v5; // rbp
  __int64 v6; // rax

  v3 = pHttpRequest;
  v4 = pStatus;
  v5 = this;
  if ( pStatus )
  {
    v6 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[33].__vecDelDtor)(pHttpRequest);
    v4->nHttpStatus = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 32i64))(v6);
    v4->eError = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v3->vfptr[28].__vecDelDtor)(v3);
  }
  v5->m_eState = v4->eError == 0;
  return v4->eError == 0;
}

// File Line: 196
// RVA: 0xED566C
bool __fastcall OSuite::ZAtomEntry::ClassMatch(OSuite::ZAtomEntry *this, int nClassId)
{
  return OSuite::ZAtomEntry::s_nClassId == nClassId;
}

// File Line: 202
// RVA: 0xED5AC0
char __fastcall OSuite::ZAtomEntry::InternalUpdate(OSuite::ZAtomEntry *this, OSuite::ZAtomEntry::UploadRequest *pRequest)
{
  OSuite::ZAtomEntry *v2; // rsi
  OSuite::ZAtomEntry::UploadRequest *v3; // r14
  OSuite::ZHttpManager *v4; // rax
  OSuite::IHttpRequest *v5; // rax
  OSuite::IHttpRequest v6; // rbx
  __int64 v7; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v8; // rax
  OSuite::IHttpRequest *v9; // rdi
  OSuite::ZString *v10; // rbx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v11; // rax
  OSuite::ZObjectVtbl *v12; // rbx
  __int64 v13; // rax
  OSuite::ZObjectVtbl *v14; // rbx
  __int64 v15; // rax
  OSuite::ZObjectVtbl *v16; // rbx
  unsigned __int64 v17; // rax
  OSuite::IHttpRequest *v18; // rcx
  OSuite::ZString key; // [rsp+30h] [rbp-D0h]
  OSuite::ZDateTime v21; // [rsp+48h] [rbp-B8h]
  __int64 v22; // [rsp+60h] [rbp-A0h]
  __int64 v23; // [rsp+68h] [rbp-98h]
  OSuite::ZAtomEntry *v24; // [rsp+70h] [rbp-90h]
  bool (__fastcall *v25)(OSuite::ZAtomEntry *, OSuite::IHttpRequest *, unsigned __int64); // [rsp+78h] [rbp-88h]
  OSuite::ZAtomEntry *v26; // [rsp+80h] [rbp-80h]
  bool (__fastcall *v27)(OSuite::ZAtomEntry *, OSuite::IHttpRequest *, OSuite::ZHttp::EError); // [rsp+88h] [rbp-78h]
  char v28; // [rsp+90h] [rbp-70h]
  OSuite::ZUrl result; // [rsp+A0h] [rbp-60h]

  v2 = this;
  this->m_eState = 3;
  v3 = pRequest;
  v22 = 0i64;
  OSuite::ZJsonDocument::ZJsonDocument((OSuite::ZJsonDocument *)&v21.m_nYear);
  OSuite::ZDateTime::ZDateTime(&v21);
  ((void (__fastcall *)(OSuite::ZAtomEntry *, int *, signed __int64))v2->vfptr[2].__vecDelDtor)(v2, &v21.m_nYear, 4i64);
  OSuite::ZJsonSerializer::Serialize(
    (OSuite::ZJsonSerializer *)&v21,
    &v3->m_entrycontent,
    (OSuite::ZJsonDocument *)&v21.m_nYear);
  OSuite::ZJsonSerializer::~ZJsonSerializer(&v21);
  OSuite::ZJsonDocument::~ZJsonDocument((OSuite::ZJsonDocument *)&v21.m_nYear);
  result.m_sProtocol.m_pString = 0i64;
  result.m_sHost.m_pString = 0i64;
  result.m_sFakeHost.m_pString = 0i64;
  result.m_sPath.m_pString = 0i64;
  result.m_urlParameters.m_parameters.m_pTop = 0i64;
  result.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
  OSuite::ZAtomBase::EditURL((OSuite::ZAtomBase *)&v2->vfptr, &result);
  v4 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::CreateHttpRequest(v4->m_httpRequestManager, &result, v2, 1, 30);
  v2->m_pCurrentRequest = v5;
  v6.vfptr = v5->vfptr;
  OSuite::ZString::ZString((OSuite::ZString *)&v21.m_nYear, "PUT");
  v6.vfptr[44].__vecDelDtor((OSuite::ZObject *)&v2->m_pCurrentRequest->vfptr, v7);
  OSuite::ZString::ZString((OSuite::ZString *)&v21.m_nYear, "PUT");
  OSuite::ZString::ZString(&key, "X-HTTP-Method-Override");
  v8 = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *)((__int64 (*)(void))v2->m_pCurrentRequest->vfptr[27].__vecDelDtor)();
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    v8,
    &key,
    (OSuite::ZString *)&v21.m_nYear);
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::~ZString((OSuite::ZString *)&v21.m_nYear);
  if ( ((unsigned __int8 (__fastcall *)(OSuite::ZAtomEntry *))v2->vfptr[4].__vecDelDtor)(v2) )
  {
    OSuite::ZString::ZString((OSuite::ZString *)&v21.m_nYear, "If-Match");
    v9 = v2->m_pCurrentRequest;
    v10 = (OSuite::ZString *)((__int64 (__fastcall *)(OSuite::ZAtomEntry *))v2->vfptr[5].__vecDelDtor)(v2);
    v11 = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *)((__int64 (__fastcall *)(OSuite::IHttpRequest *))v9->vfptr[27].__vecDelDtor)(v9);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      v11,
      (OSuite::ZString *)&v21.m_nYear,
      v10);
    OSuite::ZString::~ZString((OSuite::ZString *)&v21.m_nYear);
  }
  v12 = v2->m_pCurrentRequest->vfptr;
  OSuite::ZString::ZString((OSuite::ZString *)&v21.m_nYear, "application/json");
  v12[36].__vecDelDtor((OSuite::ZObject *)&v2->m_pCurrentRequest->vfptr, v13);
  v14 = v2->m_pCurrentRequest->vfptr;
  OSuite::ZString::ZString((OSuite::ZString *)&v21.m_nYear, "application/json");
  v14[41].__vecDelDtor((OSuite::ZObject *)&v2->m_pCurrentRequest->vfptr, v15);
  v16 = v2->m_pCurrentRequest->vfptr;
  v17 = OSuite::ZStringBuilder::Count((OSuite::ZStringBuilder *)&v3->m_entrycontent);
  v16[42].__vecDelDtor((OSuite::ZObject *)&v2->m_pCurrentRequest->vfptr, v17);
  v2->m_pCurrentRequest->vfptr[43].__vecDelDtor((OSuite::ZObject *)&v2->m_pCurrentRequest->vfptr, (unsigned int)v3);
  OSuite::ZUrl::operator=(&v3->m_CbData.URL, &result);
  *(_QWORD *)&v21.m_nDate = 0i64;
  v25 = OSuite::ZAtomEntry::OnDataNeeded;
  *(_QWORD *)&v21.m_nYear = 0i64;
  v27 = OSuite::ZAtomEntry::OnUpdateFinished;
  v18 = v2->m_pCurrentRequest;
  v23 = 0i64;
  v22 = 0i64;
  v24 = v2;
  v26 = v2;
  v28 = 0;
  v18->vfptr[6].__vecDelDtor((OSuite::ZObject *)&v18->vfptr, (unsigned int)&v21.m_nYear);
  OSuite::ZUrl::~ZUrl(&result);
  return 1;
}

// File Line: 242
// RVA: 0xED58B4
char __fastcall OSuite::ZAtomEntry::InternalPostTo(OSuite::ZAtomEntry *this, OSuite::ZAtomEntry::UploadRequest *pRequest)
{
  OSuite::ZAtomEntry *v2; // r14
  OSuite::ZAtomEntry::UploadRequest *v3; // rsi
  OSuite::ZHttpManager *v4; // rax
  OSuite::IHttpRequest *v5; // rax
  OSuite::ZObjectVtbl *v6; // rbx
  __int64 v7; // rax
  OSuite::ZObjectVtbl *v8; // rbx
  __int64 v9; // rax
  OSuite::ZObjectVtbl *v10; // rbx
  __int64 v11; // rax
  OSuite::ZObjectVtbl *v12; // rbx
  unsigned __int64 v13; // rax
  OSuite::ZUrl *v14; // rax
  OSuite::IHttpRequest *v15; // rcx
  OSuite::ZUrl url; // [rsp+30h] [rbp-D0h]
  OSuite::ZDateTime v18; // [rsp+108h] [rbp+8h]
  __int64 v19; // [rsp+120h] [rbp+20h]
  __int64 v20; // [rsp+128h] [rbp+28h]
  OSuite::ZAtomEntry *v21; // [rsp+130h] [rbp+30h]
  bool (__fastcall *v22)(OSuite::ZAtomEntry *, OSuite::IHttpRequest *, unsigned __int64); // [rsp+138h] [rbp+38h]
  OSuite::ZAtomEntry *v23; // [rsp+140h] [rbp+40h]
  bool (__fastcall *v24)(OSuite::ZAtomEntry *, OSuite::IHttpRequest *, OSuite::ZHttp::EError); // [rsp+148h] [rbp+48h]
  char v25; // [rsp+150h] [rbp+50h]

  v2 = this;
  this->m_eState = 4;
  v3 = pRequest;
  OSuite::ZDateTime::ZDateTime(&v18);
  v19 = 0i64;
  OSuite::ZJsonDocument::ZJsonDocument((OSuite::ZJsonDocument *)&v18.m_nYear);
  ((void (__fastcall *)(OSuite::ZAtomEntry *, int *, signed __int64))v2->vfptr[2].__vecDelDtor)(v2, &v18.m_nYear, 2i64);
  OSuite::ZJsonSerializer::Serialize(
    (OSuite::ZJsonSerializer *)&v18,
    &v3->m_entrycontent,
    (OSuite::ZJsonDocument *)&v18.m_nYear);
  OSuite::ZJsonDocument::~ZJsonDocument((OSuite::ZJsonDocument *)&v18.m_nYear);
  OSuite::ZJsonSerializer::~ZJsonSerializer(&v18);
  OSuite::ZUrl::ZUrl(&url, &v2->m_sFeedURL);
  v4 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::CreateHttpRequest(v4->m_httpRequestManager, &url, v2, 1, 30);
  v2->m_pCurrentRequest = v5;
  OSuite::ZUrl::~ZUrl(&url);
  v6 = v2->m_pCurrentRequest->vfptr;
  OSuite::ZString::ZString((OSuite::ZString *)&v18.m_nYear, "POST");
  v6[44].__vecDelDtor((OSuite::ZObject *)&v2->m_pCurrentRequest->vfptr, v7);
  v8 = v2->m_pCurrentRequest->vfptr;
  OSuite::ZString::ZString((OSuite::ZString *)&v18.m_nYear, "application/json");
  v8[36].__vecDelDtor((OSuite::ZObject *)&v2->m_pCurrentRequest->vfptr, v9);
  v10 = v2->m_pCurrentRequest->vfptr;
  OSuite::ZString::ZString((OSuite::ZString *)&v18.m_nYear, "application/json");
  v10[41].__vecDelDtor((OSuite::ZObject *)&v2->m_pCurrentRequest->vfptr, v11);
  v12 = v2->m_pCurrentRequest->vfptr;
  v13 = OSuite::ZStringBuilder::Count((OSuite::ZStringBuilder *)&v3->m_entrycontent);
  v12[42].__vecDelDtor((OSuite::ZObject *)&v2->m_pCurrentRequest->vfptr, v13);
  v2->m_pCurrentRequest->vfptr[43].__vecDelDtor((OSuite::ZObject *)&v2->m_pCurrentRequest->vfptr, (unsigned int)v3);
  v14 = (OSuite::ZUrl *)((__int64 (*)(void))v2->m_pCurrentRequest->vfptr[34].__vecDelDtor)();
  OSuite::ZUrl::operator=(&v3->m_CbData.URL, v14);
  *(_QWORD *)&v18.m_nDate = 0i64;
  *(_QWORD *)&v18.m_nYear = 0i64;
  v20 = 0i64;
  v19 = 0i64;
  v22 = OSuite::ZAtomEntry::OnPostToDataNeeded;
  v21 = v2;
  v24 = OSuite::ZAtomEntry::OnFinished;
  v15 = v2->m_pCurrentRequest;
  v23 = v2;
  v25 = 0;
  v15->vfptr[6].__vecDelDtor((OSuite::ZObject *)&v15->vfptr, (unsigned int)&v18.m_nYear);
  return 1;
}

// File Line: 271
// RVA: 0xED569C
char __fastcall OSuite::ZAtomEntry::InternalDelete(OSuite::ZAtomEntry *this, OSuite::ZAtomEntry::Request *pRequest)
{
  OSuite::ZAtomEntry::Request *v2; // r14
  OSuite::ZAtomEntry *v3; // rsi
  OSuite::ZHttpManager *v4; // rax
  OSuite::IHttpRequest *v5; // rax
  OSuite::IHttpRequest v6; // rbx
  __int64 v7; // rax
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v8; // rax
  OSuite::IHttpRequest *v9; // rdi
  OSuite::ZString *v10; // rbx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v11; // rax
  OSuite::ZObjectVtbl *v12; // rbx
  __int64 v13; // rax
  OSuite::IHttpRequest *v14; // rcx
  OSuite::ZString value; // [rsp+30h] [rbp-D0h]
  __int64 v17; // [rsp+48h] [rbp-B8h]
  __int64 v18; // [rsp+50h] [rbp-B0h]
  __int64 v19; // [rsp+58h] [rbp-A8h]
  __int64 v20; // [rsp+60h] [rbp-A0h]
  __int64 v21; // [rsp+68h] [rbp-98h]
  __int64 v22; // [rsp+70h] [rbp-90h]
  OSuite::ZAtomEntry *v23; // [rsp+78h] [rbp-88h]
  bool (__fastcall *v24)(OSuite::ZAtomEntry *, OSuite::IHttpRequest *, OSuite::ZHttp::EError); // [rsp+80h] [rbp-80h]
  char v25; // [rsp+88h] [rbp-78h]
  OSuite::ZString key; // [rsp+90h] [rbp-70h]
  OSuite::ZUrl result; // [rsp+B0h] [rbp-50h]

  v2 = pRequest;
  v3 = this;
  this->m_eState = 2;
  result.m_sProtocol.m_pString = 0i64;
  result.m_sHost.m_pString = 0i64;
  result.m_sFakeHost.m_pString = 0i64;
  result.m_sPath.m_pString = 0i64;
  result.m_urlParameters.m_parameters.m_pTop = 0i64;
  result.m_urlParameters.m_arrayParameters.m_pTop = 0i64;
  OSuite::ZAtomBase::EditURL((OSuite::ZAtomBase *)&this->vfptr, &result);
  v4 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::CreateHttpRequest(v4->m_httpRequestManager, &result, v3, 1, 30);
  v3->m_pCurrentRequest = v5;
  v6.vfptr = v5->vfptr;
  OSuite::ZString::ZString(&value, "DELETE");
  v6.vfptr[44].__vecDelDtor((OSuite::ZObject *)&v3->m_pCurrentRequest->vfptr, v7);
  OSuite::ZString::ZString(&value, "DELETE");
  OSuite::ZString::ZString(&key, "X-HTTP-Method-Override");
  v8 = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *)((__int64 (*)(void))v3->m_pCurrentRequest->vfptr[27].__vecDelDtor)();
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
    v8,
    &key,
    &value);
  OSuite::ZString::~ZString(&key);
  OSuite::ZString::~ZString(&value);
  if ( ((unsigned __int8 (__fastcall *)(OSuite::ZAtomEntry *))v3->vfptr[4].__vecDelDtor)(v3) )
  {
    OSuite::ZString::ZString(&value, "If-Match");
    v9 = v3->m_pCurrentRequest;
    v10 = (OSuite::ZString *)((__int64 (__fastcall *)(OSuite::ZAtomEntry *))v3->vfptr[5].__vecDelDtor)(v3);
    v11 = (OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *)((__int64 (__fastcall *)(OSuite::IHttpRequest *))v9->vfptr[27].__vecDelDtor)(v9);
    OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
      v11,
      &value,
      v10);
    OSuite::ZString::~ZString(&value);
  }
  v12 = v3->m_pCurrentRequest->vfptr;
  OSuite::ZString::ZString(&value, "application/json");
  v12[36].__vecDelDtor((OSuite::ZObject *)&v3->m_pCurrentRequest->vfptr, v13);
  v3->m_pCurrentRequest->vfptr[43].__vecDelDtor((OSuite::ZObject *)&v3->m_pCurrentRequest->vfptr, (unsigned int)v2);
  OSuite::ZUrl::operator=(&v2->m_CbData.URL, &result);
  v18 = 0i64;
  v24 = OSuite::ZAtomEntry::OnFinished;
  v14 = v3->m_pCurrentRequest;
  v17 = 0i64;
  v20 = 0i64;
  v19 = 0i64;
  v22 = 0i64;
  v21 = 0i64;
  v23 = v3;
  v25 = 0;
  v14->vfptr[6].__vecDelDtor((OSuite::ZObject *)&v14->vfptr, (unsigned int)&v17);
  OSuite::ZUrl::~ZUrl(&result);
  return 1;
}

// File Line: 295
// RVA: 0xED5D98
bool __fastcall OSuite::ZAtomEntry::OnDataNeeded(OSuite::ZAtomEntry *this, OSuite::IHttpRequest *pHttpRequest, unsigned __int64 __formal)
{
  OSuite::IHttpRequest *v3; // rsi
  __int64 v4; // rax
  OSuite::ZStringBuilder *v6; // rbp
  OSuite::ZObjectVtbl *v7; // rdi
  unsigned __int64 v8; // rbx
  const void *v9; // rax

  v3 = pHttpRequest;
  if ( !this->m_pCurrentRequest )
    return 0;
  v4 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *, OSuite::IHttpRequest *, unsigned __int64))pHttpRequest->vfptr[30].__vecDelDtor)(
         pHttpRequest,
         pHttpRequest,
         __formal);
  if ( *(_QWORD *)(v4 + 304) )
    return ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v3->vfptr[13].__vecDelDtor)(v3);
  v6 = (OSuite::ZStringBuilder *)(v4 + 312);
  if ( !OSuite::ZStringBuilder::Count((OSuite::ZStringBuilder *)(v4 + 312)) )
    return 0;
  v7 = v3->vfptr;
  v8 = OSuite::ZStringBuilder::Count(v6);
  v9 = OSuite::ZUtf8Buffer::Buffer((OSuite::ZUtf8Buffer *)v6);
  return ((__int64 (__fastcall *)(OSuite::IHttpRequest *, const void *, unsigned __int64))v7[14].__vecDelDtor)(
           v3,
           v9,
           v8);
}

// File Line: 317
// RVA: 0xED5F58
bool __fastcall OSuite::ZAtomEntry::OnPostToDataNeeded(OSuite::ZAtomEntry *this, OSuite::IHttpRequest *pHttpRequest, unsigned __int64 __formal)
{
  OSuite::IHttpRequest *v3; // rbx
  __int64 v5; // rax

  v3 = pHttpRequest;
  if ( !this->m_pCurrentRequest )
    return 0;
  v5 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *, OSuite::IHttpRequest *, unsigned __int64))pHttpRequest->vfptr[30].__vecDelDtor)(
         pHttpRequest,
         pHttpRequest,
         __formal);
  return OSuite::ZMimeMultipartEntity::PostTo((OSuite::ZMimeMultipartEntity *)(v5 + 368), v3);
}

// File Line: 329
// RVA: 0xED5E2C
bool __fastcall OSuite::ZAtomEntry::OnFinished(OSuite::ZAtomEntry *this, OSuite::IHttpRequest *pHttpRequest, __int64 __formal)
{
  OSuite::IHttpRequest *v3; // r14
  OSuite::ZAtomEntry *v4; // rsi
  OSuite::ManagedCallback *v6; // rdi
  OSuite::SHttpStatus *v7; // rax
  OSuite::SCallbackData *v8; // r15
  OSuite::SHttpStatus *v9; // rbx
  bool v10; // bp
  OSuite::ZInternalAtomEntryDelegate *v11; // rax
  OSuite::ManagedCallback *v12; // rax
  OSuite::SHttpStatus *v13; // rcx
  OSuite::ZHttpManager *v14; // rax
  OSuite::ZWorker *v15; // rax
  OSuite::SHttpStatus v16; // [rsp+20h] [rbp-28h]
  OSuite::SHttpStatus v17; // [rsp+28h] [rbp-20h]

  v3 = pHttpRequest;
  v4 = this;
  if ( !this->m_pCurrentRequest )
    return 0;
  v6 = 0i64;
  v7 = (OSuite::SHttpStatus *)((__int64 (__fastcall *)(OSuite::IHttpRequest *, OSuite::IHttpRequest *, __int64))pHttpRequest->vfptr[30].__vecDelDtor)(
                                pHttpRequest,
                                pHttpRequest,
                                __formal);
  v8 = (OSuite::SCallbackData *)&v7[1];
  v9 = v7;
  v10 = OSuite::ZAtomEntry::ParseError(v4, v7 + 1, v3);
  if ( *(_QWORD *)&v9[35] || *(_QWORD *)&v9[36] )
  {
    v11 = (OSuite::ZInternalAtomEntryDelegate *)OSuite::ZObject::operator new(0x138ui64);
    if ( v11 )
    {
      v11->m_delegate.m_Closure.m_pthis = 0i64;
      v11->m_pAtomEntry = 0i64;
      v17 = v9[36];
      v16 = v9[35];
      OSuite::ZInternalAtomEntryDelegate::ZInternalAtomEntryDelegate(
        v11,
        v4,
        (OSuite::fastdelegate::FastDelegate1<OSuite::SCallbackData *,void> *)&v16,
        v8);
      v6 = v12;
    }
  }
  v13 = (OSuite::SHttpStatus *)v9[37];
  if ( v13 )
    *v13 = v8->Status;
  (**(void (__fastcall ***)(OSuite::SHttpStatus *, signed __int64))v9)(v9, 1i64);
  v3->vfptr[43].__vecDelDtor((OSuite::ZObject *)&v3->vfptr, 0);
  v14 = OSuite::TSingleton<OSuite::ZHttpManager>::Object();
  OSuite::ZHttpRequestManager::ReleaseHttpRequest(v14->m_httpRequestManager, v3);
  v4->m_pCurrentRequest = 0i64;
  if ( v6 )
  {
    v15 = OSuite::ZWorker::Instance();
    OSuite::ZWorker::AddCallback(v15, v6);
  }
  return v10;
}

// File Line: 362
// RVA: 0xED5F94
bool __fastcall OSuite::ZAtomEntry::OnUpdateFinished(OSuite::ZAtomEntry *this, OSuite::IHttpRequest *pHttpRequest, OSuite::ZHttp::EError error)
{
  OSuite::ZHttp::EError v3; // ebp
  OSuite::IHttpRequest *v4; // rdi
  OSuite::ZAtomEntry *v5; // rbx
  __int64 v7; // rsi
  OSuite::ZString *v8; // rax
  OSuite::ZString v9; // [rsp+20h] [rbp-38h]
  OSuite::ZString v10; // [rsp+38h] [rbp-20h]

  v3 = error;
  v4 = pHttpRequest;
  v5 = this;
  if ( !this->m_pCurrentRequest )
    return 0;
  v7 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[33].__vecDelDtor)(pHttpRequest);
  if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v7 + 32i64))(v7) == 204 )
  {
    OSuite::ZString::ZString(&v9, "ETag");
    v8 = (OSuite::ZString *)(*(__int64 (__fastcall **)(__int64, OSuite::ZString *, OSuite::ZString *))(*(_QWORD *)v7 + 8i64))(
                              v7,
                              &v10,
                              &v9);
    OSuite::ZString::operator=(&v5->m_ETag, v8);
    OSuite::ZString::~ZString(&v10);
    OSuite::ZString::~ZString(&v9);
  }
  return OSuite::ZAtomEntry::OnFinished(v5, v4, (unsigned int)v3);
}

