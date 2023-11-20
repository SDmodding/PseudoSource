// File Line: 102
// RVA: 0x260AF0
UFG::allocator::free_link *__fastcall antlr3StringFactoryNew(unsigned int encoding)
{
  unsigned int v1; // edi
  UFG::allocator::free_link *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  ANTLR3_STRING_struct *(__fastcall *v5)(ANTLR3_STRING_FACTORY_struct *, ANTLR3_STRING_struct *); // rax

  v1 = encoding;
  v2 = antlrCalloc(1u, 0x58u);
  if ( !v2 )
    return 0i64;
  v3 = antlr3VectorNew(0);
  LODWORD(v2[1].mNext) = 0;
  v2->mNext = v3;
  if ( !v3 )
  {
    antlrFree(v2);
    return 0i64;
  }
  if ( v1 < 0x10 )
    goto LABEL_14;
  if ( v1 <= 0x12 )
  {
    v2[2].mNext = (UFG::allocator::free_link *)newRawUTF16;
    v2[3].mNext = (UFG::allocator::free_link *)newSizeUTF16;
    v2[4].mNext = (UFG::allocator::free_link *)newPtrUTF16_UTF16;
    v2[5].mNext = (UFG::allocator::free_link *)newPtrUTF16_8;
    v2[6].mNext = (UFG::allocator::free_link *)newStrUTF16_UTF16;
    v2[7].mNext = (UFG::allocator::free_link *)newStrUTF16_8;
    v5 = printableUTF16;
    goto LABEL_9;
  }
  if ( v1 - 32 > 2 )
  {
LABEL_14:
    v2[2].mNext = (UFG::allocator::free_link *)newRaw8;
    v2[3].mNext = (UFG::allocator::free_link *)newSize8;
    v2[4].mNext = (UFG::allocator::free_link *)newPtr8;
    v2[5].mNext = (UFG::allocator::free_link *)newPtr8;
    v2[6].mNext = (UFG::allocator::free_link *)newStrUTF16_8;
    v2[7].mNext = (UFG::allocator::free_link *)newStrUTF16_8;
    v5 = printable8;
LABEL_9:
    v2[9].mNext = (UFG::allocator::free_link *)v5;
    v2[8].mNext = (UFG::allocator::free_link *)destroy;
    v2[10].mNext = (UFG::allocator::free_link *)closeFactory;
  }
  return v2;
}

// File Line: 190
// RVA: 0x260150
ANTLR3_STRING_struct *__fastcall newRaw8(ANTLR3_STRING_FACTORY_struct *factory)
{
  ANTLR3_STRING_FACTORY_struct *v1; // rdi
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v3; // rbx
  char v4; // ST20_1

  v1 = factory;
  result = (ANTLR3_STRING_struct *)antlrMalloc(0xC0ui64);
  v3 = result;
  if ( result )
  {
    stringInit8(result);
    v3->factory = v1;
    v4 = 1;
    v1->strings->set(v1->strings, v1->index, v3, (void (__fastcall *)(void *))stringFree, v4);
    v3->index = v1->index++;
    result = v3;
  }
  return result;
}

// File Line: 219
// RVA: 0x2601C0
ANTLR3_STRING_struct *__fastcall newRawUTF16(ANTLR3_STRING_FACTORY_struct *factory)
{
  ANTLR3_STRING_FACTORY_struct *v1; // rdi
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v3; // rbx
  char v4; // ST20_1

  v1 = factory;
  result = (ANTLR3_STRING_struct *)antlrMalloc(0xC0ui64);
  v3 = result;
  if ( result )
  {
    stringInitUTF16(result);
    v3->factory = v1;
    v4 = 1;
    v1->strings->set(v1->strings, v1->index, v3, (void (__fastcall *)(void *))stringFree, v4);
    v3->index = v1->index++;
    result = v3;
  }
  return result;
}

// File Line: 243
// RVA: 0x260670
void __fastcall stringFree(ANTLR3_STRING_struct *string)
{
  ANTLR3_STRING_struct *v1; // rbx
  char *v2; // rcx

  v1 = string;
  v2 = string->chars;
  if ( v2 )
    antlrFree(v2);
  antlrFree(v1);
}

