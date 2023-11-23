// File Line: 24
// RVA: 0x149BBA0
__int64 dynamic_initializer_for__audioEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&audioEnum, "Global/Act/AudioTag.xml");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__audioEnum__);
}

// File Line: 151
// RVA: 0x1494CB0
__int64 dynamic_initializer_for__AudioTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AudioTrack", 0xFFFFFFFF);
  AudioTrack::sClassNameUID = result;
  return result;
}

// File Line: 172
// RVA: 0x2DDEF0
void __fastcall AudioTrack::AudioTrack(AudioTrack *this)
{
  ITrack::ITrack(this, AudioTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AudioTask>::`vftable;
  this->m_RtpcVal = 0.0;
  this->m_playPercent = 100.0;
  *(_QWORD *)&this->m_audioTagId[4] = 0i64;
  *(_QWORD *)&this->m_audioTagId[2] = 0i64;
  *(_QWORD *)this->m_audioTagId = 0i64;
  *(_QWORD *)&this->m_audioTagUID[4] = 0i64;
  *(_QWORD *)&this->m_audioTagUID[2] = 0i64;
  *(_QWORD *)this->m_audioTagUID = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrack::`vftable;
  *(_WORD *)&this->m_playOnActor = 0;
}

// File Line: 178
// RVA: 0x2E3340
void __fastcall AudioTrack::~AudioTrack(AudioTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrack::`vftable;
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

// File Line: 194
// RVA: 0x1494CF0
__int64 dynamic_initializer_for__AudioTrackSimple::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AudioTrackSimple", 0xFFFFFFFF);
  AudioTrackSimple::sClassNameUID = result;
  return result;
}

// File Line: 205
// RVA: 0x2DDFE0
void __fastcall AudioTrackSimple::AudioTrackSimple(AudioTrackSimple *this, MemImageLoadFlag flag)
{
  ITrack::ITrack(this, flag);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AudioTaskSimple>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackSimple::`vftable;
}

// File Line: 214
// RVA: 0x2DE020
void __fastcall AudioTrackSimple::AudioTrackSimple(AudioTrackSimple *this)
{
  ITrack::ITrack(this, AudioTrackSimple::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AudioTaskSimple>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackSimple::`vftable;
  *(_QWORD *)&this->m_audioTagId = 0i64;
  this->m_hsmEnabled = 0;
}

// File Line: 302
// RVA: 0x1494D10
__int64 dynamic_initializer_for__AudioTrackSoundbankIO::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AudioTrackSoundbankIO", 0xFFFFFFFF);
  AudioTrackSoundbankIO::sClassNameUID = result;
  return result;
}

// File Line: 313
// RVA: 0x2DE070
void __fastcall AudioTrackSoundbankIO::AudioTrackSoundbankIO(AudioTrackSoundbankIO *this)
{
  ITrack::ITrack(this, AudioTrackSoundbankIO::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AudioTaskSoundbankIO>::`vftable;
  this->m_RtpcVal = 0.0;
  this->m_playPercent = 100.0;
  *(_QWORD *)&this->m_audioTagId[4] = 0i64;
  *(_QWORD *)&this->m_audioTagId[2] = 0i64;
  *(_QWORD *)this->m_audioTagId = 0i64;
  *(_QWORD *)&this->m_audioTagUID[4] = 0i64;
  *(_QWORD *)&this->m_audioTagUID[2] = 0i64;
  *(_QWORD *)this->m_audioTagUID = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackSoundbankIO::`vftable;
}

// File Line: 318
// RVA: 0x2E34E0
void __fastcall AudioTrackSoundbankIO::~AudioTrackSoundbankIO(AudioTrackSoundbankIO *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackSoundbankIO::`vftable;
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

// File Line: 331
// RVA: 0x1494CD0
__int64 dynamic_initializer_for__AudioTrackMusicState::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AudioTrackMusicState", 0xFFFFFFFF);
  AudioTrackMusicState::sClassNameUID = result;
  return result;
}

// File Line: 344
// RVA: 0x2DDF70
void __fastcall AudioTrackMusicState::AudioTrackMusicState(AudioTrackMusicState *this)
{
  ITrack::ITrack(this, AudioTrackMusicState::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AudioTaskMusicState>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackMusicState::`vftable;
  this->mStateName.mOffset = 1i64;
  BinString::Set(&this->mStateName, "NO_STATE");
  this->mStateValue.mOffset = 1i64;
  BinString::Set(&this->mStateValue, "NO_VALUE");
}

// File Line: 348
// RVA: 0x2E33B0
void __fastcall AudioTrackMusicState::~AudioTrackMusicState(AudioTrackMusicState *this)
{
  char *v2; // rcx
  char *v3; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v5; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackMusicState::`vftable;
  if ( (this->mStateValue.mOffset & 1) != 0 && (this->mStateValue.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v2 = (char *)&this->mStateValue + (this->mStateValue.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v2 != BinString::sEmptyString )
      operator delete[](v2);
  }
  if ( (this->mStateName.mOffset & 1) != 0 && (this->mStateName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)&this->mStateName + (this->mStateName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (this->mMasterRate.text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v5 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v5 != BinString::sEmptyString )
      operator delete[](v5);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

