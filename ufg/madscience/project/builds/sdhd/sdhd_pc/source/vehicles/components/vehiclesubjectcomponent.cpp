// File Line: 31
// RVA: 0x157B910
__int64 dynamic_initializer_for__UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList__);
}

// File Line: 32
// RVA: 0x67A430
UFG::ComponentIDDesc *__fastcall UFG::VehicleSubjectComponent::GetDesc(UFG::VehicleSubjectComponent *this)
{
  return &UFG::VehicleSubjectComponent::_TypeIDesc;
}

// File Line: 36
// RVA: 0x66B920
void __fastcall UFG::VehicleSubjectComponent::VehicleSubjectComponent(
        UFG::VehicleSubjectComponent *this,
        unsigned int name_uid)
{
  UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *mPrev; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::qVector4 v14; // xmm1
  UFG::qVector4 v15; // xmm2
  UFG::qVector4 v16; // xmm3
  UFG::qVector4 v17; // xmm1
  UFG::qVector4 v18; // xmm2
  UFG::qVector4 v19; // xmm3
  UFG::ChaseCameraParameters *v20; // rax
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *result; // [rsp+50h] [rbp+18h] BYREF

  UFG::CameraSubject::CameraSubject(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent>;
  this->mNext = &this->UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleSubjectComponent::`vftable;
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0>::RebindingComponentHandle<UFG::AiDriverComponent,0>(&this->pAiDriver);
  UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0>::RebindingComponentHandle<UFG::RoadSpaceComponent,0>(&this->pRoadSpace);
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>(&this->pPhysicsMover);
  UFG::RebindingComponentHandle<UFG::VehicleOccupantComponent,0>::RebindingComponentHandle<UFG::VehicleOccupantComponent,0>(&this->pVehicleOccupants);
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>(&this->pAnimation);
  UFG::RebindingComponentHandle<UFG::TargetingSystemVehicleComponent,0>::RebindingComponentHandle<UFG::TargetingSystemVehicleComponent,0>(&this->pTargetingSystem);
  *(_QWORD *)&this->mBox.mMin.x = 0i64;
  *(_QWORD *)&this->mBox.mMin.z = 0i64;
  *(_QWORD *)&this->mBox.mMax.y = 0i64;
  result = &this->mChaserList;
  this->mChaserList.mNode.mPrev = &this->mChaserList.mNode;
  this->mChaserList.mNode.mNext = &this->mChaserList.mNode;
  this->mFollowOverrideContext.mUID = -1;
  mPrev = UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList.mNode.mPrev;
  UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *)&UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList;
  UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList.mNode.mPrev = &this->UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::VehicleSubjectComponent::_VehicleSubjectComponentTypeUID,
    "VehicleSubjectComponent");
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->vAngularVelocity.x = UFG::qVector3::msZero.x;
  this->vAngularVelocity.y = y;
  this->vAngularVelocity.z = z;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  this->vVelocity.x = UFG::qVector3::msZero.x;
  this->vVelocity.y = v6;
  this->vVelocity.z = v7;
  v8 = UFG::qVector3::msUnity.y;
  v9 = UFG::qVector3::msUnity.z;
  this->vUp.x = UFG::qVector3::msUnity.x;
  this->vUp.y = v8;
  this->vUp.z = v9;
  v10 = UFG::qVector3::msZero.y;
  v11 = UFG::qVector3::msZero.z;
  this->vOriginOffset.x = UFG::qVector3::msZero.x;
  this->vOriginOffset.y = v10;
  this->vOriginOffset.z = v11;
  *(_QWORD *)&this->rAimLookOffsetLowZ = 0i64;
  this->rAimDistFromSide = 1.8;
  *(_QWORD *)&this->rAimDistFromBumper = 1053609165i64;
  this->rAimOriginOffsetConstX = 0.0;
  v12 = UFG::qVector3::msZero.y;
  v13 = UFG::qVector3::msZero.z;
  this->mPositionOffset.x = UFG::qVector3::msZero.x;
  this->mPositionOffset.y = v12;
  this->mPositionOffset.z = v13;
  v14 = UFG::qMatrix44::msIdentity.v1;
  v15 = UFG::qMatrix44::msIdentity.v2;
  v16 = UFG::qMatrix44::msIdentity.v3;
  this->mLocalWorldOffset.v0 = UFG::qMatrix44::msIdentity.v0;
  this->mLocalWorldOffset.v1 = v14;
  this->mLocalWorldOffset.v2 = v15;
  this->mLocalWorldOffset.v3 = v16;
  v17 = UFG::qMatrix44::msIdentity.v1;
  v18 = UFG::qMatrix44::msIdentity.v2;
  v19 = UFG::qMatrix44::msIdentity.v3;
  this->mWorldLocalOffset.v0 = UFG::qMatrix44::msIdentity.v0;
  this->mWorldLocalOffset.v1 = v17;
  this->mWorldLocalOffset.v2 = v18;
  this->mWorldLocalOffset.v3 = v19;
  *(_WORD *)&this->bFleeing = 256;
  this->bCanPassRight = 1;
  this->mRadius = 0.0;
  v17.x = UFG::qVector3::msZero.y;
  v18.x = UFG::qVector3::msZero.z;
  this->mBox.mMin.x = UFG::qVector3::msZero.x;
  this->mBox.mMin.y = v17.x;
  this->mBox.mMin.z = v18.x;
  v17.x = UFG::qVector3::msZero.y;
  v18.x = UFG::qVector3::msZero.z;
  this->mBox.mMax.x = UFG::qVector3::msZero.x;
  this->mBox.mMax.y = v17.x;
  this->mBox.mMax.z = v18.x;
  this->mSeatBone = -2;
  this->pActionHijacker = 0i64;
  this->pPlayerOccupant = 0i64;
  this->mFollowOverrideContext.mUID = UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&result, 0xFFFFFFFF)->mUID;
  v20 = UFG::DefaultChaseParameters();
  this->pChaseParametersAim = v20;
  this->pChaseParametersFlee = v20;
  this->pChaseParametersRace = v20;
  this->pChaseParametersDrive = v20;
  this->pChaseParametersBurnout = v20;
  this->pChaseParametersLookUp = v20;
  this->pChaseParametersLookBack = v20;
  this->pChaseParametersLookSide = v20;
  this->pChaseParametersPassenger = v20;
  this->pChaseParametersHijackBack = v20;
  this->pChaseParametersHijackSide = v20;
  this->pChaseParametersHijackFront = v20;
  this->pChaseParametersHijackTop = v20;
}

// File Line: 86
// RVA: 0x66D7A0
void __fastcall UFG::VehicleSubjectComponent::~VehicleSubjectComponent(UFG::VehicleSubjectComponent *this)
{
  UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *v2; // rdi
  UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *mPrev; // rcx
  UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *mNext; // rax
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v5; // rcx
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v6; // rax
  UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *v7; // rcx
  UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent> *v8; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleSubjectComponent::`vftable;
  if ( this == UFG::VehicleSubjectComponent::s_VehicleSubjectComponentpCurrentIterator )
    UFG::VehicleSubjectComponent::s_VehicleSubjectComponentpCurrentIterator = (UFG::VehicleSubjectComponent *)&this->mPrev[-18];
  v2 = &this->UFG::qNode<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mChaserList);
  UFG::VehicleSubjectComponent::HandleChaserListChange(this);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->mChaserList);
  v5 = this->mChaserList.mNode.mPrev;
  v6 = this->mChaserList.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mChaserList.mNode.mPrev = &this->mChaserList.mNode;
  this->mChaserList.mNode.mNext = &this->mChaserList.mNode;
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->pTargetingSystem);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->pAnimation);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->pVehicleOccupants);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->pPhysicsMover);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->pRoadSpace);
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->pAiDriver);
  v7 = v2->mPrev;
  v8 = v2->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::CameraSubject::~CameraSubject(this);
}

