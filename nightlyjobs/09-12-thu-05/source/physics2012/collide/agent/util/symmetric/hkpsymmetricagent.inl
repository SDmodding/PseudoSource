// File Line: 26
// RVA: 0xD29E20
void __fastcall hkpSymmetricAgent<hkpMultiSphereAgent>::linearCast(hkpSymmetricAgent<hkpMultiSphereAgent> *this, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpLinearCastCollisionInput *input, hkpCdPointCollector *collector, hkpCdPointCollector *startCollector)
{
  __int128 v6; // xmm0
  __int128 v7; // xmm1
  __int128 v8; // xmm0
  hkVector4f v9; // xmm1
  hkVector4f v10; // xmm0
  hkVector4f v11; // xmm1
  hkVector4f v12; // xmm0
  hkpCdPointCollector v13; // [rsp+30h] [rbp-E8h]
  __int128 v14; // [rsp+40h] [rbp-D8h]
  hkpCdPointCollector *v15; // [rsp+50h] [rbp-C8h]
  void **v16; // [rsp+60h] [rbp-B8h]
  int v17; // [rsp+68h] [rbp-B0h]
  __int128 v18; // [rsp+70h] [rbp-A8h]
  hkpCdPointCollector *v19; // [rsp+80h] [rbp-98h]
  hkpLinearCastCollisionInput inputa; // [rsp+90h] [rbp-88h]

  v6 = *(_OWORD *)&input->m_dispatcher.m_storage;
  v7 = *(_OWORD *)&input->m_tolerance.m_storage;
  v13.m_earlyOutDistance = 3.40282e38;
  v13.vfptr = (hkpCdPointCollectorVtbl *)&hkpSymmetricAgentFlipCastCollector::`vftable';
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
  _mm_store_si128((__m128i *)&v14, (__m128i)v12.m_quad);
  if ( startCollector )
  {
    v19 = startCollector;
    v17 = 2139095022;
    _mm_store_si128((__m128i *)&v18, (__m128i)v12.m_quad);
    v16 = &hkpSymmetricAgentFlipCastCollector::`vftable';
    hkpMultiSphereAgent::linearCast(
      (hkpMultiSphereAgent *)&this->vfptr,
      bodyB,
      bodyA,
      &inputa,
      &v13,
      (hkpCdPointCollector *)&v16);
  }
  else
  {
    hkpMultiSphereAgent::linearCast((hkpMultiSphereAgent *)&this->vfptr, bodyB, bodyA, &inputa, &v13, 0i64);
  }
}

