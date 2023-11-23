// File Line: 19
// RVA: 0x15788E0
__int64 dynamic_initializer_for__WayFinderDummyGraph__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__WayFinderDummyGraph__);
}

// File Line: 26
// RVA: 0x643790
void __fastcall UFG::WheeledVehicleNavigationData::WheeledVehicleNavigationData(
        UFG::WheeledVehicleNavigationData *this)
{
  this->m_RoadNetworkGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::WayGraph::`vftable;
  this->m_RoadNetworkGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::RoadNetworkGraph::`vftable;
  this->m_RoadNetworkGraph.mRoadNetworkType = 0;
  this->m_RoadNetworkGraph.pWayfindingList = 0i64;
  this->m_RoadNetworkGraph.pRoadNetworkResource = 0i64;
  this->m_TrafficGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::WayGraph::`vftable;
  this->m_TrafficGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::RoadNetworkGraph::`vftable;
  this->m_TrafficGraph.mRoadNetworkType = 0;
  this->m_TrafficGraph.pWayfindingList = 0i64;
  this->m_TrafficGraph.pRoadNetworkResource = 0i64;
  this->m_TramGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::WayGraph::`vftable;
  this->m_TramGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::RoadNetworkGraph::`vftable;
  this->m_TramGraph.mRoadNetworkType = 0;
  this->m_TramGraph.pWayfindingList = 0i64;
  this->m_TramGraph.pRoadNetworkResource = 0i64;
  this->m_FerryGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::WayGraph::`vftable;
  this->m_FerryGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::RoadNetworkGraph::`vftable;
  this->m_FerryGraph.mRoadNetworkType = 0;
  this->m_FerryGraph.pWayfindingList = 0i64;
  this->m_FerryGraph.pRoadNetworkResource = 0i64;
  this->m_OceanGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::WayGraph::`vftable;
  this->m_OceanGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::RoadNetworkGraph::`vftable;
  this->m_OceanGraph.mRoadNetworkType = 0;
  this->m_OceanGraph.pWayfindingList = 0i64;
  this->m_OceanGraph.pRoadNetworkResource = 0i64;
  UFG::WayFinder::WayFinder(&this->mTrafficWayFinder, &WayFinderDummyGraph);
  UFG::WayFinder::WayFinder(&this->mTramWayFinder, &WayFinderDummyGraph);
  UFG::WayFinder::WayFinder(&this->mFerryWayFinder, &WayFinderDummyGraph);
  UFG::WayFinder::WayFinder(&this->mOceanWayFinder, &WayFinderDummyGraph);
  this->m_RoadBlockList.mNode.mPrev = &this->m_RoadBlockList.mNode;
  this->m_RoadBlockList.mNode.mNext = &this->m_RoadBlockList.mNode;
  this->m_Valid = 1;
}

// File Line: 34
// RVA: 0x64F290
UFG::RoadNetworkResource *__fastcall UFG::WheeledVehicleNavigationData::GetRoadNetwork(
        UFG::WheeledVehicleNavigationData *this)
{
  return UFG::gpRoadNetworkResource;
}

