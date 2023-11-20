// File Line: 61
// RVA: 0x15BFF70
hkClassEnum *dynamic_initializer_for__hkaiAstarCostModifierClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiAstarCostModifierCostModifierTypeEnum;
  hkaiAstarCostModifierClass_Members.m_enum = hkaiAstarCostModifierCostModifierTypeEnum;
  return result;
}

// File Line: 78
// RVA: 0x15BFF00
void dynamic_initializer_for__hkaiAstarCostModifierClass__()
{
  hkClass::hkClass(
    &hkaiAstarCostModifierClass,
    "hkaiAstarCostModifier",
    &hkReferencedObjectClass,
    24,
    0i64,
    0,
    &hkaiAstarCostModifierEnums,
    1,
    &hkaiAstarCostModifierClass_Members,
    1,
    0i64,
    0i64,
    0,
    3u);
}

// File Line: 81
// RVA: 0xBB5E10
hkClass *__fastcall hkaiAstarCostModifier::staticClass()
{
  return &hkaiAstarCostModifierClass;
}

