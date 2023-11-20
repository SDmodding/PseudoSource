// File Line: 222
// RVA: 0x9DF8C0
void __fastcall Scaleform::Render::ContextImpl::Entry::destroyHelper(Scaleform::Render::ContextImpl::Entry *this)
{
  Scaleform::Render::ContextImpl::Entry *v1; // rdi
  unsigned __int64 v2; // rbx
  __int64 v3; // rsi
  unsigned __int64 v4; // r12
  void *v5; // r15
  Scaleform::Render::ContextImpl::Entry *v6; // r14
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  _RTL_CRITICAL_SECTION *v8; // rbx

  v1 = this;
  v2 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v3 = *(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x18);
  v4 = 8
     * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4)
      + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                               - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                              * (signed __int128)5270498306774157605i64) >> 64) >> 63))
     + 40;
  v5 = *(void **)(v4 + *(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20));
  v6 = this->pPrev;
  (*(void (__fastcall **)(_QWORD))(*(_QWORD *)v5 + 24i64))(*(_QWORD *)(v4
                                                                     + *(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                                 + 0x20)));
  v7 = v1->PNode.pPrev;
  if ( v7 )
  {
    v7->pNext = v1->PNode.pNext;
    v1->PNode.pNext->pPrev = v1->PNode.pPrev;
    v1->PNode.pNext = 0i64;
    v1->PNode.pPrev = 0i64;
  }
  if ( v6 )
  {
    (*(void (__fastcall **)(void *))(*(_QWORD *)v5 + 32i64))(v5);
    if ( SLODWORD(v6->pNext) >= 0 )
    {
      *(_QWORD *)(v4 + *(_QWORD *)(v2 + 32)) |= 1ui64;
      v1->pPrev = *(Scaleform::Render::ContextImpl::Entry **)(v3 + 80);
      v1->RefCount = v3 + 80;
      *(_QWORD *)(*(_QWORD *)(v3 + 80) + 8i64) = v1;
      *(_QWORD *)(v3 + 80) = v1;
    }
    else
    {
      if ( (_QWORD)v1->pNative & 1 )
      {
        v8 = (_RTL_CRITICAL_SECTION *)(*(_QWORD *)(*(_QWORD *)(v3 + 16) + 112i64) + 16i64);
        EnterCriticalSection(v8);
        Scaleform::Render::ContextImpl::Context::clearRTHandle(
          *(Scaleform::Render::ContextImpl::Context **)(v3 + 16),
          v1);
        LeaveCriticalSection(v8);
      }
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
      Scaleform::Render::ContextImpl::EntryTable::FreeEntry(
        (Scaleform::Render::ContextImpl::EntryTable *)(*(_QWORD *)(v3 + 16) + 16i64),
        v1);
    }
    v6->pPrev = 0i64;
    v6->RefCount = *(_QWORD *)(v3 + 56);
    *(_QWORD *)(v3 + 56) = v6;
  }
  else
  {
    *(_QWORD *)(v4 + *(_QWORD *)(v2 + 32)) |= 1ui64;
    v1->pPrev = *(Scaleform::Render::ContextImpl::Entry **)(v3 + 80);
    v1->RefCount = v3 + 80;
    *(_QWORD *)(*(_QWORD *)(v3 + 80) + 8i64) = v1;
    *(_QWORD *)(v3 + 80) = v1;
  }
}

// File Line: 270
// RVA: 0x9CA930
void __fastcall Scaleform::Render::ContextImpl::Entry::addToPropagateImpl(Scaleform::Render::ContextImpl::Entry *this)
{
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v1; // r8
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v2; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v3; // rax

  v1 = &this->PNode;
  v2 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                + 0x18);
  v3 = v2[4].pPrev;
  v2 += 4;
  v1->pPrev = v3;
  v1->pNext = v2;
  v2->pPrev->pNext = &this->PNode;
  v2->pPrev = &this->PNode;
}

// File Line: 276
// RVA: 0x9E7AC0
Scaleform::Render::ContextImpl::EntryData *__fastcall Scaleform::Render::ContextImpl::Entry::getWritableData(Scaleform::Render::ContextImpl::Entry *this, unsigned int changeBits)
{
  Scaleform::Render::ContextImpl::Entry *v2; // r14
  unsigned int v3; // esi
  unsigned __int64 v4; // rdi
  Scaleform::Render::ContextImpl::Snapshot *v5; // rbx

  v2 = this;
  v3 = changeBits;
  v4 = *(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
     + 8
     * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4)
      + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                               - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                              * (signed __int128)5270498306774157605i64) >> 64) >> 63));
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
    v2->pPrev = (Scaleform::Render::ContextImpl::Entry *)Scaleform::Render::ContextImpl::Snapshot::AddChangeItem(
                                                           v5,
                                                           v2,
                                                           v3);
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
void __fastcall Scaleform::Render::ContextImpl::EntryPage::AddEntriesToList(Scaleform::Render::ContextImpl::EntryPage *this, Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *plist)
{
  $CF9B47D13B4677C524D36BBF7F22A366 *v2; // r9
  signed __int64 v3; // r10
  Scaleform::Render::ContextImpl::Entry *v4; // rax
  Scaleform::Render::ContextImpl::Entry *v5; // rcx

  v2 = &this->Entries[1].8;
  v3 = 12i64;
  do
  {
    v4 = plist->Root.pPrev;
    v2[-7].RefCount = (unsigned __int64)plist;
    v2[-8].RefCount = (unsigned __int64)v4;
    plist->Root.pPrev->RefCount = (unsigned __int64)&v2[-8];
    plist->Root.pPrev = (Scaleform::Render::ContextImpl::Entry *)&v2[-8];
    v2[-1].RefCount = (unsigned __int64)&v2[-8];
    v2->pNext = &plist->Root;
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
    v5->pPrev = (Scaleform::Render::ContextImpl::Entry *)&v2[20];
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
void __fastcall Scaleform::Render::ContextImpl::EntryPage::RemoveEntriesFromList(Scaleform::Render::ContextImpl::EntryPage *this, Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *plist)
{
  $CF9B47D13B4677C524D36BBF7F22A366 *v2; // rax
  signed __int64 v3; // r8
  Scaleform::Render::ContextImpl::Entry *v4; // rdx
  Scaleform::Render::ContextImpl::Entry *v5; // rcx

  v2 = &this->Entries[1].8;
  v3 = 12i64;
  do
  {
    v4 = v2[-8].pNext;
    v5 = v2[-7].pNext;
    v2 += 42;
    v4->RefCount = (unsigned __int64)v5;
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
char __fastcall Scaleform::Render::ContextImpl::EntryTable::AllocEntryPage(Scaleform::Render::ContextImpl::EntryTable *this)
{
  Scaleform::Render::ContextImpl::EntryTable *v1; // rdi
  Scaleform::Render::ContextImpl::EntryPage *v2; // rax
  Scaleform::Render::ContextImpl::EntryPage *v3; // rbx
  Scaleform::Render::ContextImpl::SnapshotPage *v4; // rax
  Scaleform::Render::ContextImpl::Snapshot *v6; // rax

  v1 = this;
  v2 = (Scaleform::Render::ContextImpl::EntryPage *)this->pHeap->vfptr->Alloc(this->pHeap, 4088ui64, 4096ui64, 0i64);
  v3 = v2;
  if ( !v2 )
    return 0;
  memset(v2, 0, 0xFF8ui64);
  v4 = (Scaleform::Render::ContextImpl::SnapshotPage *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, signed __int64))v1->pHeap->vfptr->Alloc)(
                                                         v1->pHeap,
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
  v6 = v1->pActiveSnapshot;
  v3->UseCount = 0;
  v3->pSnapshot = v6;
  Scaleform::Render::ContextImpl::EntryPage::AddEntriesToList(v3, &v1->FreeNodes);
  v3->pPrev = v1->EntryPages.Root.pPrev;
  v3->pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)&v1->EntryPages;
  v1->EntryPages.Root.pPrev->pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)&v3->0;
  v1->EntryPages.Root.pPrev = (Scaleform::Render::ContextImpl::EntryPageBase *)&v3->0;
  return 1;
}

// File Line: 359
// RVA: 0x97E320
void __fastcall Scaleform::Render::ContextImpl::EntryTable::FreeEntryPage(Scaleform::Render::ContextImpl::EntryTable *this, Scaleform::Render::ContextImpl::EntryPage *ppage)
{
  Scaleform::Render::ContextImpl::EntryPage *v2; // rsi
  Scaleform::Render::ContextImpl::EntryTable *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx
  Scaleform::Render::ContextImpl::SnapshotPage *v5; // rax
  Scaleform::Render::ContextImpl::SnapshotPage *i; // rcx
  Scaleform::Render::ContextImpl::SnapshotPage *v7; // rdx
  Scaleform::Render::ContextImpl::SnapshotPage *v8; // rdx
  Scaleform::Render::ContextImpl::SnapshotPage *v9; // rcx
  Scaleform::Render::ContextImpl::SnapshotPage *v10; // rcx

  v2 = ppage;
  v3 = this;
  v4 = &this->pContext->pCaptureLock.pObject->LockObject.cs;
  EnterCriticalSection(v4);
  v2->pPrev->pNext = v2->pNext;
  v2->pNext->pPrev = v2->pPrev;
  v2->pPrev = (Scaleform::Render::ContextImpl::EntryPageBase *)-1i64;
  v2->pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)-1i64;
  Scaleform::Render::ContextImpl::EntryPage::RemoveEntriesFromList(v2, &v3->FreeNodes);
  v5 = v2->pSnapshotPage;
  for ( i = v5->pNewerSnapshotPage; i; i = i->pNewerSnapshotPage )
    v5 = i;
  do
  {
    v5->pEntryPage = 0i64;
    v5 = v5->pOlderSnapshotPage;
  }
  while ( v5 );
  v7 = v2->pSnapshotPage;
  if ( v7->pNext )
  {
    v7->pPrev->pNext = v7->pNext;
    v7->pNext->pPrev = v7->pPrev;
    v7->pPrev = (Scaleform::Render::ContextImpl::SnapshotPage *)-1i64;
    v7->pNext = (Scaleform::Render::ContextImpl::SnapshotPage *)-1i64;
  }
  v8 = v2->pSnapshotPage;
  v9 = v8->pNewerSnapshotPage;
  if ( v9 )
    v9->pOlderSnapshotPage = v8->pOlderSnapshotPage;
  v10 = v8->pOlderSnapshotPage;
  if ( v10 )
    v10->pNewerSnapshotPage = v8->pNewerSnapshotPage;
  ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
  LeaveCriticalSection(v4);
}

// File Line: 385
// RVA: 0x957B50
Scaleform::Render::ContextImpl::Entry *__fastcall Scaleform::Render::ContextImpl::EntryTable::AllocEntry(Scaleform::Render::ContextImpl::EntryTable *this, Scaleform::Render::ContextImpl::EntryData *pdata)
{
  Scaleform::Render::ContextImpl::EntryData *v2; // rdi
  Scaleform::Render::ContextImpl::EntryTable *v3; // rbx
  Scaleform::Render::ContextImpl::Entry *result; // rax
  Scaleform::Render::ContextImpl::Entry *v5; // r9

  v2 = pdata;
  v3 = this;
  if ( (Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *)this->FreeNodes.Root.pNext == &this->FreeNodes
    && !Scaleform::Render::ContextImpl::EntryTable::AllocEntryPage(this) )
  {
    return 0i64;
  }
  v5 = v3->FreeNodes.Root.pNext;
  v5->pPrev->RefCount = v5->RefCount;
  v5->pNext->pPrev = v5->pPrev;
  result = v5;
  ++*(_DWORD *)(((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64) + 0x10);
  *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
            + 8
            * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v5[-1]
                                                                      - ((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64))
                                                     * (signed __int128)5270498306774157605i64) >> 64) >> 63)
             + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v5[-1]
                                                                                  - ((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64))
                                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 4))
            + 40) = v2;
  return result;
}

