// File Line: 24
// RVA: 0xEDC18C
OSuite::fastdelegate::FastDelegate1<OSuite::IHttpRequest *,bool> *__fastcall OSuite::ZHttpRequestBase::GetOnStartedCB(OSuite::ZHttpRequestBase *this, OSuite::fastdelegate::FastDelegate1<OSuite::IHttpRequest *,bool> *result)
{
  result->m_Closure.m_pthis = 0i64;
  result->m_Closure.m_pFunction = 0i64;
  result->m_Closure.m_pFunction = this->m_OnStartedCB.m_Closure.m_pFunction;
  result->m_Closure.m_pthis = this->m_OnStartedCB.m_Closure.m_pthis;
  return result;
}

// File Line: 25
// RVA: 0xEDC138
OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest *,OSuite::IBufferedReader *,bool> *__fastcall OSuite::ZHttpRequestBase::GetOnDataAvailableCB(OSuite::ZHttpRequestBase *this, OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest *,OSuite::IBufferedReader *,bool> *result)
{
  result->m_Closure.m_pthis = 0i64;
  result->m_Closure.m_pFunction = 0i64;
  result->m_Closure.m_pFunction = this->m_OnDataAvailableCB.m_Closure.m_pFunction;
  result->m_Closure.m_pthis = this->m_OnDataAvailableCB.m_Closure.m_pthis;
  return result;
}

// File Line: 26
// RVA: 0xEDC154
OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest *,unsigned __int64,bool> *__fastcall OSuite::ZHttpRequestBase::GetOnDataNeededCB(OSuite::ZHttpRequestBase *this, OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest *,unsigned __int64,bool> *result)
{
  result->m_Closure.m_pthis = 0i64;
  result->m_Closure.m_pFunction = 0i64;
  result->m_Closure.m_pFunction = this->m_OnDataNeededCB.m_Closure.m_pFunction;
  result->m_Closure.m_pthis = this->m_OnDataNeededCB.m_Closure.m_pthis;
  return result;
}

// File Line: 27
// RVA: 0xEDC170
OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest *,enum OSuite::ZHttp::EError,bool> *__fastcall OSuite::ZHttpRequestBase::GetOnFinishedCB(OSuite::ZHttpRequestBase *this, OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest *,enum OSuite::ZHttp::EError,bool> *result)
{
  result->m_Closure.m_pthis = 0i64;
  result->m_Closure.m_pFunction = 0i64;
  result->m_Closure.m_pFunction = this->m_OnFinishedCB.m_Closure.m_pFunction;
  result->m_Closure.m_pthis = this->m_OnFinishedCB.m_Closure.m_pthis;
  return result;
}

// File Line: 35
// RVA: 0xEDC314
bool __fastcall OSuite::ZHttpRequestBase::IsClientCallback(OSuite::ZHttpRequestBase *this)
{
  return this->m_bClientCallback;
}

// File Line: 39
// RVA: 0xEDC118
__int64 __fastcall OSuite::ZHttpRequestBase::GetLastError(OSuite::ZHttpRequestBase *this)
{
  return (unsigned int)this->m_lastError;
}

// File Line: 40
// RVA: 0xEDC054
__int64 __fastcall OSuite::ZHttpRequestBase::GetAsynchState(OSuite::ZHttpRequestBase *this)
{
  return (unsigned int)this->m_asynchState;
}

// File Line: 41
// RVA: 0xEDC0D4
OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *__fastcall OSuite::ZHttpRequestBase::GetHeaders(OSuite::ZHttpRequestBase *this)
{
  return &this->m_clientHeaders;
}

// File Line: 42
// RVA: 0xEDC120
unsigned __int64 __fastcall OSuite::ZHttpRequestBase::GetLengthToSend(OSuite::ZHttpRequestBase *this)
{
  return this->m_nLengthToSend;
}

// File Line: 43
// RVA: 0xEDC128
void *__fastcall OSuite::ZHttpRequestBase::GetLinkedObject(OSuite::ZHttpRequestBase *this)
{
  return this->m_pLinkedObject;
}

// File Line: 44
// RVA: 0xEDC130
OSuite::ZMemoryBufferChain *__fastcall OSuite::ZHttpRequestBase::GetMemoryBuffer(OSuite::ZHttpRequestBase *this)
{
  return &this->m_bufferChain;
}

// File Line: 45
// RVA: 0xEDC1A8
void *__fastcall OSuite::ZHttpRequestBase::GetParent(OSuite::ZHttpRequestBase *this)
{
  return this->m_pParent;
}

// File Line: 46
// RVA: 0xEDC1D4
OSuite::ZUrl *__fastcall OSuite::ZHttpRequestBase::GetUrl(OSuite::ZHttpRequestBase *this)
{
  return &this->m_url;
}

