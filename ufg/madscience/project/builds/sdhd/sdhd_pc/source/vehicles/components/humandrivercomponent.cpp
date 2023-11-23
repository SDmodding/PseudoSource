// File Line: 32
// RVA: 0x157B7D0
__int64 dynamic_initializer_for__UFG::HumanDriverComponent::s_HumanDriverComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::HumanDriverComponent::s_HumanDriverComponentList__);
}

// File Line: 33
// RVA: 0x67A3B0
UFG::ComponentIDDesc *__fastcall UFG::HumanDriverComponent::GetDesc(UFG::HumanDriverComponent *this)
{
  return &UFG::HumanDriverComponent::_TypeIDesc;
}

// File Line: 40
// RVA: 0x1582C40
__int64 UFG::_dynamic_initializer_for__gSymEnableMaxSpeedStatGame__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("EnableMaxSpeedStatGame", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&gSymEnableMaxSpeedStatGame, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSymEnableMaxSpeedStatGame__);
}

// File Line: 57
// RVA: 0x669860
void __fastcall UFG::HumanDriverComponent::HumanDriverComponent(UFG::HumanDriverComponent *this, unsigned int name_uid)
{
  UFG::CruiseControl *v3; // rsi
  UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *mPrev; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::CruiseControl *v6; // rax

  UFG::VehicleDriverInterface::VehicleDriverInterface(this, name_uid);
  this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mPrev = &this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>;
  this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mNext = &this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>;
  this->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HumanDriverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::VehicleDriverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::HumanDriverComponent::`vftable{for `UFG::UpdateInterface};
  UFG::SimpleTimer::SimpleTimer(&this->mHangTime);
  UFG::SimpleTimer::SimpleTimer(&this->mMaxSpeedTime);
  v3 = 0i64;
  this->mCruiseControl = 0i64;
  this->mController = 0i64;
  *(_QWORD *)&this->mJumpLocHeight = 0i64;
  this->mHighestJump = 0.0;
  this->mChaseTime = -1.0;
  *(_WORD *)&this->mAtMaxSpeed = 0;
  this->mSirenIsOn = 0;
  mPrev = UFG::HumanDriverComponent::s_HumanDriverComponentList.mNode.mPrev;
  UFG::HumanDriverComponent::s_HumanDriverComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>;
  this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mPrev = mPrev;
  this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mNext = (UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *)&UFG::HumanDriverComponent::s_HumanDriverComponentList;
  UFG::HumanDriverComponent::s_HumanDriverComponentList.mNode.mPrev = &this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>;
  UFG::SimComponent::AddType(this, UFG::HumanDriverComponent::_HumanDriverComponentTypeUID, "HumanDriverComponent");
  this->mController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
  v5 = UFG::qMalloc(0x18ui64, "mCruiseControl", 0i64);
  if ( v5 )
  {
    UFG::CruiseControl::CruiseControl((UFG::CruiseControl *)v5, 1.0, 1.0, 0.0);
    v3 = v6;
  }
  this->mCruiseControl = v3;
}

// File Line: 68
// RVA: 0x66CAC0
void __fastcall UFG::HumanDriverComponent::~HumanDriverComponent(UFG::HumanDriverComponent *this)
{
  UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *v2; // rdi
  UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *mPrev; // rcx
  UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *mNext; // rax
  UFG::CruiseControl *mCruiseControl; // rcx
  UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *v6; // rcx
  UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *v7; // rax

  this->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HumanDriverComponent::`vftable{for `UFG::SimComponent};
  this->UFG::VehicleDriverInterface::UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::HumanDriverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::HumanDriverComponent::s_HumanDriverComponentpCurrentIterator )
    UFG::HumanDriverComponent::s_HumanDriverComponentpCurrentIterator = (UFG::HumanDriverComponent *)&this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mPrev[-19];
  v2 = &this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>;
  mPrev = this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  mCruiseControl = this->mCruiseControl;
  if ( mCruiseControl )
    mCruiseControl->vfptr->__vecDelDtor(mCruiseControl, 1u);
  _((AMD_HD3D *)&this->mMaxSpeedTime);
  _((AMD_HD3D *)&this->mHangTime);
  v6 = v2->mPrev;
  v7 = v2->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::VehicleDriverInterface::~VehicleDriverInterface(this);
}

