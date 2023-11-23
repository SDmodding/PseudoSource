// File Line: 63
// RVA: 0x1C0C0
void __fastcall UFG::qBaseNodeRB::qBaseNodeRB(UFG::qBaseNodeRB *this, unsigned int uid)
{
  this->mParent = 0i64;
  this->mChild[0] = 0i64;
  this->mChild[1] = 0i64;
  this->mUID = uid;
}

// File Line: 68
// RVA: 0x3BF0
__int64 __fastcall BasicArrayImplementation<hkDataArrayImpl *>::getSize(
        BasicArrayImplementation<hkDataObjectImpl *> *this)
{
  return (unsigned int)this->m_data.m_size;
}

// File Line: 102
// RVA: 0x1E100
_BOOL8 __fastcall UFG::qBaseTreeRB::IsEmpty(UFG::qBaseTreeRB *this)
{
  return this->mCount == 0;
}

// File Line: 146
// RVA: 0x1ECBE0
void __fastcall UFG::qNodeRB<UFG::PropertyMetadata>::qNodeRB<UFG::PropertyMetadata>(
        UFG::qNodeRB<UFG::PropertyMetadata> *this,
        unsigned int uid)
{
  UFG::qBaseNodeRB::qBaseNodeRB(&this->mNode, uid);
}

// File Line: 173
// RVA: 0x289E0
void __fastcall UFG::qTreeRB<UFG::qMapNode32<void *>,UFG::qMapNode32<void *>,1>::~qTreeRB<UFG::qMapNode32<void *>,UFG::qMapNode32<void *>,1>(
        UFG::qTreeRB<UFG::qMapNode32<unsigned long>,UFG::qMapNode32<unsigned long>,1> *this)
{
  Render::SkinningCacheNode *Head; // rbx

  while ( this->mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)this, &Head->mNode);
    operator delete[](Head);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)this);
}

// File Line: 180
// RVA: 0x16EF50
UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *__fastcall UFG::qTreeRB<UFG::qFileMapLocation,UFG::qFileMapLocation,1>::Get(
        UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *this,
        unsigned int uid)
{
  UFG::qSharedStringData *p_mNULL; // r9
  UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *result; // rax
  bool i; // zf
  unsigned int mUID; // ecx
  UFG::qSharedStringData *j; // rcx

  if ( uid )
  {
    p_mNULL = (UFG::qSharedStringData *)&this->mTree.mNULL;
    result = this;
    for ( i = this == (UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *)&this->mTree.mNULL;
          !i;
          i = result == (UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *)p_mNULL )
    {
      mUID = result->mTree.mRoot.mUID;
      if ( result != this && mUID == uid )
      {
        for ( j = (UFG::qSharedStringData *)result->mTree.mRoot.mChild[0];
              j;
              j = (UFG::qSharedStringData *)j->mNode.mChild[0] )
        {
          if ( j->mNode.mUID != uid )
            break;
          result = (UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *)j;
        }
        return result;
      }
      if ( uid > mUID )
        result = (UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *)result->mTree.mRoot.mChild[1];
      else
        result = (UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *)result->mTree.mRoot.mChild[0];
    }
  }
  return 0i64;
}

// File Line: 184
// RVA: 0x5B7CB0
// attributes: thunk
void __fastcall UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(
        UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *this,
        UFG::qNodeRB<UEL::ParameterBindingEntry> *n)
{
  UFG::qBaseTreeRB::Add(&this->mTree, &n->mNode);
}

// File Line: 187
// RVA: 0x5BDED0
void __fastcall UFG::qTreeRB<UFG::UIScreenTextureManager::TexturePackReference,UFG::UIScreenTextureManager::TexturePackReference,1>::DeleteAll(
        UFG::qTreeRB<UFG::UIScreenTextureManager::TexturePackReference,UFG::UIScreenTextureManager::TexturePackReference,1> *this)
{
  Render::SkinningCacheNode *Head; // rbx
  Illusion::Buffer *mCachedBufferPtr; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rcx

  while ( this->mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)this, &Head->mNode);
    if ( Head )
    {
      mCachedBufferPtr = Head[3].mCachedBufferPtr;
      if ( mCachedBufferPtr )
        operator delete[](mCachedBufferPtr);
      Head[3].mCachedBufferPtr = 0i64;
      Head[3].mNode.mUID = 0i64;
      v4 = Head[3].mNode.mChild[1];
      if ( v4 )
        operator delete[](v4);
      Head[3].mNode.mChild[1] = 0i64;
      Head[3].mNode.mChild[0] = 0i64;
      UFG::DataStreamer::Handle::~Handle((UFG::DataStreamer::Handle *)&Head[2]);
      UFG::qString::~qString((UFG::qString *)&Head->mCachedBufferPtr);
      operator delete[](Head);
    }
  }
}

