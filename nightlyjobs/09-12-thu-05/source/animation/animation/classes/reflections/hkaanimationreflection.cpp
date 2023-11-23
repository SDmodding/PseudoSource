// File Line: 59
// RVA: 0x15BE670
hkClassEnum *dynamic_initializer_for__hkaAnimation::Members__()
{
  hkClassEnum *result; // rax

  result = hkaAnimationAnimationTypeEnum;
  hkaAnimation::Members.m_enum = hkaAnimationAnimationTypeEnum;
  return result;
}

// File Line: 81
// RVA: 0x15BE680
void dynamic_initializer_for__hkaAnimationClass__()
{
  hkClass::hkClass(
    &hkaAnimationClass,
    "hkaAnimation",
    &hkReferencedObjectClass,
    56,
    0i64,
    0,
    &hkaAnimationEnums,
    1,
    &hkaAnimation::Members,
    6,
    0i64,
    0i64,
    0,
    3);
}

// File Line: 84
// RVA: 0xB1CC10
hkClass *__fastcall hkaAnimation::staticClass()
{
  return &hkaAnimationClass;
}

