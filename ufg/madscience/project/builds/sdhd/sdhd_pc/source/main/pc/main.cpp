// File Line: 132
// RVA: 0xA3FF60
LRESULT __fastcall KeyboardFilterHook(int nCode, WPARAM wParam, LPARAM lParam)
{
  bool v4; // r8
  char v7; // di
  bool v8; // si

  v4 = 0;
  if ( !UFG::InputSystem::msApplicationHasFocus )
    return CallNextHookEx(0i64, nCode, wParam, lParam);
  if ( UFG::InputSystem::msPCKeyboardSwapMode == 1 )
    return CallNextHookEx(0i64, nCode, wParam, lParam);
  v7 = 0;
  if ( nCode )
    return CallNextHookEx(0i64, nCode, wParam, lParam);
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
  v8 = *(_DWORD *)lParam == 32 && (*(_BYTE *)(lParam + 8) & 0x20) != 0;
  v4 = *(_DWORD *)lParam == 27 && ((*(_BYTE *)(lParam + 8) & 0x20) != 0 || GetKeyState(17) < 0)
    || (unsigned int)(*(_DWORD *)lParam - 91) <= 1;
  if ( v8 )
  {
    gSpaceBarState = v7 != 0;
    return 1i64;
  }
  if ( (unsigned int)(*(_DWORD *)lParam - 91) <= 1 && *(_DWORD *)(lParam + 8) == 129 )
    return CallNextHookEx(0i64, nCode, wParam, lParam);
LABEL_25:
  if ( v4 )
    return 1i64;
  return CallNextHookEx(0i64, nCode, wParam, lParam);
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
  unsigned int CurrentState; // ebx
  UFG::GameState *GameStateObj; // rax
  bool v2; // al
  char v3; // cl

  gGovernMaxFrameRate = 0;
  CurrentState = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
  GameStateObj = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, CurrentState);
  if ( GameStateObj && CurrentState == uidGameStateInGame_14 )
  {
    v2 = GameStateObj->vfptr->ModeIsSet(GameStateObj, eGSM_PAUSED);
    v3 = gGovernMaxFrameRate;
    if ( v2 )
      v3 = 1;
    gGovernMaxFrameRate = v3;
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
  bool v0; // bp
  int v1; // edi
  int v2; // esi
  unsigned __int64 Ticks; // r14
  __int64 v4; // rcx
  unsigned __int64 v5; // rax
  float TickTime; // xmm0_4
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
  unsigned int SystemElapsedMSecs; // eax
  bool updated; // bl
  unsigned int CurrentState; // ebx
  UFG::GameState *GameStateObj; // rax
  bool v21; // al
  char v22; // cl
  int dest[8]; // [rsp+20h] [rbp-C8h] BYREF
  Render::RenderOutputParams outSettings; // [rsp+40h] [rbp-A8h] BYREF

  v0 = 1;
  v1 = 0;
  v2 = 0;
  Ticks = UFG::qGetTicks();
  UFG::qMemSet(dest, 0, 0x20u);
  do
  {
    SteamIntegration::Update(v4);
    v5 = UFG::qGetTicks();
    TickTime = UFG::qGetTickTime(Ticks, v5);
    v7 = TickTime;
    Ticks = UFG::qGetTicks();
    v8 = NISManager::GetInstance()->mState != STATE_INVALID;
    Render::RenderOutputParams::RenderOutputParams(&outSettings);
    Render::GetCurrentDisplaySettings(&outSettings);
    if ( outSettings.mTimeStepSmoothingFrames < 2 || TickTime <= 0.0000099999997 )
    {
      v2 = 0;
    }
    else
    {
      *(float *)&dest[v1] = TickTime;
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
            v16 = v15 % 8;
            ++v15;
            --v9;
            v10 = v10 + *(float *)&dest[v16];
          }
          while ( v9 >= 0 );
        }
      }
      v7 = v10 / (float)v2;
    }
