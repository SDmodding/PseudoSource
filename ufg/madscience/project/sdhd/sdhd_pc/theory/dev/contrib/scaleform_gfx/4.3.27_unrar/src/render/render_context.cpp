// File Line: 222
// RVA: 0x9DF8C0
void __fastcall Scaleform::Render::ContextImpl::Entry::destroyHelper(Scaleform::Render::ContextImpl::Entry *this)
{
  unsigned __int64 v2; // rbx
  __int64 v3; // rsi
  __int64 v4; // r12
  void *v5; // r15
  Scaleform::Render::ContextImpl::Entry *pPrev; // r14
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  _RTL_CRITICAL_SECTION *v8; // rbx

  v2 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v3 = *(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x18);
  v4 = 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56) + 40;
  v5 = *(void **)(v4 + *(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20));
  pPrev = this->pPrev;
  (*(void (__fastcall **)(void *))(*(_QWORD *)v5 + 24i64))(v5);
  v7 = this->PNode.pPrev;
  if ( v7 )
  {
    v7->pNext = this->PNode.pNext;
    this->PNode.pNext->pPrev = this->PNode.pPrev;
    this->PNode.pNext = 0i64;
    this->PNode.pPrev = 0i64;
  }
  if ( pPrev )
  {
    (*(void (__fastcall **)(void *))(*(_QWORD *)v5 + 32i64))(v5);
    if ( SLODWORD(pPrev->pNext) >= 0 )
    {
      *(_QWORD *)(v4 + *(_QWORD *)(v2 + 32)) |= 1ui64;
      this->pPrev = *(Scaleform::Render::ContextImpl::Entry **)(v3 + 80);
      this->RefCount = v3 + 80;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 8i64) = this;
      *(_QWORD *)(v3 + 80) = this;
    }
    else
    {
      if ( ((__int64)this->pNative & 1) != 0 )
      {
        v8 = (_RTL_CRITICAL_SECTION *)(*(_QWORD *)(*(_QWORD *)(v3 + 16) + 112i64) + 16i64);
        EnterCriticalSection(v8);
        Scaleform::Render::ContextImpl::Context::clearRTHandle(
          *(Scaleform::Render::ContextImpl::Context **)(v3 + 16),
          this);
        LeaveCriticalSection(v8);
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
      Scaleform::Render::ContextImpl::EntryTable::FreeEntry(
        (Scaleform::Render::ContextImpl::EntryTable *)(*(_QWORD *)(v3 + 16) + 16i64),
        (unsigned __int64)this);
    }
    pPrev->pPrev = 0i64;
    pPrev->RefCount = *(_QWORD *)(v3 + 56);
    *(_QWORD *)(v3 + 56) = pPrev;
  }
  else
  {
    *(_QWORD *)(v4 + *(_QWORD *)(v2 + 32)) |= 1ui64;
    this->pPrev = *(Scaleform::Render::ContextImpl::Entry **)(v3 + 80);
    this->RefCount = v3 + 80;
    *(_QWORD *)(*(_QWORD *)(v3 + 80) + 8i64) = this;
    *(_QWORD *)(v3 + 80) = this;
  }
}

// File Line: 270
// RVA: 0x9CA930
void __fastcall Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(Scaleform::Render::ContextImpl::Entry *this)
{
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v1; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  v1 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                + 0x18);
  pPrev = v1[4].pPrev;
  v1 += 4;
  this->PNode.pPrev = pPrev;
  this->PNode.pNext = v1;
  v1->pPrev->pNext = &this->PNode;
  v1->pPrev = &this->PNode;
}

// File Line: 276
// RVA: 0x9E7AC0
Scaleform::Render::ContextImpl::EntryData *__fastcall Scaleform::Render::ContextImpl::Entry::getWritableData(
        Scaleform::Render::ContextImpl::Entry *this,
        unsigned int changeBits)
{
  __int64 v4; // rdi
  Scaleform::Render::ContextImpl::Snapshot *v5; // rbx

  v4 = *(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
     + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56);
  if ( this->pPrev )
  {
    LODWORD(this->pPrev->pNext) |= changeBits;
  }
  else
  {
    v5 = *(Scaleform::Render::ContextImpl::Snapshot **)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x18);
    *(_QWORD *)(v4 + 40) = (*(__int64 (__fastcall **)(_QWORD, Scaleform::Render::LinearHeap *))(**(_QWORD **)(v4 + 40)
                                                                                              + 8i64))(
                             *(_QWORD *)(v4 + 40),
                             &v5->Heaps.Root.pNext->ChangeHeap);
    this->pPrev = (Scaleform::Render::ContextImpl::Entry *)Scaleform::Render::ContextImpl::Snapshot::AddChangeItem(
                                                             v5,
                                                             this,
                                                             changeBits);
  }
  return *(Scaleform::Render::ContextImpl::EntryData **)(v4 + 40);
}

