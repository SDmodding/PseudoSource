// File Line: 44
// RVA: 0x1413A0
void __fastcall UFG::DialogArgSet::~DialogArgSet(UFG::DialogArgSet *this)
{
  Render::Skinning *v1; // rdi
  Render::SkinningCacheNode *v2; // rbx
  Render::SkinningCacheNode *v3; // rbx

  this->vfptr = (UFG::DialogArgSetVtbl *)&UFG::DialogArgSet::`vftable';
  v1 = (Render::Skinning *)&this->m_argList;
  if ( this->m_argList.mTree.mCount )
  {
    do
    {
      v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&v1->mSkinnedVertexBuffers);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v1->mSkinnedVertexBuffers.mTree, &v2->mNode);
      UFG::qMemoryPool::Free(&g_AudioComponentPool, v2);
    }
    while ( v1->mSkinnedVertexBuffers.mTree.mCount );
  }
  while ( v1->mSkinnedVertexBuffers.mTree.mCount )
  {
    v3 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&v1->mSkinnedVertexBuffers);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v1->mSkinnedVertexBuffers.mTree, &v3->mNode);
    UFG::qMemoryPool::Free(&g_AudioComponentPool, v3);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB(v1);
}

// File Line: 64
// RVA: 0x14B5A0
void __fastcall UFG::DialogEvent::Resize(UFG::DialogEvent *this, unsigned int size)
{
  unsigned int v2; // eax
  UFG::qArray<unsigned long,0> *v3; // rdi
  signed int v4; // edx
  unsigned int v5; // ebx
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx

  v2 = this->m_args.size;
  v3 = &this->m_args;
  v4 = size - v2;
  if ( v4 <= 0 )
  {
    v8 = -v4;
    if ( v8 )
    {
      if ( v8 < v2 )
        v3->size = v2 - v8;
      else
        v3->size = 0;
    }
  }
  else
  {
    v5 = v2 + v4;
    v6 = this->m_args.capacity;
    if ( v5 > v6 )
    {
      if ( v6 )
        v7 = 2 * v6;
      else
        v7 = 1;
      for ( ; v7 < v5; v7 *= 2 )
        ;
      if ( v7 <= 4 )
        v7 = 4;
      if ( v7 - v5 > 0x10000 )
        v7 = v5 + 0x10000;
      UFG::qArray<long,0>::Reallocate(&this->m_args, v7, "DialgouEvent.Resize");
    }
    v3->size = v5;
  }
}

// File Line: 103
// RVA: 0x141390
void __fastcall UFG::DialogArgList::~DialogArgList(UFG::DialogArgList *this)
{
  this->vfptr = (UFG::DialogArgListVtbl *)&UFG::DialogArgList::`vftable';
}

