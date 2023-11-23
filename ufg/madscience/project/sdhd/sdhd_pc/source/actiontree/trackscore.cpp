// File Line: 26
// RVA: 0x14806B0
__int64 dynamic_initializer_for__PrintTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PrintTrack", 0xFFFFFFFF);
  PrintTrack::sClassNameUID = result;
  return result;
}

// File Line: 38
// RVA: 0x268FD0
void __fastcall PrintTrack::PrintTrack(PrintTrack *this)
{
  ITrack::ITrack(this, PrintTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<PrintTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&PrintTrack::`vftable;
  this->m_Text.mOffset = 1i64;
  BinString::Set(&this->m_Text, &customCaption);
  this->m_PrintLocation.mValue = 0;
  this->m_PrintAtTimeBegin = 0;
}

// File Line: 43
// RVA: 0x269F10
void __fastcall PrintTrack::~PrintTrack(PrintTrack *this)
{
  char *v2; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v4; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&PrintTrack::`vftable;
  if ( (this->m_Text.mOffset & 1) != 0 && (this->m_Text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v2 = (char *)&this->m_Text + (this->m_Text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v2 != BinString::sEmptyString )
      operator delete[](v2);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (this->mMasterRate.text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v4 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v4 != BinString::sEmptyString )
      operator delete[](v4);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 59
// RVA: 0x1480670
__int64 dynamic_initializer_for__OpportunityTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("OpportunityTrack", 0xFFFFFFFF);
  OpportunityTrack::sClassNameUID = result;
  return result;
}

// File Line: 73
// RVA: 0x268F10
void __fastcall OpportunityTrack::OpportunityTrack(OpportunityTrack *this)
{
  NodeRefTrack<OpportunityTask>::NodeRefTrack<OpportunityTask>(this, OpportunityTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&OpportunityTrack::`vftable;
  *(_QWORD *)&this->mPriority = 0x10000i64;
  this->mTruthDuration = 0.0;
  this->mConditions.mOffset = 0i64;
}

// File Line: 207
// RVA: 0x271E30
void __fastcall OpportunityTrack::ResolveReferences(OpportunityTrack *this, ActionNode *parent)
{
  __int64 v4; // rax

  ((void (__fastcall *)(OpportunityTrack *))this->vfptr[2].FindWithOldPath)(this);
  ((void (__fastcall *)(OpportunityTrack *, ActionNode *))this->vfptr[1].GetResourceOwner)(this, parent);
  v4 = ((__int64 (__fastcall *)(OpportunityTrack *))this->vfptr[2].__vecDelDtor)(this);
  if ( v4 )
    (*(void (__fastcall **)(__int64, ActionNode *))(*(_QWORD *)v4 + 120i64))(v4, parent);
}

// File Line: 218
// RVA: 0x2717B0
void __fastcall OpportunityTrack::ResolvePathReferencesRelative(OpportunityTrack *this, ActionNode *nodeRoot)
{
  __int64 mOffset; // rax
  char *v5; // rcx
  __int64 v6; // rax

  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset )
    v5 = (char *)&this->mActionNodeReference + mOffset;
  else
    v5 = 0i64;
  (*(void (__fastcall **)(char *))(*(_QWORD *)v5 + 240i64))(v5);
  v6 = ((__int64 (__fastcall *)(OpportunityTrack *))this->vfptr[2].__vecDelDtor)(this);
  if ( v6 )
    (*(void (__fastcall **)(__int64, ActionNode *))(*(_QWORD *)v6 + 128i64))(v6, nodeRoot);
}

// File Line: 229
// RVA: 0x272CF0
void __fastcall OpportunityTrack::Trim(OpportunityTrack *this, ActionNode *parent, __int64 force)
{
  __int64 mOffset; // rax
  UFG::qOffset64<ConditionGroup *> *p_mConditions; // rbx
  _DWORD *v5; // rcx

  mOffset = this->mConditions.mOffset;
  p_mConditions = &this->mConditions;
  if ( mOffset )
  {
    v5 = (_DWORD *)((char *)p_mConditions + mOffset);
    if ( (UFG::qOffset64<ConditionGroup *> *)((char *)p_mConditions + mOffset) )
    {
      if ( (v5[8] & 0x7FFFFFFF) == 0 )
      {
        (*(void (__fastcall **)(_DWORD *, __int64, __int64))(*(_QWORD *)v5 + 8i64))(v5, 1i64, force);
        p_mConditions->mOffset = 0i64;
      }
    }
  }
}

// File Line: 243
// RVA: 0x26DFE0
ActionPath *__fastcall OpportunityTrack::GetActionPath(OpportunityTrack *this)
{
  __int64 mOffset; // rax
  char *v2; // rax

  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset )
  {
    v2 = (char *)&this->mActionNodeReference + mOffset;
    if ( v2 )
      return (ActionPath *)(v2 + 56);
  }
  if ( (_S11_0 & 1) == 0 )
  {
    _S11_0 |= 1u;
    sNULL.mPath.mCount = 0;
    sNULL.mPath.mData.mOffset = 0i64;
    atexit(OpportunityTrack::GetActionPath_::_5_::_dynamic_atexit_destructor_for__sNULL__);
  }
  return &sNULL;
}

// File Line: 270
// RVA: 0x14806F0
__int64 dynamic_initializer_for__SequenceTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SequenceTrack", 0xFFFFFFFF);
  SequenceTrack::sClassNameUID = result;
  return result;
}

// File Line: 279
// RVA: 0x26CFA0
ITrack *__fastcall SequenceTrack::CreateClone(SequenceTrack *this)
{
  char *v2; // rax
  ITrack *v3; // rdi
  ITrack *v4; // rbx
  Expression::IMemberMapVtbl *vfptr; // rax
  __int64 mOffset; // rax
  char *v7; // rax
  Expression::IMemberMapVtbl *v8; // rax
  __int64 v9; // rax
  char *v10; // rcx
  __int64 v11; // rax

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "SequenceTrack::CreateClone", 0i64, 1u);
  v3 = (ITrack *)v2;
  if ( v2 )
  {
    NodeRefTrack<SequenceTask>::NodeRefTrack<SequenceTask>(
      (NodeRefTrack<SequenceTask> *)v2,
      SequenceTrack::sClassNameUID);
    v3->vfptr = (Expression::IMemberMapVtbl *)&SequenceTrack::`vftable;
  }
  else
  {
    v3 = 0i64;
  }
  v4 = v3 + 1;
  vfptr = v3[1].vfptr;
  if ( vfptr && (ITrack *)((char *)v4 + (_QWORD)vfptr) )
    (*(Expression::IMemberMapVtbl **)((char *)&v4->vfptr + (_QWORD)vfptr))->__vecDelDtor(
      (Expression::IMemberMap *)((char *)v4 + (_QWORD)vfptr),
      1u);
  ITrack::operator=(v3, this);
  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset && (v7 = (char *)&this->mActionNodeReference + mOffset) != 0i64 )
    v8 = (Expression::IMemberMapVtbl *)(v7 - (char *)v4);
  else
    v8 = 0i64;
  v4->vfptr = v8;
  v9 = this->mActionNodeReference.mOffset;
  if ( v9 )
    v10 = (char *)&this->mActionNodeReference + v9;
  else
    v10 = 0i64;
  v11 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v10 + 16i64))(v10);
  if ( v11 )
    v4->vfptr = (Expression::IMemberMapVtbl *)(v11 - (_QWORD)v4);
  else
    v4->vfptr = 0i64;
  return v3;
}

