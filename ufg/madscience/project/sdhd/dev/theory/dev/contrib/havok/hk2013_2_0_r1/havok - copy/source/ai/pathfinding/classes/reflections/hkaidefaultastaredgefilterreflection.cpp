// File Line: 53
// RVA: 0x15C0DA0
void dynamic_initializer_for__hkaiDefaultAstarEdgeFilterClass__()
{
  hkClass::hkClass(
    &hkaiDefaultAstarEdgeFilterClass,
    "hkaiDefaultAstarEdgeFilter",
    &hkaiAstarEdgeFilterClass,
    176,
    0i64,
    0,
    0i64,
    0,
    &hkaiDefaultAstarEdgeFilterClass_Members,
    2,
    0i64,
    0i64,
    0,
    2);
}

// File Line: 56
// RVA: 0xBB64F0
hkClass *__fastcall hkaiDefaultAstarEdgeFilter::staticClass()
{
  return &hkaiDefaultAstarEdgeFilterClass;
}

// File Line: 63
// RVA: 0xBB6500
void __fastcall finishLoadedObjecthkaiDefaultAstarEdgeFilter(_QWORD *p, int finishing)
{
  if ( p )
    *p = &hkaiDefaultAstarEdgeFilter::`vftable;
}

// File Line: 69
// RVA: 0xBB6520
void __fastcall cleanupLoadedObjecthkaiDefaultAstarEdgeFilter(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 73
// RVA: 0xBB6530
void **__fastcall getVtablehkaiDefaultAstarEdgeFilter()
{
  return &hkaiDefaultAstarEdgeFilter::`vftable;
}

// File Line: 95
// RVA: 0x15C0E10
void **dynamic_initializer_for__hkaiDefaultAstarEdgeFilterTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaiDefaultAstarEdgeFilter();
  hkaiDefaultAstarEdgeFilterTypeInfo.m_size = 176i64;
  hkaiDefaultAstarEdgeFilterTypeInfo.m_typeName = "hkaiDefaultAstarEdgeFilter";
  hkaiDefaultAstarEdgeFilterTypeInfo.m_vtable = result;
  hkaiDefaultAstarEdgeFilterTypeInfo.m_scopedName = "!hkaiDefaultAstarEdgeFilter";
  hkaiDefaultAstarEdgeFilterTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaiDefaultAstarEdgeFilter;
  hkaiDefaultAstarEdgeFilterTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaiDefaultAstarEdgeFilter;
  return result;
}

