// File Line: 16
// RVA: 0xD1450
void __fastcall RoadNetworkInventory::Add(RoadNetworkInventory *this, UFG::qResourceData *resource_data)
{
  UFG::RoadNetworkResource *v2; // rbp
  RoadNetworkInventory *v3; // r14
  UFG::RoadNetworkResource *v4; // rcx
  unsigned int v5; // edi
  __int64 v6; // rax
  signed __int64 v7; // rdx
  _QWORD *v8; // rcx
  UFG::RoadNetworkIntersection *v9; // rbx
  unsigned int v10; // edx
  __int64 v11; // rax
  signed __int64 v12; // rcx
  _QWORD *v13; // rdx
  UFG::RoadNetworkTrafficLightPhase *v14; // rdx
  unsigned int v15; // edi
  __int64 v16; // rax
  signed __int64 v17; // rdx
  _QWORD *v18; // rcx
  char *v19; // rbx
  UFG::qPropertySet *v20; // rax
  unsigned int v21; // esi
  unsigned int *v22; // rax
  _QWORD *v23; // rax

  v2 = (UFG::RoadNetworkResource *)resource_data;
  v3 = this;
  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(resource_data);
    UFG::RoadNetworkTrafficLightLampData::Init();
  }
  v4 = v2;
  UFG::gpRoadNetworkResource = v2;
  v5 = 0;
  if ( v2->mNumIntersections )
  {
    do
    {
      v6 = v4->mIntersectionOffsetTable.mOffset;
      if ( v6 )
        v7 = (signed __int64)&v4->mIntersectionOffsetTable + v6;
      else
        v7 = 0i64;
      v8 = (_QWORD *)(v7 + 8i64 * v5);
      v9 = (UFG::RoadNetworkIntersection *)((char *)v8 + *v8);
      if ( !*v8 )
        v9 = 0i64;
      UFG::RoadNetworkNode::Init((UFG::RoadNetworkNode *)&v9->mType);
      v9->mEnableTimer = 1;
      UFG::OnlineManager::Instance();
      v10 = (signed int)UFG::qRandom((float)(unsigned __int8)v9->mNumLightPhases, &UFG::qDefaultSeed);
      *(_QWORD *)&v9->mCurrentPhaseIndex = v10;
      if ( v9->mNumLightPhases )
      {
        v11 = v9->mLightPhases.mOffset;
        v12 = (signed __int64)(v11 ? (UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkTrafficLightPhase *> *> *)((char *)&v9->mLightPhases + v11) : 0i64);
        v13 = (_QWORD *)(v12 + 8i64 * v10);
        if ( *v13 )
        {
          v14 = (UFG::RoadNetworkTrafficLightPhase *)((char *)v13 + *v13);
          if ( v14 )
            UFG::RoadNetworkIntersection::EnableLanes(v9, v14, 0);
        }
      }
      ++v5;
      v4 = UFG::gpRoadNetworkResource;
    }
    while ( v5 < UFG::gpRoadNetworkResource->mNumIntersections );
  }
  v15 = 0;
  if ( v4->mNumSegments > 0 )
  {
    do
    {
      v16 = v4->mSegmentOffsetTable.mOffset;
      if ( v16 )
        v17 = (signed __int64)&v4->mSegmentOffsetTable + v16;
      else
        v17 = 0i64;
      v18 = (_QWORD *)(v17 + 8i64 * v15);
      v19 = (char *)v18 + *v18;
      if ( !*v18 )
        v19 = 0i64;
      *((_QWORD *)v19 + 13) = 0i64;
      v20 = UFG::RoadNetworkSegment::GetRoadPropertySet((UFG::RoadNetworkSegment *)v19);
      v21 = 0;
      if ( v20 )
      {
        v22 = UFG::qPropertySet::Get<unsigned long>(v20, (UFG::qSymbol *)&qSymbol_RoadNetworkType.mUID, DEPTH_RECURSE);
        if ( v22 )
          v21 = *v22;
      }
      *((_DWORD *)v19 + 34) = v21;
      UFG::RoadNetworkNode::Init((UFG::RoadNetworkNode *)v19);
      v23 = v19 + 120;
      *v23 = v23;
      v23[1] = v23;
      UFG::RoadNetworkSegment::CreateSubSegments((UFG::RoadNetworkSegment *)v19);
      *((_DWORD *)v19 + 42) &= 0xFFFFFF80;
      if ( 0.0 == *((float *)v19 + 41) )
        *((_DWORD *)v19 + 41) = 1096693988;
      ++v15;
      v4 = UFG::gpRoadNetworkResource;
    }
    while ( v15 < UFG::gpRoadNetworkResource->mNumSegments );
  }
  UFG::RoadNetworkResource::InitDataGrids(v4);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)&v2->mNode);
}

