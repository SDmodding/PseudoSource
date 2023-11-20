// File Line: 19
// RVA: 0x15788E0
__int64 dynamic_initializer_for__WayFinderDummyGraph__()
{
  return atexit(dynamic_atexit_destructor_for__WayFinderDummyGraph__);
}

// File Line: 26
// RVA: 0x643790
void __fastcall UFG::WheeledVehicleNavigationData::WheeledVehicleNavigationData(UFG::WheeledVehicleNavigationData *this)
{
  UFG::WheeledVehicleNavigationData *v1; // rbx
  UFG::RoadNetworkGraph *v2; // rax
  UFG::RoadNetworkGraph *v3; // rax
  UFG::RoadNetworkGraph *v4; // rax
  UFG::RoadNetworkGraph *v5; // rax
  UFG::qList<UFG::RoadBlock,UFG::RoadBlock,1,0> *v6; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->m_RoadNetworkGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::WayGraph::`vftable;
  this->m_RoadNetworkGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::RoadNetworkGraph::`vftable;
  this->m_RoadNetworkGraph.mRoadNetworkType = 0;
  this->m_RoadNetworkGraph.pWayfindingList = 0i64;
  this->m_RoadNetworkGraph.pRoadNetworkResource = 0i64;
  v2 = &this->m_TrafficGraph;
  v2->vfptr = (UFG::WayGraphVtbl *)&UFG::WayGraph::`vftable;
  v2->vfptr = (UFG::WayGraphVtbl *)&UFG::RoadNetworkGraph::`vftable;
  this->m_TrafficGraph.mRoadNetworkType = 0;
  this->m_TrafficGraph.pWayfindingList = 0i64;
  this->m_TrafficGraph.pRoadNetworkResource = 0i64;
  v3 = &this->m_TramGraph;
  v3->vfptr = (UFG::WayGraphVtbl *)&UFG::WayGraph::`vftable;
  v3->vfptr = (UFG::WayGraphVtbl *)&UFG::RoadNetworkGraph::`vftable;
  this->m_TramGraph.mRoadNetworkType = 0;
  this->m_TramGraph.pWayfindingList = 0i64;
  this->m_TramGraph.pRoadNetworkResource = 0i64;
  v4 = &this->m_FerryGraph;
  v4->vfptr = (UFG::WayGraphVtbl *)&UFG::WayGraph::`vftable;
  v4->vfptr = (UFG::WayGraphVtbl *)&UFG::RoadNetworkGraph::`vftable;
  this->m_FerryGraph.mRoadNetworkType = 0;
  this->m_FerryGraph.pWayfindingList = 0i64;
  this->m_FerryGraph.pRoadNetworkResource = 0i64;
  v5 = &this->m_OceanGraph;
  v5->vfptr = (UFG::WayGraphVtbl *)&UFG::WayGraph::`vftable;
  v5->vfptr = (UFG::WayGraphVtbl *)&UFG::RoadNetworkGraph::`vftable;
  this->m_OceanGraph.mRoadNetworkType = 0;
  this->m_OceanGraph.pWayfindingList = 0i64;
  this->m_OceanGraph.pRoadNetworkResource = 0i64;
  UFG::WayFinder::WayFinder(&this->mTrafficWayFinder, &WayFinderDummyGraph);
  UFG::WayFinder::WayFinder(&v1->mTramWayFinder, &WayFinderDummyGraph);
  UFG::WayFinder::WayFinder(&v1->mFerryWayFinder, &WayFinderDummyGraph);
  UFG::WayFinder::WayFinder(&v1->mOceanWayFinder, &WayFinderDummyGraph);
  v6 = &v1->m_RoadBlockList;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  v1->m_Valid = 1;
}

// File Line: 34
// RVA: 0x64F290
UFG::RoadNetworkResource *__fastcall UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleNavigationData *this)
{
  return UFG::gpRoadNetworkResource;
}

