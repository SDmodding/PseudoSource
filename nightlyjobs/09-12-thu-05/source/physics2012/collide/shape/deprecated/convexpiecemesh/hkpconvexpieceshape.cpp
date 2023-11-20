// File Line: 19
// RVA: 0xD34F30
void __fastcall hkpConvexPieceShape::hkpConvexPieceShape(hkpConvexPieceShape *this, float radius)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1047;
  this->m_radius = radius;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexPieceShape::`vftable'{for `hkpConvexShape'};
  this->m_userData = 0i64;
  this->vfptr = (hkpShapeContainerVtbl *)&hkpConvexPieceShape::`vftable'{for `hkpShapeContainer'};
}

// File Line: 24
// RVA: 0xD35140
void __fastcall hkpConvexPieceShape::getFirstVertex(hkpConvexPieceShape *this, hkVector4f *v)
{
  *v = (hkVector4f)this->m_vertices->m_quad;
}

// File Line: 30
// RVA: 0xD35160
int hkpConvexPieceShape::getAabb(...)
{
  hkTransformf *v4; // r8
  int v5; // edx
  float v6; // xmm5_4
  hkVector4f v7; // xmm3
  __m128 v8; // xmm4
  __int64 v9; // r10
  hkVector4f *v10; // rax
  __m128 v11; // xmm1
  __m128 v12; // xmm2
  __m128 v13; // xmm2

  v4 = localToWorld;
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
    v8 = out->m_min.m_quad;
    v9 = 0i64;
    do
    {
      v10 = this->m_vertices;
      ++v5;
      ++v9;
      v11 = v10[v9 - 1].m_quad;
      tolerance = (__int128)_mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v4->m_rotation.m_col1.m_quad),
                                  _mm_mul_ps(_mm_shuffle_ps(v10[v9 - 1].m_quad, v11, 0), v4->m_rotation.m_col0.m_quad)),
                                _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v4->m_rotation.m_col2.m_quad)),
                              v4->m_translation.m_quad);
      v8 = _mm_min_ps(v8, (__m128)tolerance);
      v7.m_quad = _mm_max_ps(v7.m_quad, (__m128)tolerance);
      out->m_min.m_quad = v8;
      out->m_max = (hkVector4f)v7.m_quad;
    }
    while ( v5 < this->m_numVertices );
  }
  *(float *)&tolerance = v6 + this->m_radius;
  v12 = _mm_shuffle_ps((__m128)tolerance, (__m128)tolerance, 0);
  v13 = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, (__m128)0i64), 196);
  out->m_min.m_quad = _mm_sub_ps(out->m_min.m_quad, v13);
  out->m_max.m_quad = _mm_add_ps(v13, out->m_max.m_quad);
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
  int v2; // er8
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
void __fastcall hkpConvexPieceShape::getSupportingVertex(hkpConvexPieceShape *this, hkVector4f *dir, hkcdVertex *supportingVertex)
{
  unsigned int v3; // esi
  float v4; // xmm6_4
  int v5; // ebx
  hkcdVertex *v6; // r15
  hkVector4f *v7; // r12
  hkpConvexPieceShape *v8; // rbp
  __int64 v9; // r14
  int v10; // edi
  __int64 v11; // rax
  __m128 v12; // xmm1
  float v13; // xmm3_4
  unsigned __int16 v14; // ax
  __m128i v15; // [rsp+20h] [rbp-238h]
  char v16; // [rsp+30h] [rbp-228h]

  v3 = 0;
  v4 = *(float *)&xmmword_141A712F0;
  v5 = 0;
  v6 = supportingVertex;
  v7 = dir;
  v8 = this;
  if ( this->m_numDisplayShapeKeys > 0 )
  {
    v9 = 0i64;
    v10 = 0;
    do
    {
      v11 = (__int64)v8->m_displayMesh->vfptr->getChildShape(
                       (hkpShapeContainer *)&v8->m_displayMesh->vfptr,
                       v8->m_displayShapeKeys[v9],
                       (char (*)[512])&v16);
      (*(void (__fastcall **)(__int64, hkVector4f *, __m128i *))(*(_QWORD *)v11 + 64i64))(v11, v7, &v15);
      v12 = _mm_mul_ps(v7->m_quad, (__m128)v15);
      v13 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170));
      if ( v13 > v4 )
      {
        v14 = _mm_extract_epi16(v15, 6);
        v4 = v13;
        *v6 = (hkcdVertex)v15;
        v3 = v10 + ((unsigned int)v14 >> 4);
      }
      ++v5;
      v10 += 3;
      ++v9;
    }
    while ( v5 < v8->m_numDisplayShapeKeys );
  }
  v6->m_quad.m128_i32[3] = v3 | 0x3F000000;
}