// File Line: 48
// RVA: 0xDFDC0
void __fastcall RoadNetworkInventory::Remove(RoadNetworkInventory *this, UFG::qResourceData *resource_data)
{
  UFG::RoadNetworkResource *v2; // rdi
  unsigned int v3; // ebx
  __int64 v4; // rax
  signed __int64 v5; // rcx
  _QWORD *v6; // rdx
  UFG::RoadNetworkIntersection *v7; // rcx
  unsigned int i; // ebx
  __int64 v9; // rax
  signed __int64 v10; // rcx
  _QWORD *v11; // rdx
  UFG::RoadNetworkSegment *v12; // rcx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v13; // rdi
  UFG::qResourceHandle *j; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v15; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v16; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v17; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v18; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *k; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v20; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v21; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v22; // rdx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v23; // rax

  v2 = (UFG::RoadNetworkResource *)resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  UFG::RoadNetworkResource::ClearDataGrids(v2);
  v3 = 0;
  if ( v2->mNumIntersections )
  {
    do
    {
      v4 = v2->mIntersectionOffsetTable.mOffset;
      if ( v4 )
        v5 = (signed __int64)&v2->mIntersectionOffsetTable + v4;
      else
        v5 = 0i64;
      v6 = (_QWORD *)(v5 + 8i64 * v3);
      v7 = (UFG::RoadNetworkIntersection *)((char *)v6 + *v6);
      if ( !*v6 )
        v7 = 0i64;
      UFG::RoadNetworkIntersection::~RoadNetworkIntersection(v7);
      ++v3;
    }
    while ( v3 < v2->mNumIntersections );
  }
  for ( i = 0; i < v2->mNumSegments; ++i )
  {
    v9 = v2->mSegmentOffsetTable.mOffset;
    if ( v9 )
      v10 = (signed __int64)&v2->mSegmentOffsetTable + v9;
    else
      v10 = 0i64;
    v11 = (_QWORD *)(v10 + 8i64 * i);
    v12 = (UFG::RoadNetworkSegment *)((char *)v11 + *v11);
    if ( !*v11 )
      v12 = 0i64;
    UFG::RoadNetworkSegment::~RoadNetworkSegment(v12);
  }
  v13 = &v2->mResourceHandles;
  for ( j = (UFG::qResourceHandle *)v13->mNode.mNext;
        j != (UFG::qResourceHandle *)v13;
        j = (UFG::qResourceHandle *)v13->mNode.mNext )
  {
    v15 = j->mPrev;
    v16 = j->mNext;
    v15->mNext = v16;
    v16->mPrev = v15;
    j->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&j->mPrev;
    j->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&j->mPrev;
    UFG::qResourceHandle::~qResourceHandle(j);
    operator delete[](j);
  }
  v17 = v13->mNode.mPrev;
  v18 = v13->mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v13->mNode.mPrev = &v13->mNode;
  v13->mNode.mNext = &v13->mNode;
  UFG::gpRoadNetworkResource = 0i64;
  if ( !(_S3_3 & 1) )
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
  for ( k = stru_1421751A0.mNode.mNext;
        (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)stru_1421751A0.mNode.mNext != &stru_1421751A0;
        k = stru_1421751A0.mNode.mNext )
  {
    v20 = k->mPrev;
    v21 = k->mNext;
    v20->mNext = v21;
    v21->mPrev = v20;
    k->mPrev = k;
    k->mNext = k;
    v22 = k->mPrev;
    v23 = k->mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    k->mPrev = k;
    k->mNext = k;
    operator delete[](k);
  }
  qword_142175188 = 0i64;
  qword_142175190 = 0i64;
  dword_142175198 = 0;
}k;
    operator delete[](k);
  }
  qword_142175188 = 0i64;
  qword_142175190 = 0i64;
  dword_142175198 =

