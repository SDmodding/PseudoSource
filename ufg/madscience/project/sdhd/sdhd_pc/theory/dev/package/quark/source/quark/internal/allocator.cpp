// File Line: 81
// RVA: 0x1814C0
void __fastcall UFG::intrusive_multi_rbtree_base::insert_fixup(UFG::intrusive_multi_rbtree_base *this, UFG::intrusive_multi_rbtree_base::node_base *node)
{
  UFG::intrusive_multi_rbtree_base::node_base *v2; // r13
  UFG::intrusive_multi_rbtree_base *v3; // r12
  unsigned __int64 v4; // rdi
  __int64 *i; // rsi
  signed __int64 v6; // rbp
  unsigned __int64 v7; // rax
  int v8; // er14
  signed __int64 v9; // r15
  __int64 v10; // rcx
  unsigned __int64 v11; // r11
  __int64 v12; // r9
  __int64 v13; // rbx
  __int64 *v14; // r8
  __int64 v15; // rdx
  __int64 v16; // r8
  signed __int64 v17; // r11
  __int64 v18; // r11
  signed __int64 v19; // r10
  __int64 *v20; // r8
  __int64 v21; // rbx
  __int64 v22; // rdx
  __int64 v23; // r8

  v2 = node;
  v3 = this;
  v4 = (_QWORD)node->mParent & 0xFFFFFFFFFFFFFFFCui64;
  for ( i = (__int64 *)(v4 + 32); *(_BYTE *)(v4 + 32) & 1; i = (__int64 *)(v4 + 32) )
  {
    v6 = ((unsigned __int64)*i >> 1) & 1;
    v7 = *i & 0xFFFFFFFFFFFFFFFCui64;
    v8 = 1 - v6;
    v9 = 8i64 * (1 - (signed int)v6);
    v10 = *(_QWORD *)(v9 + v7);
    if ( *(_BYTE *)(v10 + 32) & 1 )
    {
      *i &= 0xFFFFFFFFFFFFFFFEui64;
      *(_QWORD *)(v10 + 32) &= 0xFFFFFFFFFFFFFFFEui64;
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
        v15 = *(_QWORD *)(v13 + 8i64 * (signed int)v6);
        *v14 = v15;
        *(_QWORD *)(v15 + 32) &= 3ui64;
        *(_QWORD *)(v15 + 32) |= v4 & 0xFFFFFFFFFFFFFFFCui64;
        v16 = *v14;
        *(_QWORD *)(v16 + 32) &= 0xFFFFFFFFFFFFFFFDui64;
        *(_QWORD *)(v16 + 32) |= 2 * v8;
        *(_QWORD *)(v13 + 32) &= 1ui64;
        v17 = (v11 >> 1) & 1;
        v2 = (UFG::intrusive_multi_rbtree_base::node_base *)v4;
        *(_QWORD *)(v13 + 32) |= v12 & 0xFFFFFFFFFFFFFFFCui64 | 2 * (signed int)v17;
        *(_QWORD *)((*i & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (signed int)v17) = v13;
        *(_QWORD *)(v13 + 8i64 * (signed int)v6) = v4;
        *i &= 1ui64;
        *i |= v13 & 0xFFFFFFFFFFFFFFFCui64 | 2 * (signed int)v6;
        v4 = *i & 0xFFFFFFFFFFFFFFFCui64;
      }
      *(_QWORD *)(v4 + 32) &= 0xFFFFFFFFFFFFFFFEui64;
      *(_QWORD *)(v7 + 32) |= 1ui64;
      v18 = *(_QWORD *)(v7 + 32);
      v19 = (*(_QWORD *)(v7 + 32) >> 1) & 1i64;
      v20 = (__int64 *)(v7 + 8i64 * (signed int)v6);
      v21 = *v20;
      v22 = *(_QWORD *)(v9 + *v20);
      *v20 = v22;
      *(_QWORD *)(v22 + 32) &= 3ui64;
      *(_QWORD *)(v22 + 32) |= v7 & 0xFFFFFFFFFFFFFFFCui64;
      v23 = *v20;
      *(_QWORD *)(v23 + 32) &= 0xFFFFFFFFFFFFFFFDui64;
      *(_QWORD *)(v23 + 32) |= 2 * (signed int)v6;
      *(_QWORD *)(v21 + 32) &= 1ui64;
      *(_QWORD *)(v21 + 32) |= v18 & 0xFFFFFFFFFFFFFFFCui64 | 2 * (signed int)v19;
      *(_QWORD *)((*(_QWORD *)(v7 + 32) & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (signed int)v19) = v21;
      *(_QWORD *)(v9 + v21) = v7;
      *(_QWORD *)(v7 + 32) &= 1ui64;
      *(_QWORD *)(v7 + 32) |= v21 & 0xFFFFFFFFFFFFFFFCui64 | 2 * v8;
    }
  }
  v3->mHead.mChildren[0]->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v3->mHead.mChildren[0]->mParent & 0xFFFFFFFFFFFFFFFEui64);
}

// File Line: 110
// RVA: 0x180D00
void __fastcall UFG::intrusive_multi_rbtree_base::erase_fixup(UFG::intrusive_multi_rbtree_base *this, UFG::intrusive_multi_rbtree_base::node_base *node)
{
  UFG::intrusive_multi_rbtree_base *v2; // r12
  unsigned __int64 v3; // rbp
  unsigned __int64 v4; // rdx
  signed __int64 v5; // rbp
  int v6; // er14
  unsigned __int64 v7; // r15
  UFG::intrusive_multi_rbtree_base::node_base *v8; // rsi
  signed __int64 v9; // rcx
  unsigned __int64 v10; // r11
  UFG::intrusive_multi_rbtree_base::node_base **v11; // r8
  UFG::intrusive_multi_rbtree_base::node_base **v12; // r9
  signed __int64 v13; // r10
  unsigned __int64 v14; // rbx
  UFG::intrusive_multi_rbtree_base::node_base *v15; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v16; // r8
  signed __int64 v17; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v18; // rdi
  UFG::intrusive_multi_rbtree_base::node_base *v19; // rbx
  unsigned __int64 v20; // r11
  UFG::intrusive_multi_rbtree_base::node_base **v21; // r8
  UFG::intrusive_multi_rbtree_base::node_base *v22; // rcx
  __int64 v23; // r10
  UFG::intrusive_multi_rbtree_base::node_base *v24; // r8
  unsigned __int64 v25; // rbx
  UFG::intrusive_multi_rbtree_base::node_base **v26; // r8
  int v27; // er11
  unsigned __int64 v28; // r9
  UFG::intrusive_multi_rbtree_base::node_base **v29; // r10
  UFG::intrusive_multi_rbtree_base::node_base *v30; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v31; // r8

  v2 = this;
  if ( (_QWORD)node->mParent & 1 )
  {
    node->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)node->mParent & 0xFFFFFFFFFFFFFFFEui64);
  }
  else
  {
    do
    {
      if ( node == v2->mHead.mChildren[0] )
        break;
      v3 = (unsigned __int64)node->mParent;
      v4 = v3;
      v5 = (v3 >> 1) & 1;
      node = (UFG::intrusive_multi_rbtree_base::node_base *)(v4 & 0xFFFFFFFFFFFFFFFCui64);
      v6 = 1 - v5;
      v7 = 1 - (signed int)v5;
      v8 = node->mChildren[v7];
      if ( (_QWORD)v8->mParent & 1 )
      {
        v8->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v8->mParent & 0xFFFFFFFFFFFFFFFEui64);
        node->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)node->mParent | 1i64);
        v9 = 8i64 * (signed int)v5;
        v8 = v8->mChildren[(unsigned __int64)v9 / 8];
        v10 = (unsigned __int64)node->mChildren[v6];
        v11 = &node->mChildren[v6];
        v12 = (UFG::intrusive_multi_rbtree_base::node_base **)(v9 + v10);
        v13 = ((_QWORD)node->mParent >> 1) & 1i64;
        v14 = (_QWORD)node->mParent & 0xFFFFFFFFFFFFFFFCui64;
        v15 = *(UFG::intrusive_multi_rbtree_base::node_base **)(v9 + v10);
        *v11 = v15;
        v15->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v15->mParent & 3i64);
        v15->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v15->mParent | (unsigned __int64)node & 0xFFFFFFFFFFFFFFFCui64);
        v16 = *v11;
        v16->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v16->mParent & 0xFFFFFFFFFFFFFFFDui64);
        v16->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v16->mParent | 2 * v6);
        *(_QWORD *)(v10 + 32) &= 1ui64;
        *(_QWORD *)(v10 + 32) |= v14 | 2 * (signed int)v13;
        *(_QWORD *)(((_QWORD)node->mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (signed int)v13) = v10;
        *v12 = node;
        node->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)node->mParent & 1i64);
        node->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)node->mParent | v10 & 0xFFFFFFFFFFFFFFFCui64 | 2 * (signed int)v5);
      }
      if ( ~LOBYTE(v8->mChildren[0]->mParent) & 1 && ~LOBYTE(v8->mChildren[1]->mParent) & 1 )
      {
        v8->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v8->mParent | 1i64);
      }
      else
      {
        if ( ~LOBYTE(v8->mChildren[v7]->mParent) & 1 )
        {
          v17 = (signed __int64)&v8->mChildren[(signed int)v5];
          *(_QWORD *)(*(_QWORD *)v17 + 32i64) &= 0xFFFFFFFFFFFFFFFEui64;
          v8->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v8->mParent | 1i64);
          v18 = *(UFG::intrusive_multi_rbtree_base::node_base **)v17;
          v19 = v8->mParent;
          v20 = (unsigned __int64)v8->mChildren[(signed int)v5];
          v21 = &v8->mChildren[(signed int)v5];
          v22 = *(UFG::intrusive_multi_rbtree_base::node_base **)(v7 * 8 + v20);
          v23 = (_QWORD)v8->mParent >> 1;
          *v21 = v22;
          v22->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v22->mParent & 3i64);
          v22->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v22->mParent | (unsigned __int64)v8 & 0xFFFFFFFFFFFFFFFCui64);
          v24 = *v21;
          v24->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v24->mParent & 0xFFFFFFFFFFFFFFFDui64);
          LODWORD(v23) = v23 & 1;
          v24->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v24->mParent | 2 * (signed int)v5);
          *(_QWORD *)(v20 + 32) &= 1ui64;
          *(_QWORD *)(v20 + 32) |= (unsigned __int64)v19 & 0xFFFFFFFFFFFFFFFCui64 | 2 * (signed int)v23;
          *(_QWORD *)(((_QWORD)v8->mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * (signed int)v23) = v20;
          *(_QWORD *)(v7 * 8 + v20) = v8;
          v8->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v8->mParent & 1i64);
          v8->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v8->mParent | v20 & 0xFFFFFFFFFFFFFFFCui64 | 2 * v6);
          v8 = v18;
        }
        v8->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v8->mParent ^ (LODWORD(v8->mParent) ^ LODWORD(node->mParent)) & 1);
        node->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)node->mParent & 0xFFFFFFFFFFFFFFFEui64);
        v8->mChildren[v7]->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v8->mChildren[v7]->mParent & 0xFFFFFFFFFFFFFFFEui64);
        v25 = (unsigned __int64)node->mChildren[v6];
        v26 = &node->mChildren[v6];
        v27 = (LODWORD(node->mParent) >> 1) & 1;
        v28 = (_QWORD)node->mParent & 0xFFFFFFFFFFFFFFFCui64;
        v29 = (UFG::intrusive_multi_rbtree_base::node_base **)(v25 + 8i64 * (signed int)v5);
        v30 = *v29;
        *v26 = *v29;
        v30->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v30->mParent & 3i64);
        v30->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v30->mParent | (unsigned __int64)node & 0xFFFFFFFFFFFFFFFCui64);
        v31 = *v26;
        v31->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v31->mParent & 0xFFFFFFFFFFFFFFFDui64);
        v31->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)v31->mParent | 2 * v6);
        *(_QWORD *)(v25 + 32) &= 1ui64;
        *(_QWORD *)(v25 + 32) |= v28 | 2 * v27;
        *(_QWORD *)(((_QWORD)node->mParent & 0xFFFFFFFFFFFFFFFCui64) + 8i64 * v27) = v25;
        *v29 = node;
        node->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)node->mParent & 1i64);
        node->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)node->mParent | v25 & 0xFFFFFFFFFFFFFFFCui64 | 2 * (signed int)v5);
        node = v2->mHead.mChildren[0];
      }
    }
    while ( !((_QWORD)node->mParent & 1) );
    node->mParent = (UFG::intrusive_multi_rbtree_base::node_base *)((_QWORD)node->mParent & 0xFFFFFFFFFFFFFFFEui64);
  }
}

