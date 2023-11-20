// File Line: 48
// RVA: 0x15D0D00
void dynamic_initializer_for__hkpConstraintCollisionFilterClass__()
{
  hkClass::hkClass(
    &hkpConstraintCollisionFilterClass,
    "hkpConstraintCollisionFilter",
    &hkpPairCollisionFilterClass,
    104,
    0i64,
    1,
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
// RVA: 0xD506B0
hkClass *__fastcall hkpConstraintCollisionFilter::staticClass()
{
  return &hkpConstraintCollisionFilterClass;
}

// File Line: 58
// RVA: 0xD506C0
void __fastcall finishLoadedObjecthkpConstraintCollisionFilter(void *p, int finishing)
{
  if ( p )
  {
    *((_DWORD *)p + 21) = -1;
    *((_QWORD *)p + 9) = 0i64;
    *((_DWORD *)p + 20) = 0;
    *(_QWORD *)p = &hkpConstraintCollisionFilter::`vftable'{for `hkReferencedObject'};
    *((_QWORD *)p + 2) = &hkpConstraintCollisionFilter::`vftable'{for `hkpCollidableCollidableFilter'};
    *((_QWORD *)p + 3) = &hkpConstraintCollisionFilter::`vftable'{for `hkpShapeCollectionFilter'};
    *((_QWORD *)p + 4) = &hkpConstraintCollisionFilter::`vftable'{for `hkpRayShapeCollectionFilter'};
    *((_QWORD *)p + 5) = &hkpConstraintCollisionFilter::`vftable'{for `hkpRayCollidableFilter'};
    *((_QWORD *)p + 12) = &hkpConstraintCollisionFilter::`vftable';
  }
}

// File Line: 64
// RVA: 0xD50720
void __fastcall cleanupLoadedObjecthkpConstraintCollisionFilter(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 68
// RVA: 0xD50730
void **__fastcall getVtablehkpConstraintCollisionFilter()
{
  return &hkpConstraintCollisionFilter::`vftable'{for `hkReferencedObject'};
}

// File Line: 90
// RVA: 0x15D0D60
void **dynamic_initializer_for__hkpConstraintCollisionFilterTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpConstraintCollisionFilter();
  hkpConstraintCollisionFilterTypeInfo.m_size = 104i64;
  hkpConstraintCollisionFilterTypeInfo.m_typeName = "hkpConstraintCollisionFilter";
  hkpConstraintCollisionFilterTypeInfo.m_vtable = result;
  hkpConstraintCollisionFilterTypeInfo.m_scopedName = "!hkpConstraintCollisionFilter";
  hkpConstraintCollisionFilterTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpConstraintCollisionFilter;
  hkpConstraintCollisionFilterTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpConstraintCollisionFilter;
  return result;
}

