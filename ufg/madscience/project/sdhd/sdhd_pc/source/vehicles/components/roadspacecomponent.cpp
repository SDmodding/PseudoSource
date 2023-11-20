// File Line: 84
// RVA: 0x1573940
__int64 dynamic_initializer_for__UFG::RoadSpaceComponent::s_RoadSpaceComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::RoadSpaceComponent::s_RoadSpaceComponentList__);
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
  UFG::RoadSpaceComponent *v1; // rdi
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v2; // rbx
  float v3; // xmm1_4
  float v4; // xmm2_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v5; // rsi
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v6; // rax
  __m128 v7; // xmm4
  __m128 v8; // xmm3
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4

  v1 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, UFG::RoadSpaceComponent::mNameUID);
  v2 = (UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RoadSpaceComponent::`vftable;
  UFG::NavGuide::NavGuide(&v1->m_NavGuide);
  *(_QWORD *)&v1->m_DestNavRadius = 0x40000000i64;
  v1->m_NavWanderDestPos.y = 0.0;
  v1->m_NavWanderDestPos.z = -1000.0;
  v1->m_NavWanderRadius = 5.0;
  v1->m_HasNavWanderCenter = 0;
  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  v1->m_NavWanderCenter.x = UFG::qVector3::msZero.x;
  v1->m_NavWanderCenter.y = v3;
  v1->m_NavWanderCenter.z = v4;
  UFG::RoadNetworkGuide::RoadNetworkGuide(&v1->mGuide);
  UFG::WayFinderClient::WayFinderClient((UFG::WayFinderClient *)&v1->mWayClient.vfptr);
  v1->mWayClient.vfptr = (UFG::WayFinderClientVtbl *)&UFG::VehicleWayFinderClient::`vftable;
  v1->mWayClient.m_RoadNetworkType = 0;
  v1->mWayClient.m_LaneFlags = -1;
  v1->mWayClient.m_RoadGuide = 0i64;
  v1->mWayClient.m_AllowFootPaths = 0;
  v5 = &v1->m_pChaseTarget;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->m_pChaseTarget.m_pPointer = 0i64;
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::RebindingComponentHandle<UFG::CameraSubject,0>(&v1->m_pSubject);
  UFG::RingBuffer<UFG::Crumb>::RingBuffer<UFG::Crumb>(
    &v1->m_PositionTrail.mTrail,
    UFG::AiDriverComponent::m_NumBreadCrumbs);
  v1->m_LaneFlags = 2;
  v1->m_NavGuideEnabled = 0;
  v6 = UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mPrev;
  UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *)&v1->mPrev;
  v2->mPrev = v6;
  v1->mNext = (UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *)&UFG::RoadSpaceComponent::s_RoadSpaceComponentList;
  UFG::RoadSpaceComponent::s_RoadSpaceComponentList.mNode.mPrev = (UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *)&v1->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::RoadSpaceComponent::_RoadSpaceComponentTypeUID,
    "RoadSpaceComponent");
  v1->mWayClient.m_RoadGuide = &v1->mGuide;
  if ( v1->mGuide.m_Attached )
    UFG::VehicleWayFinderClient::SetLaneFlagsFromGuide(&v1->mWayClient, &v1->mGuide);
  v7 = 0i64;
  v8 = 0i64;
  v8.m128_f32[0] = (float)1;
  v1->m_ChaseWorld.v0 = (UFG::qVector4)v8;
  v1->m_ChaseWorld.v1 = (UFG::qVector4)_mm_shuffle_ps(v8, v8, 81);
  v1->m_ChaseWorld.v2 = (UFG::qVector4)_mm_shuffle_ps(v8, v8, 69);
  v1->m_ChaseWorld.v3 = (UFG::qVector4)_mm_shuffle_ps(v8, v8, 21);
  v7.m128_f32[0] = (float)1;
  v1->m_WorldChase.v0 = (UFG::qVector4)v7;
  v1->m_WorldChase.v1 = (UFG::qVector4)_mm_shuffle_ps(v7, v7, 81);
  v1->m_WorldChase.v2 = (UFG::qVector4)_mm_shuffle_ps(v7, v7, 69);
  v1->m_WorldChase.v3 = (UFG::qVector4)_mm_shuffle_ps(v7, v7, 21);
  if ( v1->m_pChaseTarget.m_pPointer )
  {
    v9 = v5->mPrev;
    v10 = v1->m_pChaseTarget.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->m_pChaseTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pChaseTarget.mPrev;
  }
  v1->m_pChaseTarget.m_pPointer = 0i64;
  v1->m_pChaseFormation = 0i64;
  v1->m_pRacePosition = 0i64;
  v1->m_pRacePositionSteer = 0i64;
  *(_QWORD *)&v1->m_fChaseCurvature = 0i64;
  *(_QWORD *)&v1->m_fChaseDistance = 0i64;
  v11 = UFG::qVector3::msZero.y;
  v12 = UFG::qVector3::msZero.z;
  v1->mDestinationPosition.x = UFG::qVector3::msZero.x;
  v1->mDestinationPosition.y = v11;
  v1->mDestinationPosition.z = v12;
  v13 = UFG::qVector3::msZero.y;
  v14 = UFG::qVector3::msZero.z;
  v1->mDestinationDirection.x = UFG::qVector3::msZero.x;
  v1->mDestinationDirection.y = v13;
  v1->mDestinationDirection.z = v14;
  *(_DWORD *)&v1->mBits &= 0xFFFFFFF8;
  *(_DWORD *)&v1->mBits |= 8u;
}

// File Line: 128
// RVA: 0x643E80
void __fastcall UFG::RoadSpaceComponent::~RoadSpaceComponent(UFG::RoadSpaceComponent *this)
{
  UFG::RoadSpaceComponent *v1; // rdi
  UFG::SimObjectVehicle *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::VehicleSubjectComponent *v4; // rax
  UFG::VehicleFormations *v5; // rbx
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v6; // rsi
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v7; // rcx
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v8; // rax
  UFG::Crumb *v9; // rcx
  char *v10; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v16; // rcx
  UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *v17; // rax
  UFG::VehicleWayFinderClient *v18; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::RoadSpaceComponent::`vftable;
  v2 = (UFG::SimObjectVehicle *)this->m_pChaseTarget.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v2->vfptr,
                                             UFG::VehicleSubjectComponent::_TypeUID);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v2->vfptr,
                                               UFG::VehicleSubjectComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v2->vfptr,
                                               UFG::VehicleSubjectComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v2->vfptr,
                                               UFG::VehicleSubjectComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v2);
    }
  }
  else
  {
    v4 = 0i64;
  }
  if ( v4 )
    UFG::VehicleSubjectComponent::RemoveChaser(v4, v1->m_pSimObject);
  UFG::RoadSpaceComponent::FlushRaceTrails(v1);
  v5 = v1->m_pChaseFormation;
  if ( v5 )
  {
    UFG::VehicleFormations::~VehicleFormations(v1->m_pChaseFormation);
    operator delete[](v5);
    v1->m_pChaseFormation = 0i64;
  }
  if ( v1 == UFG::RoadSpaceComponent::s_RoadSpaceComponentpCurrentIterator )
    UFG::RoadSpaceComponent::s_RoadSpaceComponentpCurrentIterator = (UFG::RoadSpaceComponent *)&v1->mPrev[-4];
  v6 = (UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *)&v1->mPrev;
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v6->mPrev = v6;
  v6->mNext = v6;
  v9 = v1->m_PositionTrail.mTrail.mData;
  if ( v9 )
  {
    v10 = (char *)&v9[-1].fCurvature;
    `eh vector destructor iterator(v9, 0x20ui64, LODWORD(v9[-1].fCurvature), (void (__fastcall *)(void *))_);
    operator delete[](v10);
  }
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)&v1->m_pSubject);
  v11 = &v1->m_pChaseTarget;
  if ( v1->m_pChaseTarget.m_pPointer )
  {
    v12 = v11->mPrev;
    v13 = v1->m_pChaseTarget.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    v1->m_pChaseTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pChaseTarget.mPrev;
  }
  v1->m_pChaseTarget.m_pPointer = 0i64;
  v14 = v11->mPrev;
  v15 = v1->m_pChaseTarget.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
  v1->m_pChaseTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->m_pChaseTarget.mPrev;
  v18 = &v1->mWayClient;
  v18->vfptr = (UFG::WayFinderClientVtbl *)&UFG::VehicleWayFinderClient::`vftable;
  v18->vfptr = (UFG::WayFinderClientVtbl *)&UFG::WayFinderClient::`vftable;
  UFG::RoadNetworkGuide::~RoadNetworkGuide(&v1->mGuide);
  UFG::NavGuide::~NavGuide(&v1->m_NavGuide);
  v16 = v6->mPrev;
  v17 = v1->mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  v6->mPrev = v6;
  v1->mNext = (UFG::qNode<UFG::RoadSpaceComponent,UFG::RoadSpaceComponent> *)&v1->mPrev;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 224
// RVA: 0x65E8D0
void __fastcall UFG::RoadSpaceComponent::TeleportEventHandler(UFG::RoadSpaceComponent *this, UFG::Event *event)
{
  bool v2; // si
  UFG::Event *v3; // rdi
  UFG::RoadSpaceComponent *v4; // rbx
  UFG::RacePosition *v5; // rcx
  UFG::qVector3 *v6; // rdi
  UFG::RacePosition *v7; // rcx

  v2 = this->mGuide.m_Attached;
  v3 = event;
  v4 = this;
  if ( v2 )
    UFG::RoadNetworkGuide::RemoveFromNetwork(&this->mGuide);
  v5 = v4->m_pRacePositionSteer;
  v6 = (UFG::qVector3 *)&v3[2].mNext;
  if ( v5 )
    UFG::RacePosition::InitPosition(v5, v6);
  v7 = v4->m_pRacePosition;
  if ( v7 )
    UFG::RacePosition::InitPosition(v7, v6);
  if ( v2 )
    UFG::RoadSpaceComponent::AttachToRoadNetwork(v4, v6, 0i64);
  v4->m_fChaseFailedTimer = 0.0;
}

// File Line: 240
// RVA: 0x656800
void __fastcall UFG::RoadSpaceComponent::OnAttach(UFG::RoadSpaceComponent *this, UFG::SimObject *object)
{
  UFG::RoadSpaceComponent *v2; // rdi
  UFG::RebindingComponentHandle<UFG::CameraSubject,0> *v3; // rcx
  UFG::SimObjectCVBase *v4; // rbx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rdx
  unsigned __int16 v9; // cx
  UFG::AiDriverComponent *v10; // rax
  UFG::SimComponent *v11; // rcx

  v2 = this;
  v3 = &this->m_pSubject;
  v4 = (UFG::SimObjectCVBase *)object;
  if ( v3->m_pSimComponent )
  {
    v5 = v3->mNext;
    v6 = v3->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    v3->m_pSimComponent = 0i64;
  }
  else
  {
    if ( !v3->m_pSimObject
      || (UFG::RebindingComponentHandle<UFG::CameraSubject,0> *)v3->mPrev == v3
      && (UFG::RebindingComponentHandle<UFG::CameraSubject,0> *)v3->mNext == v3 )
    {
      goto LABEL_8;
    }
    v7 = v3->mNext;
    v8 = v3->mPrev;
    v8->mNext = v7;
    v7->mPrev = v8;
  }
  v3->m_pSimObject = 0i64;
  v3->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
  v3->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v3->mPrev;
LABEL_8:
  v3->m_Changed = 1;
  v3->m_pSimObject = (UFG::SimObject *)&v4->vfptr;
  v3->m_TypeUID = UFG::CameraSubject::_TypeUID;
  UFG::RebindingComponentHandle<UFG::CameraSubject,0>::BindInternal<UFG::SimObject>(v3, (UFG::SimObject *)&v4->vfptr);
  if ( v4 )
  {
    v9 = v4->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v10 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v4);
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
        v10 = (UFG::AiDriverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)&v4->vfptr,
                                          UFG::AiDriverComponent::_TypeUID);
      else
        v10 = (UFG::AiDriverComponent *)((v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v4->vfptr,
                                                            UFG::AiDriverComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                                  (UFG::SimObject *)&v4->vfptr,
                                                                                                  UFG::AiDriverComponent::_TypeUID));
    }
    else
    {
      v10 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v4);
    }
    if ( v10 )
    {
      if ( UFG::SimObjectUtility::IsClassType((UFG::SimObject *)&v4->vfptr, (UFG::qSymbol *)&qSymbol_Tram.mUID) )
      {
        v2->mWayClient.m_RoadNetworkType = 1;
      }
      else if ( UFG::SimObjectUtility::IsClassType((UFG::SimObject *)&v4->vfptr, (UFG::qSymbol *)&qSymbol_Ferry.mUID) )
      {
        v2->mWayClient.m_RoadNetworkType = 2;
      }
      else
      {
        v2->mWayClient.m_RoadNetworkType = UFG::SimObjectUtility::IsClassType(
                                             (UFG::SimObject *)&v4->vfptr,
                                             (UFG::qSymbol *)&qSymbol_Boat_21.mUID) != 0 ? 3 : 0;
      }
    }
  }
  UFG::RoadSpaceComponent::SetupLaneFlags(v2);
  v11 = v2->m_pSubject.m_pSimComponent;
  if ( v11 )
  {
    if ( ((unsigned __int8 (*)(void))v11->vfptr[46].__vecDelDtor)() )
      UFG::RoadSpaceComponent::SnapToRoadNetwork(v2);
  }
}

// File Line: 274
// RVA: 0x656B30
void __fastcall UFG::RoadSpaceComponent::OnDetach(UFG::RoadSpaceComponent *this)
{
  UFG::RoadSpaceComponent *v1; // rbx
  UFG::SimObjectVehicle *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::VehicleSubjectComponent *v4; // rax
  UFG::RebindingComponentHandle<UFG::CameraSubject,0> *v5; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v7; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v8; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v9; // rax

  v1 = this;
  v2 = (UFG::SimObjectVehicle *)this->m_pChaseTarget.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             (UFG::SimObjectGame *)&v2->vfptr,
                                             UFG::VehicleSubjectComponent::_TypeUID);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v2->vfptr,
                                               UFG::VehicleSubjectComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v2->vfptr,
                                               UFG::VehicleSubjectComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v2->vfptr,
                                               UFG::VehicleSubjectComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v2);
    }
  }
  else
  {
    v4 = 0i64;
  }
  if ( v4 )
    UFG::VehicleSubjectComponent::RemoveChaser(v4, v1->m_pSimObject);
  v5 = &v1->m_pSubject;
  if ( v1->m_pSubject.m_pSimComponent )
  {
    v6 = v5->mPrev;
    v7 = v1->m_pSubject.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v1->m_pSubject.m_pSimComponent = 0i64;
LABEL_20:
    v1->m_pSubject.m_pSimObject = 0i64;
    v1->m_pSubject.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->m_pSubject.mPrev;
    v5->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v5->mPrev;
    goto LABEL_21;
  }
  if ( v1->m_pSubject.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::CameraSubject,0> *)v5->mPrev != v5
     || (UFG::RebindingComponentHandle<UFG::CameraSubject,0> *)v1->m_pSubject.mNext != &v1->m_pSubject) )
  {
    v8 = v5->mPrev;
    v9 = v1->m_pSubject.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    goto LABEL_20;
  }
LABEL_21:
  v1->m_pSubject.m_Changed = 1;
  UFG::RoadNetworkGuide::RemoveFromNetwork(&v1->mGuide);
  UFG::RoadSpaceComponent::FlushRaceTrails(v1);
}

