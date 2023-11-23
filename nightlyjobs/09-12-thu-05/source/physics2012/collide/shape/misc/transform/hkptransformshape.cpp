// File Line: 25
// RVA: 0xD0FCA0
void __fastcall hkpTransformShape::hkpTransformShape(hkpTransformShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpShape::hkpShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpTransformShape::`vftable;
  this->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  this->m_type.m_storage = 14;
}

// File Line: 30
// RVA: 0xD0F850
void __fastcall hkpTransformShape::setTransform(hkpTransformShape *this, hkTransformf *transform)
{
  this->m_transform = *transform;
  hkQuaternionf::set(&this->m_rotation, &this->m_transform.m_rotation);
}

// File Line: 38
// RVA: 0xD0F7E0
void __fastcall hkpTransformShape::hkpTransformShape(
        hkpTransformShape *this,
        hkpShape *childShape,
        hkTransformf *transform)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1038;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpTransformShape::`vftable;
  this->m_childShape.m_childShape = childShape;
  this->m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  hkReferencedObject::addReference(childShape);
  hkpTransformShape::setTransform(this, transform);
}

// File Line: 46
// RVA: 0xD0F890
void __fastcall hkpTransformShape::getAabb(
        hkpTransformShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  __int64 v6; // r8
  hkTransformf v7; // [rsp+20h] [rbp-58h] BYREF

  hkTransformf::setMul(&v7, localToWorld, &this->m_transform);
  ((void (__fastcall *)(hkpShape *, hkTransformf *, __int64, hkAabb *))this->m_childShape.m_childShape->vfptr[2].__vecDelDtor)(
    this->m_childShape.m_childShape,
    &v7,
    v6,
    out);
}

// File Line: 54
// RVA: 0xD0FCE0
float __fastcall hkpTransformShape::getMaximumProjection(hkpTransformShape *this, hkVector4f *direction)
{
  hkVector4f v2; // xmm4
  hkVector4f v5; // xmm1
  __m128 v6; // xmm5
  __m128 v7; // xmm1
  hkpShape *m_childShape; // rcx
  __m128 v9; // xmm2
  double v10; // xmm0_8
  __m128 v11; // xmm2
  __m128 v13; // [rsp+20h] [rbp-18h] BYREF

  v2.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v5.m_quad = (__m128)this->m_transform.m_rotation.m_col0;
  v6 = _mm_unpackhi_ps(v5.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v7 = _mm_unpacklo_ps(v5.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  m_childShape = this->m_childShape.m_childShape;
  v9 = _mm_movelh_ps(v7, v2.m_quad);
  v13 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(direction->m_quad, direction->m_quad, 85),
              _mm_shuffle_ps(_mm_movehl_ps(v9, v7), v2.m_quad, 212)),
            _mm_mul_ps(_mm_shuffle_ps(direction->m_quad, direction->m_quad, 0), v9)),
          _mm_mul_ps(_mm_shuffle_ps(direction->m_quad, direction->m_quad, 170), _mm_shuffle_ps(v6, v2.m_quad, 228)));
  v10 = ((double (__fastcall *)(hkpShape *, __m128 *))m_childShape->vfptr[7].__first_virtual_table_function__)(
          m_childShape,
          &v13);
  v11 = _mm_mul_ps(this->m_transform.m_translation.m_quad, direction->m_quad);
  return (float)((float)(_mm_shuffle_ps(v11, v11, 85).m128_f32[0] + _mm_shuffle_ps(v11, v11, 0).m128_f32[0])
               + _mm_shuffle_ps(v11, v11, 170).m128_f32[0])
       + *(float *)&v10;
}

