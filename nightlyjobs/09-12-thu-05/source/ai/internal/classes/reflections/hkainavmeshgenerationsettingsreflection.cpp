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
    3u);
}

// File Line: 189
// RVA: 0xB47960
hkClass *__fastcall hkaiNavMeshGenerationSettings::OverrideSettings::staticClass()
{
  return &hkaiNavMeshGenerationSettingsOverrideSettingsClass;
}

// File Line: 196
// RVA: 0xB479A0
void __fastcall finishLoadedObjecthkaiNavMeshGenerationSettingsOverrideSettings(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiNavMeshGenerationSettings::OverrideSettings::OverrideSettings);
}

// File Line: 202
// RVA: 0xB479C0
void __fastcall cleanupLoadedObjecthkaiNavMeshGenerationSettingsOverrideSettings(void *p)
{
  hkaiNavMeshGenerationSettings::OverrideSettings::~OverrideSettings((hkaiNavMeshGenerationSettings::OverrideSettings *)p);
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
    2u);
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
void __fastcall cleanupLoadedObjecthkaiNavMeshGenerationSettingsRegionPruningSettings(void *p)
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
      16 * v1);
    v2[2] = 0i64;
    *((_DWORD *)v2 + 7) = 2147483648;
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
    1u);
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
    0x19u);
}

// File Line: 510
// RVA: 0xB47940
hkClass *__fastcall hkaiNavMeshGenerationSettings::staticClass()
{
  return &hkaiNavMeshGenerationSettingsClass;
}

// File Line: 517
// RVA: 0xB47A70
void __fastcall finishLoadedObjecthkaiNavMeshGenerationSettings(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings);
}

// File Line: 523
// RVA: 0xB47A90
void __fastcall cleanupLoadedObjecthkaiNavMeshGenerationSettings(void *p)
{
  hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings((hkaiNavMeshGenerationSettings *)p);
}

