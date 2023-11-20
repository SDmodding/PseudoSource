// File Line: 46
// RVA: 0x157B790
__int64 dynamic_initializer_for__UFG::CarHumanDriverComponent::s_CarHumanDriverComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::CarHumanDriverComponent::s_CarHumanDriverComponentList__);
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
  return atexit(UFG::_dynamic_atexit_destructor_for__gsymCarMiscProperties__);
}

// File Line: 58
// RVA: 0x6675C0
void __fastcall UFG::CarHumanDriverComponent::CarHumanDriverComponent(UFG::CarHumanDriverComponent *this, unsigned int name_uid)
{
  UFG::CarHumanDriverComponent *v2; // rbx
  UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *v3; // rdx
  UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *v4; // rax
  UFG::qPropertySet *v5; // rax
  float *v6; // rax
  int *v7; // rcx
  float v8; // xmm1_4
  float v9; // xmm2_4
  int v10; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::HumanDriverComponent::HumanDriverComponent((UFG::HumanDriverComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CarHumanDriverComponent::`vftable'{for `UFG::SimComponent'};
  v2->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CarHumanDriverComponent::`vftable'{for `UFG::UpdateInterface'};
  v2->mNoCollision = -1.0;
  v4 = UFG::CarHumanDriverComponent::s_CarHumanDriverComponentList.mNode.mPrev;
  UFG::CarHumanDriverComponent::s_CarHumanDriverComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *)&UFG::CarHumanDriverComponent::s_CarHumanDriverComponentList;
  UFG::CarHumanDriverComponent::s_CarHumanDriverComponentList.mNode.mPrev = (UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::CarHumanDriverComponent::_CarHumanDriverComponentTypeUID,
    "CarHumanDriverComponent");
  v5 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&gsymCarMiscProperties.mUID);
  v2->mPropertySet = v5;
  v10 = 0;
  v6 = UFG::qPropertySet::Get<float>(v5, (UFG::qSymbol *)&PhysicsSym_reverseLockoutDelay.mUID, DEPTH_RECURSE);
  v7 = &v10;
  if ( v6 )
    v7 = (int *)v6;
  LODWORD(v2->reverseLockoutDelay) = *v7;
  *(_QWORD *)&v2->nTimeTrialExit = 0i64;
  v2->nTimeTrialUid = -1;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  v2->vPreviousPosition.x = UFG::qVector3::msZero.x;
  v2->vPreviousPosition.y = v8;
  v2->vPreviousPosition.z = v9;
}

// File Line: 76
// RVA: 0x66C320
void __fastcall UFG::CarHumanDriverComponent::~CarHumanDriverComponent(UFG::CarHumanDriverComponent *this)
{
  UFG::CarHumanDriverComponent *v1; // r8
  UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *v2; // rdx
  UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *v3; // rcx
  UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *v4; // rax
  UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *v5; // rcx
  UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::CarHumanDriverComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::CarHumanDriverComponent::`vftable'{for `UFG::UpdateInterface'};
  if ( this == UFG::CarHumanDriverComponent::s_CarHumanDriverComponentpCurrentIterator )
    UFG::CarHumanDriverComponent::s_CarHumanDriverComponentpCurrentIterator = (UFG::CarHumanDriverComponent *)&this->mPrev[-25];
  v2 = (UFG::qNode<UFG::CarHumanDriverComponent,UFG::CarHumanDriverComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::HumanDriverComponent::~HumanDriverComponent((UFG::HumanDriverComponent *)&v1->vfptr);
}

// File Line: 83
// RVA: 0x682960
void __fastcall UFG::CarHumanDriverComponent::OnAttach(UFG::CarHumanDriverComponent *this, UFG::SimObject *object)
{
  UFG::SimObject *v2; // rbx
  UFG::CarHumanDriverComponent *v3; // rdi
  UFG::TransformNodeComponent *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm1_4

  v2 = object;
  v3 = this;
  UFG::HumanDriverComponent::OnAttach((UFG::HumanDriverComponent *)&this->vfptr, object);
  if ( v2 )
  {
    v4 = v2->m_pTransformNodeComponent;
    if ( v4 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v4);
      v5 = v4->mWorldTransform.v3.y;
      v6 = v4->mWorldTransform.v3.z;
      v3->vPreviousPosition.x = v4->mWorldTransform.v3.x;
      v3->vPreviousPosition.y = v5;
      v3->vPreviousPosition.z = v6;
    }
  }
}

// File Line: 94
// RVA: 0x684110
void __fastcall UFG::RemoteDriverComponent::OnDetach(UFG::RemoteDriverComponent *this)
{
  UFG::VehicleDriverInterface::OnDetach((UFG::VehicleDriverInterface *)&this->vfptr);
}

