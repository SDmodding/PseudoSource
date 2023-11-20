// File Line: 31
// RVA: 0xC309B0
void __fastcall hkaiNavMeshFaceShape::getAabb(hkaiNavMeshFaceShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  hkTransformf *v4; // rdi
  hkaiNavMesh *v5; // rdx
  hkaiNavMesh *v6; // rcx
  hkAabb *v7; // rbx
  hkAabb *aabbOut[2]; // [rsp+20h] [rbp-48h]
  hkSimdFloat32 v9; // [rsp+30h] [rbp-38h]
  hkSimdFloat32 extraRadius; // [rsp+40h] [rbp-28h]

  v4 = localToWorld;
  v5 = (hkaiNavMesh *)(unsigned int)this->m_faceIndex;
  v6 = this->m_navMesh;
  v7 = out;
  *(hkVector4f *)aabbOut = (hkVector4f)::aabbOut.m_quad;
  hkaiNavMeshUtils::calcFaceAabb<hkaiNavMesh>((hkaiNavMeshUtils *)v6, v5, (__int64)aabbOut, &extraRadius);
  v9.m_real = _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0);
  hkAabbUtil::calcAabb(v4, (hkAabb *)&extraRadius, &v9, v7);
}

// File Line: 39
// RVA: 0xC308B0
hkBool *__fastcall hkaiNavMeshFaceShape::castRay(hkaiNavMeshFaceShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *output)
{
  hkBool *v4; // rbx
  hkaiNavMesh *v5; // rdx
  hkaiNavMeshFaceShape *v6; // rsi
  hkaiNavMesh *v7; // rcx
  hkpShapeRayCastOutput *v8; // rdi
  hkVector4f v9; // xmm6
  hkVector4f v10; // xmm7
  __m128i v11; // xmm6
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  char v14; // al
  int v15; // xmm0_4
  int v16; // eax
  hkcdRay ray; // [rsp+20h] [rbp-68h]
  __m128 v19; // [rsp+50h] [rbp-38h]

  v4 = result;
  v5 = (hkaiNavMesh *)(unsigned int)this->m_faceIndex;
  v6 = this;
  v7 = this->m_navMesh;
  v8 = output;
  v9.m_quad = (__m128)input->m_to;
  ray.m_origin = (hkVector4f)xmmword_141A712A0;
  v10.m_quad = (__m128)input->m_from;
  v11 = (__m128i)_mm_sub_ps(v9.m_quad, input->m_from.m_quad);
  v12 = _mm_cmpeqps((__m128)0i64, (__m128)v11);
  v13 = _mm_rcp_ps((__m128)v11);
  ray.m_invDirection.m_quad = _mm_shuffle_ps((__m128)v11, _mm_unpackhi_ps((__m128)v11, query.m_quad), 196);
  v19 = _mm_or_ps(
          _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v11, 0x1Fu), 0x1Fu), (__m128)_xmm), v12),
          _mm_andnot_ps(v12, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v13, (__m128)v11)), v13)));
  ray.m_direction = (hkVector4f)v10.m_quad;
  v19.m128_i32[3] = _mm_movemask_ps(_mm_cmpleps((__m128)0i64, ray.m_invDirection.m_quad)) & 7 | 0x3F000000;
  v14 = hkaiNavMeshUtils::castRayFace<hkaiNavMesh>(
          (hkaiNavMeshUtils *)v7,
          v5,
          (__int64)&ray.m_direction,
          &ray,
          (hkSimdFloat32 *)xmmword_141A712A0);
  v15 = ray.m_origin.m_quad.m128_i32[0];
  if ( v14 && ray.m_origin.m_quad.m128_f32[0] < v8->m_hitFraction )
  {
    v16 = v6->m_faceIndex;
    v4->m_bool = 1;
    v8->m_shapeKeys[0] = v16;
    LODWORD(v8->m_hitFraction) = v15;
  }
  else
  {
    v4->m_bool = 0;
  }
  return v4;
}

// File Line: 59
// RVA: 0xC30B50
signed __int64 __fastcall hkaiNavMeshFaceShape::getNextKey(hkaiNavMeshFaceShape *this, unsigned int oldKey)
{
  signed __int64 result; // rax

  if ( oldKey == *(signed __int16 *)(*(_QWORD *)(this->m_userData + 16)
                                   + 16i64 * *(signed int *)&this->m_type.m_storage
                                   + 8)
               - 3 )
    result = 0xFFFFFFFFi64;
  else
    result = oldKey + 1;
  return result;
}

// File Line: 66
// RVA: 0xC30A20
hkpShape *__fastcall hkaiNavMeshFaceShape::getChildShape(hkaiNavMeshFaceShape *this, unsigned int key, char (*buffer)[512])
{
  _QWORD *v3; // r10
  __int64 v4; // r9
  __int128 v5; // xmm0
  unsigned int v6; // eax
  __int64 v7; // rdx
  __int64 v8; // rcx
  __int128 v9; // xmm1
  __int128 v10; // xmm2
  hkpShape *result; // rax

  v3 = (_QWORD *)this->m_userData;
  v4 = *(signed int *)(v3[2] + 16i64 * *(signed int *)&this->m_type.m_storage);
  v5 = *(_OWORD *)(v3[6] + 16i64 * *(signed int *)(v3[4] + 20 * v4));
  v6 = key + 1;
  v7 = v3[6];
  v8 = v3[4];
  v9 = *(_OWORD *)(v7 + 16i64 * *(signed int *)(v8 + 20i64 * (signed int)(v4 + v6)));
  v10 = *(_OWORD *)(v7 + 16i64 * *(signed int *)(v8 + 20i64 * (signed int)(v4 + v6) + 4));
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
    result = (hkpShape *)buffer;
  }
  return result;
}

