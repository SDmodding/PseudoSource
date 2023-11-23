// File Line: 26
// RVA: 0x784EB0
void __fastcall Scaleform::GFx::AS3::ValueStack::ValueStack(Scaleform::GFx::AS3::ValueStack *this)
{
  Scaleform::GFx::AS3::ValueStack::Page *v2; // rax
  Scaleform::GFx::AS3::Value *Values; // rax

  this->pCurrent = (Scaleform::GFx::AS3::Value *)-32i64;
  this->pStack = 0i64;
  this->pCurrentPage = 0i64;
  this->pReserved = 0i64;
  v2 = Scaleform::GFx::AS3::ValueStack::NewPage(this, 0x40u);
  this->pCurrentPage = v2;
  v2->pNext = 0i64;
  this->pCurrentPage->pPrev = 0i64;
  this->pCurrentPage->pCurrent = 0i64;
  Values = this->pCurrentPage->Values;
  this->pStack = Values;
  this->pCurrent = Values - 1;
  Scaleform::GFx::AS3::ValueStack::Reserve(this, 1u);
}

// File Line: 49
// RVA: 0x78FC20
void __fastcall Scaleform::GFx::AS3::ValueStack::~ValueStack(Scaleform::GFx::AS3::ValueStack *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::ValueStack::Page *pPrev; // rcx

  while ( this->pReserved )
  {
    this->pReserved = this->pReserved->pNext;
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  while ( this->pCurrentPage )
  {
    for ( ; this->pCurrent >= this->pCurrentPage->Values; --this->pCurrent )
    {
      pCurrent = this->pCurrent;
      if ( (this->pCurrent->Flags & 0x1F) > 9 )
      {
        if ( (this->pCurrent->Flags & 0x200) != 0 )
        {
          pWeakProxy = pCurrent->Bonus.pWeakProxy;
          if ( pWeakProxy->RefCount-- == 1 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          pCurrent->Flags &= 0xFFFFFDE0;
          pCurrent->Bonus.pWeakProxy = 0i64;
          pCurrent->value.VS._1.VStr = 0i64;
          pCurrent->value.VS._2.VObj = 0i64;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(this->pCurrent);
        }
      }
    }
    pPrev = this->pCurrentPage->pPrev;
    this->pCurrentPage = pPrev;
    if ( pPrev )
    {
      this->pCurrent = pPrev->pCurrent;
      this->pStack = pPrev->pFirst;
    }
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 80
// RVA: 0x813BC0
void __fastcall Scaleform::GFx::AS3::ValueStack::Reserve(Scaleform::GFx::AS3::ValueStack *this, unsigned __int16 n)
{
  Scaleform::GFx::AS3::ValueStack::Page *pCurrentPage; // r8
  Scaleform::GFx::AS3::Value *pCurrent; // rcx
  Scaleform::GFx::AS3::ValueStack::Page *v5; // rax

  pCurrentPage = this->pCurrentPage;
  pCurrent = this->pCurrent;
  if ( &pCurrent[n] >= &pCurrentPage->Values[pCurrentPage->PageSize] )
  {
    v5 = Scaleform::GFx::AS3::ValueStack::NewPage(this, n);
    v5->pNext = 0i64;
    v5->pPrev = this->pCurrentPage;
    this->pCurrentPage->pNext = v5;
    this->pCurrentPage->pCurrent = this->pCurrent;
    this->pCurrentPage = v5;
    v5 = (Scaleform::GFx::AS3::ValueStack::Page *)((char *)v5 + 40);
    this->pStack = (Scaleform::GFx::AS3::Value *)v5;
    this->pCurrent = v5[-1].Values;
    ++this->pCurrentPage->ReservationNum;
  }
  else
  {
    this->pStack = pCurrent + 1;
    ++pCurrentPage->ReservationNum;
  }
}

// File Line: 119
// RVA: 0x811140
void __fastcall Scaleform::GFx::AS3::ValueStack::ReleaseReserved(
        Scaleform::GFx::AS3::ValueStack *this,
        Scaleform::GFx::AS3::Value *first)
{
  Scaleform::GFx::AS3::ValueStack::Page *pCurrentPage; // r9
  Scaleform::GFx::AS3::Value *pCurrent; // r10
  Scaleform::GFx::AS3::ValueStack::Page *pPrev; // rax
  Scaleform::GFx::AS3::ValueStack::Page *v5; // rax
  Scaleform::GFx::AS3::Value *Values; // rax
  Scaleform::GFx::AS3::Value::V1U *p_value; // r9
  bool v8; // zf
  Scaleform::GFx::AS3::Value *v9; // rdx

  --this->pCurrentPage->ReservationNum;
  pCurrentPage = this->pCurrentPage;
  if ( pCurrentPage->ReservationNum || !pCurrentPage->pPrev )
  {
    this->pStack = first;
  }
  else
  {
    pCurrent = this->pCurrent;
    pPrev = pCurrentPage->pPrev;
    this->pCurrentPage = pPrev;
    pPrev->pNext = 0i64;
    v5 = this->pCurrentPage;
    this->pCurrent = v5->pCurrent;
    this->pStack = v5->pFirst;
    pCurrentPage->pNext = this->pReserved;
    this->pReserved = pCurrentPage;
    Values = pCurrentPage->Values;
    if ( pCurrentPage->Values <= pCurrent )
    {
      p_value = (Scaleform::GFx::AS3::Value::V1U *)&pCurrentPage->Values[0].value;
      do
      {
        v8 = this->pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
        v9 = this->pCurrent;
        if ( !v8 )
        {
          v9->Flags = Values->Flags;
          v9->Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)p_value[-1].VStr;
          v9->value.VS._1 = *p_value;
          v9->value.VS._2.VObj = p_value[1].VObj;
          Values->Flags = 0;
        }
        ++Values;
        p_value += 4;
      }
      while ( Values <= pCurrent );
    }
  }
}

// File Line: 152
// RVA: 0x807800
void __fastcall Scaleform::GFx::AS3::ValueStack::PopReserved(
        Scaleform::GFx::AS3::ValueStack *this,
        Scaleform::GFx::AS3::Value *current,
        bool retVal)
{
  Scaleform::GFx::AS3::ValueStack::Page *pCurrentPage; // rcx
  Scaleform::GFx::AS3::Value *Values; // r15
  Scaleform::GFx::AS3::Value *v8; // r11
  unsigned int v9; // r9d
  Scaleform::GFx::AS3::Value::Extra v10; // rax
  Scaleform::GFx::AS3::Value::V1U v11; // rdx
  Scaleform::GFx::AS3::Value::V2U v12; // r8
  Scaleform::GFx::AS3::Value *j; // r14
  Scaleform::GFx::AS3::Value *v14; // rdi
  Scaleform::GFx::AS3::WeakProxy *v15; // rdx
  bool v16; // zf
  Scaleform::GFx::AS3::Value *pCurrent; // r11
  Scaleform::GFx::AS3::Value::V1U v18; // rdx
  Scaleform::GFx::AS3::Value::V2U v19; // r8
  unsigned int Flags; // r9d
  Scaleform::GFx::AS3::Value::Extra v21; // rax
  Scaleform::GFx::AS3::Value *i; // r15
  Scaleform::GFx::AS3::Value *v23; // rdi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx

  pCurrentPage = this->pCurrentPage;
  Values = pCurrentPage->Values;
  if ( current < pCurrentPage->Values || current >= &pCurrentPage->Values[pCurrentPage->PageSize] )
  {
    if ( retVal )
    {
      pCurrent = this->pCurrent;
      if ( this->pCurrent >= &Values[retVal] )
      {
        v18 = pCurrentPage->Values[0].value.VS._1;
        v19.VObj = (Scaleform::GFx::AS3::Object *)pCurrentPage->Values[0].value.VS._2;
        Flags = Values->Flags;
        v21.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)pCurrentPage->Values[0].Bonus;
        Values->Flags = pCurrent->Flags;
        pCurrentPage->Values[0].Bonus.pWeakProxy = pCurrent->Bonus.pWeakProxy;
        pCurrentPage->Values[0].value.VS._1.VStr = pCurrent->value.VS._1.VStr;
        pCurrentPage->Values[0].value.VS._2.VObj = pCurrent->value.VS._2.VObj;
        pCurrent->value.VS._1 = v18;
        pCurrent->value.VS._2 = v19;
        pCurrent->Flags = Flags;
        pCurrent->Bonus = v21;
      }
    }
    for ( i = &Values[retVal]; this->pCurrent >= i; --this->pCurrent )
    {
      v23 = this->pCurrent;
      if ( (this->pCurrent->Flags & 0x1F) > 9 )
      {
        if ( (this->pCurrent->Flags & 0x200) != 0 )
        {
          pWeakProxy = v23->Bonus.pWeakProxy;
          v16 = pWeakProxy->RefCount-- == 1;
          if ( v16 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v23->Flags &= 0xFFFFFDE0;
          v23->Bonus.pWeakProxy = 0i64;
          v23->value.VS._1.VStr = 0i64;
          v23->value.VS._2.VObj = 0i64;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(this->pCurrent);
        }
      }
    }
  }
  else
  {
    if ( retVal )
    {
      v8 = this->pCurrent;
      if ( this->pCurrent > &current[retVal] )
      {
        v9 = current->Flags;
        v10.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)current->Bonus;
        v11 = current->value.VS._1;
        v12.VObj = (Scaleform::GFx::AS3::Object *)current->value.VS._2;
        current->Flags = v8->Flags;
        current->Bonus.pWeakProxy = v8->Bonus.pWeakProxy;
        current->value.VS._1.VStr = v8->value.VS._1.VStr;
        current->value.VS._2.VObj = v8->value.VS._2.VObj;
        v8->value.VS._1 = v11;
        v8->value.VS._2 = v12;
        v8->Flags = v9;
        v8->Bonus = v10;
      }
    }
    for ( j = &current[retVal]; this->pCurrent > j; --this->pCurrent )
    {
      v14 = this->pCurrent;
      if ( (this->pCurrent->Flags & 0x1F) > 9 )
      {
        if ( (this->pCurrent->Flags & 0x200) != 0 )
        {
          v15 = v14->Bonus.pWeakProxy;
          v16 = v15->RefCount-- == 1;
          if ( v16 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v14->Flags &= 0xFFFFFDE0;
          v14->Bonus.pWeakProxy = 0i64;
          v14->value.VS._1.VStr = 0i64;
          v14->value.VS._2.VObj = 0i64;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(this->pCurrent);
        }
      }
    }
  }
}

// File Line: 193
// RVA: 0x8023C0
Scaleform::GFx::AS3::ValueStack::Page *__fastcall Scaleform::GFx::AS3::ValueStack::NewPage(
        Scaleform::GFx::AS3::ValueStack *this,
        unsigned __int16 pageSize)
{
  Scaleform::GFx::AS3::ValueStack::Page *result; // rax
  unsigned __int16 v3; // bx
  Scaleform::GFx::AS3::ValueStack::Page *pNext; // rdx
  Scaleform::GFx::AS3::ValueStack::Page *v5; // rdx

  result = this->pReserved;
  if ( result )
  {
    while ( result->PageSize < pageSize )
    {
      result = result->pNext;
      if ( !result )
        goto LABEL_4;
    }
    if ( result == this->pReserved )
    {
      pNext = result->pNext;
      this->pReserved = pNext;
      if ( pNext )
        pNext->pPrev = 0i64;
      result->pNext = 0i64;
    }
    else
    {
      result->pPrev->pNext = result->pNext;
      v5 = result->pNext;
      if ( v5 )
        v5->pPrev = result->pPrev;
      result->pNext = 0i64;
      result->pPrev = 0i64;
    }
  }
  else
  {
LABEL_4:
    v3 = 64;
    if ( pageSize > 0x40u )
      v3 = pageSize;
    result = (Scaleform::GFx::AS3::ValueStack::Page *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        this,
                                                        32i64 * (v3 - 1) + 72,
                                                        0i64);
    result->PageSize = v3;
    result->ReservationNum = 0;
  }
  return result;
}

// File Line: 253
// RVA: 0x78FB40
void __fastcall Scaleform::GFx::AS3::ValueRegisterFile::~ValueRegisterFile(
        Scaleform::GFx::AS3::ValueRegisterFile *this)
{
  unsigned __int16 i; // si
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx

  while ( this->pReserved )
  {
    this->pReserved = this->pReserved->pNext;
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  for ( i = 0; i < this->ReservedNum; ++i )
  {
    v3 = &this->pRF[i];
    if ( (v3->Flags & 0x1F) > 9 )
    {
      if ( (v3->Flags & 0x200) != 0 )
      {
        pWeakProxy = v3->Bonus.pWeakProxy;
        if ( pWeakProxy->RefCount-- == 1 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v3->Flags &= 0xFFFFFDE0;
        v3->Bonus.pWeakProxy = 0i64;
        v3->value.VS._1.VStr = 0i64;
        v3->value.VS._2.VObj = 0i64;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&this->pRF[i]);
      }
    }
  }
  if ( this->pCurrentPage )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 277
// RVA: 0x813AB0
void __fastcall Scaleform::GFx::AS3::ValueRegisterFile::Reserve(
        Scaleform::GFx::AS3::ValueRegisterFile *this,
        unsigned __int16 n)
{
  int v2; // ebp
  __int16 v4; // si
  __int64 ReservedNum; // rcx
  __int64 v6; // rdi
  Scaleform::GFx::AS3::ValueRegisterFile::Page *pCurrentPage; // rdx
  Scaleform::GFx::AS3::Value *Values; // rax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v9; // rax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v10; // rdx
  __int64 v11; // rax
  __int64 v12; // r8
  Scaleform::GFx::AS3::Value *v13; // rdx

  v2 = n;
  v4 = 0;
  ReservedNum = this->ReservedNum;
  v6 = n;
  pCurrentPage = this->pCurrentPage;
  if ( (int)ReservedNum + v2 > pCurrentPage->PageSize )
  {
    v9 = Scaleform::GFx::AS3::ValueRegisterFile::NewPage(this, v2);
    v9->pNext = 0i64;
    v9->pPrev = this->pCurrentPage;
    this->pCurrentPage->pNext = v9;
    this->pCurrentPage->ReservedNum = this->ReservedNum;
    this->pCurrentPage->pCurrent = this->pRF;
    this->pCurrentPage = v9;
    Values = v9->Values;
    this->ReservedNum = v2;
  }
  else
  {
    v4 = ReservedNum - (((char *)this->pRF - (char *)pCurrentPage - 32) >> 5);
    Values = &pCurrentPage->Values[ReservedNum];
    this->ReservedNum = v2 + ReservedNum;
  }
  this->pRF = Values;
  v10 = this->pCurrentPage;
  *((_WORD *)&v10->Values[v10->PageSize].Flags + v10->CurrPos++) = v4;
  if ( (_DWORD)v6 )
  {
    v11 = 0i64;
    v12 = v6;
    do
    {
      v13 = &this->pRF[v11];
      if ( v13 )
      {
        v13->Flags = 0;
        v13->Bonus.pWeakProxy = 0i64;
      }
      ++v11;
      --v12;
    }
    while ( v12 );
  }
}

// File Line: 319
// RVA: 0x811000
void __fastcall Scaleform::GFx::AS3::ValueRegisterFile::ReleaseReserved(
        Scaleform::GFx::AS3::ValueRegisterFile *this,
        unsigned __int16 n)
{
  unsigned __int16 v4; // di
  int v5; // ebp
  Scaleform::GFx::AS3::Value *v6; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *pCurrentPage; // rdx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v10; // rdx
  unsigned __int16 MaxReservedPageSize; // cx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v12; // rax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *pPrev; // rdx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v14; // rax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v15; // rcx

  v4 = 0;
  v5 = n;
  if ( n )
  {
    do
    {
      v6 = &this->pRF[v4];
      if ( (v6->Flags & 0x1F) > 9 )
      {
        if ( (v6->Flags & 0x200) != 0 )
        {
          pWeakProxy = v6->Bonus.pWeakProxy;
          if ( pWeakProxy->RefCount-- == 1 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v6->Flags &= 0xFFFFFDE0;
          v6->Bonus.pWeakProxy = 0i64;
          v6->value.VS._1.VStr = 0i64;
          v6->value.VS._2.VObj = 0i64;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&this->pRF[v4]);
        }
      }
      ++v4;
    }
    while ( v4 < v5 );
  }
  this->ReservedNum -= n;
  pCurrentPage = this->pCurrentPage;
  this->pRF -= *((unsigned __int16 *)&pCurrentPage->Values[pCurrentPage->PageSize].Flags + --pCurrentPage->CurrPos);
  if ( !this->ReservedNum )
  {
    v10 = this->pCurrentPage;
    if ( v10->pPrev )
    {
      MaxReservedPageSize = this->MaxReservedPageSize;
      v12 = this->pCurrentPage;
      if ( MaxReservedPageSize < v10->PageSize )
        MaxReservedPageSize = v10->PageSize;
      this->MaxReservedPageSize = MaxReservedPageSize;
      pPrev = v10->pPrev;
      v12->pPrev = 0i64;
      this->pCurrentPage->pNext = this->pReserved;
      v14 = this->pCurrentPage;
      this->pCurrentPage = pPrev;
      this->pReserved = v14;
      pPrev->pNext = 0i64;
      v15 = this->pCurrentPage;
      this->ReservedNum = v15->ReservedNum;
      this->pRF = v15->pCurrent;
    }
  }
}

// File Line: 350
// RVA: 0x7B0440
Scaleform::GFx::AS3::ValueRegisterFile::Page *__fastcall Scaleform::GFx::AS3::ValueRegisterFile::AllocPage(
        Scaleform::GFx::AS3::ValueRegisterFile *this,
        unsigned __int16 pageSize)
{
  unsigned __int16 MaxAllocatedPageSize; // cx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *result; // rax

  MaxAllocatedPageSize = this->MaxAllocatedPageSize;
  if ( pageSize <= MaxAllocatedPageSize )
  {
    v4 = 64;
    if ( MaxAllocatedPageSize > 0x40u )
      v4 = MaxAllocatedPageSize;
  }
  else
  {
    v4 = ((((pageSize + 64) >> 31) & 0x3F) + pageSize + 64) & 0xFFC0;
  }
  this->MaxAllocatedPageSize = v4;
  v5 = v4;
  result = (Scaleform::GFx::AS3::ValueRegisterFile::Page *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             this,
                                                             2 * (v4 + 16 * (v4 - 1 + 2i64)),
                                                             0i64);
  *(_DWORD *)&result->PageSize = v5;
  result->CurrPos = 0;
  result->pCurrent = 0i64;
  return result;
}

// File Line: 370
// RVA: 0x802350
Scaleform::GFx::AS3::ValueRegisterFile::Page *__fastcall Scaleform::GFx::AS3::ValueRegisterFile::NewPage(
        Scaleform::GFx::AS3::ValueRegisterFile *this,
        unsigned __int16 pageSize)
{
  Scaleform::GFx::AS3::ValueRegisterFile::Page *result; // rax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *pNext; // rdx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v4; // rdx

  if ( pageSize > this->MaxReservedPageSize )
    return Scaleform::GFx::AS3::ValueRegisterFile::AllocPage(this, pageSize);
  result = this->pReserved;
  if ( !result )
    return Scaleform::GFx::AS3::ValueRegisterFile::AllocPage(this, pageSize);
  while ( result->PageSize < pageSize )
  {
    result = result->pNext;
    if ( !result )
      return Scaleform::GFx::AS3::ValueRegisterFile::AllocPage(this, pageSize);
  }
  if ( result == this->pReserved )
  {
    pNext = result->pNext;
    this->pReserved = pNext;
    if ( pNext )
      pNext->pPrev = 0i64;
    result->pNext = 0i64;
  }
  else
  {
    result->pPrev->pNext = result->pNext;
    v4 = result->pNext;
    if ( v4 )
      v4->pPrev = result->pPrev;
    result->pNext = 0i64;
    result->pPrev = 0i64;
  }
  return result;
}