// File Line: 264
// RVA: 0x2606A0
void __fastcall stringInit8(ANTLR3_STRING_struct *string)
{
  string->encoding = 4;
  *(_QWORD *)&string->len = 0i64;
  string->chars = 0i64;
  string->set = set8;
  string->set8 = set8;
  string->append = append8;
  string->append8 = append8;
  string->insert = insert8;
  string->insert8 = insert8;
  string->addi = addiUTF16;
  string->inserti = (char *(__fastcall *)(ANTLR3_STRING_struct *, unsigned int, int))insertiUTF16;
  string->addc = addc8;
  string->charAt = (unsigned int (__fastcall *)(ANTLR3_STRING_struct *, unsigned int))charAt8;
  string->compare = (unsigned int (__fastcall *)(ANTLR3_STRING_struct *, const char *))compare8;
  string->compare8 = (unsigned int (__fastcall *)(ANTLR3_STRING_struct *, const char *))compare8;
  string->subString = subString8;
  string->toInt32 = toInt32_8;
  string->to8 = (ANTLR3_STRING_struct *(__fastcall *)(ANTLR3_STRING_struct *))Assembly::GetRCX;
  string->toUTF8 = toUTF8_8;
  string->compareS = (unsigned int (__fastcall *)(ANTLR3_STRING_struct *, ANTLR3_STRING_struct *))compareS;
  string->setS = setS;
  string->appendS = appendS;
  string->insertS = (char *(__fastcall *)(ANTLR3_STRING_struct *, unsigned int, ANTLR3_STRING_struct *))insertS;
}

// File Line: 301
// RVA: 0x260790
void __fastcall stringInitUTF16(ANTLR3_STRING_struct *string)
{
  string->encoding = 4;
  *(_QWORD *)&string->len = 0i64;
  string->chars = 0i64;
  string->set = setUTF16_UTF16;
  string->set8 = setUTF16_8;
  string->append = appendUTF16_UTF16;
  string->append8 = appendUTF16_8;
  string->insert = insertUTF16_UTF16;
  string->insert8 = insertUTF16_8;
  string->addi = addiUTF16;
  string->inserti = (char *(__fastcall *)(ANTLR3_STRING_struct *, unsigned int, int))insertiUTF16;
  string->addc = addcUTF16;
  string->charAt = (unsigned int (__fastcall *)(ANTLR3_STRING_struct *, unsigned int))charAtUTF16;
  string->compare = (unsigned int (__fastcall *)(ANTLR3_STRING_struct *, const char *))compareUTF16_UTF16;
  string->compare8 = (unsigned int (__fastcall *)(ANTLR3_STRING_struct *, const char *))compareUTF16_8;
  string->subString = subStringUTF16;
  string->toInt32 = toInt32_UTF16;
  string->to8 = to8_UTF16;
  string->toUTF8 = toUTF8_UTF16;
  string->compareS = (unsigned int (__fastcall *)(ANTLR3_STRING_struct *, ANTLR3_STRING_struct *))compareS;
  string->setS = setS;
  string->appendS = appendS;
  string->insertS = (char *(__fastcall *)(ANTLR3_STRING_struct *, unsigned int, ANTLR3_STRING_struct *))insertS;
}

// File Line: 353
// RVA: 0x260A20
ANTLR3_STRING_struct *__fastcall toUTF8_8(ANTLR3_STRING_struct *string)
{
  return (ANTLR3_STRING_struct *)string->factory->newPtr(string->factory, string->chars, string->len);
}

// File Line: 364
// RVA: 0x260A40
ANTLR3_STRING_struct *__fastcall toUTF8_UTF16(ANTLR3_STRING_struct *string)
{
  ANTLR3_STRING_struct *v1; // rdi
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v3; // rbx
  unsigned int v4; // edx
  UFG::allocator::free_link *v5; // rax
  char *targetStart; // [rsp+40h] [rbp+8h]
  unsigned __int16 *sourceStart; // [rsp+48h] [rbp+10h]

  v1 = string;
  result = string->factory->newStr8(string->factory, &customWorldMapCaption);
  v3 = result;
  if ( result )
  {
    antlrFree(result->chars);
    v4 = v1->len;
    v3->size = 3 * v4;
    v5 = antlrMalloc(3 * v4 + 1);
    v3->chars = (char *)v5;
    if ( v5 )
    {
      sourceStart = (unsigned __int16 *)v1->chars;
      targetStart = v3->chars;
      ConvertUTF16toUTF8(
        (const unsigned __int16 **)&sourceStart,
        &sourceStart[v1->len],
        &targetStart,
        &targetStart[v3->size - 1],
        lenientConversion);
      v3->len = (_DWORD)targetStart - LODWORD(v3->chars);
      targetStart[1] = 0;
    }
    result = v3;
  }
  return result;
}

// File Line: 425
// RVA: 0x260230
ANTLR3_STRING_struct *__fastcall newSize8(ANTLR3_STRING_FACTORY_struct *factory, unsigned int size)
{
  unsigned int v2; // ebx
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v4; // rdi
  unsigned int v5; // ebx
  UFG::allocator::free_link *v6; // rax

  v2 = size;
  result = (ANTLR3_STRING_struct *)((__int64 (*)(void))factory->newRaw)();
  v4 = result;
  if ( result )
  {
    v5 = v2 + 1;
    v6 = antlrMalloc(v5);
    v4->chars = (char *)v6;
    LOBYTE(v6->mNext) = 0;
    v4->size = v5;
    result = v4;
  }
  return result;
}