// File Line: 400
// RVA: 0x97E2B0
void __fastcall Scaleform::Render::ContextImpl::EntryTable::FreeEntry(Scaleform::Render::ContextImpl::EntryTable *this, Scaleform::Render::ContextImpl::Entry *p)
{
  Scaleform::Render::ContextImpl::Entry *v2; // rax
  Scaleform::Render::ContextImpl::EntryPage *v3; // r8
  __int64 v4; // rax
  unsigned __int64 v5; // rdx
  bool v6; // zf

  v2 = this->FreeNodes.Root.pNext;
  p->pPrev = &this->FreeNodes.Root;
  p->RefCount = (unsigned __int64)v2;
  this->FreeNodes.Root.pNext->pPrev = p;
  this->FreeNodes.Root.RefCount = (unsigned __int64)p;
  v3 = (Scaleform::Render::ContextImpl::EntryPage *)((unsigned __int64)p & 0xFFFFFFFFFFFFF000ui64);
  v4 = *(_QWORD *)(((unsigned __int64)p & 0xFFFFFFFFFFFFF000ui64) + 0x20);
  v5 = (signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&p[-1]
                                                           - ((unsigned __int64)p & 0xFFFFFFFFFFFFF000ui64))
                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4;
  *(_QWORD *)(v4 + 8 * ((unsigned int)v5 + (v5 >> 63)) + 40) = 0i64;
  v6 = v3->UseCount-- == 1;
  if ( v6 )
    Scaleform::Render::ContextImpl::EntryTable::FreeEntryPage(this, v3);
}

// File Line: 428
// RVA: 0x99C530
void __fastcall Scaleform::Render::ContextImpl::EntryTable::NextSnapshot(Scaleform::Render::ContextImpl::EntryTable *this, Scaleform::Render::ContextImpl::Snapshot *pnewSnapshot)
{
  Scaleform::Render::ContextImpl::EntryTable *v2; // rdi
  Scaleform::List<Scaleform::Render::ContextImpl::EntryPage,Scaleform::Render::ContextImpl::EntryPageBase> *v3; // r15
  Scaleform::Render::ContextImpl::Snapshot *v4; // r14
  Scaleform::Render::ContextImpl::EntryTable *v5; // rbp
  Scaleform::Render::ContextImpl::Entry *v6; // rsi
  Scaleform::Render::ContextImpl::Entry *v7; // rax
  Scaleform::Render::ContextImpl::Entry *v8; // rbx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v10; // rcx
  signed __int64 v11; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode v12; // xmm0

  v2 = (Scaleform::Render::ContextImpl::EntryTable *)this->EntryPages.Root.pNext;
  v3 = &this->EntryPages;
  v4 = pnewSnapshot;
  v5 = this;
  if ( v2 == (Scaleform::Render::ContextImpl::EntryTable *)&this->EntryPages )
  {
    this->pActiveSnapshot = pnewSnapshot;
  }
  else
  {
    do
    {
      v6 = v2->FreeNodes.Root.pPrev;
      v7 = (Scaleform::Render::ContextImpl::Entry *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, signed __int64))v5->pHeap->vfptr->Alloc)(
                                                      v5->pHeap,
                                                      616i64,
                                                      16i64);
      v8 = v7;
      if ( v7 )
      {
        v7->pPrev = 0i64;
        v7->RefCount = 0i64;
        v7->pNative = v6->pNative;
        v9 = &v6->PNode;
        v10 = &v7->PNode;
        v7->pRenderer = (Scaleform::Render::TreeCacheNode *)v6;
        v7->pParent = 0i64;
        if ( ((unsigned __int8)((_BYTE)v7 + 40) | (unsigned __int8)((_BYTE)v6 + 40)) & 0xF )
        {
          memmove(v10, v9, 0x240ui64);
        }
        else
        {
          v11 = 4i64;
          do
          {
            v12 = *v9;
            v10 += 8;
            v9 += 8;
            v10[-8] = v12;
            v10[-7] = v9[-7];
            v10[-6] = v9[-6];
            v10[-5] = v9[-5];
            v10[-4] = v9[-4];
            v10[-3] = v9[-3];
            v10[-2] = v9[-2];
            v10[-1] = v9[-1];
            --v11;
          }
          while ( v11 );
          *v10 = *v9;
          v10[1] = v9[1];
          v10[2] = v9[2];
          v10[3] = v9[3];
        }
        v6->pParent = v8;
      }
      else
      {
        v8 = 0i64;
      }
      v2->FreeNodes.Root.pPrev = v8;
      v2->EntryPages.Root.pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)v4;
      v2 = (Scaleform::Render::ContextImpl::EntryTable *)v2->pHeap;
    }
    while ( v2 != (Scaleform::Render::ContextImpl::EntryTable *)v3 );
    v5->pActiveSnapshot = v4;
  }
}

// File Line: 509
// RVA: 0x944720
void __fastcall Scaleform::Render::ContextImpl::Snapshot::Snapshot(Scaleform::Render::ContextImpl::Snapshot *this, Scaleform::Render::ContextImpl::Context *pcontext, Scaleform::MemoryHeap *pheap)
{
  Scaleform::MemoryHeap *v3; // rsi
  Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *v4; // rax
  Scaleform::List<Scaleform::Render::ContextImpl::Entry::PropagateNode,Scaleform::Render::ContextImpl::Entry::PropagateNode> *v5; // rax
  Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *v6; // rax
  Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *v7; // rbx
  Scaleform::Render::ContextImpl::Snapshot::HeapNode *v8; // rax
  Scaleform::Render::ContextImpl::Snapshot::HeapNode *v9; // rcx

  v3 = pheap;
  this->pContext = pcontext;
  v4 = &this->SnapshotPages;
  v4->Root.pPrev = (Scaleform::Render::ContextImpl::SnapshotPage *)v4;
  v4->Root.pNext = (Scaleform::Render::ContextImpl::SnapshotPage *)v4;
  this->Changes.pPages = 0i64;
  this->Changes.pLast = 0i64;
  this->pFreeChangeNodes = 0i64;
  v5 = &this->PropagateEntrys;
  v5->Root.pPrev = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v5;
  v5->Root.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v5;
  v6 = &this->DestroyedNodes;
  v6->Root.pPrev = &v6->Root;
  v6->Root.RefCount = (unsigned __int64)v6;
  this->ForceUpdateImagesFlag = 0;
  v7 = &this->Heaps;
  v7->Root.pPrev = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)v7;
  v7->Root.pNext = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)v7;
  v8 = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)pheap->vfptr->Alloc(pheap, 56ui64, 0i64);
  v9 = v8;
  if ( v8 )
  {
    v8->ChangeHeap.pHeap = v3;
    v8->ChangeHeap.Granularity = 0x2000i64;
    v8->ChangeHeap.pPagePool = 0i64;
    v8->ChangeHeap.pLastPage = 0i64;
    v8->ChangeHeap.MaxPages = 0i64;
  }
  else
  {
    v9 = 0i64;
  }
  v9->pPrev = v7->Root.pPrev;
  v9->pNext = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)v7;
  v7->Root.pPrev->pNext = v9;
  v7->Root.pPrev = v9;
}

// File Line: 515
// RVA: 0x94CBF0
void __fastcall Scaleform::Render::ContextImpl::Snapshot::~Snapshot(Scaleform::Render::ContextImpl::Snapshot *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v1; // rsi
  char **v2; // rbp
  Scaleform::Render::ContextImpl::Snapshot::HeapNode *v3; // rbx
  unsigned __int64 v4; // rax
  char **v5; // rdi
  Scaleform::Render::ContextImpl::SnapshotPage *v6; // rdx
  Scaleform::Render::ContextImpl::SnapshotPage *v7; // rcx
  Scaleform::Render::ContextImpl::SnapshotPage *v8; // rcx

  v1 = this;
  v2 = (char **)&this->Heaps;
  if ( (Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *)this->Heaps.Root.pNext != &this->Heaps )
  {
    do
    {
      v3 = v1->Heaps.Root.pNext;
      v3->pPrev->pNext = v3->pNext;
      v3->pNext->pPrev = v3->pPrev;
      v3->pPrev = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)-1i64;
      v3->pNext = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)-1i64;
      v4 = v3->ChangeHeap.MaxPages;
      if ( v4 )
      {
        v5 = &v3->ChangeHeap.pPagePool->pStart + 3 * v4 - 3;
        do
        {
          --v3->ChangeHeap.MaxPages;
          if ( *v5 )
            ((void (__cdecl *)(Scaleform::MemoryHeap *))v3->ChangeHeap.pHeap->vfptr->Free)(v3->ChangeHeap.pHeap);
          v5 -= 3;
        }
        while ( v3->ChangeHeap.MaxPages );
        --v3->ChangeHeap.MaxPages;
        v3->ChangeHeap.pHeap->vfptr->Free(v3->ChangeHeap.pHeap, v3->ChangeHeap.pPagePool);
      }
      v3->ChangeHeap.pLastPage = 0i64;
      v3->ChangeHeap.pPagePool = 0i64;
      v3->ChangeHeap.MaxPages = 0i64;
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
    }
    while ( v2[1] != (char *)v2 );
  }
  while ( (Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *)v1->SnapshotPages.Root.pNext != &v1->SnapshotPages )
  {
    v6 = v1->SnapshotPages.Root.pNext;
    v6->pPrev->pNext = v6->pNext;
    v6->pNext->pPrev = v6->pPrev;
    v6->pPrev = (Scaleform::Render::ContextImpl::SnapshotPage *)-1i64;
    v6->pNext = (Scaleform::Render::ContextImpl::SnapshotPage *)-1i64;
    v7 = v6->pNewerSnapshotPage;
    if ( v7 )
      v7->pOlderSnapshotPage = v6->pOlderSnapshotPage;
    v8 = v6->pOlderSnapshotPage;
    if ( v8 )
      v8->pNewerSnapshotPage = v6->pNewerSnapshotPage;
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::~PagedItemBuffer<Scaleform::Render::VertexElement,32>(&v1->Changes);
}

// File Line: 533
// RVA: 0x954010
Scaleform::Render::ContextImpl::EntryChange *__fastcall Scaleform::Render::ContextImpl::Snapshot::AddChangeItem(Scaleform::Render::ContextImpl::Snapshot *this, Scaleform::Render::ContextImpl::Entry *pentry, unsigned int changeBits)
{
  Scaleform::Render::ContextImpl::EntryChange *v3; // r9
  unsigned int v4; // edi
  Scaleform::Render::ContextImpl::Entry *v5; // rsi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63> *v6; // rbx
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v7; // rdx
  __int64 v8; // rcx

  v3 = this->pFreeChangeNodes;
  v4 = changeBits;
  v5 = pentry;
  if ( v3 )
  {
    this->pFreeChangeNodes = v3->pNextFreeNode;
  }
  else
  {
    v6 = &this->Changes;
    Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::ensureCountAvailable(
      &this->Changes,
      1u);
    v7 = v6->pLast;
    v8 = v7->Count;
    v3 = (Scaleform::Render::ContextImpl::EntryChange *)((char *)v7 + 16 * (v8 + 1));
    v7->Count = v8 + 1;
  }
  v3->pNode = v5;
  v3->ChangeBits = v4;
  return v3;
}

