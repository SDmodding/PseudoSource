// File Line: 51
// RVA: 0x94B1F0
void __fastcall Scaleform::Render::LinearHeap::~LinearHeap(Scaleform::Render::LinearHeap *this)
{
  Scaleform::Render::LinearHeap::ClearAndRelease(this);
}

// File Line: 65
// RVA: 0x9602A0
void __fastcall Scaleform::Render::LinearHeap::ClearAndRelease(Scaleform::Render::LinearHeap *this)
{
  unsigned __int64 v1; // rax
  Scaleform::Render::LinearHeap *v2; // rbx
  char **v3; // rdi
  Scaleform::MemoryHeap *v4; // rcx

  v1 = this->MaxPages;
  v2 = this;
  if ( v1 )
  {
    v3 = &this->pPagePool->pStart + 3 * v1 - 3;
    do
    {
      --v2->MaxPages;
      if ( *v3 )
        ((void (*)(void))v2->pHeap->vfptr->Free)();
      v3 -= 3;
    }
    while ( v2->MaxPages );
    v4 = v2->pHeap;
    --v2->MaxPages;
    v4->vfptr->Free(v4, v2->pPagePool);
  }
  v2->pLastPage = 0i64;
  v2->pPagePool = 0i64;
  v2->MaxPages = 0i64;
}

// File Line: 94
// RVA: 0x6DA530
void *__fastcall Scaleform::Render::LinearHeap::Alloc(Scaleform::Render::LinearHeap *this, unsigned __int64 size)
{
  Scaleform::Render::LinearHeap *v2; // rdi
  unsigned __int64 v3; // rbp
  void *result; // rax
  Scaleform::Render::LinearHeap::PageType *v5; // rax
  signed __int64 v6; // rdx
  signed __int64 v7; // rsi
  Scaleform::Render::LinearHeap::PageType *v8; // rbx
  unsigned __int64 v9; // rax

  v2 = this;
  v3 = (size + 7) & 0xFFFFFFFFFFFFFFF8ui64;
  if ( this->pLastPage )
  {
    result = Scaleform::Render::LinearHeap::allocFromLastPage(this, (size + 7) & 0xFFFFFFFFFFFFFFF8ui64);
    if ( result )
      return result;
    ++v2->pLastPage;
  }
  else
  {
    v5 = (Scaleform::Render::LinearHeap::PageType *)this->pHeap->vfptr->Alloc(this->pHeap, 1536ui64, 0i64);
    v2->pPagePool = v5;
    v2->pLastPage = v5;
    memset(v5, 0, 0x600ui64);
    v2->MaxPages = 64i64;
  }
  v6 = v2->MaxPages;
  v7 = ((unsigned __int64)((unsigned __int128)(((char *)v2->pLastPage - (char *)v2->pPagePool)
                                             * (signed __int128)3074457345618258603i64) >> 64) >> 63)
     + ((signed __int64)((unsigned __int128)(((char *)v2->pLastPage - (char *)v2->pPagePool)
                                           * (signed __int128)3074457345618258603i64) >> 64) >> 2);
  if ( v7 >= v6 )
  {
    v8 = (Scaleform::Render::LinearHeap::PageType *)v2->pHeap->vfptr->Alloc(v2->pHeap, 48 * v6, 0i64);
    memmove(v8, v2->pPagePool, 24 * v2->MaxPages);
    memset(&v8[v2->MaxPages], 0, 24 * v2->MaxPages);
    v2->pHeap->vfptr->Free(v2->pHeap, v2->pPagePool);
    v9 = v2->MaxPages;
    v2->pPagePool = v8;
    v2->MaxPages = 2 * v9;
    v2->pLastPage = &v8[v7];
  }
  return Scaleform::Render::LinearHeap::allocFromLastPage(v2, v3);
}

