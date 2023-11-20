// File Line: 31
// RVA: 0x157B910
__int64 dynamic_initializer_for__UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList__);
}

// File Line: 32
// RVA: 0x67A430
UFG::ComponentIDDesc *__fastcall UFG::VehicleSubjectComponent::GetDesc(UFG::VehicleSubjectComponent *this)
{
  return &UFG::VehicleSubjectComponent::_TypeIDesc;
}

// File Line: 36
// RVA: 0x66B920
void __fastcall UFG::VehicleSubjectComponent::VehicleSubjectComponent(UFG::VehicleSubjectComponent *this, unsigned int name_uid)
{
  UFG::VehicleSubjectComponent *v2; // rdi
  UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *v3; // rbx
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *v4; // rax
  UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::qVector4 v16; // xmm1
  UFG::qVector4 v17; // xmm2
  UFG::qVector4 v18; // xmm3
  UFG::qVector4 v19; // xmm1
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm3
  UFG::ChaseCameraParameters *v22; // rax
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *result; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::CameraSubject::CameraSubject((UFG::CameraSubject *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleSubjectComponent::`vftable';
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0>::RebindingComponentHandle<UFG::AiDriverComponent,0>(&v2->pAiDriver);
  UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0>::RebindingComponentHandle<UFG::RoadSpaceComponent,0>(&v2->pRoadSpace);
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>(&v2->pPhysicsMover);
  UFG::RebindingComponentHandle<UFG::VehicleOccupantComponent,0>::RebindingComponentHandle<UFG::VehicleOccupantComponent,0>(&v2->pVehicleOccupants);
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&v2->pAnimation);
  UFG::RebindingComponentHandle<UFG::TargetingSystemVehicleComponent,0>::RebindingComponentHandle<UFG::TargetingSystemVehicleComponent,0>(&v2->pTargetingSystem);
  *(_QWORD *)&v2->mBox.mMin.x = 0i64;
  *(_QWORD *)&v2->mBox.mMin.z = 0i64;
  *(_QWORD *)&v2->mBox.mMax.y = 0i64;
  v4 = &v2->mChaserList;
  result = v4;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v2->mFollowOverrideContext.mUID = -1;
  v5 = UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList.mNode.mPrev;
  UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *)&v2->mPrev;
  v3->mPrev = v5;
  v2->mNext = (UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *)&UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList;
  UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList.mNode.mPrev = (UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::VehicleSubjectComponent::_VehicleSubjectComponentTypeUID,
    "VehicleSubjectComponent");
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  v2->vAngularVelocity.x = UFG::qVector3::msZero.x;
  v2->vAngularVelocity.y = v6;
  v2->vAngularVelocity.z = v7;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  v2->vVelocity.x = UFG::qVector3::msZero.x;
  v2->vVelocity.y = v8;
  v2->vVelocity.z = v9;
  v10 = UFG::qVector3::msUnity.y;
  v11 = UFG::qVector3::msUnity.z;
  v2->vUp.x = UFG::qVector3::msUnity.x;
  v2->vUp.y = v10;
  v2->vUp.z = v11;
  v12 = UFG::qVector3::msZero.y;
  v13 = UFG::qVector3::msZero.z;
  v2->vOriginOffset.x = UFG::qVector3::msZero.x;
  v2->vOriginOffset.y = v12;
  v2->vOriginOffset.z = v13;
  *(_QWORD *)&v2->rAimLookOffsetLowZ = 0i64;
  v2->rAimDistFromSide = 1.8;
  *(_QWORD *)&v2->rAimDistFromBumper = 1053609165i64;
  v2->rAimOriginOffsetConstX = 0.0;
  v14 = UFG::qVector3::msZero.y;
  v15 = UFG::qVector3::msZero.z;
  v2->mPositionOffset.x = UFG::qVector3::msZero.x;
  v2->mPositionOffset.y = v14;
  v2->mPositionOffset.z = v15;
  v16 = UFG::qMatrix44::msIdentity.v1;
  v17 = UFG::qMatrix44::msIdentity.v2;
  v18 = UFG::qMatrix44::msIdentity.v3;
  v2->mLocalWorldOffset.v0 = UFG::qMatrix44::msIdentity.v0;
  v2->mLocalWorldOffset.v1 = v16;
  v2->mLocalWorldOffset.v2 = v17;
  v2->mLocalWorldOffset.v3 = v18;
  v19 = UFG::qMatrix44::msIdentity.v1;
  v20 = UFG::qMatrix44::msIdentity.v2;
  v21 = UFG::qMatrix44::msIdentity.v3;
  v2->mWorldLocalOffset.v0 = UFG::qMatrix44::msIdentity.v0;
  v2->mWorldLocalOffset.v1 = v19;
  v2->mWorldLocalOffset.v2 = v20;
  v2->mWorldLocalOffset.v3 = v21;
  *(_WORD *)&v2->bFleeing = 256;
  v2->bCanPassRight = 1;
  v2->mRadius = 0.0;
  v19.x = UFG::qVector3::msZero.y;
  v20.x = UFG::qVector3::msZero.z;
  v2->mBox.mMin.x = UFG::qVector3::msZero.x;
  v2->mBox.mMin.y = v19.x;
  v2->mBox.mMin.z = v20.x;
  v19.x = UFG::qVector3::msZero.y;
  v20.x = UFG::qVector3::msZero.z;
  v2->mBox.mMax.x = UFG::qVector3::msZero.x;
  v2->mBox.mMax.y = v19.x;
  v2->mBox.mMax.z = v20.x;
  v2->mSeatBone = -2;
  v2->pActionHijacker = 0i64;
  v2->pPlayerOccupant = 0i64;
  v2->mFollowOverrideContext.mUID = UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&result, 0xFFFFFFFF)->mUID;
  v22 = UFG::DefaultChaseParameters();
  v2->pChaseParametersAim = v22;
  v2->pChaseParametersFlee = v22;
  v2->pChaseParametersRace = v22;
  v2->pChaseParametersDrive = v22;
  v2->pChaseParametersBurnout = v22;
  v2->pChaseParametersLookUp = v22;
  v2->pChaseParametersLookBack = v22;
  v2->pChaseParametersLookSide = v22;
  v2->pChaseParametersPassenger = v22;
  v2->pChaseParametersHijackBack = v22;
  v2->pChaseParametersHijackSide = v22;
  v2->pChaseParametersHijackFront = v22;
  v2->pChaseParametersHijackTop = v22;
}

// File Line: 86
// RVA: 0x66D7A0
void __fastcall UFG::VehicleSubjectComponent::~VehicleSubjectComponent(UFG::VehicleSubjectComponent *this)
{
  UFG::VehicleSubjectComponent *v1; // rsi
  UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *v2; // rdi
  UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *v3; // rcx
  UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *v4; // rax
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v5; // rcx
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v6; // rax
  UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *v7; // rcx
  UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *v8; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleSubjectComponent::`vftable';
  if ( this == UFG::VehicleSubjectComponent::s_VehicleSubjectComponentpCurrentIterator )
    UFG::VehicleSubjectComponent::s_VehicleSubjectComponentpCurrentIterator = (UFG::VehicleSubjectComponent *)&this->mPrev[-18];
  v2 = (UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v1->mChaserList);
  UFG::VehicleSubjectComponent::HandleChaserListChange(v1);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v1->mChaserList);
  v5 = v1->mChaserList.mNode.mPrev;
  v6 = v1->mChaserList.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->mChaserList.mNode.mPrev = &v1->mChaserList.mNode;
  v1->mChaserList.mNode.mNext = &v1->mChaserList.mNode;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->pTargetingSystem);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->pAnimation);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->pVehicleOccupants);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->pPhysicsMover);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->pRoadSpace);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->pAiDriver);
  v7 = v2->mPrev;
  v8 = v2->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::CameraSubject::~CameraSubject((UFG::CameraSubject *)&v1->vfptr);
}

// File Line: 98
// RVA: 0x67D0D0
bool __fastcall UFG::VehicleSubjectComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qSymbol *)&SimSymX_propset_componentVehicleSubject.mUID);
}

