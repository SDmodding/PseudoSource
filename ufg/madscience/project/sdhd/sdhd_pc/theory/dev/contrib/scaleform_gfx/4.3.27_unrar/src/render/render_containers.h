// File Line: 51
// RVA: 0x94B1F0
// attributes: thunk
void __fastcall Scaleform::Render::LinearHeap::~LinearHeap(Scaleform::Render::LinearHeap *this)
{
  Scaleform::Render::LinearHeap::ClearAndRelease(this);
}

// File Line: 65
// RVA: 0x9602A0
void __fastcall Scaleform::Render::LinearHeap::ClearAndRelease(Scaleform::Render::LinearHeap *this)
{
  unsigned __int64 MaxPages; // rax
  Scaleform::Render::LinearHeap::PageType *v3; // rdi
  Scaleform::MemoryHeap *pHeap; // rcx

  MaxPages = this->MaxPages;
  if ( MaxPages )
  {
    v3 = &this->pPagePool[MaxPages - 1];
    do
    {
      --this->MaxPages;
      if ( v3->pStart )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))this->pHeap->vfptr->Free)(this->pHeap);
      --v3;
    }
    while ( this->MaxPages );
    pHeap = this->pHeap;
    --this->MaxPages;
    pHeap->vfptr->Free(pHeap, this->pPagePool);
  }
  this->pLastPage = 0i64;
  this->pPagePool = 0i64;
  this->MaxPages = 0i64;
}

// File Line: 94
// RVA: 0x6DA530
void *__fastcall Scaleform::Render::LinearHeap::Alloc(Scaleform::Render::LinearHeap *this, unsigned __int64 size)
{
  unsigned __int64 v3; // rbp
  void *result; // rax
  Scaleform::Render::LinearHeap::PageType *v5; // rax
  signed __int64 MaxPages; // rdx
  signed __int64 v7; // rsi
  Scaleform::Render::LinearHeap::PageType *v8; // rbx
  unsigned __int64 v9; // rax

  v3 = (size + 7) & 0xFFFFFFFFFFFFFFF8ui64;
  if ( this->pLastPage )
  {
    result = Scaleform::Render::LinearHeap::allocFromLastPage(this, (size + 7) & 0xFFFFFFFFFFFFFFF8ui64);
    if ( result )
      return result;
    ++this->pLastPage;
  }
  else
  {
    v5 = (Scaleform::Render::LinearHeap::PageType *)this->pHeap->vfptr->Alloc(this->pHeap, 1536i64, 0i64);
    this->pPagePool = v5;
    this->pLastPage = v5;
    memset(v5, 0, 0x600ui64);
    this->MaxPages = 64i64;
  }
  MaxPages = this->MaxPages;
  v7 = this->pLastPage - this->pPagePool;
  if ( v7 >= MaxPages )
  {
    v8 = (Scaleform::Render::LinearHeap::PageType *)this->pHeap->vfptr->Alloc(this->pHeap, 48 * MaxPages, 0i64);
    memmove(v8, this->pPagePool, 24 * this->MaxPages);
    memset(&v8[this->MaxPages], 0, 24 * this->MaxPages);
    this->pHeap->vfptr->Free(this->pHeap, this->pPagePool);
    v9 = this->MaxPages;
    this->pPagePool = v8;
    this->MaxPages = 2 * v9;
    this->pLastPage = &v8[v7];
  }
  return Scaleform::Render::LinearHeap::allocFromLastPage(this, v3);
}

// File Line: 129
// RVA: 0x724D90
char *__fastcall Scaleform::Render::LinearHeap::allocFromLastPage(
        Scaleform::Render::LinearHeap *this,
        signed __int64 size)
{
  Scaleform::Render::LinearHeap::PageType *pLastPage; // rcx
  char *pFree; // rdx
  signed __int64 v6; // rax

  pLastPage = this->pLastPage;
  pFree = pLastPage->pFree;
  v6 = pLastPage->pEnd - pFree;
  if ( v6 < size )
  {
    if ( pFree == pLastPage->pStart )
    {
      if ( v6 < size )
        Scaleform::Render::LinearHeap::allocPage(this, size);
      this->pLastPage->pFree += size;
      return this->pLastPage->pStart;
    }
    else
    {
      return 0i64;
    }
  }
  else
  {
    pLastPage->pFree = &pFree[size];
    return &this->pLastPage->pFree[-size];
  }
}