// File Line: 90
// RVA: 0x682BE0
void __fastcall UFG::HumanDriverComponent::OnAttach(UFG::HumanDriverComponent *this, UFG::SimObjectGame *object)
{
  UFG::SimObjectVehiclePropertiesComponent *v4; // rdi
  signed __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  unsigned int v8; // eax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  int v10; // eax
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimComponent *v12; // r15
  int v13; // r12d
  int v14; // xmm2_4
  int mPrev_high; // xmm3_4
  int vfptr; // xmm0_4
  int mNext_high; // xmm1_4
  int m_TypeUID; // xmm2_4
  int m_NameUID; // xmm3_4
  int v20; // xmm2_4
  int m_pSimObject_high; // xmm3_4
  int v22; // xmm0_4
  int mNext; // xmm2_4
  int v24; // xmm3_4
  int v25; // xmm0_4
  UFG::PhysicsVehicle *v26; // rcx
  float v27; // xmm1_4
  float v28; // xmm2_4
  UFG::qVector3 *v29; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v33; // rax
  UFG::SimObjectCVBase *v34; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::PhysicsWheeledVehicle *v36; // rcx
  UFG::SimObjectCVBase *v37; // rcx
  __int16 v38; // dx
  UFG::SimObjectVehiclePropertiesComponent *ComponentOfType; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  bool *v42; // rax
  UFG::qVector3 velocity; // [rsp+10h] [rbp-29h] BYREF
  UFG::qVector3 result; // [rsp+20h] [rbp-19h] BYREF
  int v45[20]; // [rsp+30h] [rbp-9h] BYREF
  UFG::qSymbol vars0; // [rsp+A0h] [rbp+67h] BYREF
  void *retaddr; // [rsp+A8h] [rbp+6Fh] BYREF

  UFG::VehicleDriverInterface::OnAttach(this, object);
  v4 = 0i64;
  if ( object )
  {
    m_Flags = object->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          goto LABEL_37;
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(object, UFG::PhysicsMoverInterface::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(object, UFG::PhysicsMoverInterface::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = object->m_Components.p[34].m_pComponent;
      }
      if ( m_pComponent )
      {
        vars0.mUID = -1;
        UFG::qSymbol::set_null(&vars0);
        if ( HIDWORD(m_pComponent[9].m_BoundComponentHandles.mNode.mPrev) == -1 )
          HIDWORD(m_pComponent[9].m_BoundComponentHandles.mNode.mPrev) = UFG::qStringHashUpper32(
                                                                           (const char *)m_pComponent[9].m_pSimObject,
                                                                           -1);
        v8 = UFG::qStringHashUpper32("_Body_P", HIDWORD(m_pComponent[9].m_BoundComponentHandles.mNode.mPrev));
        if ( UFG::BasePhysicsSystem::GetCollisionModel(UFG::BasePhysicsSystem::mInstance, v8) )
        {
          mPrev = m_pComponent[10].m_SafePointerList.mNode.mPrev;
          v10 = *(_DWORD *)(&m_pComponent[3].m_SimObjIndex + 1);
          LODWORD(retaddr) = v10;
          if ( !mPrev || v10 != LODWORD(m_pComponent[8].m_BoundComponentHandles.mNode.mPrev) )
          {
            LODWORD(m_pComponent[8].m_BoundComponentHandles.mNode.mPrev) = v10;
            if ( mPrev )
            {
              ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *, void **))mPrev->mPrev[1].mNext)(
                mPrev,
                &retaddr);
            }
            else
            {
              m_pSimObject = m_pComponent->m_pSimObject;
              if ( m_pSimObject )
                v12 = m_pSimObject->m_Components.p[2].m_pComponent;
              else
                v12 = 0i64;
              v13 = 1;
              if ( ((__int64)m_pComponent[14].vfptr & 8) != 0 )
                v13 = 4;
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
              v14 = (int)v12[2].m_SafePointerList.mNode.mPrev;
              mPrev_high = HIDWORD(v12[2].m_SafePointerList.mNode.mPrev);
              vfptr = (int)v12[2].vfptr;
              v45[1] = HIDWORD(v12[2].vfptr);
              v45[2] = v14;
              v45[0] = vfptr;
              v45[3] = mPrev_high;
              mNext_high = HIDWORD(v12[2].m_SafePointerList.mNode.mNext);
              m_TypeUID = v12[2].m_TypeUID;
              m_NameUID = v12[2].m_NameUID;
              v45[4] = (int)v12[2].m_SafePointerList.mNode.mNext;
              v45[5] = mNext_high;
              v45[6] = m_TypeUID;
              v45[7] = m_NameUID;
              v20 = (int)v12[2].m_pSimObject;
              m_pSimObject_high = HIDWORD(v12[2].m_pSimObject);
              v22 = *(_DWORD *)&v12[2].m_Flags;
              v45[9] = *(_DWORD *)(&v12[2].m_SimObjIndex + 1);
              v45[8] = v22;
              v45[10] = v20;
              v45[11] = m_pSimObject_high;
              mNext = (int)v12[2].m_BoundComponentHandles.mNode.mNext;
              v24 = HIDWORD(v12[2].m_BoundComponentHandles.mNode.mNext);
              v25 = (int)v12[2].m_BoundComponentHandles.mNode.mPrev;
              v45[13] = HIDWORD(v12[2].m_BoundComponentHandles.mNode.mPrev);
              v45[14] = mNext;
              v45[12] = v25;
              v45[15] = v24;
              UFG::PhysicsMoverInterface::SetOccupantTargetLocks((UFG::PhysicsMoverInterface *)m_pComponent, 0);
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
              v26 = (UFG::PhysicsVehicle *)m_pComponent[10].m_SafePointerList.mNode.mPrev;
              v27 = *((float *)&v12[4].vfptr + 1);
              v28 = *(float *)&v12[4].m_SafePointerList.mNode.mPrev;
              velocity.x = *(float *)&v12[4].vfptr;
              velocity.y = v27;
              velocity.z = v28;
              if ( v26 )
              {
                v29 = UFG::PhysicsVehicle::GetVelocity(v26, &result);
                y = v29->y;
                z = v29->z;
                velocity.x = v29->x;
                velocity.y = y;
                velocity.z = z;
              }
              v32 = m_pComponent[10].m_SafePointerList.mNode.mPrev;
              if ( v32 )
                ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *, __int64))v32->mPrev->mPrev)(
                  v32,
                  1i64);
              v33 = m_pComponent->vfptr;
              m_pComponent[10].m_SafePointerList.mNode.mPrev = 0i64;
              ((void (__fastcall *)(UFG::SimComponent *, int *, UFG::qVector3 *))v33[19].__vecDelDtor)(
                m_pComponent,
                v45,
                &velocity);
              LODWORD(m_pComponent[10].m_SafePointerList.mNode.mPrev[34].mPrev) = v13;
              UFG::PhysicsVehicle::SetVelocity(
                (UFG::PhysicsVehicle *)m_pComponent[10].m_SafePointerList.mNode.mPrev,
                &velocity);
              if ( ((__int64)m_pComponent[14].vfptr & 2) != 0 )
                ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *))m_pComponent[10].m_SafePointerList.mNode.mPrev->mPrev[3].mNext)(m_pComponent[10].m_SafePointerList.mNode.mPrev);
              UFG::PhysicsMoverInterface::SetOccupantTargetLocks((UFG::PhysicsMoverInterface *)m_pComponent, 1);
            }
          }
          v34 = (UFG::SimObjectCVBase *)m_pComponent->m_pSimObject;
          if ( v34 )
          {
            if ( UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v34) )
            {
              v35 = m_pComponent[10].m_SafePointerList.mNode.mPrev;
              if ( v35 )
              {
                v36 = 0i64;
                if ( (BYTE4(v35[37].mNext) & 7) != 0 )
                  v36 = (UFG::PhysicsWheeledVehicle *)m_pComponent[10].m_SafePointerList.mNode.mPrev;
                if ( v36 )
                  UFG::PhysicsWheeledVehicle::ClearSteeringDeadZone(v36);
              }
            }
          }
        }
      }
    }
  }
