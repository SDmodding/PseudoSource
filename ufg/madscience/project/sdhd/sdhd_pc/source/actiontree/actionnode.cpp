// File Line: 247
// RVA: 0x26EF00
void ActionNode::Init(void)
{
  char *v0; // rdi
  UFG::allocator::free_link *v1; // rax
  UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *v2; // rcx
  UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *mPrev; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x78ui64, "ActionNode::Init", 0i64, 1u);
  if ( v0 )
  {
    *(_QWORD *)v0 = &Expression::IMemberMap::`vftable;
    *((_QWORD *)v0 + 1) = 0i64;
    *(_QWORD *)v0 = &ActionNode::`vftable;
    *((_QWORD *)v0 + 2) = 0i64;
    *((_QWORD *)v0 + 3) = 0i64;
    *((_DWORD *)v0 + 8) = -1;
    *((_DWORD *)v0 + 9) = 0;
    *((_DWORD *)v0 + 10) = UFG::qStringHashUpper32("Global", -1);
    *((_DWORD *)v0 + 11) = 0;
    v0[48] = 0;
    *(_QWORD *)v0 = &ActionNodeImplementation::`vftable;
    *((_DWORD *)v0 + 18) = 0;
    *((_QWORD *)v0 + 10) = 0i64;
    *((_QWORD *)v0 + 7) = 0i64;
    *((_QWORD *)v0 + 8) = 0i64;
    *((_QWORD *)v0 + 11) = v0 + 88;
    *((_QWORD *)v0 + 12) = v0 + 88;
    *(_QWORD *)v0 = &ActionNodeBank::`vftable;
    *((_WORD *)v0 + 52) = 0;
    v0[106] = 0;
    *((_QWORD *)v0 + 14) = -1i64;
  }
  else
  {
    v0 = 0i64;
  }
  ActionNode::smRoot = (ActionNode *)v0;
  v1 = UFG::qMalloc(0x40ui64, "MemberMapLoadHandler", 0i64);
  v2 = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)v1;
  if ( v1 )
  {
    v1->mNext = v1;
    v1[1].mNext = v1;
    v1[2].mNext = 0i64;
    v1[3].mNext = 0i64;
    v1[4].mNext = 0i64;
    v1[5].mNext = 0i64;
    v1[6].mNext = 0i64;
    v1[7].mNext = 0i64;
  }
  else
  {
    v2 = 0i64;
  }
  v2[1].mPrev = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)"act";
  v2[1].mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)"ActionTree";
  v2[2].mPrev = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)ActionNode::Load;
  v2[2].mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)ActionNode::NewMemberMap;
  v2[3].mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)ActionNode::GetDataBaseRoot;
  mPrev = Expression::IMemberMap::smFileHandlers.mNode.mPrev;
  Expression::IMemberMap::smFileHandlers.mNode.mPrev->mNext = v2;
  v2->mPrev = mPrev;
  v2->mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)&Expression::IMemberMap::smFileHandlers;
  Expression::IMemberMap::smFileHandlers.mNode.mPrev = v2;
}

// File Line: 517
// RVA: 0x26DBE0
ActionNode *__fastcall ActionNode::Find(ActionPath *absolutePath, ActionNode *absoluteRoot)
{
  unsigned int v3; // ebx
  ActionNode *result; // rax
  unsigned int v5; // esi
  __int64 v6; // rdi
  __int64 mOffset; // rcx
  char *v8; // rdx
  int v9; // [rsp+30h] [rbp+8h] BYREF

  v3 = absolutePath->mPath.mCount & 0x7FFFFFFF;
  if ( v3 <= 1 )
    return 0i64;
  result = ActionNode::smRoot;
  v5 = 1;
  if ( absoluteRoot )
    result = absoluteRoot;
  v6 = 4i64;
  do
  {
    if ( !result )
      break;
    mOffset = absolutePath->mPath.mData.mOffset;
    v8 = mOffset ? (char *)&absolutePath->mPath.mData + mOffset : 0i64;
    v9 = *(_DWORD *)&v8[v6];
    result = (ActionNode *)((__int64 (__fastcall *)(ActionNode *, int *, _QWORD))result->vfptr[1].CreateClone)(
                             result,
                             &v9,
                             0i64);
    ++v5;
    v6 += 4i64;
  }
  while ( v5 < v3 );
  return result;
}

// File Line: 548
// RVA: 0x26DE60
ActionNode *__fastcall ActionNode::FindWithOldPath(ActionNode *this, const char *resourcePath)
{
  ActionNode *v2; // rbx
  unsigned int v3; // edi
  unsigned int v4; // esi
  __int64 v5; // r14
  char *v6; // rcx
  int mCount; // edx
  ActionPath v9[2]; // [rsp+28h] [rbp-20h] BYREF
  int v10; // [rsp+60h] [rbp+18h] BYREF

  v9[0].mPath.mCount = 0;
  v9[0].mPath.mData.mOffset = 0i64;
  ActionPath::Append(v9, resourcePath);
  v2 = 0i64;
  v3 = v9[0].mPath.mCount & 0x7FFFFFFF;
  if ( (v9[0].mPath.mCount & 0x7FFFFFFFu) > 1 )
  {
    v2 = ActionNode::smRoot;
    v4 = 1;
    if ( v3 > 1 )
    {
      v5 = 4i64;
      do
      {
        if ( !v2 )
          break;
        v6 = v9[0].mPath.mData.mOffset ? (char *)&v9[0].mPath.mData + v9[0].mPath.mData.mOffset : 0i64;
        v10 = *(_DWORD *)&v6[v5];
        v2 = (ActionNode *)((__int64 (__fastcall *)(ActionNode *, int *, _QWORD))v2->vfptr[1].CreateClone)(
                             v2,
                             &v10,
                             0i64);
        ++v4;
        v5 += 4i64;
      }
      while ( v4 < v3 );
    }
  }
  mCount = v9[0].mPath.mCount;
  if ( v9[0].mPath.mCount >= 0 )
  {
    if ( v9[0].mPath.mData.mOffset
      && (UFG::qOffset64<ActionID *> *)((char *)&v9[0].mPath.mData + v9[0].mPath.mData.mOffset) )
    {
      operator delete[]((char *)&v9[0].mPath.mData + v9[0].mPath.mData.mOffset);
      mCount = v9[0].mPath.mCount;
    }
    v9[0].mPath.mData.mOffset = 0i64;
    v9[0].mPath.mCount = mCount & 0x80000000;
  }
  return v2;
}

// File Line: 558
// RVA: 0x1480430
__int64 dynamic_initializer_for__ActionNode::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActionNode", 0xFFFFFFFF);
  ActionNode::sClassNameUID = result;
  return result;
}

// File Line: 564
// RVA: 0x268910
void __fastcall ActionNode::ActionNode(ActionNode *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNode::`vftable;
  this->mParent.mOffset = 0i64;
  this->mFirstCallback = 0i64;
  this->mMostUsedIndex = -1;
  *(_QWORD *)&this->mUniqueID = 0i64;
  *(_DWORD *)&this->mBreakPoint = 0;
  this->mPad2 = 0;
}

// File Line: 608
// RVA: 0x269790
void __fastcall ActionNode::~ActionNode(ActionNode *this)
{
  __int64 mOffset; // rax
  char *v3; // rcx
  char *mFirstCallback; // rdx
  char *v5; // rbx

  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNode::`vftable;
  mOffset = this->mParent.mOffset;
  if ( mOffset )
  {
    v3 = (char *)&this->mParent + mOffset;
    if ( v3 )
      (*(void (__fastcall **)(char *, ActionNode *))(*(_QWORD *)v3 + 184i64))(v3, this);
  }
  mFirstCallback = (char *)this->mFirstCallback;
  if ( mFirstCallback )
  {
    do
    {
      v5 = *(char **)mFirstCallback;
      UFG::qMemoryPool2::Free(&gActionTreeMemoryPool, mFirstCallback, 0x20ui64);
      mFirstCallback = v5;
    }
    while ( v5 );
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 627
// RVA: 0x2722C0
void __fastcall ActionNode::Serialize(ActionNode *this, IActionTreeSerializer *serializer)
{
  UFG::qOffset64<ActionNode *> *p_mParent; // rdx
  unsigned int v4; // eax
  __int64 mOffset; // rcx
  ActionNode *v6; // rcx
  char *v7; // rcx
  unsigned int *i; // rcx

  p_mParent = &this->mParent;
  v4 = 0;
  mOffset = this->mParent.mOffset;
  if ( mOffset )
    v6 = (ActionNode *)((char *)p_mParent + mOffset);
  else
    v6 = 0i64;
  if ( v6 == ActionNode::smRoot )
  {
    p_mParent->mOffset = 0i64;
    if ( ActionNode::smRoot )
      v7 = (char *)((char *)ActionNode::smRoot - (char *)p_mParent);
    else
      v7 = 0i64;
    p_mParent->mOffset = (__int64)v7;
  }
  for ( i = gMostUsedTable; *i != this->mID.mUID; ++i )
  {
    if ( ++v4 >= 0x40 )
    {
      this->mMostUsedIndex = -1;
      return;
    }
  }
  this->mMostUsedIndex = v4;
}

// File Line: 668
// RVA: 0x26E7A0
ActionPath *__fastcall ActionNode::GetNameFullPath(ActionNode *this, ActionPath *result)
{
  result->mPath.mCount = 0;
  result->mPath.mData.mOffset = 0i64;
  ActionNode::GetNameFullPath(this, result);
  return result;
}

// File Line: 675
// RVA: 0x26E7E0
void __fastcall ActionNode::GetNameFullPath(ActionNode *this, ActionPath *pathToPopulate)
{
  int v2; // r8d
  __int64 *v4; // rax
  __int64 mOffset; // rdx
  UFG::qOffset64<ActionNode *> *p_mParent; // rcx
  __int64 v7; // rbx
  __int64 i; // rdx
  __int64 v9; // rax
  char *v10; // rcx
  unsigned int mCount; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // edx
  __int64 v15; // rcx
  __int64 v16; // r8
  __int64 v17; // rax
  char *v18; // rdx
  int v19; // eax
  int v20[40]; // [rsp+20h] [rbp-1E8h]
  __int64 v21[41]; // [rsp+C0h] [rbp-148h] BYREF

  v2 = 0;
  if ( this )
  {
    v4 = v21;
    do
    {
      mOffset = this->mParent.mOffset;
      *v4 = (__int64)this;
      p_mParent = &this->mParent;
      ++v2;
      ++v4;
      if ( !mOffset )
        break;
      this = (ActionNode *)((char *)p_mParent + mOffset);
    }
    while ( this );
  }
  v7 = 0i64;
  for ( i = v2 - 1; i >= 0; --i )
  {
    v20[v7] = *(_DWORD *)(v21[i] + 40);
    v7 = (unsigned int)(v7 + 1);
  }
  if ( pathToPopulate->mPath.mCount >= 0 )
  {
    v9 = pathToPopulate->mPath.mData.mOffset;
    if ( v9 )
    {
      v10 = (char *)&pathToPopulate->mPath.mData + v9;
      if ( v10 )
        operator delete[](v10);
    }
    pathToPopulate->mPath.mData.mOffset = 0i64;
    pathToPopulate->mPath.mCount &= 0x80000000;
  }
  mCount = pathToPopulate->mPath.mCount;
  v12 = pathToPopulate->mPath.mCount & 0x7FFFFFFF;
  if ( (int)(v7 - v12) <= 0 )
  {
    v14 = v12 - v7;
    if ( v12 != (_DWORD)v7 )
    {
      if ( v14 < v12 )
        pathToPopulate->mPath.mCount = mCount ^ (mCount ^ (mCount - v14)) & 0x7FFFFFFF;
      else
        pathToPopulate->mPath.mCount = mCount & 0x80000000;
    }
  }
  else
  {
    if ( (unsigned int)v7 > mCount )
    {
      v13 = 1;
      if ( mCount )
        v13 = 2 * mCount;
      for ( ; v13 < (unsigned int)v7; v13 *= 2 )
        ;
      if ( v13 - (unsigned int)v7 > 0x10000 )
        v13 = v7 + 0x10000;
      BinArray<ActionID,0>::Reallocate(&pathToPopulate->mPath, v13, "ActionID.Set");
    }
    pathToPopulate->mPath.mCount &= 0x80000000;
    pathToPopulate->mPath.mCount |= v7 & 0x7FFFFFFF;
  }
  if ( (_DWORD)v7 )
  {
    v15 = 0i64;
    v16 = (unsigned int)v7;
    do
    {
      v17 = pathToPopulate->mPath.mData.mOffset;
      if ( v17 )
        v18 = (char *)&pathToPopulate->mPath.mData + v17;
      else
        v18 = 0i64;
      v19 = v20[v15++];
      *(_DWORD *)&v18[v15 * 4 - 4] = v19;
      --v16;
    }
    while ( v16 );
  }
}

// File Line: 707
// RVA: 0x26EBD0
void __fastcall ActionNode::GetResourcePath(ActionNode *this, char *path, int pathSize)
{
  ActionPath *NameFullPath; // rax
  char *String_DBG; // rax
  ActionPath result; // [rsp+28h] [rbp-20h] BYREF

  NameFullPath = ActionNode::GetNameFullPath(this, &result);
  String_DBG = ActionPath::GetString_DBG(NameFullPath);
  UFG::qSPrintf(path, pathSize, String_DBG);
  if ( result.mPath.mCount >= 0 && result.mPath.mData.mOffset )
  {
    if ( (UFG::qOffset64<ActionID *> *)((char *)&result.mPath.mData + result.mPath.mData.mOffset) )
      operator delete[]((char *)&result.mPath.mData + result.mPath.mData.mOffset);
  }
}

// File Line: 712
// RVA: 0x26DD40
ActionNode *__fastcall ActionNode::FindRelative(ActionNode *this, ActionPath *relativePath)
{
  unsigned int v5; // ebp
  unsigned int v6; // edi
  __int64 v7; // rsi
  __int64 mOffset; // rax
  char *v9; // rcx
  int v10; // eax
  UFG::qOffset64<ActionNode *> *p_mParent; // rbx
  int v12; // [rsp+58h] [rbp+10h] BYREF

  if ( !relativePath )
    return 0i64;
  v5 = relativePath->mPath.mCount & 0x7FFFFFFF;
  if ( !v5 )
    return 0i64;
  v6 = 0;
  if ( v5 )
  {
    v7 = 0i64;
    do
    {
      if ( !this )
        break;
      mOffset = relativePath->mPath.mData.mOffset;
      if ( mOffset )
        v9 = (char *)&relativePath->mPath.mData + mOffset;
      else
        v9 = 0i64;
      v10 = *(_DWORD *)&v9[v7];
      v12 = v10;
      if ( (_S8_6 & 1) == 0 )
      {
        _S8_6 |= 1u;
        dword_1423AFFC8 = UFG::qStringHashUpper32("..", -1);
        v10 = v12;
      }
      if ( v10 == dword_1423AFFC8 )
      {
        p_mParent = &this->mParent;
        this = p_mParent->mOffset ? (ActionNode *)((char *)p_mParent + p_mParent->mOffset) : 0i64;
      }
      else
      {
        if ( (_S6_6 & 1) == 0 )
        {
          _S6_6 |= 1u;
          dword_1423AFFC0 = UFG::qStringHashUpper32(".", -1);
          v10 = v12;
        }
        if ( v10 != dword_1423AFFC0 )
          this = (ActionNode *)((__int64 (__fastcall *)(ActionNode *, int *, _QWORD))this->vfptr[1].CreateClone)(
                                 this,
                                 &v12,
                                 0i64);
      }
      ++v6;
      v7 += 4i64;
    }
    while ( v6 < v5 );
  }
  return this;
}

// File Line: 786
// RVA: 0x272030
void ActionNode::ResolveReferencesGlobal(void)
{
  if ( ActionNode::smRoot )
  {
    ActionNode::sIsResolvingAllGlobal = 1;
    ActionNode::smRoot->vfptr->ResolveReferences(ActionNode::smRoot);
    ActionNode::sIsResolvingAllGlobal = 0;
  }
}

// File Line: 808
// RVA: 0x271890
void __fastcall ActionNode::ResolveReferences(ActionNode *this)
{
  __int64 v2; // rax
  ConditionGroup *v3; // rax
  ConditionGroup *v4; // rdi
  __int64 v5; // rax
  _DWORD *v6; // rdi
  __int64 v7; // rbx
  __int64 v8; // rsi
  __int64 v9; // rcx

  v2 = ((__int64 (__fastcall *)(ActionNode *))this->vfptr[3].GetClassNameUID)(this);
  if ( v2 )
    (*(void (__fastcall **)(__int64, ActionNode *))(*(_QWORD *)v2 + 80i64))(v2, this);
  v3 = (ConditionGroup *)this->vfptr[3].GetClassname(this);
  v4 = v3;
  if ( v3 )
  {
    ConditionGroup::ResortEntries(v3);
    ((void (__fastcall *)(ConditionGroup *, ActionNode *))v4->vfptr[1].GetClassNameUID)(v4, this);
  }
  v5 = ((__int64 (__fastcall *)(ActionNode *))this->vfptr[1].GetResourcePath)(this);
  v6 = (_DWORD *)v5;
  if ( v5 )
  {
    v7 = 0i64;
    v8 = v5 + *(_QWORD *)(v5 + 8) + 8i64;
    if ( (*(_DWORD *)v5 & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v9 = *(_QWORD *)(v8 + 8 * v7) + v8 + 8 * v7;
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 56i64))(v9);
        v7 = (unsigned int)(v7 + 1);
      }
      while ( (unsigned int)v7 < (*v6 & 0x7FFFFFFFu) );
    }
  }
}

