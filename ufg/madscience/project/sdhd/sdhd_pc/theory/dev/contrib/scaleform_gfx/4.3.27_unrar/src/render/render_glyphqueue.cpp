// File Line: 44
// RVA: 0x93CA50
void __fastcall Scaleform::Render::GlyphQueue::GlyphQueue(Scaleform::Render::GlyphQueue *this)
{
  Scaleform::List2<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot_Active> *p_ActiveSlots; // rcx

  *(_QWORD *)&this->MinSlotSpace = 10i64;
  *(_QWORD *)&this->NumTextures = 0i64;
  *(_QWORD *)&this->TextureHeight = 0i64;
  this->NumBandsInTexture = 0;
  this->Slots.FirstPage = 0i64;
  this->Slots.LastPage = 0i64;
  this->Slots.NumElementsInPage = 127;
  this->Slots.FirstEmptySlot = 0i64;
  this->Slots.pHeapOrPtr = &this->Slots;
  this->SlotQueue.Root.pPrev = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  this->SlotQueue.Root.pNext = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  this->SlotQueueSize = 0;
  p_ActiveSlots = &this->ActiveSlots;
  p_ActiveSlots->Root.TextFields.Root.pPrev = (Scaleform::Render::TextNotifier *)&p_ActiveSlots->Root.TextFields;
  p_ActiveSlots->Root.TextFields.Root.pNext = (Scaleform::Render::TextNotifier *)&p_ActiveSlots->Root.TextFields;
  p_ActiveSlots->Root.SlotFence.pObject = 0i64;
  p_ActiveSlots->Root.pPrevActive = &p_ActiveSlots->Root;
  p_ActiveSlots->Root.pNextActive = &p_ActiveSlots->Root;
  this->Glyphs.FirstPage = 0i64;
  this->Glyphs.LastPage = 0i64;
  this->Glyphs.NumElementsInPage = 127;
  this->Glyphs.FirstEmptySlot = 0i64;
  this->Glyphs.pHeapOrPtr = &this->Glyphs;
  this->Bands.Data = 0i64;
  this->Bands.Size = 0i64;
  this->Bands.Capacity = 0i64;
  this->GlyphHTable.mHash.pTable = 0i64;
  this->NumUsedBands = 0;
  this->Notifiers.FirstPage = 0i64;
  this->Notifiers.LastPage = 0i64;
  this->Notifiers.NumElementsInPage = 127;
  this->Notifiers.FirstEmptySlot = 0i64;
  this->Notifiers.pHeapOrPtr = &this->Notifiers;
  this->pEvictNotifier = 0i64;
}

// File Line: 49
// RVA: 0x95F3D0
void __fastcall Scaleform::Render::GlyphQueue::Clear(Scaleform::Render::GlyphQueue *this)
{
  Scaleform::Render::GlyphSlot *pNext; // rdi
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *i; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> >::TableType *pTable; // rax
  __int64 v5; // rcx
  __int64 v6; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> >::TableType *v7; // rax
  unsigned int v8; // edx
  __int64 v9; // rcx
  Scaleform::List2<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot_Band> *p_Slots; // rcx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::PageType *FirstPage; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::PageType *v12; // rdi
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::PageType *v13; // rdx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::PageType *v14; // rdi

  pNext = this->SlotQueue.Root.pNext;
  for ( i = &this->SlotQueue; pNext != (Scaleform::Render::GlyphSlot *)i; pNext = pNext->pNext )
  {
    while ( (Scaleform::List<Scaleform::Render::TextNotifier,Scaleform::Render::TextNotifier> *)pNext->TextFields.Root.pNext != &pNext->TextFields )
      this->pEvictNotifier->vfptr->Evict(this->pEvictNotifier, pNext->TextFields.Root.pNext->pText);
  }
  pTable = this->GlyphHTable.mHash.pTable;
  if ( pTable )
  {
    v5 = 0i64;
    v6 = pTable->SizeMask + 1;
    do
    {
      v7 = this->GlyphHTable.mHash.pTable;
      if ( v7[v5 + 1].EntryCount != -2i64 )
        v7[v5 + 1].EntryCount = -2i64;
      v5 += 2i64;
      --v6;
    }
    while ( v6 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->GlyphHTable.mHash.pTable);
    this->GlyphHTable.mHash.pTable = 0i64;
  }
  i->Root.pPrev = (Scaleform::Render::GlyphSlot *)i;
  i->Root.pNext = (Scaleform::Render::GlyphSlot *)i;
  v8 = 0;
  this->ActiveSlots.Root.pPrevActive = &this->ActiveSlots.Root;
  for ( this->ActiveSlots.Root.pNextActive = &this->ActiveSlots.Root;
        v8 < this->NumUsedBands;
        p_Slots->Root.pNextInBand = &p_Slots->Root )
  {
    v9 = v8++;
    p_Slots = &this->Bands.Data[v9].Slots;
    p_Slots->Root.pPrevInBand = &p_Slots->Root;
  }
  FirstPage = this->Slots.FirstPage;
  if ( FirstPage )
  {
    do
    {
      v12 = FirstPage->pNext;
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      FirstPage = v12;
    }
    while ( v12 );
  }
  this->Slots.FirstPage = 0i64;
  this->Slots.LastPage = 0i64;
  this->Slots.NumElementsInPage = 127;
  this->Slots.FirstEmptySlot = 0i64;
  v13 = this->Glyphs.FirstPage;
  if ( v13 )
  {
    do
    {
      v14 = v13->pNext;
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v13 = v14;
    }
    while ( v14 );
  }
  this->Glyphs.FirstPage = 0i64;
  this->Glyphs.LastPage = 0i64;
  this->Glyphs.FirstEmptySlot = 0i64;
  this->Glyphs.NumElementsInPage = 127;
  this->SlotQueueSize = 0;
  this->NumUsedBands = 0;
}

// File Line: 118
// RVA: 0x9EB7B0
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::packGlyph(
        Scaleform::Render::GlyphQueue *this,
        unsigned int w,
        unsigned int h,
        Scaleform::Render::GlyphNode *glyph)
{
  Scaleform::Render::GlyphNode *pNext; // r9
  Scaleform::Render::GlyphNode *v8; // r10
  Scaleform::Render::GlyphNode *result; // rax
  Scaleform::Render::GlyphNode *pNex2; // r9
  unsigned int v11; // ebp
  unsigned int v12; // edi
  unsigned int v13; // edi
  unsigned int v14; // ebp
  Scaleform::Render::GlyphNode *v15; // rax
  Scaleform::Render::GlyphNode *v16; // rax
  Scaleform::Render::GlyphNode *v17; // rax
  Scaleform::Render::GlyphQueue *v18; // [rsp+40h] [rbp+8h]
  unsigned __int16 v19; // [rsp+50h] [rbp+18h]

  v19 = h;
  v18 = this;
  if ( glyph->Param.pFont )
  {
    pNext = glyph->pNext;
    v8 = 0i64;
    if ( pNext )
    {
      result = Scaleform::Render::GlyphQueue::packGlyph(this, w, h, pNext);
      v8 = result;
      if ( result )
        return result;
      this = v18;
    }
    pNex2 = glyph->pNex2;
    if ( pNex2 )
      return Scaleform::Render::GlyphQueue::packGlyph(this, w, h, pNex2);
    return v8;
  }
  else
  {
    v11 = glyph->mRect.w;
    if ( w > v11 )
      return 0i64;
    v12 = glyph->mRect.h;
    if ( h > v12 )
    {
      return 0i64;
    }
    else
    {
      v13 = v12 - h;
      v14 = v11 - w;
      if ( v14 >= this->MinSlotSpace || v13 >= this->MinSlotSpace )
      {
        v15 = Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75>>::Alloc(
                &this->Glyphs,
                glyph);
        glyph->pNext = v15;
        if ( v14 <= v13 )
        {
          v15->mRect.y = v19 + glyph->mRect.y;
          glyph->pNext->mRect.h = v13;
          if ( v14 >= v18->MinSlotSpace )
          {
            v17 = Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75>>::Alloc(
                    &v18->Glyphs,
                    glyph);
            glyph->pNex2 = v17;
            v17->pNext = 0i64;
            glyph->pNex2->mRect.x = w + glyph->mRect.x;
            glyph->pNex2->mRect.w = v14;
            glyph->pNex2->mRect.h = v19;
          }
        }
        else
        {
          v15->mRect.x = w + glyph->mRect.x;
          glyph->pNext->mRect.w = v14;
          if ( v13 >= v18->MinSlotSpace )
          {
            v16 = Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75>>::Alloc(
                    &v18->Glyphs,
                    glyph);
            glyph->pNex2 = v16;
            v16->pNext = 0i64;
            glyph->pNex2->mRect.y = v19 + glyph->mRect.y;
            glyph->pNex2->mRect.h = v13;
            glyph->pNex2->mRect.w = w;
            glyph->mRect.w = w;
            glyph->mRect.h = v19;
            return glyph;
          }
        }
      }
      glyph->mRect.w = w;
      glyph->mRect.h = v19;
      return glyph;
    }
  }
}

