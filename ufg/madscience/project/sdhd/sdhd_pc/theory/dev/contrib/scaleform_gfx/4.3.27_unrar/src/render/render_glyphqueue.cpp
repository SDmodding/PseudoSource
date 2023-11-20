// File Line: 44
// RVA: 0x93CA50
void __fastcall Scaleform::Render::GlyphQueue::GlyphQueue(Scaleform::Render::GlyphQueue *this)
{
  Scaleform::Render::GlyphQueue *v1; // rdx
  Scaleform::ListAllocLH_POD<Scaleform::Render::GlyphSlot,127,75> *v2; // rax
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *v3; // rax
  Scaleform::List2<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot_Active> *v4; // rcx
  Scaleform::List<Scaleform::Render::TextNotifier,Scaleform::Render::TextNotifier> *v5; // rax
  signed __int64 v6; // rax
  Scaleform::ArrayUnsafeLH_POD<Scaleform::Render::GlyphBand,75> *v7; // rax
  signed __int64 v8; // rax

  v1 = this;
  *(_QWORD *)&this->MinSlotSpace = 10i64;
  *(_QWORD *)&this->NumTextures = 0i64;
  *(_QWORD *)&this->TextureHeight = 0i64;
  this->NumBandsInTexture = 0;
  v2 = &this->Slots;
  v2->FirstPage = 0i64;
  v2->LastPage = 0i64;
  v2->NumElementsInPage = 127;
  v2->FirstEmptySlot = 0i64;
  v2->pHeapOrPtr = v2;
  v3 = &this->SlotQueue;
  v3->Root.pPrev = (Scaleform::Render::GlyphSlot *)v3;
  v3->Root.pNext = (Scaleform::Render::GlyphSlot *)v3;
  this->SlotQueueSize = 0;
  v4 = &this->ActiveSlots;
  v5 = &v4->Root.TextFields;
  v5->Root.pPrev = (Scaleform::Render::TextNotifier *)v5;
  v5->Root.pNext = (Scaleform::Render::TextNotifier *)v5;
  v4->Root.SlotFence.pObject = 0i64;
  v4->Root.pPrevActive = &v4->Root;
  v4->Root.pNextActive = &v4->Root;
  v6 = (signed __int64)&v1->Glyphs;
  *(_QWORD *)v6 = 0i64;
  *(_QWORD *)(v6 + 8) = 0i64;
  *(_DWORD *)(v6 + 16) = 127;
  *(_QWORD *)(v6 + 24) = 0i64;
  *(_QWORD *)(v6 + 32) = v6;
  v7 = &v1->Bands;
  v7->Data = 0i64;
  v7->Size = 0i64;
  v7->Capacity = 0i64;
  v1->GlyphHTable.mHash.pTable = 0i64;
  v1->NumUsedBands = 0;
  v8 = (signed __int64)&v1->Notifiers;
  *(_QWORD *)v8 = 0i64;
  *(_QWORD *)(v8 + 8) = 0i64;
  *(_DWORD *)(v8 + 16) = 127;
  *(_QWORD *)(v8 + 24) = 0i64;
  *(_QWORD *)(v8 + 32) = v8;
  v1->pEvictNotifier = 0i64;
}

// File Line: 49
// RVA: 0x95F3D0
void __fastcall Scaleform::Render::GlyphQueue::Clear(Scaleform::Render::GlyphQueue *this)
{
  Scaleform::Render::GlyphSlot *v1; // rdi
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *v2; // r14
  Scaleform::Render::GlyphQueue *v3; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> >::TableType *v4; // rax
  __int64 v5; // rcx
  signed __int64 v6; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> >::TableType *v7; // rax
  signed __int64 v8; // rax
  unsigned int v9; // edx
  __int64 v10; // rcx
  signed __int64 v11; // rcx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::PageType *v12; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::PageType *v13; // rdi
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::PageType *v14; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::PageType *v15; // rdi

  v1 = this->SlotQueue.Root.pNext;
  v2 = &this->SlotQueue;
  v3 = this;
  if ( v1 != (Scaleform::Render::GlyphSlot *)&this->SlotQueue )
  {
    do
    {
      while ( (Scaleform::List<Scaleform::Render::TextNotifier,Scaleform::Render::TextNotifier> *)v1->TextFields.Root.pNext != &v1->TextFields )
        v3->pEvictNotifier->vfptr->Evict(v3->pEvictNotifier, v1->TextFields.Root.pNext->pText);
      v1 = v1->pNext;
    }
    while ( v1 != (Scaleform::Render::GlyphSlot *)v2 );
  }
  v4 = v3->GlyphHTable.mHash.pTable;
  if ( v4 )
  {
    v5 = 0i64;
    v6 = v4->SizeMask + 1;
    do
    {
      v7 = v3->GlyphHTable.mHash.pTable;
      if ( v7[v5 + 1].EntryCount != -2i64 )
        v7[v5 + 1].EntryCount = -2i64;
      v5 += 2i64;
      --v6;
    }
    while ( v6 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3->GlyphHTable.mHash.pTable);
    v3->GlyphHTable.mHash.pTable = 0i64;
  }
  v2->Root.pPrev = (Scaleform::Render::GlyphSlot *)v2;
  v2->Root.pNext = (Scaleform::Render::GlyphSlot *)v2;
  v8 = (signed __int64)&v3->ActiveSlots;
  v9 = 0;
  *(_QWORD *)(v8 + 40) = v8;
  for ( *(_QWORD *)(v8 + 48) = v8; v9 < v3->NumUsedBands; *(_QWORD *)(v11 + 32) = v11 )
  {
    v10 = v9++;
    v11 = (signed __int64)&v3->Bands.Data[v10].Slots;
    *(_QWORD *)(v11 + 24) = v11;
  }
  v12 = v3->Slots.FirstPage;
  if ( v12 )
  {
    do
    {
      v13 = v12->pNext;
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v12 = v13;
    }
    while ( v13 );
  }
  v3->Slots.FirstPage = 0i64;
  v3->Slots.LastPage = 0i64;
  v3->Slots.NumElementsInPage = 127;
  v3->Slots.FirstEmptySlot = 0i64;
  v14 = v3->Glyphs.FirstPage;
  if ( v14 )
  {
    do
    {
      v15 = v14->pNext;
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v14 = v15;
    }
    while ( v15 );
  }
  v3->Glyphs.FirstPage = 0i64;
  v3->Glyphs.LastPage = 0i64;
  v3->Glyphs.FirstEmptySlot = 0i64;
  v3->Glyphs.NumElementsInPage = 127;
  v3->SlotQueueSize = 0;
  v3->NumUsedBands = 0;
}

