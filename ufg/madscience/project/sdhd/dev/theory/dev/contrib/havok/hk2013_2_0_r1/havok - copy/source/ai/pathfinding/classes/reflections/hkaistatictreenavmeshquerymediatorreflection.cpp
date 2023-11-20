// File Line: 57
// RVA: 0x15C2C40
void dynamic_initializer_for__hkaiStaticTreeNavMeshQueryMediatorClass__()
{
  hkClass::hkClass(
    &hkaiStaticTreeNavMeshQueryMediatorClass,
    "hkaiStaticTreeNavMeshQueryMediator",
    &hkaiNavMeshQueryMediatorClass,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiStaticTreeNavMeshQueryMediator::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 60
// RVA: 0xBB7740
hkClass *__fastcall hkaiStaticTreeNavMeshQueryMediator::staticClass()
{
  return &hkaiStaticTreeNavMeshQueryMediatorClass;
}

// File Line: 67
// RVA: 0xBB7750
void __fastcall finishLoadedObjecthkaiStaticTreeNavMeshQueryMediator(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiStaticTreeNavMeshQueryMediator::hkaiStaticTreeNavMeshQueryMediator);
}

// File Line: 73
// RVA: 0xBB7770
void __fastcall cleanupLoadedObjecthkaiStaticTreeNavMeshQueryMediator(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 77
// RVA: 0xBB7780
hkBaseObjectVtbl *__fastcall getVtablehkaiStaticTreeNavMeshQueryMediator()
{
  hkaiStaticTreeNavMeshQueryMediator v1; // [rsp+20h] [rbp-28h]

  hkaiStaticTreeNavMeshQueryMediator::hkaiStaticTreeNavMeshQueryMediator(&v1, 0);
  return v1.vfptr;
}

// File Line: 99
// RVA: 0x15C2CB0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiStaticTreeNavMeshQueryMediatorTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiStaticTreeNavMeshQueryMediator();
  hkaiStaticTreeNavMeshQueryMediatorTypeInfo.m_size = 32i64;
  hkaiStaticTreeNavMeshQueryMediatorTypeInfo.m_typeName = "hkaiStaticTreeNavMeshQueryMediator";
  hkaiStaticTreeNavMeshQueryMediatorTypeInfo.m_vtable = result;
  hkaiStaticTreeNavMeshQueryMediatorTypeInfo.m_scopedName = "!hkaiStaticTreeNavMeshQueryMediator";
  hkaiStaticTreeNavMeshQueryMediatorTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiStaticTreeNavMeshQueryMediator;
  hkaiStaticTreeNavMeshQueryMediatorTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiStaticTreeNavMeshQueryMediator;
  return result;
}

