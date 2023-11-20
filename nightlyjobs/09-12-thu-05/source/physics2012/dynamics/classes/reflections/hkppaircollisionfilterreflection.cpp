// File Line: 56
// RVA: 0x15D1350
void dynamic_initializer_for__hkpPairCollisionFilterMapPairFilterKeyOverrideTypeClass__()
{
  hkClass::hkClass(
    &hkpPairCollisionFilterMapPairFilterKeyOverrideTypeClass,
    "hkpPairCollisionFilterMapPairFilterKeyOverrideType",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkpPairCollisionFilter_MapPairFilterKeyOverrideTypeClass_Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xD50EC0
hkClass *__fastcall hkpPairCollisionFilter::MapPairFilterKeyOverrideType::staticClass()
{
  return &hkpPairCollisionFilterMapPairFilterKeyOverrideTypeClass;
}

// File Line: 66
// RVA: 0xD50ED0
void __fastcall cleanupLoadedObjecthkpPairCollisionFilterMapPairFilterKeyOverrideType(void *p)
{
  ;
}

// File Line: 106
// RVA: 0x15D12E0
void dynamic_initializer_for__hkpPairCollisionFilterClass__()
{
  hkClass::hkClass(
    &hkpPairCollisionFilterClass,
    "hkpPairCollisionFilter",
    &hkpCollisionFilterClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkpPairCollisionFilterClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 109
// RVA: 0xD50EB0
hkClass *__fastcall hkpPairCollisionFilter::staticClass()
{
  return &hkpPairCollisionFilterClass;
}

// File Line: 116
// RVA: 0xD50EE0
void __fastcall finishLoadedObjecthkpPairCollisionFilter(void *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpPairCollisionFilter::`vftable{for `hkReferencedObject};
    *((_QWORD *)p + 2) = &hkpPairCollisionFilter::`vftable{for `hkpCollidableCollidableFilter};
    *((_QWORD *)p + 3) = &hkpPairCollisionFilter::`vftable{for `hkpShapeCollectionFilter};
    *((_QWORD *)p + 4) = &hkpPairCollisionFilter::`vftable{for `hkpRayShapeCollectionFilter};
    *((_QWORD *)p + 5) = &hkpPairCollisionFilter::`vftable{for `hkpRayCollidableFilter};
    *((_DWORD *)p + 21) = -1;
    *((_QWORD *)p + 9) = 0i64;
    *((_DWORD *)p + 20) = 0;
  }
}

// File Line: 122
// RVA: 0xD50F40
void __fastcall cleanupLoadedObjecthkpPairCollisionFilter(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 126
// RVA: 0xD50F50
void **__fastcall getVtablehkpPairCollisionFilter()
{
  return &hkpPairCollisionFilter::`vftable{for `hkReferencedObject};
}

// File Line: 148
// RVA: 0x15D13B0
void **dynamic_initializer_for__hkpPairCollisionFilterTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpPairCollisionFilter();
  hkpPairCollisionFilterTypeInfo.m_size = 96i64;
  hkpPairCollisionFilterTypeInfo.m_typeName = "hkpPairCollisionFilter";
  hkpPairCollisionFilterTypeInfo.m_vtable = result;
  hkpPairCollisionFilterTypeInfo.m_scopedName = "!hkpPairCollisionFilter";
  hkpPairCollisionFilterTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpPairCollisionFilter;
  hkpPairCollisionFilterTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpPairCollisionFilter;
  return result;
}

