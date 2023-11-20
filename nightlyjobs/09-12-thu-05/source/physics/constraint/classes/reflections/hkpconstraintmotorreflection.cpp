// File Line: 55
// RVA: 0x15CF430
hkClassEnum *dynamic_initializer_for__hkpConstraintMotorClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkpConstraintMotorMotorTypeEnum;
  hkpConstraintMotorClass_Members.m_enum = hkpConstraintMotorMotorTypeEnum;
  return result;
}

// File Line: 72
// RVA: 0x15CF3C0
void dynamic_initializer_for__hkpConstraintMotorClass__()
{
  hkClass::hkClass(
    &hkpConstraintMotorClass,
    "hkpConstraintMotor",
    &hkReferencedObjectClass,
    24,
    0i64,
    0,
    &hkpConstraintMotorEnums,
    1,
    &hkpConstraintMotorClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 75
// RVA: 0xD44FB0
hkClass *__fastcall hkpConstraintMotor::staticClass()
{
  return &hkpConstraintMotorClass;
}