// File Line: 453
// RVA: 0x260280
ANTLR3_STRING_struct *__fastcall newSizeUTF16(ANTLR3_STRING_FACTORY_struct *factory, unsigned int size)
{
  unsigned int v2; // ebx
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v4; // rdi
  unsigned int v5; // ebx
  UFG::allocator::free_link *v6; // rax

  v2 = size;
  result = (ANTLR3_STRING_struct *)((__int64 (*)(void))factory->newRaw)();
  v4 = result;
  if ( result )
  {
    v5 = v2 + 1;
    v6 = antlrMalloc(2i64 * v5);
    v4->chars = (char *)v6;
    LOBYTE(v6->mNext) = 0;
    v4->size = v5;
    result = v4;
  }
  return result;
}

// File Line: 480
// RVA: 0x25FFF0
ANTLR3_STRING_struct *__fastcall newPtr8(ANTLR3_STRING_FACTORY_struct *factory, char *ptr, unsigned int size)
{
  char *v3; // rsi
  __int64 v4; // rdi
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v6; // rbx

  v3 = ptr;
  v4 = size;
  result = factory->newSize(factory, size);
  v6 = result;
  if ( result && (_DWORD)v4 )
  {
    if ( v3 )
    {
      UFG::qMemMove(result->chars, v3, v4);
      v6->chars[v4] = 0;
      v6->len = v4;
    }
    result = v6;
  }
  return result;
}

// File Line: 513
// RVA: 0x260060
ANTLR3_STRING_struct *__fastcall newPtrUTF16_8(ANTLR3_STRING_FACTORY_struct *factory, char *ptr, unsigned int size)
{
  char *v3; // rbx
  __int64 v4; // rdi
  ANTLR3_STRING_struct *result; // rax
  char *v6; // rcx
  int v7; // edx

  v3 = ptr;
  v4 = size;
  result = factory->newSize(factory, size);
  if ( result && (_DWORD)v4 && v3 )
  {
    v6 = result->chars;
    v7 = v4;
    if ( (signed int)v4 > 0 )
    {
      do
      {
        --v7;
        v6 += 2;
        *((_WORD *)v6 - 1) = (unsigned __int8)*v3++;
      }
      while ( v7 > 0 );
    }
    *(_WORD *)&result->chars[2 * v4] = 0;
    result->len = v4;
  }
  return result;
}

// File Line: 561
// RVA: 0x2600E0
ANTLR3_STRING_struct *__fastcall newPtrUTF16_UTF16(ANTLR3_STRING_FACTORY_struct *factory, char *ptr, unsigned int size)
{
  char *v3; // rsi
  __int64 v4; // rdi
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v6; // rbx

  v3 = ptr;
  v4 = size;
  result = factory->newSize(factory, size);
  v6 = result;
  if ( result && (_DWORD)v4 )
  {
    if ( v3 )
    {
      UFG::qMemMove(result->chars, v3, 2 * v4);
      *(_WORD *)&v6->chars[2 * v4] = 0;
      v6->len = v4;
    }
    result = v6;
  }
  return result;
}

// File Line: 596
// RVA: 0x2602D0
ANTLR3_STRING_struct *__fastcall newStrUTF16_8(ANTLR3_STRING_FACTORY_struct *factory, char *ptr)
{
  signed __int64 v2; // r8

  v2 = -1i64;
  do
    ++v2;
  while ( ptr[v2] );
  return (ANTLR3_STRING_struct *)((__int64 (*)(void))factory->newPtr8)();
}

// File Line: 618
// RVA: 0x2602F0
ANTLR3_STRING_struct *__fastcall newStrUTF16_UTF16(ANTLR3_STRING_FACTORY_struct *factory, char *ptr)
{
  int v2; // er8
  char *i; // rax

  v2 = 0;
  for ( i = ptr; *(_WORD *)i; ++v2 )
    i += 2;
  return (ANTLR3_STRING_struct *)((__int64 (*)(void))factory->newPtr)();
}

// File Line: 636
// RVA: 0x25FC70
void __fastcall destroy(ANTLR3_STRING_FACTORY_struct *factory, ANTLR3_STRING_struct *string)
{
  unsigned int v2; // ebx
  ANTLR3_STRING_FACTORY_struct *v3; // rdi

  v2 = string->index;
  v3 = factory;
  factory->strings->del(factory->strings, string->index);
  if ( v2 < --v3->index )
  {
    do
    {
      *((_DWORD *)v3->strings->elements[v2].element + 6) = v2;
      ++v2;
    }
    while ( v2 < v3->index );
  }
}

