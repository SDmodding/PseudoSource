// File Line: 16
// RVA: 0xC25F40
void __fastcall hkaiPath::setDistances(hkaiPath *this)
{
  int v1; // er8
  signed __int64 v2; // rdx
  hkaiPath::PathPoint *v3; // rax
  __m128 v4; // xmm1
  __m128 v5; // xmm1
  __m128 v6; // xmm2
  __m128 v7; // xmm1

  v1 = 1;
  this->m_points.m_data->m_position = (hkVector4f)_mm_srli_si128(
                                                    _mm_slli_si128(
                                                      _mm_load_si128((const __m128i *)this->m_points.m_data),
                                                      4),
                                                    4);
  if ( this->m_points.m_size > 1 )
  {
    v2 = 1i64;
    do
    {
      v3 = this->m_points.m_data;
      ++v1;
      ++v2;
      v4 = _mm_sub_ps(v3[v2 - 2].m_position.m_quad, v3[v2 - 1].m_position.m_quad);
      v5 = _mm_mul_ps(v4, v4);
      v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
      v7 = _mm_rsqrt_ps(v6);
      v3[v2 - 1].m_position.m_quad = _mm_shuffle_ps(
                                       v3[v2 - 1].m_position.m_quad,
                                       _mm_unpackhi_ps(
                                         v3[v2 - 1].m_position.m_quad,
                                         _mm_add_ps(
                                           _mm_shuffle_ps(
                                             v3[v2 - 2].m_position.m_quad,
                                             v3[v2 - 2].m_position.m_quad,
                                             255),
                                           _mm_andnot_ps(
                                             _mm_cmpleps(v6, (__m128)0i64),
                                             _mm_mul_ps(
                                               _mm_mul_ps(
                                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v7, v6), v7)),
                                                 _mm_mul_ps(*(__m128 *)_xmm, v7)),
                                               v6)))),
                                       196);
    }
    while ( v1 < this->m_points.m_size );
  }
}

// File Line: 30
// RVA: 0xC26030
int __fastcall hkaiPathUtil::getNumEdgesInPath(hkaiNavMeshAStarCommand *command)
{
  return hkaiPathUtil::_getPathLength(command->m_edgesOut, command->m_maxEdgesOut);
}

// File Line: 35
// RVA: 0xC26050
int __fastcall hkaiPathUtil::getNumCellsInPath(hkaiNavVolumeAStarCommand *command)
{
  return hkaiPathUtil::_getPathLength(command->m_cellsOut, command->m_maxCellsOut);
}

// File Line: 40
// RVA: 0xC26070
int __fastcall hkaiPathUtil::getNumPointsInPath(hkaiNavMeshAStarCommand *command)
{
  return hkaiPathUtil::_getNumPathPoints(command->m_pointsOut, command->m_maxPointsOut);
}

// File Line: 45
// RVA: 0xC26090
int __fastcall hkaiPathUtil::getNumPointsInPath(hkaiNavVolumeAStarCommand *command)
{
  return hkaiPathUtil::_getNumPathPoints(command->m_pointsOut, command->m_maxPointsOut);
}

// File Line: 50
// RVA: 0xC260B0
__int64 __fastcall hkaiPathUtil::_getPathLength(const unsigned int *output, __int64 maxOutputLength)
{
  const unsigned int *v2; // r8
  __int64 result; // rax
  __int64 i; // rcx

  v2 = output;
  if ( !output )
    return 0i64;
  result = 0i64;
  maxOutputLength = (signed int)maxOutputLength;
  for ( i = 0i64; i < maxOutputLength; result = (unsigned int)(result + 1) )
  {
    if ( v2[i] == -1 )
      break;
    ++i;
  }
  return result;
}