// File Line: 44
// RVA: 0x6514E0
void __fastcall UFG::WheeledVehicleNavigationData::InitGlobalData(UFG::WheeledVehicleNavigationData *this)
{
  UFG::RoadNetworkResource *v2; // rcx
  UFG::RoadNetworkResource *v3; // rcx
  UFG::RoadNetworkWayfindingList *WayfindingList; // rax
  UFG::RoadNetworkResource *v5; // rcx
  UFG::RoadNetworkWayfindingList *v6; // rax
  UFG::RoadNetworkResource *v7; // rcx
  UFG::RoadNetworkWayfindingList *v8; // rax
  UFG::RoadNetworkResource *v9; // rcx
  UFG::RoadNetworkWayfindingList *v10; // rax
  UFG::RoadNetworkResource *v11; // rax
  unsigned int i; // ebx
  UFG::RoadNetworkSegment *Segment; // rax
  unsigned int v14; // r12d
  UFG::RoadNetworkIntersection *Intersection; // rbp
  unsigned int mNumGates; // r14d
  int v17; // r15d
  unsigned int v18; // esi
  UFG::RoadNetworkConnection *IncomingConnection; // rax
  UFG::RoadNetworkSegment *mOffset; // rcx
  UFG::qPropertySet *RoadPropertySet; // rax
  UFG::qPropertySet *v22; // rdi
  unsigned int v23; // ebx
  bool *v24; // rax
  bool *v25; // rax
  bool *v26; // rax
  bool *v27; // rax
  int RoadNetworkType; // eax
  int v29; // r14d
  bool v30; // cl
  unsigned int v31; // [rsp+50h] [rbp+8h]

  if ( this->m_Valid )
  {
    v2 = UFG::gpRoadNetworkResource;
    if ( UFG::gpRoadNetworkResource )
    {
      this->m_RoadNetworkGraph.pRoadNetworkResource = UFG::gpRoadNetworkResource;
      this->m_RoadNetworkGraph.pWayfindingList = UFG::RoadNetworkResource::GetWayfindingList(v2);
      v3 = UFG::gpRoadNetworkResource;
      this->m_TrafficGraph.pRoadNetworkResource = UFG::gpRoadNetworkResource;
      WayfindingList = UFG::RoadNetworkResource::GetWayfindingList(v3);
      this->m_TrafficGraph.mRoadNetworkType = 0;
      this->m_TrafficGraph.pWayfindingList = WayfindingList;
      v5 = UFG::gpRoadNetworkResource;
      this->m_TramGraph.pRoadNetworkResource = UFG::gpRoadNetworkResource;
      v6 = UFG::RoadNetworkResource::GetWayfindingList(v5);
      this->m_TramGraph.mRoadNetworkType = 1;
      this->m_TramGraph.pWayfindingList = v6;
      v7 = UFG::gpRoadNetworkResource;
      this->m_FerryGraph.pRoadNetworkResource = UFG::gpRoadNetworkResource;
      v8 = UFG::RoadNetworkResource::GetWayfindingList(v7);
      this->m_FerryGraph.mRoadNetworkType = 2;
      this->m_FerryGraph.pWayfindingList = v8;
      v9 = UFG::gpRoadNetworkResource;
      this->m_OceanGraph.pRoadNetworkResource = UFG::gpRoadNetworkResource;
      v10 = UFG::RoadNetworkResource::GetWayfindingList(v9);
      this->m_OceanGraph.mRoadNetworkType = 3;
      this->m_OceanGraph.pWayfindingList = v10;
      UFG::GetWayFinder()->m_WayGraph = &this->m_RoadNetworkGraph;
      this->mOceanWayFinder.m_WayGraph = &this->m_OceanGraph;
      this->mTrafficWayFinder.m_WayGraph = &this->m_TrafficGraph;
      this->mTramWayFinder.m_WayGraph = &this->m_TramGraph;
      this->mFerryWayFinder.m_WayGraph = &this->m_FerryGraph;
      v11 = UFG::gpRoadNetworkResource;
      for ( i = 0; i < UFG::gpRoadNetworkResource->mNumSegments; ++i )
      {
        Segment = UFG::RoadNetworkResource::GetSegment(v11, i);
        UFG::RoadNetworkSegment::SetBitsFromRoadPropertySet(Segment);
        v11 = UFG::gpRoadNetworkResource;
      }
      v14 = 0;
      v31 = 0;
      if ( v11->mNumIntersections )
      {
        do
        {
          Intersection = UFG::RoadNetworkResource::GetIntersection(v11, v14);
          mNumGates = (unsigned __int8)Intersection->mNumGates;
          if ( Intersection->mNumGates )
          {
            v17 = 0;
            v18 = 0;
            if ( Intersection->mNumGates )
            {
              while ( 1 )
              {
                IncomingConnection = UFG::RoadNetworkGate::GetIncomingConnection(
                                       (UFG::RoadNetworkGate *)Intersection,
                                       v18);
                mOffset = (UFG::RoadNetworkSegment *)IncomingConnection->mLaneList.mOffset;
                if ( mOffset )
                  mOffset = (UFG::RoadNetworkSegment *)((char *)&mOffset->mDataHash + (_QWORD)IncomingConnection);
                RoadPropertySet = UFG::RoadNetworkSegment::GetRoadPropertySet(mOffset);
                v22 = RoadPropertySet;
                if ( !RoadPropertySet )
                  goto LABEL_25;
                v23 = -1;
                v24 = UFG::qPropertySet::Get<bool>(
                        RoadPropertySet,
                        (UFG::qArray<unsigned long,0> *)&qSymbol_RoadDriveableTraffic,
                        DEPTH_RECURSE);
                if ( v24 && !*v24 )
                  v23 = -24;
                v25 = UFG::qPropertySet::Get<bool>(
                        v22,
                        (UFG::qArray<unsigned long,0> *)&qSymbol_RoadDriveableTransitOnly,
                        DEPTH_RECURSE);
                if ( v25 && *v25 )
                  v23 &= 0xFFFFFFF9;
                v26 = UFG::qPropertySet::Get<bool>(
                        v22,
                        (UFG::qArray<unsigned long,0> *)&qSymbol_WayFinderNoVehicle,
                        DEPTH_RECURSE);
                if ( v26 && *v26 )
                  v23 = 64;
                v27 = UFG::qPropertySet::Get<bool>(
                        v22,
                        (UFG::qArray<unsigned long,0> *)&qSymbol_WayFinderGPSOnly,
                        DEPTH_RECURSE);
                if ( v27 )
                {
                  if ( *v27 )
                    break;
                }
                if ( v23 != -1 )
                  goto LABEL_24;
LABEL_25:
                if ( ++v18 >= mNumGates )
                {
                  v14 = v31;
                  goto LABEL_27;
                }
              }
              v23 = 64;
LABEL_24:
              ++v17;
              UFG::RoadNetworkIntersection::AddLanesToGateModification(Intersection, v18, v23);
              goto LABEL_25;
            }
LABEL_27:
            RoadNetworkType = UFG::RoadNetworkIntersection::GetRoadNetworkType(Intersection);
            v29 = mNumGates - v17;
            v30 = Intersection->mNumLightPhases < 2u && Intersection->mIsMerged;
            if ( RoadNetworkType == 3 || v29 == 2 || v30 )
              UFG::RoadNetworkIntersection::AddPhaseModification(Intersection, All_Green);
          }
          v11 = UFG::gpRoadNetworkResource;
          v31 = ++v14;
        }
        while ( v14 < UFG::gpRoadNetworkResource->mNumIntersections );
      }
    }
  }
}

