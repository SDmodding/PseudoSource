// File Line: 55
// RVA: 0x15C4610
void dynamic_initializer_for__hkaiDuckUnderAnalyzerClass__()
{
  hkClass::hkClass(
    &hkaiDuckUnderAnalyzerClass,
    "hkaiDuckUnderAnalyzer",
    &hkaiTraversalAnalyzerClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkaiDuckUnderAnalyzerClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xC322A0
hkClass *__fastcall hkaiDuckUnderAnalyzer::staticClass()
{
  return &hkaiDuckUnderAnalyzerClass;
}

// File Line: 65
// RVA: 0xC322B0
void __fastcall finishLoadedObjecthkaiDuckUnderAnalyzer(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkaiDuckUnderAnalyzer::`vftable;
}

// File Line: 71
// RVA: 0xC322D0
void __fastcall cleanupLoadedObjecthkaiDuckUnderAnalyzer(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 75
// RVA: 0xC322E0
void **__fastcall getVtablehkaiDuckUnderAnalyzer()
{
  return &hkaiDuckUnderAnalyzer::`vftable;
}

// File Line: 97
// RVA: 0x15C4680
void **dynamic_initializer_for__hkaiDuckUnderAnalyzerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiDuckUnderAnalyzer();
  hkaiDuckUnderAnalyzerTypeInfo.m_size = 48i64;
  hkaiDuckUnderAnalyzerTypeInfo.m_typeName = "hkaiDuckUnderAnalyzer";
  hkaiDuckUnderAnalyzerTypeInfo.m_vtable = result;
  hkaiDuckUnderAnalyzerTypeInfo.m_scopedName = "!hkaiDuckUnderAnalyzer";
  hkaiDuckUnderAnalyzerTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiDuckUnderAnalyzer;
  hkaiDuckUnderAnalyzerTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiDuckUnderAnalyzer;
  return result;
}

