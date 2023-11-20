// File Line: 60
// RVA: 0x702400
void Scaleform::GFx::AS2::Disasm::LogF(Scaleform::GFx::AS2::Disasm *this, const char *pfmt, ...)
{
  Scaleform::GFx::AS2::Disasm *v2; // rax
  Scaleform::Log *v3; // rcx
  int v4; // [rsp+20h] [rbp-18h]
  va_list va; // [rsp+50h] [rbp+18h]

  va_start(va, pfmt);
  v2 = this;
  v3 = this->pLog;
  if ( v3 )
  {
    v4 = v2->MsgId.Id;
    ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *, _QWORD))v3->vfptr[1].__vecDelDtor)(
      v3,
      &v4,
      pfmt,
      (__int64 *)va,
      *(_QWORD *)&v4);
  }
}

// File Line: 87
// RVA: 0x7010A0
_BOOL8 __fastcall Scaleform::GFx::AS2::ActionLogger::IsVerboseActionErrors(Scaleform::GFx::AS2::ActionLogger *this)
{
  return this->VerboseActionErrors;
}

// File Line: 175
// RVA: 0x70B220
void __fastcall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this)
{
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v1; // rdi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v2; // rbx
  unsigned __int64 v3; // rcx
  unsigned __int64 v4; // rbp
  unsigned __int64 v5; // r8
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page **v6; // rax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page **v7; // rcx
  Scaleform::GFx::AS2::Value *v8; // rax

  v1 = this->pReserved;
  v2 = this;
  if ( v1 )
    this->pReserved = v1->pNext;
  else
    v1 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                                                   Scaleform::Memory::pGlobalHeap,
                                                                                   this,
                                                                                   1032ui64,
                                                                                   0i64);
  if ( !v1 )
  {
    --v2->pCurrent;
    return;
  }
  v3 = v2->Pages.Data.Size;
  v4 = v3 + 1;
  if ( v3 + 1 >= v3 )
  {
    if ( v4 > v2->Pages.Data.Policy.Capacity )
    {
      v5 = v4 + (v4 >> 2);
      goto LABEL_10;
    }
  }
  else if ( v4 < v2->Pages.Data.Policy.Capacity >> 1 )
  {
    v5 = v3 + 1;
LABEL_10:
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v2->Pages,
      &v2->Pages,
      v5);
    goto LABEL_11;
  }
LABEL_11:
  v6 = v2->Pages.Data.Data;
  v2->Pages.Data.Size = v4;
  v7 = &v6[v4 - 1];
  if ( v7 )
    *v7 = v1;
  v8 = v2->pPageEnd;
  v2->pPageStart = (Scaleform::GFx::AS2::Value *)v1;
  v2->pCurrent = (Scaleform::GFx::AS2::Value *)v1;
  v2->pPrevPageTop = v8 - 1;
  v2->pPageEnd = (Scaleform::GFx::AS2::Value *)&v1->pNext;
}

// File Line: 200
// RVA: 0x7086B0
void __fastcall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this)
{
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v1; // rbx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v2; // r8
  Scaleform::GFx::AS2::Value *v3; // rdx
  unsigned __int64 v4; // rcx
  bool v5; // zf

  v1 = this;
  if ( this->Pages.Data.Size <= 1 )
  {
    v5 = this->pCurrent == (Scaleform::GFx::AS2::Value *)-32i64;
    ++this->pCurrent;
    if ( !v5 )
      this->pCurrent->T.Type = 0;
  }
  else
  {
    v2 = this->Pages.Data.Data[this->Pages.Data.Size - 1];
    v2->pNext = this->pReserved;
    this->pReserved = v2;
    Scaleform::ArrayData<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      (Scaleform::ArrayData<Scaleform::GFx::AS2::Value *,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value *,2>,Scaleform::ArrayDefaultPolicy> *)&this->Pages,
      this->Pages.Data.Size - 1);
    v3 = v1->Pages.Data.Data[v1->Pages.Data.Size - 1]->Values;
    v1->pPageStart = v3;
    v1->pPageEnd = v3 + 32;
    v1->pCurrent = v3 + 31;
    v4 = v1->Pages.Data.Size;
    if ( v4 <= 1 )
      v1->pPrevPageTop = v3;
    else
      v1->pPrevPageTop = &v1->Pages.Data.Data[v4 - 2]->Values[31];
  }
}

