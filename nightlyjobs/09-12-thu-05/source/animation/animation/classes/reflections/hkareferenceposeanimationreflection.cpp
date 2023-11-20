// File Line: 55
// RVA: 0x15BF400
void dynamic_initializer_for__hkaReferencePoseAnimationClass__()
{
  hkClass::hkClass(
    &hkaReferencePoseAnimationClass,
    "hkaReferencePoseAnimation",
    &hkaAnimationClass,
    64,
    0i64,
    0,
    0i64,
    0,
    &hkaReferencePoseAnimation::Members,
    1,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 58
// RVA: 0xB1DC30
hkClass *__fastcall hkaReferencePoseAnimation::staticClass()
{
  return &hkaReferencePoseAnimationClass;
}

// File Line: 65
// RVA: 0xB1DC40
void __fastcall finishLoadedObjecthkaReferencePoseAnimation(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaReferencePoseAnimation::`vftable';
}

// File Line: 71
// RVA: 0xB1DC60
void __fastcall cleanupLoadedObjecthkaReferencePoseAnimation(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 75
// RVA: 0xB1DC70
void **__fastcall getVtablehkaReferencePoseAnimation()
{
  return &hkaReferencePoseAnimation::`vftable';
}

// File Line: 97
// RVA: 0x15BF470
void **dynamic_initializer_for__hkaReferencePoseAnimationTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaReferencePoseAnimation();
  hkaReferencePoseAnimationTypeInfo.m_size = 64i64;
  hkaReferencePoseAnimationTypeInfo.m_typeName = "hkaReferencePoseAnimation";
  hkaReferencePoseAnimationTypeInfo.m_vtable = result;
  hkaReferencePoseAnimationTypeInfo.m_scopedName = "!hkaReferencePoseAnimation";
  hkaReferencePoseAnimationTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaReferencePoseAnimation;
  hkaReferencePoseAnimationTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaReferencePoseAnimation;
  return result;
}