// File Line: 563
// RVA: 0x99AE90
void __fastcall Scaleform::Render::ContextImpl::Snapshot::Merge(Scaleform::Render::ContextImpl::Snapshot *this, Scaleform::Render::ContextImpl::Snapshot *pold)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v2; // r15
  Scaleform::Render::ContextImpl::Snapshot *v3; // r9
  Scaleform::Render::ContextImpl::Snapshot *v4; // r13
  __int64 v5; // r8
  unsigned int v6; // esi
  _DWORD *v7; // rbx
  Scaleform::Render::ContextImpl::Entry *v8; // rbp
  __int64 v9; // rcx
  unsigned __int64 v10; // r12
  __int64 v11; // rdi
  __int64 v12; // rdx
  unsigned __int64 v13; // rdx
  __int64 v14; // rcx
  Scaleform::Render::ContextImpl::EntryChange *v15; // rdx
  unsigned int v16; // er14
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v17; // rdi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v18; // rax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v19; // rax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v20; // rcx
  __int64 v21; // rax
  bool v22; // al
  Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *v23; // r8
  Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *v24; // rax
  Scaleform::Render::ContextImpl::Entry *v25; // rcx
  Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *v26; // rax
  signed __int64 v27; // r13
  Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *v28; // rdx
  Scaleform::Render::ContextImpl::Snapshot::HeapNode *v29; // rcx
  Scaleform::Render::ContextImpl::Snapshot *v30; // [rsp+58h] [rbp+10h]

  v30 = pold;
  v2 = pold->Changes.pPages;
  v3 = pold;
  v4 = this;
  if ( v2 )
  {
    v5 = 0i64;
    while ( 1 )
    {
      v6 = 0;
      if ( v2->Count )
        break;
LABEL_23:
      v2 = v2->pNext;
      if ( !v2 )
      {
        v3 = v30;
        goto LABEL_25;
      }
    }
    while ( 1 )
    {
      v7 = (_DWORD *)((char *)v2 + 16 * (v6 + 1i64));
      v8 = *(Scaleform::Render::ContextImpl::Entry **)v7;
      if ( *(_QWORD *)v7 )
        break;
LABEL_22:
      if ( ++v6 >= v2->Count )
        goto LABEL_23;
    }
    v9 = *(_QWORD *)(((unsigned __int64)v8 & 0xFFFFFFFFFFFFF000ui64) + 0x20);
    v10 = 8
        * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v8[-1]
                                                                              - ((unsigned __int64)v8 & 0xFFFFFFFFFFFFF000ui64))
                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 4)
         + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v8[-1]
                                                                  - ((unsigned __int64)v8 & 0xFFFFFFFFFFFFF000ui64))
                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 63))
        + 40;
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
            (_QWORD)v8->pNative & 0xFFFFFFFFFFFFFFFEui64,
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
      if ( v14 && !(*(_BYTE *)(v10 + *(_QWORD *)(((unsigned __int64)v8 & 0xFFFFFFFFFFFFF000ui64) + 0x20)) & 1) )
        *(_DWORD *)(v14 + 8) |= v7[2] & 0x7FFFFFFF;
      goto LABEL_22;
    }
    v15 = v4->pFreeChangeNodes;
    v16 = v7[2];
    if ( v15 )
    {
      v4->pFreeChangeNodes = v15->pNextFreeNode;
LABEL_21:
      v15->pNode = v8;
      v15->ChangeBits = v16;
      goto LABEL_22;
    }
    v17 = v4->Changes.pLast;
    if ( v17 )
    {
      if ( v17->Count + 1 <= 0x3F )
      {
LABEL_20:
        v20 = v4->Changes.pLast;
        v21 = v20->Count;
        v15 = (Scaleform::Render::ContextImpl::EntryChange *)((char *)v20 + 16 * (v21 + 1));
        v20->Count = v21 + 1;
        goto LABEL_21;
      }
      v19 = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, &v4->Changes, 1024ui64, 0i64);
      v4->Changes.pLast = v19;
      v17->pNext = v19;
      v18 = v4->Changes.pLast;
    }
    else
    {
      v18 = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, &v4->Changes, 1024ui64, 0i64);
      v4->Changes.pPages = v18;
      v4->Changes.pLast = v18;
    }
    v5 = 0i64;
    v18->pNext = 0i64;
    v4->Changes.pLast->Count = 0;
    goto LABEL_20;
  }
LABEL_25:
  v22 = v3->ForceUpdateImagesFlag;
  if ( v22 )
    v4->ForceUpdateImagesFlag = v22;
  v23 = (Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *)v3->DestroyedNodes.Root.pNext;
  v24 = &v3->DestroyedNodes;
  if ( v23 != &v3->DestroyedNodes )
  {
    v25 = v24->Root.pPrev;
    v3->DestroyedNodes.Root.RefCount = (unsigned __int64)&v3->DestroyedNodes;
    v24->Root.pPrev = &v24->Root;
    v25->RefCount = v4->DestroyedNodes.Root.RefCount;
    v23->Root.pPrev = &v4->DestroyedNodes.Root;
    v4->DestroyedNodes.Root.pNext->pPrev = v25;
    v4->DestroyedNodes.Root.RefCount = (unsigned __int64)v23;
  }
  v26 = &v3->Heaps;
  v27 = (signed __int64)&v4->Heaps;
  v28 = (Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *)v3->Heaps.Root.pNext;
  if ( v28 != &v3->Heaps )
  {
    v29 = v26->Root.pPrev;
    v3->Heaps.Root.pNext = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)&v3->Heaps;
    v26->Root.pPrev = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)v26;
    v29->pNext = *(Scaleform::Render::ContextImpl::Snapshot::HeapNode **)(v27 + 8);
    v28->Root.pPrev = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)v27;
    **(_QWORD **)(v27 + 8) = v29;
    *(_QWORD *)(v27 + 8) = v28;
  }
}

// File Line: 662
// RVA: 0x93DD50
void __fastcall Scaleform::Render::ContextImpl::RTHandle::HandleData::HandleData(Scaleform::Render::ContextImpl::RTHandle::HandleData *this, Scaleform::Render::ContextImpl::Entry *entry, Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::ContextImpl::ContextLock *v3; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,69>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::ContextImpl::RTHandle::HandleData,69>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ContextImpl::RTHandle::HandleData::`vftable;
  v3 = context->pCaptureLock.pObject;
  if ( v3 )
    _InterlockedExchangeAdd(&v3->RefCount, 1u);
  this->pContextLock.pObject = context->pCaptureLock.pObject;
  this->State = 0;
  this->pEntry = entry;
}

// File Line: 666
// RVA: 0x94AF40
void __fastcall Scaleform::Render::ContextImpl::RTHandle::HandleData::~HandleData(Scaleform::Render::ContextImpl::RTHandle::HandleData *this)
{
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v1; // rdi
  _RTL_CRITICAL_SECTION *v2; // rbx
  Scaleform::Render::ContextImpl::Entry *v3; // rax
  Scaleform::Render::ContextImpl::ContextLock *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ContextImpl::RTHandle::HandleData::`vftable;
  v2 = &this->pContextLock.pObject->LockObject.cs;
  EnterCriticalSection(v2);
  if ( v1->pContextLock.pObject->pContext )
  {
    v3 = v1->pEntry;
    if ( v3 )
    {
      v3->pNative = (Scaleform::Render::ContextImpl::EntryData *)((_QWORD)v3->pNative & 0xFFFFFFFFFFFFFFFEui64);
      v1->pPrev->pNext = v1->pNext;
      v1->pNext->pPrev = v1->pPrev;
      v1->pPrev = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
      v1->pNext = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
    }
  }
  LeaveCriticalSection(v2);
  v4 = v1->pContextLock.pObject;
  if ( v4 && _InterlockedExchangeAdd(&v4->RefCount, 0xFFFFFFFF) == 1 && v4 )
    v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 677
// RVA: 0x940E60
void __fastcall Scaleform::Render::ContextImpl::RTHandle::RTHandle(Scaleform::Render::ContextImpl::RTHandle *this, Scaleform::Render::ContextImpl::Entry *entry)
{
  Scaleform::Render::ContextImpl::Entry *v2; // rsi
  Scaleform::Render::ContextImpl::RTHandle *v3; // rdi
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v4; // rbx
  Scaleform::Render::ContextImpl::Context *v5; // rbp
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v6; // rax
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v7; // rax
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v8; // rcx
  _RTL_CRITICAL_SECTION *v9; // rbx
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v10; // rcx

  v2 = entry;
  v3 = this;
  v4 = 0i64;
  this->pData.pObject = 0i64;
  if ( entry )
  {
    v5 = *(Scaleform::Render::ContextImpl::Context **)(*(_QWORD *)(((unsigned __int64)entry & 0xFFFFFFFFFFFFF000ui64)
                                                                 + 0x18)
                                                     + 16i64);
    v6 = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                                                   Scaleform::Memory::pGlobalHeap,
                                                                   56ui64,
                                                                   0i64);
    if ( v6 )
    {
      Scaleform::Render::ContextImpl::RTHandle::HandleData::HandleData(v6, v2, v5);
      v4 = v7;
    }
    v8 = v3->pData.pObject;
    if ( v3->pData.pObject && !_InterlockedDecrement(&v8->RefCount) )
    {
      if ( v8 )
        v8->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v8->vfptr, 1u);
    }
    v3->pData.pObject = v4;
    v9 = &v5->pCaptureLock.pObject->LockObject.cs;
    EnterCriticalSection(v9);
    v2->pNative = (Scaleform::Render::ContextImpl::EntryData *)((_QWORD)v2->pNative | 1i64);
    v10 = v3->pData.pObject;
    v10->pPrev = v5->RTHandleList.Root.pPrev;
    v10->pNext = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)&v5->RenderNode.8;
    v5->RTHandleList.Root.pPrev->pNext = v10;
    v5->RTHandleList.Root.pPrev = v10;
    LeaveCriticalSection(v9);
  }
}

// File Line: 691
// RVA: 0x94C190
void __fastcall Scaleform::Render::ContextImpl::RTHandle::~RTHandle(Scaleform::Render::ContextImpl::RTHandle *this)
{
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v1; // rcx

  v1 = this->pData.pObject;
  if ( v1 && !_InterlockedDecrement(&v1->RefCount) )
  {
    if ( v1 )
      v1->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v1->vfptr, 1u);
  }
}

