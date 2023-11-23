// File Line: 84
// RVA: 0x1573940
__int64 dynamic_initializer_for__UFG::RoadSpaceComponent::s_RoadSpaceComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::RoadSpaceComponent::s_RoadSpaceComponentList__);
}

// File Line: 85
// RVA: 0x64DA40
UFG::ComponentIDDesc *__fastcall UFG::RoadSpaceComponent::GetDesc(UFG::RoadSpaceComponent *this)
{
  return &UFG::RoadSpaceComponent::_TypeIDesc;
}

// File Line: 87
// RVA: 0x15738D0
__int64 dynamic_initializer_for__UFG::RoadSpaceComponent::mNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RoadSpace", 0xFFFFFFFF);
  UFG::RoadSpaceComponent::mNameUID = result;
  return result;
}

// File Line: 100
// RVA: 0x642EB0
void __fastcall UFG::RoadSpaceComponent::RoadSpaceComponent(UFG::RoadSpaceComponent *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pChaseTarget; // rsi
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *mPrev; // rax
  UFG::qVector4 v6; // xmm4
  UFG::qVector4 v7; // xmm3
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4

  UFG::SimComponent::SimComponent(this, UFG::RoadSpaceComponent::mNameUID);
  this->mPrev = &this->UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent>;
  this->mNext = &this->UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RoadSpaceComponent::`vftable;
  UFG::NavGuide::NavGuide(&this->m_NavGuide);
  *(_QWORD *)&this->m_DestNavRadius = 0x40000000i64;
  this->m_NavWanderDestPos.y = 0.0;
  this->m_NavWanderDestPos.z = -1000.0;
  this->m_NavWanderRadius = 5.0;
  this->m_HasNavWanderCenter = 0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_NavWanderCenter.x = UFG::qVector3::msZero.x;
  this->m_NavWanderCenter.y = y;
  this->m_NavWanderCenter.z = z;
  UFG::RoadNetworkGuide::RoadNetworkGuide(&this->mGuide);
  UFG::WayFinderClient::WayFinderClient(&this->mWayClient);
  this->mWayClient.vfptr = (UFG::WayFinderClientVtbl *)&UFG::VehicleWayFinderClient::`vftable;
  this->mWayClient.m_RoadNetworkType = 0;
  this->mWayClient.m_LaneFlags = -1;
  this->mWayClient.m_RoadGuide = 0i64;
  this->mWayClient.m_AllowFootPaths = 0;
  p_m_pChaseTarget = &this->m_pChaseTarget;
  this->m_pChaseTarget.mPrev = &this->m_pChaseTarget;
  this->m_pChaseTarget.mNext = &this->m_pChaseTarget;
  this->m_pChaseTarget.m_pPointer = 0i64;
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::RebindingComponentHandle<UFG::CameraSubject,0>(&this->m_pSubject);
  UFG::RingBuffer<UFG::Crumb>::RingBuffer<UFG::Crumb>(
    &this->m_PositionTrail.mTrail,
    UFG::AiDriverComponent::m_NumBreadCrumbs);
  this->m_LaneFlags = 2;
  this->m_NavGuideEnabled = 0;
  mPrev = UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mPrev;
  UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *)&UFG::RoadSpaceComponent::s_RoadSpaceComponentList;
  UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mPrev = &this->UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent>;
  UFG::SimComponent::AddType(this, UFG::RoadSpaceComponent::_RoadSpaceComponentTypeUID, "RoadSpaceComponent");
  this->mWayClient.m_RoadGuide = &this->mGuide;
  if ( this->mGuide.m_Attached )
    UFG::VehicleWayFinderClient::SetLaneFlagsFromGuide(&this->mWayClient, &this->mGuide);
  v6 = 0i64;
  v7 = 0i64;
  v7.x = (float)1;
  this->m_ChaseWorld.v0 = v7;
  this->m_ChaseWorld.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v7, (__m128)v7, 81);
  this->m_ChaseWorld.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v7, (__m128)v7, 69);
  this->m_ChaseWorld.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v7, (__m128)v7, 21);
  v6.x = (float)1;
  this->m_WorldChase.v0 = v6;
  this->m_WorldChase.v1 = (UFG::qVector4)_mm_shuffle_ps((__m128)v6, (__m128)v6, 81);
  this->m_WorldChase.v2 = (UFG::qVector4)_mm_shuffle_ps((__m128)v6, (__m128)v6, 69);
  this->m_WorldChase.v3 = (UFG::qVector4)_mm_shuffle_ps((__m128)v6, (__m128)v6, 21);
  if ( this->m_pChaseTarget.m_pPointer )
  {
    v8 = p_m_pChaseTarget->mPrev;
    mNext = this->m_pChaseTarget.mNext;
    v8->mNext = mNext;
    mNext->mPrev = v8;
    p_m_pChaseTarget->mPrev = p_m_pChaseTarget;
    this->m_pChaseTarget.mNext = &this->m_pChaseTarget;
  }
  this->m_pChaseTarget.m_pPointer = 0i64;
  this->m_pChaseFormation = 0i64;
  this->m_pRacePosition = 0i64;
  this->m_pRacePositionSteer = 0i64;
  *(_QWORD *)&this->m_fChaseCurvature = 0i64;
  *(_QWORD *)&this->m_fChaseDistance = 0i64;
  v10 = UFG::qVector3::msZero.y;
  v11 = UFG::qVector3::msZero.z;
  this->mDestinationPosition.x = UFG::qVector3::msZero.x;
  this->mDestinationPosition.y = v10;
  this->mDestinationPosition.z = v11;
  v12 = UFG::qVector3::msZero.y;
  v13 = UFG::qVector3::msZero.z;
  this->mDestinationDirection.x = UFG::qVector3::msZero.x;
  this->mDestinationDirection.y = v12;
  this->mDestinationDirection.z = v13;
  *(_DWORD *)&this->mBits &= 0xFFFFFFF8;
  *(_DWORD *)&this->mBits |= 8u;
}

// File Line: 128
// RVA: 0x643E80
void __fastcall UFG::RoadSpaceComponent::~RoadSpaceComponent(UFG::RoadSpaceComponent *this)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::VehicleSubjectComponent *ComponentOfTypeHK; // rax
  UFG::VehicleFormations *m_pChaseFormation; // rbx
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v6; // rsi
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *mPrev; // rcx
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *mNext; // rax
  UFG::Crumb *mData; // rcx
  float *p_fCurvature; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pChaseTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v16; // rcx
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v17; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RoadSpaceComponent::`vftable;
  m_pPointer = (UFG::SimObjectVehicle *)this->m_pChaseTarget.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      goto LABEL_8;
    if ( m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(m_pPointer);
      goto LABEL_11;
    }
    if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_8:
      ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::VehicleSubjectComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::VehicleSubjectComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
LABEL_11:
  if ( ComponentOfTypeHK )
    UFG::VehicleSubjectComponent::RemoveChaser(ComponentOfTypeHK, this->m_pSimObject);
  UFG::RoadSpaceComponent::FlushRaceTrails(this);
  m_pChaseFormation = this->m_pChaseFormation;
  if ( m_pChaseFormation )
  {
    UFG::VehicleFormations::~VehicleFormations(this->m_pChaseFormation);
    operator delete[](m_pChaseFormation);
    this->m_pChaseFormation = 0i64;
  }
  if ( this == UFG::RoadSpaceComponent::s_RoadSpaceComponentpCurrentIterator )
    UFG::RoadSpaceComponent::s_RoadSpaceComponentpCurrentIterator = (UFG::RoadSpaceComponent *)&this->mPrev[-4];
  v6 = &this->UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent>;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent>;
  this->mNext = &this->UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent>;
  mData = this->m_PositionTrail.mTrail.mData;
  if ( mData )
  {
    p_fCurvature = &mData[-1].fCurvature;
    `eh vector destructor iterator(mData, 0x20ui64, LODWORD(mData[-1].fCurvature), (void (__fastcall *)(void *))_);
    operator delete[](p_fCurvature);
  }
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&this->m_pSubject);
  p_m_pChaseTarget = &this->m_pChaseTarget;
  if ( this->m_pChaseTarget.m_pPointer )
  {
    v12 = p_m_pChaseTarget->mPrev;
    v13 = this->m_pChaseTarget.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    p_m_pChaseTarget->mPrev = p_m_pChaseTarget;
    this->m_pChaseTarget.mNext = &this->m_pChaseTarget;
  }
  this->m_pChaseTarget.m_pPointer = 0i64;
  v14 = p_m_pChaseTarget->mPrev;
  v15 = this->m_pChaseTarget.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  p_m_pChaseTarget->mPrev = p_m_pChaseTarget;
  this->m_pChaseTarget.mNext = &this->m_pChaseTarget;
  this->mWayClient.vfptr = (UFG::WayFinderClientVtbl *)&UFG::VehicleWayFinderClient::`vftable;
  this->mWayClient.vfptr = (UFG::WayFinderClientVtbl *)&UFG::WayFinderClient::`vftable;
  UFG::RoadNetworkGuide::~RoadNetworkGuide(&this->mGuide);
  UFG::NavGuide::~NavGuide(&this->m_NavGuide);
  v16 = v6->mPrev;
  v17 = this->mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v6->mPrev = v6;
  this->mNext = &this->UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 224
// RVA: 0x65E8D0
void __fastcall UFG::RoadSpaceComponent::TeleportEventHandler(UFG::RoadSpaceComponent *this, UFG::Event *event)
{
  bool m_Attached; // si
  UFG::RacePosition *m_pRacePositionSteer; // rcx
  UFG::qVector3 *p_mNext; // rdi
  UFG::RacePosition *m_pRacePosition; // rcx

  m_Attached = this->mGuide.m_Attached;
  if ( m_Attached )
    UFG::RoadNetworkGuide::RemoveFromNetwork(&this->mGuide);
  m_pRacePositionSteer = this->m_pRacePositionSteer;
  p_mNext = (UFG::qVector3 *)&event[2].mNext;
  if ( m_pRacePositionSteer )
    UFG::RacePosition::InitPosition(m_pRacePositionSteer, p_mNext);
  m_pRacePosition = this->m_pRacePosition;
  if ( m_pRacePosition )
    UFG::RacePosition::InitPosition(m_pRacePosition, p_mNext);
  if ( m_Attached )
    UFG::RoadSpaceComponent::AttachToRoadNetwork(this, p_mNext, 0i64);
  this->m_fChaseFailedTimer = 0.0;
}

// File Line: 240
// RVA: 0x656800
void __fastcall UFG::RoadSpaceComponent::OnAttach(UFG::RoadSpaceComponent *this, UFG::SimObjectCVBase *object)
{
  UFG::RebindingComponentHandle<UFG::CameraSubject,0> *p_m_pSubject; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx
  signed __int16 m_Flags; // cx
  UFG::AiDriverComponent *v10; // rax
  UFG::SimComponent *m_pSimComponent; // rcx

  p_m_pSubject = &this->m_pSubject;
  if ( p_m_pSubject->m_pSimComponent )
  {
    mNext = p_m_pSubject->mNext;
    mPrev = p_m_pSubject->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pSubject->m_pSimComponent = 0i64;
  }
  else
  {
    if ( !p_m_pSubject->m_pSimObject || p_m_pSubject->mPrev == p_m_pSubject && p_m_pSubject->mNext == p_m_pSubject )
      goto LABEL_8;
    v7 = p_m_pSubject->mNext;
    v8 = p_m_pSubject->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
  }
  p_m_pSubject->m_pSimObject = 0i64;
  p_m_pSubject->mNext = p_m_pSubject;
  p_m_pSubject->mPrev = p_m_pSubject;
LABEL_8:
  p_m_pSubject->m_Changed = 1;
  p_m_pSubject->m_pSimObject = object;
  p_m_pSubject->m_TypeUID = UFG::CameraSubject::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::BindInternal<UFG::SimObject>(p_m_pSubject, object);
  if ( object )
  {
    m_Flags = object->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      v10 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(object);
    else
      v10 = (UFG::AiDriverComponent *)((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                     ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                         object,
                                         UFG::AiDriverComponent::_TypeUID)
                                     : UFG::SimObject::GetComponentOfType(object, UFG::AiDriverComponent::_TypeUID));
    if ( v10 )
    {
      if ( UFG::SimObjectUtility::IsClassType(object, &qSymbol_Tram) )
      {
        this->mWayClient.m_RoadNetworkType = 1;
      }
      else if ( UFG::SimObjectUtility::IsClassType(object, &qSymbol_Ferry) )
      {
        this->mWayClient.m_RoadNetworkType = 2;
      }
      else
      {
        this->mWayClient.m_RoadNetworkType = UFG::SimObjectUtility::IsClassType(object, &qSymbol_Boat_21) != 0 ? 3 : 0;
      }
    }
  }
  UFG::RoadSpaceComponent::SetupLaneFlags(this);
  m_pSimComponent = this->m_pSubject.m_pSimComponent;
  if ( m_pSimComponent )
  {
    if ( ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[46].__vecDelDtor)(m_pSimComponent) )
      UFG::RoadSpaceComponent::SnapToRoadNetwork(this);
  }
}

// File Line: 274
// RVA: 0x656B30
void __fastcall UFG::RoadSpaceComponent::OnDetach(UFG::RoadSpaceComponent *this)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::VehicleSubjectComponent *ComponentOfTypeHK; // rax
  UFG::RebindingComponentHandle<UFG::CameraSubject,0> *p_m_pSubject; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax

  m_pPointer = (UFG::SimObjectVehicle *)this->m_pChaseTarget.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      goto LABEL_8;
    if ( m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(m_pPointer);
      goto LABEL_11;
    }
    if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_8:
      ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::VehicleSubjectComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::VehicleSubjectComponent::_TypeUID);
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
LABEL_11:
  if ( ComponentOfTypeHK )
    UFG::VehicleSubjectComponent::RemoveChaser(ComponentOfTypeHK, this->m_pSimObject);
  p_m_pSubject = &this->m_pSubject;
  if ( this->m_pSubject.m_pSimComponent )
  {
    mPrev = p_m_pSubject->mPrev;
    mNext = this->m_pSubject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->m_pSubject.m_pSimComponent = 0i64;
LABEL_19:
    this->m_pSubject.m_pSimObject = 0i64;
    this->m_pSubject.mNext = &this->m_pSubject;
    p_m_pSubject->mPrev = p_m_pSubject;
    goto LABEL_20;
  }
  if ( this->m_pSubject.m_pSimObject
    && (p_m_pSubject->mPrev != p_m_pSubject || this->m_pSubject.mNext != &this->m_pSubject) )
  {
    v8 = p_m_pSubject->mPrev;
    v9 = this->m_pSubject.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    goto LABEL_19;
  }
LABEL_20:
  this->m_pSubject.m_Changed = 1;
  UFG::RoadNetworkGuide::RemoveFromNetwork(&this->mGuide);
  UFG::RoadSpaceComponent::FlushRaceTrails(this);
}

