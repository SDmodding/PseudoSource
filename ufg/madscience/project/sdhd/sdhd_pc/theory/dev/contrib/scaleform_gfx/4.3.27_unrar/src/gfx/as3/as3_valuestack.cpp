// File Line: 26
// RVA: 0x784EB0
void __fastcall Scaleform::GFx::AS3::ValueStack::ValueStack(Scaleform::GFx::AS3::ValueStack *this)
{
  Scaleform::GFx::AS3::ValueStack *v1; // rbx
  Scaleform::GFx::AS3::ValueStack::Page *v2; // rax
  signed __int64 v3; // rax

  v1 = this;
  this->pCurrent = (Scaleform::GFx::AS3::Value *)-32i64;
  this->pStack = 0i64;
  this->pCurrentPage = 0i64;
  this->pReserved = 0i64;
  v2 = Scaleform::GFx::AS3::ValueStack::NewPage(this, 0x40u);
  v1->pCurrentPage = v2;
  v2->pNext = 0i64;
  v1->pCurrentPage->pPrev = 0i64;
  v1->pCurrentPage->pCurrent = 0i64;
  v3 = (signed __int64)v1->pCurrentPage->Values;
  v1->pStack = (Scaleform::GFx::AS3::Value *)v3;
  v1->pCurrent = (Scaleform::GFx::AS3::Value *)(v3 - 32);
  Scaleform::GFx::AS3::ValueStack::Reserve(v1, 1u);
}

