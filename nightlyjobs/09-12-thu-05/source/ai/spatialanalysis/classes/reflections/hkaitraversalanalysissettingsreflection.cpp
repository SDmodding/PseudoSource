// File Line: 83
// RVA: 0x15C47B0
void dynamic_initializer_for__hkaiTraversalAnalysisSettingsClass__()
{
  hkClass::hkClass(
    &hkaiTraversalAnalysisSettingsClass,
    "hkaiTraversalAnalysisSettings",
    &hkReferencedObjectClass,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkaiTraversalAnalysisSettingsClass_Members,
    6,
    &hkaiTraversalAnalysisSettings_Default,
    0i64,
    0,
    0);
}

// File Line: 86
// RVA: 0xC32340
hkClass *__fastcall hkaiTraversalAnalysisSettings::staticClass()
{
  return &hkaiTraversalAnalysisSettingsClass;
}

// File Line: 93
// RVA: 0xC32350
void __fastcall finishLoadedObjecthkaiTraversalAnalysisSettings(
        hkaiTraversalAnalysisSettings *p,
        hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkaiTraversalAnalysisSettings::hkaiTraversalAnalysisSettings(p, finishing);
}

// File Line: 99
// RVA: 0xC32370
void __fastcall cleanupLoadedObjecthkaiTraversalAnalysisSettings(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 103
// RVA: 0xC32380
hkBaseObjectVtbl *__fastcall getVtablehkaiTraversalAnalysisSettings()
{
  hkaiTraversalAnalysisSettings v1; // [rsp+20h] [rbp-48h] BYREF

  hkaiTraversalAnalysisSettings::hkaiTraversalAnalysisSettings(&v1, 0);
  return v1.vfptr;
}

// File Line: 125
// RVA: 0x15C4820
hkBaseObjectVtbl *dynamic_initializer_for__hkaiTraversalAnalysisSettingsTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiTraversalAnalysisSettings();
  hkaiTraversalAnalysisSettingsTypeInfo.m_size = 64i64;
  hkaiTraversalAnalysisSettingsTypeInfo.m_typeName = "hkaiTraversalAnalysisSettings";
  hkaiTraversalAnalysisSettingsTypeInfo.m_vtable = result;
  hkaiTraversalAnalysisSettingsTypeInfo.m_scopedName = "!hkaiTraversalAnalysisSettings";
  hkaiTraversalAnalysisSettingsTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiTraversalAnalysisSettings;
  hkaiTraversalAnalysisSettingsTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiTraversalAnalysisSettings;
  return result;
}

