// File Line: 19
// RVA: 0xE4D60
void __fastcall NavMeshCostModifierMultiDestPrioritized::NavMeshCostModifierMultiDestPrioritized(NavMeshCostModifierMultiDestPrioritized *this, UFG::FindPathMultiDestPrioritizedImmediateQuery *query)
{
  UFG::FindPathMultiDestPrioritizedImmediateQuery *v2; // r9
  unsigned int v3; // er11
  unsigned int v4; // er10
  signed __int64 v5; // rbx
  __int64 v6; // rdx
  unsigned int v7; // eax
  __int64 v8; // r8
  UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination *v9; // rax
  float v10; // xmm0_4
  UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination *v11; // rax
  UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination *v12; // rax
  UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination *v13; // rax
  signed __int64 v14; // rdx
  __int64 v15; // r8
  UFG::FindPathMultiDestPrioritizedImmediateQuery::PrioritizedDestination *v16; // rax
  float v17; // xmm0_4

  v2 = query;
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
  v4 = query->m_aPrioritizedDestinations.size;
  v5 = 0i64;
  if ( (signed int)v4 >= 4 )
  {
    v6 = 0i64;
    v7 = ((v4 - 4) >> 2) + 1;
    v8 = v7;
    v3 = 4 * v7;
    v5 = 4i64 * v7;
    do
    {
      v9 = v2->m_aPrioritizedDestinations.p;
      v10 = this->m_fMaxPriority;
      if ( v10 <= v9[v6].m_fPriority )
        v10 = v9[v6].m_fPriority;
      this->m_fMaxPriority = v10;
      v11 = v2->m_aPrioritizedDestinations.p;
      if ( v10 <= v11[v6 + 1].m_fPriority )
        v10 = v11[v6 + 1].m_fPriority;
      this->m_fMaxPriority = v10;
      v12 = v2->m_aPrioritizedDestinations.p;
      if ( v10 <= v12[v6 + 2].m_fPriority )
        v10 = v12[v6 + 2].m_fPriority;
      this->m_fMaxPriority = v10;
      v13 = v2->m_aPrioritizedDestinations.p;
      if ( v10 <= v13[v6 + 3].m_fPriority )
        v10 = v13[v6 + 3].m_fPriority;
      this->m_fMaxPriority = v10;
      v6 += 4i64;
      --v8;
    }
    while ( v8 );
  }
  if ( v3 < v4 )
  {
    v14 = v5;
    v15 = v4 - v3;
    do
    {
      v16 = v2->m_aPrioritizedDestinations.p;
      v17 = this->m_fMaxPriority;
      if ( v17 <= v16[v14].m_fPriority )
        v17 = v16[v14].m_fPriority;
      this->m_fMaxPriority = v17;
      ++v14;
      --v15;
    }
    while ( v15 );
  }
}