// File Line: 149
// RVA: 0x724E10
void __fastcall Scaleform::Render::LinearHeap::allocPage(Scaleform::Render::LinearHeap *this, unsigned __int64 size)
{
  unsigned __int64 v4; // rbx
  char *v5; // rax

  if ( this->pLastPage->pStart )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))this->pHeap->vfptr->Free)(this->pHeap);
  v4 = this->Granularity * ((this->Granularity + size - 1) / this->Granularity);
  v5 = (char *)this->pHeap->vfptr->Alloc(this->pHeap, v4, 0i64);
  this->pLastPage->pFree = v5;
  this->pLastPage->pStart = v5;
  this->pLastPage->pEnd = &this->pLastPage->pStart[v4];
}

// File Line: 200
// RVA: 0x9A21F0
void __fastcall Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::BaseLineType,4,4>::PushBack(
        Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::BaseLineType,4,4> *this,
        Scaleform::Render::Tessellator::BaseLineType *val)
{
  unsigned __int64 v4; // rbx
  Scaleform::Render::Tessellator::BaseLineType *v5; // rdx

  v4 = this->Size >> 4;
  if ( v4 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4> *)this,
      this->Size >> 4);
  v5 = &this->Pages[v4][this->Size & 0xF];
  v5->y = val->y;
  v5->styleLeft = val->styleLeft;
  v5->vertexLeft = val->vertexLeft;
  v5->vertexRight = val->vertexRight;
  v5->firstChain = val->firstChain;
  v5->numChains = val->numChains;
  v5->leftAbove = val->leftAbove;
  ++this->Size;
}

// File Line: 246
// RVA: 0x9CCDB0
void __fastcall Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::allocPage(
        Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4> *this,
        unsigned __int64 nb)
{
  unsigned __int64 MaxPages; // rdx
  void *v5; // rbx
  unsigned __int64 v6; // rax

  MaxPages = this->MaxPages;
  if ( nb >= MaxPages )
  {
    if ( this->Pages )
    {
      v5 = Scaleform::Render::LinearHeap::Alloc(this->pHeap, 16 * MaxPages);
      memmove(v5, this->Pages, 8 * this->NumPages);
      v6 = this->MaxPages;
      this->Pages = (Scaleform::Render::TessMesh **)v5;
      this->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 4i64;
      this->Pages = (Scaleform::Render::TessMesh **)Scaleform::Render::LinearHeap::Alloc(this->pHeap, 0x20ui64);
    }
  }
  this->Pages[nb] = (Scaleform::Render::TessMesh *)Scaleform::Render::LinearHeap::Alloc(this->pHeap, 0x1C0ui64);
  ++this->NumPages;
}

// File Line: 342
// RVA: 0x953F00
void __fastcall Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *this)
{
  unsigned __int64 NumArrays; // rax
  unsigned __int64 MaxArrays; // rdx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v4; // rbx
  unsigned __int64 v5; // rax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v6; // rax

  NumArrays = this->NumArrays;
  MaxArrays = this->MaxArrays;
  if ( NumArrays >= MaxArrays )
  {
    if ( NumArrays )
    {
      v4 = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)Scaleform::Render::LinearHeap::Alloc(this->pHeap, MaxArrays << 6);
      memmove(v4, this->Arrays, 32 * this->NumArrays);
      v5 = this->MaxArrays;
      this->Arrays = v4;
      this->MaxArrays = 2 * v5;
    }
    else
    {
      this->MaxArrays = 16i64;
      this->Arrays = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)Scaleform::Render::LinearHeap::Alloc(this->pHeap, 0x200ui64);
    }
  }
  v6 = &this->Arrays[this->NumArrays];
  v6->Size = 0i64;
  v6->NumPages = 0i64;
  v6->MaxPages = 0i64;
  v6->Pages = 0i64;
  ++this->NumArrays;
}

// File Line: 377
// RVA: 0x9A2150
void __fastcall Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::PushBack(
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *this,
        unsigned __int64 i,
        Scaleform::Render::Tessellator::TriangleType *val)
{
  unsigned __int64 v4; // rsi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v6; // rdi
  unsigned __int64 v7; // rbx
  Scaleform::Render::Tessellator::TriangleType *v8; // rdx

  v4 = i;
  v6 = &this->Arrays[i];
  v7 = v6->Size >> 4;
  if ( v7 >= v6->NumPages )
    Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
      this,
      &this->Arrays[i],
      v6->Size >> 4);
  v8 = &v6->Pages[v7][v6->Size & 0xF];
  v8->d.m.v1 = val->d.m.v1;
  v8->d.m.v2 = val->d.m.v2;
  v8->d.m.v3 = val->d.m.v3;
  ++this->Arrays[v4].Size;
}

