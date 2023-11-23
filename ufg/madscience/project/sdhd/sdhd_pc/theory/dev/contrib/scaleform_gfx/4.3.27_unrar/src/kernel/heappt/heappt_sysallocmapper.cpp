// File Line: 39
// RVA: 0x945430
void __fastcall Scaleform::SysAllocMapper::SysAllocMapper(
        Scaleform::SysAllocMapper *this,
        Scaleform::SysMemMapper *mapper,
        unsigned __int64 segSize,
        unsigned __int64 granularity,
        bool bestFit)
{
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rbx

  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocBase::`vftable;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocPaged::`vftable;
  this->vfptr = (Scaleform::SysAllocBaseVtbl *)&Scaleform::SysAllocMapper::`vftable;
  this->pMapper = mapper;
  this->PageSize = 0i64;
  this->SegmSize = segSize;
  v6 = 1i64;
  if ( granularity )
    v6 = granularity;
  this->Granularity = v6;
  this->Footprint = 0i64;
  this->NumSegments = 0i64;
  this->LastSegment = -1i64;
  this->BestFit = bestFit;
  this->LastUsed = 0i64;
  v7 = mapper->vfptr->GetPageSize(mapper);
  this->PageSize = v7;
  this->PageShift = (unsigned __int8)Scaleform::Alg::UpperBit(v7);
  this->Granularity = (v7 + this->Granularity - 1) & ~(v7 - 1);
  this->Footprint = 0i64;
  this->NumSegments = 0i64;
  this->LastSegment = -1i64;
}

// File Line: 64
// RVA: 0x987560
void __fastcall Scaleform::SysAllocMapper::GetInfo(Scaleform::SysAllocMapper *this, Scaleform::SysAllocPaged::Info *i)
{
  unsigned __int64 Granularity; // rax

  i->MinAlign = this->PageSize;
  i->MaxAlign = 0i64;
  Granularity = this->Granularity;
  i->HasRealloc = 1;
  if ( Granularity <= 0x1000 )
    Granularity = 0i64;
  i->Granularity = Granularity;
}

// File Line: 100
// RVA: 0x9CF4E0
__int64 __fastcall Scaleform::SysAllocMapper::binarySearch(Scaleform::SysAllocMapper *this, char *ptr)
{
  __int64 NumSegments; // rax
  __int64 v3; // r9
  __int64 v5; // rdx

  NumSegments = this->NumSegments;
  v3 = 0i64;
  while ( NumSegments > 0 )
  {
    v5 = (NumSegments >> 1) + v3;
    if ( this->Segments[v5].Memory >= ptr )
    {
      NumSegments >>= 1;
    }
    else
    {
      v3 = v5 + 1;
      NumSegments += -1 - (NumSegments >> 1);
    }
  }
  return v3;
}

// File Line: 125
// RVA: 0x9E3060
unsigned __int64 __fastcall Scaleform::SysAllocMapper::findSegment(Scaleform::SysAllocMapper *this, char *ptr)
{
  __int64 NumSegments; // r8
  unsigned __int64 v3; // r10
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rcx
  unsigned __int64 result; // rax
  char *Memory; // rax
  unsigned __int64 v10; // rdx

  NumSegments = this->NumSegments;
  v3 = 0i64;
  if ( NumSegments > 0 )
  {
    do
    {
      v6 = (NumSegments >> 1) + v3;
      if ( this->Segments[v6].Memory >= ptr )
      {
        NumSegments >>= 1;
      }
      else
      {
        v3 = v6 + 1;
        NumSegments += -1 - (NumSegments >> 1);
      }
    }
    while ( NumSegments > 0 );
    if ( v3 )
    {
      v7 = *(&this->SegmSize + 3 * v3);
      if ( (unsigned __int64)ptr >= v7 && (unsigned __int64)ptr < this->SegmSize + v7 )
        return v3 - 1;
    }
  }
  if ( v3 >= this->NumSegments )
    return this->NumSegments;
  Memory = this->Segments[v3].Memory;
  if ( ptr < Memory )
    return this->NumSegments;
  v10 = (unsigned __int64)&Memory[this->SegmSize];
  result = v3;
  if ( (unsigned __int64)ptr >= v10 )
    return this->NumSegments;
  return result;
}

// File Line: 141
// RVA: 0x9F05C0
char __fastcall Scaleform::SysAllocMapper::reserveSegment(Scaleform::SysAllocMapper *this, unsigned __int64 size)
{
  unsigned __int64 PageSize; // r9
  unsigned __int64 SegmSize; // rbx
  unsigned __int64 v6; // r11
  __int64 v7; // r10
  char *v8; // rbp
  unsigned __int64 Granularity; // rcx
  unsigned __int64 v11; // rsi
  char *v12; // rax
  char *v13; // r14
  unsigned __int64 v14; // r9
  unsigned __int64 PageShift; // r10
  char *v16; // r8
  unsigned __int64 v17; // rsi
  unsigned __int64 NumSegments; // rax
  unsigned __int64 v19; // rax

  if ( this->NumSegments >= 0x20 )
    return 0;
  PageSize = this->PageSize;
  SegmSize = this->SegmSize;
  v6 = this->PageShift + 3;
  v7 = ~(PageSize - 1);
  if ( SegmSize - (v7 & (((SegmSize + 8 * PageSize - 1) >> (LOBYTE(this->PageShift) + 3)) + PageSize - 1)) < size )
    SegmSize = this->Granularity
             * ((this->Granularity + (v7 & (((size - 1 + 8 * PageSize) >> v6) + PageSize - 1)) + size - 1)
              / this->Granularity);
  for ( ; SegmSize - (v7 & (((SegmSize + 8 * PageSize - 1) >> v6) + PageSize - 1)) < size; SegmSize += this->Granularity )
    ;
  while ( 1 )
  {
    v8 = (char *)this->pMapper->vfptr->ReserveAddrSpace(this->pMapper, SegmSize);
    if ( v8 )
      break;
    Granularity = this->Granularity;
    SegmSize = Granularity * (((SegmSize >> 1) + Granularity - 1) / Granularity);
    if ( SegmSize < 2 * Granularity
      || SegmSize
       - (~(this->PageSize - 1) & (((SegmSize + 8 * this->PageSize - 1) >> (LOBYTE(this->PageShift) + 3))
                                 + this->PageSize
                                 - 1)) < size )
    {
      return 0;
    }
  }
  v11 = ~(this->PageSize - 1) & (((SegmSize + 8 * this->PageSize - 1) >> (LOBYTE(this->PageShift) + 3))
                               + this->PageSize
                               - 1);
  v12 = (char *)this->pMapper->vfptr->MapPages(this->pMapper, &v8[SegmSize - v11], v11);
  v13 = v12;
  if ( v12 )
  {
    memset(v12, 0, v11 & 0xFFFFFFFFFFFFFFFCui64);
    v14 = this->PageSize;
    PageShift = this->PageShift;
    v16 = &v13[4
             * ((SegmSize - (~(v14 - 1) & (((SegmSize + 8 * v14 - 1) >> ((unsigned __int8)PageShift + 3)) + v14 - 1))) >> PageShift >> 5)];
    *(_DWORD *)v16 |= 1 << (((SegmSize
                            - (~(v14 - 1) & (((SegmSize + 8 * v14 - 1) >> ((unsigned __int8)PageShift + 3)) + v14 - 1))) >> PageShift) & 0x1F);
    v17 = Scaleform::SysAllocMapper::binarySearch(this, v8);
    NumSegments = this->NumSegments;
    if ( v17 < NumSegments )
      memmove(&this->Segments[v17 + 1], &this->Segments[v17], 24 * (NumSegments - v17));
    ++this->NumSegments;
    v19 = v17;
    this->Segments[v19].Memory = v8;
    this->Segments[v19].Size = SegmSize;
    this->Segments[v19].PageCount = 0i64;
    return 1;
  }
  else
  {
    this->pMapper->vfptr->ReleaseAddrSpace(this->pMapper, v8, SegmSize);
    return 0;
  }
}

// File Line: 206
// RVA: 0x9EFCD0
void __fastcall Scaleform::SysAllocMapper::releaseSegment(Scaleform::SysAllocMapper *this, unsigned __int64 pos)
{
  unsigned __int64 PageSize; // r9
  unsigned __int64 Size; // r11
  char *v4; // rbp
  unsigned __int64 NumSegments; // rcx

  PageSize = this->PageSize;
  Size = this->Segments[pos].Size;
  v4 = (char *)this + 24 * pos;
  this->pMapper->vfptr->UnmapPages(
    this->pMapper,
    (void *)(Size
           + *((_QWORD *)v4 + 7)
           - (~(PageSize - 1) & (((Size + 8 * PageSize - 1) >> ((unsigned __int8)this->PageShift + 3)) + PageSize - 1))),
    ~(PageSize - 1) & (((Size + 8 * PageSize - 1) >> ((unsigned __int8)this->PageShift + 3)) + PageSize - 1));
  this->pMapper->vfptr->ReleaseAddrSpace(this->pMapper, (void *)*((_QWORD *)v4 + 7), *((_QWORD *)v4 + 8));
  NumSegments = this->NumSegments;
  if ( pos + 1 < NumSegments )
    memmove(v4 + 56, v4 + 80, 24 * (NumSegments - pos - 1));
  --this->NumSegments;
  this->LastSegment = -1i64;
}

// File Line: 249
// RVA: 0x9CBF40
char *__fastcall Scaleform::SysAllocMapper::allocMem(
        Scaleform::SysAllocMapper *this,
        unsigned __int64 pos,
        unsigned __int64 size,
        unsigned __int64 alignment)
{
  unsigned __int64 PageSize; // r13
  unsigned __int64 PageShift; // rbx
  __int64 v7; // r9
  unsigned __int64 v8; // r10
  char **v9; // rax
  char *v10; // rsi
  char *v11; // r11
  unsigned __int64 v12; // r14
  unsigned int *v13; // rdi
  unsigned __int64 v14; // r15
  __int64 v15; // r12
  unsigned __int64 v16; // rsi
  unsigned __int64 v17; // rbx
  unsigned __int64 v18; // rsi
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rcx
  unsigned int v21; // edx
  unsigned int v22; // r8d
  unsigned int v23; // r8d
  int v24; // ecx
  int v25; // ecx
  unsigned __int64 v26; // rdx
  unsigned __int64 i; // rcx
  unsigned __int64 v28; // rcx
  __int64 v29; // rcx
  __int64 v30; // rcx
  unsigned __int64 FreeSize; // rax
  unsigned __int64 v32; // rbx
  char *v33; // rsi
  unsigned __int64 v34; // rax
  char **v36; // [rsp+70h] [rbp+8h]

  PageSize = this->PageSize;
  PageShift = this->PageShift;
  v7 = ~(PageSize - 1);
  v8 = size;
  v9 = &this->Segments[0].Memory + 2 * pos + pos;
  v10 = v9[1];
  v11 = *v9;
  v36 = v9;
  v12 = size >> PageShift;
  v13 = (unsigned int *)&(*v9)[(_QWORD)v10
                             - (v7 & (((unsigned __int64)&v10[8 * PageSize - 1] >> ((unsigned __int8)PageShift + 3))
                                    + PageSize
                                    - 1))];
  v14 = -1i64;
  v15 = -1i64;
  v16 = (unsigned __int64)&v10[-(v7 & (((unsigned __int64)&v10[8 * PageSize - 1] >> ((unsigned __int8)PageShift + 3))
                                     + PageSize
                                     - 1))];
  v17 = 0i64;
  v18 = v16 >> this->PageShift;
  if ( !v18 )
    goto LABEL_31;
  do
  {
    v19 = v17 >> 5;
    v20 = v17 & 0x1F;
    if ( ((v13[v17 >> 5] >> v20) & 1) != 0 )
    {
      v21 = Scaleform::HeapPT::BitSet1::HeadUsedTable[v20];
      v22 = v21 & v13[v19];
      if ( v22 == v21 )
      {
        v26 = 32 - v20;
        for ( i = 32 * (v19 + 1); i < v18; v26 += 32i64 )
        {
          ++v19;
          i += 32i64;
          if ( v13[v19] != -1 )
            break;
        }
        v28 = v13[v19];
        if ( (_WORD)v28 == 0xFFFF )
        {
          if ( (v28 & 0xFFFFFF) == 0xFFFFFF )
            v30 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[v28 >> 24] + 24;
          else
            v30 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[BYTE2(v28)] + 16;
          v17 += v30 + v26;
        }
        else
        {
          if ( (_BYTE)v28 == 0xFF )
            v29 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[BYTE1(v28)] + 8;
          else
            v29 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[(unsigned __int8)v28];
          v17 += v29 + v26;
        }
      }
      else
      {
        v23 = v22 >> v20;
        if ( (_WORD)v23 == 0xFFFF )
        {
          if ( (v23 & 0xFFFFFF) == 0xFFFFFF )
            v25 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[(unsigned __int64)v23 >> 24] + 24;
          else
            v25 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[BYTE2(v23)] + 16;
          v17 += v25;
        }
        else
        {
          if ( (_BYTE)v23 == 0xFF )
            v24 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[BYTE1(v23)] + 8;
          else
            v24 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[(unsigned __int8)v23];
          v17 += v24;
        }
      }
      continue;
    }
    FreeSize = Scaleform::HeapPT::BitSet1::FindFreeSize(v13, v17);
    v8 = size;
    v11 = *v36;
    if ( size + (~(alignment - 1) & (unsigned __int64)&(*v36)[v17 * PageSize - 1 + alignment]) <= (unsigned __int64)&(*v36)[v17 * PageSize + FreeSize * PageSize]
      && FreeSize - v12 < v14 )
    {
      v15 = v17;
      v14 = FreeSize - v12;
      if ( !this->BestFit )
        break;
    }
    v17 += FreeSize;
  }
  while ( v17 < v18 );
  if ( v15 == 0xFFFFFFFFi64 )
  {
    v33 = 0i64;
  }
  else
  {
LABEL_31:
    v32 = v15
        + ((__int64)((~(alignment - 1) & (unsigned __int64)&v11[v15 * PageSize - 1 + alignment])
                   - v15 * PageSize
                   - (_QWORD)v11) >> this->PageShift);
    v33 = (char *)this->pMapper->vfptr->MapPages(this->pMapper, &v11[PageSize * v32], v8);
    if ( v33 )
    {
      Scaleform::HeapPT::BitSet1::SetUsed(v13, v32, v12);
      v36[2] += v12;
      this->Footprint += v12 << this->PageShift;
    }
  }
  v34 = -1i64;
  if ( v33 )
    v34 = pos;
  this->LastSegment = v34;
  this->LastUsed = &v33[size];
  return v33;
}

// File Line: 310
// RVA: 0x9CC2F0
char *__fastcall Scaleform::SysAllocMapper::allocMem(
        Scaleform::SysAllocMapper *this,
        unsigned __int64 size,
        unsigned __int64 alignment)
{
  unsigned __int64 LastSegment; // rdx
  char *result; // rax
  unsigned __int64 i; // rbx

  LastSegment = this->LastSegment;
  if ( LastSegment != -1i64 )
  {
    result = Scaleform::SysAllocMapper::allocMem(this, LastSegment, size, alignment);
    if ( result )
      return result;
    this->LastUsed = 0i64;
  }
  for ( i = 0i64; i < this->NumSegments; ++i )
  {
    if ( i != this->LastSegment )
    {
      result = Scaleform::SysAllocMapper::allocMem(this, i, size, alignment);
      if ( result )
        return result;
      this->LastUsed = 0i64;
    }
  }
  return 0i64;
}

// File Line: 338
// RVA: 0x9E35D0
unsigned __int64 __fastcall Scaleform::SysAllocMapper::freeMem(
        Scaleform::SysAllocMapper *this,
        char *ptr,
        unsigned __int64 size)
{
  unsigned __int64 Segment; // rsi
  Scaleform::SysAllocBaseVtbl **v7; // rbx
  unsigned __int64 PageShift; // rcx
  unsigned __int64 v9; // r14

  Segment = Scaleform::SysAllocMapper::findSegment(this, ptr);
  v7 = &(&this->vfptr)[3 * Segment];
  this->pMapper->vfptr->UnmapPages(this->pMapper, ptr, size);
  PageShift = this->PageShift;
  v9 = size >> PageShift;
  Scaleform::HeapPT::BitSet1::SetFree(
    (unsigned int *)((char *)v7[7]
                   + (_QWORD)v7[8]
                   - (~(this->PageSize - 1) & ((((unsigned __int64)v7[8] + 8 * this->PageSize - 1) >> ((unsigned __int8)PageShift + 3))
                                             + this->PageSize
                                             - 1))),
    (ptr - (char *)v7[7]) >> PageShift,
    v9);
  v7[9] = (Scaleform::SysAllocBaseVtbl *)((char *)v7[9] - v9);
  this->Footprint -= v9 << this->PageShift;
  return Segment;
}

// File Line: 360
// RVA: 0x956D50
void *__fastcall Scaleform::SysAllocMapper::Alloc(
        Scaleform::SysAllocMapper *this,
        unsigned __int64 size,
        unsigned __int64 alignment)
{
  unsigned __int64 PageSize; // rdi
  unsigned __int64 v5; // rbx
  void *result; // rax

  PageSize = alignment;
  if ( alignment < this->PageSize )
    PageSize = this->PageSize;
  v5 = ~(PageSize - 1) & (PageSize + size - 1);
  result = Scaleform::SysAllocMapper::allocMem(this, v5, PageSize);
  if ( !result )
  {
    if ( Scaleform::SysAllocMapper::reserveSegment(this, v5) )
      return Scaleform::SysAllocMapper::allocMem(this, v5, PageSize);
    else
      return 0i64;
  }
  return result;
}

// File Line: 381
// RVA: 0x9A7090
char __fastcall Scaleform::SysAllocMapper::ReallocInPlace(
        Scaleform::SysAllocMapper *this,
        const char *oldPtr,
        unsigned __int64 oldSize,
        unsigned __int64 newSize,
        unsigned __int64 alignment)
{
  unsigned __int64 PageSize; // rbp
  unsigned __int64 v7; // rcx
  __int64 v9; // rax
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // rsi
  char result; // al
  unsigned __int64 Segment; // rax
  unsigned __int64 PageShift; // r10
  unsigned __int64 v15; // rsi
  Scaleform::SysAllocBaseVtbl **v16; // r15
  __int64 v17; // r14
  unsigned __int64 v18; // rdi
  unsigned int *v19; // r12

  PageSize = this->PageSize;
  v7 = alignment;
  if ( alignment < PageSize )
    v7 = PageSize;
  v9 = ~(v7 - 1);
  v10 = v9 & (v7 + oldSize - 1);
  v11 = v9 & (v7 + newSize - 1);
  if ( v11 == v10 )
    return 1;
  if ( v11 <= v10 )
    return ((__int64 (__fastcall *)(Scaleform::SysAllocMapper *, const char *, unsigned __int64, unsigned __int64))this->vfptr[1].shutdownHeapEngine)(
             this,
             &oldPtr[v11],
             v10 - v11,
             v7);
  Segment = Scaleform::SysAllocMapper::findSegment(this, oldPtr);
  PageShift = this->PageShift;
  v15 = v11 - v10;
  v16 = &(&this->vfptr)[3 * Segment];
  v17 = (__int64)(v10 + oldPtr - (const char *)v16[7]) >> PageShift;
  v18 = v15 >> PageShift;
  v19 = (unsigned int *)((char *)v16[7]
                       + (_QWORD)v16[8]
                       - (~(PageSize - 1) & ((((unsigned __int64)v16[8] + 8 * PageSize - 1) >> ((unsigned __int8)PageShift
                                                                                              + 3))
                                           + PageSize
                                           - 1)));
  if ( Scaleform::HeapPT::BitSet1::FindFreeSize(v19, v17) < v15 >> PageShift
    || !this->pMapper->vfptr->MapPages(this->pMapper, (char *)v16[7] + v17 * PageSize, v15) )
  {
    return 0;
  }
  Scaleform::HeapPT::BitSet1::SetUsed(v19, v17, v18);
  v16[9] = (Scaleform::SysAllocBaseVtbl *)((char *)v16[9] + v18);
  result = 1;
  this->Footprint += v18 << this->PageShift;
  return result;
}

// File Line: 422
// RVA: 0x97DFF0
char __fastcall Scaleform::SysAllocMapper::Free(
        Scaleform::SysAllocMapper *this,
        void *ptr,
        unsigned __int64 size,
        unsigned __int64 alignment)
{
  unsigned __int64 v5; // rax

  if ( alignment < this->PageSize )
    alignment = this->PageSize;
  v5 = Scaleform::SysAllocMapper::freeMem(this, ptr, ~(alignment - 1) & (alignment + size - 1));
  if ( !this->Segments[v5].PageCount )
    Scaleform::SysAllocMapper::releaseSegment(this, v5);
  return 1;
}

// File Line: 439
// RVA: 0x9800B0
char *__fastcall Scaleform::SysAllocMapper::GetBase(Scaleform::SysAllocMapper *this)
{
  if ( this->NumSegments )
    return this->Segments[0].Memory;
  else
    return 0i64;
}

