// File Line: 67
// RVA: 0x257B30
void __fastcall antlr3BitsetFree(ANTLR3_BITSET_struct *bitset)
{
  ANTLR3_BITSET_struct *v1; // rbx
  unsigned __int64 *v2; // rcx

  v1 = bitset;
  v2 = bitset->blist.bits;
  if ( v2 )
  {
    antlrFree(v2);
    v1->blist.bits = 0i64;
  }
  antlrFree(v1);
}

// File Line: 80
// RVA: 0x258100
ANTLR3_BITSET_struct *__fastcall antlr3BitsetNew(unsigned int numBits)
{
  unsigned int v1; // edi
  ANTLR3_BITSET_struct *v2; // rsi
  unsigned int v3; // edi
  UFG::allocator::free_link *v4; // rax
  bool v5; // zf

  v1 = numBits;
  v2 = (ANTLR3_BITSET_struct *)antlrMalloc(0x78ui64);
  if ( !v2 )
    return 0i64;
  if ( v1 < 0x200 )
    v1 = 512;
  v3 = ((v1 - 1) >> 6) + 1;
  v4 = antlrMalloc(8i64 * v3);
  v2->blist.bits = (unsigned __int64 *)v4;
  memset(v4, 0, 8i64 * v3);
  v5 = v2->blist.bits == 0i64;
  v2->blist.length = v3;
  if ( v5 )
  {
    antlrFree(v2);
    return 0i64;
  }
  antlr3BitsetSetAPI(v2);
  return v2;
}

// File Line: 126
// RVA: 0x258290
void __fastcall antlr3BitsetSetAPI(ANTLR3_BITSET_struct *bitset)
{
  bitset->clone = antlr3BitsetClone;
  bitset->bor = antlr3BitsetOR;
  bitset->borInPlace = antlr3BitsetORInPlace;
  bitset->size = (unsigned int (__fastcall *)(ANTLR3_BITSET_struct *))antlr3BitsetSize;
  bitset->add = antlr3BitsetAdd;
  bitset->grow = grow;
  bitset->equals = antlr3BitsetEquals;
  bitset->isMember = (char (__fastcall *)(ANTLR3_BITSET_struct *, unsigned int))antlr3BitsetMember;
  bitset->numBits = (unsigned int (__fastcall *)(ANTLR3_BITSET_struct *))antlr3BitsetNumBits;
  bitset->remove = antlr3BitsetRemove;
  bitset->isNilNode = antlr3BitsetIsNil;
  bitset->toIntList = (int *(__fastcall *)(ANTLR3_BITSET_struct *))antlr3BitsetToIntList;
  bitset->free = antlr3BitsetFree;
}

// File Line: 145
// RVA: 0x257EC0
UFG::allocator::free_link *__fastcall antlr3BitsetCopy(ANTLR3_BITSET_LIST_struct *blist)
{
  ANTLR3_BITSET_LIST_struct *v1; // rsi
  UFG::allocator::free_link *result; // rax
  ANTLR3_BITSET_struct *v3; // rbx
  signed int v4; // edi
  UFG::allocator::free_link *v5; // rax

  v1 = blist;
  result = antlrMalloc(0x78ui64);
  v3 = (ANTLR3_BITSET_struct *)result;
  if ( result )
  {
    v4 = v1->length;
    if ( v4 < 8 )
      v4 = 8;
    LODWORD(result[1].mNext) = v4;
    v5 = antlrMalloc(8i64 * v4);
    v3->blist.bits = (unsigned __int64 *)v5;
    if ( v5 )
    {
      UFG::qMemCopy(v5, v1->bits, 8 * v4);
      result = (UFG::allocator::free_link *)v3;
    }
    else
    {
      antlrFree(v3);
      result = 0i64;
    }
  }
  return result;
}

