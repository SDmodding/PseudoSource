// File Line: 32
// RVA: 0x157B7D0
__int64 dynamic_initializer_for__UFG::HumanDriverComponent::s_HumanDriverComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::HumanDriverComponent::s_HumanDriverComponentList__);
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
  return atexit(UFG::_dynamic_atexit_destructor_for__gSymEnableMaxSpeedStatGame__);
}

// File Line: 57
// RVA: 0x669860
void __fastcall UFG::HumanDriverComponent::HumanDriverComponent(UFG::HumanDriverComponent *this, unsigned int name_uid)
{
  UFG::HumanDriverComponent *v2; // rdi
  UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *v3; // rbx
  UFG::CruiseControl *v4; // rsi
  UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *v5; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::CruiseControl *v7; // rax

  v2 = this;
  UFG::VehicleDriverInterface::VehicleDriverInterface((UFG::VehicleDriverInterface *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HumanDriverComponent::`vftable{for `UFG::SimComponent};
  v2->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::HumanDriverComponent::`vftable{for `UFG::UpdateInterface};
  UFG::SimpleTimer::SimpleTimer(&v2->mHangTime);
  UFG::SimpleTimer::SimpleTimer(&v2->mMaxSpeedTime);
  v4 = 0i64;
  v2->mCruiseControl = 0i64;
  v2->mController = 0i64;
  *(_QWORD *)&v2->mJumpLocHeight = 0i64;
  v2->mHighestJump = 0.0;
  v2->mChaseTime = -1.0;
  *(_WORD *)&v2->mAtMaxSpeed = 0;
  v2->mSirenIsOn = 0;
  v5 = UFG::HumanDriverComponent::s_HumanDriverComponentList.mNode.mPrev;
  UFG::HumanDriverComponent::s_HumanDriverComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *)&v2->mPrev;
  v3->mPrev = v5;
  v2->mNext = (UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *)&UFG::HumanDriverComponent::s_HumanDriverComponentList;
  UFG::HumanDriverComponent::s_HumanDriverComponentList.mNode.mPrev = (UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::HumanDriverComponent::_HumanDriverComponentTypeUID,
    "HumanDriverComponent");
  v2->mController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
  v6 = UFG::qMalloc(0x18ui64, "mCruiseControl", 0i64);
  if ( v6 )
  {
    UFG::CruiseControl::CruiseControl((UFG::CruiseControl *)v6, 1.0, 1.0, 0.0);
    v4 = v7;
  }
  v2->mCruiseControl = v4;
}

// File Line: 68
// RVA: 0x66CAC0
void __fastcall UFG::HumanDriverComponent::~HumanDriverComponent(UFG::HumanDriverComponent *this)
{
  UFG::HumanDriverComponent *v1; // rbx
  UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *v2; // rdi
  UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *v3; // rcx
  UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *v4; // rax
  UFG::CruiseControl *v5; // rcx
  UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *v6; // rcx
  UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *v7; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::HumanDriverComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::HumanDriverComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::HumanDriverComponent::s_HumanDriverComponentpCurrentIterator )
    UFG::HumanDriverComponent::s_HumanDriverComponentpCurrentIterator = (UFG::HumanDriverComponent *)&this->mPrev[-19];
  v2 = (UFG::qNode<UFG::HumanDriverComponent,UFG::HumanDriverComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v1->mCruiseControl;
  if ( v5 )
    v5->vfptr->__vecDelDtor(v5, 1u);
  _((AMD_HD3D *)&v1->mMaxSpeedTime);
  _((AMD_HD3D *)&v1->mHangTime);
  v6 = v2->mPrev;
  v7 = v2->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::VehicleDriverInterface::~VehicleDriverInterface((UFG::VehicleDriverInterface *)&v1->vfptr);
}