// File Line: 104
// RVA: 0x687D80
UFG::SimComponent *__fastcall UFG::VehicleSubjectComponent::PropertiesOnActivate(UFG::SceneObjectProperties *scene_object_properties)
{
  UFG::SceneObjectProperties *v1; // rbx
  unsigned int v2; // edi
  UFG::qMemoryPool *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *v7; // rdx
  unsigned __int16 v8; // cx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h]

  v1 = scene_object_properties;
  v2 = scene_object_properties->m_NameUID;
  v3 = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(v3, 0x3D8ui64, "VehicleSubjectComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::VehicleSubjectComponent::VehicleSubjectComponent((UFG::VehicleSubjectComponent *)v4, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v1->m_pSimObject;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 || (v8 & 0x8000u) == 0 )
    v9 = -1;
  else
    v9 = 31;
  UFG::SimObjectModifier::SimObjectModifier(&v11, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v6, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return v6;
}

// File Line: 112
// RVA: 0x68D200
void __fastcall UFG::VehicleSubjectComponent::TeleportEventHandler(UFG::VehicleSubjectComponent *this, UFG::Event *event)
{
  UFG::SimObject *v2; // rdi
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rax
  UFG::ChaseCameraComponent *v5; // rbx

  v2 = this->m_pSimObject;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    v4 = UFG::SimObject::GetComponentOfType(v3, UFG::ChaseCameraComponent::_TypeUID);
    v5 = (UFG::ChaseCameraComponent *)v4;
    if ( v4 )
    {
      if ( v2 == (UFG::SimObject *)((__int64 (__fastcall *)(UFG::SimComponent *))v4->vfptr[17].__vecDelDtor)(v4) )
      {
        ((void (__fastcall *)(UFG::ChaseCameraComponent *))v5->vfptr[14].__vecDelDtor)(v5);
        v5->vfptr[16].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v5->vfptr, (unsigned int)v2);
        UFG::ChaseCameraComponent::LockEye(v5, 0);
        ((void (__fastcall *)(UFG::ChaseCameraComponent *))v5->vfptr[15].__vecDelDtor)(v5);
        ((void (__fastcall *)(UFG::ChaseCameraComponent *))v5->vfptr[31].__vecDelDtor)(v5);
      }
    }
  }
}

// File Line: 127
// RVA: 0x66F370
void __fastcall UFG::VehicleSubjectComponent::AddChaser(UFG::VehicleSubjectComponent *this, UFG::SimObject *chaser)
{
  UFG::SimObject *v2; // rdi
  UFG::VehicleSubjectComponent *v3; // rsi
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v4; // rax
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rcx
  UFG::allocator::free_link *v8; // rax

  v2 = chaser;
  v3 = this;
  v4 = this->mChaserList.mNode.mNext;
  v5 = &this->mChaserList;
  if ( v4 == (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)&this->mChaserList )
  {
LABEL_4:
    v6 = UFG::qMalloc(0x18ui64, "VehicleEffectsComponent.SimObjectPointer", 0i64);
    v7 = v6;
    if ( v6 )
    {
      v6->mNext = v6;
      v6[1].mNext = v6;
      v6[2].mNext = (UFG::allocator::free_link *)v2;
    }
    else
    {
      v7 = 0i64;
    }
    v8 = (UFG::allocator::free_link *)v5->mNode.mPrev;
    v8[1].mNext = v7;
    v7->mNext = v8;
    v7[1].mNext = (UFG::allocator::free_link *)v5;
    v5->mNode.mPrev = (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)v7;
  }
  else
  {
    while ( chaser != (UFG::SimObject *)v4[1].mPrev )
    {
      v4 = v4->mNext;
      if ( v4 == (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)v5 )
        goto LABEL_4;
    }
  }
  UFG::VehicleSubjectComponent::HandleChaserListChange(v3);
}

// File Line: 134
// RVA: 0x689660
void __fastcall UFG::VehicleSubjectComponent::RemoveChaser(UFG::VehicleSubjectComponent *this, UFG::SimObject *chaser)
{
  UFG::VehicleSubjectComponent *v2; // rdi
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v3; // rcx
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v4; // rdx
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v5; // rax
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v6; // rdx
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v7; // rax
  UFG::SimComponent *v8; // rdx

  v2 = this;
  v3 = this->mChaserList.mNode.mNext;
  if ( v3 != (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)&v2->mChaserList )
  {
    while ( chaser != (UFG::SimObject *)v3[1].mPrev )
    {
      v3 = v3->mNext;
      if ( v3 == (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)&v2->mChaserList )
        goto LABEL_6;
    }
    v4 = v3->mPrev;
    v5 = v3->mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = v3;
    v3->mNext = v3;
    v6 = v3->mPrev;
    v7 = v3->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v3->mPrev = v3;
    v3->mNext = v3;
    operator delete[](v3);
  }
LABEL_6:
  if ( (UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *)v2->mChaserList.mNode.mNext == &v2->mChaserList )
  {
    v8 = v2->pRoadSpace.m_pSimComponent;
    if ( v8 )
    {
      if ( v8[30].m_TypeUID & 1 )
        UFG::Simulation::DestroySimComponent(&UFG::gSim, v8);
    }
  }
  UFG::VehicleSubjectComponent::HandleChaserListChange(v2);
}

// File Line: 150
// RVA: 0x67BB30
void __fastcall UFG::VehicleSubjectComponent::HandleChaserListChange(UFG::VehicleSubjectComponent *this)
{
  UFG::VehicleSubjectComponent *v1; // rdi
  UFG::SimComponent *v2; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rbx
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *v4; // rsi
  UFG::allocator::free_link *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax

  v1 = this;
  if ( this->pRoadSpace.m_pSimComponent )
  {
    v2 = this->pRoadSpace.m_pSimComponent;
    v3 = v2[26].m_BoundComponentHandles.mNode.mPrev;
    v4 = &this->mChaserList;
    if ( (UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *)this->mChaserList.mNode.mNext == &this->mChaserList )
    {
      if ( v3 )
      {
        UFG::VehicleFormations::~VehicleFormations((UFG::VehicleFormations *)v2[26].m_BoundComponentHandles.mNode.mPrev);
        operator delete[](v3);
        v1->pRoadSpace.m_pSimComponent[26].m_BoundComponentHandles.mNode.mPrev = 0i64;
      }
    }
    else
    {
      if ( !v3 )
      {
        v5 = UFG::qMalloc(0x268ui64, "VehicleEffectsComponent.VehicleFormations", 0i64);
        if ( v5 )
        {
          UFG::VehicleFormations::VehicleFormations((UFG::VehicleFormations *)v5, v1, v4);
          v3 = v6;
        }
        else
        {
          v3 = 0i64;
        }
        v1->pRoadSpace.m_pSimComponent[26].m_BoundComponentHandles.mNode.mPrev = v3;
      }
      BYTE6(v3[38].mPrev) = 1;
    }
  }
}

// File Line: 183
// RVA: 0x67F330
bool __fastcall UFG::VehicleSubjectComponent::IsInReverse(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *v1; // rax

  v1 = this->pPhysicsMover.m_pSimComponent;
  return v1 && (_QWORD)v1[1].m_pSimObject & 1;
}

// File Line: 189
// RVA: 0x67ED90
bool __fastcall UFG::VehicleSubjectComponent::IsGas(UFG::VehicleSubjectComponent *this)
{
  UFG::PhysicsMoverInterface *v1; // rax

  v1 = (UFG::PhysicsMoverInterface *)this->pPhysicsMover.m_pSimComponent;
  return v1 && v1->mInput.mRawGasBrakes < -0.2;
}

// File Line: 195
// RVA: 0x67F220
bool __fastcall UFG::VehicleSubjectComponent::IsInAir(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *v1; // rcx
  bool result; // al

  v1 = this->pPhysicsMover.m_pSimComponent;
  if ( v1 )
    v1 = (UFG::SimComponent *)v1[10].m_SafePointerList.mNode.mPrev;
  if ( v1 )
    result = ((__int64 (*)(void))v1->vfptr[14].__vecDelDtor)();
  else
    result = 0;
  return result;
}