// File Line: 887
// RVA: 0x271640
void __fastcall ActionNode::ResolvePathReferencesRelative(ActionNode *this, ActionNode *nodeRoot)
{
  __int64 v4; // rax
  ConditionGroup *v5; // rax
  ConditionGroup *v6; // rdi
  __int64 v7; // rax
  _DWORD *v8; // rdi
  __int64 v9; // rbx
  __int64 v10; // r14
  __int64 v11; // rcx

  v4 = ((__int64 (__fastcall *)(ActionNode *))this->vfptr[3].GetClassNameUID)(this);
  if ( v4 )
    (*(void (__fastcall **)(__int64, ActionNode *))(*(_QWORD *)v4 + 88i64))(v4, nodeRoot);
  v5 = (ConditionGroup *)this->vfptr[3].GetClassname(this);
  v6 = v5;
  if ( v5 )
  {
    ConditionGroup::ResortEntries(v5);
    ((void (__fastcall *)(ConditionGroup *, ActionNode *))v6->vfptr[1].GetResourcePath)(v6, nodeRoot);
  }
  v7 = ((__int64 (__fastcall *)(ActionNode *))this->vfptr[1].GetResourcePath)(this);
  v8 = (_DWORD *)v7;
  if ( v7 )
  {
    v9 = 0i64;
    v10 = v7 + *(_QWORD *)(v7 + 8) + 8i64;
    if ( (*(_DWORD *)v7 & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v11 = *(_QWORD *)(v10 + 8 * v9) + v10 + 8 * v9;
        (*(void (__fastcall **)(__int64, ActionNode *))(*(_QWORD *)v11 + 240i64))(v11, nodeRoot);
        v9 = (unsigned int)(v9 + 1);
      }
      while ( (unsigned int)v9 < (*v8 & 0x7FFFFFFFu) );
    }
  }
}

// File Line: 914
// RVA: 0x271010
void __fastcall ActionNode::RemoveReferences(ActionNode *this)
{
  __int64 v2; // rax
  __int64 v3; // rbx
  __int64 v4; // rsi
  unsigned int v5; // edi
  __int64 v6; // r15
  __int64 v7; // rcx
  __int64 v8; // rax
  _DWORD *v9; // rdi
  __int64 v10; // rsi
  __int64 v11; // rcx

  v2 = ((__int64 (*)(void))this->vfptr[3].GetClassNameUID)();
  v3 = 0i64;
  v4 = v2;
  if ( v2 )
  {
    v5 = 0;
    v6 = v2 + *(_QWORD *)(v2 + 24) + 24i64;
    if ( (*(_DWORD *)(v2 + 16) & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v7 = *(_QWORD *)(v6 + 8i64 * v5) + v6 + 8i64 * v5;
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v7 + 104i64))(v7);
        ++v5;
      }
      while ( v5 < (*(_DWORD *)(v4 + 16) & 0x7FFFFFFFu) );
    }
  }
  v8 = ((__int64 (__fastcall *)(ActionNode *))this->vfptr[1].GetResourcePath)(this);
  v9 = (_DWORD *)v8;
  if ( v8 )
  {
    v10 = v8 + *(_QWORD *)(v8 + 8) + 8i64;
    if ( (*(_DWORD *)v8 & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v11 = v10 + 8 * v3 + *(_QWORD *)(v10 + 8 * v3);
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v11 + 248i64))(v11);
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < (*v9 & 0x7FFFFFFFu) );
    }
  }
}

// File Line: 938
// RVA: 0x2714E0
void __fastcall ActionNode::ResolveFileReferences(ActionNode *this)
{
  __int64 v1; // rax
  _DWORD *v2; // rdi
  __int64 v3; // rbx
  __int64 v4; // rsi
  __int64 v5; // rcx

  v1 = ((__int64 (__fastcall *)(ActionNode *))this->vfptr[1].GetResourcePath)(this);
  v2 = (_DWORD *)v1;
  if ( v1 )
  {
    v3 = 0i64;
    v4 = v1 + *(_QWORD *)(v1 + 8) + 8i64;
    if ( (*(_DWORD *)v1 & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v5 = *(_QWORD *)(v4 + 8 * v3) + v4 + 8 * v3;
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 224i64))(v5);
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < (*v2 & 0x7FFFFFFFu) );
    }
  }
}

// File Line: 1106
// RVA: 0x268960
void __fastcall ActionNodeImplementation::ActionNodeImplementation(ActionNodeImplementation *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNode::`vftable;
  this->mParent.mOffset = 0i64;
  this->mFirstCallback = 0i64;
  this->mMostUsedIndex = -1;
  this->mUniqueID = 0;
  this->mID.mUID = UFG::qStringHashUpper32("NO_NAME", -1);
  *(_DWORD *)&this->mBreakPoint = 0;
  this->mPad2 = 0;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeImplementation::`vftable;
  this->mChildren.mCount = 0;
  this->mChildren.mData.mOffset = 0i64;
  this->mConditions.mOffset = 0i64;
  this->mTracks.mOffset = 0i64;
}

