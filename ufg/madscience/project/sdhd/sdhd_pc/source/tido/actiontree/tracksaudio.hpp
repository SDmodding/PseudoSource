// File Line: 97
// RVA: 0x2BDCA0
__int64 __fastcall AudioTrack::GetClassNameUID(AudioTrack *this)
{
  return AudioTrack::sClassNameUID;
}

// File Line: 145
// RVA: 0x2E3470
void __fastcall AudioTrackSimple::~AudioTrackSimple(AudioTrackSimple *this)
{
  AudioTrackSimple *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackSimple::`vftable';
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

// File Line: 147
// RVA: 0x301E50
__int64 __fastcall AudioTrackSimple::GetClassNameUID(AudioTrackSimple *this)
{
  return AudioTrackSimple::sClassNameUID;
}

// File Line: 185
// RVA: 0x2C0970
const char *__fastcall AudioTrackSoundbankIO::GetClassname(AudioTrackSoundbankIO *this)
{
  return AudioTrackSoundbankIO::sClassName;
}

// File Line: 210
// RVA: 0x315AA0
void __fastcall AudioTrackMusicState::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "MemberMap::AudioTrackMusicState", 0i64, 1u);
  if ( v0 )
    AudioTrackMusicState::AudioTrackMusicState((AudioTrackMusicState *)v0);
}

