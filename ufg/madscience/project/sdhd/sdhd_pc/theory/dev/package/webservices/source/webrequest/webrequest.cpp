// File Line: 62
// RVA: 0x254640
UFG::allocator::free_link *__fastcall UFG::LibCurlAlloc(unsigned __int64 size)
{
  return UFG::qMalloc(size, "LibCurl::Malloc", 0i64);
}

// File Line: 67
// RVA: 0x2546B0
void __fastcall UFG::LibCurlFree(Illusion::Material *material)
{
  if ( material )
    operator delete[](material);
}

// File Line: 75
// RVA: 0x2546C0
UFG::allocator::free_link *__fastcall UFG::LibCurlRealloc(void *ptr, unsigned __int64 size)
{
  return UFG::qRealloc(ptr, size, "LibCurl::Realloc", 0i64);
}

// File Line: 80
// RVA: 0x254650
UFG::allocator::free_link *__fastcall UFG::LibCurlCalloc(unsigned __int64 num, unsigned __int64 size)
{
  int v2; // esi
  int v3; // edi
  UFG::allocator::free_link *result; // rax
  UFG::allocator::free_link *v5; // rbx

  v2 = num;
  v3 = size;
  result = UFG::qMalloc(size * num, "LibCurl::Calloc", 0i64);
  v5 = result;
  if ( result )
  {
    UFG::qMemSet(result, 0, v2 * v3);
    return v5;
  }
  return result;
}

// File Line: 90
// RVA: 0x2546D0
char *__fastcall UFG::LibCurlStrDup(char *source)
{
  int v2; // edi
  char *result; // rax
  char *v4; // rbx

  v2 = UFG::qStringLength(source);
  result = (char *)UFG::qMalloc(v2 + 1i64, "LibCurl::StrDup", 0i64);
  v4 = result;
  if ( result )
  {
    UFG::qStringCopy(result, v2 + 1, source, v2);
    return v4;
  }
  return result;
}

