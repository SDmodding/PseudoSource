// File Line: 46
// RVA: 0x157B790
__int64 dynamic_initializer_for__UFG::CarHumanDriverComponent::s_CarHumanDriverComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CarHumanDriverComponent::s_CarHumanDriverComponentList__);
}

// File Line: 47
// RVA: 0x67B420
const char *__fastcall UFG::CarHumanDriverComponent::GetTypeName(UFG::CarHumanDriverComponent *this)
{
  return "CarHumanDriverComponent";
}

// File Line: 49
// RVA: 0x1582EA0
__int64 UFG::_dynamic_initializer_for__gsymCarMiscProperties__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Vehicles-CarMiscProperties", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gsymCarMiscProperties, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gsymCarMiscProperties__);
}

// File Line: 58
// RVA: 0x6675C0
void __fastcall UFG::CarHumanDriverComponent::CarHumanDriverComponent(
        UFG::CarHumanDriverComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *mPrev; // rax
  UFG::qPropertySet *PropertySet; // rax
  float *v5; // rax
  float *v6; // rcx
  float y; // xmm1_4
  float z; // xmm2_4
  int v9; // [rsp+50h] [rbp+18h] BYREF

  UFG::HumanDriverComponent::HumanDriverComponent(this, name_uid);
  this->UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent>::mPrev = &this->UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent>;
  this->UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent>::mNext = &this->UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent>;
  this->UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CarHumanDriverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CarHumanDriverComponent::`vftable{for `UFG::UpdateInterface};
  this->mNoCollision = -1.0;
  mPrev = UFG::CarHumanDriverComponent::s_CarHumanDriverComponentList.mNode.mPrev;
  UFG::CarHumanDriverComponent::s_CarHumanDriverComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent>;
  this->UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent>::mNext = (UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *)&UFG::CarHumanDriverComponent::s_CarHumanDriverComponentList;
  UFG::CarHumanDriverComponent::s_CarHumanDriverComponentList.mNode.mPrev = &this->UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::CarHumanDriverComponent::_CarHumanDriverComponentTypeUID,
    "CarHumanDriverComponent");
  PropertySet = UFG::PropertySetManager::GetPropertySet(&gsymCarMiscProperties);
  this->mPropertySet = PropertySet;
  v9 = 0;
  v5 = UFG::qPropertySet::Get<float>(
         PropertySet,
         (UFG::qArray<unsigned long,0> *)&PhysicsSym_reverseLockoutDelay,
         DEPTH_RECURSE);
  v6 = (float *)&v9;
  if ( v5 )
    v6 = v5;
  this->reverseLockoutDelay = *v6;
  *(_QWORD *)&this->nTimeTrialExit = 0i64;
  this->nTimeTrialUid = -1;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->vPreviousPosition.x = UFG::qVector3::msZero.x;
  this->vPreviousPosition.y = y;
  this->vPreviousPosition.z = z;
}

// File Line: 76
// RVA: 0x66C320
void __fastcall UFG::CarHumanDriverComponent::~CarHumanDriverComponent(UFG::CarHumanDriverComponent *this)
{
  UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *v2; // rdx
  UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *mPrev; // rcx
  UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *mNext; // rax
  UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *v5; // rcx
  UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *v6; // rax

  this->UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CarHumanDriverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CarHumanDriverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::CarHumanDriverComponent::s_CarHumanDriverComponentpCurrentIterator )
    UFG::CarHumanDriverComponent::s_CarHumanDriverComponentpCurrentIterator = (UFG::CarHumanDriverComponent *)&this->UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent>::mPrev[-25];
  v2 = &this->UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent>;
  mPrev = this->UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::HumanDriverComponent::~HumanDriverComponent(this);
}

// File Line: 83
// RVA: 0x682960
void __fastcall UFG::CarHumanDriverComponent::OnAttach(UFG::CarHumanDriverComponent *this, UFG::SimObject *object)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float y; // xmm0_4
  float z; // xmm1_4

  UFG::HumanDriverComponent::OnAttach(this, object);
  if ( object )
  {
    m_pTransformNodeComponent = object->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      y = m_pTransformNodeComponent->mWorldTransform.v3.y;
      z = m_pTransformNodeComponent->mWorldTransform.v3.z;
      this->vPreviousPosition.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
      this->vPreviousPosition.y = y;
      this->vPreviousPosition.z = z;
    }
  }
}

// File Line: 94
// RVA: 0x684110
// attributes: thunk
void __fastcall UFG::RemoteDriverComponent::OnDetach(UFG::RemoteDriverComponent *this)
{
  UFG::VehicleDriverInterface::OnDetach(this);
}

// File Line: 101
// RVA: 0x68D0A0
void __fastcall UFG::CarHumanDriverComponent::TeleportEventHandler(
        UFG::CarHumanDriverComponent *this,
        UFG::Event *event)
{
  float v2; // xmm0_4
  float v3; // xmm1_4

  v2 = *((float *)&event[2].mNext + 1);
  v3 = *(float *)&event[2].m_EventUID;
  this->vPreviousPosition.x = *(float *)&event[2].mNext;
  this->vPreviousPosition.y = v2;
  this->vPreviousPosition.z = v3;
}

