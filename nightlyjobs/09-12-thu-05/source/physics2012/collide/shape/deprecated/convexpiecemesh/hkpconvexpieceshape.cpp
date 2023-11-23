// File Line: 19
// RVA: 0xD34F30
void __fastcall hkpConvexPieceShape::hkpConvexPieceShape(hkpConvexPieceShape *this, float radius)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1047;
  this->m_radius = radius;
  this->hkpConvexShape::hkpSphereRepShape::hkpShape::hkpShapeBase::hkcdShape::hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpConvexPieceShape::`vftable{for `hkpConvexShape};
  this->m_userData = 0i64;
  this->hkpShapeContainer::vfptr = (hkpShapeContainerVtbl *)&hkpConvexPieceShape::`vftable{for `hkpShapeContainer};
}

// File Line: 24
// RVA: 0xD35140
void __fastcall hkpConvexPieceShape::getFirstVertex(hkpConvexPieceShape *this, hkVector4f *v)
{
  *v = (hkVector4f)this->m_vertices->m_quad;
}

// File Line: 30
// RVA: 0xD35160
// local variable allocation has failed, the output may be wrong!
void __fastcall hkpConvexPieceShape::getAabb(
        hkpConvexPieceShape *this,
        hkTransformf *localToWorld,
        double tolerance,
        hkAabb *out)
{
  int v5; // edx
  float v6; // xmm5_4
  hkVector4f v7; // xmm3
  __m128 m_quad; // xmm4
  __int64 v9; // r10
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm2

  v5 = 0;
  v6 = *(float *)&tolerance;
  out->m_min.m_quad = _mm_shuffle_ps(
                        (__m128)xmmword_141A712A0,
                        _mm_unpackhi_ps((__m128)xmmword_141A712A0, out->m_min.m_quad),
                        196);
  v7.m_quad = _mm_shuffle_ps(
                (__m128)xmmword_141A712F0,
                _mm_unpackhi_ps((__m128)xmmword_141A712F0, out->m_max.m_quad),
                196);
  out->m_max = (hkVector4f)v7.m_quad;
  if ( this->m_numVertices > 0 )
  {
    m_quad = out->m_min.m_quad;
    v9 = 0i64;
    do
    {
      ++v5;
      v10 = this->m_vertices[v9++].m_quad;
      *(__m128 *)&tolerance = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), localToWorld->m_rotation.m_col1.m_quad),
                                    _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), localToWorld->m_rotation.m_col0.m_quad)),
                                  _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), localToWorld->m_rotation.m_col2.m_quad)),
                                localToWorld->m_translation.m_quad);
      m_quad = _mm_min_ps(m_quad, *(__m128 *)&tolerance);
      v7.m_quad = _mm_max_ps(v7.m_quad, *(__m128 *)&tolerance);
      out->m_min.m_quad = m_quad;
      out->m_max = (hkVector4f)v7.m_quad;
    }
    while ( v5 < this->m_numVertices );
  }
  *(float *)&tolerance = v6 + this->m_radius;
  v11 = _mm_shuffle_ps(*(__m128 *)&tolerance, *(__m128 *)&tolerance, 0);
  v12 = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, (__m128)0i64), 196);
  out->m_min.m_quad = _mm_sub_ps(out->m_min.m_quad, v12);
  out->m_max.m_quad = _mm_add_ps(v12, out->m_max.m_quad);
}

// File Line: 48
// RVA: 0xD35560
__int64 __fastcall hkpConvexPieceShape::getNumCollisionSpheres(hkpConvexPieceShape *this)
{
  return (unsigned int)this->m_numVertices;
}

// File Line: 53
// RVA: 0xD35570
hkSphere *__fastcall hkpConvexPieceShape::getCollisionSpheres(hkpConvexPieceShape *this, hkSphere *sphereBuffer)
{
  int v2; // r8d
  hkSphere *v3; // r10
  __int64 v4; // r9

  v2 = 0;
  v3 = sphereBuffer;
  if ( this->m_numVertices > 0 )
  {
    v4 = 0i64;
    do
    {
      ++v2;
      ++v3;
      ++v4;
      v3[-1].m_pos.m_quad = _mm_shuffle_ps(
                              this->m_vertices[v4 - 1].m_quad,
                              _mm_unpackhi_ps(
                                this->m_vertices[v4 - 1].m_quad,
                                _mm_shuffle_ps((__m128)LODWORD(this->m_radius), (__m128)LODWORD(this->m_radius), 0)),
                              196);
    }
    while ( v2 < this->m_numVertices );
  }
  return sphereBuffer;
}

