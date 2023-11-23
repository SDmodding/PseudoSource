// File Line: 81
// RVA: 0x1814C0
void __fastcall UFG::intrusive_multi_rbtree_base::insert_fixup(
        UFG::intrusive_multi_rbtree_base *this,
        UFG::intrusive_multi_rbtree_base::node_base *node)
{
  UFG::intrusive_multi_rbtree_base::node_base *v2; // r13
  unsigned __int64 v4; // rdi
  __int64 *i; // rsi
  __int64 v6; // rbp
  unsigned __int64 v7; // rax
  int v8; // r14d
  __int64 v9; // r15
  __int64 v10; // rcx
  unsigned __int64 v11; // r11
  __int64 v12; // r9
  __int64 v13; // rbx
  __int64 *v14; // r8
  __int64 v15; // rdx
  __int64 v16; // r8
  __int64 v17; // r11
  unsigned __int64 v18; // r10
  unsigned __int64 v19; // r11
  __int64 v20; // r10
  __int64 *v21; // r8
  __int64 v22; // rbx
  __int64 v23; // rdx
  __int64 v24; // r8

  v2 = node;
  v4 = (unsigned __int64)node->mParent & 0xFFFFFFFFFFFFFFFCui64;
  for ( i = (__int64 *)(v4 + 32); (*(_BYTE *)(v4 + 32) & 1) != 0; i = (__int64 *)(v4 + 32) )
  {
    v6 = ((unsigned __int64)*i >> 1) & 1;
    v7 = *i & 0xFFFFFFFFFFFFFFFCui64;
    v8 = 1 - v6;
    v9 = 8i64 * (1 - (int)v6);
    v10 = *(_QWORD *)(v9 + v7);
    if ( (*(_BYTE *)(v10 + 32) & 1) != 0 )
    {
      *i &= ~1ui64;
      *(_QWORD *)(v10 + 32) &= ~1ui64;
      *(_QWORD *)(v7 + 32) |= 1ui64;
      v2 = (UFG::intrusive_multi_rbtree_base::node_base *)v7;
      v4 = *(_QWORD *)(v7 + 32) & 0xFFFFFFFFFFFFFFFCui64;
    }
    else
    {
      if ( v2 == *(UFG::intrusive_multi_rbtree_base::node_base **)(v9 + v4) )
      {
        v11 = *(unsigned int *)i;
        v12 = *i;
        v13 = *(_QWORD *)(v4 + 8i64 * v8);
        v14 = (__int64 *)(v4 + 8i64 * v8);
        v15 = *(_QWORD *)(v13 + 8i64 * (int)v6);
        *v14 = v15;
        *(_QWORD *)(v15 + 32) &= 3ui64;
        *(_QWORD *)(v15 + 32) |= v4 & 0xFFFFFFFFFFFFFFFCui64;
        v16 = *v14;
        *(_QWORD *)(v16 + 32) &= ~2ui64;
        *(_QWORD *)(v16 + 32) |= 2 * v8;
        *(_QWORD *)(v13 + 32) &= 1ui64;
        v17 = (v11 >> 1) & 1;
        v2 = (UFG::intrusive_multi_rbtree_base::node_base *)v4;
        *(_QWORD *)(v13 + 32) |= v12 & 0xFFFFFFFFFFFFFFFCui64 | (2 * (int)v17);
        *(_QWORD *)((*i & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (int)v17) = v13;
        *(_QWORD *)(v13 + 8i64 * (int)v6) = v4;
        *i &= 1ui64;
        *i |= v13 & 0xFFFFFFFFFFFFFFFCui64 | (2 * (int)v6);
        v4 = *i & 0xFFFFFFFFFFFFFFFCui64;
      }
      *(_QWORD *)(v4 + 32) &= ~1ui64;
      *(_QWORD *)(v7 + 32) |= 1ui64;
      v18 = *(_QWORD *)(v7 + 32);
      v19 = v18 & 0xFFFFFFFFFFFFFFFCui64;
      v20 = (v18 >> 1) & 1;
      v21 = (__int64 *)(v7 + 8i64 * (int)v6);
      v22 = *v21;
      v23 = *(_QWORD *)(v9 + *v21);
      *v21 = v23;
      *(_QWORD *)(v23 + 32) &= 3ui64;
      *(_QWORD *)(v23 + 32) |= v7 & 0xFFFFFFFFFFFFFFFCui64;
      v24 = *v21;
      *(_QWORD *)(v24 + 32) &= ~2ui64;
      *(_QWORD *)(v24 + 32) |= 2 * (int)v6;
      *(_QWORD *)(v22 + 32) &= 1ui64;
      *(_QWORD *)(v22 + 32) |= v19 | (2 * (int)v20);
      *(_QWORD *)((*(_QWORD *)(v7 + 32) & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (int)v20) = v22;
      *(_QWORD *)(v9 + v22) = v7;
      *(_QWORD *)(v7 + 32) &= 1ui64;
      *(_QWORD *)(v7 + 32) |= v22 & 0xFFFFFFFFFFFFFFFCui64 | (2 * v8);
    }
  }
  this->mHead.mChildren[0]->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)this->mHead.mChildren[0]->mParent & ~1ui64);
}

// File Line: 110
// RVA: 0x180D00
void __fastcall UFG::intrusive_multi_rbtree_base::erase_fixup(
        UFG::intrusive_multi_rbtree_base *this,
        unsigned __int64 node)
{
  unsigned __int64 v3; // rdx
  __int64 v4; // rbp
  int v5; // r14d
  unsigned __int64 v6; // r15
  unsigned __int64 v7; // rsi
  unsigned __int64 v8; // r10
  unsigned __int64 v9; // rbx
  __int64 v10; // rcx
  unsigned __int64 v11; // r11
  UFG::intrusive_multi_rbtree_base::node_base **v12; // r8
  unsigned __int64 *v13; // r9
  __int64 v14; // r10
  UFG::intrusive_multi_rbtree_base::node_base *v15; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v16; // r8
  UFG::intrusive_multi_rbtree_base::node_base **v17; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v18; // rdi
  unsigned __int64 v19; // rbx
  UFG::intrusive_multi_rbtree_base::node_base *v20; // r11
  UFG::intrusive_multi_rbtree_base::node_base **v21; // r8
  UFG::intrusive_multi_rbtree_base::node_base *v22; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v23; // r8
  int v24; // r10d
  unsigned __int64 v25; // rbx
  unsigned __int64 *v26; // r8
  int v27; // r11d
  unsigned __int64 v28; // r9
  unsigned __int64 *v29; // r10
  unsigned __int64 v30; // rcx
  unsigned __int64 v31; // r8

  if ( (*(_BYTE *)(node + 32) & 1) != 0 )
  {
    *(_QWORD *)(node + 32) &= ~1ui64;
  }
  else
  {
    do
    {
      if ( (UFG::intrusive_multi_rbtree_base::node_base *)node == this->mHead.mChildren[0] )
        break;
      v3 = *(_QWORD *)(node + 32);
      v4 = (v3 >> 1) & 1;
      node = v3 & 0xFFFFFFFFFFFFFFFCui64;
      v5 = 1 - v4;
      v6 = 8i64 * (1 - (int)v4);
      v7 = *(_QWORD *)(v6 + node);
      if ( (*(_BYTE *)(v7 + 32) & 1) != 0 )
      {
        *(_QWORD *)(v7 + 32) &= ~1ui64;
        *(_QWORD *)(node + 32) |= 1ui64;
        v8 = *(_QWORD *)(node + 32);
        v9 = v8 & 0xFFFFFFFFFFFFFFFCui64;
        v10 = 8i64 * (int)v4;
        v7 = *(_QWORD *)(v10 + v7);
        v11 = *(_QWORD *)(node + 8i64 * v5);
        v12 = (UFG::intrusive_multi_rbtree_base::node_base **)(node + 8i64 * v5);
        v13 = (unsigned __int64 *)(v10 + v11);
        v14 = (v8 >> 1) & 1;
        v15 = *(UFG::intrusive_multi_rbtree_base::node_base **)(v10 + v11);
        *v12 = v15;
        v15->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v15->mParent & 3);
        v15->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v15->mParent | node & 0xFFFFFFFFFFFFFFFCui64);
        v16 = *v12;
        v16->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v16->mParent & ~2ui64);
        v16->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((__int64)v16->mParent | (2 * v5));
        *(_QWORD *)(v11 + 32) &= 1ui64;
        *(_QWORD *)(v11 + 32) |= v9 & 0xFFFFFFFFFFFFFFFCui64 | (2 * (int)v14);
        *(_QWORD *)((*(_QWORD *)(node + 32) & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (int)v14) = v11;
        *v13 = node;
        *(_QWORD *)(node + 32) &= 1ui64;
        *(_QWORD *)(node + 32) |= v11 & 0xFFFFFFFFFFFFFFFCui64 | (2 * (int)v4);
      }
      if ( (*(_BYTE *)(*(_QWORD *)v7 + 32i64) & 1) != 0 || (*(_BYTE *)(*(_QWORD *)(v7 + 8) + 32i64) & 1) != 0 )
      {
        if ( (*(_BYTE *)(*(_QWORD *)(v6 + v7) + 32i64) & 1) == 0 )
        {
          v17 = (UFG::intrusive_multi_rbtree_base::node_base **)(v7 + 8i64 * (int)v4);
          (*v17)->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)(*v17)->mParent & ~1ui64);
          *(_QWORD *)(v7 + 32) |= 1ui64;
          v18 = *v17;
          v19 = *(_QWORD *)(v7 + 32);
          v20 = *v17;
          v21 = v17;
          v22 = (*v17)->mChildren[v6 / 8];
          *v21 = v22;
          v22->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v22->mParent & 3);
          v22->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v22->mParent | v7 & 0xFFFFFFFFFFFFFFFCui64);
          v23 = *v21;
          v23->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v23->mParent & ~2ui64);
          v24 = (v19 >> 1) & 1;
          v23->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((__int64)v23->mParent | (2 * (int)v4));
          v20->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v20->mParent & 1);
          v20->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((unsigned __int64)v20->mParent | v19 & 0xFFFFFFFFFFFFFFFCui64 | (2 * v24));
          *(_QWORD *)((*(_QWORD *)(v7 + 32) & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * v24) = v20;
          v20->mChildren[v6 / 8] = (UFG::intrusive_multi_rbtree_base::node_base *)v7;
          *(_QWORD *)(v7 + 32) &= 1ui64;
          *(_QWORD *)(v7 + 32) |= (unsigned __int64)v20 & 0xFFFFFFFFFFFFFFFCui64 | (2 * v5);
          v7 = (unsigned __int64)v18;
        }
        *(_QWORD *)(v7 + 32) ^= (*(_DWORD *)(v7 + 32) ^ *(_DWORD *)(node + 32)) & 1;
        *(_QWORD *)(node + 32) &= ~1ui64;
        *(_QWORD *)(*(_QWORD *)(v6 + v7) + 32i64) &= ~1ui64;
        v25 = *(_QWORD *)(node + 8i64 * v5);
        v26 = (unsigned __int64 *)(node + 8i64 * v5);
        v27 = (*(_DWORD *)(node + 32) >> 1) & 1;
        v28 = *(_QWORD *)(node + 32) & 0xFFFFFFFFFFFFFFFCui64;
        v29 = (unsigned __int64 *)(v25 + 8i64 * (int)v4);
        v30 = *v29;
        *v26 = *v29;
        *(_QWORD *)(v30 + 32) &= 3ui64;
        *(_QWORD *)(v30 + 32) |= node & 0xFFFFFFFFFFFFFFFCui64;
        v31 = *v26;
        *(_QWORD *)(v31 + 32) &= ~2ui64;
        *(_QWORD *)(v31 + 32) |= 2 * v5;
        *(_QWORD *)(v25 + 32) &= 1ui64;
        *(_QWORD *)(v25 + 32) |= v28 | (2 * v27);
        *(_QWORD *)((*(_QWORD *)(node + 32) & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * v27) = v25;
        *v29 = node;
        *(_QWORD *)(node + 32) &= 1ui64;
        *(_QWORD *)(node + 32) |= v25 & 0xFFFFFFFFFFFFFFFCui64 | (2 * (int)v4);
        node = (unsigned __int64)this->mHead.mChildren[0];
      }
      else
      {
        *(_QWORD *)(v7 + 32) |= 1ui64;
      }
    }
    while ( (*(_BYTE *)(node + 32) & 1) == 0 );
    *(_QWORD *)(node + 32) &= ~1ui64;
  }
}

