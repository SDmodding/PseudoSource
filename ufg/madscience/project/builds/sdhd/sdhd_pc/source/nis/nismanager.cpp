// File Line: 136
// RVA: 0x14CF180
__int64 dynamic_initializer_for__nis_mixer_exit_to_game__()
{
  nis_mixer_exit_to_game.mUID = UFG::qWiseSymbolUIDFromString("nis_mixer_exit_to_game", 0x811C9DC5);
  _((AMD_HD3D *)nis_mixer_exit_to_game.mUID);
  return atexit(dynamic_atexit_destructor_for__nis_mixer_exit_to_game__);
}

// File Line: 137
// RVA: 0x14CF1D0
__int64 dynamic_initializer_for__nis_mixer_exit_to_game_instant__()
{
  nis_mixer_exit_to_game_instant.mUID = UFG::qWiseSymbolUIDFromString("nis_mixer_exit_to_game_instant", 0x811C9DC5);
  _((AMD_HD3D *)nis_mixer_exit_to_game_instant.mUID);
  return atexit(dynamic_atexit_destructor_for__nis_mixer_exit_to_game_instant__);
}

// File Line: 140
// RVA: 0x3E2FC0
void NISManager::Init(void)
{
  char *v0; // rax
  NISManager *v1; // rax
  UFG::qSharedString filename; // [rsp+40h] [rbp+8h]

  UFG::qSharedString::qSharedString(&filename, "Data\\AnimationNIS\\NISSpatialData.bin");
  gSpatialDataStreamPriorityHandle = UFG::StreamPrioritySystem::CreateHandle(
                                       NISManager::sStreamPrioritySystem,
                                       &filename);
  UFG::qSharedString::~qSharedString(&filename);
  UFG::StreamPrioritySystem::ChangePriority(
    NISManager::sStreamPrioritySystem,
    gSpatialDataStreamPriorityHandle,
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
  NISManager *v1; // rbx
  ActionContext *v2; // rdi
  UFG::qSafePointer<NISInstance,NISInstance> *v3; // rax
  UFG::qList<NISInstance,NISInstanceMasterList,0,0> *v4; // rax
  ActionController *v5; // rsi
  UFG::allocator::free_link *v6; // rax
  ActionContext *v7; // rax
  ActionContext *v8; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v9; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->mpActiveInstance.mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&this->mpActiveInstance.mPrev;
  this->mpActiveInstance.mNext = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&this->mpActiveInstance.mPrev;
  v2 = 0i64;
  this->mpActiveInstance.m_pPointer = 0i64;
  v3 = &this->mpPreloadInstance;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  this->mpPreloadInstance.m_pPointer = 0i64;
  v4 = &this->mInstances;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v5 = &this->mActionController;
  ActionController::ActionController(&this->mActionController);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mSpatialDataHandle.mPrev);
  v1->mpDynamicOutline = 0i64;
  v9 = &v1->mDisabledVehicle;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v1->mDisabledVehicle.m_pPointer = 0i64;
  v1->mbAudioStopped = 0;
  v1->mUIHelpbarLocked = 0;
  UFG::SceneSettings::SceneSettings(&v1->mPostNisSettings, "NisManager");
  v1->mPlaceHolderTimeOut = 0.0;
  v6 = UFG::qMalloc(0xD8ui64, "ActionTreeComponent::ActionContext", 0i64);
  if ( v6 )
  {
    ActionContext::ActionContext((ActionContext *)v6);
    v2 = v7;
  }
  v1->mpActionContext = v2;
  ActionContext::Reset(v2, eACTION_TREE_TYPE_ACTION, 0i64);
  v8 = v1->mpActionContext;
  v1->mActionController.m_Context = v8;
  v8->mActionController = v5;
  v1->mActionController.mKeepAlive = 0;
  NISManager::Reset(v1);
}

// File Line: 223
// RVA: 0x3E0BB0
void __fastcall NISManager::~NISManager(NISManager *this)
{
  NISManager *v1; // rbx
  ActionContext *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax
  UFG::qSafePointer<NISInstance,NISInstance> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v19; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v20; // rax
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v21; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v22; // rax

  v1 = this;
  NISManager::AllowGameStateChanges(this);
  NISManager::StopNIS(v1);
  NISManager::ResetNISSettings(v1);
  NISManager::Reset(v1);
  v2 = v1->mpActionContext;
  if ( v2 )
  {
    if ( v2->mSimObject.m_pPointer )
    {
      v3 = v2->mSimObject.mPrev;
      v4 = v2->mSimObject.mNext;
      v3->mNext = v4;
      v4->mPrev = v3;
      v2->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mSimObject.mPrev;
      v2->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mSimObject.mPrev;
    }
    v2->mSimObject.m_pPointer = 0i64;
    v5 = v2->mSimObject.mPrev;
    v6 = v2->mSimObject.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mSimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mSimObject.mPrev;
    v2->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mSimObject.mPrev;
    operator delete[](v2);
  }
  UFG::SceneSettings::~SceneSettings(&v1->mPostNisSettings);
  v7 = &v1->mDisabledVehicle;
  if ( v1->mDisabledVehicle.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mDisabledVehicle.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mDisabledVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mDisabledVehicle.mPrev;
  }
  v1->mDisabledVehicle.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mDisabledVehicle.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mDisabledVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mDisabledVehicle.mPrev;
  v12 = `UFG::qGetResourceInventory<UFG::NISSpatialData>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::NISSpatialData>'::`2'::result )
  {
    v13 = UFG::qResourceWarehouse::Instance();
    v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x59362AA3u);
    `UFG::qGetResourceInventory<UFG::NISSpatialData>'::`2'::result = v12;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSpatialDataHandle.mPrev, v12);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mSpatialDataHandle.mPrev);
  ActionController::~ActionController(&v1->mActionController);
  UFG::qList<NISInstance,NISInstanceMasterList,0,0>::~qList<NISInstance,NISInstanceMasterList,0,0>(&v1->mInstances);
  v14 = &v1->mpPreloadInstance;
  if ( v1->mpPreloadInstance.m_pPointer )
  {
    v15 = v14->mPrev;
    v16 = v1->mpPreloadInstance.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v14->mPrev;
    v1->mpPreloadInstance.mNext = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v1->mpPreloadInstance.mPrev;
  }
  v1->mpPreloadInstance.m_pPointer = 0i64;
  v17 = v14->mPrev;
  v18 = v1->mpPreloadInstance.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v1->mpPreloadInstance.mNext = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v1->mpPreloadInstance.mPrev;
  if ( v1->mpActiveInstance.m_pPointer )
  {
    v19 = v1->mpActiveInstance.mPrev;
    v20 = v1->mpActiveInstance.mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    v1->mpActiveInstance.mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v1->mpActiveInstance.mPrev;
    v1->mpActiveInstance.mNext = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v1->mpActiveInstance.mPrev;
  }
  v1->mpActiveInstance.m_pPointer = 0i64;
  v21 = v1->mpActiveInstance.mPrev;
  v22 = v1->mpActiveInstance.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  v1->mpActiveInstance.mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v1->mpActiveInstance.mPrev;
  v1->mpActiveInstance.mNext = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v1->mpActiveInstance.mPrev;
}

// File Line: 230
// RVA: 0x3E3B30
char __fastcall NISManager::Play(NISManager *this, const char *pathName)
{
  NISManager *v2; // rbx
  NISInstance *v3; // rax

  v2 = this;
  v3 = NISManager::CreateInstance(this, pathName);
  v3->mbDestroyOnUnload = 1;
  v3->mbPostNISFadeIn = 1;
  return NISManager::PlayInternal(v2, v3);
}

// File Line: 246
// RVA: 0x3E3B20
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
  NISManager *v1; // rbx
  UFG::SimObjectCharacter *v2; // rax
  unsigned __int16 v3; // r8
  UFG::SimComponent *v4; // rcx
  UFG::SimComponent *v5; // rax

  v1 = this;
  this->mModifyPlayerVulnerability = 0;
  v2 = UFG::GetLocalPlayer();
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[6].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::HealthComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::HealthComponent::_TypeUID);
      }
      else
      {
        v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HealthComponent::_TypeUID);
      }
      v4 = v5;
    }
    else
    {
      v4 = v2->m_Components.p[6].m_pComponent;
    }
    if ( v4 )
    {
      v1->mModifyPlayerVulnerability = BYTE5(v4[1].m_BoundComponentHandles.mNode.mPrev) == 0;
      BYTE5(v4[1].m_BoundComponentHandles.mNode.mPrev) = 1;
    }
  }
}

// File Line: 278
// RVA: 0x3E15E0
void __fastcall NISManager::AllowGameStateChanges(NISManager *this)
{
  NISManager *v1; // rbx
  UFG::SimObjectCharacter *v2; // rax
  unsigned __int16 v3; // r8
  UFG::SimComponent *v4; // rax

  v1 = this;
  v2 = UFG::GetLocalPlayer();
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[6].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::HealthComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v2->vfptr, UFG::HealthComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::HealthComponent::_TypeUID);
      }
    }
    else
    {
      v4 = v2->m_Components.p[6].m_pComponent;
    }
    if ( v4 )
    {
      if ( v1->mModifyPlayerVulnerability )
        BYTE5(v4[1].m_BoundComponentHandles.mNode.mPrev) = 0;
    }
  }
}

// File Line: 292
// RVA: 0x3E4560
void __fastcall NISManager::Reset(NISManager *this)
{
  NISManager *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  NISInstance *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  v1 = this;
  ActionController::Stop(&this->mActionController);
  v2 = `UFG::qGetResourceInventory<UFG::NISSpatialData>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::NISSpatialData>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0x59362AA3u);
    `UFG::qGetResourceInventory<UFG::NISSpatialData>'::`2'::result = v2;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSpatialDataHandle.mPrev, v2);
  if ( v1->mpDynamicOutline )
  {
    ((void (*)(void))UFG::NavManager::ms_pInstance->vfptr->RemoveDynamicOutline)();
    v1->mpDynamicOutline = 0i64;
  }
  v1->mPaused = 0;
  v1->mState = 0;
  *(_QWORD *)&v1->mfStateTimeoutS = 2139095039i64;
  *(_QWORD *)&v1->mTime = 0i64;
  v1->mTimeToEndAt = -1.0;
  *(_QWORD *)&v1->mAudioTime = -1082130432i64;
  *(_WORD *)&v1->mbCurtainsShown = 0;
  v1->mbUserInputDisabled = 0;
  *(_QWORD *)&v1->mHudDisableCount = 0i64;
  v1->mbStreamingComplete = 0;
  UFG::SceneSettings::Reset(&v1->mPostNisSettings);
  v4 = v1->mpActiveInstance.m_pPointer;
  if ( v4 )
  {
    NISInstance::Unload(v4, 1);
    if ( v1->mpActiveInstance.m_pPointer )
    {
      v5 = v1->mpActiveInstance.mPrev;
      v6 = v1->mpActiveInstance.mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      v1->mpActiveInstance.mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v1->mpActiveInstance.mPrev;
      v1->mpActiveInstance.mNext = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v1->mpActiveInstance.mPrev;
    }
    v1->mpActiveInstance.m_pPointer = 0i64;
  }
  v7 = &v1->mDisabledVehicle;
  if ( v1->mDisabledVehicle.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mDisabledVehicle.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mDisabledVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mDisabledVehicle.mPrev;
  }
  v1->mDisabledVehicle.m_pPointer = 0i64;
  v1->mbAudioStopped = 0;
}

