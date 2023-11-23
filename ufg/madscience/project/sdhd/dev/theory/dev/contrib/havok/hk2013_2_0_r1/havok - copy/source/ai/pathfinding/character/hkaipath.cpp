// File Line: 16
// RVA: 0xC25F40
void __fastcall hkaiPath::setDistances(hkaiPath *this)
{
  int v1; // r8d
  __int64 v2; // rdx
  hkaiPath::PathPoint *m_data; // rax
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
      m_data = this->m_points.m_data;
      ++v1;
      ++v2;
      v4 = _mm_sub_ps(m_data[v2 - 2].m_position.m_quad, m_data[v2 - 1].m_position.m_quad);
      v5 = _mm_mul_ps(v4, v4);
      v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
      v7 = _mm_rsqrt_ps(v6);
      m_data[v2 - 1].m_position.m_quad = _mm_shuffle_ps(
                                           m_data[v2 - 1].m_position.m_quad,
                                           _mm_unpackhi_ps(
                                             m_data[v2 - 1].m_position.m_quad,
                                             _mm_add_ps(
                                               _mm_shuffle_ps(
                                                 m_data[v2 - 2].m_position.m_quad,
                                                 m_data[v2 - 2].m_position.m_quad,
                                                 255),
                                               _mm_andnot_ps(
                                                 _mm_cmple_ps(v6, (__m128)0i64),
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
__int64 __fastcall hkaiPathUtil::_getPathLength(const unsigned int *output, int maxOutputLength)
{
  __int64 result; // rax
  __int64 i; // rcx

  if ( !output )
    return 0i64;
  result = 0i64;
  for ( i = 0i64; i < maxOutputLength; result = (unsigned int)(result + 1) )
  {
    if ( output[i] == -1 )
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
  unsigned int *p_m_userEdgeData; // rcx

  v2 = maxPathLength;
  if ( !path )
    return 0i64;
  result = 0i64;
  v4 = 0i64;
  if ( v2 > 0 )
  {
    p_m_userEdgeData = &path->m_userEdgeData;
    do
    {
      if ( !*((_BYTE *)p_m_userEdgeData + 8) && *p_m_userEdgeData == 0x80000000 )
        break;
      ++v4;
      result = (unsigned int)(result + 1);
      p_m_userEdgeData += 12;
    }
    while ( v4 < v2 );
  }
  return result;
}

// File Line: 86
// RVA: 0xC26120
void __fastcall hkaiPathUtil::transformPathPositionsSectionLocalToWorld(
        hkaiStreamingCollection *collection,
        hkaiPath *pathIn,
        hkArray<hkaiPath::PathPoint,hkContainerTempAllocator> *pointsOut,
        int startIndex)
{
  __int64 m_size; // rbp
  __int64 v5; // rsi
  int v9; // eax
  int v10; // r9d
  int v11; // eax
  __int64 v12; // r8
  __int64 v13; // r9
  hkaiPath::PathPoint *v14; // rdx
  __int64 m_sectionId; // rax
  hkaiPath::PathPoint *v16; // rcx
  __m128 m_quad; // xmm1
  hkaiNavMeshInstance *m_instancePtr; // rax
  hkVector4f *p_m_col0; // rax
  hkVector4f v20; // xmm2
  hkaiPath::PathPoint *v21; // rcx
  hkResult result; // [rsp+68h] [rbp+20h] BYREF

  m_size = pathIn->m_points.m_size;
  v5 = startIndex;
  if ( startIndex < (int)m_size )
  {
    v9 = pointsOut->m_capacityAndFlags & 0x3FFFFFFF;
    v10 = m_size - startIndex;
    if ( v9 < (int)m_size - (int)v5 )
    {
      v11 = 2 * v9;
      if ( v10 < v11 )
        v10 = v11;
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, pointsOut, v10, 48);
    }
    if ( v5 < m_size )
    {
      v12 = v5;
      v13 = m_size - v5;
      do
      {
        v14 = &pathIn->m_points.m_data[v12];
        m_sectionId = v14->m_sectionId;
        if ( (_DWORD)m_sectionId == -1 )
        {
          v16 = &pointsOut->m_data[pointsOut->m_size];
          if ( v16 )
          {
            v16->m_position = v14->m_position;
            v16->m_normal = v14->m_normal;
            *(_OWORD *)&v16->m_userEdgeData = *(_OWORD *)&v14->m_userEdgeData;
          }
          ++pointsOut->m_size;
        }
        else
        {
          if ( (int)m_sectionId < collection->m_instances.m_size
            && (m_instancePtr = collection->m_instances.m_data[m_sectionId].m_instancePtr) != 0i64 )
          {
            p_m_col0 = &m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col0;
          }
          else
          {
            p_m_col0 = &transform;
          }
          m_quad = v14->m_position.m_quad;
          v20.m_quad = _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), p_m_col0[1].m_quad),
                             _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), p_m_col0->m_quad)),
                           _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), p_m_col0[2].m_quad)),
                         p_m_col0[3].m_quad);
          v21 = &pointsOut->m_data[pointsOut->m_size];
          if ( v21 )
          {
            v21->m_position = v14->m_position;
            v21->m_normal = v14->m_normal;
            *(_OWORD *)&v21->m_userEdgeData = *(_OWORD *)&v14->m_userEdgeData;
          }
          pointsOut->m_data[pointsOut->m_size++].m_position = (hkVector4f)v20.m_quad;
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
void __fastcall hkaiPathUtil::transformPathSectionLocalToWorld(
        hkaiStreamingCollection *collection,
        hkaiPath *pathIn,
        hkaiPath *pathOut)
{
  int m_size; // esi
  int v5; // ebp
  int v7; // eax
  int v9; // eax
  int v10; // r9d
  hkaiPath::PathPoint *m_data; // rcx
  hkVector4f *p_m_normal; // rax
  char *v13; // rdx
  __int64 v14; // r8
  hkVector4f v15; // xmm0
  hkaiPath::PathPoint *v16; // rdx
  __int64 v17; // rcx
  char *v18; // r8
  __int64 v19; // r9
  __int64 v20; // r8
  hkaiPath::PathPoint *v21; // rdx
  __int64 m_sectionId; // rax
  hkaiNavMeshInstance *m_instancePtr; // rax
  hkVector4f *p_m_col0; // rax
  __m128 m_quad; // xmm3
  hkResult result; // [rsp+58h] [rbp+10h] BYREF

  m_size = pathIn->m_points.m_size;
  v5 = m_size;
  if ( m_size > pathOut->m_points.m_size )
    v5 = pathOut->m_points.m_size;
  v7 = pathOut->m_points.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < m_size )
  {
    v9 = 2 * v7;
    v10 = pathIn->m_points.m_size;
    if ( m_size < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &pathOut->m_points, v10, 48);
  }
  m_data = pathOut->m_points.m_data;
  if ( v5 > 0 )
  {
    p_m_normal = &m_data->m_normal;
    v13 = (char *)((char *)pathIn->m_points.m_data - (char *)m_data);
    v14 = v5;
    do
    {
      v15.m_quad = *(__m128 *)((char *)&p_m_normal[-1] + (_QWORD)v13);
      p_m_normal += 3;
      p_m_normal[-4] = (hkVector4f)v15.m_quad;
      p_m_normal[-3] = *(hkVector4f *)((char *)p_m_normal + (_QWORD)v13 - 48);
      p_m_normal[-2].m_quad.m128_i32[0] = *(int *)((char *)p_m_normal[-2].m_quad.m128_i32 + (_QWORD)v13);
      p_m_normal[-2].m_quad.m128_i32[1] = *(_DWORD *)((char *)&p_m_normal[-1] + (_QWORD)v13 - 12);
      p_m_normal[-2].m_quad.m128_i8[8] = *((_BYTE *)&p_m_normal[-1] + (_QWORD)v13 - 8);
      --v14;
    }
    while ( v14 );
  }
  v16 = &pathOut->m_points.m_data[v5];
  v17 = m_size - v5;
  if ( m_size - v5 > 0 )
  {
    v18 = (char *)((char *)&pathIn->m_points.m_data[v5] - (char *)v16);
    do
    {
      if ( v16 )
      {
        v16->m_position = *(hkVector4f *)((char *)&v16->m_position + (_QWORD)v18);
        v16->m_normal = *(hkVector4f *)((char *)&v16->m_normal + (_QWORD)v18);
        *(_OWORD *)&v16->m_userEdgeData = *(_OWORD *)((char *)&v16->m_userEdgeData + (_QWORD)v18);
      }
      ++v16;
      --v17;
    }
    while ( v17 );
  }
  pathOut->m_points.m_size = m_size;
  v19 = pathOut->m_points.m_size;
  pathOut->m_referenceFrame.m_storage = 0;
  if ( v19 > 0 )
  {
    v20 = 0i64;
    do
    {
      v21 = &pathOut->m_points.m_data[v20];
      m_sectionId = v21->m_sectionId;
      if ( (_DWORD)m_sectionId == -1
        || (int)m_sectionId >= collection->m_instances.m_size
        || (m_instancePtr = collection->m_instances.m_data[m_sectionId].m_instancePtr) == 0i64 )
      {
        p_m_col0 = &transform;
      }
      else
      {
        p_m_col0 = &m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col0;
      }
      m_quad = v21->m_normal.m_quad;
      ++v20;
      v21->m_position.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v21->m_position.m_quad, v21->m_position.m_quad, 85),
                                       p_m_col0[1].m_quad),
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v21->m_position.m_quad, v21->m_position.m_quad, 0),
                                       p_m_col0->m_quad)),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(v21->m_position.m_quad, v21->m_position.m_quad, 170),
                                     p_m_col0[2].m_quad)),
                                 p_m_col0[3].m_quad);
      v21->m_normal.m_quad = _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), p_m_col0[1].m_quad),
                                 _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), p_m_col0->m_quad)),
                               _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), p_m_col0[2].m_quad));
      --v19;
    }
    while ( v19 );
  }
}