// File Line: 118
// RVA: 0x9EB7B0
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::packGlyph(Scaleform::Render::GlyphQueue *this, unsigned int w, unsigned int h, Scaleform::Render::GlyphNode *glyph)
{
  Scaleform::Render::GlyphNode *v4; // rbx
  unsigned int v5; // edi
  unsigned int v6; // esi
  Scaleform::Render::GlyphNode *v7; // r9
  Scaleform::Render::GlyphNode *v8; // r10
  Scaleform::Render::GlyphNode *result; // rax
  Scaleform::Render::GlyphNode *v10; // r9
  unsigned int v11; // ebp
  unsigned int v12; // edi
  unsigned int v13; // edi
  unsigned int v14; // ebp
  Scaleform::Render::GlyphNode *v15; // rax
  Scaleform::Render::GlyphNode *v16; // rax
  Scaleform::Render::GlyphNode *v17; // rax
  Scaleform::Render::GlyphQueue *v18; // [rsp+40h] [rbp+8h]
  unsigned int v19; // [rsp+50h] [rbp+18h]

  v19 = h;
  v18 = this;
  v4 = glyph;
  v5 = h;
  v6 = w;
  if ( glyph->Param.pFont )
  {
    v7 = glyph->pNext;
    v8 = 0i64;
    if ( v7 )
    {
      result = Scaleform::Render::GlyphQueue::packGlyph(this, w, h, v7);
      v8 = result;
      if ( result )
        return result;
      this = v18;
    }
    v10 = v4->pNex2;
    if ( v10 )
      v8 = Scaleform::Render::GlyphQueue::packGlyph(this, v6, v5, v10);
    result = v8;
  }
  else
  {
    v11 = glyph->mRect.w;
    if ( w > v11 || (v12 = glyph->mRect.h, h > v12) )
    {
      result = 0i64;
    }
    else
    {
      v13 = v12 - h;
      v14 = v11 - w;
      if ( v14 >= this->MinSlotSpace || v13 >= this->MinSlotSpace )
      {
        v15 = Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75>>::Alloc(
                (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> > *)&this->Glyphs.FirstPage,
                glyph);
        v4->pNext = v15;
        if ( v14 <= v13 )
        {
          v15->mRect.y = v19 + v4->mRect.y;
          v4->pNext->mRect.h = v13;
          if ( v14 >= v18->MinSlotSpace )
          {
            v17 = Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75>>::Alloc(
                    (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> > *)&v18->Glyphs.FirstPage,
                    v4);
            v4->pNex2 = v17;
            v17->pNext = 0i64;
            v4->pNex2->mRect.x = v6 + v4->mRect.x;
            v4->pNex2->mRect.w = v14;
            v4->pNex2->mRect.h = v19;
          }
        }
        else
        {
          v15->mRect.x = v6 + v4->mRect.x;
          v4->pNext->mRect.w = v14;
          if ( v13 >= v18->MinSlotSpace )
          {
            v16 = Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75>>::Alloc(
                    (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> > *)&v18->Glyphs.FirstPage,
                    v4);
            v4->pNex2 = v16;
            v16->pNext = 0i64;
            v4->pNex2->mRect.y = v19 + v4->mRect.y;
            v4->pNex2->mRect.h = v13;
            v4->pNex2->mRect.w = v6;
            v4->mRect.w = v6;
            v4->mRect.h = v19;
            return v4;
          }
        }
      }
      v4->mRect.w = v6;
      v4->mRect.h = v19;
      result = v4;
    }
  }
  return result;
}

// File Line: 192
// RVA: 0x9F3320
void __fastcall Scaleform::Render::GlyphQueue::splitSlot(Scaleform::Render::GlyphQueue *this, Scaleform::Render::GlyphSlot *slot, unsigned int w)
{
  unsigned __int16 v3; // bx
  Scaleform::Render::GlyphSlot *v4; // rdi
  Scaleform::Render::GlyphQueue *v5; // rsi
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *v6; // rax
  Scaleform::Render::GlyphNode *v7; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *v8; // r8
  Scaleform::Render::GlyphSlot *v9; // rax
  signed __int64 v10; // rcx
  Scaleform::Render::GlyphSlot *v11; // rax

  v3 = w;
  v4 = slot;
  v5 = this;
  v6 = Scaleform::Render::GlyphQueue::initNewSlot(this, slot->pBand, w + slot->x, slot->w - w);
  v7 = v4->pRoot;
  v4->w = v3;
  v7->mRect.w = v3;
  v6[1].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)v5->SlotQueue.Root.pNext;
  v8 = v6;
  v6->pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)&v5->SlotQueue;
  v5->SlotQueue.Root.pNext->pPrev = (Scaleform::Render::GlyphSlot *)v6;
  v5->SlotQueue.Root.pNext = (Scaleform::Render::GlyphSlot *)v6;
  ++v5->SlotQueueSize;
  v9 = v4->pNextInBand;
  v8[3].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)v4;
  v10 = (signed __int64)&v5->ActiveSlots;
  v8[4].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)v9;
  v9->pPrevInBand = (Scaleform::Render::GlyphSlot *)v8;
  v4->pNextInBand = (Scaleform::Render::GlyphSlot *)v8;
  v11 = v5->ActiveSlots.Root.pNextActive;
  v8[5].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)&v5->ActiveSlots;
  v8[6].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)v11;
  *(_QWORD *)(*(_QWORD *)(v10 + 48) + 40i64) = v8;
  *(_QWORD *)(v10 + 48) = v8;
}

// File Line: 208
// RVA: 0x9F2A00
void __fastcall Scaleform::Render::GlyphQueue::splitGlyph(Scaleform::Render::GlyphQueue *this, Scaleform::Render::GlyphSlot *slot, bool left, unsigned int w)
{
  Scaleform::Render::GlyphNode *v4; // rbp
  Scaleform::Render::GlyphSlot *v5; // rbx
  Scaleform::Render::GlyphBand *v6; // rdx
  unsigned __int16 v7; // r14
  Scaleform::Render::GlyphQueue *v8; // rsi
  unsigned int v9; // edi
  bool v10; // zf
  int v11; // er8
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *v12; // rax
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *v13; // rcx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *v14; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *v15; // rax
  Scaleform::Render::GlyphSlot *v16; // rax

  v4 = slot->pRoot;
  v5 = slot;
  v6 = slot->pBand;
  v7 = w;
  v8 = this;
  v9 = v4->mRect.w - w;
  v10 = left == 0;
  v11 = v4->mRect.x;
  if ( v10 )
  {
    v14 = Scaleform::Render::GlyphQueue::initNewSlot(this, v6, w + v11, v9);
    v15 = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)v5->pNextInBand;
    v14[4].pNext = v15;
    v14[3].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)v5;
    v15[3].pNext = v14;
    v5->pNextInBand = (Scaleform::Render::GlyphSlot *)v14;
  }
  else
  {
    v12 = Scaleform::Render::GlyphQueue::initNewSlot(this, v6, v11, v9);
    v13 = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)v5->pPrevInBand;
    v12[4].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)v5;
    v12[3].pNext = v13;
    v13[4].pNext = v12;
    v5->x += v9;
    LOWORD(v13) = v5->x;
    v5->pPrevInBand = (Scaleform::Render::GlyphSlot *)v12;
    v4->mRect.x = (unsigned __int16)v13;
    v14 = v12;
  }
  v4->mRect.w = v7;
  v5->w -= v9;
  v14[1].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)v8->SlotQueue.Root.pNext;
  v14->pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)&v8->SlotQueue;
  v8->SlotQueue.Root.pNext->pPrev = (Scaleform::Render::GlyphSlot *)v14;
  v8->SlotQueue.Root.pNext = (Scaleform::Render::GlyphSlot *)v14;
  ++v8->SlotQueueSize;
  v16 = v8->ActiveSlots.Root.pNextActive;
  v14[5].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)&v8->ActiveSlots;
  v14[6].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)v16;
  v8->ActiveSlots.Root.pNextActive->pPrevActive = (Scaleform::Render::GlyphSlot *)v14;
  v8->ActiveSlots.Root.pNextActive = (Scaleform::Render::GlyphSlot *)v14;
}