// File Line: 181
// RVA: 0x160B20
void __fastcall UFG::allocator::allocator(UFG::allocator *this)
{
  this->mSystemPages.mNode.mPrev = &this->mSystemPages.mNode;
  this->mSystemPages.mNode.mNext = &this->mSystemPages.mNode;
  this->mSmallBlockSystemPages.mNode.mPrev = &this->mSmallBlockSystemPages.mNode;
  this->mSmallBlockSystemPages.mNode.mNext = &this->mSmallBlockSystemPages.mNode;
  `eh vector constructor iterator(
    this->mBuckets,
    0x80ui64,
    32,
    (void (__fastcall *)(void *))UFG::allocator::bucket::bucket);
  this->mBucketFreePages.mNode.mPrev = &this->mBucketFreePages.mNode;
  this->mBucketFreePages.mNode.mNext = &this->mBucketFreePages.mNode;
  UFG::qMutex::qMutex(&this->mBucketFreePagesMutex, "allocator.mBucketFreePagesMutex");
  this->mFreeTree.mHead.mParent = &this->mFreeTree.mHead;
  this->mFreeTree.mHead.mChildren[0] = &this->mFreeTree.mHead;
  this->mFreeTree.mHead.mChildren[1] = &this->mFreeTree.mHead;
  this->mFreeTree.mHead.mNeighbours[0] = &this->mFreeTree.mHead;
  this->mFreeTree.mHead.mNeighbours[1] = &this->mFreeTree.mHead;
  this->mSmallFreeList.mNode.mPrev = &this->mSmallFreeList.mNode;
  this->mSmallFreeList.mNode.mNext = &this->mSmallFreeList.mNode;
  UFG::qMutex::qMutex(&this->mTreeMutex, "allocator.mTreeMutex");
  this->mTreeMutexLockCount = 0;
  *(_QWORD *)&this->mLargeBlockMemoryPlatformAllocated = 0i64;
  this->mAllocationNumber = 0;
  this->mSystemMode = 0;
  this->mFixedSystemPageStart = 0i64;
  this->mFixedSystemPageEnd = 0i64;
  this->mSmallBlockStart = 0i64;
  this->mSmallBlockEnd = 0i64;
  this->mMRFreeBlock = 0i64;
  *(_QWORD *)&this->mReportBucketIndex = -1i64;
  this->mReportSmallPage = 0i64;
  this->mReportSmallSlot = -1;
  this->mReportLargeSystemPage = 0i64;
  this->mReportLargeBlock = 0i64;
  UFG::qMemSet(&this->mStats, 0, 0x78u);
}

// File Line: 215
// RVA: 0x163270
void __fastcall UFG::allocator::~allocator(UFG::allocator *this)
{
  bool v2; // zf
  UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *mPrev; // rcx
  UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *mNext; // rax
  UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *p_mBucketFreePages; // r8
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v6; // rdx
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v7; // rcx
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v8; // rax
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v9; // rcx
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v10; // rax
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *p_mSmallBlockSystemPages; // r8
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v12; // rdx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v13; // rcx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v14; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v15; // rcx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v16; // rax
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *p_mSystemPages; // r8
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v18; // rdx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v19; // rcx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v20; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v21; // rcx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v22; // rax

  if ( !this->mSmallBlockStart )
  {
    v2 = this->mStats.mLargeAllocNumBlocks == 0;
LABEL_5:
    if ( v2 )
      goto LABEL_7;
    goto LABEL_6;
  }
  if ( this->mStats.mLargeAllocNumBlocks == 1 )
  {
    v2 = this->mStats.mSmallAllocNumBytes == 0;
    goto LABEL_5;
  }
LABEL_6:
  UFG::qPrintf("ERROR: All allocs must be freed before a qMemoryPool can be Closed()! Name = %s \n", this->mName);
LABEL_7:
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&this->mTreeMutex);
  UFG::qList<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl,1,0>::DeleteNodes((UFG::qList<UFG::tChunkPosition,UFG::tChunkPosition,1,0> *)&this->mSmallFreeList);
  mPrev = this->mSmallFreeList.mNode.mPrev;
  mNext = this->mSmallFreeList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mSmallFreeList.mNode.mPrev = &this->mSmallFreeList.mNode;
  this->mSmallFreeList.mNode.mNext = &this->mSmallFreeList.mNode;
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::clear(&this->mFreeTree);
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&this->mBucketFreePagesMutex);
  p_mBucketFreePages = &this->mBucketFreePages;
  v6 = this->mBucketFreePages.mNode.mNext;
  if ( v6 != (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)&this->mBucketFreePages )
  {
    do
    {
      v7 = v6->mPrev;
      v8 = v6->mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mPrev = v6;
      v6->mNext = v6;
      v6 = this->mBucketFreePages.mNode.mNext;
    }
    while ( v6 != (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)p_mBucketFreePages );
  }
  v9 = p_mBucketFreePages->mNode.mPrev;
  v10 = this->mBucketFreePages.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mBucketFreePages->mNode.mPrev = &p_mBucketFreePages->mNode;
  this->mBucketFreePages.mNode.mNext = &this->mBucketFreePages.mNode;
  `eh vector destructor iterator(
    this->mBuckets,
    0x80ui64,
    32,
    (void (__fastcall *)(void *))UFG::allocator::bucket::~bucket);
  p_mSmallBlockSystemPages = &this->mSmallBlockSystemPages;
  v12 = this->mSmallBlockSystemPages.mNode.mNext;
  if ( v12 != (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)&this->mSmallBlockSystemPages )
  {
    do
    {
      v13 = v12->mPrev;
      v14 = v12->mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v12->mPrev = v12;
      v12->mNext = v12;
      v12 = this->mSmallBlockSystemPages.mNode.mNext;
    }
    while ( v12 != (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)p_mSmallBlockSystemPages );
  }
  v15 = p_mSmallBlockSystemPages->mNode.mPrev;
  v16 = this->mSmallBlockSystemPages.mNode.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_mSmallBlockSystemPages->mNode.mPrev = &p_mSmallBlockSystemPages->mNode;
  this->mSmallBlockSystemPages.mNode.mNext = &this->mSmallBlockSystemPages.mNode;
  p_mSystemPages = &this->mSystemPages;
  v18 = this->mSystemPages.mNode.mNext;
  if ( v18 != (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)&this->mSystemPages )
  {
    do
    {
      v19 = v18->mPrev;
      v20 = v18->mNext;
      v19->mNext = v20;
      v20->mPrev = v19;
      v18->mPrev = v18;
      v18->mNext = v18;
      v18 = this->mSystemPages.mNode.mNext;
    }
    while ( v18 != (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)p_mSystemPages );
  }
  v21 = p_mSystemPages->mNode.mPrev;
  v22 = this->mSystemPages.mNode.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  p_mSystemPages->mNode.mPrev = &p_mSystemPages->mNode;
  this->mSystemPages.mNode.mNext = &this->mSystemPages.mNode;
}

// File Line: 240
// RVA: 0x1812D0
void __fastcall UFG::allocator::init(
        UFG::allocator *this,
        const char *name,
        char *large_block_memory,
        unsigned __int64 large_block_byte_size,
        unsigned __int64 small_block_byte_size,
        int can_small_block_overflow_into_large_block)
{
  const char *v10; // rax
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *p_mSystemPages; // rcx
  unsigned __int64 v12; // rsi
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *mPrev; // rax
  UFG::allocator::block_header *v14; // rdi
  unsigned __int64 mLinearAllocNumBytes; // rcx
  UFG::allocator::system_mode mSystemMode; // eax
  unsigned __int64 v17; // rcx
  unsigned __int64 v18; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v19; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v20; // rbx
  char *v21; // rax

  if ( !this->mStats.mSystemPageNumBytes )
  {
    v10 = "<Unnamed MemoryPool>";
    if ( name )
      v10 = name;
    this->mName = v10;
    if ( large_block_memory )
    {
      this->mSystemMode = 0;
      *(_QWORD *)large_block_memory = large_block_memory;
      *((_QWORD *)large_block_memory + 1) = large_block_memory;
      p_mSystemPages = &this->mSystemPages;
      v12 = large_block_byte_size - 32;
      *((_QWORD *)large_block_memory + 2) = large_block_byte_size - 32;
      mPrev = p_mSystemPages->mNode.mPrev;
      mPrev->mNext = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)large_block_memory;
      *((_QWORD *)large_block_memory + 1) = p_mSystemPages;
      *(_QWORD *)large_block_memory = mPrev;
      p_mSystemPages->mNode.mPrev = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)large_block_memory;
      this->mFixedSystemPageStart = large_block_memory;
      this->mFixedSystemPageEnd = &large_block_memory[*((_QWORD *)large_block_memory + 2) + 32];
      v14 = UFG::allocator::tree_add_block(this, large_block_memory + 32, *((_QWORD *)large_block_memory + 2));
      UFG::qMemSet(&v14->_padding[4], 0xDEDEDEDE, v14->mSizeAndFlags & 0xFFFFFFFC);
      v14->mSizeAndFlags |= 1ui64;
      v14->mName = &customCaption;
      UFG::allocator::tree_free(this, &v14->_padding[4]);
      mLinearAllocNumBytes = this->mStats.mLinearAllocNumBytes;
      this->mStats.mLargePoolNumBytes = v12;
      this->mStats.mSystemPageNumBytes = large_block_byte_size + mLinearAllocNumBytes;
      this->mStats.mLargeAllocNumBytes = 0i64;
      this->mStats.mLargeAllocNumBlocks = 0i64;
      this->mStats.mLargeAllocHighWaterNumBytes = 0i64;
      this->mStats.mSystemPageNumPages = 1i64;
    }
    else
    {
      this->mSystemMode = ACTIVE_REGION_MGT;
    }
    mSystemMode = this->mSystemMode;
    if ( mSystemMode )
    {
      if ( mSystemMode == ACTIVE_REGION_MGT )
      {
        this->mCanSmallBlockOverflowIntoLargeBlock = 0;
        this->mSmallBlockStart = 0i64;
        this->mSmallBlockEnd = 0i64;
        UFG::allocator::bucket_system_alloc(
          this,
          (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)0xFFC000);
      }
    }
    else
    {
      if ( small_block_byte_size )
      {
        v17 = (unsigned __int64)(large_block_memory + 8287) & 0xFFFFFFFFFFFFE000ui64;
        v18 = (unsigned __int64)&large_block_memory[large_block_byte_size - 8224] & 0xFFFFFFFFFFFFE000ui64;
        if ( v18 <= v17 )
        {
          UFG::qPrintf("WARNING: no space for small blocks in pool %s\n", name);
        }
        else
        {
          v19 = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)(v18 - v17);
          v20 = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)((small_block_byte_size + 0x1FFF) & 0xFFFFFFFFFFFFE000ui64);
          if ( v20 >= v19 )
            v20 = v19;
          if ( v20 )
          {
            v21 = (char *)UFG::allocator::bucket_system_alloc(this, v20);
            this->mSmallBlockStart = v21;
            this->mCanSmallBlockOverflowIntoLargeBlock = can_small_block_overflow_into_large_block;
            this->mSmallBlockEnd = &v21[(_QWORD)v20];
            return;
          }
        }
      }
      this->mCanSmallBlockOverflowIntoLargeBlock = 1;
      this->mSmallBlockStart = 0i64;
      this->mSmallBlockEnd = 0i64;
    }
  }
}

// File Line: 400
// RVA: 0x181080
unsigned __int64 __fastcall UFG::allocator::get_largest_free_size(UFG::allocator *this)
{
  UFG::intrusive_multi_rbtree_base::node_base *v2; // rax
  UFG::allocator *v3; // r8
  UFG::intrusive_multi_rbtree_base::node_base *i; // rdx
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rdi
  UFG::allocator::block_header *mMRFreeBlock; // rax

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mTreeMutex);
  v2 = this->mFreeTree.mHead.mChildren[0];
  v3 = (UFG::allocator *)v2;
  for ( i = v2->mChildren[1]; v2 != i; i = i->mChildren[1] )
  {
    v3 = (UFG::allocator *)v2;
    v2 = i;
  }
  v5 = 0i64;
  if ( v3 == (UFG::allocator *)&this->mFreeTree || v3 == (UFG::allocator *)32 )
    v6 = 0i64;
  else
    v6 = (unsigned __int64)v3[-1].mReportLargeSystemPage & 0xFFFFFFFFFFFFFFFCui64;
  mMRFreeBlock = this->mMRFreeBlock;
  if ( mMRFreeBlock )
    v5 = mMRFreeBlock->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mTreeMutex);
  if ( v6 > v5 )
    v5 = v6;
  return v5 - 32;
}

// File Line: 491
// RVA: 0x18D5E0
char __fastcall UFG::allocator::report_begin(UFG::allocator *this)
{
  int v2; // ebx
  __int64 v3; // rax

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mTreeMutex);
  v2 = 0;
  v3 = 0i64;
  do
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBuckets[v3]);
    v3 = ++v2;
  }
  while ( (unsigned __int64)v2 < 0x20 );
  return 1;
}

// File Line: 579
// RVA: 0x18D750
bool __fastcall UFG::allocator::report_get_first_small_block_info(
        UFG::allocator *this,
        UFG::MemoryPoolSmallBlockInfo *info,
        int bucket_index)
{
  UFG::allocator::page *mNext; // rax
  bool result; // al

  this->mReportSmallBucketIndex = -1;
  this->mReportSmallSlot = -1;
  this->mReportSmallPage = 0i64;
  if ( !info )
    return 0;
  if ( bucket_index < 0 || (unsigned __int64)bucket_index >= 0x20 )
    return 0;
  if ( (UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *)this->mBuckets[bucket_index].mPageList.mNode.mNext == &this->mBuckets[bucket_index].mPageList )
    return 0;
  mNext = (UFG::allocator::page *)this->mBuckets[(__int64)bucket_index].mPageList.mNode.mNext;
  if ( !mNext )
    return 0;
  this->mReportSmallPage = mNext;
  this->mReportSmallBucketIndex = bucket_index;
  this->mReportSmallSlot = 0;
  info->mBucketIndex = bucket_index;
  info->mPointer = (void *)((unsigned __int64)mNext & 0xFFFFFFFFFFFFE000ui64);
  info->mName = &customCaption;
  *(_WORD *)&info->mIsFreeBlock = 0;
  result = 1;
  info->mNumBytes = 16i64 * (unsigned int)(bucket_index + 1);
  return result;
}

