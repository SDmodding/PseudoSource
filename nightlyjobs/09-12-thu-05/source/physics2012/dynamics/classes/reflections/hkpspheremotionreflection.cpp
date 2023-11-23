// File Line: 48
// RVA: 0x15D1750
void dynamic_initializer_for__hkpSphereMotionClass__()
{
  hkClass::hkClass(
    &hkpSphereMotionClass,
    "hkpSphereMotion",
    &hkpMotionClass,
    320,
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
// RVA: 0xD511B0
hkClass *__fastcall hkpSphereMotion::staticClass()
{
  return &hkpSphereMotionClass;
}

// File Line: 58
// RVA: 0xD511C0
void __fastcall finishLoadedObjecthkpSphereMotion(_WORD *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpMotion::`vftable;
    if ( finishing )
      p[153] = 16256;
    *(_QWORD *)p = &hkpSphereMotion::`vftable;
  }
}

// File Line: 64
// RVA: 0xD51200
void __fastcall cleanupLoadedObjecthkpSphereMotion(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 68
// RVA: 0xD51210
void **__fastcall getVtablehkpSphereMotion()
{
  return &hkpSphereMotion::`vftable;
}

// File Line: 90
// RVA: 0x15D17B0
void **dynamic_initializer_for__hkpSphereMotionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpSphereMotion();
  hkpSphereMotionTypeInfo.m_size = 320i64;
  hkpSphereMotionTypeInfo.m_typeName = "hkpSphereMotion";
  hkpSphereMotionTypeInfo.m_vtable = result;
  hkpSphereMotionTypeInfo.m_scopedName = "!hkpSphereMotion";
  hkpSphereMotionTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpSphereMotion;
  hkpSphereMotionTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpSphereMotion;
  return result;
}

