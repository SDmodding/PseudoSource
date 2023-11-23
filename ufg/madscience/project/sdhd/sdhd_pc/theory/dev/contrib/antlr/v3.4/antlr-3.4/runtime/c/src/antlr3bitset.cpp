// File Line: 67
// RVA: 0x257B30
void __fastcall antlr3BitsetFree(ANTLR3_BITSET_struct *bitset)
{
  unsigned __int64 *bits; // rcx

  bits = bitset->blist.bits;
  if ( bits )
  {
    antlrFree((char *)bits);
    bitset->blist.bits = 0i64;
  }
  antlrFree((char *)bitset);
}

// File Line: 80
// RVA: 0x258100
UFG::allocator::free_link *__fastcall antlr3BitsetNew(unsigned int numBits)
{
  UFG::allocator::free_link *v2; // rsi
  unsigned int v3; // edi
  UFG::allocator::free_link *v4; // rax
  bool v5; // zf

  v2 = antlrMalloc(0x78ui64);
  if ( !v2 )
    return 0i64;
  if ( numBits < 0x200 )
    numBits = 512;
  v3 = ((numBits - 1) >> 6) + 1;
  v4 = antlrMalloc(8i64 * v3);
  v2->mNext = v4;
  memset(v4, 0, 8i64 * v3);
  v5 = v2->mNext == 0i64;
  LODWORD(v2[1].mNext) = v3;
  if ( v5 )
  {
    antlrFree((char *)v2);
    return 0i64;
  }
  antlr3BitsetSetAPI((ANTLR3_BITSET_struct *)v2);
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
  bitset->add = (void (__fastcall *)(ANTLR3_BITSET_struct *, int))antlr3BitsetAdd;
  bitset->grow = (void (__fastcall *)(ANTLR3_BITSET_struct *, int))grow;
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
  UFG::allocator::free_link *result; // rax
  char *v3; // rbx
  int length; // edi
  UFG::allocator::free_link *v5; // rax

  result = antlrMalloc(0x78ui64);
  v3 = (char *)result;
  if ( result )
  {
    length = blist->length;
    if ( length < 8 )
      length = 8;
    LODWORD(result[1].mNext) = length;
    v5 = antlrMalloc(8i64 * length);
    *(_QWORD *)v3 = v5;
    if ( v5 )
    {
      UFG::qMemCopy(v5, blist->bits, 8 * length);
      return (UFG::allocator::free_link *)v3;
    }
    else
    {
      antlrFree(v3);
      return 0i64;
    }
  }
  return result;
}

// File Line: 188
// RVA: 0x257A00
ANTLR3_BITSET_struct *__fastcall antlr3BitsetClone(ANTLR3_BITSET_struct *inSet)
{
  ANTLR3_BITSET_struct *result; // rax
  ANTLR3_BITSET_struct *v3; // rdi

  result = antlr3BitsetNew(inSet->blist.length << 6);
  v3 = result;
  if ( result )
  {
    UFG::qMemCopy(result->blist.bits, inSet->blist.bits, 8 * inSet->blist.length);
    return v3;
  }
  return result;
}

// File Line: 212
// RVA: 0x257F60
ANTLR3_BITSET_struct *__fastcall antlr3BitsetList(ANTLR3_HASH_TABLE_struct *list)
{
  UFG::allocator::free_link *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  bool v4; // zf
  ANTLR3_HASH_ENUM_struct *v5; // rdi
  unsigned int v7; // [rsp+38h] [rbp+10h] BYREF
  char v8; // [rsp+40h] [rbp+18h] BYREF

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
      antlrFree((char *)v2);
      v2 = 0i64;
    }
    else
    {
      antlr3BitsetSetAPI((ANTLR3_BITSET_struct *)v2);
    }
  }
  v5 = antlr3EnumNew(list);
  while ( !v5->next(v5, (ANTLR3_HASH_KEY_struct **)&v8, (void **)&v7) )
    ((void (__fastcall *)(UFG::allocator::free_link *, _QWORD))v2[6].mNext)(v2, v7);
  v5->free(v5);
  return 0i64;
}