// File Line: 306
// RVA: 0x949F60
void __fastcall Scaleform::Render::ContextImpl::EntryData::~EntryData(Scaleform::Render::ContextImpl::EntryData *this)
{
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::EntryData::`vftable;
}

// File Line: 312
// RVA: 0x954100
void __fastcall Scaleform::Render::ContextImpl::EntryPage::AddEntriesToList(
        Scaleform::Render::ContextImpl::EntryPage *this,
        Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *plist)
{
  $CF9B47D13B4677C524D36BBF7F22A366 *v2; // r9
  __int64 v3; // r10
  Scaleform::Render::ContextImpl::Entry *pPrev; // rax
  Scaleform::Render::ContextImpl::Entry *v5; // rcx

  v2 = &this->Entries[1].8;
  v3 = 12i64;
  do
  {
    pPrev = plist->Root.pPrev;
    v2[-7].RefCount = (unsigned __int64)plist;
    v2[-8].RefCount = (unsigned __int64)pPrev;
    plist->Root.pPrev->RefCount = (unsigned __int64)&v2[-8];
    plist->Root.pPrev = (Scaleform::Render::ContextImpl::Entry *)&v2[-8];
    v2[-1].RefCount = (unsigned __int64)&v2[-8];
    v2->RefCount = (unsigned __int64)plist;
    plist->Root.pPrev->RefCount = (unsigned __int64)&v2[-1];
    plist->Root.pPrev = (Scaleform::Render::ContextImpl::Entry *)&v2[-1];
    v2[6].RefCount = (unsigned __int64)&v2[-1];
    v2[7].RefCount = (unsigned __int64)plist;
    plist->Root.pPrev->RefCount = (unsigned __int64)&v2[6];
    plist->Root.pPrev = (Scaleform::Render::ContextImpl::Entry *)&v2[6];
    v2[13].RefCount = (unsigned __int64)&v2[6];
    v2[14].RefCount = (unsigned __int64)plist;
    plist->Root.pPrev->RefCount = (unsigned __int64)&v2[13];
    plist->Root.pPrev = (Scaleform::Render::ContextImpl::Entry *)&v2[13];
    v2[20].RefCount = (unsigned __int64)&v2[13];
    v2[21].RefCount = (unsigned __int64)plist;
    v5 = (Scaleform::Render::ContextImpl::Entry *)&v2[27];
    plist->Root.pPrev->RefCount = (unsigned __int64)&v2[20];
    plist->Root.pPrev = (Scaleform::Render::ContextImpl::Entry *)&v2[20];
    v2[27].RefCount = (unsigned __int64)&v2[20];
    v2[28].RefCount = (unsigned __int64)plist;
    v2 += 42;
    plist->Root.pPrev->RefCount = (unsigned __int64)v5;
    plist->Root.pPrev = v5;
    --v3;
  }
  while ( v3 );
}

// File Line: 319
// RVA: 0x9A9A60
void __fastcall Scaleform::Render::ContextImpl::EntryPage::RemoveEntriesFromList(
        Scaleform::Render::ContextImpl::EntryPage *this,
        Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *plist)
{
  $CF9B47D13B4677C524D36BBF7F22A366 *v2; // rax
  __int64 v3; // r8
  Scaleform::Render::ContextImpl::Entry *pNext; // rdx
  Scaleform::Render::ContextImpl::Entry *v5; // rcx

  v2 = &this->Entries[1].8;
  v3 = 12i64;
  do
  {
    pNext = v2[-8].pNext;
    v5 = v2[-7].pNext;
    v2 += 42;
    pNext->RefCount = (unsigned __int64)v5;
    v2[-49].pNext->pPrev = v2[-50].pNext;
    *($CF9B47D13B4677C524D36BBF7F22A366 *)(v2[-43].RefCount + 8) = v2[-42];
    v2[-42].pNext->pPrev = v2[-43].pNext;
    *($CF9B47D13B4677C524D36BBF7F22A366 *)(v2[-36].RefCount + 8) = v2[-35];
    v2[-35].pNext->pPrev = v2[-36].pNext;
    *($CF9B47D13B4677C524D36BBF7F22A366 *)(v2[-29].RefCount + 8) = v2[-28];
    v2[-28].pNext->pPrev = v2[-29].pNext;
    *($CF9B47D13B4677C524D36BBF7F22A366 *)(v2[-22].RefCount + 8) = v2[-21];
    v2[-21].pNext->pPrev = v2[-22].pNext;
    *($CF9B47D13B4677C524D36BBF7F22A366 *)(v2[-15].RefCount + 8) = v2[-14];
    v2[-14].pNext->pPrev = v2[-15].pNext;
    --v3;
  }
  while ( v3 );
}

// File Line: 333
// RVA: 0x957BF0
char __fastcall Scaleform::Render::ContextImpl::EntryTable::AllocEntryPage(
        Scaleform::Render::ContextImpl::EntryTable *this)
{
  Scaleform::Render::ContextImpl::EntryPage *v2; // rax
  Scaleform::Render::ContextImpl::EntryPage *v3; // rbx
  Scaleform::Render::ContextImpl::SnapshotPage *v4; // rax
  Scaleform::Render::ContextImpl::Snapshot *pActiveSnapshot; // rax

  v2 = (Scaleform::Render::ContextImpl::EntryPage *)this->pHeap->vfptr->Alloc(this->pHeap, 4088i64, 4096i64, 0i64);
  v3 = v2;
  if ( !v2 )
    return 0;
  memset(v2, 0, sizeof(Scaleform::Render::ContextImpl::EntryPage));
  v4 = (Scaleform::Render::ContextImpl::SnapshotPage *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64, __int64))this->pHeap->vfptr->Alloc)(
                                                         this->pHeap,
                                                         616i64,
                                                         16i64);
  if ( v4 )
  {
    v4->pPrev = 0i64;
    v4->pNext = 0i64;
    v4->pEntryPage = v3;
    v4->pOlderSnapshotPage = 0i64;
    v4->pNewerSnapshotPage = 0i64;
  }
  else
  {
    v4 = 0i64;
  }
  v3->pSnapshotPage = v4;
  if ( !v4 )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
    return 0;
  }
  v3->pDisplaySnapshotPage = 0i64;
  pActiveSnapshot = this->pActiveSnapshot;
  v3->UseCount = 0;
  v3->pSnapshot = pActiveSnapshot;
  Scaleform::Render::ContextImpl::EntryPage::AddEntriesToList(v3, &this->FreeNodes);
  v3->pPrev = this->EntryPages.Root.pPrev;
  v3->pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)&this->EntryPages;
  this->EntryPages.Root.pPrev->pNext = v3;
  this->EntryPages.Root.pPrev = v3;
  return 1;
}

// File Line: 359
// RVA: 0x97E320
void __fastcall Scaleform::Render::ContextImpl::EntryTable::FreeEntryPage(
        Scaleform::Render::ContextImpl::EntryTable *this,
        Scaleform::Render::ContextImpl::EntryPage *ppage)
{
  Scaleform::Lock *p_LockObject; // rbx
  Scaleform::Render::ContextImpl::SnapshotPage *pSnapshotPage; // rax
  Scaleform::Render::ContextImpl::SnapshotPage *i; // rcx
  Scaleform::Render::ContextImpl::SnapshotPage *v7; // rdx
  Scaleform::Render::ContextImpl::SnapshotPage *v8; // rdx
  Scaleform::Render::ContextImpl::SnapshotPage *pNewerSnapshotPage; // rcx
  Scaleform::Render::ContextImpl::SnapshotPage *pOlderSnapshotPage; // rcx

  p_LockObject = &this->pContext->pCaptureLock.pObject->LockObject;
  EnterCriticalSection(&p_LockObject->cs);
  ppage->pPrev->pNext = ppage->pNext;
  ppage->pNext->Scaleform::Render::ContextImpl::EntryPageBase::Scaleform::ListNode<Scaleform::Render::ContextImpl::EntryPageBase>::$606ED2F34517D6E9EB7A7D9E5B18CEE7::pPrev = ppage->pPrev;
  ppage->pPrev = (Scaleform::Render::ContextImpl::EntryPageBase *)-1i64;
  ppage->pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)-1i64;
  Scaleform::Render::ContextImpl::EntryPage::RemoveEntriesFromList(ppage, &this->FreeNodes);
  pSnapshotPage = ppage->pSnapshotPage;
  for ( i = pSnapshotPage->pNewerSnapshotPage; i; i = i->pNewerSnapshotPage )
    pSnapshotPage = i;
  do
  {
    pSnapshotPage->pEntryPage = 0i64;
    pSnapshotPage = pSnapshotPage->pOlderSnapshotPage;
  }
  while ( pSnapshotPage );
  v7 = ppage->pSnapshotPage;
  if ( v7->pNext )
  {
    v7->pPrev->pNext = v7->pNext;
    v7->pNext->Scaleform::ListNode<Scaleform::Render::ContextImpl::SnapshotPage>::$39C9E40D767711E6C2078C679D210B52::pPrev = v7->pPrev;
    v7->pPrev = (Scaleform::Render::ContextImpl::SnapshotPage *)-1i64;
    v7->pNext = (Scaleform::Render::ContextImpl::SnapshotPage *)-1i64;
  }
  v8 = ppage->pSnapshotPage;
  pNewerSnapshotPage = v8->pNewerSnapshotPage;
  if ( pNewerSnapshotPage )
    pNewerSnapshotPage->pOlderSnapshotPage = v8->pOlderSnapshotPage;
  pOlderSnapshotPage = v8->pOlderSnapshotPage;
  if ( pOlderSnapshotPage )
    pOlderSnapshotPage->pNewerSnapshotPage = v8->pNewerSnapshotPage;
  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, ppage);
  LeaveCriticalSection(&p_LockObject->cs);
}

// File Line: 385
// RVA: 0x957B50
Scaleform::Render::ContextImpl::Entry *__fastcall Scaleform::Render::ContextImpl::EntryTable::AllocEntry(
        Scaleform::Render::ContextImpl::EntryTable *this,
        Scaleform::Render::ContextImpl::EntryData *pdata)
{
  Scaleform::Render::ContextImpl::Entry *result; // rax
  Scaleform::Render::ContextImpl::Entry *pNext; // r9

  if ( (Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *)this->FreeNodes.Root.pNext == &this->FreeNodes
    && !Scaleform::Render::ContextImpl::EntryTable::AllocEntryPage(this) )
  {
    return 0i64;
  }
  pNext = this->FreeNodes.Root.pNext;
  pNext->pPrev->RefCount = pNext->RefCount;
  pNext->pNext->$CF9B47D13B4677C524D36BBF7F22A366::pPrev = pNext->pPrev;
  result = pNext;
  ++*(_DWORD *)(((unsigned __int64)pNext & 0xFFFFFFFFFFFFF000ui64) + 0x10);
  *(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNext & 0xFFFFFFFFFFFFF000ui64) + 0x20)
            + 8i64 * (unsigned int)((int)((_DWORD)pNext - ((unsigned int)pNext & 0xFFFFF000) - 56) / 56)
            + 40) = pdata;
  return result;
}

// File Line: 400
// RVA: 0x97E2B0
void __fastcall Scaleform::Render::ContextImpl::EntryTable::FreeEntry(
        Scaleform::Render::ContextImpl::EntryTable *this,
        unsigned __int64 p)
{
  Scaleform::Render::ContextImpl::Entry *pNext; // rax
  Scaleform::Render::ContextImpl::EntryPage *v3; // r8
  __int64 v4; // rax
  unsigned __int64 v5; // rdx

  pNext = this->FreeNodes.Root.pNext;
  *(_QWORD *)p = &this->FreeNodes;
  *(_QWORD *)(p + 8) = pNext;
  this->FreeNodes.Root.pNext->pPrev = (Scaleform::Render::ContextImpl::Entry *)p;
  this->FreeNodes.Root.RefCount = p;
  v3 = (Scaleform::Render::ContextImpl::EntryPage *)(p & 0xFFFFFFFFFFFFF000ui64);
  v4 = *(_QWORD *)((p & 0xFFFFFFFFFFFFF000ui64) + 0x20);
  v5 = (__int64)((unsigned __int128)((__int64)(p - (p & 0xFFFFFFFFFFFFF000ui64) - 56) * (__int128)0x4924924924924925i64) >> 64) >> 4;
  *(_QWORD *)(v4 + 8 * ((unsigned int)v5 + (v5 >> 63)) + 40) = 0i64;
  if ( v3->UseCount-- == 1 )
    Scaleform::Render::ContextImpl::EntryTable::FreeEntryPage(this, v3);
}

// File Line: 428
// RVA: 0x99C530
void __fastcall Scaleform::Render::ContextImpl::EntryTable::NextSnapshot(
        Scaleform::Render::ContextImpl::EntryTable *this,
        Scaleform::Render::ContextImpl::Snapshot *pnewSnapshot)
{
  Scaleform::Render::ContextImpl::EntryTable *pNext; // rdi
  Scaleform::List<Scaleform::Render::ContextImpl::EntryPage,Scaleform::Render::ContextImpl::EntryPageBase> *p_EntryPages; // r15
  Scaleform::Render::ContextImpl::Entry *pPrev; // rsi
  Scaleform::Render::ContextImpl::Entry *v7; // rax
  Scaleform::Render::ContextImpl::Entry *v8; // rbx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v10; // rcx
  __int64 v11; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode v12; // xmm0

  pNext = (Scaleform::Render::ContextImpl::EntryTable *)this->EntryPages.Root.pNext;
  p_EntryPages = &this->EntryPages;
  if ( pNext == (Scaleform::Render::ContextImpl::EntryTable *)&this->EntryPages )
  {
    this->pActiveSnapshot = pnewSnapshot;
  }
  else
  {
    do
    {
      pPrev = pNext->FreeNodes.Root.pPrev;
      v7 = (Scaleform::Render::ContextImpl::Entry *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64, __int64))this->pHeap->vfptr->Alloc)(
                                                      this->pHeap,
                                                      616i64,
                                                      16i64);
      v8 = v7;
      if ( v7 )
      {
        v7->pPrev = 0i64;
        v7->RefCount = 0i64;
        v7->pNative = pPrev->pNative;
        p_PNode = &pPrev->PNode;
        v10 = &v7->PNode;
        v7->pRenderer = (Scaleform::Render::TreeCacheNode *)pPrev;
        v7->pParent = 0i64;
        if ( (((unsigned __int8)((_BYTE)v7 + 40) | (unsigned __int8)((_BYTE)pPrev + 40)) & 0xF) != 0 )
        {
          memmove(v10, p_PNode, 0x240ui64);
        }
        else
        {
          v11 = 4i64;
          do
          {
            v12 = *p_PNode;
            v10 += 8;
            p_PNode += 8;
            v10[-8] = v12;
            v10[-7] = p_PNode[-7];
            v10[-6] = p_PNode[-6];
            v10[-5] = p_PNode[-5];
            v10[-4] = p_PNode[-4];
            v10[-3] = p_PNode[-3];
            v10[-2] = p_PNode[-2];
            v10[-1] = p_PNode[-1];
            --v11;
          }
          while ( v11 );
          *v10 = *p_PNode;
          v10[1] = p_PNode[1];
          v10[2] = p_PNode[2];
          v10[3] = p_PNode[3];
        }
        pPrev->pParent = v8;
      }
      else
      {
        v8 = 0i64;
      }
      pNext->FreeNodes.Root.pPrev = v8;
      pNext->EntryPages.Root.pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)pnewSnapshot;
      pNext = (Scaleform::Render::ContextImpl::EntryTable *)pNext->pHeap;
    }
    while ( pNext != (Scaleform::Render::ContextImpl::EntryTable *)p_EntryPages );
    this->pActiveSnapshot = pnewSnapshot;
  }
}

// File Line: 509
// RVA: 0x944720
void __fastcall Scaleform::Render::ContextImpl::Snapshot::Snapshot(
        Scaleform::Render::ContextImpl::Snapshot *this,
        Scaleform::Render::ContextImpl::Context *pcontext,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *p_Heaps; // rbx
  Scaleform::Render::ContextImpl::Snapshot::HeapNode *v5; // rax
  Scaleform::Render::ContextImpl::Snapshot::HeapNode *v6; // rcx

  this->pContext = pcontext;
  this->SnapshotPages.Root.pPrev = (Scaleform::Render::ContextImpl::SnapshotPage *)&this->SnapshotPages;
  this->SnapshotPages.Root.pNext = (Scaleform::Render::ContextImpl::SnapshotPage *)&this->SnapshotPages;
  this->Changes.pPages = 0i64;
  this->Changes.pLast = 0i64;
  this->pFreeChangeNodes = 0i64;
  this->PropagateEntrys.Root.pPrev = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)&this->PropagateEntrys;
  this->PropagateEntrys.Root.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)&this->PropagateEntrys;
  this->DestroyedNodes.Root.pPrev = &this->DestroyedNodes.Root;
  this->DestroyedNodes.Root.RefCount = (unsigned __int64)&this->DestroyedNodes;
  this->ForceUpdateImagesFlag = 0;
  p_Heaps = &this->Heaps;
  this->Heaps.Root.pPrev = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)&this->Heaps;
  this->Heaps.Root.pNext = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)&this->Heaps;
  v5 = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)pheap->vfptr->Alloc(pheap, 56i64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    v5->ChangeHeap.pHeap = pheap;
    v5->ChangeHeap.Granularity = 0x2000i64;
    v5->ChangeHeap.pPagePool = 0i64;
    v5->ChangeHeap.pLastPage = 0i64;
    v5->ChangeHeap.MaxPages = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  v6->pPrev = p_Heaps->Root.pPrev;
  v6->pNext = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)p_Heaps;
  p_Heaps->Root.pPrev->pNext = v6;
  p_Heaps->Root.pPrev = v6;
}

// File Line: 515
// RVA: 0x94CBF0
void __fastcall Scaleform::Render::ContextImpl::Snapshot::~Snapshot(Scaleform::Render::ContextImpl::Snapshot *this)
{
  Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *p_Heaps; // rbp
  Scaleform::Render::ContextImpl::Snapshot::HeapNode *pNext; // rbx
  unsigned __int64 MaxPages; // rax
  Scaleform::Render::LinearHeap::PageType *v5; // rdi
  Scaleform::Render::ContextImpl::SnapshotPage *v6; // rdx
  Scaleform::Render::ContextImpl::SnapshotPage *pNewerSnapshotPage; // rcx
  Scaleform::Render::ContextImpl::SnapshotPage *pOlderSnapshotPage; // rcx

  p_Heaps = &this->Heaps;
  if ( (Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *)this->Heaps.Root.pNext != &this->Heaps )
  {
    do
    {
      pNext = this->Heaps.Root.pNext;
      pNext->pPrev->pNext = pNext->pNext;
      pNext->pNext->Scaleform::ListNode<Scaleform::Render::ContextImpl::Snapshot::HeapNode>::$02CE80A8C567200551676A2681B283D7::pPrev = pNext->pPrev;
      pNext->pPrev = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)-1i64;
      pNext->pNext = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)-1i64;
      MaxPages = pNext->ChangeHeap.MaxPages;
      if ( MaxPages )
      {
        v5 = &pNext->ChangeHeap.pPagePool[MaxPages - 1];
        do
        {
          --pNext->ChangeHeap.MaxPages;
          if ( v5->pStart )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))pNext->ChangeHeap.pHeap->vfptr->Free)(pNext->ChangeHeap.pHeap);
          --v5;
        }
        while ( pNext->ChangeHeap.MaxPages );
        --pNext->ChangeHeap.MaxPages;
        pNext->ChangeHeap.pHeap->vfptr->Free(pNext->ChangeHeap.pHeap, pNext->ChangeHeap.pPagePool);
      }
      pNext->ChangeHeap.pLastPage = 0i64;
      pNext->ChangeHeap.pPagePool = 0i64;
      pNext->ChangeHeap.MaxPages = 0i64;
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pNext);
    }
    while ( (Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *)p_Heaps->Root.pNext != p_Heaps );
  }
  while ( (Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *)this->SnapshotPages.Root.pNext != &this->SnapshotPages )
  {
    v6 = this->SnapshotPages.Root.pNext;
    v6->pPrev->pNext = v6->pNext;
    v6->pNext->Scaleform::ListNode<Scaleform::Render::ContextImpl::SnapshotPage>::$39C9E40D767711E6C2078C679D210B52::pPrev = v6->pPrev;
    v6->pPrev = (Scaleform::Render::ContextImpl::SnapshotPage *)-1i64;
    v6->pNext = (Scaleform::Render::ContextImpl::SnapshotPage *)-1i64;
    pNewerSnapshotPage = v6->pNewerSnapshotPage;
    if ( pNewerSnapshotPage )
      pNewerSnapshotPage->pOlderSnapshotPage = v6->pOlderSnapshotPage;
    pOlderSnapshotPage = v6->pOlderSnapshotPage;
    if ( pOlderSnapshotPage )
      pOlderSnapshotPage->pNewerSnapshotPage = v6->pNewerSnapshotPage;
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::~PagedItemBuffer<Scaleform::Render::VertexElement,32>(&this->Changes);
}

// File Line: 533
// RVA: 0x954010
Scaleform::Render::ContextImpl::EntryChange *__fastcall Scaleform::Render::ContextImpl::Snapshot::AddChangeItem(
        Scaleform::Render::ContextImpl::Snapshot *this,
        Scaleform::Render::ContextImpl::Entry *pentry,
        unsigned int changeBits)
{
  Scaleform::Render::ContextImpl::EntryChange *pFreeChangeNodes; // r9
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63> *p_Changes; // rbx
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *pLast; // rdx
  __int64 Count; // rcx

  pFreeChangeNodes = this->pFreeChangeNodes;
  if ( pFreeChangeNodes )
  {
    this->pFreeChangeNodes = pFreeChangeNodes->pNextFreeNode;
  }
  else
  {
    p_Changes = &this->Changes;
    Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::ensureCountAvailable(
      &this->Changes,
      1u);
    pLast = p_Changes->pLast;
    Count = pLast->Count;
    pFreeChangeNodes = &pLast->Items[Count];
    pLast->Count = Count + 1;
  }
  pFreeChangeNodes->pNode = pentry;
  pFreeChangeNodes->ChangeBits = changeBits;
  return pFreeChangeNodes;
}

// File Line: 563
// RVA: 0x99AE90
void __fastcall Scaleform::Render::ContextImpl::Snapshot::Merge(
        Scaleform::Render::ContextImpl::Snapshot *this,
        Scaleform::Render::ContextImpl::Snapshot *pold)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *pPages; // r15
  Scaleform::Render::ContextImpl::Snapshot *v3; // r9
  __int64 v5; // r8
  int v6; // esi
  int *v7; // rbx
  Scaleform::Render::ContextImpl::Entry *v8; // rbp
  __int64 v9; // rcx
  __int64 v10; // r12
  __int64 v11; // rdi
  __int64 v12; // rdx
  unsigned __int64 v13; // rdx
  __int64 v14; // rcx
  Scaleform::Render::ContextImpl::EntryChange *pFreeChangeNodes; // rdx
  unsigned int v16; // r14d
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *pLast; // rdi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v18; // rax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v19; // rax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v20; // rcx
  __int64 Count; // rax
  bool ForceUpdateImagesFlag; // al
  Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *pNext; // r8
  Scaleform::Render::ContextImpl::Entry **p_pPrev; // rax
  Scaleform::Render::ContextImpl::Entry *v25; // rcx
  Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *p_Heaps; // rax
  Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *v27; // r13
  Scaleform::Render::ContextImpl::Snapshot::HeapNode *v28; // rdx
  Scaleform::Render::ContextImpl::Snapshot::HeapNode *pPrev; // rcx

  pPages = pold->Changes.pPages;
  v3 = pold;
  if ( pPages )
  {
    v5 = 0i64;
    while ( 1 )
    {
      v6 = 0;
      if ( pPages->Count )
        break;
LABEL_23:
      pPages = pPages->pNext;
      if ( !pPages )
      {
        v3 = pold;
        goto LABEL_25;
      }
    }
    while ( 1 )
    {
      v7 = (int *)&pPages->Items[v6];
      v8 = *(Scaleform::Render::ContextImpl::Entry **)v7;
      if ( *(_QWORD *)v7 )
        break;
LABEL_22:
      if ( ++v6 >= pPages->Count )
        goto LABEL_23;
    }
    v9 = *(_QWORD *)(((unsigned __int64)v8 & 0xFFFFFFFFFFFFF000ui64) + 0x20);
    v10 = 8i64 * (unsigned int)((int)((_DWORD)v8 - ((unsigned int)v8 & 0xFFFFF000) - 56) / 56) + 40;
    v11 = *(_QWORD *)(v10 + *(_QWORD *)(v9 + 24));
    v12 = *(_QWORD *)(v9 + v10);
    if ( v12 != v11 )
    {
      if ( v7[2] >= 0 )
      {
        v13 = v12 & 0xFFFFFFFFFFFFFFFEui64;
        if ( v13 == v11 )
        {
          (*(void (__fastcall **)(__int64, unsigned __int64, _QWORD, Scaleform::Render::ContextImpl::Snapshot *))(*(_QWORD *)v11 + 16i64))(
            v11,
            (unsigned __int64)v8->pNative & 0xFFFFFFFFFFFFFFFEui64,
            0i64,
            v3);
          v5 = *(_QWORD *)(((unsigned __int64)v8 & 0xFFFFFFFFFFFFF000ui64) + 0x20);
          v13 = *(_QWORD *)(*(_QWORD *)v7 + 16i64) ^ (*(_DWORD *)(v5 + v10) ^ *(_DWORD *)(*(_QWORD *)v7 + 16i64)) & 1;
          *(_QWORD *)(v5 + v10) = v13;
        }
        (*(void (__fastcall **)(__int64, unsigned __int64, __int64, Scaleform::Render::ContextImpl::Snapshot *))(*(_QWORD *)v11 + 32i64))(
          v11,
          v13,
          v5,
          v3);
        v5 = 0i64;
      }
      v14 = **(_QWORD **)v7;
      if ( v14 && (*(_BYTE *)(v10 + *(_QWORD *)(((unsigned __int64)v8 & 0xFFFFFFFFFFFFF000ui64) + 0x20)) & 1) == 0 )
        *(_DWORD *)(v14 + 8) |= v7[2] & 0x7FFFFFFF;
      goto LABEL_22;
    }
    pFreeChangeNodes = this->pFreeChangeNodes;
    v16 = v7[2];
    if ( pFreeChangeNodes )
    {
      this->pFreeChangeNodes = pFreeChangeNodes->pNextFreeNode;
LABEL_21:
      pFreeChangeNodes->pNode = v8;
      pFreeChangeNodes->ChangeBits = v16;
      goto LABEL_22;
    }
    pLast = this->Changes.pLast;
    if ( pLast )
    {
      if ( pLast->Count + 1 <= 0x3F )
      {
LABEL_20:
        v20 = this->Changes.pLast;
        Count = v20->Count;
        pFreeChangeNodes = &v20->Items[Count];
        v20->Count = Count + 1;
        goto LABEL_21;
      }
      v19 = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, &this->Changes, 1024i64, 0i64);
      this->Changes.pLast = v19;
      pLast->pNext = v19;
      v18 = this->Changes.pLast;
    }
    else
    {
      v18 = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, &this->Changes, 1024i64, 0i64);
      this->Changes.pPages = v18;
      this->Changes.pLast = v18;
    }
    v5 = 0i64;
    v18->pNext = 0i64;
    this->Changes.pLast->Count = 0;
    goto LABEL_20;
  }
LABEL_25:
  ForceUpdateImagesFlag = v3->ForceUpdateImagesFlag;
  if ( ForceUpdateImagesFlag )
    this->ForceUpdateImagesFlag = ForceUpdateImagesFlag;
  pNext = (Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *)v3->DestroyedNodes.Root.pNext;
  p_pPrev = &v3->DestroyedNodes.Root.pPrev;
  if ( pNext != &v3->DestroyedNodes )
  {
    v25 = *p_pPrev;
    v3->DestroyedNodes.Root.RefCount = (unsigned __int64)&v3->DestroyedNodes;
    *p_pPrev = (Scaleform::Render::ContextImpl::Entry *)p_pPrev;
    v25->RefCount = this->DestroyedNodes.Root.RefCount;
    pNext->Root.pPrev = &this->DestroyedNodes.Root;
    this->DestroyedNodes.Root.pNext->pPrev = v25;
    this->DestroyedNodes.Root.RefCount = (unsigned __int64)pNext;
  }
  p_Heaps = &v3->Heaps;
  v27 = &this->Heaps;
  v28 = v3->Heaps.Root.pNext;
  if ( v28 != (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)&v3->Heaps )
  {
    pPrev = p_Heaps->Root.pPrev;
    v3->Heaps.Root.pNext = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)&v3->Heaps;
    p_Heaps->Root.pPrev = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)p_Heaps;
    pPrev->pNext = v27->Root.pNext;
    v28->pPrev = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)v27;
    v27->Root.pNext->pPrev = pPrev;
    v27->Root.pNext = v28;
  }
}

// File Line: 662
// RVA: 0x93DD50
void __fastcall Scaleform::Render::ContextImpl::RTHandle::HandleData::HandleData(
        Scaleform::Render::ContextImpl::RTHandle::HandleData *this,
        Scaleform::Render::ContextImpl::Entry *entry,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::ContextImpl::ContextLock *pObject; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,69>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ContextImpl::RTHandle::HandleData,69>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ContextImpl::RTHandle::HandleData::`vftable;
  pObject = context->pCaptureLock.pObject;
  if ( pObject )
    _InterlockedExchangeAdd(&pObject->RefCount, 1u);
  this->pContextLock.pObject = context->pCaptureLock.pObject;
  this->State = State_PreCapture;
  this->pEntry = entry;
}

