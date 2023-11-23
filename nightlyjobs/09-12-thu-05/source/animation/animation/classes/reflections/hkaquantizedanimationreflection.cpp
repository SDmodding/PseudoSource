// File Line: 59
// RVA: 0x15BF340
void dynamic_initializer_for__hkaQuantizedAnimationTrackCompressionParamsClass__()
{
  hkClass::hkClass(
    &hkaQuantizedAnimationTrackCompressionParamsClass,
    "hkaQuantizedAnimationTrackCompressionParams",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkaQuantizedAnimation_TrackCompressionParamsClass_Members,
    4,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 62
// RVA: 0xB1DB70
hkClass *__fastcall hkaQuantizedAnimation::TrackCompressionParams::staticClass()
{
  return &hkaQuantizedAnimationTrackCompressionParamsClass;
}

// File Line: 69
// RVA: 0xB1DB80
void __fastcall cleanupLoadedObjecthkaQuantizedAnimationTrackCompressionParams(void *p)
{
  ;
}

// File Line: 109
// RVA: 0x15BF2D0
void dynamic_initializer_for__hkaQuantizedAnimationClass__()
{
  hkClass::hkClass(
    &hkaQuantizedAnimationClass,
    "hkaQuantizedAnimation",
    &hkaAnimationClass,
    88,
    0i64,
    0,
    0i64,
    0,
    &hkaQuantizedAnimation::Members,
    3,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 112
// RVA: 0xB1DB60
hkClass *__fastcall hkaQuantizedAnimation::staticClass()
{
  return &hkaQuantizedAnimationClass;
}

// File Line: 119
// RVA: 0xB1DB90
void __fastcall finishLoadedObjecthkaQuantizedAnimation(hkaQuantizedAnimation *p, int finishing)
{
  if ( p )
  {
    p->vfptr = (hkBaseObjectVtbl *)&hkaQuantizedAnimation::`vftable;
    if ( finishing )
      hkaQuantizedAnimation::handleEndian(p);
  }
}

// File Line: 125
// RVA: 0xB1DBB0
void __fastcall cleanupLoadedObjecthkaQuantizedAnimation(void (__fastcall ***p)(_QWORD, _QWORD))
{
  (**p)(p, 0i64);
}

// File Line: 129
// RVA: 0xB1DBC0
void **__fastcall getVtablehkaQuantizedAnimation()
{
  return &hkaQuantizedAnimation::`vftable;
}

// File Line: 151
// RVA: 0x15BF3A0
void **dynamic_initializer_for__hkaQuantizedAnimationTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaQuantizedAnimation();
  hkaQuantizedAnimationTypeInfo.m_size = 88i64;
  hkaQuantizedAnimationTypeInfo.m_typeName = "hkaQuantizedAnimation";
  hkaQuantizedAnimationTypeInfo.m_vtable = result;
  hkaQuantizedAnimationTypeInfo.m_scopedName = "!hkaQuantizedAnimation";
  hkaQuantizedAnimationTypeInfo.m_finishLoadedObjectFunction = (void (__fastcall *)(void *, int))finishLoadedObjecthkaQuantizedAnimation;
  hkaQuantizedAnimationTypeInfo.m_cleanupLoadedObjectFunction = (void (__fastcall *)(void *))cleanupLoadedObjecthkaQuantizedAnimation;
  return result;
}

