// File Line: 247
// RVA: 0x26EF00
void ActionNode::Init(void)
{
  char *v0; // rdi
  _QWORD *v1; // rax
  UFG::allocator::free_link *v2; // rax
  UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *v3; // rcx
  UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *v4; // rax

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
    *((_DWORD *)v0 + 10) = UFG::qStringHashUpper32("Global", 0xFFFFFFFF);
    *((_DWORD *)v0 + 11) = 0;
    v0[48] = 0;
    *(_QWORD *)v0 = &ActionNodeImplementation::`vftable;
    *((_DWORD *)v0 + 18) = 0;
    *((_QWORD *)v0 + 10) = 0i64;
    *((_QWORD *)v0 + 7) = 0i64;
    *((_QWORD *)v0 + 8) = 0i64;
    v1 = v0 + 88;
    *v1 = v1;
    v1[1] = v1;
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
  v2 = UFG::qMalloc(0x40ui64, "MemberMapLoadHandler", 0i64);
  v3 = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)v2;
  if ( v2 )
  {
    v2->mNext = v2;
    v2[1].mNext = v2;
    v2[2].mNext = 0i64;
    v2[3].mNext = 0i64;
    v2[4].mNext = 0i64;
    v2[5].mNext = 0i64;
    v2[6].mNext = 0i64;
    v2[7].mNext = 0i64;
  }
  else
  {
    v3 = 0i64;
  }
  v3[1].mPrev = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)"act";
  v3[1].mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)"ActionTree";
  v3[2].mPrev = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)ActionNode::Load;
  v3[2].mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)ActionNode::NewMemberMap;
  v3[3].mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)ActionNode::GetDataBaseRoot;
  v4 = Expression::IMemberMap::smFileHandlers.mNode.mPrev;
  Expression::IMemberMap::smFileHandlers.mNode.mPrev->mNext = v3;
  v3->mPrev = v4;
  v3->mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)&Expression::IMemberMap::smFileHandlers;
  Expression::IMemberMap::smFileHandlers.mNode.mPrev = v3;
}

// File Line: 517
// RVA: 0x26DBE0
ActionNode *__fastcall ActionNode::Find(ActionPath *absolutePath, ActionNode *absoluteRoot)
{
  ActionPath *v2; // r14
  unsigned int v3; // ebx
  ActionNode *result; // rax
  unsigned int v5; // esi
  signed __int64 v6; // rdi
  __int64 v7; // rcx
  signed __int64 v8; // rdx
  int v9; // [rsp+30h] [rbp+8h]

  v2 = absolutePath;
  v3 = absolutePath->mPath.mCount & 0x7FFFFFFF;
  if ( v3 <= 1 )
    return 0i64;
  result = ActionNode::smRoot;
  v5 = 1;
  if ( absoluteRoot )
    result = absoluteRoot;
  if ( v3 > 1 )
  {
    v6 = 4i64;
    do
    {
      if ( !result )
        break;
      v7 = v2->mPath.mData.mOffset;
      v8 = (signed __int64)(v7 ? (UFG::qOffset64<ActionID *> *)((char *)&v2->mPath.mData + v7) : 0i64);
      v9 = *(_DWORD *)(v6 + v8);
      result = (ActionNode *)((__int64 (__fastcall *)(ActionNode *, int *, _QWORD))result->vfptr[1].CreateClone)(
                               result,
                               &v9,
                               0i64);
      ++v5;
      v6 += 4i64;
    }
    while ( v5 < v3 );
  }
  return result;
}

// File Line: 548
// RVA: 0x26DE60
ActionNode *__fastcall ActionNode::FindWithOldPath(ActionNode *this, const char *resourcePath)
{
  ActionNode *v2; // rbx
  unsigned int v3; // edi
  unsigned int v4; // esi
  signed __int64 v5; // r14
  __int64 *v6; // rcx
  int v7; // edx
  int v9; // [rsp+28h] [rbp-20h]
  __int64 v10; // [rsp+30h] [rbp-18h]
  int v11; // [rsp+60h] [rbp+18h]

  v9 = 0;
  v10 = 0i64;
  ActionPath::Append((ActionPath *)&v9, resourcePath);
  v2 = 0i64;
  v3 = v9 & 0x7FFFFFFF;
  if ( (v9 & 0x7FFFFFFFu) > 1 )
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
        v6 = v10 ? (__int64 *)((char *)&v10 + v10) : 0i64;
        v11 = *(_DWORD *)((char *)v6 + v5);
        v2 = (ActionNode *)((__int64 (__fastcall *)(ActionNode *, int *, _QWORD))v2->vfptr[1].CreateClone)(
                             v2,
                             &v11,
                             0i64);
        ++v4;
        v5 += 4i64;
      }
      while ( v4 < v3 );
    }
  }
  v7 = v9;
  if ( v9 >= 0 )
  {
    if ( v10 && (__int64 *)((char *)&v10 + v10) )
    {
      operator delete[]((char *)&v10 + v10);
      v7 = v9;
    }
    v10 = 0i64;
    v9 = v7 & 0x80000000;
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
  ActionNode *v1; // rdi
  __int64 v2; // rax
  char *v3; // rcx
  ConditionCallback *v4; // rdx
  ConditionCallback *v5; // rbx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNode::`vftable;
  v2 = this->mParent.mOffset;
  if ( v2 )
  {
    v3 = (char *)&this->mParent + v2;
    if ( v3 )
      (*(void (__fastcall **)(char *, ActionNode *))(*(_QWORD *)v3 + 184i64))(v3, v1);
  }
  v4 = v1->mFirstCallback;
  if ( v4 )
  {
    do
    {
      v5 = v4->mNextCallback;
      UFG::qMemoryPool2::Free(&gActionTreeMemoryPool, v4, 0x20ui64);
      v4 = v5;
    }
    while ( v5 );
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 627
// RVA: 0x2722C0
void __fastcall ActionNode::Serialize(ActionNode *this, IActionTreeSerializer *serializer)
{
  UFG::qOffset64<ActionNode *> *v2; // rdx
  ActionNode *v3; // r8
  unsigned int v4; // eax
  __int64 v5; // rcx
  ActionNode *v6; // rcx
  char *v7; // rcx
  unsigned int *v8; // rcx

  v2 = &this->mParent;
  v3 = this;
  v4 = 0;
  v5 = this->mParent.mOffset;
  if ( v5 )
    v6 = (ActionNode *)((char *)v2 + v5);
  else
    v6 = 0i64;
  if ( v6 == ActionNode::smRoot )
  {
    v2->mOffset = 0i64;
    if ( ActionNode::smRoot )
      v7 = (char *)((char *)ActionNode::smRoot - (char *)v2);
    else
      v7 = 0i64;
    v2->mOffset = (__int64)v7;
  }
  v8 = gMostUsedTable;
  while ( *v8 != v3->mID.mUID )
  {
    ++v4;
    ++v8;
    if ( v4 >= 0x40 )
    {
      v3->mMostUsedIndex = -1;
      return;
    }
  }
  v3->mMostUsedIndex = v4;
}

// File Line: 668
// RVA: 0x26E7A0
ActionPath *__fastcall ActionNode::GetNameFullPath(ActionNode *this, ActionPath *result)
{
  ActionPath *v2; // rbx

  v2 = result;
  result->mPath.mCount = 0;
  result->mPath.mData.mOffset = 0i64;
  ActionNode::GetNameFullPath(this, result);
  return v2;
}

// File Line: 675
// RVA: 0x26E7E0
void __fastcall ActionNode::GetNameFullPath(ActionNode *this, ActionPath *pathToPopulate)
{
  int v2; // er8
  ActionPath *v3; // rsi
  __int64 *v4; // rax
  __int64 v5; // rdx
  UFG::qOffset64<ActionNode *> *v6; // rcx
  __int64 v7; // rbx
  __int64 i; // rdx
  __int64 v9; // rax
  char *v10; // rcx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // edx
  __int64 v15; // rcx
  __int64 v16; // r8
  __int64 v17; // rax
  signed __int64 v18; // rdx
  int v19; // eax
  int v20[40]; // [rsp+20h] [rbp-1E8h]
  __int64 v21[41]; // [rsp+C0h] [rbp-148h]

  v2 = 0;
  v3 = pathToPopulate;
  if ( this )
  {
    v4 = v21;
    do
    {
      v5 = this->mParent.mOffset;
      *v4 = (__int64)this;
      v6 = &this->mParent;
      ++v2;
      ++v4;
      if ( !v5 )
        break;
      this = (ActionNode *)((char *)v6 + v5);
    }
    while ( this );
  }
  v7 = 0i64;
  for ( i = v2 - 1; i >= 0; --i )
  {
    v20[v7] = *(_DWORD *)(v21[i] + 40);
    v7 = (unsigned int)(v7 + 1);
  }
  if ( v3->mPath.mCount >= 0 )
  {
    v9 = v3->mPath.mData.mOffset;
    if ( v9 )
    {
      v10 = (char *)&v3->mPath.mData + v9;
      if ( v10 )
        operator delete[](v10);
    }
    v3->mPath.mData.mOffset = 0i64;
    v3->mPath.mCount &= 0x80000000;
  }
  v11 = v3->mPath.mCount;
  v12 = v3->mPath.mCount & 0x7FFFFFFF;
  if ( (signed int)(v7 - v12) <= 0 )
  {
    v14 = v12 - v7;
    if ( v12 != (_DWORD)v7 )
    {
      if ( v14 < v12 )
        v3->mPath.mCount = v11 ^ (v11 ^ (v11 - v14)) & 0x7FFFFFFF;
      else
        v3->mPath.mCount = v11 & 0x80000000;
    }
  }
  else
  {
    if ( (unsigned int)v7 > v11 )
    {
      v13 = 1;
      if ( v11 )
        v13 = 2 * v11;
      for ( ; v13 < (unsigned int)v7; v13 *= 2 )
        ;
      if ( v13 - (unsigned int)v7 > 0x10000 )
        v13 = v7 + 0x10000;
      BinArray<ActionID,0>::Reallocate(&v3->mPath, v13, "ActionID.Set");
    }
    v3->mPath.mCount &= 0x80000000;
    v3->mPath.mCount |= v7 & 0x7FFFFFFF;
  }
  if ( (_DWORD)v7 )
  {
    v15 = 0i64;
    v16 = (unsigned int)v7;
    do
    {
      v17 = v3->mPath.mData.mOffset;
      if ( v17 )
        v18 = (signed __int64)&v3->mPath.mData + v17;
      else
        v18 = 0i64;
      v19 = v20[v15];
      ++v15;
      *(_DWORD *)(v15 * 4 + v18 - 4) = v19;
      --v16;
    }
    while ( v16 );
  }
}

// File Line: 707
// RVA: 0x26EBD0
void __fastcall ActionNode::GetResourcePath(ActionNode *this, char *path, int pathSize)
{
  int v3; // ebx
  char *v4; // rdi
  ActionPath *v5; // rax
  char *v6; // rax
  ActionPath result; // [rsp+28h] [rbp-20h]

  v3 = pathSize;
  v4 = path;
  v5 = ActionNode::GetNameFullPath(this, &result);
  v6 = ActionPath::GetString_DBG(v5);
  UFG::qSPrintf(v4, v3, v6);
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
  ActionPath *v2; // r14
  ActionNode *v3; // rbx
  unsigned int v5; // ebp
  unsigned int v6; // edi
  __int64 v7; // rsi
  __int64 v8; // rax
  signed __int64 v9; // rcx
  int v10; // eax
  UFG::qOffset64<ActionNode *> *v11; // rbx
  int v12; // [rsp+58h] [rbp+10h]

  v2 = relativePath;
  v3 = this;
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
      if ( !v3 )
        break;
      v8 = v2->mPath.mData.mOffset;
      if ( v8 )
        v9 = (signed __int64)&v2->mPath.mData + v8;
      else
        v9 = 0i64;
      v10 = *(_DWORD *)(v7 + v9);
      v12 = *(_DWORD *)(v7 + v9);
      if ( !(_S8_6 & 1) )
      {
        _S8_6 |= 1u;
        dword_1423AFFC8 = UFG::qStringHashUpper32("..", 0xFFFFFFFF);
        v10 = v12;
      }
      if ( v10 == dword_1423AFFC8 )
      {
        v11 = &v3->mParent;
        v3 = (ActionNode *)(v11->mOffset ? (UFG::qOffset64<ActionNode *> *)((char *)v11 + v11->mOffset) : 0i64);
      }
      else
      {
        if ( !(_S6_6 & 1) )
        {
          _S6_6 |= 1u;
          dword_1423AFFC0 = UFG::qStringHashUpper32(".", 0xFFFFFFFF);
          v10 = v12;
        }
        if ( v10 != dword_1423AFFC0 )
          v3 = (ActionNode *)((__int64 (__fastcall *)(ActionNode *, int *, _QWORD))v3->vfptr[1].CreateClone)(
                               v3,
                               &v12,
                               0i64);
      }
      ++v6;
      v7 += 4i64;
    }
    while ( v6 < v5 );
  }
  return v3;
}