// File Line: 188
// RVA: 0x257A00
ANTLR3_BITSET_struct *__fastcall antlr3BitsetClone(ANTLR3_BITSET_struct *inSet)
{
  ANTLR3_BITSET_struct *v1; // rbx
  ANTLR3_BITSET_struct *result; // rax
  ANTLR3_BITSET_struct *v3; // rdi

  v1 = inSet;
  result = antlr3BitsetNew(inSet->blist.length << 6);
  v3 = result;
  if ( result )
  {
    UFG::qMemCopy(result->blist.bits, v1->blist.bits, 8 * v1->blist.length);
    result = v3;
  }
  return result;
}

// File Line: 212
// RVA: 0x257F60
ANTLR3_BITSET_struct *__fastcall antlr3BitsetList(ANTLR3_HASH_TABLE_struct *list)
{
  ANTLR3_HASH_TABLE_struct *v1; // rdi
  UFG::allocator::free_link *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  bool v4; // zf
  ANTLR3_HASH_ENUM_struct *v5; // rdi
  void *v7; // [rsp+38h] [rbp+10h]
  char v8; // [rsp+40h] [rbp+18h]

  v1 = list;
  v2 = antlrMalloc(0x78ui64);
  if ( v2 )
  {
    v3 = antlrMalloc(0x40ui64);
    v2->mNext = v3;
    v3->mNext = 0i64;
    v3[1].mNext = 0i64;
    v3[2].mNext = 0i64;
    v3[3].mNext = 0i64;
    v3[4].mNext = 0i64;
    v3[5].mNext = 0i64;
    v3[6].mNext = 0i64;
    v3[7].mNext = 0i64;
    v4 = v2->mNext == 0i64;
    LODWORD(v2[1].mNext) = 8;
    if ( v4 )
    {
      antlrFree(v2);
      v2 = 0i64;
    }
    else
    {
      antlr3BitsetSetAPI((ANTLR3_BITSET_struct *)v2);
    }
  }
  v5 = antlr3EnumNew(v1);
  while ( !v5->next(v5, (ANTLR3_HASH_KEY_struct **)&v8, &v7) )
    ((void (__fastcall *)(UFG::allocator::free_link *, _QWORD))v2[6].mNext)(v2, (unsigned int)v7);
  v5->free(v5);
  return 0i64;
}

// File Line: 258
// RVA: 0x258030
UFG::allocator::free_link *__fastcall antlr3BitsetLoad(ANTLR3_BITSET_LIST_struct *inBits)
{
  ANTLR3_BITSET_LIST_struct *v1; // rsi
  UFG::allocator::free_link *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  bool v4; // zf
  signed __int64 v6; // rdi
  signed __int64 v7; // rdx
  UFG::allocator::free_link *v8; // rax

  v1 = inBits;
  v2 = antlrMalloc(0x78ui64);
  if ( !v2 )
    return 0i64;
  v3 = antlrMalloc(0x40ui64);
  v2->mNext = v3;
  v3->mNext = 0i64;
  v3[1].mNext = 0i64;
  v3[2].mNext = 0i64;
  v3[3].mNext = 0i64;
  v3[4].mNext = 0i64;
  v3[5].mNext = 0i64;
  v3[6].mNext = 0i64;
  v3[7].mNext = 0i64;
  v4 = v2->mNext == 0i64;
  LODWORD(v2[1].mNext) = 8;
  if ( v4 )
  {
    antlrFree(v2);
    return 0i64;
  }
  antlr3BitsetSetAPI((ANTLR3_BITSET_struct *)v2);
  if ( v1 )
  {
    v6 = 0i64;
    if ( v1->length )
    {
      do
      {
        if ( LODWORD(v2[1].mNext) <= (unsigned int)v6 )
          ((void (__fastcall *)(UFG::allocator::free_link *, _QWORD))v2[7].mNext)(v2, (unsigned int)(v6 + 1));
        v7 = v6;
        v8 = (UFG::allocator::free_link *)v1->bits[v6];
        v6 = (unsigned int)(v6 + 1);
        v2->mNext[v7].mNext = v8;
      }
      while ( (unsigned int)v6 < v1->length );
    }
  }
  return v2;
}