// File Line: 44
// RVA: 0x6514E0
void __fastcall UFG::WheeledVehicleNavigationData::InitGlobalData(UFG::WheeledVehicleNavigationData *this)
{
  UFG::WheeledVehicleNavigationData *v1; // r14
  UFG::RoadNetworkResource *v2; // rcx
  UFG::RoadNetworkResource *v3; // rcx
  UFG::RoadNetworkWayfindingList *v4; // rax
  UFG::RoadNetworkResource *v5; // rcx
  UFG::RoadNetworkWayfindingList *v6; // rax
  UFG::RoadNetworkResource *v7; // rcx
  UFG::RoadNetworkWayfindingList *v8; // rax
  UFG::RoadNetworkResource *v9; // rcx
  UFG::RoadNetworkWayfindingList *v10; // rax
  UFG::RoadNetworkResource *v11; // rax
  unsigned int v12; // ebx
  UFG::RoadNetworkSegment *v13; // rax
  unsigned int v14; // er12
  UFG::RoadNetworkIntersection *v15; // rbp
  unsigned int v16; // er14
  int v17; // er15
  unsigned int v18; // esi
  UFG::RoadNetworkConnection *v19; // rax
  UFG::RoadNetworkSegment *v20; // rcx
  UFG::qPropertySet *v21; // rax
  UFG::qPropertySet *v22; // rdi
  unsigned int v23; // ebx
  bool *v24; // rax
  bool *v25; // rax
  bool *v26; // rax
  bool *v27; // rax
  int v28; // eax
  bool v29; // cl
  unsigned int v30; // [rsp+50h] [rbp+8h]

  v1 = this;
  if ( this->m_Valid )
  {
    v2 = UFG::gpRoadNetworkResource;
    if ( UFG::gpRoadNetworkResource )
    {
      v1->m_RoadNetworkGraph.pRoadNetworkResource = UFG::gpRoadNetworkResource;
      v1->m_RoadNetworkGraph.pWayfindingList = UFG::RoadNetworkResource::GetWayfindingList(v2);
      v3 = UFG::gpRoadNetworkResource;
      v1->m_TrafficGraph.pRoadNetworkResource = UFG::gpRoadNetworkResource;
      v4 = UFG::RoadNetworkResource::GetWayfindingList(v3);
      v1->m_TrafficGraph.mRoadNetworkType = 0;
      v1->m_TrafficGraph.pWayfindingList = v4;
      v5 = UFG::gpRoadNetworkResource;
      v1->m_TramGraph.pRoadNetworkResource = UFG::gpRoadNetworkResource;
      v6 = UFG::RoadNetworkResource::GetWayfindingList(v5);
      v1->m_TramGraph.mRoadNetworkType = 1;
      v1->m_TramGraph.pWayfindingList = v6;
      v7 = UFG::gpRoadNetworkResource;
      v1->m_FerryGraph.pRoadNetworkResource = UFG::gpRoadNetworkResource;
      v8 = UFG::RoadNetworkResource::GetWayfindingList(v7);
      v1->m_FerryGraph.mRoadNetworkType = 2;
      v1->m_FerryGraph.pWayfindingList = v8;
      v9 = UFG::gpRoadNetworkResource;
      v1->m_OceanGraph.pRoadNetworkResource = UFG::gpRoadNetworkResource;
      v10 = UFG::RoadNetworkResource::GetWayfindingList(v9);
      v1->m_OceanGraph.mRoadNetworkType = 3;
      v1->m_OceanGraph.pWayfindingList = v10;
      UFG::GetWayFinder()->m_WayGraph = (UFG::WayGraph *)&v1->m_RoadNetworkGraph.vfptr;
      v1->mOceanWayFinder.m_WayGraph = (UFG::WayGraph *)&v1->m_OceanGraph.vfptr;
      v1->mTrafficWayFinder.m_WayGraph = (UFG::WayGraph *)&v1->m_TrafficGraph.vfptr;
      v1->mTramWayFinder.m_WayGraph = (UFG::WayGraph *)&v1->m_TramGraph.vfptr;
      v1->mFerryWayFinder.m_WayGraph = (UFG::WayGraph *)&v1->m_FerryGraph.vfptr;
      v11 = UFG::gpRoadNetworkResource;
      v12 = 0;
      if ( UFG::gpRoadNetworkResource->mNumSegments )
      {
        do
        {
          v13 = UFG::RoadNetworkResource::GetSegment(v11, v12);
          UFG::RoadNetworkSegment::SetBitsFromRoadPropertySet(v13);
          v11 = UFG::gpRoadNetworkResource;
          ++v12;
        }
        while ( v12 < UFG::gpRoadNetworkResource->mNumSegments );
      }
      v14 = 0;
      v30 = 0;
      if ( v11->mNumIntersections )
      {
        do
        {
          v15 = UFG::RoadNetworkResource::GetIntersection(v11, v14);
          v16 = (unsigned __int8)v15->mNumGates;
          if ( v15->mNumGates )
          {
            v17 = 0;
            v18 = 0;
            if ( v15->mNumGates )
            {
              while ( 1 )
              {
                v19 = UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v15, v18);
                v20 = (UFG::RoadNetworkSegment *)v19->mLaneList.mOffset;
                if ( v20 )
                  v20 = (UFG::RoadNetworkSegment *)((char *)v20 + (_QWORD)v19 + 8);
                v21 = UFG::RoadNetworkSegment::GetRoadPropertySet(v20);
                v22 = v21;
                if ( !v21 )
                  goto LABEL_25;
                v23 = -1;
                v24 = UFG::qPropertySet::Get<bool>(
                        v21,
                        (UFG::qSymbol *)&qSymbol_RoadDriveableTraffic.mUID,
                        DEPTH_RECURSE);
                if ( v24 && !*v24 )
                  v23 = -24;
                v25 = UFG::qPropertySet::Get<bool>(
                        v22,
                        (UFG::qSymbol *)&qSymbol_RoadDriveableTransitOnly.mUID,
                        DEPTH_RECURSE);
                if ( v25 && *v25 )
                  v23 &= 0xFFFFFFF9;
                v26 = UFG::qPropertySet::Get<bool>(v22, (UFG::qSymbol *)&qSymbol_WayFinderNoVehicle.mUID, DEPTH_RECURSE);
                if ( v26 && *v26 )
                  v23 = 64;
                v27 = UFG::qPropertySet::Get<bool>(v22, (UFG::qSymbol *)&qSymbol_WayFinderGPSOnly.mUID, DEPTH_RECURSE);
                if ( v27 )
                {
                  if ( *v27 )
                    break;
                }
                if ( v23 != -1 )
                  goto LABEL_24;
LABEL_25:
                if ( ++v18 >= v16 )
                {
                  v14 = v30;
                  goto LABEL_27;
                }
              }
              v23 = 64;
LABEL_24:
              ++v17;
              UFG::RoadNetworkIntersection::AddLanesToGateModification(v15, v18, v23);
              goto LABEL_25;
            }
LABEL_27:
            v28 = UFG::RoadNetworkIntersection::GetRoadNetworkType(v15);
            v29 = v15->mNumLightPhases < 2u && v15->mIsMerged;
            if ( v28 == 3 || v16 - v17 == 2 || v29 )
              UFG::RoadNetworkIntersection::AddPhaseModification(v15, All_Green);
          }
          v11 = UFG::gpRoadNetworkResource;
          v30 = ++v14;
        }
        while ( v14 < UFG::gpRoadNetworkResource->mNumIntersections );
      }
    }
  }
}