// File Line: 290
// RVA: 0x659A40
void __fastcall UFG::RoadSpaceComponent::SetupLaneFlags(UFG::RoadSpaceComponent *this)
{
  UFG::SimObjectVehicle *v1; // rbx
  UFG::RoadSpaceComponent *v2; // rdi
  UFG::AiDriverComponent *v3; // rax
  UFG::VehicleSubjectComponent *v4; // rax

  v1 = (UFG::SimObjectVehicle *)this->m_pSimObject;
  v2 = this;
  if ( (v1->m_Flags & 0x8000u) != 0 )
  {
    if ( v1 )
    {
      v3 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>((UFG::SimObjectCVBase *)this->m_pSimObject);
      if ( v3 )
      {
        if ( !((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v3->vfptr[16].__vecDelDtor)(v3) )
          v2->m_LaneFlags |= 1u;
      }
    }
    if ( UFG::SimObjectUtility::IsClassType((UFG::SimObject *)&v1->vfptr, (UFG::qSymbol *)&qSymbol_Tram.mUID)
      || UFG::SimObjectUtility::IsClassType((UFG::SimObject *)&v1->vfptr, (UFG::qSymbol *)&qSymbol_Ferry.mUID)
      || UFG::SimObjectUtility::IsClassType((UFG::SimObject *)&v1->vfptr, (UFG::qSymbol *)&qSymbol_Minibus.mUID) )
    {
      v2->m_LaneFlags = 16;
    }
    if ( v1 )
      v4 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v1);
    else
      v4 = 0i64;
    if ( ((unsigned __int8 (__fastcall *)(UFG::VehicleSubjectComponent *))v4->vfptr[30].__vecDelDtor)(v4) )
      v2->m_LaneFlags = v2->m_LaneFlags & 0xFFFFFFFE | 4;
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
  UFG::RoadSpaceComponent *v2; // rdi
  UFG::SimComponent *v3; // rcx
  __int64 v4; // rbx
  __int64 v5; // rax
  float v6; // xmm2_4
  float v7; // xmm3_4
  UFG::SimObject *v8; // r14
  UFG::TransformNodeComponent *v9; // r14
  UFG::qVector3 *v10; // r14
  UFG::SimComponent *v11; // rcx
  bool v12; // bp
  char v13; // si
  bool v14; // r15
  float *v15; // rax
  float v16; // xmm2_4
  UFG::WheeledVehicleNavigationData *v17; // rcx
  unsigned int v18; // eax
  UFG::WayFinder *v19; // rdx
  UFG::SimObject *v20; // rbx
  UFG::TransformNodeComponent *v21; // rbx
  UFG::RacePosition *v22; // rcx
  UFG::RacePosition *v23; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v24; // rax
  char v25; // [rsp+20h] [rbp-48h]

  v2 = this;
  v3 = this->m_pSubject.m_pSimComponent;
  if ( v3 )
  {
    v4 = ((__int64 (*)(void))v3->vfptr[23].__vecDelDtor)();
    v5 = ((__int64 (*)(void))v2->m_pSubject.m_pSimComponent->vfptr[24].__vecDelDtor)();
    LODWORD(v6) = *(_DWORD *)v4 & _xmm;
    v7 = *(float *)(v5 + 4) - *(float *)(v4 + 4);
    LODWORD(v2->mGuide.m_FrontBoundary) = *(_DWORD *)v5 & _xmm;
    v2->mGuide.m_RearBoundary = v6;
    LODWORD(v2->mGuide.m_ObjectWidth) = LODWORD(v7) & _xmm;
  }
  UFG::RoadSpaceComponent::UpdateChaseMatrix(v2);
  UFG::RoadSpaceComponent::UpdateNavGuide(v2);
  v8 = v2->m_pSimObject;
  if ( v8 )
    v9 = v8->m_pTransformNodeComponent;
  else
    v9 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v9);
  v10 = (UFG::qVector3 *)&v9->mWorldTransform.v3;
  if ( v2->mGuide.m_Attached )
  {
    UFG::RoadNetworkGuide::Update(&v2->mGuide, v10);
  }
  else
  {
    v11 = v2->m_pSubject.m_pSimComponent;
    v12 = v11 && ((unsigned __int8 (*)(void))v11->vfptr[46].__vecDelDtor)();
    v13 = (*(_DWORD *)&v2->mBits >> 2) & 1;
    v14 = v12 && !v13;
    v15 = (float *)(*((__int64 (__fastcall **)(UFG::VehicleWayFinderClient *, char *))&v2->mWayClient.vfptr[1].__vecDelDtor
                    + 1))(
                     &v2->mWayClient,
                     &v25);
    v16 = (float)((float)((float)(v10->y - v15[1]) * (float)(v10->y - v15[1]))
                + (float)((float)(v10->x - *v15) * (float)(v10->x - *v15)))
        + (float)((float)(v10->z - v15[2]) * (float)(v10->z - v15[2]));
    if ( v16 > 9.0 && v12 || v14 )
      UFG::RoadSpaceComponent::SnapToRoadNetwork(v2);
    if ( v16 > 9.0 )
    {
      v17 = UFG::WheeledVehicleManager::m_Instance->m_NavigationData;
      v18 = v2->mWayClient.m_RoadNetworkType;
      if ( v18 == 1 )
      {
        v19 = &v17->mTramWayFinder;
      }
      else if ( v18 == 2 )
      {
        v19 = &v17->mFerryWayFinder;
      }
      else
      {
        v19 = &v17->mOceanWayFinder;
        if ( v18 != 3 )
          v19 = &v17->mTrafficWayFinder;
      }
      v2->mWayClient.vfptr->SetPosition(
        (UFG::WayFinderClient *)&v2->mWayClient.vfptr,
        v19->m_WayGraph,
        v10,
        (UFG::qVector3 *)&v2->m_ChaseWorld);
    }
    if ( v13 != v12 )
    {
      *(_DWORD *)&v2->mBits &= 0xFFFFFFFB;
      *(_DWORD *)&v2->mBits |= 4 * (v12 != 0);
    }
  }
  UFG::RoadSpaceComponent::CleanupOnRaceDeleted(v2);
  v20 = v2->m_pSimObject;
  if ( v20 )
  {
    v21 = v20->m_pTransformNodeComponent;
    if ( v21 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v21);
      UFG::CrumbTrail::Update(&v2->m_PositionTrail, (UFG::qVector3 *)&v21->mWorldTransform.v3);
    }
  }
  v22 = v2->m_pRacePosition;
  if ( v22 )
    UFG::RacePosition::Update(v22, v10, delta_sec);
  v23 = v2->m_pRacePositionSteer;
  if ( v23 )
    UFG::RacePosition::UpdateRacePoint(v23, v10);
  v24 = UFG::RoadSpaceComponent::GetCarChaseTargetFormation(v2);
  if ( v24 )
    UFG::VehicleFormations::Update((UFG::VehicleFormations *)v24, delta_sec);
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
  UFG::SimObject *v1; // rdi
  UFG::RoadSpaceComponent *v2; // rbx

  v1 = this->m_pSimObject;
  v2 = this;
  if ( v1 )
    v1 = (UFG::SimObject *)v1->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1);
  UFG::NavGuide::FindPath(
    &v2->m_NavGuide,
    (UFG::qVector3 *)v1[1].mNode.mChild,
    &v2->mDestinationPosition,
    v2->m_DestNavRadius);
}

// File Line: 829
// RVA: 0x6451F0
void __fastcall UFG::RoadSpaceComponent::AttachToRoadNetwork(UFG::RoadSpaceComponent *this, UFG::qVector3 *position, UFG::qVector3 *forward)
{
  UFG::RoadNetworkResource *v3; // rsi
  UFG::qVector3 *v4; // rbp
  UFG::qVector3 *v5; // r14
  UFG::RoadSpaceComponent *v6; // rdi
  unsigned int type; // ebx
  float v8; // xmm6_4
  unsigned int v9; // ebx
  UFG::RoadNetworkNode *v10; // rax
  UFG::RoadNetworkLocation v11; // [rsp+30h] [rbp-28h]

  v3 = UFG::gpRoadNetworkResource;
  v4 = forward;
  v5 = position;
  v6 = this;
  if ( UFG::gpRoadNetworkResource )
  {
    type = 0;
    if ( UFG::SimObjectUtility::IsClassType(this->m_pSimObject, (UFG::qSymbol *)&qSymbol_Tram.mUID) )
    {
      type = 1;
    }
    else if ( UFG::SimObjectUtility::IsClassType(v6->m_pSimObject, (UFG::qSymbol *)&qSymbol_Ferry.mUID) )
    {
      type = 2;
    }
    else if ( UFG::SimObjectUtility::IsClassType(v6->m_pSimObject, (UFG::qSymbol *)&qSymbol_Boat_21.mUID) )
    {
      type = 3;
    }
    Scaleform::GFx::AS3::Value::Value(&v11);
    UFG::RoadNetworkLocation::AttachToNetwork(&v11, v3, v5, v4, type);
    v8 = v11.m_LaneT;
    v9 = v11.m_CurrentLane->mLaneIndex;
    v10 = UFG::RoadNetworkLocation::GetRoadNetworkNode(&v11);
    UFG::RoadNetworkGuide::AttachToNetwork(&v6->mGuide, v6->m_pSimObject, v10, v9, v8);
  }
}

// File Line: 859
// RVA: 0x65A5B0
void __fastcall UFG::RoadSpaceComponent::SnapToRoadNetwork(UFG::RoadSpaceComponent *this)
{
  UFG::SimObject *v1; // rbx
  UFG::RoadSpaceComponent *v2; // rdi

  v1 = this->m_pSimObject;
  v2 = this;
  if ( v1 )
    v1 = (UFG::SimObject *)v1->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1);
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1);
  UFG::RoadSpaceComponent::AttachToRoadNetwork(v2, (UFG::qVector3 *)v1[1].mNode.mChild, (UFG::qVector3 *)&v1[1]);
  UFG::RoadNetworkGuide::RemoveFromNetwork(&v2->mGuide);
}

// File Line: 866
// RVA: 0x6452F0
void __fastcall UFG::RoadSpaceComponent::AttachToRoadNetwork(UFG::RoadSpaceComponent *this, bool consider_heading)
{
  UFG::SimObject *v2; // rbx
  UFG::qVector3 *v3; // rdi
  UFG::RoadSpaceComponent *v4; // rsi
  UFG::TransformNodeComponent *v5; // rbx

  v2 = this->m_pSimObject;
  v3 = 0i64;
  v4 = this;
  if ( v2 )
    v5 = v2->m_pTransformNodeComponent;
  else
    v5 = 0i64;
  if ( consider_heading )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v5);
    v3 = (UFG::qVector3 *)&v5->mWorldTransform;
  }
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  UFG::RoadSpaceComponent::AttachToRoadNetwork(v4, (UFG::qVector3 *)&v5->mWorldTransform.v3, v3);
}

