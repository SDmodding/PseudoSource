// File Line: 55
// RVA: 0x15C3E90
void dynamic_initializer_for__hkaiSplitGenerationSnapshotClass__()
{
  hkClass::hkClass(
    &hkaiSplitGenerationSnapshotClass,
    "hkaiSplitGenerationSnapshot",
    0i64,
    608,
    0i64,
    0,
    0i64,
    0,
    &hkaiSplitGenerationSnapshot::Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xBB80B0
hkClass *__fastcall hkaiSplitGenerationSnapshot::staticClass()
{
  return &hkaiSplitGenerationSnapshotClass;
}

// File Line: 65
// RVA: 0xBB80C0
void __fastcall finishLoadedObjecthkaiSplitGenerationSnapshot(void *p, int finishing)
{
  int v2; // edi
  char *v3; // rbx

  if ( p )
  {
    v2 = finishing;
    v3 = (char *)p;
    hkGeometry::hkGeometry((hkGeometry *)p, (hkFinishLoadedObjectFlag)finishing);
    hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(
      (hkaiNavMeshGenerationSettings *)(v3 + 48),
      (hkFinishLoadedObjectFlag)v2);
    hkStringPtr::hkStringPtr((hkStringPtr *)v3 + 74);
  }
}

// File Line: 71
// RVA: 0xBB8110
void __fastcall cleanupLoadedObjecthkaiSplitGenerationSnapshot(void *p)
{
  hkaiNavMeshGenerationSnapshot *v1; // rbx

  v1 = (hkaiNavMeshGenerationSnapshot *)p;
  hkStringPtr::~hkStringPtr((hkStringPtr *)p + 74);
  hkaiNavMeshGenerationSnapshot::~hkaiNavMeshGenerationSnapshot(v1);
}