// File Line: 98
// RVA: 0x67D0D0
bool __fastcall UFG::VehicleSubjectComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentVehicleSubject);
}

// File Line: 104
// RVA: 0x687D80
UFG::VehicleSubjectComponent *__fastcall UFG::VehicleSubjectComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *scene_object_properties)
{
  unsigned int m_NameUID; // edi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::SimComponent *v5; // rax
  UFG::SimComponent *v6; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v9; // ebx
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h] BYREF

  m_NameUID = scene_object_properties->m_NameUID;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v4 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x3D8ui64, "VehicleSubjectComponent", 0i64, 1u);
  if ( v4 )
  {
    UFG::VehicleSubjectComponent::VehicleSubjectComponent((UFG::VehicleSubjectComponent *)v4, m_NameUID);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  m_pSimObject = scene_object_properties->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags >= 0 )
    v9 = -1;
  else
    v9 = 31;
  UFG::SimObjectModifier::SimObjectModifier(&v11, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, v6, v9);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return (UFG::VehicleSubjectComponent *)v6;
}

// File Line: 112
// RVA: 0x68D200
void __fastcall UFG::VehicleSubjectComponent::TeleportEventHandler(
        UFG::VehicleSubjectComponent *this,
        UFG::Event *event)
{
  UFG::SimObject *m_pSimObject; // rdi
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::ChaseCameraComponent *v5; // rbx

  m_pSimObject = this->m_pSimObject;
  v3 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v3 )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(v3, UFG::ChaseCameraComponent::_TypeUID);
    v5 = (UFG::ChaseCameraComponent *)ComponentOfType;
    if ( ComponentOfType )
    {
      if ( m_pSimObject == (UFG::SimObject *)((__int64 (__fastcall *)(UFG::SimComponent *))ComponentOfType->vfptr[17].__vecDelDtor)(ComponentOfType) )
      {
        ((void (__fastcall *)(UFG::ChaseCameraComponent *))v5->vfptr[14].__vecDelDtor)(v5);
        v5->vfptr[16].__vecDelDtor(v5, (unsigned int)m_pSimObject);
        UFG::ChaseCameraComponent::LockEye(v5, 0);
        ((void (__fastcall *)(UFG::ChaseCameraComponent *))v5->vfptr[15].__vecDelDtor)(v5);
        ((void (__fastcall *)(UFG::ChaseCameraComponent *))v5->vfptr[31].__vecDelDtor)(v5);
      }
    }
  }
}

// File Line: 127
// RVA: 0x66F370
void __fastcall UFG::VehicleSubjectComponent::AddChaser(
        UFG::VehicleSubjectComponent *this,
        UFG::allocator::free_link *chaser)
{
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *mNext; // rax
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *p_mChaserList; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rcx
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *mPrev; // rax

  mNext = this->mChaserList.mNode.mNext;
  p_mChaserList = &this->mChaserList;
  if ( mNext == (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)&this->mChaserList )
  {
LABEL_4:
    v6 = UFG::qMalloc(0x18ui64, "VehicleEffectsComponent.SimObjectPointer", 0i64);
    v7 = v6;
    if ( v6 )
    {
      v6->mNext = v6;
      v6[1].mNext = v6;
      v6[2].mNext = chaser;
    }
    else
    {
      v7 = 0i64;
    }
    mPrev = p_mChaserList->mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)v7;
    v7->mNext = (UFG::allocator::free_link *)mPrev;
    v7[1].mNext = (UFG::allocator::free_link *)p_mChaserList;
    p_mChaserList->mNode.mPrev = (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)v7;
  }
  else
  {
    while ( chaser != (UFG::allocator::free_link *)mNext[1].mPrev )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)p_mChaserList )
        goto LABEL_4;
    }
  }
  UFG::VehicleSubjectComponent::HandleChaserListChange(this);
}

// File Line: 134
// RVA: 0x689660
void __fastcall UFG::VehicleSubjectComponent::RemoveChaser(UFG::VehicleSubjectComponent *this, UFG::SimObject *chaser)
{
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *mNext; // rcx
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *mPrev; // rdx
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v5; // rax
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v6; // rdx
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *v7; // rax
  UFG::SimComponent *m_pSimComponent; // rdx

  mNext = this->mChaserList.mNode.mNext;
  if ( mNext != (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)&this->mChaserList )
  {
    while ( chaser != (UFG::SimObject *)mNext[1].mPrev )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)&this->mChaserList )
        goto LABEL_6;
    }
    mPrev = mNext->mPrev;
    v5 = mNext->mNext;
    mPrev->mNext = v5;
    v5->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    v6 = mNext->mPrev;
    v7 = mNext->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    operator delete[](mNext);
  }
LABEL_6:
  if ( (UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *)this->mChaserList.mNode.mNext == &this->mChaserList )
  {
    m_pSimComponent = this->pRoadSpace.m_pSimComponent;
    if ( m_pSimComponent )
    {
      if ( (m_pSimComponent[30].m_TypeUID & 1) != 0 )
        UFG::Simulation::DestroySimComponent(&UFG::gSim, m_pSimComponent);
    }
  }
  UFG::VehicleSubjectComponent::HandleChaserListChange(this);
}

// File Line: 150
// RVA: 0x67BB30
void __fastcall UFG::VehicleSubjectComponent::HandleChaserListChange(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rbx
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *p_mChaserList; // rsi
  UFG::allocator::free_link *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax

  if ( this->pRoadSpace.m_pSimComponent )
  {
    m_pSimComponent = this->pRoadSpace.m_pSimComponent;
    mPrev = m_pSimComponent[26].m_BoundComponentHandles.mNode.mPrev;
    p_mChaserList = &this->mChaserList;
    if ( (UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *)this->mChaserList.mNode.mNext == &this->mChaserList )
    {
      if ( mPrev )
      {
        UFG::VehicleFormations::~VehicleFormations((UFG::VehicleFormations *)m_pSimComponent[26].m_BoundComponentHandles.mNode.mPrev);
        operator delete[](mPrev);
        this->pRoadSpace.m_pSimComponent[26].m_BoundComponentHandles.mNode.mPrev = 0i64;
      }
    }
    else
    {
      if ( !mPrev )
      {
        v5 = UFG::qMalloc(0x268ui64, "VehicleEffectsComponent.VehicleFormations", 0i64);
        if ( v5 )
        {
          UFG::VehicleFormations::VehicleFormations((UFG::VehicleFormations *)v5, this, p_mChaserList);
          mPrev = v6;
        }
        else
        {
          mPrev = 0i64;
        }
        this->pRoadSpace.m_pSimComponent[26].m_BoundComponentHandles.mNode.mPrev = mPrev;
      }
      BYTE6(mPrev[38].mPrev) = 1;
    }
  }
}

// File Line: 183
// RVA: 0x67F330
bool __fastcall UFG::VehicleSubjectComponent::IsInReverse(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax

  m_pSimComponent = this->pPhysicsMover.m_pSimComponent;
  return m_pSimComponent && ((__int64)m_pSimComponent[1].m_pSimObject & 1) != 0;
}

// File Line: 189
// RVA: 0x67ED90
bool __fastcall UFG::VehicleSubjectComponent::IsGas(UFG::VehicleSubjectComponent *this)
{
  UFG::PhysicsMoverInterface *m_pSimComponent; // rax

  m_pSimComponent = (UFG::PhysicsMoverInterface *)this->pPhysicsMover.m_pSimComponent;
  return m_pSimComponent && m_pSimComponent->mInput.mRawGasBrakes < -0.2;
}