// File Line: 423
// RVA: 0x9B7610
char __fastcall Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::Split(
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *this,
        unsigned __int64 i,
        unsigned __int64 at)
{
  unsigned __int64 v3; // r14
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v5; // rax
  unsigned __int64 Size; // r13
  unsigned __int64 v8; // r12
  unsigned __int64 v9; // rbp
  unsigned __int64 v10; // rbx
  Scaleform::Render::Tessellator::TriangleType **v11; // rsi
  unsigned __int64 v12; // rdi
  unsigned __int64 v13; // rcx

  v3 = i;
  v5 = &this->Arrays[i];
  Size = v5->Size;
  if ( at >= v5->Size )
    return 0;
  v8 = at >> 4;
  v9 = at & 0xFFFFFFFFFFFFFFF0ui64;
  v10 = v5->MaxPages - (at >> 4);
  v11 = &v5->Pages[at >> 4];
  v12 = v5->NumPages - (at >> 4);
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(this);
  this->Arrays[v3].NumPages = v8;
  this->Arrays[v3].MaxPages = v8;
  this->Arrays[v3].Size = v9;
  v13 = this->NumArrays - 1;
  this->Arrays[v13].NumPages = v12;
  this->Arrays[v13].MaxPages = v10;
  this->Arrays[v13].Size = Size - v9;
  this->Arrays[v13].Pages = v11;
  return 1;
}

// File Line: 449
// RVA: 0x9CC3A0
void __fastcall Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *this,
        Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *a,
        unsigned __int64 nb)
{
  unsigned __int64 MaxPages; // rdx
  void *v7; // rbx
  unsigned __int64 v8; // rax

  MaxPages = a->MaxPages;
  if ( nb >= MaxPages )
  {
    if ( a->Pages )
    {
      v7 = Scaleform::Render::LinearHeap::Alloc(this->pHeap, 16 * MaxPages);
      memmove(v7, a->Pages, 8 * a->NumPages);
      v8 = a->MaxPages;
      a->Pages = (Scaleform::Render::Tessellator::TriangleType **)v7;
      a->MaxPages = 2 * v8;
    }
    else
    {
      a->MaxPages = 16i64;
      a->Pages = (Scaleform::Render::Tessellator::TriangleType **)Scaleform::Render::LinearHeap::Alloc(
                                                                    this->pHeap,
                                                                    0x80ui64);
    }
  }
  a->Pages[nb] = (Scaleform::Render::Tessellator::TriangleType *)Scaleform::Render::LinearHeap::Alloc(
                                                                   this->pHeap,
                                                                   0x180ui64);
  ++a->NumPages;
}

// File Line: 507
// RVA: 0x9AC6D0
void __fastcall Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::Cell *>::Resize(
        Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::SortedY> *this,
        unsigned __int64 size)
{
  size_t v4; // rbx
  Scaleform::Render::Rasterizer::SortedY *v5; // rbp
  Scaleform::Render::Rasterizer::SortedY *Array; // rdx
  unsigned __int64 v7; // r8

  if ( size <= this->Size )
  {
    this->Size = size;
  }
  else
  {
    v4 = 8 * size;
    v5 = (Scaleform::Render::Rasterizer::SortedY *)Scaleform::Render::LinearHeap::Alloc(this->pHeap, 8 * size);
    memset(v5, 0, v4);
    Array = this->Array;
    if ( Array )
    {
      v7 = this->Size;
      if ( v7 )
        memmove(v5, Array, 8 * v7);
    }
    this->Array = v5;
    this->Size = size;
  }
}

// File Line: 603
// RVA: 0x9E1E20
void __fastcall Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::ensureCountAvailable(
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63> *this,
        unsigned int count)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *pLast; // rdi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v4; // rax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v5; // rax

  pLast = this->pLast;
  if ( pLast )
  {
    if ( count + pLast->Count <= 0x3F )
      return;
    v5 = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 1024i64, 0i64);
    this->pLast = v5;
    pLast->pNext = v5;
    v4 = this->pLast;
  }
  else
  {
    v4 = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 1024i64, 0i64);
    this->pPages = v4;
    this->pLast = v4;
  }
  v4->pNext = 0i64;
  this->pLast->Count = 0;
}

