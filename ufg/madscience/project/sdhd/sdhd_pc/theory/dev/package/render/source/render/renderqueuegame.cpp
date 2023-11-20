// File Line: 29
// RVA: 0x615C0
UFG::qBaseNodeRB *__fastcall AllocateRenderQueue(UFG::qTreeRB<RenderQueueTreeNode,RenderQueueTreeNode,1> *render_queue_tree, unsigned int tree_node_uid, unsigned int is_alpha_queue)
{
  UFG::qBaseNodeRB *v3; // rbp
  unsigned int v4; // edi
  UFG::qTreeRB<RenderQueueTreeNode,RenderQueueTreeNode,1> *v5; // rsi
  UFG::qBaseNodeRB *v6; // rbx
  char *v7; // rax
  UFG::qBaseNodeRB *v8; // rax

  v3 = (UFG::qBaseNodeRB *)is_alpha_queue;
  v4 = tree_node_uid;
  v5 = render_queue_tree;
  if ( !tree_node_uid
    || (v6 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::Get(&render_queue_tree->mTree, tree_node_uid)) == 0i64 )
  {
    v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x480u, 0x10u);
    if ( v7 )
    {
      RenderQueueTreeNode::RenderQueueTreeNode((RenderQueueTreeNode *)v7, v4);
      v6 = v8;
    }
    else
    {
      v6 = 0i64;
    }
    if ( !v6 )
      return 0i64;
    v6[3].mParent = v3;
    UFG::qBaseTreeRB::Add(&v5->mTree, v6);
  }
  return v6 + 1;
}

// File Line: 52
// RVA: 0x61270
void __fastcall RenderQueueLayer::RenderQueueLayer(RenderQueueLayer *this)
{
  RenderQueueLayer *v1; // rbx

  v1 = this;
  this->mSerializationList = 0i64;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mTreeLayer0.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mTreeLayer1.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&v1->mDeferredAlphaTree.mTree);
}

// File Line: 56
// RVA: 0x61390
void __fastcall RenderQueueLayer::~RenderQueueLayer(RenderQueueLayer *this)
{
  RenderQueueLayer *v1; // rdi
  Render::Skinning *v2; // rbx

  v1 = this;
  v2 = (Render::Skinning *)&this->mDeferredAlphaTree;
  UFG::qTreeRB<RenderQueueTreeNode,RenderQueueTreeNode,1>::DeleteAll(&this->mDeferredAlphaTree);
  UFG::qBaseTreeRB::~qBaseTreeRB(v2);
  UFG::qTreeRB<RenderQueueTreeNode,RenderQueueTreeNode,1>::DeleteAll(&v1->mTreeLayer1);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->mTreeLayer1);
  UFG::qTreeRB<RenderQueueTreeNode,RenderQueueTreeNode,1>::DeleteAll(&v1->mTreeLayer0);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v1->mTreeLayer0);
}

// File Line: 61
// RVA: 0x61780
UFG::qBaseNodeRB *__fastcall RenderQueueLayer::GetSolidRenderQueue(RenderQueueLayer *this, unsigned int uid)
{
  return AllocateRenderQueue(&this->mTreeLayer0, uid, 0);
}

// File Line: 66
// RVA: 0x61770
UFG::qBaseNodeRB *__fastcall RenderQueueLayer::GetSolid1RenderQueue(RenderQueueLayer *this, unsigned int uid)
{
  return AllocateRenderQueue(&this->mTreeLayer1, uid, 0);
}

// File Line: 71
// RVA: 0x61750
UFG::qBaseNodeRB *__fastcall RenderQueueLayer::GetAlphaRenderQueue(RenderQueueLayer *this, unsigned int uid)
{
  return AllocateRenderQueue(&this->mDeferredAlphaTree, uid, 1u);
}

