// File Line: 94
// RVA: 0x948760
void __fastcall Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,75>>::~ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,75>>(Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> > *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *v1; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *v2; // rbx

  v1 = this->FirstPage;
  if ( this->FirstPage )
  {
    do
    {
      v2 = v1->pNext;
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v1 = v2;
    }
    while ( v2 );
  }
}

// File Line: 127
// RVA: 0x9557D0
Scaleform::Render::GlyphNode *__fastcall Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75>>::Alloc(Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> > *this, Scaleform::Render::GlyphNode *v)
{
  Scaleform::Render::GlyphNode *v2; // rbx
  Scaleform::Render::GlyphNode *result; // rax
  __int16 v4; // cx

  v2 = v;
  result = Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75>>::allocate(this);
  result->Param.pFont = v2->Param.pFont;
  *(_QWORD *)&result->Param.GlyphIndex = *(_QWORD *)&v2->Param.GlyphIndex;
  *(_QWORD *)&result->Param.BlurY = *(_QWORD *)&v2->Param.BlurY;
  result->pSlot = v2->pSlot;
  result->pNext = v2->pNext;
  result->pNex2 = v2->pNex2;
  result->mRect = v2->mRect;
  v4 = v2->Origin.y;
  result->Origin.x = v2->Origin.x;
  result->Origin.y = v4;
  result->Scale = v2->Scale;
  return result;
}

// File Line: 154
// RVA: 0x9CE2F0
Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::NodeType *__fastcall Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2>>::allocate(Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> > *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::NodeType *result; // rax
  Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> > *v2; // rbx
  unsigned int v3; // ecx
  void *v4; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *v5; // rcx
  int v6; // [rsp+30h] [rbp+8h]

  result = this->FirstEmptySlot;
  v2 = this;
  if ( result )
  {
    this->FirstEmptySlot = result->pNext;
  }
  else
  {
    v3 = this->NumElementsInPage;
    if ( v3 >= 0x7F )
    {
      v4 = v2->pHeapOrPtr;
      v6 = 2;
      result = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::NodeType *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, v4, 8136ui64, (Scaleform::AllocInfo *)&v6);
      result[1016].pNext = 0i64;
      v5 = v2->LastPage;
      if ( v5 )
        v5->pNext = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *)result;
      else
        v2->FirstPage = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *)result;
      v2->LastPage = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *)result;
      v2->NumElementsInPage = 1;
    }
    else
    {
      result = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::NodeType *)&v2->LastPage->Data[(unsigned __int64)v3];
      v2->NumElementsInPage = v3 + 1;
    }
  }
  return result;
}