// File Line: 152
// RVA: 0x64F310
UFG::WayFinder *__fastcall UFG::WheeledVehicleNavigationData::GetRoadWayFinder(UFG::WheeledVehicleNavigationData *this, UFG::VehicleWayFinderClient *client)
{
  unsigned int v2; // eax
  UFG::WayFinder *result; // rax
  bool v4; // zf

  v2 = client->m_RoadNetworkType;
  if ( v2 == 1 )
    return &this->mTramWayFinder;
  if ( v2 == 2 )
    return &this->mFerryWayFinder;
  v4 = v2 == 3;
  result = &this->mOceanWayFinder;
  if ( !v4 )
    result = &this->mTrafficWayFinder;
  return result;
}

// File Line: 178
// RVA: 0x64F2A0
UFG::WheeledVehicleNavigationData *__fastcall UFG::WheeledVehicleNavigationData::GetRoadNetworkGraph(UFG::WheeledVehicleNavigationData *this, UFG::VehicleWayFinderClient *client)
{
  unsigned int v2; // eax
  UFG::WheeledVehicleNavigationData *result; // rax
  bool v4; // zf

  v2 = client->m_RoadNetworkType;
  switch ( v2 )
  {
    case 0u:
      return (UFG::WheeledVehicleNavigationData *)((char *)this + 32);
    case 1u:
      return (UFG::WheeledVehicleNavigationData *)((char *)this + 64);
    case 2u:
      return (UFG::WheeledVehicleNavigationData *)((char *)this + 96);
  }
  v4 = v2 == 3;
  result = (UFG::WheeledVehicleNavigationData *)((char *)this + 128);
  if ( !v4 )
    result = this;
  return result;
}

// File Line: 187
// RVA: 0x64F2E0
UFG::WheeledVehicleNavigationData *__fastcall UFG::WheeledVehicleNavigationData::GetRoadNetworkGraph(UFG::WheeledVehicleNavigationData *this, UFG::RoadNetworkNode::RoadNetworkType type)
{
  UFG::WheeledVehicleNavigationData *result; // rax

  switch ( type )
  {
    case 0:
      return (UFG::WheeledVehicleNavigationData *)((char *)this + 32);
    case 1:
      return (UFG::WheeledVehicleNavigationData *)((char *)this + 64);
    case 2:
      return (UFG::WheeledVehicleNavigationData *)((char *)this + 96);
  }
  result = (UFG::WheeledVehicleNavigationData *)((char *)this + 128);
  if ( type != 3 )
    result = this;
  return result;
}