// File Line: 321
// RVA: 0x258190
UFG::allocator::free_link *antlr3BitsetOf(int bit, ...)
{
  UFG::allocator::free_link *v1; // rbx
  UFG::allocator::free_link *v2; // rax
  bool v3; // zf
  unsigned int v5; // esi
  unsigned int *v6; // r14
  unsigned int v7; // edx
  __int64 v8; // rdi
  __int64 v9; // rdx
  unsigned int v10; // [rsp+50h] [rbp+8h]

  v10 = bit;
  v1 = antlrMalloc(0x78ui64);
  if ( !v1 )
    return 0i64;
  v2 = antlrMalloc(0x40ui64);
  v1->mNext = v2;
  v2->mNext = 0i64;
  v2[1].mNext = 0i64;
  v2[2].mNext = 0i64;
  v2[3].mNext = 0i64;
  v2[4].mNext = 0i64;
  v2[5].mNext = 0i64;
  v2[6].mNext = 0i64;
  v2[7].mNext = 0i64;
  v3 = v1->mNext == 0i64;
  LODWORD(v1[1].mNext) = 8;
  if ( v3 )
  {
    antlrFree(v1);
    return 0i64;
  }
  antlr3BitsetSetAPI((ANTLR3_BITSET_struct *)v1);
  v5 = v10;
  if ( v10 != -1 )
  {
    v6 = &v10;
    do
    {
      v7 = (unsigned int)v1[1].mNext;
      v8 = v5 >> 6;
      if ( (unsigned int)v8 >= v7 )
      {
        v9 = 2 * v7;
        if ( (unsigned int)v9 <= (signed int)v8 + 1 )
          v9 = (unsigned int)(v8 + 1);
        ((void (__fastcall *)(UFG::allocator::free_link *, __int64))v1[7].mNext)(v1, v9);
      }
      v6 += 2;
      v1->mNext[v8].mNext = (UFG::allocator::free_link *)((_QWORD)v1->mNext[v8].mNext | (1i64 << (v5 & 0x3F)));
      v5 = *v6;
      v10 = v5;
    }
    while ( v5 != -1 );
  }
  return v1;
}

// File Line: 358
// RVA: 0x257BD0
ANTLR3_BITSET_struct *__fastcall antlr3BitsetOR(ANTLR3_BITSET_struct *bitset1, ANTLR3_BITSET_struct *bitset2)
{
  ANTLR3_BITSET_struct *v2; // rsi
  ANTLR3_BITSET_struct *v3; // rdi
  ANTLR3_BITSET_struct *v4; // rax
  ANTLR3_BITSET_struct *v5; // rbx
  ANTLR3_BITSET_struct *result; // rax
  unsigned int v7; // ecx
  ANTLR3_BITSET_struct *v8; // rax
  ANTLR3_BITSET_struct *v9; // rbx
  ANTLR3_BITSET_struct *v10; // rax
  ANTLR3_BITSET_struct *v11; // rbx

  v2 = bitset2;
  v3 = bitset1;
  if ( bitset1 )
  {
    v7 = bitset1->blist.length << 6;
    if ( bitset2 )
    {
      v10 = antlr3BitsetNew(v7);
      v11 = v10;
      if ( v10 )
        UFG::qMemCopy(v10->blist.bits, v3->blist.bits, 8 * v3->blist.length);
      antlr3BitsetORInPlace(v11, v2);
      result = v11;
    }
    else
    {
      v8 = antlr3BitsetNew(v7);
      v9 = v8;
      if ( !v8 )
        return 0i64;
      UFG::qMemCopy(v8->blist.bits, v3->blist.bits, 8 * v3->blist.length);
      result = v9;
    }
  }
  else
  {
    v4 = antlr3BitsetNew(bitset2->blist.length << 6);
    v5 = v4;
    if ( !v4 )
      return 0i64;
    UFG::qMemCopy(v4->blist.bits, v2->blist.bits, 8 * v2->blist.length);
    result = v5;
  }
  return result;
}