// File Line: 619
// RVA: 0x18D930
bool __fastcall UFG::allocator::report_get_next_small_block_info(
        UFG::allocator *this,
        UFG::MemoryPoolSmallBlockInfo *info)
{
  __int64 mReportSmallBucketIndex; // r10
  UFG::allocator::page *mReportSmallPage; // r9
  bool result; // al
  int v5; // r8d
  __int64 v6; // rcx

  mReportSmallBucketIndex = this->mReportSmallBucketIndex;
  mReportSmallPage = this->mReportSmallPage;
  if ( info == 0i64 || (int)mReportSmallBucketIndex < 0 )
    return 0;
  v5 = this->mReportSmallSlot + 1;
  if ( v5 == 0x1FE0 / (16 * (unsigned __int64)((unsigned int)mReportSmallPage->mBucketIndex + 1) + 8) - 1 )
  {
    mReportSmallPage = (UFG::allocator::page *)mReportSmallPage->mNext;
    if ( mReportSmallPage == (UFG::allocator::page *)&this->mBuckets[mReportSmallBucketIndex].mPageList )
    {
      LODWORD(mReportSmallBucketIndex) = -1;
      mReportSmallPage = 0i64;
      v5 = -1;
    }
    else
    {
      v5 = 0;
    }
  }
  this->mReportSmallBucketIndex = mReportSmallBucketIndex;
  this->mReportSmallPage = mReportSmallPage;
  this->mReportSmallSlot = v5;
  if ( (int)mReportSmallBucketIndex < 0 )
    return 0;
  info->mName = &customCaption;
  v6 = (unsigned int)mReportSmallPage->mBucketIndex + 1;
  info->mBucketIndex = mReportSmallBucketIndex;
  *(_WORD *)&info->mIsFreeBlock = 0;
  info->mPointer = (void *)(((unsigned __int64)mReportSmallPage & 0xFFFFFFFFFFFFE000ui64) + v5 * 16 * v6);
  result = 1;
  info->mNumBytes = 16i64 * (unsigned int)(mReportSmallBucketIndex + 1);
  return result;
}

// File Line: 671
// RVA: 0x18D650
bool __fastcall UFG::allocator::report_get_first_large_block_info(
        UFG::allocator *this,
        UFG::MemoryPoolLargeBlockInfo *info)
{
  int v2; // r9d
  bool result; // al
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *p_mSystemPages; // r10
  UFG::allocator::system_page_header *mNext; // rdx
  UFG::allocator::block_header *v8; // rax
  UFG::allocator::block_header *v9; // r8
  unsigned __int64 v10; // rcx
  bool v11; // zf
  int mSizeAndFlags; // ecx

  v2 = 0;
  this->mReportLargeSystemPage = 0i64;
  this->mReportLargeBlock = 0i64;
  if ( !info )
    return 0;
  p_mSystemPages = &this->mSystemPages;
  if ( (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)this->mSystemPages.mNode.mNext == &this->mSystemPages )
    mNext = 0i64;
  else
    mNext = (UFG::allocator::system_page_header *)this->mSystemPages.mNode.mNext;
  v8 = 0i64;
  if ( mNext )
  {
    while ( !v8 )
    {
      v8 = (UFG::allocator::block_header *)&mNext[1];
      v9 = (UFG::allocator::block_header *)((char *)mNext + mNext->mByteSize);
      v10 = mNext[1].mByteSize & 0xFFFFFFFFFFFFFFFCui64;
      if ( v10 )
      {
LABEL_11:
        v11 = v8 == v9;
      }
      else
      {
        while ( 1 )
        {
          v11 = v8 == v9;
          if ( v8 >= v9 )
            break;
          v8 = (UFG::allocator::block_header *)((char *)v8 + v10 + 32);
          v10 = v8->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64;
          if ( v10 )
            goto LABEL_11;
        }
      }
      if ( v11 )
      {
        mNext = (UFG::allocator::system_page_header *)mNext->mNext;
        v8 = 0i64;
        if ( mNext == (UFG::allocator::system_page_header *)p_mSystemPages )
        {
          mNext = 0i64;
          break;
        }
      }
      if ( !mNext )
        break;
    }
  }
  this->mReportLargeSystemPage = mNext;
  this->mReportLargeBlock = v8;
  LOBYTE(v2) = mNext == 0i64;
  if ( v2 | (v8 == 0i64) )
    return 0;
  info->mName = v8->mName;
  info->mPointer = &v8->_padding[4];
  info->mNumBytes = v8->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64;
  info->mIsFreeBlock = (v8->mSizeAndFlags & 1) == 0;
  mSizeAndFlags = v8->mSizeAndFlags;
  result = 1;
  info->mIsMarked = (mSizeAndFlags & 2) != 0;
  return result;
}

// File Line: 736
// RVA: 0x18D800
bool __fastcall UFG::allocator::report_get_next_large_block_info(
        UFG::allocator *this,
        UFG::MemoryPoolLargeBlockInfo *info)
{
  bool result; // al
  UFG::allocator::block_header *mReportLargeBlock; // r10
  UFG::allocator::system_page_header *mReportLargeSystemPage; // r8
  int v7; // r9d
  UFG::allocator::block_header *v8; // rax
  UFG::allocator::block_header *v9; // rdx
  unsigned __int64 v10; // rcx
  bool v11; // zf
  int mSizeAndFlags; // ecx

  if ( !info )
    return 0;
  mReportLargeBlock = this->mReportLargeBlock;
  mReportLargeSystemPage = this->mReportLargeSystemPage;
  v7 = 0;
  v8 = 0i64;
  if ( mReportLargeSystemPage != 0i64 && mReportLargeBlock != 0i64 )
  {
    do
    {
      v9 = (UFG::allocator::block_header *)((char *)mReportLargeSystemPage + mReportLargeSystemPage->mByteSize);
      v8 = (UFG::allocator::block_header *)&mReportLargeBlock->_padding[(mReportLargeBlock->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64)
                                                                      + 4];
      v10 = v8->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64;
      if ( v10 )
      {
LABEL_7:
        v11 = v8 == v9;
      }
      else
      {
        while ( 1 )
        {
          v11 = v8 == v9;
          if ( v8 >= v9 )
            break;
          v8 = (UFG::allocator::block_header *)((char *)v8 + v10 + 32);
          v10 = v8->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64;
          if ( v10 )
            goto LABEL_7;
        }
      }
      if ( v11 )
      {
        mReportLargeSystemPage = (UFG::allocator::system_page_header *)mReportLargeSystemPage->mNext;
        if ( mReportLargeSystemPage == (UFG::allocator::system_page_header *)&this->mSystemPages )
        {
          mReportLargeSystemPage = 0i64;
          mReportLargeBlock = 0i64;
        }
        else
        {
          mReportLargeBlock = (UFG::allocator::block_header *)&mReportLargeSystemPage[1];
        }
        v8 = 0i64;
      }
    }
    while ( mReportLargeBlock != 0i64 && v8 == 0i64 && mReportLargeSystemPage != 0i64 );
  }
  this->mReportLargeSystemPage = mReportLargeSystemPage;
  this->mReportLargeBlock = v8;
  LOBYTE(v7) = mReportLargeSystemPage == 0i64;
  if ( v7 | (v8 == 0i64) )
    return 0;
  info->mName = v8->mName;
  info->mPointer = &v8->_padding[4];
  info->mNumBytes = v8->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64;
  info->mIsFreeBlock = (v8->mSizeAndFlags & 1) == 0;
  mSizeAndFlags = v8->mSizeAndFlags;
  result = 1;
  info->mIsMarked = (mSizeAndFlags & 2) != 0;
  return result;
}

// File Line: 808
// RVA: 0x18DD40
void __fastcall UFG::allocator::set_mark(UFG::allocator *this)
{
  int v1; // ebx
  int v3; // esi
  __int64 v4; // rax
  int v5; // r8d
  __int64 v6; // rax
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> **p_mNext; // r9
  UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *mNext; // rcx
  UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *p_mPageList; // rdx
  __int64 v10; // rax
  _RTL_CRITICAL_SECTION *p_mTreeMutex; // rbx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v12; // r8
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *i; // rdi
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v14; // rax
  unsigned __int64 v15; // r9
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *mPrev; // rcx

  v1 = 0;
  v3 = 0;
  v4 = 0i64;
  do
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBuckets[v4]);
    v4 = ++v3;
  }
  while ( (unsigned __int64)v3 < 0x20 );
  v5 = 0;
  v6 = 0i64;
  p_mNext = &this->mBuckets[0].mPageList.mNode.mNext;
  do
  {
    mNext = (UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *)*p_mNext;
    p_mPageList = &this->mBuckets[v6].mPageList;
    if ( *p_mNext != (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)p_mPageList )
    {
      do
        mNext = (UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *)mNext->mNode.mNext;
      while ( mNext != p_mPageList );
    }
    ++v5;
    p_mNext += 16;
    v6 = v5;
  }
  while ( (unsigned __int64)v5 < 0x20 );
  v10 = 0i64;
  do
  {
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mBuckets[v10]);
    v10 = ++v1;
  }
  while ( (unsigned __int64)v1 < 0x20 );
  p_mTreeMutex = (_RTL_CRITICAL_SECTION *)&this->mTreeMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mTreeMutex);
  v12 = this->mSystemPages.mNode.mNext;
  for ( i = &this->mSystemPages;
        v12 != (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)i;
        v12 = v12->mNext )
  {
    v14 = v12 + 2;
    v15 = (unsigned __int64)v12 + (unsigned __int64)v12[1].mPrev;
    if ( (unsigned __int64)&v12[2] < v15 )
    {
      do
      {
        mPrev = v14[1].mPrev;
        if ( ((unsigned __int64)mPrev & 0xFFFFFFFFFFFFFFFCui64) != 0 )
          v14[1].mPrev = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)((unsigned __int64)mPrev | 2);
        v14 = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)((char *)v14
                                                                                                  + ((unsigned __int64)v14[1].mPrev & 0xFFFFFFFFFFFFFFFCui64)
                                                                                                  + 32);
      }
      while ( (unsigned __int64)v14 < v15 );
    }
  }
  UFG::qMutex::Unlock(p_mTreeMutex);
}

// File Line: 905
// RVA: 0x181150
__int64 __fastcall UFG::allocator::get_unmarked_count(UFG::allocator *this)
{
  int v1; // ebx
  int v3; // edi
  int v4; // esi
  __int64 v5; // rax
  int v6; // r10d
  __int64 v7; // rax
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> **p_mNext; // r11
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v9; // r8
  UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *p_mPageList; // r9
  int v11; // eax
  int v12; // esi
  __int64 v13; // rax
  _RTL_CRITICAL_SECTION *p_mTreeMutex; // rsi
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *mNext; // r8
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *i; // rbp
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v17; // rax
  unsigned __int64 v18; // r9

  v1 = 0;
  v3 = 0;
  if ( (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)this->mSmallBlockSystemPages.mNode.mNext != &this->mSmallBlockSystemPages )
  {
    v4 = 0;
    v5 = 0i64;
    do
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBuckets[v5]);
      v5 = ++v4;
    }
    while ( (unsigned __int64)v4 < 0x20 );
    v6 = 0;
    v7 = 0i64;
    p_mNext = &this->mBuckets[0].mPageList.mNode.mNext;
    do
    {
      v9 = *p_mNext;
      p_mPageList = &this->mBuckets[v7].mPageList;
      if ( *p_mNext != (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)p_mPageList )
      {
        do
        {
          v11 = 0x1FE0 / (16 * (unsigned __int64)((unsigned int)LOWORD(v9[1].mNext) + 1) + 8) - 1;
          if ( v11 > 0 )
            v3 += v11;
          v9 = v9->mNext;
        }
        while ( v9 != (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)p_mPageList );
      }
      ++v6;
      p_mNext += 16;
      v7 = v6;
    }
    while ( (unsigned __int64)v6 < 0x20 );
    v12 = 0;
    v13 = 0i64;
    do
    {
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mBuckets[v13]);
      v13 = ++v12;
    }
    while ( (unsigned __int64)v12 < 0x20 );
  }
  p_mTreeMutex = (_RTL_CRITICAL_SECTION *)&this->mTreeMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mTreeMutex);
  mNext = this->mSystemPages.mNode.mNext;
  for ( i = &this->mSystemPages;
        mNext != (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)i;
        mNext = mNext->mNext )
  {
    v17 = mNext + 2;
    v18 = (unsigned __int64)mNext + (unsigned __int64)mNext[1].mPrev;
    if ( (unsigned __int64)&mNext[2] < v18 )
    {
      do
      {
        if ( ((unsigned __int64)v17[1].mPrev & 0xFFFFFFFFFFFFFFFCui64) != 0
          && v17->mNext
          && ((__int64)v17[1].mPrev & 2) == 0 )
        {
          ++v1;
        }
        v17 = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)((char *)v17
                                                                                                  + ((unsigned __int64)v17[1].mPrev & 0xFFFFFFFFFFFFFFFCui64)
                                                                                                  + 32);
      }
      while ( (unsigned __int64)v17 < v18 );
    }
  }
  UFG::qMutex::Unlock(p_mTreeMutex);
  return (unsigned int)(v1 + v3);
}

