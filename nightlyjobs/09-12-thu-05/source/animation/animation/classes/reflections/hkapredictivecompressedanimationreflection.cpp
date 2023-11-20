// File Line: 107
// RVA: 0x15BF210
void dynamic_initializer_for__hkaPredictiveCompressedAnimationTrackCompressionParamsClass__()
{
  hkClass::hkClass(
    &hkaPredictiveCompressedAnimationTrackCompressionParamsClass,
    "hkaPredictiveCompressedAnimationTrackCompressionParams",
    0i64,
    32,
    0i64,
    0,
    0i64,
    0,
    &hkaPredictiveCompressedAnimation_TrackCompressionParamsClass_Members,
    8,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 110
// RVA: 0xB1DAF0
hkClass *__fastcall hkaPredictiveCompressedAnimation::TrackCompressionParams::staticClass()
{
  return &hkaPredictiveCompressedAnimationTrackCompressionParamsClass;
}

// File Line: 117
// RVA: 0xB1DB00
void __fastcall cleanupLoadedObjecthkaPredictiveCompressedAnimationTrackCompressionParams(void *p)
{
  ;
}

// File Line: 165
// RVA: 0x15BF190
void dynamic_initializer_for__hkaPredictiveCompressedAnimationClass__()
{
  hkClass::hkClass(
    &hkaPredictiveCompressedAnimationClass,
    "hkaPredictiveCompressedAnimation",
    &hkaAnimationClass,
    192,
    0i64,
    0,
    &hkaPredictiveCompressedAnimationEnums,
    3,
    &hkaPredictiveCompressedAnimation::Members,
    11,
    0i64,
    0i64,
    0,
    1u);
}

// File Line: 168
// RVA: 0xB1DAE0
hkClass *__fastcall hkaPredictiveCompressedAnimation::staticClass()
{
  return &hkaPredictiveCompressedAnimationClass;
}

// File Line: 175
// RVA: 0xB1DB10
void __fastcall finishLoadedObjecthkaPredictiveCompressedAnimation(void *p, int finishing)
{
  JUMPOUT(p, 0i64, hkaPredictiveCompressedAnimation::hkaPredictiveCompressedAnimation);
}

// File Line: 181
// RVA: 0xB1DB30
void __fastcall cleanupLoadedObjecthkaPredictiveCompressedAnimation(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 185
// RVA: 0xB1DB40
hkBaseObjectVtbl *__fastcall getVtablehkaPredictiveCompressedAnimation()
{
  hkaPredictiveCompressedAnimation v1; // [rsp+20h] [rbp-C8h]

  hkaPredictiveCompressedAnimation::hkaPredictiveCompressedAnimation(&v1, 0);
  return v1.vfptr;
}

// File Line: 207
// RVA: 0x15BF270
hkBaseObjectVtbl *dynamic_initializer_for__hkaPredictiveCompressedAnimationTypeInfo__()
{
  hkBaseObjectVtbl *result; // rax

  result = getVtablehkaPredictiveCompressedAnimation();
  hkaPredictiveCompressedAnimationTypeInfo.m_size = 192i64;
  hkaPredictiveCompressedAnimationTypeInfo.m_typeName = "hkaPredictiveCompressedAnimation";
  hkaPredictiveCompressedAnimationTypeInfo.m_vtable = result;
  hkaPredictiveCompressedAnimationTypeInfo.m_scopedName = "!hkaPredictiveCompressedAnimation";
  hkaPredictiveCompressedAnimationTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaPredictiveCompressedAnimation;
  hkaPredictiveCompressedAnimationTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaPredictiveCompressedAnimation;
  return result;
}