// File Line: 195
// RVA: 0x67F220
bool __fastcall UFG::VehicleSubjectComponent::IsInAir(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rcx

  m_pSimComponent = this->pPhysicsMover.m_pSimComponent;
  if ( m_pSimComponent )
    m_pSimComponent = (UFG::SimComponent *)m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
  if ( m_pSimComponent )
    return ((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[14].__vecDelDtor)(m_pSimComponent);
  else
    return 0;
}

// File Line: 222
// RVA: 0x681F10
__int64 __fastcall UFG::VehicleSubjectComponent::NumChasersCloserThan(
        UFG::VehicleSubjectComponent *this,
        float distance)
{
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *mNext; // rbx
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *p_mChaserList; // rbp
  unsigned int i; // edi
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *mPrev; // rax
  float *v7; // rsi
  float *v8; // rax

  mNext = this->mChaserList.mNode.mNext;
  p_mChaserList = &this->mChaserList;
  for ( i = 0; mNext != (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)p_mChaserList; mNext = mNext->mNext )
  {
    mPrev = mNext[1].mPrev;
    if ( mPrev )
    {
      v7 = (float *)mPrev[5].mNext;
      if ( v7 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)mPrev[5].mNext);
        v8 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))this->vfptr[17].__vecDelDtor)(this);
        if ( (float)((float)((float)((float)(v8[1] - v7[45]) * (float)(v8[1] - v7[45]))
                           + (float)((float)(*v8 - v7[44]) * (float)(*v8 - v7[44])))
                   + (float)((float)(v8[2] - v7[46]) * (float)(v8[2] - v7[46]))) < (float)(distance * distance) )
          ++i;
      }
    }
  }
  return i;
}

// File Line: 240
// RVA: 0x689220
void __fastcall UFG::VehicleSubjectComponent::ReassignChasersTo(
        UFG::VehicleSubjectComponent *this,
        UFG::SimObjectVehicle *new_target)
{
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *mNext; // rbx
  UFG::qList<UFG::SimObjectPointer,UFG::SimObjectPointer,1,0> *p_mChaserList; // rdi
  UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *i; // rax
  UFG::SimObjectCVBase *mPrev; // rcx
  __int16 m_Flags; // dx
  UFG::AiDriverComponent *ComponentOfTypeHK; // rax

  mNext = this->mChaserList.mNode.mNext;
  p_mChaserList = &this->mChaserList;
  for ( i = mNext; mNext != (UFG::qNode<UFG::SimObjectPointer,UFG::SimObjectPointer> *)p_mChaserList; i = mNext )
  {
    mPrev = (UFG::SimObjectCVBase *)i[1].mPrev;
    mNext = mNext->mNext;
    if ( mPrev )
    {
      m_Flags = mPrev->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(mPrev);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        mPrev,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::AiDriverComponent *)UFG::SimObject::GetComponentOfType(
                                                        mPrev,
                                                        UFG::AiDriverComponent::_TypeUID);
      }
      if ( ComponentOfTypeHK )
        UFG::AiDriverComponent::SetChaseTarget(ComponentOfTypeHK, new_target);
    }
  }
}

// File Line: 251
// RVA: 0x1582AC0
__int64 UFG::_dynamic_initializer_for__default_chase_parameter_set__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Cameras-ChaseCameraCommon", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::default_chase_parameter_set, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__default_chase_parameter_set__);
}

