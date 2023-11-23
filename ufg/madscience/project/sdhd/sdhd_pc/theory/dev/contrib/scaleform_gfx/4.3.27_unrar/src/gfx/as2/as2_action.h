// File Line: 60
// RVA: 0x702400
void Scaleform::GFx::AS2::Disasm::LogF(Scaleform::GFx::AS2::Disasm *this, const char *pfmt, ...)
{
  Scaleform::Log *pLog; // rcx
  int v4[6]; // [rsp+20h] [rbp-18h] BYREF
  va_list va; // [rsp+50h] [rbp+18h] BYREF

  va_start(va, pfmt);
  pLog = this->pLog;
  if ( pLog )
  {
    v4[0] = this->MsgId.Id;
    ((void (__fastcall *)(Scaleform::Log *, int *, const char *, __int64 *))pLog->vfptr[1].__vecDelDtor)(
      pLog,
      v4,
      pfmt,
      (__int64 *)va);
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
void __fastcall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this)
{
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *pReserved; // rdi
  unsigned __int64 Size; // rcx
  unsigned __int64 v4; // rbp
  unsigned __int64 v5; // r8
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page **Data; // rax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page **v7; // rcx
  Scaleform::GFx::AS2::Value *pPageEnd; // rax

  pReserved = this->pReserved;
  if ( pReserved )
    this->pReserved = pReserved->pNext;
  else
    pReserved = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                                                          Scaleform::Memory::pGlobalHeap,
                                                                                          this,
                                                                                          1032i64,
                                                                                          0i64);
  if ( !pReserved )
  {
    --this->pCurrent;
    return;
  }
  Size = this->Pages.Data.Size;
  v4 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v4 > this->Pages.Data.Policy.Capacity )
    {
      v5 = v4 + (v4 >> 2);
      goto LABEL_10;
    }
  }
  else if ( v4 < this->Pages.Data.Policy.Capacity >> 1 )
  {
    v5 = Size + 1;
LABEL_10:
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Pages,
      &this->Pages,
      v5);
  }
  Data = this->Pages.Data.Data;
  this->Pages.Data.Size = v4;
  v7 = &Data[v4 - 1];
  if ( v7 )
    *v7 = pReserved;
  pPageEnd = this->pPageEnd;
  this->pPageStart = (Scaleform::GFx::AS2::Value *)pReserved;
  this->pCurrent = (Scaleform::GFx::AS2::Value *)pReserved;
  this->pPrevPageTop = pPageEnd - 1;
  this->pPageEnd = (Scaleform::GFx::AS2::Value *)&pReserved->pNext;
}

// File Line: 200
// RVA: 0x7086B0
void __fastcall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this)
{
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v2; // r8
  Scaleform::GFx::AS2::Value *Values; // rdx
  unsigned __int64 Size; // rcx

  if ( this->Pages.Data.Size <= 1 )
  {
    if ( this->pCurrent++ != (Scaleform::GFx::AS2::Value *)-32i64 )
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
    Values = this->Pages.Data.Data[this->Pages.Data.Size - 1]->Values;
    this->pPageStart = Values;
    this->pPageEnd = Values + 32;
    this->pCurrent = Values + 31;
    Size = this->Pages.Data.Size;
    if ( Size <= 1 )
      this->pPrevPageTop = Values;
    else
      this->pPrevPageTop = &this->Pages.Data.Data[Size - 2]->Values[31];
  }
}

