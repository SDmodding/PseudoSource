// File Line: 54
// RVA: 0x15D5560
void dynamic_initializer_for__hkpVehicleDefaultSuspensionWheelSpringSuspensionParametersClass__()
{
  hkClass::hkClass(
    &hkpVehicleDefaultSuspensionWheelSpringSuspensionParametersClass,
    "hkpVehicleDefaultSuspensionWheelSpringSuspensionParameters",
    0i64,
    12,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleDefaultSuspension_WheelSpringSuspensionParametersClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xE25790
hkClass *__fastcall hkpVehicleDefaultSuspension::WheelSpringSuspensionParameters::staticClass()
{
  return &hkpVehicleDefaultSuspensionWheelSpringSuspensionParametersClass;
}

// File Line: 64
// RVA: 0xE257A0
void __fastcall cleanupLoadedObjecthkpVehicleDefaultSuspensionWheelSpringSuspensionParameters(void *p)
{
  ;
}

// File Line: 102
// RVA: 0x15D5490
void dynamic_initializer_for__hkpVehicleDefaultSuspensionClass__()
{
  hkClass::hkClass(
    &hkpVehicleDefaultSuspensionClass,
    "hkpVehicleDefaultSuspension",
    &hkpVehicleSuspensionClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleDefaultSuspensionClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 105
// RVA: 0xE25780
hkClass *__fastcall hkpVehicleDefaultSuspension::staticClass()
{
  return &hkpVehicleDefaultSuspensionClass;
}

// File Line: 112
// RVA: 0xE257B0
void __fastcall finishLoadedObjecthkpVehicleDefaultSuspension(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpVehicleDefaultSuspension::`vftable;
}

// File Line: 118
// RVA: 0xE257D0
void __fastcall cleanupLoadedObjecthkpVehicleDefaultSuspension(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 122
// RVA: 0xE257E0
void **__fastcall getVtablehkpVehicleDefaultSuspension()
{
  return &hkpVehicleDefaultSuspension::`vftable;
}

// File Line: 144
// RVA: 0x15D5500
void **dynamic_initializer_for__hkpVehicleDefaultSuspensionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleDefaultSuspension();
  hkpVehicleDefaultSuspensionTypeInfo.m_size = 48i64;
  hkpVehicleDefaultSuspensionTypeInfo.m_typeName = "hkpVehicleDefaultSuspension";
  hkpVehicleDefaultSuspensionTypeInfo.m_vtable = result;
  hkpVehicleDefaultSuspensionTypeInfo.m_scopedName = "!hkpVehicleDefaultSuspension";
  hkpVehicleDefaultSuspensionTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpVehicleDefaultSuspension;
  hkpVehicleDefaultSuspensionTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpVehicleDefaultSuspension;
  return result;
}

