// File Line: 78
// RVA: 0x1BEA0
void __fastcall Render::PersistentSkinningCache::PersistentSkinningCache(Render::PersistentSkinningCache *this)
{
  this->mCachedVertexDataTree.mTree.mRoot.mParent = 0i64;
  this->mCachedVertexDataTree.mTree.mRoot.8 = 0ui64;
  this->mCachedVertexDataTree.mTree.mNULL.mParent = 0i64;
  this->mCachedVertexDataTree.mTree.mNULL.8 = 0ui64;
  this->mCachedVertexDataTree.mTree.mNULL.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&this->mCachedVertexDataTree.mTree.mNULL | (__int64)this->mCachedVertexDataTree.mTree.mNULL.mParent & 1);
  this->mCachedVertexDataTree.mTree.mNULL.mChild[0] = &this->mCachedVertexDataTree.mTree.mNULL;
  this->mCachedVertexDataTree.mTree.mNULL.mChild[1] = &this->mCachedVertexDataTree.mTree.mNULL;
  this->mCachedVertexDataTree.mTree.mNULL.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)this->mCachedVertexDataTree.mTree.mNULL.mParent & ~1ui64);
  this->mCachedVertexDataTree.mTree.mNULL.mUID = 0i64;
  this->mCachedVertexDataTree.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&this->mCachedVertexDataTree.mTree.mNULL | (__int64)this->mCachedVertexDataTree.mTree.mRoot.mParent & 1);
  this->mCachedVertexDataTree.mTree.mRoot.mChild[0] = &this->mCachedVertexDataTree.mTree.mNULL;
  this->mCachedVertexDataTree.mTree.mRoot.mChild[1] = &this->mCachedVertexDataTree.mTree.mNULL;
  this->mCachedVertexDataTree.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)this->mCachedVertexDataTree.mTree.mRoot.mParent & ~1ui64);
  this->mCachedVertexDataTree.mTree.mRoot.mUID = -1i64;
  this->mCachedVertexDataTree.mTree.mCount = 0;
  this->mCachedVertexDataList.mNode.mPrev = &this->mCachedVertexDataList.mNode;
  this->mCachedVertexDataList.mNode.mNext = &this->mCachedVertexDataList.mNode;
  UFG::qMemoryPool::qMemoryPool(&this->mCachedVertexDataPool);
}

// File Line: 79
// RVA: 0x1C1B0
void __fastcall Render::PersistentSkinningCache::~PersistentSkinningCache(Render::PersistentSkinningCache *this)
{
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *mPrev; // rcx
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *mNext; // rax
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *v4; // rcx
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *v5; // rax
  UFG::qMemoryPool *p_mCachedVertexDataPool; // [rsp+48h] [rbp+10h]

  p_mCachedVertexDataPool = &this->mCachedVertexDataPool;
  mPrev = this->mCachedVertexDataPool.mPrev;
  mNext = p_mCachedVertexDataPool->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mCachedVertexDataPool->mPrev = p_mCachedVertexDataPool;
  p_mCachedVertexDataPool->mNext = p_mCachedVertexDataPool;
  UFG::qList<PoseCacheNode,PoseCacheNode,1,0>::DeleteNodes(&this->mCachedVertexDataList);
  v4 = this->mCachedVertexDataList.mNode.mPrev;
  v5 = this->mCachedVertexDataList.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->mCachedVertexDataList.mNode.mPrev = &this->mCachedVertexDataList.mNode;
  this->mCachedVertexDataList.mNode.mNext = &this->mCachedVertexDataList.mNode;
  UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1>::DeleteAll(&this->mCachedVertexDataTree);
  this->mCachedVertexDataTree.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&this->mCachedVertexDataTree.mTree.mNULL | (__int64)this->mCachedVertexDataTree.mTree.mRoot.mParent & 1);
  this->mCachedVertexDataTree.mTree.mRoot.mChild[0] = &this->mCachedVertexDataTree.mTree.mNULL;
  this->mCachedVertexDataTree.mTree.mRoot.mChild[1] = &this->mCachedVertexDataTree.mTree.mNULL;
  this->mCachedVertexDataTree.mTree.mCount = 0;
}