// File Line: 181
// RVA: 0x160B20
void __fastcall UFG::allocator::allocator(UFG::allocator *this)
{
  UFG::allocator *v1; // rbx
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v2; // rax
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *v3; // [rsp+58h] [rbp+10h]
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *v4; // [rsp+58h] [rbp+10h]
  UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *v5; // [rsp+58h] [rbp+10h]
  UFG::qList<UFG::allocator::small_free_node,UFG::allocator::small_free_node,1,0> *v6; // [rsp+58h] [rbp+10h]

  v1 = this;
  v3 = &this->mSystemPages;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  v4 = &this->mSmallBlockSystemPages;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  `eh vector constructor iterator'(
    this->mBuckets,
    0x80ui64,
    32,
    (void (__fastcall *)(void *))UFG::allocator::bucket::bucket);
  v5 = &v1->mBucketFreePages;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  UFG::qMutex::qMutex(&v1->mBucketFreePagesMutex, "allocator.mBucketFreePagesMutex");
  v2 = &v1->mFreeTree;
  v2->mHead.mParent = &v2->mHead;
  v2->mHead.mChildren[0] = &v2->mHead;
  v2->mHead.mChildren[1] = &v2->mHead;
  v2->mHead.mNeighbours[0] = &v2->mHead;
  v2->mHead.mNeighbours[1] = &v2->mHead;
  v6 = &v1->mSmallFreeList;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  UFG::qMutex::qMutex(&v1->mTreeMutex, "allocator.mTreeMutex");
  v1->mTreeMutexLockCount = 0;
  *(_QWORD *)&v1->mLargeBlockMemoryPlatformAllocated = 0i64;
  v1->mAllocationNumber = 0;
  v1->mSystemMode = 0;
  v1->mFixedSystemPageStart = 0i64;
  v1->mFixedSystemPageEnd = 0i64;
  v1->mSmallBlockStart = 0i64;
  v1->mSmallBlockEnd = 0i64;
  v1->mMRFreeBlock = 0i64;
  *(_QWORD *)&v1->mReportBucketIndex = -1i64;
  v1->mReportSmallPage = 0i64;
  v1->mReportSmallSlot = -1;
  v1->mReportLargeSystemPage = 0i64;
  v1->mReportLargeBlock = 0i64;
  UFG::qMemSet(&v1->mStats, 0, 0x78u);
}

// File Line: 215
// RVA: 0x163270
void __fastcall UFG::allocator::~allocator(UFG::allocator *this)
{
  UFG::allocator *v1; // rdi
  bool v2; // zf
  UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *v3; // rcx
  UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *v4; // rax
  UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *v5; // r8
  UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *v6; // rdx
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v7; // rcx
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v8; // rax
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v9; // rcx
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v10; // rax
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *v11; // r8
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *v12; // rdx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v13; // rcx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v14; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v15; // rcx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v16; // rax
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *v17; // r8
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *v18; // rdx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v19; // rcx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v20; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v21; // rcx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v22; // rax

  v1 = this;
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
  UFG::qPrintf("ERROR: All allocs must be free'd before a qMemoryPool can be Closed()! Name = '%s' \n", this->mName);
LABEL_7:
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v1->mTreeMutex);
  UFG::qList<UFG::qTaskFunctionDecl,UFG::qTaskFunctionDecl,1,0>::DeleteNodes((UFG::qList<UFG::tChunkPosition,UFG::tChunkPosition,1,0> *)&v1->mSmallFreeList);
  v3 = v1->mSmallFreeList.mNode.mPrev;
  v4 = v1->mSmallFreeList.mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v1->mSmallFreeList.mNode.mPrev = &v1->mSmallFreeList.mNode;
  v1->mSmallFreeList.mNode.mNext = &v1->mSmallFreeList.mNode;
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::clear(&v1->mFreeTree);
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v1->mBucketFreePagesMutex);
  v5 = &v1->mBucketFreePages;
  v6 = (UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *)v1->mBucketFreePages.mNode.mNext;
  if ( v6 != &v1->mBucketFreePages )
  {
    do
    {
      v7 = v6->mNode.mPrev;
      v8 = v6->mNode.mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mNode.mPrev = &v6->mNode;
      v6->mNode.mNext = &v6->mNode;
      v6 = (UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *)v1->mBucketFreePages.mNode.mNext;
    }
    while ( v6 != v5 );
  }
  v9 = v5->mNode.mPrev;
  v10 = v1->mBucketFreePages.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v5->mNode.mPrev = &v5->mNode;
  v1->mBucketFreePages.mNode.mNext = &v1->mBucketFreePages.mNode;
  `eh vector destructor iterator'(
    v1->mBuckets,
    0x80ui64,
    32,
    (void (__fastcall *)(void *))UFG::allocator::bucket::~bucket);
  v11 = &v1->mSmallBlockSystemPages;
  v12 = (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)v1->mSmallBlockSystemPages.mNode.mNext;
  if ( v12 != &v1->mSmallBlockSystemPages )
  {
    do
    {
      v13 = v12->mNode.mPrev;
      v14 = v12->mNode.mNext;
      v13->mNext = v14;
      v14->mPrev = v13;
      v12->mNode.mPrev = &v12->mNode;
      v12->mNode.mNext = &v12->mNode;
      v12 = (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)v1->mSmallBlockSystemPages.mNode.mNext;
    }
    while ( v12 != v11 );
  }
  v15 = v11->mNode.mPrev;
  v16 = v1->mSmallBlockSystemPages.mNode.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v11->mNode.mPrev = &v11->mNode;
  v1->mSmallBlockSystemPages.mNode.mNext = &v1->mSmallBlockSystemPages.mNode;
  v17 = &v1->mSystemPages;
  v18 = (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)v1->mSystemPages.mNode.mNext;
  if ( v18 != &v1->mSystemPages )
  {
    do
    {
      v19 = v18->mNode.mPrev;
      v20 = v18->mNode.mNext;
      v19->mNext = v20;
      v20->mPrev = v19;
      v18->mNode.mPrev = &v18->mNode;
      v18->mNode.mNext = &v18->mNode;
      v18 = (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)v1->mSystemPages.mNode.mNext;
    }
    while ( v18 != v17 );
  }
  v21 = v17->mNode.mPrev;
  v22 = v1->mSystemPages.mNode.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  v17->mNode.mPrev = &v17->mNode;
  v1->mSystemPages.mNode.mNext = &v1->mSystemPages.mNode;
}

// File Line: 240
// RVA: 0x1812D0
void __fastcall UFG::allocator::init(UFG::allocator *this, const char *name, char *large_block_memory, unsigned __int64 large_block_byte_size, unsigned __int64 small_block_byte_size, int can_small_block_overflow_into_large_block)
{
  unsigned __int64 v6; // r12
  char *v7; // r15
  const char *v8; // rbp
  UFG::allocator *v9; // r14
  const char *v10; // rax
  __int64 *v11; // rcx
  unsigned __int64 v12; // rsi
  __int64 v13; // rax
  UFG::allocator::block_header *v14; // rdi
  unsigned __int64 v15; // rcx
  UFG::allocator::system_mode v16; // eax
  unsigned __int64 v17; // rcx
  unsigned __int64 v18; // rax
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rbx
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v21; // rax

  v6 = large_block_byte_size;
  v7 = large_block_memory;
  v8 = name;
  v9 = this;
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
      v11 = (__int64 *)&this->mSystemPages;
      v12 = large_block_byte_size - 32;
      *((_QWORD *)large_block_memory + 2) = large_block_byte_size - 32;
      v13 = *v11;
      *(_QWORD *)(v13 + 8) = large_block_memory;
      *((_QWORD *)large_block_memory + 1) = v11;
      *(_QWORD *)large_block_memory = v13;
      *v11 = (__int64)large_block_memory;
      v9->mFixedSystemPageStart = large_block_memory;
      v9->mFixedSystemPageEnd = &large_block_memory[*((_QWORD *)large_block_memory + 2) + 32];
      v14 = UFG::allocator::tree_add_block(v9, large_block_memory + 32, *((_QWORD *)large_block_memory + 2));
      UFG::qMemSet(&v14[1], 0xDEDEDEDE, v14->mSizeAndFlags & 0xFFFFFFFC);
      v14->mSizeAndFlags |= 1ui64;
      v14->mName = &customWorldMapCaption;
      UFG::allocator::tree_free(v9, &v14[1]);
      v15 = v9->mStats.mLinearAllocNumBytes;
      v9->mStats.mLargePoolNumBytes = v12;
      v9->mStats.mSystemPageNumBytes = v6 + v15;
      v9->mStats.mLargeAllocNumBytes = 0i64;
      v9->mStats.mLargeAllocNumBlocks = 0i64;
      v9->mStats.mLargeAllocHighWaterNumBytes = 0i64;
      v9->mStats.mSystemPageNumPages = 1i64;
    }
    else
    {
      this->mSystemMode = 1;
    }
    v16 = v9->mSystemMode;
    if ( v16 )
    {
      if ( v16 == 1 )
      {
        v9->mCanSmallBlockOverflowIntoLargeBlock = 0;
        v9->mSmallBlockStart = 0i64;
        v9->mSmallBlockEnd = 0i64;
        UFG::allocator::bucket_system_alloc(v9, 0xFFC000ui64);
      }
    }
    else
    {
      if ( small_block_byte_size )
      {
        v17 = (unsigned __int64)(v7 + 8287) & 0xFFFFFFFFFFFFE000ui64;
        v18 = (unsigned __int64)&v7[v6 - 8224] & 0xFFFFFFFFFFFFE000ui64;
        if ( v18 <= v17 )
        {
          UFG::qPrintf("WARNING: no space for small blocks in pool '%s'\n", v8);
        }
        else
        {
          v19 = v18 - v17;
          v20 = (small_block_byte_size + 0x1FFF) & 0xFFFFFFFFFFFFE000ui64;
          if ( v20 >= v19 )
            v20 = v19;
          if ( v20 )
          {
            v21 = UFG::allocator::bucket_system_alloc(v9, v20);
            v9->mSmallBlockStart = (char *)v21;
            v9->mCanSmallBlockOverflowIntoLargeBlock = can_small_block_overflow_into_large_block;
            v9->mSmallBlockEnd = (char *)v21 + v20;
            return;
          }
        }
      }
      v9->mCanSmallBlockOverflowIntoLargeBlock = 1;
      v9->mSmallBlockStart = 0i64;
      v9->mSmallBlockEnd = 0i64;
    }
  }
}

// File Line: 400
// RVA: 0x181080
signed __int64 __fastcall UFG::allocator::get_largest_free_size(UFG::allocator *this)
{
  UFG::allocator *v1; // rsi
  UFG::intrusive_multi_rbtree_base::node_base *v2; // rax
  UFG::allocator *v3; // r8
  UFG::intrusive_multi_rbtree_base::node_base *i; // rdx
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rdi
  UFG::allocator::block_header *v7; // rax

  v1 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mTreeMutex);
  v2 = v1->mFreeTree.mHead.mChildren[0];
  v3 = (UFG::allocator *)v2;
  for ( i = v2->mChildren[1]; v2 != i; i = i->mChildren[1] )
  {
    v3 = (UFG::allocator *)v2;
    v2 = i;
  }
  v5 = 0i64;
  if ( v3 == (UFG::allocator *)&v1->mFreeTree || v3 == (UFG::allocator *)32 )
    v6 = 0i64;
  else
    v6 = (_QWORD)v3[-1].mReportLargeSystemPage & 0xFFFFFFFFFFFFFFFCui64;
  v7 = v1->mMRFreeBlock;
  if ( v7 )
    v5 = v7->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mTreeMutex);
  if ( v6 > v5 )
    v5 = v6;
  return v5 - 32;
}

// File Line: 491
// RVA: 0x18D5E0
char __fastcall UFG::allocator::report_begin(UFG::allocator *this)
{
  UFG::allocator *v1; // rdi
  int v2; // ebx
  __int64 v3; // rax

  v1 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mTreeMutex);
  v2 = 0;
  v3 = 0i64;
  do
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mBuckets[v3]);
    v3 = ++v2;
  }
  while ( (unsigned __int64)v2 < 0x20 );
  return 1;
}

// File Line: 579
// RVA: 0x18D750
char __fastcall UFG::allocator::report_get_first_small_block_info(UFG::allocator *this, UFG::MemoryPoolSmallBlockInfo *info, int bucket_index)
{
  UFG::allocator::page *v3; // rax
  char result; // al

  this->mReportSmallBucketIndex = -1;
  this->mReportSmallSlot = -1;
  this->mReportSmallPage = 0i64;
  if ( !info )
    return 0;
  if ( bucket_index < 0 || (unsigned __int64)bucket_index >= 0x20 )
    return 0;
  if ( *((UFG::allocator **)&this->mLargeBlockMemoryPlatformAllocated + 16 * (bucket_index + 2i64)) == (UFG::allocator *)((char *)this + 128 * (bucket_index + 2i64)) )
    return 0;
  v3 = (UFG::allocator::page *)this->mBuckets[(signed __int64)bucket_index].mPageList.mNode.mNext;
  if ( !v3 )
    return 0;
  this->mReportSmallPage = v3;
  this->mReportSmallBucketIndex = bucket_index;
  this->mReportSmallSlot = 0;
  info->mBucketIndex = bucket_index;
  info->mPointer = (void *)((unsigned __int64)v3 & 0xFFFFFFFFFFFFE000ui64);
  info->mName = &customWorldMapCaption;
  *(_WORD *)&info->mIsFreeBlock = 0;
  result = 1;
  info->mNumBytes = 16i64 * (unsigned int)(bucket_index + 1);
  return result;
}

