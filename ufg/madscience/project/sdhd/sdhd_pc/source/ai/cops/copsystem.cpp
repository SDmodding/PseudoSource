// File Line: 149
// RVA: 0x3EF340
UFG::CopSystem *__fastcall UFG::CopSystem::Instance()
{
  if ( !(_S10_5 & 1) )
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
  UFG::CopSystem *v1; // rsi
  float v2; // xmm1_4
  float v3; // xmm2_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // rdi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax

  v1 = this;
  UFG::EncounterBase::EncounterBase((UFG::EncounterBase *)&this->vfptr);
  v1->vfptr = (UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *)&UFG::CopSystem::`vftable';
  v1->mNumArrestAttempts = 0;
  v1->mAreRoadBlocksActive = 0;
  v1->mRoadBlockCooldownTimestamp = 0.0;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->mRoadBlockTriggerOrigin.x = UFG::qVector3::msZero.x;
  v1->mRoadBlockTriggerOrigin.y = v2;
  v1->mRoadBlockTriggerOrigin.z = v3;
  *(_QWORD *)&v1->mAudioTimer = 0i64;
  v1->mAudioPursuitDelay = 0.0;
  v1->mDistantSirens.m_pOneShot = 0i64;
  *(_QWORD *)&v1->mAudioHeatLevel.m_currentValue = 0i64;
  v1->mAudioHeatLevel.m_riseRate = 10000000.0;
  v1->mAudioHeatLevel.m_fallRate = 10000000.0;
  `eh vector constructor iterator'(
    v1->mHeatEvents,
    0xCui64,
    26,
    (void (__fastcall *)(void *))UFG::CopHeatEvent::CopHeatEvent);
  v4 = &v1->mpAmbientSuspect;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v1->mpAmbientSuspect.m_pPointer = 0i64;
  v5 = &v1->mpArrestRightHumanCop;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->mpArrestRightHumanCop.m_pPointer = 0i64;
  UFG::qString::qString(&v1->mLastHeatEventCaption);
  v1->mLastHeatEventIndex = 0;
  *(_WORD *)&v1->mIsExcludingPlayerForRestOfChase = 256;
  v1->mReloadTuningFiles = 0;
  v1->mDebugDrawLevel = 1;
  *(_WORD *)&v1->mShowCops = 0;
  v1->mShowResources = 0;
  if ( v1->mpAmbientSuspect.m_pPointer )
  {
    v6 = v4->mPrev;
    v7 = v1->mpAmbientSuspect.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v1->mpAmbientSuspect.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpAmbientSuspect.mPrev;
  }
  v1->mpAmbientSuspect.m_pPointer = 0i64;
  if ( v1->mpArrestRightHumanCop.m_pPointer )
  {
    v8 = v5->mPrev;
    v9 = v1->mpArrestRightHumanCop.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->mpArrestRightHumanCop.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpArrestRightHumanCop.mPrev;
  }
  v1->mpArrestRightHumanCop.m_pPointer = 0i64;
  v1->mArrestRightTimestamp = 0.0;
}

// File Line: 202
// RVA: 0x3EC3D0
void __fastcall UFG::CopSystem::~CopSystem(UFG::CopSystem *this)
{
  UFG::CopSystem *v1; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *)&UFG::CopSystem::`vftable';
  UFG::qString::~qString(&this->mLastHeatEventCaption);
  v2 = &v1->mpArrestRightHumanCop;
  if ( v1->mpArrestRightHumanCop.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v1->mpArrestRightHumanCop.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v1->mpArrestRightHumanCop.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpArrestRightHumanCop.mPrev;
  }
  v1->mpArrestRightHumanCop.m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v1->mpArrestRightHumanCop.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->mpArrestRightHumanCop.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpArrestRightHumanCop.mPrev;
  v7 = &v1->mpAmbientSuspect;
  if ( v1->mpAmbientSuspect.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mpAmbientSuspect.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mpAmbientSuspect.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpAmbientSuspect.mPrev;
  }
  v1->mpAmbientSuspect.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mpAmbientSuspect.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mpAmbientSuspect.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpAmbientSuspect.mPrev;
  `eh vector destructor iterator'(v1->mHeatEvents, 0xCui64, 26, (void (__fastcall *)(void *))_);
  UFG::OneShotHandle::Release(&v1->mDistantSirens);
  UFG::EncounterBase::~EncounterBase((UFG::EncounterBase *)&v1->vfptr);
}

// File Line: 206
// RVA: 0x3EF0D0
void __fastcall UFG::CopSystem::Initialize(UFG::CopSystem *this)
{
  UFG::CopSystem *v1; // rbx
  hkSeekableStreamReader *v2; // rax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v3; // rdi
  UFG::SimObjectCharacter *v4; // rax
  unsigned int v5; // eax
  UFG::qPropertySet *v6; // rax
  float *v7; // rdi
  UFG::qPropertySet *v8; // rax
  float *v9; // rax
  hkSeekableStreamReader *v10; // [rsp+38h] [rbp-20h]
  __int64 (__fastcall *v11)(__int64); // [rsp+40h] [rbp-18h]

  v1 = this;
  v11 =  UFG::CopSystem::`vcall'{744,{flat}};
  v10 = Assembly::GetRCX(this);
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v10,
    UFG::gGameStatEventChannel.mUID,
    UFG::gGameStatEventChannel.mName,
    0);
  v2 = Assembly::GetRCX(v1);
  v11 =  UFG::CopSystem::`vcall'{736,{flat}};
  v10 = v2;
  UFG::EventDispatcher::Register(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v10,
    UFG::gDestructionEventChannel.mUID,
    UFG::gDestructionEventChannel.mName,
    0);
  v1->vfptr[5].__vecDelDtor(
    (UFG::qSafePointerNode<UFG::EncounterBase> *)&v1->vfptr,
    (unsigned int)sCopsTuningPropertySetName);
  v3 = v1->vfptr;
  v4 = UFG::GetLocalPlayer();
  v3[19].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v1->vfptr, (unsigned int)v4);
  UFG::EncounterBase::Initialize((UFG::EncounterBase *)&v1->vfptr);
  if ( !(_S11_4 & 1) )
  {
    _S11_4 |= 1u;
    v5 = UFG::qStringHash32("audio-copaudiocomponent", 0xFFFFFFFF);
    UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&audioPropertySet, v5);
    atexit(UFG::CopSystem::Initialize_::_2_::_dynamic_atexit_destructor_for__audioPropertySet__);
  }
  v6 = UFG::PropertySetManager::CreateOrFindPropertySet((UFG::qSymbol *)&audioPropertySet.mUID);
  v1->mCopAudioConfig = v6;
  v7 = UFG::qPropertySet::Get<float>(v6, (UFG::qSymbol *)&vehicle_pursuit_max_time.mUID, DEPTH_RECURSE);
  v1->mAudioPursuitDelay = UFG::qRandom(*v7, &UFG::qDefaultSeed) + 2.0;
  v1->mAudioScannerDelay = UFG::qRandom(*v7, &UFG::qDefaultSeed) + 2.0;
  v1->mAudioTimer = 0.0;
  memset(v1->mStimulusWatchList, 0, sizeof(v1->mStimulusWatchList));
  v1->mStimulusWatchList[5] = 1;
  *(_WORD *)&v1->mStimulusWatchList[9] = 257;
  *(_DWORD *)&v1->mStimulusWatchList[13] = 16843009;
  v1->mStimulusWatchList[17] = 1;
  v1->mStimulusWatchList[19] = 1;
  v1->mStimulusWatchList[21] = 1;
  *(_WORD *)&v1->mStimulusWatchList[23] = 257;
  v1->mStimulusWatchList[25] = 1;
  *(_WORD *)&v1->mStimulusWatchList[28] = 257;
  UFG::GameStatAction::Player::SetHeat(0.0);
  v1->mIsAmbientUnitsAllowed = 1;
  if ( v1->mHeatLevel == HEATLEVEL_NONE )
  {
    v8 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::CopSystem *))v1->vfptr[33].__vecDelDtor)(v1);
    v9 = UFG::qPropertySet::Get<float>(v8, (UFG::qSymbol *)&EncounterSym_heatwave_timer.mUID, DEPTH_RECURSE);
    v1->mWaveTimer = UFG::qRandom(*v9, &UFG::qDefaultSeed);
  }
  *(_QWORD *)&v1->mStats.mFinishReason = 0i64;
  v1->mStats.mLastLevelKillCount = 0;
  ((void (__fastcall *)(UFG::CopSystem *))v1->vfptr[120].__vecDelDtor)(v1);
  v1->mHeatLevelTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
  v1->mOnFootNoSprintTimer = 0.0;
}

// File Line: 273
// RVA: 0x3F0630
void __fastcall UFG::CopSystem::Shutdown(UFG::CopSystem *this, __int64 a2)
{
  UFG::CopSystem *v2; // rsi
  UFG::CopRoadBlock *v3; // rcx
  UFG::qList<UFG::CopRoadBlock,UFG::CopRoadBlock,1,0> *v4; // rbx
  hkSeekableStreamReader *v5; // rax
  hkSeekableStreamReader *v6; // [rsp+20h] [rbp-18h]
  __int64 (__fastcall *v7)(__int64); // [rsp+28h] [rbp-10h]

  LOBYTE(a2) = 1;
  v2 = this;
  this->vfptr[3].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)this, a2);
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
  v2->mAreRoadBlocksActive = 0;
  UFG::EncounterBase::Shutdown((UFG::EncounterBase *)&v2->vfptr);
  v7 =  UFG::CopSystem::`vcall'{736,{flat}};
  v6 = Assembly::GetRCX(v2);
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v6,
    UFG::gDestructionEventChannel.mUID);
  v5 = Assembly::GetRCX(v2);
  v7 =  UFG::CopSystem::`vcall'{744,{flat}};
  v6 = v5;
  UFG::EventDispatcher::UnRegister(
    &UFG::EventDispatcher::mInstance,
    (fastdelegate::FastDelegate1<UFG::Event *,void> *)&v6,
    UFG::gGameStatEventChannel.mUID);
  ((void (__fastcall *)(UFG::CopSystem *))v2->vfptr[117].__vecDelDtor)(v2);
}

// File Line: 293
// RVA: 0x3F0170
void __fastcall UFG::CopSystem::RemoveAllUnitsOnScene(UFG::CopSystem *this, bool includeNonManaged)
{
  bool v2; // r14
  UFG::SimObjectCharacter *v3; // rax
  unsigned __int16 v4; // r9
  UFG::VehicleOwnershipComponent *v5; // rax
  UFG::SimObject *v6; // rbp
  UFG::qList<UFG::CopUnitComponent,UFG::CopUnitComponent,1,0> *v7; // rax
  char v8; // cl
  UFG::qList<UFG::CopUnitComponent,UFG::CopUnitComponent,1,0> *v9; // rbx
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *v10; // rdi

  v2 = includeNonManaged;
  UFG::EncounterBase::RemoveAllUnitsOnScene((UFG::EncounterBase *)&this->vfptr, includeNonManaged);
  v3 = UFG::GetLocalPlayer();
  if ( v3
    && ((v4 = v3->m_Flags, !((v4 >> 14) & 1)) ? ((v4 & 0x8000u) == 0 ? (!((v4 >> 13) & 1) ? (!((v4 >> 12) & 1) ? (v5 = (UFG::VehicleOwnershipComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::VehicleOwnershipComponent::_TypeUID)) : (v5 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::VehicleOwnershipComponent::_TypeUID))) : (v5 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::VehicleOwnershipComponent::_TypeUID))) : (v5 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::VehicleOwnershipComponent::_TypeUID))) : (v5 = (UFG::VehicleOwnershipComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::VehicleOwnershipComponent::_TypeUID)),
        v5) )
  {
    v6 = UFG::VehicleOwnershipComponent::GetOwnedVehicle(v5);
  }
  else
  {
    v6 = 0i64;
  }
  v7 = (UFG::qList<UFG::CopUnitComponent,UFG::CopUnitComponent,1,0> *)&UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mNext[-5].mNext;
  if ( &UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mNext[-5].mNext != (UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> **)((char *)&UFG::CopUnitComponent::s_CopUnitComponentList - 72) )
  {
    do
    {
      v8 = (char)v7[30].mNode.mPrev;
      v9 = (UFG::qList<UFG::CopUnitComponent,UFG::CopUnitComponent,1,0> *)&v7[5].mNode.mPrev[-5].mNext;
      if ( v8 & 2 && (v2 || v8 & 1) )
      {
        v10 = v7[2].mNode.mNext;
        UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v10[4].mNext);
        if ( v10 == (UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> *)v6 )
        {
          UFG::qPrintChannel::Print(
            &UFG::gPrintChannel_HK_Cops,
            OUTPUT_LEVEL_DEBUG,
            "[CopSystem]:   IGNORING (%s), because player vehicle!\n");
        }
        else
        {
          UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Cops, OUTPUT_LEVEL_DEBUG, "[CopSystem]:   Deleting (%s)\n");
          UFG::Simulation::QueueSimObjectToBeDestroyed(&UFG::gSim, (UFG::SimObject *)v10);
        }
      }
      v7 = v9;
    }
    while ( v9 != (UFG::qList<UFG::CopUnitComponent,UFG::CopUnitComponent,1,0> *)((char *)&UFG::CopUnitComponent::s_CopUnitComponentList
                                                                                - 72) );
  }
}

// File Line: 323
// RVA: 0x3ECF90
void __fastcall UFG::CopSystem::EnableAmbientUnits(UFG::CopSystem *this, __int64 enable)
{
  UFG::CopSystem *v2; // rbx

  v2 = this;
  if ( (_BYTE)enable != this->mIsAmbientUnitsAllowed )
  {
    this->mIsAmbientUnitsAllowed = enable;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Cops,
      OUTPUT_LEVEL_DEBUG,
      "[CopSystem]: Enable ambient state changed to (%s)\n");
  }
  if ( !v2->mIsAmbientUnitsAllowed && v2->mHeatLevel == HEATLEVEL_NONE )
  {
    LOBYTE(enable) = 1;
    v2->vfptr[3].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v2->vfptr, enable);
  }
}

// File Line: 338
// RVA: 0x3EF8C0
void __fastcall UFG::CopSystem::OnRestore(UFG::CopSystem *this)
{
  UFG::CopSystem *v1; // rbx
  __int64 v2; // rdx
  UFG::qPropertySet *v3; // rax
  float *v4; // rax

  v1 = this;
  ((void (*)(void))this->vfptr[117].__vecDelDtor)();
  ((void (__fastcall *)(UFG::CopSystem *, _QWORD, _QWORD))v1->vfptr[88].__vecDelDtor)(v1, 0i64, 0i64);
  ((void (__fastcall *)(UFG::CopSystem *))v1->vfptr[112].__vecDelDtor)(v1);
  LOBYTE(v2) = 1;
  v1->vfptr[3].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v1->vfptr, v2);
  ((void (__fastcall *)(UFG::CopSystem *))v1->vfptr[120].__vecDelDtor)(v1);
  v3 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::CopSystem *))v1->vfptr[33].__vecDelDtor)(v1);
  v4 = UFG::qPropertySet::Get<float>(v3, (UFG::qSymbol *)&EncounterSym_heatwave_timer.mUID, DEPTH_RECURSE);
  v1->mWaveTimer = UFG::qRandom(*v4, &UFG::qDefaultSeed);
}