// File Line: 623
// RVA: 0xA05B20
void __fastcall Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::freePages(
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *this,
        bool keepLast)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *pPages; // rdi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *v5; // rsi
  __int64 i; // rbx
  Scaleform::Render::RenderBuffer *v7; // rcx

  pPages = this->pPages;
  v5 = 0i64;
  if ( this->pPages )
  {
    do
    {
      for ( i = 0i64; (unsigned int)i < pPages->Count; i = (unsigned int)(i + 1) )
      {
        v7 = (Scaleform::Render::RenderBuffer *)*((_QWORD *)&(&pPages->Items[0].Value.pSysFormat.pObject)[4 * i]
                                                + (unsigned int)i);
        if ( v7 )
          Scaleform::RefCountImpl::Release(v7);
      }
      if ( v5 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
      v5 = pPages;
      pPages = pPages->pNext;
    }
    while ( pPages );
    if ( !v5 )
      goto LABEL_12;
    if ( keepLast )
    {
      v5->Count = 0;
LABEL_12:
      this->pPages = v5;
      this->pLast = v5;
      return;
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
    this->pPages = 0i64;
    this->pLast = 0i64;
  }
  else
  {
    this->pPages = 0i64;
    this->pLast = 0i64;
  }
}

// File Line: 660
// RVA: 0x9FBA10
void __fastcall Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::~PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>(
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *this)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::freePages(
    this,
    0);
}

// File Line: 695
// RVA: 0xA09330
Scaleform::Render::VertexElement *__fastcall Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::AddItems(
        Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32> *this,
        Scaleform::Render::VertexElement *source,
        unsigned int count)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::Page *pLast; // r9
  Scaleform::Render::VertexElement *result; // rax
  Scaleform::Render::VertexElement *v8; // r9
  signed __int64 v9; // rbx
  __int64 v10; // rdx

  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::ensureCountAvailable(this, count);
  pLast = this->pLast;
  result = &pLast->Items[pLast->Count];
  if ( count )
  {
    v8 = &pLast->Items[pLast->Count];
    v9 = (char *)source - (char *)result;
    v10 = count;
    do
    {
      if ( v8 )
        *v8 = *(Scaleform::Render::VertexElement *)((char *)v8 + v9);
      ++v8;
      --v10;
    }
    while ( v10 );
  }
  this->pLast->Count += count;
  return result;
}

// File Line: 1040
// RVA: 0x9E7B70
bool __fastcall Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(
        Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *this,
        unsigned int depth)
{
  unsigned int v4; // edi
  Scaleform::Render::TreeCacheNode **v5; // rax
  Scaleform::Render::TreeCacheNode **v6; // rsi
  unsigned int v7; // edx
  unsigned int v8; // edi
  __int64 v9; // rcx

  v4 = (depth + 31) & 0xFFFFFFE0;
  v5 = (Scaleform::Render::TreeCacheNode **)this->pHeap->vfptr->Alloc(this->pHeap, 8i64 * v4, 0i64);
  v6 = v5;
  if ( v5 )
  {
    memmove(v5, this->pDepth, 8i64 * this->DepthUsed);
    v7 = 0;
    v8 = v4 - this->DepthUsed;
    if ( v8 )
    {
      do
      {
        v9 = v7 + this->DepthUsed;
        ++v7;
        v6[v9] = this->NullValue;
      }
      while ( v7 < v8 );
    }
    if ( this->pDepth != this->ArrayReserve )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    this->pDepth = v6;
    this->DepthAvailable = depth;
    LOBYTE(v5) = 1;
  }
  return (char)v5;
}