// File Line: 222
// RVA: 0x681F10
__int64 __fastcall UFG::VehicleSubjectComponent::NumChasersCloserThan(UFG::VehicleSubjectComponent *this, float distance)
{
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v2; // rbx
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *v3; // rbp
  unsigned int v4; // edi
  UFG::VehicleSubjectComponent *v5; // r14
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v6; // rax
  float *v7; // rsi
  float *v8; // rax

  v2 = this->mChaserList.mNode.mNext;
  v3 = &this->mChaserList;
  v4 = 0;
  v5 = this;
  if ( v2 != (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)&this->mChaserList )
  {
    do
    {
      v6 = v2[1].mPrev;
      if ( v6 )
      {
        v7 = (float *)v6[5].mNext;
        if ( v7 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v6[5].mNext);
          v8 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v5->vfptr[17].__vecDelDtor)(v5);
          if ( (float)((float)((float)((float)(v8[1] - v7[45]) * (float)(v8[1] - v7[45]))
                             + (float)((float)(*v8 - v7[44]) * (float)(*v8 - v7[44])))
                     + (float)((float)(v8[2] - v7[46]) * (float)(v8[2] - v7[46]))) < (float)(distance * distance) )
            ++v4;
        }
      }
      v2 = v2->mNext;
    }
    while ( v2 != (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)v3 );
  }
  return v4;
}

// File Line: 240
// RVA: 0x689220
void __fastcall UFG::VehicleSubjectComponent::ReassignChasersTo(UFG::VehicleSubjectComponent *this, UFG::SimObject *new_target)
{
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v2; // rbx
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *v3; // rdi
  UFG::SimObject *v4; // rsi
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v5; // rax
  UFG::SimObjectCVBase *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::AiDriverComponent *v8; // rax

  v2 = this->mChaserList.mNode.mNext;
  v3 = &this->mChaserList;
  v4 = new_target;
  v5 = v2;
  if ( v2 != (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)&this->mChaserList )
  {
    do
    {
      v6 = (UFG::SimObjectCVBase *)v5[1].mPrev;
      v2 = v2->mNext;
      if ( v6 )
      {
        v7 = v6->m_Flags;
        if ( (v7 >> 14) & 1 )
        {
          v8 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v6);
        }
        else if ( (v7 & 0x8000u) == 0 )
        {
          if ( (v7 >> 13) & 1 )
          {
            v8 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v6->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          }
          else if ( (v7 >> 12) & 1 )
          {
            v8 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v6->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          }
          else
          {
            v8 = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v6->vfptr,
                                             UFG::AiDriverComponent::_TypeUID);
          }
        }
        else
        {
          v8 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v6);
        }
        if ( v8 )
          UFG::AiDriverComponent::SetChaseTarget(v8, v4);
      }
      v5 = v2;
    }
    while ( v2 != (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)v3 );
  }
}

// File Line: 251
// RVA: 0x1582AC0
__int64 UFG::_dynamic_initializer_for__default_chase_parameter_set__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Cameras-ChaseCameraCommon", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::default_chase_parameter_set, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__default_chase_parameter_set__);
}

// File Line: 254
// RVA: 0x683B10
void __fastcall UFG::VehicleSubjectComponent::OnAttach(UFG::VehicleSubjectComponent *this, UFG::SimObject *object)
{
  UFG::SimObjectVehicle *v2; // rsi
  UFG::VehicleSubjectComponent *v3; // rbx
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *v4; // rcx
  UFG::qSymbol *v5; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v10; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemVehicleComponent,0> *v15; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::SimObject *v20; // rcx
  UFG::SceneObjectProperties *v21; // rsi
  UFG::qPropertySet *v22; // rax
  UFG::qStaticSymbol *v23; // r14
  UFG::qPropertySet *v24; // rax
  float v25; // xmm1_4
  float v26; // xmm2_4
  UFG::qPropertySet *v27; // rax
  UFG::qPropertySet *v28; // rax
  UFG::qPropertySet *v29; // rax
  UFG::qPropertySet *v30; // rax
  UFG::qPropertySet *v31; // rax
  UFG::qPropertySet *v32; // rax
  UFG::qPropertySet *v33; // rsi
  UFG::qSymbol _override; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *v35; // [rsp+58h] [rbp+10h]

  v2 = (UFG::SimObjectVehicle *)object;
  v3 = this;
  UFG::CameraSubject::OnAttach((UFG::CameraSubject *)&this->vfptr, object);
  v4 = &v3->pAiDriver;
  v5 = 0i64;
  if ( v3->pAiDriver.m_pSimComponent )
  {
    v6 = v4->mPrev;
    v7 = v3->pAiDriver.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v3->pAiDriver.m_pSimComponent = 0i64;
LABEL_7:
    v3->pAiDriver.m_pSimObject = 0i64;
    v3->pAiDriver.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->pAiDriver.mPrev;
    v4->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v4->mPrev;
    goto LABEL_8;
  }
  if ( v3->pAiDriver.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *)v4->mPrev != v4
     || (UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *)v3->pAiDriver.mNext != &v3->pAiDriver) )
  {
    v8 = v4->mPrev;
    v9 = v3->pAiDriver.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  v3->pAiDriver.m_Changed = 1;
  v3->pAiDriver.m_pSimObject = (UFG::SimObject *)&v2->vfptr;
  v3->pAiDriver.m_TypeUID = UFG::AiDriverComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0>::BindInternal<UFG::SimObjectVehicle>(v4, v2);
  UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0>::Bind<UFG::SimObjectVehicle>(&v3->pRoadSpace, v2);
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::Bind<UFG::SimObjectVehicle>(&v3->pPhysicsMover, v2);
  v10 = &v3->pAnimation;
  if ( v3->pAnimation.m_pSimComponent )
  {
    v11 = v10->mPrev;
    v12 = v3->pAnimation.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v3->pAnimation.m_pSimComponent = 0i64;
LABEL_14:
    v3->pAnimation.m_pSimObject = 0i64;
    v3->pAnimation.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->pAnimation.mPrev;
    v10->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v10->mPrev;
    goto LABEL_15;
  }
  if ( v3->pAnimation.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v10->mPrev != v10
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v3->pAnimation.mNext != &v3->pAnimation) )
  {
    v13 = v10->mPrev;
    v14 = v3->pAnimation.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    goto LABEL_14;
  }
LABEL_15:
  v3->pAnimation.m_Changed = 1;
  v3->pAnimation.m_pSimObject = (UFG::SimObject *)&v2->vfptr;
  v3->pAnimation.m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObjectVehicle>(
    &v3->pAnimation,
    (UFG::SimObjectCharacter *)v2);
  v15 = &v3->pTargetingSystem;
  if ( v3->pTargetingSystem.m_pSimComponent )
  {
    v16 = v15->mPrev;
    v17 = v3->pTargetingSystem.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v3->pTargetingSystem.m_pSimComponent = 0i64;
LABEL_21:
    v3->pTargetingSystem.m_pSimObject = 0i64;
    v3->pTargetingSystem.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->pTargetingSystem.mPrev;
    v15->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v15->mPrev;
    goto LABEL_22;
  }
  if ( v3->pTargetingSystem.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemVehicleComponent,0> *)v15->mPrev != v15
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemVehicleComponent,0> *)v3->pTargetingSystem.mNext != &v3->pTargetingSystem) )
  {
    v18 = v15->mPrev;
    v19 = v3->pTargetingSystem.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    goto LABEL_21;
  }
