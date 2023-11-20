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
void __fastcall cleanupLoadedObjecthkaiNavVolumeDebugUtilsDebugInfo(void *p)
{
  int v1; // er8
  _QWORD *v2; // rbx

  v1 = *((_DWORD *)p + 27);
  v2 = p;
  *((_DWORD *)p + 26) = 0;
  if ( v1 < 0 )
  {
    *((_QWORD *)p + 12) = 0i64;
    *((_DWORD *)p + 27) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)*((_QWORD *)p + 12),
      4 * v1);
    v2[12] = 0i64;
    *((_DWORD *)v2 + 27) = 2147483648;
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
void __fastcall cleanupLoadedObjecthkaiNavVolumeDebugUtilsGeomteryBuildSettings(void *p)
{
  _QWORD *v1; // rbx
  hkReferencedObject *v2; // rcx

  v1 = p;
  v2 = (hkReferencedObject *)*((_QWORD *)p + 1);
  if ( v2 )
    hkReferencedObject::removeReference(v2);
  v1[1] = 0i64;
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

