// File Line: 44
// RVA: 0x157B710
__int64 dynamic_initializer_for__UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentList__);
}

// File Line: 45
// RVA: 0x67A350
UFG::ComponentIDDesc *__fastcall UFG::BikeHumanDriverComponent::GetDesc(UFG::BikeHumanDriverComponent *this)
{
  return &UFG::BikeHumanDriverComponent::_TypeIDesc;
}

// File Line: 47
// RVA: 0x1582E60
__int64 UFG::_dynamic_initializer_for__gsymBikeMiscProperties__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Vehicles-BikeMiscProperties", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymBikeMiscProperties, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gsymBikeMiscProperties__);
}

// File Line: 56
// RVA: 0x666DE0
void __fastcall UFG::BikeHumanDriverComponent::BikeHumanDriverComponent(UFG::BikeHumanDriverComponent *this, unsigned int name_uid)
{
  UFG::BikeHumanDriverComponent *v2; // rbx
  UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *v3; // rdx
  UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *v4; // rax
  UFG::qPropertySet *v5; // rax

  v2 = this;
  UFG::HumanDriverComponent::HumanDriverComponent((UFG::HumanDriverComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BikeHumanDriverComponent::`vftable{for `UFG::SimComponent};
  v2->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BikeHumanDriverComponent::`vftable{for `UFG::UpdateInterface};
  *(_QWORD *)&v2->mWheelieTime = 0i64;
  *(_WORD *)&v2->mIsHoodBounce = 256;
  v4 = UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentList.mNode.mPrev;
  UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *)&UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentList;
  UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentList.mNode.mPrev = (UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::BikeHumanDriverComponent::_BikeHumanDriverComponentTypeUID,
    "BikeHumanDriverComponent");
  v5 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&UFG::gsymBikeMiscProperties.mUID);
  v2->mPropertySet = v5;
  v2->reverseLockoutDelay = *UFG::qPropertySet::Get<float>(
                               v5,
                               (UFG::qSymbol *)&PhysicsSym_reverseLockoutDelay.mUID,
                               DEPTH_RECURSE);
}

// File Line: 69
// RVA: 0x66C050
void __fastcall UFG::BikeHumanDriverComponent::~BikeHumanDriverComponent(UFG::BikeHumanDriverComponent *this)
{
  UFG::BikeHumanDriverComponent *v1; // r8
  UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *v2; // rdx
  UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *v3; // rcx
  UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *v4; // rax
  UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *v5; // rcx
  UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BikeHumanDriverComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BikeHumanDriverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentpCurrentIterator )
    UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentpCurrentIterator = (UFG::BikeHumanDriverComponent *)&this->mPrev[-25];
  v2 = (UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *)&this->mPrev;
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

// File Line: 76
// RVA: 0x682680
void __fastcall UFG::BikeHumanDriverComponent::OnAttach(UFG::BikeHumanDriverComponent *this, UFG::SimObject *simObject)
{
  UFG::SimObject *v2; // rbx
  UFG::BikeHumanDriverComponent *v3; // rdi
  UFG::SceneObjectProperties *v4; // rax
  UFG::qPropertySet *v5; // rcx
  UFG::qPropertySet *v6; // rax

  v2 = simObject;
  v3 = this;
  UFG::HumanDriverComponent::OnAttach((UFG::HumanDriverComponent *)&this->vfptr, simObject);
  v4 = v2->m_pSceneObj;
  v5 = v4->mpWritableProperties;
  if ( !v5 )
    v5 = v4->mpConstProperties;
  v6 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v5,
         (UFG::qSymbol *)&component_BikePhysicsMover::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v6 )
    v6 = (UFG::qPropertySet *)UFG::qPropertySet::GetMemImagePtr(v6);
  v3->mCanWheelie = v6[1].mName.mUID != 0;
}

