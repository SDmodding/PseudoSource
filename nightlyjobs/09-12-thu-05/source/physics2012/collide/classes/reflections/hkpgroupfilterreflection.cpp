// File Line: 54
// RVA: 0x15CA0F0
void dynamic_initializer_for__hkpGroupFilterClass__()
{
  hkClass::hkClass(
    &hkpGroupFilterClass,
    "hkpGroupFilter",
    &hkpCollisionFilterClass,
    272,
    0i64,
    0,
    0i64,
    0,
    &hkpGroupFilterClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xCEB690
hkClass *__fastcall hkpGroupFilter::staticClass()
{
  return &hkpGroupFilterClass;
}

// File Line: 64
// RVA: 0xCEB6A0
void __fastcall finishLoadedObjecthkpGroupFilter(_QWORD *p, int finishing)
{
  if ( p )
  {
    *p = &hkpGroupFilter::`vftable{for `hkReferencedObject};
    p[2] = &hkpGroupFilter::`vftable{for `hkpCollidableCollidableFilter};
    p[3] = &hkpGroupFilter::`vftable{for `hkpShapeCollectionFilter};
    p[4] = &hkpGroupFilter::`vftable{for `hkpRayShapeCollectionFilter};
    p[5] = &hkpGroupFilter::`vftable{for `hkpRayCollidableFilter};
    if ( finishing )
      *((_DWORD *)p + 14) = 2;
  }
}

// File Line: 70
// RVA: 0xCEB6F0
void __fastcall cleanupLoadedObjecthkpGroupFilter(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 74
// RVA: 0xCEB700
void **__fastcall getVtablehkpGroupFilter()
{
  return &hkpGroupFilter::`vftable{for `hkReferencedObject};
}

// File Line: 96
// RVA: 0x15CA160
void **dynamic_initializer_for__hkpGroupFilterTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpGroupFilter();
  hkpGroupFilterTypeInfo.m_size = 272i64;
  hkpGroupFilterTypeInfo.m_typeName = "hkpGroupFilter";
  hkpGroupFilterTypeInfo.m_vtable = result;
  hkpGroupFilterTypeInfo.m_scopedName = "!hkpGroupFilter";
  hkpGroupFilterTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpGroupFilter;
  hkpGroupFilterTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpGroupFilter;
  return result;
}

