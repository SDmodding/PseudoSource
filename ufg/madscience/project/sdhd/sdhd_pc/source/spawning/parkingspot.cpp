// File Line: 47
// RVA: 0x5B36D0
UFG::ComponentIDDesc *__fastcall UFG::VehicleSpot::GetDesc(UFG::VehicleSpot *this)
{
  return &UFG::VehicleSpot::_TypeIDesc;
}

// File Line: 55
// RVA: 0x5B1B70
void __fastcall UFG::VehicleSpot::VehicleSpot(UFG::VehicleSpot *this, UFG::qSymbol *name, UFG::SimObject *simobj)
{
  UFG::MarkerBase::MarkerBase(this, name, simobj, 0);
  this->mPrev = &this->UFG::qNode<UFG::VehicleSpot,UFG::VehicleSpot>;
  this->mNext = &this->UFG::qNode<UFG::VehicleSpot,UFG::VehicleSpot>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleSpot::`vftable;
  this->mNearOrOnIntersection = 0;
  this->mOccupier.mPrev = &this->mOccupier;
  this->mOccupier.mNext = &this->mOccupier;
  this->mOccupier.m_pPointer = 0i64;
  UFG::SimComponent::AddType(this, UFG::VehicleSpot::_VehicleSpotTypeUID, "VehicleSpot");
  UFG::VehicleSpot::Initialize(this, simobj);
}

// File Line: 61
// RVA: 0x5B20D0
void __fastcall UFG::VehicleSpot::~VehicleSpot(UFG::VehicleSpot *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *p_mOccupier; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::VehicleSpot,UFG::VehicleSpot> *v7; // rcx
  UFG::qNode<UFG::VehicleSpot,UFG::VehicleSpot> *v8; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleSpot::`vftable;
  p_mOccupier = &this->mOccupier;
  if ( this->mOccupier.m_pPointer )
  {
    mPrev = p_mOccupier->mPrev;
    mNext = p_mOccupier->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mOccupier->mPrev = p_mOccupier;
    p_mOccupier->mNext = p_mOccupier;
  }
  p_mOccupier->m_pPointer = 0i64;
  v5 = p_mOccupier->mPrev;
  v6 = p_mOccupier->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mOccupier->mPrev = p_mOccupier;
  p_mOccupier->mNext = p_mOccupier;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<UFG::VehicleSpot,UFG::VehicleSpot>;
  this->mNext = &this->UFG::qNode<UFG::VehicleSpot,UFG::VehicleSpot>;
  UFG::MarkerBase::~MarkerBase(this);
}

// File Line: 66
// RVA: 0x5B4D60
void __fastcall UFG::VehicleSpot::Initialize(UFG::VehicleSpot *this, UFG::SimObject *simobj)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *p_mOccupier; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  this->mCanSpawn = 1;
  this->mRoadSegmentID = -1;
  this->mRoadNetworkType = 0;
  this->mBoundingBoxMin.x = -2.5;
  this->mBoundingBoxMin.y = -1.0;
  this->mBoundingBoxMin.z = 0.0;
  p_mOccupier = &this->mOccupier;
  this->mBoundingBoxMax.x = 2.5;
  this->mBoundingBoxMax.y = 1.0;
  this->mBoundingBoxMax.z = 1.5;
  if ( this->mOccupier.m_pPointer )
  {
    mPrev = p_mOccupier->mPrev;
    mNext = p_mOccupier->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mOccupier->mPrev = p_mOccupier;
    p_mOccupier->mNext = p_mOccupier;
  }
  p_mOccupier->m_pPointer = 0i64;
}

