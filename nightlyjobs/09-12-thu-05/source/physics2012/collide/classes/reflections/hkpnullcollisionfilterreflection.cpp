// File Line: 48
// RVA: 0x15CA700
void dynamic_initializer_for__hkpNullCollisionFilterClass__()
{
  hkClass::hkClass(
    &hkpNullCollisionFilterClass,
    "hkpNullCollisionFilter",
    &hkpCollisionFilterClass,
    72,
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
// RVA: 0xCEBAD0
hkClass *__fastcall hkpNullCollisionFilter::staticClass()
{
  return &hkpNullCollisionFilterClass;
}

// File Line: 58
// RVA: 0xCEBAE0
void __fastcall finishLoadedObjecthkpNullCollisionFilter(void *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpNullCollisionFilter::`vftable'{for `hkReferencedObject'};
    *((_QWORD *)p + 2) = &hkpNullCollisionFilter::`vftable'{for `hkpCollidableCollidableFilter'};
    *((_QWORD *)p + 3) = &hkpNullCollisionFilter::`vftable'{for `hkpShapeCollectionFilter'};
    *((_QWORD *)p + 4) = &hkpNullCollisionFilter::`vftable'{for `hkpRayShapeCollectionFilter'};
    *((_QWORD *)p + 5) = &hkpNullCollisionFilter::`vftable'{for `hkpRayCollidableFilter'};
    if ( finishing )
      *((_DWORD *)p + 14) = 1;
  }
}

// File Line: 64
// RVA: 0xCEBB30
void __fastcall cleanupLoadedObjecthkpNullCollisionFilter(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 68
// RVA: 0xCEBB40
void **__fastcall getVtablehkpNullCollisionFilter()
{
  return &hkpNullCollisionFilter::`vftable'{for `hkReferencedObject'};
}

// File Line: 90
// RVA: 0x15CA760
void **dynamic_initializer_for__hkpNullCollisionFilterTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpNullCollisionFilter();
  hkpNullCollisionFilterTypeInfo.m_size = 72i64;
  hkpNullCollisionFilterTypeInfo.m_typeName = "hkpNullCollisionFilter";
  hkpNullCollisionFilterTypeInfo.m_vtable = result;
  hkpNullCollisionFilterTypeInfo.m_scopedName = "!hkpNullCollisionFilter";
  hkpNullCollisionFilterTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpNullCollisionFilter;
  hkpNullCollisionFilterTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpNullCollisionFilter;
  return result;
}