// File Line: 238
// RVA: 0x6C5DE0
void __fastcall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PagedStack<Scaleform::GFx::AS2::Value,32>(
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this)
{
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *p_Pages; // rbx
  Scaleform::ArrayLH<Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *,2,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v4; // rax
  unsigned __int64 v5; // rsi
  unsigned __int64 v6; // r8
  _QWORD *p_pObject; // rcx
  Scaleform::ArrayLH<Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *,2,Scaleform::ArrayDefaultPolicy> *v8; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::ArrayLH<Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *,2,Scaleform::ArrayDefaultPolicy> *v9; // [rsp+60h] [rbp+18h]

  p_Pages = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->Pages;
  v8 = &this->Pages;
  v9 = &this->Pages;
  this->Pages.Data.Data = 0i64;
  this->Pages.Data.Size = 0i64;
  this->Pages.Data.Policy.Capacity = 0i64;
  this->pReserved = 0i64;
  v3 = (Scaleform::ArrayLH<Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *,2,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *, __int64, _QWORD, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(Scaleform::Memory::pGlobalHeap, this, 1032i64, 0i64, -2i64);
  if ( p_Pages->Policy.Capacity < 0xF )
  {
    if ( p_Pages->Data )
    {
      v4 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                            Scaleform::Memory::pGlobalHeap,
                                                            p_Pages->Data,
                                                            128i64);
    }
    else
    {
      LODWORD(v8) = 2;
      v4 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                            Scaleform::Memory::pGlobalHeap,
                                                            p_Pages,
                                                            128i64,
                                                            &v8);
    }
    p_Pages->Data = v4;
    p_Pages->Policy.Capacity = 16i64;
  }
  v5 = p_Pages->Size + 1;
  if ( v5 >= p_Pages->Size )
  {
    if ( v5 <= p_Pages->Policy.Capacity )
      goto LABEL_12;
    v6 = v5 + (v5 >> 2);
  }
  else
  {
    if ( v5 >= p_Pages->Policy.Capacity >> 1 )
      goto LABEL_12;
    v6 = p_Pages->Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    p_Pages,
    p_Pages,
    v6);
LABEL_12:
  p_Pages->Size = v5;
  p_pObject = &p_Pages->Data[v5 - 1].pObject;
  if ( p_pObject )
    *p_pObject = v3;
  this->pPageStart = (Scaleform::GFx::AS2::Value *)v3;
  this->pPageEnd = (Scaleform::GFx::AS2::Value *)&v3[42].Data.Policy;
  this->pCurrent = (Scaleform::GFx::AS2::Value *)v3;
  this->pPrevPageTop = (Scaleform::GFx::AS2::Value *)v3;
  v8 = v3;
  v9 = v3;
  if ( v3 )
    LOBYTE(v3->Data.Data) = 0;
}