// File Line: 67
// RVA: 0xD34F70
void __fastcall hkpConvexPieceShape::getSupportingVertex(
        hkpConvexPieceShape *this,
        hkVector4f *dir,
        hkcdVertex *supportingVertex)
{
  int v3; // esi
  float v4; // xmm6_4
  int v5; // ebx
  __int64 v9; // r14
  int v10; // edi
  hkpShape *v11; // rax
  __m128 v12; // xmm1
  float v13; // xmm3_4
  unsigned __int16 epi16; // ax
  hkcdVertex v15; // [rsp+20h] [rbp-238h] BYREF
  char v16[528]; // [rsp+30h] [rbp-228h] BYREF

  v3 = 0;
  v4 = -3.40282e38;
  v5 = 0;
  if ( this->m_numDisplayShapeKeys > 0 )
  {
    v9 = 0i64;
    v10 = 0;
    do
    {
      v11 = this->m_displayMesh->vfptr->getChildShape(
              &this->m_displayMesh->hkpShapeContainer,
              this->m_displayShapeKeys[v9],
              v16);
      ((void (__fastcall *)(hkpShape *, hkVector4f *, hkcdVertex *))v11->vfptr[4].__vecDelDtor)(v11, dir, &v15);
      v12 = _mm_mul_ps(dir->m_quad, v15.m_quad);
      v13 = (float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0] + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
          + _mm_shuffle_ps(v12, v12, 170).m128_f32[0];
      if ( v13 > v4 )
      {
        epi16 = _mm_extract_epi16((__m128i)v15.m_quad, 6);
        v4 = v13;
        *supportingVertex = (hkcdVertex)v15.m_quad;
        v3 = v10 + (epi16 >> 4);
      }
      ++v5;
      v10 += 3;
      ++v9;
    }
    while ( v5 < this->m_numDisplayShapeKeys );
  }
  supportingVertex->m_quad.m128_i32[3] = v3 | 0x3F000000;
}

// File Line: 90
// RVA: 0xD35080
void __fastcall hkpConvexPieceShape::convertVertexIdsToVertices(
        hkpConvexPieceShape *this,
        const unsigned __int16 *ids,
        int numIds,
        hkcdVertex *verticesOut)
{
  int i; // ebp
  int v8; // edi
  char v9[536]; // [rsp+20h] [rbp-218h] BYREF

  for ( i = numIds - 1; i >= 0; verticesOut[-1].m_quad.m128_i32[3] = v8 | 0x3F000000 )
  {
    v8 = *ids;
    ++verticesOut;
    ++ids;
    --i;
    verticesOut[-1] = *((hkcdVertex *)&this->m_displayMesh->vfptr->getChildShape(
                                         &this->m_displayMesh->hkpShapeContainer,
                                         this->m_displayShapeKeys[v8 / 3],
                                         v9)[1].m_type.m_storage
                      + v8 % 3);
  }
}

// File Line: 108
// RVA: 0xD35240
hkBool *__fastcall hkpConvexPieceShape::castRay(
        hkpConvexPieceShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  int v12; // edi
  unsigned int v13; // r15d
  __int64 v14; // rsi
  hkpRayShapeCollectionFilter *m_rayShapeCollectionFilter; // rcx
  hkpShapeCollection *m_displayMesh; // rax
  hkpShapeContainer *v17; // r9
  hkpShape *v18; // rax
  _QWORD *v19; // rax
  _QWORD *v20; // rcx
  _QWORD *v21; // r8
  unsigned __int64 v22; // rax
  _QWORD *v23; // rcx
  char v25[512]; // [rsp+30h] [rbp-228h] BYREF
  char v26; // [rsp+260h] [rbp+8h] BYREF
  char v27; // [rsp+268h] [rbp+10h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcConvxPiece";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  ++results->m_shapeKeyIndex;
  v12 = 0;
  v13 = -1;
  if ( this->m_numDisplayShapeKeys > 0 )
  {
    v14 = 0i64;
    do
    {
      m_rayShapeCollectionFilter = input->m_rayShapeCollectionFilter;
      if ( !m_rayShapeCollectionFilter
        || ((m_displayMesh = this->m_displayMesh) == 0i64 ? (v17 = 0i64) : (v17 = &m_displayMesh->hkpShapeContainer),
            *(_BYTE *)m_rayShapeCollectionFilter->vfptr->isCollisionEnabled(
                        m_rayShapeCollectionFilter,
                        (hkBool *)&v26,
                        input,
                        v17,
                        this->m_displayShapeKeys[v14])) )
      {
        v18 = this->m_displayMesh->vfptr->getChildShape(
                &this->m_displayMesh->hkpShapeContainer,
                this->m_displayShapeKeys[v14],
                v25);
        if ( *(_BYTE *)((__int64 (__fastcall *)(hkpShape *, char *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))v18->vfptr[2].__first_virtual_table_function__)(
                         v18,
                         &v27,
                         input,
                         results) )
          v13 = v12;
      }
      ++v12;
      ++v14;
    }
    while ( v12 < this->m_numDisplayShapeKeys );
  }
  --results->m_shapeKeyIndex;
  if ( v13 != -1 )
    results->m_shapeKeys[results->m_shapeKeyIndex] = v13;
  v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v20 = (_QWORD *)v19[1];
  v21 = v19;
  if ( (unsigned __int64)v20 < v19[3] )
  {
    *v20 = "Et";
    v22 = __rdtsc();
    v23 = v20 + 2;
    *((_DWORD *)v23 - 2) = v22;
    v21[1] = v23;
  }
  result->m_bool = v13 != -1;
  return result;
}

