// File Line: 48
// RVA: 0x15D0AA0
void dynamic_initializer_for__hkpCharacterMotionClass__()
{
  hkClass::hkClass(
    &hkpCharacterMotionClass,
    "hkpCharacterMotion",
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
// RVA: 0xD50390
hkClass *__fastcall hkpCharacterMotion::staticClass()
{
  return &hkpCharacterMotionClass;
}

// File Line: 58
// RVA: 0xD503A0
void __fastcall finishLoadedObjecthkpCharacterMotion(void *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkpMotion::`vftable;
    if ( finishing )
      *((_WORD *)p + 153) = 16256;
    *(_QWORD *)p = &hkpCharacterMotion::`vftable;
  }
}

// File Line: 64
// RVA: 0xD503E0
void __fastcall cleanupLoadedObjecthkpCharacterMotion(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 68
// RVA: 0xD503F0
void **__fastcall getVtablehkpCharacterMotion()
{
  return &hkpCharacterMotion::`vftable;
}

// File Line: 90
// RVA: 0x15D0B00
void **dynamic_initializer_for__hkpCharacterMotionTypeInfo__()
{
  void **result; // rax

  result = getVtablehkpCharacterMotion();
  hkpCharacterMotionTypeInfo.m_size = 320i64;
  hkpCharacterMotionTypeInfo.m_typeName = "hkpCharacterMotion";
  hkpCharacterMotionTypeInfo.m_vtable = result;
  hkpCharacterMotionTypeInfo.m_scopedName = "!hkpCharacterMotion";
  hkpCharacterMotionTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkpCharacterMotion;
  hkpCharacterMotionTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkpCharacterMotion;
  return result;
}

