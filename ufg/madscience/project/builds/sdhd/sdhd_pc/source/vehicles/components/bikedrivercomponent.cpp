// File Line: 44
// RVA: 0x157B710
__int64 dynamic_initializer_for__UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentList__);
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
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gsymBikeMiscProperties__);
}

// File Line: 56
// RVA: 0x666DE0
void __fastcall UFG::BikeHumanDriverComponent::BikeHumanDriverComponent(
        UFG::BikeHumanDriverComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *mPrev; // rax
  UFG::qPropertySet *PropertySet; // rax

  UFG::HumanDriverComponent::HumanDriverComponent(this, name_uid);
  this->UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent>::mPrev = &this->UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent>;
  this->UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent>::mNext = &this->UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent>;
  this->UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BikeHumanDriverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BikeHumanDriverComponent::`vftable{for `UFG::UpdateInterface};
  *(_QWORD *)&this->mWheelieTime = 0i64;
  *(_WORD *)&this->mIsHoodBounce = 256;
  mPrev = UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentList.mNode.mPrev;
  UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent>;
  this->UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent>::mNext = (UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *)&UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentList;
  UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentList.mNode.mPrev = &this->UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::BikeHumanDriverComponent::_BikeHumanDriverComponentTypeUID,
    "BikeHumanDriverComponent");
  PropertySet = UFG::PropertySetManager::GetPropertySet(&UFG::gsymBikeMiscProperties);
  this->mPropertySet = PropertySet;
  this->reverseLockoutDelay = *UFG::qPropertySet::Get<float>(
                                 PropertySet,
                                 (UFG::qArray<unsigned long,0> *)&PhysicsSym_reverseLockoutDelay,
                                 DEPTH_RECURSE);
}

// File Line: 69
// RVA: 0x66C050
void __fastcall UFG::BikeHumanDriverComponent::~BikeHumanDriverComponent(UFG::BikeHumanDriverComponent *this)
{
  UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *v2; // rdx
  UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *mPrev; // rcx
  UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *mNext; // rax
  UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *v5; // rcx
  UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent> *v6; // rax

  this->UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::BikeHumanDriverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::BikeHumanDriverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentpCurrentIterator )
    UFG::BikeHumanDriverComponent::s_BikeHumanDriverComponentpCurrentIterator = (UFG::BikeHumanDriverComponent *)&this->UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent>::mPrev[-25];
  v2 = &this->UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent>;
  mPrev = this->UFG::qNode<UFG::BikeHumanDriverComponent,UFG::BikeHumanDriverComponent>::mPrev;
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

// File Line: 76
// RVA: 0x682680
void __fastcall UFG::BikeHumanDriverComponent::OnAttach(UFG::BikeHumanDriverComponent *this, UFG::SimObject *simObject)
{
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *MemImagePtr; // rax

  UFG::HumanDriverComponent::OnAttach(this, simObject);
  m_pSceneObj = simObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  MemImagePtr = UFG::qPropertySet::Get<UFG::qPropertySet>(
                  mpWritableProperties,
                  (UFG::qArray<unsigned long,0> *)&component_BikePhysicsMover::sPropertyName,
                  DEPTH_RECURSE);
  if ( MemImagePtr )
    MemImagePtr = (UFG::qPropertySet *)UFG::qPropertySet::GetMemImagePtr(MemImagePtr);
  this->mCanWheelie = MemImagePtr[1].mName.mUID != 0;
}

