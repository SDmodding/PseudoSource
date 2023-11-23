// File Line: 57
// RVA: 0x15C1240
void dynamic_initializer_for__hkaiDynamicNavVolumeMediatorClass__()
{
  hkClass::hkClass(
    &hkaiDynamicNavVolumeMediatorClass,
    "hkaiDynamicNavVolumeMediator",
    &hkaiNavVolumeMediatorClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiDynamicNavVolumeMediatorClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 60
// RVA: 0xBB6730
hkClass *__fastcall hkaiDynamicNavVolumeMediator::staticClass()
{
  return &hkaiDynamicNavVolumeMediatorClass;
}

// File Line: 67
// RVA: 0xBB6740
void __fastcall finishLoadedObjecthkaiDynamicNavVolumeMediator(
        hkaiDynamicNavVolumeMediator *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiDynamicNavVolumeMediator::hkaiDynamicNavVolumeMediator(p, finishing);
}

// File Line: 73
// RVA: 0xBB6760
void __fastcall cleanupLoadedObjecthkaiDynamicNavVolumeMediator(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 77
// RVA: 0xBB6770
hkBaseObjectVtbl *__fastcall getVtablehkaiDynamicNavVolumeMediator()
{
  hkaiDynamicNavVolumeMediator v1; // [rsp+20h] [rbp-28h] BYREF

  hkaiDynamicNavVolumeMediator::hkaiDynamicNavVolumeMediator(&v1, 0);
  return v1.vfptr;
}

// File Line: 99
// RVA: 0x15C12B0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiDynamicNavVolumeMediatorTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiDynamicNavVolumeMediator();
  hkaiDynamicNavVolumeMediatorTypeInfo.m_size = 32i64;
  hkaiDynamicNavVolumeMediatorTypeInfo.m_typeName = "hkaiDynamicNavVolumeMediator";
  hkaiDynamicNavVolumeMediatorTypeInfo.m_vtable = result;
  hkaiDynamicNavVolumeMediatorTypeInfo.m_scopedName = "!hkaiDynamicNavVolumeMediator";
  hkaiDynamicNavVolumeMediatorTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiDynamicNavVolumeMediator;
  hkaiDynamicNavVolumeMediatorTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiDynamicNavVolumeMediator;
  return result;
}

