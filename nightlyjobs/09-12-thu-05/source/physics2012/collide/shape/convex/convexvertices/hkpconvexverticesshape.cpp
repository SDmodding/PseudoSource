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
  this->m_rotatedVertices.m_capacityAndFlags = 2147483648;
  this->m_useSpuBuffer.m_bool = 0;
  this->m_planeEquations.m_data = 0i64;
  this->m_planeEquations.m_size = 0;
  this->m_planeEquations.m_capacityAndFlags = 2147483648;
  this->m_connectivity = 0i64;
}

// File Line: 86
// RVA: 0xD072E0
void __fastcall hkpConvexVerticesShape::hkpConvexVerticesShape(hkpConvexVerticesShape *this, hkStridedVertices *vertsIn, hkArray<hkVector4f,hkContainerHeapAllocator> *planeEquations, float radius)
{
  hkpConvexVerticesShape *v4; // rbx
  hkArray<hkVector4f,hkContainerHeapAllocator> *v5; // rsi
  int v6; // eax
  hkStridedVertices *v7; // rdi
  __int64 v8; // rax
  hkVector4f *v9; // rcx
  __int64 v10; // rdx
  char *v11; // r8
  hkVector4f v12; // xmm0
  int v13; // [rsp+48h] [rbp+20h]

  v4 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1029;
  v5 = planeEquations;
  this->m_radius = radius;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexVerticesShape::`vftable;
  this->m_rotatedVertices.m_data = 0i64;
  this->m_rotatedVertices.m_size = 0;
  this->m_rotatedVertices.m_capacityAndFlags = 2147483648;
  this->m_useSpuBuffer.m_bool = 0;
  this->m_planeEquations.m_data = 0i64;
  this->m_planeEquations.m_size = 0;
  this->m_planeEquations.m_capacityAndFlags = 2147483648;
  this->m_connectivity = 0i64;
  v6 = this->m_planeEquations.m_capacityAndFlags;
  v7 = vertsIn;
  if ( (v6 & 0x3FFFFFFF) < planeEquations->m_size )
  {
    if ( v6 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        0i64,
        16 * v6);
    v13 = 16 * v5->m_size;
    v4->m_planeEquations.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                  &v13);
    v4->m_planeEquations.m_capacityAndFlags = v13 / 16;
  }
  v8 = v5->m_size;
  v9 = v4->m_planeEquations.m_data;
  v4->m_planeEquations.m_size = v8;
  v10 = v8;
  if ( (signed int)v8 > 0 )
  {
    v11 = (char *)((char *)v5->m_data - (char *)v9);
    do
    {
      v12.m_quad = *(__m128 *)((char *)v9 + (_QWORD)v11);
      ++v9;
      v9[-1] = (hkVector4f)v12.m_quad;
      --v10;
    }
    while ( v10 );
  }
  hkpConvexVerticesShape::copyVertexData(v4, v7->m_vertices, v7->m_striding, v7->m_numVertices);
}

// File Line: 107
// RVA: 0xD07400
void __fastcall hkpConvexVerticesShape::hkpConvexVerticesShape(hkpConvexVerticesShape *this, hkFourTransposedPointsf *rotatedVertices, int numVertices, hkVector4f *planes, int numPlanes, hkAabb *aabb, float radius)
{
  int v7; // eax
  hkAabb *v8; // rax
  hkVector4f v9; // xmm0
  hkVector4f v10; // xmm1

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1029;
  this->m_radius = radius;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexVerticesShape::`vftable;
  this->m_userData = 0i64;
  this->m_rotatedVertices.m_data = rotatedVertices;
  v7 = (signed int)((numVertices + 3) & 0xFFFFFFFC) / 4;
  this->m_rotatedVertices.m_size = v7;
  this->m_rotatedVertices.m_capacityAndFlags = v7 | 0x80000000;
  this->m_numVertices = numVertices;
  this->m_useSpuBuffer.m_bool = 0;
  this->m_planeEquations.m_size = numPlanes;
  this->m_planeEquations.m_data = planes;
  this->m_planeEquations.m_capacityAndFlags = numPlanes | 0x80000000;
  v8 = aabb;
  this->m_connectivity = 0i64;
  v9.m_quad = _mm_sub_ps(v8->m_max.m_quad, v8->m_min.m_quad);
  this->m_aabbHalfExtents = (hkVector4f)v9.m_quad;
  this->m_aabbHalfExtents.m_quad = _mm_mul_ps(v9.m_quad, (__m128)xmmword_141A711B0);
  v10.m_quad = _mm_add_ps(v8->m_min.m_quad, v8->m_max.m_quad);
  this->m_aabbCenter = (hkVector4f)v10.m_quad;
  this->m_aabbCenter.m_quad = _mm_mul_ps(v10.m_quad, (__m128)xmmword_141A711B0);
}

// File Line: 151
// RVA: 0xD07500
void __fastcall hkpConvexVerticesShape::hkpConvexVerticesShape(hkpConvexVerticesShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpConvexVerticesShape *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = flag.m_finishing;
  v2 = this;
  hkpConvexShape::hkpConvexShape((hkpConvexShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpConvexVerticesShape::`vftable;
  if ( v3 )
    v2->m_type.m_storage = 5;
}

// File Line: 159
// RVA: 0xD07540
void __fastcall hkpConvexVerticesShape::~hkpConvexVerticesShape(hkpConvexVerticesShape *this)
{
  hkpConvexVerticesShape *v1; // rbx
  hkpConvexVerticesConnectivity *v2; // rcx
  int v3; // er8
  int v4; // eax

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexVerticesShape::`vftable;
  v2 = this->m_connectivity;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v3 = v1->m_planeEquations.m_capacityAndFlags;
  v1->m_planeEquations.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_planeEquations.m_data,
      16 * v3);
  v1->m_planeEquations.m_data = 0i64;
  v1->m_planeEquations.m_capacityAndFlags = 2147483648;
  v4 = v1->m_rotatedVertices.m_capacityAndFlags;
  v1->m_rotatedVertices.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_rotatedVertices.m_data,
      48 * (v4 & 0x3FFFFFFF));
  v1->m_rotatedVertices.m_data = 0i64;
  v1->m_rotatedVertices.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 168
// RVA: 0xD07CB0
void __fastcall hkpConvexVerticesShape::setConnectivity(hkpConvexVerticesShape *this, hkpConvexVerticesConnectivity *connect, bool sort)
{
  bool v3; // si
  hkpConvexVerticesConnectivity *v4; // rbx
  hkpConvexVerticesShape *v5; // rdi
  hkReferencedObject *v6; // rcx

  v3 = sort;
  v4 = connect;
  v5 = this;
  if ( connect )
    hkReferencedObject::addReference((hkReferencedObject *)&connect->vfptr);
  v6 = (hkReferencedObject *)&v5->m_connectivity->vfptr;
  if ( v6 )
    hkReferencedObject::removeReference(v6);
  v5->m_connectivity = v4;
  if ( v3 )
  {
    if ( v4 )
      hkpConvexVerticesShape::sortPlanes(v5);
  }
}

// File Line: 189
// RVA: 0xD075F0
void __fastcall hkpConvexVerticesShape::getOriginalVertices(hkpConvexVerticesShape *this, hkArray<hkVector4f,hkContainerHeapAllocator> *vertices)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v2; // rbx
  int v3; // edi
  int v4; // eax
  hkpConvexVerticesShape *v5; // rsi
  int v6; // eax
  int v7; // er9
  hkcdVertex *v8; // r8
  int v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // er9
  hkResult result; // [rsp+40h] [rbp+8h]

  v2 = vertices;
  v3 = 4 * this->m_rotatedVertices.m_size;
  v4 = vertices->m_capacityAndFlags & 0x3FFFFFFF;
  v5 = this;
  if ( v4 < v3 )
  {
    v6 = 2 * v4;
    v7 = 4 * this->m_rotatedVertices.m_size;
    if ( v3 < v6 )
      v7 = v6;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, vertices, v7, 16);
  }
  v8 = (hkcdVertex *)v2->m_data;
  v2->m_size = v3;
  hkFourTransposedPointsf::getOriginalVertices(v5->m_rotatedVertices.m_data, v5->m_numVertices, v8);
  v9 = v5->m_numVertices;
  v10 = v2->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v10 < v9 )
  {
    v11 = 2 * v10;
    v12 = v5->m_numVertices;
    if ( v9 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, v12, 16);
  }
  v2->m_size = v9;
}