// File Line: 619
// RVA: 0x18D930
char __fastcall UFG::allocator::report_get_next_small_block_info(UFG::allocator *this, UFG::MemoryPoolSmallBlockInfo *info)
{
  __int64 v2; // r10
  UFG::allocator::page *v3; // r9
  char result; // al
  int v5; // er8
  __int64 v6; // rcx

  v2 = this->mReportSmallBucketIndex;
  v3 = this->mReportSmallPage;
  if ( info == 0i64 || (signed int)v2 < 0 )
    return 0;
  v5 = this->mReportSmallSlot + 1;
  if ( v5 == 0x1FE0 / (16 * (unsigned __int64)((unsigned int)v3->mBucketIndex + 1) + 8) - 1 )
  {
    v3 = (UFG::allocator::page *)v3->mNext;
    if ( v3 == (UFG::allocator::page *)((char *)this + 128 * (v2 + 2)) )
    {
      LODWORD(v2) = -1;
      v3 = 0i64;
      v5 = -1;
    }
    else
    {
      v5 = 0;
    }
  }
  this->mReportSmallBucketIndex = v2;
  this->mReportSmallPage = v3;
  this->mReportSmallSlot = v5;
  if ( (signed int)v2 < 0 )
    return 0;
  info->mName = &customWorldMapCaption;
  v6 = (unsigned int)v3->mBucketIndex + 1;
  info->mBucketIndex = v2;
  *(_WORD *)&info->mIsFreeBlock = 0;
  info->mPointer = (void *)(((unsigned __int64)v3 & 0xFFFFFFFFFFFFE000ui64) + v5 * 16 * v6);
  result = 1;
  info->mNumBytes = 16i64 * (unsigned int)(v2 + 1);
  return result;
}

// File Line: 671
// RVA: 0x18D650
char __fastcall UFG::allocator::report_get_first_large_block_info(UFG::allocator *this, UFG::MemoryPoolLargeBlockInfo *info)
{
  int v2; // er9
  UFG::MemoryPoolLargeBlockInfo *v3; // rbx
  UFG::allocator *v4; // r11
  char result; // al
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *v6; // r10
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v7; // rdx
  unsigned __int64 v8; // rax
  char *v9; // r8
  unsigned __int64 v10; // rcx
  bool v11; // zf
  unsigned int v12; // ecx

  v2 = 0;
  v3 = info;
  v4 = this;
  this->mReportLargeSystemPage = 0i64;
  this->mReportLargeBlock = 0i64;
  if ( !info )
    return 0;
  v6 = &this->mSystemPages;
  if ( (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)this->mSystemPages.mNode.mNext == &this->mSystemPages )
    v7 = 0i64;
  else
    v7 = this->mSystemPages.mNode.mNext;
  v8 = 0i64;
  if ( v7 )
  {
    while ( !v8 )
    {
      v8 = (unsigned __int64)&v7[2];
      v9 = (char *)v7 + (unsigned __int64)v7[1].mPrev;
      v10 = (_QWORD)v7[3].mPrev & 0xFFFFFFFFFFFFFFFCui64;
      if ( v10 )
      {
LABEL_11:
        v11 = v8 == (_QWORD)v9;
      }
      else
      {
        while ( 1 )
        {
          v11 = v8 == (_QWORD)v9;
          if ( v8 >= (unsigned __int64)v9 )
            break;
          v8 += v10 + 32;
          v10 = *(_QWORD *)(v8 + 16) & 0xFFFFFFFFFFFFFFFCui64;
          if ( v10 )
            goto LABEL_11;
        }
      }
      if ( v11 )
      {
        v7 = v7->mNext;
        v8 = 0i64;
        if ( v7 == (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)v6 )
        {
          v7 = 0i64;
          break;
        }
      }
      if ( !v7 )
        break;
    }
  }
  v4->mReportLargeSystemPage = (UFG::allocator::system_page_header *)v7;
  v4->mReportLargeBlock = (UFG::allocator::block_header *)v8;
  LOBYTE(v2) = v7 == 0i64;
  if ( v2 | (v8 == 0) )
    return 0;
  v3->mName = *(const char **)(v8 + 8);
  v3->mPointer = (void *)(v8 + 32);
  v3->mNumBytes = *(_QWORD *)(v8 + 16) & 0xFFFFFFFFFFFFFFFCui64;
  v3->mIsFreeBlock = ~*(_BYTE *)(v8 + 16) & 1;
  v12 = *(_DWORD *)(v8 + 16);
  result = 1;
  v3->mIsMarked = (v12 >> 1) & 1;
  return result;
}

// File Line: 736
// RVA: 0x18D800
char __fastcall UFG::allocator::report_get_next_large_block_info(UFG::allocator *this, UFG::MemoryPoolLargeBlockInfo *info)
{
  UFG::MemoryPoolLargeBlockInfo *v2; // rbx
  UFG::allocator *v3; // r11
  char result; // al
  UFG::allocator::block_header *v5; // r10
  UFG::allocator::system_page_header *v6; // r8
  int v7; // er9
  unsigned __int64 v8; // rax
  char *v9; // rdx
  unsigned __int64 v10; // rcx
  bool v11; // zf
  unsigned int v12; // ecx

  v2 = info;
  v3 = this;
  if ( !info )
    return 0;
  v5 = this->mReportLargeBlock;
  v6 = this->mReportLargeSystemPage;
  v7 = 0;
  v8 = 0i64;
  if ( v6 != 0i64 && v5 != 0i64 )
  {
    do
    {
      v9 = (char *)v6 + v6->mByteSize;
      v8 = (unsigned __int64)&v5[1] + (v5->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64);
      v10 = *(_QWORD *)(v8 + 16) & 0xFFFFFFFFFFFFFFFCui64;
      if ( v10 )
      {
LABEL_7:
        v11 = v8 == (_QWORD)v9;
      }
      else
      {
        while ( 1 )
        {
          v11 = v8 == (_QWORD)v9;
          if ( v8 >= (unsigned __int64)v9 )
            break;
          v8 += v10 + 32;
          v10 = *(_QWORD *)(v8 + 16) & 0xFFFFFFFFFFFFFFFCui64;
          if ( v10 )
            goto LABEL_7;
        }
      }
      if ( v11 )
      {
        v6 = (UFG::allocator::system_page_header *)v6->mNext;
        if ( v6 == (UFG::allocator::system_page_header *)&v3->mSystemPages )
        {
          v6 = 0i64;
          v5 = 0i64;
        }
        else
        {
          v5 = (UFG::allocator::block_header *)&v6[1];
        }
        v8 = 0i64;
      }
    }
    while ( v5 != 0i64 && v8 == 0 && v6 != 0i64 );
  }
  v3->mReportLargeSystemPage = v6;
  v3->mReportLargeBlock = (UFG::allocator::block_header *)v8;
  LOBYTE(v7) = v6 == 0i64;
  if ( v7 | (v8 == 0) )
    return 0;
  v2->mName = *(const char **)(v8 + 8);
  v2->mPointer = (void *)(v8 + 32);
  v2->mNumBytes = *(_QWORD *)(v8 + 16) & 0xFFFFFFFFFFFFFFFCui64;
  v2->mIsFreeBlock = ~*(_BYTE *)(v8 + 16) & 1;
  v12 = *(_DWORD *)(v8 + 16);
  result = 1;
  v2->mIsMarked = (v12 >> 1) & 1;
  return result;
}

// File Line: 808
// RVA: 0x18DD40
void __fastcall UFG::allocator::set_mark(UFG::allocator *this)
{
  int v1; // ebx
  UFG::allocator *v2; // rdi
  int v3; // esi
  __int64 v4; // rax
  int v5; // er8
  __int64 v6; // rax
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> **v7; // r9
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v8; // rcx
  signed __int64 v9; // rdx
  __int64 v10; // rax
  _RTL_CRITICAL_SECTION *v11; // rbx
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v12; // r8
  signed __int64 i; // rdi
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // r9
  __int64 v16; // rcx

  v1 = 0;
  v2 = this;
  v3 = 0;
  v4 = 0i64;
  do
  {
    UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mBuckets[v4]);
    v4 = ++v3;
  }
  while ( (unsigned __int64)v3 < 0x20 );
  v5 = 0;
  v6 = 0i64;
  v7 = &v2->mBuckets[0].mPageList.mNode.mNext;
  do
  {
    v8 = *v7;
    v9 = (signed __int64)v2 + 128 * (v6 + 2);
    if ( *v7 != (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)v9 )
    {
      do
        v8 = v8->mNext;
      while ( v8 != (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)v9 );
    }
    ++v5;
    v7 += 16;
    v6 = v5;
  }
  while ( (unsigned __int64)v5 < 0x20 );
  v10 = 0i64;
  do
  {
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->mBuckets[v10]);
    v10 = ++v1;
  }
  while ( (unsigned __int64)v1 < 0x20 );
  v11 = (_RTL_CRITICAL_SECTION *)&v2->mTreeMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mTreeMutex);
  v12 = v2->mSystemPages.mNode.mNext;
  for ( i = (signed __int64)&v2->mSystemPages;
        v12 != (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)i;
        v12 = v12->mNext )
  {
    v14 = (unsigned __int64)&v12[2];
    v15 = (unsigned __int64)v12 + (unsigned __int64)v12[1].mPrev;
    if ( (unsigned __int64)&v12[2] < v15 )
    {
      do
      {
        v16 = *(_QWORD *)(v14 + 16);
        if ( v16 & 0xFFFFFFFFFFFFFFFCui64 )
          *(_QWORD *)(v14 + 16) = v16 | 2;
        v14 += (*(_QWORD *)(v14 + 16) & 0xFFFFFFFFFFFFFFFCui64) + 32;
      }
      while ( v14 < v15 );
    }
  }
  UFG::qMutex::Unlock(v11);
}

// File Line: 905
// RVA: 0x181150
__int64 __fastcall UFG::allocator::get_unmarked_count(UFG::allocator *this)
{
  int v1; // ebx
  UFG::allocator *v2; // rbp
  int v3; // edi
  int v4; // esi
  __int64 v5; // rax
  int v6; // er10
  __int64 v7; // rax
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> **v8; // r11
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v9; // r8
  signed __int64 v10; // r9
  int v11; // eax
  int v12; // esi
  __int64 v13; // rax
  _RTL_CRITICAL_SECTION *v14; // rsi
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v15; // r8
  signed __int64 i; // rbp
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // r9

  v1 = 0;
  v2 = this;
  v3 = 0;
  if ( (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)this->mSmallBlockSystemPages.mNode.mNext != &this->mSmallBlockSystemPages )
  {
    v4 = 0;
    v5 = 0i64;
    do
    {
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mBuckets[v5]);
      v5 = ++v4;
    }
    while ( (unsigned __int64)v4 < 0x20 );
    v6 = 0;
    v7 = 0i64;
    v8 = &v2->mBuckets[0].mPageList.mNode.mNext;
    do
    {
      v9 = *v8;
      v10 = (signed __int64)v2 + 128 * (v7 + 2);
      if ( *v8 != (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)v10 )
      {
        do
        {
          v11 = 0x1FE0 / (16 * (unsigned __int64)((unsigned int)LOWORD(v9[1].mNext) + 1) + 8) - 1;
          if ( v11 > 0 )
            v3 += v11;
          v9 = v9->mNext;
        }
        while ( v9 != (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)v10 );
      }
      ++v6;
      v8 += 16;
      v7 = v6;
    }
    while ( (unsigned __int64)v6 < 0x20 );
    v12 = 0;
    v13 = 0i64;
    do
    {
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v2->mBuckets[v13]);
      v13 = ++v12;
    }
    while ( (unsigned __int64)v12 < 0x20 );
  }
  v14 = (_RTL_CRITICAL_SECTION *)&v2->mTreeMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v2->mTreeMutex);
  v15 = v2->mSystemPages.mNode.mNext;
  for ( i = (signed __int64)&v2->mSystemPages;
        v15 != (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)i;
        v15 = v15->mNext )
  {
    v17 = (unsigned __int64)&v15[2];
    v18 = (unsigned __int64)v15 + (unsigned __int64)v15[1].mPrev;
    if ( (unsigned __int64)&v15[2] < v18 )
    {
      do
      {
        if ( *(_QWORD *)(v17 + 16) & 0xFFFFFFFFFFFFFFFCui64 && *(_QWORD *)(v17 + 8) && !(*(_BYTE *)(v17 + 16) & 2) )
          ++v1;
        v17 += (*(_QWORD *)(v17 + 16) & 0xFFFFFFFFFFFFFFFCui64) + 32;
      }
      while ( v17 < v18 );
    }
  }
  UFG::qMutex::Unlock(v14);
  return (unsigned int)(v1 + v3);
}