// File Line: 1175
// RVA: 0x269A10
void __fastcall ActionNodeImplementation::~ActionNodeImplementation(ActionNodeImplementation *this)
{
  __int64 mOffset; // rax
  __int64 v3; // rax
  char *v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rax
  char *v7; // rcx
  __int64 v8; // rax
  char *v9; // rcx
  char *v10; // rdx
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 v13; // rax
  char *v14; // rcx
  __int64 v15; // rax
  char *v16; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeImplementation::`vftable;
  mOffset = this->mConditions.mOffset;
  if ( mOffset )
  {
    if ( (UFG::qOffset64<ConditionGroup *> *)((char *)&this->mConditions + mOffset) )
    {
      v3 = this->mConditions.mOffset;
      if ( v3 )
      {
        v4 = (char *)&this->mConditions + v3;
        if ( v4 )
          (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)v4 + 8i64))(v4, 1i64);
      }
    }
  }
  v5 = this->mTracks.mOffset;
  if ( v5 )
  {
    if ( (UFG::qOffset64<TrackGroup *> *)((char *)&this->mTracks + v5) )
    {
      v6 = this->mTracks.mOffset;
      if ( v6 )
      {
        v7 = (char *)&this->mTracks + v6;
        if ( v7 )
          (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)v7 + 8i64))(v7, 1i64);
      }
    }
  }
  while ( (this->mChildren.mCount & 0x7FFFFFFF) != 0 )
  {
    v8 = this->mChildren.mData.mOffset;
    if ( v8 )
      v9 = (char *)&this->mChildren.mData + v8;
    else
      v9 = 0i64;
    v10 = &v9[8 * (this->mChildren.mCount & 0x7FFFFFFF) - 8];
    v11 = *(_QWORD *)v10;
    if ( *(_QWORD *)v10 && &v10[v11] )
      (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)&v10[v11] + 8i64))(&v10[v11], 1i64);
  }
  v12 = this->mParent.mOffset;
  if ( v12 && (UFG::qOffset64<ActionNode *> *)((char *)&this->mParent + v12) )
  {
    v13 = this->mParent.mOffset;
    if ( v13 )
      v14 = (char *)&this->mParent + v13;
    else
      v14 = 0i64;
    (*(void (__fastcall **)(char *, ActionNodeImplementation *))(*(_QWORD *)v14 + 184i64))(v14, this);
    this->mParent.mOffset = 0i64;
  }
  if ( this->mChildren.mCount >= 0 )
  {
    v15 = this->mChildren.mData.mOffset;
    if ( v15 )
    {
      v16 = (char *)&this->mChildren.mData + v15;
      if ( v16 )
        operator delete[](v16);
    }
    this->mChildren.mData.mOffset = 0i64;
    this->mChildren.mCount &= 0x80000000;
  }
  ActionNode::~ActionNode(this);
}

// File Line: 1213
// RVA: 0x26C340
void __fastcall ActionNodeImplementation::CopyFrom(
        ActionNodeImplementation *this,
        ActionNodeImplementation *source_action_node)
{
  __int64 mOffset; // rax
  UFG::qOffset64<ConditionGroup *> *p_mConditions; // rbx
  __int64 v6; // rax
  char *v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rax
  UFG::qOffset64<TrackGroup *> *p_mTracks; // rbx
  __int64 v11; // rax
  char *v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rbp
  char *v15; // r14
  __int64 v16; // rcx
  __int64 v17; // rbx

  mOffset = this->mConditions.mOffset;
  p_mConditions = &this->mConditions;
  if ( mOffset && (UFG::qOffset64<ConditionGroup *> *)((char *)p_mConditions + mOffset) )
  {
    (*(void (__fastcall **)(char *, __int64))(*(__int64 *)((char *)&p_mConditions->mOffset + mOffset) + 8))(
      (char *)p_mConditions + mOffset,
      1i64);
    p_mConditions->mOffset = 0i64;
  }
  v6 = source_action_node->mConditions.mOffset;
  if ( v6 )
  {
    v7 = (char *)&source_action_node->mConditions + v6;
    if ( v7 )
    {
      v8 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v7 + 16i64))(v7);
      if ( v8 )
        v8 -= (__int64)p_mConditions;
      p_mConditions->mOffset = v8;
    }
  }
  v9 = this->mTracks.mOffset;
  p_mTracks = &this->mTracks;
  if ( v9 && (UFG::qOffset64<TrackGroup *> *)((char *)p_mTracks + v9) )
  {
    (*(void (__fastcall **)(char *, __int64))(*(__int64 *)((char *)&p_mTracks->mOffset + v9) + 8))(
      (char *)p_mTracks + v9,
      1i64);
    p_mTracks->mOffset = 0i64;
  }
  v11 = source_action_node->mTracks.mOffset;
  if ( v11 )
  {
    v12 = (char *)&source_action_node->mTracks + v11;
    if ( v12 )
    {
      v13 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v12 + 16i64))(v12);
      if ( v13 )
        v13 -= (__int64)p_mTracks;
      p_mTracks->mOffset = v13;
    }
  }
  v14 = 0i64;
  v15 = (char *)&source_action_node->mChildren.mData + source_action_node->mChildren.mData.mOffset;
  if ( (source_action_node->mChildren.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v16 = (__int64)&v15[8 * v14 + *(_QWORD *)&v15[8 * v14]];
      v17 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v16 + 16i64))(v16);
      this->vfptr[2].__vecDelDtor(this, v17);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v17 + 256i64))(v17);
      v14 = (unsigned int)(v14 + 1);
    }
    while ( (unsigned int)v14 < (source_action_node->mChildren.mCount & 0x7FFFFFFFu) );
  }
  this->mID.mUID = source_action_node->mID.mUID;
  this->mParent.mOffset = 0i64;
  this->mBreakPoint = source_action_node->mBreakPoint != 0;
}

// File Line: 1302
// RVA: 0x26DC80
ActionNode *__fastcall ActionNodeImplementation::FindChild(
        ActionNodeImplementation *this,
        ActionID *childAnimID,
        bool recursive)
{
  __int64 v3; // rbx
  char *v5; // r14
  char *v8; // rcx
  char *v9; // r9
  ActionNode *result; // rax

  v3 = 0i64;
  v5 = (char *)&this->mChildren.mData + this->mChildren.mData.mOffset;
  if ( (this->mChildren.mCount & 0x7FFFFFFF) == 0 )
    return 0i64;
  while ( 1 )
  {
    v8 = &v5[8 * v3];
    v9 = &v8[*(_QWORD *)v8];
    if ( *((_DWORD *)v9 + 10) == childAnimID->mUID )
      break;
    if ( recursive )
    {
      result = (ActionNode *)(*(__int64 (__fastcall **)(char *, ActionID *, bool))(*(_QWORD *)v9 + 96i64))(
                               &v8[*(_QWORD *)&v5[8 * v3]],
                               childAnimID,
                               recursive);
      if ( result )
        return result;
    }
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= (this->mChildren.mCount & 0x7FFFFFFFu) )
      return 0i64;
  }
  return (ActionNode *)&v8[*(_QWORD *)&v5[8 * v3]];
}

// File Line: 1328
// RVA: 0x272350
void __fastcall ActionNodeImplementation::Serialize(ActionNodeImplementation *this, IActionTreeSerializer *serializer)
{
  __int64 mOffset; // rax
  char *v5; // rbx
  const char *v6; // rax
  __int64 v7; // rax
  char *v8; // rbx
  const char *v9; // rax
  unsigned int v10; // ebx
  char *v11; // r15
  char *v12; // rcx
  char *v13; // rdi
  const char *v14; // rax

  mOffset = this->mConditions.mOffset;
  if ( mOffset )
  {
    v5 = (char *)&this->mConditions + mOffset;
    if ( v5 )
    {
      v6 = (const char *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 32i64))(v5);
      serializer->vfptr->_PushObjectToSerialize(
        serializer,
        v5,
        1u,
        (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
        v6,
        PRIORITY_MEDIUM,
        0,
        0i64,
        -1u,
        0i64);
    }
  }
  v7 = this->mTracks.mOffset;
  if ( v7 )
  {
    v8 = (char *)&this->mTracks + v7;
    if ( v8 )
    {
      v9 = (const char *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v8 + 32i64))(v8);
      serializer->vfptr->_PushObjectToSerialize(
        serializer,
        v8,
        1u,
        (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
        v9,
        PRIORITY_MEDIUM,
        0,
        0i64,
        -1u,
        0i64);
    }
  }
  v10 = 0;
  v11 = (char *)&this->mChildren.mData + this->mChildren.mData.mOffset;
  if ( (this->mChildren.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v12 = &v11[8 * v10];
      v13 = &v12[*(_QWORD *)v12];
      if ( v13 )
      {
        v14 = (const char *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v13 + 32i64))(&v12[*(_QWORD *)v12]);
        serializer->vfptr->_PushObjectToSerialize(
          serializer,
          v13,
          1u,
          (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
          v14,
          PRIORITY_MEDIUM,
          0,
          0i64,
          -1u,
          0i64);
      }
      ++v10;
    }
    while ( v10 < (this->mChildren.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 1354
// RVA: 0x148A480
const char *dynamic_initializer_for__sActionNodeFactoryList__()
{
  const char *result; // rax

  sActionNodeFactoryList[0].mClassName = ActionNodeRoot::sClassName;
  sActionNodeFactoryList[1].mClassName = ActionNodeBank::sClassName;
  sActionNodeFactoryList[2].mClassName = ActionNodePlayable::sClassName;
  sActionNodeFactoryList[3].mClassName = ActionNodeFileReference::sClassName;
  sActionNodeFactoryList[4].mClassName = NISNode::sClassName;
  sActionNodeFactoryList[5].mClassName = StimulusBank::sClassName;
  result = TrackLibraryNode::sClassName;
  sActionNodeFactoryList[6].mClassName = TrackLibraryNode::sClassName;
  return result;
}

// File Line: 1360
// RVA: 0x1483D30
__int64 dynamic_initializer_for__gActionNodeFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(&gActionNodeFactory, sActionNodeFactoryList, sActionNodeFactoryListNum);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gActionNodeFactory__);
}

// File Line: 1365
// RVA: 0x148A450
const char *dynamic_initializer_for__sActionNodeExtraFactoryList__()
{
  const char *result; // rax

  sActionNodeExtraFactoryList[0].mClassName = TrackGroup::sClassName;
  sActionNodeExtraFactoryList[1].mClassName = ActionNodeReference::sClassName;
  result = ActionNodeRoot::sClassName;
  sActionNodeExtraFactoryList[2].mClassName = ActionNodeRoot::sClassName;
  return result;
}

// File Line: 1371
// RVA: 0x1483D00
__int64 dynamic_initializer_for__gActionNodeExtraFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(
    &gActionNodeExtraFactory,
    sActionNodeExtraFactoryList,
    sActionNodeExtraFactoryListNum);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gActionNodeExtraFactory__);
}

// File Line: 1383
// RVA: 0x1480450
__int64 dynamic_initializer_for__ActionNodeBank::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActionNodeBank", 0xFFFFFFFF);
  ActionNodeBank::sClassNameUID = result;
  return result;
}

// File Line: 1421
// RVA: 0x26C280
void __fastcall ActionNodeBank::CopyFrom(ActionNodeBank *this, ActionNodeBank *source_action_node)
{
  this->mSignalMask = source_action_node->mSignalMask;
  this->m_NeedsBalancing = source_action_node->m_NeedsBalancing;
  this->m_Level = source_action_node->m_Level;
  ActionNodeImplementation::CopyFrom(this, source_action_node);
}

// File Line: 1441
// RVA: 0x26CA90
Expression::IMemberMap *__fastcall ActionNodeBank::CreateClone(ActionNodeBank *this)
{
  char *v2; // rax
  char *v3; // rbx

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x78ui64, "ActionNodeBank::CreateClone", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    ActionNodeImplementation::ActionNodeImplementation((ActionNodeImplementation *)v2);
    *((_QWORD *)v3 + 11) = v3 + 88;
    *((_QWORD *)v3 + 12) = v3 + 88;
    *(_QWORD *)v3 = &ActionNodeBank::`vftable;
    *((_WORD *)v3 + 52) = 0;
    *((_QWORD *)v3 + 14) = -1i64;
  }
  else
  {
    v3 = 0i64;
  }
  *((_QWORD *)v3 + 14) = this->mSignalMask;
  v3[106] = this->m_NeedsBalancing;
  *((_WORD *)v3 + 52) = this->m_Level;
  ActionNodeImplementation::CopyFrom((ActionNodeImplementation *)v3, this);
  return (Expression::IMemberMap *)v3;
}

// File Line: 1472
// RVA: 0x271940
void __fastcall ActionNodeBank::ResolveReferences(ActionNodeBank *this)
{
  __int64 v2; // rax
  int v3; // ecx
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v4; // rdx
  ActionNodeBank *p_mNext; // rax
  UFG::qNode<ActionNodeBank,ActionNodeBank> *mPrev; // rax

  ActionNode::ResolveReferences(this);
  ActionNodeBank::UpdateSignalAndConditionMask(this);
  if ( this->m_NeedsBalancing )
  {
    v2 = ((__int64 (__fastcall *)(ActionNodeBank *))this->vfptr[1].SetResourceOwner)(this);
    v3 = -1;
    v4 = (UFG::qNode<ActionNodeBank,ActionNodeBank> *)(v2 + 176);
    p_mNext = (ActionNodeBank *)(*(_QWORD *)(v2 + 184) - 88i64);
    if ( p_mNext == (ActionNodeBank *)&v4[-6].mNext )
      goto LABEL_7;
    while ( 1 )
    {
      ++v3;
      if ( p_mNext == this )
        break;
      p_mNext = (ActionNodeBank *)&p_mNext->mNext[-6].mNext;
      if ( p_mNext == (ActionNodeBank *)&v4[-6].mNext )
        goto LABEL_7;
    }
    if ( v3 == -1 )
    {
LABEL_7:
      mPrev = v4->mPrev;
      mPrev->mNext = &this->UFG::qNode<ActionNodeBank,ActionNodeBank>;
      this->mPrev = mPrev;
      this->mNext = v4;
      v4->mPrev = &this->UFG::qNode<ActionNodeBank,ActionNodeBank>;
    }
  }
}

// File Line: 1524
// RVA: 0x2710E0
void __fastcall ActionNodeBank::RemoveReferences(ActionNodeBank *this)
{
  ActionNode::RemoveReferences(this);
  ActionNodeBank::UpdateSignalAndConditionMask(this);
}

// File Line: 1531
// RVA: 0x2737D0
void __fastcall ActionNodeBank::UpdateSignalAndConditionMask(ActionNodeBank *this)
{
  unsigned __int64 v2; // rbp
  const char *v3; // rax
  int v4; // ebx
  unsigned __int64 v5; // rdi
  unsigned int v6; // r14d
  char *v7; // r15
  __int64 v8; // rcx
  unsigned __int64 v9; // rcx
  int i; // edx
  unsigned __int64 j; // rcx

  v2 = -1i64;
  v3 = this->vfptr[3].GetClassname(this);
  if ( v3 )
    v2 = (*(__int64 (__fastcall **)(const char *))(*(_QWORD *)v3 + 96i64))(v3);
  v4 = 0;
  v5 = 0i64;
  v6 = 0;
  v7 = (char *)&this->mChildren.mData + this->mChildren.mData.mOffset;
  if ( (this->mChildren.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v8 = (__int64)&v7[8 * v6 + *(_QWORD *)&v7[8 * v6]];
      ++v6;
      v5 |= (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 216i64))(v8);
    }
    while ( v6 < (this->mChildren.mCount & 0x7FFFFFFFu) );
  }
  if ( v2 != -1i64 )
  {
    if ( v5 == -1i64 )
    {
      this->mSignalMask = v2;
      return;
    }
    v9 = v2;
    for ( i = 0; v9; v9 &= v9 - 1 )
      ++i;
    for ( j = v5; j; j &= j - 1 )
      ++v4;
    if ( i <= v4 )
      v5 = v2;
  }
  this->mSignalMask = v5;
}

// File Line: 1576
// RVA: 0x26F7D0
ActionNodePlayable *__fastcall ActionNodeBank::Match(ActionNodeBank *this, ActionContext *context)
{
  __int64 mOffset; // rax
  __int64 v6; // rsi
  char *v7; // rcx
  unsigned __int64 mSignalMask; // rax
  __int64 v9; // rax
  char *v10; // rax
  unsigned int v11; // ebx
  char *v12; // r14
  __int64 v13; // rcx

  if ( this->mDisable )
    return 0i64;
  mOffset = this->mConditions.mOffset;
  v6 = 0i64;
  if ( mOffset )
    v7 = (char *)&this->mConditions + mOffset;
  else
    v7 = 0i64;
  mSignalMask = this->mSignalMask;
  if ( mSignalMask != -1i64 && (mSignalMask & context->mSignals) == 0 )
    return 0i64;
  if ( !v7 || (*((_DWORD *)v7 + 8) & 0x7FFFFFFF) == 0 )
    goto LABEL_20;
  if ( (*((_DWORD *)v7 + 8) & 0x7FFFFFFF) == 1 && *((_QWORD *)v7 + 3) == -1i64 )
  {
    v9 = *((_QWORD *)v7 + 5);
    if ( v9 )
      v10 = &v7[v9 + 40];
    else
      v10 = 0i64;
    if ( *(_QWORD *)v10 )
      v7 = &v10[*(_QWORD *)v10];
    else
      v7 = 0i64;
  }
  if ( (*(unsigned __int8 (__fastcall **)(char *))(*(_QWORD *)v7 + 80i64))(v7) )
  {
LABEL_20:
    v11 = 0;
    v12 = (char *)&this->mChildren.mData + this->mChildren.mData.mOffset;
    if ( (this->mChildren.mCount & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v13 = (__int64)&v12[8 * v11 + *(_QWORD *)&v12[8 * v11]];
        v6 = (*(__int64 (__fastcall **)(__int64, ActionContext *))(*(_QWORD *)v13 + 200i64))(v13, context);
        if ( v6 )
          break;
        ++v11;
      }
      while ( v11 < (this->mChildren.mCount & 0x7FFFFFFFu) );
    }
  }
  return (ActionNodePlayable *)v6;
}

