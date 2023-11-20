// File Line: 83
// RVA: 0x1460910
hkSeekableStreamReader *dynamic_initializer_for__UFG::ClosestSegmentCache::mNodeCacheItem__()
{
  hkSeekableStreamReader *v0; // rbx
  signed int v1; // edi
  hkSeekableStreamReader *result; // rax

  v0 = &UFG::ClosestSegmentCache::mNodeCacheItem;
  v1 = 31;
  do
  {
    result = Assembly::GetRCX(v0);
    v0 += 2;
    --v1;
  }
  while ( v1 >= 0 );
  return result;
}

// File Line: 115
// RVA: 0xDD100
void __fastcall UFG::RoadNetworkResource::InitDataGrids(UFG::RoadNetworkResource *this)
{
  UFG::RoadNetworkResource *v1; // r13
  float *v2; // rax
  signed __int64 v3; // r14
  signed __int64 v4; // rdx
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  unsigned int v8; // esi
  __int64 v9; // rax
  signed __int64 v10; // rcx
  _QWORD *v11; // rdx
  char *v12; // rax
  unsigned __int8 v13; // dl
  __int64 v14; // rcx
  signed __int64 v15; // rcx
  _QWORD *v16; // rdx
  float *v17; // rdi
  char *v18; // rax
  __int64 v19; // rcx
  UFG::RoadNetworkConnection *v20; // rcx
  float v21; // xmm8_4
  float i; // xmm6_4
  char *v23; // rax
  __int64 v24; // rcx
  UFG::RoadNetworkConnection *v25; // rcx
  UFG::qBezierPathMemImaged *v26; // rax
  UFG::RoadNetworkConnection *v27; // rbx
  unsigned int v28; // eax
  UFG::qBezierSplineMemImaged *v29; // rax
  __int64 v30; // rdi
  UFG::Grid<UFG::RoadNetworkSegment> *v31; // rax
  UFG::Grid<UFG::RoadNetworkSegment> *v32; // rbx
  UFG::Grid<UFG::RoadNetworkSegment> *v33; // rax
  UFG::Grid<UFG::RoadNetworkSegment> *v34; // rbx
  unsigned int j; // er15
  int v36; // er14
  __int64 v37; // rax
  signed __int64 v38; // rcx
  _QWORD *v39; // rdx
  UFG::RoadNetworkSegment *v40; // rdi
  unsigned __int8 v41; // al
  __int64 v42; // rax
  __int64 v43; // rcx
  signed __int64 v44; // rcx
  _QWORD *v45; // rdx
  float *v46; // rsi
  char *v47; // rax
  __int64 v48; // rcx
  UFG::RoadNetworkConnection *v49; // rcx
  float v50; // xmm8_4
  float v51; // xmm6_4
  char *v52; // rax
  __int64 v53; // rcx
  UFG::RoadNetworkConnection *v54; // rcx
  UFG::qBezierPathMemImaged *v55; // rax
  UFG::RoadNetworkConnection *v56; // rbx
  unsigned int v57; // eax
  UFG::qBezierSplineMemImaged *v58; // rax
  float v59; // xmm7_4
  int v60; // xmm4_4
  __m128 v61; // xmm2
  __m128 v62; // xmm1
  float v63; // xmm3_4
  float v64; // xmm1_4
  float v65; // xmm2_4
  float v66; // xmm0_4
  UFG::qVector3 *v67; // rax
  unsigned int v68; // ebx
  UFG::qPropertySet *v69; // rax
  unsigned int *v70; // rax
  UFG::Grid<UFG::RoadNetworkSegment> *v71; // rcx
  int v72; // er8
  unsigned int k; // er15
  int v74; // er14
  __int64 v75; // rax
  signed __int64 v76; // rcx
  _QWORD *v77; // rdx
  UFG::RoadNetworkIntersection *v78; // rbx
  unsigned int v79; // edi
  __int64 v80; // rax
  signed __int64 v81; // rcx
  _QWORD *v82; // rdx
  float *v83; // rsi
  UFG::Grid<UFG::RoadNetworkSegment> *v84; // rcx
  int v85; // er8
  UFG::qVector3 result; // [rsp+8h] [rbp-71h]
  UFG::qVector3 tangent; // [rsp+18h] [rbp-61h]
  float y_max; // [rsp+28h] [rbp-51h]
  UFG::RoadNetworkResource *v89; // [rsp+E0h] [rbp+67h]
  float splineT[2]; // [rsp+E8h] [rbp+6Fh]

  v1 = this;
  v2 = (float *)&UFG::ClosestSegmentCache::mNodeCacheItem.m_memSizeAndFlags;
  v3 = 4i64;
  v4 = 4i64;
  v5 = UFG::qVector3::msZero.z;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.x;
  do
  {
    *(v2 - 2) = v7;
    *(v2 - 1) = v6;
    *v2 = v5;
    *((_QWORD *)v2 + 2) = 0i64;
    v2[1] = v7;
    v2[2] = v6;
    v2[3] = v5;
    v2[6] = v7;
    v2[7] = v6;
    v2[8] = v5;
    *((_QWORD *)v2 + 6) = 0i64;
    v2[9] = v7;
    v2[10] = v6;
    v2[11] = v5;
    v2[14] = v7;
    v2[15] = v6;
    v2[16] = v5;
    *((_QWORD *)v2 + 10) = 0i64;
    v2[17] = v7;
    v2[18] = v6;
    v2[19] = v5;
    v2[22] = v7;
    v2[23] = v6;
    v2[24] = v5;
    *((_QWORD *)v2 + 14) = 0i64;
    v2[25] = v7;
    v2[26] = v6;
    v2[27] = v5;
    v2[30] = v7;
    v2[31] = v6;
    v2[32] = v5;
    *((_QWORD *)v2 + 18) = 0i64;
    v2[33] = v7;
    v2[34] = v6;
    v2[35] = v5;
    v2[38] = v7;
    v2[39] = v6;
    v2[40] = v5;
    *((_QWORD *)v2 + 22) = 0i64;
    v2[41] = v7;
    v2[42] = v6;
    v2[43] = v5;
    v2[46] = v7;
    v2[47] = v6;
    v2[48] = v5;
    *((_QWORD *)v2 + 26) = 0i64;
    v2[49] = v7;
    v2[50] = v6;
    v2[51] = v5;
    v2[54] = v7;
    v2[55] = v6;
    v2[56] = v5;
    *((_QWORD *)v2 + 30) = 0i64;
    v2[57] = v7;
    v2[58] = v6;
    v2[59] = v5;
    v2 += 64;
    --v4;
  }
  while ( v4 );
  v8 = 0;
  if ( this->mNumSegments > 0 )
  {
    do
    {
      v9 = v1->mSegmentOffsetTable.mOffset;
      if ( v9 )
        v10 = (signed __int64)&v1->mSegmentOffsetTable + v9;
      else
        v10 = 0i64;
      v11 = (_QWORD *)(v10 + 8i64 * v8);
      if ( *v11 )
        v12 = (char *)v11 + *v11;
      else
        v12 = 0i64;
      v13 = v12[40];
      if ( v13 )
      {
        v14 = *((_QWORD *)v12 + 6);
        if ( v14 )
          v15 = (signed __int64)&v12[v14 + 48];
        else
          v15 = 0i64;
        v16 = (_QWORD *)(v15 + 8 * ((unsigned __int64)v13 >> 1));
        v17 = (float *)((char *)v16 + *v16);
        if ( !*v16 )
          v17 = 0i64;
        if ( *(_QWORD *)v17 )
          v18 = (char *)v17 + *(_QWORD *)v17;
        else
          v18 = 0i64;
        v19 = *((_QWORD *)v18 + 4);
        if ( v19 )
          v20 = (UFG::RoadNetworkConnection *)&v18[v19 + 32];
        else
          v20 = 0i64;
        v21 = 20.0
            / *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v20, *((unsigned __int16 *)v17 + 19))->mNode.mOffset
              + 1);
        for ( i = v21; i < 1.0; i = i + v21 )
        {
          if ( *(_QWORD *)v17 )
            v23 = (char *)v17 + *(_QWORD *)v17;
          else
            v23 = 0i64;
          v24 = *((_QWORD *)v23 + 4);
          if ( v24 )
            v25 = (UFG::RoadNetworkConnection *)&v23[v24 + 32];
          else
            v25 = 0i64;
          v26 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                               v25,
                                               *((unsigned __int16 *)v17 + 19));
          v27 = (UFG::RoadNetworkConnection *)v26;
          v28 = UFG::qBezierPathMemImaged::GetSplineParameters(v26, i, splineT);
          v29 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v27, v28);
          UFG::RoadNetworkLane::GetOffsetPos(&result, v29, splineT[0], v17[10]);
          if ( RoadExtents_minX >= (float)(result.x - 30.0) )
            RoadExtents_minX = result.x - 30.0;
          if ( RoadExtents_minY >= (float)(result.y - 30.0) )
            RoadExtents_minY = result.y - 30.0;
          if ( RoadExtents_maxX <= (float)(result.x + 30.0) )
            RoadExtents_maxX = result.x + 30.0;
          if ( RoadExtents_maxY <= (float)(result.y + 30.0) )
            RoadExtents_maxY = result.y + 30.0;
        }
      }
      ++v8;
    }
    while ( v8 < v1->mNumSegments );
  }
  v30 = 0i64;
  do
  {
    v31 = (UFG::Grid<UFG::RoadNetworkSegment> *)UFG::qMalloc(0x30ui64, "Grid<RoadNetworkSegment>", 0i64);
    v32 = v31;
    *(_QWORD *)splineT = v31;
    if ( v31 )
    {
      v31->mGridNodes = 0i64;
      UFG::Grid<UFG::RoadNetworkSegment>::Init(
        v31,
        RoadExtents_minX,
        RoadExtents_minY,
        RoadExtents_maxX,
        RoadExtents_maxY,
        150.0);
    }
    else
    {
      v32 = 0i64;
    }
    *(_QWORD *)(v30 + 5403791664i64) = v32;
    v33 = (UFG::Grid<UFG::RoadNetworkSegment> *)UFG::qMalloc(0x30ui64, "Grid<RoadNetworkIntersection>", 0i64);
    v34 = v33;
    *(_QWORD *)splineT = v33;
    if ( v33 )
    {
      v33->mGridNodes = 0i64;
      UFG::Grid<UFG::RoadNetworkSegment>::Init(
        v33,
        RoadExtents_minX,
        RoadExtents_minY,
        RoadExtents_maxX,
        RoadExtents_maxY,
        150.0);
    }
    else
    {
      v34 = 0i64;
    }
    *(_QWORD *)(v30 + 5403791696i64) = v34;
    v30 += 8i64;
    --v3;
  }
  while ( v3 );
  for ( j = 0; j < v1->mNumSegments; ++j )
  {
    v36 = -1;
    v37 = v1->mSegmentOffsetTable.mOffset;
    if ( v37 )
      v38 = (signed __int64)&v1->mSegmentOffsetTable + v37;
    else
      v38 = 0i64;
    v39 = (_QWORD *)(v38 + 8i64 * j);
    v40 = (UFG::RoadNetworkSegment *)((char *)v39 + *v39);
    if ( !*v39 )
      v40 = 0i64;
    if ( !v40->mType.mValue )
    {
      v41 = v40->mNumLanes;
      if ( v41 )
      {
        v42 = ((unsigned int)v41 - 1) >> 1;
        v43 = v40->mLane.mOffset;
        if ( v43 )
          v44 = (signed __int64)&v40->mLane + v43;
        else
          v44 = 0i64;
        v45 = (_QWORD *)(v44 + 8 * v42);
        v46 = (float *)((char *)v45 + *v45);
        if ( !*v45 )
          v46 = 0i64;
        if ( *(_QWORD *)v46 )
          v47 = (char *)v46 + *(_QWORD *)v46;
        else
          v47 = 0i64;
        v48 = *((_QWORD *)v47 + 4);
        if ( v48 )
          v49 = (UFG::RoadNetworkConnection *)&v47[v48 + 32];
        else
          v49 = 0i64;
        v50 = 1.0
            / *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v49, *((unsigned __int16 *)v46 + 19))->mNode.mOffset
              + 1);
        v51 = v50;
        if ( v50 < 1.0 )
        {
          do
          {
            if ( *(_QWORD *)v46 )
              v52 = (char *)v46 + *(_QWORD *)v46;
            else
              v52 = 0i64;
            v53 = *((_QWORD *)v52 + 4);
            if ( v53 )
              v54 = (UFG::RoadNetworkConnection *)&v52[v53 + 32];
            else
              v54 = 0i64;
            v55 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                 v54,
                                                 *((unsigned __int16 *)v46 + 19));
            v56 = (UFG::RoadNetworkConnection *)v55;
            v57 = UFG::qBezierPathMemImaged::GetSplineParameters(v55, v51, splineT);
            v58 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v56, v57);
            v59 = v46[10];
            if ( v59 == 0.0 )
            {
              v67 = UFG::qBezierSplineMemImaged::GetPosition(v58, (UFG::qVector3 *)&y_max, splineT[0]);
              v65 = v67->y;
              v66 = v67->z;
              v64 = v67->x;
            }
            else
            {
              UFG::qBezierSplineMemImaged::GetPositionAndTangent(v58, splineT[0], &result, &tangent);
              v60 = LODWORD(tangent.x) ^ _xmm[0];
              v61 = (__m128)LODWORD(tangent.y);
              v62 = v61;
              v62.m128_f32[0] = (float)(v61.m128_f32[0] * v61.m128_f32[0]) + (float)(*(float *)&v60 * *(float *)&v60);
              if ( v62.m128_f32[0] == 0.0 )
                v63 = 0.0;
              else
                v63 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v62));
              v64 = result.x + (float)((float)(v63 * tangent.y) * v59);
              v65 = result.y + (float)((float)(*(float *)&v60 * v63) * v59);
              v66 = result.z + (float)((float)(v63 * 0.0) * v59);
            }
            result.z = v66;
            result.y = v65;
            result.x = v64;
            if ( v40->mpPropertySetCached )
            {
              v68 = v40->mRoadNetworkType.mValue;
            }
            else
            {
              v69 = UFG::RoadNetworkSegment::GetRoadPropertySet(v40);
              v68 = 0;
              if ( v69 )
              {
                v70 = UFG::qPropertySet::Get<unsigned long>(
                        v69,
                        (UFG::qSymbol *)&qSymbol_RoadNetworkType.mUID,
                        DEPTH_RECURSE);
                if ( v70 )
                  v68 = *v70;
              }
              v65 = result.y;
              v64 = result.x;
            }
            v71 = gSegmentsDataGrid[v68];
            if ( v71 )
            {
              v72 = (signed int)(float)((float)(v64 - v71->mXMin) * v71->mGridSizeInv)
                  + v71->mXDim * (signed int)(float)((float)(v65 - v71->mYMin) * v71->mGridSizeInv);
              if ( v72 != v36 )
              {
                v36 = (signed int)(float)((float)(v64 - v71->mXMin) * v71->mGridSizeInv)
                    + v71->mXDim * (signed int)(float)((float)(v65 - v71->mYMin) * v71->mGridSizeInv);
                UFG::Grid<UFG::RoadNetworkSegment>::Add(v71, v40, v72);
              }
            }
            v51 = v51 + v50;
          }
          while ( v51 < 1.0 );
          v1 = v89;
        }
      }
    }
  }
  for ( k = 0; k < v1->mNumIntersections; ++k )
  {
    v74 = -1;
    v75 = v1->mIntersectionOffsetTable.mOffset;
    if ( v75 )
      v76 = (signed __int64)&v1->mIntersectionOffsetTable + v75;
    else
      v76 = 0i64;
    v77 = (_QWORD *)(v76 + 8i64 * k);
    v78 = (UFG::RoadNetworkIntersection *)((char *)v77 + *v77);
    if ( !*v77 )
      v78 = 0i64;
    if ( v78->mNumLanes )
    {
      v79 = 0;
      if ( v78->mNumGates > 0u )
      {
        do
        {
          v80 = v78->mGates.mOffset;
          if ( v80 )
            v81 = (signed __int64)&v78->mGates + v80;
          else
            v81 = 0i64;
          v82 = (_QWORD *)(v81 + 8i64 * v79);
          v83 = (float *)((char *)v82 + *v82);
          if ( !*v82 )
            v83 = 0i64;
          v84 = (UFG::Grid<UFG::RoadNetworkSegment> *)gIntersectionsDataGrid[(unsigned int)UFG::RoadNetworkIntersection::GetRoadNetworkType(v78)];
          if ( v84 )
          {
            v85 = (signed int)(float)((float)(v83[6] - v84->mXMin) * v84->mGridSizeInv)
                + v84->mXDim * (signed int)(float)((float)(v83[7] - v84->mYMin) * v84->mGridSizeInv);
            if ( v85 != v74 )
            {
              v74 = (signed int)(float)((float)(v83[6] - v84->mXMin) * v84->mGridSizeInv)
                  + v84->mXDim * (signed int)(float)((float)(v83[7] - v84->mYMin) * v84->mGridSizeInv);
              UFG::Grid<UFG::RoadNetworkSegment>::Add(v84, (UFG::RoadNetworkSegment *)v78, v85);
            }
          }
          ++v79;
        }
        while ( v79 < (unsigned __int8)v78->mNumGates );
        v1 = v89;
      }
    }
  }
}

