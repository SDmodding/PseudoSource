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
hkResult *__fastcall hkpAccurateInertiaTensorComputer::computeConvexHullMassProperties(
        hkResult *result,
        hkStridedVertices *vertices,
        float r,
        hkMassProperties *a4)
{
  double v4; // xmm3_8
  __m128 v8; // xmm7
  float v9; // xmm9_4
  __m128 v10; // xmm7
  __m128 v11; // xmm8
  __m128 v12; // xmm6
  int Dimensions; // eax
  int v14; // eax
  int v15; // eax
  float v16; // xmm7_4
  __m128 v17; // xmm0
  int m_numVertices; // r10d
  __int64 m_striding; // r14
  const float *m_vertices; // r15
  unsigned __int64 *v21; // rcx
  hkgpConvexHull::BuildConfig v22; // xmm1
  __m128 v23; // xmm4
  int v24; // r9d
  int v25; // eax
  __m128 v26; // xmm4
  int v27; // r11d
  float v28; // xmm3_4
  unsigned int *v29; // rdx
  __m128 v30; // xmm1
  float v31; // xmm2_4
  hkMassProperties *mass; // [rsp+20h] [rbp-C8h]
  hkResult resulta; // [rsp+38h] [rbp-B0h] BYREF
  hkgpConvexHull v35; // [rsp+40h] [rbp-A8h] BYREF
  hkResult v36; // [rsp+68h] [rbp-80h] BYREF
  hkgpConvexHull::BuildConfig config; // [rsp+70h] [rbp-78h] BYREF
  hkVector4f endAxis; // [rsp+88h] [rbp-60h] BYREF
  hkSimdFloat32 v39; // [rsp+98h] [rbp-50h] BYREF
  hkSimdFloat32 v40; // [rsp+A8h] [rbp-40h] BYREF
  void *retaddr; // [rsp+148h] [rbp+60h] BYREF

  hkOptionalComponent_hkpAccurateInertiaTensorComputer.m_isUsed.m_bool = 1;
  hkgpConvexHull::hkgpConvexHull(&v35);
  hkgpConvexHull::BuildConfig::BuildConfig(&config);
  *(_WORD *)&config.m_allowLowerDimensions.m_bool = 1;
  hkgpConvexHull::build(&v35, vertices, &config);
  v8 = (__m128)(unsigned int)retaddr;
  *(float *)&retaddr = r;
  v12 = (__m128)LODWORD(r);
  v9 = 0.0;
  v10 = _mm_shuffle_ps(v8, v8, 0);
  *(float *)&resulta.m_enum = 0.000011920929;
  v11 = 0i64;
  v12.m128_f32[0] = fmaxf(r, 0.000011920929);
  Dimensions = hkgpConvexHull::getDimensions(&v35);
  if ( !Dimensions )
  {
    hkInertiaTensorComputer::computeSphereVolumeMassProperties(result, v12.m128_f32[0], 1.0, a4);
    goto LABEL_27;
  }
  v14 = Dimensions - 1;
  if ( v14 )
  {
    v15 = v14 - 1;
    if ( v15 )
    {
      if ( v15 != 1 )
      {
        result->m_enum = HK_FAILURE;
LABEL_27:
        hkgpConvexHull::~hkgpConvexHull(&v35);
        return result;
      }
      hkgpConvexHull::buildMassProperties(&v35, &resulta);
      if ( v10.m128_f32[0] > 0.0 )
        v11 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_shuffle_ps((__m128)LODWORD(FLOAT_4_1887903), (__m128)LODWORD(FLOAT_4_1887903), 0),
                      v10),
                    v10),
                  v10),
                _mm_mul_ps(hkgpConvexHull::getSurfaceArea(&v35, &v40)->m_real, v10));
    }
    else
    {
      v16 = fmaxf(hkConvexShapeDefaultRadius * 0.2, v10.m128_f32[0]);
      while ( 1 )
      {
        hkgpConvexHull::expandByPlanarMargin(&v35, (hkBool *)&retaddr, v16, v4);
        if ( (unsigned int)hkgpConvexHull::getDimensions(&v35) == 3 )
          hkgpConvexHull::buildMassProperties(&v35, &v36);
        v16 = v16 * 2.0;
        if ( (unsigned int)hkgpConvexHull::getDimensions(&v35) == 3 )
        {
          v12.m128_f32[0] = *(float *)&resulta.m_enum;
          v12 = _mm_shuffle_ps(v12, v12, 0);
          if ( COERCE_FLOAT(*hkgpConvexHull::getVolume(&v35, &v39)) >= v12.m128_f32[0] )
            break;
        }
      }
    }
    a4->m_centerOfMass = (hkVector4f)hkgpConvexHull::getCenterOfMass(&v35)->m_quad;
    a4->m_inertiaTensor = *hkgpConvexHull::getWorldInertia(&v35);
    v17 = _mm_add_ps(hkgpConvexHull::getVolume(&v35, &v39)->m_real, v11);
    LODWORD(a4->m_volume) = v17.m128_i32[0];
    a4->m_mass = 1.0;
    if ( v17.m128_f32[0] > 0.0 && v11.m128_f32[0] > 0.0 )
    {
      config = (hkgpConvexHull::BuildConfig)_mm_add_ps(
                                              _mm_div_ps(
                                                _mm_add_ps(v11, v11),
                                                _mm_mul_ps(v17, (__m128)xmmword_141A710E0)),
                                              query.m_quad);
      hkMatrix3f::mul(&a4->m_inertiaTensor, (hkSimdFloat32 *)&config);
    }
    result->m_enum = HK_SUCCESS;
    goto LABEL_27;
  }
  m_numVertices = vertices->m_numVertices;
  m_striding = vertices->m_striding;
  m_vertices = vertices->m_vertices;
  v21 = (unsigned __int64 *)((char *)vertices->m_vertices + m_striding);
  v22 = (hkgpConvexHull::BuildConfig)_mm_movelh_ps(
                                       (__m128)*(unsigned __int64 *)vertices->m_vertices,
                                       (__m128)*((unsigned int *)vertices->m_vertices + 2));
  config = v22;
  v23 = _mm_movelh_ps((__m128)*v21, (__m128)*((unsigned int *)v21 + 2));
  endAxis.m_quad = v23;
  if ( m_numVertices > 2 )
  {
    v24 = 0;
    v25 = 1;
    v26 = _mm_sub_ps(v23, (__m128)v22);
    v27 = 0;
    v28 = 0.0;
    v29 = (unsigned int *)(v21 + 1);
    do
    {
      v30 = _mm_mul_ps(_mm_movelh_ps((__m128)*v21, (__m128)*v29), v26);
      v31 = (float)(_mm_shuffle_ps(v30, v30, 85).m128_f32[0] + _mm_shuffle_ps(v30, v30, 0).m128_f32[0])
          + _mm_shuffle_ps(v30, v30, 170).m128_f32[0];
      if ( v31 > v28 )
      {
        v27 = v25;
        v28 = v31;
      }
      if ( v31 < v9 )
      {
        v24 = v25;
        v9 = v31;
      }
      ++v25;
      v21 = (unsigned __int64 *)((char *)v21 + m_striding);
      v29 = (unsigned int *)((char *)v29 + m_striding);
    }
    while ( v25 < m_numVertices );
    config = (hkgpConvexHull::BuildConfig)_mm_movelh_ps(
                                            (__m128)*(unsigned __int64 *)((char *)m_vertices + v24 * (int)m_striding),
                                            (__m128)*(unsigned int *)((char *)m_vertices + v24 * (int)m_striding + 8));
    endAxis.m_quad = _mm_movelh_ps(
                       (__m128)*(unsigned __int64 *)((char *)m_vertices + v27 * (int)m_striding),
                       (__m128)*(unsigned int *)((char *)m_vertices + v27 * (int)m_striding + 8));
  }
  LODWORD(mass) = (_DWORD)FLOAT_1_0;
  hkInertiaTensorComputer::computeCapsuleVolumeMassProperties(
    result,
    (hkVector4f *)&config,
    &endAxis,
    v12.m128_f32[0],
    mass,
    a4);
  hkgpConvexHull::~hkgpConvexHull(&v35);
  return result;
}

