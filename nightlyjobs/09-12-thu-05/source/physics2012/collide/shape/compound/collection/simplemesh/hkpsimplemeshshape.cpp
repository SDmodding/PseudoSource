// File Line: 21
// RVA: 0xD19370
void __fastcall hkpSimpleMeshShape::hkpSimpleMeshShape(hkpSimpleMeshShape *this, float radius)
{
  hkpSimpleMeshShape *v2; // rbx

  v2 = this;
  hkpShapeCollection::hkpShapeCollection(
    (hkpShapeCollection *)&this->vfptr,
    TRIANGLE_COLLECTION,
    COLLECTION_SIMPLE_MESH);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpSimpleMeshShape::`vftable'{for `hkpShape'};
  v2->vfptr = (hkpShapeContainerVtbl *)&hkpSimpleMeshShape::`vftable'{for `hkpShapeContainer'};
  v2->m_vertices.m_capacityAndFlags = 2147483648;
  v2->m_vertices.m_data = 0i64;
  v2->m_vertices.m_size = 0;
  v2->m_triangles.m_data = 0i64;
  v2->m_triangles.m_size = 0;
  v2->m_triangles.m_capacityAndFlags = 2147483648;
  v2->m_materialIndices.m_data = 0i64;
  v2->m_materialIndices.m_size = 0;
  v2->m_materialIndices.m_capacityAndFlags = 2147483648;
  v2->m_weldingType.m_storage = 6;
  v2->m_radius = radius;
}

// File Line: 32
// RVA: 0xD193F0
void __fastcall hkpSimpleMeshShape::hkpSimpleMeshShape(hkpSimpleMeshShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpSimpleMeshShape *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = flag.m_finishing;
  v2 = this;
  hkpShapeCollection::hkpShapeCollection((hkpShapeCollection *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpSimpleMeshShape::`vftable'{for `hkpShape'};
  v2->vfptr = (hkpShapeContainerVtbl *)&hkpSimpleMeshShape::`vftable'{for `hkpShapeContainer'};
  if ( v3 )
  {
    v2->m_type.m_storage = 27;
    v2->m_collectionType.m_storage = 4;
  }
}

// File Line: 43
// RVA: 0xD19680
void __fastcall hkpSimpleMeshShape::setWeldingInfo(hkpSimpleMeshShape *this, unsigned int key, __int16 weldingInfo)
{
  this->m_triangles.m_data[key].m_weldingInfo = weldingInfo;
}

// File Line: 51
// RVA: 0xD196A0
void __fastcall hkpSimpleMeshShape::initWeldingInfo(hkpSimpleMeshShape *this, hkpWeldingUtility::WeldingType weldingType)
{
  int v2; // er8
  __int64 v3; // rdx

  this->m_weldingType.m_storage = weldingType;
  v2 = 0;
  if ( this->m_triangles.m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      ++v2;
      ++v3;
      *((_WORD *)&this->m_triangles.m_data[v3] - 2) = 0;
    }
    while ( v2 < this->m_triangles.m_size );
  }
}

// File Line: 61
// RVA: 0xD196E0
void __fastcall hkpSimpleMeshShape::getAabb(hkpSimpleMeshShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  int v4; // er8
  float v5; // xmm4_4
  hkVector4f v6; // xmm3
  __int64 v7; // r10
  hkVector4f *v8; // rax
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 v11; // xmm2
  hkVector4f v12; // xmm1

  v4 = 0;
  v5 = tolerance;
  out->m_min = (hkVector4f)xmmword_141A712A0;
  out->m_max = (hkVector4f)xmmword_141A712F0;
  if ( this->m_vertices.m_size > 0 )
  {
    v6.m_quad = (__m128)xmmword_141A712F0;
    v7 = 0i64;
    do
    {
      v8 = this->m_vertices.m_data;
      ++v4;
      ++v7;
      v9 = v8[v7 - 1].m_quad;
      v10 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), localToWorld->m_rotation.m_col1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v8[v7 - 1].m_quad, v9, 0), localToWorld->m_rotation.m_col0.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), localToWorld->m_rotation.m_col2.m_quad)),
              localToWorld->m_translation.m_quad);
      v6.m_quad = _mm_max_ps(v6.m_quad, v10);
      out->m_min.m_quad = _mm_min_ps(out->m_min.m_quad, v10);
      out->m_max = (hkVector4f)v6.m_quad;
    }
    while ( v4 < this->m_vertices.m_size );
  }
  v11 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT(v5 + this->m_radius),
          (__m128)COERCE_UNSIGNED_INT(v5 + this->m_radius),
          0);
  v12.m_quad = _mm_add_ps(out->m_max.m_quad, v11);
  out->m_min.m_quad = _mm_sub_ps(out->m_min.m_quad, v11);
  out->m_max = (hkVector4f)v12.m_quad;
}

