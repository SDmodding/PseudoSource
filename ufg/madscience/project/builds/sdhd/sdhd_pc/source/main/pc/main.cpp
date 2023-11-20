// File Line: 132
// RVA: 0xA3FF60
LRESULT __fastcall KeyboardFilterHook(int nCode, unsigned __int64 wParam, __int64 lParam)
{
  __int64 v3; // rbx
  bool v4; // r8
  unsigned __int64 v5; // r14
  int v6; // ebp
  char v7; // di
  bool v8; // si

  v3 = lParam;
  v4 = 0;
  v5 = wParam;
  v6 = nCode;
  if ( !UFG::InputSystem::msApplicationHasFocus )
    return CallNextHookEx(0i64, v6, v5, v3);
  if ( UFG::InputSystem::msPCKeyboardSwapMode == 1 )
    return CallNextHookEx(0i64, v6, v5, v3);
  v7 = 0;
  if ( nCode )
    return CallNextHookEx(0i64, v6, v5, v3);
  if ( wParam != 256 )
  {
    if ( wParam == 257 )
      goto LABEL_10;
    if ( wParam != 260 )
    {
      if ( wParam != 261 )
        goto LABEL_25;
      goto LABEL_10;
    }
  }
  v7 = 1;
LABEL_10:
  v8 = *(_DWORD *)v3 == 32 && *(_BYTE *)(v3 + 8) & 0x20;
  v4 = *(_DWORD *)v3 == 27 && (*(_BYTE *)(v3 + 8) & 0x20 || GetKeyState(17) < 0)
    || (unsigned int)(*(_DWORD *)v3 - 91) <= 1;
  if ( v8 )
  {
    gSpaceBarState = v7 != 0;
    return 1i64;
  }
  if ( (unsigned int)(*(_DWORD *)v3 - 91) <= 1 && *(_DWORD *)(v3 + 8) == 129 )
    return CallNextHookEx(0i64, v6, v5, v3);
LABEL_25:
  if ( v4 )
    return 1i64;
  return CallNextHookEx(0i64, v6, v5, v3);
}

// File Line: 210
// RVA: 0xA3FF00
void __fastcall InstallKeyboardHook(bool install)
{
  if ( install )
  {
    if ( !hhkLowLevelKybd )
      hhkLowLevelKybd = SetWindowsHookExA(13, KeyboardFilterHook, 0i64, 0);
  }
  else if ( hhkLowLevelKybd )
  {
    UnhookWindowsHookEx(hhkLowLevelKybd);
    hhkLowLevelKybd = 0i64;
  }
}

// File Line: 320
// RVA: 0xA40320
void pcPushState(void)
{
  unsigned int v0; // eax
  unsigned int v1; // ebx
  UFG::GameState *v2; // rax
  bool v3; // al
  char v4; // cl

  gGovernMaxFrameRate = 0;
  v0 = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  v1 = v0;
  v2 = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, v0);
  if ( v2 && v1 == uidGameStateInGame_14 )
  {
    v3 = v2->vfptr->ModeIsSet(v2, eGSM_PAUSED);
    v4 = gGovernMaxFrameRate;
    if ( v3 )
      v4 = 1;
    gGovernMaxFrameRate = v4;
  }
  else
  {
    gGovernMaxFrameRate = 1;
  }
}

// File Line: 366
// RVA: 0xA40080
void MainLoop(void)
{
  __int64 v0; // rbp
  int v1; // edi
  signed int v2; // esi
  unsigned __int64 v3; // r14
  __int64 v4; // rcx
  unsigned __int64 v5; // rax
  float v6; // xmm0_4
  float v7; // xmm6_4
  bool v8; // bl
  int v9; // edx
  float v10; // xmm6_4
  unsigned __int64 v11; // r8
  int v12; // ecx
  float v13; // xmm6_4
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  unsigned int v17; // eax
  bool v18; // bl
  unsigned int v19; // eax
  unsigned int v20; // ebx
  UFG::GameState *v21; // rax
  signed __int64 v22; // rcx
  bool v23; // al
  int dest[8]; // [rsp+20h] [rbp-C8h]
  Render::RenderOutputParams outSettings; // [rsp+40h] [rbp-A8h]

  LOBYTE(v0) = 1;
  v1 = 0;
  v2 = 0;
  v3 = UFG::qGetTicks();
  UFG::qMemSet(dest, 0, 0x20u);
  do
  {
    SteamIntegration::Update(v4);
    v5 = UFG::qGetTicks();
    v6 = UFG::qGetTickTime(v3, v5);
    v7 = v6;
    v3 = UFG::qGetTicks();
    v8 = NISManager::GetInstance()->mState != 0;
    Render::RenderOutputParams::RenderOutputParams(&outSettings);
    Render::GetCurrentDisplaySettings(&outSettings);
    if ( outSettings.mTimeStepSmoothingFrames < 2 || v6 <= 0.0000099999997 )
    {
      v2 = 0;
    }
    else
    {
      *(float *)&dest[v1] = v6;
      v1 = (v1 + 1) % 8;
      if ( ++v2 >= 8 )
      {
        v2 = 8;
      }
      else if ( v2 <= 1 )
      {
        goto LABEL_17;
      }
      v9 = v2 - 1;
      v10 = 0.0;
      if ( v2 - 1 >= 0 )
      {
        if ( v2 >= 4 )
        {
          v11 = (unsigned __int64)(unsigned int)v2 >> 2;
          v12 = v1 - v9 + 9;
          v9 -= 4 * ((unsigned int)v2 >> 2);
          do
          {
            v13 = (float)((float)(v10 + *(float *)&dest[(v12 - 1) % 8]) + *(float *)&dest[v12 % 8])
                + *(float *)&dest[(v12 + 1) % 8];
            v14 = (v12 + 2) % 8;
            v12 += 4;
            v10 = v13 + *(float *)&dest[v14];
            --v11;
          }
          while ( v11 );
        }
        if ( v9 >= 0 )
        {
          v15 = v1 - v9 + 8;
          do
          {
            v16 = v15++ % 8;
            --v9;
            v10 = v10 + *(float *)&dest[v16];
          }
          while ( v9 >= 0 );
        }
      }
      v7 = v10 / (float)v2;
    }
LABEL_17:
    v17 = UFG::qGetSystemElapsedMSecs();
    UFG::Metrics::UpdateAll(v17, v7, 1, v8);
    v18 = Render::UpdateGameSystems(UFG::Metrics::msRealTimeDelta_Accurate);
    UFG::BenchmarkHelper::Update(&UFG::BenchmarkHelper::gBenchmarkHelper);
    if ( v18 )
    {
      gGovernMaxFrameRate = 0;
      v19 = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
      v20 = v19;
      v21 = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, v19);
      v22 = (signed __int64)v21;
      if ( v21 )
      {
        if ( v20 == uidGameStateInGame_14 )
        {
          v23 = v21->vfptr->ModeIsSet(v21, eGSM_PAUSED);
          v22 = gGovernMaxFrameRate;
          if ( v23 )
            v22 = 1i64;
          gGovernMaxFrameRate = v22;
        }
        else
        {
          gGovernMaxFrameRate = 1;
        }
      }
      else
      {
        gGovernMaxFrameRate = 1;
      }
      v0 = (unsigned __int8)Render::RenderFrame(UFG::Metrics::msRealTimeDelta_Accurate, (Render *)v22);
    }
    if ( !(_BYTE)v0 )
      break;
    v4 = (unsigned __int8)gGameQuitEvent;
  }
  while ( !gGameQuitEvent );
}