// File Line: 319
// RVA: 0x1480550
__int64 dynamic_initializer_for__ExecuteTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ExecuteTrack", 0xFFFFFFFF);
  ExecuteTrack::sClassNameUID = result;
  return result;
}

// File Line: 333
// RVA: 0x14805F0
__int64 dynamic_initializer_for__MasterTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MasterTrack", 0xFFFFFFFF);
  MasterTrack::sClassNameUID = result;
  return result;
}

// File Line: 347
// RVA: 0x1480710
__int64 dynamic_initializer_for__SpawnTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SpawnTrack", 0xFFFFFFFF);
  SpawnTrack::sClassNameUID = result;
  return result;
}

// File Line: 362
// RVA: 0x269110
void __fastcall SpawnTrack::SpawnTrack(SpawnTrack *this)
{
  NodeRefTrack<SpawnTask>::NodeRefTrack<SpawnTask>(this, SpawnTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&SpawnTrack::`vftable;
  *(_WORD *)&this->mKeepAlive = 1;
}

// File Line: 371
// RVA: 0x26D090
Expression::IMemberMap *__fastcall SpawnTrack::CreateClone(SpawnTrack *this)
{
  char *v2; // rax
  char *v3; // rbx
  char *v4; // rdi
  __int64 v5; // rax
  __int64 mOffset; // rax
  char *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rax
  char *v10; // rcx
  __int64 v11; // rax

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "SpawnTrack::CreateClone", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    NodeRefTrack<SpawnTask>::NodeRefTrack<SpawnTask>((NodeRefTrack<SpawnTask> *)v2, SpawnTrack::sClassNameUID);
    *(_QWORD *)v3 = &SpawnTrack::`vftable;
    *((_WORD *)v3 + 32) = 1;
  }
  else
  {
    v3 = 0i64;
  }
  v4 = v3 + 56;
  v5 = *((_QWORD *)v3 + 7);
  if ( v5 && &v4[v5] )
    (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)&v4[v5] + 8i64))(&v4[v5], 1i64);
  ITrack::operator=((ITrack *)v3, this);
  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset && (v7 = (char *)&this->mActionNodeReference + mOffset) != 0i64 )
    v8 = v7 - v4;
  else
    v8 = 0i64;
  *(_QWORD *)v4 = v8;
  v3[64] = this->mKeepAlive;
  v3[65] = this->mSpawnedNodeActionTreeType.mValue;
  v9 = this->mActionNodeReference.mOffset;
  if ( v9 )
    v10 = (char *)&this->mActionNodeReference + v9;
  else
    v10 = 0i64;
  v11 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v10 + 16i64))(v10);
  if ( v11 )
    *(_QWORD *)v4 = v11 - (_QWORD)v4;
  else
    *(_QWORD *)v4 = 0i64;
  return (Expression::IMemberMap *)v3;
}

// File Line: 681
// RVA: 0x271F40
void __fastcall SpawnTrack::ResolveReferences(SpawnTrack *this, ActionNode *parent)
{
  __int64 mOffset; // rax
  __int64 v5; // rcx
  __int64 v6; // rcx

  ((void (__fastcall *)(SpawnTrack *))this->vfptr[2].FindWithOldPath)(this);
  ((void (__fastcall *)(SpawnTrack *, ActionNode *))this->vfptr[1].GetResourceOwner)(this, parent);
  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset )
    mOffset += (__int64)&this->mActionNodeReference;
  v5 = *(_QWORD *)(mOffset + 72);
  if ( v5 )
  {
    v6 = mOffset + v5 + 72;
    if ( v6 )
      this->mSpawnedNodeActionTreeType.mValue = *(_BYTE *)((*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 152i64))(v6)
                                                         + 236);
  }
}

