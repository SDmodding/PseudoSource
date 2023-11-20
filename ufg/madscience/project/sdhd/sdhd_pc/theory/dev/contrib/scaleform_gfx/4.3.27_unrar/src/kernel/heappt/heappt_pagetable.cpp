// File Line: 45
// RVA: 0x9994F0
char __fastcall Scaleform::HeapPT::PageTable::MapRange(Scaleform::HeapPT::PageTable *this, void *mem, unsigned __int64 size)
{
  Scaleform::HeapPT::Granulator **v3; // r12
  unsigned __int64 v4; // rbp
  unsigned __int64 v5; // r14
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // rcx
  unsigned __int64 v8; // r15
  Scaleform::HeapPT::Granulator **v9; // r13
  Scaleform::HeapPT::DualTNode *v10; // rax
  unsigned __int64 v11; // rdi
  unsigned __int64 v12; // rdx
  signed __int64 v13; // rcx
  Scaleform::HeapPT::DualTNode **v14; // rbx
  Scaleform::HeapPT::DualTNode *v15; // rax
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // rbp
  unsigned __int64 v18; // rsi
  signed __int64 v19; // r13
  Scaleform::HeapPT::DualTNode **v20; // r14
  Scaleform::HeapPT::DualTNode *v21; // rax
  unsigned __int64 v22; // rdi
  unsigned __int64 v23; // r15
  signed __int64 v24; // rsi
  Scaleform::HeapPT::DualTNode *v25; // rbx
  Scaleform::HeapPT::DualTNode *v26; // rax
  unsigned __int64 v28; // [rsp+20h] [rbp-98h]
  unsigned __int64 v29; // [rsp+28h] [rbp-90h]
  signed __int64 v30; // [rsp+30h] [rbp-88h]
  signed __int64 v31; // [rsp+38h] [rbp-80h]
  signed __int64 v32; // [rsp+40h] [rbp-78h]
  signed __int64 v33; // [rsp+48h] [rbp-70h]
  unsigned __int64 v34; // [rsp+50h] [rbp-68h]
  unsigned __int64 v35; // [rsp+58h] [rbp-60h]
  unsigned __int64 v36; // [rsp+60h] [rbp-58h]
  Scaleform::HeapPT::DualTNode **v37; // [rsp+68h] [rbp-50h]
  unsigned __int64 v38; // [rsp+70h] [rbp-48h]
  unsigned __int64 mema; // [rsp+C8h] [rbp+10h]
  unsigned __int64 v40; // [rsp+D0h] [rbp+18h]
  signed __int64 v41; // [rsp+D8h] [rbp+20h]

  mema = (unsigned __int64)mem;
  v3 = (Scaleform::HeapPT::Granulator **)this;
  v4 = (unsigned __int64)mem >> 52;
  v5 = (unsigned __int64)mem + size - 1;
  v6 = (unsigned __int64)mem;
  v29 = (unsigned __int64)mem >> 52;
  v36 = (unsigned __int64)mem + size - 1;
  v7 = v5 >> 52;
  v8 = (unsigned __int64)mem >> 52;
  v40 = (unsigned __int64)mem >> 52;
  v35 = v5 >> 52;
  if ( (unsigned __int64)mem >> 52 > v5 >> 52 )
    return 1;
  v9 = &v3[2 * v4 + 1];
  v33 = (signed __int64)&v3[2 * v4 + 1];
  while ( 1 )
  {
    if ( !*v9 )
    {
      v10 = Scaleform::HeapPT::Granulator::Alloc(*v3, 0x10000ui64, 0x8000ui64);
      *v9 = (Scaleform::HeapPT::Granulator *)v10;
      if ( !v10 )
      {
        Scaleform::HeapPT::PageTable::UnmapRange((Scaleform::HeapPT::PageTable *)v3, (void *)v6, (v8 - v4) << 52);
        return 0;
      }
      memset(v10, 0, 0x10000ui64);
      v7 = v35;
    }
    v9[1] = (Scaleform::HeapPT::Granulator *)((char *)v9[1] + 1);
    v11 = 0i64;
    v12 = 4095i64;
    v41 = 0i64;
    v31 = 4095i64;
    if ( v8 == v4 )
    {
      v11 = (v6 >> 40) & 0xFFF;
      v41 = (v6 >> 40) & 0xFFF;
    }
    if ( v8 == v7 )
    {
      v12 = (v5 >> 40) & 0xFFF;
      v31 = (v5 >> 40) & 0xFFF;
    }
    v28 = v11;
    if ( v11 <= v12 )
      break;
LABEL_39:
    ++v8;
    v9 += 2;
    v40 = v8;
    v33 = (signed __int64)v9;
    if ( v8 > v7 )
      return 1;
  }
  v13 = 16 * v11;
  v32 = 16 * v11;
  while ( 1 )
  {
    v14 = (Scaleform::HeapPT::DualTNode **)((char *)*v9 + v13);
    v37 = (Scaleform::HeapPT::DualTNode **)((char *)*v9 + v13);
    if ( !*(Scaleform::SysAllocPaged **)((char *)&(*v9)->pSysAlloc + v13) )
    {
      v15 = Scaleform::HeapPT::Granulator::Alloc(*v3, 0x10000ui64, 0x8000ui64);
      *v14 = v15;
      if ( !v15 )
      {
        Scaleform::HeapPT::PageTable::UnmapRange(
          (Scaleform::HeapPT::PageTable *)v3,
          (void *)v6,
          (v11 + ((v40 - v29) << 12) - v28) << 40);
        return 0;
      }
      memset(v15, 0, 0x10000ui64);
      v12 = v31;
    }
    v14[1] = (Scaleform::HeapPT::DualTNode *)((char *)v14[1] + 1);
    v16 = 4095i64;
    v17 = 0i64;
    v30 = 4095i64;
    if ( v11 == v28 )
      v17 = (v6 >> 28) & 0xFFF;
    if ( v11 == v12 )
    {
      v16 = (v5 >> 28) & 0xFFF;
      v30 = (v5 >> 28) & 0xFFF;
    }
    v18 = v17;
    v34 = v17;
    if ( v17 <= v16 )
      break;
LABEL_37:
    v6 = mema;
    ++v11;
    v13 = v32 + 16;
    v41 = v11;
    v32 += 16i64;
    if ( v11 > v12 )
    {
      v8 = v40;
      v4 = v29;
      v7 = v35;
      goto LABEL_39;
    }
  }
  v19 = 16 * v17;
  while ( 1 )
  {
    v20 = (Scaleform::HeapPT::DualTNode **)((char *)&(*v14)->pPrev + v19);
    if ( !*v20 )
    {
      v21 = Scaleform::HeapPT::Granulator::Alloc(*v3, 0x1000ui64, 0x800ui64);
      *v20 = v21;
      if ( !v21 )
      {
        Scaleform::HeapPT::PageTable::UnmapRange(
          (Scaleform::HeapPT::PageTable *)v3,
          (void *)mema,
          (v17 + ((v41 + ((v40 - v29) << 12) - v28) << 12) - v18) << 28);
        return 0;
      }
      memset(v21, 0, 0x1000ui64);
      v16 = v30;
    }
    v20[1] = (Scaleform::HeapPT::DualTNode *)((char *)v20[1] + 1);
    v22 = 0i64;
    v23 = 255i64;
    if ( v17 == v18 )
      v22 = (unsigned __int8)(mema >> 20);
    if ( v17 == v16 )
      v23 = (unsigned __int8)(v36 >> 20);
    v38 = v22;
    if ( v22 <= v23 )
      break;
LABEL_35:
    ++v17;
    v19 += 16i64;
    if ( v17 > v16 )
    {
      v11 = v41;
      v5 = v36;
      v12 = v31;
      v9 = (Scaleform::HeapPT::Granulator **)v33;
      goto LABEL_37;
    }
  }
  v24 = 16 * v22;
  while ( 1 )
  {
    v25 = *v20;
    if ( !*(Scaleform::HeapPT::DualTNode **)((char *)&(*v20)->pPrev + v24) )
      break;
LABEL_33:
    ++*(Scaleform::HeapPT::DualTNode **)((char *)&v25->pNext + v24);
    ++v22;
    v24 += 16i64;
    if ( v22 > v23 )
    {
      v16 = v30;
      v14 = v37;
      v18 = v34;
      goto LABEL_35;
    }
  }
  v26 = Scaleform::HeapPT::Granulator::Alloc(*v3, 0x800ui64, 0x800ui64);
  *(Scaleform::HeapPT::DualTNode **)((char *)&v25->pPrev + v24) = v26;
  if ( v26 )
  {
    memset(v26, 0, 0x800ui64);
    goto LABEL_33;
  }
  Scaleform::HeapPT::PageTable::UnmapRange(
    (Scaleform::HeapPT::PageTable *)v3,
    (void *)mema,
    (v22 + ((v17 + ((v41 + ((v40 - v29) << 12) - v28) << 12) - v34) << 8) - v38) << 20);
  return 0;
}