// File Line: 90
// RVA: 0x682BE0
void __fastcall UFG::HumanDriverComponent::OnAttach(UFG::HumanDriverComponent *this, UFG::SimObject *object)
{
  UFG::HumanDriverComponent *v2; // r14
  UFG::SimObjectGame *v3; // rsi
  UFG::SimObjectVehiclePropertiesComponent *v4; // rdi
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rbx
  UFG::SimComponent *v7; // rax
  unsigned int v8; // eax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  int v10; // eax
  UFG::SimObject *v11; // rax
  UFG::SimComponent *v12; // r15
  signed int v13; // er12
  int v14; // xmm2_4
  int v15; // xmm3_4
  int v16; // xmm0_4
  int v17; // xmm1_4
  int v18; // xmm2_4
  int v19; // xmm3_4
  int v20; // xmm2_4
  int v21; // xmm3_4
  int v22; // xmm0_4
  int v23; // xmm2_4
  int v24; // xmm3_4
  int v25; // xmm0_4
  UFG::PhysicsVehicle *v26; // rcx
  float v27; // xmm1_4
  float v28; // xmm2_4
  UFG::qVector3 *v29; // rax
  float v30; // xmm1_4
  float v31; // xmm2_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v33; // rax
  UFG::SimObjectCVBase *v34; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::PhysicsWheeledVehicle *v36; // rcx
  UFG::SimObjectCVBase *v37; // rcx
  unsigned __int16 v38; // dx
  UFG::SimObjectVehiclePropertiesComponent *v39; // rax
  UFG::SceneObjectProperties *v40; // rax
  UFG::qPropertySet *v41; // rcx
  bool *v42; // rax
  UFG::qVector3 velocity; // [rsp+10h] [rbp-29h]
  UFG::qVector3 result; // [rsp+20h] [rbp-19h]
  int v45; // [rsp+30h] [rbp-9h]
  int v46; // [rsp+34h] [rbp-5h]
  int v47; // [rsp+38h] [rbp-1h]
  int v48; // [rsp+3Ch] [rbp+3h]
  int v49; // [rsp+40h] [rbp+7h]
  int v50; // [rsp+44h] [rbp+Bh]
  int v51; // [rsp+48h] [rbp+Fh]
  int v52; // [rsp+4Ch] [rbp+13h]
  int v53; // [rsp+50h] [rbp+17h]
  int v54; // [rsp+54h] [rbp+1Bh]
  int v55; // [rsp+58h] [rbp+1Fh]
  int v56; // [rsp+5Ch] [rbp+23h]
  int v57; // [rsp+60h] [rbp+27h]
  int v58; // [rsp+64h] [rbp+2Bh]
  int v59; // [rsp+68h] [rbp+2Fh]
  int v60; // [rsp+6Ch] [rbp+33h]
  UFG::qSymbol vars0; // [rsp+A0h] [rbp+67h]
  int retaddr; // [rsp+A8h] [rbp+6Fh]

  v2 = this;
  v3 = (UFG::SimObjectGame *)object;
  UFG::VehicleDriverInterface::OnAttach((UFG::VehicleDriverInterface *)&this->vfptr, object);
  v4 = 0i64;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( !((v5 >> 14) & 1) )
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
          goto LABEL_37;
        if ( (v5 >> 12) & 1 )
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v6 = v7;
      }
      else
      {
        v6 = v3->m_Components.p[34].m_pComponent;
      }
      if ( v6 )
      {
        vars0.mUID = -1;
        UFG::qSymbol::set_null(&vars0);
        if ( HIDWORD(v6[9].m_BoundComponentHandles.mNode.mPrev) == -1 )
          HIDWORD(v6[9].m_BoundComponentHandles.mNode.mPrev) = UFG::qStringHashUpper32(
                                                                 (const char *)v6[9].m_pSimObject,
                                                                 0xFFFFFFFF);
        v8 = UFG::qStringHashUpper32("_Body_P", HIDWORD(v6[9].m_BoundComponentHandles.mNode.mPrev));
        if ( UFG::BasePhysicsSystem::GetCollisionModel(UFG::BasePhysicsSystem::mInstance, v8) )
        {
          v9 = v6[10].m_SafePointerList.mNode.mPrev;
          v10 = *(_DWORD *)(&v6[3].m_SimObjIndex + 1);
          retaddr = *(_DWORD *)(&v6[3].m_SimObjIndex + 1);
          if ( !v9 || v10 != LODWORD(v6[8].m_BoundComponentHandles.mNode.mPrev) )
          {
            LODWORD(v6[8].m_BoundComponentHandles.mNode.mPrev) = v10;
            if ( v9 )
            {
              ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *, int *))v9->mPrev[1].mNext)(
                v9,
                &retaddr);
            }
            else
            {
              v11 = v6->m_pSimObject;
              if ( v11 )
                v12 = v11->m_Components.p[2].m_pComponent;
              else
                v12 = 0i64;
              v13 = 1;
              if ( (_QWORD)v6[14].vfptr & 8 )
                v13 = 4;
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
              v14 = (int)v12[2].m_SafePointerList.mNode.mPrev;
              v15 = HIDWORD(v12[2].m_SafePointerList.mNode.mPrev);
              v16 = (int)v12[2].vfptr;
              v46 = HIDWORD(v12[2].vfptr);
              v47 = v14;
              v45 = v16;
              v48 = v15;
              v17 = HIDWORD(v12[2].m_SafePointerList.mNode.mNext);
              v18 = v12[2].m_TypeUID;
              v19 = v12[2].m_NameUID;
              v49 = (int)v12[2].m_SafePointerList.mNode.mNext;
              v50 = v17;
              v51 = v18;
              v52 = v19;
              v20 = (int)v12[2].m_pSimObject;
              v21 = HIDWORD(v12[2].m_pSimObject);
              v22 = *(_DWORD *)&v12[2].m_Flags;
              v54 = *(_DWORD *)(&v12[2].m_SimObjIndex + 1);
              v53 = v22;
              v55 = v20;
              v56 = v21;
              v23 = (int)v12[2].m_BoundComponentHandles.mNode.mNext;
              v24 = HIDWORD(v12[2].m_BoundComponentHandles.mNode.mNext);
              v25 = (int)v12[2].m_BoundComponentHandles.mNode.mPrev;
              v58 = HIDWORD(v12[2].m_BoundComponentHandles.mNode.mPrev);
              v59 = v23;
              v57 = v25;
              v60 = v24;
              UFG::PhysicsMoverInterface::SetOccupantTargetLocks((UFG::PhysicsMoverInterface *)v6, 0);
              UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
              v26 = (UFG::PhysicsVehicle *)v6[10].m_SafePointerList.mNode.mPrev;
              v27 = *((float *)&v12[4].vfptr + 1);
              v28 = *(float *)&v12[4].m_SafePointerList.mNode.mPrev;
              velocity.x = *(float *)&v12[4].vfptr;
              velocity.y = v27;
              velocity.z = v28;
              if ( v26 )
              {
                v29 = UFG::PhysicsVehicle::GetVelocity(v26, &result);
                v30 = v29->y;
                v31 = v29->z;
                velocity.x = v29->x;
                velocity.y = v30;
                velocity.z = v31;
              }
              v32 = v6[10].m_SafePointerList.mNode.mPrev;
              if ( v32 )
                ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *, signed __int64))v32->mPrev->mPrev)(
                  v32,
                  1i64);
              v33 = v6->vfptr;
              v6[10].m_SafePointerList.mNode.mPrev = 0i64;
              ((void (__fastcall *)(UFG::SimComponent *, int *, UFG::qVector3 *))v33[19].__vecDelDtor)(
                v6,
                &v45,
                &velocity);
              LODWORD(v6[10].m_SafePointerList.mNode.mPrev[34].mPrev) = v13;
              UFG::PhysicsVehicle::SetVelocity((UFG::PhysicsVehicle *)v6[10].m_SafePointerList.mNode.mPrev, &velocity);
              if ( (_QWORD)v6[14].vfptr & 2 )
                ((void (*)(void))v6[10].m_SafePointerList.mNode.mPrev->mPrev[3].mNext)();
              UFG::PhysicsMoverInterface::SetOccupantTargetLocks((UFG::PhysicsMoverInterface *)v6, 1);
            }
          }
          v34 = (UFG::SimObjectCVBase *)v6->m_pSimObject;
          if ( v34 )
          {
            if ( UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v34) )
            {
              v35 = v6[10].m_SafePointerList.mNode.mPrev;
              if ( v35 )
              {
                v36 = 0i64;
                if ( BYTE4(v35[37].mNext) & 7 )
                  v36 = (UFG::PhysicsWheeledVehicle *)v6[10].m_SafePointerList.mNode.mPrev;
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
  v37 = (UFG::SimObjectCVBase *)v2->m_pSimObject;
  if ( v37 )
  {
    v38 = v37->m_Flags;
    if ( (v38 >> 14) & 1 )
    {
      v39 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v37);
    }
    else if ( (v38 & 0x8000u) == 0 )
    {
      if ( (v38 >> 13) & 1 )
      {
        v39 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v37->vfptr,
                                                            UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
      }
      else if ( (v38 >> 12) & 1 )
      {
        v39 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v37->vfptr,
                                                            UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
      }
      else
      {
        v39 = (UFG::SimObjectVehiclePropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                            (UFG::SimObject *)&v37->vfptr,
                                                            UFG::SimObjectVehiclePropertiesComponent::_TypeUID);
      }
    }
    else
    {
      v39 = UFG::SimObjectCVBase::GetComponent<UFG::SimObjectVehiclePropertiesComponent>(v37);
    }
    v4 = v39;
  }
  v2->mVehicleType = v4->m_eSimObjectVehicleType;
  v40 = v3->m_pSceneObj;
  v41 = v40->mpWritableProperties;
  if ( !v41 )
    v41 = v40->mpConstProperties;
  v42 = PropertyUtils::Get<bool>(v41, (UFG::qSymbol *)&gSymEnableMaxSpeedStatGame.mUID, DEPTH_RECURSE);
  if ( v42 )
    v2->mEnableMaxSpeedStat = *v42;
  else
    v2->mEnableMaxSpeedStat = 0;
}

