// File Line: 53
// RVA: 0x15D5C90
void dynamic_initializer_for__hkpVehicleRayCastBatchingManagerClass__()
{
  hkClass::hkClass(
    &hkpVehicleRayCastBatchingManagerClass,
    "hkpVehicleRayCastBatchingManager",
    &hkpVehicleCastBatchingManagerClass,
    40,
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

// File Line: 56
// RVA: 0xE25DB0
hkClass *__fastcall hkpVehicleRayCastBatchingManager::staticClass()
{
  return &hkpVehicleRayCastBatchingManagerClass;
}

// File Line: 63
// RVA: 0xE25DC0
void __fastcall finishLoadedObjecthkpVehicleRayCastBatchingManager(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpVehicleRayCastBatchingManager::`vftable';
}

// File Line: 69
// RVA: 0xE25DE0
void __fastcall cleanupLoadedObjecthkpVehicleRayCastBatchingManager(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 73
// RVA: 0xE25DF0
void **__fastcall getVtablehkpVehicleRayCastBatchingManager()
{
  return &hkpVehicleRayCastBatchingManager::`vftable';
}

// File Line: 95
// RVA: 0x15D5CF0
void **dynamic_initializer_for__hkpVehicleRayCastBatchingManagerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleRayCastBatchingManager();
  hkpVehicleRayCastBatchingManagerTypeInfo.m_size = 40i64;
  hkpVehicleRayCastBatchingManagerTypeInfo.m_typeName = "hkpVehicleRayCastBatchingManager";
  hkpVehicleRayCastBatchingManagerTypeInfo.m_vtable = result;
  hkpVehicleRayCastBatchingManagerTypeInfo.m_scopedName = "!hkpVehicleRayCastBatchingManager";
  hkpVehicleRayCastBatchingManagerTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpVehicleRayCastBatchingManager;
  hkpVehicleRayCastBatchingManagerTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpVehicleRayCastBatchingManager;
  return result;
}