// File Line: 197
// RVA: 0xD07A40
void __fastcall hkpConvexVerticesShape::copyVertexData(hkpConvexVerticesShape *this, const float *vertexIn, int byteStriding, int numVertices)
{
  const float *v4; // r13
  hkpConvexVerticesShape *v5; // r15
  int v6; // ebx
  __int64 v7; // rbp
  int v8; // ecx
  int v9; // eax
  int v10; // edi
  int v11; // ecx
  int v12; // er9
  int v13; // edi
  const float *v14; // rax
  __int64 v15; // r9
  unsigned int *v16; // rdx
  __int64 v17; // r10
  __m128 v18; // xmm6
  __m128 v19; // xmm0
  hkFourTransposedPointsf *v20; // rcx
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
  signed __int64 v40; // rdi
  __m128 *v41; // rcx
  __m128 v42; // xmm1
  __m128 v43; // xmm0
  unsigned __int64 *v44; // rax
  __m128 *v45; // rsi
  __m128 *v46; // rax
  __m128 v47; // xmm3
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  hkAabb aabbOut; // [rsp+30h] [rbp-98h]
  __m128 v51; // [rsp+50h] [rbp-78h]
  __m128 v52; // [rsp+60h] [rbp-68h]
  __m128 v53; // [rsp+70h] [rbp-58h]
  __m128 v54; // [rsp+80h] [rbp-48h]
  hkResult result; // [rsp+E8h] [rbp+20h]

  v4 = vertexIn;
  v5 = this;
  v6 = numVertices;
  v7 = byteStriding;
  this->m_numVertices = numVertices;
  v8 = this->m_rotatedVertices.m_capacityAndFlags & 0x3FFFFFFF;
  v9 = (signed int)((numVertices + 3) & 0xFFFFFFFC) / 4;
  v10 = v9;
  if ( v8 < v9 )
  {
    v11 = 2 * v8;
    v12 = (signed int)((numVertices + 3) & 0xFFFFFFFC) / 4;
    if ( v9 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v5->m_rotatedVertices,
      v12,
      48);
  }
  v5->m_rotatedVertices.m_size = v10;
  v13 = v6 >> 2;
  v14 = v4;
  if ( v6 >> 2 > 0 )
  {
    v15 = 0i64;
    v16 = (unsigned int *)(v4 + 2);
    v17 = v13;
    do
    {
      v18 = (__m128)*(unsigned __int64 *)v14;
      v19 = (__m128)*v16;
      v20 = v5->m_rotatedVertices.m_data;
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
      v16 = (unsigned int *)((char *)v31 + v7);
      v37 = _mm_movelh_ps(v34, v36);
      v38 = _mm_shuffle_ps(v35, v37, 68);
      v20[v15 - 1].m_vertices[0].m_quad = _mm_shuffle_ps(v33, v38, 136);
      *((__m128 *)&v20[v15] - 2) = _mm_shuffle_ps(v33, v38, 221);
      *((__m128 *)&v20[v15] - 1) = _mm_shuffle_ps(_mm_shuffle_ps(v24, v29, 238), _mm_shuffle_ps(v35, v37, 238), 136);
      --v17;
    }
    while ( v17 );
  }
  LODWORD(v39) = v6 - 4 * v13;
  if ( v6 != 4 * v13 )
  {
    v40 = (signed int)v39;
    if ( (signed int)v39 > 0 )
    {
      v41 = &v51;
      v39 = (signed int)v39;
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
    v44 = (unsigned __int64 *)((char *)v14 - (signed int)v7);
    if ( v40 < 4 )
    {
      v45 = &v51 + v40;
      *v45 = _mm_movelh_ps((__m128)*v44, (__m128)*((unsigned int *)v44 + 2));
      qmemcpy(&v45[1], v45, 16 * (3 - v40));
    }
    v46 = (__m128 *)&v5->m_rotatedVertices.m_data[v6 >> 2];
    v47 = _mm_shuffle_ps(v51, v52, 68);
    v48 = _mm_shuffle_ps(v53, v54, 68);
    v46[2] = _mm_shuffle_ps(_mm_shuffle_ps(v51, v52, 238), _mm_shuffle_ps(v53, v54, 238), 136);
    *v46 = _mm_shuffle_ps(v47, v48, 136);
    v46[1] = _mm_shuffle_ps(v47, v48, 221);
  }
  hkAabbUtil::calcAabb(v4, v6, (unsigned int)v7, &aabbOut);
  v49 = _mm_add_ps(aabbOut.m_min.m_quad, aabbOut.m_max.m_quad);
  v5->m_aabbHalfExtents.m_quad = _mm_mul_ps(
                                   _mm_sub_ps(aabbOut.m_max.m_quad, aabbOut.m_min.m_quad),
                                   (__m128)xmmword_141A711B0);
  v5->m_aabbCenter.m_quad = _mm_mul_ps(v49, (__m128)xmmword_141A711B0);
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
  hkFourTransposedPointsf *v2; // r10
  int v3; // er8
  hkSphere *v4; // r9
  __m128 v5; // xmm5
  unsigned __int64 v6; // rcx
  __m128 v7; // xmm4
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
  int v20; // er8

  v2 = this->m_rotatedVertices.m_data;
  v3 = this->m_numVertices - 1;
  v4 = sphereBuffer;
  v5 = _mm_shuffle_ps((__m128)LODWORD(this->m_radius), (__m128)LODWORD(this->m_radius), 0);
  if ( v3 >= 3 )
  {
    v6 = (unsigned __int64)(unsigned int)this->m_numVertices >> 2;
    v3 -= 4 * ((unsigned int)(v3 + 1) >> 2);
    do
    {
      v7 = v2->m_vertices[0].m_quad;
      v8 = v2->m_vertices[2].m_quad;
      v4 += 4;
      ++v2;
      v9 = v7;
      v10 = v8;
      v11 = _mm_shuffle_ps(v7, v2[-1].m_vertices[1].m_quad, 238);
      v12 = _mm_shuffle_ps(v8, v5, 238);
      v13 = _mm_shuffle_ps(v9, v2[-1].m_vertices[1].m_quad, 68);
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
    v15 = _mm_shuffle_ps(v2->m_vertices[0].m_quad, v2->m_vertices[1].m_quad, 238);
    v16 = _mm_shuffle_ps(v2->m_vertices[0].m_quad, v2->m_vertices[1].m_quad, 68);
    v17 = _mm_shuffle_ps(v2->m_vertices[2].m_quad, v5, 68);
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
      v4[2].m_pos.m_quad = _mm_shuffle_ps(v15, _mm_shuffle_ps(v2->m_vertices[2].m_quad, v5, 238), 136);
      goto LABEL_9;
    }
  }
  return sphereBuffer;
}

// File Line: 356
// RVA: 0xD084B0
void __fastcall hkpConvexVerticesShape::getAabb(hkpConvexVerticesShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
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
             _mm_mul_ps(
               _mm_shuffle_ps(this->m_aabbCenter.m_quad, v6.m_quad, 85),
               localToWorld->m_rotation.m_col1.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 170), localToWorld->m_rotation.m_col2.m_quad)),
         localToWorld->m_translation.m_quad);
  out->m_max.m_quad = _mm_add_ps(v7, v5);
  out->m_min.m_quad = _mm_add_ps(
                        _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v5),
                        v7);
}