// File Line: 233
// RVA: 0x9EB960
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::packGlyph(Scaleform::Render::GlyphQueue *this, unsigned int w, unsigned int h, Scaleform::Render::GlyphSlot *slot)
{
  Scaleform::Render::GlyphSlot *v4; // rbx
  Scaleform::Render::GlyphNode *v5; // r9
  unsigned int v6; // ebp
  unsigned int v7; // edi
  Scaleform::Render::GlyphQueue *v8; // rsi
  unsigned int v9; // er10
  unsigned int v10; // edx
  int v11; // ecx
  int v12; // eax
  Scaleform::Render::GlyphNode *result; // rax
  unsigned __int16 v14; // cx

  v4 = slot;
  v5 = slot->pRoot;
  v6 = h;
  v7 = w;
  v8 = this;
  if ( !v5->Param.pFont )
  {
    v9 = v4->w;
    if ( v9 > 2 * w )
    {
      if ( v5->pNext )
      {
        if ( !v5->pNex2 && v5->mRect.h == v4->pBand->h )
        {
          v10 = v5->mRect.w;
          if ( v10 > v7 )
          {
            v11 = v5->mRect.x;
            v12 = v4->x;
            if ( ((_WORD)v11 == (_WORD)v12) != (v10 + v11 == v9 + v12) )
              Scaleform::Render::GlyphQueue::splitGlyph(v8, v4, (_WORD)v11 == (_WORD)v12, v7);
          }
        }
      }
      else if ( !v5->pNex2 )
      {
        Scaleform::Render::GlyphQueue::splitSlot(this, v4, w);
      }
    }
  }
  result = Scaleform::Render::GlyphQueue::packGlyph(v8, v7, v6, v4->pRoot);
  if ( !result )
    ++v4->Failures;
  v14 = v4->Failures;
  if ( v14 <= 0x10u )
  {
    if ( v14 )
    {
      if ( result )
        v4->Failures = v14 - 1;
    }
  }
  else
  {
    v4->pPrevActive->pNextActive = v4->pNextActive;
    v4->pNextActive->pPrevActive = v4->pPrevActive;
    v4->TextureId |= 0x8000u;
  }
  return result;
}

// File Line: 285
// RVA: 0x9E3110
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::findSpaceInSlots(Scaleform::Render::GlyphQueue *this, unsigned int w, unsigned int h)
{
  Scaleform::Render::GlyphSlot *v3; // rbx
  Scaleform::List2<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot_Active> *v4; // r14
  unsigned int v5; // er15
  unsigned int v6; // edi
  Scaleform::Render::GlyphQueue *v7; // rbp
  Scaleform::Render::GlyphNode *v8; // rdx
  Scaleform::Render::GlyphSlot *v9; // rsi
  unsigned int v10; // er8
  unsigned int v11; // er9
  int v12; // ecx
  int v13; // eax
  Scaleform::Render::GlyphNode *result; // rax
  unsigned __int16 v15; // cx

  v3 = this->ActiveSlots.Root.pNextActive;
  v4 = &this->ActiveSlots;
  v5 = h;
  v6 = w;
  v7 = this;
  if ( v3 != (Scaleform::Render::GlyphSlot *)&this->ActiveSlots )
  {
    while ( 1 )
    {
      v8 = v3->pRoot;
      v9 = v3->pNextActive;
      if ( !v8->Param.pFont )
      {
        v10 = v3->w;
        if ( v10 > 2 * v6 )
        {
          if ( v8->pNext )
          {
            if ( !v8->pNex2 && v8->mRect.h == v3->pBand->h )
            {
              v11 = v8->mRect.w;
              if ( v11 > v6 )
              {
                v12 = v8->mRect.x;
                v13 = v3->x;
                if ( ((_WORD)v12 == (_WORD)v13) != (v11 + v12 == v10 + v13) )
                  Scaleform::Render::GlyphQueue::splitGlyph(v7, v3, (_WORD)v12 == (_WORD)v13, v6);
              }
            }
          }
          else if ( !v8->pNex2 )
          {
            Scaleform::Render::GlyphQueue::splitSlot(v7, v3, v6);
          }
        }
      }
      result = Scaleform::Render::GlyphQueue::packGlyph(v7, v6, v5, v3->pRoot);
      if ( !result )
        ++v3->Failures;
      v15 = v3->Failures;
      if ( v15 > 0x10u )
        break;
      if ( !v15 )
        goto LABEL_19;
      if ( result )
      {
        v3->Failures = v15 - 1;
LABEL_19:
        if ( result )
          return result;
      }
      v3 = v9;
      if ( v9 == (Scaleform::Render::GlyphSlot *)v4 )
        return 0i64;
    }
    v3->pPrevActive->pNextActive = v3->pNextActive;
    v3->pNextActive->pPrevActive = v3->pPrevActive;
    v3->TextureId |= 0x8000u;
    goto LABEL_19;
  }
  return 0i64;
}

// File Line: 331
// RVA: 0x9E8520
Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *__fastcall Scaleform::Render::GlyphQueue::initNewSlot(Scaleform::Render::GlyphQueue *this, Scaleform::Render::GlyphBand *band, unsigned int x, unsigned int w)
{
  Scaleform::Render::GlyphQueue *v4; // rbx
  __int16 v5; // si
  __int16 v6; // di
  Scaleform::Render::GlyphBand *v7; // r14
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *v8; // rbp
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *v9; // rax
  unsigned __int16 v10; // cx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *v11; // r8
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *v12; // rcx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *v14; // [rsp+40h] [rbp+8h]

  v4 = this;
  v5 = w;
  v6 = x;
  v7 = band;
  v8 = Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75>>::allocate((Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> > *)&this->Slots.FirstPage);
  v9 = Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75>>::allocate((Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> > *)&v4->Glyphs.FirstPage);
  v8[7].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)v7;
  v8[2].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)v9;
  v10 = v7->TextureId;
  WORD1(v8[8].pNext) = v6;
  LOWORD(v8[8].pNext) = v10;
  WORD2(v8[8].pNext) = v5;
  v11 = v9;
  v12 = v8 + 10;
  HIWORD(v8[8].pNext) = 0;
  LODWORD(v8[9].pNext) = 0;
  v12->pNext = v12;
  v12[1].pNext = v12;
  v8[12].pNext = 0i64;
  v9->pNext = 0i64;
  v9[1].pNext = 0i64;
  LOWORD(v9[2].pNext) = 0;
  WORD1(v9[2].pNext) = 16;
  v9[3].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)v8;
  v9[4].pNext = 0i64;
  v9[5].pNext = 0i64;
  LOWORD(v14) = WORD1(v8[8].pNext);
  WORD1(v14) = v7->y;
  WORD2(v14) = WORD2(v8[8].pNext);
  LOWORD(v9) = v7->h;
  LODWORD(v11[7].pNext) = 0;
  HIWORD(v14) = (_WORD)v9;
  v11[6].pNext = v14;
  return v8;
}