// File Line: 208
// RVA: 0x644970
void __fastcall UFG::WheeledVehicleNavigationData::AddRoadBlock(UFG::WheeledVehicleNavigationData *this, UFG::RoadNetworkSegment *source, UFG::RoadNetworkSegment *dest)
{
  UFG::RoadNetworkSegment *v3; // r14
  UFG::RoadNetworkSegment *v4; // r15
  UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *v5; // rax
  UFG::qList<UFG::RoadBlock,UFG::RoadBlock,1,0> *v6; // r13
  UFG::RoadNetworkNode *v7; // r12
  unsigned int v8; // ebp
  UFG::RoadNetworkLane *v9; // rax
  __int64 v10; // rcx
  UFG::RoadNetworkConnection *v11; // rdi
  unsigned int v12; // ebx
  UFG::RoadNetworkLane *v13; // rax
  UFG::RoadNetworkLane *v14; // rsi
  UFG::RoadNetworkConnection *v15; // rcx
  UFG::RoadNetworkLane *v16; // rax
  UFG::RoadNetworkSegment *v17; // rax
  unsigned int v18; // eax
  unsigned int v19; // edi
  unsigned int v20; // ebx
  unsigned __int64 v21; // rax
  UFG::allocator::free_link *v22; // rax
  unsigned int *v23; // rsi
  unsigned int *v24; // r9
  __int64 v25; // r8
  unsigned int v26; // ebx
  UFG::RoadNetworkLane *v27; // rax
  unsigned int v28; // ebp
  UFG::RoadNetworkLane *v29; // rax
  __int64 v30; // rcx
  UFG::RoadNetworkConnection *v31; // rdi
  unsigned int v32; // ebx
  UFG::RoadNetworkLane *v33; // rax
  UFG::RoadNetworkLane *v34; // rsi
  UFG::RoadNetworkConnection *v35; // rcx
  UFG::RoadNetworkLane *v36; // rax
  UFG::RoadNetworkSegment *v37; // rax
  UFG::RoadNetworkNodeModification *v38; // rbx
  UFG::allocator::free_link *v39; // rax
  UFG::allocator::free_link *v40; // rcx
  UFG::allocator::free_link *v41; // rax
  UFG::qArray<unsigned long,0> laneFlags; // [rsp+28h] [rbp-40h]

  v3 = dest;
  v4 = source;
  v5 = this->m_RoadBlockList.mNode.mNext;
  v6 = &this->m_RoadBlockList;
  if ( v5 == (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)&this->m_RoadBlockList )
  {
LABEL_4:
    v7 = 0i64;
    v8 = 0;
    if ( source->mNumLanes )
    {
      do
      {
        v9 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v4->mType, v8);
        v10 = v9->mNextConnection.mOffset;
        if ( v10 )
          v11 = (UFG::RoadNetworkConnection *)((char *)&v9->mNextConnection + v10);
        else
          v11 = 0i64;
        v12 = 0;
        if ( v11->mNumLanes )
        {
          while ( 1 )
          {
            v13 = UFG::qBezierPathCollectionMemImaged::GetPath(v11, v12);
            v14 = v13;
            v15 = (UFG::RoadNetworkConnection *)v13->mNextConnection.mOffset;
            if ( v15 )
              v15 = (UFG::RoadNetworkConnection *)((char *)v15 + (_QWORD)v13 + 104);
            v16 = UFG::qBezierPathCollectionMemImaged::GetPath(v15, 0);
            v17 = (UFG::RoadNetworkSegment *)(v16->mNode.mOffset ? (UFG::RoadNetworkLane *)((char *)v16
                                                                                          + v16->mNode.mOffset) : 0i64);
            if ( v17 == v3 )
              break;
            if ( ++v12 >= v11->mNumLanes )
              goto LABEL_20;
          }
          if ( v14->mNode.mOffset )
            v7 = (UFG::RoadNetworkNode *)((char *)v14 + v14->mNode.mOffset);
          else
            v7 = 0i64;
        }
LABEL_20:
        ++v8;
      }
      while ( v8 < (unsigned __int8)v4->mNumLanes );
      if ( v7 )
      {
        laneFlags.p = 0i64;
        *(_QWORD *)&laneFlags.size = 0i64;
        v18 = (unsigned __int8)v7->mNumLanes;
        if ( (signed int)v18 <= 0 )
        {
          if ( v7->mNumLanes )
            laneFlags.size = 0;
        }
        else
        {
          v19 = (unsigned __int8)v7->mNumLanes;
          if ( v18 > laneFlags.capacity )
          {
            if ( laneFlags.capacity )
              v20 = 2 * laneFlags.capacity;
            else
              v20 = 1;
            for ( ; v20 < v18; v20 *= 2 )
              ;
            if ( v20 <= 4 )
              v20 = 4;
            if ( v20 - v18 > 0x10000 )
              v20 = v18 + 0x10000;
            if ( v20 )
            {
              v21 = 4i64 * v20;
              if ( !is_mul_ok(v20, 4ui64) )
                v21 = -1i64;
              v22 = UFG::qMalloc(v21, "WheeledVehicleNavigationData", 0i64);
              v23 = (unsigned int *)v22;
              v24 = laneFlags.p;
              if ( laneFlags.p )
              {
                v25 = 0i64;
                if ( laneFlags.size )
                {
                  do
                  {
                    *((_DWORD *)&v22->mNext + v25) = v24[v25];
                    v25 = (unsigned int)(v25 + 1);
                    v24 = laneFlags.p;
                  }
                  while ( (unsigned int)v25 < laneFlags.size );
                }
                operator delete[](v24);
              }
              laneFlags.p = v23;
              laneFlags.capacity = v20;
            }
          }
          laneFlags.size = v19;
        }
        v26 = 0;
        if ( v7->mNumLanes )
        {
          do
          {
            v27 = UFG::RoadNetworkNode::GetLane(v7, v26);
            laneFlags.p[v27->mLaneIndex] = (unsigned __int8)v27->mLaneFlags;
            ++v26;
          }
          while ( v26 < (unsigned __int8)v7->mNumLanes );
        }
        v28 = 0;
        if ( v4->mNumLanes )
        {
          do
          {
            v29 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v4->mType, v28);
            v30 = v29->mNextConnection.mOffset;
            if ( v30 )
              v31 = (UFG::RoadNetworkConnection *)((char *)&v29->mNextConnection + v30);
            else
              v31 = 0i64;
            v32 = 0;
            if ( v31->mNumLanes )
            {
              do
              {
                v33 = UFG::qBezierPathCollectionMemImaged::GetPath(v31, v32);
                v34 = v33;
                v35 = (UFG::RoadNetworkConnection *)v33->mNextConnection.mOffset;
                if ( v35 )
                  v35 = (UFG::RoadNetworkConnection *)((char *)v35 + (_QWORD)v33 + 104);
                v36 = UFG::qBezierPathCollectionMemImaged::GetPath(v35, 0);
                if ( v36->mNode.mOffset )
                  v37 = (UFG::RoadNetworkSegment *)((char *)v36 + v36->mNode.mOffset);
                else
                  v37 = 0i64;
                if ( v37 == v3 )
                  laneFlags.p[v34->mLaneIndex] &= 0xFFFFFFE9;
                ++v32;
              }
              while ( v32 < v31->mNumLanes );
            }
            ++v28;
          }
          while ( v28 < (unsigned __int8)v4->mNumLanes );
        }
        v38 = UFG::RoadNetworkNode::AddChangeLaneFlagsModification(v7, &laneFlags);
        v39 = UFG::qMalloc(0x30ui64, "RoadBlock", 0i64);
        v40 = v39;
        if ( v39 )
        {
          v39->mNext = v39;
          v39[1].mNext = v39;
          v39[2].mNext = (UFG::allocator::free_link *)v4;
          v39[3].mNext = (UFG::allocator::free_link *)v3;
          v39[4].mNext = (UFG::allocator::free_link *)v7;
          v39[5].mNext = (UFG::allocator::free_link *)v38;
        }
        else
        {
          v40 = 0i64;
        }
        v41 = (UFG::allocator::free_link *)v6->mNode.mPrev;
        v41[1].mNext = v40;
        v40->mNext = v41;
        v40[1].mNext = (UFG::allocator::free_link *)v6;
        v6->mNode.mPrev = (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)v40;
        if ( laneFlags.p )
          operator delete[](laneFlags.p);
      }
    }
  }
  else
  {
    while ( __PAIR__((unsigned __int64)dest, (unsigned __int64)source) != *(_OWORD *)&v5[1] )
    {
      v5 = v5->mNext;
      if ( v5 == (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)v6 )
        goto LABEL_4;
    }
  }
}