// File Line: 90
// RVA: 0x68F230
void __fastcall UFG::BikeHumanDriverComponent::Update(UFG::BikeHumanDriverComponent *this, float deltaTime)
{
  UFG::BikeHumanDriverComponent *v2; // rdi
  float v3; // xmm9_4
  int v4; // ecx
  UFG::Controller *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rbx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  __int64 v10; // rsi
  float v11; // xmm1_4
  int v12; // eax
  float v13; // xmm2_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rdx
  UFG::PhysicsWheeledVehicle *v16; // rcx
  int v17; // eax
  unsigned int v18; // eax
  UFG::InputActionData *v19; // rcx
  UFG::InputActionData *v20; // rcx
  UFG::InputActionData *v21; // rcx
  UFG::InputActionData *v22; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rax
  UFG::TransformNodeComponent *v24; // rsi
  float v25; // xmm7_4
  float v26; // xmm6_4
  float v27; // xmm8_4
  int v28; // eax
  int v29; // eax
  float v30; // xmm9_4
  float v31; // xmm6_4
  UFG::OSuiteLeaderboardManager *v32; // rax
  UFG::OSuiteLeaderboardData *v33; // rax
  float v34; // xmm9_4
  UFG::OSuiteLeaderboardManager *v35; // rax
  UFG::OSuiteLeaderboardData *v36; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-58h]

  v2 = this;
  v3 = deltaTime;
  UFG::HumanDriverComponent::Update((UFG::HumanDriverComponent *)&this->vfptr, deltaTime);
  v4 = (int)v2->mAudioComponent.mNext;
  v5 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
  v6 = v2->m_BoundComponentHandles.mNode.mPrev;
  *(_QWORD *)&v2->mBreakOnUpdate = v5;
  v7 = v4 - 1;
  if ( !v7 )
    goto LABEL_48;
  v8 = v7 - 1;
  if ( v8 )
  {
    v9 = v8 - 2;
    if ( v9 )
    {
      if ( v9 == 1 )
        LODWORD(v6[6].mNext) |= 2u;
      return;
    }
LABEL_48:
    LODWORD(v6[6].mNext) |= 6u;
    return;
  }
  v10 = (signed int)v5->mControllerIndex;
  v11 = *((float *)&v6[43].mPrev + 1) * 3.5999999;
  if ( !v2->mAudioComponent.mPrev )
    return;
  LODWORD(v6[6].mNext) &= 0xFFFFFFE7;
  v12 = (int)v6[6].mNext;
  if ( !*(&v2->mHangTime.mIsStarted + 1) )
  {
    if ( !BYTE1(v2->mController) )
      goto LABEL_25;
    v13 = *((float *)&v6[5].mNext + 1);
    if ( v13 >= -0.5 || *((float *)&v6[6].mPrev + 1) >= -0.85000002 || v11 < 0.0 )
    {
      if ( v13 <= 0.5 || !(v12 & 4) || v11 <= 20.0 )
      {
LABEL_25:
        if ( !((_QWORD)v6[6].mNext & 0x10) )
        {
          if ( (v19 = UFG::ActionDef_AccelerateButton.mDataPerController[v10]) != 0i64 && v19->mActionTrue
            || (v20 = UFG::ActionDef_Accelerate.mDataPerController[v10]) != 0i64 && v20->mActionTrue )
          {
            v21 = UFG::ActionDef_HandBrake.mDataPerController[v10];
            if ( v21 )
            {
              if ( v21->mActionTrue )
                goto LABEL_51;
            }
          }
          v22 = UFG::ActionDef_HandBrake.mDataPerController[v10];
          if ( v22 && v22->mActionTrue )
          {
            v23 = v2->m_BoundComponentHandles.mNode.mPrev[2].mNext;
            v24 = (UFG::TransformNodeComponent *)(v23 ? v23[6].mNext[2].mPrev : 0i64);
            UFG::TransformNodeComponent::UpdateWorldTransform(v24);
            v25 = v24->mWorldTransform.v1.x;
            v26 = v24->mWorldTransform.v1.y;
            v27 = v24->mWorldTransform.v1.z;
            UFG::PhysicsMoverInterface::GetVelocity(
              (UFG::PhysicsMoverInterface *)v2->m_BoundComponentHandles.mNode.mPrev,
              &result);
            if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(result.y * v26) + (float)(result.x * v25)) + (float)(result.z * v27)) & _xmm) > 2.5
              && *((float *)&v2->m_BoundComponentHandles.mNode.mPrev[43].mPrev + 1) > 2.5 )
            {
LABEL_51:
              v28 = (int)v6[6].mNext;
              LODWORD(v6[6].mPrev) = -1082130432;
              HIDWORD(v6[6].mPrev) = -1082130432;
              LODWORD(v6[6].mNext) = v28 & 0xFFFFFFFB | 0x20;
            }
          }
        }
        LOBYTE(v2->mController) = 0;
        goto LABEL_41;
      }
      v6[6].mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)1065353216;
      v18 = v12 & 0xFFFFFFDB | 0x10;
    }
    else
    {
      v14 = v2->m_BoundComponentHandles.mNode.mPrev;
      v15 = v14[40].mNext;
      if ( v15 )
      {
        v16 = 0i64;
        if ( BYTE4(v15[37].mNext) & 7 )
          v16 = (UFG::PhysicsWheeledVehicle *)v14[40].mNext;
        if ( v16 && !UFG::PhysicsWheeledVehicle::IsWheelOnGround(v16, 1) )
          goto LABEL_25;
      }
      v17 = (int)v6[6].mNext;
      if ( v17 & 1 )
        goto LABEL_25;
      v18 = v17 | 8;
    }
    LODWORD(v6[6].mNext) = v18;
    goto LABEL_25;
  }
  LOBYTE(v2->mController) = UFG::BikeHumanDriverComponent::IsHoodBounce((UFG::BikeHumanDriverComponent *)((char *)v2 - 64));
