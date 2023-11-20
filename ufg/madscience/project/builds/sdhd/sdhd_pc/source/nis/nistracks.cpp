// File Line: 72
// RVA: 0x14D1230
const char *dynamic_initializer_for__sNISTrackFactoryListAction__()
{
  const char *result; // rax

  sNISTrackFactoryListAction[0].mClassName = PrintTrack::sClassName;
  sNISTrackFactoryListAction[1].mClassName = AudioTrackNIS::sClassName;
  sNISTrackFactoryListAction[2].mClassName = AudioTrackSimple::sClassName;
  sNISTrackFactoryListAction[3].mClassName = AudioTrackMusicState::sClassName;
  sNISTrackFactoryListAction[4].mClassName = CameraAnimationTrack::sClassName;
  sNISTrackFactoryListAction[5].mClassName = SkookumTrack::sClassName;
  sNISTrackFactoryListAction[6].mClassName = SubtitleTrack::sClassName;
  sNISTrackFactoryListAction[7].mClassName = SubtitleGroupTrack::sClassName;
  sNISTrackFactoryListAction[8].mClassName = CurtainShowTrack::sClassName;
  sNISTrackFactoryListAction[9].mClassName = FastCurtainShowTrack::sClassName;
  sNISTrackFactoryListAction[10].mClassName = NISFadeOutTrack::sClassName;
  sNISTrackFactoryListAction[11].mClassName = NISLightGroupAnimationTrack::sClassName;
  sNISTrackFactoryListAction[12].mClassName = PlayEffectTrack::sClassName;
  sNISTrackFactoryListAction[13].mClassName = UIScreenTrack::sClassName;
  sNISTrackFactoryListAction[14].mClassName = NISShadowCascadeTrack::sClassName;
  sNISTrackFactoryListAction[15].mClassName = DamageEffectTrack::sClassName;
  sNISTrackFactoryListAction[16].mClassName = NISPlayMovieTrack::sClassName;
  result = NISAllowPlayerControlTrack::sClassName;
  sNISTrackFactoryListAction[17].mClassName = NISAllowPlayerControlTrack::sClassName;
  return result;
}

// File Line: 75
// RVA: 0x14CF140
__int64 dynamic_initializer_for__gNISTrackFactoryAction__()
{
  Expression::MemberMapFactory::MemberMapFactory(&gNISTrackFactoryAction, sNISTrackFactoryListAction, 18);
  return atexit(dynamic_atexit_destructor_for__gNISTrackFactoryAction__);
}

// File Line: 84
// RVA: 0x14CA0E0
__int64 dynamic_initializer_for__SubtitleTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SubtitleTrack", 0xFFFFFFFF);
  SubtitleTrack::sClassNameUID = result;
  return result;
}

// File Line: 114
// RVA: 0x14CA0C0
__int64 dynamic_initializer_for__SubtitleGroupTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SubtitleGroupTrack", 0xFFFFFFFF);
  SubtitleGroupTrack::sClassNameUID = result;
  return result;
}

// File Line: 145
// RVA: 0x14C9EE0
__int64 dynamic_initializer_for__CurtainShowTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CurtainShowTrack", 0xFFFFFFFF);
  CurtainShowTrack::sClassNameUID = result;
  return result;
}

// File Line: 160
// RVA: 0x3DFBE0
void __fastcall CurtainShowTrack::CurtainShowTrack(CurtainShowTrack *this)
{
  CurtainShowTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CurtainShowTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CurtainShowTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&CurtainShowTrack::`vftable';
  *(_WORD *)&v1->mFadeIn = 257;
  v1->mFadeInTime = 1.0;
  v1->mFadeOutTime = 1.0;
}

// File Line: 174
// RVA: 0x14C9F00
__int64 dynamic_initializer_for__FastCurtainShowTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FastCurtainShowTrack", 0xFFFFFFFF);
  FastCurtainShowTrack::sClassNameUID = result;
  return result;
}

// File Line: 282
// RVA: 0x14C9EC0
__int64 dynamic_initializer_for__AudioTrackNIS::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AudioTrackNIS", 0xFFFFFFFF);
  AudioTrackNIS::sClassNameUID = result;
  return result;
}

// File Line: 331
// RVA: 0x14CA020
__int64 dynamic_initializer_for__NISFadeOutTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NISFadeOutTrack", 0xFFFFFFFF);
  NISFadeOutTrack::sClassNameUID = result;
  return result;
}

// File Line: 386
// RVA: 0x14CA0A0
__int64 dynamic_initializer_for__NISShadowCascadeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NISShadowCascadeTrack", 0xFFFFFFFF);
  NISShadowCascadeTrack::sClassNameUID = result;
  return result;
}

// File Line: 399
// RVA: 0x3E05F0
void __fastcall NISShadowCascadeTrack::NISShadowCascadeTrack(NISShadowCascadeTrack *this)
{
  NISShadowCascadeTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, NISShadowCascadeTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<NISShadowCascadeTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&NISShadowCascadeTrack::`vftable';
  v1->mCascade0 = -1.0;
  v1->mCascade1 = -1.0;
  v1->mCascade2 = -1.0;
  v1->mBias0 = -1.0;
  v1->mBias1 = -1.0;
  v1->mBias2 = -1.0;
}