// File Line: 254
// RVA: 0x683B10
void __fastcall UFG::VehicleSubjectComponent::OnAttach(
        UFG::VehicleSubjectComponent *this,
        UFG::SimObjectVehicle *object)
{
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *p_pAiDriver; // rcx
  UFG::qSymbol *MemImagePtr; // rdi
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_pAnimation; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v12; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemVehicleComponent,0> *p_pTargetingSystem; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v17; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SceneObjectProperties *m_pSceneObj; // rsi
  UFG::qPropertySet *v22; // rax
  UFG::qStaticSymbol *v23; // r14
  UFG::qVector3 *v24; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  float *v27; // rax
  float *v28; // rax
  float *v29; // rax
  float *v30; // rax
  float *v31; // rax
  float *v32; // rax
  UFG::qPropertySet *PropertySet; // rsi
  UFG::qSymbol _override; // [rsp+50h] [rbp+8h] BYREF
  UFG::qSymbol *p_override; // [rsp+58h] [rbp+10h]

  UFG::CameraSubject::OnAttach(this, object);
  p_pAiDriver = &this->pAiDriver;
  MemImagePtr = 0i64;
  if ( this->pAiDriver.m_pSimComponent )
  {
    mPrev = p_pAiDriver->mPrev;
    mNext = this->pAiDriver.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->pAiDriver.m_pSimComponent = 0i64;
LABEL_7:
    this->pAiDriver.m_pSimObject = 0i64;
    this->pAiDriver.mNext = &this->pAiDriver;
    p_pAiDriver->mPrev = p_pAiDriver;
    goto LABEL_8;
  }
  if ( this->pAiDriver.m_pSimObject && (p_pAiDriver->mPrev != p_pAiDriver || this->pAiDriver.mNext != &this->pAiDriver) )
  {
    v8 = p_pAiDriver->mPrev;
    v9 = this->pAiDriver.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    goto LABEL_7;
  }
LABEL_8:
  this->pAiDriver.m_Changed = 1;
  this->pAiDriver.m_pSimObject = object;
  this->pAiDriver.m_TypeUID = UFG::AiDriverComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0>::BindInternal<UFG::SimObjectVehicle>(p_pAiDriver, object);
  UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0>::Bind<UFG::SimObjectVehicle>(&this->pRoadSpace, object);
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0>::Bind<UFG::SimObjectVehicle>(&this->pPhysicsMover, object);
  p_pAnimation = &this->pAnimation;
  if ( this->pAnimation.m_pSimComponent )
  {
    v11 = p_pAnimation->mPrev;
    v12 = this->pAnimation.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    this->pAnimation.m_pSimComponent = 0i64;
LABEL_14:
    this->pAnimation.m_pSimObject = 0i64;
    this->pAnimation.mNext = &this->pAnimation;
    p_pAnimation->mPrev = p_pAnimation;
    goto LABEL_15;
  }
  if ( this->pAnimation.m_pSimObject
    && (p_pAnimation->mPrev != p_pAnimation || this->pAnimation.mNext != &this->pAnimation) )
  {
    v13 = p_pAnimation->mPrev;
    v14 = this->pAnimation.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    goto LABEL_14;
  }
LABEL_15:
  this->pAnimation.m_Changed = 1;
  this->pAnimation.m_pSimObject = object;
  this->pAnimation.m_TypeUID = UFG::CharacterAnimationComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0>::BindInternal<UFG::SimObjectVehicle>(
    &this->pAnimation,
    (UFG::SimObjectCharacter *)object);
  p_pTargetingSystem = &this->pTargetingSystem;
  if ( this->pTargetingSystem.m_pSimComponent )
  {
    v16 = p_pTargetingSystem->mPrev;
    v17 = this->pTargetingSystem.mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    this->pTargetingSystem.m_pSimComponent = 0i64;
LABEL_21:
    this->pTargetingSystem.m_pSimObject = 0i64;
    this->pTargetingSystem.mNext = &this->pTargetingSystem;
    p_pTargetingSystem->mPrev = p_pTargetingSystem;
    goto LABEL_22;
  }
  if ( this->pTargetingSystem.m_pSimObject
    && (p_pTargetingSystem->mPrev != p_pTargetingSystem || this->pTargetingSystem.mNext != &this->pTargetingSystem) )
  {
    v18 = p_pTargetingSystem->mPrev;
    v19 = this->pTargetingSystem.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    goto LABEL_21;
  }
LABEL_22:
  this->pTargetingSystem.m_Changed = 1;
  this->pTargetingSystem.m_pSimObject = object;
  this->pTargetingSystem.m_TypeUID = UFG::TargetingSystemVehicleComponent::_TypeUID;
  UFG::RebindingComponentHandle<UFG::TargetingSystemVehicleComponent,0>::BindInternal<UFG::SimObjectVehicle>(
    &this->pTargetingSystem,
    object);
  UFG::RebindingComponentHandle<UFG::VehicleOccupantComponent,0>::Bind<UFG::SimObjectVehicle>(
    &this->pVehicleOccupants,
    object);
  if ( this->pPhysicsMover.m_pSimComponent )
  {
    m_pSimObject = this->pPhysicsMover.m_pSimComponent->m_pSimObject;
    m_pSceneObj = m_pSimObject->m_pSceneObj;
    if ( m_pSceneObj )
    {
      v22 = PropertyUtils::Get<UFG::qSymbol>(
              m_pSimObject->m_pSceneObj,
              (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_ChaseCameraParameters);
      v23 = &UFG::default_chase_parameter_set;
      if ( v22 )
        v23 = (UFG::qStaticSymbol *)v22;
      v24 = PropertyUtils::Get<UFG::qVector3>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_OriginOffset);
      if ( v24 )
      {
        y = v24->y;
        z = v24->z;
        this->vOriginOffset.x = v24->x;
        this->vOriginOffset.y = y;
        this->vOriginOffset.z = z;
      }
      v27 = PropertyUtils::Get<float>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_AimLookOffsetLowZ);
      if ( v27 )
        this->rAimLookOffsetLowZ = *v27;
      v28 = PropertyUtils::Get<float>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_AimLookOffsetHighZ);
      if ( v28 )
        this->rAimLookOffsetHighZ = *v28;
      v29 = PropertyUtils::Get<float>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_AimDistFromSide);
      if ( v29 )
        this->rAimDistFromSide = *v29;
      v30 = PropertyUtils::Get<float>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_AimDistFromBumper);
      if ( v30 )
        this->rAimDistFromBumper = *v30;
      v31 = PropertyUtils::Get<float>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_AimOriginOffsetX);
      if ( v31 )
        this->rAimOriginOffsetX = *v31;
      v32 = PropertyUtils::Get<float>(m_pSceneObj, (UFG::qArray<unsigned long,0> *)&CAMERA_SYMBOL_AimOriginOffsetConstX);
      if ( v32 )
        this->rAimOriginOffsetConstX = *v32;
      p_override = &_override;
      _override.mUID = v23->mUID;
      if ( UFG::CharacterSubjectComponent::IsOverrideSymbolValid(&_override) )
      {
        this->mFollowOverrideContext.mUID = v23->mUID;
        v23 = &UFG::default_chase_parameter_set;
      }
      PropertySet = UFG::PropertySetManager::GetPropertySet(v23);
      if ( Cameras_ChaseCameraCommon::IsClass(PropertySet->mSchemaName.mUID) )
        MemImagePtr = (UFG::qSymbol *)UFG::qPropertySet::GetMemImagePtr(PropertySet);
      this->pChaseParametersAim = UFG::FindChaseParameters(MemImagePtr);
      this->pChaseParametersFlee = UFG::FindChaseParameters(MemImagePtr + 1);
      this->pChaseParametersRace = UFG::FindChaseParameters(MemImagePtr + 2);
      this->pChaseParametersDrive = UFG::FindChaseParameters(MemImagePtr + 3);
      this->pChaseParametersBurnout = UFG::FindChaseParameters(MemImagePtr + 4);
      this->pChaseParametersLookUp = UFG::FindChaseParameters(MemImagePtr + 5);
      this->pChaseParametersLookBack = UFG::FindChaseParameters(MemImagePtr + 6);
      this->pChaseParametersLookSide = UFG::FindChaseParameters(MemImagePtr + 7);
      this->pChaseParametersPassenger = UFG::FindChaseParameters(MemImagePtr + 8);
      this->pChaseParametersHijackBack = UFG::FindChaseParameters(MemImagePtr + 9);
      this->pChaseParametersHijackSide = UFG::FindChaseParameters(MemImagePtr + 10);
      this->pChaseParametersHijackFront = UFG::FindChaseParameters(MemImagePtr + 11);
      this->pChaseParametersHijackTop = UFG::FindChaseParameters(MemImagePtr + 12);
    }
  }
}

// File Line: 336
// RVA: 0x684660
void __fastcall UFG::VehicleSubjectComponent::OnDetach(UFG::VehicleSubjectComponent *this)
{
  UFG::RebindingComponentHandle<UFG::VehicleOccupantComponent,0> *p_pVehicleOccupants; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rax
  UFG::RebindingComponentHandle<UFG::TargetingSystemVehicleComponent,0> *p_pTargetingSystem; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v10; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v11; // rax
  UFG::RebindingComponentHandle<UFG::PhysicsMoverInterface,0> *p_pPhysicsMover; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v14; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v16; // rax
  UFG::RebindingComponentHandle<UFG::CharacterAnimationComponent,0> *p_pAnimation; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v18; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v19; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v20; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v21; // rax
  UFG::RebindingComponentHandle<UFG::RoadSpaceComponent,0> *p_pRoadSpace; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v25; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v26; // rax
  UFG::RebindingComponentHandle<UFG::AiDriverComponent,0> *p_pAiDriver; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v28; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v29; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v30; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v31; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h] BYREF

  p_pVehicleOccupants = &this->pVehicleOccupants;
  if ( this->pVehicleOccupants.m_pSimComponent )
  {
    mPrev = p_pVehicleOccupants->mPrev;
    mNext = this->pVehicleOccupants.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->pVehicleOccupants.m_pSimComponent = 0i64;
LABEL_7:
    p_pVehicleOccupants->m_pSimObject = 0i64;
    p_pVehicleOccupants->mNext = p_pVehicleOccupants;
    p_pVehicleOccupants->mPrev = p_pVehicleOccupants;
    goto LABEL_8;
  }
  if ( this->pVehicleOccupants.m_pSimObject
    && (p_pVehicleOccupants->mPrev != p_pVehicleOccupants || this->pVehicleOccupants.mNext != &this->pVehicleOccupants) )
  {
    v5 = p_pVehicleOccupants->mPrev;
    v6 = p_pVehicleOccupants->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    goto LABEL_7;
  }
LABEL_8:
  p_pTargetingSystem = &this->pTargetingSystem;
  p_pVehicleOccupants->m_Changed = 1;
  if ( this->pTargetingSystem.m_pSimComponent )
  {
    v8 = p_pTargetingSystem->mPrev;
    v9 = this->pTargetingSystem.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    this->pTargetingSystem.m_pSimComponent = 0i64;
LABEL_14:
    this->pTargetingSystem.m_pSimObject = 0i64;
    this->pTargetingSystem.mNext = &this->pTargetingSystem;
    p_pTargetingSystem->mPrev = p_pTargetingSystem;
    goto LABEL_15;
  }
  if ( this->pTargetingSystem.m_pSimObject
    && (p_pTargetingSystem->mPrev != p_pTargetingSystem || this->pTargetingSystem.mNext != &this->pTargetingSystem) )
  {
    v10 = p_pTargetingSystem->mPrev;
    v11 = this->pTargetingSystem.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    goto LABEL_14;
  }