// File Line: 129
// RVA: 0x724D90
char *__fastcall Scaleform::Render::LinearHeap::allocFromLastPage(Scaleform::Render::LinearHeap *this, unsigned __int64 size)
{
  signed __int64 v2; // rbx
  Scaleform::Render::LinearHeap *v3; // rdi
  Scaleform::Render::LinearHeap::PageType *v4; // rcx
  char *v5; // rdx
  char *v6; // rax
  char *result; // rax

  v2 = size;
  v3 = this;
  v4 = this->pLastPage;
  v5 = v4->pFree;
  v6 = (char *)(v4->pEnd - v5);
  if ( (signed __int64)v6 < v2 )
  {
    if ( v5 == v4->pStart )
    {
      if ( (signed __int64)v6 < v2 )
        Scaleform::Render::LinearHeap::allocPage(v3, v2);
      v3->pLastPage->pFree += v2;
      result = v3->pLastPage->pStart;
    }
    else
    {
      result = 0i64;
    }
  }
  else
  {
    v4->pFree = &v5[v2];
    result = &v3->pLastPage->pFree[-v2];
  }
  return result;
}

// File Line: 149
// RVA: 0x724E10
void __fastcall Scaleform::Render::LinearHeap::allocPage(Scaleform::Render::LinearHeap *this, unsigned __int64 size)
{
  unsigned __int64 v2; // rbx
  Scaleform::Render::LinearHeap *v3; // rdi
  unsigned __int64 v4; // rbx
  __int64 v5; // rax

  v2 = size;
  v3 = this;
  if ( this->pLastPage->pStart )
    ((void (*)(void))this->pHeap->vfptr->Free)();
  v4 = v3->Granularity * ((v3->Granularity + v2 - 1) / v3->Granularity);
  v5 = (__int64)v3->pHeap->vfptr->Alloc(v3->pHeap, v4, 0i64);
  v3->pLastPage->pFree = (char *)v5;
  v3->pLastPage->pStart = (char *)v5;
  v3->pLastPage->pEnd = &v3->pLastPage->pStart[v4];
}

// File Line: 200
// RVA: 0x9A21F0
void __fastcall Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::BaseLineType,4,4>::PushBack(Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::BaseLineType,4,4> *this, Scaleform::Render::Tessellator::BaseLineType *val)
{
  Scaleform::Render::Tessellator::BaseLineType *v2; // rsi
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::BaseLineType,4,4> *v3; // rdi
  unsigned __int64 v4; // rbx
  _DWORD *v5; // rdx

  v2 = val;
  v3 = this;
  v4 = this->Size >> 4;
  if ( v4 >= this->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4> *)this,
      this->Size >> 4);
  v5 = (_DWORD *)&v3->Pages[v4][v3->Size & 0xF].y;
  *v5 = LODWORD(v2->y);
  v5[1] = v2->styleLeft;
  v5[2] = v2->vertexLeft;
  v5[3] = v2->vertexRight;
  v5[4] = v2->firstChain;
  v5[5] = v2->numChains;
  v5[6] = v2->leftAbove;
  ++v3->Size;
}

// File Line: 246
// RVA: 0x9CCDB0
void __fastcall Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4>::allocPage(Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4> *this, unsigned __int64 nb)
{
  unsigned __int64 v2; // rsi
  unsigned __int64 v3; // rdx
  Scaleform::Render::ArrayPaged<Scaleform::Render::TessMesh,4,4> *v4; // rdi
  void *v5; // rbx
  unsigned __int64 v6; // rax

  v2 = nb;
  v3 = this->MaxPages;
  v4 = this;
  if ( v2 >= v3 )
  {
    if ( this->Pages )
    {
      v5 = Scaleform::Render::LinearHeap::Alloc(this->pHeap, 16 * v3);
      memmove(v5, v4->Pages, 8 * v4->NumPages);
      v6 = v4->MaxPages;
      v4->Pages = (Scaleform::Render::TessMesh **)v5;
      v4->MaxPages = 2 * v6;
    }
    else
    {
      this->MaxPages = 4i64;
      this->Pages = (Scaleform::Render::TessMesh **)Scaleform::Render::LinearHeap::Alloc(this->pHeap, 0x20ui64);
    }
  }
  v4->Pages[v2] = (Scaleform::Render::TessMesh *)Scaleform::Render::LinearHeap::Alloc(v4->pHeap, 0x1C0ui64);
  ++v4->NumPages;
}