// File Line: 68
// RVA: 0xC260E0
__int64 __fastcall hkaiPathUtil::_getNumPathPoints(hkaiPath::PathPoint *path, int maxPathLength)
{
  __int64 v2; // r8
  __int64 result; // rax
  __int64 v4; // rdx
  unsigned int *v5; // rcx

  v2 = maxPathLength;
  if ( !path )
    return 0i64;
  result = 0i64;
  v4 = 0i64;
  if ( v2 > 0 )
  {
    v5 = &path->m_userEdgeData;
    do
    {
      if ( !*((_BYTE *)v5 + 8) && *v5 == 0x80000000 )
        break;
      ++v4;
      result = (unsigned int)(result + 1);
      v5 += 12;
    }
    while ( v4 < v2 );
  }
  return result;
}

// File Line: 86
// RVA: 0xC26120
void __fastcall hkaiPathUtil::transformPathPositionsSectionLocalToWorld(hkaiStreamingCollection *collection, hkaiPath *pathIn, hkArray<hkaiPath::PathPoint,hkContainerTempAllocator> *pointsOut, int startIndex)
{
  signed __int64 v4; // rbp
  signed __int64 v5; // rsi
  hkArray<hkaiPath::PathPoint,hkContainerTempAllocator> *v6; // rbx
  hkaiPath *v7; // r14
  hkaiStreamingCollection *v8; // rdi
  int v9; // eax
  int v10; // er9
  int v11; // eax
  signed __int64 v12; // r8
  signed __int64 v13; // r9
  hkaiPath::PathPoint *v14; // rdx
  __int64 v15; // rax
  hkVector4f *v16; // rcx
  __m128 v17; // xmm1
  hkaiNavMeshInstance *v18; // rax
  hkVector4f *v19; // rax
  __m128 v20; // xmm2
  hkVector4f *v21; // rcx
  hkResult result; // [rsp+68h] [rbp+20h]

  v4 = pathIn->m_points.m_size;
  v5 = startIndex;
  v6 = pointsOut;
  v7 = pathIn;
  v8 = collection;
  if ( startIndex < (signed int)v4 )
  {
    v9 = pointsOut->m_capacityAndFlags & 0x3FFFFFFF;
    v10 = v4 - v5;
    if ( v9 < (signed int)v4 - (signed int)v5 )
    {
      v11 = 2 * v9;
      if ( v10 < v11 )
        v10 = v11;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, pointsOut, v10, 48);
    }
    if ( v5 < v4 )
    {
      v12 = v5;
      v13 = v4 - v5;
      do
      {
        v14 = &v7->m_points.m_data[v12];
        v15 = v14->m_sectionId;
        if ( (_DWORD)v15 == -1 )
        {
          v16 = &v6->m_data[v6->m_size].m_position;
          if ( v16 )
          {
            *v16 = v14->m_position;
            v16[1] = v14->m_normal;
            v16[2] = *(hkVector4f *)&v14->m_userEdgeData;
          }
          ++v6->m_size;
        }
        else
        {
          if ( (signed int)v15 < v8->m_instances.m_size && (v18 = v8->m_instances.m_data[v15].m_instancePtr) != 0i64 )
            v19 = &v18->m_referenceFrame.m_transform.m_rotation.m_col0;
          else
            v19 = &transform;
          v17 = v14->m_position.m_quad;
          v20 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), v19[1].m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v19->m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), v19[2].m_quad)),
                  v19[3].m_quad);
          v21 = &v6->m_data[v6->m_size].m_position;
          if ( v21 )
          {
            *v21 = v14->m_position;
            v21[1] = v14->m_normal;
            v21[2] = *(hkVector4f *)&v14->m_userEdgeData;
          }
          v6->m_data[++v6->m_size - 1].m_position.m_quad = v20;
        }
        ++v12;
        --v13;
      }
      while ( v13 );
    }
  }
}