// File Line: 107
// RVA: 0x5B5170
void __fastcall UFG::VehicleSpot::PropertiesLoad(UFG::VehicleSpot *this, UFG::SceneObjectProperties *pSceneObj)
{
  bool *v4; // rax
  unsigned __int16 *v5; // rax
  UFG::qPropertySet *v6; // rax
  unsigned int mFlags; // eax
  UFG::qPropertySet *v8; // rax
  float *v9; // rax
  float v10; // xmm0_4
  bool *v11; // rax

  v4 = PropertyUtils::Get<bool>(pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_CanSpawn);
  if ( v4 )
    this->mCanSpawn = *v4;
  v5 = (unsigned __int16 *)PropertyUtils::Get<unsigned long>(
                             pSceneObj,
                             (UFG::qArray<unsigned long,0> *)&qSymbol_RoadNetworkType);
  if ( v5 )
    this->mRoadNetworkType = *v5;
  v6 = PropertyUtils::Get<long>(pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_RoadNetworkNodeID);
  if ( v6 )
    mFlags = v6->mFlags;
  else
    mFlags = -1;
  this->mRoadSegmentID = mFlags;
  v8 = PropertyUtils::Get<long>(pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_RoadNetworkClosestLaneIndex);
  if ( v8 )
    LODWORD(v8) = v8->mFlags;
  this->mClosestLaneIndex = (unsigned __int16)v8;
  v9 = PropertyUtils::Get<float>(pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_RoadNetworkClosestT);
  if ( v9 )
    v10 = *v9;
  else
    v10 = 0.0;
  this->mClosestT = v10;
  v11 = PropertyUtils::Get<bool>(pSceneObj, (UFG::qArray<unsigned long,0> *)&qSymbol_RoadNetworkNearOrOnIntersection);
  if ( v11 )
    this->mNearOrOnIntersection = *v11;
  else
    this->mNearOrOnIntersection = 0;
}

// File Line: 206
// RVA: 0x5B36A0
UFG::ComponentIDDesc *__fastcall UFG::ParkingSpot::GetDesc(UFG::ParkingSpot *this)
{
  return &UFG::ParkingSpot::_TypeIDesc;
}

// File Line: 245
// RVA: 0x5B2A40
void __fastcall UFG::ParkingSpot::AddToCollection(UFG::ParkingSpot *this)
{
  UFG::RoadNetworkResource *RoadNetwork; // rax
  UFG::RoadNetworkSegment *Segment; // rax

  RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  if ( RoadNetwork )
  {
    Segment = UFG::RoadNetworkResource::GetSegment(RoadNetwork, this->mRoadSegmentID);
    if ( !this->mNearOrOnIntersection )
      UFG::RoadNetworkSegment::AddParkingSpot(Segment, this);
  }
}

// File Line: 313
// RVA: 0x5B4340
bool __fastcall UFG::ParkingSpot::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&qSymbolX_propset_componentParkingSpot);
}

