// File Line: 53
// RVA: 0x15CF440
void dynamic_initializer_for__hkpLimitedForceConstraintMotorClass__()
{
  hkClass::hkClass(
    &hkpLimitedForceConstraintMotorClass,
    "hkpLimitedForceConstraintMotor",
    &hkpConstraintMotorClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpLimitedForceConstraintMotorClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 56
// RVA: 0xD44FC0
hkClass *__fastcall hkpLimitedForceConstraintMotor::staticClass()
{
  return &hkpLimitedForceConstraintMotorClass;
}

