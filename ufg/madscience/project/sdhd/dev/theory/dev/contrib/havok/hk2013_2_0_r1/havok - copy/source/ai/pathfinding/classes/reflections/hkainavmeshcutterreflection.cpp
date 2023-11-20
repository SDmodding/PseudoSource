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
    1u);
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
void __fastcall cleanupLoadedObjecthkaiNavMeshCutterSavedConnectivity(void *p)
{
  hkaiNavMeshCutter::SavedConnectivity::~SavedConnectivity((hkaiNavMeshCutter::SavedConnectivity *)p);
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
void __fastcall cleanupLoadedObjecthkaiNavMeshCutterMeshInfo(void *p)
{
  int v1; // er8
  _QWORD *v2; // rbx

  v1 = *((_DWORD *)p + 7);
  v2 = p;
  *((_DWORD *)p + 6) = 0;
  if ( v1 < 0 )
  {
    *((_QWORD *)p + 2) = 0i64;
    *((_DWORD *)p + 7) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)*((_QWORD *)p + 2),
      4 * v1);
    v2[2] = 0i64;
    *((_DWORD *)v2 + 7) = 2147483648;
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
    0xDu);
}

// File Line: 324
// RVA: 0xBB6A40
hkClass *__fastcall hkaiNavMeshCutter::staticClass()
{
  return &hkaiNavMeshCutterClass;
}

// File Line: 331
// RVA: 0xBB6B30
void __fastcall finishLoadedObjecthkaiNavMeshCutter(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiNavMeshCutter::hkaiNavMeshCutter);
}

// File Line: 337
// RVA: 0xBB6B50
void __fastcall cleanupLoadedObjecthkaiNavMeshCutter(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 341
// RVA: 0xBB6B60
hkBaseObjectVtbl *__fastcall getVtablehkaiNavMeshCutter()
{
  hkaiNavMeshCutter v1; // [rsp+20h] [rbp-C8h]

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
  hkaiNavMeshCutterTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiNavMeshCutter;
  hkaiNavMeshCutterTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiNavMeshCutter;
  return result;
}

