// File Line: 20
// RVA: 0xCF0B30
void __fastcall hkpConvexTransformShape::hkpConvexTransformShape(hkpConvexTransformShape *this, hkpConvexShape *childShape, hkTransformf *transform, hkpShapeContainer::ReferencePolicy ref)
{
  hkpConvexShape *v4; // rdi
  hkTransformf *v5; // rbx
  hkpConvexTransformShape *v6; // rsi

  v4 = childShape;
  v5 = transform;
  v6 = this;
  hkpConvexTransformShapeBase::hkpConvexTransformShapeBase(
    (hkpConvexTransformShapeBase *)&this->vfptr,
    CONVEX_TRANSFORM,
    childShape->m_radius,
    childShape,
    ref);
  v6->vfptr = (hkBaseObjectVtbl *)&hkpConvexTransformShape::`vftable';
  hkQsTransformf::setFromTransformNoScale(&v6->m_transform, v5);
  v6->m_extraScale = 0i64;
  v6->m_userData = v4->m_userData;
}

// File Line: 28
// RVA: 0xCF0BA0
void __fastcall hkpConvexTransformShape::hkpConvexTransformShape(hkpConvexTransformShape *this, hkpConvexShape *childShape, hkQsTransformf *transform, hkpShapeContainer::ReferencePolicy ref)
{
  hkpConvexShape *v4; // rdi
  hkQsTransformf *v5; // rbx
  hkpConvexTransformShape *v6; // rsi

  v4 = childShape;
  v5 = transform;
  v6 = this;
  hkpConvexTransformShapeBase::hkpConvexTransformShapeBase(
    (hkpConvexTransformShapeBase *)&this->vfptr,
    CONVEX_TRANSFORM,
    childShape->m_radius,
    childShape,
    ref);
  v6->vfptr = (hkBaseObjectVtbl *)&hkpConvexTransformShape::`vftable';
  hkpConvexTransformShape::setTransform(v6, v5);
  v6->m_userData = v4->m_userData;
}

