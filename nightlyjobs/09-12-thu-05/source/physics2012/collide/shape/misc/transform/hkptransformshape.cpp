// File Line: 25
// RVA: 0xD0FCA0
void __fastcall hkpTransformShape::hkpTransformShape(hkpTransformShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpTransformShape *v2; // rbx

  v2 = this;
  hkpShape::hkpShape((hkpShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpTransformShape::`vftable';
  v2->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable';
  v2->m_type.m_storage = 14;
}

// File Line: 30
// RVA: 0xD0F850
void __fastcall hkpTransformShape::setTransform(hkpTransformShape *this, hkTransformf *transform)
{
  hkVector4f *v2; // rax

  v2 = &this->m_transform.m_rotation.m_col0;
  *v2 = transform->m_rotation.m_col0;
  v2[1] = transform->m_rotation.m_col1;
  v2[2] = transform->m_rotation.m_col2;
  v2[3] = transform->m_translation;
  hkQuaternionf::set(&this->m_rotation, &this->m_transform.m_rotation);
}

// File Line: 38
// RVA: 0xD0F7E0
void __fastcall hkpTransformShape::hkpTransformShape(hkpTransformShape *this, hkpShape *childShape, hkTransformf *transform)
{
  hkpTransformShape *v3; // rdi
  hkTransformf *v4; // rbx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1038;
  this->m_userData = 0i64;
  v3 = this;
  v4 = transform;
  this->vfptr = (hkBaseObjectVtbl *)&hkpTransformShape::`vftable';
  this->m_childShape.m_childShape = childShape;
  this->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable';
  hkReferencedObject::addReference((hkReferencedObject *)&childShape->vfptr);
  hkpTransformShape::setTransform(v3, v4);
}

// File Line: 46
// RVA: 0xD0F890
void __fastcall hkpTransformShape::getAabb(hkpTransformShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  hkpTransformShape *v4; // rbx
  hkAabb *v5; // rdi
  __int64 v6; // r8
  hkTransformf v7; // [rsp+20h] [rbp-58h]

  v4 = this;
  v5 = out;
  hkTransformf::setMul(&v7, localToWorld, &this->m_transform);
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, hkAabb *))v4->m_childShape.m_childShape->vfptr[2].__vecDelDtor)(
    v4->m_childShape.m_childShape,
    &v7,
    v6,
    v5);
}

// File Line: 54
// RVA: 0xD0FCE0
float __fastcall hkpTransformShape::getMaximumProjection(hkpTransformShape *this, hkVector4f *direction)
{
  hkVector4f v2; // xmm4
  hkpTransformShape *v3; // rbx
  hkVector4f *v4; // rdi
  __m128 v5; // xmm1
  __m128 v6; // xmm5
  hkpShape *v7; // rcx
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm0
  __m128 v13; // xmm2
  __m128 v15; // [rsp+20h] [rbp-18h]

  v2.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v3 = this;
  v4 = direction;
  v5 = _mm_unpacklo_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v6 = _mm_shuffle_ps(
         _mm_unpackhi_ps(this->m_transform.m_rotation.m_col0.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
         v2.m_quad,
         228);
  v7 = this->m_childShape.m_childShape;
  v8 = _mm_movelh_ps(v5, v2.m_quad);
  v9 = _mm_movehl_ps(v8, v5);
  v10 = direction->m_quad;
  v11 = _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v9, v2.m_quad, 212));
  v12 = _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v8);
  v15 = _mm_add_ps(_mm_add_ps(v11, v12), _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), v6));
  ((void (__fastcall *)(hkpShape *, __m128 *))v7->vfptr[7].__first_virtual_table_function__)(v7, &v15);
  v13 = _mm_mul_ps(v3->m_transform.m_translation.m_quad, v4->m_quad);
  return (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
               + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170)))
       + v12.m128_f32[0];
}