// File Line: 238
// RVA: 0x6C5DE0
void __fastcall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PagedStack<Scaleform::GFx::AS2::Value,32>(Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this)
{
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v1; // r14
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v2; // rbx
  Scaleform::ArrayLH<Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *,2,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v4; // rax
  unsigned __int64 v5; // rsi
  unsigned __int64 v6; // r8
  _QWORD *v7; // rcx
  void *v8; // [rsp+58h] [rbp+10h]
  Scaleform::ArrayLH<Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *,2,Scaleform::ArrayDefaultPolicy> *v9; // [rsp+60h] [rbp+18h]

  v1 = this;
  v2 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Pages;
  v8 = v2;
  v9 = &this->Pages;
  v2->Data = 0i64;
  v2->Size = 0i64;
  v2->Policy.Capacity = 0i64;
  this->pReserved = 0i64;
  v3 = (Scaleform::ArrayLH<Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *,2,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *, signed __int64, _QWORD, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(Scaleform::Memory::pGlobalHeap, this, 1032i64, 0i64, -2i64);
  if ( v2->Policy.Capacity < 0xF )
  {
    if ( v2->Data )
    {
      v4 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                            Scaleform::Memory::pGlobalHeap,
                                                            v2->Data,
                                                            128ui64);
    }
    else
    {
      LODWORD(v8) = 2;
      v4 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                            Scaleform::Memory::pGlobalHeap,
                                                            v2,
                                                            128ui64,
                                                            (Scaleform::AllocInfo *)&v8);
    }
    v2->Data = v4;
    v2->Policy.Capacity = 16i64;
  }
  v5 = v2->Size + 1;
  if ( v5 >= v2->Size )
  {
    if ( v5 <= v2->Policy.Capacity )
      goto LABEL_12;
    v6 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= v2->Policy.Capacity >> 1 )
      goto LABEL_12;
    v6 = v2->Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    v2,
    v2,
    v6);
LABEL_12:
  v2->Size = v5;
  v7 = &v2->Data[v5 - 1].pObject;
  if ( v7 )
    *v7 = v3;
  v1->pPageStart = (Scaleform::GFx::AS2::Value *)v3;
  v1->pPageEnd = (Scaleform::GFx::AS2::Value *)&v3[42].Data.Policy;
  v1->pCurrent = (Scaleform::GFx::AS2::Value *)v3;
  v1->pPrevPageTop = (Scaleform::GFx::AS2::Value *)v3;
  v8 = v3;
  v9 = v3;
  if ( v3 )
    LOBYTE(v3->Data.Data) = 0;
}

// File Line: 255
// RVA: 0x6CFD30
void __fastcall Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::~PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>(Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32> *this)
{
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32> *v1; // rdi
  int i; // ebx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v3; // rcx
  unsigned int v4; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rcx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *v7; // rdx
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *v8; // rbx

  v1 = this;
  for ( i = 32 * (this->Pages.Data.Size - 1) + ((_QWORD)((char *)this->pCurrent - (char *)this->pPageStart) >> 3); i; --i )
  {
    v3 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v1->pCurrent->pObject;
    if ( v3 )
    {
      v4 = v3->RefCount;
      if ( v4 & 0x3FFFFFF )
      {
        v3->RefCount = v4 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v3);
      }
    }
    --v1->pCurrent;
    if ( v1->pCurrent < v1->pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::PopPage(v1);
  }
  v5 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v1->pCurrent->pObject;
  if ( v5 )
  {
    v6 = v5->RefCount;
    if ( v6 & 0x3FFFFFF )
    {
      v5->RefCount = v6 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
  v7 = v1->Pages.Data.Data[v1->Pages.Data.Size - 1];
  v7->pNext = v1->pReserved;
  v1->pReserved = v7;
  do
  {
    v8 = v1->pReserved->pNext;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->pReserved);
    v1->pReserved = v8;
  }
  while ( v8 );
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Pages.Data.Data);
}