// File Line: 681
// RVA: 0x260320
ANTLR3_STRING_struct *__fastcall printable8(ANTLR3_STRING_FACTORY_struct *factory, ANTLR3_STRING_struct *instr)
{
  ANTLR3_STRING_struct *v2; // rsi
  ANTLR3_STRING_struct *v3; // rax
  __int64 v4; // rdi
  _WORD *v5; // rbx
  ANTLR3_STRING_struct *v6; // rbp
  unsigned __int8 v7; // dl

  v2 = instr;
  v3 = factory->newSize(factory, 2 * instr->len + 1);
  v4 = 0i64;
  v5 = v3->chars;
  v6 = v3;
  if ( v2->len )
  {
    do
    {
      v7 = v2->chars[v4];
      if ( v7 == 10 )
      {
        *v5 = 28252;
        ++v5;
      }
      else if ( v7 == 13 )
      {
        *v5 = 29276;
        ++v5;
      }
      else
      {
        if ( isprint(v7) )
          *(_BYTE *)v5 = v2->chars[v4];
        else
          *(_BYTE *)v5 = 63;
        v5 = (_WORD *)((char *)v5 + 1);
      }
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < v2->len );
  }
  *(_BYTE *)v5 = 0;
  v6->len = (_DWORD)v5 - LODWORD(v6->chars);
  return v6;
}

// File Line: 728
// RVA: 0x2603E0
ANTLR3_STRING_struct *__fastcall printableUTF16(ANTLR3_STRING_FACTORY_struct *factory, ANTLR3_STRING_struct *instr)
{
  ANTLR3_STRING_struct *v2; // rbp
  ANTLR3_STRING_struct *v3; // rax
  char *v4; // r12
  _DWORD *v5; // rbx
  ANTLR3_STRING_struct *v6; // r15
  unsigned int v7; // edi
  unsigned int v8; // esi
  unsigned __int16 v9; // ax
  ANTLR3_STRING_struct *v11; // [rsp+50h] [rbp+8h]

  v2 = instr;
  v3 = factory->newSize(factory, 2 * instr->len + 1);
  v4 = v2->chars;
  v5 = v3->chars;
  v6 = v3;
  v11 = v3;
  v7 = 0;
  v8 = 0;
  if ( v2->len )
  {
    do
    {
      v9 = *(_WORD *)&v4[2 * v8];
      if ( v9 == 10 )
      {
        *v5 = 7209052;
        ++v5;
        v7 += 2;
      }
      else if ( v9 == 13 )
      {
        *v5 = 7471196;
        ++v5;
        v7 += 2;
      }
      else
      {
        if ( isprint(v9) )
          *(_WORD *)v5 = *(_WORD *)&v4[2 * v8];
        else
          *(_WORD *)v5 = 63;
        v5 = (_DWORD *)((char *)v5 + 2);
        ++v7;
      }
      ++v8;
    }
    while ( v8 < v2->len );
    v6 = v11;
  }
  *(_WORD *)v5 = 0;
  v6->len = v7;
  return v6;
}

// File Line: 786
// RVA: 0x25FB70
void __fastcall closeFactory(ANTLR3_STRING_FACTORY_struct *factory)
{
  ANTLR3_STRING_FACTORY_struct *v1; // rbx

  v1 = factory;
  factory->strings->free(factory->strings);
  antlrFree(v1);
}

// File Line: 799
// RVA: 0x25F950
char *__fastcall append8(ANTLR3_STRING_struct *string, const char *newbit)
{
  const char *v2; // rsi
  ANTLR3_STRING_struct *v3; // rdi
  signed __int64 v4; // rbx
  __int64 v5; // rcx
  unsigned int v6; // eax
  UFG::allocator::free_link *v7; // rax

  v2 = newbit;
  v3 = string;
  v4 = -1i64;
  do
    ++v4;
  while ( newbit[v4] );
  v5 = string->len;
  v6 = v4 + v5 + 1;
  if ( v3->size < v6 )
  {
    v7 = antlrRealloc(v3->chars, v6);
    v5 = v3->len;
    v3->chars = (char *)v7;
    v3->size = v4 + v5 + 1;
  }
  UFG::qMemMove(&v3->chars[v5], v2, v4 + 1);
  v3->len += v4;
  return v3->chars;
}

