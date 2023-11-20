// File Line: 56
// RVA: 0x15BEEC0
void dynamic_initializer_for__hkaInterleavedUncompressedAnimationClass__()
{
  hkClass::hkClass(
    &hkaInterleavedUncompressedAnimationClass,
    "hkaInterleavedUncompressedAnimation",
    &hkaAnimationClass,
    88,
    0i64,
    0,
    0i64,
    0,
    &hkaInterleavedUncompressedAnimationClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 59
// RVA: 0xB1D580
hkClass *__fastcall hkaInterleavedUncompressedAnimation::staticClass()
{
  return &hkaInterleavedUncompressedAnimationClass;
}

// File Line: 66
// RVA: 0xB1D590
void __fastcall finishLoadedObjecthkaInterleavedUncompressedAnimation(void *p, int finishing)
{
  if ( p )
    *(_QWORD *)p = &hkaInterleavedUncompressedAnimation::`vftable';
}

// File Line: 72
// RVA: 0xB1D5B0
void __fastcall cleanupLoadedObjecthkaInterleavedUncompressedAnimation(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 76
// RVA: 0xB1D5C0
void **__fastcall getVtablehkaInterleavedUncompressedAnimation()
{
  return &hkaInterleavedUncompressedAnimation::`vftable';
}

// File Line: 98
// RVA: 0x15BEF30
void **dynamic_initializer_for__hkaInterleavedUncompressedAnimationTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaInterleavedUncompressedAnimation();
  hkaInterleavedUncompressedAnimationTypeInfo.m_size = 88i64;
  hkaInterleavedUncompressedAnimationTypeInfo.m_typeName = "hkaInterleavedUncompressedAnimation";
  hkaInterleavedUncompressedAnimationTypeInfo.m_vtable = result;
  hkaInterleavedUncompressedAnimationTypeInfo.m_scopedName = "!hkaInterleavedUncompressedAnimation";
  hkaInterleavedUncompressedAnimationTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaInterleavedUncompressedAnimation;
  hkaInterleavedUncompressedAnimationTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaInterleavedUncompressedAnimation;
  return result;
}