// File Line: 360
// RVA: 0x9CE540
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::allocateNewSlot(Scaleform::Render::GlyphQueue *this, unsigned int w, unsigned int h)
{
  Scaleform::Render::GlyphQueue *v3; // rbx
  unsigned __int64 v4; // rcx
  unsigned int v5; // ebp
  unsigned int v6; // esi
  unsigned int v7; // edx
  Scaleform::Render::GlyphBand *v8; // r8
  unsigned __int16 v9; // cx
  unsigned int v10; // ecx
  signed __int64 v11; // rax
  signed __int64 v12; // rdi
  unsigned int v13; // ecx
  unsigned int v14; // er9
  Scaleform::Render::GlyphSlot *v15; // rax
  Scaleform::Render::GlyphSlot *v16; // r9
  Scaleform::Render::GlyphSlot *v17; // rcx
  Scaleform::Render::GlyphSlot *v18; // rax

  v3 = this;
  v4 = this->NumUsedBands;
  v5 = h;
  v6 = w;
  if ( (!(_DWORD)v4 || v3->Bands.Data[(unsigned int)(v4 - 1)].RightSpace < w) && v4 < v3->Bands.Size )
  {
    v7 = (unsigned int)v4 % v3->NumBandsInTexture;
    v8 = &v3->Bands.Data[v4];
    v8->TextureId = (unsigned int)v4 / v3->NumBandsInTexture + LOWORD(v3->FirstTexture);
    v9 = v7 * LOWORD(v3->MaxSlotHeight);
    v8->y = v9;
    if ( v7 + 1 == v3->NumBandsInTexture )
      LOWORD(v10) = v3->TextureHeight - v9;
    else
      v10 = v3->MaxSlotHeight;
    v8->h = v10;
    v8->RightSpace = v3->TextureWidth;
    v11 = (signed __int64)&v8->Slots;
    *(_QWORD *)(v11 + 24) = v11;
    *(_QWORD *)(v11 + 32) = v11;
    ++v3->NumUsedBands;
  }
  v12 = (signed __int64)&v3->Bands.Data[v3->NumUsedBands - 1];
  v13 = *(unsigned __int16 *)(v12 + 6);
  if ( v6 > v13 )
    return 0i64;
  v14 = v6;
  if ( v13 - v6 < v6 )
    v14 = *(unsigned __int16 *)(v12 + 6);
  v15 = Scaleform::Render::GlyphQueue::initNewSlot(
          v3,
          &v3->Bands.Data[v3->NumUsedBands - 1],
          v3->TextureWidth - v13,
          v14);
  v16 = v15;
  *(_WORD *)(v12 + 6) -= v15->w;
  v17 = v3->SlotQueue.Root.pPrev;
  v15->pNext = (Scaleform::Render::GlyphSlot *)&v3->SlotQueue;
  v15->pPrev = v17;
  v3->SlotQueue.Root.pPrev->pNext = v15;
  v3->SlotQueue.Root.pPrev = v15;
  ++v3->SlotQueueSize;
  v15->pPrevInBand = *(Scaleform::Render::GlyphSlot **)(v12 + 32);
  v15->pNextInBand = (Scaleform::Render::GlyphSlot *)(v12 + 8);
  *(_QWORD *)(*(_QWORD *)(v12 + 32) + 32i64) = v15;
  *(_QWORD *)(v12 + 32) = v15;
  v18 = v3->ActiveSlots.Root.pNextActive;
  v16->pPrevActive = &v3->ActiveSlots.Root;
  v16->pNextActive = v18;
  v3->ActiveSlots.Root.pNextActive->pPrevActive = v16;
  v3->ActiveSlots.Root.pNextActive = v16;
  return Scaleform::Render::GlyphQueue::packGlyph(v3, v6, v5, v16);
}

// File Line: 410
// RVA: 0x9EFC60
void __fastcall Scaleform::Render::GlyphQueue::releaseGlyphTree(Scaleform::Render::GlyphQueue *this, Scaleform::Render::GlyphNode *glyph)
{
  Scaleform::Render::GlyphNode *v2; // rbx
  Scaleform::Render::GlyphQueue *v3; // rdi
  Scaleform::Render::GlyphParamHash key; // [rsp+38h] [rbp+10h]

  if ( glyph )
  {
    v2 = glyph;
    v3 = this;
    Scaleform::Render::GlyphQueue::releaseGlyphTree(this, glyph->pNext);
    Scaleform::Render::GlyphQueue::releaseGlyphTree(v3, v2->pNex2);
    if ( v2->Param.pFont )
    {
      key.Param = &v2->Param;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::RemoveAlt<Scaleform::Render::GlyphParamHash>(
        (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> > *)&v3->GlyphHTable.mHash.pTable,
        &key);
    }
    v2->Param.pFont = 0i64;
    v2->Param.pFont = (Scaleform::Render::FontCacheHandle *)v3->Glyphs.FirstEmptySlot;
    v3->Glyphs.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)v2;
  }
}

// File Line: 430
// RVA: 0x9EFF10
void __fastcall Scaleform::Render::GlyphQueue::releaseSlot(Scaleform::Render::GlyphQueue *this, Scaleform::Render::GlyphSlot *slot)
{
  Scaleform::Render::GlyphSlot *v2; // rbx
  Scaleform::Render::GlyphQueue *v3; // rdi
  Scaleform::Render::Fence *v4; // r8
  Scaleform::Render::FenceImpl *v5; // r8
  Scaleform::Render::Fence *v6; // rcx
  Scaleform::Render::GlyphNode *v7; // rsi
  Scaleform::Render::GlyphNode *v8; // rsi
  Scaleform::Render::GlyphBand *v9; // rax
  unsigned __int16 v10; // cx
  Scaleform::Render::GlyphBand *v11; // rcx
  unsigned __int16 v12; // ax
  Scaleform::Render::GlyphParamHash *v13; // rcx
  Scaleform::Render::Fence *v14; // rcx
  unsigned __int16 v15; // ax
  Scaleform::Render::GlyphSlot *v16; // rax
  Scaleform::Render::GlyphParamHash key; // [rsp+38h] [rbp+10h]

  v2 = slot;
  v3 = this;
  if ( !slot->PinCount )
  {
    v4 = slot->SlotFence.pObject;
    if ( v4 )
    {
      if ( v4->HasData )
      {
        v5 = v4->Data;
        if ( v5 )
        {
          if ( v5->Parent )
            ((void (__fastcall *)(Scaleform::Render::RenderSync *, signed __int64, unsigned __int64))v5->RSContext->vfptr[5].__vecDelDtor)(
              v5->RSContext,
              1i64,
              v5->APIHandle);
        }
      }
    }
    v6 = v2->SlotFence.pObject;
    if ( v6 )
      Scaleform::Render::Fence::Release(v6);
    v2->SlotFence.pObject = 0i64;
  }
  v7 = v2->pRoot->pNext;
  if ( v7 )
  {
    Scaleform::Render::GlyphQueue::releaseGlyphTree(v3, v7->pNext);
    Scaleform::Render::GlyphQueue::releaseGlyphTree(v3, v7->pNex2);
    if ( v7->Param.pFont )
    {
      key.Param = &v7->Param;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::RemoveAlt<Scaleform::Render::GlyphParamHash>(
        (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> > *)&v3->GlyphHTable.mHash.pTable,
        &key);
    }
    v7->Param.pFont = 0i64;
    v7->Param.pFont = (Scaleform::Render::FontCacheHandle *)v3->Glyphs.FirstEmptySlot;
    v3->Glyphs.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)v7;
  }
  v8 = v2->pRoot->pNex2;
  if ( v8 )
  {
    Scaleform::Render::GlyphQueue::releaseGlyphTree(v3, v8->pNext);
    Scaleform::Render::GlyphQueue::releaseGlyphTree(v3, v8->pNex2);
    if ( v8->Param.pFont )
    {
      key.Param = &v8->Param;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::RemoveAlt<Scaleform::Render::GlyphParamHash>(
        (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> > *)&v3->GlyphHTable.mHash.pTable,
        &key);
    }
    v8->Param.pFont = 0i64;
    v8->Param.pFont = (Scaleform::Render::FontCacheHandle *)v3->Glyphs.FirstEmptySlot;
    v3->Glyphs.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)v8;
  }
  while ( (Scaleform::List<Scaleform::Render::TextNotifier,Scaleform::Render::TextNotifier> *)v2->TextFields.Root.pNext != &v2->TextFields )
    v3->pEvictNotifier->vfptr->Evict(v3->pEvictNotifier, v2->TextFields.Root.pNext->pText);
  if ( v2->pRoot->Param.pFont )
  {
    key.Param = &v2->pRoot->Param;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::RemoveAlt<Scaleform::Render::GlyphParamHash>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> > *)&v3->GlyphHTable.mHash.pTable,
      &key);
  }
  v9 = v2->pBand;
  v10 = v9->RightSpace;
  if ( v10 && v2 == v9->Slots.Root.pPrevInBand )
  {
    v2->w += v10;
    v9->RightSpace = 0;
  }
  v2->pRoot->Param.pFont = 0i64;
  v11 = v2->pBand;
  LOWORD(key.Param) = v2->x;
  WORD1(key.Param) = v11->y;
  WORD2(key.Param) = v2->w;
  v12 = v11->h;
  v13 = (Scaleform::Render::GlyphParamHash *)v2->pRoot;
  HIWORD(key.Param) = v12;
  v13[6].Param = key.Param;
  v2->pRoot->pNext = 0i64;
  v2->pRoot->pNex2 = 0i64;
  v2->Failures = 0;
  v14 = v2->SlotFence.pObject;
  if ( v14 )
    Scaleform::Render::Fence::Release(v14);
  v2->SlotFence.pObject = 0i64;
  v15 = v2->TextureId;
  if ( (v15 & 0x8000u) != 0 )
  {
    v2->TextureId = v15 & 0x7FFF;
    v16 = v3->ActiveSlots.Root.pNextActive;
    v2->pPrevActive = &v3->ActiveSlots.Root;
    v2->pNextActive = v16;
    v3->ActiveSlots.Root.pNextActive->pPrevActive = v2;
    v3->ActiveSlots.Root.pNextActive = v2;
  }
}