// File Line: 346
// RVA: 0x708350
void __fastcall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this)
{
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v1; // rbx
  Scaleform::GFx::AS2::Value *v2; // rcx
  signed int v3; // edi

  v1 = this;
  v2 = this->pCurrent;
  if ( &v2[-3] >= v1->pPageStart )
  {
    if ( v2->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v2);
    --v1->pCurrent;
    if ( v1->pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v1->pCurrent);
    --v1->pCurrent;
    if ( v1->pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v1->pCurrent);
    --v1->pCurrent;
  }
  else
  {
    v3 = 3;
    do
    {
      if ( v1->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v1->pCurrent);
      --v1->pCurrent;
      if ( v1->pCurrent < v1->pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(v1);
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 362
// RVA: 0x7083E0
void __fastcall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this, unsigned int n)
{
  unsigned int v2; // edi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v3; // rbx

  if ( n )
  {
    v2 = n;
    v3 = this;
    do
    {
      if ( v3->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v3->pCurrent);
      --v3->pCurrent;
      if ( v3->pCurrent < v3->pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(v3);
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 382
// RVA: 0x722880
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Top(Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this, unsigned int offset)
{
  unsigned int v2; // er8
  Scaleform::GFx::AS2::Value *result; // rax

  v2 = 32 * (LODWORD(this->Pages.Data.Size) - 1) + ((_QWORD)((char *)this->pCurrent - (char *)this->pPageStart) >> 5);
  if ( offset > v2 )
    result = 0i64;
  else
    result = &this->Pages.Data.Data[(unsigned __int64)(v2 - offset) >> 5]->Values[((_BYTE)v2 - (_BYTE)offset) & 0x1F];
  return result;
}

// File Line: 436
// RVA: 0x6EED10
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Environment::TryDescr::GetCatchName(Scaleform::GFx::AS2::Environment::TryDescr *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // r9
  char v5; // al
  Scaleform::GFx::ASStringNode *v6; // rdi
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ASString *v12; // [rsp+48h] [rbp+10h]

  v12 = result;
  v3 = result;
  v4 = *(Scaleform::GFx::ASStringNode **)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  result->pNode = v4;
  ++v4->RefCount;
  v5 = *this->pTryBlock;
  if ( !(v5 & 1) || v5 & 4 )
    return result;
  v6 = Scaleform::GFx::AS2::Environment::CreateString(penv, &resulta, this->pTryBlock + 7)->pNode;
  ++v6->RefCount;
  v7 = v3->pNode;
  v8 = v3->pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v3->pNode = v6;
  v9 = resulta.pNode;
  v8 = resulta.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  return v3;
}

// File Line: 494
// RVA: 0x6C8530
void __fastcall Scaleform::GFx::AS2::Environment::Environment(Scaleform::GFx::AS2::Environment *this)
{
  Scaleform::GFx::AS2::Environment *v1; // rbx
  signed __int64 v2; // [rsp+58h] [rbp+10h]
  signed __int64 v3; // [rsp+58h] [rbp+10h]
  signed __int64 v4; // [rsp+58h] [rbp+10h]

  v1 = this;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::`vftable;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>Vtbl *)&Scaleform::GFx::AS2::Environment::`vftable;
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PagedStack<Scaleform::GFx::AS2::Value,32>(&this->Stack);
  `eh vector constructor iterator(
    v1->GlobalRegister,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
  v2 = (signed __int64)&v1->LocalRegister;
  *(_OWORD *)v2 = 0ui64;
  *(_QWORD *)(v2 + 16) = 0i64;
  v1->Target = 0i64;
  v1->StringContext.pContext = 0i64;
  v1->StringContext.SWFVersion = 0;
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>(&v1->CallStack);
  v1->pASLogger = 0i64;
  v3 = (signed __int64)&v1->TryBlocks;
  *(_OWORD *)v3 = 0ui64;
  *(_QWORD *)(v3 + 16) = 0i64;
  v1->ThrowingValue.T.Type = 10;
  v1->ExecutionNestingLevel = 0;
  v1->FuncCallNestingLevel = 0;
  *((_BYTE *)v1 + 382) &= 0xFCu;
  v4 = (signed __int64)&v1->LocalFrames;
  *(_OWORD *)v4 = 0ui64;
  *(_QWORD *)(v4 + 16) = 0i64;
}

// File Line: 498
// RVA: 0x6D1360
void __fastcall Scaleform::GFx::AS2::Environment::~Environment(Scaleform::GFx::AS2::Environment *this)
{
  Scaleform::GFx::AS2::Environment *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>Vtbl *)&Scaleform::GFx::AS2::Environment::`vftable;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->LocalFrames);
  if ( v1->ThrowingValue.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v1->ThrowingValue);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->TryBlocks.Data.Data);
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::~PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>(&v1->CallStack);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> *)&v1->LocalRegister);
  `eh vector destructor iterator(
    v1->GlobalRegister,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::~PagedStack<Scaleform::GFx::AS2::Value,32>(&v1->Stack);
  v1->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::`vftable;
}

// File Line: 634
// RVA: 0x6D8510
void __fastcall Scaleform::GFx::AS2::Environment::AddFrameBarrier(Scaleform::GFx::AS2::Environment *this)
{
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2,Scaleform::ArrayDefaultPolicy> *v1; // rbx
  Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *v2; // rdx

  v1 = &this->LocalFrames;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->LocalFrames,
    &this->LocalFrames,
    this->LocalFrames.Data.Size + 1);
  v2 = &v1->Data.Data[v1->Data.Size - 1];
  if ( v2 )
    v2->pObject = 0i64;
}

// File Line: 680
// RVA: 0x6DC290
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Environment::CallTop(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::AS2::Value *result, int off)
{
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::Environment *v4; // r10
  Scaleform::GFx::AS2::Object **v5; // r9
  unsigned __int64 v6; // rcx
  __int64 v7; // rdx
  unsigned int v8; // ecx

  v3 = result;
  v4 = this;
  v5 = 0i64;
  v6 = this->CallStack.Pages.Data.Size;
  v7 = (_QWORD)((char *)v4->CallStack.pCurrent - (char *)v4->CallStack.pPageStart) >> 3;
  if ( (signed int)v7 + 32 * ((signed int)v6 - 1) >= (unsigned int)off )
  {
    v8 = v7 + 32 * (v6 - 1);
    if ( off <= v8 )
      v5 = (Scaleform::GFx::AS2::Object **)&v4->CallStack.Pages.Data.Data[(v8 - off) >> 5]->Values[(v8 - off) & 0x1F];
    Scaleform::GFx::AS2::Value::Value(v3, *v5);
  }
  else
  {
    v3->T.Type = 1;
  }
  return v3;
}

// File Line: 799
// RVA: 0x71B1F0
void __fastcall Scaleform::GFx::AS2::GlobalContext::SetPrototype(Scaleform::GFx::AS2::GlobalContext *this, Scaleform::GFx::AS2::ASBuiltinType type, Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto)
{
  Scaleform::GFx::AS2::Object *v3; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF> > *v4; // rcx
  signed __int64 v5; // rdx
  unsigned __int64 v6; // r9
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rcx
  unsigned int v8; // eax
  Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeRef key; // [rsp+28h] [rbp-20h]
  Scaleform::GFx::AS2::ASBuiltinType v10; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS2::Object *v11; // [rsp+60h] [rbp+18h]

  v11 = objproto.pObject;
  v10 = type;
  v3 = objproto.pObject;
  key.pFirst = &v10;
  key.pSecond = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)objproto.pObject;
  v4 = (Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeHashF> > *)&this->Prototypes.mHash.pTable;
  v5 = 4i64;
  v6 = 5381i64;
  do
    v6 = *((unsigned __int8 *)&v10 + --v5) + 65599 * v6;
  while ( v5 );
  Scaleform::HashSetBase<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum  Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::add<Scaleform::HashNode<enum  Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum  Scaleform::GFx::AS2::ASBuiltinType>>::NodeRef>(
    v4,
    v4,
    &key,
    v6);
  v7 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v3->vfptr;
  if ( v3->vfptr )
  {
    v8 = v7->RefCount;
    if ( v8 & 0x3FFFFFF )
    {
      v7->RefCount = v8 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
    }
  }
}

// File Line: 824
// RVA: 0x6BDFB0
void __fastcall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<11,Scaleform::GFx::AS2::ColorCtorFunction>(Scaleform::GFx::AS2::GlobalContext *this, Scaleform::GFx::AS2::ASStringContext *sc, Scaleform::GFx::AS2::Object *pdest)
{
  Scaleform::GFx::AS2::Object *v3; // rbp
  Scaleform::GFx::AS2::ASStringContext *v4; // r14
  Scaleform::GFx::AS2::GlobalContext *v5; // rdi
  Scaleform::GFx::ASString *v6; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v7; // rbx
  __int64 v8; // rax
  signed __int64 v9; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // rcx
  unsigned int v11; // eax
  Scaleform::GFx::ASMovieRootBase *v12; // rcx
  Scaleform::GFx::AS2::FunctionRef *(__fastcall *v13)(Scaleform::GFx::AS2::FunctionRef *, Scaleform::GFx::AS2::GlobalContext *); // [rsp+38h] [rbp-50h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // [rsp+40h] [rbp-48h]
  Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef key; // [rsp+48h] [rbp-40h]
  char v16; // [rsp+90h] [rbp+8h]

  v3 = pdest;
  v4 = sc;
  v5 = this;
  v7 = this->BuiltinClassesRegistry.mHash.pTable;
  if ( !v7
    || (v6 = (Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[10],
        v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&this->BuiltinClassesRegistry.mHash.pTable,
               v6,
               v6->pNode->HashFlags & v7->SizeMask),
        v8 < 0)
    || (v9 = (signed __int64)&v7[2 * v8 + 1].SizeMask) == 0
    || v9 == -8 )
  {
    v13 = Scaleform::GFx::AS2::ColorCtorFunction::Register;
    v14 = 0i64;
    key.pFirst = (Scaleform::GFx::ASString *)&v5->pMovieRoot->pASMovieRoot.pObject[10];
    key.pSecond = (Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *)&v13;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v5->BuiltinClassesRegistry.mHash.pTable,
      &v5->BuiltinClassesRegistry,
      &key,
      key.pFirst->pNode->HashFlags);
    v10 = v14;
    if ( v14 )
    {
      v11 = v14->RefCount;
      if ( v11 & 0x3FFFFFF )
      {
        v14->RefCount = v11 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
      }
    }
    v12 = v5->pMovieRoot->pASMovieRoot.pObject;
    LOBYTE(key.pFirst) = 11;
    key.pSecond = (Scaleform::GFx::AS2::GlobalContext::ClassRegEntry *)v12[10].vfptr;
    ++LODWORD(key.pSecond[1].ResolvedFunc.pObject);
    v16 = 0;
    v3->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
      v4,
      (Scaleform::GFx::ASString *)&v5->pMovieRoot->pASMovieRoot.pObject[10],
      (Scaleform::GFx::AS2::Value *)&key,
      (Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( LOBYTE(key.pFirst) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&key);
  }
}

// File Line: 853
// RVA: 0x6DF980
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::GlobalContext::CreateConstString(Scaleform::GFx::AS2::GlobalContext *this, Scaleform::GFx::ASString *result, const char *pstr)
{
  Scaleform::GFx::ASString *v3; // rbx

  v3 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pstr);
  return v3;
}

