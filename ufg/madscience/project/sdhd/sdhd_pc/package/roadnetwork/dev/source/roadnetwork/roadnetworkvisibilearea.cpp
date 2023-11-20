// File Line: 82
// RVA: 0xD0450
void __fastcall UFG::RoadNetworkVisibleArea::RoadNetworkVisibleArea(UFG::RoadNetworkVisibleArea *this)
{
  UFG::RoadNetworkVisibleArea *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4

  v1 = this;
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
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mVisitedSegments.mTree.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mVisitedIntersections.mTree.mTree);
  v1->mVisibleAreaExpansionStep = 0;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->mPreviousStartPosition.x = UFG::qVector3::msZero.x;
  v1->mPreviousStartPosition.y = v2;
  v1->mPreviousStartPosition.z = v3;
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v1->mStartPosition.x = UFG::qVector3::msZero.x;
  v1->mStartPosition.y = v4;
  v1->mStartPosition.z = v5;
  v6 = UFG::qVector3::msDirFront.y;
  v7 = UFG::qVector3::msDirFront.z;
  v1->mStartDirection.x = UFG::qVector3::msDirFront.x;
  v1->mStartDirection.y = v6;
  v1->mStartDirection.z = v7;
  v1->mStartSpeed = 0.0;
  v1->mForceVisibleAreaUpdate = 0;
}

// File Line: 87
// RVA: 0xDCCD0
void __fastcall UFG::RoadNetworkVisibleArea::Init(UFG::RoadNetworkVisibleArea *this, UFG::RoadNetworkResource *roadNetwork)
{
  UFG::RoadNetworkVisibleArea *v2; // rdi
  float v3; // xmm1_4
  float v4; // xmm2_4
  char *v5; // rax
  char *v6; // rax
  char *v7; // rax
  char *v8; // rax
  unsigned int v9; // ecx
  unsigned int v10; // ebx
  unsigned int v11; // edx
  unsigned int v12; // edx
  unsigned int v13; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edx
  unsigned int v16; // ecx
  unsigned int v17; // edx
  unsigned int v18; // edx
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v19; // r14
  unsigned int v20; // eax
  unsigned int v21; // eax

  v2 = this;
  *(_QWORD *)&this->mPreviousStartPosition.x = 0i64;
  this->mPreviousStartPosition.z = -1000.0;
  *(_QWORD *)&this->mStartPosition.x = 0i64;
  this->mStartPosition.z = -1000.0;
  v3 = UFG::qVector3::msDirFront.y;
  v4 = UFG::qVector3::msDirFront.z;
  this->mStartDirection.x = UFG::qVector3::msDirFront.x;
  this->mStartDirection.y = v3;
  this->mStartDirection.z = v4;
  this->mStartSpeed = 0.0;
  this->mRoadNetwork = roadNetwork;
  v5 = UFG::qMalloc(0x10ui64, "qArray", 0i64);
  if ( v5 )
  {
    *((_QWORD *)v5 + 1) = 0i64;
    *(_QWORD *)v5 = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v2->mPreviousVisibleRoadNetwork = (UFG::qArray<UFG::RoadNetworkNode *,0> *)v5;
  v6 = UFG::qMalloc(0x10ui64, "qArray", 0i64);
  if ( v6 )
  {
    *((_QWORD *)v6 + 1) = 0i64;
    *(_QWORD *)v6 = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  v2->mCurrentVisibleRoadNetwork = (UFG::qArray<UFG::RoadNetworkNode *,0> *)v6;
  v7 = UFG::qMalloc(0x10ui64, "qArray", 0i64);
  if ( v7 )
  {
    *((_QWORD *)v7 + 1) = 0i64;
    *(_QWORD *)v7 = 0i64;
  }
  else
  {
    v7 = 0i64;
  }
  v2->mPreviousVisibleSubSegments = (UFG::qArray<UFG::RoadNetworkSubSegment *,0> *)v7;
  v8 = UFG::qMalloc(0x10ui64, "qArray", 0i64);
  if ( v8 )
  {
    *((_QWORD *)v8 + 1) = 0i64;
    *(_QWORD *)v8 = 0i64;
  }
  else
  {
    v8 = 0i64;
  }
  v2->mCurrentVisibleSubSegments = (UFG::qArray<UFG::RoadNetworkSubSegment *,0> *)v8;
  v9 = v2->mClosestNodeCollection.size;
  v10 = 1;
  if ( (signed int)(4 - v9) <= 0 )
  {
    if ( v9 != 4 )
    {
      if ( v9 - 4 < v9 )
        v2->mClosestNodeCollection.size = 4;
      else
        v2->mClosestNodeCollection.size = 0;
    }
  }
  else
  {
    v11 = v2->mClosestNodeCollection.capacity;
    if ( v11 < 4 )
    {
      if ( v11 )
        v12 = 2 * v11;
      else
        v12 = 1;
      for ( ; v12 < 4; v12 *= 2 )
        ;
      if ( v12 <= 2 )
        v12 = 2;
      if ( v12 - 4 > 0x10000 )
        v12 = 65540;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v2->mClosestNodeCollection,
        v12,
        "RoadNetworkVisibleArea");
    }
    v2->mClosestNodeCollection.size = 4;
  }
  v13 = v2->mClosestSubSegmentCollection.size;
  if ( (signed int)(4 - v13) <= 0 )
  {
    if ( v13 != 4 )
    {
      if ( v13 - 4 < v13 )
        v2->mClosestSubSegmentCollection.size = 4;
      else
        v2->mClosestSubSegmentCollection.size = 0;
    }
  }
  else
  {
    v14 = v2->mClosestSubSegmentCollection.capacity;
    if ( v14 < 4 )
    {
      if ( v14 )
        v15 = 2 * v14;
      else
        v15 = 1;
      for ( ; v15 < 4; v15 *= 2 )
        ;
      if ( v15 <= 2 )
        v15 = 2;
      if ( v15 - 4 > 0x10000 )
        v15 = 65540;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v2->mClosestSubSegmentCollection,
        v15,
        "RoadNetworkVisibleArea");
    }
    v2->mClosestSubSegmentCollection.size = 4;
  }
  v16 = v2->mPreviousClosestNodeCollection.size;
  if ( (signed int)(4 - v16) <= 0 )
  {
    if ( v16 != 4 )
    {
      if ( v16 - 4 < v16 )
        v2->mPreviousClosestNodeCollection.size = 4;
      else
        v2->mPreviousClosestNodeCollection.size = 0;
    }
  }
  else
  {
    v17 = v2->mPreviousClosestNodeCollection.capacity;
    if ( v17 < 4 )
    {
      if ( v17 )
        v18 = 2 * v17;
      else
        v18 = 1;
      for ( ; v18 < 4; v18 *= 2 )
        ;
      if ( v18 <= 2 )
        v18 = 2;
      if ( v18 - 4 > 0x10000 )
        v18 = 65540;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v2->mPreviousClosestNodeCollection,
        v18,
        "RoadNetworkVisibleArea");
    }
    v2->mPreviousClosestNodeCollection.size = 4;
  }
  v19 = &v2->mPreviousClosestSubSegmentCollection;
  v20 = v2->mPreviousClosestSubSegmentCollection.size;
  if ( (signed int)(4 - v20) <= 0 )
  {
    if ( v20 != 4 )
    {
      if ( v20 - 4 < v20 )
        v19->size = 4;
      else
        v19->size = 0;
    }
  }
  else
  {
    v21 = v2->mPreviousClosestSubSegmentCollection.capacity;
    if ( v21 < 4 )
    {
      if ( v21 )
        v10 = 2 * v21;
      for ( ; v10 < 4; v10 *= 2 )
        ;
      if ( v10 <= 2 )
        v10 = 2;
      if ( v10 - 4 > 0x10000 )
        v10 = 65540;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v2->mPreviousClosestSubSegmentCollection,
        v10,
        "RoadNetworkVisibleArea");
    }
    v19->size = 4;
  }
  *v2->mClosestNodeCollection.p = 0i64;
  *v2->mClosestSubSegmentCollection.p = 0i64;
  *v2->mPreviousClosestNodeCollection.p = 0i64;
  *v2->mPreviousClosestSubSegmentCollection.p = 0i64;
  *((_QWORD *)v2->mClosestNodeCollection.p + 1) = 0i64;
  *((_QWORD *)v2->mClosestSubSegmentCollection.p + 1) = 0i64;
  *((_QWORD *)v2->mPreviousClosestNodeCollection.p + 1) = 0i64;
  *((_QWORD *)v2->mPreviousClosestSubSegmentCollection.p + 1) = 0i64;
  *((_QWORD *)v2->mClosestNodeCollection.p + 2) = 0i64;
  *((_QWORD *)v2->mClosestSubSegmentCollection.p + 2) = 0i64;
  *((_QWORD *)v2->mPreviousClosestNodeCollection.p + 2) = 0i64;
  *((_QWORD *)v2->mPreviousClosestSubSegmentCollection.p + 2) = 0i64;
  *((_QWORD *)v2->mClosestNodeCollection.p + 3) = 0i64;
  *((_QWORD *)v2->mClosestSubSegmentCollection.p + 3) = 0i64;
  *((_QWORD *)v2->mPreviousClosestNodeCollection.p + 3) = 0i64;
  *((_QWORD *)v2->mPreviousClosestSubSegmentCollection.p + 3) = 0i64;
}

// File Line: 115
// RVA: 0xDFC90
void __fastcall UFG::RoadNetworkVisibleArea::Release(UFG::RoadNetworkVisibleArea *this)
{
  UFG::qArray<UFG::RoadNetworkNode *,0> *v1; // rdi
  UFG::RoadNetworkVisibleArea *v2; // rbx
  UFG::RoadNetworkNode **v3; // rcx
  UFG::qArray<UFG::RoadNetworkNode *,0> *v4; // rdi
  UFG::RoadNetworkNode **v5; // rcx
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v6; // rdi
  UFG::RoadNetworkSubSegment **v7; // rcx
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v8; // rdi
  UFG::RoadNetworkSubSegment **v9; // rcx
  UFG::RoadNetworkNode **v10; // rcx
  UFG::RoadNetworkSubSegment **v11; // rcx
  UFG::RoadNetworkNode **v12; // rcx
  UFG::RoadNetworkSubSegment **v13; // rcx

  v1 = this->mPreviousVisibleRoadNetwork;
  v2 = this;
  if ( v1 )
  {
    v3 = v1->p;
    if ( v3 )
      operator delete[](v3);
    v1->p = 0i64;
    *(_QWORD *)&v1->size = 0i64;
    operator delete[](v1);
  }
  v4 = v2->mCurrentVisibleRoadNetwork;
  if ( v4 )
  {
    v5 = v4->p;
    if ( v5 )
      operator delete[](v5);
    v4->p = 0i64;
    *(_QWORD *)&v4->size = 0i64;
    operator delete[](v4);
  }
  v6 = v2->mPreviousVisibleSubSegments;
  if ( v6 )
  {
    v7 = v6->p;
    if ( v7 )
      operator delete[](v7);
    v6->p = 0i64;
    *(_QWORD *)&v6->size = 0i64;
    operator delete[](v6);
  }
  v8 = v2->mCurrentVisibleSubSegments;
  if ( v8 )
  {
    v9 = v8->p;
    if ( v9 )
      operator delete[](v9);
    v8->p = 0i64;
    *(_QWORD *)&v8->size = 0i64;
    operator delete[](v8);
  }
  v10 = v2->mClosestNodeCollection.p;
  if ( v10 )
    operator delete[](v10);
  v2->mClosestNodeCollection.p = 0i64;
  *(_QWORD *)&v2->mClosestNodeCollection.size = 0i64;
  v11 = v2->mClosestSubSegmentCollection.p;
  if ( v11 )
    operator delete[](v11);
  v2->mClosestSubSegmentCollection.p = 0i64;
  *(_QWORD *)&v2->mClosestSubSegmentCollection.size = 0i64;
  v12 = v2->mPreviousClosestNodeCollection.p;
  if ( v12 )
    operator delete[](v12);
  v2->mPreviousClosestNodeCollection.p = 0i64;
  *(_QWORD *)&v2->mPreviousClosestNodeCollection.size = 0i64;
  v13 = v2->mPreviousClosestSubSegmentCollection.p;
  if ( v13 )
    operator delete[](v13);
  v2->mPreviousClosestSubSegmentCollection.p = 0i64;
  *(_QWORD *)&v2->mPreviousClosestSubSegmentCollection.size = 0i64;
  UFG::RoadNetworkVisibleAreaEdgeManager::Clear(&v2->mEdgeManager);
}

// File Line: 182
// RVA: 0xDF970
void __fastcall UFG::RoadNetworkVisibleArea::Reinitialize(UFG::RoadNetworkVisibleArea *this)
{
  UFG::RoadNetworkVisibleArea *v1; // rdi
  unsigned int v2; // er8
  UFG::RoadNetworkSubSegment *v3; // r9
  unsigned __int16 v4; // ax
  unsigned int i; // er8
  UFG::RoadNetworkNode *v6; // r9
  unsigned __int16 v7; // ax
  unsigned int j; // er8
  UFG::RoadNetworkSubSegment *v9; // r9
  unsigned __int16 v10; // ax
  unsigned int k; // er8
  UFG::RoadNetworkNode *v12; // r9
  unsigned __int16 v13; // ax
  UFG::qBaseTreeRB *l; // rax
  UFG::qBaseNodeRB *v15; // rdx
  __int16 v16; // cx
  Render::SkinningCacheNode *v17; // rbx
  Render::SkinningCacheNode *v18; // rbx
  float v19; // xmm1_4
  float v20; // xmm2_4

  v1 = this;
  if ( this->mRoadNetwork )
  {
    v2 = 0;
    if ( this->mCurrentVisibleSubSegments->size )
    {
      do
      {
        v3 = this->mCurrentVisibleSubSegments->p[v2];
        v4 = v3->mActive;
        do
          --v4;
        while ( v4 );
        v3->mActive = 0;
        ++v2;
      }
      while ( v2 < this->mCurrentVisibleSubSegments->size );
    }
    for ( i = 0; i < this->mCurrentVisibleRoadNetwork->size; ++i )
    {
      v6 = this->mCurrentVisibleRoadNetwork->p[i];
      v7 = v6->mActive;
      do
        --v7;
      while ( v7 );
      v6->mActive = 0;
    }
    for ( j = 0; j < this->mPreviousVisibleSubSegments->size; ++j )
    {
      v9 = this->mPreviousVisibleSubSegments->p[j];
      v10 = v9->mActive;
      do
        --v10;
      while ( v10 );
      v9->mActive = 0;
    }
    for ( k = 0; k < this->mPreviousVisibleRoadNetwork->size; ++k )
    {
      v12 = this->mPreviousVisibleRoadNetwork->p[k];
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
    v1->mVisibleAreaExpansionStep = 0;
    for ( l = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mVisitedIntersections);
          l;
          l = UFG::qBaseTreeRB::GetNext(&v1->mVisitedIntersections.mTree.mTree, &l->mRoot) )
    {
      v15 = l->mNULL.mParent;
      v16 = WORD1(v15->mParent);
      do
        --v16;
      while ( v16 );
      WORD1(v15->mParent) = 0;
    }
    while ( v1->mVisitedSegments.mTree.mTree.mCount )
    {
      v17 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mVisitedSegments);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mVisitedSegments,
        &v17->mNode);
      operator delete[](v17);
    }
    while ( v1->mVisitedIntersections.mTree.mTree.mCount )
    {
      v18 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v1->mVisitedIntersections);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
        (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v1->mVisitedIntersections,
        &v18->mNode);
      operator delete[](v18);
    }
    *(_QWORD *)&v1->mPreviousStartPosition.x = 0i64;
    v1->mPreviousStartPosition.z = -1000.0;
    *(_QWORD *)&v1->mStartPosition.x = 0i64;
    v1->mStartPosition.z = -1000.0;
    v19 = UFG::qVector3::msDirFront.y;
    v20 = UFG::qVector3::msDirFront.z;
    v1->mStartDirection.x = UFG::qVector3::msDirFront.x;
    v1->mStartDirection.y = v19;
    v1->mStartDirection.z = v20;
    v1->mStartSpeed = 0.0;
    v1->mForceVisibleAreaUpdate = 1;
  }
}