// File Line: 106
// RVA: 0x69A380
void __fastcall UFG::CarHumanDriverComponent::UpdateTimeTrial(UFG::CarHumanDriverComponent *this, float delta_seconds)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r15
  unsigned int nTimeTrialUid; // ecx
  float v6; // xmm6_4
  UFG::TimeTrial *TimeTrial; // rax
  UFG::GameStatTracker *v8; // rax
  UFG::PersistentData::MapFloat *MapFloat; // rbx
  float Status; // xmm0_4
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qWiseSymbol result; // [rsp+60h] [rbp+8h] BYREF

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    if ( m_pTransformNodeComponent )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      if ( (float)((float)((float)(this->vPreviousPosition.x * this->vPreviousPosition.x)
                         + (float)(this->vPreviousPosition.y * this->vPreviousPosition.y))
                 + (float)(this->vPreviousPosition.z * this->vPreviousPosition.z)) != 0.0 )
      {
        nTimeTrialUid = this->nTimeTrialUid;
        if ( nTimeTrialUid == -1 )
        {
          if ( UFG::RaceManager::TimeTrialEntered(
                 &this->vPreviousPosition,
                 (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
                 &this->nTimeTrialUid,
                 &this->nTimeTrialExit) )
          {
            this->fTimeTrialSeconds = 0.0;
          }
          goto LABEL_14;
        }
        v6 = delta_seconds + this->fTimeTrialSeconds;
        this->fTimeTrialSeconds = v6;
        TimeTrial = UFG::RaceManager::GetTimeTrial(nTimeTrialUid);
        if ( v6 > 10000.0 || !TimeTrial )
          goto LABEL_11;
        if ( UFG::TimeTrial::Exits(
               TimeTrial,
               &this->vPreviousPosition,
               (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
               this->nTimeTrialExit) )
        {
          v8 = UFG::GameStatTracker::Instance();
          MapFloat = UFG::GameStatTracker::GetMapFloat(v8, BestTimeTrial);
          UFG::qSymbol::qSymbol(&result, this->nTimeTrialUid);
          Status = UFG::PersistentData::MapFloat::GetStatus(MapFloat, (UFG::qSymbol *)&result);
          if ( Status == 0.0 || Status > this->fTimeTrialSeconds )
            UFG::PersistentData::MapFloat::SetStatus(MapFloat, (UFG::qSymbol *)&result, this->fTimeTrialSeconds);
LABEL_11:
          this->nTimeTrialUid = -1;
        }
      }
LABEL_14:
      y = m_pTransformNodeComponent->mWorldTransform.v3.y;
      z = m_pTransformNodeComponent->mWorldTransform.v3.z;
      this->vPreviousPosition.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
      this->vPreviousPosition.y = y;
      this->vPreviousPosition.z = z;
    }
  }
}

