// File Line: 54
// RVA: 0x15CE270
void dynamic_initializer_for__hkpVelocityConstraintMotorClass__()
{
  hkClass::hkClass(
    &hkpVelocityConstraintMotorClass,
    "hkpVelocityConstraintMotor",
    &hkpLimitedForceConstraintMotorClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkpVelocityConstraintMotorClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xD446B0
hkClass *__fastcall hkpVelocityConstraintMotor::staticClass()
{
  return &hkpVelocityConstraintMotorClass;
}

// File Line: 64
// RVA: 0xD446C0
void __fastcall finishLoadedObjecthkpVelocityConstraintMotor(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpVelocityConstraintMotor::`vftable;
}

// File Line: 70
// RVA: 0xD446E0
void __fastcall cleanupLoadedObjecthkpVelocityConstraintMotor(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 74
// RVA: 0xD446F0
void **__fastcall getVtablehkpVelocityConstraintMotor()
{
  return &hkpVelocityConstraintMotor::`vftable;
}

// File Line: 96
// RVA: 0x15CE2E0
void **dynamic_initializer_for__hkpVelocityConstraintMotorTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVelocityConstraintMotor();
  hkpVelocityConstraintMotorTypeInfo.m_size = 48i64;
  hkpVelocityConstraintMotorTypeInfo.m_typeName = "hkpVelocityConstraintMotor";
  hkpVelocityConstraintMotorTypeInfo.m_vtable = result;
  hkpVelocityConstraintMotorTypeInfo.m_scopedName = "!hkpVelocityConstraintMotor";
  hkpVelocityConstraintMotorTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpVelocityConstraintMotor;
  hkpVelocityConstraintMotorTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpVelocityConstraintMotor;
  return result;
}

