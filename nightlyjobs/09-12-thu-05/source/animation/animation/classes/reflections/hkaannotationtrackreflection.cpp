// File Line: 53
// RVA: 0x15BF6A0
void dynamic_initializer_for__hkaAnnotationTrackAnnotationClass__()
{
  hkClass::hkClass(
    &hkaAnnotationTrackAnnotationClass,
    "hkaAnnotationTrackAnnotation",
    0i64,
    16,
    0i64,
    0,
    0i64,
    0,
    &hkaAnnotationTrack_AnnotationClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 56
// RVA: 0xB1DE40
hkClass *__fastcall hkaAnnotationTrack::Annotation::staticClass()
{
  return &hkaAnnotationTrackAnnotationClass;
}

// File Line: 63
// RVA: 0xB1DE50
void __fastcall finishLoadedObjecthkaAnnotationTrackAnnotation(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkStringPtr::hkStringPtr(p + 1, finishing);
}

// File Line: 69
// RVA: 0xB1DE70
void __fastcall cleanupLoadedObjecthkaAnnotationTrackAnnotation(hkStringPtr *p)
{
  hkStringPtr::~hkStringPtr(p + 1);
}

// File Line: 106
// RVA: 0x15BF700
void dynamic_initializer_for__hkaAnnotationTrackClass__()
{
  hkClass::hkClass(
    &hkaAnnotationTrackClass,
    "hkaAnnotationTrack",
    0i64,
    24,
    0i64,
    0,
    0i64,
    0,
    &hkaAnnotationTrackClass_Members,
    2,
    0i64,
    0i64,
    0,
    0);
}

// File Line: 109
// RVA: 0xB1DE30
hkClass *__fastcall hkaAnnotationTrack::staticClass()
{
  return &hkaAnnotationTrackClass;
}

// File Line: 116
// RVA: 0xB1DE80
void __fastcall finishLoadedObjecthkaAnnotationTrack(hkStringPtr *p, hkFinishLoadedObjectFlag finishing)
{
  if ( p )
    hkStringPtr::hkStringPtr(p, finishing);
}

// File Line: 122
// RVA: 0xB1DEA0
// attributes: thunk
void __fastcall cleanupLoadedObjecthkaAnnotationTrack(hkaAnnotationTrack *p)
{
  hkaAnnotationTrack::~hkaAnnotationTrack(p);
}

