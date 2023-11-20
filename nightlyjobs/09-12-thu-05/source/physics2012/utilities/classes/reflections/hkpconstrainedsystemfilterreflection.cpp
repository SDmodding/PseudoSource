// File Line: 54
// RVA: 0x15D2EB0
void dynamic_initializer_for__hkpConstrainedSystemFilterClass__()
{
  hkClass::hkClass(
    &hkpConstrainedSystemFilterClass,
    "hkpConstrainedSystemFilter",
    &hkpCollisionFilterClass,
    88,
    0i64,
    1,
    0i64,
    0,
    &hkpConstrainedSystemFilter::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xE0A6A0
hkClass *__fastcall hkpConstrainedSystemFilter::staticClass()
{
  return &hkpConstrainedSystemFilterClass;
}

// File Line: 64
// RVA: 0xE0A6B0
void __fastcall finishLoadedObjecthkpConstrainedSystemFilter(void *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpConstrainedSystemFilter::`vftable{for `hkReferencedObject};
    *((_QWORD *)p + 2) = &hkpConstrainedSystemFilter::`vftable{for `hkpCollidableCollidableFilter};
    *((_QWORD *)p + 3) = &hkpConstrainedSystemFilter::`vftable{for `hkpShapeCollectionFilter};
    *((_QWORD *)p + 4) = &hkpConstrainedSystemFilter::`vftable{for `hkpRayShapeCollectionFilter};
    *((_QWORD *)p + 5) = &hkpConstrainedSystemFilter::`vftable{for `hkpRayCollidableFilter};
    *((_QWORD *)p + 9) = &hkpConstrainedSystemFilter::`vftable;
  }
}

// File Line: 70
// RVA: 0xE0A700
void __fastcall cleanupLoadedObjecthkpConstrainedSystemFilter(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 74
// RVA: 0xE0A710
void **__fastcall getVtablehkpConstrainedSystemFilter()
{
  return &hkpConstrainedSystemFilter::`vftable{for `hkReferencedObject};
}

// File Line: 96
// RVA: 0x15D2F20
void **dynamic_initializer_for__hkpConstrainedSystemFilterTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpConstrainedSystemFilter();
  hkpConstrainedSystemFilterTypeInfo.m_size = 88i64;
  hkpConstrainedSystemFilterTypeInfo.m_typeName = "hkpConstrainedSystemFilter";
  hkpConstrainedSystemFilterTypeInfo.m_vtable = result;
  hkpConstrainedSystemFilterTypeInfo.m_scopedName = "!hkpConstrainedSystemFilter";
  hkpConstrainedSystemFilterTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpConstrainedSystemFilter;
  hkpConstrainedSystemFilterTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpConstrainedSystemFilter;
  return result;
}

