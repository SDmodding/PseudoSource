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
  PrintTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, PrintTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<PrintTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&PrintTrack::`vftable';
  v1->m_Text.mOffset = 1i64;
  BinString::Set(&v1->m_Text, &customWorldMapCaption);
  v1->m_PrintLocation.mValue = 0;
  v1->m_PrintAtTimeBegin = 0;
}

// File Line: 43
// RVA: 0x269F10
void __fastcall PrintTrack::~PrintTrack(PrintTrack *this)
{
  PrintTrack *v1; // rbx
  char *v2; // rcx
  ExpressionParameterFloat *v3; // rcx
  char *v4; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&PrintTrack::`vftable';
  if ( !(~LOBYTE(this->m_Text.mOffset) & 1) )
  {
    if ( this->m_Text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v2 = (char *)&this->m_Text + (this->m_Text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v2 != BinString::sEmptyString )
        operator delete[](v2);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v3 = &v1->mMasterRate;
  if ( !(~LOBYTE(v1->mMasterRate.text.mOffset) & 1) )
  {
    if ( v3->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v4 = (char *)v3 + (v3->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v4 != BinString::sEmptyString )
        operator delete[](v4);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  OpportunityTrack *v1; // rbx

  v1 = this;
  NodeRefTrack<OpportunityTask>::NodeRefTrack<OpportunityTask>(
    (NodeRefTrack<OpportunityTask> *)&this->vfptr,
    OpportunityTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&OpportunityTrack::`vftable';
  *(_QWORD *)&v1->mPriority = 0x10000i64;
  v1->mTruthDuration = 0.0;
  v1->mConditions.mOffset = 0i64;
}

// File Line: 207
// RVA: 0x271E30
void __fastcall OpportunityTrack::ResolveReferences(OpportunityTrack *this, ActionNode *parent)
{
  ActionNode *v2; // rdi
  OpportunityTrack *v3; // rbx
  __int64 v4; // rax

  v2 = parent;
  v3 = this;
  ((void (*)(void))this->vfptr[2].FindWithOldPath)();
  ((void (__fastcall *)(OpportunityTrack *, ActionNode *))v3->vfptr[1].GetResourceOwner)(v3, v2);
  v4 = ((__int64 (__fastcall *)(OpportunityTrack *))v3->vfptr[2].__vecDelDtor)(v3);
  if ( v4 )
    (*(void (__fastcall **)(__int64, ActionNode *))(*(_QWORD *)v4 + 120i64))(v4, v2);
}

// File Line: 218
// RVA: 0x2717B0
void __fastcall OpportunityTrack::ResolvePathReferencesRelative(OpportunityTrack *this, ActionNode *nodeRoot)
{
  __int64 v2; // rax
  ActionNode *v3; // rdi
  OpportunityTrack *v4; // rbx
  char *v5; // rcx
  __int64 v6; // rax

  v2 = this->mActionNodeReference.mOffset;
  v3 = nodeRoot;
  v4 = this;
  if ( v2 )
    v5 = (char *)&this->mActionNodeReference + v2;
  else
    v5 = 0i64;
  (*(void (**)(void))(*(_QWORD *)v5 + 240i64))();
  v6 = ((__int64 (__fastcall *)(OpportunityTrack *))v4->vfptr[2].__vecDelDtor)(v4);
  if ( v6 )
    (*(void (__fastcall **)(__int64, ActionNode *))(*(_QWORD *)v6 + 128i64))(v6, v3);
}

// File Line: 229
// RVA: 0x272CF0
void __fastcall OpportunityTrack::Trim(OpportunityTrack *this, ActionNode *parent, __int64 force)
{
  __int64 v3; // rax
  UFG::qOffset64<ConditionGroup *> *v4; // rbx
  _DWORD *v5; // rcx

  v3 = this->mConditions.mOffset;
  v4 = &this->mConditions;
  if ( v3 )
  {
    v5 = (_DWORD *)((char *)v4 + v3);
    if ( (UFG::qOffset64<ConditionGroup *> *)((char *)v4 + v3) )
    {
      if ( !(v5[8] & 0x7FFFFFFF) )
      {
        (*(void (__fastcall **)(_DWORD *, signed __int64, __int64))(*(_QWORD *)v5 + 8i64))(v5, 1i64, force);
        v4->mOffset = 0i64;
      }
    }
  }
}

// File Line: 243
// RVA: 0x26DFE0
ActionPath *__fastcall OpportunityTrack::GetActionPath(OpportunityTrack *this)
{
  __int64 v1; // rax
  char *v2; // rax

  v1 = this->mActionNodeReference.mOffset;
  if ( v1 )
  {
    v2 = (char *)&this->mActionNodeReference + v1;
    if ( v2 )
      return (ActionPath *)(v2 + 56);
  }
  if ( !(_S11_0 & 1) )
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
  SequenceTrack *v1; // rsi
  char *v2; // rax
  ITrack *v3; // rdi
  ITrack *v4; // rbx
  Expression::IMemberMapVtbl *v5; // rax
  __int64 v6; // rax
  signed __int64 v7; // rax
  signed __int64 v8; // rax
  __int64 v9; // rax
  signed __int64 v10; // rcx
  __int64 v11; // rax

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "SequenceTrack::CreateClone", 0i64, 1u);
  v3 = (ITrack *)v2;
  if ( v2 )
  {
    NodeRefTrack<SequenceTask>::NodeRefTrack<SequenceTask>(
      (NodeRefTrack<SequenceTask> *)v2,
      SequenceTrack::sClassNameUID);
    v3->vfptr = (Expression::IMemberMapVtbl *)&SequenceTrack::`vftable';
  }
  else
  {
    v3 = 0i64;
  }
  v4 = v3 + 1;
  v5 = v3[1].vfptr;
  if ( v5 && (ITrack *)((char *)v4 + (_QWORD)v5) )
    (*(Expression::IMemberMapVtbl **)((char *)&v4->vfptr + (_QWORD)v5))->__vecDelDtor(
      (Expression::IMemberMap *)((char *)&v4->vfptr + (_QWORD)v5),
      1u);
  ITrack::operator=(v3, (ITrack *)&v1->vfptr);
  v6 = v1->mActionNodeReference.mOffset;
  if ( v6 && (v7 = (signed __int64)&v1->mActionNodeReference + v6) != 0 )
    v8 = v7 - (_QWORD)v4;
  else
    v8 = 0i64;
  v4->vfptr = (Expression::IMemberMapVtbl *)v8;
  v9 = v1->mActionNodeReference.mOffset;
  if ( v9 )
    v10 = (signed __int64)&v1->mActionNodeReference + v9;
  else
    v10 = 0i64;
  v11 = (*(__int64 (**)(void))(*(_QWORD *)v10 + 16i64))();
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
  SpawnTrack *v1; // rbx

  v1 = this;
  NodeRefTrack<SpawnTask>::NodeRefTrack<SpawnTask>((NodeRefTrack<SpawnTask> *)&this->vfptr, SpawnTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SpawnTrack::`vftable';
  *(_WORD *)&v1->mKeepAlive = 1;
}

// File Line: 371
// RVA: 0x26D090
Expression::IMemberMap *__fastcall SpawnTrack::CreateClone(SpawnTrack *this)
{
  SpawnTrack *v1; // rsi
  char *v2; // rax
  char *v3; // rbx
  char *v4; // rdi
  __int64 v5; // rax
  __int64 v6; // rax
  signed __int64 v7; // rax
  signed __int64 v8; // rax
  __int64 v9; // rax
  signed __int64 v10; // rcx
  __int64 v11; // rax

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "SpawnTrack::CreateClone", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    NodeRefTrack<SpawnTask>::NodeRefTrack<SpawnTask>((NodeRefTrack<SpawnTask> *)v2, SpawnTrack::sClassNameUID);
    *(_QWORD *)v3 = &SpawnTrack::`vftable';
    *((_WORD *)v3 + 32) = 1;
  }
  else
  {
    v3 = 0i64;
  }
  v4 = v3 + 56;
  v5 = *((_QWORD *)v3 + 7);
  if ( v5 && &v4[v5] )
    (*(void (__fastcall **)(char *, signed __int64))(*(_QWORD *)&v4[v5] + 8i64))(&v4[v5], 1i64);
  ITrack::operator=((ITrack *)v3, (ITrack *)&v1->vfptr);
  v6 = v1->mActionNodeReference.mOffset;
  if ( v6 && (v7 = (signed __int64)&v1->mActionNodeReference + v6) != 0 )
    v8 = v7 - (_QWORD)v4;
  else
    v8 = 0i64;
  *(_QWORD *)v4 = v8;
  v3[64] = v1->mKeepAlive;
  v3[65] = v1->mSpawnedNodeActionTreeType.mValue;
  v9 = v1->mActionNodeReference.mOffset;
  if ( v9 )
    v10 = (signed __int64)&v1->mActionNodeReference + v9;
  else
    v10 = 0i64;
  v11 = (*(__int64 (**)(void))(*(_QWORD *)v10 + 16i64))();
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
  ActionNode *v2; // rbx
  SpawnTrack *v3; // rdi
  __int64 v4; // rax
  __int64 v5; // rcx
  signed __int64 v6; // rcx

  v2 = parent;
  v3 = this;
  ((void (*)(void))this->vfptr[2].FindWithOldPath)();
  ((void (__fastcall *)(SpawnTrack *, ActionNode *))v3->vfptr[1].GetResourceOwner)(v3, v2);
  v4 = v3->mActionNodeReference.mOffset;
  if ( v4 )
    v4 += (__int64)&v3->mActionNodeReference;
  v5 = *(_QWORD *)(v4 + 72);
  if ( v5 )
  {
    v6 = v4 + v5 + 72;
    if ( v6 )
      v3->mSpawnedNodeActionTreeType.mValue = *(_BYTE *)((*(__int64 (**)(void))(*(_QWORD *)v6 + 152i64))() + 236);
  }
}

