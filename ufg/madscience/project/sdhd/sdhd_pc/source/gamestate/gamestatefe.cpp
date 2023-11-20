// File Line: 41
// RVA: 0x410590
void __fastcall UFG::GameStateFE::OnEnter(UFG::GameStateFE *this, float fRealTimeDelta)
{
  UFG::GameStateFE *v2; // rdi
  ANTLR3_INPUT_STREAM_struct *v3; // rax
  const char *v4; // rbx
  UFG::ProgressionTracker *v5; // rax
  UFG::UIScreenTextureManager *v6; // rax

  v2 = this;
  gbUseHotswapping = 0;
  UFG::HotSwapFileManager::SetEnabled(0);
  UFG::RenderWorld::SetRenderWorld(0);
  UFG::UIHK_NISOverlay::SetCurtainStateCallbacks(0i64, 0i64);
  v3 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::SetGameState(v3, 1u);
  *(_QWORD *)UFG::Metrics::msFramesPerSecBuckets = 0i64;
  qword_14235C0D0 = 0i64;
  qword_14235C0D8 = 0i64;
  dword_14235C0E0 = 0;
  v4 = v2->mGameStateUserDataStr.mData;
  if ( *v4 )
  {
    UFG::qString::Set(&v2->mGameStateUserDataStr, &customWorldMapCaption);
  }
  else
  {
    v5 = UFG::ProgressionTracker::Instance();
    v4 = UFG::ProgressionTracker::GetGameSetup(v5)->mInitMenu;
  }
  v6 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v6, v4, 0i64);
  UFG::InputSystem::SetShouldRestrictCursor(0, 0, 1, 1);
  UFG::InputSystem::SetShouldHideCursor(1, 0, 1, 0);
  UFG::InputSystem::msRelativeMouseMode = 0;
}

// File Line: 93
// RVA: 0x4121F0
void __fastcall UFG::GameStateFE::OnUpdate(UFG::GameStateFE *this, float fRealTimeDelta)
{
  UFG *v2; // rcx
  AMD_HD3D *v3; // rax

  ((void (*)(void))UFG::gInputSystem->vfptr->Update)();
  CheckForConsoleInput(v2);
  v3 = (AMD_HD3D *)UserManager::GetInstance();
  _(v3);
  ((void (*)(void))UFG::UIScreenManager::s_instance->vfptr->update)();
}

// File Line: 113
// RVA: 0x408250
bool __fastcall UFG::GameStateFE::CanSwitchFrom(UFG::GameState *this, unsigned int stateUID)
{
  return stateUID != this->mGameStateUID;
}

