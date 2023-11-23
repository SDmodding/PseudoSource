// File Line: 136
// RVA: 0x14CF180
__int64 dynamic_initializer_for__nis_mixer_exit_to_game__()
{
  nis_mixer_exit_to_game.mUID = UFG::qWiseSymbolUIDFromString("nis_mixer_exit_to_game", 0x811C9DC5);
  _((AMD_HD3D *)nis_mixer_exit_to_game.mUID);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__nis_mixer_exit_to_game__);
}

// File Line: 137
// RVA: 0x14CF1D0
__int64 dynamic_initializer_for__nis_mixer_exit_to_game_instant__()
{
  nis_mixer_exit_to_game_instant.mUID = UFG::qWiseSymbolUIDFromString("nis_mixer_exit_to_game_instant", 0x811C9DC5);
  _((AMD_HD3D *)nis_mixer_exit_to_game_instant.mUID);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__nis_mixer_exit_to_game_instant__);
}

// File Line: 140
// RVA: 0x3E2FC0
void NISManager::Init(void)
{
  char *v0; // rax
  NISManager *v1; // rax
  UFG::qSharedString filename; // [rsp+40h] [rbp+8h] BYREF

  UFG::qSharedString::qSharedString(&filename, "Data\\AnimationNIS\\NISSpatialData.bin");
  gSpatialDataStreamPriorityHandle = UFG::StreamPrioritySystem::CreateHandle(
                                       NISManager::sStreamPrioritySystem,
                                       &filename);
  UFG::qSharedString::~qSharedString(&filename);
  UFG::StreamPrioritySystem::ChangePriority(
    NISManager::sStreamPrioritySystem,
    (UFG::qPropertySet *)gSpatialDataStreamPriorityHandle,
    0x100000u);
  v0 = (char *)UFG::qMalloc(0x330ui64, "NISManager", 0i64);
  filename.mText = v0;
  if ( v0 )
  {
    NISManager::NISManager((NISManager *)v0);
    NISManager::sInstance = v1;
  }
  else
  {
    NISManager::sInstance = 0i64;
  }
}

// File Line: 175
// RVA: 0x3E4330
void NISManager::Quit(void)
{
  NISManager *v0; // rbx

  v0 = NISManager::sInstance;
  if ( NISManager::sInstance )
  {
    NISManager::~NISManager(NISManager::sInstance);
    operator delete[](v0);
    NISManager::sInstance = 0i64;
  }
  if ( gSpatialDataStreamPriorityHandle )
  {
    UFG::StreamPrioritySystem::FreeHandle(NISManager::sStreamPrioritySystem, gSpatialDataStreamPriorityHandle);
    gSpatialDataStreamPriorityHandle = 0i64;
  }
}

// File Line: 200
// RVA: 0x3E2D10
NISManager *__fastcall NISManager::GetInstance()
{
  return NISManager::sInstance;
}

// File Line: 211
// RVA: 0x3E01C0
void __fastcall NISManager::NISManager(NISManager *this)
{
  ActionContext *v2; // rdi
  ActionController *p_mActionController; // rsi
  UFG::allocator::free_link *v4; // rax
  ActionContext *v5; // rax
  ActionContext *mpActionContext; // rax

  this->mpActiveInstance.mPrev = &this->mpActiveInstance;
  this->mpActiveInstance.mNext = &this->mpActiveInstance;
  v2 = 0i64;
  this->mpActiveInstance.m_pPointer = 0i64;
  this->mpPreloadInstance.mPrev = &this->mpPreloadInstance;
  this->mpPreloadInstance.mNext = &this->mpPreloadInstance;
  this->mpPreloadInstance.m_pPointer = 0i64;
  this->mInstances.mNode.mPrev = &this->mInstances.mNode;
  this->mInstances.mNode.mNext = &this->mInstances.mNode;
  p_mActionController = &this->mActionController;
  ActionController::ActionController(&this->mActionController);
  UFG::qResourceHandle::qResourceHandle(&this->mSpatialDataHandle);
  this->mpDynamicOutline = 0i64;
  this->mDisabledVehicle.mPrev = &this->mDisabledVehicle;
  this->mDisabledVehicle.mNext = &this->mDisabledVehicle;
  this->mDisabledVehicle.m_pPointer = 0i64;
  this->mbAudioStopped = 0;
  this->mUIHelpbarLocked = 0;
  UFG::SceneSettings::SceneSettings(&this->mPostNisSettings, "NisManager");
  this->mPlaceHolderTimeOut = 0.0;
  v4 = UFG::qMalloc(0xD8ui64, "ActionTreeComponent::ActionContext", 0i64);
  if ( v4 )
  {
    ActionContext::ActionContext((ActionContext *)v4);
    v2 = v5;
  }
  this->mpActionContext = v2;
  ActionContext::Reset(v2, eACTION_TREE_TYPE_ACTION, 0i64);
  mpActionContext = this->mpActionContext;
  this->mActionController.m_Context = mpActionContext;
  mpActionContext->mActionController = p_mActionController;
  this->mActionController.mKeepAlive = 0;
  NISManager::Reset(this);
}