// File Line: 294
// RVA: 0x644CC0
void __fastcall UFG::WheeledVehicleNavigationData::AddRoadBlocksAroundSegment(UFG::WheeledVehicleNavigationData *this, UFG::RoadNetworkSegment *segment)
{
  unsigned int v2; // ebp
  UFG::RoadNetworkSegment *v3; // rsi
  UFG::WheeledVehicleNavigationData *v4; // r14
  UFG::RoadNetworkConnection *v5; // rax
  __int64 v6; // rcx
  signed __int64 v7; // rdi
  unsigned int v8; // ebx
  UFG::RoadNetworkConnection *v9; // rax
  __int64 v10; // rcx
  UFG::RoadNetworkSegment *v11; // rdx

  v2 = 0;
  v3 = segment;
  v4 = this;
  if ( segment->mNumGates )
  {
    do
    {
      v5 = UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v3, v2);
      v6 = v5->mLaneList.mOffset;
      if ( v6 )
      {
        v7 = (signed __int64)&v5->mLaneList + v6;
        if ( v7 )
        {
          if ( *(_WORD *)v7 != 1 )
          {
            UFG::WheeledVehicleNavigationData::AddRoadBlock(
              v4,
              (UFG::RoadNetworkSegment *)((char *)&v5->mLaneList + v6),
              v3);
            return;
          }
          v8 = 0;
          if ( *(_BYTE *)(v7 + 41) )
          {
            do
            {
              v9 = UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v7, v8);
              v10 = v9->mLaneList.mOffset;
              if ( v10 )
              {
                v11 = (UFG::RoadNetworkSegment *)((char *)&v9->mLaneList + v10);
                if ( v11 )
                {
                  if ( v3 != v11 )
                    UFG::WheeledVehicleNavigationData::AddRoadBlock(v4, v11, v3);
                }
              }
              ++v8;
            }
            while ( v8 < *(unsigned __int8 *)(v7 + 41) );
          }
        }
      }
      ++v2;
    }
    while ( v2 < (unsigned __int8)v3->mNumGates );
  }
}

