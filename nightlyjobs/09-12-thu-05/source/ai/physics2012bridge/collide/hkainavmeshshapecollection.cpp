// File Line: 31
// RVA: 0xC309B0
void __fastcall hkaiNavMeshFaceShape::getAabb(
        hkaiNavMeshFaceShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  hkaiNavMesh *m_faceIndex; // rdx
  hkaiNavMesh *m_navMesh; // rcx
  hkAabb *aabbOut[2]; // [rsp+20h] [rbp-48h] BYREF
  hkSimdFloat32 v9; // [rsp+30h] [rbp-38h] BYREF
  hkAabb extraRadius; // [rsp+40h] [rbp-28h] BYREF

  m_faceIndex = (hkaiNavMesh *)(unsigned int)this->m_faceIndex;
  m_navMesh = this->m_navMesh;
  *(hkVector4f *)aabbOut = (hkVector4f)::aabbOut.m_quad;
  hkaiNavMeshUtils::calcFaceAabb<hkaiNavMesh>(
    (hkaiNavMeshUtils *)m_navMesh,
    m_faceIndex,
    (__m128 *)aabbOut,
    (hkSimdFloat32 *)&extraRadius);
  v9.m_real = _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0);
  hkAabbUtil::calcAabb(localToWorld, &extraRadius, &v9, out);
}

// File Line: 39
// RVA: 0xC308B0
hkBool *__fastcall hkaiNavMeshFaceShape::castRay(
        hkaiNavMeshFaceShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *output)
{
  hkaiNavMesh *m_faceIndex; // rdx
  hkaiNavMesh *m_navMesh; // rcx
  hkVector4f v9; // xmm6
  hkVector4f v10; // xmm7
  __m128i v11; // xmm6
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  char v14; // al
  float v15; // xmm0_4
  int v16; // eax
  hkcdRay ray; // [rsp+20h] [rbp-68h] BYREF
  __m128 v19; // [rsp+50h] [rbp-38h]

  m_faceIndex = (hkaiNavMesh *)(unsigned int)this->m_faceIndex;
  m_navMesh = this->m_navMesh;
  v9.m_quad = (__m128)input->m_to;
  ray.m_origin = (hkVector4f)xmmword_141A712A0;
  v10.m_quad = (__m128)input->m_from;
  v11 = (__m128i)_mm_sub_ps(v9.m_quad, input->m_from.m_quad);
  v12 = _mm_cmpeq_ps((__m128)0i64, (__m128)v11);
  v13 = _mm_rcp_ps((__m128)v11);
  ray.m_invDirection.m_quad = _mm_shuffle_ps((__m128)v11, _mm_unpackhi_ps((__m128)v11, query.m_quad), 196);
  v19 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v11, 0x1Fu), 0x1Fu), (__m128)_xmm), v12),
          _mm_andnot_ps(v12, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v13, (__m128)v11)), v13)));
  ray.m_direction = (hkVector4f)v10.m_quad;
  v19.m128_i32[3] = _mm_movemask_ps(_mm_cmple_ps((__m128)0i64, ray.m_invDirection.m_quad)) & 7 | 0x3F000000;
  v14 = hkaiNavMeshUtils::castRayFace<hkaiNavMesh>(
          (hkaiNavMeshUtils *)m_navMesh,
          m_faceIndex,
          &ray.m_direction.m_quad,
          &ray,
          (hkSimdFloat32 *)0x7F7FFFEE7F7FFFEEi64);
  v15 = ray.m_origin.m_quad.m128_f32[0];
  if ( v14 && ray.m_origin.m_quad.m128_f32[0] < output->m_hitFraction )
  {
    v16 = this->m_faceIndex;
    result->m_bool = 1;
    output->m_shapeKeys[0] = v16;
    output->m_hitFraction = v15;
  }
  else
  {
    result->m_bool = 0;
  }
  return result;
}

// File Line: 59
// RVA: 0xC30B50
__int64 __fastcall hkaiNavMeshFaceShape::getNextKey(hkaiNavMeshFaceShape *this, unsigned int oldKey)
{
  if ( oldKey == *(__int16 *)(*(_QWORD *)(this->m_userData + 16) + 16i64 * *(int *)&this->m_type.m_storage + 8) - 3 )
    return 0xFFFFFFFFi64;
  else
    return oldKey + 1;
}

