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
__int64 __fastcall BasicArrayImplementation<hkDataArrayImpl *>::getSize(BasicArrayImplementation<hkDataObjectImpl *> *this)
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
void __fastcall UFG::qNodeRB<UFG::PropertyMetadata>::qNodeRB<UFG::PropertyMetadata>(UFG::qNodeRB<UFG::PropertyMetadata> *this, unsigned int uid)
{
  UFG::qBaseNodeRB::qBaseNodeRB(&this->mNode, uid);
}

// File Line: 173
// RVA: 0x289E0
void __fastcall UFG::qTreeRB<UFG::qMapNode32<void *>,UFG::qMapNode32<void *>,1>::~qTreeRB<UFG::qMapNode32<void *>,UFG::qMapNode32<void *>,1>(UFG::qTreeRB<UFG::qMapNode32<unsigned long>,UFG::qMapNode32<unsigned long>,1> *this)
{
  Render::Skinning *v1; // rdi
  Render::SkinningCacheNode *v2; // rbx

  v1 = (Render::Skinning *)this;
  if ( this->mTree.mCount )
  {
    do
    {
      v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&v1->mSkinnedVertexBuffers);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v1->mSkinnedVertexBuffers.mTree, &v2->mNode);
      operator delete[](v2);
    }
    while ( v1->mSkinnedVertexBuffers.mTree.mCount );
  }
  UFG::qBaseTreeRB::~qBaseTreeRB(v1);
}

// File Line: 180
// RVA: 0x16EF50
UFG::qSharedStringData *__fastcall UFG::qTreeRB<UFG::qFileMapLocation,UFG::qFileMapLocation,1>::Get(UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *this, unsigned int uid)
{
  UFG::qSharedStringData *v2; // r8
  UFG::qSharedStringData *v3; // r9
  UFG::qSharedStringData *result; // rax
  bool i; // zf
  unsigned int v6; // ecx
  UFG::qSharedStringData *j; // rcx

  v2 = (UFG::qSharedStringData *)this;
  if ( uid )
  {
    v3 = (UFG::qSharedStringData *)&this->mTree.mNULL;
    result = (UFG::qSharedStringData *)this;
    for ( i = this == (UFG::qTreeRB<UFG::qSharedStringData,UFG::qSharedStringData,0> *)&this->mTree.mNULL;
          !i;
          i = result == v3 )
    {
      v6 = result->mNode.mUID;
      if ( result != v2 && v6 == uid )
      {
        for ( j = (UFG::qSharedStringData *)result->mNode.mChild[0]; j; j = (UFG::qSharedStringData *)j->mNode.mChild[0] )
        {
          if ( j->mNode.mUID != uid )
            break;
          result = j;
        }
        return result;
      }
      if ( uid > v6 )
        result = (UFG::qSharedStringData *)result->mNode.mChild[1];
      else
        result = (UFG::qSharedStringData *)result->mNode.mChild[0];
    }
  }
  return 0i64;
}

// File Line: 184
// RVA: 0x5B7CB0
void __fastcall UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::Add(UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *this, UFG::qNodeRB<UEL::ParameterBindingEntry> *n)
{
  UFG::qBaseTreeRB::Add(&this->mTree, &n->mNode);
}

// File Line: 187
// RVA: 0x5BDED0
void __fastcall UFG::qTreeRB<UFG::UIScreenTextureManager::TexturePackReference,UFG::UIScreenTextureManager::TexturePackReference,1>::DeleteAll(UFG::qTreeRB<UFG::UIScreenTextureManager::TexturePackReference,UFG::UIScreenTextureManager::TexturePackReference,1> *this)
{
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *v1; // rdi
  Render::SkinningCacheNode *v2; // rbx
  Illusion::Buffer *v3; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rcx

  v1 = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this;
  if ( this->mTree.mCount )
  {
    do
    {
      v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(v1);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v1->mTree, &v2->mNode);
      if ( v2 )
      {
        v3 = v2[3].mCachedBufferPtr;
        if ( v3 )
          operator delete[](v3);
        v2[3].mCachedBufferPtr = 0i64;
        v2[3].mNode.mUID = 0i64;
        v4 = v2[3].mNode.mChild[1];
        if ( v4 )
          operator delete[](v4);
        v2[3].mNode.mChild[1] = 0i64;
        v2[3].mNode.mChild[0] = 0i64;
        UFG::DataStreamer::Handle::~Handle((UFG::DataStreamer::Handle *)&v2[2]);
        UFG::qString::~qString((UFG::qString *)&v2->mCachedBufferPtr);
        operator delete[](v2);
      }
    }
    while ( v1->mTree.mCount );
  }
}

