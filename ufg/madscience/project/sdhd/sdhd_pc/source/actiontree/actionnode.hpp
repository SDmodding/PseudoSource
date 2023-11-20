// File Line: 156
// RVA: 0x26E400
const char *__fastcall ActionNode::GetClassname(ActionNode *this)
{
  return ActionNode::sClassName;
}

// File Line: 158
// RVA: 0x2AF180
void __fastcall _(AMD_HD3D *this)
{
  ;
}

// File Line: 189
// RVA: 0x26FE60
ActionNode *__fastcall ActionNode::NewMemberMap(const char *fileName, unsigned __int64 toolVersion)
{
  return ActionNode::New(fileName, toolVersion);
}

// File Line: 190
// RVA: 0x26E5A0
ActionNode *__fastcall ActionNode::GetDataBaseRoot()
{
  return ActionNode::smRoot;
}

// File Line: 258
// RVA: 0x26E9C0
char *__fastcall ActionNode::GetName_DBG(ActionNode *this)
{
  return UFG::qSymbolRegistry::Get(this->mID.mUID);
}

// File Line: 267
// RVA: 0x26E950
char *__fastcall ActionNode::GetNameFullPathe_DBG(ActionNode *this)
{
  ActionPath *v1; // rax
  char *v2; // rax
  const char *v3; // rbx
  ActionPath result; // [rsp+28h] [rbp-20h]

  v1 = ActionNode::GetNameFullPath(this, &result);
  v2 = ActionPath::GetString_DBG(v1);
  v3 = v2;
  if ( result.mPath.mCount >= 0 )
  {
    if ( result.mPath.mData.mOffset )
    {
      if ( (UFG::qOffset64<ActionID *> *)((char *)&result.mPath.mData + result.mPath.mData.mOffset) )
        operator delete[]((char *)&result.mPath.mData + result.mPath.mData.mOffset);
    }
    v2 = (char *)v3;
  }
  return v2;
}

// File Line: 296
// RVA: 0x2728C0
void __fastcall ActionNode::SetParent(ActionNode *this, ActionNode *parent)
{
  UFG::qOffset64<ActionNode *> *v2; // rcx

  v2 = &this->mParent;
  if ( parent )
    v2->mOffset = (char *)parent - (char *)v2;
  else
    v2->mOffset = 0i64;
}

// File Line: 323
// RVA: 0x271600
void __fastcall ActionNode::ResolvePathReferences(ActionNode *this)
{
  this->vfptr[3].FindWithOldPath((Expression::IMemberMap *)this, (const char *)this);
}

// File Line: 344
// RVA: 0x26B630
void __fastcall ActionNode::BalanceWeights(ActionNode *this, unsigned int level, ActionContext *context)
{
  ActionContext *v3; // rsi
  unsigned int v4; // ebp
  __int64 v5; // rbx
  __int64 v6; // rdi
  signed __int64 v7; // r14
  signed __int64 v8; // rcx

  v3 = context;
  v4 = level;
  v5 = 0i64;
  v6 = ((__int64 (*)(void))this->vfptr[1].GetResourcePath)();
  v7 = v6 + *(_QWORD *)(v6 + 8) + 8i64;
  if ( *(_DWORD *)v6 & 0x7FFFFFFF )
  {
    do
    {
      v8 = v7 + 8 * v5 + *(_QWORD *)(v7 + 8 * v5);
      (*(void (__fastcall **)(signed __int64, _QWORD, ActionContext *))(*(_QWORD *)v8 + 304i64))(v8, v4, v3);
      v5 = (unsigned int)(v5 + 1);
    }
    while ( (unsigned int)v5 < (*(_DWORD *)v6 & 0x7FFFFFFFu) );
  }
}

// File Line: 562
// RVA: 0x26E730
ActionNodeRoot *__fastcall ActionNodeImplementation::GetLocalRoot(ActionNodeImplementation *this)
{
  __int64 v1; // rax
  char *v2; // rcx
  ActionNodeRoot *result; // rax

  v1 = this->mParent.mOffset;
  if ( v1 && (v2 = (char *)&this->mParent + v1) != 0i64 )
    result = (ActionNodeRoot *)(*(__int64 (**)(void))(*(_QWORD *)v2 + 144i64))();
  else
    result = 0i64;
  return result;
}

// File Line: 563
// RVA: 0x26DF70
ActionNodeRoot *__fastcall ActionNodeImplementation::GetAbsoluteRoot(ActionNodeImplementation *this)
{
  __int64 v1; // rax
  char *v2; // rcx
  ActionNodeRoot *result; // rax

  v1 = this->mParent.mOffset;
  if ( v1 && (v2 = (char *)&this->mParent + v1) != 0i64 )
    result = (ActionNodeRoot *)(*(__int64 (**)(void))(*(_QWORD *)v2 + 152i64))();
  else
    result = 0i64;
  return result;
}

// File Line: 568
// RVA: 0x26B0D0
void __fastcall ActionNodeImplementation::Accept(MemberMapFileNode *this, MemberMapFileNodeVisitor *visitor)
{
  visitor->vfptr->Visit(visitor, this);
}

// File Line: 608
// RVA: 0x26E560
ConditionGroup *__fastcall ActionNodeImplementation::GetConditionGroup2(ActionNodeImplementation *this)
{
  ConditionGroup *result; // rax

  result = (ConditionGroup *)this->mConditions.mOffset;
  if ( result )
    result = (ConditionGroup *)((char *)result + (_QWORD)this + 56);
  return result;
}

