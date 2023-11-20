// File Line: 59
// RVA: 0x15C49C0
void dynamic_initializer_for__hkaiVaultAnalyzerClass__()
{
  hkClass::hkClass(
    &hkaiVaultAnalyzerClass,
    "hkaiVaultAnalyzer",
    &hkaiTraversalAnalyzerClass,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkaiVaultAnalyzerClass_Members,
    8,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 62
// RVA: 0xC325E0
hkClass *__fastcall hkaiVaultAnalyzer::staticClass()
{
  return &hkaiVaultAnalyzerClass;
}

// File Line: 69
// RVA: 0xC325F0
void __fastcall finishLoadedObjecthkaiVaultAnalyzer(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaiVaultAnalyzer::`vftable;
}

// File Line: 75
// RVA: 0xC32610
void __fastcall cleanupLoadedObjecthkaiVaultAnalyzer(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 79
// RVA: 0xC32620
void **__fastcall getVtablehkaiVaultAnalyzer()
{
  return &hkaiVaultAnalyzer::`vftable;
}

// File Line: 101
// RVA: 0x15C4A30
void **dynamic_initializer_for__hkaiVaultAnalyzerTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiVaultAnalyzer();
  hkaiVaultAnalyzerTypeInfo.m_size = 64i64;
  hkaiVaultAnalyzerTypeInfo.m_typeName = "hkaiVaultAnalyzer";
  hkaiVaultAnalyzerTypeInfo.m_vtable = result;
  hkaiVaultAnalyzerTypeInfo.m_scopedName = "!hkaiVaultAnalyzer";
  hkaiVaultAnalyzerTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiVaultAnalyzer;
  hkaiVaultAnalyzerTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiVaultAnalyzer;
  return result;
}