// File Line: 336
// RVA: 0x658000
void __fastcall UFG::WheeledVehicleNavigationData::RemoveRoadBlocksAroundSegment(UFG::WheeledVehicleNavigationData *this, UFG::RoadNetworkSegment *segment)
{
  UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *v2; // rbx
  UFG::qList<UFG::RoadBlock,UFG::RoadBlock,1,0> *v3; // rsi
  UFG::RoadNetworkSegment *v4; // rbp
  UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *v5; // rdi
  UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *v6; // rcx
  UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *v7; // rax

  v2 = this->m_RoadBlockList.mNode.mNext;
  v3 = &this->m_RoadBlockList;
  v4 = segment;
  if ( v2 != (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)&this->m_RoadBlockList )
  {
    do
    {
      v5 = v2->mNext;
      if ( (UFG::RoadNetworkSegment *)v2[1].mNext == v4 )
      {
        UFG::RoadNetworkNode::RemoveModification(
          (UFG::RoadNetworkNode *)v2[2].mPrev,
          (UFG::RoadNetworkNodeModification *)v2[2].mNext);
        v6 = v2->mPrev;
        v7 = v2->mNext;
        v6->mNext = v7;
        v7->mPrev = v6;
        v2->mPrev = v2;
        v2->mNext = v2;
      }
      v2 = v5;
    }
    while ( v5 != (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)v3 );
  }
}

// File Line: 544
// RVA: 0x64EB60
__int64 __fastcall UFG::RoadNetworkGraph::GetNumNodes(UFG::RoadNetworkGraph *this)
{
  return this->pWayfindingList->mNumNodes;
}

// File Line: 551
// RVA: 0x64EB30
__int64 __fastcall UFG::RoadNetworkGraph::GetNumNodeEdges(UFG::RoadNetworkGraph *this, unsigned __int16 node)
{
  __int64 result; // rax

  if ( node == -1 )
    result = 0i64;
  else
    result = UFG::RoadNetworkWayfindingList::GetNode(this->pWayfindingList, node)->mNumEdges;
  return result;
}

// File Line: 558
// RVA: 0x64E9A0
__int64 __fastcall UFG::RoadNetworkGraph::GetNodeEdge(UFG::RoadNetworkGraph *this, unsigned __int16 node, unsigned int whichEdge)
{
  __int64 result; // rax

  result = 0xFFFFi64;
  if ( node != -1 )
    result = UFG::RoadNetworkWayfindingList::GetNodeEdge(this->pWayfindingList, node, whichEdge);
  return result;
}

// File Line: 565
// RVA: 0x64EA30
__int64 __fastcall UFG::RoadNetworkGraph::GetNumEdges(UFG::RoadNetworkGraph *this)
{
  return this->pWayfindingList->mNumEdges;
}

