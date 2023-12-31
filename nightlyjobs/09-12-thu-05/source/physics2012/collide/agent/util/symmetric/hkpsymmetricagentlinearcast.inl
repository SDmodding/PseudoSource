// File Line: 16
// RVA: 0xD29F30
void __fastcall hkpSymmetricAgentLinearCast<hkpMultiSphereAgent>::processCollision(
        hkpSymmetricAgentLinearCast<hkpMultiSphereAgent> *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpProcessCollisionInput *input,
        hkpProcessCollisionOutput *result)
{
  hkpProcessCdPoint *m_storage; // rdi
  float v6; // xmm6_4
  __m128 *p_m_quad; // rcx
  __m128 v8; // xmm2
  __m128 v9; // xmm0

  m_storage = result->m_firstFreeContactPoint.m_storage;
  v6 = result->m_toi.m_time.m_storage;
  hkpMultiSphereAgent::processCollision(this, bodyB, bodyA, input, result);
  if ( m_storage < result->m_firstFreeContactPoint.m_storage )
  {
    p_m_quad = &m_storage->m_contact.m_separatingNormal.m_quad;
    v8 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64);
    do
    {
      v9 = *p_m_quad;
      p_m_quad += 3;
      p_m_quad[-4] = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 255), v9), p_m_quad[-4]);
      p_m_quad[-3] = _mm_xor_ps(v8, p_m_quad[-3]);
    }
    while ( (hkpProcessCdPoint *)&p_m_quad[-1] < result->m_firstFreeContactPoint.m_storage );
  }
  if ( v6 != result->m_toi.m_time.m_storage )
    hkpProcessCollisionData::ToiInfo::flip(&result->m_toi);
}

// File Line: 40
// RVA: 0xD284E0
void __fastcall hkpSymmetricAgentLinearCast<hkpConvexListAgent>::getClosestPoints(
        hkpSymmetricAgentLinearCast<hkpConvexListAgent> *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  hkpCdPointCollector v5; // [rsp+30h] [rbp-28h] BYREF
  hkpCdPointCollector *v6; // [rsp+40h] [rbp-18h]

  v5.vfptr = (hkpCdPointCollectorVtbl *)&hkpSymmetricAgentFlipCollector::`vftable;
  v5.m_earlyOutDistance = FLOAT_3_40282e38;
  v6 = collector;
  hkpConvexListAgent::getClosestPoints(this, bodyB, bodyA, input, &v5);
}

// File Line: 47
// RVA: 0xD1CDD0
void __fastcall hkpSymmetricAgentLinearCast<hkpBvCompressedMeshAgent>::staticGetClosestPoints(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdPointCollector *collector)
{
  hkpCdPointCollector collectora; // [rsp+20h] [rbp-28h] BYREF
  hkpCdPointCollector *v5; // [rsp+30h] [rbp-18h]

  v5 = collector;
  collectora.vfptr = (hkpCdPointCollectorVtbl *)&hkpSymmetricAgentFlipCollector::`vftable;
  collectora.m_earlyOutDistance = FLOAT_3_40282e38;
  hkpBvTreeAgent::staticGetClosestPoints(bodyB, bodyA, input, &collectora);
}

// File Line: 55
// RVA: 0xD1EAD0
void __fastcall hkpSymmetricAgentLinearCast<hkpBvTreeAgent>::getPenetrations(
        hkpSymmetricAgentLinearCast<hkpMoppAgent> *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpCdBodyPairCollector v5; // [rsp+30h] [rbp-28h] BYREF
  hkpCdBodyPairCollector *v6; // [rsp+40h] [rbp-18h]

  v5.vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpSymmetricAgentFlipBodyCollector::`vftable;
  v6 = collector;
  v5.m_earlyOut.m_bool = 0;
  hkpBvTreeAgent::getPenetrations(this, bodyB, bodyA, input, &v5);
}

// File Line: 63
// RVA: 0xCF4EB0
void __fastcall hkpSymmetricAgentLinearCast<hkpShapeCollectionAgent>::staticGetPenetrations(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpCdBodyPairCollector *collector)
{
  hkpCdBodyPairCollector collectora; // [rsp+20h] [rbp-28h] BYREF
  hkpCdBodyPairCollector *v5; // [rsp+30h] [rbp-18h]

  v5 = collector;
  collectora.vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpSymmetricAgentFlipBodyCollector::`vftable;
  collectora.m_earlyOut.m_bool = 0;
  hkpShapeCollectionAgent::staticGetPenetrations(bodyB, bodyA, input, &collectora);
}