// File Line: 290
// RVA: 0x659A40
void __fastcall UFG::RoadSpaceComponent::SetupLaneFlags(UFG::RoadSpaceComponent *this)
{
  UFG::SimObjectVehicle *m_pSimObject; // rbx
  UFG::AiDriverComponent *v3; // rax
  UFG::VehicleSubjectComponent *v4; // rax

  m_pSimObject = (UFG::SimObjectVehicle *)this->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x8000u) != 0 )
  {
    if ( m_pSimObject )
    {
      v3 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)this->m_pSimObject);
      if ( v3 )
      {
        if ( !((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v3->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(v3) )
          this->m_LaneFlags |= 1u;
      }
    }
    if ( UFG::SimObjectUtility::IsClassType(m_pSimObject, &qSymbol_Tram)
      || UFG::SimObjectUtility::IsClassType(m_pSimObject, &qSymbol_Ferry)
      || UFG::SimObjectUtility::IsClassType(m_pSimObject, &qSymbol_Minibus) )
    {
      this->m_LaneFlags = 16;
    }
    if ( m_pSimObject )
      v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(m_pSimObject);
    else
      v4 = 0i64;
    if ( ((unsigned __int8 (__fastcall *)(UFG::VehicleSubjectComponent *))v4->vfptr[30].__vecDelDtor)(v4) )
      this->m_LaneFlags = this->m_LaneFlags & 0xFFFFFFFA | 4;
  }
}

// File Line: 321
// RVA: 0x6594E0
void __fastcall UFG::RoadSpaceComponent::SetLaneFlags(UFG::RoadSpaceComponent *this, unsigned int flagMask)
{
  this->m_LaneFlags = flagMask;
}

// File Line: 338
// RVA: 0x65F6F0
void __fastcall UFG::RoadSpaceComponent::Update(UFG::RoadSpaceComponent *this, float delta_sec)
{
  UFG::SimComponent *m_pSimComponent; // rcx
  __int64 v4; // rbx
  __int64 v5; // rax
  float v6; // xmm2_4
  float v7; // xmm3_4
  UFG::SimObject *m_pSimObject; // r14
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r14
  UFG::qVector3 *v10; // r14
  UFG::SimComponent *v11; // rcx
  char v12; // bp
  char v13; // si
  bool v14; // r15
  float *v15; // rax
  float v16; // xmm2_4
  UFG::WheeledVehicleNavigationData *m_NavigationData; // rcx
  unsigned int m_RoadNetworkType; // eax
  UFG::WayGraph **p_m_WayGraph; // rdx
  UFG::SimObject *v20; // rbx
  UFG::TransformNodeComponent *v21; // rbx
  UFG::RacePosition *m_pRacePosition; // rcx
  UFG::RacePosition *m_pRacePositionSteer; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *CarChaseTargetFormation; // rax
  char v25[16]; // [rsp+20h] [rbp-48h] BYREF

  m_pSimComponent = this->m_pSubject.m_pSimComponent;
  if ( m_pSimComponent )
  {
    v4 = ((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[23].__vecDelDtor)(m_pSimComponent);
    v5 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pSubject.m_pSimComponent->vfptr[24].__vecDelDtor)(this->m_pSubject.m_pSimComponent);
    LODWORD(v6) = *(_DWORD *)v4 & _xmm;
    v7 = *(float *)(v5 + 4) - *(float *)(v4 + 4);
    LODWORD(this->mGuide.m_FrontBoundary) = *(_DWORD *)v5 & _xmm;
    this->mGuide.m_RearBoundary = v6;
    LODWORD(this->mGuide.m_ObjectWidth) = LODWORD(v7) & _xmm;
  }
  UFG::RoadSpaceComponent::UpdateChaseMatrix(this);
  UFG::RoadSpaceComponent::UpdateNavGuide(this);
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v10 = (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3;
  if ( this->mGuide.m_Attached )
  {
    UFG::RoadNetworkGuide::Update(&this->mGuide, v10);
  }
  else
  {
    v11 = this->m_pSubject.m_pSimComponent;
    v12 = v11 && ((unsigned __int8 (__fastcall *)(UFG::SimComponent *))v11->vfptr[46].__vecDelDtor)(v11);
    v13 = (*(_DWORD *)&this->mBits & 4) != 0;
    v14 = v12 && (*(_DWORD *)&this->mBits & 4) == 0;
    v15 = (float *)(*((__int64 (__fastcall **)(UFG::VehicleWayFinderClient *, char *))&this->mWayClient.vfptr[1].__vecDelDtor
                    + 1))(
                     &this->mWayClient,
                     v25);
    v16 = (float)((float)((float)(v10->y - v15[1]) * (float)(v10->y - v15[1]))
                + (float)((float)(v10->x - *v15) * (float)(v10->x - *v15)))
        + (float)((float)(v10->z - v15[2]) * (float)(v10->z - v15[2]));
    if ( v16 > 9.0 && v12 || v14 )
      UFG::RoadSpaceComponent::SnapToRoadNetwork(this);
    if ( v16 > 9.0 )
    {
      m_NavigationData = UFG::WheeledVehicleManager::m_Instance->m_NavigationData;
      m_RoadNetworkType = this->mWayClient.m_RoadNetworkType;
      if ( m_RoadNetworkType == 1 )
      {
        p_m_WayGraph = &m_NavigationData->mTramWayFinder.m_WayGraph;
      }
      else if ( m_RoadNetworkType == 2 )
      {
        p_m_WayGraph = &m_NavigationData->mFerryWayFinder.m_WayGraph;
      }
      else
      {
        p_m_WayGraph = &m_NavigationData->mOceanWayFinder.m_WayGraph;
        if ( m_RoadNetworkType != 3 )
          p_m_WayGraph = &m_NavigationData->mTrafficWayFinder.m_WayGraph;
      }
      this->mWayClient.vfptr->SetPosition(&this->mWayClient, *p_m_WayGraph, v10, (UFG::qVector3 *)&this->m_ChaseWorld);
    }
    if ( v13 != v12 )
    {
      *(_DWORD *)&this->mBits &= ~4u;
      *(_DWORD *)&this->mBits |= 4 * (v12 != 0);
    }
  }
  UFG::RoadSpaceComponent::CleanupOnRaceDeleted(this);
  v20 = this->m_pSimObject;
  if ( v20 )
  {
    v21 = v20->m_pTransformNodeComponent;
    if ( v21 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v21);
      UFG::CrumbTrail::Update(&this->m_PositionTrail, (UFG::qVector3 *)&v21->mWorldTransform.v3);
    }
  }
  m_pRacePosition = this->m_pRacePosition;
  if ( m_pRacePosition )
    UFG::RacePosition::Update(m_pRacePosition, v10, delta_sec);
  m_pRacePositionSteer = this->m_pRacePositionSteer;
  if ( m_pRacePositionSteer )
    UFG::RacePosition::UpdateRacePoint(m_pRacePositionSteer, v10);
  CarChaseTargetFormation = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(this);
  if ( CarChaseTargetFormation )
    UFG::VehicleFormations::Update((UFG::VehicleFormations *)CarChaseTargetFormation, delta_sec);
}

// File Line: 780
// RVA: 0x651DB0
_BOOL8 __fastcall UFG::RoadSpaceComponent::IsNavGuideEnabled(UFG::RoadSpaceComponent *this)
{
  return this->m_NavGuideEnabled;
}

// File Line: 800
// RVA: 0x64D530
void __fastcall UFG::RoadSpaceComponent::FindPath(UFG::RoadSpaceComponent *this)
{
  UFG::SimObject *m_pSimObject; // rdi

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimObject);
  UFG::NavGuide::FindPath(
    &this->m_NavGuide,
    (UFG::qVector3 *)m_pSimObject[1].mNode.mChild,
    &this->mDestinationPosition,
    COERCE_DOUBLE((unsigned __int64)LODWORD(this->m_DestNavRadius)));
}

// File Line: 829
// RVA: 0x6451F0
void __fastcall UFG::RoadSpaceComponent::AttachToRoadNetwork(
        UFG::RoadSpaceComponent *this,
        UFG::qVector3 *position,
        UFG::qVector3 *forward)
{
  UFG::RoadNetworkResource *v3; // rsi
  unsigned int type; // ebx
  float m_LaneT; // xmm6_4
  unsigned int mLaneIndex; // ebx
  UFG::RoadNetworkNode *RoadNetworkNode; // rax
  UFG::RoadNetworkLocation v11; // [rsp+30h] [rbp-28h] BYREF

  v3 = UFG::gpRoadNetworkResource;
  if ( UFG::gpRoadNetworkResource )
  {
    type = 0;
    if ( UFG::SimObjectUtility::IsClassType(this->m_pSimObject, &qSymbol_Tram) )
    {
      type = 1;
    }
    else if ( UFG::SimObjectUtility::IsClassType(this->m_pSimObject, &qSymbol_Ferry) )
    {
      type = 2;
    }
    else if ( UFG::SimObjectUtility::IsClassType(this->m_pSimObject, &qSymbol_Boat_21) )
    {
      type = 3;
    }
    Scaleform::GFx::AS3::Value::Value(&v11);
    UFG::RoadNetworkLocation::AttachToNetwork(&v11, v3, position, forward, type);
    m_LaneT = v11.m_LaneT;
    mLaneIndex = v11.m_CurrentLane->mLaneIndex;
    RoadNetworkNode = UFG::RoadNetworkLocation::GetRoadNetworkNode(&v11);
    UFG::RoadNetworkGuide::AttachToNetwork(&this->mGuide, this->m_pSimObject, RoadNetworkNode, mLaneIndex, m_LaneT);
  }
}

// File Line: 859
// RVA: 0x65A5B0
void __fastcall UFG::RoadSpaceComponent::SnapToRoadNetwork(UFG::RoadSpaceComponent *this)
{
  UFG::SimObject *m_pSimObject; // rbx

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimObject);
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimObject);
  UFG::RoadSpaceComponent::AttachToRoadNetwork(
    this,
    (UFG::qVector3 *)m_pSimObject[1].mNode.mChild,
    (UFG::qVector3 *)&m_pSimObject[1]);
  UFG::RoadNetworkGuide::RemoveFromNetwork(&this->mGuide);
}

// File Line: 866
// RVA: 0x6452F0
void __fastcall UFG::RoadSpaceComponent::AttachToRoadNetwork(UFG::RoadSpaceComponent *this, bool consider_heading)
{
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qVector3 *p_mWorldTransform; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx

  m_pSimObject = this->m_pSimObject;
  p_mWorldTransform = 0i64;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  if ( consider_heading )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    p_mWorldTransform = (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform;
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  UFG::RoadSpaceComponent::AttachToRoadNetwork(
    this,
    (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
    p_mWorldTransform);
}

// File Line: 878
// RVA: 0x64FB10
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::GetSteerToDestination(
        UFG::RoadSpaceComponent *this,
        UFG::qVector3 *result,
        float steerToDistance,
        bool isBoat,
        bool useDirection)
{
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::SimComponent *m_pSimComponent; // rcx
  __m128 x_low; // xmm10
  float v13; // xmm7_4
  float v14; // xmm11_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *vfptr; // rax
  UFG::qVector3 *v16; // rbp
  float v17; // xmm9_4
  float v18; // xmm8_4
  UFG::SimComponent *v19; // rdi
  float *v20; // rbx
  float v21; // xmm13_4
  float v22; // xmm6_4
  float v23; // xmm6_4
  float v24; // xmm15_4
  float v25; // xmm4_4
  float x; // xmm5_4
  float v27; // xmm8_4
  __m128 v28; // xmm9
  float v29; // xmm7_4
  __m128 v30; // xmm2
  float v31; // xmm1_4
  float v32; // xmm11_4
  float v33; // xmm9_4
  float v34; // xmm7_4
  float v35; // xmm8_4
  float v36; // xmm12_4
  float v37; // xmm2_4
  float v38; // xmm8_4
  float v39; // xmm9_4
  __m128 y_low; // xmm10
  float v41; // xmm7_4
  __m128 v42; // xmm11
  float v43; // xmm12_4
  __m128 v44; // xmm2
  __m128 v45; // xmm0
  __m128 v46; // xmm2
  float v47; // xmm6_4
  float v48; // xmm10_4
  float v49; // xmm12_4
  float v50; // xmm11_4
  __m128 v51; // xmm3
  float v52; // xmm5_4
  __m128 v53; // xmm2
  float v54; // xmm4_4
  float v55; // xmm10_4
  float v56; // xmm6_4
  float v57; // xmm9_4
  float v58; // xmm7_4
  float v59; // xmm9_4
  float v60; // xmm7_4
  UFG::qVector3 *v61; // rax
  float v62; // xmm0_4
  float v63; // xmm1_4
  UFG::qVector3 ray; // [rsp+30h] [rbp-D8h] BYREF
  UFG::qVector3 resulta; // [rsp+40h] [rbp-C8h] BYREF
  float v66; // [rsp+110h] [rbp+8h]

  y = this->mDestinationPosition.y;
  z = this->mDestinationPosition.z;
  result->x = this->mDestinationPosition.x;
  result->y = y;
  result->z = z;
  if ( !this->m_pSubject.m_pSimComponent )
    return result;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  m_pSimComponent = this->m_pSubject.m_pSimComponent;
  x_low = (__m128)LODWORD(this->mDestinationDirection.x);
  v13 = this->mDestinationDirection.y;
  v14 = this->mDestinationDirection.z;
  vfptr = m_pSimComponent->vfptr;
  ray.x = this->mDestinationDirection.x;
  ray.y = v13;
  ray.z = v14;
  v16 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::SimComponent *))vfptr[17].__vecDelDtor)(m_pSimComponent);
  ((void (__fastcall *)(UFG::SimComponent *))this->m_pSubject.m_pSimComponent->vfptr[16].__vecDelDtor)(this->m_pSubject.m_pSimComponent);
  if ( useDirection
    && (float)((float)((float)(v13 * v13) + (float)(x_low.m128_f32[0] * x_low.m128_f32[0])) + (float)(v14 * v14)) >= 0.001 )
  {
    if ( (float)((float)((float)((float)(v16->y - result->y) * (float)(v16->y - result->y))
                       + (float)((float)(v16->x - result->x) * (float)(v16->x - result->x)))
               + (float)((float)(v16->z - result->z) * (float)(v16->z - result->z))) > 4.0 )
    {
      v17 = FLOAT_0_78539819;
      if ( isBoat )
        v17 = FLOAT_0_39269909;
      v18 = FLOAT_10_0;
      if ( isBoat )
        v18 = FLOAT_20_0;
      v19 = this->m_pSubject.m_pSimComponent;
      v20 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v19->vfptr[24].__vecDelDtor)(v19);
      v21 = *(float *)&FLOAT_1_0;
      v22 = (float)(*v20 - *(float *)((__int64 (__fastcall *)(UFG::SimComponent *))v19->vfptr[23].__vecDelDtor)(v19))
          - 1.0;
      if ( v22 < 1.0 )
        v22 = *(float *)&FLOAT_1_0;
      v23 = v22 / v17;
      if ( v23 <= 2.0 )
        v23 = FLOAT_2_0;
      if ( v23 >= v18 )
        v23 = v18;
      v24 = UFG::qVector3::msDirUp.y;
      v25 = UFG::qVector3::msDirUp.z;
      x = UFG::qVector3::msDirUp.x;
      v28 = x_low;
      v66 = v23 * v23;
      v27 = (float)(v14 * UFG::qVector3::msDirUp.y) - (float)(v13 * UFG::qVector3::msDirUp.z);
      v28.m128_f32[0] = (float)(x_low.m128_f32[0] * UFG::qVector3::msDirUp.z) - (float)(v14 * UFG::qVector3::msDirUp.x);
      v30 = v28;
      v29 = (float)(v13 * UFG::qVector3::msDirUp.x) - (float)(x_low.m128_f32[0] * UFG::qVector3::msDirUp.y);
      v30.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(v27 * v27)) + (float)(v29 * v29);
      if ( v30.m128_f32[0] == 0.0 )
        v31 = 0.0;
      else
        v31 = 1.0 / _mm_sqrt_ps(v30).m128_f32[0];
      v32 = result->y;
      v33 = v28.m128_f32[0] * v31;
      v34 = v29 * v31;
      v35 = v27 * v31;
      v36 = result->z;
      v37 = (float)((float)((float)(v16->y - v32) * v33) + (float)((float)(v16->x - result->x) * v35))
          + (float)((float)(v16->z - v36) * v34);
      if ( v37 <= 0.0 )
      {
        if ( v37 >= 0.0 )
          v21 = 0.0;
        else
          v21 = FLOAT_N1_0;
      }
      v38 = (float)(v35 * (float)(v21 * v23)) + result->x;
      y_low = (__m128)LODWORD(v16->y);
      v39 = (float)(v33 * (float)(v21 * v23)) + v32;
      v42 = (__m128)LODWORD(v16->x);
      y_low.m128_f32[0] = y_low.m128_f32[0] - v39;
      v41 = (float)(v34 * (float)(v21 * v23)) + v36;
      v44 = y_low;
      v42.m128_f32[0] = v42.m128_f32[0] - v38;
      v43 = v16->z - v41;
      v44.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                              + (float)(v42.m128_f32[0] * v42.m128_f32[0]))
                      + (float)(v43 * v43);
      v45 = v44;
      v45.m128_f32[0] = v44.m128_f32[0] - v66;
      if ( (float)(v44.m128_f32[0] - v66) >= 0.001 )
      {
        v45.m128_f32[0] = v45.m128_f32[0] / v44.m128_f32[0];
        v51 = v42;
        v52 = _mm_sqrt_ps(v45).m128_f32[0];
        v51.m128_f32[0] = (float)(v42.m128_f32[0] * UFG::qVector3::msDirUp.z) - (float)(v43 * UFG::qVector3::msDirUp.x);
        v53 = v51;
        v54 = (float)(v43 * UFG::qVector3::msDirUp.y) - (float)(y_low.m128_f32[0] * UFG::qVector3::msDirUp.z);
        v55 = (float)(y_low.m128_f32[0] * UFG::qVector3::msDirUp.x)
            - (float)(v42.m128_f32[0] * UFG::qVector3::msDirUp.y);
        v53.m128_f32[0] = (float)((float)(v51.m128_f32[0] * v51.m128_f32[0]) + (float)(v54 * v54)) + (float)(v55 * v55);
        v56 = (float)(v23 / v52) / _mm_sqrt_ps(v53).m128_f32[0];
        v57 = (float)(v39 + (float)((float)(v51.m128_f32[0] * v56) * v21)) - v16->y;
        v58 = (float)(v41 + (float)((float)(v55 * v56) * v21)) - v16->z;
        ray.x = (float)(v38 + (float)((float)(v54 * v56) * v21)) - v16->x;
        ray.y = v57;
        ray.z = v58;
        v59 = (float)(v57 * v52) + v16->y;
        v60 = (float)(v58 * v52) + v16->z;
        result->x = (float)(ray.x * v52) + v16->x;
        result->y = v59;
        result->z = v60;
      }
      else
      {
        if ( v44.m128_f32[0] < 0.001 )
        {
          y_low = (__m128)LODWORD(result->y);
          v42.m128_f32[0] = result->x - v38;
          y_low.m128_f32[0] = y_low.m128_f32[0] - v39;
          v43 = result->z - v41;
        }
        v46 = y_low;
        v46.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                                + (float)(v42.m128_f32[0] * v42.m128_f32[0]))
                        + (float)(v43 * v43);
        v47 = v23 / _mm_sqrt_ps(v46).m128_f32[0];
        v48 = y_low.m128_f32[0] * v47;
        v49 = v43 * v47;
        v50 = v42.m128_f32[0] * v47;
        result->y = v48 + v39;
        result->z = v49 + v41;
        ray.x = (float)((float)(v49 * v24) - (float)(v48 * v25)) * v21;
        result->x = v50 + v38;
        ray.y = (float)((float)(v50 * v25) - (float)(v49 * x)) * v21;
        ray.z = (float)((float)(v48 * x) - (float)(v50 * v24)) * v21;
      }
    }
    v61 = UFG::RoadSpaceComponent::SteerTo(&resulta, v16, steerToDistance, result, &ray);
    v62 = v61->y;
    v63 = v61->z;
    result->x = v61->x;
    result->y = v62;
    result->z = v63;
  }
  return result;
}