// File Line: 342
// RVA: 0x3E5D10
void __fastcall NISManager::SetupNISSettingsPreStreamed(NISManager *this)
{
  NISInstance *v1; // rax
  UFG::SceneSettings *v2; // rbp
  UFG::SceneSettings *v3; // rdx
  NISNode *v4; // rsi
  NISManager *v5; // rbx
  UFG::SceneSettings *v6; // rcx
  NISInstance *v7; // rcx
  bool v8; // al
  UFG::SimObject *v9; // rcx
  UFG::SimComponent *v10; // rax
  UFG::ObjectResourceManager *v11; // rax
  UFG::PedSpawnManager *v12; // rax
  UFG::TimeOfDayManager *v13; // rax
  UFG::TimeOfDayManager *v14; // rdi
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  UFG::TimeOfDayManager *v18; // rax
  UFG::TimeOfDayManager *v19; // rdi
  bool v20; // zf
  __int64 v21; // rax
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  UFG::PedSpawnManager *v25; // rax
  UFG::CopSystem *v26; // rax
  UFG::CopSystem *v27; // rax
  __int64 v28; // [rsp+20h] [rbp-28h]
  float v29; // [rsp+28h] [rbp-20h]
  int v30; // [rsp+2Ch] [rbp-1Ch]
  float v31; // [rsp+30h] [rbp-18h]
  int v32; // [rsp+34h] [rbp-14h]
  int timeInSeconds; // [rsp+50h] [rbp+8h]

  v1 = this->mpActiveInstance.m_pPointer;
  v2 = &this->mPostNisSettings;
  v3 = v1->mpPostNISSceneSettings;
  v4 = v1->mpNISNode;
  v5 = this;
  v6 = &this->mPostNisSettings;
  if ( v3 )
    UFG::SceneSettings::operator=(v6, v3);
  else
    UFG::SceneSettings::Reset(v6);
  v7 = v5->mpActiveInstance.m_pPointer;
  v5->mPostNisSettings.mShowCurtains = 0;
  v5->mPostNisSettings.mHideCurtains = v7->mbPostNISFadeIn;
  if ( v7->mbIntermediateNIS )
  {
    v8 = UFG::WheeledVehicleManager::mTrafficCarSpawningEnabled
      && UFG::WheeledVehicleManager::m_TrafficSpawningUpdatesEnabled;
    v5->mPostNisSettings.mEnableTrafficOnEnd = v8;
    v5->mPostNisSettings.mEnableAmbientPedsOnEnd = UFG::PedSpawnManager::msAmbientSpawningEnable;
  }
  v9 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v9 )
  {
    v10 = UFG::SimObject::GetComponentOfType(v9, UFG::CameraAnimationComponent::_TypeUID);
    if ( v10 )
      HIBYTE(v10[2].m_Flags) = 1;
  }
  if ( v4->mDisableAmbientPeds && !v4->mSeamlessOut )
  {
    UFG::PedSpawning_AmbientPedEnableHelper(0);
    UFG::WheeledVehicleManager::EnableTrafficSystem(UFG::WheeledVehicleManager::m_Instance, 0);
    v11 = UFG::ObjectResourceManager::Instance();
    UFG::ObjectResourceManager::ReleaseAllAmbientPreloads(v11);
    v5->mPostNisSettings.mResetAmbientPeds = 1;
  }
  if ( v4->mDisableScriptedPeds )
  {
    v12 = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::SuspendAllScripted(v12);
    UFG::PedSpawnManager::SetScriptedStatusCheckEnable(0);
    if ( UFG::PedSpawnManager::msAmbientSpawningEnable == 1 )
      UFG::PedSpawnManager::SetAmbientSpawningEnable(0);
    v5->mPostNisSettings.mResetAmbientPeds = 1;
  }
  v13 = UFG::TimeOfDayManager::GetInstance();
  v14 = v13;
  if ( v5->mPostNisSettings.mTimeOverrideInSeconds < 0.0 )
    v5->mPostNisSettings.mTimeOverrideInSeconds = v13->m_SecondsSinceMidnight;
  if ( !v5->mPostNisSettings.mTimeOverrideLockSet )
  {
    v2->mTimeOverrideLock = v13->m_GameSecondsPerRealSecond == 0.0;
    v2->mTimeOverrideLockSet = 1;
  }
  if ( v4->mInteriorTime )
  {
    UFG::TimeOfDayManager::SetTime(v13, 82800.0, 0);
    TimePlotPoint::SetTimeValue(v14, 0.0);
    goto LABEL_36;
  }
  if ( v4->mTODTime < 0.0 )
  {
    if ( v4->mForceContinousTimeMode )
      goto LABEL_36;
    v16 = v13->m_SecondsSinceMidnight;
    v17 = FLOAT_39600_0;
    if ( v16 <= 39600.0 )
    {
      if ( v16 <= 45000.0 )
        goto LABEL_36;
    }
    else if ( v16 <= 45000.0 )
    {
LABEL_35:
      UFG::TimeOfDayManager::SetTime(v13, v17, 0);
      goto LABEL_36;
    }
    v17 = FLOAT_50400_0;
    if ( v16 >= 50400.0 )
      goto LABEL_36;
    goto LABEL_35;
  }
  v15 = v4->mTODTime;
  timeInSeconds = 0;
  if ( UFG::TimeOfDayManager::GetTimeInSeconds(v15, &timeInSeconds) )
  {
    UFG::TimeOfDayManager::SetTime(v14, (float)timeInSeconds, 0);
    TimePlotPoint::SetTimeValue(v14, 40.0);
  }
LABEL_36:
  v14->mGlobalIlluminationBlend = v4->mGI_Irradiance;
  v18 = UFG::TimeOfDayManager::GetInstance();
  v19 = v18;
  if ( v5->mPostNisSettings.mWeatherOverrideIntensity < 0.0 )
    v5->mPostNisSettings.mWeatherOverrideIntensity = v18->m_WeatherState;
  if ( !v5->mPostNisSettings.mWeatherOverrideLockSet )
  {
    v20 = v18->m_WeatherRandomInterval == 0;
    v2->mWeatherOverrideLockSet = 1;
    v2->mWeatherOverrideLock = v20;
  }
  if ( v5->mPostNisSettings.mWeatherOverrideWetness < 0.0 )
    v5->mPostNisSettings.mWeatherOverrideWetness = v18->m_OverrideSurfaceWetness;
  UFG::TimeOfDayManager::LockWeather(v18, 1);
  v21 = (signed int)v4->mWeatherType.mValue;
  if ( (_DWORD)v21 )
  {
    v28 = 0i64;
    v32 = 0x40000000;
    v29 = FLOAT_0_1;
    v30 = (signed int)FLOAT_1_0;
    v22 = FLOAT_2_0;
    v31 = FLOAT_1_5;
    v23 = *((float *)&v28 + v21);
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
  v24 = v4->mWeatherWetness;
  if ( v24 >= 0.0 )
    UFG::TimeOfDayManager::SetSurfaceWetnessOverride(v19, v24, "NISManager::SetupNISSettingsPreStreamed");
  UFG::StreamedResourceComponent::sAssetLoadDistance = FLOAT_3_4028235e38;
  Render::SetVSyncEnable(VSYNC_TRUE);
  v25 = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::SetupSocialForNIS(v25, 1);
  v26 = UFG::CopSystem::Instance();
  v5->mWasCopSystemEnabled = ((__int64 (__fastcall *)(UFG::CopSystem *))v26->vfptr[7].__vecDelDtor)(v26);
  v27 = UFG::CopSystem::Instance();
  v27->vfptr[4].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v27->vfptr, 0);
}

// File Line: 505
// RVA: 0x3E5770
void __fastcall NISManager::SetupNISSettingsPostStreamed(NISManager *this)
{
  NISManager *v1; // r13
  NISNode *v2; // r15
  UFG::TiDo *v3; // rax
  _BOOL8 v4; // rdx
  unsigned __int64 v5; // rax
  const char *v6; // rcx
  const char *v7; // rcx
  unsigned int v8; // eax
  UFG::SimComponent *v9; // r14
  UFG::VehicleOwnershipComponent *v10; // rsi
  unsigned __int16 v11; // dx
  UFG::VehicleOwnershipComponent *v12; // rax
  UFG::SimObjectGame *v13; // rax
  unsigned __int16 v14; // dx
  UFG::PhysicsMoverInterface *v15; // rax
  UFG::SimObjectGame *v16; // rax
  unsigned __int16 v17; // dx
  UFG::VehicleEffectsComponent *v18; // rax
  const char *v19; // rcx
  unsigned int v20; // ebx
  UFG::qResourceInventory *v21; // rax
  UFG::qResourceWarehouse *v22; // rax
  UFG::qResourceData *v23; // r12
  float v24; // xmm2_4
  float v25; // xmm4_4
  unsigned int v26; // xmm0_4
  unsigned int v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm1_4
  UFG::PedSpawnManager *v31; // rax
  UFG::SimObjectGame *v32; // rax
  UFG::SimObject *v33; // rbx
  unsigned __int16 v34; // cx
  UFG::SimComponent *v35; // rax
  float *v36; // rax
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  UFG::qVector3 max; // [rsp+30h] [rbp-29h]
  UFG::qVector3 min; // [rsp+40h] [rbp-19h]
  UFG::qVector4 v44; // [rsp+50h] [rbp-9h]
  UFG::qVector4 v45; // [rsp+60h] [rbp+7h]
  UFG::qVector4 v46; // [rsp+70h] [rbp+17h]
  __int128 v47; // [rsp+80h] [rbp+27h]

  v1 = this;
  v2 = this->mpActiveInstance.m_pPointer->mpNISNode;
  if ( UFG::TiDo::GetInstance() )
  {
    v3 = UFG::TiDo::GetInstance();
    LOBYTE(v4) = 1;
    v3->vfptr->SetNISMode(v3, v4);
  }
  v5 = v2->mLightLayerDisableName.mOffset & 0xFFFFFFFFFFFFFFFEui64;
  if ( v5 )
    v6 = (char *)&v2->mLightLayerDisableName + v5;
  else
    v6 = BinString::sEmptyString;
  if ( *v6 )
  {
    if ( v5 )
      v7 = (char *)&v2->mLightLayerDisableName + v5;
    else
      v7 = BinString::sEmptyString;
    v8 = UFG::qStringHashUpper32(v7, 0xFFFFFFFF);
    v1->mLightLayerUID = v8;
    Render::EnableLightLayer(v8, 0);
  }
  v9 = 0i64;
  if ( !LocalPlayer )
  {
    v10 = 0i64;
    goto LABEL_46;
  }
  v11 = LocalPlayer->m_Flags;
  if ( (v11 >> 14) & 1 )
  {
    v12 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                              UFG::VehicleOwnershipComponent::_TypeUID);
  }
  else if ( (v11 & 0x8000u) == 0 )
  {
    if ( (v11 >> 13) & 1 )
    {
      v12 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                UFG::VehicleOwnershipComponent::_TypeUID);
    }
    else if ( (v11 >> 12) & 1 )
    {
      v12 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                UFG::VehicleOwnershipComponent::_TypeUID);
    }
    else
    {
      v12 = (UFG::VehicleOwnershipComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&LocalPlayer->vfptr,
                                                UFG::VehicleOwnershipComponent::_TypeUID);
    }
  }
  else
  {
    v12 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                              UFG::VehicleOwnershipComponent::_TypeUID);
  }
  v10 = v12;
  if ( v12 && UFG::VehicleOwnershipComponent::GetOwnedVehicle(v12) )
  {
    v13 = (UFG::SimObjectGame *)UFG::VehicleOwnershipComponent::GetOwnedVehicle(v10);
    if ( v13 )
    {
      v14 = v13->m_Flags;
      if ( !((v14 >> 14) & 1) )
      {
        if ( (v14 & 0x8000u) != 0 )
        {
          v15 = (UFG::PhysicsMoverInterface *)v13->m_Components.p[34].m_pComponent;
          goto LABEL_32;
        }
        if ( !((v14 >> 13) & 1) )
        {
          if ( (v14 >> 12) & 1 )
            v15 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v13,
                                                  UFG::PhysicsMoverInterface::_TypeUID);
          else
            v15 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v13->vfptr,
                                                  UFG::PhysicsMoverInterface::_TypeUID);
LABEL_32:
          if ( v15 )
            UFG::PhysicsMoverInterface::RepairDamage(v15);
          goto LABEL_34;
        }
      }
    }