// File Line: 152
// RVA: 0x64F310
UFG::WayFinder *__fastcall UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
        UFG::WheeledVehicleNavigationData *this,
        UFG::VehicleWayFinderClient *client)
{
  unsigned int m_RoadNetworkType; // eax
  UFG::WayFinder *result; // rax
  bool v4; // zf

  m_RoadNetworkType = client->m_RoadNetworkType;
  if ( m_RoadNetworkType == 1 )
    return &this->mTramWayFinder;
  if ( m_RoadNetworkType == 2 )
    return &this->mFerryWayFinder;
  v4 = m_RoadNetworkType == 3;
  result = &this->mOceanWayFinder;
  if ( !v4 )
    return &this->mTrafficWayFinder;
  return result;
}

// File Line: 178
// RVA: 0x64F2A0
UFG::WheeledVehicleNavigationData *__fastcall UFG::WheeledVehicleNavigationData::GetRoadNetworkGraph(
        UFG::WheeledVehicleNavigationData *this,
        UFG::VehicleWayFinderClient *client)
{
  unsigned int m_RoadNetworkType; // eax
  UFG::WheeledVehicleNavigationData *result; // rax
  bool v4; // zf

  m_RoadNetworkType = client->m_RoadNetworkType;
  switch ( m_RoadNetworkType )
  {
    case 0u:
      return (UFG::WheeledVehicleNavigationData *)&this->m_TrafficGraph;
    case 1u:
      return (UFG::WheeledVehicleNavigationData *)&this->m_TramGraph;
    case 2u:
      return (UFG::WheeledVehicleNavigationData *)&this->m_FerryGraph;
  }
  v4 = m_RoadNetworkType == 3;
  result = (UFG::WheeledVehicleNavigationData *)&this->m_OceanGraph;
  if ( !v4 )
    return this;
  return result;
}

// File Line: 187
// RVA: 0x64F2E0
UFG::WheeledVehicleNavigationData *__fastcall UFG::WheeledVehicleNavigationData::GetRoadNetworkGraph(
        UFG::WheeledVehicleNavigationData *this,
        UFG::RoadNetworkNode::RoadNetworkType type)
{
  UFG::WheeledVehicleNavigationData *result; // rax

  switch ( type )
  {
    case Traffic:
      return (UFG::WheeledVehicleNavigationData *)&this->m_TrafficGraph;
    case Tram:
      return (UFG::WheeledVehicleNavigationData *)&this->m_TramGraph;
    case Ferry:
      return (UFG::WheeledVehicleNavigationData *)&this->m_FerryGraph;
  }
  result = (UFG::WheeledVehicleNavigationData *)&this->m_OceanGraph;
  if ( type != Ocean )
    return this;
  return result;
}