// File Line: 192
// RVA: 0x28180
Render::SkinningCacheNode *__fastcall UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1>::GetHead(UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *this)
{
  return UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
}

// File Line: 194
// RVA: 0x28190
UFG::qBaseTreeRB *__fastcall UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1>::GetNext(UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *this, UFG::qNodeRB<UFG::qResourceData> *x)
{
  return UFG::qBaseTreeRB::GetNext(&this->mTree, &x->mNode);
}

// File Line: 195
// RVA: 0x172050
UFG::qResourceData *__fastcall UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1>::GetPrev(UFG::qTreeRB<UFG::qResourceData,UFG::qResourceData,1> *this, UFG::qNodeRB<UFG::qResourceData> *x)
{
  UFG::qResourceData *v2; // r8
  UFG::qBaseNodeRB *v3; // r9
  UFG::qResourceData *v4; // r10
  UFG::qResourceData *i; // rax
  UFG::qResourceData *result; // rax
  UFG::qResourceData *v7; // rcx

  v2 = (UFG::qResourceData *)x->mNode.mChild[0];
  v3 = &this->mTree.mNULL;
  v4 = (UFG::qResourceData *)this;
  if ( &this->mTree.mNULL == (UFG::qBaseNodeRB *)v2 )
  {
    result = (UFG::qResourceData *)((_QWORD)x->mNode.mParent & 0xFFFFFFFFFFFFFFFEui64);
    if ( x == (UFG::qNodeRB<UFG::qResourceData> *)result->mNode.mChild[0] )
    {
      while ( result != v4 )
      {
        v7 = result;
        result = (UFG::qResourceData *)((_QWORD)result->mNode.mParent & 0xFFFFFFFFFFFFFFFEui64);
        if ( v7 != (UFG::qResourceData *)result->mNode.mChild[0] )
          return result;
      }
      result = 0i64;
    }
  }
  else
  {
    for ( i = (UFG::qResourceData *)v2->mNode.mChild[1];
          i != (UFG::qResourceData *)v3;
          i = (UFG::qResourceData *)i->mNode.mChild[1] )
    {
      v2 = i;
    }
    result = v2;
  }
  return result;
}

// File Line: 214
// RVA: 0x5C39C0
void __fastcall UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip>(UFG::qMapNode32<UFG::UIHKPlayerObjectiveMinimapBlip> *this, unsigned int key, UFG::UIHKPlayerObjectiveMinimapBlip *val)
{
  UFG::UIHKPlayerObjectiveMinimapBlip *v3; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::HudComponent> *v4; // ST28_8
  UFG::UIHKPlayerObjectiveMinimapBlip *v5; // [rsp+68h] [rbp+20h]

  v3 = val;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = key;
  v5 = &this->mValue;
  v5->name.mUID = -1;
  UFG::qString::qString(&this->mValue.type);
  v4 = &v5->target;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v5->target.m_pPointer = 0i64;
  UFG::UIHKPlayerObjectiveMinimapBlip::operator=(v5, v3);
}

// File Line: 232
// RVA: 0xE0160
void __fastcall UFG::qMap<Render::VerletCloth *>::Set(UFG::qMap<Render::VerletCloth *> *this, unsigned int key, Render::VerletCloth *const *value)
{
  Render::VerletCloth *const *v3; // rdi
  unsigned int v4; // esi
  UFG::qMap<Render::VerletCloth *> *v5; // rbp
  UFG::qBaseTreeRB *v6; // rax
  char *v7; // rax
  UFG::qBaseNodeRB *v8; // rbx

  v3 = value;
  v4 = key;
  v5 = this;
  if ( key && (v6 = UFG::qBaseTreeRB::Get(&this->mTree.mTree, key)) != 0i64 )
  {
    v6->mNULL.mParent = (UFG::qBaseNodeRB *)*v3;
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
      *((_DWORD *)v7 + 6) = v4;
      *((Render::VerletCloth **)v7 + 4) = *v3;
    }
    else
    {
      v8 = 0i64;
    }
    UFG::qBaseTreeRB::Add(&v5->mTree.mTree, v8);
    v8[1].mParent = (UFG::qBaseNodeRB *)*v3;
  }
}

