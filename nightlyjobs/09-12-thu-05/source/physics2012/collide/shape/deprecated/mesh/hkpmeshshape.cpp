// File Line: 26
// RVA: 0xD17E30
void __fastcall hkpMeshShape::hkpMeshShape(hkpMeshShape *this, float radius, int numBitsForSubpartIndex)
{
  hkpShapeCollection::hkpShapeCollection(this, TRIANGLE_COLLECTION, COLLECTION_MESH_SHAPE);
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpMeshShape::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpMeshShape::`vftable{for `hkpShapeContainer};
  this->m_subparts.m_capacityAndFlags = 0x80000000;
  this->m_subparts.m_data = 0i64;
  this->m_subparts.m_size = 0;
  this->m_weldingInfo.m_data = 0i64;
  this->m_weldingInfo.m_size = 0;
  this->m_weldingInfo.m_capacityAndFlags = 0x80000000;
  this->m_scaling.m_quad = _mm_shuffle_ps(
                             *(__m128 *)_xmm,
                             _mm_unpackhi_ps(*(__m128 *)_xmm, this->m_scaling.m_quad),
                             196);
  this->m_radius = radius;
  this->m_weldingType.m_storage = 6;
  this->m_numBitsForSubpartIndex = numBitsForSubpartIndex;
}

// File Line: 44
// RVA: 0xD17ED0
void __fastcall hkpMeshShape::hkpMeshShape(hkpMeshShape *this, hkFinishLoadedObjectFlag flag)
{
  int v3; // ecx
  __int64 v4; // rdx
  hkpMeshShape::Subpart *m_data; // rax

  hkpShapeCollection::hkpShapeCollection(this, flag);
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpMeshShape::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpMeshShape::`vftable{for `hkpShapeContainer};
  if ( flag.m_finishing )
  {
    v3 = 0;
    if ( this->m_subparts.m_size > 0 )
    {
      v4 = 0i64;
      do
      {
        m_data = this->m_subparts.m_data;
        if ( !m_data[v4].m_materialIndexStridingType.m_storage )
          m_data[v4].m_materialIndexStridingType.m_storage = 1;
        ++v3;
        ++v4;
      }
      while ( v3 < this->m_subparts.m_size );
    }
    this->m_type.m_storage = 27;
    this->m_collectionType.m_storage = 5;
  }
}

// File Line: 62
// RVA: 0xD17F50
void __fastcall hkpMeshShape::setWeldingInfo(hkpMeshShape *this, unsigned int key, unsigned __int16 weldingInfo)
{
  this->m_weldingInfo.m_data[(key & (0xFFFFFFFF >> this->m_numBitsForSubpartIndex))
                           + this->m_subparts.m_data[key >> (32 - LOBYTE(this->m_numBitsForSubpartIndex))].m_triangleOffset] = weldingInfo;
}

