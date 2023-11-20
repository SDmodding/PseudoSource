// File Line: 61
// RVA: 0x3E2530
BinString *__fastcall SubtitleTrack::Create()
{
  char *v0; // rax
  BinString *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::SubtitleTrack", 0i64, 1u);
  v1 = (BinString *)v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, SubtitleTrack::sClassNameUID);
  v1->mOffset = (__int64)&Track<SubtitleTask>::`vftable';
  v1->mOffset = (__int64)&SubtitleTrack::`vftable';
  v1[7].mOffset = 1i64;
  BinString::Set(v1 + 7, &customWorldMapCaption);
  return v1;
}

// File Line: 91
// RVA: 0x3E24A0
BinString *__fastcall SubtitleGroupTrack::Create()
{
  char *v0; // rax
  BinString *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::SubtitleGroupTrack", 0i64, 1u);
  v1 = (BinString *)v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, SubtitleGroupTrack::sClassNameUID);
  v1->mOffset = (__int64)&Track<SubtitleGroupTask>::`vftable';
  v1->mOffset = (__int64)&SubtitleGroupTrack::`vftable';
  v1[7].mOffset = 1i64;
  BinString::Set(v1 + 7, &customWorldMapCaption);
  return v1;
}

// File Line: 187
// RVA: 0x3E21C0
FastCurtainShowTrack *__fastcall FastCurtainShowTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::FastCurtainShowTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, FastCurtainShowTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<FastCurtainShowTask>::`vftable';
  *(_QWORD *)v1 = &FastCurtainShowTrack::`vftable';
  *((_WORD *)v1 + 28) = 257;
  return (FastCurtainShowTrack *)v1;
}

// File Line: 238
// RVA: 0x3E2140
AudioTrackNIS *__fastcall AudioTrackNIS::Create()
{
  AudioTrackNIS *result; // rax
  AudioTrackNIS *v1; // rbx

  result = (AudioTrackNIS *)UFG::qMemoryPool2::Allocate(
                              &gActionTreeMemoryPool,
                              0x48ui64,
                              "MemberMap::AudioTrackNIS",
                              0i64,
                              1u);
  v1 = result;
  if ( result )
  {
    ITrack::ITrack((ITrack *)&result->vfptr, AudioTrackNIS::sClassNameUID);
    v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AudioTaskNIS>::`vftable';
    v1->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackNIS::`vftable';
    *(_QWORD *)v1->m_audioTagId = 0i64;
    *(_QWORD *)v1->m_audioTagUID = 0i64;
    v1->mMaster = 1;
    result = v1;
  }
  return result;
}

// File Line: 290
// RVA: 0x3E2300
ITrack *__fastcall NISFadeOutTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "MemberMap::NISFadeOutTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, NISFadeOutTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<NISFadeOutTask>::`vftable';
  *(_QWORD *)v1 = &NISFadeOutTrack::`vftable';
  *((_WORD *)v1 + 28) = 0;
  v1[22] = 1;
  *(_QWORD *)(v1 + 60) = 0i64;
  return (ITrack *)v1;
}

// File Line: 346
// RVA: 0x3E2450
void __fastcall NISShadowCascadeTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "MemberMap::NISShadowCascadeTrack", 0i64, 1u);
  if ( v0 )
    NISShadowCascadeTrack::NISShadowCascadeTrack((NISShadowCascadeTrack *)v0);
}

// File Line: 521
// RVA: 0x3E2380
NISLightGroupAnimationTrack *__fastcall NISLightGroupAnimationTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::NISLightGroupAnimationTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, NISLightGroupAnimationTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<NISLightGroupAnimationTask>::`vftable';
  *(_QWORD *)v1 = &NISLightGroupAnimationTrack::`vftable';
  v1[56] = 0;
  return (NISLightGroupAnimationTrack *)v1;
}

// File Line: 558
// RVA: 0x3E2400
void __fastcall NISPlayMovieTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "MemberMap::NISPlayMovieTrack", 0i64, 1u);
  if ( v0 )
    NISPlayMovieTrack::NISPlayMovieTrack((NISPlayMovieTrack *)v0);
}

// File Line: 598
// RVA: 0x3E2290
NISAllowPlayerControlTrack *__fastcall NISAllowPlayerControlTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::NISAllowPlayerControlTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, NISAllowPlayerControlTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<NISAllowPlayerControlTask>::`vftable';
  *(_QWORD *)v1 = &NISAllowPlayerControlTrack::`vftable';
  return (NISAllowPlayerControlTrack *)v1;
}