// File Line: 49
// RVA: 0x78FC20
void __fastcall Scaleform::GFx::AS3::ValueStack::~ValueStack(Scaleform::GFx::AS3::ValueStack *this)
{
  Scaleform::GFx::AS3::ValueStack *v1; // rdi
  Scaleform::GFx::AS3::Value *v2; // rbx
  Scaleform::GFx::AS3::WeakProxy *v3; // rdx
  bool v4; // zf
  Scaleform::GFx::AS3::ValueStack::Page *v5; // rcx

  v1 = this;
  while ( v1->pReserved )
  {
    v1->pReserved = v1->pReserved->pNext;
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
  while ( v1->pCurrentPage )
  {
    for ( ; v1->pCurrent >= v1->pCurrentPage->Values; --v1->pCurrent )
    {
      v2 = v1->pCurrent;
      if ( (v1->pCurrent->Flags & 0x1F) > 9 )
      {
        if ( (v1->pCurrent->Flags >> 9) & 1 )
        {
          v3 = v2->Bonus.pWeakProxy;
          v4 = v3->RefCount-- == 1;
          if ( v4 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v2->Flags &= 0xFFFFFDE0;
          v2->Bonus.pWeakProxy = 0i64;
          v2->value.VNumber = 0.0;
          v2->value.VS._2.VObj = 0i64;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(v1->pCurrent);
        }
      }
    }
    v5 = v1->pCurrentPage->pPrev;
    v1->pCurrentPage = v5;
    if ( v5 )
    {
      v1->pCurrent = v5->pCurrent;
      v1->pStack = v5->pFirst;
    }
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 80
// RVA: 0x813BC0
void __fastcall Scaleform::GFx::AS3::ValueStack::Reserve(Scaleform::GFx::AS3::ValueStack *this, unsigned __int16 n)
{
  Scaleform::GFx::AS3::ValueStack::Page *v2; // r8
  Scaleform::GFx::AS3::ValueStack *v3; // rbx
  Scaleform::GFx::AS3::Value *v4; // rcx
  Scaleform::GFx::AS3::ValueStack::Page *v5; // rax

  v2 = this->pCurrentPage;
  v3 = this;
  v4 = this->pCurrent;
  if ( &v4[n] >= &v2->Values[v2->PageSize] )
  {
    v5 = Scaleform::GFx::AS3::ValueStack::NewPage(v3, n);
    v5->pNext = 0i64;
    v5->pPrev = v3->pCurrentPage;
    v3->pCurrentPage->pNext = v5;
    v3->pCurrentPage->pCurrent = v3->pCurrent;
    v3->pCurrentPage = v5;
    v5 = (Scaleform::GFx::AS3::ValueStack::Page *)((char *)v5 + 40);
    v3->pStack = (Scaleform::GFx::AS3::Value *)v5;
    v3->pCurrent = v5[-1].Values;
    ++v3->pCurrentPage->ReservationNum;
  }
  else
  {
    v3->pStack = v4 + 1;
    ++v2->ReservationNum;
  }
}

// File Line: 119
// RVA: 0x811140
void __fastcall Scaleform::GFx::AS3::ValueStack::ReleaseReserved(Scaleform::GFx::AS3::ValueStack *this, Scaleform::GFx::AS3::Value *first)
{
  Scaleform::GFx::AS3::ValueStack::Page *v2; // r9
  Scaleform::GFx::AS3::Value *v3; // r10
  Scaleform::GFx::AS3::ValueStack::Page *v4; // rax
  Scaleform::GFx::AS3::ValueStack::Page *v5; // rax
  Scaleform::GFx::AS3::Value *v6; // rax
  long double *v7; // r9
  bool v8; // zf
  Scaleform::GFx::AS3::Value *v9; // rdx

  --this->pCurrentPage->ReservationNum;
  v2 = this->pCurrentPage;
  if ( v2->ReservationNum || !v2->pPrev )
  {
    this->pStack = first;
  }
  else
  {
    v3 = this->pCurrent;
    v4 = v2->pPrev;
    this->pCurrentPage = v4;
    v4->pNext = 0i64;
    v5 = this->pCurrentPage;
    this->pCurrent = v5->pCurrent;
    this->pStack = v5->pFirst;
    v2->pNext = this->pReserved;
    this->pReserved = v2;
    v6 = v2->Values;
    if ( v2->Values <= v3 )
    {
      v7 = &v2->Values[0].value.VNumber;
      do
      {
        v8 = this->pCurrent == (Scaleform::GFx::AS3::Value *)-32i64;
        ++this->pCurrent;
        v9 = this->pCurrent;
        if ( !v8 )
        {
          v9->Flags = v6->Flags;
          v9->Bonus.pWeakProxy = *(Scaleform::GFx::AS3::WeakProxy **)(v7 - 1);
          v9->value.VNumber = *v7;
          v9->value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v7[1];
          v6->Flags = 0;
        }
        ++v6;
        v7 += 4;
      }
      while ( v6 <= v3 );
    }
  }
}

// File Line: 152
// RVA: 0x807800
void __fastcall Scaleform::GFx::AS3::ValueStack::PopReserved(Scaleform::GFx::AS3::ValueStack *this, Scaleform::GFx::AS3::Value *current, bool retVal)
{
  Scaleform::GFx::AS3::ValueStack *v3; // rbx
  Scaleform::GFx::AS3::ValueStack::Page *v4; // rcx
  bool v5; // r10
  Scaleform::GFx::AS3::Value *v6; // r15
  Scaleform::GFx::AS3::Value *v7; // r14
  Scaleform::GFx::AS3::Value *v8; // r11
  unsigned int v9; // er9
  Scaleform::GFx::AS3::Value::Extra v10; // rax
  long double v11; // rdx
  Scaleform::GFx::AS3::Value::V2U v12; // r8
  unsigned __int64 j; // r14
  Scaleform::GFx::AS3::Value *v14; // rdi
  Scaleform::GFx::AS3::WeakProxy *v15; // rdx
  bool v16; // zf
  Scaleform::GFx::AS3::Value *v17; // r11
  long double v18; // rdx
  Scaleform::GFx::AS3::Value::V2U v19; // r8
  unsigned int v20; // er9
  Scaleform::GFx::AS3::Value::Extra v21; // rax
  unsigned __int64 i; // r15
  Scaleform::GFx::AS3::Value *v23; // rdi
  Scaleform::GFx::AS3::WeakProxy *v24; // rdx

  v3 = this;
  v4 = this->pCurrentPage;
  v5 = retVal;
  v6 = v4->Values;
  v7 = current;
  if ( current < v4->Values || current >= &v4->Values[v4->PageSize] )
  {
    if ( retVal )
    {
      v17 = v3->pCurrent;
      if ( v3->pCurrent >= &v6[retVal] )
      {
        v18 = v4->Values[0].value.VNumber;
        v19.VObj = (Scaleform::GFx::AS3::Object *)v4->Values[0].value.VS._2;
        v20 = v6->Flags;
        v21.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v4->Values[0].Bonus;
        v6->Flags = v17->Flags;
        v4->Values[0].Bonus.pWeakProxy = v17->Bonus.pWeakProxy;
        v4->Values[0].value.VNumber = v17->value.VNumber;
        v4->Values[0].value.VS._2.VObj = v17->value.VS._2.VObj;
        v17->value.VNumber = v18;
        v17->value.VS._2 = v19;
        v17->Flags = v20;
        v17->Bonus = v21;
      }
    }
    for ( i = (unsigned __int64)&v6[v5]; v3->pCurrent >= (Scaleform::GFx::AS3::Value *)i; --v3->pCurrent )
    {
      v23 = v3->pCurrent;
      if ( (v3->pCurrent->Flags & 0x1F) > 9 )
      {
        if ( (v3->pCurrent->Flags >> 9) & 1 )
        {
          v24 = v23->Bonus.pWeakProxy;
          v16 = v24->RefCount-- == 1;
          if ( v16 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v23->Flags &= 0xFFFFFDE0;
          v23->Bonus.pWeakProxy = 0i64;
          v23->value.VNumber = 0.0;
          v23->value.VS._2.VObj = 0i64;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(v3->pCurrent);
        }
      }
    }
  }
  else
  {
    if ( retVal )
    {
      v8 = v3->pCurrent;
      if ( v3->pCurrent > &current[retVal] )
      {
        v9 = current->Flags;
        v10.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)current->Bonus;
        v11 = current->value.VNumber;
        v12.VObj = (Scaleform::GFx::AS3::Object *)v7->value.VS._2;
        v7->Flags = v8->Flags;
        v7->Bonus.pWeakProxy = v8->Bonus.pWeakProxy;
        v7->value.VNumber = v8->value.VNumber;
        v7->value.VS._2.VObj = v8->value.VS._2.VObj;
        v8->value.VNumber = v11;
        v8->value.VS._2 = v12;
        v8->Flags = v9;
        v8->Bonus = v10;
      }
    }
    for ( j = (unsigned __int64)&v7[v5]; v3->pCurrent > (Scaleform::GFx::AS3::Value *)j; --v3->pCurrent )
    {
      v14 = v3->pCurrent;
      if ( (v3->pCurrent->Flags & 0x1F) > 9 )
      {
        if ( (v3->pCurrent->Flags >> 9) & 1 )
        {
          v15 = v14->Bonus.pWeakProxy;
          v16 = v15->RefCount-- == 1;
          if ( v16 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v14->Flags &= 0xFFFFFDE0;
          v14->Bonus.pWeakProxy = 0i64;
          v14->value.VNumber = 0.0;
          v14->value.VS._2.VObj = 0i64;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(v3->pCurrent);
        }
      }
    }
  }
}

// File Line: 193
// RVA: 0x8023C0
Scaleform::GFx::AS3::ValueStack::Page *__fastcall Scaleform::GFx::AS3::ValueStack::NewPage(Scaleform::GFx::AS3::ValueStack *this, unsigned __int16 pageSize)
{
  Scaleform::GFx::AS3::ValueStack::Page *result; // rax
  unsigned __int16 v3; // bx
  Scaleform::GFx::AS3::ValueStack::Page *v4; // rdx
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
      v4 = result->pNext;
      this->pReserved = v4;
      if ( v4 )
        v4->pPrev = 0i64;
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
void __fastcall Scaleform::GFx::AS3::ValueRegisterFile::~ValueRegisterFile(Scaleform::GFx::AS3::ValueRegisterFile *this)
{
  Scaleform::GFx::AS3::ValueRegisterFile *v1; // rdi
  unsigned __int16 i; // si
  signed __int64 v3; // rbx
  _DWORD *v4; // rdx
  bool v5; // zf

  v1 = this;
  while ( v1->pReserved )
  {
    v1->pReserved = v1->pReserved->pNext;
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
  for ( i = 0; i < v1->ReservedNum; ++i )
  {
    v3 = (signed __int64)&v1->pRF[i];
    if ( (*(_BYTE *)v3 & 0x1F) > 9 )
    {
      if ( (*(_DWORD *)v3 >> 9) & 1 )
      {
        v4 = *(_DWORD **)(v3 + 8);
        v5 = (*v4)-- == 1;
        if ( v5 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        *(_DWORD *)v3 &= 0xFFFFFDE0;
        *(_QWORD *)(v3 + 8) = 0i64;
        *(_QWORD *)(v3 + 16) = 0i64;
        *(_QWORD *)(v3 + 24) = 0i64;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v1->pRF[i]);
      }
    }
  }
  if ( v1->pCurrentPage )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 277
// RVA: 0x813AB0
void __fastcall Scaleform::GFx::AS3::ValueRegisterFile::Reserve(Scaleform::GFx::AS3::ValueRegisterFile *this, unsigned __int16 n)
{
  int v2; // ebp
  Scaleform::GFx::AS3::ValueRegisterFile *v3; // rbx
  unsigned __int16 v4; // si
  __int64 v5; // rcx
  __int64 v6; // rdi
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v7; // rdx
  signed __int64 v8; // rax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v9; // rax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v10; // rdx
  __int64 v11; // rax
  __int64 v12; // r8
  Scaleform::GFx::AS3::Value *v13; // rdx

  v2 = n;
  v3 = this;
  v4 = 0;
  v5 = this->ReservedNum;
  v6 = n;
  v7 = v3->pCurrentPage;
  if ( (signed int)v5 + v2 > v7->PageSize )
  {
    v9 = Scaleform::GFx::AS3::ValueRegisterFile::NewPage(v3, v2);
    v9->pNext = 0i64;
    v9->pPrev = v3->pCurrentPage;
    v3->pCurrentPage->pNext = v9;
    v3->pCurrentPage->ReservedNum = v3->ReservedNum;
    v3->pCurrentPage->pCurrent = v3->pRF;
    v3->pCurrentPage = v9;
    v8 = (signed __int64)v9->Values;
    v3->ReservedNum = v2;
  }
  else
  {
    v4 = v5 - ((_QWORD)((char *)v3->pRF - (char *)v7 - 32) >> 5);
    v8 = (signed __int64)v7 + 32 * (v5 + 1);
    v3->ReservedNum = v2 + v5;
  }
  v3->pRF = (Scaleform::GFx::AS3::Value *)v8;
  v10 = v3->pCurrentPage;
  *(&v10->CurrPos + v10->CurrPos++ + 16 * (v10->PageSize + 1i64)) = v4;
  if ( (_DWORD)v6 )
  {
    v11 = 0i64;
    v12 = v6;
    do
    {
      v13 = &v3->pRF[v11];
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
void __fastcall Scaleform::GFx::AS3::ValueRegisterFile::ReleaseReserved(Scaleform::GFx::AS3::ValueRegisterFile *this, unsigned __int16 n)
{
  unsigned __int16 v2; // r14
  Scaleform::GFx::AS3::ValueRegisterFile *v3; // rsi
  unsigned __int16 v4; // di
  signed int i; // ebp
  signed __int64 v6; // rbx
  _DWORD *v7; // rdx
  bool v8; // zf
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v9; // rdx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v10; // rdx
  unsigned __int16 v11; // cx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v12; // rax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v13; // rdx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v14; // rax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v15; // rcx

  v2 = n;
  v3 = this;
  v4 = 0;
  for ( i = n; v4 < i; ++v4 )
  {
    v6 = (signed __int64)&v3->pRF[v4];
    if ( (*(_BYTE *)v6 & 0x1F) > 9 )
    {
      if ( (*(_DWORD *)v6 >> 9) & 1 )
      {
        v7 = *(_DWORD **)(v6 + 8);
        v8 = (*v7)-- == 1;
        if ( v8 )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        *(_DWORD *)v6 &= 0xFFFFFDE0;
        *(_QWORD *)(v6 + 8) = 0i64;
        *(_QWORD *)(v6 + 16) = 0i64;
        *(_QWORD *)(v6 + 24) = 0i64;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v3->pRF[v4]);
      }
    }
  }
  v3->ReservedNum -= v2;
  v9 = v3->pCurrentPage;
  v3->pRF -= *((unsigned __int16 *)&v9->Values[0].Flags + --v9->CurrPos + 16i64 * v9->PageSize);
  if ( !v3->ReservedNum )
  {
    v10 = v3->pCurrentPage;
    if ( v10->pPrev )
    {
      v11 = v3->MaxReservedPageSize;
      v12 = v3->pCurrentPage;
      if ( v11 < v10->PageSize )
        v11 = v10->PageSize;
      v3->MaxReservedPageSize = v11;
      v13 = v10->pPrev;
      v12->pPrev = 0i64;
      v3->pCurrentPage->pNext = v3->pReserved;
      v14 = v3->pCurrentPage;
      v3->pCurrentPage = v13;
      v3->pReserved = v14;
      v13->pNext = 0i64;
      v15 = v3->pCurrentPage;
      v3->ReservedNum = v15->ReservedNum;
      v3->pRF = v15->pCurrent;
    }
  }
}

// File Line: 350
// RVA: 0x7B0440
Scaleform::GFx::AS3::ValueRegisterFile::Page *__fastcall Scaleform::GFx::AS3::ValueRegisterFile::AllocPage(Scaleform::GFx::AS3::ValueRegisterFile *this, unsigned __int16 pageSize)
{
  Scaleform::GFx::AS3::ValueRegisterFile *v2; // r11
  unsigned __int16 v3; // cx
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  Scaleform::GFx::AS3::ValueRegisterFile::Page *result; // rax

  v2 = this;
  v3 = this->MaxAllocatedPageSize;
  if ( pageSize <= v3 )
  {
    v4 = 64;
    if ( v3 > 0x40u )
      v4 = v3;
  }
  else
  {
    v4 = ((((pageSize + 64) >> 31) & 0x3F) + pageSize + 64) & 0xFFC0;
  }
  v2->MaxAllocatedPageSize = v4;
  v5 = v4;
  result = (Scaleform::GFx::AS3::ValueRegisterFile::Page *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             v2,
                                                             2 * (v4 + 16 * (v4 - 1 + 2i64)),
                                                             0i64);
  result->PageSize = v5;
  result->ReservedNum = 0;
  result->CurrPos = 0;
  result->pCurrent = 0i64;
  return result;
}

// File Line: 370
// RVA: 0x802350
Scaleform::GFx::AS3::ValueRegisterFile::Page *__fastcall Scaleform::GFx::AS3::ValueRegisterFile::NewPage(Scaleform::GFx::AS3::ValueRegisterFile *this, unsigned __int16 pageSize)
{
  Scaleform::GFx::AS3::ValueRegisterFile::Page *result; // rax
  Scaleform::GFx::AS3::ValueRegisterFile::Page *v3; // rdx
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
    v3 = result->pNext;
    this->pReserved = v3;
    if ( v3 )
      v3->pPrev = 0i64;
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

