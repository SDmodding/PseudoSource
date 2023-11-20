// File Line: 16
// RVA: 0x15D4430
void dynamic_initializer_for__hkOptionalComponent_hkpAccurateInertiaTensorComputer__()
{
  hkOptionalComponent::hkOptionalComponent(
    &hkOptionalComponent_hkpAccurateInertiaTensorComputer,
    "hkpAccurateInertiaTensorComputer",
    (void **)&hkInertiaTensorComputer::s_computeConvexHullMassPropertiesFunction,
    hkpAccurateInertiaTensorComputer::computeConvexHullMassProperties);
}

// File Line: 19
// RVA: 0xE11600
hkResult *__usercall hkpAccurateInertiaTensorComputer::computeConvexHullMassProperties@<rax>(hkResult *result@<rcx>, hkStridedVertices *vertices@<rdx>, float r@<xmm2>, hkMassProperties *a4@<r9>, __m128 *a5@<xmm3>, __int128 a6@<xmm10>)
{
  hkResult *v6; // rbx
  hkMassProperties *v7; // rsi
  hkStridedVertices *v8; // rdi
  __m128 v9; // xmm7
  float v10; // xmm9_4
  __m128 v11; // xmm7
  __m128 v12; // xmm8
  __m128 v13; // xmm6
  int v14; // eax
  __m128 *v15; // xmm4_8
  int v16; // eax
  int v17; // eax
  float v18; // xmm7_4
  hkMatrix3f *v19; // rax
  __m128 v20; // xmm0
  signed int v21; // er10
  __int64 v22; // r14
  const float *v23; // r15
  unsigned __int64 *v24; // rcx
  hkgpConvexHull::BuildConfig v25; // xmm1
  __m128 v26; // xmm4
  signed int v27; // er9
  signed int v28; // eax
  __m128 v29; // xmm4
  signed int v30; // er11
  float v31; // xmm3_4
  unsigned int *v32; // rdx
  __m128 v33; // xmm1
  float v34; // xmm2_4
  __int64 mass; // [rsp+20h] [rbp-C8h]
  hkResult resulta; // [rsp+38h] [rbp-B0h]
  hkgpConvexHull v38; // [rsp+40h] [rbp-A8h]
  hkResult v39; // [rsp+68h] [rbp-80h]
  hkgpConvexHull::BuildConfig config; // [rsp+70h] [rbp-78h]
  hkVector4f endAxis; // [rsp+88h] [rbp-60h]
  hkSimdFloat32 v42; // [rsp+98h] [rbp-50h]
  hkSimdFloat32 v43; // [rsp+A8h] [rbp-40h]
  __int128 v44; // [rsp+E0h] [rbp-8h]
  void *retaddr; // [rsp+148h] [rbp+60h]

  v6 = result;
  v7 = a4;
  v8 = vertices;
  hkOptionalComponent_hkpAccurateInertiaTensorComputer.m_isUsed.m_bool = 1;
  hkgpConvexHull::hkgpConvexHull(&v38);
  hkgpConvexHull::BuildConfig::BuildConfig(&config);
  *(_WORD *)&config.m_allowLowerDimensions.m_bool = 1;
  hkgpConvexHull::build(&v38, v8, &config);
  v9 = (__m128)(unsigned int)retaddr;
  *(float *)&retaddr = r;
  v13 = (__m128)LODWORD(r);
  v10 = 0.0;
  v11 = _mm_shuffle_ps(v9, v9, 0);
  *(float *)&resulta.m_enum = 0.000011920929;
  v12 = 0i64;
  v13.m128_f32[0] = fmaxf(r, 0.000011920929);
  v14 = hkgpConvexHull::getDimensions(&v38);
  if ( !v14 )
  {
    hkInertiaTensorComputer::computeSphereVolumeMassProperties(v6, v13.m128_f32[0], 1.0, v7, a5, v15);
    goto LABEL_28;
  }
  v16 = v14 - 1;
  if ( v16 )
  {
    v17 = v16 - 1;
    if ( v17 )
    {
      if ( v17 != 1 )
      {
        v6->m_enum = 1;
LABEL_28:
        hkgpConvexHull::~hkgpConvexHull(&v38);
        return v6;
      }
      hkgpConvexHull::buildMassProperties(&v38, &resulta);
      if ( v11.m128_f32[0] > 0.0 )
        v12 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_shuffle_ps((__m128)LODWORD(FLOAT_4_1887903), (__m128)LODWORD(FLOAT_4_1887903), 0),
                      v11),
                    v11),
                  v11),
                _mm_mul_ps(hkgpConvexHull::getSurfaceArea(&v38, &v43)->m_real, v11));
    }
    else
    {
      v44 = a6;
      v18 = fmaxf(hkConvexShapeDefaultRadius * 0.2, v11.m128_f32[0]);
      while ( 1 )
      {
        hkgpConvexHull::expandByPlanarMargin(&v38, (hkBool *)&retaddr, v18);
        if ( (unsigned int)hkgpConvexHull::getDimensions(&v38) == 3 )
          hkgpConvexHull::buildMassProperties(&v38, &v39);
        v18 = v18 * 2.0;
        if ( (unsigned int)hkgpConvexHull::getDimensions(&v38) == 3 )
        {
          v13.m128_f32[0] = *(float *)&resulta.m_enum;
          v13 = _mm_shuffle_ps(v13, v13, 0);
          if ( COERCE_FLOAT(*hkgpConvexHull::getVolume(&v38, &v42)) >= v13.m128_f32[0] )
            break;
        }
      }
    }
    v7->m_centerOfMass = (hkVector4f)hkgpConvexHull::getCenterOfMass(&v38)->m_quad;
    v19 = hkgpConvexHull::getWorldInertia(&v38);
    v7->m_inertiaTensor.m_col0 = v19->m_col0;
    v7->m_inertiaTensor.m_col1 = v19->m_col1;
    v7->m_inertiaTensor.m_col2 = v19->m_col2;
    v20 = _mm_add_ps(hkgpConvexHull::getVolume(&v38, &v42)->m_real, v12);
    LODWORD(v7->m_volume) = v20.m128_i32[0];
    v7->m_mass = 1.0;
    if ( v20.m128_f32[0] > 0.0 && v12.m128_f32[0] > 0.0 )
    {
      config = (hkgpConvexHull::BuildConfig)_mm_add_ps(
                                              _mm_div_ps(
                                                _mm_add_ps(v12, v12),
                                                _mm_mul_ps(v20, (__m128)xmmword_141A710E0)),
                                              query.m_quad);
      hkMatrix3f::mul(&v7->m_inertiaTensor, (hkSimdFloat32 *)&config);
    }
    v6->m_enum = 0;
    goto LABEL_28;
  }
  v21 = v8->m_numVertices;
  v22 = v8->m_striding;
  v23 = v8->m_vertices;
  v24 = (unsigned __int64 *)((char *)v8->m_vertices + v22);
  v25 = (hkgpConvexHull::BuildConfig)_mm_movelh_ps(
                                       (__m128)*(unsigned __int64 *)v8->m_vertices,
                                       (__m128)*((unsigned int *)v8->m_vertices + 2));
  config = v25;
  v26 = _mm_movelh_ps((__m128)*v24, (__m128)*((unsigned int *)v24 + 2));
  endAxis.m_quad = v26;
  if ( v21 > 2 )
  {
    v27 = 0;
    v28 = 1;
    v29 = _mm_sub_ps(v26, (__m128)v25);
    v30 = 0;
    v31 = 0.0;
    if ( v21 > 1 )
    {
      v32 = (unsigned int *)(v24 + 1);
      do
      {
        v33 = _mm_mul_ps(_mm_movelh_ps((__m128)*v24, (__m128)*v32), v29);
        v34 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 0)))
            + COERCE_FLOAT(_mm_shuffle_ps(v33, v33, 170));
        if ( v34 > v31 )
        {
          v30 = v28;
          v31 = v34;
        }
        if ( v34 < v10 )
        {
          v27 = v28;
          v10 = v34;
        }
        ++v28;
        v24 = (unsigned __int64 *)((char *)v24 + v22);
        v32 = (unsigned int *)((char *)v32 + v22);
      }
      while ( v28 < v21 );
    }
    config = (hkgpConvexHull::BuildConfig)_mm_movelh_ps(
                                            (__m128)*(unsigned __int64 *)((char *)v23 + v27 * (signed int)v22),
                                            (__m128)*(unsigned int *)((char *)v23 + v27 * (signed int)v22 + 8));
    endAxis.m_quad = _mm_movelh_ps(
                       (__m128)*(unsigned __int64 *)((char *)v23 + v30 * (signed int)v22),
                       (__m128)*(unsigned int *)((char *)v23 + v30 * (signed int)v22 + 8));
  }
  LODWORD(mass) = (_DWORD)FLOAT_1_0;
  hkInertiaTensorComputer::computeCapsuleVolumeMassProperties(
    v6,
    (hkVector4f *)&config,
    &endAxis,
    v13.m128_f32[0],
    (__m128 *)a6,
    mass,
    v7);
  hkgpConvexHull::~hkgpConvexHull(&v38);
  return v6;
}