// File Line: 383
// RVA: 0x2579A0
void __fastcall antlr3BitsetAdd(ANTLR3_BITSET_struct *bitset, int bit)
{
  unsigned int v2; // edi
  char v3; // si
  unsigned int v4; // edx
  __int64 v5; // rdi
  ANTLR3_BITSET_struct *v6; // rbx
  __int64 v7; // rdx

  v2 = bit;
  v3 = bit;
  v4 = bitset->blist.length;
  v5 = v2 >> 6;
  v6 = bitset;
  if ( (unsigned int)v5 >= v4 )
  {
    v7 = 2 * v4;
    if ( (unsigned int)v7 <= (signed int)v5 + 1 )
      v7 = (unsigned int)(v5 + 1);
    bitset->grow(bitset, v7);
  }
  v6->blist.bits[v5] |= 1i64 << (v3 & 0x3F);
}

// File Line: 399
// RVA: 0x257E40
void __fastcall grow(ANTLR3_BITSET_struct *bitset, int newSize)
{
  int v2; // edi
  ANTLR3_BITSET_struct *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  unsigned __int64 *v5; // rsi

  v2 = newSize;
  v3 = bitset;
  v4 = antlrCalloc(1u, 8 * newSize);
  v5 = (unsigned __int64 *)v4;
  if ( v3->blist.bits )
  {
    UFG::qMemCopy(v4, v3->blist.bits, 8 * v3->blist.length);
    antlrFree(v3->blist.bits);
    v3->blist.bits = v5;
  }
  else
  {
    v3->blist.bits = (unsigned __int64 *)v4;
  }
  v3->blist.length = v2;
}

// File Line: 444
// RVA: 0x257CC0
void __fastcall antlr3BitsetORInPlace(ANTLR3_BITSET_struct *bitset, ANTLR3_BITSET_struct *bitset2)
{
  unsigned int v2; // eax
  ANTLR3_BITSET_struct *v3; // rdi
  unsigned int v4; // edx
  ANTLR3_BITSET_struct *v5; // rbx
  unsigned int v6; // eax
  __int64 v7; // rdx
  __int64 v8; // r8

  if ( bitset2 )
  {
    v2 = bitset->blist.length;
    v3 = bitset2;
    v4 = bitset2->blist.length;
    v5 = bitset;
    if ( v2 < v4 )
    {
      v6 = 2 * v2;
      v7 = (8 * v4 >> 6) + 1;
      if ( v6 > (unsigned int)v7 )
        v7 = v6;
      bitset->grow(bitset, v7);
    }
    LODWORD(v8) = v3->blist.length;
    if ( v5->blist.length < (unsigned int)v8 )
      LODWORD(v8) = v5->blist.length;
    for ( ; (_DWORD)v8; v5->blist.bits[v8] |= v3->blist.bits[v8] )
      v8 = (unsigned int)(v8 - 1);
  }
}