// File Line: 820
// RVA: 0x25FA00
char *__fastcall appendUTF16_8(ANTLR3_STRING_struct *string, const char *newbit)
{
  const char *v2; // rbx
  ANTLR3_STRING_struct *v3; // rsi
  signed __int64 v4; // rdi
  __int64 v5; // rcx
  unsigned int v6; // er8
  UFG::allocator::free_link *v7; // rax
  char *v8; // rax
  char *v9; // rdx
  __int64 v10; // rcx
  __int16 v11; // ax

  v2 = newbit;
  v3 = string;
  v4 = -1i64;
  do
    ++v4;
  while ( newbit[v4] );
  v5 = string->len;
  v6 = v5 + v4;
  if ( v3->size < (unsigned int)(v5 + v4 + 1) )
  {
    v7 = antlrRealloc(v3->chars, 2 * v6 + 2);
    v5 = v3->len;
    v6 = v5 + v4;
    v3->chars = (char *)v7;
    v3->size = v5 + v4 + 1;
  }
  v8 = v3->chars;
  v3->len = v6;
  v9 = &v8[2 * v5];
  if ( (_DWORD)v4 )
  {
    v10 = (unsigned int)v4;
    do
    {
      v11 = *v2;
      v9 += 2;
      ++v2;
      *((_WORD *)v9 - 1) = v11;
      --v10;
    }
    while ( v10 );
  }
  *(_WORD *)v9 = 0;
  return v3->chars;
}

// File Line: 847
// RVA: 0x25FAA0
char *__fastcall appendUTF16_UTF16(ANTLR3_STRING_struct *string, const char *newbit)
{
  int v2; // ebx
  const char *v3; // rsi
  ANTLR3_STRING_struct *v4; // rdi
  const char *i; // rax
  __int64 v6; // rcx
  UFG::allocator::free_link *v7; // rax

  v2 = 0;
  v3 = newbit;
  v4 = string;
  for ( i = newbit; *(_WORD *)i; ++v2 )
    i += 2;
  v6 = string->len;
  if ( v4->size < (unsigned int)(v6 + v2 + 1) )
  {
    v7 = antlrRealloc(v4->chars, (unsigned int)(2 * (v6 + v2) + 2));
    v6 = v4->len;
    v4->chars = (char *)v7;
    v4->size = v2 + v6 + 1;
  }
  UFG::qMemMove(&v4->chars[2 * v6], v3, 2 * v2 + 2);
  v4->len += v2;
  return v4->chars;
}

// File Line: 877
// RVA: 0x2604D0
char *__fastcall set8(ANTLR3_STRING_struct *string, const char *chars)
{
  const char *v2; // rdi
  ANTLR3_STRING_struct *v3; // rsi
  signed __int64 v4; // rbx
  unsigned int v5; // ebp
  UFG::allocator::free_link *v6; // rax
  char *result; // rax

  v2 = chars;
  v3 = string;
  v4 = -1i64;
  do
    ++v4;
  while ( chars[v4] );
  v5 = v4 + 1;
  if ( string->size < (unsigned int)(v4 + 1) )
  {
    v6 = antlrRealloc(string->chars, v5);
    v3->size = v5;
    v3->chars = (char *)v6;
  }
  UFG::qMemMove(v3->chars, v2, v5);
  result = v3->chars;
  v3->len = v4;
  return result;
}

// File Line: 898
// RVA: 0x260550
char *__fastcall setUTF16_8(ANTLR3_STRING_struct *string, const char *chars)
{
  const char *v2; // rsi
  ANTLR3_STRING_struct *v3; // rdi
  signed __int64 v4; // rbx
  UFG::allocator::free_link *v5; // rax
  char *v6; // r8
  unsigned int v7; // edx
  __int64 v8; // rax

  v2 = chars;
  v3 = string;
  v4 = -1i64;
  do
    ++v4;
  while ( chars[v4] );
  if ( string->size < (unsigned int)(v4 + 1) )
  {
    v5 = antlrRealloc(string->chars, (unsigned int)(2 * v4 + 2));
    v3->size = v4 + 1;
    v3->chars = (char *)v5;
  }
  v6 = v3->chars;
  v3->len = v4;
  v7 = 0;
  if ( (_DWORD)v4 )
  {
    do
    {
      v8 = v7++;
      v6 += 2;
      *((_WORD *)v6 - 1) = v2[v8];
    }
    while ( v7 < v3->len );
  }
  *(_WORD *)v6 = 0;
  return v3->chars;
}

// File Line: 923
// RVA: 0x2605F0
char *__fastcall setUTF16_UTF16(ANTLR3_STRING_struct *string, const char *chars)
{
  unsigned int v2; // ebx
  const char *v3; // rsi
  ANTLR3_STRING_struct *v4; // rdi
  const char *i; // rax
  UFG::allocator::free_link *v6; // rax
  char *result; // rax

  v2 = 0;
  v3 = chars;
  v4 = string;
  for ( i = chars; *(_WORD *)i; ++v2 )
    i += 2;
  if ( string->size < v2 + 1 )
  {
    v6 = antlrRealloc(string->chars, 2 * v2 + 2);
    v4->size = v2 + 1;
    v4->chars = (char *)v6;
  }
  UFG::qMemMove(v4->chars, v3, 2 * v2 + 2);
  result = v4->chars;
  v4->len = v2;
  return result;
}

