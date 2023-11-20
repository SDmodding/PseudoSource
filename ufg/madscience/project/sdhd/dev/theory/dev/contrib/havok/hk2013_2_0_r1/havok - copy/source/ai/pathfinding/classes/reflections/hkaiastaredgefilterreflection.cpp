// File Line: 60
// RVA: 0x15BFFF0
hkClassEnum *dynamic_initializer_for__hkaiAstarEdgeFilterClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiAstarEdgeFilterEdgeFilterTypeEnum;
  hkaiAstarEdgeFilterClass_Members.m_enum = hkaiAstarEdgeFilterEdgeFilterTypeEnum;
  return result;
}

// File Line: 77
// RVA: 0x15BFF80
void dynamic_initializer_for__hkaiAstarEdgeFilterClass__()
{
  hkClass::hkClass(
    &hkaiAstarEdgeFilterClass,
    "hkaiAstarEdgeFilter",
    &hkReferencedObjectClass,
    24,
    0i64,
    0,
    &hkaiAstarEdgeFilterEnums,
    1,
    &hkaiAstarEdgeFilterClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 80
// RVA: 0xBB5E20
hkClass *__fastcall hkaiAstarEdgeFilter::staticClass()
{
  return &hkaiAstarEdgeFilterClass;
}