// File Line: 84
// RVA: 0xD195B0
hkpShape *__fastcall hkpSimpleMeshShape::getChildShape(hkpSimpleMeshShape *this, unsigned int key, char (*buffer)[512])
{
  char (*v3)[512]; // r11
  int v4; // xmm0_4
  char v5; // r10
  __int16 v6; // r9
  hkpShape *result; // rax

  v3 = buffer;
  if ( buffer )
  {
    v4 = (int)this->m_triangles.m_data;
    v5 = BYTE4(this->m_triangles.m_data);
    v6 = *((_WORD *)&this->vfptr->getNumChildShapes + 8 * (signed int)key + 2);
    *(_DWORD *)&(*buffer)[8] = 0x1FFFF;
    *(_DWORD *)&(*buffer)[16] = 1026;
    *(_DWORD *)&(*buffer)[32] = v4;
    *(_QWORD *)&(*buffer)[24] = 0i64;
    (*buffer)[42] = v5;
    *(_OWORD *)&(*buffer)[96] = 0i64;
    *(_WORD *)&(*buffer)[40] = v6;
    (*buffer)[43] = 0;
    *(_QWORD *)buffer = &hkpTriangleShape::`vftable';
  }
  else
  {
    v3 = 0i64;
  }
  result = (hkpShape *)v3;
  *(_OWORD *)&(*v3)[48] = *(_OWORD *)(*(_QWORD *)&this->m_type.m_storage
                                    + 16i64 * *((signed int *)&this->vfptr->__vecDelDtor + 4 * (signed int)key));
  *(_OWORD *)&(*v3)[64] = *(_OWORD *)(*(_QWORD *)&this->m_type.m_storage
                                    + 16i64 * *((signed int *)&this->vfptr->__vecDelDtor + 4 * (signed int)key + 1));
  *(_OWORD *)&(*v3)[80] = *(_OWORD *)(*(_QWORD *)&this->m_type.m_storage
                                    + 16i64 * *((signed int *)&this->vfptr->getNumChildShapes + 4 * (signed int)key));
  return result;
}

// File Line: 108
// RVA: 0xD19440
signed __int64 __fastcall hkpSimpleMeshShape::getFirstKey(hkpSimpleMeshShape *this)
{
  unsigned int v1; // ebx
  hkpSimpleMeshShape *v2; // rsi
  __int64 v3; // rdi
  __int64 v4; // r9
  hkpShapeContainerVtbl *v5; // rax
  __int64 v6; // r8
  __int64 v7; // rdx
  __int64 v8; // rcx
  hkSimdFloat32 tolerance; // [rsp+20h] [rbp-18h]

  v1 = 0;
  v2 = this;
  if ( *(_DWORD *)&this->m_disableWelding.m_bool <= 0 )
    return 0xFFFFFFFFi64;
  v3 = 0i64;
  while ( 1 )
  {
    v4 = *(_QWORD *)&v2->m_type.m_storage;
    v5 = v2->vfptr;
    v6 = *(signed int *)((char *)&v5->getNumChildShapes + v3);
    v7 = *(signed int *)((char *)&v5->__vecDelDtor + v3 + 4);
    v8 = *(signed int *)((char *)&v5->__vecDelDtor + v3);
    tolerance.m_real = _mm_shuffle_ps(
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         0);
    if ( !hkcdTriangleUtil::isDegenerate(
            (hkVector4f *)(v4 + 16 * v8),
            (hkVector4f *)(v4 + 16 * v7),
            (hkVector4f *)(v4 + 16 * v6),
            &tolerance) )
      break;
    ++v1;
    v3 += 16i64;
    if ( (signed int)v1 >= *(_DWORD *)&v2->m_disableWelding.m_bool )
      return 0xFFFFFFFFi64;
  }
  return v1;
}

// File Line: 124
// RVA: 0xD194F0
signed __int64 __fastcall hkpSimpleMeshShape::getNextKey(hkpSimpleMeshShape *this, unsigned int oldKey)
{
  signed int v2; // ebx
  hkpSimpleMeshShape *v3; // rsi
  signed __int64 v4; // rdi
  __int64 v5; // r9
  hkpShapeContainerVtbl *v6; // rax
  __int64 v7; // r8
  __int64 v8; // rdx
  __int64 v9; // rcx
  hkSimdFloat32 tolerance; // [rsp+20h] [rbp-18h]

  v2 = oldKey + 1;
  v3 = this;
  if ( (signed int)(oldKey + 1) >= *(_DWORD *)&this->m_disableWelding.m_bool )
    return 0xFFFFFFFFi64;
  v4 = 16i64 * v2;
  while ( 1 )
  {
    v5 = *(_QWORD *)&v3->m_type.m_storage;
    v6 = v3->vfptr;
    v7 = *(signed int *)((char *)&v6->getNumChildShapes + v4);
    v8 = *(signed int *)((char *)&v6->__vecDelDtor + v4 + 4);
    v9 = *(signed int *)((char *)&v6->__vecDelDtor + v4);
    tolerance.m_real = _mm_shuffle_ps(
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         (__m128)LODWORD(hkDefaultTriangleDegeneracyTolerance),
                         0);
    if ( !hkcdTriangleUtil::isDegenerate(
            (hkVector4f *)(v5 + 16 * v9),
            (hkVector4f *)(v5 + 16 * v8),
            (hkVector4f *)(v5 + 16 * v7),
            &tolerance) )
      break;
    ++v2;
    v4 += 16i64;
    if ( v2 >= *(_DWORD *)&v3->m_disableWelding.m_bool )
      return 0xFFFFFFFFi64;
  }
  return (unsigned int)v2;
}