// File Line: 964
// RVA: 0x18DA20
void __fastcall UFG::allocator::report_unmarked(UFG::allocator *this)
{
  UFG::allocator *v1; // r13
  int v2; // er14
  int v3; // ebx
  __int64 v4; // rax
  __int64 *v5; // rcx
  int v6; // er12
  __int64 v7; // rax
  __int64 v8; // rbx
  signed __int64 v9; // r15
  unsigned int v10; // eax
  __int64 v11; // rdi
  __int64 v12; // rbp
  signed __int64 v13; // r8
  __int64 v14; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *i; // rdi
  unsigned __int64 v16; // rbx
  unsigned __int64 v17; // rsi
  UFG::allocator *v18; // [rsp+70h] [rbp+8h]
  signed __int64 v19; // [rsp+78h] [rbp+10h]

  v18 = this;
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
    v5 = (__int64 *)&v1->mBuckets[0].mPageList.mNode.mNext;
    v6 = 0;
    v7 = 0i64;
    v19 = (signed __int64)&v1->mBuckets[0].mPageList.mNode.mNext;
    do
    {
      v8 = *v5;
      v9 = (signed __int64)v1 + 128 * (v7 + 2);
      if ( *v5 != v9 )
      {
        do
        {
          v10 = 0x1FE0 / (16 * (unsigned __int64)((unsigned int)*(unsigned __int16 *)(v8 + 24) + 1) + 8) - 1;
          if ( (signed int)v10 > 0 )
          {
            v11 = 0i64;
            v12 = v10;
            do
            {
              v13 = 16i64 * ((unsigned int)*(unsigned __int16 *)(v8 + 24) + 1);
              UFG::qPrintf(
                "0x%08x | %10d | %s | %s\n",
                (v8 & 0xFFFFFFFFFFFFE000ui64) + v13 * v11++,
                v13,
                "unmarked",
                &customWorldMapCaption);
              --v12;
            }
            while ( v12 );
          }
          v8 = *(_QWORD *)(v8 + 8);
        }
        while ( v8 != v9 );
        v1 = v18;
        v5 = (__int64 *)v19;
      }
      ++v6;
      v5 += 16;
      v7 = v6;
      v19 = (signed __int64)v5;
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
        if ( *(_QWORD *)(v16 + 16) & 0xFFFFFFFFFFFFFFFCui64 && *(_QWORD *)(v16 + 8) && !(*(_BYTE *)(v16 + 16) & 2) )
          UFG::qPrintf(
            "0x%08x | %10d | %s | %s\n",
            v16 + 32,
            *(_QWORD *)(v16 + 16) & 0xFFFFFFFFFFFFFFFCui64,
            "unmarked",
            *(_QWORD *)(v16 + 8));
        v16 += (*(_QWORD *)(v16 + 16) & 0xFFFFFFFFFFFFFFFCui64) + 32;
      }
      while ( v16 < v17 );
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mTreeMutex);
}

// File Line: 1077
// RVA: 0x17FF60
UFG::allocator::free_link *__fastcall UFG::allocator::alloc(UFG::allocator *this, unsigned __int64 size, UFG::allocator::allocation_strategy strategy, const char *name)
{
  const char *v4; // rsi
  UFG::allocator::allocation_strategy v5; // ebp
  signed __int64 v6; // rbx
  UFG::allocator *v7; // rdi
  UFG::allocator::free_link *result; // rax

  v4 = name;
  v5 = strategy;
  v6 = size;
  v7 = this;
  if ( !size )
    return 0i64;
  if ( (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)this->mSmallBlockSystemPages.mNode.mNext == &this->mSmallBlockSystemPages
    || size > 0x200 )
  {
    goto LABEL_9;
  }
  if ( size < 0x10 )
    v6 = 16i64;
  result = UFG::allocator::bucket_alloc_direct(this, (unsigned int)((unsigned __int64)(v6 + 15) >> 4) - 1, name);
  if ( !result )
  {
    if ( !v7->mCanSmallBlockOverflowIntoLargeBlock )
      return 0i64;
LABEL_9:
    result = (UFG::allocator::free_link *)UFG::allocator::tree_alloc(v7, v6, v5, v4);
  }
  return result;
}

// File Line: 1118
// RVA: 0x17FE80
UFG::allocator::free_link *__fastcall UFG::allocator::alloc(UFG::allocator *this, unsigned __int64 size, unsigned __int64 alignment, UFG::allocator::allocation_strategy strategy, const char *name)
{
  UFG::allocator::allocation_strategy v5; // ebp
  unsigned __int64 v6; // rsi
  signed __int64 v7; // rbx
  UFG::allocator *v8; // rdi
  UFG::allocator::free_link *result; // rax

  v5 = strategy;
  v6 = alignment;
  v7 = size;
  v8 = this;
  if ( alignment <= 0x10 )
    return (UFG::allocator::free_link *)UFG::allocator::alloc(this, size, strategy, name);
  if ( !size )
    return 0i64;
  if ( (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)this->mSmallBlockSystemPages.mNode.mNext == &this->mSmallBlockSystemPages
    || size > 0x200
    || alignment > 0x200 )
  {
    return (UFG::allocator::free_link *)UFG::allocator::tree_alloc_aligned(v8, v7, v6, v5, name);
  }
  if ( size < 0x10 )
    v7 = 16i64;
  result = UFG::allocator::bucket_alloc_direct(
             this,
             (unsigned int)(((-(signed int)alignment & (v7 + alignment - 1)) + 15) >> 4) - 1,
             name);
  if ( !result )
  {
    if ( v8->mCanSmallBlockOverflowIntoLargeBlock )
      return (UFG::allocator::free_link *)UFG::allocator::tree_alloc_aligned(v8, v7, v6, v5, name);
  }
  return result;
}

// File Line: 1156
// RVA: 0x18D4F0
void *__fastcall UFG::allocator::realloc(UFG::allocator *this, void *ptr, unsigned __int64 new_size, unsigned __int64 old_size, UFG::allocator::allocation_strategy strategy, const char *name)
{
  unsigned __int64 v6; // rbp
  unsigned __int64 v7; // rsi
  void *v8; // rbx
  UFG::allocator *v9; // rdi
  void *result; // rax
  void *v11; // r14
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *i; // rax

  v6 = old_size;
  v7 = new_size;
  v8 = ptr;
  v9 = this;
  if ( ((old_size + 15) ^ (new_size + 15)) & 0xFFFFFFFFFFFFFFF0ui64 )
  {
    result = UFG::allocator::alloc(this, new_size, strategy, name);
    v11 = result;
    if ( result || !v7 )
    {
      if ( v7 < v6 )
        LODWORD(v6) = v7;
      UFG::qMemCopy(result, v8, v6);
      UFG::allocator::free(v9, v8);
      result = v11;
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
          if ( ptr >= (void *)((char *)i - (char *)i[1].mPrev) && ptr < i )
            break;
        }
      }
    }
    result = ptr;
  }
  return result;
}

// File Line: 1190
// RVA: 0x18DEB0
unsigned __int64 __fastcall UFG::allocator::size(UFG::allocator *this, void *ptr)
{
  UFG::allocator *v2; // rax
  char *v4; // rcx
  unsigned __int64 i; // rcx

  v2 = this;
  if ( !ptr )
    return 0i64;
  v4 = this->mSmallBlockStart;
  if ( !v4 )
  {
    for ( i = (unsigned __int64)v2->mSmallBlockSystemPages.mNode.mNext;
          (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)i != &v2->mSmallBlockSystemPages;
          i = *(_QWORD *)(i + 8) )
    {
      if ( (unsigned __int64)ptr >= i - *(_QWORD *)(i + 16) && (unsigned __int64)ptr < i )
        return 16i64
             * ((unsigned int)*(unsigned __int16 *)(((unsigned __int64)ptr & 0xFFFFFFFFFFFFE000ui64) + 0x1FF8) + 1);
    }
    return *((_QWORD *)ptr - 2) & 0xFFFFFFFFFFFFFFFCui64;
  }
  if ( ptr < v4 || ptr >= v2->mSmallBlockEnd )
    return *((_QWORD *)ptr - 2) & 0xFFFFFFFFFFFFFFFCui64;
  return 16i64 * ((unsigned int)*(unsigned __int16 *)(((unsigned __int64)ptr & 0xFFFFFFFFFFFFE000ui64) + 0x1FF8) + 1);
}

// File Line: 1271
// RVA: 0x181020
void __fastcall UFG::allocator::free(UFG::allocator *this, void *ptr)
{
  char *v2; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *i; // rax

  if ( ptr )
  {
    v2 = this->mSmallBlockStart;
    if ( !v2 )
    {
      for ( i = this->mSmallBlockSystemPages.mNode.mNext;
            i != (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)&this->mSmallBlockSystemPages;
            i = i->mNext )
      {
        if ( ptr >= (void *)((char *)i - (char *)i[1].mPrev) && ptr < i )
          goto LABEL_12;
      }
      goto LABEL_5;
    }
    if ( ptr < v2 || ptr >= this->mSmallBlockEnd )
    {
LABEL_5:
      UFG::allocator::tree_free(this, ptr);
      return;
    }
LABEL_12:
    UFG::allocator::bucket_free(this, ptr);
  }
}

// File Line: 1432
// RVA: 0x160C60
void __fastcall UFG::allocator::bucket::bucket(UFG::allocator::bucket *this)
{
  UFG::allocator::bucket *v1; // rbx
  UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::qMutex::qMutex(&this->mLock, "Bucket");
  v2 = &v1->mPageList;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v1->mAllocNumBytes = 0i64;
  v1->mFreeNumBytes = 0i64;
  UFG::qMemSet(v1->_padding, 0, 0x30u);
}

// File Line: 1542
// RVA: 0x180540
UFG::qNode<UFG::allocator::page,UFG::allocator::page> *__fastcall UFG::allocator::bucket_system_alloc(UFG::allocator *this, unsigned __int64 size)
{
  unsigned __int64 v2; // rdi
  UFG::allocator *v3; // rbx
  signed __int64 v4; // rbp
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v5; // rsi
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v6; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> **v7; // r8
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v8; // rcx
  unsigned __int64 v9; // rdi
  UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *v10; // rdx
  __int64 v11; // r8
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v12; // rcx

  v2 = size;
  v3 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBucketFreePagesMutex);
  v4 = v2 + 32;
  if ( v2 == -32i64 )
  {
    v5 = 0i64;
  }
  else
  {
    v6 = (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)UFG::allocator::tree_alloc_aligned(
                                                                    v3,
                                                                    v2 + 32,
                                                                    0x2000ui64,
                                                                    0,
                                                                    "allocator.SmallBlockMemory");
    v5 = v6;
    if ( v6 )
    {
      v7 = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> **)((char *)v6 + v2);
      *v7 = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)v7;
      v7[1] = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)v7;
      v7[2] = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)v2;
      v8 = v3->mSmallBlockSystemPages.mNode.mPrev;
      v8->mNext = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)((char *)v6 + v2);
      *v7 = v8;
      v7[1] = &v3->mSmallBlockSystemPages.mNode;
      v3->mSmallBlockSystemPages.mNode.mPrev = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)((char *)v6 + v2);
      v9 = v2 >> 13;
      if ( (signed int)v9 > 0 )
      {
        v10 = &v3->mBucketFreePages;
        v11 = (signed int)v9;
        do
        {
          if ( v6 )
          {
            v6->mPrev = v6;
            v6->mNext = v6;
            v6[1].mPrev = 0i64;
            LODWORD(v6[1].mNext) = -1;
          }
          v12 = v10->mNode.mPrev;
          v12->mNext = v6;
          v6->mPrev = v12;
          v6->mNext = &v10->mNode;
          v10->mNode.mPrev = v6;
          v6 += 512;
          --v11;
        }
        while ( v11 );
      }
      v3->mStats.mSmallSystemAllocNumBytes += v4 + 32;
      ++v3->mStats.mSmallSystemAllocNumBlocks;
      v3->mStats.mSmallPoolNumBytes += (signed __int64)(signed int)v9 << 13;
      v3->mStats.mSmallPoolNumPages += (signed int)v9;
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mBucketFreePagesMutex);
  return v5;
}

