// File Line: 26
// RVA: 0x159CBA0
__int64 dynamic_initializer_for__Scaleform::Render::SortKeyInterface::NullInterface__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Scaleform::Render::SortKeyInterface::NullInterface__);
}

// File Line: 65
// RVA: 0x9B8550
void __fastcall Scaleform::Render::BundleEntryRange::StripChainsByDepth(
        Scaleform::Render::BundleEntryRange *this,
        unsigned int topDepth)
{
  Scaleform::Render::BundleEntry *pFirst; // r9
  Scaleform::Render::Bundle *pObject; // r8
  Scaleform::Render::BundleEntry *v4; // rax
  __int64 p_pChain; // r8
  bool v6; // zf

  pFirst = this->pFirst;
  if ( this->pFirst )
  {
    while ( 1 )
    {
      pObject = pFirst->pBundle.pObject;
      v4 = pFirst;
      if ( pObject )
        pObject->NeedUpdate = 1;
      p_pChain = (__int64)&pFirst->pChain;
      if ( pFirst->pChain )
      {
        do
        {
          if ( v4->ChainHeight > v4->pSourceNode->Depth - topDepth )
            break;
          v4 = *(Scaleform::Render::BundleEntry **)p_pChain;
          v6 = *(_QWORD *)(*(_QWORD *)p_pChain + 8i64) == 0i64;
          p_pChain = *(_QWORD *)p_pChain + 8i64;
        }
        while ( !v6 );
      }
      v4->pChain = 0i64;
      v4->ChainHeight = 0;
      if ( pFirst == this->pLast )
        break;
      pFirst = pFirst->pNextPattern;
    }
  }
}

// File Line: 167
// RVA: 0x99A010
bool __fastcall Scaleform::Render::BundleEntryRangeMatcher::Match(
        Scaleform::Render::BundleEntryRangeMatcher *this,
        Scaleform::Render::BundleEntryRange *other,
        unsigned int *mergeDepth)
{
  unsigned int *v4; // r10
  Scaleform::Render::BundleEntryRange *v5; // r11
  Scaleform::Render::BundleEntry *pFirst; // rcx
  Scaleform::Render::BundleEntry *v8; // rdi
  bool v9; // zf
  Scaleform::Render::BundleEntry **pLastEntries; // r9
  unsigned int v11; // ebp
  int v12; // r13d
  unsigned __int64 v13; // rsi
  char v14; // r12
  Scaleform::Render::SortKeyInterface *pImpl; // rdx
  unsigned int Flags; // r8d
  Scaleform::Render::BundleEntry *v17; // rdx
  __int64 p_pChain; // rax
  Scaleform::Render::TreeCacheNode *pSourceNode; // rax
  unsigned __int64 LastEntryCount; // rax
  __int64 p_Key; // r14
  __int64 v22; // rax
  int v23; // eax
  Scaleform::Render::BundleEntry **v24; // [rsp+20h] [rbp-88h]
  __int64 *v25; // [rsp+28h] [rbp-80h]
  __int64 v26[7]; // [rsp+30h] [rbp-78h] BYREF
  Scaleform::Render::BundleEntry *v29; // [rsp+C8h] [rbp+20h]

  v4 = mergeDepth;
  v5 = other;
  if ( (other->Length & 0x7FFFFFFF) > (this->Length & 0x7FFFFFFF) )
    return 0;
  pFirst = this->pFirst;
  v8 = other->pFirst;
  v29 = this->pFirst;
  if ( !this->pFirst )
    return v8 == 0i64;
  v9 = v8 == 0i64;
  if ( v8 )
  {
    pLastEntries = this->pLastEntries;
    v11 = 0;
    v12 = 0;
    v24 = this->pLastEntries;
    v13 = 0i64;
    while ( 1 )
    {
      v14 = 0;
      if ( v12 != v11 )
        goto LABEL_28;
      pImpl = pFirst->Key.pImpl;
      Flags = pImpl->Flags;
      if ( (Flags & 0x8000) != 0 || pFirst->Key.Data != v8->Key.Data || pImpl != v8->Key.pImpl || (Flags & 0x2000) == 0 )
        goto LABEL_28;
      if ( v4 )
        break;
LABEL_24:
      if ( v8 == v5->pLast )
        v8 = 0i64;
      else
        v8 = v8->pNextPattern;
      v14 = 1;
LABEL_28:
      p_Key = (__int64)&pFirst->Key;
      if ( (pFirst->Key.pImpl->Flags & 0x1000) != 0 )
      {
        if ( v11 == 6 )
          return 0;
        v22 = v11++;
        v26[v22] = p_Key;
        if ( v14 )
          ++v12;
      }
      else if ( v11 )
      {
        v25 = &v26[v11 - 1];
        v23 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64))(**(_QWORD **)*v25 + 24i64))(
                *(_QWORD *)*v25,
                *(_QWORD *)(*v25 + 8),
                p_Key);
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
            *v25 = p_Key;
          }
        }
        pLastEntries = v24;
        v4 = mergeDepth;
        v5 = other;
      }
      if ( v29 != this->pLast )
      {
        pFirst = v29->pNextPattern;
        ++pLastEntries;
        ++v13;
        v29 = v29->pNextPattern;
        v24 = pLastEntries;
        if ( v8 )
          continue;
      }
      return v8 == 0i64;
    }
    if ( v13 >= this->LastEntryCount || (v17 = *pLastEntries) == 0i64 )
      v17 = pFirst;
    p_pChain = (__int64)&v17->pChain;
    if ( v17->pChain )
    {
      do
      {
        v17 = *(Scaleform::Render::BundleEntry **)p_pChain;
        v9 = *(_QWORD *)(*(_QWORD *)p_pChain + 8i64) == 0i64;
        p_pChain = *(_QWORD *)p_pChain + 8i64;
      }
      while ( !v9 );
    }
    pSourceNode = v17->pSourceNode;
    v17->pChain = v8;
    v17->ChainHeight = pSourceNode->Depth - *(_WORD *)v4;
    LastEntryCount = this->LastEntryCount;
    if ( v13 >= LastEntryCount )
    {
      if ( v13 >= 8 )
      {
LABEL_23:
        pFirst = v29;
        goto LABEL_24;
      }
      if ( LastEntryCount < v13 )
      {
        do
          this->pLastEntries[this->LastEntryCount++] = 0i64;
        while ( this->LastEntryCount < v13 );
      }
      ++this->LastEntryCount;
    }
    *pLastEntries = v8;
    goto LABEL_23;
  }
  return v9;
}