// File Line: 478
// RVA: 0x9E9B70
void __fastcall Scaleform::Render::GlyphQueue::mergeSlots(Scaleform::Render::GlyphQueue *this, Scaleform::Render::GlyphSlot *from, Scaleform::Render::GlyphSlot *to, unsigned int w)
{
  unsigned __int16 v4; // r15
  Scaleform::Render::GlyphSlot *v5; // r14
  Scaleform::Render::GlyphSlot *v6; // rsi
  Scaleform::Render::GlyphQueue *v7; // rdi
  Scaleform::Render::GlyphSlot *i; // rbx
  Scaleform::Render::GlyphSlot *v9; // rbp
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *v10; // rcx
  Scaleform::Render::GlyphNode *v11; // rax
  signed __int64 v12; // rdx
  Scaleform::Render::GlyphSlot *v13; // rax

  v4 = w;
  v5 = to;
  v6 = from;
  v7 = this;
  for ( i = from; ; i = v9 )
  {
    v9 = i->pNextInBand;
    Scaleform::Render::GlyphQueue::releaseSlot(v7, i);
    if ( i != v6 )
    {
      v10 = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)i->pRoot;
      v10->pNext = v7->Glyphs.FirstEmptySlot;
      v7->Glyphs.FirstEmptySlot = v10;
      i->pPrev->pNext = i->pNext;
      i->pNext->pPrev = i->pPrev;
      --v7->SlotQueueSize;
      if ( !(i->TextureId & 0x8000) )
      {
        i->pPrevActive->pNextActive = i->pNextActive;
        i->pNextActive->pPrevActive = i->pPrevActive;
      }
      i->pPrevInBand->pNextInBand = i->pNextInBand;
      i->pNextInBand->pPrevInBand = i->pPrevInBand;
      i->pPrev = (Scaleform::Render::GlyphSlot *)v7->Slots.FirstEmptySlot;
      v7->Slots.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)i;
    }
    if ( i == v5 )
      break;
  }
  v11 = v6->pRoot;
  v6->w = v4;
  v11->mRect.w = v4;
  v12 = (signed __int64)&v7->SlotQueue;
  v6->pPrev->pNext = v6->pNext;
  v6->pNext->pPrev = v6->pPrev;
  v13 = v7->SlotQueue.Root.pNext;
  v6->pPrev = (Scaleform::Render::GlyphSlot *)&v7->SlotQueue;
  v6->pNext = v13;
  **(_QWORD **)(v12 + 8) = v6;
  *(_QWORD *)(v12 + 8) = v6;
}

// File Line: 512
// RVA: 0x9E99A0
Scaleform::Render::GlyphSlot *__fastcall Scaleform::Render::GlyphQueue::mergeSlotWithNeighbor(Scaleform::Render::GlyphQueue *this, Scaleform::Render::GlyphSlot *slot)
{
  Scaleform::Render::GlyphBand *v2; // r13
  Scaleform::Render::GlyphSlot *v3; // rbx
  Scaleform::Render::GlyphSlot *v4; // rdi
  Scaleform::Render::GlyphQueue *v5; // r15
  char v6; // bp
  Scaleform::Render::GlyphNode *v7; // rsi
  Scaleform::Render::GlyphNode *v8; // r14
  int v9; // edx
  int v10; // er8
  int v11; // eax
  bool v12; // zf
  unsigned __int16 v13; // ax
  Scaleform::Render::GlyphSlot *v14; // rcx
  Scaleform::Render::GlyphRect v16; // [rsp+58h] [rbp+10h]

  v2 = slot->pBand;
  v3 = slot->pNextInBand;
  v4 = slot;
  v5 = this;
  v6 = 1;
  if ( v3 == (Scaleform::Render::GlyphSlot *)&v2->Slots )
  {
    v3 = slot->pPrevInBand;
    v6 = 0;
    if ( v3 == (Scaleform::Render::GlyphSlot *)&v2->Slots )
      return 0i64;
  }
  if ( v3->w > slot->w )
    return 0i64;
  v7 = v3->pRoot;
  v8 = slot->pRoot;
  Scaleform::Render::GlyphQueue::releaseSlot(this, slot);
  v9 = v4->x;
  v10 = v4->w;
  v4->pPrev->pNext = v4->pNext;
  v4->pNext->pPrev = v4->pPrev;
  --v5->SlotQueueSize;
  if ( (v4->TextureId & 0x8000u) == 0 )
  {
    v4->pPrevActive->pNextActive = v4->pNextActive;
    v4->pNextActive->pPrevActive = v4->pPrevActive;
  }
  v4->pPrevInBand->pNextInBand = v4->pNextInBand;
  v4->pNextInBand->pPrevInBand = v4->pPrevInBand;
  v4->pPrev = (Scaleform::Render::GlyphSlot *)v5->Slots.FirstEmptySlot;
  v5->Slots.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)v4;
  if ( v7->Param.pFont
    || v7->pNex2
    || v7->mRect.h != v2->h
    || ((v11 = v7->mRect.x, !v6) ? (v12 = v11 + v7->mRect.w == v9) : (v12 = v10 + v9 == v11), !v12) )
  {
    v8->pNext = v7;
    v8->pNex2 = 0i64;
    v8->pSlot = v3;
    v16.x = v9;
    v16.w = v10;
    v16.y = v2->y;
    v16.h = v2->h;
    v8->mRect = v16;
    v3->pRoot = v8;
  }
  else
  {
    v8->Param.pFont = (Scaleform::Render::FontCacheHandle *)v5->Glyphs.FirstEmptySlot;
    v5->Glyphs.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)v8;
    if ( v6 )
      v7->mRect.x = v9;
    v7->mRect.w += v10;
  }
  if ( v6 )
    v3->x = v9;
  v13 = v3->TextureId;
  v3->w += v10;
  if ( v13 & 0x8000 )
  {
    v3->Failures = 0;
    v3->TextureId = v13 & 0x7FFF;
    v14 = v5->ActiveSlots.Root.pNextActive;
    v3->pPrevActive = &v5->ActiveSlots.Root;
    v3->pNextActive = v14;
    v5->ActiveSlots.Root.pNextActive->pPrevActive = v3;
    v5->ActiveSlots.Root.pNextActive = v3;
  }
  return v3;
}