// File Line: 954
// RVA: 0x25F860
char *__fastcall addc8(ANTLR3_STRING_struct *string, unsigned int c)
{
  ANTLR3_STRING_struct *v2; // rbx
  __int64 v3; // rcx
  char v4; // di
  UFG::allocator::free_link *v5; // rax

  v2 = string;
  v3 = string->len;
  v4 = c;
  if ( v2->size < (unsigned int)(v3 + 2) )
  {
    v5 = antlrRealloc(v2->chars, (unsigned int)(v3 + 2));
    v3 = v2->len;
    v2->chars = (char *)v5;
    v2->size = v3 + 2;
  }
  v2->chars[v3] = v4;
  v2->chars[v2->len++ + 1] = 0;
  return v2->chars;
}

// File Line: 969
// RVA: 0x25F8C0
char *__fastcall addcUTF16(ANTLR3_STRING_struct *string, unsigned int c)
{
  unsigned int v2; // er8
  __int16 v3; // di
  ANTLR3_STRING_struct *v4; // rbx
  UFG::allocator::free_link *v5; // rax
  char *v6; // rcx

  v2 = string->len;
  v3 = c;
  v4 = string;
  if ( string->size < v2 + 2 )
  {
    v5 = antlrRealloc(string->chars, 2 * (v2 + 2));
    v2 = v4->len;
    v4->chars = (char *)v5;
    v4->size = v2 + 2;
  }
  v6 = v4->chars;
  *(_WORD *)&v6[2 * v2] = v3;
  *(_WORD *)&v6[2 * v4->len++ + 2] = 0;
  return v4->chars;
}

// File Line: 988
// RVA: 0x25F920
char *__fastcall addiUTF16(ANTLR3_STRING_struct *string, int i)
{
  ANTLR3_STRING_struct *v2; // rbx
  char stringa; // [rsp+20h] [rbp-28h]

  v2 = string;
  sprintf(&stringa, "%d", (unsigned int)i);
  return (char *)v2->append8(v2, &stringa);
}

// File Line: 1007
// RVA: 0x25FFB0
char *__fastcall insertiUTF16(ANTLR3_STRING_struct *string, unsigned int point, __int64 i)
{
  unsigned int v3; // ebx
  ANTLR3_STRING_struct *v4; // rdi
  char stringa; // [rsp+20h] [rbp-28h]

  v3 = point;
  v4 = string;
  sprintf(&stringa, "%d", i);
  return (char *)v4->insert8(v4, v3, &stringa);
}

// File Line: 1024
// RVA: 0x25FCD0
char *__fastcall insert8(ANTLR3_STRING_struct *string, unsigned int point, const char *newbit)
{
  const char *v3; // rbp
  unsigned int v4; // er8
  __int64 v5; // r14
  ANTLR3_STRING_struct *v6; // rsi
  signed __int64 v8; // rbx
  unsigned int v9; // eax
  UFG::allocator::free_link *v10; // rax

  v3 = newbit;
  v4 = string->len;
  v5 = point;
  v6 = string;
  if ( point >= v4 )
    return (char *)string->append(string, v3);
  v8 = -1i64;
  do
    ++v8;
  while ( v3[v8] );
  if ( !(_DWORD)v8 )
    return string->chars;
  v9 = v8 + v4 + 1;
  if ( string->size < v9 )
  {
    v10 = antlrRealloc(string->chars, v9);
    v4 = v6->len;
    v6->chars = (char *)v10;
    v6->size = v8 + v4 + 1;
  }
  UFG::qMemMove(&v6->chars[v5 + (unsigned int)v8], &v6->chars[v5], v4 - v5 + 1);
  UFG::qMemMove(&v6->chars[v5], v3, v8);
  v6->len += v8;
  return v6->chars;
}

