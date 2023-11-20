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
  JUMPOUT(material, 0i64, operator delete[]);
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
    result = v5;
  }
  return result;
}

// File Line: 90
// RVA: 0x2546D0
char *__fastcall UFG::LibCurlStrDup(const char *source)
{
  const char *v1; // rsi
  int v2; // eax
  int v3; // edi
  char *result; // rax
  char *v5; // rbx

  v1 = source;
  v2 = UFG::qStringLength(source);
  v3 = v2;
  result = (char *)UFG::qMalloc(v2 + 1i64, "LibCurl::StrDup", 0i64);
  v5 = result;
  if ( result )
  {
    UFG::qStringCopy(result, v3 + 1, v1, v3);
    result = v5;
  }
  return result;
}

// File Line: 334
// RVA: 0x254140
void __fastcall UFG::WebRequest::~WebRequest(UFG::WebRequest *this)
{
  UFG::WebRequest *v1; // rbx
  curl_httppost *v2; // rcx
  curl_slist *v3; // rcx
  void *v4; // rcx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v5; // rcx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v6; // rax

  v1 = this;
  v2 = this->mCurlPostBegin;
  if ( v2 )
    curl_formfree(v2);
  v3 = v1->mCurlHeader;
  if ( v3 )
  {
    curl_slist_free_all(v3);
    v1->mCurlHeader = 0i64;
  }
  v4 = v1->mCurlHandle;
  if ( v4 )
  {
    curl_easy_cleanup(v4);
    v1->mCurlHandle = 0i64;
  }
  UFG::HttpBody::~HttpBody(&v1->mResponseBody);
  UFG::HttpHeader::~HttpHeader((UFG::HttpQueryData *)&v1->mResponseHeader);
  UFG::HttpBody::~HttpBody(&v1->mRequestBody);
  UFG::HttpHeader::~HttpHeader((UFG::HttpQueryData *)&v1->mRequestHeader);
  UFG::HttpHeader::~HttpHeader(&v1->mQueryData);
  UFG::qString::~qString(&v1->mUrl);
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mPrev = (UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *)&v1->mPrev;
}

