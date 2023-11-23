// File Line: 44
// RVA: 0x1413A0
void __fastcall UFG::DialogArgSet::~DialogArgSet(UFG::DialogArgSet *this)
{
  Render::Skinning *p_m_argList; // rdi
  Render::SkinningCacheNode *Head; // rbx
  Render::SkinningCacheNode *v3; // rbx

  this->vfptr = (UFG::DialogArgSetVtbl *)&UFG::DialogArgSet::`vftable;
  p_m_argList = (Render::Skinning *)&this->m_argList;
  if ( this->m_argList.mTree.mCount )
  {
    do
    {
      Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&p_m_argList->mSkinnedVertexBuffers);
      UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&p_m_argList->mSkinnedVertexBuffers.mTree, &Head->mNode);
      UFG::qMemoryPool::Free(&g_AudioComponentPool, Head);
    }
    while ( p_m_argList->mSkinnedVertexBuffers.mTree.mCount );
  }
  while ( p_m_argList->mSkinnedVertexBuffers.mTree.mCount )
  {
    v3 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&p_m_argList->mSkinnedVertexBuffers);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&p_m_argList->mSkinnedVertexBuffers.mTree, &v3->mNode);
    UFG::qMemoryPool::Free(&g_AudioComponentPool, v3);
  }
  UFG::qBaseTreeRB::~qBaseTreeRB(p_m_argList);
}

// File Line: 64
// RVA: 0x14B5A0
void __fastcall UFG::DialogEvent::Resize(UFG::DialogEvent *this, unsigned int size)
{
  unsigned int v2; // eax
  UFG::qArray<unsigned long,0> *p_m_args; // rdi
  int v4; // edx
  unsigned int v5; // ebx
  unsigned int capacity; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx

  v2 = this->m_args.size;
  p_m_args = &this->m_args;
  v4 = size - v2;
  if ( v4 <= 0 )
  {
    v8 = -v4;
    if ( v8 )
    {
      if ( v8 < v2 )
        p_m_args->size = v2 - v8;
      else
        p_m_args->size = 0;
    }
  }
  else
  {
    v5 = v2 + v4;
    capacity = this->m_args.capacity;
    if ( v5 > capacity )
    {
      if ( capacity )
        v7 = 2 * capacity;
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
    p_m_args->size = v5;
  }
}

// File Line: 103
// RVA: 0x141390
void __fastcall UFG::DialogArgList::~DialogArgList(UFG::DialogArgList *this)
{
  this->vfptr = (UFG::DialogArgListVtbl *)&UFG::DialogArgList::`vftable;
}