// File Line: 68
// RVA: 0xD0F8F0
hkBool *__fastcall hkpTransformShape::castRay(
        hkpTransformShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkVector4f v13; // xmm3
  hkVector4f v14; // xmm4
  hkVector4f v15; // xmm0
  hkVector4f v16; // xmm5
  __m128 v17; // xmm5
  __int128 v18; // xmm1
  __int128 v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm5
  hkVector4f v26; // xmm4
  __m128 v27; // xmm1
  __m128 v28; // xmm5
  __m128 v29; // xmm1
  __m128 v30; // xmm4
  hkpShape *m_childShape; // rcx
  __m128 v32; // xmm0
  __int64 m_shapeKeyIndex; // rax
  _QWORD *v34; // r8
  _QWORD *v35; // rcx
  unsigned __int64 v36; // rax
  _QWORD *v37; // rcx
  __m128 m_quad; // [rsp+20h] [rbp-48h] BYREF
  hkVector4f v40; // [rsp+30h] [rbp-38h]
  __int128 v41; // [rsp+40h] [rbp-28h]
  __int128 v42; // [rsp+50h] [rbp-18h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcTransform";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  v13.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v14.m_quad = (__m128)this->m_transform.m_rotation.m_col0;
  v15.m_quad = (__m128)input->m_from;
  v16.m_quad = (__m128)input->m_from;
  v40.m_quad = (__m128)input->m_to;
  v17 = _mm_sub_ps(v16.m_quad, this->m_transform.m_translation.m_quad);
  v18 = *(_OWORD *)&input->m_collidable;
  m_quad = v15.m_quad;
  v19 = *(_OWORD *)&input->m_filterInfo;
  v42 = v18;
  v41 = v19;
  v20 = _mm_unpacklo_ps(v14.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v21 = _mm_movelh_ps(v20, v13.m_quad);
  v22 = _mm_movehl_ps(v21, v20);
  v23 = _mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), v21);
  v24 = _mm_shuffle_ps(v17, v17, 85);
  v25 = _mm_mul_ps(
          _mm_shuffle_ps(v17, v17, 170),
          _mm_shuffle_ps(_mm_unpackhi_ps(v14.m_quad, this->m_transform.m_rotation.m_col1.m_quad), v13.m_quad, 228));
  v26.m_quad = (__m128)this->m_transform.m_rotation.m_col0;
  v27 = _mm_add_ps(_mm_add_ps(v23, _mm_mul_ps(v24, _mm_shuffle_ps(v22, v13.m_quad, 212))), v25);
  v28 = _mm_sub_ps(input->m_to.m_quad, this->m_transform.m_translation.m_quad);
  m_quad = v27;
  v29 = _mm_unpacklo_ps(v26.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v30 = _mm_shuffle_ps(_mm_unpackhi_ps(v26.m_quad, this->m_transform.m_rotation.m_col1.m_quad), v13.m_quad, 228);
  ++results->m_shapeKeyIndex;
  m_childShape = this->m_childShape.m_childShape;
  v32 = _mm_movelh_ps(v29, v13.m_quad);
  v40.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), v32),
                   _mm_mul_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(_mm_movehl_ps(v32, v29), v13.m_quad, 212))),
                 _mm_mul_ps(_mm_shuffle_ps(v28, v28, 170), v30));
  ((void (__fastcall *)(hkpShape *, hkBool *, __m128 *, hkpShapeRayCastOutput *))m_childShape->vfptr[2].__first_virtual_table_function__)(
    m_childShape,
    result,
    &m_quad,
    results);
  --results->m_shapeKeyIndex;
  if ( result->m_bool )
  {
    m_shapeKeyIndex = results->m_shapeKeyIndex;
    results->m_normal.m_quad = _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(results->m_normal.m_quad, results->m_normal.m_quad, 85),
                                     this->m_transform.m_rotation.m_col1.m_quad),
                                   _mm_mul_ps(
                                     _mm_shuffle_ps(results->m_normal.m_quad, results->m_normal.m_quad, 0),
                                     this->m_transform.m_rotation.m_col0.m_quad)),
                                 _mm_mul_ps(
                                   _mm_shuffle_ps(results->m_normal.m_quad, results->m_normal.m_quad, 170),
                                   this->m_transform.m_rotation.m_col2.m_quad));
    results->m_shapeKeys[m_shapeKeyIndex] = 0;
  }
  v34 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v35 = (_QWORD *)v34[1];
  if ( (unsigned __int64)v35 < v34[3] )
  {
    *v35 = "Et";
    v36 = __rdtsc();
    v37 = v35 + 2;
    *((_DWORD *)v37 - 2) = v36;
    v34[1] = v37;
  }
  return result;
}