LABEL_15:
  this->pTargetingSystem.m_Changed = 1;
  p_pPhysicsMover = &this->pPhysicsMover;
  if ( this->pPhysicsMover.m_pSimComponent )
  {
    v13 = p_pPhysicsMover->mPrev;
    v14 = this->pPhysicsMover.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    this->pPhysicsMover.m_pSimComponent = 0i64;
LABEL_21:
    this->pPhysicsMover.m_pSimObject = 0i64;
    this->pPhysicsMover.mNext = &this->pPhysicsMover;
    p_pPhysicsMover->mPrev = p_pPhysicsMover;
    goto LABEL_22;
  }
  if ( this->pPhysicsMover.m_pSimObject
    && (p_pPhysicsMover->mPrev != p_pPhysicsMover || this->pPhysicsMover.mNext != &this->pPhysicsMover) )
  {
    v15 = p_pPhysicsMover->mPrev;
    v16 = this->pPhysicsMover.mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    goto LABEL_21;
  }
LABEL_22:
  this->pPhysicsMover.m_Changed = 1;
  p_pAnimation = &this->pAnimation;
  if ( this->pAnimation.m_pSimComponent )
  {
    v18 = p_pAnimation->mPrev;
    v19 = this->pAnimation.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    this->pAnimation.m_pSimComponent = 0i64;
LABEL_28:
    this->pAnimation.m_pSimObject = 0i64;
    this->pAnimation.mNext = &this->pAnimation;
    p_pAnimation->mPrev = p_pAnimation;
    goto LABEL_29;
  }
  if ( this->pAnimation.m_pSimObject
    && (p_pAnimation->mPrev != p_pAnimation || this->pAnimation.mNext != &this->pAnimation) )
  {
    v20 = p_pAnimation->mPrev;
    v21 = this->pAnimation.mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    goto LABEL_28;
  }
LABEL_29:
  this->pAnimation.m_Changed = 1;
  p_pRoadSpace = &this->pRoadSpace;
  if ( this->pRoadSpace.m_pSimComponent )
  {
    v23 = p_pRoadSpace->mPrev;
    v24 = this->pRoadSpace.mNext;
    v23->mNext = v24;
    v24->mPrev = v23;
    this->pRoadSpace.m_pSimComponent = 0i64;
LABEL_35:
    this->pRoadSpace.m_pSimObject = 0i64;
    this->pRoadSpace.mNext = &this->pRoadSpace;
    p_pRoadSpace->mPrev = p_pRoadSpace;
    goto LABEL_36;
  }
  if ( this->pRoadSpace.m_pSimObject
    && (p_pRoadSpace->mPrev != p_pRoadSpace || this->pRoadSpace.mNext != &this->pRoadSpace) )
  {
    v25 = p_pRoadSpace->mPrev;
    v26 = this->pRoadSpace.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    goto LABEL_35;
  }
LABEL_36:
  this->pRoadSpace.m_Changed = 1;
  p_pAiDriver = &this->pAiDriver;
  if ( this->pAiDriver.m_pSimComponent )
  {
    v28 = p_pAiDriver->mPrev;
    v29 = this->pAiDriver.mNext;
    v28->mNext = v29;
    v29->mPrev = v28;
    this->pAiDriver.m_pSimComponent = 0i64;
LABEL_42:
    this->pAiDriver.m_pSimObject = 0i64;
    this->pAiDriver.mNext = &this->pAiDriver;
    p_pAiDriver->mPrev = p_pAiDriver;
    goto LABEL_43;
  }
  if ( this->pAiDriver.m_pSimObject && (p_pAiDriver->mPrev != p_pAiDriver || this->pAiDriver.mNext != &this->pAiDriver) )
  {
    v30 = p_pAiDriver->mPrev;
    v31 = this->pAiDriver.mNext;
    v30->mNext = v31;
    v31->mPrev = v30;
    goto LABEL_42;
  }
LABEL_43:
  this->pAiDriver.m_Changed = 1;
  this->mFollowOverrideContext.mUID = UFG::qSymbol::qSymbol(&result, 0xFFFFFFFF)->mUID;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->vOriginOffset.x = UFG::qVector3::msZero.x;
  this->vOriginOffset.y = y;
  this->vOriginOffset.z = z;
  *(_QWORD *)&this->rAimLookOffsetLowZ = 0i64;
  this->rAimDistFromSide = 1.8;
  *(_QWORD *)&this->rAimDistFromBumper = 1053609165i64;
  this->rAimOriginOffsetConstX = 0.0;
  UFG::CameraSubject::OnDetach(this);
  this->mSeatBone = -2;
};
  this->rAimDistFromSide = 1.8;
  *(_QWORD *)&this->rAimDistFromBumper = 1053609165i64;
  this->rAimOriginOffsetConstX = 0.0;
  UFG::CameraSubject::OnDetach(this);
  thi

// File Line: 367
// RVA: 0x67A1E0
UFG::qBaseNodeRB *__fastcall UFG::VehicleSubjectComponent::GetChaseTarget(UFG::VehicleSubjectComponent *this)
{
  UFG::qBaseNodeRB *result; // rax

  result = (UFG::qBaseNodeRB *)this->pRoadSpace.m_pSimComponent;
  if ( result )
    return result[53].mChild[0];
  return result;
}

// File Line: 373
// RVA: 0x67F3A0
UFG::SimComponent *__fastcall UFG::VehicleSubjectComponent::IsParkedWithDriver(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *result; // rax

  result = this->pAiDriver.m_pSimComponent;
  if ( result )
    return (UFG::SimComponent *)BYTE1(result[22].m_BoundComponentHandles.mNode.mNext);
  return result;
}

// File Line: 385
// RVA: 0x67F3C0
bool __fastcall UFG::VehicleSubjectComponent::IsParkedWithoutDriver(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax

  m_pSimComponent = this->pVehicleOccupants.m_pSimComponent;
  return m_pSimComponent && m_pSimComponent[1].m_SafePointerList.mNode.mNext;
}

// File Line: 390
// RVA: 0x67F530
__int64 __fastcall UFG::VehicleSubjectComponent::IsRacing(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  UFG::SimComponent *v4; // rax

  if ( ((unsigned __int8 (__fastcall *)(UFG::VehicleSubjectComponent *))this->vfptr[32].__vecDelDtor)(this) )
  {
    m_pSimComponent = this->pRoadSpace.m_pSimComponent;
    if ( !m_pSimComponent || !m_pSimComponent[26].m_SafePointerList.mNode.mPrev )
      return 0i64;
  }
  else
  {
    v4 = this->pAiDriver.m_pSimComponent;
    if ( !v4 || LODWORD(v4[13].m_SafePointerList.mNode.mPrev) != 6 )
      return 0i64;
  }
  return 1i64;
}

// File Line: 407
// RVA: 0x67ED60
bool __fastcall UFG::VehicleSubjectComponent::IsEnemy(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax

  m_pSimComponent = this->pVehicleOccupants.m_pSimComponent;
  return m_pSimComponent && m_pSimComponent[1].m_pSimObject && this->pAiDriver.m_pSimComponent;
}

// File Line: 412
// RVA: 0x67F3E0
bool __fastcall UFG::VehicleSubjectComponent::IsPlayer(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax

  m_pSimComponent = this->pVehicleOccupants.m_pSimComponent;
  return m_pSimComponent && m_pSimComponent[1].m_pSimObject && !this->pAiDriver.m_pSimComponent;
}

// File Line: 417
// RVA: 0x67EAB0
bool __fastcall UFG::VehicleSubjectComponent::IsCop(UFG::VehicleSubjectComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject
    && ((m_Flags = m_pSimObject->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::CopUnitComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CopUnitComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pSimObject->m_Components.p[17].m_pComponent))
      : (ComponentOfTypeHK = m_pSimObject->m_Components.p[17].m_pComponent),
        ComponentOfTypeHK) )
  {
    return ComponentOfTypeHK[7].m_Flags & 1;
  }
  else
  {
    return 0;
  }
}