// File Line: 192
// RVA: 0x9F3320
void __fastcall Scaleform::Render::GlyphQueue::splitSlot(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphSlot *slot,
        __int16 w)
{
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::PageType *inited; // rax
  Scaleform::Render::GlyphNode *pRoot; // rdx
  Scaleform::Render::GlyphSlot *v8; // r8
  Scaleform::Render::GlyphSlot *pNextInBand; // rax
  Scaleform::Render::GlyphSlot *pNextActive; // rax

  inited = Scaleform::Render::GlyphQueue::initNewSlot(this, slot->pBand, w + slot->x, slot->w - w);
  pRoot = slot->pRoot;
  slot->w = w;
  pRoot->mRect.w = w;
  inited->Data[0].pNext = this->SlotQueue.Root.pNext;
  v8 = (Scaleform::Render::GlyphSlot *)inited;
  inited->Data[0].pPrev = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  this->SlotQueue.Root.pNext->pPrev = (Scaleform::Render::GlyphSlot *)inited;
  this->SlotQueue.Root.pNext = (Scaleform::Render::GlyphSlot *)inited;
  ++this->SlotQueueSize;
  pNextInBand = slot->pNextInBand;
  v8->pPrevInBand = slot;
  v8->pNextInBand = pNextInBand;
  pNextInBand->pPrevInBand = v8;
  slot->pNextInBand = v8;
  pNextActive = this->ActiveSlots.Root.pNextActive;
  v8->pPrevActive = &this->ActiveSlots.Root;
  v8->pNextActive = pNextActive;
  this->ActiveSlots.Root.pNextActive->pPrevActive = v8;
  this->ActiveSlots.Root.pNextActive = v8;
}

// File Line: 208
// RVA: 0x9F2A00
void __fastcall Scaleform::Render::GlyphQueue::splitGlyph(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphSlot *slot,
        bool left,
        __int16 w)
{
  Scaleform::Render::GlyphNode *pRoot; // rbp
  Scaleform::Render::GlyphBand *pBand; // rdx
  unsigned __int16 v9; // di
  bool v10; // zf
  unsigned __int16 x; // r8
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::PageType *v12; // rax
  Scaleform::Render::GlyphSlot *pPrevInBand; // rcx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::PageType *inited; // rdx
  Scaleform::Render::GlyphSlot *pNextInBand; // rax
  Scaleform::Render::GlyphSlot *pNextActive; // rax

  pRoot = slot->pRoot;
  pBand = slot->pBand;
  v9 = pRoot->mRect.w - w;
  v10 = !left;
  x = pRoot->mRect.x;
  if ( v10 )
  {
    inited = Scaleform::Render::GlyphQueue::initNewSlot(this, pBand, w + x, v9);
    pNextInBand = slot->pNextInBand;
    inited->Data[0].pNextInBand = pNextInBand;
    inited->Data[0].pPrevInBand = slot;
    pNextInBand->pPrevInBand = (Scaleform::Render::GlyphSlot *)inited;
    slot->pNextInBand = (Scaleform::Render::GlyphSlot *)inited;
  }
  else
  {
    v12 = Scaleform::Render::GlyphQueue::initNewSlot(this, pBand, x, v9);
    pPrevInBand = slot->pPrevInBand;
    v12->Data[0].pNextInBand = slot;
    v12->Data[0].pPrevInBand = pPrevInBand;
    pPrevInBand->pNextInBand = (Scaleform::Render::GlyphSlot *)v12;
    slot->x += v9;
    LOWORD(pPrevInBand) = slot->x;
    slot->pPrevInBand = (Scaleform::Render::GlyphSlot *)v12;
    pRoot->mRect.x = (unsigned __int16)pPrevInBand;
    inited = v12;
  }
  pRoot->mRect.w = w;
  slot->w -= v9;
  inited->Data[0].pNext = this->SlotQueue.Root.pNext;
  inited->Data[0].pPrev = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  this->SlotQueue.Root.pNext->pPrev = (Scaleform::Render::GlyphSlot *)inited;
  this->SlotQueue.Root.pNext = (Scaleform::Render::GlyphSlot *)inited;
  ++this->SlotQueueSize;
  pNextActive = this->ActiveSlots.Root.pNextActive;
  inited->Data[0].pPrevActive = &this->ActiveSlots.Root;
  inited->Data[0].pNextActive = pNextActive;
  this->ActiveSlots.Root.pNextActive->pPrevActive = (Scaleform::Render::GlyphSlot *)inited;
  this->ActiveSlots.Root.pNextActive = (Scaleform::Render::GlyphSlot *)inited;
}

// File Line: 233
// RVA: 0x9EB960
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::packGlyph(
        Scaleform::Render::GlyphQueue *this,
        unsigned int w,
        unsigned int h,
        Scaleform::Render::GlyphSlot *slot)
{
  Scaleform::Render::GlyphNode *pRoot; // r9
  unsigned int v9; // r10d
  unsigned int v10; // edx
  int x; // ecx
  int v12; // eax
  Scaleform::Render::GlyphNode *result; // rax
  unsigned __int16 Failures; // cx

  pRoot = slot->pRoot;
  if ( !pRoot->Param.pFont )
  {
    v9 = slot->w;
    if ( v9 > 2 * w )
    {
      if ( pRoot->pNext )
      {
        if ( !pRoot->pNex2 && pRoot->mRect.h == slot->pBand->h )
        {
          v10 = pRoot->mRect.w;
          if ( v10 > w )
          {
            x = pRoot->mRect.x;
            v12 = slot->x;
            if ( ((_WORD)x == (unsigned __int16)v12) != (v10 + x == v9 + v12) )
              Scaleform::Render::GlyphQueue::splitGlyph(this, slot, (_WORD)x == (unsigned __int16)v12, w);
          }
        }
      }
      else if ( !pRoot->pNex2 )
      {
        Scaleform::Render::GlyphQueue::splitSlot(this, slot, w);
      }
    }
  }
  result = Scaleform::Render::GlyphQueue::packGlyph(this, w, h, slot->pRoot);
  if ( !result )
    ++slot->Failures;
  Failures = slot->Failures;
  if ( Failures <= 0x10u )
  {
    if ( Failures )
    {
      if ( result )
        slot->Failures = Failures - 1;
    }
  }
  else
  {
    slot->pPrevActive->pNextActive = slot->pNextActive;
    slot->pNextActive->pPrevActive = slot->pPrevActive;
    slot->TextureId |= 0x8000u;
  }
  return result;
}