// File Line: 223
// RVA: 0x3E0BB0
void __fastcall NISManager::~NISManager(NISManager *this)
{
  ActionContext *mpActionContext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mDisabledVehicle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v13; // rax
  UFG::qSafePointer<NISInstance,NISInstance> *p_mpPreloadInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v22; // rax

  NISManager::AllowGameStateChanges(this);
  NISManager::StopNIS(this);
  NISManager::ResetNISSettings(this);
  NISManager::Reset(this);
  mpActionContext = this->mpActionContext;
  if ( mpActionContext )
  {
    if ( mpActionContext->mSimObject.m_pPointer )
    {
      mPrev = mpActionContext->mSimObject.mPrev;
      mNext = mpActionContext->mSimObject.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      mpActionContext->mSimObject.mPrev = &mpActionContext->mSimObject;
      mpActionContext->mSimObject.mNext = &mpActionContext->mSimObject;
    }
    mpActionContext->mSimObject.m_pPointer = 0i64;
    v5 = mpActionContext->mSimObject.mPrev;
    v6 = mpActionContext->mSimObject.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    mpActionContext->mSimObject.mPrev = &mpActionContext->mSimObject;
    mpActionContext->mSimObject.mNext = &mpActionContext->mSimObject;
    operator delete[](mpActionContext);
  }
  UFG::SceneSettings::~SceneSettings(&this->mPostNisSettings);
  p_mDisabledVehicle = &this->mDisabledVehicle;
  if ( this->mDisabledVehicle.m_pPointer )
  {
    v8 = p_mDisabledVehicle->mPrev;
    v9 = this->mDisabledVehicle.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mDisabledVehicle->mPrev = p_mDisabledVehicle;
    this->mDisabledVehicle.mNext = &this->mDisabledVehicle;
  }
  this->mDisabledVehicle.m_pPointer = 0i64;
  v10 = p_mDisabledVehicle->mPrev;
  v11 = this->mDisabledVehicle.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mDisabledVehicle->mPrev = p_mDisabledVehicle;
  this->mDisabledVehicle.mNext = &this->mDisabledVehicle;
  Inventory = `UFG::qGetResourceInventory<UFG::NISSpatialData>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::NISSpatialData>::`2::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v13, 0x59362AA3u);
    `UFG::qGetResourceInventory<UFG::NISSpatialData>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mSpatialDataHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mSpatialDataHandle);
  ActionController::~ActionController(&this->mActionController);
  UFG::qList<NISInstance,NISInstanceMasterList,0,0>::~qList<NISInstance,NISInstanceMasterList,0,0>(&this->mInstances);
  p_mpPreloadInstance = &this->mpPreloadInstance;
  if ( this->mpPreloadInstance.m_pPointer )
  {
    v15 = p_mpPreloadInstance->mPrev;
    v16 = this->mpPreloadInstance.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    p_mpPreloadInstance->mPrev = p_mpPreloadInstance;
    this->mpPreloadInstance.mNext = &this->mpPreloadInstance;
  }
  this->mpPreloadInstance.m_pPointer = 0i64;
  v17 = p_mpPreloadInstance->mPrev;
  v18 = this->mpPreloadInstance.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  p_mpPreloadInstance->mPrev = p_mpPreloadInstance;
  this->mpPreloadInstance.mNext = &this->mpPreloadInstance;
  if ( this->mpActiveInstance.m_pPointer )
  {
    v19 = this->mpActiveInstance.mPrev;
    v20 = this->mpActiveInstance.mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    this->mpActiveInstance.mPrev = &this->mpActiveInstance;
    this->mpActiveInstance.mNext = &this->mpActiveInstance;
  }
  this->mpActiveInstance.m_pPointer = 0i64;
  v21 = this->mpActiveInstance.mPrev;
  v22 = this->mpActiveInstance.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  this->mpActiveInstance.mPrev = &this->mpActiveInstance;
  this->mpActiveInstance.mNext = &this->mpActiveInstance;
}

// File Line: 230
// RVA: 0x3E3B30
char __fastcall NISManager::Play(NISManager *this, const char *pathName)
{
  NISInstance *Instance; // rax

  Instance = NISManager::CreateInstance(this, pathName);
  Instance->mbDestroyOnUnload = 1;
  Instance->mbPostNISFadeIn = 1;
  return NISManager::PlayInternal(this, Instance);
}

// File Line: 246
// RVA: 0x3E3B20
// attributes: thunk
char __fastcall NISManager::Play(NISManager *this, NISInstance *pInstance)
{
  return NISManager::PlayInternal(this, pInstance);
}

// File Line: 251
// RVA: 0x3E3840
void __fastcall NISManager::Pause(NISManager *this)
{
  this->mPaused = 1;
}

// File Line: 256
// RVA: 0x3E4A20
void __fastcall NISManager::Resume(NISManager *this)
{
  this->mPaused = 0;
}

// File Line: 261
// RVA: 0x3E4290
void __fastcall NISManager::PreventGameStateChanges(NISManager *this)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  this->mModifyPlayerVulnerability = 0;
  LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = LocalPlayer->m_Components.p[6].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::HealthComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::HealthComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = LocalPlayer->m_Components.p[6].m_pComponent;
    }
    if ( m_pComponent )
    {
      this->mModifyPlayerVulnerability = BYTE5(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) == 0;
      BYTE5(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) = 1;
    }
  }
}

// File Line: 278
// RVA: 0x3E15E0
void __fastcall NISManager::AllowGameStateChanges(NISManager *this)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax

  LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = LocalPlayer->m_Components.p[6].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::HealthComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::HealthComponent::_TypeUID);
    }
    else
    {
      m_pComponent = LocalPlayer->m_Components.p[6].m_pComponent;
    }
    if ( m_pComponent )
    {
      if ( this->mModifyPlayerVulnerability )
        BYTE5(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) = 0;
    }
  }
}

// File Line: 292
// RVA: 0x3E4560
void __fastcall NISManager::Reset(NISManager *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  NISInstance *m_pPointer; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mDisabledVehicle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  ActionController::Stop(&this->mActionController);
  Inventory = `UFG::qGetResourceInventory<UFG::NISSpatialData>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::NISSpatialData>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x59362AA3u);
    `UFG::qGetResourceInventory<UFG::NISSpatialData>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mSpatialDataHandle, Inventory);
  if ( this->mpDynamicOutline )
  {
    ((void (__fastcall *)(UFG::NavManager *))UFG::NavManager::ms_pInstance->vfptr->RemoveDynamicOutline)(UFG::NavManager::ms_pInstance);
    this->mpDynamicOutline = 0i64;
  }
  this->mPaused = 0;
  this->mState = STATE_INVALID;
  *(_QWORD *)&this->mfStateTimeoutS = 2139095039i64;
  *(_QWORD *)&this->mTime = 0i64;
  this->mTimeToEndAt = -1.0;
  *(_QWORD *)&this->mAudioTime = -1082130432i64;
  *(_WORD *)&this->mbCurtainsShown = 0;
  this->mbUserInputDisabled = 0;
  *(_QWORD *)&this->mHudDisableCount = 0i64;
  this->mbStreamingComplete = 0;
  UFG::SceneSettings::Reset(&this->mPostNisSettings);
  m_pPointer = this->mpActiveInstance.m_pPointer;
  if ( m_pPointer )
  {
    NISInstance::Unload(m_pPointer, 1);
    if ( this->mpActiveInstance.m_pPointer )
    {
      mPrev = this->mpActiveInstance.mPrev;
      mNext = this->mpActiveInstance.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      this->mpActiveInstance.mPrev = &this->mpActiveInstance;
      this->mpActiveInstance.mNext = &this->mpActiveInstance;
    }
    this->mpActiveInstance.m_pPointer = 0i64;
  }
  p_mDisabledVehicle = &this->mDisabledVehicle;
  if ( this->mDisabledVehicle.m_pPointer )
  {
    v8 = p_mDisabledVehicle->mPrev;
    v9 = this->mDisabledVehicle.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mDisabledVehicle->mPrev = p_mDisabledVehicle;
    this->mDisabledVehicle.mNext = &this->mDisabledVehicle;
  }
  this->mDisabledVehicle.m_pPointer = 0i64;
  this->mbAudioStopped = 0;
}

// File Line: 342
// RVA: 0x3E5D10
void __fastcall NISManager::SetupNISSettingsPreStreamed(NISManager *this)
{
  NISInstance *m_pPointer; // rax
  UFG::SceneSettings *p_mPostNisSettings; // rbp
  UFG::SceneSettings *mpPostNISSceneSettings; // rdx
  NISNode *mpNISNode; // rsi
  UFG::SceneSettings *v6; // rcx
  NISInstance *v7; // rcx
  bool v8; // al
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::ObjectResourceManager *v11; // rax
  UFG::PedSpawnManager *Instance; // rax
  UFG::TimeOfDayManager *v13; // rax
  UFG::TimeOfDayManager *v14; // rdi
  float mTODTime; // xmm0_4
  float m_SecondsSinceMidnight; // xmm0_4
  float v17; // xmm1_4
  UFG::TimeOfDayManager *v18; // rax
  UFG::TimeOfDayManager *v19; // rdi
  bool v20; // zf
  __int64 mValue; // rax
  float v22; // xmm1_4
  float v23; // xmm0_4
  float mWeatherWetness; // xmm1_4
  UFG::PedSpawnManager *v25; // rax
  UFG::CopSystem *v26; // rax
  UFG::CopSystem *v27; // rax
  __int64 v28; // [rsp+20h] [rbp-28h]
  float v29; // [rsp+28h] [rbp-20h]
  int v30; // [rsp+2Ch] [rbp-1Ch]
  float v31; // [rsp+30h] [rbp-18h]
  int v32; // [rsp+34h] [rbp-14h]
  int timeInSeconds; // [rsp+50h] [rbp+8h] BYREF

  m_pPointer = this->mpActiveInstance.m_pPointer;
  p_mPostNisSettings = &this->mPostNisSettings;
  mpPostNISSceneSettings = m_pPointer->mpPostNISSceneSettings;
  mpNISNode = m_pPointer->mpNISNode;
  v6 = &this->mPostNisSettings;
  if ( mpPostNISSceneSettings )
    UFG::SceneSettings::operator=(v6, mpPostNISSceneSettings);
  else
    UFG::SceneSettings::Reset(v6);
  v7 = this->mpActiveInstance.m_pPointer;
  this->mPostNisSettings.mShowCurtains = 0;
  this->mPostNisSettings.mHideCurtains = v7->mbPostNISFadeIn;
  if ( v7->mbIntermediateNIS )
  {
    v8 = UFG::WheeledVehicleManager::mTrafficCarSpawningEnabled
      && UFG::WheeledVehicleManager::m_TrafficSpawningUpdatesEnabled;
    this->mPostNisSettings.mEnableTrafficOnEnd = v8;
    this->mPostNisSettings.mEnableAmbientPedsOnEnd = UFG::PedSpawnManager::msAmbientSpawningEnable;
  }
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CameraAnimationComponent::_TypeUID);
    if ( ComponentOfType )
      HIBYTE(ComponentOfType[2].m_Flags) = 1;
  }
  if ( mpNISNode->mDisableAmbientPeds && !mpNISNode->mSeamlessOut )
  {
    UFG::PedSpawning_AmbientPedEnableHelper(0);
    UFG::WheeledVehicleManager::EnableTrafficSystem(UFG::WheeledVehicleManager::m_Instance, 0);
    v11 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::ReleaseAllAmbientPreloads(v11);
    this->mPostNisSettings.mResetAmbientPeds = 1;
  }
  if ( mpNISNode->mDisableScriptedPeds )
  {
    Instance = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::SuspendAllScripted(Instance);
    UFG::PedSpawnManager::SetScriptedStatusCheckEnable(0);
    if ( UFG::PedSpawnManager::msAmbientSpawningEnable )
      UFG::PedSpawnManager::SetAmbientSpawningEnable(0);
    this->mPostNisSettings.mResetAmbientPeds = 1;
  }
  v13 = UFG::TimeOfDayManager::GetInstance();
  v14 = v13;
  if ( this->mPostNisSettings.mTimeOverrideInSeconds < 0.0 )
    this->mPostNisSettings.mTimeOverrideInSeconds = v13->m_SecondsSinceMidnight;
  if ( !this->mPostNisSettings.mTimeOverrideLockSet )
  {
    p_mPostNisSettings->mTimeOverrideLock = v13->m_GameSecondsPerRealSecond == 0.0;
    p_mPostNisSettings->mTimeOverrideLockSet = 1;
  }
  if ( mpNISNode->mInteriorTime )
  {
    UFG::TimeOfDayManager::SetTime(v13, 82800.0, 0);
    TimePlotPoint::SetTimeValue(v14, 0.0);
    goto LABEL_36;
  }
  if ( mpNISNode->mTODTime < 0.0 )
  {
    if ( mpNISNode->mForceContinousTimeMode )
      goto LABEL_36;
    m_SecondsSinceMidnight = v13->m_SecondsSinceMidnight;
    v17 = FLOAT_39600_0;
    if ( m_SecondsSinceMidnight <= 39600.0 )
    {
      if ( m_SecondsSinceMidnight <= 45000.0 )
        goto LABEL_36;
    }
    else if ( m_SecondsSinceMidnight <= 45000.0 )
    {
LABEL_35:
      UFG::TimeOfDayManager::SetTime(v13, v17, 0);
      goto LABEL_36;
    }
    v17 = FLOAT_50400_0;
    if ( m_SecondsSinceMidnight >= 50400.0 )
      goto LABEL_36;
    goto LABEL_35;
  }
  mTODTime = mpNISNode->mTODTime;
  timeInSeconds = 0;
  if ( UFG::TimeOfDayManager::GetTimeInSeconds(mTODTime, &timeInSeconds) )
  {
    UFG::TimeOfDayManager::SetTime(v14, (float)timeInSeconds, 0);
    TimePlotPoint::SetTimeValue(v14, 40.0);
  }
LABEL_36:
  v14->mGlobalIlluminationBlend = mpNISNode->mGI_Irradiance;
  v18 = UFG::TimeOfDayManager::GetInstance();
  v19 = v18;
  if ( this->mPostNisSettings.mWeatherOverrideIntensity < 0.0 )
    this->mPostNisSettings.mWeatherOverrideIntensity = v18->m_WeatherState;
  if ( !this->mPostNisSettings.mWeatherOverrideLockSet )
  {
    v20 = v18->m_WeatherRandomInterval == 0;
    p_mPostNisSettings->mWeatherOverrideLockSet = 1;
    p_mPostNisSettings->mWeatherOverrideLock = v20;
  }
  if ( this->mPostNisSettings.mWeatherOverrideWetness < 0.0 )
    this->mPostNisSettings.mWeatherOverrideWetness = v18->m_OverrideSurfaceWetness;
  UFG::TimeOfDayManager::LockWeather(v18, 1);
  mValue = (int)mpNISNode->mWeatherType.mValue;
  if ( (_DWORD)mValue )
  {
    v28 = 0i64;
    v32 = 0x40000000;
    v29 = FLOAT_0_1;
    v30 = (int)FLOAT_1_0;
    v22 = FLOAT_2_0;
    v31 = FLOAT_1_5;
    v23 = *((float *)&v28 + mValue);
    if ( v23 <= 0.0 )
    {
      v23 = 0.0;
    }
    else if ( v23 >= 2.0 )
    {
      goto LABEL_48;
    }
    v22 = v23;
LABEL_48:
    v19->m_WeatherState = v22;
    v19->m_WeatherTarget = v22;
    v19->m_NextWeatherTarget = v22;
  }
  mWeatherWetness = mpNISNode->mWeatherWetness;
  if ( mWeatherWetness >= 0.0 )
    UFG::TimeOfDayManager::SetSurfaceWetnessOverride(v19, mWeatherWetness, "NISManager::SetupNISSettingsPreStreamed");
  UFG::StreamedResourceComponent::sAssetLoadDistance = FLOAT_3_4028235e38;
  Render::SetVSyncEnable(VSYNC_TRUE);
  v25 = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::SetupSocialForNIS(v25, 1);
  v26 = UFG::CopSystem::Instance();
  this->mWasCopSystemEnabled = ((__int64 (__fastcall *)(UFG::CopSystem *))v26->vfptr[7].__vecDelDtor)(v26);
  v27 = UFG::CopSystem::Instance();
  v27->vfptr[4].__vecDelDtor(v27, 0);
}

// File Line: 505
// RVA: 0x3E5770
void __fastcall NISManager::SetupNISSettingsPostStreamed(NISManager *this)
{
  NISNode *mpNISNode; // r15
  UFG::TiDo *Instance; // rax
  _BOOL8 v4; // rdx
  unsigned __int64 v5; // rax
  const char *v6; // rcx
  const char *v7; // rcx
  unsigned int v8; // eax
  UFG::SimComponent *v9; // r14
  UFG::VehicleOwnershipComponent *v10; // rsi
  signed __int16 m_Flags; // dx
  UFG::VehicleOwnershipComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *OwnedVehicle; // rax
  __int16 v14; // dx
  UFG::PhysicsMoverInterface *ComponentOfType; // rax
  UFG::SimObjectGame *v16; // rax
  __int16 v17; // dx
  UFG::VehicleEffectsComponent *m_pComponent; // rax
  const char *v19; // rcx
  unsigned int v20; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v22; // rax
  UFG::qResourceData *mData; // r12
  float v24; // xmm2_4
  float v25; // xmm4_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm1_4
  UFG::PedSpawnManager *v31; // rax
  UFG::SimObjectGame *v32; // rax
  UFG::SimObject *v33; // rbx
  __int16 v34; // cx
  UFG::SimComponent *v35; // rax
  float *mNext; // rax
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  UFG::qVector3 max; // [rsp+30h] [rbp-29h] BYREF
  UFG::qVector3 min; // [rsp+40h] [rbp-19h] BYREF
  __int128 v44[3]; // [rsp+50h] [rbp-9h] BYREF
  float v45; // [rsp+80h] [rbp+27h]
  float v46; // [rsp+84h] [rbp+2Bh]
  float v47; // [rsp+88h] [rbp+2Fh]
  int v48; // [rsp+8Ch] [rbp+33h]

  mpNISNode = this->mpActiveInstance.m_pPointer->mpNISNode;
  if ( UFG::TiDo::GetInstance() )
  {
    Instance = UFG::TiDo::GetInstance();
    LOBYTE(v4) = 1;
    Instance->vfptr->SetNISMode(Instance, v4);
  }
  v5 = mpNISNode->mLightLayerDisableName.mOffset & 0xFFFFFFFFFFFFFFFEui64;
  if ( v5 )
    v6 = (char *)&mpNISNode->mLightLayerDisableName + v5;
  else
    v6 = BinString::sEmptyString;
  if ( *v6 )
  {
    if ( v5 )
      v7 = (char *)&mpNISNode->mLightLayerDisableName + v5;
    else
      v7 = BinString::sEmptyString;
    v8 = UFG::qStringHashUpper32(v7, -1);
    this->mLightLayerUID = v8;
    Render::EnableLightLayer(v8, 0);
  }
  v9 = 0i64;
  if ( !LocalPlayer )
  {
    v10 = 0i64;
    goto LABEL_43;
  }
  m_Flags = LocalPlayer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    ComponentOfTypeHK = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            LocalPlayer,
                                                            UFG::VehicleOwnershipComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::VehicleOwnershipComponent *)UFG::SimObject::GetComponentOfType(
                                                            LocalPlayer,
                                                            UFG::VehicleOwnershipComponent::_TypeUID);
  v10 = ComponentOfTypeHK;
  if ( ComponentOfTypeHK && UFG::VehicleOwnershipComponent::GetOwnedVehicle(ComponentOfTypeHK) )
  {
    OwnedVehicle = (UFG::SimObjectGame *)UFG::VehicleOwnershipComponent::GetOwnedVehicle(v10);
    if ( OwnedVehicle )
    {
      v14 = OwnedVehicle->m_Flags;
      if ( (v14 & 0x4000) == 0 )
      {
        if ( v14 >= 0 )
        {
          if ( (v14 & 0x2000) != 0 )
            goto LABEL_32;
          if ( (v14 & 0x1000) != 0 )
            ComponentOfType = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              OwnedVehicle,
                                                              UFG::PhysicsMoverInterface::_TypeUID);
          else
            ComponentOfType = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                              OwnedVehicle,
                                                              UFG::PhysicsMoverInterface::_TypeUID);
        }
        else
        {
          ComponentOfType = (UFG::PhysicsMoverInterface *)OwnedVehicle->m_Components.p[34].m_pComponent;
        }
        if ( ComponentOfType )
          UFG::PhysicsMoverInterface::RepairDamage(ComponentOfType);
      }
    }
LABEL_32:
    v16 = (UFG::SimObjectGame *)UFG::VehicleOwnershipComponent::GetOwnedVehicle(v10);
    if ( !v16 )
      goto LABEL_43;
    v17 = v16->m_Flags;
    if ( (v17 & 0x4000) != 0 )
      goto LABEL_34;
    if ( v17 >= 0 )
    {
      if ( (v17 & 0x2000) != 0 || (v17 & 0x1000) != 0 )
      {
LABEL_34:
        m_pComponent = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v16,
                                                         UFG::VehicleEffectsComponent::_TypeUID);
        goto LABEL_41;
      }
      m_pComponent = (UFG::VehicleEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                       v16,
                                                       UFG::VehicleEffectsComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::VehicleEffectsComponent *)v16->m_Components.p[32].m_pComponent;
    }
LABEL_41:
    if ( m_pComponent )
      UFG::VehicleEffectsComponent::TurnOffEffects(m_pComponent, 0);
  }
LABEL_43:
  if ( (mpNISNode->mNISName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    v19 = (char *)&mpNISNode->mNISName + (mpNISNode->mNISName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
  else
    v19 = BinString::sEmptyString;
  v20 = UFG::qStringHash32(v19, 0xFFFFFFFF);
  Inventory = `UFG::qGetResourceInventory<UFG::NISSpatialData>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::NISSpatialData>::`2::result )
  {
    v22 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v22, 0x59362AA3u);
    `UFG::qGetResourceInventory<UFG::NISSpatialData>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mSpatialDataHandle, 0x59362AA3u, v20, Inventory);
  mData = this->mSpatialDataHandle.mData;
  if ( mData )
  {
    if ( mpNISNode->mUseBoundingBoxToClearPeds )
    {
      v24 = *(float *)&mData[1].mResourceHandles.mNode.mPrev;
      v25 = *(float *)&mData[1].mNode.mUID;
      v26 = v25 - *(float *)&mData[1].mNode.mParent;
      v27 = *((float *)&mData[1].mNode.mUID + 1) - *((float *)&mData[1].mNode.mParent + 1);
      v46 = *((float *)&mData[1].mNode.mUID + 1);
      max.x = v26;
      max.y = v27;
      v47 = v24;
      v28 = v24 - *(float *)mData[1].mNode.mChild;
      v29 = v25 - *((float *)mData[1].mNode.mChild + 1);
      v45 = v25;
      max.z = v28;
      min.x = v29;
      v30 = v24 - *((float *)&mData[1].mNode.mChild[1] + 1);
      min.y = v46 - *(float *)&mData[1].mNode.mChild[1];
      min.z = v30;
      v44[1] = (__int128)UFG::qMatrix44::msIdentity.v1;
      v48 = (int)FLOAT_1_0;
      v44[2] = (__int128)UFG::qMatrix44::msIdentity.v2;
      v44[0] = (__int128)UFG::qMatrix44::msIdentity.v0;
      this->mpDynamicOutline = UFG::NavManager::ms_pInstance->vfptr->AddDynamicOutline(
                                 UFG::NavManager::ms_pInstance,
                                 v44,
                                 &max,
                                 &min,
                                 0i64,
                                 0);
      v31 = UFG::PedSpawnManager::GetInstance();
      UFG::PedSpawnManager::DeleteAmbientPedsFromNISBoundingVolume(
        v31,
        (UFG::qVector3 *)&mData[1],
        (UFG::qVector3 *)((char *)mData[1].mNode.mChild + 4));
    }
    if ( mpNISNode->mUseBoundingBoxToClearVehicles )
    {
      UFG::WheeledVehicleManager::DestroyWheeledVehiclesInNISBoundingVolume(
        UFG::WheeledVehicleManager::m_Instance,
        (UFG::qVector3 *)&mData[1],
        (UFG::qVector3 *)((char *)mData[1].mNode.mChild + 4));
      if ( v10 )
      {
        if ( UFG::VehicleOwnershipComponent::GetOwnedVehicle(v10) )
        {
          v32 = (UFG::SimObjectGame *)UFG::VehicleOwnershipComponent::GetOwnedVehicle(v10);
          v33 = v32;
          if ( v32 )
          {
            v34 = v32->m_Flags;
            if ( (v34 & 0x4000) != 0 )
            {
              v9 = v32->m_Components.p[14].m_pComponent;
            }
            else if ( v34 >= 0 )
            {
              if ( (v34 & 0x2000) != 0 )
              {
                v9 = v32->m_Components.p[9].m_pComponent;
              }
              else
              {
                if ( (v34 & 0x1000) != 0 )
                  v35 = UFG::SimObjectGame::GetComponentOfTypeHK(v32, UFG::CompositeDrawableComponent::_TypeUID);
                else
                  v35 = UFG::SimObject::GetComponentOfType(v32, UFG::CompositeDrawableComponent::_TypeUID);
                v9 = v35;
              }
            }
            else
            {
              v9 = v32->m_Components.p[14].m_pComponent;
            }
          }
          if ( !NISManager::IsActiveInNIS(this, v33) )
          {
            if ( v9 )
            {
              mNext = (float *)v9[22].m_SafePointerList.mNode.mNext;
              if ( mNext )
              {
                v37 = mNext[33];
                min.x = mNext[32];
                v38 = mNext[34];
                min.y = v37;
                v39 = mNext[35];
                min.z = v38;
                v40 = mNext[36];
                max.x = v39;
                v41 = mNext[37];
                max.y = v40;
                max.z = v41;
                TransformAABB((UFG::qMatrix44 *)&v9[20], &min, &max);
                if ( *(float *)&mData[1].mNode.mParent <= max.x
                  && *((float *)mData[1].mNode.mChild + 1) >= min.x
                  && *((float *)&mData[1].mNode.mParent + 1) <= max.y
                  && *(float *)&mData[1].mNode.mChild[1] >= min.y
                  && *(float *)mData[1].mNode.mChild <= max.z
                  && *((float *)&mData[1].mNode.mChild[1] + 1) >= min.z )
                {
                  UFG::SimObject::Suspend(v33);
                  UFG::qSafePointer<Creature,Creature>::operator=(
                    (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&this->mDisabledVehicle,
                    (UFG::SimComponent *)v33);
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 597
// RVA: 0x3E4680
void __fastcall NISManager::ResetNISSettings(NISManager *this)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::BaseAnimationComponent *ComponentOfType; // rax
  UFG::PedSpawnManager *Instance; // rax
  unsigned int mLightLayerUID; // ecx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::CopSystem *v8; // rax
  UFG::SimObject *m_pPointer; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mDisabledVehicle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = (UFG::BaseAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                       m_pSimObject,
                                                       UFG::CameraAnimationComponent::_TypeUID);
    if ( ComponentOfType )
      UFG::BaseAnimationComponent::SetUpdateFromNIS(ComponentOfType, 0);
  }
  UFG::StreamedResourceComponent::sAssetLoadDistance = UFG::StreamedResourceComponent::sDefaultAssetLoadDistance;
  Render::SetVSyncEnable(VSYNC_DEFAULT);
  Instance = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::SetupSocialForNIS(Instance, 0);
  mLightLayerUID = this->mLightLayerUID;
  if ( mLightLayerUID != -1 )
    Render::EnableLightLayer(mLightLayerUID, 1);
  UFG::TimeOfDayManager::GetInstance()->mGlobalIlluminationBlend = 1.0;
  Inventory = `UFG::qGetResourceInventory<UFG::NISSpatialData>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::NISSpatialData>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x59362AA3u);
    `UFG::qGetResourceInventory<UFG::NISSpatialData>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mSpatialDataHandle, Inventory);
  if ( this->mpDynamicOutline )
  {
    ((void (__fastcall *)(UFG::NavManager *))UFG::NavManager::ms_pInstance->vfptr->RemoveDynamicOutline)(UFG::NavManager::ms_pInstance);
    this->mpDynamicOutline = 0i64;
  }
  v8 = UFG::CopSystem::Instance();
  v8->vfptr[4].__vecDelDtor(v8, this->mWasCopSystemEnabled);
  m_pPointer = this->mDisabledVehicle.m_pPointer;
  if ( m_pPointer )
    UFG::SimObject::Restore(m_pPointer);
  p_mDisabledVehicle = &this->mDisabledVehicle;
  if ( this->mDisabledVehicle.m_pPointer )
  {
    mPrev = p_mDisabledVehicle->mPrev;
    mNext = this->mDisabledVehicle.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mDisabledVehicle->mPrev = p_mDisabledVehicle;
    this->mDisabledVehicle.mNext = &this->mDisabledVehicle;
  }
  this->mDisabledVehicle.m_pPointer = 0i64;
}

// File Line: 644
// RVA: 0x3E3B60
char __fastcall NISManager::PlayInternal(NISManager *this, UFG::SimComponent *pInstance)
{
  NISNode *mPrev; // rsi

  if ( !gNISesEnabled || !pInstance || !LODWORD(pInstance->m_pSimObject) )
    return 0;
  mPrev = (NISNode *)pInstance->m_BoundComponentHandles.mNode.mPrev;
  if ( !mPrev )
    return 0;
  if ( this->mpActiveInstance.m_pPointer )
    NISManager::StopActiveNIS(this);
  UFG::qSafePointer<Creature,Creature>::operator=(
    (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)this,
    pInstance);
  NISManager::PreventGameStateChanges(this);
  if ( NISInstance::IsLoaded(this->mpActiveInstance.m_pPointer) && mPrev->mSeamlessIn )
  {
    this->mfStateTimeoutS = 3.4028235e38;
    this->mState = STATE_DANGER;
    this->mfStateTimeoutS = gInstanceLoadTimeoutS;
    NISManager::EnterStateLoadingInstance(this);
  }
  else
  {
    this->mState = STATE_NORMAL;
    this->mfStateTimeoutS = 3.4028235e38;
    NISManager::EnterStateIntroCurtains(this);
  }
  this->mbAudioStopped = 0;
  return 1;
}

// File Line: 718
// RVA: 0x3E3C40
void __fastcall NISManager::PlayNIS(NISManager *this)
{
  NISNode *mpNISNode; // r14
  int v3; // ebx
  int v4; // ebp
  NISActorNode *v5; // rdi
  UFG::SimObjectCVBase *SimObject; // rax
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *v8; // rax
  Creature *mCreature; // rcx
  UFG::qMatrix44 *p_mNISSceneRoot; // rax
  float z; // xmm2_4
  float w; // xmm3_4
  float x; // xmm0_4
  float y; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  NISInstance *m_pPointer; // r8
  UFG::qSafePointer<NISInstance,NISInstance> *p_mpPreloadInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mNext; // rax
  NISInstance *p_mNext; // rcx
  unsigned int v28; // ebx
  UFG::UIHKTextOverlay *Instance; // rax
  UFG::qMatrix44 root; // [rsp+20h] [rbp-48h] BYREF

  UFG::VehicleAudioComponent::KillOffensiveSoundsForNIS();
  mpNISNode = this->mpActiveInstance.m_pPointer->mpNISNode;
  v3 = 0;
  v4 = (int)mpNISNode->vfptr[1].GetClassname(mpNISNode);
  if ( v4 > 0 )
  {
    do
    {
      v5 = (NISActorNode *)((__int64 (__fastcall *)(NISNode *, _QWORD))mpNISNode->vfptr[1].Serialize)(
                             mpNISNode,
                             (unsigned int)v3);
      NISActorNode::Play(v5);
      NISActorNode::Update(v5, 0.0);
      if ( this->mpActiveInstance.m_pPointer->mPlayRelativeToNISSceneRoot )
      {
        SimObject = (UFG::SimObjectCVBase *)UFG::Simulation::GetSimObject(&UFG::gSim, &v5->mActorID);
        if ( SimObject )
        {
          m_Flags = SimObject->m_Flags;
          if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
          {
            v8 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(SimObject);
          }
          else if ( (m_Flags & 0x2000) != 0 )
          {
            v8 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)SimObject);
          }
          else
          {
            v8 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                                    ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        SimObject,
                                                        UFG::CharacterAnimationComponent::_TypeUID)
                                                    : UFG::SimObject::GetComponentOfType(
                                                        SimObject,
                                                        UFG::CharacterAnimationComponent::_TypeUID));
          }
          if ( v8 )
          {
            mCreature = v8->mCreature;
            if ( mCreature )
            {
              p_mNISSceneRoot = &this->mpActiveInstance.m_pPointer->mNISSceneRoot;
              z = this->mpActiveInstance.m_pPointer->mNISSceneRoot.v0.z;
              w = this->mpActiveInstance.m_pPointer->mNISSceneRoot.v0.w;
              x = p_mNISSceneRoot->v0.x;
              root.v0.y = this->mpActiveInstance.m_pPointer->mNISSceneRoot.v0.y;
              root.v0.z = z;
              root.v0.x = x;
              root.v0.w = w;
              y = p_mNISSceneRoot->v1.y;
              v15 = p_mNISSceneRoot->v1.z;
              v16 = p_mNISSceneRoot->v1.w;
              root.v1.x = p_mNISSceneRoot->v1.x;
              root.v1.y = y;
              root.v1.z = v15;
              root.v1.w = v16;
              v17 = p_mNISSceneRoot->v2.z;
              v18 = p_mNISSceneRoot->v2.w;
              v19 = p_mNISSceneRoot->v2.x;
              root.v2.y = p_mNISSceneRoot->v2.y;
              root.v2.x = v19;
              root.v2.z = v17;
              root.v2.w = v18;
              v20 = p_mNISSceneRoot->v3.z;
              v21 = p_mNISSceneRoot->v3.w;
              v22 = p_mNISSceneRoot->v3.x;
              root.v3.y = p_mNISSceneRoot->v3.y;
              root.v3.z = v20;
              root.v3.x = v22;
              root.v3.w = v21;
              Creature::SetAbsoluteRelativeRoot(mCreature, &root);
            }
          }
        }
      }
      ++v3;
    }
    while ( v3 < v4 );
  }
  NISManager::SetPlayTime(this, 0.0, 0);
  m_pPointer = this->mpActiveInstance.m_pPointer;
  this->mAudioTime = 0.0;
  if ( m_pPointer->mStatus == eSTATUS_PRELOADING )
  {
    p_mpPreloadInstance = &NISManager::sInstance->mpPreloadInstance;
    if ( NISManager::sInstance->mpPreloadInstance.m_pPointer )
    {
      mPrev = p_mpPreloadInstance->mPrev;
      mNext = NISManager::sInstance->mpPreloadInstance.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mpPreloadInstance->mPrev = p_mpPreloadInstance;
      p_mpPreloadInstance->mNext = p_mpPreloadInstance;
    }
    p_mpPreloadInstance->m_pPointer = 0i64;
  }
  m_pPointer->mStatus = eSTATUS_PLAYING;
  p_mNext = (NISInstance *)&this->mInstances.mNode.mNext[-2].mNext;
  if ( p_mNext != (NISInstance *)&this->mpPreloadInstance )
  {
    while ( p_mNext->mStatus != eSTATUS_QUEUED_FOR_PRELOADING )
    {
      p_mNext = (NISInstance *)&p_mNext->mNext[-2].mNext;
      if ( p_mNext == (NISInstance *)&this->mpPreloadInstance )
        goto LABEL_25;
    }
    NISInstance::Preload(p_mNext);
  }
LABEL_25:
  v28 = mpNISNode->m_audioTagUID[1];
  if ( this->mbCurtainsShown )
  {
    this->mbCurtainsShown = 0;
    UFG::UIHK_NISOverlay::getInstance();
    UFG::UIHK_NISOverlay::SetPostNISHideCurtainsAudioEvent(v28, 0);
    UFG::UIHK_NISOverlay::HideCurtains(0.0, 0);
  }
  else if ( v28 )
  {
    UFG::UIHK_NISOverlay::getInstance();
    UFG::UIHK_NISOverlay::SetPostNISHideCurtainsAudioEvent(v28, 0);
  }
  if ( !this->mUIHelpbarLocked )
  {
    this->mUIHelpbarLocked = 1;
    UFG::UIHKHelpBarWidget::Lock();
  }
  if ( UFG::UIHKTextOverlay::getInstance() )
  {
    Instance = UFG::UIHKTextOverlay::getInstance();
    UFG::UIHKTextOverlay::StopAllSubtitles(Instance, 1);
  }
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_NIS_START_5, 0xFFFFFFFF);
}

// File Line: 839
// RVA: 0x3E60D0
void __fastcall NISManager::StopNIS(NISManager *this)
{
  NISInstance *m_pPointer; // rbx
  NISNode *v2; // rbp
  NISNode *mpNISNode; // rbx
  int v5; // esi
  int v6; // r14d
  NISActorNode *v7; // rax
  NISInstance *v8; // rax
  unsigned int v9; // ebx
  UFG::TiDo *Instance; // rax
  UFG::UIHKTextOverlay *v11; // rax

  m_pPointer = this->mpActiveInstance.m_pPointer;
  v2 = 0i64;
  if ( m_pPointer )
    mpNISNode = m_pPointer->mpNISNode;
  else
    mpNISNode = 0i64;
  if ( mpNISNode )
  {
    v5 = 0;
    v6 = (int)mpNISNode->vfptr[1].GetClassname(mpNISNode);
    if ( v6 > 0 )
    {
      do
      {
        v7 = (NISActorNode *)((__int64 (__fastcall *)(NISNode *, _QWORD))mpNISNode->vfptr[1].Serialize)(
                               mpNISNode,
                               (unsigned int)v5);
        NISActorNode::nodeCleanup(v7);
        ++v5;
      }
      while ( v5 < v6 );
    }
  }
  if ( this->mUIHelpbarLocked )
  {
    this->mUIHelpbarLocked = 0;
    UFG::UIHKHelpBarWidget::Unlock();
  }
  if ( !this->mbAudioStopped )
  {
    v8 = this->mpActiveInstance.m_pPointer;
    this->mbAudioStopped = 1;
    if ( v8 )
      v2 = v8->mpNISNode;
    if ( v2 )
    {
      v9 = v2->m_audioTagUID[3];
      UFG::UIHK_NISOverlay::getInstance();
      UFG::UIHK_NISOverlay::SetPostNISHideCurtainsAudioEvent(v9, 0);
      if ( UFG::TiDo::GetInstance() )
      {
        Instance = UFG::TiDo::GetInstance();
        Instance->vfptr->SetNISMode(Instance, 0);
      }
      if ( UFG::UIHKTextOverlay::getInstance() )
      {
        v11 = UFG::UIHKTextOverlay::getInstance();
        UFG::UIHKTextOverlay::StopAllSubtitles(v11, 1);
      }
    }
  }
}

// File Line: 902
// RVA: 0x3E6800
void __fastcall NISManager::Update(NISManager *this, float timeDelta)
{
  NISManager::eStateEnum mState; // eax

  mState = this->mState;
  if ( mState == STATE_INVALID )
    goto LABEL_11;
  if ( !this->mpActiveInstance.m_pPointer )
  {
    NISManager::AllowGameStateChanges(this);
    NISManager::StopNIS(this);
    NISManager::ResetNISSettings(this);
    NISManager::Reset(this);
LABEL_11:
    UFG::RenderWorld::msIsNisPlaying = this->mState != STATE_INVALID;
    return;
  }
  switch ( mState )
  {
    case STATE_NORMAL:
      NISManager::UpdateStateIntroCurtains(this, timeDelta);
      UFG::RenderWorld::msIsNisPlaying = this->mState != STATE_INVALID;
      break;
    case STATE_DANGER:
      NISManager::UpdateStateLoadingInstance(this, timeDelta);
      UFG::RenderWorld::msIsNisPlaying = this->mState != STATE_INVALID;
      break;
    case STATE_COMPLETE:
      NISManager::UpdateStateSetupLocation(this, timeDelta);
      UFG::RenderWorld::msIsNisPlaying = this->mState != STATE_INVALID;
      break;
    case STATE_INCOMPLETE:
      NISManager::UpdateStateAction(this, timeDelta);
      UFG::RenderWorld::msIsNisPlaying = this->mState != STATE_INVALID;
      break;
    case STATE_ANIMATE_COMPLETE:
      NISManager::UpdateStateOutroCurtains(this, timeDelta);
      UFG::RenderWorld::msIsNisPlaying = this->mState != STATE_INVALID;
      break;
    case NUM_STATES:
      NISManager::UpdateStateUnloadingInstance(this, timeDelta);
      UFG::RenderWorld::msIsNisPlaying = this->mState != STATE_INVALID;
      break;
    default:
      goto LABEL_11;
  }
}

// File Line: 989
// RVA: 0x3E7950
void __fastcall NISManager::UpdateTransforms(NISManager *this, float timeDelta)
{
  NISNode *mpNISNode; // rdi
  int v3; // ebx
  int v4; // esi
  NISActorNode *v5; // rax

  if ( this->mState == STATE_INCOMPLETE )
  {
    mpNISNode = this->mpActiveInstance.m_pPointer->mpNISNode;
    if ( mpNISNode )
    {
      v3 = 0;
      v4 = (int)mpNISNode->vfptr[1].GetClassname(mpNISNode);
      if ( v4 > 0 )
      {
        do
        {
          v5 = (NISActorNode *)((__int64 (__fastcall *)(NISNode *, _QWORD))mpNISNode->vfptr[1].Serialize)(
                                 mpNISNode,
                                 (unsigned int)v3);
          NISActorNode::UpdateTransforms(v5, timeDelta);
          ++v3;
        }
        while ( v3 < v4 );
      }
    }
  }
}

// File Line: 1016
// RVA: 0x3E6070
void __fastcall NISManager::StopActiveNIS(NISManager *this)
{
  if ( this->mState )
  {
    this->mState = NUM_STATES;
    this->mfStateTimeoutS = 3.4028235e38;
    NISManager::EnterStateUnloadingInstance(this);
    NISManager::Update(this, 0.0);
  }
  else
  {
    NISManager::AllowGameStateChanges(this);
    NISManager::StopNIS(this);
    NISManager::ResetNISSettings(this);
    NISManager::Reset(this);
  }
}

// File Line: 1066
// RVA: 0x3E2D20
void __fastcall NISManager::HideHUD(NISManager *this)
{
  if ( this->mHudDisableCount )
  {
    ++this->mHudDisableCount;
  }
  else
  {
    UFG::UIHK_NISOverlay::ShowLetterBox();
    ++this->mHudDisableCount;
  }
}

// File Line: 1086
// RVA: 0x3E29F0
void __fastcall NISManager::EnterStateIntroCurtains(NISManager *this)
{
  unsigned int v2; // edi
  float v3; // xmm6_4
  UFG::UI *v4; // rcx
  ANTLR3_INPUT_STREAM_struct *v5; // rax

  UFG::UI::LockGameplayInput((UFG::UI *)this);
  v2 = this->mpActiveInstance.m_pPointer->mpNISNode->m_audioTagUID[0];
  if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_1 )
    v3 = FLOAT_0_33000001;
  else
    v3 = 0.0;
  this->mbCurtainsShown = 1;
  if ( v2 )
    UFG::NISAudio::PlayNISCurtainEvent(UFG::NISAudio::m_instance, v2);
  UFG::UIHK_NISOverlay::ShowCurtains(v3, 0);
  NISInstance::Preload(this->mpActiveInstance.m_pPointer);
  this->mbUpdatedOnce = 0;
  if ( (unsigned __int8)UFG::UI::IsGamePaused() )
  {
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
    UFG::UI::UnpauseGame(v4);
  }
  this->mbUserInputDisabled = 1;
  v5 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::SetGameState(v5, 4u);
}

