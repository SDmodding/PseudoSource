// File Line: 34
// RVA: 0xF5780
hkSimdFloat32 *__fastcall hkaiUFGNavMeshCostModifier::getModifiedCost(
        hkaiUFGNavMeshCostModifier *this,
        hkSimdFloat32 *result,
        hkaiAstarCostModifier::NavMeshGetModifiedCostCallbackContext *context)
{
  hkSimdFloat32 *v3; // rax

  v3 = result;
  *result = context->m_originalCost;
  return v3;
}

