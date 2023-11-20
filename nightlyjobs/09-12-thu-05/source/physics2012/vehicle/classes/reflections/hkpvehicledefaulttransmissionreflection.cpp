// File Line: 58
// RVA: 0x15D55C0
void dynamic_initializer_for__hkpVehicleDefaultTransmissionClass__()
{
  hkClass::hkClass(
    &hkpVehicleDefaultTransmissionClass,
    "hkpVehicleDefaultTransmission",
    &hkpVehicleTransmissionClass,
    72,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleDefaultTransmissionClass_Members,
    7,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 61
// RVA: 0xE257F0
hkClass *__fastcall hkpVehicleDefaultTransmission::staticClass()
{
  return &hkpVehicleDefaultTransmissionClass;
}

// File Line: 68
// RVA: 0xE25800
void __fastcall finishLoadedObjecthkpVehicleDefaultTransmission(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpVehicleDefaultTransmission::`vftable';
}

// File Line: 74
// RVA: 0xE25820
void __fastcall cleanupLoadedObjecthkpVehicleDefaultTransmission(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 78
// RVA: 0xE25830
void **__fastcall getVtablehkpVehicleDefaultTransmission()
{
  return &hkpVehicleDefaultTransmission::`vftable';
}

// File Line: 100
// RVA: 0x15D5630
void **dynamic_initializer_for__hkpVehicleDefaultTransmissionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleDefaultTransmission();
  hkpVehicleDefaultTransmissionTypeInfo.m_size = 72i64;
  hkpVehicleDefaultTransmissionTypeInfo.m_typeName = "hkpVehicleDefaultTransmission";
  hkpVehicleDefaultTransmissionTypeInfo.m_vtable = result;
  hkpVehicleDefaultTransmissionTypeInfo.m_scopedName = "!hkpVehicleDefaultTransmission";
  hkpVehicleDefaultTransmissionTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpVehicleDefaultTransmission;
  hkpVehicleDefaultTransmissionTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpVehicleDefaultTransmission;
  return result;
}

