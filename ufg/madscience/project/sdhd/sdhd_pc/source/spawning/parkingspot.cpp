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
  UFG::SimObject *v3; // rbx
  UFG::VehicleSpot *v4; // rdi
  UFG::qNode<UFG::VehicleSpot,UFG::VehicleSpot> *v5; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v6; // [rsp+58h] [rbp+20h]

  v3 = simobj;
  v4 = this;
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)&this->vfptr, name, simobj, 0);
  v5 = (UFG::qNode<UFG::VehicleSpot,UFG::VehicleSpot> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleSpot::`vftable';
  v4->mNearOrOnIntersection = 0;
  v6 = &v4->mOccupier;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v4->mOccupier.m_pPointer = 0i64;
  UFG::SimComponent::AddType((UFG::SimComponent *)&v4->vfptr, UFG::VehicleSpot::_VehicleSpotTypeUID, "VehicleSpot");
  UFG::VehicleSpot::Initialize(v4, v3);
}

// File Line: 61
// RVA: 0x5B20D0
void __fastcall UFG::VehicleSpot::~VehicleSpot(UFG::VehicleSpot *this)
{
  UFG::VehicleSpot *v1; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::VehicleSpot,UFG::VehicleSpot> *v7; // rdx
  UFG::qNode<UFG::VehicleSpot,UFG::VehicleSpot> *v8; // rcx
  UFG::qNode<UFG::VehicleSpot,UFG::VehicleSpot> *v9; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleSpot::`vftable';
  v2 = &this->mOccupier;
  if ( this->mOccupier.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = (UFG::qNode<UFG::VehicleSpot,UFG::VehicleSpot> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
  UFG::MarkerBase::~MarkerBase((UFG::MarkerBase *)&v1->vfptr);
}

// File Line: 66
// RVA: 0x5B4D60
void __fastcall UFG::VehicleSpot::Initialize(UFG::VehicleSpot *this, UFG::SimObject *simobj)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax

  this->mCanSpawn = 1;
  this->mRoadSegmentID = -1;
  this->mRoadNetworkType = 0;
  this->mBoundingBoxMin.x = -2.5;
  this->mBoundingBoxMin.y = -1.0;
  this->mBoundingBoxMin.z = 0.0;
  v2 = &this->mOccupier;
  this->mBoundingBoxMax.x = 2.5;
  this->mBoundingBoxMax.y = 1.0;
  this->mBoundingBoxMax.z = 1.5;
  if ( this->mOccupier.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
}

// File Line: 107
// RVA: 0x5B5170
void __fastcall UFG::VehicleSpot::PropertiesLoad(UFG::VehicleSpot *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v2; // rdi
  UFG::VehicleSpot *v3; // rbx
  UFG::qPropertySet *v4; // rax
  UFG::qPropertySet *v5; // rax
  UFG::qPropertySet *v6; // rax
  signed int v7; // eax
  UFG::qPropertySet *v8; // rax
  UFG::qPropertySet *v9; // rax
  float v10; // xmm0_4
  UFG::qPropertySet *v11; // rax

  v2 = pSceneObj;
  v3 = this;
  v4 = PropertyUtils::Get<bool>(pSceneObj, (UFG::qSymbol *)&qSymbol_CanSpawn.mUID);
  if ( v4 )
    v3->mCanSpawn = v4->mFlags;
  v5 = PropertyUtils::Get<unsigned long>(v2, (UFG::qSymbol *)&qSymbol_RoadNetworkType.mUID);
  if ( v5 )
    v3->mRoadNetworkType = v5->mFlags;
  v6 = PropertyUtils::Get<long>(v2, (UFG::qSymbol *)&qSymbol_RoadNetworkNodeID.mUID);
  if ( v6 )
    v7 = v6->mFlags;
  else
    v7 = -1;
  v3->mRoadSegmentID = v7;
  v8 = PropertyUtils::Get<long>(v2, (UFG::qSymbol *)&qSymbol_RoadNetworkClosestLaneIndex.mUID);
  if ( v8 )
    LODWORD(v8) = v8->mFlags;
  v3->mClosestLaneIndex = (unsigned __int16)v8;
  v9 = PropertyUtils::Get<float>(v2, (UFG::qSymbol *)&qSymbol_RoadNetworkClosestT.mUID);
  if ( v9 )
    v10 = *(float *)&v9->mFlags;
  else
    v10 = 0.0;
  v3->mClosestT = v10;
  v11 = PropertyUtils::Get<bool>(v2, (UFG::qSymbol *)&qSymbol_RoadNetworkNearOrOnIntersection.mUID);
  if ( v11 )
    v3->mNearOrOnIntersection = LOBYTE(v11->mFlags);
  else
    v3->mNearOrOnIntersection = 0;
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
  UFG::ParkingSpot *v1; // rbx
  UFG::RoadNetworkResource *v2; // rax
  UFG::RoadNetworkSegment *v3; // rax

  v1 = this;
  v2 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  if ( v2 )
  {
    v3 = UFG::RoadNetworkResource::GetSegment(v2, v1->mRoadSegmentID);
    if ( !v1->mNearOrOnIntersection )
      UFG::RoadNetworkSegment::AddParkingSpot(v3, v1);
  }
}

// File Line: 313
// RVA: 0x5B4340
bool __fastcall UFG::ParkingSpot::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(pSceneObj, (UFG::qSymbol *)&qSymbolX_propset_componentParkingSpot.mUID);
}

// File Line: 323
// RVA: 0x5B5320
UFG::VehicleSpot *__fastcall UFG::ParkingSpot::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbp
  UFG::qMemoryPool *v2; // rax
  UFG::VehicleSpot *v3; // rdi
  UFG::SimObject *v4; // rbx
  UFG::qSymbol *v5; // rax
  UFG::VehicleSpot *v6; // rax
  UFG::qSymbol result; // [rsp+68h] [rbp+10h]
  UFG::VehicleSpot *v9; // [rsp+70h] [rbp+18h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = (UFG::VehicleSpot *)UFG::qMemoryPool::Allocate(v2, 0xD0ui64, "ParkingSpot", 0i64, 1u);
  v9 = v3;
  if ( v3 )
  {
    v4 = v1->m_pSimObject;
    v5 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v1, &result);
    UFG::VehicleSpot::VehicleSpot(v3, v5, v4);
    v6 = v3 + 1;
    v6->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)v6;
    v6->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v6;
    v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ParkingSpot::`vftable';
    UFG::SimComponent::AddType((UFG::SimComponent *)&v3->vfptr, UFG::ParkingSpot::_ParkingSpotTypeUID, "ParkingSpot");
    v3->mRoadSegmentID = -1;
  }
  else
  {
    v3 = 0i64;
  }
  v3->vfptr[12].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v3->vfptr, (unsigned int)v1);
  ((void (__fastcall *)(UFG::VehicleSpot *))v3->vfptr[19].__vecDelDtor)(v3);
  return v3;
}

// File Line: 331
// RVA: 0x5B5160
void __fastcall UFG::ParkingSpot::PropertiesLoad(UFG::ParkingSpot *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::VehicleSpot::PropertiesLoad((UFG::VehicleSpot *)&this->vfptr, pSceneObj);
}

// File Line: 339
// RVA: 0x5B6E50
UFG::SimObject *__fastcall UFG::ParkingSpot::Spawn(UFG::ParkingSpot *this, UFG::qSymbol *objName, UFG::qPropertySet *parentSet, UFG::SpawnInfoInterface::SpawnPriority priority)
{
  UFG::ParkingSpot *v4; // rbp
  UFG::SpawnInfoInterface::SpawnPriority v5; // esi
  UFG::qPropertySet *v6; // r14
  UFG::SceneObjectProperties *v7; // rax
  UFG::SceneObjectProperties *v8; // rbx
  UFG::qStaticSymbol *v9; // r8
  UFG::SimObject *v10; // rdi
  UFG::qSymbolUC *v11; // rax
  char *v12; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::RoadNetworkGuide *v17; // rcx
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+20h]

  v4 = this;
  v5 = priority;
  v6 = parentSet;
  v7 = UFG::SceneObjectProperties::Create(objName, 0i64, parentSet);
  v8 = v7;
  if ( v5 != 5 )
  {
    switch ( v5 )
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
      case 5:
        goto LABEL_11;
      default:
        v9 = &qSymbol_Critical;
        break;
    }
    PropertyUtils::SetRuntime<UFG::qSymbol>(v7, (UFG::qSymbol *)&qSymbol_SpawnPriority.mUID, (UFG::qSymbol *)&v9->mUID);
  }
LABEL_11:
  v10 = UFG::SceneObjectProperties::Activate(v8, 3u, 0i64, 0i64);
  if ( v10 )
  {
    UFG::SpawnInfoInterface::ClearSpawnLocation(v8, v5);
    UFG::SpawnInfoInterface::ActivateObjectPost(v8, v5, 0i64, v6, 0);
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
  v13 = &v4->mOccupier;
  if ( v4->mOccupier.m_pPointer )
  {
    v14 = v13->mPrev;
    v15 = v4->mOccupier.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v4->mOccupier.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mOccupier.mPrev;
  }
  v4->mOccupier.m_pPointer = v10;
  if ( v10 )
  {
    v16 = v10->m_SafePointerList.mNode.mPrev;
    v16->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v13->mPrev = v16;
    v4->mOccupier.mNext = &v10->m_SafePointerList.mNode;
    v10->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v17 = (UFG::RoadNetworkGuide *)v10->m_Components.p[30].m_pComponent;
  }
  else
  {
    v17 = 0i64;
  }
  UFG::VehicleOccupantComponent::SetParkingSpot(v17, (UFG::RoadNetworkLane *)v4);
  return v10;
}

// File Line: 366
// RVA: 0x155E4F0
__int64 UFG::_dynamic_initializer_for__gsymParkingSets__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("default-roadnetwork-parking-parkingsets", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gsymParkingSets, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gsymParkingSets__);
}

// File Line: 369
// RVA: 0x5B2D00
bool __fastcall UFG::ParkingSpot::CanSpawn(UFG::ParkingSpot *this)
{
  return this->mCanSpawn && !this->mOccupier.m_pPointer;
}

