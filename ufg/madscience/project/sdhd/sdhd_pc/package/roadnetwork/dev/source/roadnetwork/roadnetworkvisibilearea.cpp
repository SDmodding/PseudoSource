// File Line: 82
// RVA: 0xD0450
void __fastcall UFG::RoadNetworkVisibleArea::RoadNetworkVisibleArea(UFG::RoadNetworkVisibleArea *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4

  this->mRoadNetwork = 0i64;
  this->mPreviousVisibleRoadNetwork = 0i64;
  this->mCurrentVisibleRoadNetwork = 0i64;
  this->mPreviousVisibleSubSegments = 0i64;
  this->mCurrentVisibleSubSegments = 0i64;
  this->mCurrentVisibleDistance = 110.0;
  this->mClosestNodeFromAllTypes = 0i64;
  this->mClosestSubSegmentFromAllTypes = 0i64;
  this->mClosestNodeCollection.p = 0i64;
  *(_QWORD *)&this->mClosestNodeCollection.size = 0i64;
  this->mClosestSubSegmentCollection.p = 0i64;
  *(_QWORD *)&this->mClosestSubSegmentCollection.size = 0i64;
  this->mPreviousClosestNodeFromAllTypes = 0i64;
  this->mPreviousClosestSubSegmentFromAllTypes = 0i64;
  this->mPreviousClosestNodeCollection.p = 0i64;
  *(_QWORD *)&this->mPreviousClosestNodeCollection.size = 0i64;
  this->mPreviousClosestSubSegmentCollection.p = 0i64;
  *(_QWORD *)&this->mPreviousClosestSubSegmentCollection.size = 0i64;
  UFG::RoadNetworkVisibleAreaEdgeManager::RoadNetworkVisibleAreaEdgeManager(&this->mEdgeManager);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mVisitedSegments.mTree.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mVisitedIntersections.mTree.mTree);
  this->mVisibleAreaExpansionStep = 0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mPreviousStartPosition.x = UFG::qVector3::msZero.x;
  this->mPreviousStartPosition.y = y;
  this->mPreviousStartPosition.z = z;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->mStartPosition.x = UFG::qVector3::msZero.x;
  this->mStartPosition.y = v4;
  this->mStartPosition.z = v5;
  v6 = UFG::qVector3::msDirFront.y;
  v7 = UFG::qVector3::msDirFront.z;
  this->mStartDirection.x = UFG::qVector3::msDirFront.x;
  this->mStartDirection.y = v6;
  this->mStartDirection.z = v7;
  this->mStartSpeed = 0.0;
  this->mForceVisibleAreaUpdate = 0;
}

// File Line: 87
// RVA: 0xDCCD0
void __fastcall UFG::RoadNetworkVisibleArea::Init(
        UFG::RoadNetworkVisibleArea *this,
        UFG::RoadNetworkResource *roadNetwork)
{
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qArray<UFG::RoadNetworkNode *,0> *v5; // rax
  UFG::qArray<UFG::RoadNetworkNode *,0> *v6; // rax
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v7; // rax
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v8; // rax
  unsigned int size; // ecx
  unsigned int v10; // ebx
  unsigned int capacity; // edx
  unsigned int v12; // edx
  unsigned int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edx
  unsigned int v16; // ecx
  unsigned int v17; // edx
  unsigned int v18; // edx
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *p_mPreviousClosestSubSegmentCollection; // r14
  unsigned int v20; // eax
  unsigned int v21; // eax

  *(_QWORD *)&this->mPreviousStartPosition.x = 0i64;
  this->mPreviousStartPosition.z = -1000.0;
  *(_QWORD *)&this->mStartPosition.x = 0i64;
  this->mStartPosition.z = -1000.0;
  y = UFG::qVector3::msDirFront.y;
  z = UFG::qVector3::msDirFront.z;
  this->mStartDirection.x = UFG::qVector3::msDirFront.x;
  this->mStartDirection.y = y;
  this->mStartDirection.z = z;
  this->mStartSpeed = 0.0;
  this->mRoadNetwork = roadNetwork;
  v5 = (UFG::qArray<UFG::RoadNetworkNode *,0> *)UFG::qMalloc(0x10ui64, "qArray", 0i64);
  if ( v5 )
  {
    v5->p = 0i64;
    *(_QWORD *)&v5->size = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  this->mPreviousVisibleRoadNetwork = v5;
  v6 = (UFG::qArray<UFG::RoadNetworkNode *,0> *)UFG::qMalloc(0x10ui64, "qArray", 0i64);
  if ( v6 )
  {
    v6->p = 0i64;
    *(_QWORD *)&v6->size = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  this->mCurrentVisibleRoadNetwork = v6;
  v7 = (UFG::qArray<UFG::RoadNetworkSubSegment *,0> *)UFG::qMalloc(0x10ui64, "qArray", 0i64);
  if ( v7 )
  {
    v7->p = 0i64;
    *(_QWORD *)&v7->size = 0i64;
  }
  else
  {
    v7 = 0i64;
  }
  this->mPreviousVisibleSubSegments = v7;
  v8 = (UFG::qArray<UFG::RoadNetworkSubSegment *,0> *)UFG::qMalloc(0x10ui64, "qArray", 0i64);
  if ( v8 )
  {
    v8->p = 0i64;
    *(_QWORD *)&v8->size = 0i64;
  }
  else
  {
    v8 = 0i64;
  }
  this->mCurrentVisibleSubSegments = v8;
  size = this->mClosestNodeCollection.size;
  v10 = 1;
  if ( (int)(4 - size) <= 0 )
  {
    if ( size != 4 )
    {
      if ( size - 4 < size )
        this->mClosestNodeCollection.size = 4;
      else
        this->mClosestNodeCollection.size = 0;
    }
  }
  else
  {
    capacity = this->mClosestNodeCollection.capacity;
    if ( capacity < 4 )
    {
      if ( capacity )
        v12 = 2 * capacity;
      else
        v12 = 1;
      for ( ; v12 < 4; v12 *= 2 )
        ;
      if ( v12 - 4 > 0x10000 )
        v12 = 65540;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mClosestNodeCollection,
        v12,
        "RoadNetworkVisibleArea");
    }
    this->mClosestNodeCollection.size = 4;
  }
  v13 = this->mClosestSubSegmentCollection.size;
  if ( (int)(4 - v13) <= 0 )
  {
    if ( v13 != 4 )
    {
      if ( v13 - 4 < v13 )
        this->mClosestSubSegmentCollection.size = 4;
      else
        this->mClosestSubSegmentCollection.size = 0;
    }
  }
  else
  {
    v14 = this->mClosestSubSegmentCollection.capacity;
    if ( v14 < 4 )
    {
      if ( v14 )
        v15 = 2 * v14;
      else
        v15 = 1;
      for ( ; v15 < 4; v15 *= 2 )
        ;
      if ( v15 - 4 > 0x10000 )
        v15 = 65540;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mClosestSubSegmentCollection,
        v15,
        "RoadNetworkVisibleArea");
    }
    this->mClosestSubSegmentCollection.size = 4;
  }
  v16 = this->mPreviousClosestNodeCollection.size;
  if ( (int)(4 - v16) <= 0 )
  {
    if ( v16 != 4 )
    {
      if ( v16 - 4 < v16 )
        this->mPreviousClosestNodeCollection.size = 4;
      else
        this->mPreviousClosestNodeCollection.size = 0;
    }
  }
  else
  {
    v17 = this->mPreviousClosestNodeCollection.capacity;
    if ( v17 < 4 )
    {
      if ( v17 )
        v18 = 2 * v17;
      else
        v18 = 1;
      for ( ; v18 < 4; v18 *= 2 )
        ;
      if ( v18 - 4 > 0x10000 )
        v18 = 65540;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mPreviousClosestNodeCollection,
        v18,
        "RoadNetworkVisibleArea");
    }
    this->mPreviousClosestNodeCollection.size = 4;
  }
  p_mPreviousClosestSubSegmentCollection = &this->mPreviousClosestSubSegmentCollection;
  v20 = this->mPreviousClosestSubSegmentCollection.size;
  if ( (int)(4 - v20) <= 0 )
  {
    if ( v20 != 4 )
    {
      if ( v20 - 4 < v20 )
        p_mPreviousClosestSubSegmentCollection->size = 4;
      else
        p_mPreviousClosestSubSegmentCollection->size = 0;
    }
  }
  else
  {
    v21 = this->mPreviousClosestSubSegmentCollection.capacity;
    if ( v21 < 4 )
    {
      if ( v21 )
        v10 = 2 * v21;
      for ( ; v10 < 4; v10 *= 2 )
        ;
      if ( v10 - 4 > 0x10000 )
        v10 = 65540;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mPreviousClosestSubSegmentCollection,
        v10,
        "RoadNetworkVisibleArea");
    }
    p_mPreviousClosestSubSegmentCollection->size = 4;
  }
  *this->mClosestNodeCollection.p = 0i64;
  *this->mClosestSubSegmentCollection.p = 0i64;
  *this->mPreviousClosestNodeCollection.p = 0i64;
  *this->mPreviousClosestSubSegmentCollection.p = 0i64;
  *((_QWORD *)this->mClosestNodeCollection.p + 1) = 0i64;
  *((_QWORD *)this->mClosestSubSegmentCollection.p + 1) = 0i64;
  *((_QWORD *)this->mPreviousClosestNodeCollection.p + 1) = 0i64;
  *((_QWORD *)this->mPreviousClosestSubSegmentCollection.p + 1) = 0i64;
  *((_QWORD *)this->mClosestNodeCollection.p + 2) = 0i64;
  *((_QWORD *)this->mClosestSubSegmentCollection.p + 2) = 0i64;
  *((_QWORD *)this->mPreviousClosestNodeCollection.p + 2) = 0i64;
  *((_QWORD *)this->mPreviousClosestSubSegmentCollection.p + 2) = 0i64;
  *((_QWORD *)this->mClosestNodeCollection.p + 3) = 0i64;
  *((_QWORD *)this->mClosestSubSegmentCollection.p + 3) = 0i64;
  *((_QWORD *)this->mPreviousClosestNodeCollection.p + 3) = 0i64;
  *((_QWORD *)this->mPreviousClosestSubSegmentCollection.p + 3) = 0i64;
}

// File Line: 115
// RVA: 0xDFC90
void __fastcall UFG::RoadNetworkVisibleArea::Release(UFG::RoadNetworkVisibleArea *this)
{
  UFG::qArray<UFG::RoadNetworkNode *,0> *mPreviousVisibleRoadNetwork; // rdi
  UFG::RoadNetworkNode **p; // rcx
  UFG::qArray<UFG::RoadNetworkNode *,0> *mCurrentVisibleRoadNetwork; // rdi
  UFG::RoadNetworkNode **v5; // rcx
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *mPreviousVisibleSubSegments; // rdi
  UFG::RoadNetworkSubSegment **v7; // rcx
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *mCurrentVisibleSubSegments; // rdi
  UFG::RoadNetworkSubSegment **v9; // rcx
  UFG::RoadNetworkNode **v10; // rcx
  UFG::RoadNetworkSubSegment **v11; // rcx
  UFG::RoadNetworkNode **v12; // rcx
  UFG::RoadNetworkSubSegment **v13; // rcx

  mPreviousVisibleRoadNetwork = this->mPreviousVisibleRoadNetwork;
  if ( mPreviousVisibleRoadNetwork )
  {
    p = mPreviousVisibleRoadNetwork->p;
    if ( p )
      operator delete[](p);
    mPreviousVisibleRoadNetwork->p = 0i64;
    *(_QWORD *)&mPreviousVisibleRoadNetwork->size = 0i64;
    operator delete[](mPreviousVisibleRoadNetwork);
  }
  mCurrentVisibleRoadNetwork = this->mCurrentVisibleRoadNetwork;
  if ( mCurrentVisibleRoadNetwork )
  {
    v5 = mCurrentVisibleRoadNetwork->p;
    if ( v5 )
      operator delete[](v5);
    mCurrentVisibleRoadNetwork->p = 0i64;
    *(_QWORD *)&mCurrentVisibleRoadNetwork->size = 0i64;
    operator delete[](mCurrentVisibleRoadNetwork);
  }
  mPreviousVisibleSubSegments = this->mPreviousVisibleSubSegments;
  if ( mPreviousVisibleSubSegments )
  {
    v7 = mPreviousVisibleSubSegments->p;
    if ( v7 )
      operator delete[](v7);
    mPreviousVisibleSubSegments->p = 0i64;
    *(_QWORD *)&mPreviousVisibleSubSegments->size = 0i64;
    operator delete[](mPreviousVisibleSubSegments);
  }
  mCurrentVisibleSubSegments = this->mCurrentVisibleSubSegments;
  if ( mCurrentVisibleSubSegments )
  {
    v9 = mCurrentVisibleSubSegments->p;
    if ( v9 )
      operator delete[](v9);
    mCurrentVisibleSubSegments->p = 0i64;
    *(_QWORD *)&mCurrentVisibleSubSegments->size = 0i64;
    operator delete[](mCurrentVisibleSubSegments);
  }
  v10 = this->mClosestNodeCollection.p;
  if ( v10 )
    operator delete[](v10);
  this->mClosestNodeCollection.p = 0i64;
  *(_QWORD *)&this->mClosestNodeCollection.size = 0i64;
  v11 = this->mClosestSubSegmentCollection.p;
  if ( v11 )
    operator delete[](v11);
  this->mClosestSubSegmentCollection.p = 0i64;
  *(_QWORD *)&this->mClosestSubSegmentCollection.size = 0i64;
  v12 = this->mPreviousClosestNodeCollection.p;
  if ( v12 )
    operator delete[](v12);
  this->mPreviousClosestNodeCollection.p = 0i64;
  *(_QWORD *)&this->mPreviousClosestNodeCollection.size = 0i64;
  v13 = this->mPreviousClosestSubSegmentCollection.p;
  if ( v13 )
    operator delete[](v13);
  this->mPreviousClosestSubSegmentCollection.p = 0i64;
  *(_QWORD *)&this->mPreviousClosestSubSegmentCollection.size = 0i64;
  UFG::RoadNetworkVisibleAreaEdgeManager::Clear(&this->mEdgeManager);
}

// File Line: 182
// RVA: 0xDF970
void __fastcall UFG::RoadNetworkVisibleArea::Reinitialize(UFG::RoadNetworkVisibleArea *this)
{
  unsigned int i; // r8d
  UFG::RoadNetworkSubSegment *v3; // r9
  unsigned __int16 mActive; // ax
  unsigned int j; // r8d
  UFG::RoadNetworkNode *v6; // r9
  unsigned __int16 v7; // ax
  unsigned int k; // r8d
  UFG::RoadNetworkSubSegment *v9; // r9
  unsigned __int16 v10; // ax
  unsigned int m; // r8d
  UFG::RoadNetworkNode *v12; // r9
  unsigned __int16 v13; // ax
  UFG::qBaseTreeRB *n; // rax
  UFG::qBaseNodeRB *mParent; // rdx
  __int16 v16; // cx
  Render::SkinningCacheNode *Head; // rbx
  Render::SkinningCacheNode *v18; // rbx
  float y; // xmm1_4
  float z; // xmm2_4

  if ( this->mRoadNetwork )
  {
    for ( i = 0; i < this->mCurrentVisibleSubSegments->size; ++i )
    {
      v3 = this->mCurrentVisibleSubSegments->p[i];
      mActive = v3->mActive;
      do
        --mActive;
      while ( mActive );
      v3->mActive = 0;
    }
    for ( j = 0; j < this->mCurrentVisibleRoadNetwork->size; ++j )
    {
      v6 = this->mCurrentVisibleRoadNetwork->p[j];
      v7 = v6->mActive;
      do
        --v7;
      while ( v7 );
      v6->mActive = 0;
    }
    for ( k = 0; k < this->mPreviousVisibleSubSegments->size; ++k )
    {
      v9 = this->mPreviousVisibleSubSegments->p[k];
      v10 = v9->mActive;
      do
        --v10;
      while ( v10 );
      v9->mActive = 0;
    }
    for ( m = 0; m < this->mPreviousVisibleRoadNetwork->size; ++m )
    {
      v12 = this->mPreviousVisibleRoadNetwork->p[m];
      v13 = v12->mActive;
      do
        --v13;
      while ( v13 );
      v12->mActive = 0;
    }
    this->mPreviousVisibleRoadNetwork->size = 0;
    this->mCurrentVisibleRoadNetwork->size = 0;
    this->mPreviousVisibleSubSegments->size = 0;
    this->mCurrentVisibleSubSegments->size = 0;
    *this->mClosestNodeCollection.p = 0i64;
    *this->mClosestSubSegmentCollection.p = 0i64;
    *this->mPreviousClosestNodeCollection.p = 0i64;
    *this->mPreviousClosestSubSegmentCollection.p = 0i64;
    *((_QWORD *)this->mClosestNodeCollection.p + 1) = 0i64;
    *((_QWORD *)this->mClosestSubSegmentCollection.p + 1) = 0i64;
    *((_QWORD *)this->mPreviousClosestNodeCollection.p + 1) = 0i64;
    *((_QWORD *)this->mPreviousClosestSubSegmentCollection.p + 1) = 0i64;
    *((_QWORD *)this->mClosestNodeCollection.p + 2) = 0i64;
    *((_QWORD *)this->mClosestSubSegmentCollection.p + 2) = 0i64;
    *((_QWORD *)this->mPreviousClosestNodeCollection.p + 2) = 0i64;
    *((_QWORD *)this->mPreviousClosestSubSegmentCollection.p + 2) = 0i64;
    *((_QWORD *)this->mClosestNodeCollection.p + 3) = 0i64;
    *((_QWORD *)this->mClosestSubSegmentCollection.p + 3) = 0i64;
    *((_QWORD *)this->mPreviousClosestNodeCollection.p + 3) = 0i64;
    *((_QWORD *)this->mPreviousClosestSubSegmentCollection.p + 3) = 0i64;
    this->mClosestNodeFromAllTypes = 0i64;
    this->mClosestSubSegmentFromAllTypes = 0i64;
    this->mPreviousClosestNodeFromAllTypes = 0i64;
    this->mPreviousClosestSubSegmentFromAllTypes = 0i64;
    UFG::RoadNetworkVisibleAreaEdgeManager::Clear(&this->mEdgeManager);
    this->mVisibleAreaExpansionStep = 0;
    for ( n = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mVisitedIntersections);
          n;
          n = UFG::qBaseTreeRB::GetNext(&this->mVisitedIntersections.mTree.mTree, &n->mRoot) )
    {
      mParent = n->mNULL.mParent;
      v16 = WORD1(mParent->mParent);
      do
        --v16;
      while ( v16 );
      WORD1(mParent->mParent) = 0;
    }
    while ( this->mVisitedSegments.mTree.mTree.mCount )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mVisitedSegments);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mVisitedSegments,
        &Head->mNode);
      operator delete[](Head);
    }
    while ( this->mVisitedIntersections.mTree.mTree.mCount )
    {
      v18 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mVisitedIntersections);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mVisitedIntersections,
        &v18->mNode);
      operator delete[](v18);
    }
    *(_QWORD *)&this->mPreviousStartPosition.x = 0i64;
    this->mPreviousStartPosition.z = -1000.0;
    *(_QWORD *)&this->mStartPosition.x = 0i64;
    this->mStartPosition.z = -1000.0;
    y = UFG::qVector3::msDirFront.y;
    z = UFG::qVector3::msDirFront.z;
    this->mStartDirection.x = UFG::qVector3::msDirFront.x;
    this->mStartDirection.y = y;
    this->mStartDirection.z = z;
    this->mStartSpeed = 0.0;
    this->mForceVisibleAreaUpdate = 1;
  }
}