// File Line: 352
// RVA: 0x3ECEE0
void __fastcall UFG::CopSystem::Enable(UFG::CopSystem *this, bool enable)
{
  UFG::CopSystem *v2; // rbx

  v2 = this;
  if ( enable != this->mEnable )
  {
    this->mEnable = enable;
    UFG::qPrintChannel::Print(
      &UFG::gPrintChannel_HK_Cops,
      OUTPUT_LEVEL_DEBUG,
      "[CopSystem]: Enable state changed to (%s)\n");
    ((void (__fastcall *)(UFG::CopSystem *))v2->vfptr[50].__vecDelDtor)(v2);
  }
  if ( !v2->mEnable )
  {
    if ( !(_S10_5 & 1) )
    {
      _S10_5 |= 1u;
      UFG::CopSystem::CopSystem(&sCopSystem);
      atexit(UFG::CopSystem::Instance_::_2_::_dynamic_atexit_destructor_for__sCopSystem__);
    }
    UFG::CopSystem::mspInstance = &sCopSystem;
    sCopSystem.vfptr[3].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&sCopSystem, 0);
  }
}

// File Line: 369
// RVA: 0x3EF870
signed __int64 __fastcall UFG::CopSystem::IsStimulusUpdateRequired(UFG::CopSystem *this)
{
  bool *v1; // rax
  signed __int64 v2; // rdx
  signed __int64 result; // rax

  v1 = &this->mHeatEvents[0].mTracked;
  v2 = 0i64;
  while ( *v1 )
  {
    ++v2;
    v1 += 12;
    if ( v2 >= 26 )
    {
      result = 0i64;
      if ( this->mShowStimulus )
        result = 1i64;
      return result;
    }
  }
  result = 1i64;
  if ( this->mShowStimulus )
    result = 1i64;
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
      result = 1;
  }
  return result;
}

// File Line: 397
// RVA: 0x3ED720
int __fastcall UFG::CopSystem::GetDesiredVehiclePopulation(UFG::CopSystem *this, UFG::qPropertySet *heatPropSet)
{
  UFG::qPropertySet *v2; // rdi
  UFG::CopSystem *v3; // rbx
  int result; // eax
  int v5; // edi
  unsigned int v6; // eax
  signed int v7; // ecx

  v2 = heatPropSet;
  v3 = this;
  if ( this->mHeatLevel )
  {
    v5 = UFG::EncounterBase::GetDesiredVehiclePopulation((UFG::EncounterBase *)&this->vfptr, heatPropSet);
    if ( v3->mFocusTargetContext.mIsOnFootHeuristic )
    {
      v6 = (__int64)v3->vfptr[44].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v3->vfptr, 2u);
      if ( v6 + v5 > 8 )
      {
        v7 = 8;
        if ( v6 < 8 )
          v7 = v6;
        v5 = 8 - v7;
      }
    }
    if ( v3->mFocusTargetContext.mIsInsideInterior )
      v5 = 0;
    result = v5;
  }
  else if ( ((unsigned __int8 (*)(void))this->vfptr[113].__vecDelDtor)() )
  {
    result = UFG::EncounterBase::GetDesiredVehiclePopulation((UFG::EncounterBase *)&v3->vfptr, v2);
  }
  else
  {
    result = 0;
  }
  return result;
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
    return UFG::EncounterBase::GetDesiredOnFootPopulation((UFG::EncounterBase *)&this->vfptr, heatPropSet);
  if ( ((unsigned __int8 (*)(void))this->vfptr[113].__vecDelDtor)() )
  {
    heatPropSet = v2;
    this = v3;
    return UFG::EncounterBase::GetDesiredOnFootPopulation((UFG::EncounterBase *)&this->vfptr, heatPropSet);
  }
  return 0i64;
}

// File Line: 437
// RVA: 0x3F17B0
void __fastcall UFG::CopSystem::UpdateHeatTimer(UFG::CopSystem *this, float deltaTime, float currentTime)
{
  UFG::CopSystem *v3; // rbx
  Render::DebugDrawManager *v4; // rax
  _BOOL8 v5; // rdx
  double v6; // xmm0_8
  Render::DebugDrawContext *v7; // rdi
  __int64 v8; // rax
  bool v9; // al
  bool v10; // zf
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v11; // rax
  UFG::qPropertySet *v12; // rax
  UFG::HeatLevelEnum v13; // eax
  char v14; // di
  float v15; // xmm7_4
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v16; // rax
  UFG::qPropertySet *v17; // rax
  float v18; // xmm0_4
  __int64 v19; // [rsp+28h] [rbp-40h]

  v3 = this;
  v4 = Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 3u);
  v5 = v3->mCoolingDown;
  *(float *)&v6 = v3->mReducedRadiusTimer - deltaTime;
  v3->mCoolingDown = 0;
  v7 = (Render::DebugDrawContext *)v4;
  if ( *(float *)&v6 <= 0.0 )
    LODWORD(v6) = 0;
  v8 = v3->mHeatLevel;
  v3->mReducedRadiusTimer = *(float *)&v6;
  if ( (_DWORD)v8 )
  {
    v9 = UFG::Metrics::msInstance.mSimTimeMSec - v3->mStartTimestamp < CopSystem_MinimumEngagedTime[v8];
    if ( v3->mIsSafehouseInstantCooldownActive || !v9 )
    {
      if ( (_BYTE)v5 || !v3->mIsReplenishing || (*(float *)&v6 = v3->mReplenishTimeout, *(float *)&v6 <= 0.0) )
      {
        if ( ((unsigned int (__fastcall *)(UFG::CopSystem *))v3->vfptr[32].__vecDelDtor)(v3) )
          v3->mCooldownAllowed = 0;
        if ( v3->mEnable && v3->mDebugDrawLevel > 1 )
        {
          if ( v3->mCooldownAllowed )
          {
            Render::DebugDrawContext::DrawTextA(v7, 700, 20, &UFG::qColour::Green, "(ESCAPED!)");
          }
          else
          {
            LODWORD(v19) = v3->mInsideDynamicRadiusCount;
            Render::DebugDrawContext::DrawTextA(
              v7,
              700,
              20,
              &UFG::qColour::Red,
              "(INSIDE) Inside (dynamic: %d) heat regions",
              v19);
          }
        }
      }
      else
      {
        *(float *)&v6 = *(float *)&v6 - deltaTime;
        if ( *(float *)&v6 <= 0.0 )
          LODWORD(v6) = 0;
        v10 = v3->mEnable == 0;
        v3->mReplenishTimeout = *(float *)&v6;
        v3->mCooldownAllowed = 0;
        if ( !v10 && v3->mDebugDrawLevel > 1 )
        {
          v6 = *(float *)&v6;
          Render::DebugDrawContext::DrawTextA(
            v7,
            700,
            20,
            &UFG::qColour::Green,
            "(REPLENSHING) (%.2f seconds remaining)",
            v6);
        }
      }
    }
    else
    {
      v3->mWaveCount = 0;
      v3->mCooldownAllowed = 0;
      v3->mIsReplenishing = 1;
    }
  }
  if ( v3->mCooldownAllowed )
  {
    v3->mCoolingDown = 1;
  }
  else
  {
    v11 = v3->vfptr;
    v3->mCooldownAllowed = 1;
    v12 = (UFG::qPropertySet *)v11[33].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v3->vfptr, v5);
    *(float *)&v6 = UFG::Metrics::msInstance.mSimTime_Temp
                  + *UFG::qPropertySet::Get<float>(
                       v12,
                       (UFG::qSymbol *)&EncounterSym_cooldown_timer.mUID,
                       DEPTH_RECURSE);
    v3->mNonEventfulCooldownTimestamp = *(float *)&v6;
  }
  if ( v3->mInstantCooldownActive || v3->mIsSafehouseInstantCooldownActive )
    v3->mCoolingDown = 1;
  if ( currentTime <= v3->mNonEventfulCooldownTimestamp || !v3->mCoolingDown )
    goto LABEL_40;
  v13 = v3->mHeatLevel;
  v14 = 0;
  v15 = 0.0;
  if ( v13 == HEATLEVEL_NONE )
    v14 = 1;
  if ( (signed int)v13 > 0 )
  {
    v3->vfptr[87].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v3->vfptr, 0);
    v16 = v3->vfptr;
    v3->mStats.mFinishReason = 3;
    v15 = *(float *)&v6;
    v17 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::CopSystem *))v16[33].__vecDelDtor)(v3);
    v3->mNonEventfulCooldownTimestamp = UFG::Metrics::msInstance.mSimTime_Temp
                                      + *UFG::qPropertySet::Get<float>(
                                           v17,
                                           (UFG::qSymbol *)&EncounterSym_cooldown_timer.mUID,
                                           DEPTH_RECURSE);
  }
  UFG::GameStatAction::Player::SetHeat(v15);
  if ( v14 )
  {
LABEL_40:
    if ( !v3->mIsReplenishing )
    {
      v18 = v3->mWaveTimer - deltaTime;
      v3->mWaveTimer = v18;
      if ( v18 <= 0.0 )
        ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[23].__vecDelDtor)(v3);
    }
  }
}

// File Line: 559
// RVA: 0x3EEB70
void __fastcall UFG::CopSystem::HandleHeatLevelChange(UFG::CopSystem *this)
{
  UFG::CopSystem *v1; // rbx
  UFG::qPropertySet *v2; // rax
  UFG::qPropertySet *v3; // rdi
  signed int v4; // ebp
  bool *v5; // rax
  bool v6; // zf
  bool v7; // cl
  UFG::qStaticSymbol *v8; // rax
  __int128 v9; // xmm6
  signed int v10; // esi
  UFG::eAIObjective v11; // er15
  unsigned int v12; // er14
  UFG::SimObjectCVBase *v13; // rcx
  unsigned __int16 v14; // dx
  UFG::ActiveAIEntityComponent *v15; // rax
  UFG::ActiveAIEntityComponent *v16; // rdi
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v17; // rax
  signed int v18; // edi
  UFG::HeatLevelEnum v19; // eax
  UFG::HeatLevelEnum v20; // eax
  UFG::qSymbol name; // [rsp+50h] [rbp+8h]

  v1 = this;
  v2 = (UFG::qPropertySet *)((__int64 (*)(void))this->vfptr[33].__vecDelDtor)();
  v3 = v2;
  if ( v2 )
  {
    v4 = 1;
    v1->mIsAvoidPeds = *UFG::qPropertySet::Get<bool>(
                          v2,
                          (UFG::qSymbol *)&EncounterSym_vehicle_avoid_peds.mUID,
                          DEPTH_RECURSE);
    v1->mIsAllowedToPass = *UFG::qPropertySet::Get<bool>(
                              v3,
                              (UFG::qSymbol *)&EncounterSym_vehicle_allowed_to_pass.mUID,
                              DEPTH_RECURSE);
    v1->mIsStaysOffSidewalk = *UFG::qPropertySet::Get<bool>(
                                 v3,
                                 (UFG::qSymbol *)&EncounterSym_vehicle_stays_off_sidewalk.mUID,
                                 DEPTH_RECURSE);
    v1->mIsRespectSpeedLimit = *UFG::qPropertySet::Get<bool>(
                                  v3,
                                  (UFG::qSymbol *)&EncounterSym_vehicle_respect_speed_limit.mUID,
                                  DEPTH_RECURSE);
    v5 = UFG::qPropertySet::Get<bool>(v3, (UFG::qSymbol *)&EncounterSym_vehicle_can_turn_around.mUID, DEPTH_RECURSE);
    v6 = v1->mFocusTargetContext.mIsOnFootHeuristic == 0;
    v7 = *v5;
    v8 = &EncounterSym_ambient_density_invehicle;
    v1->mIsCanTurnAround = v7;
    if ( !v6 )
      v8 = &EncounterSym_ambient_density_onfoot;
    name.mUID = v8->mUID;
    v9 = *(unsigned int *)UFG::qPropertySet::Get<float>(v3, &name, DEPTH_RECURSE);
    UFG::PedSpawnManager::GetInstance();
    UFG::PedSpawnManager::AdjustCopSystemDensityModifier(*(float *)&v9);
    v10 = 0;
    v11 = 0;
    v12 = 0;
    LODWORD(UFG::WheeledVehicleManager::mMaxRoadDensityScale) = v9;
    if ( v1->mHeatLevel > 0 )
      v11 = eAI_OBJECTIVE_PURSUIT_TARGET;
    if ( v1->mHumans.size > 0 )
    {
      do
      {
        v13 = (UFG::SimObjectCVBase *)v1->mHumans.p[v12]->m_pSimObject;
        if ( v13 )
        {
          v14 = v13->m_Flags;
          if ( (v14 >> 14) & 1 )
          {
            v15 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v13);
          }
          else if ( (v14 & 0x8000u) == 0 )
          {
            if ( (v14 >> 13) & 1 )
              v15 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v13->vfptr,
                                                      UFG::ActiveAIEntityComponent::_TypeUID);
            else
              v15 = (UFG::ActiveAIEntityComponent *)((v14 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         (UFG::SimObjectGame *)&v13->vfptr,
                                                                         UFG::ActiveAIEntityComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::ActiveAIEntityComponent::_TypeUID));
          }
          else
          {
            v15 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v13);
          }
          v16 = v15;
          if ( v15 )
          {
            UFG::ActiveAIEntityComponent::SetCurrentObjective(v15, v11, "EncounterBase::HandleHeatLevelChange");
            v16->m_bCanWander = 1;
          }
        }
        ++v12;
      }
      while ( v12 < v1->mHumans.size );
    }
    ((void (__fastcall *)(UFG::CopSystem *))v1->vfptr[49].__vecDelDtor)(v1);
    if ( v1->mHeatLevel )
    {
      v18 = 0;
      do
      {
        if ( v1->mEnable )
        {
          v19 = v1->mHeatLevel;
          if ( v18 == v19 || v18 == v19 + 1 )
            v1->vfptr[45].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v1->vfptr, v18);
        }
        ++v18;
      }
      while ( v18 < 6 );
      do
      {
        if ( !v1->mEnable || (v20 = v1->mHeatLevel, v10 != v20) && v10 != v20 + 1 )
          v1->vfptr[46].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v1->vfptr, v10);
        ++v10;
      }
      while ( v10 < 6 );
    }
    else
    {
      v17 = v1->vfptr;
      if ( v1->mEnable )
        v17[45].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v1->vfptr, 0);
      else
        v17[46].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v1->vfptr, 0);
      do
        v1->vfptr[46].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v1->vfptr, v4++);
      while ( v4 < 6 );
    }
  }
}

// File Line: 638
// RVA: 0x3F1FA0
void __fastcall UFG::CopSystem::UpdateVehicleFlags(UFG::CopSystem *this, UFG::SimObject *pSimObject)
{
  UFG::SimObjectCVBase *v2; // rbx
  unsigned __int16 v3; // dx
  UFG::CopSystem *v4; // rsi
  UFG::AiDriverComponent *v5; // rax
  UFG::AiDriverComponent *v6; // rdi
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rbx
  UFG::SimComponent *v9; // rax
  unsigned int v10; // edx
  char v11; // cl

  if ( pSimObject )
  {
    v2 = (UFG::SimObjectCVBase *)pSimObject;
    v3 = pSimObject->m_Flags;
    v4 = this;
    if ( (v3 >> 14) & 1 )
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v5 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v2->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                         (UFG::SimObject *)&v2->vfptr,
                                         UFG::AiDriverComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2);
    }
    v6 = v5;
    if ( v5 )
    {
      UFG::AiDriverComponent::SetAvoidPeds(v5, v4->mIsAvoidPeds);
      UFG::AiDriverComponent::SetAllowedToPass(v6, v4->mIsAllowedToPass);
      UFG::AiDriverComponent::SetStayOffSidewalk(v6, v4->mIsStaysOffSidewalk);
      UFG::AiDriverComponent::SetRespectSpeedLimit(v6, v4->mIsRespectSpeedLimit);
      UFG::AiDriverComponent::SetCanTurnAround(v6, v4->mIsCanTurnAround);
    }
    v7 = v2->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = v2->m_Components.p[24].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v2->vfptr,
               UFG::RoadSpaceComponent::_TypeUID);
      }
      else if ( (v7 >> 12) & 1 )
      {
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&v2->vfptr,
               UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::RoadSpaceComponent::_TypeUID);
      }
      v8 = v9;
    }
    else
    {
      v8 = v2->m_Components.p[24].m_pComponent;
    }
    if ( v8 )
    {
      v10 = 4;
      if ( v4->mHeatLevel )
        v10 = 1;
      UFG::RoadSpaceComponent::SetLaneFlags((UFG::RoadSpaceComponent *)v8, v10);
      v11 = 0;
      if ( v4->mHeatLevel )
        v11 = 1;
      v8[30].m_TypeUID &= 0xFFFFFFFD;
      v8[30].m_TypeUID |= 2 * (v11 != 0);
    }
  }
}

