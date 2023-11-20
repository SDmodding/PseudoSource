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
    1u);
}

// File Line: 58
// RVA: 0xBB7DF0
hkClass *__fastcall hkaiNavMeshGenerationSnapshot::staticClass()
{
  return &hkaiNavMeshGenerationSnapshotClass;
}

// File Line: 65
// RVA: 0xBB7E00
void __fastcall finishLoadedObjecthkaiNavMeshGenerationSnapshot(void *p, int finishing)
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
  }
}

// File Line: 71
// RVA: 0xBB7E40
void __fastcall cleanupLoadedObjecthkaiNavMeshGenerationSnapshot(void *p)
{
  hkaiNavMeshGenerationSnapshot::~hkaiNavMeshGenerationSnapshot((hkaiNavMeshGenerationSnapshot *)p);
}

