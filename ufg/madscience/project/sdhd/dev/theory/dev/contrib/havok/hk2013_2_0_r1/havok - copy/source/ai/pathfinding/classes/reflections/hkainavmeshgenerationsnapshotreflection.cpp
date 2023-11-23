// File Line: 55
// RVA: 0x15C3930
void dynamic_initializer_for__hkaiNavMeshGenerationSnapshotClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshGenerationSnapshotClass,
    "hkaiNavMeshGenerationSnapshot",
    0i64,
    544,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMeshGenerationSnapshot::Members,
    2,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 58
// RVA: 0xBB7DF0
hkClass *__fastcall hkaiNavMeshGenerationSnapshot::staticClass()
{
  return &hkaiNavMeshGenerationSnapshotClass;
}

// File Line: 65
// RVA: 0xBB7E00
void __fastcall finishLoadedObjecthkaiNavMeshGenerationSnapshot(char *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
  {
    hkGeometry::hkGeometry((hkGeometry *)p, finishing);
    hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings((hkaiNavMeshGenerationSettings *)(p + 48), finishing);
  }
}

// File Line: 71
// RVA: 0xBB7E40
// attributes: thunk
void __fastcall cleanupLoadedObjecthkaiNavMeshGenerationSnapshot(hkaiNavMeshGenerationSnapshot *p)
{
  hkaiNavMeshGenerationSnapshot::~hkaiNavMeshGenerationSnapshot(p);
}