// File Line: 786
// RVA: 0x272030
void ActionNode::ResolveReferencesGlobal(void)
{
  if ( ActionNode::smRoot )
  {
    ActionNode::sIsResolvingAllGlobal = 1;
    ((void (*)(void))ActionNode::smRoot->vfptr->ResolveReferences)();
    ActionNode::sIsResolvingAllGlobal = 0;
  }
}

// File Line: 808
// RVA: 0x271890
void __fastcall ActionNode::ResolveReferences(ActionNode *this)
{
  ActionNode *v1; // rbx
  __int64 v2; // rax
  ConditionGroup *v3; // rax
  ConditionGroup *v4; // rdi
  __int64 v5; // rax
  _DWORD *v6; // rdi
  __int64 v7; // rbx
  signed __int64 v8; // rsi

  v1 = this;
  v2 = ((__int64 (*)(void))this->vfptr[3].GetClassNameUID)();
  if ( v2 )
    (*(void (__fastcall **)(__int64, ActionNode *))(*(_QWORD *)v2 + 80i64))(v2, v1);
  v3 = (ConditionGroup *)v1->vfptr[3].GetClassname((Expression::IMemberMap *)&v1->vfptr);
  v4 = v3;
  if ( v3 )
  {
    ConditionGroup::ResortEntries(v3);
    ((void (__fastcall *)(ConditionGroup *, ActionNode *))v4->vfptr[1].GetClassNameUID)(v4, v1);
  }
  v5 = ((__int64 (__fastcall *)(ActionNode *))v1->vfptr[1].GetResourcePath)(v1);
  v6 = (_DWORD *)v5;
  if ( v5 )
  {
    v7 = 0i64;
    v8 = v5 + *(_QWORD *)(v5 + 8) + 8i64;
    if ( *(_DWORD *)v5 & 0x7FFFFFFF )
    {
      do
      {
        (*(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v8 + 8 * v7) + v8 + 8 * v7) + 56i64))();
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
  ActionNode *v2; // rsi
  ActionNode *v3; // rbx
  __int64 v4; // rax
  ConditionGroup *v5; // rax
  ConditionGroup *v6; // rdi
  __int64 v7; // rax
  _DWORD *v8; // rdi
  __int64 v9; // rbx
  signed __int64 v10; // r14
  signed __int64 v11; // rcx

  v2 = nodeRoot;
  v3 = this;
  v4 = ((__int64 (*)(void))this->vfptr[3].GetClassNameUID)();
  if ( v4 )
    (*(void (__fastcall **)(__int64, ActionNode *))(*(_QWORD *)v4 + 88i64))(v4, v2);
  v5 = (ConditionGroup *)v3->vfptr[3].GetClassname((Expression::IMemberMap *)&v3->vfptr);
  v6 = v5;
  if ( v5 )
  {
    ConditionGroup::ResortEntries(v5);
    ((void (__fastcall *)(ConditionGroup *, ActionNode *))v6->vfptr[1].GetResourcePath)(v6, v2);
  }
  v7 = ((__int64 (__fastcall *)(ActionNode *))v3->vfptr[1].GetResourcePath)(v3);
  v8 = (_DWORD *)v7;
  if ( v7 )
  {
    v9 = 0i64;
    v10 = v7 + *(_QWORD *)(v7 + 8) + 8i64;
    if ( *(_DWORD *)v7 & 0x7FFFFFFF )
    {
      do
      {
        v11 = *(_QWORD *)(v10 + 8 * v9) + v10 + 8 * v9;
        (*(void (__fastcall **)(signed __int64, ActionNode *))(*(_QWORD *)v11 + 240i64))(v11, v2);
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
  ActionNode *v1; // r14
  __int64 v2; // rax
  __int64 v3; // rbx
  __int64 v4; // rsi
  unsigned int v5; // edi
  signed __int64 v6; // r15
  __int64 v7; // rax
  _DWORD *v8; // rdi
  signed __int64 v9; // rsi

  v1 = this;
  v2 = ((__int64 (*)(void))this->vfptr[3].GetClassNameUID)();
  v3 = 0i64;
  v4 = v2;
  if ( v2 )
  {
    v5 = 0;
    v6 = v2 + *(_QWORD *)(v2 + 24) + 24i64;
    if ( *(_DWORD *)(v2 + 16) & 0x7FFFFFFF )
    {
      do
      {
        (*(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v6 + 8i64 * v5) + v6 + 8i64 * v5) + 104i64))();
        ++v5;
      }
      while ( v5 < (*(_DWORD *)(v4 + 16) & 0x7FFFFFFFu) );
    }
  }
  v7 = ((__int64 (__fastcall *)(ActionNode *))v1->vfptr[1].GetResourcePath)(v1);
  v8 = (_DWORD *)v7;
  if ( v7 )
  {
    v9 = v7 + *(_QWORD *)(v7 + 8) + 8i64;
    if ( *(_DWORD *)v7 & 0x7FFFFFFF )
    {
      do
      {
        (*(void (**)(void))(*(_QWORD *)(v9 + 8 * v3 + *(_QWORD *)(v9 + 8 * v3)) + 248i64))();
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < (*v8 & 0x7FFFFFFFu) );
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
  signed __int64 v4; // rsi

  v1 = ((__int64 (*)(void))this->vfptr[1].GetResourcePath)();
  v2 = (_DWORD *)v1;
  if ( v1 )
  {
    v3 = 0i64;
    v4 = v1 + *(_QWORD *)(v1 + 8) + 8i64;
    if ( *(_DWORD *)v1 & 0x7FFFFFFF )
    {
      do
      {
        (*(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v4 + 8 * v3) + v4 + 8 * v3) + 224i64))();
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
  ActionNodeImplementation *v1; // rbx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNode::`vftable;
  this->mParent.mOffset = 0i64;
  this->mFirstCallback = 0i64;
  this->mMostUsedIndex = -1;
  this->mUniqueID = 0;
  this->mID.mUID = UFG::qStringHashUpper32("NO_NAME", 0xFFFFFFFF);
  *(_DWORD *)&v1->mBreakPoint = 0;
  v1->mPad2 = 0;
  v1->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeImplementation::`vftable;
  v1->mChildren.mCount = 0;
  v1->mChildren.mData.mOffset = 0i64;
  v1->mConditions.mOffset = 0i64;
  v1->mTracks.mOffset = 0i64;
}

// File Line: 1175
// RVA: 0x269A10
void __fastcall ActionNodeImplementation::~ActionNodeImplementation(ActionNodeImplementation *this)
{
  ActionNodeImplementation *v1; // rbx
  __int64 v2; // rax
  __int64 v3; // rax
  char *v4; // rcx
  __int64 v5; // rax
  __int64 v6; // rax
  signed __int64 v7; // rcx
  __int64 v8; // rax
  signed __int64 v9; // rcx
  char *v10; // rdx
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 v13; // rax
  signed __int64 v14; // rcx
  __int64 v15; // rax
  char *v16; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeImplementation::`vftable;
  v2 = this->mConditions.mOffset;
  if ( v2 )
  {
    if ( (UFG::qOffset64<ConditionGroup *> *)((char *)&this->mConditions + v2) )
    {
      v3 = this->mConditions.mOffset;
      if ( v3 )
      {
        v4 = (char *)&this->mConditions + v3;
        if ( v4 )
          (*(void (__fastcall **)(char *, signed __int64))(*(_QWORD *)v4 + 8i64))(v4, 1i64);
      }
    }
  }
  v5 = v1->mTracks.mOffset;
  if ( v5 )
  {
    if ( (UFG::qOffset64<TrackGroup *> *)((char *)&v1->mTracks + v5) )
    {
      v6 = v1->mTracks.mOffset;
      if ( v6 )
      {
        v7 = (signed __int64)&v1->mTracks + v6;
        if ( v7 )
          (*(void (__fastcall **)(signed __int64, signed __int64))(*(_QWORD *)v7 + 8i64))(v7, 1i64);
      }
    }
  }
  while ( v1->mChildren.mCount & 0x7FFFFFFF )
  {
    v8 = v1->mChildren.mData.mOffset;
    if ( v8 )
      v9 = (signed __int64)&v1->mChildren.mData + v8;
    else
      v9 = 0i64;
    v10 = (char *)(v9 + 8i64 * ((v1->mChildren.mCount & 0x7FFFFFFFu) - 1));
    v11 = *(_QWORD *)v10;
    if ( *(_QWORD *)v10 && &v10[v11] )
      (*(void (__fastcall **)(char *, signed __int64))(*(_QWORD *)&v10[v11] + 8i64))(&v10[v11], 1i64);
  }
  v12 = v1->mParent.mOffset;
  if ( v12 && (UFG::qOffset64<ActionNode *> *)((char *)&v1->mParent + v12) )
  {
    v13 = v1->mParent.mOffset;
    if ( v13 )
      v14 = (signed __int64)&v1->mParent + v13;
    else
      v14 = 0i64;
    (*(void (__fastcall **)(signed __int64, ActionNodeImplementation *))(*(_QWORD *)v14 + 184i64))(v14, v1);
    v1->mParent.mOffset = 0i64;
  }
  if ( v1->mChildren.mCount >= 0 )
  {
    v15 = v1->mChildren.mData.mOffset;
    if ( v15 )
    {
      v16 = (char *)&v1->mChildren.mData + v15;
      if ( v16 )
        operator delete[](v16);
    }
    v1->mChildren.mData.mOffset = 0i64;
    v1->mChildren.mCount &= 0x80000000;
  }
  ActionNode::~ActionNode((ActionNode *)&v1->vfptr);
}

// File Line: 1213
// RVA: 0x26C340
void __fastcall ActionNodeImplementation::CopyFrom(ActionNodeImplementation *this, ActionNodeImplementation *source_action_node)
{
  __int64 v2; // rax
  UFG::qOffset64<ConditionGroup *> *v3; // rbx
  ActionNodeImplementation *v4; // rsi
  ActionNodeImplementation *v5; // rdi
  __int64 v6; // rax
  signed __int64 v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rax
  signed __int64 v10; // rbx
  __int64 v11; // rax
  signed __int64 v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rbp
  signed __int64 v15; // r14
  __int64 v16; // rbx

  v2 = this->mConditions.mOffset;
  v3 = &this->mConditions;
  v4 = source_action_node;
  v5 = this;
  if ( v2 && (UFG::qOffset64<ConditionGroup *> *)((char *)v3 + v2) )
  {
    (*(void (__fastcall **)(char *, signed __int64))(*(__int64 *)((char *)&v3->mOffset + v2) + 8))(
      (char *)v3 + v2,
      1i64);
    v3->mOffset = 0i64;
  }
  v6 = v4->mConditions.mOffset;
  if ( v6 )
  {
    v7 = (signed __int64)&v4->mConditions + v6;
    if ( v7 )
    {
      v8 = (*(__int64 (**)(void))(*(_QWORD *)v7 + 16i64))();
      if ( v8 )
        v8 -= (signed __int64)v3;
      v3->mOffset = v8;
    }
  }
  v9 = v5->mTracks.mOffset;
  v10 = (signed __int64)&v5->mTracks;
  if ( v9 && v9 + v10 )
  {
    (*(void (__fastcall **)(__int64, signed __int64))(*(_QWORD *)(v9 + v10) + 8i64))(v9 + v10, 1i64);
    *(_QWORD *)v10 = 0i64;
  }
  v11 = v4->mTracks.mOffset;
  if ( v11 )
  {
    v12 = (signed __int64)&v4->mTracks + v11;
    if ( v12 )
    {
      v13 = (*(__int64 (**)(void))(*(_QWORD *)v12 + 16i64))();
      if ( v13 )
        v13 -= v10;
      *(_QWORD *)v10 = v13;
    }
  }
  v14 = 0i64;
  v15 = (signed __int64)&v4->mChildren.mData + v4->mChildren.mData.mOffset;
  if ( v4->mChildren.mCount & 0x7FFFFFFF )
  {
    do
    {
      v16 = (*(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(v15 + 8 * v14) + v15 + 8 * v14) + 16i64))();
      v5->vfptr[2].__vecDelDtor((Expression::IMemberMap *)&v5->vfptr, v16);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v16 + 256i64))(v16);
      v14 = (unsigned int)(v14 + 1);
    }
    while ( (unsigned int)v14 < (v4->mChildren.mCount & 0x7FFFFFFFu) );
  }
  v5->mID.mUID = v4->mID.mUID;
  v5->mParent.mOffset = 0i64;
  v5->mBreakPoint = v4->mBreakPoint != 0;
}

// File Line: 1302
// RVA: 0x26DC80
ActionNode *__fastcall ActionNodeImplementation::FindChild(ActionNodeImplementation *this, ActionID *childAnimID, bool recursive)
{
  __int64 v3; // rbx
  bool v4; // di
  char *v5; // r14
  ActionID *v6; // rsi
  ActionNodeImplementation *v7; // rbp
  signed __int64 v8; // rcx
  _DWORD *v9; // r9
  ActionNode *result; // rax

  v3 = 0i64;
  v4 = recursive;
  v5 = (char *)&this->mChildren.mData + this->mChildren.mData.mOffset;
  v6 = childAnimID;
  v7 = this;
  if ( !(this->mChildren.mCount & 0x7FFFFFFF) )
    return 0i64;
  while ( 1 )
  {
    v8 = (signed __int64)&v5[8 * v3];
    v9 = (_DWORD *)(v8 + *(_QWORD *)&v5[8 * v3]);
    if ( v9[10] == v6->mUID )
      break;
    if ( v4 )
    {
      result = (ActionNode *)(*(__int64 (__fastcall **)(signed __int64, ActionID *, bool))(*(_QWORD *)v9 + 96i64))(
                               v8 + *(_QWORD *)&v5[8 * v3],
                               v6,
                               v4);
      if ( result )
        return result;
    }
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= (v7->mChildren.mCount & 0x7FFFFFFFu) )
      return 0i64;
  }
  return (ActionNode *)(v8 + *(_QWORD *)&v5[8 * v3]);
}

// File Line: 1328
// RVA: 0x272350
void __fastcall ActionNodeImplementation::Serialize(ActionNodeImplementation *this, IActionTreeSerializer *serializer)
{
  __int64 v2; // rax
  IActionTreeSerializer *v3; // r14
  ActionNodeImplementation *v4; // rsi
  char *v5; // rbx
  __int64 v6; // rax
  signed int v7; // ST40_4
  unsigned int v8; // ST30_4
  signed int v9; // ST28_4
  __int64 v10; // rax
  signed __int64 v11; // rbx
  __int64 v12; // rax
  unsigned int v13; // ebx
  signed __int64 v14; // r15
  char *v15; // rcx
  char *v16; // rdi
  __int64 v17; // rax
  __int64 v18; // [rsp+28h] [rbp-40h]
  __int64 v19; // [rsp+30h] [rbp-38h]
  __int64 v20; // [rsp+40h] [rbp-28h]

  v2 = this->mConditions.mOffset;
  v3 = serializer;
  v4 = this;
  if ( v2 )
  {
    v5 = (char *)&this->mConditions + v2;
    if ( v5 )
    {
      v6 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 32i64))(v5);
      v7 = -1;
      v8 = 0;
      v9 = 1;
      v3->vfptr->_PushObjectToSerialize(
        v3,
        v5,
        1u,
        (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
        (const char *)v6,
        (QUEUE_PRIORITY)v9,
        v8,
        0i64,
        v7,
        0i64);
    }
  }
  v10 = v4->mTracks.mOffset;
  if ( v10 )
  {
    v11 = (signed __int64)&v4->mTracks + v10;
    if ( v11 )
    {
      v12 = (*(__int64 (__fastcall **)(signed __int64))(*(_QWORD *)v11 + 32i64))(v11);
      LODWORD(v20) = -1;
      LODWORD(v19) = 0;
      LODWORD(v18) = 1;
      v3->vfptr->_PushObjectToSerialize(
        v3,
        (void *)v11,
        1u,
        (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
        (const char *)v12,
        (QUEUE_PRIORITY)v18,
        v19,
        0i64,
        v20,
        0i64);
    }
  }
  v13 = 0;
  v14 = (signed __int64)&v4->mChildren.mData + v4->mChildren.mData.mOffset;
  if ( v4->mChildren.mCount & 0x7FFFFFFF )
  {
    do
    {
      v15 = (char *)(v14 + 8i64 * v13);
      v16 = &v15[*(_QWORD *)v15];
      if ( v16 )
      {
        v17 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v16 + 32i64))(&v15[*(_QWORD *)v15]);
        LODWORD(v20) = -1;
        LODWORD(v19) = 0;
        LODWORD(v18) = 1;
        v3->vfptr->_PushObjectToSerialize(
          v3,
          v16,
          1u,
          (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
          (const char *)v17,
          (QUEUE_PRIORITY)v18,
          v19,
          0i64,
          v20,
          0i64);
      }
      ++v13;
    }
    while ( v13 < (v4->mChildren.mCount & 0x7FFFFFFFu) );
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
  return atexit(dynamic_atexit_destructor_for__gActionNodeFactory__);
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
  return atexit(dynamic_atexit_destructor_for__gActionNodeExtraFactory__);
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
  ActionNodeImplementation::CopyFrom(
    (ActionNodeImplementation *)&this->vfptr,
    (ActionNodeImplementation *)&source_action_node->vfptr);
}

// File Line: 1441
// RVA: 0x26CA90
Expression::IMemberMap *__fastcall ActionNodeBank::CreateClone(ActionNodeBank *this)
{
  ActionNodeBank *v1; // rdi
  char *v2; // rax
  char *v3; // rbx
  _QWORD *v4; // rax

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x78ui64, "ActionNodeBank::CreateClone", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    ActionNodeImplementation::ActionNodeImplementation((ActionNodeImplementation *)v2);
    v4 = v3 + 88;
    *v4 = v4;
    v4[1] = v4;
    *(_QWORD *)v3 = &ActionNodeBank::`vftable;
    *((_WORD *)v3 + 52) = 0;
    *((_QWORD *)v3 + 14) = -1i64;
  }
  else
  {
    v3 = 0i64;
  }
  *((_QWORD *)v3 + 14) = v1->mSignalMask;
  v3[106] = v1->m_NeedsBalancing;
  *((_WORD *)v3 + 52) = v1->m_Level;
  ActionNodeImplementation::CopyFrom((ActionNodeImplementation *)v3, (ActionNodeImplementation *)&v1->vfptr);
  return (Expression::IMemberMap *)v3;
}

// File Line: 1472
// RVA: 0x271940
void __fastcall ActionNodeBank::ResolveReferences(ActionNodeBank *this)
{
  ActionNodeBank *v1; // rbx
  __int64 v2; // rax
  signed int v3; // ecx
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v4; // rdx
  signed __int64 v5; // rax
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v6; // rax
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v7; // rcx

  v1 = this;
  ActionNode::ResolveReferences((ActionNode *)&this->vfptr);
  ActionNodeBank::UpdateSignalAndConditionMask(v1);
  if ( v1->m_NeedsBalancing )
  {
    v2 = ((__int64 (__fastcall *)(ActionNodeBank *))v1->vfptr[1].SetResourceOwner)(v1);
    v3 = -1;
    v4 = (UFG::qNode<ActionNodeBank,ActionNodeBank> *)(v2 + 176);
    v5 = *(_QWORD *)(v2 + 184) - 88i64;
    if ( (UFG::qNode<ActionNodeBank,ActionNodeBank> **)v5 == &v4[-6].mNext )
      goto LABEL_7;
    while ( 1 )
    {
      ++v3;
      if ( (ActionNodeBank *)v5 == v1 )
        break;
      v5 = *(_QWORD *)(v5 + 96) - 88i64;
      if ( (UFG::qNode<ActionNodeBank,ActionNodeBank> **)v5 == &v4[-6].mNext )
        goto LABEL_7;
    }
    if ( v3 == -1 )
    {
LABEL_7:
      v6 = v4->mPrev;
      v7 = (UFG::qNode<ActionNodeBank,ActionNodeBank> *)&v1->mPrev;
      v6->mNext = (UFG::qNode<ActionNodeBank,ActionNodeBank> *)&v1->mPrev;
      v7->mPrev = v6;
      v7->mNext = v4;
      v4->mPrev = (UFG::qNode<ActionNodeBank,ActionNodeBank> *)&v1->mPrev;
    }
  }
}

// File Line: 1524
// RVA: 0x2710E0
void __fastcall ActionNodeBank::RemoveReferences(ActionNodeBank *this)
{
  ActionNodeBank *v1; // rbx

  v1 = this;
  ActionNode::RemoveReferences((ActionNode *)&this->vfptr);
  ActionNodeBank::UpdateSignalAndConditionMask(v1);
}

// File Line: 1531
// RVA: 0x2737D0
void __fastcall ActionNodeBank::UpdateSignalAndConditionMask(ActionNodeBank *this)
{
  ActionNodeBank *v1; // rsi
  __int64 v2; // rbp
  __int64 v3; // rax
  int v4; // ebx
  __int64 v5; // rdi
  unsigned int v6; // er14
  signed __int64 v7; // r15
  __int64 v8; // rax
  __int64 v9; // rcx
  int i; // edx
  __int64 j; // rcx

  v1 = this;
  v2 = -1i64;
  v3 = ((__int64 (*)(void))this->vfptr[3].GetClassname)();
  if ( v3 )
    v2 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v3 + 96i64))(v3);
  v4 = 0;
  v5 = 0i64;
  v6 = 0;
  v7 = (signed __int64)&v1->mChildren.mData + v1->mChildren.mData.mOffset;
  if ( v1->mChildren.mCount & 0x7FFFFFFF )
  {
    do
    {
      v8 = (*(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(v7 + 8i64 * v6) + v7 + 8i64 * v6) + 216i64))();
      ++v6;
      v5 |= v8;
    }
    while ( v6 < (v1->mChildren.mCount & 0x7FFFFFFFu) );
  }
  if ( v2 != -1 )
  {
    if ( v5 == -1 )
    {
      v1->mSignalMask = v2;
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
  v1->mSignalMask = v5;
}

// File Line: 1576
// RVA: 0x26F7D0
ActionNodePlayable *__fastcall ActionNodeBank::Match(ActionNodeBank *this, ActionContext *context)
{
  ActionContext *v2; // rbp
  ActionNodeBank *v3; // rdi
  __int64 v5; // rax
  __int64 v6; // rsi
  char *v7; // rcx
  unsigned __int64 v8; // rax
  __int64 v9; // rax
  char *v10; // rax
  unsigned int v11; // ebx
  signed __int64 v12; // r14
  signed __int64 v13; // rcx

  v2 = context;
  v3 = this;
  if ( this->mDisable )
    return 0i64;
  v5 = this->mConditions.mOffset;
  v6 = 0i64;
  if ( v5 )
    v7 = (char *)&this->mConditions + v5;
  else
    v7 = 0i64;
  v8 = v3->mSignalMask;
  if ( v8 != -1i64 && !(v8 & context->mSignals) )
    return 0i64;
  if ( !v7 || (*((_DWORD *)v7 + 8) & 0x7FFFFFFF) <= 0 )
    goto LABEL_26;
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
  if ( (*(unsigned __int8 (**)(void))(*(_QWORD *)v7 + 80i64))() )
  {
LABEL_26:
    v11 = 0;
    v12 = (signed __int64)&v3->mChildren.mData + v3->mChildren.mData.mOffset;
    if ( v3->mChildren.mCount & 0x7FFFFFFF )
    {
      do
      {
        v13 = *(_QWORD *)(v12 + 8i64 * v11) + v12 + 8i64 * v11;
        v6 = (*(__int64 (__fastcall **)(signed __int64, ActionContext *))(*(_QWORD *)v13 + 200i64))(v13, v2);
        if ( v6 )
          break;
        ++v11;
      }
      while ( v11 < (v3->mChildren.mCount & 0x7FFFFFFFu) );
    }
  }
  return (ActionNodePlayable *)v6;
}

// File Line: 1762
// RVA: 0x26E6A0
ActionNodePlayable *__fastcall ActionNodeBank::GetFirstPlayable(ActionNodeBank *this)
{
  __int64 v1; // rbx
  ActionNodeBank *v2; // rdi
  char *v3; // rsi
  ActionNodePlayable *result; // rax

  v1 = 0i64;
  v2 = this;
  v3 = (char *)&this->mChildren.mData + this->mChildren.mData.mOffset;
  if ( !(this->mChildren.mCount & 0x7FFFFFFF) )
    return 0i64;
  while ( 1 )
  {
    result = (ActionNodePlayable *)(*(__int64 (**)(void))(*(_QWORD *)&v3[8 * v1 + *(_QWORD *)&v3[8 * v1]] + 208i64))();
    if ( result )
      break;
    v1 = (unsigned int)(v1 + 1);
    if ( (unsigned int)v1 >= (v2->mChildren.mCount & 0x7FFFFFFFu) )
      return 0i64;
  }
  return result;
}

// File Line: 1779
// RVA: 0x26B6B0
void __fastcall ActionNodeBank::BalanceWeights(ActionNodeBank *this, unsigned int level, ActionContext *context)
{
  unsigned int v3; // ebx
  ActionContext *v4; // rsi
  ActionNodeBank *v5; // rdi

  v3 = level;
  this->m_Level = level;
  v4 = context;
  v5 = this;
  if ( ActionNodeBank::BalanceWeightsForThisLevel(this, context) > 0 )
    ++v3;
  ActionNode::BalanceWeights((ActionNode *)&v5->vfptr, v3, v4);
}

// File Line: 1795
// RVA: 0x26B720
__int64 __usercall ActionNodeBank::BalanceWeightsForThisLevel@<rax>(ActionNodeBank *this@<rcx>, ActionContext *context@<rdx>, float a3@<xmm0>)
{
  unsigned int v3; // er15
  char *v4; // r13
  __int64 v5; // r14
  float v6; // xmm6_4
  float v7; // xmm10_4
  ActionNodeBank *v8; // rbx
  bool v9; // si
  __int64 v10; // rax
  __int64 v11; // rbp
  __int64 v12; // rdi
  signed __int64 v13; // r12
  __int64 v14; // rax
  __int64 v15; // rbx
  __int64 v16; // r14
  signed __int64 v17; // rcx
  __int64 v18; // rax
  __int64 v19; // rbp
  __int64 v20; // rdi
  signed __int64 v21; // r13
  int v22; // er14
  __int64 v23; // rax
  __int64 v24; // rbx
  signed __int64 v26; // [rsp+20h] [rbp-A8h]
  ActionNodeBank *v27; // [rsp+D0h] [rbp+8h]
  ActionContext *v28; // [rsp+D8h] [rbp+10h]
  int v29; // [rsp+E0h] [rbp+18h]
  char *v30; // [rsp+E8h] [rbp+20h]
  int v31; // [rsp+E8h] [rbp+20h]

  v28 = context;
  v27 = this;
  v3 = 0;
  v4 = (char *)&this->mChildren.mData + this->mChildren.mData.mOffset;
  v5 = 0i64;
  v6 = 0.0;
  v7 = 0.0;
  v8 = this;
  v9 = 1;
  v29 = 0;
  v30 = (char *)&this->mChildren.mData + this->mChildren.mData.mOffset;
  if ( !(this->mChildren.mCount & 0x7FFFFFFF) )
    return 0i64;
  do
  {
    v10 = (*(__int64 (**)(void))(*(_QWORD *)&v4[8 * v5 + *(_QWORD *)&v4[8 * v5]] + 272i64))();
    v11 = v10;
    if ( v10 )
    {
      v12 = 0i64;
      v13 = *(_QWORD *)(v10 + 40) + v10 + 40;
      if ( *(_DWORD *)(v10 + 32) & 0x7FFFFFFF )
      {
        do
        {
          v14 = (*(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(v13 + 8 * v12) + v13 + 8 * v12) + 112i64))();
          v15 = v14;
          if ( v14 )
          {
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 32i64))(v14);
            (*(void (__fastcall **)(__int64, ActionContext *))(*(_QWORD *)v15 + 24i64))(v15, v28);
            if ( a3 > 0.0 )
            {
              v6 = v6 + a3;
              ++v3;
            }
            v9 = v9 && (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v15 + 48i64))(v15);
          }
          v12 = (unsigned int)(v12 + 1);
        }
        while ( (unsigned int)v12 < (*(_DWORD *)(v11 + 32) & 0x7FFFFFFFu) );
        v4 = v30;
        v8 = v27;
      }
    }
    v5 = (unsigned int)(v5 + 1);
  }
  while ( (unsigned int)v5 < (v8->mChildren.mCount & 0x7FFFFFFFu) );
  if ( v6 == 0.0 )
    return v3;
  v16 = 0i64;
  v31 = 0;
  v17 = (signed __int64)&v8->mChildren.mData + v8->mChildren.mData.mOffset;
  v26 = (signed __int64)&v8->mChildren.mData + v8->mChildren.mData.mOffset;
  if ( !(v8->mChildren.mCount & 0x7FFFFFFF) )
    return v3;
  do
  {
    v18 = (*(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(v17 + 8 * v16) + v17 + 8 * v16) + 272i64))();
    v19 = v18;
    if ( v18 )
    {
      v20 = 0i64;
      v21 = *(_QWORD *)(v18 + 40) + v18 + 40;
      if ( *(_DWORD *)(v18 + 32) & 0x7FFFFFFF )
      {
        v22 = v29;
        do
        {
          v23 = (*(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(v21 + 8 * v20) + v21 + 8 * v20) + 112i64))();
          v24 = v23;
          if ( v23 )
          {
            (*(void (__fastcall **)(__int64, ActionContext *))(*(_QWORD *)v23 + 24i64))(v23, v28);
            if ( a3 > 0.0 )
            {
              ++v22;
              if ( ((signed int)v3 > 1i64 || !v9) && v22 != v3 )
              {
                a3 = (float)(a3 * 100.0) / v6;
                v7 = v7 + a3;
              }
              (*(void (__fastcall **)(__int64))(*(_QWORD *)v24 + 32i64))(v24);
              (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v24 + 40i64))(v24, v27->m_Level);
            }
          }
          v20 = (unsigned int)(v20 + 1);
        }
        while ( (unsigned int)v20 < (*(_DWORD *)(v19 + 32) & 0x7FFFFFFFu) );
        v8 = v27;
        v29 = v22;
        LODWORD(v16) = v31;
      }
    }
    v16 = (unsigned int)(v16 + 1);
    v31 = v16;
    v17 = v26;
  }
  while ( (unsigned int)v16 < (v8->mChildren.mCount & 0x7FFFFFFFu) );
  return v3;
} + 1);
    v31 = v16;
    v17 = v26;
  }
  while ( (unsigned int)v16 < (v8->mChildren.mCount & 0x7FFFFFFFu) );
  ret

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
  this->mID.mUID = UFG::qStringHashUpper32(namestr, 0xFFFFFFFF);
}

// File Line: 1974
// RVA: 0x26CBE0
ActionNodeImplementation *__fastcall ActionNodePlayable::CreateClone(ActionNodePlayable *this)
{
  ActionNodePlayable *v1; // rdi
  char *v2; // rax
  ActionNodeImplementation *v3; // rbx

  v1 = this;
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
  ActionNodeImplementation::CopyFrom(v3, (ActionNodeImplementation *)&v1->vfptr);
  return v3;
}

// File Line: 2001
// RVA: 0x26F8F0
ActionNodePlayable *__fastcall ActionNodePlayable::Match(ActionNodePlayable *this, ActionContext *context)
{
  ActionNodePlayable *v2; // rdi
  __int64 v4; // rax
  ActionNodePlayable *v5; // rbx
  char *v6; // rcx
  char v7; // al
  __int64 v8; // rax
  char *v9; // rax

  v2 = this;
  if ( this->mDisable )
    return 0i64;
  v4 = this->mConditions.mOffset;
  v5 = 0i64;
  if ( v4 )
    v6 = (char *)&this->mConditions + v4;
  else
    v6 = 0i64;
  v7 = 1;
  if ( v6 )
  {
    if ( (*((_DWORD *)v6 + 8) & 0x7FFFFFFF) != 1 || *((_QWORD *)v6 + 3) != -1i64 )
    {
      v7 = (*(__int64 (__fastcall **)(char *, ActionContext *))(*(_QWORD *)v6 + 80i64))(v6, context);
    }
    else
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
  }
  if ( v7 )
    v5 = v2;
  return v5;
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
  ActionNodeReference *v1; // rdi
  ActionPath *v2; // rbx
  __int64 v3; // rax
  __int64 v4; // rax
  char *v5; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeReference::`vftable;
  v2 = &this->mAnyPathToNode;
  if ( this->mAnyPathToNode.mPath.mCount >= 0 )
  {
    v3 = this->mAnyPathToNode.mPath.mData.mOffset;
    if ( v3 && (UFG::qOffset64<ActionID *> *)((char *)&v2->mPath.mData + v3) )
    {
      v4 = this->mAnyPathToNode.mPath.mData.mOffset;
      if ( v4 )
        v5 = (char *)&this->mAnyPathToNode.mPath.mData + v4;
      else
        v5 = 0i64;
      operator delete[](v5);
    }
    v2->mPath.mData.mOffset = 0i64;
    v2->mPath.mCount &= 0x80000000;
  }
  ActionNode::~ActionNode((ActionNode *)&v1->vfptr);
}

// File Line: 2715
// RVA: 0x26C480
void __fastcall ActionNodeReference::CopyFrom(ActionNodeReference *this, ActionNodeReference *source_action_node)
{
  ActionNodeReference *v2; // rbx
  ActionNodeReference *v3; // rdi

  v2 = source_action_node;
  v3 = this;
  BinArray<ActionID,0>::Clone(&source_action_node->mAnyPathToNode.mPath, &this->mAnyPathToNode.mPath);
  v3->mActionNode.mOffset = 0i64;
  v3->mID.mUID = v2->mID.mUID;
  v3->mParent.mOffset = 0i64;
  v3->mBreakPoint = v2->mBreakPoint != 0;
}

// File Line: 2736
// RVA: 0x26CC60
Expression::IMemberMap *__fastcall ActionNodeReference::CreateClone(ActionNodeReference *this)
{
  ActionNodeReference *v1; // rsi
  char *v2; // rbx
  signed __int64 v4; // [rsp+58h] [rbp+10h]

  v1 = this;
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
    v4 = (signed __int64)(v2 + 56);
    *(_DWORD *)v4 = 0;
    *(_QWORD *)(v4 + 8) = 0i64;
    *((_QWORD *)v2 + 9) = 0i64;
  }
  else
  {
    v2 = 0i64;
  }
  BinArray<ActionID,0>::Clone(&v1->mAnyPathToNode.mPath, (BinArray<ActionID,0> *)(v2 + 56));
  *((_QWORD *)v2 + 9) = 0i64;
  *((_DWORD *)v2 + 10) = v1->mID.mUID;
  *((_QWORD *)v2 + 2) = 0i64;
  v2[44] = v1->mBreakPoint != 0;
  return (Expression::IMemberMap *)v2;
}