// File Line: 425
// RVA: 0x67E970
bool __fastcall UFG::VehicleSubjectComponent::IsAmbient(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rcx

  m_pSimComponent = this->pAiDriver.m_pSimComponent;
  return m_pSimComponent
      && ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[16].__vecDelDtor)(m_pSimComponent);
}

// File Line: 430
// RVA: 0x67E9A0
bool __fastcall UFG::VehicleSubjectComponent::IsAttacking(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax

  m_pSimComponent = this->pAiDriver.m_pSimComponent;
  return m_pSimComponent && m_pSimComponent[22].m_TypeUID != 7;
}

// File Line: 435
// RVA: 0x67EB80
bool __fastcall UFG::VehicleSubjectComponent::IsDoingWheelie(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax
  int m_pSimObject; // ecx
  bool result; // al

  m_pSimComponent = this->pPhysicsMover.m_pSimComponent;
  result = 0;
  if ( m_pSimComponent )
  {
    m_pSimObject = (int)m_pSimComponent[1].m_pSimObject;
    if ( (m_pSimObject & 8) != 0 && (m_pSimObject & 0x100) == 0 )
      return 1;
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
    return (UFG::SimComponent *)((LODWORD(result[1].m_pSimObject) >> 5) & 1);
  return result;
}

// File Line: 445
// RVA: 0x67EB60
UFG::SimComponent *__fastcall UFG::VehicleSubjectComponent::IsDoingOneEighty(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *result; // rax

  result = this->pPhysicsMover.m_pSimComponent;
  if ( result )
    return (UFG::SimComponent *)((LODWORD(result[1].m_pSimObject) >> 4) & 1);
  return result;
}

// File Line: 449
// RVA: 0x15855A0
__int64 UFG::_dynamic_initializer_for__symSeatSync01__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("SeatSync01", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symSeatSync01, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symSeatSync01__);
}

// File Line: 450
// RVA: 0x15855E0
__int64 UFG::_dynamic_initializer_for__symSeatSync__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("SeatSync", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&symSeatSync, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__symSeatSync__);
}