// File Line: 440
// RVA: 0xD08170
void __fastcall hkpConvexVerticesShape::getSupportingVertex(hkpConvexVerticesShape *this, hkVector4f *direction, hkcdVertex *supportingVertexOut)
{
  __m128 v3; // xmm4
  hkFourTransposedPointsf *v4; // r9
  signed __int64 v5; // rcx
  __m128i v6; // xmm5
  hkcdVertex *v7; // r10
  __m128 v8; // xmm7
  __m128 v9; // xmm8
  __m128 v10; // xmm4
  __m128i v11; // xmm6
  __m128 v12; // xmm3
  __m128i v13; // xmm9
  __m128 *v14; // rax
  signed __int64 v15; // rcx
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
  unsigned int v26; // er8
  unsigned __int64 v27; // rdx
  __int64 v28; // rcx

  v3 = direction->m_quad;
  v4 = this->m_rotatedVertices.m_data;
  v5 = this->m_rotatedVertices.m_size;
  v6 = (__m128i)xmmword_141A720C0;
  v7 = supportingVertexOut;
  v8 = _mm_shuffle_ps(v3, v3, 0);
  v9 = _mm_shuffle_ps(direction->m_quad, direction->m_quad, 85);
  v10 = _mm_shuffle_ps(v3, v3, 170);
  v11 = (__m128i)xmmword_141A720C0;
  v12 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(v4->m_vertices[1].m_quad, v9), _mm_mul_ps(v4->m_vertices[0].m_quad, v8)),
          _mm_mul_ps(v4->m_vertices[2].m_quad, v10));
  if ( v5 > 1 )
  {
    v13 = _mm_load_si128((const __m128i *)&xmmword_141A720B0);
    v14 = &v4[1].m_vertices[2].m_quad;
    v15 = v5 - 1;
    do
    {
      v16 = v14[-1];
      v17 = v14[-2];
      v18 = *v14;
      v6 = _mm_add_epi32(v6, v13);
      v14 += 3;
      v19 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v16, v9), _mm_mul_ps(v17, v8)), _mm_mul_ps(v18, v10));
      v20 = (__m128i)_mm_cmpltps(v12, v19);
      v12 = _mm_or_ps(_mm_and_ps(v19, (__m128)v20), _mm_andnot_ps((__m128)v20, v12));
      v11 = _mm_or_si128(_mm_andnot_si128(v20, v11), _mm_and_si128(v20, v6));
      --v15;
    }
    while ( v15 );
  }
  v21 = _mm_shuffle_ps(v12, v12, 57);
  v22 = (__m128i)_mm_cmpltps(v12, v21);
  v23 = _mm_max_ps(v21, v12);
  v24 = _mm_or_si128(_mm_and_si128(_mm_shuffle_epi32(v11, 57), v22), _mm_andnot_si128(v22, v11));
  v25 = (__m128i)_mm_cmpltps(v23, _mm_shuffle_ps(v23, v23, 170));
  v26 = _mm_cvtsi128_si32(_mm_or_si128(_mm_and_si128(_mm_shuffle_epi32(v24, 170), v25), _mm_andnot_si128(v25, v24)));
  v27 = (unsigned __int64)&v4[(unsigned __int64)v26 >> 2];
  v28 = v26 & 3;
  v7->m_quad.m128_i32[0] = *(_DWORD *)(v27 + 4 * v28);
  v7->m_quad.m128_i32[1] = *(_DWORD *)(v27 + 4 * v28 + 16);
  v7->m_quad.m128_i32[2] = *(_DWORD *)(v27 + 4 * v28 + 32);
  v7->m_quad.m128_i32[3] = v26 | 0x3F000000;
}

