// File Line: 23
// RVA: 0x15ADE40
__int64 OSuite::_dynamic_initializer_for__m_EncryptedAppTicketCBRes__()
{
  return atexit((int (__fastcall *)())OSuite::_dynamic_atexit_destructor_for__m_EncryptedAppTicketCBRes__);
}

// File Line: 35
// RVA: 0xA37040
__int64 __fastcall OSuite::ZGameInterface::PlatformInit(
        OSuite::ZGameInterface *this,
        const char *gameUrl,
        OSuite::IGameConfig *__formal)
{
  HINTERNET v5; // rsi
  HINTERNET v6; // rax
  __int64 v7; // rcx
  OSuite::AuthenticationManager *v8; // rax
  WSAData WSAData; // [rsp+30h] [rbp-1A8h] BYREF

  v5 = InternetOpenA("OS GameUrl TEST", 0, 0i64, 0i64, 0);
  v6 = InternetOpenUrlA(v5, gameUrl, 0i64, 0, 0, 1ui64);
  if ( v6 )
    InternetCloseHandle(v6);
  InternetCloseHandle(v5);
  this->m_bInitSuccess = OSuite::psock::LoadRootCertitificates(POLICY_ACCEPT_CA_ONLY);
  if ( WSAStartup(0x202u, &WSAData) || WSAData.wVersion != 514 )
    WSACleanup();
  else
    OSuite::g_NetInitialized = 1;
  OSuite::g_SteamInitialized = SteamAPI_Init(v7);
  v8 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
  OSuite::AuthenticationManager::SetInitialized(v8, OSuite::g_SteamInitialized);
  this->m_bInitSuccess = this->m_bInitSuccess && OSuite::g_NetInitialized && OSuite::g_SteamInitialized;
  return 0i64;
}

// File Line: 79
// RVA: 0xA372B0
// attributes: thunk
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
void __fastcall OSuite::ZGameInterface::RequestTicket(
        OSuite::ZGameInterface *this,
        OSuite::IOnlineAuthentication::AuthState *eState,
        OSuite::fastdelegate::FastDelegate2<enum OSuite::IOnlineAuthentication::AuthState,OSuite::IOnlineAuthentication::AuthTicket,void> *cb)
{
  __int64 v5; // rax
  __int64 *v6; // rbx
  __int64 *v7; // rax
  __int64 v8; // r9
  unsigned __int64 v9; // rbx
  __int64 v10; // [rsp+40h] [rbp+18h] BYREF
  char v11; // [rsp+48h] [rbp+20h] BYREF

  OSuite::m_cb = *cb;
  v5 = SteamUser(this, eState);
  v6 = (__int64 *)v5;
  if ( v5 )
  {
    v7 = (__int64 *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v5 + 16i64))(v5, &v11);
    v8 = *v6;
    v10 = *v7;
    v9 = (*(__int64 (__fastcall **)(__int64 *, __int64 *, __int64))(v8 + 160))(v6, &v10, 8i64);
    if ( OSuite::m_EncryptedAppTicketCBRes.m_hAPICall )
      SteamAPI_UnregisterCallResult(&OSuite::m_EncryptedAppTicketCBRes);
    OSuite::m_EncryptedAppTicketCBRes.m_hAPICall = v9;
    OSuite::m_EncryptedAppTicketCBRes.m_pObj = this;
    OSuite::m_EncryptedAppTicketCBRes.m_Func = OSuite::ZGameInterface::OnRequestEncryptedAppTicketCB;
    if ( v9 )
      SteamAPI_RegisterCallResult(&OSuite::m_EncryptedAppTicketCBRes, v9);
    *eState = AUTH_STATE_TICKET_WAITING;
  }
  else
  {
    *eState = AUTH_STATE_TICKET_NOT_FOUND;
  }
}