// File Line: 101
// RVA: 0x68D0A0
void __fastcall UFG::CarHumanDriverComponent::TeleportEventHandler(UFG::CarHumanDriverComponent *this, UFG::Event *event)
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
  UFG::SimObject *v2; // rax
  UFG::CarHumanDriverComponent *v3; // rdi
  UFG::TransformNodeComponent *v4; // r15
  unsigned int v5; // ecx
  float v6; // xmm6_4
  UFG::TimeTrial *v7; // rax
  UFG::GameStatTracker *v8; // rax
  UFG::PersistentData::MapFloat *v9; // rbx
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  UFG::qWiseSymbol result; // [rsp+60h] [rbp+8h]

  v2 = this->m_pSimObject;
  v3 = this;
  if ( v2 )
  {
    v4 = v2->m_pTransformNodeComponent;
    if ( v4 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v4);
      if ( (float)((float)((float)(v3->vPreviousPosition.x * v3->vPreviousPosition.x)
                         + (float)(v3->vPreviousPosition.y * v3->vPreviousPosition.y))
                 + (float)(v3->vPreviousPosition.z * v3->vPreviousPosition.z)) != 0.0 )
      {
        v5 = v3->nTimeTrialUid;
        if ( v5 == -1 )
        {
          if ( UFG::RaceManager::TimeTrialEntered(
                 &v3->vPreviousPosition,
                 (UFG::qVector3 *)&v4->mWorldTransform.v3,
                 &v3->nTimeTrialUid,
                 &v3->nTimeTrialExit) )
          {
            v3->fTimeTrialSeconds = 0.0;
          }
          goto LABEL_14;
        }
        v6 = delta_seconds + v3->fTimeTrialSeconds;
        v3->fTimeTrialSeconds = v6;
        v7 = UFG::RaceManager::GetTimeTrial(v5);
        if ( v6 > 10000.0 || !v7 )
          goto LABEL_11;
        if ( UFG::TimeTrial::Exits(
               v7,
               &v3->vPreviousPosition,
               (UFG::qVector3 *)&v4->mWorldTransform.v3,
               v3->nTimeTrialExit) )
        {
          v8 = UFG::GameStatTracker::Instance();
          v9 = UFG::GameStatTracker::GetMapFloat(v8, 0);
          UFG::qSymbol::qSymbol(&result, v3->nTimeTrialUid);
          v10 = UFG::PersistentData::MapFloat::GetStatus(v9, (UFG::qSymbol *)&result);
          if ( v10 == 0.0 || v10 > v3->fTimeTrialSeconds )
            UFG::PersistentData::MapFloat::SetStatus(v9, (UFG::qSymbol *)&result, v3->fTimeTrialSeconds);
LABEL_11:
          v3->nTimeTrialUid = -1;
          goto LABEL_14;
        }
      }
LABEL_14:
      v11 = v4->mWorldTransform.v3.y;
      v12 = v4->mWorldTransform.v3.z;
      v3->vPreviousPosition.x = v4->mWorldTransform.v3.x;
      v3->vPreviousPosition.y = v11;
      v3->vPreviousPosition.z = v12;
      return;
    }
  }
}