// File Line: 965
// RVA: 0x64F8C0
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::GetSteerTo(
        UFG::RoadSpaceComponent *this,
        UFG::qVector3 *result,
        UFG::qVector3 *steer_to,
        float offset,
        float steer_to_distance)
{
  float x; // xmm0_4
  float y; // xmm1_4
  bool v7; // bp
  float z; // xmm2_4
  UFG::qVector3 *SteerToFollow; // rax
  UFG::NavPath *m_pNavPath; // rax
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  UFG::qVector2 *TargetLocation; // rax
  UFG::RoadNetworkLane *v19; // rdi
  float v20; // xmm6_4
  float Length; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm5_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-38h] BYREF

  x = UFG::qVector3::msZero.x;
  y = UFG::qVector3::msZero.y;
  v7 = this->m_pChaseTarget.m_pPointer != 0i64;
  z = UFG::qVector3::msZero.z;
  if ( this->m_pChaseTarget.m_pPointer )
  {
    SteerToFollow = UFG::RoadSpaceComponent::GetSteerToFollow(this, &resulta, steer_to_distance);
    x = SteerToFollow->x;
    y = SteerToFollow->y;
    z = SteerToFollow->z;
  }
  if ( this->m_NavGuideEnabled && this->m_NavGuide.m_Active )
  {
    m_pNavPath = this->m_NavGuide.m_PathQueryOutput.m_pPath.m_pNavPath;
    if ( m_pNavPath && m_pNavPath->m_aWaypoints.size )
    {
      UFG::RoadSpaceComponent::GetSteerToNavPath(this, &resulta, steer_to, steer_to_distance);
      v14 = resulta.y;
      result->x = resulta.x;
      v15 = resulta.z;
      result->y = v14;
      result->z = v15;
      return result;
    }
    if ( this->m_HasNavWanderCenter )
    {
      UFG::RoadSpaceComponent::GetSteerToNavWanderDestination(this, &resulta, steer_to, steer_to_distance);
      v16 = resulta.y;
      result->x = resulta.x;
      v17 = resulta.z;
      result->y = v16;
      result->z = v17;
      return result;
    }
LABEL_27:
    result->x = steer_to->x;
    result->y = steer_to->y;
    result->z = steer_to->z;
    return result;
  }
  if ( !this->mGuide.m_Attached )
  {
    if ( v7 )
    {
      result->x = x;
      result->y = y;
      result->z = z;
      return result;
    }
    goto LABEL_27;
  }
  TargetLocation = UFG::RoadNetworkGuide::GetTargetLocation((UFG::RippleGenerator *)&this->mGuide);
  v19 = (UFG::RoadNetworkLane *)TargetLocation[1];
  v20 = TargetLocation->x;
  Length = UFG::RoadNetworkLane::GetLength(v19);
  v22 = 0.0;
  if ( Length > 0.0 )
  {
    v22 = 10.0 / Length;
    if ( (float)(10.0 / Length) > 0.5 )
      v22 = FLOAT_0_5;
  }
  if ( v20 >= 0.5 )
  {
    v23 = 1.0 - v20;
    if ( (float)(1.0 - v20) < 0.0 )
      v23 = 0.0;
  }
  else
  {
    v23 = v20;
  }
  v24 = FLOAT_0_000099999997;
  if ( v22 >= 0.000099999997 )
    v24 = v22;
  v25 = v23 * (float)(1.0 / v24);
  if ( v25 <= 0.0 )
  {
    v25 = 0.0;
  }
  else if ( v25 >= 1.0 )
  {
    v25 = *(float *)&FLOAT_1_0;
  }
  UFG::RoadNetworkLane::GetOffsetPos(v19, &resulta, v20, offset - (float)((float)(1.0 - v25) * v19->mOffset));
  v26 = resulta.y;
  result->x = resulta.x;
  v27 = resulta.z;
  result->y = v26;
  result->z = v27;
  return result;
}

// File Line: 1019
// RVA: 0x651A40
_BOOL8 __fastcall UFG::RoadSpaceComponent::IsAttachedToRoadNetwork(UFG::RoadSpaceComponent *this)
{
  return this->mGuide.m_Attached;
}

// File Line: 1025
// RVA: 0x64C020
void __fastcall UFG::RoadSpaceComponent::DetachFromRoadNetwork(UFG::RoadSpaceComponent *this)
{
  UFG::RoadNetworkGuide::RemoveFromNetwork(&this->mGuide);
}

// File Line: 1031
// RVA: 0x652860
void __fastcall UFG::RoadSpaceComponent::MoveCarToRoadNetworkPosition(
        UFG::RoadSpaceComponent *this,
        UFG::RoadNetworkLocation *location,
        bool snapToGround)
{
  UFG::allocator::free_link *v5; // rax
  UFG::qVector3 position; // [rsp+48h] [rbp-40h] BYREF
  UFG::qVector3 out; // [rsp+58h] [rbp-30h] BYREF
  UFG::qVector3 dir; // [rsp+68h] [rbp-20h] BYREF

  UFG::RoadNetworkLocation::GetVectors(location, &position, &dir);
  out = position;
  if ( snapToGround )
  {
    position.z = position.z + 0.5;
    UFG::SimObjectUtility::PlaceOnGround(&out, &position, 0.050000001, 6.0);
  }
  v5 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
  if ( v5 )
    UFG::TeleportEvent::TeleportEvent(
      (UFG::TeleportEvent *)v5,
      &out,
      &dir,
      this->m_pSimObject->mNode.mUID,
      0,
      UFG::TeleportEvent::m_Name,
      &UFG::qVector3::msDirUp);
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v5);
}

// File Line: 1051
// RVA: 0x6586A0
void __fastcall UFG::RoadSpaceComponent::SetCarDestination(
        UFG::RoadSpaceComponent *this,
        UFG::TransformNodeComponent *xform)
{
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float y; // xmm0_4
  float z; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4

  if ( xform )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(xform);
    y = xform->mWorldTransform.v3.y;
    z = xform->mWorldTransform.v3.z;
    this->mDestinationPosition.x = xform->mWorldTransform.v3.x;
    this->mDestinationPosition.y = y;
    this->mDestinationPosition.z = z;
    UFG::TransformNodeComponent::UpdateWorldTransform(xform);
    v10 = xform->mWorldTransform.v0.y;
    v11 = xform->mWorldTransform.v0.z;
    this->mDestinationDirection.x = xform->mWorldTransform.v0.x;
    this->mDestinationDirection.y = v10;
    this->mDestinationDirection.z = v11;
  }
  else
  {
    v4 = UFG::qVector3::msZero.y;
    v5 = UFG::qVector3::msZero.z;
    this->mDestinationPosition.x = UFG::qVector3::msZero.x;
    this->mDestinationPosition.y = v4;
    this->mDestinationPosition.z = v5;
    v6 = UFG::qVector3::msZero.y;
    v7 = UFG::qVector3::msZero.z;
    this->mDestinationDirection.x = UFG::qVector3::msZero.x;
    this->mDestinationDirection.y = v6;
    this->mDestinationDirection.z = v7;
  }
}

// File Line: 1065
// RVA: 0x6585F0
void __fastcall UFG::RoadSpaceComponent::SetCarDestination(UFG::RoadSpaceComponent *this, UFG::qMatrix44 *matrix)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float y; // xmm0_4
  float z; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4

  if ( matrix )
  {
    y = matrix->v3.y;
    z = matrix->v3.z;
    this->mDestinationPosition.x = matrix->v3.x;
    this->mDestinationPosition.y = y;
    this->mDestinationPosition.z = z;
    v8 = matrix->v0.y;
    v9 = matrix->v0.z;
    this->mDestinationDirection.x = matrix->v0.x;
    this->mDestinationDirection.y = v8;
    this->mDestinationDirection.z = v9;
  }
  else
  {
    v2 = UFG::qVector3::msZero.y;
    v3 = UFG::qVector3::msZero.z;
    this->mDestinationPosition.x = UFG::qVector3::msZero.x;
    this->mDestinationPosition.y = v2;
    this->mDestinationPosition.z = v3;
    v4 = UFG::qVector3::msZero.y;
    v5 = UFG::qVector3::msZero.z;
    this->mDestinationDirection.x = UFG::qVector3::msZero.x;
    this->mDestinationDirection.y = v4;
    this->mDestinationDirection.z = v5;
  }
}

// File Line: 1085
// RVA: 0x6588B0
void __fastcall UFG::RoadSpaceComponent::SetChaseTarget(UFG::RoadSpaceComponent *this, UFG::SimObjectVehicle *target)
{
  UFG::SimObjectVehicle *m_pPointer; // rcx
  __int16 v5; // r8
  UFG::VehicleSubjectComponent *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pChaseTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimObjectVehicle *v12; // rcx
  __int16 v13; // dx
  UFG::VehicleSubjectComponent *ComponentOfType; // rax
  UFG::SimObjectGame *v15; // rcx
  __int16 v16; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::SimComponent *v20; // rax
  UFG::SimComponent *v21; // rsi
  UFG::SimObject *v22; // rdx
  __int16 m_Flags; // cx
  unsigned int v24; // edi
  UFG::qVector3 result; // [rsp+38h] [rbp-40h] BYREF
  UFG::SimObjectModifier v26; // [rsp+48h] [rbp-30h] BYREF

  m_pPointer = (UFG::SimObjectVehicle *)this->m_pChaseTarget.m_pPointer;
  if ( m_pPointer != target )
  {
    if ( !m_pPointer )
    {
LABEL_13:
      p_m_pChaseTarget = &this->m_pChaseTarget;
      if ( this->m_pChaseTarget.m_pPointer )
      {
        mPrev = p_m_pChaseTarget->mPrev;
        mNext = this->m_pChaseTarget.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_m_pChaseTarget->mPrev = p_m_pChaseTarget;
        this->m_pChaseTarget.mNext = &this->m_pChaseTarget;
      }
      this->m_pChaseTarget.m_pPointer = target;
      if ( target )
      {
        v10 = target->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v10->mNext = p_m_pChaseTarget;
        p_m_pChaseTarget->mPrev = v10;
        this->m_pChaseTarget.mNext = &target->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        target->m_SafePointerList.UFG::SimObjectCVBase::UFG::SimObjectGame::UFG::SimObject::UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pChaseTarget;
      }
      if ( !this->m_pChaseTarget.m_pPointer )
        goto LABEL_50;
      m_pSimObject = this->m_pSimObject;
      if ( m_pSimObject && m_pSimObject->m_pTransformNodeComponent )
        UFG::RoadSpaceComponent::GetSteerToFollow(this, &result, 0.0);
      v12 = (UFG::SimObjectVehicle *)this->m_pChaseTarget.m_pPointer;
      if ( !v12 )
      {
LABEL_32:
        v15 = (UFG::SimObjectGame *)this->m_pChaseTarget.m_pPointer;
        if ( !v15
          || ((v16 = v15->m_Flags, (v16 & 0x4000) == 0)
            ? (v16 >= 0
             ? ((v16 & 0x2000) != 0 || (v16 & 0x1000) != 0
              ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::RoadSpaceComponent::_TypeUID))
              : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v15, UFG::RoadSpaceComponent::_TypeUID)))
             : (ComponentOfTypeHK = v15->m_Components.p[24].m_pComponent))
            : (ComponentOfTypeHK = v15->m_Components.p[24].m_pComponent),
              !ComponentOfTypeHK) )
        {
          SimulationMemoryPool = UFG::GetSimulationMemoryPool();
          v19 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x7A0ui64, "RoadSpaceComponent", 0i64, 1u);
          if ( v19 )
          {
            UFG::RoadSpaceComponent::RoadSpaceComponent((UFG::RoadSpaceComponent *)v19);
            v21 = v20;
          }
          else
          {
            v21 = 0i64;
          }
          v22 = this->m_pChaseTarget.m_pPointer;
          m_Flags = v22->m_Flags;
          if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
            v24 = 24;
          else
            v24 = -1;
          UFG::SimObjectModifier::SimObjectModifier(&v26, v22, 1);
          UFG::SimObjectModifier::AttachComponent(&v26, v21, v24);
          UFG::SimObjectModifier::Close(&v26);
          UFG::SimObjectModifier::~SimObjectModifier(&v26);
          v21[30].m_TypeUID |= 1u;
        }