// File Line: 138
// RVA: 0xC26470
void __fastcall hkaiPathUtil::transformPathWorldToSectionLocal(
        hkaiStreamingCollection *collection,
        hkaiPath *pathIn,
        hkaiPath *pathOut)
{
  int m_size; // ebx
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *p_m_points; // rsi
  int v5; // edi
  int v7; // eax
  int v10; // eax
  int v11; // r9d
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *v12; // r8
  hkaiPath::PathPoint *m_data; // rcx
  hkVector4f *p_m_normal; // rax
  char *v15; // rdx
  __int64 v16; // r8
  hkVector4f v17; // xmm0
  char *v18; // rdx
  __int64 v19; // rcx
  signed __int64 v20; // r8
  __int64 v21; // r15
  int v22; // ecx
  __int64 v23; // r14
  hkaiPath::PathPoint *v24; // rdi
  __int64 m_sectionId; // rbx
  hkaiNavMeshInstance *m_instancePtr; // rax
  hkTransformf *p_m_transform; // rax
  __m128 m_quad; // xmm3
  hkTransformf v29; // [rsp+30h] [rbp-A8h] BYREF
  hkTransformf t; // [rsp+70h] [rbp-68h] BYREF
  hkResult result; // [rsp+E8h] [rbp+10h] BYREF

  m_size = pathIn->m_points.m_size;
  p_m_points = &pathOut->m_points;
  v5 = m_size;
  if ( m_size > pathOut->m_points.m_size )
    v5 = pathOut->m_points.m_size;
  v7 = pathOut->m_points.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 < m_size )
  {
    v10 = 2 * v7;
    v11 = pathIn->m_points.m_size;
    v12 = &pathOut->m_points;
    if ( m_size < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, v12, v11, 48);
  }
  m_data = p_m_points->m_data;
  if ( v5 > 0 )
  {
    p_m_normal = &m_data->m_normal;
    v15 = (char *)((char *)pathIn->m_points.m_data - (char *)m_data);
    v16 = v5;
    do
    {
      v17.m_quad = *(__m128 *)((char *)&p_m_normal[-1] + (_QWORD)v15);
      p_m_normal += 3;
      p_m_normal[-4] = (hkVector4f)v17.m_quad;
      p_m_normal[-3] = *(hkVector4f *)((char *)p_m_normal + (_QWORD)v15 - 48);
      p_m_normal[-2].m_quad.m128_i32[0] = *(int *)((char *)p_m_normal[-2].m_quad.m128_i32 + (_QWORD)v15);
      p_m_normal[-2].m_quad.m128_i32[1] = *(_DWORD *)((char *)&p_m_normal[-1] + (_QWORD)v15 - 12);
      p_m_normal[-2].m_quad.m128_i8[8] = *((_BYTE *)&p_m_normal[-1] + (_QWORD)v15 - 8);
      --v16;
    }
    while ( v16 );
  }
  v18 = (char *)&p_m_points->m_data[v5];
  v19 = m_size - v5;
  if ( m_size - v5 > 0 )
  {
    v20 = (char *)&pathIn->m_points.m_data[v5] - v18;
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
  p_m_points->m_size = m_size;
  pathOut->m_referenceFrame.m_storage = 1;
  v21 = pathOut->m_points.m_size;
  v22 = -1;
  if ( v21 > 0 )
  {
    v23 = 0i64;
    do
    {
      v24 = &p_m_points->m_data[v23];
      m_sectionId = v24->m_sectionId;
      if ( (_DWORD)m_sectionId != v22 )
      {
        if ( (_DWORD)m_sectionId == -1
          || (int)m_sectionId >= collection->m_instances.m_size
          || (m_instancePtr = collection->m_instances.m_data[m_sectionId].m_instancePtr) == 0i64 )
        {
          p_m_transform = (hkTransformf *)&transform;
        }
        else
        {
          p_m_transform = &m_instancePtr->m_referenceFrame.m_transform;
        }
        t = *p_m_transform;
        hkTransformf::setInverse(&v29, &t);
        v22 = m_sectionId;
      }
      m_quad = v24->m_normal.m_quad;
      ++v23;
      v24->m_position.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v24->m_position.m_quad, v24->m_position.m_quad, 85),
                                       v29.m_rotation.m_col1.m_quad),
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v24->m_position.m_quad, v24->m_position.m_quad, 0),
                                       v29.m_rotation.m_col0.m_quad)),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(v24->m_position.m_quad, v24->m_position.m_quad, 170),
                                     v29.m_rotation.m_col2.m_quad)),
                                 v29.m_translation.m_quad);
      v24->m_normal.m_quad = _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v29.m_rotation.m_col1.m_quad),
                                 _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v29.m_rotation.m_col0.m_quad)),
                               _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v29.m_rotation.m_col2.m_quad));
      --v21;
    }
    while ( v21 );
  }
}

