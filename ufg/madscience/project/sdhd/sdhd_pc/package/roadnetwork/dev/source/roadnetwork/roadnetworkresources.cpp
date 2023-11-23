// File Line: 16
// RVA: 0xD1450
void __fastcall RoadNetworkInventory::Add(RoadNetworkInventory *this, UFG::RoadNetworkResource *resource_data)
{
  UFG::RoadNetworkResource *v4; // rcx
  unsigned int i; // edi
  __int64 mOffset; // rax
  char *v7; // rdx
  char *v8; // rcx
  UFG::RoadNetworkIntersection *v9; // rbx
  unsigned int v10; // edx
  __int64 v11; // rax
  __int64 v12; // rcx
  _QWORD *v13; // rdx
  UFG::RoadNetworkTrafficLightPhase *v14; // rdx
  unsigned int v15; // edi
  __int64 v16; // rax
  char *v17; // rdx
  char *v18; // rcx
  char *v19; // rbx
  UFG::qPropertySet *RoadPropertySet; // rax
  unsigned int v21; // esi
  unsigned int *v22; // rax

  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(resource_data);
    UFG::RoadNetworkTrafficLightLampData::Init();
  }
  v4 = resource_data;
  UFG::gpRoadNetworkResource = resource_data;
  for ( i = 0; i < UFG::gpRoadNetworkResource->mNumIntersections; v4 = UFG::gpRoadNetworkResource )
  {
    mOffset = v4->mIntersectionOffsetTable.mOffset;
    if ( mOffset )
      v7 = (char *)&v4->mIntersectionOffsetTable + mOffset;
    else
      v7 = 0i64;
    v8 = &v7[8 * i];
    v9 = (UFG::RoadNetworkIntersection *)&v8[*(_QWORD *)v8];
    if ( !*(_QWORD *)v8 )
      v9 = 0i64;
    UFG::RoadNetworkNode::Init(v9);
    v9->mEnableTimer = 1;
    UFG::OnlineManager::Instance();
    v10 = (int)UFG::qRandom((float)(unsigned __int8)v9->mNumLightPhases, &UFG::qDefaultSeed);
    *(_QWORD *)&v9->mCurrentPhaseIndex = v10;
    if ( v9->mNumLightPhases )
    {
      v11 = v9->mLightPhases.mOffset;
      v12 = v11 ? (__int64)&v9->mLightPhases + v11 : 0i64;
      v13 = (_QWORD *)(v12 + 8i64 * v10);
      if ( *v13 )
      {
        v14 = (UFG::RoadNetworkTrafficLightPhase *)((char *)v13 + *v13);
        if ( v14 )
          UFG::RoadNetworkIntersection::EnableLanes(v9, v14, 0);
      }
    }
    ++i;
  }
  v15 = 0;
  if ( v4->mNumSegments )
  {
    do
    {
      v16 = v4->mSegmentOffsetTable.mOffset;
      if ( v16 )
        v17 = (char *)&v4->mSegmentOffsetTable + v16;
      else
        v17 = 0i64;
      v18 = &v17[8 * v15];
      v19 = &v18[*(_QWORD *)v18];
      if ( !*(_QWORD *)v18 )
        v19 = 0i64;
      *((_QWORD *)v19 + 13) = 0i64;
      RoadPropertySet = UFG::RoadNetworkSegment::GetRoadPropertySet((UFG::RoadNetworkSegment *)v19);
      v21 = 0;
      if ( RoadPropertySet )
      {
        v22 = UFG::qPropertySet::Get<unsigned long>(RoadPropertySet, &qSymbol_RoadNetworkType, DEPTH_RECURSE);
        if ( v22 )
          v21 = *v22;
      }
      *((_DWORD *)v19 + 34) = v21;
      UFG::RoadNetworkNode::Init((UFG::RoadNetworkNode *)v19);
      *((_QWORD *)v19 + 15) = v19 + 120;
      *((_QWORD *)v19 + 16) = v19 + 120;
      UFG::RoadNetworkSegment::CreateSubSegments((UFG::RoadNetworkSegment *)v19);
      *((_DWORD *)v19 + 42) &= 0xFFFFFF80;
      if ( *((float *)v19 + 41) == 0.0 )
        *((_DWORD *)v19 + 41) = 1096693988;
      ++v15;
      v4 = UFG::gpRoadNetworkResource;
    }
    while ( v15 < UFG::gpRoadNetworkResource->mNumSegments );
  }
  UFG::RoadNetworkResource::InitDataGrids(v4);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 48
