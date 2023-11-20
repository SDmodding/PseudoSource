// File Line: 39
// RVA: 0x945430
void __fastcall Scaleform::SysAllocMapper::SysAllocMapper(Scaleform::SysAllocMapper *this, Scaleform::SysMemMapper *mapper, unsigned __int64 segSize, unsigned __int64 granularity, bool bestFit)
{
  Scaleform::SysAllocMapper *v5; // rdi
  signed __int64 v6; // rax
  unsigned __int64 v7; // rbx

  v5 = this;
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
  v5->PageSize = v7;
  v5->PageShift = (unsigned __int8)Scaleform::Alg::UpperBit(v7);
  v5->Granularity = (v7 + v5->Granularity - 1) & ~(v7 - 1);
  v5->Footprint = 0i64;
  v5->NumSegments = 0i64;
  v5->LastSegment = -1i64;
}

// File Line: 64
// RVA: 0x987560
void __fastcall Scaleform::SysAllocMapper::GetInfo(Scaleform::SysAllocMapper *this, Scaleform::SysAllocPaged::Info *i)
{
  unsigned __int64 v2; // rax

  i->MinAlign = this->PageSize;
  i->MaxAlign = 0i64;
  v2 = this->Granularity;
  i->HasRealloc = 1;
  if ( v2 <= 0x1000 )
    v2 = 0i64;
  i->Granularity = v2;
}

// File Line: 100
// RVA: 0x9CF4E0
signed __int64 __fastcall Scaleform::SysAllocMapper::binarySearch(Scaleform::SysAllocMapper *this, const char *ptr)
{
  signed __int64 v2; // rax
  signed __int64 v3; // r9
  char *v4; // r11
  signed __int64 v5; // rdx

  v2 = this->NumSegments;
  v3 = 0i64;
  v4 = (char *)ptr;
  while ( v2 > 0 )
  {
    v5 = (v2 >> 1) + v3;
    if ( this->Segments[v5].Memory >= v4 )
    {
      v2 >>= 1;
    }
    else
    {
      v3 = v5 + 1;
      v2 += -1 - (v2 >> 1);
    }
  }
  return v3;
}

// File Line: 125
// RVA: 0x9E3060
signed __int64 __fastcall Scaleform::SysAllocMapper::findSegment(Scaleform::SysAllocMapper *this, const char *ptr)
{
  signed __int64 v2; // r8
  unsigned __int64 v3; // r10
  const char *v4; // rbx
  Scaleform::SysAllocMapper *v5; // r11
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rcx
  signed __int64 result; // rax
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rdx

  v2 = this->NumSegments;
  v3 = 0i64;
  v4 = ptr;
  v5 = this;
  if ( v2 > 0 )
  {
    do
    {
      v6 = (v2 >> 1) + v3;
      if ( v5->Segments[v6].Memory >= ptr )
      {
        v2 >>= 1;
      }
      else
      {
        v3 = v6 + 1;
        v2 += -1 - (v2 >> 1);
      }
    }
    while ( v2 > 0 );
    if ( v3 )
    {
      v7 = *(&v5->SegmSize + 3 * v3);
      if ( (unsigned __int64)ptr >= v7 && (unsigned __int64)ptr < v5->SegmSize + v7 )
        return v3 - 1;
    }
  }
  if ( v3 >= v5->NumSegments
    || (v9 = (unsigned __int64)v5->Segments[v3].Memory, (unsigned __int64)ptr < v9)
    || (v10 = v9 + v5->SegmSize, result = v3, (unsigned __int64)v4 >= v10) )
  {
    result = v5->NumSegments;
  }
  return result;
}

