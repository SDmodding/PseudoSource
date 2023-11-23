// File Line: 56
// RVA: 0x269E50
void __fastcall ITrack::~ITrack(ITrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rdx
  unsigned __int64 v3; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (this->mMasterRate.text.mOffset & 1) != 0 )
  {
    v3 = p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64;
    if ( v3 )
    {
      if ( (char *)p_mMasterRate + v3 != BinString::sEmptyString )
        operator delete[]((char *)p_mMasterRate + v3);
    }
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 216
// RVA: 0x2B5D20
ITask *__fastcall Track<InteractionPointInteractWithBestTask>::CreateTask(
        Track<InteractionPointInteractWithBestTask> *this,
        const char *debugName)
{
  char *v3; // rax
  ITask *v4; // rbx
  _QWORD *v5; // rax

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
  ITask::SetTrack(v4, this);
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
  char *v5; // r14
  __int64 v6; // rcx

  v2 = 0i64;
  v5 = (char *)&this->mTracks.mData + this->mTracks.mData.mOffset;
  if ( (this->mTracks.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v6 = (__int64)&v5[8 * v2 + *(_QWORD *)&v5[8 * v2]];
      (*(void (__fastcall **)(__int64, ActionNode *))(*(_QWORD *)v6 + 88i64))(v6, parent);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < (this->mTracks.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 326
// RVA: 0x271810
void __fastcall TrackGroup::ResolvePathReferencesRelative(TrackGroup *this, ActionNode *nodeRoot)
{
  __int64 v2; // rbx
  char *v5; // r14
  __int64 v6; // rcx

  v2 = 0i64;
  v5 = (char *)&this->mTracks.mData + this->mTracks.mData.mOffset;
  if ( (this->mTracks.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v6 = (__int64)&v5[8 * v2 + *(_QWORD *)&v5[8 * v2]];
      (*(void (__fastcall **)(__int64, ActionNode *))(*(_QWORD *)v6 + 96i64))(v6, nodeRoot);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < (this->mTracks.mCount & 0x7FFFFFFFu) );
  }
}