// File Line: 135
// RVA: 0xA36E30
void __fastcall OSuite::ZGameInterface::OnRequestEncryptedAppTicketCB(
        OSuite::ZGameInterface *this,
        EncryptedAppTicketResponse_t *pEncryptedAppTicketResponse,
        bool bIOFailure)
{
  unsigned int v5; // edi
  __int64 v6; // rdx
  __int64 v7; // rbx
  void *v8; // rsi
  OSuite::ZString *v9; // rax
  int v10; // ecx
  OSuite::ZString *v11; // rax
  OSuite::ZString that; // [rsp+20h] [rbp-81h] BYREF
  OSuite::IOnlineAuthentication::AuthProvider v13; // [rsp+48h] [rbp-59h]
  _DWORD nLength[7]; // [rsp+4Ch] [rbp-55h] BYREF
  __int64 v15; // [rsp+68h] [rbp-39h]
  OSuite::IOnlineAuthentication::AuthTicket v16; // [rsp+70h] [rbp-31h] BYREF
  OSuite::ZString v17; // [rsp+C0h] [rbp+1Fh] BYREF
  OSuite::ZString result; // [rsp+D8h] [rbp+37h] BYREF
  unsigned __int64 nNumber; // [rsp+120h] [rbp+7Fh] BYREF

  v15 = -2i64;
  v5 = 0;
  OSuite::ZString::ZString(&that);
  OSuite::ZString::ZString((OSuite::ZString *)&that.m_pString);
  OSuite::ZString::ZString((OSuite::ZString *)&nLength[1]);
  if ( !bIOFailure && pEncryptedAppTicketResponse->m_eResult == k_EResultOK )
  {
    v7 = SteamUser((unsigned int)(pEncryptedAppTicketResponse->m_eResult - 1), v6);
    if ( v7 )
    {
      v8 = (void *)OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, 1024i64, 0i64);
      memset(v8, 0, 0x400ui64);
      v5 = 3;
      (*(void (__fastcall **)(__int64, void *, __int64, _DWORD *))(*(_QWORD *)v7 + 168i64))(v7, v8, 1024i64, nLength);
      v9 = OSuite::ZMimeEntity::Base64Encode(&result, v8, nLength[0]);
      OSuite::ZString::operator=((OSuite::ZString *)&that.m_pString, v9);
      OSuite::ZString::~ZString(&result);
      v13 = AUTH_PROVIDER_STEAM;
      (*(void (__fastcall **)(__int64, unsigned __int64 *))(*(_QWORD *)v7 + 16i64))(v7, &nNumber);
      v10 = (HIDWORD(nNumber) >> 20) & 0xF;
      if ( (unsigned int)(v10 - 1) <= 9
        && (unsigned int)((SHIDWORD(nNumber) >> 24) - 1) <= 3
        && (v10 != 1 || (_DWORD)nNumber && (HIDWORD(nNumber) & 0xFFFFFu) <= 4)
        && (v10 != 7 || (_DWORD)nNumber && (nNumber & 0xFFFFF00000000i64) == 0)
        && (v10 != 3 || (_DWORD)nNumber) )
      {
        OSuite::ZString::ZString(&v17, nNumber);
        OSuite::ZString::operator=(&that, v11);
        OSuite::ZString::~ZString(&v17);
      }
      OSuite::ZObject::m_allocator->vfptr->free(OSuite::ZObject::m_allocator, v8);
    }
  }
  nNumber = (unsigned __int64)&v16;
  OSuite::ZString::ZString(&v16.m_strOwner, &that);
  OSuite::ZString::ZString(&v16.m_strTicketData, (OSuite::ZString *)&that.m_pString);
  v16.m_eProvider = v13;
  v16.m_uTicketSize = nLength[0];
  OSuite::ZString::ZString(&v16.m_strAccessToken, (OSuite::ZString *)&nLength[1]);
  OSuite::fastdelegate::FastDelegate2<enum OSuite::IOnlineAuthentication::AuthState,OSuite::IOnlineAuthentication::AuthTicket,void>::operator()(
    &OSuite::m_cb,
    v5,
    &v16);
  OSuite::ZString::~ZString((OSuite::ZString *)&nLength[1]);
  OSuite::ZString::~ZString((OSuite::ZString *)&that.m_pString);
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
    return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v3 + 72i64))(v3);
  }
  return result;
}

