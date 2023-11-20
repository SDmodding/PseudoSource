// File Line: 36
// RVA: 0x193040
void __fastcall UFG::ContextDataBase::~ContextDataBase(UFG::ContextDataBase *this)
{
  this->vfptr = (UFG::ContextDataBaseVtbl *)&UFG::ContextDataBase::`vftable';
}

// File Line: 49
// RVA: 0x192430
void __fastcall UFG::ContextData<UFG::DUIPopupMenuWindow *>::ContextData<UFG::DUIPopupMenuWindow *>(UFG::ContextData<UFG::DUIPopupMenuWindow *> *this, const char *key, UFG::DUIPopupMenuWindow *const *value)
{
  UFG::DUIPopupMenuWindow *const *v3; // rbx
  UFG::ContextData<UFG::DUIPopupMenuWindow *> *v4; // rdi
  unsigned int v5; // eax

  v3 = value;
  v4 = this;
  v5 = UFG::qStringHashUpper32(key, 0xFFFFFFFF);
  v4->mNode.mParent = 0i64;
  v4->mNode.mChild[0] = 0i64;
  v4->mNode.mChild[1] = 0i64;
  v4->mNode.mUID = v5;
  v4->vfptr = (UFG::ContextDataBaseVtbl *)&UFG::ContextDataBase::`vftable';
  v4->vfptr = (UFG::ContextDataBaseVtbl *)&UFG::ContextData<UFG::DUIPopupMenuWindow *>::`vftable';
  v4->mData = *v3;
}

// File Line: 52
// RVA: 0x19A670
UFG::allocator::free_link *__fastcall UFG::ContextData<UFG::DUIPoint>::NewClone(UFG::ContextData<UFG::DUIPoint> *this)
{
  UFG::ContextData<UFG::DUIPoint> *v1; // rbx
  UFG::allocator::free_link *result; // rax
  unsigned int v3; // edx

  v1 = this;
  result = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  if ( !result )
    return 0i64;
  v3 = v1->mNode.mUID;
  result[1].mNext = 0i64;
  result[2].mNext = 0i64;
  result[3].mNext = 0i64;
  LODWORD(result[4].mNext) = v3;
  result->mNext = (UFG::allocator::free_link *)&UFG::ContextDataBase::`vftable';
  result->mNext = (UFG::allocator::free_link *)&UFG::ContextData<UFG::DUIPoint>::`vftable';
  result[5].mNext = (UFG::allocator::free_link *)v1->mData;
  return result;
}

// File Line: 74
// RVA: 0x192520
void __fastcall UFG::CommandContext::CommandContext(UFG::CommandContext *this, UFG::CommandContext *context)
{
  UFG::CommandContext *v2; // rbp
  UFG::qBaseTreeRB *v3; // rdi
  UFG::qBaseTreeRB *i; // rax
  signed __int64 v5; // rbx
  __int64 v6; // rax
  UFG::qBaseNodeRB *v7; // rdx

  v2 = context;
  this->vfptr = (UFG::CommandContextVtbl *)&UFG::CommandContext::`vftable';
  v3 = &this->mDictionary.mTree;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mDictionary.mTree);
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v2->mDictionary);
        ;
        i = UFG::qBaseTreeRB::GetNext(&v2->mDictionary.mTree, (UFG::qBaseNodeRB *)(v5 + 8)) )
  {
    v5 = (signed __int64)(i ? &i[-1].mCount : 0i64);
    if ( !v5 )
      break;
    v6 = (**(__int64 (__fastcall ***)(signed __int64))v5)(v5);
    if ( v6 )
      v7 = (UFG::qBaseNodeRB *)(v6 + 8);
    else
      v7 = 0i64;
    UFG::qBaseTreeRB::Add(v3, v7);
  }
}

// File Line: 82
// RVA: 0x193000
void __fastcall UFG::CommandContext::~CommandContext(UFG::CommandContext *this)
{
  Render::Skinning *v1; // rbx

  this->vfptr = (UFG::CommandContextVtbl *)&UFG::CommandContext::`vftable';
  v1 = (Render::Skinning *)&this->mDictionary;
  UFG::qTreeRB<UFG::ContextDataBase,UFG::ContextDataBase,1>::DeleteAll(&this->mDictionary);
  UFG::qBaseTreeRB::~qBaseTreeRB(v1);
}

// File Line: 86
// RVA: 0x192010
void __fastcall UFG::CommandContext::AddContext<UFG::DUIPopupMenuWindow *>(UFG::CommandContext *this, const char *key, UFG::DUIPopupMenuWindow *const *data)
{
  UFG::DUIPopupMenuWindow *const *v3; // rdi
  const char *v4; // rbp
  UFG::CommandContext *v5; // rsi
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::qBaseNodeRB *v9; // rbx
  __int64 v10; // rax

  v3 = data;
  v4 = key;
  v5 = this;
  v6 = UFG::qStringHashUpper32(key, 0xFFFFFFFF);
  if ( v6 && (v7 = UFG::qBaseTreeRB::Get(&v5->mDictionary.mTree, v6)) != 0i64 && v7 != (UFG::qBaseTreeRB *)8 )
  {
    v7->mNULL.mParent = (UFG::qBaseNodeRB *)*v3;
  }
  else
  {
    v8 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v9 = 0i64;
    if ( v8 )
      UFG::ContextData<UFG::DUIPopupMenuWindow *>::ContextData<UFG::DUIPopupMenuWindow *>(
        (UFG::ContextData<UFG::DUIPopupMenuWindow *> *)v8,
        v4,
        v3);
    else
      v10 = 0i64;
    if ( v10 )
      v9 = (UFG::qBaseNodeRB *)(v10 + 8);
    UFG::qBaseTreeRB::Add(&v5->mDictionary.mTree, v9);
  }
}

// File Line: 253
// RVA: 0x192F60
void __fastcall UFG::Command::~Command(UFG::Command *this)
{
  UFG::Command *v1; // rdi
  UFG::qNode<UFG::qString,UFG::qString> *v2; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v3; // rax
  UFG::qNode<UFG::Command,UFG::Command> *v4; // rdx
  UFG::qNode<UFG::Command,UFG::Command> *v5; // rcx
  UFG::qNode<UFG::Command,UFG::Command> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::CommandVtbl *)&UFG::Command::`vftable';
  UFG::qString::~qString(&this->mUserType);
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(&v1->mTags);
  v2 = v1->mTags.mNode.mPrev;
  v3 = v1->mTags.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mTags.mNode.mPrev = &v1->mTags.mNode;
  v1->mTags.mNode.mNext = &v1->mTags.mNode;
  UFG::qString::~qString(&v1->mDisplayText);
  UFG::qString::~qString(&v1->mName);
  v4 = (UFG::qNode<UFG::Command,UFG::Command> *)&v1->mPrev;
  v5 = v1->mPrev;
  v6 = v1->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v4->mPrev = v4;
  v4->mNext = v4;
}