LABEL_34:
    v16 = (UFG::SimObjectGame *)UFG::VehicleOwnershipComponent::GetOwnedVehicle(v10);
    if ( v16 )
    {
      v17 = v16->m_Flags;
      if ( (v17 >> 14) & 1 )
      {
        v18 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v16,
                                                UFG::VehicleEffectsComponent::_TypeUID);
      }
      else if ( (v17 & 0x8000u) == 0 )
      {
        if ( (v17 >> 13) & 1 )
          v18 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v16,
                                                  UFG::VehicleEffectsComponent::_TypeUID);
        else
          v18 = (UFG::VehicleEffectsComponent *)((v17 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v16,
                                                                     UFG::VehicleEffectsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v16->vfptr, UFG::VehicleEffectsComponent::_TypeUID));
      }
      else
      {
        v18 = (UFG::VehicleEffectsComponent *)v16->m_Components.p[32].m_pComponent;
      }
      if ( v18 )
        UFG::VehicleEffectsComponent::TurnOffEffects(v18, 0);
    }
  }
LABEL_46:
  if ( v2->mNISName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    v19 = (char *)&v2->mNISName + (v2->mNISName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
  else
    v19 = BinString::sEmptyString;
  v20 = UFG::qStringHash32(v19, 0xFFFFFFFF);
  v21 = `UFG::qGetResourceInventory<UFG::NISSpatialData>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::NISSpatialData>'::`2'::result )
  {
    v22 = UFG::qResourceWarehouse::Instance();
    v21 = UFG::qResourceWarehouse::GetInventory(v22, 0x59362AA3u);
    `UFG::qGetResourceInventory<UFG::NISSpatialData>'::`2'::result = v21;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mSpatialDataHandle.mPrev, 0x59362AA3u, v20, v21);
  v23 = v1->mSpatialDataHandle.mData;
  if ( v23 )
  {
    if ( v2->mUseBoundingBoxToClearPeds )
    {
      v24 = *(float *)&v23[1].mResourceHandles.mNode.mPrev;
      v25 = *(float *)&v23[1].mNode.mUID;
      *(float *)&v26 = *(float *)&v23[1].mNode.mUID - *(float *)&v23[1].mNode.mParent;
      *(float *)&v27 = *((float *)&v23[1].mNode.mUID + 1) - *((float *)&v23[1].mNode.mParent + 1);
      DWORD1(v47) = *(&v23[1].mNode.mUID + 1);
      *(_QWORD *)&max.x = __PAIR__(v27, v26);
      *((_QWORD *)&v47 + 1) = __PAIR__((unsigned int)FLOAT_1_0, LODWORD(v24));
      v28 = v24 - *(float *)v23[1].mNode.mChild;
      v29 = v25 - *((float *)v23[1].mNode.mChild + 1);
      *(float *)&v47 = v25;
      max.z = v28;
      min.x = v29;
      v30 = v24 - *((float *)&v23[1].mNode.mChild[1] + 1);
      min.y = *((float *)&v47 + 1) - *(float *)&v23[1].mNode.mChild[1];
      min.z = v30;
      v45 = UFG::qMatrix44::msIdentity.v1;
      v46 = UFG::qMatrix44::msIdentity.v2;
      v44 = UFG::qMatrix44::msIdentity.v0;
      v1->mpDynamicOutline = (UFG::NavDynamicOutline *)((__int64 (__fastcall *)(UFG::NavManager *, UFG::qVector4 *, UFG::qVector3 *, UFG::qVector3 *, _QWORD, _DWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, unsigned __int64))UFG::NavManager::ms_pInstance->vfptr->AddDynamicOutline)(
                                                         UFG::NavManager::ms_pInstance,
                                                         &v44,
                                                         &max,
                                                         &min,
                                                         0i64,
                                                         0,
                                                         *(_QWORD *)&max.x,
                                                         *(_QWORD *)&max.z,
                                                         *(_QWORD *)&min.x,
                                                         *(_QWORD *)&min.z,
                                                         *(_QWORD *)&UFG::qMatrix44::msIdentity.v0.x,
                                                         *(_QWORD *)&UFG::qMatrix44::msIdentity.v0.z,
                                                         *(_QWORD *)&UFG::qMatrix44::msIdentity.v1.x,
                                                         *(_QWORD *)&UFG::qMatrix44::msIdentity.v1.z,
                                                         *(_QWORD *)&UFG::qMatrix44::msIdentity.v2.x,
                                                         *(_QWORD *)&UFG::qMatrix44::msIdentity.v2.z,
                                                         v47,
                                                         __PAIR__((unsigned int)FLOAT_1_0, LODWORD(v24)));
      v31 = UFG::PedSpawnManager::GetInstance();
      UFG::PedSpawnManager::DeleteAmbientPedsFromNISBoundingVolume(
        v31,
        (UFG::qVector3 *)&v23[1],
        (UFG::qVector3 *)((char *)v23[1].mNode.mChild + 4));
    }
    if ( v2->mUseBoundingBoxToClearVehicles )
    {
      UFG::WheeledVehicleManager::DestroyWheeledVehiclesInNISBoundingVolume(
        UFG::WheeledVehicleManager::m_Instance,
        (UFG::qVector3 *)&v23[1],
        (UFG::qVector3 *)((char *)v23[1].mNode.mChild + 4));
      if ( v10 )
      {
        if ( UFG::VehicleOwnershipComponent::GetOwnedVehicle(v10) )
        {
          v32 = (UFG::SimObjectGame *)UFG::VehicleOwnershipComponent::GetOwnedVehicle(v10);
          v33 = (UFG::SimObject *)&v32->vfptr;
          if ( v32 )
          {
            v34 = v32->m_Flags;
            if ( (v34 >> 14) & 1 )
            {
              v9 = v32->m_Components.p[14].m_pComponent;
            }
            else if ( (v34 & 0x8000u) == 0 )
            {
              if ( (v34 >> 13) & 1 )
              {
                v9 = v32->m_Components.p[9].m_pComponent;
              }
              else
              {
                if ( (v34 >> 12) & 1 )
                  v35 = UFG::SimObjectGame::GetComponentOfTypeHK(v32, UFG::CompositeDrawableComponent::_TypeUID);
                else
                  v35 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v32->vfptr,
                          UFG::CompositeDrawableComponent::_TypeUID);
                v9 = v35;
              }
            }
            else
            {
              v9 = v32->m_Components.p[14].m_pComponent;
            }
          }
          if ( !NISManager::IsActiveInNIS(v1, v33) )
          {
            if ( v9 )
            {
              v36 = (float *)v9[22].m_SafePointerList.mNode.mNext;
              if ( v36 )
              {
                v37 = v36[33];
                min.x = v36[32];
                v38 = v36[34];
                min.y = v37;
                v39 = v36[35];
                min.z = v38;
                v40 = v36[36];
                max.x = v39;
                v41 = v36[37];
                max.y = v40;
                max.z = v41;
                TransformAABB((UFG::qMatrix44 *)&v9[20], &min, &max);
                if ( *(float *)&v23[1].mNode.mParent <= max.x
                  && *((float *)v23[1].mNode.mChild + 1) >= min.x
                  && *((float *)&v23[1].mNode.mParent + 1) <= max.y
                  && *(float *)&v23[1].mNode.mChild[1] >= min.y
                  && *(float *)v23[1].mNode.mChild <= max.z
                  && *((float *)&v23[1].mNode.mChild[1] + 1) >= min.z )
                {
                  UFG::SimObject::Suspend(v33);
                  UFG::qSafePointer<Creature,Creature>::operator=(
                    (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v1->mDisabledVehicle,
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
  NISManager *v1; // rbx
  UFG::SimObject *v2; // rcx
  UFG::BaseAnimationComponent *v3; // rax
  UFG::PedSpawnManager *v4; // rax
  unsigned int v5; // ecx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::CopSystem *v8; // rax
  UFG::SimObject *v9; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax

  v1 = this;
  v2 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v2 )
  {
    v3 = (UFG::BaseAnimationComponent *)UFG::SimObject::GetComponentOfType(v2, UFG::CameraAnimationComponent::_TypeUID);
    if ( v3 )
      UFG::BaseAnimationComponent::SetUpdateFromNIS(v3, 0);
  }
  UFG::StreamedResourceComponent::sAssetLoadDistance = UFG::StreamedResourceComponent::sDefaultAssetLoadDistance;
  Render::SetVSyncEnable(VSYNC_DEFAULT);
  v4 = UFG::PedSpawnManager::GetInstance();
  UFG::PedSpawnManager::SetupSocialForNIS(v4, 0);
  v5 = v1->mLightLayerUID;
  if ( v5 != -1 )
    Render::EnableLightLayer(v5, 1);
  UFG::TimeOfDayManager::GetInstance()->mGlobalIlluminationBlend = 1.0;
  v6 = `UFG::qGetResourceInventory<UFG::NISSpatialData>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::NISSpatialData>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x59362AA3u);
    `UFG::qGetResourceInventory<UFG::NISSpatialData>'::`2'::result = v6;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSpatialDataHandle.mPrev, v6);
  if ( v1->mpDynamicOutline )
  {
    ((void (*)(void))UFG::NavManager::ms_pInstance->vfptr->RemoveDynamicOutline)();
    v1->mpDynamicOutline = 0i64;
  }
  v8 = UFG::CopSystem::Instance();
  v8->vfptr[4].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v8->vfptr, v1->mWasCopSystemEnabled);
  v9 = v1->mDisabledVehicle.m_pPointer;
  if ( v9 )
    UFG::SimObject::Restore(v9);
  v10 = &v1->mDisabledVehicle;
  if ( v1->mDisabledVehicle.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->mDisabledVehicle.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->mDisabledVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mDisabledVehicle.mPrev;
  }
  v1->mDisabledVehicle.m_pPointer = 0i64;
}

// File Line: 644
// RVA: 0x3E3B60
char __fastcall NISManager::PlayInternal(NISManager *this, NISInstance *pInstance)
{
  UFG::SimComponent *v2; // rdi
  NISManager *v3; // rbx
  NISNode *v5; // rsi

  v2 = (UFG::SimComponent *)pInstance;
  v3 = this;
  if ( !gNISesEnabled || !pInstance || pInstance->mStatus == eSTATUS_INVALID )
    return 0;
  v5 = pInstance->mpNISNode;
  if ( !v5 )
    return 0;
  if ( this->mpActiveInstance.m_pPointer )
    NISManager::StopActiveNIS(this);
  UFG::qSafePointer<Creature,Creature>::operator=((UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)v3, v2);
  NISManager::PreventGameStateChanges(v3);
  if ( NISInstance::IsLoaded(v3->mpActiveInstance.m_pPointer) && v5->mSeamlessIn )
  {
    v3->mfStateTimeoutS = 3.4028235e38;
    v3->mState = 2;
    v3->mfStateTimeoutS = gInstanceLoadTimeoutS;
    NISManager::EnterStateLoadingInstance(v3);
  }
  else
  {
    v3->mState = 1;
    v3->mfStateTimeoutS = 3.4028235e38;
    NISManager::EnterStateIntroCurtains(v3);
  }
  v3->mbAudioStopped = 0;
  return 1;
}

// File Line: 718
// RVA: 0x3E3C40
void __fastcall NISManager::PlayNIS(NISManager *this)
{
  NISManager *v1; // rsi
  NISNode *v2; // r14
  unsigned int v3; // ebx
  int v4; // ebp
  NISActorNode *v5; // rdi
  UFG::SimObjectCVBase *v6; // rax
  unsigned __int16 v7; // dx
  UFG::CharacterAnimationComponent *v8; // rax
  Creature *v9; // rcx
  signed __int64 v10; // rax
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  NISInstance *v23; // r8
  UFG::qSafePointer<NISInstance,NISInstance> *v24; // rdx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v25; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v26; // rax
  signed __int64 v27; // rcx
  unsigned int v28; // ebx
  UFG::UIHKTextOverlay *v29; // rax
  UFG::qMatrix44 root; // [rsp+20h] [rbp-48h]

  v1 = this;
  UFG::VehicleAudioComponent::KillOffensiveSoundsForNIS();
  v2 = v1->mpActiveInstance.m_pPointer->mpNISNode;
  v3 = 0;
  v4 = (__int64)v2->vfptr[1].GetClassname((Expression::IMemberMap *)&v2->vfptr);
  if ( v4 > 0 )
  {
    do
    {
      v5 = (NISActorNode *)((__int64 (__fastcall *)(NISNode *, _QWORD))v2->vfptr[1].Serialize)(v2, v3);
      NISActorNode::Play(v5);
      NISActorNode::Update(v5, 0.0);
      if ( v1->mpActiveInstance.m_pPointer->mPlayRelativeToNISSceneRoot )
      {
        v6 = (UFG::SimObjectCVBase *)UFG::Simulation::GetSimObject(&UFG::gSim, &v5->mActorID);
        if ( v6 )
        {
          v7 = v6->m_Flags;
          if ( (v7 >> 14) & 1 )
          {
            v8 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v6);
          }
          else if ( (v7 & 0x8000u) == 0 )
          {
            if ( (v7 >> 13) & 1 )
              v8 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v6);
            else
              v8 = (UFG::CharacterAnimationComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v6->vfptr,
                                                                           UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
          }
          else
          {
            v8 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v6);
          }
          if ( v8 )
          {
            v9 = v8->mCreature;
            if ( v9 )
            {
              v10 = (signed __int64)&v1->mpActiveInstance.m_pPointer->mNISSceneRoot;
              v11 = v1->mpActiveInstance.m_pPointer->mNISSceneRoot.v0.z;
              v12 = v1->mpActiveInstance.m_pPointer->mNISSceneRoot.v0.w;
              v13 = *(float *)v10;
              root.v0.y = v1->mpActiveInstance.m_pPointer->mNISSceneRoot.v0.y;
              root.v0.z = v11;
              root.v0.x = v13;
              root.v0.w = v12;
              v14 = *(float *)(v10 + 20);
              v15 = *(float *)(v10 + 24);
              v16 = *(float *)(v10 + 28);
              root.v1.x = *(float *)(v10 + 16);
              root.v1.y = v14;
              root.v1.z = v15;
              root.v1.w = v16;
              v17 = *(float *)(v10 + 40);
              v18 = *(float *)(v10 + 44);
              v19 = *(float *)(v10 + 32);
              root.v2.y = *(float *)(v10 + 36);
              root.v2.x = v19;
              root.v2.z = v17;
              root.v2.w = v18;
              v20 = *(float *)(v10 + 56);
              v21 = *(float *)(v10 + 60);
              v22 = *(float *)(v10 + 48);
              root.v3.y = *(float *)(v10 + 52);
              root.v3.z = v20;
              root.v3.x = v22;
              root.v3.w = v21;
              Creature::SetAbsoluteRelativeRoot(v9, &root);
            }
          }
        }
      }
      ++v3;
    }
    while ( (signed int)v3 < v4 );
  }
  NISManager::SetPlayTime(v1, 0.0, 0);
  v23 = v1->mpActiveInstance.m_pPointer;
  v1->mAudioTime = 0.0;
  if ( v23->mStatus == 3 )
  {
    v24 = &NISManager::sInstance->mpPreloadInstance;
    if ( NISManager::sInstance->mpPreloadInstance.m_pPointer )
    {
      v25 = v24->mPrev;
      v26 = NISManager::sInstance->mpPreloadInstance.mNext;
      v25->mNext = v26;
      v26->mPrev = v25;
      v24->mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v24->mPrev;
      v24->mNext = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v24->mPrev;
    }
    v24->m_pPointer = 0i64;
  }
  v23->mStatus = 5;
  v27 = (signed __int64)&v1->mInstances.mNode.mNext[-2].mNext;
  if ( (UFG::qSafePointer<NISInstance,NISInstance> *)v27 != &v1->mpPreloadInstance )
  {
    while ( *(_DWORD *)(v27 + 40) != 2 )
    {
      v27 = *(_QWORD *)(v27 + 32) - 24i64;
      if ( (UFG::qSafePointer<NISInstance,NISInstance> *)v27 == &v1->mpPreloadInstance )
        goto LABEL_26;
    }
    NISInstance::Preload((NISInstance *)v27);
  }
LABEL_26:
  v28 = v2->m_audioTagUID[1];
  if ( v1->mbCurtainsShown )
  {
    v1->mbCurtainsShown = 0;
    UFG::UIHK_NISOverlay::getInstance();
    UFG::UIHK_NISOverlay::SetPostNISHideCurtainsAudioEvent(v28, 0);
    UFG::UIHK_NISOverlay::HideCurtains(0.0, 0);
  }
  else if ( v28 )
  {
    UFG::UIHK_NISOverlay::getInstance();
    UFG::UIHK_NISOverlay::SetPostNISHideCurtainsAudioEvent(v28, 0);
  }
  if ( !v1->mUIHelpbarLocked )
  {
    v1->mUIHelpbarLocked = 1;
    UFG::UIHKHelpBarWidget::Lock();
  }
  if ( UFG::UIHKTextOverlay::getInstance() )
  {
    v29 = UFG::UIHKTextOverlay::getInstance();
    UFG::UIHKTextOverlay::StopAllSubtitles(v29, 1);
  }
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_NIS_START_5,
    0xFFFFFFFF);
}

// File Line: 839
// RVA: 0x3E60D0
void __fastcall NISManager::StopNIS(NISManager *this)
{
  NISInstance *v1; // rbx
  NISNode *v2; // rbp
  NISManager *v3; // rdi
  NISNode *v4; // rbx
  unsigned int v5; // esi
  int v6; // er14
  NISActorNode *v7; // rax
  NISInstance *v8; // rax
  unsigned int v9; // ebx
  UFG::TiDo *v10; // rax
  UFG::UIHKTextOverlay *v11; // rax

  v1 = this->mpActiveInstance.m_pPointer;
  v2 = 0i64;
  v3 = this;
  if ( v1 )
    v4 = v1->mpNISNode;
  else
    v4 = 0i64;
  if ( v4 )
  {
    v5 = 0;
    v6 = (__int64)v4->vfptr[1].GetClassname((Expression::IMemberMap *)&v4->vfptr);
    if ( v6 > 0 )
    {
      do
      {
        v7 = (NISActorNode *)((__int64 (__fastcall *)(NISNode *, _QWORD))v4->vfptr[1].Serialize)(v4, v5);
        NISActorNode::nodeCleanup(v7);
        ++v5;
      }
      while ( (signed int)v5 < v6 );
    }
  }
  if ( v3->mUIHelpbarLocked )
  {
    v3->mUIHelpbarLocked = 0;
    UFG::UIHKHelpBarWidget::Unlock();
  }
  if ( v3->mbAudioStopped != 1 )
  {
    v8 = v3->mpActiveInstance.m_pPointer;
    v3->mbAudioStopped = 1;
    if ( v8 )
      v2 = v8->mpNISNode;
    if ( v2 )
    {
      v9 = v2->m_audioTagUID[3];
      UFG::UIHK_NISOverlay::getInstance();
      UFG::UIHK_NISOverlay::SetPostNISHideCurtainsAudioEvent(v9, 0);
      if ( UFG::TiDo::GetInstance() )
      {
        v10 = UFG::TiDo::GetInstance();
        v10->vfptr->SetNISMode(v10, 0);
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
  NISManager::eStateEnum v2; // eax
  NISManager *v3; // rbx

  v2 = this->mState;
  v3 = this;
  if ( v2 == STATE_INVALID )
    goto LABEL_11;
  if ( !this->mpActiveInstance.m_pPointer )
  {
    NISManager::AllowGameStateChanges(this);
    NISManager::StopNIS(v3);
    NISManager::ResetNISSettings(v3);
    NISManager::Reset(v3);
LABEL_11:
    UFG::RenderWorld::msIsNisPlaying = v3->mState != 0;
    return;
  }
  switch ( v2 )
  {
    case 1:
      NISManager::UpdateStateIntroCurtains(this, timeDelta);
      UFG::RenderWorld::msIsNisPlaying = v3->mState != 0;
      break;
    case 2:
      NISManager::UpdateStateLoadingInstance(this, timeDelta);
      UFG::RenderWorld::msIsNisPlaying = v3->mState != 0;
      break;
    case 3:
      NISManager::UpdateStateSetupLocation(this, timeDelta);
      UFG::RenderWorld::msIsNisPlaying = v3->mState != 0;
      break;
    case 4:
      NISManager::UpdateStateAction(this, timeDelta);
      UFG::RenderWorld::msIsNisPlaying = v3->mState != 0;
      break;
    case 5:
      NISManager::UpdateStateOutroCurtains(this, timeDelta);
      UFG::RenderWorld::msIsNisPlaying = v3->mState != 0;
      break;
    case 6:
      NISManager::UpdateStateUnloadingInstance(this, timeDelta);
      UFG::RenderWorld::msIsNisPlaying = v3->mState != 0;
      break;
    default:
      goto LABEL_11;
  }
}

// File Line: 989
// RVA: 0x3E7950
void __fastcall NISManager::UpdateTransforms(NISManager *this, float timeDelta)
{
  NISNode *v2; // rdi
  unsigned int v3; // ebx
  int v4; // esi
  NISActorNode *v5; // rax

  if ( this->mState == 4 )
  {
    v2 = this->mpActiveInstance.m_pPointer->mpNISNode;
    if ( v2 )
    {
      v3 = 0;
      v4 = (__int64)v2->vfptr[1].GetClassname((Expression::IMemberMap *)&v2->vfptr);
      if ( v4 > 0 )
      {
        do
        {
          v5 = (NISActorNode *)((__int64 (__fastcall *)(NISNode *, _QWORD))v2->vfptr[1].Serialize)(v2, v3);
          NISActorNode::UpdateTransforms(v5, timeDelta);
          ++v3;
        }
        while ( (signed int)v3 < v4 );
      }
    }
  }
}

// File Line: 1016
// RVA: 0x3E6070
void __fastcall NISManager::StopActiveNIS(NISManager *this)
{
  NISManager *v1; // rbx

  v1 = this;
  if ( this->mState )
  {
    this->mState = 6;
    this->mfStateTimeoutS = 3.4028235e38;
    NISManager::EnterStateUnloadingInstance(this);
    NISManager::Update(v1, 0.0);
  }
  else
  {
    NISManager::AllowGameStateChanges(this);
    NISManager::StopNIS(v1);
    NISManager::ResetNISSettings(v1);
    NISManager::Reset(v1);
  }
}

// File Line: 1066
// RVA: 0x3E2D20
void __fastcall NISManager::HideHUD(NISManager *this)
{
  NISManager *v1; // rbx

  v1 = this;
  if ( this->mHudDisableCount )
  {
    ++this->mHudDisableCount;
  }
  else
  {
    UFG::UIHK_NISOverlay::ShowLetterBox();
    ++v1->mHudDisableCount;
  }
}

// File Line: 1086
// RVA: 0x3E29F0
void __fastcall NISManager::EnterStateIntroCurtains(NISManager *this)
{
  NISManager *v1; // rbx
  unsigned int v2; // edi
  float v3; // xmm6_4
  UFG::UI *v4; // rcx
  ANTLR3_INPUT_STREAM_struct *v5; // rax

  v1 = this;
  UFG::UI::LockGameplayInput((UFG::UI *)this);
  v2 = v1->mpActiveInstance.m_pPointer->mpNISNode->m_audioTagUID[0];
  if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_1 )
    v3 = FLOAT_0_33000001;
  else
    v3 = 0.0;
  v1->mbCurtainsShown = 1;
  if ( v2 )
    UFG::NISAudio::PlayNISCurtainEvent(UFG::NISAudio::m_instance, v2);
  UFG::UIHK_NISOverlay::ShowCurtains(v3, 0);
  NISInstance::Preload(v1->mpActiveInstance.m_pPointer);
  v1->mbUpdatedOnce = 0;
  if ( (unsigned __int8)UFG::UI::IsGamePaused() )
  {
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xFFFFFFFF);
    UFG::UI::UnpauseGame(v4);
  }
  v1->mbUserInputDisabled = 1;
  v5 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::SetGameState(v5, 4u);
}

// File Line: 1108
// RVA: 0x3E71B0
void __fastcall NISManager::UpdateStateIntroCurtains(NISManager *this, float timeDelta)
{
  NISManager *v2; // rbx

  v2 = this;
  if ( this->mbUpdatedOnce )
  {
    if ( UFG::UIHK_NISOverlay::IsCurtainStable() )
    {
      v2->mfStateTimeoutS = 3.4028235e38;
      v2->mState = 2;
      v2->mfStateTimeoutS = gInstanceLoadTimeoutS;
      NISManager::EnterStateLoadingInstance(v2);
    }
    v2->mbUpdatedOnce = 1;
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
  NISManager *v1; // rbx
  ANTLR3_INPUT_STREAM_struct *v2; // rax
  UFG::ObjectResourceManager *v3; // rax
  UFG::UI *v4; // rcx

  v1 = this;
  NISManager::SetupNISSettingsPreStreamed(this);
  if ( !NISInstance::IsLoaded(v1->mpActiveInstance.m_pPointer) )
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
  NISInstance::LoadAllResources(v1->mpActiveInstance.m_pPointer);
  if ( v1->mbUserInputDisabled )
    UFG::UI::UnlockGameplayInput(v4);
}

// File Line: 1154
// RVA: 0x3E7210
void __fastcall NISManager::UpdateStateLoadingInstance(NISManager *this, float timeDelta)
{
  NISManager *v2; // rbx
  char v3; // di
  hkgpIndexedMeshDefinitions::Edge *v4; // rdx
  AnimationGroup *v5; // rcx
  NISInstance *v6; // rax
  AnimationGroup *v7; // rcx
  NISInstance *v8; // rax
  AnimationGroup *v9; // rcx

  v2 = this;
  NISInstance::UpdateActorResources(this->mpActiveInstance.m_pPointer, timeDelta);
  if ( NISInstance::IsLoaded(v2->mpActiveInstance.m_pPointer)
    && (unsigned __int8)NISInstance::AreActorsReady(v2->mpActiveInstance.m_pPointer) )
  {
    goto LABEL_26;
  }
  v3 = 0;
  if ( v2->mfStateTimeoutS <= 0.0 )
  {
    if ( NISInstance::AreAnimationsLoaded(v2->mpActiveInstance.m_pPointer)
      && NISInstance::IsAudioResourceLoaded(v2->mpActiveInstance.m_pPointer, v4) )
    {
      NISInstance::AreAllActorsLoaded(v2->mpActiveInstance.m_pPointer);
      NISInstance::IsLightGroupLoaded(v2->mpActiveInstance.m_pPointer);
      v3 = 1;
    }
    else
    {
      v5 = v2->mpActiveInstance.m_pPointer->mAnimationGroupHandle.m_AnimationGroup.m_pPointer;
      if ( v5 )
        AnimationGroup::IsStreamedIn(v5);
      v6 = v2->mpActiveInstance.m_pPointer;
      if ( v6->mFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1 )
      {
        v7 = v6->mFacialAnimGroupHandle.m_AnimationGroup.m_pPointer;
        if ( v7 )
          AnimationGroup::IsStreamedIn(v7);
      }
      v8 = v2->mpActiveInstance.m_pPointer;
      if ( v8->mExtraFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1 )
      {
        v9 = v8->mExtraFacialAnimGroupHandle.m_AnimationGroup.m_pPointer;
        if ( v9 )
          AnimationGroup::IsStreamedIn(v9);
      }
      NISInstance::IsAudioResourceLoaded(v2->mpActiveInstance.m_pPointer, v4);
      v2->mState = 6;
      v2->mfStateTimeoutS = 3.4028235e38;
      NISManager::EnterStateUnloadingInstance(v2);
    }
  }
  v2->mfStateTimeoutS = v2->mfStateTimeoutS - timeDelta;
  if ( v3 )
  {
LABEL_26:
    if ( v2->mpActiveInstance.m_pPointer->mpNISNode->mSeamlessIn )
    {
      if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateInGame_1 )
        UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateInGame_1);
      v2->mState = 4;
      v2->mfStateTimeoutS = 3.4028235e38;
      NISManager::EnterStateAction(v2);
    }
    else
    {
      if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateLoadNIS_1 )
        UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateLoadNIS_1);
      v2->mState = 3;
      v2->mfStateTimeoutS = 3.4028235e38;
      NISManager::EnterStateSetupLocation(v2);
    }
  }
}

// File Line: 1238
// RVA: 0x3E2B90
void __fastcall NISManager::EnterStateSetupLocation(NISManager *this)
{
  NISManager *v1; // rdi
  NISNode *v2; // rbx
  ITrack *v3; // rdx
  UFG::ProgressionTracker *v4; // rax

  v1 = this;
  v2 = this->mpActiveInstance.m_pPointer->mpNISNode;
  ActionController::Stop(&this->mActionController);
  ActionController::Play(&v1->mActionController, (ActionNodePlayable *)&v2->vfptr);
  v3 = (ITrack *)&v2->mPrimaryCameraAnimationTrack->vfptr;
  if ( v3 )
  {
    ActionController::PlayTracks(&v1->mActionController, v3, 0, 0.0);
    ActionController::Update(&v1->mActionController, 0.0);
  }
  NISManager::SetPlayTime(v1, 0.0, 0);
  v4 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::SetResourceFreezeMode(v4, 0);
  v1->mbStreamingComplete = 0;
}

// File Line: 1276
// RVA: 0x3E73F0
void __fastcall NISManager::UpdateStateSetupLocation(NISManager *this, float timeDelta)
{
  NISManager *v2; // rbx

  v2 = this;
  if ( this->mbStreamingComplete )
  {
    if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) != uidGameStateInGame_1 )
      UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateInGame_1);
    v2->mState = 4;
    v2->mfStateTimeoutS = 3.4028235e38;
    NISManager::EnterStateAction(v2);
  }
}