// File Line: 342
// RVA: 0x953F00
void __fastcall Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *this)
{
  unsigned __int64 v1; // rax
  unsigned __int64 v2; // rdx
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *v3; // rdi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v4; // rbx
  unsigned __int64 v5; // rax
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v6; // rax

  v1 = this->NumArrays;
  v2 = this->MaxArrays;
  v3 = this;
  if ( v1 >= v2 )
  {
    if ( v1 )
    {
      v4 = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)Scaleform::Render::LinearHeap::Alloc(this->pHeap, v2 << 6);
      memmove(v4, v3->Arrays, 32 * v3->NumArrays);
      v5 = v3->MaxArrays;
      v3->Arrays = v4;
      v3->MaxArrays = 2 * v5;
    }
    else
    {
      this->MaxArrays = 16i64;
      this->Arrays = (Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *)Scaleform::Render::LinearHeap::Alloc(this->pHeap, 0x200ui64);
    }
  }
  v6 = &v3->Arrays[v3->NumArrays];
  v6->Size = 0i64;
  v6->NumPages = 0i64;
  v6->MaxPages = 0i64;
  v6->Pages = 0i64;
  ++v3->NumArrays;
}

// File Line: 377
// RVA: 0x9A2150
void __fastcall Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::PushBack(Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *this, unsigned __int64 i, Scaleform::Render::Tessellator::TriangleType *val)
{
  Scaleform::Render::Tessellator::TriangleType *v3; // r14
  unsigned __int64 v4; // rsi
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *v5; // rbp
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v6; // rdi
  unsigned __int64 v7; // rbx
  Scaleform::Render::Tessellator::TriangleType *v8; // rdx

  v3 = val;
  v4 = i;
  v5 = this;
  v6 = &this->Arrays[i];
  v7 = v6->Size >> 4;
  if ( v7 >= v6->NumPages )
    Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(
      this,
      &this->Arrays[i],
      v6->Size >> 4);
  v8 = &v6->Pages[v7][v6->Size & 0xF];
  v8->d.m.v1 = v3->d.m.v1;
  v8->d.m.v2 = v3->d.m.v2;
  v8->d.m.v3 = v3->d.m.v3;
  ++v5->Arrays[v4].Size;
}

// File Line: 423
// RVA: 0x9B7610
char __fastcall Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::Split(Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *this, unsigned __int64 i, unsigned __int64 at)
{
  unsigned __int64 v3; // r14
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *v4; // r15
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v5; // rax
  unsigned __int64 v6; // r13
  unsigned __int64 v8; // r12
  unsigned __int64 v9; // rbp
  unsigned __int64 v10; // rbx
  unsigned __int64 v11; // rsi
  unsigned __int64 v12; // rdi
  signed __int64 v13; // rcx

  v3 = i;
  v4 = this;
  v5 = &this->Arrays[i];
  v6 = v5->Size;
  if ( at >= v5->Size )
    return 0;
  v8 = at >> 4;
  v9 = at & 0xFFFFFFFFFFFFFFF0ui64;
  v10 = v5->MaxPages - (at >> 4);
  v11 = (unsigned __int64)&v5->Pages[at >> 4];
  v12 = v5->NumPages - (at >> 4);
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::AddArray(this);
  v4->Arrays[v3].NumPages = v8;
  v4->Arrays[v3].MaxPages = v8;
  v4->Arrays[v3].Size = v9;
  v13 = v4->NumArrays - 1;
  v4->Arrays[v13].NumPages = v12;
  v4->Arrays[v13].MaxPages = v10;
  v4->Arrays[v13].Size = v6 - v9;
  v4->Arrays[v13].Pages = (Scaleform::Render::Tessellator::TriangleType **)v11;
  return 1;
}

// File Line: 449
// RVA: 0x9CC3A0
void __fastcall Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::allocPage(Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *this, Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *a, unsigned __int64 nb)
{
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16>::ArrayType *v3; // rdi
  unsigned __int64 v4; // rdx
  unsigned __int64 v5; // rbp
  Scaleform::Render::ArrayJagged<Scaleform::Render::Tessellator::TriangleType,4,16> *v6; // rsi
  void *v7; // rbx
  unsigned __int64 v8; // rax

  v3 = a;
  v4 = a->MaxPages;
  v5 = nb;
  v6 = this;
  if ( nb >= v4 )
  {
    if ( v3->Pages )
    {
      v7 = Scaleform::Render::LinearHeap::Alloc(this->pHeap, 16 * v4);
      memmove(v7, v3->Pages, 8 * v3->NumPages);
      v8 = v3->MaxPages;
      v3->Pages = (Scaleform::Render::Tessellator::TriangleType **)v7;
      v3->MaxPages = 2 * v8;
    }
    else
    {
      v3->MaxPages = 16i64;
      v3->Pages = (Scaleform::Render::Tessellator::TriangleType **)Scaleform::Render::LinearHeap::Alloc(
                                                                     this->pHeap,
                                                                     0x80ui64);
    }
  }
  v3->Pages[v5] = (Scaleform::Render::Tessellator::TriangleType *)Scaleform::Render::LinearHeap::Alloc(
                                                                    v6->pHeap,
                                                                    0x180ui64);
  ++v3->NumPages;
}

