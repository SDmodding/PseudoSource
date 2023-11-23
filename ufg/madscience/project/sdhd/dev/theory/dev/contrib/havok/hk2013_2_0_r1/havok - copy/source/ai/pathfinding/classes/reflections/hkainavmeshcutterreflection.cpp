// File Line: 59
// RVA: 0x15C1A70
void dynamic_initializer_for__hkaiPersistentFaceKeyClass__()
{
  hkClass::hkClass(
    &hkaiPersistentFaceKeyClass,
    "hkaiPersistentFaceKey",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkaiPersistentFaceKeyClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 62
// RVA: 0xBB6A20
hkClass *__fastcall hkaiPersistentFaceKey::staticClass()
{
  return &hkaiPersistentFaceKeyClass;
}

// File Line: 69
// RVA: 0xBB6A70
void __fastcall cleanupLoadedObjecthkaiPersistentFaceKey(void *p)
{
  ;
}

// File Line: 106
// RVA: 0x15C1A10
void dynamic_initializer_for__hkaiPersistentEdgeKeyClass__()
{
  hkClass::hkClass(
    &hkaiPersistentEdgeKeyClass,
    "hkaiPersistentEdgeKey",
    0i64,
    12,
    0i64,
    0,
    0i64,
    0,
    &hkaiPersistentEdgeKeyClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 109
// RVA: 0xBB6A30
hkClass *__fastcall hkaiPersistentEdgeKey::staticClass()
{
  return &hkaiPersistentEdgeKeyClass;
}

// File Line: 116
// RVA: 0xBB6A80
void __fastcall cleanupLoadedObjecthkaiPersistentEdgeKey(void *p)
{
  ;
}

// File Line: 176
// RVA: 0x15C1940
void dynamic_initializer_for__hkaiNavMeshCutterSavedConnectivityClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshCutterSavedConnectivityClass,
    "hkaiNavMeshCutterSavedConnectivity",
    0i64,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMeshCutter_SavedConnectivityClass_Members,
    1,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 179
// RVA: 0xBB6A50
hkClass *__fastcall hkaiNavMeshCutter::SavedConnectivity::staticClass()
{
  return &hkaiNavMeshCutterSavedConnectivityClass;
}

// File Line: 186
// RVA: 0xBB6A90
void __fastcall finishLoadedObjecthkaiNavMeshCutterSavedConnectivity(void *p, int finishing)
{
  ;
}

// File Line: 192
// RVA: 0xBB6AA0
// attributes: thunk
void __fastcall cleanupLoadedObjecthkaiNavMeshCutterSavedConnectivity(hkaiNavMeshCutter::SavedConnectivity *p)
{
  hkaiNavMeshCutter::SavedConnectivity::~SavedConnectivity(p);
}

// File Line: 230
// RVA: 0x15C18E0
void dynamic_initializer_for__hkaiNavMeshCutterMeshInfoClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshCutterMeshInfoClass,
    "hkaiNavMeshCutterMeshInfo",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMeshCutter_MeshInfoClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 233
// RVA: 0xBB6A60
hkClass *__fastcall hkaiNavMeshCutter::MeshInfo::staticClass()
{
  return &hkaiNavMeshCutterMeshInfoClass;
}

// File Line: 240
// RVA: 0xBB6AB0
void __fastcall finishLoadedObjecthkaiNavMeshCutterMeshInfo(void *p, int finishing)
{
  ;
}

// File Line: 246
// RVA: 0xBB6AC0
void __fastcall cleanupLoadedObjecthkaiNavMeshCutterMeshInfo(_DWORD *p)
{
  int v1; // r8d

  v1 = p[7];
  p[6] = 0;
  if ( v1 < 0 )
  {
    *((_QWORD *)p + 2) = 0i64;
    p[7] = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      (void *)*((_QWORD *)p + 2),
      4 * v1);
    *((_QWORD *)p + 2) = 0i64;
    p[7] = 0x80000000;
  }
}

// File Line: 277
// RVA: 0x15C1850
hkClassEnum *dynamic_initializer_for__hkaiNavMeshCutter::Members__()
{
  hkClassEnum *result; // rax

  result = hkaiNavMeshCutterClearanceResetMethodEnum;
  unk_142104CA0 = hkaiNavMeshCutterClearanceResetMethodEnum;
  return result;
}

// File Line: 321
// RVA: 0x15C1860
void dynamic_initializer_for__hkaiNavMeshCutterClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshCutterClass,
    "hkaiNavMeshCutter",
    &hkReferencedObjectClass,
    192,
    0i64,
    0,
    &hkaiNavMeshCutterEnums,
    2,
    &hkaiNavMeshCutter::Members,
    13,
    &hkaiNavMeshCutter_Default,
    0i64,
    0,
    13);
}

// File Line: 324
// RVA: 0xBB6A40
hkClass *__fastcall hkaiNavMeshCutter::staticClass()
{
  return &hkaiNavMeshCutterClass;
}

// File Line: 331
// RVA: 0xBB6B30
void __fastcall finishLoadedObjecthkaiNavMeshCutter(hkaiNavMeshCutter *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiNavMeshCutter::hkaiNavMeshCutter(p, finishing);
}

// File Line: 337
// RVA: 0xBB6B50
void __fastcall cleanupLoadedObjecthkaiNavMeshCutter(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 341
// RVA: 0xBB6B60
hkBaseObjectVtbl *__fastcall getVtablehkaiNavMeshCutter()
{
  hkaiNavMeshCutter v1; // [rsp+20h] [rbp-C8h] BYREF

  hkaiNavMeshCutter::hkaiNavMeshCutter(&v1, 0);
  return v1.vfptr;
}

// File Line: 363
// RVA: 0x15C19B0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiNavMeshCutterTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiNavMeshCutter();
  hkaiNavMeshCutterTypeInfo.m_size = 192i64;
  hkaiNavMeshCutterTypeInfo.m_typeName = "hkaiNavMeshCutter";
  hkaiNavMeshCutterTypeInfo.m_vtable = result;
  hkaiNavMeshCutterTypeInfo.m_scopedName = "!hkaiNavMeshCutter";
  hkaiNavMeshCutterTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiNavMeshCutter;
  hkaiNavMeshCutterTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiNavMeshCutter;
  return result;
}

