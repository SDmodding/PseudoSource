// File Line: 59
// RVA: 0x5937A0
void __fastcall UFG::VisualEffectAudioTrack::VisualEffectAudioTrack(UFG::VisualEffectAudioTrack *this)
{
  UFG::qList<UFG::VisualEffectAudioNode,UFG::VisualEffectAudioNode,1,0> *v1; // r8
  UFG::qNode<UFG::VisualEffectAudioNode,UFG::VisualEffectAudioNode> **v2; // rax
  UFG::qSymbol *v3; // r10
  _QWORD *v4; // rdx
  UFG::qNode<UFG::VisualEffectAudioNode,UFG::VisualEffectAudioNode> *v5; // rcx
  UFG::qNode<UFG::VisualEffectAudioNode,UFG::VisualEffectAudioNode> *v6; // rax

  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->vfptr = (UFG::VisualEffectAudioTrackVtbl *)&UFG::VisualEffectAudioTrack::`vftable';
  this->m_visualEffect.mUID = -1;
  v1 = &this->m_nodes;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
  this->m_visualEffect = UFG::gNullQSymbol;
  v2 = &this->m_nodes.mNode.mNext[-1].mNext;
  v3 = &this->m_visualEffect;
  if ( v2 != (UFG::qNode<UFG::VisualEffectAudioNode,UFG::VisualEffectAudioNode> **)&this->m_visualEffect )
  {
    do
    {
      v4 = v2 + 1;
      v5 = v2[1];
      v6 = v2[2];
      v5->mNext = v6;
      v6->mPrev = v5;
      *v4 = v4;
      v4[1] = v4;
      v2 = &v1->mNode.mNext[-1].mNext;
    }
    while ( v2 != (UFG::qNode<UFG::VisualEffectAudioNode,UFG::VisualEffectAudioNode> **)v3 );
  }
}

// File Line: 66
// RVA: 0x594AA0
void __fastcall UFG::VisualEffectAudioTrack::~VisualEffectAudioTrack(UFG::VisualEffectAudioTrack *this)
{
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v1; // rbx
  UFG::qSymbol *v2; // rax
  UFG::qSymbol *v3; // rdi
  UFG::qSymbol *v4; // rdx
  __int64 v5; // rcx
  _QWORD *v6; // rax
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v7; // rcx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v8; // rax

  this->vfptr = (UFG::VisualEffectAudioTrackVtbl *)&UFG::VisualEffectAudioTrack::`vftable';
  v1 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_nodes;
  v2 = (UFG::qSymbol *)&this->m_nodes.mNode.mNext[-1].mNext;
  v3 = &this->m_visualEffect;
  if ( v2 != &this->m_visualEffect )
  {
    do
    {
      v4 = v2 + 2;
      v5 = *(_QWORD *)&v2[2].mUID;
      v6 = *(_QWORD **)&v2[4].mUID;
      *(_QWORD *)(v5 + 8) = v6;
      *v6 = v5;
      *(_QWORD *)&v4->mUID = v4;
      *(_QWORD *)&v4[2].mUID = v4;
      if ( v4 != (UFG::qSymbol *)8 )
        (**(void (__fastcall ***)(unsigned int *, signed __int64))&v4[-2].mUID)(&v4[-2].mUID, 1i64);
      v2 = (UFG::qSymbol *)&v1->mNode.mNext[-1].mNext;
    }
    while ( v2 != v3 );
  }
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes(v1);
  v7 = v1->mNode.mPrev;
  v8 = v1->mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
}

// File Line: 189
// RVA: 0x5949B0
void __fastcall UFG::SurfaceBankNode::~SurfaceBankNode(UFG::SurfaceBankNode *this)
{
  Render::Skinning *v1; // rdi
  Render::SkinningCacheNode *v2; // rax
  Illusion::Buffer **v3; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rdx

  this->vfptr = (UFG::SurfaceBankNodeVtbl *)&UFG::SurfaceBankNode::`vftable';
  v1 = (Render::Skinning *)&this->m_banks;
  if ( this->m_banks.mTree.mCount )
  {
    while ( 1 )
    {
      v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&v1->mSkinnedVertexBuffers);
      if ( !v2 )
        break;
      v3 = &v2[-1].mCachedBufferPtr;
      if ( v2 == (Render::SkinningCacheNode *)8 )
        goto LABEL_6;
      v4 = &v2->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v1->mSkinnedVertexBuffers.mTree, v4);
      if ( v3 )
        ((void (__fastcall *)(Illusion::Buffer **, signed __int64))(*v3)->mNode.mParent)(v3, 1i64);
      if ( !v1->mSkinnedVertexBuffers.mTree.mCount )
        goto LABEL_10;
    }
    v3 = 0i64;
LABEL_6:
    v4 = 0i64;
    goto LABEL_7;
  }
LABEL_10:
  UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll((UFG::qTreeRB<UFG::DialogEvent,UFG::DialogEvent,1> *)v1);
  UFG::qBaseTreeRB::~qBaseTreeRB(v1);
}