// File Line: 415
// RVA: 0x14C9E80
__int64 dynamic_initializer_for__ActorAttachTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActorAttachTrack", 0xFFFFFFFF);
  ActorAttachTrack::sClassNameUID = result;
  return result;
}

// File Line: 428
// RVA: 0x3DFAC0
void __fastcall ActorAttachTrack::ActorAttachTrack(ActorAttachTrack *this)
{
  ActorAttachTrack *v1; // rbx
  UFG::qSymbolUC result; // [rsp+48h] [rbp+10h]

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, ActorAttachTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<ActorAttachTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&ActorAttachTrack::`vftable';
  v1->mActorID.mUID = -1;
  v1->mAttachToActor = 0;
  v1->mBlendInTime = 0.0;
  *(_QWORD *)&v1->mAttachJointName.mUID = -1i64;
  v1->mAttachJointName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "none")->mUID;
  v1->mActorAttachJointName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "none")->mUID;
}

// File Line: 446
// RVA: 0x14C9EA0
__int64 dynamic_initializer_for__ActorDetachTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActorDetachTrack", 0xFFFFFFFF);
  ActorDetachTrack::sClassNameUID = result;
  return result;
}

// File Line: 461
// RVA: 0x3DFB50
void __fastcall ActorDetachTrack::ActorDetachTrack(ActorDetachTrack *this)
{
  ActorDetachTrack *v1; // rbx
  UFG::qSymbolUC result; // [rsp+48h] [rbp+10h]

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, ActorDetachTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<ActorDetachTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&ActorDetachTrack::`vftable';
  v1->mActorID.mUID = -1;
  *(_WORD *)&v1->mDetachFromActor = 256;
  v1->mBlendOutTime = 0.0;
  *(_QWORD *)&v1->mAttachJointName.mUID = -1i64;
  v1->mAttachJointName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "none")->mUID;
  v1->mActorAttachJointName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "none")->mUID;
}

// File Line: 481
// RVA: 0x14CF080
__int64 dynamic_initializer_for__gLGAPlayModeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gLGAPlayModeEnum, gLGAPlayModeStringList, 3, 0i64);
  return atexit(dynamic_atexit_destructor_for__gLGAPlayModeEnum__);
}

// File Line: 483
// RVA: 0x14CA040
__int64 dynamic_initializer_for__NISLightGroupAnimationTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NISLightGroupAnimationTrack", 0xFFFFFFFF);
  NISLightGroupAnimationTrack::sClassNameUID = result;
  return result;
}

// File Line: 497
// RVA: 0x3E0B40
void __fastcall NISLightGroupAnimationTrack::~NISLightGroupAnimationTrack(NISLightGroupAnimationTrack *this)
{
  NISLightGroupAnimationTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&NISLightGroupAnimationTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 511
// RVA: 0x14CA080
__int64 dynamic_initializer_for__NISPlayMovieTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NISPlayMovieTrack", 0xFFFFFFFF);
  NISPlayMovieTrack::sClassNameUID = result;
  return result;
}

