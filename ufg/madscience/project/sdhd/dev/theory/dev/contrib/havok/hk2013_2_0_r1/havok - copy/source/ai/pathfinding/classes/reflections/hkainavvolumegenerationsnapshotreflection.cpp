// File Line: 55
// RVA: 0x15C3AB0
void dynamic_initializer_for__hkaiNavVolumeGenerationSnapshotClass__()
{
  hkClass::hkClass(
    &hkaiNavVolumeGenerationSnapshotClass,
    "hkaiNavVolumeGenerationSnapshot",
    0i64,
    304,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavVolumeGenerationSnapshot::Members,
    2,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 58
// RVA: 0xBB7EC0
hkClass *__fastcall hkaiNavVolumeGenerationSnapshot::staticClass()
{
  return &hkaiNavVolumeGenerationSnapshotClass;
}

// File Line: 65
// RVA: 0xBB7ED0
void __fastcall finishLoadedObjecthkaiNavVolumeGenerationSnapshot(void *p, int finishing)
{
  int v2; // edi
  char *v3; // rbx

  if ( p )
  {
    v2 = finishing;
    v3 = (char *)p;
    hkGeometry::hkGeometry((hkGeometry *)p, (hkFinishLoadedObjectFlag)finishing);
    hkaiNavVolumeGenerationSettings::hkaiNavVolumeGenerationSettings(
      (hkaiNavVolumeGenerationSettings *)(v3 + 48),
      (hkFinishLoadedObjectFlag)v2);
  }
}

// File Line: 71
// RVA: 0xBB7F10
void __fastcall cleanupLoadedObjecthkaiNavVolumeGenerationSnapshot(void *p)
{
  hkGeometry *v1; // rbx

  v1 = (hkGeometry *)p;
  hkaiNavVolumeGenerationSettings::~hkaiNavVolumeGenerationSettings((hkaiNavVolumeGenerationSettings *)((char *)p + 48));
  hkGeometry::~hkGeometry(v1);
}