// File Line: 90
// RVA: 0xD35080
void __fastcall hkpConvexPieceShape::convertVertexIdsToVertices(hkpConvexPieceShape *this, const unsigned __int16 *ids, int numIds, hkcdVertex *verticesOut)
{
  int v4; // ebp
  hkcdVertex *v5; // rsi
  const unsigned __int16 *v6; // r14
  hkpConvexPieceShape *i; // r15
  int v8; // edi
  int v9; // ebx
  char v10; // [rsp+20h] [rbp-218h]

  v4 = numIds - 1;
  v5 = verticesOut;
  v6 = ids;
  for ( i = this; v4 >= 0; v5[-1].m_quad.m128_i32[3] = v8 | 0x3F000000 )
  {
    v8 = *v6;
    v9 = v8 / 3;
    ++v5;
    ++v6;
    --v4;
    v5[-1] = *(hkcdVertex *)((__int64)i->m_displayMesh->vfptr->getChildShape(
                                        (hkpShapeContainer *)&i->m_displayMesh->vfptr,
                                        i->m_displayShapeKeys[v9],
                                        (char (*)[512])&v10)
                           + 16 * (v8 - 3 * v9 + 3i64));
  }
}

// File Line: 108
// RVA: 0xD35240
hkBool *__fastcall hkpConvexPieceShape::castRay(hkpConvexPieceShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkpConvexPieceShape *v4; // rbx
  hkpShapeRayCastOutput *v5; // rbp
  hkpShapeRayCastInput *v6; // r14
  hkBool *v7; // r12
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  int v12; // edi
  signed int v13; // er15
  __int64 v14; // rsi
  hkpRayShapeCollectionFilter *v15; // rcx
  hkpShapeCollection *v16; // rax
  signed __int64 v17; // r9
  __int64 v18; // rax
  _QWORD *v19; // rax
  _QWORD *v20; // rcx
  _QWORD *v21; // r8
  unsigned __int64 v22; // rax
  signed __int64 v23; // rcx
  __int64 v25[2]; // [rsp+20h] [rbp-238h]
  char v26; // [rsp+30h] [rbp-228h]
  char v27; // [rsp+260h] [rbp+8h]
  char v28; // [rsp+268h] [rbp+10h]

  v4 = this;
  v5 = results;
  v6 = input;
  v7 = result;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcConvxPiece";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  ++v5->m_shapeKeyIndex;
  v12 = 0;
  v13 = -1;
  if ( v4->m_numDisplayShapeKeys > 0 )
  {
    v14 = 0i64;
    do
    {
      v15 = v6->m_rayShapeCollectionFilter;
      if ( !v15
        || ((v16 = v4->m_displayMesh) == 0i64 ? (v17 = 0i64) : (v17 = (signed __int64)&v16->vfptr),
            LODWORD(v25[0]) = v4->m_displayShapeKeys[v14],
            *(_BYTE *)v15->vfptr->isCollisionEnabled(v15, (hkBool *)&v27, v6, (hkpShapeContainer *)v17, v25[0])) )
      {
        v18 = (__int64)v4->m_displayMesh->vfptr->getChildShape(
                         (hkpShapeContainer *)&v4->m_displayMesh->vfptr,
                         v4->m_displayShapeKeys[v14],
                         (char (*)[512])&v26);
        if ( *(_BYTE *)(*(__int64 (__fastcall **)(__int64, char *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))(*(_QWORD *)v18 + 40i64))(
                         v18,
                         &v28,
                         v6,
                         v5) )
          v13 = v12;
      }
      ++v12;
      ++v14;
    }
    while ( v12 < v4->m_numDisplayShapeKeys );
  }
  --v5->m_shapeKeyIndex;
  if ( v13 != -1 )
    v5->m_shapeKeys[v5->m_shapeKeyIndex] = v13;
  v19 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v20 = (_QWORD *)v19[1];
  v21 = v19;
  if ( (unsigned __int64)v20 < v19[3] )
  {
    *v20 = "Et";
    v22 = __rdtsc();
    v23 = (signed __int64)(v20 + 2);
    *(_DWORD *)(v23 - 8) = v22;
    v21[1] = v23;
  }
  v7->m_bool = v13 != -1;
  return v7;
}

