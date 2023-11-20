// File Line: 34
// RVA: 0x2BDCE0
__int64 __fastcall AudioTrackSurfaceDetection::GetClassNameUID(AudioTrackSurfaceDetection *this)
{
  return AudioTrackSurfaceDetection::sClassNameUID;
}

// File Line: 62
// RVA: 0x2C1FA0
const char *__fastcall PoliceScannerAudioEventTrack::GetClassname(PoliceScannerAudioEventTrack *this)
{
  return PoliceScannerAudioEventTrack::sClassName;
}

// File Line: 121
// RVA: 0x2C1100
const char *__fastcall DialogueTrack::GetClassname(DialogueTrack *this)
{
  return DialogueTrack::sClassName;
}

// File Line: 164
// RVA: 0x2C1110
const char *__fastcall DialogueTrackPOI::GetClassname(DialogueTrackPOI *this)
{
  return DialogueTrackPOI::sClassName;
}

// File Line: 213
// RVA: 0x2BE480
__int64 __fastcall DialogueTrackWeaponImpact::GetClassNameUID(DialogueTrackWeaponImpact *this)
{
  return DialogueTrackWeaponImpact::sClassNameUID;
}

// File Line: 262
// RVA: 0x29B090
void __fastcall ConversationTrackCreate::~ConversationTrackCreate(ConversationTrackCreate *this)
{
  ConversationTrackCreate *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ConversationTrackCreate::`vftable';
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

// File Line: 264
// RVA: 0x2BE290
__int64 __fastcall ConversationTrackCreate::GetClassNameUID(ConversationTrackCreate *this)
{
  return ConversationTrackCreate::sClassNameUID;
}

// File Line: 286
// RVA: 0x29B020
void __fastcall ConversationTrackCleanup::~ConversationTrackCleanup(ConversationTrackCleanup *this)
{
  ConversationTrackCleanup *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ConversationTrackCleanup::`vftable';
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

// File Line: 287
// RVA: 0x317D00
ConversationTrackCleanup *__fastcall ConversationTrackCleanup::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::ConversationTrackCleanup", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, ConversationTrackCleanup::sClassNameUID);
  *(_QWORD *)v1 = &Track<ConversationTaskCleanup>::`vftable';
  *(_QWORD *)v1 = &ConversationTrackCleanup::`vftable';
  return (ConversationTrackCleanup *)v1;
}

// File Line: 303
// RVA: 0x29B170
void __fastcall ConversationTrackOperation::~ConversationTrackOperation(ConversationTrackOperation *this)
{
  ConversationTrackOperation *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ConversationTrackOperation::`vftable';
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

// File Line: 305
// RVA: 0x2BE2B0
__int64 __fastcall ConversationTrackOperation::GetClassNameUID(ConversationTrackOperation *this)
{
  return ConversationTrackOperation::sClassNameUID;
}

// File Line: 326
// RVA: 0x29B100
void __fastcall ConversationTrackInterrupt::~ConversationTrackInterrupt(ConversationTrackInterrupt *this)
{
  ConversationTrackInterrupt *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ConversationTrackInterrupt::`vftable';
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

// File Line: 328
// RVA: 0x2BE2A0
__int64 __fastcall ConversationTrackInterrupt::GetClassNameUID(ConversationTrackInterrupt *this)
{
  return ConversationTrackInterrupt::sClassNameUID;
}