// File Line: 80
// RVA: 0xC30AD0
float __fastcall hkaiNavMeshFaceShape::getMaximumProjection(hkaiNavMeshFaceShape *this, hkVector4f *direction)
{
  hkaiNavMesh *v2; // r9
  hkaiNavMesh::Face *v3; // r8
  __m128 v4; // xmm3
  __int64 v5; // r10
  __m128 v6; // xmm4
  hkaiNavMesh::Edge *v7; // rdx
  __int64 v8; // rax
  __m128 v9; // xmm2

  v2 = this->m_navMesh;
  v3 = &v2->m_faces.m_data[this->m_faceIndex];
  v4 = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A712A0);
  v5 = v3->m_numEdges;
  if ( (signed int)v5 <= 0 )
    return v4.m128_f32[0];
  v6 = direction->m_quad;
  v7 = &v2->m_edges.m_data[v3->m_startEdgeIndex];
  do
  {
    v8 = v7->m_a;
    ++v7;
    v9 = _mm_mul_ps(v2->m_vertices.m_data[v8].m_quad, v6);
    v4 = _mm_max_ps(
           v4,
           _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170)));
    --v5;
  }
  while ( v5 );
  return v4.m128_f32[0];
}

// File Line: 101
// RVA: 0xC305C0
void __fastcall hkaiNavMeshShapeCollection::hkaiNavMeshShapeCollection(hkaiNavMeshShapeCollection *this, hkaiNavMesh *navMesh)
{
  hkaiNavMesh *v2; // rdi
  hkaiNavMeshShapeCollection *v3; // rbx
  hkReferencedObject *v4; // rcx

  v2 = navMesh;
  v3 = this;
  hkpShapeCollection::hkpShapeCollection((hkpShapeCollection *)&this->vfptr, COLLECTION, COLLECTION_USER);
  v3->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshShapeCollection::`vftable{for `hkpShape};
  v3->vfptr = (hkpShapeContainerVtbl *)&hkaiNavMeshShapeCollection::`vftable{for `hkpShapeContainer};
  v3->m_navMesh.m_pntr = 0i64;
  if ( v2 )
    hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
  v4 = (hkReferencedObject *)&v3->m_navMesh.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_navMesh.m_pntr = v2;
}

// File Line: 106
// RVA: 0xC30690
signed __int64 __fastcall hkaiNavMeshShapeCollection::getFirstKey(hkaiNavMeshShapeCollection *this)
{
  signed __int64 result; // rax

  result = 0i64;
  if ( !*(_DWORD *)(*(_QWORD *)&this->m_type.m_storage + 24i64) )
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 115
// RVA: 0xC306B0
signed __int64 __fastcall hkaiNavMeshShapeCollection::getNextKey(hkaiNavMeshShapeCollection *this, unsigned int oldKey)
{
  int v2; // eax
  signed __int64 result; // rax

  v2 = *(_DWORD *)(*(_QWORD *)&this->m_type.m_storage + 24i64);
  if ( v2 && oldKey != v2 - 1 )
    result = oldKey + 1;
  else
    result = 0xFFFFFFFFi64;
  return result;
}

// File Line: 124
// RVA: 0xC306D0
hkpShape *__fastcall hkaiNavMeshShapeCollection::getChildShape(hkaiNavMeshShapeCollection *this, unsigned int key, char (*buffer)[512])
{
  char (*v3)[512]; // rbx
  unsigned int v4; // edi
  hkaiNavMeshShapeCollection *v5; // rsi

  v3 = buffer;
  v4 = key;
  v5 = this;
  if ( buffer )
  {
    hkpShapeCollection::hkpShapeCollection((hkpShapeCollection *)buffer, COLLECTION, COLLECTION_USER);
    *(_QWORD *)v3 = &hkaiNavMeshFaceShape::`vftable{for `hkpShape};
    *(_QWORD *)&(*v3)[32] = &hkaiNavMeshFaceShape::`vftable{for `hkpShapeContainer};
  }
  else
  {
    v3 = 0i64;
  }
  *(_DWORD *)&(*v3)[48] = v4;
  *(_QWORD *)&(*v3)[56] = *(_QWORD *)&v5->m_type.m_storage;
  return (hkpShape *)v3;
}

// File Line: 132
// RVA: 0xC30740
__int64 __fastcall hkaiNavMeshShapeCollection::getNumChildShapes(hkaiNavMeshShapeCollection *this)
{
  return *(unsigned int *)(*(_QWORD *)&this->m_type.m_storage + 24i64);
}

// File Line: 137
// RVA: 0xC30750
void __fastcall hkaiNavMeshShapeCollection::getAabb(hkaiNavMeshShapeCollection *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  hkTransformf *v4; // rax
  hkAabb *v5; // rdx
  hkSimdFloat32 extraRadius; // [rsp+20h] [rbp-18h]

  v4 = localToWorld;
  v5 = &this->m_navMesh.m_pntr->m_aabb;
  extraRadius.m_real = _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0);
  hkAabbUtil::calcAabb(v4, v5, &extraRadius, out);
}

// File Line: 143
// RVA: 0xC30630
void __fastcall hkaiNavMeshShapeCollection::~hkaiNavMeshShapeCollection(hkaiNavMeshShapeCollection *this)
{
  hkaiNavMeshShapeCollection *v1; // rbx
  hkaiNavMesh *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavMeshShapeCollection::`vftable{for `hkpShape};
  this->vfptr = (hkpShapeContainerVtbl *)&hkaiNavMeshShapeCollection::`vftable{for `hkpShapeContainer};
  v2 = this->m_navMesh.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_navMesh.m_pntr = 0i64;
  v1->vfptr = (hkpShapeContainerVtbl *)&hkpShapeContainer::`vftable;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

