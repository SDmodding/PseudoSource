// File Line: 30
// RVA: 0x15E200
void __fastcall OSuite::ZGameInterface::ZGameInterface(OSuite::ZGameInterface *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZGameInterface::`vftable;
  this->m_pLogger = 0i64;
  this->m_bInitSuccess = 0;
  OSuite::ZString::ZString(&this->m_strUserId);
}

// File Line: 34
// RVA: 0x15E250
void __fastcall OSuite::ZGameInterface::~ZGameInterface(OSuite::ZGameInterface *this)
{
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZGameInterface::`vftable;
  OSuite::ZString::~ZString(&this->m_strUserId);
}

// File Line: 39
// RVA: 0x15E450
__int64 __fastcall OSuite::ZGameInterface::Initialize(
        OSuite::ZGameInterface *this,
        const char *gameUrl,
        OSuite::IGameConfig *pGameConfig)
{
  unsigned int v3; // eax
  void (__fastcall *v4)(OSuite::fastdelegate::detail::GenericClass *); // rcx
  unsigned int v5; // ebx
  OSuite::ZError *v6; // rax
  void (__fastcall *v7)(OSuite::fastdelegate::detail::GenericClass *); // rcx
  void (__fastcall *v8)(OSuite::fastdelegate::detail::GenericClass *); // rax
  OSuite::ZLog *v9; // rax
  OSuite::fastdelegate::FastDelegate3<enum OSuite::ZLog::LogLevel,char const *,char const *,void> v11; // [rsp+20h] [rbp-18h] BYREF

  v3 = OSuite::ZGameInterface::PlatformInit(this, gameUrl, pGameConfig);
  v4 = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::fastdelegate::FastDelegate2<OSuite::SCallbackData *,OSuite::ZWebServiceClient *,void>::InvokeStaticFunction;
  v5 = v3;
  v11.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)OSuite::ZGameInterface::OnError;
  if ( !OSuite::ZGameInterface::OnError )
    v4 = 0i64;
  v11.m_Closure.m_pFunction = v4;
  v6 = OSuite::TSingleton<OSuite::ZError>::Object();
  OSuite::ZError::SetErrorDelegate(
    v6,
    (OSuite::fastdelegate::FastDelegate2<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> const &,void> *)&v11);
  v7 = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::fastdelegate::FastDelegate2<bool,char const *,void>::InvokeStaticFunction;
  OSuite::gAssertDelegate.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)_;
  v8 = (void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *))OSuite::fastdelegate::FastDelegate3<enum OSuite::ZLog::LogLevel,char const *,char const *,void>::InvokeStaticFunction;
  if ( !_ )
    v7 = 0i64;
  OSuite::gAssertDelegate.m_Closure.m_pFunction = v7;
  v11.m_Closure.m_pthis = (OSuite::fastdelegate::detail::GenericClass *)OSuite::ZGameInterface::OnLog;
  if ( !OSuite::ZGameInterface::OnLog )
    v8 = 0i64;
  v11.m_Closure.m_pFunction = v8;
  v9 = OSuite::TSingleton<OSuite::ZLog>::Object();
  OSuite::ZLog::SetLogDelegate(v9, &v11);
  return v5;
}

// File Line: 56
// RVA: 0x15E7E0
// attributes: thunk
__int64 __fastcall OSuite::ZGameInterface::Shutdown(OSuite::ZGameInterface *this)
{
  return OSuite::ZGameInterface::PlatformShutdown(this);
}

// File Line: 62
// RVA: 0x15E7D0
void __fastcall OSuite::ZGameInterface::OnLog(OSuite::ZLog::LogLevel __formal, const char *a2, const char *message)
{
  UFG::OSuitePrintf("%s", message);
}

// File Line: 82
// RVA: 0x15E710
void __fastcall OSuite::ZGameInterface::OnError(
        unsigned __int64 __formal,
        OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> *error)
{
  const char *ErrorString; // rax
  const char *v4; // rax
  const char *v5; // rax
  const char *v6; // rax
  OSuite::ZString v7; // [rsp+28h] [rbp-40h] BYREF
  OSuite::ZString v8; // [rsp+40h] [rbp-28h] BYREF

  ErrorString = OSuite::ZError::GetErrorString(error->m_First);
  OSuite::ZString::ZString(&v8, ErrorString);
  v4 = OSuite::ZString::c_str(&error->m_Second);
  OSuite::ZString::ZString(&v7, v4);
  if ( OSuite::ZString::Count(&v8) )
  {
    v5 = OSuite::ZString::c_str(&v8);
    UFG::OSuitePrintf("[OS ERROR] Message: %s", v5);
    if ( OSuite::ZString::Count(&v7) )
    {
      v6 = OSuite::ZString::c_str(&v7);
      UFG::OSuitePrintf(" - Additional details: %s", v6);
    }
    UFG::OSuitePrintf("\n");
  }
  OSuite::ZString::~ZString(&v7);
  OSuite::ZString::~ZString(&v8);
}

