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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gNISTrackFactoryAction__);
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
  ITrack::ITrack(this, CurtainShowTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CurtainShowTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CurtainShowTrack::`vftable;
  *(_WORD *)&this->mFadeIn = 257;
  this->mFadeInTime = 1.0;
  this->mFadeOutTime = 1.0;
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
  ITrack::ITrack(this, NISShadowCascadeTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<NISShadowCascadeTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&NISShadowCascadeTrack::`vftable;
  this->mCascade0 = -1.0;
  this->mCascade1 = -1.0;
  this->mCascade2 = -1.0;
  this->mBias0 = -1.0;
  this->mBias1 = -1.0;
  this->mBias2 = -1.0;
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
  UFG::qSymbolUC result; // [rsp+48h] [rbp+10h] BYREF

  ITrack::ITrack(this, ActorAttachTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<ActorAttachTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActorAttachTrack::`vftable;
  this->mActorID.mUID = -1;
  this->mAttachToActor = 0;
  this->mBlendInTime = 0.0;
  *(_QWORD *)&this->mAttachJointName.mUID = -1i64;
  this->mAttachJointName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "none")->mUID;
  this->mActorAttachJointName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "none")->mUID;
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
  UFG::qSymbolUC result; // [rsp+48h] [rbp+10h] BYREF

  ITrack::ITrack(this, ActorDetachTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<ActorDetachTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActorDetachTrack::`vftable;
  this->mActorID.mUID = -1;
  *(_WORD *)&this->mDetachFromActor = 256;
  this->mBlendOutTime = 0.0;
  *(_QWORD *)&this->mAttachJointName.mUID = -1i64;
  this->mAttachJointName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "none")->mUID;
  this->mActorAttachJointName = (UFG::qSymbolUC)UFG::qSymbolUC::create_from_string(&result, "none")->mUID;
}