// File Line: 284
// RVA: 0xD38F0
void __fastcall UFG::RoadNetworkVisibleArea::ClearLastVisibleArea(UFG::RoadNetworkVisibleArea *this)
{
  __int64 size; // r8
  __int64 v3; // rdx
  UFG::RoadNetworkSubSegment *v4; // r9
  unsigned __int16 mActive; // ax
  unsigned int v6; // ecx
  __int64 v7; // rdi
  __int64 v8; // rsi
  UFG::RoadNetworkNode *v9; // rbx
  unsigned int mIndex; // edx
  unsigned __int16 v11; // ax
  UFG::qBaseTreeRB *i; // rax
  UFG::qBaseNodeRB *mParent; // rdx
  __int16 v14; // cx
  Render::SkinningCacheNode *Head; // rbx
  Render::SkinningCacheNode *v16; // rbx

  size = this->mPreviousVisibleSubSegments->size;
  if ( (_DWORD)size )
  {
    v3 = 0i64;
    do
    {
      v4 = this->mPreviousVisibleSubSegments->p[v3];
      mActive = v4->mActive;
      if ( mActive )
      {
        do
          --mActive;
        while ( mActive );
        v4->mActive = 0;
      }
      ++v3;
      --size;
    }
    while ( size );
  }
  v6 = this->mPreviousVisibleRoadNetwork->size;
  if ( v6 )
  {
    v7 = 0i64;
    v8 = v6;
    do
    {
      v9 = this->mPreviousVisibleRoadNetwork->p[v7];
      mIndex = v9->mIndex;
      if ( !mIndex || !UFG::qBaseTreeRB::Get(&this->mVisitedIntersections.mTree.mTree, mIndex) )
      {
        v11 = v9->mActive;
        do
          --v11;
        while ( v11 );
        v9->mActive = 0;
      }
      ++v7;
      --v8;
    }
    while ( v8 );
  }
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mVisitedIntersections);
        i;
        i = UFG::qBaseTreeRB::GetNext(&this->mVisitedIntersections.mTree.mTree, &i->mRoot) )
  {
    mParent = i->mNULL.mParent;
    v14 = WORD1(mParent->mParent);
    do
      --v14;
    while ( v14 );
    WORD1(mParent->mParent) = 0;
  }
  while ( this->mVisitedSegments.mTree.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mVisitedSegments);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mVisitedSegments,
      &Head->mNode);
    operator delete[](Head);
  }
  while ( this->mVisitedIntersections.mTree.mTree.mCount )
  {
    v16 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&this->mVisitedIntersections);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&this->mVisitedIntersections,
      &v16->mNode);
    operator delete[](v16);
  }
  UFG::RoadNetworkVisibleAreaEdgeManager::Clear(&this->mEdgeManager);
  this->mVisibleAreaExpansionStep = 0;
}

// File Line: 358
// RVA: 0xE1060
char __fastcall UFG::RoadNetworkVisibleArea::UpdateClosestRoadNetworkNodes(UFG::RoadNetworkVisibleArea *this)
{
  float v1; // xmm7_4
  unsigned int v2; // edi
  unsigned int v4; // r14d
  __int64 v5; // rsi
  float x; // xmm10_4
  float v7; // xmm8_4
  float y; // xmm11_4
  float z; // xmm12_4
  UFG::RoadNetworkResource *mRoadNetwork; // rcx
  UFG::RoadNetworkSegment *ClosestNode; // rax
  UFG::RoadNetworkNode *v12; // rbp
  float v13; // xmm6_4
  UFG::RoadNetworkSubSegment *ClosestSubSegment; // rax
  UFG::RoadNetworkNode *v15; // rcx
  UFG::RoadNetworkNode *mClosestNodeFromAllTypes; // rcx
  char result; // al
  UFG::RoadNetworkSubSegment *mClosestSubSegmentFromAllTypes; // rcx
  UFG::RoadNetworkSubSegment **p; // rcx
  char *v20; // rdx
  UFG::qVector3 nodePos; // [rsp+30h] [rbp-98h] BYREF
  UFG::qVector3 pos; // [rsp+40h] [rbp-88h] BYREF

  v1 = FLOAT_3_4028235e38;
  v2 = 0;
  v4 = 0;
  v5 = 0i64;
  x = this->mStartPosition.x;
  pos.x = x;
  v7 = FLOAT_3_4028235e38;
  y = this->mStartPosition.y;
  z = this->mStartPosition.z;
  pos.y = y;
  pos.z = z;
  do
  {
    mRoadNetwork = this->mRoadNetwork;
    nodePos = UFG::qVector3::msZero;
    ClosestNode = (UFG::RoadNetworkSegment *)UFG::RoadNetworkResource::GetClosestNode(
                                               mRoadNetwork,
                                               &pos,
                                               v4,
                                               &nodePos,
                                               0i64);
    v12 = ClosestNode;
    v13 = (float)((float)((float)(nodePos.y - y) * (float)(nodePos.y - y))
                + (float)((float)(nodePos.x - x) * (float)(nodePos.x - x)))
        + (float)((float)(nodePos.z - z) * (float)(nodePos.z - z));
    if ( ClosestNode && v13 <= 19600.0 )
    {
      if ( ClosestNode->mType.mValue )
      {
        this->mClosestSubSegmentCollection.p[v5] = 0i64;
        this->mClosestNodeCollection.p[v5] = ClosestNode;
        v15 = this->mClosestNodeCollection.p[v5];
        if ( (float)((float)((float)((float)(v15->mPosition.y - y) * (float)(v15->mPosition.y - y))
                           + (float)((float)(v15->mPosition.x - x) * (float)(v15->mPosition.x - x)))
                   + (float)((float)(v15->mPosition.z - z) * (float)(v15->mPosition.z - z))) < v1 )
        {
          v1 = (float)((float)((float)(v15->mPosition.y - y) * (float)(v15->mPosition.y - y))
                     + (float)((float)(v15->mPosition.x - x) * (float)(v15->mPosition.x - x)))
             + (float)((float)(v15->mPosition.z - z) * (float)(v15->mPosition.z - z));
          this->mClosestNodeFromAllTypes = v15;
        }
      }
      else
      {
        ClosestSubSegment = UFG::RoadNetworkSegment::GetClosestSubSegment(ClosestNode, &pos);
        this->mClosestSubSegmentCollection.p[v5] = ClosestSubSegment;
        this->mClosestNodeCollection.p[v5] = v12;
        if ( v13 < v7 )
        {
          v7 = v13;
          this->mClosestSubSegmentFromAllTypes = ClosestSubSegment;
        }
        if ( v13 < v1 )
        {
          v1 = v13;
          this->mClosestNodeFromAllTypes = v12;
        }
      }
    }
    else
    {
      this->mClosestNodeCollection.p[v5] = 0i64;
      this->mClosestSubSegmentCollection.p[v5] = 0i64;
    }
    ++v4;
    ++v5;
  }
  while ( v4 < 4 );
  mClosestNodeFromAllTypes = this->mClosestNodeFromAllTypes;
  if ( !mClosestNodeFromAllTypes )
    return this->mPreviousClosestNodeFromAllTypes != 0i64;
  if ( mClosestNodeFromAllTypes == this->mPreviousClosestNodeFromAllTypes )
  {
    if ( mClosestNodeFromAllTypes->mType.mValue
      || (mClosestSubSegmentFromAllTypes = this->mClosestSubSegmentFromAllTypes,
          result = mClosestSubSegmentFromAllTypes != this->mPreviousClosestSubSegmentFromAllTypes,
          mClosestSubSegmentFromAllTypes == this->mPreviousClosestSubSegmentFromAllTypes) )
    {
      p = this->mClosestSubSegmentCollection.p;
      v20 = (char *)((char *)this->mPreviousClosestSubSegmentCollection.p - (char *)p);
      do
      {
        result = *p != *(UFG::RoadNetworkSubSegment **)((char *)p + (_QWORD)v20);
        if ( *p != *(UFG::RoadNetworkSubSegment **)((char *)p + (_QWORD)v20) )
          break;
        ++v2;
        ++p;
      }
      while ( v2 < 4 );
    }
    else
    {
      this->mPreviousClosestSubSegmentFromAllTypes = mClosestSubSegmentFromAllTypes;
    }
  }
  else
  {
    this->mPreviousClosestNodeFromAllTypes = mClosestNodeFromAllTypes;
    if ( mClosestNodeFromAllTypes->mType.mValue == 1 )
      this->mPreviousClosestSubSegmentFromAllTypes = 0i64;
    else
      this->mPreviousClosestSubSegmentFromAllTypes = this->mClosestSubSegmentFromAllTypes;
    return 1;
  }
  return result;
}

// File Line: 486
// RVA: 0xE0FC0
// attributes: thunk
bool __fastcall UFG::RoadNetworkVisibleArea::Update(
        UFG::RoadNetworkVisibleArea *this,
        UFG::qArray<UFG::RoadNetworkSubSegment *,0> *deactivateSubSegments,
        UFG::qArray<UFG::RoadNetworkSubSegment *,0> *activateSubSegments)
{
  return UFG::RoadNetworkVisibleArea::UpdateByEdges(this, deactivateSubSegments, activateSubSegments);
}

// File Line: 492
// RVA: 0xDBD10
UFG::qVector3 *__fastcall UFG::RoadNetworkVisibleArea::GetSubjectPosition(
        UFG::RoadNetworkVisibleArea *this,
        UFG::qVector3 *result)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::qVector3 *v4; // rax
  float y; // xmm1_4
  float z; // xmm0_4

  m_pTransformNodeComponent = (UFG::TransformNodeComponent *)LocalPlayer;
  if ( LocalPlayer )
    m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
  if ( m_pTransformNodeComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    result->x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    result->y = m_pTransformNodeComponent->mWorldTransform.v3.y;
    result->z = m_pTransformNodeComponent->mWorldTransform.v3.z;
    return result;
  }
  else
  {
    y = UFG::qVector3::msZero.y;
    v4 = result;
    result->x = UFG::qVector3::msZero.x;
    z = UFG::qVector3::msZero.z;
    result->y = y;
    result->z = z;
  }
  return v4;
}

// File Line: 528
// RVA: 0xDBDA0
double __fastcall UFG::RoadNetworkVisibleArea::GetSubjectSpeed(UFG::RoadNetworkVisibleArea *this)
{
  UFG::SimObjectCharacter *v1; // rbx
  signed __int16 m_Flags; // cx
  UFG::CharacterSubjectComponent *v3; // rax
  double result; // xmm0_8
  __int16 v5; // cx
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObjectGame *CurrentVehicle; // rax
  __int16 v8; // dx
  UFG::PhysicsMoverInterface *ComponentOfTypeHK; // rax

  v1 = LocalPlayer;
  if ( !LocalPlayer )
    return 0.0;
  m_Flags = LocalPlayer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    v3 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(LocalPlayer);
  else
    v3 = (UFG::CharacterSubjectComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                          ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                              LocalPlayer,
                                              UFG::CharacterSubjectComponent::_TypeUID)
                                          : UFG::SimObject::GetComponentOfType(
                                              LocalPlayer,
                                              UFG::CharacterSubjectComponent::_TypeUID));
  if ( !v3 )
    return 0.0;
  result = ((double (__fastcall *)(UFG::CharacterSubjectComponent *))v3->vfptr[28].__vecDelDtor)(v3);
  v5 = v1->m_Flags;
  if ( (v5 & 0x4000) != 0 )
  {
    m_pComponent = (UFG::CharacterOccupantComponent *)v1->m_Components.p[44].m_pComponent;
  }
  else if ( v5 < 0 || (v5 & 0x2000) != 0 || (v5 & 0x1000) != 0 )
  {
    m_pComponent = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v1,
                                                        UFG::CharacterOccupantComponent::_TypeUID);
  }
  else
  {
    m_pComponent = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                        v1,
                                                        UFG::CharacterOccupantComponent::_TypeUID);
  }
  if ( m_pComponent )
  {
    CurrentVehicle = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
    if ( CurrentVehicle )
    {
      v8 = CurrentVehicle->m_Flags;
      if ( (v8 & 0x4000) == 0 )
      {
        if ( v8 >= 0 )
        {
          if ( (v8 & 0x2000) != 0 )
            return result;
          if ( (v8 & 0x1000) != 0 )
            ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                CurrentVehicle,
                                                                UFG::PhysicsMoverInterface::_TypeUID);
          else
            ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                                CurrentVehicle,
                                                                UFG::PhysicsMoverInterface::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::PhysicsMoverInterface *)CurrentVehicle->m_Components.p[34].m_pComponent;
        }
        if ( ComponentOfTypeHK )
          *(float *)&result = UFG::PhysicsMoverInterface::GetLinearVelocityMagnitude(ComponentOfTypeHK);
      }
    }
  }
  return result;
}

// File Line: 562
// RVA: 0xDB600
UFG::qVector3 *__fastcall UFG::RoadNetworkVisibleArea::GetPreviousStartPosition(
        UFG::RoadNetworkVisibleArea *this,
        UFG::qVector3 *result)
{
  *result = this->mPreviousStartPosition;
  return result;
}

// File Line: 567
// RVA: 0xDBCE0
UFG::qVector3 *__fastcall UFG::RoadNetworkVisibleArea::GetStartPosition(
        UFG::RoadNetworkVisibleArea *this,
        UFG::qVector3 *result)
{
  *result = this->mStartPosition;
  return result;
}