// File Line: 615
// RVA: 0x26ECA0
__int64 __fastcall ActionNodeImplementation::GetSignalMask(ActionNodeImplementation *this)
{
  __int64 v1; // rax
  char *v2; // rcx
  __int64 result; // rax

  v1 = this->mConditions.mOffset;
  if ( v1 && (v2 = (char *)&this->mConditions + v1) != 0i64 )
    result = (*(__int64 (**)(void))(*(_QWORD *)v2 + 96i64))();
  else
    result = -1i64;
  return result;
}

// File Line: 635
// RVA: 0x26E190
ActionNode *__fastcall ActionNodeImplementation::GetChild(ActionNodeImplementation *this, int priority)
{
  __int64 v2; // rax
  char *v3; // rcx
  __int64 v4; // rax
  signed __int64 v5; // rdx
  ActionNode *result; // rax

  v2 = this->mChildren.mData.mOffset;
  if ( v2 )
    v3 = (char *)&this->mChildren.mData + v2;
  else
    v3 = 0i64;
  v4 = priority;
  v5 = (signed __int64)&v3[8 * v4];
  result = *(ActionNode **)&v3[8 * v4];
  if ( result )
    result = (ActionNode *)((char *)result + v5);
  return result;
}

// File Line: 640
// RVA: 0x26E240
int __fastcall ActionNodeImplementation::GetChildCount(ActionNodeImplementation *this)
{
  return this->mChildren.mCount & 0x7FFFFFFF;
}

// File Line: 645
// RVA: 0x26EA30
ActionNode *__fastcall ActionNodeImplementation::GetNext_Sibling(ActionNodeImplementation *this)
{
  __int64 v1; // rax
  ActionNodeImplementation *v2; // rdi
  char *v3; // rcx
  BinPtrArray<ActionNode,0,0> *v4; // rax
  BinPtrArray<ActionNode,0,0> *v5; // rbx
  int v6; // eax
  __int64 v7; // rdx
  signed __int64 v8; // rcx
  signed __int64 v9; // rdx
  signed __int64 v10; // r8
  __int64 v11; // rax

  v1 = this->mParent.mOffset;
  v2 = this;
  if ( !v1 )
    return 0i64;
  v3 = (char *)&this->mParent + v1;
  if ( !v3 )
    return 0i64;
  v4 = (BinPtrArray<ActionNode,0,0> *)(*(__int64 (**)(void))(*(_QWORD *)v3 + 128i64))();
  v5 = v4;
  if ( !v4 )
    return 0i64;
  v6 = (unsigned __int64)BinPtrArray<ActionNode,0,0>::Find(v4, (ActionNode *)&v2->vfptr) + 1;
  if ( v6 >= (v5->mCount & 0x7FFFFFFF) )
    return 0i64;
  v7 = v5->mData.mOffset;
  v8 = 0i64;
  if ( v7 )
    v9 = (signed __int64)&v5->mData + v7;
  else
    v9 = 0i64;
  v10 = v9 + 8i64 * v6;
  v11 = *(_QWORD *)(v9 + 8i64 * v6);
  if ( v11 )
    v8 = v11 + v10;
  return (ActionNode *)v8;
}

// File Line: 672
// RVA: 0x2728E0
void __fastcall ActionNodeImplementation::SetParent(ActionNodeImplementation *this, ActionNode *parent)
{
  __int64 v2; // rax
  ActionNode *v3; // rbx
  ActionNodeImplementation *v4; // rdi
  char *v5; // rcx

  v2 = this->mParent.mOffset;
  v3 = parent;
  v4 = this;
  if ( v2 )
  {
    v5 = (char *)&this->mParent + v2;
    if ( v5 )
    {
      (*(void (__fastcall **)(char *, ActionNodeImplementation *))(*(_QWORD *)v5 + 184i64))(v5, v4);
      v4->mParent.mOffset = 0i64;
    }
  }
  if ( v3 )
    v3->vfptr[2].__vecDelDtor((Expression::IMemberMap *)&v3->vfptr, (unsigned int)v4);
}

// File Line: 686
// RVA: 0x26D720
void __fastcall ActionNodeImplementation::DeleteChild(ActionNodeImplementation *this, ActionNode *child)
{
  ActionNode *v2; // rbx

  v2 = child;
  ((void (*)(void))this->vfptr[2].Serialize)();
  if ( v2 )
    v2->vfptr->__vecDelDtor((Expression::IMemberMap *)&v2->vfptr, 1u);
}

// File Line: 692
// RVA: 0x270FA0
void __fastcall ActionNodeImplementation::RemoveChild(ActionNodeImplementation *this, ActionNode *child)
{
  BinPtrArray<ActionNode,0,0> *v2; // rbx
  __int64 v3; // rax
  char *v4; // rcx

  v2 = &this->mChildren;
  BinPtrArray<UELNode,0,0>::Remove(&this->mChildren, child);
  if ( !(v2->mCount & 0x7FFFFFFF) && v2->mCount >= 0 )
  {
    v3 = v2->mData.mOffset;
    if ( v3 )
    {
      v4 = (char *)&v2->mData + v3;
      if ( v4 )
        operator delete[](v4);
    }
    v2->mData.mOffset = 0i64;
    v2->mCount &= 0x80000000;
  }
}

// File Line: 699
// RVA: 0x26BFE0
void __fastcall ActionNodeImplementation::ChangeChildPriority(ActionNodeImplementation *this, ActionNode *childMove, bool increase)
{
  qNodeOrderChange<ActionNode,0>(&this->mChildren, childMove, increase);
}