// File Line: 285
// RVA: 0x9E3110
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::findSpaceInSlots(
        Scaleform::Render::GlyphQueue *this,
        unsigned int w,
        unsigned int h)
{
  Scaleform::Render::GlyphSlot *pNextActive; // rbx
  Scaleform::List2<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot_Active> *p_ActiveSlots; // r14
  Scaleform::Render::GlyphNode *pRoot; // rdx
  Scaleform::List2<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot_Active> *v9; // rsi
  unsigned int v10; // r8d
  unsigned int v11; // r9d
  int x; // ecx
  int v13; // eax
  Scaleform::Render::GlyphNode *result; // rax
  unsigned __int16 Failures; // cx

  pNextActive = this->ActiveSlots.Root.pNextActive;
  p_ActiveSlots = &this->ActiveSlots;
  if ( pNextActive != (Scaleform::Render::GlyphSlot *)&this->ActiveSlots )
  {
    while ( 1 )
    {
      pRoot = pNextActive->pRoot;
      v9 = (Scaleform::List2<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot_Active> *)pNextActive->pNextActive;
      if ( !pRoot->Param.pFont )
      {
        v10 = pNextActive->w;
        if ( v10 > 2 * w )
        {
          if ( pRoot->pNext )
          {
            if ( !pRoot->pNex2 && pRoot->mRect.h == pNextActive->pBand->h )
            {
              v11 = pRoot->mRect.w;
              if ( v11 > w )
              {
                x = pRoot->mRect.x;
                v13 = pNextActive->x;
                if ( ((_WORD)x == (unsigned __int16)v13) != (v11 + x == v10 + v13) )
                  Scaleform::Render::GlyphQueue::splitGlyph(this, pNextActive, (_WORD)x == (unsigned __int16)v13, w);
              }
            }
          }
          else if ( !pRoot->pNex2 )
          {
            Scaleform::Render::GlyphQueue::splitSlot(this, pNextActive, w);
          }
        }
      }
      result = Scaleform::Render::GlyphQueue::packGlyph(this, w, h, pNextActive->pRoot);
      if ( !result )
        ++pNextActive->Failures;
      Failures = pNextActive->Failures;
      if ( Failures > 0x10u )
        break;
      if ( !Failures )
        goto LABEL_19;
      if ( result )
      {
        pNextActive->Failures = Failures - 1;
LABEL_19:
        if ( result )
          return result;
      }
      pNextActive = &v9->Root;
      if ( v9 == p_ActiveSlots )
        return 0i64;
    }
    pNextActive->pPrevActive->pNextActive = pNextActive->pNextActive;
    pNextActive->pNextActive->pPrevActive = pNextActive->pPrevActive;
    pNextActive->TextureId |= 0x8000u;
    goto LABEL_19;
  }
  return 0i64;
}

// File Line: 331
// RVA: 0x9E8520
Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::PageType *__fastcall Scaleform::Render::GlyphQueue::initNewSlot(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphBand *band,
        unsigned __int16 x,
        unsigned __int16 w)
{
  Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::PageType *v8; // rbp
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::PageType *v9; // rax
  unsigned __int16 TextureId; // cx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::PageType *v11; // r8
  Scaleform::Render::GlyphRect v13; // [rsp+40h] [rbp+8h]

  v8 = Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75>>::allocate(&this->Slots);
  v9 = Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75>>::allocate(&this->Glyphs);
  v8->Data[0].pBand = band;
  v8->Data[0].pRoot = (Scaleform::Render::GlyphNode *)v9;
  TextureId = band->TextureId;
  v8->Data[0].x = x;
  v8->Data[0].TextureId = TextureId;
  v8->Data[0].w = w;
  v11 = v9;
  v8->Data[0].Failures = 0;
  v8->Data[0].PinCount = 0;
  v8->Data[0].TextFields.Root.pPrev = (Scaleform::Render::TextNotifier *)&v8->Data[0].TextFields;
  v8->Data[0].TextFields.Root.pNext = (Scaleform::Render::TextNotifier *)&v8->Data[0].TextFields;
  v8->Data[0].SlotFence.pObject = 0i64;
  v9->Data[0].Param.pFont = 0i64;
  *(_QWORD *)&v9->Data[0].Param.GlyphIndex = 0i64;
  v9->Data[0].Param.BlurY = 0;
  v9->Data[0].Param.BlurStrength = 16;
  v9->Data[0].pSlot = (Scaleform::Render::GlyphSlot *)v8;
  v9->Data[0].pNext = 0i64;
  v9->Data[0].pNex2 = 0i64;
  v13.x = v8->Data[0].x;
  v13.y = band->y;
  v13.w = v8->Data[0].w;
  LOWORD(v9) = band->h;
  v11->Data[0].Origin = 0;
  v13.h = (unsigned __int16)v9;
  v11->Data[0].mRect = v13;
  return v8;
}

// File Line: 360
// RVA: 0x9CE540
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::allocateNewSlot(
        Scaleform::Render::GlyphQueue *this,
        unsigned int w,
        unsigned int h)
{
  unsigned __int64 NumUsedBands; // rcx
  unsigned int v7; // edx
  Scaleform::Render::GlyphBand *v8; // r8
  unsigned __int16 v9; // cx
  unsigned int MaxSlotHeight; // ecx
  Scaleform::Render::GlyphBand *v11; // rdi
  unsigned int RightSpace; // ecx
  unsigned int v13; // r9d
  Scaleform::Render::GlyphSlot *inited; // r9
  Scaleform::Render::GlyphSlot *pPrev; // rcx
  Scaleform::Render::GlyphSlot *pNextActive; // rax

  NumUsedBands = this->NumUsedBands;
  if ( (!(_DWORD)NumUsedBands || this->Bands.Data[(unsigned int)(NumUsedBands - 1)].RightSpace < w)
    && NumUsedBands < this->Bands.Size )
  {
    v7 = (unsigned int)NumUsedBands % this->NumBandsInTexture;
    v8 = &this->Bands.Data[NumUsedBands];
    v8->TextureId = (unsigned int)NumUsedBands / this->NumBandsInTexture + LOWORD(this->FirstTexture);
    v9 = v7 * LOWORD(this->MaxSlotHeight);
    v8->y = v9;
    if ( v7 + 1 == this->NumBandsInTexture )
      LOWORD(MaxSlotHeight) = this->TextureHeight - v9;
    else
      MaxSlotHeight = this->MaxSlotHeight;
    v8->h = MaxSlotHeight;
    v8->RightSpace = this->TextureWidth;
    v8->Slots.Root.pPrevInBand = &v8->Slots.Root;
    v8->Slots.Root.pNextInBand = &v8->Slots.Root;
    ++this->NumUsedBands;
  }
  v11 = &this->Bands.Data[this->NumUsedBands - 1];
  RightSpace = v11->RightSpace;
  if ( w > RightSpace )
    return 0i64;
  v13 = w;
  if ( RightSpace - w < w )
    v13 = v11->RightSpace;
  inited = Scaleform::Render::GlyphQueue::initNewSlot(
             this,
             &this->Bands.Data[this->NumUsedBands - 1],
             this->TextureWidth - RightSpace,
             v13);
  v11->RightSpace -= inited->w;
  pPrev = this->SlotQueue.Root.pPrev;
  inited->pNext = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  inited->pPrev = pPrev;
  this->SlotQueue.Root.pPrev->pNext = inited;
  this->SlotQueue.Root.pPrev = inited;
  ++this->SlotQueueSize;
  inited->pPrevInBand = v11->Slots.Root.pPrevInBand;
  inited->pNextInBand = &v11->Slots.Root;
  v11->Slots.Root.pPrevInBand->pNextInBand = inited;
  v11->Slots.Root.pPrevInBand = inited;
  pNextActive = this->ActiveSlots.Root.pNextActive;
  inited->pPrevActive = &this->ActiveSlots.Root;
  inited->pNextActive = pNextActive;
  this->ActiveSlots.Root.pNextActive->pPrevActive = inited;
  this->ActiveSlots.Root.pNextActive = inited;
  return Scaleform::Render::GlyphQueue::packGlyph(this, w, h, inited);
}

