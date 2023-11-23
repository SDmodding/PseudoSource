// File Line: 29
// RVA: 0x615C0
UFG::qBaseNodeRB *__fastcall AllocateRenderQueue(
        UFG::qTreeRB<RenderQueueTreeNode,RenderQueueTreeNode,1> *render_queue_tree,
        unsigned int tree_node_uid,
        unsigned int is_alpha_queue)
{
  UFG::qBaseNodeRB *v3; // rbp
  UFG::qBaseNodeRB *v6; // rbx
  char *v7; // rax
  UFG::qBaseNodeRB *v8; // rax

  v3 = (UFG::qBaseNodeRB *)is_alpha_queue;
  if ( !tree_node_uid
    || (v6 = (UFG::qBaseNodeRB *)UFG::qBaseTreeRB::Get(&render_queue_tree->mTree, tree_node_uid)) == 0i64 )
  {
    v7 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x480u, 0x10u);
    if ( v7 )
    {
      RenderQueueTreeNode::RenderQueueTreeNode((RenderQueueTreeNode *)v7, tree_node_uid);
      v6 = v8;
    }
    else
    {
      v6 = 0i64;
    }
    if ( !v6 )
      return 0i64;
    v6[3].mParent = v3;
    UFG::qBaseTreeRB::Add(&render_queue_tree->mTree, v6);
  }
  return v6 + 1;
}

// File Line: 52
// RVA: 0x61270
void __fastcall RenderQueueLayer::RenderQueueLayer(RenderQueueLayer *this)
{
  this->mSerializationList = 0i64;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mTreeLayer0.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mTreeLayer1.mTree);
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mDeferredAlphaTree.mTree);
}

// File Line: 56
// RVA: 0x61390
void __fastcall RenderQueueLayer::~RenderQueueLayer(RenderQueueLayer *this)
{
  Render::Skinning *p_mDeferredAlphaTree; // rbx

  p_mDeferredAlphaTree = (Render::Skinning *)&this->mDeferredAlphaTree;
  UFG::qTreeRB<RenderQueueTreeNode,RenderQueueTreeNode,1>::DeleteAll(&this->mDeferredAlphaTree);
  UFG::qBaseTreeRB::~qBaseTreeRB(p_mDeferredAlphaTree);
  UFG::qTreeRB<RenderQueueTreeNode,RenderQueueTreeNode,1>::DeleteAll(&this->mTreeLayer1);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mTreeLayer1);
  UFG::qTreeRB<RenderQueueTreeNode,RenderQueueTreeNode,1>::DeleteAll(&this->mTreeLayer0);
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&this->mTreeLayer0);
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
void __fastcall RenderQueueLayer::AddRenderCommand(
        RenderQueueLayer *this,
        __int16 command_type,
        __int16 index,
        void *data)
{
  char *v8; // rax
  char *v9; // rbx
  __int64 v10; // rcx
  __int64 v11; // rdx
  __int64 v12; // rax
  char *v13; // rax
  char *v14; // rdx
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 v17; // rax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *mSerializationList; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax

  RenderQueueLayer::SerializeTree(this, &this->mTreeLayer0);
  RenderQueueLayer::SerializeTree(this, &this->mTreeLayer1);
  v8 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x460u, 0x10u);
  v9 = v8;
  if ( v8 )
  {
    *(_QWORD *)v8 = v8;
    *((_QWORD *)v8 + 1) = v8;
    *((_QWORD *)v8 + 2) = v8 + 16;
    *((_QWORD *)v8 + 3) = v8 + 16;
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
  v10 = *((_QWORD *)v9 + 5);
  if ( v10 )
  {
    v11 = *(unsigned int *)(v10 + 24);
    if ( (unsigned int)v11 < 0x7E )
    {
      *(_DWORD *)(v10 + 24) = v11 + 1;
      v12 = v10 + 16 * (v11 + 2);
      goto LABEL_12;
    }
    *((_DWORD *)v9 + 18) += *(_DWORD *)(v10 + 24);
    *((_QWORD *)v9 + 5) = 0i64;
  }
  v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x800u, 0x10u);
  v14 = v13;
  if ( v13 )
  {
    *(_QWORD *)v13 = v13;
    *((_QWORD *)v13 + 1) = v13;
    *((_QWORD *)v13 + 2) = 0i64;
    *((_DWORD *)v13 + 6) = 0;
    v15 = *((_QWORD *)v9 + 2);
    *(_QWORD *)(v15 + 8) = v14;
    *(_QWORD *)v14 = v15;
    *((_QWORD *)v14 + 1) = v9 + 16;
    *((_QWORD *)v9 + 2) = v14;
    *((_QWORD *)v9 + 5) = v14;
  }
  v16 = *((_QWORD *)v9 + 5);
  if ( v16 )
  {
    *(_DWORD *)(v16 + 24) = 1;
    v12 = *((_QWORD *)v9 + 5) + 32i64;
LABEL_12:
    if ( v12 )
    {
      *(_WORD *)v12 = command_type;
      *(_WORD *)(v12 + 2) = index;
      *(_QWORD *)(v12 + 8) = data;
    }
  }
  v17 = *((_QWORD *)v9 + 5);
  if ( v17 )
  {
    *((_DWORD *)v9 + 18) += *(_DWORD *)(v17 + 24);
    *((_QWORD *)v9 + 5) = 0i64;
  }
  mSerializationList = this->mSerializationList;
  mPrev = this->mSerializationList->mNode.mPrev;
  mPrev->mNext = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v9;
  *(_QWORD *)v9 = mPrev;
  *((_QWORD *)v9 + 1) = mSerializationList;
  mSerializationList->mNode.mPrev = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)v9;
}