// File Line: 563
// RVA: 0xD082F0
void __fastcall hkpConvexVerticesShape::convertVertexIdsToVertices(hkpConvexVerticesShape *this, const unsigned __int16 *ids, int numIds, hkcdVertex *verticesOut)
{
  int v4; // er10
  const unsigned __int16 *v5; // r11
  hkpConvexVerticesShape *i; // rbx
  unsigned int v7; // er8
  signed __int64 v8; // rcx
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // [rsp+0h] [rbp-48h]
  __m128 v16; // [rsp+10h] [rbp-38h]
  __m128 v17; // [rsp+20h] [rbp-28h]
  __m128 v18; // [rsp+30h] [rbp-18h]

  v4 = numIds - 1;
  v5 = ids;
  for ( i = this; v4 >= 0; verticesOut[-1].m_quad.m128_i32[3] = v7 | 0x3F000000 )
  {
    v7 = *v5;
    ++verticesOut;
    ++v5;
    v8 = (signed __int64)&i->m_rotatedVertices.m_data[(signed __int64)v7 >> 2];
    --v4;
    v9 = *(__m128 *)(v8 + 32);
    v10 = v9;
    v11 = _mm_shuffle_ps(*(__m128 *)v8, *(__m128 *)(v8 + 16), 238);
    v12 = _mm_shuffle_ps(v9, (__m128)0i64, 238);
    v13 = _mm_shuffle_ps(*(__m128 *)v8, *(__m128 *)(v8 + 16), 68);
    v14 = _mm_shuffle_ps(v10, (__m128)0i64, 68);
    v15 = _mm_shuffle_ps(v13, v14, 136);
    v16 = _mm_shuffle_ps(v13, v14, 221);
    v17 = _mm_shuffle_ps(v11, v12, 136);
    v18 = _mm_shuffle_ps(v11, v12, 221);
    verticesOut[-1] = *((hkcdVertex *)&v15 + (v7 & 3));
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
hkBool *__fastcall hkpConvexVerticesShape::castRay(hkpConvexVerticesShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkpConvexVerticesShape *v4; // rdi
  hkpShapeRayCastOutput *v5; // rbx
  hkpShapeRayCastInput *v6; // rbp
  hkBool *v7; // rsi
  _QWORD *v8; // r9
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 v12; // xmm3
  int v13; // er8
  hkFourTransposedPointsf *v14; // rdx
  __m128 v15; // xmm2
  hkVector4f v16; // xmm0
  __m128 v17; // xmm1
  hkVector4f v18; // xmm1
  hkSimdFloat32 v19; // xmm0
  hkVector4f v20; // xmm0
  __int64 v21; // rax
  _QWORD *v22; // r8
  unsigned __int64 v23; // rcx
  unsigned __int64 v24; // rax
  char v25; // al
  _QWORD *v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rax
  signed __int64 v29; // rcx
  __m128 v30; // xmm4
  hkVector4f *v31; // r10
  int v32; // er9
  __m128 v33; // xmm11
  __m128 v34; // xmm12
  __m128 v35; // xmm5
  __m128i v36; // xmm13
  __m128i v37; // xmm14
  __int64 v38; // rcx
  __m128 v39; // xmm5
  __m128 v40; // xmm6
  __m128i v41; // xmm15
  __m128 v42; // xmm7
  __m128 v43; // xmm8
  signed int v44; // er9
  __m128 v45; // xmm3
  __m128 v46; // xmm1
  __m128 v47; // xmm0
  __m128 v48; // xmm5
  __m128 v49; // xmm4
  __m128 v50; // xmm5
  __m128 v51; // xmm4
  __m128 v52; // xmm2
  __m128 v53; // xmm3
  __m128 v54; // xmm10
  __m128 v55; // xmm5
  __m128 v56; // xmm10
  __m128 v57; // xmm0
  __m128 v58; // xmm1
  int v59; // edi
  signed __int64 v60; // rdx
  __m128 v61; // xmm4
  __m128 v62; // xmm5
  __m128 v63; // xmm3
  __m128 v64; // xmm6
  __m128 v65; // xmm2
  __m128 v66; // xmm3
  __m128 v67; // xmm2
  __m128 v68; // xmm8
  __m128 v69; // xmm5
  __m128 v70; // xmm6
  __m128 v71; // xmm3
  __m128 v72; // xmm6
  __m128 v73; // xmm1
  __m128 v74; // xmm5
  __m128 v75; // xmm0
  __m128 v76; // xmm4
  __m128 *v77; // rcx
  __m128i v78; // xmm2
  __m128i v79; // xmm3
  __m128 v80; // xmm1
  __m128 v81; // xmm6
  __m128 v82; // xmm8
  __m128 v83; // xmm7
  __m128 v84; // xmm9
  __m128 v85; // xmm5
  __m128 v86; // xmm3
  __m128 v87; // xmm0
  __m128 v88; // xmm1
  __m128 v89; // xmm2
  __m128 v90; // xmm4
  __m128 v91; // xmm5
  __m128 v92; // xmm3
  __m128 v93; // xmm2
  __m128 v94; // xmm10
  __m128 v95; // xmm5
  __m128 v96; // xmm10
  __m128 v97; // xmm0
  __m128 v98; // xmm3
  __m128 v99; // xmm1
  __m128 v100; // xmm2
  __m128 v101; // xmm4
  __m128 v102; // xmm5
  __m128 v103; // xmm3
  __m128 v104; // xmm2
  __m128 v105; // xmm6
  __m128 v106; // xmm1
  __m128 v107; // xmm0
  __m128 v108; // xmm7
  __m128 v109; // xmm6
  __m128 v110; // xmm6
  __m128i v111; // xmm5
  __m128 v112; // xmm7
  __m128i v113; // xmm4
  float v114; // xmm9_4
  __m128 v115; // xmm2
  __m128 v116; // xmm3
  __m128i v117; // xmm0
  __m128 v118; // xmm3
  __m128i v119; // xmm1
  __m128i v120; // xmm3
  hkVector4f v121; // xmm2
  int v122; // ecx
  int v123; // eax
  __int64 v124; // rax
  _QWORD *v125; // r8
  unsigned __int64 v126; // rcx
  unsigned __int64 v127; // rax
  hkcdGsk::RayCastOutput output; // [rsp+30h] [rbp-168h]
  __m128 v130; // [rsp+50h] [rbp-148h]
  __m128i v131; // [rsp+60h] [rbp-138h]
  __m128 v132; // [rsp+70h] [rbp-128h]
  hkcdGsk::RayCastInput inputa; // [rsp+80h] [rbp-118h]
  hkBool resulta; // [rsp+1A0h] [rbp+8h]

  v4 = this;
  v5 = results;
  v6 = input;
  v7 = result;
  if ( this->m_planeEquations.m_size )
  {
    v26 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v27 = (_QWORD *)v26[1];
    if ( (unsigned __int64)v27 < v26[3] )
    {
      *v27 = "TtconvexVertCastRayPlaneEq";
      v28 = __rdtsc();
      v29 = (signed __int64)(v27 + 2);
      *(_DWORD *)(v29 - 8) = v28;
      v26[1] = v29;
    }
    v30 = v6->m_from.m_quad;
    v31 = v4->m_planeEquations.m_data;
    v32 = v4->m_planeEquations.m_size;
    v33 = g_vectorfConstants[0];
    v34 = (__m128)_mm_load_si128((const __m128i *)&xmmword_141A710D0);
    v35 = _mm_sub_ps(v6->m_to.m_quad, v6->m_from.m_quad);
    output.m_normalOut.m_quad = _mm_shuffle_ps(
                                  (__m128)LODWORD(v5->m_hitFraction),
                                  (__m128)LODWORD(v5->m_hitFraction),
                                  0);
    v36 = 0i64;
    v37 = 0i64;
    v38 = v32 - 4;
    v39 = _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v35, _mm_unpackhi_ps(v35, query.m_quad), 196), output.m_normalOut.m_quad),
            v30);
    v40 = v31[v38].m_quad;
    v41 = _mm_unpacklo_epi32(
            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v32 - 4), _mm_cvtsi32_si128(v32 - 4 + 2)),
            _mm_unpacklo_epi32(_mm_cvtsi32_si128(v32 - 4 + 1), _mm_cvtsi32_si128(v32 - 4 + 3)));
    v42 = v31[v38 + 1].m_quad;
    v43 = v31[v38 + 2].m_quad;
    _mm_store_si128(&v131, (__m128i)xmmword_141A720C0);
    v44 = v32 & 0xFFFFFFFC;
    v132 = _mm_shuffle_ps(v30, _mm_unpackhi_ps(v30, query.m_quad), 196);
    v45 = _mm_mul_ps(v132, v43);
    v130 = _mm_shuffle_ps(v39, _mm_unpackhi_ps(v39, query.m_quad), 196);
    v46 = _mm_mul_ps(v132, v31[v38 + 3].m_quad);
    v47 = _mm_mul_ps(v132, v42);
    v48 = _mm_mul_ps(v132, v40);
    v49 = v48;
    v50 = _mm_shuffle_ps(v48, v47, 238);
    v51 = _mm_shuffle_ps(v49, v47, 68);
    v52 = _mm_shuffle_ps(v45, v46, 68);
    v53 = _mm_shuffle_ps(v45, v46, 238);
    v54 = _mm_add_ps(_mm_shuffle_ps(v50, v53, 221), _mm_shuffle_ps(v50, v53, 136));
    v55 = _mm_mul_ps(v130, v40);
    v56 = _mm_add_ps(v54, _mm_add_ps(_mm_shuffle_ps(v51, v52, 221), _mm_shuffle_ps(v51, v52, 136)));
    v57 = _mm_mul_ps(v130, v42);
    v58 = _mm_mul_ps(v130, v31[v38 + 3].m_quad);
    v59 = 0;
    v60 = 0i64;
    v61 = _mm_shuffle_ps(v55, v57, 68);
    v62 = _mm_shuffle_ps(v55, v57, 238);
    v63 = _mm_mul_ps(v130, v43);
    v64 = v62;
    v65 = v63;
    v66 = _mm_shuffle_ps(v63, v58, 238);
    v67 = _mm_shuffle_ps(v65, v58, 68);
    v68 = 0i64;
    v69 = _mm_shuffle_ps(v62, v66, 136);
    v70 = _mm_shuffle_ps(v64, v66, 221);
    v71 = _mm_cmpleps((__m128)0i64, v56);
    v72 = _mm_add_ps(_mm_add_ps(v70, v69), _mm_add_ps(_mm_shuffle_ps(v61, v67, 221), _mm_shuffle_ps(v61, v67, 136)));
    v73 = _mm_sub_ps(v56, v72);
    v74 = _mm_cmpleps((__m128)0i64, v72);
    v75 = _mm_rcp_ps(v73);
    v76 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v73, v75)), v75), v56);
    if ( !_mm_movemask_ps(_mm_and_ps(v74, v71)) )
    {
      v77 = &v31[2].m_quad;
      while ( 1 )
      {
        v78 = (__m128i)_mm_andnot_ps(v74, _mm_and_ps(_mm_cmpltps(v33, v76), v71));
        v33 = _mm_or_ps(_mm_andnot_ps((__m128)v78, v33), _mm_and_ps((__m128)v78, v76));
        v36 = _mm_or_si128(_mm_and_si128(v78, v41), _mm_andnot_si128(v78, v36));
        v79 = (__m128i)_mm_andnot_ps(v71, _mm_and_ps(_mm_cmpltps(v76, v34), v74));
        v34 = _mm_or_ps(_mm_andnot_ps((__m128)v79, v34), _mm_and_ps((__m128)v79, v76));
        v37 = _mm_or_si128(_mm_and_si128(v79, v41), _mm_andnot_si128(v79, v37));
        if ( v60 >= v44 )
          break;
        v80 = v132;
        v81 = v77[-2];
        v82 = *v77;
        v60 += 4i64;
        v83 = v77[-1];
        v84 = v77[1];
        v41 = v131;
        v77 += 4;
        v85 = _mm_mul_ps(v132, v81);
        v86 = _mm_mul_ps(v132, v82);
        _mm_store_si128(&v131, _mm_add_epi32(_mm_load_si128((const __m128i *)&_xmm), v131));
        v87 = _mm_mul_ps(v80, v83);
        v88 = _mm_mul_ps(v80, v84);
        v89 = v86;
        v90 = _mm_shuffle_ps(v85, v87, 68);
        v91 = _mm_shuffle_ps(v85, v87, 238);
        v92 = _mm_shuffle_ps(v86, v88, 238);
        v93 = _mm_shuffle_ps(v89, v88, 68);
        v94 = _mm_add_ps(_mm_shuffle_ps(v91, v92, 221), _mm_shuffle_ps(v91, v92, 136));
        v95 = _mm_mul_ps(v130, v81);
        v96 = _mm_add_ps(v94, _mm_add_ps(_mm_shuffle_ps(v90, v93, 221), _mm_shuffle_ps(v90, v93, 136)));
        v97 = _mm_mul_ps(v130, v83);
        v98 = _mm_mul_ps(v130, v82);
        v99 = _mm_mul_ps(v130, v84);
        v100 = v98;
        v101 = _mm_shuffle_ps(v95, v97, 68);
        v102 = _mm_shuffle_ps(v95, v97, 238);
        v103 = _mm_shuffle_ps(v98, v99, 238);
        v104 = _mm_shuffle_ps(v100, v99, 68);
        v68 = 0i64;
        v105 = _mm_add_ps(
                 _mm_add_ps(_mm_shuffle_ps(v102, v103, 221), _mm_shuffle_ps(v102, v103, 136)),
                 _mm_add_ps(_mm_shuffle_ps(v101, v104, 221), _mm_shuffle_ps(v101, v104, 136)));
        v71 = _mm_cmpleps((__m128)0i64, v96);
        v106 = _mm_sub_ps(v96, v105);
        v74 = _mm_cmpleps((__m128)0i64, v105);
        v107 = _mm_rcp_ps(v106);
        v76 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v106, v107)), v107), v96);
        if ( _mm_movemask_ps(_mm_and_ps(v74, v71)) )
          goto LABEL_18;
      }
      v108 = _mm_min_ps(_mm_shuffle_ps(v34, v34, 78), v34);
      v109 = _mm_max_ps(_mm_shuffle_ps(v33, v33, 78), v33);
      v110 = _mm_max_ps(v109, _mm_shuffle_ps(v109, v109, 177));
      v111 = (__m128i)_mm_and_ps(_mm_cmpltps(v110, v68), *(__m128 *)hkVector4fComparison_maskToComparison_346);
      v112 = _mm_min_ps(v108, _mm_shuffle_ps(v108, v108, 177));
      v113 = _mm_or_si128(_mm_and_si128(v111, v37), _mm_andnot_si128(v111, v36));
      v114 = output.m_normalOut.m_quad.m128_f32[0]
           * COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps((__m128)v111, v110) | v111.m128i_i32[0] & v112.m128_i32[0]);
      v115 = _mm_or_ps(
               _mm_and_ps(
                 _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v34),
                 (__m128)v111),
               _mm_andnot_ps((__m128)v111, v33));
      v116 = _mm_shuffle_ps(v115, v115, 57);
      v117 = (__m128i)_mm_cmpleps(v115, v116);
      v118 = _mm_max_ps(v116, v115);
      v119 = _mm_or_si128(_mm_and_si128(_mm_shuffle_epi32(v113, 57), v117), _mm_andnot_si128(v117, v113));
      v120 = (__m128i)_mm_cmpleps(v118, _mm_shuffle_ps(v118, v118, 170));
      v121.m_quad = (__m128)v31[_mm_cvtsi128_si32(
                                  _mm_or_si128(
                                    _mm_and_si128(_mm_shuffle_epi32(v119, 170), v120),
                                    _mm_andnot_si128(v120, v119)))];
      v122 = _mm_movemask_ps(
               _mm_or_ps(
                 _mm_andnot_ps((__m128)v111, _mm_and_ps(_mm_cmpleps(v110, v112), _mm_cmpleps(v68, v110))),
                 _mm_and_ps(_mm_cmpneqps(v112, (__m128)xmmword_141A710D0), (__m128)v111)));
      v123 = v122 * _mm_movemask_ps((__m128)v111);
      v59 = v122 | 16 * v123 | v123 & 0xF0;
      if ( v59 )
      {
        v124 = v5->m_shapeKeyIndex;
        v5->m_hitFraction = v114;
        v5->m_normal = (hkVector4f)v121.m_quad;
        v5->m_shapeKeys[v124] = -1;
      }
    }