// File Line: 878
// RVA: 0x64FB10
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::GetSteerToDestination(UFG::RoadSpaceComponent *this, UFG::qVector3 *result, float steerToDistance, bool isBoat, bool useDirection)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  bool v7; // bl
  UFG::qVector3 *v8; // rsi
  UFG::RoadSpaceComponent *v9; // rdi
  __m128 v11; // xmm10
  float v12; // xmm7_4
  float v13; // xmm11_4
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl *v14; // rax
  UFG::qVector3 *v15; // rbp
  float v16; // xmm9_4
  float v17; // xmm8_4
  UFG::SimComponent *v18; // rdi
  float *v19; // rbx
  float v20; // xmm13_4
  float v21; // xmm6_4
  float v22; // xmm6_4
  float v23; // xmm15_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  float v26; // xmm8_4
  __m128 v27; // xmm9
  float v28; // xmm7_4
  __m128 v29; // xmm2
  float v30; // xmm1_4
  float v31; // xmm11_4
  float v32; // xmm9_4
  float v33; // xmm7_4
  float v34; // xmm8_4
  float v35; // xmm12_4
  float v36; // xmm2_4
  float v37; // xmm8_4
  float v38; // xmm9_4
  __m128 v39; // xmm10
  float v40; // xmm7_4
  __m128 v41; // xmm11
  float v42; // xmm12_4
  __m128 v43; // xmm2
  __m128 v44; // xmm0
  __m128 v45; // xmm2
  float v46; // xmm6_4
  float v47; // xmm10_4
  float v48; // xmm12_4
  float v49; // xmm11_4
  __m128 v50; // xmm3
  float v51; // xmm5_4
  __m128 v52; // xmm2
  float v53; // xmm4_4
  float v54; // xmm10_4
  float v55; // xmm6_4
  float v56; // xmm9_4
  float v57; // xmm7_4
  float v58; // xmm9_4
  float v59; // xmm7_4
  UFG::qVector3 *v60; // rax
  float v61; // xmm0_4
  float v62; // xmm1_4
  UFG::qVector3 ray; // [rsp+30h] [rbp-D8h]
  UFG::qVector3 resulta; // [rsp+40h] [rbp-C8h]
  float v65; // [rsp+110h] [rbp+8h]
  float radius; // [rsp+120h] [rbp+18h]

  radius = steerToDistance;
  v5 = this->mDestinationPosition.y;
  v6 = this->mDestinationPosition.z;
  result->x = this->mDestinationPosition.x;
  v7 = isBoat;
  v8 = result;
  result->y = v5;
  result->z = v6;
  v9 = this;
  if ( !this->m_pSubject.m_pSimComponent )
    return result;
  Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 2u);
  v11 = (__m128)LODWORD(v9->mDestinationDirection.x);
  v12 = v9->mDestinationDirection.y;
  v13 = v9->mDestinationDirection.z;
  v14 = v9->m_pSubject.m_pSimComponent->vfptr;
  ray.x = v9->mDestinationDirection.x;
  ray.y = v12;
  ray.z = v13;
  v15 = (UFG::qVector3 *)((__int64 (*)(void))v14[17].__vecDelDtor)();
  ((void (*)(void))v9->m_pSubject.m_pSimComponent->vfptr[16].__vecDelDtor)();
  if ( useDirection
    && (float)((float)((float)(v12 * v12) + (float)(v11.m128_f32[0] * v11.m128_f32[0])) + (float)(v13 * v13)) >= 0.001 )
  {
    if ( (float)((float)((float)((float)(v15->y - v8->y) * (float)(v15->y - v8->y))
                       + (float)((float)(v15->x - v8->x) * (float)(v15->x - v8->x)))
               + (float)((float)(v15->z - v8->z) * (float)(v15->z - v8->z))) > 4.0 )
    {
      v16 = FLOAT_0_78539819;
      if ( v7 )
        v16 = FLOAT_0_39269909;
      v17 = FLOAT_10_0;
      if ( v7 )
        v17 = FLOAT_20_0;
      v18 = v9->m_pSubject.m_pSimComponent;
      v19 = (float *)((__int64 (__fastcall *)(UFG::SimComponent *))v18->vfptr[24].__vecDelDtor)(v18);
      v20 = *(float *)&FLOAT_1_0;
      v21 = (float)(*v19 - *(float *)((__int64 (__fastcall *)(UFG::SimComponent *))v18->vfptr[23].__vecDelDtor)(v18))
          - 1.0;
      if ( v21 < 1.0 )
        v21 = *(float *)&FLOAT_1_0;
      v22 = v21 / v16;
      if ( v22 <= 2.0 )
        v22 = FLOAT_2_0;
      if ( v22 >= v17 )
        v22 = v17;
      v23 = UFG::qVector3::msDirUp.y;
      v24 = UFG::qVector3::msDirUp.z;
      v25 = UFG::qVector3::msDirUp.x;
      v27 = v11;
      v65 = v22 * v22;
      v26 = (float)(v13 * UFG::qVector3::msDirUp.y) - (float)(v12 * UFG::qVector3::msDirUp.z);
      v27.m128_f32[0] = (float)(v11.m128_f32[0] * UFG::qVector3::msDirUp.z) - (float)(v13 * UFG::qVector3::msDirUp.x);
      v29 = v27;
      v28 = (float)(v12 * UFG::qVector3::msDirUp.x) - (float)(v11.m128_f32[0] * UFG::qVector3::msDirUp.y);
      v29.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v27.m128_f32[0]) + (float)(v26 * v26)) + (float)(v28 * v28);
      if ( v29.m128_f32[0] == 0.0 )
        v30 = 0.0;
      else
        v30 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v29));
      v31 = v8->y;
      v32 = v27.m128_f32[0] * v30;
      v33 = v28 * v30;
      v34 = v26 * v30;
      v35 = v8->z;
      v36 = (float)((float)((float)(v15->y - v31) * v32) + (float)((float)(v15->x - v8->x) * v34))
          + (float)((float)(v15->z - v35) * v33);
      if ( v36 <= 0.0 )
      {
        if ( v36 >= 0.0 )
          v20 = 0.0;
        else
          v20 = FLOAT_N1_0;
      }
      v37 = (float)(v34 * (float)(v20 * v22)) + v8->x;
      v39 = (__m128)LODWORD(v15->y);
      v38 = (float)(v32 * (float)(v20 * v22)) + v31;
      v41 = (__m128)LODWORD(v15->x);
      v39.m128_f32[0] = v39.m128_f32[0] - v38;
      v40 = (float)(v33 * (float)(v20 * v22)) + v35;
      v43 = v39;
      v41.m128_f32[0] = v41.m128_f32[0] - v37;
      v42 = v15->z - v40;
      v43.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v41.m128_f32[0] * v41.m128_f32[0]))
                      + (float)(v42 * v42);
      v44 = v43;
      v44.m128_f32[0] = v43.m128_f32[0] - v65;
      if ( (float)(v43.m128_f32[0] - v65) >= 0.001 )
      {
        v44.m128_f32[0] = v44.m128_f32[0] / v43.m128_f32[0];
        v50 = v41;
        LODWORD(v51) = (unsigned __int128)_mm_sqrt_ps(v44);
        v50.m128_f32[0] = (float)(v41.m128_f32[0] * UFG::qVector3::msDirUp.z) - (float)(v42 * UFG::qVector3::msDirUp.x);
        v52 = v50;
        v53 = (float)(v42 * UFG::qVector3::msDirUp.y) - (float)(v39.m128_f32[0] * UFG::qVector3::msDirUp.z);
        v54 = (float)(v39.m128_f32[0] * UFG::qVector3::msDirUp.x) - (float)(v41.m128_f32[0] * UFG::qVector3::msDirUp.y);
        v52.m128_f32[0] = (float)((float)(v50.m128_f32[0] * v50.m128_f32[0]) + (float)(v53 * v53)) + (float)(v54 * v54);
        v55 = (float)(v22 / v51) / COERCE_FLOAT(_mm_sqrt_ps(v52));
        v56 = (float)(v38 + (float)((float)(v50.m128_f32[0] * v55) * v20)) - v15->y;
        v57 = (float)(v40 + (float)((float)(v54 * v55) * v20)) - v15->z;
        ray.x = (float)(v37 + (float)((float)(v53 * v55) * v20)) - v15->x;
        ray.y = v56;
        ray.z = v57;
        v58 = (float)(v56 * v51) + v15->y;
        v59 = (float)(v57 * v51) + v15->z;
        v8->x = (float)(ray.x * v51) + v15->x;
        v8->y = v58;
        v8->z = v59;
      }
      else
      {
        if ( v43.m128_f32[0] < 0.001 )
        {
          v39 = (__m128)LODWORD(v8->y);
          v41.m128_f32[0] = v8->x - v37;
          v39.m128_f32[0] = v39.m128_f32[0] - v38;
          v42 = v8->z - v40;
        }
        v45 = v39;
        v45.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v41.m128_f32[0] * v41.m128_f32[0]))
                        + (float)(v42 * v42);
        v46 = v22 / COERCE_FLOAT(_mm_sqrt_ps(v45));
        v47 = v39.m128_f32[0] * v46;
        v48 = v42 * v46;
        v49 = v41.m128_f32[0] * v46;
        v8->y = v47 + v38;
        v8->z = v48 + v40;
        ray.x = (float)((float)(v48 * v23) - (float)(v47 * v24)) * v20;
        v8->x = v49 + v37;
        ray.y = (float)((float)(v49 * v24) - (float)(v48 * v25)) * v20;
        ray.z = (float)((float)(v47 * v25) - (float)(v49 * v23)) * v20;
      }
    }
    v60 = UFG::RoadSpaceComponent::SteerTo(&resulta, v15, radius, v8, &ray);
    v61 = v60->y;
    v62 = v60->z;
    v8->x = v60->x;
    v8->y = v61;
    v8->z = v62;
  }
  return v8;
}

// File Line: 965
// RVA: 0x64F8C0
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::GetSteerTo(UFG::RoadSpaceComponent *this, UFG::qVector3 *result, UFG::qVector3 *steer_to, float offset, float steer_to_distance)
{
  float v5; // xmm0_4
  float v6; // xmm1_4
  bool v7; // bp
  UFG::qVector3 *v8; // rdi
  UFG::qVector3 *v9; // rbx
  UFG::RoadSpaceComponent *v10; // rsi
  float v11; // xmm2_4
  UFG::qVector3 *v12; // rax
  UFG::NavPath *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  UFG::qVector2 *v18; // rax
  UFG::RoadNetworkLane *v19; // rdi
  float v20; // xmm6_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm5_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-38h]

  v5 = UFG::qVector3::msZero.x;
  v6 = UFG::qVector3::msZero.y;
  v7 = this->m_pChaseTarget.m_pPointer != 0i64;
  v8 = steer_to;
  v9 = result;
  v10 = this;
  v11 = UFG::qVector3::msZero.z;
  if ( this->m_pChaseTarget.m_pPointer )
  {
    v12 = UFG::RoadSpaceComponent::GetSteerToFollow(this, &resulta, steer_to_distance);
    v5 = v12->x;
    v6 = v12->y;
    v11 = v12->z;
  }
  if ( v10->m_NavGuideEnabled && v10->m_NavGuide.m_Active )
  {
    v13 = v10->m_NavGuide.m_PathQueryOutput.m_pPath.m_pNavPath;
    if ( v13 && v13->m_aWaypoints.size )
    {
      UFG::RoadSpaceComponent::GetSteerToNavPath(v10, &resulta, v8, steer_to_distance);
      v14 = resulta.y;
      v9->x = resulta.x;
      v15 = resulta.z;
      v9->y = v14;
      v9->z = v15;
      return v9;
    }
    if ( v10->m_HasNavWanderCenter )
    {
      UFG::RoadSpaceComponent::GetSteerToNavWanderDestination(v10, &resulta, v8, steer_to_distance);
      v16 = resulta.y;
      v9->x = resulta.x;
      v17 = resulta.z;
      v9->y = v16;
      v9->z = v17;
      return v9;
    }
LABEL_27:
    v9->x = v8->x;
    v9->y = v8->y;
    v9->z = v8->z;
    return v9;
  }
  if ( !v10->mGuide.m_Attached )
  {
    if ( v7 )
    {
      v9->x = v5;
      v9->y = v6;
      v9->z = v11;
      return v9;
    }
    goto LABEL_27;
  }
  v18 = UFG::RoadNetworkGuide::GetTargetLocation((UFG::RippleGenerator *)&v10->mGuide);
  v19 = (UFG::RoadNetworkLane *)v18[1];
  v20 = v18->x;
  v21 = UFG::RoadNetworkLane::GetLength(*(UFG::RoadNetworkLane **)&v18[1]);
  v22 = 0.0;
  if ( v21 > 0.0 )
  {
    v22 = 10.0 / v21;
    if ( (float)(10.0 / v21) > 0.5 )
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
  v9->x = resulta.x;
  v27 = resulta.z;
  v9->y = v26;
  v9->z = v27;
  return v9;
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
void __fastcall UFG::RoadSpaceComponent::MoveCarToRoadNetworkPosition(UFG::RoadSpaceComponent *this, UFG::RoadNetworkLocation *location, bool snapToGround)
{
  bool v3; // bl
  UFG::RoadSpaceComponent *v4; // rdi
  UFG::allocator::free_link *v5; // rax
  UFG::qVector3 position; // [rsp+48h] [rbp-40h]
  UFG::qVector3 out; // [rsp+58h] [rbp-30h]
  UFG::qVector3 dir; // [rsp+68h] [rbp-20h]

  v3 = snapToGround;
  v4 = this;
  UFG::RoadNetworkLocation::GetVectors(location, &position, &dir);
  out = position;
  if ( v3 )
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
      v4->m_pSimObject->mNode.mUID,
      0,
      UFG::TeleportEvent::m_Name,
      &UFG::qVector3::msDirUp);
  UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v5);
}

// File Line: 1051
// RVA: 0x6586A0
void __fastcall UFG::RoadSpaceComponent::SetCarDestination(UFG::RoadSpaceComponent *this, UFG::TransformNodeComponent *xform)
{
  UFG::TransformNodeComponent *v2; // rdi
  UFG::RoadSpaceComponent *v3; // rbx
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4

  v2 = xform;
  v3 = this;
  if ( xform )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(xform);
    v8 = v2->mWorldTransform.v3.y;
    v9 = v2->mWorldTransform.v3.z;
    v3->mDestinationPosition.x = v2->mWorldTransform.v3.x;
    v3->mDestinationPosition.y = v8;
    v3->mDestinationPosition.z = v9;
    UFG::TransformNodeComponent::UpdateWorldTransform(v2);
    v10 = v2->mWorldTransform.v0.y;
    v11 = v2->mWorldTransform.v0.z;
    v3->mDestinationDirection.x = v2->mWorldTransform.v0.x;
    v3->mDestinationDirection.y = v10;
    v3->mDestinationDirection.z = v11;
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
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4

  if ( matrix )
  {
    v6 = matrix->v3.y;
    v7 = matrix->v3.z;
    this->mDestinationPosition.x = matrix->v3.x;
    this->mDestinationPosition.y = v6;
    this->mDestinationPosition.z = v7;
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
void __fastcall UFG::RoadSpaceComponent::SetChaseTarget(UFG::RoadSpaceComponent *this, UFG::SimObject *target)
{
  UFG::SimObject *v2; // rdi
  UFG::RoadSpaceComponent *v3; // rbx
  UFG::SimObjectVehicle *v4; // rcx
  unsigned __int16 v5; // r8
  UFG::VehicleSubjectComponent *v6; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::SimObject *v11; // rax
  UFG::SimObjectVehicle *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::VehicleSubjectComponent *v14; // rax
  UFG::SimObjectGame *v15; // rcx
  unsigned __int16 v16; // dx
  UFG::SimComponent *v17; // rax
  UFG::qMemoryPool *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::SimComponent *v20; // rax
  UFG::SimComponent *v21; // rsi
  UFG::SimObject *v22; // rdx
  unsigned __int16 v23; // cx
  unsigned int v24; // edi
  UFG::qVector3 result; // [rsp+38h] [rbp-40h]
  UFG::SimObjectModifier v26; // [rsp+48h] [rbp-30h]

  v2 = target;
  v3 = this;
  v4 = (UFG::SimObjectVehicle *)this->m_pChaseTarget.m_pPointer;
  if ( v4 != (UFG::SimObjectVehicle *)target )
  {
    if ( v4 )
    {
      v5 = v4->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v4->vfptr,
                                               UFG::VehicleSubjectComponent::_TypeUID);
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
          v6 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v4->vfptr,
                                                 UFG::VehicleSubjectComponent::_TypeUID);
        else
          v6 = (UFG::VehicleSubjectComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&v4->vfptr,
                                                                   UFG::VehicleSubjectComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::VehicleSubjectComponent::_TypeUID));
      }
      else
      {
        v6 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v4);
      }
      if ( v6 )
        UFG::VehicleSubjectComponent::RemoveChaser(v6, v3->m_pSimObject);
    }
    v7 = &v3->m_pChaseTarget;
    if ( v3->m_pChaseTarget.m_pPointer )
    {
      v8 = v7->mPrev;
      v9 = v3->m_pChaseTarget.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v3->m_pChaseTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->m_pChaseTarget.mPrev;
    }
    v3->m_pChaseTarget.m_pPointer = v2;
    if ( v2 )
    {
      v10 = v2->m_SafePointerList.mNode.mPrev;
      v10->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
      v7->mPrev = v10;
      v3->m_pChaseTarget.mNext = &v2->m_SafePointerList.mNode;
      v2->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    }
    if ( v3->m_pChaseTarget.m_pPointer )
    {
      v11 = v3->m_pSimObject;
      if ( v11 && v11->m_pTransformNodeComponent )
        UFG::RoadSpaceComponent::GetSteerToFollow(v3, &result, 0.0);
      v12 = (UFG::SimObjectVehicle *)v3->m_pChaseTarget.m_pPointer;
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 >> 14) & 1 )
        {
          v14 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v12->vfptr,
                                                  UFG::VehicleSubjectComponent::_TypeUID);
        }
        else if ( (v13 & 0x8000u) == 0 )
        {
          if ( (v13 >> 13) & 1 )
            v14 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v12->vfptr,
                                                    UFG::VehicleSubjectComponent::_TypeUID);
          else
            v14 = (UFG::VehicleSubjectComponent *)((v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)&v12->vfptr,
                                                                       UFG::VehicleSubjectComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::VehicleSubjectComponent::_TypeUID));
        }
        else
        {
          v14 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v12);
        }
        if ( v14 )
          UFG::VehicleSubjectComponent::AddChaser(v14, v3->m_pSimObject);
      }
      v15 = (UFG::SimObjectGame *)v3->m_pChaseTarget.m_pPointer;
      if ( !v15
        || ((v16 = v15->m_Flags, !((v16 >> 14) & 1)) ? ((v16 & 0x8000u) == 0 ? (!((v16 >> 13) & 1) ? (!((v16 >> 12) & 1) ? (v17 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v15->vfptr, UFG::RoadSpaceComponent::_TypeUID)) : (v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::RoadSpaceComponent::_TypeUID))) : (v17 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::RoadSpaceComponent::_TypeUID))) : (v17 = v15->m_Components.p[24].m_pComponent)) : (v17 = v15->m_Components.p[24].m_pComponent),
            !v17) )
      {
        v18 = UFG::GetSimulationMemoryPool();
        v19 = UFG::qMemoryPool::Allocate(v18, 0x7A0ui64, "RoadSpaceComponent", 0i64, 1u);
        if ( v19 )
        {
          UFG::RoadSpaceComponent::RoadSpaceComponent((UFG::RoadSpaceComponent *)v19);
          v21 = v20;
        }
        else
        {
          v21 = 0i64;
        }
        v22 = v3->m_pChaseTarget.m_pPointer;
        v23 = v22->m_Flags;
        if ( (v23 >> 14) & 1 || (v23 & 0x8000u) != 0 )
          v24 = 24;
        else
          v24 = -1;
        UFG::SimObjectModifier::SimObjectModifier(&v26, v22, 1);
        UFG::SimObjectModifier::AttachComponent(&v26, v21, v24);
        UFG::SimObjectModifier::Close(&v26);
        UFG::SimObjectModifier::~SimObjectModifier(&v26);
        v21[30].m_TypeUID |= 1u;
      }
    }
    v3->m_fChaseFailedTimer = 0.0;
  }
}