LABEL_22:
  v3->pTargetingSystem.m_Changed = 1;
  v3->pTargetingSystem.m_pSimObject = (UFG::SimObject *)&v2->vfptr;
  v3->pTargetingSystem.m_TypeUID = UFG::TargetingSystemVehicleComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemVehicleComponent,0>::BindInternal<UFG::SimObjectVehicle>(
    &v3->pTargetingSystem,
    v2);
  UFG::RebindingComponentHandle<UFG::VehicleOccupantComponent,0>::Bind<UFG::SimObjectVehicle>(
    &v3->pVehicleOccupants,
    v2);
  if ( v3->pPhysicsMover.m_pSimComponent )
  {
    v20 = v3->pPhysicsMover.m_pSimComponent->m_pSimObject;
    v21 = v20->m_pSceneObj;
    if ( v21 )
    {
      v22 = PropertyUtils::Get<UFG::qSymbol>(
              v20->m_pSceneObj,
              (UFG::qSymbol *)&CAMERA_SYMBOL_ChaseCameraParameters.mUID);
      v23 = &UFG::default_chase_parameter_set;
      if ( v22 )
        v23 = (UFG::qStaticSymbol *)v22;
      v24 = PropertyUtils::Get<UFG::qVector3>(v21, (UFG::qSymbol *)&CAMERA_SYMBOL_OriginOffset.mUID);
      if ( v24 )
      {
        v25 = *(float *)&v24->mPad0;
        v26 = *(float *)&v24->mOwner.mOffset;
        LODWORD(v3->vOriginOffset.x) = v24->mFlags;
        v3->vOriginOffset.y = v25;
        v3->vOriginOffset.z = v26;
      }
      v27 = PropertyUtils::Get<float>(v21, (UFG::qSymbol *)&CAMERA_SYMBOL_AimLookOffsetLowZ.mUID);
      if ( v27 )
        LODWORD(v3->rAimLookOffsetLowZ) = v27->mFlags;
      v28 = PropertyUtils::Get<float>(v21, (UFG::qSymbol *)&CAMERA_SYMBOL_AimLookOffsetHighZ.mUID);
      if ( v28 )
        LODWORD(v3->rAimLookOffsetHighZ) = v28->mFlags;
      v29 = PropertyUtils::Get<float>(v21, (UFG::qSymbol *)&CAMERA_SYMBOL_AimDistFromSide.mUID);
      if ( v29 )
        LODWORD(v3->rAimDistFromSide) = v29->mFlags;
      v30 = PropertyUtils::Get<float>(v21, (UFG::qSymbol *)&CAMERA_SYMBOL_AimDistFromBumper.mUID);
      if ( v30 )
        LODWORD(v3->rAimDistFromBumper) = v30->mFlags;
      v31 = PropertyUtils::Get<float>(v21, (UFG::qSymbol *)&CAMERA_SYMBOL_AimOriginOffsetX.mUID);
      if ( v31 )
        LODWORD(v3->rAimOriginOffsetX) = v31->mFlags;
      v32 = PropertyUtils::Get<float>(v21, (UFG::qSymbol *)&CAMERA_SYMBOL_AimOriginOffsetConstX.mUID);
      if ( v32 )
        LODWORD(v3->rAimOriginOffsetConstX) = v32->mFlags;
      v35 = &_override;
      _override.mUID = v23->mUID;
      if ( UFG::CharacterSubjectComponent::IsOverrideSymbolValid((__int64)&_override) )
      {
        v3->mFollowOverrideContext.mUID = v23->mUID;
        v23 = &UFG::default_chase_parameter_set;
      }
      v33 = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)&v23->mUID);
      if ( Cameras_ChaseCameraCommon::IsClass(v33->mSchemaName.mUID) )
        v5 = (UFG::qSymbol *)UFG::qPropertySet::GetMemImagePtr(v33);
      v3->pChaseParametersAim = UFG::FindChaseParameters(v5);
      v3->pChaseParametersFlee = UFG::FindChaseParameters(v5 + 1);
      v3->pChaseParametersRace = UFG::FindChaseParameters(v5 + 2);
      v3->pChaseParametersDrive = UFG::FindChaseParameters(v5 + 3);
      v3->pChaseParametersBurnout = UFG::FindChaseParameters(v5 + 4);
      v3->pChaseParametersLookUp = UFG::FindChaseParameters(v5 + 5);
      v3->pChaseParametersLookBack = UFG::FindChaseParameters(v5 + 6);
      v3->pChaseParametersLookSide = UFG::FindChaseParameters(v5 + 7);
      v3->pChaseParametersPassenger = UFG::FindChaseParameters(v5 + 8);
      v3->pChaseParametersHijackBack = UFG::FindChaseParameters(v5 + 9);
      v3->pChaseParametersHijackSide = UFG::FindChaseParameters(v5 + 10);
      v3->pChaseParametersHijackFront = UFG::FindChaseParameters(v5 + 11);
      v3->pChaseParametersHijackTop = UFG::FindChaseParameters(v5 + 12);
    }
  }
}

// File Line: 336
// RVA: 0x684660
void __fastcall UFG::VehicleSubjectComponent::OnDetach(UFG::VehicleSubjectComponent *this)
{
  UFG::RebindingComponentHandle<UFG::VehicleOccupantComponent,0> *v1; // r8
  UFG::VehicleSubjectComponent *v2; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemVehicleComponent,0> *v7; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *v12; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *v17; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0> *v22; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *v27; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  float v32; // xmm1_4
  float v33; // xmm2_4
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h]

  v1 = &this->pVehicleOccupants;
  v2 = this;
  if ( this->pVehicleOccupants.m_pSimComponent )
  {
    v3 = v1->mPrev;
    v4 = this->pVehicleOccupants.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    this->pVehicleOccupants.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->pVehicleOccupants.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::VehicleOccupantComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::VehicleOccupantComponent,0> *)this->pVehicleOccupants.mNext != &this->pVehicleOccupants) )
  {
    v5 = v1->mPrev;
    v6 = v1->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  v7 = &v2->pTargetingSystem;
  v1->m_Changed = 1;
  if ( v2->pTargetingSystem.m_pSimComponent )
  {
    v8 = v7->mPrev;
    v9 = v2->pTargetingSystem.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v2->pTargetingSystem.m_pSimComponent = 0i64;
LABEL_14:
    v2->pTargetingSystem.m_pSimObject = 0i64;
    v2->pTargetingSystem.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->pTargetingSystem.mPrev;
    v7->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v7->mPrev;
    goto LABEL_15;
  }
  if ( v2->pTargetingSystem.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TargetingSystemVehicleComponent,0> *)v7->mPrev != v7
     || (UFG::RebindingComponentHandle<UFG::TargetingSystemVehicleComponent,0> *)v2->pTargetingSystem.mNext != &v2->pTargetingSystem) )
  {
    v10 = v7->mPrev;
    v11 = v2->pTargetingSystem.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  v2->pTargetingSystem.m_Changed = 1;
  v12 = &v2->pPhysicsMover;
  if ( v2->pPhysicsMover.m_pSimComponent )
  {
    v13 = v12->mPrev;
    v14 = v2->pPhysicsMover.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v2->pPhysicsMover.m_pSimComponent = 0i64;
LABEL_21:
    v2->pPhysicsMover.m_pSimObject = 0i64;
    v2->pPhysicsMover.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->pPhysicsMover.mPrev;
    v12->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v12->mPrev;
    goto LABEL_22;
  }
  if ( v2->pPhysicsMover.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *)v12->mPrev != v12
     || (UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *)v2->pPhysicsMover.mNext != &v2->pPhysicsMover) )
  {
    v15 = v12->mPrev;
    v16 = v2->pPhysicsMover.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  v2->pPhysicsMover.m_Changed = 1;
  v17 = &v2->pAnimation;
  if ( v2->pAnimation.m_pSimComponent )
  {
    v18 = v17->mPrev;
    v19 = v2->pAnimation.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v2->pAnimation.m_pSimComponent = 0i64;
LABEL_28:
    v2->pAnimation.m_pSimObject = 0i64;
    v2->pAnimation.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->pAnimation.mPrev;
    v17->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v17->mPrev;
    goto LABEL_29;
  }
  if ( v2->pAnimation.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v17->mPrev != v17
     || (UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *)v2->pAnimation.mNext != &v2->pAnimation) )
  {
    v20 = v17->mPrev;
    v21 = v2->pAnimation.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  v2->pAnimation.m_Changed = 1;
  v22 = &v2->pRoadSpace;
  if ( v2->pRoadSpace.m_pSimComponent )
  {
    v23 = v22->mPrev;
    v24 = v2->pRoadSpace.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    v2->pRoadSpace.m_pSimComponent = 0i64;
LABEL_35:
    v2->pRoadSpace.m_pSimObject = 0i64;
    v2->pRoadSpace.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->pRoadSpace.mPrev;
    v22->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v22->mPrev;
    goto LABEL_36;
  }
  if ( v2->pRoadSpace.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0> *)v22->mPrev != v22
     || (UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0> *)v2->pRoadSpace.mNext != &v2->pRoadSpace) )
  {
    v25 = v22->mPrev;
    v26 = v2->pRoadSpace.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  v2->pRoadSpace.m_Changed = 1;
  v27 = &v2->pAiDriver;
  if ( v2->pAiDriver.m_pSimComponent )
  {
    v28 = v27->mPrev;
    v29 = v2->pAiDriver.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    v2->pAiDriver.m_pSimComponent = 0i64;
LABEL_42:
    v2->pAiDriver.m_pSimObject = 0i64;
    v2->pAiDriver.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v2->pAiDriver.mPrev;
    v27->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v27->mPrev;
    goto LABEL_43;
  }
  if ( v2->pAiDriver.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *)v27->mPrev != v27
     || (UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *)v2->pAiDriver.mNext != &v2->pAiDriver) )
  {
    v30 = v27->mPrev;
    v31 = v2->pAiDriver.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    goto LABEL_42;
  }