// File Line: 666
// RVA: 0x94AF40
void __fastcall Scaleform::Render::ContextImpl::RTHandle::HandleData::~HandleData(
        Scaleform::Render::ContextImpl::RTHandle::HandleData *this)
{
  Scaleform::Lock *p_LockObject; // rbx
  Scaleform::Render::ContextImpl::Entry *pEntry; // rax
  Scaleform::Render::ContextImpl::ContextLock *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ContextImpl::RTHandle::HandleData::`vftable;
  p_LockObject = &this->pContextLock.pObject->LockObject;
  EnterCriticalSection(&p_LockObject->cs);
  if ( this->pContextLock.pObject->pContext )
  {
    pEntry = this->pEntry;
    if ( pEntry )
    {
      pEntry->pNative = (Scaleform::Render::ContextImpl::EntryData *)((unsigned __int64)pEntry->pNative & ~1ui64);
      this->pPrev->pNext = this->pNext;
      this->pNext->pPrev = this->pPrev;
      this->pPrev = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
      this->pNext = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
    }
  }
  LeaveCriticalSection(&p_LockObject->cs);
  pObject = this->pContextLock.pObject;
  if ( pObject && _InterlockedExchangeAdd(&pObject->RefCount, 0xFFFFFFFF) == 1 )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 677
// RVA: 0x940E60
void __fastcall Scaleform::Render::ContextImpl::RTHandle::RTHandle(
        Scaleform::Render::ContextImpl::RTHandle *this,
        Scaleform::Render::ContextImpl::Entry *entry)
{
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v4; // rbx
  Scaleform::Render::ContextImpl::Context *v5; // rbp
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v6; // rax
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v7; // rax
  Scaleform::Render::ContextImpl::RTHandle::HandleData *pObject; // rcx
  _RTL_CRITICAL_SECTION *p_cs; // rbx
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v10; // rcx

  v4 = 0i64;
  this->pData.pObject = 0i64;
  if ( entry )
  {
    v5 = *(Scaleform::Render::ContextImpl::Context **)(*(_QWORD *)(((unsigned __int64)entry & 0xFFFFFFFFFFFFF000ui64)
                                                                 + 0x18)
                                                     + 16i64);
    v6 = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                                   Scaleform::Memory::pGlobalHeap,
                                                                   56i64,
                                                                   0i64);
    if ( v6 )
    {
      Scaleform::Render::ContextImpl::RTHandle::HandleData::HandleData(v6, entry, v5);
      v4 = v7;
    }
    pObject = this->pData.pObject;
    if ( this->pData.pObject && !_InterlockedDecrement(&pObject->RefCount) )
    {
      if ( pObject )
        pObject->vfptr->__vecDelDtor(pObject, 1u);
    }
    this->pData.pObject = v4;
    p_cs = &v5->pCaptureLock.pObject->LockObject.cs;
    EnterCriticalSection(p_cs);
    entry->pNative = (Scaleform::Render::ContextImpl::EntryData *)((unsigned __int64)entry->pNative | 1);
    v10 = this->pData.pObject;
    v10->pPrev = v5->RTHandleList.Root.pPrev;
    v10->pNext = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)&v5->RenderNode.8;
    v5->RTHandleList.Root.pPrev->pNext = v10;
    v5->RTHandleList.Root.pPrev = v10;
    LeaveCriticalSection(p_cs);
  }
}

// File Line: 691
// RVA: 0x94C190
void __fastcall Scaleform::Render::ContextImpl::RTHandle::~RTHandle(Scaleform::Render::ContextImpl::RTHandle *this)
{
  Scaleform::Render::ContextImpl::RTHandle::HandleData *pObject; // rcx

  pObject = this->pData.pObject;
  if ( pObject )
  {
    if ( !_InterlockedDecrement(&pObject->RefCount) )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
  }
}

// File Line: 696
// RVA: 0x99C1C0
bool __fastcall Scaleform::Render::ContextImpl::RTHandle::NextCapture(
        Scaleform::Render::ContextImpl::RTHandle *this,
        Scaleform::Render::ContextImpl::RenderNotify *render)
{
  Scaleform::Lock *p_LockObject; // r12
  Scaleform::Render::ContextImpl::Context *pContext; // rdi
  Scaleform::Render::ContextImpl::Snapshot *v6; // rbp
  _RTL_CRITICAL_SECTION *p_cs; // rbx
  _RTL_CRITICAL_SECTION *v8; // rcx
  Scaleform::Render::ContextImpl::ContextCaptureNotify *k; // rcx
  __int64 v10; // rax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v11; // rbx
  _BOOL8 v12; // r8
  Scaleform::Render::ContextImpl::Snapshot *v13; // rdx
  Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *p_SnapshotPages; // rdx
  Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *i; // rax
  Scaleform::Render::ContextImpl::SnapshotPage *pPrev; // rcx
  Scaleform::Render::ContextImpl::Snapshot *v17; // rcx
  Scaleform::Render::ContextImpl::ContextCaptureNotify *j; // rcx
  __int64 v19; // rax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *pNext; // rbx
  bool v21; // bl
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+60h] [rbp+8h]

  if ( !this->pData.pObject )
    return 0;
  p_LockObject = &this->pData.pObject->pContextLock.pObject->LockObject;
  EnterCriticalSection(&p_LockObject->cs);
  pContext = this->pData.pObject->pContextLock.pObject->pContext;
  if ( !pContext || this->pData.pObject->State == State_Dead )
  {
LABEL_40:
    LeaveCriticalSection(&p_LockObject->cs);
    return 0;
  }
  v6 = 0i64;
  p_cs = &pContext->pCaptureLock.pObject->LockObject.cs;
  lpCriticalSection = p_cs;
  EnterCriticalSection(p_cs);
  if ( !pContext->NextCaptureCalledInFrame )
  {
    if ( !pContext->ShutdownRequested )
    {
      if ( pContext->CreateThreadId != UFG::qGetCurrentThreadID() )
        pContext->MultiThreadedUse = 1;
      if ( render )
        pContext->NextCaptureCalledInFrame = 1;
      v13 = pContext->pSnapshots[1];
      if ( v13 )
      {
        p_SnapshotPages = &v13->SnapshotPages;
        for ( i = (Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *)p_SnapshotPages->Root.pNext;
              i != p_SnapshotPages;
              i = (Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *)i->Root.pNext )
        {
          pPrev = i[1].Root.pPrev;
          if ( pPrev )
            pPrev->pData[0] = (Scaleform::Render::ContextImpl::EntryData *)i;
        }
        pContext->pSnapshots[3] = pContext->pSnapshots[2];
        v17 = pContext->pSnapshots[1];
        pContext->pSnapshots[2] = v17;
        pContext->pSnapshots[1] = 0i64;
        pContext->SnapshotFrameIds[3] = pContext->SnapshotFrameIds[2];
        pContext->SnapshotFrameIds[2] = pContext->SnapshotFrameIds[1];
        if ( render )
        {
          v6 = v17;
          LOBYTE(v12) = 1;
          render->vfptr->NewCapture(render, pContext, v12);
        }
        for ( j = pContext->CaptureNotifyList.Root.pNext; ; j = pNext )
        {
          v19 = pContext == (Scaleform::Render::ContextImpl::Context *)-120i64 ? 0i64 : (__int64)&pContext->pCaptureLock;
          if ( j == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v19 )
            break;
          pNext = j->pNext;
          j->vfptr->OnNextCapture(j, render);
        }
        pContext->DIChangesRequired = 0;
      }
      else if ( render )
      {
        render->vfptr->NewCapture(render, pContext, 0);
      }
      v8 = lpCriticalSection;
      goto LABEL_35;
    }
    Scaleform::Render::ContextImpl::Context::clearRTHandleList(pContext);
    Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(pContext);
    for ( k = pContext->CaptureNotifyList.Root.pNext; ; k = v11 )
    {
      v10 = pContext == (Scaleform::Render::ContextImpl::Context *)-120i64 ? 0i64 : (__int64)&pContext->pCaptureLock;
      if ( k == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v10 )
        break;
      v11 = k->pNext;
      k->vfptr->OnNextCapture(k, render);
    }
    pContext->DIChangesRequired = 0;
    LeaveCriticalSection(lpCriticalSection);
    this->pData.pObject->pContextLock.pObject->pContext = 0i64;
    goto LABEL_40;
  }
  v8 = p_cs;
LABEL_35:
  LeaveCriticalSection(v8);
  if ( this->pData.pObject->State == State_PreCapture )
    this->pData.pObject->State = State_Valid;
  v21 = this->pData.pObject->State == State_Valid;
  LeaveCriticalSection(&p_LockObject->cs);
  if ( v6 )
    Scaleform::Render::ContextImpl::Context::nextCapture_NotifyChanges(pContext, v6, render);
  return v21;
}

// File Line: 783
// RVA: 0x98B020
Scaleform::Render::ContextImpl::Entry *__fastcall Scaleform::Render::ContextImpl::RTHandle::GetRenderEntry(
        Scaleform::Render::ContextImpl::RTHandle *this)
{
  Scaleform::Render::ContextImpl::RTHandle::HandleData *pObject; // rax

  pObject = this->pData.pObject;
  if ( this->pData.pObject && pObject->State == State_Valid )
    return pObject->pEntry;
  else
    return 0i64;
}

// File Line: 792
// RVA: 0x94C430
void __fastcall Scaleform::Render::ContextImpl::RenderNotify::~RenderNotify(
        Scaleform::Render::ContextImpl::RenderNotify *this)
{
  this->vfptr = (Scaleform::Render::ContextImpl::RenderNotifyVtbl *)&Scaleform::Render::ContextImpl::RenderNotify::`vftable;
  Scaleform::Render::ContextImpl::RenderNotify::ReleaseAllContextData(this);
  this->ServiceCommandInstance.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 797
// RVA: 0x99C180
void __fastcall Scaleform::Render::ContextImpl::RenderNotify::NewCapture(
        Scaleform::Render::ContextImpl::RenderNotify *this,
        Scaleform::Render::ContextImpl::Context *context,
        bool hasChanges)
{
  Scaleform::Render::ContextImpl::RenderNotify::ContextNode *pPrev; // rax
  Scaleform::Render::ContextImpl::RenderNotify::ContextNode *p_RenderNode; // rdx
  Scaleform::List<Scaleform::Render::ContextImpl::RenderNotify::ContextNode,Scaleform::Render::ContextImpl::RenderNotify::ContextNode> *p_ActiveContextSet; // rcx

  if ( context->pRenderer != this )
  {
    context->pRenderer = this;
    pPrev = this->ActiveContextSet.Root.pPrev;
    p_RenderNode = &context->RenderNode;
    p_ActiveContextSet = &this->ActiveContextSet;
    p_RenderNode->pPrev = pPrev;
    p_RenderNode->pNext = (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)p_ActiveContextSet;
    p_ActiveContextSet->Root.pPrev->pNext = p_RenderNode;
    p_ActiveContextSet->Root.pPrev = p_RenderNode;
  }
}

// File Line: 809
// RVA: 0x962B00
void __fastcall Scaleform::Render::ContextImpl::RenderNotify::ContextReleased(
        Scaleform::Render::ContextImpl::RenderNotify *this,
        Scaleform::Render::ContextImpl::Context *context)
{
  context->RenderNode.pPrev->pNext = context->RenderNode.pNext;
  context->RenderNode.pNext->pPrev = context->RenderNode.pPrev;
  context->RenderNode.pPrev = (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)-1i64;
  context->RenderNode.pNext = (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)-1i64;
  context->pRenderer = 0i64;
  context->NextCaptureCalledInFrame = 0;
}

// File Line: 817
// RVA: 0x9ADEE0
void __fastcall Scaleform::Render::ContextImpl::RenderNotify::ServiceQueues(
        Scaleform::Render::ContextImpl::RenderNotify *this)
{
  Scaleform::Render::ContextImpl::RenderNotify::ContextNode *pNext; // rdi
  Scaleform::List<Scaleform::Render::ContextImpl::RenderNotify::ContextNode,Scaleform::Render::ContextImpl::RenderNotify::ContextNode> *p_ActiveContextSet; // rbp
  Scaleform::Render::ContextImpl::RenderNotify::ContextNode *v3; // rsi
  Scaleform::Render::ContextImpl::Context *pContext; // rsi
  _RTL_CRITICAL_SECTION *p_cs; // rbx

  pNext = this->ActiveContextSet.Root.pNext;
  p_ActiveContextSet = &this->ActiveContextSet;
  while ( pNext != (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)p_ActiveContextSet )
  {
    v3 = pNext;
    pNext = pNext->pNext;
    if ( v3->pContext->pShutdownEvent )
    {
      pContext = v3->pContext;
      p_cs = &pContext->pCaptureLock.pObject->LockObject.cs;
      EnterCriticalSection(p_cs);
      if ( pContext->CreateThreadId != UFG::qGetCurrentThreadID() )
        pContext->MultiThreadedUse = 1;
      Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(pContext);
      LeaveCriticalSection(p_cs);
    }
  }
}

// File Line: 831
// RVA: 0x9A7D80
void __fastcall Scaleform::Render::ContextImpl::RenderNotify::ReleaseAllContextData(
        Scaleform::Render::ContextImpl::RenderNotify *this)
{
  Scaleform::List<Scaleform::Render::ContextImpl::RenderNotify::ContextNode,Scaleform::Render::ContextImpl::RenderNotify::ContextNode> *p_ActiveContextSet; // rsi
  Scaleform::Render::ContextImpl::Context *pContext; // rdi
  _RTL_CRITICAL_SECTION *p_cs; // rbx

  p_ActiveContextSet = &this->ActiveContextSet;
  if ( (Scaleform::List<Scaleform::Render::ContextImpl::RenderNotify::ContextNode,Scaleform::Render::ContextImpl::RenderNotify::ContextNode> *)this->ActiveContextSet.Root.pNext != &this->ActiveContextSet )
  {
    do
    {
      pContext = this->ActiveContextSet.Root.pNext->pContext;
      p_cs = &pContext->pCaptureLock.pObject->LockObject.cs;
      EnterCriticalSection(p_cs);
      if ( pContext->CreateThreadId != UFG::qGetCurrentThreadID() )
        pContext->MultiThreadedUse = 1;
      Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(pContext);
      LeaveCriticalSection(p_cs);
    }
    while ( (Scaleform::List<Scaleform::Render::ContextImpl::RenderNotify::ContextNode,Scaleform::Render::ContextImpl::RenderNotify::ContextNode> *)p_ActiveContextSet->Root.pNext != p_ActiveContextSet );
  }
}

// File Line: 851
// RVA: 0x949530
void __fastcall Scaleform::Render::ContextImpl::ContextCaptureNotify::~ContextCaptureNotify(
        Scaleform::Render::ContextImpl::ContextCaptureNotify *this)
{
  this->vfptr = (Scaleform::Render::ContextImpl::ContextCaptureNotifyVtbl *)&Scaleform::Render::ContextImpl::ContextCaptureNotify::`vftable;
  if ( this->pOwnedContext )
    Scaleform::Render::ContextImpl::Context::RemoveCaptureNotify(this->pOwnedContext, this);
}

// File Line: 866
// RVA: 0x939910
void __fastcall Scaleform::Render::ContextImpl::Context::Context(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::MemoryHeap *pheap)
{
  bool v3; // zf
  Scaleform::List<Scaleform::Render::ContextImpl::ContextCaptureNotify,Scaleform::Render::ContextImpl::ContextCaptureNotify> *p_CaptureNotifyList; // rcx
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v5; // rax
  $A3CD21CDD07B2C71DC3514FD9C471131 *v6; // rcx
  Scaleform::Render::ContextImpl::ContextLock *v7; // rax
  Scaleform::Render::ContextImpl::ContextLock *v8; // rax
  Scaleform::Render::ContextImpl::ContextLock *v9; // rdi
  Scaleform::Render::ContextImpl::ContextLock *pObject; // rcx
  Scaleform::Render::ContextImpl::Snapshot *v11; // rax
  Scaleform::Render::ContextImpl::Snapshot *v12; // rax

  this->pHeap = pheap;
  this->Table.pContext = this;
  this->Table.pHeap = pheap;
  this->Table.EntryPages.Root.pPrev = (Scaleform::Render::ContextImpl::EntryPageBase *)&this->Table.EntryPages;
  this->Table.EntryPages.Root.pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)&this->Table.EntryPages;
  this->Table.FreeNodes.Root.pPrev = &this->Table.FreeNodes.Root;
  this->Table.FreeNodes.Root.RefCount = (unsigned __int64)&this->Table.FreeNodes;
  this->Table.pActiveSnapshot = 0i64;
  this->pCaptureLock.pObject = 0i64;
  v3 = &this->CaptureNotifyList == 0i64;
  p_CaptureNotifyList = &this->CaptureNotifyList;
  v5 = (Scaleform::Render::ContextImpl::ContextCaptureNotify *)&p_CaptureNotifyList[-1].Root.8;
  if ( v3 )
    v5 = 0i64;
  p_CaptureNotifyList->Root.pPrev = v5;
  p_CaptureNotifyList->Root.pNext = v5;
  this->pRenderer = 0i64;
  this->NextCaptureCalledInFrame = 0;
  this->DIChangesRequired = 0;
  this->ShutdownRequested = 0;
  this->pShutdownEvent = 0i64;
  this->RenderNode.pContext = this;
  v6 = &this->RenderNode.8;
  if ( this == (Scaleform::Render::ContextImpl::Context *)-184i64 )
    v6 = 0i64;
  this->RTHandleList.Root.pPrev = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)v6;
  this->RTHandleList.Root.pNext = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)v6;
  v7 = (Scaleform::Render::ContextImpl::ContextLock *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        64i64);
  if ( v7 )
  {
    Scaleform::Render::ContextImpl::ContextLock::ContextLock(v7, this);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  pObject = this->pCaptureLock.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->pCaptureLock.pObject = v9;
  this->CreateThreadId = UFG::qGetCurrentThreadID();
  this->MultiThreadedUse = 0;
  v11 = (Scaleform::Render::ContextImpl::Snapshot *)this->pHeap->vfptr->Alloc(this->pHeap, 160i64, 0i64);
  if ( v11 )
    Scaleform::Render::ContextImpl::Snapshot::Snapshot(v11, this, this->pHeap);
  else
    v12 = 0i64;
  this->pSnapshots[0] = v12;
  this->pSnapshots[3] = 0i64;
  this->pSnapshots[2] = 0i64;
  this->pSnapshots[1] = 0i64;
  this->FinalizedFrameId = 0i64;
  this->SnapshotFrameIds[0] = 1i64;
  this->SnapshotFrameIds[1] = 0i64;
  this->SnapshotFrameIds[2] = 0i64;
  this->SnapshotFrameIds[3] = 0i64;
  this->Table.pActiveSnapshot = this->pSnapshots[0];
  this->CaptureCalled = 0;
}

// File Line: 891
// RVA: 0x9493E0
void __fastcall Scaleform::Render::ContextImpl::Context::~Context(Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v2; // r8
  Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *p_SnapshotPages; // r8
  Scaleform::Render::ContextImpl::Context *i; // rdx
  Scaleform::Render::ContextImpl::EntryPageBase *pPrev; // rcx
  Scaleform::Ptr<Scaleform::Render::ContextImpl::ContextLock> *p_pCaptureLock; // rax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *pNext; // rsi
  Scaleform::Lock *p_LockObject; // rbx
  Scaleform::Render::ContextImpl::ContextLock *pObject; // rcx

  Scaleform::Render::ContextImpl::Context::Shutdown(this, 1);
  Scaleform::Render::ContextImpl::Context::destroySnapshot(this, this->pSnapshots[3]);
  Scaleform::Render::ContextImpl::Context::destroySnapshot(this, this->pSnapshots[2]);
  Scaleform::Render::ContextImpl::Context::destroySnapshot(this, this->pSnapshots[1]);
  v2 = this->pSnapshots[0];
  if ( v2 )
  {
    p_SnapshotPages = &v2->SnapshotPages;
    for ( i = (Scaleform::Render::ContextImpl::Context *)this->Table.EntryPages.Root.pNext;
          i != (Scaleform::Render::ContextImpl::Context *)&this->Table.EntryPages;
          i = (Scaleform::Render::ContextImpl::Context *)i->CreateThreadId )
    {
      pPrev = i->Table.EntryPages.Root.pPrev;
      pPrev->pPrev = (Scaleform::Render::ContextImpl::EntryPageBase *)p_SnapshotPages->Root.pPrev;
      pPrev->pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)p_SnapshotPages;
      p_SnapshotPages->Root.pPrev->pNext = (Scaleform::Render::ContextImpl::SnapshotPage *)pPrev;
      p_SnapshotPages->Root.pPrev = (Scaleform::Render::ContextImpl::SnapshotPage *)pPrev;
    }
    Scaleform::Render::ContextImpl::Context::destroySnapshot(this, this->pSnapshots[0]);
  }
  while ( 1 )
  {
    p_pCaptureLock = &this->pCaptureLock;
    if ( this == (Scaleform::Render::ContextImpl::Context *)-120i64 )
      p_pCaptureLock = 0i64;
    if ( (Scaleform::Ptr<Scaleform::Render::ContextImpl::ContextLock> *)this->CaptureNotifyList.Root.pNext == p_pCaptureLock )
      break;
    pNext = this->CaptureNotifyList.Root.pNext;
    p_LockObject = &this->pCaptureLock.pObject->LockObject;
    EnterCriticalSection(&p_LockObject->cs);
    if ( pNext->pOwnedContext == this )
    {
      pNext->pPrev->pNext = pNext->pNext;
      pNext->pNext->pPrev = pNext->pPrev;
      pNext->pPrev = (Scaleform::Render::ContextImpl::ContextCaptureNotify *)-1i64;
      pNext->pNext = (Scaleform::Render::ContextImpl::ContextCaptureNotify *)-1i64;
      pNext->pOwnedContext = 0i64;
    }
    LeaveCriticalSection(&p_LockObject->cs);
  }
  pObject = this->pCaptureLock.pObject;
  if ( pObject && _InterlockedExchangeAdd(&pObject->RefCount, 0xFFFFFFFF) == 1 )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
}

// File Line: 916
// RVA: 0x9DD200
Scaleform::Render::ContextImpl::Entry *__fastcall Scaleform::Render::ContextImpl::Context::createEntryHelper(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::Render::ContextImpl::EntryData *pdata)
{
  Scaleform::Render::ContextImpl::Entry *result; // rax
  Scaleform::Render::ContextImpl::Entry *v5; // rax
  Scaleform::Render::ContextImpl::Entry *v6; // rdi
  Scaleform::Render::ContextImpl::EntryChange *v7; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  if ( !pdata )
    return 0i64;
  v5 = Scaleform::Render::ContextImpl::EntryTable::AllocEntry(&this->Table, pdata);
  v6 = v5;
  if ( v5 )
  {
    v7 = Scaleform::Render::ContextImpl::Snapshot::AddChangeItem(this->pSnapshots[0], v5, 0x80000000);
    v6->pNative = pdata;
    v6->pPrev = (Scaleform::Render::ContextImpl::Entry *)v7;
    v6->RefCount = 1i64;
    v6->pRenderer = 0i64;
    v6->pParent = 0i64;
    v6->PNode.pNext = 0i64;
    v6->PNode.pPrev = 0i64;
    v8 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64)
                                                                  + 0x18);
    pPrev = v8[4].pPrev;
    v8 += 4;
    v6->PNode.pPrev = pPrev;
    v6->PNode.pNext = v8;
    v8->pPrev->pNext = &v6->PNode;
    result = v6;
    v8->pPrev = &v6->PNode;
  }
  else
  {
    pdata->vfptr->Destroy(pdata);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pdata);
    return 0i64;
  }
  return result;
}

// File Line: 940
// RVA: 0x9DFF20
void __fastcall Scaleform::Render::ContextImpl::Context::destroySnapshot(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::Render::ContextImpl::Snapshot *p)
{
  Scaleform::Render::ContextImpl::Snapshot *i; // rax
  Scaleform::Render::ContextImpl::Context *pContext; // r8
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *j; // rdi
  unsigned int k; // ebx
  Scaleform::Render::ContextImpl::Entry *pNode; // rdx
  unsigned __int64 v9; // r8
  unsigned __int64 v10; // rdx
  __int64 v11; // rcx

  if ( p )
  {
    for ( i = (Scaleform::Render::ContextImpl::Snapshot *)p->SnapshotPages.Root.pNext;
          i != (Scaleform::Render::ContextImpl::Snapshot *)&p->SnapshotPages;
          i = i->pNext )
    {
      pContext = i->pContext;
      if ( pContext )
        pContext->Table.FreeNodes.Root.pPrev = (Scaleform::Render::ContextImpl::Entry *)i;
    }
    for ( j = p->Changes.pPages; j; j = j->pNext )
    {
      for ( k = 0; k < j->Count; ++k )
      {
        pNode = j->Items[k].pNode;
        if ( pNode )
        {
          if ( (j->Items[k].ChangeBits & 0x80000000) == 0 )
          {
            v9 = (unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64;
            v10 = (__int64)((unsigned __int128)((__int64)((__int64)&pNode[-1]
                                                        - ((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64))
                                              * (__int128)0x4924924924924925i64) >> 64) >> 4;
            v11 = *(_QWORD *)(*(_QWORD *)(v9 + 48) + 8 * ((unsigned int)v10 + (v10 >> 63)) + 40);
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v11 + 32i64))(v11);
          }
        }
      }
    }
    Scaleform::Render::ContextImpl::Context::destroyNativeNodes(this, &p->DestroyedNodes);
    Scaleform::Render::ContextImpl::Snapshot::~Snapshot(p);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p);
  }
}

// File Line: 980
// RVA: 0x9DFE00
void __fastcall Scaleform::Render::ContextImpl::Context::destroyNativeNodes(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *destroyList)
{
  unsigned __int64 RefCount; // rbx
  Scaleform::Render::ContextImpl::EntryTable *p_Table; // rsi
  Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *p_FreeNodes; // rbp
  Scaleform::Render::ContextImpl::EntryPage *v6; // r8
  bool v7; // zf

  RefCount = destroyList->Root.RefCount;
  if ( (Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *)RefCount != destroyList )
  {
    p_Table = &this->Table;
    p_FreeNodes = &this->Table.FreeNodes;
    do
    {
      *(_QWORD *)(*(_QWORD *)RefCount + 8i64) = *(_QWORD *)(RefCount + 8);
      **(_QWORD **)(RefCount + 8) = *(_QWORD *)RefCount;
      (*(void (__fastcall **)(unsigned __int64))(*(_QWORD *)(*(_QWORD *)(RefCount + 16) & 0xFFFFFFFFFFFFFFFEui64) + 32i64))(*(_QWORD *)(RefCount + 16) & 0xFFFFFFFFFFFFFFFEui64);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(
        Scaleform::Memory::pGlobalHeap,
        (void *)(*(_QWORD *)(RefCount + 16) & 0xFFFFFFFFFFFFFFFEui64));
      *(_QWORD *)(RefCount + 16) = 0i64;
      *(_QWORD *)(RefCount + 8) = p_FreeNodes->Root.pNext;
      *(_QWORD *)RefCount = p_FreeNodes;
      p_FreeNodes->Root.pNext->pPrev = (Scaleform::Render::ContextImpl::Entry *)RefCount;
      p_FreeNodes->Root.RefCount = RefCount;
      v6 = (Scaleform::Render::ContextImpl::EntryPage *)(RefCount & 0xFFFFFFFFFFFFF000ui64);
      v6->pSnapshotPage->pData[(int)(RefCount - (RefCount & 0xFFFFF000) - 56) / 56] = 0i64;
      v7 = *(_DWORD *)((RefCount & 0xFFFFFFFFFFFFF000ui64) + 0x10) == 1;
      --v6->UseCount;
      if ( v7 )
        Scaleform::Render::ContextImpl::EntryTable::FreeEntryPage(p_Table, v6);
      RefCount = destroyList->Root.RefCount;
    }
    while ( (Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *)RefCount != destroyList );
  }
}

// File Line: 997
// RVA: 0x9D5EE0
void __fastcall Scaleform::Render::ContextImpl::Context::clearRTHandle(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::Render::ContextImpl::Entry *entry)
{
  Scaleform::Render::ContextImpl::RTHandle::HandleData *pNext; // rax
  Scaleform::List<Scaleform::Render::ContextImpl::RTHandle::HandleData,Scaleform::Render::ContextImpl::RTHandle::HandleData> *p_RTHandleList; // r8
  __int64 v4; // rcx

  pNext = this->RTHandleList.Root.pNext;
  p_RTHandleList = &this->RTHandleList;
  while ( 1 )
  {
    v4 = p_RTHandleList ? (__int64)&p_RTHandleList[-1] : 0i64;
    if ( pNext == (Scaleform::Render::ContextImpl::RTHandle::HandleData *)v4 )
      break;
    if ( pNext->pEntry == entry )
    {
      pNext->pPrev->pNext = pNext->pNext;
      pNext->pNext->pPrev = pNext->pPrev;
      pNext->pPrev = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
      pNext->pNext = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
      pNext->State = State_Dead;
      pNext->pEntry = 0i64;
      entry->pNative = (Scaleform::Render::ContextImpl::EntryData *)((unsigned __int64)entry->pNative & ~1ui64);
      return;
    }
    pNext = pNext->pNext;
  }
}

// File Line: 1017
// RVA: 0x9D5F50
void __fastcall Scaleform::Render::ContextImpl::Context::clearRTHandleList(
        Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::List<Scaleform::Render::ContextImpl::RTHandle::HandleData,Scaleform::Render::ContextImpl::RTHandle::HandleData> *p_RTHandleList; // r8
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v3; // rax
  Scaleform::Render::ContextImpl::RTHandle::HandleData *pNext; // rax
  Scaleform::Render::ContextImpl::Entry *pEntry; // rcx

  p_RTHandleList = &this->RTHandleList;
  while ( 1 )
  {
    v3 = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)&p_RTHandleList[-1];
    if ( !p_RTHandleList )
      v3 = 0i64;
    if ( p_RTHandleList->Root.pNext == v3 )
      break;
    pNext = this->RTHandleList.Root.pNext;
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->pPrev = pNext->pPrev;
    pNext->pPrev = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
    pNext->pNext = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
    pEntry = pNext->pEntry;
    pNext->State = State_Dead;
    if ( pEntry )
      pEntry->pNative = (Scaleform::Render::ContextImpl::EntryData *)((unsigned __int64)pEntry->pNative & ~1ui64);
    pNext->pEntry = 0i64;
  }
}

// File Line: 1031
// RVA: 0x991330
bool __fastcall Scaleform::Render::ContextImpl::Context::HasChanges(Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v1; // rdx
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *pPages; // rax
  volatile bool result; // al

  v1 = this->pSnapshots[0];
  pPages = v1->Changes.pPages;
  if ( pPages && pPages->Count )
    return 1;
  if ( (Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *)v1->DestroyedNodes.Root.pNext != &v1->DestroyedNodes )
    return 1;
  result = this->DIChangesRequired;
  if ( result )
    return 1;
  return result;
}

// File Line: 1040
// RVA: 0x95DC50
char __fastcall Scaleform::Render::ContextImpl::Context::Capture(Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Lock *p_LockObject; // rbx
  Scaleform::Render::ContextImpl::Snapshot *v4; // rdi
  Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *p_SnapshotPages; // r8
  Scaleform::Render::ContextImpl::Context *i; // rdx
  Scaleform::Render::ContextImpl::EntryPageBase *pPrev; // rcx
  Scaleform::Render::ContextImpl::Snapshot *v8; // rdx
  Scaleform::Render::ContextImpl::Snapshot *v9; // rsi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *j; // rdx
  unsigned int k; // ecx
  Scaleform::Render::ContextImpl::Entry *pNode; // r8
  Scaleform::Render::ContextImpl::Snapshot *v13; // rax
  Scaleform::Render::ContextImpl::Snapshot *v14; // rax
  Scaleform::Render::ContextImpl::Snapshot *v15; // rdi
  Scaleform::Render::ContextImpl::Snapshot *v16; // r15
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *m; // r15
  unsigned int n; // edi
  Scaleform::Render::ContextImpl::Entry *v19; // rsi
  __int64 v20; // r8
  __int64 v21; // rax
  __int64 v22; // r14
  unsigned __int64 v23; // rcx
  unsigned __int64 v24; // rax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *pNext; // rdi
  Scaleform::List<Scaleform::Render::ContextImpl::ContextCaptureNotify,Scaleform::Render::ContextImpl::ContextCaptureNotify> *p_CaptureNotifyList; // rbp
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v27; // rax

  Scaleform::Render::ContextImpl::Context::PropagateChangesUp(this);
  if ( this->ShutdownRequested )
    return 0;
  p_LockObject = &this->pCaptureLock.pObject->LockObject;
  EnterCriticalSection(&p_LockObject->cs);
  Scaleform::Render::ContextImpl::Context::handleFinalizingSnaphot(this);
  v4 = this->pSnapshots[0];
  p_SnapshotPages = &v4->SnapshotPages;
  for ( i = (Scaleform::Render::ContextImpl::Context *)this->Table.EntryPages.Root.pNext;
        i != (Scaleform::Render::ContextImpl::Context *)&this->Table.EntryPages;
        i = (Scaleform::Render::ContextImpl::Context *)i->CreateThreadId )
  {
    pPrev = i->Table.EntryPages.Root.pPrev;
    pPrev->pPrev = (Scaleform::Render::ContextImpl::EntryPageBase *)p_SnapshotPages->Root.pPrev;
    pPrev->pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)p_SnapshotPages;
    p_SnapshotPages->Root.pPrev->pNext = (Scaleform::Render::ContextImpl::SnapshotPage *)pPrev;
    p_SnapshotPages->Root.pPrev = (Scaleform::Render::ContextImpl::SnapshotPage *)pPrev;
  }
  v8 = this->pSnapshots[1];
  if ( v8 )
  {
    Scaleform::Render::ContextImpl::Snapshot::Merge(v4, v8);
    v9 = this->pSnapshots[1];
    if ( v9 )
    {
      Scaleform::Render::ContextImpl::Snapshot::~Snapshot(this->pSnapshots[1]);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9);
    }
  }
  this->pSnapshots[1] = v4;
  this->SnapshotFrameIds[1] = this->SnapshotFrameIds[0];
  for ( j = v4->Changes.pPages; j; j = j->pNext )
  {
    for ( k = 0; k < j->Count; ++k )
    {
      pNode = j->Items[k].pNode;
      if ( pNode )
        pNode->pPrev = 0i64;
    }
  }
  v13 = (Scaleform::Render::ContextImpl::Snapshot *)this->pHeap->vfptr->Alloc(this->pHeap, 160i64, 0i64);
  if ( v13 )
  {
    Scaleform::Render::ContextImpl::Snapshot::Snapshot(v13, this, this->pHeap);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  Scaleform::Render::ContextImpl::EntryTable::NextSnapshot(&this->Table, v15);
  this->pSnapshots[0] = v15;
  ++this->SnapshotFrameIds[0];
  v16 = this->pSnapshots[2];
  if ( v16 )
  {
    for ( m = v16->Changes.pPages; m; m = m->pNext )
    {
      for ( n = 0; n < m->Count; ++n )
      {
        v19 = m->Items[n].pNode;
        if ( v19 )
        {
          if ( (m->Items[n].ChangeBits & 0x80000000) == 0 )
          {
            v20 = *(_QWORD *)(((unsigned __int64)v19 & 0xFFFFFFFFFFFFF000ui64) + 0x28);
            v21 = (unsigned int)((int)((_DWORD)v19 - ((unsigned int)v19 & 0xFFFFF000) - 56) / 56);
            v22 = *(_QWORD *)(v20 + 32) + 8 * v21;
            v23 = *(_QWORD *)(v22 + 40) & 0xFFFFFFFFFFFFFFFEui64;
            if ( *(_QWORD *)(v20 + 8 * v21 + 40) == v23 )
            {
              (*(void (__fastcall **)(unsigned __int64, unsigned __int64))(*(_QWORD *)v23 + 16i64))(
                v23,
                (unsigned __int64)v19->pNative & 0xFFFFFFFFFFFFFFFEui64);
              v24 = (unsigned __int64)v19->pNative & 0xFFFFFFFFFFFFFFFEui64;
              *(_QWORD *)(v22 + 40) &= 1ui64;
              *(_QWORD *)(v22 + 40) |= v24;
            }
          }
        }
      }
    }
  }
  this->CaptureCalled = 1;
  pNext = this->CaptureNotifyList.Root.pNext;
  p_CaptureNotifyList = &this->CaptureNotifyList;
  while ( 1 )
  {
    v27 = (Scaleform::Render::ContextImpl::ContextCaptureNotify *)&p_CaptureNotifyList[-1].Root.8;
    if ( !p_CaptureNotifyList )
      v27 = 0i64;
    if ( pNext == v27 )
      break;
    pNext->vfptr->OnCapture(pNext);
    pNext = pNext->pNext;
  }
  LeaveCriticalSection(&p_LockObject->cs);
  return 1;
}

// File Line: 1159
// RVA: 0x9E7CD0
void __fastcall Scaleform::Render::ContextImpl::Context::handleFinalizingSnaphot(
        Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v1; // rsi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *i; // rdi
  unsigned int j; // ebx
  Scaleform::Render::ContextImpl::Entry *pNode; // r9
  __int64 v6; // r10
  __int64 v7; // rcx
  __int64 v8; // rax
  __int64 v9; // rdx
  unsigned __int64 v10; // rax

  v1 = this->pSnapshots[3];
  if ( v1 )
  {
    for ( i = v1->Changes.pPages; i; i = i->pNext )
    {
      for ( j = 0; j < i->Count; ++j )
      {
        pNode = i->Items[j].pNode;
        if ( pNode && (i->Items[j].ChangeBits & 0x80000000) == 0 )
        {
          v6 = *(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x20);
          v7 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28) + 24i64);
          v8 = (unsigned int)((int)((_DWORD)pNode - ((unsigned int)pNode & 0xFFFFF000) - 56) / 56);
          v9 = 8 * v8 + 40;
          if ( *(_QWORD *)(v9 + v7) == (*(_QWORD *)(v6 + 8 * v8 + 40) & 0xFFFFFFFFFFFFFFFEui64) )
            *(_QWORD *)(v9 + v6) = (__int64)pNode->pNative ^ (*(_DWORD *)(v9 + v6) ^ LODWORD(pNode->pNative)) & 1;
          (*(void (__fastcall **)(_QWORD))(**(_QWORD **)(v9 + v7) + 32i64))(*(_QWORD *)(v9 + v7));
        }
      }
    }
    Scaleform::Render::ContextImpl::Context::destroyNativeNodes(this, &v1->DestroyedNodes);
    Scaleform::Render::ContextImpl::Snapshot::~Snapshot(v1);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1);
    v10 = this->SnapshotFrameIds[3];
    this->pSnapshots[3] = 0i64;
    this->FinalizedFrameId = v10;
  }
}

// File Line: 1209
// RVA: 0x9B6030
void __fastcall Scaleform::Render::ContextImpl::Context::Shutdown(
        Scaleform::Render::ContextImpl::Context *this,
        bool waitFlag)
{
  Scaleform::Render::ContextImpl::ContextCaptureNotify *i; // rcx
  Scaleform::Ptr<Scaleform::Render::ContextImpl::ContextLock> *p_pCaptureLock; // rax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *pNext; // rbx
  char v7; // di
  Scaleform::Lock *p_LockObject; // rbx
  $A3CD21CDD07B2C71DC3514FD9C471131 *v9; // rax
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v10; // rax
  Scaleform::Render::ContextImpl::Entry *pEntry; // rcx
  Scaleform::Lock *v12; // rbx
  Scaleform::Render::ContextImpl::RenderNotify *pRenderer; // rdx
  Scaleform::Render::ThreadCommandQueue *pRTCommandQueue; // rcx
  volatile signed __int32 *v15; // rbx
  void **v16; // [rsp+30h] [rbp-39h] BYREF
  int v17; // [rsp+38h] [rbp-31h]
  volatile signed __int32 *v18; // [rsp+40h] [rbp-29h]
  void **v19; // [rsp+48h] [rbp-21h]
  char v20; // [rsp+50h] [rbp-19h]
  char v21; // [rsp+51h] [rbp-18h]
  Scaleform::Mutex pmutex; // [rsp+58h] [rbp-11h] BYREF
  Scaleform::WaitCondition v23; // [rsp+80h] [rbp+17h] BYREF

  for ( i = this->CaptureNotifyList.Root.pNext; ; i = pNext )
  {
    p_pCaptureLock = &this->pCaptureLock;
    if ( this == (Scaleform::Render::ContextImpl::Context *)-120i64 )
      p_pCaptureLock = 0i64;
    if ( i == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)p_pCaptureLock )
      break;
    pNext = i->pNext;
    i->vfptr->OnShutdown(i, waitFlag);
  }
  this->DIChangesRequired = 0;
  while ( 1 )
  {
    v7 = 0;
    p_LockObject = &this->pCaptureLock.pObject->LockObject;
    EnterCriticalSection(&p_LockObject->cs);
    Scaleform::Render::ContextImpl::Context::handleFinalizingSnaphot(this);
    this->ShutdownRequested = 1;
    if ( !waitFlag )
      goto LABEL_19;
    if ( this->pRenderer )
    {
      if ( this->MultiThreadedUse )
      {
        v7 = 1;
        goto LABEL_19;
      }
      Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(this);
    }
    while ( 1 )
    {
      v9 = &this->RenderNode.8;
      if ( this == (Scaleform::Render::ContextImpl::Context *)-184i64 )
        v9 = 0i64;
      if ( ($A3CD21CDD07B2C71DC3514FD9C471131 *)this->RTHandleList.Root.pNext == v9 )
        break;
      v10 = this->RTHandleList.Root.pNext;
      v10->pPrev->pNext = v10->pNext;
      v10->pNext->pPrev = v10->pPrev;
      v10->pPrev = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
      v10->pNext = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
      v10->State = State_Dead;
      pEntry = v10->pEntry;
      if ( pEntry )
        pEntry->pNative = (Scaleform::Render::ContextImpl::EntryData *)((unsigned __int64)pEntry->pNative & ~1ui64);
      v10->pEntry = 0i64;
    }
    this->pCaptureLock.pObject->pContext = 0i64;
LABEL_19:
    LeaveCriticalSection(&p_LockObject->cs);
    if ( !v7 )
      break;
    v17 = 1;
    v18 = 0i64;
    v16 = &Scaleform::Event::`vftable{for `Scaleform::Waitable};
    v19 = &Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
    Scaleform::Mutex::Mutex(&pmutex, 1, 0);
    Scaleform::WaitCondition::WaitCondition(&v23);
    v20 = 0;
    v21 = 0;
    v12 = &this->pCaptureLock.pObject->LockObject;
    EnterCriticalSection(&v12->cs);
    if ( this->pRenderer )
    {
      this->pShutdownEvent = (Scaleform::Event *volatile)&v16;
      pRenderer = this->pRenderer;
      pRTCommandQueue = pRenderer->pRTCommandQueue;
      if ( pRTCommandQueue )
        pRTCommandQueue->vfptr->PushThreadCommand(pRTCommandQueue, &pRenderer->ServiceCommandInstance);
    }
    else
    {
      v7 = 0;
    }
    LeaveCriticalSection(&v12->cs);
    if ( v7 )
    {
      Scaleform::Mutex::DoLock(&pmutex);
      while ( !v20 )
        Scaleform::WaitCondition::Wait(&v23, &pmutex, 0xFFFFFFFF);
      if ( v21 )
      {
        v21 = 0;
        v20 = 0;
      }
      Scaleform::Mutex::Unlock(&pmutex);
    }
    v16 = &Scaleform::Event::`vftable{for `Scaleform::Waitable};
    v19 = &Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
    Scaleform::WaitCondition::~WaitCondition(&v23);
    Scaleform::Mutex::~Mutex(&pmutex);
    v19 = &Scaleform::AcquireInterface::`vftable;
    v16 = &Scaleform::Waitable::`vftable;
    v15 = v18;
    if ( v18 && !_InterlockedDecrement(v18) && v15 )
    {
      DeleteCriticalSection((LPCRITICAL_SECTION)(v15 + 8));
      if ( *((_QWORD *)v15 + 1) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v15);
    }
    v16 = &Scaleform::RefCountImplCore::`vftable;
  }
}

// File Line: 1280
// RVA: 0x997D10
_BOOL8 __fastcall Scaleform::Render::ContextImpl::Context::IsShutdownComplete(
        Scaleform::Render::ContextImpl::Context *this)
{
  bool v2; // bl
  Scaleform::Lock *lpCriticalSection; // [rsp+40h] [rbp+8h]

  lpCriticalSection = &this->pCaptureLock.pObject->LockObject;
  EnterCriticalSection(&lpCriticalSection->cs);
  v2 = this->ShutdownRequested && !this->pRenderer;
  LeaveCriticalSection(&lpCriticalSection->cs);
  return v2;
}

// File Line: 1289
// RVA: 0x9EA290
__int64 __fastcall Scaleform::Render::ContextImpl::Context::nextCapture_LockScope(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::Render::ContextImpl::Snapshot **updateSnapshot,
        Scaleform::Render::ContextImpl::RenderNotify *pnotify,
        Scaleform::Render::ContextImpl::Context::CaptureMode mode)
{
  Scaleform::Render::ContextImpl::ContextCaptureNotify *k; // rcx
  Scaleform::Ptr<Scaleform::Render::ContextImpl::ContextLock> *v9; // rax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v10; // rbx
  unsigned __int8 v11; // bl
  _BOOL8 v12; // r8
  Scaleform::Render::ContextImpl::Snapshot *v13; // rdx
  Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *p_SnapshotPages; // rdx
  Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *i; // rax
  Scaleform::Render::ContextImpl::SnapshotPage *pPrev; // rcx
  Scaleform::Render::ContextImpl::Snapshot *v17; // rcx
  Scaleform::Render::ContextImpl::ContextCaptureNotify *j; // rcx
  Scaleform::Ptr<Scaleform::Render::ContextImpl::ContextLock> *v19; // rax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *pNext; // rbx
  Scaleform::Lock *lpCriticalSection; // [rsp+40h] [rbp+8h]

  lpCriticalSection = &this->pCaptureLock.pObject->LockObject;
  EnterCriticalSection(&lpCriticalSection->cs);
  if ( mode == Capture_OnceAFrame && this->NextCaptureCalledInFrame )
  {
LABEL_32:
    v11 = 1;
    goto LABEL_33;
  }
  if ( !this->ShutdownRequested )
  {
    if ( this->CreateThreadId != UFG::qGetCurrentThreadID() )
      this->MultiThreadedUse = 1;
    if ( pnotify && mode == Capture_OnceAFrame )
      this->NextCaptureCalledInFrame = 1;
    v13 = this->pSnapshots[1];
    if ( v13 )
    {
      p_SnapshotPages = &v13->SnapshotPages;
      for ( i = (Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *)p_SnapshotPages->Root.pNext;
            i != p_SnapshotPages;
            i = (Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *)i->Root.pNext )
      {
        pPrev = i[1].Root.pPrev;
        if ( pPrev )
          pPrev->pData[0] = (Scaleform::Render::ContextImpl::EntryData *)i;
      }
      this->pSnapshots[3] = this->pSnapshots[2];
      v17 = this->pSnapshots[1];
      this->pSnapshots[2] = v17;
      this->pSnapshots[1] = 0i64;
      this->SnapshotFrameIds[3] = this->SnapshotFrameIds[2];
      this->SnapshotFrameIds[2] = this->SnapshotFrameIds[1];
      if ( pnotify )
      {
        *updateSnapshot = v17;
        LOBYTE(v12) = 1;
        pnotify->vfptr->NewCapture(pnotify, this, v12);
      }
      for ( j = this->CaptureNotifyList.Root.pNext; ; j = pNext )
      {
        v19 = this == (Scaleform::Render::ContextImpl::Context *)-120i64 ? 0i64 : &this->pCaptureLock;
        if ( j == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v19 )
          break;
        pNext = j->pNext;
        j->vfptr->OnNextCapture(j, pnotify);
      }
      this->DIChangesRequired = 0;
    }
    else if ( pnotify )
    {
      pnotify->vfptr->NewCapture(pnotify, this, 0);
    }
    goto LABEL_32;
  }
  Scaleform::Render::ContextImpl::Context::clearRTHandleList(this);
  Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(this);
  for ( k = this->CaptureNotifyList.Root.pNext; ; k = v10 )
  {
    v9 = this == (Scaleform::Render::ContextImpl::Context *)-120i64 ? 0i64 : &this->pCaptureLock;
    if ( k == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v9 )
      break;
    v10 = k->pNext;
    k->vfptr->OnNextCapture(k, pnotify);
  }
  this->DIChangesRequired = 0;
  v11 = 0;
LABEL_33:
  LeaveCriticalSection(&lpCriticalSection->cs);
  return v11;
}

// File Line: 1389
// RVA: 0x9EA470
void __fastcall Scaleform::Render::ContextImpl::Context::nextCapture_NotifyChanges(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::Render::ContextImpl::Snapshot *displaySnaphot,
        Scaleform::Render::ContextImpl::RenderNotify *pnotify)
{
  Scaleform::Render::ContextImpl::Snapshot *pNext; // rbx
  Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *p_DestroyedNodes; // rbp
  Scaleform::Render::ContextImpl::Entry *v8; // rdi
  Scaleform::Lock *p_LockObject; // rbx
  Scaleform::Render::ContextImpl::RTHandle::HandleData *i; // rax
  $A3CD21CDD07B2C71DC3514FD9C471131 *v11; // rcx

  if ( displaySnaphot )
  {
    ((void (__fastcall *)(Scaleform::Render::ContextImpl::RenderNotify *, Scaleform::Render::ContextImpl::Context *, Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63> *, bool, __int64))pnotify->vfptr->EntryChanges)(
      pnotify,
      this,
      &displaySnaphot->Changes,
      displaySnaphot->ForceUpdateImagesFlag,
      -2i64);
    displaySnaphot->ForceUpdateImagesFlag = 0;
    pNext = (Scaleform::Render::ContextImpl::Snapshot *)displaySnaphot->DestroyedNodes.Root.pNext;
    p_DestroyedNodes = &displaySnaphot->DestroyedNodes;
    if ( pNext != (Scaleform::Render::ContextImpl::Snapshot *)&displaySnaphot->DestroyedNodes )
    {
      do
      {
        pnotify->vfptr->EntryDestroy(pnotify, (Scaleform::Render::ContextImpl::Entry *)pNext);
        pNext->SnapshotPages.Root.pPrev = (Scaleform::Render::ContextImpl::SnapshotPage *)2989;
        pNext = pNext->pNext;
      }
      while ( pNext != (Scaleform::Render::ContextImpl::Snapshot *)p_DestroyedNodes );
      v8 = displaySnaphot->DestroyedNodes.Root.pNext;
      p_LockObject = &this->pCaptureLock.pObject->LockObject;
      EnterCriticalSection(&p_LockObject->cs);
      do
      {
        if ( ((__int64)v8->pNative & 1) != 0 )
        {
          for ( i = this->RTHandleList.Root.pNext; ; i = i->pNext )
          {
            v11 = &this->RenderNode.8;
            if ( this == (Scaleform::Render::ContextImpl::Context *)-184i64 )
              v11 = 0i64;
            if ( i == (Scaleform::Render::ContextImpl::RTHandle::HandleData *)v11 )
              break;
            if ( i->pEntry == v8 )
            {
              i->pPrev->pNext = i->pNext;
              i->pNext->pPrev = i->pPrev;
              i->pPrev = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
              i->pNext = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
              i->State = State_Dead;
              i->pEntry = 0i64;
              v8->pNative = (Scaleform::Render::ContextImpl::EntryData *)((unsigned __int64)v8->pNative & ~1ui64);
              break;
            }
          }
        }
        v8 = v8->pNext;
      }
      while ( v8 != (Scaleform::Render::ContextImpl::Entry *)p_DestroyedNodes );
      LeaveCriticalSection(&p_LockObject->cs);
    }
  }
}

// File Line: 1423
// RVA: 0x97AEC0
void __fastcall Scaleform::Render::ContextImpl::Context::ForceUpdateImages(
        Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v1; // rax

  v1 = this->pSnapshots[0];
  if ( v1 )
    v1->ForceUpdateImagesFlag = 1;
}

// File Line: 1439
// RVA: 0x953FA0
void __fastcall Scaleform::Render::ContextImpl::Context::AddCaptureNotify(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::Render::ContextImpl::ContextCaptureNotify *notify)
{
  Scaleform::Lock *p_LockObject; // rbx

  p_LockObject = &this->pCaptureLock.pObject->LockObject;
  EnterCriticalSection(&p_LockObject->cs);
  notify->pOwnedContext = this;
  notify->pPrev = this->CaptureNotifyList.Root.pPrev;
  notify->pNext = (Scaleform::Render::ContextImpl::ContextCaptureNotify *)&this->pCaptureLock;
  this->CaptureNotifyList.Root.pPrev->pNext = notify;
  this->CaptureNotifyList.Root.pPrev = notify;
  LeaveCriticalSection(&p_LockObject->cs);
}

// File Line: 1447
// RVA: 0x9A96F0
void __fastcall Scaleform::Render::ContextImpl::Context::RemoveCaptureNotify(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::Render::ContextImpl::ContextCaptureNotify *notify)
{
  Scaleform::Lock *p_LockObject; // rbx

  p_LockObject = &this->pCaptureLock.pObject->LockObject;
  EnterCriticalSection(&p_LockObject->cs);
  if ( notify->pOwnedContext == this )
  {
    notify->pPrev->pNext = notify->pNext;
    notify->pNext->pPrev = notify->pPrev;
    notify->pPrev = (Scaleform::Render::ContextImpl::ContextCaptureNotify *)-1i64;
    notify->pNext = (Scaleform::Render::ContextImpl::ContextCaptureNotify *)-1i64;
    notify->pOwnedContext = 0i64;
  }
  LeaveCriticalSection(&p_LockObject->cs);
}

// File Line: 1477
// RVA: 0x9F2500
void __fastcall Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(
        Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v2; // rax
  Scaleform::Render::ContextImpl::SnapshotPage *pNext; // rsi
  Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *i; // r14
  Scaleform::Render::ContextImpl::EntryPage *pEntryPage; // rbx
  Scaleform::Render::TreeCacheNode **p_pRenderer; // rbx
  __int64 v7; // rdi

  if ( this->pRenderer )
  {
    v2 = this->pSnapshots[2];
    if ( v2 )
    {
      pNext = v2->SnapshotPages.Root.pNext;
      for ( i = &v2->SnapshotPages; pNext != (Scaleform::Render::ContextImpl::SnapshotPage *)i; pNext = pNext->pNext )
      {
        pEntryPage = pNext->pEntryPage;
        if ( pEntryPage )
        {
          p_pRenderer = &pEntryPage->Entries[0].pRenderer;
          v7 = 72i64;
          do
          {
            if ( *p_pRenderer != (Scaleform::Render::TreeCacheNode *)2989 && *p_pRenderer )
              this->pRenderer->vfptr->EntryFlush(
                this->pRenderer,
                (Scaleform::Render::ContextImpl::Entry *)(p_pRenderer - 3));
            p_pRenderer += 7;
            --v7;
          }
          while ( v7 );
        }
      }
      this->pRenderer->vfptr->ContextReleased(this->pRenderer, this);
      if ( this->pShutdownEvent )
      {
        Scaleform::Event::SetEvent(this->pShutdownEvent);
        this->pShutdownEvent = 0i64;
      }
    }
  }
}

// File Line: 1529
// RVA: 0x9A05D0
void __fastcall Scaleform::Render::ContextImpl::Context::PropagateChangesUp(
        Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v1; // r12
  __int64 v2; // rdx
  char *v3; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pNext; // r14
  Scaleform::List<Scaleform::Render::ContextImpl::Entry::PropagateNode,Scaleform::Render::ContextImpl::Entry::PropagateNode> *p_PropagateEntrys; // r12
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v6; // r15
  unsigned int v7; // ebx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *i; // rax
  char *v9; // rax
  char *v10; // rdi
  unsigned int v11; // ecx
  unsigned int v12; // esi
  int v13; // edx
  __int64 v14; // rcx
  unsigned int v15; // eax
  __int64 v16; // rbx
  __int64 v17; // r15
  _QWORD *v18; // r14
  unsigned __int64 v19; // rdx
  __int64 v20; // rcx
  __int64 v21; // rsi
  __int64 v22; // r13
  unsigned int v23; // r12d
  char *v24; // rax
  char *v25; // rbx
  unsigned int v26; // edx
  unsigned int v27; // edi
  int v28; // ecx
  unsigned int v29; // eax
  char *Src; // [rsp+20h] [rbp-B8h]
  unsigned int v31; // [rsp+28h] [rbp-B0h]
  unsigned int v32; // [rsp+2Ch] [rbp-ACh]
  Scaleform::MemoryHeap *pHeap; // [rsp+30h] [rbp-A8h]
  char v34[216]; // [rsp+40h] [rbp-98h] BYREF
  __int64 v35; // [rsp+118h] [rbp+40h]
  unsigned int v36; // [rsp+158h] [rbp+80h]

  v35 = -2i64;
  v1 = this->pSnapshots[0];
  Src = v34;
  v31 = 0;
  v2 = 32i64;
  v32 = 32;
  pHeap = this->pHeap;
  v3 = v34;
  do
  {
    *(_QWORD *)v3 = 0i64;
    v3 += 8;
    --v2;
  }
  while ( v2 );
  pNext = v1->PropagateEntrys.Root.pNext;
  p_PropagateEntrys = &v1->PropagateEntrys;
  if ( pNext != (Scaleform::Render::ContextImpl::Entry::PropagateNode *)p_PropagateEntrys )
  {
    while ( 1 )
    {
      v6 = pNext->pNext;
      v7 = 0;
      for ( i = pNext[-1].pNext; i; i = i[2].pPrev )
        ++v7;
      if ( v7 < v32 )
        break;
      v9 = (char *)pHeap->vfptr->Alloc(pHeap, 8i64 * ((v7 + 32) & 0xFFFFFFE0), 0i64);
      v10 = v9;
      if ( v9 )
      {
        memmove(v9, Src, 8i64 * v31);
        v11 = v31;
        v12 = ((v7 + 32) & 0xFFFFFFE0) - v31;
        v13 = 0;
        if ( v12 )
        {
          while ( 1 )
          {
            *(_QWORD *)&v10[8 * v13 + 8 * v11] = 0i64;
            if ( ++v13 >= v12 )
              break;
            v11 = v31;
          }
        }
        if ( Src != v34 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        Src = v10;
        v32 = v7 + 1;
        goto LABEL_15;
      }
LABEL_18:
      pNext->pPrev = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)1;
      pNext = v6;
      if ( v6 == (Scaleform::Render::ContextImpl::Entry::PropagateNode *)p_PropagateEntrys )
        goto LABEL_19;
    }
    v10 = Src;
LABEL_15:
    v14 = 8i64 * v7;
    pNext->pNext = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)&v10[v14];
    *(_QWORD *)&Src[v14] = pNext;
    v15 = v31;
    if ( v31 < v7 + 1 )
      v15 = v7 + 1;
    v31 = v15;
    goto LABEL_18;
  }
LABEL_19:
  p_PropagateEntrys->Root.pPrev = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)p_PropagateEntrys;
  p_PropagateEntrys->Root.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)p_PropagateEntrys;
  v16 = v31 - 1;
  v36 = v31 - 1;
  if ( v31 )
  {
    while ( 1 )
    {
      v17 = *(_QWORD *)&Src[8 * v16];
      if ( v17 )
        break;
LABEL_38:
      v16 = (unsigned int)(v16 - 1);
      v36 = v16;
      if ( (_DWORD)v16 == -1 )
        goto LABEL_39;
    }
    while ( 1 )
    {
      v18 = (_QWORD *)(v17 - 40);
      v19 = (__int64)((unsigned __int128)((__int64)(v17 - 40 - ((v17 - 40) & 0xFFFFFFFFFFFFF000ui64) - 56)
                                        * (__int128)0x4924924924924925i64) >> 64) >> 4;
      v20 = *(_QWORD *)(*(_QWORD *)(((v17 - 40) & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                      + 8 * ((unsigned int)v19 + (v19 >> 63))
                      + 40);
      if ( !(*(unsigned __int8 (__fastcall **)(__int64, __int64))(*(_QWORD *)v20 + 40i64))(v20, v17 - 40) )
        goto LABEL_37;
      v21 = v18[4];
      if ( !v21 || *(_QWORD *)(v21 + 48) )
        goto LABEL_37;
      v22 = (unsigned int)(v16 - 1);
      if ( (unsigned int)v22 < v32 )
        break;
      v23 = v16;
      v24 = (char *)pHeap->vfptr->Alloc(pHeap, 8i64 * (((_DWORD)v22 + 32) & 0xFFFFFFE0), 0i64);
      v25 = v24;
      if ( v24 )
      {
        memmove(v24, Src, 8i64 * v31);
        v26 = v31;
        v27 = ((v22 + 32) & 0xFFFFFFE0) - v31;
        v28 = 0;
        if ( v27 )
        {
          while ( 1 )
          {
            *(_QWORD *)&v25[8 * v28 + 8 * v26] = 0i64;
            if ( ++v28 >= v27 )
              break;
            v26 = v31;
          }
        }
        if ( Src != v34 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        Src = v25;
        v32 = v23;
        goto LABEL_33;
      }
LABEL_36:
      LODWORD(v16) = v36;
LABEL_37:
      v17 = *(_QWORD *)(v17 + 8);
      v18[6] = 0i64;
      v18[5] = 0i64;
      if ( !v17 )
        goto LABEL_38;
    }
    v25 = Src;
LABEL_33:
    *(_QWORD *)(v21 + 48) = *(_QWORD *)&v25[8 * v22];
    *(_QWORD *)&Src[8 * v22] = v21 + 40;
    v29 = v31;
    if ( v31 < (int)v22 + 1 )
      v29 = v22 + 1;
    v31 = v29;
    goto LABEL_36;
  }
LABEL_39:
  if ( Src != v34 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

