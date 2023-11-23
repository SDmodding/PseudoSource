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
void __fastcall finishLoadedObjecthkpVehiclePerWheelSimulationWheelData(
        hkpConstraintData *p,
        hkFinishLoadedObjectFlag finishing)
{
  hkpConstraintData *v2; // rbx

  if ( p )
  {
    v2 = p + 2;
    hkpConstraintData::hkpConstraintData(p + 2, finishing);
    v2->vfptr = (hkBaseObjectVtbl *)&hkpWheelFrictionConstraintData::`vftable;
    if ( finishing.m_finishing )
    {
      *(hkBaseObjectVtbl **)((char *)&v2[8].vfptr + 4) = 0i64;
      *(_QWORD *)(&v2[8].m_referenceCount + 1) = 0i64;
    }
  }
}

// File Line: 78
// RVA: 0xE25CD0
void __fastcall cleanupLoadedObjecthkpVehiclePerWheelSimulationWheelData(_QWORD *p)
{
  p[6] = &hkBaseObject::`vftable;
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
void __fastcall finishLoadedObjecthkpVehiclePerWheelSimulation(_QWORD *p, int finishing)
{
  if ( p )
  {
    *p = &hkpVehiclePerWheelSimulation::`vftable{for `hkpVehicleSimulation};
    p[2] = &hkpVehiclePerWheelSimulation::`vftable{for `hkpWorldPostSimulationListener};
  }
}

// File Line: 139
// RVA: 0xE25D20
void __fastcall cleanupLoadedObjecthkpVehiclePerWheelSimulation(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
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
  hkpVehiclePerWheelSimulationTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpVehiclePerWheelSimulation;
  hkpVehiclePerWheelSimulationTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpVehiclePerWheelSimulation;
  return result;
}

