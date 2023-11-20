// File Line: 23
// RVA: 0x15ADE40
__int64 OSuite::_dynamic_initializer_for__m_EncryptedAppTicketCBRes__()
{
  return atexit(OSuite::_dynamic_atexit_destructor_for__m_EncryptedAppTicketCBRes__);
}

// File Line: 35
// RVA: 0xA37040
__int64 __fastcall OSuite::ZGameInterface::PlatformInit(OSuite::ZGameInterface *this, const char *gameUrl, OSuite::IGameConfig *__formal)
{
  OSuite::ZGameInterface *v3; // rdi
  const char *v4; // rbx
  HINTERNET v5; // rax
  void *v6; // rsi
  HINTERNET v7; // rax
  __int64 v8; // rcx
  OSuite::AuthenticationManager *v9; // rax
  WSAData WSAData; // [rsp+30h] [rbp-1A8h]

  v3 = this;
  v4 = gameUrl;
  v5 = InternetOpenA("OS GameUrl TEST", 0, 0i64, 0i64, 0);
  v6 = v5;
  v7 = InternetOpenUrlA(v5, v4, 0i64, 0, 0, 1ui64);
  if ( v7 )
    InternetCloseHandle(v7);
  InternetCloseHandle(v6);
  v3->m_bInitSuccess = OSuite::psock::LoadRootCertitificates(POLICY_ACCEPT_CA_ONLY);
  if ( WSAStartup(0x202u, &WSAData) || WSAData.wVersion != 514 )
    WSACleanup();
  else
    OSuite::g_NetInitialized = 1;
  OSuite::g_SteamInitialized = SteamAPI_Init(v8);
  v9 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
  OSuite::AuthenticationManager::SetInitialized(v9, OSuite::g_SteamInitialized);
  v3->m_bInitSuccess = v3->m_bInitSuccess && OSuite::g_NetInitialized && OSuite::g_SteamInitialized;
  return 0i64;
}

// File Line: 79
// RVA: 0xA372B0
void __fastcall OSuite::ZGameInterface::Update(OSuite::ZGameInterface *this)
{
  SteamAPI_RunCallbacks(this);
}

// File Line: 84
// RVA: 0xA37150
__int64 __fastcall OSuite::ZGameInterface::PlatformShutdown(OSuite::ZGameInterface *this)
{
  if ( OSuite::g_SteamInitialized )
    SteamAPI_Shutdown(this);
  if ( OSuite::g_NetInitialized )
    WSACleanup();
  return 0i64;
}

// File Line: 97
// RVA: 0xA36D30
const char *__fastcall OSuite::ZGameInterface::GetSteamShopURL(OSuite::ZGameInterface *this)
{
  return OSuite::g_SteamShopUrl;
}

// File Line: 112
// RVA: 0xA37180
void __fastcall OSuite::ZGameInterface::RequestTicket(OSuite::ZGameInterface *this, OSuite::IOnlineAuthentication::AuthState *eState, OSuite::fastdelegate::FastDelegate2<enum OSuite::IOnlineAuthentication::AuthState,OSuite::IOnlineAuthentication::AuthTicket,void> *cb)
{
  OSuite::IOnlineAuthentication::AuthState *v3; // rdi
  OSuite::ZGameInterface *v4; // rsi
  __int64 v5; // rax
  __int64 *v6; // rbx
  __int64 *v7; // rax
  __int64 v8; // r9
  unsigned __int64 v9; // rbx
  __int64 v10; // [rsp+40h] [rbp+18h]
  char v11; // [rsp+48h] [rbp+20h]

  v3 = eState;
  v4 = this;
  OSuite::m_cb.m_Closure.m_pFunction = cb->m_Closure.m_pFunction;
  OSuite::m_cb.m_Closure.m_pthis = cb->m_Closure.m_pthis;
  v5 = SteamUser(this, eState);
  v6 = (__int64 *)v5;
  if ( v5 )
  {
    v7 = (__int64 *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v5 + 16i64))(v5, &v11);
    v8 = *v6;
    v10 = *v7;
    v9 = (*(__int64 (__fastcall **)(__int64 *, __int64 *, signed __int64))(v8 + 160))(v6, &v10, 8i64);
    if ( OSuite::m_EncryptedAppTicketCBRes.m_hAPICall )
      SteamAPI_UnregisterCallResult(&OSuite::m_EncryptedAppTicketCBRes);
    OSuite::m_EncryptedAppTicketCBRes.m_hAPICall = v9;
    OSuite::m_EncryptedAppTicketCBRes.m_pObj = v4;
    OSuite::m_EncryptedAppTicketCBRes.m_Func = OSuite::ZGameInterface::OnRequestEncryptedAppTicketCB;
    if ( v9 )
      SteamAPI_RegisterCallResult(&OSuite::m_EncryptedAppTicketCBRes, v9);
    *v3 = 1;
  }
  else
  {
    *v3 = 0;
  }
}