// File Line: 1108
// RVA: 0x3E71B0
void __fastcall NISManager::UpdateStateIntroCurtains(NISManager *this, float timeDelta)
{
  if ( this->mbUpdatedOnce )
  {
    if ( UFG::UIHK_NISOverlay::IsCurtainStable() )
    {
      this->mfStateTimeoutS = 3.4028235e38;
      this->mState = STATE_DANGER;
      this->mfStateTimeoutS = gInstanceLoadTimeoutS;
      NISManager::EnterStateLoadingInstance(this);
    }
    this->mbUpdatedOnce = 1;
  }
  else
  {
    this->mbUpdatedOnce = 1;
  }
}

// File Line: 1120
// RVA: 0x3E2AB0
void __fastcall NISManager::EnterStateLoadingInstance(NISManager *this)
{
  ANTLR3_INPUT_STREAM_struct *v2; // rax
  UFG::ObjectResourceManager *v3; // rax
  UFG::UI *v4; // rcx

  NISManager::SetupNISSettingsPreStreamed(this);
  if ( !NISInstance::IsLoaded(this->mpActiveInstance.m_pPointer) )
  {
    if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_1 )
    {
      v2 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::SetGameState(v2, 8u);
      UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateLoadNIS_1);
    }
    UFG::StreamPool_FullDefragDown(0xEu);
    UFG::StreamPool_FullDefragDown(5u);
  }
  v3 = UFG::ObjectResourceManager::Instance();
  UFG::ObjectResourceManager::SetFragmentationReservePercentage(v3, 0.15000001);
  NISInstance::LoadAllResources(this->mpActiveInstance.m_pPointer);
  if ( this->mbUserInputDisabled )
    UFG::UI::UnlockGameplayInput(v4);
}