// File Line: 141
// RVA: 0x9F05C0
char __fastcall Scaleform::SysAllocMapper::reserveSegment(Scaleform::SysAllocMapper *this, unsigned __int64 size)
{
  unsigned __int64 v2; // rsi
  Scaleform::SysAllocMapper *v3; // rdi
  unsigned __int64 v4; // r9
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // r11
  signed __int64 v7; // r10
  const char *v8; // rbp
  unsigned __int64 v9; // rcx
  char result; // al
  unsigned __int64 v11; // rsi
  char *v12; // rax
  char *v13; // r14
  unsigned __int64 v14; // r9
  unsigned __int64 v15; // r10
  char *v16; // r8
  unsigned __int64 v17; // rsi
  unsigned __int64 v18; // rax
  signed __int64 v19; // rax

  v2 = size;
  v3 = this;
  if ( this->NumSegments >= 0x20 )
    return 0;
  v4 = this->PageSize;
  v5 = this->SegmSize;
  v6 = this->PageShift + 3;
  v7 = ~(v4 - 1);
  if ( v5 - (v7 & (((v5 + 8 * v4 - 1) >> (LOBYTE(this->PageShift) + 3)) + v4 - 1)) < size )
    v5 = this->Granularity
       * ((this->Granularity + (v7 & (((size - 1 + 8 * v4) >> v6) + v4 - 1)) + size - 1)
        / this->Granularity);
  for ( ; v5 - (v7 & (((v5 + 8 * v4 - 1) >> v6) + v4 - 1)) < size; v5 += this->Granularity )
    ;
  while ( 1 )
  {
    v8 = (const char *)v3->pMapper->vfptr->ReserveAddrSpace(v3->pMapper, v5);
    if ( v8 )
      break;
    v9 = v3->Granularity;
    v5 = v9 * (((v5 >> 1) + v9 - 1) / v9);
    if ( v5 < 2 * v9
      || v5 - (~(v3->PageSize - 1) & (((v5 + 8 * v3->PageSize - 1) >> (LOBYTE(v3->PageShift) + 3)) + v3->PageSize - 1)) < v2 )
    {
      return 0;
    }
  }
  v11 = ~(v3->PageSize - 1) & (((v5 + 8 * v3->PageSize - 1) >> (LOBYTE(v3->PageShift) + 3)) + v3->PageSize - 1);
  v12 = (char *)v3->pMapper->vfptr->MapPages(v3->pMapper, (void *)&v8[v5 - v11], v11);
  v13 = v12;
  if ( v12 )
  {
    memset(v12, 0, v11 & 0xFFFFFFFFFFFFFFFCui64);
    v14 = v3->PageSize;
    v15 = v3->PageShift;
    v16 = &v13[4
             * ((v5 - (~(v14 - 1) & (((v5 + 8 * v14 - 1) >> ((unsigned __int8)v15 + 3)) + v14 - 1))) >> v3->PageShift >> 5)];
    *(_DWORD *)v16 |= 1 << (((v5 - (~(v14 - 1) & (((v5 + 8 * v14 - 1) >> ((unsigned __int8)v15 + 3)) + v14 - 1))) >> v3->PageShift) & 0x1F);
    v17 = Scaleform::SysAllocMapper::binarySearch(v3, v8);
    v18 = v3->NumSegments;
    if ( v17 < v18 )
      memmove(&v3->vfptr + 3 * v17 + 10, &v3->Segments[v17], 24 * (v18 - v17));
    ++v3->NumSegments;
    v19 = v17;
    v3->Segments[v19].Memory = (char *)v8;
    v3->Segments[v19].Size = v5;
    v3->Segments[v19].PageCount = 0i64;
    result = 1;
  }
  else
  {
    v3->pMapper->vfptr->ReleaseAddrSpace(v3->pMapper, (void *)v8, v5);
    result = 0;
  }
  return result;
}

// File Line: 206
// RVA: 0x9EFCD0
void __fastcall Scaleform::SysAllocMapper::releaseSegment(Scaleform::SysAllocMapper *this, unsigned __int64 pos)
{
  unsigned __int64 v2; // r9
  unsigned __int64 v3; // r11
  char *v4; // rbp
  unsigned __int64 v5; // r14
  Scaleform::SysAllocMapper *v6; // rdi
  unsigned __int64 v7; // rcx

  v2 = this->PageSize;
  v3 = this->Segments[pos].Size;
  v4 = (char *)this + 24 * pos;
  v5 = pos;
  v6 = this;
  this->pMapper->vfptr->UnmapPages(
    this->pMapper,
    (void *)(v3
           + *((_QWORD *)v4 + 7)
           - (~(v2 - 1) & (((v3 + 8 * v2 - 1) >> ((unsigned __int8)this->PageShift + 3)) + v2 - 1))),
    ~(v2 - 1) & (((v3 + 8 * v2 - 1) >> ((unsigned __int8)this->PageShift + 3)) + v2 - 1));
  v6->pMapper->vfptr->ReleaseAddrSpace(v6->pMapper, (void *)*((_QWORD *)v4 + 7), *((_QWORD *)v4 + 8));
  v7 = v6->NumSegments;
  if ( v5 + 1 < v7 )
    memmove(v4 + 56, v4 + 80, 24 * (v7 - v5 - 1));
  --v6->NumSegments;
  v6->LastSegment = -1i64;
}

