// File Line: 27
// RVA: 0xC9BA60
void __fastcall scaleMassProperties(hkSimdFloat32 *scale, hkMassProperties *massProperties)
{
  hkMassProperties *v2; // rbx
  float v3; // xmm6_4

  v2 = massProperties;
  v3 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(v2->m_mass), (__m128)LODWORD(v2->m_mass), 0))
     * scale->m_real.m128_f32[0];
  hkMatrix3f::mul(&massProperties->m_inertiaTensor, scale);
  v2->m_mass = v3;
}

// File Line: 38
// RVA: 0xC98BB0
hkResult *__usercall hkInertiaTensorComputer::computeSphereVolumeMassProperties@<rax>(hkResult *result@<rcx>, float radius@<xmm1>, float mass@<xmm2>, hkMassProperties *a4@<r9>, __m128 a5@<xmm3>, __m128 a6@<xmm4>)
{
  __m128 v6; // xmm4
  hkResult *v7; // rax
  __m128 v8; // xmm3
  __m128 v9; // xmm0

  a6.m128_f32[0] = mass;
  v6 = _mm_shuffle_ps(a6, a6, 0);
  if ( v6.m128_f32[0] <= 0.0 || (a5.m128_f32[0] = radius, v8 = _mm_shuffle_ps(a5, a5, 0), v8.m128_f32[0] <= 0.0) )
  {
    result->m_enum = 1;
    v7 = result;
  }
  else
  {
    result->m_enum = 0;
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
hkResult *__usercall hkInertiaTensorComputer::computeSphereSurfaceMassProperties@<rax>(hkResult *result@<rcx>, __int128 radius@<xmm1>, float mass@<xmm2>, __int64 surfaceThickness@<xmm3>, __m128 a5@<xmm0>, __m128 *a6@<xmm4>, hkMassProperties *resulta)
{
  __m128 v7; // xmm0
  hkResult *v8; // rsi
  hkResult *v9; // rax
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  __m128 v12; // xmm8
  __m128 v13; // xmm9
  __m128 v14; // xmm7
  __m128 *v15; // xmm4_8
  hkVector4f v16; // xmm0
  hkVector4f v17; // xmm1
  __m128 v18; // xmm0
  float v19; // xmm6_4
  hkResult v20; // [rsp+20h] [rbp-E0h]
  hkSimdFloat32 scale; // [rsp+30h] [rbp-D0h]
  hkMassProperties v22; // [rsp+40h] [rbp-C0h]
  hkMassProperties v23; // [rsp+90h] [rbp-70h]

  a5.m128_f32[0] = mass;
  v7 = _mm_shuffle_ps(a5, a5, 0);
  v8 = result;
  scale.m_real = v7;
  if ( v7.m128_f32[0] <= 0.0
    || (v7.m128_f32[0] = *(float *)&surfaceThickness,
        v10 = _mm_shuffle_ps((__m128)radius, (__m128)radius, 0),
        v11 = _mm_shuffle_ps(v7, v7, 0),
        v10.m128_f32[0] <= v11.m128_f32[0])
    || v11.m128_f32[0] <= 0.0 )
  {
    result->m_enum = 1;
    v9 = result;
  }
  else
  {
    *(_QWORD *)&v22.m_volume = 0i64;
    *(_QWORD *)&v23.m_volume = 0i64;
    v12 = _mm_sub_ps(v10, v11);
    v22.m_centerOfMass = 0i64;
    v22.m_inertiaTensor.m_col0 = 0i64;
    v22.m_inertiaTensor.m_col1 = 0i64;
    v13 = _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(v10, (__m128)xmmword_141A713E0), v10), v10);
    v22.m_inertiaTensor.m_col2 = 0i64;
    v23.m_centerOfMass = 0i64;
    v14 = _mm_mul_ps(_mm_mul_ps(_mm_mul_ps((__m128)xmmword_141A713E0, v12), v12), v12);
    v23.m_inertiaTensor.m_col0 = 0i64;
    v23.m_inertiaTensor.m_col1 = 0i64;
    v23.m_inertiaTensor.m_col2 = 0i64;
    if ( hkInertiaTensorComputer::computeSphereVolumeMassProperties(
           &v20,
           v10.m128_f32[0],
           v13.m128_f32[0],
           &v22,
           (__m128 *)surfaceThickness,
           a6)->m_enum == 1
      || hkInertiaTensorComputer::computeSphereVolumeMassProperties(
           &v20,
           v12.m128_f32[0],
           v14.m128_f32[0],
           &v23,
           (__m128 *)surfaceThickness,
           v15)->m_enum == 1 )
    {
      v8->m_enum = 1;
    }
    else
    {
      v16.m_quad = (__m128)v22.m_inertiaTensor.m_col0;
      v17.m_quad = (__m128)v22.m_inertiaTensor.m_col1;
      resulta->m_centerOfMass = 0i64;
      resulta->m_inertiaTensor.m_col0 = (hkVector4f)v16.m_quad;
      resulta->m_inertiaTensor.m_col2 = v22.m_inertiaTensor.m_col2;
      resulta->m_inertiaTensor.m_col1 = (hkVector4f)v17.m_quad;
      hkMatrix3f::sub(&resulta->m_inertiaTensor, &v23.m_inertiaTensor);
      v17.m_quad.m128_f32[0] = v22.m_volume - v23.m_volume;
      resulta->m_mass = v22.m_mass - v23.m_mass;
      LODWORD(resulta->m_volume) = v17.m_quad.m128_i32[0];
      v18 = _mm_div_ps(scale.m_real, _mm_sub_ps(v13, v14));
      v19 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(resulta->m_mass), (__m128)LODWORD(resulta->m_mass), 0))
          * v18.m128_f32[0];
      scale.m_real = v18;
      hkMatrix3f::mul(&resulta->m_inertiaTensor, &scale);
      resulta->m_mass = v19;
      v8->m_enum = 0;
    }
    v9 = v8;
  }
  return v9;
}

// File Line: 126
// RVA: 0xC99940
hkResult *__usercall hkInertiaTensorComputer::computeBoxSurfaceMassProperties@<rax>(hkResult *result@<rcx>, hkVector4f *halfExtents@<rdx>, float mass@<xmm2>, float surfaceThickness@<xmm3>, __m128 a5@<xmm0>, __m128 a6@<xmm1>, hkMassProperties *resulta)
{
  hkResult *v7; // rsi
  hkResult *v8; // rax
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm8
  __m128 v12; // xmm7
  hkVector4f v13; // xmm0
  hkVector4f v14; // xmm1
  __m128 v15; // xmm0
  float v16; // xmm6_4
  hkResult v17; // [rsp+20h] [rbp-E0h]
  hkSimdFloat32 scale; // [rsp+30h] [rbp-D0h]
  hkMassProperties v19; // [rsp+40h] [rbp-C0h]
  hkVector4f halfExtentsa; // [rsp+90h] [rbp-70h]
  hkMassProperties v21; // [rsp+A0h] [rbp-60h]

  a5.m128_f32[0] = mass;
  v7 = result;
  scale.m_real = _mm_shuffle_ps(a5, a5, 0);
  if ( scale.m_real.m128_f32[0] <= 0.0
    || (a6.m128_f32[0] = surfaceThickness,
        v9 = halfExtents->m_quad,
        v10 = _mm_shuffle_ps(a6, a6, 0),
        (_mm_movemask_ps(_mm_cmpltps(v10, halfExtents->m_quad)) & 7) != 7)
    || _mm_movemask_ps(_mm_cmpleps(v10, (__m128)0i64)) )
  {
    result->m_enum = 1;
    v8 = result;
  }
  else
  {
    *(_QWORD *)&v19.m_volume = 0i64;
    *(_QWORD *)&v21.m_volume = 0i64;
    v19.m_centerOfMass = 0i64;
    halfExtentsa.m_quad = _mm_sub_ps(v9, v10);
    v19.m_inertiaTensor.m_col0 = 0i64;
    v19.m_inertiaTensor.m_col1 = 0i64;
    v19.m_inertiaTensor.m_col2 = 0i64;
    v21.m_centerOfMass = 0i64;
    v21.m_inertiaTensor.m_col0 = 0i64;
    v21.m_inertiaTensor.m_col1 = 0i64;
    v11 = _mm_mul_ps(
            _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170)),
            (__m128)xmmword_141A71130);
    v21.m_inertiaTensor.m_col2 = 0i64;
    v12 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_shuffle_ps(halfExtentsa.m_quad, halfExtentsa.m_quad, 85),
                _mm_shuffle_ps(halfExtentsa.m_quad, halfExtentsa.m_quad, 0)),
              _mm_shuffle_ps(halfExtentsa.m_quad, halfExtentsa.m_quad, 170)),
            (__m128)xmmword_141A71130);
    if ( hkInertiaTensorComputer::computeBoxVolumeMassProperties(&v17, halfExtents, v11.m128_f32[0], &v19)->m_enum == 1
      || hkInertiaTensorComputer::computeBoxVolumeMassProperties(&v17, &halfExtentsa, v12.m128_f32[0], &v21)->m_enum == 1 )
    {
      v7->m_enum = 1;
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
      v16 = COERCE_FLOAT(_mm_shuffle_ps((__m128)LODWORD(resulta->m_mass), (__m128)LODWORD(resulta->m_mass), 0))
          * v15.m128_f32[0];
      scale.m_real = v15;
      hkMatrix3f::mul(&resulta->m_inertiaTensor, &scale);
      resulta->m_mass = v16;
      v7->m_enum = 0;
    }
    v8 = v7;
  }
  return v8;
}