// File Line: 30
// RVA: 0xE62B0
void __fastcall NavMeshCostModifierMultiDestPrioritized::~NavMeshCostModifierMultiDestPrioritized(NavMeshCostModifierMultiDestPrioritized *this)
{
  this->vfptr = (hkBaseObjectVtbl *)&NavMeshCostModifierMultiDestPrioritized::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiAstarCostModifier::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkReferencedObject::`vftable;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 34
// RVA: 0xF5400
__m128i *__fastcall NavMeshCostModifierMultiDestPrioritized::getModifiedCost(NavMeshCostModifierMultiDestPrioritized *this, hkSimdFloat32 *result, hkaiAstarCostModifier::NavMeshGetModifiedCostCallbackContext *context)
{
  hkaiNavMeshEdgePairInfo *v3; // rax
  hkaiAstarCostModifier::NavMeshGetModifiedCostCallbackContext *v4; // rdi
  __m128i *v5; // r11
  NavMeshCostModifierMultiDestPrioritized *v6; // rbp
  UFG::FindPathMultiDestPrioritizedImmediateQuery *v7; // rsi
  float v8; // xmm4_4
  float v9; // xmm5_4
  unsigned int v10; // edx
  unsigned int v11; // er8
  unsigned int v12; // er10
  float v13; // xmm6_4
  float v14; // xmm3_4
  signed __int64 v15; // rax
  float *v16; // rcx
  signed int v17; // er9
  float *v18; // r9
  __m128 v19; // xmm2
  float v20; // xmm3_4
  __int64 v21; // rcx
  __m128 v22; // xmm0
  __m128i *v23; // rax

  v3 = context->m_edgeFaceInfo;
  v4 = context;
  v5 = (__m128i *)result;
  v6 = this;
  if ( v3->m_outgoingEdgeInfo.m_edge && v3->m_outgoingEdgeInfo.m_edgeKey != -1 )
    goto LABEL_26;
  v7 = this->m_Query;
  v8 = v3->m_outgoingEdgeInfo.m_position.m_quad.m128_f32[0];
  v9 = v3->m_outgoingEdgeInfo.m_position.m_quad.m128_f32[1];
  v10 = 0;
  v11 = -1;
  v12 = v7->m_aPrioritizedDestinations.size;
  v13 = v3->m_outgoingEdgeInfo.m_position.m_quad.m128_f32[2];
  v14 = FLOAT_3_4028235e38;
  v15 = 0i64;
  if ( (signed int)v12 >= 4 )
  {
    v16 = &v7->m_aPrioritizedDestinations.p->m_npPosition.m_vPosition.z;
    v17 = 2;
    v15 = 4i64 * (((v12 - 4) >> 2) + 1);
    do
    {
      if ( (float)((float)((float)((float)(v9 - *(v16 - 1)) * (float)(v9 - *(v16 - 1)))
                         + (float)((float)(v8 - *(v16 - 2)) * (float)(v8 - *(v16 - 2))))
                 + (float)((float)(v13 - *v16) * (float)(v13 - *v16))) < v14 )
      {
        v11 = v10;
        v14 = (float)((float)((float)(v9 - *(v16 - 1)) * (float)(v9 - *(v16 - 1)))
                    + (float)((float)(v8 - *(v16 - 2)) * (float)(v8 - *(v16 - 2))))
            + (float)((float)(v13 - *v16) * (float)(v13 - *v16));
      }
      if ( (float)((float)((float)((float)(v9 - v16[19]) * (float)(v9 - v16[19]))
                         + (float)((float)(v8 - v16[18]) * (float)(v8 - v16[18])))
                 + (float)((float)(v13 - v16[20]) * (float)(v13 - v16[20]))) < v14 )
      {
        v11 = v17 - 1;
        v14 = (float)((float)((float)(v9 - v16[19]) * (float)(v9 - v16[19]))
                    + (float)((float)(v8 - v16[18]) * (float)(v8 - v16[18])))
            + (float)((float)(v13 - v16[20]) * (float)(v13 - v16[20]));
      }
      if ( (float)((float)((float)((float)(v9 - v16[39]) * (float)(v9 - v16[39]))
                         + (float)((float)(v8 - v16[38]) * (float)(v8 - v16[38])))
                 + (float)((float)(v13 - v16[40]) * (float)(v13 - v16[40]))) < v14 )
      {
        v11 = v17;
        v14 = (float)((float)((float)(v9 - v16[39]) * (float)(v9 - v16[39]))
                    + (float)((float)(v8 - v16[38]) * (float)(v8 - v16[38])))
            + (float)((float)(v13 - v16[40]) * (float)(v13 - v16[40]));
      }
      if ( (float)((float)((float)((float)(v9 - v16[59]) * (float)(v9 - v16[59]))
                         + (float)((float)(v8 - v16[58]) * (float)(v8 - v16[58])))
                 + (float)((float)(v13 - v16[60]) * (float)(v13 - v16[60]))) < v14 )
      {
        v11 = v17 + 1;
        v14 = (float)((float)((float)(v9 - v16[59]) * (float)(v9 - v16[59]))
                    + (float)((float)(v8 - v16[58]) * (float)(v8 - v16[58])))
            + (float)((float)(v13 - v16[60]) * (float)(v13 - v16[60]));
      }
      v10 += 4;
      v16 += 80;
      v17 += 4;
    }
    while ( v10 < v12 - 3 );
  }
  if ( v10 < v12 )
  {
    v18 = &v7->m_aPrioritizedDestinations.p->m_npPosition.m_vPosition.z + 20 * v15;
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
    while ( v10 < v12 );
  }
  if ( (v11 & 0x80000000) != 0 )
  {
LABEL_26:
    _mm_store_si128(v5, (__m128i)v4->m_originalCost.m_real);
    v23 = v5;
  }
  else
  {
    v19 = _mm_add_ps(v4->m_searchPathCost.m_real, v4->m_originalCost.m_real);
    v20 = COERCE_FLOAT(*(_OWORD *)&v4->m_originalCost)
        + (float)(v6->m_fMaxPriority - v7->m_aPrioritizedDestinations.p[v11].m_fPriority);
    v21 = *(_QWORD *)&v7->m_pOutput[1].m_id;
    v22 = (__m128)*(unsigned int *)(v21 + 4i64 * v11);
    if ( v22.m128_f32[0] >= v19.m128_f32[0] )
      v22 = v19;
    *(_DWORD *)(v21 + 4i64 * v11) = v22.m128_i32[0];
    v22.m128_f32[0] = v20;
    v23 = v5;
    *(__m128 *)v5 = _mm_shuffle_ps(v22, v22, 0);
  }
  return v23;
}