// File Line: 1290
// RVA: 0x3E28F0
void __fastcall NISManager::EnterStateAction(NISManager *this)
{
  NISManager *v1; // rdi
  NISNode *v2; // rsi
  float v3; // xmm6_4
  __int64 v4; // rax
  TrackGroup *v5; // rdx

  v1 = this;
  v2 = this->mpActiveInstance.m_pPointer->mpNISNode;
  if ( v2->mFadeInDuration > 0.0 )
  {
    this->mbCurtainsShown = 1;
    UFG::UIHK_NISOverlay::ShowCurtains(0.0, 0);
    v3 = v2->mFadeInDuration;
    v1->mbCurtainsShown = 0;
    UFG::UIHK_NISOverlay::getInstance();
    UFG::UIHK_NISOverlay::SetPostNISHideCurtainsAudioEvent(0, 0);
    UFG::UIHK_NISOverlay::HideCurtains(v3, 0);
    v1->mbCurtainsShown = 0;
  }
  if ( !v1->mbCameraAttached )
  {
    ActionController::Stop(&v1->mActionController);
    ActionController::Play(&v1->mActionController, (ActionNodePlayable *)&v2->vfptr);
  }
  v4 = v2->mTracksAction.mOffset;
  if ( v4 )
    v5 = (TrackGroup *)((char *)&v2->mTracksAction + v4);
  else
    v5 = 0i64;
  ActionController::PlayTracks(&v1->mActionController, v5, 0, 0.0);
  NISLightGroup::Play(v2->mLightGroupObject);
  ActionController::Update(&v1->mActionController, 0.0);
  NISManager::SetupNISSettingsPostStreamed(v1);
  NISManager::PlayNIS(v1);
}