// File Line: 453
// RVA: 0x694760
void __fastcall UFG::VehicleSubjectComponent::Update(
        UFG::VehicleSubjectComponent *this,
        float delta_sec,
        UFG::SimObjectVehicle *playerVehicle)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rsi
  bool v5; // zf
  UFG::SimObjectCharacter *v7; // rax
  Creature *v8; // rcx
  float y; // xmm1_4
  float z; // xmm2_4
  float v11; // xmm5_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm4_4
  UFG::SimComponent *m_pSimComponent; // rbx
  UFG::PhysicsVehicle *mPrev; // rcx
  float v21; // xmm0_4
  float v22; // xmm1_4
  float x; // xmm2_4
  UFG::SimComponent *v24; // rbx
  UFG::PhysicsVehicle *v25; // rcx
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  UFG::SimComponent *v29; // rax
  __int64 v30; // rax
  __m128 v31; // xmm1
  float v32; // xmm6_4
  __int64 v33; // rax
  __m128 v34; // xmm1
  float v35; // xmm2_4
  UFG::CopSystem *v36; // rbx
  int BoneID; // r14d
  UFG::RoadNetworkLocation *Name; // rbx
  UFG::SimComponent *v39; // rbp
  UFG::TargetingSimObject *mNext; // rbx
  UFG::TargetingSimObject *i; // rbp
  bool v42; // cl
  __int64 v43; // rbx
  int v44; // eax
  float v45; // xmm1_4
  float v46; // xmm0_4
  UFG::qVector4 v47; // xmm3
  UFG::qVector4 v48; // xmm2
  UFG::qVector4 v49; // xmm0
  UFG::qVector4 v50; // xmm1
  float v51; // xmm10_4
  float v52; // xmm9_4
  float v53; // xmm5_4
  float v54; // xmm11_4
  float v55; // xmm6_4
  float v56; // xmm7_4
  float v57; // xmm8_4
  float v58; // xmm11_4
  float v59; // xmm9_4
  float v60; // xmm6_4
  float v61; // xmm4_4
  float v62; // xmm5_4
  float v63; // xmm10_4
  float v64; // xmm8_4
  float v65; // xmm11_4
  UFG::qVector3 result; // [rsp+20h] [rbp-78h] BYREF

  this->vUp.z = 1.0;
  v4 = 0i64;
  *(_QWORD *)&this->vUp.x = 0i64;
  v5 = this->m_pSimObject == playerVehicle;
  this->pPlayerOccupant = 0i64;
  v7 = 0i64;
  if ( v5 )
    v7 = LocalPlayer;
  this->pPlayerOccupant = v7;
  if ( this->pAnimation.m_pSimComponent )
  {
    v8 = *(Creature **)&this->pAnimation.m_pSimComponent[2].m_TypeUID;
    if ( v8 )
    {
      Creature::GetTransform(v8, &this->mLocalWorld);
      UFG::qInverseAffine(&this->mWorldLocal, &this->mLocalWorld);
    }
  }
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  v11 = 0.0;
  this->vVelocity.x = UFG::qVector3::msZero.x;
  this->vVelocity.y = y;
  this->vVelocity.z = z;
  v12 = UFG::qVector3::msZero.y;
  v13 = UFG::qVector3::msZero.z;
  this->vAngularVelocity.x = UFG::qVector3::msZero.x;
  v14 = *(float *)&FLOAT_1_0;
  this->vAngularVelocity.y = v12;
  v15 = *(float *)&FLOAT_1_0;
  v16 = FLOAT_N1_0;
  this->vAngularVelocity.z = v13;
  v17 = *(float *)&FLOAT_1_0;
  v18 = FLOAT_N1_0;
  if ( this->pPhysicsMover.m_pSimComponent )
  {
    m_pSimComponent = this->pPhysicsMover.m_pSimComponent;
    mPrev = (UFG::PhysicsVehicle *)m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
    if ( !mPrev || UFG::PhysicsVehicle::IsSuspended(mPrev) )
    {
      x = UFG::qVector3::msZero.x;
      v22 = UFG::qVector3::msZero.y;
      v21 = UFG::qVector3::msZero.z;
    }
    else
    {
      UFG::PhysicsVehicle::GetVelocity(
        (UFG::PhysicsVehicle *)m_pSimComponent[10].m_SafePointerList.mNode.mPrev,
        &result);
      v21 = result.z;
      v22 = result.y;
      x = result.x;
    }
    v24 = this->pPhysicsMover.m_pSimComponent;
    this->vVelocity.x = x;
    this->vVelocity.y = v22;
    this->vVelocity.z = v21;
    v25 = (UFG::PhysicsVehicle *)v24[10].m_SafePointerList.mNode.mPrev;
    if ( !v25 || UFG::PhysicsVehicle::IsSuspended(v25) )
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
    v29 = this->pPhysicsMover.m_pSimComponent;
    this->vAngularVelocity.x = v28;
    this->vAngularVelocity.y = v27;
    this->vAngularVelocity.z = v26;
    v16 = *(float *)&v29[10].m_NameUID;
    v18 = *(float *)&v29[10].m_Flags;
    v11 = *(float *)(&v29[10].m_SimObjIndex + 1);
    v14 = *(float *)&v29[10].m_pSimObject;
    v17 = *((float *)&v29[10].m_pSimObject + 1);
    v15 = *(float *)&v29[10].m_BoundComponentHandles.mNode.mPrev;
  }
  this->mBox.mMin.x = v16;
  this->mBox.mMin.y = v18;
  this->mBox.mMin.z = v11;
  this->mBox.mMax.x = v14;
  this->mBox.mMax.y = v17;
  this->mBox.mMax.z = v15;
  v30 = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))this->vfptr[24].__vecDelDtor)(this);
  v31 = (__m128)*(unsigned int *)(v30 + 4);
  v31.m128_f32[0] = (float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(*(float *)v30 * *(float *)v30);
  v32 = _mm_sqrt_ps(v31).m128_f32[0];
  v33 = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))this->vfptr[23].__vecDelDtor)(this);
  v34 = (__m128)*(unsigned int *)(v33 + 4);
  v34.m128_f32[0] = (float)(v34.m128_f32[0] * v34.m128_f32[0]) + (float)(*(float *)v33 * *(float *)v33);
  v35 = _mm_sqrt_ps(v34).m128_f32[0];
  if ( v35 <= v32 )
    v35 = v32;
  this->mRadius = v35;
  this->bFleeing = 0;
  if ( this->pPlayerOccupant )
  {
    v36 = UFG::CopSystem::Instance();
    if ( ((unsigned __int8 (__fastcall *)(UFG::CopSystem *))v36->vfptr[6].__vecDelDtor)(v36) )
    {
      if ( ((unsigned int (__fastcall *)(UFG::CopSystem *))v36->vfptr[32].__vecDelDtor)(v36) )
        this->bFleeing = 1;
    }
  }
  BoneID = -1;
  *(_WORD *)&this->bCanPassLeft = 257;
  if ( this->pRoadSpace.m_pSimComponent && LOBYTE(this->pRoadSpace.m_pSimComponent[8].m_Flags) )
  {
    Name = Scaleform::GFx::AS3::Instances::fl::XML::GetName((UFG::RoadNetworkGuide *)&this->pRoadSpace.m_pSimComponent[5].m_BoundComponentHandles.mNode.mNext);
    this->bCanPassRight = UFG::RoadNetworkLocation::CanReachLane(Name, 1);
    this->bCanPassLeft = UFG::RoadNetworkLocation::CanReachLane(Name, -1);
  }
  this->pActionHijacker = 0i64;
  if ( this->pTargetingSystem.m_pSimComponent )
  {
    v39 = this->pTargetingSystem.m_pSimComponent;
    mNext = (UFG::TargetingSimObject *)v39[1].m_BoundComponentHandles.mNode.mPrev;
    for ( i = (UFG::TargetingSimObject *)&v39[1].m_pSimObject; mNext != i; mNext = (UFG::TargetingSimObject *)mNext->mNext )
    {
      if ( mNext->m_pTarget.m_pPointer
        && mNext->m_bLock
        && mNext->m_eTargetType.mValue == eTARGET_TYPE_VEHICLE_ACTION_HIJACK )
      {
        this->pActionHijacker = (UFG::SimObject *)UFG::TargetingSimObject::GetOwner(mNext);
      }
    }
  }
  if ( this->pAnimation.m_pSimComponent )
  {
    v42 = this->mSeatBone == -2;
    if ( this->pAnimation.m_Changed )
    {
      this->pAnimation.m_Changed = 0;
      v42 = 1;
    }
    v43 = *(_QWORD *)&this->pAnimation.m_pSimComponent[2].m_TypeUID;
    if ( v43 && v42 )
    {
      v44 = *(_QWORD *)(v43 + 440) ? Skeleton::GetBoneID(*(Skeleton **)(v43 + 480), symSeatSync01.mUID) : -1;
      this->mSeatBone = v44;
      if ( v44 == -1 )
      {
        if ( *(_QWORD *)(v43 + 440) )
          BoneID = Skeleton::GetBoneID(*(Skeleton **)(v43 + 480), symSeatSync.mUID);
        this->mSeatBone = BoneID;
      }
    }
  }
  if ( this->pPhysicsMover.m_pSimComponent )
    v4 = this->pPhysicsMover.m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
  if ( v4
    && ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *))v4->mPrev[7].mPrev)(v4) )
  {
    if ( !this->bPinnedOrientation )
      UFG::CameraSubject::PinOrientationSmooth(this, PinOrientMode_Velocity);
  }
  else if ( this->bPinnedOrientation )
  {
    this->bPinnedOrientation = 0;
  }
  UFG::CameraSubject::UpdateBase(this, delta_sec, UFG::bCameraDebugDraw, &UFG::gCameraSubjectUpdateParams);
  if ( UFG::ChaseCameraComponent::bOffsetTune )
  {
    v45 = UFG::ChaseCameraComponent::rOffsetTuneY;
    result.x = UFG::ChaseCameraComponent::rOffsetTuneX;
    v46 = UFG::ChaseCameraComponent::rOffsetTuneZ;
  }
  else
  {
    v45 = this->vOriginOffset.y;
    result.x = this->vOriginOffset.x;
    v46 = this->vOriginOffset.z;
  }
  v47 = this->mLocalWorld.v1;
  v48 = this->mLocalWorld.v2;
  result.z = v46;
  v49 = this->mLocalWorld.v0;
  result.y = v45;
  v50 = this->mLocalWorld.v3;
  v51 = result.x;
  v52 = result.y;
  v53 = result.x;
  v54 = result.z;
  this->mLocalWorldOffset.v0 = v49;
  this->mLocalWorldOffset.v1 = v47;
  this->mLocalWorldOffset.v2 = v48;
  this->mLocalWorldOffset.v3 = v50;
  v49.x = v52 * this->mLocalWorldOffset.v1.x;
  v55 = v54 * this->mLocalWorldOffset.v2.x;
  v56 = v54 * this->mLocalWorldOffset.v2.y;
  v50.x = v52 * this->mLocalWorldOffset.v1.y;
  v48.x = v52 * this->mLocalWorldOffset.v1.z;
  v57 = v54 * this->mLocalWorldOffset.v2.z;
  v58 = v54 * this->mLocalWorldOffset.v2.w;
  v59 = v52 * this->mLocalWorldOffset.v1.w;
  v60 = (float)(v55 + (float)((float)(v51 * this->mLocalWorldOffset.v0.x) + v49.x)) + this->mLocalWorldOffset.v3.x;
  v61 = v51 * this->mLocalWorldOffset.v0.y;
  v62 = v53 * this->mLocalWorldOffset.v0.z;
  v63 = v51 * this->mLocalWorldOffset.v0.w;
  this->mLocalWorldOffset.v3.x = v60;
  v64 = (float)(v57 + (float)(v62 + v48.x)) + this->mLocalWorldOffset.v3.z;
  v65 = (float)(v58 + (float)(v63 + v59)) + this->mLocalWorldOffset.v3.w;
  this->mLocalWorldOffset.v3.y = (float)(v56 + (float)(v61 + v50.x)) + this->mLocalWorldOffset.v3.y;
  this->mLocalWorldOffset.v3.z = v64;
  this->mLocalWorldOffset.v3.w = v65;
  v50.x = this->mLocalWorld.v3.y;
  v48.x = this->mLocalWorld.v3.z;
  this->mPositionOffset.x = this->mLocalWorld.v3.x;
  this->mPositionOffset.y = v50.x;
  this->mPositionOffset.z = v48.x;
  UFG::qInverseAffine(&this->mWorldLocalOffset, &this->mLocalWorldOffset);
}

