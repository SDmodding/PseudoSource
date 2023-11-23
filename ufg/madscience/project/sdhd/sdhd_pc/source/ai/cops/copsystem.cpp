// File Line: 149
// RVA: 0x3EF340
UFG::CopSystem *__fastcall UFG::CopSystem::Instance()
{
  if ( (_S10_5 & 1) == 0 )
  {
    _S10_5 |= 1u;
    UFG::CopSystem::CopSystem(&sCopSystem);
    atexit(UFG::CopSystem::Instance_::_2_::_dynamic_atexit_destructor_for__sCopSystem__);
  }
  UFG::CopSystem::mspInstance = &sCopSystem;
  return &sCopSystem;
}

// File Line: 170
// RVA: 0x3EC240
void __fastcall UFG::CopSystem::CopSystem(UFG::CopSystem *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpAmbientSuspect; // rdi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpArrestRightHumanCop; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  UFG::EncounterBase::EncounterBase(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *)&UFG::CopSystem::`vftable;
  this->mNumArrestAttempts = 0;
  this->mAreRoadBlocksActive = 0;
  this->mRoadBlockCooldownTimestamp = 0.0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mRoadBlockTriggerOrigin.x = UFG::qVector3::msZero.x;
  this->mRoadBlockTriggerOrigin.y = y;
  this->mRoadBlockTriggerOrigin.z = z;
  *(_QWORD *)&this->mAudioTimer = 0i64;
  this->mAudioPursuitDelay = 0.0;
  this->mDistantSirens.m_pOneShot = 0i64;
  *(_QWORD *)&this->mAudioHeatLevel.m_currentValue = 0i64;
  this->mAudioHeatLevel.m_riseRate = 10000000.0;
  this->mAudioHeatLevel.m_fallRate = 10000000.0;
  `eh vector constructor iterator(
    this->mHeatEvents,
    0xCui64,
    26,
    (void (__fastcall *)(void *))UFG::CopHeatEvent::CopHeatEvent);
  p_mpAmbientSuspect = &this->mpAmbientSuspect;
  this->mpAmbientSuspect.mPrev = &this->mpAmbientSuspect;
  this->mpAmbientSuspect.mNext = &this->mpAmbientSuspect;
  this->mpAmbientSuspect.m_pPointer = 0i64;
  p_mpArrestRightHumanCop = &this->mpArrestRightHumanCop;
  this->mpArrestRightHumanCop.mPrev = &this->mpArrestRightHumanCop;
  this->mpArrestRightHumanCop.mNext = &this->mpArrestRightHumanCop;
  this->mpArrestRightHumanCop.m_pPointer = 0i64;
  UFG::qString::qString(&this->mLastHeatEventCaption);
  this->mLastHeatEventIndex = eHEATEVENT_NONE;
  *(_WORD *)&this->mIsExcludingPlayerForRestOfChase = 256;
  this->mReloadTuningFiles = 0;
  this->mDebugDrawLevel = 1;
  *(_WORD *)&this->mShowCops = 0;
  this->mShowResources = 0;
  if ( this->mpAmbientSuspect.m_pPointer )
  {
    mPrev = p_mpAmbientSuspect->mPrev;
    mNext = this->mpAmbientSuspect.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpAmbientSuspect->mPrev = p_mpAmbientSuspect;
    this->mpAmbientSuspect.mNext = &this->mpAmbientSuspect;
  }
  this->mpAmbientSuspect.m_pPointer = 0i64;
  if ( this->mpArrestRightHumanCop.m_pPointer )
  {
    v8 = p_mpArrestRightHumanCop->mPrev;
    v9 = this->mpArrestRightHumanCop.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mpArrestRightHumanCop->mPrev = p_mpArrestRightHumanCop;
    this->mpArrestRightHumanCop.mNext = &this->mpArrestRightHumanCop;
  }
  this->mpArrestRightHumanCop.m_pPointer = 0i64;
  this->mArrestRightTimestamp = 0.0;
}

// File Line: 202
// RVA: 0x3EC3D0
void __fastcall UFG::CopSystem::~CopSystem(UFG::CopSystem *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpArrestRightHumanCop; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpAmbientSuspect; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *)&UFG::CopSystem::`vftable;
  UFG::qString::~qString(&this->mLastHeatEventCaption);
  p_mpArrestRightHumanCop = &this->mpArrestRightHumanCop;
  if ( this->mpArrestRightHumanCop.m_pPointer )
  {
    mPrev = p_mpArrestRightHumanCop->mPrev;
    mNext = this->mpArrestRightHumanCop.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpArrestRightHumanCop->mPrev = p_mpArrestRightHumanCop;
    this->mpArrestRightHumanCop.mNext = &this->mpArrestRightHumanCop;
  }
  this->mpArrestRightHumanCop.m_pPointer = 0i64;
  v5 = p_mpArrestRightHumanCop->mPrev;
  v6 = this->mpArrestRightHumanCop.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mpArrestRightHumanCop->mPrev = p_mpArrestRightHumanCop;
  this->mpArrestRightHumanCop.mNext = &this->mpArrestRightHumanCop;
  p_mpAmbientSuspect = &this->mpAmbientSuspect;
  if ( this->mpAmbientSuspect.m_pPointer )
  {
    v8 = p_mpAmbientSuspect->mPrev;
    v9 = this->mpAmbientSuspect.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mpAmbientSuspect->mPrev = p_mpAmbientSuspect;
    this->mpAmbientSuspect.mNext = &this->mpAmbientSuspect;
  }
  this->mpAmbientSuspect.m_pPointer = 0i64;
  v10 = p_mpAmbientSuspect->mPrev;
  v11 = this->mpAmbientSuspect.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mpAmbientSuspect->mPrev = p_mpAmbientSuspect;
  this->mpAmbientSuspect.mNext = &this->mpAmbientSuspect;
  `eh vector destructor iterator(this->mHeatEvents, 0xCui64, 26, (void (__fastcall *)(void *))_);
  UFG::OneShotHandle::Release(&this->mDistantSirens);
  UFG::EncounterBase::~EncounterBase(this);
}

// File Line: 206
// RVA: 0x3EF0D0
void __fastcall UFG::CopSystem::Initialize(UFG::CopSystem *this)
{
  fastdelegate::detail::GenericClass *RCX; // rax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *vfptr; // rdi
  UFG::SimObjectCharacter *LocalPlayer; // rax
  unsigned int v5; // eax
  UFG::qPropertySet *PropertySet; // rax
  float *v7; // rdi
  UFG::qPropertySet *v8; // rax
  float *v9; // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v10[2]; // [rsp+38h] [rbp-20h] BYREF

  v10[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *)) UFG::CopSystem::`vcall{744,{flat}};
  v10[0].m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    v10,
    UFG::gGameStatEventChannel.mUID,
    UFG::gGameStatEventChannel.mName,
    0);
  RCX = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v10[0].m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *)) UFG::CopSystem::`vcall{736,{flat}};
  v10[0].m_Closure.m_pthis = RCX;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    v10,
    UFG::gDestructionEventChannel.mUID,
    UFG::gDestructionEventChannel.mName,
    0);
  this->vfptr[5].__vecDelDtor(this, (unsigned int)sCopsTuningPropertySetName);
  vfptr = this->vfptr;
  LocalPlayer = UFG::GetLocalPlayer();
  vfptr[19].__vecDelDtor(this, (unsigned int)LocalPlayer);
  UFG::EncounterBase::Initialize(this);
  if ( (_S11_4 & 1) == 0 )
  {
    _S11_4 |= 1u;
    v5 = UFG::qStringHash32("audio-copaudiocomponent", 0xFFFFFFFF);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&audioPropertySet, v5);
    atexit(UFG::CopSystem::Initialize_::_2_::_dynamic_atexit_destructor_for__audioPropertySet__);
  }
  PropertySet = UFG::PropertySetManager::CreateOrFindPropertySet(&audioPropertySet);
  this->mCopAudioConfig = PropertySet;
  v7 = UFG::qPropertySet::Get<float>(
         PropertySet,
         (UFG::qArray<unsigned long,0> *)&vehicle_pursuit_max_time,
         DEPTH_RECURSE);
  this->mAudioPursuitDelay = UFG::qRandom(*v7, (unsigned int *)&UFG::qDefaultSeed) + 2.0;
  this->mAudioScannerDelay = UFG::qRandom(*v7, (unsigned int *)&UFG::qDefaultSeed) + 2.0;
  this->mAudioTimer = 0.0;
  memset(this->mStimulusWatchList, 0, sizeof(this->mStimulusWatchList));
  this->mStimulusWatchList[5] = 1;
  *(_WORD *)&this->mStimulusWatchList[9] = 257;
  *(_DWORD *)&this->mStimulusWatchList[13] = 16843009;
  this->mStimulusWatchList[17] = 1;
  this->mStimulusWatchList[19] = 1;
  this->mStimulusWatchList[21] = 1;
  *(_WORD *)&this->mStimulusWatchList[23] = 257;
  this->mStimulusWatchList[25] = 1;
  *(_WORD *)&this->mStimulusWatchList[28] = 257;
  UFG::GameStatAction::Player::SetHeat(0.0);
  this->mIsAmbientUnitsAllowed = 1;
  if ( this->mHeatLevel == HEATLEVEL_NONE )
  {
    v8 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[33].__vecDelDtor)(this);
    v9 = UFG::qPropertySet::Get<float>(v8, (UFG::qArray<unsigned long,0> *)&EncounterSym_heatwave_timer, DEPTH_RECURSE);
    this->mWaveTimer = UFG::qRandom(*v9, (unsigned int *)&UFG::qDefaultSeed);
  }
  *(_QWORD *)&this->mStats.mFinishReason = 0i64;
  this->mStats.mLastLevelKillCount = 0;
  ((void (__fastcall *)(UFG::CopSystem *))this->vfptr[120].__vecDelDtor)(this);
  this->mHeatLevelTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
  this->mOnFootNoSprintTimer = 0.0;
}

// File Line: 273
// RVA: 0x3F0630
void __fastcall UFG::CopSystem::Shutdown(UFG::CopSystem *this, __int64 a2)
{
  UFG::CopRoadBlock *v3; // rcx
  UFG::qList<UFG::CopRoadBlock,UFG::CopRoadBlock,1,0> *v4; // rbx
  fastdelegate::detail::GenericClass *RCX; // rax
  fastdelegate::FastDelegate1<UFG::Event *,void> v6; // [rsp+20h] [rbp-18h] BYREF

  LOBYTE(a2) = 1;
  this->vfptr[3].__vecDelDtor(this, a2);
  v3 = (UFG::CopRoadBlock *)&UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mNext[-7];
  if ( (UFG::qList<UFG::CopRoadBlock,UFG::CopRoadBlock,1,0> *)&UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mNext[-7] != &UFG::CopRoadBlock::s_CopRoadBlockList - 7 )
  {
    do
    {
      v4 = (UFG::qList<UFG::CopRoadBlock,UFG::CopRoadBlock,1,0> *)&v3->mNext[-7];
      UFG::CopRoadBlock::Despawn(v3);
      v3 = (UFG::CopRoadBlock *)v4;
    }
    while ( v4 != &UFG::CopRoadBlock::s_CopRoadBlockList - 7 );
  }
  this->mAreRoadBlocksActive = 0;
  UFG::EncounterBase::Shutdown(this);
  v6.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *)) UFG::CopSystem::`vcall{736,{flat}};
  v6.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v6, UFG::gDestructionEventChannel.mUID);
  RCX = (fastdelegate::detail::GenericClass *)Assembly::GetRCX(this);
  v6.m_Closure.m_pFunction = (void (__fastcall *)(fastdelegate::detail::GenericClass *)) UFG::CopSystem::`vcall{744,{flat}};
  v6.m_Closure.m_pthis = RCX;
  UFG::EventDispatcher::UnRegister(&UFG::EventDispatcher::mInstance, &v6, UFG::gGameStatEventChannel.mUID);
  ((void (__fastcall *)(UFG::CopSystem *))this->vfptr[117].__vecDelDtor)(this);
}

// File Line: 293
// RVA: 0x3F0170
void __fastcall UFG::CopSystem::RemoveAllUnitsOnScene(UFG::CopSystem *this, bool includeNonManaged)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax
  __int16 m_Flags; // r9
  UFG::VehicleOwnershipComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *OwnedVehicle; // rbp
  UFG::qList<UFG::CopUnitComponent,UFG::CopUnitComponent,1,0> *p_mNext; // rax
  char mPrev; // cl
  UFG::qList<UFG::CopUnitComponent,UFG::CopUnitComponent,1,0> *v9; // rbx
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *mNext; // rdi

  UFG::EncounterBase::RemoveAllUnitsOnScene(this, includeNonManaged);
  LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer
    && ((m_Flags = LocalPlayer->m_Flags, (m_Flags & 0x4000) != 0)
     || m_Flags < 0
     || (m_Flags & 0x2000) != 0
     || (m_Flags & 0x1000) != 0
      ? (ComponentOfTypeHK = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 LocalPlayer,
                                                                 UFG::VehicleOwnershipComponent::_TypeUID))
      : (ComponentOfTypeHK = (UFG::VehicleOwnershipComponent *)UFG::SimObject::GetComponentOfType(
                                                                 LocalPlayer,
                                                                 UFG::VehicleOwnershipComponent::_TypeUID)),
        ComponentOfTypeHK) )
  {
    OwnedVehicle = UFG::VehicleOwnershipComponent::GetOwnedVehicle(ComponentOfTypeHK);
  }
  else
  {
    OwnedVehicle = 0i64;
  }
  p_mNext = (UFG::qList<UFG::CopUnitComponent,UFG::CopUnitComponent,1,0> *)&UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mNext[-5].mNext;
  if ( &UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mNext[-5].mNext != (UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> **)((char *)&UFG::CopUnitComponent::s_CopUnitComponentList - 72) )
  {
    do
    {
      mPrev = (char)p_mNext[30].mNode.mPrev;
      v9 = (UFG::qList<UFG::CopUnitComponent,UFG::CopUnitComponent,1,0> *)&p_mNext[5].mNode.mPrev[-5].mNext;
      if ( (mPrev & 2) != 0 && (includeNonManaged || (mPrev & 1) != 0) )
      {
        mNext = p_mNext[2].mNode.mNext;
        UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&mNext[4].mNext);
        if ( mNext == (UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *)OwnedVehicle )
        {
          UFG::qPrintChannel::Print(
            &UFG::gPrintChannel_HK_Cops,
            OUTPUT_LEVEL_DEBUG,
            "[CopSystem]:   IGNORING (%s), because player vehicle!\n");
        }
        else
        {
          UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Cops, OUTPUT_LEVEL_DEBUG, "[CopSystem]:   Deleting (%s)\n");
          UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, (UFG::SimObject *)mNext);
        }
      }
      p_mNext = v9;
    }
    while ( v9 != (UFG::qList<UFG::CopUnitComponent,UFG::CopUnitComponent,1,0> *)((char *)&UFG::CopUnitComponent::s_CopUnitComponentList
                                                                                - 72) );
  }
}

// File Line: 323
// RVA: 0x3ECF90
void __fastcall UFG::CopSystem::EnableAmbientUnits(UFG::CopSystem *this, __int64 enable)
{
  if ( (_BYTE)enable != this->mIsAmbientUnitsAllowed )
  {
    this->mIsAmbientUnitsAllowed = enable;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Cops,
      OUTPUT_LEVEL_DEBUG,
      "[CopSystem]: Enable ambient state changed to (%s)\n");
  }
  if ( !this->mIsAmbientUnitsAllowed && this->mHeatLevel == HEATLEVEL_NONE )
  {
    LOBYTE(enable) = 1;
    this->vfptr[3].__vecDelDtor(this, enable);
  }
}

// File Line: 338
// RVA: 0x3EF8C0
void __fastcall UFG::CopSystem::OnRestore(UFG::CopSystem *this)
{
  __int64 v2; // rdx
  UFG::qPropertySet *v3; // rax
  float *v4; // rax

  ((void (__fastcall *)(UFG::CopSystem *))this->vfptr[117].__vecDelDtor)(this);
  ((void (__fastcall *)(UFG::CopSystem *, _QWORD, _QWORD))this->vfptr[88].__vecDelDtor)(this, 0i64, 0i64);
  ((void (__fastcall *)(UFG::CopSystem *))this->vfptr[112].__vecDelDtor)(this);
  LOBYTE(v2) = 1;
  this->vfptr[3].__vecDelDtor(this, v2);
  ((void (__fastcall *)(UFG::CopSystem *))this->vfptr[120].__vecDelDtor)(this);
  v3 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[33].__vecDelDtor)(this);
  v4 = UFG::qPropertySet::Get<float>(v3, (UFG::qArray<unsigned long,0> *)&EncounterSym_heatwave_timer, DEPTH_RECURSE);
  this->mWaveTimer = UFG::qRandom(*v4, (unsigned int *)&UFG::qDefaultSeed);
}

// File Line: 352
// RVA: 0x3ECEE0
void __fastcall UFG::CopSystem::Enable(UFG::CopSystem *this, bool enable)
{
  if ( enable != this->mEnable )
  {
    this->mEnable = enable;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Cops,
      OUTPUT_LEVEL_DEBUG,
      "[CopSystem]: Enable state changed to (%s)\n");
    ((void (__fastcall *)(UFG::CopSystem *))this->vfptr[50].__vecDelDtor)(this);
  }
  if ( !this->mEnable )
  {
    if ( (_S10_5 & 1) == 0 )
    {
      _S10_5 |= 1u;
      UFG::CopSystem::CopSystem(&sCopSystem);
      atexit(UFG::CopSystem::Instance_::_2_::_dynamic_atexit_destructor_for__sCopSystem__);
    }
    UFG::CopSystem::mspInstance = &sCopSystem;
    sCopSystem.vfptr[3].__vecDelDtor(&sCopSystem, 0);
  }
}

// File Line: 369
// RVA: 0x3EF870
_BOOL8 __fastcall UFG::CopSystem::IsStimulusUpdateRequired(UFG::CopSystem *this)
{
  bool *p_mTracked; // rax
  __int64 v2; // rdx
  _BOOL8 result; // rax

  p_mTracked = &this->mHeatEvents[0].mTracked;
  v2 = 0i64;
  while ( *p_mTracked )
  {
    ++v2;
    p_mTracked += 12;
    if ( v2 >= 26 )
      return this->mShowStimulus;
  }
  result = 1i64;
  if ( this->mShowStimulus )
    return 1i64;
  return result;
}

// File Line: 391
// RVA: 0x3EF3A0
bool __fastcall UFG::CopSystem::IsAmbientUnitsAllowed(UFG::CopSystem *this)
{
  UFG::ProgressionTracker *v1; // rax
  bool result; // al

  result = 0;
  if ( this->mIsAmbientUnitsAllowed )
  {
    v1 = UFG::ProgressionTracker::Instance();
    if ( !UFG::ProgressionTracker::IsRunningCriticalActiveMaster(v1) )
      return 1;
  }
  return result;
}

// File Line: 397
// RVA: 0x3ED720
unsigned int __fastcall UFG::CopSystem::GetDesiredVehiclePopulation(
        UFG::CopSystem *this,
        UFG::qPropertySet *heatPropSet)
{
  unsigned int DesiredVehiclePopulation; // edi
  unsigned int v6; // eax
  int v7; // ecx

  if ( this->mHeatLevel )
  {
    DesiredVehiclePopulation = UFG::EncounterBase::GetDesiredVehiclePopulation(this, heatPropSet);
    if ( this->mFocusTargetContext.mIsOnFootHeuristic )
    {
      v6 = (unsigned int)this->vfptr[44].__vecDelDtor(this, 2i64);
      if ( v6 + DesiredVehiclePopulation > 8 )
      {
        v7 = 8;
        if ( v6 < 8 )
          v7 = v6;
        DesiredVehiclePopulation = 8 - v7;
      }
    }
    if ( this->mFocusTargetContext.mIsInsideInterior )
      return 0;
    return DesiredVehiclePopulation;
  }
  else if ( ((unsigned __int8 (__fastcall *)(UFG::CopSystem *))this->vfptr[113].__vecDelDtor)(this) )
  {
    return UFG::EncounterBase::GetDesiredVehiclePopulation(this, heatPropSet);
  }
  else
  {
    return 0;
  }
}

// File Line: 425
// RVA: 0x3ED6D0
__int64 __fastcall UFG::CopSystem::GetDesiredOnFootPopulation(UFG::CopSystem *this, UFG::qPropertySet *heatPropSet)
{
  UFG::qPropertySet *v2; // rdi
  UFG::CopSystem *v3; // rbx

  v2 = heatPropSet;
  v3 = this;
  if ( this->mHeatLevel )
    return UFG::EncounterBase::GetDesiredOnFootPopulation(this, heatPropSet);
  if ( ((unsigned __int8 (__fastcall *)(UFG::CopSystem *))this->vfptr[113].__vecDelDtor)(this) )
  {
    heatPropSet = v2;
    this = v3;
    return UFG::EncounterBase::GetDesiredOnFootPopulation(this, heatPropSet);
  }
  return 0i64;
}

// File Line: 437
// RVA: 0x3F17B0
void __fastcall UFG::CopSystem::UpdateHeatTimer(UFG::CopSystem *this, float deltaTime, float currentTime)
{
  Render::DebugDrawManager *Context; // rax
  _BOOL8 mCoolingDown; // rdx
  float v6; // xmm0_4
  Render::DebugDrawContext *v7; // rdi
  __int64 mHeatLevel; // rax
  bool v9; // al
  float mReplenishTimeout; // xmm0_4
  float v11; // xmm0_4
  bool v12; // zf
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *vfptr; // rax
  UFG::qPropertySet *v14; // rax
  UFG::HeatLevelEnum v15; // eax
  char v16; // di
  float v17; // xmm7_4
  double v18; // xmm0_8
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v19; // rax
  UFG::qPropertySet *v20; // rax
  float v21; // xmm0_4

  Context = Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  mCoolingDown = this->mCoolingDown;
  v6 = this->mReducedRadiusTimer - deltaTime;
  this->mCoolingDown = 0;
  v7 = (Render::DebugDrawContext *)Context;
  if ( v6 <= 0.0 )
    v6 = 0.0;
  mHeatLevel = this->mHeatLevel;
  this->mReducedRadiusTimer = v6;
  if ( (_DWORD)mHeatLevel )
  {
    v9 = UFG::Metrics::msInstance.mSimTimeMSec - this->mStartTimestamp < CopSystem_MinimumEngagedTime[mHeatLevel];
    if ( this->mIsSafehouseInstantCooldownActive || !v9 )
    {
      if ( mCoolingDown
        || !this->mIsReplenishing
        || (mReplenishTimeout = this->mReplenishTimeout, mReplenishTimeout <= 0.0) )
      {
        if ( ((unsigned int (__fastcall *)(UFG::CopSystem *))this->vfptr[32].__vecDelDtor)(this) )
          this->mCooldownAllowed = 0;
        if ( this->mEnable && this->mDebugDrawLevel > 1 )
        {
          if ( this->mCooldownAllowed )
            Render::DebugDrawContext::DrawTextA(v7, 700, 20, &UFG::qColour::Green, "(ESCAPED!)");
          else
            Render::DebugDrawContext::DrawTextA(
              v7,
              700,
              20,
              &UFG::qColour::Red,
              "(INSIDE) Inside (dynamic: %d) heat regions",
              this->mInsideDynamicRadiusCount);
        }
      }
      else
      {
        v11 = mReplenishTimeout - deltaTime;
        if ( v11 <= 0.0 )
          v11 = 0.0;
        v12 = !this->mEnable;
        this->mReplenishTimeout = v11;
        this->mCooldownAllowed = 0;
        if ( !v12 && this->mDebugDrawLevel > 1 )
          Render::DebugDrawContext::DrawTextA(
            v7,
            700,
            20,
            &UFG::qColour::Green,
            "(REPLENSHING) (%.2f seconds remaining)",
            v11);
      }
    }
    else
    {
      this->mWaveCount = 0;
      this->mCooldownAllowed = 0;
      this->mIsReplenishing = 1;
    }
  }
  if ( this->mCooldownAllowed )
  {
    this->mCoolingDown = 1;
  }
  else
  {
    vfptr = this->vfptr;
    this->mCooldownAllowed = 1;
    v14 = (UFG::qPropertySet *)vfptr[33].__vecDelDtor(this, mCoolingDown);
    this->mNonEventfulCooldownTimestamp = UFG::Metrics::msInstance.mSimTime_Temp
                                        + *UFG::qPropertySet::Get<float>(
                                             v14,
                                             (UFG::qArray<unsigned long,0> *)&EncounterSym_cooldown_timer,
                                             DEPTH_RECURSE);
  }
  if ( this->mInstantCooldownActive || this->mIsSafehouseInstantCooldownActive )
    this->mCoolingDown = 1;
  if ( currentTime <= this->mNonEventfulCooldownTimestamp || !this->mCoolingDown )
    goto LABEL_40;
  v15 = this->mHeatLevel;
  v16 = 0;
  v17 = 0.0;
  if ( v15 == HEATLEVEL_NONE )
    v16 = 1;
  if ( v15 > HEATLEVEL_NONE )
  {
    v18 = ((double (__fastcall *)(UFG::CopSystem *, _QWORD))this->vfptr[87].__vecDelDtor)(this, 0i64);
    v19 = this->vfptr;
    this->mStats.mFinishReason = eFinishReason_Escaped;
    v17 = *(float *)&v18;
    v20 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::CopSystem *))v19[33].__vecDelDtor)(this);
    this->mNonEventfulCooldownTimestamp = UFG::Metrics::msInstance.mSimTime_Temp
                                        + *UFG::qPropertySet::Get<float>(
                                             v20,
                                             (UFG::qArray<unsigned long,0> *)&EncounterSym_cooldown_timer,
                                             DEPTH_RECURSE);
  }
  UFG::GameStatAction::Player::SetHeat(v17);
  if ( v16 )
  {
LABEL_40:
    if ( !this->mIsReplenishing )
    {
      v21 = this->mWaveTimer - deltaTime;
      this->mWaveTimer = v21;
      if ( v21 <= 0.0 )
        ((void (__fastcall *)(UFG::CopSystem *))this->vfptr[23].__vecDelDtor)(this);
    }
  }
}

// File Line: 559
// RVA: 0x3EEB70
void __fastcall UFG::CopSystem::HandleHeatLevelChange(UFG::CopSystem *this)
{
  UFG::qPropertySet *v2; // rax
  UFG::qPropertySet *v3; // rdi
  signed int v4; // ebp
  bool *v5; // rax
  bool v6; // zf
  bool v7; // cl
  UFG::qStaticSymbol *v8; // rax
  float v9; // xmm6_4
  signed int v10; // esi
  UFG::eAIObjective v11; // r15d
  unsigned int v12; // r14d
  UFG::SimObjectCVBase *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *v15; // rax
  UFG::ActiveAIEntityComponent *v16; // rdi
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *vfptr; // rax
  signed int i; // edi
  UFG::HeatLevelEnum mHeatLevel; // eax
  UFG::HeatLevelEnum v20; // eax
  UFG::qArray<unsigned long,0> name; // [rsp+50h] [rbp+8h] BYREF

  v2 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[33].__vecDelDtor)(this);
  v3 = v2;
  if ( v2 )
  {
    v4 = 1;
    this->mIsAvoidPeds = *UFG::qPropertySet::Get<bool>(
                            v2,
                            (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_avoid_peds,
                            DEPTH_RECURSE);
    this->mIsAllowedToPass = *UFG::qPropertySet::Get<bool>(
                                v3,
                                (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_allowed_to_pass,
                                DEPTH_RECURSE);
    this->mIsStaysOffSidewalk = *UFG::qPropertySet::Get<bool>(
                                   v3,
                                   (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_stays_off_sidewalk,
                                   DEPTH_RECURSE);
    this->mIsRespectSpeedLimit = *UFG::qPropertySet::Get<bool>(
                                    v3,
                                    (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_respect_speed_limit,
                                    DEPTH_RECURSE);
    v5 = UFG::qPropertySet::Get<bool>(
           v3,
           (UFG::qArray<unsigned long,0> *)&EncounterSym_vehicle_can_turn_around,
           DEPTH_RECURSE);
    v6 = !this->mFocusTargetContext.mIsOnFootHeuristic;
    v7 = *v5;
    v8 = &EncounterSym_ambient_density_invehicle;
    this->mIsCanTurnAround = v7;
    if ( !v6 )
      v8 = &EncounterSym_ambient_density_onfoot;
    name.size = v8->mUID;
    v9 = *UFG::qPropertySet::Get<float>(v3, &name, DEPTH_RECURSE);
    UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::AdjustCopSystemDensityModifier(v9);
    v10 = 0;
    v11 = eAI_OBJECTIVE_NONE;
    v12 = 0;
    UFG::WheeledVehicleManager::mMaxRoadDensityScale = v9;
    if ( this->mHeatLevel > HEATLEVEL_NONE )
      v11 = eAI_OBJECTIVE_PURSUIT_TARGET;
    if ( this->mHumans.size )
    {
      do
      {
        m_pSimObject = (UFG::SimObjectCVBase *)this->mHumans.p[v12]->m_pSimObject;
        if ( m_pSimObject )
        {
          m_Flags = m_pSimObject->m_Flags;
          if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
            v15 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pSimObject);
          else
            v15 = (UFG::ActiveAIEntityComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                                 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     m_pSimObject,
                                                     UFG::ActiveAIEntityComponent::_TypeUID)
                                                 : UFG::SimObject::GetComponentOfType(
                                                     m_pSimObject,
                                                     UFG::ActiveAIEntityComponent::_TypeUID));
          v16 = v15;
          if ( v15 )
          {
            UFG::ActiveAIEntityComponent::SetCurrentObjective(v15, v11, "EncounterBase::HandleHeatLevelChange");
            v16->m_bCanWander = 1;
          }
        }
        ++v12;
      }
      while ( v12 < this->mHumans.size );
    }
    ((void (__fastcall *)(UFG::CopSystem *))this->vfptr[49].__vecDelDtor)(this);
    if ( this->mHeatLevel )
    {
      for ( i = 0; i < 6; ++i )
      {
        if ( this->mEnable )
        {
          mHeatLevel = this->mHeatLevel;
          if ( i == mHeatLevel || i == mHeatLevel + 1 )
            this->vfptr[45].__vecDelDtor(this, i);
        }
      }
      do
      {
        if ( !this->mEnable || (v20 = this->mHeatLevel, v10 != v20) && v10 != v20 + 1 )
          this->vfptr[46].__vecDelDtor(this, v10);
        ++v10;
      }
      while ( v10 < 6 );
    }
    else
    {
      vfptr = this->vfptr;
      if ( this->mEnable )
        vfptr[45].__vecDelDtor(this, 0);
      else
        vfptr[46].__vecDelDtor(this, 0);
      do
        this->vfptr[46].__vecDelDtor(this, v4++);
      while ( v4 < 6 );
    }
  }
}

// File Line: 638
// RVA: 0x3F1FA0
void __fastcall UFG::CopSystem::UpdateVehicleFlags(UFG::CopSystem *this, UFG::SimObjectCVBase *pSimObject)
{
  signed __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::AiDriverComponent *v6; // rdi
  signed __int16 v7; // cx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v10; // edx
  bool v11; // cl

  if ( pSimObject )
  {
    m_Flags = pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(pSimObject);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      pSimObject,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                      pSimObject,
                                                      UFG::AiDriverComponent::_TypeUID);
    }
    v6 = ComponentOfTypeHK;
    if ( ComponentOfTypeHK )
    {
      UFG::AiDriverComponent::SetAvoidPeds(ComponentOfTypeHK, this->mIsAvoidPeds);
      UFG::AiDriverComponent::SetAllowedToPass(v6, this->mIsAllowedToPass);
      UFG::AiDriverComponent::SetStayOffSidewalk(v6, this->mIsStaysOffSidewalk);
      UFG::AiDriverComponent::SetRespectSpeedLimit(v6, this->mIsRespectSpeedLimit);
      UFG::AiDriverComponent::SetCanTurnAround(v6, this->mIsCanTurnAround);
    }
    v7 = pSimObject->m_Flags;
    if ( (v7 & 0x4000) != 0 )
    {
      m_pComponent = pSimObject->m_Components.p[24].m_pComponent;
    }
    else if ( v7 >= 0 )
    {
      if ( (v7 & 0x2000) != 0 || (v7 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(pSimObject, UFG::RoadSpaceComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(pSimObject, UFG::RoadSpaceComponent::_TypeUID);
      m_pComponent = ComponentOfType;
    }
    else
    {
      m_pComponent = pSimObject->m_Components.p[24].m_pComponent;
    }
    if ( m_pComponent )
    {
      v10 = 4;
      if ( this->mHeatLevel )
        v10 = 1;
      UFG::RoadSpaceComponent::SetLaneFlags((UFG::RoadSpaceComponent *)m_pComponent, v10);
      v11 = this->mHeatLevel != HEATLEVEL_NONE;
      m_pComponent[30].m_TypeUID &= ~2u;
      m_pComponent[30].m_TypeUID |= 2 * v11;
    }
  }
}

// File Line: 672
// RVA: 0x3ED000
void __fastcall UFG::CopSystem::ExcludePlayerForRestOfChase(UFG::CopSystem *this)
{
  UFG::GameStatTracker *v2; // rax
  __int64 i; // rbp
  UFG::SimObjectGame *m_pSimObject; // rbx
  __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rsi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v8; // zf
  UFG::SimObjectGame *v9; // rcx
  unsigned __int8 v10; // cl
  __int64 v11; // rdi
  __int16 v12; // cx
  UFG::SimComponent *ComponentOfType; // rax

  if ( !this->mIsExcludingPlayerForRestOfChase && this->mHeatLevel > HEATLEVEL_NONE )
  {
    this->mIsExcludingPlayerForRestOfChase = 1;
    v2 = UFG::FactionInterface::Get();
    UFG::FactionInterface::SetStanding(&v2->mFactionInterface, FACTION_PLAYER, FACTION_LAW, FACTIONSTANDING_INDIFFERENT);
    for ( i = 0i64; (unsigned int)i < this->mHumans.size; i = (unsigned int)(i + 1) )
    {
      m_pSimObject = (UFG::SimObjectGame *)this->mHumans.p[i]->m_pSimObject;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  (UFG::SimObjectGame *)this->mHumans.p[i]->m_pSimObject,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v8 = (m_Flags & 0x1000) == 0;
            v9 = (UFG::SimObjectGame *)this->mHumans.p[i]->m_pSimObject;
            if ( v8 )
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v9,
                                    UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          m_pComponent = ComponentOfTypeHK;
        }
        else
        {
          m_pComponent = m_pSimObject->m_Components.p[20].m_pComponent;
        }
        if ( m_pComponent )
        {
          v10 = *(_BYTE *)(*(_QWORD *)&m_pComponent[1].m_Flags + 37i64);
          if ( v10 )
          {
            v11 = 56i64 * v10;
            UFG::TargetingSimObject::SetTarget(
              (UFG::TargetingSimObject *)(v11 + *(_QWORD *)&m_pComponent[1].m_TypeUID),
              0i64);
            UFG::TargetingSimObject::SetLock(
              (UFG::TargetingSimObject *)(v11 + *(_QWORD *)&m_pComponent[1].m_TypeUID),
              0);
          }
        }
        v12 = m_pSimObject->m_Flags;
        if ( (v12 & 0x4000) != 0 )
        {
          ComponentOfType = m_pSimObject->m_Components.p[6].m_pComponent;
        }
        else if ( v12 >= 0 )
        {
          if ( (v12 & 0x2000) != 0 || (v12 & 0x1000) != 0 )
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::HealthComponent::_TypeUID);
          else
            ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::HealthComponent::_TypeUID);
        }
        else
        {
          ComponentOfType = m_pSimObject->m_Components.p[6].m_pComponent;
        }
        BYTE6(ComponentOfType[1].m_BoundComponentHandles.mNode.mPrev) = 0;
      }
    }
  }
}

// File Line: 703
// RVA: 0x3EF990
void __fastcall UFG::CopSystem::ReIncludePlayerForRestOfChase(UFG::CopSystem *this)
{
  UFG::GameStatTracker *v2; // rax
  __int64 i; // rbx
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax

  if ( this->mHeatLevel > HEATLEVEL_NONE )
  {
    this->mIsExcludingPlayerForRestOfChase = 0;
    v2 = UFG::FactionInterface::Get();
    UFG::FactionInterface::SetStanding(&v2->mFactionInterface, FACTION_PLAYER, FACTION_LAW, FACTIONSTANDING_HOSTILE);
    for ( i = 0i64; (unsigned int)i < this->mHumans.size; i = (unsigned int)(i + 1) )
    {
      m_pSimObject = (UFG::SimObjectGame *)this->mHumans.p[i]->m_pSimObject;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::HealthComponent::_TypeUID);
          else
            m_pComponent = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::HealthComponent::_TypeUID);
        }
        else
        {
          m_pComponent = m_pSimObject->m_Components.p[6].m_pComponent;
        }
        BYTE6(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) = 1;
      }
    }
  }
}

// File Line: 727
// RVA: 0x3F03C0
void __fastcall UFG::CopSystem::ResetChaseStats(UFG::CopSystem *this)
{
  int v2; // ecx
  bool *p_mTracked; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float mSimTime_Temp; // xmm0_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpAmbientSuspect; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpArrestRightHumanCop; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax

  this->mIsExcludingPlayerForRestOfChase = 0;
  this->mInstantCooldownActive = 0;
  this->mIsSafehouseInstantCooldownActive = 0;
  *(_QWORD *)&this->mWaveCount = 0i64;
  *(_WORD *)&this->mHasSpawnedInFrontForCurrentWave = 0;
  this->mNumArrestAttempts = 0;
  UFG::qString::Set(&this->mLastHeatEventCaption, &customCaption);
  this->mLastHeatEventIndex = eHEATEVENT_NONE;
  UFG::EncounterUnitContext::Reset(&this->mFocusTargetContext);
  this->mEnableWaveTimerChangesByDisabledUnits = 1;
  this->mAreRoadBlocksActive = 0;
  this->mRoadBlockCooldownTimestamp = 0.0;
  v2 = 0;
  p_mTracked = &this->mHeatEvents[0].mTracked;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mRoadBlockTriggerOrigin.x = UFG::qVector3::msZero.x;
  this->mRoadBlockTriggerOrigin.y = y;
  this->mRoadBlockTriggerOrigin.z = z;
  do
  {
    *((_DWORD *)p_mTracked + 1) = v2;
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    ++v2;
    *p_mTracked = 1;
    *((float *)p_mTracked - 1) = mSimTime_Temp;
    p_mTracked += 12;
  }
  while ( v2 < 26 );
  p_mpAmbientSuspect = &this->mpAmbientSuspect;
  if ( this->mpAmbientSuspect.m_pPointer )
  {
    mPrev = p_mpAmbientSuspect->mPrev;
    mNext = this->mpAmbientSuspect.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpAmbientSuspect->mPrev = p_mpAmbientSuspect;
    this->mpAmbientSuspect.mNext = &this->mpAmbientSuspect;
  }
  this->mpAmbientSuspect.m_pPointer = 0i64;
  p_mpArrestRightHumanCop = &this->mpArrestRightHumanCop;
  if ( this->mpArrestRightHumanCop.m_pPointer )
  {
    v11 = p_mpArrestRightHumanCop->mPrev;
    v12 = this->mpArrestRightHumanCop.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    p_mpArrestRightHumanCop->mPrev = p_mpArrestRightHumanCop;
    this->mpArrestRightHumanCop.mNext = &this->mpArrestRightHumanCop;
  }
  this->mpArrestRightHumanCop.m_pPointer = 0i64;
  this->mArrestRightTimestamp = 0.0;
  this->mOnFootNoSprintTimer = 0.0;
}

// File Line: 760
// RVA: 0x3F13F0
void __fastcall UFG::CopSystem::UpdateHeatLevel(UFG::CopSystem *this)
{
  UFG::HeatLevelEnum mHeatLevel; // r14d
  UFG::GameStatTracker *v3; // rax
  float Stat; // xmm0_4
  int v5; // ebp
  UFG::GameStatTracker *v6; // rax
  __int64 v7; // rdx
  UFG::qPropertySet *v8; // rax
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  UFG::GameStatTracker *v12; // rax
  UFG::eFactionClassEnum j; // ebx
  UFG::GameStatTracker *v14; // rax
  const char *v15; // rdx
  UFG::GameStatTracker *v16; // rax
  UFG::eFactionClassEnum i; // edi
  UFG::GameStatTracker *v18; // rax
  UFG::eFactionStandingEnum Standing; // ebx
  UFG::GameStatTracker *v20; // rax
  UFG::qString *v21; // rax
  UFG::qString result; // [rsp+38h] [rbp-40h] BYREF

  mHeatLevel = this->mHeatLevel;
  v3 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v3, Heat);
  UFG::PropertySetHandle::Bind(&this->mProperties);
  if ( Stat >= *UFG::qPropertySet::Get<float>(
                  this->mProperties.mpPropSet,
                  (UFG::qArray<unsigned long,0> *)&EncounterSym_threshold_level1,
                  DEPTH_RECURSE) )
  {
    UFG::PropertySetHandle::Bind(&this->mProperties);
    if ( Stat >= *UFG::qPropertySet::Get<float>(
                    this->mProperties.mpPropSet,
                    (UFG::qArray<unsigned long,0> *)&EncounterSym_threshold_level2,
                    DEPTH_RECURSE) )
    {
      UFG::PropertySetHandle::Bind(&this->mProperties);
      if ( Stat >= *UFG::qPropertySet::Get<float>(
                      this->mProperties.mpPropSet,
                      (UFG::qArray<unsigned long,0> *)&EncounterSym_threshold_level3,
                      DEPTH_RECURSE) )
      {
        UFG::PropertySetHandle::Bind(&this->mProperties);
        if ( Stat >= *UFG::qPropertySet::Get<float>(
                        this->mProperties.mpPropSet,
                        (UFG::qArray<unsigned long,0> *)&EncounterSym_threshold_level4,
                        DEPTH_RECURSE) )
        {
          UFG::PropertySetHandle::Bind(&this->mProperties);
          v5 = (Stat >= *UFG::qPropertySet::Get<float>(
                           this->mProperties.mpPropSet,
                           (UFG::qArray<unsigned long,0> *)&EncounterSym_threshold_level5,
                           DEPTH_RECURSE))
             + 4;
        }
        else
        {
          v5 = 3;
        }
      }
      else
      {
        v5 = 2;
      }
    }
    else
    {
      v5 = 1;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 == mHeatLevel )
    return;
  UFG::CopSystem::UpdateTelemetryStatsNewLevel(this, mHeatLevel, (UFG::HeatLevelEnum)v5);
  this->mCurrentWaveType.mUID = this->mHeatLevelPropertiesName[v5].mUID;
  this->mHeatLevel = v5;
  this->mHeatLevelTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
  v6 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStatHigh(v6, HighestHeatLevel, v5);
  if ( v5 )
  {
    if ( v5 > mHeatLevel )
    {
      this->mWaveCount = 0;
      this->mHasSpawnedInFrontForCurrentWave = 0;
      ((void (__fastcall *)(UFG::CopSystem *))this->vfptr[23].__vecDelDtor)(this);
    }
    if ( mHeatLevel )
      goto LABEL_33;
    this->mStartTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    v16 = UFG::FactionInterface::Get();
    UFG::FactionInterface::SetStanding(&v16->mFactionInterface, FACTION_PLAYER, FACTION_LAW, FACTIONSTANDING_HOSTILE);
    for ( i = FACTION_INVALID; (unsigned int)i < NUM_FACTIONS; ++i )
    {
      if ( (unsigned int)(i - 2) > 1 && i != FACTION_LAW_HOSTILE )
      {
        v18 = UFG::FactionInterface::Get();
        Standing = (unsigned int)UFG::FactionInterface::GetStanding(&v18->mFactionInterface, FACTION_PLAYER, i);
        v20 = UFG::FactionInterface::Get();
        UFG::FactionInterface::SetStanding(&v20->mFactionInterface, FACTION_LAW, i, Standing);
      }
    }
    if ( this->mLastHeatEventIndex == eHEATEVENT_NONE )
      goto LABEL_33;
    v15 = "Begin_Pursuit";
  }
  else
  {
    ((void (__fastcall *)(UFG::CopSystem *))this->vfptr[120].__vecDelDtor)(this);
    if ( (unsigned __int8)UFG::CopSystem::IsPlayerInsideUnlockedSafehouse(this, 0i64) )
    {
      LOBYTE(v7) = 1;
      this->vfptr[3].__vecDelDtor(this, v7);
    }
    v8 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[33].__vecDelDtor)(this);
    v9 = *UFG::qPropertySet::Get<float>(v8, (UFG::qArray<unsigned long,0> *)&EncounterSym_heatwave_timer, DEPTH_RECURSE);
    v10 = UFG::qRandom(v9, (unsigned int *)&UFG::qDefaultSeed);
    v11 = FLOAT_60_0;
    if ( v10 >= 60.0 )
      v11 = v10;
    this->mWaveTimer = v11;
    v12 = UFG::FactionInterface::Get();
    UFG::FactionInterface::SetStanding(
      &v12->mFactionInterface,
      FACTION_PLAYER,
      FACTION_LAW,
      FACTIONSTANDING_INDIFFERENT);
    for ( j = FACTION_INVALID; (unsigned int)j < NUM_FACTIONS; ++j )
    {
      if ( j != FACTION_LAW && j != FACTION_LAW_HOSTILE )
      {
        v14 = UFG::FactionInterface::Get();
        UFG::FactionInterface::SetStanding(&v14->mFactionInterface, FACTION_LAW, j, FACTIONSTANDING_INDIFFERENT);
      }
    }
    this->mStartTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    v15 = "End_Pursuit";
  }
  UFG::PoliceScannerAudio::PlayScenario(&UFG::PoliceScannerAudio::sm_Instance, v15);
LABEL_33:
  ((void (__fastcall *)(UFG::CopSystem *))this->vfptr[50].__vecDelDtor)(this);
  UFG::GameStatAction::Player::NotifyHeatLevelChange(mHeatLevel, (UFG::HeatLevelEnum)v5);
  ((void (__fastcall *)(UFG::CopSystem *, _QWORD, _QWORD))this->vfptr[115].__vecDelDtor)(
    this,
    (unsigned int)mHeatLevel,
    (unsigned int)v5);
  if ( this->mEnable && this->mDebugDrawLevel > 0 )
  {
    v21 = UFG::qString::FormatEx(&result, "DEBUG: Heat level changed to (%d)!", (unsigned int)v5);
    UFG::qString::Set(&this->mLastHeatEventCaption, v21->mData, v21->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
    UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Cops, OUTPUT_LEVEL_DEBUG, "[CopSystem]: %s\n");
  }
}

// File Line: 888
// RVA: 0x3EEF50
void __fastcall UFG::CopSystem::HandleOnFootSpawnPost(UFG::CopSystem *this, UFG::SimObjectGame *pOnFootSpawn)
{
  signed __int16 m_Flags; // dx
  UFG::StimulusReceiverComponent *m_pComponent; // rsi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  int v7; // ebx
  bool *mStimulusWatchList; // rdi

  UFG::EncounterBase::HandleOnFootSpawnPost(this, pOnFootSpawn);
  if ( pOnFootSpawn )
  {
    m_Flags = pOnFootSpawn->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StimulusReceiverComponent *)pOnFootSpawn->m_Components.p[11].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              pOnFootSpawn,
                              UFG::StimulusReceiverComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(pOnFootSpawn, UFG::StimulusReceiverComponent::_TypeUID);
      m_pComponent = (UFG::StimulusReceiverComponent *)ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = (UFG::StimulusReceiverComponent *)pOnFootSpawn->m_Components.p[11].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = 0;
      mStimulusWatchList = this->mStimulusWatchList;
      do
      {
        if ( *mStimulusWatchList )
          UFG::StimulusReceiverComponent::RequestToReceiveStimulus(m_pComponent, v7);
        ++v7;
        ++mStimulusWatchList;
      }
      while ( v7 < 116 );
    }
  }
}

// File Line: 916
// RVA: 0x3EF3D0
bool __fastcall UFG::CopSystem::IsCharacterInUseHeuristic(
        UFG::CopSystem *this,
        UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObject *m_pSimObject; // rbx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax

  m_pSimObject = pEncounterUnitComponent->m_pSimObject;
  if ( !m_pSimObject )
    return UFG::EncounterBase::IsCharacterInUseHeuristic(this, pEncounterUnitComponent);
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[17].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                     (UFG::SimObjectGame *)m_pSimObject,
                     UFG::CopUnitComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CopUnitComponent::_TypeUID);
  }
  else
  {
    m_pComponent = m_pSimObject->m_Components.p[17].m_pComponent;
  }
  if ( !m_pComponent || (m_pComponent[7].m_Flags & 2) != 0 )
    return UFG::EncounterBase::IsCharacterInUseHeuristic(this, pEncounterUnitComponent);
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_pSimObject->m_Name);
  UFG::qPrintChannel::Print(
    &UFG::gPrintChannel_HK_Cops,
    OUTPUT_LEVEL_DEBUG,
    "[CopSystem]: This character (%s) is no longer usable by the cop system!\n");
  return 0;
}

// File Line: 933
// RVA: 0x3EFA70
char __fastcall UFG::CopSystem::Reacquire(
        UFG::CopSystem *this,
        UFG::EncounterUnit::UnitType unitType,
        UFG::SimObject *pPlayer,
        UFG::TransformNodeComponent *pPlayerTransform,
        UFG::SimObject **pExisting)
{
  bool v7; // cf
  char *p_mNext; // rbp
  bool i; // zf
  __int64 v10; // r15
  char v11; // al
  UFG::SimObjectGame *v12; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  __int16 m_Flags; // cx
  UFG::EncounterUnitComponent *m_pComponent; // rsi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::EncounterUnitComponent *v19; // rax
  __int16 v20; // cx
  unsigned int v21; // edi
  __int16 v22; // cx
  UFG::CharacterOccupantComponent *v23; // rax
  UFG::VehicleOccupantComponent *v24; // rax
  UFG::qSafePointerNode<UFG::SimObject>Vtbl *vfptr; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObjectGame *Texture; // rax
  __int16 v28; // dx
  UFG::SimComponent *v29; // rax
  UFG::PedSpawnManager *Instance; // rax
  __int16 v31; // cx
  UFG::TargetingSystemBaseComponent *v32; // rax
  __int16 v33; // cx
  UFG::SimComponent *v34; // rax
  __int16 v35; // cx
  UFG::StreamedResourceComponent *v36; // rdi
  UFG::SimComponent *v37; // rax
  __int16 v38; // cx
  UFG::CharacterOccupantComponent *v39; // rax
  UFG::TransformNodeComponent *CurrentVehicle; // rax
  UFG::SimObjectModifier v42; // [rsp+40h] [rbp-48h] BYREF
  UFG::qSymbol symbol; // [rsp+98h] [rbp+10h] BYREF

  if ( unitType == F5_1Pt2_512 )
    v7 = this->mHumans.size < 0x20;
  else
    v7 = this->mVehicles.size < 8;
  if ( v7 )
  {
    p_mNext = (char *)&UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mNext[-5].mNext;
    for ( i = &UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mNext[-5].mNext == (UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> **)((char *)&UFG::CopUnitComponent::s_CopUnitComponentList - 72);
          ;
          i = v10 == (_QWORD)&UFG::CopUnitComponent::s_CopUnitComponentList - 72 )
    {
      if ( i )
        return 0;
      v10 = *((_QWORD *)p_mNext + 10) - 72i64;
      if ( *((_DWORD *)p_mNext + 119) == unitType )
      {
        v11 = p_mNext[480];
        if ( (v11 & 2) != 0 && (v11 & 8) != 0 && (v11 & 1) == 0 )
        {
          v12 = (UFG::SimObjectGame *)*((_QWORD *)p_mNext + 5);
          if ( v12 )
          {
            m_pTransformNodeComponent = v12->m_pTransformNodeComponent;
            if ( m_pTransformNodeComponent )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v12->m_pTransformNodeComponent);
              if ( !this->vfptr[58].__vecDelDtor(this, &m_pTransformNodeComponent->mWorldTransform.v3)
                && (this->vfptr[47].__vecDelDtor(this, v12) || (p_mNext[480] & 0x10) != 0) )
              {
                m_Flags = v12->m_Flags;
                if ( (m_Flags & 0x4000) != 0 )
                {
                  m_pComponent = (UFG::EncounterUnitComponent *)v12->m_Components.p[16].m_pComponent;
                }
                else if ( m_Flags >= 0 )
                {
                  if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
                    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                          v12,
                                          UFG::EncounterUnitComponent::_TypeUID);
                  else
                    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v12, UFG::EncounterUnitComponent::_TypeUID);
                  m_pComponent = (UFG::EncounterUnitComponent *)ComponentOfTypeHK;
                }
                else
                {
                  m_pComponent = (UFG::EncounterUnitComponent *)v12->m_Components.p[16].m_pComponent;
                }
                if ( !m_pComponent )
                {
                  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
                  v18 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xE0ui64, "EncounterUnitComponent", 0i64, 1u);
                  if ( v18 )
                  {
                    UFG::EncounterUnitComponent::EncounterUnitComponent(
                      (UFG::EncounterUnitComponent *)v18,
                      v12->mNode.mUID);
                    m_pComponent = v19;
                  }
                  else
                  {
                    m_pComponent = 0i64;
                  }
                  v20 = v12->m_Flags;
                  if ( (v20 & 0x4000) != 0 )
                  {
                    v21 = 16;
                  }
                  else if ( v20 >= 0 )
                  {
                    v21 = -1;
                  }
                  else
                  {
                    v21 = 16;
                  }
                  UFG::SimObjectModifier::SimObjectModifier(&v42, v12, 1);
                  UFG::SimObjectModifier::AttachComponent(&v42, m_pComponent, v21);
                  UFG::SimObjectModifier::Close(&v42);
                  UFG::SimObjectModifier::~SimObjectModifier(&v42);
                }
                if ( this->vfptr[78].__vecDelDtor(this, m_pComponent) )
                {
                  v22 = v12->m_Flags;
                  if ( unitType != F5_1Pt2_512 )
                  {
                    if ( (v22 & 0x4000) != 0 )
                      goto LABEL_56;
                    if ( v22 >= 0 )
                    {
                      if ( (v22 & 0x2000) != 0 || (v22 & 0x1000) != 0 )
LABEL_56:
                        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(
                                            v12,
                                            UFG::VehicleOccupantComponent::_TypeUID);
                      else
                        ComponentOfType = UFG::SimObject::GetComponentOfType(
                                            v12,
                                            UFG::VehicleOccupantComponent::_TypeUID);
                    }
                    else
                    {
                      ComponentOfType = v12->m_Components.p[30].m_pComponent;
                    }
                    if ( !ComponentOfType )
                      goto LABEL_91;
                    Texture = (UFG::SimObjectGame *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)ComponentOfType);
                    if ( Texture )
                    {
                      v28 = Texture->m_Flags;
                      if ( (v28 & 0x4000) != 0 )
                      {
                        v29 = Texture->m_Components.p[17].m_pComponent;
                      }
                      else if ( v28 >= 0 )
                      {
                        v29 = (v28 & 0x2000) != 0 || (v28 & 0x1000) != 0
                            ? UFG::SimObjectGame::GetComponentOfTypeHK(Texture, UFG::CopUnitComponent::_TypeUID)
                            : UFG::SimObject::GetComponentOfType(Texture, UFG::CopUnitComponent::_TypeUID);
                      }
                      else
                      {
                        v29 = Texture->m_Components.p[17].m_pComponent;
                      }
                      if ( v29 && (v29[7].m_Flags & 1) != 0 )
                        goto LABEL_91;
                    }
                    goto LABEL_70;
                  }
                  if ( (v22 & 0x4000) != 0 )
                  {
                    v23 = (UFG::CharacterOccupantComponent *)v12->m_Components.p[44].m_pComponent;
                  }
                  else if ( v22 < 0 || (v22 & 0x2000) != 0 || (v22 & 0x1000) != 0 )
                  {
                    v23 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               v12,
                                                               UFG::CharacterOccupantComponent::_TypeUID);
                  }
                  else
                  {
                    v23 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                               v12,
                                                               UFG::CharacterOccupantComponent::_TypeUID);
                  }
                  if ( !v23
                    || (v24 = UFG::CharacterOccupantComponent::GetCurrentVehicle(v23)) == 0i64
                    || (vfptr = v24->mpDriver.m_pPointer[2].vfptr) == 0i64
                    || !HIBYTE(vfptr[17].__vecDelDtor) )
                  {
                    UFG::PedSpawnManager::AquireOwnership(v12, 0, 1, -1);
                    Instance = UFG::PedSpawnManager::GetInstance();
                    UFG::PedSpawnManager::SetSuspendOption(Instance, v12, NoSuspend);
                    if ( this->mIsExcludingPlayerForRestOfChase )
                    {
                      v31 = v12->m_Flags;
                      if ( (v31 & 0x4000) != 0 )
                      {
                        v32 = (UFG::TargetingSystemBaseComponent *)v12->m_Components.p[20].m_pComponent;
                      }
                      else if ( v31 >= 0 )
                      {
                        if ( (v31 & 0x2000) != 0 || (v31 & 0x1000) != 0 )
                          v32 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v12,
                                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
                        else
                          v32 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                       v12,
                                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
                      }
                      else
                      {
                        v32 = (UFG::TargetingSystemBaseComponent *)v12->m_Components.p[20].m_pComponent;
                      }
                      if ( v32 )
                        UFG::TargetingSystemBaseComponent::ClearTarget(v32, eTARGET_TYPE_AI_OBJECTIVE);
                      v33 = v12->m_Flags;
                      if ( (v33 & 0x4000) != 0 )
                      {
                        v34 = v12->m_Components.p[6].m_pComponent;
                      }
                      else if ( v33 >= 0 )
                      {
                        if ( (v33 & 0x2000) != 0 || (v33 & 0x1000) != 0 )
                          v34 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::HealthComponent::_TypeUID);
                        else
                          v34 = UFG::SimObject::GetComponentOfType(v12, UFG::HealthComponent::_TypeUID);
                      }
                      else
                      {
                        v34 = v12->m_Components.p[6].m_pComponent;
                      }
                      BYTE6(v34[1].m_BoundComponentHandles.mNode.mPrev) = 0;
                    }
LABEL_91:
                    v35 = v12->m_Flags;
                    if ( (v35 & 0x4000) != 0 )
                    {
                      v36 = (UFG::StreamedResourceComponent *)v12->m_Components.p[10].m_pComponent;
                    }
                    else if ( v35 >= 0 )
                    {
                      if ( (v35 & 0x2000) != 0 )
                      {
                        v36 = (UFG::StreamedResourceComponent *)v12->m_Components.p[7].m_pComponent;
                      }
                      else
                      {
                        if ( (v35 & 0x1000) != 0 )
                          v37 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::StreamedResourceComponent::_TypeUID);
                        else
                          v37 = UFG::SimObject::GetComponentOfType(v12, UFG::StreamedResourceComponent::_TypeUID);
                        v36 = (UFG::StreamedResourceComponent *)v37;
                      }
                    }
                    else
                    {
                      v36 = (UFG::StreamedResourceComponent *)v12->m_Components.p[10].m_pComponent;
                    }
                    if ( v36 )
                    {
                      symbol.mUID = v36->mActivePriority.mUID;
                      UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(v36, &qSymbol_Critical);
                      UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(v36, &symbol);
                    }
                    p_mNext[480] = p_mNext[480] & 0xFA | 1;
                    if ( *((_QWORD *)p_mNext + 20) )
                    {
                      this->mVehicles.p[this->mVehicles.size++] = m_pComponent;
                    }
                    else
                    {
                      v38 = v12->m_Flags;
                      if ( (v38 & 0x4000) != 0 )
                      {
                        v39 = (UFG::CharacterOccupantComponent *)v12->m_Components.p[44].m_pComponent;
                      }
                      else if ( v38 < 0 || (v38 & 0x2000) != 0 || (v38 & 0x1000) != 0 )
                      {
                        v39 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   v12,
                                                                   UFG::CharacterOccupantComponent::_TypeUID);
                      }
                      else
                      {
                        v39 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                   v12,
                                                                   UFG::CharacterOccupantComponent::_TypeUID);
                      }
                      if ( v39 )
                      {
                        CurrentVehicle = (UFG::TransformNodeComponent *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v39);
                        if ( CurrentVehicle )
                        {
                          UFG::EncounterUnitComponent::SetGroupVehicle((SkeletalPose *)m_pComponent, CurrentVehicle);
                          UFG::EncounterUnitComponent::IncrementGroupVehicleUsageCount(m_pComponent);
                        }
                      }
                      this->mHumans.p[this->mHumans.size++] = m_pComponent;
                    }
                    ((void (__fastcall *)(UFG::CopSystem *, UFG::EncounterUnitComponent *, _QWORD))this->vfptr[69].__vecDelDtor)(
                      this,
                      m_pComponent,
                      0i64);
                    *pExisting = (UFG::SimObject *)*((_QWORD *)p_mNext + 5);
                    return 1;
                  }
                }
              }
            }
          }
        }
      }
LABEL_70:
      p_mNext = (char *)v10;
    }
  }
  return 0;
}

// File Line: 1073
// RVA: 0x3F1AA0
void __fastcall UFG::CopSystem::UpdateRoadBlocks(UFG::CopSystem *this)
{
  __int64 v2; // rax
  UFG::TransformNodeComponent *v3; // r14
  char mAreRoadBlocksActive; // si
  UFG::qVector3 *v5; // r14
  float v6; // xmm6_4
  float v7; // xmm7_4
  float *v8; // rax
  UFG::qPropertySet *v9; // rax
  float v10; // xmm1_4
  bool v11; // al
  float y; // xmm0_4
  float z; // xmm1_4
  char v14; // al
  char v15; // bp
  float *v16; // rax
  float v17; // xmm6_4
  float *v18; // rax
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *p_mNode; // rcx
  float v20; // xmm7_4
  UFG::qList<UFG::CopRoadBlock,UFG::CopRoadBlock,1,0> *v21; // rbx
  UFG::CopRoadBlock *v22; // rcx
  UFG::qList<UFG::CopRoadBlock,UFG::CopRoadBlock,1,0> *v23; // rbx
  int pBitfields; // [rsp+70h] [rbp+8h] BYREF

  v2 = ((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[18].__vecDelDtor)(this);
  if ( !v2 )
    return;
  v3 = *(UFG::TransformNodeComponent **)(v2 + 88);
  if ( !v3 )
    return;
  UFG::TransformNodeComponent::UpdateWorldTransform(v3);
  mAreRoadBlocksActive = this->mAreRoadBlocksActive;
  v5 = (UFG::qVector3 *)&v3->mWorldTransform.v3;
  if ( mAreRoadBlocksActive )
  {
    v6 = this->mRoadBlockTriggerOrigin.x - v5->x;
    v7 = this->mRoadBlockTriggerOrigin.y - v5->y;
    UFG::PropertySetHandle::Bind(&this->mProperties);
    v8 = UFG::qPropertySet::Get<float>(
           this->mProperties.mpPropSet,
           (UFG::qArray<unsigned long,0> *)&CopSym_roadblock_escape_radius,
           DEPTH_RECURSE);
    if ( (float)((float)(v7 * v7) + (float)(v6 * v6)) > (float)(*v8 * *v8) )
    {
      this->mAreRoadBlocksActive = 0;
      this->mRoadBlockCooldownTimestamp = UFG::Metrics::msInstance.mSimTime_Temp;
    }
  }
  v9 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[33].__vecDelDtor)(this);
  v10 = *UFG::qPropertySet::Get<float>(v9, (UFG::qArray<unsigned long,0> *)&CopSym_roadblock_frequency, DEPTH_RECURSE);
  v11 = v10 >= 0.0;
  if ( this->mFocusTargetContext.mIsInWater || this->mFocusTargetContext.mIsInsideInterior )
  {
    v11 = 0;
  }
  else if ( v10 >= 0.0 )
  {
    goto LABEL_12;
  }
  this->mAreRoadBlocksActive = 0;
  this->mRoadBlockCooldownTimestamp = UFG::Metrics::msInstance.mSimTime_Temp;
LABEL_12:
  if ( !mAreRoadBlocksActive
    && v11
    && (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->mRoadBlockCooldownTimestamp) > v10 )
  {
    this->mAreRoadBlocksActive = 1;
    y = v5->y;
    z = v5->z;
    this->mRoadBlockTriggerOrigin.x = v5->x;
    this->mRoadBlockTriggerOrigin.y = y;
    this->mRoadBlockTriggerOrigin.z = z;
  }
  v14 = this->mAreRoadBlocksActive;
  if ( mAreRoadBlocksActive != v14 )
  {
    if ( v14 )
    {
      v15 = 0;
      pBitfields = 0;
      UFG::PropertySetHandle::Bind(&this->mProperties);
      v16 = UFG::qPropertySet::Get<float>(
              this->mProperties.mpPropSet,
              (UFG::qArray<unsigned long,0> *)&CopSym_roadblock_spawn_min_radius,
              DEPTH_RECURSE);
      v17 = *v16 * *v16;
      UFG::PropertySetHandle::Bind(&this->mProperties);
      v18 = UFG::qPropertySet::Get<float>(
              this->mProperties.mpPropSet,
              (UFG::qArray<unsigned long,0> *)&CopSym_roadblock_spawn_max_radius,
              DEPTH_RECURSE);
      p_mNode = UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mNext - 7;
      v20 = *v18 * *v18;
      if ( (UFG::qList<UFG::CopRoadBlock,UFG::CopRoadBlock,1,0> *)&UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mNext[-7] == &UFG::CopRoadBlock::s_CopRoadBlockList - 7 )
        goto LABEL_23;
      do
      {
        v21 = (UFG::qList<UFG::CopRoadBlock,UFG::CopRoadBlock,1,0> *)&p_mNode[7].mNext[-7];
        if ( ((__int64)p_mNode[2].mPrev & 3) == 1 )
          v15 |= UFG::CopRoadBlock::ActivateByDistance((UFG::CopRoadBlock *)p_mNode, v5, v17, v20, &pBitfields);
        p_mNode = &v21->mNode;
      }
      while ( v21 != &UFG::CopRoadBlock::s_CopRoadBlockList - 7 );
      if ( !v15 )
LABEL_23:
        this->mAreRoadBlocksActive = 0;
    }
    else
    {
      v22 = (UFG::CopRoadBlock *)&UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mNext[-7];
      if ( (UFG::qList<UFG::CopRoadBlock,UFG::CopRoadBlock,1,0> *)&UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mNext[-7] != &UFG::CopRoadBlock::s_CopRoadBlockList - 7 )
      {
        do
        {
          v23 = (UFG::qList<UFG::CopRoadBlock,UFG::CopRoadBlock,1,0> *)&v22->mNext[-7];
          UFG::CopRoadBlock::Deactivate(v22);
          v22 = (UFG::CopRoadBlock *)v23;
        }
        while ( v23 != &UFG::CopRoadBlock::s_CopRoadBlockList - 7 );
      }
    }
  }
}

// File Line: 1172
// RVA: 0x3ED930
float __fastcall UFG::CopSystem::GetHeatRadius(
        UFG::CopSystem *this,
        bool isOnfoot,
        UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::qStaticSymbol *v7; // rbx
  UFG::qPropertySet *v8; // rax
  float v9; // xmm6_4
  float mInsideRadiusTimer; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4

  if ( !((unsigned int (__fastcall *)(UFG::CopSystem *))this->vfptr[89].__vecDelDtor)(this) )
    return sCopSystem_WitnessRadius;
  if ( this->mInstantCooldownActive || this->mIsSafehouseInstantCooldownActive )
  {
    v9 = 0.0;
  }
  else
  {
    v7 = &EncounterSym_heat_radius_vehicle;
    if ( isOnfoot )
      v7 = &EncounterSym_heat_radius_onfoot;
    v8 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[33].__vecDelDtor)(this);
    v9 = *UFG::qPropertySet::Get<float>(v8, (UFG::qArray<unsigned long,0> *)v7, DEPTH_RECURSE);
  }
  if ( pEncounterUnitComponent )
  {
    mInsideRadiusTimer = pEncounterUnitComponent->mInsideRadiusTimer;
    if ( mInsideRadiusTimer < 0.0 || (v11 = pEncounterUnitComponent->mAcquiredTimer - mInsideRadiusTimer, v11 <= 0.0) )
    {
      v11 = 0.0;
    }
    else
    {
      v12 = *(float *)&FLOAT_1_0;
      if ( v11 >= 1.0 )
        goto LABEL_16;
    }
    v12 = v11;
LABEL_16:
    v9 = v9 * (float)((float)(v12 * 0.60000002) + 0.40000001);
  }
  if ( ((unsigned __int8 (__fastcall *)(UFG::CopSystem *))this->vfptr[16].__vecDelDtor)(this) )
    return v9 * this->mReducedRadiusPercentage;
  return v9;
}

// File Line: 1200
// RVA: 0x3ED690
float __fastcall UFG::CopSystem::GetCurrentHeatLevelElapsedTime(UFG::CopSystem *this)
{
  float v1; // xmm0_4

  v1 = (float)(LODWORD(UFG::Metrics::msInstance.mSimTimeMSec) - LODWORD(this->mHeatLevelTimestamp));
  if ( (__int64)(UFG::Metrics::msInstance.mSimTimeMSec - this->mHeatLevelTimestamp) < 0 )
    v1 = v1 + 1.8446744e19;
  return v1 * 0.001;
}

// File Line: 1207
// RVA: 0x3F0780
void __fastcall UFG::CopSystem::TriggerOnFootNoSprint(UFG::CopSystem *this)
{
  if ( ((int (__fastcall *)(UFG::CopSystem *))this->vfptr[89].__vecDelDtor)(this) > 0 )
  {
    UFG::PropertySetHandle::Bind(&this->mProperties);
    this->mOnFootNoSprintTimer = *UFG::qPropertySet::Get<float>(
                                    this->mProperties.mpPropSet,
                                    (UFG::qArray<unsigned long,0> *)&EncounterSym_success_vault_no_sprint_timer,
                                    DEPTH_RECURSE);
  }
}

// File Line: 1215
// RVA: 0x3EF510
char __fastcall UFG::CopSystem::IsOnFootNoSprintActive(UFG::CopSystem *this)
{
  char result; // al

  if ( this->mOnFootNoSprintTimer > 0.0 )
    return 1;
  result = ((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[16].__vecDelDtor)(this);
  if ( result )
    return 1;
  return result;
}

// File Line: 1220
// RVA: 0x3EDA60
float __fastcall UFG::CopSystem::GetHeatThresholdByLevel(UFG::CopSystem *this, int heatLevel)
{
  UFG::PropertySetHandle *v2; // rbx
  float result; // xmm0_4
  UFG::PropertySetHandle *v4; // rbx
  UFG::PropertySetHandle *v5; // rbx
  UFG::PropertySetHandle *v6; // rbx
  UFG::PropertySetHandle *p_mProperties; // rbx

  switch ( heatLevel )
  {
    case -1:
    case 5:
      p_mProperties = &this->mProperties;
      UFG::PropertySetHandle::Bind(&this->mProperties);
      result = *UFG::qPropertySet::Get<float>(
                  p_mProperties->mpPropSet,
                  (UFG::qArray<unsigned long,0> *)&EncounterSym_threshold_level5,
                  DEPTH_RECURSE);
      break;
    case 1:
      v2 = &this->mProperties;
      UFG::PropertySetHandle::Bind(&this->mProperties);
      result = *UFG::qPropertySet::Get<float>(
                  v2->mpPropSet,
                  (UFG::qArray<unsigned long,0> *)&EncounterSym_threshold_level1,
                  DEPTH_RECURSE);
      break;
    case 2:
      v4 = &this->mProperties;
      UFG::PropertySetHandle::Bind(&this->mProperties);
      result = *UFG::qPropertySet::Get<float>(
                  v4->mpPropSet,
                  (UFG::qArray<unsigned long,0> *)&EncounterSym_threshold_level2,
                  DEPTH_RECURSE);
      break;
    case 3:
      v5 = &this->mProperties;
      UFG::PropertySetHandle::Bind(&this->mProperties);
      result = *UFG::qPropertySet::Get<float>(
                  v5->mpPropSet,
                  (UFG::qArray<unsigned long,0> *)&EncounterSym_threshold_level3,
                  DEPTH_RECURSE);
      break;
    case 4:
      v6 = &this->mProperties;
      UFG::PropertySetHandle::Bind(&this->mProperties);
      result = *UFG::qPropertySet::Get<float>(
                  v6->mpPropSet,
                  (UFG::qArray<unsigned long,0> *)&EncounterSym_threshold_level4,
                  DEPTH_RECURSE);
      break;
    default:
      result = 0.0;
      break;
  }
  return result;
}

// File Line: 1237
// RVA: 0x3F0550
void __fastcall UFG::CopSystem::SetHeatLevel(UFG::CopSystem *this, __int64 heatLevel, UFG::eHeatEventEnum heatEvent)
{
  int mMaxHeatLevel; // eax
  double v6; // xmm0_8
  UFG::GameStatTracker *v7; // rax

  mMaxHeatLevel = this->mMaxHeatLevel;
  if ( mMaxHeatLevel != -1 && mMaxHeatLevel < (int)heatLevel )
    heatLevel = (unsigned int)mMaxHeatLevel;
  v6 = ((double (__fastcall *)(UFG::CopSystem *, __int64))this->vfptr[87].__vecDelDtor)(this, heatLevel);
  this->mLastHeatEventIndex = heatEvent;
  UFG::PropertySetHandle::Bind(&this->mProperties);
  this->mLastHeatEventTimer = *UFG::qPropertySet::Get<float>(
                                 this->mProperties.mpPropSet,
                                 (UFG::qArray<unsigned long,0> *)&EncounterSym_last_heat_event_timer,
                                 DEPTH_RECURSE);
  v7 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v7, Heat, *(float *)&v6);
  this->mCooldownAllowed = 0;
}

// File Line: 1259
// RVA: 0x3EF4C0
_BOOL8 __fastcall UFG::EncounterBase::IsCoolingDown(UFG::CopSystem *this)
{
  return this->mCoolingDown;
}

// File Line: 1264
// RVA: 0x3F0770
void __fastcall UFG::EncounterBase::TriggerInstantCooldown(UFG::CopSystem *this)
{
  this->mInstantCooldownActive = 1;
}

// File Line: 1269
// RVA: 0x3ED860
float __fastcall UFG::CopSystem::GetHeatLevelPercentage(UFG::CopSystem *this)
{
  UFG::GameStatTracker *v2; // rax
  float Stat; // xmm6_4
  double v4; // xmm0_8
  __int64 v5; // rdx
  __int32 v6; // eax
  float v7; // xmm7_4
  float v8; // xmm0_4

  v2 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v2, Heat);
  v4 = ((double (__fastcall *)(UFG::CopSystem *, _QWORD))this->vfptr[87].__vecDelDtor)(
         this,
         (unsigned int)this->mHeatLevel);
  v5 = 5i64;
  v6 = this->mHeatLevel + 1;
  v7 = *(float *)&v4;
  if ( v6 < 5 )
    v5 = (unsigned int)v6;
  v8 = ((float (__fastcall *)(UFG::CopSystem *, __int64))this->vfptr[87].__vecDelDtor)(this, v5) - *(float *)&v4;
  if ( v8 > 0.0 )
    return (float)(Stat - v7) / v8;
  else
    return *(float *)&FLOAT_1_0;
}

// File Line: 1284
// RVA: 0x14D6F60
__int64 UFG::_dynamic_initializer_for__gSafeHouseSymbol_SFAB__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("SFAB-AB", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSafeHouseSymbol_SFAB, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSafeHouseSymbol_SFAB__);
}

// File Line: 1285
// RVA: 0x14D6FA0
__int64 UFG::_dynamic_initializer_for__gSafeHouseSymbol_SFCT__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("SFCT-CT", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSafeHouseSymbol_SFCT, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSafeHouseSymbol_SFCT__);
}

// File Line: 1286
// RVA: 0x14D6FE0
__int64 UFG::_dynamic_initializer_for__gSafeHouseSymbol_SFKT__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("SFKT-KT", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSafeHouseSymbol_SFKT, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSafeHouseSymbol_SFKT__);
}

// File Line: 1287
// RVA: 0x14D7020
__int64 UFG::_dynamic_initializer_for__gSafeHouseSymbol_SFNP__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("SFNP-NP", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSafeHouseSymbol_SFNP, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSafeHouseSymbol_SFNP__);
}

// File Line: 1290
// RVA: 0x3EF540
UFG::UIHKScreenHud *__fastcall UFG::CopSystem::IsPlayerInsideUnlockedSafehouse(
        UFG::CopSystem *this,
        bool *pIsFullyInside)
{
  UFG::UIHKScreenHud *result; // rax
  UFG::eInteriors mActiveInterior; // ebx
  bool Stat; // si
  UFG::GameStatTracker *v6; // rax
  UFG::GameStatTracker *v7; // rax
  UFG::GameStatTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimObjectCharacterPropertiesComponent *v11; // rax
  bool v12; // al
  unsigned int v13; // eax
  UFG::qStaticSymbol *v14; // rdx
  unsigned int v15; // eax
  unsigned int v16; // eax
  UFG::SimObjectGame *SimObject; // rax
  __int16 m_Flags; // dx
  UFG::DoorComponent *ComponentOfTypeHK; // rax

  result = UFG::UIHKScreenHud::getInstance();
  if ( result )
  {
    UFG::UIHKScreenHud::getInstance();
    mActiveInterior = UFG::UIHKScreenHud::mInteriorManager->mActiveInterior;
    Stat = 0;
    switch ( mActiveInterior )
    {
      case INTERIOR_BAMBAM:
      case INTERIOR_PENDREWHQ:
      case INTERIOR_KARAOKE:
      case INTERIOR_GAMBLINGDENCT:
      case INTERIOR_GAMBLINGDENNP:
        Stat = 1;
        break;
      case INTERIOR_SAFEHOUSEAB:
        v6 = UFG::GameStatTracker::Instance();
        Stat = UFG::GameStatTracker::GetStat(v6, Collectible_Safehouse, &UFG::gSafeHouseSymbol_SFAB);
        break;
      case INTERIOR_SAFEHOUSECT:
        v7 = UFG::GameStatTracker::Instance();
        Stat = UFG::GameStatTracker::GetStat(v7, Collectible_Safehouse, &UFG::gSafeHouseSymbol_SFCT);
        break;
      case INTERIOR_SAFEHOUSEKT:
        v8 = UFG::GameStatTracker::Instance();
        Stat = UFG::GameStatTracker::GetStat(v8, Collectible_Safehouse, &UFG::gSafeHouseSymbol_SFKT);
        break;
      case INTERIOR_SAFEHOUSENP:
        v9 = UFG::GameStatTracker::Instance();
        Stat = UFG::GameStatTracker::GetStat(v9, Collectible_Safehouse, &UFG::gSafeHouseSymbol_SFNP);
        break;
      default:
        break;
    }
    if ( !pIsFullyInside )
      return (UFG::UIHKScreenHud *)Stat;
    if ( mActiveInterior != INTERIOR_PENDREWHQ )
    {
      if ( mActiveInterior == INTERIOR_SAFEHOUSEAB )
      {
        if ( (_S12_3 & 1) == 0 )
        {
          _S12_3 |= 1u;
          v13 = UFG::qStringHash32("LOI_AB_SHDoor001_101", 0xFFFFFFFF);
          UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sABSafeHouse, v13);
          atexit(UFG::CopSystem::IsPlayerInsideUnlockedSafehouse_::_22_::_dynamic_atexit_destructor_for__sABSafeHouse__);
        }
        v14 = &sABSafeHouse;
LABEL_30:
        SimObject = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, v14);
        if ( SimObject )
        {
          m_Flags = SimObject->m_Flags;
          if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = (UFG::DoorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        SimObject,
                                                        UFG::DoorComponent::_TypeUID);
          else
            ComponentOfTypeHK = (UFG::DoorComponent *)UFG::SimObject::GetComponentOfType(
                                                        SimObject,
                                                        UFG::DoorComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = 0i64;
        }
        if ( ComponentOfTypeHK )
        {
          *pIsFullyInside = !UFG::DoorComponent::IsOpen(ComponentOfTypeHK);
          return (UFG::UIHKScreenHud *)Stat;
        }
LABEL_41:
        *pIsFullyInside = 1;
        return (UFG::UIHKScreenHud *)Stat;
      }
      if ( mActiveInterior != INTERIOR_SAFEHOUSEKT )
      {
        if ( (unsigned int)(mActiveInterior - 22) > 1 )
        {
          v12 = 0;
          if ( UFG::GetLocalPlayer() )
          {
            LocalPlayer = UFG::GetLocalPlayer();
            v11 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(LocalPlayer);
            if ( v11 )
            {
              if ( (v11->mBooleans.mBits[0] & 2) == 0 )
                v12 = 1;
            }
          }
          *pIsFullyInside = v12;
          return (UFG::UIHKScreenHud *)Stat;
        }
        goto LABEL_41;
      }
    }
    if ( mActiveInterior == INTERIOR_SAFEHOUSEKT )
    {
      if ( (_S12_3 & 2) == 0 )
      {
        _S12_3 |= 2u;
        v15 = UFG::qStringHash32("LOI_KT_SHDoor001_101", 0xFFFFFFFF);
        UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sKTSafeHouse, v15);
        atexit(UFG::CopSystem::IsPlayerInsideUnlockedSafehouse_::_26_::_dynamic_atexit_destructor_for__sKTSafeHouse__);
      }
      v14 = &sKTSafeHouse;
    }
    else
    {
      if ( (_S12_3 & 4) == 0 )
      {
        _S12_3 |= 4u;
        v16 = UFG::qStringHash32("LOI_PHQDoor004_01", 0xFFFFFFFF);
        UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sPendrewsHqDoor, v16);
        atexit(UFG::CopSystem::IsPlayerInsideUnlockedSafehouse_::_30_::_dynamic_atexit_destructor_for__sPendrewsHqDoor__);
      }
      v14 = &sPendrewsHqDoor;
    }
    goto LABEL_30;
  }
  return result;
}

// File Line: 1373
// RVA: 0x3EC860
bool __fastcall UFG::CopSystem::AllowSpawnRegionSpawning(UFG::CopSystem *this)
{
  UFG::CopSystem *v3; // rax

  if ( !((unsigned __int8 (__fastcall *)(UFG::CopSystem *))this->vfptr[7].__vecDelDtor)(this)
    || !((unsigned __int8 (__fastcall *)(UFG::CopSystem *))this->vfptr[113].__vecDelDtor)(this) )
  {
    return 0;
  }
  v3 = UFG::CopSystem::Instance();
  return !((unsigned int (__fastcall *)(UFG::CopSystem *))v3->vfptr[89].__vecDelDtor)(v3)
      || this->mFocusTargetContext.mIsOnFootHeuristic;
}

// File Line: 1404
// RVA: 0x3F07D0
void __fastcall UFG::CopSystem::Update(UFG::CopSystem *this, float deltaTime)
{
  UFG::CopSystem *v3; // rdi
  Render::DebugDrawContext *Context; // r15
  UFG::OSuiteLeaderboardManager *v5; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *vfptr; // rbx
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimObject *v9; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qVector3 *v11; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float mSimTime_Temp; // xmm7_4
  float v15; // xmm1_4
  char *mStimulusCount; // rbp
  char *v17; // rdx
  __int64 v18; // r9
  __int64 v19; // r14
  __int64 v20; // r10
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *p_mNode; // rax
  UFG::qList<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent,1,0> *v22; // rcx
  __int64 v23; // rax
  float *v24; // rax
  int v25; // esi
  const char **v26; // rbx
  UFG::qColour *v27; // r9
  bool *p_mTracked; // rbx
  __int64 v29; // rsi
  float mLastHeatEventTimer; // xmm0_4
  float v31; // xmm0_4
  bool mIsOnFootHeuristic; // bl
  UFG::SimObject *v33; // rax
  int mHeatLevel; // eax
  bool v35; // cc
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v36; // rax
  UFG::qPropertySet *v37; // rax
  UFG::qStaticSymbol *v38; // rcx
  float *v39; // rax
  float v40; // xmm6_4
  float v41; // xmm0_4
  float v42; // xmm7_4
  float v43; // xmm6_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpArrestRightHumanCop; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  __int64 v47; // [rsp+30h] [rbp-98h]
  UFG::qArray<unsigned long,0> result; // [rsp+E0h] [rbp+18h] BYREF

  v3 = this;
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  UFG::OnlineManager::Instance();
  if ( ((int (__fastcall *)(UFG::CopSystem *))v3->vfptr[89].__vecDelDtor)(v3) > 1 )
  {
    v5 = UFG::OSuiteLeaderboardManager::Instance();
    LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                            v5,
                                            "StatAwardsSurvivor");
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, deltaTime);
  }
  vfptr = v3->vfptr;
  LocalPlayer = UFG::GetLocalPlayer();
  vfptr[19].__vecDelDtor(v3, (unsigned int)LocalPlayer);
  if ( v3->mReloadTuningFiles )
  {
    UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, sCopsTuningPropertySetName);
    UFG::PropertySetManager::ReloadPropertySet((UFG::qSymbol *)&result);
    v3->mReloadTuningFiles = 0;
  }
  if ( !v3->mEnable )
    UFG::GameStatAction::Player::SetHeat(0.0);
  v9 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[18].__vecDelDtor)(v3);
  if ( v9 && (m_pTransformNodeComponent = v9->m_pTransformNodeComponent) != 0i64 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v9->m_pTransformNodeComponent);
    v11 = (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3;
  }
  else
  {
    v11 = &UFG::qVector3::msZero;
  }
  y = v11->y;
  z = v11->z;
  v3->mFocusTargetPosition.x = v11->x;
  v3->mFocusTargetPosition.y = y;
  v3->mFocusTargetPosition.z = z;
  mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( ((unsigned __int8 (__fastcall *)(UFG::CopSystem *))v3->vfptr[118].__vecDelDtor)(v3) )
  {
    UFG::PropertySetHandle::Bind(&v3->mProperties);
    v15 = *UFG::qPropertySet::Get<float>(
             v3->mProperties.mpPropSet,
             (UFG::qArray<unsigned long,0> *)&CopSym_tunable_stimulus_alive_time,
             DEPTH_RECURSE);
    mStimulusCount = v3->mStimulusCount;
    v17 = v3->mStimulusCount;
    v18 = 112i64;
    v19 = 116i64;
    v20 = 116i64;
    do
    {
      *v17 = 0;
      if ( *(v17 - 116) )
      {
        p_mNode = UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList.mNode.mNext - 4;
        if ( (UFG::qList<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent,1,0> *)&UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList.mNode.mNext[-4] != &UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList - 4 )
        {
          do
          {
            v22 = (UFG::qList<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent,1,0> *)&p_mNode[4].mNext[-4];
            v23 = *(__int64 *)((char *)&p_mNode->mPrev + v18);
            if ( v23 )
            {
              v24 = (float *)(v23 + 32);
              if ( v24 )
              {
                if ( v15 >= (float)(mSimTime_Temp - *v24) )
                  ++*v17;
              }
            }
            p_mNode = &v22->mNode;
          }
          while ( v22 != &UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList - 4 );
        }
      }
      v18 += 8i64;
      ++v17;
      --v20;
    }
    while ( v20 );
    if ( v3->mShowStimulus )
    {
      Render::DebugDrawContext::DrawTextA(
        Context,
        40,
        80,
        &UFG::qColour::White,
        "Tracking stimulus for heat generation:");
      v25 = 90;
      v26 = UFG::g_StimulusName;
      do
      {
        if ( *(mStimulusCount - 116) )
        {
          v27 = &UFG::qColour::White;
          if ( *mStimulusCount )
            v27 = &UFG::qColour::Yellow;
          LODWORD(v47) = (unsigned __int8)*mStimulusCount;
          Render::DebugDrawContext::DrawTextA(Context, 60, v25, v27, "%s: %d", *v26, v47);
          v25 += 10;
        }
        ++mStimulusCount;
        ++v26;
        --v19;
      }
      while ( v19 );
      v3 = this;
    }
  }
  p_mTracked = &v3->mHeatEvents[0].mTracked;
  v29 = 26i64;
  do
  {
    if ( !*p_mTracked && (float)(UFG::Metrics::msInstance.mSimTime_Temp - *((float *)p_mTracked - 1)) > 0.5 )
    {
      if ( (_S10_5 & 1) == 0 )
      {
        _S10_5 |= 1u;
        UFG::CopSystem::CopSystem(&sCopSystem);
        atexit(UFG::CopSystem::Instance_::_2_::_dynamic_atexit_destructor_for__sCopSystem__);
      }
      UFG::CopSystem::mspInstance = &sCopSystem;
      sCopSystem.vfptr[99].__vecDelDtor(&sCopSystem, *((unsigned int *)p_mTracked + 1));
      *((_DWORD *)p_mTracked - 1) = LODWORD(UFG::Metrics::msInstance.mSimTime_Temp);
      *p_mTracked = 1;
    }
    p_mTracked += 12;
    --v29;
  }
  while ( v29 );
  mLastHeatEventTimer = v3->mLastHeatEventTimer;
  if ( mLastHeatEventTimer > 0.0 )
  {
    v31 = mLastHeatEventTimer - deltaTime;
    if ( v31 <= 0.0 )
      v31 = 0.0;
    v3->mLastHeatEventTimer = v31;
    if ( v31 == 0.0 )
    {
      v3->mLastHeatEventIndex = eHEATEVENT_NONE;
    }
    else if ( v3->mLastHeatEventIndex == eHEATEVENT_NONE )
    {
      v3->mLastHeatEventTimer = 0.0;
    }
  }
  mIsOnFootHeuristic = v3->mFocusTargetContext.mIsOnFootHeuristic;
  v33 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[18].__vecDelDtor)(v3);
  UFG::EncounterUnitContext::Update(&v3->mFocusTargetContext, v33, deltaTime);
  if ( mIsOnFootHeuristic && !v3->mFocusTargetContext.mIsOnFootHeuristic )
  {
    mHeatLevel = v3->mHeatLevel;
    if ( mHeatLevel >= 1 )
    {
      v35 = mHeatLevel <= 2;
      v36 = v3->vfptr;
      if ( v35 )
      {
        v3->mFocusTargetContext.mOpenFired = 1;
        ((void (__fastcall *)(UFG::CopSystem *, __int64, __int64))v36[88].__vecDelDtor)(v3, 2i64, 25i64);
      }
      else
      {
        v36[111].__vecDelDtor(v3, 25u);
      }
      ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[23].__vecDelDtor)(v3);
    }
  }
  if ( v3->mHeatLevel >= HEATLEVEL_ONE )
  {
    v37 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[33].__vecDelDtor)(v3);
    if ( v37 )
    {
      v38 = &EncounterSym_ambient_density_invehicle;
      if ( v3->mFocusTargetContext.mIsOnFootHeuristic )
        v38 = &EncounterSym_ambient_density_onfoot;
      result.size = v38->mUID;
      v39 = UFG::qPropertySet::Get<float>(v37, &result, DEPTH_RECURSE);
      if ( v39 )
      {
        v40 = *v39;
        if ( *v39 >= 0.0 )
        {
          UFG::PedSpawnManager::GetInstance();
          UFG::PedSpawnManager::AdjustCopSystemDensityModifier(v40);
          UFG::WheeledVehicleManager::mMaxRoadDensityScale = v40;
        }
      }
    }
  }
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[38].__vecDelDtor)(v3);
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[40].__vecDelDtor)(v3);
  UFG::CopSystem::ApplySpeedCap(v3);
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[39].__vecDelDtor)(v3);
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[112].__vecDelDtor)(v3);
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[76].__vecDelDtor)(v3);
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[41].__vecDelDtor)(v3);
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[114].__vecDelDtor)(v3);
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[116].__vecDelDtor)(v3);
  if ( !v3->mpArrestRightHumanCop.m_pPointer )
    ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[83].__vecDelDtor)(v3);
  v41 = v3->mOnFootNoSprintTimer - deltaTime;
  if ( v41 <= 0.0 )
    v41 = 0.0;
  v3->mOnFootNoSprintTimer = v41;
  if ( v3->mpArrestRightHumanCop.m_pPointer )
  {
    v42 = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::PropertySetHandle::Bind(&v3->mProperties);
    v43 = v42 - v3->mArrestRightTimestamp;
    if ( v43 > *UFG::qPropertySet::Get<float>(
                  v3->mProperties.mpPropSet,
                  (UFG::qArray<unsigned long,0> *)&EncounterSym_arrest_right_timeout_timer,
                  DEPTH_RECURSE) )
    {
      p_mpArrestRightHumanCop = &v3->mpArrestRightHumanCop;
      if ( v3->mpArrestRightHumanCop.m_pPointer )
      {
        mPrev = p_mpArrestRightHumanCop->mPrev;
        mNext = v3->mpArrestRightHumanCop.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mpArrestRightHumanCop->mPrev = p_mpArrestRightHumanCop;
        v3->mpArrestRightHumanCop.mNext = &v3->mpArrestRightHumanCop;
      }
      v3->mpArrestRightHumanCop.m_pPointer = 0i64;
      v3->mArrestRightTimestamp = v42;
    }
  }
  if ( ((int (__fastcall *)(UFG::CopSystem *))v3->vfptr[89].__vecDelDtor)(v3) > 0 )
  {
    LOBYTE(result.size) = 0;
    if ( (unsigned __int8)UFG::CopSystem::IsPlayerInsideUnlockedSafehouse(v3, (bool *)&result) )
    {
      v3->mIsSafehouseInstantCooldownActive = result.size;
      v3->mFocusTargetContext.mOpenFired = 1;
    }
    else
    {
      v3->mIsSafehouseInstantCooldownActive = 0;
    }
  }
}

// File Line: 1812
// RVA: 0x3EC990
void __fastcall UFG::CopSystem::ApplySpeedCap(UFG::CopSystem *this)
{
  __int64 i; // rbp
  UFG::EncounterUnitComponent *v3; // rdi
  char v4; // r14
  double v5; // xmm0_8
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float v8; // xmm6_4
  float v9; // xmm7_4
  float *v10; // rax
  UFG::SimObjectCVBase *v11; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax
  UFG::AiDriverComponent *v14; // rdi

  for ( i = 0i64; (unsigned int)i < this->mVehicles.size; i = (unsigned int)(i + 1) )
  {
    v3 = this->mVehicles.p[i];
    if ( v3->mEngaged )
    {
      v4 = ((__int64 (__fastcall *)(UFG::CopSystem *))this->vfptr[16].__vecDelDtor)(this);
      if ( !v4 )
      {
        if ( v3->m_pSimObject )
        {
          v5 = ((double (__fastcall *)(UFG::CopSystem *, _QWORD, UFG::EncounterUnitComponent *))this->vfptr[17].__vecDelDtor)(
                 this,
                 0i64,
                 v3);
          m_pSimObject = v3->m_pSimObject;
          if ( m_pSimObject )
          {
            m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
            if ( m_pTransformNodeComponent )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject->m_pTransformNodeComponent);
              v8 = this->mFocusTargetPosition.x - m_pTransformNodeComponent->mWorldTransform.v3.x;
              v9 = this->mFocusTargetPosition.y - m_pTransformNodeComponent->mWorldTransform.v3.y;
              UFG::PropertySetHandle::Bind(&this->mProperties);
              v10 = UFG::qPropertySet::Get<float>(
                      this->mProperties.mpPropSet,
                      (UFG::qArray<unsigned long,0> *)&EncounterSym_disengage_vehicle_radius_ratio,
                      DEPTH_RECURSE);
              if ( (float)((float)(v9 * v9) + (float)(v8 * v8)) > (float)((float)(*(float *)&v5 * *v10)
                                                                        * (float)(*(float *)&v5 * *v10)) )
                v4 = 1;
            }
          }
        }
      }
      v11 = (UFG::SimObjectCVBase *)v3->m_pSimObject;
      if ( v11 )
      {
        m_Flags = v11->m_Flags;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        {
          ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v11);
        }
        else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        {
          ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v11,
                                                          UFG::AiDriverComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                          v11,
                                                          UFG::AiDriverComponent::_TypeUID);
        }
        v14 = ComponentOfTypeHK;
        if ( ComponentOfTypeHK )
        {
          if ( v4 )
          {
            UFG::PropertySetHandle::Bind(&this->mProperties);
            v14->m_DesiredSpeedLimit = *UFG::qPropertySet::Get<float>(
                                          this->mProperties.mpPropSet,
                                          (UFG::qArray<unsigned long,0> *)&EncounterSym_disengage_vehicle_topspeed,
                                          DEPTH_RECURSE)
                                     * 0.27777779;
          }
          else
          {
            ComponentOfTypeHK->m_DesiredSpeedLimit = -1.0;
          }
        }
      }
    }
  }
}

// File Line: 1863
// RVA: 0x3EDC00
void __fastcall UFG::CopSystem::HandleArrest(
        UFG::CopSystem *this,
        UFG::SimObject *pSource,
        UFG::SimObjectCharacter *pTarget)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rax
  UFG::ProgressionTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax
  unsigned int v10; // edx

  if ( pTarget )
  {
    m_pSceneObj = pTarget->m_pSceneObj;
    if ( m_pSceneObj )
    {
      if ( m_pSceneObj->mpWritableProperties || m_pSceneObj->mpConstProperties )
      {
        m_Flags = pTarget->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = pTarget->m_Components.p[8].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(
                             pTarget,
                             UFG::MissionFailConditionComponent::_TypeUID);
          else
            m_pComponent = UFG::SimObject::GetComponentOfType(pTarget, UFG::MissionFailConditionComponent::_TypeUID);
        }
        else
        {
          m_pComponent = pTarget->m_Components.p[8].m_pComponent;
        }
        if ( m_pComponent && BYTE4(m_pComponent[1].m_BoundComponentHandles.mNode.mPrev) )
        {
          v8 = UFG::ProgressionTracker::Instance();
          UFG::ProgressionTracker::SetRestoreType(v8, RestoreType_PoliceStation, 1);
          UFG::MissionFailConditionComponent::FailObject(pTarget, &qSymbol_ArrestFailCaption);
        }
      }
    }
  }
  if ( pTarget == UFG::GetLocalPlayer() )
  {
    v9 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v9, TimesArrested, 1);
    v10 = UI_HASH_CLEANUPMINIGAME_6;
    this->mStats.mFinishReason = eFinishReason_Arrested;
    UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, v10, 0xFFFFFFFF);
  }
}

// File Line: 1890
// RVA: 0x3F02D0
void __fastcall UFG::CopSystem::Replenish(UFG::CopSystem *this)
{
  if ( !this->mIsExcludingPlayerForRestOfChase )
    UFG::EncounterBase::Replenish(this);
}

// File Line: 1898
// RVA: 0x3EC8C0
void __fastcall UFG::CopSystem::ApplyReducedRadius(UFG::CopSystem *this)
{
  UFG::GameStatTracker *v2; // rax
  int Stat; // eax
  UFG::PropertySetHandle *p_mProperties; // rcx
  UFG::qStaticSymbol *v5; // rdx

  if ( !((unsigned __int8 (__fastcall *)(UFG::CopSystem *))this->vfptr[16].__vecDelDtor)(this) )
  {
    v2 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v2, CopDrivingStage);
    p_mProperties = &this->mProperties;
    if ( Stat < 5 )
    {
      UFG::PropertySetHandle::Bind(p_mProperties);
      this->mReducedRadiusTimer = *UFG::qPropertySet::Get<float>(
                                     this->mProperties.mpPropSet,
                                     (UFG::qArray<unsigned long,0> *)&CopSym_reduced_radius_timer,
                                     DEPTH_RECURSE);
      UFG::PropertySetHandle::Bind(&this->mProperties);
      v5 = &CopSym_reduced_radius_percentage;
    }
    else
    {
      UFG::PropertySetHandle::Bind(p_mProperties);
      this->mReducedRadiusTimer = *UFG::qPropertySet::Get<float>(
                                     this->mProperties.mpPropSet,
                                     (UFG::qArray<unsigned long,0> *)&CopSym_reduced_radius_timer_perk,
                                     DEPTH_RECURSE);
      UFG::PropertySetHandle::Bind(&this->mProperties);
      v5 = &CopSym_reduced_radius_percentage_perk;
    }
    this->mReducedRadiusPercentage = *UFG::qPropertySet::Get<float>(
                                        this->mProperties.mpPropSet,
                                        (UFG::qArray<unsigned long,0> *)v5,
                                        DEPTH_RECURSE);
  }
}

// File Line: 1917
// RVA: 0x3ED420
void __fastcall UFG::CopSystem::GenerateHeatEvent(UFG::CopSystem *this, UFG::eHeatEventEnum heatEvent)
{
  __int64 v3; // rdx
  float mSimTime_Temp; // xmm6_4
  __int64 v5; // r14
  bool *mStimulusWatchList; // r12
  __int64 v7; // r13
  float v8; // xmm7_4
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *p_mNode; // rbx
  __int64 v10; // rax
  UFG::qList<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent,1,0> *v11; // rdi
  float *v12; // rax
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *mNext; // rax
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *v14; // rsi
  __m128 mPrev_high; // xmm1
  float v16; // xmm0_4
  UFG::SimObjectGame *v17; // rcx
  UFG::SimComponent *m_pComponent; // rax
  __int16 m_Flags; // dx

  if ( this->mEnable && !this->mIsExcludingPlayerForRestOfChase )
  {
    v3 = heatEvent;
    if ( this->mHeatEvents[v3].mTracked
      && (float)(UFG::Metrics::msInstance.mSimTime_Temp - this->mHeatEvents[v3].mTimestamp) > 0.69999999 )
    {
      this->mHeatEvents[v3].mTimestamp = UFG::Metrics::msInstance.mSimTime_Temp;
      this->mHeatEvents[v3].mTracked = 0;
    }
    UFG::UIHKScreenHud::PingMinimap();
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::PropertySetHandle::Bind(&this->mProperties);
    v5 = 112i64;
    mStimulusWatchList = this->mStimulusWatchList;
    v7 = 116i64;
    v8 = *UFG::qPropertySet::Get<float>(
            this->mProperties.mpPropSet,
            (UFG::qArray<unsigned long,0> *)&CopSym_tunable_stimulus_alive_time,
            DEPTH_RECURSE);
    do
    {
      if ( *mStimulusWatchList )
      {
        p_mNode = UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList.mNode.mNext - 4;
        if ( (UFG::qList<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent,1,0> *)&UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList.mNode.mNext[-4] != &UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList - 4 )
        {
          do
          {
            v10 = *(__int64 *)((char *)&p_mNode->mPrev + v5);
            v11 = (UFG::qList<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent,1,0> *)&p_mNode[4].mNext[-4];
            if ( v10 )
            {
              v12 = (float *)(v10 + 32);
              if ( v12 )
              {
                if ( (float)(mSimTime_Temp - *v12) <= v8 )
                {
                  mNext = p_mNode[2].mNext;
                  if ( mNext )
                  {
                    v14 = mNext[5].mNext;
                    if ( v14 )
                    {
                      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)mNext[5].mNext);
                      mPrev_high = (__m128)HIDWORD(v14[11].mPrev);
                      v16 = *(float *)&v14[11].mPrev - this->mFocusTargetPosition.x;
                      mPrev_high.m128_f32[0] = (float)((float)(mPrev_high.m128_f32[0] - this->mFocusTargetPosition.y)
                                                     * (float)(mPrev_high.m128_f32[0] - this->mFocusTargetPosition.y))
                                             + (float)(v16 * v16);
                      if ( _mm_sqrt_ps(mPrev_high).m128_f32[0] < sCopSystem_WitnessRadius )
                      {
                        v17 = (UFG::SimObjectGame *)p_mNode[2].mNext;
                        if ( v17 )
                        {
                          m_Flags = v17->m_Flags;
                          if ( (m_Flags & 0x4000) != 0 )
                          {
                            m_pComponent = v17->m_Components.p[17].m_pComponent;
                          }
                          else if ( m_Flags >= 0 )
                          {
                            if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
                              m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v17,
                                               UFG::CopUnitComponent::_TypeUID);
                            else
                              m_pComponent = UFG::SimObject::GetComponentOfType(v17, UFG::CopUnitComponent::_TypeUID);
                          }
                          else
                          {
                            m_pComponent = v17->m_Components.p[17].m_pComponent;
                          }
                        }
                        else
                        {
                          m_pComponent = 0i64;
                        }
                        UFG::UIHKScreenHud::AddWitness((UFG::qVector3 *)&v14[11], m_pComponent != 0i64);
                      }
                    }
                  }
                }
              }
            }
            p_mNode = &v11->mNode;
          }
          while ( v11 != &UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList - 4 );
        }
      }
      v5 += 8i64;
      ++mStimulusWatchList;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 1964
// RVA: 0x3ECBA0
float __fastcall UFG::CopSystem::CalculateMultiplier(UFG::CopSystem *this, UFG::eHeatEventEnum heatEvent)
{
  __int64 v3; // rax
  unsigned __int8 v4; // r8
  __int64 v5; // rax
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // al
  float v8; // xmm7_4
  UFG::PropertySetHandle *p_mProperties; // rcx
  UFG::qStaticSymbol *v10; // rdx

  v3 = stimulusMultiplierType[heatEvent][0];
  v4 = 0;
  if ( (_DWORD)v3 != 116 )
    v4 = this->mStimulusCount[v3];
  v5 = stimulusMultiplierType[heatEvent][1];
  if ( (_DWORD)v5 != 116 )
  {
    v6 = this->mStimulusCount[v5];
    v7 = v4;
    if ( v4 <= v6 )
      v7 = v6;
    v4 = v7;
  }
  v8 = *(float *)&FLOAT_1_0;
  if ( v4 )
  {
    p_mProperties = &this->mProperties;
    if ( v4 > 5u )
    {
      if ( v4 > 0xCu )
      {
        UFG::PropertySetHandle::Bind(p_mProperties);
        v10 = &CopSym_multiplier_density_thirdteen_up;
      }
      else
      {
        UFG::PropertySetHandle::Bind(p_mProperties);
        v10 = &CopSym_multiplier_density_six_to_twelve;
      }
    }
    else
    {
      UFG::PropertySetHandle::Bind(p_mProperties);
      v10 = &CopSym_multiplier_density_one_to_five;
    }
    v8 = *UFG::qPropertySet::Get<float>(this->mProperties.mpPropSet, (UFG::qArray<unsigned long,0> *)v10, DEPTH_RECURSE);
  }
  return (float)(1.0 - UFG::PlayerBuffTracker::GetHeatLevelReductionPercent()) * v8;
}

// File Line: 2031
// RVA: 0x3ECC80
void __fastcall UFG::CopSystem::CommitHeatEvent(UFG::CopSystem *this, UFG::eHeatEventEnum heatEvent)
{
  __int64 v2; // rdi
  float v4; // xmm9_4
  double v5; // xmm0_8
  float v6; // xmm10_4
  float v7; // xmm7_4
  UFG::ProgressionTracker *v8; // rax
  float v9; // xmm6_4
  double v10; // xmm0_8
  float v11; // xmm8_4
  UFG::GameStatTracker *v12; // rax
  float v13; // xmm0_4
  char *v14; // rax
  UFG::qString *v15; // rax
  UFG::qString result; // [rsp+48h] [rbp-80h] BYREF

  v2 = heatEvent;
  if ( this->mEnable && !this->mIsExcludingPlayerForRestOfChase )
  {
    UFG::PropertySetHandle::Bind(&this->mProperties);
    v4 = *UFG::qPropertySet::Get<float>(
            this->mProperties.mpPropSet,
            (UFG::qArray<unsigned long,0> *)CopSystemProperty_stimulus[v2],
            DEPTH_RECURSE);
    v5 = ((double (__fastcall *)(UFG::CopSystem *, _QWORD))this->vfptr[119].__vecDelDtor)(this, (unsigned int)v2);
    v6 = *(float *)&v5;
    v7 = *(float *)&FLOAT_1_0;
    v8 = UFG::ProgressionTracker::Instance();
    if ( UFG::ProgressionTracker::IsRunningCriticalActiveMaster(v8) )
      v7 = sCopSystem_ActiveMissionMultiplier;
    v9 = (float)(*(float *)&v5 * v4) * v7;
    v10 = ((double (__fastcall *)(UFG::CopSystem *, _QWORD))this->vfptr[87].__vecDelDtor)(
            this,
            (unsigned int)this->mMaxHeatLevel);
    v11 = *(float *)&v10;
    v12 = UFG::GameStatTracker::Instance();
    v13 = UFG::GameStatTracker::GetStat(v12, Heat) + v9;
    if ( v13 >= v11 )
      v13 = v11;
    UFG::GameStatAction::Player::SetHeat(v13);
    v14 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)CopSystemProperty_stimulus[v2]);
    v15 = UFG::qString::FormatEx(
            &result,
            "DEBUG: Last committed HeatEvent(%d - %s) - Base(%.2f) X (%.2f) X (%.2f) = (%.2f)",
            (unsigned int)v2,
            v14,
            v4,
            v6,
            v7,
            v9);
    UFG::qString::Set(&this->mLastHeatEventCaption, v15->mData, v15->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
    UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Cops, OUTPUT_LEVEL_DEBUG, "[CopSystem]: %s\n");
    this->mLastHeatEventIndex = v2;
    UFG::PropertySetHandle::Bind(&this->mProperties);
    this->mLastHeatEventTimer = *UFG::qPropertySet::Get<float>(
                                   this->mProperties.mpPropSet,
                                   (UFG::qArray<unsigned long,0> *)&EncounterSym_last_heat_event_timer,
                                   DEPTH_RECURSE);
    this->mCooldownAllowed = 0;
    UFG::CopSystem::HandleHeatEvent(this);
  }
}

// File Line: 2065
// RVA: 0x3F05E0
void __fastcall UFG::CopSystem::SetMaxHeatLevel(UFG::CopSystem *this, int maxHeatLevel)
{
  __int64 mHeatLevel; // rdx
  double v4; // xmm0_8
  UFG::GameStatTracker *v5; // rax

  this->mMaxHeatLevel = maxHeatLevel;
  if ( maxHeatLevel != -1 )
  {
    mHeatLevel = (unsigned int)this->mHeatLevel;
    if ( maxHeatLevel < (int)mHeatLevel )
      mHeatLevel = (unsigned int)maxHeatLevel;
    v4 = ((double (__fastcall *)(UFG::CopSystem *, __int64))this->vfptr[87].__vecDelDtor)(this, mHeatLevel);
    v5 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v5, Heat, *(float *)&v4);
  }
}

// File Line: 2076
// RVA: 0x3ECC70
void __fastcall UFG::CopSystem::ClearMaxHeatLevel(UFG::CopSystem *this)
{
  this->mMaxHeatLevel = -1;
}

// File Line: 2081
// RVA: 0x3EC500
bool __fastcall UFG::CopSystem::AcquireArrestRight(UFG::CopSystem *this, UFG::SimObjectGame *pCop)
{
  UFG::SimObject *m_pPointer; // rbp
  bool result; // al
  UFG::TransformNodeComponent *v6; // rbx
  UFG::SimComponent *m_pComponent; // rax
  signed __int16 m_Flags; // cx
  UFG::CopSystem *v9; // rcx
  UFG::CopSystem *v10; // rax
  float *v11; // r14
  float mSimTime_Temp; // xmm6_4
  float v13; // xmm6_4
  UFG::TransformNodeComponent *v14; // rbx
  __m128 v15; // xmm8
  float v16; // xmm7_4
  float v17; // xmm6_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbp
  __m128 y_low; // xmm2
  float v20; // xmm7_4
  __m128 v21; // xmm2
  float v22; // xmm6_4
  float v23; // xmm0_4

  m_pPointer = this->mpArrestRightHumanCop.m_pPointer;
  if ( m_pPointer == pCop )
    return 1;
  v6 = 0i64;
  if ( pCop )
  {
    m_Flags = pCop->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = pCop->m_Components.p[16].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(pCop, UFG::EncounterUnitComponent::_TypeUID);
      else
        m_pComponent = UFG::SimObject::GetComponentOfType(pCop, UFG::EncounterUnitComponent::_TypeUID);
    }
    else
    {
      m_pComponent = pCop->m_Components.p[16].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v9 = this;
  if ( m_pComponent )
  {
    v10 = *(UFG::CopSystem **)&m_pComponent[1].m_TypeUID;
    if ( v10 )
      v9 = v10;
  }
  v11 = (float *)((__int64 (__fastcall *)(UFG::CopSystem *))v9->vfptr[20].__vecDelDtor)(v9);
  if ( m_pPointer )
  {
    m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
    if ( pCop )
      v6 = pCop->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent && v6 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
      y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v11[1]) * (float)(y_low.m128_f32[0] - v11[1]))
                                + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - *v11)
                                        * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - *v11)))
                        + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.z - v11[2])
                                * (float)(m_pTransformNodeComponent->mWorldTransform.v3.z - v11[2]));
      LODWORD(v20) = _mm_sqrt_ps(y_low).m128_u32[0];
      UFG::TransformNodeComponent::UpdateWorldTransform(v6);
      v21 = (__m128)LODWORD(v6->mWorldTransform.v3.y);
      v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] - v11[1]) * (float)(v21.m128_f32[0] - v11[1]))
                              + (float)((float)(v6->mWorldTransform.v3.x - *v11)
                                      * (float)(v6->mWorldTransform.v3.x - *v11)))
                      + (float)((float)(v6->mWorldTransform.v3.z - v11[2]) * (float)(v6->mWorldTransform.v3.z - v11[2]));
      v22 = _mm_sqrt_ps(v21).m128_f32[0];
      UFG::PropertySetHandle::Bind(&this->mProperties);
      v23 = *UFG::qPropertySet::Get<float>(
               this->mProperties.mpPropSet,
               (UFG::qArray<unsigned long,0> *)&EncounterSym_arrest_right_closer_distance_threshold,
               DEPTH_RECURSE);
      if ( v22 < v23 )
        v23 = v22;
      if ( (float)(v23 + v22) < v20 )
      {
        UFG::qSafePointer<Creature,Creature>::operator=(
          (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&this->mpArrestRightHumanCop,
          (UFG::SimComponent *)pCop);
        this->mArrestRightTimestamp = UFG::Metrics::msInstance.mSimTime_Temp;
      }
    }
  }
  else
  {
    mSimTime_Temp = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::PropertySetHandle::Bind(&this->mProperties);
    v13 = mSimTime_Temp - this->mArrestRightTimestamp;
    if ( v13 > *UFG::qPropertySet::Get<float>(
                  this->mProperties.mpPropSet,
                  (UFG::qArray<unsigned long,0> *)&EncounterSym_arrest_right_cooldown_timer,
                  DEPTH_RECURSE) )
    {
      if ( pCop )
      {
        v14 = pCop->m_pTransformNodeComponent;
        if ( v14 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(pCop->m_pTransformNodeComponent);
          v15 = (__m128)LODWORD(v14->mWorldTransform.v3.y);
          v16 = v14->mWorldTransform.v3.x - *v11;
          v15.m128_f32[0] = v15.m128_f32[0] - v11[1];
          v17 = v14->mWorldTransform.v3.z - v11[2];
          UFG::PropertySetHandle::Bind(&this->mProperties);
          v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v16 * v16))
                          + (float)(v17 * v17);
          if ( _mm_sqrt_ps(v15).m128_f32[0] < *UFG::qPropertySet::Get<float>(
                                                 this->mProperties.mpPropSet,
                                                 (UFG::qArray<unsigned long,0> *)&EncounterSym_arrest_right_distance_threshold,
                                                 DEPTH_RECURSE) )
          {
            UFG::qSafePointer<Creature,Creature>::operator=(
              (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&this->mpArrestRightHumanCop,
              (UFG::SimComponent *)pCop);
            result = 1;
            this->mArrestRightTimestamp = UFG::Metrics::msInstance.mSimTime_Temp;
            return result;
          }
        }
      }
    }
  }
  return 0;
}

// File Line: 2143
// RVA: 0x3F0120
void __fastcall UFG::CopSystem::ReleaseArrestRight(UFG::CopSystem *this, UFG::SimObject *pCop)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpArrestRightHumanCop; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  if ( this->mpArrestRightHumanCop.m_pPointer == pCop )
  {
    p_mpArrestRightHumanCop = &this->mpArrestRightHumanCop;
    if ( this->mpArrestRightHumanCop.m_pPointer )
    {
      mPrev = p_mpArrestRightHumanCop->mPrev;
      mNext = this->mpArrestRightHumanCop.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mpArrestRightHumanCop->mPrev = p_mpArrestRightHumanCop;
      this->mpArrestRightHumanCop.mNext = &this->mpArrestRightHumanCop;
    }
    this->mpArrestRightHumanCop.m_pPointer = 0i64;
    this->mArrestRightTimestamp = UFG::Metrics::msInstance.mSimTime_Temp;
  }
}

// File Line: 2153
// RVA: 0x3EF860
bool __fastcall UFG::CopSystem::IsSoloOnScene(UFG::CopSystem *this, UFG::SimObject *pCop)
{
  return this->mHumans.size == 1;
}

// File Line: 2159
// RVA: 0x3EDBA0
__int64 __fastcall UFG::CopSystem::GetLastHeatEventIndex(UFG::CopSystem *this)
{
  return (unsigned int)this->mLastHeatEventIndex;
}

// File Line: 2164
// RVA: 0x3ED850
const char *__fastcall UFG::CopSystem::GetHeatEventName(UFG::CopSystem *this, UFG::eHeatEventEnum heatEvent)
{
  return UFG::HeatEventEnumNames[heatEvent];
}

// File Line: 2169
// RVA: 0x3ED7E0
__int64 __fastcall UFG::CopSystem::GetHeatEventEnum(UFG::CopSystem *this, UFG::qString *heatEventName)
{
  unsigned int v3; // edi
  const char **v4; // rbx

  v3 = 0;
  v4 = UFG::HeatEventEnumNames;
  while ( !UFG::qString::operator==(heatEventName, *v4) )
  {
    ++v4;
    ++v3;
    if ( (__int64)v4 >= (__int64)UFG::VehicleOrientationEnumNames )
      return 0i64;
  }
  return v3;
}

// File Line: 2182
// RVA: 0x3F02E0
void __fastcall UFG::CopSystem::ReportInfractionTarget(
        UFG::CopSystem *this,
        UFG::SimObjectGame *pWitness,
        UFG::SimObject *pSuspect)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  signed __int16 m_Flags; // dx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mpAmbientSuspect; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax

  if ( pWitness )
  {
    m_pTransformNodeComponent = pWitness->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      m_Flags = pWitness->m_Flags;
      if ( (m_Flags & 0x4000) == 0 && m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          UFG::SimObjectGame::GetComponentOfTypeHK(pWitness, UFG::CopUnitComponent::_TypeUID);
        else
          UFG::SimObject::GetComponentOfType(pWitness, UFG::CopUnitComponent::_TypeUID);
      }
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      UFG::UIHKScreenHud::AddWitness((UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3, 0);
    }
  }
  p_mpAmbientSuspect = &this->mpAmbientSuspect;
  if ( this->mpAmbientSuspect.m_pPointer )
  {
    mPrev = p_mpAmbientSuspect->mPrev;
    mNext = this->mpAmbientSuspect.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mpAmbientSuspect->mPrev = p_mpAmbientSuspect;
    this->mpAmbientSuspect.mNext = &this->mpAmbientSuspect;
  }
  this->mpAmbientSuspect.m_pPointer = pSuspect;
  if ( pSuspect )
  {
    v11 = pSuspect->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v11->mNext = p_mpAmbientSuspect;
    p_mpAmbientSuspect->mPrev = v11;
    this->mpAmbientSuspect.mNext = &pSuspect->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pSuspect->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mpAmbientSuspect;
  }
}

// File Line: 2198
// RVA: 0x3ECE90
__int64 __fastcall UFG::CopSystem::CountActualUnits(UFG::CopSystem *this, UFG::EncounterUnit::UnitType unitType)
{
  unsigned int v2; // r8d
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> **p_mNext; // rax
  UFG::qList<UFG::CopUnitComponent,UFG::CopUnitComponent,1,0> *v4; // rcx

  v2 = 0;
  p_mNext = &UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mNext[-5].mNext;
  if ( &UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mNext[-5].mNext != (UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> **)((char *)&UFG::CopUnitComponent::s_CopUnitComponentList - 72) )
  {
    do
    {
      v4 = (UFG::qList<UFG::CopUnitComponent,UFG::CopUnitComponent,1,0> *)&p_mNext[10][-5].mNext;
      if ( *((_DWORD *)p_mNext + 119) == unitType && ((_BYTE)p_mNext[60] & 2) != 0 )
        ++v2;
      p_mNext = &p_mNext[10][-5].mNext;
    }
    while ( v4 != (UFG::qList<UFG::CopUnitComponent,UFG::CopUnitComponent,1,0> *)((char *)&UFG::CopUnitComponent::s_CopUnitComponentList
                                                                                - 72) );
  }
  return v2;
}

// File Line: 2213
// RVA: 0x3EDBE0
const char *__fastcall UFG::CopSystem::GetSpawningPrefix(UFG::CopSystem *this, bool isCharacter)
{
  const char *result; // rax

  result = "cops_vehicle_";
  if ( isCharacter )
    return "cops_character_";
  return result;
}

// File Line: 2218
// RVA: 0x3EEB00
void __fastcall UFG::CopSystem::HandleHeatEvent(UFG::CopSystem *this)
{
  UFG::eHeatEventEnum mLastHeatEventIndex; // ecx
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimComponent *m_pComponent; // rdx

  mLastHeatEventIndex = this->mLastHeatEventIndex;
  if ( (unsigned int)(mLastHeatEventIndex - 4) <= 1 || mLastHeatEventIndex == eHEATEVENT_FIRE_WEAPON )
  {
    this->mFocusTargetContext.mOpenFired = 1;
    LocalPlayer = UFG::GetLocalPlayer();
    if ( LocalPlayer )
    {
      m_pComponent = LocalPlayer->m_Components.p[20].m_pComponent;
      if ( m_pComponent )
      {
        if ( *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 31i64)
                       + *(_QWORD *)&m_pComponent[1].m_TypeUID
                       + 40) )
          this->mFocusTargetContext.mOpenFiredWithHostage = 1;
      }
    }
  }
}

