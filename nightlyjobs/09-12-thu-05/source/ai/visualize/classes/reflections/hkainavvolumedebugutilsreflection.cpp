// File Line: 78
// RVA: 0x15C54F0
void dynamic_initializer_for__hkaiNavVolumeDebugUtilsDebugInfoClass__()
{
  hkClass::hkClass(
    &hkaiNavVolumeDebugUtilsDebugInfoClass,
    "hkaiNavVolumeDebugUtilsDebugInfo",
    0i64,
    128,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavVolumeDebugUtils_DebugInfoClass_Members,
    23,
    0i64,
    0i64,
    1u,
    0);
}

// File Line: 81
// RVA: 0xC3E270
hkClass *__fastcall hkaiNavVolumeDebugUtils::DebugInfo::staticClass()
{
  return &hkaiNavVolumeDebugUtilsDebugInfoClass;
}

// File Line: 88
// RVA: 0xC3E2A0
void __fastcall cleanupLoadedObjecthkaiNavVolumeDebugUtilsDebugInfo(_DWORD *p)
{
  int v1; // r8d

  v1 = p[27];
  p[26] = 0;
  if ( v1 < 0 )
  {
    *((_QWORD *)p + 12) = 0i64;
    p[27] = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      (void *)*((_QWORD *)p + 12),
      4 * v1);
    *((_QWORD *)p + 12) = 0i64;
    p[27] = 0x80000000;
  }
}

// File Line: 125
// RVA: 0x15C5560
void dynamic_initializer_for__hkaiNavVolumeDebugUtilsGeomteryBuildSettingsClass__()
{
  hkClass::hkClass(
    &hkaiNavVolumeDebugUtilsGeomteryBuildSettingsClass,
    "hkaiNavVolumeDebugUtilsGeomteryBuildSettings",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavVolumeDebugUtils_GeomteryBuildSettingsClass_Members,
    2,
    0i64,
    0i64,
    1u,
    0);
}

// File Line: 128
// RVA: 0xC3E280
hkClass *__fastcall hkaiNavVolumeDebugUtils::GeomteryBuildSettings::staticClass()
{
  return &hkaiNavVolumeDebugUtilsGeomteryBuildSettingsClass;
}

// File Line: 135
// RVA: 0xC3E310
void __fastcall cleanupLoadedObjecthkaiNavVolumeDebugUtilsGeomteryBuildSettings(_QWORD *p)
{
  hkReferencedObject *v2; // rcx

  v2 = (hkReferencedObject *)p[1];
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  p[1] = 0i64;
}

// File Line: 177
// RVA: 0x15C55D0
void dynamic_initializer_for__hkaiNavVolumeDebugUtilsGeomteryDisplaySettingsClass__()
{
  hkClass::hkClass(
    &hkaiNavVolumeDebugUtilsGeomteryDisplaySettingsClass,
    "hkaiNavVolumeDebugUtilsGeomteryDisplaySettings",
    0i64,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavVolumeDebugUtils_GeomteryDisplaySettingsClass_Members,
    7,
    0i64,
    0i64,
    1u,
    0);
}

// File Line: 180
// RVA: 0xC3E290
hkClass *__fastcall hkaiNavVolumeDebugUtils::GeomteryDisplaySettings::staticClass()
{
  return &hkaiNavVolumeDebugUtilsGeomteryDisplaySettingsClass;
}

// File Line: 187
// RVA: 0xC3E340
void __fastcall cleanupLoadedObjecthkaiNavVolumeDebugUtilsGeomteryDisplaySettings(void *p)
{
  ;
}