LABEL_17:
    SystemElapsedMSecs = UFG::qGetSystemElapsedMSecs();
    UFG::Metrics::UpdateAll(SystemElapsedMSecs, v7, 1, v8);
    updated = Render::UpdateGameSystems(UFG::Metrics::msRealTimeDelta_Accurate);
    UFG::BenchmarkHelper::Update(&UFG::BenchmarkHelper::gBenchmarkHelper);
    if ( updated )
    {
      gGovernMaxFrameRate = 0;
      CurrentState = UFG::FlowController::GetCurrentState(&UFG::gFlowController);
      GameStateObj = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, CurrentState);
      if ( GameStateObj )
      {
        if ( CurrentState == uidGameStateInGame_14 )
        {
          v21 = GameStateObj->vfptr->ModeIsSet(GameStateObj, eGSM_PAUSED);
          v22 = gGovernMaxFrameRate;
          if ( v21 )
            v22 = 1;
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
      v0 = Render::RenderFrame(UFG::Metrics::msRealTimeDelta_Accurate);
    }
    if ( !v0 )
      break;
    v4 = gGameQuitEvent;
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__m_ExeName__);
}

// File Line: 572
// RVA: 0xA403A0
int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  const char *CommandLineA; // rax
  UFG::qString *FilenameWithoutExtension; // rax
  int v8; // eax
  char v9; // dl
  HANDLE MutexA; // rsi
  HANDLE CurrentProcess; // rax
  UFG::qString *FilePath; // rax
  hkpEntity *v19; // rdx
  hkEntitySelectorAll *v20; // rcx
  __int64 v21; // rcx
  UFG::qString result; // [rsp+50h] [rbp-488h] BYREF
  UFG::qString v23; // [rsp+78h] [rbp-460h] BYREF
  UFG::qString v24; // [rsp+A0h] [rbp-438h] BYREF
  char format[1024]; // [rsp+D0h] [rbp-408h] BYREF

  CommandLineA = GetCommandLineA();
  UFG::qString::qString(&v23, CommandLineA);
  FilenameWithoutExtension = UFG::qString::GetFilenameWithoutExtension(&v23, &result);
  UFG::qString::Set(&m_ExeName, FilenameWithoutExtension->mData, FilenameWithoutExtension->mLength, 0i64, 0);
  UFG::qString::~qString(&result);
  SystemParametersInfoA(0x3Au, 8u, &g_StartupStickyKeys, 0);
  SystemParametersInfoA(0x34u, 8u, &g_StartupToggleKeys, 0);
  SystemParametersInfoA(0x32u, 0x18u, &g_StartupFilterKeys, 0);
  v8 = UFG::qString::find(&v23, "-benchmark");
  v9 = gAutoBenchmarkMode;
  if ( v8 != UFG::qString::npos )
    v9 = 1;
  gAutoBenchmarkMode = v9;
  MutexA = CreateMutexA(0i64, 0, "UFG_GameMutex_SD2");
  if ( GetLastError() == 183 )
  {
    CloseHandle(MutexA);
    exit(1);
  }
  _RAX = 1i64;
  __asm { cpuid; Get CPU ID }
  if ( (_RDX & 0x4000000) != 0 )
  {
    CurrentProcess = GetCurrentProcess();
    if ( (unsigned int)GetModuleFileNameExA_0(CurrentProcess, 0i64, format, 1024i64) )
    {
      UFG::qString::qString(&result, format);
      FilePath = UFG::qString::GetFilePath(&result, &v24);
      UFG::qSetDirectory(FilePath->mData);
      UFG::qString::~qString(&v24);
      UFG::qString::~qString(&result);
    }
    gInstance = hInstance;
    gCmdShow = nShowCmd;
    if ( !SteamIntegration::InitAPI(SteamAPITextHook, (void (__fastcall *)())_, 0) )
      exit(1);
    pcPushState();
    InitGameSystems(v20, v19);
    MainLoop();
    if ( hhkLowLevelKybd )
    {
      UnhookWindowsHookEx(hhkLowLevelKybd);
      hhkLowLevelKybd = 0i64;
    }
    UFG::AllowAccessibilityShortcutKeys(1);
    CloseGameSystems();
    CloseRenderEngine();
    SteamIntegration::CloseAPI(v21);
    CloseHandle(MutexA);
    exit(1);
  }
  UFG::qString::~qString(&v23);
  return 1;
}

// File Line: 718
// RVA: 0x141EFC0
WinMain$catch$0