// File Line: 208
// RVA: 0x644970
void __fastcall UFG::WheeledVehicleNavigationData::AddRoadBlock(
        UFG::WheeledVehicleNavigationData *this,
        UFG::RoadNetworkSegment *source,
        UFG::RoadNetworkSegment *dest)
{
  UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *mNext; // rax
  UFG::qList<UFG::RoadBlock,UFG::RoadBlock,1,0> *p_m_RoadBlockList; // r13
  UFG::RoadNetworkNode *v7; // r12
  unsigned int v8; // ebp
  UFG::RoadNetworkLane *Lane; // rax
  __int64 mOffset; // rcx
  UFG::RoadNetworkConnection *v11; // rdi
  unsigned int v12; // ebx
  UFG::RoadNetworkLane *Path; // rax
  UFG::RoadNetworkLane *v14; // rsi
  UFG::RoadNetworkConnection *v15; // rcx
  UFG::RoadNetworkLane *v16; // rax
  UFG::RoadNetworkSegment *v17; // rax
  unsigned int mNumLanes; // eax
  unsigned int v19; // edi
  unsigned int i; // ebx
  unsigned __int64 v21; // rax
  unsigned int j; // ebx
  UFG::RoadNetworkLane *v23; // rax
  unsigned int k; // ebp
  UFG::RoadNetworkLane *v25; // rax
  __int64 v26; // rcx
  UFG::RoadNetworkConnection *v27; // rdi
  unsigned int m; // ebx
  UFG::RoadNetworkLane *v29; // rax
  UFG::RoadNetworkLane *v30; // rsi
  UFG::RoadNetworkConnection *v31; // rcx
  UFG::RoadNetworkLane *v32; // rax
  UFG::RoadNetworkSegment *v33; // rax
  UFG::RoadNetworkNodeModification *v34; // rbx
  UFG::allocator::free_link *v35; // rax
  UFG::allocator::free_link *v36; // rcx
  UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *mPrev; // rax
  UFG::qArray<unsigned long,0> laneFlags; // [rsp+28h] [rbp-40h] BYREF

  mNext = this->m_RoadBlockList.mNode.mNext;
  p_m_RoadBlockList = &this->m_RoadBlockList;
  if ( mNext == (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)&this->m_RoadBlockList )
  {
LABEL_5:
    v7 = 0i64;
    v8 = 0;
    if ( source->mNumLanes )
    {
      do
      {
        Lane = UFG::RoadNetworkNode::GetLane(source, v8);
        mOffset = Lane->mNextConnection.mOffset;
        if ( mOffset )
          v11 = (UFG::RoadNetworkConnection *)((char *)&Lane->mNextConnection + mOffset);
        else
          v11 = 0i64;
        v12 = 0;
        if ( v11->mNumLanes )
        {
          while ( 1 )
          {
            Path = UFG::qBezierPathCollectionMemImaged::GetPath(v11, v12);
            v14 = Path;
            v15 = (UFG::RoadNetworkConnection *)Path->mNextConnection.mOffset;
            if ( v15 )
              v15 = (UFG::RoadNetworkConnection *)((char *)v15 + (_QWORD)Path + 104);
            v16 = UFG::qBezierPathCollectionMemImaged::GetPath(v15, 0);
            v17 = v16->mNode.mOffset ? (UFG::RoadNetworkSegment *)((char *)v16 + v16->mNode.mOffset) : 0i64;
            if ( v17 == dest )
              break;
            if ( ++v12 >= v11->mNumLanes )
              goto LABEL_21;
          }
          if ( v14->mNode.mOffset )
            v7 = (UFG::RoadNetworkNode *)((char *)v14 + v14->mNode.mOffset);
          else
            v7 = 0i64;
        }
LABEL_21:
        ++v8;
      }
      while ( v8 < (unsigned __int8)source->mNumLanes );
      if ( v7 )
      {
        laneFlags.p = 0i64;
        *(_QWORD *)&laneFlags.size = 0i64;
        mNumLanes = (unsigned __int8)v7->mNumLanes;
        if ( v7->mNumLanes )
        {
          v19 = (unsigned __int8)v7->mNumLanes;
          if ( mNumLanes > laneFlags.capacity )
          {
            for ( i = 1; i < mNumLanes; i *= 2 )
              ;
            if ( i <= 4 )
              i = 4;
            if ( i - mNumLanes > 0x10000 )
              i = mNumLanes + 0x10000;
            if ( i )
            {
              v21 = 4i64 * i;
              if ( !is_mul_ok(i, 4ui64) )
                v21 = -1i64;
              laneFlags.p = (unsigned int *)UFG::qMalloc(v21, "WheeledVehicleNavigationData", 0i64);
              laneFlags.capacity = i;
            }
          }
          laneFlags.size = v19;
        }
        for ( j = 0; j < (unsigned __int8)v7->mNumLanes; ++j )
        {
          v23 = UFG::RoadNetworkNode::GetLane(v7, j);
          laneFlags.p[v23->mLaneIndex] = (unsigned __int8)v23->mLaneFlags;
        }
        for ( k = 0; k < (unsigned __int8)source->mNumLanes; ++k )
        {
          v25 = UFG::RoadNetworkNode::GetLane(source, k);
          v26 = v25->mNextConnection.mOffset;
          if ( v26 )
            v27 = (UFG::RoadNetworkConnection *)((char *)&v25->mNextConnection + v26);
          else
            v27 = 0i64;
          for ( m = 0; m < v27->mNumLanes; ++m )
          {
            v29 = UFG::qBezierPathCollectionMemImaged::GetPath(v27, m);
            v30 = v29;
            v31 = (UFG::RoadNetworkConnection *)v29->mNextConnection.mOffset;
            if ( v31 )
              v31 = (UFG::RoadNetworkConnection *)((char *)v31 + (_QWORD)v29 + 104);
            v32 = UFG::qBezierPathCollectionMemImaged::GetPath(v31, 0);
            if ( v32->mNode.mOffset )
              v33 = (UFG::RoadNetworkSegment *)((char *)v32 + v32->mNode.mOffset);
            else
              v33 = 0i64;
            if ( v33 == dest )
              laneFlags.p[v30->mLaneIndex] &= 0xFFFFFFE9;
          }
        }
        v34 = UFG::RoadNetworkNode::AddChangeLaneFlagsModification(v7, &laneFlags);
        v35 = UFG::qMalloc(0x30ui64, "RoadBlock", 0i64);
        v36 = v35;
        if ( v35 )
        {
          v35->mNext = v35;
          v35[1].mNext = v35;
          v35[2].mNext = (UFG::allocator::free_link *)source;
          v35[3].mNext = (UFG::allocator::free_link *)dest;
          v35[4].mNext = (UFG::allocator::free_link *)v7;
          v35[5].mNext = (UFG::allocator::free_link *)v34;
        }
        else
        {
          v36 = 0i64;
        }
        mPrev = p_m_RoadBlockList->mNode.mPrev;
        mPrev->mNext = (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)v36;
        v36->mNext = (UFG::allocator::free_link *)mPrev;
        v36[1].mNext = (UFG::allocator::free_link *)p_m_RoadBlockList;
        p_m_RoadBlockList->mNode.mPrev = (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)v36;
        if ( laneFlags.p )
          operator delete[](laneFlags.p);
      }
    }
  }
  else
  {
    while ( source != (UFG::RoadNetworkSegment *)mNext[1].mPrev || dest != (UFG::RoadNetworkSegment *)mNext[1].mNext )
    {
      mNext = mNext->mNext;
      if ( mNext == (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)p_m_RoadBlockList )
        goto LABEL_5;
    }
  }
}