// File Line: 481
// RVA: 0x14CF080
__int64 dynamic_initializer_for__gLGAPlayModeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gLGAPlayModeEnum, gLGAPlayModeStringList, 3, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gLGAPlayModeEnum__);
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
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&NISLightGroupAnimationTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  ITrack::ITrack(this, NISPlayMovieTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<NISPlayMovieTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&NISPlayMovieTrack::`vftable;
  this->mMovieFilename.mOffset = 1i64;
  BinString::Set(&this->mMovieFilename, &customCaption);
  *(_WORD *)&this->mPauseSound = 1;
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
  ITrack *m_Track; // rdx
  float v4; // xmm6_4
  UFG::allocator::free_link *v5; // rax
  UFG::UISubtitleMessage *v6; // rax
  UFG::UISubtitleMessage *v7; // rbx
  UFG::UIHKTextOverlay *Instance; // rax
  UFG::qString v9; // [rsp+28h] [rbp-70h] BYREF
  UFG::qString v10; // [rsp+50h] [rbp-48h] BYREF

  m_Track = this->m_Track;
  if ( ((unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    UFG::qString::qString(
      &v10,
      (const char *)&m_Track[1] + ((unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64));
  else
    UFG::qString::qString(&v10, BinString::sEmptyString);
  v4 = this->m_Track->mTimeEnd - this->m_Track->mTimeBegin;
  UFG::qString::qString(&v9, "Red");
  if ( v4 < 0.0 )
    v4 = FLOAT_120_0;
  v5 = UFG::qMalloc(0xD0ui64, "UISubtitleMessage", 0i64);
  if ( v5 )
  {
    UFG::UISubtitleMessage::UISubtitleMessage((UFG::UISubtitleMessage *)v5, TYPE_SUBTITLE_TEXT, v10.mData, 0i64);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v7->lifetime = v4;
  UFG::qString::Set(&v7->color, v9.mData);
  Instance = UFG::UIHKTextOverlay::getInstance();
  if ( Instance )
    UFG::UIHKTextOverlay::QueueMessage(Instance, v7);
  UFG::qString::~qString(&v9);
  UFG::qString::~qString(&v10);
}

// File Line: 600
// RVA: 0x3E1FC0
void __fastcall SubtitleGroupTask::Begin(SubtitleGroupTask *this, ActionContext *context)
{
  ITrack *m_Track; // rdx
  UFG::qString v3; // [rsp+28h] [rbp-30h] BYREF

  m_Track = this->m_Track;
  if ( ((unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    UFG::qString::qString(
      &v3,
      (const char *)&m_Track[1] + ((unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64));
  else
    UFG::qString::qString(&v3, BinString::sEmptyString);
  UFG::qString::~qString(&v3);
}

// File Line: 614
// RVA: 0x3E28C0
void __fastcall SubtitleGroupTask::End(SubtitleTask *this)
{
  UFG::UIHKTextOverlay *Instance; // rax

  Instance = UFG::UIHKTextOverlay::getInstance();
  if ( Instance )
    UFG::UIHKTextOverlay::StopAllSubtitles(Instance, 1);
}

// File Line: 627
// RVA: 0x3E1AE0
void __fastcall CurtainShowTask::Begin(CurtainShowTask *this, ActionContext *context)
{
  ITrack *m_Track; // r8
  bool v3; // dl
  bool v4; // zf

  m_Track = this->m_Track;
  this->mDuration = m_Track->mTimeEnd - m_Track->mTimeBegin;
  v3 = LOBYTE(m_Track[1].vfptr) != 0;
  this->mFadeIn = v3;
  v4 = BYTE1(m_Track[1].vfptr) == 0;
  this->mTimeRemaining = 0.0;
  this->mFadeOut = !v4;
  if ( v3 )
    UFG::UIHK_NISOverlay::ShowCurtains(*((float *)&m_Track[1].vfptr + 1), 0);
  else
    UFG::UIHK_NISOverlay::ShowCurtains(0.0, 0);
}

// File Line: 641
// RVA: 0x3E6650
bool __fastcall CurtainShowTask::Update(FastCurtainShowTask *this, float timeDelta)
{
  float v3; // xmm2_4
  bool result; // al

  result = 0;
  if ( UFG::UIHK_NISOverlay::IsCurtainStable() )
  {
    v3 = this->mTimeRemaining - timeDelta;
    this->mTimeRemaining = v3;
    if ( v3 <= 0.0 )
      return 1;
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
  ITrack *m_Track; // rax
  bool v3; // dl
  bool v4; // zf

  m_Track = this->m_Track;
  this->mDuration = m_Track->mTimeEnd - m_Track->mTimeBegin;
  v3 = LOBYTE(m_Track[1].vfptr) != 0;
  this->mFadeIn = v3;
  v4 = BYTE1(m_Track[1].vfptr) == 0;
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
  unsigned int mResourceOwner; // edx

  this->mContext = context;
  v2 = UFG::NISAudio::m_instance;
  this->m_hasStarted = 0;
  this->m_nisAudio = v2;
  this->m_lastElapsedTime = 0.0;
  this->m_playDelay = 0.0;
  mResourceOwner = (unsigned int)this->m_Track[1].mResourceOwner;
  if ( mResourceOwner )
    UFG::NISAudio::Play(this->m_nisAudio, mResourceOwner, 0i64);
}

// File Line: 717
// RVA: 0x3E65F0
bool __fastcall AudioTaskNIS::Update(AudioTaskNIS *this, float timeDelta)
{
  UFG::AudioEventController *p_m_controller; // rax
  bool result; // al
  float m_playDelay; // xmm0_4

  p_m_controller = &this->m_nisAudio->m_controller;
  if ( p_m_controller->m_pEvent )
    result = (*((_BYTE *)p_m_controller->m_pEvent + 144) & 0x40) != 0;
  else
    result = 0;
  if ( !this->m_hasStarted )
  {
    if ( result || (m_playDelay = this->m_playDelay, m_playDelay >= 0.75) )
    {
      if ( this->m_playDelay > 0.75 )
        return 0;
    }
    else
    {
      result = 1;
      this->m_playDelay = m_playDelay + timeDelta;
    }
  }
  return result;
}

// File Line: 740
// RVA: 0x3E26C0
void __fastcall AudioTaskNIS::End(AudioTaskNIS *this)
{
  UFG::NISAudio *m_nisAudio; // rcx
  UFG::AudioEvent *m_pEvent; // rax
  UFG::AudioEvent *v4; // rcx
  UFG::OneShotHandle pHandle; // [rsp+40h] [rbp+8h] BYREF

  m_nisAudio = this->m_nisAudio;
  m_pEvent = m_nisAudio->m_controller.m_pEvent;
  if ( m_pEvent )
  {
    if ( (*((_BYTE *)m_pEvent + 144) & 0x40) != 0 )
    {
      v4 = m_nisAudio->m_controller.m_pEvent;
      if ( v4 )
        UFG::AudioEvent::StopAndForget(v4, 100);
    }
  }
  if ( HIDWORD(this->m_Track[1].mResourceOwner) )
  {
    pHandle.m_pOneShot = 0i64;
    UFG::OneShotPool::GetOneShotHandle(&pHandle, &UFG::qMatrix44::msIdentity);
    if ( UFG::OneShotHandle::IsValid(&pHandle) )
      UFG::OneShot::Play(pHandle.m_pOneShot, HIDWORD(this->m_Track[1].mResourceOwner));
    UFG::OneShotHandle::Release(&pHandle);
  }
}

// File Line: 757
// RVA: 0x3E2CC0
float __fastcall AudioTaskNIS::GetElapsedTime(AudioTaskNIS *this)
{
  UFG::AudioEvent *m_pEvent; // rcx
  float result; // xmm0_4

  m_pEvent = this->m_nisAudio->m_controller.m_pEvent;
  if ( !m_pEvent )
    return this->m_lastElapsedTime;
  if ( (*((_BYTE *)m_pEvent + 144) & 0x40) == 0 )
    return this->m_lastElapsedTime;
  result = UFG::AudioEvent::GetElapsedTime(m_pEvent);
  if ( result <= 0.0 )
    return this->m_lastElapsedTime;
  this->m_lastElapsedTime = result;
  this->m_hasStarted = 1;
  return result;
}

// File Line: 795
// RVA: 0x3E1BA0
void __fastcall NISFadeOutTask::Begin(NISFadeOutTask *this, ActionContext *context)
{
  ITrack *m_Track; // rax
  unsigned int mResourceOwner; // ebx
  float v4; // xmm0_4
  UFG::OneShotHandle pHandle; // [rsp+40h] [rbp+8h] BYREF

  m_Track = this->m_Track;
  mResourceOwner = (unsigned int)m_Track[1].mResourceOwner;
  if ( LOBYTE(m_Track[1].vfptr) )
    v4 = 0.0;
  else
    v4 = FLOAT_0_33000001;
  UFG::UIHK_NISOverlay::ShowCurtains(v4, mResourceOwner == 0);
  if ( mResourceOwner )
  {
    pHandle.m_pOneShot = 0i64;
    UFG::OneShotPool::GetOneShotHandle(&pHandle, &UFG::qMatrix44::msIdentity);
    if ( UFG::OneShotHandle::IsValid(&pHandle) )
      UFG::OneShot::Play(pHandle.m_pOneShot, mResourceOwner);
    UFG::OneShotHandle::Release(&pHandle);
  }
}

// File Line: 825
// RVA: 0x3E6770
bool __fastcall NISFadeOutTask::Update(NISFadeOutTask *this, float timeDelta)
{
  return !LOBYTE(this->m_Track[1].vfptr) && UFG::UIHK_NISOverlay::IsCurtainHidden();
}

// File Line: 837
// RVA: 0x3E27D0
void __fastcall NISFadeOutTask::End(NISFadeOutTask *this)
{
  if ( BYTE1(this->m_Track[1].vfptr) )
    UFG::UIHK_NISOverlay::HideLetterBox();
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
  UFG::SimObjectCVBase *m_pPointer; // rbp
  UFG::qSymbol *v4; // rax
  UFG::qBaseNodeRB *SimObject; // rax
  ITrack *m_Track; // rcx
  unsigned int m_TrackClassNameUID; // ebx
  unsigned int mResourceOwner_high; // edi
  UFG::SimObjectCVBase *v9; // r14
  UFG::CharacterAnimationComponent *v10; // rsi
  UFG::CharacterAnimationComponent *v11; // r15
  __int16 m_Flags; // cx
  UFG::CharacterAnimationComponent *v13; // rax
  __int16 v14; // cx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // r15
  Creature *v17; // rsi
  int attachmentBoneID; // r12d
  int BoneID; // ebx
  UFG::qWiseSymbol result; // [rsp+70h] [rbp+8h] BYREF

  m_pPointer = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  v4 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, (unsigned int)this->m_Track[1].vfptr);
  SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, v4);
  if ( !SimObject )
    return 1;
  m_Track = this->m_Track;
  if ( BYTE4(m_Track[1].vfptr) )
  {
    m_TrackClassNameUID = m_Track[1].m_TrackClassNameUID;
    mResourceOwner_high = HIDWORD(m_Track[1].mResourceOwner);
    v9 = (UFG::SimObjectCVBase *)SimObject;
  }
  else
  {
    m_TrackClassNameUID = HIDWORD(m_Track[1].mResourceOwner);
    mResourceOwner_high = m_Track[1].m_TrackClassNameUID;
    v9 = m_pPointer;
    m_pPointer = (UFG::SimObjectCVBase *)SimObject;
  }
  v10 = 0i64;
  if ( v9 )
  {
    m_Flags = v9->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      v13 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      v13 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v9);
    }
    else
    {
      v13 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                               ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v9,
                                                   UFG::CharacterAnimationComponent::_TypeUID)
                                               : UFG::SimObject::GetComponentOfType(
                                                   v9,
                                                   UFG::CharacterAnimationComponent::_TypeUID));
    }
    v11 = v13;
  }
  else
  {
    v11 = 0i64;
  }
  if ( m_pPointer )
  {
    v14 = m_pPointer->m_Flags;
    if ( (v14 & 0x4000) != 0 || v14 < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
    }
    else if ( (v14 & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
    }
    else if ( (v14 & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    v10 = ComponentOfTypeHK;
  }
  if ( !v11 )
    return 1;
  if ( !v10 )
    return 1;
  mCreature = v11->mCreature;
  v17 = v10->mCreature;
  if ( !mCreature || !v17 )
    return 1;
  attachmentBoneID = -1;
  if ( mCreature->mPose.mRigHandle.mData )
    BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, m_TrackClassNameUID);
  else
    BoneID = -1;
  if ( v17->mPose.mRigHandle.mData )
    attachmentBoneID = Skeleton::GetBoneID(v17->mPose.mRigHandle.mUFGSkeleton, mResourceOwner_high);
  Creature::AddAttachment(
    mCreature,
    v9,
    BoneID,
    m_pPointer,
    attachmentBoneID,
    0,
    *(float *)&this->m_Track[1].mResourceOwner);
  return 0;
}

// File Line: 945
// RVA: 0x3E18D0
void __fastcall ActorDetachTask::Begin(ActorDetachTask *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rsi
  UFG::qSymbol *v4; // rax
  UFG::qBaseNodeRB *SimObject; // rax
  ITrack *m_Track; // rcx
  unsigned int m_TrackClassNameUID; // ebx
  UFG::SimObjectCVBase *v8; // rbp
  UFG::CharacterAnimationComponent *v9; // rdi
  UFG::CharacterAnimationComponent *v10; // r14
  __int16 m_Flags; // cx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  __int16 v13; // cx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  Creature *mCreature; // r14
  Creature *v16; // rdi
  int BoneID; // eax
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h] BYREF

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, (unsigned int)this->m_Track[1].vfptr);
  SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, v4);
  if ( SimObject )
  {
    m_Track = this->m_Track;
    if ( BYTE4(m_Track[1].vfptr) )
    {
      m_TrackClassNameUID = m_Track[1].m_TrackClassNameUID;
      v8 = (UFG::SimObjectCVBase *)SimObject;
    }
    else
    {
      m_TrackClassNameUID = HIDWORD(m_Track[1].mResourceOwner);
      v8 = m_pPointer;
      m_pPointer = (UFG::SimObjectCVBase *)SimObject;
    }
    v9 = 0i64;
    if ( v8 )
    {
      m_Flags = v8->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
      }
      else if ( (m_Flags & 0x2000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v8);
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v8,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v8,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      v10 = ComponentOfTypeHK;
    }
    else
    {
      v10 = 0i64;
    }
    if ( m_pPointer )
    {
      v13 = m_pPointer->m_Flags;
      if ( (v13 & 0x4000) != 0 || v13 < 0 )
      {
        ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
      }
      else if ( (v13 & 0x2000) != 0 )
      {
        ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
      }
      else if ( (v13 & 0x1000) != 0 )
      {
        ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
      }
      v9 = ComponentOfType;
    }
    if ( v10 )
    {
      if ( v9 )
      {
        mCreature = v10->mCreature;
        v16 = v9->mCreature;
        if ( mCreature )
        {
          if ( v16 )
          {
            if ( mCreature->mPose.mRigHandle.mData )
              BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, m_TrackClassNameUID);
            else
              BoneID = -1;
            if ( Creature::RemoveAttachment(mCreature, v8, BoneID, m_pPointer) )
            {
              if ( BYTE5(this->m_Track[1].vfptr) )
                Creature::MakeUpright(v16, 0.0);
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
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<NISLightGroupAnimationTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&NISLightGroupAnimationTask::`vftable;
  this->mController.mPrev = &this->mController;
  this->mController.mNext = &this->mController;
  this->mController.m_pPointer = 0i64;
}

