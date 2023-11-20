// File Line: 56
// RVA: 0x15D4E80
void dynamic_initializer_for__hkpVehicleDefaultAerodynamicsClass__()
{
  hkClass::hkClass(
    &hkpVehicleDefaultAerodynamicsClass,
    "hkpVehicleDefaultAerodynamics",
    &hkpVehicleAerodynamicsClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleDefaultAerodynamicsClass_Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xE25370
hkClass *__fastcall hkpVehicleDefaultAerodynamics::staticClass()
{
  return &hkpVehicleDefaultAerodynamicsClass;
}

// File Line: 66
// RVA: 0xE25380
void __fastcall finishLoadedObjecthkpVehicleDefaultAerodynamics(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpVehicleDefaultAerodynamics::`vftable';
}

// File Line: 72
// RVA: 0xE253A0
void __fastcall cleanupLoadedObjecthkpVehicleDefaultAerodynamics(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 76
// RVA: 0xE253B0
void **__fastcall getVtablehkpVehicleDefaultAerodynamics()
{
  return &hkpVehicleDefaultAerodynamics::`vftable';
}

// File Line: 98
// RVA: 0x15D4EF0
void **dynamic_initializer_for__hkpVehicleDefaultAerodynamicsTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleDefaultAerodynamics();
  hkpVehicleDefaultAerodynamicsTypeInfo.m_size = 48i64;
  hkpVehicleDefaultAerodynamicsTypeInfo.m_typeName = "hkpVehicleDefaultAerodynamics";
  hkpVehicleDefaultAerodynamicsTypeInfo.m_vtable = result;
  hkpVehicleDefaultAerodynamicsTypeInfo.m_scopedName = "!hkpVehicleDefaultAerodynamics";
  hkpVehicleDefaultAerodynamicsTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpVehicleDefaultAerodynamics;
  hkpVehicleDefaultAerodynamicsTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpVehicleDefaultAerodynamics;
  return result;
}