// File Line: 1154
// RVA: 0x3E7210
void __fastcall NISManager::UpdateStateLoadingInstance(NISManager *this, float timeDelta)
{
  char v3; // di
  hkgpIndexedMeshDefinitions::Edge *v4; // rdx
  AnimationGroup *m_pPointer; // rcx
  NISInstance *v6; // rax
  AnimationGroup *v7; // rcx
  NISInstance *v8; // rax
  AnimationGroup *v9; // rcx

  NISInstance::UpdateActorResources(this->mpActiveInstance.m_pPointer, timeDelta);
  if ( NISInstance::IsLoaded(this->mpActiveInstance.m_pPointer)
    && (unsigned __int8)NISInstance::AreActorsReady(this->mpActiveInstance.m_pPointer) )
  {
    goto LABEL_26;
  }
  v3 = 0;
  if ( this->mfStateTimeoutS <= 0.0 )
  {
    if ( NISInstance::AreAnimationsLoaded(this->mpActiveInstance.m_pPointer)
      && NISInstance::IsAudioResourceLoaded(this->mpActiveInstance.m_pPointer, v4) )
    {
      NISInstance::AreAllActorsLoaded(this->mpActiveInstance.m_pPointer);
      NISInstance::IsLightGroupLoaded(this->mpActiveInstance.m_pPointer);
      v3 = 1;
    }
    else
    {
      m_pPointer = this->mpActiveInstance.m_pPointer->mAnimationGroupHandle.m_AnimationGroup.m_pPointer;
      if ( m_pPointer )
        AnimationGroup::IsStreamedIn(m_pPointer);
      v6 = this->mpActiveInstance.m_pPointer;
      if ( v6->mFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1 )
      {
        v7 = v6->mFacialAnimGroupHandle.m_AnimationGroup.m_pPointer;
        if ( v7 )
          AnimationGroup::IsStreamedIn(v7);
      }
      v8 = this->mpActiveInstance.m_pPointer;
      if ( v8->mExtraFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1 )
      {
        v9 = v8->mExtraFacialAnimGroupHandle.m_AnimationGroup.m_pPointer;
        if ( v9 )
          AnimationGroup::IsStreamedIn(v9);
      }
      NISInstance::IsAudioResourceLoaded(this->mpActiveInstance.m_pPointer, v4);
      this->mState = NUM_STATES;
      this->mfStateTimeoutS = 3.4028235e38;
      NISManager::EnterStateUnloadingInstance(this);
    }
  }
  this->mfStateTimeoutS = this->mfStateTimeoutS - timeDelta;
  if ( v3 )
  {
LABEL_26:
    if ( this->mpActiveInstance.m_pPointer->mpNISNode->mSeamlessIn )
    {
      if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateInGame_1 )
        UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateInGame_1);
      this->mState = STATE_INCOMPLETE;
      this->mfStateTimeoutS = 3.4028235e38;
      NISManager::EnterStateAction(this);
    }
    else
    {
      if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateLoadNIS_1 )
        UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateLoadNIS_1);
      this->mState = STATE_COMPLETE;
      this->mfStateTimeoutS = 3.4028235e38;
      NISManager::EnterStateSetupLocation(this);
    }
  }
}

