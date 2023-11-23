// File Line: 55
// RVA: 0x15CCED0
hkClassEnum *dynamic_initializer_for__hkpCallbackConstraintMotorClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkpCallbackConstraintMotorCallbackTypeEnum;
  unk_14210F1E8 = hkpCallbackConstraintMotorCallbackTypeEnum;
  return result;
}

// File Line: 95
// RVA: 0x15CCE50
void dynamic_initializer_for__hkpCallbackConstraintMotorClass__()
{
  hkClass::hkClass(
    &hkpCallbackConstraintMotorClass,
    "hkpCallbackConstraintMotor",
    &hkpLimitedForceConstraintMotorClass,
    72,
    0i64,
    0,
    &hkpCallbackConstraintMotorEnums,
    1,
    &hkpCallbackConstraintMotorClass_Members,
    5,
    &hkpCallbackConstraintMotor_Default,
    0i64,
    0,
    0);
}

// File Line: 98
// RVA: 0xD43620
hkClass *__fastcall hkpCallbackConstraintMotor::staticClass()
{
  return &hkpCallbackConstraintMotorClass;
}

// File Line: 105
// RVA: 0xD43630
void __fastcall finishLoadedObjecthkpCallbackConstraintMotor(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpCallbackConstraintMotor::`vftable;
}

// File Line: 111
// RVA: 0xD43650
void __fastcall cleanupLoadedObjecthkpCallbackConstraintMotor(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 115
// RVA: 0xD43660
void **__fastcall getVtablehkpCallbackConstraintMotor()
{
  return &hkpCallbackConstraintMotor::`vftable;
}

// File Line: 137
// RVA: 0x15CCEE0
void **dynamic_initializer_for__hkpCallbackConstraintMotorTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpCallbackConstraintMotor();
  hkpCallbackConstraintMotorTypeInfo.m_size = 72i64;
  hkpCallbackConstraintMotorTypeInfo.m_typeName = "hkpCallbackConstraintMotor";
  hkpCallbackConstraintMotorTypeInfo.m_vtable = result;
  hkpCallbackConstraintMotorTypeInfo.m_scopedName = "!hkpCallbackConstraintMotor";
  hkpCallbackConstraintMotorTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpCallbackConstraintMotor;
  hkpCallbackConstraintMotorTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpCallbackConstraintMotor;
  return result;
}

