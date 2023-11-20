// File Line: 55
// RVA: 0x15CD980
void dynamic_initializer_for__hkpPositionConstraintMotorClass__()
{
  hkClass::hkClass(
    &hkpPositionConstraintMotorClass,
    "hkpPositionConstraintMotor",
    &hkpLimitedForceConstraintMotorClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkpPositionConstraintMotorClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xD43F70
hkClass *__fastcall hkpPositionConstraintMotor::staticClass()
{
  return &hkpPositionConstraintMotorClass;
}

// File Line: 65
// RVA: 0xD43F80
void __fastcall finishLoadedObjecthkpPositionConstraintMotor(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpPositionConstraintMotor::`vftable;
}

// File Line: 71
// RVA: 0xD43FA0
void __fastcall cleanupLoadedObjecthkpPositionConstraintMotor(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 75
// RVA: 0xD43FB0
void **__fastcall getVtablehkpPositionConstraintMotor()
{
  return &hkpPositionConstraintMotor::`vftable;
}

// File Line: 97
// RVA: 0x15CD9F0
void **dynamic_initializer_for__hkpPositionConstraintMotorTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpPositionConstraintMotor();
  hkpPositionConstraintMotorTypeInfo.m_size = 48i64;
  hkpPositionConstraintMotorTypeInfo.m_typeName = "hkpPositionConstraintMotor";
  hkpPositionConstraintMotorTypeInfo.m_vtable = result;
  hkpPositionConstraintMotorTypeInfo.m_scopedName = "!hkpPositionConstraintMotor";
  hkpPositionConstraintMotorTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpPositionConstraintMotor;
  hkpPositionConstraintMotorTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpPositionConstraintMotor;
  return result;
}