// File Line: 334
// RVA: 0x254140
void __fastcall UFG::WebRequest::~WebRequest(UFG::WebRequest *this)
{
  curl_httppost *mCurlPostBegin; // rcx
  curl_slist *mCurlHeader; // rcx
  void *mCurlHandle; // rcx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *mPrev; // rcx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *mNext; // rax

  mCurlPostBegin = this->mCurlPostBegin;
  if ( mCurlPostBegin )
    curl_formfree(mCurlPostBegin);
  mCurlHeader = this->mCurlHeader;
  if ( mCurlHeader )
  {
    curl_slist_free_all(mCurlHeader);
    this->mCurlHeader = 0i64;
  }
  mCurlHandle = this->mCurlHandle;
  if ( mCurlHandle )
  {
    curl_easy_cleanup(mCurlHandle);
    this->mCurlHandle = 0i64;
  }
  UFG::HttpBody::~HttpBody(&this->mResponseBody);
  UFG::HttpHeader::~HttpHeader((UFG::HttpQueryData *)&this->mResponseHeader);
  UFG::HttpBody::~HttpBody(&this->mRequestBody);
  UFG::HttpHeader::~HttpHeader((UFG::HttpQueryData *)&this->mRequestHeader);
  UFG::HttpHeader::~HttpHeader(&this->mQueryData);
  UFG::qString::~qString(&this->mUrl);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 371
// RVA: 0x253F80
void __fastcall UFG::WebSystem::WebSystem(UFG::WebSystem *this)
{
  this->mActive = 0;
  UFG::qString::qString(&this->mUserAgentId);
  UFG::qString::qString(&this->mProxyString);
  UFG::qString::qString(&this->mProxyCredentials);
  this->mCookieJar.mDomainList.mNode.mPrev = &this->mCookieJar.mDomainList.mNode;
  this->mCookieJar.mDomainList.mNode.mNext = &this->mCookieJar.mDomainList.mNode;
  *(_QWORD *)&this->mNumberOfSuccessfulRequests = 0i64;
  UFG::qThread::qThread(&this->mWorkerThread, "Http-WorkerThrad");
  UFG::qEvent::qEvent(&this->mPendingEventHandle, "WebSystemEventHandle", 1);
  UFG::qMutex::qMutex(&this->mDoneListMutex, &customCaption);
  UFG::qMutex::qMutex(&this->mPendingEventMutex, &customCaption);
  this->mPendingList.mNode.mPrev = &this->mPendingList.mNode;
  this->mPendingList.mNode.mNext = &this->mPendingList.mNode;
  this->mWorkingList.mNode.mPrev = &this->mWorkingList.mNode;
  this->mWorkingList.mNode.mNext = &this->mWorkingList.mNode;
  this->mDoneList.mNode.mPrev = &this->mDoneList.mNode;
  this->mDoneList.mNode.mNext = &this->mDoneList.mNode;
  this->mDestroyList.mNode.mPrev = &this->mDestroyList.mNode;
  this->mDestroyList.mNode.mNext = &this->mDestroyList.mNode;
}

// File Line: 379
// RVA: 0x254630
UFG::WebSystem *__fastcall UFG::WebSystem::Instance()
{
  return UFG::WebSystem::sInstance;
}

// File Line: 385
// RVA: 0x2543C0
void __fastcall UFG::WebSystem::Init(const char *userAgentId, const char *proxyCredentials, bool enableSSLOnly)
{
  UFG::allocator::free_link *v6; // rax
  __int64 v7; // rcx

  v6 = UFG::qMalloc(0x190ui64, "WebSystem", 0i64);
  if ( v6 )
    UFG::WebSystem::WebSystem((UFG::WebSystem *)v6);
  UFG::WebSystem::sInstance = (UFG::WebSystem *)v6;
  if ( v6 )
  {
    UFG::WebSystem::InitializeProxySettings((UFG::WebSystem *)v6);
    v7 = 3i64;
    if ( enableSSLOnly )
      v7 = 1i64;
    curl_global_init_mem(
      v7,
      UFG::LibCurlAlloc,
      UFG::LibCurlFree,
      UFG::LibCurlRealloc,
      UFG::LibCurlStrDup,
      UFG::LibCurlCalloc,
      -2i64);
    UFG::qString::Set(&UFG::WebSystem::sInstance->mUserAgentId, userAgentId);
    UFG::qThread::SetName((ANTLR3_TOKEN_STREAM_struct *)&UFG::WebSystem::sInstance->mWorkerThread, &unk_1416D0B48);
    UFG::WebSystem::sInstance->mActive = 1;
    UFG::qString::Set(&UFG::WebSystem::sInstance->mProxyCredentials, proxyCredentials);
    UFG::qThread::Start(
      &UFG::WebSystem::sInstance->mWorkerThread,
      UFG::WebSystem::ThreadFunction,
      UFG::WebSystem::sInstance);
  }
}

// File Line: 421
// RVA: 0x254AA0
void __fastcall UFG::WebSystem::Update(UFG::WebSystem *this, float elapsed)
{
  _RTL_CRITICAL_SECTION *p_mDoneListMutex; // rbx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *mNext; // rdx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *mPrev; // rcx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v6; // rax
  __int64 *v7; // rax
  UFG::WebRequest *i; // rbx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v9; // rcx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v10; // rax
  void (__fastcall *mCallback)(UFG::WebRequest *, void *); // rax
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v12; // rax
  UFG::WebRequest *v13; // rbx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v14; // rdx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v15; // rax
  UFG::WebRequest *j; // rbx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v17; // rdx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v18; // rax
  __int64 *v19; // rcx
  UFG::WebRequest *v20; // rax
  __int64 *v21; // [rsp+28h] [rbp-20h] BYREF
  UFG::WebRequest *v22; // [rsp+30h] [rbp-18h]

  v21 = (__int64 *)&v21;
  v22 = (UFG::WebRequest *)&v21;
  p_mDoneListMutex = (_RTL_CRITICAL_SECTION *)&this->mDoneListMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mDoneListMutex);
  for ( ;
        (UFG::qList<UFG::WebRequest,UFG::internalListOnly,1,0> *)this->mDoneList.mNode.mNext != &this->mDoneList;
        v21 = (__int64 *)mNext )
  {
    mNext = this->mDoneList.mNode.mNext;
    mPrev = mNext->mPrev;
    v6 = mNext->mNext;
    mPrev->mNext = v6;
    v6->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    v7 = v21;
    v21[1] = (__int64)mNext;
    mNext->mPrev = (UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *)v7;
    mNext->mNext = (UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *)&v21;
  }
  UFG::qMutex::Unlock(p_mDoneListMutex);
  for ( i = v22; v22 != (UFG::WebRequest *)&v21; i = v22 )
  {
    v9 = i->mPrev;
    v10 = i->mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    i->mPrev = i;
    i->mNext = i;
    if ( i->mResponseCode == Resp_200_OK )
      ++this->mNumberOfSuccessfulRequests;
    else
      ++this->mNumberOfErrors;
    mCallback = i->mCallback;
    if ( mCallback )
    {
      mCallback(i, i->mUserData);
      if ( i->mPrev == i && i->mNext == i )
      {
        v12 = this->mDestroyList.mNode.mPrev;
        v12->mNext = i;
        i->mPrev = v12;
        i->mNext = &this->mDestroyList.mNode;
        this->mDestroyList.mNode.mPrev = i;
      }
    }
  }
  while ( (UFG::qList<UFG::WebRequest,UFG::internalListOnly,1,0> *)this->mDestroyList.mNode.mNext != &this->mDestroyList )
  {
    v13 = (UFG::WebRequest *)this->mDestroyList.mNode.mNext;
    v14 = v13->mPrev;
    v15 = v13->mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v13->mPrev = v13;
    v13->mNext = v13;
    if ( v13->mIsBeingClosed || v13->mAutoClose )
    {
      UFG::WebRequest::~WebRequest(v13);
      operator delete[](v13);
    }
  }
  for ( j = v22; v22 != (UFG::WebRequest *)&v21; j = v22 )
  {
    v17 = j->mPrev;
    v18 = j->mNext;
    v17->mNext = v18;
    v18->mPrev = v17;
    j->mPrev = j;
    j->mNext = j;
    UFG::WebRequest::~WebRequest(j);
    operator delete[](j);
  }
  v19 = v21;
  v20 = v22;
  v21[1] = (__int64)v22;
  v20->mPrev = (UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *)v19;
}

