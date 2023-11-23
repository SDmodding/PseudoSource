// File Line: 52
// RVA: 0x15D49C0
void dynamic_initializer_for__hkpMultithreadedVehicleManagerClass__()
{
  hkClass::hkClass(
    &hkpMultithreadedVehicleManagerClass,
    "hkpMultithreadedVehicleManager",
    &hkpVehicleManagerClass,
    32,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 55
// RVA: 0xE24E20
hkClass *__fastcall hkpMultithreadedVehicleManager::staticClass()
{
  return &hkpMultithreadedVehicleManagerClass;
}

// File Line: 62
// RVA: 0xE24E30
void __fastcall finishLoadedObjecthkpMultithreadedVehicleManager(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpMultithreadedVehicleManager::`vftable;
}

// File Line: 68
// RVA: 0xE24E50
void __fastcall cleanupLoadedObjecthkpMultithreadedVehicleManager(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 72
// RVA: 0xE24E60
void **__fastcall getVtablehkpMultithreadedVehicleManager()
{
  return &hkpMultithreadedVehicleManager::`vftable;
}

// File Line: 94
// RVA: 0x15D4A20
void **dynamic_initializer_for__hkpMultithreadedVehicleManagerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpMultithreadedVehicleManager();
  hkpMultithreadedVehicleManagerTypeInfo.m_size = 32i64;
  hkpMultithreadedVehicleManagerTypeInfo.m_typeName = "hkpMultithreadedVehicleManager";
  hkpMultithreadedVehicleManagerTypeInfo.m_vtable = result;
  hkpMultithreadedVehicleManagerTypeInfo.m_scopedName = "!hkpMultithreadedVehicleManager";
  hkpMultithreadedVehicleManagerTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpMultithreadedVehicleManager;
  hkpMultithreadedVehicleManagerTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpMultithreadedVehicleManager;
  return result;
}