// File Line: 1238
// RVA: 0x3E2B90
void __fastcall NISManager::EnterStateSetupLocation(NISManager *this)
{
  NISNode *mpNISNode; // rbx
  ITrack *mPrimaryCameraAnimationTrack; // rdx
  UFG::ProgressionTracker *v4; // rax

  mpNISNode = this->mpActiveInstance.m_pPointer->mpNISNode;
  ActionController::Stop(&this->mActionController);
  ActionController::Play(&this->mActionController, mpNISNode);
  mPrimaryCameraAnimationTrack = mpNISNode->mPrimaryCameraAnimationTrack;
  if ( mPrimaryCameraAnimationTrack )
  {
    ActionController::PlayTracks(&this->mActionController, mPrimaryCameraAnimationTrack, 0, 0.0);
    ActionController::Update(&this->mActionController, 0.0);
  }
  NISManager::SetPlayTime(this, 0.0, 0);
  v4 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::SetResourceFreezeMode(v4, 0);
  this->mbStreamingComplete = 0;
}

// File Line: 1276
// RVA: 0x3E73F0
void __fastcall NISManager::UpdateStateSetupLocation(NISManager *this, float timeDelta)
{
  if ( this->mbStreamingComplete )
  {
    if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateInGame_1 )
      UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateInGame_1);
    this->mState = STATE_INCOMPLETE;
    this->mfStateTimeoutS = 3.4028235e38;
    NISManager::EnterStateAction(this);
  }
}

// File Line: 1290
// RVA: 0x3E28F0
void __fastcall NISManager::EnterStateAction(NISManager *this)
{
  NISNode *mpNISNode; // rsi
  float mFadeInDuration; // xmm6_4
  __int64 mOffset; // rax
  TrackGroup *v5; // rdx

  mpNISNode = this->mpActiveInstance.m_pPointer->mpNISNode;
  if ( mpNISNode->mFadeInDuration > 0.0 )
  {
    this->mbCurtainsShown = 1;
    UFG::UIHK_NISOverlay::ShowCurtains(0.0, 0);
    mFadeInDuration = mpNISNode->mFadeInDuration;
    this->mbCurtainsShown = 0;
    UFG::UIHK_NISOverlay::getInstance();
    UFG::UIHK_NISOverlay::SetPostNISHideCurtainsAudioEvent(0, 0);
    UFG::UIHK_NISOverlay::HideCurtains(mFadeInDuration, 0);
    this->mbCurtainsShown = 0;
  }
  if ( !this->mbCameraAttached )
  {
    ActionController::Stop(&this->mActionController);
    ActionController::Play(&this->mActionController, mpNISNode);
  }
  mOffset = mpNISNode->mTracksAction.mOffset;
  if ( mOffset )
    v5 = (TrackGroup *)((char *)&mpNISNode->mTracksAction + mOffset);
  else
    v5 = 0i64;
  ActionController::PlayTracks(&this->mActionController, v5, 0, 0.0);
  NISLightGroup::Play(mpNISNode->mLightGroupObject);
  ActionController::Update(&this->mActionController, 0.0);
  NISManager::SetupNISSettingsPostStreamed(this);
  NISManager::PlayNIS(this);
}