// File Line: 231
// RVA: 0xD3810
void __fastcall UFG::RoadNetworkResource::ClearDataGrids(UFG::RoadNetworkResource *this)
{
  signed __int64 v1; // rbp
  void ***v2; // rsi
  signed __int64 v3; // r14
  void **v4; // rdi
  char *v5; // rcx
  char *v6; // rbx
  void ***v7; // rsi
  void **v8; // rbx
  char *v9; // rcx
  char *v10; // rdi

  v1 = 4i64;
  v2 = (void ***)gSegmentsDataGrid;
  v3 = 4i64;
  do
  {
    v4 = *v2;
    if ( *v2 )
    {
      v5 = (char *)*v4;
      if ( *v4 )
      {
        v6 = v5 - 8;
        `eh vector destructor iterator'(
          v5,
          0x10ui64,
          *((_DWORD *)v5 - 2),
          (void (__fastcall *)(void *))UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0>::~qList<UFG::qReflectField,UFG::qReflectField,1,0>);
        operator delete[](v6);
      }
      operator delete[](v4);
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  v7 = (void ***)gIntersectionsDataGrid;
  do
  {
    v8 = *v7;
    if ( *v7 )
    {
      v9 = (char *)*v8;
      if ( *v8 )
      {
        v10 = v9 - 8;
        `eh vector destructor iterator'(
          v9,
          0x10ui64,
          *((_DWORD *)v9 - 2),
          (void (__fastcall *)(void *))UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0>::~qList<UFG::qReflectField,UFG::qReflectField,1,0>);
        operator delete[](v10);
      }
      operator delete[](v8);
    }
    ++v7;
    --v1;
  }
  while ( v1 );
}

// File Line: 241
// RVA: 0xD91B0
void __fastcall UFG::RoadNetworkResource::GetIntersectionsInGrid(UFG::RoadNetworkResource *this, UFG::qArray<UFG::RoadNetworkNode *,0> *intersections, UFG::qVector3 *position, unsigned int roadNetworkType, float radius)
{
  unsigned int v5; // ebp
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v6; // r14
  UFG::Grid<UFG::RoadNetworkIntersection> *v7; // rdi
  float v8; // xmm3_4
  float v9; // xmm5_4
  __int64 v10; // r11
  __int64 v11; // rdx
  signed int v12; // er10
  float v13; // xmm2_4
  signed int v14; // ebx
  int v15; // eax
  int v16; // ecx
  signed int v17; // er8
  signed __int64 v18; // rsi
  signed __int64 v19; // r9
  __int64 v20; // r11
  __int64 v21; // rcx
  __int64 v22; // r8
  __int64 v23; // r13
  __int64 *v24; // r12
  __int64 v25; // r15
  __int64 v26; // rsi
  UFG::RoadNetworkIntersection *v27; // rcx
  __int64 v28; // rdi
  UFG::qReflectInventoryBase *v29; // rbp
  __int64 v30; // rcx
  unsigned int v31; // edx
  unsigned int v32; // ebx
  unsigned int v33; // edx
  UFG::qReflectInventoryBase **v34; // rax
  __int64 v35; // [rsp+20h] [rbp-108h]
  __int64 v36[25]; // [rsp+30h] [rbp-F8h]
  int v37; // [rsp+F8h] [rbp-30h]
  unsigned int v38; // [rsp+148h] [rbp+20h]

  v38 = roadNetworkType;
  v5 = roadNetworkType;
  v6 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)intersections;
  v7 = gIntersectionsDataGrid[roadNetworkType];
  if ( v7->mNodeCount )
  {
    v8 = radius;
    if ( radius > MaxGridQueryDistance )
      v8 = MaxGridQueryDistance;
    v9 = v7->mGridSizeInv;
    v10 = v7->mXDim;
    v11 = 0i64;
    v12 = (signed int)(float)((float)((float)(position->x - v8) - v7->mXMin) * v9);
    v13 = (float)((float)(position->x + v8) - v7->mXMin) * v9;
    if ( v12 < 0 )
      v12 = 0;
    v14 = (signed int)v13;
    if ( (signed int)v13 >= (signed int)v10 )
      v14 = v10 - 1;
    v15 = v7->mYDim;
    v16 = (signed int)(float)((float)((float)(position->y + v8) - v7->mYMin) * v9);
    v17 = (signed int)(float)((float)((float)(position->y - v8) - v7->mYMin) * v9);
    if ( v17 < 0 )
      v17 = 0;
    if ( v16 >= v15 )
      v16 = v15 - 1;
    v37 = 0;
    if ( v17 <= v16 )
    {
      v18 = 16 * v10;
      v19 = 16i64 * (v12 + v17 * (signed int)v10);
      v20 = (unsigned int)(v16 - v17 + 1);
      do
      {
        if ( v12 <= v14 )
        {
          v21 = (__int64)v7->mGridNodes + v19;
          v22 = (unsigned int)(v14 - v12 + 1);
          do
          {
            if ( *(_QWORD *)(v21 + 8) != v21 )
            {
              v36[v11] = v21;
              v11 = (unsigned int)(v37++ + 1);
            }
            v21 += 16i64;
            --v22;
          }
          while ( v22 );
        }
        v19 += v18;
        --v20;
      }
      while ( v20 );
    }
    if ( (_DWORD)v11 )
    {
      v23 = (unsigned int)v11;
      v24 = v36;
      v35 = (unsigned int)v11;
      do
      {
        v25 = *v24;
        v26 = *(_QWORD *)(*v24 + 8);
        if ( v26 != *v24 )
        {
          do
          {
            v27 = *(UFG::RoadNetworkIntersection **)(v26 + 16);
            if ( v27->mNumLanes && UFG::RoadNetworkIntersection::GetRoadNetworkType(v27) == v5 )
            {
              v28 = v6->size;
              v29 = *(UFG::qReflectInventoryBase **)(v26 + 16);
              v30 = 0i64;
              if ( !(_DWORD)v28 )
                goto LABEL_30;
              while ( v29 != v6->p[v30] )
              {
                v30 = (unsigned int)(v30 + 1);
                if ( (unsigned int)v30 >= (unsigned int)v28 )
                  goto LABEL_30;
              }
              if ( (_DWORD)v30 == -1 )
              {
LABEL_30:
                v31 = v6->capacity;
                v32 = v28 + 1;
                if ( (signed int)v28 + 1 > v31 )
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
                    v33 = v28 + 65537;
                  UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v6, v33, "qArray.Add");
                }
                v34 = v6->p;
                v6->size = v32;
                v34[v28] = v29;
              }
              v5 = v38;
            }
            v26 = *(_QWORD *)(v26 + 8);
          }
          while ( v26 != v25 );
          v23 = v35;
        }
        ++v24;
        v35 = --v23;
      }
      while ( v23 );
    }
  }
}