// File Line: 525
// RVA: 0x3E0590
void __fastcall NISPlayMovieTrack::NISPlayMovieTrack(NISPlayMovieTrack *this)
{
  NISPlayMovieTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, NISPlayMovieTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<NISPlayMovieTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&NISPlayMovieTrack::`vftable';
  v1->mMovieFilename.mOffset = 1i64;
  BinString::Set(&v1->mMovieFilename, &customWorldMapCaption);
  *(_WORD *)&v1->mPauseSound = 1;
}

// File Line: 540
// RVA: 0x14CA000
__int64 dynamic_initializer_for__NISAllowPlayerControlTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NISAllowPlayerControlTrack", 0xFFFFFFFF);
  NISAllowPlayerControlTrack::sClassNameUID = result;
  return result;
}

// File Line: 565
// RVA: 0x3E2010
void __fastcall SubtitleTask::Begin(SubtitleTask *this, ActionContext *context)
{
  SubtitleTask *v2; // rbx
  ITrack *v3; // rdx
  const char *v4; // rdx
  float v5; // xmm6_4
  UFG::allocator::free_link *v6; // rax
  UFG::UISubtitleMessage *v7; // rax
  UFG::UISubtitleMessage *v8; // rbx
  UFG::UIHKTextOverlay *v9; // rax
  UFG::qString v10; // [rsp+28h] [rbp-70h]
  UFG::qString v11; // [rsp+50h] [rbp-48h]

  v2 = this;
  v3 = this->m_Track;
  if ( (_QWORD)v3[1].vfptr & 0xFFFFFFFFFFFFFFFEui64 )
    v4 = (char *)&v3[1] + ((_QWORD)v3[1].vfptr & 0xFFFFFFFFFFFFFFFEui64);
  else
    v4 = BinString::sEmptyString;
  UFG::qString::qString(&v11, v4);
  v5 = v2->m_Track->mTimeEnd - v2->m_Track->mTimeBegin;
  UFG::qString::qString(&v10, "Red");
  if ( v5 < 0.0 )
    v5 = FLOAT_120_0;
  v6 = UFG::qMalloc(0xD0ui64, "UISubtitleMessage", 0i64);
  if ( v6 )
  {
    UFG::UISubtitleMessage::UISubtitleMessage((UFG::UISubtitleMessage *)v6, 0, v11.mData, 0i64);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  v8->lifetime = v5;
  UFG::qString::Set(&v8->color, v10.mData);
  v9 = UFG::UIHKTextOverlay::getInstance();
  if ( v9 )
    UFG::UIHKTextOverlay::QueueMessage(v9, v8);
  UFG::qString::~qString(&v10);
  UFG::qString::~qString(&v11);
}

// File Line: 600
// RVA: 0x3E1FC0
void __fastcall SubtitleGroupTask::Begin(SubtitleGroupTask *this, ActionContext *context)
{
  ITrack *v2; // rdx
  const char *v3; // rdx
  UFG::qString v4; // [rsp+28h] [rbp-30h]

  v2 = this->m_Track;
  if ( (_QWORD)v2[1].vfptr & 0xFFFFFFFFFFFFFFFEui64 )
    v3 = (char *)&v2[1] + ((_QWORD)v2[1].vfptr & 0xFFFFFFFFFFFFFFFEui64);
  else
    v3 = BinString::sEmptyString;
  UFG::qString::qString(&v4, v3);
  UFG::qString::~qString(&v4);
}

// File Line: 614
// RVA: 0x3E28C0
void __fastcall SubtitleGroupTask::End(SubtitleTask *this)
{
  UFG::UIHKTextOverlay *v1; // rax

  v1 = UFG::UIHKTextOverlay::getInstance();
  if ( v1 )
    UFG::UIHKTextOverlay::StopAllSubtitles(v1, 1);
}

// File Line: 627
// RVA: 0x3E1AE0
void __fastcall CurtainShowTask::Begin(CurtainShowTask *this, ActionContext *context)
{
  ITrack *v2; // r8
  bool v3; // dl
  bool v4; // zf

  v2 = this->m_Track;
  this->mDuration = v2->mTimeEnd - v2->mTimeBegin;
  v3 = LOBYTE(v2[1].vfptr) != 0;
  this->mFadeIn = v3;
  v4 = BYTE1(v2[1].vfptr) == 0;
  this->mTimeRemaining = 0.0;
  this->mFadeOut = !v4;
  if ( v3 )
    UFG::UIHK_NISOverlay::ShowCurtains(*((float *)&v2[1].vfptr + 1), 0);
  else
    UFG::UIHK_NISOverlay::ShowCurtains(0.0, 0);
}

// File Line: 641
// RVA: 0x3E6650
bool __fastcall CurtainShowTask::Update(FastCurtainShowTask *this, float timeDelta)
{
  FastCurtainShowTask *v2; // rbx
  float v3; // xmm2_4
  bool result; // al

  v2 = this;
  result = 0;
  if ( UFG::UIHK_NISOverlay::IsCurtainStable() )
  {
    v3 = v2->mTimeRemaining - timeDelta;
    v2->mTimeRemaining = v3;
    if ( v3 <= 0.0 )
      result = 1;
  }
  return result;
}

// File Line: 654
// RVA: 0x3E2760
void __fastcall CurtainShowTask::End(CurtainShowTask *this)
{
  float v1; // xmm0_4

  v1 = 0.0;
  if ( this->mDuration > 0.0 )
  {
    if ( this->mFadeOut )
      v1 = *(float *)&this->m_Track[1].mResourceOwner;
    UFG::UIHK_NISOverlay::HideCurtains(v1, 0);
  }
}

// File Line: 666
// RVA: 0x3E1B30
void __fastcall FastCurtainShowTask::Begin(FastCurtainShowTask *this, ActionContext *context)
{
  ITrack *v2; // rax
  bool v3; // dl
  bool v4; // zf

  v2 = this->m_Track;
  this->mDuration = v2->mTimeEnd - v2->mTimeBegin;
  v3 = LOBYTE(v2[1].vfptr) != 0;
  this->mFadeIn = v3;
  v4 = BYTE1(v2[1].vfptr) == 0;
  this->mTimeRemaining = 0.0;
  this->mFadeOut = !v4;
  if ( v3 )
    UFG::UIHK_NISOverlay::ShowCurtains(0.33000001, 0);
  else
    UFG::UIHK_NISOverlay::ShowCurtains(0.0, 0);
}

// File Line: 692
// RVA: 0x3E2790
void __fastcall FastCurtainShowTask::End(FastCurtainShowTask *this)
{
  float v1; // xmm0_4

  v1 = 0.0;
  if ( this->mDuration > 0.0 )
  {
    if ( this->mFadeOut )
      v1 = FLOAT_0_33000001;
    UFG::UIHK_NISOverlay::HideCurtains(v1, 0);
  }
}

// File Line: 703
// RVA: 0x3E1AA0
void __fastcall AudioTaskNIS::Begin(AudioTaskNIS *this, ActionContext *context)
{
  UFG::NISAudio *v2; // rax
  unsigned int v3; // edx

  this->mContext = context;
  v2 = UFG::NISAudio::m_instance;
  this->m_hasStarted = 0;
  this->m_nisAudio = v2;
  this->m_lastElapsedTime = 0.0;
  this->m_playDelay = 0.0;
  v3 = (unsigned int)this->m_Track[1].mResourceOwner;
  if ( v3 )
    UFG::NISAudio::Play(this->m_nisAudio, v3, 0i64);
}

// File Line: 717
// RVA: 0x3E65F0
char __fastcall AudioTaskNIS::Update(AudioTaskNIS *this, float timeDelta)
{
  UFG::AudioEventController *v2; // rax
  char result; // al
  float v4; // xmm0_4

  v2 = &this->m_nisAudio->m_controller;
  if ( v2->m_pEvent )
    result = (*((_BYTE *)v2->m_pEvent + 144) >> 6) & 1;
  else
    result = 0;
  if ( !this->m_hasStarted )
  {
    if ( result || (v4 = this->m_playDelay, v4 >= 0.75) )
    {
      if ( this->m_playDelay > 0.75 )
        result = 0;
    }
    else
    {
      result = 1;
      this->m_playDelay = v4 + timeDelta;
    }
  }
  return result;
}

// File Line: 740
// RVA: 0x3E26C0
void __fastcall AudioTaskNIS::End(AudioTaskNIS *this)
{
  AudioTaskNIS *v1; // rbx
  UFG::NISAudio *v2; // rcx
  UFG::AudioEvent *v3; // rax
  UFG::AudioEvent *v4; // rcx
  UFG::OneShotHandle pHandle; // [rsp+40h] [rbp+8h]

  v1 = this;
  v2 = this->m_nisAudio;
  v3 = v2->m_controller.m_pEvent;
  if ( v3 )
  {
    if ( (*((_BYTE *)v3 + 144) >> 6) & 1 )
    {
      v4 = v2->m_controller.m_pEvent;
      if ( v4 )
        UFG::AudioEvent::StopAndForget(v4, 0x64u);
    }
  }
  if ( HIDWORD(v1->m_Track[1].mResourceOwner) )
  {
    pHandle.m_pOneShot = 0i64;
    UFG::OneShotPool::GetOneShotHandle(&pHandle, &UFG::qMatrix44::msIdentity);
    if ( UFG::OneShotHandle::IsValid(&pHandle) )
      UFG::OneShot::Play(pHandle.m_pOneShot, HIDWORD(v1->m_Track[1].mResourceOwner));
    UFG::OneShotHandle::Release(&pHandle);
  }
}

// File Line: 757
// RVA: 0x3E2CC0
float __fastcall AudioTaskNIS::GetElapsedTime(AudioTaskNIS *this)
{
  AudioTaskNIS *v1; // rbx
  UFG::AudioEvent *v2; // rcx
  float result; // xmm0_4

  v1 = this;
  v2 = this->m_nisAudio->m_controller.m_pEvent;
  if ( !v2 )
    return v1->m_lastElapsedTime;
  if ( !((*((_BYTE *)v2 + 144) >> 6) & 1) )
    return v1->m_lastElapsedTime;
  result = UFG::AudioEvent::GetElapsedTime(v2);
  if ( result <= 0.0 )
    return v1->m_lastElapsedTime;
  v1->m_lastElapsedTime = result;
  v1->m_hasStarted = 1;
  return result;
}

// File Line: 795
// RVA: 0x3E1BA0
void __fastcall NISFadeOutTask::Begin(NISFadeOutTask *this, ActionContext *context)
{
  ITrack *v2; // rax
  unsigned int v3; // ebx
  bool v4; // cl
  float v5; // xmm0_4
  UFG::OneShotHandle pHandle; // [rsp+40h] [rbp+8h]

  v2 = this->m_Track;
  v3 = (unsigned int)v2[1].mResourceOwner;
  v4 = 1;
  if ( v3 )
    v4 = 0;
  if ( LOBYTE(v2[1].vfptr) )
    v5 = 0.0;
  else
    v5 = FLOAT_0_33000001;
  UFG::UIHK_NISOverlay::ShowCurtains(v5, v4);
  if ( v3 )
  {
    pHandle.m_pOneShot = 0i64;
    UFG::OneShotPool::GetOneShotHandle(&pHandle, &UFG::qMatrix44::msIdentity);
    if ( UFG::OneShotHandle::IsValid(&pHandle) )
      UFG::OneShot::Play(pHandle.m_pOneShot, v3);
    UFG::OneShotHandle::Release(&pHandle);
  }
}

// File Line: 825
// RVA: 0x3E6770
bool __fastcall NISFadeOutTask::Update(NISFadeOutTask *this, float timeDelta)
{
  bool result; // al

  if ( LOBYTE(this->m_Track[1].vfptr) )
    result = 0;
  else
    result = UFG::UIHK_NISOverlay::IsCurtainHidden();
  return result;
}

// File Line: 837
// RVA: 0x3E27D0
void __fastcall NISFadeOutTask::End(NISFadeOutTask *this)
{
  JUMPOUT(BYTE1(this->m_Track[1].vfptr), 0, UFG::UIHK_NISOverlay::HideLetterBox);
}

// File Line: 884
// RVA: 0x3E18C0
void __fastcall SequenceTask::Begin(SequenceTask *this, ActionContext *context)
{
  this->mContext = context;
}

// File Line: 889
// RVA: 0x3E63F0
char __fastcall ActorAttachTask::Update(ActorAttachTask *this, float timeDelta)
{
  ActorAttachTask *v2; // r13
  UFG::SimObjectCVBase *v3; // rbp
  UFG::qSymbol *v4; // rax
  UFG::qBaseNodeRB *v5; // rax
  ITrack *v6; // rcx
  unsigned int v7; // ebx
  unsigned int v8; // edi
  UFG::SimObjectCVBase *v9; // r14
  UFG::CharacterAnimationComponent *v10; // rsi
  UFG::CharacterAnimationComponent *v11; // r15
  unsigned __int16 v12; // cx
  UFG::CharacterAnimationComponent *v13; // rax
  unsigned __int16 v14; // cx
  UFG::CharacterAnimationComponent *v15; // rax
  Creature *v16; // r15
  Creature *v17; // rsi
  int attachmentBoneID; // er12
  int v19; // ebx
  UFG::qWiseSymbol result; // [rsp+70h] [rbp+8h]

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  v4 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, (unsigned int)this->m_Track[1].vfptr);
  v5 = UFG::Simulation::GetSimObject(&UFG::gSim, v4);
  if ( !v5 )
    return 1;
  v6 = v2->m_Track;
  if ( BYTE4(v6[1].vfptr) )
  {
    v7 = v6[1].m_TrackClassNameUID;
    v8 = HIDWORD(v6[1].mResourceOwner);
    v9 = (UFG::SimObjectCVBase *)v5;
  }
  else
  {
    v7 = HIDWORD(v6[1].mResourceOwner);
    v8 = v6[1].m_TrackClassNameUID;
    v9 = v3;
    v3 = (UFG::SimObjectCVBase *)v5;
  }
  v10 = 0i64;
  if ( v9 )
  {
    v12 = v9->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v13 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
      {
        v13 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v9);
      }
      else if ( (v12 >> 12) & 1 )
      {
        v13 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v9->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v13 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v9->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v13 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
    }
    v11 = v13;
  }
  else
  {
    v11 = 0i64;
  }
  if ( v3 )
  {
    v14 = v3->m_Flags;
    if ( (v14 >> 14) & 1 )
    {
      v15 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    }
    else if ( (v14 & 0x8000u) == 0 )
    {
      if ( (v14 >> 13) & 1 )
      {
        v15 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v3);
      }
      else if ( (v14 >> 12) & 1 )
      {
        v15 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&v3->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v15 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v3->vfptr,
                                                    UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v15 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    }
    v10 = v15;
  }
  if ( !v11 )
    return 1;
  if ( !v10 )
    return 1;
  v16 = v11->mCreature;
  v17 = v10->mCreature;
  if ( !v16 || !v17 )
    return 1;
  attachmentBoneID = -1;
  if ( v16->mPose.mRigHandle.mData )
    v19 = Skeleton::GetBoneID(v16->mPose.mRigHandle.mUFGSkeleton, v7);
  else
    v19 = -1;
  if ( v17->mPose.mRigHandle.mData )
    attachmentBoneID = Skeleton::GetBoneID(v17->mPose.mRigHandle.mUFGSkeleton, v8);
  Creature::AddAttachment(
    v16,
    (UFG::SimObject *)&v9->vfptr,
    v19,
    (UFG::SimObject *)&v3->vfptr,
    attachmentBoneID,
    0,
    *(float *)&v2->m_Track[1].mResourceOwner);
  return 0;
}

// File Line: 945
// RVA: 0x3E18D0
void __fastcall ActorDetachTask::Begin(ActorDetachTask *this, ActionContext *context)
{
  UFG::SimObjectCVBase *v2; // rsi
  ActorDetachTask *v3; // r15
  UFG::qSymbol *v4; // rax
  UFG::qBaseNodeRB *v5; // rax
  ITrack *v6; // rcx
  unsigned int v7; // ebx
  UFG::SimObjectCVBase *v8; // rbp
  UFG::CharacterAnimationComponent *v9; // rdi
  UFG::CharacterAnimationComponent *v10; // r14
  unsigned __int16 v11; // cx
  UFG::CharacterAnimationComponent *v12; // rax
  unsigned __int16 v13; // cx
  UFG::CharacterAnimationComponent *v14; // rax
  Creature *v15; // r14
  Creature *v16; // rdi
  int v17; // eax
  __int64 v18; // rdx
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h]

  v2 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v3 = this;
  v4 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, (unsigned int)this->m_Track[1].vfptr);
  v5 = UFG::Simulation::GetSimObject(&UFG::gSim, v4);
  if ( v5 )
  {
    v6 = v3->m_Track;
    if ( BYTE4(v6[1].vfptr) )
    {
      v7 = v6[1].m_TrackClassNameUID;
      v8 = (UFG::SimObjectCVBase *)v5;
    }
    else
    {
      v7 = HIDWORD(v6[1].mResourceOwner);
      v8 = v2;
      v2 = (UFG::SimObjectCVBase *)v5;
    }
    v9 = 0i64;
    if ( v8 )
    {
      v11 = v8->m_Flags;
      if ( (v11 >> 14) & 1 )
      {
        v12 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
      }
      else if ( (v11 & 0x8000u) == 0 )
      {
        if ( (v11 >> 13) & 1 )
        {
          v12 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v8);
        }
        else if ( (v11 >> 12) & 1 )
        {
          v12 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v8->vfptr,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
        else
        {
          v12 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v8->vfptr,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v12 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
      }
      v10 = v12;
    }
    else
    {
      v10 = 0i64;
    }
    if ( v2 )
    {
      v13 = v2->m_Flags;
      if ( (v13 >> 14) & 1 )
      {
        v14 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v2);
      }
      else if ( (v13 & 0x8000u) == 0 )
      {
        if ( (v13 >> 13) & 1 )
        {
          v14 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v2);
        }
        else if ( (v13 >> 12) & 1 )
        {
          v14 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      (UFG::SimObjectGame *)&v2->vfptr,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
        else
        {
          v14 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v2->vfptr,
                                                      UFG::CharacterAnimationComponent::_TypeUID);
        }
      }
      else
      {
        v14 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v2);
      }
      v9 = v14;
    }
    if ( v10 )
    {
      if ( v9 )
      {
        v15 = v10->mCreature;
        v16 = v9->mCreature;
        if ( v15 )
        {
          if ( v16 )
          {
            if ( v15->mPose.mRigHandle.mData )
              v17 = Skeleton::GetBoneID(v15->mPose.mRigHandle.mUFGSkeleton, v7);
            else
              v17 = -1;
            if ( Creature::RemoveAttachment(v15, (UFG::SimObject *)&v8->vfptr, v17, (UFG::SimObject *)&v2->vfptr) )
            {
              if ( BYTE5(v3->m_Track[1].vfptr) )
                Creature::MakeUpright(v16, 0.0, v18);
            }
          }
        }
      }
    }
  }
}

// File Line: 1005
// RVA: 0x3E0160
void __fastcall NISLightGroupAnimationTask::NISLightGroupAnimationTask(NISLightGroupAnimationTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<PoseNode,PoseNode> *v2; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<NISLightGroupAnimationTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&NISLightGroupAnimationTask::`vftable';
  v2 = &this->mController;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mController.m_pPointer = 0i64;
}