// File Line: 255
// RVA: 0x6CFD30
void __fastcall Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::~PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>(
        Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32> *this)
{
  int i; // ebx
  Scaleform::GFx::AS2::FunctionObject *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::FunctionObject *v5; // rcx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *v7; // rdx
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::Page *pNext; // rbx

  for ( i = 32 * (this->Pages.Data.Size - 1) + this->pCurrent - this->pPageStart; i; --i )
  {
    pObject = this->pCurrent->pObject;
    if ( pObject )
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    if ( --this->pCurrent < this->pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::PopPage(this);
  }
  v5 = this->pCurrent->pObject;
  if ( v5 )
  {
    v6 = v5->RefCount;
    if ( (v6 & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = v6 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
  v7 = this->Pages.Data.Data[this->Pages.Data.Size - 1];
  v7->pNext = this->pReserved;
  this->pReserved = v7;
  do
  {
    pNext = this->pReserved->pNext;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pReserved);
    this->pReserved = pNext;
  }
  while ( pNext );
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Pages.Data.Data);
}

// File Line: 346
// RVA: 0x708350
void __fastcall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this)
{
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  int v3; // edi

  pCurrent = this->pCurrent;
  if ( &pCurrent[-3] >= this->pPageStart )
  {
    if ( pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pCurrent);
    --this->pCurrent;
    if ( this->pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(this->pCurrent);
    --this->pCurrent;
    if ( this->pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(this->pCurrent);
    --this->pCurrent;
  }
  else
  {
    v3 = 3;
    do
    {
      if ( this->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(this->pCurrent);
      if ( --this->pCurrent < this->pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(this);
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 362
// RVA: 0x7083E0
void __fastcall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this,
        unsigned int n)
{
  unsigned int v2; // edi

  if ( n )
  {
    v2 = n;
    do
    {
      if ( this->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(this->pCurrent);
      if ( --this->pCurrent < this->pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(this);
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 382
// RVA: 0x722880
Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *__fastcall Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Top(
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *this,
        unsigned int offset)
{
  unsigned int v2; // r8d

  v2 = 32 * (LODWORD(this->Pages.Data.Size) - 1) + this->pCurrent - this->pPageStart;
  if ( offset > v2 )
    return 0i64;
  else
    return (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *)((char *)this->Pages.Data.Data[(unsigned __int64)(v2 - offset) >> 5]
                                                                                  + 32
                                                                                  * (((unsigned __int8)v2
                                                                                    - (unsigned __int8)offset) & 0x1F));
}

// File Line: 436
// RVA: 0x6EED10
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Environment::TryDescr::GetCatchName(
        Scaleform::GFx::AS2::Environment::TryDescr *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASStringNode *v4; // r9
  char v5; // al
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ASString *v13; // [rsp+48h] [rbp+10h]

  v13 = result;
  v4 = *(Scaleform::GFx::ASStringNode **)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  result->pNode = v4;
  ++v4->RefCount;
  v5 = *this->pTryBlock;
  if ( (v5 & 1) == 0 || (v5 & 4) != 0 )
    return result;
  v6 = Scaleform::GFx::AS2::Environment::CreateString(penv, &resulta, this->pTryBlock + 7);
  pNode = v6->pNode;
  ++v6->pNode->RefCount;
  v8 = result->pNode;
  v9 = result->pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  result->pNode = pNode;
  v10 = resulta.pNode;
  v9 = resulta.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  return result;
}

// File Line: 494
// RVA: 0x6C8530
void __fastcall Scaleform::GFx::AS2::Environment::Environment(Scaleform::GFx::AS2::Environment *this)
{
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::`vftable;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>Vtbl *)&Scaleform::GFx::AS2::Environment::`vftable;
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PagedStack<Scaleform::GFx::AS2::Value,32>(&this->Stack);
  `eh vector constructor iterator(
    this->GlobalRegister,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::Value);
  this->LocalRegister.Data.Data = 0i64;
  this->LocalRegister.Data.Size = 0i64;
  this->LocalRegister.Data.Policy.Capacity = 0i64;
  this->Target = 0i64;
  this->StringContext.pContext = 0i64;
  this->StringContext.SWFVersion = 0;
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>(&this->CallStack);
  this->pASLogger = 0i64;
  this->TryBlocks.Data.Data = 0i64;
  this->TryBlocks.Data.Size = 0i64;
  this->TryBlocks.Data.Policy.Capacity = 0i64;
  this->ThrowingValue.T.Type = 10;
  this->ExecutionNestingLevel = 0;
  this->FuncCallNestingLevel = 0;
  *((_BYTE *)this + 382) &= 0xFCu;
  this->LocalFrames.Data.Data = 0i64;
  this->LocalFrames.Data.Size = 0i64;
  this->LocalFrames.Data.Policy.Capacity = 0i64;
}

// File Line: 498
// RVA: 0x6D1360
void __fastcall Scaleform::GFx::AS2::Environment::~Environment(Scaleform::GFx::AS2::Environment *this)
{
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>Vtbl *)&Scaleform::GFx::AS2::Environment::`vftable;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->LocalFrames);
  if ( this->ThrowingValue.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&this->ThrowingValue);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->TryBlocks.Data.Data);
  Scaleform::GFx::AS2::PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>::~PagedStack<Scaleform::Ptr<Scaleform::GFx::AS2::FunctionObject>,32>(&this->CallStack);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> *)&this->LocalRegister);
  `eh vector destructor iterator(
    this->GlobalRegister,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Scaleform::GFx::AS2::Value::~Value);
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::~PagedStack<Scaleform::GFx::AS2::Value,32>(&this->Stack);
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::`vftable;
}

// File Line: 634
// RVA: 0x6D8510
void __fastcall Scaleform::GFx::AS2::Environment::AddFrameBarrier(Scaleform::GFx::AS2::Environment *this)
{
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2,Scaleform::ArrayDefaultPolicy> *p_LocalFrames; // rbx
  Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *v2; // rdx

  p_LocalFrames = &this->LocalFrames;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->LocalFrames,
    &this->LocalFrames,
    this->LocalFrames.Data.Size + 1);
  v2 = &p_LocalFrames->Data.Data[p_LocalFrames->Data.Size - 1];
  if ( v2 )
    v2->pObject = 0i64;
}

// File Line: 680
// RVA: 0x6DC290
Scaleform::GFx::AS2::Value *__fastcall Scaleform::GFx::AS2::Environment::CallTop(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::Value *result,
        unsigned int off)
{
  Scaleform::GFx::ASStringNode **v5; // r9
  unsigned __int64 Size; // rcx
  signed __int64 v7; // rdx
  unsigned int v8; // ecx

  v5 = 0i64;
  Size = this->CallStack.Pages.Data.Size;
  v7 = this->CallStack.pCurrent - this->CallStack.pPageStart;
  if ( (int)v7 + 32 * ((int)Size - 1) >= off )
  {
    v8 = v7 + 32 * (Size - 1);
    if ( off <= v8 )
      v5 = (Scaleform::GFx::ASStringNode **)&this->CallStack.Pages.Data.Data[(v8 - off) >> 5]->Values[(v8 - off) & 0x1F];
    Scaleform::GFx::AS2::Value::Value(result, *v5);
  }
  else
  {
    result->T.Type = 1;
  }
  return result;
}

// File Line: 799
// RVA: 0x71B1F0
void __fastcall Scaleform::GFx::AS2::GlobalContext::SetPrototype(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::AS2::ASBuiltinType type,
        Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto)
{
  Scaleform::HashUncachedLH<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>,2> *p_Prototypes; // rcx
  __int64 v5; // rdx
  unsigned __int64 v6; // r9
  Scaleform::GFx::AS2::RefCountBaseGC<323> *vfptr; // rcx
  unsigned int RefCount; // eax
  Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType> >::NodeRef key; // [rsp+28h] [rbp-20h] BYREF
  Scaleform::GFx::AS2::ASBuiltinType v10; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::AS2::Object *pObject; // [rsp+60h] [rbp+18h]

  pObject = objproto.pObject;
  v10 = type;
  key.pFirst = &v10;
  key.pSecond = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)objproto.pObject;
  p_Prototypes = &this->Prototypes;
  v5 = 4i64;
  v6 = 5381i64;
  do
  {
    --v5;
    v6 = *((unsigned __int8 *)&v10 + v5) + 65599 * v6;
  }
  while ( v5 );
  Scaleform::HashSetBase<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeAltHashF,Scaleform::AllocatorLH<enum Scaleform::GFx::AS2::ASBuiltinType,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>,Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeHashF>>::add<Scaleform::HashNode<enum Scaleform::GFx::AS2::ASBuiltinType,Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::FixedSizeHash<enum Scaleform::GFx::AS2::ASBuiltinType>>::NodeRef>(
    &p_Prototypes->mHash,
    p_Prototypes,
    &key,
    v6);
  vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)objproto.pObject->vfptr;
  if ( objproto.pObject->vfptr )
  {
    RefCount = vfptr->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      vfptr->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(vfptr);
    }
  }
}

// File Line: 824
// RVA: 0x6BDFB0
void __fastcall Scaleform::GFx::AS2::GlobalContext::AddBuiltinClassRegistry<11,Scaleform::GFx::AS2::ColorCtorFunction>(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::AS2::ASStringContext *sc,
        Scaleform::GFx::AS2::Object *pdest)
{
  Scaleform::GFx::ASString *v6; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // rbx
  __int64 v8; // rax
  unsigned __int64 *p_SizeMask; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::GFx::AS2::FunctionRef *(__fastcall *v13)(Scaleform::GFx::AS2::FunctionRef *, Scaleform::GFx::AS2::GlobalContext *); // [rsp+38h] [rbp-50h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v14; // [rsp+40h] [rbp-48h]
  Scaleform::GFx::AS2::Value key; // [rsp+48h] [rbp-40h] BYREF
  char v16; // [rsp+90h] [rbp+8h] BYREF

  pTable = this->BuiltinClassesRegistry.mHash.pTable;
  if ( !pTable
    || (v6 = (Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[10],
        v8 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
               &this->BuiltinClassesRegistry.mHash,
               v6,
               v6->pNode->HashFlags & pTable->SizeMask),
        v8 < 0)
    || (p_SizeMask = &pTable[2 * v8 + 1].SizeMask) == 0i64
    || p_SizeMask == (unsigned __int64 *)-8i64 )
  {
    v13 = Scaleform::GFx::AS2::ColorCtorFunction::Register;
    v14 = 0i64;
    *(_QWORD *)&key.T.Type = this->pMovieRoot->pASMovieRoot.pObject + 10;
    key.V.pStringNode = (Scaleform::GFx::ASStringNode *)&v13;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
      &this->BuiltinClassesRegistry.mHash,
      &this->BuiltinClassesRegistry,
      (Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeRef *)&key,
      *(unsigned int *)(**(_QWORD **)&key.T.Type + 28i64));
    v10 = v14;
    if ( v14 )
    {
      RefCount = v14->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v14->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
      }
    }
    pObject = this->pMovieRoot->pASMovieRoot.pObject;
    key.T.Type = 11;
    key.V.pStringNode = (Scaleform::GFx::ASStringNode *)pObject[10].vfptr;
    ++key.V.pStringNode->RefCount;
    v16 = 0;
    pdest->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &pdest->Scaleform::GFx::AS2::ObjectInterface,
      sc,
      (Scaleform::GFx::ASString *)&this->pMovieRoot->pASMovieRoot.pObject[10],
      &key,
      (Scaleform::GFx::AS2::PropFlags *)&v16);
    if ( key.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&key);
  }
}

// File Line: 853
// RVA: 0x6DF980
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::GlobalContext::CreateConstString(
        Scaleform::GFx::AS2::GlobalContext *this,
        Scaleform::GFx::ASString *result,
        const char *pstr)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pstr);
  return result;
}