// File Line: 273
// RVA: 0xDBA00
void __fastcall UFG::RoadNetworkResource::GetSegmentsInGrid(UFG::RoadNetworkResource *this, UFG::qArray<UFG::RoadNetworkSegment *,0> *segments, UFG::qVector3 *position, unsigned int roadNetworkType, float radius)
{
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v5; // r14
  UFG::Grid<UFG::RoadNetworkSegment> *v6; // rdi
  float v7; // xmm3_4
  float v8; // xmm5_4
  __int64 v9; // r11
  __int64 v10; // rdx
  signed int v11; // er10
  float v12; // xmm2_4
  signed int v13; // ebx
  int v14; // eax
  int v15; // ecx
  signed int v16; // er8
  signed __int64 v17; // rsi
  signed __int64 v18; // r9
  __int64 v19; // r11
  __int64 v20; // rcx
  __int64 v21; // r8
  __int64 *v22; // r12
  __int64 v23; // r13
  __int64 v24; // r15
  __int64 v25; // rbp
  __int64 v26; // rdi
  unsigned int v27; // ebx
  UFG::qPropertySet *v28; // rax
  unsigned int *v29; // rax
  __int64 v30; // rsi
  int v31; // ecx
  unsigned int v32; // edx
  unsigned int v33; // ebx
  unsigned int v34; // edx
  UFG::qReflectInventoryBase **v35; // rax
  __int64 v36; // [rsp+20h] [rbp-108h]
  __int64 *v37; // [rsp+28h] [rbp-100h]
  __int64 v38[25]; // [rsp+30h] [rbp-F8h]
  int v39; // [rsp+F8h] [rbp-30h]
  unsigned int v40; // [rsp+148h] [rbp+20h]

  v40 = roadNetworkType;
  v5 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)segments;
  v6 = gSegmentsDataGrid[roadNetworkType];
  if ( v6->mNodeCount )
  {
    v7 = radius;
    if ( radius > MaxGridQueryDistance )
      v7 = MaxGridQueryDistance;
    v8 = v6->mGridSizeInv;
    v9 = v6->mXDim;
    v10 = 0i64;
    v11 = (signed int)(float)((float)((float)(position->x - v7) - v6->mXMin) * v8);
    v12 = (float)((float)(position->x + v7) - v6->mXMin) * v8;
    if ( v11 < 0 )
      v11 = 0;
    v13 = (signed int)v12;
    if ( (signed int)v12 >= (signed int)v9 )
      v13 = v9 - 1;
    v14 = v6->mYDim;
    v15 = (signed int)(float)((float)((float)(position->y + v7) - v6->mYMin) * v8);
    v16 = (signed int)(float)((float)((float)(position->y - v7) - v6->mYMin) * v8);
    if ( v16 < 0 )
      v16 = 0;
    if ( v15 >= v14 )
      v15 = v14 - 1;
    v39 = 0;
    if ( v16 <= v15 )
    {
      v17 = 16 * v9;
      v18 = 16i64 * (v11 + v16 * (signed int)v9);
      v19 = (unsigned int)(v15 - v16 + 1);
      do
      {
        if ( v11 <= v13 )
        {
          v20 = (__int64)v6->mGridNodes + v18;
          v21 = (unsigned int)(v13 - v11 + 1);
          do
          {
            if ( *(_QWORD *)(v20 + 8) != v20 )
            {
              v38[v10] = v20;
              v10 = (unsigned int)(v39++ + 1);
            }
            v20 += 16i64;
            --v21;
          }
          while ( v21 );
        }
        v18 += v17;
        --v19;
      }
      while ( v19 );
    }
    if ( (_DWORD)v10 )
    {
      v22 = v38;
      v23 = (unsigned int)v10;
      v37 = v38;
      v36 = (unsigned int)v10;
      do
      {
        v24 = *v22;
        v25 = *(_QWORD *)(*v22 + 8);
        if ( v25 != *v22 )
        {
          do
          {
            v26 = *(_QWORD *)(v25 + 16);
            if ( *(_BYTE *)(v26 + 40) )
            {
              if ( *(_QWORD *)(v26 + 104) )
              {
                v27 = *(_DWORD *)(v26 + 136);
              }
              else
              {
                v28 = UFG::RoadNetworkSegment::GetRoadPropertySet(*(UFG::RoadNetworkSegment **)(v25 + 16));
                v27 = 0;
                if ( v28 )
                {
                  v29 = UFG::qPropertySet::Get<unsigned long>(
                          v28,
                          (UFG::qSymbol *)&qSymbol_RoadNetworkType.mUID,
                          DEPTH_RECURSE);
                  if ( v29 )
                    v27 = *v29;
                }
              }
              if ( v27 == v40 )
              {
                v30 = v5->size;
                v31 = 0;
                if ( !(_DWORD)v30 )
                  goto LABEL_35;
                while ( (UFG::qReflectInventoryBase *)v26 != v5->p[v31] )
                {
                  if ( ++v31 >= (unsigned int)v30 )
                    goto LABEL_35;
                }
                if ( v31 == -1 )
                {
LABEL_35:
                  v32 = v5->capacity;
                  v33 = v30 + 1;
                  if ( (signed int)v30 + 1 > v32 )
                  {
                    if ( v32 )
                      v34 = 2 * v32;
                    else
                      v34 = 1;
                    for ( ; v34 < v33; v34 *= 2 )
                      ;
                    if ( v34 <= 2 )
                      v34 = 2;
                    if ( v34 - v33 > 0x10000 )
                      v34 = v30 + 65537;
                    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v5, v34, "qArray.Add");
                  }
                  v35 = v5->p;
                  v5->size = v33;
                  v35[v30] = (UFG::qReflectInventoryBase *)v26;
                }
              }
            }
            v25 = *(_QWORD *)(v25 + 8);
          }
          while ( v25 != v24 );
          v22 = v37;
          v23 = v36;
        }
        ++v22;
        v36 = --v23;
        v37 = v22;
      }
      while ( v23 );
    }
  }
}

// File Line: 307
// RVA: 0xD6E30
UFG::RoadNetworkIntersection *__fastcall UFG::RoadNetworkResource::GetClosestNode(UFG::RoadNetworkResource *this, UFG::qVector3 *pos, unsigned int roadNetworkType, UFG::qVector3 *nodePos, UFG::RoadNetworkClosestQueryCache *cache)
{
  UFG::qVector3 *v5; // rbx
  UFG::qVector3 *v6; // rsi
  unsigned int v7; // ebp
  UFG::RoadNetworkResource *v8; // r14
  UFG::RoadNetworkSegment *v9; // rax
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm8_4
  UFG::RoadNetworkNode *v13; // rdi
  __m128 v14; // xmm2
  float v15; // xmm3_4
  UFG::RoadNetworkIntersection *result; // rax
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm5_4
  float v21; // xmm10_4
  float v22; // xmm11_4
  UFG::qVector3 pposClosest; // [rsp+30h] [rbp-88h]

  v5 = nodePos;
  v6 = pos;
  pposClosest = UFG::qVector3::msZero;
  v7 = roadNetworkType;
  v8 = this;
  v9 = UFG::RoadNetworkResource::GetClosestSegment(this, pos, 0i64, roadNetworkType, &pposClosest, cache);
  v10 = pposClosest.z;
  v11 = pposClosest.y;
  v12 = pposClosest.x;
  v13 = (UFG::RoadNetworkNode *)&v9->mType;
  if ( v9 )
  {
    v14 = (__m128)LODWORD(v6->y);
    v14.m128_f32[0] = (float)((float)((float)(v14.m128_f32[0] - pposClosest.y) * (float)(v14.m128_f32[0] - pposClosest.y))
                            + (float)((float)(v6->x - pposClosest.x) * (float)(v6->x - pposClosest.x)))
                    + (float)((float)(v6->z - pposClosest.z) * (float)(v6->z - pposClosest.z));
    LODWORD(v15) = (unsigned __int128)_mm_sqrt_ps(v14);
  }
  else
  {
    v15 = FLOAT_3_4028235e38;
  }
  pposClosest = UFG::qVector3::msZero;
  result = UFG::RoadNetworkResource::GetClosestIntersection(v8, v6, v7, v15, &pposClosest, cache);
  if ( v13 )
  {
    if ( result )
    {
      v19 = v6->x;
      v20 = v6->y;
      v21 = pposClosest.y;
      v22 = pposClosest.z;
      if ( (float)((float)((float)((float)(v20 - pposClosest.y) * (float)(v20 - pposClosest.y))
                         + (float)((float)(v19 - pposClosest.x) * (float)(v19 - pposClosest.x)))
                 + (float)((float)(v6->z - pposClosest.z) * (float)(v6->z - pposClosest.z))) >= (float)((float)((float)((float)(v20 - v11) * (float)(v20 - v11)) + (float)((float)(v19 - v12) * (float)(v19 - v12))) + (float)((float)(v6->z - v10) * (float)(v6->z - v10))) )
      {
        if ( v5 )
        {
          v5->x = v12;
          v5->y = v11;
          v5->z = v10;
        }
        result = (UFG::RoadNetworkIntersection *)v13;
      }
      else if ( v5 )
      {
        v5->x = pposClosest.x;
        v5->y = v21;
        v5->z = v22;
      }
    }
    else
    {
      if ( v5 )
      {
        v5->x = v12;
        v5->y = v11;
        v5->z = v10;
      }
      result = (UFG::RoadNetworkIntersection *)v13;
    }
  }
  else if ( result )
  {
    if ( v5 )
    {
      v17 = pposClosest.y;
      v5->x = pposClosest.x;
      v18 = pposClosest.z;
      v5->y = v17;
      v5->z = v18;
    }
  }
  return result;
}

