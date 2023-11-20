// File Line: 53
// RVA: 0x15D3550
void dynamic_initializer_for__hkpGroupCollisionFilterClass__()
{
  hkClass::hkClass(
    &hkpGroupCollisionFilterClass,
    "hkpGroupCollisionFilter",
    &hkpCollisionFilterClass,
    208,
    0i64,
    0,
    0i64,
    0,
    &hkpGroupCollisionFilterClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 56
// RVA: 0xE0AF20
hkClass *__fastcall hkpGroupCollisionFilter::staticClass()
{
  return &hkpGroupCollisionFilterClass;
}

// File Line: 63
// RVA: 0xE0AF30
void __fastcall finishLoadedObjecthkpGroupCollisionFilter(void *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpGroupCollisionFilter::`vftable'{for `hkReferencedObject'};
    *((_QWORD *)p + 2) = &hkpGroupCollisionFilter::`vftable'{for `hkpCollidableCollidableFilter'};
    *((_QWORD *)p + 3) = &hkpGroupCollisionFilter::`vftable'{for `hkpShapeCollectionFilter'};
    *((_QWORD *)p + 4) = &hkpGroupCollisionFilter::`vftable'{for `hkpRayShapeCollectionFilter'};
    *((_QWORD *)p + 5) = &hkpGroupCollisionFilter::`vftable'{for `hkpRayCollidableFilter'};
  }
}

// File Line: 69
// RVA: 0xE0AF80
void __fastcall cleanupLoadedObjecthkpGroupCollisionFilter(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 73
// RVA: 0xE0AF90
void **__fastcall getVtablehkpGroupCollisionFilter()
{
  return &hkpGroupCollisionFilter::`vftable'{for `hkReferencedObject'};
}

// File Line: 95
// RVA: 0x15D35C0
void **dynamic_initializer_for__hkpGroupCollisionFilterTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpGroupCollisionFilter();
  hkpGroupCollisionFilterTypeInfo.m_size = 208i64;
  hkpGroupCollisionFilterTypeInfo.m_typeName = "hkpGroupCollisionFilter";
  hkpGroupCollisionFilterTypeInfo.m_vtable = result;
  hkpGroupCollisionFilterTypeInfo.m_scopedName = "!hkpGroupCollisionFilter";
  hkpGroupCollisionFilterTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpGroupCollisionFilter;
  hkpGroupCollisionFilterTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpGroupCollisionFilter;
  return result;
}