// File Line: 1060
// RVA: 0x25FDB0
char *__fastcall insertUTF16_8(ANTLR3_STRING_struct *string, unsigned int point, const char *newbit)
{
  const char *v3; // rbx
  unsigned int v4; // er8
  __int64 v5; // r15
  ANTLR3_STRING_struct *v6; // rbp
  signed __int64 v8; // rsi
  UFG::allocator::free_link *v9; // rax
  __int64 v10; // r14
  char *v11; // rcx
  signed __int64 v12; // rcx
  __int16 v13; // ax

  v3 = newbit;
  v4 = string->len;
  v5 = point;
  v6 = string;
  if ( point >= v4 )
    return (char *)string->append8(string, v3);
  v8 = -1i64;
  do
    ++v8;
  while ( v3[v8] );
  if ( !(_DWORD)v8 )
    return string->chars;
  if ( string->size < v4 + (unsigned int)v8 + 1 )
  {
    v9 = antlrRealloc(string->chars, 2 * (v4 + (unsigned int)v8) + 2);
    v4 = v6->len;
    v6->chars = (char *)v9;
    v6->size = v8 + v4 + 1;
  }
  v10 = (unsigned int)v8;
  UFG::qMemMove(&v6->chars[2 * ((unsigned int)v8 + v5)], &v6->chars[2 * v5], 2 * (v4 - v5) + 2);
  v11 = v6->chars;
  v6->len += v8;
  v12 = (signed __int64)&v11[2 * v5];
  if ( (_DWORD)v8 )
  {
    do
    {
      v13 = *v3;
      v12 += 2i64;
      ++v3;
      *(_WORD *)(v12 - 2) = v13;
      --v10;
    }
    while ( v10 );
  }
  return v6->chars;
}

// File Line: 1100
// RVA: 0x25FEB0
char *__fastcall insertUTF16_UTF16(ANTLR3_STRING_struct *string, unsigned int point, const char *newbit)
{
  const char *v3; // rbp
  unsigned int v4; // er8
  __int64 v5; // r14
  ANTLR3_STRING_struct *v6; // rsi
  unsigned int v8; // edi
  const char *v9; // rax
  UFG::allocator::free_link *v10; // rax

  v3 = newbit;
  v4 = string->len;
  v5 = point;
  v6 = string;
  if ( point >= v4 )
    return (char *)string->append(string, v3);
  v8 = 0;
  v9 = v3;
  if ( !*(_WORD *)v3 )
    return string->chars;
  do
  {
    v9 += 2;
    ++v8;
  }
  while ( *(_WORD *)v9 );
  if ( !v8 )
    return string->chars;
  if ( string->size < v4 + v8 + 1 )
  {
    v10 = antlrRealloc(string->chars, 2 * (v4 + v8) + 2);
    v4 = v6->len;
    v6->chars = (char *)v10;
    v6->size = v8 + v4 + 1;
  }
  UFG::qMemMove(&v6->chars[2 * (v5 + v8)], &v6->chars[2 * v5], 2 * (v4 - v5) + 2);
  UFG::qMemMove(&v6->chars[2 * v5], v3, 2 * v8);
  v6->len += v8;
  return v6->chars;
}

// File Line: 1145
// RVA: 0x260540
char *__fastcall setS(ANTLR3_STRING_struct *string, ANTLR3_STRING_struct *chars)
{
  return (char *)string->set(string, chars->chars);
}

// File Line: 1150
// RVA: 0x25F9D0
char *__fastcall appendS(ANTLR3_STRING_struct *string, ANTLR3_STRING_struct *newbit)
{
  char *result; // rax

  if ( newbit && newbit->len && newbit->size && newbit->chars )
    result = (char *)((__int64 (*)(void))string->append)();
  else
    result = string->chars;
  return result;
}

// File Line: 1164
// RVA: 0x25FDA0
char *__fastcall insertS(ANTLR3_STRING_struct *string, __int64 point, ANTLR3_STRING_struct *newbit)
{
  return (char *)string->insert(string, point, newbit->chars);
}

// File Line: 1173
// RVA: 0x25FBA0
__int64 __fastcall compare8(ANTLR3_STRING_struct *string, const char *compStr)
{
  char *v2; // rax
  const char *v3; // rdx
  unsigned __int8 v4; // cl

  v2 = string->chars;
  v3 = (const char *)(compStr - v2);
  while ( 1 )
  {
    v4 = *v2;
    if ( *v2 != v3[(_QWORD)v2] )
      break;
    ++v2;
    if ( !v4 )
      return 0i64;
  }
  return -(v4 < v3[(_QWORD)v2]) | 1u;
}

// File Line: 1183
// RVA: 0x25FBD0
__int64 __fastcall compareUTF16_8(ANTLR3_STRING_struct *string, const char *compStr)
{
  char *v2; // rax
  unsigned __int16 i; // r8
  char v4; // cl

  v2 = string->chars;
  for ( i = *(_WORD *)v2; i; ++compStr )
  {
    v4 = *compStr;
    if ( !*compStr )
      break;
    if ( i != v4 )
      return (unsigned int)i - v4;
    i = *((_WORD *)v2 + 1);
    v2 += 2;
  }
  return (unsigned int)*(unsigned __int16 *)v2 - *compStr;
}