LABEL_50:
        this->m_fChaseFailedTimer = 0.0;
        return;
      }
      v13 = v12->m_Flags;
      if ( (v13 & 0x4000) != 0 )
        goto LABEL_28;
      if ( v13 < 0 )
      {
        ComponentOfType = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v12);
        goto LABEL_30;
      }
      if ( (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
LABEL_28:
        ComponentOfType = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v12,
                                                            UFG::VehicleSubjectComponent::_TypeUID);
      else
        ComponentOfType = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                            v12,
                                                            UFG::VehicleSubjectComponent::_TypeUID);
LABEL_30:
      if ( ComponentOfType )
        UFG::VehicleSubjectComponent::AddChaser(ComponentOfType, this->m_pSimObject);
      goto LABEL_32;
    }
    v5 = m_pPointer->m_Flags;
    if ( (v5 & 0x4000) != 0 )
      goto LABEL_4;
    if ( v5 >= 0 )
    {
      if ( (v5 & 0x2000) != 0 || (v5 & 0x1000) != 0 )
      {
LABEL_4:
        v6 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               m_pPointer,
                                               UFG::VehicleSubjectComponent::_TypeUID);
        goto LABEL_11;
      }
      v6 = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                             m_pPointer,
                                             UFG::VehicleSubjectComponent::_TypeUID);
    }
    else
    {
      v6 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(m_pPointer);
    }
LABEL_11:
    if ( v6 )
      UFG::VehicleSubjectComponent::RemoveChaser(v6, this->m_pSimObject);
    goto LABEL_13;
  }
}

// File Line: 1123
// RVA: 0x662840
void __fastcall UFG::RoadSpaceComponent::UpdateNavGuide(UFG::RoadSpaceComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  float v3; // xmm6_4
  __int16 m_Flags; // dx
  UFG::PhysicsMoverInterface *m_pComponent; // rax
  __m128 x_low; // xmm1
  __m128 y_low; // xmm2
  float v8; // xmm3_4
  float v9; // xmm6_4
  UFG::qVector3 max; // [rsp+20h] [rbp-38h] BYREF
  UFG::qVector3 min; // [rsp+30h] [rbp-28h] BYREF

  if ( this->m_NavGuide.m_Initialized )
    goto LABEL_15;
  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  v3 = FLOAT_2_0;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) == 0 )
    {
      if ( m_Flags < 0 )
      {
        m_pComponent = (UFG::PhysicsMoverInterface *)m_pSimObject->m_Components.p[34].m_pComponent;
        goto LABEL_10;
      }
      if ( (m_Flags & 0x2000) == 0 )
      {
        if ( (m_Flags & 0x1000) != 0 )
          m_pComponent = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pSimObject,
                                                         UFG::PhysicsMoverInterface::_TypeUID);
        else
          m_pComponent = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                         m_pSimObject,
                                                         UFG::PhysicsMoverInterface::_TypeUID);
LABEL_10:
        if ( m_pComponent )
        {
          UFG::PhysicsMoverInterface::GetBoundingBoxLocalSpace(m_pComponent, &min, &max);
          x_low = (__m128)LODWORD(max.x);
          y_low = (__m128)LODWORD(min.y);
          x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(max.y * max.y);
          v8 = _mm_sqrt_ps(x_low).m128_f32[0];
          y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(min.x * min.x);
          v9 = _mm_sqrt_ps(y_low).m128_f32[0];
          if ( v9 <= v8 )
            v9 = v8;
          v3 = v9 + 0.5;
        }
      }
    }
  }
  this->m_NavGuide.m_NavParams.m_fRadius = v3;
  this->m_NavGuide.m_Initialized = 1;
LABEL_15:
  if ( this->m_NavGuide.m_Active )
    UFG::NavGuide::UpdatePathQuery(&this->m_NavGuide);
}

// File Line: 1150
// RVA: 0x6603A0
void __fastcall UFG::RoadSpaceComponent::UpdateChaseMatrix(UFG::RoadSpaceComponent *this)
{
  UFG::SimObject *m_pSimObject; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::SimComponent *m_pSimComponent; // rcx
  float v7; // xmm1_4
  float *v8; // rax
  float v9; // xmm7_4
  __m128 v10; // xmm6
  float v11; // xmm3_4
  __m128 v12; // xmm2
  float v13; // xmm1_4
  float x; // xmm6_4
  float v15; // xmm7_4
  UFG::VehicleFormations *m_pChaseFormation; // rax
  UFG::RoadNetworkNode *mpClosestSegment; // rcx
  UFG::RoadNetworkLane *Lane; // rdi
  float Length; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  UFG::RoadNetworkNode *v22; // rcx
  float v23; // xmm0_4
  int x_low; // xmm6_4
  int y_low; // xmm7_4
  int z_low; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  UFG::SimObjectVehicle *v29; // rcx
  __int16 m_Flags; // dx
  UFG::VehicleSubjectComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v32; // rcx
  __int16 v33; // dx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObjectVehicle *CurrentVehicle; // rax
  UFG::VehicleSubjectComponent *v36; // rax
  __m128 v37; // xmm1
  float v38; // xmm1_4
  float v39; // xmm12_4
  float v40; // xmm11_4
  float v41; // xmm10_4
  float v42; // xmm2_4
  float v43; // xmm9_4
  float v44; // xmm3_4
  float v45; // xmm1_4
  float v46; // xmm12_4
  float v47; // xmm10_4
  float v48; // xmm11_4
  UFG::qVector3 v1; // [rsp+18h] [rbp-59h] BYREF
  UFG::qVector3 pos; // [rsp+28h] [rbp-49h] BYREF
  UFG::qVector3 v2; // [rsp+38h] [rbp-39h] BYREF
  UFG::qVector3 result; // [rsp+48h] [rbp-29h] BYREF
  void *retaddr; // [rsp+D8h] [rbp+67h] BYREF

  m_pSimObject = this->m_pSimObject;
  if ( !m_pSimObject )
    return;
  m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  if ( !m_pTransformNodeComponent || !this->m_pSubject.m_pSimComponent )
    return;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y = m_pTransformNodeComponent->mWorldTransform.v3.y;
  pos.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  z = m_pTransformNodeComponent->mWorldTransform.v3.z;
  pos.y = y;
  pos.z = z;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  m_pSimComponent = this->m_pSubject.m_pSimComponent;
  v7 = m_pTransformNodeComponent->mWorldTransform.v0.y;
  v1.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
  v1.z = m_pTransformNodeComponent->mWorldTransform.v0.z;
  v1.y = v7;
  v8 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pSimComponent->vfptr[20].__vecDelDtor)(m_pSimComponent);
  v9 = v8[1];
  v10 = (__m128)*(unsigned int *)v8;
  v11 = v8[2];
  v12 = v10;
  v12.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v9 * v9)) + (float)(v11 * v11);
  if ( v12.m128_f32[0] <= 0.25 )
  {
    v15 = v1.y;
    x = v1.x;
  }
  else
  {
    if ( v12.m128_f32[0] == 0.0 )
      v13 = 0.0;
    else
      v13 = 1.0 / _mm_sqrt_ps(v12).m128_f32[0];
    x = v10.m128_f32[0] * v13;
    v15 = v9 * v13;
    v1.x = x;
    v1.y = v15;
    v1.z = v11 * v13;
  }
  m_pChaseFormation = this->m_pChaseFormation;
  if ( m_pChaseFormation )
  {
    if ( UFG::gpRoadNetworkResource )
    {
      mpClosestSegment = m_pChaseFormation->mpClosestSegment;
      if ( mpClosestSegment )
      {
        Lane = UFG::RoadNetworkNode::GetLane(mpClosestSegment, m_pChaseFormation->mClosestLaneIndex);
        UFG::RoadNetworkLane::GetNearestPoint(Lane, &result, &pos, (float *)&retaddr);
        Length = UFG::RoadNetworkLane::GetLength(Lane);
        v20 = Length - 0.5;
        v21 = Length * 0.0;
        if ( v20 < 0.0 )
          v20 = 0.0;
        if ( v21 < 0.5 || v21 > v20 )
        {
          v15 = v1.y;
          x = v1.x;
        }
        else
        {
          if ( Lane->mNode.mOffset )
            v22 = (UFG::RoadNetworkNode *)((char *)Lane + Lane->mNode.mOffset);
          else
            v22 = 0i64;
          UFG::RoadNetworkNode::GetTangent(v22, &v2, Lane->mLaneIndex, 0.0);
          pos.x = result.x + (float)((float)(pos.x - result.x) * 0.60000002);
          pos.y = result.y + (float)((float)(pos.y - result.y) * 0.60000002);
          pos.z = result.z + (float)((float)(pos.z - result.z) * 0.60000002);
          v23 = UFG::qAngleBetween(&v1, &v2);
          x_low = SLODWORD(v2.x);
          y_low = SLODWORD(v2.y);
          z_low = SLODWORD(v2.z);
          if ( v23 > 1.5707964 )
          {
            x_low = LODWORD(v2.x) ^ _xmm[0];
            y_low = LODWORD(v2.y) ^ _xmm[0];
            z_low = LODWORD(v2.z) ^ _xmm[0];
          }
          v27 = (float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)(*(float *)&y_low * *(float *)&y_low))
              + (float)(*(float *)&z_low * *(float *)&z_low);
          if ( v27 == 0.0 )
            v28 = 0.0;
          else
            v28 = 1.0 / fsqrt(v27);
          x = *(float *)&x_low * v28;
          v15 = *(float *)&y_low * v28;
          v1.x = x;
          v1.y = v15;
          v1.z = *(float *)&z_low * v28;
        }
      }
    }
  }
  v29 = (UFG::SimObjectVehicle *)this->m_pSimObject;
  if ( !v29 )
    goto LABEL_39;
  m_Flags = v29->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_34;
  if ( m_Flags < 0 )
  {
    ComponentOfTypeHK = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v29);
    goto LABEL_36;
  }
  if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_34:
    ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v29,
                                                          UFG::VehicleSubjectComponent::_TypeUID);
  else
    ComponentOfTypeHK = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                          v29,
                                                          UFG::VehicleSubjectComponent::_TypeUID);
LABEL_36:
  if ( ComponentOfTypeHK && UFG::VehicleSubjectComponent::IsBoat(ComponentOfTypeHK) )
  {
LABEL_53:
    x = v1.x;
    v15 = v1.y;
    if ( (float)((float)((float)((float)(v1.x - (float)(v1.z * 0.0)) * (float)(v1.x - (float)(v1.z * 0.0)))
                       + (float)((float)((float)(v1.z * 0.0) - v1.y) * (float)((float)(v1.z * 0.0) - v1.y)))
               + (float)((float)((float)(v1.y * 0.0) - (float)(v1.x * 0.0))
                       * (float)((float)(v1.y * 0.0) - (float)(v1.x * 0.0)))) > 0.0000000099999991 )
    {
      v37 = (__m128)LODWORD(v1.y);
      v37.m128_f32[0] = (float)(v1.y * v1.y) + (float)(v1.x * v1.x);
      if ( v37.m128_f32[0] == 0.0 )
        v38 = 0.0;
      else
        v38 = 1.0 / _mm_sqrt_ps(v37).m128_f32[0];
      x = v1.x * v38;
      v15 = v1.y * v38;
      v1.z = v38 * 0.0;
      v1.x = v1.x * v38;
      v1.y = v1.y * v38;
    }
    goto LABEL_59;
  }
  v15 = v1.y;
  x = v1.x;
LABEL_39:
  v32 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( !v32 )
    goto LABEL_59;
  v33 = v32->m_Flags;
  if ( (v33 & 0x4000) != 0 )
  {
    m_pComponent = (UFG::CharacterOccupantComponent *)v32->m_Components.p[44].m_pComponent;
  }
  else
  {
    m_pComponent = (UFG::CharacterOccupantComponent *)(v33 < 0 || (v33 & 0x2000) != 0 || (v33 & 0x1000) != 0
                                                     ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v32,
                                                         UFG::CharacterOccupantComponent::_TypeUID)
                                                     : UFG::SimObject::GetComponentOfType(
                                                         v32,
                                                         UFG::CharacterOccupantComponent::_TypeUID));
    x = v1.x;
    v15 = v1.y;
  }
  if ( !m_pComponent )
    goto LABEL_59;
  CurrentVehicle = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
  if ( CurrentVehicle )
  {
    v36 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(CurrentVehicle);
    if ( v36 )
    {
      if ( UFG::VehicleSubjectComponent::IsBoat(v36) )
        goto LABEL_53;
    }
  }
  v15 = v1.y;
  x = v1.x;
LABEL_59:
  v39 = x - (float)(v1.z * 0.0);
  v40 = (float)(v1.z * 0.0) - v15;
  v41 = (float)(v15 * 0.0) - (float)(x * 0.0);
  v42 = (float)((float)(v39 * v39) + (float)(v40 * v40)) + (float)(v41 * v41);
  if ( v42 == 0.0 )
    v43 = 0.0;
  else
    v43 = 1.0 / fsqrt(v42);
  v44 = v1.z;
  v45 = pos.y;
  this->m_ChaseWorld.v3.w = 1.0;
  v46 = v39 * v43;
  v47 = v41 * v43;
  this->m_ChaseWorld.v3.y = v45;
  v48 = v40 * v43;
  this->m_ChaseWorld.v3.x = pos.x;
  this->m_ChaseWorld.v3.z = pos.z;
  this->m_ChaseWorld.v0.x = x;
  this->m_ChaseWorld.v0.y = v15;
  this->m_ChaseWorld.v0.w = 0.0;
  this->m_ChaseWorld.v0.z = v44;
  this->m_ChaseWorld.v1.x = v48;
  this->m_ChaseWorld.v1.y = v46;
  this->m_ChaseWorld.v1.w = 0.0;
  this->m_ChaseWorld.v1.z = v47;
  this->m_ChaseWorld.v2.x = (float)(v47 * v15) - (float)(v46 * v44);
  this->m_ChaseWorld.v2.y = (float)(v48 * v44) - (float)(v47 * x);
  this->m_ChaseWorld.v2.w = 0.0;
  this->m_ChaseWorld.v2.z = (float)(v46 * x) - (float)(v48 * v15);
  UFG::qInverseAffine(&this->m_WorldChase, &this->m_ChaseWorld);
}