// File Line: 294
// RVA: 0x644CC0
void __fastcall UFG::WheeledVehicleNavigationData::AddRoadBlocksAroundSegment(
        UFG::WheeledVehicleNavigationData *this,
        UFG::RoadNetworkGate *segment)
{
  unsigned int i; // ebp
  UFG::RoadNetworkConnection *IncomingConnection; // rax
  __int64 mOffset; // rcx
  UFG::RoadNetworkGate *v7; // rdi
  unsigned int j; // ebx
  UFG::RoadNetworkConnection *v9; // rax
  __int64 v10; // rcx
  UFG::RoadNetworkSegment *v11; // rdx

  for ( i = 0; i < BYTE1(segment->mDirection.y); ++i )
  {
    IncomingConnection = UFG::RoadNetworkGate::GetIncomingConnection(segment, i);
    mOffset = IncomingConnection->mLaneList.mOffset;
    if ( mOffset )
    {
      v7 = (UFG::RoadNetworkGate *)((char *)&IncomingConnection->mLaneList + mOffset);
      if ( v7 )
      {
        if ( LOWORD(v7->mNode.mOffset) != 1 )
        {
          UFG::WheeledVehicleNavigationData::AddRoadBlock(
            this,
            (UFG::RoadNetworkSegment *)((char *)&IncomingConnection->mLaneList + mOffset),
            (UFG::RoadNetworkSegment *)segment);
          return;
        }
        for ( j = 0; j < BYTE1(v7->mDirection.y); ++j )
        {
          v9 = UFG::RoadNetworkGate::GetIncomingConnection(v7, j);
          v10 = v9->mLaneList.mOffset;
          if ( v10 )
          {
            v11 = (UFG::RoadNetworkSegment *)((char *)&v9->mLaneList + v10);
            if ( v11 )
            {
              if ( segment != (UFG::RoadNetworkGate *)v11 )
                UFG::WheeledVehicleNavigationData::AddRoadBlock(this, v11, (UFG::RoadNetworkSegment *)segment);
            }
          }
        }
      }
    }
  }
}