LABEL_43:
  v2->pAiDriver.m_Changed = 1;
  v2->mFollowOverrideContext.mUID = UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF)->mUID;
  v32 = UFG::qVector3::msZero.y;
  v33 = UFG::qVector3::msZero.z;
  v2->vOriginOffset.x = UFG::qVector3::msZero.x;
  v2->vOriginOffset.y = v32;
  v2->vOriginOffset.z = v33;
  *(_QWORD *)&v2->rAimLookOffsetLowZ = 0i64;
  v2->rAimDistFromSide = 1.8;
  *(_QWORD *)&v2->rAimDistFromBumper = 1053609165i64;
  v2->rAimOriginOffsetConstX = 0.0;
  UFG::CameraSubject::OnDetach((UFG::CameraSubject *)&v2->vfptr);
  v2->mSeatBone = -2;
}

// File Line: 367
// RVA: 0x67A1E0
UFG::SimObject *__fastcall UFG::VehicleSubjectComponent::GetChaseTarget(UFG::VehicleSubjectComponent *this)
{
  UFG::SimObject *result; // rax

  result = (UFG::SimObject *)this->pRoadSpace.m_pSimComponent;
  if ( result )
    result = (UFG::SimObject *)result[13].mNode.mParent;
  return result;
}

// File Line: 373
// RVA: 0x67F3A0
UFG::SimComponent *__fastcall UFG::VehicleSubjectComponent::IsParkedWithDriver(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *result; // rax

  result = this->pAiDriver.m_pSimComponent;
  if ( result )
    result = (UFG::SimComponent *)BYTE1(result[22].m_BoundComponentHandles.mNode.mNext);
  return result;
}

// File Line: 385
// RVA: 0x67F3C0
bool __fastcall UFG::VehicleSubjectComponent::IsParkedWithoutDriver(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *v1; // rax

  v1 = this->pVehicleOccupants.m_pSimComponent;
  return v1 && v1[1].m_SafePointerList.mNode.mNext;
}

// File Line: 390
// RVA: 0x67F530
signed __int64 __fastcall UFG::VehicleSubjectComponent::IsRacing(UFG::VehicleSubjectComponent *this)
{
  UFG::VehicleSubjectComponent *v1; // rbx
  UFG::SimComponent *v2; // rax
  UFG::SimComponent *v4; // rax

  v1 = this;
  if ( ((unsigned __int8 (*)(void))this->vfptr[32].__vecDelDtor)() )
  {
    v2 = v1->pRoadSpace.m_pSimComponent;
    if ( !v2 || !v2[26].m_SafePointerList.mNode.mPrev )
      return 0i64;
  }
  else
  {
    v4 = v1->pAiDriver.m_pSimComponent;
    if ( !v4 || LODWORD(v4[13].m_SafePointerList.mNode.mPrev) != 6 )
      return 0i64;
  }
  return 1i64;
}

// File Line: 407
// RVA: 0x67ED60
bool __fastcall UFG::VehicleSubjectComponent::IsEnemy(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *v1; // rax

  v1 = this->pVehicleOccupants.m_pSimComponent;
  return v1 && v1[1].m_pSimObject && this->pAiDriver.m_pSimComponent;
}

// File Line: 412
// RVA: 0x67F3E0
bool __fastcall UFG::VehicleSubjectComponent::IsPlayer(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *v1; // rax

  v1 = this->pVehicleOccupants.m_pSimComponent;
  return v1 && v1[1].m_pSimObject && !this->pAiDriver.m_pSimComponent;
}

// File Line: 417
// RVA: 0x67EAB0
bool __fastcall UFG::VehicleSubjectComponent::IsCop(UFG::VehicleSubjectComponent *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax
  bool result; // al

  v1 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v1
    && ((v2 = v1->m_Flags, !((v2 >> 14) & 1)) ? ((v2 & 0x8000u) == 0 ? (!((v2 >> 13) & 1) ? (!((v2 >> 12) & 1) ? (v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::CopUnitComponent::_TypeUID)) : (v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::CopUnitComponent::_TypeUID))) : (v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::CopUnitComponent::_TypeUID))) : (v3 = v1->m_Components.p[17].m_pComponent)) : (v3 = v1->m_Components.p[17].m_pComponent),
        v3) )
  {
    result = v3[7].m_Flags & 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 425
// RVA: 0x67E970
bool __fastcall UFG::VehicleSubjectComponent::IsAmbient(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *v1; // rcx

  v1 = this->pAiDriver.m_pSimComponent;
  return v1 && ((unsigned __int8 (*)(void))v1->vfptr[16].__vecDelDtor)();
}

// File Line: 430
// RVA: 0x67E9A0
bool __fastcall UFG::VehicleSubjectComponent::IsAttacking(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *v1; // rax

  v1 = this->pAiDriver.m_pSimComponent;
  return v1 && v1[22].m_TypeUID != 7;
}

// File Line: 435
// RVA: 0x67EB80
bool __fastcall UFG::VehicleSubjectComponent::IsDoingWheelie(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *v1; // rax
  int v2; // ecx
  bool result; // al

  v1 = this->pPhysicsMover.m_pSimComponent;
  result = 0;
  if ( v1 )
  {
    v2 = (int)v1[1].m_pSimObject;
    if ( v2 & 8 )
    {
      if ( !_bittest(&v2, 8u) )
        result = 1;
    }
  }
  return result;
}

// File Line: 440
// RVA: 0x67EB40
UFG::SimComponent *__fastcall UFG::VehicleSubjectComponent::IsDoingBurnout(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *result; // rax

  result = this->pPhysicsMover.m_pSimComponent;
  if ( result )
    result = (UFG::SimComponent *)((LODWORD(result[1].m_pSimObject) >> 5) & 1);
  return result;
}

// File Line: 445
// RVA: 0x67EB60
UFG::SimComponent *__fastcall UFG::VehicleSubjectComponent::IsDoingOneEighty(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *result; // rax

  result = this->pPhysicsMover.m_pSimComponent;
  if ( result )
    result = (UFG::SimComponent *)((LODWORD(result[1].m_pSimObject) >> 4) & 1);
  return result;
}

// File Line: 449
// RVA: 0x15855A0
__int64 UFG::_dynamic_initializer_for__symSeatSync01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("SeatSync01", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symSeatSync01, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symSeatSync01__);
}

// File Line: 450
// RVA: 0x15855E0
__int64 UFG::_dynamic_initializer_for__symSeatSync__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("SeatSync", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symSeatSync, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__symSeatSync__);
}

