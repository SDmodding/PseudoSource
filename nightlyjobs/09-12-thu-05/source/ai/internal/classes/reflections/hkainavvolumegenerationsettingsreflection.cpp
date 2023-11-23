// File Line: 71
// RVA: 0x15BFD40
hkClassEnum *dynamic_initializer_for__hkaiNavVolumeGenerationSettings_MaterialConstructionInfoClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiNavVolumeGenerationSettingsMaterialFlagsBitsEnum;
  unk_1421027C8 = hkaiNavVolumeGenerationSettingsMaterialFlagsBitsEnum;
  return result;
}

// File Line: 111
// RVA: 0x15BFC60
void dynamic_initializer_for__hkaiNavVolumeGenerationSettingsMaterialConstructionInfoClass__()
{
  hkClass::hkClass(
    &hkaiNavVolumeGenerationSettingsMaterialConstructionInfoClass,
    "hkaiNavVolumeGenerationSettingsMaterialConstructionInfo",
    0i64,
    12,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavVolumeGenerationSettings_MaterialConstructionInfoClass_Members,
    3,
    &hkaiNavVolumeGenerationSettingsMaterialConstructionInfo_Default,
    0i64,
    0,
    2);
}

// File Line: 114
// RVA: 0xB47BF0
hkClass *__fastcall hkaiNavVolumeGenerationSettings::MaterialConstructionInfo::staticClass()
{
  return &hkaiNavVolumeGenerationSettingsMaterialConstructionInfoClass;
}

// File Line: 121
// RVA: 0xB47C20
void __fastcall finishLoadedObjecthkaiNavVolumeGenerationSettingsMaterialConstructionInfo(
        hkaiNavVolumeGenerationSettings::MaterialConstructionInfo *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiNavVolumeGenerationSettings::MaterialConstructionInfo::MaterialConstructionInfo(p, finishing);
}

// File Line: 127
// RVA: 0xB47C40
void __fastcall cleanupLoadedObjecthkaiNavVolumeGenerationSettingsMaterialConstructionInfo(void *p)
{
  ;
}

// File Line: 208
// RVA: 0x15BFB60
void dynamic_initializer_for__hkaiNavVolumeGenerationSettingsChunkSettingsClass__()
{
  hkClass::hkClass(
    &hkaiNavVolumeGenerationSettingsChunkSettingsClass,
    "hkaiNavVolumeGenerationSettingsChunkSettings",
    0i64,
    6,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavVolumeGenerationSettings_ChunkSettingsClass_Members,
    3,
    &hkaiNavVolumeGenerationSettingsChunkSettings_Default,
    0i64,
    0,
    0);
}

// File Line: 211
// RVA: 0xB47C00
hkClass *__fastcall hkaiNavVolumeGenerationSettings::ChunkSettings::staticClass()
{
  return &hkaiNavVolumeGenerationSettingsChunkSettingsClass;
}

// File Line: 218
// RVA: 0xB47C50
void __fastcall finishLoadedObjecthkaiNavVolumeGenerationSettingsChunkSettings(void *p, int finishing)
{
  ;
}

// File Line: 224
// RVA: 0xB47C60
void __fastcall cleanupLoadedObjecthkaiNavVolumeGenerationSettingsChunkSettings(void *p)
{
  ;
}

// File Line: 303
// RVA: 0x15BFCD0
void dynamic_initializer_for__hkaiNavVolumeGenerationSettingsMergingSettingsClass__()
{
  hkClass::hkClass(
    &hkaiNavVolumeGenerationSettingsMergingSettingsClass,
    "hkaiNavVolumeGenerationSettingsMergingSettings",
    0i64,
    36,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavVolumeGenerationSettings_MergingSettingsClass_Members,
    9,
    &hkaiNavVolumeGenerationSettingsMergingSettings_Default,
    0i64,
    0,
    3);
}

// File Line: 306
// RVA: 0xB47C10
hkClass *__fastcall hkaiNavVolumeGenerationSettings::MergingSettings::staticClass()
{
  return &hkaiNavVolumeGenerationSettingsMergingSettingsClass;
}

// File Line: 313
// RVA: 0xB47C70
void __fastcall finishLoadedObjecthkaiNavVolumeGenerationSettingsMergingSettings(void *p, int finishing)
{
  ;
}

// File Line: 319
// RVA: 0xB47C80
void __fastcall cleanupLoadedObjecthkaiNavVolumeGenerationSettingsMergingSettings(void *p)
{
  ;
}

// File Line: 420
// RVA: 0x15BFC50
hkClassEnum *dynamic_initializer_for__hkaiNavVolumeGenerationSettingsClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiNavVolumeGenerationSettingsCellWidthToResolutionRoundingEnum;
  unk_142102AB0 = hkaiNavVolumeGenerationSettingsCellWidthToResolutionRoundingEnum;
  return result;
}

// File Line: 482
// RVA: 0x15BFBD0
void dynamic_initializer_for__hkaiNavVolumeGenerationSettingsClass__()
{
  hkClass::hkClass(
    &hkaiNavVolumeGenerationSettingsClass,
    "hkaiNavVolumeGenerationSettings",
    0i64,
    256,
    0i64,
    0,
    &hkaiNavVolumeGenerationSettingsEnums,
    2,
    &hkaiNavVolumeGenerationSettingsClass_Members,
    23,
    &hkaiNavVolumeGenerationSettings_Default,
    0i64,
    0,
    9);
}

// File Line: 485
// RVA: 0xB47BE0
hkClass *__fastcall hkaiNavVolumeGenerationSettings::staticClass()
{
  return &hkaiNavVolumeGenerationSettingsClass;
}

// File Line: 492
// RVA: 0xB47C90
void __fastcall finishLoadedObjecthkaiNavVolumeGenerationSettings(
        hkaiNavVolumeGenerationSettings *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiNavVolumeGenerationSettings::hkaiNavVolumeGenerationSettings(p, finishing);
}

// File Line: 498
// RVA: 0xB47CB0
// attributes: thunk
void __fastcall cleanupLoadedObjecthkaiNavVolumeGenerationSettings(hkaiNavVolumeGenerationSettings *p)
{
  hkaiNavVolumeGenerationSettings::~hkaiNavVolumeGenerationSettings(p);
}