// File Line: 572
// RVA: 0x64DB70
__int64 __fastcall UFG::RoadNetworkGraph::GetEdgeNode(UFG::RoadNetworkGraph *this, int edge, int which_end)
{
  UFG::RoadNetworkWayfindingList *v3; // rcx
  __int64 result; // rax

  v3 = this->pWayfindingList;
  edge = (unsigned __int16)edge;
  if ( which_end )
    result = LOWORD(UFG::RoadNetworkWayfindingList::GetEdge(v3, edge)->mNode2Index);
  else
    result = LOWORD(UFG::RoadNetworkWayfindingList::GetEdge(v3, edge)->mNode1Index);
  return result;
}

// File Line: 578
// RVA: 0x651B50
bool __fastcall UFG::RoadNetworkGraph::IsEdge(UFG::RoadNetworkGraph *this, unsigned __int16 node)
{
  bool result; // al

  if ( node == -1 )
    result = 0;
  else
    result = node < this->pWayfindingList->mNumEdges;
  return result;
}

// File Line: 586
// RVA: 0x64DAF0
bool __fastcall UFG::RoadNetworkGraph::GetEdge(UFG::RoadNetworkGraph *this, UFG::WayFinderClient *client, UFG::qVector3 *position, unsigned __int16 *edge)
{
  unsigned __int16 *v4; // rbx
  unsigned int v5; // er9
  UFG::RoadNetworkResource *v6; // rcx
  UFG::RoadNetworkSegment *v7; // rax
  unsigned int p_segment_index; // [rsp+40h] [rbp+8h]

  v4 = edge;
  v5 = this->mRoadNetworkType;
  v6 = this->pRoadNetworkResource;
  p_segment_index = 0;
  v7 = UFG::RoadNetworkResource::GetClosestSegment(v6, position, &p_segment_index, v5);
  if ( v7 )
  {
    *v4 = p_segment_index;
    LOBYTE(v7) = 1;
  }
  return (char)v7;
}

// File Line: 604
// RVA: 0x64DBA0
bool __fastcall UFG::RoadNetworkGraph::GetEdgeNode(UFG::RoadNetworkGraph *this, UFG::WayFinderClient *client, UFG::qVector3 *position, UFG::qVector3 *direction, unsigned __int16 *edge, int *which_end)
{
  UFG::qVector3 *v6; // rbp
  UFG::qVector3 *v7; // rbx
  UFG::RoadNetworkSegment *v8; // rax
  unsigned int v9; // er9
  UFG::RoadNetworkResource *v10; // rcx
  int v11; // edi
  UFG::RoadNetworkNode *v12; // rsi
  UFG::RoadNetworkLane *v13; // rax
  UFG::qVector3 *v14; // rax
  float v15; // xmm9_4
  float v16; // xmm7_4
  float v17; // xmm8_4
  UFG::RoadNetworkLane *v18; // rax
  UFG::qVector3 result; // [rsp+30h] [rbp-58h]
  unsigned int p_segment_index; // [rsp+90h] [rbp+8h]

  v6 = direction;
  v7 = position;
  if ( this->pWayfindingList )
  {
    v9 = this->mRoadNetworkType;
    v10 = this->pRoadNetworkResource;
    v11 = 0;
    p_segment_index = 0;
    v8 = UFG::RoadNetworkResource::GetClosestSegment(v10, position, &p_segment_index, v9);
    v12 = (UFG::RoadNetworkNode *)&v8->mType;
    if ( v8 )
    {
      *edge = p_segment_index;
      v13 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v8->mType, 0);
      v14 = UFG::RoadNetworkLane::GetPos(v13, &result, 0.0);
      v15 = v14->x - v7->x;
      v16 = v14->y - v7->y;
      v17 = v14->z - v7->z;
      v18 = UFG::RoadNetworkNode::GetLane(v12, 0);
      v8 = (UFG::RoadNetworkSegment *)UFG::RoadNetworkLane::GetPos(v18, &result, 1.0);
      LOBYTE(v11) = (float)((float)((float)(v6->x * (float)(*(float *)&v8->mType.mValue - v7->x))
                                  + (float)(v6->y * (float)(*(float *)&v8->mNameHash - v7->y)))
                          + (float)(v6->z * (float)(*(float *)&v8->mDataHash - v7->z))) > (float)((float)((float)(v6->x * v15) + (float)(v6->y * v16))
                                                                                                + (float)(v6->z * v17));
      *which_end = v11;
      LOBYTE(v8) = 1;
    }
  }
  else
  {
    LOBYTE(v8) = 0;
  }
  return (char)v8;
}