// File Line: 964
// RVA: 0x18DA20
void __fastcall UFG::allocator::report_unmarked(UFG::allocator *this)
{
  UFG::allocator *v1; // r13
  int v2; // r14d
  int v3; // ebx
  __int64 v4; // rax
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> **p_mNext; // rcx
  int v6; // r12d
  __int64 v7; // rax
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v8; // rbx
  UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *p_mPageList; // r15
  int v10; // eax
  __int64 v11; // rdi
  __int64 v12; // rbp
  __int64 v13; // r8
  __int64 v14; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *i; // rdi
  unsigned __int64 v16; // rbx
  unsigned __int64 v17; // rsi
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> **v19; // [rsp+78h] [rbp+10h]

  v1 = this;
  if ( (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)this->mSmallBlockSystemPages.mNode.mNext != &this->mSmallBlockSystemPages )
  {
    v2 = 0;
    v3 = 0;
    v4 = 0i64;
    do
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mBuckets[v4]);
      v4 = ++v3;
    }
    while ( (unsigned __int64)v3 < 0x20 );
    p_mNext = &v1->mBuckets[0].mPageList.mNode.mNext;
    v6 = 0;
    v7 = 0i64;
    v19 = &v1->mBuckets[0].mPageList.mNode.mNext;
    do
    {
      v8 = *p_mNext;
      p_mPageList = &v1->mBuckets[v7].mPageList;
      if ( *p_mNext != (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)p_mPageList )
      {
        do
        {
          v10 = 0x1FE0 / (16 * (unsigned __int64)((unsigned int)LOWORD(v8[1].mNext) + 1) + 8) - 1;
          if ( v10 > 0 )
          {
            v11 = 0i64;
            v12 = (unsigned int)v10;
            do
            {
              v13 = 16i64 * ((unsigned int)LOWORD(v8[1].mNext) + 1);
              UFG::qPrintf(
                "0x%08x | %10d | %s | %s\n",
                ((unsigned __int64)v8 & 0xFFFFFFFFFFFFE000ui64) + v13 * v11++,
                v13,
                "unmarked",
                &customCaption);
              --v12;
            }
            while ( v12 );
          }
          v8 = v8->mNext;
        }
        while ( v8 != (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)p_mPageList );
        v1 = this;
        p_mNext = v19;
      }
      ++v6;
      p_mNext += 16;
      v7 = v6;
      v19 = p_mNext;
    }
    while ( (unsigned __int64)v6 < 0x20 );
    v14 = 0i64;
    do
    {
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mBuckets[v14]);
      v14 = ++v2;
    }
    while ( (unsigned __int64)v2 < 0x20 );
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mTreeMutex);
  for ( i = v1->mSystemPages.mNode.mNext;
        i != (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)&v1->mSystemPages;
        i = i->mNext )
  {
    v16 = (unsigned __int64)&i[2];
    v17 = (unsigned __int64)i + (unsigned __int64)i[1].mPrev;
    if ( (unsigned __int64)&i[2] < v17 )
    {
      do
      {
        if ( (*(_QWORD *)(v16 + 16) & 0xFFFFFFFFFFFFFFFCui64) != 0
          && *(_QWORD *)(v16 + 8)
          && (*(_BYTE *)(v16 + 16) & 2) == 0 )
        {
          UFG::qPrintf(
            "0x%08x | %10d | %s | %s\n",
            v16 + 32,
            *(_QWORD *)(v16 + 16) & 0xFFFFFFFFFFFFFFFCui64,
            "unmarked",
            *(const char **)(v16 + 8));
        }
        v16 += (*(_QWORD *)(v16 + 16) & 0xFFFFFFFFFFFFFFFCui64) + 32;
      }
      while ( v16 < v17 );
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mTreeMutex);
}

// File Line: 1077
// RVA: 0x17FF60
UFG::allocator::free_link *__fastcall UFG::allocator::alloc(
        UFG::allocator *this,
        unsigned __int64 size,
        UFG::allocator::allocation_strategy strategy,
        const char *name)
{
  unsigned __int64 v6; // rbx
  UFG::allocator::free_link *result; // rax

  v6 = size;
  if ( !size )
    return 0i64;
  if ( (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)this->mSmallBlockSystemPages.mNode.mNext == &this->mSmallBlockSystemPages
    || size > 0x200 )
  {
    return (UFG::allocator::free_link *)UFG::allocator::tree_alloc(this, v6, strategy, name);
  }
  if ( size < 0x10 )
    v6 = 16i64;
  result = UFG::allocator::bucket_alloc_direct(this, (unsigned int)((v6 + 15) >> 4) - 1, name);
  if ( !result )
  {
    if ( !this->mCanSmallBlockOverflowIntoLargeBlock )
      return 0i64;
    return (UFG::allocator::free_link *)UFG::allocator::tree_alloc(this, v6, strategy, name);
  }
  return result;
}

// File Line: 1118
// RVA: 0x17FE80
UFG::allocator::free_link *__fastcall UFG::allocator::alloc(
        UFG::allocator *this,
        unsigned __int64 size,
        unsigned __int64 alignment,
        UFG::allocator::allocation_strategy strategy,
        const char *name)
{
  unsigned __int64 v7; // rbx
  UFG::allocator::free_link *result; // rax

  v7 = size;
  if ( alignment <= 0x10 )
    return (UFG::allocator::free_link *)UFG::allocator::alloc(this, size, strategy, name);
  if ( !size )
    return 0i64;
  if ( (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)this->mSmallBlockSystemPages.mNode.mNext == &this->mSmallBlockSystemPages
    || size > 0x200
    || alignment > 0x200 )
  {
    return (UFG::allocator::free_link *)UFG::allocator::tree_alloc_aligned(this, v7, alignment, strategy, name);
  }
  if ( size < 0x10 )
    v7 = 16i64;
  result = UFG::allocator::bucket_alloc_direct(
             this,
             (unsigned int)(((-(int)alignment & (v7 + alignment - 1)) + 15) >> 4) - 1,
             name);
  if ( !result )
  {
    if ( this->mCanSmallBlockOverflowIntoLargeBlock )
      return (UFG::allocator::free_link *)UFG::allocator::tree_alloc_aligned(this, v7, alignment, strategy, name);
  }
  return result;
}

// File Line: 1156
// RVA: 0x18D4F0
UFG::allocator::free_link *__fastcall UFG::allocator::realloc(
        UFG::allocator *this,
        UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *ptr,
        unsigned __int64 new_size,
        unsigned __int64 old_size,
        UFG::allocator::allocation_strategy strategy,
        const char *name)
{
  unsigned __int64 v6; // rbp
  UFG::allocator::free_link *result; // rax
  UFG::allocator::free_link *v11; // r14
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *i; // rax

  v6 = old_size;
  if ( (((old_size + 15) ^ (new_size + 15)) & 0xFFFFFFFFFFFFFFF0ui64) != 0 )
  {
    result = UFG::allocator::alloc(this, new_size, strategy, name);
    v11 = result;
    if ( result || !new_size )
    {
      if ( new_size < v6 )
        LODWORD(v6) = new_size;
      UFG::qMemCopy(result, ptr, v6);
      UFG::allocator::free(this, (char *)ptr);
      return v11;
    }
  }
  else
  {
    if ( !this->mSmallBlockStart )
    {
      if ( ptr )
      {
        for ( i = this->mSmallBlockSystemPages.mNode.mNext;
              i != (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)&this->mSmallBlockSystemPages;
              i = i->mNext )
        {
          if ( ptr >= (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)((char *)i - (char *)i[1].mPrev)
            && ptr < i )
          {
            break;
          }
        }
      }
    }
    return (UFG::allocator::free_link *)ptr;
  }
  return result;
}

// File Line: 1190
// RVA: 0x18DEB0
unsigned __int64 __fastcall UFG::allocator::size(UFG::allocator *this, char *ptr)
{
  char *mSmallBlockStart; // rcx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *i; // rcx

  if ( !ptr )
    return 0i64;
  mSmallBlockStart = this->mSmallBlockStart;
  if ( !mSmallBlockStart )
  {
    for ( i = this->mSmallBlockSystemPages.mNode.mNext;
          i != (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)&this->mSmallBlockSystemPages;
          i = i->mNext )
    {
      if ( ptr >= (char *)((char *)i - (char *)i[1].mPrev) && ptr < (char *)i )
        return 16i64
             * ((unsigned int)*(unsigned __int16 *)(((unsigned __int64)ptr & 0xFFFFFFFFFFFFE000ui64) + 0x1FF8) + 1);
    }
    return *((_QWORD *)ptr - 2) & 0xFFFFFFFFFFFFFFFCui64;
  }
  if ( ptr < mSmallBlockStart || ptr >= this->mSmallBlockEnd )
    return *((_QWORD *)ptr - 2) & 0xFFFFFFFFFFFFFFFCui64;
  return 16i64 * ((unsigned int)*(unsigned __int16 *)(((unsigned __int64)ptr & 0xFFFFFFFFFFFFE000ui64) + 0x1FF8) + 1);
}

// File Line: 1271
// RVA: 0x181020
void __fastcall UFG::allocator::free(UFG::allocator *this, char *ptr)
{
  char *mSmallBlockStart; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *i; // rax

  if ( ptr )
  {
    mSmallBlockStart = this->mSmallBlockStart;
    if ( !mSmallBlockStart )
    {
      for ( i = this->mSmallBlockSystemPages.mNode.mNext;
            i != (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)&this->mSmallBlockSystemPages;
            i = i->mNext )
      {
        if ( ptr >= (char *)((char *)i - (char *)i[1].mPrev) && ptr < (char *)i )
          goto LABEL_12;
      }
      goto LABEL_5;
    }
    if ( ptr < mSmallBlockStart || ptr >= this->mSmallBlockEnd )
    {
LABEL_5:
      UFG::allocator::tree_free(this, ptr);
      return;
    }
LABEL_12:
    UFG::allocator::bucket_free(this, (unsigned __int64)ptr);
  }
}

// File Line: 1432
// RVA: 0x160C60
void __fastcall UFG::allocator::bucket::bucket(UFG::allocator::bucket *this)
{
  UFG::qMutex::qMutex(&this->mLock, "Bucket");
  this->mPageList.mNode.mPrev = &this->mPageList.mNode;
  this->mPageList.mNode.mNext = &this->mPageList.mNode;
  this->mAllocNumBytes = 0i64;
  this->mFreeNumBytes = 0i64;
  UFG::qMemSet(this->_padding, 0, 0x30u);
}

// File Line: 1542
// RVA: 0x180540
UFG::qNode<UFG::allocator::page,UFG::allocator::page> *__fastcall UFG::allocator::bucket_system_alloc(
        UFG::allocator *this,
        UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *size)
{
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v4; // rbp
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v5; // rsi
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v6; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> **v7; // r8
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *mPrev; // rcx
  unsigned __int64 v9; // rdi
  UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *p_mBucketFreePages; // rdx
  __int64 v11; // r8
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v12; // rcx

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBucketFreePagesMutex);
  v4 = size + 2;
  if ( size == (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)-32i64 )
  {
    v5 = 0i64;
  }
  else
  {
    v6 = (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)UFG::allocator::tree_alloc_aligned(
                                                                    this,
                                                                    (unsigned __int64)&size[2],
                                                                    0x2000ui64,
                                                                    strategy_bestfit,
                                                                    "allocator.SmallBlockMemory");
    v5 = v6;
    if ( v6 )
    {
      v7 = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> **)((char *)&size->mPrev
                                                                                                + (_QWORD)v6);
      *v7 = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)v7;
      v7[1] = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)v7;
      v7[2] = size;
      mPrev = this->mSmallBlockSystemPages.mNode.mPrev;
      mPrev->mNext = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)((char *)size + (_QWORD)v6);
      *v7 = mPrev;
      v7[1] = &this->mSmallBlockSystemPages.mNode;
      this->mSmallBlockSystemPages.mNode.mPrev = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)((char *)size + (_QWORD)v6);
      v9 = (unsigned __int64)size >> 13;
      if ( (int)v9 > 0 )
      {
        p_mBucketFreePages = &this->mBucketFreePages;
        v11 = (int)v9;
        do
        {
          if ( v6 )
          {
            v6->mPrev = v6;
            v6->mNext = v6;
            v6[1].mPrev = 0i64;
            LODWORD(v6[1].mNext) = -1;
          }
          v12 = p_mBucketFreePages->mNode.mPrev;
          v12->mNext = v6;
          v6->mPrev = v12;
          v6->mNext = &p_mBucketFreePages->mNode;
          p_mBucketFreePages->mNode.mPrev = v6;
          v6 += 512;
          --v11;
        }
        while ( v11 );
      }
      this->mStats.mSmallSystemAllocNumBytes += (unsigned __int64)&v4[2];
      ++this->mStats.mSmallSystemAllocNumBlocks;
      this->mStats.mSmallPoolNumBytes += (__int64)(int)v9 << 13;
      this->mStats.mSmallPoolNumPages += (int)v9;
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mBucketFreePagesMutex);
  return v5;
}

