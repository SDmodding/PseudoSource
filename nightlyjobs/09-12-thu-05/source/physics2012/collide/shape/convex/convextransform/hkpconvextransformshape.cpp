// File Line: 20
// RVA: 0xCF0B30
void __fastcall hkpConvexTransformShape::hkpConvexTransformShape(
        hkpConvexTransformShape *this,
        hkpConvexShape *childShape,
        hkTransformf *transform,
        hkpShapeContainer::ReferencePolicy ref)
{
  hkpConvexTransformShapeBase::hkpConvexTransformShapeBase(
    this,
    CONVEX_TRANSFORM,
    childShape->m_radius,
    childShape,
    ref);
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexTransformShape::`vftable;
  hkQsTransformf::setFromTransformNoScale(&this->m_transform, transform);
  this->m_extraScale = 0i64;
  this->m_userData = childShape->m_userData;
}

// File Line: 28
// RVA: 0xCF0BA0
void __fastcall hkpConvexTransformShape::hkpConvexTransformShape(
        hkpConvexTransformShape *this,
        hkpConvexShape *childShape,
        hkQsTransformf *transform,
        hkpShapeContainer::ReferencePolicy ref)
{
  hkpConvexTransformShapeBase::hkpConvexTransformShapeBase(
    this,
    CONVEX_TRANSFORM,
    childShape->m_radius,
    childShape,
    ref);
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexTransformShape::`vftable;
  hkpConvexTransformShape::setTransform(this, transform);
  this->m_userData = childShape->m_userData;
}