// File Line: 149
// RVA: 0x68FE00
void __fastcall UFG::CarHumanDriverComponent::Update(UFG::CarHumanDriverComponent *this, float deltaTime)
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdi
  UFG::Controller *v5; // rcx
  int mNext; // edx
  int v7; // edx
  int v8; // edx
  int v9; // edx
  __int64 mControllerIndex; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  bool v13; // bp
  UFG::InputActionData *v14; // rcx
  UFG::InputActionData *v15; // rcx
  UFG::InputActionData *v16; // rcx
  bool v17; // si
  UFG::InputActionData *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::TransformNodeComponent *v20; // r15
  float x; // xmm7_4
  float y; // xmm6_4
  float z; // xmm8_4
  int v24; // eax
  UFG::CopSystem *v25; // rax
  float mJumpDistance; // xmm1_4
  float v27; // xmm6_4
  UFG::OSuiteLeaderboardManager *v28; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-68h] BYREF

  UFG::HumanDriverComponent::Update(this, deltaTime);
  UFG::CarHumanDriverComponent::UpdateTimeTrial((UFG::CarHumanDriverComponent *)((char *)this - 64), deltaTime);
  mPrev = this->m_BoundComponentHandles.mNode.UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::mPrev;
  v5 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
  mNext = (int)this->mAudioComponent.mNext;
  *(_QWORD *)&this->mBreakOnUpdate = v5;
  v7 = mNext - 1;
  if ( !v7 )
    goto LABEL_38;
  v8 = v7 - 1;
  if ( v8 )
  {
    v9 = v8 - 2;
    if ( v9 )
    {
      if ( v9 == 1 )
      {
        LODWORD(mPrev[6].mNext) |= 2u;
        UFG::CarHumanDriverComponent::StopCollisionFreeDrive((UFG::CarHumanDriverComponent *)((char *)this - 64));
      }
      return;
    }
LABEL_38:
    LODWORD(mPrev[6].mNext) |= 6u;
    UFG::CarHumanDriverComponent::StopCollisionFreeDrive((UFG::CarHumanDriverComponent *)((char *)this - 64));
    return;
  }
  if ( this->mAudioComponent.UFG::HumanDriverComponent::UFG::VehicleDriverInterface::mPrev )
  {
    mControllerIndex = (int)v5->mControllerIndex;
    v11 = mPrev[40].mNext;
    if ( !v11 )
      goto LABEL_12;
    v12 = 0i64;
    if ( (BYTE4(v11[37].mNext) & 7) != 0 )
      v12 = mPrev[40].mNext;
    if ( v12 )
      v13 = ((__int64)v12[68].mNext & 0x10) != 0;
    else
LABEL_12:
      v13 = 1;
    v14 = UFG::ActionDef_AccelerateButton.mDataPerController[mControllerIndex];
    if ( (v14 && v14->mActionTrue
       || (v15 = UFG::ActionDef_Accelerate.mDataPerController[mControllerIndex]) != 0i64 && v15->mActionTrue)
      && (v16 = UFG::ActionDef_HandBrake.mDataPerController[mControllerIndex]) != 0i64
      && v16->mActionTrue )
    {
      v17 = 1;
    }
    else
    {
      v18 = UFG::ActionDef_HandBrake.mDataPerController[mControllerIndex];
      v17 = 0;
      if ( v18 && v18->mActionTrue )
      {
        v19 = mPrev[2].mNext;
        v20 = v19 ? (UFG::TransformNodeComponent *)v19[6].mNext[2].mPrev : 0i64;
        UFG::TransformNodeComponent::UpdateWorldTransform(v20);
        x = v20->mWorldTransform.v1.x;
        y = v20->mWorldTransform.v1.y;
        z = v20->mWorldTransform.v1.z;
        UFG::PhysicsMoverInterface::GetVelocity(
          (UFG::PhysicsMoverInterface *)this->m_BoundComponentHandles.mNode.UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::mPrev,
          &result);
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(result.y * y) + (float)(result.x * x)) + (float)(result.z * z)) & _xmm) > 2.5 )
          v17 = *((float *)&this->m_BoundComponentHandles.mNode.UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::mPrev[43].mPrev
                + 1) > 2.5;
      }
    }
    if ( v13 && v17 )
    {
      v24 = (int)mPrev[6].mNext;
      LODWORD(mPrev[6].mPrev) = -1082130432;
      HIDWORD(mPrev[6].mPrev) = -1082130432;
      LODWORD(mPrev[6].mNext) = v24 & 0xFFFFFFDB | 0x20;
    }
  }
  if ( (float)(*((float *)&this->m_BoundComponentHandles.mNode.UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::mPrev[43].mPrev
               + 1)
             * 3.5999999) <= UFG::gCollisionFreeDrivingSpeed
    || (v25 = UFG::CopSystem::Instance(),
        ((unsigned int (__fastcall *)(UFG::CopSystem *))v25->vfptr[89].__vecDelDtor)(v25)) )
  {
    UFG::CarHumanDriverComponent::StopCollisionFreeDrive((UFG::CarHumanDriverComponent *)((char *)this - 64));
  }
  else
  {
    mJumpDistance = this->mJumpDistance;
    if ( mJumpDistance >= 0.0 )
    {
      v27 = (float)(UFG::Metrics::msInstance.mSimTimeScaleInGame * deltaTime) + mJumpDistance;
      this->mJumpDistance = v27;
      v28 = UFG::OSuiteLeaderboardManager::Instance();
      LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                              v28,
                                              "StatGamesLongestNoDamageDriving");
      UFG::StatGameManager::UpdateScore(LeaderboardDataUsingLeaderboardName, v27, 0);
      if ( this->mJumpDistance >= 120.0 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(16);
    }
    else
    {
      this->mJumpDistance = 0.0;
    }
  }
}

// File Line: 234
// RVA: 0x68CA00
void __fastcall UFG::CarHumanDriverComponent::StopCollisionFreeDrive(UFG::CarHumanDriverComponent *this)
{
  float mNoCollision; // xmm6_4
  UFG::OSuiteLeaderboardManager *v3; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  float v5; // xmm6_4
  UFG::OSuiteLeaderboardManager *v6; // rax
  UFG::OSuiteLeaderboardData *v7; // rax

  mNoCollision = this->mNoCollision;
  if ( mNoCollision > 0.0 )
  {
    if ( mNoCollision >= UFG::gMinimumStatAwardTimeForCleanDrive )
    {
      v3 = UFG::OSuiteLeaderboardManager::Instance();
      LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                              v3,
                                              "StatAwardsSafeDriver");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, mNoCollision);
    }
    v5 = this->mNoCollision;
    v6 = UFG::OSuiteLeaderboardManager::Instance();
    v7 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v6, "StatGamesLongestNoDamageDriving");
    UFG::StatGameManager::EndStatGame(v7, (int)(float)(v5 * 1000.0));
    this->mNoCollision = -1.0;
  }
}