// File Line: 453
// RVA: 0x694760
void __fastcall UFG::VehicleSubjectComponent::Update(UFG::VehicleSubjectComponent *this, float delta_sec, UFG::SimObjectVehicle *playerVehicle)
{
  UFG::VehicleSubjectComponent *v3; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rsi
  bool v5; // zf
  float v6; // xmm7_4
  UFG::SimObjectCharacter *v7; // rax
  Creature *v8; // rcx
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm4_4
  UFG::SimComponent *v19; // rbx
  UFG::PhysicsVehicle *v20; // rcx
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  UFG::SimComponent *v24; // rbx
  UFG::PhysicsVehicle *v25; // rcx
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  float *v29; // rax
  __int64 v30; // rax
  __m128 v31; // xmm1
  float v32; // xmm6_4
  __int64 v33; // rax
  __m128 v34; // xmm1
  float v35; // xmm2_4
  UFG::CopSystem *v36; // rbx
  signed int v37; // er14
  UFG::RoadNetworkLocation *v38; // rbx
  UFG::SimComponent *v39; // rbp
  UFG::TargetingSimObject *v40; // rbx
  signed __int64 i; // rbp
  bool v42; // cl
  __int64 v43; // rbx
  unsigned int v44; // eax
  float v45; // xmm1_4
  float v46; // xmm0_4
  UFG::qVector4 v47; // xmm3
  UFG::qVector4 v48; // xmm2
  UFG::qVector4 *v49; // rdx
  UFG::qVector4 v50; // xmm0
  UFG::qVector4 v51; // xmm1
  float v52; // xmm10_4
  float v53; // xmm9_4
  float v54; // xmm5_4
  float v55; // xmm11_4
  float v56; // xmm6_4
  float v57; // xmm7_4
  float v58; // xmm8_4
  float v59; // xmm11_4
  float v60; // xmm9_4
  float v61; // xmm6_4
  float v62; // xmm4_4
  float v63; // xmm5_4
  float v64; // xmm10_4
  float v65; // xmm8_4
  float v66; // xmm11_4
  UFG::qVector3 result; // [rsp+20h] [rbp-78h]

  this->vUp.z = 1.0;
  v3 = this;
  v4 = 0i64;
  *(_QWORD *)&this->vUp.x = 0i64;
  v5 = this->m_pSimObject == (UFG::SimObject *)playerVehicle;
  v6 = delta_sec;
  this->pPlayerOccupant = 0i64;
  v7 = 0i64;
  if ( v5 )
    v7 = LocalPlayer;
  this->pPlayerOccupant = (UFG::SimObject *)&v7->vfptr;
  if ( this->pAnimation.m_pSimComponent )
  {
    v8 = *(Creature **)&this->pAnimation.m_pSimComponent[2].m_TypeUID;
    if ( v8 )
    {
      Creature::GetTransform(v8, &v3->mLocalWorld);
      UFG::qInverseAffine(&v3->mWorldLocal, &v3->mLocalWorld);
    }
  }
  v9 = UFG::qVector3::msZero.y;
  v10 = UFG::qVector3::msZero.z;
  v11 = 0.0;
  v3->vVelocity.x = UFG::qVector3::msZero.x;
  v3->vVelocity.y = v9;
  v3->vVelocity.z = v10;
  v12 = UFG::qVector3::msZero.y;
  v13 = UFG::qVector3::msZero.z;
  v3->vAngularVelocity.x = UFG::qVector3::msZero.x;
  v14 = *(float *)&FLOAT_1_0;
  v3->vAngularVelocity.y = v12;
  v15 = *(float *)&FLOAT_1_0;
  v16 = FLOAT_N1_0;
  v3->vAngularVelocity.z = v13;
  v17 = *(float *)&FLOAT_1_0;
  v18 = FLOAT_N1_0;
  if ( v3->pPhysicsMover.m_pSimComponent )
  {
    v19 = v3->pPhysicsMover.m_pSimComponent;
    v20 = (UFG::PhysicsVehicle *)v19[10].m_SafePointerList.mNode.mPrev;
    if ( !v20 || (unsigned __int8)UFG::PhysicsVehicle::IsSuspended(v20) )
    {
      v23 = UFG::qVector3::msZero.x;
      v22 = UFG::qVector3::msZero.y;
      v21 = UFG::qVector3::msZero.z;
    }
    else
    {
      UFG::PhysicsVehicle::GetVelocity((UFG::PhysicsVehicle *)v19[10].m_SafePointerList.mNode.mPrev, &result);
      v21 = result.z;
      v22 = result.y;
      v23 = result.x;
    }
    v24 = v3->pPhysicsMover.m_pSimComponent;
    v3->vVelocity.x = v23;
    v3->vVelocity.y = v22;
    v3->vVelocity.z = v21;
    v25 = (UFG::PhysicsVehicle *)v24[10].m_SafePointerList.mNode.mPrev;
    if ( !v25 || (unsigned __int8)UFG::PhysicsVehicle::IsSuspended(v25) )
    {
      v28 = UFG::qVector3::msZero.x;
      v27 = UFG::qVector3::msZero.y;
      v26 = UFG::qVector3::msZero.z;
    }
    else
    {
      UFG::PhysicsVehicle::GetAngularVelocity((UFG::PhysicsVehicle *)v24[10].m_SafePointerList.mNode.mPrev, &result);
      v26 = result.z;
      v27 = result.y;
      v28 = result.x;
    }
    v29 = (float *)v3->pPhysicsMover.m_pSimComponent;
    v3->vAngularVelocity.x = v28;
    v3->vAngularVelocity.y = v27;
    v3->vAngularVelocity.z = v26;
    v16 = v29[167];
    v18 = v29[168];
    v11 = v29[169];
    v14 = v29[170];
    v17 = v29[171];
    v15 = v29[172];
  }
  v3->mBox.mMin.x = v16;
  v3->mBox.mMin.y = v18;
  v3->mBox.mMin.z = v11;
  v3->mBox.mMax.x = v14;
  v3->mBox.mMax.y = v17;
  v3->mBox.mMax.z = v15;
  v30 = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v3->vfptr[24].__vecDelDtor)(v3);
  v31 = (__m128)*(unsigned int *)(v30 + 4);
  v31.m128_f32[0] = (float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(*(float *)v30 * *(float *)v30);
  LODWORD(v32) = (unsigned __int128)_mm_sqrt_ps(v31);
  v33 = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v3->vfptr[23].__vecDelDtor)(v3);
  v34 = (__m128)*(unsigned int *)(v33 + 4);
  v34.m128_f32[0] = (float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(*(float *)v33 * *(float *)v33);
  LODWORD(v35) = (unsigned __int128)_mm_sqrt_ps(v34);
  if ( v35 <= v32 )
    v35 = v32;
  v3->mRadius = v35;
  v3->bFleeing = 0;
  if ( v3->pPlayerOccupant )
  {
    v36 = UFG::CopSystem::Instance();
    if ( ((unsigned __int8 (__fastcall *)(UFG::CopSystem *))v36->vfptr[6].__vecDelDtor)(v36) )
    {
      if ( ((unsigned int (__fastcall *)(UFG::CopSystem *))v36->vfptr[32].__vecDelDtor)(v36) )
        v3->bFleeing = 1;
    }
  }
  v37 = -1;
  *(_WORD *)&v3->bCanPassLeft = 257;
  if ( v3->pRoadSpace.m_pSimComponent && LOBYTE(v3->pRoadSpace.m_pSimComponent[8].m_Flags) )
  {
    v38 = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&v3->pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext);
    v3->bCanPassRight = UFG::RoadNetworkLocation::CanReachLane(v38, 1);
    v3->bCanPassLeft = UFG::RoadNetworkLocation::CanReachLane(v38, -1);
  }
  v3->pActionHijacker = 0i64;
  if ( v3->pTargetingSystem.m_pSimComponent )
  {
    v39 = v3->pTargetingSystem.m_pSimComponent;
    v40 = (UFG::TargetingSimObject *)v39[1].m_BoundComponentHandles.mNode.mPrev;
    for ( i = (signed __int64)&v39[1].m_pSimObject;
          v40 != (UFG::TargetingSimObject *)i;
          v40 = (UFG::TargetingSimObject *)v40->mNext )
    {
      if ( v40->m_pTarget.m_pPointer && v40->m_bLock && v40->m_eTargetType.mValue == eTARGET_TYPE_VEHICLE_ACTION_HIJACK )
        v3->pActionHijacker = UFG::TargetingSimObject::GetOwner(v40);
    }
  }
  if ( v3->pAnimation.m_pSimComponent )
  {
    v42 = v3->mSeatBone == -2;
    if ( v3->pAnimation.m_Changed )
    {
      v3->pAnimation.m_Changed = 0;
      v42 = 1;
    }
    v43 = *(_QWORD *)&v3->pAnimation.m_pSimComponent[2].m_TypeUID;
    if ( v43 && v42 )
    {
      v44 = *(_QWORD *)(v43 + 440) ? (unsigned int)Skeleton::GetBoneID(*(Skeleton **)(v43 + 480), symSeatSync01.mUID) : -1;
      v3->mSeatBone = v44;
      if ( v44 == -1 )
      {
        if ( *(_QWORD *)(v43 + 440) )
          v37 = Skeleton::GetBoneID(*(Skeleton **)(v43 + 480), symSeatSync.mUID);
        v3->mSeatBone = v37;
      }
    }
  }
  if ( v3->pPhysicsMover.m_pSimComponent )
    v4 = v3->pPhysicsMover.m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
  if ( v4
    && ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *))v4->mPrev[7].mPrev)(v4) )
  {
    if ( !v3->bPinnedOrientation )
      UFG::CameraSubject::PinOrientationSmooth((UFG::CameraSubject *)&v3->vfptr, PinOrientMode_Velocity);
  }
  else if ( v3->bPinnedOrientation )
  {
    v3->bPinnedOrientation = 0;
  }
  UFG::CameraSubject::UpdateBase(
    (UFG::CameraSubject *)&v3->vfptr,
    v6,
    UFG::bCameraDebugDraw,
    &UFG::gCameraSubjectUpdateParams);
  if ( UFG::ChaseCameraComponent::bOffsetTune )
  {
    v45 = UFG::ChaseCameraComponent::rOffsetTuneY;
    result.x = UFG::ChaseCameraComponent::rOffsetTuneX;
    v46 = UFG::ChaseCameraComponent::rOffsetTuneZ;
  }
  else
  {
    v45 = v3->vOriginOffset.y;
    result.x = v3->vOriginOffset.x;
    v46 = v3->vOriginOffset.z;
  }
  v47 = v3->mLocalWorld.v1;
  v48 = v3->mLocalWorld.v2;
  v49 = &v3->mLocalWorldOffset.v0;
  result.z = v46;
  v50 = v3->mLocalWorld.v0;
  result.y = v45;
  v51 = v3->mLocalWorld.v3;
  v52 = result.x;
  v53 = result.y;
  v54 = result.x;
  v55 = result.z;
  *v49 = v50;
  v49[1] = v47;
  v49[2] = v48;
  v49[3] = v51;
  v50.x = v53 * v3->mLocalWorldOffset.v1.x;
  v56 = v55 * v3->mLocalWorldOffset.v2.x;
  v57 = v55 * v3->mLocalWorldOffset.v2.y;
  v51.x = v53 * v3->mLocalWorldOffset.v1.y;
  v48.x = v53 * v3->mLocalWorldOffset.v1.z;
  v58 = v55 * v3->mLocalWorldOffset.v2.z;
  v59 = v55 * v3->mLocalWorldOffset.v2.w;
  v60 = v53 * v3->mLocalWorldOffset.v1.w;
  v61 = (float)(v56 + (float)((float)(v52 * v3->mLocalWorldOffset.v0.x) + v50.x)) + v3->mLocalWorldOffset.v3.x;
  v62 = v52 * v3->mLocalWorldOffset.v0.y;
  v63 = v54 * v3->mLocalWorldOffset.v0.z;
  v64 = v52 * v3->mLocalWorldOffset.v0.w;
  v3->mLocalWorldOffset.v3.x = v61;
  v65 = (float)(v58 + (float)(v63 + v48.x)) + v3->mLocalWorldOffset.v3.z;
  v66 = (float)(v59 + (float)(v64 + v60)) + v3->mLocalWorldOffset.v3.w;
  v3->mLocalWorldOffset.v3.y = (float)(v57 + (float)(v62 + v51.x)) + v3->mLocalWorldOffset.v3.y;
  v3->mLocalWorldOffset.v3.z = v65;
  v3->mLocalWorldOffset.v3.w = v66;
  v51.x = v3->mLocalWorld.v3.y;
  v48.x = v3->mLocalWorld.v3.z;
  v3->mPositionOffset.x = v3->mLocalWorld.v3.x;
  v3->mPositionOffset.y = v51.x;
  v3->mPositionOffset.z = v48.x;
  UFG::qInverseAffine(&v3->mWorldLocalOffset, &v3->mLocalWorldOffset);
}