// File Line: 1589
// RVA: 0x1803B0
UFG::qNode<UFG::allocator::page,UFG::allocator::page> *__fastcall UFG::allocator::bucket_page_alloc(UFG::allocator *this)
{
  UFG::allocator *v1; // rbx
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v2; // rsi
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v3; // rax
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v4; // rcx
  unsigned __int64 v5; // rdx
  unsigned __int64 v6; // r8

  v1 = this;
  v2 = 0i64;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBucketFreePagesMutex);
  if ( (UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *)v1->mBucketFreePages.mNode.mNext != &v1->mBucketFreePages )
    goto LABEL_13;
  if ( v1->mSystemMode == 1 )
    UFG::allocator::bucket_system_alloc(v1, 0xFFC000ui64);
  if ( (UFG::qList<UFG::allocator::page,UFG::allocator::page,0,0> *)v1->mBucketFreePages.mNode.mNext != &v1->mBucketFreePages )
  {
LABEL_13:
    v2 = v1->mBucketFreePages.mNode.mNext;
    v3 = v2->mNext;
    v4 = v2->mPrev;
    v4->mNext = v3;
    v3->mPrev = v4;
    v2->mPrev = v2;
    v2->mNext = v2;
    v1->mStats.mSmallAllocNumBytes += 0x2000i64;
    ++v1->mStats.mSmallAllocNumPages;
    v5 = v1->mStats.mSmallAllocNumBytes;
    if ( v1->mStats.mSmallAllocHighWaterNumBytes > v5 )
      v5 = v1->mStats.mSmallAllocHighWaterNumBytes;
    v1->mStats.mSmallAllocHighWaterNumBytes = v5;
    v6 = v1->mStats.mSmallAllocNumPages;
    if ( v1->mStats.mSmallAllocHighWaterNumPages > v6 )
      v6 = v1->mStats.mSmallAllocHighWaterNumPages;
    v1->mStats.mSmallAllocHighWaterNumPages = v6;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mBucketFreePagesMutex);
  return v2;
}

// File Line: 1619
// RVA: 0x180490
void __fastcall UFG::allocator::bucket_page_free(UFG::allocator *this, void *ptr)
{
  _RTL_CRITICAL_SECTION *v2; // rsi
  _QWORD *v3; // rdi
  _QWORD *v4; // rax

  v2 = (_RTL_CRITICAL_SECTION *)this;
  v3 = (_QWORD *)((unsigned __int64)ptr & 0xFFFFFFFFFFFFE000ui64);
  if ( (unsigned __int64)ptr & 0xFFFFFFFFFFFFE000ui64 )
  {
    *v3 = v3;
    *(_QWORD *)(((unsigned __int64)ptr & 0xFFFFFFFFFFFFE000ui64) + 8) = (unsigned __int64)ptr & 0xFFFFFFFFFFFFE000ui64;
    *(_QWORD *)(((unsigned __int64)ptr & 0xFFFFFFFFFFFFE000ui64) + 0x10) = 0i64;
    *(_DWORD *)(((unsigned __int64)ptr & 0xFFFFFFFFFFFFE000ui64) + 0x18) = -1;
  }
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mBucketFreePagesMutex);
  v4 = v2[107].LockSemaphore;
  v4[1] = v3;
  *v3 = v4;
  v3[1] = (char *)v2 + 4304;
  v2[107].LockSemaphore = v3;
  v2[3].OwningThread = (char *)v2[3].OwningThread - 0x2000;
  --v2[3].LockSemaphore;
  UFG::qMutex::Unlock(v2 + 108);
}

// File Line: 1640
// RVA: 0x1802D0
unsigned __int64 __fastcall UFG::allocator::bucket_grow(UFG::allocator *this, unsigned __int64 elemSize)
{
  unsigned __int16 v2; // bx
  unsigned __int64 result; // rax
  unsigned __int64 v4; // r9
  unsigned __int64 v5; // r8
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rbx
  _QWORD *v8; // r10
  _QWORD *v9; // rcx
  unsigned __int64 v10; // r8

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
    v5 = 16i64 * ((unsigned int)*(unsigned __int16 *)((result & 0xFFFFFFFFFFFFE000ui64) + 0x1FF8) + 1) + 8;
    v6 = 0x1FE0 / v5;
    v7 = 0x1FE0 / v5 - 2;
    v8 = (_QWORD *)(v4 & 0xFFFFFFFFFFFFE000ui64);
    v9 = (_QWORD *)((v4 & 0xFFFFFFFFFFFFE000ui64) + 16i64 * ((unsigned int)*(unsigned __int16 *)(v4 + 24) + 1));
    v10 = 0i64;
    if ( v6 != 2 )
    {
      do
      {
        v9 = (_QWORD *)((v4 & 0xFFFFFFFFFFFFE000ui64)
                      + ((signed int)v10 + 1) * 16i64 * ((unsigned int)*(unsigned __int16 *)(v4 + 24) + 1));
        *v8 = v9;
        v8 = v9;
        ++v10;
      }
      while ( v10 < v7 );
    }
    *v9 = 0i64;
    result = v4;
  }
  return result;
}

// File Line: 1736
// RVA: 0x180070
UFG::allocator::free_link *__fastcall UFG::allocator::bucket_alloc_direct(UFG::allocator *this, unsigned int bi, const char *name)
{
  unsigned int v3; // ebx
  __int64 v4; // r15
  UFG::allocator *v5; // rbp
  unsigned __int64 v6; // r14
  _RTL_CRITICAL_SECTION *v7; // rdi
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v8; // rsi
  unsigned __int64 v9; // rbx
  UFG::allocator::page *v10; // r9
  signed __int64 v12; // rcx
  UFG::allocator::page **v13; // rax
  UFG::allocator::free_link *v14; // r14
  UFG::allocator::free_link *v15; // rax
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v16; // rcx
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v17; // rax
  UFG::qNode<UFG::allocator::page,UFG::allocator::page> *v18; // rcx

  v3 = bi;
  v4 = bi;
  v5 = this;
  v6 = (unsigned __int64)bi << 7;
  v7 = (_RTL_CRITICAL_SECTION *)((char *)this->mBuckets + v6);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)((char *)this->mBuckets + v6));
  v8 = (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)&v7[1].LockCount;
  v9 = 16i64 * (v3 + 1);
  if ( v7[1].OwningThread == &v7[1].LockCount || (v10 = (UFG::allocator::page *)v7[1].OwningThread, !v10->mFreeList) )
  {
    v10 = UFG::allocator::bucket_grow(v5, v9);
    if ( !v10 )
    {
      UFG::qMutex::Unlock(v7);
      return 0i64;
    }
    v12 = (signed __int64)v5 + 128 * (v4 + 2);
    v13 = *(UFG::allocator::page ***)(v12 + 8);
    *(_QWORD *)(v12 + 8) = v10;
    v10->mPrev = (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)v12;
    v10->mNext = (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)v13;
    *v13 = v10;
    *(unsigned __int64 *)((char *)&v5->mBuckets[0].mFreeNumBytes + v6) += 16i64
                                                                        * ((unsigned int)v10->mBucketIndex + 1)
                                                                        * (0x1FE0
                                                                         / (16
                                                                          * (unsigned __int64)((unsigned int)v10->mBucketIndex
                                                                                             + 1)
                                                                          + 8)
                                                                         - 1);
  }
  v14 = v10->mFreeList;
  v15 = v14->mNext;
  v10->mFreeList = v14->mNext;
  if ( !v15 )
  {
    v16 = v10->mPrev;
    v17 = v10->mNext;
    v16->mNext = v17;
    v17->mPrev = v16;
    v10->mPrev = (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)&v10->mPrev;
    v10->mNext = (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)&v10->mPrev;
    v18 = v8->mPrev;
    v18->mNext = (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)&v10->mPrev;
    v10->mPrev = v18;
    v10->mNext = v8;
    v8->mPrev = (UFG::qNode<UFG::allocator::page,UFG::allocator::page> *)&v10->mPrev;
  }
  ++v10->mUseCount;
  v7[1].LockSemaphore = (char *)v7[1].LockSemaphore + v9;
  v7[1].SpinCount -= v9;
  UFG::qMutex::Unlock(v7);
  return v14;
}

// File Line: 1768
// RVA: 0x1801B0
void __fastcall UFG::allocator::bucket_free(UFG::allocator *this, void *ptr)
{
  _QWORD *v2; // rbx
  UFG::allocator *v3; // r15
  _WORD *v4; // rdi
  unsigned __int64 v5; // r14
  _RTL_CRITICAL_SECTION *v6; // rsi
  signed __int64 v7; // rbp
  __int64 v8; // rax
  __int64 v9; // rcx
  _QWORD *v10; // rax
  _QWORD *v11; // rcx
  __int64 v12; // r8
  _QWORD *v13; // rax

  v2 = ptr;
  v3 = this;
  v4 = (_WORD *)(((unsigned __int64)ptr & 0xFFFFFFFFFFFFE000ui64) + 8160);
  v5 = (unsigned __int64)*(unsigned __int16 *)(((unsigned __int64)ptr & 0xFFFFFFFFFFFFE000ui64) + 0x1FF8) << 7;
  v6 = (_RTL_CRITICAL_SECTION *)((char *)this->mBuckets + v5);
  v7 = 16i64 * ((unsigned int)*(unsigned __int16 *)(((unsigned __int64)ptr & 0xFFFFFFFFFFFFE000ui64) + 0x1FF8) + 1);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)((char *)this->mBuckets + v5));
  v8 = *((_QWORD *)v4 + 2);
  *v2 = v8;
  --v4[13];
  *((_QWORD *)v4 + 2) = v2;
  if ( !v8 )
  {
    v9 = *(_QWORD *)v4;
    v10 = (_QWORD *)*((_QWORD *)v4 + 1);
    *(_QWORD *)(v9 + 8) = v10;
    *v10 = v9;
    *(_QWORD *)v4 = v4;
    *((_QWORD *)v4 + 1) = v4;
    v11 = v6[1].OwningThread;
    v6[1].OwningThread = v4;
    *((_QWORD *)v4 + 1) = v11;
    *(_QWORD *)v4 = (char *)v6 + 48;
    *v11 = v4;
  }
  v6[1].LockSemaphore = (char *)v6[1].LockSemaphore - v7;
  v6[1].SpinCount += v7;
  if ( !v4[13] )
  {
    *(unsigned __int64 *)((char *)&v3->mBuckets[0].mFreeNumBytes + v5) -= 16i64
                                                                        * ((unsigned int)(unsigned __int16)v4[12] + 1)
                                                                        * (0x1FE0
                                                                         / (16
                                                                          * (unsigned __int64)((unsigned int)(unsigned __int16)v4[12]
                                                                                             + 1)
                                                                          + 8)
                                                                         - 1);
    v12 = *(_QWORD *)v4;
    v13 = (_QWORD *)*((_QWORD *)v4 + 1);
    *(_QWORD *)(v12 + 8) = v13;
    *v13 = v12;
    *(_QWORD *)v4 = v4;
    *((_QWORD *)v4 + 1) = v4;
    UFG::allocator::bucket_page_free(v3, v4);
  }
  UFG::qMutex::Unlock(v6);
}