// File Line: 68
// RVA: 0xD0F8F0
hkBool *__fastcall hkpTransformShape::castRay(hkpTransformShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkpTransformShape *v4; // rbx
  hkpShapeRayCastOutput *v5; // rdi
  hkpShapeRayCastInput *v6; // rbp
  hkBool *v7; // rsi
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __m128 v13; // xmm3
  __m128 v14; // xmm4
  __int128 v15; // xmm0
  __m128 v16; // xmm5
  __m128 v17; // xmm5
  __int128 v18; // xmm1
  __int128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm5
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  __m128 v28; // xmm5
  __m128 v29; // xmm1
  __m128 v30; // xmm4
  hkpShape *v31; // rcx
  __m128 v32; // xmm0
  __int64 v33; // rax
  _QWORD *v34; // r8
  _QWORD *v35; // rcx
  unsigned __int64 v36; // rax
  signed __int64 v37; // rcx
  __int128 v39; // [rsp+20h] [rbp-48h]
  __m128 v40; // [rsp+30h] [rbp-38h]
  __int128 v41; // [rsp+40h] [rbp-28h]
  __int128 v42; // [rsp+50h] [rbp-18h]

  v4 = this;
  v5 = results;
  v6 = input;
  v7 = result;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcTransform";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = v4->m_transform.m_rotation.m_col2.m_quad;
  v14 = v4->m_transform.m_rotation.m_col0.m_quad;
  v15 = (__int128)v6->m_from;
  v16 = v6->m_from.m_quad;
  v40 = v6->m_to.m_quad;
  v17 = _mm_sub_ps(v16, v4->m_transform.m_translation.m_quad);
  v18 = *(_OWORD *)&v6->m_collidable;
  v39 = v15;
  v19 = *(_OWORD *)&v6->m_filterInfo;
  v42 = v18;
  v41 = v19;
  v20 = _mm_unpacklo_ps(v14, v4->m_transform.m_rotation.m_col1.m_quad);
  v21 = _mm_movelh_ps(v20, v13);
  v22 = _mm_movehl_ps(v21, v20);
  v23 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v21);
  v24 = _mm_shuffle_ps(v17, v17, 85);
  v25 = _mm_mul_ps(
          _mm_shuffle_ps(v17, v17, 170),
          _mm_shuffle_ps(_mm_unpackhi_ps(v14, v4->m_transform.m_rotation.m_col1.m_quad), v13, 228));
  v26 = v4->m_transform.m_rotation.m_col0.m_quad;
  v27 = _mm_add_ps(_mm_add_ps(v23, _mm_mul_ps(v24, _mm_shuffle_ps(v22, v13, 212))), v25);
  v28 = _mm_sub_ps(v6->m_to.m_quad, v4->m_transform.m_translation.m_quad);
  v39 = (__int128)v27;
  v29 = _mm_unpacklo_ps(v26, v4->m_transform.m_rotation.m_col1.m_quad);
  v30 = _mm_shuffle_ps(_mm_unpackhi_ps(v26, v4->m_transform.m_rotation.m_col1.m_quad), v13, 228);
  ++v5->m_shapeKeyIndex;
  v31 = v4->m_childShape.m_childShape;
  v32 = _mm_movelh_ps(v29, v13);
  v40 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), v32),
            _mm_mul_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(_mm_movehl_ps(v32, v29), v13, 212))),
          _mm_mul_ps(_mm_shuffle_ps(v28, v28, 170), v30));
  ((void (__fastcall *)(hkpShape *, hkBool *, __int128 *, hkpShapeRayCastOutput *, _QWORD, _QWORD, unsigned __int64, unsigned __int64, _QWORD, _QWORD, _QWORD, _QWORD))v31->vfptr[2].__first_virtual_table_function__)(
    v31,
    v7,
    &v39,
    v5,
    v39,
    *((_QWORD *)&v39 + 1),
    v40.m128_u64[0],
    v40.m128_u64[1],
    v41,
    *((_QWORD *)&v41 + 1),
    v42,
    *((_QWORD *)&v42 + 1));
  --v5->m_shapeKeyIndex;
  if ( v7->m_bool )
  {
    v33 = v5->m_shapeKeyIndex;
    v5->m_normal.m_quad = _mm_add_ps(
                            _mm_add_ps(
                              _mm_mul_ps(
                                _mm_shuffle_ps(v5->m_normal.m_quad, v5->m_normal.m_quad, 85),
                                v4->m_transform.m_rotation.m_col1.m_quad),
                              _mm_mul_ps(
                                _mm_shuffle_ps(v5->m_normal.m_quad, v5->m_normal.m_quad, 0),
                                v4->m_transform.m_rotation.m_col0.m_quad)),
                            _mm_mul_ps(
                              _mm_shuffle_ps(v5->m_normal.m_quad, v5->m_normal.m_quad, 170),
                              v4->m_transform.m_rotation.m_col2.m_quad));
    v5->m_shapeKeys[v33] = 0;
  }
  v34 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v35 = (_QWORD *)v34[1];
  if ( (unsigned __int64)v35 < v34[3] )
  {
    *v35 = "Et";
    v36 = __rdtsc();
    v37 = (signed __int64)(v35 + 2);
    *(_DWORD *)(v37 - 8) = v36;
    v34[1] = v37;
  }
  return v7;
}