LABEL_18:
    v125 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v126 = v125[1];
    if ( v126 < v125[3] )
    {
      *(_QWORD *)v126 = "Et";
      v127 = __rdtsc();
      *(_DWORD *)(v126 + 8) = v127;
      v125[1] = v126 + 16;
    }
    v25 = v59 != 0;
  }
  else
  {
    v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v9 = (_QWORD *)v8[1];
    if ( (unsigned __int64)v9 < v8[3] )
    {
      *v9 = "TtconvexVertCastRayGSK";
      v10 = __rdtsc();
      v11 = (signed __int64)(v9 + 2);
      *(_DWORD *)(v11 - 8) = v10;
      v8[1] = v11;
    }
    v12 = (__m128)LODWORD(v4->m_radius);
    v13 = v4->m_numVertices;
    v14 = v4->m_rotatedVertices.m_data;
    v15 = (__m128)LODWORD(v4->m_radius);
    inputa.m_aTb.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
    v15.m128_f32[0] = (float)(v15.m128_f32[0] + 0.001) * (float)(v15.m128_f32[0] + 0.001);
    inputa.m_aTb.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    v16.m_quad = (__m128)v6->m_from;
    inputa.m_aTb.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    v17 = v6->m_to.m_quad;
    inputa.m_from = (hkVector4f)v16.m_quad;
    v18.m_quad = _mm_sub_ps(v17, v16.m_quad);
    v19.m_real = _mm_shuffle_ps((__m128)LODWORD(v5->m_hitFraction), (__m128)LODWORD(v5->m_hitFraction), 0);
    inputa.m_data.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v12, (__m128)0i64), _mm_unpacklo_ps(v15, (__m128)0i64));
    inputa.m_aTb.m_translation = 0i64;
    output.m_fractionInOut = (hkSimdFloat32)v19.m_real;
    inputa.m_direction = (hkVector4f)v18.m_quad;
    output.m_normalOut = 0i64;
    hkcdGsk::rayCast(&resulta, v14, v13, &inputa, &output);
    if ( resulta.m_bool )
    {
      v20.m_quad = (__m128)output.m_normalOut;
      v21 = v5->m_shapeKeyIndex;
      v5->m_hitFraction = output.m_fractionInOut.m_real.m128_f32[0];
      v5->m_normal = (hkVector4f)v20.m_quad;
      v5->m_shapeKeys[v21] = -1;
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
    v25 = resulta.m_bool;
  }
  v7->m_bool = v25;
  return v7;
}