// File Line: 1335
// RVA: 0x3E6CE0
void __fastcall NISManager::UpdateStateAction(NISManager *this, float timeDelta)
{
  NISNode *mpNISNode; // rsi
  float v4; // xmm6_4
  NISManager *AudioMasterTask; // rax
  AudioTaskNIS *v6; // rdx
  UFG::qNode<NISInstance,NISInstanceMasterList> *mPrev; // rax
  float v8; // xmm0_4
  int v9; // ebx
  int v10; // ebp
  NISActorNode *v11; // rax
  float m_ActionNodePlayTime; // xmm7_4
  NISManager *v13; // rax
  AudioTaskNIS *v14; // rbx
  UFG::qNode<NISInstance,NISInstanceMasterList> *v15; // rcx
  float ElapsedTime; // xmm0_4
  float v17; // xmm2_4
  UFG::AudioEvent *m_pEvent; // rcx
  float v19; // xmm0_4
  float mFadeOutDuration; // xmm7_4
  float mTime; // xmm2_4
  unsigned int v22; // edx
  char v23; // bl
  float v24; // xmm0_4
  UFG::GameStatTracker *v25; // rax
  UFG::PersistentData::MapBool *MapBool; // r14
  const char *v27; // rdx
  UFG::OSuiteDBLogger *v28; // rbp
  int mUID; // ebx
  int v30; // ebx
  int v31; // r8d
  UFG::GameStatTracker *v32; // rax
  UFG::GameStat::Int32Stat v33; // edx
  bool v34; // zf
  char dest[128]; // [rsp+20h] [rbp-C8h] BYREF
  UFG::qSymbol result; // [rsp+F0h] [rbp+8h] BYREF

  mpNISNode = this->mpActiveInstance.m_pPointer->mpNISNode;
  v4 = timeDelta;
  if ( !mpNISNode || (unsigned __int8)UFG::MovieHandler::IsPlayingNonInMemMovies(&UFG::TheMovieHandler) )
  {
    if ( (unsigned __int8)UFG::MovieHandler::IsPlayingNonInMemMovies(&UFG::TheMovieHandler)
      && !mpNISNode->mPrimaryCameraAnimationTrack )
    {
      if ( !this->mbCameraAttached && this->mTime == 0.0 )
        this->mLength = UFG::MovieHandler::GetNonInMemMovieLength(&UFG::TheMovieHandler);
      if ( !this->mPaused )
        this->mTime = timeDelta + this->mTime;
    }
  }
  else
  {
    AudioMasterTask = NISManager::GetAudioMasterTask(this);
    v6 = (AudioTaskNIS *)AudioMasterTask;
    if ( gNISSyncWithAudio )
    {
      if ( AudioMasterTask )
      {
        mPrev = AudioMasterTask->mInstances.mNode.mPrev[20].mPrev;
        if ( mPrev )
        {
          if ( ((__int64)mPrev[9].mPrev & 0x40) != 0 )
          {
            v8 = AudioTaskNIS::GetElapsedTime(v6) * 0.001;
            v4 = v8 - this->mAudioTime;
            if ( v4 >= 0.0 )
              this->mAudioTime = v8;
            else
              v4 = 0.0;
          }
        }
      }
    }
    if ( !this->mPaused )
    {
      ActionController::Update(&this->mActionController, v4);
      v9 = 0;
      v10 = (int)mpNISNode->vfptr[1].GetClassname(mpNISNode);
      if ( v10 > 0 )
      {
        do
        {
          v11 = (NISActorNode *)((__int64 (__fastcall *)(NISNode *, _QWORD))mpNISNode->vfptr[1].Serialize)(
                                  mpNISNode,
                                  (unsigned int)v9);
          NISActorNode::Update(v11, v4);
          ++v9;
        }
        while ( v9 < v10 );
      }
    }
    m_ActionNodePlayTime = this->mActionController.m_ActionNodePlayTime;
    v13 = NISManager::GetAudioMasterTask(this);
    v14 = (AudioTaskNIS *)v13;
    if ( v13 )
    {
      v15 = v13->mInstances.mNode.mPrev[20].mPrev;
      if ( v15 )
      {
        if ( ((__int64)v15[9].mPrev & 0x40) != 0 )
        {
          ElapsedTime = UFG::AudioEvent::GetElapsedTime((UFG::AudioEvent *)v15);
          if ( ElapsedTime > 0.0 )
          {
            v14->m_lastElapsedTime = ElapsedTime;
            v14->m_hasStarted = 1;
          }
        }
      }
      v17 = v14->m_lastElapsedTime * 0.001;
    }
    else
    {
      v17 = FLOAT_N1_0;
    }
    NISManager::UpdateActionDebugDisplay(this, m_ActionNodePlayTime, v17);
    if ( !this->mPaused && this->mActionController.m_currentNode )
    {
      if ( gNISSyncWithAudio
        && v14
        && (m_pEvent = v14->m_nisAudio->m_controller.m_pEvent) != 0i64
        && (*((_BYTE *)m_pEvent + 144) & 0x40) != 0 )
      {
        v19 = AudioTaskNIS::GetElapsedTime(v14) * 0.001;
        NISManager::SetPlayTime(this, v19, 0);
      }
      else
      {
        NISManager::SetPlayTime(this, m_ActionNodePlayTime, 0);
      }
    }
  }
  mFadeOutDuration = mpNISNode->mFadeOutDuration;
  if ( !this->mbCurtainsShown && mFadeOutDuration > 0.0 )
  {
    mTime = this->mTime;
    if ( mTime >= (float)(this->mLength - mFadeOutDuration) )
    {
      if ( mFadeOutDuration >= (float)(this->mLength - mTime) )
        mFadeOutDuration = this->mLength - mTime;
      v22 = this->mpActiveInstance.m_pPointer->mpNISNode->m_audioTagUID[2];
      this->mbCurtainsShown = 1;
      if ( v22 )
        UFG::NISAudio::PlayNISCurtainEvent(UFG::NISAudio::m_instance, v22);
      UFG::UIHK_NISOverlay::ShowCurtains(mFadeOutDuration, 0);
    }
  }
  v23 = 0;
  if ( this->mEndCondition )
  {
    v24 = this->mTimeToEndAt - v4;
    this->mTimeToEndAt = v24;
    if ( v24 <= 0.0 )
    {
      v23 = 1;
      if ( mpNISNode->mSeamlessOut )
        NISManager::SetPlayTime(this, this->mLength, 0);
    }
  }
  if ( !this->mActionController.m_currentNode
    || mpNISNode->mPrimaryCameraAnimationTrack && !this->mbCameraAttached
    || v23 )
  {
    ActionController::Stop(&this->mActionController);
    v25 = UFG::GameStatTracker::Instance();
    MapBool = UFG::GameStatTracker::GetMapBool(v25, WatchedNISBoolList);
    if ( (mpNISNode->mNISName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
      v27 = (char *)&mpNISNode->mNISName + (mpNISNode->mNISName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    else
      v27 = BinString::sEmptyString;
    UFG::qSymbol::create_from_string(&result, v27);
    if ( this->mEndCondition == eNIS_Skipping )
    {
      v28 = UFG::OSuiteDBLogger::Instance();
      if ( UFG::OSuiteDBLogger::CreateMetric(v28, "CutScene") )
      {
        mUID = result.mUID;
        UFG::qSPrintf(dest, 128, "i32_%s", "CutsceneID");
        OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, mUID);
        v30 = (int)this->mTime;
        UFG::qSPrintf(dest, 128, "i32_%s", "AmountShown");
        OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v30);
        if ( UFG::PersistentData::MapBool::GetStatus(MapBool, &result) )
        {
          UFG::qSPrintf(dest, 128, "i32_%s", "IsFirstTimeShown");
          v31 = 0;
        }
        else
        {
          UFG::qSPrintf(dest, 128, "i32_%s", "IsFirstTimeShown");
          v31 = 1;
        }
        OSuite::ZMetric::SetProperty(v28->m_pMetric, dest, v31);
        UFG::OSuiteDBLogger::SubmitMetric(v28, 0);
      }
      v32 = UFG::GameStatTracker::Instance();
      v33 = CutSceneSkipped;
    }
    else
    {
      v32 = UFG::GameStatTracker::Instance();
      v33 = CutSceneWatched;
    }
    UFG::GameStatTracker::ApplyDelta(v32, v33, 1);
    if ( !UFG::PersistentData::MapBool::GetStatus(MapBool, &result) )
      UFG::PersistentData::MapBool::SetStatus(MapBool, &result, 1);
    this->mEndCondition = eNIS_Finished;
    v34 = mpNISNode->mSeamlessOut == 0;
    this->mfStateTimeoutS = 3.4028235e38;
    if ( v34 )
    {
      this->mState = STATE_ANIMATE_COMPLETE;
      NISManager::EnterStateOutroCurtains(this);
    }
    else
    {
      this->mState = NUM_STATES;
      NISManager::EnterStateUnloadingInstance(this);
    }
  }
}

// File Line: 1514
// RVA: 0x3E2B50
void __fastcall NISManager::EnterStateOutroCurtains(NISManager *this)
{
  unsigned int v1; // edx

  v1 = this->mpActiveInstance.m_pPointer->mpNISNode->m_audioTagUID[2];
  this->mbCurtainsShown = 1;
  if ( v1 )
    UFG::NISAudio::PlayNISCurtainEvent(UFG::NISAudio::m_instance, v1);
  UFG::UIHK_NISOverlay::ShowCurtains(0.0, 0);
}

// File Line: 1521
// RVA: 0x3E73B0
void __fastcall NISManager::UpdateStateOutroCurtains(NISManager *this, float timeDelta)
{
  if ( UFG::UIHK_NISOverlay::IsCurtainStable() )
  {
    this->mState = NUM_STATES;
    this->mfStateTimeoutS = 3.4028235e38;
    NISManager::EnterStateUnloadingInstance(this);
  }
}

// File Line: 1529
// RVA: 0x3E2C20
void __fastcall NISManager::EnterStateUnloadingInstance(NISManager *this)
{
  UFG::ObjectResourceManager *v2; // rax

  NISInstance::Unload(this->mpActiveInstance.m_pPointer, 0);
  v2 = UFG::ObjectResourceManager::Instance();
  UFG::ObjectResourceManager::SetFragmentationReservePercentage(v2, 0.15000001);
  NISManager::StopNIS(this);
  NISManager::ResetNISSettings(this);
}

// File Line: 1543
// RVA: 0x3E7450
void __fastcall NISManager::UpdateStateUnloadingInstance(NISManager *this, float timeDelta)
{
  NISNode *mpNISNode; // rcx
  UFG::ProgressionTracker *v4; // rax
  UFG::ProgressionTracker *v5; // rax
  UFG::TimeOfDayManager *Instance; // rax
  UFG::TimeOfDayManager *v7; // rbx
  float mTimeOverrideInSeconds; // xmm1_4
  float v9; // xmm1_4
  float mWeatherOverrideIntensity; // xmm1_4
  float v11; // xmm0_4
  UFG::PedSpawnManager *v12; // rax

  mpNISNode = this->mpActiveInstance.m_pPointer->mpNISNode;
  if ( !mpNISNode )
    goto LABEL_30;
  if ( !mpNISNode->mSeamlessOut )
  {
    v4 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::SetResourceFreezeMode(v4, 1);
    if ( !this->mpActiveInstance.m_pPointer->mbIntermediateNIS )
    {
      v5 = UFG::ProgressionTracker::Instance();
      UFG::ProgressionTracker::ApplySceneSettings(v5, &this->mPostNisSettings);
    }
    goto LABEL_30;
  }
  Instance = UFG::TimeOfDayManager::GetInstance();
  v7 = Instance;
  if ( this->mPostNisSettings.mResetEnvironmentOverride )
    UFG::TimeOfDayManager::SetOverrideEnvironmentSettings(Instance, 0, 0.0);
  mTimeOverrideInSeconds = this->mPostNisSettings.mTimeOverrideInSeconds;
  if ( mTimeOverrideInSeconds >= 0.0 )
    UFG::TimeOfDayManager::SetTime(v7, mTimeOverrideInSeconds, 0);
  if ( this->mPostNisSettings.mTimeOverrideLockSet )
  {
    if ( this->mPostNisSettings.mTimeOverrideLock )
      v9 = 0.0;
    else
      v9 = FLOAT_40_0;
    TimePlotPoint::SetTimeValue(v7, v9);
  }
  mWeatherOverrideIntensity = this->mPostNisSettings.mWeatherOverrideIntensity;
  if ( mWeatherOverrideIntensity >= 0.0 )
  {
    if ( mWeatherOverrideIntensity <= 0.0 )
    {
      mWeatherOverrideIntensity = 0.0;
    }
    else
    {
      v11 = FLOAT_2_0;
      if ( mWeatherOverrideIntensity >= 2.0 )
        goto LABEL_20;
    }
    v11 = mWeatherOverrideIntensity;
LABEL_20:
    v7->m_WeatherState = v11;
    v7->m_WeatherTarget = v11;
    v7->m_NextWeatherTarget = v11;
  }
  if ( this->mPostNisSettings.mWeatherOverrideLockSet )
    UFG::TimeOfDayManager::LockWeather(v7, this->mPostNisSettings.mWeatherOverrideLock);
  if ( this->mPostNisSettings.mWeatherOverrideWetness >= 0.0 )
    UFG::TimeOfDayManager::SetSurfaceWetnessOverride(v7, -1.0, "NISManager::UpdateStateUnloadingInstance");
  if ( this->mPostNisSettings.mResetAmbientPeds )
  {
    UFG::PedSpawnManager::SetAmbientSpawningEnable(this->mPostNisSettings.mEnableAmbientPedsOnEnd);
    v12 = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::RestoreAllScriptedToFullyActive(v12);
    UFG::PedSpawnManager::SetScriptedStatusCheckEnable(1);
  }
  if ( UFG::UIHK_NISOverlay::IsCurtainVisible() || !UFG::UIHK_NISOverlay::IsCurtainStable() )
  {
    this->mbCurtainsShown = 1;
    UFG::UIHK_NISOverlay::ShowCurtains(0.0, 0);
    this->mbCurtainsShown = 0;
    UFG::UIHK_NISOverlay::getInstance();
    UFG::UIHK_NISOverlay::SetPostNISHideCurtainsAudioEvent(0, 0);
    UFG::UIHK_NISOverlay::HideCurtains(1.0, 0);
  }
LABEL_30:
  NISManager::AllowGameStateChanges(this);
  NISManager::StopNIS(this);
  NISManager::ResetNISSettings(this);
  NISManager::Reset(this);
}

// File Line: 1607
// RVA: 0x3E6940
void __fastcall NISManager::UpdateActionDebugDisplay(NISManager *this, float sceneTime, float masterAudioSceneTime)
{
  NISInstance *m_pPointer; // rbx
  float v4; // xmm6_4
  Render::DebugDrawContext *Context; // rdi
  AnimationGroupHandle::ReferenceInfo *m_pReferenceInfo; // rax
  UFG::SimObject *m_pSimObject; // rsi
  UFG::SimComponent *ComponentOfType; // rbx
  bool v9; // zf
  const char *v10; // r8
  const char *v11; // rcx
  UFG::UIHK_NISOverlay *Instance; // rbx
  char *v13; // rdx
  UFG::UIHK_NISFrameCounterWidget *p_FrameCounter; // rbx
  char buff[32]; // [rsp+40h] [rbp-68h] BYREF
  char v16[32]; // [rsp+60h] [rbp-48h] BYREF

  m_pPointer = this->mpActiveInstance.m_pPointer;
  v4 = sceneTime;
  if ( m_pPointer )
    m_pPointer = (NISInstance *)m_pPointer->mpNISNode;
  if ( gNISDebugDisplay )
  {
    GetUnitsTime(sceneTime, buff, 32, gNISTimeUnitsDisplay);
    Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    if ( masterAudioSceneTime < 0.0 )
    {
      Render::DebugDrawContext::DrawTextA(Context, 100, 60, &UFG::qColour::Red, "SceneTime:%s::AudioTime:NONE", buff);
    }
    else
    {
      v4 = masterAudioSceneTime;
      GetUnitsTime(masterAudioSceneTime, v16, 32, gNISTimeUnitsDisplay);
      Render::DebugDrawContext::DrawTextA(
        Context,
        100,
        60,
        &UFG::qColour::White,
        "SceneTime:%s::AudioTime:%s",
        buff,
        v16);
    }
    if ( m_pPointer )
    {
      m_pReferenceInfo = m_pPointer->mFacialAnimGroupHandle.m_pReferenceInfo;
      m_pSimObject = m_pReferenceInfo[1].m_pSimObject;
      if ( m_pSimObject )
      {
        ComponentOfType = UFG::SimObject::GetComponentOfType(
                            m_pReferenceInfo[1].m_pSimObject,
                            UFG::LightGroupComponent::_TypeUID);
        v9 = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::LightGroupAnimationComponent::_TypeUID) == 0i64;
        v10 = "None";
        v11 = "None";
        if ( !v9 )
          v11 = "Active";
        if ( ComponentOfType )
          v10 = "Active";
        Render::DebugDrawContext::DrawTextA(
          Context,
          100,
          70,
          &UFG::qColour::White,
          "NISLight:LightGroup:%s::LightAnim:%s",
          v10,
          v11);
      }
      else
      {
        Render::DebugDrawContext::DrawTextA(Context, 100, 70, &UFG::qColour::Red, "NISLight:None");
      }
    }
    Instance = UFG::UIHK_NISOverlay::getInstance();
    if ( Instance )
    {
      if ( gNISSyncWithAudio )
      {
        GetUnitsTime(v4, v16, 32, gNISTimeUnitsDisplay);
        v13 = v16;
      }
      else
      {
        v13 = buff;
      }
      p_FrameCounter = &Instance->FrameCounter;
      UFG::UIHK_NISFrameCounterWidget::SetCaption(p_FrameCounter, v13);
      UFG::UIHK_NISFrameCounterWidget::SetVisible(p_FrameCounter, 1);
    }
  }
}