// File Line: 755
// RVA: 0x26C5B0
ActionNodeBank *__fastcall ActionNodeBank::Create()
{
  ActionNodeBank *result; // rax
  ActionNodeBank *v1; // rbx
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v2; // rcx

  result = (ActionNodeBank *)UFG::qMemoryPool2::Allocate(
                               &gActionTreeMemoryPool,
                               0x78ui64,
                               "MemberMap::ActionNodeBank",
                               0i64,
                               1u);
  v1 = result;
  if ( result )
  {
    ActionNodeImplementation::ActionNodeImplementation((ActionNodeImplementation *)&result->vfptr);
    v2 = (UFG::qNode<ActionNodeBank,ActionNodeBank> *)&v1->mPrev;
    v2->mPrev = v2;
    v2->mNext = v2;
    v1->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeBank::`vftable;
    v1->m_Level = 0;
    v1->mSignalMask = -1i64;
    result = v1;
  }
  return result;
}

// File Line: 817
// RVA: 0x26C6C0
ActionNodeImplementation *__fastcall ActionNodePlayable::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x58ui64, "MemberMap::ActionNodePlayable", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ActionNodeImplementation::ActionNodeImplementation((ActionNodeImplementation *)v0);
  *(_QWORD *)v1 = &ActionNodePlayable::`vftable;
  return (ActionNodeImplementation *)v1;
}

// File Line: 822
// RVA: 0x26B0E0
void __fastcall MemberMapFileDependent::Accept(MemberMapFileDependent *this, MemberMapFileNodeVisitor *visitor)
{
  visitor->vfptr->Visit(visitor, this);
}

// File Line: 948
// RVA: 0x2689F0
void __fastcall ActionNodeReference::ActionNodeReference(ActionNodeReference *this, const char *name)
{
  ActionNodeReference *v2; // rbx
  signed __int64 v3; // [rsp+50h] [rbp+18h]

  v2 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNode::`vftable;
  this->mParent.mOffset = 0i64;
  this->mFirstCallback = 0i64;
  this->mMostUsedIndex = -1;
  this->mUniqueID = 0;
  this->mID.mUID = UFG::qStringHashUpper32(name, 0xFFFFFFFF);
  *(_DWORD *)&v2->mBreakPoint = 0;
  v2->mPad2 = 0;
  v2->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeReference::`vftable;
  v3 = (signed __int64)&v2->mAnyPathToNode;
  *(_DWORD *)v3 = 0;
  *(_QWORD *)(v3 + 8) = 0i64;
  v2->mActionNode.mOffset = 0i64;
}

// File Line: 951
// RVA: 0x26E440
const char *__fastcall ActionNodeReference::GetClassname(ActionNodeReference *this)
{
  return ActionNodeReference::sClassName;
}

// File Line: 976
// RVA: 0x26E750
ActionNodeRoot *__fastcall ActionNodeReference::GetLocalRoot(ActionNodeReference *this)
{
  __int64 v1; // rax
  char *v2; // rcx
  ActionNodeRoot *result; // rax

  v1 = this->mActionNode.mOffset;
  if ( v1 && (v2 = (char *)&this->mActionNode + v1) != 0i64 )
    result = (ActionNodeRoot *)(*(__int64 (**)(void))(*(_QWORD *)v2 + 144i64))();
  else
    result = 0i64;
  return result;
}

// File Line: 977
// RVA: 0x26DF90
ActionNodeRoot *__fastcall ActionNodeReference::GetAbsoluteRoot(ActionNodeReference *this)
{
  __int64 v1; // rax
  char *v2; // rcx
  ActionNodeRoot *result; // rax

  v1 = this->mActionNode.mOffset;
  if ( v1 && (v2 = (char *)&this->mActionNode + v1) != 0i64 )
    result = (ActionNodeRoot *)(*(__int64 (**)(void))(*(_QWORD *)v2 + 152i64))();
  else
    result = 0i64;
  return result;
}

// File Line: 991
// RVA: 0x26ECC0
__int64 __fastcall ActionNodeReference::GetSignalMask(ActionNodeReference *this)
{
  __int64 v1; // rax
  char *v2; // rcx
  __int64 result; // rax

  v1 = this->mActionNode.mOffset;
  if ( v1 && (v2 = (char *)&this->mActionNode + v1) != 0i64 )
    result = (*(__int64 (**)(void))(*(_QWORD *)v2 + 216i64))();
  else
    result = 0i64;
  return result;
}

// File Line: 1057
// RVA: 0x26E710
ActionNodePlayable *__fastcall ActionNodeReference::GetFirstPlayable(ActionNodeReference *this)
{
  __int64 v1; // rax
  char *v2; // rcx
  ActionNodePlayable *result; // rax

  v1 = this->mActionNode.mOffset;
  if ( v1 && (v2 = (char *)&this->mActionNode + v1) != 0i64 )
    result = (ActionNodePlayable *)(*(__int64 (**)(void))(*(_QWORD *)v2 + 208i64))();
  else
    result = 0i64;
  return result;
}

// File Line: 1068
// RVA: 0x26DD20
ActionNode *__fastcall ActionNodeReference::FindChild(ActionNodeReference *this, ActionID *childName, __int64 recursive)
{
  __int64 v3; // rax
  char *v4; // rcx
  ActionNode *result; // rax

  v3 = this->mActionNode.mOffset;
  if ( v3 && (v4 = (char *)&this->mActionNode + v3) != 0i64 )
    result = (ActionNode *)(*(__int64 (__fastcall **)(char *, ActionID *, __int64))(*(_QWORD *)v4 + 96i64))(
                             v4,
                             childName,
                             recursive);
  else
    result = 0i64;
  return result;
}

// File Line: 1079
// RVA: 0x26E1C0
ActionNode *__fastcall ActionNodeReference::GetChild(ActionNodeReference *this, __int64 priority)
{
  __int64 v2; // rax
  char *v3; // rcx
  ActionNode *result; // rax

  v2 = this->mActionNode.mOffset;
  if ( v2 && (v3 = (char *)&this->mActionNode + v2) != 0i64 )
    result = (ActionNode *)(*(__int64 (__fastcall **)(char *, __int64))(*(_QWORD *)v3 + 104i64))(v3, priority);
  else
    result = 0i64;
  return result;
}

// File Line: 1089
// RVA: 0x26E250
__int64 __fastcall ActionNodeReference::GetChildCount(ActionNodeReference *this)
{
  __int64 v1; // rax
  char *v2; // rcx
  __int64 result; // rax

  v1 = this->mActionNode.mOffset;
  if ( v1 && (v2 = (char *)&this->mActionNode + v1) != 0i64 )
    result = (*(__int64 (**)(void))(*(_QWORD *)v2 + 112i64))();
  else
    result = 0i64;
  return result;
}

// File Line: 1099
// RVA: 0x26EAC0
ActionNode *__fastcall ActionNodeReference::GetNext_Sibling(ActionNodeReference *this)
{
  __int64 v1; // rax
  ActionNodeReference *v2; // rbx
  __int64 v3; // rax
  char *v4; // rcx
  BinPtrArray<ActionNode,0,0> *v5; // rax
  BinPtrArray<ActionNode,0,0> *v6; // rdi
  int v7; // eax
  __int64 v8; // rdx
  signed __int64 v9; // rcx
  signed __int64 v10; // rdx
  signed __int64 v11; // r8
  __int64 v12; // rax

  v1 = this->mActionNode.mOffset;
  v2 = this;
  if ( !v1 )
    return 0i64;
  if ( !(UFG::qOffset64<ActionNode *> *)((char *)&this->mActionNode + v1) )
    return 0i64;
  v3 = this->mParent.mOffset;
  if ( !v3 )
    return 0i64;
  v4 = (char *)&this->mParent + v3;
  if ( !v4 )
    return 0i64;
  v5 = (BinPtrArray<ActionNode,0,0> *)(*(__int64 (**)(void))(*(_QWORD *)v4 + 128i64))();
  v6 = v5;
  if ( !v5 )
    return 0i64;
  v7 = (unsigned __int64)BinPtrArray<ActionNode,0,0>::Find(v5, (ActionNode *)&v2->vfptr) + 1;
  if ( v7 >= (v6->mCount & 0x7FFFFFFF) )
    return 0i64;
  v8 = v6->mData.mOffset;
  v9 = 0i64;
  if ( v8 )
    v10 = (signed __int64)&v6->mData + v8;
  else
    v10 = 0i64;
  v11 = v10 + 8i64 * v7;
  v12 = *(_QWORD *)(v10 + 8i64 * v7);
  if ( v12 )
    v9 = v12 + v11;
  return (ActionNode *)v9;
}

// File Line: 1124
// RVA: 0x26E270
BinPtrArray<ActionNode,0,0> *__fastcall ActionNodeReference::GetChildList(ActionNodeReference *this)
{
  __int64 v1; // rax
  char *v2; // rcx
  BinPtrArray<ActionNode,0,0> *result; // rax

  v1 = this->mActionNode.mOffset;
  if ( v1 && (v2 = (char *)&this->mActionNode + v1) != 0i64 )
    result = (BinPtrArray<ActionNode,0,0> *)(*(__int64 (**)(void))(*(_QWORD *)v2 + 128i64))();
  else
    result = 0i64;
  return result;
}

// File Line: 1134
// RVA: 0x26B3B0
void __fastcall ActionNodeReference::AddChild(ActionNodeReference *this, ActionNode *node)
{
  __int64 v2; // rax
  char *v3; // rcx

  v2 = this->mActionNode.mOffset;
  if ( v2 )
  {
    v3 = (char *)&this->mActionNode + v2;
    if ( v3 )
      (*(void (__fastcall **)(char *, ActionNode *))(*(_QWORD *)v3 + 168i64))(v3, node);
  }
}

// File Line: 1142
// RVA: 0x26D760
void __fastcall ActionNodeReference::DeleteChild(ActionNodeReference *this, ActionNode *node)
{
  __int64 v2; // rax
  char *v3; // rcx

  v2 = this->mActionNode.mOffset;
  if ( v2 )
  {
    v3 = (char *)&this->mActionNode + v2;
    if ( v3 )
      (*(void (__fastcall **)(char *, ActionNode *))(*(_QWORD *)v3 + 176i64))(v3, node);
  }
}

// File Line: 1150
// RVA: 0x270FF0
void __fastcall ActionNodeReference::RemoveChild(ActionNodeReference *this, ActionNode *node)
{
  __int64 v2; // rax
  char *v3; // rcx

  v2 = this->mActionNode.mOffset;
  if ( v2 )
  {
    v3 = (char *)&this->mActionNode + v2;
    if ( v3 )
      (*(void (__fastcall **)(char *, ActionNode *))(*(_QWORD *)v3 + 184i64))(v3, node);
  }
}

// File Line: 1158
// RVA: 0x26BFF0
void __fastcall ActionNodeReference::ChangeChildPriority(ActionNodeReference *this, ActionNode *child, __int64 increase)
{
  __int64 v3; // rax
  char *v4; // rcx

  v3 = this->mActionNode.mOffset;
  if ( v3 )
  {
    v4 = (char *)&this->mActionNode + v3;
    if ( v4 )
      (*(void (__fastcall **)(char *, ActionNode *, __int64))(*(_QWORD *)v4 + 192i64))(v4, child, increase);
  }
}

// File Line: 1166
// RVA: 0x26F990
ActionNodePlayable *__fastcall ActionNodeReference::Match(ActionNodeReference *this, ActionContext *context)
{
  __int64 v2; // rax
  char *v3; // rcx
  ActionNodePlayable *result; // rax

  v2 = this->mActionNode.mOffset;
  if ( v2 && (v3 = (char *)&this->mActionNode + v2) != 0i64 )
    result = (ActionNodePlayable *)(*(__int64 (__fastcall **)(char *, ActionContext *))(*(_QWORD *)v3 + 200i64))(
                                     v3,
                                     context);
  else
    result = 0i64;
  return result;
}

// File Line: 1176
// RVA: 0x26E580
ConditionGroup *__fastcall ActionNodeReference::GetConditionGroup(ActionNodeReference *this)
{
  __int64 v1; // rax
  char *v2; // rcx
  ConditionGroup *result; // rax

  v1 = this->mActionNode.mOffset;
  if ( v1 && (v2 = (char *)&this->mActionNode + v1) != 0i64 )
    result = (ConditionGroup *)(*(__int64 (**)(void))(*(_QWORD *)v2 + 272i64))();
  else
    result = 0i64;
  return result;
}

// File Line: 1186
// RVA: 0x26EEE0
TrackGroup *__fastcall ActionNodeReference::GetTrackGroup(ActionNodeReference *this)
{
  __int64 v1; // rax
  ActionNodePlayable *v2; // rcx
  TrackGroup *result; // rax

  v1 = this->mActionNode.mOffset;
  if ( v1 && (v2 = (ActionNodePlayable *)((char *)&this->mActionNode + v1)) != 0i64 )
    result = (TrackGroup *)((__int64 (*)(void))v2->vfptr[3].GetClassNameUID)();
  else
    result = 0i64;
  return result;
}

// File Line: 1196
// RVA: 0x272770
void __fastcall ActionNodeReference::SetConditionGroup(ActionNodeReference *this, ConditionGroup *conditions)
{
  __int64 v2; // rax
  char *v3; // rcx

  v2 = this->mActionNode.mOffset;
  if ( v2 )
  {
    v3 = (char *)&this->mActionNode + v2;
    if ( v3 )
      (*(void (__fastcall **)(char *, ConditionGroup *))(*(_QWORD *)v3 + 288i64))(v3, conditions);
  }
}

// File Line: 1203
// RVA: 0x272A60
void __fastcall ActionNodeReference::SetTrackGroup(ActionNodeReference *this, TrackGroup *tracks)
{
  __int64 v2; // rax
  char *v3; // rcx

  v2 = this->mActionNode.mOffset;
  if ( v2 )
  {
    v3 = (char *)&this->mActionNode + v2;
    if ( v3 )
      (*(void (__fastcall **)(char *, TrackGroup *))(*(_QWORD *)v3 + 0x128i64))(v3, tracks);
  }
}

// File Line: 1211
// RVA: 0x26B700
void __fastcall ActionNodeReference::BalanceWeights(ActionNodeReference *this, __int64 level, ActionContext *context)
{
  __int64 v3; // rax
  char *v4; // rcx

  v3 = this->mActionNode.mOffset;
  if ( v3 )
  {
    v4 = (char *)&this->mActionNode + v3;
    if ( v4 )
      (*(void (__fastcall **)(char *, __int64, ActionContext *))(*(_QWORD *)v4 + 304i64))(v4, level, context);
  }
}

// File Line: 1232
// RVA: 0x26E420
const char *__fastcall ActionNodeFileReference::GetClassname(ActionNodeFileReference *this)
{
  return ActionNodeFileReference::sClassName;
}

// File Line: 1268
// RVA: 0x26B330
void __fastcall ActionNodeFileReference::AddChild2(ActionNodeImplementation *this, Expression::IMemberMap *node)
{
  this->vfptr[2].__vecDelDtor((Expression::IMemberMap *)this, (unsigned int)node);
}

// File Line: 1269
// RVA: 0x26D710
void __fastcall ActionNodeFileReference::DeleteChild2(ActionNodeImplementation *this, Expression::IMemberMap *node)
{
  ((void (__fastcall *)(ActionNodeImplementation *, Expression::IMemberMap *))this->vfptr[2].CreateClone)(this, node);
}

// File Line: 1270
// RVA: 0x26BFD0
void __fastcall ActionNodeImplementation::ChangeChildPriority2(ActionNodeImplementation *this, Expression::IMemberMap *node, __int64 increase)
{
  ((void (__fastcall *)(ActionNodeImplementation *, Expression::IMemberMap *, __int64))this->vfptr[2].GetClassname)(
    this,
    node,
    increase);
}

// File Line: 1272
// RVA: 0x26E550
Expression::IMemberMap *__fastcall ActionNodeFileReference::GetConditionGroup2(ActionNodeFileReference *this)
{
  return (Expression::IMemberMap *)((__int64 (*)(void))this->vfptr[3].GetClassname)();
}

// File Line: 1273
// RVA: 0x26EEB0
Expression::IMemberMap *__fastcall ActionNodeFileReference::GetTrackGroup2(ActionNodeFileReference *this)
{
  return (Expression::IMemberMap *)((__int64 (*)(void))this->vfptr[3].GetClassNameUID)();
}

// File Line: 1275
// RVA: 0x272760
void __fastcall ActionNodeImplementation::SetConditionGroup2(ActionNodeImplementation *this, Expression::IMemberMap *conditions)
{
  ((void (__fastcall *)(ActionNodeImplementation *, Expression::IMemberMap *))this->vfptr[3].GetResourcePath)(
    this,
    conditions);
}

// File Line: 1276
// RVA: 0x272A30
void __fastcall ActionNodeImplementation::SetTrackGroup2(ActionNodeImplementation *this, Expression::IMemberMap *tracks)
{
  ((void (__fastcall *)(ActionNodeImplementation *, Expression::IMemberMap *))this->vfptr[3].ResolveReferences)(
    this,
    tracks);
}

// File Line: 1357
// RVA: 0x26C7C0
void __fastcall ActionNodeRoot::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xF0ui64, "MemberMap::ActionNodeRoot", 0i64, 1u);
  if ( v0 )
    ActionNodeRoot::ActionNodeRoot((ActionNodeRoot *)v0);
}