// File Line: 364
// RVA: 0xD6180
UFG::RoadNetworkIntersection *__fastcall UFG::RoadNetworkResource::GetClosestIntersection(UFG::RoadNetworkResource *this, UFG::qVector3 *pos, unsigned int roadNetworkType, float fMaxDistance, UFG::qVector3 *pposClosest, UFG::RoadNetworkClosestQueryCache *cache)
{
  float v6; // xmm2_4
  unsigned int v7; // edi
  __int64 v8; // rbx
  signed __int64 v9; // r14
  UFG::RoadNetworkIntersection *v10; // r12
  unsigned int v11; // er13
  UFG::RoadNetworkIntersection *v12; // rsi
  float v13; // xmm11_4
  float v14; // xmm12_4
  float v15; // xmm7_4
  float v16; // xmm14_4
  float v17; // xmm15_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  UFG::Grid<UFG::RoadNetworkSegment> *v21; // rdx
  __int64 v23; // rax
  float v24; // xmm8_4
  float v25; // xmm9_4
  UFG::GridNodesArray<UFG::RoadNetworkSegment> *v26; // rbx
  UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *v27; // rbx
  UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > *v28; // r15
  __int64 v29; // rbx
  UFG::RoadNetworkNode::RoadNetworkType v30; // eax
  float v31; // xmm0_4
  float v32; // xmm4_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm1_4
  float v39; // xmm5_4
  float v40; // xmm3_4
  float v41; // xmm10_4
  int v42; // xmm11_4
  float v43; // xmm12_4
  unsigned int v44; // esi
  float v45; // xmm9_4
  __int64 v46; // rax
  signed __int64 v47; // rcx
  __int64 v48; // rax
  signed __int64 v49; // rax
  signed __int64 v50; // rcx
  unsigned int v51; // edx
  __int64 v52; // rax
  UFG::RoadNetworkConnection *v53; // rcx
  UFG::qBezierPathMemImaged *v54; // rax
  float v55; // xmm2_4
  float v56; // xmm1_4
  __int64 v57; // rax
  signed __int64 v58; // rcx
  UFG::GridNodesArray<UFG::RoadNetworkSegment> *v59; // rbx
  float v60; // xmm10_4
  float v61; // xmm0_4
  signed __int64 v62; // r11
  unsigned int v63; // edx
  float *v64; // rcx
  float v65; // xmm0_4
  float v66; // xmm0_4
  float v67; // xmm0_4
  float v68; // xmm0_4
  float *v69; // rcx
  float v70; // xmm0_4
  float *v71; // rcx
  float v72; // xmm0_4
  UFG::qVector3 posa; // [rsp+20h] [rbp-A8h]
  UFG::RoadNetworkIntersection *v74; // [rsp+30h] [rbp-98h]
  float v75; // [rsp+38h] [rbp-90h]
  float v76; // [rsp+3Ch] [rbp-8Ch]
  float v77; // [rsp+40h] [rbp-88h]
  float v78; // [rsp+44h] [rbp-84h]
  UFG::GridNodesArray<UFG::RoadNetworkSegment> *v79; // [rsp+48h] [rbp-80h]
  float t; // [rsp+50h] [rbp-78h]
  int v81; // [rsp+54h] [rbp-74h]
  __int64 v82; // [rsp+58h] [rbp-70h]
  __int64 v83; // [rsp+60h] [rbp-68h]
  UFG::qVector3 result; // [rsp+68h] [rbp-60h]
  UFG::GridNodesArray<UFG::RoadNetworkSegment> v85; // [rsp+648h] [rbp+580h]
  char v86; // [rsp+800h] [rbp+738h]
  int v87; // [rsp+808h] [rbp+740h]
  float v88; // [rsp+810h] [rbp+748h]
  float *v89; // [rsp+818h] [rbp+750h]

  v6 = pos->x;
  v7 = 0;
  v8 = 0i64;
  v9 = 0xFFFFFFFFi64;
  v86 = 1;
  v10 = 0i64;
  v11 = 0;
  v12 = 0i64;
  v13 = UFG::qVector3::msZero.x;
  v14 = UFG::qVector3::msZero.y;
  v77 = UFG::qVector3::msZero.z;
  v82 = 0i64;
  v74 = 0i64;
  v15 = FLOAT_3_4028235e38;
  v16 = FLOAT_3_4028235e38;
  v76 = UFG::qVector3::msZero.x;
  v75 = UFG::qVector3::msZero.y;
  posa.x = v6;
  v17 = FLOAT_3_4028235e38;
  v18 = fMaxDistance;
  v19 = pos->z;
  v20 = pos->y;
  v78 = FLOAT_3_4028235e38;
  posa.y = v20;
  posa.z = v19;
  if ( v19 < -1000.0 )
  {
    v86 = 0;
    posa.z = 0.0;
  }
  v21 = (UFG::Grid<UFG::RoadNetworkSegment> *)gIntersectionsDataGrid[roadNetworkType];
  if ( !v21->mNodeCount )
    return 0i64;
  UFG::GridNodesArray<UFG::RoadNetworkSegment>::GridNodesArray<UFG::RoadNetworkSegment>(&v85, v21, v6, v20);
  v23 = v85.mNumValidNodes;
  v24 = posa.z;
  v25 = FLOAT_6_0;
  if ( v85.mNumValidNodes )
  {
    v26 = &v85;
    v83 = v85.mNumValidNodes;
    v79 = &v85;
    do
    {
      v27 = v26->mGridNodeArray[0];
      v28 = v27->mNode.mNext;
      if ( v28 != (UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > *)v27 )
      {
        while ( 1 )
        {
          v29 = (__int64)v28[1].mPrev;
          if ( *(_BYTE *)(v29 + 40) )
          {
            v30 = UFG::RoadNetworkIntersection::GetRoadNetworkType((UFG::RoadNetworkIntersection *)v28[1].mPrev);
            if ( v30 != v87 )
              goto LABEL_103;
            v31 = *(float *)(v29 + 128);
            v32 = posa.x;
            if ( posa.x >= v31 )
              v33 = 0.0;
            else
              v33 = v31 - posa.x;
            v34 = *(float *)(v29 + 140);
            if ( posa.x <= v34 )
              v35 = 0.0;
            else
              v35 = posa.x - v34;
            if ( v33 <= v35 )
              v33 = v35;
            v36 = *(float *)(v29 + 132);
            v37 = posa.y;
            if ( posa.y >= v36 )
              v38 = 0.0;
            else
              v38 = v36 - posa.y;
            v39 = *(float *)(v29 + 144);
            if ( posa.y <= v39 )
              v40 = 0.0;
            else
              v40 = posa.y - v39;
            if ( v38 <= v40 )
              v38 = v40;
            if ( (float)((float)(v38 * v38) + (float)(v33 * v33)) > (float)(v18 * v18) )
            {
LABEL_103:
              v24 = posa.z;
              v25 = FLOAT_6_0;
            }
            else
            {
              v41 = *(float *)(v29 + 12);
              v42 = *(int *)(v29 + 16);
              v43 = *(float *)(v29 + 20);
              v44 = 0;
              t = 0.0;
              v45 = FLOAT_3_4028235e38;
              if ( *(_BYTE *)(v29 + 40) <= 0u )
              {
                v24 = posa.z;
              }
              else
              {
                do
                {
                  v46 = *(_QWORD *)(v29 + 48);
                  if ( v46 )
                    v47 = v29 + v46 + 48;
                  else
                    v47 = 0i64;
                  v48 = *(_QWORD *)(v47 + 8i64 * v44);
                  if ( v48 )
                    v49 = v47 + 8i64 * v44 + v48;
                  else
                    v49 = 0i64;
                  if ( *(_QWORD *)v49 )
                    v50 = v49 + *(_QWORD *)v49;
                  else
                    v50 = 0i64;
                  v51 = *(unsigned __int16 *)(v49 + 38);
                  v52 = *(_QWORD *)(v50 + 32);
                  if ( v52 )
                    v53 = (UFG::RoadNetworkConnection *)(v52 + v50 + 32);
                  else
                    v53 = 0i64;
                  v54 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v53, v51);
                  UFG::qBezierPathMemImaged::ClosestPoint3D(v54, &result, &posa, &t);
                  v32 = posa.x;
                  v37 = posa.y;
                  v24 = posa.z;
                  if ( (float)((float)((float)((float)(result.y - posa.y) * (float)(result.y - posa.y))
                                     + (float)((float)(result.x - posa.x) * (float)(result.x - posa.x)))
                             + (float)((float)(result.z - posa.z) * (float)(result.z - posa.z))) < v45 )
                  {
                    v45 = (float)((float)((float)(result.y - posa.y) * (float)(result.y - posa.y))
                                + (float)((float)(result.x - posa.x) * (float)(result.x - posa.x)))
                        + (float)((float)(result.z - posa.z) * (float)(result.z - posa.z));
                    v41 = result.x;
                    v42 = SLODWORD(result.y);
                    v43 = result.z;
                  }
                  ++v44;
                }
                while ( v44 < *(unsigned __int8 *)(v29 + 40) );
                v18 = v88;
                v15 = v78;
              }
              v25 = FLOAT_6_0;
              v55 = (float)((float)((float)(v37 - *(float *)&v42) * (float)(v37 - *(float *)&v42))
                          + (float)((float)(v32 - v41) * (float)(v32 - v41)))
                  + (float)((float)(v24 - v43) * (float)(v24 - v43));
              if ( v86 )
              {
                v56 = *(float *)(v29 + 20);
                if ( v56 > v24 && COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - v56) & _xmm) > 6.0 )
                {
                  v12 = v74;
                  if ( v55 < v15 )
                  {
                    v15 = v55;
                    v76 = v41;
                    v75 = *(float *)&v42;
                    v82 = v29;
                    v78 = v55;
                    v77 = v43;
                  }
                  goto LABEL_58;
                }
              }
              v57 = v11++;
              v58 = 3 * v57;
              *(&v79 + v58) = (UFG::GridNodesArray<UFG::RoadNetworkSegment> *)v29;
              *(&t + 2 * v58) = v41;
              *(&v81 + 2 * v58) = v42;
              *((float *)&v82 + 2 * v58) = v43;
              if ( v55 >= v18 )
              {
LABEL_57:
                v12 = v74;
                goto LABEL_58;
              }
              if ( v55 >= v17 )
              {
                if ( v55 >= v16 || *(_DWORD *)(v29 + 24) == v10->mIndex )
                  goto LABEL_57;
                v12 = (UFG::RoadNetworkIntersection *)v29;
                v74 = (UFG::RoadNetworkIntersection *)v29;
                v16 = v55;
              }
              else
              {
                v12 = v10;
                v74 = v10;
                v16 = v17;
                v10 = (UFG::RoadNetworkIntersection *)v29;
                v17 = v55;
                v9 = v11 - 1;
              }
            }
          }
LABEL_58:
          v59 = v79;
          v28 = v28->mNext;
          if ( v28 == (UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > *)v79->mGridNodeArray[0] )
          {
            v23 = v83;
            goto LABEL_61;
          }
        }
      }
      v59 = v79;
