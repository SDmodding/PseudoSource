// File Line: 185
// RVA: 0x1C0F0
void __fastcall UFG::qTreeRB64<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode,1>::~qTreeRB64<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode,1>(UFG::qTreeRB64<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode,1> *this)
{
  UFG::qTreeRB64<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode,1> *v1; // rbx

  v1 = this;
  UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1>::DeleteAll(this);
  v1->mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&v1->mTree.mNULL | (_QWORD)v1->mTree.mRoot.mParent & 1);
  v1->mTree.mRoot.mChild[0] = &v1->mTree.mNULL;
  v1->mTree.mRoot.mChild[1] = &v1->mTree.mNULL;
  v1->mTree.mCount = 0;
}

// File Line: 192
// RVA: 0x2971D0
Render::PersistentSkinningCache *__fastcall Render::PersistentSkinningCache::Find(Render::PersistentSkinningCache *this, unsigned __int64 uid)
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
void __fastcall UFG::qTreeRB<UFG::qHotswappedFile,UFG::qHotswappedFile,1>::DeleteAll(UFG::qTreeRB<UFG::tPatchPoint,UFG::tPatchPoint,1> *this)
{
  UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *v1; // rsi
  Render::SkinningCacheNode *v2; // rdi
  Illusion::Buffer **v3; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v5; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v6; // rax

  v1 = (UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)this;
  if ( this->mTree.mCount )
  {
    do
    {
      v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(v1);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v1->mTree, &v2->mNode);
      if ( v2 )
      {
        v3 = &v2->mCachedBufferPtr;
        v4 = v2[1].mNode.mChild[1];
        if ( v4 != (UFG::qBaseNodeVariableRB<unsigned __int64> *)UFG::qString::sEmptyString )
        {
          if ( v4 )
            UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v4);
        }
        LODWORD(v2[1].mNode.mChild[0]) = 0;
        v5 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)*v3;
        v6 = v2[1].mNode.mParent;
        v5->mChild[0] = v6;
        v6->mParent = v5;
        *v3 = (Illusion::Buffer *)v3;
        v2[1].mNode.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v2->mCachedBufferPtr;
        UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v2);
      }
    }
    while ( v1->mTree.mCount );
  }
}

// File Line: 202
// RVA: 0x2C3100
Render::SkinningCacheNode *__fastcall UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *this)
{
  Render::SkinningCacheNode *v1; // rdx
  Render::SkinningCacheNode *v2; // rcx
  Render::SkinningCacheNode *i; // rax
  Render::SkinningCacheNode *result; // rax

  v1 = (Render::SkinningCacheNode *)this->mTree.mRoot.mChild[0];
  v2 = (Render::SkinningCacheNode *)&this->mTree.mNULL;
  for ( i = (Render::SkinningCacheNode *)v1->mNode.mChild[0]; i != v2; i = (Render::SkinningCacheNode *)i->mNode.mChild[0] )
    v1 = i;
  result = 0i64;
  if ( v1 != v2 )
    result = v1;
  return result;
}

