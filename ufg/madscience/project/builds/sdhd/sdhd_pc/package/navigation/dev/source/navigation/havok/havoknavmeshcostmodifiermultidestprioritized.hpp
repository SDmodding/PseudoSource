// File Line: 19
// RVA: 0xE4D60
void __fastcall NavMeshCostModifierMultiDestPrioritized::NavMeshCostModifierMultiDestPrioritized(
        NavMeshCostModifierMultiDestPrioritized *this,
        UFG::FindPathMultiDestPrioritizedImmediateQuery *query)
{
  unsigned int v3; // r11d
  signed int size; // r10d
  __int64 v5; // rbx
  __int64 v6; // rdx
  unsigned int v7; // eax
  __int64 v8; // r8
  UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination *p; // rax
  float m_fMaxPriority; // xmm0_4
  UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination *v11; // rax
  UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination *v12; // rax
  UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination *v13; // rax
  __int64 v14; // rdx
  __int64 v15; // r8
  UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination *v16; // rax
  float m_fPriority; // xmm0_4

  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiAstarCostModifier::`vftable;
  this->m_type.m_storage = 1;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiUFGNavMeshCostModifier::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&NavMeshCostModifierMultiDestPrioritized::`vftable;
  v3 = 0;
  this->m_fMaxPriority = 0.0;
  this->m_Query = query;
  size = query->m_aPrioritizedDestinations.size;
  v5 = 0i64;
  if ( size >= 4 )
  {
    v6 = 0i64;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    v8 = v7;
    v3 = 4 * v7;
    v5 = 4i64 * v7;
    do
    {
      p = query->m_aPrioritizedDestinations.p;
      m_fMaxPriority = this->m_fMaxPriority;
      if ( m_fMaxPriority <= p[v6].m_fPriority )
        m_fMaxPriority = p[v6].m_fPriority;
      this->m_fMaxPriority = m_fMaxPriority;
      v11 = query->m_aPrioritizedDestinations.p;
      if ( m_fMaxPriority <= v11[v6 + 1].m_fPriority )
        m_fMaxPriority = v11[v6 + 1].m_fPriority;
      this->m_fMaxPriority = m_fMaxPriority;
      v12 = query->m_aPrioritizedDestinations.p;
      if ( m_fMaxPriority <= v12[v6 + 2].m_fPriority )
        m_fMaxPriority = v12[v6 + 2].m_fPriority;
      this->m_fMaxPriority = m_fMaxPriority;
      v13 = query->m_aPrioritizedDestinations.p;
      if ( m_fMaxPriority <= v13[v6 + 3].m_fPriority )
        m_fMaxPriority = v13[v6 + 3].m_fPriority;
      this->m_fMaxPriority = m_fMaxPriority;
      v6 += 4i64;
      --v8;
    }
    while ( v8 );
  }
  if ( v3 < size )
  {
    v14 = v5;
    v15 = size - v3;
    do
    {
      v16 = query->m_aPrioritizedDestinations.p;
      m_fPriority = this->m_fMaxPriority;
      if ( m_fPriority <= v16[v14].m_fPriority )
        m_fPriority = v16[v14].m_fPriority;
      this->m_fMaxPriority = m_fPriority;
      ++v14;
      --v15;
    }
    while ( v15 );
  }
}

