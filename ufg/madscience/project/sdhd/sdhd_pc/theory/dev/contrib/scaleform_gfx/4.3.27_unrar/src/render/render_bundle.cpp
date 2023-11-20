// File Line: 26
// RVA: 0x159CBA0
__int64 dynamic_initializer_for__Scaleform::Render::SortKeyInterface::NullInterface__()
{
  return atexit(dynamic_atexit_destructor_for__Scaleform::Render::SortKeyInterface::NullInterface__);
}

// File Line: 65
// RVA: 0x9B8550
void __fastcall Scaleform::Render::BundleEntryRange::StripChainsByDepth(Scaleform::Render::BundleEntryRange *this, unsigned int topDepth)
{
  Scaleform::Render::BundleEntry *v2; // r9
  Scaleform::Render::Bundle *v3; // r8
  Scaleform::Render::BundleEntry *v4; // rax
  signed __int64 v5; // r8
  bool v6; // zf

  v2 = this->pFirst;
  if ( this->pFirst )
  {
    while ( 1 )
    {
      v3 = v2->pBundle.pObject;
      v4 = v2;
      if ( v3 )
        v3->NeedUpdate = 1;
      v5 = (signed __int64)&v2->pChain;
      if ( v2->pChain )
      {
        do
        {
          if ( v4->ChainHeight > v4->pSourceNode->Depth - topDepth )
            break;
          v4 = *(Scaleform::Render::BundleEntry **)v5;
          v6 = *(_QWORD *)(*(_QWORD *)v5 + 8i64) == 0i64;
          v5 = *(_QWORD *)v5 + 8i64;
        }
        while ( !v6 );
      }
      v4->pChain = 0i64;
      v4->ChainHeight = 0;
      if ( v2 == this->pLast )
        break;
      v2 = v2->pNextPattern;
    }
  }
}