// File Line: 90
// RVA: 0x68F230
void __fastcall UFG::BikeHumanDriverComponent::Update(UFG::BikeHumanDriverComponent *this, float deltaTime)
{
  int mNext; // ecx
  UFG::Controller *v5; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rbx
  int v7; // ecx
  int v8; // ecx
  int v9; // ecx
  __int64 mControllerIndex; // rsi
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
  float x; // xmm7_4
  float y; // xmm6_4
  float z; // xmm8_4
  int v28; // eax
  int v29; // eax
  float v30; // xmm9_4
  float v31; // xmm6_4
  UFG::OSuiteLeaderboardManager *v32; // rax
  UFG::OSuiteLeaderboardData *v33; // rax
  float v34; // xmm9_4
  UFG::OSuiteLeaderboardManager *v35; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-58h] BYREF

  UFG::HumanDriverComponent::Update(this, deltaTime);
  mNext = (int)this->mAudioComponent.mNext;
  v5 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
  mPrev = this->m_BoundComponentHandles.mNode.UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::mPrev;
  *(_QWORD *)&this->mBreakOnUpdate = v5;
  v7 = mNext - 1;
  if ( !v7 )
    goto LABEL_48;
  v8 = v7 - 1;
  if ( v8 )
  {
    v9 = v8 - 2;
    if ( v9 )
    {
      if ( v9 == 1 )
        LODWORD(mPrev[6].mNext) |= 2u;
      return;
    }
LABEL_48:
    LODWORD(mPrev[6].mNext) |= 6u;
    return;
  }
  mControllerIndex = (int)v5->mControllerIndex;
  v11 = *((float *)&mPrev[43].mPrev + 1) * 3.5999999;
  if ( !this->mAudioComponent.UFG::HumanDriverComponent::UFG::VehicleDriverInterface::mPrev )
    return;
  LODWORD(mPrev[6].mNext) &= 0xFFFFFFE7;
  v12 = (int)mPrev[6].mNext;
  if ( !*(&this->mHangTime.mIsStarted + 1) )
  {
    if ( !BYTE1(this->mController) )
      goto LABEL_25;
    v13 = *((float *)&mPrev[5].mNext + 1);
    if ( v13 >= -0.5 || *((float *)&mPrev[6].mPrev + 1) >= -0.85000002 || v11 < 0.0 )
    {
      if ( v13 <= 0.5 || (v12 & 4) == 0 || v11 <= 20.0 )
      {
LABEL_25:
        if ( ((__int64)mPrev[6].mNext & 0x10) == 0 )
        {
          if ( (v19 = UFG::ActionDef_AccelerateButton.mDataPerController[mControllerIndex]) != 0i64 && v19->mActionTrue
            || (v20 = UFG::ActionDef_Accelerate.mDataPerController[mControllerIndex]) != 0i64 && v20->mActionTrue )
          {
            v21 = UFG::ActionDef_HandBrake.mDataPerController[mControllerIndex];
            if ( v21 )
            {
              if ( v21->mActionTrue )
                goto LABEL_39;
            }
          }
          v22 = UFG::ActionDef_HandBrake.mDataPerController[mControllerIndex];
          if ( v22 && v22->mActionTrue )
          {
            v23 = this->m_BoundComponentHandles.mNode.UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::mPrev[2].mNext;
            v24 = v23 ? (UFG::TransformNodeComponent *)v23[6].mNext[2].mPrev : 0i64;
            UFG::TransformNodeComponent::UpdateWorldTransform(v24);
            x = v24->mWorldTransform.v1.x;
            y = v24->mWorldTransform.v1.y;
            z = v24->mWorldTransform.v1.z;
            UFG::PhysicsMoverInterface::GetVelocity(
              (UFG::PhysicsMoverInterface *)this->m_BoundComponentHandles.mNode.UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::mPrev,
              &result);
            if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(result.y * y) + (float)(result.x * x)) + (float)(result.z * z)) & _xmm) > 2.5
              && *((float *)&this->m_BoundComponentHandles.mNode.UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::mPrev[43].mPrev
                 + 1) > 2.5 )
            {
LABEL_39:
              v28 = (int)mPrev[6].mNext;
              LODWORD(mPrev[6].mPrev) = -1082130432;
              HIDWORD(mPrev[6].mPrev) = -1082130432;
              LODWORD(mPrev[6].mNext) = v28 & 0xFFFFFFDB | 0x20;
            }
          }
        }
        LOBYTE(this->mController) = 0;
        goto LABEL_41;
      }
      mPrev[6].mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)1065353216;
      v18 = v12 & 0xFFFFFFCB | 0x10;
    }
    else
    {
      v14 = this->m_BoundComponentHandles.mNode.UFG::HumanDriverComponent::UFG::VehicleDriverInterface::UFG::SimComponent::mPrev;
      v15 = v14[40].mNext;
      if ( v15 )
      {
        v16 = 0i64;
        if ( (BYTE4(v15[37].mNext) & 7) != 0 )
          v16 = (UFG::PhysicsWheeledVehicle *)v14[40].mNext;
        if ( v16 && !UFG::PhysicsWheeledVehicle::IsWheelOnGround(v16, 1) )
          goto LABEL_25;
      }
      v17 = (int)mPrev[6].mNext;
      if ( (v17 & 1) != 0 )
        goto LABEL_25;
      v18 = v17 | 8;
    }
    LODWORD(mPrev[6].mNext) = v18;
    goto LABEL_25;
  }
  LOBYTE(this->mController) = UFG::BikeHumanDriverComponent::IsHoodBounce((UFG::BikeHumanDriverComponent *)((char *)this - 64));
