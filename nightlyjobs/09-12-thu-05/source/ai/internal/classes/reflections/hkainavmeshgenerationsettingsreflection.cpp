// File Line: 99
// RVA: 0x15BFA40
hkClassEnum *dynamic_initializer_for__hkaiNavMeshGenerationSettings_MaterialConstructionPairClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiNavMeshGenerationSettingsConstructionFlagsBitsEnum;
  unk_142101CB8 = hkaiNavMeshGenerationSettingsConstructionFlagsBitsEnum;
  return result;
}

// File Line: 115
// RVA: 0x15BF890
void dynamic_initializer_for__hkaiNavMeshGenerationSettingsMaterialConstructionPairClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshGenerationSettingsMaterialConstructionPairClass,
    "hkaiNavMeshGenerationSettingsMaterialConstructionPair",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMeshGenerationSettings_MaterialConstructionPairClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 118
// RVA: 0xB47950
hkClass *__fastcall hkaiNavMeshGenerationSettings::MaterialConstructionPair::staticClass()
{
  return &hkaiNavMeshGenerationSettingsMaterialConstructionPairClass;
}

// File Line: 125
// RVA: 0xB47990
void __fastcall cleanupLoadedObjecthkaiNavMeshGenerationSettingsMaterialConstructionPair(void *p)
{
  ;
}

// File Line: 146
// RVA: 0x15BFA50
hkClassEnum *dynamic_initializer_for__hkaiNavMeshGenerationSettings_OverrideSettingsClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiNavMeshGenerationSettingsCharacterWidthUsageEnum;
  unk_142101D60 = hkaiNavMeshGenerationSettingsCharacterWidthUsageEnum;
  return result;
}

// File Line: 186
// RVA: 0x15BF8F0
void dynamic_initializer_for__hkaiNavMeshGenerationSettingsOverrideSettingsClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshGenerationSettingsOverrideSettingsClass,
    "hkaiNavMeshGenerationSettingsOverrideSettings",
    0i64,
    240,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMeshGenerationSettings_OverrideSettingsClass_Members,
    6,
    &hkaiNavMeshGenerationSettingsOverrideSettings_Default,
    0i64,
    0,
    3);
}

// File Line: 189
// RVA: 0xB47960
hkClass *__fastcall hkaiNavMeshGenerationSettings::OverrideSettings::staticClass()
{
  return &hkaiNavMeshGenerationSettingsOverrideSettingsClass;
}

// File Line: 196
// RVA: 0xB479A0
void __fastcall finishLoadedObjecthkaiNavMeshGenerationSettingsOverrideSettings(
        hkaiNavMeshGenerationSettings::OverrideSettings *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiNavMeshGenerationSettings::OverrideSettings::OverrideSettings(p, finishing);
}

// File Line: 202
// RVA: 0xB479C0
// attributes: thunk
void __fastcall cleanupLoadedObjecthkaiNavMeshGenerationSettingsOverrideSettings(
        hkaiNavMeshGenerationSettings::OverrideSettings *p)
{
  hkaiNavMeshGenerationSettings::OverrideSettings::~OverrideSettings(p);
}

// File Line: 280
// RVA: 0x15BF960
void dynamic_initializer_for__hkaiNavMeshGenerationSettingsRegionPruningSettingsClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshGenerationSettingsRegionPruningSettingsClass,
    "hkaiNavMeshGenerationSettingsRegionPruningSettings",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMeshGenerationSettings_RegionPruningSettingsClass_Members,
    6,
    &hkaiNavMeshGenerationSettingsRegionPruningSettings_Default,
    0i64,
    0,
    2);
}

// File Line: 283
// RVA: 0xB47970
hkClass *__fastcall hkaiNavMeshGenerationSettings::RegionPruningSettings::staticClass()
{
  return &hkaiNavMeshGenerationSettingsRegionPruningSettingsClass;
}

// File Line: 290
// RVA: 0xB479D0
void __fastcall finishLoadedObjecthkaiNavMeshGenerationSettingsRegionPruningSettings(void *p, int finishing)
{
  ;
}

// File Line: 296
// RVA: 0xB479E0
void __fastcall cleanupLoadedObjecthkaiNavMeshGenerationSettingsRegionPruningSettings(_DWORD *p)
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
      16 * v1);
    *((_QWORD *)p + 2) = 0i64;
    p[7] = 0x80000000;
  }
}

// File Line: 352
// RVA: 0x15BF9D0
void dynamic_initializer_for__hkaiNavMeshGenerationSettingsWallClimbingSettingsClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshGenerationSettingsWallClimbingSettingsClass,
    "hkaiNavMeshGenerationSettingsWallClimbingSettings",
    0i64,
    2,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMeshGenerationSettings_WallClimbingSettingsClass_Members,
    2,
    &hkaiNavMeshGenerationSettingsWallClimbingSettings_Default,
    0i64,
    0,
    1);
}

// File Line: 355
// RVA: 0xB47980
hkClass *__fastcall hkaiNavMeshGenerationSettings::WallClimbingSettings::staticClass()
{
  return &hkaiNavMeshGenerationSettingsWallClimbingSettingsClass;
}

// File Line: 362
// RVA: 0xB47A50
void __fastcall finishLoadedObjecthkaiNavMeshGenerationSettingsWallClimbingSettings(void *p, int finishing)
{
  ;
}

// File Line: 368
// RVA: 0xB47A60
void __fastcall cleanupLoadedObjecthkaiNavMeshGenerationSettingsWallClimbingSettings(void *p)
{
  ;
}

// File Line: 433
// RVA: 0x15BF850
hkClassEnum *dynamic_initializer_for__hkaiNavMeshGenerationSettingsClass_Members__()
{
  hkClassEnum *result; // rax

  unk_142101FA0 = hkaiNavMeshGenerationSettingsTriangleWindingEnum;
  unk_142102090 = hkaiNavMeshGenerationSettingsEdgeMatchingMetricEnum;
  unk_1421021D0 = hkaiNavMeshGenerationSettingsConstructionFlagsBitsEnum;
  result = hkaiNavMeshGenerationSettingsCharacterWidthUsageEnum;
  unk_142102298 = hkaiNavMeshGenerationSettingsCharacterWidthUsageEnum;
  return result;
}

// File Line: 507
// RVA: 0x15BF7D0
void dynamic_initializer_for__hkaiNavMeshGenerationSettingsClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshGenerationSettingsClass,
    "hkaiNavMeshGenerationSettings",
    0i64,
    496,
    0i64,
    0,
    &hkaiNavMeshGenerationSettingsEnums,
    4,
    &hkaiNavMeshGenerationSettingsClass_Members,
    33,
    &hkaiNavMeshGenerationSettings_Default,
    0i64,
    0,
    25);
}

// File Line: 510
// RVA: 0xB47940
hkClass *__fastcall hkaiNavMeshGenerationSettings::staticClass()
{
  return &hkaiNavMeshGenerationSettingsClass;
}

// File Line: 517
// RVA: 0xB47A70
void __fastcall finishLoadedObjecthkaiNavMeshGenerationSettings(
        hkaiNavMeshGenerationSettings *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(p, finishing);
}

// File Line: 523
// RVA: 0xB47A90
// attributes: thunk
void __fastcall cleanupLoadedObjecthkaiNavMeshGenerationSettings(hkaiNavMeshGenerationSettings *p)
{
  hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings(p);
}