// File Line: 1360
// RVA: 0x26DFB0
ActionNodeRoot *__fastcall ActionNodeRoot::GetAbsoluteRoot(ActionNodeRoot *this)
{
  ActionNodeRoot *result; // rax
  __int64 v2; // rcx
  ActionNode *v3; // rcx

  result = this;
  v2 = this->mParent.mOffset;
  if ( v2 )
  {
    v3 = (ActionNode *)((char *)&result->mParent + v2);
    if ( v3 )
    {
      if ( v3 != ActionNode::smRoot )
        result = (ActionNodeRoot *)((__int64 (*)(void))v3->vfptr[1].GetResourceOwner)();
    }
  }
  return result;
}

// File Line: 1378
// RVA: 0x26B0F0
void __fastcall ActionNodeRoot::Accept(MemberMapFileManager *this, MemberMapFileNodeVisitor *visitor)
{
  visitor->vfptr->Visit(visitor, this);
}

// File Line: 1511
// RVA: 0x30EE60
void __fastcall NodeRefTrack<ResourceOpportunityTask>::NodeRefTrack<ResourceOpportunityTask>(NodeRefTrack<ResourceOpportunityTask> *this, unsigned int class_name_uid)
{
  NodeRefTrack<ResourceOpportunityTask> *v2; // rdi
  char *v3; // rax
  char *v4; // rbx
  char *v5; // r8
  UFG::qOffset64<ActionNodeReference *> *v6; // rax
  signed __int64 v7; // rbx
  signed __int64 v8; // [rsp+68h] [rbp+20h]

  v2 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, class_name_uid);
  v2->vfptr = (Expression::IMemberMapVtbl *)&Track<ResourceOpportunityTask>::`vftable;
  v2->vfptr = (Expression::IMemberMapVtbl *)&NodeRefTrack<ResourceOpportunityTask>::`vftable;
  v3 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "ActionNodeReference", 0i64, 1u);
  v4 = v3;
  if ( v3 )
  {
    ActionNode::ActionNode((ActionNode *)v3);
    *(_QWORD *)v4 = &ActionNodeReference::`vftable;
    v8 = (signed __int64)(v4 + 56);
    v5 = 0i64;
    *(_DWORD *)v8 = 0;
    *(_QWORD *)(v8 + 8) = 0i64;
    *((_QWORD *)v4 + 9) = 0i64;
  }
  else
  {
    v5 = 0i64;
    v4 = 0i64;
  }
  v6 = &v2->mActionNodeReference;
  if ( v4 )
    v7 = v4 - (char *)v6;
  else
    v7 = 0i64;
  v6->mOffset = v7;
  if ( v7 )
    v5 = (char *)v6 + v7;
  (*(void (__fastcall **)(char *, NodeRefTrack<ResourceOpportunityTask> *))(*(_QWORD *)v5 + 64i64))(v5, v2);
}

// File Line: 1520
// RVA: 0x299000
void __fastcall NodeRefTrack<SetOpeningBranchTask>::~NodeRefTrack<SetOpeningBranchTask>(NodeRefTrack<SetOpeningBranchTask> *this)
{
  NodeRefTrack<SetOpeningBranchTask> *v1; // rbx
  __int64 v2; // rax
  char *v3; // rcx
  ExpressionParameterFloat *v4; // rcx
  char *v5; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRefTrack<SetOpeningBranchTask>::`vftable;
  v2 = this->mActionNodeReference.mOffset;
  if ( v2 )
  {
    v3 = (char *)&this->mActionNodeReference + v2;
    if ( v3 )
      (*(void (__fastcall **)(char *, signed __int64))(*(_QWORD *)v3 + 8i64))(v3, 1i64);
  }
  v1->mActionNodeReference.mOffset = 0i64;
  v1->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
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
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 1522
// RVA: 0x2C31D0
const char *__fastcall NodeRefTrack<SpawnTask>::GetPath(NodeRefTrack<SpawnTask> *this)
{
  __int64 v1; // rax
  const char *result; // rax

  v1 = this->mActionNodeReference.mOffset;
  if ( v1 )
    result = (const char *)(*(__int64 (**)(void))(*(__int64 *)((char *)&this->mActionNodeReference.mOffset + v1) + 312))();
  else
    result = (const char *)(*(__int64 (**)(void))(MEMORY[0] + 312))();
  return result;
}

// File Line: 1523
// RVA: 0x2DCC50
void __fastcall NodeRefTrack<SetOpeningBranchTask>::SetPath(NodeRefTrack<SpawnTask> *this, const char *path)
{
  __int64 v2; // rax

  v2 = this->mActionNodeReference.mOffset;
  if ( v2 )
    (*(void (__fastcall **)(char *, const char *))(*(__int64 *)((char *)&this->mActionNodeReference.mOffset + v2) + 320))(
      (char *)&this->mActionNodeReference + v2,
      path);
  else
    (*(void (__fastcall **)(_QWORD, const char *))(MEMORY[0] + 320))(0i64, path);
}

// File Line: 1538
// RVA: 0x2DC8A0
void __fastcall NodeRefTrack<TargetPlayTask>::ResolveReferences(NodeRefTrack<TargetPlayTask> *this, ActionNode *parent)
{
  ActionNode *v2; // rbx
  NodeRefTrack<TargetPlayTask> *v3; // rdi

  v2 = parent;
  v3 = this;
  _((AMD_HD3D *)this);
  v3->vfptr[2].FindWithOldPath((Expression::IMemberMap *)&v3->vfptr, (const char *)v2);
  ((void (__fastcall *)(NodeRefTrack<TargetPlayTask> *, ActionNode *))v3->vfptr[1].GetResourceOwner)(v3, v2);
}

// File Line: 1555
// RVA: 0x271610
void __fastcall NodeRefTrack<OpportunityTask>::ResolvePathReferencesRelative(NodeRefTrack<SpawnTask> *this, ActionNode *nodeRoot)
{
  __int64 v2; // rax

  v2 = this->mActionNodeReference.mOffset;
  if ( v2 )
    (*(void (__fastcall **)(char *, ActionNode *))(*(__int64 *)((char *)&this->mActionNodeReference.mOffset + v2) + 240))(
      (char *)&this->mActionNodeReference + v2,
      nodeRoot);
  else
    (*(void (__fastcall **)(_QWORD, ActionNode *))(MEMORY[0] + 240))(0i64, nodeRoot);
}

// File Line: 1557
// RVA: 0x2DC470
bool __fastcall NodeRefTrack<SpawnTask>::IsResolved(NodeRefTrack<SpawnTask> *this, ActionNode *relative_to_node)
{
  __int64 v2; // rax
  bool result; // al

  v2 = this->mActionNodeReference.mOffset;
  if ( v2 )
    result = ActionNodeReference::IsResolved(
               (ActionNodeReference *)((char *)&this->mActionNodeReference + v2),
               relative_to_node);
  else
    result = ActionNodeReference::IsResolved(0i64, relative_to_node);
  return result;
}

// File Line: 1558
// RVA: 0x2DCAA0
void __fastcall NodeRefTrack<AttackCollisionTask>::SetActionNodeParent(NodeRefTrack<SpawnTask> *this, ActionNode *parent)
{
  __int64 v2; // rax

  v2 = this->mActionNodeReference.mOffset;
  if ( v2 )
    (*(void (__fastcall **)(char *, ActionNode *))(*(__int64 *)((char *)&this->mActionNodeReference.mOffset + v2) + 160))(
      (char *)&this->mActionNodeReference + v2,
      parent);
  else
    (*(void (__fastcall **)(_QWORD, ActionNode *))(MEMORY[0] + 160))(0i64, parent);
}

// File Line: 1587
// RVA: 0x2DC920
void __fastcall NodeRefTrack<TargetPlayTask>::Serialize(NodeRefTrack<SpawnTask> *this, IActionTreeSerializer *serializer)
{
  __int64 v2; // rax
  IActionTreeSerializer *v3; // r8
  Expression::IMemberMap *v4; // rdx

  v2 = this->mActionNodeReference.mOffset;
  v3 = serializer;
  if ( v2 )
  {
    v4 = (Expression::IMemberMap *)((char *)&this->mActionNodeReference + v2);
    if ( v4 )
      IActionTreeSerializer::PushObjectToSerialize(v3, v4);
  }
}

// File Line: 1619
// RVA: 0x268E30
void __fastcall NodeRefCondition::NodeRefCondition(NodeRefCondition *this)
{
  NodeRefCondition *v1; // rbx
  char *v2; // rax
  char *v3; // rcx
  UFG::qOffset64<ActionNodeReference *> *v4; // rax
  __int64 v5; // rcx
  signed __int64 v6; // [rsp+70h] [rbp+18h]

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->mBreakPoint = 0;
  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRefCondition::`vftable;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "ActionNodeReference", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = &Expression::IMemberMap::`vftable;
    *((_QWORD *)v2 + 1) = 0i64;
    *(_QWORD *)v2 = &ActionNode::`vftable;
    *((_QWORD *)v2 + 2) = 0i64;
    *((_QWORD *)v2 + 3) = 0i64;
    *((_DWORD *)v2 + 8) = -1;
    *(_QWORD *)(v2 + 36) = 0i64;
    *((_DWORD *)v2 + 11) = 0;
    v2[48] = 0;
    *(_QWORD *)v2 = &ActionNodeReference::`vftable;
    v6 = (signed __int64)(v2 + 56);
    *(_DWORD *)v6 = 0;
    *(_QWORD *)(v6 + 8) = 0i64;
    *((_QWORD *)v2 + 9) = 0i64;
  }
  else
  {
    v3 = 0i64;
  }
  v4 = &v1->mActionNodeReference;
  if ( v3 )
    v5 = v3 - (char *)v4;
  else
    v5 = 0i64;
  v4->mOffset = v5;
}