// File Line: 777
// RVA: 0x254730
void __fastcall UFG::WebSystem::ThreadFunction(char *param)
{
  __int64 v2; // r13
  UFG::qEvent *v3; // rax
  char **v4; // rsi
  __int64 *v5; // r15
  __int64 *v6; // rsi
  __int64 v7; // rcx
  _QWORD *v8; // rax
  __int64 v9; // rax
  __int64 i; // rax
  __int64 *v11; // rsi
  __int64 v12; // rcx
  unsigned int v13; // r8d
  const char *v14; // rbp
  const char *v15; // rax
  __int64 v16; // rcx
  _QWORD *v17; // rax
  __int64 v18; // rax
  __int64 *v19; // r14
  __int64 *v20; // rsi
  __int64 v21; // rcx
  _QWORD *v22; // rax
  __int64 v23; // rax
  int v24; // [rsp+90h] [rbp+8h] BYREF
  int v25; // [rsp+98h] [rbp+10h] BYREF
  char *v26; // [rsp+A0h] [rbp+18h]
  char *v27; // [rsp+A8h] [rbp+20h]

  v2 = curl_multi_init();
  if ( *param )
  {
    v3 = (UFG::qEvent *)(param + 216);
    v4 = (char **)(param + 336);
    v5 = (__int64 *)(param + 352);
    do
    {
      UFG::qEvent::Wait(v3);
      v25 = 0;
      do
      {
        v26 = param + 288;
        UFG::qMutex::Lock((LPCRITICAL_SECTION)(param + 288));
        if ( v4[1] != (char *)v4 )
        {
          v6 = (__int64 *)*((_QWORD *)param + 43);
          v7 = *v6;
          v8 = (_QWORD *)v6[1];
          *(_QWORD *)(v7 + 8) = v8;
          *v8 = v7;
          *v6 = (__int64)v6;
          v6[1] = (__int64)v6;
          curl_multi_add_handle(v2, v6[3]);
          v9 = *v5;
          *(_QWORD *)(v9 + 8) = v6;
          *v6 = v9;
          v6[1] = (__int64)v5;
          *v5 = (__int64)v6;
        }
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)(param + 288));
        curl_multi_perform(v2, &v25);
        curl_multi_wait(v2, 0i64, 0i64, 1000i64, 0i64);
        v24 = 0;
        for ( i = curl_multi_info_read(v2, &v24); i; i = curl_multi_info_read(v2, &v24) )
        {
          if ( *(_DWORD *)i == 1 )
          {
            v11 = (__int64 *)*((_QWORD *)param + 45);
            if ( v11 != v5 )
            {
              v12 = *(_QWORD *)(i + 8);
              while ( v11[3] != v12 )
              {
                v11 = (__int64 *)v11[1];
                if ( v11 == v5 )
                  goto LABEL_27;
              }
              v13 = *(_DWORD *)(i + 16);
              if ( v13 )
              {
                switch ( v13 )
                {
                  case 1u:
                    *((_DWORD *)v11 + 26) = 1;
                    break;
                  case 3u:
                    UFG::qPrintf("Curl Error: URL Malformed (%s)\n", (const char *)v11[10]);
                    *((_DWORD *)v11 + 26) = 2;
                    break;
                  case 5u:
                    UFG::qPrintf("Curl Error: could not resolve proxy (%s)\n", (const char *)v11[10]);
                    *((_DWORD *)v11 + 26) = 3;
                    break;
                  case 6u:
                    UFG::qPrintf("Curl Error: could not resolve host (%s)\n", (const char *)v11[10]);
                    *((_DWORD *)v11 + 26) = 4;
                    break;
                  case 7u:
                    UFG::qPrintf("Curl Error: could not connect (%s)\n", (const char *)v11[10]);
                    *((_DWORD *)v11 + 26) = 5;
                    break;
                  default:
                    v14 = (const char *)v11[10];
                    v15 = (const char *)curl_easy_strerror(v13);
                    UFG::qPrintf("Curl Error: failed: %s (%s)\n", v15, v14);
                    *((_DWORD *)v11 + 26) = 6;
                    break;
                }
              }
              else
              {
                curl_easy_getinfo(v12, 2097154i64, v11 + 13);
              }
              curl_multi_remove_handle(v2, v11[3]);
              v16 = *v11;
              v17 = (_QWORD *)v11[1];
              *(_QWORD *)(v16 + 8) = v17;
              *v17 = v16;
              *v11 = (__int64)v11;
              v11[1] = (__int64)v11;
              v11[49] = UFG::qGetTicks();
              v27 = param + 240;
              UFG::qMutex::Lock((LPCRITICAL_SECTION)param + 6);
              v18 = *((_QWORD *)param + 46);
              *(_QWORD *)(v18 + 8) = v11;
              *v11 = v18;
              v11[1] = (__int64)(param + 368);
              *((_QWORD *)param + 46) = v11;
              UFG::qMutex::Unlock((LPCRITICAL_SECTION)param + 6);
            }
          }
LABEL_27:
          ;
        }
        v4 = (char **)(param + 336);
      }
      while ( v25 );
      UFG::qMutex::Lock((LPCRITICAL_SECTION)param + 6);
      if ( *((char **)param + 45) != param + 352 )
      {
        v19 = (__int64 *)(param + 368);
        do
        {
          v20 = (__int64 *)*((_QWORD *)param + 45);
          v21 = *v20;
          v22 = (_QWORD *)v20[1];
          *(_QWORD *)(v21 + 8) = v22;
          *v22 = v21;
          *v20 = (__int64)v20;
          v20[1] = (__int64)v20;
          v20[49] = UFG::qGetTicks();
          v23 = *v19;
          *(_QWORD *)(v23 + 8) = v20;
          *v20 = v23;
          v20[1] = (__int64)v19;
          *v19 = (__int64)v20;
        }
        while ( *((char **)param + 45) != param + 352 );
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)param + 6);
      v4 = (char **)(param + 336);
      v3 = (UFG::qEvent *)(param + 216);
    }
    while ( *param );
  }
  curl_multi_cleanup(v2);
}

