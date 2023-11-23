// File Line: 81
// RVA: 0x15C3610
void dynamic_initializer_for__hkaiHierarchyUtilsClusterSettingsClass__()
{
  hkClass::hkClass(
    &hkaiHierarchyUtilsClusterSettingsClass,
    "hkaiHierarchyUtilsClusterSettings",
    0i64,
    88,
    0i64,
    0,
    0i64,
    0,
    &hkaiHierarchyUtils_ClusterSettingsClass_Members,
    4,
    &hkaiHierarchyUtilsClusterSettings_Default,
    0i64,
    0,
    1);
}

// File Line: 84
// RVA: 0xBB7C50
hkClass *__fastcall hkaiHierarchyUtils::ClusterSettings::staticClass()
{
  return &hkaiHierarchyUtilsClusterSettingsClass;
}

// File Line: 91
// RVA: 0xBB7C60
void __fastcall finishLoadedObjecthkaiHierarchyUtilsClusterSettings(
        hkaiHierarchyUtils::ClusterSettings *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiHierarchyUtils::ClusterSettings::ClusterSettings(p, finishing);
}

// File Line: 97
// RVA: 0xBB7C80
void __fastcall cleanupLoadedObjecthkaiHierarchyUtilsClusterSettings(void *p)
{
  ;
}

// File Line: 129
// RVA: 0x15C35B0
void dynamic_initializer_for__hkaiHierarchyUtilsClass__()
{
  hkClass::hkClass(&hkaiHierarchyUtilsClass, "hkaiHierarchyUtils", 0i64, 1, 0i64, 0, 0i64, 0, 0i64, 0, 0i64, 0i64, 0, 0);
}

// File Line: 132
// RVA: 0xBB7C40
hkClass *__fastcall hkaiHierarchyUtils::staticClass()
{
  return &hkaiHierarchyUtilsClass;
}

// File Line: 139
// RVA: 0xBB7C90
void __fastcall cleanupLoadedObjecthkaiHierarchyUtils(void *p)
{
  ;
}