// File Line: 1123
// RVA: 0x662840
void __fastcall UFG::RoadSpaceComponent::UpdateNavGuide(UFG::RoadSpaceComponent *this)
{
  UFG::RoadSpaceComponent *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  float v3; // xmm6_4
  unsigned __int16 v4; // dx
  UFG::PhysicsMoverInterface *v5; // rax
  __m128 v6; // xmm1
  __m128 v7; // xmm2
  float v8; // xmm3_4
  float v9; // xmm6_4
  UFG::qVector3 max; // [rsp+20h] [rbp-38h]
  UFG::qVector3 min; // [rsp+30h] [rbp-28h]

  v1 = this;
  if ( this->m_NavGuide.m_Initialized )
    goto LABEL_15;
  v2 = (UFG::SimObjectGame *)this->m_pSimObject;
  v3 = FLOAT_2_0;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( !((v4 >> 14) & 1) )
    {
      if ( (v4 & 0x8000u) != 0 )
      {
        v5 = (UFG::PhysicsMoverInterface *)v2->m_Components.p[34].m_pComponent;
        goto LABEL_10;
      }
      if ( !((v4 >> 13) & 1) )
      {
        if ( (v4 >> 12) & 1 )
          v5 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               v2,
                                               UFG::PhysicsMoverInterface::_TypeUID);
        else
          v5 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v2->vfptr,
                                               UFG::PhysicsMoverInterface::_TypeUID);
LABEL_10:
        if ( v5 )
        {
          UFG::PhysicsMoverInterface::GetBoundingBoxLocalSpace(v5, &min, &max);
          v6 = (__m128)LODWORD(max.x);
          v7 = (__m128)LODWORD(min.y);
          v6.m128_f32[0] = (float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(max.y * max.y);
          LODWORD(v8) = (unsigned __int128)_mm_sqrt_ps(v6);
          v7.m128_f32[0] = (float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(min.x * min.x);
          LODWORD(v9) = (unsigned __int128)_mm_sqrt_ps(v7);
          if ( v9 <= v8 )
            v9 = v8;
          v3 = v9 + 0.5;
        }
        goto LABEL_14;
      }
    }
  }
LABEL_14:
  v1->m_NavGuide.m_NavParams.m_fRadius = v3;
  v1->m_NavGuide.m_Initialized = 1;
LABEL_15:
  if ( v1->m_NavGuide.m_Active )
    UFG::NavGuide::UpdatePathQuery(&v1->m_NavGuide);
}

// File Line: 1150
// RVA: 0x6603A0
void __fastcall UFG::RoadSpaceComponent::UpdateChaseMatrix(UFG::RoadSpaceComponent *this)
{
  UFG::SimObject *rdi1; // rdi
  UFG::RoadSpaceComponent *rbx1; // rbx
  UFG::TransformNodeComponent *v3; // rdi
  float v4; // xmm1_4
  float v5; // xmm0_4
  UFG::SimComponent *v6; // rcx
  float v7; // xmm1_4
  float *v8; // rax
  float v9; // xmm7_4
  __m128 v10; // xmm6
  float v11; // xmm3_4
  __m128 v12; // xmm2
  float v13; // xmm1_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  UFG::VehicleFormations *v16; // rax
  UFG::RoadNetworkNode *v17; // rcx
  UFG::RoadNetworkLane *v18; // rdi
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  UFG::RoadNetworkNode *v23; // rcx
  float v24; // xmm0_4
  int v25; // xmm6_4
  int v26; // xmm7_4
  int v27; // xmm3_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  UFG::SimObjectVehicle *v30; // rcx
  unsigned __int16 v31; // dx
  UFG::VehicleSubjectComponent *v32; // rax
  UFG::SimObjectGame *v33; // rcx
  unsigned __int16 v34; // dx
  UFG::CharacterOccupantComponent *v35; // rax
  UFG::SimObjectVehicle *v36; // rax
  UFG::VehicleSubjectComponent *v37; // rax
  __m128 v38; // xmm1
  float v39; // xmm1_4
  float v40; // xmm12_4
  float v41; // xmm11_4
  float v42; // xmm10_4
  float v43; // xmm2_4
  float v44; // xmm9_4
  float v45; // xmm3_4
  float v46; // xmm1_4
  signed __int64 v47; // rdx
  float v48; // xmm12_4
  float v49; // xmm10_4
  float v50; // xmm11_4
  UFG::qVector3 v1; // [rsp+18h] [rbp-59h]
  UFG::qVector3 pos; // [rsp+28h] [rbp-49h]
  UFG::qVector3 v2; // [rsp+38h] [rbp-39h]
  UFG::qVector3 result; // [rsp+48h] [rbp-29h]
  void *retaddr; // [rsp+D8h] [rbp+67h]

  rdi1 = this->m_pSimObject;
  rbx1 = this;
  if ( !rdi1 )
    return;
  v3 = rdi1->m_pTransformNodeComponent;
  if ( !v3 || !this->m_pSubject.m_pSimComponent )
    return;
  UFG::TransformNodeComponent::UpdateWorldTransform(v3);
  v4 = v3->mWorldTransform.v3.y;
  pos.x = v3->mWorldTransform.v3.x;
  v5 = v3->mWorldTransform.v3.z;
  pos.y = v4;
  pos.z = v5;
  UFG::TransformNodeComponent::UpdateWorldTransform(v3);
  v6 = rbx1->m_pSubject.m_pSimComponent;
  v7 = v3->mWorldTransform.v0.y;
  v1.x = v3->mWorldTransform.v0.x;
  v1.z = v3->mWorldTransform.v0.z;
  v1.y = v7;
  v8 = (float *)((__int64 (*)(void))v6->vfptr[20].__vecDelDtor)();
  v9 = v8[1];
  v10 = (__m128)*(unsigned int *)v8;
  v11 = v8[2];
  v12 = v10;
  v12.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v9 * v9)) + (float)(v11 * v11);
  if ( v12.m128_f32[0] <= 0.25 )
  {
    v15 = v1.y;
    v14 = v1.x;
  }
  else
  {
    if ( v12.m128_f32[0] == 0.0 )
      v13 = 0.0;
    else
      v13 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v12));
    v14 = v10.m128_f32[0] * v13;
    v15 = v9 * v13;
    v1.x = v14;
    v1.y = v15;
    v1.z = v11 * v13;
  }
  v16 = rbx1->m_pChaseFormation;
  if ( v16 )
  {
    if ( UFG::gpRoadNetworkResource )
    {
      v17 = (UFG::RoadNetworkNode *)&v16->mpClosestSegment->mType;
      if ( v17 )
      {
        v18 = UFG::RoadNetworkNode::GetLane(v17, v16->mClosestLaneIndex);
        UFG::RoadNetworkLane::GetNearestPoint(v18, &result, &pos, (float *)&retaddr);
        v19 = UFG::RoadNetworkLane::GetLength(v18);
        v20 = v19;
        v21 = v19 - 0.5;
        v22 = v20 * 0.0;
        if ( v21 < 0.0 )
          v21 = 0.0;
        if ( v22 < 0.5 || v22 > v21 )
        {
          v15 = v1.y;
          v14 = v1.x;
        }
        else
        {
          if ( v18->mNode.mOffset )
            v23 = (UFG::RoadNetworkNode *)((char *)v18 + v18->mNode.mOffset);
          else
            v23 = 0i64;
          UFG::RoadNetworkNode::GetTangent(v23, &v2, v18->mLaneIndex, 0.0);
          pos.x = result.x + (float)((float)(pos.x - result.x) * 0.60000002);
          pos.y = result.y + (float)((float)(pos.y - result.y) * 0.60000002);
          pos.z = result.z + (float)((float)(pos.z - result.z) * 0.60000002);
          v24 = UFG::qAngleBetween(&v1, &v2);
          v25 = SLODWORD(v2.x);
          v26 = SLODWORD(v2.y);
          v27 = SLODWORD(v2.z);
          if ( v24 > 1.5707964 )
          {
            v25 = LODWORD(v2.x) ^ _xmm[0];
            v26 = LODWORD(v2.y) ^ _xmm[0];
            v27 = LODWORD(v2.z) ^ _xmm[0];
          }
          v28 = (float)((float)(*(float *)&v25 * *(float *)&v25) + (float)(*(float *)&v26 * *(float *)&v26))
              + (float)(*(float *)&v27 * *(float *)&v27);
          if ( v28 == 0.0 )
            v29 = 0.0;
          else
            v29 = 1.0 / fsqrt(v28);
          v14 = *(float *)&v25 * v29;
          v15 = *(float *)&v26 * v29;
          v1.x = v14;
          v1.y = v15;
          v1.z = *(float *)&v27 * v29;
        }
      }
    }
  }
  v30 = (UFG::SimObjectVehicle *)rbx1->m_pSimObject;
  if ( v30 )
  {
    v31 = v30->m_Flags;
    if ( (v31 >> 14) & 1 )
    {
      v32 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              (UFG::SimObjectGame *)&v30->vfptr,
                                              UFG::VehicleSubjectComponent::_TypeUID);
    }
    else if ( (v31 & 0x8000u) == 0 )
    {
      if ( (v31 >> 13) & 1 )
      {
        v32 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v30->vfptr,
                                                UFG::VehicleSubjectComponent::_TypeUID);
      }
      else if ( (v31 >> 12) & 1 )
      {
        v32 = (UFG::VehicleSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                (UFG::SimObjectGame *)&v30->vfptr,
                                                UFG::VehicleSubjectComponent::_TypeUID);
      }
      else
      {
        v32 = (UFG::VehicleSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                (UFG::SimObject *)&v30->vfptr,
                                                UFG::VehicleSubjectComponent::_TypeUID);
      }
    }
    else
    {
      v32 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v30);
    }
    if ( v32 && UFG::VehicleSubjectComponent::IsBoat(v32) )
    {
LABEL_55:
      v14 = v1.x;
      v15 = v1.y;
      if ( (float)((float)((float)((float)(v1.x - (float)(v1.z * 0.0)) * (float)(v1.x - (float)(v1.z * 0.0)))
                         + (float)((float)((float)(v1.z * 0.0) - v1.y) * (float)((float)(v1.z * 0.0) - v1.y)))
                 + (float)((float)((float)(v1.y * 0.0) - (float)(v1.x * 0.0))
                         * (float)((float)(v1.y * 0.0) - (float)(v1.x * 0.0)))) > 0.0000000099999991 )
      {
        v38 = (__m128)LODWORD(v1.y);
        v38.m128_f32[0] = (float)(v1.y * v1.y) + (float)(v1.x * v1.x);
        if ( v38.m128_f32[0] == 0.0 )
          v39 = 0.0;
        else
          v39 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v38));
        v14 = v1.x * v39;
        v15 = v1.y * v39;
        v1.z = v39 * 0.0;
        v1.x = v1.x * v39;
        v1.y = v1.y * v39;
      }
      goto LABEL_61;
    }
    v15 = v1.y;
    v14 = v1.x;
  }
  v33 = (UFG::SimObjectGame *)rbx1->m_pSimObject;
  if ( !v33 )
    goto LABEL_61;
  v34 = v33->m_Flags;
  if ( (v34 >> 14) & 1 )
  {
    v35 = (UFG::CharacterOccupantComponent *)v33->m_Components.p[44].m_pComponent;
  }
  else
  {
    if ( (v34 & 0x8000u) == 0 )
    {
      if ( (v34 >> 13) & 1 )
        v35 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v33,
                                                   UFG::CharacterOccupantComponent::_TypeUID);
      else
        v35 = (UFG::CharacterOccupantComponent *)((v34 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v33,
                                                                      UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v33->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
    }
    else
    {
      v35 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v33,
                                                 UFG::CharacterOccupantComponent::_TypeUID);
    }
    v14 = v1.x;
    v15 = v1.y;
  }
  if ( !v35 )
    goto LABEL_61;
  v36 = (UFG::SimObjectVehicle *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v35);
  if ( v36 )
  {
    v37 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v36);
    if ( v37 )
    {
      if ( UFG::VehicleSubjectComponent::IsBoat(v37) )
        goto LABEL_55;
    }
  }
  v15 = v1.y;
  v14 = v1.x;
LABEL_61:
  v40 = v14 - (float)(v1.z * 0.0);
  v41 = (float)(v1.z * 0.0) - v15;
  v42 = (float)(v15 * 0.0) - (float)(v14 * 0.0);
  v43 = (float)((float)(v40 * v40) + (float)(v41 * v41)) + (float)(v42 * v42);
  if ( v43 == 0.0 )
    v44 = 0.0;
  else
    v44 = 1.0 / fsqrt(v43);
  v45 = v1.z;
  v46 = pos.y;
  rbx1->m_ChaseWorld.v3.w = 1.0;
  v47 = (signed __int64)&rbx1->m_ChaseWorld;
  v48 = v40 * v44;
  v49 = v42 * v44;
  rbx1->m_ChaseWorld.v3.y = v46;
  v50 = v41 * v44;
  rbx1->m_ChaseWorld.v3.x = pos.x;
  rbx1->m_ChaseWorld.v3.z = pos.z;
  *(float *)v47 = v14;
  *(float *)(v47 + 4) = v15;
  *(_DWORD *)(v47 + 12) = 0;
  *(float *)(v47 + 8) = v45;
  rbx1->m_ChaseWorld.v1.x = v50;
  rbx1->m_ChaseWorld.v1.y = v48;
  rbx1->m_ChaseWorld.v1.w = 0.0;
  rbx1->m_ChaseWorld.v1.z = v49;
  rbx1->m_ChaseWorld.v2.x = (float)(v49 * v15) - (float)(v48 * v45);
  rbx1->m_ChaseWorld.v2.y = (float)(v50 * v45) - (float)(v49 * v14);
  rbx1->m_ChaseWorld.v2.w = 0.0;
  rbx1->m_ChaseWorld.v2.z = (float)(v48 * v14) - (float)(v50 * v15);
  UFG::qInverseAffine(&rbx1->m_WorldChase, &rbx1->m_ChaseWorld);
}