LABEL_61:
      v26 = (UFG::GridNodesArray<UFG::RoadNetworkSegment> *)((char *)v59 + 8);
      v83 = --v23;
      v79 = v26;
    }
    while ( v23 );
    v13 = v76;
    v14 = v75;
    v8 = v82;
  }
  if ( v86 && v11 > 1 && v12 )
  {
    v60 = (float)(UFG::RoadNetworkIntersection::GetIntersectionRadius(v10) * 2.0) + 20.0;
    v61 = (float)(UFG::RoadNetworkIntersection::GetIntersectionRadius(v12) * 2.0) + 20.0;
    if ( v60 <= v61 )
      v60 = v61;
    v62 = 0i64;
    if ( (signed int)v11 >= 4 )
    {
      v63 = 2;
      v64 = (float *)&v82;
      v62 = 4i64 * (((v11 - 4) >> 2) + 1);
      do
      {
        if ( v7 != (_DWORD)v9 )
        {
          v65 = *(&t + 6 * v9) - *(v64 - 2);
          if ( (float)((float)((float)(*((float *)&v81 + 6 * v9) - *(v64 - 1))
                             * (float)(*((float *)&v81 + 6 * v9) - *(v64 - 1)))
                     + (float)(v65 * v65)) < (float)(v60 * v60)
            && COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - *((float *)&v82 + 6 * v9)) & _xmm) > (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - *v64) & _xmm)
                                                                                                 + v25) )
          {
            v9 = v7;
          }
        }
        if ( v63 - 1 != (_DWORD)v9 )
        {
          v66 = *(&t + 6 * v9) - v64[4];
          if ( (float)((float)((float)(*((float *)&v81 + 6 * v9) - v64[5]) * (float)(*((float *)&v81 + 6 * v9) - v64[5]))
                     + (float)(v66 * v66)) < (float)(v60 * v60)
            && COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - *((float *)&v82 + 6 * v9)) & _xmm) > (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - v64[6]) & _xmm)
                                                                                                 + v25) )
          {
            v9 = v63 - 1;
          }
        }
        if ( v63 != (_DWORD)v9 )
        {
          v67 = *(&t + 6 * v9) - v64[10];
          if ( (float)((float)((float)(*((float *)&v81 + 6 * v9) - v64[11])
                             * (float)(*((float *)&v81 + 6 * v9) - v64[11]))
                     + (float)(v67 * v67)) < (float)(v60 * v60)
            && COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - *((float *)&v82 + 6 * v9)) & _xmm) > (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - v64[12]) & _xmm)
                                                                                                 + v25) )
          {
            v9 = v63;
          }
        }
        if ( v63 + 1 != (_DWORD)v9 )
        {
          v68 = *(&t + 6 * v9) - v64[16];
          if ( (float)((float)((float)(*((float *)&v81 + 6 * v9) - v64[17])
                             * (float)(*((float *)&v81 + 6 * v9) - v64[17]))
                     + (float)(v68 * v68)) < (float)(v60 * v60)
            && COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - *((float *)&v82 + 6 * v9)) & _xmm) > (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - v64[18]) & _xmm)
                                                                                                 + v25) )
          {
            v9 = v63 + 1;
          }
        }
        v7 += 4;
        v64 += 24;
        v63 += 4;
      }
      while ( v7 < v11 - 3 );
    }
    if ( v7 < v11 )
    {
      v69 = (float *)(&v82 + 3 * v62);
      do
      {
        if ( v7 != (_DWORD)v9 )
        {
          v70 = *(&t + 6 * v9) - *(v69 - 2);
          if ( (float)((float)((float)(*((float *)&v81 + 6 * v9) - *(v69 - 1))
                             * (float)(*((float *)&v81 + 6 * v9) - *(v69 - 1)))
                     + (float)(v70 * v70)) < (float)(v60 * v60)
            && COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - *((float *)&v82 + 6 * v9)) & _xmm) > (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - *v69) & _xmm)
                                                                                                 + v25) )
          {
            v9 = v7;
          }
        }
        ++v7;
        v69 += 6;
      }
      while ( v7 < v11 );
    }
  }
  v71 = v89;
  if ( (_DWORD)v9 != -1 )
  {
    v10 = (UFG::RoadNetworkIntersection *)*(&v79 + 3 * v9);
    if ( v89 )
    {
      *v89 = *(&t + 6 * v9);
      *((_DWORD *)v71 + 1) = *(&v81 + 6 * v9);
      v71[2] = *((float *)&v82 + 6 * v9);
    }
  }
  if ( !v10 )
  {
    v10 = (UFG::RoadNetworkIntersection *)v8;
    if ( v71 )
    {
      v72 = v77;
      *v71 = v13;
      v71[1] = v14;
      v71[2] = v72;
    }
  }
  return v10;
}

