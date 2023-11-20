// File Line: 27
// RVA: 0xF52A0
hkSimdFloat32 *__fastcall UFG::FleeTraversalCostModifier::getModifiedCost(UFG::FleeTraversalCostModifier *this, hkSimdFloat32 *result, hkaiAstarCostModifier::NavMeshGetModifiedCostCallbackContext *context)
{
  hkaiNavMeshEdgePairInfo *v3; // r9
  hkaiAstarCostModifier::NavMeshGetModifiedCostCallbackContext *v4; // rbp
  hkSimdFloat32 *v5; // r14
  UFG::FleeTraversalCostModifier *v6; // rsi
  __m128 v7; // xmm6
  const int *v8; // r9
  unsigned int v9; // ebx
  __m128 *v10; // rdi
  __m128 v11; // xmm1
  __m128 v12; // xmm1
  __m128 v13; // xmm0
  float v14; // xmm2_4
  float v15; // xmm1_4
  hkSimdFloat32 *v16; // rax
  hkLineSegmentUtil::ClosestPointLineSegResult resulta; // [rsp+20h] [rbp-48h]

  v3 = context->m_edgeFaceInfo;
  v4 = context;
  v5 = result;
  v6 = this;
  v7 = 0i64;
  if ( v3->m_face )
  {
    v8 = v3->m_faceData;
    if ( *v8 == 1 )
    {
      v7 = _mm_add_ps((__m128)0i64, (__m128)_xmm);
    }
    else if ( *v8 == 2 )
    {
      v7 = _mm_add_ps(
             (__m128)0i64,
             _mm_shuffle_ps((__m128)LODWORD(this->m_roadCost), (__m128)LODWORD(this->m_roadCost), 0));
    }
    else if ( *v8 != 4 )
    {
      v7 = _mm_add_ps((__m128)0i64, (__m128)_xmm);
    }
  }
  v9 = 0;
  if ( this->m_threats.size )
  {
    do
    {
      v10 = (__m128 *)((char *)v6 + 32 * (v9 + 2i64));
      hkLineSegmentUtil::closestPointLineSeg(
        (hkVector4f *)v6 + 2 * (v9 + 2i64),
        &v4->m_edgeFaceInfo->m_incomingEdgeInfo.m_position,
        &v4->m_edgeFaceInfo->m_outgoingEdgeInfo.m_position,
        &resulta);
      v11 = _mm_sub_ps(resulta.m_pointOnEdge.m_quad, *v10);
      v12 = _mm_mul_ps(v11, v11);
      v13 = (__m128)LODWORD(v6->m_fleeRadius);
      v14 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 0)))
          + COERCE_FLOAT(_mm_shuffle_ps(v12, v12, 170));
      if ( v14 < v13.m128_f32[0] )
      {
        v15 = *(float *)&FLOAT_1_0;
        if ( v14 < v10[1].m128_f32[0] )
          v15 = FLOAT_10_0;
        v13.m128_f32[0] = (float)(v13.m128_f32[0] - v14) * v15;
        v7 = _mm_add_ps(v7, _mm_shuffle_ps(v13, v13, 0));
      }
      ++v9;
    }
    while ( v9 < v6->m_threats.size );
  }
  v16 = v5;
  v5->m_real = _mm_add_ps(v4->m_originalCost.m_real, v7);
  return v16;
}

// File Line: 117
// RVA: 0xF4900
char __fastcall UFG::FleeTraversalNearestFeatureCallback::edgeTraversed(UFG::SpawnTraversalNearestFeatureCallback *this, unsigned int edgeKey, hkaiAgentTraversalInfo *agentInfo)
{
  unsigned int v3; // er8
  __int64 v4; // rdx
  __int64 v5; // r10
  int v6; // er8
  __m128 *v7; // r9
  __int64 v8; // rbx
  __int64 v9; // rdx
  int v10; // eax
  signed __int64 v11; // rcx
  __int64 v12; // rax
  int v13; // er11
  signed int *v14; // r8
  __m128 *v15; // rcx
  __int64 v16; // rax
  signed int v17; // edx
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
  __m128 v31; // [rsp+0h] [rbp-38h]

  v3 = edgeKey;
  v4 = edgeKey >> 22;
  v5 = (unsigned int)v4;
  v6 = v3 & 0x3FFFFF;
  v7 = (__m128 *)this;
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
  v14 = (signed int *)(v12 + 4 * v11);
  v15 = *(__m128 **)(v8 + 48 * v5);
  v16 = *v14;
  v17 = v15[3].m128_i32[2];
  if ( (signed int)v16 >= v17 )
    v18 = (__m128 *)(v15[19].m128_u64[0] + 16i64 * ((signed int)v16 - v17));
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
  if ( (signed int)v22 >= v17 )
    v26 = (__m128 *)(v15[19].m128_u64[0] + 16i64 * ((signed int)v22 - v17));
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
  v28 = _mm_sub_ps(v7[1], v27);
  v31 = v27;
  v29 = _mm_mul_ps(v28, v28);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v29, v29, 170))) <= v7[2].m128_f32[0] )
    return 1;
  v7[3].m128_i8[0] = 1;
  result = 0;
  v7[2].m128_i32[1] = v27.m128_i32[0];
  v7[2].m128_u64[1] = *(unsigned __int64 *)((char *)v31.m128_u64 + 4);
  return result;
}