// File Line: 672
// RVA: 0x3ED000
void __fastcall UFG::CopSystem::ExcludePlayerForRestOfChase(UFG::CopSystem *this)
{
  UFG::CopSystem *v1; // r14
  UFG::GameStatTracker *v2; // rax
  __int64 v3; // rbp
  UFG::SimObjectGame *v4; // rbx
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rsi
  UFG::SimComponent *v7; // rax
  bool v8; // zf
  UFG::SimObjectGame *v9; // rcx
  unsigned __int8 v10; // cl
  signed __int64 v11; // rdi
  unsigned __int16 v12; // cx
  UFG::SimComponent *v13; // rax

  v1 = this;
  if ( !this->mIsExcludingPlayerForRestOfChase && this->mHeatLevel > 0 )
  {
    this->mIsExcludingPlayerForRestOfChase = 1;
    v2 = UFG::FactionInterface::Get();
    UFG::FactionInterface::SetStanding(&v2->mFactionInterface, FACTION_PLAYER, FACTION_LAW, FACTIONSTANDING_INDIFFERENT);
    v3 = 0i64;
    if ( v1->mHumans.size )
    {
      do
      {
        v4 = (UFG::SimObjectGame *)v1->mHumans.p[v3]->m_pSimObject;
        if ( v4 )
        {
          v5 = v4->m_Flags;
          if ( (v5 >> 14) & 1 )
          {
            v6 = v4->m_Components.p[20].m_pComponent;
          }
          else if ( (v5 & 0x8000u) == 0 )
          {
            if ( (v5 >> 13) & 1 )
            {
              v7 = UFG::SimObjectGame::GetComponentOfTypeHK(
                     (UFG::SimObjectGame *)v1->mHumans.p[v3]->m_pSimObject,
                     UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            else
            {
              v8 = ((v5 >> 12) & 1) == 0;
              v9 = (UFG::SimObjectGame *)v1->mHumans.p[v3]->m_pSimObject;
              if ( v8 )
                v7 = UFG::SimObject::GetComponentOfType(
                       (UFG::SimObject *)&v9->vfptr,
                       UFG::TargetingSystemBaseComponent::_TypeUID);
              else
                v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            v6 = v7;
          }
          else
          {
            v6 = v4->m_Components.p[20].m_pComponent;
          }
          if ( v6 )
          {
            v10 = *(_BYTE *)(*(_QWORD *)&v6[1].m_Flags + 37i64);
            if ( v10 )
            {
              v11 = 56i64 * v10;
              UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v11 + *(_QWORD *)&v6[1].m_TypeUID), 0i64);
              UFG::TargetingSimObject::SetLock((UFG::TargetingSimObject *)(v11 + *(_QWORD *)&v6[1].m_TypeUID), 0);
            }
          }
          v12 = v4->m_Flags;
          if ( (v12 >> 14) & 1 )
          {
            v13 = v4->m_Components.p[6].m_pComponent;
          }
          else if ( (v12 & 0x8000u) == 0 )
          {
            if ( (v12 >> 13) & 1 )
            {
              v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::HealthComponent::_TypeUID);
            }
            else if ( (v12 >> 12) & 1 )
            {
              v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::HealthComponent::_TypeUID);
            }
            else
            {
              v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::HealthComponent::_TypeUID);
            }
          }
          else
          {
            v13 = v4->m_Components.p[6].m_pComponent;
          }
          BYTE6(v13[1].m_BoundComponentHandles.mNode.mPrev) = 0;
        }
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < v1->mHumans.size );
    }
  }
}

// File Line: 703
// RVA: 0x3EF990
void __fastcall UFG::CopSystem::ReIncludePlayerForRestOfChase(UFG::CopSystem *this)
{
  UFG::CopSystem *v1; // rdi
  UFG::GameStatTracker *v2; // rax
  __int64 v3; // rbx
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax

  v1 = this;
  if ( this->mHeatLevel > 0 )
  {
    this->mIsExcludingPlayerForRestOfChase = 0;
    v2 = UFG::FactionInterface::Get();
    UFG::FactionInterface::SetStanding(&v2->mFactionInterface, FACTION_PLAYER, FACTION_LAW, FACTIONSTANDING_HOSTILE);
    v3 = 0i64;
    if ( v1->mHumans.size )
    {
      do
      {
        v4 = (UFG::SimObjectGame *)v1->mHumans.p[v3]->m_pSimObject;
        if ( v4 )
        {
          v5 = v4->m_Flags;
          if ( (v5 >> 14) & 1 )
          {
            v6 = v4->m_Components.p[6].m_pComponent;
          }
          else if ( (v5 & 0x8000u) == 0 )
          {
            if ( (v5 >> 13) & 1 )
            {
              v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::HealthComponent::_TypeUID);
            }
            else if ( (v5 >> 12) & 1 )
            {
              v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::HealthComponent::_TypeUID);
            }
            else
            {
              v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::HealthComponent::_TypeUID);
            }
          }
          else
          {
            v6 = v4->m_Components.p[6].m_pComponent;
          }
          BYTE6(v6[1].m_BoundComponentHandles.mNode.mPrev) = 1;
        }
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < v1->mHumans.size );
    }
  }
}

// File Line: 727
// RVA: 0x3F03C0
void __fastcall UFG::CopSystem::ResetChaseStats(UFG::CopSystem *this)
{
  UFG::CopSystem *v1; // rbx
  signed int v2; // ecx
  signed __int64 v3; // rax
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax

  v1 = this;
  this->mIsExcludingPlayerForRestOfChase = 0;
  this->mInstantCooldownActive = 0;
  this->mIsSafehouseInstantCooldownActive = 0;
  *(_QWORD *)&this->mWaveCount = 0i64;
  *(_WORD *)&this->mHasSpawnedInFrontForCurrentWave = 0;
  this->mNumArrestAttempts = 0;
  UFG::qString::Set(&this->mLastHeatEventCaption, &customWorldMapCaption);
  v1->mLastHeatEventIndex = 0;
  UFG::EncounterUnitContext::Reset(&v1->mFocusTargetContext);
  v1->mEnableWaveTimerChangesByDisabledUnits = 1;
  v1->mAreRoadBlocksActive = 0;
  v1->mRoadBlockCooldownTimestamp = 0.0;
  v2 = 0;
  v3 = (signed __int64)&v1->mHeatEvents[0].mTracked;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v1->mRoadBlockTriggerOrigin.x = UFG::qVector3::msZero.x;
  v1->mRoadBlockTriggerOrigin.y = v4;
  v1->mRoadBlockTriggerOrigin.z = v5;
  do
  {
    *(_DWORD *)(v3 + 4) = v2;
    v6 = UFG::Metrics::msInstance.mSimTime_Temp;
    ++v2;
    *(_BYTE *)v3 = 1;
    *(float *)(v3 - 4) = v6;
    v3 += 12i64;
  }
  while ( v2 < 26 );
  v7 = &v1->mpAmbientSuspect;
  if ( v1->mpAmbientSuspect.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mpAmbientSuspect.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mpAmbientSuspect.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpAmbientSuspect.mPrev;
  }
  v1->mpAmbientSuspect.m_pPointer = 0i64;
  v10 = &v1->mpArrestRightHumanCop;
  if ( v1->mpArrestRightHumanCop.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->mpArrestRightHumanCop.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->mpArrestRightHumanCop.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mpArrestRightHumanCop.mPrev;
  }
  v1->mpArrestRightHumanCop.m_pPointer = 0i64;
  v1->mArrestRightTimestamp = 0.0;
  v1->mOnFootNoSprintTimer = 0.0;
}

// File Line: 760
// RVA: 0x3F13F0
void __fastcall UFG::CopSystem::UpdateHeatLevel(UFG::CopSystem *this)
{
  UFG::CopSystem *v1; // rsi
  UFG::HeatLevelEnum v2; // er14
  UFG::GameStatTracker *v3; // rax
  float v4; // xmm0_4
  int v5; // ebp
  UFG::GameStatTracker *v6; // rax
  __int64 v7; // rdx
  UFG::qPropertySet *v8; // rax
  __int128 v9; // xmm0
  float v10; // xmm0_4
  float v11; // xmm1_4
  UFG::GameStatTracker *v12; // rax
  UFG::eFactionClassEnum v13; // ebx
  UFG::GameStatTracker *v14; // rax
  const char *v15; // rdx
  UFG::GameStatTracker *v16; // rax
  UFG::eFactionClassEnum v17; // edi
  UFG::GameStatTracker *v18; // rax
  UFG::eFactionStandingEnum v19; // ebx
  UFG::GameStatTracker *v20; // rax
  UFG::qString *v21; // rax
  char *v22; // r9
  UFG::qString result; // [rsp+38h] [rbp-40h]

  v1 = this;
  v2 = this->mHeatLevel;
  v3 = UFG::GameStatTracker::Instance();
  v4 = UFG::GameStatTracker::GetStat(v3, Heat);
  UFG::PropertySetHandle::Bind(&v1->mProperties);
  if ( v4 >= *UFG::qPropertySet::Get<float>(
                v1->mProperties.mpPropSet,
                (UFG::qSymbol *)&EncounterSym_threshold_level1.mUID,
                DEPTH_RECURSE) )
  {
    UFG::PropertySetHandle::Bind(&v1->mProperties);
    if ( v4 >= *UFG::qPropertySet::Get<float>(
                  v1->mProperties.mpPropSet,
                  (UFG::qSymbol *)&EncounterSym_threshold_level2.mUID,
                  DEPTH_RECURSE) )
    {
      UFG::PropertySetHandle::Bind(&v1->mProperties);
      if ( v4 >= *UFG::qPropertySet::Get<float>(
                    v1->mProperties.mpPropSet,
                    (UFG::qSymbol *)&EncounterSym_threshold_level3.mUID,
                    DEPTH_RECURSE) )
      {
        UFG::PropertySetHandle::Bind(&v1->mProperties);
        if ( v4 >= *UFG::qPropertySet::Get<float>(
                      v1->mProperties.mpPropSet,
                      (UFG::qSymbol *)&EncounterSym_threshold_level4.mUID,
                      DEPTH_RECURSE) )
        {
          UFG::PropertySetHandle::Bind(&v1->mProperties);
          v5 = (v4 >= *UFG::qPropertySet::Get<float>(
                         v1->mProperties.mpPropSet,
                         (UFG::qSymbol *)&EncounterSym_threshold_level5.mUID,
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
  if ( v5 == v2 )
    return;
  UFG::CopSystem::UpdateTelemetryStatsNewLevel(v1, v2, (UFG::HeatLevelEnum)v5);
  v1->mCurrentWaveType.mUID = v1->mHeatLevelPropertiesName[v5].mUID;
  v1->mHeatLevel = v5;
  v1->mHeatLevelTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
  v6 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStatHigh(v6, HighestHeatLevel, v5);
  if ( v5 )
  {
    if ( v5 > v2 )
    {
      v1->mWaveCount = 0;
      v1->mHasSpawnedInFrontForCurrentWave = 0;
      ((void (__fastcall *)(UFG::CopSystem *))v1->vfptr[23].__vecDelDtor)(v1);
    }
    if ( v2 )
      goto LABEL_33;
    v1->mStartTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    v16 = UFG::FactionInterface::Get();
    UFG::FactionInterface::SetStanding(&v16->mFactionInterface, FACTION_PLAYER, FACTION_LAW, FACTIONSTANDING_HOSTILE);
    v17 = 0;
    do
    {
      if ( (unsigned int)(v17 - 2) > 1 && v17 != 36 )
      {
        v18 = UFG::FactionInterface::Get();
        v19 = (unsigned int)UFG::FactionInterface::GetStanding(&v18->mFactionInterface, FACTION_PLAYER, v17);
        v20 = UFG::FactionInterface::Get();
        UFG::FactionInterface::SetStanding(&v20->mFactionInterface, FACTION_LAW, v17, v19);
      }
      ++v17;
    }
    while ( (unsigned int)v17 < 0x27 );
    if ( v1->mLastHeatEventIndex == eHEATEVENT_NONE )
      goto LABEL_33;
    v15 = "Begin_Pursuit";
  }
  else
  {
    ((void (__fastcall *)(UFG::CopSystem *))v1->vfptr[120].__vecDelDtor)(v1);
    if ( (unsigned __int8)UFG::CopSystem::IsPlayerInsideUnlockedSafehouse(v1, 0i64) )
    {
      LOBYTE(v7) = 1;
      v1->vfptr[3].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v1->vfptr, v7);
    }
    v8 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::CopSystem *))v1->vfptr[33].__vecDelDtor)(v1);
    v9 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                            v8,
                            (UFG::qSymbol *)&EncounterSym_heatwave_timer.mUID,
                            DEPTH_RECURSE);
    v10 = UFG::qRandom(*(float *)&v9, &UFG::qDefaultSeed);
    v11 = FLOAT_60_0;
    if ( v10 >= 60.0 )
      v11 = v10;
    v1->mWaveTimer = v11;
    v12 = UFG::FactionInterface::Get();
    UFG::FactionInterface::SetStanding(
      &v12->mFactionInterface,
      FACTION_PLAYER,
      FACTION_LAW,
      FACTIONSTANDING_INDIFFERENT);
    v13 = 0;
    do
    {
      if ( v13 != 3 && v13 != 36 )
      {
        v14 = UFG::FactionInterface::Get();
        UFG::FactionInterface::SetStanding(&v14->mFactionInterface, FACTION_LAW, v13, FACTIONSTANDING_INDIFFERENT);
      }
      ++v13;
    }
    while ( (unsigned int)v13 < 0x27 );
    v1->mStartTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
    v15 = "End_Pursuit";
  }
  UFG::PoliceScannerAudio::PlayScenario(&UFG::PoliceScannerAudio::sm_Instance, v15);
LABEL_33:
  ((void (__fastcall *)(UFG::CopSystem *))v1->vfptr[50].__vecDelDtor)(v1);
  UFG::GameStatAction::Player::NotifyHeatLevelChange(v2, (UFG::HeatLevelEnum)v5);
  ((void (__fastcall *)(UFG::CopSystem *, _QWORD, _QWORD))v1->vfptr[115].__vecDelDtor)(
    v1,
    (unsigned int)v2,
    (unsigned int)v5);
  if ( v1->mEnable )
  {
    if ( v1->mDebugDrawLevel > 0 )
    {
      v21 = UFG::qString::FormatEx(&result, "DEBUG: Heat level changed to (%d)!", (unsigned int)v5);
      UFG::qString::Set(&v1->mLastHeatEventCaption, v21->mData, v21->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      v22 = v1->mLastHeatEventCaption.mData;
      UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Cops, OUTPUT_LEVEL_DEBUG, "[CopSystem]: %s\n");
    }
  }
}

// File Line: 888
// RVA: 0x3EEF50
void __fastcall UFG::CopSystem::HandleOnFootSpawnPost(UFG::CopSystem *this, UFG::SimObject *pOnFootSpawn)
{
  UFG::SimObjectGame *v2; // rbx
  UFG::CopSystem *v3; // rdi
  unsigned __int16 v4; // dx
  UFG::StimulusReceiverComponent *v5; // rsi
  UFG::SimComponent *v6; // rax
  UFG::eStimulusType v7; // ebx
  bool *v8; // rdi

  v2 = (UFG::SimObjectGame *)pOnFootSpawn;
  v3 = this;
  UFG::EncounterBase::HandleOnFootSpawnPost((UFG::EncounterBase *)&this->vfptr, pOnFootSpawn);
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::StimulusReceiverComponent *)v2->m_Components.p[11].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::StimulusReceiverComponent::_TypeUID);
      else
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::StimulusReceiverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::StimulusReceiverComponent::_TypeUID);
      v5 = (UFG::StimulusReceiverComponent *)v6;
    }
    else
    {
      v5 = (UFG::StimulusReceiverComponent *)v2->m_Components.p[11].m_pComponent;
    }
    if ( v5 )
    {
      v7 = 0;
      v8 = v3->mStimulusWatchList;
      do
      {
        if ( *v8 )
          UFG::StimulusReceiverComponent::RequestToReceiveStimulus(v5, v7);
        ++v7;
        ++v8;
      }
      while ( (signed int)v7 < 116 );
    }
  }
}