// File Line: 279
// RVA: 0x9BD660
void __fastcall Scaleform::Render::Bundle::UpdateChain(
        Scaleform::Render::Bundle *this,
        Scaleform::Render::BundleEntry *newTop)
{
  unsigned __int64 v2; // rbx
  Scaleform::Render::BundleEntry *i; // rdi
  unsigned __int64 Size; // r9
  unsigned __int64 v7; // r8
  Scaleform::Render::BundleEntry **v8; // rcx
  unsigned __int64 v9; // r8

  v2 = 0i64;
  this->NeedUpdate = 0;
  for ( i = newTop; i; ++v2 )
  {
    Size = this->Entries.Data.Size;
    if ( v2 >= Size || i != this->Entries.Data.Data[v2] )
    {
      if ( i->pBundle.pObject != this )
        goto LABEL_13;
      v7 = v2;
      if ( v2 < Size )
      {
        v8 = &this->Entries.Data.Data[v2];
        do
        {
          if ( *v8 == i )
            break;
          ++v7;
          ++v8;
        }
        while ( v7 < Size );
        if ( v7 > v2 )
          ((void (__fastcall *)(Scaleform::Render::Bundle *, unsigned __int64, unsigned __int64))this->vfptr[2].__vecDelDtor)(
            this,
            v2,
            v7 - v2);
      }
      if ( v2 >= this->Entries.Data.Size || i != this->Entries.Data.Data[v2] )
      {
LABEL_13:
        Scaleform::Render::BundleEntry::SetBundle(i, this, v2);
        ((void (__fastcall *)(Scaleform::Render::Bundle *, unsigned __int64, Scaleform::Render::BundleEntry *))this->vfptr[1].__vecDelDtor)(
          this,
          v2,
          i);
      }
    }
    i = i->pChain;
  }
  v9 = this->Entries.Data.Size;
  if ( v2 < v9 )
    ((void (__fastcall *)(Scaleform::Render::Bundle *, unsigned __int64, unsigned __int64))this->vfptr[2].__vecDelDtor)(
      this,
      v2,
      v9 - v2);
  this->pTop = newTop;
}

// File Line: 332
// RVA: 0x9950C0
void __fastcall Scaleform::Render::Bundle::InsertEntry(
        Scaleform::Render::Bundle *this,
        unsigned __int64 index,
        Scaleform::Render::BundleEntry *shape)
{
  Scaleform::ArrayLH<Scaleform::Render::BundleEntry *,2,Scaleform::ArrayDefaultPolicy> *p_Entries; // rbx
  unsigned __int64 Size; // r8
  Scaleform::Render::BundleEntry **v7; // rcx

  p_Entries = &this->Entries;
  Scaleform::ArrayData<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<Scaleform::GFx::AS2::Value *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value *,2>,Scaleform::ArrayDefaultPolicy> *)&this->Entries,
    this->Entries.Data.Size + 1);
  Size = p_Entries->Data.Size;
  if ( index < Size - 1 )
    memmove(&p_Entries->Data.Data[index + 1], &p_Entries->Data.Data[index], 8 * (Size - index) - 8);
  v7 = &p_Entries->Data.Data[index];
  if ( v7 )
    *v7 = shape;
}

// File Line: 338
// RVA: 0x9A97D0
void __fastcall Scaleform::Render::Bundle::RemoveEntries(
        Scaleform::Render::Bundle *this,
        unsigned __int64 index,
        unsigned __int64 count)
{
  unsigned int v6; // esi
  __int64 v7; // rax
  __int64 v8; // rdi
  __int64 v9; // rcx
  unsigned __int64 Size; // r8

  v6 = 0;
  if ( count )
  {
    v7 = 0i64;
    do
    {
      v8 = *((_QWORD *)&this->Entries.Data.Data[v7] + index);
      v9 = *(_QWORD *)(v8 + 40);
      if ( v9 )
      {
        if ( (*(_DWORD *)(v9 + 8))-- == 1 )
          (**(void (__fastcall ***)(__int64, __int64))v9)(v9, 1i64);
      }
      ++v6;
      *(_QWORD *)(v8 + 40) = 0i64;
      *(_WORD *)(v8 + 18) = 0;
      v7 = v6;
    }
    while ( v6 < count );
  }
  Size = this->Entries.Data.Size;
  if ( Size == count )
  {
    if ( Size && (this->Entries.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    {
      if ( this->Entries.Data.Data )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        this->Entries.Data.Data = 0i64;
      }
      this->Entries.Data.Policy.Capacity = 0i64;
    }
    this->Entries.Data.Size = 0i64;
  }
  else
  {
    memmove(&this->Entries.Data.Data[index], &this->Entries.Data.Data[index] + count, 8 * (Size - index - count));
    this->Entries.Data.Size -= count;
  }
}