// File Line: 696
// RVA: 0x99C1C0
bool __fastcall Scaleform::Render::ContextImpl::RTHandle::NextCapture(Scaleform::Render::ContextImpl::RTHandle *this, Scaleform::Render::ContextImpl::RenderNotify *render)
{
  Scaleform::Render::ContextImpl::RenderNotify *v2; // r14
  Scaleform::Render::ContextImpl::RTHandle *v3; // r15
  _RTL_CRITICAL_SECTION *v4; // r12
  Scaleform::Render::ContextImpl::Context *v5; // rdi
  Scaleform::Render::ContextImpl::Snapshot *v6; // rbp
  _RTL_CRITICAL_SECTION *v7; // rbx
  _RTL_CRITICAL_SECTION *v8; // rcx
  Scaleform::Render::ContextImpl::ContextCaptureNotify *k; // rcx
  signed __int64 v10; // rax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v11; // rbx
  _BOOL8 v12; // r8
  Scaleform::Render::ContextImpl::Snapshot *v13; // rdx
  signed __int64 v14; // rdx
  __int64 i; // rax
  __int64 v16; // rcx
  Scaleform::Render::ContextImpl::Snapshot *v17; // rcx
  Scaleform::Render::ContextImpl::ContextCaptureNotify *j; // rcx
  signed __int64 v19; // rax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v20; // rbx
  bool v21; // bl
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+60h] [rbp+8h]

  v2 = render;
  v3 = this;
  if ( !this->pData.pObject )
    return 0;
  v4 = &this->pData.pObject->pContextLock.pObject->LockObject.cs;
  EnterCriticalSection(v4);
  v5 = v3->pData.pObject->pContextLock.pObject->pContext;
  if ( !v5 || v3->pData.pObject->State == 2 )
  {
LABEL_40:
    LeaveCriticalSection(v4);
    return 0;
  }
  v6 = 0i64;
  v7 = &v5->pCaptureLock.pObject->LockObject.cs;
  lpCriticalSection = &v5->pCaptureLock.pObject->LockObject.cs;
  EnterCriticalSection(v7);
  if ( !v5->NextCaptureCalledInFrame )
  {
    if ( !v5->ShutdownRequested )
    {
      if ( v5->CreateThreadId != UFG::qGetCurrentThreadID() )
        v5->MultiThreadedUse = 1;
      if ( v2 )
        v5->NextCaptureCalledInFrame = 1;
      v13 = v5->pSnapshots[1];
      if ( v13 )
      {
        v14 = (signed __int64)&v13->SnapshotPages;
        for ( i = *(_QWORD *)(v14 + 8); i != v14; i = *(_QWORD *)(i + 8) )
        {
          v16 = *(_QWORD *)(i + 16);
          if ( v16 )
            *(_QWORD *)(v16 + 40) = i;
        }
        v5->pSnapshots[3] = v5->pSnapshots[2];
        v17 = v5->pSnapshots[1];
        v5->pSnapshots[2] = v17;
        v5->pSnapshots[1] = 0i64;
        v5->SnapshotFrameIds[3] = v5->SnapshotFrameIds[2];
        v5->SnapshotFrameIds[2] = v5->SnapshotFrameIds[1];
        if ( v2 )
        {
          v6 = v17;
          LOBYTE(v12) = 1;
          v2->vfptr->NewCapture(v2, v5, v12);
        }
        for ( j = v5->CaptureNotifyList.Root.pNext; ; j = v20 )
        {
          v19 = (signed __int64)(v5 == (Scaleform::Render::ContextImpl::Context *)-120i64 ? 0i64 : &v5->pCaptureLock);
          if ( j == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v19 )
            break;
          v20 = j->pNext;
          j->vfptr->OnNextCapture(j, v2);
        }
        v5->DIChangesRequired = 0;
      }
      else if ( v2 )
      {
        v2->vfptr->NewCapture(v2, v5, 0);
      }
      v8 = lpCriticalSection;
      goto LABEL_35;
    }
    Scaleform::Render::ContextImpl::Context::clearRTHandleList(v5);
    Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(v5);
    for ( k = v5->CaptureNotifyList.Root.pNext; ; k = v11 )
    {
      v10 = (signed __int64)(v5 == (Scaleform::Render::ContextImpl::Context *)-120i64 ? 0i64 : &v5->pCaptureLock);
      if ( k == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v10 )
        break;
      v11 = k->pNext;
      k->vfptr->OnNextCapture(k, v2);
    }
    v5->DIChangesRequired = 0;
    LeaveCriticalSection(lpCriticalSection);
    v3->pData.pObject->pContextLock.pObject->pContext = 0i64;
    goto LABEL_40;
  }
  v8 = v7;
LABEL_35:
  LeaveCriticalSection(v8);
  if ( v3->pData.pObject->State == State_PreCapture )
    v3->pData.pObject->State = 1;
  v21 = v3->pData.pObject->State == 1;
  LeaveCriticalSection(v4);
  if ( v6 )
    Scaleform::Render::ContextImpl::Context::nextCapture_NotifyChanges(v5, v6, v2);
  return v21;
} if ( v6 )
    Scaleform::Render::ContextImpl::C

// File Line: 783
// RVA: 0x98B020
Scaleform::Render::ContextImpl::Entry *__fastcall Scaleform::Render::ContextImpl::RTHandle::GetRenderEntry(Scaleform::Render::ContextImpl::RTHandle *this)
{
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v1; // rax
  Scaleform::Render::ContextImpl::Entry *result; // rax

  v1 = this->pData.pObject;
  if ( this->pData.pObject && v1->State == 1 )
    result = v1->pEntry;
  else
    result = 0i64;
  return result;
}

// File Line: 792
// RVA: 0x94C430
void __fastcall Scaleform::Render::ContextImpl::RenderNotify::~RenderNotify(Scaleform::Render::ContextImpl::RenderNotify *this)
{
  Scaleform::Render::ContextImpl::RenderNotify *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::Render::ContextImpl::RenderNotifyVtbl *)&Scaleform::Render::ContextImpl::RenderNotify::`vftable;
  Scaleform::Render::ContextImpl::RenderNotify::ReleaseAllContextData(this);
  v1->ServiceCommandInstance.vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
}

// File Line: 797
// RVA: 0x99C180
void __fastcall Scaleform::Render::ContextImpl::RenderNotify::NewCapture(Scaleform::Render::ContextImpl::RenderNotify *this, Scaleform::Render::ContextImpl::Context *context, bool hasChanges)
{
  Scaleform::Render::ContextImpl::RenderNotify::ContextNode *v3; // rax
  Scaleform::Render::ContextImpl::RenderNotify::ContextNode *v4; // rdx
  Scaleform::List<Scaleform::Render::ContextImpl::RenderNotify::ContextNode,Scaleform::Render::ContextImpl::RenderNotify::ContextNode> *v5; // rcx

  if ( context->pRenderer != this )
  {
    context->pRenderer = this;
    v3 = this->ActiveContextSet.Root.pPrev;
    v4 = &context->RenderNode;
    v5 = &this->ActiveContextSet;
    v4->pPrev = v3;
    v4->pNext = (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)v5;
    v5->Root.pPrev->pNext = v4;
    v5->Root.pPrev = v4;
  }
}

// File Line: 809
// RVA: 0x962B00
void __fastcall Scaleform::Render::ContextImpl::RenderNotify::ContextReleased(Scaleform::Render::ContextImpl::RenderNotify *this, Scaleform::Render::ContextImpl::Context *context)
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
void __fastcall Scaleform::Render::ContextImpl::RenderNotify::ServiceQueues(Scaleform::Render::ContextImpl::RenderNotify *this)
{
  Scaleform::Render::ContextImpl::RenderNotify::ContextNode *v1; // rdi
  Scaleform::Render::ContextImpl::RenderNotify::ContextNode *v2; // rbp
  Scaleform::Render::ContextImpl::RenderNotify::ContextNode *v3; // rsi
  Scaleform::Render::ContextImpl::Context *v4; // rsi
  _RTL_CRITICAL_SECTION *v5; // rbx

  v1 = this->ActiveContextSet.Root.pNext;
  v2 = (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)&this->ActiveContextSet;
  if ( v1 != (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)&this->ActiveContextSet )
  {
    do
    {
      v3 = v1;
      v1 = v1->pNext;
      if ( v3->pContext->pShutdownEvent )
      {
        v4 = v3->pContext;
        v5 = &v4->pCaptureLock.pObject->LockObject.cs;
        EnterCriticalSection(v5);
        if ( v4->CreateThreadId != UFG::qGetCurrentThreadID() )
          v4->MultiThreadedUse = 1;
        Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(v4);
        LeaveCriticalSection(v5);
      }
    }
    while ( v1 != v2 );
  }
}

// File Line: 831
// RVA: 0x9A7D80
void __fastcall Scaleform::Render::ContextImpl::RenderNotify::ReleaseAllContextData(Scaleform::Render::ContextImpl::RenderNotify *this)
{
  Scaleform::Render::ContextImpl::RenderNotify *v1; // rbp
  char **v2; // rsi
  Scaleform::Render::ContextImpl::Context *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx

  v1 = this;
  v2 = (char **)&this->ActiveContextSet;
  if ( (Scaleform::List<Scaleform::Render::ContextImpl::RenderNotify::ContextNode,Scaleform::Render::ContextImpl::RenderNotify::ContextNode> *)this->ActiveContextSet.Root.pNext != &this->ActiveContextSet )
  {
    do
    {
      v3 = v1->ActiveContextSet.Root.pNext->pContext;
      v4 = &v3->pCaptureLock.pObject->LockObject.cs;
      EnterCriticalSection(v4);
      if ( v3->CreateThreadId != UFG::qGetCurrentThreadID() )
        v3->MultiThreadedUse = 1;
      Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(v3);
      LeaveCriticalSection(v4);
    }
    while ( v2[1] != (char *)v2 );
  }
}

// File Line: 851
// RVA: 0x949530
void __fastcall Scaleform::Render::ContextImpl::ContextCaptureNotify::~ContextCaptureNotify(Scaleform::Render::ContextImpl::ContextCaptureNotify *this)
{
  this->vfptr = (Scaleform::Render::ContextImpl::ContextCaptureNotifyVtbl *)&Scaleform::Render::ContextImpl::ContextCaptureNotify::`vftable;
  if ( this->pOwnedContext )
    Scaleform::Render::ContextImpl::Context::RemoveCaptureNotify(this->pOwnedContext, this);
}

// File Line: 866
// RVA: 0x939910
void __fastcall Scaleform::Render::ContextImpl::Context::Context(Scaleform::Render::ContextImpl::Context *this, Scaleform::MemoryHeap *pheap)
{
  Scaleform::Render::ContextImpl::Context *v2; // rbx
  Scaleform::List<Scaleform::Render::ContextImpl::EntryPage,Scaleform::Render::ContextImpl::EntryPageBase> *v3; // rax
  Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *v4; // rax
  bool v5; // zf
  _QWORD *v6; // rcx
  signed __int64 v7; // rax
  signed __int64 v8; // rcx
  Scaleform::Render::ContextImpl::ContextLock *v9; // rax
  Scaleform::Render::ContextImpl::ContextLock *v10; // rax
  Scaleform::Render::ContextImpl::ContextLock *v11; // rdi
  Scaleform::Render::ContextImpl::ContextLock *v12; // rcx
  Scaleform::Render::ContextImpl::Snapshot *v13; // rax
  Scaleform::Render::ContextImpl::Snapshot *v14; // rax

  v2 = this;
  this->pHeap = pheap;
  this->Table.pContext = this;
  this->Table.pHeap = pheap;
  v3 = &this->Table.EntryPages;
  v3->Root.pPrev = (Scaleform::Render::ContextImpl::EntryPageBase *)v3;
  v3->Root.pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)v3;
  v4 = &this->Table.FreeNodes;
  v4->Root.pPrev = &v4->Root;
  v4->Root.RefCount = (unsigned __int64)v4;
  this->Table.pActiveSnapshot = 0i64;
  this->pCaptureLock.pObject = 0i64;
  v5 = &this->CaptureNotifyList == 0i64;
  v6 = &this->CaptureNotifyList.Root.pPrev;
  v7 = (signed __int64)(v6 - 1);
  if ( v5 )
    v7 = 0i64;
  *v6 = v7;
  v6[1] = v7;
  v2->pRenderer = 0i64;
  v2->NextCaptureCalledInFrame = 0;
  v2->DIChangesRequired = 0;
  v2->ShutdownRequested = 0;
  v2->pShutdownEvent = 0i64;
  v2->RenderNode.pContext = v2;
  v8 = (signed __int64)&v2->RenderNode.8;
  if ( v2 == (Scaleform::Render::ContextImpl::Context *)-184i64 )
    v8 = 0i64;
  v2->RTHandleList.Root.pPrev = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)v8;
  v2->RTHandleList.Root.pNext = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)v8;
  v9 = (Scaleform::Render::ContextImpl::ContextLock *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        64i64);
  if ( v9 )
  {
    Scaleform::Render::ContextImpl::ContextLock::ContextLock(v9, v2);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = v2->pCaptureLock.pObject;
  if ( v12 && !_InterlockedDecrement(&v12->RefCount) && v12 )
    v12->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, 1u);
  v2->pCaptureLock.pObject = v11;
  v2->CreateThreadId = UFG::qGetCurrentThreadID();
  v2->MultiThreadedUse = 0;
  v13 = (Scaleform::Render::ContextImpl::Snapshot *)v2->pHeap->vfptr->Alloc(v2->pHeap, 160ui64, 0i64);
  if ( v13 )
    Scaleform::Render::ContextImpl::Snapshot::Snapshot(v13, v2, v2->pHeap);
  else
    v14 = 0i64;
  v2->pSnapshots[0] = v14;
  v2->pSnapshots[3] = 0i64;
  v2->pSnapshots[2] = 0i64;
  v2->pSnapshots[1] = 0i64;
  v2->FinalizedFrameId = 0i64;
  v2->SnapshotFrameIds[0] = 1i64;
  v2->SnapshotFrameIds[1] = 0i64;
  v2->SnapshotFrameIds[2] = 0i64;
  v2->SnapshotFrameIds[3] = 0i64;
  v2->Table.pActiveSnapshot = v2->pSnapshots[0];
  v2->CaptureCalled = 0;
}

