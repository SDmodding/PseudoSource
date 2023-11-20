// File Line: 48
// RVA: 0x15CFF50
void dynamic_initializer_for__hkpKeyframedRigidMotionClass__()
{
  hkClass::hkClass(
    &hkpKeyframedRigidMotionClass,
    "hkpKeyframedRigidMotion",
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
// RVA: 0xD4FD40
hkClass *__fastcall hkpKeyframedRigidMotion::staticClass()
{
  return &hkpKeyframedRigidMotionClass;
}

// File Line: 58
// RVA: 0xD4FD60
void __fastcall finishLoadedObjecthkpKeyframedRigidMotion(void *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpMotion::`vftable;
    if ( finishing )
      *((_WORD *)p + 153) = 16256;
    *(_QWORD *)p = &hkpKeyframedRigidMotion::`vftable;
  }
}

// File Line: 64
// RVA: 0xD4FDA0
void __fastcall cleanupLoadedObjecthkpKeyframedRigidMotion(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 68
// RVA: 0xD4FDB0
void **__fastcall getVtablehkpKeyframedRigidMotion()
{
  return &hkpKeyframedRigidMotion::`vftable;
}

// File Line: 90
// RVA: 0x15CFFB0
void **dynamic_initializer_for__hkpKeyframedRigidMotionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpKeyframedRigidMotion();
  hkpKeyframedRigidMotionTypeInfo.m_size = 320i64;
  hkpKeyframedRigidMotionTypeInfo.m_typeName = "hkpKeyframedRigidMotion";
  hkpKeyframedRigidMotionTypeInfo.m_vtable = result;
  hkpKeyframedRigidMotionTypeInfo.m_scopedName = "!hkpKeyframedRigidMotion";
  hkpKeyframedRigidMotionTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpKeyframedRigidMotion;
  hkpKeyframedRigidMotionTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpKeyframedRigidMotion;
  return result;
}

// File Line: 112
// RVA: 0x15D0010
void dynamic_initializer_for__hkpMaxSizeMotionClass__()
{
  hkClass::hkClass(
    &hkpMaxSizeMotionClass,
    "hkpMaxSizeMotion",
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

// File Line: 115
// RVA: 0xD4FD50
hkClass *__fastcall hkpMaxSizeMotion::staticClass()
{
  return &hkpMaxSizeMotionClass;
}

// File Line: 122
// RVA: 0xD4FDC0
void __fastcall finishLoadedObjecthkpMaxSizeMotion(void *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpMotion::`vftable;
    if ( finishing )
      *((_WORD *)p + 153) = 16256;
    *(_QWORD *)p = &hkpMaxSizeMotion::`vftable;
  }
}

// File Line: 128
// RVA: 0xD4FE00
void __fastcall cleanupLoadedObjecthkpMaxSizeMotion(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 132
// RVA: 0xD4FE10
void **__fastcall getVtablehkpMaxSizeMotion()
{
  return &hkpMaxSizeMotion::`vftable;
}

// File Line: 154
// RVA: 0x15D0070
void **dynamic_initializer_for__hkpMaxSizeMotionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpMaxSizeMotion();
  hkpMaxSizeMotionTypeInfo.m_size = 320i64;
  hkpMaxSizeMotionTypeInfo.m_typeName = "hkpMaxSizeMotion";
  hkpMaxSizeMotionTypeInfo.m_vtable = result;
  hkpMaxSizeMotionTypeInfo.m_scopedName = "!hkpMaxSizeMotion";
  hkpMaxSizeMotionTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpMaxSizeMotion;
  hkpMaxSizeMotionTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpMaxSizeMotion;
  return result;
}

