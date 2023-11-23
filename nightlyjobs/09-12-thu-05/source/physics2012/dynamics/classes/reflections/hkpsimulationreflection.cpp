// File Line: 78
// RVA: 0x15D1670
hkClassEnum *dynamic_initializer_for__hkpSimulation::Members__()
{
  hkClassEnum *result; // rax

  result = hkpSimulationLastProcessingStepEnum;
  unk_142111700 = hkpSimulationLastProcessingStepEnum;
  return result;
}

// File Line: 101
// RVA: 0x15D1680
void dynamic_initializer_for__hkpSimulationClass__()
{
  hkClass::hkClass(
    &hkpSimulationClass,
    "hkpSimulation",
    &hkReferencedObjectClass,
    64,
    0i64,
    0,
    &hkpSimulationEnums,
    3,
    &hkpSimulation::Members,
    9,
    0i64,
    0i64,
    1u,
    0);
}

// File Line: 104
// RVA: 0xD51100
hkClass *__fastcall hkpSimulation::staticClass()
{
  return &hkpSimulationClass;
}

// File Line: 111
// RVA: 0xD51110
void __fastcall finishLoadedObjecthkpSimulation(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpSimulation::`vftable;
}

// File Line: 117
// RVA: 0xD51130
void __fastcall cleanupLoadedObjecthkpSimulation(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 121
// RVA: 0xD51140
void **__fastcall getVtablehkpSimulation()
{
  return &hkpSimulation::`vftable;
}

// File Line: 143
// RVA: 0x15D16F0
void **dynamic_initializer_for__hkpSimulationTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpSimulation();
  hkpSimulationTypeInfo.m_size = 64i64;
  hkpSimulationTypeInfo.m_typeName = "hkpSimulation";
  hkpSimulationTypeInfo.m_vtable = result;
  hkpSimulationTypeInfo.m_scopedName = "!hkpSimulation";
  hkpSimulationTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpSimulation;
  hkpSimulationTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpSimulation;
  return result;
}