LABEL_41:
  if ( HIDWORD(v2->mCruiseControl) == 1 )
  {
    v34 = v3 + *(float *)&v2->mCruiseControl;
    *(float *)&v2->mCruiseControl = v34;
    v35 = UFG::OSuiteLeaderboardManager::Instance();
    v36 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v35, "StatGamesWheelieDistance");
    UFG::StatGameManager::UpdateScore(v36, v34, 0);
  }
  else if ( HIDWORD(v2->mCruiseControl) == 2 )
  {
    v29 = (int)v6[6].mNext;
    if ( !(v29 & 8) || _bittest(&v29, 8u) )
    {
      v30 = v3 + *(float *)&v2->mCruiseControl;
      *(float *)&v2->mCruiseControl = v30;
      UFG::GameStatAction::Bike::WheelieDistance(v30);
      v31 = *(float *)&v2->mCruiseControl;
      v32 = UFG::OSuiteLeaderboardManager::Instance();
      v33 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v32, "StatGamesWheelieDistance");
      UFG::StatGameManager::EndStatGame(v33, (signed int)(float)(v31 * 1000.0));
      v2->mCruiseControl = 0i64;
    }
  }
}

// File Line: 216
// RVA: 0x67F040
char __fastcall UFG::BikeHumanDriverComponent::IsHoodBounce(UFG::BikeHumanDriverComponent *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rbx
  UFG::SimComponent *v4; // rax
  UFG::SimObjectCVBase *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::SimObjectVehiclePropertiesComponent *v7; // rax
  UFG::TransformNodeComponent *v8; // rdi
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  char result; // al

  v1 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( !v1 )
    goto LABEL_32;
  v2 = v1->m_Flags;
  if ( (v2 >> 14) & 1 )
  {
    v3 = v1->m_Components.p[15].m_pComponent;
  }
  else if ( (v2 & 0x8000u) == 0 )
  {
    if ( (v2 >> 13) & 1 )
      v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::HitReactionComponent::_TypeUID);
    else
      v4 = (v2 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::HitReactionComponent::_TypeUID);
    v3 = v4;
  }
  else
  {
    v3 = v1->m_Components.p[15].m_pComponent;
  }
  if ( !v3 )
    goto LABEL_32;
  v5 = *(UFG::SimObjectCVBase **)&v3[3].m_TypeUID;
  if ( !v5 )
    goto LABEL_32;
  v6 = v5->m_Flags;
  if ( (v6 >> 14) & 1 )
  {
    v7 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v5);
  }
  else if ( (v6 & 0x8000u) == 0 )
  {
    if ( (v6 >> 13) & 1 )
      v7 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v5->vfptr,
                                                         UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
    else
      v7 = (UFG::SimObjectVehiclePropertiesComponent *)((v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           (UFG::SimObjectGame *)&v5->vfptr,
                                                                           UFG::SimObjectVehiclePropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::SimObjectVehiclePropertiesComponent::_TypeUID));
  }
  else
  {
    v7 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v5);
  }
  if ( !v7 || v7->m_eSimObjectVehicleType != 2 )
    goto LABEL_32;
  v8 = *(UFG::TransformNodeComponent **)&v3[3].m_TypeUID;
  if ( v8 )
    v8 = (UFG::TransformNodeComponent *)v8->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(v8);
  UFG::TransformNodeComponent::UpdateWorldTransform(v8);
  v9 = (float)(v8->mWorldTransform.v0.z * 2.0) + v8->mWorldTransform.v3.z;
  v10 = *(float *)&v3[6].vfptr - (float)((float)(v8->mWorldTransform.v0.x * 2.0) + v8->mWorldTransform.v3.x);
  v11 = *((float *)&v3[6].vfptr + 1) - (float)((float)(v8->mWorldTransform.v0.y * 2.0) + v8->mWorldTransform.v3.y);
  if ( (float)((float)((float)(v11 * v11) + (float)(v10 * v10))
             + (float)((float)(*(float *)&v3[6].m_SafePointerList.mNode.mPrev - v9)
                     * (float)(*(float *)&v3[6].m_SafePointerList.mNode.mPrev - v9))) <= 2.0 )
    result = 1;
  else
LABEL_32:
    result = 0;
  return result;
}

// File Line: 249
// RVA: 0x69B910
void __fastcall UFG::BikeHumanDriverComponent::WheelieStart(UFG::BikeHumanDriverComponent *this)
{
  if ( this->mCanWheelie )
    this->mWheelieState = 1;
}

// File Line: 258
// RVA: 0x69B930
void __fastcall UFG::BikeHumanDriverComponent::WheelieStop(UFG::BikeHumanDriverComponent *this)
{
  if ( this->mWheelieState == 1 )
    this->mWheelieState = 2;
}

