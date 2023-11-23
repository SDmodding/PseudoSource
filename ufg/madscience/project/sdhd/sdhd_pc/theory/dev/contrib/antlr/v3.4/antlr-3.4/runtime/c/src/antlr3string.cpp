// File Line: 102
// RVA: 0x260AF0
UFG::allocator::free_link *__fastcall antlr3StringFactoryNew(unsigned int encoding)
{
  UFG::allocator::free_link *v2; // rbx
  __int64 v3; // rax
  ANTLR3_STRING_struct *(__fastcall *v5)(ANTLR3_STRING_FACTORY_struct *, ANTLR3_STRING_struct *); // rax

  v2 = antlrCalloc(1u, 0x58u);
  if ( !v2 )
    return 0i64;
  v3 = antlr3VectorNew(0);
  LODWORD(v2[1].mNext) = 0;
  v2->mNext = (UFG::allocator::free_link *)v3;
  if ( !v3 )
  {
    antlrFree((char *)v2);
    return 0i64;
  }
  if ( encoding < 0x10 )
    goto LABEL_8;
  if ( encoding <= 0x12 )
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
  if ( encoding - 32 > 2 )
  {
LABEL_8:
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
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v3; // rbx
  char v4; // [rsp+20h] [rbp-18h]

  result = (ANTLR3_STRING_struct *)antlrMalloc(0xC0ui64);
  v3 = result;
  if ( result )
  {
    stringInit8(result);
    v3->factory = factory;
    v4 = 1;
    factory->strings->set(factory->strings, factory->index, v3, (void (__fastcall *)(void *))stringFree, v4);
    v3->index = factory->index++;
    return v3;
  }
  return result;
}

// File Line: 219
// RVA: 0x2601C0
ANTLR3_STRING_struct *__fastcall newRawUTF16(ANTLR3_STRING_FACTORY_struct *factory)
{
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v3; // rbx
  char v4; // [rsp+20h] [rbp-18h]

  result = (ANTLR3_STRING_struct *)antlrMalloc(0xC0ui64);
  v3 = result;
  if ( result )
  {
    stringInitUTF16(result);
    v3->factory = factory;
    v4 = 1;
    factory->strings->set(factory->strings, factory->index, v3, (void (__fastcall *)(void *))stringFree, v4);
    v3->index = factory->index++;
    return v3;
  }
  return result;
}

// File Line: 243
// RVA: 0x260670
void __fastcall stringFree(ANTLR3_STRING_struct *string)
{
  char *chars; // rcx

  chars = string->chars;
  if ( chars )
    antlrFree(chars);
  antlrFree((char *)string);
}

// File Line: 264
// RVA: 0x2606A0
void __fastcall stringInit8(ANTLR3_STRING_struct *string)
{
  string->encoding = 4;
  *(_QWORD *)&string->len = 0i64;
  string->chars = 0i64;
  string->set = (char *(__fastcall *)(ANTLR3_STRING_struct *, const char *))set8;
  string->set8 = (char *(__fastcall *)(ANTLR3_STRING_struct *, const char *))set8;
  string->append = (char *(__fastcall *)(ANTLR3_STRING_struct *, const char *))append8;
  string->append8 = (char *(__fastcall *)(ANTLR3_STRING_struct *, const char *))append8;
  string->insert = (char *(__fastcall *)(ANTLR3_STRING_struct *, unsigned int, const char *))insert8;
  string->insert8 = (char *(__fastcall *)(ANTLR3_STRING_struct *, unsigned int, const char *))insert8;
  string->addi = (char *(__fastcall *)(ANTLR3_STRING_struct *, int))addiUTF16;
  string->inserti = (char *(__fastcall *)(ANTLR3_STRING_struct *, unsigned int, int))insertiUTF16;
  string->addc = (char *(__fastcall *)(ANTLR3_STRING_struct *, unsigned int))addc8;
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
  string->set = (char *(__fastcall *)(ANTLR3_STRING_struct *, const char *))setUTF16_UTF16;
  string->set8 = setUTF16_8;
  string->append = (char *(__fastcall *)(ANTLR3_STRING_struct *, const char *))appendUTF16_UTF16;
  string->append8 = appendUTF16_8;
  string->insert = (char *(__fastcall *)(ANTLR3_STRING_struct *, unsigned int, const char *))insertUTF16_UTF16;
  string->insert8 = insertUTF16_8;
  string->addi = (char *(__fastcall *)(ANTLR3_STRING_struct *, int))addiUTF16;
  string->inserti = (char *(__fastcall *)(ANTLR3_STRING_struct *, unsigned int, int))insertiUTF16;
  string->addc = (char *(__fastcall *)(ANTLR3_STRING_struct *, unsigned int))addcUTF16;
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
  return string->factory->newPtr(string->factory, string->chars, string->len);
}

// File Line: 364
// RVA: 0x260A40
ANTLR3_STRING_struct *__fastcall toUTF8_UTF16(ANTLR3_STRING_struct *string)
{
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v3; // rbx
  unsigned int len; // edx
  UFG::allocator::free_link *v5; // rax
  char *targetStart; // [rsp+40h] [rbp+8h] BYREF
  unsigned __int16 *sourceStart; // [rsp+48h] [rbp+10h] BYREF

  result = string->factory->newStr8(string->factory, &customCaption);
  v3 = result;
  if ( result )
  {
    antlrFree(result->chars);
    len = string->len;
    v3->size = 3 * len;
    v5 = antlrMalloc(3 * len + 1);
    v3->chars = (char *)v5;
    if ( v5 )
    {
      sourceStart = (unsigned __int16 *)string->chars;
      targetStart = v3->chars;
      ConvertUTF16toUTF8(
        (const unsigned __int16 **)&sourceStart,
        &sourceStart[string->len],
        &targetStart,
        &targetStart[v3->size - 1],
        lenientConversion);
      v3->len = (_DWORD)targetStart - LODWORD(v3->chars);
      targetStart[1] = 0;
    }
    return v3;
  }
  return result;
}

// File Line: 425
// RVA: 0x260230
ANTLR3_STRING_struct *__fastcall newSize8(ANTLR3_STRING_FACTORY_struct *factory, unsigned int size)
{
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v4; // rdi
  unsigned int v5; // ebx
  UFG::allocator::free_link *v6; // rax

  result = (ANTLR3_STRING_struct *)((__int64 (*)(void))factory->newRaw)();
  v4 = result;
  if ( result )
  {
    v5 = size + 1;
    v6 = antlrMalloc(v5);
    v4->chars = (char *)v6;
    LOBYTE(v6->mNext) = 0;
    v4->size = v5;
    return v4;
  }
  return result;
}

// File Line: 453
// RVA: 0x260280
ANTLR3_STRING_struct *__fastcall newSizeUTF16(ANTLR3_STRING_FACTORY_struct *factory, unsigned int size)
{
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v4; // rdi
  unsigned int v5; // ebx
  UFG::allocator::free_link *v6; // rax

  result = (ANTLR3_STRING_struct *)((__int64 (*)(void))factory->newRaw)();
  v4 = result;
  if ( result )
  {
    v5 = size + 1;
    v6 = antlrMalloc(2i64 * v5);
    v4->chars = (char *)v6;
    LOBYTE(v6->mNext) = 0;
    v4->size = v5;
    return v4;
  }
  return result;
}

// File Line: 480
// RVA: 0x25FFF0
ANTLR3_STRING_struct *__fastcall newPtr8(ANTLR3_STRING_FACTORY_struct *factory, char *ptr, unsigned int size)
{
  __int64 v4; // rdi
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v6; // rbx

  v4 = size;
  result = factory->newSize(factory, size);
  v6 = result;
  if ( result && (_DWORD)v4 )
  {
    if ( ptr )
    {
      UFG::qMemMove(result->chars, ptr, v4);
      v6->chars[v4] = 0;
      v6->len = v4;
    }
    return v6;
  }
  return result;
}

// File Line: 513
// RVA: 0x260060
ANTLR3_STRING_struct *__fastcall newPtrUTF16_8(ANTLR3_STRING_FACTORY_struct *factory, char *ptr, unsigned int size)
{
  __int64 v4; // rdi
  ANTLR3_STRING_struct *result; // rax
  char *chars; // rcx
  int i; // edx

  v4 = size;
  result = factory->newSize(factory, size);
  if ( result && (_DWORD)v4 && ptr )
  {
    chars = result->chars;
    for ( i = v4; i > 0; ++ptr )
    {
      --i;
      chars += 2;
      *((_WORD *)chars - 1) = (unsigned __int8)*ptr;
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
  __int64 v4; // rdi
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v6; // rbx

  v4 = size;
  result = factory->newSize(factory, size);
  v6 = result;
  if ( result && (_DWORD)v4 )
  {
    if ( ptr )
    {
      UFG::qMemMove(result->chars, ptr, 2 * v4);
      *(_WORD *)&v6->chars[2 * v4] = 0;
      v6->len = v4;
    }
    return v6;
  }
  return result;
}

// File Line: 596
// RVA: 0x2602D0
ANTLR3_STRING_struct *__fastcall newStrUTF16_8(ANTLR3_STRING_FACTORY_struct *factory, char *ptr)
{
  __int64 v2; // r8

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
  int v2; // r8d
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
  unsigned int index; // ebx

  index = string->index;
  factory->strings->del(factory->strings, index);
  if ( index < --factory->index )
  {
    do
    {
      *((_DWORD *)factory->strings->elements[index].element + 6) = index;
      ++index;
    }
    while ( index < factory->index );
  }
}

// File Line: 681
// RVA: 0x260320
ANTLR3_STRING_struct *__fastcall printable8(ANTLR3_STRING_FACTORY_struct *factory, ANTLR3_STRING_struct *instr)
{
  ANTLR3_STRING_struct *v3; // rax
  __int64 v4; // rdi
  _WORD *chars; // rbx
  ANTLR3_STRING_struct *i; // rbp
  unsigned __int8 v7; // dl

  v3 = factory->newSize(factory, 2 * instr->len + 1);
  v4 = 0i64;
  chars = v3->chars;
  for ( i = v3; (unsigned int)v4 < instr->len; v4 = (unsigned int)(v4 + 1) )
  {
    v7 = instr->chars[v4];
    if ( v7 == 10 )
    {
      *chars++ = 28252;
    }
    else if ( v7 == 13 )
    {
      *chars++ = 29276;
    }
    else
    {
      if ( isprint(v7) )
        *(_BYTE *)chars = instr->chars[v4];
      else
        *(_BYTE *)chars = 63;
      chars = (_WORD *)((char *)chars + 1);
    }
  }
  *(_BYTE *)chars = 0;
  i->len = (_DWORD)chars - LODWORD(i->chars);
  return i;
}

// File Line: 728
// RVA: 0x2603E0
ANTLR3_STRING_struct *__fastcall printableUTF16(ANTLR3_STRING_FACTORY_struct *factory, ANTLR3_STRING_struct *instr)
{
  ANTLR3_STRING_struct *v3; // rax
  char *chars; // r12
  _DWORD *v5; // rbx
  ANTLR3_STRING_struct *v6; // r15
  unsigned int v7; // edi
  unsigned int v8; // esi
  char *v9; // r14
  unsigned __int16 v10; // ax
  ANTLR3_STRING_struct *v12; // [rsp+50h] [rbp+8h]

  v3 = factory->newSize(factory, 2 * instr->len + 1);
  chars = instr->chars;
  v5 = v3->chars;
  v6 = v3;
  v12 = v3;
  v7 = 0;
  v8 = 0;
  if ( instr->len )
  {
    do
    {
      v9 = &chars[2 * v8];
      v10 = *(_WORD *)v9;
      if ( *(_WORD *)v9 == 10 )
      {
        *v5++ = 7209052;
        v7 += 2;
      }
      else if ( v10 == 13 )
      {
        *v5++ = 7471196;
        v7 += 2;
      }
      else
      {
        if ( isprint(v10) )
          *(_WORD *)v5 = *(_WORD *)v9;
        else
          *(_WORD *)v5 = 63;
        v5 = (_DWORD *)((char *)v5 + 2);
        ++v7;
      }
      ++v8;
    }
    while ( v8 < instr->len );
    v6 = v12;
  }
  *(_WORD *)v5 = 0;
  v6->len = v7;
  return v6;
}

// File Line: 786
// RVA: 0x25FB70
void __fastcall closeFactory(ANTLR3_STRING_FACTORY_struct *factory)
{
  factory->strings->free(factory->strings);
  antlrFree((char *)factory);
}

// File Line: 799
// RVA: 0x25F950
char *__fastcall append8(ANTLR3_STRING_struct *string, char *newbit)
{
  __int64 v4; // rbx
  __int64 len; // rcx
  unsigned int v6; // eax
  char *v7; // rax

  v4 = -1i64;
  do
    ++v4;
  while ( newbit[v4] );
  len = string->len;
  v6 = v4 + len + 1;
  if ( string->size < v6 )
  {
    v7 = (char *)antlrRealloc(string->chars, v6);
    len = string->len;
    string->chars = v7;
    string->size = v4 + len + 1;
  }
  UFG::qMemMove(&string->chars[len], newbit, v4 + 1);
  string->len += v4;
  return string->chars;
}

// File Line: 820
// RVA: 0x25FA00
char *__fastcall appendUTF16_8(ANTLR3_STRING_struct *string, const char *newbit)
{
  const char *v2; // rbx
  __int64 v4; // rdi
  __int64 len; // rcx
  unsigned int v6; // r8d
  char *v7; // rax
  char *chars; // rax
  char *v9; // rdx
  __int64 v10; // rcx
  __int16 v11; // ax

  v2 = newbit;
  v4 = -1i64;
  do
    ++v4;
  while ( newbit[v4] );
  len = string->len;
  v6 = len + v4;
  if ( string->size < (unsigned int)(len + v4 + 1) )
  {
    v7 = (char *)antlrRealloc(string->chars, 2 * v6 + 2);
    len = string->len;
    v6 = len + v4;
    string->chars = v7;
    string->size = len + v4 + 1;
  }
  chars = string->chars;
  string->len = v6;
  v9 = &chars[2 * len];
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
  return string->chars;
}

// File Line: 847
// RVA: 0x25FAA0
char *__fastcall appendUTF16_UTF16(ANTLR3_STRING_struct *string, char *newbit)
{
  int v2; // ebx
  char *i; // rax
  __int64 len; // rcx
  char *v7; // rax

  v2 = 0;
  for ( i = newbit; *(_WORD *)i; ++v2 )
    i += 2;
  len = string->len;
  if ( string->size < (unsigned int)(len + v2 + 1) )
  {
    v7 = (char *)antlrRealloc(string->chars, (unsigned int)(2 * (len + v2) + 2));
    len = string->len;
    string->chars = v7;
    string->size = v2 + len + 1;
  }
  UFG::qMemMove(&string->chars[2 * len], newbit, 2 * v2 + 2);
  string->len += v2;
  return string->chars;
}

// File Line: 877
// RVA: 0x2604D0
char *__fastcall set8(ANTLR3_STRING_struct *string, char *chars)
{
  __int64 v4; // rbx
  unsigned int v5; // ebp
  char *v6; // rax
  char *result; // rax

  v4 = -1i64;
  do
    ++v4;
  while ( chars[v4] );
  v5 = v4 + 1;
  if ( string->size < (unsigned int)(v4 + 1) )
  {
    v6 = (char *)antlrRealloc(string->chars, v5);
    string->size = v5;
    string->chars = v6;
  }
  UFG::qMemMove(string->chars, chars, v5);
  result = string->chars;
  string->len = v4;
  return result;
}

// File Line: 898
// RVA: 0x260550
char *__fastcall setUTF16_8(ANTLR3_STRING_struct *string, const char *chars)
{
  __int64 v4; // rbx
  char *v5; // rax
  char *v6; // r8
  unsigned int i; // edx
  __int64 v8; // rax

  v4 = -1i64;
  do
    ++v4;
  while ( chars[v4] );
  if ( string->size < (unsigned int)(v4 + 1) )
  {
    v5 = (char *)antlrRealloc(string->chars, (unsigned int)(2 * v4 + 2));
    string->size = v4 + 1;
    string->chars = v5;
  }
  v6 = string->chars;
  string->len = v4;
  for ( i = 0; i < string->len; *((_WORD *)v6 - 1) = chars[v8] )
  {
    v8 = i++;
    v6 += 2;
  }
  *(_WORD *)v6 = 0;
  return string->chars;
}

// File Line: 923
// RVA: 0x2605F0
char *__fastcall setUTF16_UTF16(ANTLR3_STRING_struct *string, char *chars)
{
  unsigned int v2; // ebx
  char *i; // rax
  char *v6; // rax
  char *result; // rax

  v2 = 0;
  for ( i = chars; *(_WORD *)i; ++v2 )
    i += 2;
  if ( string->size < v2 + 1 )
  {
    v6 = (char *)antlrRealloc(string->chars, 2 * v2 + 2);
    string->size = v2 + 1;
    string->chars = v6;
  }
  UFG::qMemMove(string->chars, chars, 2 * v2 + 2);
  result = string->chars;
  string->len = v2;
  return result;
}

// File Line: 954
// RVA: 0x25F860
char *__fastcall addc8(ANTLR3_STRING_struct *string, char c)
{
  __int64 len; // rcx
  char *v5; // rax

  len = string->len;
  if ( string->size < (unsigned int)(len + 2) )
  {
    v5 = (char *)antlrRealloc(string->chars, (unsigned int)(len + 2));
    len = string->len;
    string->chars = v5;
    string->size = len + 2;
  }
  string->chars[len] = c;
  string->chars[++string->len] = 0;
  return string->chars;
}

// File Line: 969
// RVA: 0x25F8C0
char *__fastcall addcUTF16(ANTLR3_STRING_struct *string, __int16 c)
{
  unsigned int len; // r8d
  char *v5; // rax
  char *chars; // rcx

  len = string->len;
  if ( string->size < len + 2 )
  {
    v5 = (char *)antlrRealloc(string->chars, 2 * (len + 2));
    len = string->len;
    string->chars = v5;
    string->size = len + 2;
  }
  chars = string->chars;
  *(_WORD *)&chars[2 * len] = c;
  *(_WORD *)&chars[2 * string->len++ + 2] = 0;
  return string->chars;
}

// File Line: 988
// RVA: 0x25F920
char *__fastcall addiUTF16(ANTLR3_STRING_struct *string, unsigned int i)
{
  char stringa[40]; // [rsp+20h] [rbp-28h] BYREF

  sprintf(stringa, "%d", i);
  return string->append8(string, stringa);
}

// File Line: 1007
// RVA: 0x25FFB0
char *__fastcall insertiUTF16(ANTLR3_STRING_struct *string, unsigned int point, __int64 i)
{
  char stringa[40]; // [rsp+20h] [rbp-28h] BYREF

  sprintf(stringa, "%d", i);
  return string->insert8(string, point, stringa);
}

// File Line: 1024
// RVA: 0x25FCD0
char *__fastcall insert8(ANTLR3_STRING_struct *string, unsigned int point, char *newbit)
{
  unsigned int len; // r8d
  __int64 v5; // r14
  __int64 v8; // rbx
  unsigned int v9; // eax
  char *v10; // rax

  len = string->len;
  v5 = point;
  if ( point >= len )
    return string->append(string, newbit);
  v8 = -1i64;
  do
    ++v8;
  while ( newbit[v8] );
  if ( !(_DWORD)v8 )
    return string->chars;
  v9 = v8 + len + 1;
  if ( string->size < v9 )
  {
    v10 = (char *)antlrRealloc(string->chars, v9);
    len = string->len;
    string->chars = v10;
    string->size = v8 + len + 1;
  }
  UFG::qMemMove(&string->chars[v5 + (unsigned int)v8], &string->chars[v5], len - v5 + 1);
  UFG::qMemMove(&string->chars[v5], newbit, v8);
  string->len += v8;
  return string->chars;
}

// File Line: 1060
// RVA: 0x25FDB0
char *__fastcall insertUTF16_8(ANTLR3_STRING_struct *string, unsigned int point, const char *newbit)
{
  unsigned int len; // r8d
  __int64 v5; // r15
  __int64 v8; // rsi
  char *v9; // rax
  __int64 v10; // r14
  char *chars; // rcx
  char *v12; // rcx
  __int16 v13; // ax

  len = string->len;
  v5 = point;
  if ( point >= len )
    return string->append8(string, newbit);
  v8 = -1i64;
  do
    ++v8;
  while ( newbit[v8] );
  if ( !(_DWORD)v8 )
    return string->chars;
  if ( string->size < len + (unsigned int)v8 + 1 )
  {
    v9 = (char *)antlrRealloc(string->chars, 2 * (len + (unsigned int)v8) + 2);
    len = string->len;
    string->chars = v9;
    string->size = v8 + len + 1;
  }
  v10 = (unsigned int)v8;
  UFG::qMemMove(&string->chars[2 * (unsigned int)v8 + 2 * v5], &string->chars[2 * v5], 2 * (len - v5) + 2);
  chars = string->chars;
  string->len += v8;
  v12 = &chars[2 * v5];
  do
  {
    v13 = *newbit;
    v12 += 2;
    ++newbit;
    *((_WORD *)v12 - 1) = v13;
    --v10;
  }
  while ( v10 );
  return string->chars;
}

// File Line: 1100
// RVA: 0x25FEB0
char *__fastcall insertUTF16_UTF16(ANTLR3_STRING_struct *string, unsigned int point, char *newbit)
{
  unsigned int len; // r8d
  __int64 v5; // r14
  unsigned int v8; // edi
  char *v9; // rax
  char *v10; // rax

  len = string->len;
  v5 = point;
  if ( point >= len )
    return string->append(string, newbit);
  v8 = 0;
  v9 = newbit;
  if ( !*(_WORD *)newbit )
    return string->chars;
  do
  {
    v9 += 2;
    ++v8;
  }
  while ( *(_WORD *)v9 );
  if ( !v8 )
    return string->chars;
  if ( string->size < len + v8 + 1 )
  {
    v10 = (char *)antlrRealloc(string->chars, 2 * (len + v8) + 2);
    len = string->len;
    string->chars = v10;
    string->size = v8 + len + 1;
  }
  UFG::qMemMove(&string->chars[2 * v5 + 2 * v8], &string->chars[2 * v5], 2 * (len - v5) + 2);
  UFG::qMemMove(&string->chars[2 * v5], newbit, 2 * v8);
  string->len += v8;
  return string->chars;
}

// File Line: 1145
// RVA: 0x260540
char *__fastcall setS(ANTLR3_STRING_struct *string, ANTLR3_STRING_struct *chars)
{
  return string->set(string, chars->chars);
}

// File Line: 1150
// RVA: 0x25F9D0
char *__fastcall appendS(ANTLR3_STRING_struct *string, ANTLR3_STRING_struct *newbit)
{
  if ( newbit && newbit->len && newbit->size && newbit->chars )
    return (char *)((__int64 (*)(void))string->append)();
  else
    return string->chars;
}

// File Line: 1164
// RVA: 0x25FDA0
char *__fastcall insertS(ANTLR3_STRING_struct *string, __int64 point, ANTLR3_STRING_struct *newbit)
{
  return string->insert(string, point, newbit->chars);
}

// File Line: 1173
// RVA: 0x25FBA0
__int64 __fastcall compare8(ANTLR3_STRING_struct *string, const char *compStr)
{
  char *chars; // rax
  const char *v3; // rdx
  unsigned __int8 v4; // cl

  chars = string->chars;
  v3 = (const char *)(compStr - chars);
  while ( 1 )
  {
    v4 = *chars;
    if ( *chars != v3[(_QWORD)chars] )
      break;
    ++chars;
    if ( !v4 )
      return 0i64;
  }
  return v4 < (unsigned int)v3[(_QWORD)chars] ? -1 : 1;
}

// File Line: 1183
// RVA: 0x25FBD0
__int64 __fastcall compareUTF16_8(ANTLR3_STRING_struct *string, char *compStr)
{
  char *chars; // rax
  unsigned __int16 i; // r8
  char v4; // cl

  chars = string->chars;
  for ( i = *(_WORD *)chars; i; ++compStr )
  {
    v4 = *compStr;
    if ( !*compStr )
      break;
    if ( i != v4 )
      return (unsigned int)i - v4;
    i = *((_WORD *)chars + 1);
    chars += 2;
  }
  return (unsigned int)*(unsigned __int16 *)chars - *compStr;
}

// File Line: 1212
// RVA: 0x25FC20
__int64 __fastcall compareUTF16_UTF16(ANTLR3_STRING_struct *string, const char *compStr8)
{
  char *chars; // rax
  unsigned __int16 i; // r8
  unsigned __int16 v4; // cx

  chars = string->chars;
  for ( i = *(_WORD *)chars; i; compStr8 += 2 )
  {
    v4 = *(_WORD *)compStr8;
    if ( !*(_WORD *)compStr8 )
      break;
    if ( i != v4 )
      return i - (unsigned int)v4;
    i = *((_WORD *)chars + 1);
    chars += 2;
  }
  return *(unsigned __int16 *)chars - (unsigned int)*(unsigned __int16 *)compStr8;
}

// File Line: 1242
// RVA: 0x25FBC0
__int64 __fastcall compareS(ANTLR3_STRING_struct *string, ANTLR3_STRING_struct *compStr)
{
  return ((__int64 (__fastcall *)(ANTLR3_STRING_struct *, char *))string->compare)(string, compStr->chars);
}

// File Line: 1252
// RVA: 0x25FB30
__int64 __fastcall charAt8(ANTLR3_STRING_struct *string, unsigned int offset)
{
  if ( offset <= string->len )
    return (unsigned __int8)string->chars[offset];
  else
    return 0i64;
}

// File Line: 1268
// RVA: 0x25FB50
__int64 __fastcall charAtUTF16(ANTLR3_STRING_struct *string, unsigned int offset)
{
  if ( offset <= string->len )
    return *(unsigned __int16 *)&string->chars[2 * offset];
  else
    return 0i64;
}

// File Line: 1284
// RVA: 0x2608A0
ANTLR3_STRING_struct *__fastcall subString8(
        ANTLR3_STRING_struct *string,
        unsigned int startIndex,
        unsigned int endIndex)
{
  unsigned int len; // eax

  len = string->len;
  if ( endIndex > len )
    endIndex = len + 1;
  return string->factory->newPtr(string->factory, &string->chars[startIndex], endIndex - startIndex);
}

// File Line: 1301
// RVA: 0x2608C0
ANTLR3_STRING_struct *__fastcall subStringUTF16(
        ANTLR3_STRING_struct *string,
        unsigned int startIndex,
        unsigned int endIndex)
{
  unsigned int len; // eax

  len = string->len;
  if ( endIndex > len )
    endIndex = len + 1;
  return string->factory->newPtr(string->factory, &string->chars[2 * startIndex], endIndex - startIndex);
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
  char *chars; // rbx
  unsigned int v2; // edi
  char v3; // si
  unsigned __int16 i; // ax
  int v5; // eax

  chars = string->chars;
  v2 = 0;
  v3 = 0;
  if ( *(_WORD *)chars == 45 )
  {
    v3 = 1;
  }
  else if ( *(_WORD *)chars != 43 )
  {
    goto LABEL_5;
  }
  chars += 2;
LABEL_5:
  for ( i = *(_WORD *)chars; *(_WORD *)chars; i = *(_WORD *)chars )
  {
    if ( !isdigit(i) )
      break;
    v5 = *(unsigned __int16 *)chars;
    chars += 2;
    v2 = v5 + 2 * (5 * v2 - 24);
  }
  if ( v3 )
    return -v2;
  return v2;
}

// File Line: 1369
// RVA: 0x2608F0
ANTLR3_STRING_struct *__fastcall to8_UTF16(ANTLR3_STRING_struct *string)
{
  ANTLR3_STRING_struct *result; // rax
  ANTLR3_STRING_struct *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  __int64 v5; // r9
  char v6; // dl

  result = newRaw8(string->factory);
  v3 = result;
  if ( result )
  {
    v4 = antlrMalloc(string->len + 1);
    v5 = 0i64;
    v3->chars = (char *)v4;
    v3->size = string->len + 1;
    for ( v3->len = string->len; (unsigned int)v5 < string->len; v5 = (unsigned int)(v5 + 1) )
    {
      v6 = *(_WORD *)&string->chars[2 * v5];
      if ( *(unsigned __int16 *)&string->chars[2 * v5] > 0xFFu )
        v6 = 95;
      v3->chars[v5] = v6;
    }
    v3->chars[v3->len] = 0;
    return v3;
  }
  return result;
}