// File Line: 1071
// RVA: 0x9483A0
void __fastcall Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::~DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>(
        Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *this)
{
  if ( this->pDepth != this->ArrayReserve )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 1097
// RVA: 0x9989C0
void __fastcall Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::Link(
        Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *this,
        unsigned int index,
        Scaleform::Render::TreeCacheNode **pnext,
        Scaleform::Render::TreeCacheNode *val)
{
  __int64 v6; // rdi
  __int64 v8; // rdx
  unsigned int v9; // edi

  v6 = index;
  if ( index < this->DepthAvailable
    || Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(this, index + 1) )
  {
    v8 = v6;
    v9 = v6 + 1;
    *pnext = this->pDepth[v8];
    this->pDepth[v8] = val;
    if ( this->DepthUsed < v9 )
      this->DepthUsed = v9;
  }
}

// File Line: 1143
// RVA: 0x9CBE10
Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *__fastcall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Render::MeshCacheItem *,2>::allocInsertCopy(
        Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *this,
        unsigned __int64 index,
        Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *source,
        unsigned __int64 size,
        unsigned __int64 allocSize)
{
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *result; // rax
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v9; // rbx

  result = (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                                      Scaleform::Memory::pGlobalHeap,
                                                                      this,
                                                                      8 * allocSize,
                                                                      0i64);
  v9 = result;
  if ( result )
  {
    if ( index )
      memmove(result, source, 8 * index);
    if ( index < size )
      memmove(&v9[index + 1], &source[index], 8 * (size - index));
    return v9;
  }
  return result;
}

// File Line: 1163
// RVA: 0x9E8CF0
Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *__fastcall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::insertSpot(
        Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *this,
        unsigned __int64 index)
{
  unsigned __int64 Size; // r9
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v5; // rdi
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *inserted; // rax
  unsigned __int64 allocSize; // rsi
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v9; // rax
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v10; // r14

  Size = this->Size;
  if ( this->Size < 2 )
  {
    if ( index < Size )
      memmove(&this->Raw[8 * index + 8], &(&this->AD.pData)[index], 8 * (Size - index));
    v5 = (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)&(&this->AD.pData)[index];
    goto LABEL_15;
  }
  if ( this->Size == 2 )
  {
    inserted = Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Render::MeshCacheItem *,2>::allocInsertCopy(
                 this,
                 index,
                 (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)&this->8,
                 2ui64,
                 4ui64);
    if ( !inserted )
      return 0i64;
    v5 = &inserted[index];
    this->AD.pData = inserted;
    this->AD.Reserve = 4i64;
  }
  else
  {
    if ( Size < this->AD.Reserve )
    {
      if ( index < Size )
        memmove(&this->AD.pData[index + 1], &this->AD.pData[index], 8 * (Size - index));
      v5 = &this->AD.pData[index];
      goto LABEL_15;
    }
    allocSize = (Size + 4) & 0xFFFFFFFFFFFFFFFCui64;
    v9 = Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Render::MeshCacheItem *,2>::allocInsertCopy(
           this,
           index,
           this->AD.pData,
           Size,
           allocSize);
    v10 = v9;
    if ( !v9 )
      return 0i64;
    v5 = &v9[index];
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->AD.pData);
    this->AD.pData = v10;
    this->AD.Reserve = allocSize;
  }
LABEL_15:
  ++this->Size;
  return v5;
}

// File Line: 1218
// RVA: 0x948030
void __fastcall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::~ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>(
        Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *this)
{
  unsigned __int64 Size; // rdi
  $01882366495A2482556485982BC413F8 *v3; // r14
  $01882366495A2482556485982BC413F8 *pData; // rbx
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v5; // rcx

  Size = this->Size;
  v3 = &this->8;
  if ( this->Size <= 2 )
    pData = &this->8;
  else
    pData = ($01882366495A2482556485982BC413F8 *)v3->AD.pData;
  for ( ; Size; --Size )
  {
    v5 = pData->AD.pData;
    if ( pData->AD.pData && !_InterlockedDecrement((volatile signed __int32 *)&v5[1]) && v5 )
      ((void (__fastcall *)(Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *, __int64))v5->pObject->vfptr)(
        v5,
        1i64);
    pData = ($01882366495A2482556485982BC413F8 *)((char *)pData + 8);
  }
  if ( this->Size > 2 )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3->AD.pData);
}