// File Line: 165
// RVA: 0xC266B0
void __fastcall hkaiPathUtil::transformPathSectionLocalToSectionFixed(
        hkaiStreamingCollection *collection,
        int fixedSectionId,
        hkaiPath *pathIn,
        hkaiPath *pathOut)
{
  int m_size; // ebx
  hkArray<hkaiPath::PathPoint,hkContainerHeapAllocator> *p_m_points; // r15
  int v6; // edi
  int v8; // eax
  __int64 v10; // rsi
  int v12; // eax
  int v13; // r9d
  hkaiPath::PathPoint *m_data; // rcx
  hkVector4f *p_m_normal; // rax
  char *v16; // rdx
  __int64 v17; // r8
  hkVector4f v18; // xmm0
  char *v19; // rdx
  __int64 v20; // rcx
  signed __int64 v21; // r8
  hkaiNavMeshInstance *m_instancePtr; // rax
  hkTransformf *p_m_transform; // rax
  __int64 v24; // r13
  int v25; // ecx
  __int64 v26; // r12
  hkaiPath::PathPoint *v27; // rsi
  __int64 m_sectionId; // rbx
  hkaiNavMeshInstance *v29; // rax
  hkTransformf *v30; // rax
  __m128 m_quad; // xmm3
  hkTransformf v32; // [rsp+30h] [rbp-D0h] BYREF
  hkTransformf t; // [rsp+70h] [rbp-90h] BYREF
  hkTransformf bTc; // [rsp+B0h] [rbp-50h] BYREF
  hkTransformf aTb; // [rsp+F0h] [rbp-10h] BYREF
  hkResult result; // [rsp+168h] [rbp+68h] BYREF

  m_size = pathIn->m_points.m_size;
  p_m_points = &pathOut->m_points;
  v6 = m_size;
  if ( m_size > pathOut->m_points.m_size )
    v6 = pathOut->m_points.m_size;
  v8 = pathOut->m_points.m_capacityAndFlags & 0x3FFFFFFF;
  v10 = fixedSectionId;
  if ( v8 < m_size )
  {
    v12 = 2 * v8;
    v13 = pathIn->m_points.m_size;
    if ( m_size < v12 )
      v13 = v12;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, p_m_points, v13, 48);
  }
  m_data = p_m_points->m_data;
  if ( v6 > 0 )
  {
    p_m_normal = &m_data->m_normal;
    v16 = (char *)((char *)pathIn->m_points.m_data - (char *)m_data);
    v17 = v6;
    do
    {
      v18.m_quad = *(__m128 *)((char *)&p_m_normal[-1] + (_QWORD)v16);
      p_m_normal += 3;
      p_m_normal[-4] = (hkVector4f)v18.m_quad;
      p_m_normal[-3] = *(hkVector4f *)((char *)p_m_normal + (_QWORD)v16 - 48);
      p_m_normal[-2].m_quad.m128_i32[0] = *(int *)((char *)p_m_normal[-2].m_quad.m128_i32 + (_QWORD)v16);
      p_m_normal[-2].m_quad.m128_i32[1] = *(_DWORD *)((char *)&p_m_normal[-1] + (_QWORD)v16 - 12);
      p_m_normal[-2].m_quad.m128_i8[8] = *((_BYTE *)&p_m_normal[-1] + (_QWORD)v16 - 8);
      --v17;
    }
    while ( v17 );
  }
  v19 = (char *)&p_m_points->m_data[v6];
  v20 = m_size - v6;
  if ( m_size - v6 > 0 )
  {
    v21 = (char *)&pathIn->m_points.m_data[v6] - v19;
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
  p_m_points->m_size = m_size;
  pathOut->m_referenceFrame.m_storage = 2;
  if ( (_DWORD)v10 == -1
    || (int)v10 >= collection->m_instances.m_size
    || (m_instancePtr = collection->m_instances.m_data[v10].m_instancePtr) == 0i64 )
  {
    p_m_transform = (hkTransformf *)&transform;
  }
  else
  {
    p_m_transform = &m_instancePtr->m_referenceFrame.m_transform;
  }
  t = *p_m_transform;
  hkTransformf::setInverse(&aTb, &t);
  v24 = pathOut->m_points.m_size;
  v25 = -1;
  if ( v24 > 0 )
  {
    v26 = 0i64;
    do
    {
      v27 = &p_m_points->m_data[v26];
      m_sectionId = v27->m_sectionId;
      if ( (_DWORD)m_sectionId != v25 )
      {
        if ( (_DWORD)m_sectionId == -1
          || (int)m_sectionId >= collection->m_instances.m_size
          || (v29 = collection->m_instances.m_data[m_sectionId].m_instancePtr) == 0i64 )
        {
          v30 = (hkTransformf *)&transform;
        }
        else
        {
          v30 = &v29->m_referenceFrame.m_transform;
        }
        bTc = *v30;
        hkTransformf::setMul(&v32, &aTb, &bTc);
        v25 = m_sectionId;
      }
      m_quad = v27->m_normal.m_quad;
      ++v26;
      v27->m_position.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v27->m_position.m_quad, v27->m_position.m_quad, 85),
                                       v32.m_rotation.m_col1.m_quad),
                                     _mm_mul_ps(
                                       _mm_shuffle_ps(v27->m_position.m_quad, v27->m_position.m_quad, 0),
                                       v32.m_rotation.m_col0.m_quad)),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(v27->m_position.m_quad, v27->m_position.m_quad, 170),
                                     v32.m_rotation.m_col2.m_quad)),
                                 v32.m_translation.m_quad);
      v27->m_normal.m_quad = _mm_add_ps(
                               _mm_add_ps(
                                 _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v32.m_rotation.m_col1.m_quad),
                                 _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v32.m_rotation.m_col0.m_quad)),
                               _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v32.m_rotation.m_col2.m_quad));
      --v24;
    }
    while ( v24 );
  }
}

