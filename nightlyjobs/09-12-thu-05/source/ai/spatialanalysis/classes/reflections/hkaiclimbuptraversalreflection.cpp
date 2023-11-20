// File Line: 56
// RVA: 0x15C4470
void dynamic_initializer_for__hkaiClimbUpAnalyzerClass__()
{
  hkClass::hkClass(
    &hkaiClimbUpAnalyzerClass,
    "hkaiClimbUpAnalyzer",
    &hkaiTraversalAnalyzerClass,
    56,
    0i64,
    0,
    0i64,
    0,
    &hkaiClimbUpAnalyzerClass_Members,
    5,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xC32200
hkClass *__fastcall hkaiClimbUpAnalyzer::staticClass()
{
  return &hkaiClimbUpAnalyzerClass;
}

// File Line: 66
// RVA: 0xC32210
void __fastcall finishLoadedObjecthkaiClimbUpAnalyzer(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiClimbUpAnalyzer::`vftable';
}

// File Line: 72
// RVA: 0xC32230
void __fastcall cleanupLoadedObjecthkaiClimbUpAnalyzer(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 76
// RVA: 0xC32240
void **__fastcall getVtablehkaiClimbUpAnalyzer()
{
  return &hkaiClimbUpAnalyzer::`vftable';
}

// File Line: 98
// RVA: 0x15C44E0
void **dynamic_initializer_for__hkaiClimbUpAnalyzerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiClimbUpAnalyzer();
  hkaiClimbUpAnalyzerTypeInfo.m_size = 56i64;
  hkaiClimbUpAnalyzerTypeInfo.m_typeName = "hkaiClimbUpAnalyzer";
  hkaiClimbUpAnalyzerTypeInfo.m_vtable = result;
  hkaiClimbUpAnalyzerTypeInfo.m_scopedName = "!hkaiClimbUpAnalyzer";
  hkaiClimbUpAnalyzerTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiClimbUpAnalyzer;
  hkaiClimbUpAnalyzerTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiClimbUpAnalyzer;
  return result;
}

