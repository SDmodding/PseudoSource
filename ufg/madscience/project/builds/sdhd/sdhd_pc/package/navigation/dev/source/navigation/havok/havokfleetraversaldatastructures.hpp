// File Line: 27
// RVA: 0xF52A0
hkSimdFloat32 *__fastcall UFG::FleeTraversalCostModifier::getModifiedCost(
        UFG::FleeTraversalCostModifier *this,
        hkSimdFloat32 *result,
        hkaiAstarCostModifier::NavMeshGetModifiedCostCallbackContext *context)
{
  hkaiNavMeshEdgePairInfo *m_edgeFaceInfo; // r9
  __m128 v7; // xmm6
  const int *m_faceData; // r9
  unsigned int i; // ebx
  UFG::FleeTraversalCostModifier::ThreatTarget *v10; // rdi
  __m128 v11; // xmm1
  __m128 v12; // xmm1
  __m128 m_fleeRadius_low; // xmm0
  float v14; // xmm2_4
  float v15; // xmm1_4
  hkSimdFloat32 *v16; // rax
  hkLineSegmentUtil::ClosestPointLineSegResult resulta; // [rsp+20h] [rbp-48h] BYREF

  m_edgeFaceInfo = context->m_edgeFaceInfo;
  v7 = 0i64;
  if ( m_edgeFaceInfo->m_face )
  {
    m_faceData = m_edgeFaceInfo->m_faceData;
    if ( *m_faceData == 1 )
    {
      v7 = _mm_add_ps((__m128)0i64, (__m128)_xmm);
    }
    else if ( *m_faceData == 2 )
    {
      v7 = _mm_add_ps(
             (__m128)0i64,
             _mm_shuffle_ps((__m128)LODWORD(this->m_roadCost), (__m128)LODWORD(this->m_roadCost), 0));
    }
    else if ( *m_faceData != 4 )
    {
      v7 = _mm_add_ps((__m128)0i64, (__m128)_xmm);
    }
  }
  for ( i = 0; i < this->m_threats.size; ++i )
  {
    v10 = &this->m_threats.p[i];
    hkLineSegmentUtil::closestPointLineSeg(
      &v10->m_position,
      &context->m_edgeFaceInfo->m_incomingEdgeInfo.m_position,
      &context->m_edgeFaceInfo->m_outgoingEdgeInfo.m_position,
      &resulta);
    v11 = _mm_sub_ps(resulta.m_pointOnEdge.m_quad, v10->m_position.m_quad);
    v12 = _mm_mul_ps(v11, v11);
    m_fleeRadius_low = (__m128)LODWORD(this->m_fleeRadius);
    v14 = (float)(_mm_shuffle_ps(v12, v12, 85).m128_f32[0] + _mm_shuffle_ps(v12, v12, 0).m128_f32[0])
        + _mm_shuffle_ps(v12, v12, 170).m128_f32[0];
    if ( v14 < m_fleeRadius_low.m128_f32[0] )
    {
      v15 = *(float *)&FLOAT_1_0;
      if ( v14 < v10->m_radius )
        v15 = FLOAT_10_0;
      m_fleeRadius_low.m128_f32[0] = (float)(m_fleeRadius_low.m128_f32[0] - v14) * v15;
      v7 = _mm_add_ps(v7, _mm_shuffle_ps(m_fleeRadius_low, m_fleeRadius_low, 0));
    }
  }
  v16 = result;
  result->m_real = _mm_add_ps(context->m_originalCost.m_real, v7);
  return v16;
}

// File Line: 117
// RVA: 0xF4900
char __fastcall UFG::FleeTraversalNearestFeatureCallback::edgeTraversed(
        UFG::SpawnTraversalNearestFeatureCallback *this,
        unsigned int edgeKey,
        hkaiAgentTraversalInfo *agentInfo)
{
  __int64 v4; // rdx
  __int64 v5; // r10
  signed int v6; // r8d
  __int64 v8; // rbx
  __int64 v9; // rdx
  int v10; // eax
  __int64 v11; // rcx
  __int64 v12; // rax
  signed int v13; // r11d
  int *v14; // r8
  __m128 *v15; // rcx
  __int64 v16; // rax
  int v17; // edx
  __m128 *v18; // rax
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  __m128 v21; // xmm5
  __int64 v22; // rax
  __m128 v23; // xmm6
  __m128 v24; // xmm7
  __m128 v25; // xmm2
  __m128 *v26; // rax
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  __m128 v29; // xmm2
  char result; // al

  v4 = edgeKey >> 22;
  v5 = (unsigned int)v4;
  v6 = edgeKey & 0x3FFFFF;
  v8 = *((_QWORD *)UFG::NavManager::ms_pInstance[3].vfptr->LowHealthDefrag + 4);
  v9 = *(_QWORD *)(v8 + 48 * v4);
  v10 = *(_DWORD *)(v9 + 40);
  if ( v6 < v10 )
  {
    if ( *(_DWORD *)(v9 + 216) )
      v13 = *(_DWORD *)(*(_QWORD *)(v9 + 208) + 4i64 * v6);
    else
      v13 = v6;
    if ( v13 == -1 )
    {
      v11 = 5i64 * v6;
      v12 = *(_QWORD *)(v9 + 32);
    }
    else
    {
      v11 = 5i64 * v13;
      v12 = *(_QWORD *)(v9 + 256);
    }
  }
  else
  {
    v11 = 5i64 * (v6 - v10);
    v12 = *(_QWORD *)(v9 + 288);
  }
  v14 = (int *)(v12 + 4 * v11);
  v15 = *(__m128 **)(v8 + 48 * v5);
  v16 = *v14;
  v17 = v15[3].m128_i32[2];
  if ( (int)v16 >= v17 )
    v18 = (__m128 *)(v15[19].m128_u64[0] + 16i64 * ((int)v16 - v17));
  else
    v18 = (__m128 *)(v15[3].m128_u64[0] + 16 * v16);
  v19 = *v18;
  v20 = v15[8];
  v21 = v15[7];
  v22 = v14[1];
  v23 = v15[9];
  v24 = v15[10];
  v25 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v21), _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), v20)),
            _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v23)),
          v24);
  if ( (int)v22 >= v17 )
    v26 = (__m128 *)(v15[19].m128_u64[0] + 16i64 * ((int)v22 - v17));
  else
    v26 = (__m128 *)(v15[3].m128_u64[0] + 16 * v22);
  v27 = _mm_mul_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(*v26, *v26, 0), v21),
                  _mm_mul_ps(_mm_shuffle_ps(*v26, *v26, 85), v20)),
                _mm_mul_ps(_mm_shuffle_ps(*v26, *v26, 170), v23)),
              v24),
            v25),
          *(__m128 *)_xmm);
  v28 = _mm_sub_ps(this->m_SearchOrigin.m_quad, v27);
  v29 = _mm_mul_ps(v28, v28);
  if ( (float)((float)(_mm_shuffle_ps(v29, v29, 85).m128_f32[0] + _mm_shuffle_ps(v29, v29, 0).m128_f32[0])
             + _mm_shuffle_ps(v29, v29, 170).m128_f32[0]) <= this->m_SearchRadiusSq )
    return 1;
  this->m_SpawnPositionFound = 1;
  result = 0;
  LODWORD(this->m_SpawnPosition.x) = v27.m128_i32[0];
  LODWORD(this->m_SpawnPosition.y) = v27.m128_i32[1];
  LODWORD(this->m_SpawnPosition.z) = v27.m128_i32[2];
  return result;
}

