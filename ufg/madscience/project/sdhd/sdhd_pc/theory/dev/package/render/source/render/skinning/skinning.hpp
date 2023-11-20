// File Line: 78
// RVA: 0x1BEA0
void __fastcall Render::PersistentSkinningCache::PersistentSkinningCache(Render::PersistentSkinningCache *this)
{
  Render::PersistentSkinningCache *v1; // rbx
  unsigned __int64 v2; // rdx
  UFG::qList<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode,1,0> *v3; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->mCachedVertexDataTree.mTree.mRoot.mParent = 0i64;
  this->mCachedVertexDataTree.mTree.mRoot.8 = 0ui64;
  v2 = (unsigned __int64)&this->mCachedVertexDataTree.mTree.mNULL;
  *(_QWORD *)v2 = 0i64;
  *(_QWORD *)(v2 + 8) = 0i64;
  *(_QWORD *)(v2 + 16) = 0i64;
  *(_QWORD *)v2 = v2 | *(_DWORD *)v2 & 1;
  v1->mCachedVertexDataTree.mTree.mNULL.mChild[0] = &v1->mCachedVertexDataTree.mTree.mNULL;
  v1->mCachedVertexDataTree.mTree.mNULL.mChild[1] = &v1->mCachedVertexDataTree.mTree.mNULL;
  *(_QWORD *)v2 &= 0xFFFFFFFFFFFFFFFEui64;
  this->mCachedVertexDataTree.mTree.mNULL.mUID = 0i64;
  v1->mCachedVertexDataTree.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&v1->mCachedVertexDataTree.mTree.mNULL | (_QWORD)v1->mCachedVertexDataTree.mTree.mRoot.mParent & 1);
  v1->mCachedVertexDataTree.mTree.mRoot.mChild[0] = &v1->mCachedVertexDataTree.mTree.mNULL;
  v1->mCachedVertexDataTree.mTree.mRoot.mChild[1] = &v1->mCachedVertexDataTree.mTree.mNULL;
  v1->mCachedVertexDataTree.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((_QWORD)v1->mCachedVertexDataTree.mTree.mRoot.mParent & 0xFFFFFFFFFFFFFFFEui64);
  this->mCachedVertexDataTree.mTree.mRoot.mUID = -1i64;
  this->mCachedVertexDataTree.mTree.mCount = 0;
  v3 = &this->mCachedVertexDataList;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  UFG::qMemoryPool::qMemoryPool(&this->mCachedVertexDataPool);
}

// File Line: 79
// RVA: 0x1C1B0
void __fastcall Render::PersistentSkinningCache::~PersistentSkinningCache(Render::PersistentSkinningCache *this)
{
  Render::PersistentSkinningCache *v1; // rdi
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *v2; // rcx
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *v3; // rax
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *v4; // rcx
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *v5; // rax
  UFG::qMemoryPool *v6; // [rsp+48h] [rbp+10h]

  v1 = this;
  v6 = &this->mCachedVertexDataPool;
  v2 = this->mCachedVertexDataPool.mPrev;
  v3 = v6->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v6->mPrev = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&v6->mPrev;
  UFG::qList<PoseCacheNode,PoseCacheNode,1,0>::DeleteNodes(&v1->mCachedVertexDataList);
  v4 = v1->mCachedVertexDataList.mNode.mPrev;
  v5 = v1->mCachedVertexDataList.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mCachedVertexDataList.mNode.mPrev = &v1->mCachedVertexDataList.mNode;
  v1->mCachedVertexDataList.mNode.mNext = &v1->mCachedVertexDataList.mNode;
  UFG::qTreeRB64<PoseCacheNode,PoseCacheNode,1>::DeleteAll(&v1->mCachedVertexDataTree);
  v1->mCachedVertexDataTree.mTree.mRoot.mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((unsigned __int64)&v1->mCachedVertexDataTree.mTree.mNULL | (_QWORD)v1->mCachedVertexDataTree.mTree.mRoot.mParent & 1);
  v1->mCachedVertexDataTree.mTree.mRoot.mChild[0] = &v1->mCachedVertexDataTree.mTree.mNULL;
  v1->mCachedVertexDataTree.mTree.mRoot.mChild[1] = &v1->mCachedVertexDataTree.mTree.mNULL;
  v1->mCachedVertexDataTree.mTree.mCount = 0;
}