// File Line: 79
// RVA: 0xD17FA0
void __fastcall hkpMeshShape::initWeldingInfo(hkpMeshShape *this, hkpWeldingUtility::WeldingType weldingType)
{
  int v3; // ecx
  int v4; // ebx
  hkpMeshShape::Subpart *m_data; // rdx
  __int64 v6; // rax
  hkArray<unsigned short,hkContainerHeapAllocator> *p_m_weldingInfo; // r14
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  __int64 m_size; // rdx
  unsigned __int16 *v12; // rdi
  __int64 v13; // rcx
  int m_capacityAndFlags; // r8d
  hkResult result; // [rsp+48h] [rbp+10h] BYREF

  this->m_weldingType.m_storage = weldingType;
  if ( weldingType == WELDING_TYPE_NONE )
  {
    m_capacityAndFlags = this->m_weldingInfo.m_capacityAndFlags;
    this->m_weldingInfo.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_weldingInfo.m_data,
        2 * (m_capacityAndFlags & 0x3FFFFFFF));
    this->m_weldingInfo.m_data = 0i64;
    this->m_weldingInfo.m_capacityAndFlags = 0x80000000;
  }
  else
  {
    v3 = 0;
    v4 = 0;
    if ( this->m_subparts.m_size > 0 )
    {
      m_data = this->m_subparts.m_data;
      v6 = 0i64;
      do
      {
        m_data[v6].m_triangleOffset = v4;
        m_data = this->m_subparts.m_data;
        ++v3;
        v4 += m_data[v6++].m_numTriangles;
      }
      while ( v3 < this->m_subparts.m_size );
    }
    p_m_weldingInfo = &this->m_weldingInfo;
    if ( (this->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF) < v4 )
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_weldingInfo.m_data,
        v4,
        2);
    v8 = this->m_weldingInfo.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 < v4 )
    {
      v9 = 2 * v8;
      v10 = v4;
      if ( v4 < v9 )
        v10 = v9;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_weldingInfo.m_data,
        v10,
        2);
    }
    m_size = this->m_weldingInfo.m_size;
    v12 = &p_m_weldingInfo->m_data[m_size];
    v13 = v4 - (int)m_size;
    if ( v4 - (int)m_size > 0 )
    {
      while ( v13 )
      {
        *v12++ = 0;
        --v13;
      }
    }
    p_m_weldingInfo->m_size = v4;
  }
}