// File Line: 709
// RVA: 0xD076A0
hkArray<hkVector4f,hkContainerHeapAllocator> *__fastcall hkpConvexVerticesShape::getPlaneEquations(hkpConvexVerticesShape *this)
{
  return &this->m_planeEquations;
}

// File Line: 714
// RVA: 0xD076B0
void __fastcall hkpConvexVerticesShape::setPlaneEquations(hkpConvexVerticesShape *this, hkArray<hkVector4f,hkContainerHeapAllocator> *planes)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v2; // rdi
  hkpConvexVerticesShape *v3; // rbx
  __int64 v4; // rcx
  hkVector4f *v5; // rax
  __int64 v6; // rdx
  char *v7; // r8
  hkVector4f v8; // xmm0
  int v9; // [rsp+30h] [rbp+8h]

  v2 = planes;
  v3 = this;
  if ( (this->m_planeEquations.m_capacityAndFlags & 0x3FFFFFFF) < planes->m_size )
  {
    if ( this->m_planeEquations.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_planeEquations.m_data,
        16 * this->m_planeEquations.m_capacityAndFlags);
    v9 = 16 * v2->m_size;
    v3->m_planeEquations.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                                  &v9);
    v3->m_planeEquations.m_capacityAndFlags = v9 / 16;
  }
  v4 = v2->m_size;
  v5 = v3->m_planeEquations.m_data;
  v3->m_planeEquations.m_size = v4;
  v6 = v4;
  if ( (signed int)v4 > 0 )
  {
    v7 = (char *)((char *)v2->m_data - (char *)v5);
    do
    {
      v8.m_quad = *(__m128 *)((char *)v5 + (_QWORD)v7);
      ++v5;
      v5[-1] = (hkVector4f)v8.m_quad;
      --v6;
    }
    while ( v6 );
  }
  if ( v3->m_connectivity )
    hkpConvexVerticesShape::sortPlanes(v3);
}

