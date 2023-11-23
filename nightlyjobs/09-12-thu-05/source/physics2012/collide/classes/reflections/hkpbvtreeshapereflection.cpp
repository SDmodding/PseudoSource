// File Line: 55
// RVA: 0x15C9910
hkClassEnum *dynamic_initializer_for__hkpBvTreeShapeClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkpBvTreeShapeBvTreeTypeEnum;
  hkpBvTreeShapeClass_Members.m_enum = hkpBvTreeShapeBvTreeTypeEnum;
  return result;
}

// File Line: 93
// RVA: 0x15C9890
void dynamic_initializer_for__hkpBvTreeShapeClass__()
{
  hkClass::hkClass(
    &hkpBvTreeShapeClass,
    "hkpBvTreeShape",
    &hkpShapeClass,
    40,
    0i64,
    0,
    &hkpBvTreeShapeEnums,
    1,
    &hkpBvTreeShapeClass_Members,
    1,
    &hkpBvTreeShape_Default,
    0i64,
    0,
    1);
}

// File Line: 96
// RVA: 0xCEAF40
hkClass *__fastcall hkpBvTreeShape::staticClass()
{
  return &hkpBvTreeShapeClass;
}