// File Line: 167
// RVA: 0x99A010
bool __fastcall Scaleform::Render::BundleEntryRangeMatcher::Match(Scaleform::Render::BundleEntryRangeMatcher *this, Scaleform::Render::BundleEntryRange *other, unsigned int *mergeDepth)
{
  Scaleform::Render::BundleEntryRangeMatcher *v3; // rbx
  unsigned int *v4; // r10
  Scaleform::Render::BundleEntryRange *v5; // r11
  Scaleform::Render::BundleEntry *v7; // rcx
  Scaleform::Render::BundleEntry *v8; // rdi
  bool v9; // zf
  Scaleform::Render::BundleEntry **v10; // r9
  unsigned int v11; // ebp
  int v12; // er13
  unsigned __int64 v13; // rsi
  char v14; // r12
  Scaleform::Render::SortKeyInterface *v15; // rdx
  unsigned int v16; // er8
  Scaleform::Render::BundleEntry *v17; // rdx
  signed __int64 v18; // rax
  Scaleform::Render::TreeCacheNode *v19; // rax
  unsigned __int64 v20; // rax
  signed __int64 v21; // r14
  __int64 v22; // rax
  int v23; // eax
  signed __int64 v24; // [rsp+20h] [rbp-88h]
  __int64 *v25; // [rsp+28h] [rbp-80h]
  __int64 v26[7]; // [rsp+30h] [rbp-78h]
  Scaleform::Render::BundleEntryRange *v27; // [rsp+B8h] [rbp+10h]
  unsigned int *v28; // [rsp+C0h] [rbp+18h]
  Scaleform::Render::BundleEntry *v29; // [rsp+C8h] [rbp+20h]

  v28 = mergeDepth;
  v27 = other;
  v3 = this;
  v4 = mergeDepth;
  v5 = other;
  if ( (other->Length & 0x7FFFFFFF) > (this->Length & 0x7FFFFFFF) )
    return 0;
  v7 = this->pFirst;
  v8 = other->pFirst;
  v29 = v3->pFirst;
  if ( !v3->pFirst )
    return v8 == 0i64;
  v9 = v8 == 0i64;
  if ( v8 )
  {
    v10 = v3->pLastEntries;
    v11 = 0;
    v12 = 0;
    v24 = (signed __int64)v3->pLastEntries;
    v13 = 0i64;
    while ( 1 )
    {
      v14 = 0;
      if ( v12 != v11 )
        goto LABEL_28;
      v15 = v7->Key.pImpl;
      v16 = v15->Flags;
      if ( _bittest((const signed int *)&v16, 0xFu)
        || v7->Key.Data != v8->Key.Data
        || v15 != v8->Key.pImpl
        || !_bittest((const signed int *)&v16, 0xDu) )
      {
        goto LABEL_28;
      }
      if ( v4 )
        break;
LABEL_24:
      if ( v8 == v5->pLast )
        v8 = 0i64;
      else
        v8 = v8->pNextPattern;
      v14 = 1;
LABEL_28:
      v21 = (signed __int64)&v7->Key;
      if ( (v7->Key.pImpl->Flags >> 12) & 1 )
      {
        if ( v11 == 6 )
          return 0;
        v22 = v11++;
        v26[v22] = v21;
        if ( v14 )
          ++v12;
      }
      else if ( v11 )
      {
        v25 = &v26[v11 - 1];
        v23 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, signed __int64))(**(_QWORD **)*v25 + 24i64))(
                *(_QWORD *)*v25,
                *(_QWORD *)(*v25 + 8),
                v21);
        if ( v23 )
        {
          if ( v12 == v11 && !v14 )
            return 0;
          if ( v23 == 2 )
          {
            if ( v12 == v11 )
              --v12;
            --v11;
          }
          else
          {
            *v25 = v21;
          }
        }
        v10 = (Scaleform::Render::BundleEntry **)v24;
        v4 = v28;
        v5 = v27;
      }
      if ( v29 != v3->pLast )
      {
        v7 = v29->pNextPattern;
        ++v10;
        ++v13;
        v29 = v29->pNextPattern;
        v24 = (signed __int64)v10;
        if ( v8 )
          continue;
      }
      return v8 == 0i64;
    }
    if ( v13 >= v3->LastEntryCount || (v17 = *v10) == 0i64 )
      v17 = v7;
    v18 = (signed __int64)&v17->pChain;
    if ( v17->pChain )
    {
      do
      {
        v17 = *(Scaleform::Render::BundleEntry **)v18;
        v9 = *(_QWORD *)(*(_QWORD *)v18 + 8i64) == 0i64;
        v18 = *(_QWORD *)v18 + 8i64;
      }
      while ( !v9 );
    }
    v19 = v17->pSourceNode;
    v17->pChain = v8;
    v17->ChainHeight = v19->Depth - *(_WORD *)v4;
    v20 = v3->LastEntryCount;
    if ( v13 >= v20 )
    {
      if ( v13 >= 8 )
      {
LABEL_23:
        v7 = v29;
        goto LABEL_24;
      }
      if ( v20 < v13 )
      {
        do
          v3->pLastEntries[v3->LastEntryCount++] = 0i64;
        while ( v3->LastEntryCount < v13 );
      }
      ++v3->LastEntryCount;
    }
    *v10 = v8;
    goto LABEL_23;
  }
  return v9;
}] = 0i64;
        while ( v3->LastEntryCount < v13 );
      