// File Line: 323
// RVA: 0x5B5320
UFG::ParkingSpot *__fastcall UFG::ParkingSpot::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::VehicleSpot *v3; // rdi
  UFG::SimObject *m_pSimObject; // rbx
  UFG::qSymbol *v5; // rax
  UFG::qSymbol result; // [rsp+68h] [rbp+10h] BYREF
  UFG::VehicleSpot *v8; // [rsp+70h] [rbp+18h]

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = (UFG::VehicleSpot *)UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xD0ui64, "ParkingSpot", 0i64, 1u);
  v8 = v3;
  if ( v3 )
  {
    m_pSimObject = pSceneObj->m_pSimObject;
    v5 = (UFG::qSymbol *)UFG::SceneObjectProperties::operator UFG::qSymbol const(pSceneObj, (UFG::qWiseSymbol *)&result);
    UFG::VehicleSpot::VehicleSpot(v3, v5, m_pSimObject);
    v3[1].vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&v3[1];
    v3[1].m_SafePointerList.UFG::MarkerBase::UFG::HintComponentBase::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mNode.UFG::MarkerBase::UFG::HintComponentBase::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3[1];
    v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ParkingSpot::`vftable;
    UFG::SimComponent::AddType(v3, UFG::ParkingSpot::_ParkingSpotTypeUID, "ParkingSpot");
    v3->mRoadSegmentID = -1;
  }
  else
  {
    v3 = 0i64;
  }
  v3->vfptr[12].__vecDelDtor(v3, (unsigned int)pSceneObj);
  ((void (__fastcall *)(UFG::VehicleSpot *))v3->vfptr[19].__vecDelDtor)(v3);
  return (UFG::ParkingSpot *)v3;
}

// File Line: 331
// RVA: 0x5B5160
// attributes: thunk
void __fastcall UFG::ParkingSpot::PropertiesLoad(UFG::ParkingSpot *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::VehicleSpot::PropertiesLoad(this, pSceneObj);
}

// File Line: 339
// RVA: 0x5B6E50
UFG::SimObject *__fastcall UFG::ParkingSpot::Spawn(
        UFG::ParkingSpot *this,
        UFG::qSymbol *objName,
        UFG::qPropertySet *parentSet,
        __int32 priority)
{
  UFG::SceneObjectProperties *v7; // rax
  UFG::SceneObjectProperties *v8; // rbx
  UFG::qStaticSymbol *v9; // r8
  UFG::SimObject *v10; // rdi
  UFG::qSymbolUC *v11; // rax
  char *v12; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *p_mOccupier; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::RoadNetworkGuide *m_pComponent; // rcx
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+20h] BYREF

  v7 = UFG::SceneObjectProperties::Create(objName, 0i64, parentSet);
  v8 = v7;
  if ( priority != 5 )
  {
    switch ( priority )
    {
      case 1:
        v9 = &qSymbol_High;
        break;
      case 2:
        v9 = &qSymbol_Medium;
        break;
      case 3:
        v9 = &qSymbol_Low;
        break;
      default:
        v9 = &qSymbol_Critical;
        break;
    }
    PropertyUtils::SetRuntime<UFG::qSymbol>(v7, (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnPriority, v9);
  }
  v10 = UFG::SceneObjectProperties::Activate(v8, 3u, 0i64, 0i64);
  if ( v10 )
  {
    UFG::SpawnInfoInterface::ClearSpawnLocation(v8, (UFG::SpawnInfoInterface::SpawnPriority)priority);
    UFG::SpawnInfoInterface::ActivateObjectPost(v8, priority, 0i64, parentSet, 0);
  }
  else
  {
    if ( v8 )
    {
      v11 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol(&result, v8->m_NameUID);
      v12 = UFG::qSymbol::as_cstr_dbg(v11);
    }
    else
    {
      v12 = "<NULL>";
    }
    UFG::qPrintf("Spawn Object [%s] failed to spawn object [%s]\n", "<NULL>", v12);
  }
  p_mOccupier = &this->mOccupier;
  if ( this->mOccupier.m_pPointer )
  {
    mPrev = p_mOccupier->mPrev;
    mNext = this->mOccupier.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mOccupier->mPrev = p_mOccupier;
    this->mOccupier.mNext = &this->mOccupier;
  }
  this->mOccupier.m_pPointer = v10;
  if ( v10 )
  {
    v16 = v10->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v16->mNext = p_mOccupier;
    p_mOccupier->mPrev = v16;
    this->mOccupier.mNext = &v10->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v10->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mOccupier;
    m_pComponent = (UFG::RoadNetworkGuide *)v10->m_Components.p[30].m_pComponent;
  }
  else
  {
    m_pComponent = 0i64;
  }
  UFG::VehicleOccupantComponent::SetParkingSpot(m_pComponent, (UFG::RoadNetworkLane *)this);
  return v10;
}

// File Line: 366
// RVA: 0x155E4F0
__int64 UFG::_dynamic_initializer_for__gsymParkingSets__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default-roadnetwork-parking-parkingsets", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymParkingSets, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gsymParkingSets__);
}

// File Line: 369
// RVA: 0x5B2D00
bool __fastcall UFG::ParkingSpot::CanSpawn(UFG::ParkingSpot *this)
{
  return this->mCanSpawn && !this->mOccupier.m_pPointer;
}

