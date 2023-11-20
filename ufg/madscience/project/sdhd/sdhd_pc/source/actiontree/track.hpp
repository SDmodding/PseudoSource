// File Line: 56
// RVA: 0x269E50
void __fastcall ITrack::~ITrack(ITrack *this)
{
  ITrack *v1; // rbx
  ExpressionParameterFloat *v2; // rdx
  unsigned __int64 v3; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(this->mMasterRate.text.mOffset) & 1) )
  {
    v3 = v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64;
    if ( v3 )
    {
      if ( (char *)v2 + v3 != BinString::sEmptyString )
        operator delete[]((char *)v2 + v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 216
// RVA: 0x2B5D20
ITask *__fastcall Track<InteractionPointInteractWithBestTask>::CreateTask(Track<InteractionPointInteractWithBestTask> *this, const char *debugName)
{
  Track<InteractionPointInteractWithBestTask> *v2; // rdi
  char *v3; // rax
  ITask *v4; // rbx
  _QWORD *v5; // rax

  v2 = this;
  v3 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x30ui64, debugName, 0i64, 1u);
  v4 = (ITask *)v3;
  if ( v3 )
  {
    v5 = v3 + 8;
    *v5 = v5;
    v5[1] = v5;
    v4->vfptr = (ITaskVtbl *)&ITask::`vftable;
    v4->vfptr = (ITaskVtbl *)&Task<InteractionPointInteractWithBestTrack>::`vftable;
    v4->vfptr = (ITaskVtbl *)&InteractionPointInteractWithBestTask::`vftable;
  }
  else
  {
    v4 = 0i64;
  }
  ITask::SetTrack(v4, (ITrack *)&v2->vfptr);
  return v4;
}

// File Line: 238
// RVA: 0x26E530
const char *__fastcall TrackGroup::GetClassname(TrackGroup *this)
{
  return TrackGroup::sClassName;
}

// File Line: 317
// RVA: 0x271FB0
void __fastcall TrackGroup::ResolveReferences(TrackGroup *this, ActionNode *parent)
{
  __int64 v2; // rbx
  ActionNode *v3; // rsi
  TrackGroup *v4; // rdi
  char *v5; // r14
  signed __int64 v6; // rcx

  v2 = 0i64;
  v3 = parent;
  v4 = this;
  v5 = (char *)&this->mTracks.mData + this->mTracks.mData.mOffset;
  if ( this->mTracks.mCount & 0x7FFFFFFF )
  {
    do
    {
      v6 = (signed __int64)&v5[8 * v2 + *(_QWORD *)&v5[8 * v2]];
      (*(void (__fastcall **)(signed __int64, ActionNode *))(*(_QWORD *)v6 + 88i64))(v6, v3);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < (v4->mTracks.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 326
// RVA: 0x271810
void __fastcall TrackGroup::ResolvePathReferencesRelative(TrackGroup *this, ActionNode *nodeRoot)
{
  __int64 v2; // rbx
  ActionNode *v3; // rsi
  TrackGroup *v4; // rdi
  char *v5; // r14
  signed __int64 v6; // rcx

  v2 = 0i64;
  v3 = nodeRoot;
  v4 = this;
  v5 = (char *)&this->mTracks.mData + this->mTracks.mData.mOffset;
  if ( this->mTracks.mCount & 0x7FFFFFFF )
  {
    do
    {
      v6 = (signed __int64)&v5[8 * v2 + *(_QWORD *)&v5[8 * v2]];
      (*(void (__fastcall **)(signed __int64, ActionNode *))(*(_QWORD *)v6 + 96i64))(v6, v3);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < (v4->mTracks.mCount & 0x7FFFFFFFu) );
  }
}