// File Line: 279
// RVA: 0x9BD660
void __fastcall Scaleform::Render::Bundle::UpdateChain(Scaleform::Render::Bundle *this, Scaleform::Render::BundleEntry *newTop)
{
  unsigned __int64 v2; // rbx
  Scaleform::Render::BundleEntry *v3; // rbp
  Scaleform::Render::Bundle *v4; // rsi
  Scaleform::Render::BundleEntry *i; // rdi
  unsigned __int64 v6; // r9
  unsigned __int64 v7; // r8
  Scaleform::Render::BundleEntry **v8; // rcx
  unsigned __int64 v9; // r8

  v2 = 0i64;
  v3 = newTop;
  v4 = this;
  this->NeedUpdate = 0;
  for ( i = newTop; i; ++v2 )
  {
    v6 = v4->Entries.Data.Size;
    if ( v2 >= v6 || i != v4->Entries.Data.Data[v2] )
    {
      if ( i->pBundle.pObject != v4 )
        goto LABEL_20;
      v7 = v2;
      if ( v2 < v6 )
      {
        v8 = &v4->Entries.Data.Data[v2];
        do
        {
          if ( *v8 == i )
            break;
          ++v7;
          ++v8;
        }
        while ( v7 < v6 );
        if ( v7 > v2 )
          ((void (__fastcall *)(Scaleform::Render::Bundle *, unsigned __int64, unsigned __int64))v4->vfptr[2].__vecDelDtor)(
            v4,
            v2,
            v7 - v2);
      }
      if ( v2 >= v4->Entries.Data.Size || i != v4->Entries.Data.Data[v2] )
      {
LABEL_20:
        Scaleform::Render::BundleEntry::SetBundle(i, v4, v2);
        ((void (__fastcall *)(Scaleform::Render::Bundle *, unsigned __int64, Scaleform::Render::BundleEntry *))v4->vfptr[1].__vecDelDtor)(
          v4,
          v2,
          i);
      }
    }
    i = i->pChain;
  }
  v9 = v4->Entries.Data.Size;
  if ( v2 < v9 )
    ((void (__fastcall *)(Scaleform::Render::Bundle *, unsigned __int64, unsigned __int64))v4->vfptr[2].__vecDelDtor)(
      v4,
      v2,
      v9 - v2);
  v4->pTop = v3;
}

// File Line: 332
// RVA: 0x9950C0
void __fastcall Scaleform::Render::Bundle::InsertEntry(Scaleform::Render::Bundle *this, unsigned __int64 index, Scaleform::Render::BundleEntry *shape)
{
  Scaleform::ArrayLH<Scaleform::Render::BundleEntry *,2,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  unsigned __int64 v4; // rdi
  Scaleform::Render::BundleEntry *v5; // rsi
  unsigned __int64 v6; // r8
  Scaleform::Render::BundleEntry **v7; // rcx

  v3 = &this->Entries;
  v4 = index;
  v5 = shape;
  Scaleform::ArrayData<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<Scaleform::GFx::AS2::Value *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value *,2>,Scaleform::ArrayDefaultPolicy> *)&this->Entries,
    this->Entries.Data.Size + 1);
  v6 = v3->Data.Size;
  if ( v4 < v6 - 1 )
    memmove(&v3->Data.Data[v4 + 1], &v3->Data.Data[v4], 8 * (v6 - v4) - 8);
  v7 = &v3->Data.Data[v4];
  if ( v7 )
    *v7 = v5;
}

// File Line: 338
// RVA: 0x9A97D0
void __fastcall Scaleform::Render::Bundle::RemoveEntries(Scaleform::Render::Bundle *this, unsigned __int64 index, unsigned __int64 count)
{
  unsigned __int64 v3; // rbp
  unsigned __int64 v4; // r14
  Scaleform::Render::Bundle *v5; // rbx
  unsigned int v6; // esi
  __int64 v7; // rax
  Scaleform::Render::BundleEntry *v8; // rdi
  Scaleform::Render::Bundle *v9; // rcx
  bool v10; // zf
  unsigned __int64 v11; // r8

  v3 = count;
  v4 = index;
  v5 = this;
  v6 = 0;
  if ( count )
  {
    v7 = 0i64;
    do
    {
      v8 = v5->Entries.Data.Data[v7 + v4];
      v9 = v8->pBundle.pObject;
      if ( v9 )
      {
        v10 = v9->RefCount-- == 1;
        if ( v10 )
          v9->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v9->vfptr, 1u);
      }
      ++v6;
      v8->pBundle.pObject = 0i64;
      v8->IndexHint = 0;
      v7 = v6;
    }
    while ( v6 < v3 );
  }
  v11 = v5->Entries.Data.Size;
  if ( v11 == v3 )
  {
    if ( v11 && v5->Entries.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( v5->Entries.Data.Data )
      {
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v5->Entries.Data.Data = 0i64;
      }
      v5->Entries.Data.Policy.Capacity = 0i64;
    }
    v5->Entries.Data.Size = 0i64;
  }
  else
  {
    memmove(&v5->Entries.Data.Data[v4], &v5->Entries.Data.Data[v4 + v3], 8 * (v11 - v4 - v3));
    v5->Entries.Data.Size -= v3;
  }
}