// File Line: 192
// RVA: 0x28180
// attributes: thunk
Render::SkinningCacheNode *__fastcall UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1>::GetHead(
        UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *this)
{
  return UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
}

// File Line: 194
// RVA: 0x28190
// attributes: thunk
UFG::qBaseTreeRB *__fastcall UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1>::GetNext(
        UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *this,
        UFG::qBaseNodeRB *x)
{
  return UFG::qBaseTreeRB::GetNext(&this->mTree, x);
}

// File Line: 195
// RVA: 0x172050
UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *__fastcall UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1>::GetPrev(
        UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *this,
        UFG::qNodeRB<UFG::qResourceData> *x)
{
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *v2; // r8
  UFG::qBaseNodeRB *p_mNULL; // r9
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *i; // rax
  UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *result; // rax
  UFG::qResourceData *v7; // rcx

  v2 = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)x->mNode.mChild[0];
  p_mNULL = &this->mTree.mNULL;
  if ( &this->mTree.mNULL == (UFG::qBaseNodeRB *)v2 )
  {
    result = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((unsigned __int64)x->mNode.mParent & 0xFFFFFFFFFFFFFFFEui64);
    if ( x == (UFG::qNodeRB<UFG::qResourceData> *)result->mTree.mRoot.mChild[0] )
    {
      while ( result != this )
      {
        v7 = (UFG::qResourceData *)result;
        result = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)((unsigned __int64)result->mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
        if ( v7 != (UFG::qResourceData *)result->mTree.mRoot.mChild[0] )
          return result;
      }
      return 0i64;
    }
  }
  else
  {
    for ( i = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)v2->mTree.mRoot.mChild[1];
          i != (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)p_mNULL;
          i = (UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *)i->mTree.mRoot.mChild[1] )
    {
      v2 = i;
    }
    return v2;
  }
  return result;
}

// File Line: 214
// RVA: 0x5C39C0
void __fastcall UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>(
        UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip> *this,
        unsigned int key,
        UFG::UIHKPlayerObjectiveMinimapBlip *val)
{
  UFG::UIHKPlayerObjectiveMinimapBlip *p_mValue; // rbx

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = key;
  p_mValue = &this->mValue;
  this->mValue.name.mUID = -1;
  UFG::qString::qString(&this->mValue.type);
  p_mValue->target.mPrev = &p_mValue->target;
  p_mValue->target.mNext = &p_mValue->target;
  p_mValue->target.m_pPointer = 0i64;
  UFG::UIHKPlayerObjectiveMinimapBlip::operator=(p_mValue, val);
}

// File Line: 232
// RVA: 0xE0160
void __fastcall UFG::qMap<Render::VerletCloth *>::Set(
        UFG::qMap<Render::VerletCloth *> *this,
        unsigned int key,
        Render::VerletCloth **value)
{
  UFG::qBaseTreeRB *v6; // rax
  char *v7; // rax
  UFG::qBaseNodeRB *v8; // rbx

  if ( key && (v6 = UFG::qBaseTreeRB::Get(&this->mTree.mTree, key)) != 0i64 )
  {
    v6->mNULL.mParent = (UFG::qBaseNodeRB *)*value;
  }
  else
  {
    v7 = UFG::qMalloc(0x28ui64, "qMap::qMapNode32", 0i64);
    v8 = (UFG::qBaseNodeRB *)v7;
    if ( v7 )
    {
      *(_QWORD *)v7 = 0i64;
      *((_QWORD *)v7 + 1) = 0i64;
      *((_QWORD *)v7 + 2) = 0i64;
      *((_DWORD *)v7 + 6) = key;
      *((_QWORD *)v7 + 4) = *value;
    }
    else
    {
      v8 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&this->mTree.mTree, v8);
    v8[1].mParent = (UFG::qBaseNodeRB *)*value;
  }
}