// File Line: 507
// RVA: 0x9AC6D0
void __fastcall Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::Cell *>::Resize(Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::SortedY> *this, unsigned __int64 size)
{
  unsigned __int64 v2; // rsi
  Scaleform::Render::ArrayUnsafe<Scaleform::Render::Rasterizer::SortedY> *v3; // rdi
  size_t v4; // rbx
  Scaleform::Render::Rasterizer::SortedY *v5; // rbp
  Scaleform::Render::Rasterizer::SortedY *v6; // rdx
  unsigned __int64 v7; // r8

  v2 = size;
  v3 = this;
  if ( size <= this->Size )
  {
    this->Size = size;
  }
  else
  {
    v4 = 8 * size;
    v5 = (Scaleform::Render::Rasterizer::SortedY *)Scaleform::Render::LinearHeap::Alloc(this->pHeap, 8 * size);
    memset(v5, 0, v4);
    v6 = v3->Array;
    if ( v6 )
    {
      v7 = v3->Size;
      if ( v7 )
        memmove(v5, v6, 8 * v7);
    }
    v3->Array = v5;
    v3->Size = v2;
  }
}

// File Line: 603
// RVA: 0x9E1E20
void __fastcall Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::ensureCountAvailable(Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63> *this, unsigned int count)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v2; // rdi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63> *v3; // rbx
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v4; // rax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *v5; // rax

  v2 = this->pLast;
  v3 = this;
  if ( v2 )
  {
    if ( count + v2->Count <= 0x3F )
      return;
    v5 = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 1024ui64, 0i64);
    v3->pLast = v5;
    v2->pNext = v5;
    v4 = v3->pLast;
  }
  else
  {
    v4 = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63>::Page *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 1024ui64, 0i64);
    v3->pPages = v4;
    v3->pLast = v4;
  }
  v4->pNext = 0i64;
  v3->pLast->Count = 0;
}

// File Line: 623
// RVA: 0xA05B20
void __fastcall Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::freePages(Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *this, bool keepLast)
{
  bool v2; // bp
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *v3; // r14
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *v4; // rdi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *v5; // rsi
  __int64 v6; // rbx
  Scaleform::Render::RenderBuffer *v7; // rcx

  v2 = keepLast;
  v3 = this;
  v4 = this->pPages;
  v5 = 0i64;
  if ( this->pPages )
  {
    do
    {
      v6 = 0i64;
      if ( v4->Count )
      {
        do
        {
          v7 = (Scaleform::Render::RenderBuffer *)*((_QWORD *)&v4->Items[0].Value.Size + (unsigned int)v6
                                                                                       + 2i64
                                                                                       + 4 * v6);
          if ( v7 )
            Scaleform::RefCountImpl::Release(v7);
          v6 = (unsigned int)(v6 + 1);
        }
        while ( (unsigned int)v6 < v4->Count );
      }
      if ( v5 )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
      v5 = v4;
      v4 = v4->pNext;
    }
    while ( v4 );
    if ( !v5 )
      goto LABEL_12;
    if ( v2 )
    {
      v5->Count = 0;
LABEL_12:
      v3->pPages = v5;
      v3->pLast = v5;
      return;
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
    v3->pPages = 0i64;
    v3->pLast = 0i64;
  }
  else
  {
    this->pPages = 0i64;
    this->pLast = 0i64;
  }
}

// File Line: 660
// RVA: 0x9FBA10
void __fastcall Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::~PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>(Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8> *this)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::freePages(
    this,
    0);
}

