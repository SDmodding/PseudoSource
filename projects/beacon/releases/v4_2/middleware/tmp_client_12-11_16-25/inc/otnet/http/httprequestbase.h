// File Line: 24
// RVA: 0xEDC18C
OSuite::fastdelegate::FastDelegate1<OSuite::IHttpRequest *,bool> *__fastcall OSuite::ZHttpRequestBase::GetOnStartedCB(
        OSuite::ZHttpRequestBase *this,
        OSuite::fastdelegate::FastDelegate1<OSuite::IHttpRequest *,bool> *result)
{
  result->m_Closure.m_pthis = 0i64;
  result->m_Closure.m_pFunction = 0i64;
  *result = this->m_OnStartedCB;
  return result;
}

// File Line: 25
// RVA: 0xEDC138
OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest *,OSuite::IBufferedReader *,bool> *__fastcall OSuite::ZHttpRequestBase::GetOnDataAvailableCB(
        OSuite::ZHttpRequestBase *this,
        OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest *,OSuite::IBufferedReader *,bool> *result)
{
  result->m_Closure.m_pthis = 0i64;
  result->m_Closure.m_pFunction = 0i64;
  *result = this->m_OnDataAvailableCB;
  return result;
}

// File Line: 26
// RVA: 0xEDC154
OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest *,unsigned __int64,bool> *__fastcall OSuite::ZHttpRequestBase::GetOnDataNeededCB(
        OSuite::ZHttpRequestBase *this,
        OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest *,unsigned __int64,bool> *result)
{
  result->m_Closure.m_pthis = 0i64;
  result->m_Closure.m_pFunction = 0i64;
  *result = this->m_OnDataNeededCB;
  return result;
}

// File Line: 27
// RVA: 0xEDC170
OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest *,enum OSuite::ZHttp::EError,bool> *__fastcall OSuite::ZHttpRequestBase::GetOnFinishedCB(
        OSuite::ZHttpRequestBase *this,
        OSuite::fastdelegate::FastDelegate2<OSuite::IHttpRequest *,enum OSuite::ZHttp::EError,bool> *result)
{
  result->m_Closure.m_pthis = 0i64;
  result->m_Closure.m_pFunction = 0i64;
  *result = this->m_OnFinishedCB;
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
OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *__fastcall OSuite::ZHttpRequestBase::GetHeaders(
        OSuite::ZHttpRequestBase *this)
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
  OSuite::ZString::operator=(&this->m_acceptType, pAcceptType);
  OSuite::ZString::~ZString(pAcceptType);
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
  OSuite::ZString::operator=(&this->m_contentType, pContentType);
  OSuite::ZString::~ZString(pContentType);
}

// File Line: 54
// RVA: 0xEDCA94
void __fastcall OSuite::ZHttpRequestBase::SetLengthToSend(
        OSuite::ZHttpRequestBase *this,
        unsigned __int64 nLengthToSend)
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
  OSuite::ZString::operator=(&this->m_method, pMethod);
  OSuite::ZString::~ZString(pMethod);
}

// File Line: 57
// RVA: 0xEDCAD0
void __fastcall OSuite::ZHttpRequestBase::SetUrl(OSuite::ZHttpRequestBase *this, OSuite::ZUrl *url)
{
  OSuite::ZUrl::operator=(&this->m_url, url);
}

// File Line: 58
// RVA: 0xEDCB94
void __fastcall OSuite::ZHttpRequestBase::ThrottleBandwidth(
        OSuite::ZHttpRequestBase *this,
        unsigned __int64 nBytesPerSecond)
{
  this->m_nMaxBytesPerSecond = nBytesPerSecond;
}

// File Line: 63
// RVA: 0xEDBDA8
void __fastcall OSuite::ZHttpRequestBase::~ZHttpRequestBase(OSuite::ZHttpRequestBase *this)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *p_m_clientHeaders; // rcx

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZHttpRequestBase::`vftable;
  p_m_clientHeaders = &this->m_clientHeaders;
  p_m_clientHeaders->vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable;
  p_m_clientHeaders->m_Comparer.OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > >::vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  p_m_clientHeaders->m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::ZObject};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase(p_m_clientHeaders);
  this->m_headers.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TRedBlackTree<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZString>,1,OSuite::TKeyValueElementComparer<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>>::`vftable;
  this->m_headers.m_Comparer.vfptr = (OSuite::IComparer<OSuite::ZString>Vtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::IComparer<OSuite::ZString>};
  this->m_headers.m_Comparer.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TOperatorComparer<OSuite::ZString>::`vftable{for `OSuite::ZObject};
  OSuite::ZRedBlackTreeBase::~ZRedBlackTreeBase(&this->m_headers);
  OSuite::ZString::~ZString(&this->m_contentType);
  OSuite::ZString::~ZString(&this->m_acceptType);
  OSuite::ZString::~ZString(&this->m_method);
  OSuite::ZMemoryBufferChain::~ZMemoryBufferChain(&this->m_bufferChain);
  OSuite::ZMutex::~ZMutex(&this->m_StateMutex);
  OSuite::ZUrl::~ZUrl(&this->m_url);
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::IHttpRequest::`vftable;
}

