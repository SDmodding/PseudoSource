// File Line: 54
// RVA: 0x15D5690
void dynamic_initializer_for__hkpVehicleDefaultVelocityDamperClass__()
{
  hkClass::hkClass(
    &hkpVehicleDefaultVelocityDamperClass,
    "hkpVehicleDefaultVelocityDamper",
    &hkpVehicleVelocityDamperClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleDefaultVelocityDamperClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xE258A0
hkClass *__fastcall hkpVehicleDefaultVelocityDamper::staticClass()
{
  return &hkpVehicleDefaultVelocityDamperClass;
}

// File Line: 64
// RVA: 0xE258B0
void __fastcall finishLoadedObjecthkpVehicleDefaultVelocityDamper(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpVehicleDefaultVelocityDamper::`vftable;
}

// File Line: 70
// RVA: 0xE258D0
void __fastcall cleanupLoadedObjecthkpVehicleDefaultVelocityDamper(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 74
// RVA: 0xE258E0
void **__fastcall getVtablehkpVehicleDefaultVelocityDamper()
{
  return &hkpVehicleDefaultVelocityDamper::`vftable;
}

// File Line: 96
// RVA: 0x15D5700
void **dynamic_initializer_for__hkpVehicleDefaultVelocityDamperTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleDefaultVelocityDamper();
  hkpVehicleDefaultVelocityDamperTypeInfo.m_size = 32i64;
  hkpVehicleDefaultVelocityDamperTypeInfo.m_typeName = "hkpVehicleDefaultVelocityDamper";
  hkpVehicleDefaultVelocityDamperTypeInfo.m_vtable = result;
  hkpVehicleDefaultVelocityDamperTypeInfo.m_scopedName = "!hkpVehicleDefaultVelocityDamper";
  hkpVehicleDefaultVelocityDamperTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpVehicleDefaultVelocityDamper;
  hkpVehicleDefaultVelocityDamperTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpVehicleDefaultVelocityDamper;
  return result;
}