// File Line: 1696
// RVA: 0x3E2110
bool __fastcall NISManager::CanSkipNow(NISManager *this)
{
  NISInstance *m_pPointer; // rax
  NISNode *mpNISNode; // rax
  bool result; // al

  m_pPointer = this->mpActiveInstance.m_pPointer;
  result = 0;
  if ( m_pPointer )
  {
    mpNISNode = m_pPointer->mpNISNode;
    if ( mpNISNode )
    {
      if ( mpNISNode->mCanSkip && this->mEndCondition == eNIS_Playing && mpNISNode->mTimeBeforeCanSkip <= this->mTime )
        return 1;
    }
  }
  return result;
}

// File Line: 1713
// RVA: 0x3E44E0
void __fastcall NISManager::RequestSkip(NISManager *this)
{
  bool v1; // zf
  float v2; // xmm6_4
  unsigned int v3; // edx

  v1 = this->mState == STATE_INCOMPLETE;
  this->mEndCondition = eNIS_Skipping;
  this->mTimeToEndAt = NISManager::sFadeOutDurationS;
  if ( v1 && !this->mbCurtainsShown )
  {
    v2 = NISManager::sFadeOutDurationS;
    if ( NISManager::sFadeOutDurationS >= (float)(this->mLength - this->mTime) )
      v2 = this->mLength - this->mTime;
    v3 = this->mpActiveInstance.m_pPointer->mpNISNode->m_audioTagUID[2];
    this->mbCurtainsShown = 1;
    if ( v3 )
      UFG::NISAudio::PlayNISCurtainEvent(UFG::NISAudio::m_instance, v3);
    UFG::UIHK_NISOverlay::ShowCurtains(v2, 0);
  }
}

// File Line: 1759
// RVA: 0x3E2C60
NISManager *__fastcall NISManager::GetAudioMasterTask(NISManager *this)
{
  ActionNodePlayable **p_m_SequenceNode; // rdi
  NISManager *p_mNext; // rbx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mPrev; // rcx

  p_m_SequenceNode = &this->mActionController.m_SequenceNode;
  p_mNext = (NISManager *)&this->mActionController.m_RunningTasks.mNode.mNext[-1].mNext;
  if ( p_mNext == (NISManager *)&this->mActionController.m_SequenceNode )
    return 0i64;
  while ( 1 )
  {
    mPrev = p_mNext->mpPreloadInstance.mPrev;
    if ( mPrev )
    {
      if ( AudioTrackNIS::sClassNameUID == ((unsigned int (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *))mPrev->mPrev[2].mNext)(mPrev) )
        break;
    }
    p_mNext = (NISManager *)&p_mNext->mpActiveInstance.m_pPointer[-1].mNISSceneRoot.v3.z;
    if ( p_mNext == (NISManager *)p_m_SequenceNode )
      return 0i64;
  }
  return p_mNext;
}

// File Line: 1775
// RVA: 0x3E51B0
void __fastcall NISManager::SetPlayTime(NISManager *this, float timeAbsolute, bool syncSceneTime)
{
  NISManager *AudioMasterTask; // rax
  NISManager *v6; // rbx
  int v7; // edi
  UFG::qNode<NISInstance,NISInstanceMasterList> *mPrev; // rcx
  NISNode *mpNISNode; // r14
  bool v10; // r13
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rbx
  hkReferencedObject *v17; // rcx
  hkReferencedObject *v18; // rbx
  __int64 *v19; // rax
  int v20; // edi
  hkReferencedObject *v21; // rcx
  unsigned int *v22; // rsi
  int v23; // eax
  __m128 v24; // xmm4
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128i v27; // xmm6
  __m128 v28; // xmm2
  __m128 v29; // xmm3
  unsigned int v30; // r9d
  unsigned int v31; // eax
  UFG::qResourceData *mData; // rax
  unsigned int mPrev_high; // r10d
  unsigned int *v34; // rcx
  unsigned int v35; // edx
  unsigned int v36; // eax
  int v37; // r12d
  unsigned int i; // ebp
  UFG::qSymbol *v39; // rax
  UFG::qBaseNodeRB *SimObject; // rax
  UFG::SimComponent *v41; // rax
  UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *p_m_BoundComponentHandles; // rsi
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v43; // rbx
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *j; // rdi
  hkReferencedObject *v45; // [rsp+A0h] [rbp+8h] BYREF
  int v46; // [rsp+A8h] [rbp+10h]
  unsigned int v47; // [rsp+B0h] [rbp+18h]
  hkReferencedObject *v48; // [rsp+B8h] [rbp+20h] BYREF

  v46 = 0;
  if ( syncSceneTime )
  {
    AudioMasterTask = NISManager::GetAudioMasterTask(this);
    v6 = AudioMasterTask;
    if ( AudioMasterTask )
    {
      v7 = (int)(float)(timeAbsolute * 1000.0);
      mPrev = AudioMasterTask->mInstances.mNode.mPrev[20].mPrev;
      if ( mPrev && ((__int64)mPrev[9].mPrev & 0x40) != 0 )
        ((void (__fastcall *)(UFG::qNode<NISInstance,NISInstanceMasterList> *, _QWORD))mPrev->mPrev[2].mNext)(
          mPrev,
          (unsigned int)v7);
      *(float *)&v6->mPaused = (float)v7 * 0.001;
      this->mAudioTime = timeAbsolute;
    }
    TimePlotPoint::SetTimeValue((UFG::TimeOfDayManager *)&this->mActionController, timeAbsolute);
  }
  mpNISNode = this->mpActiveInstance.m_pPointer->mpNISNode;
  v10 = 0;
  if ( !this->mbCameraAttached )
    goto LABEL_41;
  if ( !this->mSpatialDataHandle.mData )
    goto LABEL_41;
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( !m_pSimObject )
    goto LABEL_41;
  ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::AnimatedCameraComponent::_TypeUID);
  if ( !ComponentOfType )
    goto LABEL_41;
  v13 = ComponentOfType[23].m_SafePointerList.mNode.mPrev[12].mPrev;
  mNext = v13[6].mNext;
  if ( mNext )
  {
    mNext = mNext[6].mPrev;
    if ( mNext )
      goto LABEL_18;
  }
  v15 = v13[8].mNext;
  if ( v15 )
  {
    v16 = v15[6].mNext;
    if ( !v16 )
    {
LABEL_21:
      v21 = 0i64;
      v45 = 0i64;
      v19 = (__int64 *)&v45;
      v20 = 2;
      v18 = v48;
      goto LABEL_22;
    }
    mNext = v16[6].mPrev;
  }
  if ( !mNext )
    goto LABEL_21;