// File Line: 1762
// RVA: 0x26E6A0
ActionNodePlayable *__fastcall ActionNodeBank::GetFirstPlayable(ActionNodeBank *this)
{
  __int64 v1; // rbx
  char *v3; // rsi
  __int64 v4; // rcx
  ActionNodePlayable *result; // rax

  v1 = 0i64;
  v3 = (char *)&this->mChildren.mData + this->mChildren.mData.mOffset;
  if ( (this->mChildren.mCount & 0x7FFFFFFF) == 0 )
    return 0i64;
  while ( 1 )
  {
    v4 = (__int64)&v3[8 * v1 + *(_QWORD *)&v3[8 * v1]];
    result = (ActionNodePlayable *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 208i64))(v4);
    if ( result )
      break;
    v1 = (unsigned int)(v1 + 1);
    if ( (unsigned int)v1 >= (this->mChildren.mCount & 0x7FFFFFFFu) )
      return 0i64;
  }
  return result;
}

// File Line: 1779
// RVA: 0x26B6B0
void __fastcall ActionNodeBank::BalanceWeights(ActionNodeBank *this, unsigned int level, ActionContext *context)
{
  unsigned int v3; // ebx

  v3 = level;
  this->m_Level = level;
  if ( ActionNodeBank::BalanceWeightsForThisLevel(this, context) > 0 )
    ++v3;
  ActionNode::BalanceWeights(this, v3, context);
}

// File Line: 1795
// RVA: 0x26B720
__int64 __fastcall ActionNodeBank::BalanceWeightsForThisLevel(ActionNodeBank *this, ActionContext *context)
{
  unsigned int v2; // r15d
  char *v3; // r13
  __int64 v4; // r14
  float v5; // xmm6_4
  float v6; // xmm10_4
  ActionNodeBank *v7; // rbx
  bool v8; // si
  __int64 v9; // rcx
  __int64 v10; // rax
  __int64 v11; // rbp
  __int64 v12; // rdi
  __int64 v13; // r12
  __int64 v14; // rcx
  __int64 v15; // rax
  __int64 v16; // rbx
  float v17; // xmm0_4
  __int64 v18; // r14
  char *v19; // rcx
  __int64 v20; // rcx
  __int64 v21; // rax
  __int64 v22; // rbp
  __int64 v23; // rdi
  __int64 v24; // r13
  int v25; // r14d
  __int64 v26; // rcx
  __int64 v27; // rax
  __int64 v28; // rbx
  float v29; // xmm0_4
  char *v31; // [rsp+20h] [rbp-A8h]
  int v34; // [rsp+E0h] [rbp+18h]
  char *v35; // [rsp+E8h] [rbp+20h]
  int v36; // [rsp+E8h] [rbp+20h]

  v2 = 0;
  v3 = (char *)&this->mChildren.mData + this->mChildren.mData.mOffset;
  v4 = 0i64;
  v5 = 0.0;
  v6 = 0.0;
  v7 = this;
  v8 = 1;
  v34 = 0;
  v35 = v3;
  if ( (this->mChildren.mCount & 0x7FFFFFFF) == 0 )
    return 0i64;
  do
  {
    v9 = (__int64)&v3[8 * v4 + *(_QWORD *)&v3[8 * v4]];
    v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v9 + 272i64))(v9);
    v11 = v10;
    if ( v10 )
    {
      v12 = 0i64;
      v13 = *(_QWORD *)(v10 + 40) + v10 + 40;
      if ( (*(_DWORD *)(v10 + 32) & 0x7FFFFFFF) != 0 )
      {
        do
        {
          v14 = *(_QWORD *)(v13 + 8 * v12) + v13 + 8 * v12;
          v15 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 112i64))(v14);
          v16 = v15;
          if ( v15 )
          {
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v15 + 32i64))(v15);
            v17 = (*(float (__fastcall **)(__int64, ActionContext *))(*(_QWORD *)v16 + 24i64))(v16, context);
            if ( v17 > 0.0 )
            {
              v5 = v5 + v17;
              ++v2;
            }
            v8 = v8 && (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v16 + 48i64))(v16);
          }
          v12 = (unsigned int)(v12 + 1);
        }
        while ( (unsigned int)v12 < (*(_DWORD *)(v11 + 32) & 0x7FFFFFFFu) );
        v3 = v35;
        v7 = this;
      }
    }
    v4 = (unsigned int)(v4 + 1);
  }
  while ( (unsigned int)v4 < (v7->mChildren.mCount & 0x7FFFFFFFu) );
  if ( v5 == 0.0 )
    return v2;
  v18 = 0i64;
  v36 = 0;
  v19 = (char *)&v7->mChildren.mData + v7->mChildren.mData.mOffset;
  v31 = v19;
  if ( (v7->mChildren.mCount & 0x7FFFFFFF) == 0 )
    return v2;
  do
  {
    v20 = (__int64)&v19[8 * v18 + *(_QWORD *)&v19[8 * v18]];
    v21 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v20 + 272i64))(v20);
    v22 = v21;
    if ( v21 )
    {
      v23 = 0i64;
      v24 = *(_QWORD *)(v21 + 40) + v21 + 40;
      if ( (*(_DWORD *)(v21 + 32) & 0x7FFFFFFF) != 0 )
      {
        v25 = v34;
        do
        {
          v26 = *(_QWORD *)(v24 + 8 * v23) + v24 + 8 * v23;
          v27 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 112i64))(v26);
          v28 = v27;
          if ( v27 )
          {
            v29 = (*(float (__fastcall **)(__int64, ActionContext *))(*(_QWORD *)v27 + 24i64))(v27, context);
            if ( v29 > 0.0 )
            {
              ++v25;
              if ( ((int)v2 > 1i64 || !v8) && v25 != v2 )
                v6 = v6 + (float)((float)(v29 * 100.0) / v5);
              (*(void (__fastcall **)(__int64))(*(_QWORD *)v28 + 32i64))(v28);
              (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v28 + 40i64))(v28, this->m_Level);
            }
          }
          v23 = (unsigned int)(v23 + 1);
        }
        while ( (unsigned int)v23 < (*(_DWORD *)(v22 + 32) & 0x7FFFFFFFu) );
        v7 = this;
        v34 = v25;
        LODWORD(v18) = v36;
      }
    }
    v18 = (unsigned int)(v18 + 1);
    v36 = v18;
    v19 = v31;
  }
  while ( (unsigned int)v18 < (v7->mChildren.mCount & 0x7FFFFFFFu) );
  return v2;
}

// File Line: 1922
// RVA: 0x1480490
__int64 dynamic_initializer_for__ActionNodePlayable::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActionNodePlayable", 0xFFFFFFFF);
  ActionNodePlayable::sClassNameUID = result;
  return result;
}

// File Line: 1952
// RVA: 0x272790
void __fastcall ActionNode::SetName(ActionNode *this, const char *namestr)
{
  this->mID.mUID = UFG::qStringHashUpper32(namestr, -1);
}

// File Line: 1974
// RVA: 0x26CBE0
ActionNodeImplementation *__fastcall ActionNodePlayable::CreateClone(ActionNodePlayable *this)
{
  char *v2; // rax
  ActionNodeImplementation *v3; // rbx

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x58ui64, "ActionNodePlayable::CreateClone", 0i64, 1u);
  v3 = (ActionNodeImplementation *)v2;
  if ( v2 )
  {
    ActionNodeImplementation::ActionNodeImplementation((ActionNodeImplementation *)v2);
    v3->vfptr = (Expression::IMemberMapVtbl *)&ActionNodePlayable::`vftable;
  }
  else
  {
    v3 = 0i64;
  }
  ActionNodeImplementation::CopyFrom(v3, this);
  return v3;
}

// File Line: 2001
// RVA: 0x26F8F0
ActionNodePlayable *__fastcall ActionNodePlayable::Match(ActionNodePlayable *this, ActionContext *context)
{
  __int64 mOffset; // rax
  __int64 v5; // rbx
  char *v6; // rcx
  char v7; // al
  __int64 v8; // rax
  char *v9; // rax

  if ( this->mDisable )
    return 0i64;
  mOffset = this->mConditions.mOffset;
  v5 = 0i64;
  if ( mOffset )
    v6 = (char *)&this->mConditions + mOffset;
  else
    v6 = 0i64;
  v7 = 1;
  if ( v6 )
  {
    if ( (*((_DWORD *)v6 + 8) & 0x7FFFFFFF) == 1 && *((_QWORD *)v6 + 3) == -1i64 )
    {
      v8 = *((_QWORD *)v6 + 5);
      if ( v8 )
        v9 = &v6[v8 + 40];
      else
        v9 = 0i64;
      if ( *(_QWORD *)v9 )
        v7 = (*(__int64 (__fastcall **)(char *, ActionContext *))(*(_QWORD *)&v9[*(_QWORD *)v9] + 80i64))(
               &v9[*(_QWORD *)v9],
               context);
      else
        v7 = (*(__int64 (__fastcall **)(_QWORD, ActionContext *))(MEMORY[0] + 80))(0i64, context);
    }
    else
    {
      v7 = (*(__int64 (__fastcall **)(char *, ActionContext *))(*(_QWORD *)v6 + 80i64))(v6, context);
    }
  }
  if ( v7 )
    return this;
  return (ActionNodePlayable *)v5;
}

// File Line: 2144
// RVA: 0x14804B0
__int64 dynamic_initializer_for__ActionNodeReference::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActionNodeReference", 0xFFFFFFFF);
  ActionNodeReference::sClassNameUID = result;
  return result;
}

// File Line: 2701
// RVA: 0x269B80
void __fastcall ActionNodeReference::~ActionNodeReference(ActionNodeReference *this)
{
  ActionPath *p_mAnyPathToNode; // rbx
  __int64 mOffset; // rax
  __int64 v4; // rax
  char *v5; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeReference::`vftable;
  p_mAnyPathToNode = &this->mAnyPathToNode;
  if ( this->mAnyPathToNode.mPath.mCount >= 0 )
  {
    mOffset = this->mAnyPathToNode.mPath.mData.mOffset;
    if ( mOffset && (UFG::qOffset64<ActionID *> *)((char *)&p_mAnyPathToNode->mPath.mData + mOffset) )
    {
      v4 = this->mAnyPathToNode.mPath.mData.mOffset;
      if ( v4 )
        v5 = (char *)&this->mAnyPathToNode.mPath.mData + v4;
      else
        v5 = 0i64;
      operator delete[](v5);
    }
    p_mAnyPathToNode->mPath.mData.mOffset = 0i64;
    p_mAnyPathToNode->mPath.mCount &= 0x80000000;
  }
  ActionNode::~ActionNode(this);
}

// File Line: 2715
// RVA: 0x26C480
void __fastcall ActionNodeReference::CopyFrom(ActionNodeReference *this, ActionNodeReference *source_action_node)
{
  BinArray<ActionID,0>::Clone(&source_action_node->mAnyPathToNode.mPath, &this->mAnyPathToNode.mPath);
  this->mActionNode.mOffset = 0i64;
  this->mID.mUID = source_action_node->mID.mUID;
  this->mParent.mOffset = 0i64;
  this->mBreakPoint = source_action_node->mBreakPoint != 0;
}

// File Line: 2736
// RVA: 0x26CC60
Expression::IMemberMap *__fastcall ActionNodeReference::CreateClone(ActionNodeReference *this)
{
  char *v2; // rbx

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "ActionNodeReference::CreateClone", 0i64, 1u);
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
    *((_DWORD *)v2 + 14) = 0;
    *((_QWORD *)v2 + 8) = 0i64;
    *((_QWORD *)v2 + 9) = 0i64;
  }
  else
  {
    v2 = 0i64;
  }
  BinArray<ActionID,0>::Clone(&this->mAnyPathToNode.mPath, (BinArray<ActionID,0> *)(v2 + 56));
  *((_QWORD *)v2 + 9) = 0i64;
  *((_DWORD *)v2 + 10) = this->mID.mUID;
  *((_QWORD *)v2 + 2) = 0i64;
  v2[44] = this->mBreakPoint != 0;
  return (Expression::IMemberMap *)v2;
}

// File Line: 2758
// RVA: 0x2724C0
void __fastcall ActionNodeReference::Serialize(ActionNodeReference *this, IActionTreeSerializer *serializer)
{
  __int64 mOffset; // rbx
  UFG::qOffset64<ActionNode *> *p_mActionNode; // r10
  bool v4; // di
  ActionNodeReference *v5; // r9
  ActionNodeReference *v6; // r8
  __int64 v7; // rax
  UFG::qOffset64<ActionNode *> *p_mParent; // rcx
  ActionNode *v9; // rdx
  __int64 v10; // rax
  UFG::qOffset64<ActionNode *> *v11; // rcx
  ActionNode *v12; // rdx

  mOffset = this->mActionNode.mOffset;
  p_mActionNode = &this->mActionNode;
  v4 = 0;
  v5 = this;
  if ( mOffset )
  {
    v6 = (ActionNodeReference *)((char *)p_mActionNode + mOffset);
    if ( (UFG::qOffset64<ActionNode *> *)((char *)p_mActionNode + mOffset) )
    {
      while ( 1 )
      {
        v7 = v5->mParent.mOffset;
        p_mParent = &v5->mParent;
        v9 = v7 ? (ActionNode *)((char *)p_mParent + v7) : 0i64;
        if ( v9 == ActionNode::smRoot )
          break;
        if ( v7 )
        {
          v5 = (ActionNodeReference *)((char *)p_mParent + v7);
          if ( (UFG::qOffset64<ActionNode *> *)((char *)p_mParent + v7) )
            continue;
        }
        v5 = 0i64;
        break;
      }
      while ( 1 )
      {
        v10 = v6->mParent.mOffset;
        v11 = &v6->mParent;
        v12 = v10 ? (ActionNode *)((char *)v11 + v10) : 0i64;
        if ( v12 == ActionNode::smRoot )
          break;
        if ( v10 )
        {
          v6 = (ActionNodeReference *)((char *)v11 + v10);
          if ( (UFG::qOffset64<ActionNode *> *)((char *)v11 + v10) )
            continue;
        }
        v6 = 0i64;
        break;
      }
      v4 = v5 != v6;
    }
    if ( (UFG::qOffset64<ActionNode *> *)((char *)p_mActionNode + mOffset) && v4 )
    {
      p_mActionNode->mOffset = 0i64;
      if ( (UFG::qOffset64<ActionNode *> *)((char *)p_mActionNode + mOffset) )
        p_mActionNode->mOffset = mOffset;
      else
        p_mActionNode->mOffset = 0i64;
    }
  }
}