// File Line: 1258
// RVA: 0x64D7A0
UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *__fastcall UFG::RoadSpaceComponent::GetCarChaseTargetFormation(
        UFG::RoadSpaceComponent *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pChaseTarget.m_pPointer;
  if ( m_pPointer
    && ((m_Flags = m_pPointer->m_Flags, (m_Flags & 0x4000) == 0)
      ? (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RoadSpaceComponent::_TypeUID))
        : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RoadSpaceComponent::_TypeUID)))
       : (ComponentOfTypeHK = m_pPointer->m_Components.p[24].m_pComponent))
      : (ComponentOfTypeHK = m_pPointer->m_Components.p[24].m_pComponent),
        ComponentOfTypeHK) )
  {
    return ComponentOfTypeHK[26].m_BoundComponentHandles.mNode.mPrev;
  }
  else
  {
    return 0i64;
  }
}

// File Line: 1277
// RVA: 0x6663F0
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::WorldToChase(
        UFG::RoadSpaceComponent *this,
        UFG::qVector3 *result,
        UFG::qVector3 *position)
{
  float v6; // xmm6_4
  float fCurvature; // xmm0_4
  float x; // xmm5_4
  float y; // xmm4_4
  float v10; // xmm3_4
  float v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  __m128 y_low; // xmm2
  float v17; // xmm1_4
  float v18; // xmm0_4
  float z; // xmm4_4
  float v20; // xmm2_4
  float v21; // xmm6_4
  float v22; // xmm6_4
  UFG::qVector3 b; // [rsp+20h] [rbp-48h] BYREF
  UFG::qVector3 a; // [rsp+30h] [rbp-38h] BYREF

  if ( this->m_PositionTrail.mTrail.mCount <= 0 )
    goto LABEL_13;
  v6 = FLOAT_N1_0;
  fCurvature = this->m_PositionTrail.mTrail.mData[this->m_PositionTrail.mTrail.mLast].fCurvature;
  if ( fCurvature <= -1.0 )
  {
    fCurvature = FLOAT_N1_0;
    goto LABEL_6;
  }
  if ( fCurvature < 1.0 )
  {
LABEL_6:
    if ( fCurvature < -0.0099999998 || fCurvature > 0.0099999998 )
    {
      if ( fCurvature <= 0.0 )
      {
        if ( fCurvature >= 0.0 )
          v6 = 0.0;
      }
      else
      {
        v6 = *(float *)&FLOAT_1_0;
      }
      goto LABEL_12;
    }
LABEL_13:
    z = position->z;
    v20 = (float)(position->x * this->m_WorldChase.v0.y) + (float)(position->y * this->m_WorldChase.v1.y);
    v21 = (float)(position->x * this->m_WorldChase.v0.z) + (float)(position->y * this->m_WorldChase.v1.z);
    result->x = (float)((float)((float)(position->y * this->m_WorldChase.v1.x)
                              + (float)(position->x * this->m_WorldChase.v0.x))
                      + (float)(z * this->m_WorldChase.v2.x))
              + this->m_WorldChase.v3.x;
    v22 = (float)(v21 + (float)(z * this->m_WorldChase.v2.z)) + this->m_WorldChase.v3.z;
    result->y = (float)(v20 + (float)(z * this->m_WorldChase.v2.y)) + this->m_WorldChase.v3.y;
    result->z = v22;
    return result;
  }
  fCurvature = *(float *)&FLOAT_1_0;
  v6 = *(float *)&FLOAT_1_0;
LABEL_12:
  x = this->m_ChaseWorld.v1.x;
  y = this->m_ChaseWorld.v1.y;
  v10 = this->m_ChaseWorld.v1.z;
  v11 = 1.0 / fCurvature;
  v12 = (float)(x * (float)(1.0 / fCurvature)) + this->m_ChaseWorld.v3.x;
  v13 = (float)((float)(y * (float)(1.0 / fCurvature)) + this->m_ChaseWorld.v3.y) - position->y;
  v14 = (float)((float)(v10 * v11) + this->m_ChaseWorld.v3.z) - position->z;
  b.x = v12 - position->x;
  b.y = v13;
  b.z = v14;
  a.x = x * v6;
  a.y = y * v6;
  a.z = v10 * v6;
  v15 = UFG::qSignedAngleBetween(&a, &b);
  y_low = (__m128)LODWORD(b.y);
  v17 = b.z;
  result->x = v15 * v11;
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(b.x * b.x)) + (float)(v17 * v17);
  v18 = position->z - this->m_ChaseWorld.v3.z;
  result->y = v11 - (float)(_mm_sqrt_ps(y_low).m128_f32[0] * v6);
  result->z = v18;
  return result;
}

// File Line: 1296
// RVA: 0x647BD0
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::ChaseToWorld(
        UFG::RoadSpaceComponent *this,
        UFG::qVector3 *result,
        UFG::qVector3 *position,
        UFG::qVector3 *p_direction)
{
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  UFG::qVector3 *v10; // rax
  float v11; // xmm2_4
  float v12; // xmm6_4
  float v13; // xmm6_4
  float v14; // xmm13_4
  float fCurvature; // xmm11_4
  float v16; // xmm6_4
  float v17; // xmm14_4
  float v18; // xmm7_4
  float v19; // xmm9_4
  float v20; // xmm10_4
  float v21; // xmm8_4
  float v22; // xmm9_4
  float v23; // xmm7_4
  float v24; // xmm15_4
  float v25; // xmm6_4
  float v26; // xmm7_4
  float v27; // xmm4_4
  float v28; // xmm6_4
  float v29; // xmm4_4
  float v30; // xmm5_4
  float v31; // xmm6_4
  float v32; // xmm2_4
  float v33; // xmm12_4
  float v34; // xmm0_4
  float v35; // xmm1_4
  float y; // xmm0_4
  float z; // xmm1_4
  float v38; // xmm4_4
  float v39; // xmm2_4
  float v40; // xmm6_4
  float v41; // xmm6_4
  float v42; // [rsp+D0h] [rbp+8h]

  if ( !this->m_pChaseFormation )
  {
    if ( this->m_PositionTrail.mTrail.mCount > 0 )
    {
      v14 = FLOAT_N1_0;
      fCurvature = this->m_PositionTrail.mTrail.mData[this->m_PositionTrail.mTrail.mLast].fCurvature;
      if ( fCurvature <= -1.0 )
      {
        fCurvature = FLOAT_N1_0;
      }
      else if ( fCurvature >= 1.0 )
      {
        fCurvature = *(float *)&FLOAT_1_0;
LABEL_12:
        v16 = fCurvature * position->x;
        v17 = 1.0 / fCurvature;
        v18 = position->y - (float)(1.0 / fCurvature);
        v19 = sinf(v16) * v18;
        v20 = v19 * this->m_ChaseWorld.v0.z;
        v21 = v19 * this->m_ChaseWorld.v0.x;
        v22 = v19 * this->m_ChaseWorld.v0.y;
        v23 = cosf(v16) * v18;
        v24 = (float)(v23 * this->m_ChaseWorld.v1.z) - v20;
        v25 = (float)(v23 * this->m_ChaseWorld.v1.y) - v22;
        v26 = (float)(v23 * this->m_ChaseWorld.v1.x) - v21;
        v42 = v25;
        if ( p_direction )
        {
          v27 = (float)(v24 * UFG::qVector3::msAxisZ.y) - (float)(v25 * UFG::qVector3::msAxisZ.z);
          v28 = (float)(v25 * UFG::qVector3::msAxisZ.x) - (float)(v26 * UFG::qVector3::msAxisZ.y);
          if ( fCurvature <= 0.0 )
          {
            if ( fCurvature >= 0.0 )
              v14 = 0.0;
          }
          else
          {
            v14 = *(float *)&FLOAT_1_0;
          }
          v29 = v27 * v14;
          v30 = (float)((float)(v26 * UFG::qVector3::msAxisZ.z) - (float)(v24 * UFG::qVector3::msAxisZ.x)) * v14;
          v31 = v28 * v14;
          v32 = (float)((float)(v30 * v30) + (float)(v29 * v29)) + (float)(v31 * v31);
          if ( v32 == 0.0 )
            v33 = 0.0;
          else
            v33 = 1.0 / fsqrt(v32);
          p_direction->z = v31 * v33;
          v25 = v42;
          p_direction->x = v29 * v33;
          p_direction->y = v30 * v33;
        }
        v34 = (float)((float)(v17 * this->m_ChaseWorld.v1.x) + this->m_ChaseWorld.v3.x) + v26;
        v35 = (float)((float)(v17 * this->m_ChaseWorld.v1.y) + this->m_ChaseWorld.v3.y) + v25;
        result->z = (float)((float)(v17 * this->m_ChaseWorld.v1.z) + this->m_ChaseWorld.v3.z) + v24;
        result->x = v34;
        result->y = v35;
        return result;
      }
      if ( fCurvature < -0.0099999998 || fCurvature > 0.0099999998 )
        goto LABEL_12;
    }
    if ( p_direction )
    {
      y = this->m_ChaseWorld.v0.y;
      z = this->m_ChaseWorld.v0.z;
      p_direction->x = this->m_ChaseWorld.v0.x;
      p_direction->y = y;
      p_direction->z = z;
    }
    v38 = position->z;
    v39 = (float)(position->y * this->m_ChaseWorld.v1.y) + (float)(position->x * this->m_ChaseWorld.v0.y);
    v40 = (float)(position->y * this->m_ChaseWorld.v1.z) + (float)(position->x * this->m_ChaseWorld.v0.z);
    result->x = (float)((float)((float)(position->y * this->m_ChaseWorld.v1.x)
                              + (float)(position->x * this->m_ChaseWorld.v0.x))
                      + (float)(v38 * this->m_ChaseWorld.v2.x))
              + this->m_ChaseWorld.v3.x;
    v41 = (float)(v40 + (float)(v38 * this->m_ChaseWorld.v2.z)) + this->m_ChaseWorld.v3.z;
    result->y = (float)(v39 + (float)(v38 * this->m_ChaseWorld.v2.y)) + this->m_ChaseWorld.v3.y;
    result->z = v41;
    return result;
  }
  if ( p_direction )
  {
    v7 = this->m_ChaseWorld.v0.y;
    v8 = this->m_ChaseWorld.v0.z;
    p_direction->x = this->m_ChaseWorld.v0.x;
    p_direction->y = v7;
    p_direction->z = v8;
  }
  v9 = position->z;
  v10 = result;
  v11 = (float)(position->y * this->m_ChaseWorld.v1.y) + (float)(position->x * this->m_ChaseWorld.v0.y);
  v12 = (float)(position->y * this->m_ChaseWorld.v1.z) + (float)(position->x * this->m_ChaseWorld.v0.z);
  result->x = (float)((float)((float)(position->y * this->m_ChaseWorld.v1.x)
                            + (float)(position->x * this->m_ChaseWorld.v0.x))
                    + (float)(v9 * this->m_ChaseWorld.v2.x))
            + this->m_ChaseWorld.v3.x;
  v13 = (float)(v12 + (float)(v9 * this->m_ChaseWorld.v2.z)) + this->m_ChaseWorld.v3.z;
  result->y = (float)(v11 + (float)(v9 * this->m_ChaseWorld.v2.y)) + this->m_ChaseWorld.v3.y;
  result->z = v13;
  return v10;
}

// File Line: 1332
// RVA: 0x65AE80
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::SteerTo(
        UFG::qVector3 *result,
        UFG::qVector3 *centre,
        float radius,
        UFG::qVector3 *point,
        UFG::qVector3 *ray)
{
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v8; // xmm9_4
  float v9; // xmm8_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  __m128 y_low; // xmm12
  float v13; // xmm13_4
  float v14; // xmm3_4
  __m128 x_low; // xmm7
  __m128 v16; // xmm14
  __m128 v17; // xmm15
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm2_4

  x = centre->x;
  y = centre->y;
  z = centre->z;
  y_low = (__m128)LODWORD(point->y);
  v8 = ray->y;
  v9 = ray->x;
  v10 = ray->z;
  v11 = point->x - centre->x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - y;
  x_low = (__m128)LODWORD(ray->x);
  v16 = y_low;
  v13 = point->z - z;
  v14 = (float)((float)(v9 * v9) + (float)(v8 * v8)) + (float)(v10 * v10);
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * v11) + (float)(v8 * y_low.m128_f32[0])) + (float)(v10 * v13);
  v17 = x_low;
  v16.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v11 * v11)) + (float)(v13 * v13);
  v17.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                  - (float)((float)(v16.m128_f32[0] - (float)(radius * radius)) * v14);
  if ( v17.m128_f32[0] < 0.0 || v14 < 0.0000099999997 )
  {
    v23 = radius / _mm_sqrt_ps(v16).m128_f32[0];
    result->z = (float)(v23 * v13) + z;
    result->x = (float)(v23 * v11) + x;
    result->y = (float)(v23 * y_low.m128_f32[0]) + y;
  }
  else
  {
    v18 = _mm_sqrt_ps(v17).m128_f32[0] * 2.0;
    v19 = 1.0 / (float)(v14 * 2.0);
    v20 = (float)(x_low.m128_f32[0] * -2.0) - v18;
    v21 = (float)(v18 - (float)(x_low.m128_f32[0] * 2.0)) * v19;
    v22 = v20 * v19;
    if ( v21 <= v22 )
      v21 = v22;
    result->x = (float)(x + v11) + (float)(v9 * v21);
    result->y = (float)(y + y_low.m128_f32[0]) + (float)(v8 * v21);
    result->z = (float)(z + v13) + (float)(v10 * v21);
  }
  return result;
}