// File Line: 1335
// RVA: 0x3E6CE0
void __fastcall NISManager::UpdateStateAction(NISManager *this, float timeDelta)
{
  NISManager *v2; // rdi
  NISNode *v3; // rsi
  float v4; // xmm6_4
  NISManager *v5; // rax
  AudioTaskNIS *v6; // rdx
  UFG::qNode<NISInstance,NISInstanceMasterList> *v7; // rax
  float v8; // xmm0_4
  unsigned int v9; // ebx
  int v10; // ebp
  NISActorNode *v11; // rax
  float v12; // xmm7_4
  NISManager *v13; // rax
  AudioTaskNIS *v14; // rbx
  UFG::qNode<NISInstance,NISInstanceMasterList> *v15; // rcx
  float v16; // xmm0_4
  float v17; // xmm2_4
  UFG::AudioEvent *v18; // rcx
  float v19; // xmm0_4
  float v20; // xmm7_4
  float v21; // xmm2_4
  unsigned int v22; // edx
  char v23; // bl
  float v24; // xmm0_4
  UFG::GameStatTracker *v25; // rax
  UFG::PersistentData::MapBool *v26; // r14
  const char *v27; // rdx
  UFG::OSuiteDBLogger *v28; // rbp
  int v29; // ebx
  int v30; // ebx
  int v31; // er8
  UFG::GameStatTracker *v32; // rax
  UFG::GameStat::Int32Stat v33; // edx
  bool v34; // zf
  char dest; // [rsp+20h] [rbp-C8h]
  UFG::qSymbol result; // [rsp+F0h] [rbp+8h]

  v2 = this;
  v3 = this->mpActiveInstance.m_pPointer->mpNISNode;
  v4 = timeDelta;
  if ( !v3 || (unsigned __int8)UFG::MovieHandler::IsPlayingNonInMemMovies(&UFG::TheMovieHandler) )
  {
    if ( (unsigned __int8)UFG::MovieHandler::IsPlayingNonInMemMovies(&UFG::TheMovieHandler)
      && !v3->mPrimaryCameraAnimationTrack )
    {
      if ( !v2->mbCameraAttached && 0.0 == v2->mTime )
        v2->mLength = UFG::MovieHandler::GetNonInMemMovieLength(&UFG::TheMovieHandler);
      if ( !v2->mPaused )
        v2->mTime = timeDelta + v2->mTime;
    }
  }
  else
  {
    v5 = NISManager::GetAudioMasterTask(v2);
    v6 = (AudioTaskNIS *)v5;
    if ( gNISSyncWithAudio )
    {
      if ( v5 )
      {
        v7 = v5->mInstances.mNode.mPrev[20].mPrev;
        if ( v7 )
        {
          if ( (LOBYTE(v7[9].mPrev) >> 6) & 1 )
          {
            v8 = AudioTaskNIS::GetElapsedTime(v6) * 0.001;
            v4 = v8 - v2->mAudioTime;
            if ( v4 >= 0.0 )
              v2->mAudioTime = v8;
            else
              v4 = 0.0;
          }
        }
      }
    }
    if ( !v2->mPaused )
    {
      ActionController::Update(&v2->mActionController, v4);
      v9 = 0;
      v10 = (__int64)v3->vfptr[1].GetClassname((Expression::IMemberMap *)&v3->vfptr);
      if ( v10 > 0 )
      {
        do
        {
          v11 = (NISActorNode *)((__int64 (__fastcall *)(NISNode *, _QWORD))v3->vfptr[1].Serialize)(v3, v9);
          NISActorNode::Update(v11, v4);
          ++v9;
        }
        while ( (signed int)v9 < v10 );
      }
    }
    v12 = v2->mActionController.m_ActionNodePlayTime;
    v13 = NISManager::GetAudioMasterTask(v2);
    v14 = (AudioTaskNIS *)v13;
    if ( v13 )
    {
      v15 = v13->mInstances.mNode.mPrev[20].mPrev;
      if ( v15 )
      {
        if ( (LOBYTE(v15[9].mPrev) >> 6) & 1 )
        {
          v16 = UFG::AudioEvent::GetElapsedTime((UFG::AudioEvent *)v15);
          if ( v16 > 0.0 )
          {
            v14->m_lastElapsedTime = v16;
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
    NISManager::UpdateActionDebugDisplay(v2, v12, v17);
    if ( !v2->mPaused && v2->mActionController.m_currentNode )
    {
      if ( gNISSyncWithAudio
        && v14
        && (v18 = v14->m_nisAudio->m_controller.m_pEvent) != 0i64
        && (*((_BYTE *)v18 + 144) >> 6) & 1 )
      {
        v19 = AudioTaskNIS::GetElapsedTime(v14) * 0.001;
        NISManager::SetPlayTime(v2, v19, 0);
      }
      else
      {
        NISManager::SetPlayTime(v2, v12, 0);
      }
    }
  }
  v20 = v3->mFadeOutDuration;
  if ( !v2->mbCurtainsShown && v20 > 0.0 )
  {
    v21 = v2->mTime;
    if ( v21 >= (float)(v2->mLength - v20) )
    {
      if ( v20 >= (float)(v2->mLength - v21) )
        v20 = v2->mLength - v21;
      v22 = v2->mpActiveInstance.m_pPointer->mpNISNode->m_audioTagUID[2];
      v2->mbCurtainsShown = 1;
      if ( v22 )
        UFG::NISAudio::PlayNISCurtainEvent(UFG::NISAudio::m_instance, v22);
      UFG::UIHK_NISOverlay::ShowCurtains(v20, 0);
    }
  }
  v23 = 0;
  if ( v2->mEndCondition )
  {
    v24 = v2->mTimeToEndAt - v4;
    v2->mTimeToEndAt = v24;
    if ( v24 <= 0.0 )
    {
      v23 = 1;
      if ( v3->mSeamlessOut )
        NISManager::SetPlayTime(v2, v2->mLength, 0);
    }
  }
  if ( !v2->mActionController.m_currentNode || v3->mPrimaryCameraAnimationTrack && !v2->mbCameraAttached || v23 )
  {
    ActionController::Stop(&v2->mActionController);
    v25 = UFG::GameStatTracker::Instance();
    v26 = UFG::GameStatTracker::GetMapBool(v25, WatchedNISBoolList);
    if ( v3->mNISName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
      v27 = (char *)&v3->mNISName + (v3->mNISName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    else
      v27 = BinString::sEmptyString;
    UFG::qSymbol::create_from_string(&result, v27);
    if ( v2->mEndCondition == 2 )
    {
      v28 = UFG::OSuiteDBLogger::Instance();
      if ( UFG::OSuiteDBLogger::CreateMetric(v28, "CutScene") )
      {
        v29 = result.mUID;
        UFG::qSPrintf(&dest, 128, "i32_%s", "CutsceneID");
        OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v29);
        v30 = (signed int)v2->mTime;
        UFG::qSPrintf(&dest, 128, "i32_%s", "AmountShown");
        OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v30);
        if ( UFG::PersistentData::MapBool::GetStatus(v26, &result) )
        {
          UFG::qSPrintf(&dest, 128, "i32_%s", "IsFirstTimeShown");
          v31 = 0;
        }
        else
        {
          UFG::qSPrintf(&dest, 128, "i32_%s", "IsFirstTimeShown");
          v31 = 1;
        }
        OSuite::ZMetric::SetProperty(v28->m_pMetric, &dest, v31);
        UFG::OSuiteDBLogger::SubmitMetric(v28, 0);
      }
      v32 = UFG::GameStatTracker::Instance();
      v33 = 15;
    }
    else
    {
      v32 = UFG::GameStatTracker::Instance();
      v33 = 14;
    }
    UFG::GameStatTracker::ApplyDelta(v32, v33, 1);
    if ( !UFG::PersistentData::MapBool::GetStatus(v26, &result) )
      UFG::PersistentData::MapBool::SetStatus(v26, &result, 1);
    v2->mEndCondition = 1;
    v34 = v3->mSeamlessOut == 0;
    v2->mfStateTimeoutS = 3.4028235e38;
    if ( v34 )
    {
      v2->mState = 5;
      NISManager::EnterStateOutroCurtains(v2);
    }
    else
    {
      v2->mState = 6;
      NISManager::EnterStateUnloadingInstance(v2);
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
  NISManager *v2; // rbx

  v2 = this;
  if ( UFG::UIHK_NISOverlay::IsCurtainStable() )
  {
    v2->mState = 6;
    v2->mfStateTimeoutS = 3.4028235e38;
    NISManager::EnterStateUnloadingInstance(v2);
  }
}

// File Line: 1529
// RVA: 0x3E2C20
void __fastcall NISManager::EnterStateUnloadingInstance(NISManager *this)
{
  NISManager *v1; // rbx
  UFG::ObjectResourceManager *v2; // rax

  v1 = this;
  NISInstance::Unload(this->mpActiveInstance.m_pPointer, 0);
  v2 = UFG::ObjectResourceManager::Instance();
  UFG::ObjectResourceManager::SetFragmentationReservePercentage(v2, 0.15000001);
  NISManager::StopNIS(v1);
  NISManager::ResetNISSettings(v1);
}

// File Line: 1543
// RVA: 0x3E7450
void __fastcall NISManager::UpdateStateUnloadingInstance(NISManager *this, float timeDelta)
{
  NISManager *v2; // rdi
  NISNode *v3; // rcx
  UFG::ProgressionTracker *v4; // rax
  UFG::ProgressionTracker *v5; // rax
  UFG::TimeOfDayManager *v6; // rax
  UFG::TimeOfDayManager *v7; // rbx
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  UFG::PedSpawnManager *v12; // rax

  v2 = this;
  v3 = this->mpActiveInstance.m_pPointer->mpNISNode;
  if ( !v3 )
    goto LABEL_30;
  if ( !v3->mSeamlessOut )
  {
    v4 = UFG::ProgressionTracker::Instance();
    UFG::ProgressionTracker::SetResourceFreezeMode(v4, 1);
    if ( !v2->mpActiveInstance.m_pPointer->mbIntermediateNIS )
    {
      v5 = UFG::ProgressionTracker::Instance();
      UFG::ProgressionTracker::ApplySceneSettings(v5, &v2->mPostNisSettings);
    }
    goto LABEL_30;
  }
  v6 = UFG::TimeOfDayManager::GetInstance();
  v7 = v6;
  if ( v2->mPostNisSettings.mResetEnvironmentOverride )
    UFG::TimeOfDayManager::SetOverrideEnvironmentSettings(v6, 0, 0.0);
  v8 = v2->mPostNisSettings.mTimeOverrideInSeconds;
  if ( v8 >= 0.0 )
    UFG::TimeOfDayManager::SetTime(v7, v8, 0);
  if ( v2->mPostNisSettings.mTimeOverrideLockSet )
  {
    if ( v2->mPostNisSettings.mTimeOverrideLock )
      v9 = 0.0;
    else
      v9 = FLOAT_40_0;
    TimePlotPoint::SetTimeValue(v7, v9);
  }
  v10 = v2->mPostNisSettings.mWeatherOverrideIntensity;
  if ( v10 >= 0.0 )
  {
    if ( v10 <= 0.0 )
    {
      v10 = 0.0;
    }
    else
    {
      v11 = FLOAT_2_0;
      if ( v10 >= 2.0 )
        goto LABEL_20;
    }
    v11 = v10;
LABEL_20:
    v7->m_WeatherState = v11;
    v7->m_WeatherTarget = v11;
    v7->m_NextWeatherTarget = v11;
  }
  if ( v2->mPostNisSettings.mWeatherOverrideLockSet )
    UFG::TimeOfDayManager::LockWeather(v7, v2->mPostNisSettings.mWeatherOverrideLock);
  if ( v2->mPostNisSettings.mWeatherOverrideWetness >= 0.0 )
    UFG::TimeOfDayManager::SetSurfaceWetnessOverride(v7, -1.0, "NISManager::UpdateStateUnloadingInstance");
  if ( v2->mPostNisSettings.mResetAmbientPeds )
  {
    UFG::PedSpawnManager::SetAmbientSpawningEnable(v2->mPostNisSettings.mEnableAmbientPedsOnEnd);
    v12 = UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::RestoreAllScriptedToFullyActive(v12);
    UFG::PedSpawnManager::SetScriptedStatusCheckEnable(1);
  }
  if ( UFG::UIHK_NISOverlay::IsCurtainVisible() || !UFG::UIHK_NISOverlay::IsCurtainStable() )
  {
    v2->mbCurtainsShown = 1;
    UFG::UIHK_NISOverlay::ShowCurtains(0.0, 0);
    v2->mbCurtainsShown = 0;
    UFG::UIHK_NISOverlay::getInstance();
    UFG::UIHK_NISOverlay::SetPostNISHideCurtainsAudioEvent(0, 0);
    UFG::UIHK_NISOverlay::HideCurtains(1.0, 0);
  }
LABEL_30:
  NISManager::AllowGameStateChanges(v2);
  NISManager::StopNIS(v2);
  NISManager::ResetNISSettings(v2);
  NISManager::Reset(v2);
}

// File Line: 1607
// RVA: 0x3E6940
void __fastcall NISManager::UpdateActionDebugDisplay(NISManager *this, float sceneTime, float masterAudioSceneTime)
{
  NISInstance *v3; // rbx
  float v4; // xmm6_4
  Render::DebugDrawContext *v5; // rdi
  AnimationGroupHandle::ReferenceInfo *v6; // rax
  UFG::SimObject *v7; // rsi
  UFG::SimComponent *v8; // rbx
  bool v9; // zf
  const char *v10; // r8
  const char *v11; // rcx
  UFG::UIHK_NISOverlay *v12; // rbx
  char *v13; // rdx
  UFG::UIHK_NISFrameCounterWidget *v14; // rbx
  char buff; // [rsp+40h] [rbp-68h]
  char v16; // [rsp+60h] [rbp-48h]

  v3 = this->mpActiveInstance.m_pPointer;
  v4 = sceneTime;
  if ( v3 )
    v3 = (NISInstance *)v3->mpNISNode;
  if ( gNISDebugDisplay )
  {
    GetUnitsTime(sceneTime, &buff, 32, gNISTimeUnitsDisplay);
    v5 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
    if ( masterAudioSceneTime < 0.0 )
    {
      Render::DebugDrawContext::DrawTextA(v5, 100, 60, &UFG::qColour::Red, "SceneTime:%s::AudioTime:NONE", &buff);
    }
    else
    {
      v4 = masterAudioSceneTime;
      GetUnitsTime(masterAudioSceneTime, &v16, 32, gNISTimeUnitsDisplay);
      Render::DebugDrawContext::DrawTextA(v5, 100, 60, &UFG::qColour::White, "SceneTime:%s::AudioTime:%s", &buff, &v16);
    }
    if ( v3 )
    {
      v6 = v3->mFacialAnimGroupHandle.m_pReferenceInfo;
      v7 = v6[1].m_pSimObject;
      if ( v7 )
      {
        v8 = UFG::SimObject::GetComponentOfType(v6[1].m_pSimObject, UFG::LightGroupComponent::_TypeUID);
        v9 = UFG::SimObject::GetComponentOfType(v7, UFG::LightGroupAnimationComponent::_TypeUID) == 0i64;
        v10 = "None";
        v11 = "None";
        if ( !v9 )
          v11 = "Active";
        if ( v8 )
          v10 = "Active";
        Render::DebugDrawContext::DrawTextA(
          v5,
          100,
          70,
          &UFG::qColour::White,
          "NISLight:LightGroup:%s::LightAnim:%s",
          v10,
          v11);
      }
      else
      {
        Render::DebugDrawContext::DrawTextA(v5, 100, 70, &UFG::qColour::Red, "NISLight:None");
      }
    }
    v12 = UFG::UIHK_NISOverlay::getInstance();
    if ( v12 )
    {
      if ( gNISSyncWithAudio )
      {
        GetUnitsTime(v4, &v16, 32, gNISTimeUnitsDisplay);
        v13 = &v16;
      }
      else
      {
        v13 = &buff;
      }
      v14 = &v12->FrameCounter;
      UFG::UIHK_NISFrameCounterWidget::SetCaption(v14, v13);
      UFG::UIHK_NISFrameCounterWidget::SetVisible(v14, 1);
    }
  }
}

// File Line: 1696
// RVA: 0x3E2110
bool __fastcall NISManager::CanSkipNow(NISManager *this)
{
  NISInstance *v1; // rax
  NISNode *v2; // rax
  bool result; // al

  v1 = this->mpActiveInstance.m_pPointer;
  result = 0;
  if ( v1 )
  {
    v2 = v1->mpNISNode;
    if ( v2 )
    {
      if ( v2->mCanSkip && this->mEndCondition == eNIS_Playing && v2->mTimeBeforeCanSkip <= this->mTime )
        result = 1;
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

  v1 = this->mState == 4;
  this->mEndCondition = 2;
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
  ActionNodePlayable **v1; // rdi
  NISManager *v2; // rbx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v3; // rcx

  v1 = &this->mActionController.m_SequenceNode;
  v2 = (NISManager *)&this->mActionController.m_RunningTasks.mNode.mNext[-1].mNext;
  if ( v2 == (NISManager *)&this->mActionController.m_SequenceNode )
    return 0i64;
  while ( 1 )
  {
    v3 = v2->mpPreloadInstance.mPrev;
    if ( v3 )
    {
      if ( AudioTrackNIS::sClassNameUID == ((unsigned int (*)(void))v3->mPrev[2].mNext)() )
        break;
    }
    v2 = (NISManager *)&v2->mpActiveInstance.m_pPointer[-1].mNISSceneRoot.v3.z;
    if ( v2 == (NISManager *)v1 )
      return 0i64;
  }
  return v2;
}

// File Line: 1775
// RVA: 0x3E51B0
void __fastcall NISManager::SetPlayTime(NISManager *this, float timeAbsolute, bool syncSceneTime)
{
  float v3; // xmm7_4
  NISManager *v4; // r15
  NISManager *v5; // rax
  NISManager *v6; // rbx
  signed int v7; // edi
  UFG::qNode<NISInstance,NISInstanceMasterList> *v8; // rcx
  NISNode *v9; // r14
  bool v10; // r13
  UFG::SimObject *v11; // rcx
  UFG::SimComponent *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rbx
  hkReferencedObject *v17; // rcx
  hkReferencedObject *v18; // rbx
  __int64 *v19; // rax
  signed int v20; // edi
  hkReferencedObject *v21; // rcx
  unsigned int *v22; // rsi
  signed int v23; // eax
  __m128 v24; // xmm4
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128i v27; // xmm6
  __m128 v28; // xmm2
  __m128 v29; // xmm3
  unsigned int v30; // er9
  unsigned int v31; // eax
  UFG::qResourceData *v32; // rax
  unsigned int v33; // er10
  unsigned int *v34; // rcx
  unsigned int v35; // edx
  unsigned int v36; // eax
  int v37; // er12
  unsigned int v38; // ebp
  UFG::qSymbol *v39; // rax
  UFG::qBaseNodeRB *v40; // rax
  UFG::SimComponent *v41; // rax
  signed __int64 v42; // rsi
  _QWORD *v43; // rbx
  signed __int64 i; // rdi
  hkReferencedObject *v45; // [rsp+A0h] [rbp+8h]
  int v46; // [rsp+A8h] [rbp+10h]
  float v47; // [rsp+B0h] [rbp+18h]
  hkReferencedObject *v48; // [rsp+B8h] [rbp+20h]

  v3 = timeAbsolute;
  v4 = this;
  v46 = 0;
  if ( syncSceneTime )
  {
    v5 = NISManager::GetAudioMasterTask(this);
    v6 = v5;
    if ( v5 )
    {
      v7 = (signed int)(float)(timeAbsolute * 1000.0);
      v8 = v5->mInstances.mNode.mPrev[20].mPrev;
      if ( v8 && (LOBYTE(v8[9].mPrev) >> 6) & 1 )
        ((void (__fastcall *)(UFG::qNode<NISInstance,NISInstanceMasterList> *, _QWORD))v8->mPrev[2].mNext)(
          v8,
          (unsigned int)v7);
      *(float *)&v6->mPaused = (float)v7 * 0.001;
      v4->mAudioTime = timeAbsolute;
    }
    TimePlotPoint::SetTimeValue((UFG::TimeOfDayManager *)&v4->mActionController, timeAbsolute);
  }
  v9 = v4->mpActiveInstance.m_pPointer->mpNISNode;
  v10 = 0;
  if ( !v4->mbCameraAttached )
    goto LABEL_41;
  if ( !v4->mSpatialDataHandle.mData )
    goto LABEL_41;
  v11 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( !v11 )
    goto LABEL_41;
  v12 = UFG::SimObject::GetComponentOfType(v11, UFG::AnimatedCameraComponent::_TypeUID);
  if ( !v12 )
    goto LABEL_41;
  v13 = v12[23].m_SafePointerList.mNode.mPrev[12].mPrev;
  v14 = v13[6].mNext;
  if ( v14 )
  {
    v14 = v14[6].mPrev;
    if ( v14 )
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
    v14 = v16[6].mPrev;
  }
  if ( !v14 )
    goto LABEL_21;
LABEL_18:
  v17 = (hkReferencedObject *)v14[1].mNext;
  if ( v17 )
    hkReferencedObject::addReference(v17);
  v18 = (hkReferencedObject *)v14[1].mNext;
  v48 = v18;
  v19 = (__int64 *)&v48;
  v20 = 1;
  v21 = v45;
LABEL_22:
  v46 = v20;
  v22 = (unsigned int *)*v19;
  if ( v20 & 2 )
  {
    v20 &= 0xFFFFFFFD;
    v46 = v20;
    if ( v21 )
      hkReferencedObject::removeReference(v21);
    v45 = 0i64;
  }
  if ( v20 & 1 )
  {
    if ( v18 )
      hkReferencedObject::removeReference(v18);
    v48 = 0i64;
  }
  v47 = timeAbsolute;
  v23 = (unsigned __int64)(*(__int64 (__fastcall **)(unsigned int *))(*(_QWORD *)v22 + 64i64))(v22) - 1;
  v24 = _mm_shuffle_ps((__m128)v22[5], (__m128)v22[5], 0);
  v25 = 0i64;
  v25.m128_f32[0] = (float)v23;
  v26 = _mm_rcp_ps(v24);
  v27 = (__m128i)_mm_and_ps(
                   _mm_cmpltps((__m128)0i64, v24),
                   _mm_mul_ps(
                     _mm_mul_ps(
                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v26, v24)), v26),
                       _mm_shuffle_ps((__m128)LODWORD(v47), (__m128)LODWORD(v47), 0)),
                     _mm_shuffle_ps(v25, v25, 0)));
  v28 = _mm_sub_ps(
          _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v27, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
          *(__m128 *)two23);
  v29 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v27, 1u), 1u));
  v30 = _mm_cvtsi128_si32(
          _mm_cvttps_epi32(
            _mm_or_ps(
              _mm_andnot_ps(v29, _mm_add_ps(_mm_cvtepi32_ps((__m128i)_mm_cmpltps((__m128)v27, v28)), v28)),
              _mm_and_ps(v29, (__m128)v27))));
  v31 = v23 - 1;
  if ( v30 > v31 )
    v30 = v31;
  v32 = v4->mSpatialDataHandle.mData;
  v33 = HIDWORD(v32[1].mResourceHandles.mNode.mPrev);
  v34 = (unsigned int *)v32[1].mResourceHandles.mNode.mNext;
  if ( v34 )
    v34 = (unsigned int *)((char *)v34 + (_QWORD)v32 + 128);
  v35 = 0;
  if ( v33 )
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
        if ( v35 < v33 )
          continue;
      }
      goto LABEL_41;
    }
    v10 = 1;
  }
