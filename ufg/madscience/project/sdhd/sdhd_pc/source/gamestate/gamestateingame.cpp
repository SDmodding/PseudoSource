// File Line: 92
// RVA: 0x410660
void __fastcall UFG::GameStateInGame::OnEnter(UFG::GameStateInGame *this, float fRealTimeDelta)
{
  char v3; // cl
  UFG::GameStatTracker *v4; // rax

  gbUseHotswapping = 0;
  UFG::HotSwapFileManager::SetEnabled(0);
  this->vfptr->ModeSet(this, eGSM_PAUSED, 0);
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
  ((void (__fastcall *)(UFG::UIScreenManager *))UFG::UIScreenManager::s_instance->vfptr->update)(UFG::UIScreenManager::s_instance);
}

// File Line: 156
// RVA: 0x412240
void __fastcall UFG::GameStateInGame::OnUpdate(UFG::GameStateInGame *this, float fRealTimeDelta)
{
  AMD_HD3D *Instance; // rax
  UFG *v4; // rcx
  float mSimTimeDelta; // xmm6_4
  Render *v6; // rcx
  UFG::SimObjectCharacter *LocalPlayer; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float v9; // xmm2_4
  float v10; // xmm3_4
  unsigned int CellIndexAtPosition; // ebx
  Render *v12; // rcx
  float v13; // xmm0_4
  AMD_HD3D *v14; // rcx
  UFG::qVector3 position; // [rsp+20h] [rbp-48h] BYREF

  Instance = (AMD_HD3D *)UserManager::GetInstance();
  _(Instance);
  if ( this->mUpdateCount )
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
  ++this->mUpdateCount;
  ((void (__fastcall *)(UFG::InputSystem *))UFG::gInputSystem->vfptr->Update)(UFG::gInputSystem);
  CheckForConsoleInput(v4);
  if ( !this->mUpdateSim )
  {
    gUIUpdateDelta = fRealTimeDelta;
    UFG::UI::gUpdateWorldPos = 1;
    ((void (__fastcall *)(UFG::UIScreenManager *))UFG::UIScreenManager::s_instance->vfptr->update)(UFG::UIScreenManager::s_instance);
    UFG::PhotoManager::Update(fRealTimeDelta);
    return;
  }
  mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
  LocalPlayer = UFG::GetLocalPlayer();
  if ( UFG::GameSetup::msProject || !this->vfptr->ModeIsSet(this, eGSM_PAUSED) )
  {
    if ( mSimTimeDelta > 0.0 )
    {
      if ( LocalPlayer )
      {
        m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        v9 = (float)(m_pTransformNodeComponent->mWorldVelocity.z * 0.06666667)
           + m_pTransformNodeComponent->mWorldTransform.v3.z;
        v10 = (float)(m_pTransformNodeComponent->mWorldVelocity.y * 0.06666667)
            + m_pTransformNodeComponent->mWorldTransform.v3.y;
        position.x = (float)(m_pTransformNodeComponent->mWorldVelocity.x * 0.06666667)
                   + m_pTransformNodeComponent->mWorldTransform.v3.x;
        position.y = v10;
        position.z = v9;
        CellIndexAtPosition = UFG::SectionChooser::GetCellIndexAtPosition(&position, 0);
        if ( !UFG::SectionChooser::IsSectionVisible_CellIndex(CellIndexAtPosition, SCENERY_LAYER_STD, 0)
          && (*(_BYTE *)(UFG::SectionLayout::GetSectionFromCellIndex(CellIndexAtPosition) + 4) & 2) == 0 )
        {
          if ( !UFG::UIHK_NISOverlay::IsCurtainVisible()
            && NISManager::GetInstance()->mState == STATE_INVALID
            && freeze_time < 20.0 )
          {
            v13 = freeze_time + mSimTimeDelta;
            mSimTimeDelta = 0.0;
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
    mSimTimeDelta = 0.0;
  }
LABEL_19:
  gUIUpdateDelta = fRealTimeDelta;
  UFG::UpdateSim(mSimTimeDelta, UFG::CBUpdateUI);
  if ( !UFG::bCameraUseSimTime )
    mSimTimeDelta = fRealTimeDelta;
  UFG::UpdateCamera(mSimTimeDelta, v14);
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
bool __fastcall UFG::GameStateInGame::ModeSet(UFG::GameStateInGame *this, UFG::eGameStateMode mode, bool enable)
{
  bool result; // al
  bool v7; // si
  unsigned int v8; // edx
  NISManager *v9; // rax
  char *mData; // rsi
  unsigned int v11; // edx
  NISManager *Instance; // rax

  if ( mode == eGSM_PAUSED )
  {
    UFG::OnlineManager::Instance();
    UFG::Metrics::msInstance.mSimPausedInGame = enable;
    UFG::Metrics::msInstance.mSimTimeDeltaStep = 0.0;
    if ( enable == this->vfptr->ModeIsSet(this, eGSM_PAUSED) )
      return 0;
    if ( !enable )
    {
      v11 = UI_HASH_GAMESTATE_UNPAUSE_0;
      this->mUpdateSim = 1;
      UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, v11, 0xFFFFFFFF);
      Instance = NISManager::GetInstance();
      NISManager::Resume(Instance);
      UFG::MovieHandler::Unpause(&UFG::TheMovieHandler);
      if ( UFG::TiDo::GetIsInstantiated() )
        ((void (__fastcall *)(UFG::TiDo *, __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
          UFG::TiDo::m_pInstance,
          4i64);
      goto LABEL_27;
    }
    v7 = !this->vfptr->ModeIsSet(this, eGSM_PAUSED) || UFG::GameSetup::msProject;
    UFG::RenderWorld::SetRenderWorld(v7);
    v8 = UI_HASH_GAMESTATE_PAUSE_0;
    this->mUpdateSim = v7;
    UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, v8, 0xFFFFFFFF);
    v9 = NISManager::GetInstance();
    NISManager::Pause(v9);
    UFG::MovieHandler::Pause(&UFG::TheMovieHandler);
    mData = this->mGameStateUserDataStr.mData;
    if ( *mData )
    {
      if ( (!(unsigned int)UFG::qStringCompare("PauseMenu", this->mGameStateUserDataStr.mData, -1)
         || !(unsigned int)UFG::qStringCompare("WorldMap", mData, -1)
         || !(unsigned int)UFG::qStringCompare("SocialHub", mData, -1)
         || !(unsigned int)UFG::qStringCompare("UIMenuActionMenu", mData, -1)
         || !(unsigned int)UFG::qStringCompare("UIMenuRacePaused", mData, -1))
        && UFG::TiDo::GetIsInstantiated() )
      {
        ((void (__fastcall *)(UFG::TiDo *, __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
          UFG::TiDo::m_pInstance,
          1i64);
      }
      if ( !(unsigned int)UFG::qStringCompare("NISPause", mData, -1) && UFG::TiDo::GetIsInstantiated() )
        ((void (__fastcall *)(UFG::TiDo *, __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
          UFG::TiDo::m_pInstance,
          10i64);
      UFG::qString::Set(&this->mGameStateUserDataStr, &customCaption);
    }
  }
  else if ( mode != eGSM_DEBUG_CAM || enable == this->vfptr->ModeIsSet(this, eGSM_DEBUG_CAM) )
  {
    return 0;
  }
  if ( enable )
  {
    this->mMode |= mode;
    return 1;
  }
LABEL_27:
  result = 1;
  this->mMode &= ~mode;
  return result;
}

