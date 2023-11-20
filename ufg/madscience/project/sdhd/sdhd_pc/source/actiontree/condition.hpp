// File Line: 92
// RVA: 0x269D60
void __fastcall Condition::~Condition(Condition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 212
// RVA: 0x269D90
void __fastcall ConditionGroup::~ConditionGroup(ConditionGroup *this)
{
  ConditionGroup *v1; // rbx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ConditionGroup::`vftable';
  BinPtrArray<JointReferences,1,0>::Clear((BinPtrArray<ITrack,1,0> *)&this->mConditions);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 241
// RVA: 0x26E310
__int64 __fastcall ConditionGroup::GetClassNameUID(ConditionGroup *this)
{
  return ConditionGroup::sClassNameUID;
}

// File Line: 333
// RVA: 0x271BC0
void __fastcall ConditionGroup::ResolveReferences(ConditionGroup *this, ActionNode *parent)
{
  __int64 v2; // rbx
  ActionNode *v3; // rsi
  ConditionGroup *v4; // rdi
  char *v5; // r14
  signed __int64 v6; // rcx

  v2 = 0i64;
  v3 = parent;
  v4 = this;
  v5 = (char *)&this->mConditions.mData + this->mConditions.mData.mOffset;
  if ( this->mConditions.mCount & 0x7FFFFFFF )
  {
    do
    {
      v6 = (signed __int64)&v5[8 * v2 + *(_QWORD *)&v5[8 * v2]];
      (*(void (__fastcall **)(signed __int64, ActionNode *))(*(_QWORD *)v6 + 120i64))(v6, v3);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < (v4->mConditions.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 342
// RVA: 0x271710
void __fastcall ConditionGroup::ResolvePathReferencesRelative(ConditionGroup *this, ActionNode *nodeRoot)
{
  __int64 v2; // rbx
  ActionNode *v3; // rsi
  ConditionGroup *v4; // rdi
  char *v5; // r14
  signed __int64 v6; // rcx

  v2 = 0i64;
  v3 = nodeRoot;
  v4 = this;
  v5 = (char *)&this->mConditions.mData + this->mConditions.mData.mOffset;
  if ( this->mConditions.mCount & 0x7FFFFFFF )
  {
    do
    {
      v6 = (signed __int64)&v5[8 * v2 + *(_QWORD *)&v5[8 * v2]];
      (*(void (__fastcall **)(signed __int64, ActionNode *))(*(_QWORD *)v6 + 128i64))(v6, v3);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < (v4->mConditions.mCount & 0x7FFFFFFFu) );
  }
}

