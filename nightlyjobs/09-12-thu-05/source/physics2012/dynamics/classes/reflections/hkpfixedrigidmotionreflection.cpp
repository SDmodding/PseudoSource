// File Line: 48
// RVA: 0x15D1160
void dynamic_initializer_for__hkpFixedRigidMotionClass__()
{
  hkClass::hkClass(
    &hkpFixedRigidMotionClass,
    "hkpFixedRigidMotion",
    &hkpKeyframedRigidMotionClass,
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
// RVA: 0xD50DD0
hkClass *__fastcall hkpFixedRigidMotion::staticClass()
{
  return &hkpFixedRigidMotionClass;
}

// File Line: 58
// RVA: 0xD50DE0
void __fastcall finishLoadedObjecthkpFixedRigidMotion(void *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpMotion::`vftable;
    if ( finishing )
      *((_WORD *)p + 153) = 16256;
    *(_QWORD *)p = &hkpFixedRigidMotion::`vftable;
  }
}

// File Line: 64
// RVA: 0xD50E20
void __fastcall cleanupLoadedObjecthkpFixedRigidMotion(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 68
// RVA: 0xD50E30
void **__fastcall getVtablehkpFixedRigidMotion()
{
  return &hkpFixedRigidMotion::`vftable;
}

// File Line: 90
// RVA: 0x15D11C0
void **dynamic_initializer_for__hkpFixedRigidMotionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpFixedRigidMotion();
  hkpFixedRigidMotionTypeInfo.m_size = 320i64;
  hkpFixedRigidMotionTypeInfo.m_typeName = "hkpFixedRigidMotion";
  hkpFixedRigidMotionTypeInfo.m_vtable = result;
  hkpFixedRigidMotionTypeInfo.m_scopedName = "!hkpFixedRigidMotion";
  hkpFixedRigidMotionTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpFixedRigidMotion;
  hkpFixedRigidMotionTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpFixedRigidMotion;
  return result;
}

