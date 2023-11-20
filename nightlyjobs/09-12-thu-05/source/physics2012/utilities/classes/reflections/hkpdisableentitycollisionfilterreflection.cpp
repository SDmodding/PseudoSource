// File Line: 55
// RVA: 0x15D3050
void dynamic_initializer_for__hkpDisableEntityCollisionFilterClass__()
{
  hkClass::hkClass(
    &hkpDisableEntityCollisionFilterClass,
    "hkpDisableEntityCollisionFilter",
    &hkpCollisionFilterClass,
    96,
    0i64,
    1,
    0i64,
    0,
    &hkpDisableEntityCollisionFilterClass_Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xE0A910
hkClass *__fastcall hkpDisableEntityCollisionFilter::staticClass()
{
  return &hkpDisableEntityCollisionFilterClass;
}

// File Line: 65
// RVA: 0xE0A920
void __fastcall finishLoadedObjecthkpDisableEntityCollisionFilter(void *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpDisableEntityCollisionFilter::`vftable'{for `hkReferencedObject'};
    *((_QWORD *)p + 2) = &hkpDisableEntityCollisionFilter::`vftable'{for `hkpCollidableCollidableFilter'};
    *((_QWORD *)p + 3) = &hkpDisableEntityCollisionFilter::`vftable'{for `hkpShapeCollectionFilter'};
    *((_QWORD *)p + 4) = &hkpDisableEntityCollisionFilter::`vftable'{for `hkpRayShapeCollectionFilter'};
    *((_QWORD *)p + 5) = &hkpDisableEntityCollisionFilter::`vftable'{for `hkpRayCollidableFilter'};
    *((_QWORD *)p + 9) = &hkpDisableEntityCollisionFilter::`vftable';
  }
}

// File Line: 71
// RVA: 0xE0A970
void __fastcall cleanupLoadedObjecthkpDisableEntityCollisionFilter(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 75
// RVA: 0xE0A980
void **__fastcall getVtablehkpDisableEntityCollisionFilter()
{
  return &hkpDisableEntityCollisionFilter::`vftable'{for `hkReferencedObject'};
}

// File Line: 97
// RVA: 0x15D30C0
void **dynamic_initializer_for__hkpDisableEntityCollisionFilterTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpDisableEntityCollisionFilter();
  hkpDisableEntityCollisionFilterTypeInfo.m_size = 96i64;
  hkpDisableEntityCollisionFilterTypeInfo.m_typeName = "hkpDisableEntityCollisionFilter";
  hkpDisableEntityCollisionFilterTypeInfo.m_vtable = result;
  hkpDisableEntityCollisionFilterTypeInfo.m_scopedName = "!hkpDisableEntityCollisionFilter";
  hkpDisableEntityCollisionFilterTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpDisableEntityCollisionFilter;
  hkpDisableEntityCollisionFilterTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpDisableEntityCollisionFilter;
  return result;
}