// File Line: 695
// RVA: 0xA09330
Scaleform::Render::VertexElement *__fastcall Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::AddItems(Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32> *this, Scaleform::Render::VertexElement *source, unsigned int count)
{
  Scaleform::Render::VertexElement *v3; // rbx
  unsigned int v4; // edi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32> *v5; // rsi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::Page *v6; // r9
  Scaleform::Render::VertexElement *result; // rax
  Scaleform::Render::VertexElement *v8; // r9
  signed __int64 v9; // rbx
  __int64 v10; // rdx

  v3 = source;
  v4 = count;
  v5 = this;
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::ensureCountAvailable(this, count);
  v6 = v5->pLast;
  result = &v6->Items[v6->Count];
  if ( v4 )
  {
    v8 = &v6->Items[v6->Count];
    v9 = (char *)v3 - (char *)result;
    v10 = v4;
    do
    {
      if ( v8 )
        *v8 = *(Scaleform::Render::VertexElement *)((char *)v8 + v9);
      ++v8;
      --v10;
    }
    while ( v10 );
  }
  v5->pLast->Count += v4;
  return result;
}

// File Line: 1040
// RVA: 0x9E7B70
bool __fastcall Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *this, unsigned int depth)
{
  unsigned int v2; // ebp
  Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *v3; // rbx
  unsigned int v4; // edi
  Scaleform::Render::TreeCacheNode **v5; // rax
  Scaleform::Render::TreeCacheNode **v6; // rsi
  unsigned int v7; // edx
  unsigned int v8; // edi
  __int64 v9; // rcx

  v2 = depth;
  v3 = this;
  v4 = (depth + 31) & 0xFFFFFFE0;
  v5 = (Scaleform::Render::TreeCacheNode **)this->pHeap->vfptr->Alloc(this->pHeap, 8i64 * v4, 0i64);
  v6 = v5;
  if ( v5 )
  {
    memmove(v5, v3->pDepth, 8i64 * v3->DepthUsed);
    v7 = 0;
    v8 = v4 - v3->DepthUsed;
    if ( v8 )
    {
      do
      {
        v9 = v7++ + v3->DepthUsed;
        v6[v9] = v3->NullValue;
      }
      while ( v7 < v8 );
    }
    if ( v3->pDepth != v3->ArrayReserve )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v3->pDepth = v6;
    v3->DepthAvailable = v2;
    LOBYTE(v5) = 1;
  }
  return (char)v5;
}

// File Line: 1071
// RVA: 0x9483A0
void __fastcall Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::~DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>(Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *this)
{
  if ( this->pDepth != this->ArrayReserve )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 1097
// RVA: 0x9989C0
void __fastcall Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::Link(Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *this, unsigned int index, Scaleform::Render::TreeCacheNode **pnext, Scaleform::Render::TreeCacheNode *val)
{
  Scaleform::Render::TreeCacheNode *v4; // rsi
  Scaleform::Render::TreeCacheNode **v5; // r14
  signed __int64 v6; // rdi
  Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *v7; // rbx
  signed __int64 v8; // rdx
  unsigned int v9; // edi

  v4 = val;
  v5 = pnext;
  v6 = index;
  v7 = this;
  if ( index < this->DepthAvailable
    || Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(this, index + 1) )
  {
    v8 = v6;
    v9 = v6 + 1;
    *v5 = v7->pDepth[v8];
    v7->pDepth[v8] = v4;
    if ( v7->DepthUsed < v9 )
      v7->DepthUsed = v9;
  }
}

// File Line: 1143
// RVA: 0x9CBE10
Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *__fastcall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Render::MeshCacheItem *,2>::allocInsertCopy(Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *this, unsigned __int64 index, Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *source, unsigned __int64 size, unsigned __int64 allocSize)
{
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v5; // r14
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // rdi
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *result; // rax
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v9; // rbx

  v5 = source;
  v6 = index;
  v7 = size;
  result = (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                                      Scaleform::Memory::pGlobalHeap,
                                                                      this,
                                                                      8 * allocSize,
                                                                      0i64);
  v9 = result;
  if ( result )
  {
    if ( v6 )
      memmove(result, v5, 8 * v6);
    if ( v6 < v7 )
      memmove(&v9[v6 + 1], &v5[v6], 8 * (v7 - v6));
    result = v9;
  }
  return result;
}

// File Line: 1163
// RVA: 0x9E8CF0
Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *__fastcall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::insertSpot(Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *this, unsigned __int64 index)
{
  unsigned __int64 v2; // r9
  unsigned __int64 v3; // rdi
  Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *v4; // rbx
  signed __int64 v5; // rdi
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v6; // rax
  unsigned __int64 allocSize; // rsi
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v9; // rax
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v10; // r14

  v2 = this->Size;
  v3 = index;
  v4 = this;
  if ( this->Size < 2 )
  {
    if ( index < v2 )
      memmove(&this->Raw[8 * index + 8], &(&this->AD.pData)[index], 8 * (v2 - index));
    v5 = (signed __int64)v4 + 8 * (v3 + 1);
    goto LABEL_15;
  }
  if ( this->Size == 2 )
  {
    v6 = Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Render::MeshCacheItem *,2>::allocInsertCopy(
           this,
           index,
           (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)&this->8,
           2ui64,
           4ui64);
    if ( !v6 )
      return 0i64;
    v5 = (signed __int64)&v6[v3];
    v4->AD.pData = v6;
    v4->AD.Reserve = 4i64;
  }
  else
  {
    if ( v2 < this->AD.Reserve )
    {
      if ( index < v2 )
        memmove(&this->AD.pData[index + 1], &this->AD.pData[index], 8 * (v2 - index));
      v5 = (signed __int64)&v4->AD.pData[v3];
      goto LABEL_15;
    }
    allocSize = (v2 + 4) & 0xFFFFFFFFFFFFFFFCui64;
    v9 = Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Render::MeshCacheItem *,2>::allocInsertCopy(
           this,
           index,
           this->AD.pData,
           v2,
           allocSize);
    v10 = v9;
    if ( !v9 )
      return 0i64;
    v5 = (signed __int64)&v9[v3];
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v4->AD.pData);
    v4->AD.pData = v10;
    v4->AD.Reserve = allocSize;
  }
LABEL_15:
  ++v4->Size;
  return (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)v5;
}