// File Line: 891
// RVA: 0x9493E0
void __fastcall Scaleform::Render::ContextImpl::Context::~Context(Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Context *v1; // rdi
  Scaleform::Render::ContextImpl::Snapshot *v2; // r8
  signed __int64 v3; // r8
  Scaleform::Render::ContextImpl::Context *i; // rdx
  Scaleform::Render::ContextImpl::EntryPageBase *v5; // rcx
  signed __int64 v6; // rax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v7; // rsi
  _RTL_CRITICAL_SECTION *v8; // rbx
  Scaleform::Render::ContextImpl::ContextLock *v9; // rcx

  v1 = this;
  Scaleform::Render::ContextImpl::Context::Shutdown(this, 1);
  Scaleform::Render::ContextImpl::Context::destroySnapshot(v1, v1->pSnapshots[3]);
  Scaleform::Render::ContextImpl::Context::destroySnapshot(v1, v1->pSnapshots[2]);
  Scaleform::Render::ContextImpl::Context::destroySnapshot(v1, v1->pSnapshots[1]);
  v2 = v1->pSnapshots[0];
  if ( v2 )
  {
    v3 = (signed __int64)&v2->SnapshotPages;
    for ( i = (Scaleform::Render::ContextImpl::Context *)v1->Table.EntryPages.Root.pNext;
          i != (Scaleform::Render::ContextImpl::Context *)&v1->Table.EntryPages;
          i = (Scaleform::Render::ContextImpl::Context *)i->CreateThreadId )
    {
      v5 = i->Table.EntryPages.Root.pPrev;
      v5->pPrev = *(Scaleform::Render::ContextImpl::EntryPageBase **)v3;
      v5->pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)v3;
      *(_QWORD *)(*(_QWORD *)v3 + 8i64) = v5;
      *(_QWORD *)v3 = v5;
    }
    Scaleform::Render::ContextImpl::Context::destroySnapshot(v1, v1->pSnapshots[0]);
  }
  while ( 1 )
  {
    v6 = (signed __int64)&v1->pCaptureLock;
    if ( v1 == (Scaleform::Render::ContextImpl::Context *)-120i64 )
      v6 = 0i64;
    if ( v1->CaptureNotifyList.Root.pNext == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v6 )
      break;
    v7 = v1->CaptureNotifyList.Root.pNext;
    v8 = &v1->pCaptureLock.pObject->LockObject.cs;
    EnterCriticalSection(v8);
    if ( v7->pOwnedContext == v1 )
    {
      v7->pPrev->pNext = v7->pNext;
      v7->pNext->pPrev = v7->pPrev;
      v7->pPrev = (Scaleform::Render::ContextImpl::ContextCaptureNotify *)-1i64;
      v7->pNext = (Scaleform::Render::ContextImpl::ContextCaptureNotify *)-1i64;
      v7->pOwnedContext = 0i64;
    }
    LeaveCriticalSection(v8);
  }
  v9 = v1->pCaptureLock.pObject;
  if ( v9 && _InterlockedExchangeAdd(&v9->RefCount, 0xFFFFFFFF) == 1 && v9 )
    v9->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, 1u);
}

// File Line: 916
// RVA: 0x9DD200
Scaleform::Render::ContextImpl::Entry *__fastcall Scaleform::Render::ContextImpl::Context::createEntryHelper(Scaleform::Render::ContextImpl::Context *this, Scaleform::Render::ContextImpl::EntryData *pdata)
{
  Scaleform::Render::ContextImpl::EntryData *v2; // rbx
  Scaleform::Render::ContextImpl::Context *v3; // rsi
  Scaleform::Render::ContextImpl::Entry *result; // rax
  Scaleform::Render::ContextImpl::Entry *v5; // rax
  Scaleform::Render::ContextImpl::Entry *v6; // rdi
  Scaleform::Render::ContextImpl::EntryChange *v7; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v10; // rax

  v2 = pdata;
  v3 = this;
  if ( !pdata )
    return 0i64;
  v5 = Scaleform::Render::ContextImpl::EntryTable::AllocEntry(&this->Table, pdata);
  v6 = v5;
  if ( v5 )
  {
    v7 = Scaleform::Render::ContextImpl::Snapshot::AddChangeItem(v3->pSnapshots[0], v5, 0x80000000);
    v6->pNative = v2;
    v6->pPrev = (Scaleform::Render::ContextImpl::Entry *)v7;
    v6->RefCount = 1i64;
    v8 = &v6->PNode;
    v6->pRenderer = 0i64;
    v6->pParent = 0i64;
    v8->pNext = 0i64;
    v8->pPrev = 0i64;
    v9 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64)
                                                                  + 0x18);
    v10 = v9[4].pPrev;
    v9 += 4;
    v8->pPrev = v10;
    v8->pNext = v9;
    v9->pPrev->pNext = &v6->PNode;
    result = v6;
    v9->pPrev = &v6->PNode;
  }
  else
  {
    v2->vfptr->Destroy(v2);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
    result = 0i64;
  }
  return result;
}