// File Line: 91
// RVA: 0xD0FAD0
void __fastcall hkpTransformShape::castRayWithCollector(
        hkpTransformShape *this,
        hkpShapeRayCastInput *input,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r10
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkVector4f v13; // xmm3
  hkVector4f v14; // xmm4
  hkTransformf *m_motion; // rdx
  hkVector4f v16; // xmm0
  hkVector4f v17; // xmm5
  __m128 v18; // xmm5
  __int128 v19; // xmm1
  __int128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm5
  hkVector4f v26; // xmm4
  __m128 v27; // xmm1
  __m128 v28; // xmm5
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  hkpShape *m_childShape; // rcx
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  _QWORD *v35; // rcx
  hkpShape *v36; // [rsp+20h] [rbp-A8h] BYREF
  int v37; // [rsp+28h] [rbp-A0h]
  hkTransformf *v38; // [rsp+30h] [rbp-98h]
  hkpCdBody *v39; // [rsp+38h] [rbp-90h]
  __m128 m_quad; // [rsp+40h] [rbp-88h] BYREF
  hkVector4f v41; // [rsp+50h] [rbp-78h]
  __int128 v42; // [rsp+60h] [rbp-68h]
  __int128 v43; // [rsp+70h] [rbp-58h]
  hkTransformf v44; // [rsp+80h] [rbp-48h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcTransform";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  v13.m_quad = (__m128)this->m_transform.m_rotation.m_col2;
  v14.m_quad = (__m128)this->m_transform.m_rotation.m_col0;
  m_motion = (hkTransformf *)cdBody->m_motion;
  v16.m_quad = (__m128)input->m_from;
  v17.m_quad = (__m128)input->m_from;
  v41.m_quad = (__m128)input->m_to;
  v18 = _mm_sub_ps(v17.m_quad, this->m_transform.m_translation.m_quad);
  v19 = *(_OWORD *)&input->m_collidable;
  m_quad = v16.m_quad;
  v20 = *(_OWORD *)&input->m_filterInfo;
  v43 = v19;
  v42 = v20;
  v21 = _mm_unpacklo_ps(v14.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v22 = _mm_movelh_ps(v21, v13.m_quad);
  v23 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(_mm_movehl_ps(v22, v21), v13.m_quad, 212));
  v24 = _mm_shuffle_ps(v18, v18, 0);
  v25 = _mm_mul_ps(
          _mm_shuffle_ps(v18, v18, 170),
          _mm_shuffle_ps(_mm_unpackhi_ps(v14.m_quad, this->m_transform.m_rotation.m_col1.m_quad), v13.m_quad, 228));
  v26.m_quad = (__m128)this->m_transform.m_rotation.m_col0;
  v27 = _mm_add_ps(_mm_add_ps(v23, _mm_mul_ps(v24, v22)), v25);
  v28 = _mm_sub_ps(input->m_to.m_quad, this->m_transform.m_translation.m_quad);
  m_quad = v27;
  v29 = _mm_unpacklo_ps(v26.m_quad, this->m_transform.m_rotation.m_col1.m_quad);
  v30 = _mm_movelh_ps(v29, v13.m_quad);
  v41.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v28, v28, 85), _mm_shuffle_ps(_mm_movehl_ps(v30, v29), v13.m_quad, 212)),
                   _mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), v30)),
                 _mm_mul_ps(
                   _mm_shuffle_ps(v28, v28, 170),
                   _mm_shuffle_ps(
                     _mm_unpackhi_ps(v26.m_quad, this->m_transform.m_rotation.m_col1.m_quad),
                     v13.m_quad,
                     228)));
  hkTransformf::setMul(&v44, m_motion, &this->m_transform);
  m_childShape = this->m_childShape.m_childShape;
  v39 = cdBody;
  v37 = 0;
  v36 = m_childShape;
  v38 = &v44;
  ((void (__fastcall *)(hkpShape *, __m128 *, hkpShape **, hkpRayHitCollector *))m_childShape->vfptr[3].__vecDelDtor)(
    m_childShape,
    &m_quad,
    &v36,
    collector);
  v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v33 = (_QWORD *)v32[1];
  if ( (unsigned __int64)v33 < v32[3] )
  {
    *v33 = "Et";
    v34 = __rdtsc();
    v35 = v33 + 2;
    *((_DWORD *)v35 - 2) = v34;
    v32[1] = v35;
  }
}

// File Line: 111
// RVA: 0xD0FD90
hkpSingleShapeContainer *__fastcall hkpTransformShape::getContainer(hkpTransformShape *this)
{
  return &this->m_childShape;
}

// File Line: 116
// RVA: 0xD0FDA0
__int64 __fastcall hkpTransformShape::calcSizeForSpu(
        hkpTransformShape *this,
        hkpShape::CalcSizeForSpuInput *input,
        int spuBufferSizeLeft)
{
  int v4; // edi
  int v5; // eax

  v4 = spuBufferSizeLeft - 144;
  v5 = ((__int64 (__fastcall *)(hkpShape *, hkpShape::CalcSizeForSpuInput *, _QWORD))this->m_childShape.m_childShape->vfptr[8].__vecDelDtor)(
         this->m_childShape.m_childShape,
         input,
         (unsigned int)(spuBufferSizeLeft - 144));
  if ( v5 < 0 || v5 > v4 )
    return 0xFFFFFFFFi64;
  if ( this->m_childShape.m_childShape == &this[1] )
  {
    this->m_childShapeSize = 0;
    return (unsigned int)v5 + 144i64;
  }
  else
  {
    this->m_childShapeSize = v5;
    return 144i64;
  }
}