// File Line: 79
// RVA: 0xD1E160
void __fastcall hkpSymmetricAgentLinearCast<hkpMoppAgent>::staticLinearCast(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpLinearCastCollisionInput *input,
        hkpCdPointCollector *collector,
        hkpCdPointCollector *startCollector)
{
  __int128 v5; // xmm0
  __int128 v6; // xmm1
  __int128 v7; // xmm0
  hkVector4f v8; // xmm1
  hkVector4f v9; // xmm0
  hkVector4f v10; // xmm1
  __int128 v11; // xmm1
  hkpCdPointCollector v12; // [rsp+30h] [rbp-D8h] BYREF
  hkpCdPointCollector *v13; // [rsp+40h] [rbp-C8h]
  hkpCdPointCollector collectora; // [rsp+50h] [rbp-B8h] BYREF
  hkVector4f v15; // [rsp+60h] [rbp-A8h]
  hkpCdPointCollector *v16; // [rsp+70h] [rbp-98h]
  hkpLinearCastCollisionInput inputa; // [rsp+80h] [rbp-88h] BYREF

  v5 = *(_OWORD *)&input->m_dispatcher.m_storage;
  v6 = *(_OWORD *)&input->m_tolerance.m_storage;
  v16 = collector;
  collectora.m_earlyOutDistance = 3.40282e38;
  *(_OWORD *)&inputa.m_dispatcher.m_storage = v5;
  v7 = *(_OWORD *)&input->m_convexListFilter.m_storage;
  *(_OWORD *)&inputa.m_tolerance.m_storage = v6;
  v8.m_quad = (__m128)input->m_aabb32Info.m_bitOffsetLow;
  *(_OWORD *)&inputa.m_convexListFilter.m_storage = v7;
  inputa.m_aabb32Info.m_bitOffsetHigh = input->m_aabb32Info.m_bitOffsetHigh;
  v9.m_quad = (__m128)input->m_path;
  inputa.m_aabb32Info.m_bitOffsetLow = (hkVector4f)v8.m_quad;
  v10.m_quad = (__m128)input->m_aabb32Info.m_bitScale;
  inputa.m_path = (hkVector4f)v9.m_quad;
  inputa.m_aabb32Info.m_bitScale = (hkVector4f)v10.m_quad;
  v11 = *(_OWORD *)&input->m_maxExtraPenetration;
  collectora.vfptr = (hkpCdPointCollectorVtbl *)&hkpSymmetricAgentFlipCastCollector::`vftable;
  *(_OWORD *)&inputa.m_maxExtraPenetration = v11;
  inputa.m_path.m_quad = _mm_xor_ps(
                           (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
                           input->m_path.m_quad);
  v15.m_quad = (__m128)input->m_path;
  if ( startCollector )
  {
    v13 = startCollector;
    v12.m_earlyOutDistance = 3.40282e38;
    v12.vfptr = (hkpCdPointCollectorVtbl *)&hkpSymmetricAgentFlipCollector::`vftable;
    hkpMoppAgent::staticLinearCast(bodyB, bodyA, &inputa, &collectora, &v12);
  }
  else
  {
    hkpMoppAgent::staticLinearCast(bodyB, bodyA, &inputa, &collectora, 0i64);
  }
}

// File Line: 97
// RVA: 0xD28A90
void __fastcall hkpSymmetricAgentLinearCast<hkpConvexListAgent>::updateShapeCollectionFilter(
        hkpSymmetricAgentLinearCast<hkpConvexListAgent> *this,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpConstraintOwner *constraintOwner)
{
  hkpConvexListAgent::updateShapeCollectionFilter(this, bodyB, bodyA, input, constraintOwner);
}