LABEL_41:
  if ( gSprinDriverAdjust && v10 )
  {
    if ( v9 )
    {
      v37 = (__int64)v9->vfptr[1].GetClassname((Expression::IMemberMap *)&v9->vfptr);
      v38 = 0;
      if ( v37 > 0 )
      {
        do
        {
          v39 = (UFG::qSymbol *)((__int64 (__fastcall *)(NISNode *, _QWORD))v9->vfptr[1].Serialize)(v9, v38);
          if ( v39 )
          {
            v40 = UFG::Simulation::GetSimObject(&UFG::gSim, v39 + 64);
            if ( v40 )
            {
              v41 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)v40,
                      UFG::CharacterAnimationComponent::_TypeUID);
              if ( v41 )
                v41 = *(UFG::SimComponent **)&v41[2].m_TypeUID;
              if ( v41 )
              {
                v42 = (signed __int64)&v41[3].m_BoundComponentHandles;
                v43 = (_QWORD *)(*(_QWORD *)&v41->m_Flags - 16i64);
                for ( i = (signed __int64)&v41->m_SafePointerList; v43 != (_QWORD *)i; v43 = (_QWORD *)(v43[3] - 16i64) )
                  (*(void (__fastcall **)(_QWORD *, signed __int64))(*v43 + 160i64))(v43, v42);
              }
            }
          }
          ++v38;
        }
        while ( (signed int)v38 < v37 );
      }
    }
  }
  NISNode::SetPlayTime(v9, v3, v10);
  v4->mTime = v3;
}