// File Line: 916
// RVA: 0x3EF3D0
bool __fastcall UFG::CopSystem::IsCharacterInUseHeuristic(UFG::CopSystem *this, UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::SimObject *v2; // rbx
  UFG::EncounterUnitComponent *v3; // rdi
  UFG::CopSystem *v4; // rsi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax

  v2 = pEncounterUnitComponent->m_pSimObject;
  v3 = pEncounterUnitComponent;
  v4 = this;
  if ( !v2 )
    return UFG::EncounterBase::IsCharacterInUseHeuristic((UFG::EncounterBase *)&v4->vfptr, v3);
  v5 = v2->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v2->m_Components.p[17].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v2, UFG::CopUnitComponent::_TypeUID);
    else
      v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                              (UFG::SimObjectGame *)v2,
                              UFG::CopUnitComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                   v2,
                                                                   UFG::CopUnitComponent::_TypeUID);
  }
  else
  {
    v6 = v2->m_Components.p[17].m_pComponent;
  }
  if ( !v6 || v6[7].m_Flags & 2 )
    return UFG::EncounterBase::IsCharacterInUseHeuristic((UFG::EncounterBase *)&v4->vfptr, v3);
  UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2->m_Name);
  UFG::qPrintChannel::Print(
    &UFG::gPrintChannel_HK_Cops,
    OUTPUT_LEVEL_DEBUG,
    "[CopSystem]: This character (%s) is no longer usable by the cop system!\n");
  return 0;
}

// File Line: 933
// RVA: 0x3EFA70
char __fastcall UFG::CopSystem::Reacquire(UFG::CopSystem *this, UFG::EncounterUnit::UnitType unitType, UFG::SimObject *pPlayer, UFG::TransformNodeComponent *pPlayerTransform, UFG::SimObject **pExisting)
{
  UFG::EncounterUnit::UnitType v5; // er12
  UFG::CopSystem *v6; // r14
  bool v7; // cf
  char *v8; // rbp
  bool i; // zf
  signed __int64 v10; // r15
  char v11; // al
  UFG::SimObjectGame *v12; // rbx
  UFG::TransformNodeComponent *v13; // rdi
  unsigned __int16 v14; // cx
  UFG::EncounterUnitComponent *v15; // rsi
  UFG::SimComponent *v16; // rax
  UFG::qMemoryPool *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::EncounterUnitComponent *v19; // rax
  unsigned __int16 v20; // cx
  unsigned int v21; // edi
  unsigned __int16 v22; // cx
  __int16 v23; // ax
  UFG::CharacterOccupantComponent *v24; // rax
  UFG::VehicleOccupantComponent *v25; // rax
  UFG::qSafePointerNode<UFG::SimObject>Vtbl *v26; // rcx
  UFG::SimComponent *v27; // rax
  UFG::SimObjectGame *v28; // rax
  unsigned __int16 v29; // dx
  UFG::SimComponent *v30; // rax
  UFG::PedSpawnManager *v31; // rax
  unsigned __int16 v32; // cx
  UFG::TargetingSystemBaseComponent *v33; // rax
  unsigned __int16 v34; // cx
  UFG::SimComponent *v35; // rax
  unsigned __int16 v36; // cx
  UFG::StreamedResourceComponent *v37; // rdi
  UFG::SimComponent *v38; // rax
  unsigned __int16 v39; // cx
  UFG::CharacterOccupantComponent *v40; // rax
  UFG::TransformNodeComponent *v41; // rax
  UFG::SimObjectModifier v43; // [rsp+40h] [rbp-48h]
  UFG::qSymbol symbol; // [rsp+98h] [rbp+10h]

  v5 = unitType;
  v6 = this;
  if ( unitType == 1 )
    v7 = this->mHumans.size < 0x20;
  else
    v7 = this->mVehicles.size < 8;
  if ( v7 )
  {
    v8 = (char *)&UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mNext[-5].mNext;
    for ( i = &UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mNext[-5].mNext == (UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> **)((char *)&UFG::CopUnitComponent::s_CopUnitComponentList - 72);
          !i;
          i = v10 == (_QWORD)&UFG::CopUnitComponent::s_CopUnitComponentList - 72 )
    {
      v10 = *((_QWORD *)v8 + 10) - 72i64;
      if ( *((_DWORD *)v8 + 119) == v5 )
      {
        v11 = v8[480];
        if ( v11 & 2 )
        {
          if ( v11 & 8 )
          {
            if ( !(v11 & 1) )
            {
              v12 = (UFG::SimObjectGame *)*((_QWORD *)v8 + 5);
              if ( v12 )
              {
                v13 = v12->m_pTransformNodeComponent;
                if ( v13 )
                {
                  UFG::TransformNodeComponent::UpdateWorldTransform(v12->m_pTransformNodeComponent);
                  if ( !(unsigned __int8)v6->vfptr[58].__vecDelDtor(
                                           (UFG::qSafePointerNode<UFG::EncounterBase> *)&v6->vfptr,
                                           (unsigned int)&v13->mWorldTransform.v3)
                    && ((unsigned __int8)v6->vfptr[47].__vecDelDtor(
                                           (UFG::qSafePointerNode<UFG::EncounterBase> *)&v6->vfptr,
                                           (unsigned int)v12)
                     || ((unsigned __int8)v8[480] >> 4) & 1) )
                  {
                    v14 = v12->m_Flags;
                    if ( (v14 >> 14) & 1 )
                    {
                      v15 = (UFG::EncounterUnitComponent *)v12->m_Components.p[16].m_pComponent;
                    }
                    else if ( (v14 & 0x8000u) == 0 )
                    {
                      if ( (v14 >> 13) & 1 )
                      {
                        v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::EncounterUnitComponent::_TypeUID);
                      }
                      else if ( (v14 >> 12) & 1 )
                      {
                        v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::EncounterUnitComponent::_TypeUID);
                      }
                      else
                      {
                        v16 = UFG::SimObject::GetComponentOfType(
                                (UFG::SimObject *)&v12->vfptr,
                                UFG::EncounterUnitComponent::_TypeUID);
                      }
                      v15 = (UFG::EncounterUnitComponent *)v16;
                    }
                    else
                    {
                      v15 = (UFG::EncounterUnitComponent *)v12->m_Components.p[16].m_pComponent;
                    }
                    if ( !v15 )
                    {
                      v17 = UFG::GetSimulationMemoryPool();
                      v18 = UFG::qMemoryPool::Allocate(v17, 0xE0ui64, "EncounterUnitComponent", 0i64, 1u);
                      if ( v18 )
                      {
                        UFG::EncounterUnitComponent::EncounterUnitComponent(
                          (UFG::EncounterUnitComponent *)v18,
                          v12->mNode.mUID);
                        v15 = v19;
                      }
                      else
                      {
                        v15 = 0i64;
                      }
                      v20 = v12->m_Flags;
                      if ( (v20 >> 14) & 1 )
                      {
                        v21 = 16;
                      }
                      else if ( (v20 & 0x8000u) == 0 )
                      {
                        v21 = -1;
                      }
                      else
                      {
                        v21 = 16;
                      }
                      UFG::SimObjectModifier::SimObjectModifier(&v43, (UFG::SimObject *)&v12->vfptr, 1);
                      UFG::SimObjectModifier::AttachComponent(&v43, (UFG::SimComponent *)&v15->vfptr, v21);
                      UFG::SimObjectModifier::Close(&v43);
                      UFG::SimObjectModifier::~SimObjectModifier(&v43);
                    }
                    if ( v6->vfptr[78].__vecDelDtor(
                           (UFG::qSafePointerNode<UFG::EncounterBase> *)&v6->vfptr,
                           (unsigned int)v15) )
                    {
                      v22 = v12->m_Flags;
                      v23 = v22 >> 14;
                      if ( v5 == 1 )
                      {
                        if ( v23 & 1 )
                        {
                          v24 = (UFG::CharacterOccupantComponent *)v12->m_Components.p[44].m_pComponent;
                        }
                        else if ( (v22 & 0x8000u) == 0 )
                        {
                          if ( (v22 >> 13) & 1 )
                          {
                            v24 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v12,
                                                                       UFG::CharacterOccupantComponent::_TypeUID);
                          }
                          else if ( (v22 >> 12) & 1 )
                          {
                            v24 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v12,
                                                                       UFG::CharacterOccupantComponent::_TypeUID);
                          }
                          else
                          {
                            v24 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                       (UFG::SimObject *)&v12->vfptr,
                                                                       UFG::CharacterOccupantComponent::_TypeUID);
                          }
                        }
                        else
                        {
                          v24 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     v12,
                                                                     UFG::CharacterOccupantComponent::_TypeUID);
                        }
                        if ( !v24
                          || (v25 = UFG::CharacterOccupantComponent::GetCurrentVehicle(v24)) == 0i64
                          || (v26 = v25->mpDriver.m_pPointer[2].vfptr) == 0i64
                          || !HIBYTE(v26[17].__vecDelDtor) )
                        {
                          UFG::PedSpawnManager::AquireOwnership((UFG::SimObject *)&v12->vfptr, 0, 1, -1);
                          v31 = UFG::PedSpawnManager::GetInstance();
                          UFG::PedSpawnManager::SetSuspendOption(v31, (UFG::SimObject *)&v12->vfptr, NoSuspend);
                          if ( v6->mIsExcludingPlayerForRestOfChase )
                          {
                            v32 = v12->m_Flags;
                            if ( (v32 >> 14) & 1 )
                            {
                              v33 = (UFG::TargetingSystemBaseComponent *)v12->m_Components.p[20].m_pComponent;
                            }
                            else if ( (v32 & 0x8000u) == 0 )
                            {
                              if ( (v32 >> 13) & 1 )
                              {
                                v33 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             v12,
                                                                             UFG::TargetingSystemBaseComponent::_TypeUID);
                              }
                              else if ( (v32 >> 12) & 1 )
                              {
                                v33 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             v12,
                                                                             UFG::TargetingSystemBaseComponent::_TypeUID);
                              }
                              else
                              {
                                v33 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                             (UFG::SimObject *)&v12->vfptr,
                                                                             UFG::TargetingSystemBaseComponent::_TypeUID);
                              }
                            }
                            else
                            {
                              v33 = (UFG::TargetingSystemBaseComponent *)v12->m_Components.p[20].m_pComponent;
                            }
                            if ( v33 )
                              UFG::TargetingSystemBaseComponent::ClearTarget(v33, eTARGET_TYPE_AI_OBJECTIVE);
                            v34 = v12->m_Flags;
                            if ( (v34 >> 14) & 1 )
                            {
                              v35 = v12->m_Components.p[6].m_pComponent;
                            }
                            else if ( (v34 & 0x8000u) == 0 )
                            {
                              if ( (v34 >> 13) & 1 )
                              {
                                v35 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::HealthComponent::_TypeUID);
                              }
                              else if ( (v34 >> 12) & 1 )
                              {
                                v35 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::HealthComponent::_TypeUID);
                              }
                              else
                              {
                                v35 = UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v12->vfptr,
                                        UFG::HealthComponent::_TypeUID);
                              }
                            }
                            else
                            {
                              v35 = v12->m_Components.p[6].m_pComponent;
                            }
                            BYTE6(v35[1].m_BoundComponentHandles.mNode.mPrev) = 0;
                          }
LABEL_97:
                          v36 = v12->m_Flags;
                          if ( (v36 >> 14) & 1 )
                          {
                            v37 = (UFG::StreamedResourceComponent *)v12->m_Components.p[10].m_pComponent;
                          }
                          else if ( (v36 & 0x8000u) == 0 )
                          {
                            if ( (v36 >> 13) & 1 )
                            {
                              v37 = (UFG::StreamedResourceComponent *)v12->m_Components.p[7].m_pComponent;
                            }
                            else
                            {
                              if ( (v36 >> 12) & 1 )
                                v38 = UFG::SimObjectGame::GetComponentOfTypeHK(
                                        v12,
                                        UFG::StreamedResourceComponent::_TypeUID);
                              else
                                v38 = UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v12->vfptr,
                                        UFG::StreamedResourceComponent::_TypeUID);
                              v37 = (UFG::StreamedResourceComponent *)v38;
                            }
                          }
                          else
                          {
                            v37 = (UFG::StreamedResourceComponent *)v12->m_Components.p[10].m_pComponent;
                          }
                          if ( v37 )
                          {
                            symbol.mUID = v37->mActivePriority.mUID;
                            UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(
                              v37,
                              (UFG::qSymbol *)&qSymbol_Critical.mUID);
                            UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(v37, &symbol);
                          }
                          v8[480] = v8[480] & 0xFB | 1;
                          if ( *((_QWORD *)v8 + 20) )
                          {
                            v6->mVehicles.p[v6->mVehicles.size++] = v15;
                          }
                          else
                          {
                            v39 = v12->m_Flags;
                            if ( (v39 >> 14) & 1 )
                            {
                              v40 = (UFG::CharacterOccupantComponent *)v12->m_Components.p[44].m_pComponent;
                            }
                            else if ( (v39 & 0x8000u) == 0 )
                            {
                              if ( (v39 >> 13) & 1 )
                              {
                                v40 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           v12,
                                                                           UFG::CharacterOccupantComponent::_TypeUID);
                              }
                              else if ( (v39 >> 12) & 1 )
                              {
                                v40 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           v12,
                                                                           UFG::CharacterOccupantComponent::_TypeUID);
                              }
                              else
                              {
                                v40 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                           (UFG::SimObject *)&v12->vfptr,
                                                                           UFG::CharacterOccupantComponent::_TypeUID);
                              }
                            }
                            else
                            {
                              v40 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         v12,
                                                                         UFG::CharacterOccupantComponent::_TypeUID);
                            }
                            if ( v40 )
                            {
                              v41 = (UFG::TransformNodeComponent *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v40);
                              if ( v41 )
                              {
                                UFG::EncounterUnitComponent::SetGroupVehicle((SkeletalPose *)v15, v41);
                                UFG::EncounterUnitComponent::IncrementGroupVehicleUsageCount(v15);
                              }
                            }
                            v6->mHumans.p[v6->mHumans.size++] = v15;
                          }
                          ((void (__fastcall *)(UFG::CopSystem *, UFG::EncounterUnitComponent *, _QWORD))v6->vfptr[69].__vecDelDtor)(
                            v6,
                            v15,
                            0i64);
                          *pExisting = (UFG::SimObject *)*((_QWORD *)v8 + 5);
                          return 1;
                        }
                      }
                      else
                      {
                        if ( v23 & 1 )
                        {
                          v27 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::VehicleOccupantComponent::_TypeUID);
                        }
                        else if ( (v22 & 0x8000u) == 0 )
                        {
                          if ( (v22 >> 13) & 1 )
                          {
                            v27 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::VehicleOccupantComponent::_TypeUID);
                          }
                          else if ( (v22 >> 12) & 1 )
                          {
                            v27 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::VehicleOccupantComponent::_TypeUID);
                          }
                          else
                          {
                            v27 = UFG::SimObject::GetComponentOfType(
                                    (UFG::SimObject *)&v12->vfptr,
                                    UFG::VehicleOccupantComponent::_TypeUID);
                          }
                        }
                        else
                        {
                          v27 = v12->m_Components.p[30].m_pComponent;
                        }
                        if ( !v27 )
                          goto LABEL_97;
                        v28 = (UFG::SimObjectGame *)Scaleform::Render::RBGenericImpl::RenderTarget::GetTexture((hkSimpleLocalFrame *)v27);
                        if ( v28 )
                        {
                          v29 = v28->m_Flags;
                          if ( (v29 >> 14) & 1 )
                          {
                            v30 = v28->m_Components.p[17].m_pComponent;
                          }
                          else if ( (v29 & 0x8000u) == 0 )
                          {
                            if ( (v29 >> 13) & 1 )
                              v30 = UFG::SimObjectGame::GetComponentOfTypeHK(v28, UFG::CopUnitComponent::_TypeUID);
                            else
                              v30 = (v29 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v28,
                                                        UFG::CopUnitComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                             (UFG::SimObject *)&v28->vfptr,
                                                                                             UFG::CopUnitComponent::_TypeUID);
                          }
                          else
                          {
                            v30 = v28->m_Components.p[17].m_pComponent;
                          }
                          if ( v30 && v30[7].m_Flags & 1 )
                            goto LABEL_97;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      v8 = (char *)v10;
    }
  }
  return 0;
}