// File Line: 1218
// RVA: 0x948030
void __fastcall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::~ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>(Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *this)
{
  unsigned __int64 v1; // rdi
  Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *v2; // rsi
  void **v3; // r14
  __int64 *v4; // rbx
  __int64 v5; // rcx

  v1 = this->Size;
  v2 = this;
  v3 = (void **)&this->AD.pData;
  if ( this->Size <= 2 )
    v4 = (__int64 *)&this->8;
  else
    v4 = (__int64 *)*v3;
  for ( ; v1; --v1 )
  {
    v5 = *v4;
    if ( *v4 && !_InterlockedDecrement((volatile signed __int32 *)(v5 + 8)) && v5 )
      (**(void (__fastcall ***)(__int64, signed __int64))v5)(v5, 1i64);
    ++v4;
  }
  if ( v2->Size > 2 )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v3);
}

// File Line: 1257
// RVA: 0x9A9640
void __fastcall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::RemoveAt(Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *this, unsigned __int64 index)
{
  unsigned __int64 v2; // rbp
  Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *v3; // rbx
  $01882366495A2482556485982BC413F8 *v4; // rdi
  $01882366495A2482556485982BC413F8 *v5; // rax
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v6; // rcx
  unsigned __int64 v7; // rsi
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *v8; // rdx

  v2 = index;
  v3 = this;
  v4 = &this->8;
  if ( this->Size <= 2 )
    v5 = &this->8;
  else
    v5 = ($01882366495A2482556485982BC413F8 *)v4->AD.pData;
  v6 = (&v5->AD.pData)[index];
  v7 = (unsigned __int64)v5 + 8 * index;
  if ( v6 && !_InterlockedDecrement((volatile signed __int32 *)&v6[1]) && v6 )
    ((void (__fastcall *)(Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *, signed __int64))v6->pObject->vfptr)(
      v6,
      1i64);
  memmove((void *)v7, (const void *)(v7 + 8), 8 * (v3->Size - v2) - 8);
  if ( --v3->Size == 2 )
  {
    v8 = v4->AD.pData;
    v4->AD.pData = (Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *)v4->AD.pData->pObject;
    v4->AD.Reserve = (unsigned __int64)v8[1].pObject;
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 1288
// RVA: 0x95F180
void __fastcall Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::Clear(Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *this)
{
  unsigned __int64 v1; // rdi
  Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2> *v2; // rsi
  void **v3; // r14
  __int64 *v4; // rbx
  __int64 v5; // rcx

  v1 = this->Size;
  v2 = this;
  v3 = (void **)&this->AD.pData;
  if ( this->Size <= 2 )
    v4 = (__int64 *)&this->8;
  else
    v4 = (__int64 *)*v3;
  for ( ; v1; --v1 )
  {
    v5 = *v4;
    if ( *v4 && !_InterlockedDecrement((volatile signed __int32 *)(v5 + 8)) && v5 )
      (**(void (__fastcall ***)(__int64, signed __int64))v5)(v5, 1i64);
    ++v4;
  }
  if ( v2->Size > 2 )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v3);
  v2->Size = 0i64;
}

// File Line: 1315
// RVA: 0x948D00
void __fastcall Scaleform::Render::BitSet::~BitSet(Scaleform::Render::BitSet *this)
{
  if ( this->pData != &this->Local )
    ((void (*)(void))this->pHeap->vfptr->Free)();
}

// File Line: 1542
// RVA: 0x9FB9E0
void __fastcall Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::~MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>(Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *this)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63> *v1; // rbx

  v1 = (Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,63> *)this;
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::freePages(
    &this->ValueBuffer,
    0);
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::~PagedItemBuffer<Scaleform::Render::VertexElement,32>(v1);
}