// File Line: 891
// RVA: 0x6E15E0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Environment::CreateString(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::ASString *result, const char *pstr)
{
  Scaleform::GFx::ASString *v3; // rbx

  v3 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pstr);
  return v3;
}

// File Line: 895
// RVA: 0x6E1680
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Environment::CreateString(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::ASString *result, const wchar_t *pwstr)
{
  Scaleform::GFx::ASString *v3; // rbx

  v3 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pwstr,
    -1i64);
  return v3;
}

// File Line: 899
// RVA: 0x6DF930
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Environment::CreateConstString(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::ASString *result, const char *pstr)
{
  Scaleform::GFx::ASString *v3; // rbx

  v3 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pstr);
  return v3;
}

// File Line: 903
// RVA: 0x6E1630
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Environment::CreateString(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::ASString *result, const char *pstr, unsigned __int64 length)
{
  Scaleform::GFx::ASString *v4; // rbx

  v4 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pstr,
    length);
  return v4;
}

// File Line: 907
// RVA: 0x6E1590
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Environment::CreateString(Scaleform::GFx::AS2::Environment *this, Scaleform::GFx::ASString *result, Scaleform::String *str)
{
  Scaleform::GFx::ASString *v3; // rbx

  v3 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    str);
  return v3;
}

// File Line: 955
// RVA: 0x6DF830
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::ASStringContext::CreateConstString(Scaleform::GFx::AS2::ASStringContext *this, Scaleform::GFx::ASString *result, const char *pstr)
{
  Scaleform::GFx::ASString *v3; // rbx

  v3 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pstr);
  return v3;
}

// File Line: 959
// RVA: 0x6E1360
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::ASStringContext::CreateString(Scaleform::GFx::AS2::ASStringContext *this, Scaleform::GFx::ASString *result, const char *pstr)
{
  Scaleform::GFx::ASString *v3; // rbx

  v3 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pstr);
  return v3;
}

// File Line: 967
// RVA: 0x6E13B0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::ASStringContext::CreateString(Scaleform::GFx::AS2::ASStringContext *this, Scaleform::GFx::ASString *result, const char *pstr, unsigned __int64 length)
{
  Scaleform::GFx::ASString *v4; // rbx

  v4 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pstr,
    length);
  return v4;
}

// File Line: 971
// RVA: 0x6E1310
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::ASStringContext::CreateString(Scaleform::GFx::AS2::ASStringContext *this, Scaleform::GFx::ASString *result, Scaleform::String *str)
{
  Scaleform::GFx::ASString *v3; // rbx

  v3 = result;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    str);
  return v3;
}