// File Line: 584
// RVA: 0xD2A80
__int64 __fastcall UFG::RoadNetworkVisibleArea::BuildVisibleRoadNetworkByGrid(
        UFG::RoadNetworkVisibleArea *this,
        UFG::RoadNetworkNode *closestNode,
        unsigned int roadNetworkType)
{
  unsigned __int8 v5; // r15
  float v6; // xmm6_4
  float x; // xmm7_4
  float y; // xmm8_4
  float z; // xmm9_4
  UFG::RoadNetworkSegment **p; // rdi
  UFG::RoadNetworkSegment **v11; // r12
  __int64 size; // r13
  UFG::RoadNetworkSegment *v13; // rdi
  unsigned int mIndex; // edx
  unsigned int v15; // esi
  UFG::qBaseTreeRB *v16; // rbx
  UFG::RoadNetworkSubSegment *i; // rbx
  Render::SkinningCacheNode *Head; // rbx
  UFG::qVector3 pos; // [rsp+30h] [rbp-A8h] BYREF
  UFG::qArray<UFG::RoadNetworkSegment *,0> segments; // [rsp+40h] [rbp-98h] BYREF
  UFG::qVector3 nodePos; // [rsp+50h] [rbp-88h] BYREF
  __int64 v23; // [rsp+60h] [rbp-78h]
  __int64 v24; // [rsp+68h] [rbp-70h]
  UFG::qBaseTreeRB v25; // [rsp+70h] [rbp-68h] BYREF
  UFG::qBaseTreeRB *v26; // [rsp+118h] [rbp+40h]

  v25.mNULL.mChild[0] = (UFG::qBaseNodeRB *)-2i64;
  v5 = 0;
  segments.p = 0i64;
  *(_QWORD *)&segments.size = 0i64;
  v24 = 0i64;
  v23 = 0i64;
  v6 = FLOAT_110_0;
  if ( roadNetworkType - 2 <= 1 )
    v6 = FLOAT_200_0;
  x = this->mStartPosition.x;
  y = this->mStartPosition.y;
  z = this->mStartPosition.z;
  pos.x = x;
  pos.y = y;
  pos.z = z;
  if ( roadNetworkType - 2 <= 1 )
  {
    nodePos = UFG::qVector3::msZero;
    if ( UFG::RoadNetworkResource::GetClosestNode(this->mRoadNetwork, &pos, roadNetworkType, &nodePos, 0i64) )
    {
      x = nodePos.x;
      pos = nodePos;
      y = nodePos.y;
      z = nodePos.z;
    }
  }
  UFG::RoadNetworkResource::GetSegmentsInGrid(this->mRoadNetwork, &segments, &pos, roadNetworkType, v6);
  v26 = &v25;
  UFG::qBaseTreeRB::qBaseTreeRB(&v25);
  p = segments.p;
  if ( segments.size )
  {
    v11 = segments.p;
    size = segments.size;
    do
    {
      v13 = *v11;
      mIndex = (*v11)->mIndex;
      if ( !mIndex || !UFG::qBaseTreeRB::Get(&v25, mIndex) )
      {
        v15 = v13->mIndex;
        if ( !v15 || (v16 = UFG::qBaseTreeRB::Get(&v25, v15)) == 0i64 )
        {
          v16 = (UFG::qBaseTreeRB *)UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
          v26 = v16;
          if ( v16 )
          {
            v16->mRoot.mParent = 0i64;
            v16->mRoot.mChild[0] = 0i64;
            v16->mRoot.mChild[1] = 0i64;
            v16->mRoot.mUID = v15;
            v16->mNULL.mParent = (UFG::qBaseNodeRB *)v13;
          }
          else
          {
            v16 = 0i64;
          }
          UFG::qBaseTreeRB::Add(&v25, &v16->mRoot);
        }
        v16->mNULL.mParent = (UFG::qBaseNodeRB *)v13;
        for ( i = (UFG::RoadNetworkSubSegment *)v13->mSubSegmentCollection.mNode.mNext;
              i != (UFG::RoadNetworkSubSegment *)&v13->mSubSegmentCollection;
              i = (UFG::RoadNetworkSubSegment *)i->mNext )
        {
          if ( !i->mActive
            && (float)(v6 * v6) > (float)((float)((float)((float)(x - i->mPosition.x) * (float)(x - i->mPosition.x))
                                                + (float)((float)(y - i->mPosition.y) * (float)(y - i->mPosition.y)))
                                        + (float)((float)(z - i->mPosition.z) * (float)(z - i->mPosition.z))) )
          {
            v5 = 1;
            UFG::RoadNetworkVisibleArea::CreateEdges(this, i);
            while ( !UFG::RoadNetworkVisibleAreaEdgeManager::ExpandOneStep(&this->mEdgeManager) )
              ;
          }
        }
      }
      ++v11;
      --size;
    }
    while ( size );
    p = segments.p;
  }
  v26 = &v25;
  while ( v25.mRoot.mUID )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v25);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)&v25, &Head->mNode);
    operator delete[](Head);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v25);
  v24 = 0i64;
  v23 = 0i64;
  if ( p )
    operator delete[](p);
  return v5;
}aseTreeRB((Render::S

// File Line: 649
// RVA: 0xD58A0
bool __fastcall UFG::RoadNetworkVisibleArea::GenerateOceanVisibleArea(UFG::RoadNetworkVisibleArea *this)
{
  UFG::RoadNetworkNode **p; // rax
  UFG::RoadNetworkNode *v3; // rdi
  bool result; // al

  p = this->mClosestNodeCollection.p;
  v3 = p[3];
  if ( v3 )
  {
    result = UFG::RoadNetworkVisibleArea::BuildVisibleRoadNetworkByGrid(this, p[3], 3u);
    if ( v3->mType.mValue == 1 )
    {
      *((_QWORD *)this->mPreviousClosestNodeCollection.p + 3) = *((_QWORD *)this->mClosestNodeCollection.p + 3);
      *((_QWORD *)this->mPreviousClosestSubSegmentCollection.p + 3) = 0i64;
    }
    else
    {
      *((_QWORD *)this->mPreviousClosestNodeCollection.p + 3) = *((_QWORD *)this->mClosestNodeCollection.p + 3);
      *((_QWORD *)this->mPreviousClosestSubSegmentCollection.p + 3) = *((_QWORD *)this->mClosestSubSegmentCollection.p
                                                                      + 3);
    }
  }
  else
  {
    result = 0;
    *((_QWORD *)this->mPreviousClosestNodeCollection.p + 3) = 0i64;
    *((_QWORD *)this->mPreviousClosestSubSegmentCollection.p + 3) = 0i64;
  }
  return result;
}

// File Line: 726
// RVA: 0xDC450
float __fastcall UFG::RoadNetworkVisibleArea::GetValidDistance(
        UFG::RoadNetworkVisibleArea *this,
        UFG::qVector3 *position,
        bool extensionAllowed,
        bool useSafetyMargin,
        bool isWater)
{
  float mCurrentVisibleDistance; // xmm6_4
  bool IsWithinVisibleAngle; // di
  bool IsWithinVisibleExpandAngle; // al
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm2_4

  mCurrentVisibleDistance = this->mCurrentVisibleDistance;
  IsWithinVisibleAngle = UFG::RoadNetworkVisibleArea::IsWithinVisibleAngle(this, position);
  IsWithinVisibleExpandAngle = UFG::RoadNetworkVisibleArea::IsWithinVisibleExpandAngle(this, position);
  if ( isWater )
  {
    IsWithinVisibleAngle = 1;
    IsWithinVisibleExpandAngle = 1;
  }
  else if ( !IsWithinVisibleAngle )
  {
    goto LABEL_8;
  }
  if ( !extensionAllowed )
  {
LABEL_8:
    if ( !IsWithinVisibleExpandAngle )
      goto LABEL_15;
    v12 = (float)((float)(this->mStartSpeed * 3.5999999) - 23.0) * 1.5217391;
    if ( v12 <= 0.0 )
    {
      v12 = 0.0;
    }
    else
    {
      v13 = FLOAT_35_0;
      if ( v12 >= 35.0 )
        goto LABEL_14;
    }
    v13 = v12;
LABEL_14:
    mCurrentVisibleDistance = mCurrentVisibleDistance + v13;
    goto LABEL_15;
  }
  if ( isWater )
    mCurrentVisibleDistance = mCurrentVisibleDistance + 490.0;
  else
    mCurrentVisibleDistance = mCurrentVisibleDistance + 60.0;
LABEL_15:
  if ( IsWithinVisibleAngle || extensionAllowed )
    goto LABEL_29;
  v14 = (float)((float)(this->mStartSpeed * 3.5999999) - 23.0) * 0.86956519;
  if ( v14 <= 0.0 )
  {
    v14 = 0.0;
  }
  else
  {
    v15 = FLOAT_20_0;
    if ( v14 >= 20.0 )
      goto LABEL_22;
  }
  v15 = v14;
LABEL_22:
  v16 = mCurrentVisibleDistance - v15;
  if ( isWater )
    v17 = FLOAT_100_0;
  else
    v17 = Twk_RN_VisAreaMinVisibleDistanceDelta;
  mCurrentVisibleDistance = this->mCurrentVisibleDistance - v17;
  if ( mCurrentVisibleDistance < 0.0 )
    mCurrentVisibleDistance = 0.0;
  if ( mCurrentVisibleDistance <= v16 )
    mCurrentVisibleDistance = v16;
LABEL_29:
  if ( useSafetyMargin )
    return mCurrentVisibleDistance + -5.0;
  return mCurrentVisibleDistance;
}

// File Line: 784
// RVA: 0xDE4B0
bool __fastcall UFG::RoadNetworkVisibleArea::IsInRange(
        UFG::RoadNetworkVisibleArea *this,
        UFG::RoadNetworkIntersection *roadInter,
        UFG::qVector3 *position)
{
  UFG::RoadNetworkSubSegment *mPreviousClosestSubSegmentFromAllTypes; // rax
  char ExtendBeyondVisibleAreaLimit; // r9
  UFG::RoadNetworkIntersection *mPreviousClosestNodeFromAllTypes; // rcx
  bool v9; // di
  bool isWater; // al
  float ValidDistance; // xmm0_4

  mPreviousClosestSubSegmentFromAllTypes = this->mPreviousClosestSubSegmentFromAllTypes;
  if ( mPreviousClosestSubSegmentFromAllTypes )
  {
    ExtendBeyondVisibleAreaLimit = (*(_DWORD *)&mPreviousClosestSubSegmentFromAllTypes->mParentNode->mBits & 0x40) != 0;
  }
  else
  {
    mPreviousClosestNodeFromAllTypes = (UFG::RoadNetworkIntersection *)this->mPreviousClosestNodeFromAllTypes;
    if ( !mPreviousClosestNodeFromAllTypes )
    {
LABEL_7:
      v9 = 0;
      goto LABEL_8;
    }
    ExtendBeyondVisibleAreaLimit = UFG::RoadNetworkIntersection::GetExtendBeyondVisibleAreaLimit(mPreviousClosestNodeFromAllTypes);
  }
  if ( !ExtendBeyondVisibleAreaLimit )
    goto LABEL_7;
  v9 = 1;
  if ( !UFG::RoadNetworkIntersection::GetExtendBeyondVisibleAreaLimit(roadInter) )
    goto LABEL_7;
LABEL_8:
  isWater = UFG::RoadNetworkIntersection::IsWater(roadInter);
  ValidDistance = UFG::RoadNetworkVisibleArea::GetValidDistance(this, position, v9, 0, isWater);
  return (float)(ValidDistance * ValidDistance) > (float)((float)((float)((float)(this->mStartPosition.y - position->y)
                                                                        * (float)(this->mStartPosition.y - position->y))
                                                                + (float)((float)(this->mStartPosition.x - position->x)
                                                                        * (float)(this->mStartPosition.x - position->x)))
                                                        + (float)((float)(this->mStartPosition.z - position->z)
                                                                * (float)(this->mStartPosition.z - position->z)));
}

// File Line: 790
// RVA: 0xDE5A0
bool __fastcall UFG::RoadNetworkVisibleArea::IsInRange(
        UFG::RoadNetworkVisibleArea *this,
        UFG::RoadNetworkSegment *roadSeg,
        UFG::qVector3 *position)
{
  bool v5; // r14
  unsigned int mValue; // edi
  UFG::qPropertySet *RoadPropertySet; // rax
  unsigned int *v9; // rax
  UFG::RoadNetworkSubSegment *mPreviousClosestSubSegmentFromAllTypes; // rax
  bool isWater; // di
  char ExtendBeyondVisibleAreaLimit; // cl
  UFG::RoadNetworkIntersection *mPreviousClosestNodeFromAllTypes; // rcx
  float ValidDistance; // xmm0_4

  v5 = 1;
  if ( roadSeg->mpPropertySetCached )
  {
    mValue = roadSeg->mRoadNetworkType.mValue;
  }
  else
  {
    RoadPropertySet = UFG::RoadNetworkSegment::GetRoadPropertySet(roadSeg);
    mValue = 0;
    if ( RoadPropertySet )
    {
      v9 = UFG::qPropertySet::Get<unsigned long>(RoadPropertySet, &qSymbol_RoadNetworkType, DEPTH_RECURSE);
      if ( v9 )
        mValue = *v9;
    }
  }
  mPreviousClosestSubSegmentFromAllTypes = this->mPreviousClosestSubSegmentFromAllTypes;
  isWater = mValue - 2 <= 1;
  if ( mPreviousClosestSubSegmentFromAllTypes )
  {
    ExtendBeyondVisibleAreaLimit = (*(_DWORD *)&mPreviousClosestSubSegmentFromAllTypes->mParentNode->mBits & 0x40) != 0;
  }
  else
  {
    mPreviousClosestNodeFromAllTypes = (UFG::RoadNetworkIntersection *)this->mPreviousClosestNodeFromAllTypes;
    if ( !mPreviousClosestNodeFromAllTypes )
    {
LABEL_12:
      v5 = 0;
      goto LABEL_13;
    }
    ExtendBeyondVisibleAreaLimit = UFG::RoadNetworkIntersection::GetExtendBeyondVisibleAreaLimit(mPreviousClosestNodeFromAllTypes);
  }
  if ( !ExtendBeyondVisibleAreaLimit || (*(_DWORD *)&roadSeg->mBits & 0x40) == 0 )
    goto LABEL_12;
LABEL_13:
  ValidDistance = UFG::RoadNetworkVisibleArea::GetValidDistance(this, position, v5, 0, isWater);
  return (float)(ValidDistance * ValidDistance) > (float)((float)((float)((float)(this->mStartPosition.y - position->y)
                                                                        * (float)(this->mStartPosition.y - position->y))
                                                                + (float)((float)(this->mStartPosition.x - position->x)
                                                                        * (float)(this->mStartPosition.x - position->x)))
                                                        + (float)((float)(this->mStartPosition.z - position->z)
                                                                * (float)(this->mStartPosition.z - position->z)));
}

// File Line: 796
// RVA: 0xDEC60
bool __fastcall UFG::RoadNetworkVisibleArea::IsSubSegmentInRange(
        UFG::RoadNetworkVisibleArea *this,
        UFG::RoadNetworkSubSegment *subSegment)
{
  UFG::RoadNetworkSegment *mParentNode; // rbp
  UFG::RoadNetworkConnection *v4; // rdi
  __int64 v6; // r14
  float v7; // xmm6_4
  __int64 mOffset; // rax
  char *v9; // rax
  char *v10; // rcx
  float *v11; // rsi
  char *v12; // rax
  __int64 v13; // rcx
  UFG::RoadNetworkConnection *v14; // rcx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v17; // rax
  float v19; // xmm6_4
  __int64 v20; // rax
  char *v21; // rax
  char *v22; // rcx
  float *v23; // rsi
  char *v24; // rax
  __int64 v25; // rcx
  UFG::qBezierPathMemImaged *v26; // rbx
  unsigned int v27; // eax
  UFG::qBezierSplineMemImaged *v28; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-48h] BYREF
  float splineT; // [rsp+78h] [rbp+10h] BYREF

  mParentNode = subSegment->mParentNode;
  v4 = 0i64;
  v6 = (unsigned int)(((unsigned __int8)mParentNode->mNumLanes - 1) / 2);
  v7 = subSegment->mBeginTCollection[v6];
  mOffset = mParentNode->mLane.mOffset;
  if ( mOffset )
    v9 = (char *)&mParentNode->mLane + mOffset;
  else
    v9 = 0i64;
  v10 = &v9[8 * v6];
  v11 = (float *)&v10[*(_QWORD *)v10];
  if ( !*(_QWORD *)v10 )
    v11 = 0i64;
  if ( *(_QWORD *)v11 )
    v12 = (char *)v11 + *(_QWORD *)v11;
  else
    v12 = 0i64;
  v13 = *((_QWORD *)v12 + 4);
  if ( v13 )
    v14 = (UFG::RoadNetworkConnection *)&v12[v13 + 32];
  else
    v14 = 0i64;
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v14, *((unsigned __int16 *)v11 + 19));
  SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, v7, &splineT);
  v17 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)Path,
                                         SplineParameters);
  UFG::RoadNetworkLane::GetOffsetPos(&result, v17, splineT, v11[10]);
  if ( UFG::RoadNetworkVisibleArea::IsInRange(this, mParentNode, &result) )
    return 1;
  v19 = subSegment->mEndTCollection[v6];
  v20 = mParentNode->mLane.mOffset;
  if ( v20 )
    v21 = (char *)&mParentNode->mLane + v20;
  else
    v21 = 0i64;
  v22 = &v21[8 * v6];
  v23 = (float *)&v22[*(_QWORD *)v22];
  if ( !*(_QWORD *)v22 )
    v23 = 0i64;
  if ( *(_QWORD *)v23 )
    v24 = (char *)v23 + *(_QWORD *)v23;
  else
    v24 = 0i64;
  v25 = *((_QWORD *)v24 + 4);
  if ( v25 )
    v4 = (UFG::RoadNetworkConnection *)&v24[v25 + 32];
  v26 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v4, *((unsigned __int16 *)v23 + 19));
  v27 = UFG::qBezierPathMemImaged::GetSplineParameters(v26, v19, &splineT);
  v28 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)v26,
                                         v27);
  UFG::RoadNetworkLane::GetOffsetPos(&result, v28, splineT, v23[10]);
  return UFG::RoadNetworkVisibleArea::IsInRange(this, mParentNode, &result);
}

// File Line: 810
// RVA: 0xDE6C0
bool __fastcall UFG::RoadNetworkVisibleArea::IsNearStartPosition(
        UFG::RoadNetworkVisibleArea *this,
        UFG::qVector3 *pos,
        float maxDistance)
{
  return (float)(maxDistance * maxDistance) > (float)((float)((float)((float)(this->mStartPosition.x - pos->x)
                                                                    * (float)(this->mStartPosition.x - pos->x))
                                                            + (float)((float)(this->mStartPosition.y - pos->y)
                                                                    * (float)(this->mStartPosition.y - pos->y)))
                                                    + (float)((float)(this->mStartPosition.z - pos->z)
                                                            * (float)(this->mStartPosition.z - pos->z)));
}

// File Line: 818
// RVA: 0xD22D0
_BOOL8 __fastcall UFG::RoadNetworkVisibleArea::AllowVisibleExtension(
        UFG::RoadNetworkVisibleArea *this,
        UFG::RoadNetworkIntersection *roadNode)
{
  UFG::RoadNetworkSubSegment *mPreviousClosestSubSegmentFromAllTypes; // rax
  bool ExtendBeyondVisibleAreaLimit; // cl
  UFG::RoadNetworkIntersection *mPreviousClosestNodeFromAllTypes; // rcx
  bool v6; // zf
  bool v7; // cl
  UFG::RoadNetworkIntersection *v8; // rcx

  mPreviousClosestSubSegmentFromAllTypes = this->mPreviousClosestSubSegmentFromAllTypes;
  if ( roadNode->mType.mValue == 1 )
  {
    if ( mPreviousClosestSubSegmentFromAllTypes )
    {
      ExtendBeyondVisibleAreaLimit = (*(_DWORD *)&mPreviousClosestSubSegmentFromAllTypes->mParentNode->mBits & 0x40) != 0;
    }
    else
    {
      mPreviousClosestNodeFromAllTypes = (UFG::RoadNetworkIntersection *)this->mPreviousClosestNodeFromAllTypes;
      if ( !mPreviousClosestNodeFromAllTypes )
        return 0i64;
      ExtendBeyondVisibleAreaLimit = UFG::RoadNetworkIntersection::GetExtendBeyondVisibleAreaLimit(mPreviousClosestNodeFromAllTypes);
    }
    if ( !ExtendBeyondVisibleAreaLimit )
      return 0i64;
    v6 = !UFG::RoadNetworkIntersection::GetExtendBeyondVisibleAreaLimit(roadNode);
  }
  else
  {
    if ( mPreviousClosestSubSegmentFromAllTypes )
    {
      v7 = (*(_DWORD *)&mPreviousClosestSubSegmentFromAllTypes->mParentNode->mBits & 0x40) != 0;
    }
    else
    {
      v8 = (UFG::RoadNetworkIntersection *)this->mPreviousClosestNodeFromAllTypes;
      if ( !v8 )
        return 0i64;
      v7 = UFG::RoadNetworkIntersection::GetExtendBeyondVisibleAreaLimit(v8);
    }
    if ( !v7 )
      return 0i64;
    v6 = (LODWORD(roadNode[1].mPosition.y) & 0x40) == 0;
  }
  return !v6;
}

