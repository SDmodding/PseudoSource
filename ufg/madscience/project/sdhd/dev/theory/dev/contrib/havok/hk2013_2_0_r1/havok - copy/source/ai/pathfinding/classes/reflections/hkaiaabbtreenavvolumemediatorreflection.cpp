// File Line: 57
// RVA: 0x15C0220
void dynamic_initializer_for__hkaiAabbTreeNavVolumeMediatorClass__()
{
  hkClass::hkClass(
    &hkaiAabbTreeNavVolumeMediatorClass,
    "hkaiAabbTreeNavVolumeMediator",
    &hkaiNavVolumeMediatorClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiAabbTreeNavVolumeMediator::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 60
// RVA: 0xBB5E80
hkClass *__fastcall hkaiAabbTreeNavVolumeMediator::staticClass()
{
  return &hkaiAabbTreeNavVolumeMediatorClass;
}

// File Line: 67
// RVA: 0xBB5E90
void __fastcall finishLoadedObjecthkaiAabbTreeNavVolumeMediator(
        hkaiAabbTreeNavVolumeMediator *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiAabbTreeNavVolumeMediator::hkaiAabbTreeNavVolumeMediator(p, finishing);
}

// File Line: 73
// RVA: 0xBB5EB0
void __fastcall cleanupLoadedObjecthkaiAabbTreeNavVolumeMediator(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 77
// RVA: 0xBB5EC0
hkBaseObjectVtbl *__fastcall getVtablehkaiAabbTreeNavVolumeMediator()
{
  hkaiAabbTreeNavVolumeMediator v1; // [rsp+20h] [rbp-28h] BYREF

  hkaiAabbTreeNavVolumeMediator::hkaiAabbTreeNavVolumeMediator(&v1, 0);
  return v1.vfptr;
}

// File Line: 99
// RVA: 0x15C0290
hkBaseObjectVtbl *dynamic_initializer_for__hkaiAabbTreeNavVolumeMediatorTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiAabbTreeNavVolumeMediator();
  hkaiAabbTreeNavVolumeMediatorTypeInfo.m_size = 32i64;
  hkaiAabbTreeNavVolumeMediatorTypeInfo.m_typeName = "hkaiAabbTreeNavVolumeMediator";
  hkaiAabbTreeNavVolumeMediatorTypeInfo.m_vtable = result;
  hkaiAabbTreeNavVolumeMediatorTypeInfo.m_scopedName = "!hkaiAabbTreeNavVolumeMediator";
  hkaiAabbTreeNavVolumeMediatorTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiAabbTreeNavVolumeMediator;
  hkaiAabbTreeNavVolumeMediatorTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiAabbTreeNavVolumeMediator;
  return result;
}