// File Line: 2874
// RVA: 0x26F590
bool __fastcall ActionNodeReference::IsResolved(ActionNodeReference *this, ActionNode *relative_to_node)
{
  int *mOffset; // rax
  int v5; // ebx
  ActionNode *Relative; // rcx
  unsigned int v7; // ebx
  unsigned int v8; // esi
  __int64 v9; // r14
  __int64 v10; // rax
  char *v11; // rdx
  __int64 v12; // rax
  UFG::qOffset64<ActionNode *> *p_mActionNode; // rax
  __int64 v14; // rdx
  int v16; // [rsp+50h] [rbp+8h] BYREF

  if ( (this->mAnyPathToNode.mPath.mCount & 0x7FFFFFFF) != 0 )
  {
    mOffset = (int *)this->mAnyPathToNode.mPath.mData.mOffset;
    if ( mOffset )
      mOffset = (int *)((char *)mOffset + (_QWORD)this + 64);
    v5 = *mOffset;
  }
  else
  {
    v5 = v16;
  }
  if ( (_S6_6 & 1) == 0 )
  {
    _S6_6 |= 1u;
    dword_1423AFFC0 = UFG::qStringHashUpper32(".", -1);
  }
  if ( v5 == dword_1423AFFC0 )
    goto LABEL_23;
  if ( (_S8_6 & 1) == 0 )
  {
    _S8_6 |= 1u;
    dword_1423AFFC8 = UFG::qStringHashUpper32("..", -1);
  }
  if ( v5 == dword_1423AFFC8 )
  {
LABEL_23:
    v12 = this->mParent.mOffset;
    if ( v12 )
    {
      Relative = (ActionNode *)((char *)&this->mParent + v12);
      if ( Relative )
        Relative = ActionNode::FindRelative(Relative, &this->mAnyPathToNode);
    }
    else
    {
      Relative = 0i64;
    }
  }
  else if ( relative_to_node )
  {
    Relative = ActionNode::Find(&this->mAnyPathToNode, ActionNode::smRoot);
  }
  else
  {
    Relative = 0i64;
    v7 = this->mAnyPathToNode.mPath.mCount & 0x7FFFFFFF;
    if ( v7 > 1 )
    {
      Relative = ActionNode::smRoot;
      v8 = 1;
      v9 = 4i64;
      do
      {
        if ( !Relative )
          break;
        v10 = this->mAnyPathToNode.mPath.mData.mOffset;
        v11 = v10 ? (char *)&this->mAnyPathToNode.mPath.mData + v10 : 0i64;
        v16 = *(_DWORD *)&v11[v9];
        Relative = (ActionNode *)((__int64 (__fastcall *)(ActionNode *, int *, _QWORD))Relative->vfptr[1].CreateClone)(
                                   Relative,
                                   &v16,
                                   0i64);
        ++v8;
        v9 += 4i64;
      }
      while ( v8 < v7 );
    }
  }
  p_mActionNode = &this->mActionNode;
  v14 = this->mActionNode.mOffset;
  if ( v14 )
    v14 += (__int64)p_mActionNode;
  if ( Relative != (ActionNode *)v14 )
  {
    if ( Relative )
      Relative = (ActionNode *)((char *)Relative - (__int64)p_mActionNode);
    p_mActionNode->mOffset = (__int64)Relative;
  }
  return p_mActionNode->mOffset && (UFG::qOffset64<ActionNode *> *)((char *)p_mActionNode + p_mActionNode->mOffset);
}

// File Line: 3145
// RVA: 0x26EB60
char *__fastcall ActionNodeReference::GetPath(ActionNodeReference *this)
{
  return ActionPath::GetString_DBG(&this->mAnyPathToNode);
}

// File Line: 3150
// RVA: 0x272940
void __fastcall ActionNodeReference::SetPath(ActionNodeReference *this, const char *path)
{
  __int64 mOffset; // rax
  ActionNode *v3; // rdi
  __int64 v6; // rax
  char *v7; // rcx
  __int64 v8; // rax

  mOffset = this->mActionNode.mOffset;
  v3 = 0i64;
  if ( mOffset && (UFG::qOffset64<ActionNode *> *)((char *)&this->mActionNode + mOffset) )
    this->mActionNode.mOffset = 0i64;
  if ( this->mAnyPathToNode.mPath.mCount >= 0 )
  {
    v6 = this->mAnyPathToNode.mPath.mData.mOffset;
    if ( v6 )
    {
      v7 = (char *)&this->mAnyPathToNode.mPath.mData + v6;
      if ( v7 )
        operator delete[](v7);
    }
    this->mAnyPathToNode.mPath.mData.mOffset = 0i64;
    this->mAnyPathToNode.mPath.mCount &= 0x80000000;
  }
  ActionPath::Append(&this->mAnyPathToNode, path);
  v8 = this->mParent.mOffset;
  if ( v8 )
    v3 = (ActionNode *)((char *)&this->mParent + v8);
  ActionNodeReference::IsResolved(this, v3);
}

// File Line: 3174
// RVA: 0x271A60
// attributes: thunk
void __fastcall ActionNodeReference::ResolveReferences(ActionNodeReference *this)
{
  ActionNode::ResolveReferences(this);
}

// File Line: 3226
// RVA: 0x1480470
__int64 dynamic_initializer_for__ActionNodeFileReference::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActionNodeFileReference", 0xFFFFFFFF);
  ActionNodeFileReference::sClassNameUID = result;
  return result;
}

// File Line: 3264
// RVA: 0x269860
void __fastcall ActionNodeFileReference::~ActionNodeFileReference(ActionNodeFileReference *this)
{
  UFG::qBaseTreeRB *Head; // rbx
  UFG::qBaseNodeRB *mParent; // rcx
  __int64 mOffset; // rax
  char *v5; // rcx
  char *v6; // rcx
  ActionPath *p_mAnyPathToNode; // rbx
  __int64 v8; // rax
  __int64 v9; // rax
  char *v10; // rcx
  __int64 v11; // rax
  char *v12; // rcx
  char *mFirstCallback; // rdx
  char *v14; // rbx

  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeFileReference::`vftable;
  Head = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&ActionNode::sActionTreeFileEntries);
  if ( Head )
  {
    while ( this != *(ActionNodeFileReference **)&Head->mCount )
    {
      Head = UFG::qBaseTreeRB::GetNext(&ActionNode::sActionTreeFileEntries.mTree, &Head->mRoot);
      if ( !Head )
        goto LABEL_8;
    }
    *(_QWORD *)&Head->mCount = 0i64;
    mParent = Head->mNULL.mParent;
    if ( mParent )
      ((void (__fastcall *)(UFG::qBaseNodeRB *, __int64))mParent->mParent->mChild[0])(mParent, 1i64);
    Head->mNULL.mParent = 0i64;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&ActionNode::sActionTreeFileEntries,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)Head);
  }
  else
  {
LABEL_8:
    if ( this->m_IsClone )
    {
      mOffset = this->mActionNode.mOffset;
      if ( mOffset )
      {
        v5 = (char *)&this->mActionNode + mOffset;
        if ( v5 )
          (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)v5 + 8i64))(v5, 1i64);
      }
    }
  }
  if ( (this->mRelativeFilePath.mOffset & 1) != 0 && (this->mRelativeFilePath.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v6 = (char *)&this->mRelativeFilePath + (this->mRelativeFilePath.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v6 != BinString::sEmptyString )
      operator delete[](v6);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeReference::`vftable;
  p_mAnyPathToNode = &this->mAnyPathToNode;
  if ( this->mAnyPathToNode.mPath.mCount >= 0 )
  {
    v8 = this->mAnyPathToNode.mPath.mData.mOffset;
    if ( v8 && (UFG::qOffset64<ActionID *> *)((char *)&p_mAnyPathToNode->mPath.mData + v8) )
    {
      v9 = this->mAnyPathToNode.mPath.mData.mOffset;
      if ( v9 )
        v10 = (char *)&this->mAnyPathToNode.mPath.mData + v9;
      else
        v10 = 0i64;
      operator delete[](v10);
    }
    this->mAnyPathToNode.mPath.mData.mOffset = 0i64;
    p_mAnyPathToNode->mPath.mCount &= 0x80000000;
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNode::`vftable;
  v11 = this->mParent.mOffset;
  if ( v11 )
  {
    v12 = (char *)&this->mParent + v11;
    if ( v12 )
      (*(void (__fastcall **)(char *, ActionNodeFileReference *))(*(_QWORD *)v12 + 184i64))(v12, this);
  }
  mFirstCallback = (char *)this->mFirstCallback;
  if ( mFirstCallback )
  {
    do
    {
      v14 = *(char **)mFirstCallback;
      UFG::qMemoryPool2::Free(&gActionTreeMemoryPool, mFirstCallback, 0x20ui64);
      mFirstCallback = v14;
    }
    while ( v14 );
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 3291
// RVA: 0x272B20
void __fastcall ActionNodeFileReference::Trim(ActionNodeFileReference *this, __int64 force)
{
  __int64 mOffset; // rax
  char *v3; // rcx

  mOffset = this->mActionNode.mOffset;
  if ( mOffset )
  {
    v3 = (char *)&this->mActionNode + mOffset;
    if ( v3 )
      (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)v3 + 264i64))(v3, force);
  }
}

// File Line: 3301
// RVA: 0x272330
void __fastcall ActionNodeFileReference::Serialize(ActionNodeFileReference *this, IActionTreeSerializer *serializer)
{
  __int64 mOffset; // rax
  Expression::IMemberMap *v4; // rdx

  mOffset = this->mActionNode.mOffset;
  if ( mOffset )
  {
    v4 = (Expression::IMemberMap *)((char *)&this->mActionNode + mOffset);
    if ( v4 )
      IActionTreeSerializer::PushObjectToSerialize(serializer, v4);
  }
}

// File Line: 3315
// RVA: 0x271460
void __fastcall ActionNodeFileReference::ResolveFileReferenceParent(ActionNodeFileReference *this)
{
  __int64 mOffset; // rax
  ActionNodeRoot *v2; // rbx
  __int64 v3; // rax
  UFG::qOffset64<ActionNode *> *p_mParent; // r8
  __int64 v5; // rax
  char *v6; // rcx
  ActionNodeRoot *v7; // rax

  mOffset = this->mActionNode.mOffset;
  if ( mOffset )
  {
    v2 = (ActionNodeRoot *)((char *)&this->mActionNode + mOffset);
    if ( v2 )
    {
      v3 = v2->mParent.mOffset;
      p_mParent = &v2->mParent;
      if ( !v3 || !(UFG::qOffset64<ActionNode *> *)((char *)p_mParent + v3) )
      {
        v5 = this->mParent.mOffset;
        if ( v5 )
        {
          v6 = (char *)&this->mParent + v5;
          if ( v6 )
          {
            p_mParent->mOffset = v6 - (char *)p_mParent;
            v7 = (ActionNodeRoot *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v6 + 144i64))(v6);
            if ( v7 )
              ActionNodeRoot::AddToInitList(v7, v2);
          }
        }
      }
    }
  }
}

// File Line: 3340
// RVA: 0x26C2A0
void __fastcall ActionNodeFileReference::CopyFrom(
        ActionNodeFileReference *this,
        ActionNodeFileReference *source_action_node)
{
  const char *v4; // rdx
  __int64 mOffset; // rax
  char *v6; // rcx
  __int64 v7; // rax
  UFG::qOffset64<ActionNode *> *p_mActionNode; // rcx

  if ( (source_action_node->mRelativeFilePath.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    v4 = (char *)&source_action_node->mRelativeFilePath
       + (source_action_node->mRelativeFilePath.mOffset & 0xFFFFFFFFFFFFFFFEui64);
  else
    v4 = BinString::sEmptyString;
  BinString::Set(&this->mRelativeFilePath, v4);
  this->m_Writeable = source_action_node->m_Writeable;
  BinArray<ActionID,0>::Clone(&source_action_node->mAnyPathToNode.mPath, &this->mAnyPathToNode.mPath);
  mOffset = source_action_node->mActionNode.mOffset;
  if ( mOffset && (v6 = (char *)&source_action_node->mActionNode + mOffset) != 0i64 )
  {
    v7 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v6 + 16i64))(v6);
    p_mActionNode = &this->mActionNode;
    if ( v7 )
      p_mActionNode->mOffset = v7 - (_QWORD)p_mActionNode;
    else
      p_mActionNode->mOffset = 0i64;
  }
  else
  {
    this->mActionNode.mOffset = 0i64;
  }
  this->mID.mUID = source_action_node->mID.mUID;
  this->mParent.mOffset = 0i64;
  this->mBreakPoint = source_action_node->mBreakPoint != 0;
}

// File Line: 3410
// RVA: 0x26CB40
Expression::IMemberMap *__fastcall ActionNodeFileReference::CreateClone(ActionNodeFileReference *this)
{
  char *v2; // rax
  char *v3; // rbx

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x60ui64, "ActionNodeFileReference::CreateClone", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    ActionNodeReference::ActionNodeReference((ActionNodeReference *)v2, ActionNodeFileReference::sUnresolvedName);
    *(_QWORD *)v3 = &ActionNodeFileReference::`vftable;
    *((_QWORD *)v3 + 10) = 1i64;
    BinString::Set((BinString *)v3 + 10, &customCaption);
    *((_WORD *)v3 + 44) = 1;
  }
  else
  {
    v3 = 0i64;
  }
  ActionNodeFileReference::CopyFrom((ActionNodeFileReference *)v3, this);
  v3[89] = 1;
  return (Expression::IMemberMap *)v3;
}

