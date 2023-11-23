// File Line: 34
// RVA: 0x594BD0
void __fastcall UFG::SurfaceBankNode::operator delete(
        char *in_pMemAddress,
        unsigned __int64 in_size,
        unsigned int in_dwFreeType)
{
  UFG::qMemoryPool::Free(&g_AudioMemoryPool, in_pMemAddress);
}

// File Line: 58
// RVA: 0x5940E0
void __fastcall UFG::AudioUIScreen::~AudioUIScreen(UFG::AudioUIScreen *this)
{
  Render::Skinning *p_mInputList; // rdi
  Render::SkinningCacheNode *Head; // rax
  Illusion::Buffer **p_mCachedBufferPtr; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNode; // rdx

  this->vfptr = (UFG::AudioUIScreenVtbl *)&UFG::AudioUIScreen::`vftable;
  p_mInputList = (Render::Skinning *)&this->mInputList;
  if ( this->mInputList.mTree.mCount )
  {
    while ( 1 )
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&p_mInputList->mSkinnedVertexBuffers);
      if ( !Head )
        break;
      p_mCachedBufferPtr = &Head[-1].mCachedBufferPtr;
      if ( Head == (Render::SkinningCacheNode *)8 )
        goto LABEL_6;
      p_mNode = &Head->mNode;
LABEL_7:
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&p_mInputList->mSkinnedVertexBuffers.mTree, p_mNode);
      if ( p_mCachedBufferPtr )
        ((void (__fastcall *)(Illusion::Buffer **, __int64))(*p_mCachedBufferPtr)->mNode.mParent)(
          p_mCachedBufferPtr,
          1i64);
      if ( !p_mInputList->mSkinnedVertexBuffers.mTree.mCount )
        goto LABEL_10;
    }
    p_mCachedBufferPtr = 0i64;
LABEL_6:
    p_mNode = 0i64;
    goto LABEL_7;
  }
LABEL_10:
  UFG::qTreeRB<UFG::BankNode,UFG::BankNode,1>::DeleteAll((UFG::qTreeRB<UFG::DialogEvent,UFG::DialogEvent,1> *)p_mInputList);
  UFG::qBaseTreeRB::~qBaseTreeRB(p_mInputList);
}