// File Line: 336
// RVA: 0x658000
void __fastcall UFG::WheeledVehicleNavigationData::RemoveRoadBlocksAroundSegment(
        UFG::WheeledVehicleNavigationData *this,
        UFG::RoadNetworkSegment *segment)
{
  UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *mNext; // rbx
  UFG::qList<UFG::RoadBlock,UFG::RoadBlock,1,0> *p_m_RoadBlockList; // rsi
  UFG::qList<UFG::RoadBlock,UFG::RoadBlock,1,0> *v5; // rdi
  UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *mPrev; // rcx
  UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *v7; // rax

  mNext = this->m_RoadBlockList.mNode.mNext;
  p_m_RoadBlockList = &this->m_RoadBlockList;
  if ( mNext != (UFG::qNode<UFG::RoadBlock,UFG::RoadBlock> *)&this->m_RoadBlockList )
  {
    do
    {
      v5 = (UFG::qList<UFG::RoadBlock,UFG::RoadBlock,1,0> *)mNext->mNext;
      if ( (UFG::RoadNetworkSegment *)mNext[1].mNext == segment )
      {
        UFG::RoadNetworkNode::RemoveModification(
          (UFG::RoadNetworkNode *)mNext[2].mPrev,
          (UFG::RoadNetworkNodeModification *)mNext[2].mNext);
        mPrev = mNext->mPrev;
        v7 = mNext->mNext;
        mPrev->mNext = v7;
        v7->mPrev = mPrev;
        mNext->mPrev = mNext;
        mNext->mNext = mNext;
      }
      mNext = &v5->mNode;
    }
    while ( v5 != p_m_RoadBlockList );
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
  if ( node == 0xFFFF )
    return 0i64;
  else
    return UFG::RoadNetworkWayfindingList::GetNode(this->pWayfindingList, node)->mNumEdges;
}

// File Line: 558
// RVA: 0x64E9A0
__int64 __fastcall UFG::RoadNetworkGraph::GetNodeEdge(
        UFG::RoadNetworkGraph *this,
        unsigned __int16 node,
        unsigned int whichEdge)
{
  __int64 result; // rax

  result = 0xFFFFi64;
  if ( node != 0xFFFF )
    return UFG::RoadNetworkWayfindingList::GetNodeEdge(this->pWayfindingList, node, whichEdge);
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
__int64 __fastcall UFG::RoadNetworkGraph::GetEdgeNode(
        UFG::RoadNetworkGraph *this,
        unsigned __int16 edge,
        int which_end)
{
  UFG::RoadNetworkWayfindingList *pWayfindingList; // rcx

  pWayfindingList = this->pWayfindingList;
  if ( which_end )
    return LOWORD(UFG::RoadNetworkWayfindingList::GetEdge(pWayfindingList, edge)->mNode2Index);
  else
    return LOWORD(UFG::RoadNetworkWayfindingList::GetEdge(pWayfindingList, edge)->mNode1Index);
}

// File Line: 578
// RVA: 0x651B50
bool __fastcall UFG::RoadNetworkGraph::IsEdge(UFG::RoadNetworkGraph *this, unsigned __int16 node)
{
  return node != 0xFFFF && node < this->pWayfindingList->mNumEdges;
}

// File Line: 586
// RVA: 0x64DAF0
bool __fastcall UFG::RoadNetworkGraph::GetEdge(
        UFG::RoadNetworkGraph *this,
        UFG::WayFinderClient *client,
        UFG::qVector3 *position,
        unsigned __int16 *edge)
{
  unsigned int mRoadNetworkType; // r9d
  UFG::RoadNetworkResource *pRoadNetworkResource; // rcx
  UFG::RoadNetworkSegment *ClosestSegment; // rax
  unsigned int p_segment_index; // [rsp+40h] [rbp+8h] BYREF

  mRoadNetworkType = this->mRoadNetworkType;
  pRoadNetworkResource = this->pRoadNetworkResource;
  p_segment_index = 0;
  ClosestSegment = UFG::RoadNetworkResource::GetClosestSegment(
                     pRoadNetworkResource,
                     position,
                     &p_segment_index,
                     mRoadNetworkType);
  if ( ClosestSegment )
  {
    *edge = p_segment_index;
    LOBYTE(ClosestSegment) = 1;
  }
  return (char)ClosestSegment;
}

// File Line: 604
// RVA: 0x64DBA0
bool __fastcall UFG::RoadNetworkGraph::GetEdgeNode(
        UFG::RoadNetworkGraph *this,
        UFG::WayFinderClient *client,
        UFG::qVector3 *position,
        UFG::qVector3 *direction,
        unsigned __int16 *edge,
        int *which_end)
{
  UFG::RoadNetworkSegment *ClosestSegment; // rax
  unsigned int mRoadNetworkType; // r9d
  UFG::RoadNetworkResource *pRoadNetworkResource; // rcx
  int v11; // edi
  UFG::RoadNetworkNode *v12; // rsi
  UFG::RoadNetworkLane *Lane; // rax
  UFG::qVector3 *Pos; // rax
  float v15; // xmm9_4
  float v16; // xmm7_4
  float v17; // xmm8_4
  UFG::RoadNetworkLane *v18; // rax
  UFG::qVector3 result; // [rsp+30h] [rbp-58h] BYREF
  unsigned int p_segment_index; // [rsp+90h] [rbp+8h] BYREF

  if ( this->pWayfindingList )
  {
    mRoadNetworkType = this->mRoadNetworkType;
    pRoadNetworkResource = this->pRoadNetworkResource;
    v11 = 0;
    p_segment_index = 0;
    ClosestSegment = UFG::RoadNetworkResource::GetClosestSegment(
                       pRoadNetworkResource,
                       position,
                       &p_segment_index,
                       mRoadNetworkType);
    v12 = ClosestSegment;
    if ( ClosestSegment )
    {
      *edge = p_segment_index;
      Lane = UFG::RoadNetworkNode::GetLane(ClosestSegment, 0);
      Pos = UFG::RoadNetworkLane::GetPos(Lane, &result, 0.0);
      v15 = Pos->x - position->x;
      v16 = Pos->y - position->y;
      v17 = Pos->z - position->z;
      v18 = UFG::RoadNetworkNode::GetLane(v12, 0);
      ClosestSegment = (UFG::RoadNetworkSegment *)UFG::RoadNetworkLane::GetPos(v18, &result, 1.0);
      LOBYTE(v11) = (float)((float)((float)(direction->x * (float)(*(float *)&ClosestSegment->mType.mValue - position->x))
                                  + (float)(direction->y * (float)(*(float *)&ClosestSegment->mNameHash - position->y)))
                          + (float)(direction->z * (float)(*(float *)&ClosestSegment->mDataHash - position->z))) > (float)((float)((float)(direction->x * v15) + (float)(direction->y * v16)) + (float)(direction->z * v17));
      *which_end = v11;
      LOBYTE(ClosestSegment) = 1;
    }
  }
  else
  {
    LOBYTE(ClosestSegment) = 0;
  }
  return (char)ClosestSegment;
}

// File Line: 633
// RVA: 0x64E9C0
UFG::qVector3 *__fastcall UFG::RoadNetworkGraph::GetNodePosition(
        UFG::RoadNetworkGraph *this,
        UFG::qVector3 *result,
        unsigned __int16 node)
{
  unsigned int v6; // edx
  UFG::qVector3 *p_mPosition; // rax

  v6 = node - this->vfptr->GetNumEdges(this);
  if ( node == 0xFFFF )
    p_mPosition = &UFG::qVector3::msZero;
  else
    p_mPosition = &UFG::RoadNetworkResource::GetIntersection(this->pRoadNetworkResource, v6)->mPosition;
  result->x = p_mPosition->x;
  *(_QWORD *)&result->y = *(_QWORD *)&p_mPosition->y;
  return result;
}

// File Line: 640
// RVA: 0x64DD40
UFG::qVector3 *__fastcall UFG::RoadNetworkGraph::GetEdgePosition(
        UFG::RoadNetworkGraph *this,
        UFG::qVector3 *result,
        unsigned __int16 edge,
        int which_end)
{
  float v5; // xmm6_4
  UFG::RoadNetworkSegment *Segment; // rax
  UFG::RoadNetworkLane *Lane; // rax

  if ( which_end )
    v5 = *(float *)&FLOAT_1_0;
  else
    v5 = 0.0;
  Segment = UFG::RoadNetworkResource::GetSegment(this->pRoadNetworkResource, edge);
  Lane = UFG::RoadNetworkNode::GetLane(Segment, 0);
  UFG::RoadNetworkLane::GetPos(Lane, result, v5);
  return result;
}

// File Line: 646
// RVA: 0x64DB40
double __fastcall UFG::RoadNetworkGraph::GetEdgeLength(UFG::RoadNetworkGraph *this, unsigned __int16 edge)
{
  UFG::RoadNetworkSegment *Segment; // rax
  UFG::RoadNetworkLane *Lane; // rax
  double result; // xmm0_8

  Segment = UFG::RoadNetworkResource::GetSegment(this->pRoadNetworkResource, edge);
  Lane = UFG::RoadNetworkNode::GetLane(Segment, 0);
  *(float *)&result = UFG::RoadNetworkLane::GetLength(Lane);
  return result;
}

// File Line: 653
// RVA: 0x64EA40
__int64 __fastcall UFG::RoadNetworkGraph::GetNumLanesFromToThru(
        UFG::RoadNetworkGraph *this,
        unsigned __int16 from_edge,
        unsigned __int16 to_edge,
        unsigned __int16 thru_node,
        unsigned __int8 laneFlags)
{
  UFG::RoadNetworkResource *pRoadNetworkResource; // rsi
  unsigned int v6; // ebx
  int v8; // ebp
  UFG::RoadNetworkSegment *Segment; // r15
  UFG::RoadNetworkSegment *v10; // r14
  int v11; // eax
  unsigned int v12; // ebx
  UFG::RoadNetworkIntersection *Intersection; // rdi
  UFG::RoadNetworkGate *IncomingConnection; // rax
  UFG::RoadNetworkIntersection *mOffset; // rcx
  UFG::RoadNetworkLane *laneList; // [rsp+30h] [rbp-38h] BYREF
  unsigned int numLanes; // [rsp+78h] [rbp+10h] BYREF

  pRoadNetworkResource = this->pRoadNetworkResource;
  v6 = from_edge;
  v8 = thru_node;
  Segment = UFG::RoadNetworkResource::GetSegment(pRoadNetworkResource, to_edge);
  v10 = UFG::RoadNetworkResource::GetSegment(pRoadNetworkResource, v6);
  v11 = this->vfptr->GetNumEdges(this);
  v12 = 0;
  Intersection = UFG::RoadNetworkResource::GetIntersection(pRoadNetworkResource, v8 - v11);
  if ( !v10->mNumGates )
    return 0i64;
  while ( 1 )
  {
    IncomingConnection = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection(
                                                   (UFG::RoadNetworkGate *)v10,
                                                   v12);
    mOffset = (UFG::RoadNetworkIntersection *)IncomingConnection->mConnectedNode.mOffset;
    if ( mOffset )
      mOffset = (UFG::RoadNetworkIntersection *)((char *)&mOffset->mDataHash + (_QWORD)IncomingConnection);
    if ( mOffset == Intersection )
      break;
    if ( ++v12 >= (unsigned __int8)v10->mNumGates )
      return 0i64;
  }
  if ( !IncomingConnection )
    return 0i64;
  numLanes = 0;
  UFG::RoadNetworkGate::GetLanesLeadingToNode(IncomingConnection, Segment, &laneList, &numLanes, 4u, laneFlags);
  return numLanes;
}