// File Line: 249
// RVA: 0x9CBF40
__int64 __fastcall Scaleform::SysAllocMapper::allocMem(Scaleform::SysAllocMapper *this, unsigned __int64 pos, unsigned __int64 size, unsigned __int64 alignment)
{
  unsigned __int64 v4; // r13
  unsigned __int64 v5; // rbx
  Scaleform::SysAllocMapper *v6; // rbp
  signed __int64 v7; // r9
  unsigned __int64 v8; // r10
  Scaleform::SysAllocBaseVtbl **v9; // rax
  Scaleform::SysAllocBaseVtbl *v10; // rsi
  Scaleform::SysAllocBaseVtbl *v11; // r11
  unsigned __int64 v12; // r14
  unsigned int *v13; // rdi
  unsigned __int64 v14; // r15
  signed __int64 v15; // r12
  unsigned __int64 v16; // rsi
  unsigned __int64 v17; // rbx
  unsigned __int64 v18; // rsi
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rcx
  unsigned int v21; // edx
  unsigned int v22; // er8
  unsigned int v23; // er8
  int v24; // ecx
  int v25; // ecx
  signed __int64 v26; // rdx
  unsigned __int64 i; // rcx
  unsigned __int64 v28; // rcx
  __int64 v29; // rcx
  __int64 v30; // rcx
  signed __int64 v31; // rax
  unsigned __int64 v32; // rbx
  __int64 v33; // rsi
  signed __int64 v34; // rax
  Scaleform::SysAllocBaseVtbl **v36; // [rsp+70h] [rbp+8h]
  unsigned __int64 v37; // [rsp+78h] [rbp+10h]
  unsigned __int64 v38; // [rsp+80h] [rbp+18h]
  unsigned __int64 v39; // [rsp+88h] [rbp+20h]

  v39 = alignment;
  v38 = size;
  v37 = pos;
  v4 = this->PageSize;
  v5 = this->PageShift;
  v6 = this;
  v7 = ~(v4 - 1);
  v8 = size;
  v9 = &this->vfptr + pos + 2 * pos + 7;
  v10 = v9[1];
  v11 = *v9;
  v36 = &this->vfptr + pos + 2 * pos + 7;
  v12 = size >> v5;
  v13 = (unsigned int *)((char *)*v9
                       + (_QWORD)v10
                       - (v7 & ((((unsigned __int64)v10 + 8 * v4 - 1) >> ((unsigned __int8)v5 + 3)) + v4 - 1)));
  v14 = -1i64;
  v15 = -1i64;
  v16 = (unsigned __int64)v10 - (v7 & ((((unsigned __int64)v10 + 8 * v4 - 1) >> ((unsigned __int8)v5 + 3)) + v4 - 1));
  v17 = 0i64;
  v18 = v16 >> this->PageShift;
  if ( !v18 )
    goto LABEL_31;
  do
  {
    v19 = v17 >> 5;
    v20 = v17 & 0x1F;
    if ( (v13[v17 >> 5] >> v20) & 1 )
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
        if ( (_WORD)v28 == -1 )
        {
          if ( (v28 & 0xFFFFFF) == 0xFFFFFF )
            v30 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[v28 >> 24] + 24;
          else
            v30 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[BYTE2(v28)] + 16;
          v17 += v30 + v26;
        }
        else
        {
          if ( (_BYTE)v28 == -1 )
            v29 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[BYTE1(v28)] + 8;
          else
            v29 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[(unsigned __int8)v28];
          v17 += v29 + v26;
        }
      }
      else
      {
        v23 = v22 >> v20;
        if ( (_WORD)v23 == -1 )
        {
          if ( (v23 & 0xFFFFFF) == 0xFFFFFF )
            v25 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[(unsigned __int64)v23 >> 24] + 24;
          else
            v25 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[BYTE2(v23)] + 16;
          v17 += v25;
        }
        else
        {
          if ( (_BYTE)v23 == -1 )
            v24 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[BYTE1(v23)] + 8;
          else
            v24 = (unsigned __int8)Scaleform::HeapPT::BitSet1::LastUsedBlock[(unsigned __int8)v23];
          v17 += v24;
        }
      }
      continue;
    }
    v31 = Scaleform::HeapPT::BitSet1::FindFreeSize(v13, v17);
    v8 = v38;
    v11 = *v36;
    if ( v38 + (~(v39 - 1) & ((unsigned __int64)*v36 + v17 * v4 + v39 - 1)) <= (unsigned __int64)*v36
                                                                             + v17 * v4
                                                                             + v31 * v4
      && v31 - v12 < v14 )
    {
      v15 = v17;
      v14 = v31 - v12;
      if ( !v6->BestFit )
        break;
    }
    v17 += v31;
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
        + ((signed __int64)((~(v39 - 1) & ((unsigned __int64)v11 + v15 * v4 + v39 - 1)) - v15 * v4 - (_QWORD)v11) >> v6->PageShift);
    v33 = (__int64)v6->pMapper->vfptr->MapPages(
                     v6->pMapper,
                     (char *)v11
                   + v4
                   * (v15
                    + ((signed __int64)((~(v39 - 1) & ((unsigned __int64)v11 + v15 * v4 + v39 - 1))
                                      - v15 * v4
                                      - (_QWORD)v11) >> v6->PageShift)),
                     v8);
    if ( v33 )
    {
      Scaleform::HeapPT::BitSet1::SetUsed(v13, v32, v12);
      v36[2] = (Scaleform::SysAllocBaseVtbl *)((char *)v36[2] + v12);
      v6->Footprint += v12 << v6->PageShift;
    }
  }
  v34 = -1i64;
  if ( v33 )
    v34 = v37;
  v6->LastSegment = v34;
  v6->LastUsed = (char *)(v33 + v38);
  return v33;
}