// File Line: 738
// RVA: 0xD07780
void __fastcall hkpConvexVerticesShape::transformVerticesAndPlaneEquations(hkpConvexVerticesShape *this, hkTransformf *t)
{
  hkTransformf *v2; // rdi
  hkpConvexVerticesShape *v3; // rsi
  int v4; // ebx
  LPVOID v5; // rax
  hkLifoAllocator *v6; // rcx
  hkVector4f *v7; // rax
  int v8; // edx
  char *v9; // r8
  __m128 v10; // xmm3
  __m128 v11; // xmm4
  __m128 v12; // xmm5
  __int64 v13; // rcx
  hkVector4f *v14; // rax
  __m128 v15; // xmm6
  __m128 v16; // xmm1
  hkVector4f *v17; // rax
  __m128 v18; // xmm6
  __m128 v19; // xmm7
  __m128 v20; // xmm8
  __m128 *v21; // rcx
  __m128 v22; // xmm1
  int v23; // edx
  __m128 v24; // xmm2
  __m128 v25; // xmm4
  __m128 v26; // xmm5
  __m128 v27; // xmm4
  __m128 v28; // xmm1
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  __m128 v31; // xmm3
  int v32; // eax
  char *v33; // rdi
  signed int v34; // ebx
  hkLifoAllocator *v35; // rax
  int v36; // er8
  hkArray<hkVector4f,hkContainerHeapAllocator> vertices; // [rsp+20h] [rbp-58h]
  void *p; // [rsp+30h] [rbp-48h]
  int v39; // [rsp+38h] [rbp-40h]

  v2 = t;
  v3 = this;
  v4 = ((__int64 (*)(void))this->vfptr[5].__first_virtual_table_function__)();
  vertices.m_data = 0i64;
  vertices.m_size = 0;
  vertices.m_capacityAndFlags = 2147483648;
  v39 = v4;
  if ( v4 )
  {
    v5 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (hkLifoAllocator *)v5;
    v7 = (hkVector4f *)*((_QWORD *)v5 + 3);
    v8 = (16 * v4 + 127) & 0xFFFFFF80;
    v9 = (char *)v7 + v8;
    if ( v8 > v6->m_slabSize || v9 > v6->m_end )
      v7 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v6, v8);
    else
      v6->m_cur = v9;
  }
  else
  {
    v7 = 0i64;
  }
  vertices.m_data = v7;
  p = v7;
  vertices.m_capacityAndFlags = v4 | 0x80000000;
  hkpConvexVerticesShape::getOriginalVertices(v3, &vertices);
  v10 = v2->m_rotation.m_col0.m_quad;
  v11 = v2->m_rotation.m_col1.m_quad;
  v12 = v2->m_rotation.m_col2.m_quad;
  v13 = vertices.m_size - 1;
  v14 = &vertices.m_data[v13];
  v15 = v2->m_translation.m_quad;
  do
  {
    v16 = v14->m_quad;
    --v14;
    --v13;
    v14[1].m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), v11),
                          _mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), v10)),
                        _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), v12)),
                      v15);
  }
  while ( v13 >= 0 );
  hkpConvexVerticesShape::copyVertexData(v3, vertices.m_data->m_quad.m128_f32, 16, vertices.m_size);
  v17 = v3->m_planeEquations.m_data;
  v18 = v2->m_rotation.m_col2.m_quad;
  v19 = v2->m_rotation.m_col0.m_quad;
  v20 = v2->m_rotation.m_col1.m_quad;
  v21 = &v3->m_planeEquations.m_data->m_quad;
  v22 = _mm_unpacklo_ps(v2->m_rotation.m_col0.m_quad, v20);
  v23 = v3->m_planeEquations.m_size - 1;
  v24 = _mm_movelh_ps(v22, v18);
  v25 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v2->m_translation.m_quad);
  v26 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(_mm_movehl_ps(v24, v22), v18, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v24)),
          _mm_mul_ps(
            _mm_shuffle_ps(_mm_unpackhi_ps(v2->m_rotation.m_col0.m_quad, v20), v18, 228),
            _mm_shuffle_ps(v25, v25, 170)));
  do
  {
    v27 = *v21;
    ++v17;
    ++v21;
    --v23;
    v28 = _mm_mul_ps(v27, v26);
    v29 = _mm_shuffle_ps(v28, _mm_unpackhi_ps(v28, v27), 196);
    v30 = _mm_add_ps(_mm_shuffle_ps(v29, v29, 78), v29);
    v31 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v27, v27, 85), v20), _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v19)),
            _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), v18));
    v17[-1].m_quad = _mm_shuffle_ps(v31, _mm_unpackhi_ps(v31, _mm_add_ps(_mm_shuffle_ps(v30, v30, 177), v30)), 196);
  }
  while ( v23 >= 0 );
  v32 = vertices.m_size;
  v33 = (char *)p;
  if ( p == vertices.m_data )
    v32 = 0;
  vertices.m_size = v32;
  v34 = (16 * v39 + 127) & 0xFFFFFF80;
  v35 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v36 = (v34 + 15) & 0xFFFFFFF0;
  if ( v34 > v35->m_slabSize || &v33[v36] != v35->m_cur || v35->m_firstNonLifoEnd == v33 )
    hkLifoAllocator::slowBlockFree(v35, v33, v36);
  else
    v35->m_cur = v33;
  vertices.m_size = 0;
  if ( vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      vertices.m_data,
      16 * vertices.m_capacityAndFlags);
}