// File Line: 1867
// RVA: 0x180730
UFG::allocator::block_header *__fastcall UFG::allocator::coalesce_block(UFG::allocator *this, UFG::allocator::block_header *bl)
{
  UFG::allocator::block_header *v2; // rdi
  UFG::allocator *v3; // rsi
  UFG::allocator::block_header *v4; // rbx
  UFG::allocator::free_node *v5; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v6; // rcx
  char *v7; // rax
  UFG::allocator::block_header *v8; // rbx
  UFG::allocator::free_node *v9; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v10; // rcx
  char *v11; // rax
  UFG::allocator::block_header *result; // rax

  v2 = bl;
  v3 = this;
  v4 = (UFG::allocator::block_header *)((char *)bl + (bl->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) + 32);
  if ( !(v4->mSizeAndFlags & 1) )
  {
    if ( this->mMRFreeBlock == v4 )
    {
      this->mMRFreeBlock = 0i64;
    }
    else
    {
      v5 = (UFG::allocator::free_node *)&v4[1];
      if ( (v4->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
      {
        v6 = v5->mChildren[0];
        v7 = (char *)v4[1].mName;
        v6->mChildren[1] = (UFG::intrusive_multi_rbtree_base::node_base *)v7;
        *(_QWORD *)v7 = v6;
        v5->mChildren[0] = (UFG::intrusive_multi_rbtree_base::node_base *)v5->mChildren;
        v4[1].mName = (const char *)&v4[1];
      }
      else
      {
        UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(&this->mFreeTree, v5);
      }
    }
    *(UFG::allocator::block_header **)((char *)&v4[1].mPrev + (v4->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64)) = v4->mPrev;
    v4->mPrev->mSizeAndFlags = v4->mPrev->mSizeAndFlags & 3 | ((unsigned __int64)v4
                                                             + (v4->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64)
                                                             - (unsigned __int64)v4->mPrev);
  }
  v8 = v2->mPrev;
  if ( v2->mPrev->mSizeAndFlags & 1 )
    return v2;
  if ( v3->mMRFreeBlock == v8 )
  {
    v3->mMRFreeBlock = 0i64;
  }
  else
  {
    v9 = (UFG::allocator::free_node *)&v8[1];
    if ( (v8->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
    {
      v10 = v9->mChildren[0];
      v11 = (char *)v8[1].mName;
      v10->mChildren[1] = (UFG::intrusive_multi_rbtree_base::node_base *)v11;
      *(_QWORD *)v11 = v10;
      v9->mChildren[0] = (UFG::intrusive_multi_rbtree_base::node_base *)v9->mChildren;
      v8[1].mName = (const char *)&v8[1];
    }
    else
    {
      UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(&v3->mFreeTree, v9);
    }
  }
  *(UFG::allocator::block_header **)((char *)&v2[1].mPrev + (v2->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64)) = v2->mPrev;
  result = v8;
  v2->mPrev->mSizeAndFlags = v2->mPrev->mSizeAndFlags & 3 | ((unsigned __int64)v2
                                                           + (v2->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64)
                                                           - (unsigned __int64)v2->mPrev);
  return result;
}

// File Line: 1898
// RVA: 0x18EE30
signed __int64 __fastcall UFG::allocator::tree_system_alloc(UFG::allocator *this, unsigned __int64 size)
{
  unsigned __int64 v2; // rdi
  UFG::allocator *v3; // rbx
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *v5; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v6; // rdx
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *v7; // rcx
  UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *v8; // r8
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v9; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v10; // rax
  UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *v11; // rax

  v2 = size;
  v3 = this;
  if ( this->mSystemMode == 0 )
    return 0i64;
  v5 = (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)UFG::qSystemAlloc(size + 32);
  v6 = &v5->mNode;
  if ( !v5 )
    return 0i64;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  v5[1].mNode.mPrev = (UFG::qNode<UFG::allocator::system_page_header,UFG::allocator::system_page_header> *)v2;
  v7 = (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)v3->mSystemPages.mNode.mNext;
  v8 = &v3->mSystemPages;
  if ( v7 == &v3->mSystemPages )
    goto LABEL_14;
  while ( v5 >= v7 )
  {
    v7 = (UFG::qList<UFG::allocator::system_page_header,UFG::allocator::system_page_header,0,0> *)v7->mNode.mNext;
    if ( v7 == v8 )
      goto LABEL_9;
  }
  v9 = v7->mNode.mPrev;
  v9->mNext = v6;
  v6->mPrev = v9;
  v6->mNext = &v7->mNode;
  v7->mNode.mPrev = v6;
LABEL_9:
  if ( v7 == v8 )
  {
LABEL_14:
    v10 = v8->mNode.mPrev;
    v10->mNext = v6;
    v6->mPrev = v10;
    v6->mNext = &v8->mNode;
    v8->mNode.mPrev = v6;
  }
  v11 = v6[1].mPrev;
  ++v3->mStats.mSystemPageNumPages;
  v3->mStats.mSystemPageNumBytes += (unsigned __int64)&v11[2];
  v3->mStats.mLargePoolNumBytes += (unsigned __int64)&v6[1].mPrev[-2];
  return (signed __int64)&v6[2];
}

// File Line: 1968
// RVA: 0x18DFB0
UFG::allocator::block_header *__fastcall UFG::allocator::tree_add_block(UFG::allocator *this, void *mem, unsigned __int64 size)
{
  char *v3; // r9
  UFG::allocator *v4; // r10
  char *v5; // rcx

  *((_QWORD *)mem + 2) &= 2ui64;
  *((_QWORD *)mem + 2) |= 1ui64;
  v3 = (char *)mem + 32;
  v4 = this;
  v5 = (char *)mem + size;
  *((_QWORD *)mem + 1) = &customWorldMapCaption;
  *(_QWORD *)mem = 0i64;
  *((_QWORD *)v3 + 2) &= 2ui64;
  *((_QWORD *)v3 + 2) |= 1ui64;
  *((_QWORD *)v3 + 1) = &customWorldMapCaption;
  *(_QWORD *)v3 = mem;
  *((_QWORD *)v5 - 2) &= 2ui64;
  *((_QWORD *)v5 - 2) |= 1ui64;
  *((_QWORD *)v5 - 3) = &customWorldMapCaption;
  *((_QWORD *)v3 + 2) &= 2ui64;
  *((_QWORD *)v3 + 1) = 0i64;
  *((_QWORD *)v3 + 2) |= (char *)mem + size - 32 - v3 - 32;
  *((_QWORD *)v5 - 4) = (char *)mem + 32;
  return UFG::allocator::coalesce_block(v4, (UFG::allocator::block_header *)mem + 1);
}

// File Line: 2007
// RVA: 0x18E5A0
UFG::allocator::block_header *__fastcall UFG::allocator::tree_extract(UFG::allocator *this, unsigned __int64 size, UFG::allocator::allocation_strategy strategy)
{
  unsigned __int64 v3; // rbp
  UFG::allocator *v4; // rsi
  char *v5; // rcx
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rbx
  UFG::allocator::block_header *v8; // rdx
  UFG::allocator::free_node *v10; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v11; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v12; // rax
  signed __int64 v13; // rdx
  int v14; // eax
  unsigned __int64 v15; // rcx
  __int64 v16; // rcx
  char *v17; // rdx
  unsigned __int64 v18; // rdx
  unsigned __int64 v19; // rdi
  UFG::allocator::free_node *v20; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v21; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v22; // rax
  unsigned __int64 v23; // r8
  int v24; // eax
  unsigned __int64 v25; // rcx
  __int64 v26; // rcx
  unsigned __int64 v27; // rbx
  signed __int64 v28; // r8
  signed __int64 v29; // rbx
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v30; // rcx
  __int64 v31; // rdx
  _QWORD *v32; // rcx
  _QWORD *v33; // r8

  v3 = size;
  v4 = this;
  if ( strategy == 1 )
  {
    v5 = this->mFixedSystemPageStart;
    if ( v5 )
    {
      v6 = (unsigned __int64)(v4->mFixedSystemPageEnd - 32);
      v7 = (unsigned __int64)&v5[(*((_QWORD *)v5 + 6) & 0xFFFFFFFFFFFFFFFCui64) + 64];
      if ( v7 < v6 )
      {
        while ( *(_BYTE *)(v7 + 16) & 1 || (*(_QWORD *)(v7 + 16) & 0xFFFFFFFFFFFFFFFCui64) <= v3 + 544 )
        {
          v7 += (*(_QWORD *)(v7 + 16) & 0xFFFFFFFFFFFFFFFCui64) + 32;
          if ( v7 >= v6 )
            goto LABEL_7;
        }
        if ( v4->mMRFreeBlock == (UFG::allocator::block_header *)v7 )
        {
          v4->mMRFreeBlock = 0i64;
        }
        else
        {
          v10 = (UFG::allocator::free_node *)(v7 + 32);
          if ( (*(_QWORD *)(v7 + 16) & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
          {
            v11 = v10->mChildren[0];
            v12 = *(UFG::intrusive_multi_rbtree_base::node_base **)(v7 + 40);
            v11->mChildren[1] = v12;
            v12->mChildren[0] = v11;
            v10->mChildren[0] = (UFG::intrusive_multi_rbtree_base::node_base *)v10->mChildren;
            *(_QWORD *)(v7 + 40) = v7 + 32;
          }
          else
          {
            UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(&v4->mFreeTree, v10);
          }
        }
        v13 = v7 + v3 + 32;
        v14 = *(_DWORD *)(v13 + 16);
        *(_QWORD *)v13 = v7;
        v15 = v14 & 3 | ((*(_QWORD *)(v7 + 16) & 0xFFFFFFFFFFFFFFFCui64) - (v3 + 32));
        *(_QWORD *)(v13 + 16) = v15;
        *(_QWORD *)((v15 & 0xFFFFFFFFFFFFFFFCui64) + v13 + 32) = v13;
        v16 = *(_QWORD *)v13;
        *(_QWORD *)(v16 + 16) &= 3ui64;
        *(_QWORD *)(v16 + 16) |= v7 + v3 - v16;
        *(_QWORD *)(v13 + 16) &= 0xFFFFFFFFFFFFFFFEui64;
        *(_QWORD *)(v13 + 8) = 0i64;
        UFG::allocator::tree_attach(
          v4,
          (UFG::allocator::block_header *)(v7 + (*(_QWORD *)(v7 + 16) & 0xFFFFFFFFFFFFFFFCui64) + 32));
        return (UFG::allocator::block_header *)v7;
      }
    }
LABEL_7:
    v8 = v4->mMRFreeBlock;
    if ( v8 && (v8->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) >= v3 )
    {
      v4->mMRFreeBlock = 0i64;
      return v8;
    }
    v28 = (signed __int64)&v4->mFreeTree;
    v29 = (signed __int64)&v4->mFreeTree;
    v30 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v4->mFreeTree.mHead.mChildren[0];
    if ( v30 != &v4->mFreeTree )
    {
      do
      {
        if ( ((_QWORD)v30[-1].mHead.mNeighbours[1] & 0xFFFFFFFFFFFFFFFCui64) >= v3 )
        {
          v29 = (signed __int64)v30;
          v30 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v30->mHead.mChildren[0];
        }
        else
        {
          v30 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v30->mHead.mChildren[1];
        }
      }
      while ( v30 != (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v28 );
    }
    if ( v29 == v28 )
      return 0i64;
    v7 = *(_QWORD *)(v29 + 24) - 32i64;
    if ( v8 == (UFG::allocator::block_header *)v7 )
    {
      v4->mMRFreeBlock = 0i64;
    }
    else if ( (*(_QWORD *)(v7 + 16) & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
    {
      v31 = *(_QWORD *)(v7 + 32);
      v32 = *(_QWORD **)(v7 + 40);
      v33 = (_QWORD *)(v7 + 32);
      *(_QWORD *)(v31 + 8) = v32;
      *v32 = v31;
      *v33 = v33;
      v33[1] = v33;
    }
    else
    {
      UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(
        &v4->mFreeTree,
        (UFG::allocator::free_node *)(v7 + 32));
    }
    return (UFG::allocator::block_header *)v7;
  }
  if ( strategy != 2 )
    goto LABEL_7;
  v17 = this->mFixedSystemPageStart;
  if ( !v17 )
    goto LABEL_7;
  v18 = (unsigned __int64)(v17 + 32);
  v19 = *((_QWORD *)this->mFixedSystemPageEnd - 4);
  if ( v19 <= v18 )
    goto LABEL_7;
  while ( *(_BYTE *)(v19 + 16) & 1 || (*(_QWORD *)(v19 + 16) & 0xFFFFFFFFFFFFFFFCui64) <= v3 + 544 )
  {
    v19 = *(_QWORD *)v19;
    if ( v19 <= v18 )
      goto LABEL_7;
  }
  if ( this->mMRFreeBlock == (UFG::allocator::block_header *)v19 )
  {
    this->mMRFreeBlock = 0i64;
  }
  else
  {
    v20 = (UFG::allocator::free_node *)(v19 + 32);
    if ( (*(_QWORD *)(v19 + 16) & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
    {
      v21 = v20->mChildren[0];
      v22 = *(UFG::intrusive_multi_rbtree_base::node_base **)(v19 + 40);
      v21->mChildren[1] = v22;
      v22->mChildren[0] = v21;
      v20->mChildren[0] = (UFG::intrusive_multi_rbtree_base::node_base *)v20->mChildren;
      *(_QWORD *)(v19 + 40) = v19 + 32;
    }
    else
    {
      UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(&this->mFreeTree, v20);
    }
  }
  v23 = v19 + (*(_QWORD *)(v19 + 16) & 0xFFFFFFFFFFFFFFFCui64) - v3;
  v24 = *(_DWORD *)(v23 + 16);
  *(_QWORD *)v23 = v19;
  v25 = v24 & 3 | (v19 + (*(_QWORD *)(v19 + 16) & 0xFFFFFFFFFFFFFFFCui64) - v23);
  *(_QWORD *)(v23 + 16) = v25;
  *(_QWORD *)((v25 & 0xFFFFFFFFFFFFFFFCui64) + v23 + 32) = v23;
  v26 = *(_QWORD *)v23;
  *(_QWORD *)(v26 + 16) &= 3ui64;
  *(_QWORD *)(v26 + 16) |= v23 - v26 - 32;
  *(_QWORD *)(v23 + 16) &= 0xFFFFFFFFFFFFFFFEui64;
  *(_QWORD *)(v23 + 8) = 0i64;
  v27 = *(_QWORD *)(v19 + 16) & 0xFFFFFFFFFFFFFFFCui64;
  UFG::allocator::tree_attach(v4, (UFG::allocator::block_header *)v19);
  return (UFG::allocator::block_header *)(v27 + v19 + 32);
}

// File Line: 2097
// RVA: 0x18E8D0
UFG::allocator::block_header *__fastcall UFG::allocator::tree_extract_aligned(UFG::allocator *this, unsigned __int64 size, unsigned __int64 alignment, UFG::allocator::allocation_strategy strategy)
{
  unsigned __int64 v4; // rsi
  unsigned __int64 v5; // r14
  UFG::allocator *v6; // rbp
  char *v7; // rcx
  unsigned __int64 v8; // rdx
  UFG::allocator::block_header *v9; // rbx
  UFG::allocator::free_node *v10; // rdi
  UFG::allocator::block_header *result; // rax
  unsigned __int64 v12; // r8
  int v13; // eax
  unsigned __int64 v14; // rcx
  __int64 v15; // rdx
  char *v16; // rdx
  unsigned __int64 v17; // rdx
  UFG::allocator::block_header *v18; // rdi
  unsigned __int64 v19; // rbx
  unsigned __int64 v20; // rbx
  UFG::allocator::free_node *v21; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v22; // rcx
  char *v23; // rax
  int v24; // eax
  UFG::allocator::block_header **v25; // r8
  unsigned __int64 v26; // rcx
  __int64 v27; // rcx
  unsigned __int64 v28; // rbx
  signed __int64 v29; // r9
  unsigned __int64 v30; // r11
  UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *v31; // r8
  UFG::allocator::free_node *v32; // rax
  UFG::allocator::free_node *v33; // rdx
  signed __int64 v34; // r10
  signed __int64 v35; // r8
  int v36; // esi
  UFG::intrusive_multi_rbtree_base::node_base *v37; // rcx
  unsigned __int64 v38; // rdx
  UFG::allocator::free_node *i; // rcx
  char v40; // cl
  UFG::intrusive_multi_rbtree_base::node_base *v41; // rdx
  char *v42; // rcx
  UFG::allocator::free_node *v43; // r8

  v4 = alignment;
  v5 = size;
  v6 = this;
  if ( strategy == 1 )
  {
    v7 = this->mFixedSystemPageStart;
    if ( v7 )
    {
      v8 = (unsigned __int64)(v6->mFixedSystemPageEnd - 32);
      v9 = (UFG::allocator::block_header *)&v7[(*((_QWORD *)v7 + 6) & 0xFFFFFFFFFFFFFFFCui64) + 64];
      if ( (unsigned __int64)v9 < v8 )
      {
        while ( v9->mSizeAndFlags & 1 || (v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= v5 + alignment + 544 )
        {
          v9 = (UFG::allocator::block_header *)((char *)v9 + (v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) + 32);
          if ( (unsigned __int64)v9 >= v8 )
            goto LABEL_7;
        }
        UFG::allocator::tree_detach(v6, v9);
        v12 = -(signed int)v4 & (unsigned __int64)&v9->_padding[v5 + 3 + v4];
        v13 = *(_DWORD *)(v12 + 0x10);
        *(_QWORD *)v12 = v9;
        v14 = v13 & 3 | ((unsigned __int64)v9 + (v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) - v12);
        *(_QWORD *)(v12 + 16) = v14;
        *(_QWORD *)((v14 & 0xFFFFFFFFFFFFFFFCui64) + v12 + 32) = v12;
        v15 = *(_QWORD *)v12;
        *(_QWORD *)(v15 + 16) &= 3ui64;
        *(_QWORD *)(v15 + 16) |= v12 - v15 - 32;
        *(_QWORD *)(v12 + 16) &= 0xFFFFFFFFFFFFFFFEui64;
        *(_QWORD *)(v12 + 8) = 0i64;
        UFG::allocator::tree_attach(
          v6,
          (UFG::allocator::block_header *)((char *)v9 + (v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) + 32));
        return v9;
      }
    }
LABEL_7:
    v10 = (UFG::allocator::free_node *)v6->mMRFreeBlock;
    if ( v10
      && ((_QWORD)v10->mNeighbours[0] & 0xFFFFFFFFFFFFFFFCui64) >= v5
                                                                 + (-(signed int)alignment & ((unsigned __int64)&v10->mNeighbours[1]
                                                                                            + alignment
                                                                                            + 7))
                                                                 - (_QWORD)v10
                                                                 - 32 )
    {
      result = v6->mMRFreeBlock;
      v6->mMRFreeBlock = 0i64;
      return result;
    }
    v29 = (signed __int64)&v6->mFreeTree;
    v30 = v5 + alignment;
    v31 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v6->mFreeTree.mHead.mChildren[0];
    v32 = (UFG::allocator::free_node *)&v6->mFreeTree;
    v33 = (UFG::allocator::free_node *)v31;
    if ( v31 != &v6->mFreeTree )
    {
      do
      {
        if ( ((_QWORD)v33[-1].mNeighbours[1] & 0xFFFFFFFFFFFFFFFCui64) >= v5 )
        {
          v32 = v33;
          v33 = (UFG::allocator::free_node *)v33->mChildren[0];
        }
        else
        {
          v33 = (UFG::allocator::free_node *)v33->mChildren[1];
        }
      }
      while ( v33 != (UFG::allocator::free_node *)v29 );
    }
    v34 = (signed __int64)&v6->mFreeTree;
    while ( v31 != (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v29 )
    {
      if ( ((_QWORD)v31[-1].mHead.mNeighbours[1] & 0xFFFFFFFFFFFFFFFCui64) <= v30 )
      {
        v31 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v31->mHead.mChildren[1];
      }
      else
      {
        v34 = (signed __int64)v31;
        v31 = (UFG::intrusive_multi_rbtree<UFG::allocator::free_node> *)v31->mHead.mChildren[0];
      }
    }
    if ( v32 != (UFG::allocator::free_node *)v34 )
    {
      v35 = v4 - 1;
      v36 = -(signed int)v4;
      do
      {
        if ( ((_QWORD)v32[-1].mNeighbours[1] & 0xFFFFFFFFFFFFFFFCui64) >= v5
                                                                        + (v36 & ((unsigned __int64)v32 + v35))
                                                                        - (_QWORD)v32 )
          break;
        v32 = (UFG::allocator::free_node *)v32->mNeighbours[1];
        v37 = v32->mParent;
        v38 = (_QWORD)v32->mParent & 0xFFFFFFFFFFFFFFFCui64;
        if ( v38 )
        {
          v32 = (UFG::allocator::free_node *)v32->mChildren[1];
          if ( v32 == (UFG::allocator::free_node *)v32->mChildren[1] )
          {
            v32 = (UFG::allocator::free_node *)v38;
            if ( ((unsigned __int8)v37 >> 1) & 1 )
            {
              do
              {
                v40 = (unsigned __int8)LODWORD(v32->mParent) >> 1;
                v32 = (UFG::allocator::free_node *)((_QWORD)v32->mParent & 0xFFFFFFFFFFFFFFFCui64);
              }
              while ( v40 & 1 );
            }
          }
          else
          {
            for ( i = (UFG::allocator::free_node *)v32->mChildren[0];
                  i != (UFG::allocator::free_node *)i->mChildren[1];
                  i = (UFG::allocator::free_node *)i->mChildren[0] )
            {
              v32 = i;
            }
          }
        }
      }
      while ( v32 != (UFG::allocator::free_node *)v34 );
    }
    if ( v32 == (UFG::allocator::free_node *)v29 )
      return 0i64;
    if ( v32 == (UFG::allocator::free_node *)v34 )
      v32 = (UFG::allocator::free_node *)v32->mNeighbours[1];
    v9 = (UFG::allocator::block_header *)&v32[-1].mChildren[1];
    if ( v10 == (UFG::allocator::free_node *)&v32[-1].mChildren[1] )
    {
      v6->mMRFreeBlock = 0i64;
    }
    else if ( (v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
    {
      v41 = v32->mChildren[0];
      v42 = (char *)v9[1].mName;
      v43 = v32;
      v41->mChildren[1] = (UFG::intrusive_multi_rbtree_base::node_base *)v42;
      *(_QWORD *)v42 = v41;
      v43->mChildren[0] = (UFG::intrusive_multi_rbtree_base::node_base *)v43->mChildren;
      v43->mChildren[1] = (UFG::intrusive_multi_rbtree_base::node_base *)v43->mChildren;
    }
    else
    {
      UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(&v6->mFreeTree, v32);
    }
    return v9;
  }
  if ( strategy != 2 )
    goto LABEL_7;
  v16 = this->mFixedSystemPageStart;
  if ( !v16 )
    goto LABEL_7;
  v17 = (unsigned __int64)(v16 + 32);
  v18 = (UFG::allocator::block_header *)*((_QWORD *)this->mFixedSystemPageEnd - 4);
  if ( (unsigned __int64)v18 <= v17 )
    goto LABEL_7;
  while ( 1 )
  {
    if ( !(v18->mSizeAndFlags & 1) )
    {
      v19 = v18->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64;
      if ( v19 > v5 + alignment + 544 )
      {
        v20 = -(signed int)alignment & ((unsigned __int64)v18 + v19 - v5);
        if ( v20 > (unsigned __int64)&v18[2] )
          break;
      }
    }
    v18 = v18->mPrev;
    if ( (unsigned __int64)v18 <= v17 )
      goto LABEL_7;
  }
  if ( this->mMRFreeBlock == v18 )
  {
    this->mMRFreeBlock = 0i64;
  }
  else
  {
    v21 = (UFG::allocator::free_node *)&v18[1];
    if ( (v18->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
    {
      v22 = v21->mChildren[0];
      v23 = (char *)v18[1].mName;
      v22->mChildren[1] = (UFG::intrusive_multi_rbtree_base::node_base *)v23;
      *(_QWORD *)v23 = v22;
      v21->mChildren[0] = (UFG::intrusive_multi_rbtree_base::node_base *)v21->mChildren;
      v18[1].mName = (const char *)&v18[1];
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
  UFG::allocator::tree_attach(v6, v18);
  return (UFG::allocator::block_header *)((char *)v18 + v28 + 32);
}

// File Line: 2204
// RVA: 0x18E4C0
void __fastcall UFG::allocator::tree_attach(UFG::allocator *this, UFG::allocator::block_header *bl)
{
  UFG::allocator *v2; // rbx
  UFG::allocator::block_header *v3; // rcx
  UFG::allocator::block_header *v4; // rdi
  UFG::allocator::block_header *v5; // rcx
  UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *v6; // rax

  v2 = this;
  v3 = this->mMRFreeBlock;
  v4 = bl;
  if ( v3 )
  {
    if ( (v3->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
    {
      v5 = v3 + 1;
      v6 = v2->mSmallFreeList.mNode.mPrev;
      v6->mNext = (UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *)v5;
      v5->mPrev = (UFG::allocator::block_header *)v6;
      v5->mName = (const char *)&v2->mSmallFreeList;
      v2->mSmallFreeList.mNode.mPrev = (UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *)v5;
    }
    else
    {
      UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_insert(
        &v2->mFreeTree,
        (UFG::allocator::free_node *)&v3[1]);
    }
    v2->mMRFreeBlock = v4;
  }
  else
  {
    v2->mMRFreeBlock = bl;
  }
}

// File Line: 2222
// RVA: 0x18E550
void __fastcall UFG::allocator::tree_detach(UFG::allocator *this, UFG::allocator::block_header *bl)
{
  unsigned __int64 v2; // rax
  UFG::allocator::free_node *v3; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v4; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v5; // rax

  if ( this->mMRFreeBlock == bl )
  {
    this->mMRFreeBlock = 0i64;
  }
  else
  {
    v2 = bl->mSizeAndFlags;
    v3 = (UFG::allocator::free_node *)&bl[1];
    if ( (v2 & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
    {
      v4 = v3->mChildren[0];
      v5 = v3->mChildren[1];
      v4->mChildren[1] = v5;
      v5->mChildren[0] = v4;
      v3->mChildren[0] = (UFG::intrusive_multi_rbtree_base::node_base *)v3->mChildren;
      v3->mChildren[1] = (UFG::intrusive_multi_rbtree_base::node_base *)v3->mChildren;
    }
    else
    {
      UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(&this->mFreeTree, v3);
    }
  }
}

// File Line: 2242
// RVA: 0x18E020
UFG::allocator::block_header *__fastcall UFG::allocator::tree_alloc(UFG::allocator *this, unsigned __int64 size, UFG::allocator::allocation_strategy strategy, const char *name)
{
  unsigned __int64 v4; // rbx
  UFG::allocator::allocation_strategy v5; // edi
  UFG::allocator *v6; // rsi
  const char *v7; // r15
  unsigned __int64 v8; // rbp
  UFG::allocator::block_header *v9; // rbx
  void *v10; // rax
  UFG::allocator::block_header *result; // rax
  signed __int64 v12; // rdx
  int v13; // eax
  unsigned __int64 v14; // rcx
  __int64 v15; // rcx
  UFG::allocator::block_header *v16; // rcx
  unsigned __int64 v17; // rdi
  UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *v18; // rcx
  UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *v19; // rax
  unsigned __int64 v20; // rcx
  unsigned __int64 v21; // rdx

  v4 = size;
  v5 = strategy;
  v6 = this;
  v7 = name;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mTreeMutex);
  if ( v4 < 0x28 )
    v4 = 40i64;
  v8 = (v4 + 31) & 0xFFFFFFFFFFFFFFE0ui64;
  v9 = UFG::allocator::tree_extract(v6, v8, v5);
  if ( v9
    || (v10 = UFG::allocator::tree_system_alloc(v6, (v8 + 16777311) & 0xFFFFFFFFFF000000ui64)) != 0i64
    && (v9 = UFG::allocator::tree_add_block(v6, v10, (v8 + 16777311) & 0xFFFFFFFFFF000000ui64)) != 0i64 )
  {
    if ( (v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) >= v8 + 72 )
    {
      v12 = (signed __int64)&v9[1] + v8;
      v13 = *(_DWORD *)(v12 + 16);
      *(_QWORD *)v12 = v9;
      v14 = v13 & 3 | ((v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) - (v8 + 32));
      *(_QWORD *)(v12 + 16) = v14;
      *(_QWORD *)((v14 & 0xFFFFFFFFFFFFFFFCui64) + v12 + 32) = v12;
      v15 = *(_QWORD *)v12;
      *(_QWORD *)(v15 + 16) &= 3ui64;
      *(_QWORD *)(v15 + 16) |= (unsigned __int64)v9 + v8 - v15;
      *(_QWORD *)(v12 + 16) &= 0xFFFFFFFFFFFFFFFEui64;
      *(_QWORD *)(v12 + 8) = 0i64;
      v16 = v6->mMRFreeBlock;
      v17 = (unsigned __int64)&v9[1] + (v9->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64);
      if ( v16 )
      {
        if ( (v16->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
        {
          v18 = (UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *)&v16[1];
          v19 = v6->mSmallFreeList.mNode.mPrev;
          v19->mNext = v18;
          v18->mPrev = v19;
          v18->mNext = &v6->mSmallFreeList.mNode;
          v6->mSmallFreeList.mNode.mPrev = v18;
        }
        else
        {
          UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_insert(
            &v6->mFreeTree,
            (UFG::allocator::free_node *)&v16[1]);
        }
      }
      v6->mMRFreeBlock = (UFG::allocator::block_header *)v17;
    }
    v9->mSizeAndFlags |= 1ui64;
    v20 = v9->mSizeAndFlags;
    v9->mName = v7;
    ++v6->mStats.mLargeAllocNumBlocks;
    v6->mStats.mLargeAllocNumBytes += (v20 & 0xFFFFFFFFFFFFFFFCui64) + 32;
    v21 = v6->mStats.mLargeAllocHighWaterNumBytes;
    if ( v6->mStats.mLargeAllocNumBytes > v21 )
      v21 = v6->mStats.mLargeAllocNumBytes;
    v6->mStats.mLargeAllocHighWaterNumBytes = v21;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v6->mTreeMutex);
    result = v9 + 1;
  }
  else
  {
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v6->mTreeMutex);
    result = 0i64;
  }
  return result;
}

// File Line: 2298
// RVA: 0x18E1F0
UFG::allocator::block_header *__fastcall UFG::allocator::tree_alloc_aligned(UFG::allocator *this, unsigned __int64 size, unsigned __int64 alignment, UFG::allocator::allocation_strategy strategy, const char *name)
{
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rbp
  UFG::allocator *v7; // rsi
  UFG::allocator::allocation_strategy v8; // edi
  unsigned __int64 v9; // r14
  UFG::allocator::block_header *v10; // rbx
  void *v11; // rax
  UFG::allocator::block_header *result; // rax
  unsigned __int64 v13; // r9
  int v14; // eax
  UFG::allocator::block_header **v15; // rdx
  unsigned __int64 v16; // rcx
  UFG::allocator::block_header *v17; // rcx
  UFG::allocator::block_header *v18; // r8
  UFG::allocator::block_header *v19; // rdx
  __int64 v20; // rax
  unsigned __int64 v21; // rcx
  unsigned __int64 v22; // rcx
  UFG::allocator::block_header *v23; // rcx
  signed __int64 v24; // rdx
  int v25; // eax
  unsigned __int64 v26; // rcx
  __int64 v27; // rcx
  UFG::allocator::block_header *v28; // rcx
  unsigned __int64 v29; // rdi
  UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *v30; // rcx
  UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *v31; // rax
  unsigned __int64 v32; // rcx
  unsigned __int64 v33; // rdx

  v5 = size;
  v6 = alignment;
  v7 = this;
  v8 = strategy;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mTreeMutex);
  if ( v5 < 0x28 )
    v5 = 40i64;
  v9 = (v5 + 31) & 0xFFFFFFFFFFFFFFE0ui64;
  v10 = UFG::allocator::tree_extract_aligned(v7, v9, v6, v8);
  if ( v10
    || (v11 = UFG::allocator::tree_system_alloc(v7, (v9 + v6 + 16777311) & 0xFFFFFFFFFF000000ui64)) != 0i64
    && (v10 = UFG::allocator::tree_add_block(v7, v11, (v9 + v6 + 16777311) & 0xFFFFFFFFFF000000ui64)) != 0i64 )
  {
    v13 = (-(signed int)v6 & (unsigned __int64)&v10->_padding[v6 + 3]) - (_QWORD)v10 - 32;
    if ( v13 < 0x48 )
    {
      if ( (-(signed int)v6 & (unsigned __int64)&v10->_padding[v6 + 3]) - (_QWORD)v10 != 32 )
      {
        v18 = v10->mPrev;
        *(UFG::allocator::block_header **)((char *)&v10[1].mPrev + (v10->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64)) = v10->mPrev;
        v19 = v10->mPrev;
        v20 = v10->mPrev->mSizeAndFlags & 3;
        v21 = (unsigned __int64)v10 + (v10->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) - (unsigned __int64)v10->mPrev;
        v10 = (UFG::allocator::block_header *)((-(signed int)v6 & (unsigned __int64)&v10->_padding[v6 + 3]) - 32);
        v19->mSizeAndFlags = v20 | v21;
        LODWORD(v20) = v10->mSizeAndFlags;
        v10->mPrev = v18;
        v22 = v20 & 3 | ((unsigned __int64)v18 + (v18->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) - (_QWORD)v10);
        v10->mSizeAndFlags = v22;
        *(UFG::allocator::block_header **)((char *)&v10[1].mPrev + (v22 & 0xFFFFFFFFFFFFFFFCui64)) = v10;
        v23 = v10->mPrev;
        v23->mSizeAndFlags &= 3ui64;
        v23->mSizeAndFlags |= (char *)v10 - (char *)v23 - 32;
        v10->mSizeAndFlags &= 0xFFFFFFFFFFFFFFFEui64;
        v10->mName = 0i64;
      }
    }
    else
    {
      v14 = *(_DWORD *)((-(signed int)v6 & (unsigned __int64)&v10->_padding[v6 + 3]) - 32 + 0x10);
      v15 = (UFG::allocator::block_header **)((-(signed int)v6 & (unsigned __int64)&v10->_padding[v6 + 3]) - 32);
      *v15 = v10;
      v16 = v14 & 3 | ((v10->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) - v13);
      v15[2] = (UFG::allocator::block_header *)v16;
      *(UFG::allocator::block_header **)((char *)v15 + (v16 & 0xFFFFFFFFFFFFFFFCui64) + 32) = (UFG::allocator::block_header *)v15;
      v17 = *v15;
      v17->mSizeAndFlags &= 3ui64;
      v17->mSizeAndFlags |= (char *)v15 - (char *)v17 - 32;
      v15[2] = (UFG::allocator::block_header *)((unsigned __int64)v15[2] & 0xFFFFFFFFFFFFFFFEui64);
      v15[1] = 0i64;
      UFG::allocator::tree_attach(v7, v10);
      v10 = (UFG::allocator::block_header *)((char *)v10 + (v10->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) + 32);
    }
    if ( (v10->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) >= v9 + 72 )
    {
      v24 = (signed __int64)&v10[1] + v9;
      v25 = *(_DWORD *)(v24 + 16);
      *(_QWORD *)v24 = v10;
      v26 = v25 & 3 | ((v10->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) - (v9 + 32));
      *(_QWORD *)(v24 + 16) = v26;
      *(_QWORD *)((v26 & 0xFFFFFFFFFFFFFFFCui64) + v24 + 32) = v24;
      v27 = *(_QWORD *)v24;
      *(_QWORD *)(v27 + 16) &= 3ui64;
      *(_QWORD *)(v27 + 16) |= (unsigned __int64)v10 + v9 - v27;
      *(_QWORD *)(v24 + 16) &= 0xFFFFFFFFFFFFFFFEui64;
      *(_QWORD *)(v24 + 8) = 0i64;
      v28 = v7->mMRFreeBlock;
      v29 = (unsigned __int64)&v10[1] + (v10->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64);
      if ( v28 )
      {
        if ( (v28->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64) <= 0x28 )
        {
          v30 = (UFG::qNode<UFG::allocator::small_free_node,UFG::allocator::small_free_node> *)&v28[1];
          v31 = v7->mSmallFreeList.mNode.mPrev;
          v31->mNext = v30;
          v30->mPrev = v31;
          v30->mNext = &v7->mSmallFreeList.mNode;
          v7->mSmallFreeList.mNode.mPrev = v30;
        }
        else
        {
          UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_insert(
            &v7->mFreeTree,
            (UFG::allocator::free_node *)&v28[1]);
        }
      }
      v7->mMRFreeBlock = (UFG::allocator::block_header *)v29;
    }
    v10->mSizeAndFlags |= 1ui64;
    v32 = v10->mSizeAndFlags;
    v10->mName = name;
    ++v7->mStats.mLargeAllocNumBlocks;
    v7->mStats.mLargeAllocNumBytes += (v32 & 0xFFFFFFFFFFFFFFFCui64) + 32;
    v33 = v7->mStats.mLargeAllocHighWaterNumBytes;
    if ( v7->mStats.mLargeAllocNumBytes > v33 )
      v33 = v7->mStats.mLargeAllocNumBytes;
    v7->mStats.mLargeAllocHighWaterNumBytes = v33;
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v7->mTreeMutex);
    result = v10 + 1;
  }
  else
  {
    UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v7->mTreeMutex);
    result = 0i64;
  }
  return result;
}

// File Line: 2367
// RVA: 0x18ECC0
void __fastcall UFG::allocator::tree_free(UFG::allocator *this, void *ptr)
{
  UFG::allocator::block_header *v2; // rbx
  UFG::allocator *v3; // rdi
  unsigned __int64 v4; // r8
  signed __int64 v5; // rdx
  UFG::allocator::block_header *v6; // rbx

  v2 = (UFG::allocator::block_header *)ptr;
  v3 = this;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mTreeMutex);
  v4 = v2[-1].mSizeAndFlags;
  --v3->mStats.mLargeAllocNumBlocks;
  v5 = (signed __int64)&v2[-1];
  v3->mStats.mLargeAllocNumBytes += -32i64 - (v4 & 0xFFFFFFFFFFFFFFFCui64);
  *(_QWORD *)(v5 + 16) &= 0xFFFFFFFFFFFFFFFEui64;
  *(_QWORD *)(v5 + 8) = 0i64;
  v6 = UFG::allocator::coalesce_block(v3, v2 - 1);
  UFG::allocator::tree_attach(v3, v6);
  if ( v3->mSystemMode == 1 )
    UFG::allocator::tree_purge_block(v3, v6);
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mTreeMutex);
}

// File Line: 2400
// RVA: 0x18ED60
void __fastcall UFG::allocator::tree_purge_block(UFG::allocator *this, UFG::allocator::block_header *bl)
{
  UFG::allocator::block_header *v2; // rbx
  UFG::allocator *v3; // rdi
  unsigned __int64 v4; // rax
  UFG::allocator::free_node *v5; // rdx
  UFG::intrusive_multi_rbtree_base::node_base *v6; // rcx
  UFG::intrusive_multi_rbtree_base::node_base *v7; // rax
  char *v8; // rax
  UFG::allocator::block_header *v9; // rdx
  UFG::allocator::block_header *v10; // rcx
  signed __int64 v11; // rax

  v2 = bl;
  v3 = this;
  if ( !bl->mPrev->mPrev )
  {
    v4 = bl->mSizeAndFlags & 0xFFFFFFFFFFFFFFFCui64;
    if ( !(*(unsigned __int64 *)((_BYTE *)&bl[1].mSizeAndFlags + v4) & 0xFFFFFFFFFFFFFFFCui64) )
    {
      if ( this->mMRFreeBlock == bl )
      {
        this->mMRFreeBlock = 0i64;
      }
      else
      {
        v5 = (UFG::allocator::free_node *)&bl[1];
        if ( v4 <= 0x28 )
        {
          v6 = v5->mChildren[0];
          v7 = v5->mChildren[1];
          v6->mChildren[1] = v7;
          v7->mChildren[0] = v6;
          v5->mChildren[0] = (UFG::intrusive_multi_rbtree_base::node_base *)v5->mChildren;
          v5->mChildren[1] = (UFG::intrusive_multi_rbtree_base::node_base *)v5->mChildren;
        }
        else
        {
          UFG::intrusive_multi_rbtree<UFG::allocator::free_node>::do_erase(&this->mFreeTree, v5);
        }
      }
      if ( v3->mSystemMode )
      {
        v8 = (char *)v2->mPrev[-1].mName;
        v9 = v2->mPrev[-1].mPrev;
        v10 = v2->mPrev - 1;
        v9->mName = v8;
        *(_QWORD *)v8 = v9;
        v10->mPrev = v10;
        v10->mName = (const char *)v10;
        v11 = -32i64 - v10->mSizeAndFlags;
        --v3->mStats.mSystemPageNumPages;
        v3->mStats.mSystemPageNumBytes += v11;
        v3->mStats.mLargePoolNumBytes += 32 - v10->mSizeAndFlags;
        UFG::qSystemFree(v10);
      }
    }
  }
}

