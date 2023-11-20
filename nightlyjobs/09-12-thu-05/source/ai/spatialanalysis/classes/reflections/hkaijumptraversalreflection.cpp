// File Line: 55
// RVA: 0x15C46E0
void dynamic_initializer_for__hkaiJumpAnalyzerClass__()
{
  hkClass::hkClass(
    &hkaiJumpAnalyzerClass,
    "hkaiJumpAnalyzer",
    &hkaiTraversalAnalyzerClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkaiJumpAnalyzerClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xC322F0
hkClass *__fastcall hkaiJumpAnalyzer::staticClass()
{
  return &hkaiJumpAnalyzerClass;
}

// File Line: 65
// RVA: 0xC32300
void __fastcall finishLoadedObjecthkaiJumpAnalyzer(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiJumpAnalyzer::`vftable';
}

// File Line: 71
// RVA: 0xC32320
void __fastcall cleanupLoadedObjecthkaiJumpAnalyzer(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 75
// RVA: 0xC32330
void **__fastcall getVtablehkaiJumpAnalyzer()
{
  return &hkaiJumpAnalyzer::`vftable';
}

// File Line: 97
// RVA: 0x15C4750
void **dynamic_initializer_for__hkaiJumpAnalyzerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiJumpAnalyzer();
  hkaiJumpAnalyzerTypeInfo.m_size = 48i64;
  hkaiJumpAnalyzerTypeInfo.m_typeName = "hkaiJumpAnalyzer";
  hkaiJumpAnalyzerTypeInfo.m_vtable = result;
  hkaiJumpAnalyzerTypeInfo.m_scopedName = "!hkaiJumpAnalyzer";
  hkaiJumpAnalyzerTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiJumpAnalyzer;
  hkaiJumpAnalyzerTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiJumpAnalyzer;
  return result;
}

