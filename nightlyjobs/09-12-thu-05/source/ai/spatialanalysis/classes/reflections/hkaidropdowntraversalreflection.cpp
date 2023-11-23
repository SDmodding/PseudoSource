// File Line: 54
// RVA: 0x15C4540
void dynamic_initializer_for__hkaiDropDownAnalyzerClass__()
{
  hkClass::hkClass(
    &hkaiDropDownAnalyzerClass,
    "hkaiDropDownAnalyzer",
    &hkaiTraversalAnalyzerClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkaiDropDownAnalyzerClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xC32250
hkClass *__fastcall hkaiDropDownAnalyzer::staticClass()
{
  return &hkaiDropDownAnalyzerClass;
}

// File Line: 64
// RVA: 0xC32260
void __fastcall finishLoadedObjecthkaiDropDownAnalyzer(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkaiDropDownAnalyzer::`vftable;
}

// File Line: 70
// RVA: 0xC32280
void __fastcall cleanupLoadedObjecthkaiDropDownAnalyzer(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 74
// RVA: 0xC32290
void **__fastcall getVtablehkaiDropDownAnalyzer()
{
  return &hkaiDropDownAnalyzer::`vftable;
}

// File Line: 96
// RVA: 0x15C45B0
void **dynamic_initializer_for__hkaiDropDownAnalyzerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiDropDownAnalyzer();
  hkaiDropDownAnalyzerTypeInfo.m_size = 48i64;
  hkaiDropDownAnalyzerTypeInfo.m_typeName = "hkaiDropDownAnalyzer";
  hkaiDropDownAnalyzerTypeInfo.m_vtable = result;
  hkaiDropDownAnalyzerTypeInfo.m_scopedName = "!hkaiDropDownAnalyzer";
  hkaiDropDownAnalyzerTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiDropDownAnalyzer;
  hkaiDropDownAnalyzerTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiDropDownAnalyzer;
  return result;
}

