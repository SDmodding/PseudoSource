// File Line: 81
// RVA: 0x15C1170
void dynamic_initializer_for__hkaiDynamicNavMeshQueryMediatorClass__()
{
  hkClass::hkClass(
    &hkaiDynamicNavMeshQueryMediatorClass,
    "hkaiDynamicNavMeshQueryMediator",
    &hkaiNavMeshQueryMediatorClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkaiDynamicNavMeshQueryMediatorClass_Members,
    4,
    &hkaiDynamicNavMeshQueryMediator_Default,
    0i64,
    0,
    4);
}

// File Line: 84
// RVA: 0xBB66D0
hkClass *__fastcall hkaiDynamicNavMeshQueryMediator::staticClass()
{
  return &hkaiDynamicNavMeshQueryMediatorClass;
}

// File Line: 91
// RVA: 0xBB66E0
void __fastcall finishLoadedObjecthkaiDynamicNavMeshQueryMediator(
        hkaiDynamicNavMeshQueryMediator *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiDynamicNavMeshQueryMediator::hkaiDynamicNavMeshQueryMediator(p, finishing);
}

// File Line: 97
// RVA: 0xBB6700
void __fastcall cleanupLoadedObjecthkaiDynamicNavMeshQueryMediator(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 101
// RVA: 0xBB6710
hkBaseObjectVtbl *__fastcall getVtablehkaiDynamicNavMeshQueryMediator()
{
  hkaiDynamicNavMeshQueryMediator v1; // [rsp+20h] [rbp-38h] BYREF

  hkaiDynamicNavMeshQueryMediator::hkaiDynamicNavMeshQueryMediator(&v1, 0);
  return v1.vfptr;
}

// File Line: 123
// RVA: 0x15C11E0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiDynamicNavMeshQueryMediatorTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiDynamicNavMeshQueryMediator();
  hkaiDynamicNavMeshQueryMediatorTypeInfo.m_size = 48i64;
  hkaiDynamicNavMeshQueryMediatorTypeInfo.m_typeName = "hkaiDynamicNavMeshQueryMediator";
  hkaiDynamicNavMeshQueryMediatorTypeInfo.m_vtable = result;
  hkaiDynamicNavMeshQueryMediatorTypeInfo.m_scopedName = "!hkaiDynamicNavMeshQueryMediator";
  hkaiDynamicNavMeshQueryMediatorTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiDynamicNavMeshQueryMediator;
  hkaiDynamicNavMeshQueryMediatorTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiDynamicNavMeshQueryMediator;
  return result;
}