// File Line: 487
// RVA: 0x257D70
__int64 __fastcall antlr3BitsetSize(ANTLR3_BITSET_struct *bitset)
{
  unsigned int v1; // edx
  signed int v2; // eax
  __int64 v3; // r9
  unsigned __int64 *v4; // r10
  unsigned __int64 v5; // r8
  unsigned __int8 v6; // cl

  v1 = 0;
  v2 = bitset->blist.length - 1;
  v3 = v2;
  if ( v2 >= 0 )
  {
    v4 = &bitset->blist.bits[v2];
    do
    {
      if ( *v4 )
      {
        v6 = 63;
        do
        {
          v5 = *v4;
          if ( _bittest64((const signed __int64 *)&v5, v6) )
            ++v1;
          --v6;
        }
        while ( (v6 & 0x80u) == 0 );
      }
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  return v1;
}

// File Line: 516
// RVA: 0x257A50
char __fastcall antlr3BitsetEquals(ANTLR3_BITSET_struct *bitset1, ANTLR3_BITSET_struct *bitset2)
{
  ANTLR3_BITSET_struct *v2; // rbx
  ANTLR3_BITSET_struct *v3; // rdi
  unsigned int v4; // er10
  unsigned int v5; // er9
  unsigned int v6; // eax
  __int64 v7; // r8
  unsigned __int64 *v8; // rcx
  unsigned __int64 *v9; // rdx
  unsigned __int64 *v10; // rdx
  unsigned __int64 *v12; // rdx

  v2 = bitset2;
  v3 = bitset1;
  if ( bitset1 && bitset2 )
  {
    v4 = bitset1->blist.length;
    v5 = bitset2->blist.length;
    v6 = bitset2->blist.length;
    if ( v4 < v5 )
      v6 = bitset1->blist.length;
    v7 = (signed int)(v6 - 1);
    if ( (signed int)(v6 - 1) >= 0 )
    {
      v8 = bitset2->blist.bits;
      v9 = &bitset2->blist.bits[v7];
      while ( *(unsigned __int64 *)((char *)v9 + (char *)v3->blist.bits - (char *)v8) == *v9 )
      {
        --v9;
        if ( --v7 < 0 )
          goto LABEL_9;
      }
      return 0;
    }
LABEL_9:
    if ( v4 <= v6 )
    {
      if ( v5 > v6 && v6 < v5 )
      {
        v12 = &v2->blist.bits[v6];
        while ( !*v12 )
        {
          ++v6;
          ++v12;
          if ( v6 >= v5 )
            return 1;
        }
        return 0;
      }
    }
    else if ( v6 < v4 )
    {
      v10 = &v3->blist.bits[v6];
      while ( !*v10 )
      {
        ++v6;
        ++v10;
        if ( v6 >= v4 )
          return 1;
      }
      return 0;
    }
    return 1;
  }
  return 0;
}

// File Line: 575
// RVA: 0x257B90
unsigned __int8 __fastcall antlr3BitsetMember(ANTLR3_BITSET_struct *bitset, unsigned int bit)
{
  unsigned __int64 v3; // rcx

  if ( bit >> 6 >= bitset->blist.length )
    return 0;
  v3 = bitset->blist.bits[bit >> 6];
  return _bittest64((const signed __int64 *)&v3, bit & 0x3F);
}

// File Line: 597
// RVA: 0x257D40
void __fastcall antlr3BitsetRemove(ANTLR3_BITSET_struct *bitset, unsigned int bit)
{
  if ( bit >> 6 < bitset->blist.length )
    bitset->blist.bits[bit >> 6] &= ~(1i64 << (bit & 0x3F));
}

// File Line: 609
// RVA: 0x257B60
char __fastcall antlr3BitsetIsNil(ANTLR3_BITSET_struct *bitset)
{
  __int64 v1; // rax
  unsigned __int64 *v2; // rdx

  v1 = bitset->blist.length - 1;
  if ( (signed int)v1 < 0 )
    return 1;
  v2 = &bitset->blist.bits[(signed int)v1];
  while ( !*v2 )
  {
    --v2;
    if ( --v1 < 0 )
      return 1;
  }
  return 0;
}

// File Line: 637
// RVA: 0x257BC0
__int64 __fastcall antlr3BitsetNumBits(ANTLR3_BITSET_struct *bitset)
{
  return bitset->blist.length << 6;
}

// File Line: 650
// RVA: 0x257DB0
UFG::allocator::free_link *__fastcall antlr3BitsetToIntList(ANTLR3_BITSET_struct *bitset)
{
  ANTLR3_BITSET_struct *v1; // rsi
  unsigned int v2; // ebx
  unsigned int v3; // ebp
  UFG::allocator::free_link *result; // rax
  int *v5; // r14
  unsigned int v6; // ebx
  unsigned int v7; // edi
  __int64 v8; // rax

  v1 = bitset;
  v2 = (unsigned __int64)((__int64 (*)(void))bitset->size)() + 1;
  v3 = v1->numBits(v1);
  result = antlrMalloc(4i64 * v2);
  v5 = (int *)result;
  if ( result )
  {
    LODWORD(result->mNext) = v2;
    v6 = 0;
    v7 = 1;
    if ( v3 )
    {
      do
      {
        if ( v1->isMember(v1, v6) == 1 )
        {
          v8 = v7++;
          v5[v8] = v6;
        }
        ++v6;
      }
      while ( v6 < v3 );
    }
    result = (UFG::allocator::free_link *)v5;
  }
  return result;
}

