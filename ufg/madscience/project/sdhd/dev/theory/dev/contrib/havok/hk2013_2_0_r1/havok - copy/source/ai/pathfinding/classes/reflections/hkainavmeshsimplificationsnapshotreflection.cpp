// File Line: 61
// RVA: 0x15C3A50
void dynamic_initializer_for__hkaiNavMeshSimplificationSnapshotClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshSimplificationSnapshotClass,
    "hkaiNavMeshSimplificationSnapshot",
    0i64,
    560,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMeshSimplificationSnapshotClass_Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 64
// RVA: 0xBB7E80
hkClass *__fastcall hkaiNavMeshSimplificationSnapshot::staticClass()
{
  return &hkaiNavMeshSimplificationSnapshotClass;
}

// File Line: 71
// RVA: 0xBB7E90
void __fastcall finishLoadedObjecthkaiNavMeshSimplificationSnapshot(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiNavMeshSimplificationSnapshot::hkaiNavMeshSimplificationSnapshot);
}

// File Line: 77
// RVA: 0xBB7EB0
void __fastcall cleanupLoadedObjecthkaiNavMeshSimplificationSnapshot(void *p)
{
  hkaiNavMeshSimplificationSnapshot::~hkaiNavMeshSimplificationSnapshot((hkaiNavMeshSimplificationSnapshot *)p);
}