// File Line: 76
// RVA: 0x61410
void __fastcall RenderQueueLayer::AddRenderCommand(RenderQueueLayer *this, __int16 command_type, __int16 index, void *data)
{
  void *v4; // rbp
  __int16 v5; // r14
  __int16 v6; // r15
  RenderQueueLayer *v7; // rsi
  char *v8; // rax
  char *v9; // rbx
  _QWORD *v10; // ST30_8
  __int64 v11; // rcx
  __int64 v12; // rdx
  signed __int64 v13; // rax
  char *v14; // rax
  char *v15; // rdx
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v19; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v20; // rax

  v4 = data;
  v5 = index;
  v6 = command_type;
  v7 = this;
  RenderQueueLayer::SerializeTree(this, &this->mTreeLayer0);
  RenderQueueLayer::SerializeTree(v7, &v7->mTreeLayer1);
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
  v9 = v8;
  if ( v8 )
  {
    *(_QWORD *)v8 = v8;
    *((_QWORD *)v8 + 1) = v8;
    v10 = v8 + 16;
    *v10 = v10;
    v10[1] = v10;
    UFG::qMemSet(v8 + 96, 0, 0x400u);
    *((_QWORD *)v9 + 11) = 0i64;
    *((_QWORD *)v9 + 10) = 0i64;
    *((_DWORD *)v9 + 8) = 0;
    *((_QWORD *)v9 + 5) = 0i64;
    *((_QWORD *)v9 + 6) = 0i64;
    *((_QWORD *)v9 + 7) = 0i64;
    *((_QWORD *)v9 + 8) = 0i64;
    *((_QWORD *)v9 + 9) = 0i64;
  }
  else
  {
    v9 = 0i64;
  }
  v11 = *((_QWORD *)v9 + 5);
  if ( v11 )
  {
    v12 = *(unsigned int *)(v11 + 24);
    if ( (unsigned int)v12 < 0x7E )
    {
      *(_DWORD *)(v11 + 24) = v12 + 1;
      v13 = v11 + 16 * (v12 + 2);
      goto LABEL_13;
    }
    if ( v11 )
    {
      *((_DWORD *)v9 + 18) += *(_DWORD *)(v11 + 24);
      *((_QWORD *)v9 + 5) = 0i64;
    }
  }
  v14 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v15 = v14;
  if ( v14 )
  {
    *(_QWORD *)v14 = v14;
    *((_QWORD *)v14 + 1) = v14;
    *((_QWORD *)v14 + 2) = 0i64;
    *((_DWORD *)v14 + 6) = 0;
    v16 = *((_QWORD *)v9 + 2);
    *(_QWORD *)(v16 + 8) = v15;
    *(_QWORD *)v15 = v16;
    *((_QWORD *)v15 + 1) = v9 + 16;
    *((_QWORD *)v9 + 2) = v15;
    *((_QWORD *)v9 + 5) = v15;
  }
  v17 = *((_QWORD *)v9 + 5);
  if ( v17 )
  {
    *(_DWORD *)(v17 + 24) = 1;
    v13 = *((_QWORD *)v9 + 5) + 32i64;
LABEL_13:
    if ( v13 )
    {
      *(_WORD *)v13 = v6;
      *(_WORD *)(v13 + 2) = v5;
      *(_QWORD *)(v13 + 8) = v4;
    }
  }
  v18 = *((_QWORD *)v9 + 5);
  if ( v18 )
  {
    *((_DWORD *)v9 + 18) += *(_DWORD *)(v18 + 24);
    *((_QWORD *)v9 + 5) = 0i64;
  }
  v19 = v7->mSerializationList;
  v20 = v7->mSerializationList->mNode.mPrev;
  v20->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v9;
  *(_QWORD *)v9 = v20;
  *((_QWORD *)v9 + 1) = v19;
  v19->mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v9;
}

// File Line: 109
// RVA: 0x61790
void __fastcall RenderQueueLayer::Merge(RenderQueueLayer *this, RenderQueueLayer *src_render_queue_game)
{
  RenderQueueLayer *v2; // rbp
  RenderQueueLayer *v3; // r14
  Render::SkinningCacheNode *i; // rbx
  Render::SkinningCacheNode *j; // rbx
  Render::Skinning *v6; // rdi
  Render::SkinningCacheNode *k; // rbx

  v2 = this;
  v3 = src_render_queue_game;
  for ( i = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&src_render_queue_game->mTreeLayer0);
        i;
        i = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mTreeLayer0) )
  {
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mTreeLayer0,
      &i->mNode);
    UFG::qBaseTreeRB::Add(&v2->mTreeLayer0.mTree, (UFG::qBaseNodeRB *)i);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v3->mTreeLayer0);
  for ( j = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mTreeLayer1);
        j;
        j = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mTreeLayer1) )
  {
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&v3->mTreeLayer1,
      &j->mNode);
    UFG::qBaseTreeRB::Add(&v2->mTreeLayer1.mTree, (UFG::qBaseNodeRB *)j);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&v3->mTreeLayer1);
  v6 = (Render::Skinning *)&v3->mDeferredAlphaTree;
  for ( k = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&v3->mDeferredAlphaTree);
        k;
        k = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&v6->mSkinnedVertexBuffers) )
  {
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v6->mSkinnedVertexBuffers.mTree, &k->mNode);
    UFG::qBaseTreeRB::Add(&v2->mDeferredAlphaTree.mTree, (UFG::qBaseNodeRB *)k);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB(v6);
}

// File Line: 116
// RVA: 0x618E0
void __fastcall RenderQueueLayer::SerializeTree(RenderQueueLayer *this, UFG::qTreeRB<RenderQueueTreeNode,RenderQueueTreeNode,1> *tree)
{
  RenderQueueLayer *v2; // rdi
  UFG::qTreeRB<RenderQueueTreeNode,RenderQueueTreeNode,1> *v3; // rbx
  UFG::qBaseTreeRB *i; // r9
  UFG::qBaseNodeRB *v5; // rdx
  UFG::qBaseNodeRB *v6; // r8
  unsigned int v7; // eax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *v8; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *v9; // rax

  v2 = this;
  v3 = tree;
  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)tree);
        i;
        i = UFG::qBaseTreeRB::GetNext(&v3->mTree, &i->mRoot) )
  {
    v5 = i[1].mRoot.mParent;
    v6 = &i->mNULL;
    if ( v5 )
    {
      v7 = v5->mUID;
      i[1].mRoot.mParent = 0i64;
      LODWORD(i[1].mNULL.mParent) += v7;
    }
    v8 = v2->mSerializationList;
    v9 = v2->mSerializationList->mNode.mPrev;
    v9->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v6;
    i->mNULL.mChild[0] = (UFG::qBaseNodeRB *)v8;
    v6->mParent = (UFG::qBaseNodeRB *)v9;
    v8->mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v6;
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)v3);
}

// File Line: 128
// RVA: 0x618A0
void __fastcall RenderQueueLayer::SerializeDeferredAlpha(RenderQueueLayer *this)
{
  RenderQueueLayer::SerializeTree(this, &this->mDeferredAlphaTree);
}

// File Line: 133
// RVA: 0x618B0
void __fastcall RenderQueueLayer::SerializeRenderQueues(RenderQueueLayer *this)
{
  RenderQueueLayer *v1; // rbx

  v1 = this;
  RenderQueueLayer::SerializeTree(this, &this->mTreeLayer0);
  RenderQueueLayer::SerializeTree(v1, &v1->mTreeLayer1);
}