// File Line: 633
// RVA: 0x64E9C0
UFG::qVector3 *__fastcall UFG::RoadNetworkGraph::GetNodePosition(UFG::RoadNetworkGraph *this, UFG::qVector3 *result, unsigned __int16 node)
{
  unsigned __int16 v3; // bx
  UFG::qVector3 *v4; // rdi
  UFG::RoadNetworkGraph *v5; // rsi
  unsigned int v6; // edx
  UFG::qVector3 *v7; // rax
  float v8; // ecx

  v3 = node;
  v4 = result;
  v5 = this;
  v6 = node - ((unsigned int (*)(void))this->vfptr->GetNumEdges)();
  if ( v3 == -1 )
    v7 = &UFG::qVector3::msZero;
  else
    v7 = &UFG::RoadNetworkResource::GetIntersection(v5->pRoadNetworkResource, v6)->mPosition;
  v4->x = v7->x;
  v8 = v7->y;
  v4->z = v7->z;
  v4->y = v8;
  return v4;
}

// File Line: 640
// RVA: 0x64DD40
UFG::qVector3 *__fastcall UFG::RoadNetworkGraph::GetEdgePosition(UFG::RoadNetworkGraph *this, UFG::qVector3 *result, unsigned __int16 edge, int which_end)
{
  UFG::qVector3 *v4; // rbx
  float v5; // xmm6_4
  UFG::RoadNetworkSegment *v6; // rax
  UFG::RoadNetworkLane *v7; // rax

  v4 = result;
  if ( which_end )
    v5 = *(float *)&FLOAT_1_0;
  else
    v5 = 0.0;
  v6 = UFG::RoadNetworkResource::GetSegment(this->pRoadNetworkResource, edge);
  v7 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v6->mType, 0);
  UFG::RoadNetworkLane::GetPos(v7, v4, v5);
  return v4;
}

// File Line: 646
// RVA: 0x64DB40
void __fastcall UFG::RoadNetworkGraph::GetEdgeLength(UFG::RoadNetworkGraph *this, unsigned __int16 edge)
{
  UFG::RoadNetworkSegment *v2; // rax
  UFG::RoadNetworkLane *v3; // rax

  v2 = UFG::RoadNetworkResource::GetSegment(this->pRoadNetworkResource, edge);
  v3 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v2->mType, 0);
  UFG::RoadNetworkLane::GetLength(v3);
}

// File Line: 653
// RVA: 0x64EA40
__int64 __fastcall UFG::RoadNetworkGraph::GetNumLanesFromToThru(UFG::RoadNetworkGraph *this, unsigned __int16 from_edge, unsigned __int16 to_edge, unsigned __int16 thru_node, unsigned int laneFlags)
{
  UFG::RoadNetworkResource *v5; // rsi
  unsigned int v6; // ebx
  UFG::RoadNetworkGraph *v7; // rdi
  int v8; // ebp
  UFG::RoadNetworkSegment *v9; // r15
  UFG::RoadNetworkSegment *v10; // r14
  int v11; // eax
  unsigned int v12; // ebx
  UFG::RoadNetworkIntersection *v13; // rdi
  UFG::RoadNetworkGate *v14; // rax
  UFG::RoadNetworkIntersection *v15; // rcx
  UFG::RoadNetworkLane *laneList; // [rsp+30h] [rbp-38h]
  unsigned int numLanes; // [rsp+78h] [rbp+10h]

  v5 = this->pRoadNetworkResource;
  v6 = from_edge;
  v7 = this;
  v8 = thru_node;
  v9 = UFG::RoadNetworkResource::GetSegment(this->pRoadNetworkResource, to_edge);
  v10 = UFG::RoadNetworkResource::GetSegment(v5, v6);
  v11 = v7->vfptr->GetNumEdges((UFG::WayGraph *)&v7->vfptr);
  v12 = 0;
  v13 = UFG::RoadNetworkResource::GetIntersection(v5, v8 - v11);
  if ( !v10->mNumGates )
    return 0i64;
  while ( 1 )
  {
    v14 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v10, v12);
    v15 = (UFG::RoadNetworkIntersection *)v14->mConnectedNode.mOffset;
    if ( v15 )
      v15 = (UFG::RoadNetworkIntersection *)((char *)v15 + (_QWORD)v14 + 8);
    if ( v15 == v13 )
      break;
    if ( ++v12 >= (unsigned __int8)v10->mNumGates )
      return 0i64;
  }
  if ( !v14 )
    return 0i64;
  numLanes = 0;
  UFG::RoadNetworkGate::GetLanesLeadingToNode(
    v14,
    (UFG::RoadNetworkNode *)&v9->mType,
    &laneList,
    &numLanes,
    4u,
    laneFlags);
  return numLanes;
}

