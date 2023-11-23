// File Line: 26
// RVA: 0xD29E20
void __fastcall hkpSymmetricAgent<hkpMultiSphereAgent>::linearCast(
        hkpSymmetricAgent<hkpMultiSphereAgent> *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  __int128 v6; // xmm0
  __int128 v7; // xmm1
  __int128 v8; // xmm0
  hkVector4f v9; // xmm1
  hkVector4f v10; // xmm0
  hkVector4f v11; // xmm1
  hkVector4f v12; // xmm0
  hkpCdPointCollector v13; // [rsp+30h] [rbp-E8h] BYREF
  __m128 m_quad; // [rsp+40h] [rbp-D8h]
  hkpCdPointCollector *v15; // [rsp+50h] [rbp-C8h]
  hkpCdPointCollector v16[2]; // [rsp+60h] [rbp-B8h] BYREF
  hkpCdPointCollector *v17; // [rsp+80h] [rbp-98h]
  hkpLinearCastCollisionInput inputa; // [rsp+90h] [rbp-88h] BYREF

  v6 = *(_OWORD *)&input->m_dispatcher.m_storage;
  v7 = *(_OWORD *)&input->m_tolerance.m_storage;
  v13.m_earlyOutDistance = 3.40282e38;
  v13.vfptr = (hkpCdPointCollectorVtbl *)&hkpSymmetricAgentFlipCastCollector::`vftable;
  *(_OWORD *)&inputa.m_dispatcher.m_storage = v6;
  v8 = *(_OWORD *)&input->m_convexListFilter.m_storage;
  *(_OWORD *)&inputa.m_tolerance.m_storage = v7;
  v9.m_quad = (__m128)input->m_aabb32Info.m_bitOffsetLow;
  *(_OWORD *)&inputa.m_convexListFilter.m_storage = v8;
  inputa.m_aabb32Info.m_bitOffsetHigh = input->m_aabb32Info.m_bitOffsetHigh;
  v10.m_quad = (__m128)input->m_path;
  inputa.m_aabb32Info.m_bitOffsetLow = (hkVector4f)v9.m_quad;
  v11.m_quad = (__m128)input->m_aabb32Info.m_bitScale;
  inputa.m_path = (hkVector4f)v10.m_quad;
  inputa.m_aabb32Info.m_bitScale = (hkVector4f)v11.m_quad;
  *(_OWORD *)&inputa.m_maxExtraPenetration = *(_OWORD *)&input->m_maxExtraPenetration;
  v15 = collector;
  inputa.m_path.m_quad = _mm_xor_ps(
                           (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                           input->m_path.m_quad);
  v12.m_quad = (__m128)input->m_path;
  m_quad = v12.m_quad;
  if ( startCollector )
  {
    v17 = startCollector;
    v16[0].m_earlyOutDistance = 3.40282e38;
    v16[1] = (hkpCdPointCollector)v12.m_quad;
    v16[0].vfptr = (hkpCdPointCollectorVtbl *)&hkpSymmetricAgentFlipCastCollector::`vftable;
    hkpMultiSphereAgent::linearCast(this, bodyB, bodyA, &inputa, &v13, v16);
  }
  else
  {
    hkpMultiSphereAgent::linearCast(this, bodyB, bodyA, &inputa, &v13, 0i64);
  }
}

