// File Line: 54
// RVA: 0x15D51C0
void dynamic_initializer_for__hkpVehicleDefaultBrakeWheelBrakingPropertiesClass__()
{
  hkClass::hkClass(
    &hkpVehicleDefaultBrakeWheelBrakingPropertiesClass,
    "hkpVehicleDefaultBrakeWheelBrakingProperties",
    0i64,
    12,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleDefaultBrake_WheelBrakingPropertiesClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xE25470
hkClass *__fastcall hkpVehicleDefaultBrake::WheelBrakingProperties::staticClass()
{
  return &hkpVehicleDefaultBrakeWheelBrakingPropertiesClass;
}

// File Line: 64
// RVA: 0xE25480
void __fastcall cleanupLoadedObjecthkpVehicleDefaultBrakeWheelBrakingProperties(void *p)
{
  ;
}

// File Line: 103
// RVA: 0x15D50F0
void dynamic_initializer_for__hkpVehicleDefaultBrakeClass__()
{
  hkClass::hkClass(
    &hkpVehicleDefaultBrakeClass,
    "hkpVehicleDefaultBrake",
    &hkpVehicleBrakeClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleDefaultBrakeClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 106
// RVA: 0xE25460
hkClass *__fastcall hkpVehicleDefaultBrake::staticClass()
{
  return &hkpVehicleDefaultBrakeClass;
}

// File Line: 113
// RVA: 0xE25490
void __fastcall finishLoadedObjecthkpVehicleDefaultBrake(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpVehicleDefaultBrake::`vftable;
}

// File Line: 119
// RVA: 0xE254B0
void __fastcall cleanupLoadedObjecthkpVehicleDefaultBrake(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 123
// RVA: 0xE254C0
void **__fastcall getVtablehkpVehicleDefaultBrake()
{
  return &hkpVehicleDefaultBrake::`vftable;
}

// File Line: 145
// RVA: 0x15D5160
void **dynamic_initializer_for__hkpVehicleDefaultBrakeTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleDefaultBrake();
  hkpVehicleDefaultBrakeTypeInfo.m_size = 40i64;
  hkpVehicleDefaultBrakeTypeInfo.m_typeName = "hkpVehicleDefaultBrake";
  hkpVehicleDefaultBrakeTypeInfo.m_vtable = result;
  hkpVehicleDefaultBrakeTypeInfo.m_scopedName = "!hkpVehicleDefaultBrake";
  hkpVehicleDefaultBrakeTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpVehicleDefaultBrake;
  hkpVehicleDefaultBrakeTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpVehicleDefaultBrake;
  return result;
}

