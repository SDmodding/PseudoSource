// File Line: 54
// RVA: 0x15C9E80
void dynamic_initializer_for__hkpCollisionFilterListClass__()
{
  hkClass::hkClass(
    &hkpCollisionFilterListClass,
    "hkpCollisionFilterList",
    &hkpCollisionFilterClass,
    88,
    0i64,
    0,
    0i64,
    0,
    &hkpCollisionFilterList::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 57
// RVA: 0xCEB400
hkClass *__fastcall hkpCollisionFilterList::staticClass()
{
  return &hkpCollisionFilterListClass;
}

// File Line: 64
// RVA: 0xCEB410
void __fastcall finishLoadedObjecthkpCollisionFilterList(_QWORD *p, int finishing)
{
  if ( p )
  {
    *p = &hkpCollisionFilterList::`vftable{for `hkReferencedObject};
    p[2] = &hkpCollisionFilterList::`vftable{for `hkpCollidableCollidableFilter};
    p[3] = &hkpCollisionFilterList::`vftable{for `hkpShapeCollectionFilter};
    p[4] = &hkpCollisionFilterList::`vftable{for `hkpRayShapeCollectionFilter};
    p[5] = &hkpCollisionFilterList::`vftable{for `hkpRayCollidableFilter};
    if ( finishing )
      *((_DWORD *)p + 14) = 3;
  }
}

// File Line: 70
// RVA: 0xCEB460
void __fastcall cleanupLoadedObjecthkpCollisionFilterList(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 74
// RVA: 0xCEB470
void **__fastcall getVtablehkpCollisionFilterList()
{
  return &hkpCollisionFilterList::`vftable{for `hkReferencedObject};
}

// File Line: 96
// RVA: 0x15C9EF0
void **dynamic_initializer_for__hkpCollisionFilterListTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpCollisionFilterList();
  hkpCollisionFilterListTypeInfo.m_size = 88i64;
  hkpCollisionFilterListTypeInfo.m_typeName = "hkpCollisionFilterList";
  hkpCollisionFilterListTypeInfo.m_vtable = result;
  hkpCollisionFilterListTypeInfo.m_scopedName = "!hkpCollisionFilterList";
  hkpCollisionFilterListTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpCollisionFilterList;
  hkpCollisionFilterListTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpCollisionFilterList;
  return result;
}