// File Line: 487
// RVA: 0xA40390
void __fastcall SteamAPITextHook(int nSeverity, const char *pchDebugText)
{
  UFG::qPrintf("%s", pchDebugText);
}

// File Line: 502
// RVA: 0x15B08C0
__int64 dynamic_initializer_for__m_ExeName__()
{
  UFG::qString::qString(&m_ExeName);
  return atexit(dynamic_atexit_destructor_for__m_ExeName__);
}

// File Line: 572
// RVA: 0xA403A0
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  float v4; // xmm0_4
  int v5; // er14
  HINSTANCE v6; // r15
  const char *v7; // rax
  UFG::qString *v8; // rax
  int v9; // eax
  char v10; // dl
  HANDLE v11; // rsi
  HANDLE v18; // rax
  UFG::qString *v19; // rax
  hkpEntity *v20; // rdx
  hkEntitySelectorAll *v21; // rcx
  __int64 v22; // rcx
  UFG::qString result; // [rsp+50h] [rbp-488h]
  UFG::qString v24; // [rsp+78h] [rbp-460h]
  UFG::qString v25; // [rsp+A0h] [rbp-438h]
  char format; // [rsp+D0h] [rbp-408h]

  v5 = nShowCmd;
  v6 = hInstance;
  v7 = GetCommandLineA();
  UFG::qString::qString(&v24, v7);
  v8 = UFG::qString::GetFilenameWithoutExtension(&v24, &result);
  UFG::qString::Set(&m_ExeName, v8->mData, v8->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  SystemParametersInfoA(0x3Au, 8u, &g_StartupStickyKeys, 0);
  SystemParametersInfoA(0x34u, 8u, &g_StartupToggleKeys, 0);
  SystemParametersInfoA(0x32u, 0x18u, &g_StartupFilterKeys, 0);
  v9 = UFG::qString::find(&v24, "-benchmark");
  v10 = gAutoBenchmarkMode;
  if ( v9 != UFG::qString::npos )
    v10 = 1;
  gAutoBenchmarkMode = v10;
  v11 = CreateMutexA(0i64, 0, "UFG_GameMutex_SD2");
  if ( GetLastError() == 183 )
  {
    CloseHandle(v11);
    exit(1);
  }
  _RAX = 1i64;
  __asm { cpuid; Get CPU ID }
  if ( _bittest((const signed int *)&_RDX, 0x1Au) )
  {
    v18 = GetCurrentProcess();
    if ( (unsigned int)GetModuleFileNameExA_0(v18, 0i64, &format, 1024i64) )
    {
      UFG::qString::qString(&result, &format);
      v19 = UFG::qString::GetFilePath(&result, &v25);
      UFG::qSetDirectory(v19->mData);
      UFG::qString::~qString(&v25);
      UFG::qString::~qString(&result);
    }
    gInstance = v6;
    gCmdShow = v5;
    if ( !SteamIntegration::InitAPI(SteamAPITextHook, (void (__fastcall *)())_, 0) )
      exit(1);
    pcPushState();
    InitGameSystems(v21, v20, v4);
    MainLoop();
    if ( hhkLowLevelKybd )
    {
      UnhookWindowsHookEx(hhkLowLevelKybd);
      hhkLowLevelKybd = 0i64;
    }
    UFG::AllowAccessibilityShortcutKeys(1);
    CloseGameSystems();
    CloseRenderEngine();
    SteamIntegration::CloseAPI(v22);
    CloseHandle(v11);
    exit(1);
  }
  UFG::qString::~qString(&v24);
  return 1;
}

// File Line: 718
// RVA: 0x141EFC0
WinMain$catch$0

