// File Line: 53
// RVA: 0x426FE0
void __fastcall SteamImplementation::SteamImplementation(
        SteamImplementation *this,
        void (__fastcall *textCallbackFn)(int, const char *),
        void (__fastcall *dlcCallbackFn)())
{
  CCallback<SteamImplementation,DlcInstalled_t,0> *p_mDLCInstalledCallback; // rcx

  this->mTextCallback = textCallbackFn;
  this->mDLCCallback = dlcCallbackFn;
  p_mDLCInstalledCallback = &this->mDLCInstalledCallback;
  p_mDLCInstalledCallback->m_nCallbackFlags = 0;
  p_mDLCInstalledCallback->m_iCallback = 0;
  p_mDLCInstalledCallback->vfptr = (CCallbackBaseVtbl *)&CCallback<SteamImplementation,DlcInstalled_t,0>::`vftable;
  p_mDLCInstalledCallback->m_pObj = this;
  p_mDLCInstalledCallback->m_Func = SteamImplementation::OnDLCInstalled;
  if ( SteamImplementation::OnDLCInstalled )
  {
    p_mDLCInstalledCallback->m_pObj = this;
    p_mDLCInstalledCallback->m_Func = SteamImplementation::OnDLCInstalled;
    SteamAPI_RegisterCallback(p_mDLCInstalledCallback, 1005i64);
  }
  this->mRegisterActivationCodeCallback.m_nCallbackFlags = 0;
  this->mRegisterActivationCodeCallback.m_iCallback = 0;
  this->mRegisterActivationCodeCallback.vfptr = (CCallbackBaseVtbl *)&CCallback<SteamImplementation,RegisterActivationCodeResponse_t,0>::`vftable;
  this->mRegisterActivationCodeCallback.m_pObj = this;
  this->mRegisterActivationCodeCallback.m_Func = SteamImplementation::OnRegisterActivationCode;
  if ( SteamImplementation::OnRegisterActivationCode )
  {
    this->mRegisterActivationCodeCallback.m_pObj = this;
    this->mRegisterActivationCodeCallback.m_Func = SteamImplementation::OnRegisterActivationCode;
    SteamAPI_RegisterCallback(&this->mRegisterActivationCodeCallback, 1008i64);
  }
}

// File Line: 57
// RVA: 0x427270
void __fastcall SteamImplementation::OnDLCInstalled(SteamImplementation *this, DlcInstalled_t *callbackData)
{
  void (__fastcall *mDLCCallback)(); // rax
  char string[520]; // [rsp+20h] [rbp-208h] BYREF

  if ( this->mTextCallback )
  {
    snprintf(string, 0x200ui64, "SteamImplementation::OnDLCInstalled(): AppID %d\n", callbackData->m_nAppID);
    this->mTextCallback(1i64, string);
  }
  mDLCCallback = this->mDLCCallback;
  if ( mDLCCallback )
    ((void (__fastcall *)(SteamImplementation *, DlcInstalled_t *))mDLCCallback)(this, callbackData);
}

// File Line: 71
// RVA: 0x4272C0
void __fastcall SteamImplementation::OnRegisterActivationCode(
        SteamImplementation *this,
        RegisterActivationCodeResponse_t *callbackData)
{
  void (__fastcall *mDLCCallback)(); // rax
  char string[520]; // [rsp+20h] [rbp-208h] BYREF

  if ( this->mTextCallback )
  {
    snprintf(string, 0x200ui64, "SteamImplementation::OnRegisterActivationCode()\n");
    this->mTextCallback(1i64, string);
  }
  mDLCCallback = this->mDLCCallback;
  if ( mDLCCallback )
    ((void (__fastcall *)(SteamImplementation *, RegisterActivationCodeResponse_t *))mDLCCallback)(this, callbackData);
}

// File Line: 149
// RVA: 0x427230
void __fastcall MiniDumpFunction(unsigned int nExceptionCode, _EXCEPTION_POINTERS *pException)
{
  SteamAPI_SetMiniDumpComment("Minidump comment: SDHDShip.exe\n");
  SteamAPI_WriteMiniDump(nExceptionCode, pException, (unsigned int)UFG::gCL_number);
}

// File Line: 164
// RVA: 0x427160
char __fastcall SteamIntegration::InitAPI(
        void (__fastcall *textCallbackFn)(int, const char *),
        void (__fastcall *dlcCallbackFn)(),
        bool dev_mode)
{
  __int64 v6; // rcx
  __int64 v7; // rcx
  ISteamClient *v8; // rax
  __int64 v9; // rcx
  ISteamUtils *v10; // rax
  UFG::allocator::free_link *v11; // rax

  if ( !dev_mode && (unsigned __int8)SteamAPI_RestartAppIfNecessary((unsigned int)UFG::OnlineManagerPlat::SteamAppID) )
    return 0;
  _set_se_translator(MiniDumpFunction);
  if ( !(unsigned __int8)SteamAPI_Init(v6) )
    return 0;
  gOutputCallback = textCallbackFn;
  gDLCInstalledCallback = dlcCallbackFn;
  v8 = (ISteamClient *)SteamClient(v7);
  v8->vfptr->SetWarningMessageHook(v8, textCallbackFn);
  v10 = (ISteamUtils *)SteamUtils(v9);
  v10->vfptr->SetOverlayNotificationPosition(v10, k_EPositionBottomRight);
  v11 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  if ( v11 )
    SteamImplementation::SteamImplementation((SteamImplementation *)v11, textCallbackFn, dlcCallbackFn);
  sImplementation = (SteamImplementation *)v11;
  return 1;
}

// File Line: 213
// RVA: 0x4270D0
void __fastcall SteamIntegration::CloseAPI(__int64 a1)
{
  SteamImplementation *v1; // rbx
  CCallback<SteamImplementation,RegisterActivationCodeResponse_t,0> *p_mRegisterActivationCodeCallback; // rcx

  v1 = sImplementation;
  if ( sImplementation )
  {
    p_mRegisterActivationCodeCallback = &sImplementation->mRegisterActivationCodeCallback;
    sImplementation->mRegisterActivationCodeCallback.vfptr = (CCallbackBaseVtbl *)&CCallback<SteamImplementation,RegisterActivationCodeResponse_t,0>::`vftable;
    if ( (v1->mRegisterActivationCodeCallback.m_nCallbackFlags & 1) != 0 )
      SteamAPI_UnregisterCallback(p_mRegisterActivationCodeCallback);
    v1->mDLCInstalledCallback.vfptr = (CCallbackBaseVtbl *)&CCallback<SteamImplementation,DlcInstalled_t,0>::`vftable;
    if ( (v1->mDLCInstalledCallback.m_nCallbackFlags & 1) != 0 )
      SteamAPI_UnregisterCallback(&v1->mDLCInstalledCallback);
    operator delete[](v1);
  }
  sImplementation = 0i64;
  SteamAPI_Shutdown(a1);
}

// File Line: 232
// RVA: 0x427310
void __fastcall SteamIntegration::Update(__int64 a1)
{
  OSuite::ZGameInterface *v1; // rcx

  if ( (unsigned __int8)SteamAPI_IsSteamRunning(a1) )
  {
    if ( sImplementation )
      SteamAPI_RunCallbacks(v1);
  }
}