// File Line: 1009
// RVA: 0x3E0AB0
void __fastcall NISLightGroupAnimationTask::~NISLightGroupAnimationTask(NISLightGroupAnimationTask *this)
{
  NISLightGroupAnimationTask *v1; // r8
  UFG::qSafePointer<PoseNode,PoseNode> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&NISLightGroupAnimationTask::`vftable';
  v2 = &this->mController;
  if ( this->mController.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 1013
// RVA: 0x3E1C30
void __fastcall NISLightGroupAnimationTask::Begin(NISLightGroupAnimationTask *this, ActionContext *context)
{
  NISLightGroupAnimationTask *v2; // rdi
  NISInstance *v3; // rbx
  UFG::SimObject *v4; // rcx
  UFG::SimComponent *v5; // rsi
  const char *v6; // r8
  Creature *v7; // rcx
  PoseNode *v8; // rax
  UFG::qSafePointer<PoseNode,PoseNode> *v9; // r8
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qList<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList,1,0> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qSafePointer<PoseNode,PoseNode> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v16; // rax
  PoseNode *v17; // rcx
  UFG::qString v18; // [rsp+48h] [rbp-30h]
  int returnCode; // [rsp+90h] [rbp+18h]
  UFG::qSymbolUC result; // [rsp+98h] [rbp+20h]

  v2 = this;
  v3 = NISManager::sInstance->mpActiveInstance.m_pPointer;
  if ( v3 )
    v3 = (NISInstance *)v3->mpNISNode;
  v4 = v3->mFacialAnimGroupHandle.m_pReferenceInfo[1].m_pSimObject;
  if ( v4 )
  {
    v5 = UFG::SimObject::GetComponentOfType(v4, UFG::LightGroupAnimationComponent::_TypeUID);
    if ( v5 )
    {
      UFG::qString::qString(&v18);
      if ( (_QWORD)v3->mFacialAnimGroupHandle.m_AnimationGroup.m_pPointer & 0xFFFFFFFFFFFFFFFEui64 )
        v6 = (char *)&v3->mFacialAnimGroupHandle.m_AnimationGroup.m_pPointer
           + ((_QWORD)v3->mFacialAnimGroupHandle.m_AnimationGroup.m_pPointer & 0xFFFFFFFFFFFFFFFEui64);
      else
        v6 = BinString::sEmptyString;
      UFG::qString::Format(&v18, "NIS_%s_LIGHT", v6);
      UFG::qSymbolUC::create_from_string(&result, v18.mData);
      returnCode = 0;
      v7 = *(Creature **)&v5[2].m_TypeUID;
      if ( v7 )
      {
        v8 = Creature::PlayAnimation(v7, &result, APM_CYCLIC, 0.0, -1.0, 0.0, 0, &returnCode);
        v9 = &v2->mController;
        if ( v2->mController.m_pPointer )
        {
          v10 = v9->mPrev;
          v11 = v2->mController.mNext;
          v10->mNext = v11;
          v11->mPrev = v10;
          v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v9->mPrev;
          v2->mController.mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mController.mPrev;
        }
        v2->mController.m_pPointer = v8;
        if ( v8 )
        {
          v12 = &v8->m_SafePointerList;
          v13 = v8->m_SafePointerList.mNode.mPrev;
          v13->mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v9->mPrev;
          v9->mPrev = v13;
          v2->mController.mNext = &v12->mNode;
          v12->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v9->mPrev;
        }
      }
      else
      {
        v14 = &v2->mController;
        if ( v2->mController.m_pPointer )
        {
          v15 = v14->mPrev;
          v16 = v2->mController.mNext;
          v15->mNext = v16;
          v16->mPrev = v15;
          v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v14->mPrev;
          v2->mController.mNext = (UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *)&v2->mController.mPrev;
        }
        v2->mController.m_pPointer = 0i64;
      }
      v17 = v2->mController.m_pPointer;
      if ( v17 )
        v17->vfptr[2].FindWithOldPath((Expression::IMemberMap *)&v17->vfptr, (const char *)LOBYTE(v2->m_Track[1].vfptr));
      UFG::qString::~qString(&v18);
    }
  }
}

// File Line: 1047
// RVA: 0x3E6790
bool __fastcall NISLightGroupAnimationTask::Update(NISLightGroupAnimationTask *this, float timeDelta)
{
  NISLightGroupAnimationTask *v2; // rdi
  PoseNode *v3; // rcx
  int v4; // ebx
  bool result; // al

  v2 = this;
  v3 = this->mController.m_pPointer;
  if ( !v3 )
    return 0;
  v4 = LOBYTE(v2->m_Track[1].vfptr);
  result = 1;
  if ( v4 != 1 && v4 != 6 )
  {
    if ( ((unsigned __int8 (*)(void))v3->vfptr[1].SetResourceOwner)() )
    {
      ((void (*)(void))v2->mController.m_pPointer->vfptr[1].GetResourceOwner)();
      if ( v4 != 2 )
        result = 0;
    }
  }
  return result;
}

// File Line: 1082
// RVA: 0x3E0540
void __fastcall NISPlayMovieTask::NISPlayMovieTask(NISPlayMovieTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<NISPlayMovieTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&NISPlayMovieTask::`vftable';
  this->mPlayer = 0i64;
}