// File Line: 1257
// RVA: 0x9A9640
void __fastcall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::RemoveAt(
        Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *this,
        unsigned __int64 index)
{
  $01882366495A2482556485982BC413F8 *v4; // rdi
  $01882366495A2482556485982BC413F8 *pData; // rax
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v6; // rcx
  char *v7; // rsi
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v8; // rdx

  v4 = &this->8;
  if ( this->Size <= 2 )
    pData = &this->8;
  else
    pData = ($01882366495A2482556485982BC413F8 *)v4->AD.pData;
  v6 = (&pData->AD.pData)[index];
  v7 = &pData->Raw[8 * index];
  if ( v6 && !_InterlockedDecrement((volatile signed __int32 *)&v6[1]) )
    ((void (__fastcall *)(Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *, __int64))v6->pObject->vfptr)(
      v6,
      1i64);
  memmove(v7, v7 + 8, 8 * (this->Size - index) - 8);
  if ( --this->Size == 2 )
  {
    v8 = v4->AD.pData;
    v4->AD.pData = (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)v4->AD.pData->pObject;
    *(Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)&v4->Raw[8] = v8[1];
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 1288
// RVA: 0x95F180
void __fastcall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::Clear(
        Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *this)
{
  unsigned __int64 Size; // rdi
  $01882366495A2482556485982BC413F8 *v3; // r14
  $01882366495A2482556485982BC413F8 *pData; // rbx
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v5; // rcx

  Size = this->Size;
  v3 = &this->8;
  if ( this->Size <= 2 )
    pData = &this->8;
  else
    pData = ($01882366495A2482556485982BC413F8 *)v3->AD.pData;
  for ( ; Size; --Size )
  {
    v5 = pData->AD.pData;
    if ( pData->AD.pData && !_InterlockedDecrement((volatile signed __int32 *)&v5[1]) && v5 )
      ((void (__fastcall *)(Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *, __int64))v5->pObject->vfptr)(
        v5,
        1i64);
    pData = ($01882366495A2482556485982BC413F8 *)((char *)pData + 8);
  }
  if ( this->Size > 2 )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3->AD.pData);
  this->Size = 0i64;
}

// File Line: 1315
// RVA: 0x948D00
void __fastcall Scaleform::Render::BitSet::~BitSet(Scaleform::Render::BitSet *this)
{
  if ( this->pData != &this->Local )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))this->pHeap->vfptr->Free)(this->pHeap);
}

// File Line: 1542
// RVA: 0x9FB9E0
void __fastcall Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::~MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>(
        Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *this)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::freePages(
    &this->ValueBuffer,
    0);
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::~PagedItemBuffer<Scaleform::Render::VertexElement,32>((Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63> *)this);
}

// File Line: 1546
// RVA: 0xA09480
Scaleform::Render::VertexFormat *__fastcall Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Find(
        Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *this,
        Scaleform::Render::VertexElement *keys,
        unsigned int count)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *pPages; // rsi
  unsigned int v6; // edi
  unsigned int v7; // ebx
  Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem *Items; // r11
  unsigned int v9; // edx
  Scaleform::Render::VertexElement *v10; // rax
  $3C54659889F1EB765F9D24AEEC355797 *v11; // r8

  pPages = this->ValueBuffer.pPages;
  if ( !pPages )
    return 0i64;
  while ( 1 )
  {
    v6 = pPages->Count;
    v7 = 0;
    if ( v6 )
      break;
LABEL_12:
    pPages = pPages->pNext;
    if ( !pPages )
      return 0i64;
  }
  Items = pPages->Items;
  while ( 1 )
  {
    if ( Items->KeyCount == count )
    {
      v9 = 0;
      if ( count )
      {
        v10 = keys;
        v11 = &Items->pKey->4;
        do
        {
          if ( *(unsigned int *)((char *)&v10->Offset + (char *)Items->pKey - (char *)keys) != v10->Offset )
            break;
          if ( v11->Attribute != v10->Attribute )
            break;
          ++v9;
          ++v10;
          v11 += 2;
        }
        while ( v9 < count );
      }
      if ( v9 == count )
        return &Items->Value;
    }
    ++v7;
    ++Items;
    if ( v7 >= v6 )
      goto LABEL_12;
  }
}

// File Line: 1583
// RVA: 0xA09280
Scaleform::Render::VertexFormat *__fastcall Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Add(
        Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *this,
        Scaleform::Render::VertexElement **ppnewKeys,
        Scaleform::Render::VertexElement *keys,
        unsigned int count)
{
  char *v7; // rdx

  *ppnewKeys = Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::AddItems(
                 &this->KeyBuffer,
                 keys,
                 count);
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::ensureCountAvailable(
    &this->ValueBuffer,
    1u);
  v7 = (char *)this->ValueBuffer.pLast->Items + 32 * this->ValueBuffer.pLast->Count + 8 * this->ValueBuffer.pLast->Count;
  if ( v7 )
    *((_QWORD *)v7 + 4) = 0i64;
  ++this->ValueBuffer.pLast->Count;
  if ( !*ppnewKeys || !v7 )
    return 0i64;
  *(_QWORD *)v7 = *ppnewKeys;
  *((_DWORD *)v7 + 2) = count;
  return (Scaleform::Render::VertexFormat *)(v7 + 16);
}