// File Line: 1546
// RVA: 0xA09480
Scaleform::Render::VertexFormat *__fastcall Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Find(Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *this, Scaleform::Render::VertexElement *keys, unsigned int count)
{
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::Page *v3; // rsi
  unsigned int v4; // er9
  Scaleform::Render::VertexElement *v5; // rbp
  unsigned int v6; // edi
  unsigned int v7; // ebx
  signed __int64 v8; // r11
  unsigned int v9; // edx
  Scaleform::Render::VertexElement *v10; // rax
  _DWORD *v11; // r8

  v3 = this->ValueBuffer.pPages;
  v4 = count;
  v5 = keys;
  if ( !v3 )
    return 0i64;
  while ( 1 )
  {
    v6 = v3->Count;
    v7 = 0;
    if ( v6 )
      break;
LABEL_12:
    v3 = v3->pNext;
    if ( !v3 )
      return 0i64;
  }
  v8 = (signed __int64)v3->Items;
  while ( 1 )
  {
    if ( *(_DWORD *)(v8 + 8) == v4 )
    {
      v9 = 0;
      if ( v4 )
      {
        v10 = v5;
        v11 = (_DWORD *)(*(_QWORD *)v8 + 4i64);
        do
        {
          if ( *(unsigned int *)((char *)&v10->Offset + *(_QWORD *)v8 - (_QWORD)v5) != v10->Offset )
            break;
          if ( *v11 != v10->Attribute )
            break;
          ++v9;
          ++v10;
          v11 += 2;
        }
        while ( v9 < v4 );
      }
      if ( v9 == v4 )
        return (Scaleform::Render::VertexFormat *)(v8 + 16);
    }
    ++v7;
    v8 += 40i64;
    if ( v7 >= v6 )
      goto LABEL_12;
  }
}

// File Line: 1583
// RVA: 0xA09280
Scaleform::Render::VertexFormat *__fastcall Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::Add(Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *this, Scaleform::Render::VertexElement **ppnewKeys, Scaleform::Render::VertexElement *keys, unsigned int count)
{
  unsigned int v4; // edi
  Scaleform::Render::VertexElement **v5; // rsi
  Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8> *v6; // rbx
  signed __int64 v7; // rdx

  v4 = count;
  v5 = ppnewKeys;
  v6 = this;
  *ppnewKeys = Scaleform::Render::PagedItemBuffer<Scaleform::Render::VertexElement,32>::AddItems(
                 &this->KeyBuffer,
                 keys,
                 count);
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::MultiKeyCollection<Scaleform::Render::VertexElement,Scaleform::Render::VertexFormat,32,8>::ValueItem,8>::ensureCountAvailable(
    &v6->ValueBuffer,
    1u);
  v7 = (signed __int64)v6->ValueBuffer.pLast
     + 8 * (v6->ValueBuffer.pLast->Count + 4i64 * v6->ValueBuffer.pLast->Count + 2);
  if ( v7 )
    *(_QWORD *)(v7 + 32) = 0i64;
  ++v6->ValueBuffer.pLast->Count;
  if ( !*v5 || !v7 )
    return 0i64;
  *(_QWORD *)v7 = *v5;
  *(_DWORD *)(v7 + 8) = v4;
  return (Scaleform::Render::VertexFormat *)(v7 + 16);
}