// File Line: 1086
// RVA: 0x3E1DD0
void __fastcall NISPlayMovieTask::Begin(NISPlayMovieTask *this, ActionContext *context)
{
  NISPlayMovieTask *v2; // rsi
  ITrack *v3; // rdx
  const char *v4; // rdi
  UFG::GameStatTracker *v5; // rax
  float v6; // xmm6_4
  ITrack *v7; // rax
  UFG::MoviePlayer *i; // rbx
  UFG::MoviePlayer *v9; // rbx
  UFG::allocator::free_link *v10; // rax
  UFG::MoviePlayer *v11; // rax
  NISManager *v12; // rbx

  v2 = this;
  v3 = this->m_Track;
  if ( (_QWORD)v3[1].vfptr & 0xFFFFFFFFFFFFFFFEui64 )
    v4 = (char *)&v3[1] + ((_QWORD)v3[1].vfptr & 0xFFFFFFFFFFFFFFFEui64);
  else
    v4 = BinString::sEmptyString;
  if ( v4 && (unsigned int)UFG::qStringLength(v4) )
  {
    v5 = UFG::GameStatTracker::Instance();
    v6 = (float)(signed int)UFG::GameStatTracker::GetStat(v5, VolumeSFX) * 2000.0;
    v7 = v2->m_Track;
    if ( BYTE1(v7[1].mResourceOwner) )
    {
      UFG::qMutex::Lock(&stru_142042A80);
      for ( i = off_142042A68; i != (UFG::MoviePlayer *)&UFG::TheMovieHandler; i = (UFG::MoviePlayer *)i->mNext )
      {
        if ( i->mFlags & 0x10 && !(unsigned int)UFG::qStringCompareInsensitive(v4, i->mFilename, -1) )
        {
          v2->mPlayer = i;
          UFG::MoviePlayer::PlayFromStart(i, 0);
          UFG::MoviePlayer::SetAudioVolume(v2->mPlayer, 0, (signed int)v6);
          break;
        }
      }
      UFG::qMutex::Unlock(&stru_142042A80);
    }
    else
    {
      v9 = 0i64;
      if ( LOBYTE(v7[1].mResourceOwner) )
      {
        if ( !(_S8_9 & 1) )
        {
          _S8_9 |= 1u;
          UFG::qWiseSymbol::create_from_string(&insta_pause, "insta_pause");
          atexit(NISPlayMovieTask::Begin_::_18_::_dynamic_atexit_destructor_for__insta_pause__);
        }
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
          insta_pause.mUID,
          0i64,
          0,
          0i64);
      }
      UFG::RenderWorld::SetRenderWorld(0);
      v10 = UFG::qMalloc(0x58ui64, "NISPlayMovieTask.mPlayer", 0i64);
      if ( v10 )
      {
        UFG::MoviePlayer::MoviePlayer((UFG::MoviePlayer *)v10);
        v9 = v11;
      }
      v2->mPlayer = v9;
      UFG::MoviePlayer::Init(v9, v4, 0i64, 0);
      UFG::MoviePlayer::SetAudioVolume(v2->mPlayer, 0, (signed int)v6);
      v12 = NISManager::sInstance;
      if ( !NISManager::sInstance->mHudDisableCount )
        UFG::UIHK_NISOverlay::ShowLetterBox();
      ++v12->mHudDisableCount;
    }
  }
}