// File Line: 410
// RVA: 0x9EFC60
void __fastcall Scaleform::Render::GlyphQueue::releaseGlyphTree(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *glyph)
{
  Scaleform::Render::GlyphParamHash key; // [rsp+38h] [rbp+10h] BYREF

  if ( glyph )
  {
    Scaleform::Render::GlyphQueue::releaseGlyphTree(this, (Scaleform::Render::GlyphNode *)glyph[4].pNext);
    Scaleform::Render::GlyphQueue::releaseGlyphTree(this, (Scaleform::Render::GlyphNode *)glyph[5].pNext);
    if ( glyph->pNext )
    {
      key.Param = (Scaleform::Render::GlyphParam *)glyph;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::RemoveAlt<Scaleform::Render::GlyphParamHash>(
        &this->GlyphHTable.mHash,
        &key);
    }
    glyph->pNext = 0i64;
    glyph->pNext = this->Glyphs.FirstEmptySlot;
    this->Glyphs.FirstEmptySlot = glyph;
  }
}

// File Line: 430
// RVA: 0x9EFF10
void __fastcall Scaleform::Render::GlyphQueue::releaseSlot(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphSlot *slot)
{
  Scaleform::Render::Fence *pObject; // r8
  Scaleform::Render::FenceImpl *Data; // r8
  Scaleform::Render::Fence *v6; // rcx
  Scaleform::Render::GlyphNode *pNext; // rsi
  Scaleform::Render::GlyphNode *pNex2; // rsi
  Scaleform::Render::GlyphBand *pBand; // rax
  unsigned __int16 RightSpace; // cx
  Scaleform::Render::GlyphBand *v11; // rcx
  unsigned __int16 h; // ax
  Scaleform::Render::GlyphNode *pRoot; // rcx
  Scaleform::Render::Fence *v14; // rcx
  signed __int16 TextureId; // ax
  Scaleform::Render::GlyphSlot *pNextActive; // rax
  Scaleform::Render::GlyphParamHash key; // [rsp+38h] [rbp+10h] BYREF

  if ( !slot->PinCount )
  {
    pObject = slot->SlotFence.pObject;
    if ( pObject )
    {
      if ( pObject->HasData )
      {
        Data = pObject->Data;
        if ( Data )
        {
          if ( Data->Parent )
            ((void (__fastcall *)(Scaleform::Render::RenderSync *, __int64, unsigned __int64))Data->RSContext->vfptr[5].__vecDelDtor)(
              Data->RSContext,
              1i64,
              Data->APIHandle);
        }
      }
    }
    v6 = slot->SlotFence.pObject;
    if ( v6 )
      Scaleform::Render::Fence::Release(v6);
    slot->SlotFence.pObject = 0i64;
  }
  pNext = slot->pRoot->pNext;
  if ( pNext )
  {
    Scaleform::Render::GlyphQueue::releaseGlyphTree(
      this,
      (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)pNext->pNext);
    Scaleform::Render::GlyphQueue::releaseGlyphTree(
      this,
      (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)pNext->pNex2);
    if ( pNext->Param.pFont )
    {
      key.Param = &pNext->Param;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::RemoveAlt<Scaleform::Render::GlyphParamHash>(
        &this->GlyphHTable.mHash,
        &key);
    }
    pNext->Param.pFont = 0i64;
    pNext->Param.pFont = (Scaleform::Render::FontCacheHandle *)this->Glyphs.FirstEmptySlot;
    this->Glyphs.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)pNext;
  }
  pNex2 = slot->pRoot->pNex2;
  if ( pNex2 )
  {
    Scaleform::Render::GlyphQueue::releaseGlyphTree(
      this,
      (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)pNex2->pNext);
    Scaleform::Render::GlyphQueue::releaseGlyphTree(
      this,
      (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)pNex2->pNex2);
    if ( pNex2->Param.pFont )
    {
      key.Param = &pNex2->Param;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::RemoveAlt<Scaleform::Render::GlyphParamHash>(
        &this->GlyphHTable.mHash,
        &key);
    }
    pNex2->Param.pFont = 0i64;
    pNex2->Param.pFont = (Scaleform::Render::FontCacheHandle *)this->Glyphs.FirstEmptySlot;
    this->Glyphs.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)pNex2;
  }
  while ( (Scaleform::List<Scaleform::Render::TextNotifier,Scaleform::Render::TextNotifier> *)slot->TextFields.Root.pNext != &slot->TextFields )
    this->pEvictNotifier->vfptr->Evict(this->pEvictNotifier, slot->TextFields.Root.pNext->pText);
  if ( slot->pRoot->Param.pFont )
  {
    key.Param = &slot->pRoot->Param;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::RemoveAlt<Scaleform::Render::GlyphParamHash>(
      &this->GlyphHTable.mHash,
      &key);
  }
  pBand = slot->pBand;
  RightSpace = pBand->RightSpace;
  if ( RightSpace && slot == pBand->Slots.Root.pPrevInBand )
  {
    slot->w += RightSpace;
    pBand->RightSpace = 0;
  }
  slot->pRoot->Param.pFont = 0i64;
  v11 = slot->pBand;
  LOWORD(key.Param) = slot->x;
  WORD1(key.Param) = v11->y;
  WORD2(key.Param) = slot->w;
  h = v11->h;
  pRoot = slot->pRoot;
  HIWORD(key.Param) = h;
  pRoot->mRect = (Scaleform::Render::GlyphRect)key.Param;
  slot->pRoot->pNext = 0i64;
  slot->pRoot->pNex2 = 0i64;
  slot->Failures = 0;
  v14 = slot->SlotFence.pObject;
  if ( v14 )
    Scaleform::Render::Fence::Release(v14);
  slot->SlotFence.pObject = 0i64;
  TextureId = slot->TextureId;
  if ( TextureId < 0 )
  {
    slot->TextureId = TextureId & 0x7FFF;
    pNextActive = this->ActiveSlots.Root.pNextActive;
    slot->pPrevActive = &this->ActiveSlots.Root;
    slot->pNextActive = pNextActive;
    this->ActiveSlots.Root.pNextActive->pPrevActive = slot;
    this->ActiveSlots.Root.pNextActive = slot;
  }
}