// File Line: 1589
// RVA: 0x1803B0
UFG::qNode<UFG::allocator::page,UFG::allocator::page> *__fastcall UFG::allocator::bucket_page_alloc(
        UFG::allocator *this)
{
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *mNext; // rsi
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v3; // rax
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *mPrev; // rcx
  unsigned __int64 mSmallAllocNumBytes; // rdx
  unsigned __int64 mSmallAllocNumPages; // r8

  mNext = 0i64;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBucketFreePagesMutex);
  if ( (UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *)this->mBucketFreePages.mNode.mNext != &this->mBucketFreePages )
    goto LABEL_5;
  if ( this->mSystemMode == ACTIVE_REGION_MGT )
    UFG::allocator::bucket_system_alloc(this, 0xFFC000ui64);
  if ( (UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *)this->mBucketFreePages.mNode.mNext != &this->mBucketFreePages )
  {
LABEL_5:
    mNext = this->mBucketFreePages.mNode.mNext;
    v3 = mNext->mNext;
    mPrev = mNext->mPrev;
    mPrev->mNext = v3;
    v3->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    this->mStats.mSmallAllocNumBytes += 0x2000i64;
    ++this->mStats.mSmallAllocNumPages;
    mSmallAllocNumBytes = this->mStats.mSmallAllocNumBytes;
    if ( this->mStats.mSmallAllocHighWaterNumBytes > mSmallAllocNumBytes )
      mSmallAllocNumBytes = this->mStats.mSmallAllocHighWaterNumBytes;
    this->mStats.mSmallAllocHighWaterNumBytes = mSmallAllocNumBytes;
    mSmallAllocNumPages = this->mStats.mSmallAllocNumPages;
    if ( this->mStats.mSmallAllocHighWaterNumPages > mSmallAllocNumPages )
      mSmallAllocNumPages = this->mStats.mSmallAllocHighWaterNumPages;
    this->mStats.mSmallAllocHighWaterNumPages = mSmallAllocNumPages;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mBucketFreePagesMutex);
  return mNext;
}

// File Line: 1619
// RVA: 0x180490
void __fastcall UFG::allocator::bucket_page_free(UFG::allocator *this, unsigned __int64 ptr)
{
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v3; // rdi
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *mPrev; // rax

  v3 = (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)(ptr & 0xFFFFFFFFFFFFE000ui64);
  if ( (ptr & 0xFFFFFFFFFFFFE000ui64) != 0 )
  {
    v3->mPrev = v3;
    *(_QWORD *)((ptr & 0xFFFFFFFFFFFFE000ui64) + 8) = ptr & 0xFFFFFFFFFFFFE000ui64;
    *(_QWORD *)((ptr & 0xFFFFFFFFFFFFE000ui64) + 0x10) = 0i64;
    *(_DWORD *)((ptr & 0xFFFFFFFFFFFFE000ui64) + 0x18) = -1;
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBucketFreePagesMutex);
  mPrev = this->mBucketFreePages.mNode.mPrev;
  mPrev->mNext = v3;
  v3->mPrev = mPrev;
  v3->mNext = &this->mBucketFreePages.mNode;
  this->mBucketFreePages.mNode.mPrev = v3;
  this->mStats.mSmallAllocNumBytes -= 0x2000i64;
  --this->mStats.mSmallAllocNumPages;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mBucketFreePagesMutex);
}

// File Line: 1640
// RVA: 0x1802D0
unsigned __int64 __fastcall UFG::allocator::bucket_grow(UFG::allocator *this, unsigned __int64 elemSize)
{
  unsigned __int16 v2; // bx
  unsigned __int64 result; // rax
  unsigned __int64 v4; // r9
  unsigned __int64 v5; // rax
  _QWORD *v6; // r10
  _QWORD *v7; // rcx
  unsigned __int64 v8; // r8

  v2 = elemSize;
  result = (unsigned __int64)UFG::allocator::bucket_page_alloc(this);
  if ( result )
  {
    v4 = (result & 0xFFFFFFFFFFFFE000ui64) + 8160;
    if ( (result & 0xFFFFFFFFFFFFE000ui64) != -8160i64 )
    {
      *(_QWORD *)((result & 0xFFFFFFFFFFFFE000ui64) + 0x1FE0) = (result & 0xFFFFFFFFFFFFE000ui64) + 8160;
      *(_QWORD *)((result & 0xFFFFFFFFFFFFE000ui64) + 0x1FE8) = (result & 0xFFFFFFFFFFFFE000ui64) + 8160;
      *(_QWORD *)((result & 0xFFFFFFFFFFFFE000ui64) + 0x1FF0) = result;
      *(_WORD *)((result & 0xFFFFFFFFFFFFE000ui64) + 0x1FF8) = (v2 >> 4) - 1;
      *(_WORD *)((result & 0xFFFFFFFFFFFFE000ui64) + 0x1FFA) = 0;
    }
    v5 = 0x1FE0
       / (16 * (unsigned __int64)((unsigned int)*(unsigned __int16 *)((result & 0xFFFFFFFFFFFFE000ui64) + 0x1FF8) + 1)
        + 8);
    v6 = (_QWORD *)(v4 & 0xFFFFFFFFFFFFE000ui64);
    v7 = (_QWORD *)((v4 & 0xFFFFFFFFFFFFE000ui64) + 16i64 * ((unsigned int)*(unsigned __int16 *)(v4 + 24) + 1));
    v8 = 0i64;
    if ( v5 != 2 )
    {
      do
      {
        v7 = (_QWORD *)((v4 & 0xFFFFFFFFFFFFE000ui64)
                      + ((int)v8 + 1) * 16i64 * ((unsigned int)*(unsigned __int16 *)(v4 + 24) + 1));
        *v6 = v7;
        v6 = v7;
        ++v8;
      }
      while ( v8 < v5 - 2 );
    }
    *v7 = 0i64;
    return v4;
  }
  return result;
}

// File Line: 1736
// RVA: 0x180070
UFG::allocator::free_link *__fastcall UFG::allocator::bucket_alloc_direct(
        UFG::allocator *this,
        unsigned int bi,
        const char *name)
{
  __int64 v4; // r15
  unsigned __int64 v6; // r14
  _RTL_CRITICAL_SECTION *v7; // rdi
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *p_LockCount; // rsi
  unsigned __int64 v9; // rbx
  UFG::allocator::page *OwningThread; // r9
  UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *p_mPageList; // rcx
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *mNext; // rax
  UFG::allocator::free_link *mFreeList; // r14
  UFG::allocator::free_link *v15; // rax
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *mPrev; // rcx
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v17; // rax
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v18; // rcx

  v4 = bi;
  v6 = (unsigned __int64)bi << 7;
  v7 = (_RTL_CRITICAL_SECTION *)((char *)this->mBuckets + v6);
  UFG::qMutex::Lock(v7);
  p_LockCount = (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)&v7[1].LockCount;
  v9 = 16i64 * (bi + 1);
  if ( v7[1].OwningThread == &v7[1].LockCount
    || (OwningThread = (UFG::allocator::page *)v7[1].OwningThread, !OwningThread->mFreeList) )
  {
    OwningThread = UFG::allocator::bucket_grow(this, v9);
    if ( !OwningThread )
    {
      UFG::qMutex::Unlock(v7);
      return 0i64;
    }
    p_mPageList = &this->mBuckets[v4].mPageList;
    mNext = p_mPageList->mNode.mNext;
    p_mPageList->mNode.mNext = OwningThread;
    OwningThread->mPrev = &p_mPageList->mNode;
    OwningThread->mNext = mNext;
    mNext->mPrev = OwningThread;
    *(unsigned __int64 *)((char *)&this->mBuckets[0].mFreeNumBytes + v6) += 16i64
                                                                          * ((unsigned int)OwningThread->mBucketIndex + 1)
                                                                          * (0x1FE0
                                                                           / (16
                                                                            * (unsigned __int64)((unsigned int)OwningThread->mBucketIndex
                                                                                               + 1)
                                                                            + 8)
                                                                           - 1);
  }
  mFreeList = OwningThread->mFreeList;
  v15 = mFreeList->mNext;
  OwningThread->mFreeList = mFreeList->mNext;
  if ( !v15 )
  {
    mPrev = OwningThread->mPrev;
    v17 = OwningThread->mNext;
    mPrev->mNext = v17;
    v17->mPrev = mPrev;
    OwningThread->mPrev = OwningThread;
    OwningThread->mNext = OwningThread;
    v18 = p_LockCount->mPrev;
    v18->mNext = OwningThread;
    OwningThread->mPrev = v18;
    OwningThread->mNext = p_LockCount;
    p_LockCount->mPrev = OwningThread;
  }
  ++OwningThread->mUseCount;
  v7[1].LockSemaphore = (char *)v7[1].LockSemaphore + v9;
  v7[1].SpinCount -= v9;
  UFG::qMutex::Unlock(v7);
  return mFreeList;
}

// File Line: 1768
// RVA: 0x1801B0
void __fastcall UFG::allocator::bucket_free(UFG::allocator *this, unsigned __int64 ptr)
{
  _WORD *v4; // rdi
  __int64 v5; // r14
  __int64 v6; // rbp
  __int64 v7; // r14
  _RTL_CRITICAL_SECTION *v8; // rsi
  __int64 v9; // rbp
  __int64 v10; // rax
  __int64 v11; // rcx
  _QWORD *v12; // rax
  _QWORD *OwningThread; // rcx
  __int64 v14; // r8
  _QWORD *v15; // rax

  v4 = (_WORD *)((ptr & 0xFFFFFFFFFFFFE000ui64) + 8160);
  v5 = *(unsigned __int16 *)((ptr & 0xFFFFFFFFFFFFE000ui64) + 0x1FF8);
  v6 = (unsigned int)(v5 + 1);
  v7 = v5 << 7;
  v8 = (_RTL_CRITICAL_SECTION *)((char *)this->mBuckets + v7);
  v9 = 16 * v6;
  UFG::qMutex::Lock(v8);
  v10 = *((_QWORD *)v4 + 2);
  *(_QWORD *)ptr = v10;
  --v4[13];
  *((_QWORD *)v4 + 2) = ptr;
  if ( !v10 )
  {
    v11 = *(_QWORD *)v4;
    v12 = (_QWORD *)*((_QWORD *)v4 + 1);
    *(_QWORD *)(v11 + 8) = v12;
    *v12 = v11;
    *(_QWORD *)v4 = v4;
    *((_QWORD *)v4 + 1) = v4;
    OwningThread = v8[1].OwningThread;
    v8[1].OwningThread = v4;
    *((_QWORD *)v4 + 1) = OwningThread;
    *(_QWORD *)v4 = (char *)v8 + 48;
    *OwningThread = v4;
  }
  v8[1].LockSemaphore = (char *)v8[1].LockSemaphore - v9;
  v8[1].SpinCount += v9;
  if ( !v4[13] )
  {
    *(unsigned __int64 *)((char *)&this->mBuckets[0].mFreeNumBytes + v7) -= 16i64
                                                                          * ((unsigned int)(unsigned __int16)v4[12] + 1)
                                                                          * (0x1FE0
                                                                           / (16
                                                                            * (unsigned __int64)((unsigned int)(unsigned __int16)v4[12]
                                                                                               + 1)
                                                                            + 8)
                                                                           - 1);
    v14 = *(_QWORD *)v4;
    v15 = (_QWORD *)*((_QWORD *)v4 + 1);
    *(_QWORD *)(v14 + 8) = v15;
    *v15 = v14;
    *(_QWORD *)v4 = v4;
    *((_QWORD *)v4 + 1) = v4;
    UFG::allocator::bucket_page_free(this, v4);
  }
  UFG::qMutex::Unlock(v8);
}