// File Line: 109
// RVA: 0x61790
void __fastcall RenderQueueLayer::Merge(RenderQueueLayer *this, RenderQueueLayer *src_render_queue_game)
{
  Render::SkinningCacheNode *i; // rbx
  Render::SkinningCacheNode *j; // rbx
  Render::Skinning *p_mDeferredAlphaTree; // rdi
  Render::SkinningCacheNode *k; // rbx

  for ( i = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&src_render_queue_game->mTreeLayer0);
        i;
        i = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&src_render_queue_game->mTreeLayer0) )
  {
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&src_render_queue_game->mTreeLayer0,
      &i->mNode);
    UFG::qBaseTreeRB::Add(&this->mTreeLayer0.mTree, (UFG::qBaseNodeRB *)i);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&src_render_queue_game->mTreeLayer0);
  for ( j = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&src_render_queue_game->mTreeLayer1);
        j;
        j = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&src_render_queue_game->mTreeLayer1) )
  {
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&src_render_queue_game->mTreeLayer1,
      &j->mNode);
    UFG::qBaseTreeRB::Add(&this->mTreeLayer1.mTree, (UFG::qBaseNodeRB *)j);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB((Render::Skinning *)&src_render_queue_game->mTreeLayer1);
  p_mDeferredAlphaTree = (Render::Skinning *)&src_render_queue_game->mDeferredAlphaTree;
  for ( k = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&src_render_queue_game->mDeferredAlphaTree);
        k;
        k = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&p_mDeferredAlphaTree->mSkinnedVertexBuffers) )
  {
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&p_mDeferredAlphaTree->mSkinnedVertexBuffers.mTree, &k->mNode);
    UFG::qBaseTreeRB::Add(&this->mDeferredAlphaTree.mTree, (UFG::qBaseNodeRB *)k);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB(p_mDeferredAlphaTree);
}

// File Line: 116
// RVA: 0x618E0
void __fastcall RenderQueueLayer::SerializeTree(RenderQueueLayer *this, Render::Skinning *tree)
{
  UFG::qBaseTreeRB *i; // r9
  UFG::qBaseNodeRB *mParent; // rdx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *p_mNULL; // r8
  unsigned int mUID; // eax
  UFG::qList<Illusion::RenderQueue,Illusion::RenderQueue,1,0> *mSerializationList; // rcx
  UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *mPrev; // rax

  for ( i = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&tree->mSkinnedVertexBuffers);
        i;
        i = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)tree, &i->mRoot) )
  {
    mParent = i[1].mRoot.mParent;
    p_mNULL = (UFG::qNode<Illusion::RenderQueue,Illusion::RenderQueue> *)&i->mNULL;
    if ( mParent )
    {
      mUID = mParent->mUID;
      i[1].mRoot.mParent = 0i64;
      LODWORD(i[1].mNULL.mParent) += mUID;
    }
    mSerializationList = this->mSerializationList;
    mPrev = this->mSerializationList->mNode.mPrev;
    mPrev->mNext = p_mNULL;
    i->mNULL.mChild[0] = (UFG::qBaseNodeRB *)mSerializationList;
    p_mNULL->mPrev = mPrev;
    mSerializationList->mNode.mPrev = p_mNULL;
  }
  UFG::qBaseTreeRB::~qBaseTreeRB(tree);
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
  RenderQueueLayer::SerializeTree(this, &this->mTreeLayer0);
  RenderQueueLayer::SerializeTree(this, &this->mTreeLayer1);
}

