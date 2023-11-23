// File Line: 15
// RVA: 0xD0E300
void __fastcall hkpConvexTranslateShape::getAabb(
        hkpConvexTranslateShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  hkVector4f v7; // xmm1
  __m128 v8; // xmm2

  ((void (__fastcall *)(hkpShape *))this->m_childShape.m_childShape->vfptr[2].__vecDelDtor)(this->m_childShape.m_childShape);
  v7.m_quad = (__m128)this->m_translation;
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 85), localToWorld->m_rotation.m_col1.m_quad),
           _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 0), localToWorld->m_rotation.m_col0.m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v7.m_quad, v7.m_quad, 170), localToWorld->m_rotation.m_col2.m_quad));
  out->m_min.m_quad = _mm_add_ps(out->m_min.m_quad, v8);
  out->m_max.m_quad = _mm_add_ps(out->m_max.m_quad, v8);
}

// File Line: 30
// RVA: 0xD0E590
void __fastcall hkpConvexTranslateShape::hkpConvexTranslateShape(
        hkpConvexTranslateShape *this,
        hkFinishLoadedObjectFlag flag)
{
  hkpConvexShape::hkpConvexShape(this, flag);
  this->m_childShape.hkpConvexTransformShapeBase::vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  this->m_type.m_storage = 10;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexTranslateShape::`vftable;
}

// File Line: 38
// RVA: 0xD0E610
float __fastcall hkpConvexTranslateShape::getMaximumProjection(hkpConvexTranslateShape *this, hkVector4f *direction)
{
  double v4; // xmm0_8
  __m128 v5; // xmm2

  v4 = ((double (__fastcall *)(hkpShape *))this->m_childShape.m_childShape->vfptr[7].__first_virtual_table_function__)(this->m_childShape.m_childShape);
  v5 = _mm_mul_ps(this->m_translation.m_quad, direction->m_quad);
  return (float)((float)(_mm_shuffle_ps(v5, v5, 85).m128_f32[0] + _mm_shuffle_ps(v5, v5, 0).m128_f32[0])
               + _mm_shuffle_ps(v5, v5, 170).m128_f32[0])
       + *(float *)&v4;
}

// File Line: 46
// RVA: 0xD0E680
__int64 __fastcall hkpConvexTranslateShape::calcSizeForSpu(
        hkpConvexTranslateShape *this,
        hkpShape::CalcSizeForSpuInput *input,
        int spuBufferSizeLeft)
{
  int v4; // edi
  int v5; // eax

  v4 = spuBufferSizeLeft - 80;
  v5 = ((__int64 (__fastcall *)(hkpShape *, hkpShape::CalcSizeForSpuInput *, _QWORD))this->m_childShape.m_childShape->vfptr[8].__vecDelDtor)(
         this->m_childShape.m_childShape,
         input,
         (unsigned int)(spuBufferSizeLeft - 80));
  if ( v5 < 0 || v5 > v4 )
    return 0xFFFFFFFFi64;
  if ( this->m_childShape.m_childShape == &this[1] )
  {
    this->m_childShapeSizeForSpu = 0;
    return (unsigned int)v5 + 80i64;
  }
  else
  {
    this->m_childShapeSizeForSpu = v5;
    return 80i64;
  }
}

// File Line: 83
// RVA: 0xD0E380
hkBool *__fastcall hkpConvexTranslateShape::castRay(
        hkpConvexTranslateShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkVector4f v13; // xmm1
  __int128 v14; // xmm0
  __int128 v15; // xmm1
  __m128 v16; // xmm0
  hkVector4f v17; // xmm1
  __m128 v18; // xmm1
  hkpShape *m_childShape; // rcx
  _QWORD *v20; // r8
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rax
  _QWORD *v23; // rcx
  hkVector4f v25; // [rsp+20h] [rbp-48h] BYREF
  __m128 m_quad; // [rsp+30h] [rbp-38h]
  __int128 v27; // [rsp+40h] [rbp-28h]
  __int128 v28; // [rsp+50h] [rbp-18h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcConvTransl";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  v13.m_quad = (__m128)input->m_to;
  v25.m_quad = (__m128)input->m_from;
  v14 = *(_OWORD *)&input->m_filterInfo;
  m_quad = v13.m_quad;
  v15 = *(_OWORD *)&input->m_collidable;
  v27 = v14;
  v16 = _mm_sub_ps(input->m_from.m_quad, this->m_translation.m_quad);
  v28 = v15;
  v17.m_quad = (__m128)input->m_to;
  v25.m_quad = v16;
  v18 = _mm_sub_ps(v17.m_quad, this->m_translation.m_quad);
  ++results->m_shapeKeyIndex;
  m_childShape = this->m_childShape.m_childShape;
  m_quad = v18;
  ((void (__fastcall *)(hkpShape *, hkBool *, hkVector4f *, hkpShapeRayCastOutput *))m_childShape->vfptr[2].__first_virtual_table_function__)(
    m_childShape,
    result,
    &v25,
    results);
  --results->m_shapeKeyIndex;
  if ( result->m_bool )
    results->m_shapeKeys[results->m_shapeKeyIndex] = 0;
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Et";
    v22 = __rdtsc();
    v23 = v21 + 2;
    *((_DWORD *)v23 - 2) = v22;
    v20[1] = v23;
  }
  return result;
}

// File Line: 102
// RVA: 0xD0E4A0
void __fastcall hkpConvexTranslateShape::castRayWithCollector(
        hkpConvexTranslateShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  __m128 m_quad; // xmm2
  hkVector4f v5; // xmm1
  __int128 v9; // xmm0
  __int128 v10; // xmm1
  __m128 v11; // xmm0
  hkVector4f v12; // xmm1
  hkTransformf *m_motion; // rdx
  __int64 v14; // rcx
  hkpShape *m_childShape; // [rsp+20h] [rbp-E8h] BYREF
  int v16; // [rsp+28h] [rbp-E0h]
  hkTransformf *v17; // [rsp+30h] [rbp-D8h]
  hkpCdBody *v18; // [rsp+38h] [rbp-D0h]
  hkVector4f v19; // [rsp+40h] [rbp-C8h] BYREF
  __m128 v20; // [rsp+50h] [rbp-B8h]
  __int128 v21; // [rsp+60h] [rbp-A8h]
  __int128 v22; // [rsp+70h] [rbp-98h]
  hkTransformf v23; // [rsp+80h] [rbp-88h] BYREF
  hkTransformf v24; // [rsp+C0h] [rbp-48h] BYREF

  m_quad = this->m_translation.m_quad;
  v5.m_quad = (__m128)input->m_to;
  v19.m_quad = (__m128)input->m_from;
  v9 = *(_OWORD *)&input->m_filterInfo;
  v20 = v5.m_quad;
  v10 = *(_OWORD *)&input->m_collidable;
  v21 = v9;
  v11 = _mm_sub_ps(input->m_from.m_quad, m_quad);
  v22 = v10;
  v12.m_quad = (__m128)input->m_to;
  v19.m_quad = v11;
  m_motion = (hkTransformf *)cdBody->m_motion;
  v20 = _mm_sub_ps(v12.m_quad, m_quad);
  v23.m_rotation.m_col0 = (hkVector4f)transform.m_quad;
  v23.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  v23.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  v23.m_translation.m_quad = m_quad;
  hkTransformf::setMul(&v24, m_motion, &v23);
  m_childShape = this->m_childShape.m_childShape;
  v18 = cdBody;
  v17 = &v24;
  v16 = 0;
  ((void (__fastcall *)(__int64, hkVector4f *, hkpShape **, hkpRayHitCollector *))m_childShape->vfptr[3].__vecDelDtor)(
    v14,
    &v19,
    &m_childShape,
    collector);
}

// File Line: 119
// RVA: 0xD0E190
void __fastcall hkpConvexTranslateShape::getSupportingVertex(
        hkpConvexTranslateShape *this,
        hkVector4f *direction,
        hkcdVertex *supportingVertexOut)
{
  __m128 v5; // xmm2

  this->m_childShape.m_childShape->vfptr[4].__vecDelDtor(this->m_childShape.m_childShape, (unsigned int)direction);
  v5 = _mm_add_ps(this->m_translation.m_quad, supportingVertexOut->m_quad);
  supportingVertexOut->m_quad = _mm_shuffle_ps(
                                  v5,
                                  _mm_unpackhi_ps(
                                    v5,
                                    _mm_shuffle_ps(supportingVertexOut->m_quad, supportingVertexOut->m_quad, 255)),
                                  196);
}

// File Line: 132
// RVA: 0xD0E1E0
void __fastcall hkpConvexTranslateShape::convertVertexIdsToVertices(
        hkpConvexTranslateShape *this,
        const unsigned __int16 *ids,
        unsigned int numIds,
        hkcdVertex *verticesOut)
{
  __int64 v7; // rax
  __m128 v8; // xmm2

  ((void (__fastcall *)(hkpShape *, const unsigned __int16 *))this->m_childShape.m_childShape->vfptr[4].__first_virtual_table_function__)(
    this->m_childShape.m_childShape,
    ids);
  if ( (int)numIds > 0 )
  {
    v7 = numIds;
    do
    {
      ++verticesOut;
      v8 = _mm_add_ps(this->m_translation.m_quad, verticesOut[-1].m_quad);
      verticesOut[-1].m_quad = _mm_shuffle_ps(v8, _mm_unpackhi_ps(v8, verticesOut[-1].m_quad), 196);
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 144
// RVA: 0xD0E250
void __fastcall hkpConvexTranslateShape::getCentre(hkpConvexTranslateShape *this, hkVector4f *centreOut)
{
  ((void (__fastcall *)(hkpShape *))this->m_childShape.m_childShape->vfptr[5].__vecDelDtor)(this->m_childShape.m_childShape);
  centreOut->m_quad = _mm_add_ps(this->m_translation.m_quad, centreOut->m_quad);
}

// File Line: 152
// RVA: 0xD0E5D0
void __fastcall hkpConvexTranslateShape::getFirstVertex(hkpConvexTranslateShape *this, hkVector4f *v)
{
  this->m_childShape.m_childShape->vfptr[8].__first_virtual_table_function__(this->m_childShape.m_childShape);
  v->m_quad = _mm_add_ps(this->m_translation.m_quad, v->m_quad);
}

// File Line: 160
// RVA: 0xD0E290
hkSphere *__fastcall hkpConvexTranslateShape::getCollisionSpheres(
        hkpConvexTranslateShape *this,
        hkSphere *sphereBuffer)
{
  __int64 v4; // rbx
  __int64 v5; // rax
  char *v6; // rcx

  v4 = ((__int64 (__fastcall *)(hkpShape *))this->m_childShape.m_childShape->vfptr[6].__vecDelDtor)(this->m_childShape.m_childShape);
  LODWORD(v5) = ((__int64 (__fastcall *)(hkpShape *))this->m_childShape.m_childShape->vfptr[5].__first_virtual_table_function__)(this->m_childShape.m_childShape);
  if ( (int)v5 > 0 )
  {
    v5 = (unsigned int)v5;
    v6 = (char *)sphereBuffer - v4;
    do
    {
      v4 += 16i64;
      *(__m128 *)&v6[v4 - 16] = _mm_add_ps(this->m_translation.m_quad, *(__m128 *)(v4 - 16));
      --v5;
    }
    while ( v5 );
  }
  return sphereBuffer;
}

// File Line: 179
// RVA: 0xD0E670
hkpSingleShapeContainer *__fastcall hkpConvexTranslateShape::getContainer(hkpConvexTranslateShape *this)
{
  return &this->m_childShape;
}