// File Line: 1129
// RVA: 0x3E6920
bool __fastcall NISPlayMovieTask::Update(NISPlayMovieTask *this, float timeDelta)
{
  UFG::MoviePlayer *v2; // rax

  v2 = this->mPlayer;
  return v2 && !(v2->mFlags & 1);
}

// File Line: 1134
// RVA: 0x3E27E0
void __fastcall NISPlayMovieTask::End(NISPlayMovieTask *this)
{
  NISPlayMovieTask *v1; // rbx
  NISManager *v2; // rax
  UFG::MoviePlayer *v3; // rdi

  v1 = this;
  if ( BYTE1(this->m_Track[1].mResourceOwner) || !this->mPlayer )
  {
    this->mPlayer = 0i64;
  }
  else
  {
    v2 = NISManager::sInstance;
    if ( !--v2->mHudDisableCount )
      UFG::UIHK_NISOverlay::HideLetterBox();
    v3 = v1->mPlayer;
    if ( v3 )
    {
      UFG::MoviePlayer::~MoviePlayer(v1->mPlayer);
      operator delete[](v3);
    }
    if ( LOBYTE(v1->m_Track[1].mResourceOwner) )
    {
      if ( !(_S9_9 & 1) )
      {
        _S9_9 |= 1u;
        UFG::qWiseSymbol::create_from_string(&insta_resume, "insta_resume");
        atexit(NISPlayMovieTask::End_::_11_::_dynamic_atexit_destructor_for__insta_resume__);
      }
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
        insta_resume.mUID,
        0i64,
        0,
        0i64);
    }
    UFG::RenderWorld::SetRenderWorld(1);
    v1->mPlayer = 0i64;
  }
}

// File Line: 1157
// RVA: 0x3DFE60
void __fastcall NISAllowPlayerControlTask::NISAllowPlayerControlTask(NISAllowPlayerControlTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<NISAllowPlayerControlTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&NISAllowPlayerControlTask::`vftable';
}

// File Line: 1161
// RVA: 0x3E1B80
void __fastcall NISAllowPlayerControlTask::Begin(NISAllowPlayerControlTask *this, ActionContext *context)
{
  NISInstance *v2; // rdx

  v2 = NISManager::sInstance->mpActiveInstance.m_pPointer;
  if ( v2 )
    v2->mpNISAllowPlayerControlTask = this;
}

// File Line: 1175
// RVA: 0x3E27B0
void __fastcall NISAllowPlayerControlTask::End(NISAllowPlayerControlTask *this)
{
  NISInstance *v1; // rcx

  v1 = NISManager::sInstance->mpActiveInstance.m_pPointer;
  if ( v1 )
    v1->mpNISAllowPlayerControlTask = 0i64;
}