// File Line: 371
// RVA: 0x253F80
void __fastcall UFG::WebSystem::WebSystem(UFG::WebSystem *this)
{
  UFG::WebSystem *v1; // rbx
  UFG::CookieJar *v2; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::WebRequest,UFG::internalListOnly,1,0> *v3; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::WebRequest,UFG::internalListOnly,1,0> *v4; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::WebRequest,UFG::internalListOnly,1,0> *v5; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::WebRequest,UFG::internalListOnly,1,0> *v6; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->mActive = 0;
  UFG::qString::qString(&this->mUserAgentId);
  UFG::qString::qString(&v1->mProxyString);
  UFG::qString::qString(&v1->mProxyCredentials);
  v2 = &v1->mCookieJar;
  v2->mDomainList.mNode.mPrev = &v2->mDomainList.mNode;
  v2->mDomainList.mNode.mNext = &v2->mDomainList.mNode;
  *(_QWORD *)&v1->mNumberOfSuccessfulRequests = 0i64;
  UFG::qThread::qThread(&v1->mWorkerThread, "Http-WorkerThrad");
  UFG::qEvent::qEvent(&v1->mPendingEventHandle, "WebSystemEventHandle", 1);
  UFG::qMutex::qMutex(&v1->mDoneListMutex, &customWorldMapCaption);
  UFG::qMutex::qMutex(&v1->mPendingEventMutex, &customWorldMapCaption);
  v3 = &v1->mPendingList;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  v4 = &v1->mWorkingList;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v5 = &v1->mDoneList;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  v6 = &v1->mDestroyList;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
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
  bool v3; // bl
  const char *v4; // rdi
  const char *v5; // rsi
  UFG::allocator::free_link *v6; // rax
  signed __int64 v7; // rcx

  v3 = enableSSLOnly;
  v4 = proxyCredentials;
  v5 = userAgentId;
  v6 = UFG::qMalloc(0x190ui64, "WebSystem", 0i64);
  if ( v6 )
    UFG::WebSystem::WebSystem((UFG::WebSystem *)v6);
  UFG::WebSystem::sInstance = (UFG::WebSystem *)v6;
  if ( v6 )
  {
    UFG::WebSystem::InitializeProxySettings((UFG::WebSystem *)v6);
    v7 = 3i64;
    if ( v3 )
      v7 = 1i64;
    curl_global_init_mem(
      v7,
      UFG::LibCurlAlloc,
      UFG::LibCurlFree,
      UFG::LibCurlRealloc,
      UFG::LibCurlStrDup,
      UFG::LibCurlCalloc,
      -2i64);
    UFG::qString::Set(&UFG::WebSystem::sInstance->mUserAgentId, v5);
    UFG::qThread::SetName((ANTLR3_TOKEN_STREAM_struct *)&UFG::WebSystem::sInstance->mWorkerThread, &unk_1416D0B48);
    UFG::WebSystem::sInstance->mActive = 1;
    UFG::qString::Set(&UFG::WebSystem::sInstance->mProxyCredentials, v4);
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
  UFG::WebSystem *v2; // rdi
  _RTL_CRITICAL_SECTION *v3; // rbx
  __int64 *v4; // rdx
  __int64 v5; // rcx
  __int64 *v6; // rax
  __int64 *v7; // rax
  UFG::WebRequest *i; // rbx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v9; // rcx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v10; // rax
  void (__fastcall *v11)(UFG::WebRequest *, void *); // rax
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v12; // rax
  UFG::WebRequest *v13; // rbx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v14; // rdx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v15; // rax
  UFG::WebRequest *j; // rbx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v17; // rdx
  UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *v18; // rax
  __int64 *v19; // rcx
  UFG::WebRequest *v20; // rax
  __int64 *v21; // [rsp+28h] [rbp-20h]
  UFG::WebRequest *v22; // [rsp+30h] [rbp-18h]

  v2 = this;
  v21 = (__int64 *)&v21;
  v22 = (UFG::WebRequest *)&v21;
  v3 = (_RTL_CRITICAL_SECTION *)&this->mDoneListMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mDoneListMutex);
  for ( ; (UFG::qList<UFG::WebRequest,UFG::internalListOnly,1,0> *)v2->mDoneList.mNode.mNext != &v2->mDoneList; v21 = v4 )
  {
    v4 = (__int64 *)v2->mDoneList.mNode.mNext;
    v5 = *v4;
    v6 = (__int64 *)v4[1];
    *(_QWORD *)(v5 + 8) = v6;
    *v6 = v5;
    *v4 = (__int64)v4;
    v4[1] = (__int64)v4;
    v7 = v21;
    v21[1] = (__int64)v4;
    *v4 = (__int64)v7;
    v4[1] = (__int64)&v21;
  }
  UFG::qMutex::Unlock(v3);
  for ( i = v22; v22 != (UFG::WebRequest *)&v21; i = v22 )
  {
    v9 = i->mPrev;
    v10 = i->mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    i->mPrev = (UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *)&i->mPrev;
    if ( i->mResponseCode == 200 )
      ++v2->mNumberOfSuccessfulRequests;
    else
      ++v2->mNumberOfErrors;
    v11 = i->mCallback;
    if ( v11 )
    {
      v11(i, i->mUserData);
      if ( (UFG::WebRequest *)i->mPrev == i && (UFG::WebRequest *)i->mNext == i )
      {
        v12 = v2->mDestroyList.mNode.mPrev;
        v12->mNext = (UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *)&i->mPrev;
        i->mPrev = v12;
        i->mNext = &v2->mDestroyList.mNode;
        v2->mDestroyList.mNode.mPrev = (UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *)&i->mPrev;
      }
    }
  }
  while ( (UFG::qList<UFG::WebRequest,UFG::internalListOnly,1,0> *)v2->mDestroyList.mNode.mNext != &v2->mDestroyList )
  {
    v13 = (UFG::WebRequest *)v2->mDestroyList.mNode.mNext;
    v14 = v13->mPrev;
    v15 = v13->mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v13->mPrev = (UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *)&v13->mPrev;
    v13->mNext = (UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *)&v13->mPrev;
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
    j->mPrev = (UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *)&j->mPrev;
    j->mNext = (UFG::qNode<UFG::WebRequest,UFG::internalListOnly> *)&j->mPrev;
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
void __fastcall UFG::WebSystem::ThreadFunction(void *param)
{
  char *v1; // r12
  __int64 v2; // r13
  UFG::qEvent *v3; // rax
  signed __int64 v4; // rsi
  __int64 *v5; // r15
  __int64 *v6; // rsi
  __int64 v7; // rcx
  _QWORD *v8; // rax
  __int64 v9; // rax
  __int64 i; // rax
  __int64 *v11; // rsi
  __int64 v12; // rcx
  unsigned int v13; // er8
  __int64 v14; // rbp
  __int64 v15; // rax
  __int64 v16; // rcx
  _QWORD *v17; // rax
  __int64 v18; // rax
  __int64 *v19; // r14
  __int64 *v20; // rsi
  __int64 v21; // rcx
  _QWORD *v22; // rax
  __int64 v23; // rax
  int v24; // [rsp+90h] [rbp+8h]
  int v25; // [rsp+98h] [rbp+10h]
  char *v26; // [rsp+A0h] [rbp+18h]
  char *v27; // [rsp+A8h] [rbp+20h]

  v1 = (char *)param;
  v2 = curl_multi_init();
  if ( *v1 )
  {
    v3 = (UFG::qEvent *)(v1 + 216);
    v4 = (signed __int64)(v1 + 336);
    v5 = (__int64 *)(v1 + 352);
    do
    {
      UFG::qEvent::Wait(v3);
      v25 = 0;
      do
      {
        v26 = v1 + 288;
        UFG::qMutex::Lock((LPCRITICAL_SECTION)(v1 + 288));
        if ( *(_QWORD *)(v4 + 8) != v4 )
        {
          v6 = (__int64 *)*((_QWORD *)v1 + 43);
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
        UFG::qMutex::Unlock((LPCRITICAL_SECTION)(v1 + 288));
        curl_multi_perform(v2, &v25);
        curl_multi_wait(v2, 0i64, 0i64, 1000i64, 0i64);
        v24 = 0;
        for ( i = curl_multi_info_read(v2, &v24); i; i = curl_multi_info_read(v2, &v24) )
        {
          if ( *(_DWORD *)i == 1 )
          {
            v11 = (__int64 *)*((_QWORD *)v1 + 45);
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
                    UFG::qPrintf(unk_1416D0B78, v11[10]);
                    *((_DWORD *)v11 + 26) = 2;
                    break;
                  case 5u:
                    UFG::qPrintf(unk_1416D0B98, v11[10]);
                    *((_DWORD *)v11 + 26) = 3;
                    break;
                  case 6u:
                    UFG::qPrintf(unk_1416D0BC8, v11[10]);
                    *((_DWORD *)v11 + 26) = 4;
                    break;
                  case 7u:
                    UFG::qPrintf(unk_1416D0BF8, v11[10]);
                    *((_DWORD *)v11 + 26) = 5;
                    break;
                  default:
                    v14 = v11[10];
                    v15 = curl_easy_strerror(v13);
                    UFG::qPrintf(unk_1416D0C20, v15, v14);
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
              v27 = v1 + 240;
              UFG::qMutex::Lock((LPCRITICAL_SECTION)v1 + 6);
              v18 = *((_QWORD *)v1 + 46);
              *(_QWORD *)(v18 + 8) = v11;
              *v11 = v18;
              v11[1] = (__int64)(v1 + 368);
              *((_QWORD *)v1 + 46) = v11;
              UFG::qMutex::Unlock((LPCRITICAL_SECTION)v1 + 6);
            }
          }
LABEL_27:
          ;
        }
        v4 = (signed __int64)(v1 + 336);
      }
      while ( v25 );
      UFG::qMutex::Lock((LPCRITICAL_SECTION)v1 + 6);
      if ( *((char **)v1 + 45) != v1 + 352 )
      {
        v19 = (__int64 *)(v1 + 368);
        do
        {
          v20 = (__int64 *)*((_QWORD *)v1 + 45);
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
        while ( *((char **)v1 + 45) != v1 + 352 );
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)v1 + 6);
      v4 = (signed __int64)(v1 + 336);
      v3 = (UFG::qEvent *)(v1 + 216);
    }
    while ( *v1 );
  }
  curl_multi_cleanup(v2);
}

// File Line: 814
// RVA: 0x2544E0
void __fastcall UFG::WebSystem::InitializeProxySettings(UFG::WebSystem *this)
{
  UFG::WebSystem *v1; // rbx
  wchar_t *v2; // rax
  const char *v3; // rdx
  wchar_t *v4; // rcx
  UFG::ConvertW2A v5; // [rsp+28h] [rbp-38h]
  WINHTTP_CURRENT_USER_IE_PROXY_CONFIG pProxyConfig; // [rsp+38h] [rbp-28h]

  v1 = this;
  if ( !WinHttpGetIEProxyConfigForCurrentUser(&pProxyConfig) )
  {
    GetLastError();
    return;
  }
  v2 = pProxyConfig.lpszAutoConfigUrl;
  if ( pProxyConfig.fAutoDetect && pProxyConfig.lpszAutoConfigUrl )
  {
    UFG::ConvertW2A::ConvertW2A(&v5, pProxyConfig.lpszAutoConfigUrl);
    v3 = "false";
    if ( pProxyConfig.fAutoDetect )
      v3 = "true";
    UFG::qPrintf(unk_1416D0C40, v3);
    UFG::qPrintf(unk_1416D0C78, v5.m_pStringA);
    UFG::qString::Set(&v1->mProxyString, v5.m_pStringA);
    goto LABEL_9;
  }
  if ( pProxyConfig.lpszProxy )
  {
    UFG::ConvertW2A::ConvertW2A(&v5, pProxyConfig.lpszProxy);
    UFG::qPrintf(unk_1416D0CB8, v5.m_pStringA);
    UFG::qString::Set(&v1->mProxyString, v5.m_pStringA);
LABEL_9:
    UFG::ConvertW2A::~ConvertW2A(&v5);
    v2 = pProxyConfig.lpszAutoConfigUrl;
  }
  v4 = pProxyConfig.lpszProxyBypass;
  if ( pProxyConfig.lpszProxyBypass )
  {
    UFG::ConvertW2A::ConvertW2A(&v5, pProxyConfig.lpszProxyBypass);
    UFG::qPrintf(unk_1416D0CF0, v5.m_pStringA);
    UFG::ConvertW2A::~ConvertW2A(&v5);
    v4 = pProxyConfig.lpszProxyBypass;
    v2 = pProxyConfig.lpszAutoConfigUrl;
  }
  if ( v2 )
  {
    GlobalFree(v2);
    v4 = pProxyConfig.lpszProxyBypass;
  }
  if ( pProxyConfig.lpszProxy )
  {
    GlobalFree(pProxyConfig.lpszProxy);
    v4 = pProxyConfig.lpszProxyBypass;
  }
  if ( v4 )
    GlobalFree(v4);
}

