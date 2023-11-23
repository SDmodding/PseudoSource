// File Line: 14
// RVA: 0xBD37F0
hkSimdFloat32 *__fastcall hkaiAstarCostModifier::getModifiedCost(
        hkaiAstarCostModifier *this,
        hkSimdFloat32 *result,
        hkaiAstarCostModifier::NavVolumeGetModifiedCostCallbackContext *context)
{
  hkSimdFloat32 *v3; // rax

  v3 = result;
  result->m_real = _mm_add_ps(context->m_adjacentCost.m_real, context->m_currentCost.m_real);
  return v3;
}

// File Line: 19
// RVA: 0xBD3810
hkSimdFloat32 *__fastcall hkaiAstarCostModifier::getModifiedCost(
        hkaiAstarCostModifier *this,
        hkSimdFloat32 *result,
        hkaiAstarCostModifier::DirectedGraphGetModifiedCostCallbackContext *context)
{
  hkSimdFloat32 *v3; // rax

  v3 = result;
  *result = context->m_edgeCost;
  return v3;
}

