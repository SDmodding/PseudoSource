// File Line: 62
// RVA: 0x15D5C30
void dynamic_initializer_for__hkpVehiclePerWheelSimulationWheelDataClass__()
{
  hkClass::hkClass(
    &hkpVehiclePerWheelSimulationWheelDataClass,
    "hkpVehiclePerWheelSimulationWheelData",
    0i64,
    336,
    0i64,
    0,
    0i64,
    0,
    &hkpVehiclePerWheelSimulation_WheelDataClass_Members,
    6,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 65
// RVA: 0xE25C70
hkClass *__fastcall hkpVehiclePerWheelSimulation::WheelData::staticClass()
{
  return &hkpVehiclePerWheelSimulationWheelDataClass;
}

// File Line: 72
// RVA: 0xE25C80
void __fastcall finishLoadedObjecthkpVehiclePerWheelSimulationWheelData(void *p, int finishing)
{
  _QWORD *v2; // rbx
  int v3; // edi

  if ( p )
  {
    v2 = (char *)p + 48;
    v3 = finishing;
    hkpConstraintData::hkpConstraintData((hkpConstraintData *)p + 2, (hkFinishLoadedObjectFlag)finishing);
    *v2 = &hkpWheelFrictionConstraintData::`vftable;
    if ( v3 )
    {
      *(_QWORD *)((char *)v2 + 196) = 0i64;
      *(_QWORD *)((char *)v2 + 204) = 0i64;
    }
  }
}

// File Line: 78
// RVA: 0xE25CD0
void __fastcall cleanupLoadedObjecthkpVehiclePerWheelSimulationWheelData(void *p)
{
  *((_QWORD *)p + 6) = &hkBaseObject::`vftable;
}

// File Line: 123
// RVA: 0x15D5B60
void dynamic_initializer_for__hkpVehiclePerWheelSimulationClass__()
{
  hkClass::hkClass(
    &hkpVehiclePerWheelSimulationClass,
    "hkpVehiclePerWheelSimulation",
    &hkpVehicleSimulationClass,
    80,
    0i64,
    1,
    0i64,
    0,
    &hkpVehiclePerWheelSimulationClass_Members,
    8,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 126
// RVA: 0xE25C60
hkClass *__fastcall hkpVehiclePerWheelSimulation::staticClass()
{
  return &hkpVehiclePerWheelSimulationClass;
}

// File Line: 133
// RVA: 0xE25CF0
void __fastcall finishLoadedObjecthkpVehiclePerWheelSimulation(void *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpVehiclePerWheelSimulation::`vftable{for `hkpVehicleSimulation};
    *((_QWORD *)p + 2) = &hkpVehiclePerWheelSimulation::`vftable{for `hkpWorldPostSimulationListener};
  }
}

// File Line: 139
// RVA: 0xE25D20
void __fastcall cleanupLoadedObjecthkpVehiclePerWheelSimulation(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 143
// RVA: 0xE25D30
void **__fastcall getVtablehkpVehiclePerWheelSimulation()
{
  return &hkpVehiclePerWheelSimulation::`vftable{for `hkpVehicleSimulation};
}

// File Line: 165
// RVA: 0x15D5BD0
void **dynamic_initializer_for__hkpVehiclePerWheelSimulationTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehiclePerWheelSimulation();
  hkpVehiclePerWheelSimulationTypeInfo.m_size = 80i64;
  hkpVehiclePerWheelSimulationTypeInfo.m_typeName = "hkpVehiclePerWheelSimulation";
  hkpVehiclePerWheelSimulationTypeInfo.m_vtable = result;
  hkpVehiclePerWheelSimulationTypeInfo.m_scopedName = "!hkpVehiclePerWheelSimulation";
  hkpVehiclePerWheelSimulationTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpVehiclePerWheelSimulation;
  hkpVehiclePerWheelSimulationTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpVehiclePerWheelSimulation;
  return result;
}