// RVA: 0xDFDC0
void __fastcall RoadNetworkInventory::Remove(RoadNetworkInventory *this, UFG::RoadNetworkResource *resource_data)
{
  unsigned int i; // ebx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mOffset; // rax
  char *v5; // rcx
  char *v6; // rdx
  UFG::RoadNetworkIntersection *v7; // rcx
  unsigned int j; // ebx
  __int64 v9; // rax
  char *v10; // rcx
  char *v11; // rdx
  UFG::RoadNetworkSegment *v12; // rcx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rdi
  UFG::qResourceHandle *k; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v17; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v18; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *m; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v20; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v21; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v22; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v23; // rax

  UFG::qResourceInventory::Remove(this, resource_data);
  UFG::RoadNetworkResource::ClearDataGrids(resource_data);
  for ( i = 0; i < resource_data->mNumIntersections; ++i )
  {
    mOffset = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)resource_data->mIntersectionOffsetTable.mOffset;
    if ( mOffset )
      v5 = (char *)&resource_data->mIntersectionOffsetTable + (_QWORD)mOffset;
    else
      v5 = 0i64;
    v6 = &v5[8 * i];
    v7 = (UFG::RoadNetworkIntersection *)&v6[*(_QWORD *)v6];
    if ( !*(_QWORD *)v6 )
      v7 = 0i64;
    UFG::RoadNetworkIntersection::~RoadNetworkIntersection(v7);
  }
  for ( j = 0; j < resource_data->mNumSegments; ++j )
  {
    v9 = resource_data->mSegmentOffsetTable.mOffset;
    if ( v9 )
      v10 = (char *)&resource_data->mSegmentOffsetTable + v9;
    else
      v10 = 0i64;
    v11 = &v10[8 * j];
    v12 = (UFG::RoadNetworkSegment *)&v11[*(_QWORD *)v11];
    if ( !*(_QWORD *)v11 )
      v12 = 0i64;
    UFG::RoadNetworkSegment::~RoadNetworkSegment(v12);
  }
  p_mResourceHandles = &resource_data->mResourceHandles;
  for ( k = (UFG::qResourceHandle *)p_mResourceHandles->mNode.mNext;
        k != (UFG::qResourceHandle *)p_mResourceHandles;
        k = (UFG::qResourceHandle *)p_mResourceHandles->mNode.mNext )
  {
    mPrev = k->mPrev;
    mNext = k->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    k->mPrev = k;
    k->mNext = k;
    UFG::qResourceHandle::~qResourceHandle(k);
    operator delete[](k);
  }
  v17 = p_mResourceHandles->mNode.mPrev;
  v18 = p_mResourceHandles->mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  p_mResourceHandles->mNode.mPrev = &p_mResourceHandles->mNode;
  p_mResourceHandles->mNode.mNext = &p_mResourceHandles->mNode;
  UFG::gpRoadNetworkResource = 0i64;
  if ( (_S3_3 & 1) == 0 )
  {
    _S3_3 |= 1u;
    allocator.mpPool = UFG::gMainMemoryPool;
    dword_142175178 = 0x4000;
    qword_142175180 = (__int64)"RoadNetworkSubSegment";
    qword_142175188 = 0i64;
    qword_142175190 = 0i64;
    dword_142175198 = 0;
    stru_1421751A0.mNode.mPrev = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)&stru_1421751A0;
    stru_1421751A0.mNode.mNext = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)&stru_1421751A0;
    atexit(GetLaneTAllocator_::_2_::_dynamic_atexit_destructor_for__allocator__);
  }
  for ( m = stru_1421751A0.mNode.mNext;
        (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)stru_1421751A0.mNode.mNext != &stru_1421751A0;
        m = stru_1421751A0.mNode.mNext )
  {
    v20 = m->mPrev;
    v21 = m->mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    m->mPrev = m;
    m->mNext = m;
    v22 = m->mPrev;
    v23 = m->mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    m->mPrev = m;
    m->mNext = m;
    operator delete[](m);
  }
  qword_142175188 = 0i64;
  qword_142175190 = 0i64;
  dword_142175198 = 0;
}operator delete[](m);
  }
  qword_142175188 = 0i64;
  qword_142175190 = 0i64;
  dwor

