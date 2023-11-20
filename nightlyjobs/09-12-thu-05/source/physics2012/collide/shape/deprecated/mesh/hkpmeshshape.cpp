// File Line: 26
// RVA: 0xD17E30
void __fastcall hkpMeshShape::hkpMeshShape(hkpMeshShape *this, float radius, int numBitsForSubpartIndex)
{
  int v3; // edi
  hkpMeshShape *v4; // rbx

  v3 = numBitsForSubpartIndex;
  v4 = this;
  hkpShapeCollection::hkpShapeCollection((hkpShapeCollection *)&this->vfptr, TRIANGLE_COLLECTION, COLLECTION_MESH_SHAPE);
  v4->vfptr = (hkBaseObjectVtbl *)&hkpMeshShape::`vftable'{for `hkpShape'};
  v4->vfptr = (hkpShapeContainerVtbl *)&hkpMeshShape::`vftable'{for `hkpShapeContainer'};
  v4->m_subparts.m_capacityAndFlags = 2147483648;
  v4->m_subparts.m_data = 0i64;
  v4->m_subparts.m_size = 0;
  v4->m_weldingInfo.m_data = 0i64;
  v4->m_weldingInfo.m_size = 0;
  v4->m_weldingInfo.m_capacityAndFlags = 2147483648;
  v4->m_scaling.m_quad = _mm_shuffle_ps(*(__m128 *)_xmm, _mm_unpackhi_ps(*(__m128 *)_xmm, v4->m_scaling.m_quad), 196);
  v4->m_radius = radius;
  v4->m_weldingType.m_storage = 6;
  v4->m_numBitsForSubpartIndex = v3;
}

// File Line: 44
// RVA: 0xD17ED0
void __fastcall hkpMeshShape::hkpMeshShape(hkpMeshShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpMeshShape *v2; // rbx
  int v3; // ecx
  __int64 v4; // rdx
  hkpMeshShape::Subpart *v5; // rax
  int v6; // [rsp+38h] [rbp+10h]

  v6 = flag.m_finishing;
  v2 = this;
  hkpShapeCollection::hkpShapeCollection((hkpShapeCollection *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpMeshShape::`vftable'{for `hkpShape'};
  v2->vfptr = (hkpShapeContainerVtbl *)&hkpMeshShape::`vftable'{for `hkpShapeContainer'};
  if ( v6 )
  {
    v3 = 0;
    if ( v2->m_subparts.m_size > 0 )
    {
      v4 = 0i64;
      do
      {
        v5 = v2->m_subparts.m_data;
        if ( !v5[v4].m_materialIndexStridingType.m_storage )
          v5[v4].m_materialIndexStridingType.m_storage = 1;
        ++v3;
        ++v4;
      }
      while ( v3 < v2->m_subparts.m_size );
    }
    v2->m_type.m_storage = 27;
    v2->m_collectionType.m_storage = 5;
  }
}

// File Line: 62
// RVA: 0xD17F50
void __fastcall hkpMeshShape::setWeldingInfo(hkpMeshShape *this, unsigned int key, __int16 weldingInfo)
{
  this->m_weldingInfo.m_data[(key & (0xFFFFFFFF >> this->m_numBitsForSubpartIndex))
                           + this->m_subparts.m_data[key >> (32 - LOBYTE(this->m_numBitsForSubpartIndex))].m_triangleOffset] = weldingInfo;
}

// File Line: 79
// RVA: 0xD17FA0
void __fastcall hkpMeshShape::initWeldingInfo(hkpMeshShape *this, hkpWeldingUtility::WeldingType weldingType)
{
  hkpMeshShape *v2; // rdi
  int v3; // ecx
  int v4; // ebx
  hkpMeshShape::Subpart *v5; // rdx
  __int64 v6; // rax
  signed __int64 v7; // r14
  int v8; // eax
  int v9; // eax
  int v10; // er9
  __int64 v11; // rdx
  _WORD *v12; // rdi
  __int64 v13; // rcx
  int v14; // er8
  hkResult result; // [rsp+48h] [rbp+10h]

  v2 = this;
  this->m_weldingType.m_storage = weldingType;
  if ( weldingType == 6 )
  {
    v14 = this->m_weldingInfo.m_capacityAndFlags;
    this->m_weldingInfo.m_size = 0;
    if ( v14 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_weldingInfo.m_data,
        2 * (v14 & 0x3FFFFFFF));
    v2->m_weldingInfo.m_data = 0i64;
    v2->m_weldingInfo.m_capacityAndFlags = 2147483648;
  }
  else
  {
    v3 = 0;
    v4 = 0;
    if ( v2->m_subparts.m_size > 0 )
    {
      v5 = v2->m_subparts.m_data;
      v6 = 0i64;
      do
      {
        v5[v6].m_triangleOffset = v4;
        v5 = v2->m_subparts.m_data;
        ++v3;
        v4 += v5[v6].m_numTriangles;
        ++v6;
      }
      while ( v3 < v2->m_subparts.m_size );
    }
    v7 = (signed __int64)&v2->m_weldingInfo;
    if ( (v2->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF) < v4 )
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v2->m_weldingInfo,
        v4,
        2);
    v8 = v2->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 < v4 )
    {
      v9 = 2 * v8;
      v10 = v4;
      if ( v4 < v9 )
        v10 = v9;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v2->m_weldingInfo,
        v10,
        2);
    }
    v11 = v2->m_weldingInfo.m_size;
    v12 = (_WORD *)(*(_QWORD *)v7 + 2 * v11);
    v13 = v4 - (signed int)v11;
    if ( v4 - (signed int)v11 > 0 )
    {
      while ( v13 )
      {
        *v12 = 0;
        ++v12;
        --v13;
      }
    }
    *(_DWORD *)(v7 + 8) = v4;
  }
}