LABEL_37:
  v37 = (UFG::SimObjectCVBase *)this->m_pSimObject;
  if ( v37 )
  {
    v38 = v37->m_Flags;
    if ( (v38 & 0x4000) != 0 || v38 < 0 )
    {
      ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v37);
    }
    else if ( (v38 & 0x2000) != 0 || (v38 & 0x1000) != 0 )
    {
      ComponentOfType = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v37,
                                                                      UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
    }
    else
    {
      ComponentOfType = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                      v37,
                                                                      UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
    }
    v4 = ComponentOfType;
  }
  this->mVehicleType = v4->m_eSimObjectVehicleType;
  m_pSceneObj = object->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  v42 = PropertyUtils::Get<bool>(
          mpWritableProperties,
          (UFG::qArray<unsigned long,0> *)&gSymEnableMaxSpeedStatGame,
          DEPTH_RECURSE);
  if ( v42 )
    this->mEnableMaxSpeedStat = *v42;
  else
    this->mEnableMaxSpeedStat = 0;
}

// File Line: 108
// RVA: 0x691130
void __fastcall UFG::HumanDriverComponent::Update(UFG::HumanDriverComponent *this, float deltaTime)
{
  UFG::BikePhysicsMoverComponent *mPrev; // rbx
  UFG::PhysicsVehicle *mPhysicsVehicle; // rax
  UFG::PhysicsVehicle *v6; // r15
  float mForwardSpeed; // xmm8_4
  char v8; // r13
  float v9; // xmm6_4
  int v10; // edx
  _BOOL8 v11; // rbp
  bool overrideSpeed; // si
  UFG::InputActionData *v13; // rcx
  UFG::InputActionData *v14; // rax
  UFG::InputActionData *v15; // rax
  UFG::InputActionData **v16; // r12
  float mAxisPositionX; // xmm0_4
  UFG::InputActionData *v18; // rax
  int v19; // xmm0_4
  UFG::InputActionData *v20; // rcx
  int v21; // xmm1_4
  float v22; // xmm1_4
  UFG::GameStatTracker *v23; // rax
  UFG::InputActionData *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rcx
  UFG::InputActionData *v27; // rax
  bool v28; // zf
  float v29; // xmm1_4
  float mAxisPositionY; // xmm6_4
  UFG::InputActionData *v31; // rax
  UFG::InputActionData *v32; // rax
  UFG::InputActionData *v33; // rax
  UFG::TransformNodeComponent *m_ChaseSpawnTransform; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v35; // rdx
  float v36; // xmm0_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v38; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v39; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v40; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v41; // rsi
  hkgpIndexedMeshDefinitions::Edge *v42; // rdx
  char v43; // al
  UFG::InputActionData *v44; // rax
  UFG::InputActionData *v45; // rax
  UFG::InputActionData *v46; // rax
  UFG::InputActionData *v47; // rax
  UFG::VehicleEffectsComponent *v48; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v49; // rcx
  int v50; // eax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v51; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v52; // rax
  UFG::InputActionData *v53; // rax
  UFG::InputActionData *v54; // rax
  float z; // xmm6_4
  bool v56; // si
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v57; // rbx
  UFG::PhysicsVehicle *v58; // rcx
  __m128 y_low; // xmm0
  float x; // xmm1_4
  float v61; // xmm6_4
  float v62; // xmm2_4
  int v63; // eax
  float v64; // xmm6_4
  UFG::OSuiteLeaderboardManager *v65; // rax
  const char *v66; // rdx
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  float LinearVelocityMagnitudeKPH; // xmm0_4
  bool v69; // si
  float ElapsedSeconds; // xmm0_4
  UFG::OSuiteLeaderboardManager *v71; // rax
  UFG::OSuiteLeaderboardData *v72; // rax
  UFG::CopSystem *v73; // rax
  int v74; // eax
  float v75; // xmm0_4
  float v76; // xmm6_4
  UFG::OSuiteLeaderboardManager *v77; // rax
  UFG::OSuiteLeaderboardData *v78; // rax
  float mElapsedTime; // xmm6_4
  UFG::OSuiteLeaderboardManager *v80; // rax
  UFG::OSuiteLeaderboardData *v81; // rax
  float v82; // xmm6_4
  UFG::OSuiteLeaderboardManager *v83; // rax
  UFG::OSuiteLeaderboardData *v84; // rax
  UFG::qVector3 result; // [rsp+30h] [rbp-A8h] BYREF
  float v86; // [rsp+3Ch] [rbp-9Ch]
  int v87; // [rsp+40h] [rbp-98h] BYREF
  __int64 v88; // [rsp+44h] [rbp-94h]
  int v89; // [rsp+4Ch] [rbp-8Ch]
  UFG::LinearGraph<float> v90; // [rsp+50h] [rbp-88h] BYREF
  char v91; // [rsp+E0h] [rbp+8h]

  UFG::VehicleDriverInterface::Update(this, deltaTime);
  mPrev = (UFG::BikePhysicsMoverComponent *)this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev;
  mPhysicsVehicle = mPrev->mPhysicsVehicle;
  if ( mPhysicsVehicle )
  {
    v6 = 0i64;
    if ( (*((_BYTE *)mPhysicsVehicle + 604) & 7) != 0 )
      v6 = mPrev->mPhysicsVehicle;
  }
  else
  {
    v6 = 0i64;
  }
  mForwardSpeed = mPrev->mForwardSpeed;
  v8 = 0;
  v91 = 0;
  v9 = mForwardSpeed * 3.5999999;
  if ( this->mAudioComponent.UFG::VehicleDriverInterface::mPrev )
  {
    *(_QWORD *)&this->mBreakOnUpdate = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    *((_DWORD *)&mPrev->mInput + 4) |= 0x200u;
    v10 = *((_DWORD *)&mPrev->mInput + 4);
    v11 = LocalPlayer != (UFG::SimObjectCharacter *)this->mAudioComponent.UFG::VehicleDriverInterface::mPrev;
    overrideSpeed = 0;
    v13 = UFG::ActionDef_Brake.mDataPerController[v11];
    if ( v13
      && v13->mActionTrue
      && !BYTE4(this->m_ChaseSpawnTransform->UFG::VehicleDriverInterface::m_SafePointerList.mNode.UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mNext)
      || (v14 = UFG::ActionDef_BrakeButton.mDataPerController[v11]) != 0i64 && v14->mActionTrue )
    {
      overrideSpeed = 1;
      v15 = UFG::ActionDef_Accelerate.mDataPerController[v11];
      v16 = &UFG::ActionDef_Accelerate.mDataPerController[v11];
      if ( v15 && v15->mActionTrue )
      {
        mPrev->mInput.mGasBrakes = 1.0;
        mPrev->mInput.mRawGasBrakes = 1.0;
        *((_DWORD *)&mPrev->mInput + 4) = v10 | 4;
        v8 = 1;
      }
      else if ( *(float *)&this->mAudioComponent.m_TypeUID > 0.0 )
      {
        mPrev->mInput.mGasBrakes = 1.0;
        mPrev->mInput.mRawGasBrakes = 1.0;
        v8 = 1;
      }
      else
      {
        if ( v13 )
          mAxisPositionX = v13->mAxisPositionX;
        else
          mAxisPositionX = 0.0;
        v18 = UFG::ActionDef_BrakeButton.mDataPerController[v11];
        if ( v18 && v18->mActionTrue )
          mAxisPositionX = *(float *)&FLOAT_1_0;
        v19 = LODWORD(mAxisPositionX) ^ _xmm[0];
        v91 = 1;
        *((_DWORD *)&mPrev->mInput + 4) = v10 | 1;
        LODWORD(mPrev->mInput.mGasBrakes) = v19;
        LODWORD(mPrev->mInput.mRawGasBrakes) = v19;
      }
    }
    else
    {
      v20 = UFG::ActionDef_Accelerate.mDataPerController[v11];
      v16 = &UFG::ActionDef_Accelerate.mDataPerController[v11];
      if ( v20
        && v20->mActionTrue
        && !BYTE4(this->m_ChaseSpawnTransform->UFG::VehicleDriverInterface::m_SafePointerList.mNode.UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mNext) )
      {
        v21 = LODWORD(v20->mAxisPositionX) ^ _xmm[0];
        LODWORD(mPrev->mInput.mGasBrakes) = v21;
        LODWORD(mPrev->mInput.mRawGasBrakes) = v21;
        if ( LODWORD(this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev[51].mNext)
          && v6
          && v9 < (float)(v6->mReverseSpeedGovernor * -0.25) )
        {
          LODWORD(v22) = v21 & _xmm;
          v8 = 1;
          mPrev->mInput.mGasBrakes = v22;
          mPrev->mInput.mRawGasBrakes = v22;
        }
        v23 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStatHigh(v23, 98, v9);
      }
      else
      {
        v24 = UFG::ActionDef_AccelerateButton.mDataPerController[v11];
        if ( v24 && v24->mActionTrue )
        {
          mPrev->mInput.mGasBrakes = -1.0;
          mPrev->mInput.mRawGasBrakes = -1.0;
          if ( LODWORD(this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev[51].mNext)
            && v6
            && v9 < (float)(v6->mReverseSpeedGovernor * -0.25) )
          {
            v8 = 1;
            LODWORD(mPrev->mInput.mGasBrakes) = LODWORD(FLOAT_N1_0) & _xmm;
            LODWORD(mPrev->mInput.mRawGasBrakes) = LODWORD(FLOAT_N1_0) & _xmm;
          }
          overrideSpeed = 1;
        }
      }
    }
    v25 = this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev;
    if ( v25 )
    {
      v26 = v25[41].mPrev;
      if ( v26 && LODWORD(v26[1].mNext) == 2 )
      {
        if ( mPrev->mInput.mGasBrakes < 0.0 )
          *(_QWORD *)&mPrev->mInput.mGasBrakes = 0i64;
      }
      else
      {
        mPrev->mInput.mGasBrakes = UFG::CruiseControl::Update(
                                     (UFG::CruiseControl *)this->m_ChaseSpawnTransform,
                                     deltaTime,
                                     mForwardSpeed,
                                     mPrev->mInput.mGasBrakes,
                                     overrideSpeed);
      }
    }
    v27 = UFG::ActionDef_Steer.mDataPerController[v11];
    if ( v27 && v27->mActionTrue )
    {
      v28 = *((_BYTE *)&mPrev->mInput + 16) >= 0;
      v29 = v27->mAxisPositionX;
      mAxisPositionY = v27->mAxisPositionY;
      v87 = -1082130432;
      v88 = 0i64;
      v90.fDomain = (const float *)&result;
      v89 = 1065353216;
      result.x = FLOAT_N0_89999998;
      result.y = FLOAT_N0_2;
      v90.nData = 4;
      v90.tRange = (const float *)&v87;
      result.z = FLOAT_0_2;
      v86 = FLOAT_0_89999998;
      if ( v28 )
        mPrev->mInput.mSteering = UFG::LinearGraph<float>::GetValue(&v90, v29);
      LODWORD(mPrev->mInput.mForwardWeightShift) = COERCE_UNSIGNED_INT(UFG::LinearGraph<float>::GetValue(&v90, mAxisPositionY)) ^ _xmm[0];
    }
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      mPrev->mInput.mForwardWeightShift = 0.0;
      v31 = UFG::ActionDef_LeanForward.mDataPerController[v11];
      if ( v31 && v31->mActionTrue )
        mPrev->mInput.mForwardWeightShift = 1.0;
      v32 = UFG::ActionDef_LeanBack.mDataPerController[v11];
      if ( v32 && v32->mActionTrue )
        mPrev->mInput.mForwardWeightShift = mPrev->mInput.mForwardWeightShift - 1.0;
    }
    v33 = UFG::ActionDef_HandBrake.mDataPerController[v11];
    if ( v33 && v33->mActionTrue )
      *((_DWORD *)&mPrev->mInput + 4) |= 4u;
    if ( UFG::HumanDriverComponent::gShouldResetVehicle
      && this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev )
    {
      UFG::HumanDriverComponent::gShouldResetVehicle = 0;
      m_ChaseSpawnTransform = this->m_ChaseSpawnTransform;
      BYTE4(m_ChaseSpawnTransform->m_SafePointerList.mNode.mNext) = 0;
      UFG::qPidControllerCore::Clear((UFG::qPidControllerCore *)m_ChaseSpawnTransform->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev);
      ((void (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, _QWORD))this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev->UFG::VehicleDriverInterface::UFG::SimComponent::mPrev[7].mPrev)(
        this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev,
        0i64);
      HIDWORD(this->mAudioComponent.mNext) = 2;
    }
    v35 = this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev;
    v36 = FLOAT_5_0;
    mNext = v35[40].mNext;
    if ( mNext )
    {
      v38 = 0i64;
      if ( (BYTE4(mNext[37].mNext) & 7) != 0 )
        v38 = v35[40].mNext;
      if ( v38 )
      {
        mNext = v38[38].mNext;
        if ( mNext )
        {
          if ( mNext[3].mNext )
          {
            v39 = v35[40].mNext;
            v40 = 0i64;
            if ( v39 && (BYTE4(v39[37].mNext) & 7) != 0 )
              v40 = v35[40].mNext;
            mNext = v40[38].mNext[3].mNext;
            v36 = *(float *)&mNext[7].mPrev;
          }
        }
      }
    }
    if ( mForwardSpeed > v36 )
      this->mAudioComponent.m_TypeUID = HIDWORD(this->mHangTime.mTimestamp);
    else
      *(float *)&this->mAudioComponent.m_TypeUID = *(float *)&this->mAudioComponent.m_TypeUID - deltaTime;
    v41 = this->mRenderComponent.mNext;
    if ( v41 )
    {
      if ( *v16 && (*v16)->mActionTrue )
      {
        if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
                (hkgpIndexedMesh::EdgeBarrier *)mNext,
                (hkgpIndexedMeshDefinitions::Edge *)v35) )
        {
          v43 = BYTE4(v41[39].mNext);
          if ( (v43 & 2) == 0 )
            BYTE4(v41[39].mNext) = v43 | 2;
        }
        UFG::VehicleAudioComponent::TurnOnRadio((UFG::VehicleAudioComponent *)this->mRenderComponent.mNext, v42);
      }
      v44 = UFG::ActionDef_HornStart.mDataPerController[v11];
      if ( v44 && v44->mActionTrue
        || (v45 = UFG::ActionDef_HornStart_Alt.mDataPerController[v11]) != 0i64 && v45->mActionTrue )
      {
        UFG::VehicleAudioComponent::OnActionDefStartHorn((UFG::VehicleAudioComponent *)this->mRenderComponent.mNext);
      }
      else
      {
        v46 = UFG::ActionDef_HornStop.mDataPerController[v11];
        if ( v46 && v46->mActionTrue
          || (v47 = UFG::ActionDef_HornStop_Alt.mDataPerController[v11]) != 0i64 && v47->mActionTrue )
        {
          UFG::VehicleAudioComponent::OnActionDefStopHorn((UFG::VehicleAudioComponent *)this->mRenderComponent.mNext);
        }
        else
        {
          v48 = (UFG::VehicleEffectsComponent *)this->mRenderComponent.mNext;
          *((_BYTE *)&v48->mEffectStatusTable[18] + 22) &= ~2u;
          *((_BYTE *)&v48->mEffectStatusTable[18] + 22) |= 4u;
        }
      }
    }
    v49 = this->mMoverComponent.mNext;
    if ( !v49 )
      goto LABEL_117;
    if ( v8
      || ((v50 = (int)this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mPrev, v50 == 1) || v50 == 6)
      && (*((_BYTE *)&mPrev->mInput + 16) & 4) != 0 )
    {
      UFG::VehicleEffectsComponent::TurnOnLightEffects((UFG::VehicleEffectsComponent *)v49, FX_BRAKELIGHTS);
    }
    else
    {
      UFG::VehicleEffectsComponent::TurnOffLightEffects((UFG::VehicleEffectsComponent *)v49, FX_BRAKELIGHTS);
    }
    v51 = this->mMoverComponent.mNext;
    if ( v91 )
      UFG::VehicleEffectsComponent::TurnOnLightEffects((UFG::VehicleEffectsComponent *)v51, FX_REVERSE);
    else
      UFG::VehicleEffectsComponent::TurnOffLightEffects((UFG::VehicleEffectsComponent *)v51, FX_REVERSE);
    v52 = this->mRenderComponent.mNext;
    if ( v52 )
    {
      if ( (BYTE6(v52[39].mNext) & 8) != 0 && !*(&this->mHangTime.mIsStarted + 2) )
      {
        *(&this->mHangTime.mIsStarted + 2) = 1;
        UFG::VehicleEffectsComponent::TurnOnCopLights((UFG::VehicleEffectsComponent *)this->mMoverComponent.mNext);
      }
      if ( (BYTE6(this->mRenderComponent.mNext[39].mNext) & 8) != 0 || !*(&this->mHangTime.mIsStarted + 2) )
        goto LABEL_117;
      *(&this->mHangTime.mIsStarted + 2) = 0;
    }
    else
    {
      v53 = UFG::ActionDef_HornStart.mDataPerController[v11];
      if ( v53 && v53->mActionTrue )
        UFG::VehicleEffectsComponent::TurnOnCopLights((UFG::VehicleEffectsComponent *)this->mMoverComponent.mNext);
      v54 = UFG::ActionDef_HornStop.mDataPerController[v11];
      if ( !v54 || !v54->mActionTrue )
        goto LABEL_117;
    }
    UFG::VehicleEffectsComponent::TurnOffCopLights((UFG::VehicleEffectsComponent *)this->mMoverComponent.mNext);
