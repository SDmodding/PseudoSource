// File Line: 32
// RVA: 0x26E390
__int64 __fastcall PrintTrack::GetClassNameUID(PrintTrack *this)
{
  return PrintTrack::sClassNameUID;
}

// File Line: 79
// RVA: 0x26E4D0
const char *__fastcall OpportunityTrack::GetClassname(OpportunityTrack *this)
{
  return OpportunityTrack::sClassName;
}

// File Line: 120
// RVA: 0x26EEC0
TrackGroup *__fastcall OpportunityTrack::GetConditionGroup2(ActionNodeImplementation *this)
{
  TrackGroup *result; // rax

  result = (TrackGroup *)this->mTracks.mOffset;
  if ( result )
    result = (TrackGroup *)((char *)result + (_QWORD)this + 64);
  return result;
}

// File Line: 122
// RVA: 0x272A40
void __fastcall ResourceOpportunityTrack::SetConditionGroup2(ActionNodeImplementation *this, TrackGroup *tracks)
{
  UFG::qOffset64<TrackGroup *> *v2; // rcx

  v2 = &this->mTracks;
  if ( tracks )
    v2->mOffset = (char *)tracks - (char *)v2;
  else
    v2->mOffset = 0i64;
}

// File Line: 148
// RVA: 0x26E3B0
__int64 __fastcall SequenceTrack::GetClassNameUID(SequenceTrack *this)
{
  return SequenceTrack::sClassNameUID;
}

// File Line: 169
// RVA: 0x2C1240
const char *__fastcall ExecuteTrack::GetClassname(ExecuteTrack *this)
{
  return ExecuteTrack::sClassName;
}

// File Line: 181
// RVA: 0x2BED80
__int64 __fastcall MasterTrack::GetClassNameUID(MasterTrack *this)
{
  return MasterTrack::sClassNameUID;
}

// File Line: 197
// RVA: 0x26E520
const char *__fastcall SpawnTrack::GetClassname(SpawnTrack *this)
{
  return SpawnTrack::sClassName;
}

