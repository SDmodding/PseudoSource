// File Line: 61
// RVA: 0x15D5220
void dynamic_initializer_for__hkpVehicleDefaultEngineClass__()
{
  hkClass::hkClass(
    &hkpVehicleDefaultEngineClass,
    "hkpVehicleDefaultEngine",
    &hkpVehicleEngineClass,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleDefaultEngineClass_Members,
    10,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 64
// RVA: 0xE25570
hkClass *__fastcall hkpVehicleDefaultEngine::staticClass()
{
  return &hkpVehicleDefaultEngineClass;
}

// File Line: 71
// RVA: 0xE25580
void __fastcall finishLoadedObjecthkpVehicleDefaultEngine(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpVehicleDefaultEngine::`vftable;
}

// File Line: 77
// RVA: 0xE255A0
void __fastcall cleanupLoadedObjecthkpVehicleDefaultEngine(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 81
// RVA: 0xE255B0
void **__fastcall getVtablehkpVehicleDefaultEngine()
{
  return &hkpVehicleDefaultEngine::`vftable;
}

// File Line: 103
// RVA: 0x15D5290
void **dynamic_initializer_for__hkpVehicleDefaultEngineTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleDefaultEngine();
  hkpVehicleDefaultEngineTypeInfo.m_size = 56i64;
  hkpVehicleDefaultEngineTypeInfo.m_typeName = "hkpVehicleDefaultEngine";
  hkpVehicleDefaultEngineTypeInfo.m_vtable = result;
  hkpVehicleDefaultEngineTypeInfo.m_scopedName = "!hkpVehicleDefaultEngine";
  hkpVehicleDefaultEngineTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpVehicleDefaultEngine;
  hkpVehicleDefaultEngineTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpVehicleDefaultEngine;
  return result;
}