// File Line: 610
// RVA: 0x9E2470
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::evictOldSlot(Scaleform::Render::GlyphQueue *this, unsigned int w, unsigned int h, unsigned int pass)
{
  Scaleform::Render::GlyphSlot *v4; // rbx
  unsigned int v5; // ebp
  unsigned int v6; // er15
  unsigned int v7; // er14
  Scaleform::Render::GlyphQueue *v8; // r13
  Scaleform::Render::GlyphSlot *v9; // rdi
  int v10; // esi
  Scaleform::Render::GlyphSlot *v11; // rax
  Scaleform::Render::GlyphSlot *i; // rbp
  Scaleform::Render::GlyphBand *v13; // r15
  unsigned int v14; // esi
  Scaleform::Render::GlyphSlot *j; // rbx
  Scaleform::Render::GlyphSlot *v16; // rcx
  Scaleform::Render::GlyphSlot *v17; // rax
  char v18; // al
  unsigned int v19; // eax
  unsigned __int16 v20; // ax
  unsigned int ha; // [rsp+70h] [rbp+18h]
  unsigned int v23; // [rsp+78h] [rbp+20h]

  v23 = pass;
  ha = h;
  v4 = this->SlotQueue.Root.pNext;
  v5 = this->SlotQueueSize;
  v6 = h;
  v7 = w;
  v8 = this;
  if ( !pass )
    v5 >>= 1;
  v9 = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  v10 = 0;
  while ( v4 != v9 )
  {
    if ( !Scaleform::Render::GlyphQueue::IsPinned(v4, v8->FenceWaitOnFullCache) )
    {
      if ( v4->w >= v7 )
      {
        Scaleform::Render::GlyphQueue::releaseSlot(v8, v4);
        return Scaleform::Render::GlyphQueue::packGlyph(v8, v7, v6, v4);
      }
      v11 = Scaleform::Render::GlyphQueue::mergeSlotWithNeighbor(v8, v4);
      if ( v11 )
      {
        if ( v11->pRoot->mRect.w >= v7 )
          return Scaleform::Render::GlyphQueue::packGlyph(v8, v7, v6, v11);
        break;
      }
    }
    v4 = v4->pNext;
    if ( ++v10 > v5 )
      break;
  }
  for ( i = v8->SlotQueue.Root.pNext; i != v9; i = i->pNext )
  {
    if ( !Scaleform::Render::GlyphQueue::IsPinned(i, v8->FenceWaitOnFullCache) )
    {
      v13 = i->pBand;
      v14 = 0;
      for ( j = i; j != (Scaleform::Render::GlyphSlot *)&v13->Slots; j = j->pNextInBand )
      {
        if ( Scaleform::Render::GlyphQueue::IsPinned(j, v8->FenceWaitOnFullCache) )
          break;
        if ( v23 || (v16 = j, v17 = j, j == v9) )
        {
LABEL_17:
          v18 = 1;
        }
        else
        {
          while ( v17 != v9 )
          {
            v16 = v16->pPrev;
            v17 = v17->pNext;
            if ( v16 == v9 )
              goto LABEL_17;
          }
          v18 = 0;
        }
        if ( j != i && !v18 )
          break;
        v19 = j->w;
        if ( v19 >= v7 )
        {
          Scaleform::Render::GlyphQueue::releaseSlot(v8, j);
          return Scaleform::Render::GlyphQueue::packGlyph(v8, v7, ha, j);
        }
        v14 += v19;
        v20 = v13->RightSpace;
        if ( v20 && j == v13->Slots.Root.pPrevInBand && v14 + v20 >= v7 )
        {
          v14 += v20;
          v13->RightSpace = 0;
        }
        if ( v14 >= v7 )
        {
          Scaleform::Render::GlyphQueue::mergeSlots(v8, i, j, v14);
          return Scaleform::Render::GlyphQueue::packGlyph(v8, v7, ha, i);
        }
      }
    }
  }
  return 0i64;
}

// File Line: 711
// RVA: 0x9E2400
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::evictOldSlot(Scaleform::Render::GlyphQueue *this, unsigned int w, unsigned int h)
{
  Scaleform::Render::GlyphQueue *v3; // rbx
  unsigned int v4; // edi
  unsigned int v5; // esi
  Scaleform::Render::GlyphNode *result; // rax

  v3 = this;
  v4 = h;
  v5 = w;
  ((void (*)(void))this->pEvictNotifier->vfptr->ApplyInUseList)();
  result = Scaleform::Render::GlyphQueue::evictOldSlot(v3, v5, v4, 0);
  if ( !result )
  {
    ((void (*)(void))v3->pEvictNotifier->vfptr->UpdatePinList)();
    result = Scaleform::Render::GlyphQueue::evictOldSlot(v3, v5, v4, 1u);
  }
  return result;
}

// File Line: 726
// RVA: 0x9691C0
Scaleform::Render::TextNotifier *__fastcall Scaleform::Render::GlyphQueue::CreateNotifier(Scaleform::Render::GlyphQueue *this, Scaleform::Render::GlyphNode *node, Scaleform::Render::TextMeshProvider *tm)
{
  Scaleform::Render::GlyphSlot *v3; // rsi
  Scaleform::Render::TextMeshProvider *v4; // rdi
  Scaleform::Render::TextNotifier *v5; // rax
  Scaleform::Render::TextNotifier *v6; // rbx
  Scaleform::Render::TextNotifier *result; // rax
  Scaleform::Render::TextNotifier *v8; // rcx

  v3 = node->pSlot;
  v4 = tm;
  v5 = v3->TextFields.Root.pPrev;
  v6 = (Scaleform::Render::TextNotifier *)&v3->TextFields;
  if ( v5 != (Scaleform::Render::TextNotifier *)&v3->TextFields && tm == v5->pText )
    return 0i64;
  result = Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,75>>::allocate((Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,75> > *)&this->Notifiers.FirstPage);
  result->pSlot = v3;
  result->pText = v4;
  v8 = v6->pPrev;
  result->pNext = v6;
  result->pPrev = v8;
  v6->pPrev->pNext = result;
  v6->pPrev = result;
  return result;
}

// File Line: 758
// RVA: 0x979DC0
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::FindGlyph(Scaleform::Render::GlyphQueue *this, Scaleform::Render::GlyphParam *gp)
{
  Scaleform::Render::GlyphQueue *v2; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> > *v3; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> > v4; // rbx
  signed __int64 v5; // rax
  signed __int64 v6; // rax
  Scaleform::Render::GlyphNode **v7; // rax
  Scaleform::Render::GlyphNode *result; // rax
  Scaleform::Render::GlyphSlot *v9; // r9
  Scaleform::Render::GlyphSlot *v10; // rcx
  Scaleform::Render::GlyphParamHash key; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> > *)&this->GlyphHTable.mHash.pTable;
  key.Param = gp;
  v4.pTable = v3->pTable;
  if ( !v3->pTable )
    return 0i64;
  v5 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::findIndexCore<Scaleform::Render::GlyphParamHash>(
         v3,
         &key,
         v4.pTable->SizeMask & ((_QWORD)gp->pFont ^ ((_QWORD)gp->pFont >> 6) ^ gp->GlyphIndex ^ gp->FontSize ^ gp->Flags ^ gp->BlurX ^ gp->BlurStrength ^ 2i64 * gp->BlurY));
  if ( v5 < 0 )
    return 0i64;
  v6 = (signed __int64)&v4.pTable[2 * (v5 + 1)];
  if ( !v6 )
    return 0i64;
  v7 = (Scaleform::Render::GlyphNode **)(v6 + 8);
  if ( !v7 )
    return 0i64;
  result = *v7;
  v9 = result->pSlot;
  v9->pPrev->pNext = v9->pNext;
  v9->pNext->pPrev = v9->pPrev;
  v10 = v2->SlotQueue.Root.pPrev;
  v9->pNext = (Scaleform::Render::GlyphSlot *)&v2->SlotQueue;
  v9->pPrev = v10;
  v2->SlotQueue.Root.pPrev->pNext = v9;
  v2->SlotQueue.Root.pPrev = v9;
  return result;
}

