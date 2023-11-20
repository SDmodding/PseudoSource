// File Line: 57
// RVA: 0x15D52F0
void dynamic_initializer_for__hkpVehicleDefaultSimulationClass__()
{
  hkClass::hkClass(
    &hkpVehicleDefaultSimulationClass,
    "hkpVehicleDefaultSimulation",
    &hkpVehicleSimulationClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleDefaultSimulation::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 60
// RVA: 0xE255C0
hkClass *__fastcall hkpVehicleDefaultSimulation::staticClass()
{
  return &hkpVehicleDefaultSimulationClass;
}

// File Line: 67
// RVA: 0xE255D0
void __fastcall finishLoadedObjecthkpVehicleDefaultSimulation(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpVehicleDefaultSimulation::`vftable';
}

// File Line: 73
// RVA: 0xE255F0
void __fastcall cleanupLoadedObjecthkpVehicleDefaultSimulation(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 77
// RVA: 0xE25600
void **__fastcall getVtablehkpVehicleDefaultSimulation()
{
  return &hkpVehicleDefaultSimulation::`vftable';
}

// File Line: 99
// RVA: 0x15D5360
void **dynamic_initializer_for__hkpVehicleDefaultSimulationTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleDefaultSimulation();
  hkpVehicleDefaultSimulationTypeInfo.m_size = 96i64;
  hkpVehicleDefaultSimulationTypeInfo.m_typeName = "hkpVehicleDefaultSimulation";
  hkpVehicleDefaultSimulationTypeInfo.m_vtable = result;
  hkpVehicleDefaultSimulationTypeInfo.m_scopedName = "!hkpVehicleDefaultSimulation";
  hkpVehicleDefaultSimulationTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpVehicleDefaultSimulation;
  hkpVehicleDefaultSimulationTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpVehicleDefaultSimulation;
  return result;
}