// File Line: 1073
// RVA: 0x3F1AA0
void __fastcall UFG::CopSystem::UpdateRoadBlocks(UFG::CopSystem *this)
{
  UFG::CopSystem *v1; // rdi
  __int64 v2; // rax
  UFG::TransformNodeComponent *v3; // r14
  bool v4; // si
  signed __int64 v5; // r14
  float v6; // xmm6_4
  float v7; // xmm7_4
  float *v8; // rax
  UFG::qPropertySet *v9; // rax
  float v10; // xmm1_4
  bool v11; // al
  float v12; // xmm0_4
  float v13; // xmm1_4
  bool v14; // al
  char v15; // bp
  float *v16; // rax
  float v17; // xmm6_4
  float *v18; // rax
  UFG::qNode<UFG::CopRoadBlock,UFG::CopRoadBlock> *v19; // rcx
  float v20; // xmm7_4
  UFG::qList<UFG::CopRoadBlock,UFG::CopRoadBlock,1,0> *v21; // rbx
  UFG::CopRoadBlock *v22; // rcx
  UFG::qList<UFG::CopRoadBlock,UFG::CopRoadBlock,1,0> *v23; // rbx
  int pBitfields; // [rsp+70h] [rbp+8h]

  v1 = this;
  v2 = ((__int64 (*)(void))this->vfptr[18].__vecDelDtor)();
  if ( !v2 )
    return;
  v3 = *(UFG::TransformNodeComponent **)(v2 + 88);
  if ( !v3 )
    return;
  UFG::TransformNodeComponent::UpdateWorldTransform(v3);
  v4 = v1->mAreRoadBlocksActive;
  v5 = (signed __int64)&v3->mWorldTransform.v3;
  if ( v4 )
  {
    v6 = v1->mRoadBlockTriggerOrigin.x - *(float *)v5;
    v7 = v1->mRoadBlockTriggerOrigin.y - *(float *)(v5 + 4);
    UFG::PropertySetHandle::Bind(&v1->mProperties);
    v8 = UFG::qPropertySet::Get<float>(
           v1->mProperties.mpPropSet,
           (UFG::qSymbol *)&CopSym_roadblock_escape_radius.mUID,
           DEPTH_RECURSE);
    if ( (float)((float)(v7 * v7) + (float)(v6 * v6)) > (float)(*v8 * *v8) )
    {
      v1->mAreRoadBlocksActive = 0;
      v1->mRoadBlockCooldownTimestamp = UFG::Metrics::msInstance.mSimTime_Temp;
    }
  }
  v9 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::CopSystem *))v1->vfptr[33].__vecDelDtor)(v1);
  v10 = *UFG::qPropertySet::Get<float>(v9, (UFG::qSymbol *)&CopSym_roadblock_frequency.mUID, DEPTH_RECURSE);
  v11 = v10 >= 0.0;
  if ( v1->mFocusTargetContext.mIsInWater || v1->mFocusTargetContext.mIsInsideInterior )
  {
    v11 = 0;
  }
  else if ( v10 >= 0.0 )
  {
    goto LABEL_12;
  }
  v1->mAreRoadBlocksActive = 0;
  v1->mRoadBlockCooldownTimestamp = UFG::Metrics::msInstance.mSimTime_Temp;
LABEL_12:
  if ( !v4 && v11 && (float)(UFG::Metrics::msInstance.mSimTime_Temp - v1->mRoadBlockCooldownTimestamp) > v10 )
  {
    v1->mAreRoadBlocksActive = 1;
    v12 = *(float *)(v5 + 4);
    v13 = *(float *)(v5 + 8);
    v1->mRoadBlockTriggerOrigin.x = *(float *)v5;
    v1->mRoadBlockTriggerOrigin.y = v12;
    v1->mRoadBlockTriggerOrigin.z = v13;
  }
  v14 = v1->mAreRoadBlocksActive;
  if ( v4 != v14 )
  {
    if ( v14 )
    {
      v15 = 0;
      pBitfields = 0;
      UFG::PropertySetHandle::Bind(&v1->mProperties);
      v16 = UFG::qPropertySet::Get<float>(
              v1->mProperties.mpPropSet,
              (UFG::qSymbol *)&CopSym_roadblock_spawn_min_radius.mUID,
              DEPTH_RECURSE);
      v17 = *v16 * *v16;
      UFG::PropertySetHandle::Bind(&v1->mProperties);
      v18 = UFG::qPropertySet::Get<float>(
              v1->mProperties.mpPropSet,
              (UFG::qSymbol *)&CopSym_roadblock_spawn_max_radius.mUID,
              DEPTH_RECURSE);
      v19 = UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mNext - 7;
      v20 = *v18 * *v18;
      if ( (UFG::qList<UFG::CopRoadBlock,UFG::CopRoadBlock,1,0> *)&UFG::CopRoadBlock::s_CopRoadBlockList.mNode.mNext[-7] == &UFG::CopRoadBlock::s_CopRoadBlockList - 7 )
        goto LABEL_28;
      do
      {
        v21 = (UFG::qList<UFG::CopRoadBlock,UFG::CopRoadBlock,1,0> *)&v19[7].mNext[-7];
        if ( ((_QWORD)v19[2].mPrev & 3) == 1 )
          v15 |= UFG::CopRoadBlock::ActivateByDistance(
                   (UFG::CopRoadBlock *)v19,
                   (UFG::qVector3 *)v5,
                   v17,
                   v20,
                   &pBitfields);
        v19 = &v21->mNode;
      }
      while ( v21 != &UFG::CopRoadBlock::s_CopRoadBlockList - 7 );
      if ( !v15 )
LABEL_28:
        v1->mAreRoadBlocksActive = 0;
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
float __fastcall UFG::CopSystem::GetHeatRadius(UFG::CopSystem *this, bool isOnfoot, UFG::EncounterUnitComponent *pEncounterUnitComponent)
{
  UFG::EncounterUnitComponent *v3; // rsi
  bool v4; // bp
  UFG::CopSystem *v5; // rdi
  UFG::qStaticSymbol *v7; // rbx
  UFG::qPropertySet *v8; // rax
  __int128 v9; // xmm6
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4

  v3 = pEncounterUnitComponent;
  v4 = isOnfoot;
  v5 = this;
  if ( !((unsigned int (*)(void))this->vfptr[89].__vecDelDtor)() )
    return sCopSystem_WitnessRadius;
  if ( v5->mInstantCooldownActive || v5->mIsSafehouseInstantCooldownActive )
  {
    LODWORD(v9) = 0;
  }
  else
  {
    v7 = &EncounterSym_heat_radius_vehicle;
    if ( v4 )
      v7 = &EncounterSym_heat_radius_onfoot;
    v8 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::CopSystem *))v5->vfptr[33].__vecDelDtor)(v5);
    v9 = *(unsigned int *)UFG::qPropertySet::Get<float>(v8, (UFG::qSymbol *)&v7->mUID, DEPTH_RECURSE);
  }
  if ( v3 )
  {
    v10 = v3->mInsideRadiusTimer;
    if ( v10 < 0.0 || (v11 = v3->mAcquiredTimer - v10, v11 <= 0.0) )
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
    *(float *)&v9 = *(float *)&v9 * (float)((float)(v12 * 0.60000002) + 0.40000001);
  }
  if ( ((unsigned __int8 (__fastcall *)(UFG::CopSystem *))v5->vfptr[16].__vecDelDtor)(v5) )
    *(float *)&v9 = *(float *)&v9 * v5->mReducedRadiusPercentage;
  return *(float *)&v9;
}

// File Line: 1200
// RVA: 0x3ED690
float __fastcall UFG::CopSystem::GetCurrentHeatLevelElapsedTime(UFG::CopSystem *this)
{
  float v1; // xmm0_4

  v1 = (float)(LODWORD(UFG::Metrics::msInstance.mSimTimeMSec) - LODWORD(this->mHeatLevelTimestamp));
  if ( (signed __int64)(UFG::Metrics::msInstance.mSimTimeMSec - this->mHeatLevelTimestamp) < 0 )
    v1 = v1 + 1.8446744e19;
  return v1 * 0.001;
}

// File Line: 1207
// RVA: 0x3F0780
void __fastcall UFG::CopSystem::TriggerOnFootNoSprint(UFG::CopSystem *this)
{
  UFG::CopSystem *v1; // rdi

  v1 = this;
  if ( ((signed int (*)(void))this->vfptr[89].__vecDelDtor)() > 0 )
  {
    UFG::PropertySetHandle::Bind(&v1->mProperties);
    v1->mOnFootNoSprintTimer = *UFG::qPropertySet::Get<float>(
                                  v1->mProperties.mpPropSet,
                                  (UFG::qSymbol *)&EncounterSym_success_vault_no_sprint_timer.mUID,
                                  DEPTH_RECURSE);
  }
}

// File Line: 1215
// RVA: 0x3EF510
char __fastcall UFG::CopSystem::IsOnFootNoSprintActive(UFG::CopSystem *this)
{
  char result; // al

  if ( this->mOnFootNoSprintTimer > 0.0 || (result = ((__int64 (*)(void))this->vfptr[16].__vecDelDtor)()) != 0 )
    result = 1;
  return result;
}

// File Line: 1220
// RVA: 0x3EDA60
float __fastcall UFG::CopSystem::GetHeatThresholdByLevel(UFG::CopSystem *this, int heatLevel)
{
  UFG::qPropertySet **v2; // rbx
  __int128 v3; // xmm0
  UFG::qPropertySet **v4; // rbx
  UFG::qPropertySet **v5; // rbx
  UFG::qPropertySet **v6; // rbx
  UFG::qPropertySet **v7; // rbx

  switch ( heatLevel + 1 )
  {
    case 0:
    case 6:
      v7 = (UFG::qPropertySet **)&this->mProperties;
      UFG::PropertySetHandle::Bind(&this->mProperties);
      v3 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                              v7[1],
                              (UFG::qSymbol *)&EncounterSym_threshold_level5.mUID,
                              DEPTH_RECURSE);
      break;
    case 2:
      v2 = (UFG::qPropertySet **)&this->mProperties;
      UFG::PropertySetHandle::Bind(&this->mProperties);
      v3 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                              v2[1],
                              (UFG::qSymbol *)&EncounterSym_threshold_level1.mUID,
                              DEPTH_RECURSE);
      break;
    case 3:
      v4 = (UFG::qPropertySet **)&this->mProperties;
      UFG::PropertySetHandle::Bind(&this->mProperties);
      v3 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                              v4[1],
                              (UFG::qSymbol *)&EncounterSym_threshold_level2.mUID,
                              DEPTH_RECURSE);
      break;
    case 4:
      v5 = (UFG::qPropertySet **)&this->mProperties;
      UFG::PropertySetHandle::Bind(&this->mProperties);
      v3 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                              v5[1],
                              (UFG::qSymbol *)&EncounterSym_threshold_level3.mUID,
                              DEPTH_RECURSE);
      break;
    case 5:
      v6 = (UFG::qPropertySet **)&this->mProperties;
      UFG::PropertySetHandle::Bind(&this->mProperties);
      v3 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                              v6[1],
                              (UFG::qSymbol *)&EncounterSym_threshold_level4.mUID,
                              DEPTH_RECURSE);
      break;
    default:
      LODWORD(v3) = 0;
      break;
  }
  return *(float *)&v3;
}

// File Line: 1237
// RVA: 0x3F0550
void __usercall UFG::CopSystem::SetHeatLevel(UFG::CopSystem *this@<rcx>, __int64 heatLevel@<rdx>, UFG::eHeatEventEnum heatEvent@<r8d>, float a4@<xmm0>)
{
  int v4; // eax
  UFG::eHeatEventEnum v5; // ebx
  UFG::CopSystem *v6; // rdi
  UFG::GameStatTracker *v7; // rax

  v4 = this->mMaxHeatLevel;
  v5 = heatEvent;
  v6 = this;
  if ( v4 != -1 && v4 < (signed int)heatLevel )
    heatLevel = (unsigned int)v4;
  this->vfptr[87].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)this, heatLevel);
  v6->mLastHeatEventIndex = v5;
  UFG::PropertySetHandle::Bind(&v6->mProperties);
  v6->mLastHeatEventTimer = *UFG::qPropertySet::Get<float>(
                               v6->mProperties.mpPropSet,
                               (UFG::qSymbol *)&EncounterSym_last_heat_event_timer.mUID,
                               DEPTH_RECURSE);
  v7 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v7, Heat, a4);
  v6->mCooldownAllowed = 0;
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
  unsigned int *v1; // rbx
  UFG::GameStatTracker *v2; // rax
  float v3; // xmm0_4
  float v4; // xmm6_4
  signed __int64 v5; // rdx
  int v6; // eax
  float v7; // xmm7_4
  float v8; // xmm0_4
  float result; // xmm0_4

  v1 = (unsigned int *)this;
  v2 = UFG::GameStatTracker::Instance();
  v3 = UFG::GameStatTracker::GetStat(v2, Heat);
  v4 = v3;
  (*(void (__fastcall **)(unsigned int *, _QWORD))(*(_QWORD *)v1 + 696i64))(v1, v1[59]);
  v5 = 5i64;
  v6 = v1[59] + 1;
  v7 = v3;
  if ( v6 < 5 )
    v5 = (unsigned int)v6;
  (*(void (__fastcall **)(unsigned int *, signed __int64))(*(_QWORD *)v1 + 696i64))(v1, v5);
  v8 = v3 - v3;
  if ( v8 > 0.0 )
    result = (float)(v4 - v7) / v8;
  else
    result = *(float *)&FLOAT_1_0;
  return result;
}