// File Line: 108
// RVA: 0x691130
void __fastcall UFG::HumanDriverComponent::Update(UFG::HumanDriverComponent *this, float deltaTime)
{
  UFG::HumanDriverComponent *v2; // rdi
  float v3; // xmm11_4
  UFG::BikePhysicsMoverComponent *v4; // rbx
  UFG::PhysicsVehicle *v5; // rax
  UFG::PhysicsVehicle *v6; // r15
  float v7; // xmm8_4
  char v8; // r13
  float v9; // xmm6_4
  int v10; // edx
  _BOOL8 v11; // rbp
  bool overrideSpeed; // si
  UFG::InputActionData *v13; // rcx
  UFG::InputActionData *v14; // rax
  UFG::InputActionData *v15; // rax
  UFG::InputActionData **v16; // r12
  float v17; // xmm0_4
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
  float v30; // xmm6_4
  UFG::InputActionData *v31; // rax
  UFG::InputActionData *v32; // rax
  UFG::InputActionData *v33; // rax
  UFG::TransformNodeComponent *v34; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v35; // rdx
  float v36; // xmm0_4
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v37; // rcx
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
  UFG::VehicleEffectsComponent *v49; // rcx
  int v50; // eax
  UFG::VehicleEffectsComponent *v51; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v52; // rax
  UFG::InputActionData *v53; // rax
  UFG::InputActionData *v54; // rax
  float v55; // xmm6_4
  bool v56; // si
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v57; // rbx
  UFG::PhysicsVehicle *v58; // rcx
  __m128 v59; // xmm0
  float v60; // xmm1_4
  float v61; // xmm6_4
  float v62; // xmm2_4
  int v63; // eax
  float v64; // xmm6_4
  UFG::OSuiteLeaderboardManager *v65; // rax
  const char *v66; // rdx
  UFG::OSuiteLeaderboardData *v67; // rax
  float v68; // xmm0_4
  bool v69; // si
  float v70; // xmm0_4
  UFG::OSuiteLeaderboardManager *v71; // rax
  UFG::OSuiteLeaderboardData *v72; // rax
  UFG::CopSystem *v73; // rax
  signed int v74; // eax
  float v75; // xmm0_4
  float v76; // xmm6_4
  UFG::OSuiteLeaderboardManager *v77; // rax
  UFG::OSuiteLeaderboardData *v78; // rax
  float v79; // xmm6_4
  UFG::OSuiteLeaderboardManager *v80; // rax
  UFG::OSuiteLeaderboardData *v81; // rax
  float v82; // xmm6_4
  UFG::OSuiteLeaderboardManager *v83; // rax
  UFG::OSuiteLeaderboardData *v84; // rax
  UFG::qVector3 result; // [rsp+30h] [rbp-A8h]
  float v86; // [rsp+3Ch] [rbp-9Ch]
  int v87; // [rsp+40h] [rbp-98h]
  __int64 v88; // [rsp+44h] [rbp-94h]
  int v89; // [rsp+4Ch] [rbp-8Ch]
  UFG::LinearGraph<float> v90; // [rsp+50h] [rbp-88h]
  char v91; // [rsp+E0h] [rbp+8h]

  v2 = this;
  v3 = deltaTime;
  UFG::VehicleDriverInterface::Update((UFG::VehicleDriverInterface *)&this->vfptr, deltaTime);
  v4 = (UFG::BikePhysicsMoverComponent *)v2->m_BoundComponentHandles.mNode.mPrev;
  v5 = v4->mPhysicsVehicle;
  if ( v5 )
  {
    v6 = 0i64;
    if ( *((_BYTE *)v5 + 604) & 7 )
      v6 = v4->mPhysicsVehicle;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v4->mForwardSpeed;
  v8 = 0;
  v91 = 0;
  v9 = v7 * 3.5999999;
  if ( v2->mAudioComponent.mPrev )
  {
    *(_QWORD *)&v2->mBreakOnUpdate = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    *((_DWORD *)&v4->mInput + 4) |= 0x200u;
    v10 = *((_DWORD *)&v4->mInput + 4);
    v11 = LocalPlayer != (UFG::SimObjectCharacter *)v2->mAudioComponent.mPrev;
    overrideSpeed = 0;
    v13 = UFG::ActionDef_Brake.mDataPerController[v11];
    if ( v13 && v13->mActionTrue && !BYTE4(v2->m_ChaseSpawnTransform->m_SafePointerList.mNode.mNext)
      || (v14 = UFG::ActionDef_BrakeButton.mDataPerController[v11]) != 0i64 && v14->mActionTrue )
    {
      overrideSpeed = 1;
      v15 = UFG::ActionDef_Accelerate.mDataPerController[v11];
      v16 = &UFG::ActionDef_Accelerate.mDataPerController[v11];
      if ( v15 && v15->mActionTrue )
      {
        v4->mInput.mGasBrakes = 1.0;
        v4->mInput.mRawGasBrakes = 1.0;
        *((_DWORD *)&v4->mInput + 4) = v10 | 4;
        v8 = 1;
      }
      else if ( *(float *)&v2->mAudioComponent.m_TypeUID > 0.0 )
      {
        v4->mInput.mGasBrakes = 1.0;
        v4->mInput.mRawGasBrakes = 1.0;
        v8 = 1;
      }
      else
      {
        if ( v13 )
          v17 = v13->mAxisPositionX;
        else
          v17 = 0.0;
        v18 = UFG::ActionDef_BrakeButton.mDataPerController[v11];
        if ( v18 && v18->mActionTrue )
          v17 = *(float *)&FLOAT_1_0;
        v19 = LODWORD(v17) ^ _xmm[0];
        v91 = 1;
        *((_DWORD *)&v4->mInput + 4) = v10 | 1;
        LODWORD(v4->mInput.mGasBrakes) = v19;
        LODWORD(v4->mInput.mRawGasBrakes) = v19;
      }
    }
    else
    {
      v20 = UFG::ActionDef_Accelerate.mDataPerController[v11];
      v16 = &UFG::ActionDef_Accelerate.mDataPerController[v11];
      if ( v20 && v20->mActionTrue && !BYTE4(v2->m_ChaseSpawnTransform->m_SafePointerList.mNode.mNext) )
      {
        v21 = LODWORD(v20->mAxisPositionX) ^ _xmm[0];
        LODWORD(v4->mInput.mGasBrakes) = v21;
        LODWORD(v4->mInput.mRawGasBrakes) = v21;
        if ( LODWORD(v2->m_BoundComponentHandles.mNode.mPrev[51].mNext)
          && v6
          && v9 < (float)(v6->mReverseSpeedGovernor * -0.25) )
        {
          LODWORD(v22) = v21 & _xmm;
          v8 = 1;
          v4->mInput.mGasBrakes = v22;
          v4->mInput.mRawGasBrakes = v22;
        }
        v23 = UFG::GameStatTracker::Instance();
        UFG::GameStatTracker::SetStatHigh(v23, TopSpeed, v9);
      }
      else
      {
        v24 = UFG::ActionDef_AccelerateButton.mDataPerController[v11];
        if ( v24 && v24->mActionTrue )
        {
          v4->mInput.mGasBrakes = -1.0;
          v4->mInput.mRawGasBrakes = -1.0;
          if ( LODWORD(v2->m_BoundComponentHandles.mNode.mPrev[51].mNext)
            && v6
            && v9 < (float)(v6->mReverseSpeedGovernor * -0.25) )
          {
            v8 = 1;
            LODWORD(v4->mInput.mGasBrakes) = LODWORD(FLOAT_N1_0) & _xmm;
            LODWORD(v4->mInput.mRawGasBrakes) = LODWORD(FLOAT_N1_0) & _xmm;
          }
          overrideSpeed = 1;
        }
      }
    }
    v25 = v2->m_BoundComponentHandles.mNode.mPrev;
    if ( v25 )
    {
      v26 = v25[41].mPrev;
      if ( v26 && LODWORD(v26[1].mNext) == 2 )
      {
        if ( v4->mInput.mGasBrakes < 0.0 )
          *(_QWORD *)&v4->mInput.mGasBrakes = 0i64;
      }
      else
      {
        v4->mInput.mGasBrakes = UFG::CruiseControl::Update(
                                  (UFG::CruiseControl *)v2->m_ChaseSpawnTransform,
                                  v3,
                                  v7,
                                  v4->mInput.mGasBrakes,
                                  overrideSpeed);
      }
    }
    v27 = UFG::ActionDef_Steer.mDataPerController[v11];
    if ( v27 && v27->mActionTrue )
    {
      v28 = *((_BYTE *)&v4->mInput + 16) >= 0;
      v29 = v27->mAxisPositionX;
      v30 = v27->mAxisPositionY;
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
        v4->mInput.mSteering = UFG::LinearGraph<float>::GetValue(&v90, v29);
      LODWORD(v4->mInput.mForwardWeightShift) = COERCE_UNSIGNED_INT(UFG::LinearGraph<float>::GetValue(&v90, v30)) ^ _xmm[0];
    }
    if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    {
      v4->mInput.mForwardWeightShift = 0.0;
      v31 = UFG::ActionDef_LeanForward.mDataPerController[v11];
      if ( v31 && v31->mActionTrue )
        v4->mInput.mForwardWeightShift = 1.0;
      v32 = UFG::ActionDef_LeanBack.mDataPerController[v11];
      if ( v32 && v32->mActionTrue )
        v4->mInput.mForwardWeightShift = v4->mInput.mForwardWeightShift - 1.0;
    }
    v33 = UFG::ActionDef_HandBrake.mDataPerController[v11];
    if ( v33 && v33->mActionTrue )
      *((_DWORD *)&v4->mInput + 4) |= 4u;
    if ( UFG::HumanDriverComponent::gShouldResetVehicle && v2->m_BoundComponentHandles.mNode.mPrev )
    {
      UFG::HumanDriverComponent::gShouldResetVehicle = 0;
      v34 = v2->m_ChaseSpawnTransform;
      BYTE4(v34->m_SafePointerList.mNode.mNext) = 0;
      UFG::qPidControllerCore::Clear((UFG::qPidControllerCore *)v34->m_SafePointerList.mNode.mPrev);
      ((void (__fastcall *)(UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *, _QWORD))v2->m_BoundComponentHandles.mNode.mPrev->mPrev[7].mPrev)(
        v2->m_BoundComponentHandles.mNode.mPrev,
        0i64);
      HIDWORD(v2->mAudioComponent.mNext) = 2;
    }
    v35 = v2->m_BoundComponentHandles.mNode.mPrev;
    v36 = FLOAT_5_0;
    v37 = v35[40].mNext;
    if ( v37 )
    {
      v38 = 0i64;
      if ( BYTE4(v37[37].mNext) & 7 )
        v38 = v35[40].mNext;
      if ( v38 )
      {
        v37 = v38[38].mNext;
        if ( v37 )
        {
          if ( v37[3].mNext )
          {
            v39 = v35[40].mNext;
            v40 = 0i64;
            if ( v39 && BYTE4(v39[37].mNext) & 7 )
              v40 = v35[40].mNext;
            v37 = v40[38].mNext[3].mNext;
            v36 = *(float *)&v37[7].mPrev;
          }
        }
      }
    }
    if ( v7 > v36 )
      v2->mAudioComponent.m_TypeUID = HIDWORD(v2->mHangTime.mTimestamp);
    else
      *(float *)&v2->mAudioComponent.m_TypeUID = *(float *)&v2->mAudioComponent.m_TypeUID - v3;
    v41 = v2->mRenderComponent.mNext;
    if ( v41 )
    {
      if ( *v16 && (*v16)->mActionTrue )
      {
        if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
                (hkgpIndexedMesh::EdgeBarrier *)v37,
                (hkgpIndexedMeshDefinitions::Edge *)v35) )
        {
          v43 = BYTE4(v41[39].mNext);
          if ( !(v43 & 2) )
            BYTE4(v41[39].mNext) = v43 | 2;
        }
        UFG::VehicleAudioComponent::TurnOnRadio((UFG::VehicleAudioComponent *)v2->mRenderComponent.mNext, v42);
      }
      v44 = UFG::ActionDef_HornStart.mDataPerController[v11];
      if ( v44 && v44->mActionTrue
        || (v45 = UFG::ActionDef_HornStart_Alt.mDataPerController[v11]) != 0i64 && v45->mActionTrue )
      {
        UFG::VehicleAudioComponent::OnActionDefStartHorn((UFG::VehicleAudioComponent *)v2->mRenderComponent.mNext);
      }
      else
      {
        v46 = UFG::ActionDef_HornStop.mDataPerController[v11];
        if ( v46 && v46->mActionTrue
          || (v47 = UFG::ActionDef_HornStop_Alt.mDataPerController[v11]) != 0i64 && v47->mActionTrue )
        {
          UFG::VehicleAudioComponent::OnActionDefStopHorn((UFG::VehicleAudioComponent *)v2->mRenderComponent.mNext);
        }
        else
        {
          v48 = (UFG::VehicleEffectsComponent *)v2->mRenderComponent.mNext;
          *((_BYTE *)&v48->mEffectStatusTable[18] + 22) &= 0xFDu;
          *((_BYTE *)&v48->mEffectStatusTable[18] + 22) |= 4u;
        }
      }
    }
    v49 = (UFG::VehicleEffectsComponent *)v2->mMoverComponent.mNext;
    if ( !v49 )
      goto LABEL_117;
    if ( v8 || ((v50 = (int)v2->mPrev, v50 == 1) || v50 == 6) && *((_BYTE *)&v4->mInput + 16) & 4 )
      UFG::VehicleEffectsComponent::TurnOnLightEffects(v49, FX_BRAKELIGHTS);
    else
      UFG::VehicleEffectsComponent::TurnOffLightEffects(v49, FX_BRAKELIGHTS);
    v51 = (UFG::VehicleEffectsComponent *)v2->mMoverComponent.mNext;
    if ( v91 )
      UFG::VehicleEffectsComponent::TurnOnLightEffects(v51, FX_REVERSE);
    else
      UFG::VehicleEffectsComponent::TurnOffLightEffects(v51, FX_REVERSE);
    v52 = v2->mRenderComponent.mNext;
    if ( v52 )
    {
      if ( BYTE6(v52[39].mNext) & 8 && !*(&v2->mHangTime.mIsStarted + 2) )
      {
        *(&v2->mHangTime.mIsStarted + 2) = 1;
        UFG::VehicleEffectsComponent::TurnOnCopLights((UFG::VehicleEffectsComponent *)v2->mMoverComponent.mNext);
      }
      if ( BYTE6(v2->mRenderComponent.mNext[39].mNext) & 8 || !*(&v2->mHangTime.mIsStarted + 2) )
        goto LABEL_117;
      *(&v2->mHangTime.mIsStarted + 2) = 0;
    }
    else
    {
      v53 = UFG::ActionDef_HornStart.mDataPerController[v11];
      if ( v53 && v53->mActionTrue )
        UFG::VehicleEffectsComponent::TurnOnCopLights((UFG::VehicleEffectsComponent *)v2->mMoverComponent.mNext);
      v54 = UFG::ActionDef_HornStop.mDataPerController[v11];
      if ( !v54 || !v54->mActionTrue )
        goto LABEL_117;
    }
    UFG::VehicleEffectsComponent::TurnOffCopLights((UFG::VehicleEffectsComponent *)v2->mMoverComponent.mNext);
    if ( !v6 )
      goto $LN19_32;
LABEL_117:
    v55 = v6->mBodyTransform.v3.z;
    v56 = ((unsigned __int8 (__fastcall *)(UFG::PhysicsVehicle *))v6->vfptr[4].DebugDraw)(v6)
       && *((float *)&v2->m_BoundComponentHandles.mNode.mPrev[43].mPrev + 1) > 0.0;
    if ( *(&v2->mHangTime.mIsStarted + 1) )
      goto LABEL_165;
    if ( v56 )
    {
      *((float *)&v2->mPrev + 1) = v55;
      v2->mNext = 0i64;
      UFG::SimpleTimer::SetElapsedTime((UFG::SimpleTimer *)&v2->mState, 0.0);
      UFG::SimpleTimer::Start((UFG::SimpleTimer *)&v2->mState);
    }
    if ( *(&v2->mHangTime.mIsStarted + 1) )
    {
LABEL_165:
      if ( !v56 )
        UFG::HumanDriverComponent::StatGameStopInAir((UFG::HumanDriverComponent *)((char *)v2 - 64));
    }
    *(&v2->mHangTime.mIsStarted + 1) = v56;
    if ( v56 )
    {
      v57 = v2->m_BoundComponentHandles.mNode.mPrev;
      v58 = (UFG::PhysicsVehicle *)v57[40].mNext;
      if ( !v58 || (unsigned __int8)UFG::PhysicsVehicle::IsSuspended(v58) )
      {
        v60 = UFG::qVector3::msZero.x;
        v59 = (__m128)LODWORD(UFG::qVector3::msZero.y);
        result.x = UFG::qVector3::msZero.x;
        result.y = UFG::qVector3::msZero.y;
      }
      else
      {
        UFG::PhysicsVehicle::GetVelocity((UFG::PhysicsVehicle *)v57[40].mNext, &result);
        v59 = (__m128)LODWORD(result.y);
        v60 = result.x;
      }
      v61 = v55 - *((float *)&v2->mPrev + 1);
      v62 = *((float *)&v2->mNext + 1);
      result.z = 0.0;
      if ( v61 <= v62 )
        v61 = v62;
      v63 = (int)v2->mPrev;
      *((float *)&v2->mNext + 1) = v61;
      v59.m128_f32[0] = (float)(v59.m128_f32[0] * v59.m128_f32[0]) + (float)(v60 * v60);
      v64 = (float)(COERCE_FLOAT(_mm_sqrt_ps(v59)) * v3) + *(float *)&v2->mNext;
      *(float *)&v2->mNext = v64;
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
          v67 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v65, v66);
          UFG::StatGameManager::UpdateScore(v67, v64, 0);
          goto $LN19_32;
        case 3:
          goto $LN19_32;
        default:
          return;
      }
    }
    else
    {
$LN19_32:
      if ( *(&v2->mHangTime.mIsStarted + 3) )
      {
        v68 = UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH((UFG::PhysicsMoverInterface *)v2->m_BoundComponentHandles.mNode.mPrev);
        v69 = v68 > UFG::sTheoraticalMaxSpeed;
        if ( v68 > UFG::sTheoraticalMaxSpeed && !v2->mHangTime.mIsStarted )
        {
          UFG::SimpleTimer::SetElapsedTime((UFG::SimpleTimer *)&v2->mPropertySet, 0.0);
          UFG::SimpleTimer::Start((UFG::SimpleTimer *)&v2->mPropertySet);
        }
        v70 = UFG::SimpleTimer::GetElapsedSeconds((UFG::SimpleTimer *)&v2->mPropertySet);
        if ( v2->mHangTime.mIsStarted && !v69 )
          UFG::HumanDriverComponent::StatGameStopMaxSpeed((UFG::HumanDriverComponent *)((char *)v2 - 64));
        v2->mHangTime.mIsStarted = v69;
        if ( v69 && LODWORD(v2->mPrev) == 1 )
        {
          v71 = UFG::OSuiteLeaderboardManager::Instance();
          v72 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                  v71,
                  "StatGamesLongestCarMaxSpeed");
          UFG::StatGameManager::UpdateScore(v72, v70, 0);
        }
      }
      v73 = UFG::CopSystem::Instance();
      v74 = ((__int64 (__fastcall *)(UFG::CopSystem *))v73->vfptr[89].__vecDelDtor)(v73);
      if ( (float)(*((float *)&v2->m_BoundComponentHandles.mNode.mPrev[43].mPrev + 1) * 3.5999999) <= UFG::gChaseMinimumDrivingSpeed
        || v74 < 1 )
      {
        v79 = v2->mHangTime.mElapsedTime;
        if ( v79 > 0.0 )
        {
          v80 = UFG::OSuiteLeaderboardManager::Instance();
          v81 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v80, "StatGamesLongestChase");
          UFG::StatGameManager::EndStatGame(v81, (signed int)(float)(v79 * 1000.0));
          v2->mHangTime.mElapsedTime = -1.0;
        }
      }
      else
      {
        v75 = v2->mHangTime.mElapsedTime;
        if ( v75 >= 0.0 )
        {
          v76 = (float)(UFG::Metrics::msInstance.mSimTimeScaleInGame * v3) + v75;
          v2->mHangTime.mElapsedTime = v76;
          v77 = UFG::OSuiteLeaderboardManager::Instance();
          v78 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v77, "StatGamesLongestChase");
          UFG::StatGameManager::UpdateScore(v78, v76, 0);
        }
        else
        {
          v2->mHangTime.mElapsedTime = 0.0;
        }
      }
    }
    return;
  }
  v82 = v2->mHangTime.mElapsedTime;
  v2->mAudioComponent.m_TypeUID = 0;
  if ( v82 > 0.0 )
  {
    v83 = UFG::OSuiteLeaderboardManager::Instance();
    v84 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v83, "StatGamesLongestChase");
    UFG::StatGameManager::EndStatGame(v84, (signed int)(float)(v82 * 1000.0));
    v2->mHangTime.mElapsedTime = -1.0;
  }
  if ( *(&v2->mHangTime.mIsStarted + 1) )
  {
    UFG::HumanDriverComponent::StatGameStopMaxSpeed((UFG::HumanDriverComponent *)((char *)v2 - 64));
    *(&v2->mHangTime.mIsStarted + 1) = 0;
  }
  if ( v2->mHangTime.mIsStarted )
  {
    UFG::HumanDriverComponent::StatGameStopMaxSpeed((UFG::HumanDriverComponent *)((char *)v2 - 64));
    v2->mHangTime.mIsStarted = 0;
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
  UFG::HumanDriverComponent *v1; // rdi
  float v2; // xmm6_4
  UFG::GameStatTracker *v3; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  v1 = this;
  v2 = UFG::SimpleTimer::GetElapsedSeconds(&this->mHangTime);
  UFG::SimpleTimer::Stop(&v1->mHangTime);
  v3 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStatHigh(v3, BestAirTime, v2);
  UFG::GameStatAction::Vehicle::SetLongestJump(v1->m_pSimObject, v1->mJumpDistance);
  v4 = v1->mMoverComponent.m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
  if ( v4 )
  {
    v5 = 0i64;
    if ( BYTE4(v4[37].mNext) & 7 )
      v5 = v1->mMoverComponent.m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
    if ( v5 )
      UFG::GameStatAction::Vehicle::SetHighestJump(HIDWORD(v5[37].mNext) & 7, v1->mHighestJump);
  }
}

// File Line: 569
// RVA: 0x68C5E0
void __fastcall UFG::HumanDriverComponent::StatGameStopMaxSpeed(UFG::HumanDriverComponent *this)
{
  UFG::HumanDriverComponent *v1; // rdi
  float v2; // xmm6_4
  UFG::OSuiteLeaderboardManager *v3; // rax
  UFG::OSuiteLeaderboardData *v4; // rax
  UFG::OSuiteLeaderboardManager *v5; // rax
  UFG::OSuiteLeaderboardData *v6; // rax

  v1 = this;
  v2 = UFG::SimpleTimer::GetElapsedSeconds(&this->mMaxSpeedTime);
  UFG::SimpleTimer::Stop(&v1->mMaxSpeedTime);
  if ( v1->mVehicleType == 2 )
  {
    v3 = UFG::OSuiteLeaderboardManager::Instance();
    v4 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v3, "StatAwardsRecklessDriver");
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v4, v2);
  }
  if ( v1->mVehicleType == 1 )
  {
    v5 = UFG::OSuiteLeaderboardManager::Instance();
    v6 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v5, "StatGamesLongestCarMaxSpeed");
    UFG::StatGameManager::EndStatGame(v6, (signed int)(float)(v2 * 1000.0));
  }
}

