// File Line: 57
// RVA: 0x15D53C0
void dynamic_initializer_for__hkpVehicleDefaultSteeringClass__()
{
  hkClass::hkClass(
    &hkpVehicleDefaultSteeringClass,
    "hkpVehicleDefaultSteering",
    &hkpVehicleSteeringClass,
    40,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleDefaultSteeringClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 60
// RVA: 0xE25690
hkClass *__fastcall hkpVehicleDefaultSteering::staticClass()
{
  return &hkpVehicleDefaultSteeringClass;
}

// File Line: 67
// RVA: 0xE256A0
void __fastcall finishLoadedObjecthkpVehicleDefaultSteering(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpVehicleDefaultSteering::`vftable;
}

// File Line: 73
// RVA: 0xE256C0
void __fastcall cleanupLoadedObjecthkpVehicleDefaultSteering(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 77
// RVA: 0xE256D0
void **__fastcall getVtablehkpVehicleDefaultSteering()
{
  return &hkpVehicleDefaultSteering::`vftable;
}

// File Line: 99
// RVA: 0x15D5430
void **dynamic_initializer_for__hkpVehicleDefaultSteeringTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleDefaultSteering();
  hkpVehicleDefaultSteeringTypeInfo.m_size = 40i64;
  hkpVehicleDefaultSteeringTypeInfo.m_typeName = "hkpVehicleDefaultSteering";
  hkpVehicleDefaultSteeringTypeInfo.m_vtable = result;
  hkpVehicleDefaultSteeringTypeInfo.m_scopedName = "!hkpVehicleDefaultSteering";
  hkpVehicleDefaultSteeringTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpVehicleDefaultSteering;
  hkpVehicleDefaultSteeringTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpVehicleDefaultSteering;
  return result;
}

