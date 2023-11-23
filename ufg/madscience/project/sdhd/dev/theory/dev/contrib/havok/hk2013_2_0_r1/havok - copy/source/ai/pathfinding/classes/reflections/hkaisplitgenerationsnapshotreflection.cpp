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
void __fastcall finishLoadedObjecthkaiSplitGenerationSnapshot(char *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
  {
    hkGeometry::hkGeometry((hkGeometry *)p, finishing);
    hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings((hkaiNavMeshGenerationSettings *)(p + 48), finishing);
    hkStringPtr::hkStringPtr((hkStringPtr *)p + 74);
  }
}

// File Line: 71
// RVA: 0xBB8110
void __fastcall cleanupLoadedObjecthkaiSplitGenerationSnapshot(hkStringPtr *p)
{
  hkStringPtr::~hkStringPtr(p + 74);
  hkaiNavMeshGenerationSnapshot::~hkaiNavMeshGenerationSnapshot((hkaiNavMeshGenerationSnapshot *)p);
}