// File Line: 197
// RVA: 0xC26940
void __fastcall hkaiPathUtil::transformPathSectionFixedToWorld(
        hkaiStreamingCollection *collection,
        int fixedSectionId,
        hkaiPath *pathIn,
        hkaiPath *pathOut)
{
  int m_size; // ebx
  int v5; // esi
  int v6; // eax
  __int64 v9; // rbp
  int v11; // eax
  int v12; // r9d
  hkaiPath::PathPoint *m_data; // rcx
  hkVector4f *p_m_normal; // rax
  char *v15; // rdx
  __int64 v16; // r8
  hkVector4f v17; // xmm0
  hkaiPath::PathPoint *v18; // rdx
  __int64 v19; // rcx
  char *v20; // r8
  hkaiNavMeshInstance *m_instancePtr; // rax
  hkVector4f *p_m_col0; // rax
  __int64 v23; // rcx
  __m128 m_quad; // xmm4
  __m128 v25; // xmm5
  __m128 v26; // xmm6
  __m128 v27; // xmm7
  __int64 v28; // rdx
  hkaiPath::PathPoint *v29; // rax
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  hkResult result; // [rsp+88h] [rbp+10h] BYREF

  m_size = pathIn->m_points.m_size;
  v5 = m_size;
  if ( m_size > pathOut->m_points.m_size )
    v5 = pathOut->m_points.m_size;
  v6 = pathOut->m_points.m_capacityAndFlags & 0x3FFFFFFF;
  v9 = fixedSectionId;
  if ( v6 < m_size )
  {
    v11 = 2 * v6;
    v12 = pathIn->m_points.m_size;
    if ( m_size < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &pathOut->m_points, v12, 48);
  }
  m_data = pathOut->m_points.m_data;
  if ( v5 > 0 )
  {
    p_m_normal = &m_data->m_normal;
    v15 = (char *)((char *)pathIn->m_points.m_data - (char *)m_data);
    v16 = v5;
    do
    {
      v17.m_quad = *(__m128 *)((char *)&p_m_normal[-1] + (_QWORD)v15);
      p_m_normal += 3;
      p_m_normal[-4] = (hkVector4f)v17.m_quad;
      p_m_normal[-3] = *(hkVector4f *)((char *)p_m_normal + (_QWORD)v15 - 48);
      p_m_normal[-2].m_quad.m128_i32[0] = *(int *)((char *)p_m_normal[-2].m_quad.m128_i32 + (_QWORD)v15);
      p_m_normal[-2].m_quad.m128_i32[1] = *(_DWORD *)((char *)&p_m_normal[-1] + (_QWORD)v15 - 12);
      p_m_normal[-2].m_quad.m128_i8[8] = *((_BYTE *)&p_m_normal[-1] + (_QWORD)v15 - 8);
      --v16;
    }
    while ( v16 );
  }
  v18 = &pathOut->m_points.m_data[v5];
  v19 = m_size - v5;
  if ( m_size - v5 > 0 )
  {
    v20 = (char *)((char *)&pathIn->m_points.m_data[v5] - (char *)v18);
    do
    {
      if ( v18 )
      {
        v18->m_position = *(hkVector4f *)((char *)&v18->m_position + (_QWORD)v20);
        v18->m_normal = *(hkVector4f *)((char *)&v18->m_normal + (_QWORD)v20);
        *(_OWORD *)&v18->m_userEdgeData = *(_OWORD *)((char *)&v18->m_userEdgeData + (_QWORD)v20);
      }
      ++v18;
      --v19;
    }
    while ( v19 );
  }
  pathOut->m_points.m_size = m_size;
  pathOut->m_referenceFrame.m_storage = 0;
  if ( (_DWORD)v9 == -1
    || (int)v9 >= collection->m_instances.m_size
    || (m_instancePtr = collection->m_instances.m_data[v9].m_instancePtr) == 0i64 )
  {
    p_m_col0 = &transform;
  }
  else
  {
    p_m_col0 = &m_instancePtr->m_referenceFrame.m_transform.m_rotation.m_col0;
  }
  v23 = pathOut->m_points.m_size;
  m_quad = p_m_col0->m_quad;
  v25 = p_m_col0[1].m_quad;
  v26 = p_m_col0[2].m_quad;
  v27 = p_m_col0[3].m_quad;
  if ( v23 > 0 )
  {
    v28 = 0i64;
    do
    {
      v29 = pathOut->m_points.m_data;
      v30 = v29[v28++].m_position.m_quad;
      v31 = v29[v28 - 1].m_normal.m_quad;
      v29[v28 - 1].m_position.m_quad = _mm_add_ps(
                                         _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v25),
                                             _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), m_quad)),
                                           _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v26)),
                                         v27);
      v29[v28 - 1].m_normal.m_quad = _mm_add_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), v25),
                                         _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), m_quad)),
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