// File Line: 66
// RVA: 0xC30A20
hkpShape *__fastcall hkaiNavMeshFaceShape::getChildShape(
        hkaiNavMeshFaceShape *this,
        unsigned int key,
        char (*buffer)[512])
{
  _QWORD *m_userData; // r10
  __int64 v4; // r9
  __int128 v5; // xmm0
  int v6; // eax
  __int64 v7; // rdx
  __int64 v8; // rcx
  __int128 v9; // xmm1
  __int128 v10; // xmm2
  hkpShape *result; // rax

  m_userData = (_QWORD *)this->m_userData;
  v4 = *(int *)(m_userData[2] + 16i64 * *(int *)&this->m_type.m_storage);
  v5 = *(_OWORD *)(m_userData[6] + 16i64 * *(int *)(m_userData[4] + 20 * v4));
  v6 = key + 1;
  v7 = m_userData[6];
  v8 = m_userData[4];
  v9 = *(_OWORD *)(v7 + 16i64 * *(int *)(v8 + 20i64 * ((int)v4 + v6)));
  v10 = *(_OWORD *)(v7 + 16i64 * *(int *)(v8 + 20i64 * ((int)v4 + v6) + 4));
  result = 0i64;
  if ( buffer )
  {
    *(_DWORD *)&(*buffer)[8] = 0x1FFFF;
    *(_DWORD *)&(*buffer)[16] = 1026;
    *(_OWORD *)&(*buffer)[48] = v5;
    *(_QWORD *)&(*buffer)[24] = 0i64;
    *(_OWORD *)&(*buffer)[64] = v9;
    *(_OWORD *)&(*buffer)[80] = v10;
    *(_DWORD *)&(*buffer)[32] = 0;
    *(_DWORD *)&(*buffer)[40] = 393216;
    *(_QWORD *)buffer = &hkpTriangleShape::`vftable;
    *(_OWORD *)&(*buffer)[96] = 0i64;
    return (hkpShape *)*buffer;
  }
  return result;
}

// File Line: 80
// RVA: 0xC30AD0
float __fastcall hkaiNavMeshFaceShape::getMaximumProjection(hkaiNavMeshFaceShape *this, hkVector4f *direction)
{
  hkaiNavMesh *m_navMesh; // r9
  hkaiNavMesh::Face *v3; // r8
  __m128 v4; // xmm3
  __int64 m_numEdges; // r10
  __m128 m_quad; // xmm4
  hkaiNavMesh::Edge *v7; // rdx
  __int64 m_a; // rax
  __m128 v9; // xmm2

  m_navMesh = this->m_navMesh;
  v3 = &m_navMesh->m_faces.m_data[this->m_faceIndex];
  v4 = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A712A0);
  m_numEdges = v3->m_numEdges;
  if ( (int)m_numEdges <= 0 )
    return v4.m128_f32[0];
  m_quad = direction->m_quad;
  v7 = &m_navMesh->m_edges.m_data[v3->m_startEdgeIndex];
  do
  {
    m_a = v7->m_a;
    ++v7;
    v9 = _mm_mul_ps(m_navMesh->m_vertices.m_data[m_a].m_quad, m_quad);
    v4 = _mm_max_ps(
           v4,
           _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170)));
    --m_numEdges;
  }
  while ( m_numEdges );
  return v4.m128_f32[0];
}

// File Line: 101
// RVA: 0xC305C0
void __fastcall hkaiNavMeshShapeCollection::hkaiNavMeshShapeCollection(
        hkaiNavMeshShapeCollection *this,
        hkaiNavMesh *navMesh)
{
  hkaiNavMesh *m_pntr; // rcx

  hkpShapeCollection::hkpShapeCollection(this, COLLECTION, COLLECTION_USER);
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshShapeCollection::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkaiNavMeshShapeCollection::`vftable{for `hkpShapeContainer};
  this->m_navMesh.m_pntr = 0i64;
  if ( navMesh )
    hkReferencedObject::addReference(navMesh);
  m_pntr = this->m_navMesh.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_navMesh.m_pntr = navMesh;
}

// File Line: 106
// RVA: 0xC30690
__int64 __fastcall hkaiNavMeshShapeCollection::getFirstKey(hkaiNavMeshShapeCollection *this)
{
  __int64 result; // rax

  result = 0i64;
  if ( !*(_DWORD *)(*(_QWORD *)&this->m_type.m_storage + 24i64) )
    return 0xFFFFFFFFi64;
  return result;
}

// File Line: 115
// RVA: 0xC306B0
__int64 __fastcall hkaiNavMeshShapeCollection::getNextKey(hkaiNavMeshShapeCollection *this, unsigned int oldKey)
{
  int v2; // eax

  v2 = *(_DWORD *)(*(_QWORD *)&this->m_type.m_storage + 24i64);
  if ( v2 && oldKey != v2 - 1 )
    return oldKey + 1;
  else
    return 0xFFFFFFFFi64;
}

// File Line: 124
// RVA: 0xC306D0
hkpShapeCollection *__fastcall hkaiNavMeshShapeCollection::getChildShape(
        hkaiNavMeshShapeCollection *this,
        unsigned int key,
        hkpShapeCollection *buffer)
{
  hkpShapeCollection *v3; // rbx

  v3 = buffer;
  if ( buffer )
  {
    hkpShapeCollection::hkpShapeCollection(buffer, COLLECTION, COLLECTION_USER);
    v3->hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshFaceShape::`vftable{for `hkpShape};
    v3->hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkaiNavMeshFaceShape::`vftable{for `hkpShapeContainer};
  }
  else
  {
    v3 = 0i64;
  }
  LODWORD(v3[1].hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr) = key;
  *(_QWORD *)&v3[1].m_memSizeAndFlags = *(_QWORD *)&this->m_type.m_storage;
  return v3;
}

// File Line: 132
// RVA: 0xC30740
__int64 __fastcall hkaiNavMeshShapeCollection::getNumChildShapes(hkaiNavMeshShapeCollection *this)
{
  return *(unsigned int *)(*(_QWORD *)&this->m_type.m_storage + 24i64);
}

// File Line: 137
// RVA: 0xC30750
void __fastcall hkaiNavMeshShapeCollection::getAabb(
        hkaiNavMeshShapeCollection *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  hkAabb *p_m_aabb; // rdx
  hkSimdFloat32 extraRadius; // [rsp+20h] [rbp-18h] BYREF

  p_m_aabb = &this->m_navMesh.m_pntr->m_aabb;
  extraRadius.m_real = _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0);
  hkAabbUtil::calcAabb(localToWorld, p_m_aabb, &extraRadius, out);
}

// File Line: 143
// RVA: 0xC30630
void __fastcall hkaiNavMeshShapeCollection::~hkaiNavMeshShapeCollection(hkaiNavMeshShapeCollection *this)
{
  hkaiNavMesh *m_pntr; // rcx

  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshShapeCollection::`vftable{for `hkpShape};
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkaiNavMeshShapeCollection::`vftable{for `hkpShapeContainer};
  m_pntr = this->m_navMesh.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_navMesh.m_pntr = 0i64;
  this->hkpShapeCollection::hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  this->hkpShapeCollection::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

