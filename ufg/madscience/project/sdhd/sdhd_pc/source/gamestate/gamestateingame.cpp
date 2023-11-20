// File Line: 92
// RVA: 0x410660
void __fastcall UFG::GameStateInGame::OnEnter(UFG::GameStateInGame *this, float fRealTimeDelta)
{
  UFG::GameStateInGame *v2; // rbx
  char v3; // cl
  UFG::GameStatTracker *v4; // rax

  v2 = this;
  gbUseHotswapping = 0;
  UFG::HotSwapFileManager::SetEnabled(0);
  v2->vfptr->ModeSet((UFG::GameState *)&v2->vfptr, eGSM_PAUSED, 0);
  *(_QWORD *)UFG::Metrics::msFramesPerSecBuckets = 0i64;
  qword_14235C0D0 = 0i64;
  qword_14235C0D8 = 0i64;
  dword_14235C0E0 = 0;
  v3 = did_rebuild;
  if ( !did_rebuild )
    v3 = 1;
  did_rebuild = v3;
  v4 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::StartGameStatTimers(v4);
  UFG::InputSystem::SetShouldRestrictCursor(0, 1, 1, 1);
  UFG::InputSystem::SetShouldHideCursor(1, 1, 1, 1);
  UFG::InputSystem::msRelativeMouseMode = 1;
}

// File Line: 146
// RVA: 0x408080
void __fastcall UFG::CBUpdateUI(float deltaTime)
{
  UFG::UI::gUpdateWorldPos = 1;
  ((void (*)(void))UFG::UIScreenManager::s_instance->vfptr->update)();
}

// File Line: 156
// RVA: 0x412240
void __fastcall UFG::GameStateInGame::OnUpdate(UFG::GameStateInGame *this, float fRealTimeDelta)
{
  UFG::GameStateInGame *v2; // rbx
  AMD_HD3D *v3; // rax
  UFG *v4; // rcx
  float v5; // xmm6_4
  Render *v6; // rcx
  UFG::SimObjectCharacter *v7; // rdi
  UFG::TransformNodeComponent *v8; // rbx
  float v9; // xmm2_4
  float v10; // xmm3_4
  unsigned int v11; // ebx
  Render *v12; // rcx
  float v13; // xmm0_4
  AMD_HD3D *v14; // rcx
  UFG::qVector3 position; // [rsp+20h] [rbp-48h]

  v2 = this;
  v3 = (AMD_HD3D *)UserManager::GetInstance();
  _(v3);
  if ( v2->mUpdateCount )
  {
    if ( !dump )
      goto LABEL_5;
  }
  else
  {
    UFG::RenderWorld::SetRenderWorld(1);
  }
  dump = 0;
LABEL_5:
  ++v2->mUpdateCount;
  ((void (*)(void))UFG::gInputSystem->vfptr->Update)();
  CheckForConsoleInput(v4);
  if ( !v2->mUpdateSim )
  {
    gUIUpdateDelta = fRealTimeDelta;
    UFG::UI::gUpdateWorldPos = 1;
    ((void (*)(void))UFG::UIScreenManager::s_instance->vfptr->update)();
    UFG::PhotoManager::Update(fRealTimeDelta);
    return;
  }
  v5 = UFG::Metrics::msInstance.mSimTimeDelta;
  v7 = UFG::GetLocalPlayer();
  if ( UFG::GameSetup::msProject || !v2->vfptr->ModeIsSet((UFG::GameState *)&v2->vfptr, eGSM_PAUSED) )
  {
    if ( v5 > 0.0 )
    {
      if ( v7 )
      {
        v8 = v7->m_pTransformNodeComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(v7->m_pTransformNodeComponent);
        UFG::TransformNodeComponent::UpdateWorldTransform(v8);
        v9 = (float)(v8->mWorldVelocity.z * 0.06666667) + v8->mWorldTransform.v3.z;
        v10 = (float)(v8->mWorldVelocity.y * 0.06666667) + v8->mWorldTransform.v3.y;
        position.x = (float)(v8->mWorldVelocity.x * 0.06666667) + v8->mWorldTransform.v3.x;
        position.y = v10;
        position.z = v9;
        v11 = UFG::SectionChooser::GetCellIndexAtPosition(&position, 0);
        if ( !UFG::SectionChooser::IsSectionVisible_CellIndex(v11, SCENERY_LAYER_STD, 0)
          && !(*(_BYTE *)(UFG::SectionLayout::GetSectionFromCellIndex(v11) + 4) & 2) )
        {
          if ( !UFG::UIHK_NISOverlay::IsCurtainVisible()
            && NISManager::GetInstance()->mState == STATE_INVALID
            && freeze_time < 20.0 )
          {
            v13 = freeze_time + v5;
            v5 = 0.0;
            freeze_time = v13;
            Render::StartEmergencyLoadScreen(v12);
          }
          goto LABEL_19;
        }
        freeze_time = 0.0;
      }
      Render::StopEmergencyLoadScreen(v6);
    }
  }
  else
  {
    UFG::OnlineManager::Instance();
    v5 = 0.0;
  }
LABEL_19:
  gUIUpdateDelta = fRealTimeDelta;
  UFG::UpdateSim(v5, UFG::CBUpdateUI);
  if ( !UFG::bCameraUseSimTime )
    v5 = fRealTimeDelta;
  UFG::UpdateCamera(v5, v14);
  UFG::PhotoManager::Update(fRealTimeDelta);
}