// File Line: 758
// RVA: 0xD07D40
void __fastcall hkpConvexVerticesShape::sortPlanes(hkpConvexVerticesShape *this)
{
  int v1; // eax
  hkpConvexVerticesShape *v2; // rbp
  hkVector4f *v3; // rsi
  int v4; // er15
  __int64 numtoinsert; // rbx
  __int64 v6; // rdx
  hkVector4f *v7; // rcx
  signed __int64 v8; // r8
  hkVector4f v9; // xmm0
  int v10; // er14
  LPVOID v11; // rax
  hkLifoAllocator *v12; // rcx
  hkVector4f *v13; // rax
  int v14; // edx
  char *v15; // r8
  __int64 v16; // r10
  int v17; // er12
  int i; // er11
  hkpConvexVerticesConnectivity *v19; // rdx
  signed int v20; // er14
  unsigned __int16 *v21; // rax
  __int64 v22; // rcx
  __m128 v23; // xmm0
  __m128 v24; // xmm2
  __m128 v25; // xmm1
  __m128 v26; // xmm5
  __m128 v27; // xmm5
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm4
  __m128 v32; // xmm6
  signed int v33; // eax
  signed int v34; // er9
  signed __int64 v35; // r8
  signed __int64 v36; // rcx
  __m128 v37; // xmm1
  float v38; // xmm3_4
  __m128 *v39; // rdx
  __m128 v40; // xmm1
  float v41; // xmm2_4
  _OWORD *v42; // rcx
  signed __int64 v43; // rdx
  signed __int64 v44; // r8
  __int64 v45; // rax
  int v46; // eax
  char *v47; // rdi
  signed int v48; // ebx
  hkLifoAllocator *v49; // rax
  int v50; // er8
  hkArray<hkVector4f,hkContainerHeapAllocator> vertices; // [rsp+30h] [rbp-58h]
  void *p; // [rsp+40h] [rbp-48h]
  int v53; // [rsp+48h] [rbp-40h]
  int v54; // [rsp+90h] [rbp+8h]

  v1 = this->m_planeEquations.m_size;
  v2 = this;
  v3 = 0i64;
  v4 = 2147483648;
  if ( v1 > 0 )
  {
    v54 = 16 * v1;
    v3 = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                         (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                         &v54);
    v4 = v54 / 16;
  }
  numtoinsert = v2->m_planeEquations.m_size;
  v6 = numtoinsert;
  if ( (signed int)numtoinsert > 0 )
  {
    v7 = v3;
    v8 = (char *)v2->m_planeEquations.m_data - (char *)v3;
    do
    {
      v9.m_quad = *(__m128 *)((char *)v7 + v8);
      ++v7;
      v7[-1] = (hkVector4f)v9.m_quad;
      --v6;
    }
    while ( v6 );
  }
  v10 = v2->m_numVertices;
  v2->m_planeEquations.m_size = 0;
  vertices.m_data = 0i64;
  vertices.m_size = 0;
  vertices.m_capacityAndFlags = 2147483648;
  v53 = v10;
  if ( v10 )
  {
    v11 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v12 = (hkLifoAllocator *)v11;
    v13 = (hkVector4f *)*((_QWORD *)v11 + 3);
    v14 = (16 * v10 + 127) & 0xFFFFFF80;
    v15 = (char *)v13 + v14;
    if ( v14 > v12->m_slabSize || v15 > v12->m_end )
      v13 = (hkVector4f *)hkLifoAllocator::allocateFromNewSlab(v12, v14);
    else
      v12->m_cur = v15;
  }
  else
  {
    v13 = 0i64;
  }
  vertices.m_data = v13;
  p = v13;
  vertices.m_capacityAndFlags = v10 | 0x80000000;
  hkpConvexVerticesShape::getOriginalVertices(v2, &vertices);
  v16 = 0i64;
  v17 = 0;
  for ( i = 0; i < v2->m_connectivity->m_numVerticesPerFace.m_size; ++v16 )
  {
    if ( !(_DWORD)numtoinsert )
      break;
    v19 = v2->m_connectivity;
    v20 = (unsigned __int8)v19->m_numVerticesPerFace.m_data[v16];
    if ( v20 >= 3 )
    {
      v21 = v19->m_vertexIndices.m_data;
      v22 = v17;
      v17 += v20;
      v23 = vertices.m_data[v21[v22]].m_quad;
      v24 = _mm_sub_ps(vertices.m_data[v21[v22 + 1]].m_quad, v23);
      v25 = _mm_sub_ps(vertices.m_data[v21[v22 + 2]].m_quad, v23);
      v26 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v24), _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v25));
      v27 = _mm_shuffle_ps(v26, v26, 201);
      v28 = _mm_mul_ps(v27, v27);
      v29 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(v28, v28, 0)),
              _mm_shuffle_ps(v28, v28, 170));
      v30 = _mm_rsqrt_ps(v29);
      v31 = _mm_cmpltps(_mm_sub_ps((__m128)0i64, v29), (__m128)0i64);
      v32 = _mm_or_ps(
              _mm_and_ps(
                _mm_mul_ps(
                  _mm_andnot_ps(
                    _mm_cmpleps(v29, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v30, v29), v30)),
                      _mm_mul_ps(*(__m128 *)_xmm, v30))),
                  v27),
                v31),
              _mm_andnot_ps(v31, v27));
      if ( _mm_movemask_ps(v31) )
      {
        v33 = 1;
        v34 = 0;
        v35 = 0i64;
        v36 = 1i64;
        v37 = _mm_mul_ps(v32, v3->m_quad);
        v38 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 0)))
            + COERCE_FLOAT(_mm_shuffle_ps(v37, v37, 170));
        if ( (signed int)numtoinsert > 1 )
        {
          v39 = &v3[1].m_quad;
          do
          {
            v40 = _mm_mul_ps(v32, *v39);
            v41 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 0)))
                + COERCE_FLOAT(_mm_shuffle_ps(v40, v40, 170));
            if ( v41 > v38 )
            {
              v38 = v41;
              v34 = v33;
              v35 = v36;
            }
            ++v33;
            ++v36;
            ++v39;
          }
          while ( v33 < (signed int)numtoinsert );
        }
        LODWORD(numtoinsert) = numtoinsert - 1;
        v42 = (_OWORD *)v3[v35].m_quad.m128_f32;
        v2->m_planeEquations.m_data[v2->m_planeEquations.m_size++] = (hkVector4f)*v42;
        if ( (_DWORD)numtoinsert != v34 )
        {
          v43 = 2i64;
          v44 = 16i64 * (signed int)numtoinsert - 16 * v35;
          do
          {
            v45 = *(_QWORD *)((char *)v42 + v44);
            v42 = (_OWORD *)((char *)v42 + 8);
            *((_QWORD *)v42 - 1) = v45;
            --v43;
          }
          while ( v43 );
        }
      }
      else
      {
        v2->m_planeEquations.m_data[v2->m_planeEquations.m_size++] = (hkVector4f)v3->m_quad;
      }
    }
    ++i;
  }
  if ( (signed int)numtoinsert > 0 )
    hkArrayBase<hkVector4f>::_insertAt(
      (hkArrayBase<hkVector4f> *)&v2->m_planeEquations.m_data,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v2->m_planeEquations.m_size,
      v3,
      numtoinsert);
  v46 = vertices.m_size;
  v47 = (char *)p;
  if ( p == vertices.m_data )
    v46 = 0;
  vertices.m_size = v46;
  v48 = (16 * v53 + 127) & 0xFFFFFF80;
  v49 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v50 = (v48 + 15) & 0xFFFFFFF0;
  if ( v48 > v49->m_slabSize || &v47[v50] != v49->m_cur || v49->m_firstNonLifoEnd == v47 )
    hkLifoAllocator::slowBlockFree(v49, v47, v50);
  else
    v49->m_cur = v47;
  vertices.m_size = 0;
  if ( vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      vertices.m_data,
      16 * vertices.m_capacityAndFlags);
  vertices.m_data = 0i64;
  vertices.m_capacityAndFlags = 2147483648;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v3,
      16 * v4);
}

