// File Line: 58
// RVA: 0x15C40C0
void dynamic_initializer_for__hkaiMoppNavMeshQueryMediatorClass__()
{
  hkClass::hkClass(
    &hkaiMoppNavMeshQueryMediatorClass,
    "hkaiMoppNavMeshQueryMediator",
    &hkaiNavMeshQueryMediatorClass,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkaiMoppNavMeshQueryMediator::Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 61
// RVA: 0xC2E300
hkClass *__fastcall hkaiMoppNavMeshQueryMediator::staticClass()
{
  return &hkaiMoppNavMeshQueryMediatorClass;
}

// File Line: 68
// RVA: 0xC2E310
void __fastcall finishLoadedObjecthkaiMoppNavMeshQueryMediator(
        hkaiMoppNavMeshQueryMediator *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiMoppNavMeshQueryMediator::hkaiMoppNavMeshQueryMediator(p, finishing);
}

// File Line: 74
// RVA: 0xC2E330
void __fastcall cleanupLoadedObjecthkaiMoppNavMeshQueryMediator(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 78
// RVA: 0xC2E340
hkBaseObjectVtbl *__fastcall getVtablehkaiMoppNavMeshQueryMediator()
{
  hkaiMoppNavMeshQueryMediator v1; // [rsp+20h] [rbp-48h] BYREF

  hkaiMoppNavMeshQueryMediator::hkaiMoppNavMeshQueryMediator(&v1, 0);
  return v1.vfptr;
}

// File Line: 100
// RVA: 0x15C4130
hkBaseObjectVtbl *dynamic_initializer_for__hkaiMoppNavMeshQueryMediatorTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiMoppNavMeshQueryMediator();
  hkaiMoppNavMeshQueryMediatorTypeInfo.m_size = 64i64;
  hkaiMoppNavMeshQueryMediatorTypeInfo.m_typeName = "hkaiMoppNavMeshQueryMediator";
  hkaiMoppNavMeshQueryMediatorTypeInfo.m_vtable = result;
  hkaiMoppNavMeshQueryMediatorTypeInfo.m_scopedName = "!hkaiMoppNavMeshQueryMediator";
  hkaiMoppNavMeshQueryMediatorTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiMoppNavMeshQueryMediator;
  hkaiMoppNavMeshQueryMediatorTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiMoppNavMeshQueryMediator;
  return result;
}