LABEL_41:
  if ( HIDWORD(this->mCruiseControl) == 1 )
  {
    v34 = deltaTime + *(float *)&this->mCruiseControl;
    *(float *)&this->mCruiseControl = v34;
    v35 = UFG::OSuiteLeaderboardManager::Instance();
    LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                            v35,
                                            "StatGamesWheelieDistance");
    UFG::StatGameManager::UpdateScore(LeaderboardDataUsingLeaderboardName, v34, 0);
  }
  else if ( HIDWORD(this->mCruiseControl) == 2 )
  {
    v29 = (int)mPrev[6].mNext;
    if ( (v29 & 8) == 0 || (v29 & 0x100) != 0 )
    {
      v30 = deltaTime + *(float *)&this->mCruiseControl;
      *(float *)&this->mCruiseControl = v30;
      UFG::GameStatAction::Bike::WheelieDistance(v30);
      v31 = *(float *)&this->mCruiseControl;
      v32 = UFG::OSuiteLeaderboardManager::Instance();
      v33 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v32, "StatGamesWheelieDistance");
      UFG::StatGameManager::EndStatGame(v33, (int)(float)(v31 * 1000.0));
      this->mCruiseControl = 0i64;
    }
  }
}

// File Line: 216
// RVA: 0x67F040
bool __fastcall UFG::BikeHumanDriverComponent::IsHoodBounce(UFG::BikeHumanDriverComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *v4; // rax
  UFG::SimObjectCVBase *v5; // rcx
  __int16 v6; // dx
  UFG::SimObjectVehiclePropertiesComponent *v7; // rax
  UFG::TransformNodeComponent *mNext; // rdi
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm2_4

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( !m_pSimObject )
    return 0;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pSimObject->m_Components.p[15].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v4 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::HitReactionComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::HitReactionComponent::_TypeUID);
    m_pComponent = v4;
  }
  else
  {
    m_pComponent = m_pSimObject->m_Components.p[15].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v5 = *(UFG::SimObjectCVBase **)&m_pComponent[3].m_TypeUID;
  if ( !v5 )
    return 0;
  v6 = v5->m_Flags;
  if ( (v6 & 0x4000) != 0 || v6 < 0 )
    v7 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v5);
  else
    v7 = (UFG::SimObjectVehiclePropertiesComponent *)((v6 & 0x2000) != 0 || (v6 & 0x1000) != 0
                                                    ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v5,
                                                        UFG::SimObjectVehiclePropertiesComponent::_TypeUID)
                                                    : UFG::SimObject::GetComponentOfType(
                                                        v5,
                                                        UFG::SimObjectVehiclePropertiesComponent::_TypeUID));
  if ( !v7 || v7->m_eSimObjectVehicleType != eSIM_OBJ_VEHICLE_TYPE_CAR )
    return 0;
  mNext = *(UFG::TransformNodeComponent **)&m_pComponent[3].m_TypeUID;
  if ( mNext )
    mNext = (UFG::TransformNodeComponent *)mNext->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(mNext);
  UFG::TransformNodeComponent::UpdateWorldTransform(mNext);
  v9 = (float)(mNext->mWorldTransform.v0.z * 2.0) + mNext->mWorldTransform.v3.z;
  v10 = *(float *)&m_pComponent[6].vfptr
      - (float)((float)(mNext->mWorldTransform.v0.x * 2.0) + mNext->mWorldTransform.v3.x);
  v11 = *((float *)&m_pComponent[6].vfptr + 1)
      - (float)((float)(mNext->mWorldTransform.v0.y * 2.0) + mNext->mWorldTransform.v3.y);
  return (float)((float)((float)(v11 * v11) + (float)(v10 * v10))
               + (float)((float)(*(float *)&m_pComponent[6].m_SafePointerList.mNode.mPrev - v9)
                       * (float)(*(float *)&m_pComponent[6].m_SafePointerList.mNode.mPrev - v9))) <= 2.0;
}

// File Line: 249
// RVA: 0x69B910
void __fastcall UFG::BikeHumanDriverComponent::WheelieStart(UFG::BikeHumanDriverComponent *this)
{
  if ( this->mCanWheelie )
    this->mWheelieState = WheelieOn;
}

// File Line: 258
// RVA: 0x69B930
void __fastcall UFG::BikeHumanDriverComponent::WheelieStop(UFG::BikeHumanDriverComponent *this)
{
  if ( this->mWheelieState == WheelieOn )
    this->mWheelieState = WheelieRequestStop;
}