// File Line: 3439
// RVA: 0x2727B0
void __fastcall ActionNodeFileReference::SetName(ActionNodeFileReference *this, const char *namestr)
{
  __int64 mOffset; // rax
  char *v3; // rcx

  mOffset = this->mActionNode.mOffset;
  if ( mOffset )
  {
    v3 = (char *)&this->mActionNode + mOffset;
    if ( v3 )
      (*(void (__fastcall **)(char *, const char *))(*(_QWORD *)v3 + 80i64))(v3, namestr);
  }
}

// File Line: 3448
// RVA: 0x26E9D0
const char *__fastcall ActionNodeFileReference::GetName_DBG(ActionNodeFileReference *this)
{
  __int64 mOffset; // rax
  char *v2; // rcx

  mOffset = this->mActionNode.mOffset;
  if ( mOffset && (v2 = (char *)&this->mActionNode + mOffset) != 0i64 )
    return (const char *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v2 + 88i64))(v2);
  else
    return ActionNodeFileReference::sUnresolvedName;
}

// File Line: 3483
// RVA: 0x275580
UFG::qString *__fastcall makeFullPath(UFG::qString *result, const char *base_directory, const char *rel_filename)
{
  UFG::qMakeFullPath(result, base_directory, rel_filename);
  return result;
}

// File Line: 3670
// RVA: 0x271550
void __fastcall ActionNodeFileReference::ResolveFileReferences(ActionNodeFileReference *this)
{
  __int64 mOffset; // rax
  __int64 v3; // rax
  _DWORD *v4; // rdi
  __int64 v5; // rbx
  __int64 v6; // rsi
  __int64 v7; // rcx
  char v8[520]; // [rsp+20h] [rbp-208h] BYREF

  mOffset = this->mActionNode.mOffset;
  if ( !mOffset || !(UFG::qOffset64<ActionNode *> *)((char *)&this->mActionNode + mOffset) )
    this->vfptr->GetResourcePath(this, v8, 512);
  v3 = ((__int64 (__fastcall *)(ActionNodeFileReference *))this->vfptr[1].GetResourcePath)(this);
  v4 = (_DWORD *)v3;
  if ( v3 )
  {
    v5 = 0i64;
    v6 = v3 + *(_QWORD *)(v3 + 8) + 8i64;
    if ( (*(_DWORD *)v3 & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v7 = *(_QWORD *)(v6 + 8 * v5) + v6 + 8 * v5;
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v7 + 224i64))(v7);
        v5 = (unsigned int)(v5 + 1);
      }
      while ( (unsigned int)v5 < (*v4 & 0x7FFFFFFFu) );
    }
  }
}

// File Line: 3733
// RVA: 0x2719C0
void __fastcall ActionNodeFileReference::ResolveReferences(ActionNodeFileReference *this)
{
  __int64 mOffset; // rax
  ActionNodeRoot *v3; // rdi
  __int64 v4; // rax
  char *v5; // rcx
  ActionNodeRoot *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rax
  ActionNode *v9; // rdx

  mOffset = this->mActionNode.mOffset;
  if ( mOffset )
  {
    v3 = (ActionNodeRoot *)((char *)&this->mActionNode + mOffset);
    if ( v3 )
    {
      v3->vfptr->ResolveReferences(v3);
      v4 = this->mParent.mOffset;
      if ( v4 )
      {
        v5 = (char *)&this->mParent + v4;
        if ( v5 )
        {
          v6 = (ActionNodeRoot *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 144i64))(v5);
          if ( v6 )
            ActionNodeRoot::AddToInitList(v6, v3);
        }
      }
    }
  }
  v7 = this->mActionNode.mOffset;
  if ( !v7 || !(UFG::qOffset64<ActionNode *> *)((char *)&this->mActionNode + v7) )
  {
    v8 = this->mParent.mOffset;
    if ( v8 )
    {
      v9 = (ActionNode *)((char *)&this->mParent + v8);
      if ( v9 )
        ActionNodeReference::IsResolved(this, v9);
    }
  }
  ActionNode::ResolveReferences(this);
}

// File Line: 3778
// RVA: 0x271100
void __fastcall ActionNodeFileReference::RemoveReferences(ActionNodeFileReference *this)
{
  __int64 mOffset; // rax
  char *v3; // rcx

  mOffset = this->mActionNode.mOffset;
  if ( mOffset )
  {
    v3 = (char *)&this->mActionNode + mOffset;
    if ( v3 )
      (*(void (__fastcall **)(char *))(*(_QWORD *)v3 + 248i64))(v3);
  }
  ActionNode::RemoveReferences(this);
}

// File Line: 3792
// RVA: 0x270E80
void __fastcall ActionNodeFileReference::Reload(ActionNodeFileReference *this, UFG::qBaseTreeRB *reloadEntry)
{
  UFG::qBaseNodeRB *v2; // rbp
  UFG::qBaseTreeRB *Head; // rbx
  __int64 mOffset; // rax
  char *v6; // rcx
  ActionNodeRoot *mParent; // rax
  __int64 v8; // rax
  UFG::qOffset64<ActionNode *> *p_mActionNode; // rdi
  char *v10; // rdx
  __int64 v11; // rax
  char *v12; // rcx
  UFG::qBaseNodeRB *v13; // rcx
  __int64 v14; // rax

  v2 = 0i64;
  Head = reloadEntry;
  if ( reloadEntry )
  {
    mParent = (ActionNodeRoot *)reloadEntry->mNULL.mParent;
  }
  else
  {
    Head = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&ActionNode::sActionTreeFileEntries);
    if ( !Head )
      return;
    while ( 1 )
    {
      mOffset = this->mActionNode.mOffset;
      v6 = mOffset ? (char *)&this->mActionNode + mOffset : 0i64;
      if ( v6 == (char *)Head->mNULL.mParent && this == *(ActionNodeFileReference **)&Head->mCount )
        break;
      Head = UFG::qBaseTreeRB::GetNext(&ActionNode::sActionTreeFileEntries.mTree, &Head->mRoot);
      if ( !Head )
        return;
    }
    mParent = (ActionNodeRoot *)Head->mNULL.mParent;
  }
  if ( mParent )
  {
    v8 = this->mActionNode.mOffset;
    p_mActionNode = &this->mActionNode;
    if ( v8 )
    {
      v10 = (char *)p_mActionNode + v8;
      if ( (UFG::qOffset64<ActionNode *> *)((char *)p_mActionNode + v8) )
      {
        v11 = *((_QWORD *)v10 + 2);
        if ( v11 )
        {
          v12 = &v10[v11 + 16];
          if ( v12 )
            (*(void (__fastcall **)(char *))(*(_QWORD *)v12 + 184i64))(v12);
        }
      }
    }
    p_mActionNode->mOffset = 0i64;
    v13 = Head->mNULL.mParent;
    *(_QWORD *)&Head->mCount = this;
    if ( v13 )
    {
      v14 = this->mParent.mOffset;
      if ( v14 )
      {
        if ( (UFG::qOffset64<ActionNode *> *)((char *)&this->mParent + v14) )
        {
          v13->mChild[1] = (UFG::qBaseNodeRB *)((char *)this + v14 - (char *)v13);
          if ( p_mActionNode->mOffset )
            v2 = (UFG::qBaseNodeRB *)((char *)p_mActionNode + p_mActionNode->mOffset);
          if ( v13 != v2 )
            p_mActionNode->mOffset = (char *)v13 - (char *)p_mActionNode;
        }
      }
    }
  }
}

// File Line: 3961
// RVA: 0x1483D60
__int64 dynamic_initializer_for__gActionNodeMemoryTracker__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&gActionNodeMemoryTracker.mNodes.mTree);
  stru_1423AE978.mNode.mPrev = (UFG::qNode<ActionNodeMemoryTracker::Node,ActionNodeMemoryTracker::Node> *)&stru_1423AE978;
  stru_1423AE978.mNode.mNext = (UFG::qNode<ActionNodeMemoryTracker::Node,ActionNodeMemoryTracker::Node> *)&stru_1423AE978;
  unk_1423AE988 = 0i64;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gActionNodeMemoryTracker__);
}

// File Line: 3974
// RVA: 0x14803E0
__int64 dynamic_initializer_for__ActionNode::sActionTreeFileEntries__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&ActionNode::sActionTreeFileEntries.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__ActionNode::sActionTreeFileEntries__);
}

// File Line: 3978
// RVA: 0x26F740
Expression::IMemberMap *__fastcall ActionNode::Load(const char *fileName)
{
  const char *v2; // rcx
  unsigned int v3; // eax
  UFG::qResourceData *v4; // rax
  UFG::qResourceData *v5; // rcx
  UFG::qBaseNodeRB *mParent; // rax
  const char *v8; // rdx

  v2 = &fileName[(int)UFG::qStringLength(fileName) - 1];
  if ( v2 >= fileName )
  {
    while ( *v2 != 92 && *v2 != 47 )
    {
      if ( --v2 < fileName )
        goto LABEL_7;
    }
    ++v2;
  }
LABEL_7:
  v3 = UFG::qStringHashUpper32(v2, -1);
  v4 = UFG::qResourceInventory::Get(&gActionTreeResourceInventory, v3);
  v5 = v4;
  if ( v4 )
  {
    mParent = v4[1].mNode.mParent;
    if ( mParent )
      return (Expression::IMemberMap *)((char *)&mParent[2].mChild[2] + (_QWORD)v5);
  }
  else
  {
    v8 = "<NULL>";
    if ( fileName )
      v8 = fileName;
    UFG::qPrintf("WARNING: ActionNode::Load: couldnt find act file in binary: %s\n", v8);
  }
  return 0i64;
}

// File Line: 4271
// RVA: 0x26BED0
void __fastcall ActionNode::BeginDeferredResolve(ActionNode *this)
{
  gActionNode_DeferredResolve = 1;
}

// File Line: 4275
// RVA: 0x26DB40
void __fastcall ActionNode::EndDeferredResolve(ActionNode *this)
{
  if ( !gActionNode_BareBonesLoading )
    ((void (__fastcall *)(ActionNode *))this->vfptr[2].SetResourceOwner)(this);
  this->vfptr->ResolveReferences(this);
  gActionNode_DeferredResolve = 0;
}

// File Line: 4360
// RVA: 0x26B3D0
void __fastcall ActionNode::AddOnEnterCallback(
        ActionNode *this,
        fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *callback_delegate)
{
  ConditionCallback *mFirstCallback; // r8
  fastdelegate::detail::GenericClass *m_pthis; // rdx
  char *v6; // rdx
  ConditionCallback *v7; // rax

  mFirstCallback = this->mFirstCallback;
  if ( mFirstCallback )
  {
    m_pthis = callback_delegate->m_Closure.m_pthis;
    while ( mFirstCallback->m_CallbackDelegate.m_Closure.m_pthis != m_pthis
         || mFirstCallback->m_CallbackDelegate.m_Closure.m_pFunction != callback_delegate->m_Closure.m_pFunction
         || mFirstCallback->mType )
    {
      mFirstCallback = mFirstCallback->mNextCallback;
      if ( !mFirstCallback )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    v6 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "ConditionCallback", 0i64, 1u);
    if ( v6 )
    {
      *(_QWORD *)v6 = 0i64;
      *((_QWORD *)v6 + 1) = 0i64;
      *((_QWORD *)v6 + 2) = 0i64;
      *((_DWORD *)v6 + 6) = 0;
    }
    else
    {
      v6 = 0i64;
    }
    *((_QWORD *)v6 + 2) = callback_delegate->m_Closure.m_pFunction;
    *((_QWORD *)v6 + 1) = callback_delegate->m_Closure.m_pthis;
    v7 = this->mFirstCallback;
    if ( v7 )
    {
      while ( v7->mNextCallback )
        v7 = v7->mNextCallback;
      v7->mNextCallback = (ConditionCallback *)v6;
    }
    else
    {
      this->mFirstCallback = (ConditionCallback *)v6;
    }
  }
}

