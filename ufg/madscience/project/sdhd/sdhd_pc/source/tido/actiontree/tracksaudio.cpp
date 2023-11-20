// File Line: 24
// RVA: 0x149BBA0
__int64 dynamic_initializer_for__audioEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&audioEnum, "Global/Act/AudioTag.xml");
  return atexit(dynamic_atexit_destructor_for__audioEnum__);
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
  AudioTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AudioTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AudioTask>::`vftable';
  v1->m_RtpcVal = 0.0;
  v1->m_playPercent = 100.0;
  *(_QWORD *)&v1->m_audioTagId[4] = 0i64;
  *(_QWORD *)&v1->m_audioTagId[2] = 0i64;
  *(_QWORD *)v1->m_audioTagId = 0i64;
  *(_QWORD *)&v1->m_audioTagUID[4] = 0i64;
  *(_QWORD *)&v1->m_audioTagUID[2] = 0i64;
  *(_QWORD *)v1->m_audioTagUID = 0i64;
  v1->vfptr = (Expression::IMemberMapVtbl *)&AudioTrack::`vftable';
  *(_WORD *)&v1->m_playOnActor = 0;
}

// File Line: 178
// RVA: 0x2E3340
void __fastcall AudioTrack::~AudioTrack(AudioTrack *this)
{
  AudioTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrack::`vftable';
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
  AudioTrackSimple *v2; // rbx

  v2 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, flag);
  v2->vfptr = (Expression::IMemberMapVtbl *)&Track<AudioTaskSimple>::`vftable';
  v2->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackSimple::`vftable';
}

// File Line: 214
// RVA: 0x2DE020
void __fastcall AudioTrackSimple::AudioTrackSimple(AudioTrackSimple *this)
{
  AudioTrackSimple *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AudioTrackSimple::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AudioTaskSimple>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackSimple::`vftable';
  *(_QWORD *)&v1->m_audioTagId = 0i64;
  v1->m_hsmEnabled = 0;
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
  AudioTrackSoundbankIO *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AudioTrackSoundbankIO::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AudioTaskSoundbankIO>::`vftable';
  v1->m_RtpcVal = 0.0;
  v1->m_playPercent = 100.0;
  *(_QWORD *)&v1->m_audioTagId[4] = 0i64;
  *(_QWORD *)&v1->m_audioTagId[2] = 0i64;
  *(_QWORD *)v1->m_audioTagId = 0i64;
  *(_QWORD *)&v1->m_audioTagUID[4] = 0i64;
  *(_QWORD *)&v1->m_audioTagUID[2] = 0i64;
  *(_QWORD *)v1->m_audioTagUID = 0i64;
  v1->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackSoundbankIO::`vftable';
}

// File Line: 318
// RVA: 0x2E34E0
void __fastcall AudioTrackSoundbankIO::~AudioTrackSoundbankIO(AudioTrackSoundbankIO *this)
{
  AudioTrackSoundbankIO *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackSoundbankIO::`vftable';
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
  AudioTrackMusicState *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AudioTrackMusicState::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AudioTaskMusicState>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackMusicState::`vftable';
  v1->mStateName.mOffset = 1i64;
  BinString::Set(&v1->mStateName, "NO_STATE");
  v1->mStateValue.mOffset = 1i64;
  BinString::Set(&v1->mStateValue, "NO_VALUE");
}

// File Line: 348
// RVA: 0x2E33B0
void __fastcall AudioTrackMusicState::~AudioTrackMusicState(AudioTrackMusicState *this)
{
  AudioTrackMusicState *v1; // rbx
  char *v2; // rcx
  char *v3; // rcx
  ExpressionParameterFloat *v4; // rcx
  char *v5; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackMusicState::`vftable';
  if ( !(~LOBYTE(this->mStateValue.mOffset) & 1) )
  {
    if ( this->mStateValue.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v2 = (char *)&this->mStateValue + (this->mStateValue.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v2 != BinString::sEmptyString )
        operator delete[](v2);
    }
  }
  if ( !(~LOBYTE(v1->mStateName.mOffset) & 1) )
  {
    if ( v1->mStateName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)&v1->mStateName + (v1->mStateName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v4 = &v1->mMasterRate;
  if ( !(~LOBYTE(v1->mMasterRate.text.mOffset) & 1) )
  {
    if ( v4->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v5 = (char *)v4 + (v4->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v5 != BinString::sEmptyString )
        operator delete[](v5);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