// File Line: 150
// RVA: 0xD353E0
void __fastcall hkpConvexPieceShape::castRayWithCollector(hkpConvexPieceShape *this, hkpShapeRayCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkpConvexPieceShape *v4; // rdi
  hkpCdBody *v5; // r14
  hkpShapeRayCastInput *v6; // rbp
  hkpRayHitCollector *v7; // r15
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  int v13; // ebx
  __int64 v14; // rsi
  hkpRayShapeCollectionFilter *v15; // rcx
  hkpShapeCollection *v16; // rax
  signed __int64 v17; // r9
  unsigned int v18; // ST20_4
  __int64 v19; // rax
  __int64 v20; // rcx
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r8
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  __int64 v26; // [rsp+30h] [rbp-238h]
  int v27; // [rsp+38h] [rbp-230h]
  __int64 v28; // [rsp+40h] [rbp-228h]
  hkpCdBody *v29; // [rsp+48h] [rbp-220h]
  char v30; // [rsp+50h] [rbp-218h]
  char v31; // [rsp+270h] [rbp+8h]

  v4 = this;
  v5 = cdBody;
  v6 = input;
  v7 = collector;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcConvxPiece";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = 0;
  if ( v4->m_numDisplayShapeKeys > 0 )
  {
    v14 = 0i64;
    do
    {
      v15 = v6->m_rayShapeCollectionFilter;
      if ( !v15
        || ((v16 = v4->m_displayMesh) == 0i64 ? (v17 = 0i64) : (v17 = (signed __int64)&v16->vfptr),
            v18 = v4->m_displayShapeKeys[v14],
            *(_BYTE *)((__int64 (__fastcall *)(hkpRayShapeCollectionFilter *, char *, hkpShapeRayCastInput *, signed __int64))v15->vfptr->isCollisionEnabled)(
                        v15,
                        &v31,
                        v6,
                        v17)) )
      {
        v19 = (__int64)v4->m_displayMesh->vfptr->getChildShape(
                         (hkpShapeContainer *)&v4->m_displayMesh->vfptr,
                         v4->m_displayShapeKeys[v14],
                         (char (*)[512])&v30);
        v20 = (__int64)v5->m_motion;
        v29 = v5;
        v28 = v20;
        v26 = v19;
        v27 = v13;
        (*(void (__fastcall **)(__int64, hkpShapeRayCastInput *, __int64 *, hkpRayHitCollector *))(*(_QWORD *)v19 + 48i64))(
          v19,
          v6,
          &v26,
          v7);
      }
      ++v13;
      ++v14;
    }
    while ( v13 < v4->m_numDisplayShapeKeys );
  }
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  v23 = v21;
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v24 = __rdtsc();
    v25 = (signed __int64)(v22 + 2);
    *(_DWORD *)(v25 - 8) = v24;
    v23[1] = v25;
  }
}

// File Line: 183
// RVA: 0xD355C0
hkpShapeContainer *__fastcall hkpConvexPieceShape::getContainer(hkpConvexPieceShape *this)
{
  hkpShapeContainer *result; // rax

  if ( this )
    result = (hkpShapeContainer *)&this->vfptr;
  else
    result = 0i64;
  return result;
}

// File Line: 192
// RVA: 0xD355E0
__int64 __fastcall hkpConvexPieceShape::getFirstKey(hkpConvexPieceShape *this)
{
  return 0i64;
}

// File Line: 197
// RVA: 0xD355F0
signed __int64 __fastcall hkpConvexPieceShape::getNextKey(hkpConvexPieceShape *this, unsigned int oldKey)
{
  unsigned int v2; // edx
  signed __int64 result; // rax

  v2 = oldKey + 1;
  result = 0xFFFFFFFFi64;
  if ( (signed int)v2 < SLODWORD(this->vfptr) )
    result = v2;
  return result;
}

// File Line: 205
// RVA: 0xD35610
hkpShape *__fastcall hkpConvexPieceShape::getChildShape(hkpConvexPieceShape *this, unsigned int key, char (*buffer)[512])
{
  return (hkpShape *)(*(__int64 (__fastcall **)(unsigned __int64, _QWORD, char (*)[512]))(*(_QWORD *)(this->m_userData + 32)
                                                                                        + 40i64))(
                       this->m_userData + 32,
                       *(unsigned int *)(*(_QWORD *)&this->m_radius + 4i64 * key),
                       buffer);
}