// File Line: 4397
// RVA: 0x26B4A0
void __fastcall ActionNode::AddOnExitCallback(
        ActionNode *this,
        fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *callback_delegate)
{
  ConditionCallback *mFirstCallback; // rax
  fastdelegate::detail::GenericClass *m_pthis; // rdx
  char *v6; // rdx
  ConditionCallback *v7; // rax

  mFirstCallback = this->mFirstCallback;
  if ( mFirstCallback )
  {
    m_pthis = callback_delegate->m_Closure.m_pthis;
    while ( mFirstCallback->m_CallbackDelegate.m_Closure.m_pthis != m_pthis
         || mFirstCallback->m_CallbackDelegate.m_Closure.m_pFunction != callback_delegate->m_Closure.m_pFunction
         || mFirstCallback->mType != ON_EXIT )
    {
      mFirstCallback = mFirstCallback->mNextCallback;
      if ( !mFirstCallback )
        goto LABEL_7;
    }
  }
  else
  {
LABEL_7:
    v6 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "ConditionCallback", 0i64, 1u);
    if ( v6 )
    {
      *(_QWORD *)v6 = 0i64;
      *((_QWORD *)v6 + 1) = 0i64;
      *((_QWORD *)v6 + 2) = 0i64;
      *((_DWORD *)v6 + 6) = 1;
    }
    else
    {
      v6 = 0i64;
    }
    *((_QWORD *)v6 + 2) = callback_delegate->m_Closure.m_pFunction;
    *((_QWORD *)v6 + 1) = callback_delegate->m_Closure.m_pthis;
    v7 = this->mFirstCallback;
    if ( v7 )
    {
      while ( v7->mNextCallback )
        v7 = v7->mNextCallback;
      v7->mNextCallback = (ConditionCallback *)v6;
    }
    else
    {
      this->mFirstCallback = (ConditionCallback *)v6;
    }
  }
}

// File Line: 4434
// RVA: 0x26FCA0
ActionNode *__fastcall ActionNode::New(const char *fileName, unsigned __int64 toolVersion)
{
  UFG::qSharedString *v3; // rax
  UFG::qSharedString *v4; // rbx
  char *v5; // rdi
  MemberMapFileManager *DataBaseRoot; // rax
  char *ActiveProjectAbsoluteDataPath; // rax
  int v8; // eax
  __int64 i; // rcx
  char *v10; // rax
  char *v11; // rax
  UFG::qString *FilenameWithoutExtension; // rax
  char *mText; // rbx
  UFG::qString result; // [rsp+30h] [rbp-468h] BYREF
  __int64 v16; // [rsp+58h] [rbp-440h]
  UFG::qString v17; // [rsp+60h] [rbp-438h] BYREF
  char dest[1024]; // [rsp+90h] [rbp-408h] BYREF

  v16 = -2i64;
  v3 = (UFG::qSharedString *)UFG::qMalloc(0x48ui64, "ActionNode::ActionTreeFileEntry", 0i64);
  v4 = v3;
  v5 = 0i64;
  if ( v3 )
  {
    v3->mText = 0i64;
    v3[1].mText = 0i64;
    v3[2].mText = 0i64;
    v3[4].mText = 0i64;
    UFG::qSharedString::qSharedString(v3 + 5);
    UFG::qSharedString::qSharedString(v4 + 6);
    v4[7].mText = 0i64;
    v4[8].mText = 0i64;
  }
  else
  {
    v4 = 0i64;
  }
  DataBaseRoot = MemberMapFileManager::GetDataBaseRoot();
  ActiveProjectAbsoluteDataPath = MemberMapFileManager::GetActiveProjectAbsoluteDataPath(DataBaseRoot);
  makeFullPath(&result, ActiveProjectAbsoluteDataPath, fileName);
  UFG::qSharedString::operator=(v4 + 5, fileName);
  UFG::qSharedString::operator=(v4 + 6, result.mData);
  UFG::qStringCopy(dest, 1024, result.mData, -1);
  v8 = UFG::qStringLength(dest);
  for ( i = 0i64; i < v8; ++i )
  {
    if ( dest[i] == 92 )
      dest[i] = 47;
  }
  LODWORD(v4[3].mText) = UFG::qStringHashUpper32(dest, -1);
  UFG::qBaseTreeRB::Add(&ActionNode::sActionTreeFileEntries.mTree, (UFG::qBaseNodeRB *)v4);
  v10 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xF0ui64, "ActionNodeRoot", 0i64, 1u);
  if ( v10 )
  {
    ActionNodeRoot::ActionNodeRoot((ActionNodeRoot *)v10);
    v5 = v11;
  }
  v4[4].mText = v5;
  FilenameWithoutExtension = UFG::qString::GetFilenameWithoutExtension(&result, &v17);
  (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v4[4].mText + 80i64))(
    v4[4].mText,
    FilenameWithoutExtension->mData);
  UFG::qString::~qString(&v17);
  ActionNode::smRoot->vfptr[2].__vecDelDtor(ActionNode::smRoot, (unsigned int)v4[4].mText);
  mText = v4[4].mText;
  UFG::qString::~qString(&result);
  return (ActionNode *)mText;
}

// File Line: 4573
// RVA: 0x14804D0
__int64 dynamic_initializer_for__ActionNodeRoot::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActionNodeRoot", 0xFFFFFFFF);
  ActionNodeRoot::sClassNameUID = result;
  return result;
}

// File Line: 4609
// RVA: 0x268A80
void __fastcall ActionNodeRoot::ActionNodeRoot(ActionNodeRoot *this)
{
  ActionNodeImplementation::ActionNodeImplementation(this);
  this->ActionNodeBank::UFG::qNode<ActionNodeBank,ActionNodeBank>::mPrev = &this->UFG::qNode<ActionNodeBank,ActionNodeBank>;
  this->ActionNodeBank::UFG::qNode<ActionNodeBank,ActionNodeBank>::mNext = &this->UFG::qNode<ActionNodeBank,ActionNodeBank>;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeBank::`vftable;
  this->m_Level = 0;
  this->mSignalMask = -1i64;
  this->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>::mPrev = &this->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>;
  this->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>::mNext = &this->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeRoot::`vftable;
  this->mToolVersion.mOffset = 1i64;
  BinString::Set(&this->mToolVersion, &customCaption);
  this->m_ConditionInitList.mNode.mPrev = &this->m_ConditionInitList.mNode;
  this->m_ConditionInitList.mNode.mNext = &this->m_ConditionInitList.mNode;
  this->m_SubRoots.mNode.mPrev = &this->m_SubRoots.mNode;
  this->m_SubRoots.mNode.mNext = &this->m_SubRoots.mNode;
  this->m_BanksToBalance.mNode.mPrev = &this->m_BanksToBalance.mNode;
  this->m_BanksToBalance.mNode.mNext = &this->m_BanksToBalance.mNode;
  this->mActionTreeType.mValue = 1;
  *(_QWORD *)this->m_NumNeededActionTreeComponentBaseValueUIDs = 0i64;
  *(_QWORD *)&this->m_NumNeededActionTreeComponentBaseValueUIDs[2] = 0i64;
  *(_QWORD *)&this->m_NumNeededActionTreeComponentBaseValueUIDs[4] = 0i64;
  *(_QWORD *)&this->m_NumNeededActionTreeComponentBaseValueUIDs[6] = 0i64;
  *(_QWORD *)&this->m_NumNeededActionTreeComponentBaseValueUIDs[8] = 0i64;
  this->m_NumNeededActionTreeComponentBaseValueUIDs[10] = 0;
}