// File Line: 478
// RVA: 0x9E9B70
void __fastcall Scaleform::Render::GlyphQueue::mergeSlots(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphSlot *from,
        Scaleform::Render::GlyphSlot *to,
        unsigned __int16 w)
{
  Scaleform::Render::GlyphSlot *i; // rbx
  Scaleform::Render::GlyphSlot *pNextInBand; // rbp
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *pRoot; // rcx
  Scaleform::Render::GlyphNode *v11; // rax
  Scaleform::Render::GlyphSlot *pNext; // rax

  for ( i = from; ; i = pNextInBand )
  {
    pNextInBand = i->pNextInBand;
    Scaleform::Render::GlyphQueue::releaseSlot(this, i);
    if ( i != from )
    {
      pRoot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)i->pRoot;
      pRoot->pNext = this->Glyphs.FirstEmptySlot;
      this->Glyphs.FirstEmptySlot = pRoot;
      i->pPrev->pNext = i->pNext;
      i->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$DAEF6AD9C4106FD318EA5478000E87CA::pPrev = i->pPrev;
      --this->SlotQueueSize;
      if ( (i->TextureId & 0x8000) == 0 )
      {
        i->pPrevActive->pNextActive = i->pNextActive;
        i->pNextActive->pPrevActive = i->pPrevActive;
      }
      i->pPrevInBand->pNextInBand = i->pNextInBand;
      i->pNextInBand->pPrevInBand = i->pPrevInBand;
      i->pPrev = (Scaleform::Render::GlyphSlot *)this->Slots.FirstEmptySlot;
      this->Slots.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)i;
    }
    if ( i == to )
      break;
  }
  v11 = from->pRoot;
  from->w = w;
  v11->mRect.w = w;
  from->pPrev->pNext = from->pNext;
  from->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$DAEF6AD9C4106FD318EA5478000E87CA::pPrev = from->pPrev;
  pNext = this->SlotQueue.Root.pNext;
  from->pPrev = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  from->pNext = pNext;
  this->SlotQueue.Root.pNext->pPrev = from;
  this->SlotQueue.Root.pNext = from;
}

// File Line: 512
// RVA: 0x9E99A0
Scaleform::Render::GlyphSlot *__fastcall Scaleform::Render::GlyphQueue::mergeSlotWithNeighbor(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphSlot *slot)
{
  Scaleform::Render::GlyphBand *pBand; // r13
  Scaleform::Render::GlyphSlot *pNextInBand; // rbx
  char v6; // bp
  Scaleform::Render::GlyphNode *pRoot; // rsi
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *v8; // r14
  int x; // edx
  int w; // r8d
  int v11; // eax
  bool v12; // zf
  unsigned __int16 TextureId; // ax
  Scaleform::Render::GlyphSlot *pNextActive; // rcx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *v16; // [rsp+58h] [rbp+10h]

  pBand = slot->pBand;
  pNextInBand = slot->pNextInBand;
  v6 = 1;
  if ( pNextInBand == (Scaleform::Render::GlyphSlot *)&pBand->Slots )
  {
    pNextInBand = slot->pPrevInBand;
    v6 = 0;
    if ( pNextInBand == (Scaleform::Render::GlyphSlot *)&pBand->Slots )
      return 0i64;
  }
  if ( pNextInBand->w > slot->w )
    return 0i64;
  pRoot = pNextInBand->pRoot;
  v8 = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)slot->pRoot;
  Scaleform::Render::GlyphQueue::releaseSlot(this, slot);
  x = slot->x;
  w = slot->w;
  slot->pPrev->pNext = slot->pNext;
  slot->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$DAEF6AD9C4106FD318EA5478000E87CA::pPrev = slot->pPrev;
  --this->SlotQueueSize;
  if ( (slot->TextureId & 0x8000u) == 0 )
  {
    slot->pPrevActive->pNextActive = slot->pNextActive;
    slot->pNextActive->pPrevActive = slot->pPrevActive;
  }
  slot->pPrevInBand->pNextInBand = slot->pNextInBand;
  slot->pNextInBand->pPrevInBand = slot->pPrevInBand;
  slot->pPrev = (Scaleform::Render::GlyphSlot *)this->Slots.FirstEmptySlot;
  this->Slots.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)slot;
  if ( pRoot->Param.pFont
    || pRoot->pNex2
    || pRoot->mRect.h != pBand->h
    || ((v11 = pRoot->mRect.x, !v6) ? (v12 = v11 + pRoot->mRect.w == x) : (v12 = w + x == v11), !v12) )
  {
    v8[4].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)pRoot;
    v8[5].pNext = 0i64;
    v8[3].pNext = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)pNextInBand;
    LOWORD(v16) = x;
    WORD2(v16) = w;
    WORD1(v16) = pBand->y;
    HIWORD(v16) = pBand->h;
    v8[6].pNext = v16;
    pNextInBand->pRoot = (Scaleform::Render::GlyphNode *)v8;
  }
  else
  {
    v8->pNext = this->Glyphs.FirstEmptySlot;
    this->Glyphs.FirstEmptySlot = v8;
    if ( v6 )
      pRoot->mRect.x = x;
    pRoot->mRect.w += w;
  }
  if ( v6 )
    pNextInBand->x = x;
  TextureId = pNextInBand->TextureId;
  pNextInBand->w += w;
  if ( (TextureId & 0x8000) != 0 )
  {
    pNextInBand->Failures = 0;
    pNextInBand->TextureId = TextureId & 0x7FFF;
    pNextActive = this->ActiveSlots.Root.pNextActive;
    pNextInBand->pPrevActive = &this->ActiveSlots.Root;
    pNextInBand->pNextActive = pNextActive;
    this->ActiveSlots.Root.pNextActive->pPrevActive = pNextInBand;
    this->ActiveSlots.Root.pNextActive = pNextInBand;
  }
  return pNextInBand;
}