LABEL_117:
    if ( v6 )
    {
      z = v6->mBodyTransform.v3.z;
      v56 = ((unsigned __int8 (__fastcall *)(UFG::PhysicsVehicle *))v6->vfptr[4].DebugDraw)(v6)
         && *((float *)&this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev[43].mPrev
            + 1) > 0.0;
      if ( *(&this->mHangTime.mIsStarted + 1) )
        goto LABEL_126;
      if ( v56 )
      {
        *((float *)&this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mPrev + 1) = z;
        this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mNext = 0i64;
        UFG::SimpleTimer::SetElapsedTime((UFG::SimpleTimer *)&this->mState, 0.0);
        UFG::SimpleTimer::Start((UFG::SimpleTimer *)&this->mState);
      }
      if ( *(&this->mHangTime.mIsStarted + 1) )
      {
LABEL_126:
        if ( !v56 )
          UFG::HumanDriverComponent::StatGameStopInAir((UFG::HumanDriverComponent *)((char *)this - 64));
      }
      *(&this->mHangTime.mIsStarted + 1) = v56;
      if ( v56 )
      {
        v57 = this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev;
        v58 = (UFG::PhysicsVehicle *)v57[40].mNext;
        if ( !v58 || UFG::PhysicsVehicle::IsSuspended(v58) )
        {
          x = UFG::qVector3::msZero.x;
          y_low = (__m128)LODWORD(UFG::qVector3::msZero.y);
          result.x = UFG::qVector3::msZero.x;
          result.y = UFG::qVector3::msZero.y;
        }
        else
        {
          UFG::PhysicsVehicle::GetVelocity((UFG::PhysicsVehicle *)v57[40].mNext, &result);
          y_low = (__m128)LODWORD(result.y);
          x = result.x;
        }
        v61 = z - *((float *)&this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mPrev + 1);
        v62 = *((float *)&this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mNext + 1);
        result.z = 0.0;
        if ( v61 <= v62 )
          v61 = v62;
        v63 = (int)this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mPrev;
        *((float *)&this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mNext + 1) = v61;
        y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x);
        v64 = (float)(_mm_sqrt_ps(y_low).m128_f32[0] * deltaTime)
            + *(float *)&this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mNext;
        *(float *)&this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mNext = v64;
        switch ( v63 )
        {
          case 1:
          case 6:
            v65 = UFG::OSuiteLeaderboardManager::Instance();
            v66 = "StatGamesBikeJump";
            goto LABEL_138;
          case 2:
          case 4:
          case 5:
            v65 = UFG::OSuiteLeaderboardManager::Instance();
            v66 = "StatGamesCarJump";
LABEL_138:
            LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                                    v65,
                                                    v66);
            UFG::StatGameManager::UpdateScore(LeaderboardDataUsingLeaderboardName, v64, 0);
            break;
          case 3:
            break;
          default:
            return;
        }
      }
    }
    if ( *(&this->mHangTime.mIsStarted + 3) )
    {
      LinearVelocityMagnitudeKPH = UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH((UFG::PhysicsMoverInterface *)this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev);
      v69 = LinearVelocityMagnitudeKPH > UFG::sTheoraticalMaxSpeed;
      if ( LinearVelocityMagnitudeKPH > UFG::sTheoraticalMaxSpeed && !this->mHangTime.mIsStarted )
      {
        UFG::SimpleTimer::SetElapsedTime((UFG::SimpleTimer *)&this->mPropertySet, 0.0);
        UFG::SimpleTimer::Start((UFG::SimpleTimer *)&this->mPropertySet);
      }
      ElapsedSeconds = UFG::SimpleTimer::GetElapsedSeconds((UFG::SimpleTimer *)&this->mPropertySet);
      if ( this->mHangTime.mIsStarted && !v69 )
        UFG::HumanDriverComponent::StatGameStopMaxSpeed((UFG::HumanDriverComponent *)((char *)this - 64));
      this->mHangTime.mIsStarted = v69;
      if ( v69 && LODWORD(this->UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent>::mPrev) == 1 )
      {
        v71 = UFG::OSuiteLeaderboardManager::Instance();
        v72 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v71, "StatGamesLongestCarMaxSpeed");
        UFG::StatGameManager::UpdateScore(v72, ElapsedSeconds, 0);
      }
    }
    v73 = UFG::CopSystem::Instance();
    v74 = ((__int64 (__fastcall *)(UFG::CopSystem *))v73->vfptr[89].__vecDelDtor)(v73);
    if ( (float)(*((float *)&this->m_BoundComponentHandles.mNode.UFG::VehicleDriverInterface::UFG::SimComponent::mPrev[43].mPrev
                 + 1)
               * 3.5999999) <= UFG::gChaseMinimumDrivingSpeed
      || v74 < 1 )
    {
      mElapsedTime = this->mHangTime.mElapsedTime;
      if ( mElapsedTime > 0.0 )
      {
        v80 = UFG::OSuiteLeaderboardManager::Instance();
        v81 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v80, "StatGamesLongestChase");
        UFG::StatGameManager::EndStatGame(v81, (int)(float)(mElapsedTime * 1000.0));
        this->mHangTime.mElapsedTime = -1.0;
      }
    }
    else
    {
      v75 = this->mHangTime.mElapsedTime;
      if ( v75 >= 0.0 )
      {
        v76 = (float)(UFG::Metrics::msInstance.mSimTimeScaleInGame * deltaTime) + v75;
        this->mHangTime.mElapsedTime = v76;
        v77 = UFG::OSuiteLeaderboardManager::Instance();
        v78 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v77, "StatGamesLongestChase");
        UFG::StatGameManager::UpdateScore(v78, v76, 0);
      }
      else
      {
        this->mHangTime.mElapsedTime = 0.0;
      }
    }
    return;
  }
  v82 = this->mHangTime.mElapsedTime;
  this->mAudioComponent.m_TypeUID = 0;
  if ( v82 > 0.0 )
  {
    v83 = UFG::OSuiteLeaderboardManager::Instance();
    v84 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v83, "StatGamesLongestChase");
    UFG::StatGameManager::EndStatGame(v84, (int)(float)(v82 * 1000.0));
    this->mHangTime.mElapsedTime = -1.0;
  }
  if ( *(&this->mHangTime.mIsStarted + 1) )
  {
    UFG::HumanDriverComponent::StatGameStopMaxSpeed((UFG::HumanDriverComponent *)((char *)this - 64));
    *(&this->mHangTime.mIsStarted + 1) = 0;
  }
  if ( this->mHangTime.mIsStarted )
  {
    UFG::HumanDriverComponent::StatGameStopMaxSpeed((UFG::HumanDriverComponent *)((char *)this - 64));
    this->mHangTime.mIsStarted = 0;
  }
}

