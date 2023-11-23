// File Line: 27
// RVA: 0xC9BA60
void __fastcall scaleMassProperties(hkSimdFloat32 *scale, hkMassProperties *massProperties)
{
  float v3; // xmm6_4

  v3 = _mm_shuffle_ps((__m128)LODWORD(massProperties->m_mass), (__m128)LODWORD(massProperties->m_mass), 0).m128_f32[0]
     * scale->m_real.m128_f32[0];
  hkMatrix3f::mul(&massProperties->m_inertiaTensor, scale);
  massProperties->m_mass = v3;
}

// File Line: 38
// RVA: 0xC98BB0
hkResult *__fastcall hkInertiaTensorComputer::computeSphereVolumeMassProperties(
        hkResult *result,
        float radius,
        float mass,
        hkMassProperties *a4)
{
  __m128 v4; // xmm3
  __m128 v5; // xmm4
  __m128 v6; // xmm4
  hkResult *v7; // rax
  __m128 v8; // xmm3
  __m128 v9; // xmm0

  v5.m128_f32[0] = mass;
  v6 = _mm_shuffle_ps(v5, v5, 0);
  if ( v6.m128_f32[0] <= 0.0 || (v4.m128_f32[0] = radius, v8 = _mm_shuffle_ps(v4, v4, 0), v8.m128_f32[0] <= 0.0) )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    result->m_enum = HK_SUCCESS;
    v7 = result;
    v9 = _mm_mul_ps(
           _mm_mul_ps(_mm_mul_ps(v8, v6), v8),
           _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_40000001), (__m128)LODWORD(FLOAT_0_40000001), 0));
    a4->m_inertiaTensor.m_col0.m_quad = _mm_mul_ps(v9, transform.m_quad);
    a4->m_inertiaTensor.m_col1.m_quad = _mm_mul_ps(v9, direction.m_quad);
    a4->m_inertiaTensor.m_col2.m_quad = _mm_mul_ps(v9, stru_141A71280.m_quad);
    a4->m_centerOfMass = 0i64;
    a4->m_volume = (float)((float)(v8.m128_f32[0] * 4.1887903) * v8.m128_f32[0]) * v8.m128_f32[0];
    a4->m_mass = mass;
  }
  return v7;
}

// File Line: 67
// RVA: 0xC99750
// local variable allocation has failed, the output may be wrong!
hkResult *__fastcall hkInertiaTensorComputer::computeSphereSurfaceMassProperties(
        hkResult *result,
        double radius,
        float mass,
        float surfaceThickness,
        hkMassProperties *resulta)
{
  __m128 v5; // xmm0
  __m128 v6; // xmm0
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm8
  __m128 v12; // xmm9
  __m128 v13; // xmm7
  hkVector4f v14; // xmm0
  hkVector4f v15; // xmm1
  __m128 v16; // xmm0
  float v17; // xmm6_4
  hkResult v18; // [rsp+20h] [rbp-E0h] BYREF
  hkSimdFloat32 scale; // [rsp+30h] [rbp-D0h] BYREF
  hkMassProperties v20; // [rsp+40h] [rbp-C0h] BYREF
  hkMassProperties v21; // [rsp+90h] [rbp-70h] BYREF

  v5.m128_f32[0] = mass;
  v6 = _mm_shuffle_ps(v5, v5, 0);
  scale.m_real = v6;
  if ( v6.m128_f32[0] <= 0.0
    || (v6.m128_f32[0] = surfaceThickness,
        v9 = _mm_shuffle_ps(*(__m128 *)&radius, *(__m128 *)&radius, 0),
        v10 = _mm_shuffle_ps(v6, v6, 0),
        v9.m128_f32[0] <= v10.m128_f32[0])
    || v10.m128_f32[0] <= 0.0 )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    *(_QWORD *)&v20.m_volume = 0i64;
    *(_QWORD *)&v21.m_volume = 0i64;
    v11 = _mm_sub_ps(v9, v10);
    memset(&v20.m_centerOfMass, 0, 64);
    v12 = _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(v9, (__m128)xmmword_141A713E0), v9), v9);
    memset(&v21.m_centerOfMass, 0, 64);
    v13 = _mm_mul_ps(_mm_mul_ps(_mm_mul_ps((__m128)xmmword_141A713E0, v11), v11), v11);
    if ( hkInertiaTensorComputer::computeSphereVolumeMassProperties(&v18, v9.m128_f32[0], v12.m128_f32[0], &v20)->m_enum == HK_FAILURE
      || hkInertiaTensorComputer::computeSphereVolumeMassProperties(&v18, v11.m128_f32[0], v13.m128_f32[0], &v21)->m_enum == HK_FAILURE )
    {
      result->m_enum = HK_FAILURE;
    }
    else
    {
      v14.m_quad = (__m128)v20.m_inertiaTensor.m_col0;
      v15.m_quad = (__m128)v20.m_inertiaTensor.m_col1;
      resulta->m_centerOfMass = 0i64;
      resulta->m_inertiaTensor.m_col0 = (hkVector4f)v14.m_quad;
      resulta->m_inertiaTensor.m_col2 = v20.m_inertiaTensor.m_col2;
      resulta->m_inertiaTensor.m_col1 = (hkVector4f)v15.m_quad;
      hkMatrix3f::sub(&resulta->m_inertiaTensor, &v21.m_inertiaTensor);
      v15.m_quad.m128_f32[0] = v20.m_volume - v21.m_volume;
      resulta->m_mass = v20.m_mass - v21.m_mass;
      LODWORD(resulta->m_volume) = v15.m_quad.m128_i32[0];
      v16 = _mm_div_ps(scale.m_real, _mm_sub_ps(v12, v13));
      v17 = _mm_shuffle_ps((__m128)LODWORD(resulta->m_mass), (__m128)LODWORD(resulta->m_mass), 0).m128_f32[0]
          * v16.m128_f32[0];
      scale.m_real = v16;
      hkMatrix3f::mul(&resulta->m_inertiaTensor, &scale);
      resulta->m_mass = v17;
      result->m_enum = HK_SUCCESS;
    }
    return result;
  }
}

// File Line: 126
// RVA: 0xC99940
hkResult *__fastcall hkInertiaTensorComputer::computeBoxSurfaceMassProperties(
        hkResult *result,
        hkVector4f *halfExtents,
        float mass,
        float surfaceThickness,
        hkMassProperties *resulta)
{
  __m128 v5; // xmm0
  __m128 v6; // xmm1
  __m128 m_quad; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm8
  __m128 v12; // xmm7
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm1
  __m128 v15; // xmm0
  float v16; // xmm6_4
  hkResult v17; // [rsp+20h] [rbp-E0h] BYREF
  hkSimdFloat32 scale; // [rsp+30h] [rbp-D0h] BYREF
  hkMassProperties v19; // [rsp+40h] [rbp-C0h] BYREF
  hkVector4f halfExtentsa; // [rsp+90h] [rbp-70h] BYREF
  hkMassProperties v21; // [rsp+A0h] [rbp-60h] BYREF

  v5.m128_f32[0] = mass;
  scale.m_real = _mm_shuffle_ps(v5, v5, 0);
  if ( scale.m_real.m128_f32[0] <= 0.0
    || (v6.m128_f32[0] = surfaceThickness,
        m_quad = halfExtents->m_quad,
        v10 = _mm_shuffle_ps(v6, v6, 0),
        (_mm_movemask_ps(_mm_cmplt_ps(v10, halfExtents->m_quad)) & 7) != 7)
    || _mm_movemask_ps(_mm_cmple_ps(v10, (__m128)0i64)) )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    *(_QWORD *)&v19.m_volume = 0i64;
    *(_QWORD *)&v21.m_volume = 0i64;
    memset(&v19.m_centerOfMass, 0, 64);
    halfExtentsa.m_quad = _mm_sub_ps(m_quad, v10);
    memset(&v21.m_centerOfMass, 0, 64);
    v11 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), _mm_shuffle_ps(m_quad, m_quad, 0)),
              _mm_shuffle_ps(m_quad, m_quad, 170)),
            (__m128)xmmword_141A71130);
    v12 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(halfExtentsa.m_quad, halfExtentsa.m_quad, 85),
                _mm_shuffle_ps(halfExtentsa.m_quad, halfExtentsa.m_quad, 0)),
              _mm_shuffle_ps(halfExtentsa.m_quad, halfExtentsa.m_quad, 170)),
            (__m128)xmmword_141A71130);
    if ( hkInertiaTensorComputer::computeBoxVolumeMassProperties(&v17, halfExtents, v11.m128_f32[0], &v19)->m_enum == HK_FAILURE
      || hkInertiaTensorComputer::computeBoxVolumeMassProperties(&v17, &halfExtentsa, v12.m128_f32[0], &v21)->m_enum == HK_FAILURE )
    {
      result->m_enum = HK_FAILURE;
    }
    else
    {
      v13.m_quad = (__m128)v19.m_inertiaTensor.m_col0;
      v14.m_quad = (__m128)v19.m_inertiaTensor.m_col1;
      resulta->m_centerOfMass = 0i64;
      resulta->m_inertiaTensor.m_col0 = (hkVector4f)v13.m_quad;
      resulta->m_inertiaTensor.m_col2 = v19.m_inertiaTensor.m_col2;
      resulta->m_inertiaTensor.m_col1 = (hkVector4f)v14.m_quad;
      hkMatrix3f::sub(&resulta->m_inertiaTensor, &v21.m_inertiaTensor);
      v14.m_quad.m128_f32[0] = v19.m_volume - v21.m_volume;
      resulta->m_mass = v19.m_mass - v21.m_mass;
      LODWORD(resulta->m_volume) = v14.m_quad.m128_i32[0];
      v15 = _mm_div_ps(scale.m_real, _mm_sub_ps(v11, v12));
      v16 = _mm_shuffle_ps((__m128)LODWORD(resulta->m_mass), (__m128)LODWORD(resulta->m_mass), 0).m128_f32[0]
          * v15.m128_f32[0];
      scale.m_real = v15;
      hkMatrix3f::mul(&resulta->m_inertiaTensor, &scale);
      resulta->m_mass = v16;
      result->m_enum = HK_SUCCESS;
    }
    return result;
  }
}