// File Line: 173
// RVA: 0x9BB690
void __fastcall Scaleform::HeapPT::PageTable::UnmapRange(Scaleform::HeapPT::PageTable *this, void *mem, unsigned __int64 size)
{
  unsigned __int64 v3; // r9
  Scaleform::HeapPT::PageTable *v4; // rdx
  unsigned __int64 v5; // r10
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // r13
  unsigned __int64 v8; // rbp
  unsigned __int64 *v9; // r14
  unsigned __int64 v10; // r15
  unsigned __int64 v11; // r12
  unsigned __int64 v12; // r8
  signed __int64 v13; // rcx
  unsigned __int64 v14; // rbp
  unsigned __int64 v15; // r14
  unsigned __int64 v16; // r13
  unsigned __int64 *v17; // rbp
  unsigned __int64 v18; // r8
  signed __int64 v19; // r15
  unsigned __int64 v20; // r12
  unsigned __int64 v21; // rcx
  unsigned __int64 v22; // rbp
  unsigned __int64 *v23; // r12
  signed __int64 v24; // rsi
  signed __int64 v25; // rbp
  unsigned __int64 v26; // rbx
  Scaleform::HeapPT::Granulator *v27; // r14
  bool v28; // zf
  Scaleform::HeapPT::TreeSeg *v29; // r15
  Scaleform::HeapPT::Granulator *v30; // rdi
  Scaleform::HeapPT::TreeSeg *v31; // rsi
  Scaleform::HeapPT::Granulator *v32; // rsi
  Scaleform::HeapPT::TreeSeg *v33; // rdi
  Scaleform::HeapPT::Granulator *v34; // rsi
  Scaleform::HeapPT::TreeSeg *v35; // rdi
  signed __int64 v36; // [rsp+30h] [rbp-A8h]
  unsigned __int64 v37; // [rsp+38h] [rbp-A0h]
  signed __int64 v38; // [rsp+40h] [rbp-98h]
  unsigned __int64 v39; // [rsp+48h] [rbp-90h]
  signed __int64 v40; // [rsp+50h] [rbp-88h]
  unsigned __int64 *v41; // [rsp+58h] [rbp-80h]
  signed __int64 v42; // [rsp+60h] [rbp-78h]
  unsigned __int64 v43; // [rsp+68h] [rbp-70h]
  unsigned __int64 v44; // [rsp+70h] [rbp-68h]
  unsigned __int64 v45; // [rsp+78h] [rbp-60h]
  unsigned __int64 v46; // [rsp+80h] [rbp-58h]
  Scaleform::HeapPT::PageTable *v47; // [rsp+E0h] [rbp+8h]
  void *v48; // [rsp+E8h] [rbp+10h]
  signed __int64 v49; // [rsp+F0h] [rbp+18h]
  signed __int64 v50; // [rsp+F8h] [rbp+20h]

  v48 = mem;
  v47 = this;
  v3 = (unsigned __int64)mem;
  v4 = this;
  v5 = v3 + size - 1;
  v6 = v3 >> 52;
  v37 = v3 + size - 1;
  v7 = v5 >> 52;
  v46 = v3 >> 52;
  v8 = v3 >> 52;
  v44 = v5 >> 52;
  v39 = v3 >> 52;
  if ( v3 >> 52 <= v5 >> 52 )
  {
    v9 = (unsigned __int64 *)&v4->RootTable[v6];
    v36 = (signed __int64)&v4->RootTable[v6];
    do
    {
      v10 = 0i64;
      v11 = 4095i64;
      v49 = 0i64;
      v38 = 4095i64;
      if ( v8 == v6 )
      {
        v10 = (v3 >> 40) & 0xFFF;
        v49 = (v3 >> 40) & 0xFFF;
      }
      if ( v8 == v7 )
      {
        v11 = (v5 >> 40) & 0xFFF;
        v38 = (v5 >> 40) & 0xFFF;
      }
      v12 = v10;
      v45 = v10;
      if ( v10 <= v11 )
      {
        v13 = 16 * v10;
        v50 = 16 * v10;
        do
        {
          v14 = *v9;
          v15 = 4095i64;
          v16 = 0i64;
          v17 = (unsigned __int64 *)(v13 + v14);
          v40 = 4095i64;
          v41 = v17;
          if ( v10 == v12 )
            v16 = (v3 >> 28) & 0xFFF;
          if ( v10 == v11 )
          {
            v15 = (v5 >> 28) & 0xFFF;
            v40 = (v5 >> 28) & 0xFFF;
          }
          v18 = v16;
          v43 = v16;
          if ( v16 <= v15 )
          {
            v19 = 16 * v16;
            v42 = 16 * v16;
            do
            {
              v20 = *v17;
              v21 = 0i64;
              v22 = 255i64;
              v23 = (unsigned __int64 *)(v19 + v20);
              if ( v16 == v18 )
                v21 = (unsigned __int8)(v3 >> 20);
              if ( v16 == v15 )
                v22 = (unsigned __int8)(v5 >> 20);
              if ( v21 <= v22 )
              {
                v24 = 16 * v21;
                v25 = v22 - v21 + 1;
                do
                {
                  v26 = *v23;
                  v27 = &v4->pStarter->Allocator;
                  v28 = *(_QWORD *)(v24 + *v23 + 8) == 1i64;
                  --*(_QWORD *)(v24 + v26 + 8);
                  if ( v28 )
                  {
                    v29 = Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor>::FindLeEq(
                            &v27->UsedSeg,
                            *(_QWORD *)(v24 + v26));
                    Scaleform::HeapPT::AllocLite::Free(
                      &v27->Allocator,
                      v29,
                      *(void **)(v24 + v26),
                      0x800ui64,
                      0x800ui64);
                    v28 = v29->UseCount-- == 1;
                    if ( v28 )
                      Scaleform::HeapPT::Granulator::freeSegment(v27, v29);
                    v4 = v47;
                    *(_QWORD *)(v24 + v26) = 0i64;
                  }
                  v24 += 16i64;
                  --v25;
                }
                while ( v25 );
                v15 = v40;
                v19 = v42;
              }
              v30 = &v4->pStarter->Allocator;
              v28 = v23[1]-- == 1;
              if ( v28 )
              {
                v31 = Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor>::FindLeEq(
                        &v30->UsedSeg,
                        *v23);
                Scaleform::HeapPT::AllocLite::Free(&v30->Allocator, v31, (void *)*v23, 0x1000ui64, 0x800ui64);
                v28 = v31->UseCount-- == 1;
                if ( v28 )
                  Scaleform::HeapPT::Granulator::freeSegment(v30, v31);
                v4 = v47;
                *v23 = 0i64;
              }
              v17 = v41;
              v18 = v43;
              v3 = (unsigned __int64)v48;
              v5 = v37;
              v19 += 16i64;
              ++v16;
              v42 = v19;
            }
            while ( v16 <= v15 );
            v10 = v49;
            v11 = v38;
            v13 = v50;
          }
          v32 = &v4->pStarter->Allocator;
          v28 = v17[1]-- == 1;
          if ( v28 )
          {
            v33 = Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor>::FindLeEq(
                    &v32->UsedSeg,
                    *v17);
            Scaleform::HeapPT::AllocLite::Free(&v32->Allocator, v33, (void *)*v17, 0x10000ui64, 0x8000ui64);
            v28 = v33->UseCount-- == 1;
            if ( v28 )
              Scaleform::HeapPT::Granulator::freeSegment(v32, v33);
            v4 = v47;
            v13 = v50;
            *v17 = 0i64;
          }
          v3 = (unsigned __int64)v48;
          v5 = v37;
          v9 = (unsigned __int64 *)v36;
          v12 = v45;
          ++v10;
          v13 += 16i64;
          v49 = v10;
          v50 = v13;
        }
        while ( v10 <= v11 );
        v8 = v39;
        v7 = v44;
      }
      v34 = &v4->pStarter->Allocator;
      v28 = v9[1]-- == 1;
      if ( v28 )
      {
        v35 = Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor>::FindLeEq(
                &v34->UsedSeg,
                *v9);
        Scaleform::HeapPT::AllocLite::Free(&v34->Allocator, v35, (void *)*v9, 0x10000ui64, 0x8000ui64);
        v28 = v35->UseCount-- == 1;
        if ( v28 )
          Scaleform::HeapPT::Granulator::freeSegment(v34, v35);
        v4 = v47;
        *v9 = 0i64;
      }
      v3 = (unsigned __int64)v48;
      v5 = v37;
      v6 = v46;
      ++v8;
      v9 += 2;
      v39 = v8;
      v36 = (signed __int64)v9;
    }
    while ( v8 <= v7 );
  }
}

