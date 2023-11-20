// File Line: 15
// RVA: 0xD0E300
void __fastcall hkpConvexTranslateShape::getAabb(hkpConvexTranslateShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  hkpConvexTranslateShape *v4; // rbx
  hkAabb *v5; // rsi
  hkTransformf *v6; // rdi
  __m128 v7; // xmm1
  __m128 v8; // xmm2

  v4 = this;
  v5 = out;
  v6 = localToWorld;
  ((void (*)(void))this->m_childShape.m_childShape->vfptr[2].__vecDelDtor)();
  v7 = v4->m_translation.m_quad;
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v6->m_rotation.m_col1.m_quad),
           _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v6->m_rotation.m_col0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v6->m_rotation.m_col2.m_quad));
  v5->m_min.m_quad = _mm_add_ps(v5->m_min.m_quad, v8);
  v5->m_max.m_quad = _mm_add_ps(v5->m_max.m_quad, v8);
}

// File Line: 30
// RVA: 0xD0E590
void __fastcall hkpConvexTranslateShape::hkpConvexTranslateShape(hkpConvexTranslateShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpConvexTranslateShape *v2; // rbx

  v2 = this;
  hkpConvexShape::hkpConvexShape((hkpConvexShape *)&this->vfptr, flag);
  v2->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable';
  v2->m_type.m_storage = 10;
  v2->vfptr = (hkBaseObjectVtbl *)&hkpConvexTranslateShape::`vftable';
}

// File Line: 38
// RVA: 0xD0E610
float __usercall hkpConvexTranslateShape::getMaximumProjection@<xmm0>(hkpConvexTranslateShape *this@<rcx>, hkVector4f *direction@<rdx>, float a3@<xmm0>)
{
  hkpConvexTranslateShape *v3; // rbx
  hkVector4f *v4; // rdi
  __m128 v5; // xmm2

  v3 = this;
  v4 = direction;
  ((void (*)(void))this->m_childShape.m_childShape->vfptr[7].__first_virtual_table_function__)();
  v5 = _mm_mul_ps(v3->m_translation.m_quad, v4->m_quad);
  return (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v5, v5, 170)))
       + a3;
}

// File Line: 46
// RVA: 0xD0E680
signed __int64 __fastcall hkpConvexTranslateShape::calcSizeForSpu(hkpConvexTranslateShape *this, hkpShape::CalcSizeForSpuInput *input, int spuBufferSizeLeft)
{
  hkpConvexTranslateShape *v3; // rbx
  int v4; // edi
  int v5; // eax
  signed __int64 result; // rax

  v3 = this;
  v4 = spuBufferSizeLeft - 80;
  v5 = ((__int64 (__fastcall *)(hkpShape *, hkpShape::CalcSizeForSpuInput *, _QWORD))this->m_childShape.m_childShape->vfptr[8].__vecDelDtor)(
         this->m_childShape.m_childShape,
         input,
         (unsigned int)(spuBufferSizeLeft - 80));
  if ( v5 < 0 || v5 > v4 )
    return 0xFFFFFFFFi64;
  if ( (hkpConvexTranslateShape *)v3->m_childShape.m_childShape == &v3[1] )
  {
    v3->m_childShapeSizeForSpu = 0;
    result = (unsigned int)v5 + 80i64;
  }
  else
  {
    v3->m_childShapeSizeForSpu = v5;
    result = 80i64;
  }
  return result;
}

// File Line: 83
// RVA: 0xD0E380
hkBool *__fastcall hkpConvexTranslateShape::castRay(hkpConvexTranslateShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkpConvexTranslateShape *v4; // rbp
  hkpShapeRayCastOutput *v5; // rdi
  hkpShapeRayCastInput *v6; // rsi
  hkBool *v7; // rbx
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __int128 v13; // xmm1
  __int128 v14; // xmm0
  __int128 v15; // xmm1
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  __m128 v18; // xmm1
  hkpShape *v19; // rcx
  _QWORD *v20; // r8
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rax
  signed __int64 v23; // rcx
  __m128 v25; // [rsp+20h] [rbp-48h]
  __int128 v26; // [rsp+30h] [rbp-38h]
  __int128 v27; // [rsp+40h] [rbp-28h]
  __int128 v28; // [rsp+50h] [rbp-18h]

  v4 = this;
  v5 = results;
  v6 = input;
  v7 = result;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcConvTransl";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = (__int128)v6->m_to;
  v25 = v6->m_from.m_quad;
  v14 = *(_OWORD *)&v6->m_filterInfo;
  v26 = v13;
  v15 = *(_OWORD *)&v6->m_collidable;
  v27 = v14;
  v16 = _mm_sub_ps(v6->m_from.m_quad, v4->m_translation.m_quad);
  v28 = v15;
  v17 = v6->m_to.m_quad;
  v25 = v16;
  v18 = _mm_sub_ps(v17, v4->m_translation.m_quad);
  ++v5->m_shapeKeyIndex;
  v19 = v4->m_childShape.m_childShape;
  v26 = (__int128)v18;
  ((void (__fastcall *)(hkpShape *, hkBool *, __m128 *, hkpShapeRayCastOutput *, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, _QWORD, _QWORD, _QWORD, _QWORD))v19->vfptr[2].__first_virtual_table_function__)(
    v19,
    v7,
    &v25,
    v5,
    v25.m128_u64[0],
    v25.m128_u64[1],
    v18.m128_u64[0],
    v18.m128_u64[1],
    v27,
    *((_QWORD *)&v27 + 1),
    v28,
    *((_QWORD *)&v28 + 1));
  --v5->m_shapeKeyIndex;
  if ( v7->m_bool )
    v5->m_shapeKeys[v5->m_shapeKeyIndex] = 0;
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Et";
    v22 = __rdtsc();
    v23 = (signed __int64)(v21 + 2);
    *(_DWORD *)(v23 - 8) = v22;
    v20[1] = v23;
  }
  return v7;
}

// File Line: 102
// RVA: 0xD0E4A0
void __fastcall hkpConvexTranslateShape::castRayWithCollector(hkpConvexTranslateShape *this, hkpShapeRayCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkVector4f v4; // xmm2
  hkVector4f v5; // xmm1
  hkpCdBody *v6; // rbx
  hkpConvexTranslateShape *v7; // rdi
  hkpRayHitCollector *v8; // rsi
  __int128 v9; // xmm0
  __int128 v10; // xmm1
  __m128 v11; // xmm0
  hkVector4f v12; // xmm1
  hkTransformf *v13; // rdx
  __int64 v14; // rcx
  hkpShape *v15; // [rsp+20h] [rbp-E8h]
  int v16; // [rsp+28h] [rbp-E0h]
  char *v17; // [rsp+30h] [rbp-D8h]
  hkpCdBody *v18; // [rsp+38h] [rbp-D0h]
  hkVector4f v19; // [rsp+40h] [rbp-C8h]
  __m128 v20; // [rsp+50h] [rbp-B8h]
  __int128 v21; // [rsp+60h] [rbp-A8h]
  __int128 v22; // [rsp+70h] [rbp-98h]
  __m128 v23; // [rsp+80h] [rbp-88h]
  __m128 v24; // [rsp+90h] [rbp-78h]
  __m128 v25; // [rsp+A0h] [rbp-68h]
  __m128 v26; // [rsp+B0h] [rbp-58h]
  hkTransformf v27; // [rsp+C0h] [rbp-48h]

  v4.m_quad = (__m128)this->m_translation;
  v5.m_quad = (__m128)input->m_to;
  v6 = cdBody;
  v7 = this;
  v8 = collector;
  v19.m_quad = (__m128)input->m_from;
  v9 = *(_OWORD *)&input->m_filterInfo;
  v20 = v5.m_quad;
  v10 = *(_OWORD *)&input->m_collidable;
  v21 = v9;
  v11 = _mm_sub_ps(input->m_from.m_quad, v4.m_quad);
  v22 = v10;
  v12.m_quad = (__m128)input->m_to;
  v19.m_quad = v11;
  v13 = (hkTransformf *)cdBody->m_motion;
  v20 = _mm_sub_ps(v12.m_quad, v4.m_quad);
  v23 = transform.m_quad;
  v24 = direction.m_quad;
  v25 = stru_141A71280.m_quad;
  v26 = v4.m_quad;
  hkTransformf::setMul(&v27, v13, (hkTransformf *)&v23);
  v15 = v7->m_childShape.m_childShape;
  v18 = v6;
  v17 = (char *)&v27;
  v16 = 0;
  ((void (__fastcall *)(__int64, hkVector4f *, hkpShape **, hkpRayHitCollector *, hkpShape *, _QWORD, hkTransformf *, hkpCdBody *, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, _QWORD, _QWORD, _QWORD, _QWORD))v15->vfptr[3].__vecDelDtor)(
    v14,
    &v19,
    &v15,
    v8,
    v15,
    *(_QWORD *)&v16,
    &v27,
    v6,
    v11.m128_u64[0],
    v11.m128_u64[1],
    v20.m128_u64[0],
    v20.m128_u64[1],
    v21,
    *((_QWORD *)&v21 + 1),
    v22,
    *((_QWORD *)&v22 + 1));
}

// File Line: 119
// RVA: 0xD0E190
void __fastcall hkpConvexTranslateShape::getSupportingVertex(hkpConvexTranslateShape *this, hkVector4f *direction, hkcdVertex *supportingVertexOut)
{
  hkpConvexTranslateShape *v3; // rbx
  hkcdVertex *v4; // rdi
  __m128 v5; // xmm2

  v3 = this;
  v4 = supportingVertexOut;
  this->m_childShape.m_childShape->vfptr[4].__vecDelDtor(
    (hkBaseObject *)this->m_childShape.m_childShape,
    (unsigned int)direction);
  v5 = _mm_add_ps(v3->m_translation.m_quad, v4->m_quad);
  v4->m_quad = _mm_shuffle_ps(v5, _mm_unpackhi_ps(v5, _mm_shuffle_ps(v4->m_quad, v4->m_quad, 255)), 196);
}

// File Line: 132
// RVA: 0xD0E1E0
void __fastcall hkpConvexTranslateShape::convertVertexIdsToVertices(hkpConvexTranslateShape *this, const unsigned __int16 *ids, int numIds, hkcdVertex *verticesOut)
{
  hkpConvexTranslateShape *v4; // rdi
  hkcdVertex *v5; // rbx
  int v6; // esi
  __int64 v7; // rax
  __m128 v8; // xmm2

  v4 = this;
  v5 = verticesOut;
  v6 = numIds;
  ((void (__fastcall *)(hkpShape *, const unsigned __int16 *))this->m_childShape.m_childShape->vfptr[4].__first_virtual_table_function__)(
    this->m_childShape.m_childShape,
    ids);
  if ( v6 > 0 )
  {
    v7 = (unsigned int)v6;
    do
    {
      ++v5;
      v8 = _mm_add_ps(v4->m_translation.m_quad, v5[-1].m_quad);
      v5[-1].m_quad = _mm_shuffle_ps(v8, _mm_unpackhi_ps(v8, v5[-1].m_quad), 196);
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 144
// RVA: 0xD0E250
void __fastcall hkpConvexTranslateShape::getCentre(hkpConvexTranslateShape *this, hkVector4f *centreOut)
{
  hkpConvexTranslateShape *v2; // rbx
  hkVector4f *v3; // rdi

  v2 = this;
  v3 = centreOut;
  ((void (*)(void))this->m_childShape.m_childShape->vfptr[5].__vecDelDtor)();
  v3->m_quad = _mm_add_ps(v2->m_translation.m_quad, v3->m_quad);
}

// File Line: 152
// RVA: 0xD0E5D0
void __fastcall hkpConvexTranslateShape::getFirstVertex(hkpConvexTranslateShape *this, hkVector4f *v)
{
  hkpConvexTranslateShape *v2; // rbx
  hkVector4f *v3; // rdi

  v2 = this;
  v3 = v;
  ((void (*)(void))this->m_childShape.m_childShape->vfptr[8].__first_virtual_table_function__)();
  v3->m_quad = _mm_add_ps(v2->m_translation.m_quad, v3->m_quad);
}

// File Line: 160
// RVA: 0xD0E290
hkSphere *__fastcall hkpConvexTranslateShape::getCollisionSpheres(hkpConvexTranslateShape *this, hkSphere *sphereBuffer)
{
  hkpConvexTranslateShape *v2; // rdi
  hkSphere *v3; // rsi
  __int64 v4; // rbx
  __int64 v5; // rax
  char *v6; // rcx

  v2 = this;
  v3 = sphereBuffer;
  v4 = ((__int64 (*)(void))this->m_childShape.m_childShape->vfptr[6].__vecDelDtor)();
  LODWORD(v5) = ((__int64 (*)(void))v2->m_childShape.m_childShape->vfptr[5].__first_virtual_table_function__)();
  if ( (signed int)v5 > 0 )
  {
    v5 = (unsigned int)v5;
    v6 = (char *)v3 - v4;
    do
    {
      v4 += 16i64;
      *(__m128 *)&v6[v4 - 16] = _mm_add_ps(v2->m_translation.m_quad, *(__m128 *)(v4 - 16));
      --v5;
    }
    while ( v5 );
  }
  return v3;
}

// File Line: 179
// RVA: 0xD0E670
hkpSingleShapeContainer *__fastcall hkpConvexTranslateShape::getContainer(hkpConvexTranslateShape *this)
{
  return &this->m_childShape;
}