// File Line: 1258
// RVA: 0x64D7A0
UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *__fastcall UFG::RoadSpaceComponent::GetCarChaseTargetFormation(UFG::RoadSpaceComponent *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *result; // rax

  v1 = (UFG::SimObjectGame *)this->m_pChaseTarget.m_pPointer;
  if ( v1
    && ((v2 = v1->m_Flags, !((v2 >> 14) & 1)) ? ((v2 & 0x8000u) == 0 ? (!((v2 >> 13) & 1) ? (!((v2 >> 12) & 1) ? (v3 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::RoadSpaceComponent::_TypeUID)) : (v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RoadSpaceComponent::_TypeUID))) : (v3 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RoadSpaceComponent::_TypeUID))) : (v3 = v1->m_Components.p[24].m_pComponent)) : (v3 = v1->m_Components.p[24].m_pComponent),
        v3) )
  {
    result = v3[26].m_BoundComponentHandles.mNode.mPrev;
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 1277
// RVA: 0x6663F0
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::WorldToChase(UFG::RoadSpaceComponent *this, UFG::qVector3 *result, UFG::qVector3 *position)
{
  UFG::qVector3 *v3; // rsi
  UFG::qVector3 *v4; // rdi
  UFG::RoadSpaceComponent *v5; // rbx
  float v6; // xmm6_4
  float v7; // xmm0_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  float v10; // xmm3_4
  float v11; // xmm7_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  __m128 v16; // xmm2
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm4_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm6_4
  float v23; // xmm6_4
  UFG::qVector3 b; // [rsp+20h] [rbp-48h]
  UFG::qVector3 a; // [rsp+30h] [rbp-38h]

  v3 = position;
  v4 = result;
  v5 = this;
  if ( this->m_PositionTrail.mTrail.mCount <= 0 )
    goto LABEL_13;
  v6 = FLOAT_N1_0;
  v7 = this->m_PositionTrail.mTrail.mData[this->m_PositionTrail.mTrail.mLast].fCurvature;
  if ( v7 <= -1.0 )
  {
    v7 = FLOAT_N1_0;
    goto LABEL_6;
  }
  if ( v7 < 1.0 )
  {
LABEL_6:
    if ( v7 < -0.0099999998 || v7 > 0.0099999998 )
    {
      if ( v7 <= 0.0 )
      {
        if ( v7 >= 0.0 )
          v6 = 0.0;
      }
      else
      {
        v6 = *(float *)&FLOAT_1_0;
      }
      goto LABEL_12;
    }
LABEL_13:
    v19 = position->z;
    v20 = position->z;
    v21 = (float)(position->x * this->m_WorldChase.v0.y) + (float)(position->y * this->m_WorldChase.v1.y);
    v22 = (float)(position->x * this->m_WorldChase.v0.z) + (float)(position->y * this->m_WorldChase.v1.z);
    result->x = (float)((float)((float)(position->y * this->m_WorldChase.v1.x)
                              + (float)(position->x * this->m_WorldChase.v0.x))
                      + (float)(position->z * this->m_WorldChase.v2.x))
              + this->m_WorldChase.v3.x;
    v23 = (float)(v22 + (float)(v19 * this->m_WorldChase.v2.z)) + this->m_WorldChase.v3.z;
    result->y = (float)(v21 + (float)(v20 * this->m_WorldChase.v2.y)) + this->m_WorldChase.v3.y;
    result->z = v23;
    return v4;
  }
  v7 = *(float *)&FLOAT_1_0;
  v6 = *(float *)&FLOAT_1_0;
LABEL_12:
  v8 = this->m_ChaseWorld.v1.x;
  v9 = this->m_ChaseWorld.v1.y;
  v10 = this->m_ChaseWorld.v1.z;
  v11 = 1.0 / v7;
  v12 = (float)(this->m_ChaseWorld.v1.x * (float)(1.0 / v7)) + this->m_ChaseWorld.v3.x;
  v13 = (float)((float)(this->m_ChaseWorld.v1.y * (float)(1.0 / v7)) + this->m_ChaseWorld.v3.y) - position->y;
  v14 = (float)((float)(this->m_ChaseWorld.v1.z * v11) + this->m_ChaseWorld.v3.z) - position->z;
  b.x = v12 - position->x;
  b.y = v13;
  b.z = v14;
  a.x = v8 * v6;
  a.y = v9 * v6;
  a.z = v10 * v6;
  v15 = UFG::qSignedAngleBetween(&a, &b);
  v16 = (__m128)LODWORD(b.y);
  v17 = b.z;
  v4->x = v15 * v11;
  v16.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(b.x * b.x)) + (float)(v17 * v17);
  v18 = v3->z - v5->m_ChaseWorld.v3.z;
  v4->y = v11 - (float)(COERCE_FLOAT(_mm_sqrt_ps(v16)) * v6);
  v4->z = v18;
  return v4;
}

// File Line: 1296
// RVA: 0x647BD0
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::ChaseToWorld(UFG::RoadSpaceComponent *this, UFG::qVector3 *result, UFG::qVector3 *position, UFG::qVector3 *p_direction)
{
  UFG::qVector3 *v4; // rdi
  UFG::qVector3 *v5; // rsi
  UFG::RoadSpaceComponent *v6; // rbx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm4_4
  UFG::qVector3 *v10; // rax
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm6_4
  float v14; // xmm6_4
  float v15; // xmm13_4
  float v16; // xmm11_4
  float v17; // xmm6_4
  float v18; // xmm14_4
  float v19; // xmm7_4
  float v20; // xmm10_4
  float v21; // xmm9_4
  float v22; // xmm10_4
  float v23; // xmm8_4
  float v24; // xmm9_4
  float v25; // xmm7_4
  float v26; // xmm15_4
  float v27; // xmm6_4
  float v28; // xmm7_4
  float v29; // xmm4_4
  float v30; // xmm6_4
  float v31; // xmm4_4
  float v32; // xmm5_4
  float v33; // xmm6_4
  float v34; // xmm2_4
  float v35; // xmm12_4
  float v36; // xmm0_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm4_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm6_4
  float v44; // xmm6_4
  float v45; // [rsp+D0h] [rbp+8h]

  v4 = p_direction;
  v5 = result;
  v6 = this;
  if ( !this->m_pChaseFormation )
  {
    if ( this->m_PositionTrail.mTrail.mCount > 0 )
    {
      v15 = FLOAT_N1_0;
      v16 = this->m_PositionTrail.mTrail.mData[this->m_PositionTrail.mTrail.mLast].fCurvature;
      if ( v16 <= -1.0 )
      {
        v16 = FLOAT_N1_0;
      }
      else if ( v16 >= 1.0 )
      {
        v16 = *(float *)&FLOAT_1_0;
LABEL_12:
        v17 = v16 * position->x;
        v18 = 1.0 / v16;
        v19 = position->y - (float)(1.0 / v16);
        v20 = sinf(v17);
        v21 = v20 * v19;
        v22 = (float)(v20 * v19) * v6->m_ChaseWorld.v0.z;
        v23 = v21 * v6->m_ChaseWorld.v0.x;
        v24 = v21 * v6->m_ChaseWorld.v0.y;
        v25 = cosf(v17) * v19;
        v26 = (float)(v25 * v6->m_ChaseWorld.v1.z) - v22;
        v27 = (float)(v25 * v6->m_ChaseWorld.v1.y) - v24;
        v28 = (float)(v25 * v6->m_ChaseWorld.v1.x) - v23;
        v45 = v27;
        if ( v4 )
        {
          v29 = (float)(v26 * UFG::qVector3::msAxisZ.y) - (float)(v27 * UFG::qVector3::msAxisZ.z);
          v30 = (float)(v27 * UFG::qVector3::msAxisZ.x) - (float)(v28 * UFG::qVector3::msAxisZ.y);
          if ( v16 <= 0.0 )
          {
            if ( v16 >= 0.0 )
              v15 = 0.0;
          }
          else
          {
            v15 = *(float *)&FLOAT_1_0;
          }
          v31 = v29 * v15;
          v32 = (float)((float)(v28 * UFG::qVector3::msAxisZ.z) - (float)(v26 * UFG::qVector3::msAxisZ.x)) * v15;
          v33 = v30 * v15;
          v34 = (float)((float)(v32 * v32) + (float)(v31 * v31)) + (float)(v33 * v33);
          if ( v34 == 0.0 )
            v35 = 0.0;
          else
            v35 = 1.0 / fsqrt(v34);
          v4->z = v33 * v35;
          v27 = v45;
          v4->x = v31 * v35;
          v4->y = v32 * v35;
        }
        v36 = (float)((float)(v18 * v6->m_ChaseWorld.v1.x) + v6->m_ChaseWorld.v3.x) + v28;
        v37 = (float)((float)(v18 * v6->m_ChaseWorld.v1.y) + v6->m_ChaseWorld.v3.y) + v27;
        v5->z = (float)((float)(v18 * v6->m_ChaseWorld.v1.z) + v6->m_ChaseWorld.v3.z) + v26;
        v5->x = v36;
        v5->y = v37;
        return v5;
      }
      if ( v16 < -0.0099999998 || v16 > 0.0099999998 )
        goto LABEL_12;
    }
    if ( p_direction )
    {
      v38 = this->m_ChaseWorld.v0.y;
      v39 = this->m_ChaseWorld.v0.z;
      p_direction->x = this->m_ChaseWorld.v0.x;
      p_direction->y = v38;
      p_direction->z = v39;
    }
    v40 = position->z;
    v41 = position->z;
    v42 = (float)(position->y * this->m_ChaseWorld.v1.y) + (float)(position->x * this->m_ChaseWorld.v0.y);
    v43 = (float)(position->y * this->m_ChaseWorld.v1.z) + (float)(position->x * this->m_ChaseWorld.v0.z);
    result->x = (float)((float)((float)(position->y * this->m_ChaseWorld.v1.x)
                              + (float)(position->x * this->m_ChaseWorld.v0.x))
                      + (float)(position->z * this->m_ChaseWorld.v2.x))
              + this->m_ChaseWorld.v3.x;
    v44 = (float)(v43 + (float)(v40 * this->m_ChaseWorld.v2.z)) + this->m_ChaseWorld.v3.z;
    result->y = (float)(v42 + (float)(v41 * this->m_ChaseWorld.v2.y)) + this->m_ChaseWorld.v3.y;
    result->z = v44;
    return v5;
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
  v11 = position->z;
  v12 = (float)(position->y * this->m_ChaseWorld.v1.y) + (float)(position->x * this->m_ChaseWorld.v0.y);
  v13 = (float)(position->y * this->m_ChaseWorld.v1.z) + (float)(position->x * this->m_ChaseWorld.v0.z);
  result->x = (float)((float)((float)(position->y * this->m_ChaseWorld.v1.x)
                            + (float)(position->x * this->m_ChaseWorld.v0.x))
                    + (float)(position->z * this->m_ChaseWorld.v2.x))
            + this->m_ChaseWorld.v3.x;
  v14 = (float)(v13 + (float)(v9 * this->m_ChaseWorld.v2.z)) + this->m_ChaseWorld.v3.z;
  result->y = (float)(v12 + (float)(v11 * this->m_ChaseWorld.v2.y)) + this->m_ChaseWorld.v3.y;
  result->z = v14;
  return v10;
}

// File Line: 1332
// RVA: 0x65AE80
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::SteerTo(UFG::qVector3 *result, UFG::qVector3 *centre, float radius, UFG::qVector3 *point, UFG::qVector3 *ray)
{
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm6_4
  float v8; // xmm9_4
  float v9; // xmm8_4
  float v10; // xmm10_4
  float v11; // xmm11_4
  __m128 v12; // xmm12
  float v13; // xmm13_4
  float v14; // xmm3_4
  __m128 v15; // xmm7
  __m128 v16; // xmm14
  __m128 v17; // xmm15
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float v23; // xmm2_4

  v5 = centre->x;
  v6 = centre->y;
  v7 = centre->z;
  v12 = (__m128)LODWORD(point->y);
  v8 = ray->y;
  v9 = ray->x;
  v10 = ray->z;
  v11 = point->x - centre->x;
  v12.m128_f32[0] = v12.m128_f32[0] - v6;
  v15 = (__m128)LODWORD(ray->x);
  v16 = v12;
  v13 = point->z - v7;
  v14 = (float)((float)(v9 * v9) + (float)(v8 * v8)) + (float)(v10 * v10);
  v15.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v11) + (float)(ray->y * v12.m128_f32[0])) + (float)(ray->z * v13);
  v17 = v15;
  v16.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11)) + (float)(v13 * v13);
  v17.m128_f32[0] = (float)(v15.m128_f32[0] * v15.m128_f32[0])
                  - (float)((float)(v16.m128_f32[0] - (float)(radius * radius)) * v14);
  if ( v17.m128_f32[0] < 0.0 || v14 < 0.0000099999997 )
  {
    v23 = radius / COERCE_FLOAT(_mm_sqrt_ps(v16));
    result->z = (float)(v23 * v13) + v7;
    result->x = (float)(v23 * v11) + v5;
    result->y = (float)(v23 * v12.m128_f32[0]) + v6;
  }
  else
  {
    v18 = COERCE_FLOAT(_mm_sqrt_ps(v17)) * 2.0;
    v19 = 1.0 / (float)(v14 * 2.0);
    v20 = (float)(v15.m128_f32[0] * -2.0) - v18;
    v21 = (float)(v18 - (float)(v15.m128_f32[0] * 2.0)) * v19;
    v22 = v20 * v19;
    if ( v21 <= v22 )
      v21 = v22;
    result->x = (float)(v5 + v11) + (float)(v9 * v21);
    result->y = (float)(v6 + v12.m128_f32[0]) + (float)(v8 * v21);
    result->z = (float)(v7 + v13) + (float)(v10 * v21);
  }
  return result;
}

// File Line: 1391
// RVA: 0x650740
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::GetSteerToNavPath(UFG::RoadSpaceComponent *this, UFG::qVector3 *result, UFG::qVector3 *defaultSteerTo, float steerToDist)
{
  UFG::NavPath *v4; // r14
  UFG::qVector3 *v5; // rbx
  unsigned int v6; // esi
  unsigned int v7; // edi
  __int64 v8; // r12
  UFG::qVector3 *v9; // r15
  UFG::NavWaypoint *v10; // rax
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::qVector3 *v14; // rax
  UFG::NavGuide *v15; // rbp
  float v16; // xmm8_4
  float v17; // xmm9_4
  float v18; // xmm4_4
  float v19; // xmm10_4
  float v20; // xmm5_4
  unsigned int v21; // edi
  UFG::qVector3 *v22; // rax
  float v23; // xmm1_4
  float v24; // xmm0_4
  UFG::NavWaypoint *v25; // rax
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  UFG::qVector3 resulta; // [rsp+30h] [rbp-A8h]
  UFG::qVector3 ray; // [rsp+40h] [rbp-98h]
  UFG::qVector3 v32; // [rsp+50h] [rbp-88h]
  UFG::qVector3 v33; // [rsp+60h] [rbp-78h]

  v4 = this->m_NavGuide.m_PathQueryOutput.m_pPath.m_pNavPath;
  v5 = result;
  if ( v4 && (v6 = v4->m_aWaypoints.size) != 0 )
  {
    v7 = this->m_NavGuide.m_CurrPathPointIndex;
    v8 = v6 - 1;
    v9 = &this->m_NavGuide.m_Pos;
    if ( v7 == (_DWORD)v8 )
    {
      v10 = v4->m_aWaypoints.p;
      v11 = v10[v8].m_navPosition.m_vPosition.x;
      v12 = v10[v8].m_navPosition.m_vPosition.y;
      v13 = v10[v8].m_navPosition.m_vPosition.z;
      v14 = result;
      result->x = v11;
      result->y = v12;
      result->z = v13;
    }
    else
    {
      v15 = &this->m_NavGuide;
      UFG::NavGuide::GetPathSegmentPos(&this->m_NavGuide, &resulta, v7, &this->m_NavGuide.m_Pos);
      v16 = v9->x;
      v17 = v9->y;
      v18 = resulta.y;
      v19 = v9->z;
      v20 = resulta.z;
      if ( (float)((float)((float)((float)(v9->y - resulta.y) * (float)(v9->y - resulta.y))
                         + (float)((float)(v9->x - resulta.x) * (float)(v9->x - resulta.x)))
                 + (float)((float)(v9->z - resulta.z) * (float)(v9->z - resulta.z))) <= (float)(steerToDist * steerToDist) )
      {
        UFG::NavGuide::GetPathSegmentDir(v15, &ray, v7);
        v21 = v7 + 1;
        if ( v21 >= v6 )
        {
LABEL_12:
          v25 = v4->m_aWaypoints.p;
          v26 = v25[v8].m_navPosition.m_vPosition.y;
          v27 = v25[v8].m_navPosition.m_vPosition.z;
          v5->x = v25[v8].m_navPosition.m_vPosition.x;
          v5->y = v26;
          v5->z = v27;
        }
        else
        {
          while ( 1 )
          {
            UFG::NavGuide::GetPathSegmentPos(v15, &v32, v21, v9);
            if ( (float)((float)((float)((float)(v17 - v32.y) * (float)(v17 - v32.y))
                               + (float)((float)(v16 - v32.x) * (float)(v16 - v32.x)))
                       + (float)((float)(v19 - v32.z) * (float)(v19 - v32.z))) > (float)(steerToDist * steerToDist) )
              break;
            resulta = v32;
            v22 = UFG::NavGuide::GetPathSegmentDir(v15, &v33, v21++);
            v23 = v22->y;
            ray.x = v22->x;
            v24 = v22->z;
            ray.y = v23;
            ray.z = v24;
            if ( v21 >= v6 )
              goto LABEL_12;
          }
          UFG::RoadSpaceComponent::SteerTo(&v32, v9, steerToDist, &resulta, &ray);
          v28 = v32.y;
          v5->x = v32.x;
          v29 = v32.z;
          v5->y = v28;
          v5->z = v29;
        }
      }
      else
      {
        v5->x = resulta.x;
        v5->y = v18;
        v5->z = v20;
      }
      v14 = v5;
    }
  }
  else
  {
    result->x = defaultSteerTo->x;
    result->y = defaultSteerTo->y;
    result->z = defaultSteerTo->z;
    v14 = result;
  }
  return v14;
}