// File Line: 552
// RVA: 0x689A40
void UFG::HumanDriverComponent::ResetVehicle(void)
{
  UFG::HumanDriverComponent::gShouldResetVehicle = 1;
}

// File Line: 557
// RVA: 0x68C540
void __fastcall UFG::HumanDriverComponent::StatGameStopInAir(UFG::HumanDriverComponent *this)
{
  float ElapsedSeconds; // xmm6_4
  UFG::GameStatTracker *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  ElapsedSeconds = UFG::SimpleTimer::GetElapsedSeconds(&this->mHangTime);
  UFG::SimpleTimer::Stop(&this->mHangTime);
  v3 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStatHigh(v3, 87, ElapsedSeconds);
  UFG::GameStatAction::Vehicle::SetLongestJump((UFG::SimObjectCVBase *)this->m_pSimObject, this->mJumpDistance);
  mPrev = this->mMoverComponent.m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
  if ( mPrev )
  {
    v5 = 0i64;
    if ( (BYTE4(mPrev[37].mNext) & 7) != 0 )
      v5 = this->mMoverComponent.m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
    if ( v5 )
      UFG::GameStatAction::Vehicle::SetHighestJump(HIDWORD(v5[37].mNext) & 7, this->mHighestJump);
  }
}

// File Line: 569
// RVA: 0x68C5E0
void __fastcall UFG::HumanDriverComponent::StatGameStopMaxSpeed(UFG::HumanDriverComponent *this)
{
  float ElapsedSeconds; // xmm6_4
  UFG::OSuiteLeaderboardManager *v3; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::OSuiteLeaderboardManager *v5; // rax
  UFG::OSuiteLeaderboardData *v6; // rax

  ElapsedSeconds = UFG::SimpleTimer::GetElapsedSeconds(&this->mMaxSpeedTime);
  UFG::SimpleTimer::Stop(&this->mMaxSpeedTime);
  if ( this->mVehicleType == 2 )
  {
    v3 = UFG::OSuiteLeaderboardManager::Instance();
    LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                            v3,
                                            "StatAwardsRecklessDriver");
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, ElapsedSeconds);
  }
  if ( this->mVehicleType == 1 )
  {
    v5 = UFG::OSuiteLeaderboardManager::Instance();
    v6 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v5, "StatGamesLongestCarMaxSpeed");
    UFG::StatGameManager::EndStatGame(v6, (int)(float)(ElapsedSeconds * 1000.0));
  }
}