// File Line: 47
// RVA: 0xEDC1B0
bool __fastcall OSuite::ZHttpRequestBase::GetRecordUsage(OSuite::ZHttpRequestBase *this)
{
  return this->m_bRecordUsage;
}

// File Line: 49
// RVA: 0xEDCA44
void __fastcall OSuite::ZHttpRequestBase::SetAcceptType(OSuite::ZHttpRequestBase *this, OSuite::ZString *pAcceptType)
{
  OSuite::ZString *v2; // rbx

  v2 = pAcceptType;
  OSuite::ZString::operator=(&this->m_acceptType, pAcceptType);
  OSuite::ZString::~ZString(v2);
}

// File Line: 51
// RVA: 0xEDCA68
void __fastcall OSuite::ZHttpRequestBase::SetChunkedTransfer(OSuite::ZHttpRequestBase *this, bool bTransferChunked)
{
  this->m_bTransferChunked = bTransferChunked;
}

// File Line: 52
// RVA: 0xEDCAC8
void __fastcall OSuite::ZHttpRequestBase::SetRecordUsage(OSuite::ZHttpRequestBase *this, bool bRecordUsage)
{
  this->m_bRecordUsage = bRecordUsage;
}

// File Line: 53
// RVA: 0xEDCA70
void __fastcall OSuite::ZHttpRequestBase::SetContentType(OSuite::ZHttpRequestBase *this, OSuite::ZString *pContentType)
{
  OSuite::ZString *v2; // rbx

  v2 = pContentType;
  OSuite::ZString::operator=(&this->m_contentType, pContentType);
  OSuite::ZString::~ZString(v2);
}

// File Line: 54
// RVA: 0xEDCA94
void __fastcall OSuite::ZHttpRequestBase::SetLengthToSend(OSuite::ZHttpRequestBase *this, unsigned __int64 nLengthToSend)
{
  this->m_nLengthToSend = nLengthToSend;
}

// File Line: 55
// RVA: 0xEDCA9C
void __fastcall OSuite::ZHttpRequestBase::SetLinkedObject(OSuite::ZHttpRequestBase *this, void *pLinkedObject)
{
  this->m_pLinkedObject = pLinkedObject;
}

// File Line: 56
// RVA: 0xEDCAA4
void __fastcall OSuite::ZHttpRequestBase::SetMethod(OSuite::ZHttpRequestBase *this, OSuite::ZString *pMethod)
{
  OSuite::ZString *v2; // rbx

  v2 = pMethod;
  OSuite::ZString::operator=(&this->m_method, pMethod);
  OSuite::ZString::~ZString(v2);
}

// File Line: 57
// RVA: 0xEDCAD0
void __fastcall OSuite::ZHttpRequestBase::SetUrl(OSuite::ZHttpRequestBase *this, OSuite::ZUrl *url)
{
  OSuite::ZUrl::operator=(&this->m_url, url);
}

// File Line: 58
// RVA: 0xEDCB94
void __fastcall OSuite::ZHttpRequestBase::ThrottleBandwidth(OSuite::ZHttpRequestBase *this, unsigned __int64 nBytesPerSecond)
{
  this->m_nMaxBytesPerSecond = nBytesPerSecond;
}

// File Line: 63
// RVA: 0xEDBDA8
void __fastcall OSuite::ZHttpRequestBase::~ZHttpRequestBase(OSuite::ZHttpRequestBase *this)
{
  OSuite::ZHttpRequestBase *v1; // rbx
  OSuite::ZRedBlackTreeBase *v2; // rcx
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v3; // rcx

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpRequestBase::`vftable';
  v2 = (OSuite::ZRedBlackTreeBase *)&this->m_clientHeaders.vfptr;
  v2->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable';
  v2[1].vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  v2[1].m_pTop = (OSuite::ZRedBlackTreeBase::ZElementBase *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::ZObject'};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase(v2);
  v3 = &v1->m_headers;
  v3->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable';
  v3->m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::IComparer<OSuite::ZString>'};
  v3->m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable'{for `OSuite::ZObject'};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase((OSuite::ZRedBlackTreeBase *)&v1->m_headers.vfptr);
  OSuite::ZString::~ZString(&v1->m_contentType);
  OSuite::ZString::~ZString(&v1->m_acceptType);
  OSuite::ZString::~ZString(&v1->m_method);
  OSuite::ZMemoryBufferChain::~ZMemoryBufferChain(&v1->m_bufferChain);
  OSuite::ZMutex::~ZMutex(&v1->m_StateMutex);
  OSuite::ZUrl::~ZUrl(&v1->m_url);
  v1->vfptr = (OSuite::ZObjectVtbl *)&OSuite::IHttpRequest::`vftable';
}