// File Line: 105
// RVA: 0xD181F0
unsigned int __fastcall hkpMeshShape::getFirstKey(hkpMeshShape *this)
{
  hkpMeshShape *v1; // rbx
  unsigned int result; // eax
  hkVector4f *v3; // rax
  hkSimdFloat32 tolerance; // [rsp+20h] [rbp-218h]
  char v5; // [rsp+30h] [rbp-208h]

  v1 = this;
  if ( !this->m_scaling.m_quad.m128_i32[0] )
    return -1;
  v3 = (hkVector4f *)((__int64 (__fastcall *)(hkpMeshShape *, _QWORD, char *))this->vfptr[2].__first_virtual_table_function__)(
                       this,
                       0i64,
                       &v5);
  tolerance.m_real = _mm_shuffle_ps(
                       (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                       (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                       0);
  result = hkcdTriangleUtil::isDegenerate(v3 + 3, v3 + 4, v3 + 5, &tolerance);
  if ( result )
    result = ((__int64 (__fastcall *)(hkpMeshShape *, _QWORD))v1->vfptr[1].__first_virtual_table_function__)(v1, 0i64);
  return result;
}

// File Line: 123
// RVA: 0xD18280
signed __int64 __fastcall hkpMeshShape::getNextKey(hkpMeshShape *this, unsigned int initialKey)
{
  hkpMeshShape *v2; // r14
  __int64 v3; // rdi
  unsigned int v4; // ebx
  signed __int64 v5; // rsi
  unsigned int v6; // ebp
  hkVector4f *v7; // rax
  hkSimdFloat32 tolerance; // [rsp+20h] [rbp-228h]
  char v10; // [rsp+30h] [rbp-218h]

  v2 = this;
  v3 = initialKey >> (32 - LOBYTE(this->vfptr));
  v4 = initialKey & (0xFFFFFFFF >> LODWORD(this->vfptr));
  v5 = 80 * v3;
  while ( (signed int)++v4 < *(_DWORD *)(*(_QWORD *)&v2->m_disableWelding.m_bool + v5 + 36) )
  {
LABEL_5:
    v6 = v4 | ((_DWORD)v3 << (32 - LOBYTE(v2->vfptr)));
    v7 = (hkVector4f *)((__int64 (__fastcall *)(hkpMeshShape *, _QWORD, char *))v2->vfptr[2].__first_virtual_table_function__)(
                         v2,
                         v4 | ((_DWORD)v3 << (32 - LOBYTE(v2->vfptr))),
                         &v10);
    tolerance.m_real = _mm_shuffle_ps(
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         0);
    if ( !hkcdTriangleUtil::isDegenerate(v7 + 3, v7 + 4, v7 + 5, &tolerance) )
      return v6;
  }
  LODWORD(v3) = v3 + 1;
  v5 += 80i64;
  if ( (unsigned int)v3 < v2->m_scaling.m_quad.m128_i32[0] )
  {
    v4 = 0;
    goto LABEL_5;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 157
// RVA: 0xD18360
hkpShape *__fastcall hkpMeshShape::getChildShape(hkpMeshShape *this, unsigned int key, char (*buffer)[512])
{
  hkpMeshShape *v3; // rdi
  int v4; // ecx
  char (*v5)[512]; // r10
  unsigned int v6; // ebx
  signed __int64 v7; // r11
  int v8; // edx
  _DWORD *v9; // r9
  __int64 v10; // r8
  __int64 v11; // rcx
  __int64 v12; // rsi
  __int64 v13; // rbp
  __int64 v14; // rcx
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  __int16 v19; // cx
  int v20; // xmm0_4
  unsigned __int8 v21; // al

  v3 = this;
  v4 = (int)this->vfptr;
  v5 = buffer;
  v6 = key & (0xFFFFFFFF >> v4);
  v7 = *(_QWORD *)&v3->m_disableWelding.m_bool + 80i64 * (signed int)(key >> (32 - v4));
  v8 = *(_DWORD *)(v7 + 8);
  v9 = (_DWORD *)(*(_QWORD *)(v7 + 16) + v6 * *(_DWORD *)(v7 + 28));
  v10 = *(_QWORD *)v7;
  v11 = (signed int)(v6 & *(_DWORD *)(v7 + 32));
  if ( *(_BYTE *)(v7 + 24) == 1 )
  {
    v12 = v8 * *(unsigned __int16 *)v9;
    v13 = v8 * *((unsigned __int16 *)v9 + v11 + 1);
    v14 = v8 * *((unsigned __int16 *)v9 + (v11 ^ 1) + 1);
  }
  else
  {
    v12 = (unsigned int)(*v9 * v8);
    v13 = (unsigned int)(v8 * v9[v11 + 1]);
    v14 = (unsigned int)(v8 * v9[(v11 ^ 1) + 1]);
  }
  v15 = *(__m128 *)&v3->m_type.m_storage;
  v16 = _mm_mul_ps(
          (__m128)_mm_srli_si128(
                    _mm_slli_si128(
                      (__m128i)_mm_movelh_ps(
                                 (__m128)*(unsigned __int64 *)(v10 + v12),
                                 (__m128)*(unsigned int *)(v10 + v12 + 8)),
                      4),
                    4),
          v15);
  v17 = _mm_mul_ps(
          (__m128)_mm_srli_si128(
                    _mm_slli_si128(
                      (__m128i)_mm_movelh_ps(
                                 (__m128)*(unsigned __int64 *)(v10 + v13),
                                 (__m128)*(unsigned int *)(v10 + v13 + 8)),
                      4),
                    4),
          v15);
  v18 = _mm_mul_ps(
          (__m128)_mm_srli_si128(
                    _mm_slli_si128(
                      (__m128i)_mm_movelh_ps(
                                 (__m128)*(unsigned __int64 *)(v10 + v14),
                                 (__m128)*(unsigned int *)(v10 + v14 + 8)),
                      4),
                    4),
          v15);
  if ( v3->m_numBitsForSubpartIndex )
    v19 = *(_WORD *)(v3->m_scaling.m_quad.m128_u64[1] + 2i64 * (signed int)(v6 + *(_DWORD *)(v7 + 72)));
  else
    v19 = 0;
  if ( v5 )
  {
    v20 = HIDWORD(v3->m_subparts.m_data);
    v21 = (unsigned __int8)v3->m_subparts.m_data;
    *(_DWORD *)&(*v5)[8] = 0x1FFFF;
    *(_DWORD *)&(*v5)[16] = 1026;
    *(_QWORD *)&(*v5)[24] = 0i64;
    *(_DWORD *)&(*v5)[32] = v20;
    *(_WORD *)&(*v5)[40] = v19;
    *(_WORD *)&(*v5)[42] = v21;
    *(_OWORD *)&(*v5)[96] = 0i64;
    *(_QWORD *)v5 = &hkpTriangleShape::`vftable';
  }
  else
  {
    v5 = 0i64;
  }
  *(__m128 *)&(*v5)[48] = v16;
  *(__m128 *)&(*v5)[64] = v17;
  *(__m128 *)&(*v5)[80] = v18;
  return (hkpShape *)v5;
}

// File Line: 230
// RVA: 0xD18500
__int64 __fastcall hkpMeshShape::getCollisionFilterInfo(hkpMeshShape *this, unsigned int key)
{
  int v2; // er10
  signed __int64 v3; // r9
  __int64 v4; // r8
  __int64 v5; // rax
  int v6; // ecx
  unsigned int *v7; // rcx
  __int64 result; // rax

  v2 = (int)this->vfptr;
  v3 = 80i64 * (signed int)(key >> (32 - v2)) + *(_QWORD *)&this->m_disableWelding.m_bool;
  v4 = *(_QWORD *)(v3 + 40);
  if ( v4
    && ((v5 = *(_DWORD *)(v3 + 48) * (key & (0xFFFFFFFF >> v2)), *(_BYTE *)(v3 + 25) != 1) ? (v6 = *(unsigned __int16 *)(v5 + v4)) : (v6 = *(unsigned __int8 *)(v5 + v4)),
        v6 != -1 && (v7 = (unsigned int *)(*(_QWORD *)(v3 + 56) + v6 * *(_DWORD *)(v3 + 64))) != 0i64) )
  {
    result = *v7;
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 246
// RVA: 0xD18700
void __fastcall meshShape_addToAabb(hkAabb *aabb, hkTransformf *localToWorld, const float *v, hkVector4f *scaling)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm2
  hkVector4f v6; // xmm1

  v4 = _mm_mul_ps(
         (__m128)_mm_srli_si128(
                   _mm_slli_si128(
                     (__m128i)_mm_movelh_ps((__m128)*(unsigned __int64 *)v, (__m128)*((unsigned int *)v + 2)),
                     4),
                   4),
         scaling->m_quad);
  v5 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v4, v4, 85), localToWorld->m_rotation.m_col1.m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v4, v4, 0), localToWorld->m_rotation.m_col0.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v4, v4, 170), localToWorld->m_rotation.m_col2.m_quad)),
         localToWorld->m_translation.m_quad);
  v6.m_quad = _mm_max_ps(aabb->m_max.m_quad, v5);
  aabb->m_min.m_quad = _mm_min_ps(aabb->m_min.m_quad, v5);
  aabb->m_max = (hkVector4f)v6.m_quad;
}

// File Line: 262
// RVA: 0xD18570
void __fastcall hkpMeshShape::getAabb(hkpMeshShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  int v4; // er12
  hkAabb *v5; // rbp
  hkTransformf *v6; // r13
  hkpMeshShape *v7; // r14
  __int64 v8; // r10
  hkpMeshShape::Subpart *v9; // r11
  int i; // esi
  int v11; // ecx
  const float *v12; // rdx
  int v13; // eax
  unsigned __int16 *v14; // r8
  __int64 v15; // rbx
  __int64 v16; // rdi
  bool v17; // cf
  _DWORD *v18; // r9
  const float *v19; // rdi
  hkTransformf *v20; // rdx
  hkAabb *v21; // rcx
  const float *v22; // rax
  hkTransformf *v23; // rdx
  hkAabb *v24; // rcx
  __m128 v25; // xmm2
  __m128 v26; // xmm1

  v4 = 0;
  v5 = out;
  out->m_min = (hkVector4f)xmmword_141A712A0;
  v6 = localToWorld;
  v7 = this;
  out->m_max = (hkVector4f)xmmword_141A712F0;
  if ( this->m_subparts.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      v9 = v7->m_subparts.m_data;
      for ( i = 0; i < v9[v8].m_numTriangles; ++i )
      {
        v11 = v9[v8].m_vertexStriding;
        v12 = v9[v8].m_vertexBase;
        v13 = i * v9[v8].m_indexStriding;
        if ( v9[v8].m_stridingType.m_storage == 1 )
        {
          v14 = (unsigned __int16 *)((char *)v9[v8].m_indexBase + v13);
          v15 = v11 * *v14;
          v16 = v11 * v14[1];
          v17 = v11 * (unsigned __int64)v14[2] >> 32 != 0;
        }
        else
        {
          v18 = (char *)v9[v8].m_indexBase + v13;
          v15 = (unsigned int)(v11 * *v18);
          v16 = (unsigned int)(v11 * v18[1]);
          v17 = (unsigned __int64)(v11 * (signed __int64)(signed int)v18[2]) >> 32 != 0;
        }
        v19 = (const float *)((char *)v12 + v16);
        meshShape_addToAabb(v5, v6, (const float *)((char *)v12 + v15), &v7->m_scaling);
        meshShape_addToAabb(v21, v20, v19, &v7->m_scaling);
        meshShape_addToAabb(v24, v23, v22, &v7->m_scaling);
      }
      ++v4;
      ++v8;
    }
    while ( v4 < v7->m_subparts.m_size );
  }
  v25 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT(tolerance + v7->m_radius),
          (__m128)COERCE_UNSIGNED_INT(tolerance + v7->m_radius),
          0);
  v26 = _mm_add_ps(v5->m_max.m_quad, v25);
  v5->m_min.m_quad = _mm_sub_ps(v5->m_min.m_quad, v25);
  v5->m_max.m_quad = v26;
}

// File Line: 313
// RVA: 0xD181E0
void __fastcall hkpMeshShape::setScaling(hkpMeshShape *this, hkVector4f *scaling)
{
  this->m_scaling = (hkVector4f)scaling->m_quad;
}

// File Line: 318
// RVA: 0xD186F0
void __fastcall hkpMeshShape::assertSubpartValidity(hkpMeshShape *this, hkpMeshShape::Subpart *part)
{
  ;
}

// File Line: 341
// RVA: 0xD180E0
void __fastcall hkpMeshShape::addSubpart(hkpMeshShape *this, hkpMeshShape::Subpart *part)
{
  signed int *v2; // rbx
  hkpMeshShape::Subpart *v3; // rdi
  signed __int64 v4; // rcx
  __int64 v5; // rcx
  signed __int64 v6; // rdx

  v2 = (signed int *)&this->m_subparts;
  v3 = part;
  if ( this->m_subparts.m_size == (this->m_subparts.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 80);
  v4 = *(_QWORD *)v2 + 80i64 * v2[2];
  if ( v4 )
  {
    *(_BYTE *)(v4 + 25) = 1;
    *(_DWORD *)(v4 + 68) = 1;
    *(_DWORD *)(v4 + 48) = 0;
    *(_DWORD *)(v4 + 64) = 0;
    *(_QWORD *)(v4 + 56) = 0i64;
    *(_QWORD *)(v4 + 40) = 0i64;
    *(_DWORD *)(v4 + 32) = 0;
    *(_DWORD *)(v4 + 72) = -1;
  }
  v5 = v2[2];
  v2[2] = v5 + 1;
  v6 = *(_QWORD *)v2 + 80 * v5;
  *(_QWORD *)v6 = v3->m_vertexBase;
  *(_QWORD *)(v6 + 8) = *(_QWORD *)&v3->m_vertexStriding;
  *(_QWORD *)(v6 + 16) = v3->m_indexBase;
  *(_QWORD *)(v6 + 24) = *(_QWORD *)&v3->m_stridingType.m_storage;
  *(_QWORD *)(v6 + 32) = *(_QWORD *)&v3->m_flipAlternateTriangles;
  *(_QWORD *)(v6 + 40) = v3->m_materialIndexBase;
  *(_QWORD *)(v6 + 48) = *(_QWORD *)&v3->m_materialIndexStriding;
  *(_QWORD *)(v6 + 56) = v3->m_materialBase;
  *(_QWORD *)(v6 + 64) = *(_QWORD *)&v3->m_materialStriding;
  *(_QWORD *)(v6 + 72) = *(_QWORD *)&v3->m_triangleOffset;
  if ( !*(_QWORD *)(v6 + 40) )
  {
    *(_DWORD *)(v6 + 68) = 1;
    *(_QWORD *)(v6 + 56) = &aabbOut;
    *(_QWORD *)(v6 + 40) = &aabbOut;
  }
}