// File Line: 1438
// RVA: 0x650A20
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::GetSteerToNavWanderDestination(UFG::RoadSpaceComponent *this, UFG::qVector3 *result, UFG::qVector3 *defaultSteerTo, float steerToDist)
{
  UFG::RoadSpaceComponent *v4; // rbx
  float v5; // xmm6_4
  UFG::qVector3 *v6; // rdi
  UFG::qVector3 *v7; // rsi
  __int64 v8; // rax
  float v9; // xmm2_4
  __m128 v10; // xmm3
  float v11; // xmm4_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  __m128 v14; // xmm5
  float v15; // xmm1_4
  UFG::qVector3 ray; // [rsp+30h] [rbp-28h]

  v4 = this;
  v5 = steerToDist;
  v6 = result;
  v7 = (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::SimComponent *, UFG::qVector3 *, UFG::qVector3 *))this->m_pSubject.m_pSimComponent->vfptr[17].__vecDelDtor)(
                          this->m_pSubject.m_pSimComponent,
                          result,
                          defaultSteerTo);
  v8 = ((__int64 (*)(void))v4->m_pSubject.m_pSimComponent->vfptr[16].__vecDelDtor)();
  v10 = (__m128)LODWORD(v4->m_NavWanderDestPos.y);
  v9 = v4->m_NavWanderDestPos.x - v7->x;
  v10.m128_f32[0] = v10.m128_f32[0] - v7->y;
  v14 = v10;
  v11 = v4->m_NavWanderDestPos.z - v7->z;
  v12 = *(float *)(v8 + 4);
  ray.x = *(float *)v8;
  v13 = *(float *)(v8 + 8);
  ray.y = v12;
  ray.z = v13;
  v14.m128_f32[0] = (float)((float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v9 * v9)) + (float)(v11 * v11);
  if ( v14.m128_f32[0] > 0.0000010000001 )
  {
    v15 = 0.0;
    if ( v14.m128_f32[0] != 0.0 )
      v15 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v14));
    ray.x = v9 * v15;
    ray.y = v10.m128_f32[0] * v15;
    ray.z = v11 * v15;
  }
  UFG::RoadSpaceComponent::SteerTo(v6, v7, v5, &v4->m_NavWanderDestPos, &ray);
  return v6;
}

// File Line: 1450
// RVA: 0x650130
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::GetSteerToFollow(UFG::RoadSpaceComponent *this, UFG::qVector3 *result, float steer_to_distance)
{
  UFG::SimObject *v3; // rbp
  signed int v4; // esi
  UFG::qVector3 *v5; // r13
  UFG::RoadSpaceComponent *v6; // r14
  float v7; // xmm7_4
  UFG::TransformNodeComponent *v8; // rbp
  UFG::SimObjectGame *v9; // rcx
  UFG::TransformNodeComponent *v10; // rdi
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rbx
  UFG::SimComponent *v13; // rax
  UFG::qVector3 *v14; // r15
  UFG::qVector3 *v15; // rax
  float v16; // xmm10_4
  __m128 v17; // xmm8
  float v18; // xmm11_4
  signed __int64 v19; // rbp
  __m128 v20; // xmm2
  float v21; // xmm6_4
  float v22; // xmm0_4
  float v23; // xmm13_4
  float v24; // xmm9_4
  UFG::RingBuffer<UFG::Crumb> *v25; // rbx
  signed int v26; // er12
  float v27; // xmm6_4
  signed int v28; // er15
  float *v29; // rax
  signed int v30; // edi
  float v31; // xmm9_4
  float v32; // xmm10_4
  float v33; // xmm8_4
  int v34; // eax
  signed int v35; // ecx
  __int64 v36; // rcx
  int v37; // eax
  signed int v38; // ecx
  int v39; // eax
  __m128 v40; // xmm2
  int v41; // eax
  signed int v42; // ecx
  int v43; // eax
  signed int v44; // ecx
  __int64 v45; // r12
  int v46; // eax
  float *v47; // r12
  signed int v48; // edi
  signed __int64 v49; // rcx
  UFG::qVector3 *v50; // rax
  int v51; // eax
  signed int v52; // ecx
  __m128 v53; // xmm2
  float v54; // xmm8_4
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm0_4
  float v58; // xmm0_4
  int v59; // eax
  UFG::Crumb *v60; // rax
  UFG::qVector3 *v61; // r9
  float v62; // xmm1_4
  __m128 v63; // xmm5
  float v64; // xmm0_4
  UFG::qVector3 *ray; // rax
  float v66; // xmm0_4
  float v67; // xmm1_4
  float v68; // xmm0_4
  float v69; // xmm0_4
  UFG::qVector3 *v70; // rax
  UFG::qVector3 point; // [rsp+30h] [rbp-C8h]
  UFG::qVector3 v72; // [rsp+40h] [rbp-B8h]
  float *v73; // [rsp+100h] [rbp+8h]
  signed __int64 v74; // [rsp+100h] [rbp+8h]

  v3 = this->m_pSimObject;
  v4 = 0;
  v5 = result;
  v6 = this;
  v7 = steer_to_distance;
  if ( v3 )
    v8 = v3->m_pTransformNodeComponent;
  else
    v8 = 0i64;
  v9 = (UFG::SimObjectGame *)this->m_pChaseTarget.m_pPointer;
  v10 = 0i64;
  if ( v9 )
  {
    v11 = v9->m_Flags;
    v10 = v9->m_pTransformNodeComponent;
    if ( (v11 >> 14) & 1 )
    {
      v12 = v9->m_Components.p[24].m_pComponent;
    }
    else if ( (v11 & 0x8000u) == 0 )
    {
      if ( (v11 >> 13) & 1 )
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::RoadSpaceComponent::_TypeUID);
      }
      else if ( (v11 >> 12) & 1 )
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::RoadSpaceComponent::_TypeUID);
      }
      else
      {
        v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::RoadSpaceComponent::_TypeUID);
      }
      v12 = v13;
    }
    else
    {
      v12 = v9->m_Components.p[24].m_pComponent;
    }
  }
  else
  {
    v12 = 0i64;
  }
  v14 = &UFG::qVector3::msUnity;
  if ( v12 )
    v14 = (UFG::qVector3 *)&v12[27].m_pSimObject;
  if ( v10 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v10);
    v15 = (UFG::qVector3 *)&v10->mWorldTransform.v3;
  }
  else
  {
    v15 = &UFG::qVector3::msZero;
  }
  v17 = (__m128)LODWORD(v15->y);
  v18 = v15->z;
  point.x = v15->x;
  v16 = point.x;
  LODWORD(point.y) = v17.m128_i32[0];
  point.z = v18;
  UFG::TransformNodeComponent::UpdateWorldTransform(v8);
  v19 = (signed __int64)&v8->mWorldTransform.v3;
  v20 = (__m128)*(unsigned int *)(v19 + 4);
  v20.m128_f32[0] = (float)((float)((float)(v20.m128_f32[0] - v17.m128_f32[0])
                                  * (float)(v20.m128_f32[0] - v17.m128_f32[0]))
                          + (float)((float)(*(float *)v19 - v16) * (float)(*(float *)v19 - v16)))
                  + (float)((float)(*(float *)(v19 + 8) - v18) * (float)(*(float *)(v19 + 8) - v18));
  LODWORD(v21) = (unsigned __int128)_mm_sqrt_ps(v20);
  if ( v7 <= v21 )
    v22 = v21;
  else
    v22 = v7;
  v23 = *(float *)&FLOAT_1_0;
  v6->m_fChaseDistance = v22;
  v6->m_fTrailDistance = v21;
  if ( v21 >= 1.0 )
    v24 = v21;
  else
    v24 = *(float *)&FLOAT_1_0;
  v6->m_fChaseCurvature = UFG::qSignedAngleBetween((UFG::qVector3 *)&v6->m_ChaseWorld, v14) / v24;
  if ( v12 && v10 )
  {
    v25 = (UFG::RingBuffer<UFG::Crumb> *)&v12[29].m_BoundComponentHandles.mNode.mNext;
    v26 = v25->mCount;
    if ( v26 > 2 )
      v6->m_fChaseCurvature = v25->mData[v25->mLast].fCurvature;
    if ( v26 && v21 > v7 )
    {
      v27 = 0.0;
      v28 = 0;
      v29 = &v25->mData[v25->mLast].vPosition.x;
      v30 = 0;
      v31 = 0.0;
      v17.m128_f32[0] = (float)((float)((float)(v17.m128_f32[0] - v29[1]) * (float)(v17.m128_f32[0] - v29[1]))
                              + (float)((float)(v16 - *v29) * (float)(v16 - *v29)))
                      + (float)((float)(v18 - v29[2]) * (float)(v18 - v29[2]));
      LODWORD(v32) = (unsigned __int128)_mm_sqrt_ps(v17);
      v33 = 0.0;
      if ( v26 <= 0 )
      {
LABEL_47:
        v41 = v25->mCount;
        v42 = 0;
        if ( v28 > 0 )
          v42 = v28;
        if ( v42 < v41 )
          v41 = v42;
        v43 = UFG::qSignedMod(v25->mLast - v41, v25->mCapacity);
        v44 = 0;
        v45 = v43;
        v46 = v25->mCount;
        v47 = &v25->mData[v45].vPosition.x;
        if ( v28 > 0 )
          v44 = v28;
        if ( v44 < v46 )
          v46 = v44;
        v48 = 1;
        v49 = (signed int)UFG::qSignedMod(v25->mLast - v46, v25->mCapacity);
        v50 = &v25->mData[v49].vDirection;
        v74 = (signed __int64)&v25->mData[v49].vDirection;
        if ( v28 > 1 )
        {
          do
          {
            v51 = v25->mCount;
            v52 = 0;
            if ( v48 > 0 )
              v52 = v48;
            if ( v52 < v51 )
              v51 = v52;
            ++v48;
            v27 = v27 + v25->mData[(signed int)UFG::qSignedMod(v25->mLast - v51, v25->mCapacity)].fLength;
          }
          while ( v48 < v28 );
          v50 = (UFG::qVector3 *)v74;
        }
        v53 = (__m128)*(unsigned int *)(v19 + 4);
        v53.m128_f32[0] = (float)((float)((float)(v53.m128_f32[0] - v47[1]) * (float)(v53.m128_f32[0] - v47[1]))
                                + (float)((float)(*(float *)v19 - *v47) * (float)(*(float *)v19 - *v47)))
                        + (float)((float)(*(float *)(v19 + 8) - v47[2]) * (float)(*(float *)(v19 + 8) - v47[2]));
        LODWORD(v54) = (unsigned __int128)_mm_sqrt_ps(v53);
        v55 = UFG::qAngleBetween((UFG::qVector3 *)&v6->m_ChaseWorld, v50);
        v56 = FLOAT_1_5707964;
        if ( v55 <= 1.5707964 )
          v56 = v55;
        if ( v7 <= v54 )
          v57 = v54;
        else
          v57 = v7;
        v69 = v57 * 2.0;
        if ( v69 >= 1.0 )
          v23 = v69;
        ray = (UFG::qVector3 *)v74;
        v6->m_fTrailDistance = v54;
        v61 = (UFG::qVector3 *)v47;
        v6->m_fChaseDistance = (float)(v27 + v32) + v54;
        v6->m_fChaseCurvature = v56 / v23;
      }
      else
      {
        while ( 1 )
        {
          v34 = v25->mCount;
          v35 = 0;
          if ( v30 > 0 )
            v35 = v30;
          if ( v35 < v34 )
            v34 = v35;
          v36 = (signed int)UFG::qSignedMod(v25->mLast - v34, v25->mCapacity);
          v37 = v25->mCount;
          v33 = v33 + v25->mData[v36].fLength;
          v38 = 0;
          if ( v30 > 0 )
            v38 = v30;
          if ( v38 < v37 )
            v37 = v38;
          v39 = UFG::qSignedMod(v25->mLast - v37, v25->mCapacity);
          v40 = (__m128)*(unsigned int *)(v19 + 4);
          v73 = &v25->mData[v39].vPosition.x;
          v40.m128_f32[0] = (float)((float)((float)(v40.m128_f32[0] - v73[1]) * (float)(v40.m128_f32[0] - v73[1]))
                                  + (float)((float)(*(float *)v19 - *v73) * (float)(*(float *)v19 - *v73)))
                          + (float)((float)(*(float *)(v19 + 8) - v73[2]) * (float)(*(float *)(v19 + 8) - v73[2]));
          if ( !v30 || v40.m128_f32[0] < v31 )
          {
            v31 = v40.m128_f32[0];
            v28 = v30;
          }
          if ( v40.m128_f32[0] < (float)(v7 * v7) )
            break;
          if ( ++v30 >= v26 )
            goto LABEL_47;
        }
        LODWORD(v58) = (unsigned __int128)_mm_sqrt_ps(v40);
        if ( v30 > 0 )
          v4 = v30;
        v6->m_fTrailDistance = v58;
        v59 = v25->mCount;
        if ( v4 < v59 )
          v59 = v4;
        v6->m_fChaseCurvature = v25->mData[(signed int)UFG::qSignedMod(v25->mLast - v59, v25->mCapacity)].fCurvature;
        if ( v30 )
          v60 = UFG::RingBuffer<UFG::Crumb>::NthNewest(v25, v30 - 1);
        else
          v60 = (UFG::Crumb *)&point;
        v61 = (UFG::qVector3 *)v73;
        v62 = v60->vPosition.y - v73[1];
        v63 = (__m128)*(unsigned int *)(v19 + 4);
        v63.m128_f32[0] = v63.m128_f32[0] - v73[1];
        v72.x = v60->vPosition.x - *v73;
        v64 = v60->vPosition.z;
        ray = &v72;
        v66 = v64 - v73[2];
        v72.y = v62;
        v67 = *(float *)v19 - *v73;
        v72.z = v66;
        v68 = *(float *)(v19 + 8) - v73[2];
        v63.m128_f32[0] = (float)((float)(v63.m128_f32[0] * v63.m128_f32[0]) + (float)(v67 * v67)) + (float)(v68 * v68);
        v6->m_fChaseDistance = COERCE_FLOAT(_mm_sqrt_ps(v63)) + (float)(v33 + v32);
      }
      UFG::RoadSpaceComponent::SteerTo(v5, (UFG::qVector3 *)v19, v7, v61, ray);
      v70 = v5;
    }
    else
    {
      UFG::RoadSpaceComponent::SteerTo(v5, (UFG::qVector3 *)v19, v7, &point, v14);
      v70 = v5;
    }
  }
  else
  {
    UFG::RoadSpaceComponent::SteerTo(v5, (UFG::qVector3 *)v19, v7, &point, v14);
    v70 = v5;
  }
  return v70;
}