// File Line: 310
// RVA: 0x9CC2F0
void *__fastcall Scaleform::SysAllocMapper::allocMem(Scaleform::SysAllocMapper *this, unsigned __int64 size, unsigned __int64 alignment)
{
  unsigned __int64 v3; // rbp
  unsigned __int64 v4; // rdx
  unsigned __int64 v5; // rsi
  Scaleform::SysAllocMapper *v6; // rdi
  void *result; // rax
  unsigned __int64 i; // rbx

  v3 = size;
  v4 = this->LastSegment;
  v5 = alignment;
  v6 = this;
  if ( v4 != -1i64 )
  {
    result = (void *)Scaleform::SysAllocMapper::allocMem(this, v4, v3, alignment);
    if ( result )
      return result;
    v6->LastUsed = 0i64;
  }
  for ( i = 0i64; i < v6->NumSegments; ++i )
  {
    if ( i != v6->LastSegment )
    {
      result = (void *)Scaleform::SysAllocMapper::allocMem(v6, i, v3, v5);
      if ( result )
        return result;
      v6->LastUsed = 0i64;
    }
  }
  return 0i64;
}

// File Line: 338
// RVA: 0x9E35D0
signed __int64 __fastcall Scaleform::SysAllocMapper::freeMem(Scaleform::SysAllocMapper *this, void *ptr, unsigned __int64 size)
{
  unsigned __int64 v3; // r14
  void *v4; // rdi
  Scaleform::SysAllocMapper *v5; // rbp
  signed __int64 v6; // rax
  signed __int64 v7; // rsi
  Scaleform::SysAllocBaseVtbl **v8; // rbx
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // r14

  v3 = size;
  v4 = ptr;
  v5 = this;
  v6 = Scaleform::SysAllocMapper::findSegment(this, (const char *)ptr);
  v7 = v6;
  v8 = &(&v5->vfptr)[3 * v6];
  v5->pMapper->vfptr->UnmapPages(v5->pMapper, v4, v3);
  v9 = v5->PageShift;
  v10 = v3 >> v9;
  Scaleform::HeapPT::BitSet1::SetFree(
    (unsigned int *)((char *)v8[7]
                   + (_QWORD)v8[8]
                   - (~(v5->PageSize - 1) & ((((unsigned __int64)v8[8] + 8 * v5->PageSize - 1) >> ((unsigned __int8)v9
                                                                                                 + 3))
                                           + v5->PageSize
                                           - 1))),
    ((_BYTE *)v4 - (_BYTE *)v8[7]) >> v9,
    v10);
  v8[9] = (Scaleform::SysAllocBaseVtbl *)((char *)v8[9] - v10);
  v5->Footprint -= v10 << v5->PageShift;
  return v7;
}

