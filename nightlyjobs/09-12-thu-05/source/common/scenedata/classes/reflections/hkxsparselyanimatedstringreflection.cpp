// File Line: 56
// RVA: 0x15D7850
void dynamic_initializer_for__hkxSparselyAnimatedStringClass__()
{
  hkClass::hkClass(
    &hkxSparselyAnimatedStringClass,
    "hkxSparselyAnimatedString",
    &hkReferencedObjectClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkxSparselyAnimatedStringClass_Members,
    2,
    0i64,
    0i64,
    0,
    2u);
}

// File Line: 59
// RVA: 0xE330A0
hkClass *__fastcall hkxSparselyAnimatedString::staticClass()
{
  return &hkxSparselyAnimatedStringClass;
}

// File Line: 66
// RVA: 0xE330B0
void __fastcall finishLoadedObjecthkxSparselyAnimatedString(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkxSparselyAnimatedString::`vftable;
}

// File Line: 72
// RVA: 0xE330D0
void __fastcall cleanupLoadedObjecthkxSparselyAnimatedString(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 76
// RVA: 0xE330E0
void **__fastcall getVtablehkxSparselyAnimatedString()
{
  return &hkxSparselyAnimatedString::`vftable;
}

// File Line: 98
// RVA: 0x15D78C0
void **dynamic_initializer_for__hkxSparselyAnimatedStringTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxSparselyAnimatedString();
  hkxSparselyAnimatedStringTypeInfo.m_size = 48i64;
  hkxSparselyAnimatedStringTypeInfo.m_typeName = "hkxSparselyAnimatedString";
  hkxSparselyAnimatedStringTypeInfo.m_vtable = result;
  hkxSparselyAnimatedStringTypeInfo.m_scopedName = "!hkxSparselyAnimatedString";
  hkxSparselyAnimatedStringTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxSparselyAnimatedString;
  hkxSparselyAnimatedStringTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxSparselyAnimatedString;
  return result;
}