// File Line: 118
// RVA: 0xC26290
void __fastcall hkaiPathUtil::transformPathSectionLocalToWorld(hkaiStreamingCollection *collection, hkaiPath *pathIn, hkaiPath *pathOut)
{
  int v3; // esi
  hkaiPath *v4; // r15
  int v5; // ebp
  hkaiPath *v6; // r14
  int v7; // eax
  hkaiStreamingCollection *v8; // rdi
  int v9; // eax
  int v10; // er9
  hkaiPath::PathPoint *v11; // rcx
  signed __int64 v12; // rax
  char *v13; // rdx
  __int64 v14; // r8
  __int128 v15; // xmm0
  char *v16; // rdx
  __int64 v17; // rcx
  signed __int64 v18; // r8
  __int64 v19; // r9
  __int64 v20; // r8
  hkaiPath::PathPoint *v21; // rdx
  __int64 v22; // rax
  hkaiNavMeshInstance *v23; // rax
  hkVector4f *v24; // rax
  __m128 v25; // xmm3
  hkResult result; // [rsp+58h] [rbp+10h]

  v3 = pathIn->m_points.m_size;
  v4 = pathOut;
  v5 = pathIn->m_points.m_size;
  v6 = pathIn;
  if ( v3 > pathOut->m_points.m_size )
    v5 = pathOut->m_points.m_size;
  v7 = pathOut->m_points.m_capacityAndFlags & 0x3FFFFFFF;
  v8 = collection;
  if ( v7 < v3 )
  {
    v9 = 2 * v7;
    v10 = pathIn->m_points.m_size;
    if ( v3 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &pathOut->m_points,
      v10,
      48);
  }
  v11 = v4->m_points.m_data;
  if ( v5 > 0 )
  {
    v12 = (signed __int64)&v11->m_normal;
    v13 = (char *)((char *)v6->m_points.m_data - (char *)v11);
    v14 = v5;
    do
    {
      v15 = *(_OWORD *)&v13[v12 - 16];
      v12 += 48i64;
      *(_OWORD *)(v12 - 64) = v15;
      *(_OWORD *)(v12 - 48) = *(_OWORD *)&v13[v12 - 48];
      *(_DWORD *)(v12 - 32) = *(_DWORD *)&v13[v12 - 32];
      *(_DWORD *)(v12 - 28) = *(_DWORD *)&v13[v12 - 28];
      *(_BYTE *)(v12 - 24) = v13[v12 - 24];
      --v14;
    }
    while ( v14 );
  }
  v16 = (char *)&v4->m_points.m_data[v5];
  v17 = v3 - v5;
  if ( v3 - v5 > 0 )
  {
    v18 = (char *)&v6->m_points.m_data[v5] - v16;
    do
    {
      if ( v16 )
      {
        *(_OWORD *)v16 = *(_OWORD *)&v16[v18];
        *((_OWORD *)v16 + 1) = *(_OWORD *)&v16[v18 + 16];
        *((_OWORD *)v16 + 2) = *(_OWORD *)&v16[v18 + 32];
      }
      v16 += 48;
      --v17;
    }
    while ( v17 );
  }
  v4->m_points.m_size = v3;
  v19 = v4->m_points.m_size;
  v4->m_referenceFrame.m_storage = 0;
  if ( v19 > 0 )
  {
    v20 = 0i64;
    do
    {
      v21 = &v4->m_points.m_data[v20];
      v22 = v21->m_sectionId;
      if ( (_DWORD)v22 != -1
        && (signed int)v22 < v8->m_instances.m_size
        && (v23 = v8->m_instances.m_data[v22].m_instancePtr) != 0i64 )
      {
        v24 = &v23->m_referenceFrame.m_transform.m_rotation.m_col0;
      }
      else
      {
        v24 = &transform;
      }
      v25 = v21->m_normal.m_quad;
      ++v20;
      v21->m_position.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v21->m_position.m_quad, v21->m_position.m_quad, 85),
                                       v24[1].m_quad),
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v21->m_position.m_quad, v21->m_position.m_quad, 0),
                                       v24->m_quad)),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(v21->m_position.m_quad, v21->m_position.m_quad, 170),
                                     v24[2].m_quad)),
                                 v24[3].m_quad);
      v21->m_normal.m_quad = _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v24[1].m_quad),
                                 _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v24->m_quad)),
                               _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v24[2].m_quad));
      --v19;
    }
    while ( v19 );
  }
}

