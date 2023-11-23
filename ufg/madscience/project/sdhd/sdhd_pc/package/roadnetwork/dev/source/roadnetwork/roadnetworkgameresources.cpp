// File Line: 83
// RVA: 0x1460910
hkSeekableStreamReader *dynamic_initializer_for__UFG::ClosestSegmentCache::mNodeCacheItem__()
{
  hkSeekableStreamReader *v0; // rbx
  int i; // edi
  hkSeekableStreamReader *result; // rax

  v0 = &UFG::ClosestSegmentCache::mNodeCacheItem;
  for ( i = 31; i >= 0; --i )
  {
    result = Assembly::GetRCX(v0);
    v0 += 2;
  }
  return result;
}

// File Line: 115
// RVA: 0xDD100
void __fastcall UFG::RoadNetworkResource::InitDataGrids(UFG::RoadNetworkResource *this)
{
  UFG::RoadNetworkResource *v1; // r13
  unsigned __int16 *p_m_memSizeAndFlags; // rax
  __int64 v3; // r14
  __int64 v4; // rdx
  float z; // xmm0_4
  float y; // xmm1_4
  float x; // xmm2_4
  unsigned int v8; // esi
  __int64 mOffset; // rax
  char *v10; // rcx
  char *v11; // rdx
  char *v12; // rax
  unsigned __int8 v13; // dl
  __int64 v14; // rcx
  char *v15; // rcx
  char *v16; // rdx
  float *v17; // rdi
  char *v18; // rax
  __int64 v19; // rcx
  UFG::RoadNetworkConnection *v20; // rcx
  float v21; // xmm8_4
  float i; // xmm6_4
  char *v23; // rax
  __int64 v24; // rcx
  UFG::RoadNetworkConnection *v25; // rcx
  UFG::qBezierPathMemImaged *Path; // rbx
  unsigned int SplineParameters; // eax
  UFG::qBezierSplineMemImaged *v28; // rax
  __int64 v29; // rdi
  UFG::Grid<UFG::RoadNetworkSegment> *v30; // rax
  UFG::Grid<UFG::RoadNetworkSegment> *v31; // rbx
  UFG::Grid<UFG::RoadNetworkSegment> *v32; // rax
  UFG::Grid<UFG::RoadNetworkIntersection> *v33; // rbx
  unsigned int j; // r15d
  int v35; // r14d
  __int64 v36; // rax
  char *v37; // rcx
  char *v38; // rdx
  UFG::RoadNetworkSegment *v39; // rdi
  unsigned __int8 mNumLanes; // al
  __int64 v41; // rax
  __int64 v42; // rcx
  char *v43; // rcx
  char *v44; // rdx
  float *v45; // rsi
  char *v46; // rax
  __int64 v47; // rcx
  UFG::RoadNetworkConnection *v48; // rcx
  float v49; // xmm8_4
  float v50; // xmm6_4
  char *v51; // rax
  __int64 v52; // rcx
  UFG::RoadNetworkConnection *v53; // rcx
  UFG::qBezierPathMemImaged *v54; // rbx
  unsigned int v55; // eax
  UFG::qBezierSplineMemImaged *v56; // rax
  float v57; // xmm7_4
  int v58; // xmm4_4
  __m128 y_low; // xmm1
  float v60; // xmm3_4
  float v61; // xmm1_4
  float v62; // xmm2_4
  float v63; // xmm0_4
  UFG::qVector3 *Position; // rax
  unsigned int mValue; // ebx
  UFG::qPropertySet *RoadPropertySet; // rax
  unsigned int *v67; // rax
  UFG::Grid<UFG::RoadNetworkSegment> *v68; // rcx
  unsigned int v69; // r8d
  unsigned int k; // r15d
  int v71; // r14d
  __int64 v72; // rax
  char *v73; // rcx
  char *v74; // rdx
  UFG::RoadNetworkIntersection *v75; // rbx
  unsigned int v76; // edi
  __int64 v77; // rax
  char *v78; // rcx
  char *v79; // rdx
  float *v80; // rsi
  UFG::Grid<UFG::RoadNetworkSegment> *v81; // rcx
  unsigned int v82; // r8d
  UFG::qVector3 result; // [rsp+8h] [rbp-71h] BYREF
  UFG::qVector3 tangent; // [rsp+18h] [rbp-61h] BYREF
  UFG::qVector3 y_max; // [rsp+28h] [rbp-51h] BYREF
  UFG::RoadNetworkResource *v86; // [rsp+E0h] [rbp+67h]
  float splineT[2]; // [rsp+E8h] [rbp+6Fh] BYREF

  v1 = this;
  p_m_memSizeAndFlags = &UFG::ClosestSegmentCache::mNodeCacheItem.m_memSizeAndFlags;
  v3 = 4i64;
  v4 = 4i64;
  z = UFG::qVector3::msZero.z;
  y = UFG::qVector3::msZero.y;
  x = UFG::qVector3::msZero.x;
  do
  {
    *((float *)p_m_memSizeAndFlags - 2) = x;
    *((float *)p_m_memSizeAndFlags - 1) = y;
    *(float *)p_m_memSizeAndFlags = z;
    *((_QWORD *)p_m_memSizeAndFlags + 2) = 0i64;
    *((float *)p_m_memSizeAndFlags + 1) = x;
    *((float *)p_m_memSizeAndFlags + 2) = y;
    *((float *)p_m_memSizeAndFlags + 3) = z;
    *((float *)p_m_memSizeAndFlags + 6) = x;
    *((float *)p_m_memSizeAndFlags + 7) = y;
    *((float *)p_m_memSizeAndFlags + 8) = z;
    *((_QWORD *)p_m_memSizeAndFlags + 6) = 0i64;
    *((float *)p_m_memSizeAndFlags + 9) = x;
    *((float *)p_m_memSizeAndFlags + 10) = y;
    *((float *)p_m_memSizeAndFlags + 11) = z;
    *((float *)p_m_memSizeAndFlags + 14) = x;
    *((float *)p_m_memSizeAndFlags + 15) = y;
    *((float *)p_m_memSizeAndFlags + 16) = z;
    *((_QWORD *)p_m_memSizeAndFlags + 10) = 0i64;
    *((float *)p_m_memSizeAndFlags + 17) = x;
    *((float *)p_m_memSizeAndFlags + 18) = y;
    *((float *)p_m_memSizeAndFlags + 19) = z;
    *((float *)p_m_memSizeAndFlags + 22) = x;
    *((float *)p_m_memSizeAndFlags + 23) = y;
    *((float *)p_m_memSizeAndFlags + 24) = z;
    *((_QWORD *)p_m_memSizeAndFlags + 14) = 0i64;
    *((float *)p_m_memSizeAndFlags + 25) = x;
    *((float *)p_m_memSizeAndFlags + 26) = y;
    *((float *)p_m_memSizeAndFlags + 27) = z;
    *((float *)p_m_memSizeAndFlags + 30) = x;
    *((float *)p_m_memSizeAndFlags + 31) = y;
    *((float *)p_m_memSizeAndFlags + 32) = z;
    *((_QWORD *)p_m_memSizeAndFlags + 18) = 0i64;
    *((float *)p_m_memSizeAndFlags + 33) = x;
    *((float *)p_m_memSizeAndFlags + 34) = y;
    *((float *)p_m_memSizeAndFlags + 35) = z;
    *((float *)p_m_memSizeAndFlags + 38) = x;
    *((float *)p_m_memSizeAndFlags + 39) = y;
    *((float *)p_m_memSizeAndFlags + 40) = z;
    *((_QWORD *)p_m_memSizeAndFlags + 22) = 0i64;
    *((float *)p_m_memSizeAndFlags + 41) = x;
    *((float *)p_m_memSizeAndFlags + 42) = y;
    *((float *)p_m_memSizeAndFlags + 43) = z;
    *((float *)p_m_memSizeAndFlags + 46) = x;
    *((float *)p_m_memSizeAndFlags + 47) = y;
    *((float *)p_m_memSizeAndFlags + 48) = z;
    *((_QWORD *)p_m_memSizeAndFlags + 26) = 0i64;
    *((float *)p_m_memSizeAndFlags + 49) = x;
    *((float *)p_m_memSizeAndFlags + 50) = y;
    *((float *)p_m_memSizeAndFlags + 51) = z;
    *((float *)p_m_memSizeAndFlags + 54) = x;
    *((float *)p_m_memSizeAndFlags + 55) = y;
    *((float *)p_m_memSizeAndFlags + 56) = z;
    *((_QWORD *)p_m_memSizeAndFlags + 30) = 0i64;
    *((float *)p_m_memSizeAndFlags + 57) = x;
    *((float *)p_m_memSizeAndFlags + 58) = y;
    *((float *)p_m_memSizeAndFlags + 59) = z;
    p_m_memSizeAndFlags += 128;
    --v4;
  }
  while ( v4 );
  v8 = 0;
  if ( this->mNumSegments )
  {
    do
    {
      mOffset = v1->mSegmentOffsetTable.mOffset;
      if ( mOffset )
        v10 = (char *)&v1->mSegmentOffsetTable + mOffset;
      else
        v10 = 0i64;
      v11 = &v10[8 * v8];
      if ( *(_QWORD *)v11 )
        v12 = &v11[*(_QWORD *)v11];
      else
        v12 = 0i64;
      v13 = v12[40];
      if ( v13 )
      {
        v14 = *((_QWORD *)v12 + 6);
        if ( v14 )
          v15 = &v12[v14 + 48];
        else
          v15 = 0i64;
        v16 = &v15[8 * ((unsigned __int64)v13 >> 1)];
        v17 = (float *)&v16[*(_QWORD *)v16];
        if ( !*(_QWORD *)v16 )
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
          Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                v25,
                                                *((unsigned __int16 *)v17 + 19));
          SplineParameters = UFG::qBezierPathMemImaged::GetSplineParameters(Path, i, splineT);
          v28 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                 (UFG::RoadNetworkConnection *)Path,
                                                 SplineParameters);
          UFG::RoadNetworkLane::GetOffsetPos(&result, v28, splineT[0], v17[10]);
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
  v29 = 0i64;
  do
  {
    v30 = (UFG::Grid<UFG::RoadNetworkSegment> *)UFG::qMalloc(0x30ui64, "Grid<RoadNetworkSegment>", 0i64);
    v31 = v30;
    *(_QWORD *)splineT = v30;
    if ( v30 )
    {
      v30->mGridNodes = 0i64;
      UFG::Grid<UFG::RoadNetworkSegment>::Init(
        v30,
        RoadExtents_minX,
        RoadExtents_minY,
        RoadExtents_maxX,
        RoadExtents_maxY,
        150.0);
    }
    else
    {
      v31 = 0i64;
    }
    gSegmentsDataGrid[v29] = v31;
    v32 = (UFG::Grid<UFG::RoadNetworkSegment> *)UFG::qMalloc(0x30ui64, "Grid<RoadNetworkIntersection>", 0i64);
    v33 = (UFG::Grid<UFG::RoadNetworkIntersection> *)v32;
    *(_QWORD *)splineT = v32;
    if ( v32 )
    {
      v32->mGridNodes = 0i64;
      UFG::Grid<UFG::RoadNetworkSegment>::Init(
        v32,
        RoadExtents_minX,
        RoadExtents_minY,
        RoadExtents_maxX,
        RoadExtents_maxY,
        150.0);
    }
    else
    {
      v33 = 0i64;
    }
    gIntersectionsDataGrid[v29++] = v33;
    --v3;
  }
  while ( v3 );
  for ( j = 0; j < v1->mNumSegments; ++j )
  {
    v35 = -1;
    v36 = v1->mSegmentOffsetTable.mOffset;
    if ( v36 )
      v37 = (char *)&v1->mSegmentOffsetTable + v36;
    else
      v37 = 0i64;
    v38 = &v37[8 * j];
    v39 = (UFG::RoadNetworkSegment *)&v38[*(_QWORD *)v38];
    if ( !*(_QWORD *)v38 )
      v39 = 0i64;
    if ( !v39->mType.mValue )
    {
      mNumLanes = v39->mNumLanes;
      if ( mNumLanes )
      {
        v41 = ((unsigned int)mNumLanes - 1) >> 1;
        v42 = v39->mLane.mOffset;
        if ( v42 )
          v43 = (char *)&v39->mLane + v42;
        else
          v43 = 0i64;
        v44 = &v43[8 * v41];
        v45 = (float *)&v44[*(_QWORD *)v44];
        if ( !*(_QWORD *)v44 )
          v45 = 0i64;
        if ( *(_QWORD *)v45 )
          v46 = (char *)v45 + *(_QWORD *)v45;
        else
          v46 = 0i64;
        v47 = *((_QWORD *)v46 + 4);
        if ( v47 )
          v48 = (UFG::RoadNetworkConnection *)&v46[v47 + 32];
        else
          v48 = 0i64;
        v49 = 1.0
            / *((float *)&UFG::qBezierPathCollectionMemImaged::GetPath(v48, *((unsigned __int16 *)v45 + 19))->mNode.mOffset
              + 1);
        v50 = v49;
        if ( v49 < 1.0 )
        {
          do
          {
            if ( *(_QWORD *)v45 )
              v51 = (char *)v45 + *(_QWORD *)v45;
            else
              v51 = 0i64;
            v52 = *((_QWORD *)v51 + 4);
            if ( v52 )
              v53 = (UFG::RoadNetworkConnection *)&v51[v52 + 32];
            else
              v53 = 0i64;
            v54 = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                 v53,
                                                 *((unsigned __int16 *)v45 + 19));
            v55 = UFG::qBezierPathMemImaged::GetSplineParameters(v54, v50, splineT);
            v56 = (UFG::qBezierSplineMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(
                                                   (UFG::RoadNetworkConnection *)v54,
                                                   v55);
            v57 = v45[10];
            if ( v57 == 0.0 )
            {
              Position = UFG::qBezierSplineMemImaged::GetPosition(v56, &y_max, splineT[0]);
              v62 = Position->y;
              v63 = Position->z;
              v61 = Position->x;
            }
            else
            {
              UFG::qBezierSplineMemImaged::GetPositionAndTangent(v56, splineT[0], &result, &tangent);
              v58 = LODWORD(tangent.x) ^ _xmm[0];
              y_low = (__m128)LODWORD(tangent.y);
              y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                                + (float)(*(float *)&v58 * *(float *)&v58);
              if ( y_low.m128_f32[0] == 0.0 )
                v60 = 0.0;
              else
                v60 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
              v61 = result.x + (float)((float)(v60 * tangent.y) * v57);
              v62 = result.y + (float)((float)(*(float *)&v58 * v60) * v57);
              v63 = result.z + (float)((float)(v60 * 0.0) * v57);
            }
            result.z = v63;
            result.y = v62;
            result.x = v61;
            if ( v39->mpPropertySetCached )
            {
              mValue = v39->mRoadNetworkType.mValue;
            }
            else
            {
              RoadPropertySet = UFG::RoadNetworkSegment::GetRoadPropertySet(v39);
              mValue = 0;
              if ( RoadPropertySet )
              {
                v67 = UFG::qPropertySet::Get<unsigned long>(RoadPropertySet, &qSymbol_RoadNetworkType, DEPTH_RECURSE);
                if ( v67 )
                  mValue = *v67;
              }
              v62 = result.y;
              v61 = result.x;
            }
            v68 = gSegmentsDataGrid[mValue];
            if ( v68 )
            {
              v69 = (int)(float)((float)(v61 - v68->mXMin) * v68->mGridSizeInv)
                  + v68->mXDim * (int)(float)((float)(v62 - v68->mYMin) * v68->mGridSizeInv);
              if ( v69 != v35 )
              {
                v35 = (int)(float)((float)(v61 - v68->mXMin) * v68->mGridSizeInv)
                    + v68->mXDim * (int)(float)((float)(v62 - v68->mYMin) * v68->mGridSizeInv);
                UFG::Grid<UFG::RoadNetworkSegment>::Add(v68, v39, v69);
              }
            }
            v50 = v50 + v49;
          }
          while ( v50 < 1.0 );
          v1 = v86;
        }
      }
    }
  }
  for ( k = 0; k < v1->mNumIntersections; ++k )
  {
    v71 = -1;
    v72 = v1->mIntersectionOffsetTable.mOffset;
    if ( v72 )
      v73 = (char *)&v1->mIntersectionOffsetTable + v72;
    else
      v73 = 0i64;
    v74 = &v73[8 * k];
    v75 = (UFG::RoadNetworkIntersection *)&v74[*(_QWORD *)v74];
    if ( !*(_QWORD *)v74 )
      v75 = 0i64;
    if ( v75->mNumLanes )
    {
      v76 = 0;
      if ( v75->mNumGates )
      {
        do
        {
          v77 = v75->mGates.mOffset;
          if ( v77 )
            v78 = (char *)&v75->mGates + v77;
          else
            v78 = 0i64;
          v79 = &v78[8 * v76];
          v80 = (float *)&v79[*(_QWORD *)v79];
          if ( !*(_QWORD *)v79 )
            v80 = 0i64;
          v81 = (UFG::Grid<UFG::RoadNetworkSegment> *)gIntersectionsDataGrid[(unsigned int)UFG::RoadNetworkIntersection::GetRoadNetworkType(v75)];
          if ( v81 )
          {
            v82 = (int)(float)((float)(v80[6] - v81->mXMin) * v81->mGridSizeInv)
                + v81->mXDim * (int)(float)((float)(v80[7] - v81->mYMin) * v81->mGridSizeInv);
            if ( v82 != v71 )
            {
              v71 = (int)(float)((float)(v80[6] - v81->mXMin) * v81->mGridSizeInv)
                  + v81->mXDim * (int)(float)((float)(v80[7] - v81->mYMin) * v81->mGridSizeInv);
              UFG::Grid<UFG::RoadNetworkSegment>::Add(v81, (UFG::RoadNetworkSegment *)v75, v82);
            }
          }
          ++v76;
        }
        while ( v76 < (unsigned __int8)v75->mNumGates );
        v1 = v86;
      }
    }
  }
}

// File Line: 231
// RVA: 0xD3810
void __fastcall UFG::RoadNetworkResource::ClearDataGrids(UFG::RoadNetworkResource *this)
{
  __int64 v1; // rbp
  void ***v2; // rsi
  __int64 v3; // r14
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
        `eh vector destructor iterator(
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
        `eh vector destructor iterator(
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
void __fastcall UFG::RoadNetworkResource::GetIntersectionsInGrid(
        UFG::RoadNetworkResource *this,
        UFG::qArray<UFG::qReflectInventoryBase *,0> *intersections,
        UFG::qVector3 *position,
        unsigned int roadNetworkType,
        float radius)
{
  unsigned int v5; // ebp
  UFG::Grid<UFG::RoadNetworkIntersection> *v7; // rdi
  float v8; // xmm3_4
  float mGridSizeInv; // xmm5_4
  __int64 mXDim; // r11
  __int64 v11; // rdx
  int v12; // r10d
  float v13; // xmm2_4
  int v14; // ebx
  int mYDim; // eax
  int v16; // ecx
  int v17; // r8d
  __int64 v18; // rsi
  __int64 v19; // r9
  __int64 v20; // r11
  __int64 v21; // rcx
  __int64 v22; // r8
  __int64 v23; // r13
  __int64 *v24; // r12
  __int64 v25; // r15
  __int64 v26; // rsi
  UFG::RoadNetworkIntersection *v27; // rcx
  __int64 size; // rdi
  UFG::RoadNetworkNode *v29; // rbp
  __int64 v30; // rcx
  unsigned int capacity; // edx
  unsigned int v32; // ebx
  unsigned int v33; // edx
  UFG::RoadNetworkNode **p; // rax
  __int64 v35; // [rsp+20h] [rbp-108h]
  __int64 v36[25]; // [rsp+30h] [rbp-F8h] BYREF
  int v37; // [rsp+F8h] [rbp-30h]

  v5 = roadNetworkType;
  v7 = gIntersectionsDataGrid[roadNetworkType];
  if ( v7->mNodeCount )
  {
    v8 = radius;
    if ( radius > MaxGridQueryDistance )
      v8 = MaxGridQueryDistance;
    mGridSizeInv = v7->mGridSizeInv;
    mXDim = v7->mXDim;
    v11 = 0i64;
    v12 = (int)(float)((float)((float)(position->x - v8) - v7->mXMin) * mGridSizeInv);
    v13 = (float)((float)(position->x + v8) - v7->mXMin) * mGridSizeInv;
    if ( v12 < 0 )
      v12 = 0;
    v14 = (int)v13;
    if ( (int)v13 >= (int)mXDim )
      v14 = mXDim - 1;
    mYDim = v7->mYDim;
    v16 = (int)(float)((float)((float)(position->y + v8) - v7->mYMin) * mGridSizeInv);
    v17 = (int)(float)((float)((float)(position->y - v8) - v7->mYMin) * mGridSizeInv);
    if ( v17 < 0 )
      v17 = 0;
    if ( v16 >= mYDim )
      v16 = mYDim - 1;
    v37 = 0;
    if ( v17 <= v16 )
    {
      v18 = 16 * mXDim;
      v19 = 16i64 * (v12 + v17 * (int)mXDim);
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
              v11 = (unsigned int)++v37;
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
              size = intersections->size;
              v29 = *(UFG::RoadNetworkNode **)(v26 + 16);
              v30 = 0i64;
              if ( !(_DWORD)size )
                goto LABEL_30;
              while ( v29 != (UFG::RoadNetworkNode *)intersections->p[v30] )
              {
                v30 = (unsigned int)(v30 + 1);
                if ( (unsigned int)v30 >= (unsigned int)size )
                  goto LABEL_30;
              }
              if ( (_DWORD)v30 == -1 )
              {
LABEL_30:
                capacity = intersections->capacity;
                v32 = size + 1;
                if ( (int)size + 1 > capacity )
                {
                  if ( capacity )
                    v33 = 2 * capacity;
                  else
                    v33 = 1;
                  for ( ; v33 < v32; v33 *= 2 )
                    ;
                  if ( v33 <= 2 )
                    v33 = 2;
                  if ( v33 - v32 > 0x10000 )
                    v33 = size + 65537;
                  UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(intersections, v33, "qArray.Add");
                }
                p = (UFG::RoadNetworkNode **)intersections->p;
                intersections->size = v32;
                p[size] = v29;
              }
              v5 = roadNetworkType;
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
void __fastcall UFG::RoadNetworkResource::GetSegmentsInGrid(
        UFG::RoadNetworkResource *this,
        UFG::qArray<UFG::qReflectInventoryBase *,0> *segments,
        UFG::qVector3 *position,
        unsigned int roadNetworkType,
        float radius)
{
  UFG::Grid<UFG::RoadNetworkSegment> *v6; // rdi
  float v7; // xmm3_4
  float mGridSizeInv; // xmm5_4
  __int64 mXDim; // r11
  __int64 v10; // rdx
  int v11; // r10d
  float v12; // xmm2_4
  int v13; // ebx
  int mYDim; // eax
  int v15; // ecx
  int v16; // r8d
  __int64 v17; // rsi
  __int64 v18; // r9
  __int64 v19; // r11
  __int64 v20; // rcx
  __int64 v21; // r8
  __int64 *v22; // r12
  __int64 v23; // r13
  __int64 v24; // r15
  __int64 v25; // rbp
  UFG::RoadNetworkSegment *v26; // rdi
  unsigned int mValue; // ebx
  UFG::qPropertySet *RoadPropertySet; // rax
  unsigned int *v29; // rax
  __int64 size; // rsi
  int v31; // ecx
  unsigned int capacity; // edx
  unsigned int v33; // ebx
  unsigned int v34; // edx
  UFG::RoadNetworkSegment **p; // rax
  __int64 v36; // [rsp+20h] [rbp-108h]
  __int64 *v37; // [rsp+28h] [rbp-100h]
  __int64 v38[25]; // [rsp+30h] [rbp-F8h] BYREF
  int v39; // [rsp+F8h] [rbp-30h]

  v6 = gSegmentsDataGrid[roadNetworkType];
  if ( v6->mNodeCount )
  {
    v7 = radius;
    if ( radius > MaxGridQueryDistance )
      v7 = MaxGridQueryDistance;
    mGridSizeInv = v6->mGridSizeInv;
    mXDim = v6->mXDim;
    v10 = 0i64;
    v11 = (int)(float)((float)((float)(position->x - v7) - v6->mXMin) * mGridSizeInv);
    v12 = (float)((float)(position->x + v7) - v6->mXMin) * mGridSizeInv;
    if ( v11 < 0 )
      v11 = 0;
    v13 = (int)v12;
    if ( (int)v12 >= (int)mXDim )
      v13 = mXDim - 1;
    mYDim = v6->mYDim;
    v15 = (int)(float)((float)((float)(position->y + v7) - v6->mYMin) * mGridSizeInv);
    v16 = (int)(float)((float)((float)(position->y - v7) - v6->mYMin) * mGridSizeInv);
    if ( v16 < 0 )
      v16 = 0;
    if ( v15 >= mYDim )
      v15 = mYDim - 1;
    v39 = 0;
    if ( v16 <= v15 )
    {
      v17 = 16 * mXDim;
      v18 = 16i64 * (v11 + v16 * (int)mXDim);
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
              v10 = (unsigned int)++v39;
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
            v26 = *(UFG::RoadNetworkSegment **)(v25 + 16);
            if ( v26->mNumLanes )
            {
              if ( v26->mpPropertySetCached )
              {
                mValue = v26->mRoadNetworkType.mValue;
              }
              else
              {
                RoadPropertySet = UFG::RoadNetworkSegment::GetRoadPropertySet(*(UFG::RoadNetworkSegment **)(v25 + 16));
                mValue = 0;
                if ( RoadPropertySet )
                {
                  v29 = UFG::qPropertySet::Get<unsigned long>(RoadPropertySet, &qSymbol_RoadNetworkType, DEPTH_RECURSE);
                  if ( v29 )
                    mValue = *v29;
                }
              }
              if ( mValue == roadNetworkType )
              {
                size = segments->size;
                v31 = 0;
                if ( !(_DWORD)size )
                  goto LABEL_35;
                while ( v26 != (UFG::RoadNetworkSegment *)segments->p[v31] )
                {
                  if ( ++v31 >= (unsigned int)size )
                    goto LABEL_35;
                }
                if ( v31 == -1 )
                {
LABEL_35:
                  capacity = segments->capacity;
                  v33 = size + 1;
                  if ( (int)size + 1 > capacity )
                  {
                    if ( capacity )
                      v34 = 2 * capacity;
                    else
                      v34 = 1;
                    for ( ; v34 < v33; v34 *= 2 )
                      ;
                    if ( v34 <= 2 )
                      v34 = 2;
                    if ( v34 - v33 > 0x10000 )
                      v34 = size + 65537;
                    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(segments, v34, "qArray.Add");
                  }
                  p = (UFG::RoadNetworkSegment **)segments->p;
                  segments->size = v33;
                  p[size] = v26;
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
UFG::RoadNetworkIntersection *__fastcall UFG::RoadNetworkResource::GetClosestNode(
        UFG::RoadNetworkResource *this,
        UFG::qVector3 *pos,
        unsigned int roadNetworkType,
        UFG::qVector3 *nodePos,
        UFG::RoadNetworkClosestQueryCache *cache)
{
  UFG::RoadNetworkSegment *ClosestSegment; // rax
  float z; // xmm6_4
  float y; // xmm7_4
  float x; // xmm8_4
  UFG::RoadNetworkSegment *v13; // rdi
  __m128 y_low; // xmm2
  float v15; // xmm3_4
  UFG::RoadNetworkIntersection *result; // rax
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm5_4
  float v21; // xmm10_4
  float v22; // xmm11_4
  UFG::qVector3 pposClosest; // [rsp+30h] [rbp-88h] BYREF

  pposClosest = UFG::qVector3::msZero;
  ClosestSegment = UFG::RoadNetworkResource::GetClosestSegment(this, pos, 0i64, roadNetworkType, &pposClosest, cache);
  z = pposClosest.z;
  y = pposClosest.y;
  x = pposClosest.x;
  v13 = ClosestSegment;
  if ( ClosestSegment )
  {
    y_low = (__m128)LODWORD(pos->y);
    y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - pposClosest.y)
                                      * (float)(y_low.m128_f32[0] - pposClosest.y))
                              + (float)((float)(pos->x - pposClosest.x) * (float)(pos->x - pposClosest.x)))
                      + (float)((float)(pos->z - pposClosest.z) * (float)(pos->z - pposClosest.z));
    LODWORD(v15) = _mm_sqrt_ps(y_low).m128_u32[0];
  }
  else
  {
    v15 = FLOAT_3_4028235e38;
  }
  pposClosest = UFG::qVector3::msZero;
  result = UFG::RoadNetworkResource::GetClosestIntersection(this, pos, roadNetworkType, v15, &pposClosest, cache);
  if ( v13 )
  {
    if ( result )
    {
      v19 = pos->x;
      v20 = pos->y;
      v21 = pposClosest.y;
      v22 = pposClosest.z;
      if ( (float)((float)((float)((float)(v20 - pposClosest.y) * (float)(v20 - pposClosest.y))
                         + (float)((float)(v19 - pposClosest.x) * (float)(v19 - pposClosest.x)))
                 + (float)((float)(pos->z - pposClosest.z) * (float)(pos->z - pposClosest.z))) >= (float)((float)((float)((float)(v20 - y) * (float)(v20 - y)) + (float)((float)(v19 - x) * (float)(v19 - x))) + (float)((float)(pos->z - z) * (float)(pos->z - z))) )
      {
        if ( nodePos )
        {
          nodePos->x = x;
          nodePos->y = y;
          nodePos->z = z;
        }
        return (UFG::RoadNetworkIntersection *)v13;
      }
      else if ( nodePos )
      {
        nodePos->x = pposClosest.x;
        nodePos->y = v21;
        nodePos->z = v22;
      }
    }
    else
    {
      if ( nodePos )
      {
        nodePos->x = x;
        nodePos->y = y;
        nodePos->z = z;
      }
      return (UFG::RoadNetworkIntersection *)v13;
    }
  }
  else if ( result )
  {
    if ( nodePos )
    {
      v17 = pposClosest.y;
      nodePos->x = pposClosest.x;
      v18 = pposClosest.z;
      nodePos->y = v17;
      nodePos->z = v18;
    }
  }
  return result;
}

// File Line: 364
// RVA: 0xD6180
UFG::RoadNetworkIntersection *__fastcall UFG::RoadNetworkResource::GetClosestIntersection(
        UFG::RoadNetworkResource *this,
        UFG::qVector3 *pos,
        unsigned int roadNetworkType,
        float fMaxDistance,
        UFG::qVector3 *pposClosest,
        UFG::RoadNetworkClosestQueryCache *cache)
{
  float x; // xmm2_4
  unsigned int v7; // edi
  __int64 v8; // rbx
  __int64 v9; // r14
  UFG::RoadNetworkIntersection *v10; // r12
  unsigned int v11; // r13d
  UFG::RoadNetworkIntersection *v12; // rsi
  float v13; // xmm11_4
  float y; // xmm12_4
  float v15; // xmm7_4
  float v16; // xmm14_4
  float v17; // xmm15_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  UFG::Grid<UFG::RoadNetworkSegment> *v21; // rdx
  __int64 mNumValidNodes; // rax
  float v24; // xmm8_4
  float v25; // xmm9_4
  UFG::GridNodesArray<UFG::RoadNetworkSegment> *v26; // rbx
  UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *v27; // rbx
  UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > *mNext; // r15
  __int64 mPrev; // rbx
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
  float v42; // xmm11_4
  float v43; // xmm12_4
  unsigned int v44; // esi
  float v45; // xmm9_4
  __int64 v46; // rax
  __int64 v47; // rcx
  _QWORD *v48; // rdx
  char *v49; // rax
  char *v50; // rcx
  unsigned int v51; // edx
  __int64 v52; // rax
  UFG::RoadNetworkConnection *v53; // rcx
  UFG::qBezierPathMemImaged *Path; // rax
  float v55; // xmm2_4
  float v56; // xmm1_4
  __int64 v57; // rax
  __int64 v58; // rcx
  UFG::GridNodesArray<UFG::RoadNetworkSegment> *v59; // rbx
  float v60; // xmm10_4
  float v61; // xmm0_4
  __int64 v62; // r11
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
  UFG::qVector3 posa; // [rsp+20h] [rbp-A8h] BYREF
  UFG::RoadNetworkIntersection *v74; // [rsp+30h] [rbp-98h]
  float v75; // [rsp+38h] [rbp-90h]
  float v76; // [rsp+3Ch] [rbp-8Ch]
  float z; // [rsp+40h] [rbp-88h]
  float v78; // [rsp+44h] [rbp-84h]
  UFG::GridNodesArray<UFG::RoadNetworkSegment> *v79; // [rsp+48h] [rbp-80h]
  float t[2]; // [rsp+50h] [rbp-78h] BYREF
  __int64 v81; // [rsp+58h] [rbp-70h] BYREF
  __int64 v82; // [rsp+60h] [rbp-68h]
  UFG::qVector3 result; // [rsp+68h] [rbp-60h] BYREF
  UFG::GridNodesArray<UFG::RoadNetworkSegment> v84; // [rsp+648h] [rbp+580h] BYREF
  char v85; // [rsp+800h] [rbp+738h]
  int v86; // [rsp+808h] [rbp+740h]
  float v87; // [rsp+810h] [rbp+748h]
  float *v88; // [rsp+818h] [rbp+750h]

  x = pos->x;
  v7 = 0;
  v8 = 0i64;
  v9 = 0xFFFFFFFFi64;
  v85 = 1;
  v10 = 0i64;
  v11 = 0;
  v12 = 0i64;
  v13 = UFG::qVector3::msZero.x;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  v81 = 0i64;
  v74 = 0i64;
  v15 = FLOAT_3_4028235e38;
  v16 = FLOAT_3_4028235e38;
  v76 = UFG::qVector3::msZero.x;
  v75 = UFG::qVector3::msZero.y;
  posa.x = x;
  v17 = FLOAT_3_4028235e38;
  v19 = pos->z;
  v20 = pos->y;
  v78 = FLOAT_3_4028235e38;
  posa.y = v20;
  posa.z = v19;
  if ( v19 < -1000.0 )
  {
    v85 = 0;
    posa.z = 0.0;
  }
  v21 = (UFG::Grid<UFG::RoadNetworkSegment> *)gIntersectionsDataGrid[roadNetworkType];
  if ( !v21->mNodeCount )
    return 0i64;
  UFG::GridNodesArray<UFG::RoadNetworkSegment>::GridNodesArray<UFG::RoadNetworkSegment>(&v84, v21, x, v20);
  mNumValidNodes = v84.mNumValidNodes;
  v24 = posa.z;
  v25 = FLOAT_6_0;
  if ( v84.mNumValidNodes )
  {
    v26 = &v84;
    v82 = v84.mNumValidNodes;
    v79 = &v84;
    do
    {
      v27 = v26->mGridNodeArray[0];
      mNext = v27->mNode.mNext;
      if ( mNext != (UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > *)v27 )
      {
        while ( 1 )
        {
          mPrev = (__int64)mNext[1].mPrev;
          if ( *(_BYTE *)(mPrev + 40) )
          {
            v30 = UFG::RoadNetworkIntersection::GetRoadNetworkType((UFG::RoadNetworkIntersection *)mNext[1].mPrev);
            if ( v30 != v86 )
              goto LABEL_56;
            v31 = *(float *)(mPrev + 128);
            v32 = posa.x;
            if ( posa.x >= v31 )
              v33 = 0.0;
            else
              v33 = v31 - posa.x;
            v34 = *(float *)(mPrev + 140);
            if ( posa.x <= v34 )
              v35 = 0.0;
            else
              v35 = posa.x - v34;
            if ( v33 <= v35 )
              v33 = v35;
            v36 = *(float *)(mPrev + 132);
            v37 = posa.y;
            if ( posa.y >= v36 )
              v38 = 0.0;
            else
              v38 = v36 - posa.y;
            v39 = *(float *)(mPrev + 144);
            if ( posa.y <= v39 )
              v40 = 0.0;
            else
              v40 = posa.y - v39;
            if ( v38 <= v40 )
              v38 = v40;
            if ( (float)((float)(v38 * v38) + (float)(v33 * v33)) <= (float)(fMaxDistance * fMaxDistance) )
            {
              v41 = *(float *)(mPrev + 12);
              v42 = *(float *)(mPrev + 16);
              v43 = *(float *)(mPrev + 20);
              v44 = 0;
              t[0] = 0.0;
              v45 = FLOAT_3_4028235e38;
              if ( *(_BYTE *)(mPrev + 40) )
              {
                do
                {
                  v46 = *(_QWORD *)(mPrev + 48);
                  if ( v46 )
                    v47 = mPrev + v46 + 48;
                  else
                    v47 = 0i64;
                  v48 = (_QWORD *)(v47 + 8i64 * v44);
                  if ( *v48 )
                    v49 = (char *)v48 + *v48;
                  else
                    v49 = 0i64;
                  if ( *(_QWORD *)v49 )
                    v50 = &v49[*(_QWORD *)v49];
                  else
                    v50 = 0i64;
                  v51 = *((unsigned __int16 *)v49 + 19);
                  v52 = *((_QWORD *)v50 + 4);
                  if ( v52 )
                    v53 = (UFG::RoadNetworkConnection *)&v50[v52 + 32];
                  else
                    v53 = 0i64;
                  Path = (UFG::qBezierPathMemImaged *)UFG::qBezierPathCollectionMemImaged::GetPath(v53, v51);
                  UFG::qBezierPathMemImaged::ClosestPoint3D(Path, &result, &posa, t);
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
                    v42 = result.y;
                    v43 = result.z;
                  }
                  ++v44;
                }
                while ( v44 < *(unsigned __int8 *)(mPrev + 40) );
                fMaxDistance = v87;
                v15 = v78;
              }
              else
              {
                v24 = posa.z;
              }
              v25 = FLOAT_6_0;
              v55 = (float)((float)((float)(v37 - v42) * (float)(v37 - v42))
                          + (float)((float)(v32 - v41) * (float)(v32 - v41)))
                  + (float)((float)(v24 - v43) * (float)(v24 - v43));
              if ( v85 )
              {
                v56 = *(float *)(mPrev + 20);
                if ( v56 > v24 && COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - v56) & _xmm) > 6.0 )
                {
                  v12 = v74;
                  if ( v55 < v15 )
                  {
                    v15 = v55;
                    v76 = v41;
                    v75 = v42;
                    v81 = mPrev;
                    v78 = v55;
                    z = v43;
                  }
                  goto LABEL_58;
                }
              }
              v57 = v11++;
              v58 = 3 * v57;
              *(UFG::GridNodesArray<UFG::RoadNetworkSegment> **)&t[2 * v58 - 2] = (UFG::GridNodesArray<UFG::RoadNetworkSegment> *)mPrev;
              t[2 * v58] = v41;
              t[2 * v58 + 1] = v42;
              *((float *)&v81 + 2 * v58) = v43;
              if ( v55 >= fMaxDistance )
              {
LABEL_57:
                v12 = v74;
                goto LABEL_58;
              }
              if ( v55 >= v17 )
              {
                if ( v55 >= v16 || *(_DWORD *)(mPrev + 24) == v10->mIndex )
                  goto LABEL_57;
                v12 = (UFG::RoadNetworkIntersection *)mPrev;
                v74 = (UFG::RoadNetworkIntersection *)mPrev;
                v16 = v55;
              }
              else
              {
                v12 = v10;
                v74 = v10;
                v16 = v17;
                v10 = (UFG::RoadNetworkIntersection *)mPrev;
                v17 = v55;
                v9 = v11 - 1;
              }
            }
            else
            {
LABEL_56:
              v24 = posa.z;
              v25 = FLOAT_6_0;
            }
          }
LABEL_58:
          v59 = v79;
          mNext = mNext->mNext;
          if ( mNext == (UFG::qNode<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment> > *)v79->mGridNodeArray[0] )
          {
            mNumValidNodes = v82;
            goto LABEL_61;
          }
        }
      }
      v59 = v79;
LABEL_61:
      v26 = (UFG::GridNodesArray<UFG::RoadNetworkSegment> *)&v59->mGridNodeArray[1];
      v82 = --mNumValidNodes;
      v79 = v26;
    }
    while ( mNumValidNodes );
    v13 = v76;
    y = v75;
    v8 = v81;
  }
  if ( v85 && v11 > 1 && v12 )
  {
    v60 = (float)(UFG::RoadNetworkIntersection::GetIntersectionRadius(v10) * 2.0) + 20.0;
    v61 = (float)(UFG::RoadNetworkIntersection::GetIntersectionRadius(v12) * 2.0) + 20.0;
    if ( v60 <= v61 )
      v60 = v61;
    v62 = 0i64;
    if ( (int)v11 >= 4 )
    {
      v63 = 2;
      v64 = (float *)&v81;
      v62 = 4i64 * (((v11 - 4) >> 2) + 1);
      do
      {
        if ( v7 != (_DWORD)v9 )
        {
          v65 = t[6 * v9] - *(v64 - 2);
          if ( (float)((float)((float)(t[6 * v9 + 1] - *(v64 - 1)) * (float)(t[6 * v9 + 1] - *(v64 - 1)))
                     + (float)(v65 * v65)) < (float)(v60 * v60)
            && COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - *((float *)&v81 + 6 * v9)) & _xmm) > (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - *v64) & _xmm)
                                                                                                 + v25) )
          {
            v9 = v7;
          }
        }
        if ( v63 - 1 != (_DWORD)v9 )
        {
          v66 = t[6 * v9] - v64[4];
          if ( (float)((float)((float)(t[6 * v9 + 1] - v64[5]) * (float)(t[6 * v9 + 1] - v64[5])) + (float)(v66 * v66)) < (float)(v60 * v60)
            && COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - *((float *)&v81 + 6 * v9)) & _xmm) > (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - v64[6]) & _xmm)
                                                                                                 + v25) )
          {
            v9 = v63 - 1;
          }
        }
        if ( v63 != (_DWORD)v9 )
        {
          v67 = t[6 * v9] - v64[10];
          if ( (float)((float)((float)(t[6 * v9 + 1] - v64[11]) * (float)(t[6 * v9 + 1] - v64[11])) + (float)(v67 * v67)) < (float)(v60 * v60)
            && COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - *((float *)&v81 + 6 * v9)) & _xmm) > (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - v64[12]) & _xmm)
                                                                                                 + v25) )
          {
            v9 = v63;
          }
        }
        if ( v63 + 1 != (_DWORD)v9 )
        {
          v68 = t[6 * v9] - v64[16];
          if ( (float)((float)((float)(t[6 * v9 + 1] - v64[17]) * (float)(t[6 * v9 + 1] - v64[17])) + (float)(v68 * v68)) < (float)(v60 * v60)
            && COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - *((float *)&v81 + 6 * v9)) & _xmm) > (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - v64[18]) & _xmm)
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
      v69 = (float *)(&v81 + 3 * v62);
      do
      {
        if ( v7 != (_DWORD)v9 )
        {
          v70 = t[6 * v9] - *(v69 - 2);
          if ( (float)((float)((float)(t[6 * v9 + 1] - *(v69 - 1)) * (float)(t[6 * v9 + 1] - *(v69 - 1)))
                     + (float)(v70 * v70)) < (float)(v60 * v60)
            && COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - *((float *)&v81 + 6 * v9)) & _xmm) > (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v24 - *v69) & _xmm)
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
  v71 = v88;
  if ( (_DWORD)v9 != -1 )
  {
    v10 = *(UFG::RoadNetworkIntersection **)&t[6 * v9 - 2];
    if ( v88 )
    {
      *v88 = t[6 * v9];
      v71[1] = t[6 * v9 + 1];
      v71[2] = *((float *)&v81 + 6 * v9);
    }
  }
  if ( !v10 )
  {
    v10 = (UFG::RoadNetworkIntersection *)v8;
    if ( v71 )
    {
      v72 = z;
      *v71 = v13;
      v71[1] = y;
      v71[2] = v72;
    }
  }
  return v10;
}

