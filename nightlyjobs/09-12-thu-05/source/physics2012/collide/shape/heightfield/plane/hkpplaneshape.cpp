// File Line: 21
// RVA: 0xD16D60
void __fastcall hkpPlaneShape::hkpPlaneShape(hkpPlaneShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpShape::hkpShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpPlaneShape::`vftable;
  this->m_type.m_storage = 31;
}

// File Line: 29
// RVA: 0xD16C90
void __fastcall hkpPlaneShape::hkpPlaneShape(hkpPlaneShape *this, hkVector4f *plane, hkAabb *aabb)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1055;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPlaneShape::`vftable;
  this->m_plane = (hkVector4f)plane->m_quad;
  this->m_aabbCenter.m_quad = _mm_mul_ps(_mm_add_ps(aabb->m_max.m_quad, aabb->m_min.m_quad), (__m128)xmmword_141A711B0);
  this->m_aabbHalfExtents.m_quad = _mm_mul_ps(
                                     _mm_sub_ps(aabb->m_max.m_quad, aabb->m_min.m_quad),
                                     (__m128)xmmword_141A711B0);
}

// File Line: 37
// RVA: 0xD16CF0
void __fastcall hkpPlaneShape::hkpPlaneShape(
        hkpPlaneShape *this,
        hkVector4f *direction,
        hkVector4f *center,
        hkVector4f *halfExtents)
{
  __m128 v4; // xmm1

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1055;
  this->m_userData = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpPlaneShape::`vftable;
  v4 = _mm_mul_ps(center->m_quad, direction->m_quad);
  this->m_plane.m_quad = _mm_shuffle_ps(
                           direction->m_quad,
                           _mm_unpackhi_ps(
                             direction->m_quad,
                             _mm_sub_ps(
                               (__m128)0i64,
                               _mm_add_ps(
                                 _mm_add_ps(_mm_shuffle_ps(v4, v4, 85), _mm_shuffle_ps(v4, v4, 0)),
                                 _mm_shuffle_ps(v4, v4, 170)))),
                           196);
  this->m_aabbCenter = (hkVector4f)center->m_quad;
  this->m_aabbHalfExtents = (hkVector4f)halfExtents->m_quad;
}

// File Line: 44
// RVA: 0xD16D90
void __fastcall hkpPlaneShape::getAabb(hkpPlaneShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  hkVector4f v4; // xmm1
  __m128 v5; // xmm6
  hkVector4f v6; // xmm1
  __m128 v7; // xmm2

  v4.m_quad = (__m128)this->m_aabbHalfExtents;
  v5 = _mm_add_ps(
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(
                                  _mm_shuffle_ps(v4.m_quad, v4.m_quad, 0),
                                  localToWorld->m_rotation.m_col0.m_quad),
                       1u),
                     1u),
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(
                                  _mm_shuffle_ps(v4.m_quad, v4.m_quad, 85),
                                  localToWorld->m_rotation.m_col1.m_quad),
                       1u),
                     1u)),
         _mm_add_ps(
           (__m128)_mm_srli_epi32(
                     _mm_slli_epi32(
                       (__m128i)_mm_mul_ps(
                                  _mm_shuffle_ps(v4.m_quad, v4.m_quad, 170),
                                  localToWorld->m_rotation.m_col2.m_quad),
                       1u),
                     1u),
           _mm_shuffle_ps((__m128)LODWORD(tolerance), (__m128)LODWORD(tolerance), 0)));
  v6.m_quad = (__m128)this->m_aabbCenter;
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 0), localToWorld->m_rotation.m_col0.m_quad),
             _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 85), localToWorld->m_rotation.m_col1.m_quad)),
           _mm_mul_ps(_mm_shuffle_ps(v6.m_quad, v6.m_quad, 170), localToWorld->m_rotation.m_col2.m_quad)),
         localToWorld->m_translation.m_quad);
  out->m_max.m_quad = _mm_add_ps(v7, v5);
  out->m_min.m_quad = _mm_add_ps(
                        _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v5),
                        v7);
}

// File Line: 50
// RVA: 0xD16E60
hkBool *__fastcall hkpPlaneShape::castRay(
        hkpPlaneShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkVector4f v13; // xmm2
  hkVector4f v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __m128 v18; // xmm1
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm0
  __m128 v25; // xmm2
  __int64 m_shapeKeyIndex; // rax
  _QWORD *v27; // r8
  unsigned __int64 v28; // rcx
  unsigned __int64 v29; // rax

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcPlane";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  v13.m_quad = (__m128)this->m_plane;
  v14.m_quad = (__m128)input->m_to;
  v15 = _mm_mul_ps(v13.m_quad, input->m_from.m_quad);
  v16 = _mm_shuffle_ps(v15, _mm_unpackhi_ps(v15, v13.m_quad), 196);
  v17 = _mm_add_ps(_mm_shuffle_ps(v16, v16, 78), v16);
  v18 = _mm_mul_ps(v13.m_quad, v14.m_quad);
  v19 = _mm_add_ps(_mm_shuffle_ps(v17, v17, 177), v17);
  v20 = _mm_shuffle_ps(v18, _mm_unpackhi_ps(v18, v13.m_quad), 196);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 78), v20);
  v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 177), v21);
  if ( v19.m128_f32[0] >= 0.0
    && v22.m128_f32[0] < 0.0
    && (v23 = _mm_sub_ps(v19, v22),
        v24 = _mm_rcp_ps(v23),
        v25 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v24)), v24), v19),
        v25.m128_f32[0] < _mm_shuffle_ps(
                            (__m128)LODWORD(results->m_hitFraction),
                            (__m128)LODWORD(results->m_hitFraction),
                            0).m128_f32[0])
    && (_mm_movemask_ps(
          _mm_cmple_ps(
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32(
                        (__m128i)_mm_sub_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(_mm_sub_ps(v14.m_quad, input->m_from.m_quad), v25),
                                     input->m_from.m_quad),
                                   this->m_aabbCenter.m_quad),
                        1u),
                      1u),
            this->m_aabbHalfExtents.m_quad)) & 7) == 7 )
  {
    LODWORD(results->m_hitFraction) = v25.m128_i32[0];
    m_shapeKeyIndex = results->m_shapeKeyIndex;
    results->m_normal = this->m_plane;
    result->m_bool = 1;
    results->m_shapeKeys[m_shapeKeyIndex] = -1;
  }
  else
  {
    result->m_bool = 0;
  }
  v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v28 = v27[1];
  if ( v28 < v27[3] )
  {
    *(_QWORD *)v28 = "Et";
    v29 = __rdtsc();
    *(_DWORD *)(v28 + 8) = v29;
    v27[1] = v28 + 16;
  }
  return result;
}

// File Line: 80
// RVA: 0xD16FE0
void __fastcall hkpPlaneShape::castRayWithCollector(
        hkpPlaneShape *this,
        hkpShapeRayCastInput *inputLocal,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  hkBaseObjectVtbl *vfptr; // rax
  __m128 *m_motion; // rax
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  hkpRayHitCollectorVtbl *v11; // rax
  __m128 v12; // [rsp+20h] [rbp-58h] BYREF
  float m_earlyOutHitFraction; // [rsp+30h] [rbp-48h]
  int v14; // [rsp+34h] [rbp-44h]
  int v15; // [rsp+40h] [rbp-38h]
  int v16; // [rsp+60h] [rbp-18h]
  char v17; // [rsp+80h] [rbp+8h] BYREF

  vfptr = this->vfptr;
  m_earlyOutHitFraction = collector->m_earlyOutHitFraction;
  v14 = -1;
  v16 = 0;
  v15 = -1;
  if ( *(_BYTE *)((__int64 (__fastcall *)(hkpPlaneShape *, char *, hkpShapeRayCastInput *, __m128 *))vfptr[2].__first_virtual_table_function__)(
                   this,
                   &v17,
                   inputLocal,
                   &v12) )
  {
    m_motion = (__m128 *)cdBody->m_motion;
    v8 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), m_motion[1]);
    v9 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), *m_motion);
    v10 = _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), m_motion[2]);
    v11 = collector->vfptr;
    v12 = _mm_add_ps(_mm_add_ps(v8, v9), v10);
    v11->addRayHit(collector, cdBody, (hkpShapeRayCastCollectorOutput *)&v12);
  }
}

// File Line: 93
// RVA: 0xD17090
void __fastcall hkpPlaneShape::castSphere(
        hkpPlaneShape *this,
        hkpHeightFieldShape::hkpSphereCastInput *inputLocal,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  hkVector4f v4; // xmm3
  __m128 v5; // xmm2
  hkVector4f v6; // xmm6
  __m128 v7; // xmm1
  __m128 v8; // xmm1
  __m128 v9; // xmm0
  __m128 v10; // xmm1
  __m128 v11; // xmm4
  __m128 v12; // xmm1
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm0
  __m128 v17; // xmm4
  __m128 m_quad; // [rsp+20h] [rbp-78h] BYREF
  int v19; // [rsp+30h] [rbp-68h]
  int v20; // [rsp+34h] [rbp-64h]
  int v21; // [rsp+40h] [rbp-58h]
  int v22; // [rsp+60h] [rbp-38h]

  v4.m_quad = (__m128)inputLocal->m_to;
  v5 = _mm_shuffle_ps((__m128)LODWORD(inputLocal->m_radius), (__m128)LODWORD(inputLocal->m_radius), 0);
  v6.m_quad = (__m128)this->m_plane;
  v7 = _mm_mul_ps(v6.m_quad, inputLocal->m_from.m_quad);
  v8 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, v6.m_quad), 196);
  v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  v10 = _mm_mul_ps(v6.m_quad, v4.m_quad);
  v11 = _mm_sub_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 177), v9), v5);
  v12 = _mm_shuffle_ps(v10, _mm_unpackhi_ps(v10, v6.m_quad), 196);
  v13 = _mm_add_ps(_mm_shuffle_ps(v12, v12, 78), v12);
  v14 = _mm_sub_ps(_mm_add_ps(_mm_shuffle_ps(v13, v13, 177), v13), v5);
  if ( v14.m128_f32[0] < 0.0 )
  {
    v15 = _mm_sub_ps(v11, v14);
    if ( v15.m128_f32[0] >= _mm_shuffle_ps(
                              (__m128)LODWORD(inputLocal->m_maxExtraPenetration),
                              (__m128)LODWORD(inputLocal->m_maxExtraPenetration),
                              0).m128_f32[0] )
    {
      v16 = _mm_rcp_ps(v15);
      v17 = _mm_andnot_ps(
              _mm_cmple_ps(v11, (__m128)0i64),
              _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v15, v16)), v16), v11));
      if ( v17.m128_f32[0] < _mm_shuffle_ps(
                               (__m128)LODWORD(collector->m_earlyOutHitFraction),
                               (__m128)LODWORD(collector->m_earlyOutHitFraction),
                               0).m128_f32[0]
        && (_mm_movemask_ps(
              _mm_cmple_ps(
                (__m128)_mm_srli_epi32(
                          _mm_slli_epi32(
                            (__m128i)_mm_sub_ps(
                                       _mm_add_ps(
                                         _mm_mul_ps(_mm_sub_ps(v4.m_quad, inputLocal->m_from.m_quad), v17),
                                         inputLocal->m_from.m_quad),
                                       this->m_aabbCenter.m_quad),
                            1u),
                          1u),
                this->m_aabbHalfExtents.m_quad)) & 7) == 7 )
      {
        v20 = -1;
        v22 = 0;
        m_quad = v6.m_quad;
        v19 = v17.m128_i32[0];
        v21 = -1;
        collector->vfptr->addRayHit(collector, cdBody, (hkpShapeRayCastCollectorOutput *)&m_quad);
      }
    }
  }
}

// File Line: 130
// RVA: 0xD171F0
void __fastcall hkpPlaneShape::collideSpheres(
        hkpPlaneShape *this,
        hkpHeightFieldShape::CollideSpheresInput *input,
        hkVector4f *outputArray)
{
  hkSphere *m_spheres; // r9
  int i; // eax
  hkVector4f v5; // xmm3
  __m128 m_quad; // xmm2
  __m128 v7; // xmm1
  __m128 v8; // xmm1
  __m128 v9; // xmm0

  m_spheres = input->m_spheres;
  for ( i = input->m_numSpheres - 1;
        i >= 0;
        outputArray[-1].m_quad = _mm_shuffle_ps(
                                   v5.m_quad,
                                   _mm_unpackhi_ps(
                                     v5.m_quad,
                                     _mm_sub_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v9, v9, 177), v9),
                                       _mm_shuffle_ps(m_quad, m_quad, 255))),
                                   196) )
  {
    v5.m_quad = (__m128)this->m_plane;
    m_quad = m_spheres->m_pos.m_quad;
    ++outputArray;
    ++m_spheres;
    --i;
    v7 = _mm_mul_ps(v5.m_quad, m_quad);
    v8 = _mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, v5.m_quad), 196);
    v9 = _mm_add_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  }
}

