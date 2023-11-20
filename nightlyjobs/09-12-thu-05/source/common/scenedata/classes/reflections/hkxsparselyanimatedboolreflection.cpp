// File Line: 56
// RVA: 0x15D76B0
void dynamic_initializer_for__hkxSparselyAnimatedBoolClass__()
{
  hkClass::hkClass(
    &hkxSparselyAnimatedBoolClass,
    "hkxSparselyAnimatedBool",
    &hkReferencedObjectClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkxSparselyAnimatedBoolClass_Members,
    2,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 59
// RVA: 0xE32F10
hkClass *__fastcall hkxSparselyAnimatedBool::staticClass()
{
  return &hkxSparselyAnimatedBoolClass;
}

// File Line: 66
// RVA: 0xE32F20
void __fastcall finishLoadedObjecthkxSparselyAnimatedBool(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkxSparselyAnimatedBool::`vftable';
}

// File Line: 72
// RVA: 0xE32F40
void __fastcall cleanupLoadedObjecthkxSparselyAnimatedBool(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 76
// RVA: 0xE32F50
void **__fastcall getVtablehkxSparselyAnimatedBool()
{
  return &hkxSparselyAnimatedBool::`vftable';
}

// File Line: 98
// RVA: 0x15D7720
void **dynamic_initializer_for__hkxSparselyAnimatedBoolTypeInfo__()
{
  void **result; // rax

  result = getVtablehkxSparselyAnimatedBool();
  hkxSparselyAnimatedBoolTypeInfo.m_size = 48i64;
  hkxSparselyAnimatedBoolTypeInfo.m_typeName = "hkxSparselyAnimatedBool";
  hkxSparselyAnimatedBoolTypeInfo.m_vtable = result;
  hkxSparselyAnimatedBoolTypeInfo.m_scopedName = "!hkxSparselyAnimatedBool";
  hkxSparselyAnimatedBoolTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkxSparselyAnimatedBool;
  hkxSparselyAnimatedBoolTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkxSparselyAnimatedBool;
  return result;
}