// File Line: 772
// RVA: 0x958180
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::AllocateGlyph(Scaleform::Render::GlyphQueue *this, Scaleform::Render::GlyphParam *gp, unsigned int w, unsigned int h)
{
  unsigned int v4; // esi
  unsigned int v5; // edi
  Scaleform::Render::GlyphParam *v6; // r14
  Scaleform::Render::GlyphQueue *v7; // rbx
  Scaleform::Render::GlyphNode *v8; // rcx
  Scaleform::Render::GlyphNode *result; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> > *v10; // rsi
  Scaleform::Render::GlyphSlot *v11; // r8
  Scaleform::Render::GlyphSlot *v12; // rax
  Scaleform::Render::GlyphNode *v13; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> >::TableType *v14; // rbx
  signed __int64 v15; // rax
  signed __int64 v16; // rax
  __int64 v17; // r9
  Scaleform::Render::GlyphParamHash key; // [rsp+20h] [rbp-28h]
  Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeRef v19; // [rsp+28h] [rbp-20h]
  Scaleform::Render::GlyphNode *v20; // [rsp+50h] [rbp+8h]

  v4 = h;
  v5 = w;
  v6 = gp;
  v7 = this;
  if ( h < this->MinSlotSpace )
    this->MinSlotSpace = h;
  if ( w < this->MinSlotSpace )
    this->MinSlotSpace = w;
  v8 = Scaleform::Render::GlyphQueue::findSpaceInSlots(this, w, h);
  v20 = v8;
  if ( v8
    || (v8 = Scaleform::Render::GlyphQueue::allocateNewSlot(v7, v5, v4), (v20 = v8) != 0i64)
    || (result = Scaleform::Render::GlyphQueue::evictOldSlot(v7, v5, v4), v8 = result, (v20 = result) != 0i64) )
  {
    v10 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> > *)&v7->GlyphHTable.mHash.pTable;
    v8->Param.pFont = v6->pFont;
    *(_QWORD *)&v8->Param.GlyphIndex = *(_QWORD *)&v6->GlyphIndex;
    *(_QWORD *)&v8->Param.BlurY = *(_QWORD *)&v6->BlurY;
    v20->Origin.x = 0;
    v20->Origin.y = 0;
    v11 = v20->pSlot;
    v11->pPrev->pNext = v11->pNext;
    v11->pNext->pPrev = v11->pPrev;
    v12 = v7->SlotQueue.Root.pPrev;
    v11->pNext = (Scaleform::Render::GlyphSlot *)&v7->SlotQueue;
    v11->pPrev = v12;
    v7->SlotQueue.Root.pPrev->pNext = v11;
    v13 = v20;
    v7->SlotQueue.Root.pPrev = v11;
    v14 = v7->GlyphHTable.mHash.pTable;
    key.Param = &v13->Param;
    if ( !v14
      || (v15 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::findIndexCore<Scaleform::Render::GlyphParamHash>(
                  v10,
                  &key,
                  v14->SizeMask & ((_QWORD)v13->Param.pFont ^ ((_QWORD)v13->Param.pFont >> 6) ^ v13->Param.GlyphIndex ^ v13->Param.FontSize ^ v13->Param.Flags ^ v13->Param.BlurX ^ v13->Param.BlurStrength ^ 2i64 * v13->Param.BlurY)),
          v15 < 0)
      || (v16 = (signed __int64)&v14[2 * (v15 + 1)]) == 0
      || v16 == -8 )
    {
      v17 = v13->Param.BlurY;
      v19.pFirst = &key;
      v19.pSecond = &v20;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeRef>(
        v10,
        v10,
        &v19,
        (_QWORD)v13->Param.pFont ^ ((_QWORD)v13->Param.pFont >> 6) ^ v13->Param.GlyphIndex ^ v13->Param.FontSize ^ v13->Param.Flags ^ v13->Param.BlurX ^ v13->Param.BlurStrength ^ (unsigned __int64)(2 * v17));
      v13 = v20;
    }
    result = v13;
  }
  return result;
}

// File Line: 806
// RVA: 0x9BBB40
void __fastcall Scaleform::Render::GlyphQueue::UnpinAllSlots(Scaleform::Render::GlyphQueue *this)
{
  Scaleform::Render::GlyphSlot *v1; // rsi
  Scaleform::Render::GlyphSlot *v2; // rbp
  Scaleform::Render::Fence *v3; // rax
  Scaleform::Render::FenceImpl *v4; // r8
  Scaleform::Render::Fence *v5; // rbx
  bool v6; // zf
  Scaleform::Render::FenceImpl *v7; // rcx
  Scaleform::Render::RenderSync *v8; // rdi
  Scaleform::Render::FenceImpl *v9; // rcx

  v1 = this->SlotQueue.Root.pNext;
  v2 = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  if ( v1 != (Scaleform::Render::GlyphSlot *)&this->SlotQueue )
  {
    do
    {
      v3 = v1->SlotFence.pObject;
      v1->PinCount = 0;
      if ( v3 )
      {
        if ( v3->HasData )
        {
          v4 = v3->Data;
          if ( v3->Data )
          {
            if ( v4->Parent )
              ((void (__fastcall *)(Scaleform::Render::RenderSync *, signed __int64, unsigned __int64))v4->RSContext->vfptr[5].__vecDelDtor)(
                v4->RSContext,
                1i64,
                v4->APIHandle);
          }
        }
      }
      v5 = v1->SlotFence.pObject;
      if ( v5 )
      {
        v6 = v5->RefCount-- == 1;
        if ( v6 )
        {
          v7 = v5->Data;
          if ( v5->HasData )
          {
            v8 = v7->RSContext;
            ((void (__fastcall *)(Scaleform::Render::FenceImpl *, unsigned __int64))v7->RSContext->FenceFrameAlloc.pHeapOrPtr)(
              v7,
              v7->APIHandle);
            v9 = v5->Data;
            v9->RSContext = (Scaleform::Render::RenderSync *)v8->FenceImplAlloc.FirstEmptySlot;
            v8->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v9;
            v5->Data = (Scaleform::Render::FenceImpl *)v8->FenceAlloc.FirstEmptySlot;
            v8->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)v5;
          }
          else
          {
            v5->Data = (Scaleform::Render::FenceImpl *)v7[4].Parent;
            v7[4].Parent = (Scaleform::Render::FenceFrame *)v5;
          }
        }
      }
      v1->SlotFence.pObject = 0i64;
      v1 = v1->pNext;
    }
    while ( v1 != v2 );
  }
}

