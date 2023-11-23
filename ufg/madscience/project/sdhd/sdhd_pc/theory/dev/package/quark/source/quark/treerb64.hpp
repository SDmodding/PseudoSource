// File Line: 185
// RVA: 0x1C0F0
void __fastcall UFG::qTreeRB64<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode,1>::~qTreeRB64<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode,1>(
        UFG::qTreeRB64<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode,1> *this)
{
  UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1>::DeleteAll(this);
  this->mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&this->mTree.mNULL | (__int64)this->mTree.mRoot.mParent & 1);
  this->mTree.mRoot.mChild[0] = &this->mTree.mNULL;
  this->mTree.mRoot.mChild[1] = &this->mTree.mNULL;
  this->mTree.mCount = 0;
}

// File Line: 192
// RVA: 0x2971D0
Render::PersistentSkinningCache *__fastcall Render::PersistentSkinningCache::Find(
        Render::PersistentSkinningCache *this,
        unsigned __int64 uid)
{
  Render::PersistentSkinningCache *result; // rax
  bool i; // zf
  Render::PersistentSkinningCacheNode *j; // rcx

  if ( uid )
  {
    result = this;
    for ( i = this == (Render::PersistentSkinningCache *)&this->mCachedVertexDataTree.mTree.mNULL;
          !i;
          i = result == (Render::PersistentSkinningCache *)&this->mCachedVertexDataTree.mTree.mNULL )
    {
      if ( result != this && result->mCachedVertexDataTree.mTree.mRoot.mUID == uid )
      {
        for ( j = (Render::PersistentSkinningCacheNode *)result->mCachedVertexDataTree.mTree.mRoot.mChild[0];
              j;
              j = (Render::PersistentSkinningCacheNode *)j->mNode.mChild[0] )
        {
          if ( j->mNode.mUID != uid )
            break;
          result = (Render::PersistentSkinningCache *)j;
        }
        return result;
      }
      if ( uid > result->mCachedVertexDataTree.mTree.mRoot.mUID )
        result = (Render::PersistentSkinningCache *)result->mCachedVertexDataTree.mTree.mRoot.mChild[1];
      else
        result = (Render::PersistentSkinningCache *)result->mCachedVertexDataTree.mTree.mRoot.mChild[0];
    }
  }
  return 0i64;
}

// File Line: 197
// RVA: 0x16BD00
void __fastcall UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1>::DeleteAll(
        UFG::qTreeRB<UFG::tPatchPoint,UFG::tPatchPoint,1> *this)
{
  Render::SkinningCacheNode *Head; // rdi
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *mParent; // rax

  while ( this->mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove((UFG::qBaseTreeVariableRB<unsigned __int64> *)this, &Head->mNode);
    if ( Head )
    {
      p_mCachedBufferPtr = &Head->mCachedBufferPtr;
      v4 = Head[1].mNode.mChild[1];
      if ( v4 != (UFG::qBaseNodeVariableRB<unsigned __int64> *)UFG::qString::sEmptyString )
      {
        if ( v4 )
          UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v4);
      }
      LODWORD(Head[1].mNode.mChild[0]) = 0;
      v5 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)*p_mCachedBufferPtr;
      mParent = Head[1].mNode.mParent;
      v5->mChild[0] = mParent;
      mParent->mParent = v5;
      *p_mCachedBufferPtr = (Illusion::Buffer *)p_mCachedBufferPtr;
      Head[1].mNode.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&Head->mCachedBufferPtr;
      UFG::qMemoryPool::Free(UFG::gMainMemoryPool, Head);
    }
  }
}

// File Line: 202
// RVA: 0x2C3100
Render::SkinningCacheNode *__fastcall UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(
        UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *this)
{
  UFG::qBaseNodeVariableRB<unsigned __int64> *v1; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNULL; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *i; // rax
  Render::SkinningCacheNode *result; // rax

  v1 = this->mTree.mRoot.mChild[0];
  p_mNULL = &this->mTree.mNULL;
  for ( i = v1->mChild[0]; i != p_mNULL; i = i->mChild[0] )
    v1 = i;
  result = 0i64;
  if ( v1 != p_mNULL )
    return (Render::SkinningCacheNode *)v1;
  return result;
}