// File Line: 610
// RVA: 0x9E2470
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::evictOldSlot(
        Scaleform::Render::GlyphQueue *this,
        unsigned int w,
        unsigned int h,
        unsigned int pass)
{
  Scaleform::Render::GlyphSlot *pNext; // rbx
  unsigned int SlotQueueSize; // ebp
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *p_SlotQueue; // rdi
  int v10; // esi
  Scaleform::Render::GlyphSlot *v11; // rax
  Scaleform::Render::GlyphSlot *i; // rbp
  Scaleform::Render::GlyphBand *pBand; // r15
  unsigned int v14; // esi
  Scaleform::Render::GlyphSlot *j; // rbx
  Scaleform::Render::GlyphSlot *pPrev; // rcx
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *v17; // rax
  char v18; // al
  unsigned int v19; // eax
  unsigned __int16 RightSpace; // ax

  pNext = this->SlotQueue.Root.pNext;
  SlotQueueSize = this->SlotQueueSize;
  if ( !pass )
    SlotQueueSize >>= 1;
  p_SlotQueue = &this->SlotQueue;
  v10 = 0;
  while ( pNext != (Scaleform::Render::GlyphSlot *)p_SlotQueue )
  {
    if ( !Scaleform::Render::GlyphQueue::IsPinned(pNext, this->FenceWaitOnFullCache) )
    {
      if ( pNext->w >= w )
      {
        Scaleform::Render::GlyphQueue::releaseSlot(this, pNext);
        return Scaleform::Render::GlyphQueue::packGlyph(this, w, h, pNext);
      }
      v11 = Scaleform::Render::GlyphQueue::mergeSlotWithNeighbor(this, pNext);
      if ( v11 )
      {
        if ( v11->pRoot->mRect.w >= w )
          return Scaleform::Render::GlyphQueue::packGlyph(this, w, h, v11);
        break;
      }
    }
    pNext = pNext->pNext;
    if ( ++v10 > SlotQueueSize )
      break;
  }
  for ( i = this->SlotQueue.Root.pNext; i != (Scaleform::Render::GlyphSlot *)p_SlotQueue; i = i->pNext )
  {
    if ( !Scaleform::Render::GlyphQueue::IsPinned(i, this->FenceWaitOnFullCache) )
    {
      pBand = i->pBand;
      v14 = 0;
      for ( j = i; j != (Scaleform::Render::GlyphSlot *)&pBand->Slots; j = j->pNextInBand )
      {
        if ( Scaleform::Render::GlyphQueue::IsPinned(j, this->FenceWaitOnFullCache) )
          break;
        if ( pass
          || (pPrev = j,
              v17 = (Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *)j,
              j == (Scaleform::Render::GlyphSlot *)p_SlotQueue) )
        {
LABEL_17:
          v18 = 1;
        }
        else
        {
          while ( v17 != p_SlotQueue )
          {
            pPrev = pPrev->pPrev;
            v17 = (Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *)v17->Root.pNext;
            if ( pPrev == (Scaleform::Render::GlyphSlot *)p_SlotQueue )
              goto LABEL_17;
          }
          v18 = 0;
        }
        if ( j != i && !v18 )
          break;
        v19 = j->w;
        if ( v19 >= w )
        {
          Scaleform::Render::GlyphQueue::releaseSlot(this, j);
          return Scaleform::Render::GlyphQueue::packGlyph(this, w, h, j);
        }
        v14 += v19;
        RightSpace = pBand->RightSpace;
        if ( RightSpace && j == pBand->Slots.Root.pPrevInBand && v14 + RightSpace >= w )
        {
          v14 += RightSpace;
          pBand->RightSpace = 0;
        }
        if ( v14 >= w )
        {
          Scaleform::Render::GlyphQueue::mergeSlots(this, i, j, v14);
          return Scaleform::Render::GlyphQueue::packGlyph(this, w, h, i);
        }
      }
    }
  }
  return 0i64;
}

// File Line: 711
// RVA: 0x9E2400
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::evictOldSlot(
        Scaleform::Render::GlyphQueue *this,
        unsigned int w,
        unsigned int h)
{
  Scaleform::Render::GlyphNode *result; // rax

  this->pEvictNotifier->vfptr->ApplyInUseList(this->pEvictNotifier);
  result = Scaleform::Render::GlyphQueue::evictOldSlot(this, w, h, 0);
  if ( !result )
  {
    this->pEvictNotifier->vfptr->UpdatePinList(this->pEvictNotifier);
    return Scaleform::Render::GlyphQueue::evictOldSlot(this, w, h, 1u);
  }
  return result;
}

// File Line: 726
// RVA: 0x9691C0
Scaleform::Render::TextNotifier *__fastcall Scaleform::Render::GlyphQueue::CreateNotifier(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphNode *node,
        Scaleform::Render::TextMeshProvider *tm)
{
  Scaleform::Render::GlyphSlot *pSlot; // rsi
  Scaleform::Render::TextNotifier *pPrev; // rax
  Scaleform::Render::TextNotifier *p_TextFields; // rbx
  Scaleform::Render::TextNotifier *result; // rax
  Scaleform::Render::TextNotifier *v8; // rcx

  pSlot = node->pSlot;
  pPrev = pSlot->TextFields.Root.pPrev;
  p_TextFields = (Scaleform::Render::TextNotifier *)&pSlot->TextFields;
  if ( pPrev != (Scaleform::Render::TextNotifier *)&pSlot->TextFields && tm == pPrev->pText )
    return 0i64;
  result = Scaleform::ListAllocBase<Scaleform::Render::TextNotifier,127,Scaleform::AllocatorLH_POD<Scaleform::Render::TextNotifier,75>>::allocate(&this->Notifiers);
  result->pSlot = pSlot;
  result->pText = tm;
  v8 = p_TextFields->pPrev;
  result->pNext = p_TextFields;
  result->pPrev = v8;
  p_TextFields->pPrev->pNext = result;
  p_TextFields->pPrev = result;
  return result;
}

// File Line: 758
// RVA: 0x979DC0
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::FindGlyph(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphParam *gp)
{
  Scaleform::HashLH<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash,75,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> > *p_GlyphHTable; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> > v4; // rbx
  signed __int64 v5; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> >::TableType *v6; // rax
  Scaleform::Render::GlyphNode **p_SizeMask; // rax
  Scaleform::Render::GlyphNode *result; // rax
  Scaleform::Render::GlyphSlot *pSlot; // r9
  Scaleform::Render::GlyphSlot *pPrev; // rcx
  Scaleform::Render::GlyphParamHash key; // [rsp+30h] [rbp+8h] BYREF

  p_GlyphHTable = &this->GlyphHTable;
  key.Param = gp;
  v4.pTable = p_GlyphHTable->mHash.pTable;
  if ( !p_GlyphHTable->mHash.pTable )
    return 0i64;
  v5 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::findIndexCore<Scaleform::Render::GlyphParamHash>(
         &p_GlyphHTable->mHash,
         &key,
         v4.pTable->SizeMask & ((__int64)gp->pFont ^ ((unsigned __int64)gp->pFont >> 6) ^ gp->GlyphIndex ^ gp->FontSize ^ gp->Flags ^ gp->BlurX ^ gp->BlurStrength ^ (2i64 * gp->BlurY)));
  if ( v5 < 0 )
    return 0i64;
  v6 = &v4.pTable[2 * v5 + 2];
  if ( !v6 )
    return 0i64;
  p_SizeMask = (Scaleform::Render::GlyphNode **)&v6->SizeMask;
  if ( !p_SizeMask )
    return 0i64;
  result = *p_SizeMask;
  pSlot = result->pSlot;
  pSlot->pPrev->pNext = pSlot->pNext;
  pSlot->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$DAEF6AD9C4106FD318EA5478000E87CA::pPrev = pSlot->pPrev;
  pPrev = this->SlotQueue.Root.pPrev;
  pSlot->pNext = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
  pSlot->pPrev = pPrev;
  this->SlotQueue.Root.pPrev->pNext = pSlot;
  this->SlotQueue.Root.pPrev = pSlot;
  return result;
}