// File Line: 513
// RVA: 0xDB970
__int64 __fastcall UFG::GetRoadSegmentArrayIndex(UFG::RoadNetworkResource *resource, UFG::RoadNetworkSegment *segment)
{
  unsigned int mNumSegments; // r10d
  __int64 result; // rax
  __int64 mOffset; // r9
  UFG::qOffset64<UFG::qOffset64<UFG::RoadNetworkSegment *> *> *p_mSegmentOffsetTable; // r11
  __int64 i; // r8
  char *v8; // rcx
  char *v9; // rdx
  UFG::RoadNetworkSegment *v10; // rcx

  mNumSegments = resource->mNumSegments;
  result = 0i64;
  if ( !mNumSegments )
    return 0xFFFFFFFFi64;
  mOffset = resource->mSegmentOffsetTable.mOffset;
  p_mSegmentOffsetTable = &resource->mSegmentOffsetTable;
  for ( i = 0i64; ; i += 8i64 )
  {
    v8 = mOffset ? (char *)p_mSegmentOffsetTable + mOffset : 0i64;
    v9 = &v8[i];
    v10 = *(UFG::RoadNetworkSegment **)&v8[i];
    if ( v10 )
      v10 = (UFG::RoadNetworkSegment *)((char *)v10 + (_QWORD)v9);
    if ( v10 == segment )
      break;
    result = (unsigned int)(result + 1);
    if ( (unsigned int)result >= mNumSegments )
      return 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 532
// RVA: 0xD7100
UFG::RoadNetworkSegment *__fastcall UFG::RoadNetworkResource::GetClosestSegment(
        UFG::RoadNetworkResource *this,
        UFG::qVector3 *pos,
        unsigned int *p_segment_index,
        unsigned int roadNetworkType)
{
  __int64 v5; // rsi
  float v6; // xmm11_4
  float x; // xmm13_4
  float y; // xmm14_4
  float z; // xmm15_4
  float v10; // xmm12_4
  float v11; // xmm9_4
  float v12; // xmm8_4
  float v13; // xmm7_4
  char *v14; // rbx
  unsigned int v15; // r12d
  char *v16; // r13
  unsigned int v17; // edi
  unsigned int v18; // r14d
  __int64 v19; // r15
  float v20; // xmm10_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm3_4
  float v24; // xmm6_4
  hkSeekableStreamReader *v25; // rax
  int v26; // ecx
  int v27; // xmm6_4
  int vfptr; // xmm7_4
  int vfptr_high; // xmm8_4
  _DWORD *v30; // rax
  UFG::Grid<UFG::RoadNetworkSegment> *v31; // rdx
  int v32; // xmm4_4
  UFG::GridNodesArray<UFG::RoadNetworkSegment> *v33; // rcx
  __int64 mNumValidNodes; // rdx
  UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *v35; // rcx
  __int64 mNext; // rax
  unsigned int v37; // ebx
  UFG::qPropertySet *RoadPropertySet; // rax
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
  unsigned int v49; // r14d
  unsigned int v50; // ebx
  unsigned __int64 v51; // rax
  char *v52; // rax
  char *v53; // rdi
  char *v54; // rcx
  _QWORD *v55; // rdx
  signed __int64 v56; // r9
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
  __int64 v67; // rcx
  char v68; // r9
  float v69; // xmm3_4
  __int64 v70; // rcx
  float v71; // xmm0_4
  __int64 v72; // rcx
  __int64 v73; // rax
  unsigned int v74; // r10d
  __int64 v75; // r9
  __int64 v76; // rdx
  __int64 v77; // r8
  __int64 v78; // rax
  float *v79; // rax
  char v80; // cl
  unsigned __int64 v81; // rax
  float v83; // [rsp+30h] [rbp-90h]
  int v84; // [rsp+34h] [rbp-8Ch]
  float v85; // [rsp+38h] [rbp-88h]
  float v86; // [rsp+3Ch] [rbp-84h]
  __int64 v87; // [rsp+40h] [rbp-80h]
  __int64 posa; // [rsp+48h] [rbp-78h] BYREF
  UFG::GridNodesArray<UFG::RoadNetworkSegment> *pos_8; // [rsp+50h] [rbp-70h]
  __int64 v90; // [rsp+58h] [rbp-68h]
  __int64 v91; // [rsp+60h] [rbp-60h]
  char *result; // [rsp+68h] [rbp-58h] BYREF
  UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *result_8; // [rsp+70h] [rbp-50h] BYREF
  UFG::RoadNetworkLane *nearestLane; // [rsp+78h] [rbp-48h] BYREF
  unsigned __int64 v95; // [rsp+80h] [rbp-40h]
  __int64 v96; // [rsp+88h] [rbp-38h]
  UFG::GridNodesArray<UFG::RoadNetworkSegment> v97; // [rsp+90h] [rbp-30h] BYREF
  __int64 v98; // [rsp+250h] [rbp+190h]
  char v99; // [rsp+258h] [rbp+198h]
  _DWORD *v100; // [rsp+260h] [rbp+1A0h]
  int v101; // [rsp+268h] [rbp+1A8h]
  _DWORD *v102; // [rsp+270h] [rbp+1B0h]

  v96 = -2i64;
  v5 = 0i64;
  posa = 0i64;
  v6 = FLOAT_3_4028235e38;
  x = UFG::qVector3::msZero.x;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  v10 = FLOAT_3_4028235e38;
  v11 = UFG::qVector3::msZero.x;
  v86 = UFG::qVector3::msZero.x;
  v12 = UFG::qVector3::msZero.y;
  v85 = UFG::qVector3::msZero.y;
  v13 = UFG::qVector3::msZero.z;
  v83 = UFG::qVector3::msZero.z;
  v14 = 0i64;
  result = 0i64;
  v15 = 0;
  v91 = 0i64;
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
  *(float *)&posa = pos->x;
  *((float *)&posa + 1) = v22;
  *(float *)&pos_8 = v23;
  v99 = 1;
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
      vfptr = (int)v25[1].vfptr;
      vfptr_high = HIDWORD(v25[1].vfptr);
      if ( p_segment_index )
        *v100 = UFG::GetRoadSegmentArrayIndex(this, *(UFG::RoadNetworkSegment **)&v25[1].m_memSizeAndFlags);
      v30 = v102;
      if ( v102 )
      {
        *v102 = v27;
        v30[1] = vfptr;
        v30[2] = vfptr_high;
      }
      goto LABEL_130;
    }
  }
  else
  {
    v99 = 0;
    LODWORD(pos_8) = 0;
  }
LABEL_13:
  v95 = 8i64 * roadNetworkType;
  v31 = gSegmentsDataGrid[v95 / 8];
  if ( v31 && v31->mNodeCount )
  {
    UFG::GridNodesArray<UFG::RoadNetworkSegment>::GridNodesArray<UFG::RoadNetworkSegment>(&v97, v31, v21, v22);
    v32 = _xmm;
    if ( v97.mNumValidNodes )
    {
      v33 = &v97;
      pos_8 = &v97;
      mNumValidNodes = v97.mNumValidNodes;
      v90 = v97.mNumValidNodes;
      do
      {
        v35 = v33->mGridNodeArray[0];
        result_8 = v35;
        mNext = (__int64)v35->mNode.mNext;
        v90 = mNext;
        if ( (UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *)mNext != v35 )
        {
          while ( 1 )
          {
            v19 = *(_QWORD *)(mNext + 16);
            if ( !*(_BYTE *)(v19 + 40) )
              break;
            if ( *(_QWORD *)(v19 + 104) )
            {
              v37 = *(_DWORD *)(v19 + 136);
            }
            else
            {
              RoadPropertySet = UFG::RoadNetworkSegment::GetRoadPropertySet(*(UFG::RoadNetworkSegment **)(mNext + 16));
              v37 = 0;
              if ( RoadPropertySet )
              {
                v39 = UFG::qPropertySet::Get<unsigned long>(RoadPropertySet, &qSymbol_RoadNetworkType, DEPTH_RECURSE);
                if ( v39 )
                  v37 = *v39;
              }
              mNext = v90;
              v35 = result_8;
            }
            if ( v37 != v101 )
              break;
            v40 = *(float *)(v19 + 140);
            if ( *(float *)&posa >= v40 )
              v41 = 0.0;
            else
              v41 = v40 - *(float *)&posa;
            v42 = *(float *)(v19 + 152);
            if ( *(float *)&posa <= v42 )
              v43 = 0.0;
            else
              v43 = *(float *)&posa - v42;
            if ( v41 <= v43 )
              v41 = v43;
            v44 = *(float *)(v19 + 144);
            if ( *((float *)&posa + 1) >= v44 )
              v45 = 0.0;
            else
              v45 = v44 - *((float *)&posa + 1);
            v46 = *(float *)(v19 + 156);
            if ( *((float *)&posa + 1) <= v46 )
              v47 = 0.0;
            else
              v47 = *((float *)&posa + 1) - v46;
            if ( v45 <= v47 )
              v45 = v47;
            if ( (float)((float)(v45 * v45) + (float)(v41 * v41)) > v20 )
              break;
            UFG::RoadNetworkNode::GetNearestPos(
              (UFG::RoadNetworkNode *)v19,
              (UFG::qVector3 *)&result,
              (UFG::qVector3 *)&posa,
              &nearestLane,
              (float *)&result_8 + 1);
            v13 = *(float *)&result_8;
            v12 = *((float *)&result + 1);
            v11 = *(float *)&result;
            v48 = (float)((float)((float)(*((float *)&posa + 1) - *((float *)&result + 1))
                                * (float)(*((float *)&posa + 1) - *((float *)&result + 1)))
                        + (float)((float)(*(float *)&posa - *(float *)&result)
                                * (float)(*(float *)&posa - *(float *)&result)))
                + (float)((float)(*(float *)&pos_8 - *(float *)&result_8)
                        * (float)(*(float *)&pos_8 - *(float *)&result_8));
            if ( v99
              && *(float *)&result_8 > *(float *)&pos_8
              && COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&pos_8 - *(float *)&result_8) & _xmm) > 6.0 )
            {
              mNext = v90;
              v18 = v84;
              v35 = result_8;
              if ( v48 >= v10 )
              {
                v11 = v86;
                v12 = v85;
                v13 = v83;
              }
              else
              {
                v10 = (float)((float)((float)(*((float *)&posa + 1) - *((float *)&result + 1))
                                    * (float)(*((float *)&posa + 1) - *((float *)&result + 1)))
                            + (float)((float)(*(float *)&posa - *(float *)&result)
                                    * (float)(*(float *)&posa - *(float *)&result)))
                    + (float)((float)(*(float *)&pos_8 - *(float *)&result_8)
                            * (float)(*(float *)&pos_8 - *(float *)&result_8));
                v91 = v19;
                v85 = *((float *)&result + 1);
                v86 = *(float *)&result;
                v83 = *(float *)&result_8;
              }
              goto LABEL_91;
            }
            v49 = v15 + 1;
            if ( v15 + 1 > HIDWORD(v91) )
            {
              v50 = 1;
              if ( HIDWORD(v91) )
                v50 = 2 * HIDWORD(v91);
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
                v54 = result;
                if ( result )
                {
                  if ( v15 )
                  {
                    v55 = v52;
                    v56 = result - v52;
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
                result = v53;
                HIDWORD(v91) = v50;
                v17 = (unsigned int)nearestLane;
              }
            }
            LODWORD(v91) = v15 + 1;
            *(_QWORD *)&result[8 * v15] = v19;
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
            v15 = v91;
            if ( v48 >= v6 )
            {
              v5 = posa;
              v11 = v86;
              v12 = v85;
              v13 = v83;
              v18 = v84;
              v35 = result_8;
              if ( v48 >= v20 )
              {
                mNext = v90;
                goto LABEL_91;
              }
              mNext = v90;
              if ( *(_DWORD *)(v19 + 24) == *(_DWORD *)(posa + 24) )
                goto LABEL_91;
              v87 = v19;
              v20 = v48;
            }
            else
            {
              v87 = posa;
              v20 = v6;
              v5 = v19;
              posa = v19;
              v6 = v48;
              v18 = v49 - 1;
              v84 = v18;
              x = v11;
              y = v12;
              z = v13;
              v11 = v86;
              v12 = v85;
              v13 = v83;
              mNext = v90;
              v19 = v87;
              v35 = result_8;
            }
LABEL_92:
            mNext = *(_QWORD *)(mNext + 8);
            v90 = mNext;
            if ( (UFG::qList<UFG::qPointerNode<UFG::RoadNetworkSegment>,UFG::qPointerNode<UFG::RoadNetworkSegment>,1,0> *)mNext == v35 )
            {
              mNumValidNodes = v90;
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
        v33 = (UFG::GridNodesArray<UFG::RoadNetworkSegment> *)&pos_8->mGridNodeArray[1];
        pos_8 = (UFG::GridNodesArray<UFG::RoadNetworkSegment> *)((char *)pos_8 + 8);
        v90 = --mNumValidNodes;
      }
      while ( mNumValidNodes );
      v24 = FLOAT_4_0;
      v32 = _xmm;
      v14 = result;
    }
    v68 = v99;
    if ( v99 && v15 > 1 && v19 )
    {
      v69 = (float)((float)*(unsigned __int8 *)(v5 + 40) * v24) + 20.0;
      if ( v69 <= (float)((float)((float)*(unsigned __int8 *)(v19 + 40) * v24) + 20.0) )
        v69 = (float)((float)*(unsigned __int8 *)(v19 + 40) * v24) + 20.0;
      v70 = 0i64;
      do
      {
        if ( (_DWORD)v70 != v18 )
        {
          v71 = *(float *)&v16[12 * v18 + 4] - *(float *)&v16[12 * v70 + 4];
          if ( (float)((float)((float)(*(float *)&v16[12 * v18] - *(float *)&v16[12 * v70])
                             * (float)(*(float *)&v16[12 * v18] - *(float *)&v16[12 * v70]))
                     + (float)(v71 * v71)) < (float)(v69 * v69)
            && COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&pos_8 - *(float *)&v16[12 * v18 + 8]) & v32) > (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(*(float *)&pos_8 - *(float *)&v16[12 * v70 + 8]) & v32) + 6.0) )
          {
            v18 = v70;
          }
        }
        v70 = (unsigned int)(v70 + 1);
      }
      while ( (unsigned int)v70 < v15 );
    }
    if ( v18 != -1 )
    {
      v5 = *(_QWORD *)&v14[8 * v18];
      x = *(float *)&v16[12 * v18];
      y = *(float *)&v16[12 * v18 + 4];
      z = *(float *)&v16[12 * v18 + 8];
    }
    if ( !v5 )
    {
      v5 = v91;
      x = v11;
      y = v12;
      z = v13;
    }
    if ( v100 )
    {
      v72 = 0i64;
      v73 = v98;
      v74 = *(_DWORD *)(v98 + 104);
      if ( v74 )
      {
        v75 = *(_QWORD *)(v98 + 112);
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
          v73 = v98;
          if ( (unsigned int)v72 >= v74 )
            goto LABEL_122;
        }
      }
      else
      {
LABEL_122:
        LODWORD(v72) = -1;
      }
      *v100 = v72;
      v68 = v99;
    }
    v79 = (float *)v102;
    if ( v102 )
    {
      *(float *)v102 = x;
      v79[1] = y;
      v79[2] = z;
    }
    if ( v5 && v68 )
    {
      v80 = UFG::ClosestSegmentCache::mCircularIndex;
      v81 = 32 * (v95 + UFG::ClosestSegmentCache::mCircularIndex);
      (&UFG::ClosestSegmentCache::mNodeCacheItem.vfptr)[v81 / 8] = (hkBaseObjectVtbl *)posa;
      *(_DWORD *)((char *)&UFG::ClosestSegmentCache::mNodeCacheItem.m_memSizeAndFlags + v81) = (_DWORD)pos_8;
      *(_QWORD *)((char *)&UFG::ClosestSegmentCache::mNodeCacheItem + v81 + 24) = v5;
      *(float *)((char *)&UFG::ClosestSegmentCache::mNodeCacheItem.m_referenceCount + v81 + 2) = x;
      *(float *)((char *)&UFG::ClosestSegmentCache::mNodeCacheItem + v81 + 16) = y;
      *(float *)((char *)&UFG::ClosestSegmentCache::mNodeCacheItem + v81 + 20) = z;
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
UFG::RoadNetworkSubSegment *__fastcall UFG::RoadNetworkResource::GetClosestSubSegment(
        UFG::RoadNetworkResource *this,
        UFG::qVector3 *pos,
        unsigned int roadNetworkType)
{
  float v3; // xmm7_4
  float z; // xmm8_4
  char v6; // r12
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *v7; // r15
  float x; // xmm11_4
  float y; // xmm12_4
  UFG::Grid<UFG::RoadNetworkSegment> *v10; // rdi
  float mGridSizeInv; // xmm2_4
  __int64 mXDim; // r11
  int v14; // r10d
  int v15; // ebx
  int mYDim; // eax
  int v17; // r8d
  int v18; // ecx
  unsigned int v19; // edx
  __int64 v20; // rsi
  __int64 v21; // r9
  __int64 v22; // r11
  __int64 v23; // rcx
  __int64 v24; // r8
  __int64 *v25; // rax
  __int64 v26; // rcx
  __int64 v27; // rax
  __int64 v28; // r14
  UFG::RoadNetworkSegment *v29; // rsi
  UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *mNext; // rbx
  float v31; // xmm6_4
  unsigned int mValue; // edi
  UFG::qPropertySet *RoadPropertySet; // rax
  unsigned int *v34; // rax
  __int64 v35; // [rsp+20h] [rbp-188h]
  __int64 v36[25]; // [rsp+30h] [rbp-178h] BYREF
  int v37; // [rsp+F8h] [rbp-B0h]
  __int64 *v38; // [rsp+1B8h] [rbp+10h]
  __int64 v39; // [rsp+1C8h] [rbp+20h]

  v3 = FLOAT_3_4028235e38;
  z = pos->z;
  v6 = 1;
  v7 = 0i64;
  x = pos->x;
  y = pos->y;
  if ( z < -1000.0 )
  {
    v6 = 0;
    z = 0.0;
  }
  v10 = gSegmentsDataGrid[roadNetworkType];
  if ( !v10->mNodeCount )
    return 0i64;
  mGridSizeInv = v10->mGridSizeInv;
  mXDim = v10->mXDim;
  v14 = (int)(float)((float)((float)(x - 100.0) - v10->mXMin) * mGridSizeInv);
  if ( v14 < 0 )
    v14 = 0;
  v15 = (int)(float)((float)((float)(x + 100.0) - v10->mXMin) * mGridSizeInv);
  if ( v15 >= (int)mXDim )
    v15 = mXDim - 1;
  mYDim = v10->mYDim;
  v17 = (int)(float)((float)((float)(y - 100.0) - v10->mYMin) * mGridSizeInv);
  if ( v17 < 0 )
    v17 = 0;
  v18 = (int)(float)((float)((float)(y + 100.0) - v10->mYMin) * mGridSizeInv);
  if ( v18 >= mYDim )
    v18 = mYDim - 1;
  v19 = 0;
  v37 = 0;
  if ( v17 <= v18 )
  {
    v20 = 16 * mXDim;
    v21 = 16i64 * (v14 + v17 * (int)mXDim);
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
            v19 = ++v37;
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
          mNext = v29->mSubSegmentCollection.mNode.mNext;
          if ( mNext != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&v29->mSubSegmentCollection )
          {
            do
            {
              v31 = (float)((float)((float)(*((float *)&mNext[1].mNext + 1) - y)
                                  * (float)(*((float *)&mNext[1].mNext + 1) - y))
                          + (float)((float)(*(float *)&mNext[1].mNext - x) * (float)(*(float *)&mNext[1].mNext - x)))
                  + (float)((float)(*(float *)&mNext[2].mPrev - z) * (float)(*(float *)&mNext[2].mPrev - z));
              if ( v31 <= 10000.0
                && (!v6 || COERCE_FLOAT(COERCE_UNSIGNED_INT(z - *(float *)&mNext[2].mPrev) & _xmm) <= 6.0) )
              {
                if ( v29->mpPropertySetCached )
                {
                  mValue = v29->mRoadNetworkType.mValue;
                }
                else
                {
                  RoadPropertySet = UFG::RoadNetworkSegment::GetRoadPropertySet(v29);
                  mValue = 0;
                  if ( RoadPropertySet )
                  {
                    v34 = UFG::qPropertySet::Get<unsigned long>(
                            RoadPropertySet,
                            &qSymbol_RoadNetworkType,
                            DEPTH_RECURSE);
                    if ( v34 )
                      mValue = *v34;
                  }
                }
                if ( mValue == roadNetworkType && v31 < v3 )
                {
                  v7 = mNext;
                  v3 = v31;
                }
              }
              mNext = mNext->mNext;
            }
            while ( mNext != (UFG::qNode<UFG::RoadNetworkSubSegment,UFG::RoadNetworkSubSegment> *)&v29->mSubSegmentCollection );
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
  return (UFG::RoadNetworkSubSegment *)v7;
}

// File Line: 765
// RVA: 0xD9740
void __fastcall UFG::RoadNetworkResource::GetLanesIntersectingLine2D(
        UFG::RoadNetworkResource *this,
        UFG::qVector3 *v1,
        UFG::qVector3 *v2,
        UFG::qArray<unsigned long,0> *aIntersections,
        UFG::qArray<unsigned long,0> *aLanes,
        float fMaxIntersectionDistance)
{
  unsigned int mNumIntersections; // ebx
  float v9; // xmm2_4
  float v10; // xmm3_4
  UFG::RoadNetworkIntersection *ClosestIntersection; // rax
  UFG::RoadNetworkIntersection *v13; // rbx
  UFG::RoadNetworkGate *ClosestGate; // rax
  __int64 v15; // rdx
  UFG::RoadNetworkGate *v16; // r8
  __int64 mOffset; // rax
  char *v18; // rcx
  __int64 v19; // rax
  char *v20; // rdx
  char *v21; // rcx
  __int64 v22; // rdx
  __int64 v23; // rax
  char *v24; // rcx
  __int64 v25; // rax
  char *v26; // rdx
  char *v27; // rbp
  __int64 size; // r13
  int mIndex; // r12d
  unsigned int capacity; // ebx
  unsigned int v31; // edi
  unsigned int v32; // ebx
  unsigned __int64 v33; // rax
  char *v34; // rax
  int *v35; // r15
  __int64 j; // r9
  int *p; // rax
  int v38; // r12d
  __int64 v39; // rbp
  unsigned int v40; // ebx
  unsigned int v41; // edi
  unsigned int v42; // ebx
  unsigned __int64 v43; // rax
  char *v44; // rax
  int *v45; // r15
  __int64 k; // r9
  int *v47; // rax
  __int64 v48; // rdx
  __int64 v49; // rax
  char *v50; // rcx
  __int64 v51; // rax
  char *v52; // rdx
  char *v53; // rcx
  __int64 v54; // rdx
  __int64 v55; // rax
  char *v56; // rcx
  __int64 v57; // rax
  char *v58; // rdx
  char *v59; // rbp
  __int64 v60; // r13
  int v61; // r12d
  unsigned int v62; // ebx
  unsigned int v63; // edi
  unsigned int v64; // ebx
  unsigned __int64 v65; // rax
  char *v66; // rax
  int *v67; // r15
  __int64 n; // r9
  int *v69; // rax
  int v70; // r12d
  __int64 v71; // rbp
  unsigned int v72; // ebx
  unsigned int v73; // edi
  unsigned int v74; // ebx
  unsigned __int64 v75; // rax
  char *v76; // rax
  int *v77; // r15
  __int64 ii; // r9
  int *v79; // rax
  UFG::qVector3 pos; // [rsp+30h] [rbp-58h] BYREF
  int i; // [rsp+90h] [rbp+8h]
  int m; // [rsp+90h] [rbp+8h]
  UFG::RoadNetworkIntersection *v83; // [rsp+98h] [rbp+10h]
  UFG::RoadNetworkGate *v84; // [rsp+A0h] [rbp+18h]
  char *v85; // [rsp+A8h] [rbp+20h]
  char *v86; // [rsp+A8h] [rbp+20h]
  int aLanesa; // [rsp+B0h] [rbp+28h]
  int aLanesb; // [rsp+B0h] [rbp+28h]

  mNumIntersections = this->mNumIntersections;
  v9 = (float)(v1->y + v2->y) * 0.5;
  v10 = v1->z + v2->z;
  pos.x = (float)(v1->x + v2->x) * 0.5;
  pos.y = v9;
  pos.z = v10 * 0.5;
  if ( mNumIntersections > aIntersections->capacity )
    UFG::qArray<long,0>::Reallocate(aIntersections, mNumIntersections, "RoadNetworkResource");
  if ( 4 * mNumIntersections > aLanes->capacity )
    UFG::qArray<long,0>::Reallocate(aLanes, 4 * mNumIntersections, "RoadNetworkResource");
  ClosestIntersection = UFG::RoadNetworkResource::GetClosestIntersection(
                          this,
                          &pos,
                          0,
                          fMaxIntersectionDistance,
                          0i64,
                          0i64);
  v13 = ClosestIntersection;
  v83 = ClosestIntersection;
  if ( ClosestIntersection )
  {
    ClosestGate = UFG::RoadNetworkIntersection::GetClosestGate(ClosestIntersection, &pos);
    v15 = 0i64;
    v16 = ClosestGate;
    v84 = ClosestGate;
    for ( i = 0; (unsigned int)v15 < v16->mNumIncomingConnections; i = v15 )
    {
      mOffset = v16->mIncomingConnection.mOffset;
      if ( mOffset )
        v18 = (char *)&v16->mIncomingConnection + mOffset;
      else
        v18 = 0i64;
      v19 = *(_QWORD *)&v18[8 * v15];
      v20 = &v18[8 * v15];
      if ( v19 )
      {
        v21 = &v20[v19];
        v85 = &v20[v19];
        if ( &v20[v19] )
        {
          v22 = 0i64;
          aLanesa = 0;
          if ( *(_DWORD *)v21 )
          {
            do
            {
              v23 = *((_QWORD *)v21 + 1);
              if ( v23 )
                v24 = &v21[v23 + 8];
              else
                v24 = 0i64;
              v25 = *(_QWORD *)&v24[8 * v22];
              v26 = &v24[8 * v22];
              if ( v25 )
                v27 = &v26[v25];
              else
                v27 = 0i64;
              if ( (v27[44] & 2) != 0 )
              {
                size = aIntersections->size;
                mIndex = v13->mIndex;
                capacity = aIntersections->capacity;
                v31 = size + 1;
                if ( (int)size + 1 > capacity )
                {
                  if ( capacity )
                    v32 = 2 * capacity;
                  else
                    v32 = 1;
                  for ( ; v32 < v31; v32 *= 2 )
                    ;
                  if ( v32 <= 4 )
                    v32 = 4;
                  if ( v32 - v31 > 0x10000 )
                    v32 = size + 65537;
                  if ( v32 != (_DWORD)size )
                  {
                    v33 = 4i64 * v32;
                    if ( !is_mul_ok(v32, 4ui64) )
                      v33 = -1i64;
                    v34 = UFG::qMalloc(v33, "qArray.Add.Intersection", 0i64);
                    v35 = (int *)v34;
                    if ( aIntersections->p )
                    {
                      for ( j = 0i64; (unsigned int)j < aIntersections->size; j = (unsigned int)(j + 1) )
                        *(_DWORD *)&v34[4 * j] = aIntersections->p[j];
                      operator delete[](aIntersections->p);
                    }
                    aIntersections->p = (unsigned int *)v35;
                    aIntersections->capacity = v32;
                  }
                }
                p = (int *)aIntersections->p;
                aIntersections->size = v31;
                p[size] = mIndex;
                v38 = *((unsigned __int16 *)v27 + 18);
                v39 = aLanes->size;
                v40 = aLanes->capacity;
                v41 = v39 + 1;
                if ( (int)v39 + 1 > v40 )
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
                    if ( aLanes->p )
                    {
                      for ( k = 0i64; (unsigned int)k < aLanes->size; k = (unsigned int)(k + 1) )
                        *(_DWORD *)&v44[4 * k] = aLanes->p[k];
                      operator delete[](aLanes->p);
                    }
                    aLanes->p = (unsigned int *)v45;
                    aLanes->capacity = v42;
                  }
                }
                v47 = (int *)aLanes->p;
                v13 = v83;
                aLanes->size = v41;
                v47[v39] = v38;
              }
              v21 = v85;
              v22 = (unsigned int)(aLanesa + 1);
              aLanesa = v22;
            }
            while ( (unsigned int)v22 < *(_DWORD *)v85 );
            v16 = v84;
          }
        }
      }
      v15 = (unsigned int)(i + 1);
    }
    v48 = 0i64;
    for ( m = 0; (unsigned int)v48 < v16->mNumOutgoingConnections; m = v48 )
    {
      v49 = v16->mOutgoingConnection.mOffset;
      if ( v49 )
        v50 = (char *)&v16->mOutgoingConnection + v49;
      else
        v50 = 0i64;
      v51 = *(_QWORD *)&v50[8 * v48];
      v52 = &v50[8 * v48];
      if ( v51 )
      {
        v53 = &v52[v51];
        v86 = &v52[v51];
        if ( &v52[v51] )
        {
          v54 = 0i64;
          aLanesb = 0;
          if ( *(_DWORD *)v53 )
          {
            do
            {
              v55 = *((_QWORD *)v53 + 1);
              if ( v55 )
                v56 = &v53[v55 + 8];
              else
                v56 = 0i64;
              v57 = *(_QWORD *)&v56[8 * v54];
              v58 = &v56[8 * v54];
              if ( v57 )
                v59 = &v58[v57];
              else
                v59 = 0i64;
              if ( (v59[44] & 2) != 0 )
              {
                v60 = aIntersections->size;
                v61 = v13->mIndex;
                v62 = aIntersections->capacity;
                v63 = v60 + 1;
                if ( (int)v60 + 1 > v62 )
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
                    if ( aIntersections->p )
                    {
                      for ( n = 0i64; (unsigned int)n < aIntersections->size; n = (unsigned int)(n + 1) )
                        *(_DWORD *)&v66[4 * n] = aIntersections->p[n];
                      operator delete[](aIntersections->p);
                    }
                    aIntersections->p = (unsigned int *)v67;
                    aIntersections->capacity = v64;
                  }
                }
                v69 = (int *)aIntersections->p;
                aIntersections->size = v63;
                v69[v60] = v61;
                v70 = *((unsigned __int16 *)v59 + 18);
                v71 = aLanes->size;
                v72 = aLanes->capacity;
                v73 = v71 + 1;
                if ( (int)v71 + 1 > v72 )
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
                    if ( aLanes->p )
                    {
                      for ( ii = 0i64; (unsigned int)ii < aLanes->size; ii = (unsigned int)(ii + 1) )
                        *(_DWORD *)&v76[4 * ii] = aLanes->p[ii];
                      operator delete[](aLanes->p);
                    }
                    aLanes->p = (unsigned int *)v77;
                    aLanes->capacity = v74;
                  }
                }
                v79 = (int *)aLanes->p;
                aLanes->size = v73;
                v79[v71] = v70;
              }
              v53 = v86;
              v13 = v83;
              v54 = (unsigned int)(aLanesb + 1);
              aLanesb = v54;
            }
            while ( (unsigned int)v54 < *(_DWORD *)v86 );
            v16 = v84;
          }
        }
      }
      v13 = v83;
      v48 = (unsigned int)(m + 1);
    }
  }
}

