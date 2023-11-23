// File Line: 53
// RVA: 0x15CE1A0
void dynamic_initializer_for__hkpSpringDamperConstraintMotorClass__()
{
  hkClass::hkClass(
    &hkpSpringDamperConstraintMotorClass,
    "hkpSpringDamperConstraintMotor",
    &hkpLimitedForceConstraintMotorClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkpSpringDamperConstraintMotorClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 56
// RVA: 0xD44660
hkClass *__fastcall hkpSpringDamperConstraintMotor::staticClass()
{
  return &hkpSpringDamperConstraintMotorClass;
}

// File Line: 63
// RVA: 0xD44670
void __fastcall finishLoadedObjecthkpSpringDamperConstraintMotor(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpSpringDamperConstraintMotor::`vftable;
}

// File Line: 69
// RVA: 0xD44690
void __fastcall cleanupLoadedObjecthkpSpringDamperConstraintMotor(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 73
// RVA: 0xD446A0
void **__fastcall getVtablehkpSpringDamperConstraintMotor()
{
  return &hkpSpringDamperConstraintMotor::`vftable;
}

// File Line: 95
// RVA: 0x15CE210
void **dynamic_initializer_for__hkpSpringDamperConstraintMotorTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpSpringDamperConstraintMotor();
  hkpSpringDamperConstraintMotorTypeInfo.m_size = 40i64;
  hkpSpringDamperConstraintMotorTypeInfo.m_typeName = "hkpSpringDamperConstraintMotor";
  hkpSpringDamperConstraintMotorTypeInfo.m_vtable = result;
  hkpSpringDamperConstraintMotorTypeInfo.m_scopedName = "!hkpSpringDamperConstraintMotor";
  hkpSpringDamperConstraintMotorTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpSpringDamperConstraintMotor;
  hkpSpringDamperConstraintMotorTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpSpringDamperConstraintMotor;
  return result;
}