// File Line: 665
// RVA: 0x694EB0
void __fastcall UFG::VehicleSubjectComponent::UpdateAll(float delta_sec)
{
  UFG::SimObjectVehicle *CurrentVehicle; // rsi
  signed __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::VehicleSubjectComponent *v4; // rcx
  UFG::qList<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent,1,0> *v5; // rbx

  CurrentVehicle = 0i64;
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent;
    else
      m_pComponent = (UFG::CharacterOccupantComponent *)(m_Flags < 0
                                                      || (m_Flags & 0x2000) != 0
                                                      || (m_Flags & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           LocalPlayer,
                                                           UFG::CharacterOccupantComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           LocalPlayer,
                                                           UFG::CharacterOccupantComponent::_TypeUID));
    if ( m_pComponent )
      CurrentVehicle = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
  }
  v4 = (UFG::VehicleSubjectComponent *)&UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList.mNode.mNext[-18];
  if ( (UFG::qList<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent,1,0> *)&UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList.mNode.mNext[-18] != &UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList - 18 )
  {
    do
    {
      v5 = (UFG::qList<UFG::VehicleSubjectComponent,UFG::VehicleSubjectComponent,1,0> *)&v4->mNext[-18];
      UFG::VehicleSubjectComponent::Update(v4, delta_sec, CurrentVehicle);
      v4 = (UFG::VehicleSubjectComponent *)v5;
    }
    while ( v5 != &UFG::VehicleSubjectComponent::s_VehicleSubjectComponentList - 18 );
  }
}

// File Line: 752
// RVA: 0x67A800
double __fastcall UFG::VehicleSubjectComponent::GetMass(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rcx
  UFG::PhysicsVehicle *mPrev; // rcx

  m_pSimComponent = this->pPhysicsMover.m_pSimComponent;
  if ( m_pSimComponent && (mPrev = (UFG::PhysicsVehicle *)m_pSimComponent[10].m_SafePointerList.mNode.mPrev) != 0i64 )
    return UFG::PhysicsVehicle::GetMass(mPrev);
  else
    return 0.0;
}

// File Line: 765
// RVA: 0x67B230
float __fastcall UFG::VehicleSubjectComponent::GetSpeed(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rcx
  __m128 mPrev_low; // xmm2
  float result; // xmm0_4

  m_pSimComponent = this->pPhysicsMover.m_pSimComponent;
  if ( !m_pSimComponent )
    return 0.0;
  mPrev = m_pSimComponent[10].m_SafePointerList.mNode.mPrev;
  if ( !mPrev )
    return *((float *)&m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev + 1);
  mNext = mPrev[6].mPrev[10].mNext;
  if ( !mNext )
    return *((float *)&m_pSimComponent[10].m_BoundComponentHandles.mNode.mPrev + 1);
  mPrev_low = (__m128)LODWORD(mNext[35].mPrev);
  mPrev_low.m128_f32[0] = (float)((float)(mPrev_low.m128_f32[0] * mPrev_low.m128_f32[0])
                                + (float)(*((float *)&mNext[35].mPrev + 1) * *((float *)&mNext[35].mPrev + 1)))
                        + (float)(*(float *)&mNext[35].mNext * *(float *)&mNext[35].mNext);
  LODWORD(result) = _mm_sqrt_ps(mPrev_low).m128_u32[0];
  return result;
}

// File Line: 770
// RVA: 0x67A6A0
float __fastcall UFG::VehicleSubjectComponent::GetForwardSpeed(UFG::VehicleSubjectComponent *this)
{
  UFG::PhysicsMoverInterface *m_pSimComponent; // rax

  m_pSimComponent = (UFG::PhysicsMoverInterface *)this->pPhysicsMover.m_pSimComponent;
  if ( m_pSimComponent )
    return m_pSimComponent->mForwardSpeed;
  else
    return 0.0;
}

// File Line: 785
// RVA: 0x67E9C0
bool __fastcall UFG::VehicleSubjectComponent::IsBike(UFG::VehicleSubjectComponent *this)
{
  UFG::PhysicsMoverInterface *m_pSimComponent; // rax

  m_pSimComponent = (UFG::PhysicsMoverInterface *)this->pPhysicsMover.m_pSimComponent;
  return m_pSimComponent && m_pSimComponent->mNumWheels == 2;
}

// File Line: 790
// RVA: 0x67E9E0
bool __fastcall UFG::VehicleSubjectComponent::IsBoat(UFG::VehicleSubjectComponent *this)
{
  UFG::SimComponent *m_pSimComponent; // rax

  m_pSimComponent = this->pPhysicsMover.m_pSimComponent;
  return m_pSimComponent && !LODWORD(m_pSimComponent[12].m_BoundComponentHandles.mNode.mNext);
}

// File Line: 795
// RVA: 0x679720
signed __int64 __fastcall UFG::VehicleSubjectComponent::GetBoxSide(
        UFG::VehicleSubjectComponent *this,
        UFG::qVector3 *position)
{
  float *v4; // rbx
  float *v5; // rax
  float v6; // xmm9_4
  float v7; // xmm10_4
  float x; // xmm6_4
  float y; // xmm11_4
  float v10; // xmm8_4
  float z; // xmm7_4
  float *v12; // rax
  float v13; // xmm13_4
  float v14; // xmm9_4
  float v15; // xmm5_4
  float v16; // xmm0_4
  signed __int64 result; // rax
  float v18; // [rsp+28h] [rbp-130h]
  UFG::qVector3 verts; // [rsp+40h] [rbp-118h] BYREF
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

  UFG::CameraSubject::GetBoxVerts(this, &verts, 0.0);
  v4 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))this->vfptr[24].__vecDelDtor)(this);
  v5 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))this->vfptr[23].__vecDelDtor)(this);
  v6 = (float)(v4[1] + v5[1]) * 0.5;
  v7 = (float)(v4[2] + v5[2]) * 0.5;
  x = position->x;
  y = position->y;
  v10 = (float)(*v5 + *v4) * 0.5;
  z = position->z;
  v12 = (float *)((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))this->vfptr[19].__vecDelDtor)(this);
  v39 = (float)((float)((float)((float)(y * v12[4]) + (float)(x * *v12)) + (float)(z * v12[8])) + v12[12]) - v10;
  v38 = (float)((float)((float)((float)(y * v12[5]) + (float)(x * v12[1])) + (float)(z * v12[9])) + v12[13]) - v6;
  v18 = (float)((float)((float)((float)(y * v12[6]) + (float)(x * v12[2])) + (float)(z * v12[10])) + v12[14]) - v7;
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
UFG::TargetingSystemBaseComponent *__fastcall UFG::VehicleSubjectComponent::GetTargetingSystem(
        UFG::VehicleSubjectComponent *this)
{
  UFG::SimObjectGame *pPlayerOccupant; // rcx
  __int16 m_Flags; // dx
  unsigned int v5; // edx
  bool v6; // zf

  pPlayerOccupant = (UFG::SimObjectGame *)this->pPlayerOccupant;
  if ( !pPlayerOccupant )
    return (UFG::TargetingSystemBaseComponent *)this->pTargetingSystem.m_pSimComponent;
  m_Flags = pPlayerOccupant->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    return (UFG::TargetingSystemBaseComponent *)pPlayerOccupant->m_Components.p[20].m_pComponent;
  if ( (m_Flags & 0x2000) != 0 )
  {
    v5 = UFG::TargetingSystemBaseComponent::_TypeUID;
    return (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(pPlayerOccupant, v5);
  }
  v6 = (m_Flags & 0x1000) == 0;
  v5 = UFG::TargetingSystemBaseComponent::_TypeUID;
  if ( !v6 )
    return (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(pPlayerOccupant, v5);
  return (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                pPlayerOccupant,
                                                UFG::TargetingSystemBaseComponent::_TypeUID);
}

// File Line: 837
// RVA: 0x67B3C0
UFG::TargetingSystemVehicleComponent *__fastcall UFG::VehicleSubjectComponent::GetTargetingSystemVehicle(
        UFG::VehicleSubjectComponent *this)
{
  return (UFG::TargetingSystemVehicleComponent *)this->pTargetingSystem.m_pSimComponent;
}

