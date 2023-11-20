// File Line: 1120
// RVA: 0xA36C40
void __fastcall OSuite::fastdelegate::FastDelegate2<enum  OSuite::IOnlineAuthentication::AuthState,OSuite::IOnlineAuthentication::AuthTicket,void>::operator()(OSuite::fastdelegate::FastDelegate2<enum OSuite::IOnlineAuthentication::AuthState,OSuite::IOnlineAuthentication::AuthTicket,void> *this, OSuite::IOnlineAuthentication::AuthState p1, OSuite::IOnlineAuthentication::AuthTicket *p2)
{
  OSuite::IOnlineAuthentication::AuthTicket *v3; // r14
  OSuite::IOnlineAuthentication::AuthState v4; // esi
  OSuite::fastdelegate::FastDelegate2<enum OSuite::IOnlineAuthentication::AuthState,OSuite::IOnlineAuthentication::AuthTicket,void> *v5; // rdi
  OSuite::ZString v6; // [rsp+28h] [rbp-70h]
  OSuite::ZString v7; // [rsp+40h] [rbp-58h]
  OSuite::IOnlineAuthentication::AuthProvider v8; // [rsp+58h] [rbp-40h]
  unsigned int v9; // [rsp+5Ch] [rbp-3Ch]
  OSuite::ZString v10; // [rsp+60h] [rbp-38h]

  v3 = p2;
  v4 = p1;
  v5 = this;
  OSuite::ZString::ZString(&v6, &p2->m_strOwner);
  OSuite::ZString::ZString(&v7, &v3->m_strTicketData);
  v8 = v3->m_eProvider;
  v9 = v3->m_uTicketSize;
  OSuite::ZString::ZString(&v10, &v3->m_strAccessToken);
  ((void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *, _QWORD, OSuite::ZString *))v5->m_Closure.m_pFunction)(
    v5->m_Closure.m_pthis,
    (unsigned int)v4,
    &v6);
  OSuite::ZString::~ZString(&v3->m_strAccessToken);
  OSuite::ZString::~ZString(&v3->m_strTicketData);
  OSuite::ZString::~ZString(&v3->m_strOwner);
}

// File Line: 1148
// RVA: 0x15E500
void __fastcall OSuite::fastdelegate::FastDelegate2<bool,char const *,void>::InvokeStaticFunction(OSuite::fastdelegate::FastDelegate2<bool,char const *,void> *this, bool p1, const char *p2)
{
  ((void (__fastcall *)(bool, const char *))this)(p1, p2);
}

// File Line: 1233
// RVA: 0x15E510
void __fastcall OSuite::fastdelegate::FastDelegate3<enum  OSuite::ZLog::LogLevel,char const *,char const *,void>::InvokeStaticFunction(OSuite::fastdelegate::FastDelegate3<enum OSuite::ZLog::LogLevel,char const *,char const *,void> *this, OSuite::ZLog::LogLevel p1, const char *p2, const char *p3)
{
  ((void (__fastcall *)(_QWORD, const char *, const char *))this)((unsigned int)p1, p2, p3);
}