// File Line: 940
// RVA: 0x9DFF20
void __fastcall Scaleform::Render::ContextImpl::Context::destroySnapshot(Scaleform::Render::ContextImpl::Context *this, Scaleform::Render::ContextImpl::Snapshot *p)
{
  Scaleform::Render::ContextImpl::Snapshot *v2; // rax
  Scaleform::Render::ContextImpl::Snapshot *v3; // rsi
  Scaleform::Render::ContextImpl::Context *i; // rbp
  Scaleform::Render::ContextImpl::Context *v5; // r8
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *j; // rdi
  unsigned int v7; // ebx
  __int64 v8; // rdx
  unsigned __int64 v9; // r8
  unsigned __int64 v10; // rdx

  if ( p )
  {
    v2 = (Scaleform::Render::ContextImpl::Snapshot *)p->SnapshotPages.Root.pNext;
    v3 = p;
    for ( i = this; v2 != (Scaleform::Render::ContextImpl::Snapshot *)&p->SnapshotPages; v2 = v2->pNext )
    {
      v5 = v2->pContext;
      if ( v5 )
        v5->Table.FreeNodes.Root.pPrev = (Scaleform::Render::ContextImpl::Entry *)v2;
    }
    for ( j = p->Changes.pPages; j; j = j->pNext )
    {
      v7 = 0;
      if ( j->Count )
      {
        do
        {
          v8 = *((_QWORD *)&j->pNext + 2 * (v7 + 1i64));
          if ( v8 )
          {
            if ( (*(&j->Count + 4 * (v7 + 1i64)) & 0x80000000) == 0 )
            {
              v9 = v8 & 0xFFFFFFFFFFFFF000ui64;
              v10 = (signed __int64)((unsigned __int128)((signed __int64)(v8 - (v8 & 0xFFFFFFFFFFFFF000ui64) - 56)
                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 4;
              (*(void (**)(void))(**(_QWORD **)(*(_QWORD *)(v9 + 48) + 8 * ((unsigned int)v10 + (v10 >> 63)) + 40)
                                + 32i64))();
            }
          }
          ++v7;
        }
        while ( v7 < j->Count );
      }
    }
    Scaleform::Render::ContextImpl::Context::destroyNativeNodes(i, &v3->DestroyedNodes);
    Scaleform::Render::ContextImpl::Snapshot::~Snapshot(v3);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
}

// File Line: 980
// RVA: 0x9DFE00
void __fastcall Scaleform::Render::ContextImpl::Context::destroyNativeNodes(Scaleform::Render::ContextImpl::Context *this, Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *destroyList)
{
  unsigned __int64 v2; // rbx
  Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *v3; // rdi
  Scaleform::Render::ContextImpl::EntryTable *v4; // rsi
  Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *v5; // rbp
  bool v6; // zf

  v2 = destroyList->Root.RefCount;
  v3 = destroyList;
  if ( (Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *)v2 != destroyList )
  {
    v4 = &this->Table;
    v5 = &this->Table.FreeNodes;
    do
    {
      *(_QWORD *)(*(_QWORD *)v2 + 8i64) = *(_QWORD *)(v2 + 8);
      **(_QWORD **)(v2 + 8) = *(_QWORD *)v2;
      (*(void (**)(void))(*(_QWORD *)(*(_QWORD *)(v2 + 16) & 0xFFFFFFFFFFFFFFFEui64) + 32i64))();
      Scaleform::Memory::pGlobalHeap->vfptr->Free(
        Scaleform::Memory::pGlobalHeap,
        (void *)(*(_QWORD *)(v2 + 16) & 0xFFFFFFFFFFFFFFFEui64));
      *(_QWORD *)(v2 + 16) = 0i64;
      *(_QWORD *)(v2 + 8) = v5->Root.pNext;
      *(_QWORD *)v2 = v5;
      v5->Root.pNext->pPrev = (Scaleform::Render::ContextImpl::Entry *)v2;
      v5->Root.RefCount = v2;
      *(_QWORD *)(*(_QWORD *)((v2 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                + 8
                * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v2
                                                                                      - (v2 & 0xFFFFFFFFFFFFF000ui64)
                                                                                      - 56)
                                                                     * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                 + ((unsigned __int64)((unsigned __int128)((signed __int64)(v2 - (v2 & 0xFFFFFFFFFFFFF000ui64) - 56)
                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                + 40) = 0i64;
      v6 = (*(_DWORD *)((v2 & 0xFFFFFFFFFFFFF000ui64) + 0x10))-- == 1;
      if ( v6 )
        Scaleform::Render::ContextImpl::EntryTable::FreeEntryPage(
          v4,
          (Scaleform::Render::ContextImpl::EntryPage *)(v2 & 0xFFFFFFFFFFFFF000ui64));
      v2 = v3->Root.RefCount;
    }
    while ( (Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *)v2 != v3 );
  }
}

// File Line: 997
// RVA: 0x9D5EE0
void __fastcall Scaleform::Render::ContextImpl::Context::clearRTHandle(Scaleform::Render::ContextImpl::Context *this, Scaleform::Render::ContextImpl::Entry *entry)
{
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v2; // rax
  Scaleform::List<Scaleform::Render::ContextImpl::RTHandle::HandleData,Scaleform::Render::ContextImpl::RTHandle::HandleData> *v3; // r8
  signed __int64 v4; // rcx

  v2 = this->RTHandleList.Root.pNext;
  v3 = &this->RTHandleList;
  while ( 1 )
  {
    v4 = (signed __int64)(v3 ? &v3[-1] : 0i64);
    if ( v2 == (Scaleform::Render::ContextImpl::RTHandle::HandleData *)v4 )
      break;
    if ( v2->pEntry == entry )
    {
      v2->pPrev->pNext = v2->pNext;
      v2->pNext->pPrev = v2->pPrev;
      v2->pPrev = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
      v2->pNext = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
      v2->State = 2;
      v2->pEntry = 0i64;
      entry->pNative = (Scaleform::Render::ContextImpl::EntryData *)((_QWORD)entry->pNative & 0xFFFFFFFFFFFFFFFEui64);
      return;
    }
    v2 = v2->pNext;
  }
}

// File Line: 1017
// RVA: 0x9D5F50
void __fastcall Scaleform::Render::ContextImpl::Context::clearRTHandleList(Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Context *v1; // r9
  Scaleform::List<Scaleform::Render::ContextImpl::RTHandle::HandleData,Scaleform::Render::ContextImpl::RTHandle::HandleData> *v2; // r8
  signed __int64 v3; // rax
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v4; // rax
  Scaleform::Render::ContextImpl::Entry *v5; // rcx

  v1 = this;
  v2 = &this->RTHandleList;
  while ( 1 )
  {
    v3 = (signed __int64)&v2[-1];
    if ( !v2 )
      v3 = 0i64;
    if ( v2->Root.pNext == (Scaleform::Render::ContextImpl::RTHandle::HandleData *)v3 )
      break;
    v4 = v1->RTHandleList.Root.pNext;
    v4->pPrev->pNext = v4->pNext;
    v4->pNext->pPrev = v4->pPrev;
    v4->pPrev = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
    v4->pNext = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
    v5 = v4->pEntry;
    v4->State = 2;
    if ( v5 )
      v5->pNative = (Scaleform::Render::ContextImpl::EntryData *)((_QWORD)v5->pNative & 0xFFFFFFFFFFFFFFFEui64);
    v4->pEntry = 0i64;
  }
}

// File Line: 1031
// RVA: 0x991330
bool __fastcall Scaleform::Render::ContextImpl::Context::HasChanges(Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v1; // rdx
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v2; // rax
  volatile bool result; // al

  v1 = this->pSnapshots[0];
  v2 = v1->Changes.pPages;
  if ( v2 && v2->Count
    || (Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *)v1->DestroyedNodes.Root.pNext != &v1->DestroyedNodes
    || (result = this->DIChangesRequired) != 0 )
  {
    result = 1;
  }
  return result;
}

// File Line: 1040
// RVA: 0x95DC50
char __fastcall Scaleform::Render::ContextImpl::Context::Capture(Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Context *v1; // rbp
  _RTL_CRITICAL_SECTION *v3; // rbx
  Scaleform::Render::ContextImpl::Snapshot *v4; // rdi
  signed __int64 v5; // r8
  Scaleform::Render::ContextImpl::Context *i; // rdx
  Scaleform::Render::ContextImpl::EntryPageBase *v7; // rcx
  Scaleform::Render::ContextImpl::Snapshot *v8; // rdx
  Scaleform::Render::ContextImpl::Snapshot *v9; // rsi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *j; // rdx
  unsigned int k; // ecx
  _QWORD *v12; // r8
  Scaleform::Render::ContextImpl::Snapshot *v13; // rax
  Scaleform::Render::ContextImpl::Snapshot *v14; // rax
  Scaleform::Render::ContextImpl::Snapshot *v15; // rdi
  Scaleform::Render::ContextImpl::Snapshot *v16; // r15
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *l; // r15
  unsigned int m; // edi
  __int64 v19; // rsi
  __int64 v20; // r8
  unsigned __int64 v21; // rax
  signed __int64 v22; // r14
  unsigned __int64 v23; // rcx
  unsigned __int64 v24; // rax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v25; // rdi
  signed __int64 v26; // rbp
  signed __int64 v27; // rax

  v1 = this;
  Scaleform::Render::ContextImpl::Context::PropagateChangesUp(this);
  if ( v1->ShutdownRequested )
    return 0;
  v3 = &v1->pCaptureLock.pObject->LockObject.cs;
  EnterCriticalSection(v3);
  Scaleform::Render::ContextImpl::Context::handleFinalizingSnaphot(v1);
  v4 = v1->pSnapshots[0];
  v5 = (signed __int64)&v4->SnapshotPages;
  for ( i = (Scaleform::Render::ContextImpl::Context *)v1->Table.EntryPages.Root.pNext;
        i != (Scaleform::Render::ContextImpl::Context *)&v1->Table.EntryPages;
        i = (Scaleform::Render::ContextImpl::Context *)i->CreateThreadId )
  {
    v7 = i->Table.EntryPages.Root.pPrev;
    v7->pPrev = *(Scaleform::Render::ContextImpl::EntryPageBase **)v5;
    v7->pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)v5;
    *(_QWORD *)(*(_QWORD *)v5 + 8i64) = v7;
    *(_QWORD *)v5 = v7;
  }
  v8 = v1->pSnapshots[1];
  if ( v8 )
  {
    Scaleform::Render::ContextImpl::Snapshot::Merge(v4, v8);
    v9 = v1->pSnapshots[1];
    if ( v9 )
    {
      Scaleform::Render::ContextImpl::Snapshot::~Snapshot(v1->pSnapshots[1]);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9);
    }
  }
  v1->pSnapshots[1] = v4;
  v1->SnapshotFrameIds[1] = v1->SnapshotFrameIds[0];
  for ( j = v4->Changes.pPages; j; j = j->pNext )
  {
    for ( k = 0; k < j->Count; ++k )
    {
      v12 = (_QWORD *)*((_QWORD *)&j->pNext + 2 * (k + 1i64));
      if ( v12 )
        *v12 = 0i64;
    }
  }
  v13 = (Scaleform::Render::ContextImpl::Snapshot *)v1->pHeap->vfptr->Alloc(v1->pHeap, 160ui64, 0i64);
  if ( v13 )
  {
    Scaleform::Render::ContextImpl::Snapshot::Snapshot(v13, v1, v1->pHeap);
    v15 = v14;
  }
  else
  {
    v15 = 0i64;
  }
  Scaleform::Render::ContextImpl::EntryTable::NextSnapshot(&v1->Table, v15);
  v1->pSnapshots[0] = v15;
  ++v1->SnapshotFrameIds[0];
  v16 = v1->pSnapshots[2];
  if ( v16 )
  {
    for ( l = v16->Changes.pPages; l; l = l->pNext )
    {
      for ( m = 0; m < l->Count; ++m )
      {
        v19 = *((_QWORD *)&l->pNext + 2 * (m + 1i64));
        if ( v19 )
        {
          if ( (*(&l->Count + 4 * (m + 1i64)) & 0x80000000) == 0 )
          {
            v20 = *(_QWORD *)((v19 & 0xFFFFFFFFFFFFF000ui64) + 0x28);
            v21 = (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v19
                                                                                     - (v19 & 0xFFFFFFFFFFFFF000ui64)
                                                                                     - 56)
                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                + ((unsigned __int64)((unsigned __int128)((signed __int64)(v19 - (v19 & 0xFFFFFFFFFFFFF000ui64) - 56)
                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63);
            v22 = *(_QWORD *)(v20 + 32) + 8 * v21;
            v23 = *(_QWORD *)(v22 + 40) & 0xFFFFFFFFFFFFFFFEui64;
            if ( *(_QWORD *)(v20 + 8 * v21 + 40) == v23 )
            {
              (*(void (__fastcall **)(unsigned __int64, unsigned __int64))(*(_QWORD *)v23 + 16i64))(
                v23,
                *(_QWORD *)(v19 + 16) & 0xFFFFFFFFFFFFFFFEui64);
              v24 = *(_QWORD *)(v19 + 16) & 0xFFFFFFFFFFFFFFFEui64;
              *(_QWORD *)(v22 + 40) &= 1ui64;
              *(_QWORD *)(v22 + 40) |= v24;
            }
          }
        }
      }
    }
  }
  v1->CaptureCalled = 1;
  v25 = v1->CaptureNotifyList.Root.pNext;
  v26 = (signed __int64)&v1->CaptureNotifyList;
  while ( 1 )
  {
    v27 = v26 - 8;
    if ( !v26 )
      v27 = 0i64;
    if ( v25 == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v27 )
      break;
    v25->vfptr->OnCapture(v25);
    v25 = v25->pNext;
  }
  LeaveCriticalSection(v3);
  return 1;
}

// File Line: 1159
// RVA: 0x9E7CD0
void __fastcall Scaleform::Render::ContextImpl::Context::handleFinalizingSnaphot(Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v1; // rsi
  Scaleform::Render::ContextImpl::Context *v2; // rbp
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *i; // rdi
  unsigned int v4; // ebx
  __int64 v5; // r9
  __int64 v6; // r10
  __int64 v7; // rcx
  unsigned __int64 v8; // rax
  signed __int64 v9; // rdx
  unsigned __int64 v10; // rax

  v1 = this->pSnapshots[3];
  v2 = this;
  if ( v1 )
  {
    for ( i = v1->Changes.pPages; i; i = i->pNext )
    {
      v4 = 0;
      if ( i->Count )
      {
        do
        {
          v5 = *((_QWORD *)&i->pNext + 2 * (v4 + 1i64));
          if ( v5 && (*(&i->Count + 4 * (v4 + 1i64)) & 0x80000000) == 0 )
          {
            v6 = *(_QWORD *)((v5 & 0xFFFFFFFFFFFFF000ui64) + 0x20);
            v7 = *(_QWORD *)(*(_QWORD *)((v5 & 0xFFFFFFFFFFFFF000ui64) + 0x28) + 24i64);
            v8 = ((unsigned __int64)((unsigned __int128)((signed __int64)(v5 - (v5 & 0xFFFFFFFFFFFFF000ui64) - 56)
                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 63)
               + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v5
                                                                                    - (v5 & 0xFFFFFFFFFFFFF000ui64)
                                                                                    - 56)
                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 4);
            v9 = 8 * v8 + 40;
            if ( *(_QWORD *)(v9 + v7) == (*(_QWORD *)(v6 + 8 * v8 + 40) & 0xFFFFFFFFFFFFFFFEui64) )
              *(_QWORD *)(v9 + v6) = *(_QWORD *)(v5 + 16) ^ (*(_DWORD *)(v9 + v6) ^ *(_DWORD *)(v5 + 16)) & 1;
            (*(void (**)(void))(**(_QWORD **)(v9 + v7) + 32i64))();
          }
          ++v4;
        }
        while ( v4 < i->Count );
      }
    }
    Scaleform::Render::ContextImpl::Context::destroyNativeNodes(v2, &v1->DestroyedNodes);
    if ( v1 )
    {
      Scaleform::Render::ContextImpl::Snapshot::~Snapshot(v1);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1);
    }
    v10 = v2->SnapshotFrameIds[3];
    v2->pSnapshots[3] = 0i64;
    v2->FinalizedFrameId = v10;
  }
}

// File Line: 1209
// RVA: 0x9B6030
void __fastcall Scaleform::Render::ContextImpl::Context::Shutdown(Scaleform::Render::ContextImpl::Context *this, bool waitFlag)
{
  bool v2; // r14
  Scaleform::Render::ContextImpl::Context *v3; // rsi
  Scaleform::Render::ContextImpl::ContextCaptureNotify *i; // rcx
  signed __int64 v5; // rax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v6; // rbx
  char v7; // di
  _RTL_CRITICAL_SECTION *v8; // rbx
  signed __int64 v9; // rax
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v10; // rax
  Scaleform::Render::ContextImpl::Entry *v11; // rcx
  _RTL_CRITICAL_SECTION *v12; // rbx
  Scaleform::Render::ContextImpl::RenderNotify *v13; // rdx
  Scaleform::Render::ThreadCommandQueue *v14; // rcx
  __int64 v15; // rbx
  __int64 v16; // r8
  __int64 v17; // r9
  __int64 v18; // rdx
  void **v19; // [rsp+30h] [rbp-39h]
  int v20; // [rsp+38h] [rbp-31h]
  volatile signed __int32 *v21; // [rsp+40h] [rbp-29h]
  void **v22; // [rsp+48h] [rbp-21h]
  char v23; // [rsp+50h] [rbp-19h]
  char v24; // [rsp+51h] [rbp-18h]
  Scaleform::Mutex pmutex; // [rsp+58h] [rbp-11h]
  Scaleform::WaitCondition v26; // [rsp+80h] [rbp+17h]

  v2 = waitFlag;
  v3 = this;
  for ( i = this->CaptureNotifyList.Root.pNext; ; i = v6 )
  {
    v5 = (signed __int64)&v3->pCaptureLock;
    if ( v3 == (Scaleform::Render::ContextImpl::Context *)-120i64 )
      v5 = 0i64;
    if ( i == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v5 )
      break;
    v6 = i->pNext;
    i->vfptr->OnShutdown(i, v2);
  }
  v3->DIChangesRequired = 0;
  while ( 1 )
  {
    v7 = 0;
    v8 = &v3->pCaptureLock.pObject->LockObject.cs;
    EnterCriticalSection(v8);
    Scaleform::Render::ContextImpl::Context::handleFinalizingSnaphot(v3);
    v3->ShutdownRequested = 1;
    if ( !v2 )
      goto LABEL_19;
    if ( v3->pRenderer )
    {
      if ( v3->MultiThreadedUse )
      {
        v7 = 1;
        goto LABEL_19;
      }
      Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(v3);
    }
    while ( 1 )
    {
      v9 = (signed __int64)&v3->RenderNode.8;
      if ( v3 == (Scaleform::Render::ContextImpl::Context *)-184i64 )
        v9 = 0i64;
      if ( v3->RTHandleList.Root.pNext == (Scaleform::Render::ContextImpl::RTHandle::HandleData *)v9 )
        break;
      v10 = v3->RTHandleList.Root.pNext;
      v10->pPrev->pNext = v10->pNext;
      v10->pNext->pPrev = v10->pPrev;
      v10->pPrev = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
      v10->pNext = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
      v10->State = 2;
      v11 = v10->pEntry;
      if ( v11 )
        v11->pNative = (Scaleform::Render::ContextImpl::EntryData *)((_QWORD)v11->pNative & 0xFFFFFFFFFFFFFFFEui64);
      v10->pEntry = 0i64;
    }
    v3->pCaptureLock.pObject->pContext = 0i64;
LABEL_19:
    LeaveCriticalSection(v8);
    if ( !v7 )
      break;
    v20 = 1;
    v21 = 0i64;
    v19 = &Scaleform::Event::`vftable{for `Scaleform::Waitable};
    v22 = &Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
    Scaleform::Mutex::Mutex(&pmutex, 1, 0);
    Scaleform::WaitCondition::WaitCondition(&v26);
    v23 = 0;
    v24 = 0;
    v12 = &v3->pCaptureLock.pObject->LockObject.cs;
    EnterCriticalSection(v12);
    if ( v3->pRenderer )
    {
      v3->pShutdownEvent = (Scaleform::Event *volatile )&v19;
      v13 = v3->pRenderer;
      v14 = v13->pRTCommandQueue;
      if ( v14 )
        v14->vfptr->PushThreadCommand(v14, (Scaleform::Render::ThreadCommand *)&v13->ServiceCommandInstance.vfptr);
    }
    else
    {
      v7 = 0;
    }
    LeaveCriticalSection(v12);
    if ( v7 )
    {
      Scaleform::Mutex::DoLock(&pmutex);
      while ( !v23 )
        Scaleform::WaitCondition::Wait(&v26, &pmutex, 0xFFFFFFFF);
      if ( v24 )
      {
        v24 = 0;
        v23 = 0;
      }
      Scaleform::Mutex::Unlock(&pmutex);
    }
    v19 = &Scaleform::Event::`vftable{for `Scaleform::Waitable};
    v22 = &Scaleform::Event::`vftable{for `Scaleform::AcquireInterface};
    Scaleform::WaitCondition::~WaitCondition(&v26);
    Scaleform::Mutex::~Mutex(&pmutex);
    v22 = &Scaleform::AcquireInterface::`vftable;
    v19 = &Scaleform::Waitable::`vftable;
    v15 = (__int64)v21;
    if ( v21 && !_InterlockedDecrement(v21) && v15 )
    {
      DeleteCriticalSection((LPCRITICAL_SECTION)(v15 + 32));
      v18 = *(_QWORD *)(v15 + 8);
      if ( v18 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, __int64, __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v18,
          v16,
          v17);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v15);
    }
    v19 = &Scaleform::RefCountImplCore::`vftable;
  }
}

// File Line: 1280
// RVA: 0x997D10
_BOOL8 __fastcall Scaleform::Render::ContextImpl::Context::IsShutdownComplete(Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Context *v1; // rbx
  bool v2; // bl
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+40h] [rbp+8h]

  v1 = this;
  lpCriticalSection = &this->pCaptureLock.pObject->LockObject.cs;
  EnterCriticalSection(lpCriticalSection);
  v2 = v1->ShutdownRequested && !v1->pRenderer;
  LeaveCriticalSection(lpCriticalSection);
  return v2;
}

// File Line: 1289
// RVA: 0x9EA290
__int64 __fastcall Scaleform::Render::ContextImpl::Context::nextCapture_LockScope(Scaleform::Render::ContextImpl::Context *this, Scaleform::Render::ContextImpl::Snapshot **updateSnapshot, Scaleform::Render::ContextImpl::RenderNotify *pnotify, Scaleform::Render::ContextImpl::Context::CaptureMode mode)
{
  Scaleform::Render::ContextImpl::Context::CaptureMode v4; // ebx
  Scaleform::Render::ContextImpl::RenderNotify *v5; // r14
  Scaleform::Render::ContextImpl::Snapshot **v6; // rsi
  Scaleform::Render::ContextImpl::Context *v7; // rdi
  Scaleform::Render::ContextImpl::ContextCaptureNotify *k; // rcx
  signed __int64 v9; // rax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v10; // rbx
  unsigned __int8 v11; // bl
  _BOOL8 v12; // r8
  Scaleform::Render::ContextImpl::Snapshot *v13; // rdx
  signed __int64 v14; // rdx
  __int64 i; // rax
  __int64 v16; // rcx
  Scaleform::Render::ContextImpl::Snapshot *v17; // rcx
  Scaleform::Render::ContextImpl::ContextCaptureNotify *j; // rcx
  signed __int64 v19; // rax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v20; // rbx
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [rsp+40h] [rbp+8h]

  v4 = mode;
  v5 = pnotify;
  v6 = updateSnapshot;
  v7 = this;
  lpCriticalSection = &this->pCaptureLock.pObject->LockObject.cs;
  EnterCriticalSection(lpCriticalSection);
  if ( v4 == 1 && v7->NextCaptureCalledInFrame )
  {
LABEL_32:
    v11 = 1;
    goto LABEL_33;
  }
  if ( !v7->ShutdownRequested )
  {
    if ( v7->CreateThreadId != UFG::qGetCurrentThreadID() )
      v7->MultiThreadedUse = 1;
    if ( v5 && v4 == 1 )
      v7->NextCaptureCalledInFrame = 1;
    v13 = v7->pSnapshots[1];
    if ( v13 )
    {
      v14 = (signed __int64)&v13->SnapshotPages;
      for ( i = *(_QWORD *)(v14 + 8); i != v14; i = *(_QWORD *)(i + 8) )
      {
        v16 = *(_QWORD *)(i + 16);
        if ( v16 )
          *(_QWORD *)(v16 + 40) = i;
      }
      v7->pSnapshots[3] = v7->pSnapshots[2];
      v17 = v7->pSnapshots[1];
      v7->pSnapshots[2] = v17;
      v7->pSnapshots[1] = 0i64;
      v7->SnapshotFrameIds[3] = v7->SnapshotFrameIds[2];
      v7->SnapshotFrameIds[2] = v7->SnapshotFrameIds[1];
      if ( v5 )
      {
        *v6 = v17;
        LOBYTE(v12) = 1;
        v5->vfptr->NewCapture(v5, v7, v12);
      }
      for ( j = v7->CaptureNotifyList.Root.pNext; ; j = v20 )
      {
        v19 = (signed __int64)(v7 == (Scaleform::Render::ContextImpl::Context *)-120i64 ? 0i64 : &v7->pCaptureLock);
        if ( j == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v19 )
          break;
        v20 = j->pNext;
        j->vfptr->OnNextCapture(j, v5);
      }
      v7->DIChangesRequired = 0;
    }
    else if ( v5 )
    {
      v5->vfptr->NewCapture(v5, v7, 0);
    }
    goto LABEL_32;
  }
  Scaleform::Render::ContextImpl::Context::clearRTHandleList(v7);
  Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(v7);
  for ( k = v7->CaptureNotifyList.Root.pNext; ; k = v10 )
  {
    v9 = (signed __int64)(v7 == (Scaleform::Render::ContextImpl::Context *)-120i64 ? 0i64 : &v7->pCaptureLock);
    if ( k == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v9 )
      break;
    v10 = k->pNext;
    k->vfptr->OnNextCapture(k, v5);
  }
  v7->DIChangesRequired = 0;
  v11 = 0;
LABEL_33:
  LeaveCriticalSection(lpCriticalSection);
  return v11;
}

// File Line: 1389
// RVA: 0x9EA470
void __fastcall Scaleform::Render::ContextImpl::Context::nextCapture_NotifyChanges(Scaleform::Render::ContextImpl::Context *this, Scaleform::Render::ContextImpl::Snapshot *displaySnaphot, Scaleform::Render::ContextImpl::RenderNotify *pnotify)
{
  Scaleform::Render::ContextImpl::RenderNotify *v3; // rdi
  Scaleform::Render::ContextImpl::Snapshot *v4; // rsi
  Scaleform::Render::ContextImpl::Context *v5; // r14
  Scaleform::Render::ContextImpl::Entry *v6; // rbx
  signed __int64 v7; // rbp
  Scaleform::Render::ContextImpl::Entry *v8; // rdi
  _RTL_CRITICAL_SECTION *v9; // rbx
  Scaleform::Render::ContextImpl::RTHandle::HandleData *i; // rax
  signed __int64 v11; // rcx

  if ( displaySnaphot )
  {
    v3 = pnotify;
    v4 = displaySnaphot;
    v5 = this;
    ((void (__fastcall *)(Scaleform::Render::ContextImpl::RenderNotify *, Scaleform::Render::ContextImpl::Context *, Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63> *, bool, signed __int64))pnotify->vfptr->EntryChanges)(
      pnotify,
      this,
      &displaySnaphot->Changes,
      displaySnaphot->ForceUpdateImagesFlag,
      -2i64);
    v4->ForceUpdateImagesFlag = 0;
    v6 = v4->DestroyedNodes.Root.pNext;
    v7 = (signed __int64)&v4->DestroyedNodes;
    if ( v6 != (Scaleform::Render::ContextImpl::Entry *)&v4->DestroyedNodes )
    {
      do
      {
        v3->vfptr->EntryDestroy(v3, v6);
        v6->pRenderer = (Scaleform::Render::TreeCacheNode *)2989;
        v6 = v6->pNext;
      }
      while ( v6 != (Scaleform::Render::ContextImpl::Entry *)v7 );
      v8 = v4->DestroyedNodes.Root.pNext;
      v9 = &v5->pCaptureLock.pObject->LockObject.cs;
      EnterCriticalSection(v9);
      do
      {
        if ( (_QWORD)v8->pNative & 1 )
        {
          for ( i = v5->RTHandleList.Root.pNext; ; i = i->pNext )
          {
            v11 = (signed __int64)&v5->RenderNode.8;
            if ( v5 == (Scaleform::Render::ContextImpl::Context *)-184i64 )
              v11 = 0i64;
            if ( i == (Scaleform::Render::ContextImpl::RTHandle::HandleData *)v11 )
              break;
            if ( i->pEntry == v8 )
            {
              i->pPrev->pNext = i->pNext;
              i->pNext->pPrev = i->pPrev;
              i->pPrev = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
              i->pNext = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)-1i64;
              i->State = 2;
              i->pEntry = 0i64;
              v8->pNative = (Scaleform::Render::ContextImpl::EntryData *)((_QWORD)v8->pNative & 0xFFFFFFFFFFFFFFFEui64);
              break;
            }
          }
        }
        v8 = v8->pNext;
      }
      while ( v8 != (Scaleform::Render::ContextImpl::Entry *)v7 );
      LeaveCriticalSection(v9);
    }
  }
}

// File Line: 1423
// RVA: 0x97AEC0
void __fastcall Scaleform::Render::ContextImpl::Context::ForceUpdateImages(Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v1; // rax

  v1 = this->pSnapshots[0];
  if ( v1 )
    v1->ForceUpdateImagesFlag = 1;
}

// File Line: 1439
// RVA: 0x953FA0
void __fastcall Scaleform::Render::ContextImpl::Context::AddCaptureNotify(Scaleform::Render::ContextImpl::Context *this, Scaleform::Render::ContextImpl::ContextCaptureNotify *notify)
{
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v2; // rsi
  Scaleform::Render::ContextImpl::Context *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx

  v2 = notify;
  v3 = this;
  v4 = &this->pCaptureLock.pObject->LockObject.cs;
  EnterCriticalSection(v4);
  v2->pOwnedContext = v3;
  v2->pPrev = v3->CaptureNotifyList.Root.pPrev;
  v2->pNext = (Scaleform::Render::ContextImpl::ContextCaptureNotify *)&v3->pCaptureLock;
  v3->CaptureNotifyList.Root.pPrev->pNext = v2;
  v3->CaptureNotifyList.Root.pPrev = v2;
  LeaveCriticalSection(v4);
}

// File Line: 1447
// RVA: 0x9A96F0
void __fastcall Scaleform::Render::ContextImpl::Context::RemoveCaptureNotify(Scaleform::Render::ContextImpl::Context *this, Scaleform::Render::ContextImpl::ContextCaptureNotify *notify)
{
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v2; // rsi
  Scaleform::Render::ContextImpl::Context *v3; // rdi
  _RTL_CRITICAL_SECTION *v4; // rbx

  v2 = notify;
  v3 = this;
  v4 = &this->pCaptureLock.pObject->LockObject.cs;
  EnterCriticalSection(v4);
  if ( v2->pOwnedContext == v3 )
  {
    v2->pPrev->pNext = v2->pNext;
    v2->pNext->pPrev = v2->pPrev;
    v2->pPrev = (Scaleform::Render::ContextImpl::ContextCaptureNotify *)-1i64;
    v2->pNext = (Scaleform::Render::ContextImpl::ContextCaptureNotify *)-1i64;
    v2->pOwnedContext = 0i64;
  }
  LeaveCriticalSection(v4);
}

// File Line: 1477
// RVA: 0x9F2500
void __fastcall Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Context *v1; // rbp
  Scaleform::Render::ContextImpl::Snapshot *v2; // rax
  Scaleform::Render::ContextImpl::SnapshotPage *v3; // rsi
  signed __int64 i; // r14
  Scaleform::Render::ContextImpl::EntryPage *v5; // rbx
  Scaleform::Render::TreeCacheNode **v6; // rbx
  signed __int64 v7; // rdi

  v1 = this;
  if ( this->pRenderer )
  {
    v2 = this->pSnapshots[2];
    if ( v2 )
    {
      v3 = v2->SnapshotPages.Root.pNext;
      for ( i = (signed __int64)&v2->SnapshotPages; v3 != (Scaleform::Render::ContextImpl::SnapshotPage *)i; v3 = v3->pNext )
      {
        v5 = v3->pEntryPage;
        if ( v5 )
        {
          v6 = &v5->Entries[0].pRenderer;
          v7 = 72i64;
          do
          {
            if ( *v6 != (Scaleform::Render::TreeCacheNode *)2989 && *v6 )
              v1->pRenderer->vfptr->EntryFlush(v1->pRenderer, (Scaleform::Render::ContextImpl::Entry *)(v6 - 3));
            v6 += 7;
            --v7;
          }
          while ( v7 );
        }
      }
      v1->pRenderer->vfptr->ContextReleased(v1->pRenderer, v1);
      if ( v1->pShutdownEvent )
      {
        Scaleform::Event::SetEvent(v1->pShutdownEvent);
        v1->pShutdownEvent = 0i64;
      }
    }
  }
}

// File Line: 1529
// RVA: 0x9A05D0
void __fastcall Scaleform::Render::ContextImpl::Context::PropagateChangesUp(Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v1; // r12
  signed __int64 v2; // rdx
  char *v3; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v4; // r14
  Scaleform::List<Scaleform::Render::ContextImpl::Entry::PropagateNode,Scaleform::Render::ContextImpl::Entry::PropagateNode> *v5; // r12
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v6; // r15
  unsigned int v7; // ebx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *i; // rax
  char *v9; // rax
  char *v10; // rdi
  unsigned int v11; // ecx
  unsigned int v12; // edx
  signed __int64 v13; // rcx
  int v14; // eax
  __int64 v15; // rbx
  __int64 v16; // r15
  _QWORD *v17; // r14
  unsigned __int64 v18; // rdx
  __int64 v19; // rcx
  __int64 v20; // rsi
  __int64 v21; // r13
  unsigned int v22; // er12
  char *v23; // rax
  char *v24; // rbx
  unsigned int v25; // edx
  unsigned int v26; // ecx
  unsigned int v27; // eax
  char *Src; // [rsp+20h] [rbp-B8h]
  unsigned int v29; // [rsp+28h] [rbp-B0h]
  unsigned int v30; // [rsp+2Ch] [rbp-ACh]
  Scaleform::MemoryHeap *v31; // [rsp+30h] [rbp-A8h]
  char v32; // [rsp+40h] [rbp-98h]
  __int64 v33; // [rsp+118h] [rbp+40h]
  unsigned int v34; // [rsp+158h] [rbp+80h]

  v33 = -2i64;
  v1 = this->pSnapshots[0];
  Src = &v32;
  v29 = 0;
  v2 = 32i64;
  v30 = 32;
  v31 = this->pHeap;
  v3 = &v32;
  do
  {
    *(_QWORD *)v3 = 0i64;
    v3 += 8;
    --v2;
  }
  while ( v2 );
  v4 = v1->PropagateEntrys.Root.pNext;
  v5 = &v1->PropagateEntrys;
  if ( v4 != (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v5 )
  {
    while ( 1 )
    {
      v6 = v4->pNext;
      v7 = 0;
      for ( i = v4[-1].pNext; i; i = i[2].pPrev )
        ++v7;
      if ( v7 < v30 )
        break;
      v9 = (char *)v31->vfptr->Alloc(v31, 8i64 * ((v7 + 32) & 0xFFFFFFE0), 0i64);
      v10 = v9;
      if ( v9 )
      {
        memmove(v9, Src, 8i64 * v29);
        v11 = v29;
        v12 = 0;
        if ( ((v7 + 32) & 0xFFFFFFE0) != v29 )
        {
          while ( 1 )
          {
            *(_QWORD *)&v10[8 * (v12++ + v11)] = 0i64;
            if ( v12 >= ((v7 + 32) & 0xFFFFFFE0) - v29 )
              break;
            v11 = v29;
          }
        }
        if ( Src != &v32 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        Src = v10;
        v30 = v7 + 1;
        goto LABEL_15;
      }
LABEL_18:
      v4->pPrev = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)1;
      v4 = v6;
      if ( v6 == (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v5 )
        goto LABEL_19;
    }
    v10 = Src;
LABEL_15:
    v13 = 8i64 * v7;
    v4->pNext = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)&v10[v13];
    *(_QWORD *)&Src[v13] = v4;
    v14 = v29;
    if ( v29 < v7 + 1 )
      v14 = v7 + 1;
    v29 = v14;
    goto LABEL_18;
  }
LABEL_19:
  v5->Root.pPrev = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v5;
  v5->Root.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v5;
  v15 = v29 - 1;
  v34 = v29 - 1;
  if ( v29 )
  {
    while ( 1 )
    {
      v16 = *(_QWORD *)&Src[8 * v15];
      if ( v16 )
        break;
LABEL_38:
      v15 = (unsigned int)(v15 - 1);
      v34 = v15;
      if ( (_DWORD)v15 == -1 )
        goto LABEL_39;
    }
    while ( 1 )
    {
      v17 = (_QWORD *)(v16 - 40);
      v18 = (signed __int64)((unsigned __int128)((signed __int64)(v16 - 40 - ((v16 - 40) & 0xFFFFFFFFFFFFF000ui64) - 56)
                                               * (signed __int128)5270498306774157605i64) >> 64) >> 4;
      v19 = *(_QWORD *)(*(_QWORD *)(((v16 - 40) & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                      + 8 * ((unsigned int)v18 + (v18 >> 63))
                      + 40);
      if ( !(*(unsigned __int8 (__fastcall **)(__int64, __int64))(*(_QWORD *)v19 + 40i64))(v19, v16 - 40) )
        goto LABEL_37;
      v20 = v17[4];
      if ( !v20 || *(_QWORD *)(v20 + 48) )
        goto LABEL_37;
      v21 = (unsigned int)(v15 - 1);
      if ( (unsigned int)v21 < v30 )
        break;
      v22 = v15;
      v23 = (char *)v31->vfptr->Alloc(v31, 8i64 * (((_DWORD)v21 + 32) & 0xFFFFFFE0), 0i64);
      v24 = v23;
      if ( v23 )
      {
        memmove(v23, Src, 8i64 * v29);
        v25 = v29;
        v26 = 0;
        if ( (((_DWORD)v21 + 32) & 0xFFFFFFE0) != v29 )
        {
          while ( 1 )
          {
            *(_QWORD *)&v24[8 * (v26++ + v25)] = 0i64;
            if ( v26 >= (((_DWORD)v21 + 32) & 0xFFFFFFE0) - v29 )
              break;
            v25 = v29;
          }
        }
        if ( Src != &v32 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        Src = v24;
        v30 = v22;
        goto LABEL_33;
      }
LABEL_36:
      LODWORD(v15) = v34;
LABEL_37:
      v16 = *(_QWORD *)(v16 + 8);
      v17[6] = 0i64;
      v17[5] = 0i64;
      if ( !v16 )
        goto LABEL_38;
    }
    v24 = Src;
LABEL_33:
    *(_QWORD *)(v20 + 48) = *(_QWORD *)&v24[8 * v21];
    *(_QWORD *)&Src[8 * v21] = v20 + 40;
    v27 = v29;
    if ( v29 < (signed int)v21 + 1 )
      v27 = v21 + 1;
    v29 = v27;
    goto LABEL_36;
  }
LABEL_39:
  if ( Src != &v32 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

