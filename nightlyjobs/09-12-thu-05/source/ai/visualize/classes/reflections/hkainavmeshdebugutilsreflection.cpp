// File Line: 62
// RVA: 0x15C5480
void dynamic_initializer_for__hkaiNavMeshDebugUtilsSmallEdgeSettingsClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshDebugUtilsSmallEdgeSettingsClass,
    "hkaiNavMeshDebugUtilsSmallEdgeSettings",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMeshDebugUtils_SmallEdgeSettingsClass_Members,
    6,
    0i64,
    0i64,
    1u,
    0);
}

// File Line: 65
// RVA: 0xC3E180
hkClass *__fastcall hkaiNavMeshDebugUtils::SmallEdgeSettings::staticClass()
{
  return &hkaiNavMeshDebugUtilsSmallEdgeSettingsClass;
}

// File Line: 72
// RVA: 0xC3E1C0
void __fastcall cleanupLoadedObjecthkaiNavMeshDebugUtilsSmallEdgeSettings(void *p)
{
  ;
}

// File Line: 109
// RVA: 0x15C5410
void dynamic_initializer_for__hkaiNavMeshDebugUtilsNonplanarFacesSettingsClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshDebugUtilsNonplanarFacesSettingsClass,
    "hkaiNavMeshDebugUtilsNonplanarFacesSettings",
    0i64,
    8,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMeshDebugUtils_NonplanarFacesSettingsClass_Members,
    3,
    0i64,
    0i64,
    1u,
    0);
}

// File Line: 112
// RVA: 0xC3E190
hkClass *__fastcall hkaiNavMeshDebugUtils::NonplanarFacesSettings::staticClass()
{
  return &hkaiNavMeshDebugUtilsNonplanarFacesSettingsClass;
}

// File Line: 119
// RVA: 0xC3E1D0
void __fastcall cleanupLoadedObjecthkaiNavMeshDebugUtilsNonplanarFacesSettings(void *p)
{
  ;
}

// File Line: 158
// RVA: 0x15C53A0
void dynamic_initializer_for__hkaiNavMeshDebugUtilsFaceNormalSettingsClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshDebugUtilsFaceNormalSettingsClass,
    "hkaiNavMeshDebugUtilsFaceNormalSettings",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMeshDebugUtils_FaceNormalSettingsClass_Members,
    5,
    0i64,
    0i64,
    1u,
    0);
}

// File Line: 161
// RVA: 0xC3E1A0
hkClass *__fastcall hkaiNavMeshDebugUtils::FaceNormalSettings::staticClass()
{
  return &hkaiNavMeshDebugUtilsFaceNormalSettingsClass;
}

// File Line: 168
// RVA: 0xC3E1E0
void __fastcall cleanupLoadedObjecthkaiNavMeshDebugUtilsFaceNormalSettings(void *p)
{
  ;
}

// File Line: 278
// RVA: 0x15C5330
void dynamic_initializer_for__hkaiNavMeshDebugUtilsDebugInfoClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshDebugUtilsDebugInfoClass,
    "hkaiNavMeshDebugUtilsDebugInfo",
    0i64,
    560,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMeshDebugUtils_DebugInfoClass_Members,
    52,
    &hkaiNavMeshDebugUtilsDebugInfo_Default,
    0i64,
    1u,
    0);
}

// File Line: 281
// RVA: 0xC3E1B0
hkClass *__fastcall hkaiNavMeshDebugUtils::DebugInfo::staticClass()
{
  return &hkaiNavMeshDebugUtilsDebugInfoClass;
}

// File Line: 288
// RVA: 0xC3E1F0
void __fastcall cleanupLoadedObjecthkaiNavMeshDebugUtilsDebugInfo(void *p)
{
  hkaiNavMeshDebugUtils::DebugInfo::~DebugInfo((hkaiNavMeshDebugUtils::DebugInfo *)p);
}