// File Line: 772
// RVA: 0x958180
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::AllocateGlyph(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::GlyphParam *gp,
        unsigned int w,
        unsigned int h)
{
  Scaleform::Render::GlyphNode *SpaceInSlots; // rcx
  Scaleform::Render::GlyphNode *result; // rax
  Scaleform::HashLH<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash,75,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> > *p_GlyphHTable; // rsi
  Scaleform::Render::GlyphSlot *pSlot; // r8
  Scaleform::Render::GlyphSlot *pPrev; // rax
  Scaleform::Render::GlyphParam *p_Param; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> >::TableType *pTable; // rbx
  signed __int64 v15; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> >::TableType *v16; // rax
  __int64 BlurY; // r9
  Scaleform::Render::GlyphParamHash key; // [rsp+20h] [rbp-28h] BYREF
  Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeRef v19; // [rsp+28h] [rbp-20h] BYREF
  Scaleform::Render::GlyphNode *v20; // [rsp+50h] [rbp+8h] BYREF

  if ( h < this->MinSlotSpace )
    this->MinSlotSpace = h;
  if ( w < this->MinSlotSpace )
    this->MinSlotSpace = w;
  SpaceInSlots = Scaleform::Render::GlyphQueue::findSpaceInSlots(this, w, h);
  v20 = SpaceInSlots;
  if ( SpaceInSlots
    || (SpaceInSlots = Scaleform::Render::GlyphQueue::allocateNewSlot(this, w, h), (v20 = SpaceInSlots) != 0i64)
    || (result = Scaleform::Render::GlyphQueue::evictOldSlot(this, w, h), SpaceInSlots = result, (v20 = result) != 0i64) )
  {
    p_GlyphHTable = &this->GlyphHTable;
    SpaceInSlots->Param.pFont = gp->pFont;
    *(_QWORD *)&SpaceInSlots->Param.GlyphIndex = *(_QWORD *)&gp->GlyphIndex;
    *(_QWORD *)&SpaceInSlots->Param.BlurY = *(_QWORD *)&gp->BlurY;
    v20->Origin.x = 0;
    v20->Origin.y = 0;
    pSlot = v20->pSlot;
    pSlot->pPrev->pNext = pSlot->pNext;
    pSlot->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$DAEF6AD9C4106FD318EA5478000E87CA::pPrev = pSlot->pPrev;
    pPrev = this->SlotQueue.Root.pPrev;
    pSlot->pNext = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
    pSlot->pPrev = pPrev;
    this->SlotQueue.Root.pPrev->pNext = pSlot;
    p_Param = &v20->Param;
    this->SlotQueue.Root.pPrev = pSlot;
    pTable = this->GlyphHTable.mHash.pTable;
    key.Param = p_Param;
    if ( !pTable
      || (v15 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::findIndexCore<Scaleform::Render::GlyphParamHash>(
                  &p_GlyphHTable->mHash,
                  &key,
                  pTable->SizeMask & ((__int64)p_Param->pFont ^ ((unsigned __int64)p_Param->pFont >> 6) ^ p_Param->GlyphIndex ^ p_Param->FontSize ^ p_Param->Flags ^ p_Param->BlurX ^ p_Param->BlurStrength ^ (2i64 * p_Param->BlurY))),
          v15 < 0)
      || (v16 = &pTable[2 * v15 + 2]) == 0i64
      || v16 == (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF> >::TableType *)-8i64 )
    {
      BlurY = p_Param->BlurY;
      v19.pFirst = &key;
      v19.pSecond = &v20;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::GlyphParamHash,75>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>,Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::Render::GlyphParamHash,Scaleform::Render::GlyphNode *,Scaleform::Render::GlyphParamHash>::NodeRef>(
        &p_GlyphHTable->mHash,
        p_GlyphHTable,
        &v19,
        (unsigned __int64)p_Param->pFont ^ ((unsigned __int64)p_Param->pFont >> 6) ^ p_Param->GlyphIndex ^ p_Param->FontSize ^ p_Param->Flags ^ p_Param->BlurX ^ p_Param->BlurStrength ^ (unsigned __int64)(2 * BlurY));
      return v20;
    }
    return (Scaleform::Render::GlyphNode *)p_Param;
  }
  return result;
}

// File Line: 806
// RVA: 0x9BBB40
void __fastcall Scaleform::Render::GlyphQueue::UnpinAllSlots(Scaleform::Render::GlyphQueue *this)
{
  Scaleform::Render::GlyphSlot *pNext; // rsi
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *i; // rbp
  Scaleform::Render::Fence *pObject; // rax
  Scaleform::Render::FenceImpl *Data; // r8
  Scaleform::Render::Fence *v5; // rbx
  Scaleform::Render::FenceImpl *v7; // rcx
  Scaleform::Render::RenderSync *RSContext; // rdi
  Scaleform::Render::FenceImpl *v9; // rcx

  pNext = this->SlotQueue.Root.pNext;
  for ( i = &this->SlotQueue; pNext != (Scaleform::Render::GlyphSlot *)i; pNext = pNext->pNext )
  {
    pObject = pNext->SlotFence.pObject;
    pNext->PinCount = 0;
    if ( pObject )
    {
      if ( pObject->HasData )
      {
        Data = pObject->Data;
        if ( pObject->Data )
        {
          if ( Data->Parent )
            ((void (__fastcall *)(Scaleform::Render::RenderSync *, __int64, unsigned __int64))Data->RSContext->vfptr[5].__vecDelDtor)(
              Data->RSContext,
              1i64,
              Data->APIHandle);
        }
      }
    }
    v5 = pNext->SlotFence.pObject;
    if ( v5 )
    {
      if ( v5->RefCount-- == 1 )
      {
        v7 = v5->Data;
        if ( v5->HasData )
        {
          RSContext = v7->RSContext;
          ((void (__fastcall *)(Scaleform::Render::FenceImpl *, unsigned __int64))v7->RSContext->FenceFrameAlloc.pHeapOrPtr)(
            v7,
            v7->APIHandle);
          v9 = v5->Data;
          v9->RSContext = (Scaleform::Render::RenderSync *)RSContext->FenceImplAlloc.FirstEmptySlot;
          RSContext->FenceImplAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::FenceImpl,127,Scaleform::AllocatorLH_POD<Scaleform::Render::FenceImpl,2> >::NodeType *)v9;
          v5->Data = (Scaleform::Render::FenceImpl *)RSContext->FenceAlloc.FirstEmptySlot;
          RSContext->FenceAlloc.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::Fence,127,Scaleform::AllocatorLH<Scaleform::Render::Fence,2> >::NodeType *)v5;
        }
        else
        {
          v5->Data = (Scaleform::Render::FenceImpl *)v7[4].Parent;
          v7[4].Parent = (Scaleform::Render::FenceFrame *)v5;
        }
      }
    }
    pNext->SlotFence.pObject = 0i64;
  }
}