// File Line: 1560
// RVA: 0x649040
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::ClampToRoad(UFG::RoadSpaceComponent *this, UFG::qVector3 *result, UFG::qVector3 *initialPos, UFG::qVector3 *targetPos)
{
  UFG::qVector3 *v4; // r14
  unsigned int v5; // er8
  UFG::qVector3 *v6; // rsi
  UFG::WheeledVehicleNavigationData *v7; // rdx
  UFG::qVector3 *v8; // r13
  UFG::RoadNetworkResource *v10; // rcx
  UFG::RoadNetworkNode *v11; // rbx
  UFG::RoadNetworkIntersection *v12; // rax
  UFG::RoadNetworkNode *v13; // rcx
  unsigned int v14; // er12
  unsigned int v15; // edx
  unsigned int v16; // eax
  UFG::RoadNetworkGate *v17; // rax
  UFG::RoadNetworkConnection *v18; // rax
  UFG::RoadNetworkConnection *v19; // r12
  unsigned int v20; // er15
  unsigned int v21; // ebx
  UFG::RoadNetworkLane *v22; // rdi
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
  unsigned int v35; // edi
  UFG::RoadNetworkLane *v36; // rbx
  bool v37; // r15
  UFG::qVector3 *v38; // rax
  float v39; // xmm1_4
  float v40; // xmm6_4
  float v41; // xmm0_4
  float v42; // er13
  float v43; // xmm6_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // eax
  float v47; // xmm6_4
  UFG::qVector3 *v48; // r14
  UFG::RoadNetworkLane *v49; // rbx
  bool v50; // di
  UFG::qVector3 *v51; // rax
  float v52; // xmm2_4
  unsigned int v53; // edi
  UFG::RoadNetworkLane *v54; // rax
  UFG::qVector3 *v55; // rax
  float v56; // ST48_4
  float v57; // ST4C_4
  float v58; // ST50_4
  UFG::RoadNetworkLane *v59; // rax
  UFG::qVector3 *v60; // rax
  float v61; // xmm10_4
  float v62; // xmm11_4
  float v63; // xmm12_4
  __m128 v64; // xmm4
  float v65; // xmm5_4
  float v66; // xmm3_4
  float v67; // xmm6_4
  UFG::RoadNetworkLane *v68; // rdi
  float v69; // xmm8_4
  __m128 v70; // xmm9
  float v71; // xmm7_4
  __m128 v72; // xmm3
  float v73; // xmm8_4
  float v74; // xmm9_4
  float v75; // xmm7_4
  float v76; // xmm3_4
  float v77; // xmm5_4
  __m128 v78; // xmm2
  float v79; // xmm6_4
  float v80; // xmm0_4
  float v81; // xmm6_4
  float v82; // xmm3_4
  float v83; // xmm4_4
  float v84; // xmm5_4
  float v85; // xmm1_4
  float v86; // xmm2_4
  float v87; // xmm1_4
  unsigned int v88; // [rsp+30h] [rbp-D0h]
  int v89; // [rsp+30h] [rbp-D0h]
  unsigned int v90; // [rsp+34h] [rbp-CCh]
  UFG::RoadNetworkNode *v91; // [rsp+38h] [rbp-C8h]
  UFG::RoadNetworkLane *v92; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 v93; // [rsp+58h] [rbp-A8h]
  UFG::qVector3 resulta; // [rsp+68h] [rbp-98h]
  float laneT; // [rsp+140h] [rbp+40h]
  UFG::qVector3 *v96; // [rsp+148h] [rbp+48h]
  UFG::qVector3 *v97; // [rsp+150h] [rbp+50h]
  UFG::qVector3 *pos; // [rsp+158h] [rbp+58h]

  pos = targetPos;
  v97 = initialPos;
  v96 = result;
  v4 = initialPos;
  v5 = this->mWayClient.m_RoadNetworkType;
  v6 = result;
  v7 = UFG::WheeledVehicleManager::m_Instance->m_NavigationData;
  v8 = targetPos;
  if ( v5 )
  {
    switch ( v5 )
    {
      case 1u:
        v7 = (UFG::WheeledVehicleNavigationData *)((char *)v7 + 64);
        break;
      case 2u:
        v7 = (UFG::WheeledVehicleNavigationData *)((char *)v7 + 96);
        break;
      case 3u:
        v7 = (UFG::WheeledVehicleNavigationData *)((char *)v7 + 128);
        break;
    }
  }
  else
  {
    v7 = (UFG::WheeledVehicleNavigationData *)((char *)v7 + 32);
  }
  if ( !v7 || (v10 = v7->m_RoadNetworkGraph.pRoadNetworkResource) == 0i64 )
  {
    v6->x = v4->x;
    v6->y = v4->y;
    v6->z = v4->z;
    return v6;
  }
  v11 = 0i64;
  v12 = UFG::RoadNetworkResource::GetClosestNode(v10, v4, v5, 0i64, 0i64);
  v13 = (UFG::RoadNetworkNode *)&v12->mType;
  v91 = (UFG::RoadNetworkNode *)&v12->mType;
  if ( v12 )
  {
    v14 = (unsigned __int8)v12->mNumLanes;
    if ( v12->mNumLanes )
    {
      v15 = (unsigned __int8)v12->mNumGates;
      v90 = v15;
      if ( v15 >= 2 )
      {
        if ( v15 <= 2 )
        {
          v34 = 0;
          if ( v14 <= 1 )
            goto LABEL_65;
          v35 = v14 - 1;
          v89 = v14 - 1;
          v36 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v12->mType, 0);
          v37 = UFG::RoadNetworkLane::IsReversedInNode(v36);
          v38 = UFG::RoadNetworkLane::GetNearestPoint(v36, &resulta, v8, 0i64);
          v11 = 0i64;
          laneT = 0.0;
          v39 = v8->x;
          v40 = v8->y;
          v41 = v8->z;
          LODWORD(v42) = 1;
          v43 = v40 - v38->y;
          v44 = v39 - v38->x;
          v45 = v41 - v38->z;
          v46 = 0.0;
          v47 = (float)((float)(v43 * v43) + (float)(v44 * v44)) + (float)(v45 * v45);
          if ( v14 > 1 )
          {
            v48 = pos;
            do
            {
              v49 = UFG::RoadNetworkNode::GetLane(v91, LODWORD(v42));
              v50 = UFG::RoadNetworkLane::IsReversedInNode(v49);
              v51 = UFG::RoadNetworkLane::GetNearestPoint(v49, &resulta, v48, 0i64);
              v52 = (float)((float)((float)(v48->y - v51->y) * (float)(v48->y - v51->y))
                          + (float)((float)(v48->x - v51->x) * (float)(v48->x - v51->x)))
                  + (float)((float)(v48->z - v51->z) * (float)(v48->z - v51->z));
              if ( v52 >= v47 )
              {
                v46 = laneT;
              }
              else
              {
                v46 = v42;
                v47 = v52;
                laneT = v42;
              }
              if ( v50 != v37 )
              {
                v89 = LODWORD(v42);
                v37 = v50;
              }
              ++LODWORD(v42);
            }
            while ( LODWORD(v42) < v14 );
            v6 = v96;
            v4 = v97;
            v35 = v89;
            v11 = 0i64;
          }
          if ( LODWORD(v46) >= v35 )
          {
            v34 = v35;
            v53 = v14 - 1;
          }
          else
          {
            v34 = 0;
            v53 = v35 - 1;
          }
          v13 = v91;
          if ( v34 == v53 )
          {
LABEL_65:
            v67 = 0.0;
            laneT = 0.0;
            v68 = UFG::RoadNetworkNode::GetLane(v13, v34);
            UFG::RoadNetworkLane::GetNearestPoint(v68, &v93, v4, &laneT);
            if ( v68->mNode.mOffset )
              v11 = (UFG::RoadNetworkNode *)((char *)v68 + v68->mNode.mOffset);
            UFG::RoadNetworkNode::GetTangent(v11, &resulta, v68->mLaneIndex, laneT);
            v70 = (__m128)LODWORD(resulta.x);
            v69 = (float)(resulta.z * UFG::qVector3::msDirUp.y) - (float)(resulta.y * UFG::qVector3::msDirUp.z);
            v70.m128_f32[0] = (float)(resulta.x * UFG::qVector3::msDirUp.z)
                            - (float)(resulta.z * UFG::qVector3::msDirUp.x);
            v71 = (float)(resulta.y * UFG::qVector3::msDirUp.x) - (float)(resulta.x * UFG::qVector3::msDirUp.y);
            v72 = v70;
            v72.m128_f32[0] = (float)((float)(v70.m128_f32[0] * v70.m128_f32[0]) + (float)(v69 * v69))
                            + (float)(v71 * v71);
            if ( v72.m128_f32[0] != 0.0 )
              v67 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v72));
            v64 = (__m128)LODWORD(v93.y);
            v73 = v69 * v67;
            v74 = v70.m128_f32[0] * v67;
            v75 = v71 * v67;
            v63 = v93.x + v73;
            v62 = v93.y + v74;
            v61 = v93.z + v75;
            v66 = v93.x - v73;
            v64.m128_f32[0] = v93.y - v74;
            v65 = v93.z - v75;
          }
          else
          {
            v54 = UFG::RoadNetworkNode::GetLane(v91, v34);
            v55 = UFG::RoadNetworkLane::GetNearestPoint(v54, &resulta, v4, 0i64);
            v56 = v55->x;
            v57 = v55->y;
            v58 = v55->z;
            v59 = UFG::RoadNetworkNode::GetLane(v91, v53);
            v60 = UFG::RoadNetworkLane::GetNearestPoint(v59, &resulta, v4, 0i64);
            v61 = v58;
            v62 = v57;
            v63 = v56;
            v64 = (__m128)LODWORD(v60->y);
            v65 = v60->z;
            v66 = v60->x;
          }
          v76 = v66 - v63;
          v64.m128_f32[0] = v64.m128_f32[0] - v62;
          v77 = v65 - v61;
          v78 = v64;
          v78.m128_f32[0] = (float)((float)(v64.m128_f32[0] * v64.m128_f32[0]) + (float)(v76 * v76))
                          + (float)(v77 * v77);
          LODWORD(v79) = (unsigned __int128)_mm_sqrt_ps(v78);
          v80 = 1.0 / v79;
          v81 = v79 + 1.0;
          v82 = v76 * v80;
          v83 = v64.m128_f32[0] * v80;
          v84 = v77 * v80;
          v85 = FLOAT_N1_0;
          v86 = (float)((float)((float)(v4->y - v62) * v83) + (float)((float)(v4->x - v63) * v82))
              + (float)((float)(v4->z - v61) * v84);
          if ( v86 > -1.0 )
            v85 = (float)((float)((float)(v4->y - v62) * v83) + (float)((float)(v4->x - v63) * v82))
                + (float)((float)(v4->z - v61) * v84);
          if ( v85 >= v81 )
            v85 = v81;
          v87 = v85 - v86;
          v33 = (float)(v82 * v87) + v4->x;
          v32 = (float)(v83 * v87) + v4->y;
          v6->z = (float)(v84 * v87) + v4->z;
        }
        else
        {
          v16 = 0;
          v88 = 0;
          if ( !v15 )
          {
LABEL_35:
            v6->x = v4->x;
            v6->y = v4->y;
            v6->z = v4->z;
            return v6;
          }
          while ( 1 )
          {
            v17 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v13, v16);
            if ( v17->mNumIncomingConnections )
            {
              v18 = UFG::RoadNetworkGate::GetIncomingConnection(v17, 0);
              v19 = v18;
              v20 = v18->mNumLanes;
              if ( v18->mNumLanes )
              {
                v21 = 1;
                v22 = UFG::qBezierPathCollectionMemImaged::GetPath(v18, 0);
                v92 = v22;
                if ( v20 > 1 )
                {
                  while ( 1 )
                  {
                    v22 = UFG::qBezierPathCollectionMemImaged::GetPath(v19, v21);
                    if ( (unsigned int)UFG::RoadNetworkLane::GetTurnDirection(v22) == 1 )
                      break;
                    if ( ++v21 >= v20 )
                    {
                      v22 = v92;
                      break;
                    }
                  }
                }
                laneT = 0.0;
                UFG::RoadNetworkLane::GetNearestPoint(v22, &resulta, v4, &laneT);
                v23 = (UFG::RoadNetworkNode *)(v22->mNode.mOffset ? (UFG::RoadNetworkLane *)((char *)v22
                                                                                           + v22->mNode.mOffset) : 0i64);
                UFG::RoadNetworkNode::GetTangent(v23, &v93, v22->mLaneIndex, laneT);
                v25 = (__m128)LODWORD(v93.x);
                v24 = (float)(v93.z * UFG::qVector3::msDirUp.y) - (float)(v93.y * UFG::qVector3::msDirUp.z);
                v25.m128_f32[0] = (float)(v93.x * UFG::qVector3::msDirUp.z) - (float)(v93.z * UFG::qVector3::msDirUp.x);
                v26 = (float)(v93.y * UFG::qVector3::msDirUp.x) - (float)(v93.x * UFG::qVector3::msDirUp.y);
                v27 = v25;
                v27.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v24 * v24))
                                + (float)(v26 * v26);
                v28 = v27.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v27));
                v29 = v25.m128_f32[0] * v28;
                v30 = v26 * v28;
                v31 = v24 * v28;
                v32 = v29 + resulta.y;
                v33 = v31 + resulta.x;
                if ( (float)((float)((float)((float)(v4->y - (float)(v29 + resulta.y)) * v29)
                                   + (float)((float)(v4->x - (float)(v31 + resulta.x)) * v31))
                           + (float)((float)(v4->z - (float)(v30 + resulta.z)) * v30)) > 0.0 )
                  break;
              }
            }
            v16 = v88 + 1;
            v88 = v16;
            if ( v16 >= v90 )
              goto LABEL_35;
            v13 = v91;
          }
          v6->z = v30 + resulta.z;
        }
        v6->y = v32;
        v6->x = v33;
        return v6;
      }
    }
    v6->x = v4->x;
    v6->y = v4->y;
    v6->z = v4->z;
  }
  else
  {
    v6->x = v4->x;
    v6->y = v4->y;
    v6->z = v4->z;
  }
  return v6;
}

// File Line: 1709
// RVA: 0x64D630
void __fastcall UFG::RoadSpaceComponent::FlushRaceTrails(UFG::RoadSpaceComponent *this)
{
  UFG::RoadSpaceComponent *v1; // rbx
  UFG::RacePosition *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::RacePosition *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v11; // rax

  v1 = this;
  v2 = this->m_pRacePositionSteer;
  if ( v2 )
  {
    if ( v2->pRaceTrail.m_pPointer )
    {
      v3 = v2->pRaceTrail.mPrev;
      v4 = v2->pRaceTrail.mNext;
      v3->mNext = v4;
      v4->mPrev = v3;
      v2->pRaceTrail.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v2->pRaceTrail.mPrev;
      v2->pRaceTrail.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v2->pRaceTrail.mPrev;
    }
    v2->pRaceTrail.m_pPointer = 0i64;
    v5 = v2->pRaceTrail.mPrev;
    v6 = v2->pRaceTrail.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->pRaceTrail.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v2->pRaceTrail.mPrev;
    v2->pRaceTrail.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v2->pRaceTrail.mPrev;
    operator delete[](v2);
    v1->m_pRacePositionSteer = 0i64;
  }
  v7 = v1->m_pRacePosition;
  if ( v7 )
  {
    if ( v7->pRaceTrail.m_pPointer )
    {
      v8 = v7->pRaceTrail.mPrev;
      v9 = v7->pRaceTrail.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->pRaceTrail.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v7->pRaceTrail.mPrev;
      v7->pRaceTrail.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v7->pRaceTrail.mPrev;
    }
    v7->pRaceTrail.m_pPointer = 0i64;
    v10 = v7->pRaceTrail.mPrev;
    v11 = v7->pRaceTrail.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v7->pRaceTrail.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v7->pRaceTrail.mPrev;
    v7->pRaceTrail.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v7->pRaceTrail.mPrev;
    operator delete[](v7);
    v1->m_pRacePosition = 0i64;
  }
}