// File Line: 1628
// RVA: 0x269EB0
void __fastcall NodeRefCondition::~NodeRefCondition(NodeRefCondition *this)
{
  NodeRefCondition *v1; // rbx
  __int64 v2; // rax
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRefCondition::`vftable;
  v2 = this->mActionNodeReference.mOffset;
  if ( v2 )
  {
    v3 = (char *)&this->mActionNodeReference + v2;
    if ( v3 )
      (*(void (__fastcall **)(char *, signed __int64))(*(_QWORD *)v3 + 8i64))(v3, 1i64);
  }
  v1->mActionNodeReference.mOffset = 0i64;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 1630
// RVA: 0x26EB70
const char *__fastcall NodeRefCondition::GetPath(NodeRefCondition *this)
{
  __int64 v1; // rax
  const char *result; // rax

  v1 = this->mActionNodeReference.mOffset;
  if ( v1 )
    result = (const char *)(*(__int64 (**)(void))(*(__int64 *)((char *)&this->mActionNodeReference.mOffset + v1) + 312))();
  else
    result = (const char *)(*(__int64 (**)(void))(MEMORY[0] + 312))();
  return result;
}

// File Line: 1631
// RVA: 0x2729E0
void __fastcall NodeRefCondition::SetPath(NodeRefCondition *this, const char *path)
{
  __int64 v2; // rax

  v2 = this->mActionNodeReference.mOffset;
  if ( v2 )
    (*(void (__fastcall **)(char *, const char *))(*(__int64 *)((char *)&this->mActionNodeReference.mOffset + v2) + 320))(
      (char *)&this->mActionNodeReference + v2,
      path);
  else
    (*(void (__fastcall **)(_QWORD, const char *))(MEMORY[0] + 320))(0i64, path);
}

// File Line: 1634
// RVA: 0x26FF90
void __fastcall NodeRefCondition::OnAddedAsResource(NodeRefCondition *this)
{
  NodeRefCondition *v1; // rdi
  __int64 v2; // rbx
  int v3; // eax

  v1 = this;
  v2 = ((__int64 (*)(void))this->vfptr->GetResourceOwner)();
  if ( v2 )
  {
    while ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v2 + 40i64))(v2) == ConditionGroup::sClassNameUID )
    {
      v2 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 72i64))(v2);
      if ( !v2 )
        return;
    }
    v3 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 40i64))(v2);
    if ( v3 == ActionNode::sClassNameUID
      || v3 == ActionNodeRoot::sClassNameUID
      || v3 == ActionNodePlayable::sClassNameUID
      || v3 == ActionNodeBank::sClassNameUID
      || v3 == ActionNodeFileReference::sClassNameUID )
    {
      v1->vfptr[2].Serialize((Expression::IMemberMap *)&v1->vfptr, (IActionTreeSerializer *)v2);
    }
  }
}

// File Line: 1649
// RVA: 0x271DF0
void __fastcall NodeRefCondition::ResolveReferences(NodeRefCondition *this, ActionNode *parent)
{
  ActionNode *v2; // rbx
  NodeRefCondition *v3; // rdi

  v2 = parent;
  v3 = this;
  ((void (*)(void))this->vfptr[2].Serialize)();
  ((void (__fastcall *)(NodeRefCondition *, ActionNode *))v3->vfptr[2].CreateClone)(v3, v2);
}

// File Line: 1664
// RVA: 0x271780
void __fastcall NodeRefCondition::ResolvePathReferencesRelative(QueryCondition *this, ActionNode *root)
{
  __int64 v2; // rax

  v2 = this->mActionNodeReference.mOffset;
  if ( v2 )
    (*(void (__fastcall **)(char *, ActionNode *))(*(__int64 *)((char *)&this->mActionNodeReference.mOffset + v2) + 240))(
      (char *)&this->mActionNodeReference + v2,
      root);
  else
    (*(void (__fastcall **)(_QWORD, ActionNode *))(MEMORY[0] + 240))(0i64, root);
}

// File Line: 1666
// RVA: 0x26F720
bool __fastcall NodeRefCondition::IsResolved(NodeRefCondition *this, ActionNode *relative_to_node)
{
  __int64 v2; // rax
  bool result; // al

  v2 = this->mActionNodeReference.mOffset;
  if ( v2 )
    result = ActionNodeReference::IsResolved(
               (ActionNodeReference *)((char *)&this->mActionNodeReference + v2),
               relative_to_node);
  else
    result = ActionNodeReference::IsResolved(0i64, relative_to_node);
  return result;
}

// File Line: 1698
// RVA: 0x2DCE90
void __fastcall ActionNode_Visitor::Visit(ActionNode_Visitor *this, ActionNodeRoot *node)
{
  ActionNode_Visitor::visit_children(this, (ActionNode *)&node->vfptr);
}

// File Line: 1733
// RVA: 0x2DD090
void __fastcall ActionNode_Visitor::visit_children(ActionNode_Visitor *this, ActionNode *node)
{
  ActionNode_Visitor *v2; // rsi
  __int64 v3; // rbx
  __int64 v4; // rdi
  signed __int64 v5; // r14
  signed __int64 v6; // rcx

  v2 = this;
  v3 = 0i64;
  v4 = ((__int64 (__fastcall *)(ActionNode *))node->vfptr[1].GetResourcePath)(node);
  v5 = v4 + *(_QWORD *)(v4 + 8) + 8i64;
  if ( *(_DWORD *)v4 & 0x7FFFFFFF )
  {
    do
    {
      v6 = v5 + 8 * v3 + *(_QWORD *)(v5 + 8 * v3);
      (*(void (__fastcall **)(signed __int64, ActionNode_Visitor *))(*(_QWORD *)v6 + 136i64))(v6, v2);
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < (*(_DWORD *)v4 & 0x7FFFFFFFu) );
  }
}