// File Line: 1284
// RVA: 0x14D6F60
__int64 UFG::_dynamic_initializer_for__gSafeHouseSymbol_SFAB__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("SFAB-AB", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSafeHouseSymbol_SFAB, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gSafeHouseSymbol_SFAB__);
}

// File Line: 1285
// RVA: 0x14D6FA0
__int64 UFG::_dynamic_initializer_for__gSafeHouseSymbol_SFCT__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("SFCT-CT", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSafeHouseSymbol_SFCT, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gSafeHouseSymbol_SFCT__);
}

// File Line: 1286
// RVA: 0x14D6FE0
__int64 UFG::_dynamic_initializer_for__gSafeHouseSymbol_SFKT__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("SFKT-KT", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSafeHouseSymbol_SFKT, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gSafeHouseSymbol_SFKT__);
}

// File Line: 1287
// RVA: 0x14D7020
__int64 UFG::_dynamic_initializer_for__gSafeHouseSymbol_SFNP__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("SFNP-NP", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSafeHouseSymbol_SFNP, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gSafeHouseSymbol_SFNP__);
}

// File Line: 1290
// RVA: 0x3EF540
UFG::UIHKScreenHud *__fastcall UFG::CopSystem::IsPlayerInsideUnlockedSafehouse(UFG::CopSystem *this, bool *pIsFullyInside)
{
  bool *v2; // rdi
  UFG::UIHKScreenHud *result; // rax
  UFG::eInteriors v4; // ebx
  bool v5; // si
  UFG::GameStatTracker *v6; // rax
  UFG::GameStatTracker *v7; // rax
  UFG::GameStatTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax
  UFG::SimObjectCharacter *v10; // rax
  UFG::SimObjectCharacterPropertiesComponent *v11; // rax
  bool v12; // al
  unsigned int v13; // eax
  UFG::qStaticSymbol *v14; // rdx
  unsigned int v15; // eax
  unsigned int v16; // eax
  UFG::SimObjectGame *v17; // rax
  unsigned __int16 v18; // dx
  UFG::DoorComponent *v19; // rax

  v2 = pIsFullyInside;
  result = UFG::UIHKScreenHud::getInstance();
  if ( result )
  {
    UFG::UIHKScreenHud::getInstance();
    v4 = UFG::UIHKScreenHud::mInteriorManager->mActiveInterior;
    v5 = 0;
    switch ( v4 )
    {
      case 2:
      case 6:
      case 7:
      case 22:
      case 23:
        v5 = 1;
        break;
      case 15:
        v6 = UFG::GameStatTracker::Instance();
        v5 = UFG::GameStatTracker::GetStat(v6, Collectible_Safehouse, (UFG::qSymbol *)&UFG::gSafeHouseSymbol_SFAB.mUID);
        break;
      case 16:
        v7 = UFG::GameStatTracker::Instance();
        v5 = UFG::GameStatTracker::GetStat(v7, Collectible_Safehouse, (UFG::qSymbol *)&UFG::gSafeHouseSymbol_SFCT.mUID);
        break;
      case 17:
        v8 = UFG::GameStatTracker::Instance();
        v5 = UFG::GameStatTracker::GetStat(v8, Collectible_Safehouse, (UFG::qSymbol *)&UFG::gSafeHouseSymbol_SFKT.mUID);
        break;
      case 18:
        v9 = UFG::GameStatTracker::Instance();
        v5 = UFG::GameStatTracker::GetStat(v9, Collectible_Safehouse, (UFG::qSymbol *)&UFG::gSafeHouseSymbol_SFNP.mUID);
        break;
      default:
        break;
    }
    if ( !v2 )
      return (UFG::UIHKScreenHud *)v5;
    if ( v4 != 6 )
    {
      if ( v4 == 15 )
        goto LABEL_20;
      if ( v4 != 17 )
      {
        if ( (unsigned int)(v4 - 22) > 1 )
        {
          v12 = 0;
          if ( UFG::GetLocalPlayer() )
          {
            v10 = UFG::GetLocalPlayer();
            v11 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)&v10->vfptr);
            if ( v11 )
            {
              if ( !((LOBYTE(v11->mBooleans.mBits[0]) >> 1) & 1) )
                v12 = 1;
            }
          }
          *v2 = v12;
          return (UFG::UIHKScreenHud *)v5;
        }
        goto LABEL_44;
      }
    }
    if ( v4 != 15 )
    {
      if ( v4 == 17 )
      {
        if ( !(_S12_3 & 2) )
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
        if ( v4 != 6 )
          goto LABEL_41;
        if ( !(_S12_3 & 4) )
        {
          _S12_3 |= 4u;
          v16 = UFG::qStringHash32("LOI_PHQDoor004_01", 0xFFFFFFFF);
          UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sPendrewsHqDoor, v16);
          atexit(UFG::CopSystem::IsPlayerInsideUnlockedSafehouse_::_30_::_dynamic_atexit_destructor_for__sPendrewsHqDoor__);
        }
        v14 = &sPendrewsHqDoor;
      }
LABEL_31:
      v17 = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)&v14->mUID);
      if ( v17 )
      {
        v18 = v17->m_Flags;
        if ( (v18 >> 14) & 1 )
        {
          v19 = (UFG::DoorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::DoorComponent::_TypeUID);
        }
        else if ( (v18 & 0x8000u) == 0 )
        {
          if ( (v18 >> 13) & 1 )
          {
            v19 = (UFG::DoorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::DoorComponent::_TypeUID);
          }
          else if ( (v18 >> 12) & 1 )
          {
            v19 = (UFG::DoorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::DoorComponent::_TypeUID);
          }
          else
          {
            v19 = (UFG::DoorComponent *)UFG::SimObject::GetComponentOfType(
                                          (UFG::SimObject *)&v17->vfptr,
                                          UFG::DoorComponent::_TypeUID);
          }
        }
        else
        {
          v19 = (UFG::DoorComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::DoorComponent::_TypeUID);
        }
LABEL_42:
        if ( v19 )
        {
          *v2 = (unsigned __int8)UFG::DoorComponent::IsOpen(v19) == 0;
          return (UFG::UIHKScreenHud *)v5;
        }
LABEL_44:
        *v2 = 1;
        return (UFG::UIHKScreenHud *)v5;
      }
LABEL_41:
      v19 = 0i64;
      goto LABEL_42;
    }
LABEL_20:
    if ( !(_S12_3 & 1) )
    {
      _S12_3 |= 1u;
      v13 = UFG::qStringHash32("LOI_AB_SHDoor001_101", 0xFFFFFFFF);
      UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&sABSafeHouse, v13);
      atexit(UFG::CopSystem::IsPlayerInsideUnlockedSafehouse_::_22_::_dynamic_atexit_destructor_for__sABSafeHouse__);
    }
    v14 = &sABSafeHouse;
    goto LABEL_31;
  }
  return result;
}

// File Line: 1373
// RVA: 0x3EC860
bool __fastcall UFG::CopSystem::AllowSpawnRegionSpawning(UFG::CopSystem *this)
{
  UFG::CopSystem *v1; // rbx
  bool result; // al
  UFG::CopSystem *v3; // rax

  v1 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr[7].__vecDelDtor)()
    || !((unsigned __int8 (__fastcall *)(UFG::CopSystem *))v1->vfptr[113].__vecDelDtor)(v1) )
  {
    return 0;
  }
  v3 = UFG::CopSystem::Instance();
  if ( ((unsigned int (__fastcall *)(UFG::CopSystem *))v3->vfptr[89].__vecDelDtor)(v3) )
    result = v1->mFocusTargetContext.mIsOnFootHeuristic != 0;
  else
    result = 1;
  return result;
}

// File Line: 1404
// RVA: 0x3F07D0
void __fastcall UFG::CopSystem::Update(UFG::CopSystem *this, float deltaTime)
{
  float v2; // xmm9_4
  UFG::CopSystem *v3; // rdi
  Render::DebugDrawContext *v4; // r15
  UFG::OSuiteLeaderboardManager *v5; // rax
  UFG::OSuiteLeaderboardData *v6; // rax
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v7; // rbx
  UFG::SimObjectCharacter *v8; // rax
  UFG::SimObject *v9; // rax
  UFG::TransformNodeComponent *v10; // rbx
  UFG::qVector3 *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm7_4
  __int128 v15; // xmm1
  char *v16; // rbp
  char *v17; // rdx
  signed __int64 v18; // r9
  signed __int64 v19; // r14
  signed __int64 v20; // r10
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *v21; // rax
  UFG::qList<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent,1,0> *v22; // rcx
  __int64 v23; // rax
  float *v24; // rax
  int v25; // esi
  const char **v26; // rbx
  UFG::qColour *v27; // r9
  signed __int64 v28; // rbx
  signed __int64 v29; // rsi
  float v30; // xmm0_4
  bool v31; // bl
  UFG::SimObject *v32; // rax
  signed int v33; // eax
  bool v34; // zf
  bool v35; // sf
  unsigned __int8 v36; // of
  UFG::qSafePointerNode<UFG::EncounterBase>Vtbl *v37; // rax
  UFG::qPropertySet *v38; // rax
  UFG::qStaticSymbol *v39; // rcx
  float *v40; // rax
  float v41; // xmm6_4
  float v42; // xmm0_4
  float v43; // xmm7_4
  float v44; // xmm6_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v45; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v46; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v47; // rax
  __int64 v48; // [rsp+30h] [rbp-98h]
  UFG::CopSystem *v49; // [rsp+D0h] [rbp+8h]
  UFG::qSymbol result; // [rsp+E0h] [rbp+18h]

  v49 = this;
  v2 = deltaTime;
  v3 = this;
  v4 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  UFG::OnlineManager::Instance();
  if ( ((signed int (__fastcall *)(UFG::CopSystem *))v3->vfptr[89].__vecDelDtor)(v3) > 1 )
  {
    v5 = UFG::OSuiteLeaderboardManager::Instance();
    v6 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v5, "StatAwardsSurvivor");
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v6, deltaTime);
  }
  v7 = v3->vfptr;
  v8 = UFG::GetLocalPlayer();
  v7[19].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v3->vfptr, (unsigned int)v8);
  if ( v3->mReloadTuningFiles )
  {
    UFG::qSymbol::create_from_string(&result, sCopsTuningPropertySetName);
    UFG::PropertySetManager::ReloadPropertySet(&result);
    v3->mReloadTuningFiles = 0;
  }
  if ( !v3->mEnable )
    UFG::GameStatAction::Player::SetHeat(0.0);
  v9 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[18].__vecDelDtor)(v3);
  if ( v9 && (v10 = v9->m_pTransformNodeComponent) != 0i64 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v9->m_pTransformNodeComponent);
    v11 = (UFG::qVector3 *)&v10->mWorldTransform.v3;
  }
  else
  {
    v11 = &UFG::qVector3::msZero;
  }
  v12 = v11->y;
  v13 = v11->z;
  v3->mFocusTargetPosition.x = v11->x;
  v3->mFocusTargetPosition.y = v12;
  v3->mFocusTargetPosition.z = v13;
  v14 = UFG::Metrics::msInstance.mSimTime_Temp;
  if ( ((unsigned __int8 (__fastcall *)(UFG::CopSystem *))v3->vfptr[118].__vecDelDtor)(v3) )
  {
    UFG::PropertySetHandle::Bind(&v3->mProperties);
    v15 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                             v3->mProperties.mpPropSet,
                             (UFG::qSymbol *)&CopSym_tunable_stimulus_alive_time.mUID,
                             DEPTH_RECURSE);
    v16 = v3->mStimulusCount;
    v17 = v3->mStimulusCount;
    v18 = 112i64;
    v19 = 116i64;
    v20 = 116i64;
    do
    {
      *v17 = 0;
      if ( *(v17 - 116) )
      {
        v21 = UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList.mNode.mNext - 4;
        if ( (UFG::qList<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent,1,0> *)&UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList.mNode.mNext[-4] != &UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList - 4 )
        {
          do
          {
            v22 = (UFG::qList<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent,1,0> *)&v21[4].mNext[-4];
            v23 = *(__int64 *)((char *)&v21->mPrev + v18);
            if ( v23 )
            {
              v24 = (float *)(v23 + 32);
              if ( v24 )
              {
                if ( *(float *)&v15 >= (float)(v14 - *v24) )
                  ++*v17;
              }
            }
            v21 = &v22->mNode;
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
      Render::DebugDrawContext::DrawTextA(v4, 40, 80, &UFG::qColour::White, "Tracking stimulus for heat generation:");
      v25 = 90;
      v26 = UFG::g_StimulusName;
      do
      {
        if ( *(v16 - 116) )
        {
          v27 = &UFG::qColour::White;
          if ( *v16 )
            v27 = &UFG::qColour::Yellow;
          LODWORD(v48) = (unsigned __int8)*v16;
          Render::DebugDrawContext::DrawTextA(v4, 60, v25, v27, "%s: %d", *v26, v48);
          v25 += 10;
        }
        ++v16;
        ++v26;
        --v19;
      }
      while ( v19 );
      v3 = v49;
    }
  }
  v28 = (signed __int64)&v3->mHeatEvents[0].mTracked;
  v29 = 26i64;
  do
  {
    if ( !*(_BYTE *)v28 && (float)(UFG::Metrics::msInstance.mSimTime_Temp - *(float *)(v28 - 4)) > 0.5 )
    {
      if ( !(_S10_5 & 1) )
      {
        _S10_5 |= 1u;
        UFG::CopSystem::CopSystem(&sCopSystem);
        atexit(UFG::CopSystem::Instance_::_2_::_dynamic_atexit_destructor_for__sCopSystem__);
      }
      UFG::CopSystem::mspInstance = &sCopSystem;
      sCopSystem.vfptr[99].__vecDelDtor(
        (UFG::qSafePointerNode<UFG::EncounterBase> *)&sCopSystem,
        *(unsigned int *)(v28 + 4));
      *(float *)(v28 - 4) = UFG::Metrics::msInstance.mSimTime_Temp;
      *(_BYTE *)v28 = 1;
    }
    v28 += 12i64;
    --v29;
  }
  while ( v29 );
  v30 = v3->mLastHeatEventTimer;
  if ( v30 > 0.0 )
  {
    v30 = v30 - v2;
    if ( v30 <= 0.0 )
      v30 = 0.0;
    v3->mLastHeatEventTimer = v30;
    if ( v30 == 0.0 )
    {
      v3->mLastHeatEventIndex = 0;
    }
    else if ( v3->mLastHeatEventIndex == eHEATEVENT_NONE )
    {
      v3->mLastHeatEventTimer = 0.0;
    }
  }
  v31 = v3->mFocusTargetContext.mIsOnFootHeuristic;
  v32 = (UFG::SimObject *)((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[18].__vecDelDtor)(v3);
  UFG::EncounterUnitContext::Update(&v3->mFocusTargetContext, v32, v2);
  if ( v31 && !v3->mFocusTargetContext.mIsOnFootHeuristic )
  {
    v33 = v3->mHeatLevel;
    if ( v33 >= 1 )
    {
      v36 = __OFSUB__(v33, 2);
      v34 = v33 == 2;
      v35 = v33 - 2 < 0;
      v37 = v3->vfptr;
      if ( (unsigned __int8)(v35 ^ v36) | v34 )
      {
        v3->mFocusTargetContext.mOpenFired = 1;
        ((void (__fastcall *)(UFG::CopSystem *, signed __int64, signed __int64))v37[88].__vecDelDtor)(v3, 2i64, 25i64);
      }
      else
      {
        v37[111].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v3->vfptr, 25u);
      }
      ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[23].__vecDelDtor)(v3);
    }
  }
  if ( v3->mHeatLevel >= 1 )
  {
    v38 = (UFG::qPropertySet *)((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[33].__vecDelDtor)(v3);
    if ( v38 )
    {
      v39 = &EncounterSym_ambient_density_invehicle;
      if ( v3->mFocusTargetContext.mIsOnFootHeuristic )
        v39 = &EncounterSym_ambient_density_onfoot;
      result.mUID = v39->mUID;
      v40 = UFG::qPropertySet::Get<float>(v38, &result, DEPTH_RECURSE);
      if ( v40 )
      {
        v41 = *v40;
        if ( *v40 >= 0.0 )
        {
          UFG::PedSpawnManager::GetInstance();
          v30 = v41;
          UFG::PedSpawnManager::AdjustCopSystemDensityModifier(v41);
          UFG::WheeledVehicleManager::mMaxRoadDensityScale = v41;
        }
      }
    }
  }
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[38].__vecDelDtor)(v3);
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[40].__vecDelDtor)(v3);
  UFG::CopSystem::ApplySpeedCap(v3, v30);
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[39].__vecDelDtor)(v3);
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[112].__vecDelDtor)(v3);
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[76].__vecDelDtor)(v3);
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[41].__vecDelDtor)(v3);
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[114].__vecDelDtor)(v3);
  ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[116].__vecDelDtor)(v3);
  if ( !v3->mpArrestRightHumanCop.m_pPointer )
    ((void (__fastcall *)(UFG::CopSystem *))v3->vfptr[83].__vecDelDtor)(v3);
  v42 = v3->mOnFootNoSprintTimer - v2;
  if ( v42 <= 0.0 )
    v42 = 0.0;
  v3->mOnFootNoSprintTimer = v42;
  if ( v3->mpArrestRightHumanCop.m_pPointer )
  {
    v43 = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::PropertySetHandle::Bind(&v3->mProperties);
    v44 = v43 - v3->mArrestRightTimestamp;
    if ( v44 > *UFG::qPropertySet::Get<float>(
                  v3->mProperties.mpPropSet,
                  (UFG::qSymbol *)&EncounterSym_arrest_right_timeout_timer.mUID,
                  DEPTH_RECURSE) )
    {
      v45 = &v3->mpArrestRightHumanCop;
      if ( v3->mpArrestRightHumanCop.m_pPointer )
      {
        v46 = v45->mPrev;
        v47 = v3->mpArrestRightHumanCop.mNext;
        v46->mNext = v47;
        v47->mPrev = v46;
        v45->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v45->mPrev;
        v3->mpArrestRightHumanCop.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mpArrestRightHumanCop.mPrev;
      }
      v3->mpArrestRightHumanCop.m_pPointer = 0i64;
      v3->mArrestRightTimestamp = v43;
    }
  }
  if ( ((signed int (__fastcall *)(UFG::CopSystem *))v3->vfptr[89].__vecDelDtor)(v3) > 0 )
  {
    LOBYTE(result.mUID) = 0;
    if ( (unsigned __int8)UFG::CopSystem::IsPlayerInsideUnlockedSafehouse(v3, (bool *)&result) )
    {
      v3->mIsSafehouseInstantCooldownActive = result.mUID;
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
void __usercall UFG::CopSystem::ApplySpeedCap(UFG::CopSystem *this@<rcx>, float a2@<xmm0>)
{
  __int64 v2; // rbp
  UFG::CopSystem *v3; // rsi
  UFG::EncounterUnitComponent *v4; // rdi
  char v5; // r14
  UFG::SimObject *v6; // rax
  UFG::TransformNodeComponent *v7; // rbx
  float v8; // xmm6_4
  float v9; // xmm7_4
  float *v10; // rax
  UFG::SimObjectCVBase *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::AiDriverComponent *v13; // rax
  UFG::AiDriverComponent *v14; // rdi

  v2 = 0i64;
  v3 = this;
  if ( this->mVehicles.size )
  {
    do
    {
      v4 = v3->mVehicles.p[v2];
      if ( v4->mEngaged )
      {
        v5 = ((__int64 (__fastcall *)(UFG::CopSystem *))v3->vfptr[16].__vecDelDtor)(v3);
        if ( !v5 )
        {
          if ( v4->m_pSimObject )
          {
            ((void (__fastcall *)(UFG::CopSystem *, _QWORD, UFG::EncounterUnitComponent *))v3->vfptr[17].__vecDelDtor)(
              v3,
              0i64,
              v4);
            v6 = v4->m_pSimObject;
            if ( v6 )
            {
              v7 = v6->m_pTransformNodeComponent;
              if ( v7 )
              {
                UFG::TransformNodeComponent::UpdateWorldTransform(v6->m_pTransformNodeComponent);
                v8 = v3->mFocusTargetPosition.x - v7->mWorldTransform.v3.x;
                v9 = v3->mFocusTargetPosition.y - v7->mWorldTransform.v3.y;
                UFG::PropertySetHandle::Bind(&v3->mProperties);
                v10 = UFG::qPropertySet::Get<float>(
                        v3->mProperties.mpPropSet,
                        (UFG::qSymbol *)&EncounterSym_disengage_vehicle_radius_ratio.mUID,
                        DEPTH_RECURSE);
                if ( (float)((float)(v9 * v9) + (float)(v8 * v8)) > (float)((float)(a2 * *v10) * (float)(a2 * *v10)) )
                  v5 = 1;
              }
            }
          }
        }
        v11 = (UFG::SimObjectCVBase *)v4->m_pSimObject;
        if ( v11 )
        {
          v12 = v11->m_Flags;
          if ( (v12 >> 14) & 1 )
          {
            v13 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v11);
          }
          else if ( (v12 & 0x8000u) == 0 )
          {
            if ( (v12 >> 13) & 1 )
            {
              v13 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v11->vfptr,
                                                UFG::AiDriverComponent::_TypeUID);
            }
            else if ( (v12 >> 12) & 1 )
            {
              v13 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v11->vfptr,
                                                UFG::AiDriverComponent::_TypeUID);
            }
            else
            {
              v13 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v11->vfptr,
                                                UFG::AiDriverComponent::_TypeUID);
            }
          }
          else
          {
            v13 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v11);
          }
          v14 = v13;
          if ( v13 )
          {
            if ( v5 )
            {
              UFG::PropertySetHandle::Bind(&v3->mProperties);
              a2 = *UFG::qPropertySet::Get<float>(
                      v3->mProperties.mpPropSet,
                      (UFG::qSymbol *)&EncounterSym_disengage_vehicle_topspeed.mUID,
                      DEPTH_RECURSE)
                 * 0.27777779;
              v14->m_DesiredSpeedLimit = a2;
            }
            else
            {
              v13->m_DesiredSpeedLimit = -1.0;
            }
          }
        }
      }
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v3->mVehicles.size );
  }
}

