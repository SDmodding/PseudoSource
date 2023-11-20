// File Line: 53
// RVA: 0x15CA1C0
void dynamic_initializer_for__hkpConvexVerticesConnectivityClass__()
{
  hkClass::hkClass(
    &hkpConvexVerticesConnectivityClass,
    "hkpConvexVerticesConnectivity",
    &hkReferencedObjectClass,
    48,
    0i64,
    0,
    0i64,
    0,
    &hkpConvexVerticesConnectivityClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 56
// RVA: 0xCEB7A0
hkClass *__fastcall hkpConvexVerticesConnectivity::staticClass()
{
  return &hkpConvexVerticesConnectivityClass;
}

// File Line: 63
// RVA: 0xCEB7B0
void __fastcall finishLoadedObjecthkpConvexVerticesConnectivity(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkpConvexVerticesConnectivity::`vftable';
}

// File Line: 69
// RVA: 0xCEB7D0
void __fastcall cleanupLoadedObjecthkpConvexVerticesConnectivity(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 73
// RVA: 0xCEB7E0
void **__fastcall getVtablehkpConvexVerticesConnectivity()
{
  return &hkpConvexVerticesConnectivity::`vftable';
}

// File Line: 95
// RVA: 0x15CA230
void **dynamic_initializer_for__hkpConvexVerticesConnectivityTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpConvexVerticesConnectivity();
  hkpConvexVerticesConnectivityTypeInfo.m_size = 48i64;
  hkpConvexVerticesConnectivityTypeInfo.m_typeName = "hkpConvexVerticesConnectivity";
  hkpConvexVerticesConnectivityTypeInfo.m_vtable = result;
  hkpConvexVerticesConnectivityTypeInfo.m_scopedName = "!hkpConvexVerticesConnectivity";
  hkpConvexVerticesConnectivityTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpConvexVerticesConnectivity;
  hkpConvexVerticesConnectivityTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpConvexVerticesConnectivity;
  return result;
}

