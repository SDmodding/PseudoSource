// File Line: 1120
// RVA: 0xA36C40
void __fastcall OSuite::fastdelegate::FastDelegate2<enum OSuite::IOnlineAuthentication::AuthState,OSuite::IOnlineAuthentication::AuthTicket,void>::operator()(
        OSuite::fastdelegate::FastDelegate2<enum OSuite::IOnlineAuthentication::AuthState,OSuite::IOnlineAuthentication::AuthTicket,void> *this,
        unsigned int p1,
        OSuite::IOnlineAuthentication::AuthTicket *p2)
{
  OSuite::ZString v6; // [rsp+28h] [rbp-70h] BYREF
  OSuite::ZString v7; // [rsp+40h] [rbp-58h] BYREF
  OSuite::IOnlineAuthentication::AuthProvider m_eProvider; // [rsp+58h] [rbp-40h]
  unsigned int m_uTicketSize; // [rsp+5Ch] [rbp-3Ch]
  OSuite::ZString v10; // [rsp+60h] [rbp-38h] BYREF

  OSuite::ZString::ZString(&v6, &p2->m_strOwner);
  OSuite::ZString::ZString(&v7, &p2->m_strTicketData);
  m_eProvider = p2->m_eProvider;
  m_uTicketSize = p2->m_uTicketSize;
  OSuite::ZString::ZString(&v10, &p2->m_strAccessToken);
  ((void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *, _QWORD, OSuite::ZString *))this->m_Closure.m_pFunction)(
    this->m_Closure.m_pthis,
    p1,
    &v6);
  OSuite::ZString::~ZString(&p2->m_strAccessToken);
  OSuite::ZString::~ZString(&p2->m_strTicketData);
  OSuite::ZString::~ZString(&p2->m_strOwner);
}

// File Line: 1148
// RVA: 0x15E500
void __fastcall OSuite::fastdelegate::FastDelegate2<bool,char const *,void>::InvokeStaticFunction(
        OSuite::fastdelegate::FastDelegate2<bool,char const *,void> *this,
        bool p1,
        const char *p2)
{
  ((void (__fastcall *)(bool, const char *))this)(p1, p2);
}

// File Line: 1233
// RVA: 0x15E510
void __fastcall OSuite::fastdelegate::FastDelegate3<enum OSuite::ZLog::LogLevel,char const *,char const *,void>::InvokeStaticFunction(
        OSuite::fastdelegate::FastDelegate3<enum OSuite::ZLog::LogLevel,char const *,char const *,void> *this,
        unsigned int p1,
        const char *p2,
        const char *p3)
{
  ((void (__fastcall *)(_QWORD, const char *, const char *))this)(p1, p2, p3);
}

