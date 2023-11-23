// File Line: 36
// RVA: 0x193040
void __fastcall UFG::ContextDataBase::~ContextDataBase(UFG::ContextDataBase *this)
{
  this->vfptr = (UFG::ContextDataBaseVtbl *)&UFG::ContextDataBase::`vftable;
}

// File Line: 49
// RVA: 0x192430
void __fastcall UFG::ContextData<UFG::DUIPopupMenuWindow *>::ContextData<UFG::DUIPopupMenuWindow *>(
        UFG::ContextData<UFG::DUIPopupMenuWindow *> *this,
        const char *key,
        UFG::DUIPopupMenuWindow **value)
{
  unsigned int v5; // eax

  v5 = UFG::qStringHashUpper32(key, -1);
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v5;
  this->vfptr = (UFG::ContextDataBaseVtbl *)&UFG::ContextDataBase::`vftable;
  this->vfptr = (UFG::ContextDataBaseVtbl *)&UFG::ContextData<UFG::DUIPopupMenuWindow *>::`vftable;
  this->mData = *value;
}

// File Line: 52
// RVA: 0x19A670
UFG::allocator::free_link *__fastcall UFG::ContextData<UFG::DUIPoint>::NewClone(UFG::ContextData<UFG::DUIPoint> *this)
{
  UFG::allocator::free_link *result; // rax
  unsigned int mUID; // edx

  result = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
  if ( !result )
    return 0i64;
  mUID = this->mNode.mUID;
  result[1].mNext = 0i64;
  result[2].mNext = 0i64;
  result[3].mNext = 0i64;
  LODWORD(result[4].mNext) = mUID;
  result->mNext = (UFG::allocator::free_link *)&UFG::ContextDataBase::`vftable;
  result->mNext = (UFG::allocator::free_link *)&UFG::ContextData<UFG::DUIPoint>::`vftable;
  result[5].mNext = (UFG::allocator::free_link *)this->mData;
  return result;
}

// File Line: 74
// RVA: 0x192520
void __fastcall UFG::CommandContext::CommandContext(UFG::CommandContext *this, UFG::CommandContext *context)
{
  UFG::qTreeRB<UFG::ContextDataBase,UFG::ContextDataBase,1> *p_mDictionary; // rdi
  UFG::qBaseTreeRB *i; // rax
  __int64 v5; // rbx
  __int64 v6; // rax
  UFG::qBaseNodeRB *v7; // rdx

  this->vfptr = (UFG::CommandContextVtbl *)&UFG::CommandContext::`vftable;
  p_mDictionary = &this->mDictionary;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mDictionary.mTree);
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&context->mDictionary);
        ;
        i = UFG::qBaseTreeRB::GetNext(&context->mDictionary.mTree, (UFG::qBaseNodeRB *)(v5 + 8)) )
  {
    v5 = i ? (__int64)&i[-1].mCount : 0i64;
    if ( !v5 )
      break;
    v6 = (**(__int64 (__fastcall ***)(__int64))v5)(v5);
    if ( v6 )
      v7 = (UFG::qBaseNodeRB *)(v6 + 8);
    else
      v7 = 0i64;
    UFG::qBaseTreeRB::Add(&p_mDictionary->mTree, v7);
  }
}

// File Line: 82
// RVA: 0x193000
void __fastcall UFG::CommandContext::~CommandContext(UFG::CommandContext *this)
{
  Render::Skinning *p_mDictionary; // rbx

  this->vfptr = (UFG::CommandContextVtbl *)&UFG::CommandContext::`vftable;
  p_mDictionary = (Render::Skinning *)&this->mDictionary;
  UFG::qTreeRB<UFG::ContextDataBase,UFG::ContextDataBase,1>::DeleteAll(&this->mDictionary);
  UFG::qBaseTreeRB::~qBaseTreeRB(p_mDictionary);
}

// File Line: 86
// RVA: 0x192010
void __fastcall UFG::CommandContext::AddContext<UFG::DUIPopupMenuWindow *>(
        UFG::CommandContext *this,
        const char *key,
        UFG::qBaseNodeRB **data)
{
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::qBaseNodeRB *v9; // rbx
  __int64 v10; // rax

  v6 = UFG::qStringHashUpper32(key, -1);
  if ( v6 && (v7 = UFG::qBaseTreeRB::Get(&this->mDictionary.mTree, v6)) != 0i64 && v7 != (UFG::qBaseTreeRB *)8 )
  {
    v7->mNULL.mParent = *data;
  }
  else
  {
    v8 = UFG::qMalloc(0x30ui64, UFG::gGlobalNewName, 0i64);
    v9 = 0i64;
    if ( v8 )
      UFG::ContextData<UFG::DUIPopupMenuWindow *>::ContextData<UFG::DUIPopupMenuWindow *>(
        (UFG::ContextData<UFG::DUIPopupMenuWindow *> *)v8,
        key,
        (UFG::DUIPopupMenuWindow *const *)data);
    else
      v10 = 0i64;
    if ( v10 )
      v9 = (UFG::qBaseNodeRB *)(v10 + 8);
    UFG::qBaseTreeRB::Add(&this->mDictionary.mTree, v9);
  }
}

// File Line: 253
// RVA: 0x192F60
void __fastcall UFG::Command::~Command(UFG::Command *this)
{
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::Command,UFG::Command> *v4; // rcx
  UFG::qNode<UFG::Command,UFG::Command> *v5; // rax

  this->vfptr = (UFG::CommandVtbl *)&UFG::Command::`vftable;
  UFG::qString::~qString(&this->mUserType);
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(&this->mTags);
  mPrev = this->mTags.mNode.mPrev;
  mNext = this->mTags.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mTags.mNode.mPrev = &this->mTags.mNode;
  this->mTags.mNode.mNext = &this->mTags.mNode;
  UFG::qString::~qString(&this->mDisplayText);
  UFG::qString::~qString(&this->mName);
  v4 = this->mPrev;
  v5 = this->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->mPrev = &this->UFG::qNode<UFG::Command,UFG::Command>;
  this->mNext = &this->UFG::qNode<UFG::Command,UFG::Command>;
}