// File Line: 360
// RVA: 0x956D50
void *__fastcall Scaleform::SysAllocMapper::Alloc(Scaleform::SysAllocMapper *this, unsigned __int64 size, unsigned __int64 alignment)
{
  unsigned __int64 v3; // rdi
  Scaleform::SysAllocMapper *v4; // rsi
  signed __int64 v5; // rax
  unsigned __int64 v6; // rbx
  void *result; // rax

  v3 = alignment;
  if ( alignment < this->PageSize )
    v3 = this->PageSize;
  v4 = this;
  v5 = ~(v3 - 1);
  v6 = v5 & (v3 + size - 1);
  result = Scaleform::SysAllocMapper::allocMem(this, v5 & (v3 + size - 1), v3);
  if ( !result )
  {
    if ( Scaleform::SysAllocMapper::reserveSegment(v4, v6) )
      result = Scaleform::SysAllocMapper::allocMem(v4, v6, v3);
    else
      result = 0i64;
  }
  return result;
}

// File Line: 381
// RVA: 0x9A7090
char __fastcall Scaleform::SysAllocMapper::ReallocInPlace(Scaleform::SysAllocMapper *this, void *oldPtr, unsigned __int64 oldSize, unsigned __int64 newSize, unsigned __int64 alignment)
{
  unsigned __int64 v5; // rbp
  Scaleform::SysAllocMapper *v6; // rbx
  unsigned __int64 v7; // rcx
  _BYTE *v8; // r14
  signed __int64 v9; // rax
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // rsi
  char result; // al
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // r10
  unsigned __int64 v15; // rsi
  Scaleform::SysAllocBaseVtbl **v16; // r15
  unsigned __int64 v17; // r14
  unsigned __int64 v18; // rdi
  unsigned int *v19; // r12

  v5 = this->PageSize;
  v6 = this;
  v7 = alignment;
  if ( alignment < v5 )
    v7 = v5;
  v8 = oldPtr;
  v9 = ~(v7 - 1);
  v10 = v9 & (v7 + oldSize - 1);
  v11 = v9 & (v7 + newSize - 1);
  if ( v11 == v10 )
    return 1;
  if ( v11 <= v10 )
    return ((__int64 (__fastcall *)(Scaleform::SysAllocMapper *, char *, unsigned __int64, unsigned __int64))v6->vfptr[1].shutdownHeapEngine)(
             v6,
             (char *)oldPtr + v11,
             v10 - v11,
             v7);
  v13 = Scaleform::SysAllocMapper::findSegment(v6, (const char *)oldPtr);
  v14 = v6->PageShift;
  v15 = v11 - v10;
  v16 = &(&v6->vfptr)[3 * v13];
  v17 = (signed __int64)(v10 + v8 - v6->Segments[v13].Memory) >> v14;
  v18 = v15 >> v6->PageShift;
  v19 = (unsigned int *)((char *)v16[8]
                       + (unsigned __int64)&v6->Segments[v13].Memory[-(~(v5 - 1) & (((v6->Segments[v13].Size + 8 * v5 - 1) >> ((unsigned __int8)v14 + 3))
                                                                                  + v5
                                                                                  - 1))]);
  if ( Scaleform::HeapPT::BitSet1::FindFreeSize(v19, v17) < v18
    || !(__int64)v6->pMapper->vfptr->MapPages(v6->pMapper, (char *)v16[7] + v17 * v5, v15) )
  {
    return 0;
  }
  Scaleform::HeapPT::BitSet1::SetUsed(v19, v17, v18);
  v16[9] = (Scaleform::SysAllocBaseVtbl *)((char *)v16[9] + v18);
  result = 1;
  v6->Footprint += v18 << v6->PageShift;
  return result;
}

// File Line: 422
// RVA: 0x97DFF0
char __fastcall Scaleform::SysAllocMapper::Free(Scaleform::SysAllocMapper *this, void *ptr, unsigned __int64 size, unsigned __int64 alignment)
{
  Scaleform::SysAllocMapper *v4; // rbx
  unsigned __int64 v5; // rax

  v4 = this;
  if ( alignment < this->PageSize )
    alignment = this->PageSize;
  v5 = Scaleform::SysAllocMapper::freeMem(this, ptr, ~(alignment - 1) & (alignment + size - 1));
  if ( !v4->Segments[v5].PageCount )
    Scaleform::SysAllocMapper::releaseSegment(v4, v5);
  return 1;
}

// File Line: 439
// RVA: 0x9800B0
char *__fastcall Scaleform::SysAllocMapper::GetBase(Scaleform::SysAllocMapper *this)
{
  char *result; // rax

  if ( this->NumSegments )
    result = this->Segments[0].Memory;
  else
    result = 0i64;
  return result;
}