// File Line: 863
// RVA: 0x99B540
void __fastcall Scaleform::Render::GlyphQueue::MergeEmptySlots(Scaleform::Render::GlyphQueue *this)
{
  unsigned __int64 v1; // r14
  Scaleform::Render::GlyphQueue *v2; // rsi
  __int64 v3; // r15
  Scaleform::Render::GlyphBand *v4; // rax
  Scaleform::Render::GlyphSlot *v5; // rdi
  signed __int64 v6; // rbp
  Scaleform::Render::GlyphSlot *v7; // rbx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *v8; // rcx
  unsigned __int16 v9; // dx
  Scaleform::Render::GlyphNode *v10; // rcx
  unsigned __int16 v11; // ax
  Scaleform::Render::GlyphSlot *v12; // rax

  v1 = 0i64;
  v2 = this;
  if ( this->NumUsedBands )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->Bands.Data;
      v5 = v4[v3].Slots.Root.pNextInBand;
      v6 = (signed __int64)&v4[v3].Slots;
      while ( v5 != (Scaleform::Render::GlyphSlot *)v6 )
      {
        v7 = v5->pNextInBand;
        if ( v7 == (Scaleform::Render::GlyphSlot *)v6 )
          break;
        if ( (_QWORD)v7->pRoot->pNext | (_QWORD)v7->pRoot->pNex2 | (_QWORD)v5->pRoot->pNext | (_QWORD)v5->pRoot->pNex2 )
        {
          v5 = v5->pNextInBand;
        }
        else
        {
          Scaleform::Render::GlyphQueue::releaseSlot(v2, v5);
          Scaleform::Render::GlyphQueue::releaseSlot(v2, v7);
          v8 = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)v7->pRoot;
          v9 = v5->w + v7->w;
          v8->pNext = v2->Glyphs.FirstEmptySlot;
          v2->Glyphs.FirstEmptySlot = v8;
          v7->pPrev->pNext = v7->pNext;
          v7->pNext->pPrev = v7->pPrev;
          --v2->SlotQueueSize;
          if ( !(v7->TextureId & 0x8000) )
          {
            v7->pPrevActive->pNextActive = v7->pNextActive;
            v7->pNextActive->pPrevActive = v7->pPrevActive;
          }
          v7->pPrevInBand->pNextInBand = v7->pNextInBand;
          v7->pNextInBand->pPrevInBand = v7->pPrevInBand;
          v7->pPrev = (Scaleform::Render::GlyphSlot *)v2->Slots.FirstEmptySlot;
          v2->Slots.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)v7;
          v10 = v5->pRoot;
          v11 = v5->x;
          v5->w = v9;
          v10->mRect.x = v11;
          v5->pRoot->mRect.y = v5->pBand->y;
          v5->pRoot->mRect.w = v9;
          v5->pRoot->mRect.h = v5->pBand->h;
          v5->pPrev->pNext = v5->pNext;
          v5->pNext->pPrev = v5->pPrev;
          v12 = v2->SlotQueue.Root.pNext;
          v5->pPrev = (Scaleform::Render::GlyphSlot *)&v2->SlotQueue;
          v5->pNext = v12;
          v2->SlotQueue.Root.pNext->pPrev = v5;
          v2->SlotQueue.Root.pNext = v5;
        }
      }
      ++v1;
      ++v3;
    }
    while ( v1 < v2->NumUsedBands );
  }
}

// File Line: 907
// RVA: 0x95EFF0
void __fastcall Scaleform::Render::GlyphQueue::CleanUpTexture(Scaleform::Render::GlyphQueue *this, unsigned int textureId)
{
  Scaleform::Render::GlyphSlot *v2; // rbx
  Scaleform::Render::GlyphSlot *v3; // rsi
  unsigned int v4; // er14
  Scaleform::Render::GlyphQueue *v5; // rbp
  Scaleform::Render::GlyphSlot *v6; // rdi
  Scaleform::Render::GlyphSlot *v7; // rax

  v2 = this->SlotQueue.Root.pNext;
  v3 = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  v4 = textureId;
  v5 = this;
  if ( v2 != (Scaleform::Render::GlyphSlot *)&this->SlotQueue )
  {
    do
    {
      v6 = v2->pNext;
      if ( (v2->TextureId & 0x7FFF) == v4 )
      {
        Scaleform::Render::GlyphQueue::releaseSlot(v5, v2);
        v2->pPrev->pNext = v2->pNext;
        v2->pNext->pPrev = v2->pPrev;
        v7 = v3->pNext;
        v2->pPrev = v3;
        v2->pNext = v7;
        v3->pNext->pPrev = v2;
        v3->pNext = v2;
      }
      v2 = v6;
    }
    while ( v6 != v3 );
  }
  Scaleform::Render::GlyphQueue::MergeEmptySlots(v5);
}

// File Line: 924
// RVA: 0x9E2D90
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::findFontInSlot(Scaleform::Render::GlyphNode *glyph, Scaleform::Render::FontCacheHandle *font)
{
  Scaleform::Render::FontCacheHandle *v2; // rdi
  Scaleform::Render::GlyphNode *v3; // rbx
  Scaleform::Render::GlyphNode *result; // rax

  v2 = font;
  v3 = glyph;
  if ( !glyph )
    return 0i64;
  while ( v3->Param.pFont != v2 )
  {
    result = Scaleform::Render::GlyphQueue::findFontInSlot(v3->pNext, v2);
    if ( result )
      return result;
    v3 = v3->pNex2;
    if ( !v3 )
      return 0i64;
  }
  return v3;
}

// File Line: 941
// RVA: 0x95EE30
void __fastcall Scaleform::Render::GlyphQueue::CleanUpFont(Scaleform::Render::GlyphQueue *this, Scaleform::Render::FontCacheHandle *font)
{
  Scaleform::Render::GlyphSlot *v2; // rbx
  Scaleform::Render::GlyphSlot *v3; // rbp
  Scaleform::Render::FontCacheHandle *v4; // r14
  Scaleform::Render::GlyphQueue *v5; // r15
  Scaleform::Render::GlyphNode *v6; // rdi
  Scaleform::Render::GlyphSlot *v7; // rsi
  Scaleform::Render::GlyphNode *v8; // rax
  Scaleform::Render::Fence *v9; // rax
  Scaleform::Render::FenceImpl *v10; // r8
  Scaleform::Render::Fence *v11; // rcx
  Scaleform::Render::GlyphSlot *v12; // rax

  v2 = this->SlotQueue.Root.pNext;
  v3 = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  v4 = font;
  v5 = this;
  if ( v2 != (Scaleform::Render::GlyphSlot *)&this->SlotQueue )
  {
    do
    {
      v6 = v2->pRoot;
      v7 = v2->pNext;
      if ( v6 )
      {
        if ( v6->Param.pFont != v4 )
        {
          v8 = Scaleform::Render::GlyphQueue::findFontInSlot(v6->pNext, v4);
          if ( !v8 )
            v8 = Scaleform::Render::GlyphQueue::findFontInSlot(v6->pNex2, v4);
          v6 = v8;
        }
        if ( v6 )
        {
          if ( v2->PinCount <= 0 )
          {
            v9 = v2->SlotFence.pObject;
            if ( v9 )
            {
              if ( v9->HasData )
              {
                v10 = v9->Data;
                if ( v9->Data )
                {
                  if ( v10->Parent )
                    ((void (__fastcall *)(Scaleform::Render::RenderSync *, signed __int64, unsigned __int64))v10->RSContext->vfptr[5].__vecDelDtor)(
                      v10->RSContext,
                      1i64,
                      v10->APIHandle);
                }
              }
            }
            v11 = v2->SlotFence.pObject;
            if ( v11 )
              Scaleform::Render::Fence::Release(v11);
            v2->SlotFence.pObject = 0i64;
          }
          Scaleform::Render::GlyphQueue::releaseSlot(v5, v2);
          v2->pPrev->pNext = v2->pNext;
          v2->pNext->pPrev = v2->pPrev;
          v12 = v3->pNext;
          v2->pPrev = v3;
          v2->pNext = v12;
          v3->pNext->pPrev = v2;
          v3->pNext = v2;
        }
      }
      v2 = v7;
    }
    while ( v7 != v3 );
  }
}