// File Line: 80
// RVA: 0x14609D0
__int64 dynamic_initializer_for__gRoadNetworkInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&gRoadNetworkInventory.vfptr,
    "RoadNetworkInventory",
    0xA4F6DEDB,
    0x94132761,
    0,
    0);
  gRoadNetworkInventory.vfptr = (UFG::qResourceInventoryVtbl *)&RoadNetworkInventory::`vftable';
  return atexit(dynamic_atexit_destructor_for__gRoadNetworkInventory__);
}

// File Line: 106
// RVA: 0xDC0D0
UFG::RoadNetworkTrafficLightLocation *__fastcall UFG::RoadNetworkResource::GetTrafficLightNearPosition(UFG::RoadNetworkResource *this, UFG::qVector3 *pos)
{
  UFG::qVector3 *v2; // rdi
  float *v3; // rbx
  __int64 v4; // r15
  __int64 v5; // r14
  __int64 v6; // rsi
  unsigned int v7; // ebp
  __int64 v8; // rax
  signed __int64 v9; // rcx
  _QWORD *v10; // rdx
  char *v11; // r8
  unsigned int v12; // er11
  unsigned int v13; // er10
  __int64 v14; // r9
  __int64 v15; // rax
  signed __int64 v16; // rcx
  float ***v17; // rdx
  float **v18; // rcx
  float *v19; // rdx
  float v20; // xmm3_4
  float v21; // xmm2_4
  signed __int64 v22; // rcx
  signed __int64 v23; // rdx
  float **v24; // rcx
  signed __int64 v25; // rcx
  signed __int64 v26; // rdx
  float **v27; // rcx
  signed __int64 v28; // rcx
  _QWORD *v29; // rax
  _QWORD *v30; // rax
  float *v31; // rdx
  signed __int64 v32; // rdx
  __int64 v33; // rax
  signed __int64 v34; // rcx
  signed __int64 v35; // rax
  __int64 v36; // rcx
  float **v37; // rax
  float *v38; // rcx
  __int64 v40; // [rsp+38h] [rbp-40h]
  void *mem; // [rsp+40h] [rbp-38h]

  v2 = pos;
  mem = 0i64;
  v40 = 0i64;
  UFG::RoadNetworkResource::GetIntersectionsInGrid(this, (UFG::qArray<UFG::RoadNetworkNode *,0> *)&v40, pos, 0, 20.0);
  v3 = 0i64;
  v4 = 0i64;
  if ( (_DWORD)v40 )
  {
    do
    {
      if ( v3 )
        break;
      v5 = *((_QWORD *)mem + v4);
      v6 = 0i64;
      v7 = *(unsigned __int8 *)(v5 + 107);
      if ( *(_BYTE *)(v5 + 107) )
      {
        do
        {
          if ( v3 )
            break;
          if ( (_BYTE)v7
            && ((v8 = *(_QWORD *)(v5 + 112)) == 0 ? (v9 = 0i64) : (v9 = v8 + v5 + 112),
                v10 = (_QWORD *)(v9 + 8 * v6),
                *v10) )
          {
            v11 = (char *)v10 + *v10;
          }
          else
          {
            v11 = 0i64;
          }
          v12 = *((_DWORD *)v11 + 5);
          v13 = 0;
          v14 = 0i64;
          if ( (signed int)v12 < 4 )
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
                  v34 = (signed __int64)&v11[v33 + 48];
                else
                  v34 = 0i64;
                v35 = v32 + v34;
                v36 = *(_QWORD *)(v32 + v34);
                if ( v36 )
                  v37 = (float **)(v36 + v35);
                else
                  v37 = 0i64;
                v38 = *v37;
                if ( *v37 )
                  v38 = (float *)((char *)v38 + (_QWORD)v37);
                if ( (float)((float)((float)(v2->x - *v38) * (float)(v2->x - *v38))
                           + (float)((float)(v2->y - v38[1]) * (float)(v2->y - v38[1]))) < 1.0 )
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
                v16 = (signed __int64)&v11[v15 + 48];
              else
                v16 = 0i64;
              v17 = (float ***)(v16 + 8 * v14);
              v18 = *v17;
              if ( *v17 )
                v18 = (float **)((char *)v18 + (_QWORD)v17);
              v19 = *v18;
              if ( *v18 )
                v19 = (float *)((char *)v19 + (_QWORD)v18);
              v20 = v2->y;
              v21 = v2->x;
              if ( (float)((float)((float)(v2->x - *v19) * (float)(v2->x - *v19))
                         + (float)((float)(v2->y - v19[1]) * (float)(v2->y - v19[1]))) < 1.0 )
                goto LABEL_73;
              if ( v15 )
                v22 = (signed __int64)&v11[v15 + 48];
              else
                v22 = 0i64;
              v23 = v22 + 8 + 8 * v14;
              v24 = *(float ***)v23;
              if ( *(_QWORD *)v23 )
                v24 = (float **)((char *)v24 + v23);
              v19 = *v24;
              if ( *v24 )
                v19 = (float *)((char *)v19 + (_QWORD)v24);
              if ( (float)((float)((float)(v21 - *v19) * (float)(v21 - *v19))
                         + (float)((float)(v20 - v19[1]) * (float)(v20 - v19[1]))) < 1.0 )
                goto LABEL_73;
              if ( v15 )
                v25 = (signed __int64)&v11[v15 + 48];
              else
                v25 = 0i64;
              v26 = v25 + 16 + 8 * v14;
              v27 = *(float ***)v26;
              if ( *(_QWORD *)v26 )
                v27 = (float **)((char *)v27 + v26);
              v19 = *v27;
              if ( *v27 )
                v19 = (float *)((char *)v19 + (_QWORD)v27);
              if ( (float)((float)((float)(v21 - *v19) * (float)(v21 - *v19))
                         + (float)((float)(v20 - v19[1]) * (float)(v20 - v19[1]))) < 1.0 )
              {
LABEL_73:
                v3 = v19;
                break;
              }
              if ( v15 )
                v28 = (signed __int64)&v11[v15 + 48];
              else
                v28 = 0i64;
              v29 = (_QWORD *)(v28 + 24 + 8 * v14);
              if ( *v29 )
                v30 = (_QWORD *)((char *)v29 + *v29);
              else
                v30 = 0i64;
              if ( *v30 )
                v31 = (float *)((char *)v30 + *v30);
              else
                v31 = 0i64;
              if ( (float)((float)((float)(v21 - *v31) * (float)(v21 - *v31))
                         + (float)((float)(v20 - v31[1]) * (float)(v20 - v31[1]))) < 1.0 )
                v3 = v31;
              v14 += 4i64;
              v13 += 4;
              if ( v13 >= v12 - 3 )
                goto LABEL_52;
            }
          }
          v6 = (unsigned int)(v6 + 1);
        }
        while ( (unsigned int)v6 < v7 );
      }
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < (unsigned int)v40 );
  }
  if ( mem )
    operator delete[](mem);
  return (UFG::RoadNetworkTrafficLightLocation *)v3;
}

// File Line: 159
// RVA: 0xD8F30
UFG::RoadNetworkIntersection *__fastcall UFG::RoadNetworkResource::GetIntersection(UFG::RoadNetworkResource *this, unsigned int index)
{
  __int64 v2; // rax
  char *v3; // rcx
  __int64 v4; // rax
  signed __int64 v5; // rdx
  UFG::RoadNetworkIntersection *result; // rax

  v2 = this->mIntersectionOffsetTable.mOffset;
  if ( v2 )
    v3 = (char *)&this->mIntersectionOffsetTable + v2;
  else
    v3 = 0i64;
  v4 = index;
  v5 = (signed __int64)&v3[8 * v4];
  result = *(UFG::RoadNetworkIntersection **)&v3[8 * v4];
  if ( result )
    result = (UFG::RoadNetworkIntersection *)((char *)result + v5);
  return result;
}

// File Line: 168
// RVA: 0xD9180
UFG::RoadNetworkIntersection *__fastcall UFG::RoadNetworkResource::GetIntersectionWithLights(UFG::RoadNetworkResource *this, unsigned int index)
{
  __int64 v2; // rax
  char *v3; // rcx
  __int64 v4; // rax
  signed __int64 v5; // rdx
  UFG::RoadNetworkIntersection *result; // rax

  v2 = this->mIntersectionWithLightsOffsetTable.mOffset;
  if ( v2 )
    v3 = (char *)&this->mIntersectionWithLightsOffsetTable + v2;
  else
    v3 = 0i64;
  v4 = index;
  v5 = (signed __int64)&v3[8 * v4];
  result = *(UFG::RoadNetworkIntersection **)&v3[8 * v4];
  if ( result )
    result = (UFG::RoadNetworkIntersection *)((char *)result + v5);
  return result;
}

// File Line: 177
// RVA: 0xDB9D0
UFG::RoadNetworkSegment *__fastcall UFG::RoadNetworkResource::GetSegment(UFG::RoadNetworkResource *this, unsigned int index)
{
  __int64 v2; // rax
  char *v3; // rcx
  __int64 v4; // rax
  signed __int64 v5; // rdx
  UFG::RoadNetworkSegment *result; // rax

  v2 = this->mSegmentOffsetTable.mOffset;
  if ( v2 )
    v3 = (char *)&this->mSegmentOffsetTable + v2;
  else
    v3 = 0i64;
  v4 = index;
  v5 = (signed __int64)&v3[8 * v4];
  result = *(UFG::RoadNetworkSegment **)&v3[8 * v4];
  if ( result )
    result = (UFG::RoadNetworkSegment *)((char *)result + v5);
  return result;
}

// File Line: 195
// RVA: 0xDC7A0
UFG::RoadNetworkWayfindingList *__fastcall UFG::RoadNetworkResource::GetWayfindingList(UFG::RoadNetworkResource *this)
{
  UFG::RoadNetworkWayfindingList *result; // rax

  result = (UFG::RoadNetworkWayfindingList *)this->mWayfindingList.mOffset;
  if ( result )
    result = (UFG::RoadNetworkWayfindingList *)((char *)result + (_QWORD)this + 152);
  return result;
}