// File Line: 665
// RVA: 0x694EB0
void __fastcall UFG::VehicleSubjectComponent::UpdateAll(float delta_sec)
{
  UFG::SimObjectVehicle *v1; // rsi
  unsigned __int16 v2; // dx
  UFG::CharacterOccupantComponent *v3; // rax
  UFG::VehicleSubjectComponent *v4; // rcx
  UFG::qList<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent,1,0> *v5; // rbx

  v1 = 0i64;
  if ( LocalPlayer )
  {
    v2 = LocalPlayer->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
        v3 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      else
        v3 = (UFG::CharacterOccupantComponent *)((v2 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                                    UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
    }
    else
    {
      v3 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                UFG::CharacterOccupantComponent::_TypeUID);
    }
    if ( v3 )
      v1 = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v3);
  }
  v4 = (UFG::VehicleSubjectComponent *)&UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList.mNode.mNext[-18];
  if ( (UFG::qList<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent,1,0> *)&UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList.mNode.mNext[-18] != &UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList - 18 )
  {
    do
    {
      v5 = (UFG::qList<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent,1,0> *)&v4->mNext[-18];
      UFG::VehicleSubjectComponent::Update(v4, delta_sec, v1);
      v4 = (UFG::VehicleSubjectComponent *)v5;
    }
    while ( v5 != &UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList - 18 );
  }
}

// File Line: 752
// RVA: 0x67A800
float __fastcall UFG::VehicleSubjectComponent::GetMass(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *v1; // rcx

  v1 = this->pPhysicsMover.m_pSimComponent;
  if ( v1 )
    JUMPOUT(v1[10].m_SafePointerList.mNode.mPrev, 0i64, UFG::PhysicsVehicle::GetMass);
  return 0.0;
}

// File Line: 765
// RVA: 0x67B230
float __fastcall UFG::VehicleSubjectComponent::GetSpeed(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *v1; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  __m128 v4; // xmm2
  float result; // xmm0_4

  v1 = this->pPhysicsMover.m_pSimComponent;
  if ( !v1 )
    return 0.0;
  v2 = v1[10].m_SafePointerList.mNode.mPrev;
  if ( !v2 )
    return *((float *)&v1[10].m_BoundComponentHandles.mNode.mPrev + 1);
  v3 = v2[6].mPrev[10].mNext;
  if ( !v3 )
    return *((float *)&v1[10].m_BoundComponentHandles.mNode.mPrev + 1);
  v4 = (__m128)LODWORD(v3[35].mPrev);
  v4.m128_f32[0] = (float)((float)(v4.m128_f32[0] * v4.m128_f32[0])
                         + (float)(*((float *)&v3[35].mPrev + 1) * *((float *)&v3[35].mPrev + 1)))
                 + (float)(*(float *)&v3[35].mNext * *(float *)&v3[35].mNext);
  LODWORD(result) = (unsigned __int128)_mm_sqrt_ps(v4);
  return result;
}

// File Line: 770
// RVA: 0x67A6A0
float __fastcall UFG::VehicleSubjectComponent::GetForwardSpeed(UFG::VehicleSubjectComponent *this)
{
  UFG::PhysicsMoverInterface *v1; // rax
  float result; // xmm0_4

  v1 = (UFG::PhysicsMoverInterface *)this->pPhysicsMover.m_pSimComponent;
  if ( v1 )
    result = v1->mForwardSpeed;
  else
    result = 0.0;
  return result;
}

// File Line: 785
// RVA: 0x67E9C0
bool __fastcall UFG::VehicleSubjectComponent::IsBike(UFG::VehicleSubjectComponent *this)
{
  UFG::PhysicsMoverInterface *v1; // rax

  v1 = (UFG::PhysicsMoverInterface *)this->pPhysicsMover.m_pSimComponent;
  return v1 && v1->mNumWheels == 2;
}

