// File Line: 27
// RVA: 0xBE6DF0
void __fastcall hkaiDefaultAstarCostModifier::hkaiDefaultAstarCostModifier(hkaiDefaultAstarCostModifier *this)
{
  hkHalf *v1; // rdi
  signed __int64 i; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_type.m_storage = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiDefaultAstarCostModifier::`vftable';
  v1 = this->m_costMultiplierLookupTable;
  this->m_maxCostPenalty = 1.0;
  for ( i = 32i64; i; --i )
  {
    v1->m_value = 16256;
    ++v1;
  }
}

// File Line: 40
// RVA: 0xBE6E70
hkSimdFloat32 *__fastcall hkaiDefaultAstarCostModifier::getModifiedCost(hkaiDefaultAstarCostModifier *this, hkSimdFloat32 *result, hkaiAstarCostModifier::NavMeshGetModifiedCostCallbackContext *context)
{
  signed int v3; // er10
  const int *v4; // r9
  hkSimdFloat32 *v5; // rax
  unsigned int v6; // [rsp+8h] [rbp+8h]

  v3 = 0;
  v4 = context->m_edgeFaceInfo->m_faceData;
  if ( v4 )
    v3 = *v4;
  v5 = result;
  *(float *)&v6 = (float)((float)v3 * 2.3283064e-10) * this->m_maxCostPenalty;
  result->m_real = _mm_add_ps(_mm_shuffle_ps((__m128)v6, (__m128)v6, 0), context->m_originalCost.m_real);
  return v5;
}

// File Line: 58
// RVA: 0xBE6E40
void __fastcall hkaiDefaultAstarCostModifier::setCostMultiplier(hkaiDefaultAstarCostModifier *this, int cellCategory, float multiplier)
{
  float v3; // [rsp+10h] [rbp+10h]

  v3 = multiplier * 1.0039062;
  this->m_costMultiplierLookupTable[cellCategory].m_value = HIWORD(v3);
}

// File Line: 64
// RVA: 0xBE6EC0
hkSimdFloat32 *__fastcall hkaiDefaultAstarCostModifier::getModifiedCost(hkaiDefaultAstarCostModifier *this, hkSimdFloat32 *result, hkaiAstarCostModifier::NavVolumeGetModifiedCostCallbackContext *context)
{
  hkaiNavVolumeCellPairInfo *v3; // r9
  __m128 v4; // xmm2
  hkaiDefaultAstarCostModifier *v5; // r10
  hkaiNavVolume::Cell *v6; // rax
  __m128 v7; // xmm0
  __int64 v8; // rax
  hkaiNavVolume::Cell *v9; // rax
  __int64 v10; // rcx
  hkSimdFloat32 *v11; // rax
  unsigned int v12; // [rsp+10h] [rbp+10h]
  unsigned int v13; // [rsp+10h] [rbp+10h]

  v3 = context->m_cellEdgeInfo;
  v4 = query.m_quad;
  v5 = this;
  v6 = v3->m_currentCellInfo.m_cell;
  v7 = query.m_quad;
  if ( v6 )
  {
    v8 = v6->m_data;
    if ( (signed int)v8 < 32 )
    {
      v12 = this->m_costMultiplierLookupTable[v8].m_value << 16;
      v4 = _mm_shuffle_ps((__m128)v12, (__m128)v12, 0);
    }
  }
  v9 = v3->m_adjacentCellInfo.m_cell;
  if ( v9 )
  {
    v10 = v9->m_data;
    if ( (signed int)v10 < 32 )
    {
      v13 = v5->m_costMultiplierLookupTable[v10].m_value << 16;
      v7 = _mm_shuffle_ps((__m128)v13, (__m128)v13, 0);
    }
  }
  v11 = result;
  result->m_real = _mm_add_ps(
                     _mm_mul_ps(context->m_adjacentCost.m_real, v7),
                     _mm_mul_ps(context->m_currentCost.m_real, v4));
  return v11;
}

