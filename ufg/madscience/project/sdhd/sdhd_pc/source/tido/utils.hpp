// File Line: 59
// RVA: 0x5937A0
void __fastcall UFG::VisualEffectAudioTrack::VisualEffectAudioTrack(UFG::VisualEffectAudioTrack *this)
{
  UFG::qList<UFG::VisualEffectAudioNode,UFG::VisualEffectAudioNode,1,0> *p_m_nodes; // r8
  UFG::qNode<UFG::VisualEffectAudioNode,UFG::VisualEffectAudioNode> **p_mNext; // rax
  UFG::qSymbol *i; // r10
  _QWORD *v4; // rdx
  UFG::qNode<UFG::VisualEffectAudioNode,UFG::VisualEffectAudioNode> *v5; // rcx
  UFG::qNode<UFG::VisualEffectAudioNode,UFG::VisualEffectAudioNode> *v6; // rax

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->vfptr = (UFG::VisualEffectAudioTrackVtbl *)&UFG::VisualEffectAudioTrack::`vftable;
  this->m_visualEffect.mUID = -1;
  p_m_nodes = &this->m_nodes;
  this->m_nodes.mNode.mPrev = &this->m_nodes.mNode;
  this->m_nodes.mNode.mNext = &this->m_nodes.mNode;
  this->m_visualEffect = UFG::gNullQSymbol;
  p_mNext = &this->m_nodes.mNode.mNext[-1].mNext;
  for ( i = &this->m_visualEffect;
        p_mNext != (UFG::qNode<UFG::VisualEffectAudioNode,UFG::VisualEffectAudioNode> **)i;
        p_mNext = &p_m_nodes->mNode.mNext[-1].mNext )
  {
    v4 = p_mNext + 1;
    v5 = p_mNext[1];
    v6 = p_mNext[2];
    v5->mNext = v6;
    v6->mPrev = v5;
    *v4 = v4;
    v4[1] = v4;
  }
}

// File Line: 66
// RVA: 0x594AA0
void __fastcall UFG::VisualEffectAudioTrack::~VisualEffectAudioTrack(UFG::VisualEffectAudioTrack *this)
{
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *p_m_nodes; // rbx
  UFG::qSymbol *p_mNext; // rax
  UFG::qSymbol *i; // rdi
  UFG::qSymbol *v4; // rdx
  __int64 v5; // rcx
  _QWORD *v6; // rax
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *mPrev; // rcx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *mNext; // rax

  this->vfptr = (UFG::VisualEffectAudioTrackVtbl *)&UFG::VisualEffectAudioTrack::`vftable;
  p_m_nodes = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_nodes;
  p_mNext = (UFG::qSymbol *)&this->m_nodes.mNode.mNext[-1].mNext;
  for ( i = &this->m_visualEffect; p_mNext != i; p_mNext = (UFG::qSymbol *)&p_m_nodes->mNode.mNext[-1].mNext )
  {
    v4 = p_mNext + 2;
    v5 = *(_QWORD *)&p_mNext[2].mUID;
    v6 = *(_QWORD **)&p_mNext[4].mUID;
    *(_QWORD *)(v5 + 8) = v6;
    *v6 = v5;
    *(_QWORD *)&v4->mUID = v4;
    *(_QWORD *)&v4[2].mUID = v4;
    if ( v4 != (UFG::qSymbol *)8 )
      (**(void (__fastcall ***)(unsigned int *, __int64))&v4[-2].mUID)(&v4[-2].mUID, 1i64);
  }
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes(p_m_nodes);
  mPrev = p_m_nodes->mNode.mPrev;
  mNext = p_m_nodes->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_m_nodes->mNode.mPrev = &p_m_nodes->mNode;
  p_m_nodes->mNode.mNext = &p_m_nodes->mNode;
}

// File Line: 189
// RVA: 0x5949B0
void __fastcall UFG::SurfaceBankNode::~SurfaceBankNode(UFG::SurfaceBankNode *this)
{
  Render::Skinning *p_m_banks; // rdi
  Render::SkinningCacheNode *Head; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx

  this->vfptr = (UFG::SurfaceBankNodeVtbl *)&UFG::SurfaceBankNode::`vftable;
  p_m_banks = (Render::Skinning *)&this->m_banks;
  if ( this->m_banks.mTree.mCount )
  {
    while ( 1 )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&p_m_banks->mSkinnedVertexBuffers);
      if ( !Head )
        break;
      p_mCachedBufferPtr = &Head[-1].mCachedBufferPtr;
      if ( Head == (Render::SkinningCacheNode *)8 )
        goto LABEL_6;
      p_mNode = &Head->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&p_m_banks->mSkinnedVertexBuffers.mTree, p_mNode);
      if ( p_mCachedBufferPtr )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*p_mCachedBufferPtr)->mNode.mParent)(
          p_mCachedBufferPtr,
          1i64);
      if ( !p_m_banks->mSkinnedVertexBuffers.mTree.mCount )
        goto LABEL_10;
    }
    p_mCachedBufferPtr = 0i64;
LABEL_6:
    p_mNode = 0i64;
    goto LABEL_7;
  }
LABEL_10:
  UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll((UFG::qTreeRB<UFG::DialogEvent,UFG::DialogEvent,1> *)p_m_banks);
  UFG::qBaseTreeRB::~qBaseTreeRB(p_m_banks);
}