// File Line: 1863
// RVA: 0x3EDC00
void __fastcall UFG::CopSystem::HandleArrest(UFG::CopSystem *this, UFG::SimObject *pSource, UFG::SimObject *pTarget)
{
  UFG::SimObjectCharacter *v3; // rbx
  UFG::CopSystem *v4; // rdi
  UFG::SceneObjectProperties *v5; // rax
  unsigned __int16 v6; // cx
  UFG::SimComponent *v7; // rax
  UFG::ProgressionTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax
  unsigned int v10; // edx

  v3 = (UFG::SimObjectCharacter *)pTarget;
  v4 = this;
  if ( pTarget )
  {
    v5 = pTarget->m_pSceneObj;
    if ( v5 )
    {
      if ( v5->mpWritableProperties || v5->mpConstProperties )
      {
        v6 = pTarget->m_Flags;
        if ( (v6 >> 14) & 1 )
        {
          v7 = pTarget->m_Components.p[8].m_pComponent;
        }
        else if ( (v6 & 0x8000u) == 0 )
        {
          if ( (v6 >> 13) & 1 )
            v7 = UFG::SimObjectGame::GetComponentOfTypeHK(
                   (UFG::SimObjectGame *)pTarget,
                   UFG::MissionFailConditionComponent::_TypeUID);
          else
            v7 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    (UFG::SimObjectGame *)pTarget,
                                    UFG::MissionFailConditionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                      pTarget,
                                                                                      UFG::MissionFailConditionComponent::_TypeUID);
        }
        else
        {
          v7 = pTarget->m_Components.p[8].m_pComponent;
        }
        if ( v7 && BYTE4(v7[1].m_BoundComponentHandles.mNode.mPrev) )
        {
          v8 = UFG::ProgressionTracker::Instance();
          UFG::ProgressionTracker::SetRestoreType(v8, RestoreType_PoliceStation, 1);
          UFG::MissionFailConditionComponent::FailObject(
            (UFG::SimObject *)&v3->vfptr,
            (UFG::qSymbol *)&qSymbol_ArrestFailCaption.mUID);
        }
      }
    }
  }
  if ( v3 == UFG::GetLocalPlayer() )
  {
    v9 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v9, TimesArrested, 1);
    v10 = UI_HASH_CLEANUPMINIGAME_6;
    v4->mStats.mFinishReason = 1;
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      v10,
      0xFFFFFFFF);
  }
}

// File Line: 1890
// RVA: 0x3F02D0
void __fastcall UFG::CopSystem::Replenish(UFG::CopSystem *this)
{
  JUMPOUT(this->mIsExcludingPlayerForRestOfChase, 0, UFG::EncounterBase::Replenish);
}

// File Line: 1898
// RVA: 0x3EC8C0
void __fastcall UFG::CopSystem::ApplyReducedRadius(UFG::CopSystem *this)
{
  UFG::CopSystem *v1; // rdi
  UFG::GameStatTracker *v2; // rax
  signed int v3; // eax
  UFG::PropertySetHandle *v4; // rcx
  UFG::qStaticSymbol *v5; // rdx

  v1 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr[16].__vecDelDtor)() )
  {
    v2 = UFG::GameStatTracker::Instance();
    v3 = UFG::GameStatTracker::GetStat(v2, CopDrivingStage);
    v4 = &v1->mProperties;
    if ( v3 < 5 )
    {
      UFG::PropertySetHandle::Bind(v4);
      v1->mReducedRadiusTimer = *UFG::qPropertySet::Get<float>(
                                   v1->mProperties.mpPropSet,
                                   (UFG::qSymbol *)&CopSym_reduced_radius_timer.mUID,
                                   DEPTH_RECURSE);
      UFG::PropertySetHandle::Bind(&v1->mProperties);
      v5 = &CopSym_reduced_radius_percentage;
    }
    else
    {
      UFG::PropertySetHandle::Bind(v4);
      v1->mReducedRadiusTimer = *UFG::qPropertySet::Get<float>(
                                   v1->mProperties.mpPropSet,
                                   (UFG::qSymbol *)&CopSym_reduced_radius_timer_perk.mUID,
                                   DEPTH_RECURSE);
      UFG::PropertySetHandle::Bind(&v1->mProperties);
      v5 = &CopSym_reduced_radius_percentage_perk;
    }
    v1->mReducedRadiusPercentage = *UFG::qPropertySet::Get<float>(
                                      v1->mProperties.mpPropSet,
                                      (UFG::qSymbol *)&v5->mUID,
                                      DEPTH_RECURSE);
  }
}

// File Line: 1917
// RVA: 0x3ED420
void __fastcall UFG::CopSystem::GenerateHeatEvent(UFG::CopSystem *this, UFG::eHeatEventEnum heatEvent)
{
  UFG::CopSystem *v2; // r15
  __int64 v3; // rdx
  float v4; // xmm6_4
  signed __int64 v5; // r14
  bool *v6; // r12
  signed __int64 v7; // r13
  float v8; // xmm7_4
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *v9; // rbx
  __int64 v10; // rax
  UFG::qList<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent,1,0> *v11; // rdi
  float *v12; // rax
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *v13; // rax
  UFG::qNode<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent> *v14; // rsi
  __m128 v15; // xmm1
  float v16; // xmm0_4
  UFG::SimObjectGame *v17; // rcx
  UFG::SimComponent *v18; // rax
  unsigned __int16 v19; // dx

  v2 = this;
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
    v4 = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::PropertySetHandle::Bind(&v2->mProperties);
    v5 = 112i64;
    v6 = v2->mStimulusWatchList;
    v7 = 116i64;
    v8 = *UFG::qPropertySet::Get<float>(
            v2->mProperties.mpPropSet,
            (UFG::qSymbol *)&CopSym_tunable_stimulus_alive_time.mUID,
            DEPTH_RECURSE);
    do
    {
      if ( *v6 )
      {
        v9 = UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList.mNode.mNext - 4;
        if ( (UFG::qList<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent,1,0> *)&UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList.mNode.mNext[-4] != &UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList - 4 )
        {
          do
          {
            v10 = *(__int64 *)((char *)&v9->mPrev + v5);
            v11 = (UFG::qList<UFG::StimulusReceiverComponent,UFG::StimulusReceiverComponent,1,0> *)&v9[4].mNext[-4];
            if ( v10 )
            {
              v12 = (float *)(v10 + 32);
              if ( v12 )
              {
                if ( (float)(v4 - *v12) <= v8 )
                {
                  v13 = v9[2].mNext;
                  if ( v13 )
                  {
                    v14 = v13[5].mNext;
                    if ( v14 )
                    {
                      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v13[5].mNext);
                      v15 = (__m128)HIDWORD(v14[11].mPrev);
                      v16 = *(float *)&v14[11].mPrev - v2->mFocusTargetPosition.x;
                      v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] - v2->mFocusTargetPosition.y)
                                              * (float)(v15.m128_f32[0] - v2->mFocusTargetPosition.y))
                                      + (float)(v16 * v16);
                      if ( COERCE_FLOAT(_mm_sqrt_ps(v15)) < sCopSystem_WitnessRadius )
                      {
                        v17 = (UFG::SimObjectGame *)v9[2].mNext;
                        if ( v17 )
                        {
                          v19 = v17->m_Flags;
                          if ( (v19 >> 14) & 1 )
                          {
                            v18 = v17->m_Components.p[17].m_pComponent;
                          }
                          else if ( (v19 & 0x8000u) == 0 )
                          {
                            if ( (v19 >> 13) & 1 )
                            {
                              v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::CopUnitComponent::_TypeUID);
                            }
                            else if ( (v19 >> 12) & 1 )
                            {
                              v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::CopUnitComponent::_TypeUID);
                            }
                            else
                            {
                              v18 = UFG::SimObject::GetComponentOfType(
                                      (UFG::SimObject *)&v17->vfptr,
                                      UFG::CopUnitComponent::_TypeUID);
                            }
                          }
                          else
                          {
                            v18 = v17->m_Components.p[17].m_pComponent;
                          }
                        }
                        else
                        {
                          v18 = 0i64;
                        }
                        UFG::UIHKScreenHud::AddWitness((UFG::qVector3 *)&v14[11], v18 != 0i64);
                      }
                    }
                  }
                }
              }
            }
            v9 = &v11->mNode;
          }
          while ( v11 != &UFG::StimulusReceiverComponent::s_StimulusReceiverComponentList - 4 );
        }
      }
      v5 += 8i64;
      ++v6;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 1964
