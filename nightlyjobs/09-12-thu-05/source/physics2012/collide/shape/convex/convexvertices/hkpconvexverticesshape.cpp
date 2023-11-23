// File Line: 79
// RVA: 0xD074B0
void __fastcall hkpConvexVerticesShape::hkpConvexVerticesShape(hkpConvexVerticesShape *this, float radius)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1029;
  this->m_radius = radius;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexVerticesShape::`vftable;
  this->m_rotatedVertices.m_data = 0i64;
  this->m_rotatedVertices.m_size = 0;
  this->m_rotatedVertices.m_capacityAndFlags = 0x80000000;
  this->m_useSpuBuffer.m_bool = 0;
  this->m_planeEquations.m_data = 0i64;
  this->m_planeEquations.m_size = 0;
  this->m_planeEquations.m_capacityAndFlags = 0x80000000;
  this->m_connectivity = 0i64;
}

// File Line: 86
// RVA: 0xD072E0
void __fastcall hkpConvexVerticesShape::hkpConvexVerticesShape(
        hkpConvexVerticesShape *this,
        hkStridedVertices *vertsIn,
        hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations,
        float radius)
{
  int m_capacityAndFlags; // eax
  __int64 m_size; // rax
  hkVector4f *m_data; // rcx
  __int64 v10; // rdx
  char *v11; // r8
  hkVector4f v12; // xmm0
  int v13; // [rsp+48h] [rbp+20h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1029;
  this->m_radius = radius;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexVerticesShape::`vftable;
  this->m_rotatedVertices.m_data = 0i64;
  this->m_rotatedVertices.m_size = 0;
  this->m_rotatedVertices.m_capacityAndFlags = 0x80000000;
  this->m_useSpuBuffer.m_bool = 0;
  this->m_planeEquations.m_data = 0i64;
  this->m_planeEquations.m_size = 0;
  this->m_planeEquations.m_capacityAndFlags = 0x80000000;
  this->m_connectivity = 0i64;
  m_capacityAndFlags = this->m_planeEquations.m_capacityAndFlags;
  if ( (m_capacityAndFlags & 0x3FFFFFFF) < planeEquations->m_size )
  {
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        0i64,
        16 * m_capacityAndFlags);
    v13 = 16 * planeEquations->m_size;
    this->m_planeEquations.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                    &hkContainerHeapAllocator::s_alloc,
                                                    &v13);
    this->m_planeEquations.m_capacityAndFlags = v13 / 16;
  }
  m_size = planeEquations->m_size;
  m_data = this->m_planeEquations.m_data;
  this->m_planeEquations.m_size = m_size;
  v10 = m_size;
  if ( (int)m_size > 0 )
  {
    v11 = (char *)((char *)planeEquations->m_data - (char *)m_data);
    do
    {
      v12.m_quad = *(__m128 *)((char *)m_data++ + (_QWORD)v11);
      m_data[-1] = (hkVector4f)v12.m_quad;
      --v10;
    }
    while ( v10 );
  }
  hkpConvexVerticesShape::copyVertexData(this, vertsIn->m_vertices, vertsIn->m_striding, vertsIn->m_numVertices);
}

// File Line: 107
// RVA: 0xD07400
void __fastcall hkpConvexVerticesShape::hkpConvexVerticesShape(
        hkpConvexVerticesShape *this,
        hkFourTransposedPointsf *rotatedVertices,
        int numVertices,
        hkVector4f *planes,
        int numPlanes,
        hkAabb *aabb,
        float radius)
{
  int v7; // eax
  hkVector4f v9; // xmm0
  hkVector4f v10; // xmm1

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1029;
  this->m_radius = radius;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexVerticesShape::`vftable;
  this->m_userData = 0i64;
  this->m_rotatedVertices.m_data = rotatedVertices;
  v7 = (int)((numVertices + 3) & 0xFFFFFFFC) / 4;
  this->m_rotatedVertices.m_size = v7;
  this->m_rotatedVertices.m_capacityAndFlags = v7 | 0x80000000;
  this->m_numVertices = numVertices;
  this->m_useSpuBuffer.m_bool = 0;
  this->m_planeEquations.m_size = numPlanes;
  this->m_planeEquations.m_data = planes;
  this->m_planeEquations.m_capacityAndFlags = numPlanes | 0x80000000;
  this->m_connectivity = 0i64;
  v9.m_quad = _mm_sub_ps(aabb->m_max.m_quad, aabb->m_min.m_quad);
  this->m_aabbHalfExtents = (hkVector4f)v9.m_quad;
  this->m_aabbHalfExtents.m_quad = _mm_mul_ps(v9.m_quad, (__m128)xmmword_141A711B0);
  v10.m_quad = _mm_add_ps(aabb->m_min.m_quad, aabb->m_max.m_quad);
  this->m_aabbCenter = (hkVector4f)v10.m_quad;
  this->m_aabbCenter.m_quad = _mm_mul_ps(v10.m_quad, (__m128)xmmword_141A711B0);
}

// File Line: 151
// RVA: 0xD07500
void __fastcall hkpConvexVerticesShape::hkpConvexVerticesShape(
        hkpConvexVerticesShape *this,
        hkFinishLoadedObjectFlag flag)
{
  hkpConvexShape::hkpConvexShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexVerticesShape::`vftable;
  if ( flag.m_finishing )
    this->m_type.m_storage = 5;
}