// File Line: 39
// RVA: 0xCF0C10
void __fastcall hkpConvexTransformShape::hkpConvexTransformShape(
        hkpConvexTransformShape *this,
        hkFinishLoadedObjectFlag flag)
{
  hkpConvexShape::hkpConvexShape(this, flag);
  this->m_childShape.hkpConvexTransformShapeBase::vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  this->m_type.m_storage = 11;
  this->vfptr = (hkBaseObjectVtbl *)&hkpConvexTransformShape::`vftable;
}

// File Line: 46
// RVA: 0xCF1390
void __fastcall hkpConvexTransformShape::getAabb(
        hkpConvexTransformShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  __int64 v4; // r8
  __m128 v8; // xmm6
  __m128 v9; // xmm7
  __m128 v10; // xmm5
  __m128 v11; // xmm2
  __m128 v12; // [rsp+20h] [rbp-88h] BYREF
  __m128 v13; // [rsp+30h] [rbp-78h]
  hkTransformf transformOut; // [rsp+40h] [rbp-68h] BYREF

  ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, __m128 *))this->m_childShape.m_childShape->vfptr[2].__vecDelDtor)(
    this->m_childShape.m_childShape,
    &transform,
    v4,
    &v12);
  v8 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v13, v12), (__m128)xmmword_141A711B0), this->m_transform.m_scale.m_quad);
  v9 = _mm_mul_ps(_mm_mul_ps(_mm_add_ps(v13, v12), (__m128)xmmword_141A711B0), this->m_transform.m_scale.m_quad);
  hkQsTransformf::copyToTransformNoScale(&this->m_transform, &transformOut);
  hkTransformf::setMul(&transformOut, localToWorld, &transformOut);
  v10 = _mm_add_ps(
          _mm_add_ps(
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32(
                        (__m128i)_mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), transformOut.m_rotation.m_col1.m_quad),
                        1u),
                      1u),
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32(
                        (__m128i)_mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), transformOut.m_rotation.m_col0.m_quad),
                        1u),
                      1u)),
          _mm_add_ps(
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32(
                        (__m128i)_mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), transformOut.m_rotation.m_col2.m_quad),
                        1u),
                      1u),
            _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0)));
  v11 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), transformOut.m_rotation.m_col1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), transformOut.m_rotation.m_col0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), transformOut.m_rotation.m_col2.m_quad)),
          transformOut.m_translation.m_quad);
  out->m_max.m_quad = _mm_add_ps(v11, v10);
  out->m_min.m_quad = _mm_add_ps(
                        _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v10),
                        v11);
}

// File Line: 76
// RVA: 0xCF14F0
hkBool *__fastcall hkpConvexTransformShape::castRay(
        hkpConvexTransformShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  hkQuaternionf v12; // xmm8
  hkVector4f v13; // xmm0
  __m128 v14; // xmm4
  __m128 v15; // xmm1
  __m128 v16; // xmm10
  __m128 v17; // xmm11
  __m128 v18; // xmm9
  __m128 v19; // xmm6
  __int128 v20; // xmm1
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  __m128 v24; // xmm1
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  hkpShape *m_childShape; // rcx
  __m128 v28; // xmm3
  hkQuaternionf v29; // xmm2
  __m128 v30; // xmm11
  __int64 m_shapeKeyIndex; // rax
  __m128 v32; // xmm4
  __m128 v33; // xmm1
  __m128 v34; // xmm3
  __m128 v35; // xmm5
  __m128 v36; // xmm5
  __m128 v37; // xmm1
  __m128 v38; // xmm3
  __m128 v39; // xmm2
  _QWORD *v40; // r8
  _QWORD *v41; // rcx
  unsigned __int64 v42; // rax
  _QWORD *v43; // rcx
  __int128 v45[9]; // [rsp+20h] [rbp-98h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcCxTransform";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  v12.m_vec.m_quad = (__m128)this->m_transform.m_rotation;
  v13.m_quad = (__m128)this->m_transform.m_scale;
  v14 = _mm_sub_ps(input->m_from.m_quad, this->m_transform.m_translation.m_quad);
  v15 = _mm_rcp_ps(v13.m_quad);
  v16 = _mm_sub_ps(input->m_to.m_quad, this->m_transform.m_translation.m_quad);
  v17 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v13.m_quad, v15)), v15);
  v18 = _mm_shuffle_ps(v12.m_vec.m_quad, v12.m_vec.m_quad, 255);
  v19 = _mm_shuffle_ps(v12.m_vec.m_quad, v12.m_vec.m_quad, 201);
  v20 = *(_OWORD *)&input->m_collidable;
  v45[2] = *(_OWORD *)&input->m_filterInfo;
  v45[3] = v20;
  v21 = _mm_mul_ps(v14, v12.m_vec.m_quad);
  v22 = _mm_sub_ps(_mm_mul_ps(v14, v19), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v12.m_vec.m_quad));
  v23 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
            _mm_shuffle_ps(v21, v21, 170)),
          v12.m_vec.m_quad);
  v24 = _mm_mul_ps(v16, v12.m_vec.m_quad);
  v25 = _mm_add_ps(
          _mm_add_ps(v23, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v18, v18), (__m128)xmmword_141A711B0), v14)),
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v18));
  v26 = _mm_sub_ps(_mm_mul_ps(v16, v19), _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v12.m_vec.m_quad));
  v45[0] = (__int128)_mm_mul_ps(_mm_add_ps(v25, v25), v17);
  ++results->m_shapeKeyIndex;
  m_childShape = this->m_childShape.m_childShape;
  v28 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                _mm_shuffle_ps(v24, v24, 170)),
              v12.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v18, v18), (__m128)xmmword_141A711B0), v16)),
          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v18));
  v45[1] = (__int128)_mm_mul_ps(_mm_add_ps(v28, v28), v17);
  ((void (__fastcall *)(hkpShape *, hkBool *, __int128 *, hkpShapeRayCastOutput *))m_childShape->vfptr[2].__first_virtual_table_function__)(
    m_childShape,
    result,
    v45,
    results);
  --results->m_shapeKeyIndex;
  if ( result->m_bool )
  {
    v29.m_vec.m_quad = (__m128)this->m_transform.m_rotation;
    v30 = _mm_mul_ps(v17, results->m_normal.m_quad);
    m_shapeKeyIndex = results->m_shapeKeyIndex;
    v32 = _mm_shuffle_ps(v29.m_vec.m_quad, v29.m_vec.m_quad, 255);
    v33 = _mm_mul_ps(v30, v29.m_vec.m_quad);
    v34 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v29.m_vec.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v29.m_vec.m_quad, v29.m_vec.m_quad, 201), v30));
    v35 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                  _mm_shuffle_ps(v33, v33, 170)),
                v29.m_vec.m_quad),
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v32, v32), (__m128)xmmword_141A711B0), v30)),
            _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v32));
    v36 = _mm_add_ps(v35, v35);
    v37 = _mm_mul_ps(v36, v36);
    v38 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
            _mm_shuffle_ps(v37, v37, 170));
    v39 = _mm_rsqrt_ps(v38);
    results->m_normal.m_quad = _mm_mul_ps(
                                 _mm_andnot_ps(
                                   _mm_cmple_ps(v38, (__m128)0i64),
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                                     _mm_mul_ps(*(__m128 *)_xmm, v39))),
                                 v36);
    results->m_shapeKeys[m_shapeKeyIndex] = 0;
  }
  v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v41 = (_QWORD *)v40[1];
  if ( (unsigned __int64)v41 < v40[3] )
  {
    *v41 = "Et";
    v42 = __rdtsc();
    v43 = v41 + 2;
    *((_DWORD *)v43 - 2) = v42;
    v40[1] = v43;
  }
  return result;
}

// File Line: 119
// RVA: 0xCF17F0
void __fastcall hkpConvexTransformShape::castRayWithCollector(
        hkpConvexTransformShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkBaseObjectVtbl *vfptr; // rax
  hkpShape *m_childShape; // rax
  hkpRayHitCollectorVtbl *v15; // rax
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  _QWORD *v19; // rcx
  hkpShape *v20; // [rsp+20h] [rbp-78h] BYREF
  int v21; // [rsp+28h] [rbp-70h]
  __m128 *m_motion; // [rsp+30h] [rbp-68h]
  hkpCdBody *v23; // [rsp+38h] [rbp-60h]
  __m128 v24; // [rsp+40h] [rbp-58h] BYREF
  int v25; // [rsp+50h] [rbp-48h]
  int v26; // [rsp+54h] [rbp-44h]
  int v27; // [rsp+60h] [rbp-38h]
  int v28; // [rsp+80h] [rbp-18h]
  char v29; // [rsp+A0h] [rbp+8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcCxTransform";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  vfptr = this->vfptr;
  v25 = (int)FLOAT_1_0;
  v26 = -1;
  v28 = 0;
  v27 = -1;
  if ( *(_BYTE *)((__int64 (__fastcall *)(hkpConvexTransformShape *, char *, hkpShapeRayCastInput *, __m128 *))vfptr[2].__first_virtual_table_function__)(
                   this,
                   &v29,
                   input,
                   &v24) )
  {
    m_childShape = this->m_childShape.m_childShape;
    m_motion = (__m128 *)cdBody->m_motion;
    v20 = m_childShape;
    v15 = collector->vfptr;
    v23 = cdBody;
    v21 = 0;
    v24 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), m_motion[1]),
              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), *m_motion)),
            _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), m_motion[2]));
    v15->addRayHit(collector, (hkpCdBody *)&v20, (hkpShapeRayCastCollectorOutput *)&v24);
  }
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v18 = __rdtsc();
    v19 = v17 + 2;
    *((_DWORD *)v19 - 2) = v18;
    v16[1] = v19;
  }
}

// File Line: 135
// RVA: 0xCF0E80
void __fastcall hkpConvexTransformShape::getSupportingVertex(
        hkpConvexTransformShape *this,
        hkVector4f *direction,
        hkcdVertex *supportingVertexOut)
{
  hkQuaternionf v3; // xmm2
  __m128 v6; // xmm1
  __m128 v7; // xmm5
  __m128 v8; // xmm6
  __m128 v9; // xmm4
  __m128 v10; // xmm4
  hkpShape *m_childShape; // rcx
  hkVector4f v12; // xmm2
  __m128 v13; // xmm7
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm6
  __m128 v17; // xmm0
  __m128 v18; // xmm6
  hkQuaternionf v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm5
  __m128 v22; // xmm3
  __m128 v23; // xmm4
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  __m128 v26; // [rsp+20h] [rbp-48h] BYREF
  __m128 v27; // [rsp+30h] [rbp-38h] BYREF

  v3.m_vec.m_quad = (__m128)this->m_transform.m_rotation;
  v6 = _mm_mul_ps(v3.m_vec.m_quad, direction->m_quad);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 201), direction->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(direction->m_quad, direction->m_quad, 201), v3.m_vec.m_quad));
  v8 = _mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 255);
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170)),
             v3.m_vec.m_quad),
           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v8, v8), (__m128)xmmword_141A711B0), direction->m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v8));
  v10 = _mm_mul_ps(_mm_add_ps(v9, v9), this->m_transform.m_scale.m_quad);
  m_childShape = this->m_childShape.m_childShape;
  v26 = v10;
  ((void (__fastcall *)(hkpShape *, __m128 *, __m128 *))m_childShape->vfptr[4].__vecDelDtor)(m_childShape, &v26, &v27);
  v12.m_quad = (__m128)this->m_transform.m_scale;
  v13 = v27;
  v14 = _mm_unpacklo_ps(
          _mm_shuffle_ps(this->m_transform.m_translation.m_quad, this->m_transform.m_translation.m_quad, 255),
          _mm_shuffle_ps(v12.m_quad, v12.m_quad, 255));
  v15 = _mm_mul_ps(v12.m_quad, v27);
  v16 = v27;
  v17 = _mm_unpacklo_ps(_mm_shuffle_ps(this->m_extraScale.m_quad, this->m_extraScale.m_quad, 255), aabbOut.m_quad);
  *supportingVertexOut = (hkcdVertex)v15;
  v18 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v16, _mm_movelh_ps(v14, v17)), this->m_extraScale.m_quad), v15);
  *supportingVertexOut = (hkcdVertex)v18;
  v19.m_vec.m_quad = (__m128)this->m_transform.m_rotation;
  v20 = _mm_mul_ps(v19.m_vec.m_quad, v18);
  v21 = _mm_shuffle_ps(v19.m_vec.m_quad, v19.m_vec.m_quad, 255);
  v22 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v19.m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v19.m_vec.m_quad, v19.m_vec.m_quad, 201), v18));
  v23 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                _mm_shuffle_ps(v20, v20, 170)),
              v19.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v21, v21), (__m128)xmmword_141A711B0), v18)),
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v21));
  v24 = _mm_add_ps(v23, v23);
  *supportingVertexOut = (hkcdVertex)v24;
  v25 = _mm_add_ps(this->m_transform.m_translation.m_quad, v24);
  supportingVertexOut->m_quad = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, v13), 196);
}

// File Line: 147
// RVA: 0xCF1000
void __fastcall hkpConvexTransformShape::convertVertexIdsToVertices(
        hkpConvexTransformShape *this,
        const unsigned __int16 *ids,
        unsigned int numIds,
        hkcdVertex *verticesOut)
{
  __int64 v5; // rbx
  __int64 v7; // rax
  __m128 m_quad; // xmm8
  hkVector4f v9; // xmm7
  hkQuaternionf v10; // xmm2
  __m128 v11; // xmm5
  __m128 v12; // xmm6
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  __m128 v16; // xmm4

  v5 = (int)numIds;
  ((void (__fastcall *)(hkpShape *, const unsigned __int16 *, _QWORD))this->m_childShape.m_childShape->vfptr[4].__first_virtual_table_function__)(
    this->m_childShape.m_childShape,
    ids,
    numIds);
  v7 = v5;
  if ( v5 > 0 )
  {
    do
    {
      m_quad = verticesOut->m_quad;
      ++verticesOut;
      v9.m_quad = (__m128)this->m_transform.m_translation;
      v10.m_vec.m_quad = (__m128)this->m_transform.m_rotation;
      v11 = _mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 255);
      v12 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  m_quad,
                  _mm_movelh_ps(
                    _mm_unpacklo_ps(
                      _mm_shuffle_ps(v9.m_quad, v9.m_quad, 255),
                      _mm_shuffle_ps(this->m_transform.m_scale.m_quad, this->m_transform.m_scale.m_quad, 255)),
                    _mm_unpacklo_ps(
                      _mm_shuffle_ps(this->m_extraScale.m_quad, this->m_extraScale.m_quad, 255),
                      aabbOut.m_quad))),
                this->m_extraScale.m_quad),
              _mm_mul_ps(m_quad, this->m_transform.m_scale.m_quad));
      v13 = _mm_mul_ps(v10.m_vec.m_quad, v12);
      v14 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v10.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v10.m_vec.m_quad, v10.m_vec.m_quad, 201), v12));
      v15 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                    _mm_shuffle_ps(v13, v13, 170)),
                  v10.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v11, v11), (__m128)xmmword_141A711B0), v12)),
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v11));
      v16 = _mm_add_ps(_mm_add_ps(v15, v15), v9.m_quad);
      verticesOut[-1].m_quad = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, m_quad), 196);
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 161
// RVA: 0xCF1140
void __fastcall hkpConvexTransformShape::getCentre(hkpConvexTransformShape *this, hkVector4f *centreOut)
{
  hkVector4f v4; // xmm2
  __m128 v5; // xmm6
  __m128 v6; // xmm0
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  __m128 v10; // xmm6
  hkQuaternionf v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm5
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  __m128 v16; // xmm4
  __m128 v17; // [rsp+20h] [rbp-28h] BYREF

  this->m_childShape.m_childShape->vfptr[5].__vecDelDtor(this->m_childShape.m_childShape, (unsigned int)&v17);
  v4.m_quad = (__m128)this->m_transform.m_scale;
  v5 = v17;
  v6 = _mm_shuffle_ps(v4.m_quad, v4.m_quad, 255);
  v7 = _mm_mul_ps(v4.m_quad, v17);
  v8 = _mm_unpacklo_ps(
         _mm_shuffle_ps(this->m_transform.m_translation.m_quad, this->m_transform.m_translation.m_quad, 255),
         v6);
  v9 = _mm_unpacklo_ps(_mm_shuffle_ps(this->m_extraScale.m_quad, this->m_extraScale.m_quad, 255), aabbOut.m_quad);
  *centreOut = (hkVector4f)v7;
  v10 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v5, _mm_movelh_ps(v8, v9)), this->m_extraScale.m_quad), v7);
  *centreOut = (hkVector4f)v10;
  v11.m_vec.m_quad = (__m128)this->m_transform.m_rotation;
  v12 = _mm_mul_ps(v11.m_vec.m_quad, v10);
  v13 = _mm_shuffle_ps(v11.m_vec.m_quad, v11.m_vec.m_quad, 255);
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v11.m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v11.m_vec.m_quad, v11.m_vec.m_quad, 201), v10));
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                _mm_shuffle_ps(v12, v12, 170)),
              v11.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v10)),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13));
  v16 = _mm_add_ps(v15, v15);
  *centreOut = (hkVector4f)v16;
  centreOut->m_quad = _mm_add_ps(this->m_transform.m_translation.m_quad, v16);
}

// File Line: 167
// RVA: 0xCF0C50
void __fastcall hkpConvexTransformShape::setTransform(hkpConvexTransformShape *this, hkQsTransformf *transform)
{
  __m128i m_scale; // xmm0
  hkVector4f v5; // xmm1
  hkpShape *m_childShape; // rdi
  hkBaseObjectVtbl *vfptr; // rax
  __m128 v8; // xmm6
  __int64 v9; // r8
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  __m128i v12; // xmm7
  __m128 v13; // xmm2
  __m128 v14; // xmm4
  __m128 v15; // xmm5
  __m128 v16; // xmm4
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128 v19; // xmm0
  __m128 v20[2]; // [rsp+20h] [rbp-48h] BYREF

  this->m_transform.m_translation = transform->m_translation;
  this->m_transform.m_rotation = transform->m_rotation;
  m_scale = (__m128i)transform->m_scale;
  v5.m_quad = (__m128)_mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&this->m_transform), 4), 4);
  this->m_transform.m_scale = (hkVector4f)m_scale;
  this->m_transform.m_translation = (hkVector4f)v5.m_quad;
  this->m_transform.m_scale = (hkVector4f)_mm_srli_si128(_mm_slli_si128(m_scale, 4), 4);
  if ( (_mm_movemask_ps(
          _mm_cmplt_ps(
            (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(transform->m_scale.m_quad, query.m_quad), 1u), 1u),
            *(__m128 *)&epsilon)) & 7) == 7 )
  {
    this->m_extraScale = 0i64;
  }
  else
  {
    m_childShape = this->m_childShape.m_childShape;
    vfptr = m_childShape->vfptr;
    v8 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)transform->m_scale.m_quad, 1u), 1u);
    v20[0] = v8;
    if ( ((int (__fastcall *)(hkpShape *))vfptr[5].__first_virtual_table_function__)(m_childShape) >= 3 )
    {
      ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, __m128 *))m_childShape->vfptr[2].__vecDelDtor)(
        m_childShape,
        &::transform,
        v9,
        v20);
      v10 = _mm_shuffle_ps((__m128)LODWORD(this->m_radius), (__m128)LODWORD(this->m_radius), 0);
      v11 = _mm_shuffle_ps(
              (__m128)(unsigned int)(LODWORD(m_childShape[1].vfptr) ^ _xmm[0]),
              (__m128)(unsigned int)(LODWORD(m_childShape[1].vfptr) ^ _xmm[0]),
              0);
      v12 = _mm_srai_epi32(_mm_load_si128((const __m128i *)&transform->m_scale), 0x1Fu);
      v13 = _mm_add_ps(v20[1], v11);
      v14 = _mm_sub_ps(v20[0], v11);
      v15 = _mm_mul_ps(_mm_sub_ps(v13, v14), (__m128)xmmword_141A711B0);
      v16 = _mm_mul_ps(_mm_add_ps(v14, v13), (__m128)xmmword_141A711B0);
      v17 = _mm_mul_ps(_mm_add_ps(v10, v15), v8);
      if ( (_mm_movemask_ps(_mm_cmplt_ps(v10, v17)) & 7) == 7 )
      {
        v18 = v10;
      }
      else
      {
        v18 = _mm_min_ps(
                _mm_shuffle_ps(v17, v17, 170),
                _mm_min_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)));
        LODWORD(this->m_radius) = v18.m128_i32[0];
      }
      v19 = _mm_rcp_ps(v15);
      this->m_extraScale.m_quad = _mm_xor_ps(
                                    (__m128)_mm_slli_epi32(_mm_srli_epi32(v12, 0x1Fu), 0x1Fu),
                                    _mm_andnot_ps(
                                      _mm_cmpeq_ps(v15, (__m128)0i64),
                                      _mm_mul_ps(
                                        _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v15, v19)), v19),
                                        _mm_sub_ps(_mm_mul_ps(v10, v8), v18))));
      this->m_transform.m_translation.m_quad = _mm_shuffle_ps(
                                                 this->m_transform.m_translation.m_quad,
                                                 _mm_unpackhi_ps(
                                                   this->m_transform.m_translation.m_quad,
                                                   _mm_shuffle_ps(v16, v16, 0)),
                                                 196);
      this->m_transform.m_scale.m_quad = _mm_shuffle_ps(
                                           this->m_transform.m_scale.m_quad,
                                           _mm_unpackhi_ps(
                                             this->m_transform.m_scale.m_quad,
                                             _mm_shuffle_ps(v16, v16, 85)),
                                           196);
      this->m_extraScale.m_quad = _mm_shuffle_ps(
                                    this->m_extraScale.m_quad,
                                    _mm_unpackhi_ps(this->m_extraScale.m_quad, _mm_shuffle_ps(v16, v16, 170)),
                                    196);
    }
    else
    {
      this->m_radius = v20[0].m128_f32[0] * *(float *)&m_childShape[1].vfptr;
      this->m_extraScale = 0i64;
    }
  }
}

// File Line: 238
// RVA: 0xCF19E0
void __fastcall hkpConvexTransformShape::getFirstVertex(hkpConvexTransformShape *this, hkVector4f *v)
{
  hkVector4f v4; // xmm2
  __m128 v5; // xmm6
  __m128 v6; // xmm0
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  __m128 v10; // xmm6
  hkQuaternionf v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm5
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  __m128 v16; // xmm4
  __m128 v17; // [rsp+20h] [rbp-28h] BYREF

  ((void (__fastcall *)(hkpShape *, __m128 *))this->m_childShape.m_childShape->vfptr[8].__first_virtual_table_function__)(
    this->m_childShape.m_childShape,
    &v17);
  v4.m_quad = (__m128)this->m_transform.m_scale;
  v5 = v17;
  v6 = _mm_shuffle_ps(v4.m_quad, v4.m_quad, 255);
  v7 = _mm_mul_ps(v4.m_quad, v17);
  v8 = _mm_unpacklo_ps(
         _mm_shuffle_ps(this->m_transform.m_translation.m_quad, this->m_transform.m_translation.m_quad, 255),
         v6);
  v9 = _mm_unpacklo_ps(_mm_shuffle_ps(this->m_extraScale.m_quad, this->m_extraScale.m_quad, 255), aabbOut.m_quad);
  *v = (hkVector4f)v7;
  v10 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v5, _mm_movelh_ps(v8, v9)), this->m_extraScale.m_quad), v7);
  *v = (hkVector4f)v10;
  v11.m_vec.m_quad = (__m128)this->m_transform.m_rotation;
  v12 = _mm_mul_ps(v11.m_vec.m_quad, v10);
  v13 = _mm_shuffle_ps(v11.m_vec.m_quad, v11.m_vec.m_quad, 255);
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v11.m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v11.m_vec.m_quad, v11.m_vec.m_quad, 201), v10));
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                _mm_shuffle_ps(v12, v12, 170)),
              v11.m_vec.m_quad),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v10)),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13));
  v16 = _mm_add_ps(v15, v15);
  *v = (hkVector4f)v16;
  v->m_quad = _mm_add_ps(this->m_transform.m_translation.m_quad, v16);
}

// File Line: 247
// RVA: 0xCF1230
hkSphere *__fastcall hkpConvexTransformShape::getCollisionSpheres(
        hkpConvexTransformShape *this,
        hkSphere *sphereBuffer)
{
  __int64 v4; // rsi
  int v5; // eax
  __m128 v6; // xmm8
  __int64 v7; // rdx
  __m128 *v8; // rax
  hkVector4f v9; // xmm7
  __m128 v10; // xmm5
  hkQuaternionf v11; // xmm2
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm4

  v4 = ((__int64 (__fastcall *)(hkpShape *))this->m_childShape.m_childShape->vfptr[6].__vecDelDtor)(this->m_childShape.m_childShape);
  v5 = ((__int64 (__fastcall *)(hkpShape *))this->m_childShape.m_childShape->vfptr[5].__first_virtual_table_function__)(this->m_childShape.m_childShape);
  v6 = _mm_shuffle_ps((__m128)LODWORD(this->m_radius), (__m128)LODWORD(this->m_radius), 0);
  v7 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    v8 = (__m128 *)(v4 + 16 * v7);
    do
    {
      v9.m_quad = (__m128)this->m_transform.m_translation;
      v10 = *v8--;
      --v7;
      v11.m_vec.m_quad = (__m128)this->m_transform.m_rotation;
      v12 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  v10,
                  _mm_movelh_ps(
                    _mm_unpacklo_ps(
                      _mm_shuffle_ps(v9.m_quad, v9.m_quad, 255),
                      _mm_shuffle_ps(this->m_transform.m_scale.m_quad, this->m_transform.m_scale.m_quad, 255)),
                    _mm_unpacklo_ps(
                      _mm_shuffle_ps(this->m_extraScale.m_quad, this->m_extraScale.m_quad, 255),
                      aabbOut.m_quad))),
                this->m_extraScale.m_quad),
              _mm_mul_ps(v10, this->m_transform.m_scale.m_quad));
      v13 = _mm_shuffle_ps(v11.m_vec.m_quad, v11.m_vec.m_quad, 255);
      v14 = _mm_mul_ps(v11.m_vec.m_quad, v12);
      v15 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v11.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v11.m_vec.m_quad, v11.m_vec.m_quad, 201), v12));
      v16 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                    _mm_shuffle_ps(v14, v14, 170)),
                  v11.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v12)),
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v13));
      v17 = _mm_add_ps(_mm_add_ps(v16, v16), v9.m_quad);
      *(__m128 *)((char *)v8 + (_QWORD)sphereBuffer - v4 + 16) = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, v6), 196);
    }
    while ( v7 >= 0 );
  }
  return sphereBuffer;
}

// File Line: 269
// RVA: 0xCF1950
hkpSingleShapeContainer *__fastcall hkpConvexTransformShape::getContainer(hkpConvexTransformShape *this)
{
  return &this->m_childShape;
}

// File Line: 274
// RVA: 0xCF1960
__int64 __fastcall hkpConvexTransformShape::calcSizeForSpu(
        hkpConvexTransformShape *this,
        hkpShape::CalcSizeForSpuInput *input,
        int spuBufferSizeLeft)
{
  int v4; // edi
  int v5; // eax

  v4 = spuBufferSizeLeft - 128;
  v5 = ((__int64 (__fastcall *)(hkpShape *, hkpShape::CalcSizeForSpuInput *, _QWORD))this->m_childShape.m_childShape->vfptr[8].__vecDelDtor)(
         this->m_childShape.m_childShape,
         input,
         (unsigned int)(spuBufferSizeLeft - 128));
  if ( v5 < 0 || v5 > v4 )
    return 0xFFFFFFFFi64;
  if ( this->m_childShape.m_childShape == &this[1] )
  {
    this->m_childShapeSizeForSpu = 0;
    return (unsigned int)v5 + 128i64;
  }
  else
  {
    this->m_childShapeSizeForSpu = v5;
    return 128i64;
  }
}