// RVA: 0x3ECBA0
float __fastcall UFG::CopSystem::CalculateMultiplier(UFG::CopSystem *this, UFG::eHeatEventEnum heatEvent)
{
  UFG::CopSystem *v2; // rbx
  __int64 v3; // rax
  unsigned __int8 v4; // r8
  __int64 v5; // rax
  unsigned __int8 v6; // cl
  unsigned __int8 v7; // al
  float v8; // xmm7_4
  UFG::PropertySetHandle *v9; // rcx
  UFG::qStaticSymbol *v10; // rdx

  v2 = this;
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
    v9 = &v2->mProperties;
    if ( v4 > 5u )
    {
      if ( v4 > 0xCu )
      {
        UFG::PropertySetHandle::Bind(v9);
        v10 = &CopSym_multiplier_density_thirdteen_up;
      }
      else
      {
        UFG::PropertySetHandle::Bind(v9);
        v10 = &CopSym_multiplier_density_six_to_twelve;
      }
    }
    else
    {
      UFG::PropertySetHandle::Bind(v9);
      v10 = &CopSym_multiplier_density_one_to_five;
    }
    v8 = *UFG::qPropertySet::Get<float>(v2->mProperties.mpPropSet, (UFG::qSymbol *)&v10->mUID, DEPTH_RECURSE);
  }
  return (float)(1.0 - UFG::PlayerBuffTracker::GetHeatLevelReductionPercent()) * v8;
}

// File Line: 2031
// RVA: 0x3ECC80
void __usercall UFG::CopSystem::CommitHeatEvent(UFG::CopSystem *this@<rcx>, UFG::eHeatEventEnum heatEvent@<edx>, float a3@<xmm0>)
{
  __int64 v3; // rdi
  UFG::CopSystem *v4; // rbx
  __int128 v5; // xmm9
  float v6; // xmm10_4
  float v7; // xmm7_4
  UFG::ProgressionTracker *v8; // rax
  float v9; // xmm6_4
  float v10; // xmm8_4
  UFG::GameStatTracker *v11; // rax
  float v12; // xmm0_4
  char *v13; // rax
  UFG::qString *v14; // rax
  char *v15; // r9
  UFG::qString result; // [rsp+48h] [rbp-80h]

  v3 = heatEvent;
  v4 = this;
  if ( this->mEnable && !this->mIsExcludingPlayerForRestOfChase )
  {
    UFG::PropertySetHandle::Bind(&this->mProperties);
    v5 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                            v4->mProperties.mpPropSet,
                            CopSystemProperty_stimulus[v3],
                            DEPTH_RECURSE);
    v4->vfptr[119].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr, v3);
    v6 = a3;
    v7 = *(float *)&FLOAT_1_0;
    v8 = UFG::ProgressionTracker::Instance();
    if ( UFG::ProgressionTracker::IsRunningCriticalActiveMaster(v8) )
      v7 = sCopSystem_ActiveMissionMultiplier;
    v9 = (float)(a3 * *(float *)&v5) * v7;
    v4->vfptr[87].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)&v4->vfptr, v4->mMaxHeatLevel);
    v10 = a3;
    v11 = UFG::GameStatTracker::Instance();
    v12 = UFG::GameStatTracker::GetStat(v11, Heat) + v9;
    if ( v12 >= v10 )
      v12 = v10;
    UFG::GameStatAction::Player::SetHeat(v12);
    v13 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)CopSystemProperty_stimulus[v3]);
    v14 = UFG::qString::FormatEx(
            &result,
            "DEBUG: Last committed HeatEvent(%d - %s) - Base(%.2f) X (%.2f) X (%.2f) = (%.2f)",
            (unsigned int)v3,
            v13,
            *(float *)&v5,
            v6,
            v7,
            v9,
            -2i64);
    UFG::qString::Set(&v4->mLastHeatEventCaption, v14->mData, v14->mLength, 0i64, 0);
    UFG::qString::~qString(&result);
    v15 = v4->mLastHeatEventCaption.mData;
    UFG::qPrintChannel::Print(&UFG::gPrintChannel_HK_Cops, OUTPUT_LEVEL_DEBUG, "[CopSystem]: %s\n");
    v4->mLastHeatEventIndex = v3;
    UFG::PropertySetHandle::Bind(&v4->mProperties);
    v4->mLastHeatEventTimer = *UFG::qPropertySet::Get<float>(
                                 v4->mProperties.mpPropSet,
                                 (UFG::qSymbol *)&EncounterSym_last_heat_event_timer.mUID,
                                 DEPTH_RECURSE);
    v4->mCooldownAllowed = 0;
    UFG::CopSystem::HandleHeatEvent(v4);
  }
}

// File Line: 2065
// RVA: 0x3F05E0
void __usercall UFG::CopSystem::SetMaxHeatLevel(UFG::CopSystem *this@<rcx>, int maxHeatLevel@<edx>, float a3@<xmm0>)
{
  int v3; // eax
  __int64 v4; // rdx
  UFG::GameStatTracker *v5; // rax

  v3 = maxHeatLevel;
  this->mMaxHeatLevel = maxHeatLevel;
  if ( maxHeatLevel != -1 )
  {
    v4 = (unsigned int)this->mHeatLevel;
    if ( v3 < (signed int)v4 )
      v4 = (unsigned int)v3;
    this->vfptr[87].__vecDelDtor((UFG::qSafePointerNode<UFG::EncounterBase> *)this, v4);
    v5 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v5, Heat, a3);
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
bool __fastcall UFG::CopSystem::AcquireArrestRight(UFG::CopSystem *this, UFG::SimObject *pCop)
{
  UFG::SimObject *v2; // rbp
  UFG::SimObject *v3; // rdi
  UFG::CopSystem *v4; // rsi
  bool result; // al
  UFG::TransformNodeComponent *v6; // rbx
  UFG::SimComponent *v7; // rax
  unsigned __int16 v8; // cx
  UFG::CopSystem *v9; // rcx
  UFG::CopSystem *v10; // rax
  float *v11; // r14
  float v12; // xmm6_4
  float v13; // xmm6_4
  UFG::TransformNodeComponent *v14; // rbx
  __m128 v15; // xmm8
  float v16; // xmm7_4
  float v17; // xmm6_4
  UFG::TransformNodeComponent *v18; // rbp
  __m128 v19; // xmm2
  float v20; // xmm7_4
  __m128 v21; // xmm2
  float v22; // xmm6_4
  __int128 v23; // xmm0

  v2 = this->mpArrestRightHumanCop.m_pPointer;
  v3 = pCop;
  v4 = this;
  if ( v2 == pCop )
    return 1;
  v6 = 0i64;
  if ( pCop )
  {
    v8 = pCop->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v7 = pCop->m_Components.p[16].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pCop, UFG::EncounterUnitComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)pCop, UFG::EncounterUnitComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType(pCop, UFG::EncounterUnitComponent::_TypeUID);
      }
    }
    else
    {
      v7 = pCop->m_Components.p[16].m_pComponent;
    }
  }
  else
  {
    v7 = 0i64;
  }
  v9 = v4;
  if ( v7 )
  {
    v10 = *(UFG::CopSystem **)&v7[1].m_TypeUID;
    if ( v10 )
      v9 = v10;
  }
  v11 = (float *)((__int64 (*)(void))v9->vfptr[20].__vecDelDtor)();
  if ( v2 )
  {
    v18 = v2->m_pTransformNodeComponent;
    if ( v3 )
      v6 = v3->m_pTransformNodeComponent;
    if ( v18 && v6 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v18);
      v19 = (__m128)LODWORD(v18->mWorldTransform.v3.y);
      v19.m128_f32[0] = (float)((float)((float)(v19.m128_f32[0] - v11[1]) * (float)(v19.m128_f32[0] - v11[1]))
                              + (float)((float)(v18->mWorldTransform.v3.x - *v11)
                                      * (float)(v18->mWorldTransform.v3.x - *v11)))
                      + (float)((float)(v18->mWorldTransform.v3.z - v11[2]) * (float)(v18->mWorldTransform.v3.z - v11[2]));
      LODWORD(v20) = (unsigned __int128)_mm_sqrt_ps(v19);
      UFG::TransformNodeComponent::UpdateWorldTransform(v6);
      v21 = (__m128)LODWORD(v6->mWorldTransform.v3.y);
      v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] - v11[1]) * (float)(v21.m128_f32[0] - v11[1]))
                              + (float)((float)(v6->mWorldTransform.v3.x - *v11)
                                      * (float)(v6->mWorldTransform.v3.x - *v11)))
                      + (float)((float)(v6->mWorldTransform.v3.z - v11[2]) * (float)(v6->mWorldTransform.v3.z - v11[2]));
      LODWORD(v22) = (unsigned __int128)_mm_sqrt_ps(v21);
      UFG::PropertySetHandle::Bind(&v4->mProperties);
      v23 = *(unsigned int *)UFG::qPropertySet::Get<float>(
                               v4->mProperties.mpPropSet,
                               (UFG::qSymbol *)&EncounterSym_arrest_right_closer_distance_threshold.mUID,
                               DEPTH_RECURSE);
      if ( v22 < *(float *)&v23 )
        *(float *)&v23 = v22;
      if ( (float)(*(float *)&v23 + v22) < v20 )
      {
        UFG::qSafePointer<Creature,Creature>::operator=(
          (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v4->mpArrestRightHumanCop,
          (UFG::SimComponent *)v3);
        v4->mArrestRightTimestamp = UFG::Metrics::msInstance.mSimTime_Temp;
      }
    }
  }
  else
  {
    v12 = UFG::Metrics::msInstance.mSimTime_Temp;
    UFG::PropertySetHandle::Bind(&v4->mProperties);
    v13 = v12 - v4->mArrestRightTimestamp;
    if ( v13 > *UFG::qPropertySet::Get<float>(
                  v4->mProperties.mpPropSet,
                  (UFG::qSymbol *)&EncounterSym_arrest_right_cooldown_timer.mUID,
                  DEPTH_RECURSE) )
    {
      if ( v3 )
      {
        v14 = v3->m_pTransformNodeComponent;
        if ( v14 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v3->m_pTransformNodeComponent);
          v15 = (__m128)LODWORD(v14->mWorldTransform.v3.y);
          v16 = v14->mWorldTransform.v3.x - *v11;
          v15.m128_f32[0] = v15.m128_f32[0] - v11[1];
          v17 = v14->mWorldTransform.v3.z - v11[2];
          UFG::PropertySetHandle::Bind(&v4->mProperties);
          v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v16 * v16))
                          + (float)(v17 * v17);
          if ( COERCE_FLOAT(_mm_sqrt_ps(v15)) < *UFG::qPropertySet::Get<float>(
                                                   v4->mProperties.mpPropSet,
                                                   (UFG::qSymbol *)&EncounterSym_arrest_right_distance_threshold.mUID,
                                                   DEPTH_RECURSE) )
          {
            UFG::qSafePointer<Creature,Creature>::operator=(
              (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v4->mpArrestRightHumanCop,
              (UFG::SimComponent *)v3);
            result = 1;
            v4->mArrestRightTimestamp = UFG::Metrics::msInstance.mSimTime_Temp;
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
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax

  if ( this->mpArrestRightHumanCop.m_pPointer == pCop )
  {
    v2 = &this->mpArrestRightHumanCop;
    if ( this->mpArrestRightHumanCop.m_pPointer )
    {
      v3 = v2->mPrev;
      v4 = this->mpArrestRightHumanCop.mNext;
      v3->mNext = v4;
      v4->mPrev = v3;
      v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
      this->mpArrestRightHumanCop.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&this->mpArrestRightHumanCop.mPrev;
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
  UFG::qString *v2; // rsi
  unsigned int v3; // edi
  const char **v4; // rbx

  v2 = heatEventName;
  v3 = 0;
  v4 = UFG::HeatEventEnumNames;
  while ( !UFG::qString::operator==(v2, *v4) )
  {
    ++v4;
    ++v3;
    if ( (signed __int64)v4 >= (signed __int64)UFG::VehicleOrientationEnumNames )
      return 0i64;
  }
  return v3;
}

// File Line: 2182
// RVA: 0x3F02E0
void __fastcall UFG::CopSystem::ReportInfractionTarget(UFG::CopSystem *this, UFG::SimObject *pWitness, UFG::SimObject *pSuspect)
{
  UFG::SimObject *v3; // rbx
  UFG::SimObjectGame *v4; // r9
  UFG::CopSystem *v5; // rsi
  UFG::TransformNodeComponent *v6; // rdi
  unsigned __int16 v7; // dx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax

  v3 = pSuspect;
  v4 = (UFG::SimObjectGame *)pWitness;
  v5 = this;
  if ( pWitness )
  {
    v6 = pWitness->m_pTransformNodeComponent;
    if ( v6 )
    {
      v7 = pWitness->m_Flags;
      if ( !((v7 >> 14) & 1) && (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CopUnitComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CopUnitComponent::_TypeUID);
        }
        else
        {
          UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::CopUnitComponent::_TypeUID);
        }
      }
      UFG::TransformNodeComponent::UpdateWorldTransform(v6);
      UFG::UIHKScreenHud::AddWitness((UFG::qVector3 *)&v6->mWorldTransform.v3, 0);
    }
  }
  v8 = &v5->mpAmbientSuspect;
  if ( v5->mpAmbientSuspect.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v5->mpAmbientSuspect.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v5->mpAmbientSuspect.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mpAmbientSuspect.mPrev;
  }
  v5->mpAmbientSuspect.m_pPointer = v3;
  if ( v3 )
  {
    v11 = v3->m_SafePointerList.mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mPrev = v11;
    v5->mpAmbientSuspect.mNext = &v3->m_SafePointerList.mNode;
    v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  }
}

// File Line: 2198
// RVA: 0x3ECE90
__int64 __fastcall UFG::CopSystem::CountActualUnits(UFG::CopSystem *this, UFG::EncounterUnit::UnitType unitType)
{
  unsigned int v2; // er8
  UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> **v3; // rax
  UFG::qList<UFG::CopUnitComponent,UFG::CopUnitComponent,1,0> *v4; // rcx

  v2 = 0;
  v3 = &UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mNext[-5].mNext;
  if ( &UFG::CopUnitComponent::s_CopUnitComponentList.mNode.mNext[-5].mNext != (UFG::qNode<UFG::CopUnitComponent,UFG::CopUnitComponent> **)((char *)&UFG::CopUnitComponent::s_CopUnitComponentList - 72) )
  {
    do
    {
      v4 = (UFG::qList<UFG::CopUnitComponent,UFG::CopUnitComponent,1,0> *)&v3[10][-5].mNext;
      if ( *((_DWORD *)v3 + 119) == unitType && (_BYTE)v3[60] & 2 )
        ++v2;
      v3 = &v3[10][-5].mNext;
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
    result = "cops_character_";
  return result;
}

// File Line: 2218
// RVA: 0x3EEB00
void __fastcall UFG::CopSystem::HandleHeatEvent(UFG::CopSystem *this)
{
  UFG::CopSystem *v1; // rbx
  UFG::eHeatEventEnum v2; // ecx
  UFG::SimObjectCharacter *v3; // rax
  UFG::SimComponent *v4; // rdx

  v1 = this;
  v2 = this->mLastHeatEventIndex;
  if ( (unsigned int)(v2 - 4) <= 1 || v2 == 10 )
  {
    v1->mFocusTargetContext.mOpenFired = 1;
    v3 = UFG::GetLocalPlayer();
    if ( v3 )
    {
      v4 = v3->m_Components.p[20].m_pComponent;
      if ( v4 )
      {
        if ( *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v4[1].m_Flags + 31i64)
                       + *(_QWORD *)&v4[1].m_TypeUID
                       + 40) )
          v1->mFocusTargetContext.mOpenFiredWithHostage = 1;
      }
    }
  }
}