// File Line: 284
// RVA: 0xD38F0
void __fastcall UFG::RoadNetworkVisibleArea::ClearLastVisibleArea(UFG::RoadNetworkVisibleArea *this)
{
  __int64 v1; // r8
  UFG::RoadNetworkVisibleArea *v2; // rbp
  __int64 v3; // rdx
  UFG::RoadNetworkSubSegment *v4; // r9
  unsigned __int16 v5; // ax
  unsigned int v6; // ecx
  __int64 v7; // rdi
  __int64 v8; // rsi
  UFG::RoadNetworkNode *v9; // rbx
  unsigned int v10; // edx
  unsigned __int16 v11; // ax
  UFG::qBaseTreeRB *i; // rax
  UFG::qBaseNodeRB *v13; // rdx
  __int16 v14; // cx
  Render::SkinningCacheNode *v15; // rbx
  Render::SkinningCacheNode *v16; // rbx

  v1 = this->mPreviousVisibleSubSegments->size;
  v2 = this;
  if ( (_DWORD)v1 )
  {
    v3 = 0i64;
    do
    {
      v4 = this->mPreviousVisibleSubSegments->p[v3];
      v5 = v4->mActive;
      if ( v5 )
      {
        do
          --v5;
        while ( v5 );
        v4->mActive = 0;
      }
      ++v3;
      --v1;
    }
    while ( v1 );
  }
  v6 = this->mPreviousVisibleRoadNetwork->size;
  if ( v6 )
  {
    v7 = 0i64;
    v8 = v6;
    do
    {
      v9 = v2->mPreviousVisibleRoadNetwork->p[v7];
      v10 = v9->mIndex;
      if ( !v10 || !UFG::qBaseTreeRB::Get(&v2->mVisitedIntersections.mTree.mTree, v10) )
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
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v2->mVisitedIntersections);
        i;
        i = UFG::qBaseTreeRB::GetNext(&v2->mVisitedIntersections.mTree.mTree, &i->mRoot) )
  {
    v13 = i->mNULL.mParent;
    v14 = WORD1(v13->mParent);
    do
      --v14;
    while ( v14 );
    WORD1(v13->mParent) = 0;
  }
  while ( v2->mVisitedSegments.mTree.mTree.mCount )
  {
    v15 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v2->mVisitedSegments);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v2->mVisitedSegments,
      &v15->mNode);
    operator delete[](v15);
  }
  while ( v2->mVisitedIntersections.mTree.mTree.mCount )
  {
    v16 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v2->mVisitedIntersections);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v2->mVisitedIntersections,
      &v16->mNode);
    operator delete[](v16);
  }
  UFG::RoadNetworkVisibleAreaEdgeManager::Clear(&v2->mEdgeManager);
  v2->mVisibleAreaExpansionStep = 0;
}

// File Line: 358
// RVA: 0xE1060
bool __fastcall UFG::RoadNetworkVisibleArea::UpdateClosestRoadNetworkNodes(UFG::RoadNetworkVisibleArea *this)
{
  float v1; // xmm7_4
  unsigned int v2; // edi
  UFG::RoadNetworkVisibleArea *v3; // rbx
  unsigned int v4; // er14
  __int64 v5; // rsi
  float v6; // xmm10_4
  float v7; // xmm8_4
  float v8; // xmm11_4
  float v9; // xmm12_4
  UFG::RoadNetworkResource *v10; // rcx
  UFG::RoadNetworkSegment *v11; // rax
  UFG::RoadNetworkSegment *v12; // rbp
  float v13; // xmm6_4
  UFG::RoadNetworkSubSegment *v14; // rax
  float *v15; // rcx
  UFG::RoadNetworkNode *v16; // rcx
  bool result; // al
  UFG::RoadNetworkSubSegment *v18; // rcx
  char *v19; // rcx
  signed __int64 v20; // rdx
  UFG::qVector3 nodePos; // [rsp+30h] [rbp-98h]
  UFG::qVector3 pos; // [rsp+40h] [rbp-88h]

  v1 = FLOAT_3_4028235e38;
  v2 = 0;
  v3 = this;
  v4 = 0;
  v5 = 0i64;
  v6 = this->mStartPosition.x;
  pos.x = this->mStartPosition.x;
  v7 = FLOAT_3_4028235e38;
  v8 = this->mStartPosition.y;
  v9 = this->mStartPosition.z;
  pos.y = this->mStartPosition.y;
  pos.z = v9;
  do
  {
    v10 = v3->mRoadNetwork;
    nodePos = UFG::qVector3::msZero;
    v11 = (UFG::RoadNetworkSegment *)UFG::RoadNetworkResource::GetClosestNode(v10, &pos, v4, &nodePos, 0i64);
    v12 = v11;
    v13 = (float)((float)((float)(nodePos.y - v8) * (float)(nodePos.y - v8))
                + (float)((float)(nodePos.x - v6) * (float)(nodePos.x - v6)))
        + (float)((float)(nodePos.z - v9) * (float)(nodePos.z - v9));
    if ( v11 && v13 <= 19600.0 )
    {
      if ( v11->mType.mValue )
      {
        v3->mClosestSubSegmentCollection.p[v5] = 0i64;
        v3->mClosestNodeCollection.p[v5] = (UFG::RoadNetworkNode *)&v11->mType;
        v15 = (float *)&v3->mClosestNodeCollection.p[v5]->mType.mValue;
        if ( (float)((float)((float)((float)(v15[4] - v8) * (float)(v15[4] - v8))
                           + (float)((float)(v15[3] - v6) * (float)(v15[3] - v6)))
                   + (float)((float)(v15[5] - v9) * (float)(v15[5] - v9))) < v1 )
        {
          v1 = (float)((float)((float)(v15[4] - v8) * (float)(v15[4] - v8))
                     + (float)((float)(v15[3] - v6) * (float)(v15[3] - v6)))
             + (float)((float)(v15[5] - v9) * (float)(v15[5] - v9));
          v3->mClosestNodeFromAllTypes = (UFG::RoadNetworkNode *)v15;
        }
      }
      else
      {
        v14 = UFG::RoadNetworkSegment::GetClosestSubSegment(v11, &pos);
        v3->mClosestSubSegmentCollection.p[v5] = v14;
        v3->mClosestNodeCollection.p[v5] = (UFG::RoadNetworkNode *)&v12->mType;
        if ( v13 < v7 )
        {
          v7 = v13;
          v3->mClosestSubSegmentFromAllTypes = v14;
        }
        if ( v13 < v1 )
        {
          v1 = v13;
          v3->mClosestNodeFromAllTypes = (UFG::RoadNetworkNode *)&v12->mType;
        }
      }
    }
    else
    {
      v3->mClosestNodeCollection.p[v5] = 0i64;
      v3->mClosestSubSegmentCollection.p[v5] = 0i64;
    }
    ++v4;
    ++v5;
  }
  while ( v4 < 4 );
  v16 = v3->mClosestNodeFromAllTypes;
  if ( v16 )
  {
    if ( v16 == v3->mPreviousClosestNodeFromAllTypes )
    {
      if ( v16->mType.mValue
        || (v18 = v3->mClosestSubSegmentFromAllTypes,
            result = v18 != v3->mPreviousClosestSubSegmentFromAllTypes,
            v18 == v3->mPreviousClosestSubSegmentFromAllTypes) )
      {
        v19 = (char *)v3->mClosestSubSegmentCollection.p;
        v20 = (char *)v3->mPreviousClosestSubSegmentCollection.p - v19;
        do
        {
          result = *(_QWORD *)v19 != *(_QWORD *)&v19[v20];
          if ( result )
            break;
          ++v2;
          v19 += 8;
        }
        while ( v2 < 4 );
      }
      else
      {
        v3->mPreviousClosestSubSegmentFromAllTypes = v18;
      }
    }
    else
    {
      v3->mPreviousClosestNodeFromAllTypes = v16;
      if ( v16->mType.mValue == 1 )
        v3->mPreviousClosestSubSegmentFromAllTypes = 0i64;
      else
        v3->mPreviousClosestSubSegmentFromAllTypes = v3->mClosestSubSegmentFromAllTypes;
      result = 1;
    }
  }
  else
  {
    result = 0;
    if ( v3->mPreviousClosestNodeFromAllTypes )
      result = 1;
  }
  return result;
}

// File Line: 486
// RVA: 0xE0FC0
bool __fastcall UFG::RoadNetworkVisibleArea::Update(UFG::RoadNetworkVisibleArea *this, UFG::qArray<UFG::RoadNetworkSubSegment *,0> *deactivateSubSegments, UFG::qArray<UFG::RoadNetworkSubSegment *,0> *activateSubSegments)
{
  return UFG::RoadNetworkVisibleArea::UpdateByEdges(this, deactivateSubSegments, activateSubSegments);
}

// File Line: 492
// RVA: 0xDBD10
UFG::qVector3 *__fastcall UFG::RoadNetworkVisibleArea::GetSubjectPosition(UFG::RoadNetworkVisibleArea *this, UFG::qVector3 *result)
{
  UFG::TransformNodeComponent *v2; // rdi
  UFG::qVector3 *v3; // rbx
  UFG::qVector3 *v4; // rax
  float v5; // xmm1_4
  float v6; // xmm0_4

  v2 = (UFG::TransformNodeComponent *)LocalPlayer;
  v3 = result;
  if ( LocalPlayer )
    v2 = LocalPlayer->m_pTransformNodeComponent;
  if ( v2 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v2);
    v3->x = v2->mWorldTransform.v3.x;
    v3->y = v2->mWorldTransform.v3.y;
    v3->z = v2->mWorldTransform.v3.z;
    v4 = v3;
  }
  else
  {
    v5 = UFG::qVector3::msZero.y;
    v4 = result;
    result->x = UFG::qVector3::msZero.x;
    v6 = UFG::qVector3::msZero.z;
    result->y = v5;
    result->z = v6;
  }
  return v4;
}

// File Line: 528
// RVA: 0xDBDA0
void __fastcall UFG::RoadNetworkVisibleArea::GetSubjectSpeed(UFG::RoadNetworkVisibleArea *this)
{
  UFG::SimObjectCharacter *v1; // rbx
  unsigned __int16 v2; // cx
  UFG::CharacterSubjectComponent *v3; // rax
  unsigned __int16 v4; // cx
  UFG::CharacterOccupantComponent *v5; // rax
  UFG::SimObjectGame *v6; // rax
  unsigned __int16 v7; // dx
  UFG::PhysicsMoverInterface *v8; // rax

  v1 = LocalPlayer;
  if ( LocalPlayer )
  {
    v2 = LocalPlayer->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(LocalPlayer);
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
        v3 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                 UFG::CharacterSubjectComponent::_TypeUID);
      else
        v3 = (UFG::CharacterSubjectComponent *)((v2 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                                   UFG::CharacterSubjectComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::CharacterSubjectComponent::_TypeUID));
    }
    else
    {
      v3 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                               UFG::CharacterSubjectComponent::_TypeUID);
    }
    if ( v3 )
    {
      ((void (__fastcall *)(UFG::CharacterSubjectComponent *))v3->vfptr[28].__vecDelDtor)(v3);
      v4 = v1->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = (UFG::CharacterOccupantComponent *)v1->m_Components.p[44].m_pComponent;
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          v5 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v1->vfptr,
                                                    UFG::CharacterOccupantComponent::_TypeUID);
        else
          v5 = (UFG::CharacterOccupantComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      (UFG::SimObjectGame *)&v1->vfptr,
                                                                      UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
      }
      else
      {
        v5 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&v1->vfptr,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      }
      if ( v5 )
      {
        v6 = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v5);
        if ( v6 )
        {
          v7 = v6->m_Flags;
          if ( !((v7 >> 14) & 1) )
          {
            if ( (v7 & 0x8000u) == 0 )
            {
              if ( (v7 >> 13) & 1 )
                return;
              if ( (v7 >> 12) & 1 )
                v8 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                     v6,
                                                     UFG::PhysicsMoverInterface::_TypeUID);
              else
                v8 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                                     (UFG::SimObject *)&v6->vfptr,
                                                     UFG::PhysicsMoverInterface::_TypeUID);
            }
            else
            {
              v8 = (UFG::PhysicsMoverInterface *)v6->m_Components.p[34].m_pComponent;
            }
            if ( v8 )
              UFG::PhysicsMoverInterface::GetLinearVelocityMagnitude(v8);
          }
        }
      }
    }
  }
}

// File Line: 562
// RVA: 0xDB600
UFG::qVector3 *__fastcall UFG::RoadNetworkVisibleArea::GetPreviousStartPosition(UFG::RoadNetworkVisibleArea *this, UFG::qVector3 *result)
{
  result->x = this->mPreviousStartPosition.x;
  result->y = this->mPreviousStartPosition.y;
  result->z = this->mPreviousStartPosition.z;
  return result;
}

// File Line: 567
// RVA: 0xDBCE0
UFG::qVector3 *__fastcall UFG::RoadNetworkVisibleArea::GetStartPosition(UFG::RoadNetworkVisibleArea *this, UFG::qVector3 *result)
{
  result->x = this->mStartPosition.x;
  result->y = this->mStartPosition.y;
  result->z = this->mStartPosition.z;
  return result;
}

// File Line: 584
// RVA: 0xD2A80
__int64 __fastcall UFG::RoadNetworkVisibleArea::BuildVisibleRoadNetworkByGrid(UFG::RoadNetworkVisibleArea *this, UFG::RoadNetworkNode *closestNode, unsigned int roadNetworkType)
{
  unsigned int v3; // ebx
  UFG::RoadNetworkVisibleArea *v4; // r14
  unsigned __int8 v5; // r15
  bool v6; // al
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm9_4
  UFG::RoadNetworkSegment **v11; // rdi
  UFG::RoadNetworkSegment **v12; // r12
  __int64 v13; // r13
  UFG::RoadNetworkSegment *v14; // rdi
  unsigned int v15; // edx
  unsigned int v16; // esi
  UFG::qBaseTreeRB *v17; // rbx
  UFG::RoadNetworkSubSegment *i; // rbx
  Render::SkinningCacheNode *v19; // rbx
  UFG::qVector3 pos; // [rsp+30h] [rbp-A8h]
  UFG::qArray<UFG::RoadNetworkSegment *,0> segments; // [rsp+40h] [rbp-98h]
  UFG::qVector3 nodePos; // [rsp+50h] [rbp-88h]
  __int64 v24; // [rsp+60h] [rbp-78h]
  __int64 v25; // [rsp+68h] [rbp-70h]
  UFG::qBaseTreeRB v26; // [rsp+70h] [rbp-68h]
  UFG::qBaseTreeRB *v27; // [rsp+118h] [rbp+40h]

  v26.mNULL.mChild[0] = (UFG::qBaseNodeRB *)-2i64;
  v3 = roadNetworkType;
  v4 = this;
  v5 = 0;
  segments.p = 0i64;
  *(_QWORD *)&segments.size = 0i64;
  v25 = 0i64;
  v24 = 0i64;
  v6 = roadNetworkType - 2 <= 1;
  v7 = FLOAT_110_0;
  if ( v6 )
    v7 = FLOAT_200_0;
  v8 = this->mStartPosition.x;
  v9 = this->mStartPosition.y;
  v10 = this->mStartPosition.z;
  pos.x = this->mStartPosition.x;
  pos.y = v9;
  pos.z = v10;
  if ( v6 )
  {
    nodePos = UFG::qVector3::msZero;
    if ( UFG::RoadNetworkResource::GetClosestNode(this->mRoadNetwork, &pos, roadNetworkType, &nodePos, 0i64) )
    {
      v8 = nodePos.x;
      pos = nodePos;
      v9 = nodePos.y;
      v10 = nodePos.z;
    }
  }
  UFG::RoadNetworkResource::GetSegmentsInGrid(v4->mRoadNetwork, &segments, &pos, v3, v7);
  v27 = &v26;
  UFG::qBaseTreeRB::qBaseTreeRB(&v26);
  v11 = segments.p;
  if ( segments.size )
  {
    v12 = segments.p;
    v13 = segments.size;
    do
    {
      v14 = *v12;
      v15 = (*v12)->mIndex;
      if ( !v15 || !UFG::qBaseTreeRB::Get(&v26, v15) )
      {
        v16 = v14->mIndex;
        if ( !v16 || (v17 = UFG::qBaseTreeRB::Get(&v26, v16)) == 0i64 )
        {
          v17 = (UFG::qBaseTreeRB *)UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
          v27 = v17;
          if ( v17 )
          {
            v17->mRoot.mParent = 0i64;
            v17->mRoot.mChild[0] = 0i64;
            v17->mRoot.mChild[1] = 0i64;
            v17->mRoot.mUID = v16;
            v17->mNULL.mParent = (UFG::qBaseNodeRB *)v14;
          }
          else
          {
            v17 = 0i64;
          }
          UFG::qBaseTreeRB::Add(&v26, &v17->mRoot);
        }
        v17->mNULL.mParent = (UFG::qBaseNodeRB *)v14;
        for ( i = (UFG::RoadNetworkSubSegment *)v14->mSubSegmentCollection.mNode.mNext;
              i != (UFG::RoadNetworkSubSegment *)&v14->mSubSegmentCollection;
              i = (UFG::RoadNetworkSubSegment *)i->mNext )
        {
          if ( !i->mActive
            && (float)(v7 * v7) > (float)((float)((float)((float)(v8 - i->mPosition.x) * (float)(v8 - i->mPosition.x))
                                                + (float)((float)(v9 - i->mPosition.y) * (float)(v9 - i->mPosition.y)))
                                        + (float)((float)(v10 - i->mPosition.z) * (float)(v10 - i->mPosition.z))) )
          {
            v5 = 1;
            UFG::RoadNetworkVisibleArea::CreateEdges(v4, i);
            while ( !UFG::RoadNetworkVisibleAreaEdgeManager::ExpandOneStep(&v4->mEdgeManager) )
              ;
          }
        }
      }
      ++v12;
      --v13;
    }
    while ( v13 );
    v11 = segments.p;
  }
  v27 = &v26;
  while ( v26.mRoot.mUID )
  {
    v19 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v26);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)&v26, &v19->mNode);
    operator delete[](v19);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v26);
  v25 = 0i64;
  v24 = 0i64;
  if ( v11 )
    operator delete[](v11);
  return v5;
}

