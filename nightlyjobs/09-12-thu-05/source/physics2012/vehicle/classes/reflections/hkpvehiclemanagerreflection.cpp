// File Line: 55
// RVA: 0x15D5A90
void dynamic_initializer_for__hkpVehicleManagerClass__()
{
  hkClass::hkClass(
    &hkpVehicleManagerClass,
    "hkpVehicleManager",
    &hkReferencedObjectClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkpVehicleManagerClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xE25C10
hkClass *__fastcall hkpVehicleManager::staticClass()
{
  return &hkpVehicleManagerClass;
}

// File Line: 65
// RVA: 0xE25C20
void __fastcall finishLoadedObjecthkpVehicleManager(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpVehicleManager::`vftable;
}

// File Line: 71
// RVA: 0xE25C40
void __fastcall cleanupLoadedObjecthkpVehicleManager(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 75
// RVA: 0xE25C50
void **__fastcall getVtablehkpVehicleManager()
{
  return &hkpVehicleManager::`vftable;
}

// File Line: 97
// RVA: 0x15D5B00
void **dynamic_initializer_for__hkpVehicleManagerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleManager();
  hkpVehicleManagerTypeInfo.m_size = 32i64;
  hkpVehicleManagerTypeInfo.m_typeName = "hkpVehicleManager";
  hkpVehicleManagerTypeInfo.m_vtable = result;
  hkpVehicleManagerTypeInfo.m_scopedName = "!hkpVehicleManager";
  hkpVehicleManagerTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpVehicleManager;
  hkpVehicleManagerTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpVehicleManager;
  return result;
}