// File Line: 2758
// RVA: 0x2724C0
void __fastcall ActionNodeReference::Serialize(ActionNodeReference *this, IActionTreeSerializer *serializer)
{
  __int64 v2; // rbx
  UFG::qOffset64<ActionNode *> *v3; // r10
  char v4; // di
  ActionNodeReference *v5; // r9
  ActionNodeReference *v6; // r8
  __int64 v7; // rax
  signed __int64 v8; // rcx
  ActionNode *v9; // rdx
  __int64 v10; // rax
  signed __int64 v11; // rcx
  ActionNode *v12; // rdx

  v2 = this->mActionNode.mOffset;
  v3 = &this->mActionNode;
  v4 = 0;
  v5 = this;
  if ( v2 )
  {
    v6 = (ActionNodeReference *)((char *)v3 + v2);
    if ( (UFG::qOffset64<ActionNode *> *)((char *)v3 + v2) )
    {
      while ( 1 )
      {
        v7 = v5->mParent.mOffset;
        v8 = (signed __int64)&v5->mParent;
        v9 = (ActionNode *)(v7 ? v7 + v8 : 0i64);
        if ( v9 == ActionNode::smRoot )
          break;
        if ( v7 )
        {
          v5 = (ActionNodeReference *)(v7 + v8);
          if ( v7 + v8 )
            continue;
        }
        v5 = 0i64;
        break;
      }
      while ( 1 )
      {
        v10 = v6->mParent.mOffset;
        v11 = (signed __int64)&v6->mParent;
        v12 = (ActionNode *)(v10 ? v10 + v11 : 0i64);
        if ( v12 == ActionNode::smRoot )
          break;
        if ( v10 )
        {
          v6 = (ActionNodeReference *)(v10 + v11);
          if ( v10 + v11 )
            continue;
        }
        v6 = 0i64;
        break;
      }
      v4 = 0;
      if ( v5 != v6 )
        v4 = 1;
    }
    if ( v2 && (UFG::qOffset64<ActionNode *> *)((char *)v3 + v2) && v4 )
    {
      v3->mOffset = 0i64;
      if ( (UFG::qOffset64<ActionNode *> *)((char *)v3 + v2) )
        v3->mOffset = v2;
      else
        v3->mOffset = 0i64;
    }
  }
}