// File Line: 39
// RVA: 0xCF0C10
void __fastcall hkpConvexTransformShape::hkpConvexTransformShape(hkpConvexTransformShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpConvexTransformShape *v2; // rbx

  v2 = this;
  hkpConvexShape::hkpConvexShape((hkpConvexShape *)&this->vfptr, flag);
  v2->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable';
  v2->m_type.m_storage = 11;
  v2->vfptr = (hkBaseObjectVtbl *)&hkpConvexTransformShape::`vftable';
}

// File Line: 46
// RVA: 0xCF1390
void __usercall hkpConvexTransformShape::getAabb(hkpConvexTransformShape *this@<rcx>, hkTransformf *localToWorld@<rdx>, float tolerance@<xmm2>, hkAabb *out@<r9>, __int64 a5@<r8>)
{
  hkpConvexTransformShape *v5; // rbx
  hkAabb *v6; // rsi
  hkTransformf *v7; // rdi
  __m128 v8; // xmm6
  __m128 v9; // xmm7
  __m128 v10; // xmm5
  __m128 v11; // xmm2
  __m128 v12; // [rsp+20h] [rbp-88h]
  __m128 v13; // [rsp+30h] [rbp-78h]
  hkTransformf transformOut; // [rsp+40h] [rbp-68h]

  v5 = this;
  v6 = out;
  v7 = localToWorld;
  ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, __m128 *))this->m_childShape.m_childShape->vfptr[2].__vecDelDtor)(
    this->m_childShape.m_childShape,
    &transform,
    a5,
    &v12);
  v8 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(v13, v12), (__m128)xmmword_141A711B0), v5->m_transform.m_scale.m_quad);
  v9 = _mm_mul_ps(_mm_mul_ps(_mm_add_ps(v13, v12), (__m128)xmmword_141A711B0), v5->m_transform.m_scale.m_quad);
  hkQsTransformf::copyToTransformNoScale(&v5->m_transform, &transformOut);
  hkTransformf::setMul(&transformOut, v7, &transformOut);
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
  v6->m_max.m_quad = _mm_add_ps(v11, v10);
  v6->m_min.m_quad = _mm_add_ps(
                       _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v10),
                       v11);
}

// File Line: 76
// RVA: 0xCF14F0
hkBool *__fastcall hkpConvexTransformShape::castRay(hkpConvexTransformShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkpConvexTransformShape *v4; // rsi
  hkpShapeRayCastOutput *v5; // rdi
  hkpShapeRayCastInput *v6; // rbp
  hkBool *v7; // rbx
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
  __m128 v12; // xmm8
  __m128 v13; // xmm0
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
  hkpShape *v27; // rcx
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm11
  __int64 v31; // rax
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
  signed __int64 v43; // rcx
  __m128 v45; // [rsp+20h] [rbp-98h]
  __m128 v46; // [rsp+30h] [rbp-88h]
  __int128 v47; // [rsp+40h] [rbp-78h]
  __int128 v48; // [rsp+50h] [rbp-68h]

  v4 = this;
  v5 = results;
  v6 = input;
  v7 = result;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcCxTransform";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  v12 = v4->m_transform.m_rotation.m_vec.m_quad;
  v13 = v4->m_transform.m_scale.m_quad;
  v14 = _mm_sub_ps(v6->m_from.m_quad, v4->m_transform.m_translation.m_quad);
  v15 = _mm_rcp_ps(v13);
  v16 = _mm_sub_ps(v6->m_to.m_quad, v4->m_transform.m_translation.m_quad);
  v17 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v13, v15)), v15);
  v18 = _mm_shuffle_ps(v4->m_transform.m_rotation.m_vec.m_quad, v12, 255);
  v19 = _mm_shuffle_ps(v12, v12, 201);
  v20 = *(_OWORD *)&v6->m_collidable;
  v47 = *(_OWORD *)&v6->m_filterInfo;
  v48 = v20;
  v21 = _mm_mul_ps(v14, v12);
  v22 = _mm_sub_ps(_mm_mul_ps(v14, v19), _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v12));
  v23 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
            _mm_shuffle_ps(v21, v21, 170)),
          v12);
  v24 = _mm_mul_ps(v16, v12);
  v25 = _mm_add_ps(
          _mm_add_ps(v23, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v18, v18), (__m128)xmmword_141A711B0), v14)),
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v18));
  v26 = _mm_sub_ps(_mm_mul_ps(v16, v19), _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v12));
  v45 = _mm_mul_ps(_mm_add_ps(v25, v25), v17);
  ++v5->m_shapeKeyIndex;
  v27 = v4->m_childShape.m_childShape;
  v28 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                _mm_shuffle_ps(v24, v24, 170)),
              v12),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v18, v18), (__m128)xmmword_141A711B0), v16)),
          _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v18));
  v46 = _mm_mul_ps(_mm_add_ps(v28, v28), v17);
  ((void (__fastcall *)(hkpShape *, hkBool *, __m128 *, hkpShapeRayCastOutput *, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64, _QWORD, _QWORD, _QWORD, _QWORD))v27->vfptr[2].__first_virtual_table_function__)(
    v27,
    v7,
    &v45,
    v5,
    v45.m128_u64[0],
    v45.m128_u64[1],
    v46.m128_u64[0],
    v46.m128_u64[1],
    v47,
    *((_QWORD *)&v47 + 1),
    v48,
    *((_QWORD *)&v48 + 1));
  --v5->m_shapeKeyIndex;
  if ( v7->m_bool )
  {
    v29 = v4->m_transform.m_rotation.m_vec.m_quad;
    v30 = _mm_mul_ps(v17, v5->m_normal.m_quad);
    v31 = v5->m_shapeKeyIndex;
    v32 = _mm_shuffle_ps(v4->m_transform.m_rotation.m_vec.m_quad, v29, 255);
    v33 = _mm_mul_ps(v30, v29);
    v34 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v29), _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v30));
    v35 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v33, v33, 85), _mm_shuffle_ps(v33, v33, 0)),
                  _mm_shuffle_ps(v33, v33, 170)),
                v29),
              _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v32, v32), (__m128)xmmword_141A711B0), v30)),
            _mm_mul_ps(_mm_shuffle_ps(v34, v34, 201), v32));
    v36 = _mm_add_ps(v35, v35);
    v37 = _mm_mul_ps(v36, v36);
    v38 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
            _mm_shuffle_ps(v37, v37, 170));
    v39 = _mm_rsqrt_ps(v38);
    v5->m_normal.m_quad = _mm_mul_ps(
                            _mm_andnot_ps(
                              _mm_cmpleps(v38, (__m128)0i64),
                              _mm_mul_ps(
                                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v39, v38), v39)),
                                _mm_mul_ps(*(__m128 *)_xmm, v39))),
                            v36);
    v5->m_shapeKeys[v31] = 0;
  }
  v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v41 = (_QWORD *)v40[1];
  if ( (unsigned __int64)v41 < v40[3] )
  {
    *v41 = "Et";
    v42 = __rdtsc();
    v43 = (signed __int64)(v41 + 2);
    *(_DWORD *)(v43 - 8) = v42;
    v40[1] = v43;
  }
  return v7;
}

// File Line: 119
// RVA: 0xCF17F0
void __fastcall hkpConvexTransformShape::castRayWithCollector(hkpConvexTransformShape *this, hkpShapeRayCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkpConvexTransformShape *v4; // rbx
  hkpRayHitCollector *v5; // rsi
  hkpCdBody *v6; // rbp
  hkpShapeRayCastInput *v7; // rdi
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  hkBaseObjectVtbl *v13; // rax
  __int64 v14; // rax
  hkpRayHitCollectorVtbl *v15; // rax
  _QWORD *v16; // r8
  _QWORD *v17; // rcx
  unsigned __int64 v18; // rax
  signed __int64 v19; // rcx
  __int64 v20; // [rsp+20h] [rbp-78h]
  int v21; // [rsp+28h] [rbp-70h]
  __m128 *v22; // [rsp+30h] [rbp-68h]
  hkpCdBody *v23; // [rsp+38h] [rbp-60h]
  __m128 v24; // [rsp+40h] [rbp-58h]
  int v25; // [rsp+50h] [rbp-48h]
  int v26; // [rsp+54h] [rbp-44h]
  int v27; // [rsp+60h] [rbp-38h]
  int v28; // [rsp+80h] [rbp-18h]
  char v29; // [rsp+A0h] [rbp+8h]

  v4 = this;
  v5 = collector;
  v6 = cdBody;
  v7 = input;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcCxTransform";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = v4->vfptr;
  v25 = (signed int)FLOAT_1_0;
  v26 = -1;
  v28 = 0;
  v27 = -1;
  if ( *(_BYTE *)((__int64 (__fastcall *)(hkpConvexTransformShape *, char *, hkpShapeRayCastInput *, __m128 *))v13[2].__first_virtual_table_function__)(
                   v4,
                   &v29,
                   v7,
                   &v24) )
  {
    v14 = (__int64)v4->m_childShape.m_childShape;
    v22 = (__m128 *)v6->m_motion;
    v20 = v14;
    v15 = v5->vfptr;
    v23 = v6;
    v21 = 0;
    v24 = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v22[1]), _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), *v22)),
            _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v22[2]));
    v15->addRayHit(v5, (hkpCdBody *)&v20, (hkpShapeRayCastCollectorOutput *)&v24);
  }
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = (_QWORD *)v16[1];
  if ( (unsigned __int64)v17 < v16[3] )
  {
    *v17 = "Et";
    v18 = __rdtsc();
    v19 = (signed __int64)(v17 + 2);
    *(_DWORD *)(v19 - 8) = v18;
    v16[1] = v19;
  }
}

// File Line: 135
// RVA: 0xCF0E80
void __fastcall hkpConvexTransformShape::getSupportingVertex(hkpConvexTransformShape *this, hkVector4f *direction, hkcdVertex *supportingVertexOut)
{
  hkQuaternionf v3; // xmm2
  hkpConvexTransformShape *v4; // rbx
  hkcdVertex *v5; // rdi
  __m128 v6; // xmm1
  __m128 v7; // xmm5
  __m128 v8; // xmm6
  __m128 v9; // xmm4
  __m128 v10; // xmm4
  hkpShape *v11; // rcx
  __m128 v12; // xmm2
  __m128 v13; // xmm7
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm6
  __m128 v17; // xmm0
  __m128 v18; // xmm6
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  __m128 v21; // xmm5
  __m128 v22; // xmm3
  __m128 v23; // xmm4
  __m128 v24; // xmm4
  __m128 v25; // xmm1
  __m128 v26; // [rsp+20h] [rbp-48h]
  __m128 v27; // [rsp+30h] [rbp-38h]

  v3.m_vec.m_quad = (__m128)this->m_transform.m_rotation;
  v4 = this;
  v5 = supportingVertexOut;
  v6 = _mm_mul_ps(this->m_transform.m_rotation.m_vec.m_quad, direction->m_quad);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v3.m_vec.m_quad, v3.m_vec.m_quad, 201), direction->m_quad),
         _mm_mul_ps(_mm_shuffle_ps(direction->m_quad, direction->m_quad, 201), v3.m_vec.m_quad));
  v8 = _mm_shuffle_ps(this->m_transform.m_rotation.m_vec.m_quad, v3.m_vec.m_quad, 255);
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(
             _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170)),
             v3.m_vec.m_quad),
           _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v8, v8), (__m128)xmmword_141A711B0), direction->m_quad)),
         _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v8));
  v10 = _mm_mul_ps(_mm_add_ps(v9, v9), this->m_transform.m_scale.m_quad);
  v11 = this->m_childShape.m_childShape;
  v26 = v10;
  ((void (__fastcall *)(hkpShape *, __m128 *, __m128 *))v11->vfptr[4].__vecDelDtor)(v11, &v26, &v27);
  v12 = v4->m_transform.m_scale.m_quad;
  v13 = v27;
  v14 = _mm_unpacklo_ps(
          _mm_shuffle_ps(v4->m_transform.m_translation.m_quad, v4->m_transform.m_translation.m_quad, 255),
          _mm_shuffle_ps(v12, v12, 255));
  v15 = _mm_mul_ps(v12, v27);
  v16 = v27;
  v17 = _mm_unpacklo_ps(_mm_shuffle_ps(v4->m_extraScale.m_quad, v4->m_extraScale.m_quad, 255), aabbOut.m_quad);
  *v5 = (hkcdVertex)v15;
  v18 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v16, _mm_movelh_ps(v14, v17)), v4->m_extraScale.m_quad), v15);
  *v5 = (hkcdVertex)v18;
  v19 = v4->m_transform.m_rotation.m_vec.m_quad;
  v20 = _mm_mul_ps(v4->m_transform.m_rotation.m_vec.m_quad, v18);
  v21 = _mm_shuffle_ps(v4->m_transform.m_rotation.m_vec.m_quad, v19, 255);
  v22 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v19),
          _mm_mul_ps(_mm_shuffle_ps(v4->m_transform.m_rotation.m_vec.m_quad, v19, 201), v18));
  v23 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                _mm_shuffle_ps(v20, v20, 170)),
              v19),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v21, v21), (__m128)xmmword_141A711B0), v18)),
          _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v21));
  v24 = _mm_add_ps(v23, v23);
  *v5 = (hkcdVertex)v24;
  v25 = _mm_add_ps(v4->m_transform.m_translation.m_quad, v24);
  v5->m_quad = _mm_shuffle_ps(v25, _mm_unpackhi_ps(v25, v13), 196);
}

// File Line: 147
// RVA: 0xCF1000
void __fastcall hkpConvexTransformShape::convertVertexIdsToVertices(hkpConvexTransformShape *this, const unsigned __int16 *ids, int numIds, hkcdVertex *verticesOut)
{
  hkpConvexTransformShape *v4; // rsi
  __int64 v5; // rbx
  hkcdVertex *v6; // rdi
  __int64 v7; // rax
  __m128 v8; // xmm8
  __m128 v9; // xmm7
  __m128 v10; // xmm2
  __m128 v11; // xmm5
  __m128 v12; // xmm6
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  __m128 v16; // xmm4

  v4 = this;
  v5 = numIds;
  v6 = verticesOut;
  ((void (__fastcall *)(hkpShape *, const unsigned __int16 *, _QWORD))this->m_childShape.m_childShape->vfptr[4].__first_virtual_table_function__)(
    this->m_childShape.m_childShape,
    ids,
    (unsigned int)numIds);
  v7 = v5;
  if ( v5 > 0 )
  {
    do
    {
      v8 = v6->m_quad;
      ++v6;
      v9 = v4->m_transform.m_translation.m_quad;
      v10 = v4->m_transform.m_rotation.m_vec.m_quad;
      v11 = _mm_shuffle_ps(v4->m_transform.m_rotation.m_vec.m_quad, v10, 255);
      v12 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  v8,
                  _mm_movelh_ps(
                    _mm_unpacklo_ps(
                      _mm_shuffle_ps(v9, v9, 255),
                      _mm_shuffle_ps(v4->m_transform.m_scale.m_quad, v4->m_transform.m_scale.m_quad, 255)),
                    _mm_unpacklo_ps(
                      _mm_shuffle_ps(v4->m_extraScale.m_quad, v4->m_extraScale.m_quad, 255),
                      aabbOut.m_quad))),
                v4->m_extraScale.m_quad),
              _mm_mul_ps(v8, v4->m_transform.m_scale.m_quad));
      v13 = _mm_mul_ps(v10, v12);
      v14 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v10),
              _mm_mul_ps(_mm_shuffle_ps(v4->m_transform.m_rotation.m_vec.m_quad, v10, 201), v12));
      v15 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v13, v13, 85), _mm_shuffle_ps(v13, v13, 0)),
                    _mm_shuffle_ps(v13, v13, 170)),
                  v10),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v11, v11), (__m128)xmmword_141A711B0), v12)),
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v11));
      v16 = _mm_add_ps(_mm_add_ps(v15, v15), v9);
      v6[-1].m_quad = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, v8), 196);
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 161
// RVA: 0xCF1140
void __fastcall hkpConvexTransformShape::getCentre(hkpConvexTransformShape *this, hkVector4f *centreOut)
{
  hkpConvexTransformShape *v2; // rbx
  hkVector4f *v3; // rdi
  __m128 v4; // xmm2
  __m128 v5; // xmm6
  __m128 v6; // xmm0
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  __m128 v10; // xmm6
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm5
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  __m128 v16; // xmm4
  __m128 v17; // [rsp+20h] [rbp-28h]

  v2 = this;
  v3 = centreOut;
  this->m_childShape.m_childShape->vfptr[5].__vecDelDtor(
    (hkBaseObject *)this->m_childShape.m_childShape,
    (unsigned int)&v17);
  v4 = v2->m_transform.m_scale.m_quad;
  v5 = v17;
  v6 = _mm_shuffle_ps(v4, v4, 255);
  v7 = _mm_mul_ps(v4, v17);
  v8 = _mm_unpacklo_ps(
         _mm_shuffle_ps(v2->m_transform.m_translation.m_quad, v2->m_transform.m_translation.m_quad, 255),
         v6);
  v9 = _mm_unpacklo_ps(_mm_shuffle_ps(v2->m_extraScale.m_quad, v2->m_extraScale.m_quad, 255), aabbOut.m_quad);
  *v3 = (hkVector4f)v7;
  v10 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v5, _mm_movelh_ps(v8, v9)), v2->m_extraScale.m_quad), v7);
  *v3 = (hkVector4f)v10;
  v11 = v2->m_transform.m_rotation.m_vec.m_quad;
  v12 = _mm_mul_ps(v2->m_transform.m_rotation.m_vec.m_quad, v10);
  v13 = _mm_shuffle_ps(v2->m_transform.m_rotation.m_vec.m_quad, v11, 255);
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v11),
          _mm_mul_ps(_mm_shuffle_ps(v2->m_transform.m_rotation.m_vec.m_quad, v11, 201), v10));
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                _mm_shuffle_ps(v12, v12, 170)),
              v11),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v10)),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13));
  v16 = _mm_add_ps(v15, v15);
  *v3 = (hkVector4f)v16;
  v3->m_quad = _mm_add_ps(v2->m_transform.m_translation.m_quad, v16);
}

// File Line: 167
// RVA: 0xCF0C50
void __fastcall hkpConvexTransformShape::setTransform(hkpConvexTransformShape *this, hkQsTransformf *transform)
{
  hkQsTransformf *v2; // rsi
  __m128 *v3; // rbx
  __m128i v4; // xmm0
  __m128i v5; // xmm1
  hkpShape *v6; // rdi
  hkBaseObjectVtbl *v7; // rax
  __m128 v8; // xmm6
  hkpShape *v9; // rcx
  __int64 v10; // r8
  __m128 v11; // xmm3
  __m128 v12; // xmm1
  __m128i v13; // xmm7
  __m128 v14; // xmm2
  __m128 v15; // xmm4
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm2
  __m128 v20; // xmm0
  __m128 v21; // [rsp+20h] [rbp-48h]
  __m128 v22; // [rsp+30h] [rbp-38h]

  v2 = transform;
  v3 = (__m128 *)this;
  this->m_transform.m_translation = transform->m_translation;
  this->m_transform.m_rotation = transform->m_rotation;
  v4 = (__m128i)transform->m_scale;
  v5 = _mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&this->m_transform), 4), 4);
  this->m_transform.m_scale = (hkVector4f)v4;
  _mm_store_si128((__m128i *)&this->m_transform, v5);
  _mm_store_si128((__m128i *)&this->m_transform.m_scale, _mm_srli_si128(_mm_slli_si128(v4, 4), 4));
  if ( (_mm_movemask_ps(
          _mm_cmpltps(
            (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(transform->m_scale.m_quad, query.m_quad), 1u), 1u),
            *(__m128 *)&epsilon)) & 7) == 7 )
  {
    this->m_extraScale = 0i64;
  }
  else
  {
    v6 = this->m_childShape.m_childShape;
    v7 = v6->vfptr;
    v8 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)transform->m_scale.m_quad, 1u), 1u);
    v9 = this->m_childShape.m_childShape;
    v21 = v8;
    if ( ((signed int (__fastcall *)(hkpShape *))v7[5].__first_virtual_table_function__)(v9) >= 3 )
    {
      ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, __m128 *))v6->vfptr[2].__vecDelDtor)(
        v6,
        &::transform,
        v10,
        &v21);
      v11 = _mm_shuffle_ps((__m128)v3[2].m128_u32[0], (__m128)v3[2].m128_u32[0], 0);
      v12 = _mm_shuffle_ps(
              (__m128)(unsigned int)(LODWORD(v6[1].vfptr) ^ _xmm[0]),
              (__m128)(unsigned int)(LODWORD(v6[1].vfptr) ^ _xmm[0]),
              0);
      v13 = _mm_srai_epi32(_mm_load_si128((const __m128i *)&v2->m_scale), 0x1Fu);
      v14 = _mm_add_ps(v22, v12);
      v15 = _mm_sub_ps(v21, v12);
      v16 = _mm_mul_ps(_mm_sub_ps(v14, v15), (__m128)xmmword_141A711B0);
      v17 = _mm_mul_ps(_mm_add_ps(v15, v14), (__m128)xmmword_141A711B0);
      v18 = _mm_mul_ps(_mm_add_ps(v11, v16), v8);
      if ( (_mm_movemask_ps(_mm_cmpltps(v11, v18)) & 7) == 7 )
      {
        v19 = v11;
      }
      else
      {
        v19 = _mm_min_ps(
                _mm_shuffle_ps(v18, v18, 170),
                _mm_min_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)));
        v3[2].m128_i32[0] = v19.m128_i32[0];
      }
      v20 = _mm_rcp_ps(v16);
      v3[7] = _mm_xor_ps(
                (__m128)_mm_slli_epi32(_mm_srli_epi32(v13, 0x1Fu), 0x1Fu),
                _mm_andnot_ps(
                  _mm_cmpeqps(v16, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v16, v20)), v20),
                    _mm_sub_ps(_mm_mul_ps(v11, v8), v19))));
      v3[4] = _mm_shuffle_ps(v3[4], _mm_unpackhi_ps(v3[4], _mm_shuffle_ps(v17, v17, 0)), 196);
      v3[6] = _mm_shuffle_ps(v3[6], _mm_unpackhi_ps(v3[6], _mm_shuffle_ps(v17, v17, 85)), 196);
      v3[7] = _mm_shuffle_ps(v3[7], _mm_unpackhi_ps(v3[7], _mm_shuffle_ps(v17, v17, 170)), 196);
    }
    else
    {
      v3[2].m128_f32[0] = v21.m128_f32[0] * *(float *)&v6[1].vfptr;
      v3[7] = 0i64;
    }
  }
}

// File Line: 238
// RVA: 0xCF19E0
void __fastcall hkpConvexTransformShape::getFirstVertex(hkpConvexTransformShape *this, hkVector4f *v)
{
  hkpConvexTransformShape *v2; // rbx
  hkVector4f *v3; // rdi
  __m128 v4; // xmm2
  __m128 v5; // xmm6
  __m128 v6; // xmm0
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  __m128 v10; // xmm6
  __m128 v11; // xmm2
  __m128 v12; // xmm1
  __m128 v13; // xmm5
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  __m128 v16; // xmm4
  __m128 v17; // [rsp+20h] [rbp-28h]

  v2 = this;
  v3 = v;
  ((void (__fastcall *)(hkpShape *, __m128 *))this->m_childShape.m_childShape->vfptr[8].__first_virtual_table_function__)(
    this->m_childShape.m_childShape,
    &v17);
  v4 = v2->m_transform.m_scale.m_quad;
  v5 = v17;
  v6 = _mm_shuffle_ps(v4, v4, 255);
  v7 = _mm_mul_ps(v4, v17);
  v8 = _mm_unpacklo_ps(
         _mm_shuffle_ps(v2->m_transform.m_translation.m_quad, v2->m_transform.m_translation.m_quad, 255),
         v6);
  v9 = _mm_unpacklo_ps(_mm_shuffle_ps(v2->m_extraScale.m_quad, v2->m_extraScale.m_quad, 255), aabbOut.m_quad);
  *v3 = (hkVector4f)v7;
  v10 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v5, _mm_movelh_ps(v8, v9)), v2->m_extraScale.m_quad), v7);
  *v3 = (hkVector4f)v10;
  v11 = v2->m_transform.m_rotation.m_vec.m_quad;
  v12 = _mm_mul_ps(v2->m_transform.m_rotation.m_vec.m_quad, v10);
  v13 = _mm_shuffle_ps(v2->m_transform.m_rotation.m_vec.m_quad, v11, 255);
  v14 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v11),
          _mm_mul_ps(_mm_shuffle_ps(v2->m_transform.m_rotation.m_vec.m_quad, v11, 201), v10));
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)),
                _mm_shuffle_ps(v12, v12, 170)),
              v11),
            _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v10)),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v13));
  v16 = _mm_add_ps(v15, v15);
  *v3 = (hkVector4f)v16;
  v3->m_quad = _mm_add_ps(v2->m_transform.m_translation.m_quad, v16);
}

// File Line: 247
// RVA: 0xCF1230
hkSphere *__fastcall hkpConvexTransformShape::getCollisionSpheres(hkpConvexTransformShape *this, hkSphere *sphereBuffer)
{
  hkpConvexTransformShape *v2; // rdi
  hkSphere *v3; // rbx
  __int64 v4; // rsi
  int v5; // eax
  __m128 v6; // xmm8
  __int64 v7; // rdx
  __m128 *v8; // rax
  __m128 v9; // xmm7
  __m128 v10; // xmm5
  __m128 v11; // xmm2
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm4
  __m128 v17; // xmm4

  v2 = this;
  v3 = sphereBuffer;
  v4 = ((__int64 (*)(void))this->m_childShape.m_childShape->vfptr[6].__vecDelDtor)();
  v5 = ((__int64 (*)(void))v2->m_childShape.m_childShape->vfptr[5].__first_virtual_table_function__)();
  v6 = _mm_shuffle_ps((__m128)LODWORD(v2->m_radius), (__m128)LODWORD(v2->m_radius), 0);
  v7 = v5 - 1;
  if ( v5 - 1 >= 0 )
  {
    v8 = (__m128 *)(v4 + 16 * v7);
    do
    {
      v9 = v2->m_transform.m_translation.m_quad;
      v10 = *v8;
      --v8;
      --v7;
      v11 = v2->m_transform.m_rotation.m_vec.m_quad;
      v12 = _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  v10,
                  _mm_movelh_ps(
                    _mm_unpacklo_ps(
                      _mm_shuffle_ps(v9, v9, 255),
                      _mm_shuffle_ps(v2->m_transform.m_scale.m_quad, v2->m_transform.m_scale.m_quad, 255)),
                    _mm_unpacklo_ps(
                      _mm_shuffle_ps(v2->m_extraScale.m_quad, v2->m_extraScale.m_quad, 255),
                      aabbOut.m_quad))),
                v2->m_extraScale.m_quad),
              _mm_mul_ps(v10, v2->m_transform.m_scale.m_quad));
      v13 = _mm_shuffle_ps(v2->m_transform.m_rotation.m_vec.m_quad, v11, 255);
      v14 = _mm_mul_ps(v2->m_transform.m_rotation.m_vec.m_quad, v12);
      v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v11), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 201), v12));
      v16 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                    _mm_shuffle_ps(v14, v14, 170)),
                  v11),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v13, v13), (__m128)xmmword_141A711B0), v12)),
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v13));
      v17 = _mm_add_ps(_mm_add_ps(v16, v16), v9);
      *(__m128 *)((char *)v8 + (_QWORD)v3 - v4 + 16) = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, v6), 196);
    }
    while ( v7 >= 0 );
  }
  return v3;
}

// File Line: 269
// RVA: 0xCF1950
hkpSingleShapeContainer *__fastcall hkpConvexTransformShape::getContainer(hkpConvexTransformShape *this)
{
  return &this->m_childShape;
}

// File Line: 274
// RVA: 0xCF1960
signed __int64 __fastcall hkpConvexTransformShape::calcSizeForSpu(hkpConvexTransformShape *this, hkpShape::CalcSizeForSpuInput *input, int spuBufferSizeLeft)
{
  hkpConvexTransformShape *v3; // rbx
  int v4; // edi
  int v5; // eax
  signed __int64 result; // rax

  v3 = this;
  v4 = spuBufferSizeLeft - 128;
  v5 = ((__int64 (__fastcall *)(hkpShape *, hkpShape::CalcSizeForSpuInput *, _QWORD))this->m_childShape.m_childShape->vfptr[8].__vecDelDtor)(
         this->m_childShape.m_childShape,
         input,
         (unsigned int)(spuBufferSizeLeft - 128));
  if ( v5 < 0 || v5 > v4 )
    return 0xFFFFFFFFi64;
  if ( (hkpConvexTransformShape *)v3->m_childShape.m_childShape == &v3[1] )
  {
    v3->m_childShapeSizeForSpu = 0;
    result = (unsigned int)v5 + 128i64;
  }
  else
  {
    v3->m_childShapeSizeForSpu = v5;
    result = 128i64;
  }
  return result;
}