LABEL_18:
  v17 = (hkReferencedObject *)mNext[1].mNext;
  if ( v17 )
    hkReferencedObject::addReference(v17);
  v18 = (hkReferencedObject *)mNext[1].mNext;
  v48 = v18;
  v19 = (__int64 *)&v48;
  v20 = 1;
  v21 = v45;
LABEL_22:
  v46 = v20;
  v22 = (unsigned int *)*v19;
  if ( (v20 & 2) != 0 )
  {
    v20 &= ~2u;
    v46 = v20;
    if ( v21 )
      hkReferencedObject::removeReference(v21);
    v45 = 0i64;
  }
  if ( (v20 & 1) != 0 )
  {
    if ( v18 )
      hkReferencedObject::removeReference(v18);
    v48 = 0i64;
  }
  v47 = LODWORD(timeAbsolute);
  v23 = (*(__int64 (__fastcall **)(unsigned int *))(*(_QWORD *)v22 + 64i64))(v22) - 1;
  v24 = _mm_shuffle_ps((__m128)v22[5], (__m128)v22[5], 0);
  v25 = 0i64;
  v25.m128_f32[0] = (float)v23;
  v26 = _mm_rcp_ps(v24);
  v27 = (__m128i)_mm_and_ps(
                   _mm_cmplt_ps((__m128)0i64, v24),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v26, v24)), v26),
                       _mm_shuffle_ps((__m128)v47, (__m128)v47, 0)),
                     _mm_shuffle_ps(v25, v25, 0)));
  v28 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v27, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v29 = _mm_cmplt_ps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v27, 1u), 1u));
  v30 = _mm_cvtsi128_si32(
          _mm_cvttps_epi32(
            _mm_or_ps(
              _mm_andnot_ps(v29, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmplt_ps((__m128)v27, v28)), v28)),
              _mm_and_ps(v29, (__m128)v27))));
  v31 = v23 - 1;
  if ( v30 > v31 )
    v30 = v31;
  mData = this->mSpatialDataHandle.mData;
  mPrev_high = HIDWORD(mData[1].mResourceHandles.mNode.mPrev);
  v34 = (unsigned int *)mData[1].mResourceHandles.mNode.mNext;
  if ( v34 )
    v34 = (unsigned int *)((char *)v34 + (_QWORD)mData + 128);
  v35 = 0;
  if ( mPrev_high )
  {
    while ( 1 )
    {
      v36 = *v34;
      if ( v30 == *v34 || v30 + 1 == v36 )
        break;
      if ( v30 + 1 >= v36 )
      {
        ++v35;
        ++v34;
        if ( v35 < mPrev_high )
          continue;
      }
      goto LABEL_41;
    }
    v10 = 1;
  }
LABEL_41:
  if ( gSprinDriverAdjust && v10 )
  {
    if ( mpNISNode )
    {
      v37 = (int)mpNISNode->vfptr[1].GetClassname(mpNISNode);
      for ( i = 0; (int)i < v37; ++i )
      {
        v39 = (UFG::qSymbol *)((__int64 (__fastcall *)(NISNode *, _QWORD))mpNISNode->vfptr[1].Serialize)(mpNISNode, i);
        if ( v39 )
        {
          SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, v39 + 64);
          if ( SimObject )
          {
            v41 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)SimObject,
                    UFG::CharacterAnimationComponent::_TypeUID);
            if ( v41 )
              v41 = *(UFG::SimComponent **)&v41[2].m_TypeUID;
            if ( v41 )
            {
              p_m_BoundComponentHandles = &v41[3].m_BoundComponentHandles;
              v43 = (UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *)(*(_QWORD *)&v41->m_Flags - 16i64);
              for ( j = &v41->m_SafePointerList;
                    v43 != j;
                    v43 = (UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *)&v43[1].mNode.mNext[-1] )
              {
                ((void (__fastcall *)(UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *, UFG::qList<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase,0,0> *))v43->mNode.mPrev[10].mPrev)(
                  v43,
                  p_m_BoundComponentHandles);
              }
            }
          }
        }
      }
    }
  }
  NISNode::SetPlayTime(mpNISNode, timeAbsolute, v10);
  this->mTime = timeAbsolute;
}

// File Line: 1867
// RVA: 0x3E79D0
bool __fastcall NISManager::UseHighDefModel(NISManager *this, UFG::qSymbol *actorId)
{
  NISInstance *m_pPointer; // rdi
  NISNode *mpNISNode; // rdi
  unsigned int v6; // ebx
  int v7; // esi
  __int64 v8; // rcx

  if ( this->mHighDefModelsEnabled )
    return 1;
  m_pPointer = this->mpActiveInstance.m_pPointer;
  if ( m_pPointer )
    mpNISNode = m_pPointer->mpNISNode;
  else
    mpNISNode = 0i64;
  if ( !mpNISNode )
    return 0;
  v6 = 0;
  v7 = (int)mpNISNode->vfptr[1].GetClassname(mpNISNode);
  if ( v7 <= 0 )
    return 0;
  while ( 1 )
  {
    v8 = ((__int64 (__fastcall *)(NISNode *, _QWORD))mpNISNode->vfptr[1].Serialize)(mpNISNode, v6);
    if ( *(_DWORD *)(v8 + 256) == actorId->mUID )
      break;
    if ( (int)++v6 >= v7 )
      return 0;
  }
  return *(_BYTE *)(v8 + 269) != 0;
}

// File Line: 1889
// RVA: 0x3E30B0
char __fastcall NISManager::IsActiveInNIS(NISManager *this, UFG::SimObject *simObject)
{
  NISInstance *m_pPointer; // rdi
  unsigned int v5; // ebx
  NISNode *mpNISNode; // rdi
  int v7; // esi

  if ( !simObject || this->mState == STATE_INVALID )
    return 0;
  m_pPointer = this->mpActiveInstance.m_pPointer;
  v5 = 0;
  if ( m_pPointer )
    mpNISNode = m_pPointer->mpNISNode;
  else
    mpNISNode = 0i64;
  if ( !mpNISNode )
    return 0;
  v7 = (int)mpNISNode->vfptr[1].GetClassname(mpNISNode);
  if ( v7 <= 0 )
    return 0;
  while ( *(_DWORD *)(((__int64 (__fastcall *)(NISNode *, _QWORD))mpNISNode->vfptr[1].Serialize)(mpNISNode, v5) + 256) != simObject->m_Name.mUID )
  {
    if ( (int)++v5 >= v7 )
      return 0;
  }
  return 1;
}

// File Line: 1914
// RVA: 0x3E3060
bool __fastcall NISManager::IntersectsSpatialBoundingBox(NISManager *this, UFG::qBox *box)
{
  float *mData; // rax

  mData = (float *)this->mSpatialDataHandle.mData;
  return mData[25] >= box->mMin.x
      && mData[22] <= box->mMax.x
      && mData[26] >= box->mMin.y
      && mData[23] <= box->mMax.y
      && mData[27] >= box->mMin.z
      && mData[24] <= box->mMax.z;
}

// File Line: 1923
// RVA: 0x3E3760
void __fastcall NISManager::OnCameraAttached(NISManager *this, CameraAnimationTask *cameraTask)
{
  ITrack *m_Track; // rdi
  AnimationNode *m_pPointer; // rcx
  NISInstance *v5; // rax
  NISNode *mpNISNode; // rax

  m_Track = cameraTask->m_Track;
  m_pPointer = cameraTask->mController.m_pPointer;
  if ( m_pPointer )
    this->mLength = SkeletalAnimation::GetDuration(m_pPointer->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer);
  if ( this->mState )
  {
    v5 = this->mpActiveInstance.m_pPointer;
    if ( v5 )
    {
      mpNISNode = v5->mpNISNode;
      if ( mpNISNode )
      {
        if ( mpNISNode->mPrimaryCameraAnimationTrack == m_Track )
        {
          this->mbCameraAttached = 1;
          if ( mpNISNode->mDisableHUD )
            NISManager::HideHUD(this);
        }
      }
    }
  }
}

// File Line: 1954
// RVA: 0x3E37D0
void __fastcall NISManager::OnCameraDetached(NISManager *this, CameraAnimationTrack *cameraTrack)
{
  NISInstance *m_pPointer; // rbx
  NISNode *mpNISNode; // rbx
  UFG::ProgressionTracker *v5; // rax

  if ( this->mState )
  {
    m_pPointer = this->mpActiveInstance.m_pPointer;
    if ( m_pPointer )
    {
      mpNISNode = m_pPointer->mpNISNode;
      if ( mpNISNode )
      {
        if ( mpNISNode->mPrimaryCameraAnimationTrack == cameraTrack )
        {
          this->mbCameraAttached = 0;
          if ( mpNISNode->mDisableHUD )
          {
            if ( this->mHudDisableCount-- == 1 )
              UFG::UIHK_NISOverlay::HideLetterBox();
          }
        }
        if ( !mpNISNode->mSeamlessOut )
        {
          v5 = UFG::ProgressionTracker::Instance();
          UFG::ProgressionTracker::SetResourceFreezeMode(v5, 1);
        }
      }
    }
  }
}

// File Line: 2000
// RVA: 0x3E25C0
NISInstance *__fastcall NISManager::CreateInstance(NISManager *this, const char *pathName)
{
  UFG::allocator::free_link *v4; // rax
  __int64 v5; // rax
  __int64 v6; // r8
  UFG::qNode<NISInstance,NISInstanceMasterList> *mPrev; // rax

  v4 = UFG::qMalloc(0x1A0ui64, "NISManager::CreateInstance", 0i64);
  if ( v4 )
  {
    NISInstance::NISInstance((NISInstance *)v4, pathName);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  mPrev = this->mInstances.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<NISInstance,NISInstanceMasterList> *)(v6 + 24);
  *(_QWORD *)(v6 + 24) = mPrev;
  *(_QWORD *)(v6 + 32) = &this->mInstances;
  this->mInstances.mNode.mPrev = (UFG::qNode<NISInstance,NISInstanceMasterList> *)(v6 + 24);
  return (NISInstance *)v6;
}

// File Line: 2016
// RVA: 0x3E2640
void __fastcall NISManager::DestroyInstance(NISManager *this, NISInstance *pInstance)
{
  UFG::qNode<NISInstance,NISInstanceMasterList> *mPrev; // r8
  UFG::qNode<NISInstance,NISInstanceMasterList> *mNext; // rax
  UFG::qSafePointer<NISInstance,NISInstance> *p_mpPreloadInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v8; // rax

  mPrev = pInstance->mPrev;
  mNext = pInstance->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  pInstance->mPrev = &pInstance->UFG::qNode<NISInstance,NISInstanceMasterList>;
  pInstance->mNext = &pInstance->UFG::qNode<NISInstance,NISInstanceMasterList>;
  if ( pInstance )
    pInstance->vfptr->__vecDelDtor(pInstance, 1i64);
  if ( pInstance == this->mpPreloadInstance.m_pPointer )
  {
    p_mpPreloadInstance = &this->mpPreloadInstance;
    if ( this->mpPreloadInstance.m_pPointer )
    {
      v7 = p_mpPreloadInstance->mPrev;
      v8 = this->mpPreloadInstance.mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      p_mpPreloadInstance->mPrev = p_mpPreloadInstance;
      this->mpPreloadInstance.mNext = &this->mpPreloadInstance;
    }
    this->mpPreloadInstance.m_pPointer = 0i64;
  }
}