// File Line: 150
// RVA: 0xD353E0
void __fastcall hkpConvexPieceShape::castRayWithCollector(
        hkpConvexPieceShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  int v13; // ebx
  __int64 v14; // rsi
  hkpRayShapeCollectionFilter *m_rayShapeCollectionFilter; // rcx
  hkpShapeCollection *m_displayMesh; // rax
  hkpShapeContainer *v17; // r9
  hkpShape *v18; // rax
  const void *m_motion; // rcx
  _QWORD *v20; // rax
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  hkpShape *v25; // [rsp+30h] [rbp-238h] BYREF
  int v26; // [rsp+38h] [rbp-230h]
  const void *v27; // [rsp+40h] [rbp-228h]
  hkpCdBody *v28; // [rsp+48h] [rbp-220h]
  char v29[512]; // [rsp+50h] [rbp-218h] BYREF
  char v30; // [rsp+270h] [rbp+8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcConvxPiece";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  v13 = 0;
  if ( this->m_numDisplayShapeKeys > 0 )
  {
    v14 = 0i64;
    do
    {
      m_rayShapeCollectionFilter = input->m_rayShapeCollectionFilter;
      if ( !m_rayShapeCollectionFilter
        || ((m_displayMesh = this->m_displayMesh) == 0i64 ? (v17 = 0i64) : (v17 = &m_displayMesh->hkpShapeContainer),
            *(_BYTE *)m_rayShapeCollectionFilter->vfptr->isCollisionEnabled(
                        m_rayShapeCollectionFilter,
                        (hkBool *)&v30,
                        input,
                        v17,
                        this->m_displayShapeKeys[v14])) )
      {
        v18 = this->m_displayMesh->vfptr->getChildShape(
                &this->m_displayMesh->hkpShapeContainer,
                this->m_displayShapeKeys[v14],
                v29);
        m_motion = cdBody->m_motion;
        v28 = cdBody;
        v27 = m_motion;
        v25 = v18;
        v26 = v13;
        ((void (__fastcall *)(hkpShape *, hkpShapeRayCastInput *, hkpShape **, hkpRayHitCollector *))v18->vfptr[3].__vecDelDtor)(
          v18,
          input,
          &v25,
          collector);
      }
      ++v13;
      ++v14;
    }
    while ( v13 < this->m_numDisplayShapeKeys );
  }
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  v22 = v20;
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Et";
    v23 = __rdtsc();
    v24 = v21 + 2;
    *((_DWORD *)v24 - 2) = v23;
    v22[1] = v24;
  }
}

// File Line: 183
// RVA: 0xD355C0
hkpShapeContainer *__fastcall hkpConvexPieceShape::getContainer(hkpConvexPieceShape *this)
{
  if ( this )
    return &this->hkpShapeContainer;
  else
    return 0i64;
}

// File Line: 192
// RVA: 0xD355E0
__int64 __fastcall hkpConvexPieceShape::getFirstKey(hkpConvexPieceShape *this)
{
  return 0i64;
}

// File Line: 197
// RVA: 0xD355F0
__int64 __fastcall hkpConvexPieceShape::getNextKey(hkpConvexPieceShape *this, unsigned int oldKey)
{
  unsigned int v2; // edx
  __int64 result; // rax

  v2 = oldKey + 1;
  result = 0xFFFFFFFFi64;
  if ( (signed int)v2 < SLODWORD(this->hkpShapeContainer::vfptr) )
    return v2;
  return result;
}

// File Line: 205
// RVA: 0xD35610
hkpShape *__fastcall hkpConvexPieceShape::getChildShape(
        hkpConvexPieceShape *this,
        unsigned int key,
        char (*buffer)[512])
{
  return (hkpShape *)(*(__int64 (__fastcall **)(unsigned __int64, _QWORD, char (*)[512]))(*(_QWORD *)(this->m_userData + 32)
                                                                                        + 40i64))(
                       this->m_userData + 32,
                       *(unsigned int *)(*(_QWORD *)&this->m_radius + 4i64 * key),
                       buffer);
}