// File Line: 894
// RVA: 0xDF1C0
bool __fastcall UFG::RoadNetworkVisibleArea::IsWithinVisibleExpandAngle(
        UFG::RoadNetworkVisibleArea *this,
        UFG::qVector3 *pos)
{
  __m128 x_low; // xmm5
  float y; // xmm6_4
  float z; // xmm7_4
  __m128 v6; // xmm3
  float v7; // xmm1_4
  float v8; // xmm3_4
  __m128 y_low; // xmm5
  float v10; // xmm6_4
  __m128 v11; // xmm7
  float v12; // xmm2_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  UFG::qVector3 n2; // [rsp+20h] [rbp-48h] BYREF
  UFG::qVector3 n1; // [rsp+30h] [rbp-38h] BYREF

  x_low = (__m128)LODWORD(this->mStartDirection.x);
  v6 = x_low;
  y = this->mStartDirection.y;
  z = this->mStartDirection.z;
  v6.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
  if ( v6.m128_f32[0] == 0.0 )
    v7 = 0.0;
  else
    v7 = 1.0 / _mm_sqrt_ps(v6).m128_f32[0];
  v8 = pos->x - this->mStartPosition.x;
  n1.z = z * v7;
  n1.x = x_low.m128_f32[0] * v7;
  y_low = (__m128)LODWORD(pos->y);
  y_low.m128_f32[0] = y_low.m128_f32[0] - this->mStartPosition.y;
  n1.y = y * v7;
  v11 = y_low;
  v10 = pos->z - this->mStartPosition.z;
  v11.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v8 * v8)) + (float)(v10 * v10);
  if ( v11.m128_f32[0] == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / _mm_sqrt_ps(v11).m128_f32[0];
  n2.x = v8 * v12;
  n2.y = y_low.m128_f32[0] * v12;
  n2.z = v10 * v12;
  v13 = FLOAT_3_1415927;
  LODWORD(v14) = COERCE_UNSIGNED_INT(UFG::qAngleBetweenNormals(&n1, &n2)) & _xmm;
  if ( (float)(this->mStartSpeed * 3.5999999) > 23.0 )
    v13 = FLOAT_0_61086524;
  return v13 >= v14;
}

// File Line: 904
// RVA: 0xDF070
bool __fastcall UFG::RoadNetworkVisibleArea::IsWithinVisibleAngle(
        UFG::RoadNetworkVisibleArea *this,
        UFG::qVector3 *pos)
{
  __m128 x_low; // xmm5
  float y; // xmm6_4
  float z; // xmm7_4
  __m128 v6; // xmm3
  float v7; // xmm1_4
  float v8; // xmm3_4
  __m128 y_low; // xmm5
  float v10; // xmm6_4
  __m128 v11; // xmm7
  float v12; // xmm2_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  UFG::qVector3 n2; // [rsp+20h] [rbp-48h] BYREF
  UFG::qVector3 n1; // [rsp+30h] [rbp-38h] BYREF

  x_low = (__m128)LODWORD(this->mStartDirection.x);
  v6 = x_low;
  y = this->mStartDirection.y;
  z = this->mStartDirection.z;
  v6.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
  if ( v6.m128_f32[0] == 0.0 )
    v7 = 0.0;
  else
    v7 = 1.0 / _mm_sqrt_ps(v6).m128_f32[0];
  v8 = pos->x - this->mStartPosition.x;
  n1.z = z * v7;
  n1.x = x_low.m128_f32[0] * v7;
  y_low = (__m128)LODWORD(pos->y);
  y_low.m128_f32[0] = y_low.m128_f32[0] - this->mStartPosition.y;
  n1.y = y * v7;
  v11 = y_low;
  v10 = pos->z - this->mStartPosition.z;
  v11.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v8 * v8)) + (float)(v10 * v10);
  if ( v11.m128_f32[0] == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / _mm_sqrt_ps(v11).m128_f32[0];
  n2.x = v8 * v12;
  n2.y = y_low.m128_f32[0] * v12;
  n2.z = v10 * v12;
  v13 = FLOAT_3_1415927;
  LODWORD(v14) = COERCE_UNSIGNED_INT(UFG::qAngleBetweenNormals(&n1, &n2)) & _xmm;
  if ( (float)(this->mStartSpeed * 3.5999999) > 23.0 )
    v13 = FLOAT_1_6406095;
  return v13 >= v14;
}

// File Line: 914
// RVA: 0xDA390
float __fastcall UFG::RoadNetworkVisibleArea::GetMinVisibleDistance(UFG::RoadNetworkVisibleArea *this, bool isWater)
{
  float v2; // xmm1_4
  float result; // xmm0_4

  if ( isWater )
    v2 = FLOAT_100_0;
  else
    v2 = Twk_RN_VisAreaMinVisibleDistanceDelta;
  result = this->mCurrentVisibleDistance - v2;
  if ( result < 0.0 )
    return 0.0;
  return result;
}

// File Line: 921
// RVA: 0xDC790
float __fastcall UFG::RoadNetworkVisibleArea::GetVisibleDistance(UFG::RoadNetworkVisibleArea *this)
{
  return this->mCurrentVisibleDistance;
}

// File Line: 962
// RVA: 0xE0AC0
bool __fastcall UFG::RoadNetworkVisibleArea::ShouldUpdateVisibleArea(UFG::RoadNetworkVisibleArea *this)
{
  UFG::TransformNodeComponent *v1; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  double SubjectSpeed; // xmm0_8
  bool result; // al

  v1 = 0i64;
  if ( LocalPlayer )
    m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  if ( m_pTransformNodeComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    x = m_pTransformNodeComponent->mWorldTransform.v3.x;
    y = m_pTransformNodeComponent->mWorldTransform.v3.y;
    z = m_pTransformNodeComponent->mWorldTransform.v3.z;
    v7 = UFG::qVector3::msZero.z;
    v8 = UFG::qVector3::msZero.y;
    v9 = UFG::qVector3::msZero.x;
  }
  else
  {
    v9 = UFG::qVector3::msZero.x;
    v8 = UFG::qVector3::msZero.y;
    v7 = UFG::qVector3::msZero.z;
    x = UFG::qVector3::msZero.x;
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
  }
  if ( this->mForceVisibleAreaUpdate )
  {
    this->mForceVisibleAreaUpdate = 0;
  }
  else if ( (v9 != this->mStartPosition.x || v8 != this->mStartPosition.y || v7 != this->mStartPosition.z)
         && (float)((float)((float)((float)(y - this->mStartPosition.y) * (float)(y - this->mStartPosition.y))
                          + (float)((float)(x - this->mStartPosition.x) * (float)(x - this->mStartPosition.x)))
                  + (float)((float)(z - this->mStartPosition.z) * (float)(z - this->mStartPosition.z))) <= 100.0 )
  {
    return 0;
  }
  v10 = this->mStartPosition.y;
  v11 = this->mStartPosition.z;
  this->mPreviousStartPosition.x = this->mStartPosition.x;
  this->mPreviousStartPosition.y = v10;
  this->mPreviousStartPosition.z = v11;
  this->mStartPosition.x = x;
  this->mStartPosition.y = y;
  this->mStartPosition.z = z;
  if ( LocalPlayer )
    v1 = LocalPlayer->m_pTransformNodeComponent;
  if ( v1 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v1);
    v12 = v1->mWorldTransform.v0.x;
    v13 = v1->mWorldTransform.v0.y;
    v14 = v1->mWorldTransform.v0.z;
  }
  else
  {
    v12 = UFG::qVector3::msZero.x;
    v13 = UFG::qVector3::msZero.y;
    v14 = UFG::qVector3::msZero.z;
  }
  this->mStartDirection.x = v12;
  this->mStartDirection.y = v13;
  this->mStartDirection.z = v14;
  SubjectSpeed = UFG::RoadNetworkVisibleArea::GetSubjectSpeed(this);
  result = 1;
  this->mStartSpeed = *(float *)&SubjectSpeed;
  return result;
}

// File Line: 1000
// RVA: 0xE0970
void __fastcall UFG::RoadNetworkVisibleArea::SetVisibleDistance(UFG::RoadNetworkVisibleArea *this, float visibleDist)
{
  this->mCurrentVisibleDistance = visibleDist;
}

// File Line: 1005
// RVA: 0xE04B0
void __fastcall UFG::RoadNetworkVisibleArea::SetForceVisibleAreaUpdate(UFG::RoadNetworkVisibleArea *this)
{
  this->mForceVisibleAreaUpdate = 1;
}

// File Line: 1014
// RVA: 0xE0FD0
bool __fastcall UFG::RoadNetworkVisibleArea::UpdateByEdges(
        UFG::RoadNetworkVisibleArea *this,
        UFG::qArray<UFG::RoadNetworkSubSegment *,0> *deactivateSubSegments,
        UFG::qArray<UFG::RoadNetworkSubSegment *,0> *activateSubSegments)
{
  char LandVisibleArea; // di
  char v7; // di

  if ( !UFG::RoadNetworkVisibleArea::ShouldUpdateVisibleArea(this) )
    return 0;
  UFG::RoadNetworkVisibleArea::ClearLastVisibleArea(this);
  UFG::RoadNetworkVisibleArea::UpdateClosestRoadNetworkNodes(this);
  LandVisibleArea = UFG::RoadNetworkVisibleArea::GenerateLandVisibleArea(this);
  v7 = UFG::RoadNetworkVisibleArea::GenerateOceanVisibleArea(this) | LandVisibleArea;
  if ( v7 )
    UFG::RoadNetworkVisibleArea::UpdateVisibleArea(this, deactivateSubSegments, activateSubSegments);
  return v7;
}

// File Line: 1031
// RVA: 0xD5760
__int64 __fastcall UFG::RoadNetworkVisibleArea::GenerateLandVisibleArea(UFG::RoadNetworkVisibleArea *this)
{
  unsigned __int8 v1; // r15
  unsigned int v3; // r14d
  __int64 v4; // rdi
  UFG::RoadNetworkNode **p; // rax
  UFG::RoadNetworkNode *v6; // rsi
  bool BuildVisibleRoadNetworkByGrid; // al

  v1 = 0;
  v3 = 0;
  v4 = 0i64;
  do
  {
    p = this->mClosestNodeCollection.p;
    v6 = p[v4];
    if ( v3 != 3 )
    {
      if ( v6 )
      {
        if ( v6->mType.mValue == 1 )
          BuildVisibleRoadNetworkByGrid = UFG::RoadNetworkIntersection::GetBuildVisibleRoadNetworkByGrid((UFG::RoadNetworkIntersection *)p[v4]);
        else
          BuildVisibleRoadNetworkByGrid = (v6[1].mOutgoingConnections.mOffset & 0x20) != 0;
        if ( BuildVisibleRoadNetworkByGrid )
        {
          v1 |= UFG::RoadNetworkVisibleArea::BuildVisibleRoadNetworkByGrid(this, v6, v3);
        }
        else
        {
          v1 |= 1u;
          if ( v6->mType.mValue == 1 )
            UFG::RoadNetworkVisibleArea::CreateEdges(this, (UFG::RoadNetworkIntersection *)v6);
          else
            UFG::RoadNetworkVisibleArea::CreateEdges(this, this->mClosestSubSegmentCollection.p[v4]);
          while ( !UFG::RoadNetworkVisibleAreaEdgeManager::ExpandOneStep(&this->mEdgeManager) )
            ;
        }
        if ( v6->mType.mValue == 1 )
        {
          this->mPreviousClosestNodeCollection.p[v4] = this->mClosestNodeCollection.p[v4];
          this->mPreviousClosestSubSegmentCollection.p[v4] = 0i64;
        }
        else
        {
          this->mPreviousClosestNodeCollection.p[v4] = this->mClosestNodeCollection.p[v4];
          this->mPreviousClosestSubSegmentCollection.p[v4] = this->mClosestSubSegmentCollection.p[v4];
        }
      }
      else
      {
        this->mPreviousClosestNodeCollection.p[v4] = 0i64;
        this->mPreviousClosestSubSegmentCollection.p[v4] = 0i64;
      }
    }
    ++v3;
    ++v4;
  }
  while ( v3 < 4 );
  return v1;
}

// File Line: 1088
// RVA: 0xE1C20
void __fastcall UFG::RoadNetworkVisibleArea::UpdateVisibleArea(
        UFG::RoadNetworkVisibleArea *this,
        UFG::qArray<UFG::RoadNetworkSubSegment *,0> *deactivateSubSegments,
        UFG::qArray<UFG::RoadNetworkSubSegment *,0> *activateSubSegments)
{
  __int64 v3; // r12
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v4; // r14
  UFG::RoadNetworkSubSegment **p; // rcx
  UFG::RoadNetworkSubSegment *v8; // r8
  UFG::RoadNetworkSubSegment **v9; // rax
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *mCurrentVisibleSubSegments; // rcx
  unsigned int size; // edx
  unsigned int v12; // eax
  UFG::RoadNetworkSubSegment **v13; // rcx
  __int64 v14; // r15
  unsigned int capacity; // ebx
  unsigned int v16; // esi
  unsigned int v17; // ebx
  unsigned __int64 v18; // rax
  char *v19; // rax
  UFG::RoadNetworkSubSegment **v20; // rbp
  __int64 i; // r9
  __int64 v22; // r8
  UFG::RoadNetworkSubSegment **v23; // rcx
  __int64 j; // r12
  unsigned int v25; // eax
  UFG::RoadNetworkSubSegment *v26; // rbp
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *mPreviousVisibleSubSegments; // rcx
  unsigned int v28; // edx
  UFG::RoadNetworkSubSegment **v29; // rcx
  __int64 v30; // r15
  unsigned int v31; // ebx
  unsigned int v32; // edi
  unsigned int v33; // ebx
  unsigned __int64 v34; // rax
  char *v35; // rax
  char *v36; // rsi
  __int64 k; // r9
  __int64 v38; // r8
  UFG::RoadNetworkSubSegment **v39; // rax
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v40; // rcx
  UFG::qArray<UFG::RoadNetworkNode *,0> *mPreviousVisibleRoadNetwork; // rcx
  UFG::RoadNetworkSubSegment **v42; // [rsp+60h] [rbp+8h]

  v3 = 0i64;
  v4 = activateSubSegments;
  if ( this->mPreviousVisibleSubSegments->size )
  {
    do
    {
      p = this->mPreviousVisibleSubSegments->p;
      v8 = p[v3];
      v9 = &p[v3];
      mCurrentVisibleSubSegments = this->mCurrentVisibleSubSegments;
      size = mCurrentVisibleSubSegments->size;
      v42 = v9;
      v12 = 0;
      if ( !mCurrentVisibleSubSegments->size )
        goto LABEL_8;
      v13 = mCurrentVisibleSubSegments->p;
      while ( v8 != *v13 )
      {
        ++v12;
        ++v13;
        if ( v12 >= size )
          goto LABEL_8;
      }
      if ( v12 == -1 )
      {
LABEL_8:
        v14 = deactivateSubSegments->size;
        capacity = deactivateSubSegments->capacity;
        v16 = v14 + 1;
        if ( (int)v14 + 1 > capacity )
        {
          if ( capacity )
            v17 = 2 * capacity;
          else
            v17 = 1;
          for ( ; v17 < v16; v17 *= 2 )
            ;
          if ( v17 <= 2 )
            v17 = 2;
          if ( v17 - v16 > 0x10000 )
            v17 = v14 + 65537;
          if ( v17 != (_DWORD)v14 )
          {
            v18 = 8i64 * v17;
            if ( !is_mul_ok(v17, 8ui64) )
              v18 = -1i64;
            v19 = UFG::qMalloc(v18, "qArray.Add.deactivateSubSegments", 0i64);
            v20 = (UFG::RoadNetworkSubSegment **)v19;
            if ( deactivateSubSegments->p )
            {
              for ( i = 0i64;
                    (unsigned int)i < deactivateSubSegments->size;
                    *(_QWORD *)&v19[v22 * 8] = deactivateSubSegments->p[v22] )
              {
                v22 = i;
                i = (unsigned int)(i + 1);
              }
              operator delete[](deactivateSubSegments->p);
            }
            deactivateSubSegments->p = v20;
            deactivateSubSegments->capacity = v17;
          }
        }
        v23 = deactivateSubSegments->p;
        deactivateSubSegments->size = v16;
        v23[v14] = *v42;
      }
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < this->mPreviousVisibleSubSegments->size );
    v4 = activateSubSegments;
  }
  for ( j = 0i64; (unsigned int)j < this->mCurrentVisibleSubSegments->size; j = (unsigned int)(j + 1) )
  {
    v25 = 0;
    v26 = this->mCurrentVisibleSubSegments->p[j];
    mPreviousVisibleSubSegments = this->mPreviousVisibleSubSegments;
    v28 = mPreviousVisibleSubSegments->size;
    if ( mPreviousVisibleSubSegments->size )
    {
      v29 = mPreviousVisibleSubSegments->p;
      while ( v26 != *v29 )
      {
        ++v25;
        ++v29;
        if ( v25 >= v28 )
          goto LABEL_36;
      }
      if ( v25 != -1 )
        continue;
    }
LABEL_36:
    v30 = v4->size;
    v31 = v4->capacity;
    v32 = v30 + 1;
    if ( (int)v30 + 1 > v31 )
    {
      if ( v31 )
        v33 = 2 * v31;
      else
        v33 = 1;
      for ( ; v33 < v32; v33 *= 2 )
        ;
      if ( v33 <= 2 )
        v33 = 2;
      if ( v33 - v32 > 0x10000 )
        v33 = v30 + 65537;
      if ( v33 != (_DWORD)v30 )
      {
        v34 = 8i64 * v33;
        if ( !is_mul_ok(v33, 8ui64) )
          v34 = -1i64;
        v35 = UFG::qMalloc(v34, "qArray.Add.activateSubSegments", 0i64);
        v36 = v35;
        if ( v4->p )
        {
          for ( k = 0i64; (unsigned int)k < v4->size; *(_QWORD *)&v35[v38 * 8] = v4->p[v38] )
          {
            v38 = k;
            k = (unsigned int)(k + 1);
          }
          operator delete[](v4->p);
        }
        v4->p = (UFG::RoadNetworkSubSegment **)v36;
        v4->capacity = v33;
      }
    }
    v39 = v4->p;
    v4->size = v32;
    v39[v30] = v26;
  }
  v40 = this->mPreviousVisibleSubSegments;
  this->mPreviousVisibleSubSegments = this->mCurrentVisibleSubSegments;
  this->mCurrentVisibleSubSegments = v40;
  v40->size = 0;
  mPreviousVisibleRoadNetwork = this->mPreviousVisibleRoadNetwork;
  this->mPreviousVisibleRoadNetwork = this->mCurrentVisibleRoadNetwork;
  this->mCurrentVisibleRoadNetwork = mPreviousVisibleRoadNetwork;
  mPreviousVisibleRoadNetwork->size = 0;
}