// File Line: 184
// RVA: 0xC99B60
hkResult *__fastcall hkInertiaTensorComputer::computeTriangleSurfaceMassProperties(
        hkResult *result,
        hkVector4f *v0,
        hkVector4f *v1,
        hkVector4f *v2,
        float mass,
        float surfaceThickness,
        hkMassProperties *resulta)
{
  __m128 v7; // xmm4
  __m128 v12; // xmm4
  hkResult *v13; // rax
  __m128 v14; // xmm10
  __m128 m_quad; // xmm12
  float v16; // xmm5_4
  __m128 v17; // xmm13
  __m128 v18; // xmm14
  __m128 v19; // xmm7
  __m128 v20; // xmm1
  __m128 v21; // xmm7
  __m128 v22; // xmm7
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  float v25; // xmm9_4
  __m128 v26; // xmm6
  __m128 v27; // xmm3
  hkVector4f v28; // xmm7
  __m128 v29; // xmm2
  __m128 v30; // xmm5
  __m128 v31; // xmm4
  __m128 v32; // xmm1
  __m128 v33; // xmm4
  __m128 v34; // xmm5
  __m128 v35; // xmm0
  __m128 v36; // xmm3
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __m128 v39; // xmm6
  __m128 v40; // xmm2
  __m128 v41; // xmm7
  __m128 v42; // xmm2
  __m128 v43; // xmm8
  int v44; // r9d
  _DWORD *v45; // rax
  _DWORD *v46; // rax
  _DWORD *v47; // rax
  _DWORD *v48; // rax
  unsigned __int64 v49; // rax
  _DWORD *v50; // rax
  _DWORD *v51; // rax
  _DWORD *v52; // rax
  hkResult v53; // [rsp+30h] [rbp-D0h] BYREF
  hkMatrix3f inertia; // [rsp+40h] [rbp-C0h] BYREF
  hkMassProperties v55; // [rsp+70h] [rbp-90h] BYREF
  hkVector4f shift; // [rsp+C0h] [rbp-40h] BYREF
  hkSimdFloat32 v57; // [rsp+D0h] [rbp-30h] BYREF

  v7.m128_f32[0] = mass;
  v12 = _mm_shuffle_ps(v7, v7, 0);
  v57.m_real = v12;
  if ( v12.m128_f32[0] > 0.0 )
  {
    v14 = _mm_shuffle_ps((__m128)LODWORD(surfaceThickness), (__m128)LODWORD(surfaceThickness), 0);
    if ( v14.m128_f32[0] >= 0.0 )
    {
      v53.m_enum = LODWORD(FLOAT_0_0000099999997);
      m_quad = v1->m_quad;
      v16 = _mm_shuffle_ps((__m128)(unsigned int)v53.m_enum, (__m128)(unsigned int)v53.m_enum, 0).m128_f32[0];
      v17 = v0->m_quad;
      v18 = v2->m_quad;
      v19 = _mm_sub_ps(v0->m_quad, v1->m_quad);
      v20 = _mm_sub_ps(v2->m_quad, v1->m_quad);
      v21 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v20), _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v19));
      v22 = _mm_shuffle_ps(v21, v21, 201);
      v23 = _mm_mul_ps(v22, v22);
      v24 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
              _mm_shuffle_ps(v23, v23, 170));
      LODWORD(v25) = _mm_andnot_ps(_mm_cmple_ps(v24, (__m128)0i64), _mm_sqrt_ps(v24)).m128_u32[0];
      if ( v14.m128_f32[0] >= v16 )
      {
        if ( v25 >= v16 )
        {
          memset(&v55.m_centerOfMass, 0, 64);
          *(_QWORD *)&v55.m_volume = 0i64;
          v38 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                  _mm_shuffle_ps(v23, v23, 170));
          v39 = _mm_mul_ps(v14, (__m128)xmmword_141A711B0);
          inertia.m_col0.m_quad.m128_i32[2] = 0x1FFFF;
          inertia.m_col0.m_quad.m128_u64[0] = (unsigned __int64)&hkGeometry::`vftable;
          inertia.m_col1.m_quad.m128_u64[0] = 0i64;
          v40 = _mm_rsqrt_ps(v38);
          inertia.m_col1.m_quad.m128_u64[1] = 0x8000000000000000ui64;
          inertia.m_col2.m_quad.m128_u64[0] = 0i64;
          inertia.m_col2.m_quad.m128_u64[1] = 0x8000000000000000ui64;
          v41 = _mm_mul_ps(
                  v22,
                  _mm_andnot_ps(
                    _mm_cmple_ps(v38, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v40, v38), v40)),
                      _mm_mul_ps(*(__m128 *)_xmm, v40))));
          hkArrayUtil::_reserve(&v53, &hkContainerHeapAllocator::s_alloc, (const void **)&inertia.m_col1, 6, 16);
          inertia.m_col1.m_quad.m128_i32[2] = 6;
          v42 = _mm_mul_ps(v41, v39);
          v43 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v39), v41);
          *(__m128 *)inertia.m_col1.m_quad.m128_u64[0] = _mm_add_ps(v42, v0->m_quad);
          *(__m128 *)(inertia.m_col1.m_quad.m128_u64[0] + 16) = _mm_add_ps(v43, v0->m_quad);
          *(__m128 *)(inertia.m_col1.m_quad.m128_u64[0] + 32) = _mm_add_ps(v42, v1->m_quad);
          *(__m128 *)(inertia.m_col1.m_quad.m128_u64[0] + 48) = _mm_add_ps(v43, v1->m_quad);
          *(__m128 *)(inertia.m_col1.m_quad.m128_u64[0] + 64) = _mm_add_ps(v42, v2->m_quad);
          *(__m128 *)(inertia.m_col1.m_quad.m128_u64[0] + 80) = _mm_add_ps(v43, v2->m_quad);
          if ( (inertia.m_col2.m_quad.m128_i32[3] & 0x3FFFFFFFu) < 8 )
          {
            v44 = 8;
            if ( 2 * (inertia.m_col2.m_quad.m128_i32[3] & 0x3FFFFFFF) > 8 )
              v44 = 2 * (inertia.m_col2.m_quad.m128_i32[3] & 0x3FFFFFFF);
            hkArrayUtil::_reserve(&v53, &hkContainerHeapAllocator::s_alloc, (const void **)&inertia.m_col2, v44, 16);
          }
          v45 = (_DWORD *)inertia.m_col2.m_quad.m128_u64[0];
          inertia.m_col2.m_quad.m128_i32[2] = 8;
          *(_DWORD *)inertia.m_col2.m_quad.m128_u64[0] = 0;
          v45[1] = 2;
          v45[2] = 4;
          v45[3] = -1;
          v46 = (_DWORD *)inertia.m_col2.m_quad.m128_u64[0];
          *(_DWORD *)(inertia.m_col2.m_quad.m128_u64[0] + 16) = 1;
          v46[5] = 5;
          v46[6] = 3;
          v46[7] = -1;
          v47 = (_DWORD *)inertia.m_col2.m_quad.m128_u64[0];
          *(_DWORD *)(inertia.m_col2.m_quad.m128_u64[0] + 32) = 0;
          v47[9] = 3;
          v47[10] = 2;
          v47[11] = -1;
          v48 = (_DWORD *)inertia.m_col2.m_quad.m128_u64[0];
          *(_DWORD *)(inertia.m_col2.m_quad.m128_u64[0] + 48) = 0;
          v48[13] = 1;
          v48[14] = 3;
          v48[15] = -1;
          v49 = inertia.m_col2.m_quad.m128_u64[0];
          *(_QWORD *)(inertia.m_col2.m_quad.m128_u64[0] + 64) = 1i64;
          *(_DWORD *)(v49 + 72) = 4;
          *(_DWORD *)(v49 + 76) = -1;
          v50 = (_DWORD *)inertia.m_col2.m_quad.m128_u64[0];
          *(_DWORD *)(inertia.m_col2.m_quad.m128_u64[0] + 80) = 1;
          v50[21] = 4;
          v50[22] = 5;
          v50[23] = -1;
          v51 = (_DWORD *)inertia.m_col2.m_quad.m128_u64[0];
          *(_DWORD *)(inertia.m_col2.m_quad.m128_u64[0] + 96) = 2;
          v51[25] = 5;
          v51[26] = 4;
          v51[27] = -1;
          v52 = (_DWORD *)inertia.m_col2.m_quad.m128_u64[0];
          *(_DWORD *)(inertia.m_col2.m_quad.m128_u64[0] + 112) = 2;
          v52[29] = 3;
          v52[30] = 5;
          v52[31] = -1;
          hkInertiaTensorComputer::computeGeometryVolumeMassProperties((hkGeometry *)&inertia, mass, &v55);
          hkGeometry::~hkGeometry((hkGeometry *)&inertia);
          v28.m_quad = (__m128)v55.m_centerOfMass;
          v34 = v55.m_inertiaTensor.m_col0.m_quad;
          v33 = v55.m_inertiaTensor.m_col1.m_quad;
          v32 = v55.m_inertiaTensor.m_col2.m_quad;
        }
        else
        {
          v28.m_quad = _mm_mul_ps(_mm_add_ps(_mm_add_ps(v17, m_quad), v18), (__m128)xmmword_141A711C0);
          v35 = _mm_mul_ps(v28.m_quad, v28.m_quad);
          v36 = (__m128)_mm_srli_si128(
                          _mm_slli_si128(
                            (__m128i)_mm_mul_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v35, v35, 90), _mm_shuffle_ps(v35, v35, 65)),
                                       v12),
                            4),
                          4);
          v37 = _mm_mul_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v28.m_quad, v28.m_quad, 233), _mm_unpacklo_ps(v28.m_quad, v28.m_quad)),
                  _mm_sub_ps((__m128)0i64, v12));
          v34 = _mm_or_ps(
                  _mm_andnot_ps((__m128)xmmword_141A78FE0, _mm_unpacklo_ps(v37, v37)),
                  _mm_and_ps((__m128)xmmword_141A78FE0, v36));
          v33 = _mm_or_ps(_mm_andnot_ps((__m128)xmmword_141A78FF0, v37), _mm_and_ps((__m128)xmmword_141A78FF0, v36));
          v32 = _mm_or_ps(
                  _mm_andnot_ps((__m128)xmmword_141A79010, _mm_shuffle_ps(v37, v37, 233)),
                  _mm_and_ps((__m128)xmmword_141A79010, v36));
        }
      }
      else
      {
        v26 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_083333336), (__m128)LODWORD(FLOAT_0_083333336), 0), v12);
        v53.m_enum = LODWORD(FLOAT_9_0);
        v27 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_9_0), (__m128)LODWORD(FLOAT_9_0), 0);
        v28.m_quad = _mm_mul_ps(_mm_add_ps(_mm_add_ps(v17, m_quad), v18), (__m128)xmmword_141A711C0);
        shift.m_quad = v28.m_quad;
        v29 = _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v28.m_quad, v28.m_quad), v27), _mm_mul_ps(v17, v17)),
                    _mm_mul_ps(m_quad, m_quad)),
                  _mm_mul_ps(v18, v18)),
                v26);
        v30 = (__m128)_mm_srli_si128(
                        _mm_slli_si128(
                          (__m128i)_mm_add_ps(_mm_shuffle_ps(v29, v29, 90), _mm_shuffle_ps(v29, v29, 65)),
                          4),
                        4);
        v31 = _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v28.m_quad, v28.m_quad, 233), _mm_unpacklo_ps(v28.m_quad, v28.m_quad)),
                        v27),
                      _mm_mul_ps(_mm_shuffle_ps(v17, v17, 233), _mm_unpacklo_ps(v17, v17))),
                    _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 233), _mm_unpacklo_ps(m_quad, m_quad))),
                  _mm_mul_ps(_mm_shuffle_ps(v18, v18, 233), _mm_unpacklo_ps(v18, v18))),
                _mm_sub_ps((__m128)0i64, v26));
        inertia.m_col0.m_quad = _mm_or_ps(
                                  _mm_andnot_ps((__m128)xmmword_141A78FE0, _mm_unpacklo_ps(v31, v31)),
                                  _mm_and_ps((__m128)xmmword_141A78FE0, v30));
        inertia.m_col1.m_quad = _mm_or_ps(
                                  _mm_andnot_ps((__m128)xmmword_141A78FF0, v31),
                                  _mm_and_ps((__m128)xmmword_141A78FF0, v30));
        inertia.m_col2.m_quad = _mm_or_ps(
                                  _mm_andnot_ps((__m128)xmmword_141A79010, _mm_shuffle_ps(v31, v31, 233)),
                                  _mm_and_ps((__m128)xmmword_141A79010, v30));
        hkInertiaTensorComputer::shiftInertiaToCom(&shift, &v57, &inertia);
        v32 = inertia.m_col2.m_quad;
        v33 = inertia.m_col1.m_quad;
        v34 = inertia.m_col0.m_quad;
      }
      result->m_enum = HK_SUCCESS;
      resulta->m_mass = mass;
      resulta->m_inertiaTensor.m_col0.m_quad = v34;
      resulta->m_inertiaTensor.m_col1.m_quad = v33;
      resulta->m_inertiaTensor.m_col2.m_quad = v32;
      resulta->m_centerOfMass = (hkVector4f)v28.m_quad;
      resulta->m_volume = (float)(v25 * 0.5) * v14.m128_f32[0];
      return result;
    }
    else
    {
      v13 = result;
      result->m_enum = HK_FAILURE;
    }
  }
  else
  {
    v13 = result;
    result->m_enum = HK_FAILURE;
  }
  return v13;
}

// File Line: 383
// RVA: 0xC98C80
hkResult *__fastcall hkInertiaTensorComputer::computeBoxVolumeMassProperties(
        hkResult *result,
        hkVector4f *halfExtents,
        float mass,
        hkMassProperties *volume)
{
  hkResult *v6; // rax
  hkVector4f v7; // xmm3
  hkVector4f v8; // xmm2
  hkVector4f inertiaDiagonal; // [rsp+30h] [rbp-18h] BYREF

  volume->m_mass = mass;
  volume->m_centerOfMass = 0i64;
  inertiaDiagonal.m_quad = 0i64;
  hkInertiaTensorComputer::computeBoxVolumeMassPropertiesDiagonalized(
    result,
    halfExtents,
    mass,
    &inertiaDiagonal,
    &volume->m_volume);
  v6 = result;
  v7.m_quad = _mm_mul_ps(direction.m_quad, inertiaDiagonal.m_quad);
  v8.m_quad = _mm_mul_ps(stru_141A71280.m_quad, inertiaDiagonal.m_quad);
  volume->m_inertiaTensor.m_col0.m_quad = _mm_mul_ps(transform.m_quad, inertiaDiagonal.m_quad);
  volume->m_inertiaTensor.m_col1 = (hkVector4f)v7.m_quad;
  volume->m_inertiaTensor.m_col2 = (hkVector4f)v8.m_quad;
  return v6;
}

// File Line: 396
// RVA: 0xC98D00
hkResult *__fastcall hkInertiaTensorComputer::computeBoxVolumeMassPropertiesDiagonalized(
        hkResult *result,
        hkVector4f *halfExtents,
        float mass,
        hkVector4f *inertiaDiagonal,
        float *volume)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm3
  __m128 m_quad; // xmm0
  __m128 v9; // xmm0
  __m128 v10; // xmm1

  v5.m128_f32[0] = mass;
  v6 = _mm_shuffle_ps(v5, v5, 0);
  if ( v6.m128_f32[0] > 0.0 )
  {
    m_quad = halfExtents->m_quad;
    result->m_enum = HK_SUCCESS;
    v9 = _mm_mul_ps(m_quad, m_quad);
    v10 = _mm_mul_ps(
            _mm_add_ps(_mm_shuffle_ps(v9, v9, 90), _mm_shuffle_ps(v9, v9, 65)),
            _mm_mul_ps((__m128)xmmword_141A711C0, v6));
    *inertiaDiagonal = (hkVector4f)v10;
    inertiaDiagonal->m_quad = _mm_shuffle_ps(v10, _mm_unpackhi_ps(v10, query.m_quad), 196);
    *volume = (float)((float)(_mm_shuffle_ps(halfExtents->m_quad, halfExtents->m_quad, 85).m128_f32[0]
                            * _mm_shuffle_ps(halfExtents->m_quad, halfExtents->m_quad, 0).m128_f32[0])
                    * _mm_shuffle_ps(halfExtents->m_quad, halfExtents->m_quad, 170).m128_f32[0])
            * 8.0;
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 419
// RVA: 0xC9A770
hkResult *__fastcall hkInertiaTensorComputer::computeVertexHullVolumeMassProperties(
        hkResult *result,
        const float *vertexIn,
        int striding,
        int numVertices,
        float mass,
        hkMassProperties *resulta)
{
  hkResult v8; // [rsp+20h] [rbp-38h] BYREF
  hkStridedVertices vertices; // [rsp+28h] [rbp-30h] BYREF
  hkSimdFloat32 newMass; // [rsp+40h] [rbp-18h] BYREF

  newMass.m_real = _mm_shuffle_ps((__m128)LODWORD(mass), (__m128)LODWORD(mass), 0);
  if ( newMass.m_real.m128_f32[0] <= 0.0 || numVertices < 1 )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    vertices.m_numVertices = numVertices;
    vertices.m_vertices = vertexIn;
    vertices.m_striding = striding;
    hkInertiaTensorComputer::computeConvexHullMassProperties(&v8, &vertices, 0.0, resulta);
    hkMassProperties::scaleToMass(resulta, &newMass);
    result->m_enum = v8.m_enum;
    return result;
  }
}

// File Line: 440
// RVA: 0xC9A800
hkResult *__fastcall hkInertiaTensorComputer::computeVertexCloudMassProperties(
        hkResult *result,
        const float *vertexIn,
        int striding,
        int numVertices,
        float mass,
        hkMassProperties *resulta)
{
  __int64 v6; // rdi
  __int64 v7; // rbp
  __m128 v10; // xmm6
  __m128 v11; // xmm0
  __m128 v12; // xmm7
  __m128 v13; // xmm5
  int v14; // r8d
  __m128 *v15; // rdx
  __int64 v16; // r10
  __int64 v17; // rcx
  __int64 v18; // r8
  __m128 v19; // xmm0
  __m128 v20; // xmm1
  hkMassProperties *v21; // r9
  __m128 v22; // xmm5
  __m128 v23; // xmm0
  __m128 *v24; // rax
  __int64 v25; // rcx
  __m128 v26; // xmm7
  __m128 v27; // xmm8
  __m128 v28; // xmm9
  __m128 *v29; // rax
  __m128 v30; // xmm10
  __m128 v31; // xmm1
  __m128 v32; // xmm1
  __m128 v33; // xmm0
  __m128 v34; // xmm3
  __m128 v35; // xmm4
  __m128 *array; // [rsp+30h] [rbp-98h] BYREF
  int v38; // [rsp+38h] [rbp-90h]
  int v39; // [rsp+3Ch] [rbp-8Ch]
  hkResult v40; // [rsp+E8h] [rbp+20h] BYREF

  v6 = numVertices;
  v7 = striding;
  if ( numVertices > 0 )
  {
    v10 = 0i64;
    array = 0i64;
    v38 = 0;
    v39 = 0x80000000;
    v11 = 0i64;
    v11.m128_f32[0] = (float)numVertices;
    v12 = _mm_div_ps(query.m_quad, _mm_shuffle_ps(v11, v11, 0));
    hkArrayUtil::_reserve(&v40, &hkContainerHeapAllocator::s_alloc, (const void **)&array, numVertices, 16);
    v14 = v39;
    v15 = array;
    v38 = v6;
    v16 = v6;
    if ( (int)v6 > 0 )
    {
      v17 = 0i64;
      v18 = v6;
      do
      {
        v19 = (__m128)*((unsigned int *)vertexIn + 2);
        v20 = (__m128)*(unsigned __int64 *)vertexIn;
        vertexIn = (const float *)((char *)vertexIn + v7);
        v15[v17++] = _mm_movelh_ps(v20, v19);
        array[v17 - 1] = (__m128)_mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&array[v17 - 1]), 4), 4);
        v15 = array;
        --v18;
      }
      while ( v18 );
      v14 = v39;
    }
    v21 = resulta;
    v13.m128_f32[0] = mass;
    resulta->m_mass = mass;
    v21->m_centerOfMass = 0i64;
    v22 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v12);
    if ( (int)v6 > 0 )
    {
      v23 = 0i64;
      v24 = v15;
      v25 = v6;
      do
      {
        v23 = _mm_add_ps(v23, *v24++);
        v21->m_centerOfMass.m_quad = v23;
        --v25;
      }
      while ( v25 );
    }
    v26 = _mm_mul_ps(v12, v21->m_centerOfMass.m_quad);
    v27 = 0i64;
    v28 = 0i64;
    v21->m_centerOfMass.m_quad = v26;
    if ( (int)v6 > 0 )
    {
      v29 = v15;
      v30 = _mm_sub_ps((__m128)0i64, v22);
      do
      {
        v31 = *v29++;
        v32 = _mm_sub_ps(v31, v26);
        v33 = _mm_mul_ps(v32, v32);
        v34 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v32, v32, 233), _mm_unpacklo_ps(v32, v32)), v30);
        v35 = (__m128)_mm_srli_si128(
                        _mm_slli_si128(
                          (__m128i)_mm_mul_ps(
                                     _mm_add_ps(_mm_shuffle_ps(v33, v33, 90), _mm_shuffle_ps(v33, v33, 65)),
                                     v22),
                          4),
                        4);
        v10 = _mm_add_ps(
                v10,
                _mm_or_ps(
                  _mm_andnot_ps((__m128)xmmword_141A78FE0, _mm_unpacklo_ps(v34, v34)),
                  _mm_and_ps((__m128)xmmword_141A78FE0, v35)));
        v27 = _mm_add_ps(
                v27,
                _mm_or_ps(_mm_andnot_ps((__m128)xmmword_141A78FF0, v34), _mm_and_ps((__m128)xmmword_141A78FF0, v35)));
        v28 = _mm_add_ps(
                v28,
                _mm_or_ps(
                  _mm_andnot_ps((__m128)xmmword_141A79010, _mm_shuffle_ps(v34, v34, 233)),
                  _mm_and_ps((__m128)xmmword_141A79010, v35)));
        --v16;
      }
      while ( v16 );
    }
    v21->m_inertiaTensor.m_col0.m_quad = v10;
    result->m_enum = HK_SUCCESS;
    v38 = 0;
    v21->m_inertiaTensor.m_col1.m_quad = v27;
    v21->m_inertiaTensor.m_col2.m_quad = v28;
    if ( v14 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v15, 16 * v14);
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 528
// RVA: 0xC98D90
hkResult *__fastcall hkInertiaTensorComputer::computeCapsuleVolumeMassProperties(
        hkResult *result,
        hkVector4f *startAxis,
        hkVector4f *endAxis,
        float radius,
        hkMassProperties *mass,
        hkMassProperties *resulta)
{
  __m128 v6; // xmm10
  __m128 v9; // xmm12
  __m128 v12; // xmm10
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm11
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm4
  __m128 v20; // xmm13
  __m128 v21; // xmm7
  __m128 v22; // xmm4
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  __m128 v29; // xmm2
  __m128 v30; // xmm5
  __m128 v31; // xmm4
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm5
  __m128 v36; // xmm2
  hkVector4f v37; // xmm13
  hkVector4f v38; // xmm14
  hkVector4f v39; // xmm15
  __m128 m_quad; // xmm3
  __m128 v41; // xmm4
  __m128 v42; // xmm5
  __m128 v43; // xmm2
  char *v44; // rax
  __m128 v45; // xmm2
  __m128 v46; // xmm2
  __m128 v47; // xmm8
  int v48; // ecx
  __m128 v49; // xmm7
  __m128 v50; // xmm1
  __m128 v51; // xmm6
  __m128 v52; // xmm1
  __m128 v53; // xmm2
  __m128 v54; // xmm2
  int m_size; // edx
  hkMassElement *v56; // rcx
  float v57; // xmm12_4
  __m128 v58; // xmm8
  __m128 v59; // xmm2
  __m128 m_real; // xmm2
  int v61; // edx
  hkMassElement *v62; // rcx
  __m128 v63; // xmm2
  int v64; // edx
  hkMassElement *v65; // rcx
  float radiusa; // [rsp+20h] [rbp-D8h] BYREF
  float v67; // [rsp+24h] [rbp-D4h]
  hkSimdFloat32 v68; // [rsp+30h] [rbp-C8h] BYREF
  __int128 v69; // [rsp+40h] [rbp-B8h]
  hkVector4f shift; // [rsp+50h] [rbp-A8h] BYREF
  hkVector4f inertia; // [rsp+60h] [rbp-98h] BYREF
  _BYTE inertia_16[24]; // [rsp+70h] [rbp-88h] BYREF
  hkRotationf inertia_40; // [rsp+88h] [rbp-70h]
  __m128 v74; // [rsp+B8h] [rbp-40h]
  hkQuaternionf qi; // [rsp+C8h] [rbp-30h] BYREF
  hkRotationf v76; // [rsp+D8h] [rbp-20h] BYREF
  __m128 v77; // [rsp+108h] [rbp+10h]
  hkMassProperties v78; // [rsp+118h] [rbp+20h] BYREF
  hkSimdFloat32 scale; // [rsp+168h] [rbp+70h] BYREF
  hkVector4f axis; // [rsp+178h] [rbp+80h] BYREF
  hkSimdFloat32 angle; // [rsp+188h] [rbp+90h] BYREF
  hkArray<hkMassElement,hkContainerHeapAllocator> array; // [rsp+198h] [rbp+A0h] BYREF
  char v83; // [rsp+1A8h] [rbp+B0h] BYREF
  char v84; // [rsp+1E8h] [rbp+F0h] BYREF
  __m128 v85; // [rsp+3B0h] [rbp+2B8h]
  unsigned int v86; // [rsp+428h] [rbp+330h]

  v9 = _mm_shuffle_ps((__m128)v86, (__m128)v86, 0);
  radiusa = radius;
  if ( v9.m128_f32[0] > 0.0 )
  {
    v85 = v6;
    v6.m128_f32[0] = radius;
    v12 = _mm_shuffle_ps(v6, v6, 0);
    if ( v12.m128_f32[0] > 0.0 )
    {
      v13 = _mm_sub_ps(endAxis->m_quad, startAxis->m_quad);
      v14 = _mm_mul_ps(v13, v13);
      v15 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
              _mm_shuffle_ps(v14, v14, 170));
      v16 = _mm_andnot_ps(_mm_cmple_ps(v15, (__m128)0i64), _mm_sqrt_ps(v15));
      if ( v16.m128_f32[0] <= 0.0
        || (v17 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                    _mm_shuffle_ps(v14, v14, 170)),
            v18 = _mm_rsqrt_ps(v17),
            v67 = FLOAT_0_99998999,
            v19 = _mm_mul_ps(
                    v13,
                    _mm_andnot_ps(
                      _mm_cmple_ps(v17, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                        _mm_mul_ps(*(__m128 *)_xmm, v18)))),
            v20 = _mm_shuffle_ps(v19, v19, 170),
            COERCE_FLOAT((unsigned int)(2 * v20.m128_i32[0]) >> 1) >= _mm_shuffle_ps(
                                                                        (__m128)LODWORD(FLOAT_0_99998999),
                                                                        (__m128)LODWORD(FLOAT_0_99998999),
                                                                        0).m128_f32[0]) )
      {
        m_quad = stru_141A71280.m_quad;
        v41 = direction.m_quad;
        v42 = transform.m_quad;
        v37.m_quad = stru_141A71280.m_quad;
        v38.m_quad = direction.m_quad;
        v39.m_quad = transform.m_quad;
        v76.m_col2 = (hkVector4f)stru_141A71280.m_quad;
        v76.m_col1 = (hkVector4f)direction.m_quad;
        v76.m_col0 = (hkVector4f)transform.m_quad;
      }
      else
      {
        v21 = _mm_andnot_ps(*(__m128 *)_xmm, v20);
        v22 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), stru_141A71280.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201), v19));
        v23 = _mm_shuffle_ps(v22, v22, 201);
        v24 = _mm_mul_ps(v23, v23);
        v25 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                _mm_shuffle_ps(v24, v24, 170));
        v26 = _mm_rsqrt_ps(v25);
        v27 = _mm_cmple_ps(v25, (__m128)0i64);
        v28 = _mm_mul_ps(_mm_mul_ps(v26, v25), v26);
        v29 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v21), *(__m128 *)_xmm);
        v30 = _mm_cmplt_ps(*(__m128 *)_xmm, v21);
        axis.m_quad = _mm_mul_ps(
                        v23,
                        _mm_andnot_ps(v27, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v28), _mm_mul_ps(*(__m128 *)_xmm, v26))));
        v31 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v29), v30), _mm_andnot_ps(v30, v21));
        v32 = _mm_or_ps(_mm_andnot_ps(v30, _mm_mul_ps(v21, v21)), _mm_and_ps(v30, v29));
        v33 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v32, *(__m128 *)coeff4), *(__m128 *)coeff3), v32),
                              *(__m128 *)coeff2),
                            v32),
                          *(__m128 *)coeff1),
                        v32),
                      *(__m128 *)coeff0),
                    v32),
                  v31),
                v31);
        v34 = _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v33, v33)), v30);
        v35 = _mm_andnot_ps(v30, v33);
        v36 = _mm_cmplt_ps(v21, *(__m128 *)_xmm);
        angle.m_real = _mm_sub_ps(
                         *(__m128 *)_xmm,
                         _mm_xor_ps(
                           _mm_or_ps(_mm_andnot_ps(v36, _mm_or_ps(v34, v35)), _mm_and_ps(v36, v21)),
                           _mm_and_ps(v20, *(__m128 *)_xmm)));
        hkQuaternionf::setAxisAngle(&qi, &axis, &angle);
        hkRotationf::set(&v76, &qi);
        v37.m_quad = (__m128)v76.m_col2;
        v38.m_quad = (__m128)v76.m_col1;
        v39.m_quad = (__m128)v76.m_col0;
        m_quad = stru_141A71280.m_quad;
        v41 = direction.m_quad;
        v42 = transform.m_quad;
      }
      v43 = startAxis->m_quad;
      array.m_capacityAndFlags = -2147483645;
      array.m_data = (hkMassElement *)&v83;
      v44 = &v84;
      v45 = _mm_add_ps(v43, endAxis->m_quad);
      v68.m_real = (__m128)xmmword_141A711B0;
      array.m_size = 0;
      v46 = _mm_mul_ps(v45, (__m128)xmmword_141A711B0);
      v47 = _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(v12, (__m128)xmmword_141A713B0), v12), v16);
      v48 = 2;
      v77 = v46;
      v49 = _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(v12, (__m128)xmmword_141A713E0), v12), v12);
      v50 = _mm_add_ps(v47, v49);
      v51 = _mm_div_ps(_mm_mul_ps(v49, v9), v50);
      scale.m_real = _mm_div_ps(_mm_mul_ps(v47, v9), v50);
      do
      {
        --v48;
        *((_QWORD *)v44 - 8) = 0i64;
        *((_OWORD *)v44 - 3) = 0i64;
        *((_OWORD *)v44 - 2) = 0i64;
        *((_OWORD *)v44 - 1) = 0i64;
        *(_OWORD *)v44 = 0i64;
        v44 += 144;
        *((__m128 *)v44 - 8) = v42;
        *((__m128 *)v44 - 7) = v41;
        *((__m128 *)v44 - 6) = m_quad;
        *((_OWORD *)v44 - 5) = 0i64;
      }
      while ( v48 >= 0 );
      v74 = v46;
      v52 = _mm_mul_ps(v12, v12);
      inertia_40.m_col0 = (hkVector4f)v39.m_quad;
      inertia_40.m_col1 = (hkVector4f)v38.m_quad;
      inertia_40.m_col2 = (hkVector4f)v37.m_quad;
      v53 = _mm_mul_ps(
              _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v16, v16), (__m128)xmmword_141A711C0), v52),
              (__m128)xmmword_141A711D0);
      v54 = _mm_movelh_ps(
              _mm_unpacklo_ps(v53, v53),
              _mm_unpacklo_ps(_mm_mul_ps(v52, (__m128)xmmword_141A711B0), (__m128)xmmword_141A711D0));
      inertia.m_quad = _mm_mul_ps(v42, v54);
      *(_QWORD *)inertia_16 = _mm_mul_ps(v41, v54).m128_u64[0];
      *(__m128 *)&inertia_16[8] = _mm_mul_ps(m_quad, v54);
      hkMatrix3f::mul((hkMatrix3f *)&inertia, &scale);
      m_size = array.m_size;
      *(_QWORD *)&v69 = __PAIR64__(scale.m_real.m128_u32[0], v47.m128_u32[0]);
      shift.m_quad = 0i64;
      if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 144);
        m_size = array.m_size;
      }
      v56 = &array.m_data[m_size];
      if ( v56 )
      {
        *(_OWORD *)&v56->m_properties.m_volume = v69;
        v56->m_properties.m_centerOfMass = (hkVector4f)shift.m_quad;
        v56->m_properties.m_inertiaTensor.m_col0 = (hkVector4f)inertia.m_quad;
        v56->m_properties.m_inertiaTensor.m_col1 = *(hkVector4f *)inertia_16;
        v56->m_properties.m_inertiaTensor.m_col2 = *(hkVector4f *)&inertia_16[8];
        v56->m_transform.m_rotation = inertia_40;
        v56->m_transform.m_translation.m_quad = v74;
        m_size = array.m_size;
      }
      v57 = radiusa;
      *(_QWORD *)&v69 = 0i64;
      *(_QWORD *)&v78.m_volume = 0i64;
      array.m_size = m_size + 1;
      inertia_40 = v76;
      v58 = _mm_unpacklo_ps((__m128)0i64, (__m128)0i64);
      v59 = _mm_movelh_ps(v58, _mm_unpacklo_ps(_mm_mul_ps(v68.m_real, v16), (__m128)0i64));
      inertia.m_quad = 0i64;
      memset(inertia_16, 0, sizeof(inertia_16));
      memset(&v78.m_centerOfMass, 0, 64);
      v67 = FLOAT_0_375;
      shift.m_quad = _mm_movelh_ps(
                       v58,
                       _mm_unpacklo_ps(
                         _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_375), (__m128)LODWORD(FLOAT_0_375), 0), v12),
                         (__m128)0i64));
      v74 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v59, v59, 85), v76.m_col1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v59, v59, 0), v76.m_col0.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v59, v59, 170), v76.m_col2.m_quad)),
              v77);
      if ( hkInertiaTensorComputer::computeSphereVolumeMassProperties(
             (hkResult *)&radiusa,
             radiusa,
             v51.m128_f32[0],
             &v78)->m_enum == HK_FAILURE )
      {
        result->m_enum = HK_FAILURE;
      }
      else
      {
        inertia.m_quad = (__m128)v78.m_inertiaTensor.m_col0;
        *(_QWORD *)inertia_16 = v78.m_inertiaTensor.m_col1.m_quad.m128_u64[0];
        *(hkVector4f *)&inertia_16[8] = v78.m_inertiaTensor.m_col2;
        hkMatrix3f::mul((hkMatrix3f *)&inertia, &v68);
        qi.m_vec.m_quad = _mm_mul_ps(v51, v68.m_real);
        hkInertiaTensorComputer::shiftInertiaToCom(&shift, (hkSimdFloat32 *)&qi, (hkMatrix3f *)&inertia);
        m_real = v68.m_real;
        v61 = array.m_size;
        *(float *)&v69 = v49.m128_f32[0] * v68.m_real.m128_f32[0];
        *((float *)&v69 + 1) = v51.m128_f32[0] * v68.m_real.m128_f32[0];
        if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 144);
          v61 = array.m_size;
          m_real = v68.m_real;
        }
        v62 = &array.m_data[v61];
        if ( v62 )
        {
          *(_OWORD *)&v62->m_properties.m_volume = v69;
          v62->m_properties.m_centerOfMass = (hkVector4f)shift.m_quad;
          v62->m_properties.m_inertiaTensor.m_col0 = (hkVector4f)inertia.m_quad;
          v62->m_properties.m_inertiaTensor.m_col1 = *(hkVector4f *)inertia_16;
          v62->m_properties.m_inertiaTensor.m_col2 = *(hkVector4f *)&inertia_16[8];
          v62->m_transform.m_rotation = inertia_40;
          v62->m_transform.m_translation.m_quad = v74;
          m_real = v68.m_real;
          v61 = array.m_size;
        }
        *(_QWORD *)&v69 = 0i64;
        *(_QWORD *)&v78.m_volume = 0i64;
        array.m_size = v61 + 1;
        inertia_40 = v76;
        inertia.m_quad = 0i64;
        memset(inertia_16, 0, sizeof(inertia_16));
        v63 = _mm_movelh_ps(v58, _mm_unpacklo_ps(_mm_sub_ps((__m128)0i64, _mm_mul_ps(m_real, v16)), (__m128)0i64));
        memset(&v78.m_centerOfMass, 0, 64);
        radiusa = FLOAT_N0_375;
        shift.m_quad = _mm_movelh_ps(
                         v58,
                         _mm_unpacklo_ps(
                           _mm_mul_ps(
                             _mm_shuffle_ps((__m128)LODWORD(FLOAT_N0_375), (__m128)LODWORD(FLOAT_N0_375), 0),
                             v12),
                           (__m128)0i64));
        v74 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v63, v63, 85), v76.m_col1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v63, v63, 0), v76.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v63, v63, 170), v76.m_col2.m_quad)),
                v77);
        if ( hkInertiaTensorComputer::computeSphereVolumeMassProperties(
               (hkResult *)&radiusa,
               v57,
               v51.m128_f32[0],
               &v78)->m_enum == HK_FAILURE )
        {
          result->m_enum = HK_FAILURE;
        }
        else
        {
          inertia.m_quad = (__m128)v78.m_inertiaTensor.m_col0;
          *(_QWORD *)inertia_16 = v78.m_inertiaTensor.m_col1.m_quad.m128_u64[0];
          *(hkVector4f *)&inertia_16[8] = v78.m_inertiaTensor.m_col2;
          hkMatrix3f::mul((hkMatrix3f *)&inertia, &v68);
          qi.m_vec.m_quad = _mm_mul_ps(v51, v68.m_real);
          hkInertiaTensorComputer::shiftInertiaToCom(&shift, (hkSimdFloat32 *)&qi, (hkMatrix3f *)&inertia);
          v64 = array.m_size;
          *(float *)&v69 = v49.m128_f32[0] * v68.m_real.m128_f32[0];
          *((float *)&v69 + 1) = v51.m128_f32[0] * v68.m_real.m128_f32[0];
          if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, 144);
            v64 = array.m_size;
          }
          v65 = &array.m_data[v64];
          if ( v65 )
          {
            *(_OWORD *)&v65->m_properties.m_volume = v69;
            v65->m_properties.m_centerOfMass = (hkVector4f)shift.m_quad;
            v65->m_properties.m_inertiaTensor.m_col0 = (hkVector4f)inertia.m_quad;
            v65->m_properties.m_inertiaTensor.m_col1 = *(hkVector4f *)inertia_16;
            v65->m_properties.m_inertiaTensor.m_col2 = *(hkVector4f *)&inertia_16[8];
            v65->m_transform.m_rotation = inertia_40;
            v65->m_transform.m_translation.m_quad = v74;
            v64 = array.m_size;
          }
          array.m_size = v64 + 1;
          hkInertiaTensorComputer::combineMassProperties(result, &array, mass);
        }
      }
      array.m_size = 0;
      if ( array.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          array.m_data,
          144 * (array.m_capacityAndFlags & 0x3FFFFFFF));
      return result;
    }
    else
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}dFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          array.m_data,
          144 * (array.m_capacityAndFlags & 0x3FFFFFFF));
      return result;
    }
    else
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  

// File Line: 720
// RVA: 0xC9A1F0
hkResult *__fastcall hkInertiaTensorComputer::computeCylinderVolumeMassProperties(
        hkResult *result,
        hkVector4f *startAxis,
        hkVector4f *endAxis,
        float radius,
        hkMassProperties *mass,
        hkMassProperties *resulta)
{
  __m128 v6; // xmm10
  __m128 v9; // xmm12
  __m128 v12; // xmm10
  __m128 v13; // xmm4
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm9
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm4
  __m128 v20; // xmm13
  __m128 v21; // xmm7
  __m128 v22; // xmm4
  __m128 v23; // xmm4
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  __m128 v29; // xmm2
  __m128 v30; // xmm5
  __m128 v31; // xmm4
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm5
  __m128 v36; // xmm2
  __int128 m_col2; // xmm7
  __int128 m_col1; // xmm8
  __m128 v39; // xmm13
  __m128 v40; // xmm5
  __m128 v41; // xmm4
  __m128 m_quad; // xmm3
  __m128 v43; // xmm1
  __m128 v44; // xmm1
  float v45; // xmm6_4
  __m128 v46; // xmm10
  unsigned int v47; // xmm6_4
  __m128 v48; // xmm9
  __m128 v49; // xmm9
  hkSimdFloat32 scale; // [rsp+30h] [rbp-C8h] BYREF
  hkArray<hkMassElement,hkContainerHeapAllocator> elements; // [rsp+40h] [rbp-B8h] BYREF
  unsigned __int64 v52; // [rsp+50h] [rbp-A8h] BYREF
  __int128 v53; // [rsp+60h] [rbp-98h]
  char v54[56]; // [rsp+70h] [rbp-88h] BYREF
  __int128 v55; // [rsp+A8h] [rbp-50h]
  __int128 v56; // [rsp+B8h] [rbp-40h]
  __m128 v57; // [rsp+C8h] [rbp-30h]
  hkVector4f axis; // [rsp+D8h] [rbp-20h] BYREF
  hkRotationf v59; // [rsp+E8h] [rbp-10h] BYREF
  __m128 v60; // [rsp+118h] [rbp+20h]
  hkQuaternionf qi; // [rsp+128h] [rbp+30h] BYREF
  hkSimdFloat32 angle; // [rsp+138h] [rbp+40h] BYREF
  __m128 v63; // [rsp+180h] [rbp+88h]
  unsigned int v64; // [rsp+1F8h] [rbp+100h]

  v9 = _mm_shuffle_ps((__m128)v64, (__m128)v64, 0);
  if ( v9.m128_f32[0] > 0.0 )
  {
    v63 = v6;
    v6.m128_f32[0] = radius;
    v12 = _mm_shuffle_ps(v6, v6, 0);
    if ( v12.m128_f32[0] > 0.0 )
    {
      v13 = _mm_sub_ps(endAxis->m_quad, startAxis->m_quad);
      v14 = _mm_mul_ps(v13, v13);
      v15 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
              _mm_shuffle_ps(v14, v14, 170));
      v16 = _mm_andnot_ps(_mm_cmple_ps(v15, (__m128)0i64), _mm_sqrt_ps(v15));
      if ( v16.m128_f32[0] > 0.0 )
      {
        v17 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                _mm_shuffle_ps(v14, v14, 170));
        v18 = _mm_rsqrt_ps(v17);
        v19 = _mm_mul_ps(
                v13,
                _mm_andnot_ps(
                  _mm_cmple_ps(v17, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                    _mm_mul_ps(*(__m128 *)_xmm, v18))));
        v20 = _mm_shuffle_ps(v19, v19, 170);
        if ( COERCE_FLOAT((unsigned int)(2 * v20.m128_i32[0]) >> 1) >= _mm_shuffle_ps(
                                                                         (__m128)LODWORD(FLOAT_0_99998999),
                                                                         (__m128)LODWORD(FLOAT_0_99998999),
                                                                         0).m128_f32[0] )
        {
          m_quad = transform.m_quad;
          v41 = direction.m_quad;
          v40 = stru_141A71280.m_quad;
          v39 = transform.m_quad;
          v59.m_col0 = (hkVector4f)transform.m_quad;
          m_col1 = (__int128)direction.m_quad;
          v59.m_col1 = (hkVector4f)direction.m_quad;
          m_col2 = (__int128)stru_141A71280.m_quad;
          v59.m_col2 = (hkVector4f)stru_141A71280.m_quad;
        }
        else
        {
          v21 = _mm_andnot_ps(*(__m128 *)_xmm, v20);
          v22 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), stru_141A71280.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201), v19));
          v23 = _mm_shuffle_ps(v22, v22, 201);
          v24 = _mm_mul_ps(v23, v23);
          v25 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                  _mm_shuffle_ps(v24, v24, 170));
          v26 = _mm_rsqrt_ps(v25);
          v27 = _mm_cmple_ps(v25, (__m128)0i64);
          v28 = _mm_mul_ps(_mm_mul_ps(v26, v25), v26);
          v29 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v21), *(__m128 *)_xmm);
          v30 = _mm_cmplt_ps(*(__m128 *)_xmm, v21);
          axis.m_quad = _mm_mul_ps(
                          v23,
                          _mm_andnot_ps(
                            v27,
                            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v28), _mm_mul_ps(*(__m128 *)_xmm, v26))));
          v31 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v29), v30), _mm_andnot_ps(v30, v21));
          v32 = _mm_or_ps(_mm_andnot_ps(v30, _mm_mul_ps(v21, v21)), _mm_and_ps(v30, v29));
          v33 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v32, *(__m128 *)coeff4), *(__m128 *)coeff3), v32),
                                *(__m128 *)coeff2),
                              v32),
                            *(__m128 *)coeff1),
                          v32),
                        *(__m128 *)coeff0),
                      v32),
                    v31),
                  v31);
          v34 = _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v33, v33)), v30);
          v35 = _mm_andnot_ps(v30, v33);
          v36 = _mm_cmplt_ps(v21, *(__m128 *)_xmm);
          angle.m_real = _mm_sub_ps(
                           *(__m128 *)_xmm,
                           _mm_xor_ps(
                             _mm_or_ps(_mm_andnot_ps(v36, _mm_or_ps(v34, v35)), _mm_and_ps(v36, v21)),
                             _mm_and_ps(v20, *(__m128 *)_xmm)));
          hkQuaternionf::setAxisAngle(&qi, &axis, &angle);
          hkRotationf::set(&v59, &qi);
          m_col2 = (__int128)v59.m_col2;
          m_col1 = (__int128)v59.m_col1;
          v39 = v59.m_col0.m_quad;
          v40 = stru_141A71280.m_quad;
          v41 = direction.m_quad;
          m_quad = transform.m_quad;
        }
        v43 = startAxis->m_quad;
        elements.m_capacityAndFlags = -2147483647;
        scale.m_real = v9;
        v53 = 0i64;
        *(__m128 *)&v54[40] = v39;
        v44 = _mm_add_ps(v43, endAxis->m_quad);
        v45 = (float)(v12.m128_f32[0] * 3.1415927) * v12.m128_f32[0];
        v46 = _mm_mul_ps(v12, v12);
        elements.m_data = (hkMassElement *)&v52;
        v52 = 0i64;
        elements.m_size = 1;
        v55 = m_col1;
        v56 = m_col2;
        *(float *)&v47 = v45 * v16.m128_f32[0];
        v60 = _mm_mul_ps(v44, (__m128)xmmword_141A711B0);
        v57 = v60;
        v48 = _mm_mul_ps(
                _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v16, v16), (__m128)xmmword_141A711C0), v46),
                (__m128)xmmword_141A711D0);
        v49 = _mm_movelh_ps(
                _mm_unpacklo_ps(v48, v48),
                _mm_unpacklo_ps(_mm_mul_ps(v46, (__m128)xmmword_141A711B0), (__m128)xmmword_141A711D0));
        *(_QWORD *)&v54[16] = *(unsigned __int128 *)&_mm_mul_ps(v41, v49) >> 64;
        *(__m128 *)&v54[24] = _mm_mul_ps(v40, v49);
        *(__m128 *)v54 = _mm_mul_ps(m_quad, v49);
        hkMatrix3f::mul((hkMatrix3f *)v54, &scale);
        v52 = __PAIR64__(scale.m_real.m128_u32[0], v47);
        v53 = 0i64;
        hkInertiaTensorComputer::combineMassProperties(result, &elements, mass);
        elements.m_size = 0;
        if ( elements.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            elements.m_data,
            144 * (elements.m_capacityAndFlags & 0x3FFFFFFF));
      }
      else
      {
        result->m_enum = HK_FAILURE;
      }
      return result;
    }
    else
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}

// File Line: 828
// RVA: 0xC9A690
hkResult *__fastcall hkInertiaTensorComputer::computeConvexHullMassProperties(
        hkResult *result,
        hkStridedVertices *vertices,
        float radius,
        hkMassProperties *a4)
{
  hkResultEnum m_enum; // edx
  hkResult *v6; // rax
  hkResult resulta; // [rsp+20h] [rbp-18h] BYREF

  if ( hkInertiaTensorComputer::s_computeConvexHullMassPropertiesFunction )
  {
    m_enum = hkInertiaTensorComputer::s_computeConvexHullMassPropertiesFunction(&resulta, vertices, radius, a4)->m_enum;
    v6 = result;
    result->m_enum = m_enum;
  }
  else
  {
    hkInertiaTensorComputer::computeApproximateConvexHullMassProperties(result, vertices, radius, a4);
    return result;
  }
  return v6;
}

// File Line: 841
// RVA: 0xC9AAF0
hkResult *__fastcall hkInertiaTensorComputer::computeGeometrySurfaceMassProperties(
        hkResult *result,
        hkGeometry *geom,
        float surfaceThickness,
        hkBool distributeUniformly,
        float mass,
        hkMassProperties *resulta)
{
  char v6; // bl
  __int64 v7; // r13
  __m128 v8; // xmm0
  __m128 v9; // xmm9
  __m128 v13; // xmm9
  char *v14; // r10
  __m128 v15; // xmm6
  int m_size; // ebx
  bool v17; // cc
  __m128 v18; // xmm4
  int v19; // r9d
  __int64 v20; // r8
  hkGeometry::Triangle *m_data; // rcx
  hkVector4f *v22; // rdx
  __int64 m_b; // rax
  __m128 m_quad; // xmm0
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm3
  __m128 v29; // xmm3
  __m128 v30; // xmm1
  __m128 v31; // xmm8
  __m128 v32; // xmm0
  int v33; // esi
  __m128 v34; // xmm8
  __int64 v35; // rbx
  hkGeometry::Triangle *v36; // rax
  hkVector4f *v37; // rcx
  __m128 v38; // xmm6
  __int64 m_a; // rdx
  __int64 v40; // r8
  __int64 m_c; // r9
  hkVector4f *v42; // rdx
  hkVector4f *v43; // r8
  hkVector4f *v44; // r9
  int v45; // r8d
  hkResult v47; // [rsp+40h] [rbp-A8h] BYREF
  char *array; // [rsp+48h] [rbp-A0h] BYREF
  int v49; // [rsp+50h] [rbp-98h]
  int v50; // [rsp+54h] [rbp-94h]
  _BYTE shift[24]; // [rsp+60h] [rbp-88h] BYREF
  hkMatrix3f v52; // [rsp+78h] [rbp-70h] BYREF
  hkSimdFloat32 v53; // [rsp+A8h] [rbp-40h] BYREF
  char v54; // [rsp+160h] [rbp+78h]
  float v55; // [rsp+168h] [rbp+80h]

  v9.m128_f32[0] = v55;
  v13 = _mm_shuffle_ps(v9, v9, 0);
  v53.m_real = v13;
  if ( v13.m128_f32[0] <= 0.0 || (v8.m128_f32[0] = surfaceThickness, _mm_shuffle_ps(v8, v8, 0).m128_f32[0] <= 0.0) )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    v54 = v6;
    v47.m_enum = LODWORD(FLOAT_0_0000099999997);
    v14 = 0i64;
    *(_OWORD *)(v7 + 32) = 0i64;
    *(_OWORD *)(v7 + 48) = 0i64;
    *(_OWORD *)(v7 + 64) = 0i64;
    array = 0i64;
    v49 = 0;
    v50 = 0x80000000;
    *(_OWORD *)(v7 + 16) = 0i64;
    v15 = _mm_shuffle_ps((__m128)(unsigned int)v47.m_enum, (__m128)(unsigned int)v47.m_enum, 0);
    if ( v6 )
    {
      m_size = geom->m_triangles.m_size;
      if ( m_size > 0 )
      {
        hkArrayUtil::_reserve(
          &v47,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&array,
          geom->m_triangles.m_size,
          16);
        v14 = array;
      }
      v17 = geom->m_triangles.m_size <= 0;
      v49 = m_size;
      v18 = 0i64;
      v19 = 0;
      if ( !v17 )
      {
        v20 = 0i64;
        do
        {
          m_data = geom->m_triangles.m_data;
          v22 = geom->m_vertices.m_data;
          ++v19;
          m_b = m_data[v20++].m_b;
          m_quad = v22[m_b].m_quad;
          v25 = _mm_sub_ps(v22[m_data[v20 - 1].m_c].m_quad, m_quad);
          v26 = _mm_sub_ps(v22[m_data[v20 - 1].m_a].m_quad, m_quad);
          v27 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v25),
                  _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), v26));
          v28 = _mm_shuffle_ps(v27, v27, 201);
          v29 = _mm_mul_ps(v28, v28);
          v30 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v29, v29, 85), _mm_shuffle_ps(v29, v29, 0)),
                  _mm_shuffle_ps(v29, v29, 170));
          *(__m128 *)&v14[v20 * 16 - 16] = _mm_max_ps(
                                             v15,
                                             _mm_andnot_ps(_mm_cmple_ps(v30, (__m128)0i64), _mm_sqrt_ps(v30)));
          *(__m128 *)&array[v20 * 16 - 16] = _mm_mul_ps(*(__m128 *)&array[v20 * 16 - 16], (__m128)xmmword_141A711B0);
          v14 = array;
          v18 = _mm_add_ps(v18, *(__m128 *)&array[v20 * 16 - 16]);
        }
        while ( v19 < geom->m_triangles.m_size );
      }
      v31 = _mm_div_ps(query.m_quad, v18);
    }
    else
    {
      v32 = 0i64;
      v32.m128_f32[0] = (float)geom->m_triangles.m_size;
      v31 = _mm_div_ps(query.m_quad, _mm_shuffle_ps(v32, v32, 0));
    }
    v33 = 0;
    if ( geom->m_triangles.m_size > 0 )
    {
      v34 = _mm_mul_ps(v31, v13);
      v35 = 0i64;
      while ( 1 )
      {
        v36 = geom->m_triangles.m_data;
        v37 = geom->m_vertices.m_data;
        v38 = v34;
        m_a = v36[v35].m_a;
        v40 = v36[v35].m_b;
        m_c = v36[v35].m_c;
        *(__m128 *)shift = v34;
        v42 = &v37[m_a];
        v43 = &v37[v40];
        v44 = &v37[m_c];
        if ( v54 )
        {
          v38 = _mm_mul_ps(v34, *(__m128 *)&v14[v35 * 16]);
          *(__m128 *)shift = v38;
        }
        *(_OWORD *)&shift[8] = 0i64;
        memset(&v52, 0, sizeof(v52));
        if ( hkInertiaTensorComputer::computeTriangleSurfaceMassProperties(
               &v47,
               v42,
               v43,
               v44,
               v38.m128_f32[0],
               surfaceThickness,
               (hkMassProperties *)&shift[16])->m_enum != HK_FAILURE )
        {
          *(__m128 *)(v7 + 16) = _mm_add_ps(_mm_mul_ps(*(__m128 *)&shift[8], v38), *(__m128 *)(v7 + 16));
          hkInertiaTensorComputer::shiftInertiaFromCom((hkVector4f *)&shift[8], (hkSimdFloat32 *)shift, &v52);
          hkMatrix3f::add((hkMatrix3f *)(v7 + 32), &v52);
        }
        ++v33;
        ++v35;
        if ( v33 >= geom->m_triangles.m_size )
          break;
        v14 = array;
      }
    }
    *(float *)(v7 + 4) = v55;
    *(__m128 *)(v7 + 16) = _mm_mul_ps(*(__m128 *)(v7 + 16), _mm_div_ps(query.m_quad, v13));
    hkInertiaTensorComputer::shiftInertiaToCom((hkVector4f *)(v7 + 16), &v53, (hkMatrix3f *)(v7 + 32));
    v45 = v50;
    result->m_enum = HK_SUCCESS;
    v49 = 0;
    if ( v45 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v45);
  }
  return result;
}

// File Line: 953
// RVA: 0xC9B510
hkResult *__fastcall hkInertiaTensorComputer::combineMassProperties(
        hkResult *result,
        hkArray<hkMassElement,hkContainerHeapAllocator> *elements,
        hkMassProperties *a3)
{
  int m_size; // r9d
  __m128 v6; // xmm6
  __m128 v7; // xmm5
  __m128 v8; // xmm7
  hkMassElement *m_data; // rax
  __int64 v10; // r11
  hkVector4f *p_m_centerOfMass; // rdx
  hkVector4f *p_m_col2; // rcx
  unsigned int *p_m_mass; // r10
  __m128 m_quad; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm0
  __m128 v17; // xmm3
  hkMatrix3f *p_m_inertiaTensor; // rbp
  int v19; // r15d
  hkVector4f v20; // xmm6
  __int64 v21; // rdi
  hkTransformf *p_m_transform; // rdx
  __int64 v23; // rbx
  hkVector4f v24; // xmm1
  __m128 m_mass_low; // xmm0
  __m128 v26; // xmm2
  hkSimdFloat32 mass; // [rsp+20h] [rbp-88h] BYREF
  hkVector4f shift; // [rsp+30h] [rbp-78h] BYREF
  hkMatrix3f inertia; // [rsp+40h] [rbp-68h] BYREF

  m_size = elements->m_size;
  v6 = 0i64;
  v7 = 0i64;
  v8 = 0i64;
  if ( m_size > 0 )
  {
    m_data = elements->m_data;
    v10 = (unsigned int)m_size;
    p_m_centerOfMass = &elements->m_data->m_properties.m_centerOfMass;
    p_m_col2 = &m_data->m_transform.m_rotation.m_col2;
    p_m_mass = (unsigned int *)&m_data->m_properties.m_mass;
    do
    {
      m_quad = p_m_centerOfMass->m_quad;
      v15 = (__m128)*p_m_mass;
      ++m_data;
      v16 = p_m_centerOfMass->m_quad;
      p_m_mass += 36;
      p_m_centerOfMass += 9;
      p_m_col2 += 9;
      v17 = _mm_shuffle_ps(v15, v15, 0);
      v7 = _mm_add_ps(v7, v17);
      v8 = _mm_add_ps(
             v8,
             _mm_shuffle_ps(
               (__m128)LODWORD(m_data[-1].m_properties.m_volume),
               (__m128)LODWORD(m_data[-1].m_properties.m_volume),
               0));
      v6 = _mm_add_ps(
             v6,
             _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 85), p_m_col2[-10].m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(v16, m_quad, 0), p_m_centerOfMass[-5].m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), p_m_col2[-9].m_quad)),
                 p_m_col2[-8].m_quad),
               v17));
      --v10;
    }
    while ( v10 );
  }
  if ( v7.m128_f32[0] > 0.0 )
  {
    p_m_inertiaTensor = &a3->m_inertiaTensor;
    v19 = 0;
    v20.m_quad = _mm_mul_ps(v6, _mm_div_ps(query.m_quad, v7));
    a3->m_centerOfMass = (hkVector4f)v20.m_quad;
    LODWORD(a3->m_mass) = v7.m128_i32[0];
    LODWORD(a3->m_volume) = v8.m128_i32[0];
    a3->m_inertiaTensor.m_col0 = 0i64;
    a3->m_inertiaTensor.m_col1 = 0i64;
    a3->m_inertiaTensor.m_col2 = 0i64;
    if ( elements->m_size > 0 )
    {
      v21 = 0i64;
      do
      {
        p_m_transform = &elements->m_data->m_transform;
        v23 = v19;
        inertia = elements->m_data[v21].m_properties.m_inertiaTensor;
        hkMatrix3f::changeBasis(&inertia, (hkRotationf *)((char *)&p_m_transform->m_rotation + v23 * 144));
        v24.m_quad = (__m128)elements->m_data[v21].m_properties.m_centerOfMass;
        m_mass_low = (__m128)LODWORD(elements->m_data[v23].m_properties.m_mass);
        v26 = _mm_sub_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(v24.m_quad, v24.m_quad, 85),
                        elements->m_data[v21].m_transform.m_rotation.m_col1.m_quad),
                      _mm_mul_ps(
                        _mm_shuffle_ps(v24.m_quad, v24.m_quad, 0),
                        elements->m_data[v21].m_transform.m_rotation.m_col0.m_quad)),
                    _mm_mul_ps(
                      _mm_shuffle_ps(v24.m_quad, v24.m_quad, 170),
                      elements->m_data[v21].m_transform.m_rotation.m_col2.m_quad)),
                  elements->m_data[v21].m_transform.m_translation.m_quad),
                v20.m_quad);
        mass.m_real = _mm_shuffle_ps(m_mass_low, m_mass_low, 0);
        shift.m_quad = v26;
        hkInertiaTensorComputer::shiftInertiaFromCom(&shift, &mass, &inertia);
        hkMatrix3f::add(p_m_inertiaTensor, &inertia);
        ++v19;
        ++v21;
      }
      while ( v19 < elements->m_size );
    }
    result->m_enum = HK_SUCCESS;
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 1019
// RVA: 0xC9B980
void __fastcall hkInertiaTensorComputer::shiftInertiaToCom(hkVector4f *shift, hkSimdFloat32 *mass, hkMatrix3f *inertia)
{
  __m128 v3; // xmm0
  __m128 v4; // xmm4
  __m128 v5; // xmm5

  v3 = _mm_mul_ps(shift->m_quad, shift->m_quad);
  v4 = _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(shift->m_quad, shift->m_quad, 201), shift->m_quad), mass->m_real);
  v5 = (__m128)_mm_srli_si128(
                 _mm_slli_si128(
                   (__m128i)_mm_mul_ps(
                              _mm_add_ps(_mm_shuffle_ps(v3, v3, 90), _mm_shuffle_ps(v3, v3, 65)),
                              _mm_sub_ps((__m128)0i64, mass->m_real)),
                   4),
                 4);
  inertia->m_col0.m_quad = _mm_add_ps(
                             _mm_or_ps(
                               _mm_andnot_ps((__m128)xmmword_141A78FE0, _mm_shuffle_ps(v4, v4, 160)),
                               _mm_and_ps((__m128)xmmword_141A78FE0, v5)),
                             inertia->m_col0.m_quad);
  inertia->m_col1.m_quad = _mm_add_ps(
                             _mm_or_ps(
                               _mm_andnot_ps((__m128)xmmword_141A78FF0, _mm_unpacklo_ps(v4, v4)),
                               _mm_and_ps((__m128)xmmword_141A78FF0, v5)),
                             inertia->m_col1.m_quad);
  inertia->m_col2.m_quad = _mm_add_ps(
                             _mm_or_ps(
                               _mm_andnot_ps((__m128)xmmword_141A79010, _mm_shuffle_ps(v4, v4, 230)),
                               _mm_and_ps((__m128)xmmword_141A79010, v5)),
                             inertia->m_col2.m_quad);
}

// File Line: 1056
// RVA: 0xC9BA30
void __fastcall hkInertiaTensorComputer::shiftInertiaFromCom(
        hkVector4f *shift,
        hkSimdFloat32 *mass,
        hkMatrix3f *inertia)
{
  hkSimdFloat32 massa; // [rsp+20h] [rbp-18h] BYREF

  massa.m_real = _mm_sub_ps((__m128)0i64, mass->m_real);
  hkInertiaTensorComputer::shiftInertiaToCom(shift, &massa, inertia);
}

// File Line: 1062
// RVA: 0xC9B750
void __fastcall hkInertiaTensorComputer::simplifyInertiaTensorToOrientedParticle(hkMatrix3f *inertia)
{
  __m128 v1; // xmm3
  __m128 v2; // xmm3

  v1 = _mm_or_ps(
         _mm_andnot_ps(
           (__m128)xmmword_141A78F90,
           _mm_or_ps(
             _mm_and_ps(inertia->m_col1.m_quad, (__m128)xmmword_141A78F70),
             _mm_andnot_ps((__m128)xmmword_141A78F70, inertia->m_col0.m_quad))),
         _mm_and_ps(inertia->m_col2.m_quad, (__m128)xmmword_141A78F90));
  v2 = _mm_max_ps(_mm_shuffle_ps(v1, v1, 170), _mm_max_ps(_mm_shuffle_ps(v1, v1, 85), _mm_shuffle_ps(v1, v1, 0)));
  inertia->m_col2.m_quad = _mm_mul_ps(stru_141A71280.m_quad, v2);
  inertia->m_col0.m_quad = _mm_mul_ps(transform.m_quad, v2);
  inertia->m_col1.m_quad = _mm_mul_ps(direction.m_quad, v2);
}

// File Line: 1192
// RVA: 0xC9BBA0
void __fastcall InternalInertiaTensorComputer::compProjectionIntegrals(
        InternalInertiaTensorComputer *this,
        hkVector4f *v)
{
  const int *v3; // r10
  hkVector4f *v4; // r8
  __m128 v5; // xmm4
  int m_C; // edx
  __m128 m_quad; // xmm14
  __m128 v8; // xmm3
  __m128 v9; // xmm14
  __m128 v10; // xmm15
  __m128 v11; // xmm2
  __m128 v12; // xmm12
  __m128 v13; // xmm15
  __m128 v14; // xmm5
  __m128 v15; // xmm6
  __m128 v16; // xmm1
  __m128 v17; // xmm13
  __m128 v18; // xmm7
  __m128 v19; // xmm0
  __m128 v20; // xmm9
  __m128 v21; // xmm11
  __m128 v22; // xmm10
  __m128 v23; // xmm4
  __m128 v24; // xmm3
  __m128 v25; // xmm0
  __m128 v26; // xmm8
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm6
  __m128 v33; // xmm4
  __m128 v34; // [rsp+30h] [rbp-B8h]

  v3 = InternalInertiaTensorComputer_mod3table;
  v4 = v;
  this->m_P1 = 0i64;
  this->m_Pab = 0i64;
  this->m_Paab = 0i64;
  this->m_Pabb = 0i64;
  this->m_P_a = 0i64;
  this->m_P_b = 0i64;
  v5 = (__m128)xmmword_141A710D0;
  do
  {
    m_C = this->m_C;
    m_quad = v4->m_quad;
    if ( this->m_C )
    {
      if ( m_C == 1 )
        m_quad = _mm_shuffle_ps(m_quad, m_quad, 210);
    }
    else
    {
      m_quad = _mm_shuffle_ps(m_quad, m_quad, 201);
    }
    v8 = _mm_shuffle_ps(m_quad, m_quad, 0);
    v9 = _mm_shuffle_ps(m_quad, m_quad, 85);
    v10 = v[*v3].m_quad;
    v34 = v8;
    if ( m_C )
    {
      if ( m_C == 1 )
        v10 = _mm_shuffle_ps(v10, v10, 210);
    }
    else
    {
      v10 = _mm_shuffle_ps(v10, v10, 201);
    }
    v11 = _mm_mul_ps(v8, v8);
    v12 = _mm_shuffle_ps(v10, v10, 0);
    v13 = _mm_shuffle_ps(v10, v10, 85);
    v14 = _mm_mul_ps(v11, v8);
    v15 = _mm_mul_ps(v12, v12);
    v16 = _mm_add_ps(v12, v8);
    v17 = _mm_sub_ps(v12, v8);
    v18 = _mm_sub_ps(v13, v9);
    v19 = _mm_mul_ps(_mm_mul_ps(v12, v5), v8);
    v20 = _mm_mul_ps(v9, v9);
    v21 = _mm_mul_ps(v20, v9);
    v22 = _mm_mul_ps(v13, v13);
    v23 = _mm_add_ps(_mm_mul_ps(v11, (__m128)xmmword_141A710E0), _mm_add_ps(v19, v15));
    v24 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v15, (__m128)xmmword_141A710E0), v19), v11);
    v25 = v16;
    v26 = _mm_mul_ps(v22, v13);
    v27 = _mm_add_ps(_mm_mul_ps(v16, v12), v11);
    this->m_P1.m_real = _mm_add_ps(_mm_mul_ps(v25, v18), this->m_P1.m_real);
    v28 = _mm_add_ps(_mm_mul_ps(v27, v12), v14);
    v29 = _mm_mul_ps(
            _mm_movelh_ps(
              _mm_unpacklo_ps(v27, v28),
              _mm_unpacklo_ps(_mm_add_ps(_mm_mul_ps(v11, v11), _mm_mul_ps(v28, v12)), (__m128)xmmword_141A710D0)),
            v18);
    v30 = _mm_add_ps(_mm_mul_ps(_mm_add_ps(v13, v9), v13), v20);
    this->m_P_a.m_quad = _mm_add_ps(v29, this->m_P_a.m_quad);
    v31 = _mm_add_ps(_mm_mul_ps(v30, v13), v21);
    this->m_P_b.m_quad = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_movelh_ps(
                               _mm_unpacklo_ps(v30, v31),
                               _mm_unpacklo_ps(
                                 _mm_add_ps(_mm_mul_ps(v20, v20), _mm_mul_ps(v31, v13)),
                                 (__m128)xmmword_141A710D0)),
                             v17),
                           this->m_P_b.m_quad);
    this->m_Pab.m_real = _mm_add_ps(
                           _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v23, v9), _mm_mul_ps(v24, v13)), v18),
                           this->m_Pab.m_real);
    ++v3;
    ++v4;
    v32 = _mm_add_ps(
            _mm_mul_ps(
              _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v15, v12), (__m128)xmmword_141A710F0), _mm_mul_ps(v24, v34)),
              v13),
            _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v23, v12), _mm_mul_ps(v14, (__m128)xmmword_141A710F0)), v9));
    v5 = (__m128)xmmword_141A710D0;
    this->m_Paab.m_real = _mm_add_ps(_mm_mul_ps(v32, v18), this->m_Paab.m_real);
    this->m_Pabb.m_real = _mm_add_ps(
                            _mm_mul_ps(
                              _mm_add_ps(
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(
                                        _mm_mul_ps(_mm_mul_ps(v22, (__m128)xmmword_141A710E0), v9),
                                        _mm_mul_ps(v26, (__m128)xmmword_141A710F0)),
                                      _mm_mul_ps(_mm_mul_ps(v13, (__m128)xmmword_141A710D0), v20)),
                                    v21),
                                  v12),
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v22, (__m128)xmmword_141A710D0), v9), v26),
                                      _mm_mul_ps(_mm_mul_ps(v13, (__m128)xmmword_141A710E0), v20)),
                                    _mm_mul_ps(v21, (__m128)xmmword_141A710F0)),
                                  v34)),
                              v17),
                            this->m_Pabb.m_real);
  }
  while ( (__int64)v3 < (__int64)&InternalInertiaTensorComputer_mod3table[3] );
  v33 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_016666668), (__m128)LODWORD(FLOAT_0_016666668), 0);
  this->m_P1.m_real = _mm_mul_ps(this->m_P1.m_real, (__m128)xmmword_141A711B0);
  this->m_P_a.m_quad = _mm_mul_ps(*(__m128 *)scaleConst, this->m_P_a.m_quad);
  this->m_P_b.m_quad = _mm_mul_ps(
                         _mm_xor_ps(
                           (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                           *(__m128 *)scaleConst),
                         this->m_P_b.m_quad);
  this->m_Pab.m_real = _mm_mul_ps(
                         _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_041666668), (__m128)LODWORD(FLOAT_0_041666668), 0),
                         this->m_Pab.m_real);
  this->m_Paab.m_real = _mm_mul_ps(v33, this->m_Paab.m_real);
  this->m_Pabb.m_real = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v33), this->m_Pabb.m_real);
}

// File Line: 1279
// RVA: 0xC9BF30
void __fastcall InternalInertiaTensorComputer::compFaceIntegrals(
        InternalInertiaTensorComputer *this,
        hkVector4f *v,
        hkVector4f *n)
{
  __m128 m_quad; // xmm12
  __m128 v7; // xmm2
  __m128 v8; // xmm9
  hkVector4f v9; // xmm4
  hkVector4f v10; // xmm15
  __m128 v11; // xmm5
  __m128 v12; // xmm1
  __m128 v13; // xmm11
  __m128 v14; // xmm0
  __m128 v15; // xmm13
  __m128 v16; // xmm14
  __m128 v17; // xmm6
  hkVector4f v18; // xmm0
  __m128 v19; // xmm4
  __m128 v20; // xmm1
  hkSimdFloat32 v21; // xmm12
  hkSimdFloat32 v22; // xmm3
  __m128 v23; // xmm9
  __m128 v24; // xmm7
  __m128 v25; // xmm13
  hkSimdFloat32 v26; // xmm10
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // [rsp+20h] [rbp-138h]
  __m128 v31; // [rsp+30h] [rbp-128h]
  __m128 v32; // [rsp+40h] [rbp-118h]
  __m128 v33; // [rsp+50h] [rbp-108h]
  __m128 v34; // [rsp+60h] [rbp-F8h]
  __m128 v35; // [rsp+70h] [rbp-E8h]
  __m128 v36; // [rsp+90h] [rbp-C8h]
  __m128 v37; // [rsp+A0h] [rbp-B8h]

  InternalInertiaTensorComputer::compProjectionIntegrals(this, v);
  m_quad = n->m_quad;
  v7 = _mm_mul_ps(n->m_quad, v->m_quad);
  v8 = _mm_sub_ps(
         (__m128)0i64,
         _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170)));
  v30 = v8;
  if ( this->m_C )
  {
    if ( this->m_C == 1 )
      m_quad = _mm_shuffle_ps(m_quad, m_quad, 210);
  }
  else
  {
    m_quad = _mm_shuffle_ps(m_quad, m_quad, 201);
  }
  v9.m_quad = (__m128)this->m_P_a;
  v10.m_quad = (__m128)this->m_P_b;
  v11 = _mm_mul_ps(this->m_P1.m_real, v8);
  v35 = _mm_shuffle_ps(m_quad, m_quad, 0);
  v37 = _mm_div_ps(query.m_quad, _mm_shuffle_ps(m_quad, m_quad, 170));
  v12 = _mm_mul_ps(v37, v37);
  v13 = _mm_sub_ps((__m128)0i64, v12);
  v36 = v12;
  v32 = _mm_mul_ps(v37, v12);
  v14 = _mm_mul_ps(m_quad, m_quad);
  v34 = _mm_shuffle_ps(m_quad, m_quad, 85);
  v15 = _mm_mul_ps(v10.m_quad, v34);
  v16 = _mm_mul_ps(_mm_mul_ps((__m128)xmmword_141A710D0, v35), v34);
  v17 = _mm_shuffle_ps(v14, v14, 0);
  v31 = _mm_shuffle_ps(v14, v14, 85);
  v18.m_quad = _mm_mul_ps(v37, v9.m_quad);
  v19 = _mm_mul_ps(v9.m_quad, v35);
  v20 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v34);
  v21.m_real = (__m128)this->m_Paab;
  this->m_F_a = (hkVector4f)v18.m_quad;
  v22.m_real = (__m128)this->m_Pab;
  v23 = _mm_shuffle_ps(v19, v19, 85);
  this->m_F_b.m_quad = _mm_mul_ps(v37, v10.m_quad);
  v24 = _mm_add_ps(_mm_shuffle_ps(v15, v15, 0), _mm_shuffle_ps(v19, v19, 0));
  v33 = _mm_shuffle_ps(v19, v19, 170);
  v25 = _mm_shuffle_ps(v15, v15, 170);
  v26.m_real = (__m128)this->m_Pabb;
  v27 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v22.m_real, v16), _mm_mul_ps(v23, v35)), v20);
  this->m_Faab.m_real = _mm_mul_ps(v37, v21.m_real);
  v28 = _mm_mul_ps(this->m_Pab.m_real, v34);
  v29 = _mm_shuffle_ps(this->m_P_a.m_quad, this->m_P_a.m_quad, 0);
  this->m_F_c.m_quad = _mm_movelh_ps(
                         _mm_unpacklo_ps(
                           _mm_mul_ps(_mm_add_ps(v11, v24), v13),
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v24, (__m128)xmmword_141A710D0), v11), v30),
                               v27),
                             v32)),
                         _mm_unpacklo_ps(
                           _mm_mul_ps(
                             _mm_add_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_mul_ps(_mm_mul_ps((__m128)xmmword_141A710E0, v17), v34),
                                         v21.m_real),
                                       _mm_mul_ps(v33, v17)),
                                     _mm_mul_ps(_mm_mul_ps(_mm_mul_ps((__m128)xmmword_141A710E0, v35), v31), v26.m_real)),
                                   _mm_mul_ps(v25, v31)),
                                 _mm_mul_ps(_mm_mul_ps((__m128)xmmword_141A710E0, v30), v27)),
                               _mm_mul_ps(
                                 _mm_add_ps(_mm_mul_ps(v24, (__m128)xmmword_141A710E0), v11),
                                 _mm_mul_ps(v30, v30))),
                             _mm_sub_ps((__m128)0i64, _mm_mul_ps(v36, v36))),
                           (__m128)xmmword_141A710D0));
  this->m_Fbbc.m_real = _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v10.m_quad, v10.m_quad, 85), v30),
                            _mm_add_ps(_mm_mul_ps(v26.m_real, v35), v25)),
                          v13);
  this->m_Fcca.m_real = _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_add_ps(v28, v23), (__m128)xmmword_141A710D0),
                                _mm_mul_ps(v29, v30)),
                              v30),
                            _mm_add_ps(
                              _mm_add_ps(_mm_mul_ps(v21.m_real, v16), _mm_mul_ps(v33, v35)),
                              _mm_mul_ps(v26.m_real, v31))),
                          v32);
}

// File Line: 1320
// RVA: 0xC9C280
void __fastcall InternalInertiaTensorComputer::compVolumeIntegrals(
        InternalInertiaTensorComputer *this,
        hkGeometry *geom,
        hkVector4f *shift)
{
  __int64 m_size; // rax
  __int64 v7; // rsi
  __int64 v8; // rdi
  hkGeometry::Triangle *m_data; // rcx
  __m128 m_quad; // xmm0
  hkVector4f *v11; // rdx
  __m128 v12; // xmm3
  __int64 m_c; // rax
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm6
  __m128 v18; // xmm6
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm6
  __m128 v22; // xmm3
  hkVector4f v23; // xmm1
  hkVector4f v24; // xmm0
  __m128 v25; // xmm2
  unsigned __int64 v26; // rcx
  __m128 v27; // xmm3
  hkVector4f v28; // xmm0
  __m128 v29; // xmm0
  __m128 v30; // xmm1
  int v31; // eax
  hkVector4f v32; // xmm0
  hkVector4f v33; // xmm0
  hkSimdFloat32 v34; // xmm0
  __m128 v35; // xmm1
  hkVector4f n; // [rsp+20h] [rbp-78h] BYREF
  hkVector4f v; // [rsp+30h] [rbp-68h] BYREF
  __m128 v38; // [rsp+40h] [rbp-58h]
  __m128 v39; // [rsp+50h] [rbp-48h]

  m_size = geom->m_triangles.m_size;
  this->m_T0 = 0i64;
  this->m_T1 = 0i64;
  this->m_T2 = 0i64;
  v7 = m_size;
  this->m_TP = 0i64;
  if ( (int)m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      m_data = geom->m_triangles.m_data;
      m_quad = shift->m_quad;
      v11 = geom->m_vertices.m_data;
      v12 = v11[m_data[v8].m_b].m_quad;
      m_c = m_data[v8].m_c;
      v.m_quad = _mm_add_ps(v11[m_data[v8].m_a].m_quad, shift->m_quad);
      v14 = v11[m_c].m_quad;
      v38 = _mm_add_ps(v12, m_quad);
      v15 = _mm_sub_ps(v38, v.m_quad);
      v39 = _mm_add_ps(v14, m_quad);
      v16 = _mm_sub_ps(v39, v.m_quad);
      v17 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v15), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v16));
      v18 = _mm_shuffle_ps(v17, v17, 201);
      v19 = _mm_mul_ps(v18, v18);
      v20 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
              _mm_shuffle_ps(v19, v19, 170));
      if ( v20.m128_f32[0] > 0.0 )
      {
        v21 = _mm_mul_ps(v18, _mm_div_ps(query.m_quad, _mm_sqrt_ps(v20)));
        n.m_quad = v21;
        v22 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v21, 1u), 1u);
        this->m_C = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                           _mm_and_ps(
                                                                             _mm_cmple_ps(
                                                                               _mm_max_ps(
                                                                                 _mm_shuffle_ps(v22, v22, 170),
                                                                                 _mm_max_ps(
                                                                                   _mm_shuffle_ps(v22, v22, 85),
                                                                                   _mm_shuffle_ps(v22, v22, 0))),
                                                                               v22),
                                                                             (__m128)xmmword_141A78FC0))];
        InternalInertiaTensorComputer::compFaceIntegrals(this, &v, &n);
        v23.m_quad = (__m128)this->m_F_c;
        v24.m_quad = (__m128)this->m_F_b;
        v25 = _mm_unpacklo_ps(this->m_F_a.m_quad, v24.m_quad);
        v26 = 16i64 * this->m_C;
        v27 = _mm_unpackhi_ps(this->m_F_a.m_quad, v24.m_quad);
        v28.m_quad = _mm_movelh_ps(v25, v23.m_quad);
        this->m_F_a = (hkVector4f)v28.m_quad;
        this->m_F_c.m_quad = _mm_shuffle_ps(v27, v23.m_quad, 228);
        this->m_F_b.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v28.m_quad, v25), v23.m_quad, 212);
        v29 = _mm_and_ps((__m128)xmmword_141687F20[v26 / 0xFFFFFFFFFFFFFFF0ui64], this->m_F_a.m_quad);
        v30 = _mm_or_ps(_mm_shuffle_ps(v29, v29, 78), v29);
        this->m_T0.m_real = _mm_add_ps(
                              _mm_mul_ps(_mm_or_ps(_mm_shuffle_ps(v30, v30, 177), v30), _mm_shuffle_ps(v21, v21, 0)),
                              this->m_T0.m_real);
        v31 = this->m_C;
        v32.m_quad = (__m128)this->m_F_b;
        if ( this->m_C )
        {
          if ( v31 == 1 )
            v32.m_quad = _mm_shuffle_ps(v32.m_quad, v32.m_quad, 201);
        }
        else
        {
          v32.m_quad = _mm_shuffle_ps(v32.m_quad, v32.m_quad, 210);
        }
        this->m_T1.m_quad = _mm_add_ps(_mm_mul_ps(v32.m_quad, v21), this->m_T1.m_quad);
        v33.m_quad = (__m128)this->m_F_c;
        if ( v31 )
        {
          if ( v31 == 1 )
            v33.m_quad = _mm_shuffle_ps(v33.m_quad, v33.m_quad, 201);
        }
        else
        {
          v33.m_quad = _mm_shuffle_ps(v33.m_quad, v33.m_quad, 210);
        }
        this->m_T2.m_quad = _mm_add_ps(_mm_mul_ps(v33.m_quad, v21), this->m_T2.m_quad);
        if ( v31 )
        {
          if ( v31 == 1 )
          {
            v34.m_real = (__m128)this->m_Faab;
            v35 = _mm_unpacklo_ps(this->m_Fbbc.m_real, this->m_Fcca.m_real);
          }
          else
          {
            v34.m_real = (__m128)this->m_Fcca;
            v35 = _mm_unpacklo_ps(this->m_Faab.m_real, this->m_Fbbc.m_real);
          }
        }
        else
        {
          v34.m_real = (__m128)this->m_Fbbc;
          v35 = _mm_unpacklo_ps(this->m_Fcca.m_real, this->m_Faab.m_real);
        }
        this->m_TP.m_quad = _mm_add_ps(
                              _mm_mul_ps(_mm_movelh_ps(v35, _mm_unpacklo_ps(v34.m_real, v34.m_real)), v21),
                              this->m_TP.m_quad);
      }
      ++v8;
      --v7;
    }
    while ( v7 );
  }
  this->m_T1.m_quad = _mm_mul_ps(this->m_T1.m_quad, (__m128)xmmword_141A711B0);
  this->m_T2.m_quad = _mm_mul_ps((__m128)xmmword_141A711C0, this->m_T2.m_quad);
  this->m_TP.m_quad = _mm_mul_ps(this->m_TP.m_quad, (__m128)xmmword_141A711B0);
}

// File Line: 1392
// RVA: 0xC9BAA0
void __fastcall InternalInertiaTensorComputer::computeInertialTensorInternal(
        InternalInertiaTensorComputer *this,
        hkSimdFloat32 *mass,
        hkSimdFloat32 *density,
        hkVector4f *r,
        hkMatrix3f *J)
{
  __m128 v5; // xmm5
  __m128 v6; // xmm1
  __m128 v7; // xmm7
  __m128 v8; // xmm6

  v5 = _mm_mul_ps(this->m_T1.m_quad, _mm_div_ps(query.m_quad, this->m_T0.m_real));
  *r = (hkVector4f)v5;
  v6 = _mm_mul_ps(v5, v5);
  v7 = (__m128)_mm_srli_si128(
                 _mm_slli_si128(
                   (__m128i)_mm_sub_ps(
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_shuffle_ps(this->m_T2.m_quad, this->m_T2.m_quad, 210),
                                  _mm_shuffle_ps(this->m_T2.m_quad, this->m_T2.m_quad, 201)),
                                density->m_real),
                              _mm_mul_ps(
                                _mm_add_ps(_mm_shuffle_ps(v6, v6, 90), _mm_shuffle_ps(v6, v6, 65)),
                                mass->m_real)),
                   4),
                 4);
  v8 = _mm_add_ps(
         _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v5, v5, 201), v5), mass->m_real),
         _mm_mul_ps(_mm_sub_ps((__m128)0i64, density->m_real), this->m_TP.m_quad));
  J->m_col0.m_quad = _mm_or_ps(
                       _mm_andnot_ps((__m128)xmmword_141A78FE0, _mm_shuffle_ps(v8, v8, 160)),
                       _mm_and_ps((__m128)xmmword_141A78FE0, v7));
  J->m_col1.m_quad = _mm_or_ps(
                       _mm_andnot_ps((__m128)xmmword_141A78FF0, _mm_unpacklo_ps(v8, v8)),
                       _mm_and_ps((__m128)xmmword_141A78FF0, v7));
  J->m_col2.m_quad = _mm_or_ps(
                       _mm_andnot_ps((__m128)xmmword_141A79010, _mm_shuffle_ps(v8, v8, 230)),
                       _mm_and_ps((__m128)xmmword_141A79010, v7));
}

// File Line: 1443
// RVA: 0xC9C5B0
void __fastcall InternalInertiaTensorComputer::compGeometryAabb(
        __m128 *vertices,
        unsigned int numVerts,
        int striding,
        hkVector4f *centerOut,
        hkVector4f *aabbExtentsOut)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm2
  __int64 v7; // rax
  __m128 v8; // xmm1
  __m128 v9; // xmm2

  *centerOut = 0i64;
  *aabbExtentsOut = 0i64;
  v5 = (__m128)xmmword_141A712A0;
  v6 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
  if ( (int)numVerts > 0 )
  {
    v7 = numVerts;
    do
    {
      v8 = *vertices;
      vertices = (__m128 *)((char *)vertices + striding);
      v6 = _mm_max_ps(v8, v6);
      v5 = _mm_min_ps(v8, v5);
      --v7;
    }
    while ( v7 );
  }
  if ( numVerts )
  {
    v9 = _mm_sub_ps(v6, v5);
    centerOut->m_quad = _mm_add_ps(_mm_mul_ps(v9, (__m128)xmmword_141A711B0), v5);
    *aabbExtentsOut = (hkVector4f)v9;
  }
}

// File Line: 1468
// RVA: 0xC9AED0
void __fastcall hkInertiaTensorComputer::computeGeometryVolumeMassProperties(
        hkGeometry *geom,
        float mass,
        hkMassProperties *result)
{
  __m128 v3; // xmm0
  int m_size; // edx
  hkVector4f *m_data; // rcx
  __m128 v7; // xmm0
  __m128 v9; // xmm6
  __m128 v10; // xmm6
  __m128 m_quad; // xmm10
  __m128 v12; // xmm1
  float m_volume; // xmm0_4
  float m_mass; // xmm1_4
  hkVector4f v15; // xmm1
  hkVector4f v16; // xmm0
  hkVector4f v17; // xmm8
  __m128 v18; // xmm6
  __m128 v19; // xmm2
  __m128 v20; // xmm7
  __m128 v21; // xmm5
  __m128 v22; // xmm4
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  hkVector4f v25; // xmm3
  hkVector4f v26; // xmm2
  char v27; // al
  int v28; // xmm0_4
  int v29; // xmm1_4
  int v30; // xmm0_4
  int v31; // xmm1_4
  int v32; // xmm0_4
  int v33; // xmm1_4
  hkVector4f halfExtents; // [rsp+30h] [rbp-C8h] BYREF
  hkSimdFloat32 massa; // [rsp+40h] [rbp-B8h] BYREF
  hkVector4f centerOut; // [rsp+50h] [rbp-A8h] BYREF
  hkMassProperties resulta; // [rsp+60h] [rbp-98h] BYREF
  __int128 v38; // [rsp+178h] [rbp+80h]
  void *retaddr; // [rsp+218h] [rbp+120h] BYREF

  m_size = geom->m_vertices.m_size;
  v3.m128_f32[0] = mass;
  m_data = geom->m_vertices.m_data;
  v7 = _mm_shuffle_ps(v3, v3, 0);
  v9 = _mm_cmple_ps(v7, (__m128)0i64);
  v10 = _mm_or_ps(_mm_andnot_ps(v9, v7), _mm_and_ps(v9, query.m_quad));
  massa.m_real = v10;
  InternalInertiaTensorComputer::compGeometryAabb(m_data->m_quad.m128_f32, m_size, 16, &centerOut, &halfExtents);
  memset(&resulta.m_centerOfMass, 0, 56);
  *(_QWORD *)&resulta.m_volume = 0i64;
  hkInertiaTensorComputer::computeBoxVolumeMassProperties((hkResult *)&retaddr, &halfExtents, v10.m128_f32[0], &resulta);
  m_quad = centerOut.m_quad;
  halfExtents.m_quad = _mm_xor_ps(
                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                         centerOut.m_quad);
  InternalInertiaTensorComputer::compVolumeIntegrals(
    (InternalInertiaTensorComputer *)&resulta.m_inertiaTensor.m_col2.m_quad.m128_u16[4],
    geom,
    &halfExtents);
  v12 = (__m128)v38;
  if ( *(float *)&v38 > 0.0 )
  {
    LODWORD(result->m_volume) = v38;
    LODWORD(result->m_mass) = v10.m128_i32[0];
    halfExtents.m_quad = _mm_div_ps(v10, v12);
    InternalInertiaTensorComputer::computeInertialTensorInternal(
      (InternalInertiaTensorComputer *)&resulta.m_inertiaTensor.m_col2.m_quad.m128_u16[4],
      &massa,
      (hkSimdFloat32 *)&halfExtents,
      &result->m_centerOfMass,
      &result->m_inertiaTensor);
    v17.m_quad = _mm_add_ps(result->m_centerOfMass.m_quad, m_quad);
    result->m_centerOfMass = (hkVector4f)v17.m_quad;
    v18 = _mm_or_ps(
            _mm_andnot_ps(
              (__m128)xmmword_141A78F90,
              _mm_or_ps(
                _mm_andnot_ps((__m128)xmmword_141A78F70, result->m_inertiaTensor.m_col0.m_quad),
                _mm_and_ps(result->m_inertiaTensor.m_col1.m_quad, (__m128)xmmword_141A78F70))),
            _mm_and_ps((__m128)xmmword_141A78F90, result->m_inertiaTensor.m_col2.m_quad));
    *(float *)&retaddr = FLOAT_0_1;
    v19 = _mm_mul_ps(
            _mm_or_ps(
              _mm_andnot_ps(
                (__m128)xmmword_141A78F90,
                _mm_or_ps(
                  _mm_andnot_ps((__m128)xmmword_141A78F70, *(__m128 *)((char *)&resulta.m_centerOfMass.m_quad + 8)),
                  _mm_and_ps(*(__m128 *)((char *)&resulta.m_inertiaTensor.m_col0.m_quad + 8), (__m128)xmmword_141A78F70))),
              _mm_and_ps(*(__m128 *)((char *)&resulta.m_inertiaTensor.m_col1.m_quad + 8), (__m128)xmmword_141A78F90)),
            _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1), 0));
    v20 = _mm_cmplt_ps(v18, v19);
    v21 = _mm_or_ps(_mm_and_ps(v20, v19), _mm_andnot_ps(v20, v18));
    result->m_centerOfMass.m_quad = _mm_or_ps(_mm_andnot_ps(v20, v17.m_quad), _mm_and_ps(v20, m_quad));
    v22 = result->m_inertiaTensor.m_col0.m_quad;
    v22.m128_f32[0] = v21.m128_f32[0];
    v23 = _mm_andnot_ps((__m128)xmmword_141A78F70, result->m_inertiaTensor.m_col1.m_quad);
    v24 = _mm_andnot_ps((__m128)xmmword_141A78F90, result->m_inertiaTensor.m_col2.m_quad);
    result->m_inertiaTensor.m_col0.m_quad = v22;
    v25.m_quad = _mm_or_ps(v23, _mm_and_ps((__m128)xmmword_141A78F70, v21));
    v26.m_quad = _mm_or_ps(v24, _mm_and_ps((__m128)xmmword_141A78F90, v21));
    result->m_inertiaTensor.m_col1 = (hkVector4f)v25.m_quad;
    result->m_inertiaTensor.m_col2 = (hkVector4f)v26.m_quad;
    massa.m_real = _mm_max_ps((__m128)0i64, v22);
    centerOut.m_quad = _mm_max_ps((__m128)0i64, v25.m_quad);
    halfExtents.m_quad = _mm_max_ps((__m128)0i64, v26.m_quad);
    v27 = _mm_movemask_ps(v20);
    if ( (v27 & 1) != 0 )
    {
      v28 = massa.m_real.m128_i32[1];
      v29 = massa.m_real.m128_i32[2];
      result->m_inertiaTensor.m_col1.m_quad.m128_i32[0] = massa.m_real.m128_i32[1];
      result->m_inertiaTensor.m_col0.m_quad.m128_i32[1] = v28;
      result->m_inertiaTensor.m_col2.m_quad.m128_i32[0] = v29;
      result->m_inertiaTensor.m_col0.m_quad.m128_i32[2] = v29;
    }
    if ( (v27 & 2) != 0 )
    {
      v30 = centerOut.m_quad.m128_i32[0];
      v31 = centerOut.m_quad.m128_i32[2];
      result->m_inertiaTensor.m_col0.m_quad.m128_i32[1] = centerOut.m_quad.m128_i32[0];
      result->m_inertiaTensor.m_col1.m_quad.m128_i32[0] = v30;
      result->m_inertiaTensor.m_col2.m_quad.m128_i32[1] = v31;
      result->m_inertiaTensor.m_col1.m_quad.m128_i32[2] = v31;
    }
    if ( (v27 & 4) != 0 )
    {
      v32 = halfExtents.m_quad.m128_i32[0];
      v33 = halfExtents.m_quad.m128_i32[1];
      result->m_inertiaTensor.m_col0.m_quad.m128_i32[2] = halfExtents.m_quad.m128_i32[0];
      result->m_inertiaTensor.m_col2.m_quad.m128_i32[0] = v32;
      result->m_inertiaTensor.m_col1.m_quad.m128_i32[2] = v33;
      result->m_inertiaTensor.m_col2.m_quad.m128_i32[1] = v33;
    }
  }
  else
  {
    m_volume = resulta.m_volume;
    m_mass = resulta.m_mass;
    result->m_centerOfMass.m_quad = m_quad;
    result->m_volume = m_volume;
    result->m_mass = m_mass;
    v15.m_quad = *(__m128 *)((char *)&resulta.m_inertiaTensor.m_col0 + 8);
    result->m_inertiaTensor.m_col0 = *(hkVector4f *)((char *)&resulta.m_centerOfMass + 8);
    v16.m_quad = *(__m128 *)((char *)&resulta.m_inertiaTensor.m_col1 + 8);
    result->m_inertiaTensor.m_col1 = (hkVector4f)v15.m_quad;
    result->m_inertiaTensor.m_col2 = (hkVector4f)v16.m_quad;
  }
}

// File Line: 1565
// RVA: 0xC9B200
hkResult *__fastcall hkInertiaTensorComputer::computeGeometryVolumeMassPropertiesChecked(
        hkResult *result,
        hkGeometry *geom,
        float mass,
        hkMassProperties *a4)
{
  __m128 v4; // xmm6
  __m128 v8; // xmm6
  __m128 m_quad; // xmm10
  __m128 v11; // xmm6
  hkVector4f v12; // xmm8
  __m128 v13; // xmm6
  __m128 v14; // xmm2
  __m128 v15; // xmm7
  char v16; // al
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  hkVector4f v21; // xmm3
  hkVector4f v22; // xmm2
  int v23; // xmm0_4
  int v24; // xmm1_4
  int v25; // xmm0_4
  int v26; // xmm1_4
  int v27; // xmm0_4
  int v28; // xmm1_4
  hkResult resulta; // [rsp+30h] [rbp-C8h] BYREF
  hkVector4f halfExtents; // [rsp+40h] [rbp-B8h] BYREF
  hkVector4f centerOut; // [rsp+50h] [rbp-A8h] BYREF
  hkSimdFloat32 massa; // [rsp+60h] [rbp-98h] BYREF
  hkMassProperties v33; // [rsp+70h] [rbp-88h] BYREF
  __m128 v34; // [rsp+188h] [rbp+90h]

  v4.m128_f32[0] = mass;
  v8 = _mm_shuffle_ps(v4, v4, 0);
  massa.m_real = v8;
  if ( v8.m128_f32[0] > 0.0 )
  {
    InternalInertiaTensorComputer::compGeometryAabb(
      geom->m_vertices.m_data->m_quad.m128_f32,
      geom->m_vertices.m_size,
      16,
      &centerOut,
      &halfExtents);
    memset(&v33, 0, 72);
    hkInertiaTensorComputer::computeBoxVolumeMassProperties(&resulta, &halfExtents, mass, &v33);
    m_quad = centerOut.m_quad;
    halfExtents.m_quad = _mm_xor_ps(
                           (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                           centerOut.m_quad);
    InternalInertiaTensorComputer::compVolumeIntegrals(
      (InternalInertiaTensorComputer *)&v33.m_inertiaTensor.m_col2.m_quad.m128_u16[4],
      geom,
      &halfExtents);
    if ( v34.m128_f32[0] > 0.0 )
    {
      v11 = _mm_div_ps(v8, v34);
      LODWORD(a4->m_volume) = v34.m128_i32[0];
      a4->m_mass = mass;
      halfExtents.m_quad = v11;
      InternalInertiaTensorComputer::computeInertialTensorInternal(
        (InternalInertiaTensorComputer *)&v33.m_inertiaTensor.m_col2.m_quad.m128_u16[4],
        &massa,
        (hkSimdFloat32 *)&halfExtents,
        &a4->m_centerOfMass,
        &a4->m_inertiaTensor);
      v12.m_quad = _mm_add_ps(m_quad, a4->m_centerOfMass.m_quad);
      a4->m_centerOfMass = (hkVector4f)v12.m_quad;
      v13 = _mm_or_ps(
              _mm_andnot_ps(
                (__m128)xmmword_141A78F90,
                _mm_or_ps(
                  _mm_andnot_ps((__m128)xmmword_141A78F70, a4->m_inertiaTensor.m_col0.m_quad),
                  _mm_and_ps(a4->m_inertiaTensor.m_col1.m_quad, (__m128)xmmword_141A78F70))),
              _mm_and_ps((__m128)xmmword_141A78F90, a4->m_inertiaTensor.m_col2.m_quad));
      resulta.m_enum = LODWORD(FLOAT_0_1);
      v14 = _mm_mul_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  (__m128)xmmword_141A78F90,
                  _mm_or_ps(
                    _mm_andnot_ps((__m128)xmmword_141A78F70, *(__m128 *)((char *)&v33.m_centerOfMass.m_quad + 8)),
                    _mm_and_ps(*(__m128 *)((char *)&v33.m_inertiaTensor.m_col0.m_quad + 8), (__m128)xmmword_141A78F70))),
                _mm_and_ps(*(__m128 *)((char *)&v33.m_inertiaTensor.m_col1.m_quad + 8), (__m128)xmmword_141A78F90)),
              _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1), 0));
      v15 = _mm_cmplt_ps(v13, v14);
      v16 = _mm_movemask_ps(v15);
      v17 = _mm_or_ps(_mm_and_ps(v15, v14), _mm_andnot_ps(v15, v13));
      a4->m_centerOfMass.m_quad = _mm_or_ps(_mm_and_ps(v15, m_quad), _mm_andnot_ps(v15, v12.m_quad));
      v18 = a4->m_inertiaTensor.m_col0.m_quad;
      v18.m128_f32[0] = v17.m128_f32[0];
      v19 = _mm_andnot_ps((__m128)xmmword_141A78F70, a4->m_inertiaTensor.m_col1.m_quad);
      v20 = _mm_andnot_ps((__m128)xmmword_141A78F90, a4->m_inertiaTensor.m_col2.m_quad);
      a4->m_inertiaTensor.m_col0.m_quad = v18;
      v21.m_quad = _mm_or_ps(v19, _mm_and_ps((__m128)xmmword_141A78F70, v17));
      v22.m_quad = _mm_or_ps(v20, _mm_and_ps((__m128)xmmword_141A78F90, v17));
      a4->m_inertiaTensor.m_col1 = (hkVector4f)v21.m_quad;
      a4->m_inertiaTensor.m_col2 = (hkVector4f)v22.m_quad;
      massa.m_real = _mm_max_ps((__m128)0i64, v18);
      centerOut.m_quad = _mm_max_ps((__m128)0i64, v21.m_quad);
      halfExtents.m_quad = _mm_max_ps((__m128)0i64, v22.m_quad);
      if ( (v16 & 1) != 0 )
      {
        v23 = massa.m_real.m128_i32[1];
        v24 = massa.m_real.m128_i32[2];
        a4->m_inertiaTensor.m_col1.m_quad.m128_i32[0] = massa.m_real.m128_i32[1];
        a4->m_inertiaTensor.m_col0.m_quad.m128_i32[1] = v23;
        a4->m_inertiaTensor.m_col2.m_quad.m128_i32[0] = v24;
        a4->m_inertiaTensor.m_col0.m_quad.m128_i32[2] = v24;
      }
      if ( (v16 & 2) != 0 )
      {
        v25 = centerOut.m_quad.m128_i32[0];
        v26 = centerOut.m_quad.m128_i32[2];
        a4->m_inertiaTensor.m_col0.m_quad.m128_i32[1] = centerOut.m_quad.m128_i32[0];
        a4->m_inertiaTensor.m_col1.m_quad.m128_i32[0] = v25;
        a4->m_inertiaTensor.m_col2.m_quad.m128_i32[1] = v26;
        a4->m_inertiaTensor.m_col1.m_quad.m128_i32[2] = v26;
      }
      if ( (v16 & 4) != 0 )
      {
        v27 = halfExtents.m_quad.m128_i32[0];
        v28 = halfExtents.m_quad.m128_i32[1];
        a4->m_inertiaTensor.m_col0.m_quad.m128_i32[2] = halfExtents.m_quad.m128_i32[0];
        a4->m_inertiaTensor.m_col2.m_quad.m128_i32[0] = v27;
        a4->m_inertiaTensor.m_col1.m_quad.m128_i32[2] = v28;
        a4->m_inertiaTensor.m_col2.m_quad.m128_i32[1] = v28;
      }
      result->m_enum = HK_SUCCESS;
    }
    else
    {
      result->m_enum = HK_FAILURE;
    }
    return result;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}

// File Line: 1663
// RVA: 0xC98B70
void __fastcall hkMassProperties::scaleToMass(hkMassProperties *this, hkSimdFloat32 *newMass)
{
  __m128 m_mass_low; // xmm1
  hkMatrix3f *p_m_inertiaTensor; // rcx
  __m128 v4; // xmm0
  hkSimdFloat32 scale; // [rsp+20h] [rbp-18h] BYREF

  m_mass_low = (__m128)LODWORD(this->m_mass);
  p_m_inertiaTensor = &this->m_inertiaTensor;
  v4 = _mm_div_ps(newMass->m_real, _mm_shuffle_ps(m_mass_low, m_mass_low, 0));
  p_m_inertiaTensor[-1].m_col1.m_quad.m128_i32[1] = (int)*newMass;
  scale.m_real = v4;
  hkMatrix3f::mul(p_m_inertiaTensor, &scale);
}

// File Line: 1672
// RVA: 0xC98B40
void __fastcall hkMassProperties::scaleToDensity(hkMassProperties *this, hkSimdFloat32 *density)
{
  hkSimdFloat32 newMass; // [rsp+20h] [rbp-18h] BYREF

  newMass.m_real = _mm_mul_ps(
                     _mm_shuffle_ps((__m128)LODWORD(this->m_volume), (__m128)LODWORD(this->m_volume), 0),
                     density->m_real);
  hkMassProperties::scaleToMass(this, &newMass);
}

// File Line: 1682
// RVA: 0xC9A6D0
hkResult *__fastcall hkInertiaTensorComputer::computeApproximateConvexHullMassProperties(
        hkResult *result,
        hkStridedVertices *vertices,
        float radius,
        hkMassProperties *a4)
{
  __m128 v4; // xmm0
  __m128 m_quad; // xmm0
  hkResult *v8; // rax
  hkVector4f halfExtents; // [rsp+30h] [rbp-38h] BYREF
  hkVector4f centerOut; // [rsp+40h] [rbp-28h] BYREF

  InternalInertiaTensorComputer::compGeometryAabb(
    vertices->m_vertices,
    vertices->m_numVertices,
    vertices->m_striding,
    &centerOut,
    &halfExtents);
  v4.m128_f32[0] = radius;
  halfExtents.m_quad = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, halfExtents.m_quad), _mm_shuffle_ps(v4, v4, 0));
  hkInertiaTensorComputer::computeBoxVolumeMassProperties(result, &halfExtents, 1.0, a4);
  m_quad = centerOut.m_quad;
  v8 = result;
  a4->m_mass = 1.0;
  a4->m_centerOfMass.m_quad = m_quad;
  return v8;
}

// File Line: 1700
// RVA: 0xC9B7D0
void __fastcall hkInertiaTensorComputer::convertInertiaTensorToPrincipleAxis(
        hkMatrix3f *inertia,
        hkRotationf *principleAxisOut)
{
  __m128 v4; // xmm1
  __m128 v5; // xmm1
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  hkVector4f v8; // xmm5
  __m128 v9; // xmm5
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  hkVector4f v14; // xmm4
  __m128 v15; // xmm5
  __m128 v16; // xmm5
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  hkVector4f eigenVal; // [rsp+20h] [rbp-48h] BYREF

  hkMatrix3f::diagonalizeSymmetricApproximation(inertia, principleAxisOut, &eigenVal, 10);
  v4 = _mm_max_ps(eigenVal.m_quad, *(__m128 *)&epsilon);
  inertia->m_col0.m_quad = _mm_mul_ps(v4, transform.m_quad);
  inertia->m_col1.m_quad = _mm_mul_ps(v4, direction.m_quad);
  inertia->m_col2.m_quad = _mm_mul_ps(v4, stru_141A71280.m_quad);
  v5 = _mm_mul_ps(principleAxisOut->m_col0.m_quad, principleAxisOut->m_col0.m_quad);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v7 = _mm_rsqrt_ps(v6);
  v8.m_quad = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmple_ps(v6, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v7, v6), v7)),
                    _mm_mul_ps(*(__m128 *)_xmm, v7))),
                principleAxisOut->m_col0.m_quad);
  principleAxisOut->m_col0 = (hkVector4f)v8.m_quad;
  v9 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v8.m_quad, v8.m_quad, 201), principleAxisOut->m_col2.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(principleAxisOut->m_col2.m_quad, principleAxisOut->m_col2.m_quad, 201), v8.m_quad));
  v10 = _mm_shuffle_ps(v9, v9, 201);
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v14.m_quad = _mm_mul_ps(
                 _mm_andnot_ps(
                   _mm_cmple_ps(v12, (__m128)0i64),
                   _mm_mul_ps(
                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
                     _mm_mul_ps(*(__m128 *)_xmm, v13))),
                 v10);
  principleAxisOut->m_col1 = (hkVector4f)v14.m_quad;
  v15 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v14.m_quad, v14.m_quad, 201), principleAxisOut->m_col0.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(principleAxisOut->m_col0.m_quad, principleAxisOut->m_col0.m_quad, 201), v14.m_quad));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  principleAxisOut->m_col2.m_quad = _mm_mul_ps(
                                      _mm_andnot_ps(
                                        _mm_cmple_ps(v18, (__m128)0i64),
                                        _mm_mul_ps(
                                          _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                                          _mm_mul_ps(*(__m128 *)_xmm, v19))),
                                      v16);
}