// File Line: 255
// RVA: 0x9A8480
char __fastcall Scaleform::HeapPT::PageTable::RemapRange(Scaleform::HeapPT::PageTable *this, void *mem, unsigned __int64 newSize, unsigned __int64 oldSize)
{
  unsigned __int64 v4; // rbx
  unsigned __int64 v5; // rbp
  void *v6; // rdi
  Scaleform::HeapPT::PageTable *v7; // rsi
  char v9; // r14
  Scaleform::Heap::HeapSegment *v10; // r15

  v4 = oldSize;
  v5 = newSize;
  v6 = mem;
  v7 = this;
  if ( newSize == oldSize )
    return 1;
  v9 = 0;
  v10 = this->RootTable[(unsigned __int64)mem >> 52].pTable[((unsigned __int64)mem >> 40) & 0xFFF].pTable[((unsigned __int64)mem >> 28) & 0xFFF].pTable[(unsigned __int8)((unsigned __int64)mem >> 20)].pTable[(unsigned __int8)((unsigned __int64)mem >> 12)].pSegment;
  Scaleform::HeapPT::PageTable::UnmapRange(this, mem, oldSize);
  if ( Scaleform::HeapPT::PageTable::MapRange(v7, v6, v5) )
  {
    v4 = v5;
    v9 = 1;
  }
  else
  {
    Scaleform::HeapPT::PageTable::MapRange(v7, v6, v4);
  }
  Scaleform::HeapPT::PageTable::SetSegmentInRange(v7, (unsigned __int64)v6, v4, v10);
  return v9;
}

