// File Line: 94
// RVA: 0x948760
void __fastcall Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,75>>::~ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,75>>(
        Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> > *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *FirstPage; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::PageType *pNext; // rbx

  FirstPage = this->FirstPage;
  if ( this->FirstPage )
  {
    do
    {
      pNext = FirstPage->pNext;
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      FirstPage = pNext;
    }
    while ( pNext );
  }
}

// File Line: 127
// RVA: 0x9557D0
Scaleform::Render::GlyphNode *__fastcall Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75>>::Alloc(
        Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> > *this,
        Scaleform::Render::GlyphNode *v)
{
  Scaleform::Render::GlyphNode *result; // rax
  __int16 y; // cx

  result = Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75>>::allocate(this);
  result->Param.pFont = v->Param.pFont;
  *(_QWORD *)&result->Param.GlyphIndex = *(_QWORD *)&v->Param.GlyphIndex;
  *(_QWORD *)&result->Param.BlurY = *(_QWORD *)&v->Param.BlurY;
  result->pSlot = v->pSlot;
  result->pNext = v->pNext;
  result->pNex2 = v->pNex2;
  result->mRect = v->mRect;
  y = v->Origin.y;
  result->Origin.x = v->Origin.x;
  result->Origin.y = y;
  result->Scale = v->Scale;
  return result;
}

// File Line: 154
// RVA: 0x9CE2F0
Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *__fastcall Scaleform::ListAllocBase<Scaleform::Render::BeginDisplayData,127,Scaleform::AllocatorLH_POD<Scaleform::Render::BeginDisplayData,2>>::allocate(
        Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> > *this)
{
  Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *result; // rax
  unsigned int NumElementsInPage; // ecx
  void *pHeapOrPtr; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *LastPage; // rcx
  int v6; // [rsp+30h] [rbp+8h] BYREF

  result = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *)this->FirstEmptySlot;
  if ( result )
  {
    this->FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::NodeType *)result->Data[0].pPrev;
  }
  else
  {
    NumElementsInPage = this->NumElementsInPage;
    if ( NumElementsInPage >= 0x7F )
    {
      pHeapOrPtr = this->pHeapOrPtr;
      v6 = 2;
      result = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, pHeapOrPtr, 8136i64, &v6);
      result->pNext = 0i64;
      LastPage = this->LastPage;
      if ( LastPage )
        LastPage->pNext = result;
      else
        this->FirstPage = result;
      this->LastPage = result;
      this->NumElementsInPage = 1;
    }
    else
    {
      result = (Scaleform::ListAllocBase<Scaleform::Render::FenceFrame,127,Scaleform::AllocatorLH<Scaleform::Render::FenceFrame,2> >::PageType *)((char *)this->LastPage + 64 * (unsigned __int64)NumElementsInPage);
      this->NumElementsInPage = NumElementsInPage + 1;
    }
  }
  return result;
}