// File Line: 4626
// RVA: 0x269C10
void __fastcall ActionNodeRoot::~ActionNodeRoot(ActionNodeRoot *this)
{
  char *v2; // rcx
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *mPrev; // rcx
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *mNext; // rax
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v5; // rcx
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v6; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeRoot::`vftable;
  UFG::qList<ActionNodeBank,ActionNodeBank,0,1>::~qList<ActionNodeBank,ActionNodeBank,0,1>(&this->m_BanksToBalance);
  UFG::qList<ActionNodeRoot,ActionNodeRootInitList,0,1>::~qList<ActionNodeRoot,ActionNodeRootInitList,0,1>(&this->m_SubRoots);
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>((UFG::qList<ITask,ITask,0,0> *)&this->m_ConditionInitList);
  if ( (this->mToolVersion.mOffset & 1) != 0 && (this->mToolVersion.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v2 = (char *)&this->mToolVersion + (this->mToolVersion.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v2 != BinString::sEmptyString )
      operator delete[](v2);
  }
  mPrev = this->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>::mPrev;
  mNext = this->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>::mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>::mPrev = &this->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>;
  this->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>::mNext = &this->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>;
  v5 = this->ActionNodeBank::UFG::qNode<ActionNodeBank,ActionNodeBank>::mPrev;
  v6 = this->ActionNodeBank::UFG::qNode<ActionNodeBank,ActionNodeBank>::mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->ActionNodeBank::UFG::qNode<ActionNodeBank,ActionNodeBank>::mPrev = &this->UFG::qNode<ActionNodeBank,ActionNodeBank>;
  this->ActionNodeBank::UFG::qNode<ActionNodeBank,ActionNodeBank>::mNext = &this->UFG::qNode<ActionNodeBank,ActionNodeBank>;
  ActionNodeImplementation::~ActionNodeImplementation(this);
}

// File Line: 4732
// RVA: 0x271A70
void __fastcall ActionNodeRoot::ResolveReferences(ActionNodeRoot *this)
{
  __int64 mOffset; // rax
  UFG::eActionTreeType mValue; // ebp
  ActionNode *v4; // rax
  char v5; // bl
  UFG::qNode<IConditionInit,IConditionInit> *i; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *mNext; // rax
  UFG::qNode<IConditionInit,IConditionInit> *mPrev; // rcx
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *j; // rdx
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *v10; // rax
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *v11; // rcx
  int *m_NumNeededActionTreeComponentBaseValueUIDs; // rbx
  int k; // edi
  int NumValueUIDs; // eax
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v15; // rbx
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v16; // rsi
  ActionNodeBank *m; // rbx

  mOffset = this->mParent.mOffset;
  mValue = this->mActionTreeType.mValue;
  if ( mOffset && (v4 = (ActionNode *)((char *)&this->mParent + mOffset)) != 0i64 && v4 == ActionNode::smRoot )
  {
    v5 = 1;
    UFG::ActionTreeComponentBase::BeginResolvingActionTreeType(mValue);
  }
  else
  {
    v5 = 0;
  }
  for ( i = this->m_ConditionInitList.mNode.mNext;
        &i[-1].mNext != (UFG::qNode<IConditionInit,IConditionInit> **)&this->mToolVersion;
        i = this->m_ConditionInitList.mNode.mNext )
  {
    mNext = i->mNext;
    mPrev = i->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
  }
  for ( j = this->m_SubRoots.mNode.mNext;
        &j[-8].mNext != (UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> **)&this->mID;
        j = this->m_SubRoots.mNode.mNext )
  {
    v10 = j->mNext;
    v11 = j->mPrev;
    v11->mNext = v10;
    v10->mPrev = v11;
    j->mPrev = j;
    j->mNext = j;
  }
  ActionNodeBank::ResolveReferences(this);
  if ( v5 )
  {
    m_NumNeededActionTreeComponentBaseValueUIDs = this->m_NumNeededActionTreeComponentBaseValueUIDs;
    for ( k = 0; k < 11; ++k )
    {
      NumValueUIDs = UFG::ActionTreeComponentBase::GetNumValueUIDs(mValue, (UFG::eActionTreeMemoryElementType)k);
      if ( NumValueUIDs < 0 )
        *m_NumNeededActionTreeComponentBaseValueUIDs = NumValueUIDs;
      else
        *m_NumNeededActionTreeComponentBaseValueUIDs += NumValueUIDs;
      ++m_NumNeededActionTreeComponentBaseValueUIDs;
    }
    UFG::ActionTreeComponentBase::EndResolvingActionTreeType(mValue);
  }
  v15 = this->m_BanksToBalance.mNode.mNext;
  v16 = &this->UFG::qNode<ActionNodeBank,ActionNodeBank>;
  for ( m = (ActionNodeBank *)&v15[-6].mNext; m != (ActionNodeBank *)v16; m = (ActionNodeBank *)&m->mNext[-6].mNext )
    ActionNodeBank::BalanceWeightsForThisLevel(m, 0i64);
}

// File Line: 4816
// RVA: 0x26B5D0
void __fastcall ActionNodeRoot::AddToInitList(ActionNodeRoot *this, IConditionInit *pCondition)
{
  UFG::qList<IConditionInit,IConditionInit,0,1> *p_m_ConditionInitList; // r8
  int v3; // ecx
  IConditionInit *p_mNext; // rax
  UFG::qNode<IConditionInit,IConditionInit> *mPrev; // rax

  p_m_ConditionInitList = &this->m_ConditionInitList;
  v3 = -1;
  p_mNext = (IConditionInit *)&p_m_ConditionInitList->mNode.mNext[-1].mNext;
  if ( p_mNext == (IConditionInit *)&p_m_ConditionInitList[-1].mNode.mNext )
    goto LABEL_6;
  while ( 1 )
  {
    ++v3;
    if ( p_mNext == pCondition )
      break;
    p_mNext = (IConditionInit *)&p_mNext->mNext[-1].mNext;
    if ( p_mNext == (IConditionInit *)&p_m_ConditionInitList[-1].mNode.mNext )
      goto LABEL_6;
  }
  if ( v3 == -1 )
  {
LABEL_6:
    mPrev = p_m_ConditionInitList->mNode.mPrev;
    mPrev->mNext = &pCondition->UFG::qNode<IConditionInit,IConditionInit>;
    pCondition->mPrev = mPrev;
    pCondition->mNext = &p_m_ConditionInitList->mNode;
    p_m_ConditionInitList->mNode.mPrev = &pCondition->UFG::qNode<IConditionInit,IConditionInit>;
  }
}

// File Line: 4835
// RVA: 0x26B570
void __fastcall ActionNodeRoot::AddToInitList(ActionNodeRoot *this, ActionNodeRoot *pNodeRoot)
{
  UFG::qList<ActionNodeRoot,ActionNodeRootInitList,0,1> *p_m_SubRoots; // r8
  int v3; // ecx
  ActionNodeRoot *p_mNext; // rax
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *mPrev; // rax

  p_m_SubRoots = &this->m_SubRoots;
  v3 = -1;
  p_mNext = (ActionNodeRoot *)&p_m_SubRoots->mNode.mNext[-8].mNext;
  if ( p_mNext == (ActionNodeRoot *)&p_m_SubRoots[-8].mNode.mNext )
    goto LABEL_6;
  while ( 1 )
  {
    ++v3;
    if ( p_mNext == pNodeRoot )
      break;
    p_mNext = (ActionNodeRoot *)&p_mNext->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>::mNext[-8].mNext;
    if ( p_mNext == (ActionNodeRoot *)&p_m_SubRoots[-8].mNode.mNext )
      goto LABEL_6;
  }
  if ( v3 == -1 )
  {
LABEL_6:
    mPrev = p_m_SubRoots->mNode.mPrev;
    mPrev->mNext = &pNodeRoot->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>;
    pNodeRoot->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>::mPrev = mPrev;
    pNodeRoot->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>::mNext = &p_m_SubRoots->mNode;
    p_m_SubRoots->mNode.mPrev = &pNodeRoot->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>;
  }
}

// File Line: 4873
// RVA: 0x272AA0
void __fastcall ActionNode::Trim(ActionNode *this, bool force)
{
  __int64 v3; // rax
  _DWORD *v4; // rdi
  __int64 v5; // rbx
  __int64 v6; // rsi
  __int64 v7; // rcx

  v3 = ((__int64 (__fastcall *)(ActionNode *))this->vfptr[1].GetResourcePath)(this);
  v4 = (_DWORD *)v3;
  if ( v3 )
  {
    v5 = 0i64;
    v6 = v3 + *(_QWORD *)(v3 + 8) + 8i64;
    if ( (*(_DWORD *)v3 & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v7 = *(_QWORD *)(v6 + 8 * v5) + v6 + 8 * v5;
        (*(void (__fastcall **)(__int64, bool))(*(_QWORD *)v7 + 264i64))(v7, force);
        v5 = (unsigned int)(v5 + 1);
      }
      while ( (unsigned int)v5 < (*v4 & 0x7FFFFFFFu) );
    }
  }
}

// File Line: 4891
// RVA: 0x26B340
void __fastcall ActionNodeImplementation::AddChild(ActionNodeImplementation *this, Condition *node)
{
  __int64 v2; // rax
  UFG::qOffset64<ActionNode *> *p_mPad0; // rbx
  char *v6; // rax

  v2 = *(_QWORD *)&node->mPad0;
  p_mPad0 = (UFG::qOffset64<ActionNode *> *)&node->mPad0;
  if ( v2 && (UFG::qOffset64<ActionNode *> *)((char *)p_mPad0 + v2) )
    (*(void (__fastcall **)(char *))(*(__int64 *)((char *)&p_mPad0->mOffset + v2) + 184))((char *)p_mPad0 + v2);
  if ( this )
    v6 = (char *)((char *)this - (char *)p_mPad0);
  else
    v6 = 0i64;
  p_mPad0->mOffset = (__int64)v6;
  BinPtrArray<ActionNode,0,0>::Add((BinPtrArray<Condition,1,0> *)&this->mChildren, node, "BinPtrArray.Add");
}

// File Line: 4910
// RVA: 0x272B40
void __fastcall ActionNodeImplementation::Trim(ActionNodeImplementation *this, bool force)
{
  __int64 mOffset; // rax
  unsigned int v3; // ebx
  char *v6; // rcx
  __int64 v7; // rax
  __int64 v8; // rax
  char *v9; // rcx
  __int64 v10; // rax
  char *v11; // rcx
  unsigned int v12; // edi
  char *v13; // r14
  __int64 v14; // rax
  char *v15; // rcx
  __int64 v16; // rcx
  __int64 v17; // rax
  _DWORD *v18; // rdi
  __int64 v19; // rsi
  __int64 v20; // rcx

  mOffset = this->mConditions.mOffset;
  ++in;
  v3 = 0;
  if ( mOffset )
  {
    v6 = (char *)&this->mConditions + mOffset;
    if ( v6 )
    {
      if ( (*((_DWORD *)v6 + 8) & 0x7FFFFFFF) == 0 )
      {
        v7 = *(_QWORD *)v6;
        ++trima;
        (*(void (__fastcall **)(char *, __int64))(v7 + 8))(v6, 1i64);
        this->mConditions.mOffset = 0i64;
      }
    }
  }
  v8 = this->mTracks.mOffset;
  if ( v8 )
  {
    v9 = (char *)&this->mTracks + v8;
    if ( !v9 || (*((_DWORD *)v9 + 4) & 0x7FFFFFFF) != 0 )
    {
      v11 = (char *)&this->mTracks + v8;
      if ( v11 )
      {
        v12 = 0;
        v13 = &v11[*((_QWORD *)v11 + 3) + 24];
        while ( 1 )
        {
          v14 = this->mTracks.mOffset;
          v15 = v14 ? (char *)&this->mTracks + v14 : 0i64;
          if ( v12 >= (*((_DWORD *)v15 + 4) & 0x7FFFFFFFu) )
            break;
          v16 = (__int64)&v13[8 * v12 + *(_QWORD *)&v13[8 * v12]];
          (*(void (__fastcall **)(__int64, ActionNodeImplementation *, bool))(*(_QWORD *)v16 + 112i64))(
            v16,
            this,
            force);
          ++v12;
        }
      }
    }
    else
    {
      v10 = *(_QWORD *)v9;
      ++trimb;
      (*(void (__fastcall **)(char *, __int64))(v10 + 8))(v9, 1i64);
      this->mTracks.mOffset = 0i64;
    }
  }
  v17 = ((__int64 (__fastcall *)(ActionNodeImplementation *))this->vfptr[1].GetResourcePath)(this);
  v18 = (_DWORD *)v17;
  if ( v17 )
  {
    v19 = v17 + *(_QWORD *)(v17 + 8) + 8i64;
    if ( (*(_DWORD *)v17 & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v20 = v19 + 8i64 * v3 + *(_QWORD *)(v19 + 8i64 * v3);
        (*(void (__fastcall **)(__int64, bool))(*(_QWORD *)v20 + 264i64))(v20, force);
        ++v3;
      }
      while ( v3 < (*v18 & 0x7FFFFFFFu) );
    }
  }
}

// File Line: 4950
// RVA: 0x272C90
void __fastcall ActionNodeRoot::Trim(ActionNodeRoot *this, bool force)
{
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *mNext; // rbx
  ActionID *p_mID; // rdi
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> **i; // rbx

  ActionNodeImplementation::Trim(this, force);
  mNext = this->m_SubRoots.mNode.mNext;
  p_mID = &this->mID;
  for ( i = &mNext[-8].mNext; i != (UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> **)p_mID; i = &i[16][-8].mNext )
    ((void (__fastcall *)(UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> **, bool))(*i)[16].mNext)(i, force);
}

// File Line: 4992
// RVA: 0x26CD40
Expression::IMemberMap *__fastcall ActionNodeRoot::CreateClone(ActionNodeRoot *this)
{
  char *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx
  _DWORD *v5; // rcx
  __int64 v6; // rdx

  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xF0ui64, "ActionNodeRoot::CreateClone", 0i64, 1u);
  if ( v2 )
  {
    ActionNodeRoot::ActionNodeRoot((ActionNodeRoot *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  *(_BYTE *)(v4 + 236) = this->mActionTreeType.mValue;
  v5 = (_DWORD *)(v4 + 192);
  v6 = 11i64;
  do
  {
    *v5 = *(_DWORD *)((char *)v5 + (_QWORD)this - v4);
    ++v5;
    --v6;
  }
  while ( v6 );
  *(_QWORD *)(v4 + 112) = this->mSignalMask;
  *(_BYTE *)(v4 + 106) = this->m_NeedsBalancing;
  *(_WORD *)(v4 + 104) = this->m_Level;
  ActionNodeImplementation::CopyFrom((ActionNodeImplementation *)v4, this);
  return (Expression::IMemberMap *)v4;
}

// File Line: 5008
// RVA: 0x26F080
void __fastcall ActionNodeRoot::Init(ActionNodeRoot *this, ActionContext *pContext)
{
  BinString *p_mToolVersion; // rbp
  BinString *p_mNext; // rcx
  __int64 v6; // rbx
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *mNext; // rbx
  ActionID *p_mID; // rsi
  ActionNodeRoot *i; // rbx

  p_mToolVersion = &this->mToolVersion;
  p_mNext = (BinString *)&this->m_ConditionInitList.mNode.mNext[-1].mNext;
  if ( p_mNext != p_mToolVersion )
  {
    do
    {
      v6 = p_mNext[2].mOffset - 8;
      (*(void (__fastcall **)(BinString *, ActionContext *))p_mNext->mOffset)(p_mNext, pContext);
      p_mNext = (BinString *)v6;
    }
    while ( (BinString *)v6 != p_mToolVersion );
  }
  mNext = this->m_SubRoots.mNode.mNext;
  p_mID = &this->mID;
  for ( i = (ActionNodeRoot *)&mNext[-8].mNext;
        i != (ActionNodeRoot *)p_mID;
        i = (ActionNodeRoot *)&i->UFG::qNode<ActionNodeRoot,ActionNodeRootInitList>::mNext[-8].mNext )
  {
    ActionNodeRoot::Init(i, pContext);
  }
}

// File Line: 5045
// RVA: 0x272730
void __fastcall NodeRefCondition::SetActionNodeParent(NodeRefCondition *this, ActionNode *parent)
{
  __int64 mOffset; // rax

  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset )
    (*(void (__fastcall **)(char *, ActionNode *))(*(__int64 *)((char *)&this->mActionNodeReference.mOffset + mOffset)
                                                 + 160))(
      (char *)&this->mActionNodeReference + mOffset,
      parent);
  else
    (*(void (__fastcall **)(_QWORD, ActionNode *))(MEMORY[0] + 160))(0i64, parent);
}

// File Line: 5050
// RVA: 0x2725A0
void __fastcall NodeRefCondition::Serialize(NodeRefCondition *this, IActionTreeSerializer *serializer)
{
  __int64 mOffset; // rax
  Expression::IMemberMap *v4; // rdx

  mOffset = this->mActionNodeReference.mOffset;
  if ( mOffset )
  {
    v4 = (Expression::IMemberMap *)((char *)&this->mActionNodeReference + mOffset);
    if ( v4 )
      IActionTreeSerializer::PushObjectToSerialize(serializer, v4);
  }
}

// File Line: 5068
// RVA: 0x268B70
void __fastcall ActionNode_Iterator::ActionNode_Iterator(ActionNode_Iterator *this)
{
  this->mCurrentItem = -1;
}

// File Line: 5073
// RVA: 0x26DF60
void __fastcall ActionNode_Iterator::First(ActionNode_Iterator *this, ActionNode *startingRoot)
{
  this->mCurrentItem = 0;
  this->mSearchStack[0] = startingRoot;
}

// File Line: 5079
// RVA: 0x26FE70
void __fastcall ActionNode_Iterator::Next(ActionNode_Iterator *this)
{
  char v2; // di
  __int64 mCurrentItem; // rax
  ActionNode *v4; // rsi
  ActionNode *v5; // rcx
  int v6; // eax
  ActionNode *v7; // rcx
  __int64 v8; // rdi

  v2 = 0;
  while ( 1 )
  {
    mCurrentItem = this->mCurrentItem;
    if ( (int)mCurrentItem < 0 )
      break;
    v4 = this->mSearchStack[mCurrentItem];
    if ( (__int64)v4->vfptr[1].GetClassname(v4) <= 0 )
    {
      v5 = (ActionNode *)((__int64 (__fastcall *)(ActionNode *))v4->vfptr[1].GetClassNameUID)(v4);
      if ( v5 )
      {
        this->mSearchStack[this->mCurrentItem] = v5;
        return;
      }
      while ( 1 )
      {
        v6 = --this->mCurrentItem;
        if ( v6 <= 0 )
          break;
        v7 = (ActionNode *)((__int64 (__fastcall *)(ActionNode *))this->mSearchStack[v6]->vfptr[1].GetClassNameUID)(this->mSearchStack[v6]);
        if ( v7 )
        {
          v2 = 1;
          this->mSearchStack[this->mCurrentItem] = v7;
          break;
        }
      }
      if ( !this->mCurrentItem )
        this->mCurrentItem = -1;
      if ( v2 )
        return;
    }
    else
    {
      if ( this->mCurrentItem + 1 < 32 )
      {
        v8 = ++this->mCurrentItem;
        this->mSearchStack[v8] = (ActionNode *)((__int64 (__fastcall *)(ActionNode *, _QWORD))v4->vfptr[1].Serialize)(
                                                 v4,
                                                 0i64);
        return;
      }
      this->mCurrentItem = -1;
    }
  }
}

// File Line: 5133
// RVA: 0x26F120
_BOOL8 __fastcall ActionNode_Iterator::IsDone(ActionNode_Iterator *this)
{
  return this->mCurrentItem < 0;
}

// File Line: 5138
// RVA: 0x26D670
ActionNode *__fastcall ActionNode_Iterator::CurrentItem(ActionNode_Iterator *this)
{
  __int64 mCurrentItem; // rax

  mCurrentItem = this->mCurrentItem;
  if ( (int)mCurrentItem < 0 )
    return 0i64;
  else
    return this->mSearchStack[mCurrentItem];
}