// File Line: 1867
// RVA: 0x3E79D0
bool __fastcall NISManager::UseHighDefModel(NISManager *this, UFG::qSymbol *actorId)
{
  UFG::qSymbol *v2; // r14
  NISInstance *v4; // rdi
  NISNode *v5; // rdi
  unsigned int v6; // ebx
  int v7; // esi
  __int64 v8; // rcx

  v2 = actorId;
  if ( this->mHighDefModelsEnabled )
    return 1;
  v4 = this->mpActiveInstance.m_pPointer;
  if ( v4 )
    v5 = v4->mpNISNode;
  else
    v5 = 0i64;
  if ( !v5 )
    return 0;
  v6 = 0;
  v7 = (__int64)v5->vfptr[1].GetClassname((Expression::IMemberMap *)&v5->vfptr);
  if ( v7 <= 0 )
    return 0;
  while ( 1 )
  {
    v8 = ((__int64 (__fastcall *)(NISNode *, _QWORD))v5->vfptr[1].Serialize)(v5, v6);
    if ( *(_DWORD *)(v8 + 256) == v2->mUID )
      break;
    if ( (signed int)++v6 >= v7 )
      return 0;
  }
  return *(_BYTE *)(v8 + 269) != 0;
}

// File Line: 1889
// RVA: 0x3E30B0
char __fastcall NISManager::IsActiveInNIS(NISManager *this, UFG::SimObject *simObject)
{
  UFG::SimObject *v2; // rbp
  NISInstance *v4; // rdi
  unsigned int v5; // ebx
  NISNode *v6; // rdi
  int v7; // esi

  v2 = simObject;
  if ( !simObject || this->mState == STATE_INVALID )
    return 0;
  v4 = this->mpActiveInstance.m_pPointer;
  v5 = 0;
  if ( v4 )
    v6 = v4->mpNISNode;
  else
    v6 = 0i64;
  if ( !v6 )
    return 0;
  v7 = (__int64)v6->vfptr[1].GetClassname((Expression::IMemberMap *)&v6->vfptr);
  if ( v7 <= 0 )
    return 0;
  while ( *(_DWORD *)(((__int64 (__fastcall *)(NISNode *, _QWORD))v6->vfptr[1].Serialize)(v6, v5) + 256) != v2->m_Name.mUID )
  {
    if ( (signed int)++v5 >= v7 )
      return 0;
  }
  return 1;
}