// File Line: 1391
// RVA: 0x650740
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::GetSteerToNavPath(
        UFG::RoadSpaceComponent *this,
        UFG::qVector3 *result,
        UFG::qVector3 *defaultSteerTo,
        float steerToDist)
{
  UFG::NavPath *m_pNavPath; // r14
  unsigned int size; // esi
  unsigned int m_CurrPathPointIndex; // edi
  __int64 v8; // r12
  UFG::qVector3 *p_m_Pos; // r15
  UFG::NavWaypoint *p; // rax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qVector3 *v14; // rax
  UFG::NavGuide *p_m_NavGuide; // rbp
  float v16; // xmm8_4
  float v17; // xmm9_4
  float v18; // xmm4_4
  float v19; // xmm10_4
  float v20; // xmm5_4
  unsigned int v21; // edi
  UFG::qVector3 *PathSegmentDir; // rax
  float v23; // xmm1_4
  float v24; // xmm0_4
  UFG::NavWaypoint *v25; // rax
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  UFG::qVector3 resulta; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qVector3 ray; // [rsp+40h] [rbp-98h] BYREF
  UFG::qVector3 v32; // [rsp+50h] [rbp-88h] BYREF
  UFG::qVector3 v33; // [rsp+60h] [rbp-78h] BYREF

  m_pNavPath = this->m_NavGuide.m_PathQueryOutput.m_pPath.m_pNavPath;
  if ( m_pNavPath && (size = m_pNavPath->m_aWaypoints.size) != 0 )
  {
    m_CurrPathPointIndex = this->m_NavGuide.m_CurrPathPointIndex;
    v8 = size - 1;
    p_m_Pos = &this->m_NavGuide.m_Pos;
    if ( m_CurrPathPointIndex == (_DWORD)v8 )
    {
      p = m_pNavPath->m_aWaypoints.p;
      x = p[v8].m_navPosition.m_vPosition.x;
      y = p[v8].m_navPosition.m_vPosition.y;
      z = p[v8].m_navPosition.m_vPosition.z;
      v14 = result;
      result->x = x;
      result->y = y;
      result->z = z;
    }
    else
    {
      p_m_NavGuide = &this->m_NavGuide;
      UFG::NavGuide::GetPathSegmentPos(&this->m_NavGuide, &resulta, m_CurrPathPointIndex, &this->m_NavGuide.m_Pos);
      v16 = p_m_Pos->x;
      v17 = p_m_Pos->y;
      v18 = resulta.y;
      v19 = p_m_Pos->z;
      v20 = resulta.z;
      if ( (float)((float)((float)((float)(v17 - resulta.y) * (float)(v17 - resulta.y))
                         + (float)((float)(p_m_Pos->x - resulta.x) * (float)(p_m_Pos->x - resulta.x)))
                 + (float)((float)(v19 - resulta.z) * (float)(v19 - resulta.z))) <= (float)(steerToDist * steerToDist) )
      {
        UFG::NavGuide::GetPathSegmentDir(p_m_NavGuide, &ray, m_CurrPathPointIndex);
        v21 = m_CurrPathPointIndex + 1;
        if ( v21 >= size )
        {
LABEL_12:
          v25 = m_pNavPath->m_aWaypoints.p;
          v26 = v25[v8].m_navPosition.m_vPosition.y;
          v27 = v25[v8].m_navPosition.m_vPosition.z;
          result->x = v25[v8].m_navPosition.m_vPosition.x;
          result->y = v26;
          result->z = v27;
        }
        else
        {
          while ( 1 )
          {
            UFG::NavGuide::GetPathSegmentPos(p_m_NavGuide, &v32, v21, p_m_Pos);
            if ( (float)((float)((float)((float)(v17 - v32.y) * (float)(v17 - v32.y))
                               + (float)((float)(v16 - v32.x) * (float)(v16 - v32.x)))
                       + (float)((float)(v19 - v32.z) * (float)(v19 - v32.z))) > (float)(steerToDist * steerToDist) )
              break;
            resulta = v32;
            PathSegmentDir = UFG::NavGuide::GetPathSegmentDir(p_m_NavGuide, &v33, v21++);
            v23 = PathSegmentDir->y;
            ray.x = PathSegmentDir->x;
            v24 = PathSegmentDir->z;
            ray.y = v23;
            ray.z = v24;
            if ( v21 >= size )
              goto LABEL_12;
          }
          UFG::RoadSpaceComponent::SteerTo(&v32, p_m_Pos, steerToDist, &resulta, &ray);
          v28 = v32.y;
          result->x = v32.x;
          v29 = v32.z;
          result->y = v28;
          result->z = v29;
        }
      }
      else
      {
        result->x = resulta.x;
        result->y = v18;
        result->z = v20;
      }
      return result;
    }
  }
  else
  {
    *result = *defaultSteerTo;
    return result;
  }
  return v14;
}

// File Line: 1438
// RVA: 0x650A20
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::GetSteerToNavWanderDestination(
        UFG::RoadSpaceComponent *this,
        UFG::qVector3 *result,
        UFG::qVector3 *defaultSteerTo,
        float steerToDist)
{
  UFG::qVector3 *v7; // rsi
  __int64 v8; // rax
  float v9; // xmm2_4
  __m128 y_low; // xmm3
  float v11; // xmm4_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  __m128 v14; // xmm5
  float v15; // xmm1_4
  UFG::qVector3 ray; // [rsp+30h] [rbp-28h] BYREF

  v7 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::SimComponent *, UFG::qVector3 *, UFG::qVector3 *))this->m_pSubject.m_pSimComponent->vfptr[17].__vecDelDtor)(
                          this->m_pSubject.m_pSimComponent,
                          result,
                          defaultSteerTo);
  v8 = ((__int64 (__fastcall *)(UFG::SimComponent *))this->m_pSubject.m_pSimComponent->vfptr[16].__vecDelDtor)(this->m_pSubject.m_pSimComponent);
  y_low = (__m128)LODWORD(this->m_NavWanderDestPos.y);
  v9 = this->m_NavWanderDestPos.x - v7->x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - v7->y;
  v14 = y_low;
  v11 = this->m_NavWanderDestPos.z - v7->z;
  v12 = *(float *)(v8 + 4);
  ray.x = *(float *)v8;
  v13 = *(float *)(v8 + 8);
  ray.y = v12;
  ray.z = v13;
  v14.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v9 * v9)) + (float)(v11 * v11);
  if ( v14.m128_f32[0] > 0.0000010000001 )
  {
    v15 = 0.0;
    if ( v14.m128_f32[0] != 0.0 )
      v15 = 1.0 / _mm_sqrt_ps(v14).m128_f32[0];
    ray.x = v9 * v15;
    ray.y = y_low.m128_f32[0] * v15;
    ray.z = v11 * v15;
  }
  UFG::RoadSpaceComponent::SteerTo(result, v7, steerToDist, &this->m_NavWanderDestPos, &ray);
  return result;
}

// File Line: 1450
// RVA: 0x650130
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::GetSteerToFollow(
        UFG::RoadSpaceComponent *this,
        UFG::qVector3 *result,
        float steer_to_distance)
{
  UFG::SimObject *m_pSimObject; // rbp
  int v4; // esi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbp
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::TransformNodeComponent *v10; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qVector3 *p_m_pSimObject; // r15
  UFG::qVector3 *v15; // rax
  float x; // xmm10_4
  __m128 y_low; // xmm8
  float z; // xmm11_4
  UFG::qVector4 *v19; // rbp
  __m128 v20; // xmm2
  float v21; // xmm6_4
  float v22; // xmm0_4
  float v23; // xmm13_4
  float v24; // xmm9_4
  UFG::RingBuffer<UFG::Crumb> *p_mNext; // rbx
  int mCount; // r12d
  float v27; // xmm6_4
  int v28; // r15d
  float *p_x; // rax
  int v30; // edi
  float v31; // xmm9_4
  float v32; // xmm10_4
  float v33; // xmm8_4
  int v34; // eax
  int v35; // ecx
  __int64 v36; // rcx
  int v37; // eax
  int v38; // ecx
  int v39; // eax
  __m128 v40; // xmm2
  int v41; // eax
  int v42; // ecx
  int v43; // eax
  int v44; // ecx
  __int64 v45; // r12
  int v46; // eax
  float *v47; // r12
  int v48; // edi
  UFG::qVector3 *p_vDirection; // rax
  int v50; // eax
  int v51; // ecx
  __m128 v52; // xmm2
  float v53; // xmm8_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm0_4
  float v57; // xmm0_4
  int v58; // eax
  UFG::Crumb *p_point; // rax
  UFG::qVector3 *v60; // r9
  float v61; // xmm1_4
  __m128 v62; // xmm5
  float v63; // xmm0_4
  UFG::qVector3 *ray; // rax
  float v65; // xmm0_4
  float v66; // xmm1_4
  float v67; // xmm0_4
  float v68; // xmm0_4
  UFG::qVector3 point; // [rsp+30h] [rbp-C8h] BYREF
  UFG::qVector3 v71; // [rsp+40h] [rbp-B8h] BYREF
  float *v72; // [rsp+100h] [rbp+8h]
  UFG::qVector3 *v73; // [rsp+100h] [rbp+8h]

  m_pSimObject = this->m_pSimObject;
  v4 = 0;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  m_pPointer = (UFG::SimObjectGame *)this->m_pChaseTarget.m_pPointer;
  v10 = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    v10 = m_pPointer->m_pTransformNodeComponent;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RoadSpaceComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RoadSpaceComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[24].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_pSimObject = &UFG::qVector3::msUnity;
  if ( m_pComponent )
    p_m_pSimObject = (UFG::qVector3 *)&m_pComponent[27].m_pSimObject;
  if ( v10 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v10);
    v15 = (UFG::qVector3 *)&v10->mWorldTransform.v3;
  }
  else
  {
    v15 = &UFG::qVector3::msZero;
  }
  y_low = (__m128)LODWORD(v15->y);
  z = v15->z;
  point.x = v15->x;
  x = point.x;
  LODWORD(point.y) = y_low.m128_i32[0];
  point.z = z;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v19 = &m_pTransformNodeComponent->mWorldTransform.v3;
  v20 = (__m128)LODWORD(v19->y);
  v20.m128_f32[0] = (float)((float)((float)(v20.m128_f32[0] - y_low.m128_f32[0])
                                  * (float)(v20.m128_f32[0] - y_low.m128_f32[0]))
                          + (float)((float)(v19->x - x) * (float)(v19->x - x)))
                  + (float)((float)(v19->z - z) * (float)(v19->z - z));
  v21 = _mm_sqrt_ps(v20).m128_f32[0];
  if ( steer_to_distance <= v21 )
    v22 = v21;
  else
    v22 = steer_to_distance;
  v23 = *(float *)&FLOAT_1_0;
  this->m_fChaseDistance = v22;
  this->m_fTrailDistance = v21;
  if ( v21 >= 1.0 )
    v24 = v21;
  else
    v24 = *(float *)&FLOAT_1_0;
  this->m_fChaseCurvature = UFG::qSignedAngleBetween((UFG::qVector3 *)&this->m_ChaseWorld, p_m_pSimObject) / v24;
  if ( !m_pComponent || !v10 )
    goto LABEL_78;
  p_mNext = (UFG::RingBuffer<UFG::Crumb> *)&m_pComponent[29].m_BoundComponentHandles.mNode.mNext;
  mCount = p_mNext->mCount;
  if ( mCount > 2 )
    this->m_fChaseCurvature = p_mNext->mData[p_mNext->mLast].fCurvature;
  if ( mCount && v21 > steer_to_distance )
  {
    v27 = 0.0;
    v28 = 0;
    p_x = &p_mNext->mData[p_mNext->mLast].vPosition.x;
    v30 = 0;
    v31 = 0.0;
    y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - p_x[1]) * (float)(y_low.m128_f32[0] - p_x[1]))
                              + (float)((float)(x - *p_x) * (float)(x - *p_x)))
                      + (float)((float)(z - p_x[2]) * (float)(z - p_x[2]));
    LODWORD(v32) = _mm_sqrt_ps(y_low).m128_u32[0];
    v33 = 0.0;
    if ( mCount <= 0 )
    {
LABEL_46:
      v41 = p_mNext->mCount;
      v42 = 0;
      if ( v28 > 0 )
        v42 = v28;
      if ( v42 < v41 )
        v41 = v42;
      v43 = UFG::qSignedMod(p_mNext->mLast - v41, p_mNext->mCapacity);
      v44 = 0;
      v45 = v43;
      v46 = p_mNext->mCount;
      v47 = &p_mNext->mData[v45].vPosition.x;
      if ( v28 > 0 )
        v44 = v28;
      if ( v44 < v46 )
        v46 = v44;
      v48 = 1;
      p_vDirection = &p_mNext->mData[(int)UFG::qSignedMod(p_mNext->mLast - v46, p_mNext->mCapacity)].vDirection;
      v73 = p_vDirection;
      if ( v28 > 1 )
      {
        do
        {
          v50 = p_mNext->mCount;
          v51 = 0;
          if ( v48 > 0 )
            v51 = v48;
          if ( v51 < v50 )
            v50 = v51;
          ++v48;
          v27 = v27 + p_mNext->mData[(int)UFG::qSignedMod(p_mNext->mLast - v50, p_mNext->mCapacity)].fLength;
        }
        while ( v48 < v28 );
        p_vDirection = v73;
      }
      v52 = (__m128)LODWORD(v19->y);
      v52.m128_f32[0] = (float)((float)((float)(v52.m128_f32[0] - v47[1]) * (float)(v52.m128_f32[0] - v47[1]))
                              + (float)((float)(v19->x - *v47) * (float)(v19->x - *v47)))
                      + (float)((float)(v19->z - v47[2]) * (float)(v19->z - v47[2]));
      LODWORD(v53) = _mm_sqrt_ps(v52).m128_u32[0];
      v54 = UFG::qAngleBetween((UFG::qVector3 *)&this->m_ChaseWorld, p_vDirection);
      v55 = FLOAT_1_5707964;
      if ( v54 <= 1.5707964 )
        v55 = v54;
      if ( steer_to_distance <= v53 )
        v56 = v53;
      else
        v56 = steer_to_distance;
      v68 = v56 * 2.0;
      if ( v68 >= 1.0 )
        v23 = v68;
      ray = v73;
      this->m_fTrailDistance = v53;
      v60 = (UFG::qVector3 *)v47;
      this->m_fChaseDistance = (float)(v27 + v32) + v53;
      this->m_fChaseCurvature = v55 / v23;
    }
    else
    {
      while ( 1 )
      {
        v34 = p_mNext->mCount;
        v35 = 0;
        if ( v30 > 0 )
          v35 = v30;
        if ( v35 < v34 )
          v34 = v35;
        v36 = (int)UFG::qSignedMod(p_mNext->mLast - v34, p_mNext->mCapacity);
        v37 = p_mNext->mCount;
        v33 = v33 + p_mNext->mData[v36].fLength;
        v38 = 0;
        if ( v30 > 0 )
          v38 = v30;
        if ( v38 < v37 )
          v37 = v38;
        v39 = UFG::qSignedMod(p_mNext->mLast - v37, p_mNext->mCapacity);
        v40 = (__m128)LODWORD(v19->y);
        v72 = &p_mNext->mData[v39].vPosition.x;
        v40.m128_f32[0] = (float)((float)((float)(v40.m128_f32[0] - v72[1]) * (float)(v40.m128_f32[0] - v72[1]))
                                + (float)((float)(v19->x - *v72) * (float)(v19->x - *v72)))
                        + (float)((float)(v19->z - v72[2]) * (float)(v19->z - v72[2]));
        if ( !v30 || v40.m128_f32[0] < v31 )
        {
          v31 = v40.m128_f32[0];
          v28 = v30;
        }
        if ( v40.m128_f32[0] < (float)(steer_to_distance * steer_to_distance) )
          break;
        if ( ++v30 >= mCount )
          goto LABEL_46;
      }
      LODWORD(v57) = _mm_sqrt_ps(v40).m128_u32[0];
      if ( v30 > 0 )
        v4 = v30;
      this->m_fTrailDistance = v57;
      v58 = p_mNext->mCount;
      if ( v4 < v58 )
        v58 = v4;
      this->m_fChaseCurvature = p_mNext->mData[(int)UFG::qSignedMod(p_mNext->mLast - v58, p_mNext->mCapacity)].fCurvature;
      if ( v30 )
        p_point = UFG::RingBuffer<UFG::Crumb>::NthNewest(p_mNext, v30 - 1);
      else
        p_point = (UFG::Crumb *)&point;
      v60 = (UFG::qVector3 *)v72;
      v61 = p_point->vPosition.y - v72[1];
      v62 = (__m128)LODWORD(v19->y);
      v62.m128_f32[0] = v62.m128_f32[0] - v72[1];
      v71.x = p_point->vPosition.x - *v72;
      v63 = p_point->vPosition.z;
      ray = &v71;
      v65 = v63 - v72[2];
      v71.y = v61;
      v66 = v19->x - *v72;
      v71.z = v65;
      v67 = v19->z - v72[2];
      v62.m128_f32[0] = (float)((float)(v62.m128_f32[0] * v62.m128_f32[0]) + (float)(v66 * v66)) + (float)(v67 * v67);
      this->m_fChaseDistance = _mm_sqrt_ps(v62).m128_f32[0] + (float)(v33 + v32);
    }
    UFG::RoadSpaceComponent::SteerTo(result, (UFG::qVector3 *)v19, steer_to_distance, v60, ray);
    return result;
  }
  else
  {
LABEL_78:
    UFG::RoadSpaceComponent::SteerTo(result, (UFG::qVector3 *)v19, steer_to_distance, &point, p_m_pSimObject);
    return result;
  }
}