// File Line: 649
// RVA: 0xD58A0
bool __fastcall UFG::RoadNetworkVisibleArea::GenerateOceanVisibleArea(UFG::RoadNetworkVisibleArea *this)
{
  UFG::RoadNetworkNode **v1; // rax
  UFG::RoadNetworkVisibleArea *v2; // rbx
  UFG::RoadNetworkNode *v3; // rdi
  bool result; // al

  v1 = this->mClosestNodeCollection.p;
  v2 = this;
  v3 = v1[3];
  if ( v3 )
  {
    result = UFG::RoadNetworkVisibleArea::BuildVisibleRoadNetworkByGrid(this, v1[3], 3u);
    if ( v3->mType.mValue == 1 )
    {
      *((_QWORD *)v2->mPreviousClosestNodeCollection.p + 3) = *((_QWORD *)v2->mClosestNodeCollection.p + 3);
      *((_QWORD *)v2->mPreviousClosestSubSegmentCollection.p + 3) = 0i64;
    }
    else
    {
      *((_QWORD *)v2->mPreviousClosestNodeCollection.p + 3) = *((_QWORD *)v2->mClosestNodeCollection.p + 3);
      *((_QWORD *)v2->mPreviousClosestSubSegmentCollection.p + 3) = *((_QWORD *)v2->mClosestSubSegmentCollection.p + 3);
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
float __fastcall UFG::RoadNetworkVisibleArea::GetValidDistance(UFG::RoadNetworkVisibleArea *this, UFG::qVector3 *position, bool extensionAllowed, bool useSafetyMargin, bool isWater)
{
  float v5; // xmm6_4
  bool v6; // r14
  bool v7; // bp
  UFG::qVector3 *v8; // rbx
  UFG::RoadNetworkVisibleArea *v9; // rsi
  bool v10; // di
  bool v11; // al
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm2_4

  v5 = this->mCurrentVisibleDistance;
  v6 = useSafetyMargin;
  v7 = extensionAllowed;
  v8 = position;
  v9 = this;
  v10 = UFG::RoadNetworkVisibleArea::IsWithinVisibleAngle(this, position);
  v11 = UFG::RoadNetworkVisibleArea::IsWithinVisibleExpandAngle(v9, v8);
  if ( isWater )
  {
    v10 = 1;
    v11 = 1;
  }
  else if ( !v10 )
  {
    goto LABEL_8;
  }
  if ( !v7 )
  {
LABEL_8:
    if ( !v11 )
      goto LABEL_15;
    v12 = (float)((float)(v9->mStartSpeed * 3.5999999) - 23.0) * 1.5217391;
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
    v5 = v5 + v13;
    goto LABEL_15;
  }
  if ( isWater )
    v5 = v5 + 490.0;
  else
    v5 = v5 + 60.0;
LABEL_15:
  if ( v10 || v7 )
    goto LABEL_29;
  v14 = (float)((float)(v9->mStartSpeed * 3.5999999) - 23.0) * 0.86956519;
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
  v16 = v5 - v15;
  if ( isWater )
    v17 = FLOAT_100_0;
  else
    v17 = Twk_RN_VisAreaMinVisibleDistanceDelta;
  v5 = v9->mCurrentVisibleDistance - v17;
  if ( v5 < 0.0 )
    v5 = 0.0;
  if ( v5 <= v16 )
    v5 = v16;
LABEL_29:
  if ( v6 )
    v5 = v5 + -5.0;
  return v5;
}

// File Line: 784
// RVA: 0xDE4B0
bool __fastcall UFG::RoadNetworkVisibleArea::IsInRange(UFG::RoadNetworkVisibleArea *this, UFG::RoadNetworkIntersection *roadInter, UFG::qVector3 *position)
{
  UFG::RoadNetworkSubSegment *v3; // rax
  UFG::qVector3 *v4; // r14
  UFG::RoadNetworkIntersection *v5; // rbp
  UFG::RoadNetworkVisibleArea *v6; // rbx
  char v7; // r9
  UFG::RoadNetworkIntersection *v8; // rcx
  bool v9; // di
  bool isWater; // al
  float v11; // xmm0_4

  v3 = this->mPreviousClosestSubSegmentFromAllTypes;
  v4 = position;
  v5 = roadInter;
  v6 = this;
  if ( v3 )
  {
    v7 = (*(_DWORD *)&v3->mParentNode->mBits >> 6) & 1;
  }
  else
  {
    v8 = (UFG::RoadNetworkIntersection *)this->mPreviousClosestNodeFromAllTypes;
    if ( !v8 )
    {
LABEL_7:
      v9 = 0;
      goto LABEL_8;
    }
    v7 = UFG::RoadNetworkIntersection::GetExtendBeyondVisibleAreaLimit(v8);
  }
  if ( !v7 )
    goto LABEL_7;
  v9 = 1;
  if ( !UFG::RoadNetworkIntersection::GetExtendBeyondVisibleAreaLimit(v5) )
    goto LABEL_7;
LABEL_8:
  isWater = UFG::RoadNetworkIntersection::IsWater(v5);
  v11 = UFG::RoadNetworkVisibleArea::GetValidDistance(v6, v4, v9, 0, isWater);
  return (float)(v11 * v11) > (float)((float)((float)((float)(v6->mStartPosition.y - v4->y)
                                                    * (float)(v6->mStartPosition.y - v4->y))
                                            + (float)((float)(v6->mStartPosition.x - v4->x)
                                                    * (float)(v6->mStartPosition.x - v4->x)))
                                    + (float)((float)(v6->mStartPosition.z - v4->z)
                                            * (float)(v6->mStartPosition.z - v4->z)));
}

// File Line: 790
// RVA: 0xDE5A0
bool __fastcall UFG::RoadNetworkVisibleArea::IsInRange(UFG::RoadNetworkVisibleArea *this, UFG::RoadNetworkSegment *roadSeg, UFG::qVector3 *position)
{
  UFG::qVector3 *v3; // r15
  UFG::RoadNetworkSegment *v4; // rbx
  bool v5; // r14
  UFG::RoadNetworkVisibleArea *v6; // rsi
  unsigned int v7; // edi
  UFG::qPropertySet *v8; // rax
  unsigned int *v9; // rax
  UFG::RoadNetworkSubSegment *v10; // rax
  bool isWater; // di
  char v12; // cl
  UFG::RoadNetworkIntersection *v13; // rcx
  float v14; // xmm0_4

  v3 = position;
  v4 = roadSeg;
  v5 = 1;
  v6 = this;
  if ( roadSeg->mpPropertySetCached )
  {
    v7 = roadSeg->mRoadNetworkType.mValue;
  }
  else
  {
    v8 = UFG::RoadNetworkSegment::GetRoadPropertySet(roadSeg);
    v7 = 0;
    if ( v8 )
    {
      v9 = UFG::qPropertySet::Get<unsigned long>(v8, (UFG::qSymbol *)&qSymbol_RoadNetworkType.mUID, DEPTH_RECURSE);
      if ( v9 )
        v7 = *v9;
    }
  }
  v10 = v6->mPreviousClosestSubSegmentFromAllTypes;
  isWater = v7 - 2 <= 1;
  if ( v10 )
  {
    v12 = (*(_DWORD *)&v10->mParentNode->mBits >> 6) & 1;
  }
  else
  {
    v13 = (UFG::RoadNetworkIntersection *)v6->mPreviousClosestNodeFromAllTypes;
    if ( !v13 )
    {
LABEL_12:
      v5 = 0;
      goto LABEL_13;
    }
    v12 = UFG::RoadNetworkIntersection::GetExtendBeyondVisibleAreaLimit(v13);
  }
  if ( !v12 || !((*(_DWORD *)&v4->mBits >> 6) & 1) )
    goto LABEL_12;
LABEL_13:
  v14 = UFG::RoadNetworkVisibleArea::GetValidDistance(v6, v3, v5, 0, isWater);
  return (float)(v14 * v14) > (float)((float)((float)((float)(v6->mStartPosition.y - v3->y)
                                                    * (float)(v6->mStartPosition.y - v3->y))
                                            + (float)((float)(v6->mStartPosition.x - v3->x)
                                                    * (float)(v6->mStartPosition.x - v3->x)))
                                    + (float)((float)(v6->mStartPosition.z - v3->z)
                                            * (float)(v6->mStartPosition.z - v3->z)));
}

// File Line: 796
// RVA: 0xDEC60
bool __fastcall UFG::RoadNetworkVisibleArea::IsSubSegmentInRange(UFG::RoadNetworkVisibleArea *this, UFG::RoadNetworkSubSegment *subSegment)
{
  UFG::RoadNetworkSegment *v2; // rbp
  UFG::RoadNetworkSubSegment *v3; // r15
  UFG::RoadNetworkConnection *v4; // rdi
  UFG::RoadNetworkVisibleArea *v5; // r12
  __int64 v6; // r14
  float v7; // xmm6_4
  __int64 v8; // rax
  signed __int64 v9; // rax
  signed __int64 v10; // rcx
  __int64 v11; // rax
  signed __int64 v12; // rsi
  signed __int64 v13; // rax
  __int64 v14; // rcx
  UFG::RoadNetworkConnection *v15; // rcx
  UFG::qBezierPathMemImaged *v16; // rax
  UFG::RoadNetworkConnection *v17; // rbx
  unsigned int v18; // eax
  UFG::qBezierSplineMemImaged *v19; // rax
  float v21; // xmm6_4
  __int64 v22; // rax
  signed __int64 v23; // rax
  signed __int64 v24; // rcx
  __int64 v25; // rax
  signed __int64 v26; // rsi
  signed __int64 v27; // rax
  __int64 v28; // rcx
  UFG::qBezierPathMemImaged *v29; // rax
  UFG::RoadNetworkConnection *v30; // rbx
  unsigned int v31; // eax
  UFG::qBezierSplineMemImaged *v32; // rax
  UFG::qVector3 result; // [rsp+20h] [rbp-48h]
  float splineT; // [rsp+78h] [rbp+10h]

  v2 = subSegment->mParentNode;
  v3 = subSegment;
  v4 = 0i64;
  v5 = this;
  v6 = ((unsigned __int8)v2->mNumLanes - 1) / 2;
  v7 = subSegment->mBeginTCollection[v6];
  v8 = v2->mLane.mOffset;
  if ( v8 )
    v9 = (signed __int64)&v2->mLane + v8;
  else
    v9 = 0i64;
  v10 = v9 + 8 * v6;
  v11 = *(_QWORD *)(v9 + 8 * v6);
  v12 = v11 + v10;
  if ( !v11 )
    v12 = 0i64;
  if ( *(_QWORD *)v12 )
    v13 = v12 + *(_QWORD *)v12;
  else
    v13 = 0i64;
  v14 = *(_QWORD *)(v13 + 32);
  if ( v14 )
    v15 = (UFG::RoadNetworkConnection *)(v13 + v14 + 32);
  else
    v15 = 0i64;
  v16 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v15, *(unsigned __int16 *)(v12 + 38));
  v17 = (UFG::RoadNetworkConnection *)v16;
  v18 = UFG::qBezierPathMemImaged::GetSplineParameters(v16, v7, &splineT);
  v19 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v17, v18);
  UFG::RoadNetworkLane::GetOffsetPos(&result, v19, splineT, *(float *)(v12 + 40));
  if ( UFG::RoadNetworkVisibleArea::IsInRange(v5, v2, &result) )
    return 1;
  v21 = v3->mEndTCollection[v6];
  v22 = v2->mLane.mOffset;
  if ( v22 )
    v23 = (signed __int64)&v2->mLane + v22;
  else
    v23 = 0i64;
  v24 = v23 + 8 * v6;
  v25 = *(_QWORD *)(v23 + 8 * v6);
  v26 = v25 + v24;
  if ( !v25 )
    v26 = 0i64;
  if ( *(_QWORD *)v26 )
    v27 = v26 + *(_QWORD *)v26;
  else
    v27 = 0i64;
  v28 = *(_QWORD *)(v27 + 32);
  if ( v28 )
    v4 = (UFG::RoadNetworkConnection *)(v28 + v27 + 32);
  v29 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v4, *(unsigned __int16 *)(v26 + 38));
  v30 = (UFG::RoadNetworkConnection *)v29;
  v31 = UFG::qBezierPathMemImaged::GetSplineParameters(v29, v21, &splineT);
  v32 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v30, v31);
  UFG::RoadNetworkLane::GetOffsetPos(&result, v32, splineT, *(float *)(v26 + 40));
  return UFG::RoadNetworkVisibleArea::IsInRange(v5, v2, &result);
}

// File Line: 810
// RVA: 0xDE6C0
bool __fastcall UFG::RoadNetworkVisibleArea::IsNearStartPosition(UFG::RoadNetworkVisibleArea *this, UFG::qVector3 *pos, float maxDistance)
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
signed __int64 __fastcall UFG::RoadNetworkVisibleArea::AllowVisibleExtension(UFG::RoadNetworkVisibleArea *this, UFG::RoadNetworkNode *roadNode)
{
  UFG::RoadNetworkSubSegment *v2; // rax
  UFG::RoadNetworkNode *v3; // rbx
  bool v4; // cl
  UFG::RoadNetworkIntersection *v5; // rcx
  bool v6; // zf
  bool v7; // cl
  UFG::RoadNetworkIntersection *v8; // rcx

  v2 = this->mPreviousClosestSubSegmentFromAllTypes;
  v3 = roadNode;
  if ( roadNode->mType.mValue == 1 )
  {
    if ( v2 )
    {
      v4 = (*(_DWORD *)&v2->mParentNode->mBits >> 6) & 1;
    }
    else
    {
      v5 = (UFG::RoadNetworkIntersection *)this->mPreviousClosestNodeFromAllTypes;
      if ( !v5 )
        return 0i64;
      v4 = UFG::RoadNetworkIntersection::GetExtendBeyondVisibleAreaLimit(v5);
    }
    if ( !v4 )
      return 0i64;
    v6 = UFG::RoadNetworkIntersection::GetExtendBeyondVisibleAreaLimit((UFG::RoadNetworkIntersection *)v3) == 0;
  }
  else
  {
    if ( v2 )
    {
      v7 = (*(_DWORD *)&v2->mParentNode->mBits >> 6) & 1;
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
    v6 = ((LODWORD(v3[1].mOutgoingConnections.mOffset) >> 6) & 1) == 0;
  }
  if ( !v6 )
    return 1i64;
  return 0i64;
}

// File Line: 894
// RVA: 0xDF1C0
bool __fastcall UFG::RoadNetworkVisibleArea::IsWithinVisibleExpandAngle(UFG::RoadNetworkVisibleArea *this, UFG::qVector3 *pos)
{
  __m128 v2; // xmm5
  UFG::RoadNetworkVisibleArea *v3; // rbx
  float v4; // xmm6_4
  float v5; // xmm7_4
  __m128 v6; // xmm3
  float v7; // xmm1_4
  float v8; // xmm3_4
  __m128 v9; // xmm5
  float v10; // xmm6_4
  __m128 v11; // xmm7
  float v12; // xmm2_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  UFG::qVector3 n2; // [rsp+20h] [rbp-48h]
  UFG::qVector3 n1; // [rsp+30h] [rbp-38h]

  v2 = (__m128)LODWORD(this->mStartDirection.x);
  v6 = v2;
  v3 = this;
  v4 = this->mStartDirection.y;
  v5 = this->mStartDirection.z;
  v6.m128_f32[0] = (float)((float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(v4 * v4)) + (float)(v5 * v5);
  if ( v6.m128_f32[0] == 0.0 )
    v7 = 0.0;
  else
    v7 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v6));
  v8 = pos->x - this->mStartPosition.x;
  n1.z = v5 * v7;
  n1.x = v2.m128_f32[0] * v7;
  v9 = (__m128)LODWORD(pos->y);
  v9.m128_f32[0] = v9.m128_f32[0] - this->mStartPosition.y;
  n1.y = v4 * v7;
  v11 = v9;
  v10 = pos->z - this->mStartPosition.z;
  v11.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v8 * v8)) + (float)(v10 * v10);
  if ( v11.m128_f32[0] == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
  n2.x = v8 * v12;
  n2.y = v9.m128_f32[0] * v12;
  n2.z = v10 * v12;
  v13 = FLOAT_3_1415927;
  LODWORD(v14) = COERCE_UNSIGNED_INT(UFG::qAngleBetweenNormals(&n1, &n2)) & _xmm;
  if ( (float)(v3->mStartSpeed * 3.5999999) > 23.0 )
    v13 = FLOAT_0_61086524;
  return v13 >= v14;
}

