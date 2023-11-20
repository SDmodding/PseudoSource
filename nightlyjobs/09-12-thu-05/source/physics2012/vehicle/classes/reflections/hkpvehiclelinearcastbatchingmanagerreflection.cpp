// File Line: 54
// RVA: 0x15D58A0
void dynamic_initializer_for__hkpVehicleLinearCastBatchingManagerClass__()
{
  hkClass::hkClass(
    &hkpVehicleLinearCastBatchingManagerClass,
    "hkpVehicleLinearCastBatchingManager",
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

// File Line: 57
// RVA: 0xE25A60
hkClass *__fastcall hkpVehicleLinearCastBatchingManager::staticClass()
{
  return &hkpVehicleLinearCastBatchingManagerClass;
}

// File Line: 64
// RVA: 0xE25A70
void __fastcall finishLoadedObjecthkpVehicleLinearCastBatchingManager(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpVehicleLinearCastBatchingManager::`vftable;
}

// File Line: 70
// RVA: 0xE25A90
void __fastcall cleanupLoadedObjecthkpVehicleLinearCastBatchingManager(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 74
// RVA: 0xE25AA0
void **__fastcall getVtablehkpVehicleLinearCastBatchingManager()
{
  return &hkpVehicleLinearCastBatchingManager::`vftable;
}

// File Line: 96
// RVA: 0x15D5900
void **dynamic_initializer_for__hkpVehicleLinearCastBatchingManagerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpVehicleLinearCastBatchingManager();
  hkpVehicleLinearCastBatchingManagerTypeInfo.m_size = 40i64;
  hkpVehicleLinearCastBatchingManagerTypeInfo.m_typeName = "hkpVehicleLinearCastBatchingManager";
  hkpVehicleLinearCastBatchingManagerTypeInfo.m_vtable = result;
  hkpVehicleLinearCastBatchingManagerTypeInfo.m_scopedName = "!hkpVehicleLinearCastBatchingManager";
  hkpVehicleLinearCastBatchingManagerTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpVehicleLinearCastBatchingManager;
  hkpVehicleLinearCastBatchingManagerTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpVehicleLinearCastBatchingManager;
  return result;
}

