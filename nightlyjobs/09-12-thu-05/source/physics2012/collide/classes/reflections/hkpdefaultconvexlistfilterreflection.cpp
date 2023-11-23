// File Line: 48
// RVA: 0x15CA440
void dynamic_initializer_for__hkpDefaultConvexListFilterClass__()
{
  hkClass::hkClass(
    &hkpDefaultConvexListFilterClass,
    "hkpDefaultConvexListFilter",
    &hkpConvexListFilterClass,
    16,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 51
// RVA: 0xCEB9A0
hkClass *__fastcall hkpDefaultConvexListFilter::staticClass()
{
  return &hkpDefaultConvexListFilterClass;
}

// File Line: 58
// RVA: 0xCEB9B0
void __fastcall finishLoadedObjecthkpDefaultConvexListFilter(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkpDefaultConvexListFilter::`vftable;
}

// File Line: 64
// RVA: 0xCEB9D0
void __fastcall cleanupLoadedObjecthkpDefaultConvexListFilter(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 68
// RVA: 0xCEB9E0
void **__fastcall getVtablehkpDefaultConvexListFilter()
{
  return &hkpDefaultConvexListFilter::`vftable;
}

// File Line: 90
// RVA: 0x15CA4A0
void **dynamic_initializer_for__hkpDefaultConvexListFilterTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpDefaultConvexListFilter();
  hkpDefaultConvexListFilterTypeInfo.m_size = 16i64;
  hkpDefaultConvexListFilterTypeInfo.m_typeName = "hkpDefaultConvexListFilter";
  hkpDefaultConvexListFilterTypeInfo.m_vtable = result;
  hkpDefaultConvexListFilterTypeInfo.m_scopedName = "!hkpDefaultConvexListFilter";
  hkpDefaultConvexListFilterTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpDefaultConvexListFilter;
  hkpDefaultConvexListFilterTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpDefaultConvexListFilter;
  return result;
}