// File Line: 904
// RVA: 0xDF070
bool __fastcall UFG::RoadNetworkVisibleArea::IsWithinVisibleAngle(UFG::RoadNetworkVisibleArea *this, UFG::qVector3 *pos)
{
  __m128 v2; // xmm5
  UFG::RoadNetworkVisibleArea *v3; // rbx
  float v4; // xmm6_4
  float v5; // xmm7_4
  __m128 v6; // xmm3
  float v7; // xmm1_4
  float v8; // xmm3_4
  __m128 v9; // xmm5
  float v10; // xmm6_4
  __m128 v11; // xmm7
  float v12; // xmm2_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  UFG::qVector3 n2; // [rsp+20h] [rbp-48h]
  UFG::qVector3 n1; // [rsp+30h] [rbp-38h]

  v2 = (__m128)LODWORD(this->mStartDirection.x);
  v6 = v2;
  v3 = this;
  v4 = this->mStartDirection.y;
  v5 = this->mStartDirection.z;
  v6.m128_f32[0] = (float)((float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(v4 * v4)) + (float)(v5 * v5);
  if ( v6.m128_f32[0] == 0.0 )
    v7 = 0.0;
  else
    v7 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v6));
  v8 = pos->x - this->mStartPosition.x;
  n1.z = v5 * v7;
  n1.x = v2.m128_f32[0] * v7;
  v9 = (__m128)LODWORD(pos->y);
  v9.m128_f32[0] = v9.m128_f32[0] - this->mStartPosition.y;
  n1.y = v4 * v7;
  v11 = v9;
  v10 = pos->z - this->mStartPosition.z;
  v11.m128_f32[0] = (float)((float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v8 * v8)) + (float)(v10 * v10);
  if ( v11.m128_f32[0] == 0.0 )
    v12 = 0.0;
  else
    v12 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
  n2.x = v8 * v12;
  n2.y = v9.m128_f32[0] * v12;
  n2.z = v10 * v12;
  v13 = FLOAT_3_1415927;
  LODWORD(v14) = COERCE_UNSIGNED_INT(UFG::qAngleBetweenNormals(&n1, &n2)) & _xmm;
  if ( (float)(v3->mStartSpeed * 3.5999999) > 23.0 )
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
    result = 0.0;
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
char __fastcall UFG::RoadNetworkVisibleArea::ShouldUpdateVisibleArea(UFG::RoadNetworkVisibleArea *this)
{
  UFG::TransformNodeComponent *v1; // rdi
  UFG::RoadNetworkVisibleArea *v2; // rbx
  UFG::TransformNodeComponent *v3; // rsi
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  char result; // al

  v1 = 0i64;
  v2 = this;
  if ( LocalPlayer )
    v3 = LocalPlayer->m_pTransformNodeComponent;
  else
    v3 = 0i64;
  if ( v3 )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform(v3);
    v4 = v3->mWorldTransform.v3.x;
    v5 = v3->mWorldTransform.v3.y;
    v6 = v3->mWorldTransform.v3.z;
    v7 = UFG::qVector3::msZero.z;
    v8 = UFG::qVector3::msZero.y;
    v9 = UFG::qVector3::msZero.x;
  }
  else
  {
    v9 = UFG::qVector3::msZero.x;
    v8 = UFG::qVector3::msZero.y;
    v7 = UFG::qVector3::msZero.z;
    v4 = UFG::qVector3::msZero.x;
    v5 = UFG::qVector3::msZero.y;
    v6 = UFG::qVector3::msZero.z;
  }
  if ( v2->mForceVisibleAreaUpdate )
  {
    v2->mForceVisibleAreaUpdate = 0;
  }
  else if ( (v9 != v2->mStartPosition.x || v8 != v2->mStartPosition.y || v7 != v2->mStartPosition.z)
         && (float)((float)((float)((float)(v5 - v2->mStartPosition.y) * (float)(v5 - v2->mStartPosition.y))
                          + (float)((float)(v4 - v2->mStartPosition.x) * (float)(v4 - v2->mStartPosition.x)))
                  + (float)((float)(v6 - v2->mStartPosition.z) * (float)(v6 - v2->mStartPosition.z))) <= 100.0 )
  {
    return 0;
  }
  v10 = v2->mStartPosition.y;
  v11 = v2->mStartPosition.z;
  v2->mPreviousStartPosition.x = v2->mStartPosition.x;
  v2->mPreviousStartPosition.y = v10;
  v2->mPreviousStartPosition.z = v11;
  v2->mStartPosition.x = v4;
  v2->mStartPosition.y = v5;
  v2->mStartPosition.z = v6;
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
  v2->mStartDirection.x = v12;
  v2->mStartDirection.y = v13;
  v2->mStartDirection.z = v14;
  UFG::RoadNetworkVisibleArea::GetSubjectSpeed(v2);
  result = 1;
  v2->mStartSpeed = v12;
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
char __fastcall UFG::RoadNetworkVisibleArea::UpdateByEdges(UFG::RoadNetworkVisibleArea *this, UFG::qArray<UFG::RoadNetworkSubSegment *,0> *deactivateSubSegments, UFG::qArray<UFG::RoadNetworkSubSegment *,0> *activateSubSegments)
{
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v3; // rsi
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v4; // rbp
  UFG::RoadNetworkVisibleArea *v5; // rbx
  char v6; // di
  char v7; // di

  v3 = activateSubSegments;
  v4 = deactivateSubSegments;
  v5 = this;
  if ( !UFG::RoadNetworkVisibleArea::ShouldUpdateVisibleArea(this) )
    return 0;
  UFG::RoadNetworkVisibleArea::ClearLastVisibleArea(v5);
  UFG::RoadNetworkVisibleArea::UpdateClosestRoadNetworkNodes(v5);
  v6 = UFG::RoadNetworkVisibleArea::GenerateLandVisibleArea(v5);
  v7 = UFG::RoadNetworkVisibleArea::GenerateOceanVisibleArea(v5) | v6;
  if ( v7 )
    UFG::RoadNetworkVisibleArea::UpdateVisibleArea(v5, v4, v3);
  return v7;
}