// File Line: 1150
// RVA: 0xD18B0
void __fastcall UFG::RoadNetworkVisibleArea::AddEdge(
        UFG::RoadNetworkVisibleArea *this,
        UFG::RoadNetworkSubSegment *currentSubSegment,
        UFG::RoadNetworkSubSegment *nextSubSegment,
        UFG::RoadNetworkGate *nextGate)
{
  char *v8; // rax

  v8 = UFG::qMalloc(0x100ui64, "RoadNetworkVisibleArea.RoadNetworkVisibleAreaEdge", 0i64);
  if ( v8 )
    UFG::RoadNetworkVisibleAreaEdge::RoadNetworkVisibleAreaEdge(
      (UFG::RoadNetworkVisibleAreaEdge *)v8,
      this,
      currentSubSegment,
      nextSubSegment,
      nextGate);
  UFG::DaemonManager::RegisterDaemon(&this->mEdgeManager, (UFG::RoadNetworkVisibleAreaEdge *)v8);
}

// File Line: 1165
// RVA: 0xD1840
void __fastcall UFG::RoadNetworkVisibleArea::AddEdge(
        UFG::RoadNetworkVisibleArea *this,
        UFG::RoadNetworkGate *gate,
        UFG::RoadNetworkVisibleAreaEdge *spawner)
{
  char *v6; // rax

  v6 = UFG::qMalloc(0x100ui64, "RoadNetworkVisibleArea.RoadNetworkVisibleAreaEdge", 0i64);
  if ( v6 )
    UFG::RoadNetworkVisibleAreaEdge::RoadNetworkVisibleAreaEdge(
      (UFG::RoadNetworkVisibleAreaEdge *)v6,
      gate,
      this,
      spawner);
  UFG::DaemonManager::RegisterDaemon(&this->mEdgeManager, (UFG::RoadNetworkVisibleAreaEdge *)v6);
}

// File Line: 1172
// RVA: 0xD3DF0
void __fastcall UFG::RoadNetworkVisibleArea::CreateEdges(
        UFG::RoadNetworkVisibleArea *this,
        UFG::RoadNetworkIntersection *intersection,
        UFG::RoadNetworkVisibleAreaEdge *spawner,
        UFG::RoadNetworkGate *spawnerGate)
{
  __int64 i; // rbp
  __int64 mOffset; // rax
  char *v10; // rcx
  __int64 v11; // rax
  UFG::RoadNetworkGate *v12; // rdi
  __int64 v13; // rax
  UFG::RoadNetworkSegment *v14; // rbx
  char v15; // si
  unsigned int mIndex; // edx
  UFG::qBaseTreeRB *v17; // rax
  __int64 v18; // rax
  UFG::RoadNetworkGate *v19; // rdx

  for ( i = 0i64; (unsigned int)i < (unsigned __int8)intersection->mNumGates; i = (unsigned int)(i + 1) )
  {
    mOffset = intersection->mGates.mOffset;
    if ( mOffset )
      v10 = (char *)&intersection->mGates + mOffset;
    else
      v10 = 0i64;
    v11 = *(_QWORD *)&v10[8 * i];
    if ( v11 )
      v12 = (UFG::RoadNetworkGate *)&v10[8 * i + v11];
    else
      v12 = 0i64;
    v13 = v12->mConnectedNode.mOffset;
    if ( v13 )
      v14 = (UFG::RoadNetworkSegment *)((char *)&v12->mConnectedNode + v13);
    else
      v14 = 0i64;
    if ( v12 != spawnerGate && v14 )
    {
      v15 = 0;
      if ( v14->mType.mValue == 1 )
      {
        mIndex = v14->mIndex;
        if ( mIndex )
          v17 = UFG::qBaseTreeRB::Get(&this->mVisitedIntersections.mTree.mTree, mIndex);
        else
          v17 = 0i64;
        v15 = v17 != 0i64;
      }
      if ( !v14->mType.mValue )
      {
        v18 = v12->mConnectedGate.mOffset;
        if ( v18 )
          v19 = (UFG::RoadNetworkGate *)((char *)&v12->mConnectedGate + v18);
        else
          v19 = 0i64;
        v15 |= UFG::RoadNetworkSegment::GetClosestSubSegment(v14, v19)->mActive != 0;
      }
      if ( !v15 )
        UFG::RoadNetworkVisibleArea::AddEdge(this, v12, spawner);
    }
  }
}

// File Line: 1206
// RVA: 0xD3A70
void __fastcall UFG::RoadNetworkVisibleArea::CreateEdges(
        UFG::RoadNetworkVisibleArea *this,
        UFG::RoadNetworkIntersection *intersection)
{
  __int64 i; // r15
  __int64 mOffset; // rax
  char *v6; // rcx
  char *v7; // rdx
  UFG::RoadNetworkGate *v8; // rbx
  __int64 v9; // rax
  char *v10; // rax
  UFG::RoadNetworkVisibleAreaEdge *v11; // rax
  UFG::RoadNetworkVisibleAreaEdge *v12; // r12
  __int64 size; // r14
  unsigned int v14; // esi
  unsigned int capacity; // ebx
  unsigned int v16; // ebx
  unsigned __int64 v17; // rax
  char *v18; // rax
  UFG::RoadNetworkVisibleAreaEdge **v19; // rbp
  __int64 j; // r9

  for ( i = 0i64; (unsigned int)i < (unsigned __int8)intersection->mNumGates; i = (unsigned int)(i + 1) )
  {
    mOffset = intersection->mGates.mOffset;
    if ( mOffset )
      v6 = (char *)&intersection->mGates + mOffset;
    else
      v6 = 0i64;
    v7 = &v6[8 * i];
    if ( *(_QWORD *)v7 )
      v8 = (UFG::RoadNetworkGate *)&v7[*(_QWORD *)v7];
    else
      v8 = 0i64;
    v9 = v8->mConnectedNode.mOffset;
    if ( v9 && (UFG::qOffset64<UFG::RoadNetworkNode *> *)((char *)&v8->mConnectedNode + v9) )
    {
      v10 = UFG::qMalloc(0x100ui64, "RoadNetworkVisibleArea.RoadNetworkVisibleAreaEdge", 0i64);
      if ( v10 )
      {
        UFG::RoadNetworkVisibleAreaEdge::RoadNetworkVisibleAreaEdge((UFG::RoadNetworkVisibleAreaEdge *)v10, this, v8);
        v12 = v11;
      }
      else
      {
        v12 = 0i64;
      }
      size = this->mEdgeManager.mEdgeCollection.size;
      v14 = size + 1;
      capacity = this->mEdgeManager.mEdgeCollection.capacity;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v16 = 2 * capacity;
        else
          v16 = 1;
        for ( ; v16 < v14; v16 *= 2 )
          ;
        if ( v16 <= 2 )
          v16 = 2;
        if ( v16 - v14 > 0x10000 )
          v16 = size + 65537;
        if ( v16 != (_DWORD)size )
        {
          v17 = 8i64 * v16;
          if ( !is_mul_ok(v16, 8ui64) )
            v17 = -1i64;
          v18 = UFG::qMalloc(v17, "qArray.Add", 0i64);
          v19 = (UFG::RoadNetworkVisibleAreaEdge **)v18;
          if ( this->mEdgeManager.mEdgeCollection.p )
          {
            for ( j = 0i64; (unsigned int)j < this->mEdgeManager.mEdgeCollection.size; j = (unsigned int)(j + 1) )
              *(_QWORD *)&v18[8 * j] = this->mEdgeManager.mEdgeCollection.p[j];
            operator delete[](this->mEdgeManager.mEdgeCollection.p);
          }
          this->mEdgeManager.mEdgeCollection.p = v19;
          this->mEdgeManager.mEdgeCollection.capacity = v16;
        }
      }
      this->mEdgeManager.mEdgeCollection.size = v14;
      this->mEdgeManager.mEdgeCollection.p[size] = v12;
    }
  }
}

// File Line: 1225
// RVA: 0xD3C40
void __fastcall UFG::RoadNetworkVisibleArea::CreateEdges(
        UFG::RoadNetworkVisibleArea *this,
        UFG::RoadNetworkSubSegment *subSegment)
{
  UFG::RoadNetworkSegment *mParentNode; // r8
  UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0> *p_mSubSegmentCollection; // r14
  UFG::RoadNetworkSubSegment *mPrev; // rsi
  UFG::RoadNetworkGate *v7; // rbx
  __int64 mOffset; // rax
  _QWORD *v9; // rcx
  UFG::RoadNetworkGate *v10; // r9
  char *v11; // rcx
  __int64 v12; // rax
  __int64 v13; // rax
  UFG::RoadNetworkGate **p; // r15
  UFG::RoadNetworkGate *v15; // r9
  __int64 v16; // rax
  UFG::RoadNetworkGate **v17; // rsi
  UFG::RoadNetworkGate *v18; // r9
  __int64 v19; // rax
  UFG::qArray<UFG::RoadNetworkGate *,0> gateCollection; // [rsp+28h] [rbp-30h] BYREF

  mParentNode = subSegment->mParentNode;
  p_mSubSegmentCollection = &mParentNode->mSubSegmentCollection;
  mPrev = (UFG::RoadNetworkSubSegment *)subSegment->mPrev;
  v7 = 0i64;
  if ( (UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0> *)subSegment->mNext == &mParentNode->mSubSegmentCollection )
  {
    if ( mPrev == (UFG::RoadNetworkSubSegment *)p_mSubSegmentCollection )
    {
      mOffset = mParentNode->mGates.mOffset;
      if ( mOffset )
        v9 = (__int64 *)((char *)&mParentNode->mGates.mOffset + mOffset);
      else
        v9 = 0i64;
      v10 = (UFG::RoadNetworkGate *)((char *)v9 + *v9);
      if ( !*v9 )
        v10 = 0i64;
      if ( mOffset )
        v11 = (char *)&mParentNode->mGates + mOffset;
      else
        v11 = 0i64;
      v12 = *((_QWORD *)v11 + 1);
      if ( v12 )
        v7 = (UFG::RoadNetworkGate *)&v11[v12 + 8];
      v13 = v10->mConnectedNode.mOffset;
      if ( v13 )
      {
        if ( (UFG::qOffset64<UFG::RoadNetworkNode *> *)((char *)&v10->mConnectedNode + v13) )
          UFG::RoadNetworkVisibleArea::AddEdge(this, subSegment, 0i64, v10);
      }
      UFG::RoadNetworkVisibleArea::AddEdge(this, subSegment, 0i64, v7);
      return;
    }
    gateCollection.p = 0i64;
    *(_QWORD *)&gateCollection.size = 0i64;
    UFG::RoadNetworkSubSegment::GetGatesConnectedToSubSegment(subSegment, &gateCollection);
    p = gateCollection.p;
    v15 = *gateCollection.p;
    v16 = (*gateCollection.p)->mConnectedNode.mOffset;
    if ( v16 && (UFG::qOffset64<UFG::RoadNetworkNode *> *)((char *)&v15->mConnectedNode + v16) )
      UFG::RoadNetworkVisibleArea::AddEdge(this, subSegment, 0i64, v15);
    operator delete[](p);
    gateCollection.p = 0i64;
    *(_QWORD *)&gateCollection.size = 0i64;
  }
  else
  {
    UFG::RoadNetworkVisibleArea::AddEdge(this, subSegment, (UFG::RoadNetworkSubSegment *)subSegment->mNext, 0i64);
  }
  if ( mPrev == (UFG::RoadNetworkSubSegment *)p_mSubSegmentCollection )
  {
    gateCollection.p = 0i64;
    *(_QWORD *)&gateCollection.size = 0i64;
    UFG::RoadNetworkSubSegment::GetGatesConnectedToSubSegment(subSegment, &gateCollection);
    v17 = gateCollection.p;
    v18 = *gateCollection.p;
    v19 = (*gateCollection.p)->mConnectedNode.mOffset;
    if ( v19 && (UFG::qOffset64<UFG::RoadNetworkNode *> *)((char *)&v18->mConnectedNode + v19) )
      UFG::RoadNetworkVisibleArea::AddEdge(this, subSegment, 0i64, v18);
    operator delete[](v17);
  }
  else
  {
    UFG::RoadNetworkVisibleArea::AddEdge(this, subSegment, mPrev, 0i64);
  }
}

// File Line: 1293
// RVA: 0xD89C0
UFG::RoadNetworkGate *__fastcall UFG::RoadNetworkVisibleArea::GetFirstValidGate(
        UFG::RoadNetworkVisibleArea *this,
        UFG::RoadNetworkIntersection *intersection)
{
  __int64 v2; // rbp
  __int64 mOffset; // rax
  char *v6; // rcx
  __int64 v7; // rax
  __int64 v8; // rsi
  __int64 v9; // rax
  UFG::RoadNetworkSegment *v10; // rbx
  char v11; // di
  unsigned int mIndex; // edx
  UFG::qBaseTreeRB *v13; // rax
  __int64 v14; // rax
  UFG::RoadNetworkGate *v15; // rdx

  v2 = 0i64;
  if ( !intersection->mNumGates )
    return 0i64;
  while ( 1 )
  {
    mOffset = intersection->mGates.mOffset;
    v6 = mOffset ? (char *)&intersection->mGates + mOffset : 0i64;
    v7 = *(_QWORD *)&v6[8 * v2];
    v8 = v7 ? (__int64)&v6[8 * v2 + v7] : 0i64;
    v9 = *(_QWORD *)(v8 + 8);
    if ( v9 )
    {
      v10 = (UFG::RoadNetworkSegment *)(v9 + v8 + 8);
      if ( v10 )
      {
        v11 = 0;
        if ( v10->mType.mValue == 1 )
        {
          mIndex = v10->mIndex;
          if ( mIndex )
            v13 = UFG::qBaseTreeRB::Get(&this->mVisitedIntersections.mTree.mTree, mIndex);
          else
            v13 = 0i64;
          v11 = v13 != 0i64;
        }
        if ( !v10->mType.mValue )
        {
          v14 = *(_QWORD *)(v8 + 16);
          if ( v14 )
            v15 = (UFG::RoadNetworkGate *)(v14 + v8 + 16);
          else
            v15 = 0i64;
          v11 |= UFG::RoadNetworkSegment::GetClosestSubSegment(v10, v15)->mActive != 0;
        }
        if ( !v11 )
          break;
      }
    }
    v2 = (unsigned int)(v2 + 1);
    if ( (unsigned int)v2 >= (unsigned __int8)intersection->mNumGates )
      return 0i64;
  }
  return (UFG::RoadNetworkGate *)v8;
}

// File Line: 1392
// RVA: 0xD36E0
void __fastcall UFG::RoadNetworkVisibleArea::ClaimSubSegmentVisited(
        UFG::RoadNetworkVisibleArea *this,
        UFG::RoadNetworkSubSegment *subSegment)
{
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *mCurrentVisibleSubSegments; // rdi
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::RoadNetworkSubSegment **p; // rax

  if ( subSegment->mActive <= 1u )
  {
    mCurrentVisibleSubSegments = this->mCurrentVisibleSubSegments;
    size = mCurrentVisibleSubSegments->size;
    capacity = mCurrentVisibleSubSegments->capacity;
    v6 = size + 1;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v7 = 2 * capacity;
      else
        v7 = 1;
      for ( ; v7 < v6; v7 *= 2 )
        ;
      if ( v7 <= 2 )
        v7 = 2;
      if ( v7 - v6 > 0x10000 )
        v7 = size + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)this->mCurrentVisibleSubSegments,
        v7,
        "qArray.Add");
    }
    p = mCurrentVisibleSubSegments->p;
    mCurrentVisibleSubSegments->size = v6;
    p[size] = subSegment;
  }
}

// File Line: 1401
// RVA: 0xD5750
void __fastcall UFG::RoadNetworkVisibleArea::FirstSpawnPoint(UFG::RoadNetworkVisibleArea *this)
{
  this->mEdgeManager.mSpawnPointIterator->vfptr->First(this->mEdgeManager.mSpawnPointIterator);
}

// File Line: 1407
// RVA: 0xDF7C0
__int64 __fastcall UFG::RoadNetworkVisibleArea::NoMoreSpawnPoints(UFG::RoadNetworkVisibleArea *this)
{
  return ((__int64 (__fastcall *)(UFG::SpawnPointIterator *))this->mEdgeManager.mSpawnPointIterator->vfptr->IsDone)(this->mEdgeManager.mSpawnPointIterator);
}

// File Line: 1413
// RVA: 0xDF7B0
void __fastcall UFG::RoadNetworkVisibleArea::NextSpawnPoint(UFG::RoadNetworkVisibleArea *this)
{
  this->mEdgeManager.mSpawnPointIterator->vfptr->Next(this->mEdgeManager.mSpawnPointIterator);
}

// File Line: 1419
// RVA: 0xD85E0
UFG::RoadNetworkSpawnPoint *__fastcall UFG::RoadNetworkVisibleArea::GetCurrentEdgeSpawnPoint(
        UFG::RoadNetworkVisibleArea *this)
{
  return &this->mEdgeManager.mSpawnPointIterator->mCollection->p[this->mEdgeManager.mSpawnPointIterator->mCurrentIndex]->mSpawnPoint[this->mEdgeManager.mSpawnPointIterator->mSpawnPointIndex];
}