// File Line: 91
// RVA: 0xD0FAD0
void __fastcall hkpTransformShape::castRayWithCollector(hkpTransformShape *this, hkpShapeRayCastInput *input, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkpTransformShape *v4; // rsi
  hkpRayHitCollector *v5; // rbp
  hkpCdBody *v6; // rdi
  hkpShapeRayCastInput *v7; // rbx
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __m128 v13; // xmm3
  __m128 v14; // xmm4
  hkTransformf *v15; // rdx
  __int128 v16; // xmm0
  __m128 v17; // xmm5
  __m128 v18; // xmm5
  __int128 v19; // xmm1
  __int128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm5
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  __m128 v28; // xmm5
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  __int64 v31; // rcx
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  signed __int64 v35; // rcx
  __int64 v36; // [rsp+20h] [rbp-A8h]
  int v37; // [rsp+28h] [rbp-A0h]
  hkTransformf *v38; // [rsp+30h] [rbp-98h]
  hkpCdBody *v39; // [rsp+38h] [rbp-90h]
  __int128 v40; // [rsp+40h] [rbp-88h]
  __m128 v41; // [rsp+50h] [rbp-78h]
  __int128 v42; // [rsp+60h] [rbp-68h]
  __int128 v43; // [rsp+70h] [rbp-58h]
  hkTransformf v44; // [rsp+80h] [rbp-48h]

  v4 = this;
  v5 = collector;
  v6 = cdBody;
  v7 = input;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcTransform";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = v4->m_transform.m_rotation.m_col2.m_quad;
  v14 = v4->m_transform.m_rotation.m_col0.m_quad;
  v15 = (hkTransformf *)v6->m_motion;
  v16 = (__int128)v7->m_from;
  v17 = v7->m_from.m_quad;
  v41 = v7->m_to.m_quad;
  v18 = _mm_sub_ps(v17, v4->m_transform.m_translation.m_quad);
  v19 = *(_OWORD *)&v7->m_collidable;
  v40 = v16;
  v20 = *(_OWORD *)&v7->m_filterInfo;
  v43 = v19;
  v42 = v20;
  v21 = _mm_unpacklo_ps(v14, v4->m_transform.m_rotation.m_col1.m_quad);
  v22 = _mm_movelh_ps(v21, v13);
  v23 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(_mm_movehl_ps(v22, v21), v13, 212));
  v24 = _mm_shuffle_ps(v18, v18, 0);
  v25 = _mm_mul_ps(
          _mm_shuffle_ps(v18, v18, 170),
          _mm_shuffle_ps(_mm_unpackhi_ps(v14, v4->m_transform.m_rotation.m_col1.m_quad), v13, 228));
  v26 = v4->m_transform.m_rotation.m_col0.m_quad;
  v27 = _mm_add_ps(_mm_add_ps(v23, _mm_mul_ps(v24, v22)), v25);
  v28 = _mm_sub_ps(v7->m_to.m_quad, v4->m_transform.m_translation.m_quad);
  v40 = (__int128)v27;
  v29 = _mm_unpacklo_ps(v26, v4->m_transform.m_rotation.m_col1.m_quad);
  v30 = _mm_movelh_ps(v29, v13);
  v41 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(_mm_movehl_ps(v30, v29), v13, 212)),
            _mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), v30)),
          _mm_mul_ps(
            _mm_shuffle_ps(v28, v28, 170),
            _mm_shuffle_ps(_mm_unpackhi_ps(v26, v4->m_transform.m_rotation.m_col1.m_quad), v13, 228)));
  hkTransformf::setMul(&v44, v15, &v4->m_transform);
  v31 = (__int64)v4->m_childShape.m_childShape;
  v39 = v6;
  v37 = 0;
  v36 = v31;
  v38 = &v44;
  (*(void (__fastcall **)(__int64, __int128 *, __int64 *, hkpRayHitCollector *, __int64, _QWORD, hkTransformf *, hkpCdBody *, _QWORD, _QWORD, unsigned __int64, unsigned __int64, _QWORD, _QWORD, _QWORD, _QWORD))(*(_QWORD *)v31 + 48i64))(
    v31,
    &v40,
    &v36,
    v5,
    v31,
    *(_QWORD *)&v37,
    &v44,
    v6,
    v40,
    *((_QWORD *)&v40 + 1),
    v41.m128_u64[0],
    v41.m128_u64[1],
    v42,
    *((_QWORD *)&v42 + 1),
    v43,
    *((_QWORD *)&v43 + 1));
  v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v33 = (_QWORD *)v32[1];
  if ( (unsigned __int64)v33 < v32[3] )
  {
    *v33 = "Et";
    v34 = __rdtsc();
    v35 = (signed __int64)(v33 + 2);
    *(_DWORD *)(v35 - 8) = v34;
    v32[1] = v35;
  }
}Et";
    v34 = __rdtsc();
    v35 = (signed __int64)(v33 + 2);
    *(_DWORD *)(v35 

// File Line: 111
// RVA: 0xD0FD90
hkpSingleShapeContainer *__fastcall hkpTransformShape::getContainer(hkpTransformShape *this)
{
  return &this->m_childShape;
}

// File Line: 116
// RVA: 0xD0FDA0
signed __int64 __fastcall hkpTransformShape::calcSizeForSpu(hkpTransformShape *this, hkpShape::CalcSizeForSpuInput *input, int spuBufferSizeLeft)
{
  hkpTransformShape *v3; // rbx
  int v4; // edi
  int v5; // eax
  signed __int64 result; // rax

  v3 = this;
  v4 = spuBufferSizeLeft - 144;
  v5 = ((__int64 (__fastcall *)(hkpShape *, hkpShape::CalcSizeForSpuInput *, _QWORD))this->m_childShape.m_childShape->vfptr[8].__vecDelDtor)(
         this->m_childShape.m_childShape,
         input,
         (unsigned int)(spuBufferSizeLeft - 144));
  if ( v5 < 0 || v5 > v4 )
    return 0xFFFFFFFFi64;
  if ( (hkpTransformShape *)v3->m_childShape.m_childShape == &v3[1] )
  {
    v3->m_childShapeSize = 0;
    result = (unsigned int)v5 + 144i64;
  }
  else
  {
    v3->m_childShapeSize = v5;
    result = 144i64;
  }
  return result;
}

