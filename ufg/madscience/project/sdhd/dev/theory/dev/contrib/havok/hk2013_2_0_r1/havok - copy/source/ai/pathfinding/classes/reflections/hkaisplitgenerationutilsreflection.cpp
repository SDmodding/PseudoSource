// File Line: 65
// RVA: 0x15C0B10
void dynamic_initializer_for__hkaiCuttingGeometryInfoClass__()
{
  hkClass::hkClass(
    &hkaiCuttingGeometryInfoClass,
    "hkaiCuttingGeometryInfo",
    &hkReferencedObjectClass,
    88,
    0i64,
    0,
    0i64,
    0,
    &hkaiCuttingGeometryInfoClass_Members,
    2,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 68
// RVA: 0xBB6300
hkClass *__fastcall hkaiCuttingGeometryInfo::staticClass()
{
  return &hkaiCuttingGeometryInfoClass;
}

// File Line: 75
// RVA: 0xBB6330
void __fastcall finishLoadedObjecthkaiCuttingGeometryInfo(char *p, hkFinishLoadedObjectFlag finishing)
{
  hkGeometry *v2; // rcx

  if ( p )
  {
    v2 = (hkGeometry *)(p + 16);
    v2[-1].m_triangles.m_data = (hkGeometry::Triangle *)&hkaiCuttingGeometryInfo::`vftable;
    hkGeometry::hkGeometry(v2, finishing);
  }
}

// File Line: 81
// RVA: 0xBB6360
void __fastcall cleanupLoadedObjecthkaiCuttingGeometryInfo(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 85
// RVA: 0xBB6370
void **__fastcall getVtablehkaiCuttingGeometryInfo()
{
  hkGeometry v1; // [rsp+30h] [rbp-58h] BYREF

  hkGeometry::hkGeometry(&v1, 0);
  return &hkaiCuttingGeometryInfo::`vftable;
}

// File Line: 107
// RVA: 0x15C0B80
void **dynamic_initializer_for__hkaiCuttingGeometryInfoTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiCuttingGeometryInfo();
  hkaiCuttingGeometryInfoTypeInfo.m_size = 88i64;
  hkaiCuttingGeometryInfoTypeInfo.m_typeName = "hkaiCuttingGeometryInfo";
  hkaiCuttingGeometryInfoTypeInfo.m_vtable = result;
  hkaiCuttingGeometryInfoTypeInfo.m_scopedName = "!hkaiCuttingGeometryInfo";
  hkaiCuttingGeometryInfoTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiCuttingGeometryInfo;
  hkaiCuttingGeometryInfoTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiCuttingGeometryInfo;
  return result;
}

// File Line: 141
// RVA: 0x15C0CB0
hkClassEnum *dynamic_initializer_for__hkaiSplitGenerationUtils_SettingsClass_Members__()
{
  hkClassEnum *result; // rax

  hkaiSplitGenerationUtils_SettingsClass_Members.m_enum = hkaiSplitGenerationUtilsSplitAndGenerateOptionsEnum;
  result = hkaiSplitGenerationUtilsSplitMethodEnum;
  unk_142104378 = hkaiSplitGenerationUtilsSplitMethodEnum;
  return result;
}

// File Line: 198
// RVA: 0x15C0C40
void dynamic_initializer_for__hkaiSplitGenerationUtilsSettingsClass__()
{
  hkClass::hkClass(
    &hkaiSplitGenerationUtilsSettingsClass,
    "hkaiSplitGenerationUtilsSettings",
    0i64,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkaiSplitGenerationUtils_SettingsClass_Members,
    13,
    &hkaiSplitGenerationUtilsSettings_Default,
    0i64,
    0,
    2);
}

// File Line: 201
// RVA: 0xBB6320
hkClass *__fastcall hkaiSplitGenerationUtils::Settings::staticClass()
{
  return &hkaiSplitGenerationUtilsSettingsClass;
}

// File Line: 208
// RVA: 0xBB63B0
void __fastcall finishLoadedObjecthkaiSplitGenerationUtilsSettings(hkStringPtr *p, int finishing)
{
  if ( p )
    hkStringPtr::hkStringPtr(p + 6);
}

// File Line: 214
// RVA: 0xBB63D0
void __fastcall cleanupLoadedObjecthkaiSplitGenerationUtilsSettings(hkStringPtr *p)
{
  hkStringPtr::~hkStringPtr(p + 6);
}

// File Line: 247
// RVA: 0x15C0BE0
void dynamic_initializer_for__hkaiSplitGenerationUtilsClass__()
{
  hkClass::hkClass(
    &hkaiSplitGenerationUtilsClass,
    "hkaiSplitGenerationUtils",
    0i64,
    1,
    0i64,
    0,
    &hkaiSplitGenerationUtilsEnums,
    2,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 250
// RVA: 0xBB6310
hkClass *__fastcall hkaiSplitGenerationUtils::staticClass()
{
  return &hkaiSplitGenerationUtilsClass;
}

// File Line: 257
// RVA: 0xBB63E0
void __fastcall cleanupLoadedObjecthkaiSplitGenerationUtils(void *p)
{
  ;
}