// File Line: 30
// RVA: 0xE62B0
void __fastcall NavMeshCostModifierMultiDestPrioritized::~NavMeshCostModifierMultiDestPrioritized(
        NavMeshCostModifierMultiDestPrioritized *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&NavMeshCostModifierMultiDestPrioritized::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiAstarCostModifier::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 34
// RVA: 0xF5400
hkSimdFloat32 *__fastcall NavMeshCostModifierMultiDestPrioritized::getModifiedCost(
        NavMeshCostModifierMultiDestPrioritized *this,
        hkSimdFloat32 *result,
        hkaiAstarCostModifier::NavMeshGetModifiedCostCallbackContext *context)
{
  hkaiNavMeshEdgePairInfo *m_edgeFaceInfo; // rax
  UFG::FindPathMultiDestPrioritizedImmediateQuery *m_Query; // rsi
  float v8; // xmm4_4
  float v9; // xmm5_4
  unsigned int v10; // edx
  unsigned int v11; // r8d
  int size; // r10d
  float v13; // xmm6_4
  float v14; // xmm3_4
  __int64 v15; // rax
  float *p_z; // rcx
  int v17; // r9d
  float *v18; // r9
  __m128 v19; // xmm2
  float v20; // xmm3_4
  __int64 v21; // rcx
  __m128 v22; // xmm0
  hkSimdFloat32 *v23; // rax

  m_edgeFaceInfo = context->m_edgeFaceInfo;
  if ( m_edgeFaceInfo->m_outgoingEdgeInfo.m_edge && m_edgeFaceInfo->m_outgoingEdgeInfo.m_edgeKey != -1 )
    goto LABEL_23;
  m_Query = this->m_Query;
  v8 = m_edgeFaceInfo->m_outgoingEdgeInfo.m_position.m_quad.m128_f32[0];
  v9 = m_edgeFaceInfo->m_outgoingEdgeInfo.m_position.m_quad.m128_f32[1];
  v10 = 0;
  v11 = -1;
  size = m_Query->m_aPrioritizedDestinations.size;
  v13 = m_edgeFaceInfo->m_outgoingEdgeInfo.m_position.m_quad.m128_f32[2];
  v14 = FLOAT_3_4028235e38;
  v15 = 0i64;
  if ( size >= 4 )
  {
    p_z = &m_Query->m_aPrioritizedDestinations.p->m_npPosition.m_vPosition.z;
    v17 = 2;
    v15 = 4i64 * (((unsigned int)(size - 4) >> 2) + 1);
    do
    {
      if ( (float)((float)((float)((float)(v9 - *(p_z - 1)) * (float)(v9 - *(p_z - 1)))
                         + (float)((float)(v8 - *(p_z - 2)) * (float)(v8 - *(p_z - 2))))
                 + (float)((float)(v13 - *p_z) * (float)(v13 - *p_z))) < v14 )
      {
        v11 = v10;
        v14 = (float)((float)((float)(v9 - *(p_z - 1)) * (float)(v9 - *(p_z - 1)))
                    + (float)((float)(v8 - *(p_z - 2)) * (float)(v8 - *(p_z - 2))))
            + (float)((float)(v13 - *p_z) * (float)(v13 - *p_z));
      }
      if ( (float)((float)((float)((float)(v9 - p_z[19]) * (float)(v9 - p_z[19]))
                         + (float)((float)(v8 - p_z[18]) * (float)(v8 - p_z[18])))
                 + (float)((float)(v13 - p_z[20]) * (float)(v13 - p_z[20]))) < v14 )
      {
        v11 = v17 - 1;
        v14 = (float)((float)((float)(v9 - p_z[19]) * (float)(v9 - p_z[19]))
                    + (float)((float)(v8 - p_z[18]) * (float)(v8 - p_z[18])))
            + (float)((float)(v13 - p_z[20]) * (float)(v13 - p_z[20]));
      }
      if ( (float)((float)((float)((float)(v9 - p_z[39]) * (float)(v9 - p_z[39]))
                         + (float)((float)(v8 - p_z[38]) * (float)(v8 - p_z[38])))
                 + (float)((float)(v13 - p_z[40]) * (float)(v13 - p_z[40]))) < v14 )
      {
        v11 = v17;
        v14 = (float)((float)((float)(v9 - p_z[39]) * (float)(v9 - p_z[39]))
                    + (float)((float)(v8 - p_z[38]) * (float)(v8 - p_z[38])))
            + (float)((float)(v13 - p_z[40]) * (float)(v13 - p_z[40]));
      }
      if ( (float)((float)((float)((float)(v9 - p_z[59]) * (float)(v9 - p_z[59]))
                         + (float)((float)(v8 - p_z[58]) * (float)(v8 - p_z[58])))
                 + (float)((float)(v13 - p_z[60]) * (float)(v13 - p_z[60]))) < v14 )
      {
        v11 = v17 + 1;
        v14 = (float)((float)((float)(v9 - p_z[59]) * (float)(v9 - p_z[59]))
                    + (float)((float)(v8 - p_z[58]) * (float)(v8 - p_z[58])))
            + (float)((float)(v13 - p_z[60]) * (float)(v13 - p_z[60]));
      }
      v10 += 4;
      p_z += 80;
      v17 += 4;
    }
    while ( v10 < size - 3 );
  }
  if ( v10 < size )
  {
    v18 = &m_Query->m_aPrioritizedDestinations.p->m_npPosition.m_vPosition.z + 20 * v15;
    do
    {
      if ( (float)((float)((float)((float)(v9 - *(v18 - 1)) * (float)(v9 - *(v18 - 1)))
                         + (float)((float)(v8 - *(v18 - 2)) * (float)(v8 - *(v18 - 2))))
                 + (float)((float)(v13 - *v18) * (float)(v13 - *v18))) < v14 )
      {
        v11 = v10;
        v14 = (float)((float)((float)(v9 - *(v18 - 1)) * (float)(v9 - *(v18 - 1)))
                    + (float)((float)(v8 - *(v18 - 2)) * (float)(v8 - *(v18 - 2))))
            + (float)((float)(v13 - *v18) * (float)(v13 - *v18));
      }
      ++v10;
      v18 += 20;
    }
    while ( v10 < size );
  }
  if ( (v11 & 0x80000000) != 0 )
  {
LABEL_23:
    *result = context->m_originalCost;
    return result;
  }
  else
  {
    v19 = _mm_add_ps(context->m_searchPathCost.m_real, context->m_originalCost.m_real);
    v20 = COERCE_FLOAT(*(_OWORD *)&context->m_originalCost)
        + (float)(this->m_fMaxPriority - m_Query->m_aPrioritizedDestinations.p[v11].m_fPriority);
    v21 = *(_QWORD *)&m_Query->m_pOutput[1].m_id;
    v22 = (__m128)*(unsigned int *)(v21 + 4i64 * v11);
    if ( v22.m128_f32[0] >= v19.m128_f32[0] )
      v22 = v19;
    *(_DWORD *)(v21 + 4i64 * v11) = v22.m128_i32[0];
    v22.m128_f32[0] = v20;
    v23 = result;
    result->m_real = _mm_shuffle_ps(v22, v22, 0);
  }
  return v23;
}