// File Line: 513
// RVA: 0xDB970
signed __int64 __fastcall UFG::GetRoadSegmentArrayIndex(UFG::RoadNetworkResource *resource, UFG::RoadNetworkSegment *segment)
{
  unsigned int v2; // er10
  signed __int64 result; // rax
  UFG::RoadNetworkSegment *v4; // rbx
  __int64 v5; // r9
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkSegment *> *> *v6; // r11
  __int64 v7; // r8
  char *v8; // rcx
  char *v9; // rdx
  UFG::RoadNetworkSegment *v10; // rcx

  v2 = resource->mNumSegments;
  result = 0i64;
  v4 = segment;
  if ( !v2 )
    return 0xFFFFFFFFi64;
  v5 = resource->mSegmentOffsetTable.mOffset;
  v6 = &resource->mSegmentOffsetTable;
  v7 = 0i64;
  while ( 1 )
  {
    v8 = (char *)(v5 ? (UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkSegment *> *> *)((char *)v6 + v5) : 0i64);
    v9 = &v8[v7];
    v10 = *(UFG::RoadNetworkSegment **)&v8[v7];
    if ( v10 )
      v10 = (UFG::RoadNetworkSegment *)((char *)v10 + (_QWORD)v9);
    if ( v10 == v4 )
      break;
    result = (unsigned int)(result + 1);
    v7 += 8i64;
    if ( (unsigned int)result >= v2 )
      return 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 532
// RVA: 0xD7100
UFG::RoadNetworkSegment *__fastcall UFG::RoadNetworkResource::GetClosestSegment(UFG::RoadNetworkResource *this, UFG::qVector3 *pos, unsigned int *p_segment_index, unsigned int roadNetworkType)
{
  UFG::RoadNetworkResource *v4; // r10
  __int64 v5; // rsi
  float v6; // xmm11_4
  float v7; // xmm13_4
  float v8; // xmm14_4
  float v9; // xmm15_4
  float v10; // xmm12_4
  float v11; // xmm9_4
  float v12; // xmm8_4
  float v13; // xmm7_4
  _QWORD *v14; // rbx
  unsigned int v15; // er12
  char *v16; // r13
  unsigned int v17; // edi
  unsigned int v18; // er14
  __int64 v19; // r15
  float v20; // xmm10_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm3_4
  float v24; // xmm6_4
  hkSeekableStreamReader *v25; // rax
  int v26; // ecx
  int v27; // xmm6_4
  int v28; // xmm7_4
  int v29; // xmm8_4
  _DWORD *v30; // rax
  UFG::Grid<UFG::RoadNetworkSegment> *v31; // rdx
  int v32; // xmm4_4
  UFG::GridNodesArray<UFG::RoadNetworkSegment> *v33; // rcx
  __int64 v34; // rdx
  UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *v35; // rcx
  __int64 v36; // rax
  unsigned int v37; // ebx
  UFG::qPropertySet *v38; // rax
  unsigned int *v39; // rax
  float v40; // xmm2_4
  float v41; // xmm2_4
  float v42; // xmm1_4
  float v43; // xmm0_4
  float v44; // xmm0_4
  float v45; // xmm0_4
  float v46; // xmm3_4
  float v47; // xmm1_4
  float v48; // xmm6_4
  unsigned int v49; // er14
  unsigned int v50; // ebx
  unsigned __int64 v51; // rax
  char *v52; // rax
  char *v53; // rdi
  void *v54; // rcx
  _QWORD *v55; // rdx
  __int64 v56; // r9
  __int64 v57; // r8
  __int64 v58; // r12
  unsigned int v59; // ebx
  unsigned __int64 v60; // rax
  char *v61; // rsi
  __int64 v62; // rax
  int *v63; // rdx
  signed __int64 v64; // r8
  int v65; // xmm1_4
  int v66; // xmm2_4
  signed __int64 v67; // rcx
  char v68; // r9
  float v69; // xmm3_4
  __int64 v70; // rcx
  float v71; // xmm0_4
  __int64 v72; // rcx
  __int64 v73; // rax
  unsigned int v74; // er10
  __int64 v75; // r9
  signed __int64 v76; // rdx
  signed __int64 v77; // r8
  __int64 v78; // rax
  float *v79; // rax
  char v80; // cl
  unsigned __int64 v81; // rax
  float v83; // [rsp+30h] [rbp-90h]
  signed int v84; // [rsp+34h] [rbp-8Ch]
  float v85; // [rsp+38h] [rbp-88h]
  float v86; // [rsp+3Ch] [rbp-84h]
  __int64 v87; // [rsp+40h] [rbp-80h]
  UFG::qVector3 posa; // [rsp+48h] [rbp-78h]
  __int64 v89; // [rsp+58h] [rbp-68h]
  __int64 v90; // [rsp+60h] [rbp-60h]
  UFG::qVector3 result; // [rsp+68h] [rbp-58h]
  float nearestT; // [rsp+74h] [rbp-4Ch]
  UFG::RoadNetworkLane *nearestLane; // [rsp+78h] [rbp-48h]
  unsigned __int64 v94; // [rsp+80h] [rbp-40h]
  __int64 v95; // [rsp+88h] [rbp-38h]
  UFG::GridNodesArray<UFG::RoadNetworkSegment> v96; // [rsp+90h] [rbp-30h]
  __int64 v97; // [rsp+250h] [rbp+190h]
  char v98; // [rsp+258h] [rbp+198h]
  _DWORD *v99; // [rsp+260h] [rbp+1A0h]
  int v100; // [rsp+268h] [rbp+1A8h]
  _DWORD *v101; // [rsp+270h] [rbp+1B0h]

  v95 = -2i64;
  v4 = this;
  v5 = 0i64;
  *(_QWORD *)&posa.x = 0i64;
  v6 = FLOAT_3_4028235e38;
  v7 = UFG::qVector3::msZero.x;
  v8 = UFG::qVector3::msZero.y;
  v9 = UFG::qVector3::msZero.z;
  v10 = FLOAT_3_4028235e38;
  v11 = UFG::qVector3::msZero.x;
  v86 = UFG::qVector3::msZero.x;
  v12 = UFG::qVector3::msZero.y;
  v85 = UFG::qVector3::msZero.y;
  v13 = UFG::qVector3::msZero.z;
  v83 = UFG::qVector3::msZero.z;
  v14 = 0i64;
  *(_QWORD *)&result.x = 0i64;
  v15 = 0;
  v90 = 0i64;
  v16 = 0i64;
  v17 = 0;
  nearestLane = 0i64;
  v18 = -1;
  v84 = -1;
  v19 = 0i64;
  v87 = 0i64;
  v20 = FLOAT_3_4028235e38;
  v21 = pos->x;
  v22 = pos->y;
  v23 = pos->z;
  *(_QWORD *)&posa.x = LODWORD(pos->x);
  posa.y = v22;
  posa.z = v23;
  v98 = 1;
  v24 = FLOAT_4_0;
  if ( v23 >= -1000.0 )
  {
    if ( UFG::ClosestSegmentCache::mUseCache )
    {
      v25 = &UFG::ClosestSegmentCache::mNodeCacheItem + 16 * (unsigned __int64)roadNetworkType;
      v26 = 0;
      while ( !*(_QWORD *)&v25[1].m_memSizeAndFlags
           || (float)((float)((float)((float)(v22 - *((float *)&v25->vfptr + 1))
                                    * (float)(v22 - *((float *)&v25->vfptr + 1)))
                            + (float)((float)(v21 - *(float *)&v25->vfptr) * (float)(v21 - *(float *)&v25->vfptr)))
                    + (float)((float)(v23 - *(float *)&v25->m_memSizeAndFlags)
                            * (float)(v23 - *(float *)&v25->m_memSizeAndFlags))) >= 4.0 )
      {
        v25 += 2;
        if ( (unsigned int)++v26 >= 8 )
          goto LABEL_13;
      }
      v5 = *(_QWORD *)&v25[1].m_memSizeAndFlags;
      v27 = *(_DWORD *)(&v25->m_referenceCount + 1);
      v28 = (int)v25[1].vfptr;
      v29 = HIDWORD(v25[1].vfptr);
      if ( p_segment_index )
        *v99 = UFG::GetRoadSegmentArrayIndex(v4, *(UFG::RoadNetworkSegment **)&v25[1].m_memSizeAndFlags);
      v30 = v101;
      if ( v101 )
      {
        *v101 = v27;
        v30[1] = v28;
        v30[2] = v29;
      }
      goto LABEL_130;
    }
  }
  else
  {
    v98 = 0;
    posa.z = 0.0;
  }
LABEL_13:
  v94 = 8i64 * roadNetworkType;
  v31 = gSegmentsDataGrid[v94 / 8];
  if ( v31 && v31->mNodeCount )
  {
    UFG::GridNodesArray<UFG::RoadNetworkSegment>::GridNodesArray<UFG::RoadNetworkSegment>(&v96, v31, v21, v22);
    v32 = _xmm;
    if ( v96.mNumValidNodes )
    {
      v33 = &v96;
      *(_QWORD *)&posa.z = &v96;
      v34 = v96.mNumValidNodes;
      v89 = v96.mNumValidNodes;
      do
      {
        v35 = v33->mGridNodeArray[0];
        *(_QWORD *)&result.z = v35;
        v36 = (__int64)v35->mNode.mNext;
        v89 = v36;
        if ( (UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *)v36 != v35 )
        {
          while ( 1 )
          {
            v19 = *(_QWORD *)(v36 + 16);
            if ( !*(_BYTE *)(v19 + 40) )
              break;
            if ( *(_QWORD *)(v19 + 104) )
            {
              v37 = *(_DWORD *)(v19 + 136);
            }
            else
            {
              v38 = UFG::RoadNetworkSegment::GetRoadPropertySet(*(UFG::RoadNetworkSegment **)(v36 + 16));
              v37 = 0;
              if ( v38 )
              {
                v39 = UFG::qPropertySet::Get<unsigned long>(
                        v38,
                        (UFG::qSymbol *)&qSymbol_RoadNetworkType.mUID,
                        DEPTH_RECURSE);
                if ( v39 )
                  v37 = *v39;
              }
              v36 = v89;
              v35 = *(UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> **)&result.z;
            }
            if ( v37 != v100 )
              break;
            v40 = *(float *)(v19 + 140);
            if ( posa.x >= v40 )
              v41 = 0.0;
            else
              v41 = v40 - posa.x;
            v42 = *(float *)(v19 + 152);
            if ( posa.x <= v42 )
              v43 = 0.0;
            else
              v43 = posa.x - v42;
            if ( v41 <= v43 )
              v41 = v43;
            v44 = *(float *)(v19 + 144);
            if ( posa.y >= v44 )
              v45 = 0.0;
            else
              v45 = v44 - posa.y;
            v46 = *(float *)(v19 + 156);
            if ( posa.y <= v46 )
              v47 = 0.0;
            else
              v47 = posa.y - v46;
            if ( v45 <= v47 )
              v45 = v47;
            if ( (float)((float)(v45 * v45) + (float)(v41 * v41)) > v20 )
              break;
            UFG::RoadNetworkNode::GetNearestPos((UFG::RoadNetworkNode *)v19, &result, &posa, &nearestLane, &nearestT);
            v13 = result.z;
            v12 = result.y;
            v11 = result.x;
            v48 = (float)((float)((float)(posa.y - result.y) * (float)(posa.y - result.y))
                        + (float)((float)(posa.x - result.x) * (float)(posa.x - result.x)))
                + (float)((float)(posa.z - result.z) * (float)(posa.z - result.z));
            if ( v98 && result.z > posa.z && COERCE_FLOAT(COERCE_UNSIGNED_INT(posa.z - result.z) & _xmm) > 6.0 )
            {
              v36 = v89;
              v18 = v84;
              v35 = *(UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> **)&result.z;
              if ( v48 >= v10 )
              {
                v11 = v86;
                v12 = v85;
                v13 = v83;
              }
              else
              {
                v10 = (float)((float)((float)(posa.y - result.y) * (float)(posa.y - result.y))
                            + (float)((float)(posa.x - result.x) * (float)(posa.x - result.x)))
                    + (float)((float)(posa.z - result.z) * (float)(posa.z - result.z));
                v90 = v19;
                v86 = result.x;
                v85 = result.y;
                v83 = result.z;
              }
              goto LABEL_91;
            }
            v49 = v15 + 1;
            if ( v15 + 1 > HIDWORD(v90) )
            {
              v50 = 1;
              if ( HIDWORD(v90) )
                v50 = 2 * HIDWORD(v90);
              for ( ; v50 < v49; v50 *= 2 )
                ;
              if ( v50 <= 2 )
                v50 = 2;
              if ( v50 - v49 > 0x10000 )
                v50 = v15 + 65537;
              if ( v50 != v15 )
              {
                v51 = 8i64 * v50;
                if ( !is_mul_ok(v50, 8ui64) )
                  v51 = -1i64;
                v52 = UFG::qMalloc(v51, "qArray.Add", 0i64);
                v53 = v52;
                v54 = *(void **)&result.x;
                if ( *(_QWORD *)&result.x )
                {
                  if ( v15 )
                  {
                    v55 = v52;
                    v56 = *(_QWORD *)&result.x - (_QWORD)v52;
                    v57 = v15;
                    do
                    {
                      *v55 = *(_QWORD *)((char *)v55 + v56);
                      ++v55;
                      --v57;
                    }
                    while ( v57 );
                  }
                  operator delete[](v54);
                }
                *(_QWORD *)&result.x = v53;
                HIDWORD(v90) = v50;
                v17 = (unsigned int)nearestLane;
              }
            }
            LODWORD(v90) = v15 + 1;
            *(_QWORD *)(*(_QWORD *)&result.x + 8i64 * v15) = v19;
            v58 = v17++;
            if ( v17 > HIDWORD(nearestLane) )
            {
              if ( HIDWORD(nearestLane) )
                v59 = 2 * HIDWORD(nearestLane);
              else
                v59 = 1;
              for ( ; v59 < v17; v59 *= 2 )
                ;
              if ( v59 - v17 > 0x10000 )
                v59 = v17 + 0x10000;
              if ( v59 != (_DWORD)nearestLane )
              {
                v60 = 12i64 * v59;
                if ( !is_mul_ok(v59, 0xCui64) )
                  v60 = -1i64;
                v61 = UFG::qMalloc(v60, "qArray.Add", 0i64);
                nearestLane = (UFG::RoadNetworkLane *)v61;
                if ( v16 )
                {
                  v62 = (unsigned int)nearestLane;
                  if ( (_DWORD)nearestLane )
                  {
                    v63 = (int *)(v16 + 8);
                    v64 = v61 - v16;
                    do
                    {
                      v65 = *(v63 - 1);
                      v66 = *v63;
                      *(int *)((char *)v63 + v64 - 8) = *(v63 - 2);
                      *(int *)((char *)v63 + v64 - 4) = v65;
                      *(int *)((char *)v63 + v64) = v66;
                      v63 += 3;
                      --v62;
                    }
                    while ( v62 );
                  }
                  operator delete[](v16);
                }
                v16 = v61;
                v87 = (__int64)v61;
                HIDWORD(nearestLane) = v59;
              }
            }
            LODWORD(nearestLane) = v17;
            v67 = 3 * v58;
            *(float *)&v16[4 * v67] = v11;
            *(float *)&v16[4 * v67 + 4] = v12;
            *(float *)&v16[4 * v67 + 8] = v13;
            v15 = v90;
            if ( v48 >= v6 )
            {
              v5 = *(_QWORD *)&posa.x;
              v11 = v86;
              v12 = v85;
              v13 = v83;
              v18 = v84;
              v35 = *(UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> **)&result.z;
              if ( v48 >= v20 )
              {
                v36 = v89;
                goto LABEL_91;
              }
              v36 = v89;
              if ( *(_DWORD *)(v19 + 24) == *(_DWORD *)(*(_QWORD *)&posa.x + 24i64) )
                goto LABEL_91;
              v87 = v19;
              v20 = v48;
            }
            else
            {
              v87 = *(_QWORD *)&posa.x;
              v20 = v6;
              v5 = v19;
              *(_QWORD *)&posa.x = v19;
              v6 = v48;
              v18 = v49 - 1;
              v84 = v18;
              v7 = v11;
              v8 = v12;
              v9 = v13;
              v11 = v86;
              v12 = v85;
              v13 = v83;
              v36 = v89;
              v19 = v87;
              v35 = *(UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> **)&result.z;
            }
LABEL_92:
            v36 = *(_QWORD *)(v36 + 8);
            v89 = v36;
            if ( (UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *)v36 == v35 )
            {
              v34 = v89;
              goto LABEL_95;
            }
          }
          v11 = v86;
          v12 = v85;
          v13 = v83;
          v18 = v84;
LABEL_91:
          v19 = v87;
          goto LABEL_92;
        }
        v11 = v86;
        v12 = v85;
        v13 = v83;
        v18 = v84;
LABEL_95:
        v33 = (UFG::GridNodesArray<UFG::RoadNetworkSegment> *)(*(_QWORD *)&posa.z + 8i64);
        *(_QWORD *)&posa.z += 8i64;
        v89 = --v34;
      }
      while ( v34 );
      v24 = FLOAT_4_0;
      v32 = _xmm;
      v14 = *(_QWORD **)&result.x;
    }
    v68 = v98;
    if ( v98 && v15 > 1 && v19 )
    {
      v69 = (float)((float)*(unsigned __int8 *)(v5 + 40) * v24) + 20.0;
      if ( v69 <= (float)((float)((float)*(unsigned __int8 *)(v19 + 40) * v24) + 20.0) )
        v69 = (float)((float)*(unsigned __int8 *)(v19 + 40) * v24) + 20.0;
      v70 = 0i64;
      if ( v15 )
      {
        do
        {
          if ( (_DWORD)v70 != v18 )
          {
            v71 = *(float *)&v16[12 * v18 + 4] - *(float *)&v16[12 * v70 + 4];
            if ( (float)((float)((float)(*(float *)&v16[12 * v18] - *(float *)&v16[12 * v70])
                               * (float)(*(float *)&v16[12 * v18] - *(float *)&v16[12 * v70]))
                       + (float)(v71 * v71)) < (float)(v69 * v69)
              && COERCE_FLOAT(COERCE_UNSIGNED_INT(posa.z - *(float *)&v16[12 * v18 + 8]) & v32) > (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(posa.z - *(float *)&v16[12 * v70 + 8]) & v32) + 6.0) )
            {
              v18 = v70;
            }
          }
          v70 = (unsigned int)(v70 + 1);
        }
        while ( (unsigned int)v70 < v15 );
      }
    }
    if ( v18 != -1 )
    {
      v5 = v14[v18];
      v7 = *(float *)&v16[12 * v18];
      v8 = *(float *)&v16[12 * v18 + 4];
      v9 = *(float *)&v16[12 * v18 + 8];
    }
    if ( !v5 )
    {
      v5 = v90;
      v7 = v11;
      v8 = v12;
      v9 = v13;
    }
    if ( v99 )
    {
      v72 = 0i64;
      v73 = v97;
      v74 = *(_DWORD *)(v97 + 104);
      if ( v74 )
      {
        v75 = *(_QWORD *)(v97 + 112);
        while ( 1 )
        {
          if ( v75 )
            v76 = v73 + v75 + 112;
          else
            v76 = 0i64;
          v77 = v76 + 8 * v72;
          v78 = *(_QWORD *)v77;
          if ( *(_QWORD *)v77 )
            v78 += v77;
          if ( v78 == v5 )
            break;
          v72 = (unsigned int)(v72 + 1);
          v73 = v97;
          if ( (unsigned int)v72 >= v74 )
            goto LABEL_122;
        }
      }
      else
      {
LABEL_122:
        LODWORD(v72) = -1;
      }
      *v99 = v72;
      v68 = v98;
    }
    v79 = (float *)v101;
    if ( v101 )
    {
      *(float *)v101 = v7;
      v79[1] = v8;
      v79[2] = v9;
    }
    if ( v5 && v68 )
    {
      v80 = UFG::ClosestSegmentCache::mCircularIndex;
      v81 = 32 * (v94 + UFG::ClosestSegmentCache::mCircularIndex);
      *(float *)&(&UFG::ClosestSegmentCache::mNodeCacheItem.vfptr)[v81 / 8] = posa.x;
      HIDWORD((&UFG::ClosestSegmentCache::mNodeCacheItem.vfptr)[v81 / 8]) = LODWORD(posa.y);
      *(float *)((char *)&UFG::ClosestSegmentCache::mNodeCacheItem.m_memSizeAndFlags + v81) = posa.z;
      *(_QWORD *)((char *)&UFG::ClosestSegmentCache::mNodeCacheItem + v81 + 24) = v5;
      *(float *)((char *)&UFG::ClosestSegmentCache::mNodeCacheItem.m_referenceCount + v81 + 2) = v7;
      *(float *)((char *)&UFG::ClosestSegmentCache::mNodeCacheItem + v81 + 16) = v8;
      *(float *)((char *)&UFG::ClosestSegmentCache::mNodeCacheItem + v81 + 20) = v9;
      UFG::ClosestSegmentCache::mCircularIndex = (v80 + 1) & 7;
    }
  }
  else
  {
    v5 = 0i64;
  }
LABEL_130:
  if ( v16 )
    operator delete[](v16);
  nearestLane = 0i64;
  if ( v14 )
    operator delete[](v14);
  return (UFG::RoadNetworkSegment *)v5;
}

// File Line: 705
// RVA: 0xD7AB0
UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *__fastcall UFG::RoadNetworkResource::GetClosestSubSegment(UFG::RoadNetworkResource *this, UFG::qVector3 *pos, unsigned int roadNetworkType)
{
  float v3; // xmm7_4
  float v4; // xmm8_4
  unsigned int v5; // er13
  char v6; // r12
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v7; // r15
  float v8; // xmm11_4
  float v9; // xmm12_4
  UFG::Grid<UFG::RoadNetworkSegment> *v10; // rdi
  float v12; // xmm2_4
  __int64 v13; // r11
  signed int v14; // er10
  signed int v15; // ebx
  int v16; // eax
  signed int v17; // er8
  int v18; // ecx
  unsigned int v19; // edx
  signed __int64 v20; // rsi
  signed __int64 v21; // r9
  __int64 v22; // r11
  __int64 v23; // rcx
  __int64 v24; // r8
  __int64 *v25; // rax
  __int64 v26; // rcx
  __int64 v27; // rax
  __int64 v28; // r14
  UFG::RoadNetworkSegment *v29; // rsi
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v30; // rbx
  float v31; // xmm6_4
  unsigned int v32; // edi
  UFG::qPropertySet *v33; // rax
  unsigned int *v34; // rax
  __int64 v35; // [rsp+20h] [rbp-188h]
  __int64 v36[25]; // [rsp+30h] [rbp-178h]
  int v37; // [rsp+F8h] [rbp-B0h]
  __int64 *v38; // [rsp+1B8h] [rbp+10h]
  __int64 v39; // [rsp+1C8h] [rbp+20h]

  v3 = FLOAT_3_4028235e38;
  v4 = pos->z;
  v5 = roadNetworkType;
  v6 = 1;
  v7 = 0i64;
  v8 = pos->x;
  v9 = pos->y;
  if ( v4 < -1000.0 )
  {
    v6 = 0;
    v4 = 0.0;
  }
  v10 = gSegmentsDataGrid[roadNetworkType];
  if ( !v10->mNodeCount )
    return 0i64;
  v12 = v10->mGridSizeInv;
  v13 = v10->mXDim;
  v14 = (signed int)(float)((float)((float)(v8 - 100.0) - v10->mXMin) * v12);
  if ( v14 < 0 )
    v14 = 0;
  v15 = (signed int)(float)((float)((float)(v8 + 100.0) - v10->mXMin) * v12);
  if ( v15 >= (signed int)v13 )
    v15 = v13 - 1;
  v16 = v10->mYDim;
  v17 = (signed int)(float)((float)((float)(v9 - 100.0) - v10->mYMin) * v12);
  if ( v17 < 0 )
    v17 = 0;
  v18 = (signed int)(float)((float)((float)(v9 + 100.0) - v10->mYMin) * v12);
  if ( v18 >= v16 )
    v18 = v16 - 1;
  v19 = 0;
  v37 = 0;
  if ( v17 <= v18 )
  {
    v20 = 16 * v13;
    v21 = 16i64 * (v14 + v17 * (signed int)v13);
    v22 = (unsigned int)(v18 - v17 + 1);
    do
    {
      if ( v14 <= v15 )
      {
        v23 = (__int64)v10->mGridNodes + v21;
        v24 = (unsigned int)(v15 - v14 + 1);
        do
        {
          if ( *(_QWORD *)(v23 + 8) != v23 )
          {
            v36[v19] = v23;
            v19 = v37++ + 1;
          }
          v23 += 16i64;
          --v24;
        }
        while ( v24 );
      }
      v21 += v20;
      --v22;
    }
    while ( v22 );
  }
  if ( v19 )
  {
    v25 = v36;
    v26 = v19;
    v38 = v36;
    v39 = v19;
    do
    {
      v27 = *v25;
      v35 = v27;
      v28 = *(_QWORD *)(v27 + 8);
      if ( v28 != v27 )
      {
        do
        {
          v29 = *(UFG::RoadNetworkSegment **)(v28 + 16);
          v30 = v29->mSubSegmentCollection.mNode.mNext;
          if ( v30 != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&v29->mSubSegmentCollection )
          {
            do
            {
              v31 = (float)((float)((float)(*((float *)&v30[1].mNext + 1) - v9)
                                  * (float)(*((float *)&v30[1].mNext + 1) - v9))
                          + (float)((float)(*(float *)&v30[1].mNext - v8) * (float)(*(float *)&v30[1].mNext - v8)))
                  + (float)((float)(*(float *)&v30[2].mPrev - v4) * (float)(*(float *)&v30[2].mPrev - v4));
              if ( v31 <= 10000.0
                && (!v6 || COERCE_FLOAT(COERCE_UNSIGNED_INT(v4 - *(float *)&v30[2].mPrev) & _xmm) <= 6.0) )
              {
                if ( v29->mpPropertySetCached )
                {
                  v32 = v29->mRoadNetworkType.mValue;
                }
                else
                {
                  v33 = UFG::RoadNetworkSegment::GetRoadPropertySet(v29);
                  v32 = 0;
                  if ( v33 )
                  {
                    v34 = UFG::qPropertySet::Get<unsigned long>(
                            v33,
                            (UFG::qSymbol *)&qSymbol_RoadNetworkType.mUID,
                            DEPTH_RECURSE);
                    if ( v34 )
                      v32 = *v34;
                  }
                }
                if ( v32 == v5 && v31 < v3 )
                {
                  v7 = v30;
                  v3 = v31;
                }
              }
              v30 = v30->mNext;
            }
            while ( v30 != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&v29->mSubSegmentCollection );
            v27 = v35;
          }
          v28 = *(_QWORD *)(v28 + 8);
        }
        while ( v28 != v27 );
        v26 = v39;
      }
      v25 = v38 + 1;
      v39 = --v26;
      ++v38;
    }
    while ( v26 );
  }
  return v7;
}

// File Line: 765
// RVA: 0xD9740
void __fastcall UFG::RoadNetworkResource::GetLanesIntersectingLine2D(UFG::RoadNetworkResource *this, UFG::qVector3 *v1, UFG::qVector3 *v2, UFG::qArray<int,0> *aIntersections, UFG::qArray<int,0> *aLanes, float fMaxIntersectionDistance)
{
  unsigned int v6; // ebx
  UFG::qArray<int,0> *v7; // r14
  UFG::RoadNetworkResource *v8; // rdi
  float v9; // xmm2_4
  float v10; // xmm3_4
  UFG::qArray<int,0> *v11; // rsi
  UFG::RoadNetworkIntersection *v12; // rax
  UFG::RoadNetworkIntersection *v13; // rbx
  UFG::RoadNetworkGate *v14; // rax
  __int64 v15; // rdx
  UFG::RoadNetworkGate *v16; // r8
  __int64 v17; // rax
  signed __int64 v18; // rcx
  __int64 v19; // rax
  signed __int64 v20; // rdx
  _DWORD *v21; // rcx
  __int64 v22; // rdx
  __int64 v23; // rax
  signed __int64 v24; // rcx
  __int64 v25; // rax
  signed __int64 v26; // rdx
  signed __int64 v27; // rbp
  __int64 v28; // r13
  unsigned int v29; // er12
  unsigned int v30; // ebx
  unsigned int v31; // edi
  unsigned int v32; // ebx
  unsigned __int64 v33; // rax
  char *v34; // rax
  int *v35; // r15
  __int64 v36; // r9
  int *v37; // rax
  int v38; // er12
  __int64 v39; // rbp
  unsigned int v40; // ebx
  unsigned int v41; // edi
  unsigned int v42; // ebx
  unsigned __int64 v43; // rax
  char *v44; // rax
  int *v45; // r15
  __int64 v46; // r9
  int *v47; // rax
  __int64 v48; // rdx
  __int64 v49; // rax
  signed __int64 v50; // rcx
  __int64 v51; // rax
  signed __int64 v52; // rdx
  _DWORD *v53; // rcx
  __int64 v54; // rdx
  __int64 v55; // rax
  signed __int64 v56; // rcx
  __int64 v57; // rax
  signed __int64 v58; // rdx
  signed __int64 v59; // rbp
  __int64 v60; // r13
  unsigned int v61; // er12
  unsigned int v62; // ebx
  unsigned int v63; // edi
  unsigned int v64; // ebx
  unsigned __int64 v65; // rax
  char *v66; // rax
  int *v67; // r15
  __int64 v68; // r9
  int *v69; // rax
  int v70; // er12
  __int64 v71; // rbp
  unsigned int v72; // ebx
  unsigned int v73; // edi
  unsigned int v74; // ebx
  unsigned __int64 v75; // rax
  char *v76; // rax
  int *v77; // r15
  __int64 v78; // r9
  int *v79; // rax
  UFG::qVector3 pos; // [rsp+30h] [rbp-58h]
  int v81; // [rsp+90h] [rbp+8h]
  int v82; // [rsp+90h] [rbp+8h]
  UFG::RoadNetworkIntersection *v83; // [rsp+98h] [rbp+10h]
  UFG::RoadNetworkGate *v84; // [rsp+A0h] [rbp+18h]
  _DWORD *v85; // [rsp+A8h] [rbp+20h]
  _DWORD *v86; // [rsp+A8h] [rbp+20h]
  int aLanesa; // [rsp+B0h] [rbp+28h]
  int aLanesb; // [rsp+B0h] [rbp+28h]

  v6 = this->mNumIntersections;
  v7 = aIntersections;
  v8 = this;
  v9 = (float)(v1->y + v2->y) * 0.5;
  v10 = v1->z + v2->z;
  pos.x = (float)(v1->x + v2->x) * 0.5;
  pos.y = v9;
  pos.z = v10 * 0.5;
  if ( v6 > aIntersections->capacity )
    UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)aIntersections, v6, "RoadNetworkResource");
  v11 = aLanes;
  if ( 4 * v6 > aLanes->capacity )
    UFG::qArray<long,0>::Reallocate((UFG::qArray<unsigned long,0> *)aLanes, 4 * v6, "RoadNetworkResource");
  v12 = UFG::RoadNetworkResource::GetClosestIntersection(v8, &pos, 0, fMaxIntersectionDistance, 0i64, 0i64);
  v13 = v12;
  v83 = v12;
  if ( v12 )
  {
    v14 = UFG::RoadNetworkIntersection::GetClosestGate(v12, &pos);
    v15 = 0i64;
    v16 = v14;
    v84 = v14;
    v81 = 0;
    if ( v14->mNumIncomingConnections )
    {
      do
      {
        v17 = v16->mIncomingConnection.mOffset;
        if ( v17 )
          v18 = (signed __int64)&v16->mIncomingConnection + v17;
        else
          v18 = 0i64;
        v19 = *(_QWORD *)(v18 + 8 * v15);
        v20 = v18 + 8 * v15;
        if ( v19 )
        {
          v21 = (_DWORD *)(v20 + v19);
          v85 = (_DWORD *)(v20 + v19);
          if ( v20 + v19 )
          {
            v22 = 0i64;
            aLanesa = 0;
            if ( *v21 )
            {
              do
              {
                v23 = *((_QWORD *)v21 + 1);
                if ( v23 )
                  v24 = (signed __int64)v21 + v23 + 8;
                else
                  v24 = 0i64;
                v25 = *(_QWORD *)(v24 + 8 * v22);
                v26 = v24 + 8 * v22;
                if ( v25 )
                  v27 = v26 + v25;
                else
                  v27 = 0i64;
                if ( *(_BYTE *)(v27 + 44) & 2 )
                {
                  v28 = v7->size;
                  v29 = v13->mIndex;
                  v30 = v7->capacity;
                  v31 = v28 + 1;
                  if ( (signed int)v28 + 1 > v30 )
                  {
                    if ( v30 )
                      v32 = 2 * v30;
                    else
                      v32 = 1;
                    for ( ; v32 < v31; v32 *= 2 )
                      ;
                    if ( v32 <= 4 )
                      v32 = 4;
                    if ( v32 - v31 > 0x10000 )
                      v32 = v28 + 65537;
                    if ( v32 != (_DWORD)v28 )
                    {
                      v33 = 4i64 * v32;
                      if ( !is_mul_ok(v32, 4ui64) )
                        v33 = -1i64;
                      v34 = UFG::qMalloc(v33, "qArray.Add.Intersection", 0i64);
                      v35 = (int *)v34;
                      if ( v7->p )
                      {
                        v36 = 0i64;
                        if ( v7->size )
                        {
                          do
                          {
                            *(_DWORD *)&v34[4 * v36] = v7->p[v36];
                            v36 = (unsigned int)(v36 + 1);
                          }
                          while ( (unsigned int)v36 < v7->size );
                        }
                        operator delete[](v7->p);
                      }
                      v7->p = v35;
                      v7->capacity = v32;
                    }
                  }
                  v37 = v7->p;
                  v7->size = v31;
                  v37[v28] = v29;
                  v38 = *(unsigned __int16 *)(v27 + 36);
                  v39 = v11->size;
                  v40 = v11->capacity;
                  v41 = v39 + 1;
                  if ( (signed int)v39 + 1 > v40 )
                  {
                    if ( v40 )
                      v42 = 2 * v40;
                    else
                      v42 = 1;
                    for ( ; v42 < v41; v42 *= 2 )
                      ;
                    if ( v42 <= 4 )
                      v42 = 4;
                    if ( v42 - v41 > 0x10000 )
                      v42 = v39 + 65537;
                    if ( v42 != (_DWORD)v39 )
                    {
                      v43 = 4i64 * v42;
                      if ( !is_mul_ok(v42, 4ui64) )
                        v43 = -1i64;
                      v44 = UFG::qMalloc(v43, "qArray.Add.LaneID", 0i64);
                      v45 = (int *)v44;
                      if ( v11->p )
                      {
                        v46 = 0i64;
                        if ( v11->size )
                        {
                          do
                          {
                            *(_DWORD *)&v44[4 * v46] = v11->p[v46];
                            v46 = (unsigned int)(v46 + 1);
                          }
                          while ( (unsigned int)v46 < v11->size );
                        }
                        operator delete[](v11->p);
                      }
                      v11->p = v45;
                      v11->capacity = v42;
                    }
                  }
                  v47 = v11->p;
                  v13 = v83;
                  v11->size = v41;
                  v47[v39] = v38;
                }
                v21 = v85;
                v22 = (unsigned int)(aLanesa + 1);
                aLanesa = v22;
              }
              while ( (unsigned int)v22 < *v85 );
              v16 = v84;
            }
          }
        }
        v15 = (unsigned int)(v81 + 1);
        v81 = v15;
      }
      while ( (unsigned int)v15 < v16->mNumIncomingConnections );
    }
    v48 = 0i64;
    v82 = 0;
    if ( v16->mNumOutgoingConnections )
    {
      do
      {
        v49 = v16->mOutgoingConnection.mOffset;
        if ( v49 )
          v50 = (signed __int64)&v16->mOutgoingConnection + v49;
        else
          v50 = 0i64;
        v51 = *(_QWORD *)(v50 + 8 * v48);
        v52 = v50 + 8 * v48;
        if ( v51 )
        {
          v53 = (_DWORD *)(v52 + v51);
          v86 = (_DWORD *)(v52 + v51);
          if ( v52 + v51 )
          {
            v54 = 0i64;
            aLanesb = 0;
            if ( *v53 )
            {
              do
              {
                v55 = *((_QWORD *)v53 + 1);
                if ( v55 )
                  v56 = (signed __int64)v53 + v55 + 8;
                else
                  v56 = 0i64;
                v57 = *(_QWORD *)(v56 + 8 * v54);
                v58 = v56 + 8 * v54;
                if ( v57 )
                  v59 = v58 + v57;
                else
                  v59 = 0i64;
                if ( *(_BYTE *)(v59 + 44) & 2 )
                {
                  v60 = v7->size;
                  v61 = v13->mIndex;
                  v62 = v7->capacity;
                  v63 = v60 + 1;
                  if ( (signed int)v60 + 1 > v62 )
                  {
                    if ( v62 )
                      v64 = 2 * v62;
                    else
                      v64 = 1;
                    for ( ; v64 < v63; v64 *= 2 )
                      ;
                    if ( v64 <= 4 )
                      v64 = 4;
                    if ( v64 - v63 > 0x10000 )
                      v64 = v60 + 65537;
                    if ( v64 != (_DWORD)v60 )
                    {
                      v65 = 4i64 * v64;
                      if ( !is_mul_ok(v64, 4ui64) )
                        v65 = -1i64;
                      v66 = UFG::qMalloc(v65, "qArray.Add.Intersection", 0i64);
                      v67 = (int *)v66;
                      if ( v7->p )
                      {
                        v68 = 0i64;
                        if ( v7->size )
                        {
                          do
                          {
                            *(_DWORD *)&v66[4 * v68] = v7->p[v68];
                            v68 = (unsigned int)(v68 + 1);
                          }
                          while ( (unsigned int)v68 < v7->size );
                        }
                        operator delete[](v7->p);
                      }
                      v7->p = v67;
                      v7->capacity = v64;
                    }
                  }
                  v69 = v7->p;
                  v7->size = v63;
                  v69[v60] = v61;
                  v70 = *(unsigned __int16 *)(v59 + 36);
                  v71 = v11->size;
                  v72 = v11->capacity;
                  v73 = v71 + 1;
                  if ( (signed int)v71 + 1 > v72 )
                  {
                    if ( v72 )
                      v74 = 2 * v72;
                    else
                      v74 = 1;
                    for ( ; v74 < v73; v74 *= 2 )
                      ;
                    if ( v74 <= 4 )
                      v74 = 4;
                    if ( v74 - v73 > 0x10000 )
                      v74 = v71 + 65537;
                    if ( v74 != (_DWORD)v71 )
                    {
                      v75 = 4i64 * v74;
                      if ( !is_mul_ok(v74, 4ui64) )
                        v75 = -1i64;
                      v76 = UFG::qMalloc(v75, "qArray.Add.LaneID", 0i64);
                      v77 = (int *)v76;
                      if ( v11->p )
                      {
                        v78 = 0i64;
                        if ( v11->size )
                        {
                          do
                          {
                            *(_DWORD *)&v76[4 * v78] = v11->p[v78];
                            v78 = (unsigned int)(v78 + 1);
                          }
                          while ( (unsigned int)v78 < v11->size );
                        }
                        operator delete[](v11->p);
                      }
                      v11->p = v77;
                      v11->capacity = v74;
                    }
                  }
                  v79 = v11->p;
                  v11->size = v73;
                  v79[v71] = v70;
                }
                v53 = v86;
                v13 = v83;
                v54 = (unsigned int)(aLanesb + 1);
                aLanesb = v54;
              }
              while ( (unsigned int)v54 < *v86 );
              v16 = v84;
            }
          }
        }
        v13 = v83;
        v48 = (unsigned int)(v82 + 1);
        v82 = v48;
      }
      while ( (unsigned int)v48 < v16->mNumOutgoingConnections );
    }
  }
}