// File Line: 138
// RVA: 0xC26470
void __fastcall hkaiPathUtil::transformPathWorldToSectionLocal(hkaiStreamingCollection *collection, hkaiPath *pathIn, hkaiPath *pathOut)
{
  int v3; // ebx
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *v4; // rsi
  int v5; // edi
  hkaiPath *v6; // r15
  int v7; // eax
  hkaiPath *v8; // r14
  hkaiStreamingCollection *v9; // rbp
  int v10; // eax
  int v11; // er9
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *v12; // r8
  hkaiPath::PathPoint *v13; // rcx
  signed __int64 v14; // rax
  char *v15; // rdx
  __int64 v16; // r8
  __int128 v17; // xmm0
  char *v18; // rdx
  __int64 v19; // rcx
  signed __int64 v20; // r8
  __int64 v21; // r15
  signed int v22; // ecx
  __int64 v23; // r14
  __m128 *v24; // rdi
  __int64 v25; // rbx
  hkaiNavMeshInstance *v26; // rax
  hkVector4f *v27; // rax
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  hkTransformf v30; // [rsp+30h] [rbp-A8h]
  hkTransformf t; // [rsp+70h] [rbp-68h]
  hkResult result; // [rsp+E8h] [rbp+10h]

  v3 = pathIn->m_points.m_size;
  v4 = &pathOut->m_points;
  v5 = pathIn->m_points.m_size;
  v6 = pathOut;
  if ( v3 > pathOut->m_points.m_size )
    v5 = pathOut->m_points.m_size;
  v7 = pathOut->m_points.m_capacityAndFlags & 0x3FFFFFFF;
  v8 = pathIn;
  v9 = collection;
  if ( v7 < v3 )
  {
    v10 = 2 * v7;
    v11 = pathIn->m_points.m_size;
    v12 = &pathOut->m_points;
    if ( v3 < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12, v11, 48);
  }
  v13 = v4->m_data;
  if ( v5 > 0 )
  {
    v14 = (signed __int64)&v13->m_normal;
    v15 = (char *)((char *)v8->m_points.m_data - (char *)v13);
    v16 = v5;
    do
    {
      v17 = *(_OWORD *)&v15[v14 - 16];
      v14 += 48i64;
      *(_OWORD *)(v14 - 64) = v17;
      *(_OWORD *)(v14 - 48) = *(_OWORD *)&v15[v14 - 48];
      *(_DWORD *)(v14 - 32) = *(_DWORD *)&v15[v14 - 32];
      *(_DWORD *)(v14 - 28) = *(_DWORD *)&v15[v14 - 28];
      *(_BYTE *)(v14 - 24) = v15[v14 - 24];
      --v16;
    }
    while ( v16 );
  }
  v18 = (char *)&v4->m_data[v5];
  v19 = v3 - v5;
  if ( v3 - v5 > 0 )
  {
    v20 = (char *)&v8->m_points.m_data[v5] - v18;
    do
    {
      if ( v18 )
      {
        *(_OWORD *)v18 = *(_OWORD *)&v18[v20];
        *((_OWORD *)v18 + 1) = *(_OWORD *)&v18[v20 + 16];
        *((_OWORD *)v18 + 2) = *(_OWORD *)&v18[v20 + 32];
      }
      v18 += 48;
      --v19;
    }
    while ( v19 );
  }
  v4->m_size = v3;
  v6->m_referenceFrame.m_storage = 1;
  v21 = v6->m_points.m_size;
  v22 = -1;
  if ( v21 > 0 )
  {
    v23 = 0i64;
    do
    {
      v24 = &v4->m_data[v23].m_position.m_quad;
      v25 = v24[2].m128_i32[1];
      if ( (_DWORD)v25 != v22 )
      {
        if ( (_DWORD)v25 != -1
          && (signed int)v25 < v9->m_instances.m_size
          && (v26 = v9->m_instances.m_data[v25].m_instancePtr) != 0i64 )
        {
          v27 = &v26->m_referenceFrame.m_transform.m_rotation.m_col0;
        }
        else
        {
          v27 = &transform;
        }
        t.m_rotation.m_col0 = (hkVector4f)v27->m_quad;
        t.m_rotation.m_col1 = (hkVector4f)v27[1].m_quad;
        t.m_rotation.m_col2 = (hkVector4f)v27[2].m_quad;
        t.m_translation = (hkVector4f)v27[3].m_quad;
        hkTransformf::setInverse(&v30, &t);
        v22 = v25;
      }
      v28 = v24[1];
      ++v23;
      v29 = _mm_shuffle_ps(v24[1], v28, 85);
      *v24 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*v24, *v24, 85), v30.m_rotation.m_col1.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(*v24, *v24, 0), v30.m_rotation.m_col0.m_quad)),
                 _mm_mul_ps(_mm_shuffle_ps(*v24, *v24, 170), v30.m_rotation.m_col2.m_quad)),
               v30.m_translation.m_quad);
      v24[1] = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(v29, v30.m_rotation.m_col1.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), v30.m_rotation.m_col0.m_quad)),
                 _mm_mul_ps(_mm_shuffle_ps(v28, v28, 170), v30.m_rotation.m_col2.m_quad));
      --v21;
    }
    while ( v21 );
  }
}

