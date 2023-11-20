// File Line: 53
// RVA: 0x426FE0
void __fastcall SteamImplementation::SteamImplementation(SteamImplementation *this, void (__fastcall *textCallbackFn)(int, const char *), void (__fastcall *dlcCallbackFn)())
{
  SteamImplementation *v3; // rbx
  CCallback<SteamImplementation,DlcInstalled_t,0> *v4; // rcx
  signed __int64 v5; // rcx

  v3 = this;
  this->mTextCallback = textCallbackFn;
  this->mDLCCallback = dlcCallbackFn;
  v4 = &this->mDLCInstalledCallback;
  v4->m_nCallbackFlags = 0;
  v4->m_iCallback = 0;
  v4->vfptr = (CCallbackBaseVtbl *)&CCallback<SteamImplementation,DlcInstalled_t,0>::`vftable';
  v4->m_pObj = v3;
  v4->m_Func = SteamImplementation::OnDLCInstalled;
  if ( SteamImplementation::OnDLCInstalled )
  {
    v4->m_pObj = v3;
    v4->m_Func = SteamImplementation::OnDLCInstalled;
    SteamAPI_RegisterCallback(v4, 1005i64);
  }
  v5 = (signed __int64)&v3->mRegisterActivationCodeCallback;
  *(_BYTE *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = 0;
  *(_QWORD *)v5 = &CCallback<SteamImplementation,RegisterActivationCodeResponse_t,0>::`vftable';
  *(_QWORD *)(v5 + 16) = v3;
  *(_QWORD *)(v5 + 24) = SteamImplementation::OnRegisterActivationCode;
  if ( SteamImplementation::OnRegisterActivationCode )
  {
    v3->mRegisterActivationCodeCallback.m_pObj = v3;
    v3->mRegisterActivationCodeCallback.m_Func = SteamImplementation::OnRegisterActivationCode;
    SteamAPI_RegisterCallback(v5, 1008i64);
  }
}

// File Line: 57
// RVA: 0x427270
void __fastcall SteamImplementation::OnDLCInstalled(SteamImplementation *this, DlcInstalled_t *callbackData)
{
  SteamImplementation *v2; // rbx
  void (__fastcall *v3)(); // rax
  char string; // [rsp+20h] [rbp-208h]

  v2 = this;
  if ( this->mTextCallback )
  {
    snprintf(&string, 0x200ui64, "SteamImplementation::OnDLCInstalled(): AppID %d\n", callbackData->m_nAppID);
    v2->mTextCallback(1, &string);
  }
  v3 = v2->mDLCCallback;
  if ( v3 )
    ((void (__fastcall *)(SteamImplementation *, DlcInstalled_t *))v3)(this, callbackData);
}

// File Line: 71
// RVA: 0x4272C0
void __fastcall SteamImplementation::OnRegisterActivationCode(SteamImplementation *this, RegisterActivationCodeResponse_t *callbackData)
{
  SteamImplementation *v2; // rbx
  void (__fastcall *v3)(); // rax
  char string; // [rsp+20h] [rbp-208h]

  v2 = this;
  if ( this->mTextCallback )
  {
    snprintf(&string, 0x200ui64, "SteamImplementation::OnRegisterActivationCode()\n");
    v2->mTextCallback(1, &string);
  }
  v3 = v2->mDLCCallback;
  if ( v3 )
    ((void (__fastcall *)(SteamImplementation *, RegisterActivationCodeResponse_t *))v3)(this, callbackData);
}

// File Line: 149
// RVA: 0x427230
void __fastcall MiniDumpFunction(unsigned int nExceptionCode, _EXCEPTION_POINTERS *pException)
{
  unsigned int v2; // edi
  _EXCEPTION_POINTERS *v3; // rbx

  v2 = nExceptionCode;
  v3 = pException;
  SteamAPI_SetMiniDumpComment("Minidump comment: SDHDShip.exe\n");
  SteamAPI_WriteMiniDump(v2, v3, (unsigned int)UFG::gCL_number);
}

// File Line: 164
// RVA: 0x427160
char __fastcall SteamIntegration::InitAPI(void (__fastcall *textCallbackFn)(int, const char *), void (__fastcall *dlcCallbackFn)(), bool dev_mode)
{
  void (__fastcall *v3)(); // rdi
  void (__fastcall *v4)(int, const char *); // rbx
  __int64 v6; // rcx
  __int64 v7; // rcx
  ISteamClient *v8; // rax
  __int64 v9; // rcx
  ISteamUtils *v10; // rax
  UFG::allocator::free_link *v11; // rax

  v3 = dlcCallbackFn;
  v4 = textCallbackFn;
  if ( !dev_mode && (unsigned __int8)SteamAPI_RestartAppIfNecessary((unsigned int)UFG::OnlineManagerPlat::SteamAppID) )
    return 0;
  _set_se_translator(MiniDumpFunction);
  if ( !(unsigned __int8)SteamAPI_Init(v6) )
    return 0;
  gOutputCallback = v4;
  gDLCInstalledCallback = v3;
  v8 = (ISteamClient *)SteamClient(v7);
  v8->vfptr->SetWarningMessageHook(v8, v4);
  v10 = (ISteamUtils *)SteamUtils(v9);
  v10->vfptr->SetOverlayNotificationPosition(v10, k_EPositionBottomRight);
  v11 = UFG::qMalloc(0x50ui64, UFG::gGlobalNewName, 0i64);
  if ( v11 )
    SteamImplementation::SteamImplementation((SteamImplementation *)v11, v4, v3);
  sImplementation = (SteamImplementation *)v11;
  return 1;
}

// File Line: 213
// RVA: 0x4270D0
void __fastcall SteamIntegration::CloseAPI(__int64 a1)
{
  SteamImplementation *v1; // rbx
  CCallback<SteamImplementation,RegisterActivationCodeResponse_t,0> *v2; // rcx

  v1 = sImplementation;
  if ( sImplementation )
  {
    v2 = &sImplementation->mRegisterActivationCodeCallback;
    sImplementation->mRegisterActivationCodeCallback.vfptr = (CCallbackBaseVtbl *)&CCallback<SteamImplementation,RegisterActivationCodeResponse_t,0>::`vftable';
    if ( v1->mRegisterActivationCodeCallback.m_nCallbackFlags & 1 )
      SteamAPI_UnregisterCallback(v2);
    v1->mDLCInstalledCallback.vfptr = (CCallbackBaseVtbl *)&CCallback<SteamImplementation,DlcInstalled_t,0>::`vftable';
    if ( v1->mDLCInstalledCallback.m_nCallbackFlags & 1 )
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