// File Line: 321
// RVA: 0x9B3830
void __fastcall Scaleform::HeapPT::PageTable::SetSegmentInRange(Scaleform::HeapPT::PageTable *this, unsigned __int64 address, unsigned __int64 size, Scaleform::Heap::HeapSegment *seg)
{
  unsigned __int64 v4; // r10
  Scaleform::Heap::HeapSegment *v5; // rdi
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // r9
  unsigned __int64 v8; // r8
  unsigned __int64 v9; // rbp
  Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256>,256>,4096>,4096> *v10; // rbx
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // r13
  unsigned __int64 v13; // rsi
  signed __int64 v14; // r11
  unsigned __int64 v15; // r12
  unsigned __int64 v16; // r15
  _QWORD *v17; // rax
  unsigned __int64 v18; // r11
  signed __int64 v19; // rdx
  unsigned __int64 v20; // r14
  unsigned __int64 v21; // rbx
  unsigned __int64 v22; // r8
  signed __int64 v23; // r10
  unsigned __int64 v24; // rdx
  __int64 v25; // r9
  unsigned __int64 v26; // rax
  unsigned __int64 v27; // [rsp+0h] [rbp-78h]
  unsigned __int64 v28; // [rsp+8h] [rbp-70h]
  unsigned __int64 v29; // [rsp+10h] [rbp-68h]
  signed __int64 v30; // [rsp+18h] [rbp-60h]
  signed __int64 v31; // [rsp+20h] [rbp-58h]
  Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256>,256>,4096>,4096> *v32; // [rsp+28h] [rbp-50h]
  __int64 *v33; // [rsp+30h] [rbp-48h]
  _QWORD *v34; // [rsp+38h] [rbp-40h]
  unsigned __int64 v35; // [rsp+88h] [rbp+10h]
  signed __int64 v36; // [rsp+90h] [rbp+18h]

  v35 = address;
  v4 = address;
  v5 = seg;
  v6 = address + size - 1;
  v7 = v4 >> 52;
  v28 = v6;
  v8 = v6 >> 52;
  v29 = v4 >> 52;
  v9 = v4 >> 52;
  v27 = v6 >> 52;
  if ( v4 >> 52 <= v6 >> 52 )
  {
    v10 = &this->RootTable[v7];
    v32 = &this->RootTable[v7];
    do
    {
      v11 = 0i64;
      v12 = 4095i64;
      v36 = 0i64;
      if ( v9 == v7 )
      {
        v11 = (v4 >> 40) & 0xFFF;
        v36 = (v4 >> 40) & 0xFFF;
      }
      if ( v9 == v8 )
        v12 = (v6 >> 40) & 0xFFF;
      v13 = v11;
      if ( v11 <= v12 )
      {
        v14 = 16 * v11;
        v31 = 16 * v11;
        do
        {
          v15 = 0i64;
          v16 = 4095i64;
          v17 = (Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256>,256> **)((char *)&v10->pTable->pTable + v14);
          v34 = (Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader<Scaleform::HeapPT::HeapHeader1,256>,256> **)((char *)&v10->pTable->pTable + v14);
          if ( v13 == v11 && v9 == v7 )
            v15 = (v4 >> 28) & 0xFFF;
          if ( v13 == v12 && v9 == v8 )
            v16 = (v6 >> 28) & 0xFFF;
          v18 = v15;
          if ( v15 <= v16 )
          {
            v19 = 16 * v15;
            v30 = 16 * v15;
            do
            {
              v20 = 0i64;
              v21 = 255i64;
              v33 = (__int64 *)(v19 + *v17);
              if ( v18 == v15 && v13 == v11 && v9 == v7 )
                v20 = (unsigned __int8)(v4 >> 20);
              if ( v18 == v16 && v13 == v12 && v9 == v8 )
                v21 = (unsigned __int8)(v28 >> 20);
              v22 = v20;
              if ( v20 <= v21 )
              {
                v23 = 16 * v20;
                do
                {
                  v24 = 255i64;
                  v25 = *v33;
                  v26 = 0i64;
                  if ( v22 == v20 && v18 == v15 && v13 == v11 && v9 == v29 )
                    v26 = (unsigned __int8)(v35 >> 12);
                  if ( v22 == v21 && v18 == v16 && v13 == v12 && v9 == v27 )
                    v24 = (unsigned __int8)(v28 >> 12);
                  for ( ; v26 <= v24; *(_QWORD *)(*(_QWORD *)(v25 + v23) + 8 * v26 - 8) = v5 )
                    ++v26;
                  v11 = v36;
                  ++v22;
                  v23 += 16i64;
                }
                while ( v22 <= v21 );
                v19 = v30;
                v7 = v29;
                v4 = v35;
              }
              v8 = v27;
              v17 = v34;
              v19 += 16i64;
              ++v18;
              v30 = v19;
            }
            while ( v18 <= v16 );
            v6 = v28;
            v10 = v32;
          }
          ++v13;
          v14 = v31 + 16;
          v31 += 16i64;
        }
        while ( v13 <= v12 );
      }
      ++v10;
      ++v9;
      v32 = v10;
    }
    while ( v9 <= v8 );
  }
}