// File Line: 2874
// RVA: 0x26F590
bool __fastcall ActionNodeReference::IsResolved(ActionNodeReference *this, ActionNode *relative_to_node)
{
  ActionNode *v2; // rsi
  ActionNodeReference *v3; // rbp
  int *v4; // rax
  int v5; // ebx
  ActionNode *v6; // rcx
  unsigned int v7; // ebx
  unsigned int v8; // esi
  signed __int64 v9; // r14
  __int64 v10; // rax
  signed __int64 v11; // rdx
  __int64 v12; // rax
  signed __int64 v13; // rax
  ActionNode *v14; // rdx
  int v16; // [rsp+50h] [rbp+8h]

  v2 = relative_to_node;
  v3 = this;
  if ( this->mAnyPathToNode.mPath.mCount & 0x7FFFFFFF )
  {
    v4 = (int *)this->mAnyPathToNode.mPath.mData.mOffset;
    if ( v4 )
      v4 = (int *)((char *)v4 + (_QWORD)this + 64);
    v5 = *v4;
  }
  else
  {
    v5 = v16;
  }
  if ( !(_S6_6 & 1) )
  {
    _S6_6 |= 1u;
    dword_1423AFFC0 = UFG::qStringHashUpper32(".", 0xFFFFFFFF);
  }
  if ( v5 == dword_1423AFFC0 )
    goto LABEL_39;
  if ( !(_S8_6 & 1) )
  {
    _S8_6 |= 1u;
    dword_1423AFFC8 = UFG::qStringHashUpper32("..", 0xFFFFFFFF);
  }
  if ( v5 == dword_1423AFFC8 )
  {
LABEL_39:
    v12 = v3->mParent.mOffset;
    if ( v12 )
    {
      v6 = (ActionNode *)((char *)&v3->mParent + v12);
      if ( v6 )
        v6 = ActionNode::FindRelative(v6, &v3->mAnyPathToNode);
    }
    else
    {
      v6 = 0i64;
    }
  }
  else if ( v2 )
  {
    v6 = ActionNode::Find(&v3->mAnyPathToNode, ActionNode::smRoot);
  }
  else
  {
    v6 = 0i64;
    v7 = v3->mAnyPathToNode.mPath.mCount & 0x7FFFFFFF;
    if ( v7 > 1 )
    {
      v6 = ActionNode::smRoot;
      v8 = 1;
      if ( v7 > 1 )
      {
        v9 = 4i64;
        do
        {
          if ( !v6 )
            break;
          v10 = v3->mAnyPathToNode.mPath.mData.mOffset;
          v11 = (signed __int64)(v10 ? (UFG::qOffset64<ActionID *> *)((char *)&v3->mAnyPathToNode.mPath.mData + v10) : 0i64);
          v16 = *(_DWORD *)(v9 + v11);
          v6 = (ActionNode *)((__int64 (__fastcall *)(ActionNode *, int *, _QWORD))v6->vfptr[1].CreateClone)(
                               v6,
                               &v16,
                               0i64);
          ++v8;
          v9 += 4i64;
        }
        while ( v8 < v7 );
      }
    }
  }
  v13 = (signed __int64)&v3->mActionNode;
  v14 = (ActionNode *)v3->mActionNode.mOffset;
  if ( v14 )
    v14 = (ActionNode *)((char *)v14 + v13);
  if ( v6 != v14 )
  {
    if ( v6 )
      v6 = (ActionNode *)((char *)v6 - v13);
    *(_QWORD *)v13 = v6;
  }
  return *(_QWORD *)v13 && *(_QWORD *)v13 + v13;
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
  __int64 v2; // rax
  ActionNode *v3; // rdi
  const char *v4; // rbp
  ActionNodeReference *v5; // rsi
  __int64 v6; // rax
  char *v7; // rcx
  __int64 v8; // rax

  v2 = this->mActionNode.mOffset;
  v3 = 0i64;
  v4 = path;
  v5 = this;
  if ( v2 && (UFG::qOffset64<ActionNode *> *)((char *)&this->mActionNode + v2) )
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
    v5->mAnyPathToNode.mPath.mData.mOffset = 0i64;
    v5->mAnyPathToNode.mPath.mCount &= 0x80000000;
  }
  ActionPath::Append(&v5->mAnyPathToNode, v4);
  v8 = v5->mParent.mOffset;
  if ( v8 )
    v3 = (ActionNode *)((char *)&v5->mParent + v8);
  ActionNodeReference::IsResolved(v5, v3);
}