// File Line: 1914
// RVA: 0x3E3060
bool __fastcall NISManager::IntersectsSpatialBoundingBox(NISManager *this, UFG::qBox *box)
{
  float *v2; // rax

  v2 = (float *)this->mSpatialDataHandle.mData;
  return v2[25] >= box->mMin.x
      && v2[22] <= box->mMax.x
      && v2[26] >= box->mMin.y
      && v2[23] <= box->mMax.y
      && v2[27] >= box->mMin.z
      && v2[24] <= box->mMax.z;
}

// File Line: 1923
// RVA: 0x3E3760
void __fastcall NISManager::OnCameraAttached(NISManager *this, CameraAnimationTask *cameraTask)
{
  ITrack *v2; // rdi
  NISManager *v3; // rbx
  AnimationNode *v4; // rcx
  NISInstance *v5; // rax
  NISNode *v6; // rax

  v2 = cameraTask->m_Track;
  v3 = this;
  v4 = cameraTask->mController.m_pPointer;
  if ( v4 )
    v3->mLength = SkeletalAnimation::GetDuration(v4->mSkeletalAnimationHandle.m_SkeletalAnimation.m_pPointer);
  if ( v3->mState )
  {
    v5 = v3->mpActiveInstance.m_pPointer;
    if ( v5 )
    {
      v6 = v5->mpNISNode;
      if ( v6 )
      {
        if ( (ITrack *)v6->mPrimaryCameraAnimationTrack == v2 )
        {
          v3->mbCameraAttached = 1;
          if ( v6->mDisableHUD )
            NISManager::HideHUD(v3);
        }
      }
    }
  }
}

// File Line: 1954
// RVA: 0x3E37D0
void __fastcall NISManager::OnCameraDetached(NISManager *this, CameraAnimationTrack *cameraTrack)
{
  NISInstance *v2; // rbx
  NISNode *v3; // rbx
  bool v4; // zf
  UFG::ProgressionTracker *v5; // rax

  if ( this->mState )
  {
    v2 = this->mpActiveInstance.m_pPointer;
    if ( v2 )
    {
      v3 = v2->mpNISNode;
      if ( v3 )
      {
        if ( v3->mPrimaryCameraAnimationTrack == cameraTrack )
        {
          this->mbCameraAttached = 0;
          if ( v3->mDisableHUD )
          {
            v4 = this->mHudDisableCount-- == 1;
            if ( v4 )
              UFG::UIHK_NISOverlay::HideLetterBox();
          }
        }
        if ( !v3->mSeamlessOut )
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
  const char *v2; // rdi
  NISManager *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  __int64 v5; // rax
  __int64 v6; // r8
  UFG::qNode<NISInstance,NISInstanceMasterList> **v7; // rcx
  UFG::qNode<NISInstance,NISInstanceMasterList> *v8; // rax

  v2 = pathName;
  v3 = this;
  v4 = UFG::qMalloc(0x1A0ui64, "NISManager::CreateInstance", 0i64);
  if ( v4 )
  {
    NISInstance::NISInstance((NISInstance *)v4, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = (UFG::qNode<NISInstance,NISInstanceMasterList> **)(v6 + 24);
  v8 = v3->mInstances.mNode.mPrev;
  v8->mNext = (UFG::qNode<NISInstance,NISInstanceMasterList> *)(v6 + 24);
  *v7 = v8;
  v7[1] = &v3->mInstances.mNode;
  v3->mInstances.mNode.mPrev = (UFG::qNode<NISInstance,NISInstanceMasterList> *)(v6 + 24);
  return (NISInstance *)v6;
}

// File Line: 2016
// RVA: 0x3E2640
void __fastcall NISManager::DestroyInstance(NISManager *this, NISInstance *pInstance)
{
  UFG::qNode<NISInstance,NISInstanceMasterList> *v2; // r8
  UFG::qNode<NISInstance,NISInstanceMasterList> *v3; // rax
  UFG::qNode<NISInstance,NISInstanceMasterList> *v4; // r9
  NISInstance *v5; // rbx
  NISManager *v6; // rdi
  UFG::qSafePointer<NISInstance,NISInstance> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v9; // rax

  v2 = pInstance->mPrev;
  v3 = pInstance->mNext;
  v4 = (UFG::qNode<NISInstance,NISInstanceMasterList> *)&pInstance->mPrev;
  v2->mNext = v3;
  v3->mPrev = v2;
  v5 = pInstance;
  v4->mPrev = v4;
  v4->mNext = v4;
  v6 = this;
  if ( pInstance )
    pInstance->vfptr->__vecDelDtor((UFG::qSafePointerNode<NISInstance> *)pInstance, 1u);
  if ( v5 == v6->mpPreloadInstance.m_pPointer )
  {
    v7 = &v6->mpPreloadInstance;
    if ( v6->mpPreloadInstance.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v6->mpPreloadInstance.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v6->mpPreloadInstance.mNext = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v6->mpPreloadInstance.mPrev;
    }
    v6->mpPreloadInstance.m_pPointer = 0i64;
  }
}