// File Line: 1560
// RVA: 0x649040
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::ClampToRoad(
        UFG::RoadSpaceComponent *this,
        UFG::qVector3 *result,
        UFG::qVector3 *initialPos,
        UFG::qVector3 *targetPos)
{
  UFG::qVector3 *v4; // r14
  unsigned int m_RoadNetworkType; // r8d
  UFG::qVector3 *v6; // rsi
  UFG::WheeledVehicleNavigationData *m_NavigationData; // rdx
  UFG::RoadNetworkResource *pRoadNetworkResource; // rcx
  UFG::RoadNetworkNode *v11; // rbx
  UFG::RoadNetworkIntersection *ClosestNode; // rax
  UFG::RoadNetworkNode *v13; // rcx
  unsigned int mNumLanes; // r12d
  unsigned int mNumGates; // edx
  unsigned int v16; // eax
  UFG::RoadNetworkGate *IncomingConnection; // rax
  UFG::RoadNetworkConnection *v18; // rax
  UFG::RoadNetworkConnection *v19; // r12
  unsigned int v20; // r15d
  unsigned int v21; // ebx
  UFG::RoadNetworkLane *Path; // rdi
  UFG::RoadNetworkNode *v23; // rcx
  float v24; // xmm6_4
  __m128 v25; // xmm7
  float v26; // xmm5_4
  __m128 v27; // xmm3
  float v28; // xmm1_4
  float v29; // xmm7_4
  float v30; // xmm5_4
  float v31; // xmm6_4
  float v32; // xmm4_4
  float v33; // xmm3_4
  unsigned int v34; // edx
  UFG::RoadNetworkLane *Lane; // rbx
  char IsReversedInNode; // r15
  UFG::qVector3 *NearestPoint; // rax
  float x; // xmm1_4
  float y; // xmm6_4
  float z; // xmm0_4
  float v41; // r13d
  float v42; // xmm6_4
  UFG::qVector3 *v43; // r14
  UFG::RoadNetworkLane *v44; // rbx
  char v45; // di
  UFG::qVector3 *v46; // rax
  float v47; // xmm2_4
  float v48; // eax
  unsigned int v49; // edi
  UFG::RoadNetworkLane *v50; // rax
  UFG::RoadNetworkLane *v51; // rax
  UFG::qVector3 *v52; // rax
  float v53; // xmm10_4
  float v54; // xmm11_4
  float v55; // xmm12_4
  __m128 y_low; // xmm4
  float v57; // xmm5_4
  float v58; // xmm3_4
  float v59; // xmm6_4
  UFG::RoadNetworkLane *v60; // rdi
  float v61; // xmm8_4
  __m128 x_low; // xmm9
  float v63; // xmm7_4
  __m128 v64; // xmm3
  float v65; // xmm8_4
  float v66; // xmm9_4
  float v67; // xmm7_4
  float v68; // xmm3_4
  float v69; // xmm5_4
  __m128 v70; // xmm2
  float v71; // xmm6_4
  float v72; // xmm0_4
  float v73; // xmm6_4
  float v74; // xmm3_4
  float v75; // xmm4_4
  float v76; // xmm5_4
  float v77; // xmm1_4
  float v78; // xmm2_4
  float v79; // xmm1_4
  unsigned int v80; // [rsp+30h] [rbp-D0h]
  unsigned int v81; // [rsp+30h] [rbp-D0h]
  unsigned int v82; // [rsp+34h] [rbp-CCh]
  UFG::RoadNetworkNode *v83; // [rsp+38h] [rbp-C8h]
  UFG::RoadNetworkLane *v84; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 v85; // [rsp+48h] [rbp-B8h]
  UFG::qVector3 v86; // [rsp+58h] [rbp-A8h] BYREF
  UFG::qVector3 resulta; // [rsp+68h] [rbp-98h] BYREF
  float laneT; // [rsp+140h] [rbp+40h] BYREF
  UFG::qVector3 *v89; // [rsp+148h] [rbp+48h]
  UFG::qVector3 *v90; // [rsp+150h] [rbp+50h]
  UFG::qVector3 *pos; // [rsp+158h] [rbp+58h]

  pos = targetPos;
  v90 = initialPos;
  v89 = result;
  v4 = initialPos;
  m_RoadNetworkType = this->mWayClient.m_RoadNetworkType;
  v6 = result;
  m_NavigationData = UFG::WheeledVehicleManager::m_Instance->m_NavigationData;
  if ( m_RoadNetworkType )
  {
    switch ( m_RoadNetworkType )
    {
      case 1u:
        m_NavigationData = (UFG::WheeledVehicleNavigationData *)((char *)m_NavigationData + 64);
        break;
      case 2u:
        m_NavigationData = (UFG::WheeledVehicleNavigationData *)((char *)m_NavigationData + 96);
        break;
      case 3u:
        m_NavigationData = (UFG::WheeledVehicleNavigationData *)((char *)m_NavigationData + 128);
        break;
    }
  }
  else
  {
    m_NavigationData = (UFG::WheeledVehicleNavigationData *)((char *)m_NavigationData + 32);
  }
  if ( m_NavigationData && (pRoadNetworkResource = m_NavigationData->m_RoadNetworkGraph.pRoadNetworkResource) != 0i64 )
  {
    v11 = 0i64;
    ClosestNode = UFG::RoadNetworkResource::GetClosestNode(pRoadNetworkResource, v4, m_RoadNetworkType, 0i64, 0i64);
    v13 = ClosestNode;
    v83 = ClosestNode;
    if ( ClosestNode )
    {
      mNumLanes = (unsigned __int8)ClosestNode->mNumLanes;
      if ( ClosestNode->mNumLanes
        && (mNumGates = (unsigned __int8)ClosestNode->mNumGates, v82 = mNumGates, mNumGates >= 2) )
      {
        if ( mNumGates <= 2 )
        {
          v34 = 0;
          if ( mNumLanes <= 1 )
            goto LABEL_49;
          v81 = mNumLanes - 1;
          Lane = UFG::RoadNetworkNode::GetLane(ClosestNode, 0);
          IsReversedInNode = UFG::RoadNetworkLane::IsReversedInNode(Lane);
          NearestPoint = UFG::RoadNetworkLane::GetNearestPoint(Lane, &resulta, targetPos, 0i64);
          laneT = 0.0;
          x = targetPos->x;
          y = targetPos->y;
          z = targetPos->z;
          LODWORD(v41) = 1;
          v42 = (float)((float)((float)(y - NearestPoint->y) * (float)(y - NearestPoint->y))
                      + (float)((float)(x - NearestPoint->x) * (float)(x - NearestPoint->x)))
              + (float)((float)(z - NearestPoint->z) * (float)(z - NearestPoint->z));
          v43 = pos;
          do
          {
            v44 = UFG::RoadNetworkNode::GetLane(v83, LODWORD(v41));
            v45 = UFG::RoadNetworkLane::IsReversedInNode(v44);
            v46 = UFG::RoadNetworkLane::GetNearestPoint(v44, &resulta, v43, 0i64);
            v47 = (float)((float)((float)(v43->y - v46->y) * (float)(v43->y - v46->y))
                        + (float)((float)(v43->x - v46->x) * (float)(v43->x - v46->x)))
                + (float)((float)(v43->z - v46->z) * (float)(v43->z - v46->z));
            if ( v47 >= v42 )
            {
              v48 = laneT;
            }
            else
            {
              v48 = v41;
              v42 = v47;
              laneT = v41;
            }
            if ( v45 != IsReversedInNode )
            {
              v81 = LODWORD(v41);
              IsReversedInNode = v45;
            }
            ++LODWORD(v41);
          }
          while ( LODWORD(v41) < mNumLanes );
          v6 = v89;
          v4 = v90;
          v11 = 0i64;
          if ( LODWORD(v48) >= v81 )
          {
            v34 = v81;
            v49 = mNumLanes - 1;
          }
          else
          {
            v34 = 0;
            v49 = v81 - 1;
          }
          v13 = v83;
          if ( v34 == v49 )
          {
LABEL_49:
            v59 = 0.0;
            laneT = 0.0;
            v60 = UFG::RoadNetworkNode::GetLane(v13, v34);
            UFG::RoadNetworkLane::GetNearestPoint(v60, &v86, v4, &laneT);
            if ( v60->mNode.mOffset )
              v11 = (UFG::RoadNetworkNode *)((char *)v60 + v60->mNode.mOffset);
            UFG::RoadNetworkNode::GetTangent(v11, &resulta, v60->mLaneIndex, laneT);
            x_low = (__m128)LODWORD(resulta.x);
            v61 = (float)(resulta.z * UFG::qVector3::msDirUp.y) - (float)(resulta.y * UFG::qVector3::msDirUp.z);
            x_low.m128_f32[0] = (float)(resulta.x * UFG::qVector3::msDirUp.z)
                              - (float)(resulta.z * UFG::qVector3::msDirUp.x);
            v63 = (float)(resulta.y * UFG::qVector3::msDirUp.x) - (float)(resulta.x * UFG::qVector3::msDirUp.y);
            v64 = x_low;
            v64.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v61 * v61))
                            + (float)(v63 * v63);
            if ( v64.m128_f32[0] != 0.0 )
              v59 = 1.0 / _mm_sqrt_ps(v64).m128_f32[0];
            y_low = (__m128)LODWORD(v86.y);
            v65 = v61 * v59;
            v66 = x_low.m128_f32[0] * v59;
            v67 = v63 * v59;
            v55 = v86.x + v65;
            v54 = v86.y + v66;
            v53 = v86.z + v67;
            v58 = v86.x - v65;
            y_low.m128_f32[0] = v86.y - v66;
            v57 = v86.z - v67;
          }
          else
          {
            v50 = UFG::RoadNetworkNode::GetLane(v83, v34);
            v85 = *UFG::RoadNetworkLane::GetNearestPoint(v50, &resulta, v4, 0i64);
            v51 = UFG::RoadNetworkNode::GetLane(v83, v49);
            v52 = UFG::RoadNetworkLane::GetNearestPoint(v51, &resulta, v4, 0i64);
            v53 = v85.z;
            v54 = v85.y;
            v55 = v85.x;
            y_low = (__m128)LODWORD(v52->y);
            v57 = v52->z;
            v58 = v52->x;
          }
          v68 = v58 - v55;
          y_low.m128_f32[0] = y_low.m128_f32[0] - v54;
          v69 = v57 - v53;
          v70 = y_low;
          v70.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v68 * v68))
                          + (float)(v69 * v69);
          v71 = _mm_sqrt_ps(v70).m128_f32[0];
          v72 = 1.0 / v71;
          v73 = v71 + 1.0;
          v74 = v68 * v72;
          v75 = y_low.m128_f32[0] * v72;
          v76 = v69 * v72;
          v77 = FLOAT_N1_0;
          v78 = (float)((float)((float)(v4->y - v54) * v75) + (float)((float)(v4->x - v55) * v74))
              + (float)((float)(v4->z - v53) * v76);
          if ( v78 > -1.0 )
            v77 = (float)((float)((float)(v4->y - v54) * v75) + (float)((float)(v4->x - v55) * v74))
                + (float)((float)(v4->z - v53) * v76);
          if ( v77 >= v73 )
            v77 = v73;
          v79 = v77 - v78;
          v33 = (float)(v74 * v79) + v4->x;
          v32 = (float)(v75 * v79) + v4->y;
          v6->z = (float)(v76 * v79) + v4->z;
LABEL_59:
          v6->y = v32;
          v6->x = v33;
        }
        else
        {
          v16 = 0;
          v80 = 0;
          while ( 1 )
          {
            IncomingConnection = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection(
                                                           (UFG::RoadNetworkGate *)v13,
                                                           v16);
            if ( IncomingConnection->mNumIncomingConnections )
            {
              v18 = UFG::RoadNetworkGate::GetIncomingConnection(IncomingConnection, 0);
              v19 = v18;
              v20 = v18->mNumLanes;
              if ( v18->mNumLanes )
              {
                v21 = 1;
                Path = UFG::qBezierPathCollectionMemImaged::GetPath(v18, 0);
                v84 = Path;
                if ( v20 > 1 )
                {
                  while ( 1 )
                  {
                    Path = UFG::qBezierPathCollectionMemImaged::GetPath(v19, v21);
                    if ( (unsigned int)UFG::RoadNetworkLane::GetTurnDirection(Path) == 1 )
                      break;
                    if ( ++v21 >= v20 )
                    {
                      Path = v84;
                      break;
                    }
                  }
                }
                laneT = 0.0;
                UFG::RoadNetworkLane::GetNearestPoint(Path, &resulta, v4, &laneT);
                v23 = Path->mNode.mOffset ? (UFG::RoadNetworkNode *)((char *)Path + Path->mNode.mOffset) : 0i64;
                UFG::RoadNetworkNode::GetTangent(v23, &v86, Path->mLaneIndex, laneT);
                v25 = (__m128)LODWORD(v86.x);
                v24 = (float)(v86.z * UFG::qVector3::msDirUp.y) - (float)(v86.y * UFG::qVector3::msDirUp.z);
                v25.m128_f32[0] = (float)(v86.x * UFG::qVector3::msDirUp.z) - (float)(v86.z * UFG::qVector3::msDirUp.x);
                v26 = (float)(v86.y * UFG::qVector3::msDirUp.x) - (float)(v86.x * UFG::qVector3::msDirUp.y);
                v27 = v25;
                v27.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v24 * v24))
                                + (float)(v26 * v26);
                v28 = v27.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v27).m128_f32[0];
                v29 = v25.m128_f32[0] * v28;
                v30 = v26 * v28;
                v31 = v24 * v28;
                v32 = v29 + resulta.y;
                v33 = v31 + resulta.x;
                if ( (float)((float)((float)((float)(v4->y - (float)(v29 + resulta.y)) * v29)
                                   + (float)((float)(v4->x - (float)(v31 + resulta.x)) * v31))
                           + (float)((float)(v4->z - (float)(v30 + resulta.z)) * v30)) > 0.0 )
                {
                  v6->z = v30 + resulta.z;
                  goto LABEL_59;
                }
              }
            }
            v16 = v80 + 1;
            v80 = v16;
            if ( v16 >= v82 )
              break;
            v13 = v83;
          }
          v6->x = v4->x;
          v6->y = v4->y;
          v6->z = v4->z;
        }
      }
      else
      {
        v6->x = v4->x;
        v6->y = v4->y;
        v6->z = v4->z;
      }
    }
    else
    {
      v6->x = v4->x;
      v6->y = v4->y;
      v6->z = v4->z;
    }
    return v6;
  }
  else
  {
    v6->x = v4->x;
    v6->y = v4->y;
    v6->z = v4->z;
    return v6;
  }
}