// File Line: 184
// RVA: 0xC99B60
hkResult *__usercall hkInertiaTensorComputer::computeTriangleSurfaceMassProperties@<rax>(hkResult *result@<rcx>, hkVector4f *v0@<rdx>, hkVector4f *v1@<r8>, hkVector4f *v2@<r9>, __m128 a5@<xmm4>, float mass, float surfaceThickness, hkMassProperties *resulta)
{
  hkVector4f *v8; // rsi
  hkVector4f *v9; // r14
  hkVector4f *v10; // r15
  hkResult *v11; // rdi
  __m128 v12; // xmm4
  hkResult *v13; // rax
  __m128 v14; // xmm10
  __m128 v15; // xmm12
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
  int v44; // er9
  _DWORD *v45; // rax
  _DWORD *v46; // rax
  _DWORD *v47; // rax
  _DWORD *v48; // rax
  unsigned __int64 v49; // rax
  _DWORD *v50; // rax
  _DWORD *v51; // rax
  _DWORD *v52; // rax
  hkResult v53; // [rsp+30h] [rbp-D0h]
  hkMatrix3f inertia; // [rsp+40h] [rbp-C0h]
  hkMassProperties v55; // [rsp+70h] [rbp-90h]
  hkVector4f shift; // [rsp+C0h] [rbp-40h]
  hkSimdFloat32 v57; // [rsp+D0h] [rbp-30h]

  a5.m128_f32[0] = mass;
  v8 = v2;
  v9 = v1;
  v10 = v0;
  v11 = result;
  v12 = _mm_shuffle_ps(a5, a5, 0);
  v57.m_real = v12;
  if ( v12.m128_f32[0] > 0.0 )
  {
    v14 = _mm_shuffle_ps((__m128)LODWORD(surfaceThickness), (__m128)LODWORD(surfaceThickness), 0);
    if ( v14.m128_f32[0] >= 0.0 )
    {
      v53.m_enum = LODWORD(FLOAT_0_0000099999997);
      v15 = v1->m_quad;
      LODWORD(v16) = (unsigned __int128)_mm_shuffle_ps(
                                          (__m128)(unsigned int)v53.m_enum,
                                          (__m128)(unsigned int)v53.m_enum,
                                          0);
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
      LODWORD(v25) = (unsigned __int128)_mm_andnot_ps(_mm_cmpleps(v24, (__m128)0i64), _mm_sqrt_ps(v24));
      if ( v14.m128_f32[0] >= v16 )
      {
        if ( v25 >= v16 )
        {
          v55.m_centerOfMass = 0i64;
          v55.m_inertiaTensor.m_col0 = 0i64;
          *(_QWORD *)&v55.m_volume = 0i64;
          v38 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                  _mm_shuffle_ps(v23, v23, 170));
          v55.m_inertiaTensor.m_col1 = 0i64;
          v55.m_inertiaTensor.m_col2 = 0i64;
          v39 = _mm_mul_ps(v14, (__m128)xmmword_141A711B0);
          inertia.m_col0.m_quad.m128_i32[2] = 0x1FFFF;
          inertia.m_col0.m_quad.m128_u64[0] = (unsigned __int64)&hkGeometry::`vftable;
          inertia.m_col1.m_quad.m128_u64[0] = 0i64;
          v40 = _mm_rsqrt_ps(v38);
          inertia.m_col1.m_quad.m128_u64[1] = 0x8000000000000000i64;
          inertia.m_col2.m_quad.m128_u64[0] = 0i64;
          inertia.m_col2.m_quad.m128_u64[1] = 0x8000000000000000i64;
          v41 = _mm_mul_ps(
                  v22,
                  _mm_andnot_ps(
                    _mm_cmpleps(v38, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v40, v38), v40)),
                      _mm_mul_ps(*(__m128 *)_xmm, v40))));
          hkArrayUtil::_reserve(
            &v53,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &inertia.m_col1,
            6,
            16);
          inertia.m_col1.m_quad.m128_i32[2] = 6;
          v42 = _mm_mul_ps(v41, v39);
          v43 = _mm_mul_ps(_mm_sub_ps((__m128)0i64, v39), v41);
          *(__m128 *)inertia.m_col1.m_quad.m128_u64[0] = _mm_add_ps(v42, v10->m_quad);
          *(__m128 *)(inertia.m_col1.m_quad.m128_u64[0] + 16) = _mm_add_ps(v43, v10->m_quad);
          *(__m128 *)(inertia.m_col1.m_quad.m128_u64[0] + 32) = _mm_add_ps(v42, v9->m_quad);
          *(__m128 *)(inertia.m_col1.m_quad.m128_u64[0] + 48) = _mm_add_ps(v43, v9->m_quad);
          *(__m128 *)(inertia.m_col1.m_quad.m128_u64[0] + 64) = _mm_add_ps(v42, v8->m_quad);
          *(__m128 *)(inertia.m_col1.m_quad.m128_u64[0] + 80) = _mm_add_ps(v43, v8->m_quad);
          if ( (inertia.m_col2.m_quad.m128_i32[3] & 0x3FFFFFFF) < 8 )
          {
            v44 = 8;
            if ( 2 * (inertia.m_col2.m_quad.m128_i32[3] & 0x3FFFFFFF) > 8 )
              v44 = 2 * (inertia.m_col2.m_quad.m128_i32[3] & 0x3FFFFFFF);
            hkArrayUtil::_reserve(
              &v53,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &inertia.m_col2,
              v44,
              16);
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
          v28.m_quad = _mm_mul_ps(_mm_add_ps(_mm_add_ps(v17, v15), v18), (__m128)xmmword_141A711C0);
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
        v28.m_quad = _mm_mul_ps(_mm_add_ps(_mm_add_ps(v17, v15), v18), (__m128)xmmword_141A711C0);
        shift.m_quad = v28.m_quad;
        v29 = _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v28.m_quad, v28.m_quad), v27), _mm_mul_ps(v17, v17)),
                    _mm_mul_ps(v15, v15)),
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
                    _mm_mul_ps(_mm_shuffle_ps(v15, v15, 233), _mm_unpacklo_ps(v15, v15))),
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
      v11->m_enum = 0;
      resulta->m_mass = mass;
      resulta->m_inertiaTensor.m_col0.m_quad = v34;
      resulta->m_inertiaTensor.m_col1.m_quad = v33;
      resulta->m_inertiaTensor.m_col2.m_quad = v32;
      resulta->m_centerOfMass = (hkVector4f)v28.m_quad;
      resulta->m_volume = (float)(v25 * 0.5) * v14.m128_f32[0];
      v13 = v11;
    }
    else
    {
      v13 = result;
      result->m_enum = 1;
    }
  }
  else
  {
    v13 = result;
    result->m_enum = 1;
  }
  return v13;
}

// File Line: 383
// RVA: 0xC98C80
hkResult *__fastcall hkInertiaTensorComputer::computeBoxVolumeMassProperties(hkResult *result, hkVector4f *halfExtents, float mass, hkMassProperties *volume)
{
  hkMassProperties *v4; // rdi
  hkResult *v5; // rbx
  hkResult *v6; // rax
  __m128 v7; // xmm3
  __m128 v8; // xmm2
  hkVector4f inertiaDiagonal; // [rsp+30h] [rbp-18h]

  volume->m_mass = mass;
  v4 = volume;
  v5 = result;
  volume->m_centerOfMass = 0i64;
  inertiaDiagonal.m_quad = 0i64;
  hkInertiaTensorComputer::computeBoxVolumeMassPropertiesDiagonalized(
    result,
    halfExtents,
    mass,
    &inertiaDiagonal,
    &volume->m_volume);
  v6 = v5;
  v7 = _mm_mul_ps(direction.m_quad, inertiaDiagonal.m_quad);
  v8 = _mm_mul_ps(stru_141A71280.m_quad, inertiaDiagonal.m_quad);
  v4->m_inertiaTensor.m_col0.m_quad = _mm_mul_ps(transform.m_quad, inertiaDiagonal.m_quad);
  v4->m_inertiaTensor.m_col1.m_quad = v7;
  v4->m_inertiaTensor.m_col2.m_quad = v8;
  return v6;
}

// File Line: 396
// RVA: 0xC98D00
hkResult *__usercall hkInertiaTensorComputer::computeBoxVolumeMassPropertiesDiagonalized@<rax>(hkResult *result@<rcx>, hkVector4f *halfExtents@<rdx>, float mass@<xmm2>, hkVector4f *inertiaDiagonal@<r9>, __m128 a5@<xmm3>, float *volume)
{
  __m128 v6; // xmm3
  __m128 v8; // xmm0
  __m128 v9; // xmm0
  hkVector4f v10; // xmm1

  a5.m128_f32[0] = mass;
  v6 = _mm_shuffle_ps(a5, a5, 0);
  if ( v6.m128_f32[0] > 0.0 )
  {
    v8 = halfExtents->m_quad;
    result->m_enum = 0;
    v9 = _mm_mul_ps(v8, v8);
    v10.m_quad = _mm_mul_ps(
                   _mm_add_ps(_mm_shuffle_ps(v9, v9, 90), _mm_shuffle_ps(v9, v9, 65)),
                   _mm_mul_ps((__m128)xmmword_141A711C0, v6));
    *inertiaDiagonal = (hkVector4f)v10.m_quad;
    inertiaDiagonal->m_quad = _mm_shuffle_ps(v10.m_quad, _mm_unpackhi_ps(v10.m_quad, query.m_quad), 196);
    *volume = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(halfExtents->m_quad, halfExtents->m_quad, 85))
                            * COERCE_FLOAT(_mm_shuffle_ps(halfExtents->m_quad, halfExtents->m_quad, 0)))
                    * COERCE_FLOAT(_mm_shuffle_ps(halfExtents->m_quad, halfExtents->m_quad, 170)))
            * 8.0;
  }
  else
  {
    result->m_enum = 1;
  }
  return result;
}

// File Line: 419
// RVA: 0xC9A770
hkResult *__fastcall hkInertiaTensorComputer::computeVertexHullVolumeMassProperties(hkResult *result, const float *vertexIn, int striding, int numVertices, float mass, hkMassProperties *resulta)
{
  hkResult *v6; // rdi
  hkResult *v7; // rax
  hkResult v8; // [rsp+20h] [rbp-38h]
  hkStridedVertices vertices; // [rsp+28h] [rbp-30h]
  hkSimdFloat32 newMass; // [rsp+40h] [rbp-18h]

  v6 = result;
  newMass.m_real = _mm_shuffle_ps((__m128)LODWORD(mass), (__m128)LODWORD(mass), 0);
  if ( newMass.m_real.m128_f32[0] <= 0.0 || numVertices < 1 )
  {
    result->m_enum = 1;
    v7 = result;
  }
  else
  {
    vertices.m_numVertices = numVertices;
    vertices.m_vertices = vertexIn;
    vertices.m_striding = striding;
    hkInertiaTensorComputer::computeConvexHullMassProperties(&v8, &vertices, 0.0, resulta);
    hkMassProperties::scaleToMass(resulta, &newMass);
    v6->m_enum = v8.m_enum;
    v7 = v6;
  }
  return v7;
}

// File Line: 440
// RVA: 0xC9A800
hkResult *__usercall hkInertiaTensorComputer::computeVertexCloudMassProperties@<rax>(hkResult *result@<rcx>, const float *vertexIn@<rdx>, int striding@<r8d>, int numVertices@<r9d>, __m128 a5@<xmm5>, float mass, hkMassProperties *resulta)
{
  __int64 v7; // rdi
  __int64 v8; // rbp
  const float *v9; // rbx
  hkResult *v10; // rsi
  __m128 *v11; // rdx
  __m128 v12; // xmm6
  signed int v13; // er8
  __m128 v14; // xmm0
  __m128 v15; // xmm7
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
  __m128 *array; // [rsp+30h] [rbp-98h]
  int v38; // [rsp+38h] [rbp-90h]
  int v39; // [rsp+3Ch] [rbp-8Ch]
  hkResult v40; // [rsp+E8h] [rbp+20h]

  v7 = numVertices;
  v8 = striding;
  v9 = vertexIn;
  v10 = result;
  if ( numVertices > 0 )
  {
    v11 = 0i64;
    v12 = 0i64;
    v13 = 2147483648;
    array = 0i64;
    v38 = 0;
    v39 = 2147483648;
    v14 = 0i64;
    v14.m128_f32[0] = (float)(signed int)v7;
    v15 = _mm_div_ps(query.m_quad, _mm_shuffle_ps(v14, v14, 0));
    if ( numVertices > 0 )
    {
      hkArrayUtil::_reserve(&v40, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v7, 16);
      v13 = v39;
      v11 = array;
    }
    v38 = v7;
    v16 = v7;
    if ( (signed int)v7 > 0 )
    {
      v17 = 0i64;
      v18 = v7;
      do
      {
        v19 = (__m128)*((unsigned int *)v9 + 2);
        v20 = (__m128)*(unsigned __int64 *)v9;
        v9 = (const float *)((char *)v9 + v8);
        ++v17;
        v11[v17 - 1] = _mm_movelh_ps(v20, v19);
        array[v17 - 1] = (__m128)_mm_srli_si128(_mm_slli_si128(_mm_load_si128((const __m128i *)&array[v17 - 1]), 4), 4);
        v11 = array;
        --v18;
      }
      while ( v18 );
      v13 = v39;
    }
    v21 = resulta;
    a5.m128_f32[0] = mass;
    resulta->m_mass = mass;
    v21->m_centerOfMass = 0i64;
    v22 = _mm_mul_ps(_mm_shuffle_ps(a5, a5, 0), v15);
    if ( (signed int)v7 > 0 )
    {
      v23 = 0i64;
      v24 = v11;
      v25 = v7;
      do
      {
        v23 = _mm_add_ps(v23, *v24);
        ++v24;
        v21->m_centerOfMass.m_quad = v23;
        --v25;
      }
      while ( v25 );
    }
    v26 = _mm_mul_ps(v15, v21->m_centerOfMass.m_quad);
    v27 = 0i64;
    v28 = 0i64;
    v21->m_centerOfMass.m_quad = v26;
    if ( (signed int)v7 > 0 )
    {
      v29 = v11;
      v30 = _mm_sub_ps((__m128)0i64, v22);
      do
      {
        v31 = *v29;
        ++v29;
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
        v12 = _mm_add_ps(
                v12,
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
    v21->m_inertiaTensor.m_col0.m_quad = v12;
    v10->m_enum = 0;
    v38 = 0;
    v21->m_inertiaTensor.m_col1.m_quad = v27;
    v21->m_inertiaTensor.m_col2.m_quad = v28;
    if ( v13 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v11,
        16 * v13);
  }
  else
  {
    result->m_enum = 1;
  }
  return v10;
}

// File Line: 528
// RVA: 0xC98D90
hkResult *__usercall hkInertiaTensorComputer::computeCapsuleVolumeMassProperties@<rax>(hkResult *result@<rcx>, hkVector4f *startAxis@<rdx>, hkVector4f *endAxis@<r8>, float radius@<xmm3>, __m128 a5@<xmm10>, __int64 mass, hkMassProperties *resulta)
{
  hkVector4f *v7; // rdi
  hkVector4f *v8; // rsi
  __m128 v9; // xmm12
  hkResult *v10; // rbx
  hkResult *v11; // rax
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
  __m128 v29; // xmm6
  __m128 v30; // xmm2
  __m128 v31; // xmm5
  __m128 v32; // xmm4
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  hkVector4f v35; // xmm13
  hkVector4f v36; // xmm14
  __m128 v37; // xmm15
  __m128 v38; // xmm3
  __m128 v39; // xmm4
  __m128 v40; // xmm5
  __m128 v41; // xmm2
  char *v42; // rax
  __m128 v43; // xmm2
  __m128 v44; // xmm2
  __m128 v45; // xmm8
  signed int v46; // ecx
  __m128 v47; // xmm7
  __m128 v48; // xmm1
  __m128 v49; // xmm6
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm2
  int v53; // edx
  __int64 v54; // rcx
  float v55; // xmm12_4
  __m128 v56; // xmm8
  __m128 v57; // xmm2
  __m128 v58; // xmm2
  int v59; // edx
  __int64 v60; // rcx
  __m128 v61; // xmm2
  int v62; // edx
  __int64 v63; // rcx
  float radiusa; // [rsp+20h] [rbp-D8h]
  float v65; // [rsp+24h] [rbp-D4h]
  hkSimdFloat32 v66; // [rsp+30h] [rbp-C8h]
  __int128 v67; // [rsp+40h] [rbp-B8h]
  hkVector4f shift; // [rsp+50h] [rbp-A8h]
  char inertia[56]; // [rsp+60h] [rbp-98h]
  hkVector4f v70; // [rsp+98h] [rbp-60h]
  hkVector4f v71; // [rsp+A8h] [rbp-50h]
  __m128 v72; // [rsp+B8h] [rbp-40h]
  hkQuaternionf qi; // [rsp+C8h] [rbp-30h]
  hkRotationf v74; // [rsp+D8h] [rbp-20h]
  __m128 v75; // [rsp+108h] [rbp+10h]
  hkMassProperties v76; // [rsp+118h] [rbp+20h]
  hkSimdFloat32 scale; // [rsp+168h] [rbp+70h]
  hkVector4f axis; // [rsp+178h] [rbp+80h]
  hkSimdFloat32 angle; // [rsp+188h] [rbp+90h]
  char *array; // [rsp+198h] [rbp+A0h]
  int v81; // [rsp+1A0h] [rbp+A8h]
  int v82; // [rsp+1A4h] [rbp+ACh]
  char v83; // [rsp+1A8h] [rbp+B0h]
  char v84; // [rsp+1E8h] [rbp+F0h]
  unsigned int v85; // [rsp+428h] [rbp+330h]

  v7 = endAxis;
  v8 = startAxis;
  v9 = _mm_shuffle_ps((__m128)v85, (__m128)v85, 0);
  v10 = result;
  radiusa = radius;
  if ( v9.m128_f32[0] > 0.0 )
  {
    a5.m128_f32[0] = radius;
    v12 = _mm_shuffle_ps(a5, a5, 0);
    if ( v12.m128_f32[0] > 0.0 )
    {
      v13 = _mm_sub_ps(endAxis->m_quad, startAxis->m_quad);
      v14 = _mm_mul_ps(v13, v13);
      v15 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
              _mm_shuffle_ps(v14, v14, 170));
      v16 = _mm_andnot_ps(_mm_cmpleps(v15, (__m128)0i64), _mm_sqrt_ps(v15));
      if ( v16.m128_f32[0] <= 0.0
        || (v17 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                    _mm_shuffle_ps(v14, v14, 170)),
            v18 = _mm_rsqrt_ps(v17),
            v65 = FLOAT_0_99998999,
            v19 = _mm_mul_ps(
                    v13,
                    _mm_andnot_ps(
                      _mm_cmpleps(v17, (__m128)0i64),
                      _mm_mul_ps(
                        _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                        _mm_mul_ps(*(__m128 *)_xmm, v18)))),
            v20 = _mm_shuffle_ps(v19, v19, 170),
            COERCE_FLOAT((unsigned int)(2 * v20.m128_i32[0]) >> 1) >= COERCE_FLOAT(
                                                                        _mm_shuffle_ps(
                                                                          (__m128)LODWORD(FLOAT_0_99998999),
                                                                          (__m128)LODWORD(FLOAT_0_99998999),
                                                                          0))) )
      {
        v38 = stru_141A71280.m_quad;
        v39 = direction.m_quad;
        v40 = transform.m_quad;
        v35.m_quad = stru_141A71280.m_quad;
        v36.m_quad = direction.m_quad;
        v37 = transform.m_quad;
        v74.m_col2 = (hkVector4f)stru_141A71280.m_quad;
        v74.m_col1 = (hkVector4f)direction.m_quad;
        v74.m_col0 = (hkVector4f)transform.m_quad;
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
        v27 = _mm_cmpleps(v25, (__m128)0i64);
        v28 = _mm_mul_ps(_mm_mul_ps(v26, v25), v26);
        v29 = _mm_cmpltps(v21, *(__m128 *)_xmm);
        v30 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v21), *(__m128 *)_xmm);
        v31 = _mm_cmpltps(*(__m128 *)_xmm, v21);
        axis.m_quad = _mm_mul_ps(
                        v23,
                        _mm_andnot_ps(v27, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v28), _mm_mul_ps(*(__m128 *)_xmm, v26))));
        v32 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v30), v31), _mm_andnot_ps(v31, v21));
        v33 = _mm_or_ps(_mm_andnot_ps(v31, _mm_mul_ps(v21, v21)), _mm_and_ps(v31, v30));
        v34 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v33, *(__m128 *)coeff4), *(__m128 *)coeff3), v33),
                              *(__m128 *)coeff2),
                            v33),
                          *(__m128 *)coeff1),
                        v33),
                      *(__m128 *)coeff0),
                    v33),
                  v32),
                v32);
        angle.m_real = _mm_sub_ps(
                         *(__m128 *)_xmm,
                         _mm_xor_ps(
                           _mm_or_ps(
                             _mm_andnot_ps(
                               v29,
                               _mm_or_ps(
                                 _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v34, v34)), v31),
                                 _mm_andnot_ps(v31, v34))),
                             _mm_and_ps(v29, v21)),
                           _mm_and_ps(v20, *(__m128 *)_xmm)));
        hkQuaternionf::setAxisAngle(&qi, &axis, &angle);
        hkRotationf::set(&v74, &qi);
        v35.m_quad = (__m128)v74.m_col2;
        v36.m_quad = (__m128)v74.m_col1;
        v37 = v74.m_col0.m_quad;
        v38 = stru_141A71280.m_quad;
        v39 = direction.m_quad;
        v40 = transform.m_quad;
      }
      v41 = v8->m_quad;
      v82 = -2147483645;
      array = &v83;
      v42 = &v84;
      v43 = _mm_add_ps(v41, v7->m_quad);
      v66.m_real = (__m128)xmmword_141A711B0;
      v81 = 0;
      v44 = _mm_mul_ps(v43, (__m128)xmmword_141A711B0);
      v45 = _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(v12, (__m128)xmmword_141A713B0), v12), v16);
      v46 = 2;
      v75 = v44;
      v47 = _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(v12, (__m128)xmmword_141A713E0), v12), v12);
      v48 = _mm_add_ps(v45, v47);
      v49 = _mm_div_ps(_mm_mul_ps(v47, v9), v48);
      scale.m_real = _mm_div_ps(_mm_mul_ps(v45, v9), v48);
      do
      {
        --v46;
        *((_QWORD *)v42 - 8) = 0i64;
        *((_OWORD *)v42 - 3) = 0i64;
        *((_OWORD *)v42 - 2) = 0i64;
        *((_OWORD *)v42 - 1) = 0i64;
        *(_OWORD *)v42 = 0i64;
        v42 += 144;
        *((__m128 *)v42 - 8) = v40;
        *((__m128 *)v42 - 7) = v39;
        *((__m128 *)v42 - 6) = v38;
        *((_OWORD *)v42 - 5) = 0i64;
      }
      while ( v46 >= 0 );
      v72 = v44;
      v50 = _mm_mul_ps(v12, v12);
      *(__m128 *)&inertia[40] = v37;
      v70.m_quad = v36.m_quad;
      v71.m_quad = v35.m_quad;
      v51 = _mm_mul_ps(
              _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v16, v16), (__m128)xmmword_141A711C0), v50),
              (__m128)xmmword_141A711D0);
      v52 = _mm_movelh_ps(
              _mm_unpacklo_ps(v51, v51),
              _mm_unpacklo_ps(_mm_mul_ps(v50, (__m128)xmmword_141A711B0), (__m128)xmmword_141A711D0));
      *(__m128 *)inertia = _mm_mul_ps(v40, v52);
      *(__m128 *)&inertia[16] = _mm_mul_ps(v39, v52);
      *(__m128 *)&inertia[24] = _mm_mul_ps(v38, v52);
      hkMatrix3f::mul((hkMatrix3f *)inertia, &scale);
      v53 = v81;
      *(_QWORD *)&v67 = __PAIR__(scale.m_real.m128_u32[0], v45.m128_u32[0]);
      shift.m_quad = 0i64;
      if ( v81 == (v82 & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 144);
        v53 = v81;
      }
      v54 = (__int64)&array[144 * v53];
      if ( v54 )
      {
        *(_OWORD *)v54 = v67;
        *(hkVector4f *)(v54 + 16) = (hkVector4f)shift.m_quad;
        *(_OWORD *)(v54 + 32) = *(_OWORD *)inertia;
        *(_OWORD *)(v54 + 48) = *(_OWORD *)&inertia[16];
        *(_OWORD *)(v54 + 64) = *(_OWORD *)&inertia[24];
        *(_OWORD *)(v54 + 80) = *(_OWORD *)&inertia[40];
        *(hkVector4f *)(v54 + 96) = (hkVector4f)v70.m_quad;
        *(hkVector4f *)(v54 + 112) = (hkVector4f)v71.m_quad;
        *(__m128 *)(v54 + 128) = v72;
        v53 = v81;
      }
      v55 = radiusa;
      *(_QWORD *)&v67 = 0i64;
      *(_QWORD *)&v76.m_volume = 0i64;
      v81 = v53 + 1;
      v70.m_quad = (__m128)v74.m_col1;
      v56 = _mm_unpacklo_ps((__m128)0i64, (__m128)0i64);
      v57 = _mm_movelh_ps(v56, _mm_unpacklo_ps(_mm_mul_ps(v66.m_real, v16), (__m128)0i64));
      *(_OWORD *)inertia = 0i64;
      *(_OWORD *)&inertia[16] = 0i64;
      *(_OWORD *)&inertia[24] = 0i64;
      *(hkVector4f *)&inertia[40] = v74.m_col0;
      v71.m_quad = (__m128)v74.m_col2;
      v76.m_centerOfMass = 0i64;
      v76.m_inertiaTensor.m_col0 = 0i64;
      v76.m_inertiaTensor.m_col1 = 0i64;
      v65 = FLOAT_0_375;
      v76.m_inertiaTensor.m_col2 = 0i64;
      shift.m_quad = _mm_movelh_ps(
                       v56,
                       _mm_unpacklo_ps(
                         _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_375), (__m128)LODWORD(FLOAT_0_375), 0), v12),
                         (__m128)0i64));
      v72 = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v57, v57, 85), v74.m_col1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(v57, v57, 0), v74.m_col0.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v57, v57, 170), v74.m_col2.m_quad)),
              v75);
      if ( hkInertiaTensorComputer::computeSphereVolumeMassProperties(
             (hkResult *)&radiusa,
             radiusa,
             v49.m128_f32[0],
             &v76,
             (__m128 *)v72.m128_u64[0],
             (__m128 *)v74.m_col0.m_quad.m128_u64[0])->m_enum == 1 )
      {
        v10->m_enum = 1;
      }
      else
      {
        *(hkVector4f *)inertia = v76.m_inertiaTensor.m_col0;
        *(hkVector4f *)&inertia[16] = v76.m_inertiaTensor.m_col1;
        *(hkVector4f *)&inertia[24] = v76.m_inertiaTensor.m_col2;
        hkMatrix3f::mul((hkMatrix3f *)inertia, &v66);
        qi.m_vec.m_quad = _mm_mul_ps(v49, v66.m_real);
        hkInertiaTensorComputer::shiftInertiaToCom(&shift, (hkSimdFloat32 *)&qi, (hkMatrix3f *)inertia);
        v58 = v66.m_real;
        v59 = v81;
        *(float *)&v67 = v47.m128_f32[0] * v58.m128_f32[0];
        *((float *)&v67 + 1) = v49.m128_f32[0] * v66.m_real.m128_f32[0];
        if ( v81 == (v82 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 144);
          v59 = v81;
          v58 = v66.m_real;
        }
        v60 = (__int64)&array[144 * v59];
        if ( v60 )
        {
          *(_OWORD *)v60 = v67;
          *(hkVector4f *)(v60 + 16) = (hkVector4f)shift.m_quad;
          *(_OWORD *)(v60 + 32) = *(_OWORD *)inertia;
          *(_OWORD *)(v60 + 48) = *(_OWORD *)&inertia[16];
          *(_OWORD *)(v60 + 64) = *(_OWORD *)&inertia[24];
          *(_OWORD *)(v60 + 80) = *(_OWORD *)&inertia[40];
          *(hkVector4f *)(v60 + 96) = (hkVector4f)v70.m_quad;
          *(hkVector4f *)(v60 + 112) = (hkVector4f)v71.m_quad;
          *(__m128 *)(v60 + 128) = v72;
          v58 = v66.m_real;
          v59 = v81;
        }
        *(_QWORD *)&v67 = 0i64;
        *(_QWORD *)&v76.m_volume = 0i64;
        v81 = v59 + 1;
        v70.m_quad = (__m128)v74.m_col1;
        *(_OWORD *)inertia = 0i64;
        *(_OWORD *)&inertia[16] = 0i64;
        *(_OWORD *)&inertia[24] = 0i64;
        v61 = _mm_movelh_ps(v56, _mm_unpacklo_ps(_mm_sub_ps((__m128)0i64, _mm_mul_ps(v58, v16)), (__m128)0i64));
        *(hkVector4f *)&inertia[40] = v74.m_col0;
        v71.m_quad = (__m128)v74.m_col2;
        v76.m_centerOfMass = 0i64;
        v76.m_inertiaTensor.m_col0 = 0i64;
        v76.m_inertiaTensor.m_col1 = 0i64;
        v76.m_inertiaTensor.m_col2 = 0i64;
        radiusa = FLOAT_N0_375;
        shift.m_quad = _mm_movelh_ps(
                         v56,
                         _mm_unpacklo_ps(
                           _mm_mul_ps(
                             _mm_shuffle_ps((__m128)LODWORD(FLOAT_N0_375), (__m128)LODWORD(FLOAT_N0_375), 0),
                             v12),
                           (__m128)0i64));
        v72 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v61, v61, 85), v74.m_col1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v61, v61, 0), v74.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v61, v61, 170), v74.m_col2.m_quad)),
                v75);
        if ( hkInertiaTensorComputer::computeSphereVolumeMassProperties(
               (hkResult *)&radiusa,
               v55,
               v49.m128_f32[0],
               &v76,
               (__m128 *)v72.m128_u64[0],
               (__m128 *)v74.m_col0.m_quad.m128_u64[0])->m_enum == 1 )
        {
          v10->m_enum = 1;
        }
        else
        {
          *(hkVector4f *)inertia = v76.m_inertiaTensor.m_col0;
          *(hkVector4f *)&inertia[16] = v76.m_inertiaTensor.m_col1;
          *(hkVector4f *)&inertia[24] = v76.m_inertiaTensor.m_col2;
          hkMatrix3f::mul((hkMatrix3f *)inertia, &v66);
          qi.m_vec.m_quad = _mm_mul_ps(v49, v66.m_real);
          hkInertiaTensorComputer::shiftInertiaToCom(&shift, (hkSimdFloat32 *)&qi, (hkMatrix3f *)inertia);
          v62 = v81;
          *(float *)&v67 = v47.m128_f32[0] * v66.m_real.m128_f32[0];
          *((float *)&v67 + 1) = v49.m128_f32[0] * v66.m_real.m128_f32[0];
          if ( v81 == (v82 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 144);
            v62 = v81;
          }
          v63 = (__int64)&array[144 * v62];
          if ( v63 )
          {
            *(_OWORD *)v63 = v67;
            *(hkVector4f *)(v63 + 16) = (hkVector4f)shift.m_quad;
            *(_OWORD *)(v63 + 32) = *(_OWORD *)inertia;
            *(_OWORD *)(v63 + 48) = *(_OWORD *)&inertia[16];
            *(_OWORD *)(v63 + 64) = *(_OWORD *)&inertia[24];
            *(_OWORD *)(v63 + 80) = *(_OWORD *)&inertia[40];
            *(hkVector4f *)(v63 + 96) = (hkVector4f)v70.m_quad;
            *(hkVector4f *)(v63 + 112) = (hkVector4f)v71.m_quad;
            *(__m128 *)(v63 + 128) = v72;
            v62 = v81;
          }
          v81 = v62 + 1;
          hkInertiaTensorComputer::combineMassProperties(
            v10,
            (hkArray<hkMassElement,hkContainerHeapAllocator> *)&array,
            (hkMassProperties *)mass);
        }
      }
      v81 = 0;
      if ( v82 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          array,
          144 * (v82 & 0x3FFFFFFF));
      v11 = v10;
    }
    else
    {
      result->m_enum = 1;
      v11 = result;
    }
  }
  else
  {
    result->m_enum = 1;
    v11 = result;
  }
  return v11;
}

// File Line: 720
// RVA: 0xC9A1F0
hkResult *__usercall hkInertiaTensorComputer::computeCylinderVolumeMassProperties@<rax>(hkResult *result@<rcx>, hkVector4f *startAxis@<rdx>, hkVector4f *endAxis@<r8>, float radius@<xmm3>, __m128 a5@<xmm10>, __int64 mass, hkMassProperties *resulta)
{
  hkVector4f *v7; // rdi
  hkVector4f *v8; // rsi
  __m128i v9; // xmm12
  hkResult *v10; // rbx
  hkResult *v11; // rax
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
  __m128 v29; // xmm6
  __m128 v30; // xmm2
  __m128 v31; // xmm5
  __m128 v32; // xmm4
  __m128 v33; // xmm3
  __m128 v34; // xmm2
  __int128 v35; // xmm7
  __int128 v36; // xmm8
  __m128 v37; // xmm13
  __m128 v38; // xmm5
  __m128 v39; // xmm4
  __m128 v40; // xmm3
  __m128 v41; // xmm1
  __m128 v42; // xmm1
  float v43; // xmm6_4
  __m128 v44; // xmm10
  unsigned int v45; // xmm6_4
  __m128 v46; // xmm9
  __m128 v47; // xmm9
  hkSimdFloat32 scale; // [rsp+30h] [rbp-C8h]
  hkArray<hkMassElement,hkContainerHeapAllocator> elements; // [rsp+40h] [rbp-B8h]
  unsigned __int64 v50; // [rsp+50h] [rbp-A8h]
  __int128 v51; // [rsp+60h] [rbp-98h]
  char v52[56]; // [rsp+70h] [rbp-88h]
  __int128 v53; // [rsp+A8h] [rbp-50h]
  __int128 v54; // [rsp+B8h] [rbp-40h]
  __m128 v55; // [rsp+C8h] [rbp-30h]
  hkVector4f axis; // [rsp+D8h] [rbp-20h]
  hkRotationf v57; // [rsp+E8h] [rbp-10h]
  __m128 v58; // [rsp+118h] [rbp+20h]
  hkQuaternionf qi; // [rsp+128h] [rbp+30h]
  hkSimdFloat32 angle; // [rsp+138h] [rbp+40h]
  unsigned int v61; // [rsp+1F8h] [rbp+100h]

  v7 = endAxis;
  v8 = startAxis;
  v9 = (__m128i)_mm_shuffle_ps((__m128)v61, (__m128)v61, 0);
  v10 = result;
  if ( *(float *)v9.m128i_i32 > 0.0 )
  {
    a5.m128_f32[0] = radius;
    v12 = _mm_shuffle_ps(a5, a5, 0);
    if ( v12.m128_f32[0] > 0.0 )
    {
      v13 = _mm_sub_ps(endAxis->m_quad, startAxis->m_quad);
      v14 = _mm_mul_ps(v13, v13);
      v15 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
              _mm_shuffle_ps(v14, v14, 170));
      v16 = _mm_andnot_ps(_mm_cmpleps(v15, (__m128)0i64), _mm_sqrt_ps(v15));
      if ( v16.m128_f32[0] > 0.0 )
      {
        v17 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                _mm_shuffle_ps(v14, v14, 170));
        v18 = _mm_rsqrt_ps(v17);
        v19 = _mm_mul_ps(
                v13,
                _mm_andnot_ps(
                  _mm_cmpleps(v17, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                    _mm_mul_ps(*(__m128 *)_xmm, v18))));
        v20 = _mm_shuffle_ps(v19, v19, 170);
        if ( COERCE_FLOAT((unsigned int)(2 * v20.m128_i32[0]) >> 1) >= COERCE_FLOAT(
                                                                         _mm_shuffle_ps(
                                                                           (__m128)LODWORD(FLOAT_0_99998999),
                                                                           (__m128)LODWORD(FLOAT_0_99998999),
                                                                           0)) )
        {
          v40 = transform.m_quad;
          v39 = direction.m_quad;
          v38 = stru_141A71280.m_quad;
          v37 = transform.m_quad;
          v57.m_col0 = (hkVector4f)transform.m_quad;
          v36 = (__int128)direction.m_quad;
          v57.m_col1 = (hkVector4f)direction.m_quad;
          v35 = (__int128)stru_141A71280.m_quad;
          v57.m_col2 = (hkVector4f)stru_141A71280.m_quad;
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
          v27 = _mm_cmpleps(v25, (__m128)0i64);
          v28 = _mm_mul_ps(_mm_mul_ps(v26, v25), v26);
          v29 = _mm_cmpltps(v21, *(__m128 *)_xmm);
          v30 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)_xmm, v21), *(__m128 *)_xmm);
          v31 = _mm_cmpltps(*(__m128 *)_xmm, v21);
          axis.m_quad = _mm_mul_ps(
                          v23,
                          _mm_andnot_ps(
                            v27,
                            _mm_mul_ps(_mm_sub_ps((__m128)_xmm, v28), _mm_mul_ps(*(__m128 *)_xmm, v26))));
          v32 = _mm_or_ps(_mm_and_ps(_mm_sqrt_ps(v30), v31), _mm_andnot_ps(v31, v21));
          v33 = _mm_or_ps(_mm_andnot_ps(v31, _mm_mul_ps(v21, v21)), _mm_and_ps(v31, v30));
          v34 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(
                              _mm_add_ps(
                                _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v33, *(__m128 *)coeff4), *(__m128 *)coeff3), v33),
                                *(__m128 *)coeff2),
                              v33),
                            *(__m128 *)coeff1),
                          v33),
                        *(__m128 *)coeff0),
                      v33),
                    v32),
                  v32);
          angle.m_real = _mm_sub_ps(
                           *(__m128 *)_xmm,
                           _mm_xor_ps(
                             _mm_or_ps(
                               _mm_andnot_ps(
                                 v29,
                                 _mm_or_ps(
                                   _mm_and_ps(_mm_sub_ps(*(__m128 *)_xmm, _mm_add_ps(v34, v34)), v31),
                                   _mm_andnot_ps(v31, v34))),
                               _mm_and_ps(v29, v21)),
                             _mm_and_ps(v20, *(__m128 *)_xmm)));
          hkQuaternionf::setAxisAngle(&qi, &axis, &angle);
          hkRotationf::set(&v57, &qi);
          v35 = (__int128)v57.m_col2;
          v36 = (__int128)v57.m_col1;
          v37 = v57.m_col0.m_quad;
          v38 = stru_141A71280.m_quad;
          v39 = direction.m_quad;
          v40 = transform.m_quad;
        }
        v41 = v8->m_quad;
        elements.m_capacityAndFlags = -2147483647;
        _mm_store_si128((__m128i *)&scale, v9);
        v51 = 0i64;
        *(__m128 *)&v52[40] = v37;
        v42 = _mm_add_ps(v41, v7->m_quad);
        v43 = (float)(v12.m128_f32[0] * 3.1415927) * v12.m128_f32[0];
        v44 = _mm_mul_ps(v12, v12);
        elements.m_data = (hkMassElement *)&v50;
        v50 = 0i64;
        elements.m_size = 1;
        v53 = v36;
        v54 = v35;
        *(float *)&v45 = v43 * v16.m128_f32[0];
        v58 = _mm_mul_ps(v42, (__m128)xmmword_141A711B0);
        v55 = v58;
        v46 = _mm_mul_ps(
                _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v16, v16), (__m128)xmmword_141A711C0), v44),
                (__m128)xmmword_141A711D0);
        v47 = _mm_movelh_ps(
                _mm_unpacklo_ps(v46, v46),
                _mm_unpacklo_ps(_mm_mul_ps(v44, (__m128)xmmword_141A711B0), (__m128)xmmword_141A711D0));
        *(__m128 *)&v52[8] = _mm_mul_ps(v39, v47);
        *(__m128 *)&v52[24] = _mm_mul_ps(v38, v47);
        *(__m128 *)v52 = _mm_mul_ps(v40, v47);
        hkMatrix3f::mul((hkMatrix3f *)v52, &scale);
        v50 = __PAIR__(scale.m_real.m128_u32[0], v45);
        v51 = 0i64;
        hkInertiaTensorComputer::combineMassProperties(v10, &elements, (hkMassProperties *)mass);
        elements.m_size = 0;
        if ( elements.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            elements.m_data,
            144 * (elements.m_capacityAndFlags & 0x3FFFFFFF));
      }
      else
      {
        result->m_enum = 1;
      }
      v11 = v10;
    }
    else
    {
      result->m_enum = 1;
      v11 = result;
    }
  }
  else
  {
    result->m_enum = 1;
    v11 = result;
  }
  return v11;
}

// File Line: 828
// RVA: 0xC9A690
hkResult *__fastcall hkInertiaTensorComputer::computeConvexHullMassProperties(hkResult *result, hkStridedVertices *vertices, float radius, hkMassProperties *a4)
{
  hkResult *v4; // rbx
  hkResultEnum v5; // edx
  hkResult *v6; // rax
  hkResult resulta; // [rsp+20h] [rbp-18h]

  v4 = result;
  if ( hkInertiaTensorComputer::s_computeConvexHullMassPropertiesFunction )
  {
    v5 = hkInertiaTensorComputer::s_computeConvexHullMassPropertiesFunction(&resulta, vertices, radius, a4)->m_enum;
    v6 = v4;
    v4->m_enum = v5;
  }
  else
  {
    hkInertiaTensorComputer::computeApproximateConvexHullMassProperties(result, vertices, radius, a4);
    v6 = v4;
  }
  return v6;
}

// File Line: 841
// RVA: 0xC9AAF0
hkResult *__usercall hkInertiaTensorComputer::computeGeometrySurfaceMassProperties@<rax>(hkResult *result@<rcx>, hkGeometry *geom@<rdx>, float surfaceThickness@<xmm2>, hkBool distributeUniformly@<r9b>, __int64 a5@<rbx>, __int64 a6@<r13>, __m128 a7@<xmm0>, __m128 a8@<xmm4>, __m128 a9@<xmm9>, float mass, hkMassProperties *resulta)
{
  hkGeometry *v11; // rdi
  hkResult *v12; // r12
  float v13; // xmm10_4
  __m128 v14; // xmm9
  char *v15; // r10
  __m128 v16; // xmm6
  int v17; // ebx
  int v18; // er9
  bool v19; // zf
  bool v20; // sf
  int v21; // er9
  __int64 v22; // r8
  hkGeometry::Triangle *v23; // rcx
  hkVector4f *v24; // rdx
  __int64 v25; // rax
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm3
  __m128 v30; // xmm3
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  __m128 v33; // xmm8
  __m128 v34; // xmm0
  int v35; // esi
  __m128 v36; // xmm8
  __int64 v37; // rbx
  hkGeometry::Triangle *v38; // rax
  hkVector4f *v39; // rcx
  __m128 v40; // xmm6
  __int64 v41; // rdx
  __int64 v42; // r8
  __int64 v43; // r9
  hkVector4f *v44; // rdx
  hkVector4f *v45; // r8
  hkVector4f *v46; // r9
  int v47; // er8
  hkResult v49; // [rsp+40h] [rbp-A8h]
  char *array; // [rsp+48h] [rbp-A0h]
  int v51; // [rsp+50h] [rbp-98h]
  int v52; // [rsp+54h] [rbp-94h]
  hkVector4f shift; // [rsp+60h] [rbp-88h]
  hkMassProperties v54; // [rsp+70h] [rbp-78h]
  __int64 v55; // [rsp+160h] [rbp+78h]
  float v56; // [rsp+168h] [rbp+80h]

  v11 = geom;
  v12 = result;
  v13 = surfaceThickness;
  a9.m128_f32[0] = v56;
  v14 = _mm_shuffle_ps(a9, a9, 0);
  *(__m128 *)((char *)&v54.m_inertiaTensor.m_col1.m_quad + 8) = v14;
  if ( v14.m128_f32[0] <= 0.0 || (a7.m128_f32[0] = surfaceThickness, COERCE_FLOAT(_mm_shuffle_ps(a7, a7, 0)) <= 0.0) )
  {
    result->m_enum = 1;
  }
  else
  {
    v55 = a5;
    v49.m_enum = LODWORD(FLOAT_0_0000099999997);
    v15 = 0i64;
    *(_OWORD *)(a6 + 32) = 0i64;
    *(_OWORD *)(a6 + 48) = 0i64;
    *(_OWORD *)(a6 + 64) = 0i64;
    array = 0i64;
    v51 = 0;
    v52 = 2147483648;
    *(_OWORD *)(a6 + 16) = 0i64;
    v16 = _mm_shuffle_ps((__m128)(unsigned int)v49.m_enum, (__m128)(unsigned int)v49.m_enum, 0);
    if ( (_BYTE)a5 )
    {
      v17 = geom->m_triangles.m_size;
      if ( v17 > 0 )
      {
        v18 = geom->m_triangles.m_size;
        if ( v17 < 0 )
          v18 = 0;
        hkArrayUtil::_reserve(&v49, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v18, 16);
        v15 = array;
      }
      v19 = v11->m_triangles.m_size == 0;
      v20 = v11->m_triangles.m_size < 0;
      v51 = v17;
      a8 = 0i64;
      v21 = 0;
      if ( !v20 && !v19 )
      {
        v22 = 0i64;
        do
        {
          v23 = v11->m_triangles.m_data;
          v24 = v11->m_vertices.m_data;
          ++v21;
          v25 = v23[v22].m_b;
          ++v22;
          v26 = v24[v25].m_quad;
          v27 = _mm_sub_ps(v24[*((signed int *)&v23[v22] - 2)].m_quad, v26);
          v28 = _mm_sub_ps(v24[v23[v22 - 1].m_a].m_quad, v26);
          v29 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v27),
                  _mm_mul_ps(_mm_shuffle_ps(v27, v27, 201), v28));
          v30 = _mm_shuffle_ps(v29, v29, 201);
          v31 = _mm_mul_ps(v30, v30);
          v32 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                  _mm_shuffle_ps(v31, v31, 170));
          *(__m128 *)&v15[v22 * 16 - 16] = _mm_max_ps(
                                             v16,
                                             _mm_andnot_ps(_mm_cmpleps(v32, (__m128)0i64), _mm_sqrt_ps(v32)));
          *(__m128 *)&array[v22 * 16 - 16] = _mm_mul_ps(*(__m128 *)&array[v22 * 16 - 16], (__m128)xmmword_141A711B0);
          v15 = array;
          a8 = _mm_add_ps(a8, *(__m128 *)&array[v22 * 16 - 16]);
        }
        while ( v21 < v11->m_triangles.m_size );
      }
      v33 = _mm_div_ps(query.m_quad, a8);
    }
    else
    {
      v34 = 0i64;
      v34.m128_f32[0] = (float)geom->m_triangles.m_size;
      v33 = _mm_div_ps(query.m_quad, _mm_shuffle_ps(v34, v34, 0));
    }
    v35 = 0;
    if ( v11->m_triangles.m_size > 0 )
    {
      v36 = _mm_mul_ps(v33, v14);
      v37 = 0i64;
      while ( 1 )
      {
        v38 = v11->m_triangles.m_data;
        v39 = v11->m_vertices.m_data;
        v40 = v36;
        v41 = v38[v37].m_a;
        v42 = v38[v37].m_b;
        v43 = v38[v37].m_c;
        shift.m_quad = v36;
        v44 = &v39[v41];
        v45 = &v39[v42];
        v46 = &v39[v43];
        if ( (_BYTE)v55 )
        {
          v40 = _mm_mul_ps(v36, *(__m128 *)&v15[v37 * 16]);
          shift.m_quad = v40;
        }
        *(hkVector4f *)((char *)&shift + 8) = 0i64;
        *(_OWORD *)(&v54.m_mass + 1) = 0i64;
        *(hkVector4f *)((char *)&v54.m_centerOfMass + 8) = 0i64;
        *(hkVector4f *)((char *)&v54.m_inertiaTensor.m_col0 + 8) = 0i64;
        if ( hkInertiaTensorComputer::computeTriangleSurfaceMassProperties(
               &v49,
               v44,
               v45,
               v46,
               (__m128 *)a8.m128_u64[0],
               v40.m128_f32[0],
               v13,
               &v54)->m_enum != 1 )
        {
          *(__m128 *)(a6 + 16) = _mm_add_ps(
                                   _mm_mul_ps(*(__m128 *)((char *)&shift.m_quad + 8), v40),
                                   *(__m128 *)(a6 + 16));
          hkInertiaTensorComputer::shiftInertiaFromCom(
            (hkVector4f *)((char *)&shift + 8),
            (hkSimdFloat32 *)&shift,
            (hkMatrix3f *)(&v54.m_mass + 1));
          hkMatrix3f::add((hkMatrix3f *)(a6 + 32), (hkMatrix3f *)(&v54.m_mass + 1));
        }
        ++v35;
        ++v37;
        if ( v35 >= v11->m_triangles.m_size )
          break;
        v15 = array;
      }
    }
    *(float *)(a6 + 4) = v56;
    *(__m128 *)(a6 + 16) = _mm_mul_ps(*(__m128 *)(a6 + 16), _mm_div_ps(query.m_quad, v14));
    hkInertiaTensorComputer::shiftInertiaToCom(
      (hkVector4f *)(a6 + 16),
      (hkSimdFloat32 *)&v54.m_inertiaTensor.m_col1.m_quad.m128_u16[4],
      (hkMatrix3f *)(a6 + 32));
    v47 = v52;
    v12->m_enum = 0;
    v51 = 0;
    if ( v47 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        16 * v47);
  }
  return v12;
}

// File Line: 953
// RVA: 0xC9B510
hkResult *__fastcall hkInertiaTensorComputer::combineMassProperties(hkResult *result, hkArray<hkMassElement,hkContainerHeapAllocator> *elements, hkMassProperties *a3)
{
  int v3; // er9
  hkArray<hkMassElement,hkContainerHeapAllocator> *v4; // r14
  hkResult *v5; // rsi
  __m128 v6; // xmm6
  __m128 v7; // xmm5
  __m128 v8; // xmm7
  hkMassElement *v9; // rax
  __int64 v10; // r11
  __m128 *v11; // rdx
  signed __int64 v12; // rcx
  unsigned int *v13; // r10
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm0
  __m128 v17; // xmm3
  hkMatrix3f *v18; // rbp
  int v19; // er15
  hkVector4f v20; // xmm6
  __int64 v21; // rdi
  hkMassElement *v22; // rcx
  signed __int64 v23; // rdx
  signed __int64 v24; // rbx
  __m128 v25; // xmm1
  __m128 v26; // xmm0
  __m128 v27; // xmm2
  hkSimdFloat32 mass; // [rsp+20h] [rbp-88h]
  hkVector4f shift; // [rsp+30h] [rbp-78h]
  hkMatrix3f inertia; // [rsp+40h] [rbp-68h]

  v3 = elements->m_size;
  v4 = elements;
  v5 = result;
  v6 = 0i64;
  v7 = 0i64;
  v8 = 0i64;
  if ( v3 > 0 )
  {
    v9 = elements->m_data;
    v10 = (unsigned int)v3;
    v11 = &elements->m_data->m_properties.m_centerOfMass.m_quad;
    v12 = (signed __int64)&v9->m_transform.m_rotation.m_col2;
    v13 = (unsigned int *)&v9->m_properties.m_mass;
    do
    {
      v14 = *v11;
      v15 = (__m128)*v13;
      ++v9;
      v16 = *v11;
      v13 += 36;
      v11 += 9;
      v12 += 144i64;
      v17 = _mm_shuffle_ps(v15, v15, 0);
      v7 = _mm_add_ps(v7, v17);
      v8 = _mm_add_ps(
             v8,
             _mm_shuffle_ps(
               (__m128)LODWORD(v9[-1].m_properties.m_volume),
               (__m128)LODWORD(v9[-1].m_properties.m_volume),
               0));
      v6 = _mm_add_ps(
             v6,
             _mm_mul_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), *(__m128 *)(v12 - 160)),
                     _mm_mul_ps(_mm_shuffle_ps(v16, v14, 0), v11[-5])),
                   _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), *(__m128 *)(v12 - 144))),
                 *(__m128 *)(v12 - 128)),
               v17));
      --v10;
    }
    while ( v10 );
  }
  if ( v7.m128_f32[0] > 0.0 )
  {
    v18 = &a3->m_inertiaTensor;
    v19 = 0;
    v20.m_quad = _mm_mul_ps(v6, _mm_div_ps(query.m_quad, v7));
    a3->m_centerOfMass = (hkVector4f)v20.m_quad;
    LODWORD(a3->m_mass) = v7.m128_i32[0];
    LODWORD(a3->m_volume) = v8.m128_i32[0];
    v18->m_col0 = 0i64;
    v18->m_col1 = 0i64;
    v18->m_col2 = 0i64;
    if ( v4->m_size > 0 )
    {
      v21 = 0i64;
      do
      {
        v22 = v4->m_data;
        v23 = (signed __int64)&v4->m_data->m_transform;
        v24 = v19;
        inertia.m_col0 = v4->m_data[v21].m_properties.m_inertiaTensor.m_col0;
        inertia.m_col1 = v22[v21].m_properties.m_inertiaTensor.m_col1;
        inertia.m_col2 = v22[v21].m_properties.m_inertiaTensor.m_col2;
        hkMatrix3f::changeBasis(&inertia, (hkRotationf *)(v24 * 144 + v23));
        v25 = v4->m_data[v21].m_properties.m_centerOfMass.m_quad;
        v26 = (__m128)LODWORD(v4->m_data[v24].m_properties.m_mass);
        v27 = _mm_sub_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v4->m_data[v21].m_transform.m_rotation.m_col1.m_quad),
                      _mm_mul_ps(
                        _mm_shuffle_ps(v4->m_data[v21].m_properties.m_centerOfMass.m_quad, v25, 0),
                        v4->m_data[v21].m_transform.m_rotation.m_col0.m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v4->m_data[v21].m_transform.m_rotation.m_col2.m_quad)),
                  v4->m_data[v21].m_transform.m_translation.m_quad),
                v20.m_quad);
        mass.m_real = _mm_shuffle_ps(v26, v26, 0);
        shift.m_quad = v27;
        hkInertiaTensorComputer::shiftInertiaFromCom(&shift, &mass, &inertia);
        hkMatrix3f::add(v18, &inertia);
        ++v19;
        ++v21;
      }
      while ( v19 < v4->m_size );
    }
    v5->m_enum = 0;
  }
  else
  {
    v5->m_enum = 1;
  }
  return v5;
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
void __fastcall hkInertiaTensorComputer::shiftInertiaFromCom(hkVector4f *shift, hkSimdFloat32 *mass, hkMatrix3f *inertia)
{
  hkSimdFloat32 massa; // [rsp+20h] [rbp-18h]

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
void __fastcall InternalInertiaTensorComputer::compProjectionIntegrals(InternalInertiaTensorComputer *this, hkVector4f *v)
{
  hkVector4f *v2; // r9
  const int *v3; // r10
  hkVector4f *v4; // r8
  __m128 v5; // xmm4
  int v6; // edx
  __m128 v7; // xmm14
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

  v2 = v;
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
    v6 = this->m_C;
    v7 = v4->m_quad;
    if ( this->m_C )
    {
      if ( v6 == 1 )
        v7 = _mm_shuffle_ps(v7, v7, 210);
    }
    else
    {
      v7 = _mm_shuffle_ps(v7, v7, 201);
    }
    v8 = _mm_shuffle_ps(v7, v7, 0);
    v9 = _mm_shuffle_ps(v7, v7, 85);
    v10 = v2[*v3].m_quad;
    v34 = v8;
    if ( v6 )
    {
      if ( v6 == 1 )
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
  while ( (signed __int64)v3 < (signed __int64)&InternalInertiaTensorComputer_mod3table[3] );
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
void __fastcall InternalInertiaTensorComputer::compFaceIntegrals(InternalInertiaTensorComputer *this, hkVector4f *v, hkVector4f *n)
{
  hkVector4f *v3; // rbx
  hkVector4f *v4; // rdi
  InternalInertiaTensorComputer *v5; // rsi
  __m128 v6; // xmm12
  __m128 v7; // xmm2
  __m128 v8; // xmm9
  __m128 v9; // xmm4
  __m128 v10; // xmm15
  __m128 v11; // xmm5
  __m128 v12; // ST70_16
  __m128 v13; // STA0_16
  __m128 v14; // xmm1
  __m128 v15; // xmm11
  __m128 v16; // ST90_16
  __m128 v17; // ST40_16
  __m128 v18; // xmm0
  __m128 v19; // ST60_16
  __m128 v20; // xmm13
  __m128 v21; // xmm14
  __m128 v22; // xmm6
  __m128 v23; // ST30_16
  __m128 v24; // xmm0
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  __m128 v27; // xmm12
  __m128 v28; // xmm3
  __m128 v29; // xmm9
  __m128 v30; // xmm7
  __m128 v31; // ST50_16
  __m128 v32; // xmm13
  __m128 v33; // xmm10
  __m128 v34; // xmm3
  __m128 v35; // xmm0
  __m128 v36; // xmm1
  __m128 v37; // [rsp+20h] [rbp-138h]

  v3 = n;
  v4 = v;
  v5 = this;
  InternalInertiaTensorComputer::compProjectionIntegrals(this, v);
  v6 = v3->m_quad;
  v7 = _mm_mul_ps(v3->m_quad, v4->m_quad);
  v8 = _mm_sub_ps(
         (__m128)0i64,
         _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170)));
  v37 = v8;
  if ( v5->m_C )
  {
    if ( v5->m_C == 1 )
      v6 = _mm_shuffle_ps(v6, v6, 210);
  }
  else
  {
    v6 = _mm_shuffle_ps(v6, v6, 201);
  }
  v9 = v5->m_P_a.m_quad;
  v10 = v5->m_P_b.m_quad;
  v11 = _mm_mul_ps(v5->m_P1.m_real, v8);
  v12 = _mm_shuffle_ps(v6, v6, 0);
  v13 = _mm_div_ps(query.m_quad, _mm_shuffle_ps(v6, v6, 170));
  v14 = _mm_mul_ps(v13, v13);
  v15 = _mm_sub_ps((__m128)0i64, v14);
  v16 = v14;
  v17 = _mm_mul_ps(v13, v14);
  v18 = _mm_mul_ps(v6, v6);
  v19 = _mm_shuffle_ps(v6, v6, 85);
  v20 = _mm_mul_ps(v10, v19);
  v21 = _mm_mul_ps(_mm_mul_ps((__m128)xmmword_141A710D0, v12), v19);
  v22 = _mm_shuffle_ps(v18, v18, 0);
  v23 = _mm_shuffle_ps(v18, v18, 85);
  v24 = _mm_mul_ps(v13, v9);
  v25 = _mm_mul_ps(v9, v12);
  v26 = _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v19);
  v27 = v5->m_Paab.m_real;
  v5->m_F_a.m_quad = v24;
  v28 = v5->m_Pab.m_real;
  v29 = _mm_shuffle_ps(v25, v25, 85);
  v5->m_F_b.m_quad = _mm_mul_ps(v13, v10);
  v30 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 0), _mm_shuffle_ps(v25, v25, 0));
  v31 = _mm_shuffle_ps(v25, v25, 170);
  v32 = _mm_shuffle_ps(v20, v20, 170);
  v33 = v5->m_Pabb.m_real;
  v34 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v28, v21), _mm_mul_ps(v29, v12)), v26);
  v5->m_Faab.m_real = _mm_mul_ps(v13, v27);
  v35 = _mm_mul_ps(v5->m_Pab.m_real, v19);
  v36 = _mm_shuffle_ps(v5->m_P_a.m_quad, v5->m_P_a.m_quad, 0);
  v5->m_F_c.m_quad = _mm_movelh_ps(
                       _mm_unpacklo_ps(
                         _mm_mul_ps(_mm_add_ps(v11, v30), v15),
                         _mm_mul_ps(
                           _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(v30, (__m128)xmmword_141A710D0), v11), v37), v34),
                           v17)),
                       _mm_unpacklo_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(
                                     _mm_mul_ps(_mm_mul_ps(_mm_mul_ps((__m128)xmmword_141A710E0, v22), v19), v27),
                                     _mm_mul_ps(v31, v22)),
                                   _mm_mul_ps(_mm_mul_ps(_mm_mul_ps((__m128)xmmword_141A710E0, v12), v23), v33)),
                                 _mm_mul_ps(v32, v23)),
                               _mm_mul_ps(_mm_mul_ps((__m128)xmmword_141A710E0, v37), v34)),
                             _mm_mul_ps(
                               _mm_add_ps(_mm_mul_ps(v30, (__m128)xmmword_141A710E0), v11),
                               _mm_mul_ps(v37, v37))),
                           _mm_sub_ps((__m128)0i64, _mm_mul_ps(v16, v16))),
                         (__m128)xmmword_141A710D0));
  v5->m_Fbbc.m_real = _mm_mul_ps(
                        _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), v37), _mm_add_ps(_mm_mul_ps(v33, v12), v32)),
                        v15);
  v5->m_Fcca.m_real = _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_mul_ps(_mm_add_ps(v35, v29), (__m128)xmmword_141A710D0),
                              _mm_mul_ps(v36, v37)),
                            v37),
                          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v27, v21), _mm_mul_ps(v31, v12)), _mm_mul_ps(v33, v23))),
                        v17);
}

// File Line: 1320
// RVA: 0xC9C280
void __fastcall InternalInertiaTensorComputer::compVolumeIntegrals(InternalInertiaTensorComputer *this, hkGeometry *geom, hkVector4f *shift)
{
  __int64 v3; // rax
  hkVector4f *v4; // r14
  hkGeometry *v5; // rbp
  InternalInertiaTensorComputer *v6; // rbx
  __int64 v7; // rsi
  __int64 v8; // rdi
  hkGeometry::Triangle *v9; // rcx
  __m128 v10; // xmm0
  hkVector4f *v11; // rdx
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  signed __int64 v14; // rax
  __m128 v15; // xmm1
  __m128 v16; // xmm3
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm6
  __m128 v21; // xmm6
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm6
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  __m128 v27; // xmm0
  __m128 v28; // xmm2
  unsigned __int64 v29; // rcx
  __m128 v30; // xmm3
  __m128 v31; // xmm0
  __m128 v32; // xmm0
  __m128 v33; // xmm1
  int v34; // eax
  __m128 v35; // xmm0
  __m128 v36; // xmm0
  __m128 v37; // xmm0
  __m128 v38; // xmm1
  hkVector4f n; // [rsp+20h] [rbp-78h]
  hkVector4f v; // [rsp+30h] [rbp-68h]
  __m128 v41; // [rsp+40h] [rbp-58h]
  __m128 v42; // [rsp+50h] [rbp-48h]

  v3 = geom->m_triangles.m_size;
  v4 = shift;
  v5 = geom;
  v6 = this;
  this->m_T0 = 0i64;
  this->m_T1 = 0i64;
  this->m_T2 = 0i64;
  v7 = v3;
  this->m_TP = 0i64;
  if ( (signed int)v3 > 0 )
  {
    v8 = 0i64;
    do
    {
      v9 = v5->m_triangles.m_data;
      v10 = v4->m_quad;
      v11 = v5->m_vertices.m_data;
      v12 = _mm_add_ps(v11[v9[v8].m_a].m_quad, v4->m_quad);
      v13 = v11[v9[v8].m_b].m_quad;
      v14 = v9[v8].m_c;
      v.m_quad = v12;
      v15 = v11[v14].m_quad;
      v16 = _mm_add_ps(v13, v10);
      v41 = v16;
      v17 = _mm_add_ps(v15, v10);
      v18 = _mm_sub_ps(v16, v12);
      v42 = v17;
      v19 = _mm_sub_ps(v17, v12);
      v20 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v18), _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v19));
      v21 = _mm_shuffle_ps(v20, v20, 201);
      v22 = _mm_mul_ps(v21, v21);
      v23 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
              _mm_shuffle_ps(v22, v22, 170));
      if ( v23.m128_f32[0] > 0.0 )
      {
        v24 = _mm_mul_ps(v21, _mm_div_ps(query.m_quad, _mm_sqrt_ps(v23)));
        n.m_quad = v24;
        v25 = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v24, 1u), 1u);
        v6->m_C = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                                         _mm_and_ps(
                                                                           _mm_cmpleps(
                                                                             _mm_max_ps(
                                                                               _mm_shuffle_ps(v25, v25, 170),
                                                                               _mm_max_ps(
                                                                                 _mm_shuffle_ps(v25, v25, 85),
                                                                                 _mm_shuffle_ps(v25, v25, 0))),
                                                                             v25),
                                                                           (__m128)xmmword_141A78FC0))];
        InternalInertiaTensorComputer::compFaceIntegrals(v6, &v, &n);
        v26 = v6->m_F_c.m_quad;
        v27 = v6->m_F_b.m_quad;
        v28 = _mm_unpacklo_ps(v6->m_F_a.m_quad, v27);
        v29 = 16i64 * v6->m_C;
        v30 = _mm_unpackhi_ps(v6->m_F_a.m_quad, v27);
        v31 = _mm_movelh_ps(v28, v26);
        v6->m_F_a.m_quad = v31;
        v6->m_F_c.m_quad = _mm_shuffle_ps(v30, v26, 228);
        v6->m_F_b.m_quad = _mm_shuffle_ps(_mm_movehl_ps(v31, v28), v26, 212);
        v32 = _mm_and_ps((__m128)xmmword_141687F20[v29 / 0xFFFFFFFFFFFFFFF0ui64], v6->m_F_a.m_quad);
        v33 = _mm_or_ps(_mm_shuffle_ps(v32, v32, 78), v32);
        v6->m_T0.m_real = _mm_add_ps(
                            _mm_mul_ps(_mm_or_ps(_mm_shuffle_ps(v33, v33, 177), v33), _mm_shuffle_ps(v24, v24, 0)),
                            v6->m_T0.m_real);
        v34 = v6->m_C;
        v35 = v6->m_F_b.m_quad;
        if ( v6->m_C )
        {
          if ( v34 == 1 )
            v35 = _mm_shuffle_ps(v35, v35, 201);
        }
        else
        {
          v35 = _mm_shuffle_ps(v35, v35, 210);
        }
        v6->m_T1.m_quad = _mm_add_ps(_mm_mul_ps(v35, v24), v6->m_T1.m_quad);
        v36 = v6->m_F_c.m_quad;
        if ( v34 )
        {
          if ( v34 == 1 )
            v36 = _mm_shuffle_ps(v36, v36, 201);
        }
        else
        {
          v36 = _mm_shuffle_ps(v36, v36, 210);
        }
        v6->m_T2.m_quad = _mm_add_ps(_mm_mul_ps(v36, v24), v6->m_T2.m_quad);
        if ( v34 )
        {
          if ( v34 == 1 )
          {
            v37 = v6->m_Faab.m_real;
            v38 = _mm_unpacklo_ps(v6->m_Fbbc.m_real, v6->m_Fcca.m_real);
          }
          else
          {
            v37 = v6->m_Fcca.m_real;
            v38 = _mm_unpacklo_ps(v6->m_Faab.m_real, v6->m_Fbbc.m_real);
          }
        }
        else
        {
          v37 = v6->m_Fbbc.m_real;
          v38 = _mm_unpacklo_ps(v6->m_Fcca.m_real, v6->m_Faab.m_real);
        }
        v6->m_TP.m_quad = _mm_add_ps(_mm_mul_ps(_mm_movelh_ps(v38, _mm_unpacklo_ps(v37, v37)), v24), v6->m_TP.m_quad);
      }
      ++v8;
      --v7;
    }
    while ( v7 );
  }
  v6->m_T1.m_quad = _mm_mul_ps(v6->m_T1.m_quad, (__m128)xmmword_141A711B0);
  v6->m_T2.m_quad = _mm_mul_ps((__m128)xmmword_141A711C0, v6->m_T2.m_quad);
  v6->m_TP.m_quad = _mm_mul_ps(v6->m_TP.m_quad, (__m128)xmmword_141A711B0);
}

// File Line: 1392
// RVA: 0xC9BAA0
void __fastcall InternalInertiaTensorComputer::computeInertialTensorInternal(InternalInertiaTensorComputer *this, hkSimdFloat32 *mass, hkSimdFloat32 *density, hkVector4f *r, hkMatrix3f *J)
{
  hkVector4f v5; // xmm5
  __m128 v6; // xmm1
  __m128 v7; // xmm7
  __m128 v8; // xmm6

  v5.m_quad = _mm_mul_ps(this->m_T1.m_quad, _mm_div_ps(query.m_quad, this->m_T0.m_real));
  *r = (hkVector4f)v5.m_quad;
  v6 = _mm_mul_ps(v5.m_quad, v5.m_quad);
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
         _mm_mul_ps(_mm_mul_ps(_mm_shuffle_ps(v5.m_quad, v5.m_quad, 201), v5.m_quad), mass->m_real),
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
void __fastcall InternalInertiaTensorComputer::compGeometryAabb(const float *vertices, int numVerts, int striding, hkVector4f *centerOut, hkVector4f *aabbExtentsOut)
{
  __m128 v5; // xmm3
  __m128 v6; // xmm2
  __int64 v7; // rax
  __m128 v8; // xmm1
  hkVector4f v9; // xmm2

  *centerOut = 0i64;
  *aabbExtentsOut = 0i64;
  v5 = (__m128)xmmword_141A712A0;
  v6 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
  if ( numVerts > 0 )
  {
    v7 = (unsigned int)numVerts;
    do
    {
      v8 = *(__m128 *)vertices;
      vertices = (const float *)((char *)vertices + striding);
      v6 = _mm_max_ps(v8, v6);
      v5 = _mm_min_ps(v8, v5);
      --v7;
    }
    while ( v7 );
  }
  if ( numVerts )
  {
    v9.m_quad = _mm_sub_ps(v6, v5);
    centerOut->m_quad = _mm_add_ps(_mm_mul_ps(v9.m_quad, (__m128)xmmword_141A711B0), v5);
    *aabbExtentsOut = (hkVector4f)v9.m_quad;
  }
}

// File Line: 1468
// RVA: 0xC9AED0
void __usercall hkInertiaTensorComputer::computeGeometryVolumeMassProperties(hkGeometry *geom@<rcx>, float mass@<xmm1>, hkMassProperties *result@<r8>, __m128 a4@<xmm0>)
{
  int v4; // edx
  hkGeometry *v5; // rbx
  hkVector4f *v6; // rcx
  __m128 v7; // xmm0
  hkMassProperties *v8; // rsi
  __m128 v9; // xmm1
  __m128 v10; // xmm6
  __m128 v11; // xmm10
  __m128 v12; // xmm1
  float v13; // xmm0_4
  float v14; // xmm1_4
  hkVector4f v15; // xmm1
  hkVector4f v16; // xmm0
  __m128 v17; // xmm8
  __m128 v18; // xmm6
  __m128 v19; // xmm2
  __m128 v20; // xmm7
  __m128 v21; // xmm5
  __m128 v22; // xmm4
  __m128 v23; // xmm3
  __m128 v24; // xmm2
  __m128 v25; // xmm3
  __m128 v26; // xmm2
  char v27; // al
  __int64 v28; // kr00_8
  int v29; // xmm0_4
  float v30; // xmm1_4
  unsigned __int64 v31; // kr08_8
  hkVector4f halfExtents; // [rsp+30h] [rbp-C8h]
  hkSimdFloat32 massa; // [rsp+40h] [rbp-B8h]
  hkVector4f centerOut; // [rsp+50h] [rbp-A8h]
  hkMassProperties resulta; // [rsp+60h] [rbp-98h]
  __int128 v36; // [rsp+178h] [rbp+80h]
  void *retaddr; // [rsp+218h] [rbp+120h]

  v4 = geom->m_vertices.m_size;
  a4.m128_f32[0] = mass;
  v5 = geom;
  v6 = geom->m_vertices.m_data;
  v7 = _mm_shuffle_ps(a4, a4, 0);
  v8 = result;
  v9 = _mm_cmpleps(v7, (__m128)0i64);
  v10 = _mm_or_ps(_mm_andnot_ps(v9, v7), _mm_and_ps(v9, query.m_quad));
  massa.m_real = v10;
  InternalInertiaTensorComputer::compGeometryAabb(v6->m_quad.m128_f32, v4, 16, &centerOut, &halfExtents);
  resulta.m_centerOfMass = 0i64;
  *(hkVector4f *)((char *)&resulta.m_centerOfMass + 8) = 0i64;
  *(hkVector4f *)((char *)&resulta.m_inertiaTensor.m_col0 + 8) = 0i64;
  *(_QWORD *)&resulta.m_volume = 0i64;
  *(hkVector4f *)((char *)&resulta.m_inertiaTensor.m_col1 + 8) = 0i64;
  hkInertiaTensorComputer::computeBoxVolumeMassProperties((hkResult *)&retaddr, &halfExtents, v10.m128_f32[0], &resulta);
  v11 = centerOut.m_quad;
  halfExtents.m_quad = _mm_xor_ps(
                         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                         centerOut.m_quad);
  InternalInertiaTensorComputer::compVolumeIntegrals(
    (InternalInertiaTensorComputer *)&resulta.m_inertiaTensor.m_col2.m_quad.m128_u16[4],
    v5,
    &halfExtents);
  v12 = (__m128)v36;
  if ( *(float *)&v36 > 0.0 )
  {
    LODWORD(v8->m_volume) = v36;
    LODWORD(v8->m_mass) = v10.m128_i32[0];
    halfExtents.m_quad = _mm_div_ps(v10, v12);
    InternalInertiaTensorComputer::computeInertialTensorInternal(
      (InternalInertiaTensorComputer *)&resulta.m_inertiaTensor.m_col2.m_quad.m128_u16[4],
      &massa,
      (hkSimdFloat32 *)&halfExtents,
      &v8->m_centerOfMass,
      &v8->m_inertiaTensor);
    v17 = _mm_add_ps(v8->m_centerOfMass.m_quad, v11);
    v8->m_centerOfMass.m_quad = v17;
    v18 = _mm_or_ps(
            _mm_andnot_ps(
              (__m128)xmmword_141A78F90,
              _mm_or_ps(
                _mm_andnot_ps((__m128)xmmword_141A78F70, v8->m_inertiaTensor.m_col0.m_quad),
                _mm_and_ps(v8->m_inertiaTensor.m_col1.m_quad, (__m128)xmmword_141A78F70))),
            _mm_and_ps((__m128)xmmword_141A78F90, v8->m_inertiaTensor.m_col2.m_quad));
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
    v20 = _mm_cmpltps(v18, v19);
    v21 = _mm_or_ps(_mm_and_ps(v20, v19), _mm_andnot_ps(v20, v18));
    v8->m_centerOfMass.m_quad = _mm_or_ps(_mm_andnot_ps(v20, v17), _mm_and_ps(v20, v11));
    v22 = v8->m_inertiaTensor.m_col0.m_quad;
    v22.m128_f32[0] = v21.m128_f32[0];
    v23 = _mm_andnot_ps((__m128)xmmword_141A78F70, v8->m_inertiaTensor.m_col1.m_quad);
    v24 = _mm_andnot_ps((__m128)xmmword_141A78F90, v8->m_inertiaTensor.m_col2.m_quad);
    v8->m_inertiaTensor.m_col0.m_quad = v22;
    v25 = _mm_or_ps(v23, _mm_and_ps((__m128)xmmword_141A78F70, v21));
    v26 = _mm_or_ps(v24, _mm_and_ps((__m128)xmmword_141A78F90, v21));
    v8->m_inertiaTensor.m_col1.m_quad = v25;
    v8->m_inertiaTensor.m_col2.m_quad = v26;
    massa.m_real = _mm_max_ps((__m128)0i64, v22);
    centerOut.m_quad = _mm_max_ps((__m128)0i64, v25);
    halfExtents.m_quad = _mm_max_ps((__m128)0i64, v26);
    v27 = _mm_movemask_ps(v20);
    if ( v27 & 1 )
    {
      v28 = *(__int64 *)((char *)massa.m_real.m128_i64 + 4);
      v8->m_inertiaTensor.m_col1.m_quad.m128_i32[0] = massa.m_real.m128_i32[1];
      v8->m_inertiaTensor.m_col0.m_quad.m128_i32[1] = v28;
      v8->m_inertiaTensor.m_col2.m_quad.m128_i32[0] = HIDWORD(v28);
      v8->m_inertiaTensor.m_col0.m_quad.m128_i32[2] = HIDWORD(v28);
    }
    if ( v27 & 2 )
    {
      v29 = centerOut.m_quad.m128_i32[0];
      v30 = centerOut.m_quad.m128_f32[2];
      v8->m_inertiaTensor.m_col0.m_quad.m128_i32[1] = centerOut.m_quad.m128_i32[0];
      v8->m_inertiaTensor.m_col1.m_quad.m128_i32[0] = v29;
      v8->m_inertiaTensor.m_col2.m_quad.m128_f32[1] = v30;
      v8->m_inertiaTensor.m_col1.m_quad.m128_f32[2] = v30;
    }
    if ( v27 & 4 )
    {
      v31 = halfExtents.m_quad.m128_u64[0];
      v8->m_inertiaTensor.m_col0.m_quad.m128_i32[2] = halfExtents.m_quad.m128_i32[0];
      v8->m_inertiaTensor.m_col2.m_quad.m128_i32[0] = v31;
      v8->m_inertiaTensor.m_col1.m_quad.m128_i32[2] = HIDWORD(v31);
      v8->m_inertiaTensor.m_col2.m_quad.m128_i32[1] = HIDWORD(v31);
    }
  }
  else
  {
    v13 = resulta.m_volume;
    v14 = resulta.m_mass;
    v8->m_centerOfMass.m_quad = v11;
    v8->m_volume = v13;
    v8->m_mass = v14;
    v15.m_quad = *(__m128 *)((char *)&resulta.m_inertiaTensor.m_col0 + 8);
    v8->m_inertiaTensor.m_col0 = *(hkVector4f *)((char *)&resulta.m_centerOfMass + 8);
    v16.m_quad = *(__m128 *)((char *)&resulta.m_inertiaTensor.m_col1 + 8);
    v8->m_inertiaTensor.m_col1 = (hkVector4f)v15.m_quad;
    v8->m_inertiaTensor.m_col2 = (hkVector4f)v16.m_quad;
  }
}

// File Line: 1565
// RVA: 0xC9B200
hkResult *__usercall hkInertiaTensorComputer::computeGeometryVolumeMassPropertiesChecked@<rax>(hkResult *result@<rcx>, hkGeometry *geom@<rdx>, float mass@<xmm2>, hkMassProperties *a4@<r9>, __m128 a5@<xmm6>)
{
  hkMassProperties *v5; // r14
  hkGeometry *v6; // rbx
  hkResult *v7; // rsi
  __m128 v8; // xmm6
  hkResult *v9; // rax
  __m128 v10; // xmm10
  __m128 v11; // xmm6
  __m128 v12; // xmm8
  __m128 v13; // xmm6
  __m128 v14; // xmm2
  __m128 v15; // xmm7
  char v16; // al
  __m128 v17; // xmm5
  __m128 v18; // xmm4
  __m128 v19; // xmm3
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __int64 v23; // kr00_8
  int v24; // xmm0_4
  float v25; // xmm1_4
  unsigned __int64 v26; // kr08_8
  hkResult resulta; // [rsp+30h] [rbp-C8h]
  hkVector4f halfExtents; // [rsp+40h] [rbp-B8h]
  hkVector4f centerOut; // [rsp+50h] [rbp-A8h]
  hkSimdFloat32 massa; // [rsp+60h] [rbp-98h]
  hkMassProperties v31; // [rsp+70h] [rbp-88h]
  __m128 v32; // [rsp+188h] [rbp+90h]

  v5 = a4;
  v6 = geom;
  v7 = result;
  a5.m128_f32[0] = mass;
  v8 = _mm_shuffle_ps(a5, a5, 0);
  massa.m_real = v8;
  if ( v8.m128_f32[0] > 0.0 )
  {
    InternalInertiaTensorComputer::compGeometryAabb(
      geom->m_vertices.m_data->m_quad.m128_f32,
      geom->m_vertices.m_size,
      16,
      &centerOut,
      &halfExtents);
    *(_OWORD *)(&v31.m_mass + 1) = 0i64;
    *(hkVector4f *)((char *)&v31.m_centerOfMass + 8) = 0i64;
    *(_QWORD *)&v31.m_volume = 0i64;
    *(hkVector4f *)((char *)&v31.m_inertiaTensor.m_col0 + 8) = 0i64;
    *(hkVector4f *)((char *)&v31.m_inertiaTensor.m_col1 + 8) = 0i64;
    hkInertiaTensorComputer::computeBoxVolumeMassProperties(&resulta, &halfExtents, mass, &v31);
    v10 = centerOut.m_quad;
    halfExtents.m_quad = _mm_xor_ps(
                           (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                           centerOut.m_quad);
    InternalInertiaTensorComputer::compVolumeIntegrals(
      (InternalInertiaTensorComputer *)&v31.m_inertiaTensor.m_col2.m_quad.m128_u16[4],
      v6,
      &halfExtents);
    if ( v32.m128_f32[0] > 0.0 )
    {
      v11 = _mm_div_ps(v8, v32);
      LODWORD(v5->m_volume) = v32.m128_i32[0];
      v5->m_mass = mass;
      halfExtents.m_quad = v11;
      InternalInertiaTensorComputer::computeInertialTensorInternal(
        (InternalInertiaTensorComputer *)&v31.m_inertiaTensor.m_col2.m_quad.m128_u16[4],
        &massa,
        (hkSimdFloat32 *)&halfExtents,
        &v5->m_centerOfMass,
        &v5->m_inertiaTensor);
      v12 = _mm_add_ps(v10, v5->m_centerOfMass.m_quad);
      v5->m_centerOfMass.m_quad = v12;
      v13 = _mm_or_ps(
              _mm_andnot_ps(
                (__m128)xmmword_141A78F90,
                _mm_or_ps(
                  _mm_andnot_ps((__m128)xmmword_141A78F70, v5->m_inertiaTensor.m_col0.m_quad),
                  _mm_and_ps(v5->m_inertiaTensor.m_col1.m_quad, (__m128)xmmword_141A78F70))),
              _mm_and_ps((__m128)xmmword_141A78F90, v5->m_inertiaTensor.m_col2.m_quad));
      resulta.m_enum = LODWORD(FLOAT_0_1);
      v14 = _mm_mul_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  (__m128)xmmword_141A78F90,
                  _mm_or_ps(
                    _mm_andnot_ps((__m128)xmmword_141A78F70, *(__m128 *)((char *)&v31.m_centerOfMass.m_quad + 8)),
                    _mm_and_ps(*(__m128 *)((char *)&v31.m_inertiaTensor.m_col0.m_quad + 8), (__m128)xmmword_141A78F70))),
                _mm_and_ps(*(__m128 *)((char *)&v31.m_inertiaTensor.m_col1.m_quad + 8), (__m128)xmmword_141A78F90)),
              _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_1), (__m128)LODWORD(FLOAT_0_1), 0));
      v15 = _mm_cmpltps(v13, v14);
      v16 = _mm_movemask_ps(v15);
      v17 = _mm_or_ps(_mm_and_ps(v15, v14), _mm_andnot_ps(v15, v13));
      v5->m_centerOfMass.m_quad = _mm_or_ps(_mm_and_ps(v15, v10), _mm_andnot_ps(v15, v12));
      v18 = v5->m_inertiaTensor.m_col0.m_quad;
      v18.m128_f32[0] = v17.m128_f32[0];
      v19 = _mm_andnot_ps((__m128)xmmword_141A78F70, v5->m_inertiaTensor.m_col1.m_quad);
      v20 = _mm_andnot_ps((__m128)xmmword_141A78F90, v5->m_inertiaTensor.m_col2.m_quad);
      v5->m_inertiaTensor.m_col0.m_quad = v18;
      v21 = _mm_or_ps(v19, _mm_and_ps((__m128)xmmword_141A78F70, v17));
      v22 = _mm_or_ps(v20, _mm_and_ps((__m128)xmmword_141A78F90, v17));
      v5->m_inertiaTensor.m_col1.m_quad = v21;
      v5->m_inertiaTensor.m_col2.m_quad = v22;
      massa.m_real = _mm_max_ps((__m128)0i64, v18);
      centerOut.m_quad = _mm_max_ps((__m128)0i64, v21);
      halfExtents.m_quad = _mm_max_ps((__m128)0i64, v22);
      if ( v16 & 1 )
      {
        v23 = *(__int64 *)((char *)massa.m_real.m128_i64 + 4);
        v5->m_inertiaTensor.m_col1.m_quad.m128_i32[0] = massa.m_real.m128_i32[1];
        v5->m_inertiaTensor.m_col0.m_quad.m128_i32[1] = v23;
        v5->m_inertiaTensor.m_col2.m_quad.m128_i32[0] = HIDWORD(v23);
        v5->m_inertiaTensor.m_col0.m_quad.m128_i32[2] = HIDWORD(v23);
      }
      if ( v16 & 2 )
      {
        v24 = centerOut.m_quad.m128_i32[0];
        v25 = centerOut.m_quad.m128_f32[2];
        v5->m_inertiaTensor.m_col0.m_quad.m128_i32[1] = centerOut.m_quad.m128_i32[0];
        v5->m_inertiaTensor.m_col1.m_quad.m128_i32[0] = v24;
        v5->m_inertiaTensor.m_col2.m_quad.m128_f32[1] = v25;
        v5->m_inertiaTensor.m_col1.m_quad.m128_f32[2] = v25;
      }
      if ( v16 & 4 )
      {
        v26 = halfExtents.m_quad.m128_u64[0];
        v5->m_inertiaTensor.m_col0.m_quad.m128_i32[2] = halfExtents.m_quad.m128_i32[0];
        v5->m_inertiaTensor.m_col2.m_quad.m128_i32[0] = v26;
        v5->m_inertiaTensor.m_col1.m_quad.m128_i32[2] = HIDWORD(v26);
        v5->m_inertiaTensor.m_col2.m_quad.m128_i32[1] = HIDWORD(v26);
      }
      v7->m_enum = 0;
    }
    else
    {
      v7->m_enum = 1;
    }
    v9 = v7;
  }
  else
  {
    result->m_enum = 1;
    v9 = result;
  }
  return v9;
}

// File Line: 1663
// RVA: 0xC98B70
void __fastcall hkMassProperties::scaleToMass(hkMassProperties *this, hkSimdFloat32 *newMass)
{
  __m128 v2; // xmm1
  hkMatrix3f *v3; // rcx
  __m128 v4; // xmm0
  hkSimdFloat32 scale; // [rsp+20h] [rbp-18h]

  v2 = (__m128)LODWORD(this->m_mass);
  v3 = &this->m_inertiaTensor;
  v4 = _mm_div_ps(newMass->m_real, _mm_shuffle_ps(v2, v2, 0));
  v3[-1].m_col1.m_quad.m128_i32[1] = (int)*newMass;
  scale.m_real = v4;
  hkMatrix3f::mul(v3, &scale);
}

// File Line: 1672
// RVA: 0xC98B40
void __fastcall hkMassProperties::scaleToDensity(hkMassProperties *this, hkSimdFloat32 *density)
{
  hkSimdFloat32 newMass; // [rsp+20h] [rbp-18h]

  newMass.m_real = _mm_mul_ps(
                     _mm_shuffle_ps((__m128)LODWORD(this->m_volume), (__m128)LODWORD(this->m_volume), 0),
                     density->m_real);
  hkMassProperties::scaleToMass(this, &newMass);
}

// File Line: 1682
// RVA: 0xC9A6D0
hkResult *__usercall hkInertiaTensorComputer::computeApproximateConvexHullMassProperties@<rax>(hkResult *result@<rcx>, hkStridedVertices *vertices@<rdx>, float radius@<xmm2>, hkMassProperties *a4@<r9>, __m128 a5@<xmm0>)
{
  hkResult *v5; // rbx
  hkMassProperties *v6; // rdi
  __m128 v7; // xmm0
  hkResult *v8; // rax
  hkVector4f halfExtents; // [rsp+30h] [rbp-38h]
  hkVector4f centerOut; // [rsp+40h] [rbp-28h]

  v5 = result;
  v6 = a4;
  InternalInertiaTensorComputer::compGeometryAabb(
    vertices->m_vertices,
    vertices->m_numVertices,
    vertices->m_striding,
    &centerOut,
    &halfExtents);
  a5.m128_f32[0] = radius;
  halfExtents.m_quad = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, halfExtents.m_quad), _mm_shuffle_ps(a5, a5, 0));
  hkInertiaTensorComputer::computeBoxVolumeMassProperties(v5, &halfExtents, 1.0, v6);
  v7 = centerOut.m_quad;
  v8 = v5;
  v6->m_mass = 1.0;
  v6->m_centerOfMass.m_quad = v7;
  return v8;
}

// File Line: 1700
// RVA: 0xC9B7D0
void __fastcall hkInertiaTensorComputer::convertInertiaTensorToPrincipleAxis(hkMatrix3f *inertia, hkRotationf *principleAxisOut)
{
  hkRotationf *v2; // rdi
  hkMatrix3f *v3; // rbx
  __m128 v4; // xmm1
  __m128 v5; // xmm1
  __m128 v6; // xmm3
  __m128 v7; // xmm2
  __m128 v8; // xmm5
  __m128 v9; // xmm5
  __m128 v10; // xmm5
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm4
  __m128 v15; // xmm5
  __m128 v16; // xmm5
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  __m128 v19; // xmm1
  hkVector4f eigenVal; // [rsp+20h] [rbp-48h]

  v2 = principleAxisOut;
  v3 = inertia;
  hkMatrix3f::diagonalizeSymmetricApproximation(inertia, principleAxisOut, &eigenVal, 10);
  v4 = _mm_max_ps(eigenVal.m_quad, *(__m128 *)&epsilon);
  v3->m_col0.m_quad = _mm_mul_ps(v4, transform.m_quad);
  v3->m_col1.m_quad = _mm_mul_ps(v4, direction.m_quad);
  v3->m_col2.m_quad = _mm_mul_ps(v4, stru_141A71280.m_quad);
  v5 = _mm_mul_ps(v2->m_col0.m_quad, v2->m_col0.m_quad);
  v6 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v5, v5, 85), _mm_shuffle_ps(v5, v5, 0)), _mm_shuffle_ps(v5, v5, 170));
  v7 = _mm_rsqrt_ps(v6);
  v8 = _mm_mul_ps(
         _mm_andnot_ps(
           _mm_cmpleps(v6, (__m128)0i64),
           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v7, v6), v7)), _mm_mul_ps(*(__m128 *)_xmm, v7))),
         v2->m_col0.m_quad);
  v2->m_col0.m_quad = v8;
  v9 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v2->m_col2.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(v2->m_col2.m_quad, v2->m_col2.m_quad, 201), v8));
  v10 = _mm_shuffle_ps(v9, v9, 201);
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_mul_ps(
          _mm_andnot_ps(
            _mm_cmpleps(v12, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
              _mm_mul_ps(*(__m128 *)_xmm, v13))),
          v10);
  v2->m_col1.m_quad = v14;
  v15 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v2->m_col0.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(v2->m_col0.m_quad, v2->m_col0.m_quad, 201), v14));
  v16 = _mm_shuffle_ps(v15, v15, 201);
  v17 = _mm_mul_ps(v16, v16);
  v18 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)), _mm_shuffle_ps(v17, v17, 170));
  v19 = _mm_rsqrt_ps(v18);
  v2->m_col2.m_quad = _mm_mul_ps(
                        _mm_andnot_ps(
                          _mm_cmpleps(v18, (__m128)0i64),
                          _mm_mul_ps(
                            _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                            _mm_mul_ps(*(__m128 *)_xmm, v19))),
                        v16);
}

