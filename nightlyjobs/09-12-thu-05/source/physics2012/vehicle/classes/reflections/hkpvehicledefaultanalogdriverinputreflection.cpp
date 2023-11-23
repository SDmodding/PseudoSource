// File Line: 55
// RVA: 0x15D5020
void dynamic_initializer_for__hkpVehicleDriverInputAnalogStatusClass__()
{
  hkClass::hkClass(
    &hkpVehicleDriverInputAnalogStatusClass,
    "hkpVehicleDriverInputAnalogStatus",
    &hkpVehicleDriverInputStatusClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleDriverInputAnalogStatusClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xE253C0
hkClass *__fastcall hkpVehicleDriverInputAnalogStatus::staticClass()
{
  return &hkpVehicleDriverInputAnalogStatusClass;
}

// File Line: 65
// RVA: 0xE253E0
void __fastcall finishLoadedObjecthkpVehicleDriverInputAnalogStatus(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpVehicleDriverInputAnalogStatus::`vftable;
}

// File Line: 71
// RVA: 0xE25400
void __fastcall cleanupLoadedObjecthkpVehicleDriverInputAnalogStatus(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 75
// RVA: 0xE25410
void **__fastcall getVtablehkpVehicleDriverInputAnalogStatus()
{
  return &hkpVehicleDriverInputAnalogStatus::`vftable;
}

// File Line: 97
// RVA: 0x15D5090
void **dynamic_initializer_for__hkpVehicleDriverInputAnalogStatusTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleDriverInputAnalogStatus();
  hkpVehicleDriverInputAnalogStatusTypeInfo.m_size = 32i64;
  hkpVehicleDriverInputAnalogStatusTypeInfo.m_typeName = "hkpVehicleDriverInputAnalogStatus";
  hkpVehicleDriverInputAnalogStatusTypeInfo.m_vtable = result;
  hkpVehicleDriverInputAnalogStatusTypeInfo.m_scopedName = "!hkpVehicleDriverInputAnalogStatus";
  hkpVehicleDriverInputAnalogStatusTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpVehicleDriverInputAnalogStatus;
  hkpVehicleDriverInputAnalogStatusTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpVehicleDriverInputAnalogStatus;
  return result;
}

// File Line: 127
// RVA: 0x15D4F50
void dynamic_initializer_for__hkpVehicleDefaultAnalogDriverInputClass__()
{
  hkClass::hkClass(
    &hkpVehicleDefaultAnalogDriverInputClass,
    "hkpVehicleDefaultAnalogDriverInput",
    &hkpVehicleDriverInputClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleDefaultAnalogDriverInputClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 130
// RVA: 0xE253D0
hkClass *__fastcall hkpVehicleDefaultAnalogDriverInput::staticClass()
{
  return &hkpVehicleDefaultAnalogDriverInputClass;
}

// File Line: 137
// RVA: 0xE25420
void __fastcall finishLoadedObjecthkpVehicleDefaultAnalogDriverInput(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpVehicleDefaultAnalogDriverInput::`vftable;
}

// File Line: 143
// RVA: 0xE25440
void __fastcall cleanupLoadedObjecthkpVehicleDefaultAnalogDriverInput(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 147
// RVA: 0xE25450
void **__fastcall getVtablehkpVehicleDefaultAnalogDriverInput()
{
  return &hkpVehicleDefaultAnalogDriverInput::`vftable;
}

// File Line: 169
// RVA: 0x15D4FC0
void **dynamic_initializer_for__hkpVehicleDefaultAnalogDriverInputTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleDefaultAnalogDriverInput();
  hkpVehicleDefaultAnalogDriverInputTypeInfo.m_size = 32i64;
  hkpVehicleDefaultAnalogDriverInputTypeInfo.m_typeName = "hkpVehicleDefaultAnalogDriverInput";
  hkpVehicleDefaultAnalogDriverInputTypeInfo.m_vtable = result;
  hkpVehicleDefaultAnalogDriverInputTypeInfo.m_scopedName = "!hkpVehicleDefaultAnalogDriverInput";
  hkpVehicleDefaultAnalogDriverInputTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpVehicleDefaultAnalogDriverInput;
  hkpVehicleDefaultAnalogDriverInputTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpVehicleDefaultAnalogDriverInput;
  return result;
}