// File Line: 1709
// RVA: 0x64D630
void __fastcall UFG::RoadSpaceComponent::FlushRaceTrails(UFG::RoadSpaceComponent *this)
{
  UFG::RacePosition *m_pRacePositionSteer; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::RacePosition *m_pRacePosition; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v11; // rax

  m_pRacePositionSteer = this->m_pRacePositionSteer;
  if ( m_pRacePositionSteer )
  {
    if ( m_pRacePositionSteer->pRaceTrail.m_pPointer )
    {
      mPrev = m_pRacePositionSteer->pRaceTrail.mPrev;
      mNext = m_pRacePositionSteer->pRaceTrail.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      m_pRacePositionSteer->pRaceTrail.mPrev = &m_pRacePositionSteer->pRaceTrail;
      m_pRacePositionSteer->pRaceTrail.mNext = &m_pRacePositionSteer->pRaceTrail;
    }
    m_pRacePositionSteer->pRaceTrail.m_pPointer = 0i64;
    v5 = m_pRacePositionSteer->pRaceTrail.mPrev;
    v6 = m_pRacePositionSteer->pRaceTrail.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    m_pRacePositionSteer->pRaceTrail.mPrev = &m_pRacePositionSteer->pRaceTrail;
    m_pRacePositionSteer->pRaceTrail.mNext = &m_pRacePositionSteer->pRaceTrail;
    operator delete[](m_pRacePositionSteer);
    this->m_pRacePositionSteer = 0i64;
  }
  m_pRacePosition = this->m_pRacePosition;
  if ( m_pRacePosition )
  {
    if ( m_pRacePosition->pRaceTrail.m_pPointer )
    {
      v8 = m_pRacePosition->pRaceTrail.mPrev;
      v9 = m_pRacePosition->pRaceTrail.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      m_pRacePosition->pRaceTrail.mPrev = &m_pRacePosition->pRaceTrail;
      m_pRacePosition->pRaceTrail.mNext = &m_pRacePosition->pRaceTrail;
    }
    m_pRacePosition->pRaceTrail.m_pPointer = 0i64;
    v10 = m_pRacePosition->pRaceTrail.mPrev;
    v11 = m_pRacePosition->pRaceTrail.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    m_pRacePosition->pRaceTrail.mPrev = &m_pRacePosition->pRaceTrail;
    m_pRacePosition->pRaceTrail.mNext = &m_pRacePosition->pRaceTrail;
    operator delete[](m_pRacePosition);
    this->m_pRacePosition = 0i64;
  }
}

// File Line: 1727
// RVA: 0x659740
void __fastcall UFG::RoadSpaceComponent::SetRaceTrail(UFG::RoadSpaceComponent *this, UFG::RaceTrail *race_trail)
{
  UFG::SimObject *m_pSimObject; // rsi
  UFG::RacePosition *v5; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::allocator::free_link *v7; // rax
  UFG::RacePosition *v8; // rax

  UFG::RoadSpaceComponent::FlushRaceTrails(this);
  if ( race_trail )
  {
    m_pSimObject = this->m_pSimObject;
    v5 = 0i64;
    if ( m_pSimObject )
      m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    else
      m_pTransformNodeComponent = 0i64;
    v7 = UFG::qMalloc(0x48ui64, "RacePosition", 0i64);
    if ( v7 )
    {
      UFG::RacePosition::RacePosition((UFG::RacePosition *)v7, race_trail);
      v5 = v8;
    }
    this->m_pRacePosition = v5;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    UFG::RacePosition::InitPosition(
      this->m_pRacePosition,
      (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3);
  }
}

// File Line: 1740
// RVA: 0x6597F0
void __fastcall UFG::RoadSpaceComponent::SetRaceTrailSteer(UFG::RoadSpaceComponent *this, UFG::RaceTrail *race_trail)
{
  UFG::RacePosition *m_pRacePositionSteer; // rcx
  UFG::RacePosition *v5; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::SimObject *m_pSimObject; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::allocator::free_link *v12; // rax
  UFG::RacePosition *v13; // rax

  m_pRacePositionSteer = this->m_pRacePositionSteer;
  v5 = 0i64;
  if ( m_pRacePositionSteer )
  {
    if ( m_pRacePositionSteer->pRaceTrail.m_pPointer )
    {
      mPrev = m_pRacePositionSteer->pRaceTrail.mPrev;
      mNext = m_pRacePositionSteer->pRaceTrail.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      m_pRacePositionSteer->pRaceTrail.mPrev = &m_pRacePositionSteer->pRaceTrail;
      m_pRacePositionSteer->pRaceTrail.mNext = &m_pRacePositionSteer->pRaceTrail;
    }
    m_pRacePositionSteer->pRaceTrail.m_pPointer = 0i64;
    v8 = m_pRacePositionSteer->pRaceTrail.mPrev;
    v9 = m_pRacePositionSteer->pRaceTrail.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    m_pRacePositionSteer->pRaceTrail.mPrev = &m_pRacePositionSteer->pRaceTrail;
    m_pRacePositionSteer->pRaceTrail.mNext = &m_pRacePositionSteer->pRaceTrail;
    operator delete[](m_pRacePositionSteer);
    this->m_pRacePositionSteer = 0i64;
  }
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  v12 = UFG::qMalloc(0x48ui64, "RacePositionSteer", 0i64);
  if ( v12 )
  {
    UFG::RacePosition::RacePosition((UFG::RacePosition *)v12, race_trail);
    v5 = v13;
  }
  this->m_pRacePositionSteer = v5;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  UFG::RacePosition::InitPosition(
    this->m_pRacePositionSteer,
    (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3);
}

// File Line: 1753
// RVA: 0x6497D0
bool __fastcall UFG::RoadSpaceComponent::CleanupOnRaceDeleted(UFG::RoadSpaceComponent *this)
{
  UFG::RacePosition *m_pRacePositionSteer; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::RacePosition *m_pRacePosition; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v6; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v7; // rdx

  m_pRacePositionSteer = this->m_pRacePositionSteer;
  if ( m_pRacePositionSteer && !m_pRacePositionSteer->pRaceTrail.m_pPointer )
  {
    m_pRacePositionSteer->pRaceTrail.m_pPointer = 0i64;
    mPrev = m_pRacePositionSteer->pRaceTrail.mPrev;
    mNext = m_pRacePositionSteer->pRaceTrail.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    m_pRacePositionSteer->pRaceTrail.mPrev = &m_pRacePositionSteer->pRaceTrail;
    m_pRacePositionSteer->pRaceTrail.mNext = &m_pRacePositionSteer->pRaceTrail;
    operator delete[](m_pRacePositionSteer);
    this->m_pRacePositionSteer = 0i64;
  }
  m_pRacePosition = this->m_pRacePosition;
  if ( m_pRacePosition && !m_pRacePosition->pRaceTrail.m_pPointer )
  {
    m_pRacePosition->pRaceTrail.m_pPointer = 0i64;
    v6 = m_pRacePosition->pRaceTrail.mPrev;
    v7 = m_pRacePosition->pRaceTrail.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    m_pRacePosition->pRaceTrail.mPrev = &m_pRacePosition->pRaceTrail;
    m_pRacePosition->pRaceTrail.mNext = &m_pRacePosition->pRaceTrail;
    operator delete[](m_pRacePosition);
    this->m_pRacePosition = 0i64;
  }
  return this->m_pRacePosition == 0i64;
}

// File Line: 1771
// RVA: 0x650B40
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::GetSteerToRace(
        UFG::RoadSpaceComponent *this,
        UFG::qVector3 *result,
        float steer_to_distance,
        float *speed_limit,
        float vehicle_mass,
        bool is_boat)
{
  int v6; // edi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::SimObject *m_pSimObject; // rax
  UFG::RacePosition *m_pRacePositionSteer; // rax
  UFG::RacePoint *pRacePoint; // rsi
  UFG::qVector4 *v15; // r14
  UFG::RaceTrail *v16; // r10
  __m128 y_low; // xmm2
  float x; // xmm8_4
  __m128 v19; // xmm9
  float z; // xmm10_4
  float v21; // xmm11_4
  float v22; // xmm0_4
  int v23; // xmm1_4
  int nRacePoints; // r9d
  bool bIsLoop; // r8
  UFG::qVector3 *p_vDirection; // rax
  signed __int64 v27; // rsi
  int v28; // edx
  int v29; // esi
  __int64 v30; // r15
  __m128 v31; // xmm2
  float SpeedLimitForCurvature; // xmm6_4
  UFG::RacePoint *v33; // rbx
  float v34; // xmm8_4
  float fSpeed; // xmm0_4
  float BrakingSpeedLimit; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float y; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm0_4
  float v43; // xmm1_4
  UFG::qVector3 *ray; // rax
  UFG::qVector3 *v45; // rax
  float v46; // xmm1_4
  float v47; // xmm12_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm8_4
  float v52; // xmm10_4
  __m128 v53; // xmm2
  float v54; // xmm7_4
  float v55; // xmm0_4
  float v56; // xmm1_4
  UFG::RaceTrail *m_pPointer; // [rsp+30h] [rbp-C8h]
  UFG::qVector3 *v58; // [rsp+38h] [rbp-C0h]
  UFG::qVector3 resulta; // [rsp+40h] [rbp-B8h] BYREF
  float v60; // [rsp+50h] [rbp-A8h] BYREF
  float v61; // [rsp+54h] [rbp-A4h]
  float v62; // [rsp+58h] [rbp-A0h]
  int v63; // [rsp+100h] [rbp+8h]

  v6 = 0;
  m_pTransformNodeComponent = 0i64;
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  m_pRacePositionSteer = this->m_pRacePositionSteer;
  if ( !m_pRacePositionSteer )
    m_pRacePositionSteer = this->m_pRacePosition;
  pRacePoint = m_pRacePositionSteer->pRacePoint;
  m_pPointer = m_pRacePositionSteer->pRaceTrail.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v15 = &m_pTransformNodeComponent->mWorldTransform.v3;
  UFG::RacePoint::GetSegmentPosition(
    pRacePoint,
    &resulta,
    (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3);
  v16 = m_pPointer;
  y_low = (__m128)LODWORD(m_pTransformNodeComponent->mWorldTransform.v3.y);
  x = resulta.x;
  v19 = (__m128)LODWORD(resulta.y);
  z = resulta.z;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - resulta.y) * (float)(y_low.m128_f32[0] - resulta.y))
                            + (float)((float)(v15->x - resulta.x) * (float)(v15->x - resulta.x)))
                    + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.z - resulta.z)
                            * (float)(m_pTransformNodeComponent->mWorldTransform.v3.z - resulta.z));
  LODWORD(v21) = _mm_sqrt_ps(y_low).m128_u32[0];
  if ( m_pPointer && steer_to_distance > v21 )
  {
    v22 = pRacePoint->vDirection.x;
    v23 = LODWORD(pRacePoint->vDirection.y);
    nRacePoints = m_pPointer->nRacePoints;
    bIsLoop = m_pPointer->bIsLoop;
    p_vDirection = &pRacePoint->vDirection;
    v27 = (char *)pRacePoint - (char *)m_pPointer->pRacePoints;
    v60 = v22;
    v61 = *(float *)&v23;
    v58 = p_vDirection;
    v62 = p_vDirection->z;
    v63 = nRacePoints;
    v28 = (int)v27 / 56 + 1;
    if ( v28 >= nRacePoints )
    {
      v28 = 0;
      if ( !bIsLoop )
        v28 = nRacePoints - 1;
    }
    v29 = nRacePoints;
    v30 = 56i64 * v28 / 56;
    if ( !bIsLoop )
      v29 = nRacePoints - v30;
    if ( v29 <= 0 )
    {
LABEL_22:
      ray = v58;
    }
    else
    {
      while ( 1 )
      {
        v31 = (__m128)LODWORD(v15->y);
        SpeedLimitForCurvature = FLOAT_100_0;
        v33 = &v16->pRacePoints[(v6 + (int)v30) % nRacePoints];
        v31.m128_f32[0] = (float)((float)((float)(v31.m128_f32[0] - v33->vPosition.y)
                                        * (float)(v31.m128_f32[0] - v33->vPosition.y))
                                + (float)((float)(v15->x - v33->vPosition.x) * (float)(v15->x - v33->vPosition.x)))
                        + (float)((float)(v15->z - v33->vPosition.z) * (float)(v15->z - v33->vPosition.z));
        LODWORD(v34) = _mm_sqrt_ps(v31).m128_u32[0];
        if ( (*(_DWORD *)&this->mBits & 8) != 0 )
          SpeedLimitForCurvature = UFG::GetSpeedLimitForCurvature(v33->fCurvature, 100.0, 1.0);
        fSpeed = v33->fSpeed;
        if ( fSpeed >= 0.0 && SpeedLimitForCurvature >= fSpeed )
          SpeedLimitForCurvature = v33->fSpeed;
        BrakingSpeedLimit = UFG::GetBrakingSpeedLimit(v34, 100.0, vehicle_mass, is_boat);
        v37 = *speed_limit;
        v38 = BrakingSpeedLimit + SpeedLimitForCurvature;
        if ( *speed_limit >= v38 )
          v37 = v38;
        *speed_limit = v37;
        if ( steer_to_distance <= v34 )
          break;
        y = v33->vDirection.y;
        nRacePoints = v63;
        v16 = m_pPointer;
        ++v6;
        v60 = v33->vDirection.x;
        v40 = v33->vDirection.z;
        v61 = y;
        v41 = v33->vPosition.x;
        v62 = v40;
        v42 = v33->vPosition.y;
        resulta.x = v41;
        v43 = v33->vPosition.z;
        resulta.y = v42;
        resulta.z = v43;
        if ( v6 >= v29 )
          goto LABEL_22;
      }
      ray = (UFG::qVector3 *)&v60;
    }
    UFG::RoadSpaceComponent::SteerTo(result, (UFG::qVector3 *)v15, steer_to_distance, &resulta, ray);
    return result;
  }
  else
  {
    if ( steer_to_distance >= 1.0 )
      v46 = steer_to_distance;
    else
      v46 = *(float *)&FLOAT_1_0;
    v47 = UFG::GetSpeedLimitForCurvature(1.5707964 / v46, 100.0, 1.0);
    if ( (*(_DWORD *)&this->mBits & 8) != 0 )
    {
      v48 = UFG::GetBrakingSpeedLimit(v21, 100.0, vehicle_mass, is_boat);
      v49 = *speed_limit;
      v50 = v48 + v47;
      if ( *speed_limit >= v50 )
        v49 = v50;
      *speed_limit = v49;
    }
    v51 = x - v15->x;
    v19.m128_f32[0] = v19.m128_f32[0] - m_pTransformNodeComponent->mWorldTransform.v3.y;
    v52 = z - m_pTransformNodeComponent->mWorldTransform.v3.z;
    v45 = result;
    v53 = v19;
    v53.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v51 * v51)) + (float)(v52 * v52);
    v54 = steer_to_distance / _mm_sqrt_ps(v53).m128_f32[0];
    v55 = (float)(v54 * v19.m128_f32[0]) + m_pTransformNodeComponent->mWorldTransform.v3.y;
    v56 = (float)(v54 * v51) + v15->x;
    result->z = (float)(v54 * v52) + m_pTransformNodeComponent->mWorldTransform.v3.z;
    result->x = v56;
    result->y = v55;
  }
  return v45;
}

// File Line: 1831
// RVA: 0x64E760
float __fastcall UFG::RoadSpaceComponent::GetFractionRaceComplete(UFG::RoadSpaceComponent *this)
{
  UFG::RacePosition *m_pRacePosition; // rdx
  float result; // xmm0_4
  UFG::RaceTrail *m_pPointer; // rax
  float nLaps; // xmm1_4
  float v5; // xmm1_4

  m_pRacePosition = this->m_pRacePosition;
  result = 0.0;
  if ( m_pRacePosition )
  {
    m_pPointer = m_pRacePosition->pRaceTrail.m_pPointer;
    if ( m_pPointer )
    {
      if ( m_pPointer->bIsLoop )
        nLaps = (float)m_pPointer->nLaps;
      else
        nLaps = *(float *)&FLOAT_1_0;
      v5 = nLaps * m_pPointer->fLength;
      if ( v5 > 0.0 )
        return m_pRacePosition->fRaceDistance / v5;
    }
  }
  return result;
}