// File Line: 1450
// RVA: 0xD09C0
void __fastcall UFG::RoadNetworkVisibleAreaEdgeManager::RoadNetworkVisibleAreaEdgeManager(
        UFG::RoadNetworkVisibleAreaEdgeManager *this)
{
  UFG::EdgeStepIterator *v2; // rax
  UFG::OuterEdgeIterator *v3; // rax
  UFG::SpawnPointIterator *v4; // rax

  this->mEdgeCollection.p = 0i64;
  *(_QWORD *)&this->mEdgeCollection.size = 0i64;
  v2 = (UFG::EdgeStepIterator *)UFG::qMalloc(0x20ui64, "RoadNetworkVisibleAreaEdgeManager::EdgeStepIterator", 0i64);
  if ( v2 )
  {
    v2->vfptr = (UFG::EdgeIteratorVtbl *)&UFG::EdgeIterator::`vftable;
    v2->mCollection = &this->mEdgeCollection;
    v2->vfptr = (UFG::EdgeIteratorVtbl *)&UFG::EdgeStepIterator::`vftable;
    v2->mEndOfStep = -1;
    v2->mCurrentIndex = -1;
  }
  else
  {
    v2 = 0i64;
  }
  this->mStepIterator = v2;
  v3 = (UFG::OuterEdgeIterator *)UFG::qMalloc(0x20ui64, "RoadNetworkVisibleAreaEdgeManager::OuterEdgeIterator", 0i64);
  if ( v3 )
  {
    v3->vfptr = (UFG::EdgeIteratorVtbl *)&UFG::EdgeIterator::`vftable;
    v3->mCollection = &this->mEdgeCollection;
    v3->vfptr = (UFG::EdgeIteratorVtbl *)&UFG::EdgeStepIterator::`vftable;
    v3->mEndOfStep = -1;
    v3->mCurrentIndex = -1;
    v3->vfptr = (UFG::EdgeIteratorVtbl *)&UFG::OuterEdgeIterator::`vftable;
  }
  else
  {
    v3 = 0i64;
  }
  this->mOuterEdgeIterator = v3;
  v4 = (UFG::SpawnPointIterator *)UFG::qMalloc(0x20ui64, "RoadNetworkVisibleAreaEdgeManager::SpawnPointIterator", 0i64);
  if ( v4 )
  {
    v4->vfptr = (UFG::EdgeIteratorVtbl *)&UFG::EdgeIterator::`vftable;
    v4->mCollection = &this->mEdgeCollection;
    v4->vfptr = (UFG::EdgeIteratorVtbl *)&UFG::SpawnPointIterator::`vftable;
    v4->mSpawnPointIndex = 0;
  }
  else
  {
    v4 = 0i64;
  }
  this->mSpawnPointIterator = v4;
}

// File Line: 1456
// RVA: 0xD1180
void __fastcall UFG::RoadNetworkVisibleAreaEdgeManager::~RoadNetworkVisibleAreaEdgeManager(
        UFG::RoadNetworkVisibleAreaEdgeManager *this)
{
  UFG::EdgeStepIterator *mStepIterator; // rcx
  UFG::OuterEdgeIterator *mOuterEdgeIterator; // rcx
  UFG::SpawnPointIterator *mSpawnPointIterator; // rcx
  UFG::RoadNetworkVisibleAreaEdge **p; // rcx

  mStepIterator = this->mStepIterator;
  if ( mStepIterator )
    mStepIterator->vfptr->__vecDelDtor(mStepIterator, 1u);
  mOuterEdgeIterator = this->mOuterEdgeIterator;
  if ( mOuterEdgeIterator )
    mOuterEdgeIterator->vfptr->__vecDelDtor(mOuterEdgeIterator, 1u);
  mSpawnPointIterator = this->mSpawnPointIterator;
  if ( mSpawnPointIterator )
    mSpawnPointIterator->vfptr->__vecDelDtor(mSpawnPointIterator, 1u);
  p = this->mEdgeCollection.p;
  if ( p )
    operator delete[](p);
  this->mEdgeCollection.p = 0i64;
  *(_QWORD *)&this->mEdgeCollection.size = 0i64;
}

// File Line: 1467
// RVA: 0xD3770
void __fastcall UFG::RoadNetworkVisibleAreaEdgeManager::Clear(UFG::RoadNetworkVisibleAreaEdgeManager *this)
{
  unsigned int i; // edi
  unsigned __int64 v3; // r14
  UFG::RoadNetworkVisibleAreaEdge **p; // rax
  UFG::RoadNetworkVisibleAreaEdge *v5; // rsi
  UFG::RoadNetworkVisibleAreaEdge **v6; // rcx

  for ( i = 0; i < this->mEdgeCollection.size; this->mEdgeCollection.p[v3] = 0i64 )
  {
    v3 = i;
    p = this->mEdgeCollection.p;
    v5 = p[v3];
    if ( v5 )
    {
      UFG::RoadNetworkVisibleAreaEdge::~RoadNetworkVisibleAreaEdge(p[v3]);
      operator delete[](v5);
    }
    ++i;
  }
  v6 = this->mEdgeCollection.p;
  if ( v6 )
    operator delete[](v6);
  this->mEdgeCollection.p = 0i64;
  *(_QWORD *)&this->mEdgeCollection.size = 0i64;
}

// File Line: 1480
// RVA: 0xD4900
char __fastcall UFG::RoadNetworkVisibleAreaEdgeManager::ExpandOneStep(UFG::RoadNetworkVisibleAreaEdgeManager *this)
{
  UFG::RoadNetworkVisibleAreaEdge *v3; // rcx

  this->mStepIterator->vfptr->First(this->mStepIterator);
  if ( this->mStepIterator->vfptr->IsDone(this->mStepIterator) )
  {
    this->mOuterEdgeIterator->vfptr->First(this->mOuterEdgeIterator);
    while ( !this->mOuterEdgeIterator->vfptr->IsDone(this->mOuterEdgeIterator) )
    {
      v3 = this->mOuterEdgeIterator->mCollection->p[this->mOuterEdgeIterator->mCurrentIndex];
      if ( !v3->mNumSpawnPoints )
        UFG::RoadNetworkVisibleAreaEdge::AttachSpawnPoints(v3);
      this->mOuterEdgeIterator->vfptr->Next(this->mOuterEdgeIterator);
    }
    return 1;
  }
  else
  {
    do
    {
      UFG::RoadNetworkVisibleAreaEdge::ExpandOneStep(this->mStepIterator->mCollection->p[this->mStepIterator->mCurrentIndex]);
      this->mStepIterator->vfptr->Next(this->mStepIterator);
    }
    while ( !this->mStepIterator->vfptr->IsDone(this->mStepIterator) );
    return 0;
  }
}

// File Line: 1531
// RVA: 0xD0C90
void __fastcall UFG::EdgeStepIterator::~EdgeStepIterator(UFG::EdgeStepIterator *this)
{
  this->vfptr = (UFG::EdgeIteratorVtbl *)&UFG::EdgeStepIterator::`vftable;
  this->vfptr = (UFG::EdgeIteratorVtbl *)&UFG::EdgeIterator::`vftable;
}

// File Line: 1535
// RVA: 0xD5670
void __fastcall UFG::EdgeStepIterator::First(UFG::EdgeStepIterator *this)
{
  UFG::qArray<UFG::RoadNetworkVisibleAreaEdge *,0> *mCollection; // rax
  __int64 v2; // rbx
  unsigned int size; // edx

  mCollection = this->mCollection;
  this->mCurrentIndex = -1;
  v2 = 0i64;
  size = mCollection->size;
  this->mEndOfStep = mCollection->size;
  if ( size )
  {
    while ( !this->vfptr[1].__vecDelDtor(this, this->mCollection->p[v2]) )
    {
      v2 = (unsigned int)(v2 + 1);
      if ( (unsigned int)v2 >= this->mEndOfStep )
        return;
    }
    this->mCurrentIndex = v2;
  }
}

// File Line: 1552
// RVA: 0xDF6A0
void __fastcall UFG::EdgeStepIterator::Next(UFG::EdgeStepIterator *this)
{
  unsigned int mCurrentIndex; // ebx
  __int64 v3; // rbx

  mCurrentIndex = this->mCurrentIndex;
  if ( mCurrentIndex != -1 )
  {
    v3 = mCurrentIndex + 1;
    this->mCurrentIndex = -1;
    if ( (unsigned int)v3 < this->mEndOfStep )
    {
      while ( !this->vfptr[1].__vecDelDtor(this, this->mCollection->p[v3]) )
      {
        v3 = (unsigned int)(v3 + 1);
        if ( (unsigned int)v3 >= this->mEndOfStep )
          return;
      }
      this->mCurrentIndex = v3;
    }
  }
}

// File Line: 1571
// RVA: 0xDE460
__int64 __fastcall UFG::EdgeStepIterator::IsDone(UFG::EdgeStepIterator *this)
{
  return (this->mCurrentIndex == -1) | (unsigned int)(this->mCurrentIndex == this->mEndOfStep);
}

// File Line: 1580
// RVA: 0xDEE10
bool __fastcall UFG::EdgeStepIterator::IsValid(UFG::EdgeStepIterator *this, UFG::RoadNetworkVisibleAreaEdge *edge)
{
  return !edge->mComplete;
}

// File Line: 1594
// RVA: 0xDEE20
bool __fastcall UFG::OuterEdgeIterator::IsValid(UFG::OuterEdgeIterator *this, UFG::RoadNetworkVisibleAreaEdge *edge)
{
  return UFG::RoadNetworkVisibleAreaEdge::IsOuterEdge(edge);
}

// File Line: 1605
// RVA: 0xD56E0
void __fastcall UFG::SpawnPointIterator::First(UFG::SpawnPointIterator *this)
{
  UFG::qArray<UFG::RoadNetworkVisibleAreaEdge *,0> *mCollection; // rax
  __int64 v2; // rbx

  mCollection = this->mCollection;
  v2 = 0i64;
  this->mCurrentIndex = -1;
  if ( mCollection->size )
  {
    while ( !this->vfptr[1].__vecDelDtor(this, this->mCollection->p[v2]) )
    {
      v2 = (unsigned int)(v2 + 1);
      if ( (unsigned int)v2 >= this->mCollection->size )
        return;
    }
    this->mSpawnPointIndex = 0;
    this->mCurrentIndex = v2;
  }
}

// File Line: 1619
// RVA: 0xDF710
void __fastcall UFG::SpawnPointIterator::Next(UFG::SpawnPointIterator *this)
{
  __int64 mCurrentIndex; // rbx
  UFG::qArray<UFG::RoadNetworkVisibleAreaEdge *,0> *mCollection; // r8
  unsigned int mSpawnPointIndex; // ecx
  __int64 v5; // rbx

  mCurrentIndex = this->mCurrentIndex;
  if ( (_DWORD)mCurrentIndex != -1 )
  {
    mCollection = this->mCollection;
    mSpawnPointIndex = this->mSpawnPointIndex;
    if ( mSpawnPointIndex >= mCollection->p[mCurrentIndex]->mNumSpawnPoints - 1 )
    {
      v5 = (unsigned int)(mCurrentIndex + 1);
      this->mCurrentIndex = -1;
      if ( (unsigned int)v5 < mCollection->size )
      {
        while ( !this->vfptr[1].__vecDelDtor(this, this->mCollection->p[v5]) )
        {
          v5 = (unsigned int)(v5 + 1);
          if ( (unsigned int)v5 >= this->mCollection->size )
            return;
        }
        this->mSpawnPointIndex = 0;
        this->mCurrentIndex = v5;
      }
    }
    else
    {
      this->mSpawnPointIndex = mSpawnPointIndex + 1;
    }
  }
}

// File Line: 1648
// RVA: 0xDE480
__int64 __fastcall UFG::SpawnPointIterator::IsDone(UFG::SpawnPointIterator *this)
{
  return (this->mCurrentIndex == -1) | (unsigned int)(this->mCurrentIndex == this->mCollection->size);
}

// File Line: 1655
// RVA: 0xDEE40
_BOOL8 __fastcall UFG::SpawnPointIterator::IsValid(
        UFG::SpawnPointIterator *this,
        UFG::RoadNetworkVisibleAreaEdge *edge)
{
  return edge->mNumSpawnPoints != 0;
}

// File Line: 1685
// RVA: 0xD06E0
void __fastcall UFG::RoadNetworkVisibleAreaEdge::RoadNetworkVisibleAreaEdge(
        UFG::RoadNetworkVisibleAreaEdge *this,
        UFG::RoadNetworkVisibleArea *visibleArea,
        UFG::RoadNetworkGate *startingGate)
{
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::RoadNetworkGate *mPreviousGate; // rbx
  __int64 mOffset; // rax
  UFG::RoadNetworkSegment *v9; // rcx
  __int64 v10; // rax
  UFG::RoadNetworkGate *v11; // rdx
  UFG::RoadNetworkNode *v12; // rdx

  this->mPrev = this;
  this->mNext = this;
  this->mVisibleArea = visibleArea;
  `eh vector constructor iterator(
    this->mSpawnPoint,
    0x18ui64,
    6,
    (void (__fastcall *)(void *))UFG::RoadNetworkSpawnPoint::RoadNetworkSpawnPoint);
  this->mT = -1.0;
  this->mComplete = 0;
  this->mNumSpawnPoints = 0;
  this->mNodesToStart.p = 0i64;
  *(_QWORD *)&this->mNodesToStart.size = 0i64;
  this->mCurrentSubSegment = 0i64;
  this->mNextSubSegment = 0i64;
  this->mPreviousSubSegment = 0i64;
  this->mNextGate = 0i64;
  this->mPreviousGate = startingGate;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mDirection.x = UFG::qVector3::msZero.x;
  this->mDirection.y = y;
  this->mDirection.z = z;
  mPreviousGate = this->mPreviousGate;
  if ( mPreviousGate )
  {
    mOffset = mPreviousGate->mConnectedNode.mOffset;
    if ( mOffset )
      v9 = (UFG::RoadNetworkSegment *)((char *)&mPreviousGate->mConnectedNode + mOffset);
    else
      v9 = 0i64;
    v10 = mPreviousGate->mConnectedGate.mOffset;
    if ( v10 )
      v11 = (UFG::RoadNetworkGate *)((char *)&mPreviousGate->mConnectedGate + v10);
    else
      v11 = 0i64;
    this->mCurrentSubSegment = UFG::RoadNetworkSegment::GetClosestSubSegment(v9, v11);
  }
  v12 = (UFG::RoadNetworkNode *)((char *)mPreviousGate + mPreviousGate->mNode.mOffset);
  if ( !mPreviousGate->mNode.mOffset )
    v12 = 0i64;
  UFG::RoadNetworkVisibleAreaEdge::AddNodeToPath(this, v12);
  this->mNextSubSegment = UFG::RoadNetworkVisibleAreaEdge::GetNextSubSegment(this);
  ++this->mCurrentSubSegment->mActive;
  UFG::RoadNetworkVisibleAreaEdge::AddNodeToPath(this, this->mCurrentSubSegment->mParentNode);
  UFG::RoadNetworkVisibleAreaEdge::UpdateDirection(this);
  UFG::RoadNetworkVisibleAreaEdge::RefreshT(this);
  UFG::RoadNetworkVisibleArea::ClaimSubSegmentVisited(this->mVisibleArea, this->mCurrentSubSegment);
  this->mNextGate = 0i64;
  this->mPreviousGate = 0i64;
}

// File Line: 1710
// RVA: 0xD05B0
void __fastcall UFG::RoadNetworkVisibleAreaEdge::RoadNetworkVisibleAreaEdge(
        UFG::RoadNetworkVisibleAreaEdge *this,
        UFG::RoadNetworkGate *startingGate,
        UFG::RoadNetworkVisibleArea *visibleArea,
        UFG::RoadNetworkVisibleAreaEdge *spawner)
{
  UFG::RoadNetworkGate *v7; // rdx
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::RoadNetworkGate *mPreviousGate; // rax
  __int64 mOffset; // rcx
  UFG::RoadNetworkSegment *v12; // r8
  __int64 v13; // rcx

  this->mPrev = this;
  this->mNext = this;
  this->mVisibleArea = visibleArea;
  `eh vector constructor iterator(
    this->mSpawnPoint,
    0x18ui64,
    6,
    (void (__fastcall *)(void *))UFG::RoadNetworkSpawnPoint::RoadNetworkSpawnPoint);
  this->mT = -1.0;
  this->mComplete = 0;
  v7 = 0i64;
  this->mNumSpawnPoints = 0;
  this->mNodesToStart.p = 0i64;
  *(_QWORD *)&this->mNodesToStart.size = 0i64;
  this->mCurrentSubSegment = 0i64;
  this->mNextSubSegment = 0i64;
  this->mPreviousSubSegment = 0i64;
  this->mNextGate = 0i64;
  this->mPreviousGate = startingGate;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mDirection.x = UFG::qVector3::msZero.x;
  this->mDirection.y = y;
  this->mDirection.z = z;
  mPreviousGate = this->mPreviousGate;
  if ( mPreviousGate )
  {
    mOffset = mPreviousGate->mConnectedNode.mOffset;
    if ( mOffset )
      v12 = (UFG::RoadNetworkSegment *)((char *)&mPreviousGate->mConnectedNode + mOffset);
    else
      v12 = 0i64;
    v13 = mPreviousGate->mConnectedGate.mOffset;
    if ( v13 )
      v7 = (UFG::RoadNetworkGate *)((char *)&mPreviousGate->mConnectedGate + v13);
    this->mCurrentSubSegment = UFG::RoadNetworkSegment::GetClosestSubSegment(v12, v7);
  }
  UFG::RoadNetworkVisibleAreaEdge::Init(this, spawner);
}

// File Line: 1727
// RVA: 0xD0880
void __fastcall UFG::RoadNetworkVisibleAreaEdge::RoadNetworkVisibleAreaEdge(
        UFG::RoadNetworkVisibleAreaEdge *this,
        UFG::RoadNetworkVisibleArea *visibleArea,
        UFG::RoadNetworkSubSegment *current,
        UFG::RoadNetworkSubSegment *next,
        UFG::RoadNetworkGate *nextGate)
{
  float y; // xmm1_4
  float z; // xmm2_4

  this->mPrev = this;
  this->mNext = this;
  this->mVisibleArea = visibleArea;
  `eh vector constructor iterator(
    this->mSpawnPoint,
    0x18ui64,
    6,
    (void (__fastcall *)(void *))UFG::RoadNetworkSpawnPoint::RoadNetworkSpawnPoint);
  this->mT = -1.0;
  this->mComplete = 0;
  this->mNumSpawnPoints = 0;
  this->mNodesToStart.p = 0i64;
  *(_QWORD *)&this->mNodesToStart.size = 0i64;
  this->mCurrentSubSegment = current;
  this->mNextSubSegment = next;
  this->mPreviousSubSegment = 0i64;
  this->mNextGate = nextGate;
  this->mPreviousGate = 0i64;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mDirection.x = UFG::qVector3::msZero.x;
  this->mDirection.y = y;
  this->mDirection.z = z;
  ++this->mCurrentSubSegment->mActive;
  UFG::RoadNetworkVisibleAreaEdge::AddNodeToPath(this, this->mCurrentSubSegment->mParentNode);
  UFG::RoadNetworkVisibleAreaEdge::UpdateDirection(this);
  UFG::RoadNetworkVisibleAreaEdge::RefreshT(this);
  UFG::RoadNetworkVisibleArea::ClaimSubSegmentVisited(this->mVisibleArea, this->mCurrentSubSegment);
  this->mNextGate = 0i64;
  this->mPreviousGate = 0i64;
}

// File Line: 1733
// RVA: 0xD10B0
void __fastcall UFG::RoadNetworkVisibleAreaEdge::~RoadNetworkVisibleAreaEdge(UFG::RoadNetworkVisibleAreaEdge *this)
{
  unsigned int i; // edx
  UFG::RoadNetworkLane *mLane; // rax
  UFG::RoadNetworkSubSegment *mSubSegment; // rax
  UFG::RoadNetworkNode **p; // rcx
  UFG::qNode<UFG::RoadNetworkVisibleAreaEdge,UFG::RoadNetworkVisibleAreaEdge> *mPrev; // rcx
  UFG::qNode<UFG::RoadNetworkVisibleAreaEdge,UFG::RoadNetworkVisibleAreaEdge> *mNext; // rax

  for ( i = 0; i < this->mNumSpawnPoints; ++i )
  {
    mLane = this->mSpawnPoint[i].mLane;
    if ( mLane )
    {
      mLane->mSpawnPoint = 0i64;
      mLane->mSpawnT = 0.0;
      mSubSegment = this->mSpawnPoint[i].mSubSegment;
      --mSubSegment->mNumSpawnPoints;
      this->mSpawnPoint[i].mSubSegment = 0i64;
      this->mSpawnPoint[i].mLane = 0i64;
      *(_QWORD *)&this->mSpawnPoint[i].mSpawnTime = 0i64;
    }
  }
  p = this->mNodesToStart.p;
  if ( p )
    operator delete[](p);
  this->mNodesToStart.p = 0i64;
  *(_QWORD *)&this->mNodesToStart.size = 0i64;
  `eh vector destructor iterator(this->mSpawnPoint, 0x18ui64, 6, (void (__fastcall *)(void *))_);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 1773
// RVA: 0xDD070
void __fastcall UFG::RoadNetworkVisibleAreaEdge::Init(
        UFG::RoadNetworkVisibleAreaEdge *this,
        UFG::RoadNetworkVisibleAreaEdge *spawner)
{
  if ( spawner )
  {
    UFG::qArray<UFG::qPropertySet *,0>::Clone(&spawner->mNodesToStart, &this->mNodesToStart);
    this->mNextSubSegment = UFG::RoadNetworkVisibleAreaEdge::GetNextSubSegment(this);
  }
  ++this->mCurrentSubSegment->mActive;
  UFG::RoadNetworkVisibleAreaEdge::AddNodeToPath(this, (Render::VerletCloth *)this->mCurrentSubSegment->mParentNode);
  UFG::RoadNetworkVisibleAreaEdge::UpdateDirection(this);
  UFG::RoadNetworkVisibleAreaEdge::RefreshT(this);
  UFG::RoadNetworkVisibleArea::ClaimSubSegmentVisited(this->mVisibleArea, this->mCurrentSubSegment);
  this->mNextGate = 0i64;
  this->mPreviousGate = 0i64;
}

// File Line: 1789
// RVA: 0xD8610
UFG::qVector3 *__fastcall UFG::RoadNetworkVisibleAreaEdge::GetCurrentPosition(
        UFG::RoadNetworkVisibleAreaEdge *this,
        UFG::qVector3 *result)
{
  UFG::RoadNetworkSegment *mParentNode; // r9
  UFG::RoadNetworkConnection *v5; // rcx
  __int64 mOffset; // r8
  char *v7; // rdx
  char *v8; // r10
  char *v9; // rax
  float mT; // xmm6_4
  __int64 v11; // r10
  char *v12; // rdx
  __int64 v13; // rax
  char *v14; // rdi
  char *v15; // rax
  __int64 v16; // rdx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v19; // rax
  UFG::qVector3 *v20; // rax
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-28h] BYREF
  float splineT; // [rsp+50h] [rbp+8h] BYREF

  mParentNode = this->mCurrentSubSegment->mParentNode;
  v5 = 0i64;
  mOffset = mParentNode->mLane.mOffset;
  if ( mOffset )
    v7 = (char *)&mParentNode->mLane + mOffset;
  else
    v7 = 0i64;
  v8 = &v7[8 * (((unsigned __int8)mParentNode->mNumLanes - 1) / 2)];
  if ( *(_QWORD *)v8 )
    v9 = &v8[*(_QWORD *)v8];
  else
    v9 = 0i64;
  mT = this->mT;
  v11 = *((unsigned __int16 *)v9 + 18);
  if ( mOffset )
    v12 = (char *)&mParentNode->mLane + mOffset;
  else
    v12 = 0i64;
  v13 = *(_QWORD *)&v12[8 * v11];
  v14 = &v12[8 * v11 + v13];
  if ( !v13 )
    v14 = 0i64;
  if ( *(_QWORD *)v14 )
    v15 = &v14[*(_QWORD *)v14];
  else
    v15 = 0i64;
  v16 = *((_QWORD *)v15 + 4);
  if ( v16 )
    v5 = (UFG::RoadNetworkConnection *)&v15[v16 + 32];
  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v5, *((unsigned __int16 *)v14 + 19));
  SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, mT, &splineT);
  v19 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                         (UFG::RoadNetworkConnection *)Path,
                                         SplineParameters);
  UFG::RoadNetworkLane::GetOffsetPos(&resulta, v19, splineT, *((float *)v14 + 10));
  v20 = result;
  y = resulta.y;
  result->x = resulta.x;
  z = resulta.z;
  result->y = y;
  result->z = z;
  return v20;
}

// File Line: 1812
// RVA: 0xD4710
void __fastcall UFG::RoadNetworkVisibleAreaEdge::ExpandOneStep(UFG::RoadNetworkVisibleAreaEdge *this)
{
  UFG::RoadNetworkSegment *v2; // rbx
  unsigned int i; // edx
  UFG::RoadNetworkLane *mLane; // rax
  UFG::RoadNetworkSubSegment *mSubSegment; // rax
  UFG::RoadNetworkSubSegment *NextSubSegment; // rax
  UFG::RoadNetworkSubSegment *v7; // rsi
  UFG::RoadNetworkGate *NextGate; // rbp
  __int64 mOffset; // rax
  UFG::RoadNetworkSegment *v10; // rsi
  UFG::RoadNetworkSubSegment *ClosestSubSegment; // rax
  UFG::RoadNetworkGate *FirstValidGate; // rax
  UFG::RoadNetworkGate *v13; // rbp
  __int64 v14; // rax
  UFG::RoadNetworkSubSegment *v15; // rbx
  UFG::qVector3 result; // [rsp+20h] [rbp-28h] BYREF
  UFG::qVector3 position; // [rsp+30h] [rbp-18h] BYREF

  if ( !this->mComplete )
  {
    v2 = 0i64;
    for ( i = 0; i < this->mNumSpawnPoints; ++i )
    {
      mLane = this->mSpawnPoint[i].mLane;
      if ( mLane )
      {
        mLane->mSpawnPoint = 0i64;
        mLane->mSpawnT = 0.0;
        mSubSegment = this->mSpawnPoint[i].mSubSegment;
        --mSubSegment->mNumSpawnPoints;
        this->mSpawnPoint[i].mSubSegment = 0i64;
        this->mSpawnPoint[i].mLane = 0i64;
        *(_QWORD *)&this->mSpawnPoint[i].mSpawnTime = 0i64;
      }
    }
    this->mNumSpawnPoints = 0;
    UFG::RoadNetworkVisibleAreaEdge::GetCurrentPosition(this, &result);
    position = result;
    NextSubSegment = UFG::RoadNetworkVisibleAreaEdge::GetNextSubSegment(this);
    v7 = NextSubSegment;
    if ( NextSubSegment )
    {
      if ( UFG::RoadNetworkVisibleArea::IsSubSegmentInRange(this->mVisibleArea, NextSubSegment) )
      {
        UFG::RoadNetworkVisibleAreaEdge::SetCurrentSubSegment(this, v7);
      }
      else if ( !this->mComplete )
      {
        this->mComplete = 1;
      }
    }
    else
    {
      NextGate = UFG::RoadNetworkVisibleAreaEdge::GetNextGate(this);
      if ( !UFG::RoadNetworkVisibleAreaEdge::ShouldExpand(this, NextGate) )
        goto LABEL_25;
      mOffset = NextGate->mConnectedNode.mOffset;
      if ( mOffset )
        v10 = (UFG::RoadNetworkSegment *)((char *)&NextGate->mConnectedNode + mOffset);
      else
        v10 = 0i64;
      if ( !v10->mType.mValue )
      {
        ClosestSubSegment = UFG::RoadNetworkSegment::GetClosestSubSegment(v10, &position);
        this->mPreviousGate = NextGate;
        UFG::RoadNetworkVisibleAreaEdge::SetCurrentSubSegment(this, ClosestSubSegment);
        return;
      }
      UFG::RoadNetworkVisibleAreaEdge::AddNodeToPath(this, (Render::VerletCloth *)v10);
      FirstValidGate = UFG::RoadNetworkVisibleArea::GetFirstValidGate(
                         this->mVisibleArea,
                         (UFG::RoadNetworkIntersection *)v10);
      v13 = FirstValidGate;
      if ( FirstValidGate )
      {
        this->mPreviousGate = FirstValidGate;
        v14 = FirstValidGate->mConnectedNode.mOffset;
        if ( v14 )
          v2 = (UFG::RoadNetworkSegment *)((char *)&v13->mConnectedNode + v14);
        v15 = UFG::RoadNetworkSegment::GetClosestSubSegment(v2, &v13->mPosition);
        UFG::RoadNetworkVisibleArea::CreateEdges(this->mVisibleArea, (UFG::RoadNetworkIntersection *)v10, this, v13);
        UFG::RoadNetworkVisibleAreaEdge::SetCurrentSubSegment(this, v15);
      }
      else
      {
LABEL_25:
        if ( !this->mComplete )
          this->mComplete = 1;
      }
    }
  }
}

// File Line: 1884
// RVA: 0xD1BE0
void __fastcall UFG::RoadNetworkVisibleAreaEdge::AddNodeToPath(
        UFG::RoadNetworkVisibleAreaEdge *this,
        Render::VerletCloth *node)
{
  unsigned __int16 mPrev; // ax
  UFG::RoadNetworkVisibleArea *mVisibleArea; // rcx
  unsigned int mPrevSoftVertPosUnconstrained; // edx
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v9; // ebx
  unsigned int v10; // edx
  UFG::RoadNetworkNode **p; // rax
  Render::VerletCloth *value; // [rsp+30h] [rbp+8h] BYREF

  mPrev = (unsigned __int16)node->mPrev;
  if ( LOWORD(node->mPrev) == 1 )
    ++WORD1(node->mPrev);
  mVisibleArea = this->mVisibleArea;
  value = node;
  mPrevSoftVertPosUnconstrained = (unsigned int)node->mPrevSoftVertPosUnconstrained;
  if ( mPrev == 1 )
    UFG::qMap<Render::VerletCloth *>::Set(
      (UFG::qMap<Render::VerletCloth *> *)&mVisibleArea->mVisitedIntersections,
      mPrevSoftVertPosUnconstrained,
      &value);
  else
    UFG::qMap<Render::VerletCloth *>::Set(
      (UFG::qMap<Render::VerletCloth *> *)&mVisibleArea->mVisitedSegments,
      mPrevSoftVertPosUnconstrained,
      &value);
  size = this->mNodesToStart.size;
  capacity = this->mNodesToStart.capacity;
  v9 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v10 = 2 * capacity;
    else
      v10 = 1;
    for ( ; v10 < v9; v10 *= 2 )
      ;
    if ( v10 <= 2 )
      v10 = 2;
    if ( v10 - v9 > 0x10000 )
      v10 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mNodesToStart,
      v10,
      "qArray.Add.mNodesToStart");
  }
  p = this->mNodesToStart.p;
  this->mNodesToStart.size = v9;
  p[size] = (UFG::RoadNetworkNode *)node;
}

// File Line: 1905
// RVA: 0xE0980
bool __fastcall UFG::RoadNetworkVisibleAreaEdge::ShouldExpand(
        UFG::RoadNetworkVisibleAreaEdge *this,
        UFG::RoadNetworkGate *gate)
{
  __int64 mOffset; // rax
  UFG::qBaseTreeRB *v5; // rsi
  UFG::RoadNetworkIntersection *v6; // rdi
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::RoadNetworkGate *ClosestGate; // rax
  unsigned int mIndex; // edx
  UFG::RoadNetworkVisibleArea *mVisibleArea; // rcx
  float v12; // xmm1_4
  float v13; // xmm0_4
  bool v14; // bl
  bool IsSubSegmentInRange; // al
  __int64 v16; // rax
  UFG::RoadNetworkSubSegment *ClosestSubSegment; // rax
  UFG::qVector3 position; // [rsp+20h] [rbp-28h] BYREF
  UFG::qVector3 result; // [rsp+30h] [rbp-18h] BYREF

  if ( !gate )
    return 0;
  mOffset = gate->mConnectedNode.mOffset;
  v5 = 0i64;
  if ( mOffset )
    v6 = (UFG::RoadNetworkIntersection *)((char *)&gate->mConnectedNode + mOffset);
  else
    v6 = 0i64;
  y = gate->mPosition.y;
  position.x = gate->mPosition.x;
  z = gate->mPosition.z;
  position.y = y;
  position.z = z;
  UFG::RoadNetworkVisibleAreaEdge::GetCurrentPosition(this, &result);
  if ( !v6 )
    return 0;
  if ( v6->mType.mValue == 1 )
  {
    ClosestGate = UFG::RoadNetworkIntersection::GetClosestGate(v6, &result);
    mIndex = v6->mIndex;
    mVisibleArea = this->mVisibleArea;
    v12 = ClosestGate->mPosition.y;
    position.x = ClosestGate->mPosition.x;
    v13 = ClosestGate->mPosition.z;
    position.y = v12;
    position.z = v13;
    if ( mIndex )
      v5 = UFG::qBaseTreeRB::Get(&mVisibleArea->mVisitedIntersections.mTree.mTree, mIndex);
    v14 = v5 != 0i64;
    IsSubSegmentInRange = UFG::RoadNetworkVisibleArea::IsInRange(this->mVisibleArea, v6, &position);
  }
  else
  {
    v16 = gate->mConnectedGate.mOffset;
    if ( v16 )
      v5 = (UFG::qBaseTreeRB *)((char *)&gate->mConnectedGate + v16);
    ClosestSubSegment = UFG::RoadNetworkSegment::GetClosestSubSegment(
                          (UFG::RoadNetworkSegment *)v6,
                          (UFG::RoadNetworkGate *)v5);
    v14 = ClosestSubSegment->mActive != 0;
    IsSubSegmentInRange = UFG::RoadNetworkVisibleArea::IsSubSegmentInRange(this->mVisibleArea, ClosestSubSegment);
  }
  return !v14 && IsSubSegmentInRange;
}

// File Line: 1946
// RVA: 0xDADD0
UFG::RoadNetworkSubSegment *__fastcall UFG::RoadNetworkVisibleAreaEdge::GetNextSubSegment(
        UFG::RoadNetworkVisibleAreaEdge *this)
{
  UFG::RoadNetworkSubSegment *mCurrentSubSegment; // rdx
  __int64 v2; // r10
  UFG::RoadNetworkSubSegment *result; // rax
  UFG::RoadNetworkSubSegment *p_mSubSegmentCollection; // r8

  mCurrentSubSegment = this->mCurrentSubSegment;
  v2 = 0i64;
  result = (UFG::RoadNetworkSubSegment *)mCurrentSubSegment->mNext;
  p_mSubSegmentCollection = (UFG::RoadNetworkSubSegment *)&mCurrentSubSegment->mParentNode->mSubSegmentCollection;
  if ( result == p_mSubSegmentCollection
    || (float)((float)((float)((float)(result->mPosition.y - mCurrentSubSegment->mPosition.y) * this->mDirection.y)
                     + (float)((float)(result->mPosition.x - mCurrentSubSegment->mPosition.x) * this->mDirection.x))
             + (float)((float)(result->mPosition.z - mCurrentSubSegment->mPosition.z) * this->mDirection.z)) <= 0.0 )
  {
    if ( mCurrentSubSegment->mPrev != p_mSubSegmentCollection
      && (float)((float)((float)((float)(*((float *)&mCurrentSubSegment->mPrev[1].mNext + 1)
                                       - mCurrentSubSegment->mPosition.y)
                               * this->mDirection.y)
                       + (float)((float)(*(float *)&mCurrentSubSegment->mPrev[1].mNext - mCurrentSubSegment->mPosition.x)
                               * this->mDirection.x))
               + (float)((float)(*(float *)&mCurrentSubSegment->mPrev[2].mPrev - mCurrentSubSegment->mPosition.z)
                       * this->mDirection.z)) > 0.0 )
    {
      return (UFG::RoadNetworkSubSegment *)mCurrentSubSegment->mPrev;
    }
    return (UFG::RoadNetworkSubSegment *)v2;
  }
  return result;
}

// File Line: 1979
// RVA: 0xE1650
void __fastcall UFG::RoadNetworkVisibleAreaEdge::UpdateDirection(UFG::RoadNetworkVisibleAreaEdge *this)
{
  UFG::RoadNetworkSubSegment *mCurrentSubSegment; // rax
  UFG::RoadNetworkSubSegment *mPreviousSubSegment; // rdx
  float v3; // xmm8_4
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm7_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::RoadNetworkSubSegment *mNextSubSegment; // rdx
  UFG::RoadNetworkGate *mNextGate; // rdx
  UFG::RoadNetworkGate *mPreviousGate; // rdx
  float v14; // [rsp+0h] [rbp-48h]
  float v15; // [rsp+4h] [rbp-44h]
  float v16; // [rsp+8h] [rbp-40h]

  mCurrentSubSegment = this->mCurrentSubSegment;
  if ( mCurrentSubSegment )
  {
    mPreviousSubSegment = this->mPreviousSubSegment;
    v3 = mCurrentSubSegment->mEndPos.z - mCurrentSubSegment->mPosition.z;
    v4 = mCurrentSubSegment->mBeginPos.x - mCurrentSubSegment->mPosition.x;
    v5 = mCurrentSubSegment->mBeginPos.y - mCurrentSubSegment->mPosition.y;
    v6 = mCurrentSubSegment->mBeginPos.z - mCurrentSubSegment->mPosition.z;
    v7 = mCurrentSubSegment->mEndPos.y - mCurrentSubSegment->mPosition.y;
    if ( mPreviousSubSegment )
    {
      v8 = mCurrentSubSegment->mPosition.x - mPreviousSubSegment->mPosition.x;
      v9 = mCurrentSubSegment->mPosition.y - mPreviousSubSegment->mPosition.y;
      v10 = mCurrentSubSegment->mPosition.z - mPreviousSubSegment->mPosition.z;
    }
    else
    {
      mNextSubSegment = this->mNextSubSegment;
      if ( mNextSubSegment )
      {
        v8 = mNextSubSegment->mPosition.x - mCurrentSubSegment->mPosition.x;
        v9 = mNextSubSegment->mPosition.y - mCurrentSubSegment->mPosition.y;
        v10 = mNextSubSegment->mPosition.z - mCurrentSubSegment->mPosition.z;
      }
      else
      {
        mNextGate = this->mNextGate;
        if ( mNextGate )
        {
          v8 = mNextGate->mPosition.x - mCurrentSubSegment->mPosition.x;
          v9 = mNextGate->mPosition.y - mCurrentSubSegment->mPosition.y;
          v10 = mNextGate->mPosition.z - mCurrentSubSegment->mPosition.z;
        }
        else
        {
          mPreviousGate = this->mPreviousGate;
          if ( mPreviousGate )
          {
            v8 = mCurrentSubSegment->mPosition.x - mPreviousGate->mPosition.x;
            v9 = mCurrentSubSegment->mPosition.y - mPreviousGate->mPosition.y;
            v10 = mCurrentSubSegment->mPosition.z - mPreviousGate->mPosition.z;
          }
          else
          {
            v10 = v16;
            v9 = v15;
            v8 = v14;
          }
        }
      }
    }
    if ( (float)((float)((float)(v9 * v5) + (float)(v8 * v4)) + (float)(v10 * v6)) <= 0.0 )
    {
      this->mDirection.x = mCurrentSubSegment->mEndPos.x - mCurrentSubSegment->mPosition.x;
      this->mDirection.y = v7;
      this->mDirection.z = v3;
    }
    else
    {
      this->mDirection.x = v4;
      this->mDirection.y = v5;
      this->mDirection.z = v6;
    }
  }
}

// File Line: 2010
// RVA: 0xE0400
void __fastcall UFG::RoadNetworkVisibleAreaEdge::SetCurrentSubSegment(
        UFG::RoadNetworkVisibleAreaEdge *this,
        UFG::RoadNetworkSubSegment *subSegment)
{
  unsigned int size; // eax
  UFG::RoadNetworkNode *v3; // rsi
  UFG::RoadNetworkSegment *mParentNode; // rdx
  UFG::RoadNetworkSubSegment *mCurrentSubSegment; // rax

  size = this->mNodesToStart.size;
  v3 = 0i64;
  if ( size )
    v3 = this->mNodesToStart.p[size - 1];
  mParentNode = subSegment->mParentNode;
  if ( mParentNode == v3 )
  {
    mCurrentSubSegment = this->mCurrentSubSegment;
    this->mNextSubSegment = 0i64;
    this->mPreviousSubSegment = mCurrentSubSegment;
  }
  else
  {
    UFG::RoadNetworkVisibleAreaEdge::AddNodeToPath(this, (Render::VerletCloth *)mParentNode);
    if ( v3->mType.mValue == 1 )
      this->mPreviousSubSegment = 0i64;
  }
  this->mCurrentSubSegment = subSegment;
  ++subSegment->mActive;
  UFG::RoadNetworkVisibleAreaEdge::UpdateDirection(this);
  UFG::RoadNetworkVisibleAreaEdge::RefreshT(this);
  UFG::RoadNetworkVisibleArea::ClaimSubSegmentVisited(this->mVisibleArea, this->mCurrentSubSegment);
}

// File Line: 2038
// RVA: 0xDF900
void __fastcall UFG::RoadNetworkVisibleAreaEdge::RefreshT(UFG::RoadNetworkVisibleAreaEdge *this)
{
  UFG::RoadNetworkSubSegment *mCurrentSubSegment; // rax
  float *mEndTCollection; // rax

  mCurrentSubSegment = this->mCurrentSubSegment;
  if ( (float)((float)((float)((float)(mCurrentSubSegment->mBeginPos.y - mCurrentSubSegment->mPosition.y)
                             * this->mDirection.y)
                     + (float)((float)(mCurrentSubSegment->mBeginPos.x - mCurrentSubSegment->mPosition.x)
                             * this->mDirection.x))
             + (float)((float)(mCurrentSubSegment->mBeginPos.z - mCurrentSubSegment->mPosition.z) * this->mDirection.z)) <= 0.0 )
    mEndTCollection = mCurrentSubSegment->mEndTCollection;
  else
    mEndTCollection = mCurrentSubSegment->mBeginTCollection;
  this->mT = *mEndTCollection;
}

// File Line: 2063
// RVA: 0xDABD0
UFG::RoadNetworkGate *__fastcall UFG::RoadNetworkVisibleAreaEdge::GetNextGate(UFG::RoadNetworkVisibleAreaEdge *this)
{
  UFG::RoadNetworkGate *v2; // rsi
  UFG::RoadNetworkSegment *mParentNode; // r15
  __int64 mOffset; // rax
  _QWORD *v5; // rcx
  UFG::RoadNetworkGate *v6; // rbp
  char *v7; // rcx
  __int64 v8; // rax
  UFG::RoadNetworkGate *v9; // r14
  UFG::RoadNetworkGate **p; // r12
  UFG::RoadNetworkGate *v11; // rax
  UFG::RoadNetworkSubSegment *NextSubSegment; // rax
  UFG::RoadNetworkSubSegment *mCurrentSubSegment; // rdi
  bool v14; // zf
  UFG::RoadNetworkSubSegment *ClosestSubSegment; // rbx
  UFG::RoadNetworkSubSegment *v16; // rax
  UFG::qArray<UFG::RoadNetworkGate *,0> gateCollection; // [rsp+28h] [rbp-40h] BYREF

  v2 = 0i64;
  mParentNode = this->mCurrentSubSegment->mParentNode;
  mOffset = mParentNode->mGates.mOffset;
  if ( mOffset )
    v5 = (__int64 *)((char *)&mParentNode->mGates.mOffset + mOffset);
  else
    v5 = 0i64;
  v6 = (UFG::RoadNetworkGate *)((char *)v5 + *v5);
  if ( !*v5 )
    v6 = 0i64;
  if ( mOffset )
    v7 = (char *)&mParentNode->mGates + mOffset;
  else
    v7 = 0i64;
  v8 = *((_QWORD *)v7 + 1);
  if ( v8 )
    v9 = (UFG::RoadNetworkGate *)&v7[v8 + 8];
  else
    v9 = 0i64;
  gateCollection.p = 0i64;
  *(_QWORD *)&gateCollection.size = 0i64;
  UFG::RoadNetworkSubSegment::GetGatesConnectedToSubSegment(
    this->mCurrentSubSegment,
    (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&gateCollection);
  p = gateCollection.p;
  if ( gateCollection.size == 2 )
  {
    v2 = v9;
    if ( (float)((float)((float)((float)(v6->mPosition.y - this->mCurrentSubSegment->mPosition.y) * this->mDirection.y)
                       + (float)((float)(v6->mPosition.x - this->mCurrentSubSegment->mPosition.x) * this->mDirection.x))
               + (float)((float)(v6->mPosition.z - this->mCurrentSubSegment->mPosition.z) * this->mDirection.z)) > 0.0 )
      v2 = v6;
    goto LABEL_21;
  }
  if ( gateCollection.size == 1 )
  {
    v2 = *gateCollection.p;
    if ( (float)((float)((float)((float)((*gateCollection.p)->mPosition.y - this->mCurrentSubSegment->mPosition.y)
                               * this->mDirection.y)
                       + (float)((float)((*gateCollection.p)->mPosition.x - this->mCurrentSubSegment->mPosition.x)
                               * this->mDirection.x))
               + (float)((float)((*gateCollection.p)->mPosition.z - this->mCurrentSubSegment->mPosition.z)
                       * this->mDirection.z)) <= 0.0 )
    {
      v11 = v6;
      if ( v6 == v2 )
        v11 = v9;
      v2 = v11;
    }
LABEL_21:
    if ( v2 )
      goto LABEL_31;
  }
  if ( this->mPreviousSubSegment )
  {
    NextSubSegment = 0i64;
    mCurrentSubSegment = this->mCurrentSubSegment;
    v14 = 1;
    do
    {
      if ( !v14 )
        mCurrentSubSegment = NextSubSegment;
      NextSubSegment = UFG::RoadNetworkVisibleAreaEdge::GetNextSubSegment(this);
      v14 = NextSubSegment == 0i64;
    }
    while ( NextSubSegment );
    ClosestSubSegment = UFG::RoadNetworkSegment::GetClosestSubSegment(mParentNode, v6);
    v16 = UFG::RoadNetworkSegment::GetClosestSubSegment(mParentNode, v9);
    if ( ClosestSubSegment == mCurrentSubSegment )
    {
      v2 = v6;
    }
    else if ( v16 == mCurrentSubSegment )
    {
      v2 = v9;
    }
  }
LABEL_31:
  if ( p )
    operator delete[](p);
  return v2;
}

// File Line: 2152
// RVA: 0xD24E0
void __fastcall UFG::RoadNetworkVisibleAreaEdge::AttachSpawnPoints(UFG::RoadNetworkVisibleAreaEdge *this)
{
  unsigned int i; // edx
  UFG::RoadNetworkLane *mLane; // rax
  UFG::RoadNetworkSubSegment *mSubSegment; // rax
  UFG::RoadNetworkSubSegment *mCurrentSubSegment; // rax
  UFG::RoadNetworkSegment *mParentNode; // rsi
  char v7; // r12
  __int64 v8; // r15
  __int64 v9; // rdi
  __int64 v10; // rbp
  __int64 mNumLanes; // r14
  __int64 mOffset; // rdx
  char *v13; // rax
  char *v14; // rcx
  __int64 v15; // rax
  char *v16; // rax
  __int64 v17; // rcx
  char *v18; // r8
  char *v19; // rcx
  __int64 v20; // rax
  char *v21; // rax
  char *v22; // rcx
  __int64 v23; // rax
  char *v24; // rax
  UFG::RoadNetworkSubSegment *v25; // rax
  float *mBeginTCollection; // rcx
  float v27; // xmm7_4
  char *v28; // rax
  char *v29; // rcx
  __int64 v30; // rax
  char *v31; // rax
  char *v32; // rcx
  unsigned int v33; // edx
  __int64 v34; // rax
  UFG::RoadNetworkConnection *v35; // rcx
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  __int64 mNumSpawnPoints; // r9
  __int64 v40; // rax
  char *v41; // rcx
  char *v42; // rax
  __int64 v43; // rcx
  UFG::RoadNetworkLane *v44; // r8
  UFG::RoadNetworkSubSegment *v45; // rdx
  UFG::RoadNetworkSpawnPoint *v46; // rcx

  for ( i = 0; i < this->mNumSpawnPoints; ++i )
  {
    mLane = this->mSpawnPoint[i].mLane;
    if ( mLane )
    {
      mLane->mSpawnPoint = 0i64;
      mLane->mSpawnT = 0.0;
      mSubSegment = this->mSpawnPoint[i].mSubSegment;
      --mSubSegment->mNumSpawnPoints;
      this->mSpawnPoint[i].mSubSegment = 0i64;
      this->mSpawnPoint[i].mLane = 0i64;
      *(_QWORD *)&this->mSpawnPoint[i].mSpawnTime = 0i64;
    }
  }
  mCurrentSubSegment = this->mCurrentSubSegment;
  this->mNumSpawnPoints = 0;
  mParentNode = mCurrentSubSegment->mParentNode;
  LODWORD(mCurrentSubSegment) = ((float)((float)((float)((float)(mCurrentSubSegment->mBeginPos.y
                                                               - mCurrentSubSegment->mPosition.y)
                                                       * this->mDirection.y)
                                               + (float)((float)(mCurrentSubSegment->mBeginPos.x
                                                               - mCurrentSubSegment->mPosition.x)
                                                       * this->mDirection.x))
                                       + (float)((float)(mCurrentSubSegment->mBeginPos.z
                                                       - mCurrentSubSegment->mPosition.z)
                                               * this->mDirection.z)) <= 0.0)
                              + 1;
  v7 = 0;
  v8 = (int)mCurrentSubSegment;
  if ( (_DWORD)mCurrentSubSegment == 2 )
    v7 = 1;
  if ( mParentNode->mNumLanes )
  {
    v9 = 0i64;
    v10 = 0i64;
    mNumLanes = (unsigned __int8)mParentNode->mNumLanes;
    do
    {
      mOffset = mParentNode->mLane.mOffset;
      if ( mOffset )
        v13 = (char *)&mParentNode->mLane + mOffset;
      else
        v13 = 0i64;
      v14 = &v13[v9];
      v15 = *(_QWORD *)&v13[v9];
      if ( v15 )
        v16 = &v14[v15];
      else
        v16 = 0i64;
      v17 = *((_QWORD *)v16 + 1);
      if ( v17 )
        v18 = &v16[v17 + 8];
      else
        v18 = 0i64;
      if ( *(_QWORD *)v16 )
        v19 = &v16[*(_QWORD *)v16];
      else
        v19 = 0i64;
      v20 = *((_QWORD *)v19 + 6);
      if ( v20 )
        v21 = &v19[v20 + 48];
      else
        v21 = 0i64;
      if ( *(_QWORD *)v21 )
        v22 = &v21[*(_QWORD *)v21];
      else
        v22 = 0i64;
      v23 = *((_QWORD *)v22 + 1);
      if ( v23 )
        v24 = &v22[v23 + 8];
      else
        v24 = 0i64;
      if ( v7 == (v18 != v24) )
      {
        v25 = this->mCurrentSubSegment;
        if ( v8 == 1 )
          mBeginTCollection = v25->mBeginTCollection;
        else
          mBeginTCollection = v25->mEndTCollection;
        v27 = mBeginTCollection[v10];
        if ( mOffset )
          v28 = (char *)&mParentNode->mLane + mOffset;
        else
          v28 = 0i64;
        v29 = &v28[v9];
        v30 = *(_QWORD *)&v28[v9];
        if ( v30 )
          v31 = &v29[v30];
        else
          v31 = 0i64;
        if ( *(_QWORD *)v31 )
          v32 = &v31[*(_QWORD *)v31];
        else
          v32 = 0i64;
        v33 = *((unsigned __int16 *)v31 + 19);
        v34 = *((_QWORD *)v32 + 4);
        if ( v34 )
          v35 = (UFG::RoadNetworkConnection *)&v32[v34 + 32];
        else
          v35 = 0i64;
        v36 = *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v35, v33)->mNode.mOffset + 1);
        if ( v36 <= 0.0 )
          v37 = 0.0;
        else
          v37 = 3.0 / v36;
        v38 = v37 + v27;
        if ( v38 <= 0.0 )
        {
          v38 = 0.0;
        }
        else if ( v38 >= 1.0 )
        {
          v38 = *(float *)&FLOAT_1_0;
        }
        mNumSpawnPoints = this->mNumSpawnPoints;
        if ( (unsigned int)mNumSpawnPoints < 6 )
        {
          v40 = mParentNode->mLane.mOffset;
          if ( v40 )
            v41 = (char *)&mParentNode->mLane + v40;
          else
            v41 = 0i64;
          v42 = &v41[v9];
          v43 = *(_QWORD *)&v41[v9];
          v44 = (UFG::RoadNetworkLane *)&v42[v43];
          if ( !v43 )
            v44 = 0i64;
          v45 = this->mCurrentSubSegment;
          v46 = &this->mSpawnPoint[mNumSpawnPoints];
          v46->mLane = v44;
          v46->mSubSegment = v45;
          ++v45->mNumSpawnPoints;
          v44->mSpawnT = v38;
          v44->mSpawnPoint = v46;
          UFG::RoadNetworkSpawnPoint::Reset(v46);
          ++this->mNumSpawnPoints;
        }
      }
      ++v10;
      v9 += 8i64;
      --mNumLanes;
    }
    while ( mNumLanes );
  }
}

// File Line: 2195
// RVA: 0xDE710
bool __fastcall UFG::RoadNetworkVisibleAreaEdge::IsOuterEdge(UFG::RoadNetworkVisibleAreaEdge *this)
{
  UFG::RoadNetworkSubSegment *NextSubSegment; // rax
  UFG::RoadNetworkGate *NextGate; // rax
  __int64 mOffset; // rcx
  char *v6; // rax
  bool v7; // cl
  unsigned int v8; // edx

  NextSubSegment = UFG::RoadNetworkVisibleAreaEdge::GetNextSubSegment(this);
  if ( NextSubSegment )
    return NextSubSegment->mActive == 0;
  NextGate = UFG::RoadNetworkVisibleAreaEdge::GetNextGate(this);
  if ( !NextGate )
    return 1;
  mOffset = NextGate->mConnectedNode.mOffset;
  if ( !mOffset )
    return 1;
  v6 = (char *)&NextGate->mConnectedNode + mOffset;
  if ( !v6 )
    return 1;
  v7 = 0;
  if ( *(_WORD *)v6 == 1 )
  {
    v8 = *((_DWORD *)v6 + 6);
    if ( !v8 )
      return 1;
    v7 = UFG::qBaseTreeRB::Get(&this->mVisibleArea->mVisitedIntersections.mTree.mTree, v8) != 0i64;
  }
  return !v7;
}