// File Line: 863
// RVA: 0x99B540
void __fastcall Scaleform::Render::GlyphQueue::MergeEmptySlots(Scaleform::Render::GlyphQueue *this)
{
  unsigned __int64 v1; // r14
  __int64 v3; // r15
  Scaleform::Render::GlyphBand *Data; // rax
  Scaleform::Render::GlyphSlot *pNextInBand; // rdi
  Scaleform::List2<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot_Band> *p_Slots; // rbp
  Scaleform::Render::GlyphSlot *v7; // rbx
  Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *pRoot; // rcx
  unsigned __int16 v9; // dx
  Scaleform::Render::GlyphNode *v10; // rcx
  unsigned __int16 x; // ax
  Scaleform::Render::GlyphSlot *pNext; // rax

  v1 = 0i64;
  if ( this->NumUsedBands )
  {
    v3 = 0i64;
    do
    {
      Data = this->Bands.Data;
      pNextInBand = Data[v3].Slots.Root.pNextInBand;
      p_Slots = &Data[v3].Slots;
      while ( pNextInBand != (Scaleform::Render::GlyphSlot *)p_Slots )
      {
        v7 = pNextInBand->pNextInBand;
        if ( v7 == (Scaleform::Render::GlyphSlot *)p_Slots )
          break;
        if ( (__int64)v7->pRoot->pNext | (__int64)v7->pRoot->pNex2 | (__int64)pNextInBand->pRoot->pNext | (__int64)pNextInBand->pRoot->pNex2 )
        {
          pNextInBand = pNextInBand->pNextInBand;
        }
        else
        {
          Scaleform::Render::GlyphQueue::releaseSlot(this, pNextInBand);
          Scaleform::Render::GlyphQueue::releaseSlot(this, v7);
          pRoot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphNode,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphNode,75> >::NodeType *)v7->pRoot;
          v9 = pNextInBand->w + v7->w;
          pRoot->pNext = this->Glyphs.FirstEmptySlot;
          this->Glyphs.FirstEmptySlot = pRoot;
          v7->pPrev->pNext = v7->pNext;
          v7->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$DAEF6AD9C4106FD318EA5478000E87CA::pPrev = v7->pPrev;
          --this->SlotQueueSize;
          if ( (v7->TextureId & 0x8000) == 0 )
          {
            v7->pPrevActive->pNextActive = v7->pNextActive;
            v7->pNextActive->pPrevActive = v7->pPrevActive;
          }
          v7->pPrevInBand->pNextInBand = v7->pNextInBand;
          v7->pNextInBand->pPrevInBand = v7->pPrevInBand;
          v7->pPrev = (Scaleform::Render::GlyphSlot *)this->Slots.FirstEmptySlot;
          this->Slots.FirstEmptySlot = (Scaleform::ListAllocBase<Scaleform::Render::GlyphSlot,127,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphSlot,75> >::NodeType *)v7;
          v10 = pNextInBand->pRoot;
          x = pNextInBand->x;
          pNextInBand->w = v9;
          v10->mRect.x = x;
          pNextInBand->pRoot->mRect.y = pNextInBand->pBand->y;
          pNextInBand->pRoot->mRect.w = v9;
          pNextInBand->pRoot->mRect.h = pNextInBand->pBand->h;
          pNextInBand->pPrev->pNext = pNextInBand->pNext;
          pNextInBand->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$DAEF6AD9C4106FD318EA5478000E87CA::pPrev = pNextInBand->pPrev;
          pNext = this->SlotQueue.Root.pNext;
          pNextInBand->pPrev = (Scaleform::Render::GlyphSlot *)&this->SlotQueue;
          pNextInBand->pNext = pNext;
          this->SlotQueue.Root.pNext->pPrev = pNextInBand;
          this->SlotQueue.Root.pNext = pNextInBand;
        }
      }
      ++v1;
      ++v3;
    }
    while ( v1 < this->NumUsedBands );
  }
}

// File Line: 907
// RVA: 0x95EFF0
void __fastcall Scaleform::Render::GlyphQueue::CleanUpTexture(
        Scaleform::Render::GlyphQueue *this,
        unsigned int textureId)
{
  Scaleform::Render::GlyphSlot *pNext; // rbx
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *p_SlotQueue; // rsi
  Scaleform::Render::GlyphSlot *v6; // rdi
  Scaleform::Render::GlyphSlot *v7; // rax

  pNext = this->SlotQueue.Root.pNext;
  p_SlotQueue = &this->SlotQueue;
  if ( pNext != (Scaleform::Render::GlyphSlot *)&this->SlotQueue )
  {
    do
    {
      v6 = pNext->pNext;
      if ( (pNext->TextureId & 0x7FFF) == textureId )
      {
        Scaleform::Render::GlyphQueue::releaseSlot(this, pNext);
        pNext->pPrev->pNext = pNext->pNext;
        pNext->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$DAEF6AD9C4106FD318EA5478000E87CA::pPrev = pNext->pPrev;
        v7 = p_SlotQueue->Root.pNext;
        pNext->pPrev = (Scaleform::Render::GlyphSlot *)p_SlotQueue;
        pNext->pNext = v7;
        p_SlotQueue->Root.pNext->pPrev = pNext;
        p_SlotQueue->Root.pNext = pNext;
      }
      pNext = v6;
    }
    while ( v6 != (Scaleform::Render::GlyphSlot *)p_SlotQueue );
  }
  Scaleform::Render::GlyphQueue::MergeEmptySlots(this);
}

// File Line: 924
// RVA: 0x9E2D90
Scaleform::Render::GlyphNode *__fastcall Scaleform::Render::GlyphQueue::findFontInSlot(
        Scaleform::Render::GlyphNode *glyph,
        Scaleform::Render::FontCacheHandle *font)
{
  Scaleform::Render::GlyphNode *v3; // rbx
  Scaleform::Render::GlyphNode *result; // rax

  v3 = glyph;
  if ( !glyph )
    return 0i64;
  while ( v3->Param.pFont != font )
  {
    result = Scaleform::Render::GlyphQueue::findFontInSlot(v3->pNext, font);
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
void __fastcall Scaleform::Render::GlyphQueue::CleanUpFont(
        Scaleform::Render::GlyphQueue *this,
        Scaleform::Render::FontCacheHandle *font)
{
  Scaleform::Render::GlyphSlot *pNext; // rbx
  Scaleform::List<Scaleform::Render::GlyphSlot,Scaleform::Render::GlyphSlot> *p_SlotQueue; // rbp
  Scaleform::Render::GlyphNode *pRoot; // rdi
  Scaleform::Render::GlyphSlot *v7; // rsi
  Scaleform::Render::GlyphNode *FontInSlot; // rax
  Scaleform::Render::Fence *pObject; // rax
  Scaleform::Render::FenceImpl *Data; // r8
  Scaleform::Render::Fence *v11; // rcx
  Scaleform::Render::GlyphSlot *v12; // rax

  pNext = this->SlotQueue.Root.pNext;
  p_SlotQueue = &this->SlotQueue;
  if ( pNext != (Scaleform::Render::GlyphSlot *)&this->SlotQueue )
  {
    do
    {
      pRoot = pNext->pRoot;
      v7 = pNext->pNext;
      if ( pRoot )
      {
        if ( pRoot->Param.pFont != font )
        {
          FontInSlot = Scaleform::Render::GlyphQueue::findFontInSlot(pRoot->pNext, font);
          if ( !FontInSlot )
            FontInSlot = Scaleform::Render::GlyphQueue::findFontInSlot(pRoot->pNex2, font);
          pRoot = FontInSlot;
        }
        if ( pRoot )
        {
          if ( !pNext->PinCount )
          {
            pObject = pNext->SlotFence.pObject;
            if ( pObject )
            {
              if ( pObject->HasData )
              {
                Data = pObject->Data;
                if ( pObject->Data )
                {
                  if ( Data->Parent )
                    ((void (__fastcall *)(Scaleform::Render::RenderSync *, __int64, unsigned __int64))Data->RSContext->vfptr[5].__vecDelDtor)(
                      Data->RSContext,
                      1i64,
                      Data->APIHandle);
                }
              }
            }
            v11 = pNext->SlotFence.pObject;
            if ( v11 )
              Scaleform::Render::Fence::Release(v11);
            pNext->SlotFence.pObject = 0i64;
          }
          Scaleform::Render::GlyphQueue::releaseSlot(this, pNext);
          pNext->pPrev->pNext = pNext->pNext;
          pNext->pNext->Scaleform::ListNode<Scaleform::Render::GlyphSlot>::$DAEF6AD9C4106FD318EA5478000E87CA::pPrev = pNext->pPrev;
          v12 = p_SlotQueue->Root.pNext;
          pNext->pPrev = (Scaleform::Render::GlyphSlot *)p_SlotQueue;
          pNext->pNext = v12;
          p_SlotQueue->Root.pNext->pPrev = pNext;
          p_SlotQueue->Root.pNext = pNext;
        }
      }
      pNext = v7;
    }
    while ( v7 != (Scaleform::Render::GlyphSlot *)p_SlotQueue );
  }
}