// File Line: 790
// RVA: 0x67E9E0
bool __fastcall UFG::VehicleSubjectComponent::IsBoat(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *v1; // rax

  v1 = this->pPhysicsMover.m_pSimComponent;
  return v1 && !LODWORD(v1[12].m_BoundComponentHandles.mNode.mNext);
}

// File Line: 795
// RVA: 0x679720
signed __int64 __fastcall UFG::VehicleSubjectComponent::GetBoxSide(UFG::VehicleSubjectComponent *this, UFG::qVector3 *position)
{
  UFG::qVector3 *v2; // rdi
  UFG::VehicleSubjectComponent *v3; // rsi
  float *v4; // rbx
  float *v5; // rax
  float v6; // xmm9_4
  float v7; // xmm10_4
  float v8; // xmm6_4
  float v9; // xmm11_4
  float v10; // xmm8_4
  float v11; // xmm7_4
  float *v12; // rax
  float v13; // xmm13_4
  float v14; // xmm9_4
  float v15; // xmm5_4
  float v16; // xmm0_4
  signed __int64 result; // rax
  float v18; // [rsp+28h] [rbp-130h]
  UFG::qVector3 verts; // [rsp+40h] [rbp-118h]
  float v20; // [rsp+4Ch] [rbp-10Ch]
  float v21; // [rsp+50h] [rbp-108h]
  float v22; // [rsp+54h] [rbp-104h]
  float v23; // [rsp+64h] [rbp-F4h]
  float v24; // [rsp+68h] [rbp-F0h]
  float v25; // [rsp+6Ch] [rbp-ECh]
  float v26; // [rsp+70h] [rbp-E8h]
  float v27; // [rsp+74h] [rbp-E4h]
  float v28; // [rsp+78h] [rbp-E0h]
  float v29; // [rsp+7Ch] [rbp-DCh]
  float v30; // [rsp+80h] [rbp-D8h]
  float v31; // [rsp+84h] [rbp-D4h]
  float v32; // [rsp+88h] [rbp-D0h]
  float v33; // [rsp+8Ch] [rbp-CCh]
  float v34; // [rsp+90h] [rbp-C8h]
  float v35; // [rsp+94h] [rbp-C4h]
  float v36; // [rsp+98h] [rbp-C0h]
  float v37; // [rsp+9Ch] [rbp-BCh]
  float v38; // [rsp+168h] [rbp+10h]
  float v39; // [rsp+178h] [rbp+20h]

  v2 = position;
  v3 = this;
  UFG::CameraSubject::GetBoxVerts((UFG::CameraSubject *)&this->vfptr, &verts, 0.0);
  v4 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v3->vfptr[24].__vecDelDtor)(v3);
  v5 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v3->vfptr[23].__vecDelDtor)(v3);
  v6 = (float)(v4[1] + v5[1]) * 0.5;
  v7 = (float)(v4[2] + v5[2]) * 0.5;
  v8 = v2->x;
  v9 = v2->y;
  v10 = (float)(*v5 + *v4) * 0.5;
  v11 = v2->z;
  v12 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v3->vfptr[19].__vecDelDtor)(v3);
  v39 = (float)((float)((float)((float)(v9 * v12[4]) + (float)(v8 * *v12)) + (float)(v11 * v12[8])) + v12[12]) - v10;
  v38 = (float)((float)((float)((float)(v9 * v12[5]) + (float)(v8 * v12[1])) + (float)(v11 * v12[9])) + v12[13]) - v6;
  v18 = (float)((float)((float)((float)(v9 * v12[6]) + (float)(v8 * v12[2])) + (float)(v11 * v12[10])) + v12[14]) - v7;
  v13 = (float)((float)((float)((float)(v22 * v29) - (float)(v20 * v31)) * v38)
              + (float)((float)((float)(v21 * v31) - (float)(v22 * v30)) * v39))
      + (float)((float)((float)(v20 * v30) - (float)(v21 * v29)) * v18);
  v14 = (float)((float)((float)((float)(v35 * v31) - (float)(v37 * v29)) * v38)
              + (float)((float)((float)(v37 * v30) - (float)(v36 * v31)) * v39))
      + (float)((float)((float)(v36 * v29) - (float)(v35 * v30)) * v18);
  v15 = (float)((float)((float)((float)(v20 * v25) - (float)(v22 * v23)) * v38)
              + (float)((float)((float)(v22 * v24) - (float)(v21 * v25)) * v39))
      + (float)((float)((float)(v21 * v23) - (float)(v20 * v24)) * v18);
  v16 = (float)((float)((float)((float)(v25 * v35) - (float)(v23 * v37)) * v38)
              + (float)((float)((float)(v24 * v37) - (float)(v25 * v36)) * v39))
      + (float)((float)((float)(v23 * v36) - (float)(v24 * v35)) * v18);
  if ( (float)((float)((float)((float)((float)(v26 * v31) - (float)(v29 * v28)) * v38)
                     + (float)((float)((float)(v30 * v28) - (float)(v31 * v27)) * v39))
             + (float)((float)((float)(v29 * v27) - (float)(v26 * v30)) * v18)) >= 0.0 )
  {
    if ( (float)((float)((float)((float)((float)(v35 * v34) - (float)(v32 * v37)) * v38)
                       + (float)((float)((float)(v37 * v33) - (float)(v36 * v34)) * v39))
               + (float)((float)((float)(v32 * v36) - (float)(v35 * v33)) * v18)) < 0.0 )
    {
      if ( v16 < 0.0 )
      {
LABEL_10:
        if ( v13 >= 0.0 && v14 >= 0.0 && v15 >= 0.0 )
          return 2i64;
        goto LABEL_14;
      }
      if ( v13 >= 0.0 )
        return 1i64;
    }
    else if ( v14 < 0.0 && v15 >= 0.0 )
    {
      return 0i64;
    }
  }
  if ( v16 < 0.0 )
    goto LABEL_10;
LABEL_14:
  if ( (float)((float)((float)((float)((float)(v26 * v31) - (float)(v29 * v28)) * v38)
                     + (float)((float)((float)(v30 * v28) - (float)(v31 * v27)) * v39))
             + (float)((float)((float)(v29 * v27) - (float)(v26 * v30)) * v18)) >= 0.0 )
    return 5i64;
  if ( (float)((float)((float)((float)((float)(v35 * v34) - (float)(v32 * v37)) * v38)
                     + (float)((float)((float)(v37 * v33) - (float)(v36 * v34)) * v39))
             + (float)((float)((float)(v32 * v36) - (float)(v35 * v33)) * v18)) < 0.0 )
  {
    if ( v14 >= 0.0 && v15 < 0.0 )
      return 3i64;
    return 5i64;
  }
  if ( v16 >= 0.0 )
    return 5i64;
  result = 4i64;
  if ( v13 >= 0.0 )
    return 5i64;
  return result;
}

// File Line: 831
// RVA: 0x67B350
UFG::SimComponent *__fastcall UFG::VehicleSubjectComponent::GetTargetingSystem(UFG::VehicleSubjectComponent *this)
{
  UFG::VehicleSubjectComponent *v1; // rax
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  unsigned int v5; // edx
  bool v6; // zf

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->pPlayerOccupant;
  if ( !v2 )
    return v1->pTargetingSystem.m_pSimComponent;
  v3 = v2->m_Flags;
  if ( (v3 >> 14) & 1 || (v3 & 0x8000u) != 0 )
    return v2->m_Components.p[20].m_pComponent;
  if ( (v3 >> 13) & 1 )
  {
    v5 = UFG::TargetingSystemBaseComponent::_TypeUID;
    return UFG::SimObjectGame::GetComponentOfTypeHK(v2, v5);
  }
  v6 = ((v3 >> 12) & 1) == 0;
  v5 = UFG::TargetingSystemBaseComponent::_TypeUID;
  if ( !v6 )
    return UFG::SimObjectGame::GetComponentOfTypeHK(v2, v5);
  return UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
}

// File Line: 837
// RVA: 0x67B3C0
UFG::SimComponent *__fastcall UFG::VehicleSubjectComponent::GetTargetingSystemVehicle(UFG::VehicleSubjectComponent *this)
{
  return this->pTargetingSystem.m_pSimComponent;
}