// File Line: 165
// RVA: 0xC266B0
void __fastcall hkaiPathUtil::transformPathSectionLocalToSectionFixed(hkaiStreamingCollection *collection, int fixedSectionId, hkaiPath *pathIn, hkaiPath *pathOut)
{
  int v4; // ebx
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *v5; // r15
  int v6; // edi
  hkaiPath *v7; // r12
  int v8; // eax
  hkaiPath *v9; // r13
  __int64 v10; // rsi
  hkaiStreamingCollection *v11; // r14
  int v12; // eax
  int v13; // er9
  hkaiPath::PathPoint *v14; // rcx
  signed __int64 v15; // rax
  char *v16; // rdx
  __int64 v17; // r8
  __int128 v18; // xmm0
  char *v19; // rdx
  __int64 v20; // rcx
  signed __int64 v21; // r8
  hkaiNavMeshInstance *v22; // rax
  hkVector4f *v23; // rax
  __int64 v24; // r13
  signed int v25; // ecx
  __int64 v26; // r12
  __m128 *v27; // rsi
  __int64 v28; // rbx
  hkaiNavMeshInstance *v29; // rax
  hkVector4f *v30; // rax
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  hkTransformf v33; // [rsp+30h] [rbp-D0h]
  hkTransformf t; // [rsp+70h] [rbp-90h]
  hkTransformf bTc; // [rsp+B0h] [rbp-50h]
  hkTransformf aTb; // [rsp+F0h] [rbp-10h]
  hkResult result; // [rsp+168h] [rbp+68h]

  v4 = pathIn->m_points.m_size;
  v5 = &pathOut->m_points;
  v6 = pathIn->m_points.m_size;
  v7 = pathOut;
  if ( v4 > pathOut->m_points.m_size )
    v6 = pathOut->m_points.m_size;
  v8 = pathOut->m_points.m_capacityAndFlags & 0x3FFFFFFF;
  v9 = pathIn;
  v10 = fixedSectionId;
  v11 = collection;
  if ( v8 < v4 )
  {
    v12 = 2 * v8;
    v13 = pathIn->m_points.m_size;
    if ( v4 < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, v13, 48);
  }
  v14 = v5->m_data;
  if ( v6 > 0 )
  {
    v15 = (signed __int64)&v14->m_normal;
    v16 = (char *)((char *)v9->m_points.m_data - (char *)v14);
    v17 = v6;
    do
    {
      v18 = *(_OWORD *)&v16[v15 - 16];
      v15 += 48i64;
      *(_OWORD *)(v15 - 64) = v18;
      *(_OWORD *)(v15 - 48) = *(_OWORD *)&v16[v15 - 48];
      *(_DWORD *)(v15 - 32) = *(_DWORD *)&v16[v15 - 32];
      *(_DWORD *)(v15 - 28) = *(_DWORD *)&v16[v15 - 28];
      *(_BYTE *)(v15 - 24) = v16[v15 - 24];
      --v17;
    }
    while ( v17 );
  }
  v19 = (char *)&v5->m_data[v6];
  v20 = v4 - v6;
  if ( v4 - v6 > 0 )
  {
    v21 = (char *)&v9->m_points.m_data[v6] - v19;
    do
    {
      if ( v19 )
      {
        *(_OWORD *)v19 = *(_OWORD *)&v19[v21];
        *((_OWORD *)v19 + 1) = *(_OWORD *)&v19[v21 + 16];
        *((_OWORD *)v19 + 2) = *(_OWORD *)&v19[v21 + 32];
      }
      v19 += 48;
      --v20;
    }
    while ( v20 );
  }
  v5->m_size = v4;
  v7->m_referenceFrame.m_storage = 2;
  if ( (_DWORD)v10 != -1
    && (signed int)v10 < v11->m_instances.m_size
    && (v22 = v11->m_instances.m_data[v10].m_instancePtr) != 0i64 )
  {
    v23 = &v22->m_referenceFrame.m_transform.m_rotation.m_col0;
  }
  else
  {
    v23 = &transform;
  }
  t.m_rotation.m_col0 = (hkVector4f)v23->m_quad;
  t.m_rotation.m_col1 = (hkVector4f)v23[1].m_quad;
  t.m_rotation.m_col2 = (hkVector4f)v23[2].m_quad;
  t.m_translation = (hkVector4f)v23[3].m_quad;
  hkTransformf::setInverse(&aTb, &t);
  v24 = v7->m_points.m_size;
  v25 = -1;
  if ( v24 > 0 )
  {
    v26 = 0i64;
    do
    {
      v27 = &v5->m_data[v26].m_position.m_quad;
      v28 = v27[2].m128_i32[1];
      if ( (_DWORD)v28 != v25 )
      {
        if ( (_DWORD)v28 != -1
          && (signed int)v28 < v11->m_instances.m_size
          && (v29 = v11->m_instances.m_data[v28].m_instancePtr) != 0i64 )
        {
          v30 = &v29->m_referenceFrame.m_transform.m_rotation.m_col0;
        }
        else
        {
          v30 = &transform;
        }
        bTc.m_rotation.m_col0 = (hkVector4f)v30->m_quad;
        bTc.m_rotation.m_col1 = (hkVector4f)v30[1].m_quad;
        bTc.m_rotation.m_col2 = (hkVector4f)v30[2].m_quad;
        bTc.m_translation = (hkVector4f)v30[3].m_quad;
        hkTransformf::setMul(&v33, &aTb, &bTc);
        v25 = v28;
      }
      v31 = v27[1];
      ++v26;
      v32 = _mm_shuffle_ps(v27[1], v31, 85);
      *v27 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 85), v33.m_rotation.m_col1.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 0), v33.m_rotation.m_col0.m_quad)),
                 _mm_mul_ps(_mm_shuffle_ps(*v27, *v27, 170), v33.m_rotation.m_col2.m_quad)),
               v33.m_translation.m_quad);
      v27[1] = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(v32, v33.m_rotation.m_col1.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v33.m_rotation.m_col0.m_quad)),
                 _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v33.m_rotation.m_col2.m_quad));
      --v24;
    }
    while ( v24 );
  }
}

