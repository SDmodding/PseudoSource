// File Line: 53
// RVA: 0x15D7780
void dynamic_initializer_for__hkxSparselyAnimatedIntClass__()
{
  hkClass::hkClass(
    &hkxSparselyAnimatedIntClass,
    "hkxSparselyAnimatedInt",
    &hkReferencedObjectClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkxSparselyAnimatedIntClass_Members,
    2,
    0i64,
    0i64,
    0,
    1);
}

// File Line: 56
// RVA: 0xE33050
hkClass *__fastcall hkxSparselyAnimatedInt::staticClass()
{
  return &hkxSparselyAnimatedIntClass;
}

// File Line: 63
// RVA: 0xE33060
void __fastcall finishLoadedObjecthkxSparselyAnimatedInt(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkxSparselyAnimatedInt::`vftable;
}

// File Line: 69
// RVA: 0xE33080
void __fastcall cleanupLoadedObjecthkxSparselyAnimatedInt(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 73
// RVA: 0xE33090
void **__fastcall getVtablehkxSparselyAnimatedInt()
{
  return &hkxSparselyAnimatedInt::`vftable;
}

// File Line: 95
// RVA: 0x15D77F0
void **dynamic_initializer_for__hkxSparselyAnimatedIntTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxSparselyAnimatedInt();
  hkxSparselyAnimatedIntTypeInfo.m_size = 48i64;
  hkxSparselyAnimatedIntTypeInfo.m_typeName = "hkxSparselyAnimatedInt";
  hkxSparselyAnimatedIntTypeInfo.m_vtable = result;
  hkxSparselyAnimatedIntTypeInfo.m_scopedName = "!hkxSparselyAnimatedInt";
  hkxSparselyAnimatedIntTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkxSparselyAnimatedInt;
  hkxSparselyAnimatedIntTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkxSparselyAnimatedInt;
  return result;
}

