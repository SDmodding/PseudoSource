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
    1);
}

// File Line: 58
// RVA: 0xBB7EC0
hkClass *__fastcall hkaiNavVolumeGenerationSnapshot::staticClass()
{
  return &hkaiNavVolumeGenerationSnapshotClass;
}

// File Line: 65
// RVA: 0xBB7ED0
void __fastcall finishLoadedObjecthkaiNavVolumeGenerationSnapshot(char *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
  {
    hkGeometry::hkGeometry((hkGeometry *)p, finishing);
    hkaiNavVolumeGenerationSettings::hkaiNavVolumeGenerationSettings(
      (hkaiNavVolumeGenerationSettings *)(p + 48),
      finishing);
  }
}

// File Line: 71
// RVA: 0xBB7F10
void __fastcall cleanupLoadedObjecthkaiNavVolumeGenerationSnapshot(char *p)
{
  hkaiNavVolumeGenerationSettings::~hkaiNavVolumeGenerationSettings((hkaiNavVolumeGenerationSettings *)(p + 48));
  hkGeometry::~hkGeometry((hkGeometry *)p);
}