// File Line: 1212
// RVA: 0x25FC20
__int64 __fastcall compareUTF16_UTF16(ANTLR3_STRING_struct *string, const char *compStr8)
{
  char *v2; // rax
  unsigned __int16 i; // r8
  unsigned __int16 v4; // cx

  v2 = string->chars;
  for ( i = *(_WORD *)v2; i; compStr8 += 2 )
  {
    v4 = *(_WORD *)compStr8;
    if ( !*(_WORD *)compStr8 )
      break;
    if ( i != v4 )
      return i - (unsigned int)v4;
    i = *((_WORD *)v2 + 1);
    v2 += 2;
  }
  return *(unsigned __int16 *)v2 - (unsigned int)*(unsigned __int16 *)compStr8;
}

// File Line: 1242
// RVA: 0x25FBC0
__int64 __fastcall compareS(ANTLR3_STRING_struct *string, ANTLR3_STRING_struct *compStr)
{
  return string->compare(string, compStr->chars);
}

// File Line: 1252
// RVA: 0x25FB30
__int64 __fastcall charAt8(ANTLR3_STRING_struct *string, unsigned int offset)
{
  __int64 result; // rax

  if ( offset <= string->len )
    result = (unsigned __int8)string->chars[offset];
  else
    result = 0i64;
  return result;
}

// File Line: 1268
// RVA: 0x25FB50
__int64 __fastcall charAtUTF16(ANTLR3_STRING_struct *string, unsigned int offset)
{
  __int64 result; // rax

  if ( offset <= string->len )
    result = *(unsigned __int16 *)&string->chars[2 * offset];
  else
    result = 0i64;
  return result;
}

// File Line: 1284
// RVA: 0x2608A0
ANTLR3_STRING_struct *__fastcall subString8(ANTLR3_STRING_struct *string, unsigned int startIndex, unsigned int endIndex)
{
  unsigned int v3; // eax

  v3 = string->len;
  if ( endIndex > v3 )
    endIndex = v3 + 1;
  return (ANTLR3_STRING_struct *)string->factory->newPtr(
                                   string->factory,
                                   &string->chars[startIndex],
                                   endIndex - startIndex);
}

// File Line: 1301
// RVA: 0x2608C0
ANTLR3_STRING_struct *__fastcall subStringUTF16(ANTLR3_STRING_struct *string, unsigned int startIndex, unsigned int endIndex)
{
  unsigned int v3; // eax

  v3 = string->len;
  if ( endIndex > v3 )
    endIndex = v3 + 1;
  return (ANTLR3_STRING_struct *)string->factory->newPtr(
                                   string->factory,
                                   &string->chars[2 * startIndex],
                                   endIndex - startIndex);
}

// File Line: 1317
// RVA: 0x260990
int __fastcall toInt32_8(ANTLR3_STRING_struct *string)
{
  return atol(string->chars);
}

// File Line: 1325
// RVA: 0x2609A0
__int64 __fastcall toInt32_UTF16(ANTLR3_STRING_struct *string)
{
  char *v1; // rbx
  unsigned int v2; // edi
  char v3; // si
  unsigned __int16 i; // ax
  int v5; // eax

  v1 = string->chars;
  v2 = 0;
  v3 = 0;
  if ( *(_WORD *)v1 == 45 )
  {
    v3 = 1;
  }
  else if ( *(_WORD *)v1 != 43 )
  {
    goto LABEL_5;
  }
  v1 += 2;
LABEL_5:
  for ( i = *(_WORD *)v1; *(_WORD *)v1; i = *(_WORD *)v1 )
  {
    if ( !isdigit(i) )
      break;
    v5 = *(unsigned __int16 *)v1;
    v1 += 2;
    v2 = v5 + 2 * (5 * v2 - 24);
  }
  if ( v3 )
    v2 = -v2;
  return v2;
}

// File Line: 1369
// RVA: 0x2608F0
ANTLR3_STRING_struct *__fastcall to8_UTF16(ANTLR3_STRING_struct *string)
{
  ANTLR3_STRING_struct *v1; // rdi
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  __int64 v5; // r9
  char v6; // dl

  v1 = string;
  result = newRaw8(string->factory);
  v3 = result;
  if ( result )
  {
    v4 = antlrMalloc(v1->len + 1);
    v5 = 0i64;
    v3->chars = (char *)v4;
    v3->size = v1->len + 1;
    v3->len = v1->len;
    if ( v1->len )
    {
      do
      {
        v6 = *(_WORD *)&v1->chars[2 * v5];
        if ( *(unsigned __int16 *)&v1->chars[2 * v5] > 0xFFu )
          v6 = 95;
        v3->chars[v5] = v6;
        v5 = (unsigned int)(v5 + 1);
      }
      while ( (unsigned int)v5 < v1->len );
    }
    v3->chars[v3->len] = 0;
    result = v3;
  }
  return result;
}

