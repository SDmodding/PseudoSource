// File Line: 34
// RVA: 0x594BD0
void __fastcall UFG::SurfaceBankNode::operator delete(void *in_pMemAddress, unsigned __int64 in_size, unsigned int in_dwFreeType)
{
  UFG::qMemoryPool::Free(&g_AudioMemoryPool, in_pMemAddress);
}

// File Line: 58
// RVA: 0x5940E0
void __fastcall UFG::AudioUIScreen::~AudioUIScreen(UFG::AudioUIScreen *this)
{
  Render::Skinning *v1; // rdi
  Render::SkinningCacheNode *v2; // rax
  Illusion::Buffer **v3; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v4; // rdx

  this->vfptr = (UFG::AudioUIScreenVtbl *)&UFG::AudioUIScreen::`vftable';
  v1 = (Render::Skinning *)&this->mInputList;
  if ( this->mInputList.mTree.mCount )
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