// File Line: 1727
// RVA: 0x659740
void __fastcall UFG::RoadSpaceComponent::SetRaceTrail(UFG::RoadSpaceComponent *this, UFG::RaceTrail *race_trail)
{
  UFG::RaceTrail *v2; // rbp
  UFG::RoadSpaceComponent *v3; // rbx
  UFG::SimObject *v4; // rsi
  UFG::RacePosition *v5; // rdi
  UFG::TransformNodeComponent *v6; // rsi
  UFG::allocator::free_link *v7; // rax
  UFG::RacePosition *v8; // rax

  v2 = race_trail;
  v3 = this;
  UFG::RoadSpaceComponent::FlushRaceTrails(this);
  if ( v2 )
  {
    v4 = v3->m_pSimObject;
    v5 = 0i64;
    if ( v4 )
      v6 = v4->m_pTransformNodeComponent;
    else
      v6 = 0i64;
    v7 = UFG::qMalloc(0x48ui64, "RacePosition", 0i64);
    if ( v7 )
    {
      UFG::RacePosition::RacePosition((UFG::RacePosition *)v7, v2);
      v5 = v8;
    }
    v3->m_pRacePosition = v5;
    UFG::TransformNodeComponent::UpdateWorldTransform(v6);
    UFG::RacePosition::InitPosition(v3->m_pRacePosition, (UFG::qVector3 *)&v6->mWorldTransform.v3);
  }
}

// File Line: 1740
// RVA: 0x6597F0
void __fastcall UFG::RoadSpaceComponent::SetRaceTrailSteer(UFG::RoadSpaceComponent *this, UFG::RaceTrail *race_trail)
{
  UFG::RaceTrail *v2; // rbp
  UFG::RoadSpaceComponent *v3; // rbx
  UFG::RacePosition *v4; // rcx
  UFG::RacePosition *v5; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::SimObject *v10; // rsi
  UFG::TransformNodeComponent *v11; // rsi
  UFG::allocator::free_link *v12; // rax
  UFG::RacePosition *v13; // rax

  v2 = race_trail;
  v3 = this;
  v4 = this->m_pRacePositionSteer;
  v5 = 0i64;
  if ( v4 )
  {
    if ( v4->pRaceTrail.m_pPointer )
    {
      v6 = v4->pRaceTrail.mPrev;
      v7 = v4->pRaceTrail.mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v4->pRaceTrail.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v4->pRaceTrail.mPrev;
      v4->pRaceTrail.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v4->pRaceTrail.mPrev;
    }
    v4->pRaceTrail.m_pPointer = 0i64;
    v8 = v4->pRaceTrail.mPrev;
    v9 = v4->pRaceTrail.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v4->pRaceTrail.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v4->pRaceTrail.mPrev;
    v4->pRaceTrail.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v4->pRaceTrail.mPrev;
    operator delete[](v4);
    v3->m_pRacePositionSteer = 0i64;
  }
  v10 = v3->m_pSimObject;
  if ( v10 )
    v11 = v10->m_pTransformNodeComponent;
  else
    v11 = 0i64;
  v12 = UFG::qMalloc(0x48ui64, "RacePositionSteer", 0i64);
  if ( v12 )
  {
    UFG::RacePosition::RacePosition((UFG::RacePosition *)v12, v2);
    v5 = v13;
  }
  v3->m_pRacePositionSteer = v5;
  UFG::TransformNodeComponent::UpdateWorldTransform(v11);
  UFG::RacePosition::InitPosition(v3->m_pRacePositionSteer, (UFG::qVector3 *)&v11->mWorldTransform.v3);
}

// File Line: 1753
// RVA: 0x6497D0
bool __fastcall UFG::RoadSpaceComponent::CleanupOnRaceDeleted(UFG::RoadSpaceComponent *this)
{
  UFG::RoadSpaceComponent *v1; // rdi
  UFG::RacePosition *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::RacePosition *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v10; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *v11; // rdx

  v1 = this;
  v2 = this->m_pRacePositionSteer;
  if ( v2 && !v2->pRaceTrail.m_pPointer )
  {
    if ( v2->pRaceTrail.m_pPointer )
    {
      v3 = v2->pRaceTrail.mPrev;
      v4 = v2->pRaceTrail.mNext;
      v3->mNext = v4;
      v4->mPrev = v3;
      v2->pRaceTrail.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v2->pRaceTrail.mPrev;
      v2->pRaceTrail.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v2->pRaceTrail.mPrev;
    }
    v2->pRaceTrail.m_pPointer = 0i64;
    v5 = v2->pRaceTrail.mPrev;
    v6 = v2->pRaceTrail.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->pRaceTrail.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v2->pRaceTrail.mPrev;
    v2->pRaceTrail.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v2->pRaceTrail.mPrev;
    operator delete[](v2);
    v1->m_pRacePositionSteer = 0i64;
  }
  v7 = v1->m_pRacePosition;
  if ( v7 && !v7->pRaceTrail.m_pPointer )
  {
    if ( v7->pRaceTrail.m_pPointer )
    {
      v8 = v7->pRaceTrail.mPrev;
      v9 = v7->pRaceTrail.mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->pRaceTrail.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v7->pRaceTrail.mPrev;
      v7->pRaceTrail.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v7->pRaceTrail.mPrev;
    }
    v7->pRaceTrail.m_pPointer = 0i64;
    v10 = v7->pRaceTrail.mPrev;
    v11 = v7->pRaceTrail.mNext;
    v10->mNext = v11;
    v11->mPrev = v10;
    v7->pRaceTrail.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v7->pRaceTrail.mPrev;
    v7->pRaceTrail.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::RaceTrail>,UFG::qSafePointerNodeList> *)&v7->pRaceTrail.mPrev;
    operator delete[](v7);
    v1->m_pRacePosition = 0i64;
  }
  return v1->m_pRacePosition == 0i64;
}

// File Line: 1771
// RVA: 0x650B40
UFG::qVector3 *__fastcall UFG::RoadSpaceComponent::GetSteerToRace(UFG::RoadSpaceComponent *this, UFG::qVector3 *result, float steer_to_distance, float *speed_limit, float vehicle_mass, bool is_boat)
{
  int v6; // edi
  float *v7; // rbp
  UFG::qVector3 *v8; // r12
  UFG::RoadSpaceComponent *v9; // r13
  UFG::TransformNodeComponent *v10; // rbx
  float v11; // xmm7_4
  UFG::SimObject *v12; // rax
  UFG::RacePosition *v13; // rax
  UFG::RacePoint *v14; // rsi
  signed __int64 v15; // r14
  UFG::RaceTrail *v16; // r10
  __m128 v17; // xmm2
  float v18; // xmm8_4
  __m128 v19; // xmm9
  float v20; // xmm10_4
  float v21; // xmm11_4
  float v22; // xmm0_4
  int v23; // xmm1_4
  int v24; // er9
  bool v25; // r8
  signed __int64 v26; // rax
  signed __int64 v27; // rsi
  int v28; // edx
  int v29; // esi
  unsigned __int64 v30; // rdx
  unsigned __int64 v31; // r15
  __m128 v32; // xmm2
  float v33; // xmm6_4
  UFG::RacePoint *v34; // rbx
  float v35; // xmm8_4
  float v36; // xmm0_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm0_4
  float v44; // xmm1_4
  UFG::qVector3 *ray; // rax
  UFG::qVector3 *v46; // rax
  float v47; // xmm1_4
  float v48; // xmm12_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm0_4
  float v52; // xmm8_4
  float v53; // xmm10_4
  __m128 v54; // xmm2
  float v55; // xmm7_4
  float v56; // xmm0_4
  float v57; // xmm1_4
  UFG::RaceTrail *v58; // [rsp+30h] [rbp-C8h]
  UFG::qVector3 *v59; // [rsp+38h] [rbp-C0h]
  UFG::qVector3 resulta; // [rsp+40h] [rbp-B8h]
  float v61; // [rsp+50h] [rbp-A8h]
  float v62; // [rsp+54h] [rbp-A4h]
  float v63; // [rsp+58h] [rbp-A0h]
  int v64; // [rsp+100h] [rbp+8h]

  v6 = 0;
  v7 = speed_limit;
  v8 = result;
  v9 = this;
  v10 = 0i64;
  v11 = steer_to_distance;
  v12 = this->m_pSimObject;
  if ( v12 )
    v10 = v12->m_pTransformNodeComponent;
  v13 = this->m_pRacePositionSteer;
  if ( !v13 )
    v13 = this->m_pRacePosition;
  v14 = v13->pRacePoint;
  v58 = v13->pRaceTrail.m_pPointer;
  UFG::TransformNodeComponent::UpdateWorldTransform(v10);
  v15 = (signed __int64)&v10->mWorldTransform.v3;
  UFG::RacePoint::GetSegmentPosition(v14, &resulta, (UFG::qVector3 *)&v10->mWorldTransform.v3);
  v16 = v58;
  v17 = (__m128)LODWORD(v10->mWorldTransform.v3.y);
  v18 = resulta.x;
  v19 = (__m128)LODWORD(resulta.y);
  v20 = resulta.z;
  v17.m128_f32[0] = (float)((float)((float)(v17.m128_f32[0] - resulta.y) * (float)(v17.m128_f32[0] - resulta.y))
                          + (float)((float)(*(float *)v15 - resulta.x) * (float)(*(float *)v15 - resulta.x)))
                  + (float)((float)(v10->mWorldTransform.v3.z - resulta.z)
                          * (float)(v10->mWorldTransform.v3.z - resulta.z));
  LODWORD(v21) = (unsigned __int128)_mm_sqrt_ps(v17);
  if ( v58 && v11 > v21 )
  {
    v22 = v14->vDirection.x;
    v23 = LODWORD(v14->vDirection.y);
    v24 = v58->nRacePoints;
    v25 = v58->bIsLoop;
    v26 = (signed __int64)&v14->vDirection;
    v27 = (char *)v14 - (char *)v58->pRacePoints;
    v61 = v22;
    v62 = *(float *)&v23;
    v59 = (UFG::qVector3 *)v26;
    v63 = *(float *)(v26 + 8);
    v64 = v24;
    v28 = ((unsigned __int64)((unsigned __int128)(v27 * (signed __int128)5270498306774157605i64) >> 64) >> 63)
        + ((signed __int64)((unsigned __int128)(v27 * (signed __int128)5270498306774157605i64) >> 64) >> 4)
        + 1;
    if ( v28 >= v24 )
    {
      v28 = 0;
      if ( !v25 )
        v28 = v24 - 1;
    }
    v29 = v24;
    v30 = (unsigned __int128)(56i64 * v28 * (signed __int128)5270498306774157605i64) >> 64;
    v31 = (v30 >> 63) + ((signed __int64)v30 >> 4);
    if ( !v25 )
      v29 = v24 - v31;
    if ( v29 <= 0 )
    {
LABEL_22:
      ray = v59;
    }
    else
    {
      while ( 1 )
      {
        v32 = (__m128)*(unsigned int *)(v15 + 4);
        v33 = FLOAT_100_0;
        v34 = &v16->pRacePoints[(v6 + (signed int)v31) % v24];
        v32.m128_f32[0] = (float)((float)((float)(v32.m128_f32[0] - v34->vPosition.y)
                                        * (float)(v32.m128_f32[0] - v34->vPosition.y))
                                + (float)((float)(*(float *)v15 - v34->vPosition.x)
                                        * (float)(*(float *)v15 - v34->vPosition.x)))
                        + (float)((float)(*(float *)(v15 + 8) - v34->vPosition.z)
                                * (float)(*(float *)(v15 + 8) - v34->vPosition.z));
        LODWORD(v35) = (unsigned __int128)_mm_sqrt_ps(v32);
        if ( (*(_DWORD *)&v9->mBits >> 3) & 1 )
          v33 = UFG::GetSpeedLimitForCurvature(v34->fCurvature, 100.0, 1.0);
        v36 = v34->fSpeed;
        if ( v36 >= 0.0 && v33 >= v36 )
          v33 = v34->fSpeed;
        v37 = UFG::GetBrakingSpeedLimit(v35, 100.0, vehicle_mass, is_boat);
        v38 = *v7;
        v39 = v37 + v33;
        if ( *v7 >= v39 )
          v38 = v39;
        *v7 = v38;
        if ( v11 <= v35 )
          break;
        v40 = v34->vDirection.y;
        v24 = v64;
        v16 = v58;
        ++v6;
        v61 = v34->vDirection.x;
        v41 = v34->vDirection.z;
        v62 = v40;
        v42 = v34->vPosition.x;
        v63 = v41;
        v43 = v34->vPosition.y;
        resulta.x = v42;
        v44 = v34->vPosition.z;
        resulta.y = v43;
        resulta.z = v44;
        if ( v6 >= v29 )
          goto LABEL_22;
      }
      ray = (UFG::qVector3 *)&v61;
    }
    UFG::RoadSpaceComponent::SteerTo(v8, (UFG::qVector3 *)v15, v11, &resulta, ray);
    v46 = v8;
  }
  else
  {
    if ( v11 >= 1.0 )
      v47 = v11;
    else
      v47 = *(float *)&FLOAT_1_0;
    v48 = UFG::GetSpeedLimitForCurvature(1.5707964 / v47, 100.0, 1.0);
    if ( (*(_DWORD *)&v9->mBits >> 3) & 1 )
    {
      v49 = UFG::GetBrakingSpeedLimit(v21, 100.0, vehicle_mass, is_boat);
      v50 = *v7;
      v51 = v49 + v48;
      if ( *v7 >= v51 )
        v50 = v51;
      *v7 = v50;
    }
    v52 = v18 - *(float *)v15;
    v19.m128_f32[0] = v19.m128_f32[0] - v10->mWorldTransform.v3.y;
    v53 = v20 - v10->mWorldTransform.v3.z;
    v46 = v8;
    v54 = v19;
    v54.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v52 * v52)) + (float)(v53 * v53);
    v55 = v11 / COERCE_FLOAT(_mm_sqrt_ps(v54));
    v56 = (float)(v55 * v19.m128_f32[0]) + v10->mWorldTransform.v3.y;
    v57 = (float)(v55 * v52) + *(float *)v15;
    v8->z = (float)(v55 * v53) + v10->mWorldTransform.v3.z;
    v8->x = v57;
    v8->y = v56;
  }
  return v46;
}

// File Line: 1831
// RVA: 0x64E760
float __fastcall UFG::RoadSpaceComponent::GetFractionRaceComplete(UFG::RoadSpaceComponent *this)
{
  UFG::RacePosition *v1; // rdx
  float result; // xmm0_4
  UFG::RaceTrail *v3; // rax
  float v4; // xmm1_4
  float v5; // xmm1_4

  v1 = this->m_pRacePosition;
  result = 0.0;
  if ( v1 )
  {
    v3 = v1->pRaceTrail.m_pPointer;
    if ( v3 )
    {
      if ( v3->bIsLoop )
        v4 = (float)v3->nLaps;
      else
        v4 = *(float *)&FLOAT_1_0;
      v5 = v4 * v3->fLength;
      if ( v5 > 0.0 )
        result = v1->fRaceDistance / v5;
    }
  }
  return result;
}

