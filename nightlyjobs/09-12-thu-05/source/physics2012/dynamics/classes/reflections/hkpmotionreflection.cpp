// File Line: 67
// RVA: 0x15D2150
hkClassEnum *dynamic_initializer_for__hkpMotionClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkpMotionMotionTypeEnum;
  hkpMotionClass_Members.m_enum = hkpMotionMotionTypeEnum;
  return result;
}

// File Line: 95
// RVA: 0x15D20D0
void dynamic_initializer_for__hkpMotionClass__()
{
  hkClass::hkClass(
    &hkpMotionClass,
    "hkpMotion",
    &hkReferencedObjectClass,
    320,
    0i64,
    0,
    &hkpMotionEnums,
    1,
    &hkpMotionClass_Members,
    12,
    0i64,
    0i64,
    0,
    3u);
}

// File Line: 98
// RVA: 0xD515D0
hkClass *__fastcall hkpMotion::staticClass()
{
  return &hkpMotionClass;
}

