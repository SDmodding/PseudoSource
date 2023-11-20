// File Line: 59
// RVA: 0x15C0A40
void dynamic_initializer_for__hkaiConvexSilhouetteSetClass__()
{
  hkClass::hkClass(
    &hkaiConvexSilhouetteSetClass,
    "hkaiConvexSilhouetteSet",
    &hkReferencedObjectClass,
    96,
    0i64,
    0,
    0i64,
    0,
    &hkaiConvexSilhouetteSet::Members,
    4,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 62
// RVA: 0xBB62A0
hkClass *__fastcall hkaiConvexSilhouetteSet::staticClass()
{
  return &hkaiConvexSilhouetteSetClass;
}

// File Line: 69
// RVA: 0xBB62B0
void __fastcall finishLoadedObjecthkaiConvexSilhouetteSet(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaiConvexSilhouetteSet::hkaiConvexSilhouetteSet);
}

// File Line: 75
// RVA: 0xBB62D0
void __fastcall cleanupLoadedObjecthkaiConvexSilhouetteSet(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 79
// RVA: 0xBB62E0
hkBaseObjectVtbl *__fastcall getVtablehkaiConvexSilhouetteSet()
{
  hkaiConvexSilhouetteSet v1; // [rsp+20h] [rbp-68h]

  hkaiConvexSilhouetteSet::hkaiConvexSilhouetteSet(&v1, 0);
  return v1.vfptr;
}

// File Line: 101
// RVA: 0x15C0AB0
hkBaseObjectVtbl *dynamic_initializer_for__hkaiConvexSilhouetteSetTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaiConvexSilhouetteSet();
  hkaiConvexSilhouetteSetTypeInfo.m_size = 96i64;
  hkaiConvexSilhouetteSetTypeInfo.m_typeName = "hkaiConvexSilhouetteSet";
  hkaiConvexSilhouetteSetTypeInfo.m_vtable = result;
  hkaiConvexSilhouetteSetTypeInfo.m_scopedName = "!hkaiConvexSilhouetteSet";
  hkaiConvexSilhouetteSetTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaiConvexSilhouetteSet;
  hkaiConvexSilhouetteSetTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaiConvexSilhouetteSet;
  return result;
}