// File Line: 1031
// RVA: 0xD5760
__int64 __fastcall UFG::RoadNetworkVisibleArea::GenerateLandVisibleArea(UFG::RoadNetworkVisibleArea *this)
{
  unsigned __int8 v1; // r15
  UFG::RoadNetworkVisibleArea *v2; // rbx
  unsigned int v3; // er14
  __int64 v4; // rdi
  UFG::RoadNetworkNode **v5; // rax
  UFG::RoadNetworkNode *v6; // rsi
  bool v7; // al

  v1 = 0;
  v2 = this;
  v3 = 0;
  v4 = 0i64;
  do
  {
    v5 = v2->mClosestNodeCollection.p;
    v6 = v5[v4];
    if ( v3 != 3 )
    {
      if ( v6 )
      {
        if ( v6->mType.mValue == 1 )
          v7 = UFG::RoadNetworkIntersection::GetBuildVisibleRoadNetworkByGrid((UFG::RoadNetworkIntersection *)v5[v4]);
        else
          v7 = (LODWORD(v6[1].mOutgoingConnections.mOffset) >> 5) & 1;
        if ( v7 )
        {
          v1 |= UFG::RoadNetworkVisibleArea::BuildVisibleRoadNetworkByGrid(v2, v6, v3);
        }
        else
        {
          v1 |= 1u;
          if ( v6->mType.mValue == 1 )
            UFG::RoadNetworkVisibleArea::CreateEdges(v2, (UFG::RoadNetworkIntersection *)v6);
          else
            UFG::RoadNetworkVisibleArea::CreateEdges(v2, v2->mClosestSubSegmentCollection.p[v4]);
          while ( !UFG::RoadNetworkVisibleAreaEdgeManager::ExpandOneStep(&v2->mEdgeManager) )
            ;
        }
        if ( v6->mType.mValue == 1 )
        {
          v2->mPreviousClosestNodeCollection.p[v4] = v2->mClosestNodeCollection.p[v4];
          v2->mPreviousClosestSubSegmentCollection.p[v4] = 0i64;
        }
        else
        {
          v2->mPreviousClosestNodeCollection.p[v4] = v2->mClosestNodeCollection.p[v4];
          v2->mPreviousClosestSubSegmentCollection.p[v4] = v2->mClosestSubSegmentCollection.p[v4];
        }
      }
      else
      {
        v2->mPreviousClosestNodeCollection.p[v4] = 0i64;
        v2->mPreviousClosestSubSegmentCollection.p[v4] = 0i64;
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
void __fastcall UFG::RoadNetworkVisibleArea::UpdateVisibleArea(UFG::RoadNetworkVisibleArea *this, UFG::qArray<UFG::RoadNetworkSubSegment *,0> *deactivateSubSegments, UFG::qArray<UFG::RoadNetworkSubSegment *,0> *activateSubSegments)
{
  __int64 v3; // r12
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v4; // r14
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v5; // rdi
  UFG::RoadNetworkVisibleArea *v6; // r13
  UFG::RoadNetworkSubSegment **v7; // rcx
  UFG::RoadNetworkSubSegment *v8; // r8
  signed __int64 v9; // rax
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v10; // rcx
  unsigned int v11; // edx
  unsigned int v12; // eax
  UFG::RoadNetworkSubSegment **v13; // rcx
  __int64 v14; // r15
  unsigned int v15; // ebx
  unsigned int v16; // esi
  unsigned int v17; // ebx
  unsigned __int64 v18; // rax
  char *v19; // rax
  char *v20; // rbp
  signed __int64 v21; // r9
  signed __int64 v22; // r8
  UFG::RoadNetworkSubSegment **v23; // rcx
  __int64 v24; // r12
  unsigned int v25; // eax
  UFG::RoadNetworkSubSegment *v26; // rbp
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v27; // rcx
  unsigned int v28; // edx
  UFG::RoadNetworkSubSegment **v29; // rcx
  __int64 v30; // r15
  unsigned int v31; // ebx
  unsigned int v32; // edi
  unsigned int v33; // ebx
  unsigned __int64 v34; // rax
  char *v35; // rax
  char *v36; // rsi
  signed __int64 v37; // r9
  signed __int64 v38; // r8
  UFG::RoadNetworkSubSegment **v39; // rax
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v40; // rcx
  UFG::qArray<UFG::RoadNetworkNode *,0> *v41; // rcx
  UFG::RoadNetworkSubSegment **v42; // [rsp+60h] [rbp+8h]
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v43; // [rsp+70h] [rbp+18h]

  v43 = activateSubSegments;
  v3 = 0i64;
  v4 = activateSubSegments;
  v5 = deactivateSubSegments;
  v6 = this;
  if ( this->mPreviousVisibleSubSegments->size )
  {
    do
    {
      v7 = v6->mPreviousVisibleSubSegments->p;
      v8 = v7[v3];
      v9 = (signed __int64)&v7[v3];
      v10 = v6->mCurrentVisibleSubSegments;
      v11 = v10->size;
      v42 = (UFG::RoadNetworkSubSegment **)v9;
      v12 = 0;
      if ( !v10->size )
        goto LABEL_8;
      v13 = v10->p;
      while ( v8 != *v13 )
      {
        ++v12;
        ++v13;
        if ( v12 >= v11 )
          goto LABEL_8;
      }
      if ( v12 == -1 )
      {
LABEL_8:
        v14 = v5->size;
        v15 = v5->capacity;
        v16 = v14 + 1;
        if ( (signed int)v14 + 1 > v15 )
        {
          if ( v15 )
            v17 = 2 * v15;
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
            v20 = v19;
            if ( v5->p )
            {
              v21 = 0i64;
              if ( v5->size )
              {
                do
                {
                  v22 = v21;
                  v21 = (unsigned int)(v21 + 1);
                  *(_QWORD *)&v19[v22 * 8] = v5->p[v22];
                }
                while ( (unsigned int)v21 < v5->size );
              }
              operator delete[](v5->p);
            }
            v5->p = (UFG::RoadNetworkSubSegment **)v20;
            v5->capacity = v17;
          }
        }
        v23 = v5->p;
        v5->size = v16;
        v23[v14] = *v42;
      }
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < v6->mPreviousVisibleSubSegments->size );
    v4 = v43;
  }
  v24 = 0i64;
  if ( v6->mCurrentVisibleSubSegments->size )
  {
    do
    {
      v25 = 0;
      v26 = v6->mCurrentVisibleSubSegments->p[v24];
      v27 = v6->mPreviousVisibleSubSegments;
      v28 = v27->size;
      if ( !v27->size )
        goto LABEL_36;
      v29 = v27->p;
      while ( v26 != *v29 )
      {
        ++v25;
        ++v29;
        if ( v25 >= v28 )
          goto LABEL_36;
      }
      if ( v25 == -1 )
      {
LABEL_36:
        v30 = v4->size;
        v31 = v4->capacity;
        v32 = v30 + 1;
        if ( (signed int)v30 + 1 > v31 )
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
              v37 = 0i64;
              if ( v4->size )
              {
                do
                {
                  v38 = v37;
                  v37 = (unsigned int)(v37 + 1);
                  *(_QWORD *)&v35[v38 * 8] = v4->p[v38];
                }
                while ( (unsigned int)v37 < v4->size );
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
      v24 = (unsigned int)(v24 + 1);
    }
    while ( (unsigned int)v24 < v6->mCurrentVisibleSubSegments->size );
  }
  v40 = v6->mPreviousVisibleSubSegments;
  v6->mPreviousVisibleSubSegments = v6->mCurrentVisibleSubSegments;
  v6->mCurrentVisibleSubSegments = v40;
  v40->size = 0;
  v41 = v6->mPreviousVisibleRoadNetwork;
  v6->mPreviousVisibleRoadNetwork = v6->mCurrentVisibleRoadNetwork;
  v6->mCurrentVisibleRoadNetwork = v41;
  v41->size = 0;
}

// File Line: 1150
// RVA: 0xD18B0
void __fastcall UFG::RoadNetworkVisibleArea::AddEdge(UFG::RoadNetworkVisibleArea *this, UFG::RoadNetworkSubSegment *currentSubSegment, UFG::RoadNetworkSubSegment *nextSubSegment, UFG::RoadNetworkGate *nextGate)
{
  UFG::RoadNetworkGate *v4; // rdi
  UFG::RoadNetworkSubSegment *v5; // rsi
  UFG::RoadNetworkSubSegment *v6; // rbp
  UFG::RoadNetworkVisibleArea *v7; // rbx
  char *v8; // rax

  v4 = nextGate;
  v5 = nextSubSegment;
  v6 = currentSubSegment;
  v7 = this;
  v8 = UFG::qMalloc(0x100ui64, "RoadNetworkVisibleArea.RoadNetworkVisibleAreaEdge", 0i64);
  if ( v8 )
    UFG::RoadNetworkVisibleAreaEdge::RoadNetworkVisibleAreaEdge((UFG::RoadNetworkVisibleAreaEdge *)v8, v7, v6, v5, v4);
  UFG::DaemonManager::RegisterDaemon(&v7->mEdgeManager, (UFG::RoadNetworkVisibleAreaEdge *)v8);
}

// File Line: 1165
// RVA: 0xD1840
void __fastcall UFG::RoadNetworkVisibleArea::AddEdge(UFG::RoadNetworkVisibleArea *this, UFG::RoadNetworkGate *gate, UFG::RoadNetworkVisibleAreaEdge *spawner)
{
  UFG::RoadNetworkVisibleAreaEdge *v3; // rdi
  UFG::RoadNetworkGate *v4; // rsi
  UFG::RoadNetworkVisibleArea *v5; // rbx
  char *v6; // rax

  v3 = spawner;
  v4 = gate;
  v5 = this;
  v6 = UFG::qMalloc(0x100ui64, "RoadNetworkVisibleArea.RoadNetworkVisibleAreaEdge", 0i64);
  if ( v6 )
    UFG::RoadNetworkVisibleAreaEdge::RoadNetworkVisibleAreaEdge((UFG::RoadNetworkVisibleAreaEdge *)v6, v4, v5, v3);
  UFG::DaemonManager::RegisterDaemon(&v5->mEdgeManager, (UFG::RoadNetworkVisibleAreaEdge *)v6);
}

// File Line: 1172
// RVA: 0xD3DF0
void __fastcall UFG::RoadNetworkVisibleArea::CreateEdges(UFG::RoadNetworkVisibleArea *this, UFG::RoadNetworkIntersection *intersection, UFG::RoadNetworkVisibleAreaEdge *spawner, UFG::RoadNetworkGate *spawnerGate)
{
  __int64 v4; // rbp
  UFG::RoadNetworkGate *v5; // r12
  UFG::RoadNetworkVisibleAreaEdge *v6; // r13
  UFG::RoadNetworkIntersection *v7; // r15
  UFG::RoadNetworkVisibleArea *v8; // r14
  __int64 v9; // rax
  signed __int64 v10; // rcx
  __int64 v11; // rax
  UFG::RoadNetworkGate *v12; // rdi
  __int64 v13; // rax
  UFG::RoadNetworkSegment *v14; // rbx
  char v15; // si
  unsigned int v16; // edx
  UFG::qBaseTreeRB *v17; // rax
  __int64 v18; // rax
  UFG::RoadNetworkGate *v19; // rdx

  v4 = 0i64;
  v5 = spawnerGate;
  v6 = spawner;
  v7 = intersection;
  v8 = this;
  if ( intersection->mNumGates )
  {
    do
    {
      v9 = v7->mGates.mOffset;
      if ( v9 )
        v10 = (signed __int64)&v7->mGates + v9;
      else
        v10 = 0i64;
      v11 = *(_QWORD *)(v10 + 8 * v4);
      if ( v11 )
        v12 = (UFG::RoadNetworkGate *)(v11 + v10 + 8 * v4);
      else
        v12 = 0i64;
      v13 = v12->mConnectedNode.mOffset;
      if ( v13 )
        v14 = (UFG::RoadNetworkSegment *)((char *)&v12->mConnectedNode + v13);
      else
        v14 = 0i64;
      if ( v12 != v5 && v14 )
      {
        v15 = 0;
        if ( v14->mType.mValue == 1 )
        {
          v16 = v14->mIndex;
          if ( v16 )
            v17 = UFG::qBaseTreeRB::Get(&v8->mVisitedIntersections.mTree.mTree, v16);
          else
            v17 = 0i64;
          v15 = v17 != 0i64;
        }
        if ( !v14->mType.mValue )
        {
          v18 = v12->mConnectedGate.mOffset;
          if ( v18 )
            v19 = (UFG::RoadNetworkGate *)((char *)v12 + v18 + 16);
          else
            v19 = 0i64;
          v15 |= UFG::RoadNetworkSegment::GetClosestSubSegment(v14, v19)->mActive != 0;
        }
        if ( !v15 )
          UFG::RoadNetworkVisibleArea::AddEdge(v8, v12, v6);
      }
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < (unsigned __int8)v7->mNumGates );
  }
}

// File Line: 1206
// RVA: 0xD3A70
void __fastcall UFG::RoadNetworkVisibleArea::CreateEdges(UFG::RoadNetworkVisibleArea *this, UFG::RoadNetworkIntersection *intersection)
{
  UFG::RoadNetworkIntersection *v2; // r13
  UFG::RoadNetworkVisibleArea *v3; // rdi
  __int64 v4; // r15
  __int64 v5; // rax
  signed __int64 v6; // rcx
  _QWORD *v7; // rdx
  UFG::RoadNetworkGate *v8; // rbx
  __int64 v9; // rax
  char *v10; // rax
  UFG::RoadNetworkVisibleAreaEdge *v11; // rax
  UFG::RoadNetworkVisibleAreaEdge *v12; // r12
  __int64 v13; // r14
  unsigned int v14; // esi
  unsigned int v15; // ebx
  unsigned int v16; // ebx
  unsigned __int64 v17; // rax
  char *v18; // rax
  char *v19; // rbp
  __int64 v20; // r9

  v2 = intersection;
  v3 = this;
  v4 = 0i64;
  if ( intersection->mNumGates )
  {
    do
    {
      v5 = v2->mGates.mOffset;
      if ( v5 )
        v6 = (signed __int64)&v2->mGates + v5;
      else
        v6 = 0i64;
      v7 = (_QWORD *)(v6 + 8 * v4);
      if ( *v7 )
        v8 = (UFG::RoadNetworkGate *)((char *)v7 + *v7);
      else
        v8 = 0i64;
      v9 = v8->mConnectedNode.mOffset;
      if ( v9 && (UFG::qOffset64<UFG::RoadNetworkNode *> *)((char *)&v8->mConnectedNode + v9) )
      {
        v10 = UFG::qMalloc(0x100ui64, "RoadNetworkVisibleArea.RoadNetworkVisibleAreaEdge", 0i64);
        if ( v10 )
        {
          UFG::RoadNetworkVisibleAreaEdge::RoadNetworkVisibleAreaEdge((UFG::RoadNetworkVisibleAreaEdge *)v10, v3, v8);
          v12 = v11;
        }
        else
        {
          v12 = 0i64;
        }
        v13 = v3->mEdgeManager.mEdgeCollection.size;
        v14 = v13 + 1;
        v15 = v3->mEdgeManager.mEdgeCollection.capacity;
        if ( (signed int)v13 + 1 > v15 )
        {
          if ( v15 )
            v16 = 2 * v15;
          else
            v16 = 1;
          for ( ; v16 < v14; v16 *= 2 )
            ;
          if ( v16 <= 2 )
            v16 = 2;
          if ( v16 - v14 > 0x10000 )
            v16 = v13 + 65537;
          if ( v16 != (_DWORD)v13 )
          {
            v17 = 8i64 * v16;
            if ( !is_mul_ok(v16, 8ui64) )
              v17 = -1i64;
            v18 = UFG::qMalloc(v17, "qArray.Add", 0i64);
            v19 = v18;
            if ( v3->mEdgeManager.mEdgeCollection.p )
            {
              v20 = 0i64;
              if ( v3->mEdgeManager.mEdgeCollection.size )
              {
                do
                {
                  *(_QWORD *)&v18[8 * v20] = v3->mEdgeManager.mEdgeCollection.p[v20];
                  v20 = (unsigned int)(v20 + 1);
                }
                while ( (unsigned int)v20 < v3->mEdgeManager.mEdgeCollection.size );
              }
              operator delete[](v3->mEdgeManager.mEdgeCollection.p);
            }
            v3->mEdgeManager.mEdgeCollection.p = (UFG::RoadNetworkVisibleAreaEdge **)v19;
            v3->mEdgeManager.mEdgeCollection.capacity = v16;
          }
        }
        v3->mEdgeManager.mEdgeCollection.size = v14;
        v3->mEdgeManager.mEdgeCollection.p[v13] = v12;
      }
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < (unsigned __int8)v2->mNumGates );
  }
}

// File Line: 1225
// RVA: 0xD3C40
void __fastcall UFG::RoadNetworkVisibleArea::CreateEdges(UFG::RoadNetworkVisibleArea *this, UFG::RoadNetworkSubSegment *subSegment)
{
  UFG::RoadNetworkSubSegment *v2; // rdi
  UFG::RoadNetworkVisibleArea *v3; // rbp
  UFG::RoadNetworkSegment *v4; // r8
  signed __int64 v5; // r14
  UFG::RoadNetworkSubSegment *v6; // rsi
  UFG::RoadNetworkGate *v7; // rbx
  __int64 v8; // rax
  _QWORD *v9; // rcx
  UFG::RoadNetworkGate *v10; // r9
  signed __int64 v11; // rcx
  __int64 v12; // rax
  __int64 v13; // rax
  UFG::RoadNetworkGate **v14; // r15
  UFG::RoadNetworkGate *v15; // r9
  __int64 v16; // rax
  UFG::RoadNetworkGate **v17; // rsi
  UFG::RoadNetworkGate *v18; // r9
  __int64 v19; // rax
  UFG::qArray<UFG::RoadNetworkGate *,0> gateCollection; // [rsp+28h] [rbp-30h]

  v2 = subSegment;
  v3 = this;
  v4 = subSegment->mParentNode;
  v5 = (signed __int64)&v4->mSubSegmentCollection;
  v6 = (UFG::RoadNetworkSubSegment *)subSegment->mPrev;
  v7 = 0i64;
  if ( (UFG::qList<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment,1,0> *)subSegment->mNext == &v4->mSubSegmentCollection )
  {
    if ( v6 == (UFG::RoadNetworkSubSegment *)v5 )
    {
      v8 = v4->mGates.mOffset;
      if ( v8 )
        v9 = (__int64 *)((char *)&v4->mGates.mOffset + v8);
      else
        v9 = 0i64;
      v10 = (UFG::RoadNetworkGate *)((char *)v9 + *v9);
      if ( !*v9 )
        v10 = 0i64;
      if ( v8 )
        v11 = (signed __int64)&v4->mGates + v8;
      else
        v11 = 0i64;
      v12 = *(_QWORD *)(v11 + 8);
      if ( v12 )
        v7 = (UFG::RoadNetworkGate *)(v12 + v11 + 8);
      v13 = v10->mConnectedNode.mOffset;
      if ( v13 )
      {
        if ( (UFG::qOffset64<UFG::RoadNetworkNode *> *)((char *)&v10->mConnectedNode + v13) )
          UFG::RoadNetworkVisibleArea::AddEdge(v3, subSegment, 0i64, v10);
      }
      UFG::RoadNetworkVisibleArea::AddEdge(v3, v2, 0i64, v7);
      return;
    }
    gateCollection.p = 0i64;
    *(_QWORD *)&gateCollection.size = 0i64;
    UFG::RoadNetworkSubSegment::GetGatesConnectedToSubSegment(subSegment, &gateCollection);
    v14 = gateCollection.p;
    v15 = *gateCollection.p;
    v16 = (*gateCollection.p)->mConnectedNode.mOffset;
    if ( v16 && (UFG::qOffset64<UFG::RoadNetworkNode *> *)((char *)&v15->mConnectedNode + v16) )
      UFG::RoadNetworkVisibleArea::AddEdge(v3, v2, 0i64, v15);
    operator delete[](v14);
    gateCollection.p = 0i64;
    *(_QWORD *)&gateCollection.size = 0i64;
  }
  else
  {
    UFG::RoadNetworkVisibleArea::AddEdge(this, subSegment, (UFG::RoadNetworkSubSegment *)subSegment->mNext, 0i64);
  }
  if ( v6 == (UFG::RoadNetworkSubSegment *)v5 )
  {
    gateCollection.p = 0i64;
    *(_QWORD *)&gateCollection.size = 0i64;
    UFG::RoadNetworkSubSegment::GetGatesConnectedToSubSegment(v2, &gateCollection);
    v17 = gateCollection.p;
    v18 = *gateCollection.p;
    v19 = (*gateCollection.p)->mConnectedNode.mOffset;
    if ( v19 && (UFG::qOffset64<UFG::RoadNetworkNode *> *)((char *)&v18->mConnectedNode + v19) )
      UFG::RoadNetworkVisibleArea::AddEdge(v3, v2, 0i64, v18);
    operator delete[](v17);
  }
  else
  {
    UFG::RoadNetworkVisibleArea::AddEdge(v3, v2, v6, 0i64);
  }
}

// File Line: 1293
// RVA: 0xD89C0
UFG::RoadNetworkGate *__fastcall UFG::RoadNetworkVisibleArea::GetFirstValidGate(UFG::RoadNetworkVisibleArea *this, UFG::RoadNetworkIntersection *intersection)
{
  __int64 v2; // rbp
  UFG::RoadNetworkIntersection *v3; // r14
  UFG::RoadNetworkVisibleArea *v4; // r15
  __int64 v5; // rax
  signed __int64 v6; // rcx
  __int64 v7; // rax
  signed __int64 v8; // rsi
  __int64 v9; // rax
  UFG::RoadNetworkSegment *v10; // rbx
  char v11; // di
  unsigned int v12; // edx
  UFG::qBaseTreeRB *v13; // rax
  __int64 v14; // rax
  UFG::RoadNetworkGate *v15; // rdx

  v2 = 0i64;
  v3 = intersection;
  v4 = this;
  if ( !intersection->mNumGates )
    return 0i64;
  while ( 1 )
  {
    v5 = v3->mGates.mOffset;
    v6 = (signed __int64)(v5 ? (UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkGate *> *> *)((char *)&v3->mGates + v5) : 0i64);
    v7 = *(_QWORD *)(v6 + 8 * v2);
    v8 = v7 ? v7 + v6 + 8 * v2 : 0i64;
    v9 = *(_QWORD *)(v8 + 8);
    if ( v9 )
    {
      v10 = (UFG::RoadNetworkSegment *)(v9 + v8 + 8);
      if ( v10 )
      {
        v11 = 0;
        if ( v10->mType.mValue == 1 )
        {
          v12 = v10->mIndex;
          if ( v12 )
            v13 = UFG::qBaseTreeRB::Get(&v4->mVisitedIntersections.mTree.mTree, v12);
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
    if ( (unsigned int)v2 >= (unsigned __int8)v3->mNumGates )
      return 0i64;
  }
  return (UFG::RoadNetworkGate *)v8;
}

// File Line: 1392
// RVA: 0xD36E0
void __fastcall UFG::RoadNetworkVisibleArea::ClaimSubSegmentVisited(UFG::RoadNetworkVisibleArea *this, UFG::RoadNetworkSubSegment *subSegment)
{
  UFG::RoadNetworkSubSegment *v2; // rsi
  UFG::qArray<UFG::RoadNetworkSubSegment *,0> *v3; // rdi
  __int64 v4; // rbp
  unsigned int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // edx
  UFG::RoadNetworkSubSegment **v8; // rax

  v2 = subSegment;
  if ( subSegment->mActive <= 1u )
  {
    v3 = this->mCurrentVisibleSubSegments;
    v4 = v3->size;
    v5 = v3->capacity;
    v6 = v4 + 1;
    if ( (signed int)v4 + 1 > v5 )
    {
      if ( v5 )
        v7 = 2 * v5;
      else
        v7 = 1;
      for ( ; v7 < v6; v7 *= 2 )
        ;
      if ( v7 <= 2 )
        v7 = 2;
      if ( v7 - v6 > 0x10000 )
        v7 = v4 + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
        (UFG::qArray<UFG::qReflectInventoryBase *,0> *)this->mCurrentVisibleSubSegments,
        v7,
        "qArray.Add");
    }
    v8 = v3->p;
    v3->size = v6;
    v8[v4] = v2;
  }
}

// File Line: 1401
// RVA: 0xD5750
void __fastcall UFG::RoadNetworkVisibleArea::FirstSpawnPoint(UFG::RoadNetworkVisibleArea *this)
{
  ((void (*)(void))this->mEdgeManager.mSpawnPointIterator->vfptr->First)();
}

// File Line: 1407
// RVA: 0xDF7C0
__int64 __fastcall UFG::RoadNetworkVisibleArea::NoMoreSpawnPoints(UFG::RoadNetworkVisibleArea *this)
{
  return ((__int64 (*)(void))this->mEdgeManager.mSpawnPointIterator->vfptr->IsDone)();
}

// File Line: 1413
// RVA: 0xDF7B0
void __fastcall UFG::RoadNetworkVisibleArea::NextSpawnPoint(UFG::RoadNetworkVisibleArea *this)
{
  ((void (*)(void))this->mEdgeManager.mSpawnPointIterator->vfptr->Next)();
}

// File Line: 1419
// RVA: 0xD85E0
UFG::RoadNetworkSpawnPoint *__fastcall UFG::RoadNetworkVisibleArea::GetCurrentEdgeSpawnPoint(UFG::RoadNetworkVisibleArea *this)
{
  return (UFG::RoadNetworkSpawnPoint *)((char *)this->mEdgeManager.mSpawnPointIterator->mCollection->p[this->mEdgeManager.mSpawnPointIterator->mCurrentIndex]
                                      + 24 * (this->mEdgeManager.mSpawnPointIterator->mSpawnPointIndex + 1i64));
}

// File Line: 1450
// RVA: 0xD09C0
void __fastcall UFG::RoadNetworkVisibleAreaEdgeManager::RoadNetworkVisibleAreaEdgeManager(UFG::RoadNetworkVisibleAreaEdgeManager *this)
{
  UFG::RoadNetworkVisibleAreaEdgeManager *v1; // rbx
  char *v2; // rax
  char *v3; // rax
  char *v4; // rax

  v1 = this;
  this->mEdgeCollection.p = 0i64;
  *(_QWORD *)&this->mEdgeCollection.size = 0i64;
  v2 = UFG::qMalloc(0x20ui64, "RoadNetworkVisibleAreaEdgeManager::EdgeStepIterator", 0i64);
  if ( v2 )
  {
    *(_QWORD *)v2 = &UFG::EdgeIterator::`vftable;
    *((_QWORD *)v2 + 2) = v1;
    *(_QWORD *)v2 = &UFG::EdgeStepIterator::`vftable;
    *((_DWORD *)v2 + 6) = -1;
    *((_DWORD *)v2 + 2) = -1;
  }
  else
  {
    v2 = 0i64;
  }
  v1->mStepIterator = (UFG::EdgeStepIterator *)v2;
  v3 = UFG::qMalloc(0x20ui64, "RoadNetworkVisibleAreaEdgeManager::OuterEdgeIterator", 0i64);
  if ( v3 )
  {
    *(_QWORD *)v3 = &UFG::EdgeIterator::`vftable;
    *((_QWORD *)v3 + 2) = v1;
    *(_QWORD *)v3 = &UFG::EdgeStepIterator::`vftable;
    *((_DWORD *)v3 + 6) = -1;
    *((_DWORD *)v3 + 2) = -1;
    *(_QWORD *)v3 = &UFG::OuterEdgeIterator::`vftable;
  }
  else
  {
    v3 = 0i64;
  }
  v1->mOuterEdgeIterator = (UFG::OuterEdgeIterator *)v3;
  v4 = UFG::qMalloc(0x20ui64, "RoadNetworkVisibleAreaEdgeManager::SpawnPointIterator", 0i64);
  if ( v4 )
  {
    *(_QWORD *)v4 = &UFG::EdgeIterator::`vftable;
    *((_QWORD *)v4 + 2) = v1;
    *(_QWORD *)v4 = &UFG::SpawnPointIterator::`vftable;
    *((_DWORD *)v4 + 6) = 0;
  }
  else
  {
    v4 = 0i64;
  }
  v1->mSpawnPointIterator = (UFG::SpawnPointIterator *)v4;
}

// File Line: 1456
// RVA: 0xD1180
void __fastcall UFG::RoadNetworkVisibleAreaEdgeManager::~RoadNetworkVisibleAreaEdgeManager(UFG::RoadNetworkVisibleAreaEdgeManager *this)
{
  UFG::RoadNetworkVisibleAreaEdgeManager *v1; // rbx
  UFG::EdgeStepIterator *v2; // rcx
  UFG::OuterEdgeIterator *v3; // rcx
  UFG::SpawnPointIterator *v4; // rcx
  UFG::RoadNetworkVisibleAreaEdge **v5; // rcx

  v1 = this;
  v2 = this->mStepIterator;
  if ( v2 )
    v2->vfptr->__vecDelDtor((UFG::EdgeIterator *)&v2->vfptr, 1u);
  v3 = v1->mOuterEdgeIterator;
  if ( v3 )
    v3->vfptr->__vecDelDtor((UFG::EdgeIterator *)&v3->vfptr, 1u);
  v4 = v1->mSpawnPointIterator;
  if ( v4 )
    v4->vfptr->__vecDelDtor((UFG::EdgeIterator *)&v4->vfptr, 1u);
  v5 = v1->mEdgeCollection.p;
  if ( v5 )
    operator delete[](v5);
  v1->mEdgeCollection.p = 0i64;
  *(_QWORD *)&v1->mEdgeCollection.size = 0i64;
}

// File Line: 1467
// RVA: 0xD3770
void __fastcall UFG::RoadNetworkVisibleAreaEdgeManager::Clear(UFG::RoadNetworkVisibleAreaEdgeManager *this)
{
  UFG::RoadNetworkVisibleAreaEdgeManager *v1; // rbx
  unsigned int i; // edi
  signed __int64 v3; // r14
  UFG::RoadNetworkVisibleAreaEdge **v4; // rax
  UFG::RoadNetworkVisibleAreaEdge *v5; // rsi
  UFG::RoadNetworkVisibleAreaEdge **v6; // rcx

  v1 = this;
  for ( i = 0; i < v1->mEdgeCollection.size; v1->mEdgeCollection.p[v3] = 0i64 )
  {
    v3 = i;
    v4 = v1->mEdgeCollection.p;
    v5 = v4[v3];
    if ( v5 )
    {
      UFG::RoadNetworkVisibleAreaEdge::~RoadNetworkVisibleAreaEdge(v4[v3]);
      operator delete[](v5);
    }
    ++i;
  }
  v6 = v1->mEdgeCollection.p;
  if ( v6 )
    operator delete[](v6);
  v1->mEdgeCollection.p = 0i64;
  *(_QWORD *)&v1->mEdgeCollection.size = 0i64;
}

// File Line: 1480
// RVA: 0xD4900
char __fastcall UFG::RoadNetworkVisibleAreaEdgeManager::ExpandOneStep(UFG::RoadNetworkVisibleAreaEdgeManager *this)
{
  UFG::RoadNetworkVisibleAreaEdgeManager *v1; // rbx
  char result; // al
  UFG::RoadNetworkVisibleAreaEdge *v3; // rcx

  v1 = this;
  ((void (*)(void))this->mStepIterator->vfptr->First)();
  if ( ((unsigned __int8 (*)(void))v1->mStepIterator->vfptr->IsDone)() )
  {
    ((void (*)(void))v1->mOuterEdgeIterator->vfptr->First)();
    while ( !((unsigned __int8 (*)(void))v1->mOuterEdgeIterator->vfptr->IsDone)() )
    {
      v3 = v1->mOuterEdgeIterator->mCollection->p[v1->mOuterEdgeIterator->mCurrentIndex];
      if ( !v3->mNumSpawnPoints )
        UFG::RoadNetworkVisibleAreaEdge::AttachSpawnPoints(v3);
      ((void (*)(void))v1->mOuterEdgeIterator->vfptr->Next)();
    }
    result = 1;
  }
  else
  {
    do
    {
      UFG::RoadNetworkVisibleAreaEdge::ExpandOneStep(v1->mStepIterator->mCollection->p[v1->mStepIterator->mCurrentIndex]);
      ((void (*)(void))v1->mStepIterator->vfptr->Next)();
    }
    while ( !((unsigned __int8 (*)(void))v1->mStepIterator->vfptr->IsDone)() );
    result = 0;
  }
  return result;
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
  UFG::qArray<UFG::RoadNetworkVisibleAreaEdge *,0> *v1; // rax
  __int64 v2; // rbx
  unsigned int v3; // edx
  UFG::EdgeStepIterator *v4; // rdi

  v1 = this->mCollection;
  this->mCurrentIndex = -1;
  v2 = 0i64;
  v3 = v1->size;
  v4 = this;
  this->mEndOfStep = v1->size;
  if ( v3 )
  {
    while ( !(unsigned __int8)v4->vfptr[1].__vecDelDtor(
                                (UFG::EdgeIterator *)&v4->vfptr,
                                (unsigned int)v4->mCollection->p[v2]) )
    {
      v2 = (unsigned int)(v2 + 1);
      if ( (unsigned int)v2 >= v4->mEndOfStep )
        return;
    }
    v4->mCurrentIndex = v2;
  }
}

// File Line: 1552
// RVA: 0xDF6A0
void __fastcall UFG::EdgeStepIterator::Next(UFG::EdgeStepIterator *this)
{
  unsigned int v1; // ebx
  UFG::EdgeStepIterator *v2; // rdi
  __int64 v3; // rbx

  v1 = this->mCurrentIndex;
  v2 = this;
  if ( v1 != -1 )
  {
    v3 = v1 + 1;
    this->mCurrentIndex = -1;
    if ( (unsigned int)v3 < this->mEndOfStep )
    {
      while ( !(unsigned __int8)v2->vfptr[1].__vecDelDtor(
                                  (UFG::EdgeIterator *)&v2->vfptr,
                                  (unsigned int)v2->mCollection->p[v3]) )
      {
        v3 = (unsigned int)(v3 + 1);
        if ( (unsigned int)v3 >= v2->mEndOfStep )
          return;
      }
      v2->mCurrentIndex = v3;
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
  return edge->mComplete != 1;
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
  UFG::qArray<UFG::RoadNetworkVisibleAreaEdge *,0> *v1; // rax
  __int64 v2; // rbx
  UFG::SpawnPointIterator *v3; // rdi

  v1 = this->mCollection;
  v2 = 0i64;
  this->mCurrentIndex = -1;
  v3 = this;
  if ( v1->size )
  {
    while ( !(unsigned __int8)v3->vfptr[1].__vecDelDtor(
                                (UFG::EdgeIterator *)&v3->vfptr,
                                (unsigned int)v3->mCollection->p[v2]) )
    {
      v2 = (unsigned int)(v2 + 1);
      if ( (unsigned int)v2 >= v3->mCollection->size )
        return;
    }
    v3->mSpawnPointIndex = 0;
    v3->mCurrentIndex = v2;
  }
}

// File Line: 1619
// RVA: 0xDF710
void __fastcall UFG::SpawnPointIterator::Next(UFG::SpawnPointIterator *this)
{
  __int64 v1; // rbx
  UFG::SpawnPointIterator *v2; // rdi
  UFG::qArray<UFG::RoadNetworkVisibleAreaEdge *,0> *v3; // r8
  unsigned int v4; // ecx
  __int64 v5; // rbx

  v1 = this->mCurrentIndex;
  v2 = this;
  if ( (_DWORD)v1 != -1 )
  {
    v3 = this->mCollection;
    v4 = this->mSpawnPointIndex;
    if ( v4 >= v3->p[v1]->mNumSpawnPoints - 1 )
    {
      v5 = (unsigned int)(v1 + 1);
      v2->mCurrentIndex = -1;
      if ( (unsigned int)v5 < v3->size )
      {
        while ( !(unsigned __int8)v2->vfptr[1].__vecDelDtor(
                                    (UFG::EdgeIterator *)&v2->vfptr,
                                    (unsigned int)v2->mCollection->p[v5]) )
        {
          v5 = (unsigned int)(v5 + 1);
          if ( (unsigned int)v5 >= v2->mCollection->size )
            return;
        }
        v2->mSpawnPointIndex = 0;
        v2->mCurrentIndex = v5;
      }
    }
    else
    {
      v2->mSpawnPointIndex = v4 + 1;
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
bool __fastcall UFG::SpawnPointIterator::IsValid(UFG::SpawnPointIterator *this, UFG::RoadNetworkVisibleAreaEdge *edge)
{
  return edge->mNumSpawnPoints != 0;
}

// File Line: 1685
// RVA: 0xD06E0
void __fastcall UFG::RoadNetworkVisibleAreaEdge::RoadNetworkVisibleAreaEdge(UFG::RoadNetworkVisibleAreaEdge *this, UFG::RoadNetworkVisibleArea *visibleArea, UFG::RoadNetworkGate *startingGate)
{
  UFG::RoadNetworkGate *v3; // rbx
  UFG::RoadNetworkVisibleAreaEdge *v4; // rdi
  float v5; // xmm1_4
  float v6; // xmm2_4
  UFG::RoadNetworkGate *v7; // rbx
  __int64 v8; // rax
  UFG::RoadNetworkSegment *v9; // rcx
  __int64 v10; // rax
  UFG::RoadNetworkGate *v11; // rdx
  UFG::RoadNetworkNode *v12; // rdx

  v3 = startingGate;
  v4 = this;
  this->mPrev = (UFG::qNode<UFG::RoadNetworkVisibleAreaEdge,UFG::RoadNetworkVisibleAreaEdge> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::RoadNetworkVisibleAreaEdge,UFG::RoadNetworkVisibleAreaEdge> *)&this->mPrev;
  this->mVisibleArea = visibleArea;
  `eh vector constructor iterator(
    this->mSpawnPoint,
    0x18ui64,
    6,
    (void (__fastcall *)(void *))UFG::RoadNetworkSpawnPoint::RoadNetworkSpawnPoint);
  v4->mT = -1.0;
  v4->mComplete = 0;
  v4->mNumSpawnPoints = 0;
  v4->mNodesToStart.p = 0i64;
  *(_QWORD *)&v4->mNodesToStart.size = 0i64;
  v4->mCurrentSubSegment = 0i64;
  v4->mNextSubSegment = 0i64;
  v4->mPreviousSubSegment = 0i64;
  v4->mNextGate = 0i64;
  v4->mPreviousGate = v3;
  v5 = UFG::qVector3::msZero.y;
  v6 = UFG::qVector3::msZero.z;
  v4->mDirection.x = UFG::qVector3::msZero.x;
  v4->mDirection.y = v5;
  v4->mDirection.z = v6;
  v7 = v4->mPreviousGate;
  if ( v7 )
  {
    v8 = v7->mConnectedNode.mOffset;
    if ( v8 )
      v9 = (UFG::RoadNetworkSegment *)((char *)&v7->mConnectedNode + v8);
    else
      v9 = 0i64;
    v10 = v7->mConnectedGate.mOffset;
    if ( v10 )
      v11 = (UFG::RoadNetworkGate *)((char *)v7 + v10 + 16);
    else
      v11 = 0i64;
    v4->mCurrentSubSegment = UFG::RoadNetworkSegment::GetClosestSubSegment(v9, v11);
  }
  v12 = (UFG::RoadNetworkNode *)((char *)v7 + v7->mNode.mOffset);
  if ( !v7->mNode.mOffset )
    v12 = 0i64;
  UFG::RoadNetworkVisibleAreaEdge::AddNodeToPath(v4, v12);
  v4->mNextSubSegment = UFG::RoadNetworkVisibleAreaEdge::GetNextSubSegment(v4);
  ++v4->mCurrentSubSegment->mActive;
  UFG::RoadNetworkVisibleAreaEdge::AddNodeToPath(
    v4,
    (UFG::RoadNetworkNode *)&v4->mCurrentSubSegment->mParentNode->mType);
  UFG::RoadNetworkVisibleAreaEdge::UpdateDirection(v4);
  UFG::RoadNetworkVisibleAreaEdge::RefreshT(v4);
  UFG::RoadNetworkVisibleArea::ClaimSubSegmentVisited(v4->mVisibleArea, v4->mCurrentSubSegment);
  v4->mNextGate = 0i64;
  v4->mPreviousGate = 0i64;
}

// File Line: 1710
// RVA: 0xD05B0
void __fastcall UFG::RoadNetworkVisibleAreaEdge::RoadNetworkVisibleAreaEdge(UFG::RoadNetworkVisibleAreaEdge *this, UFG::RoadNetworkGate *startingGate, UFG::RoadNetworkVisibleArea *visibleArea, UFG::RoadNetworkVisibleAreaEdge *spawner)
{
  UFG::RoadNetworkVisibleAreaEdge *v4; // rsi
  UFG::RoadNetworkGate *v5; // rbx
  UFG::RoadNetworkVisibleAreaEdge *v6; // rdi
  UFG::RoadNetworkGate *v7; // rdx
  float v8; // xmm1_4
  float v9; // xmm2_4
  UFG::RoadNetworkGate *v10; // rax
  __int64 v11; // rcx
  UFG::RoadNetworkSegment *v12; // r8
  __int64 v13; // rcx

  v4 = spawner;
  v5 = startingGate;
  v6 = this;
  this->mPrev = (UFG::qNode<UFG::RoadNetworkVisibleAreaEdge,UFG::RoadNetworkVisibleAreaEdge> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::RoadNetworkVisibleAreaEdge,UFG::RoadNetworkVisibleAreaEdge> *)&this->mPrev;
  this->mVisibleArea = visibleArea;
  `eh vector constructor iterator(
    this->mSpawnPoint,
    0x18ui64,
    6,
    (void (__fastcall *)(void *))UFG::RoadNetworkSpawnPoint::RoadNetworkSpawnPoint);
  v6->mT = -1.0;
  v6->mComplete = 0;
  v7 = 0i64;
  v6->mNumSpawnPoints = 0;
  v6->mNodesToStart.p = 0i64;
  *(_QWORD *)&v6->mNodesToStart.size = 0i64;
  v6->mCurrentSubSegment = 0i64;
  v6->mNextSubSegment = 0i64;
  v6->mPreviousSubSegment = 0i64;
  v6->mNextGate = 0i64;
  v6->mPreviousGate = v5;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  v6->mDirection.x = UFG::qVector3::msZero.x;
  v6->mDirection.y = v8;
  v6->mDirection.z = v9;
  v10 = v6->mPreviousGate;
  if ( v10 )
  {
    v11 = v10->mConnectedNode.mOffset;
    if ( v11 )
      v12 = (UFG::RoadNetworkSegment *)((char *)&v10->mConnectedNode + v11);
    else
      v12 = 0i64;
    v13 = v10->mConnectedGate.mOffset;
    if ( v13 )
      v7 = (UFG::RoadNetworkGate *)((char *)v10 + v13 + 16);
    v6->mCurrentSubSegment = UFG::RoadNetworkSegment::GetClosestSubSegment(v12, v7);
  }
  UFG::RoadNetworkVisibleAreaEdge::Init(v6, v4);
}

// File Line: 1727
// RVA: 0xD0880
void __fastcall UFG::RoadNetworkVisibleAreaEdge::RoadNetworkVisibleAreaEdge(UFG::RoadNetworkVisibleAreaEdge *this, UFG::RoadNetworkVisibleArea *visibleArea, UFG::RoadNetworkSubSegment *current, UFG::RoadNetworkSubSegment *next, UFG::RoadNetworkGate *nextGate)
{
  UFG::RoadNetworkSubSegment *v5; // rdi
  UFG::RoadNetworkSubSegment *v6; // rbx
  UFG::RoadNetworkVisibleAreaEdge *v7; // rsi
  float v8; // xmm1_4
  float v9; // xmm2_4

  v5 = next;
  v6 = current;
  v7 = this;
  this->mPrev = (UFG::qNode<UFG::RoadNetworkVisibleAreaEdge,UFG::RoadNetworkVisibleAreaEdge> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::RoadNetworkVisibleAreaEdge,UFG::RoadNetworkVisibleAreaEdge> *)&this->mPrev;
  this->mVisibleArea = visibleArea;
  `eh vector constructor iterator(
    this->mSpawnPoint,
    0x18ui64,
    6,
    (void (__fastcall *)(void *))UFG::RoadNetworkSpawnPoint::RoadNetworkSpawnPoint);
  v7->mT = -1.0;
  v7->mComplete = 0;
  v7->mNumSpawnPoints = 0;
  v7->mNodesToStart.p = 0i64;
  *(_QWORD *)&v7->mNodesToStart.size = 0i64;
  v7->mCurrentSubSegment = v6;
  v7->mNextSubSegment = v5;
  v7->mPreviousSubSegment = 0i64;
  v7->mNextGate = nextGate;
  v7->mPreviousGate = 0i64;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  v7->mDirection.x = UFG::qVector3::msZero.x;
  v7->mDirection.y = v8;
  v7->mDirection.z = v9;
  ++v7->mCurrentSubSegment->mActive;
  UFG::RoadNetworkVisibleAreaEdge::AddNodeToPath(
    v7,
    (UFG::RoadNetworkNode *)&v7->mCurrentSubSegment->mParentNode->mType);
  UFG::RoadNetworkVisibleAreaEdge::UpdateDirection(v7);
  UFG::RoadNetworkVisibleAreaEdge::RefreshT(v7);
  UFG::RoadNetworkVisibleArea::ClaimSubSegmentVisited(v7->mVisibleArea, v7->mCurrentSubSegment);
  v7->mNextGate = 0i64;
  v7->mPreviousGate = 0i64;
}

// File Line: 1733
// RVA: 0xD10B0
void __fastcall UFG::RoadNetworkVisibleAreaEdge::~RoadNetworkVisibleAreaEdge(UFG::RoadNetworkVisibleAreaEdge *this)
{
  UFG::RoadNetworkVisibleAreaEdge *v1; // rbx
  unsigned int v2; // edx
  __int64 v3; // rax
  __int64 v4; // rax
  UFG::RoadNetworkNode **v5; // rcx
  UFG::qNode<UFG::RoadNetworkVisibleAreaEdge,UFG::RoadNetworkVisibleAreaEdge> *v6; // rcx
  UFG::qNode<UFG::RoadNetworkVisibleAreaEdge,UFG::RoadNetworkVisibleAreaEdge> *v7; // rax

  v1 = this;
  v2 = 0;
  if ( this->mNumSpawnPoints )
  {
    do
    {
      v3 = *((_QWORD *)&this->mPrev + 3 * (v2 + 1i64));
      if ( v3 )
      {
        *(_QWORD *)(v3 + 24) = 0i64;
        *(_DWORD *)(v3 + 32) = 0;
        v4 = *((_QWORD *)&this->mNext + 3 * (v2 + 1i64));
        --*(_DWORD *)(v4 + 48);
        *((_QWORD *)&this->mNext + 3 * (v2 + 1i64)) = 0i64;
        *((_QWORD *)&this->mPrev + 3 * (v2 + 1i64)) = 0i64;
        *((_QWORD *)&this->mVisibleArea + 3 * (v2 + 1i64)) = 0i64;
      }
      ++v2;
    }
    while ( v2 < this->mNumSpawnPoints );
  }
  v5 = this->mNodesToStart.p;
  if ( v5 )
    operator delete[](v5);
  v1->mNodesToStart.p = 0i64;
  *(_QWORD *)&v1->mNodesToStart.size = 0i64;
  `eh vector destructor iterator(v1->mSpawnPoint, 0x18ui64, 6, (void (__fastcall *)(void *))_);
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v1->mPrev = (UFG::qNode<UFG::RoadNetworkVisibleAreaEdge,UFG::RoadNetworkVisibleAreaEdge> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::RoadNetworkVisibleAreaEdge,UFG::RoadNetworkVisibleAreaEdge> *)&v1->mPrev;
}

// File Line: 1773
// RVA: 0xDD070
void __fastcall UFG::RoadNetworkVisibleAreaEdge::Init(UFG::RoadNetworkVisibleAreaEdge *this, UFG::RoadNetworkVisibleAreaEdge *spawner)
{
  UFG::RoadNetworkVisibleAreaEdge *v2; // rbx

  v2 = this;
  if ( spawner )
  {
    UFG::qArray<UFG::qPropertySet *,0>::Clone(&spawner->mNodesToStart, &this->mNodesToStart);
    v2->mNextSubSegment = UFG::RoadNetworkVisibleAreaEdge::GetNextSubSegment(v2);
  }
  ++v2->mCurrentSubSegment->mActive;
  UFG::RoadNetworkVisibleAreaEdge::AddNodeToPath(
    v2,
    (UFG::RoadNetworkNode *)&v2->mCurrentSubSegment->mParentNode->mType);
  UFG::RoadNetworkVisibleAreaEdge::UpdateDirection(v2);
  UFG::RoadNetworkVisibleAreaEdge::RefreshT(v2);
  UFG::RoadNetworkVisibleArea::ClaimSubSegmentVisited(v2->mVisibleArea, v2->mCurrentSubSegment);
  v2->mNextGate = 0i64;
  v2->mPreviousGate = 0i64;
}

// File Line: 1789
// RVA: 0xD8610
UFG::qVector3 *__fastcall UFG::RoadNetworkVisibleAreaEdge::GetCurrentPosition(UFG::RoadNetworkVisibleAreaEdge *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rsi
  UFG::RoadNetworkVisibleAreaEdge *v3; // r11
  UFG::RoadNetworkSegment *v4; // r9
  UFG::RoadNetworkConnection *v5; // rcx
  __int64 v6; // r8
  __int64 v7; // rax
  signed __int64 v8; // rdx
  signed __int64 v9; // r10
  __int64 v10; // rax
  signed __int64 v11; // rax
  float v12; // xmm6_4
  __int64 v13; // r10
  signed __int64 v14; // rdx
  __int64 v15; // rax
  signed __int64 v16; // rdi
  signed __int64 v17; // rax
  __int64 v18; // rdx
  UFG::qBezierPathMemImaged *v19; // rax
  UFG::RoadNetworkConnection *v20; // rbx
  unsigned int v21; // eax
  UFG::qBezierSplineMemImaged *v22; // rax
  UFG::qVector3 *v23; // rax
  float v24; // xmm1_4
  float v25; // xmm0_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-28h]
  float splineT; // [rsp+50h] [rbp+8h]

  v2 = result;
  v3 = this;
  v4 = this->mCurrentSubSegment->mParentNode;
  v5 = 0i64;
  v6 = v4->mLane.mOffset;
  v7 = ((unsigned __int8)v4->mNumLanes - 1) / 2;
  if ( v6 )
    v8 = (signed __int64)&v4->mLane + v6;
  else
    v8 = 0i64;
  v9 = v8 + 8 * v7;
  v10 = *(_QWORD *)(v8 + 8 * v7);
  if ( v10 )
    v11 = v9 + v10;
  else
    v11 = 0i64;
  v12 = v3->mT;
  v13 = *(unsigned __int16 *)(v11 + 36);
  if ( v6 )
    v14 = (signed __int64)&v4->mLane + v6;
  else
    v14 = 0i64;
  v15 = *(_QWORD *)(v14 + 8 * v13);
  v16 = v15 + v14 + 8 * v13;
  if ( !v15 )
    v16 = 0i64;
  if ( *(_QWORD *)v16 )
    v17 = v16 + *(_QWORD *)v16;
  else
    v17 = 0i64;
  v18 = *(_QWORD *)(v17 + 32);
  if ( v18 )
    v5 = (UFG::RoadNetworkConnection *)(v18 + v17 + 32);
  v19 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v5, *(unsigned __int16 *)(v16 + 38));
  v20 = (UFG::RoadNetworkConnection *)v19;
  v21 = UFG::qBezierPathMemImaged::GetSplineParameters(v19, v12, &splineT);
  v22 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v20, v21);
  UFG::RoadNetworkLane::GetOffsetPos(&resulta, v22, splineT, *(float *)(v16 + 40));
  v23 = v2;
  v24 = resulta.y;
  v2->x = resulta.x;
  v25 = resulta.z;
  v2->y = v24;
  v2->z = v25;
  return v23;
}

// File Line: 1812
// RVA: 0xD4710
void __fastcall UFG::RoadNetworkVisibleAreaEdge::ExpandOneStep(UFG::RoadNetworkVisibleAreaEdge *this)
{
  UFG::RoadNetworkVisibleAreaEdge *v1; // rdi
  UFG::RoadNetworkSegment *v2; // rbx
  unsigned int v3; // edx
  __int64 v4; // rax
  __int64 v5; // rax
  UFG::RoadNetworkSubSegment *v6; // rax
  UFG::RoadNetworkSubSegment *v7; // rsi
  UFG::RoadNetworkGate *v8; // rbp
  __int64 v9; // rax
  UFG::RoadNetworkSegment *v10; // rsi
  UFG::RoadNetworkSubSegment *v11; // rax
  UFG::RoadNetworkGate *v12; // rax
  UFG::RoadNetworkGate *v13; // rbp
  __int64 v14; // rax
  UFG::RoadNetworkSubSegment *v15; // rbx
  UFG::qVector3 result; // [rsp+20h] [rbp-28h]
  UFG::qVector3 position; // [rsp+30h] [rbp-18h]

  v1 = this;
  if ( this->mComplete != 1 )
  {
    v2 = 0i64;
    v3 = 0;
    if ( this->mNumSpawnPoints )
    {
      do
      {
        v4 = *((_QWORD *)&this->mPrev + 3 * (v3 + 1i64));
        if ( v4 )
        {
          *(_QWORD *)(v4 + 24) = 0i64;
          *(_DWORD *)(v4 + 32) = 0;
          v5 = *((_QWORD *)&this->mNext + 3 * (v3 + 1i64));
          --*(_DWORD *)(v5 + 48);
          *((_QWORD *)&this->mNext + 3 * (v3 + 1i64)) = 0i64;
          *((_QWORD *)&this->mPrev + 3 * (v3 + 1i64)) = 0i64;
          *((_QWORD *)&this->mVisibleArea + 3 * (v3 + 1i64)) = 0i64;
        }
        ++v3;
      }
      while ( v3 < this->mNumSpawnPoints );
    }
    this->mNumSpawnPoints = 0;
    UFG::RoadNetworkVisibleAreaEdge::GetCurrentPosition(this, &result);
    position = result;
    v6 = UFG::RoadNetworkVisibleAreaEdge::GetNextSubSegment(v1);
    v7 = v6;
    if ( v6 )
    {
      if ( UFG::RoadNetworkVisibleArea::IsSubSegmentInRange(v1->mVisibleArea, v6) )
      {
        UFG::RoadNetworkVisibleAreaEdge::SetCurrentSubSegment(v1, v7);
      }
      else if ( !v1->mComplete )
      {
        v1->mComplete = 1;
      }
    }
    else
    {
      v8 = UFG::RoadNetworkVisibleAreaEdge::GetNextGate(v1);
      if ( !UFG::RoadNetworkVisibleAreaEdge::ShouldExpand(v1, v8) )
        goto LABEL_25;
      v9 = v8->mConnectedNode.mOffset;
      if ( v9 )
        v10 = (UFG::RoadNetworkSegment *)((char *)&v8->mConnectedNode + v9);
      else
        v10 = 0i64;
      if ( 0 == v10->mType.mValue )
      {
        v11 = UFG::RoadNetworkSegment::GetClosestSubSegment(v10, &position);
        v1->mPreviousGate = v8;
        UFG::RoadNetworkVisibleAreaEdge::SetCurrentSubSegment(v1, v11);
        return;
      }
      UFG::RoadNetworkVisibleAreaEdge::AddNodeToPath(v1, (UFG::RoadNetworkNode *)&v10->mType);
      v12 = UFG::RoadNetworkVisibleArea::GetFirstValidGate(v1->mVisibleArea, (UFG::RoadNetworkIntersection *)v10);
      v13 = v12;
      if ( v12 )
      {
        v1->mPreviousGate = v12;
        v14 = v12->mConnectedNode.mOffset;
        if ( v14 )
          v2 = (UFG::RoadNetworkSegment *)((char *)&v13->mConnectedNode + v14);
        v15 = UFG::RoadNetworkSegment::GetClosestSubSegment(v2, &v13->mPosition);
        UFG::RoadNetworkVisibleArea::CreateEdges(v1->mVisibleArea, (UFG::RoadNetworkIntersection *)v10, v1, v13);
        UFG::RoadNetworkVisibleAreaEdge::SetCurrentSubSegment(v1, v15);
      }
      else
      {
LABEL_25:
        if ( !v1->mComplete )
          v1->mComplete = 1;
      }
    }
  }
}

// File Line: 1884
// RVA: 0xD1BE0
void __fastcall UFG::RoadNetworkVisibleAreaEdge::AddNodeToPath(UFG::RoadNetworkVisibleAreaEdge *this, UFG::RoadNetworkNode *node)
{
  unsigned __int16 v2; // ax
  unsigned __int128 v3; // di
  UFG::RoadNetworkVisibleArea *v4; // rcx
  unsigned int v5; // edx
  __int64 v6; // rbp
  unsigned int v7; // edx
  unsigned int v8; // ebx
  unsigned int v9; // edx
  __int64 v10; // rax
  Render::VerletCloth *value; // [rsp+30h] [rbp+8h]

  v2 = node->mType.mValue;
  v3 = __PAIR__((unsigned __int64)this, (unsigned __int64)node);
  if ( node->mType.mValue == 1 )
    ++node->mActive;
  v4 = this->mVisibleArea;
  value = (Render::VerletCloth *)node;
  v5 = node->mIndex;
  if ( v2 == 1 )
    UFG::qMap<Render::VerletCloth *>::Set((UFG::qMap<Render::VerletCloth *> *)&v4->mVisitedIntersections, v5, &value);
  else
    UFG::qMap<Render::VerletCloth *>::Set((UFG::qMap<Render::VerletCloth *> *)&v4->mVisitedSegments, v5, &value);
  v6 = *(unsigned int *)(*((_QWORD *)&v3 + 1) + 184i64);
  v7 = *(_DWORD *)(*((_QWORD *)&v3 + 1) + 188i64);
  v8 = v6 + 1;
  if ( (signed int)v6 + 1 > v7 )
  {
    if ( v7 )
      v9 = 2 * v7;
    else
      v9 = 1;
    for ( ; v9 < v8; v9 *= 2 )
      ;
    if ( v9 <= 2 )
      v9 = 2;
    if ( v9 - v8 > 0x10000 )
      v9 = v6 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)(*((_QWORD *)&v3 + 1) + 184i64),
      v9,
      "qArray.Add.mNodesToStart");
  }
  v10 = *(_QWORD *)(*((_QWORD *)&v3 + 1) + 192i64);
  *(_DWORD *)(*((_QWORD *)&v3 + 1) + 184i64) = v8;
  *(_QWORD *)(v10 + 8 * v6) = v3;
}

// File Line: 1905
// RVA: 0xE0980
char __fastcall UFG::RoadNetworkVisibleAreaEdge::ShouldExpand(UFG::RoadNetworkVisibleAreaEdge *this, UFG::RoadNetworkGate *gate)
{
  UFG::RoadNetworkGate *v2; // rbx
  UFG::RoadNetworkVisibleAreaEdge *v3; // rbp
  __int64 v4; // rax
  UFG::qBaseTreeRB *v5; // rsi
  UFG::RoadNetworkIntersection *v6; // rdi
  float v7; // xmm1_4
  float v8; // xmm0_4
  UFG::RoadNetworkGate *v9; // rax
  unsigned int v10; // edx
  UFG::RoadNetworkVisibleArea *v11; // rcx
  float v12; // xmm1_4
  float v13; // xmm0_4
  bool v14; // bl
  bool v15; // al
  __int64 v16; // rax
  UFG::RoadNetworkSubSegment *v17; // rax
  char v18; // al
  UFG::qVector3 position; // [rsp+20h] [rbp-28h]
  UFG::qVector3 result; // [rsp+30h] [rbp-18h]

  v2 = gate;
  v3 = this;
  if ( !gate )
    return 0;
  v4 = gate->mConnectedNode.mOffset;
  v5 = 0i64;
  if ( v4 )
    v6 = (UFG::RoadNetworkIntersection *)((char *)&gate->mConnectedNode + v4);
  else
    v6 = 0i64;
  v7 = gate->mPosition.y;
  position.x = gate->mPosition.x;
  v8 = gate->mPosition.z;
  position.y = v7;
  position.z = v8;
  UFG::RoadNetworkVisibleAreaEdge::GetCurrentPosition(this, &result);
  if ( !v6 )
    goto LABEL_21;
  if ( v6->mType.mValue == 1 )
  {
    v9 = UFG::RoadNetworkIntersection::GetClosestGate(v6, &result);
    v10 = v6->mIndex;
    v11 = v3->mVisibleArea;
    v12 = v9->mPosition.y;
    position.x = v9->mPosition.x;
    v13 = v9->mPosition.z;
    position.y = v12;
    position.z = v13;
    if ( v10 )
      v5 = UFG::qBaseTreeRB::Get(&v11->mVisitedIntersections.mTree.mTree, v10);
    v14 = v5 != 0i64;
    v15 = UFG::RoadNetworkVisibleArea::IsInRange(v3->mVisibleArea, v6, &position);
  }
  else
  {
    v16 = v2->mConnectedGate.mOffset;
    if ( v16 )
      v5 = (UFG::qBaseTreeRB *)((char *)&v2->mConnectedGate + v16);
    v17 = UFG::RoadNetworkSegment::GetClosestSubSegment((UFG::RoadNetworkSegment *)v6, (UFG::RoadNetworkGate *)v5);
    v14 = v17->mActive != 0;
    v15 = UFG::RoadNetworkVisibleArea::IsSubSegmentInRange(v3->mVisibleArea, v17);
  }
  if ( !v14 && v15 )
    v18 = 1;
  else
LABEL_21:
    v18 = 0;
  return v18;
}

// File Line: 1946
// RVA: 0xDADD0
UFG::RoadNetworkSubSegment *__fastcall UFG::RoadNetworkVisibleAreaEdge::GetNextSubSegment(UFG::RoadNetworkVisibleAreaEdge *this)
{
  UFG::RoadNetworkSubSegment *v1; // rdx
  UFG::RoadNetworkSubSegment *v2; // r10
  UFG::RoadNetworkSubSegment *result; // rax
  UFG::RoadNetworkSubSegment *v4; // r8

  v1 = this->mCurrentSubSegment;
  v2 = 0i64;
  result = (UFG::RoadNetworkSubSegment *)v1->mNext;
  v4 = (UFG::RoadNetworkSubSegment *)&v1->mParentNode->mSubSegmentCollection;
  if ( result == v4
    || (float)((float)((float)((float)(result->mPosition.y - v1->mPosition.y) * this->mDirection.y)
                     + (float)((float)(result->mPosition.x - v1->mPosition.x) * this->mDirection.x))
             + (float)((float)(result->mPosition.z - v1->mPosition.z) * this->mDirection.z)) <= 0.0 )
  {
    if ( (UFG::RoadNetworkSubSegment *)v1->mPrev != v4
      && (float)((float)((float)((float)(*((float *)&v1->mPrev[1].mNext + 1) - v1->mPosition.y) * this->mDirection.y)
                       + (float)((float)(*(float *)&v1->mPrev[1].mNext - v1->mPosition.x) * this->mDirection.x))
               + (float)((float)(*(float *)&v1->mPrev[2].mPrev - v1->mPosition.z) * this->mDirection.z)) > 0.0 )
    {
      v2 = (UFG::RoadNetworkSubSegment *)v1->mPrev;
    }
    result = v2;
  }
  return result;
}

// File Line: 1979
// RVA: 0xE1650
void __fastcall UFG::RoadNetworkVisibleAreaEdge::UpdateDirection(UFG::RoadNetworkVisibleAreaEdge *this)
{
  UFG::RoadNetworkSubSegment *v1; // rax
  UFG::RoadNetworkSubSegment *v2; // rdx
  float v3; // xmm8_4
  float v4; // xmm3_4
  float v5; // xmm4_4
  float v6; // xmm5_4
  float v7; // xmm7_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::RoadNetworkSubSegment *v11; // rdx
  UFG::RoadNetworkGate *v12; // rdx
  UFG::RoadNetworkGate *v13; // rdx
  float v14; // [rsp+0h] [rbp-48h]
  float v15; // [rsp+4h] [rbp-44h]
  float v16; // [rsp+8h] [rbp-40h]

  v1 = this->mCurrentSubSegment;
  if ( v1 )
  {
    v2 = this->mPreviousSubSegment;
    v3 = v1->mEndPos.z - v1->mPosition.z;
    v4 = v1->mBeginPos.x - v1->mPosition.x;
    v5 = v1->mBeginPos.y - v1->mPosition.y;
    v6 = v1->mBeginPos.z - v1->mPosition.z;
    v7 = v1->mEndPos.y - v1->mPosition.y;
    if ( v2 )
    {
      v8 = v1->mPosition.x - v2->mPosition.x;
      v9 = v1->mPosition.y - v2->mPosition.y;
      v10 = v1->mPosition.z - v2->mPosition.z;
    }
    else
    {
      v11 = this->mNextSubSegment;
      if ( v11 )
      {
        v8 = v11->mPosition.x - v1->mPosition.x;
        v9 = v11->mPosition.y - v1->mPosition.y;
        v10 = v11->mPosition.z - v1->mPosition.z;
      }
      else
      {
        v12 = this->mNextGate;
        if ( v12 )
        {
          v8 = v12->mPosition.x - v1->mPosition.x;
          v9 = v12->mPosition.y - v1->mPosition.y;
          v10 = v12->mPosition.z - v1->mPosition.z;
        }
        else
        {
          v13 = this->mPreviousGate;
          if ( v13 )
          {
            v8 = v1->mPosition.x - v13->mPosition.x;
            v9 = v1->mPosition.y - v13->mPosition.y;
            v10 = v1->mPosition.z - v13->mPosition.z;
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
      this->mDirection.x = v1->mEndPos.x - v1->mPosition.x;
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
void __fastcall UFG::RoadNetworkVisibleAreaEdge::SetCurrentSubSegment(UFG::RoadNetworkVisibleAreaEdge *this, UFG::RoadNetworkSubSegment *subSegment)
{
  unsigned int v2; // eax
  UFG::RoadNetworkNode *v3; // rsi
  UFG::RoadNetworkSubSegment *v4; // rdi
  UFG::RoadNetworkVisibleAreaEdge *v5; // rbx
  UFG::RoadNetworkSegment *v6; // rdx
  UFG::RoadNetworkSubSegment *v7; // rax

  v2 = this->mNodesToStart.size;
  v3 = 0i64;
  v4 = subSegment;
  v5 = this;
  if ( v2 )
    v3 = this->mNodesToStart.p[v2 - 1];
  v6 = subSegment->mParentNode;
  if ( v6 == (UFG::RoadNetworkSegment *)v3 )
  {
    v7 = this->mCurrentSubSegment;
    this->mNextSubSegment = 0i64;
    this->mPreviousSubSegment = v7;
  }
  else
  {
    UFG::RoadNetworkVisibleAreaEdge::AddNodeToPath(this, (UFG::RoadNetworkNode *)&v6->mType);
    if ( v3->mType.mValue == 1 )
      v5->mPreviousSubSegment = 0i64;
  }
  v5->mCurrentSubSegment = v4;
  ++v4->mActive;
  UFG::RoadNetworkVisibleAreaEdge::UpdateDirection(v5);
  UFG::RoadNetworkVisibleAreaEdge::RefreshT(v5);
  UFG::RoadNetworkVisibleArea::ClaimSubSegmentVisited(v5->mVisibleArea, v5->mCurrentSubSegment);
}

// File Line: 2038
// RVA: 0xDF900
void __fastcall UFG::RoadNetworkVisibleAreaEdge::RefreshT(UFG::RoadNetworkVisibleAreaEdge *this)
{
  UFG::RoadNetworkSubSegment *v1; // rax
  float *v2; // rax

  v1 = this->mCurrentSubSegment;
  if ( (float)((float)((float)((float)(v1->mBeginPos.y - v1->mPosition.y) * this->mDirection.y)
                     + (float)((float)(v1->mBeginPos.x - v1->mPosition.x) * this->mDirection.x))
             + (float)((float)(v1->mBeginPos.z - v1->mPosition.z) * this->mDirection.z)) <= 0.0 )
    v2 = v1->mEndTCollection;
  else
    v2 = v1->mBeginTCollection;
  this->mT = *v2;
}

// File Line: 2063
// RVA: 0xDABD0
UFG::RoadNetworkGate *__fastcall UFG::RoadNetworkVisibleAreaEdge::GetNextGate(UFG::RoadNetworkVisibleAreaEdge *this)
{
  UFG::RoadNetworkVisibleAreaEdge *v1; // rbx
  UFG::RoadNetworkGate *v2; // rsi
  UFG::RoadNetworkSegment *v3; // r15
  __int64 v4; // rax
  _QWORD *v5; // rcx
  UFG::RoadNetworkGate *v6; // rbp
  signed __int64 v7; // rcx
  __int64 v8; // rax
  UFG::RoadNetworkGate *v9; // r14
  UFG::RoadNetworkGate **v10; // r12
  UFG::RoadNetworkGate *v11; // rax
  UFG::RoadNetworkSubSegment *v12; // rax
  UFG::RoadNetworkSubSegment *v13; // rdi
  bool v14; // zf
  UFG::RoadNetworkSubSegment *v15; // rbx
  UFG::RoadNetworkSubSegment *v16; // rax
  UFG::qArray<UFG::RoadNetworkGate *,0> gateCollection; // [rsp+28h] [rbp-40h]

  v1 = this;
  v2 = 0i64;
  v3 = this->mCurrentSubSegment->mParentNode;
  v4 = v3->mGates.mOffset;
  if ( v4 )
    v5 = (__int64 *)((char *)&v3->mGates.mOffset + v4);
  else
    v5 = 0i64;
  v6 = (UFG::RoadNetworkGate *)((char *)v5 + *v5);
  if ( !*v5 )
    v6 = 0i64;
  if ( v4 )
    v7 = (signed __int64)&v3->mGates + v4;
  else
    v7 = 0i64;
  v8 = *(_QWORD *)(v7 + 8);
  if ( v8 )
    v9 = (UFG::RoadNetworkGate *)(v8 + v7 + 8);
  else
    v9 = 0i64;
  gateCollection.p = 0i64;
  *(_QWORD *)&gateCollection.size = 0i64;
  UFG::RoadNetworkSubSegment::GetGatesConnectedToSubSegment(v1->mCurrentSubSegment, &gateCollection);
  v10 = gateCollection.p;
  if ( gateCollection.size == 2 )
  {
    v2 = v9;
    if ( (float)((float)((float)((float)(v6->mPosition.y - v1->mCurrentSubSegment->mPosition.y) * v1->mDirection.y)
                       + (float)((float)(v6->mPosition.x - v1->mCurrentSubSegment->mPosition.x) * v1->mDirection.x))
               + (float)((float)(v6->mPosition.z - v1->mCurrentSubSegment->mPosition.z) * v1->mDirection.z)) > 0.0 )
      v2 = v6;
    goto LABEL_21;
  }
  if ( gateCollection.size == 1 )
  {
    v2 = *gateCollection.p;
    if ( (float)((float)((float)((float)((*gateCollection.p)->mPosition.y - v1->mCurrentSubSegment->mPosition.y)
                               * v1->mDirection.y)
                       + (float)((float)((*gateCollection.p)->mPosition.x - v1->mCurrentSubSegment->mPosition.x)
                               * v1->mDirection.x))
               + (float)((float)((*gateCollection.p)->mPosition.z - v1->mCurrentSubSegment->mPosition.z)
                       * v1->mDirection.z)) <= 0.0 )
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
  if ( v1->mPreviousSubSegment )
  {
    v12 = 0i64;
    v13 = v1->mCurrentSubSegment;
    v14 = 1;
    do
    {
      if ( !v14 )
        v13 = v12;
      v12 = UFG::RoadNetworkVisibleAreaEdge::GetNextSubSegment(v1);
      v14 = v12 == 0i64;
    }
    while ( v12 );
    v15 = UFG::RoadNetworkSegment::GetClosestSubSegment(v3, v6);
    v16 = UFG::RoadNetworkSegment::GetClosestSubSegment(v3, v9);
    if ( v15 == v13 )
    {
      v2 = v6;
    }
    else if ( v16 == v13 )
    {
      v2 = v9;
    }
  }
LABEL_31:
  if ( v10 )
    operator delete[](v10);
  return v2;
}

// File Line: 2152
// RVA: 0xD24E0
void __fastcall UFG::RoadNetworkVisibleAreaEdge::AttachSpawnPoints(UFG::RoadNetworkVisibleAreaEdge *this)
{
  UFG::RoadNetworkVisibleAreaEdge *v1; // rbx
  unsigned int v2; // edx
  __int64 v3; // rax
  __int64 v4; // rax
  UFG::RoadNetworkSubSegment *v5; // rax
  UFG::RoadNetworkSegment *v6; // rsi
  char v7; // r12
  __int64 v8; // r15
  __int64 v9; // rdi
  __int64 v10; // rbp
  __int64 v11; // r14
  __int64 v12; // rdx
  signed __int64 v13; // rax
  signed __int64 v14; // rcx
  __int64 v15; // rax
  _QWORD *v16; // rax
  __int64 v17; // rcx
  signed __int64 v18; // r8
  char *v19; // rcx
  __int64 v20; // rax
  char *v21; // rax
  char *v22; // rcx
  __int64 v23; // rax
  signed __int64 v24; // rax
  UFG::RoadNetworkSubSegment *v25; // rax
  float *v26; // rcx
  float v27; // xmm7_4
  signed __int64 v28; // rax
  signed __int64 v29; // rcx
  __int64 v30; // rax
  signed __int64 v31; // rax
  signed __int64 v32; // rcx
  unsigned int v33; // edx
  __int64 v34; // rax
  UFG::RoadNetworkConnection *v35; // rcx
  float v36; // xmm1_4
  float v37; // xmm0_4
  float v38; // xmm0_4
  __int64 v39; // r9
  __int64 v40; // rax
  signed __int64 v41; // rcx
  signed __int64 v42; // rax
  __int64 v43; // rcx
  UFG::RoadNetworkLane *v44; // r8
  UFG::RoadNetworkSubSegment *v45; // rdx
  UFG::RoadNetworkSpawnPoint *v46; // rcx

  v1 = this;
  v2 = 0;
  if ( this->mNumSpawnPoints )
  {
    do
    {
      v3 = *((_QWORD *)&this->mPrev + 3 * (v2 + 1i64));
      if ( v3 )
      {
        *(_QWORD *)(v3 + 24) = 0i64;
        *(_DWORD *)(v3 + 32) = 0;
        v4 = *((_QWORD *)&this->mNext + 3 * (v2 + 1i64));
        --*(_DWORD *)(v4 + 48);
        *((_QWORD *)&this->mNext + 3 * (v2 + 1i64)) = 0i64;
        *((_QWORD *)&this->mPrev + 3 * (v2 + 1i64)) = 0i64;
        *((_QWORD *)&this->mVisibleArea + 3 * (v2 + 1i64)) = 0i64;
      }
      ++v2;
    }
    while ( v2 < this->mNumSpawnPoints );
  }
  v5 = this->mCurrentSubSegment;
  this->mNumSpawnPoints = 0;
  v6 = v5->mParentNode;
  LODWORD(v5) = ((float)((float)((float)((float)(v5->mBeginPos.y - v5->mPosition.y) * this->mDirection.y)
                               + (float)((float)(v5->mBeginPos.x - v5->mPosition.x) * this->mDirection.x))
                       + (float)((float)(v5->mBeginPos.z - v5->mPosition.z) * this->mDirection.z)) <= 0.0)
              + 1;
  v7 = 0;
  v8 = (signed int)v5;
  if ( (_DWORD)v5 == 2 )
    v7 = 1;
  if ( v6->mNumLanes )
  {
    v9 = 0i64;
    v10 = 0i64;
    v11 = (unsigned __int8)v6->mNumLanes;
    do
    {
      v12 = v6->mLane.mOffset;
      if ( v12 )
        v13 = (signed __int64)&v6->mLane + v12;
      else
        v13 = 0i64;
      v14 = v9 + v13;
      v15 = *(_QWORD *)(v9 + v13);
      if ( v15 )
        v16 = (_QWORD *)(v14 + v15);
      else
        v16 = 0i64;
      v17 = v16[1];
      if ( v17 )
        v18 = (signed __int64)v16 + v17 + 8;
      else
        v18 = 0i64;
      if ( *v16 )
        v19 = (char *)v16 + *v16;
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
        v24 = (signed __int64)&v22[v23 + 8];
      else
        v24 = 0i64;
      if ( v7 == (v18 != v24) )
      {
        v25 = v1->mCurrentSubSegment;
        if ( v8 == 1 )
          v26 = v25->mBeginTCollection;
        else
          v26 = v25->mEndTCollection;
        v27 = v26[v10];
        if ( v12 )
          v28 = (signed __int64)&v6->mLane + v12;
        else
          v28 = 0i64;
        v29 = v9 + v28;
        v30 = *(_QWORD *)(v9 + v28);
        if ( v30 )
          v31 = v29 + v30;
        else
          v31 = 0i64;
        if ( *(_QWORD *)v31 )
          v32 = v31 + *(_QWORD *)v31;
        else
          v32 = 0i64;
        v33 = *(unsigned __int16 *)(v31 + 38);
        v34 = *(_QWORD *)(v32 + 32);
        if ( v34 )
          v35 = (UFG::RoadNetworkConnection *)(v34 + v32 + 32);
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
        v39 = v1->mNumSpawnPoints;
        if ( (unsigned int)v39 < 6 )
        {
          v40 = v6->mLane.mOffset;
          if ( v40 )
            v41 = (signed __int64)&v6->mLane + v40;
          else
            v41 = 0i64;
          v42 = v9 + v41;
          v43 = *(_QWORD *)(v9 + v41);
          v44 = (UFG::RoadNetworkLane *)(v43 + v42);
          if ( !v43 )
            v44 = 0i64;
          v45 = v1->mCurrentSubSegment;
          v46 = (UFG::RoadNetworkSpawnPoint *)((char *)v1 + 24 * (v39 + 1));
          v46->mLane = v44;
          v46->mSubSegment = v45;
          ++v45->mNumSpawnPoints;
          v44->mSpawnT = v38;
          v44->mSpawnPoint = v46;
          UFG::RoadNetworkSpawnPoint::Reset(v46);
          ++v1->mNumSpawnPoints;
        }
      }
      ++v10;
      v9 += 8i64;
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 2195
// RVA: 0xDE710
bool __fastcall UFG::RoadNetworkVisibleAreaEdge::IsOuterEdge(UFG::RoadNetworkVisibleAreaEdge *this)
{
  UFG::RoadNetworkVisibleAreaEdge *v1; // rbx
  UFG::RoadNetworkSubSegment *v2; // rax
  UFG::RoadNetworkGate *v4; // rax
  __int64 v5; // rcx
  signed __int64 v6; // rax
  bool v7; // cl
  unsigned int v8; // edx

  v1 = this;
  v2 = UFG::RoadNetworkVisibleAreaEdge::GetNextSubSegment(this);
  if ( v2 )
    return v2->mActive == 0;
  v4 = UFG::RoadNetworkVisibleAreaEdge::GetNextGate(v1);
  if ( !v4 )
    return 1;
  v5 = v4->mConnectedNode.mOffset;
  if ( !v5 )
    return 1;
  v6 = (signed __int64)&v4->mConnectedNode + v5;
  if ( !v6 )
    return 1;
  v7 = 0;
  if ( *(_WORD *)v6 == 1 )
  {
    v8 = *(_DWORD *)(v6 + 24);
    if ( !v8 )
      return 1;
    v7 = UFG::qBaseTreeRB::Get(&v1->mVisibleArea->mVisitedIntersections.mTree.mTree, v8) != 0i64;
  }
  return v7 == 0;
}