// File Line: 3174
// RVA: 0x271A60
void __fastcall ActionNodeReference::ResolveReferences(ActionNodeReference *this)
{
  ActionNode::ResolveReferences((ActionNode *)&this->vfptr);
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
  ActionNodeFileReference *v1; // rdi
  UFG::qBaseNodeRB *v2; // rbx
  UFG::qBaseNodeRB *v3; // rcx
  __int64 v4; // rax
  signed __int64 v5; // rcx
  char *v6; // rcx
  ActionPath *v7; // rbx
  __int64 v8; // rax
  __int64 v9; // rax
  char *v10; // rcx
  __int64 v11; // rax
  signed __int64 v12; // rcx
  ConditionCallback *v13; // rdx
  ConditionCallback *v14; // rbx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeFileReference::`vftable;
  v2 = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&ActionNode::sActionTreeFileEntries);
  if ( v2 )
  {
    while ( v1 != (ActionNodeFileReference *)v2[2].mParent )
    {
      v2 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext(&ActionNode::sActionTreeFileEntries.mTree, v2);
      if ( !v2 )
        goto LABEL_8;
    }
    v2[2].mParent = 0i64;
    v3 = v2[1].mParent;
    if ( v3 )
      ((void (__fastcall *)(UFG::qBaseNodeRB *, signed __int64))v3->mParent->mChild[0])(v3, 1i64);
    v2[1].mParent = 0i64;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&ActionNode::sActionTreeFileEntries,
      (UFG::qBaseNodeVariableRB<unsigned __int64> *)v2);
  }
  else
  {
LABEL_8:
    if ( v1->m_IsClone )
    {
      v4 = v1->mActionNode.mOffset;
      if ( v4 )
      {
        v5 = (signed __int64)&v1->mActionNode + v4;
        if ( v5 )
          (*(void (__fastcall **)(signed __int64, signed __int64))(*(_QWORD *)v5 + 8i64))(v5, 1i64);
      }
    }
  }
  if ( !(~LOBYTE(v1->mRelativeFilePath.mOffset) & 1) )
  {
    if ( v1->mRelativeFilePath.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v6 = (char *)&v1->mRelativeFilePath + (v1->mRelativeFilePath.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v6 != BinString::sEmptyString )
        operator delete[](v6);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeReference::`vftable;
  v7 = &v1->mAnyPathToNode;
  if ( v1->mAnyPathToNode.mPath.mCount >= 0 )
  {
    v8 = v1->mAnyPathToNode.mPath.mData.mOffset;
    if ( v8 && (UFG::qOffset64<ActionID *> *)((char *)&v7->mPath.mData + v8) )
    {
      v9 = v1->mAnyPathToNode.mPath.mData.mOffset;
      if ( v9 )
        v10 = (char *)&v1->mAnyPathToNode.mPath.mData + v9;
      else
        v10 = 0i64;
      operator delete[](v10);
    }
    v1->mAnyPathToNode.mPath.mData.mOffset = 0i64;
    v7->mPath.mCount &= 0x80000000;
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&ActionNode::`vftable;
  v11 = v1->mParent.mOffset;
  if ( v11 )
  {
    v12 = (signed __int64)&v1->mParent + v11;
    if ( v12 )
      (*(void (__fastcall **)(signed __int64, ActionNodeFileReference *))(*(_QWORD *)v12 + 184i64))(v12, v1);
  }
  v13 = v1->mFirstCallback;
  if ( v13 )
  {
    do
    {
      v14 = v13->mNextCallback;
      UFG::qMemoryPool2::Free(&gActionTreeMemoryPool, v13, 0x20ui64);
      v13 = v14;
    }
    while ( v14 );
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 3291
// RVA: 0x272B20
void __fastcall ActionNodeFileReference::Trim(ActionNodeFileReference *this, __int64 force)
{
  __int64 v2; // rax
  char *v3; // rcx

  v2 = this->mActionNode.mOffset;
  if ( v2 )
  {
    v3 = (char *)&this->mActionNode + v2;
    if ( v3 )
      (*(void (__fastcall **)(char *, __int64))(*(_QWORD *)v3 + 264i64))(v3, force);
  }
}

// File Line: 3301
// RVA: 0x272330
void __fastcall ActionNodeFileReference::Serialize(ActionNodeFileReference *this, IActionTreeSerializer *serializer)
{
  __int64 v2; // rax
  IActionTreeSerializer *v3; // r8
  Expression::IMemberMap *v4; // rdx

  v2 = this->mActionNode.mOffset;
  v3 = serializer;
  if ( v2 )
  {
    v4 = (Expression::IMemberMap *)((char *)&this->mActionNode + v2);
    if ( v4 )
      IActionTreeSerializer::PushObjectToSerialize(v3, v4);
  }
}

// File Line: 3315
// RVA: 0x271460
void __fastcall ActionNodeFileReference::ResolveFileReferenceParent(ActionNodeFileReference *this)
{
  __int64 v1; // rax
  ActionNodeRoot *v2; // rbx
  __int64 v3; // rax
  UFG::qOffset64<ActionNode *> *v4; // r8
  __int64 v5; // rax
  char *v6; // rcx
  ActionNodeRoot *v7; // rax

  v1 = this->mActionNode.mOffset;
  if ( v1 )
  {
    v2 = (ActionNodeRoot *)((char *)&this->mActionNode + v1);
    if ( v2 )
    {
      v3 = v2->mParent.mOffset;
      v4 = &v2->mParent;
      if ( !v3 || !(UFG::qOffset64<ActionNode *> *)((char *)v4 + v3) )
      {
        v5 = this->mParent.mOffset;
        if ( v5 )
        {
          v6 = (char *)&this->mParent + v5;
          if ( v6 )
          {
            v4->mOffset = v6 - (char *)v4;
            v7 = (ActionNodeRoot *)(*(__int64 (**)(void))(*(_QWORD *)v6 + 144i64))();
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
void __fastcall ActionNodeFileReference::CopyFrom(ActionNodeFileReference *this, ActionNodeFileReference *source_action_node)
{
  ActionNodeFileReference *v2; // rdi
  ActionNodeFileReference *v3; // rbx
  const char *v4; // rdx
  __int64 v5; // rax
  signed __int64 v6; // rcx
  __int64 v7; // rax
  UFG::qOffset64<ActionNode *> *v8; // rcx

  v2 = source_action_node;
  v3 = this;
  if ( source_action_node->mRelativeFilePath.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    v4 = (char *)&source_action_node->mRelativeFilePath
       + (source_action_node->mRelativeFilePath.mOffset & 0xFFFFFFFFFFFFFFFEui64);
  else
    v4 = BinString::sEmptyString;
  BinString::Set(&this->mRelativeFilePath, v4);
  v3->m_Writeable = v2->m_Writeable;
  BinArray<ActionID,0>::Clone(&v2->mAnyPathToNode.mPath, &v3->mAnyPathToNode.mPath);
  v5 = v2->mActionNode.mOffset;
  if ( v5 && (v6 = (signed __int64)&v2->mActionNode + v5) != 0 )
  {
    v7 = (*(__int64 (**)(void))(*(_QWORD *)v6 + 16i64))();
    v8 = &v3->mActionNode;
    if ( v7 )
      v8->mOffset = v7 - (_QWORD)v8;
    else
      v8->mOffset = 0i64;
  }
  else
  {
    v3->mActionNode.mOffset = 0i64;
  }
  v3->mID.mUID = v2->mID.mUID;
  v3->mParent.mOffset = 0i64;
  v3->mBreakPoint = v2->mBreakPoint != 0;
}

// File Line: 3410
// RVA: 0x26CB40
Expression::IMemberMap *__fastcall ActionNodeFileReference::CreateClone(ActionNodeFileReference *this)
{
  ActionNodeFileReference *v1; // rdi
  char *v2; // rax
  char *v3; // rbx

  v1 = this;
  v2 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x60ui64, "ActionNodeFileReference::CreateClone", 0i64, 1u);
  v3 = v2;
  if ( v2 )
  {
    ActionNodeReference::ActionNodeReference((ActionNodeReference *)v2, ActionNodeFileReference::sUnresolvedName);
    *(_QWORD *)v3 = &ActionNodeFileReference::`vftable;
    *((_QWORD *)v3 + 10) = 1i64;
    BinString::Set((BinString *)v3 + 10, &customWorldMapCaption);
    *((_WORD *)v3 + 44) = 1;
  }
  else
  {
    v3 = 0i64;
  }
  ActionNodeFileReference::CopyFrom((ActionNodeFileReference *)v3, v1);
  v3[89] = 1;
  return (Expression::IMemberMap *)v3;
}

// File Line: 3439
// RVA: 0x2727B0
void __fastcall ActionNodeFileReference::SetName(ActionNodeFileReference *this, const char *namestr)
{
  __int64 v2; // rax
  char *v3; // rcx

  v2 = this->mActionNode.mOffset;
  if ( v2 )
  {
    v3 = (char *)&this->mActionNode + v2;
    if ( v3 )
      (*(void (__fastcall **)(char *, const char *))(*(_QWORD *)v3 + 80i64))(v3, namestr);
  }
}

// File Line: 3448
// RVA: 0x26E9D0
const char *__fastcall ActionNodeFileReference::GetName_DBG(ActionNodeFileReference *this)
{
  __int64 v1; // rax
  char *v2; // rcx
  const char *result; // rax

  v1 = this->mActionNode.mOffset;
  if ( v1 && (v2 = (char *)&this->mActionNode + v1) != 0i64 )
    result = (const char *)(*(__int64 (**)(void))(*(_QWORD *)v2 + 88i64))();
  else
    result = ActionNodeFileReference::sUnresolvedName;
  return result;
}

// File Line: 3483
// RVA: 0x275580
UFG::qString *__fastcall makeFullPath(UFG::qString *result, const char *base_directory, const char *rel_filename)
{
  UFG::qString *v3; // rbx

  v3 = result;
  UFG::qMakeFullPath(result, base_directory, rel_filename);
  return v3;
}

// File Line: 3670
// RVA: 0x271550
void __fastcall ActionNodeFileReference::ResolveFileReferences(ActionNodeFileReference *this)
{
  __int64 v1; // rax
  ActionNodeFileReference *v2; // rbx
  __int64 v3; // rax
  _DWORD *v4; // rdi
  __int64 v5; // rbx
  signed __int64 v6; // rsi
  char v7; // [rsp+20h] [rbp-208h]

  v1 = this->mActionNode.mOffset;
  v2 = this;
  if ( !v1 || !(UFG::qOffset64<ActionNode *> *)((char *)&this->mActionNode + v1) )
    this->vfptr->GetResourcePath((Expression::IMemberMap *)this, &v7, 512);
  v3 = ((__int64 (__fastcall *)(ActionNodeFileReference *))v2->vfptr[1].GetResourcePath)(v2);
  v4 = (_DWORD *)v3;
  if ( v3 )
  {
    v5 = 0i64;
    v6 = v3 + *(_QWORD *)(v3 + 8) + 8i64;
    if ( *(_DWORD *)v3 & 0x7FFFFFFF )
    {
      do
      {
        (*(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v6 + 8 * v5) + v6 + 8 * v5) + 224i64))();
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
  __int64 v1; // rax
  ActionNodeFileReference *v2; // rbx
  ActionNodeRoot *v3; // rdi
  __int64 v4; // rax
  signed __int64 v5; // rcx
  ActionNodeRoot *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rax
  ActionNode *v9; // rdx

  v1 = this->mActionNode.mOffset;
  v2 = this;
  if ( v1 )
  {
    v3 = (ActionNodeRoot *)((char *)&this->mActionNode + v1);
    if ( v3 )
    {
      v3->vfptr->ResolveReferences((Expression::IMemberMap *)&v3->vfptr);
      v4 = v2->mParent.mOffset;
      if ( v4 )
      {
        v5 = (signed __int64)&v2->mParent + v4;
        if ( v5 )
        {
          v6 = (ActionNodeRoot *)(*(__int64 (**)(void))(*(_QWORD *)v5 + 144i64))();
          if ( v6 )
            ActionNodeRoot::AddToInitList(v6, v3);
        }
      }
    }
  }
  v7 = v2->mActionNode.mOffset;
  if ( !v7 || !(UFG::qOffset64<ActionNode *> *)((char *)&v2->mActionNode + v7) )
  {
    v8 = v2->mParent.mOffset;
    if ( v8 )
    {
      v9 = (ActionNode *)((char *)&v2->mParent + v8);
      if ( v9 )
        ActionNodeReference::IsResolved((ActionNodeReference *)&v2->vfptr, v9);
    }
  }
  ActionNode::ResolveReferences((ActionNode *)&v2->vfptr);
}

// File Line: 3778
// RVA: 0x271100
void __fastcall ActionNodeFileReference::RemoveReferences(ActionNodeFileReference *this)
{
  __int64 v1; // rax
  ActionNodeFileReference *v2; // rbx
  char *v3; // rcx

  v1 = this->mActionNode.mOffset;
  v2 = this;
  if ( v1 )
  {
    v3 = (char *)&this->mActionNode + v1;
    if ( v3 )
      (*(void (**)(void))(*(_QWORD *)v3 + 248i64))();
  }
  ActionNode::RemoveReferences((ActionNode *)&v2->vfptr);
}

// File Line: 3792
// RVA: 0x270E80
void __fastcall ActionNodeFileReference::Reload(ActionNodeFileReference *this, ActionNode::ActionTreeFileEntry *reloadEntry)
{
  UFG::qBaseNodeRB *v2; // rbp
  UFG::qBaseNodeRB *v3; // rbx
  ActionNodeFileReference *v4; // rsi
  __int64 v5; // rax
  signed __int64 v6; // rcx
  ActionNodeRoot *v7; // rax
  __int64 v8; // rax
  UFG::qOffset64<ActionNode *> *v9; // rdi
  char *v10; // rdx
  __int64 v11; // rax
  signed __int64 v12; // rcx
  UFG::qBaseNodeRB *v13; // rcx
  __int64 v14; // rax

  v2 = 0i64;
  v3 = &reloadEntry->mNode;
  v4 = this;
  if ( reloadEntry )
  {
    v7 = reloadEntry->mRoot;
  }
  else
  {
    v3 = (UFG::qBaseNodeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&ActionNode::sActionTreeFileEntries);
    if ( !v3 )
      return;
    while ( 1 )
    {
      v5 = v4->mActionNode.mOffset;
      v6 = (signed __int64)(v5 ? (UFG::qOffset64<ActionNode *> *)((char *)&v4->mActionNode + v5) : 0i64);
      if ( (UFG::qBaseNodeRB *)v6 == v3[1].mParent && v4 == (ActionNodeFileReference *)v3[2].mParent )
        break;
      v3 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::GetNext(&ActionNode::sActionTreeFileEntries.mTree, v3);
      if ( !v3 )
        return;
    }
    v7 = (ActionNodeRoot *)v3[1].mParent;
  }
  if ( v7 )
  {
    v8 = v4->mActionNode.mOffset;
    v9 = &v4->mActionNode;
    if ( v8 )
    {
      v10 = (char *)v9 + v8;
      if ( (UFG::qOffset64<ActionNode *> *)((char *)v9 + v8) )
      {
        v11 = *((_QWORD *)v10 + 2);
        if ( v11 )
        {
          v12 = (signed __int64)&v10[v11 + 16];
          if ( v12 )
            (*(void (**)(void))(*(_QWORD *)v12 + 184i64))();
        }
      }
    }
    v9->mOffset = 0i64;
    v13 = v3[1].mParent;
    v3[2].mParent = (UFG::qBaseNodeRB *)v4;
    if ( v13 )
    {
      v14 = v4->mParent.mOffset;
      if ( v14 )
      {
        if ( (UFG::qOffset64<ActionNode *> *)((char *)&v4->mParent + v14) )
        {
          v13->mChild[1] = (UFG::qBaseNodeRB *)((char *)v4 + v14 - (char *)v13);
          if ( v9->mOffset )
            v2 = (UFG::qBaseNodeRB *)((char *)v9 + v9->mOffset);
          if ( v13 != v2 )
            v9->mOffset = (char *)v13 - (char *)v9;
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
  return atexit(dynamic_atexit_destructor_for__gActionNodeMemoryTracker__);
}

// File Line: 3974
// RVA: 0x14803E0
__int64 dynamic_initializer_for__ActionNode::sActionTreeFileEntries__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&ActionNode::sActionTreeFileEntries.mTree);
  return atexit(dynamic_atexit_destructor_for__ActionNode::sActionTreeFileEntries__);
}

// File Line: 3978
// RVA: 0x26F740
Expression::IMemberMap *__fastcall ActionNode::Load(const char *fileName)
{
  const char *v1; // rbx
  const char *v2; // rcx
  unsigned int v3; // eax
  UFG::qResourceData *v4; // rax
  UFG::qResourceData *v5; // rcx
  UFG::qBaseNodeRB *v6; // rax
  const char *v8; // rdx

  v1 = fileName;
  v2 = &fileName[(signed int)UFG::qStringLength(fileName) - 1];
  if ( v2 >= v1 )
  {
    while ( *v2 != 92 && *v2 != 47 )
    {
      if ( --v2 < v1 )
        goto LABEL_7;
    }
    ++v2;
  }
LABEL_7:
  v3 = UFG::qStringHashUpper32(v2, 0xFFFFFFFF);
  v4 = UFG::qResourceInventory::Get((UFG::qResourceInventory *)&gActionTreeResourceInventory.vfptr, v3);
  v5 = v4;
  if ( v4 )
  {
    v6 = v4[1].mNode.mParent;
    if ( v6 )
      return (Expression::IMemberMap *)((char *)&v6[2].mUID + (_QWORD)v5);
  }
  else
  {
    v8 = "<NULL>";
    if ( v1 )
      v8 = v1;
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
  ActionNode *v1; // rbx

  v1 = this;
  if ( !gActionNode_BareBonesLoading )
    ((void (*)(void))this->vfptr[2].SetResourceOwner)();
  v1->vfptr->ResolveReferences((Expression::IMemberMap *)&v1->vfptr);
  gActionNode_DeferredResolve = 0;
}

// File Line: 4360
// RVA: 0x26B3D0
void __fastcall ActionNode::AddOnEnterCallback(ActionNode *this, fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *callback_delegate)
{
  fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *v2; // rbx
  ActionNode *v3; // rdi
  ConditionCallback *v4; // r8
  fastdelegate::detail::GenericClass *v5; // rdx
  char *v6; // rdx
  _QWORD *v7; // rax

  v2 = callback_delegate;
  v3 = this;
  v4 = this->mFirstCallback;
  if ( v4 )
  {
    v5 = callback_delegate->m_Closure.m_pthis;
    while ( v4->m_CallbackDelegate.m_Closure.m_pthis != v5
         || v4->m_CallbackDelegate.m_Closure.m_pFunction != v2->m_Closure.m_pFunction
         || v4->mType )
    {
      v4 = v4->mNextCallback;
      if ( !v4 )
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
    *((_QWORD *)v6 + 2) = v2->m_Closure.m_pFunction;
    *((_QWORD *)v6 + 1) = v2->m_Closure.m_pthis;
    v7 = &v3->mFirstCallback->mNextCallback;
    if ( v7 )
    {
      while ( *v7 )
        v7 = (_QWORD *)*v7;
      *v7 = v6;
    }
    else
    {
      v3->mFirstCallback = (ConditionCallback *)v6;
    }
  }
}

// File Line: 4397
// RVA: 0x26B4A0
void __fastcall ActionNode::AddOnExitCallback(ActionNode *this, fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *callback_delegate)
{
  fastdelegate::FastDelegate2<ActionNode *,ActionContext *,void> *v2; // rbx
  ActionNode *v3; // rdi
  ConditionCallback *v4; // rax
  fastdelegate::detail::GenericClass *v5; // rdx
  char *v6; // rdx
  _QWORD *v7; // rax

  v2 = callback_delegate;
  v3 = this;
  v4 = this->mFirstCallback;
  if ( v4 )
  {
    v5 = callback_delegate->m_Closure.m_pthis;
    while ( v4->m_CallbackDelegate.m_Closure.m_pthis != v5
         || v4->m_CallbackDelegate.m_Closure.m_pFunction != v2->m_Closure.m_pFunction
         || v4->mType != 1 )
    {
      v4 = v4->mNextCallback;
      if ( !v4 )
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
    *((_QWORD *)v6 + 2) = v2->m_Closure.m_pFunction;
    *((_QWORD *)v6 + 1) = v2->m_Closure.m_pthis;
    v7 = &v3->mFirstCallback->mNextCallback;
    if ( v7 )
    {
      while ( *v7 )
        v7 = (_QWORD *)*v7;
      *v7 = v6;
    }
    else
    {
      v3->mFirstCallback = (ConditionCallback *)v6;
    }
  }
}

// File Line: 4434
// RVA: 0x26FCA0
ActionNode *__fastcall ActionNode::New(const char *fileName, unsigned __int64 toolVersion)
{
  const char *v2; // rsi
  UFG::qSharedString *v3; // rax
  UFG::qSharedString *v4; // rbx
  char *v5; // rdi
  MemberMapFileManager *v6; // rax
  char *v7; // rax
  int v8; // eax
  signed __int64 v9; // rcx
  char *v10; // rax
  char *v11; // rax
  UFG::qString *v12; // rax
  char *v13; // rbx
  UFG::qString result; // [rsp+30h] [rbp-468h]
  __int64 v16; // [rsp+58h] [rbp-440h]
  UFG::qString v17; // [rsp+60h] [rbp-438h]
  char dest[1024]; // [rsp+90h] [rbp-408h]

  v16 = -2i64;
  v2 = fileName;
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
  v6 = MemberMapFileManager::GetDataBaseRoot();
  v7 = MemberMapFileManager::GetActiveProjectAbsoluteDataPath(v6);
  makeFullPath(&result, v7, v2);
  UFG::qSharedString::operator=(v4 + 5, v2);
  UFG::qSharedString::operator=(v4 + 6, result.mData);
  UFG::qStringCopy(dest, 1024, result.mData, -1);
  v8 = UFG::qStringLength(dest);
  v9 = 0i64;
  if ( v8 > 0 )
  {
    do
    {
      if ( dest[v9] == 92 )
        dest[v9] = 47;
      ++v9;
    }
    while ( v9 < v8 );
  }
  LODWORD(v4[3].mText) = UFG::qStringHashUpper32(dest, 0xFFFFFFFF);
  UFG::qBaseTreeRB::Add(&ActionNode::sActionTreeFileEntries.mTree, (UFG::qBaseNodeRB *)v4);
  v10 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xF0ui64, "ActionNodeRoot", 0i64, 1u);
  if ( v10 )
  {
    ActionNodeRoot::ActionNodeRoot((ActionNodeRoot *)v10);
    v5 = v11;
  }
  v4[4].mText = v5;
  v12 = UFG::qString::GetFilenameWithoutExtension(&result, &v17);
  (*(void (__fastcall **)(char *, char *))(*(_QWORD *)v4[4].mText + 80i64))(v4[4].mText, v12->mData);
  UFG::qString::~qString(&v17);
  ActionNode::smRoot->vfptr[2].__vecDelDtor((Expression::IMemberMap *)ActionNode::smRoot, (unsigned int)v4[4].mText);
  v13 = v4[4].mText;
  UFG::qString::~qString(&result);
  return (ActionNode *)v13;
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
  ActionNodeRoot *v1; // rbx
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v2; // rax
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *v3; // rax
  UFG::qList<IConditionInit,IConditionInit,0,1> *v4; // [rsp+48h] [rbp+10h]
  UFG::qList<ActionNodeRoot,ActionNodeRootInitList,0,1> *v5; // [rsp+48h] [rbp+10h]
  UFG::qList<ActionNodeBank,ActionNodeBank,0,1> *v6; // [rsp+48h] [rbp+10h]

  v1 = this;
  ActionNodeImplementation::ActionNodeImplementation((ActionNodeImplementation *)&this->vfptr);
  v2 = (UFG::qNode<ActionNodeBank,ActionNodeBank> *)&v1->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeBank::`vftable;
  v1->m_Level = 0;
  v1->mSignalMask = -1i64;
  v3 = (UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *)&v1->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v1->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeRoot::`vftable;
  v1->mToolVersion.mOffset = 1i64;
  BinString::Set(&v1->mToolVersion, &customWorldMapCaption);
  v4 = &v1->m_ConditionInitList;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v5 = &v1->m_SubRoots;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  v6 = &v1->m_BanksToBalance;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  v1->mActionTreeType.mValue = 1;
  *(_QWORD *)v1->m_NumNeededActionTreeComponentBaseValueUIDs = 0i64;
  *(_QWORD *)&v1->m_NumNeededActionTreeComponentBaseValueUIDs[2] = 0i64;
  *(_QWORD *)&v1->m_NumNeededActionTreeComponentBaseValueUIDs[4] = 0i64;
  *(_QWORD *)&v1->m_NumNeededActionTreeComponentBaseValueUIDs[6] = 0i64;
  *(_QWORD *)&v1->m_NumNeededActionTreeComponentBaseValueUIDs[8] = 0i64;
  v1->m_NumNeededActionTreeComponentBaseValueUIDs[10] = 0;
}

// File Line: 4626
// RVA: 0x269C10
void __fastcall ActionNodeRoot::~ActionNodeRoot(ActionNodeRoot *this)
{
  ActionNodeRoot *v1; // rbx
  char *v2; // rcx
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *v3; // rdx
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *v4; // rcx
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *v5; // rax
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v6; // rdx
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v7; // rcx
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v8; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionNodeRoot::`vftable;
  UFG::qList<ActionNodeBank,ActionNodeBank,0,1>::~qList<ActionNodeBank,ActionNodeBank,0,1>(&this->m_BanksToBalance);
  UFG::qList<ActionNodeRoot,ActionNodeRootInitList,0,1>::~qList<ActionNodeRoot,ActionNodeRootInitList,0,1>(&v1->m_SubRoots);
  UFG::qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>::~qList<UFG::PowerManagedResource,UFG::PowerManagedResourceList,0,0>((UFG::qList<ITask,ITask,0,0> *)&v1->m_ConditionInitList);
  if ( !(~LOBYTE(v1->mToolVersion.mOffset) & 1) )
  {
    if ( v1->mToolVersion.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v2 = (char *)&v1->mToolVersion + (v1->mToolVersion.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v2 != BinString::sEmptyString )
        operator delete[](v2);
    }
  }
  v3 = (UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *)&v1->mPrev;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v3->mPrev = v3;
  v3->mNext = v3;
  v6 = (UFG::qNode<ActionNodeBank,ActionNodeBank> *)&v1->mPrev;
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v6->mPrev = v6;
  v6->mNext = v6;
  ActionNodeImplementation::~ActionNodeImplementation((ActionNodeImplementation *)&v1->vfptr);
}

// File Line: 4732
// RVA: 0x271A70
void __usercall ActionNodeRoot::ResolveReferences(ActionNodeRoot *this@<rcx>, float a2@<xmm0>)
{
  __int64 v2; // rax
  UFG::eActionTreeType v3; // ebp
  ActionNodeRoot *v4; // rsi
  ActionNode *v5; // rax
  char v6; // bl
  UFG::qNode<IConditionInit,IConditionInit> *i; // rdx
  UFG::qNode<IConditionInit,IConditionInit> *v8; // rax
  UFG::qNode<IConditionInit,IConditionInit> *v9; // rcx
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *j; // rdx
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *v11; // rax
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *v12; // rcx
  int *v13; // rbx
  UFG::eActionTreeMemoryElementType v14; // edi
  int v15; // eax
  UFG::qNode<ActionNodeBank,ActionNodeBank> *v16; // rbx
  signed __int64 v17; // rsi
  ActionNodeBank *k; // rbx

  v2 = this->mParent.mOffset;
  v3 = this->mActionTreeType.mValue;
  v4 = this;
  if ( v2 && (v5 = (ActionNode *)((char *)&this->mParent + v2)) != 0i64 && v5 == ActionNode::smRoot )
  {
    v6 = 1;
    UFG::ActionTreeComponentBase::BeginResolvingActionTreeType(v3);
  }
  else
  {
    v6 = 0;
  }
  for ( i = v4->m_ConditionInitList.mNode.mNext;
        &i[-1].mNext != (UFG::qNode<IConditionInit,IConditionInit> **)&v4->mToolVersion;
        i = v4->m_ConditionInitList.mNode.mNext )
  {
    v8 = i->mNext;
    v9 = i->mPrev;
    v9->mNext = v8;
    v8->mPrev = v9;
    i->mPrev = i;
    i->mNext = i;
  }
  for ( j = v4->m_SubRoots.mNode.mNext;
        &j[-8].mNext != (UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> **)&v4->mID;
        j = v4->m_SubRoots.mNode.mNext )
  {
    v11 = j->mNext;
    v12 = j->mPrev;
    v12->mNext = v11;
    v11->mPrev = v12;
    j->mPrev = j;
    j->mNext = j;
  }
  ActionNodeBank::ResolveReferences((ActionNodeBank *)&v4->vfptr);
  if ( v6 )
  {
    v13 = v4->m_NumNeededActionTreeComponentBaseValueUIDs;
    v14 = 0;
    do
    {
      v15 = UFG::ActionTreeComponentBase::GetNumValueUIDs(v3, v14);
      if ( v15 < 0 )
        *v13 = v15;
      else
        *v13 += v15;
      ++v14;
      ++v13;
    }
    while ( (signed int)v14 < 11 );
    UFG::ActionTreeComponentBase::EndResolvingActionTreeType(v3);
  }
  v16 = v4->m_BanksToBalance.mNode.mNext;
  v17 = (signed __int64)&v4->mPrev;
  for ( k = (ActionNodeBank *)&v16[-6].mNext; k != (ActionNodeBank *)v17; k = (ActionNodeBank *)&k->mNext[-6].mNext )
    ActionNodeBank::BalanceWeightsForThisLevel(k, 0i64, a2);
}

// File Line: 4816
// RVA: 0x26B5D0
void __fastcall ActionNodeRoot::AddToInitList(ActionNodeRoot *this, IConditionInit *pCondition)
{
  UFG::qList<IConditionInit,IConditionInit,0,1> *v2; // r8
  signed int v3; // ecx
  IConditionInit *v4; // rax
  UFG::qNode<IConditionInit,IConditionInit> *v5; // rax
  UFG::qNode<IConditionInit,IConditionInit> *v6; // rcx

  v2 = &this->m_ConditionInitList;
  v3 = -1;
  v4 = (IConditionInit *)&v2->mNode.mNext[-1].mNext;
  if ( v4 == (IConditionInit *)&v2[-1].mNode.mNext )
    goto LABEL_6;
  while ( 1 )
  {
    ++v3;
    if ( v4 == pCondition )
      break;
    v4 = (IConditionInit *)&v4->mNext[-1].mNext;
    if ( v4 == (IConditionInit *)&v2[-1].mNode.mNext )
      goto LABEL_6;
  }
  if ( v3 == -1 )
  {
LABEL_6:
    v5 = v2->mNode.mPrev;
    v6 = (UFG::qNode<IConditionInit,IConditionInit> *)&pCondition->mPrev;
    v5->mNext = (UFG::qNode<IConditionInit,IConditionInit> *)&pCondition->mPrev;
    v6->mPrev = v5;
    v6->mNext = &v2->mNode;
    v2->mNode.mPrev = (UFG::qNode<IConditionInit,IConditionInit> *)&pCondition->mPrev;
  }
}

// File Line: 4835
// RVA: 0x26B570
void __fastcall ActionNodeRoot::AddToInitList(ActionNodeRoot *this, ActionNodeRoot *pNodeRoot)
{
  UFG::qList<ActionNodeRoot,ActionNodeRootInitList,0,1> *v2; // r8
  signed int v3; // ecx
  ActionNodeRoot *v4; // rax
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *v5; // rax
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *v6; // rcx

  v2 = &this->m_SubRoots;
  v3 = -1;
  v4 = (ActionNodeRoot *)&v2->mNode.mNext[-8].mNext;
  if ( v4 == (ActionNodeRoot *)&v2[-8].mNode.mNext )
    goto LABEL_6;
  while ( 1 )
  {
    ++v3;
    if ( v4 == pNodeRoot )
      break;
    v4 = (ActionNodeRoot *)&v4->mNext[-8].mNext;
    if ( v4 == (ActionNodeRoot *)&v2[-8].mNode.mNext )
      goto LABEL_6;
  }
  if ( v3 == -1 )
  {
LABEL_6:
    v5 = v2->mNode.mPrev;
    v6 = (UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *)&pNodeRoot->mPrev;
    v5->mNext = (UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *)&pNodeRoot->mPrev;
    v6->mPrev = v5;
    v6->mNext = &v2->mNode;
    v2->mNode.mPrev = (UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *)&pNodeRoot->mPrev;
  }
}

// File Line: 4873
// RVA: 0x272AA0
void __fastcall ActionNode::Trim(ActionNode *this, bool force)
{
  bool v2; // bp
  __int64 v3; // rax
  _DWORD *v4; // rdi
  __int64 v5; // rbx
  signed __int64 v6; // rsi
  signed __int64 v7; // rcx

  v2 = force;
  v3 = ((__int64 (*)(void))this->vfptr[1].GetResourcePath)();
  v4 = (_DWORD *)v3;
  if ( v3 )
  {
    v5 = 0i64;
    v6 = v3 + *(_QWORD *)(v3 + 8) + 8i64;
    if ( *(_DWORD *)v3 & 0x7FFFFFFF )
    {
      do
      {
        v7 = *(_QWORD *)(v6 + 8 * v5) + v6 + 8 * v5;
        (*(void (__fastcall **)(signed __int64, bool))(*(_QWORD *)v7 + 264i64))(v7, v2);
        v5 = (unsigned int)(v5 + 1);
      }
      while ( (unsigned int)v5 < (*v4 & 0x7FFFFFFFu) );
    }
  }
}

// File Line: 4891
// RVA: 0x26B340
void __fastcall ActionNodeImplementation::AddChild(ActionNodeImplementation *this, ActionNode *node)
{
  __int64 v2; // rax
  UFG::qOffset64<ActionNode *> *v3; // rbx
  ActionNode *v4; // rsi
  ActionNodeImplementation *v5; // rdi
  signed __int64 v6; // rax

  v2 = node->mParent.mOffset;
  v3 = &node->mParent;
  v4 = node;
  v5 = this;
  if ( v2 && (UFG::qOffset64<ActionNode *> *)((char *)v3 + v2) )
    (*(void (**)(void))(*(__int64 *)((char *)&v3->mOffset + v2) + 184))();
  if ( v5 )
    v6 = (char *)v5 - (char *)v3;
  else
    v6 = 0i64;
  v3->mOffset = v6;
  BinPtrArray<ActionNode,0,0>::Add((BinPtrArray<Condition,1,0> *)&v5->mChildren, (Condition *)v4, "BinPtrArray.Add");
}

// File Line: 4910
// RVA: 0x272B40
void __fastcall ActionNodeImplementation::Trim(ActionNodeImplementation *this, bool force)
{
  __int64 v2; // rax
  unsigned int v3; // ebx
  bool v4; // bp
  ActionNodeImplementation *v5; // rsi
  char *v6; // rcx
  __int64 v7; // rax
  __int64 v8; // rax
  signed __int64 v9; // rcx
  __int64 v10; // rax
  signed __int64 v11; // rcx
  unsigned int v12; // edi
  signed __int64 v13; // r14
  __int64 v14; // rax
  signed __int64 v15; // rcx
  signed __int64 v16; // rcx
  __int64 v17; // rax
  _DWORD *v18; // rdi
  signed __int64 v19; // rsi
  signed __int64 v20; // rcx

  v2 = this->mConditions.mOffset;
  ++in;
  v3 = 0;
  v4 = force;
  v5 = this;
  if ( v2 )
  {
    v6 = (char *)&this->mConditions + v2;
    if ( v6 )
    {
      if ( !(*((_DWORD *)v6 + 8) & 0x7FFFFFFF) )
      {
        v7 = *(_QWORD *)v6;
        ++trima;
        (*(void (__fastcall **)(char *, signed __int64))(v7 + 8))(v6, 1i64);
        v5->mConditions.mOffset = 0i64;
      }
    }
  }
  v8 = v5->mTracks.mOffset;
  if ( v8 )
  {
    v9 = (signed __int64)&v5->mTracks + v8;
    if ( !v9 || *(_DWORD *)(v9 + 16) & 0x7FFFFFFF )
    {
      if ( v8 )
      {
        v11 = (signed __int64)&v5->mTracks + v8;
        if ( v11 )
        {
          v12 = 0;
          v13 = v11 + *(_QWORD *)(v11 + 24) + 24i64;
          while ( 1 )
          {
            v14 = v5->mTracks.mOffset;
            v15 = (signed __int64)(v14 ? (UFG::qOffset64<TrackGroup *> *)((char *)&v5->mTracks + v14) : 0i64);
            if ( v12 >= (*(_DWORD *)(v15 + 16) & 0x7FFFFFFFu) )
              break;
            v16 = *(_QWORD *)(v13 + 8i64 * v12) + v13 + 8i64 * v12;
            (*(void (__fastcall **)(signed __int64, ActionNodeImplementation *, bool))(*(_QWORD *)v16 + 112i64))(
              v16,
              v5,
              v4);
            ++v12;
          }
        }
      }
    }
    else
    {
      v10 = *(_QWORD *)v9;
      ++trimb;
      (*(void (__fastcall **)(signed __int64, signed __int64))(v10 + 8))(v9, 1i64);
      v5->mTracks.mOffset = 0i64;
    }
  }
  v17 = ((__int64 (__fastcall *)(ActionNodeImplementation *))v5->vfptr[1].GetResourcePath)(v5);
  v18 = (_DWORD *)v17;
  if ( v17 )
  {
    v19 = v17 + *(_QWORD *)(v17 + 8) + 8i64;
    if ( *(_DWORD *)v17 & 0x7FFFFFFF )
    {
      do
      {
        v20 = v19 + 8i64 * v3 + *(_QWORD *)(v19 + 8i64 * v3);
        (*(void (__fastcall **)(signed __int64, bool))(*(_QWORD *)v20 + 264i64))(v20, v4);
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
  bool v2; // si
  ActionNodeRoot *v3; // rdi
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *v4; // rbx
  signed __int64 v5; // rdi
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> **i; // rbx

  v2 = force;
  v3 = this;
  ActionNodeImplementation::Trim((ActionNodeImplementation *)&this->vfptr, force);
  v4 = v3->m_SubRoots.mNode.mNext;
  v5 = (signed __int64)&v3->mID;
  for ( i = &v4[-8].mNext; i != (UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> **)v5; i = &i[16][-8].mNext )
    ((void (__fastcall *)(UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> **, bool))(*i)[16].mNext)(i, v2);
}

// File Line: 4992
// RVA: 0x26CD40
Expression::IMemberMap *__fastcall ActionNodeRoot::CreateClone(ActionNodeRoot *this)
{
  ActionNodeRoot *v1; // rdi
  char *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx
  _DWORD *v5; // rcx
  signed __int64 v6; // rdx

  v1 = this;
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
  *(_BYTE *)(v4 + 236) = v1->mActionTreeType.mValue;
  v5 = (_DWORD *)(v4 + 192);
  v6 = 11i64;
  do
  {
    *v5 = *(_DWORD *)((char *)v5 + (_QWORD)v1 - v4);
    ++v5;
    --v6;
  }
  while ( v6 );
  *(_QWORD *)(v4 + 112) = v1->mSignalMask;
  *(_BYTE *)(v4 + 106) = v1->m_NeedsBalancing;
  *(_WORD *)(v4 + 104) = v1->m_Level;
  ActionNodeImplementation::CopyFrom((ActionNodeImplementation *)v4, (ActionNodeImplementation *)&v1->vfptr);
  return (Expression::IMemberMap *)v4;
}

// File Line: 5008
// RVA: 0x26F080
void __fastcall ActionNodeRoot::Init(ActionNodeRoot *this, ActionContext *pContext)
{
  BinString *v2; // rbp
  ActionNodeRoot *v3; // rsi
  BinString *v4; // rcx
  ActionContext *v5; // rdi
  signed __int64 v6; // rbx
  UFG::qNode<ActionNodeRoot,ActionNodeRootInitList> *v7; // rbx
  signed __int64 v8; // rsi
  ActionNodeRoot *i; // rbx

  v2 = &this->mToolVersion;
  v3 = this;
  v4 = (BinString *)&this->m_ConditionInitList.mNode.mNext[-1].mNext;
  v5 = pContext;
  if ( v4 != v2 )
  {
    do
    {
      v6 = v4[2].mOffset - 8;
      (*(void (__fastcall **)(BinString *, ActionContext *))v4->mOffset)(v4, v5);
      v4 = (BinString *)v6;
    }
    while ( (BinString *)v6 != v2 );
  }
  v7 = v3->m_SubRoots.mNode.mNext;
  v8 = (signed __int64)&v3->mID;
  for ( i = (ActionNodeRoot *)&v7[-8].mNext; i != (ActionNodeRoot *)v8; i = (ActionNodeRoot *)&i->mNext[-8].mNext )
    ActionNodeRoot::Init(i, v5);
}

// File Line: 5045
// RVA: 0x272730
void __fastcall NodeRefCondition::SetActionNodeParent(NodeRefCondition *this, ActionNode *parent)
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

// File Line: 5050
// RVA: 0x2725A0
void __fastcall NodeRefCondition::Serialize(NodeRefCondition *this, IActionTreeSerializer *serializer)
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
  ActionNode_Iterator *v1; // rbx
  char v2; // di
  __int64 v3; // rax
  ActionNode *v4; // rsi
  __int64 v5; // rcx
  int v6; // eax
  __int64 v7; // rcx
  __int64 v8; // rdi

  v1 = this;
  v2 = 0;
  while ( 1 )
  {
    v3 = v1->mCurrentItem;
    if ( (signed int)v3 < 0 )
      break;
    v4 = v1->mSearchStack[v3];
    if ( (signed int)v4->vfptr[1].GetClassname((Expression::IMemberMap *)&v4->vfptr) <= 0 )
    {
      v5 = v4->vfptr[1].GetClassNameUID((Expression::IMemberMap *)&v4->vfptr);
      if ( v5 )
      {
        v1->mSearchStack[v1->mCurrentItem] = (ActionNode *)v5;
        return;
      }
      while ( 1 )
      {
        v6 = --v1->mCurrentItem;
        if ( v6 <= 0 )
          break;
        v7 = ((__int64 (*)(void))v1->mSearchStack[v6]->vfptr[1].GetClassNameUID)();
        if ( v7 )
        {
          v2 = 1;
          v1->mSearchStack[v1->mCurrentItem] = (ActionNode *)v7;
          break;
        }
      }
      if ( !v1->mCurrentItem )
        v1->mCurrentItem = -1;
      if ( v2 )
        return;
    }
    else
    {
      if ( v1->mCurrentItem + 1 < 32 )
      {
        v8 = ++v1->mCurrentItem;
        v1->mSearchStack[v8] = (ActionNode *)((__int64 (__fastcall *)(ActionNode *, _QWORD))v4->vfptr[1].Serialize)(
                                               v4,
                                               0i64);
        return;
      }
      v1->mCurrentItem = -1;
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
  __int64 v1; // rax
  ActionNode *result; // rax

  v1 = this->mCurrentItem;
  if ( (signed int)v1 < 0 )
    result = 0i64;
  else
    result = this->mSearchStack[v1];
  return result;
}