// File Line: 814
// RVA: 0x2544E0
void __fastcall UFG::WebSystem::InitializeProxySettings(UFG::WebSystem *this)
{
  wchar_t *lpszAutoConfigUrl; // rax
  const char *v3; // rdx
  wchar_t *lpszProxyBypass; // rcx
  UFG::ConvertW2A v5; // [rsp+28h] [rbp-38h] BYREF
  WINHTTP_CURRENT_USER_IE_PROXY_CONFIG pProxyConfig; // [rsp+38h] [rbp-28h] BYREF

  if ( !WinHttpGetIEProxyConfigForCurrentUser(&pProxyConfig) )
  {
    GetLastError();
    return;
  }
  lpszAutoConfigUrl = pProxyConfig.lpszAutoConfigUrl;
  if ( pProxyConfig.fAutoDetect && pProxyConfig.lpszAutoConfigUrl )
  {
    UFG::ConvertW2A::ConvertW2A(&v5, pProxyConfig.lpszAutoConfigUrl);
    v3 = "false";
    if ( pProxyConfig.fAutoDetect )
      v3 = "true";
    UFG::qPrintf("WinHttpGetIEProxyConfigForCurrentUser.fAutoDetect : %s\n", v3);
    UFG::qPrintf("WinHttpGetIEProxyConfigForCurrentUser.lpszAutoConfigUrl : %s\n", v5.m_pStringA);
    UFG::qString::Set(&this->mProxyString, v5.m_pStringA);
    goto LABEL_9;
  }
  if ( pProxyConfig.lpszProxy )
  {
    UFG::ConvertW2A::ConvertW2A(&v5, pProxyConfig.lpszProxy);
    UFG::qPrintf("WinHttpGetIEProxyConfigForCurrentUser.lpszProxy : %s\n", v5.m_pStringA);
    UFG::qString::Set(&this->mProxyString, v5.m_pStringA);
LABEL_9:
    UFG::ConvertW2A::~ConvertW2A(&v5);
    lpszAutoConfigUrl = pProxyConfig.lpszAutoConfigUrl;
  }
  lpszProxyBypass = pProxyConfig.lpszProxyBypass;
  if ( pProxyConfig.lpszProxyBypass )
  {
    UFG::ConvertW2A::ConvertW2A(&v5, pProxyConfig.lpszProxyBypass);
    UFG::qPrintf("WinHttpGetIEProxyConfigForCurrentUser.lpszProxyBypass : %s\n", v5.m_pStringA);
    UFG::ConvertW2A::~ConvertW2A(&v5);
    lpszProxyBypass = pProxyConfig.lpszProxyBypass;
    lpszAutoConfigUrl = pProxyConfig.lpszAutoConfigUrl;
  }
  if ( lpszAutoConfigUrl )
  {
    GlobalFree(lpszAutoConfigUrl);
    lpszProxyBypass = pProxyConfig.lpszProxyBypass;
  }
  if ( pProxyConfig.lpszProxy )
  {
    GlobalFree(pProxyConfig.lpszProxy);
    lpszProxyBypass = pProxyConfig.lpszProxyBypass;
  }
  if ( lpszProxyBypass )
    GlobalFree(lpszProxyBypass);
}

