// File Line: 74
// RVA: 0x15BF670
hkClassEnum *dynamic_initializer_for__hkaSplineCompressedAnimation_TrackCompressionParamsClass_Members__()
{
  hkClassEnum *result; // rax

  unk_1421016F0 = hkaSplineCompressedAnimationTrackCompressionParamsRotationQuantizationEnum;
  result = hkaSplineCompressedAnimationTrackCompressionParamsScalarQuantizationEnum;
  unk_142101718 = hkaSplineCompressedAnimationTrackCompressionParamsScalarQuantizationEnum;
  unk_142101740 = hkaSplineCompressedAnimationTrackCompressionParamsScalarQuantizationEnum;
  unk_142101768 = hkaSplineCompressedAnimationTrackCompressionParamsScalarQuantizationEnum;
  return result;
}

// File Line: 93
// RVA: 0x15BF5A0
void dynamic_initializer_for__hkaSplineCompressedAnimationTrackCompressionParamsClass__()
{
  hkClass::hkClass(
    &hkaSplineCompressedAnimationTrackCompressionParamsClass,
    "hkaSplineCompressedAnimationTrackCompressionParams",
    0i64,
    28,
    0i64,
    0,
    &hkaSplineCompressedAnimationTrackCompressionParamsEnums,
    2,
    &hkaSplineCompressedAnimation_TrackCompressionParamsClass_Members,
    12,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 96
// RVA: 0xB1DD50
hkClass *__fastcall hkaSplineCompressedAnimation::TrackCompressionParams::staticClass()
{
  return &hkaSplineCompressedAnimationTrackCompressionParamsClass;
}

// File Line: 103
// RVA: 0xB1DD70
void __fastcall cleanupLoadedObjecthkaSplineCompressedAnimationTrackCompressionParams(void *p)
{
  ;
}

// File Line: 140
// RVA: 0x15BF4D0
void dynamic_initializer_for__hkaSplineCompressedAnimationAnimationCompressionParamsClass__()
{
  hkClass::hkClass(
    &hkaSplineCompressedAnimationAnimationCompressionParamsClass,
    "hkaSplineCompressedAnimationAnimationCompressionParams",
    0i64,
    4,
    0i64,
    0,
    0i64,
    0,
    &hkaSplineCompressedAnimation_AnimationCompressionParamsClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 143
// RVA: 0xB1DD60
hkClass *__fastcall hkaSplineCompressedAnimation::AnimationCompressionParams::staticClass()
{
  return &hkaSplineCompressedAnimationAnimationCompressionParamsClass;
}

// File Line: 150
// RVA: 0xB1DD80
void __fastcall cleanupLoadedObjecthkaSplineCompressedAnimationAnimationCompressionParams(void *p)
{
  ;
}

// File Line: 200
// RVA: 0x15BF530
void dynamic_initializer_for__hkaSplineCompressedAnimationClass__()
{
  hkClass::hkClass(
    &hkaSplineCompressedAnimationClass,
    "hkaSplineCompressedAnimation",
    &hkaAnimationClass,
    176,
    0i64,
    0,
    0i64,
    0,
    &hkaSplineCompressedAnimation::Members,
    13,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 203
// RVA: 0xB1DD40
hkClass *__fastcall hkaSplineCompressedAnimation::staticClass()
{
  return &hkaSplineCompressedAnimationClass;
}

// File Line: 210
// RVA: 0xB1DD90
void __fastcall finishLoadedObjecthkaSplineCompressedAnimation(void *p, int finishing)
{
  if ( p )
  {
    *(_QWORD *)p = &hkaSplineCompressedAnimation::`vftable;
    JUMPOUT(finishing, 0, hkaSplineCompressedAnimation::handleEndian);
  }
}

// File Line: 216
// RVA: 0xB1DDB0
void __fastcall cleanupLoadedObjecthkaSplineCompressedAnimation(void *p)
{
  (**(void (__fastcall ***)(void *, _QWORD))p)(p, 0i64);
}

// File Line: 220
// RVA: 0xB1DDC0
void **__fastcall getVtablehkaSplineCompressedAnimation()
{
  return &hkaSplineCompressedAnimation::`vftable;
}

// File Line: 242
// RVA: 0x15BF610
void **dynamic_initializer_for__hkaSplineCompressedAnimationTypeInfo__()
{
  void **result; // rax

  result = getVtablehkaSplineCompressedAnimation();
  hkaSplineCompressedAnimationTypeInfo.m_size = 176i64;
  hkaSplineCompressedAnimationTypeInfo.m_typeName = "hkaSplineCompressedAnimation";
  hkaSplineCompressedAnimationTypeInfo.m_vtable = result;
  hkaSplineCompressedAnimationTypeInfo.m_scopedName = "!hkaSplineCompressedAnimation";
  hkaSplineCompressedAnimationTypeInfo.m_finishLoadedObjectFunction = finishLoadedObjecthkaSplineCompressedAnimation;
  hkaSplineCompressedAnimationTypeInfo.m_cleanupLoadedObjectFunction = cleanupLoadedObjecthkaSplineCompressedAnimation;
  return result;
}