// File Line: 105
// RVA: 0xD181F0
unsigned int __fastcall hkpMeshShape::getFirstKey(hkpMeshShape *this)
{
  unsigned int result; // eax
  hkVector4f *v3; // rax
  hkSimdFloat32 tolerance; // [rsp+20h] [rbp-218h] BYREF
  char v5[520]; // [rsp+30h] [rbp-208h] BYREF

  if ( !this->m_scaling.m_quad.m128_i32[0] )
    return -1;
  v3 = (hkVector4f *)((__int64 (__fastcall *)(hkpMeshShape *, _QWORD, char *))this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr[2].__first_virtual_table_function__)(
                       this,
                       0i64,
                       v5);
  tolerance.m_real = _mm_shuffle_ps(
                       (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                       (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                       0);
  result = hkcdTriangleUtil::isDegenerate(v3 + 3, v3 + 4, v3 + 5, &tolerance);
  if ( result )
    return ((__int64 (__fastcall *)(hkpMeshShape *, _QWORD))this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr[1].__first_virtual_table_function__)(
             this,
             0i64);
  return result;
}

// File Line: 123
// RVA: 0xD18280
__int64 __fastcall hkpMeshShape::getNextKey(hkpMeshShape *this, unsigned int initialKey)
{
  __int64 v3; // rdi
  unsigned int v4; // ebx
  __int64 v5; // rsi
  unsigned int v6; // ebp
  hkVector4f *v7; // rax
  hkSimdFloat32 tolerance; // [rsp+20h] [rbp-228h] BYREF
  char v10[536]; // [rsp+30h] [rbp-218h] BYREF

  v3 = initialKey >> (32 - LOBYTE(this->hkpShapeCollection::hkpShapeContainer::vfptr));
  v4 = initialKey & (0xFFFFFFFF >> LODWORD(this->hkpShapeCollection::hkpShapeContainer::vfptr));
  v5 = 80 * v3;
  while ( (signed int)++v4 < *(_DWORD *)(*(_QWORD *)&this->m_disableWelding.m_bool + v5 + 36) )
  {
LABEL_5:
    v6 = v4 | ((_DWORD)v3 << (32 - LOBYTE(this->hkpShapeCollection::hkpShapeContainer::vfptr)));
    v7 = (hkVector4f *)((__int64 (__fastcall *)(hkpMeshShape *, _QWORD, char *))this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr[2].__first_virtual_table_function__)(
                         this,
                         v6,
                         v10);
    tolerance.m_real = _mm_shuffle_ps(
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         0);
    if ( !hkcdTriangleUtil::isDegenerate(v7 + 3, v7 + 4, v7 + 5, &tolerance) )
      return v6;
  }
  LODWORD(v3) = v3 + 1;
  v5 += 80i64;
  if ( (unsigned int)v3 < this->m_scaling.m_quad.m128_i32[0] )
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
  int vfptr; // ecx
  unsigned int v6; // ebx
  __int64 v7; // r11
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
  int m_data_high; // xmm0_4
  unsigned __int8 m_data; // al

  vfptr = (int)this->hkpShapeCollection::hkpShapeContainer::vfptr;
  v6 = key & (0xFFFFFFFF >> vfptr);
  v7 = *(_QWORD *)&this->m_disableWelding.m_bool + 80i64 * (int)(key >> (32 - vfptr));
  v8 = *(_DWORD *)(v7 + 8);
  v9 = (_DWORD *)(*(_QWORD *)(v7 + 16) + v6 * *(_DWORD *)(v7 + 28));
  v10 = *(_QWORD *)v7;
  v11 = (int)(v6 & *(_DWORD *)(v7 + 32));
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
  v15 = *(__m128 *)&this->m_type.m_storage;
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
  if ( this->m_numBitsForSubpartIndex )
    v19 = *(_WORD *)(this->m_scaling.m_quad.m128_u64[1] + 2i64 * (int)(v6 + *(_DWORD *)(v7 + 72)));
  else
    v19 = 0;
  if ( buffer )
  {
    m_data_high = HIDWORD(this->m_subparts.m_data);
    m_data = (unsigned __int8)this->m_subparts.m_data;
    *(_DWORD *)&(*buffer)[8] = 0x1FFFF;
    *(_DWORD *)&(*buffer)[16] = 1026;
    *(_QWORD *)&(*buffer)[24] = 0i64;
    *(_DWORD *)&(*buffer)[32] = m_data_high;
    *(_WORD *)&(*buffer)[40] = v19;
    *(_WORD *)&(*buffer)[42] = m_data;
    *(_OWORD *)&(*buffer)[96] = 0i64;
    *(_QWORD *)buffer = &hkpTriangleShape::`vftable;
  }
  else
  {
    buffer = 0i64;
  }
  *(__m128 *)&(*buffer)[48] = v16;
  *(__m128 *)&(*buffer)[64] = v17;
  *(__m128 *)&(*buffer)[80] = v18;
  return (hkpShape *)*buffer;
}

// File Line: 230
// RVA: 0xD18500
__int64 __fastcall hkpMeshShape::getCollisionFilterInfo(hkpMeshShape *this, unsigned int key)
{
  int vfptr; // r10d
  __int64 v3; // r9
  __int64 v4; // r8
  __int64 v5; // rax
  int v6; // ecx
  unsigned int *v7; // rcx

  vfptr = (int)this->hkpShapeCollection::hkpShapeContainer::vfptr;
  v3 = 80i64 * (int)(key >> (32 - vfptr)) + *(_QWORD *)&this->m_disableWelding.m_bool;
  v4 = *(_QWORD *)(v3 + 40);
  if ( v4
    && ((v5 = *(_DWORD *)(v3 + 48) * (key & (0xFFFFFFFF >> vfptr)), *(_BYTE *)(v3 + 25) != 1)
      ? (v6 = *(unsigned __int16 *)(v5 + v4))
      : (v6 = *(unsigned __int8 *)(v5 + v4)),
        (v7 = (unsigned int *)(*(_QWORD *)(v3 + 56) + v6 * *(_DWORD *)(v3 + 64))) != 0i64) )
  {
    return *v7;
  }
  else
  {
    return 0i64;
  }
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
  int v4; // r12d
  __int64 v8; // r10
  hkpMeshShape::Subpart *m_data; // r11
  int i; // esi
  int m_vertexStriding; // ecx
  const float *m_vertexBase; // rdx
  int v13; // eax
  unsigned __int16 *v14; // r8
  __int64 v15; // rbx
  __int64 v16; // rdi
  _DWORD *v17; // r9
  const float *v18; // rdi
  hkTransformf *v19; // rdx
  hkAabb *v20; // rcx
  const float *v21; // rax
  hkTransformf *v22; // rdx
  hkAabb *v23; // rcx
  __m128 v24; // xmm2
  hkVector4f v25; // xmm1

  v4 = 0;
  out->m_min = (hkVector4f)xmmword_141A712A0;
  out->m_max = (hkVector4f)xmmword_141A712F0;
  if ( this->m_subparts.m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      m_data = this->m_subparts.m_data;
      for ( i = 0; i < m_data[v8].m_numTriangles; ++i )
      {
        m_vertexStriding = m_data[v8].m_vertexStriding;
        m_vertexBase = m_data[v8].m_vertexBase;
        v13 = i * m_data[v8].m_indexStriding;
        if ( m_data[v8].m_stridingType.m_storage == 1 )
        {
          v14 = (unsigned __int16 *)((char *)m_data[v8].m_indexBase + v13);
          v15 = m_vertexStriding * *v14;
          v16 = m_vertexStriding * v14[1];
        }
        else
        {
          v17 = (char *)m_data[v8].m_indexBase + v13;
          v15 = (unsigned int)(m_vertexStriding * *v17);
          v16 = (unsigned int)(m_vertexStriding * v17[1]);
        }
        v18 = (const float *)((char *)m_vertexBase + v16);
        meshShape_addToAabb(out, localToWorld, (const float *)((char *)m_vertexBase + v15), &this->m_scaling);
        meshShape_addToAabb(v20, v19, v18, &this->m_scaling);
        meshShape_addToAabb(v23, v22, v21, &this->m_scaling);
      }
      ++v4;
      ++v8;
    }
    while ( v4 < this->m_subparts.m_size );
  }
  v24 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
          (__m128)COERCE_UNSIGNED_INT(tolerance + this->m_radius),
          0);
  v25.m_quad = _mm_add_ps(out->m_max.m_quad, v24);
  out->m_min.m_quad = _mm_sub_ps(out->m_min.m_quad, v24);
  out->m_max = (hkVector4f)v25.m_quad;
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
  hkArray<hkpMeshShape::Subpart,hkContainerHeapAllocator> *p_m_subparts; // rbx
  __int64 v4; // rcx
  __int64 m_size; // rcx
  __int64 v6; // rdx

  p_m_subparts = &this->m_subparts;
  if ( this->m_subparts.m_size == (this->m_subparts.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_subparts->m_data, 80);
  v4 = (__int64)&p_m_subparts->m_data[p_m_subparts->m_size];
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
  m_size = p_m_subparts->m_size;
  p_m_subparts->m_size = m_size + 1;
  v6 = (__int64)&p_m_subparts->m_data[m_size];
  *(_QWORD *)v6 = part->m_vertexBase;
  *(_QWORD *)(v6 + 8) = *(_QWORD *)&part->m_vertexStriding;
  *(_QWORD *)(v6 + 16) = part->m_indexBase;
  *(_QWORD *)(v6 + 24) = *(_QWORD *)&part->m_stridingType.m_storage;
  *(_QWORD *)(v6 + 32) = *(_QWORD *)&part->m_flipAlternateTriangles;
  *(_QWORD *)(v6 + 40) = part->m_materialIndexBase;
  *(_QWORD *)(v6 + 48) = *(_QWORD *)&part->m_materialIndexStriding;
  *(_QWORD *)(v6 + 56) = part->m_materialBase;
  *(_QWORD *)(v6 + 64) = *(_QWORD *)&part->m_materialStriding;
  *(_QWORD *)(v6 + 72) = *(_QWORD *)&part->m_triangleOffset;
  if ( !*(_QWORD *)(v6 + 40) )
  {
    *(_DWORD *)(v6 + 68) = 1;
    *(_QWORD *)(v6 + 56) = &aabbOut;
    *(_QWORD *)(v6 + 40) = &aabbOut;
  }
}

