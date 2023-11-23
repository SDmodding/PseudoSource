// File Line: 48
// RVA: 0x15D1A00
void dynamic_initializer_for__hkpThinBoxMotionClass__()
{
  hkClass::hkClass(
    &hkpThinBoxMotionClass,
    "hkpThinBoxMotion",
    &hkpBoxMotionClass,
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
// RVA: 0xD51300
hkClass *__fastcall hkpThinBoxMotion::staticClass()
{
  return &hkpThinBoxMotionClass;
}

// File Line: 58
// RVA: 0xD51310
void __fastcall finishLoadedObjecthkpThinBoxMotion(_WORD *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpMotion::`vftable;
    if ( finishing )
      p[153] = 16256;
    *(_QWORD *)p = &hkpThinBoxMotion::`vftable;
  }
}

// File Line: 64
// RVA: 0xD51350
void __fastcall cleanupLoadedObjecthkpThinBoxMotion(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 68
// RVA: 0xD51360
void **__fastcall getVtablehkpThinBoxMotion()
{
  return &hkpThinBoxMotion::`vftable;
}

// File Line: 90
// RVA: 0x15D1A60
void **dynamic_initializer_for__hkpThinBoxMotionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpThinBoxMotion();
  hkpThinBoxMotionTypeInfo.m_size = 320i64;
  hkpThinBoxMotionTypeInfo.m_typeName = "hkpThinBoxMotion";
  hkpThinBoxMotionTypeInfo.m_vtable = result;
  hkpThinBoxMotionTypeInfo.m_scopedName = "!hkpThinBoxMotion";
  hkpThinBoxMotionTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkpThinBoxMotion;
  hkpThinBoxMotionTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkpThinBoxMotion;
  return result;
}