// File Line: 149
// RVA: 0x68FE00
void __fastcall UFG::CarHumanDriverComponent::Update(UFG::CarHumanDriverComponent *this, float deltaTime)
{
  UFG::CarHumanDriverComponent *v2; // rbx
  float v3; // xmm9_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rdi
  UFG::Controller *v5; // rcx
  int v6; // edx
  int v7; // edx
  int v8; // edx
  int v9; // edx
  __int64 v10; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  char v13; // bp
  UFG::InputActionData *v14; // rcx
  UFG::InputActionData *v15; // rcx
  UFG::InputActionData *v16; // rcx
  char v17; // si
  UFG::InputActionData *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::TransformNodeComponent *v20; // r15
  float v21; // xmm7_4
  float v22; // xmm6_4
  float v23; // xmm8_4
  int v24; // eax
  UFG::CopSystem *v25; // rax
  float v26; // xmm1_4
  float v27; // xmm6_4
  UFG::OSuiteLeaderboardManager *v28; // rax
  UFG::OSuiteLeaderboardData *v29; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-68h]

  v2 = this;
  v3 = deltaTime;
  UFG::HumanDriverComponent::Update((UFG::HumanDriverComponent *)&this->vfptr, deltaTime);
  UFG::CarHumanDriverComponent::UpdateTimeTrial((UFG::CarHumanDriverComponent *)((char *)v2 - 64), deltaTime);
  v4 = v2->m_BoundComponentHandles.mNode.mPrev;
  v5 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
  v6 = (int)v2->mAudioComponent.mNext;
  *(_QWORD *)&v2->mBreakOnUpdate = v5;
  v7 = v6 - 1;
  if ( !v7 )
    goto LABEL_39;
  v8 = v7 - 1;
  if ( v8 )
  {
    v9 = v8 - 2;
    if ( v9 )
    {
      if ( v9 == 1 )
      {
        LODWORD(v4[6].mNext) |= 2u;
        UFG::CarHumanDriverComponent::StopCollisionFreeDrive((UFG::CarHumanDriverComponent *)((char *)v2 - 64));
      }
      return;
    }
LABEL_39:
    LODWORD(v4[6].mNext) |= 6u;
    UFG::CarHumanDriverComponent::StopCollisionFreeDrive((UFG::CarHumanDriverComponent *)((char *)v2 - 64));
    return;
  }
  if ( v2->mAudioComponent.mPrev )
  {
    v10 = (signed int)v5->mControllerIndex;
    v11 = v4[40].mNext;
    if ( !v11 )
      goto LABEL_42;
    v12 = 0i64;
    if ( BYTE4(v11[37].mNext) & 7 )
      v12 = v4[40].mNext;
    if ( v12 )
      v13 = (LODWORD(v12[68].mNext) >> 4) & 1;
    else
LABEL_42:
      v13 = 1;
    v14 = UFG::ActionDef_AccelerateButton.mDataPerController[v10];
    if ( (v14 && v14->mActionTrue
       || (v15 = UFG::ActionDef_Accelerate.mDataPerController[v10]) != 0i64 && v15->mActionTrue)
      && (v16 = UFG::ActionDef_HandBrake.mDataPerController[v10]) != 0i64
      && v16->mActionTrue )
    {
      v17 = 1;
    }
    else
    {
      v18 = UFG::ActionDef_HandBrake.mDataPerController[v10];
      v17 = 0;
      if ( v18 && v18->mActionTrue )
      {
        v19 = v4[2].mNext;
        v20 = (UFG::TransformNodeComponent *)(v19 ? v19[6].mNext[2].mPrev : 0i64);
        UFG::TransformNodeComponent::UpdateWorldTransform(v20);
        v21 = v20->mWorldTransform.v1.x;
        v22 = v20->mWorldTransform.v1.y;
        v23 = v20->mWorldTransform.v1.z;
        UFG::PhysicsMoverInterface::GetVelocity(
          (UFG::PhysicsMoverInterface *)v2->m_BoundComponentHandles.mNode.mPrev,
          &result);
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(result.y * v22) + (float)(result.x * v21)) + (float)(result.z * v23)) & _xmm) > 2.5 )
        {
          v17 = 0;
          if ( *((float *)&v2->m_BoundComponentHandles.mNode.mPrev[43].mPrev + 1) > 2.5 )
            v17 = 1;
        }
      }
    }
    if ( v13 && v17 )
    {
      v24 = (int)v4[6].mNext;
      LODWORD(v4[6].mPrev) = -1082130432;
      HIDWORD(v4[6].mPrev) = -1082130432;
      LODWORD(v4[6].mNext) = v24 & 0xFFFFFFFB | 0x20;
    }
  }
  if ( (float)(*((float *)&v2->m_BoundComponentHandles.mNode.mPrev[43].mPrev + 1) * 3.5999999) <= UFG::gCollisionFreeDrivingSpeed
    || (v25 = UFG::CopSystem::Instance(),
        ((unsigned int (__fastcall *)(UFG::CopSystem *))v25->vfptr[89].__vecDelDtor)(v25)) )
  {
    UFG::CarHumanDriverComponent::StopCollisionFreeDrive((UFG::CarHumanDriverComponent *)((char *)v2 - 64));
  }
  else
  {
    v26 = v2->mJumpDistance;
    if ( v26 >= 0.0 )
    {
      v27 = (float)(UFG::Metrics::msInstance.mSimTimeScaleInGame * v3) + v26;
      v2->mJumpDistance = v27;
      v28 = UFG::OSuiteLeaderboardManager::Instance();
      v29 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
              v28,
              "StatGamesLongestNoDamageDriving");
      UFG::StatGameManager::UpdateScore(v29, v27, 0);
      if ( v2->mJumpDistance >= 120.0 )
        UFG::AchievementTrophyManager::UnlockAchievementTrophy(16);
    }
    else
    {
      v2->mJumpDistance = 0.0;
    }
  }
}

// File Line: 234
// RVA: 0x68CA00
void __fastcall UFG::CarHumanDriverComponent::StopCollisionFreeDrive(UFG::CarHumanDriverComponent *this)
{
  float v1; // xmm6_4
  UFG::CarHumanDriverComponent *v2; // rbx
  UFG::OSuiteLeaderboardManager *v3; // rax
  UFG::OSuiteLeaderboardData *v4; // rax
  float v5; // xmm6_4
  UFG::OSuiteLeaderboardManager *v6; // rax
  UFG::OSuiteLeaderboardData *v7; // rax

  v1 = this->mNoCollision;
  v2 = this;
  if ( v1 > 0.0 )
  {
    if ( v1 >= UFG::gMinimumStatAwardTimeForCleanDrive )
    {
      v3 = UFG::OSuiteLeaderboardManager::Instance();
      v4 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v3, "StatAwardsSafeDriver");
      UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v4, v1);
    }
    v5 = v2->mNoCollision;
    v6 = UFG::OSuiteLeaderboardManager::Instance();
    v7 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v6, "StatGamesLongestNoDamageDriving");
    UFG::StatGameManager::EndStatGame(v7, (signed int)(float)(v5 * 1000.0));
    v2->mNoCollision = -1.0;
  }
}

