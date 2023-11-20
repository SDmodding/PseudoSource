// File Line: 34
// RVA: 0xF5780
hkSimdFloat32 *__fastcall hkaiUFGNavMeshCostModifier::getModifiedCost(hkaiUFGNavMeshCostModifier *this, hkSimdFloat32 *result, hkaiAstarCostModifier::NavMeshGetModifiedCostCallbackContext *context)
{
  hkSimdFloat32 *v3; // rax

  v3 = result;
  _mm_store_si128((__m128i *)result, (__m128i)context->m_originalCost.m_real);
  return v3;
}