// File Line: 412
// RVA: 0x410E10
void __fastcall UFG::GameStateInGame::OnExit(UFG::GameStateInGame *this, float fRealTimeDelta)
{
  UFG::GameStatTracker *v2; // rax

  this->mUpdateCount = 0;
  Render::StopEmergencyLoadScreen((Render *)this);
  v2 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::PauseGameStatTimers(v2);
}

// File Line: 425
// RVA: 0x40E8E0
bool __fastcall UFG::GameStateInGame::ModeSet(UFG::GameStateInGame *this, UFG::eGameStateMode mode, const bool enable)
{
  UFG::GameStateInGame *v3; // rbx
  bool v4; // bp
  UFG::eGameStateMode v5; // edi
  bool result; // al
  bool v7; // si
  unsigned int v8; // edx
  NISManager *v9; // rax
  const char *v10; // rsi
  unsigned int v11; // edx
  NISManager *v12; // rax

  v3 = this;
  v4 = enable;
  v5 = mode;
  if ( mode == 1 )
  {
    UFG::OnlineManager::Instance();
    UFG::Metrics::msInstance.mSimPausedInGame = v4;
    UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
    if ( v4 == v3->vfptr->ModeIsSet((UFG::GameState *)&v3->vfptr, eGSM_PAUSED) )
      return 0;
    if ( !v4 )
    {
      v11 = UI_HASH_GAMESTATE_UNPAUSE_0;
      v3->mUpdateSim = 1;
      UFG::UIScreenManagerBase::queueMessage(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        v11,
        0xFFFFFFFF);
      v12 = NISManager::GetInstance();
      NISManager::Resume(v12);
      UFG::MovieHandler::Unpause(&UFG::TheMovieHandler);
      if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
        ((void (__fastcall *)(UFG::TiDo *, signed __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
          UFG::TiDo::m_pInstance,
          4i64);
      goto LABEL_27;
    }
    v7 = !v3->vfptr->ModeIsSet((UFG::GameState *)&v3->vfptr, eGSM_PAUSED) || UFG::GameSetup::msProject;
    UFG::RenderWorld::SetRenderWorld(v7);
    v8 = UI_HASH_GAMESTATE_PAUSE_0;
    v3->mUpdateSim = v7;
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      v8,
      0xFFFFFFFF);
    v9 = NISManager::GetInstance();
    NISManager::Pause(v9);
    UFG::MovieHandler::Pause(&UFG::TheMovieHandler);
    v10 = v3->mGameStateUserDataStr.mData;
    if ( *v10 )
    {
      if ( (!(unsigned int)UFG::qStringCompare("PauseMenu", v3->mGameStateUserDataStr.mData, -1)
         || !(unsigned int)UFG::qStringCompare("WorldMap", v10, -1)
         || !(unsigned int)UFG::qStringCompare("SocialHub", v10, -1)
         || !(unsigned int)UFG::qStringCompare("UIMenuActionMenu", v10, -1)
         || !(unsigned int)UFG::qStringCompare("UIMenuRacePaused", v10, -1))
        && (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
      {
        ((void (__fastcall *)(UFG::TiDo *, signed __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
          UFG::TiDo::m_pInstance,
          1i64);
      }
      if ( !(unsigned int)UFG::qStringCompare("NISPause", v10, -1) && (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
        ((void (__fastcall *)(UFG::TiDo *, signed __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
          UFG::TiDo::m_pInstance,
          10i64);
      UFG::qString::Set(&v3->mGameStateUserDataStr, &customWorldMapCaption);
    }
  }
  else if ( mode != 2 || enable == this->vfptr->ModeIsSet((UFG::GameState *)this, eGSM_DEBUG_CAM) )
  {
    return 0;
  }
  if ( v4 )
  {
    v3->mMode |= v5;
    return 1;
  }
LABEL_27:
  result = 1;
  v3->mMode &= ~v5;
  return result;
}

