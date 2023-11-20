// File Line: 48
// RVA: 0x15D0770
void dynamic_initializer_for__hkpBoxMotionClass__()
{
  hkClass::hkClass(
    &hkpBoxMotionClass,
    "hkpBoxMotion",
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
// RVA: 0xD500B0
hkClass *__fastcall hkpBoxMotion::staticClass()
{
  return &hkpBoxMotionClass;
}

// File Line: 58
// RVA: 0xD500C0
void __fastcall finishLoadedObjecthkpBoxMotion(void *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpMotion::`vftable;
    if ( finishing )
      *((_WORD *)p + 153) = 16256;
    *(_QWORD *)p = &hkpBoxMotion::`vftable;
  }
}

// File Line: 64
// RVA: 0xD50100
void __fastcall cleanupLoadedObjecthkpBoxMotion(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 68
// RVA: 0xD50110
void **__fastcall getVtablehkpBoxMotion()
{
  return &hkpBoxMotion::`vftable;
}

// File Line: 90
// RVA: 0x15D07D0
void **dynamic_initializer_for__hkpBoxMotionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpBoxMotion();
  hkpBoxMotionTypeInfo.m_size = 320i64;
  hkpBoxMotionTypeInfo.m_typeName = "hkpBoxMotion";
  hkpBoxMotionTypeInfo.m_vtable = result;
  hkpBoxMotionTypeInfo.m_scopedName = "!hkpBoxMotion";
  hkpBoxMotionTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpBoxMotion;
  hkpBoxMotionTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpBoxMotion;
  return result;
}