// File Line: 258
// RVA: 0x258030
UFG::allocator::free_link *__fastcall antlr3BitsetLoad(ANTLR3_BITSET_LIST_struct *inBits)
{
  UFG::allocator::free_link *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  bool v4; // zf
  __int64 i; // rdi
  __int64 v7; // rdx
  unsigned __int64 v8; // rax

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
    antlrFree((char *)v2);
    return 0i64;
  }
  antlr3BitsetSetAPI((ANTLR3_BITSET_struct *)v2);
  if ( inBits )
  {
    for ( i = 0i64; (unsigned int)i < inBits->length; v2->mNext[v7].mNext = (UFG::allocator::free_link *)v8 )
    {
      if ( LODWORD(v2[1].mNext) <= (unsigned int)i )
        ((void (__fastcall *)(UFG::allocator::free_link *, _QWORD))v2[7].mNext)(v2, (unsigned int)(i + 1));
      v7 = i;
      v8 = inBits->bits[i];
      i = (unsigned int)(i + 1);
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
  unsigned int mNext; // edx
  __int64 v8; // rdi
  __int64 v9; // rdx
  int v10; // [rsp+50h] [rbp+8h] BYREF

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
    antlrFree((char *)v1);
    return 0i64;
  }
  antlr3BitsetSetAPI((ANTLR3_BITSET_struct *)v1);
  v5 = v10;
  if ( v10 != -1 )
  {
    v6 = (unsigned int *)&v10;
    do
    {
      mNext = (unsigned int)v1[1].mNext;
      v8 = v5 >> 6;
      if ( (unsigned int)v8 >= mNext )
      {
        v9 = 2 * mNext;
        if ( (unsigned int)v9 <= (int)v8 + 1 )
          v9 = (unsigned int)(v8 + 1);
        ((void (__fastcall *)(UFG::allocator::free_link *, __int64))v1[7].mNext)(v1, v9);
      }
      v6 += 2;
      v1->mNext[v8].mNext = (UFG::allocator::free_link *)((__int64)v1->mNext[v8].mNext | (1i64 << (v5 & 0x3F)));
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
  ANTLR3_BITSET_struct *v4; // rax
  ANTLR3_BITSET_struct *v5; // rbx
  unsigned int v7; // ecx
  ANTLR3_BITSET_struct *v8; // rax
  ANTLR3_BITSET_struct *v9; // rbx
  ANTLR3_BITSET_struct *v10; // rax
  ANTLR3_BITSET_struct *v11; // rbx

  if ( bitset1 )
  {
    v7 = bitset1->blist.length << 6;
    if ( bitset2 )
    {
      v10 = antlr3BitsetNew(v7);
      v11 = v10;
      if ( v10 )
        UFG::qMemCopy(v10->blist.bits, bitset1->blist.bits, 8 * bitset1->blist.length);
      antlr3BitsetORInPlace(v11, bitset2);
      return v11;
    }
    else
    {
      v8 = antlr3BitsetNew(v7);
      v9 = v8;
      if ( !v8 )
        return 0i64;
      UFG::qMemCopy(v8->blist.bits, bitset1->blist.bits, 8 * bitset1->blist.length);
      return v9;
    }
  }
  else
  {
    v4 = antlr3BitsetNew(bitset2->blist.length << 6);
    v5 = v4;
    if ( !v4 )
      return 0i64;
    UFG::qMemCopy(v4->blist.bits, bitset2->blist.bits, 8 * bitset2->blist.length);
    return v5;
  }
}

// File Line: 383
// RVA: 0x2579A0
void __fastcall antlr3BitsetAdd(ANTLR3_BITSET_struct *bitset, unsigned int bit)
{
  char v3; // si
  unsigned int length; // edx
  __int64 v5; // rdi
  __int64 v7; // rdx

  v3 = bit;
  length = bitset->blist.length;
  v5 = bit >> 6;
  if ( (unsigned int)v5 >= length )
  {
    v7 = 2 * length;
    if ( (unsigned int)v7 <= (int)v5 + 1 )
      v7 = (unsigned int)(v5 + 1);
    bitset->grow(bitset, v7);
  }
  bitset->blist.bits[v5] |= 1i64 << (v3 & 0x3F);
}

// File Line: 399
// RVA: 0x257E40
void __fastcall grow(ANTLR3_BITSET_struct *bitset, unsigned int newSize)
{
  UFG::allocator::free_link *v4; // rax
  unsigned __int64 *v5; // rsi

  v4 = antlrCalloc(1u, 8 * newSize);
  v5 = (unsigned __int64 *)v4;
  if ( bitset->blist.bits )
  {
    UFG::qMemCopy(v4, bitset->blist.bits, 8 * bitset->blist.length);
    antlrFree((char *)bitset->blist.bits);
    bitset->blist.bits = v5;
  }
  else
  {
    bitset->blist.bits = (unsigned __int64 *)v4;
  }
  bitset->blist.length = newSize;
}

// File Line: 444
// RVA: 0x257CC0
void __fastcall antlr3BitsetORInPlace(ANTLR3_BITSET_struct *bitset, ANTLR3_BITSET_struct *bitset2)
{
  unsigned int length; // eax
  unsigned int v4; // edx
  unsigned int v6; // eax
  __int64 v7; // rdx
  __int64 v8; // r8

  if ( bitset2 )
  {
    length = bitset->blist.length;
    v4 = bitset2->blist.length;
    if ( length < v4 )
    {
      v6 = 2 * length;
      v7 = ((8 * v4) >> 6) + 1;
      if ( v6 > (unsigned int)v7 )
        v7 = v6;
      bitset->grow(bitset, v7);
    }
    LODWORD(v8) = bitset2->blist.length;
    if ( bitset->blist.length < (unsigned int)v8 )
      LODWORD(v8) = bitset->blist.length;
    for ( ; (_DWORD)v8; bitset->blist.bits[v8] |= bitset2->blist.bits[v8] )
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
  char i; // cl

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
        for ( i = 63; i >= 0; --i )
        {
          v5 = *v4;
          if ( _bittest64((const __int64 *)&v5, (unsigned __int8)i) )
            ++v1;
        }
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
  unsigned int length; // r10d
  unsigned int v5; // r9d
  unsigned int v6; // eax
  __int64 v7; // r8
  unsigned __int64 *bits; // rcx
  unsigned __int64 *v9; // rdx
  unsigned __int64 *j; // rdx
  unsigned __int64 *i; // rdx

  if ( bitset1 && bitset2 )
  {
    length = bitset1->blist.length;
    v5 = bitset2->blist.length;
    v6 = v5;
    if ( length < v5 )
      v6 = bitset1->blist.length;
    v7 = (int)(v6 - 1);
    if ( (int)(v6 - 1) < 0 )
    {
LABEL_9:
      if ( length <= v6 )
      {
        if ( v5 <= v6 )
          return 1;
        for ( i = &bitset2->blist.bits[v6]; !*i; ++i )
        {
          if ( ++v6 >= v5 )
            return 1;
        }
      }
      else
      {
        for ( j = &bitset1->blist.bits[v6]; !*j; ++j )
        {
          if ( ++v6 >= length )
            return 1;
        }
      }
    }
    else
    {
      bits = bitset2->blist.bits;
      v9 = &bitset2->blist.bits[v7];
      while ( *(unsigned __int64 *)((char *)v9 + (char *)bitset1->blist.bits - (char *)bits) == *v9 )
      {
        --v9;
        if ( --v7 < 0 )
          goto LABEL_9;
      }
    }
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
  return _bittest64((const __int64 *)&v3, bit & 0x3F);
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
  unsigned __int64 *i; // rdx

  v1 = bitset->blist.length - 1;
  if ( (int)v1 < 0 )
    return 1;
  for ( i = &bitset->blist.bits[(int)v1]; !*i; --i )
  {
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
  unsigned int v2; // ebx
  unsigned int v3; // ebp
  UFG::allocator::free_link *result; // rax
  UFG::allocator::free_link *v5; // r14
  unsigned int v6; // ebx
  unsigned int i; // edi
  __int64 v8; // rax

  v2 = ((__int64 (*)(void))bitset->size)() + 1;
  v3 = bitset->numBits(bitset);
  result = antlrMalloc(4i64 * v2);
  v5 = result;
  if ( result )
  {
    LODWORD(result->mNext) = v2;
    v6 = 0;
    for ( i = 1; v6 < v3; ++v6 )
    {
      if ( bitset->isMember(bitset, v6) == 1 )
      {
        v8 = i++;
        *((_DWORD *)&v5->mNext + v8) = v6;
      }
    }
    return v5;
  }
  return result;
}