// File Line: 1009
// RVA: 0x3E0AB0
void __fastcall NISLightGroupAnimationTask::~NISLightGroupAnimationTask(NISLightGroupAnimationTask *this)
{
  UFG::qSafePointer<PoseNode,PoseNode> *p_mController; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&NISLightGroupAnimationTask::`vftable;
  p_mController = &this->mController;
  if ( this->mController.m_pPointer )
  {
    mPrev = p_mController->mPrev;
    mNext = p_mController->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mController->mPrev = p_mController;
    p_mController->mNext = p_mController;
  }
  p_mController->m_pPointer = 0i64;
  v5 = p_mController->mPrev;
  v6 = p_mController->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mController->mPrev = p_mController;
  p_mController->mNext = p_mController;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 1013
// RVA: 0x3E1C30
void __fastcall NISLightGroupAnimationTask::Begin(NISLightGroupAnimationTask *this, ActionContext *context)
{
  NISInstance *m_pPointer; // rbx
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponent *ComponentOfType; // rsi
  const char *v6; // r8
  Creature *v7; // rcx
  PoseNode *v8; // rax
  UFG::qSafePointer<PoseNode,PoseNode> *p_mController; // r8
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qSafePointer<PoseNode,PoseNode> *v14; // rdx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<PoseNode>,UFG::qSafePointerNodeList> *v16; // rax
  PoseNode *v17; // rcx
  UFG::qString v18; // [rsp+48h] [rbp-30h] BYREF
  int returnCode; // [rsp+90h] [rbp+18h] BYREF
  UFG::qSymbolUC result; // [rsp+98h] [rbp+20h] BYREF

  m_pPointer = NISManager::sInstance->mpActiveInstance.m_pPointer;
  if ( m_pPointer )
    m_pPointer = (NISInstance *)m_pPointer->mpNISNode;
  m_pSimObject = m_pPointer->mFacialAnimGroupHandle.m_pReferenceInfo[1].m_pSimObject;
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::LightGroupAnimationComponent::_TypeUID);
    if ( ComponentOfType )
    {
      UFG::qString::qString(&v18);
      if ( ((unsigned __int64)m_pPointer->mFacialAnimGroupHandle.m_AnimationGroup.m_pPointer & 0xFFFFFFFFFFFFFFFEui64) != 0 )
        v6 = (char *)&m_pPointer->mFacialAnimGroupHandle.m_AnimationGroup.m_pPointer
           + ((unsigned __int64)m_pPointer->mFacialAnimGroupHandle.m_AnimationGroup.m_pPointer & 0xFFFFFFFFFFFFFFFEui64);
      else
        v6 = BinString::sEmptyString;
      UFG::qString::Format(&v18, "NIS_%s_LIGHT", v6);
      UFG::qSymbolUC::create_from_string(&result, v18.mData);
      returnCode = 0;
      v7 = *(Creature **)&ComponentOfType[2].m_TypeUID;
      if ( v7 )
      {
        v8 = Creature::PlayAnimation(v7, &result, APM_CYCLIC, 0.0, -1.0, 0.0, 0, &returnCode);
        p_mController = &this->mController;
        if ( this->mController.m_pPointer )
        {
          mPrev = p_mController->mPrev;
          mNext = this->mController.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_mController->mPrev = p_mController;
          this->mController.mNext = &this->mController;
        }
        this->mController.m_pPointer = v8;
        if ( v8 )
        {
          p_mNode = &v8->m_SafePointerList.mNode;
          v13 = v8->m_SafePointerList.mNode.UFG::qSafePointerNode<PoseNode>::mPrev;
          v13->mNext = p_mController;
          p_mController->mPrev = v13;
          this->mController.mNext = p_mNode;
          p_mNode->mPrev = p_mController;
        }
      }
      else
      {
        v14 = &this->mController;
        if ( this->mController.m_pPointer )
        {
          v15 = v14->mPrev;
          v16 = this->mController.mNext;
          v15->mNext = v16;
          v16->mPrev = v15;
          v14->mPrev = v14;
          this->mController.mNext = &this->mController;
        }
        this->mController.m_pPointer = 0i64;
      }
      v17 = this->mController.m_pPointer;
      if ( v17 )
        v17->Expression::IMemberMap::vfptr[2].FindWithOldPath(v17, (const char *)LOBYTE(this->m_Track[1].vfptr));
      UFG::qString::~qString(&v18);
    }
  }
}

// File Line: 1047
// RVA: 0x3E6790
bool __fastcall NISLightGroupAnimationTask::Update(NISLightGroupAnimationTask *this, float timeDelta)
{
  PoseNode *m_pPointer; // rcx
  int vfptr_low; // ebx
  bool result; // al

  m_pPointer = this->mController.m_pPointer;
  if ( !m_pPointer )
    return 0;
  vfptr_low = LOBYTE(this->m_Track[1].vfptr);
  result = 1;
  if ( vfptr_low != 1 && vfptr_low != 6 )
  {
    if ( ((unsigned __int8 (__fastcall *)(PoseNode *))m_pPointer->Expression::IMemberMap::vfptr[1].SetResourceOwner)(m_pPointer) )
    {
      this->mController.m_pPointer->vfptr[1].GetResourceOwner(this->mController.m_pPointer);
      if ( vfptr_low != 2 )
        return 0;
    }
  }
  return result;
}

// File Line: 1082
// RVA: 0x3E0540
void __fastcall NISPlayMovieTask::NISPlayMovieTask(NISPlayMovieTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<NISPlayMovieTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&NISPlayMovieTask::`vftable;
  this->mPlayer = 0i64;
}