// File Line: 159
// RVA: 0xD07540
void __fastcall hkpConvexVerticesShape::~hkpConvexVerticesShape(hkpConvexVerticesShape *this)
{
  hkpConvexVerticesConnectivity *m_connectivity; // rcx
  int m_capacityAndFlags; // r8d
  int v4; // eax

  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexVerticesShape::`vftable;
  m_connectivity = this->m_connectivity;
  if ( m_connectivity )
    hkReferencedObject::removeReference(m_connectivity);
  m_capacityAndFlags = this->m_planeEquations.m_capacityAndFlags;
  this->m_planeEquations.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_planeEquations.m_data,
      16 * m_capacityAndFlags);
  this->m_planeEquations.m_data = 0i64;
  this->m_planeEquations.m_capacityAndFlags = 0x80000000;
  v4 = this->m_rotatedVertices.m_capacityAndFlags;
  this->m_rotatedVertices.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_rotatedVertices.m_data,
      48 * (v4 & 0x3FFFFFFF));
  this->m_rotatedVertices.m_data = 0i64;
  this->m_rotatedVertices.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 168
// RVA: 0xD07CB0
void __fastcall hkpConvexVerticesShape::setConnectivity(
        hkpConvexVerticesShape *this,
        hkpConvexVerticesConnectivity *connect,
        bool sort)
{
  hkpConvexVerticesConnectivity *m_connectivity; // rcx

  if ( connect )
    hkReferencedObject::addReference(connect);
  m_connectivity = this->m_connectivity;
  if ( m_connectivity )
    hkReferencedObject::removeReference(m_connectivity);
  this->m_connectivity = connect;
  if ( sort )
  {
    if ( connect )
      hkpConvexVerticesShape::sortPlanes(this);
  }
}

// File Line: 189
// RVA: 0xD075F0
void __fastcall hkpConvexVerticesShape::getOriginalVertices(
        hkpConvexVerticesShape *this,
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices)
{
  int v3; // edi
  int v4; // eax
  int v6; // eax
  int v7; // r9d
  hkcdVertex *m_data; // r8
  int m_numVertices; // edi
  int v10; // eax
  int v11; // eax
  int v12; // r9d
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  v3 = 4 * this->m_rotatedVertices.m_size;
  v4 = vertices->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v4 < v3 )
  {
    v6 = 2 * v4;
    v7 = 4 * this->m_rotatedVertices.m_size;
    if ( v3 < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&vertices->m_data, v7, 16);
  }
  m_data = (hkcdVertex *)vertices->m_data;
  vertices->m_size = v3;
  hkFourTransposedPointsf::getOriginalVertices(this->m_rotatedVertices.m_data, this->m_numVertices, m_data);
  m_numVertices = this->m_numVertices;
  v10 = vertices->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < m_numVertices )
  {
    v11 = 2 * v10;
    v12 = this->m_numVertices;
    if ( m_numVertices < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&vertices->m_data, v12, 16);
  }
  vertices->m_size = m_numVertices;
}

// File Line: 197
// RVA: 0xD07A40
void __fastcall hkpConvexVerticesShape::copyVertexData(
        hkpConvexVerticesShape *this,
        const float *vertexIn,
        int byteStriding,
        int numVertices)
{
  __int64 v7; // rbp
  int v8; // ecx
  int v9; // eax
  int v10; // edi
  int v11; // ecx
  int v12; // r9d
  int v13; // edi
  const float *v14; // rax
  __int64 v15; // r9
  const float *v16; // rdx
  __int64 v17; // r10
  __m128 v18; // xmm6
  __m128 v19; // xmm0
  hkFourTransposedPointsf *m_data; // rcx
  unsigned int *v21; // rdx
  unsigned __int64 *v22; // rax
  __m128 v23; // xmm5
  __m128 v24; // xmm6
  __m128 v25; // xmm0
  unsigned int *v26; // rdx
  unsigned __int64 *v27; // rax
  __m128 v28; // xmm4
  __m128 v29; // xmm5
  __m128 v30; // xmm0
  unsigned int *v31; // rdx
  unsigned __int64 *v32; // rax
  __m128 v33; // xmm2
  __m128 v34; // xmm3
  __m128 v35; // xmm4
  __m128 v36; // xmm0
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  __int64 v39; // rdx
  __int64 v40; // rdi
  __m128 *v41; // rcx
  __m128 v42; // xmm1
  __m128 v43; // xmm0
  unsigned __int64 *v44; // rax
  __m128 *v45; // rsi
  hkFourTransposedPointsf *v46; // rax
  __m128 v47; // xmm3
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  hkAabb aabbOut; // [rsp+30h] [rbp-98h] BYREF
  __m128 v51; // [rsp+50h] [rbp-78h] BYREF
  __m128 v52; // [rsp+60h] [rbp-68h]
  __m128 v53; // [rsp+70h] [rbp-58h]
  __m128 v54; // [rsp+80h] [rbp-48h]
  hkResult result; // [rsp+E8h] [rbp+20h] BYREF

  v7 = byteStriding;
  this->m_numVertices = numVertices;
  v8 = this->m_rotatedVertices.m_capacityAndFlags & 0x3FFFFFFF;
  v9 = (int)((numVertices + 3) & 0xFFFFFFFC) / 4;
  v10 = v9;
  if ( v8 < v9 )
  {
    v11 = 2 * v8;
    v12 = (int)((numVertices + 3) & 0xFFFFFFFC) / 4;
    if ( v9 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_rotatedVertices.m_data,
      v12,
      48);
  }
  this->m_rotatedVertices.m_size = v10;
  v13 = numVertices >> 2;
  v14 = vertexIn;
  if ( numVertices >> 2 > 0 )
  {
    v15 = 0i64;
    v16 = vertexIn + 2;
    v17 = v13;
    do
    {
      v18 = (__m128)*(unsigned __int64 *)v14;
      v19 = (__m128)*(unsigned int *)v16;
      m_data = this->m_rotatedVertices.m_data;
      v21 = (unsigned int *)((char *)v16 + v7);
      v22 = (unsigned __int64 *)((char *)v14 + v7);
      ++v15;
      v23 = (__m128)*v22;
      v24 = _mm_movelh_ps(v18, v19);
      v25 = (__m128)*v21;
      v26 = (unsigned int *)((char *)v21 + v7);
      v27 = (unsigned __int64 *)((char *)v22 + v7);
      v28 = (__m128)*v27;
      v29 = _mm_movelh_ps(v23, v25);
      v30 = (__m128)*v26;
      v31 = (unsigned int *)((char *)v26 + v7);
      v32 = (unsigned __int64 *)((char *)v27 + v7);
      v33 = _mm_shuffle_ps(v24, v29, 68);
      v34 = (__m128)*v32;
      v35 = _mm_movelh_ps(v28, v30);
      v36 = (__m128)*v31;
      v14 = (const float *)((char *)v32 + v7);
      v16 = (const float *)((char *)v31 + v7);
      v37 = _mm_movelh_ps(v34, v36);
      v38 = _mm_shuffle_ps(v35, v37, 68);
      m_data[v15 - 1].m_vertices[0].m_quad = _mm_shuffle_ps(v33, v38, 136);
      m_data[v15 - 1].m_vertices[1].m_quad = _mm_shuffle_ps(v33, v38, 221);
      m_data[v15 - 1].m_vertices[2].m_quad = _mm_shuffle_ps(
                                               _mm_shuffle_ps(v24, v29, 238),
                                               _mm_shuffle_ps(v35, v37, 238),
                                               136);
      --v17;
    }
    while ( v17 );
  }
  LODWORD(v39) = numVertices - 4 * v13;
  if ( numVertices != 4 * v13 )
  {
    v40 = (int)v39;
    if ( (int)v39 > 0 )
    {
      v41 = &v51;
      v39 = (int)v39;
      do
      {
        v42 = (__m128)*(unsigned __int64 *)v14;
        v43 = (__m128)*((unsigned int *)v14 + 2);
        v14 = (const float *)((char *)v14 + v7);
        ++v41;
        v41[-1] = _mm_movelh_ps(v42, v43);
        --v39;
      }
      while ( v39 );
    }
    v44 = (unsigned __int64 *)((char *)v14 - (int)v7);
    if ( v40 < 4 )
    {
      v45 = &v51 + v40;
      *v45 = _mm_movelh_ps((__m128)*v44, (__m128)*((unsigned int *)v44 + 2));
      qmemcpy(&v45[1], v45, 16 * (3 - v40));
    }
    v46 = &this->m_rotatedVertices.m_data[numVertices >> 2];
    v47 = _mm_shuffle_ps(v51, v52, 68);
    v48 = _mm_shuffle_ps(v53, v54, 68);
    v46->m_vertices[2].m_quad = _mm_shuffle_ps(_mm_shuffle_ps(v51, v52, 238), _mm_shuffle_ps(v53, v54, 238), 136);
    v46->m_vertices[0].m_quad = _mm_shuffle_ps(v47, v48, 136);
    v46->m_vertices[1].m_quad = _mm_shuffle_ps(v47, v48, 221);
  }
  hkAabbUtil::calcAabb(vertexIn, numVertices, v7, &aabbOut);
  v49 = _mm_add_ps(aabbOut.m_min.m_quad, aabbOut.m_max.m_quad);
  this->m_aabbHalfExtents.m_quad = _mm_mul_ps(
                                     _mm_sub_ps(aabbOut.m_max.m_quad, aabbOut.m_min.m_quad),
                                     (__m128)xmmword_141A711B0);
  this->m_aabbCenter.m_quad = _mm_mul_ps(v49, (__m128)xmmword_141A711B0);
}

// File Line: 258
// RVA: 0xD07D10
void __fastcall hkpConvexVerticesShape::getFirstVertex(hkpConvexVerticesShape *this, hkVector4f *v)
{
  v->m_quad = _mm_shuffle_ps(
                _mm_shuffle_ps(
                  this->m_rotatedVertices.m_data->m_vertices[0].m_quad,
                  this->m_rotatedVertices.m_data->m_vertices[1].m_quad,
                  68),
                _mm_shuffle_ps(this->m_rotatedVertices.m_data->m_vertices[2].m_quad, (__m128)0i64, 68),
                136);
}

// File Line: 266
// RVA: 0xD083C0
hkSphere *__fastcall hkpConvexVerticesShape::getCollisionSpheres(hkpConvexVerticesShape *this, hkSphere *sphereBuffer)
{
  hkFourTransposedPointsf *m_data; // r10
  int v3; // r8d
  hkSphere *v4; // r9
  __m128 v5; // xmm5
  unsigned __int64 v6; // rcx
  __m128 m_quad; // xmm4
  __m128 v8; // xmm3
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm0
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  int v20; // r8d

  m_data = this->m_rotatedVertices.m_data;
  v3 = this->m_numVertices - 1;
  v4 = sphereBuffer;
  v5 = _mm_shuffle_ps((__m128)LODWORD(this->m_radius), (__m128)LODWORD(this->m_radius), 0);
  if ( v3 >= 3 )
  {
    v6 = (unsigned __int64)(unsigned int)this->m_numVertices >> 2;
    v3 -= 4 * ((unsigned int)(v3 + 1) >> 2);
    do
    {
      m_quad = m_data->m_vertices[0].m_quad;
      v8 = m_data->m_vertices[2].m_quad;
      v4 += 4;
      ++m_data;
      v9 = m_quad;
      v10 = v8;
      v11 = _mm_shuffle_ps(m_quad, m_data[-1].m_vertices[1].m_quad, 238);
      v12 = _mm_shuffle_ps(v8, v5, 238);
      v13 = _mm_shuffle_ps(v9, m_data[-1].m_vertices[1].m_quad, 68);
      v14 = _mm_shuffle_ps(v10, v5, 68);
      v4[-4].m_pos.m_quad = _mm_shuffle_ps(v13, v14, 136);
      v4[-3].m_pos.m_quad = _mm_shuffle_ps(v13, v14, 221);
      v4[-2].m_pos.m_quad = _mm_shuffle_ps(v11, v12, 136);
      v4[-1].m_pos.m_quad = _mm_shuffle_ps(v11, v12, 221);
      --v6;
    }
    while ( v6 );
  }
  if ( v3 >= 0 )
  {
    v15 = _mm_shuffle_ps(m_data->m_vertices[0].m_quad, m_data->m_vertices[1].m_quad, 238);
    v16 = _mm_shuffle_ps(m_data->m_vertices[0].m_quad, m_data->m_vertices[1].m_quad, 68);
    v17 = _mm_shuffle_ps(m_data->m_vertices[2].m_quad, v5, 68);
    v18 = _mm_shuffle_ps(v16, v17, 136);
    v19 = _mm_shuffle_ps(v16, v17, 221);
    if ( !v3 )
    {
LABEL_10:
      *v4 = (hkSphere)v18;
      return sphereBuffer;
    }
    v20 = v3 - 1;
    if ( !v20 )
    {
LABEL_9:
      v4[1] = (hkSphere)v19;
      goto LABEL_10;
    }
    if ( v20 == 1 )
    {
      v4[2].m_pos.m_quad = _mm_shuffle_ps(v15, _mm_shuffle_ps(m_data->m_vertices[2].m_quad, v5, 238), 136);
      goto LABEL_9;
    }
  }
  return sphereBuffer;
}

// File Line: 356
// RVA: 0xD084B0
void __fastcall hkpConvexVerticesShape::getAabb(
        hkpConvexVerticesShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  hkVector4f v4; // xmm1
  __m128 v5; // xmm7
  hkVector4f v6; // xmm1
  __m128 v7; // xmm2

  v4.m_quad = (__m128)this->m_aabbHalfExtents;
  v5 = _mm_add_ps(
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(
                                  _mm_shuffle_ps(v4.m_quad, v4.m_quad, 0),
                                  localToWorld->m_rotation.m_col0.m_quad),
                       1u),
                     1u),
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(
                                  _mm_shuffle_ps(v4.m_quad, v4.m_quad, 85),
                                  localToWorld->m_rotation.m_col1.m_quad),
                       1u),
                     1u)),
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(
                                  _mm_shuffle_ps(v4.m_quad, v4.m_quad, 170),
                                  localToWorld->m_rotation.m_col2.m_quad),
                       1u),
                     1u),
           _mm_shuffle_ps(
             (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
             (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
             0)));
  v6.m_quad = (__m128)this->m_aabbCenter;
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 0), localToWorld->m_rotation.m_col0.m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 85), localToWorld->m_rotation.m_col1.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 170), localToWorld->m_rotation.m_col2.m_quad)),
         localToWorld->m_translation.m_quad);
  out->m_max.m_quad = _mm_add_ps(v7, v5);
  out->m_min.m_quad = _mm_add_ps(
                        _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v5),
                        v7);
}

// File Line: 440
// RVA: 0xD08170
void __fastcall hkpConvexVerticesShape::getSupportingVertex(
        hkpConvexVerticesShape *this,
        hkVector4f *direction,
        hkcdVertex *supportingVertexOut)
{
  __m128 m_quad; // xmm4
  hkFourTransposedPointsf *m_data; // r9
  __int64 m_size; // rcx
  __m128i v6; // xmm5
  __m128 v8; // xmm7
  __m128 v9; // xmm8
  __m128 v10; // xmm4
  __m128i v11; // xmm6
  __m128 v12; // xmm3
  __m128i si128; // xmm9
  __m128 *p_m_quad; // rax
  __int64 v15; // rcx
  __m128 v16; // xmm2
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm2
  __m128i v20; // xmm1
  __m128 v21; // xmm2
  __m128i v22; // xmm0
  __m128 v23; // xmm2
  __m128i v24; // xmm1
  __m128i v25; // xmm2
  unsigned int v26; // r8d
  hkFourTransposedPointsf *v27; // rdx
  __int64 v28; // rcx

  m_quad = direction->m_quad;
  m_data = this->m_rotatedVertices.m_data;
  m_size = this->m_rotatedVertices.m_size;
  v6 = (__m128i)xmmword_141A720C0;
  v8 = _mm_shuffle_ps(m_quad, m_quad, 0);
  v9 = _mm_shuffle_ps(direction->m_quad, direction->m_quad, 85);
  v10 = _mm_shuffle_ps(m_quad, m_quad, 170);
  v11 = (__m128i)xmmword_141A720C0;
  v12 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(m_data->m_vertices[1].m_quad, v9), _mm_mul_ps(m_data->m_vertices[0].m_quad, v8)),
          _mm_mul_ps(m_data->m_vertices[2].m_quad, v10));
  if ( m_size > 1 )
  {
    si128 = _mm_load_si128((const __m128i *)&xmmword_141A720B0);
    p_m_quad = &m_data[1].m_vertices[2].m_quad;
    v15 = m_size - 1;
    do
    {
      v16 = p_m_quad[-1];
      v17 = p_m_quad[-2];
      v18 = *p_m_quad;
      v6 = _mm_add_epi32(v6, si128);
      p_m_quad += 3;
      v19 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v16, v9), _mm_mul_ps(v17, v8)), _mm_mul_ps(v18, v10));
      v20 = (__m128i)_mm_cmplt_ps(v12, v19);
      v12 = _mm_or_ps(_mm_and_ps(v19, (__m128)v20), _mm_andnot_ps((__m128)v20, v12));
      v11 = _mm_or_si128(_mm_andnot_si128(v20, v11), _mm_and_si128(v20, v6));
      --v15;
    }
    while ( v15 );
  }
  v21 = _mm_shuffle_ps(v12, v12, 57);
  v22 = (__m128i)_mm_cmplt_ps(v12, v21);
  v23 = _mm_max_ps(v21, v12);
  v24 = _mm_or_si128(_mm_and_si128(_mm_shuffle_epi32(v11, 57), v22), _mm_andnot_si128(v22, v11));
  v25 = (__m128i)_mm_cmplt_ps(v23, _mm_shuffle_ps(v23, v23, 170));
  v26 = _mm_cvtsi128_si32(_mm_or_si128(_mm_and_si128(_mm_shuffle_epi32(v24, 170), v25), _mm_andnot_si128(v25, v24)));
  v27 = &m_data[(unsigned __int64)v26 >> 2];
  v28 = v26 & 3;
  supportingVertexOut->m_quad.m128_i32[0] = v27->m_vertices[0].m_quad.m128_i32[v28];
  supportingVertexOut->m_quad.m128_i32[1] = v27->m_vertices[1].m_quad.m128_i32[v28];
  supportingVertexOut->m_quad.m128_i32[2] = v27->m_vertices[2].m_quad.m128_i32[v28];
  supportingVertexOut->m_quad.m128_i32[3] = v26 | 0x3F000000;
}

// File Line: 563
// RVA: 0xD082F0
void __fastcall hkpConvexVerticesShape::convertVertexIdsToVertices(
        hkpConvexVerticesShape *this,
        const unsigned __int16 *ids,
        int numIds,
        hkcdVertex *verticesOut)
{
  int i; // r10d
  unsigned int v7; // r8d
  hkFourTransposedPointsf *v8; // rcx
  __m128 m_quad; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __int128 v14[4]; // [rsp+0h] [rbp-48h]

  for ( i = numIds - 1; i >= 0; verticesOut[-1].m_quad.m128_i32[3] = v7 | 0x3F000000 )
  {
    v7 = *ids;
    ++verticesOut;
    ++ids;
    v8 = &this->m_rotatedVertices.m_data[(__int64)v7 >> 2];
    --i;
    m_quad = v8->m_vertices[2].m_quad;
    v10 = _mm_shuffle_ps(v8->m_vertices[0].m_quad, v8->m_vertices[1].m_quad, 238);
    v11 = _mm_shuffle_ps(m_quad, (__m128)0i64, 238);
    v12 = _mm_shuffle_ps(v8->m_vertices[0].m_quad, v8->m_vertices[1].m_quad, 68);
    v13 = _mm_shuffle_ps(m_quad, (__m128)0i64, 68);
    v14[0] = (__int128)_mm_shuffle_ps(v12, v13, 136);
    v14[1] = (__int128)_mm_shuffle_ps(v12, v13, 221);
    v14[2] = (__int128)_mm_shuffle_ps(v10, v11, 136);
    v14[3] = (__int128)_mm_shuffle_ps(v10, v11, 221);
    verticesOut[-1] = (hkcdVertex)v14[v7 & 3];
  }
}

// File Line: 585
// RVA: 0xD083B0
void __fastcall hkpConvexVerticesShape::getCentre(hkpConvexVerticesShape *this, hkVector4f *centreOut)
{
  *centreOut = this->m_aabbCenter;
}

// File Line: 615
// RVA: 0xD08580
hkBool *__fastcall hkpConvexVerticesShape::castRay(
        hkpConvexVerticesShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *v8; // r9
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  int m_numVertices; // r8d
  hkFourTransposedPointsf *v13; // rdx
  __m128 m_radius_low; // xmm2
  __m128 v15; // xmm3
  __m128 v16; // xmm0
  hkVector4f v17; // xmm1
  hkVector4f v18; // xmm1
  hkSimdFloat32 v19; // xmm0
  hkVector4f v20; // xmm0
  __int64 v21; // rax
  _QWORD *v22; // r8
  unsigned __int64 v23; // rcx
  unsigned __int64 v24; // rax
  char m_bool; // al
  _QWORD *Value; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  _QWORD *v29; // rcx
  hkVector4f v30; // xmm4
  hkVector4f *m_data; // r10
  int m_size; // r9d
  __m128 v33; // xmm11
  __m128 si128; // xmm12
  __m128 v35; // xmm5
  __m128i v36; // xmm13
  __m128i v37; // xmm14
  __int64 v38; // rcx
  __m128 v39; // xmm5
  __m128 m_quad; // xmm6
  __m128i v41; // xmm15
  __m128 v42; // xmm7
  __m128 v43; // xmm8
  signed int v44; // r9d
  __m128 v45; // xmm3
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  __m128 v48; // xmm4
  __m128 v49; // xmm5
  __m128 v50; // xmm4
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  __m128 v53; // xmm10
  __m128 v54; // xmm5
  __m128 v55; // xmm10
  __m128 v56; // xmm0
  __m128 v57; // xmm1
  int v58; // edi
  __int64 v59; // rdx
  __m128 v60; // xmm4
  __m128 v61; // xmm6
  __m128 v62; // xmm2
  __m128 v63; // xmm3
  __m128 v64; // xmm2
  __m128 v65; // xmm8
  __m128 v66; // xmm5
  __m128 v67; // xmm6
  __m128 v68; // xmm3
  __m128 v69; // xmm6
  __m128 v70; // xmm1
  __m128 v71; // xmm5
  __m128 v72; // xmm0
  __m128 v73; // xmm4
  __m128 *p_m_quad; // rcx
  __m128i v75; // xmm2
  __m128i v76; // xmm3
  __m128 v77; // xmm6
  __m128 v78; // xmm8
  __m128 v79; // xmm7
  __m128 v80; // xmm9
  __m128 v81; // xmm5
  __m128 v82; // xmm0
  __m128 v83; // xmm1
  __m128 v84; // xmm2
  __m128 v85; // xmm4
  __m128 v86; // xmm3
  __m128 v87; // xmm10
  __m128 v88; // xmm2
  __m128 v89; // xmm5
  __m128 v90; // xmm10
  __m128 v91; // xmm0
  __m128 v92; // xmm1
  __m128 v93; // xmm2
  __m128 v94; // xmm4
  __m128 v95; // xmm5
  __m128 v96; // xmm3
  __m128 v97; // xmm2
  __m128 v98; // xmm6
  __m128 v99; // xmm1
  __m128 v100; // xmm0
  __m128 v101; // xmm7
  __m128 v102; // xmm6
  __m128 v103; // xmm6
  __m128i v104; // xmm5
  __m128 v105; // xmm7
  __m128i v106; // xmm4
  float v107; // xmm9_4
  __m128 v108; // xmm2
  __m128 v109; // xmm3
  __m128i v110; // xmm0
  __m128 v111; // xmm3
  __m128i v112; // xmm1
  __m128i v113; // xmm3
  hkVector4f v114; // xmm2
  int v115; // ecx
  int v116; // eax
  __int64 m_shapeKeyIndex; // rax
  _QWORD *v118; // r8
  unsigned __int64 v119; // rcx
  unsigned __int64 v120; // rax
  hkcdGsk::RayCastOutput output; // [rsp+30h] [rbp-168h] BYREF
  __m128 v123; // [rsp+50h] [rbp-148h]
  __m128i v124; // [rsp+60h] [rbp-138h]
  __m128 v125; // [rsp+70h] [rbp-128h]
  hkcdGsk::RayCastInput inputa; // [rsp+80h] [rbp-118h] BYREF
  hkBool resulta; // [rsp+1A0h] [rbp+8h] BYREF

  if ( this->m_planeEquations.m_size )
  {
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v27 = (_QWORD *)Value[1];
    if ( (unsigned __int64)v27 < Value[3] )
    {
      *v27 = "TtconvexVertCastRayPlaneEq";
      v28 = __rdtsc();
      v29 = v27 + 2;
      *((_DWORD *)v29 - 2) = v28;
      Value[1] = v29;
    }
    v30.m_quad = (__m128)input->m_from;
    m_data = this->m_planeEquations.m_data;
    m_size = this->m_planeEquations.m_size;
    v33 = g_vectorfConstants[0];
    si128 = (__m128)_mm_load_si128((const __m128i *)&xmmword_141A710D0);
    v35 = _mm_sub_ps(input->m_to.m_quad, input->m_from.m_quad);
    output.m_normalOut.m_quad = _mm_shuffle_ps(
                                  (__m128)LODWORD(results->m_hitFraction),
                                  (__m128)LODWORD(results->m_hitFraction),
                                  0);
    v36 = 0i64;
    v37 = 0i64;
    v38 = m_size - 4;
    v39 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, query.m_quad), 196), output.m_normalOut.m_quad),
            v30.m_quad);
    m_quad = m_data[v38].m_quad;
    v41 = _mm_unpacklo_epi32(
            _mm_unpacklo_epi32(_mm_cvtsi32_si128(m_size - 4), _mm_cvtsi32_si128(m_size - 4 + 2)),
            _mm_unpacklo_epi32(_mm_cvtsi32_si128(m_size - 4 + 1), _mm_cvtsi32_si128(m_size - 4 + 3)));
    v42 = m_data[v38 + 1].m_quad;
    v43 = m_data[v38 + 2].m_quad;
    v124 = (__m128i)xmmword_141A720C0;
    v44 = m_size & 0xFFFFFFFC;
    v125 = _mm_shuffle_ps(v30.m_quad, _mm_unpackhi_ps(v30.m_quad, query.m_quad), 196);
    v45 = _mm_mul_ps(v125, v43);
    v123 = _mm_shuffle_ps(v39, _mm_unpackhi_ps(v39, query.m_quad), 196);
    v46 = _mm_mul_ps(v125, m_data[v38 + 3].m_quad);
    v47 = _mm_mul_ps(v125, v42);
    v48 = _mm_mul_ps(v125, m_quad);
    v49 = _mm_shuffle_ps(v48, v47, 238);
    v50 = _mm_shuffle_ps(v48, v47, 68);
    v51 = _mm_shuffle_ps(v45, v46, 68);
    v52 = _mm_shuffle_ps(v45, v46, 238);
    v53 = _mm_add_ps(_mm_shuffle_ps(v49, v52, 221), _mm_shuffle_ps(v49, v52, 136));
    v54 = _mm_mul_ps(v123, m_quad);
    v55 = _mm_add_ps(v53, _mm_add_ps(_mm_shuffle_ps(v50, v51, 221), _mm_shuffle_ps(v50, v51, 136)));
    v56 = _mm_mul_ps(v123, v42);
    v57 = _mm_mul_ps(v123, m_data[v38 + 3].m_quad);
    v58 = 0;
    v59 = 0i64;
    v60 = _mm_shuffle_ps(v54, v56, 68);
    v61 = _mm_shuffle_ps(v54, v56, 238);
    v62 = _mm_mul_ps(v123, v43);
    v63 = _mm_shuffle_ps(v62, v57, 238);
    v64 = _mm_shuffle_ps(v62, v57, 68);
    v65 = 0i64;
    v66 = _mm_shuffle_ps(v61, v63, 136);
    v67 = _mm_shuffle_ps(v61, v63, 221);
    v68 = _mm_cmple_ps((__m128)0i64, v55);
    v69 = _mm_add_ps(_mm_add_ps(v67, v66), _mm_add_ps(_mm_shuffle_ps(v60, v64, 221), _mm_shuffle_ps(v60, v64, 136)));
    v70 = _mm_sub_ps(v55, v69);
    v71 = _mm_cmple_ps((__m128)0i64, v69);
    v72 = _mm_rcp_ps(v70);
    v73 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v70, v72)), v72), v55);
    if ( !_mm_movemask_ps(_mm_and_ps(v71, v68)) )
    {
      p_m_quad = &m_data[2].m_quad;
      while ( 1 )
      {
        v75 = (__m128i)_mm_andnot_ps(v71, _mm_and_ps(_mm_cmplt_ps(v33, v73), v68));
        v33 = _mm_or_ps(_mm_andnot_ps((__m128)v75, v33), _mm_and_ps((__m128)v75, v73));
        v36 = _mm_or_si128(_mm_and_si128(v75, v41), _mm_andnot_si128(v75, v36));
        v76 = (__m128i)_mm_andnot_ps(v68, _mm_and_ps(_mm_cmplt_ps(v73, si128), v71));
        si128 = _mm_or_ps(_mm_andnot_ps((__m128)v76, si128), _mm_and_ps((__m128)v76, v73));
        v37 = _mm_or_si128(_mm_and_si128(v76, v41), _mm_andnot_si128(v76, v37));
        if ( v59 >= v44 )
          break;
        v77 = p_m_quad[-2];
        v78 = *p_m_quad;
        v59 += 4i64;
        v79 = p_m_quad[-1];
        v80 = p_m_quad[1];
        v41 = v124;
        p_m_quad += 4;
        v81 = _mm_mul_ps(v125, v77);
        v124 = _mm_add_epi32(_mm_load_si128((const __m128i *)&_xmm), v124);
        v82 = _mm_mul_ps(v125, v79);
        v83 = _mm_mul_ps(v125, v80);
        v84 = _mm_mul_ps(v125, v78);
        v85 = _mm_shuffle_ps(v81, v82, 68);
        v86 = _mm_shuffle_ps(v84, v83, 238);
        v87 = _mm_shuffle_ps(v81, v82, 238);
        v88 = _mm_shuffle_ps(v84, v83, 68);
        v89 = _mm_mul_ps(v123, v77);
        v90 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v87, v86, 221), _mm_shuffle_ps(v87, v86, 136)),
                _mm_add_ps(_mm_shuffle_ps(v85, v88, 221), _mm_shuffle_ps(v85, v88, 136)));
        v91 = _mm_mul_ps(v123, v79);
        v92 = _mm_mul_ps(v123, v80);
        v93 = _mm_mul_ps(v123, v78);
        v94 = _mm_shuffle_ps(v89, v91, 68);
        v95 = _mm_shuffle_ps(v89, v91, 238);
        v96 = _mm_shuffle_ps(v93, v92, 238);
        v97 = _mm_shuffle_ps(v93, v92, 68);
        v65 = 0i64;
        v98 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v95, v96, 221), _mm_shuffle_ps(v95, v96, 136)),
                _mm_add_ps(_mm_shuffle_ps(v94, v97, 221), _mm_shuffle_ps(v94, v97, 136)));
        v68 = _mm_cmple_ps((__m128)0i64, v90);
        v99 = _mm_sub_ps(v90, v98);
        v71 = _mm_cmple_ps((__m128)0i64, v98);
        v100 = _mm_rcp_ps(v99);
        v73 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v99, v100)), v100), v90);
        if ( _mm_movemask_ps(_mm_and_ps(v71, v68)) )
          goto LABEL_18;
      }
      v101 = _mm_min_ps(_mm_shuffle_ps(si128, si128, 78), si128);
      v102 = _mm_max_ps(_mm_shuffle_ps(v33, v33, 78), v33);
      v103 = _mm_max_ps(v102, _mm_shuffle_ps(v102, v102, 177));
      v104 = (__m128i)_mm_and_ps(_mm_cmplt_ps(v103, v65), *(__m128 *)hkVector4fComparison_maskToComparison_346);
      v105 = _mm_min_ps(v101, _mm_shuffle_ps(v101, v101, 177));
      v106 = _mm_or_si128(_mm_and_si128(v104, v37), _mm_andnot_si128(v104, v36));
      v107 = output.m_normalOut.m_quad.m128_f32[0]
           * COERCE_FLOAT(_mm_andnot_ps((__m128)v104, v103).m128_u32[0] | v104.m128i_i32[0] & v105.m128_i32[0]);
      v108 = _mm_or_ps(
               _mm_and_ps(
                 _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), si128),
                 (__m128)v104),
               _mm_andnot_ps((__m128)v104, v33));
      v109 = _mm_shuffle_ps(v108, v108, 57);
      v110 = (__m128i)_mm_cmple_ps(v108, v109);
      v111 = _mm_max_ps(v109, v108);
      v112 = _mm_or_si128(_mm_and_si128(_mm_shuffle_epi32(v106, 57), v110), _mm_andnot_si128(v110, v106));
      v113 = (__m128i)_mm_cmple_ps(v111, _mm_shuffle_ps(v111, v111, 170));
      v114.m_quad = (__m128)m_data[_mm_cvtsi128_si32(
                                     _mm_or_si128(
                                       _mm_and_si128(_mm_shuffle_epi32(v112, 170), v113),
                                       _mm_andnot_si128(v113, v112)))];
      v115 = _mm_movemask_ps(
               _mm_or_ps(
                 _mm_andnot_ps((__m128)v104, _mm_and_ps(_mm_cmple_ps(v103, v105), _mm_cmple_ps(v65, v103))),
                 _mm_and_ps(_mm_cmpneq_ps(v105, (__m128)xmmword_141A710D0), (__m128)v104)));
      v116 = v115 * _mm_movemask_ps((__m128)v104);
      v58 = v115 | (16 * v116) | v116 & 0xF0;
      if ( v58 )
      {
        m_shapeKeyIndex = results->m_shapeKeyIndex;
        results->m_hitFraction = v107;
        results->m_normal = (hkVector4f)v114.m_quad;
        results->m_shapeKeys[m_shapeKeyIndex] = -1;
      }
    }
LABEL_18:
    v118 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v119 = v118[1];
    if ( v119 < v118[3] )
    {
      *(_QWORD *)v119 = "Et";
      v120 = __rdtsc();
      *(_DWORD *)(v119 + 8) = v120;
      v118[1] = v119 + 16;
    }
    m_bool = v58 != 0;
  }
  else
  {
    v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v9 = (_QWORD *)v8[1];
    if ( (unsigned __int64)v9 < v8[3] )
    {
      *v9 = "TtconvexVertCastRayGSK";
      v10 = __rdtsc();
      v11 = v9 + 2;
      *((_DWORD *)v11 - 2) = v10;
      v8[1] = v11;
    }
    m_numVertices = this->m_numVertices;
    v13 = this->m_rotatedVertices.m_data;
    m_radius_low = (__m128)LODWORD(this->m_radius);
    v15 = _mm_unpacklo_ps(m_radius_low, (__m128)0i64);
    inputa.m_aTb.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
    m_radius_low.m128_f32[0] = (float)(m_radius_low.m128_f32[0] + 0.001) * (float)(m_radius_low.m128_f32[0] + 0.001);
    inputa.m_aTb.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    v16 = input->m_from.m_quad;
    inputa.m_aTb.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    v17.m_quad = (__m128)input->m_to;
    inputa.m_from.m_quad = v16;
    v18.m_quad = _mm_sub_ps(v17.m_quad, v16);
    v19.m_real = _mm_shuffle_ps((__m128)LODWORD(results->m_hitFraction), (__m128)LODWORD(results->m_hitFraction), 0);
    inputa.m_data.m_quad = _mm_unpacklo_ps(v15, _mm_unpacklo_ps(m_radius_low, (__m128)0i64));
    inputa.m_aTb.m_translation = 0i64;
    output.m_fractionInOut = (hkSimdFloat32)v19.m_real;
    inputa.m_direction = (hkVector4f)v18.m_quad;
    output.m_normalOut = 0i64;
    hkcdGsk::rayCast(&resulta, v13, m_numVertices, &inputa, &output);
    if ( resulta.m_bool )
    {
      v20.m_quad = (__m128)output.m_normalOut;
      v21 = results->m_shapeKeyIndex;
      LODWORD(results->m_hitFraction) = output.m_fractionInOut.m_real.m128_i32[0];
      results->m_normal = (hkVector4f)v20.m_quad;
      results->m_shapeKeys[v21] = -1;
    }
    v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v23 = v22[1];
    if ( v23 < v22[3] )
    {
      *(_QWORD *)v23 = "Et";
      v24 = __rdtsc();
      *(_DWORD *)(v23 + 8) = v24;
      v22[1] = v23 + 16;
    }
    m_bool = resulta.m_bool;
  }
  result->m_bool = m_bool;
  return result;
}

// File Line: 709
// RVA: 0xD076A0
hkArray<hkVector4f,hkContainerHeapAllocator> *__fastcall hkpConvexVerticesShape::getPlaneEquations(
        hkpConvexVerticesShape *this)
{
  return &this->m_planeEquations;
}

// File Line: 714
// RVA: 0xD076B0
void __fastcall hkpConvexVerticesShape::setPlaneEquations(
        hkpConvexVerticesShape *this,
        hkArray<hkVector4f,hkContainerHeapAllocator> *planes)
{
  __int64 m_size; // rcx
  hkVector4f *m_data; // rax
  __int64 v6; // rdx
  char *v7; // r8
  hkVector4f v8; // xmm0
  int v9; // [rsp+30h] [rbp+8h] BYREF

  if ( (this->m_planeEquations.m_capacityAndFlags & 0x3FFFFFFF) < planes->m_size )
  {
    if ( this->m_planeEquations.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_planeEquations.m_data,
        16 * this->m_planeEquations.m_capacityAndFlags);
    v9 = 16 * planes->m_size;
    this->m_planeEquations.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                    &hkContainerHeapAllocator::s_alloc,
                                                    &v9);
    this->m_planeEquations.m_capacityAndFlags = v9 / 16;
  }
  m_size = planes->m_size;
  m_data = this->m_planeEquations.m_data;
  this->m_planeEquations.m_size = m_size;
  v6 = m_size;
  if ( (int)m_size > 0 )
  {
    v7 = (char *)((char *)planes->m_data - (char *)m_data);
    do
    {
      v8.m_quad = *(__m128 *)((char *)m_data++ + (_QWORD)v7);
      m_data[-1] = (hkVector4f)v8.m_quad;
      --v6;
    }
    while ( v6 );
  }
  if ( this->m_connectivity )
    hkpConvexVerticesShape::sortPlanes(this);
}

// File Line: 738
// RVA: 0xD07780
void __fastcall hkpConvexVerticesShape::transformVerticesAndPlaneEquations(
        hkpConvexVerticesShape *this,
        hkTransformf *t)
{
  int v4; // ebx
  hkLifoAllocator *Value; // rcx
  hkVector4f *m_cur; // rax
  int v7; // edx
  char *v8; // r8
  hkVector4f v9; // xmm3
  hkVector4f v10; // xmm4
  hkVector4f v11; // xmm5
  __int64 v12; // rcx
  hkVector4f *v13; // rax
  hkVector4f v14; // xmm6
  __m128 m_quad; // xmm1
  hkVector4f *m_data; // rax
  hkVector4f v17; // xmm6
  hkVector4f v18; // xmm7
  hkVector4f v19; // xmm8
  hkVector4f *v20; // rcx
  __m128 v21; // xmm1
  int v22; // edx
  __m128 v23; // xmm2
  __m128 v24; // xmm4
  __m128 v25; // xmm5
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  __m128 v30; // xmm3
  int m_size; // eax
  char *v32; // rdi
  signed int v33; // ebx
  hkLifoAllocator *v34; // rax
  int v35; // r8d
  hkArray<hkVector4f,hkContainerHeapAllocator> vertices; // [rsp+20h] [rbp-58h] BYREF
  void *p; // [rsp+30h] [rbp-48h]
  int v38; // [rsp+38h] [rbp-40h]

  v4 = ((__int64 (__fastcall *)(hkpConvexVerticesShape *))this->vfptr[5].__first_virtual_table_function__)(this);
  vertices.m_data = 0i64;
  vertices.m_size = 0;
  vertices.m_capacityAndFlags = 0x80000000;
  v38 = v4;
  if ( v4 )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkVector4f *)Value->m_cur;
    v7 = (16 * v4 + 127) & 0xFFFFFF80;
    v8 = (char *)m_cur + v7;
    if ( v7 > Value->m_slabSize || v8 > Value->m_end )
      m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, v7);
    else
      Value->m_cur = v8;
  }
  else
  {
    m_cur = 0i64;
  }
  vertices.m_data = m_cur;
  p = m_cur;
  vertices.m_capacityAndFlags = v4 | 0x80000000;
  hkpConvexVerticesShape::getOriginalVertices(this, &vertices);
  v9.m_quad = (__m128)t->m_rotation.m_col0;
  v10.m_quad = (__m128)t->m_rotation.m_col1;
  v11.m_quad = (__m128)t->m_rotation.m_col2;
  v12 = vertices.m_size - 1;
  v13 = &vertices.m_data[v12];
  v14.m_quad = (__m128)t->m_translation;
  do
  {
    m_quad = v13->m_quad;
    --v13;
    --v12;
    v13[1].m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), v10.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 0), v9.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v11.m_quad)),
                      v14.m_quad);
  }
  while ( v12 >= 0 );
  hkpConvexVerticesShape::copyVertexData(this, vertices.m_data->m_quad.m128_f32, 16, vertices.m_size);
  m_data = this->m_planeEquations.m_data;
  v17.m_quad = (__m128)t->m_rotation.m_col2;
  v18.m_quad = (__m128)t->m_rotation.m_col0;
  v19.m_quad = (__m128)t->m_rotation.m_col1;
  v20 = m_data;
  v21 = _mm_unpacklo_ps(t->m_rotation.m_col0.m_quad, v19.m_quad);
  v22 = this->m_planeEquations.m_size - 1;
  v23 = _mm_movelh_ps(v21, v17.m_quad);
  v24 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), t->m_translation.m_quad);
  v25 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(_mm_movehl_ps(v23, v21), v17.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v23)),
          _mm_mul_ps(
            _mm_shuffle_ps(_mm_unpackhi_ps(t->m_rotation.m_col0.m_quad, v19.m_quad), v17.m_quad, 228),
            _mm_shuffle_ps(v24, v24, 170)));
  do
  {
    v26 = v20->m_quad;
    ++m_data;
    ++v20;
    --v22;
    v27 = _mm_mul_ps(v26, v25);
    v28 = _mm_shuffle_ps(v27, _mm_unpackhi_ps(v27, v26), 196);
    v29 = _mm_add_ps(_mm_shuffle_ps(v28, v28, 78), v28);
    v30 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), v19.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v18.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v17.m_quad));
    m_data[-1].m_quad = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, _mm_add_ps(_mm_shuffle_ps(v29, v29, 177), v29)), 196);
  }
  while ( v22 >= 0 );
  m_size = vertices.m_size;
  v32 = (char *)p;
  if ( p == vertices.m_data )
    m_size = 0;
  vertices.m_size = m_size;
  v33 = (16 * v38 + 127) & 0xFFFFFF80;
  v34 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v35 = (v33 + 15) & 0xFFFFFFF0;
  if ( v33 > v34->m_slabSize || &v32[v35] != v34->m_cur || v34->m_firstNonLifoEnd == v32 )
    hkLifoAllocator::slowBlockFree(v34, v32, v35);
  else
    v34->m_cur = v32;
  vertices.m_size = 0;
  if ( vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      vertices.m_data,
      16 * vertices.m_capacityAndFlags);
}

// File Line: 758
// RVA: 0xD07D40
void __fastcall hkpConvexVerticesShape::sortPlanes(hkpConvexVerticesShape *this)
{
  int m_size; // eax
  hkVector4f *v3; // rsi
  int v4; // r15d
  __int64 numtoinsert; // rbx
  __int64 v6; // rdx
  hkVector4f *v7; // rcx
  char *v8; // r8
  hkVector4f v9; // xmm0
  int m_numVertices; // r14d
  hkLifoAllocator *Value; // rcx
  hkVector4f *m_cur; // rax
  int v13; // edx
  char *v14; // r8
  __int64 v15; // r10
  int v16; // r12d
  int i; // r11d
  hkpConvexVerticesConnectivity *m_connectivity; // rdx
  unsigned int v19; // r14d
  unsigned __int16 *m_data; // rax
  __int64 v21; // rcx
  __m128 m_quad; // xmm0
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm5
  __m128 v26; // xmm5
  __m128 v27; // xmm1
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm4
  __m128 v31; // xmm6
  int v32; // eax
  int v33; // r9d
  __int64 v34; // r8
  __int64 v35; // rcx
  __m128 v36; // xmm1
  float v37; // xmm3_4
  __m128 *p_m_quad; // rdx
  __m128 v39; // xmm1
  float v40; // xmm2_4
  hkVector4f *v41; // rcx
  __int64 v42; // rdx
  __int64 v43; // r8
  unsigned __int64 v44; // rax
  int v45; // eax
  char *v46; // rdi
  signed int v47; // ebx
  hkLifoAllocator *v48; // rax
  int v49; // r8d
  hkArray<hkVector4f,hkContainerHeapAllocator> vertices; // [rsp+30h] [rbp-58h] BYREF
  void *p; // [rsp+40h] [rbp-48h]
  int v52; // [rsp+48h] [rbp-40h]
  int v53; // [rsp+90h] [rbp+8h] BYREF

  m_size = this->m_planeEquations.m_size;
  v3 = 0i64;
  v4 = 0x80000000;
  if ( m_size > 0 )
  {
    v53 = 16 * m_size;
    v3 = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v53);
    v4 = v53 / 16;
  }
  numtoinsert = this->m_planeEquations.m_size;
  v6 = numtoinsert;
  if ( (int)numtoinsert > 0 )
  {
    v7 = v3;
    v8 = (char *)((char *)this->m_planeEquations.m_data - (char *)v3);
    do
    {
      v9.m_quad = *(__m128 *)((char *)v7++ + (_QWORD)v8);
      v7[-1] = (hkVector4f)v9.m_quad;
      --v6;
    }
    while ( v6 );
  }
  m_numVertices = this->m_numVertices;
  this->m_planeEquations.m_size = 0;
  vertices.m_data = 0i64;
  vertices.m_size = 0;
  vertices.m_capacityAndFlags = 0x80000000;
  v52 = m_numVertices;
  if ( m_numVertices )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkVector4f *)Value->m_cur;
    v13 = (16 * m_numVertices + 127) & 0xFFFFFF80;
    v14 = (char *)m_cur + v13;
    if ( v13 > Value->m_slabSize || v14 > Value->m_end )
      m_cur = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(Value, v13);
    else
      Value->m_cur = v14;
  }
  else
  {
    m_cur = 0i64;
  }
  vertices.m_data = m_cur;
  p = m_cur;
  vertices.m_capacityAndFlags = m_numVertices | 0x80000000;
  hkpConvexVerticesShape::getOriginalVertices(this, &vertices);
  v15 = 0i64;
  v16 = 0;
  for ( i = 0; i < this->m_connectivity->m_numVerticesPerFace.m_size; ++v15 )
  {
    if ( !(_DWORD)numtoinsert )
      break;
    m_connectivity = this->m_connectivity;
    v19 = (unsigned __int8)m_connectivity->m_numVerticesPerFace.m_data[v15];
    if ( v19 >= 3 )
    {
      m_data = m_connectivity->m_vertexIndices.m_data;
      v21 = v16;
      v16 += v19;
      m_quad = vertices.m_data[m_data[v21]].m_quad;
      v23 = _mm_sub_ps(vertices.m_data[m_data[v21 + 1]].m_quad, m_quad);
      v24 = _mm_sub_ps(vertices.m_data[m_data[v21 + 2]].m_quad, m_quad);
      v25 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v23), _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v24));
      v26 = _mm_shuffle_ps(v25, v25, 201);
      v27 = _mm_mul_ps(v26, v26);
      v28 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
              _mm_shuffle_ps(v27, v27, 170));
      v29 = _mm_rsqrt_ps(v28);
      v30 = _mm_cmplt_ps(_mm_sub_ps((__m128)0i64, v28), (__m128)0i64);
      v31 = _mm_or_ps(
              _mm_and_ps(
                _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmple_ps(v28, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v29, v28), v29)),
                      _mm_mul_ps(*(__m128 *)_xmm, v29))),
                  v26),
                v30),
              _mm_andnot_ps(v30, v26));
      if ( _mm_movemask_ps(v30) )
      {
        v32 = 1;
        v33 = 0;
        v34 = 0i64;
        v35 = 1i64;
        v36 = _mm_mul_ps(v31, v3->m_quad);
        v37 = (float)(_mm_shuffle_ps(v36, v36, 85).m128_f32[0] + _mm_shuffle_ps(v36, v36, 0).m128_f32[0])
            + _mm_shuffle_ps(v36, v36, 170).m128_f32[0];
        if ( (int)numtoinsert > 1 )
        {
          p_m_quad = &v3[1].m_quad;
          do
          {
            v39 = _mm_mul_ps(v31, *p_m_quad);
            v40 = (float)(_mm_shuffle_ps(v39, v39, 85).m128_f32[0] + _mm_shuffle_ps(v39, v39, 0).m128_f32[0])
                + _mm_shuffle_ps(v39, v39, 170).m128_f32[0];
            if ( v40 > v37 )
            {
              v37 = v40;
              v33 = v32;
              v34 = v35;
            }
            ++v32;
            ++v35;
            ++p_m_quad;
          }
          while ( v32 < (int)numtoinsert );
        }
        LODWORD(numtoinsert) = numtoinsert - 1;
        v41 = &v3[v34];
        this->m_planeEquations.m_data[this->m_planeEquations.m_size++] = (hkVector4f)v41->m_quad;
        if ( (_DWORD)numtoinsert != v33 )
        {
          v42 = 2i64;
          v43 = 16i64 * (int)numtoinsert - 16 * v34;
          do
          {
            v44 = *(unsigned __int64 *)((char *)v41->m_quad.m128_u64 + v43);
            v41 = (hkVector4f *)((char *)v41 + 8);
            v41[-1].m_quad.m128_u64[1] = v44;
            --v42;
          }
          while ( v42 );
        }
      }
      else
      {
        this->m_planeEquations.m_data[this->m_planeEquations.m_size++] = (hkVector4f)v3->m_quad;
      }
    }
    ++i;
  }
  if ( (int)numtoinsert > 0 )
    hkArrayBase<hkVector4f>::_insertAt(
      &this->m_planeEquations,
      &hkContainerHeapAllocator::s_alloc,
      this->m_planeEquations.m_size,
      v3,
      numtoinsert);
  v45 = vertices.m_size;
  v46 = (char *)p;
  if ( p == vertices.m_data )
    v45 = 0;
  vertices.m_size = v45;
  v47 = (16 * v52 + 127) & 0xFFFFFF80;
  v48 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v49 = (v47 + 15) & 0xFFFFFFF0;
  if ( v47 > v48->m_slabSize || &v46[v49] != v48->m_cur || v48->m_firstNonLifoEnd == v46 )
    hkLifoAllocator::slowBlockFree(v48, v46, v49);
  else
    v48->m_cur = v46;
  vertices.m_size = 0;
  if ( vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      vertices.m_data,
      16 * vertices.m_capacityAndFlags);
  vertices.m_data = 0i64;
  vertices.m_capacityAndFlags = 0x80000000;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v3, 16 * v4);
}

