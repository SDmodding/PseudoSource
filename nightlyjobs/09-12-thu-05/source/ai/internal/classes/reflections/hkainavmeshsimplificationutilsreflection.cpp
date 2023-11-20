// File Line: 72
// RVA: 0x15BFB50
hkClassEnum *dynamic_initializer_for__hkaiNavMeshSimplificationUtils_ExtraVertexSettingsClass_Members__()
{
  hkClassEnum *result; // rax

  result = hkaiNavMeshSimplificationUtilsExtraVertexSettingsVertexSelectionMethodEnum;
  hkaiNavMeshSimplificationUtils_ExtraVertexSettingsClass_Members.m_enum = hkaiNavMeshSimplificationUtilsExtraVertexSettingsVertexSelectionMethodEnum;
  return result;
}

// File Line: 130
// RVA: 0x15BFA60
void dynamic_initializer_for__hkaiNavMeshSimplificationUtilsExtraVertexSettingsClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshSimplificationUtilsExtraVertexSettingsClass,
    "hkaiNavMeshSimplificationUtilsExtraVertexSettings",
    0i64,
    56,
    0i64,
    0,
    &hkaiNavMeshSimplificationUtilsExtraVertexSettingsEnums,
    1,
    &hkaiNavMeshSimplificationUtils_ExtraVertexSettingsClass_Members,
    12,
    &hkaiNavMeshSimplificationUtilsExtraVertexSettings_Default,
    0i64,
    0,
    4u);
}

// File Line: 133
// RVA: 0xB47AA0
hkClass *__fastcall hkaiNavMeshSimplificationUtils::ExtraVertexSettings::staticClass()
{
  return &hkaiNavMeshSimplificationUtilsExtraVertexSettingsClass;
}

// File Line: 140
// RVA: 0xB47AC0
void __fastcall finishLoadedObjecthkaiNavMeshSimplificationUtilsExtraVertexSettings(void *p, int finishing)
{
  ;
}

// File Line: 146
// RVA: 0xB47AD0
void __fastcall cleanupLoadedObjecthkaiNavMeshSimplificationUtilsExtraVertexSettings(void *p)
{
  int v1; // er8
  _QWORD *v2; // rbx

  v1 = *((_DWORD *)p + 13);
  v2 = p;
  *((_DWORD *)p + 12) = 0;
  if ( v1 < 0 )
  {
    *((_QWORD *)p + 5) = 0i64;
    *((_DWORD *)p + 13) = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)*((_QWORD *)p + 5),
      16 * v1);
    v2[5] = 0i64;
    *((_DWORD *)v2 + 13) = 2147483648;
  }
}

// File Line: 323
// RVA: 0x15BFAE0
void dynamic_initializer_for__hkaiNavMeshSimplificationUtilsSettingsClass__()
{
  hkClass::hkClass(
    &hkaiNavMeshSimplificationUtilsSettingsClass,
    "hkaiNavMeshSimplificationUtilsSettings",
    0i64,
    160,
    0i64,
    0,
    0i64,
    0,
    &hkaiNavMeshSimplificationUtils_SettingsClass_Members,
    25,
    &hkaiNavMeshSimplificationUtilsSettings_Default,
    0i64,
    0,
    0xDu);
}

// File Line: 326
// RVA: 0xB47AB0
hkClass *__fastcall hkaiNavMeshSimplificationUtils::Settings::staticClass()
{
  return &hkaiNavMeshSimplificationUtilsSettingsClass;
}

// File Line: 333
// RVA: 0xB47B40
void __fastcall finishLoadedObjecthkaiNavMeshSimplificationUtilsSettings(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiNavMeshSimplificationUtils::Settings::Settings);
}

// File Line: 339
// RVA: 0xB47B60
void __fastcall cleanupLoadedObjecthkaiNavMeshSimplificationUtilsSettings(void *p)
{
  hkaiNavMeshSimplificationUtils::Settings::~Settings((hkaiNavMeshSimplificationUtils::Settings *)p);
}