// File Line: 197
// RVA: 0xC26940
void __fastcall hkaiPathUtil::transformPathSectionFixedToWorld(hkaiStreamingCollection *collection, int fixedSectionId, hkaiPath *pathIn, hkaiPath *pathOut)
{
  int v4; // ebx
  int v5; // esi
  int v6; // eax
  hkaiPath *v7; // r15
  hkaiPath *v8; // r14
  __int64 v9; // rbp
  hkaiStreamingCollection *v10; // r13
  int v11; // eax
  int v12; // er9
  hkaiPath::PathPoint *v13; // rcx
  signed __int64 v14; // rax
  char *v15; // rdx
  __int64 v16; // r8
  __int128 v17; // xmm0
  char *v18; // rdx
  __int64 v19; // rcx
  signed __int64 v20; // r8
  hkaiNavMeshInstance *v21; // rax
  hkVector4f *v22; // rax
  __int64 v23; // rcx
  __m128 v24; // xmm4
  __m128 v25; // xmm5
  __m128 v26; // xmm6
  __m128 v27; // xmm7
  __int64 v28; // rdx
  hkaiPath::PathPoint *v29; // rax
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm1
  hkResult result; // [rsp+88h] [rbp+10h]

  v4 = pathIn->m_points.m_size;
  v5 = pathIn->m_points.m_size;
  if ( v4 > pathOut->m_points.m_size )
    v5 = pathOut->m_points.m_size;
  v6 = pathOut->m_points.m_capacityAndFlags & 0x3FFFFFFF;
  v7 = pathOut;
  v8 = pathIn;
  v9 = fixedSectionId;
  v10 = collection;
  if ( v6 < v4 )
  {
    v11 = 2 * v6;
    v12 = pathIn->m_points.m_size;
    if ( v4 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v7->m_points,
      v12,
      48);
  }
  v13 = v7->m_points.m_data;
  if ( v5 > 0 )
  {
    v14 = (signed __int64)&v13->m_normal;
    v15 = (char *)((char *)v8->m_points.m_data - (char *)v13);
    v16 = v5;
    do
    {
      v17 = *(_OWORD *)&v15[v14 - 16];
      v14 += 48i64;
      *(_OWORD *)(v14 - 64) = v17;
      *(_OWORD *)(v14 - 48) = *(_OWORD *)&v15[v14 - 48];
      *(_DWORD *)(v14 - 32) = *(_DWORD *)&v15[v14 - 32];
      *(_DWORD *)(v14 - 28) = *(_DWORD *)&v15[v14 - 28];
      *(_BYTE *)(v14 - 24) = v15[v14 - 24];
      --v16;
    }
    while ( v16 );
  }
  v18 = (char *)&v7->m_points.m_data[v5];
  v19 = v4 - v5;
  if ( v4 - v5 > 0 )
  {
    v20 = (char *)&v8->m_points.m_data[v5] - v18;
    do
    {
      if ( v18 )
      {
        *(_OWORD *)v18 = *(_OWORD *)&v18[v20];
        *((_OWORD *)v18 + 1) = *(_OWORD *)&v18[v20 + 16];
        *((_OWORD *)v18 + 2) = *(_OWORD *)&v18[v20 + 32];
      }
      v18 += 48;
      --v19;
    }
    while ( v19 );
  }
  v7->m_points.m_size = v4;
  v7->m_referenceFrame.m_storage = 0;
  if ( (_DWORD)v9 != -1
    && (signed int)v9 < v10->m_instances.m_size
    && (v21 = v10->m_instances.m_data[v9].m_instancePtr) != 0i64 )
  {
    v22 = &v21->m_referenceFrame.m_transform.m_rotation.m_col0;
  }
  else
  {
    v22 = &transform;
  }
  v23 = v7->m_points.m_size;
  v24 = v22->m_quad;
  v25 = v22[1].m_quad;
  v26 = v22[2].m_quad;
  v27 = v22[3].m_quad;
  if ( v23 > 0 )
  {
    v28 = 0i64;
    do
    {
      v29 = v7->m_points.m_data;
      ++v28;
      v30 = v29[v28 - 1].m_position.m_quad;
      v31 = *((__m128 *)&v29[v28] - 2);
      v32 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v25),
                _mm_mul_ps(_mm_shuffle_ps(v29[v28 - 1].m_position.m_quad, v30, 0), v24)),
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v26));
      v33 = _mm_shuffle_ps(*((__m128 *)&v29[v28] - 2), v31, 85);
      v29[v28 - 1].m_position.m_quad = _mm_add_ps(v32, v27);
      *((__m128 *)&v29[v28] - 2) = _mm_add_ps(
                                     _mm_add_ps(_mm_mul_ps(v33, v25), _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v24)),
                                     _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v26));
      --v23;
    }
    while ( v23 );
  }
}

// File Line: 220
// RVA: 0xC25F30
void __fastcall hkaiPath::PathPoint::checkDeterminism(hkaiPath::PathPoint *this)
{
  ;
}

