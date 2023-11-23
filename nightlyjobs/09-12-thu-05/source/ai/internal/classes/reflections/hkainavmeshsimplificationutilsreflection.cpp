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
    4);
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
void __fastcall cleanupLoadedObjecthkaiNavMeshSimplificationUtilsExtraVertexSettings(_DWORD *p)
{
  int v1; // r8d

  v1 = p[13];
  p[12] = 0;
  if ( v1 < 0 )
  {
    *((_QWORD *)p + 5) = 0i64;
    p[13] = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      (void *)*((_QWORD *)p + 5),
      16 * v1);
    *((_QWORD *)p + 5) = 0i64;
    p[13] = 0x80000000;
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
    13);
}

// File Line: 326
// RVA: 0xB47AB0
hkClass *__fastcall hkaiNavMeshSimplificationUtils::Settings::staticClass()
{
  return &hkaiNavMeshSimplificationUtilsSettingsClass;
}

// File Line: 333
// RVA: 0xB47B40
void __fastcall finishLoadedObjecthkaiNavMeshSimplificationUtilsSettings(
        hkaiNavMeshSimplificationUtils::Settings *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiNavMeshSimplificationUtils::Settings::Settings(p, finishing);
}

// File Line: 339
// RVA: 0xB47B60
// attributes: thunk
void __fastcall cleanupLoadedObjecthkaiNavMeshSimplificationUtilsSettings(hkaiNavMeshSimplificationUtils::Settings *p)
{
  hkaiNavMeshSimplificationUtils::Settings::~Settings(p);
}