// File Line: 1086
// RVA: 0x3E1DD0
void __fastcall NISPlayMovieTask::Begin(NISPlayMovieTask *this, ActionContext *context)
{
  ITrack *m_Track; // rdx
  const char *v4; // rdi
  UFG::GameStatTracker *v5; // rax
  float v6; // xmm6_4
  ITrack *v7; // rax
  UFG::MoviePlayer *i; // rbx
  UFG::MoviePlayer *v9; // rbx
  UFG::allocator::free_link *v10; // rax
  UFG::MoviePlayer *v11; // rax
  NISManager *v12; // rbx

  m_Track = this->m_Track;
  if ( ((unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    v4 = (char *)&m_Track[1] + ((unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64);
  else
    v4 = BinString::sEmptyString;
  if ( v4 && (unsigned int)UFG::qStringLength(v4) )
  {
    v5 = UFG::GameStatTracker::Instance();
    v6 = (float)(int)UFG::GameStatTracker::GetStat(v5, VolumeSFX) * 2000.0;
    v7 = this->m_Track;
    if ( BYTE1(v7[1].mResourceOwner) )
    {
      UFG::qMutex::Lock(&stru_142042A80);
      for ( i = off_142042A68; i != (UFG::MoviePlayer *)&UFG::TheMovieHandler; i = (UFG::MoviePlayer *)i->mNext )
      {
        if ( (i->mFlags & 0x10) != 0 && !(unsigned int)UFG::qStringCompareInsensitive(v4, i->mFilename, -1) )
        {
          this->mPlayer = i;
          UFG::MoviePlayer::PlayFromStart(i, 0);
          UFG::MoviePlayer::SetAudioVolume(this->mPlayer, 0, (int)v6);
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
        if ( (_S8_9 & 1) == 0 )
        {
          _S8_9 |= 1u;
          UFG::qWiseSymbol::create_from_string(&insta_pause, "insta_pause");
          atexit(NISPlayMovieTask::Begin_::_18_::_dynamic_atexit_destructor_for__insta_pause__);
        }
        UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, insta_pause.mUID, 0i64, 0, 0i64);
      }
      UFG::RenderWorld::SetRenderWorld(0);
      v10 = UFG::qMalloc(0x58ui64, "NISPlayMovieTask.mPlayer", 0i64);
      if ( v10 )
      {
        UFG::MoviePlayer::MoviePlayer((UFG::MoviePlayer *)v10);
        v9 = v11;
      }
      this->mPlayer = v9;
      UFG::MoviePlayer::Init(v9, v4, 0i64, 0);
      UFG::MoviePlayer::SetAudioVolume(this->mPlayer, 0, (int)v6);
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
  UFG::MoviePlayer *mPlayer; // rax

  mPlayer = this->mPlayer;
  return mPlayer && (mPlayer->mFlags & 1) == 0;
}

// File Line: 1134
// RVA: 0x3E27E0
void __fastcall NISPlayMovieTask::End(NISPlayMovieTask *this)
{
  NISManager *v2; // rax
  UFG::MoviePlayer *mPlayer; // rdi

  if ( BYTE1(this->m_Track[1].mResourceOwner) || !this->mPlayer )
  {
    this->mPlayer = 0i64;
  }
  else
  {
    v2 = NISManager::sInstance;
    --NISManager::sInstance->mHudDisableCount;
    if ( !v2->mHudDisableCount )
      UFG::UIHK_NISOverlay::HideLetterBox();
    mPlayer = this->mPlayer;
    if ( mPlayer )
    {
      UFG::MoviePlayer::~MoviePlayer(this->mPlayer);
      operator delete[](mPlayer);
    }
    if ( LOBYTE(this->m_Track[1].mResourceOwner) )
    {
      if ( (_S9_9 & 1) == 0 )
      {
        _S9_9 |= 1u;
        UFG::qWiseSymbol::create_from_string(&insta_resume, "insta_resume");
        atexit(NISPlayMovieTask::End_::_11_::_dynamic_atexit_destructor_for__insta_resume__);
      }
      UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, insta_resume.mUID, 0i64, 0, 0i64);
    }
    UFG::RenderWorld::SetRenderWorld(1);
    this->mPlayer = 0i64;
  }
}

// File Line: 1157
// RVA: 0x3DFE60
void __fastcall NISAllowPlayerControlTask::NISAllowPlayerControlTask(NISAllowPlayerControlTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<NISAllowPlayerControlTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&NISAllowPlayerControlTask::`vftable;
}

// File Line: 1161
// RVA: 0x3E1B80
void __fastcall NISAllowPlayerControlTask::Begin(NISAllowPlayerControlTask *this, ActionContext *context)
{
  NISInstance *m_pPointer; // rdx

  m_pPointer = NISManager::sInstance->mpActiveInstance.m_pPointer;
  if ( m_pPointer )
    m_pPointer->mpNISAllowPlayerControlTask = this;
}

// File Line: 1175
// RVA: 0x3E27B0
void __fastcall NISAllowPlayerControlTask::End(NISAllowPlayerControlTask *this)
{
  NISInstance *m_pPointer; // rcx

  m_pPointer = NISManager::sInstance->mpActiveInstance.m_pPointer;
  if ( m_pPointer )
    m_pPointer->mpNISAllowPlayerControlTask = 0i64;
}