// File Line: 135
// RVA: 0xA36E30
void __fastcall OSuite::ZGameInterface::OnRequestEncryptedAppTicketCB(OSuite::ZGameInterface *this, EncryptedAppTicketResponse_t *pEncryptedAppTicketResponse, bool bIOFailure)
{
  bool v3; // bl
  EncryptedAppTicketResponse_t *v4; // rsi
  OSuite::IOnlineAuthentication::AuthState v5; // edi
  __int64 v6; // rdx
  __int64 v7; // rbx
  void *v8; // rsi
  OSuite::ZString *v9; // rax
  int v10; // ecx
  OSuite::ZString *v11; // rax
  OSuite::ZString that; // [rsp+20h] [rbp-81h]
  int v13; // [rsp+48h] [rbp-59h]
  unsigned __int64 nLength; // [rsp+4Ch] [rbp-55h]
  __int64 v15; // [rsp+68h] [rbp-39h]
  OSuite::ZString v16; // [rsp+70h] [rbp-31h]
  OSuite::ZString v17; // [rsp+88h] [rbp-19h]
  int v18; // [rsp+A0h] [rbp-1h]
  int v19; // [rsp+A4h] [rbp+3h]
  OSuite::ZString v20; // [rsp+A8h] [rbp+7h]
  OSuite::ZString v21; // [rsp+C0h] [rbp+1Fh]
  OSuite::ZString result; // [rsp+D8h] [rbp+37h]
  unsigned __int64 nNumber; // [rsp+120h] [rbp+7Fh]

  v15 = -2i64;
  v3 = bIOFailure;
  v4 = pEncryptedAppTicketResponse;
  v5 = 0;
  OSuite::ZString::ZString(&that);
  OSuite::ZString::ZString((OSuite::ZString *)((char *)&that + 16));
  OSuite::ZString::ZString((OSuite::ZString *)((char *)&nLength + 4));
  if ( !v3 && v4->m_eResult == 1 )
  {
    v7 = SteamUser((unsigned int)(v4->m_eResult - 1), v6);
    if ( v7 )
    {
      v8 = OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, 1024ui64, 0i64);
      memset(v8, 0, 0x400ui64);
      v5 = 3;
      (*(void (__fastcall **)(__int64, void *, signed __int64, unsigned __int64 *))(*(_QWORD *)v7 + 168i64))(
        v7,
        v8,
        1024i64,
        &nLength);
      v9 = OSuite::ZMimeEntity::Base64Encode(&result, v8, (unsigned int)nLength);
      OSuite::ZString::operator=((OSuite::ZString *)((char *)&that + 16), v9);
      OSuite::ZString::~ZString(&result);
      v13 = 1;
      (*(void (__fastcall **)(__int64, unsigned __int64 *))(*(_QWORD *)v7 + 16i64))(v7, &nNumber);
      v10 = (HIDWORD(nNumber) >> 20) & 0xF;
      if ( (unsigned int)(v10 - 1) <= 9
        && (unsigned int)((SHIDWORD(nNumber) >> 24) - 1) <= 3
        && (v10 != 1 || (_DWORD)nNumber && (HIDWORD(nNumber) & 0xFFFFFu) <= 4)
        && (v10 != 7 || (_DWORD)nNumber && !(nNumber & 0xFFFFF00000000i64))
        && (v10 != 3 || (_DWORD)nNumber) )
      {
        OSuite::ZString::ZString(&v21, nNumber);
        OSuite::ZString::operator=(&that, v11);
        OSuite::ZString::~ZString(&v21);
      }
      OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, v8);
    }
  }
  nNumber = (unsigned __int64)&v16;
  OSuite::ZString::ZString(&v16, &that);
  OSuite::ZString::ZString(&v17, (OSuite::ZString *)((char *)&that + 16));
  v18 = v13;
  v19 = nLength;
  OSuite::ZString::ZString(&v20, (OSuite::ZString *)((char *)&nLength + 4));
  OSuite::fastdelegate::FastDelegate2<enum  OSuite::IOnlineAuthentication::AuthState,OSuite::IOnlineAuthentication::AuthTicket,void>::operator()(
    &OSuite::m_cb,
    v5,
    (OSuite::IOnlineAuthentication::AuthTicket *)&v16);
  OSuite::ZString::~ZString((OSuite::ZString *)((char *)&nLength + 4));
  OSuite::ZString::~ZString((OSuite::ZString *)((char *)&that + 16));
  OSuite::ZString::~ZString(&that);
}

// File Line: 209
// RVA: 0xA36D00
__int64 __fastcall OSuite::ZGameInterface::GetAppID(OSuite::ZGameInterface *this)
{
  __int64 result; // rax
  __int64 v2; // rcx
  __int64 v3; // rax

  result = SteamUtils(this);
  if ( result )
  {
    v3 = SteamUtils(v2);
    result = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v3 + 72i64))(v3);
  }
  return result;
}