// File Line: 891
// RVA: 0x6E15E0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Environment::CreateString(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASString *result,
        const char *pstr)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pstr);
  return result;
}

// File Line: 895
// RVA: 0x6E1680
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Environment::CreateString(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASString *result,
        const wchar_t *pwstr)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pwstr,
    -1i64);
  return result;
}

// File Line: 899
// RVA: 0x6DF930
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Environment::CreateConstString(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASString *result,
        const char *pstr)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pstr);
  return result;
}

// File Line: 903
// RVA: 0x6E1630
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Environment::CreateString(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASString *result,
        const char *pstr,
        unsigned __int64 length)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pstr,
    length);
  return result;
}

// File Line: 907
// RVA: 0x6E1590
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Environment::CreateString(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASString *result,
        Scaleform::String *str)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    str);
  return result;
}

// File Line: 955
// RVA: 0x6DF830
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::ASStringContext::CreateConstString(
        Scaleform::GFx::AS2::ASStringContext *this,
        Scaleform::GFx::ASString *result,
        const char *pstr)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateConstString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pstr);
  return result;
}

// File Line: 959
// RVA: 0x6E1360
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::ASStringContext::CreateString(
        Scaleform::GFx::AS2::ASStringContext *this,
        Scaleform::GFx::ASString *result,
        const char *pstr)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pstr);
  return result;
}

// File Line: 967
// RVA: 0x6E13B0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::ASStringContext::CreateString(
        Scaleform::GFx::AS2::ASStringContext *this,
        Scaleform::GFx::ASString *result,
        const char *pstr,
        unsigned __int64 length)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    pstr,
    length);
  return result;
}

// File Line: 971
// RVA: 0x6E1310
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::ASStringContext::CreateString(
        Scaleform::GFx::AS2::ASStringContext *this,
        Scaleform::GFx::ASString *result,
        Scaleform::String *str)
{
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS2::ASBuiltinType,156> *)&this->pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    result,
    str);
  return result;
}