// File Line: 1867
// RVA: 0x180730
UFG::allocator::block_header *__fastcall UFG::allocator::coalesce_block(
        UFG::allocator *this,
        UFG::allocator::block_header *bl)
{
  UFG::allocator::block_header *v4; // rbx
  UFG::allocator::free_node *v5; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v6; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v7; // rax
  UFG::allocator::block_header *mPrev; // rbx
  UFG::allocator::free_node *v9; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v10; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v11; // rax
  UFG::allocator::block_header *result; // rax

  v4 = (UFG::allocator::block_header *)&bl->_padding[(bl->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) + 4];
  if ( (v4->mSizeAndFlags & 1) == 0 )
  {
    if ( this->mMRFreeBlock == v4 )
    {
      this->mMRFreeBlock = 0i64;
    }
    else
    {
      v5 = (UFG::allocator::free_node *)&v4->_padding[4];
      if ( (v4->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
      {
        v6 = v5->mChildren[0];
        v7 = *(UFG::intrusive_multi_rbtree_base::node_base **)&v4->_padding[12];
        v6->mChildren[1] = v7;
        v7->mChildren[0] = v6;
        v5->mChildren[0] = v5;
        *(_QWORD *)&v4->_padding[12] = &v4->_padding[4];
      }
      else
      {
        UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(&this->mFreeTree, v5);
      }
    }
    *(_QWORD *)&v4->_padding[(v4->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) + 4] = v4->mPrev;
    v4->mPrev->mSizeAndFlags = v4->mPrev->mSizeAndFlags & 3 | ((unsigned __int64)v4
                                                             + (v4->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64)
                                                             - (unsigned __int64)v4->mPrev);
  }
  mPrev = bl->mPrev;
  if ( (bl->mPrev->mSizeAndFlags & 1) != 0 )
    return bl;
  if ( this->mMRFreeBlock == mPrev )
  {
    this->mMRFreeBlock = 0i64;
  }
  else
  {
    v9 = (UFG::allocator::free_node *)&mPrev->_padding[4];
    if ( (mPrev->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
    {
      v10 = v9->mChildren[0];
      v11 = *(UFG::intrusive_multi_rbtree_base::node_base **)&mPrev->_padding[12];
      v10->mChildren[1] = v11;
      v11->mChildren[0] = v10;
      v9->mChildren[0] = v9;
      *(_QWORD *)&mPrev->_padding[12] = &mPrev->_padding[4];
    }
    else
    {
      UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(&this->mFreeTree, v9);
    }
  }
  *(_QWORD *)&bl->_padding[(bl->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) + 4] = bl->mPrev;
  result = mPrev;
  bl->mPrev->mSizeAndFlags = bl->mPrev->mSizeAndFlags & 3 | ((unsigned __int64)bl
                                                           + (bl->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64)
                                                           - (unsigned __int64)bl->mPrev);
  return result;
}

// File Line: 1898
// RVA: 0x18EE30
UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *__fastcall UFG::allocator::tree_system_alloc(
        UFG::allocator *this,
        UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *size)
{
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v5; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v6; // rdx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *mNext; // rcx
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *p_mSystemPages; // r8
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *mPrev; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v10; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v11; // rax

  if ( !this->mSystemMode )
    return 0i64;
  v5 = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)UFG::qSystemAlloc((unsigned __int64)&size[2]);
  v6 = v5;
  if ( !v5 )
    return 0i64;
  v5->mPrev = v5;
  v5->mNext = v5;
  v5[1].mPrev = size;
  mNext = this->mSystemPages.mNode.mNext;
  p_mSystemPages = &this->mSystemPages;
  if ( mNext == (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)&this->mSystemPages )
    goto LABEL_10;
  while ( v5 >= mNext )
  {
    mNext = mNext->mNext;
    if ( mNext == (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)p_mSystemPages )
      goto LABEL_9;
  }
  mPrev = mNext->mPrev;
  mPrev->mNext = v6;
  v6->mPrev = mPrev;
  v6->mNext = mNext;
  mNext->mPrev = v6;
LABEL_9:
  if ( mNext == (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)p_mSystemPages )
  {
LABEL_10:
    v10 = p_mSystemPages->mNode.mPrev;
    v10->mNext = v6;
    v6->mPrev = v10;
    v6->mNext = &p_mSystemPages->mNode;
    p_mSystemPages->mNode.mPrev = v6;
  }
  v11 = v6[1].mPrev;
  ++this->mStats.mSystemPageNumPages;
  this->mStats.mSystemPageNumBytes += (unsigned __int64)&v11[2];
  this->mStats.mLargePoolNumBytes += (unsigned __int64)&v6[1].mPrev[-2];
  return v6 + 2;
}

// File Line: 1968
// RVA: 0x18DFB0
UFG::allocator::block_header *__fastcall UFG::allocator::tree_add_block(
        UFG::allocator *this,
        UFG::allocator::block_header *mem,
        unsigned __int64 size)
{
  char *v4; // rcx
  char *v5; // rax
  UFG::allocator::block_header *v6; // rdx

  mem->mSizeAndFlags &= 2ui64;
  mem->mSizeAndFlags |= 1ui64;
  v4 = (char *)mem + size;
  mem->mName = &customCaption;
  mem->mPrev = 0i64;
  *(_QWORD *)&mem->_padding[20] &= 2ui64;
  *(_QWORD *)&mem->_padding[20] |= 1ui64;
  *(_QWORD *)&mem->_padding[12] = &customCaption;
  *(_QWORD *)&mem->_padding[4] = mem;
  *((_QWORD *)v4 - 2) &= 2ui64;
  *((_QWORD *)v4 - 2) |= 1ui64;
  *((_QWORD *)v4 - 3) = &customCaption;
  *(_QWORD *)&mem->_padding[20] &= 2ui64;
  v5 = (char *)mem + size - 32;
  *(_QWORD *)&mem->_padding[12] = 0i64;
  v6 = (UFG::allocator::block_header *)&mem->_padding[4];
  v6->mSizeAndFlags |= v5 - (char *)v6 - 32;
  *((_QWORD *)v4 - 4) = v6;
  return UFG::allocator::coalesce_block(this, v6);
}

// File Line: 2007
// RVA: 0x18E5A0
UFG::allocator::block_header *__fastcall UFG::allocator::tree_extract(
        UFG::allocator *this,
        unsigned __int64 size,
        UFG::allocator::allocation_strategy strategy)
{
  char *mFixedSystemPageStart; // rcx
  char *v6; // rdx
  unsigned __int64 v7; // rbx
  UFG::allocator::block_header *mMRFreeBlock; // rdx
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v10; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v11; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v12; // rax
  unsigned __int64 v13; // rdx
  int v14; // eax
  unsigned __int64 v15; // rcx
  __int64 v16; // rcx
  char *v17; // rdx
  char *v18; // rdx
  unsigned __int64 v19; // rdi
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v20; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v21; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v22; // rax
  unsigned __int64 *v23; // r8
  int v24; // eax
  unsigned __int64 v25; // rcx
  unsigned __int64 v26; // rcx
  unsigned __int64 v27; // rbx
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *p_mFreeTree; // r8
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v29; // rbx
  UFG::intrusive_multi_rbtree_base::node_base *v30; // rcx
  __int64 v31; // rdx
  _QWORD *v32; // rcx

  if ( strategy == strategy_firstfit )
  {
    mFixedSystemPageStart = this->mFixedSystemPageStart;
    if ( mFixedSystemPageStart )
    {
      v6 = this->mFixedSystemPageEnd - 32;
      v7 = (unsigned __int64)&mFixedSystemPageStart[(*((_QWORD *)mFixedSystemPageStart + 6) & 0xFFFFFFFFFFFFFFFCui64)
                                                  + 64];
      if ( v7 < (unsigned __int64)v6 )
      {
        while ( (*(_BYTE *)(v7 + 16) & 1) != 0 || (*(_QWORD *)(v7 + 16) & 0xFFFFFFFFFFFFFFFCui64) <= size + 544 )
        {
          v7 += (*(_QWORD *)(v7 + 16) & 0xFFFFFFFFFFFFFFFCui64) + 32;
          if ( v7 >= (unsigned __int64)v6 )
            goto LABEL_7;
        }
        if ( this->mMRFreeBlock == (UFG::allocator::block_header *)v7 )
        {
          this->mMRFreeBlock = 0i64;
        }
        else
        {
          v10 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)(v7 + 32);
          if ( (*(_QWORD *)(v7 + 16) & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
          {
            v11 = v10->mHead.mChildren[0];
            v12 = *(UFG::intrusive_multi_rbtree_base::node_base **)(v7 + 40);
            v11->mChildren[1] = v12;
            v12->mChildren[0] = v11;
            v10->mHead.mChildren[0] = &v10->mHead;
            *(_QWORD *)(v7 + 40) = v7 + 32;
          }
          else
          {
            UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(&this->mFreeTree, v10);
          }
        }
        v13 = v7 + size + 32;
        v14 = *(_DWORD *)(v13 + 16);
        *(_QWORD *)v13 = v7;
        v15 = v14 & 3 | ((*(_QWORD *)(v7 + 16) & 0xFFFFFFFFFFFFFFFCui64) - (size + 32));
        *(_QWORD *)(v13 + 16) = v15;
        *(_QWORD *)((v15 & 0xFFFFFFFFFFFFFFFCui64) + v13 + 32) = v13;
        v16 = *(_QWORD *)v13;
        *(_QWORD *)(v16 + 16) &= 3ui64;
        *(_QWORD *)(v16 + 16) |= v7 + size - v16;
        *(_QWORD *)(v13 + 16) &= ~1ui64;
        *(_QWORD *)(v13 + 8) = 0i64;
        UFG::allocator::tree_attach(
          this,
          (UFG::allocator::block_header *)(v7 + (*(_QWORD *)(v7 + 16) & 0xFFFFFFFFFFFFFFFCui64) + 32));
        return (UFG::allocator::block_header *)v7;
      }
    }
LABEL_7:
    mMRFreeBlock = this->mMRFreeBlock;
    if ( mMRFreeBlock && (mMRFreeBlock->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) >= size )
    {
      this->mMRFreeBlock = 0i64;
      return mMRFreeBlock;
    }
    p_mFreeTree = &this->mFreeTree;
    v29 = &this->mFreeTree;
    v30 = this->mFreeTree.mHead.mChildren[0];
    if ( v30 != (UFG::intrusive_multi_rbtree_base::node_base *)&this->mFreeTree )
    {
      do
      {
        if ( ((unsigned __int64)v30[-1].mNeighbours[1] & 0xFFFFFFFFFFFFFFFCui64) >= size )
        {
          v29 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v30;
          v30 = v30->mChildren[0];
        }
        else
        {
          v30 = v30->mChildren[1];
        }
      }
      while ( v30 != (UFG::intrusive_multi_rbtree_base::node_base *)p_mFreeTree );
    }
    if ( v29 == p_mFreeTree )
      return 0i64;
    v7 = (unsigned __int64)&v29->mHead.mNeighbours[1][-1].mChildren[1];
    if ( mMRFreeBlock == (UFG::allocator::block_header *)v7 )
    {
      this->mMRFreeBlock = 0i64;
    }
    else if ( (*(_QWORD *)(v7 + 16) & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
    {
      v31 = *(_QWORD *)(v7 + 32);
      v32 = *(_QWORD **)(v7 + 40);
      *(_QWORD *)(v31 + 8) = v32;
      *v32 = v31;
      *(_QWORD *)(v7 + 32) = v7 + 32;
      *(_QWORD *)(v7 + 40) = v7 + 32;
    }
    else
    {
      UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(
        &this->mFreeTree,
        (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)(v7 + 32));
    }
    return (UFG::allocator::block_header *)v7;
  }
  if ( strategy != strategy_lastfit )
    goto LABEL_7;
  v17 = this->mFixedSystemPageStart;
  if ( !v17 )
    goto LABEL_7;
  v18 = v17 + 32;
  v19 = *((_QWORD *)this->mFixedSystemPageEnd - 4);
  if ( v19 <= (unsigned __int64)v18 )
    goto LABEL_7;
  while ( (*(_BYTE *)(v19 + 16) & 1) != 0 || (*(_QWORD *)(v19 + 16) & 0xFFFFFFFFFFFFFFFCui64) <= size + 544 )
  {
    v19 = *(_QWORD *)v19;
    if ( v19 <= (unsigned __int64)v18 )
      goto LABEL_7;
  }
  if ( this->mMRFreeBlock == (UFG::allocator::block_header *)v19 )
  {
    this->mMRFreeBlock = 0i64;
  }
  else
  {
    v20 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)(v19 + 32);
    if ( (*(_QWORD *)(v19 + 16) & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
    {
      v21 = v20->mHead.mChildren[0];
      v22 = *(UFG::intrusive_multi_rbtree_base::node_base **)(v19 + 40);
      v21->mChildren[1] = v22;
      v22->mChildren[0] = v21;
      v20->mHead.mChildren[0] = &v20->mHead;
      *(_QWORD *)(v19 + 40) = v19 + 32;
    }
    else
    {
      UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(&this->mFreeTree, v20);
    }
  }
  v23 = (unsigned __int64 *)(v19 + (*(_QWORD *)(v19 + 16) & 0xFFFFFFFFFFFFFFFCui64) - size);
  v24 = *((_DWORD *)v23 + 4);
  *v23 = v19;
  v25 = v24 & 3 | (v19 + (*(_QWORD *)(v19 + 16) & 0xFFFFFFFFFFFFFFFCui64) - (_QWORD)v23);
  v23[2] = v25;
  *(unsigned __int64 *)((char *)v23 + (v25 & 0xFFFFFFFFFFFFFFFCui64) + 32) = (unsigned __int64)v23;
  v26 = *v23;
  *(_QWORD *)(v26 + 16) &= 3ui64;
  *(_QWORD *)(v26 + 16) |= (unsigned __int64)v23 - v26 - 32;
  v23[2] &= ~1ui64;
  v23[1] = 0i64;
  v27 = *(_QWORD *)(v19 + 16) & 0xFFFFFFFFFFFFFFFCui64;
  UFG::allocator::tree_attach(this, (UFG::allocator::block_header *)v19);
  return (UFG::allocator::block_header *)(v27 + v19 + 32);
}

// File Line: 2097
// RVA: 0x18E8D0
UFG::allocator::block_header *__fastcall UFG::allocator::tree_extract_aligned(
        UFG::allocator *this,
        unsigned __int64 size,
        unsigned __int64 alignment,
        UFG::allocator::allocation_strategy strategy)
{
  char *mFixedSystemPageStart; // rcx
  char *v8; // rdx
  UFG::allocator::block_header *v9; // rbx
  UFG::allocator::block_header *mMRFreeBlock; // rdi
  UFG::allocator::block_header *result; // rax
  unsigned __int64 v12; // r8
  int v13; // eax
  unsigned __int64 v14; // rcx
  __int64 v15; // rdx
  char *v16; // rdx
  char *v17; // rdx
  UFG::allocator::block_header *v18; // rdi
  unsigned __int64 v19; // rbx
  unsigned __int64 v20; // rbx
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v21; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v22; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v23; // rax
  int v24; // eax
  UFG::allocator::block_header **v25; // r8
  unsigned __int64 v26; // rcx
  __int64 v27; // rcx
  unsigned __int64 v28; // rbx
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *p_mFreeTree; // r9
  unsigned __int64 v30; // r11
  UFG::intrusive_multi_rbtree_base::node_base *v31; // r8
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v32; // rax
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v33; // rdx
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v34; // r10
  __int64 v35; // r8
  int v36; // esi
  UFG::intrusive_multi_rbtree_base::node_base *mParent; // rcx
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *i; // rcx
  char v39; // cl
  UFG::intrusive_multi_rbtree_base::node_base *v40; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v41; // rcx

  if ( strategy == strategy_firstfit )
  {
    mFixedSystemPageStart = this->mFixedSystemPageStart;
    if ( mFixedSystemPageStart )
    {
      v8 = this->mFixedSystemPageEnd - 32;
      v9 = (UFG::allocator::block_header *)&mFixedSystemPageStart[(*((_QWORD *)mFixedSystemPageStart + 6) & 0xFFFFFFFFFFFFFFFCui64)
                                                                + 64];
      if ( v9 < (UFG::allocator::block_header *)v8 )
      {
        while ( (v9->mSizeAndFlags & 1) != 0 || (v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= size + alignment + 544 )
        {
          v9 = (UFG::allocator::block_header *)((char *)v9 + (v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) + 32);
          if ( v9 >= (UFG::allocator::block_header *)v8 )
            goto LABEL_7;
        }
        UFG::allocator::tree_detach(this, v9);
        v12 = -(int)alignment & (unsigned __int64)&v9->_padding[size + 3 + alignment];
        v13 = *(_DWORD *)(v12 + 0x10);
        *(_QWORD *)v12 = v9;
        v14 = v13 & 3 | ((unsigned __int64)v9 + (v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) - v12);
        *(_QWORD *)(v12 + 16) = v14;
        *(_QWORD *)((v14 & 0xFFFFFFFFFFFFFFFCui64) + v12 + 32) = v12;
        v15 = *(_QWORD *)v12;
        *(_QWORD *)(v15 + 16) &= 3ui64;
        *(_QWORD *)(v15 + 16) |= v12 - v15 - 32;
        *(_QWORD *)(v12 + 16) &= ~1ui64;
        *(_QWORD *)(v12 + 8) = 0i64;
        UFG::allocator::tree_attach(
          this,
          (UFG::allocator::block_header *)&v9->_padding[(v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) + 4]);
        return v9;
      }
    }
LABEL_7:
    mMRFreeBlock = this->mMRFreeBlock;
    if ( mMRFreeBlock
      && (mMRFreeBlock->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) >= size
                                                                 + (-(int)alignment & (unsigned __int64)&mMRFreeBlock->_padding[alignment + 3])
                                                                 - (_QWORD)mMRFreeBlock
                                                                 - 32 )
    {
      result = this->mMRFreeBlock;
      this->mMRFreeBlock = 0i64;
      return result;
    }
    p_mFreeTree = &this->mFreeTree;
    v30 = size + alignment;
    v31 = this->mFreeTree.mHead.mChildren[0];
    v32 = &this->mFreeTree;
    v33 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v31;
    if ( v31 != (UFG::intrusive_multi_rbtree_base::node_base *)&this->mFreeTree )
    {
      do
      {
        if ( ((unsigned __int64)v33[-1].mHead.mNeighbours[1] & 0xFFFFFFFFFFFFFFFCui64) >= size )
        {
          v32 = v33;
          v33 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v33->mHead.mChildren[0];
        }
        else
        {
          v33 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v33->mHead.mChildren[1];
        }
      }
      while ( v33 != p_mFreeTree );
    }
    v34 = &this->mFreeTree;
    while ( v31 != (UFG::intrusive_multi_rbtree_base::node_base *)p_mFreeTree )
    {
      if ( ((unsigned __int64)v31[-1].mNeighbours[1] & 0xFFFFFFFFFFFFFFFCui64) <= v30 )
      {
        v31 = v31->mChildren[1];
      }
      else
      {
        v34 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v31;
        v31 = v31->mChildren[0];
      }
    }
    if ( v32 != v34 )
    {
      v35 = alignment - 1;
      v36 = -(int)alignment;
      do
      {
        if ( ((unsigned __int64)v32[-1].mHead.mNeighbours[1] & 0xFFFFFFFFFFFFFFFCui64) >= size
                                                                                        + (v36 & ((unsigned __int64)v32
                                                                                                + v35))
                                                                                        - (_QWORD)v32 )
          break;
        v32 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v32->mHead.mNeighbours[1];
        mParent = v32->mHead.mParent;
        if ( ((unsigned __int64)mParent & 0xFFFFFFFFFFFFFFFCui64) != 0 )
        {
          v32 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v32->mHead.mChildren[1];
          if ( v32 == (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v32->mHead.mChildren[1] )
          {
            v32 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)((unsigned __int64)mParent & 0xFFFFFFFFFFFFFFFCui64);
            if ( ((unsigned __int8)mParent & 2) != 0 )
            {
              do
              {
                v39 = (unsigned __int8)LODWORD(v32->mHead.mParent) >> 1;
                v32 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)((unsigned __int64)v32->mHead.mParent & 0xFFFFFFFFFFFFFFFCui64);
              }
              while ( (v39 & 1) != 0 );
            }
          }
          else
          {
            for ( i = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v32->mHead.mChildren[0];
                  i != (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)i->mHead.mChildren[1];
                  i = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)i->mHead.mChildren[0] )
            {
              v32 = i;
            }
          }
        }
      }
      while ( v32 != v34 );
    }
    if ( v32 == p_mFreeTree )
      return 0i64;
    if ( v32 == v34 )
      v32 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v32->mHead.mNeighbours[1];
    v9 = (UFG::allocator::block_header *)&v32[-1].mHead.mChildren[1];
    if ( mMRFreeBlock == (UFG::allocator::block_header *)&v32[-1].mHead.mChildren[1] )
    {
      this->mMRFreeBlock = 0i64;
    }
    else if ( (v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
    {
      v40 = v32->mHead.mChildren[0];
      v41 = *(UFG::intrusive_multi_rbtree_base::node_base **)&v9->_padding[12];
      v40->mChildren[1] = v41;
      v41->mChildren[0] = v40;
      v32->mHead.mChildren[0] = &v32->mHead;
      *((_QWORD *)&v32[-1].mHead + 6) = v32;
    }
    else
    {
      UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(&this->mFreeTree, v32);
    }
    return v9;
  }
  if ( strategy != strategy_lastfit )
    goto LABEL_7;
  v16 = this->mFixedSystemPageStart;
  if ( !v16 )
    goto LABEL_7;
  v17 = v16 + 32;
  v18 = (UFG::allocator::block_header *)*((_QWORD *)this->mFixedSystemPageEnd - 4);
  if ( v18 <= (UFG::allocator::block_header *)v17 )
    goto LABEL_7;
  while ( 1 )
  {
    if ( (v18->mSizeAndFlags & 1) == 0 )
    {
      v19 = v18->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64;
      if ( v19 > size + alignment + 544 )
      {
        v20 = -(int)alignment & ((unsigned __int64)v18 + v19 - size);
        if ( v20 > (unsigned __int64)&v18->_padding[36] )
          break;
      }
    }
    v18 = v18->mPrev;
    if ( v18 <= (UFG::allocator::block_header *)v17 )
      goto LABEL_7;
  }
  if ( this->mMRFreeBlock == v18 )
  {
    this->mMRFreeBlock = 0i64;
  }
  else
  {
    v21 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)&v18->_padding[4];
    if ( (v18->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
    {
      v22 = v21->mHead.mChildren[0];
      v23 = *(UFG::intrusive_multi_rbtree_base::node_base **)&v18->_padding[12];
      v22->mChildren[1] = v23;
      v23->mChildren[0] = v22;
      v21->mHead.mChildren[0] = &v21->mHead;
      *(_QWORD *)&v18->_padding[12] = &v18->_padding[4];
    }
    else
    {
      UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(&this->mFreeTree, v21);
    }
  }
  v24 = *(_DWORD *)(v20 - 16);
  v25 = (UFG::allocator::block_header **)(v20 - 32);
  *v25 = v18;
  v26 = v24 & 3 | ((unsigned __int64)v18 + (v18->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) - (v20 - 32));
  v25[2] = (UFG::allocator::block_header *)v26;
  *(UFG::allocator::block_header **)((char *)v25 + (v26 & 0xFFFFFFFFFFFFFFFCui64) + 32) = (UFG::allocator::block_header *)v25;
  v27 = *(_QWORD *)(v20 - 32);
  *(_QWORD *)(v27 + 16) &= 3ui64;
  *(_QWORD *)(v27 + 16) |= v20 - 32 - v27 - 32;
  v25[2] = (UFG::allocator::block_header *)((unsigned __int64)v25[2] & 0xFFFFFFFFFFFFFFFEui64);
  v25[1] = 0i64;
  v28 = v18->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64;
  UFG::allocator::tree_attach(this, v18);
  return (UFG::allocator::block_header *)&v18->_padding[v28 + 4];
}

// File Line: 2204
// RVA: 0x18E4C0
void __fastcall UFG::allocator::tree_attach(UFG::allocator *this, UFG::allocator::block_header *bl)
{
  UFG::allocator::block_header *mMRFreeBlock; // rcx
  UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *v5; // rcx
  UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *mPrev; // rax

  mMRFreeBlock = this->mMRFreeBlock;
  if ( mMRFreeBlock )
  {
    if ( (mMRFreeBlock->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
    {
      v5 = (UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *)&mMRFreeBlock->_padding[4];
      mPrev = this->mSmallFreeList.mNode.mPrev;
      mPrev->mNext = v5;
      v5->mPrev = mPrev;
      v5->mNext = &this->mSmallFreeList.mNode;
      this->mSmallFreeList.mNode.mPrev = v5;
    }
    else
    {
      UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_insert(
        &this->mFreeTree,
        (UFG::allocator::free_node *)&mMRFreeBlock->_padding[4]);
    }
    this->mMRFreeBlock = bl;
  }
  else
  {
    this->mMRFreeBlock = bl;
  }
}

// File Line: 2222
// RVA: 0x18E550
void __fastcall UFG::allocator::tree_detach(UFG::allocator *this, UFG::allocator::block_header *bl)
{
  unsigned __int64 mSizeAndFlags; // rax
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v3; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v4; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v5; // rax

  if ( this->mMRFreeBlock == bl )
  {
    this->mMRFreeBlock = 0i64;
  }
  else
  {
    mSizeAndFlags = bl->mSizeAndFlags;
    v3 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)&bl->_padding[4];
    if ( (mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
    {
      v4 = v3->mHead.mChildren[0];
      v5 = v3->mHead.mChildren[1];
      v4->mChildren[1] = v5;
      v5->mChildren[0] = v4;
      v3->mHead.mChildren[0] = &v3->mHead;
      v3->mHead.mChildren[1] = &v3->mHead;
    }
    else
    {
      UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(&this->mFreeTree, v3);
    }
  }
}

// File Line: 2242
// RVA: 0x18E020
char *__fastcall UFG::allocator::tree_alloc(
        UFG::allocator *this,
        unsigned __int64 size,
        UFG::allocator::allocation_strategy strategy,
        const char *name)
{
  unsigned __int64 v8; // rbp
  UFG::allocator::block_header *v9; // rbx
  UFG::allocator::block_header *v10; // rax
  char *v12; // rdx
  int v13; // eax
  unsigned __int64 v14; // rcx
  __int64 v15; // rcx
  UFG::allocator::block_header *mMRFreeBlock; // rcx
  UFG::allocator::block_header *v17; // rdi
  UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *v18; // rcx
  UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *mPrev; // rax
  unsigned __int64 mSizeAndFlags; // rcx
  unsigned __int64 mLargeAllocHighWaterNumBytes; // rdx

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mTreeMutex);
  if ( size < 0x28 )
    size = 40i64;
  v8 = (size + 31) & 0xFFFFFFFFFFFFFFE0ui64;
  v9 = UFG::allocator::tree_extract(this, v8, strategy);
  if ( v9
    || (v10 = (UFG::allocator::block_header *)UFG::allocator::tree_system_alloc(
                                                this,
                                                (v8 + 16777311) & 0xFFFFFFFFFF000000ui64)) != 0i64
    && (v9 = UFG::allocator::tree_add_block(this, v10, (v8 + 16777311) & 0xFFFFFFFFFF000000ui64)) != 0i64 )
  {
    if ( (v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) >= v8 + 72 )
    {
      v12 = &v9->_padding[v8 + 4];
      v13 = *((_DWORD *)v12 + 4);
      *(_QWORD *)v12 = v9;
      v14 = v13 & 3 | ((v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) - (v8 + 32));
      *((_QWORD *)v12 + 2) = v14;
      *(_QWORD *)&v12[(v14 & 0xFFFFFFFFFFFFFFFCui64) + 32] = v12;
      v15 = *(_QWORD *)v12;
      *(_QWORD *)(v15 + 16) &= 3ui64;
      *(_QWORD *)(v15 + 16) |= (unsigned __int64)v9 + v8 - v15;
      *((_QWORD *)v12 + 2) &= ~1ui64;
      *((_QWORD *)v12 + 1) = 0i64;
      mMRFreeBlock = this->mMRFreeBlock;
      v17 = (UFG::allocator::block_header *)&v9->_padding[(v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) + 4];
      if ( mMRFreeBlock )
      {
        if ( (mMRFreeBlock->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
        {
          v18 = (UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *)&mMRFreeBlock->_padding[4];
          mPrev = this->mSmallFreeList.mNode.mPrev;
          mPrev->mNext = v18;
          v18->mPrev = mPrev;
          v18->mNext = &this->mSmallFreeList.mNode;
          this->mSmallFreeList.mNode.mPrev = v18;
        }
        else
        {
          UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_insert(
            &this->mFreeTree,
            (UFG::allocator::free_node *)&mMRFreeBlock->_padding[4]);
        }
      }
      this->mMRFreeBlock = v17;
    }
    v9->mSizeAndFlags |= 1ui64;
    mSizeAndFlags = v9->mSizeAndFlags;
    v9->mName = name;
    ++this->mStats.mLargeAllocNumBlocks;
    this->mStats.mLargeAllocNumBytes += (mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) + 32;
    mLargeAllocHighWaterNumBytes = this->mStats.mLargeAllocHighWaterNumBytes;
    if ( this->mStats.mLargeAllocNumBytes > mLargeAllocHighWaterNumBytes )
      mLargeAllocHighWaterNumBytes = this->mStats.mLargeAllocNumBytes;
    this->mStats.mLargeAllocHighWaterNumBytes = mLargeAllocHighWaterNumBytes;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mTreeMutex);
    return &v9->_padding[4];
  }
  else
  {
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mTreeMutex);
    return 0i64;
  }
}

// File Line: 2298
// RVA: 0x18E1F0
char *__fastcall UFG::allocator::tree_alloc_aligned(
        UFG::allocator *this,
        unsigned __int64 size,
        unsigned __int64 alignment,
        UFG::allocator::allocation_strategy strategy,
        const char *name)
{
  unsigned __int64 v9; // r14
  UFG::allocator::block_header *aligned; // rbx
  UFG::allocator::block_header *v11; // rax
  unsigned __int64 v13; // r9
  int v14; // eax
  UFG::allocator::block_header **v15; // rdx
  unsigned __int64 v16; // rcx
  UFG::allocator::block_header *v17; // rcx
  UFG::allocator::block_header *mPrev; // r8
  UFG::allocator::block_header *v19; // rdx
  __int64 v20; // rax
  unsigned __int64 v21; // rcx
  unsigned __int64 v22; // rcx
  UFG::allocator::block_header *v23; // rcx
  char *v24; // rdx
  int v25; // eax
  unsigned __int64 v26; // rcx
  __int64 v27; // rcx
  UFG::allocator::block_header *mMRFreeBlock; // rcx
  UFG::allocator::block_header *v29; // rdi
  UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *v30; // rcx
  UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *v31; // rax
  unsigned __int64 mSizeAndFlags; // rcx
  unsigned __int64 mLargeAllocHighWaterNumBytes; // rdx

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mTreeMutex);
  if ( size < 0x28 )
    size = 40i64;
  v9 = (size + 31) & 0xFFFFFFFFFFFFFFE0ui64;
  aligned = UFG::allocator::tree_extract_aligned(this, v9, alignment, strategy);
  if ( aligned
    || (v11 = (UFG::allocator::block_header *)UFG::allocator::tree_system_alloc(
                                                this,
                                                (v9 + alignment + 16777311) & 0xFFFFFFFFFF000000ui64)) != 0i64
    && (aligned = UFG::allocator::tree_add_block(this, v11, (v9 + alignment + 16777311) & 0xFFFFFFFFFF000000ui64)) != 0i64 )
  {
    v13 = (-(int)alignment & (unsigned __int64)&aligned->_padding[alignment + 3]) - (_QWORD)aligned - 32;
    if ( v13 < 0x48 )
    {
      if ( (-(int)alignment & (unsigned __int64)&aligned->_padding[alignment + 3]) - (_QWORD)aligned != 32 )
      {
        mPrev = aligned->mPrev;
        *(_QWORD *)&aligned->_padding[(aligned->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) + 4] = aligned->mPrev;
        v19 = aligned->mPrev;
        v20 = aligned->mPrev->mSizeAndFlags & 3;
        v21 = (unsigned __int64)aligned
            + (aligned->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64)
            - (unsigned __int64)aligned->mPrev;
        aligned = (UFG::allocator::block_header *)((-(int)alignment & (unsigned __int64)&aligned->_padding[alignment + 3])
                                                 - 32);
        v19->mSizeAndFlags = v20 | v21;
        LODWORD(v20) = aligned->mSizeAndFlags;
        aligned->mPrev = mPrev;
        v22 = v20 & 3 | ((unsigned __int64)mPrev + (mPrev->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) - (_QWORD)aligned);
        aligned->mSizeAndFlags = v22;
        *(_QWORD *)&aligned->_padding[(v22 & 0xFFFFFFFFFFFFFFFCui64) + 4] = aligned;
        v23 = aligned->mPrev;
        v23->mSizeAndFlags &= 3ui64;
        v23->mSizeAndFlags |= (char *)aligned - (char *)v23 - 32;
        aligned->mSizeAndFlags &= ~1ui64;
        aligned->mName = 0i64;
      }
    }
    else
    {
      v14 = *(_DWORD *)((-(int)alignment & (unsigned __int64)&aligned->_padding[alignment + 3]) - 32 + 0x10);
      v15 = (UFG::allocator::block_header **)((-(int)alignment & (unsigned __int64)&aligned->_padding[alignment + 3])
                                            - 32);
      *v15 = aligned;
      v16 = v14 & 3 | ((aligned->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) - v13);
      v15[2] = (UFG::allocator::block_header *)v16;
      *(UFG::allocator::block_header **)((char *)v15 + (v16 & 0xFFFFFFFFFFFFFFFCui64) + 32) = (UFG::allocator::block_header *)v15;
      v17 = *v15;
      v17->mSizeAndFlags &= 3ui64;
      v17->mSizeAndFlags |= (char *)v15 - (char *)v17 - 32;
      v15[2] = (UFG::allocator::block_header *)((unsigned __int64)v15[2] & 0xFFFFFFFFFFFFFFFEui64);
      v15[1] = 0i64;
      UFG::allocator::tree_attach(this, aligned);
      aligned = (UFG::allocator::block_header *)((char *)aligned + (aligned->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64)
                                                                 + 32);
    }
    if ( (aligned->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) >= v9 + 72 )
    {
      v24 = &aligned->_padding[v9 + 4];
      v25 = *((_DWORD *)v24 + 4);
      *(_QWORD *)v24 = aligned;
      v26 = v25 & 3 | ((aligned->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) - (v9 + 32));
      *((_QWORD *)v24 + 2) = v26;
      *(_QWORD *)&v24[(v26 & 0xFFFFFFFFFFFFFFFCui64) + 32] = v24;
      v27 = *(_QWORD *)v24;
      *(_QWORD *)(v27 + 16) &= 3ui64;
      *(_QWORD *)(v27 + 16) |= (unsigned __int64)aligned + v9 - v27;
      *((_QWORD *)v24 + 2) &= ~1ui64;
      *((_QWORD *)v24 + 1) = 0i64;
      mMRFreeBlock = this->mMRFreeBlock;
      v29 = (UFG::allocator::block_header *)&aligned->_padding[(aligned->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) + 4];
      if ( mMRFreeBlock )
      {
        if ( (mMRFreeBlock->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
        {
          v30 = (UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *)&mMRFreeBlock->_padding[4];
          v31 = this->mSmallFreeList.mNode.mPrev;
          v31->mNext = v30;
          v30->mPrev = v31;
          v30->mNext = &this->mSmallFreeList.mNode;
          this->mSmallFreeList.mNode.mPrev = v30;
        }
        else
        {
          UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_insert(
            &this->mFreeTree,
            (UFG::allocator::free_node *)&mMRFreeBlock->_padding[4]);
        }
      }
      this->mMRFreeBlock = v29;
    }
    aligned->mSizeAndFlags |= 1ui64;
    mSizeAndFlags = aligned->mSizeAndFlags;
    aligned->mName = name;
    ++this->mStats.mLargeAllocNumBlocks;
    this->mStats.mLargeAllocNumBytes += (mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) + 32;
    mLargeAllocHighWaterNumBytes = this->mStats.mLargeAllocHighWaterNumBytes;
    if ( this->mStats.mLargeAllocNumBytes > mLargeAllocHighWaterNumBytes )
      mLargeAllocHighWaterNumBytes = this->mStats.mLargeAllocNumBytes;
    this->mStats.mLargeAllocHighWaterNumBytes = mLargeAllocHighWaterNumBytes;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mTreeMutex);
    return &aligned->_padding[4];
  }
  else
  {
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mTreeMutex);
    return 0i64;
  }
}

// File Line: 2367
// RVA: 0x18ECC0
void __fastcall UFG::allocator::tree_free(UFG::allocator *this, UFG::allocator::block_header *ptr)
{
  __int64 v4; // r8
  UFG::allocator::block_header *v5; // rdx
  UFG::allocator::block_header *v6; // rbx

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mTreeMutex);
  v4 = *((_QWORD *)ptr - 2);
  --this->mStats.mLargeAllocNumBlocks;
  v5 = ptr - 1;
  this->mStats.mLargeAllocNumBytes += -32i64 - (v4 & 0xFFFFFFFFFFFFFFFCui64);
  v5->mSizeAndFlags &= ~1ui64;
  v5->mName = 0i64;
  v6 = UFG::allocator::coalesce_block(this, ptr - 1);
  UFG::allocator::tree_attach(this, v6);
  if ( this->mSystemMode == ACTIVE_REGION_MGT )
    UFG::allocator::tree_purge_block(this, v6);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mTreeMutex);
}

// File Line: 2400
// RVA: 0x18ED60
void __fastcall UFG::allocator::tree_purge_block(UFG::allocator *this, UFG::allocator::block_header *bl)
{
  unsigned __int64 v4; // rax
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v5; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v6; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v7; // rax
  _QWORD *v8; // rax
  __int64 v9; // rdx
  UFG::allocator::block_header *v10; // rcx
  __int64 v11; // rax

  if ( !bl->mPrev->mPrev )
  {
    v4 = bl->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64;
    if ( (*(_QWORD *)&bl->_padding[v4 + 20] & 0xFFFFFFFFFFFFFFFCui64) == 0 )
    {
      if ( this->mMRFreeBlock == bl )
      {
        this->mMRFreeBlock = 0i64;
      }
      else
      {
        v5 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)&bl->_padding[4];
        if ( v4 <= 0x28 )
        {
          v6 = v5->mHead.mChildren[0];
          v7 = v5->mHead.mChildren[1];
          v6->mChildren[1] = v7;
          v7->mChildren[0] = v6;
          v5->mHead.mChildren[0] = &v5->mHead;
          v5->mHead.mChildren[1] = &v5->mHead;
        }
        else
        {
          UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(&this->mFreeTree, v5);
        }
      }
      if ( this->mSystemMode )
      {
        v8 = (_QWORD *)*((_QWORD *)bl->mPrev - 3);
        v9 = *((_QWORD *)bl->mPrev - 4);
        v10 = bl->mPrev - 1;
        *(_QWORD *)(v9 + 8) = v8;
        *v8 = v9;
        v10->mPrev = v10;
        v10->mName = (const char *)v10;
        v11 = -32i64 - v10->mSizeAndFlags;
        --this->mStats.mSystemPageNumPages;
        this->mStats.mSystemPageNumBytes += v11;
        this->mStats.mLargePoolNumBytes += 32 - v10->mSizeAndFlags;
        UFG::qSystemFree(v10);
      }
    }
  }
}