// File Line: 80
// RVA: 0x14609D0
__int64 dynamic_initializer_for__gRoadNetworkInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &gRoadNetworkInventory,
    "RoadNetworkInventory",
    0xA4F6DEDB,
    0x94132761,
    0,
    0);
  gRoadNetworkInventory.vfptr = (UFG::qResourceInventoryVtbl *)&RoadNetworkInventory::`vftable;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gRoadNetworkInventory__);
}

// File Line: 106
// RVA: 0xDC0D0
UFG::RoadNetworkTrafficLightLocation *__fastcall UFG::RoadNetworkResource::GetTrafficLightNearPosition(
        UFG::RoadNetworkResource *this,
        UFG::qVector3 *pos)
{
  float *v3; // rbx
  __int64 i; // r15
  UFG::qReflectInventoryBase *v5; // r14
  __int64 v6; // rsi
  unsigned int j; // ebp
  __int64 mCount; // rax
  char *v9; // rcx
  char *v10; // rdx
  char *v11; // r8
  int v12; // r11d
  unsigned int v13; // r10d
  __int64 v14; // r9
  __int64 v15; // rax
  char *v16; // rcx
  float ***v17; // rdx
  float **v18; // rcx
  float *v19; // rdx
  float y; // xmm3_4
  float x; // xmm2_4
  char *v22; // rcx
  __int64 v23; // rdx
  float **v24; // rcx
  char *v25; // rcx
  __int64 v26; // rdx
  float **v27; // rcx
  char *v28; // rcx
  char *v29; // rax
  char *v30; // rax
  float *v31; // rdx
  __int64 v32; // rdx
  __int64 v33; // rax
  char *v34; // rcx
  char *v35; // rax
  __int64 v36; // rcx
  float **v37; // rax
  float *v38; // rcx
  UFG::qArray<UFG::qReflectInventoryBase *,0> v40; // [rsp+38h] [rbp-40h] BYREF

  v40.p = 0i64;
  *(_QWORD *)&v40.size = 0i64;
  UFG::RoadNetworkResource::GetIntersectionsInGrid(this, &v40, pos, 0, 20.0);
  v3 = 0i64;
  for ( i = 0i64; (unsigned int)i < v40.size; i = (unsigned int)(i + 1) )
  {
    if ( v3 )
      break;
    v5 = v40.p[i];
    v6 = 0i64;
    for ( j = BYTE3(v5->mItems.mTree.mHead.mNeighbours[1]); (unsigned int)v6 < j; v6 = (unsigned int)(v6 + 1) )
    {
      if ( v3 )
        break;
      if ( (_BYTE)j
        && ((mCount = v5->mItems.mTree.mCount) == 0 ? (v9 = 0i64) : (v9 = (char *)&v5->mItems.mTree.mCount + mCount),
            v10 = &v9[8 * v6],
            *(_QWORD *)v10) )
      {
        v11 = &v10[*(_QWORD *)v10];
      }
      else
      {
        v11 = 0i64;
      }
      v12 = *((_DWORD *)v11 + 5);
      v13 = 0;
      v14 = 0i64;
      if ( v12 < 4 )
      {
LABEL_52:
        if ( v13 < v12 )
        {
          v32 = 8 * v14;
          do
          {
            if ( v3 )
              break;
            v33 = *((_QWORD *)v11 + 6);
            if ( v33 )
              v34 = &v11[v33 + 48];
            else
              v34 = 0i64;
            v35 = &v34[v32];
            v36 = *(_QWORD *)&v34[v32];
            if ( v36 )
              v37 = (float **)&v35[v36];
            else
              v37 = 0i64;
            v38 = *v37;
            if ( *v37 )
              v38 = (float *)((char *)v38 + (_QWORD)v37);
            if ( (float)((float)((float)(pos->x - *v38) * (float)(pos->x - *v38))
                       + (float)((float)(pos->y - v38[1]) * (float)(pos->y - v38[1]))) < 1.0 )
              v3 = v38;
            v32 += 8i64;
            ++v13;
          }
          while ( v13 < v12 );
        }
      }
      else
      {
        while ( !v3 )
        {
          v15 = *((_QWORD *)v11 + 6);
          if ( v15 )
            v16 = &v11[v15 + 48];
          else
            v16 = 0i64;
          v17 = (float ***)&v16[8 * v14];
          v18 = *v17;
          if ( *v17 )
            v18 = (float **)((char *)v18 + (_QWORD)v17);
          v19 = *v18;
          if ( *v18 )
            v19 = (float *)((char *)v19 + (_QWORD)v18);
          y = pos->y;
          x = pos->x;
          if ( (float)((float)((float)(pos->x - *v19) * (float)(pos->x - *v19))
                     + (float)((float)(y - v19[1]) * (float)(y - v19[1]))) < 1.0 )
            goto LABEL_51;
          if ( v15 )
            v22 = &v11[v15 + 48];
          else
            v22 = 0i64;
          v23 = (__int64)&v22[8 * v14 + 8];
          v24 = *(float ***)v23;
          if ( *(_QWORD *)v23 )
            v24 = (float **)((char *)v24 + v23);
          v19 = *v24;
          if ( *v24 )
            v19 = (float *)((char *)v19 + (_QWORD)v24);
          if ( (float)((float)((float)(x - *v19) * (float)(x - *v19))
                     + (float)((float)(y - v19[1]) * (float)(y - v19[1]))) < 1.0 )
            goto LABEL_51;
          if ( v15 )
            v25 = &v11[v15 + 48];
          else
            v25 = 0i64;
          v26 = (__int64)&v25[8 * v14 + 16];
          v27 = *(float ***)v26;
          if ( *(_QWORD *)v26 )
            v27 = (float **)((char *)v27 + v26);
          v19 = *v27;
          if ( *v27 )
            v19 = (float *)((char *)v19 + (_QWORD)v27);
          if ( (float)((float)((float)(x - *v19) * (float)(x - *v19))
                     + (float)((float)(y - v19[1]) * (float)(y - v19[1]))) < 1.0 )
          {
LABEL_51:
            v3 = v19;
            break;
          }
          if ( v15 )
            v28 = &v11[v15 + 48];
          else
            v28 = 0i64;
          v29 = &v28[8 * v14 + 24];
          if ( *(_QWORD *)v29 )
            v30 = &v29[*(_QWORD *)v29];
          else
            v30 = 0i64;
          if ( *(_QWORD *)v30 )
            v31 = (float *)&v30[*(_QWORD *)v30];
          else
            v31 = 0i64;
          if ( (float)((float)((float)(x - *v31) * (float)(x - *v31))
                     + (float)((float)(y - v31[1]) * (float)(y - v31[1]))) < 1.0 )
            v3 = v31;
          v14 += 4i64;
          v13 += 4;
          if ( v13 >= v12 - 3 )
            goto LABEL_52;
        }
      }
    }
  }
  if ( v40.p )
    operator delete[](v40.p);
  return (UFG::RoadNetworkTrafficLightLocation *)v3;
}

// File Line: 159
// RVA: 0xD8F30
UFG::RoadNetworkIntersection *__fastcall UFG::RoadNetworkResource::GetIntersection(
        UFG::RoadNetworkResource *this,
        unsigned int index)
{
  __int64 mOffset; // rax
  char *v3; // rcx
  UFG::RoadNetworkIntersection **v4; // rdx
  UFG::RoadNetworkIntersection *result; // rax

  mOffset = this->mIntersectionOffsetTable.mOffset;
  if ( mOffset )
    v3 = (char *)&this->mIntersectionOffsetTable + mOffset;
  else
    v3 = 0i64;
  v4 = (UFG::RoadNetworkIntersection **)&v3[8 * index];
  result = *v4;
  if ( *v4 )
    return (UFG::RoadNetworkIntersection *)((char *)result + (_QWORD)v4);
  return result;
}

// File Line: 168
// RVA: 0xD9180
UFG::RoadNetworkIntersection *__fastcall UFG::RoadNetworkResource::GetIntersectionWithLights(
        UFG::RoadNetworkResource *this,
        unsigned int index)
{
  __int64 mOffset; // rax
  char *v3; // rcx
  UFG::RoadNetworkIntersection **v4; // rdx
  UFG::RoadNetworkIntersection *result; // rax

  mOffset = this->mIntersectionWithLightsOffsetTable.mOffset;
  if ( mOffset )
    v3 = (char *)&this->mIntersectionWithLightsOffsetTable + mOffset;
  else
    v3 = 0i64;
  v4 = (UFG::RoadNetworkIntersection **)&v3[8 * index];
  result = *v4;
  if ( *v4 )
    return (UFG::RoadNetworkIntersection *)((char *)result + (_QWORD)v4);
  return result;
}

// File Line: 177
// RVA: 0xDB9D0
UFG::RoadNetworkSegment *__fastcall UFG::RoadNetworkResource::GetSegment(
        UFG::RoadNetworkResource *this,
        unsigned int index)
{
  __int64 mOffset; // rax
  char *v3; // rcx
  UFG::RoadNetworkSegment **v4; // rdx
  UFG::RoadNetworkSegment *result; // rax

  mOffset = this->mSegmentOffsetTable.mOffset;
  if ( mOffset )
    v3 = (char *)&this->mSegmentOffsetTable + mOffset;
  else
    v3 = 0i64;
  v4 = (UFG::RoadNetworkSegment **)&v3[8 * index];
  result = *v4;
  if ( *v4 )
    return (UFG::RoadNetworkSegment *)((char *)result + (_QWORD)v4);
  return result;
}

// File Line: 195
// RVA: 0xDC7A0
UFG::RoadNetworkWayfindingList *__fastcall UFG::RoadNetworkResource::GetWayfindingList(UFG::RoadNetworkResource *this)
{
  UFG::RoadNetworkWayfindingList *result; // rax

  result = (UFG::RoadNetworkWayfindingList *)this->mWayfindingList.mOffset;
  if ( result )
    return (UFG::RoadNetworkWayfindingList *)((char *)result + (_QWORD)this + 152);
  return result;
}

