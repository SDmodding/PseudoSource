// File Line: 15
// RVA: 0xE65BA0
void __fastcall hkXmlStreamParser::hkXmlStreamParser(hkXmlStreamParser *this, hkStreamReader *reader)
{
  hkStreamReader *v2; // rbx
  hkXmlStreamParser *v3; // rdi

  v2 = reader;
  v3 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkXmlStreamParser::`vftable';
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_attribMap.m_map,
    0);
  v3->m_keys.m_capacityAndFlags = 2147483648;
  v3->m_keys.m_data = 0i64;
  v3->m_keys.m_size = 0;
  v3->m_keyStorage.m_data = 0i64;
  v3->m_keyStorage.m_size = 0;
  v3->m_keyStorage.m_capacityAndFlags = 2147483648;
  hkXmlLexAnalyzer::hkXmlLexAnalyzer(&v3->m_lex, v2);
  v3->m_lexemes.m_data = 0i64;
  v3->m_lexemes.m_size = 0;
  v3->m_lexemes.m_capacityAndFlags = 2147483648;
  v3->m_token = 6;
}

// File Line: 20
// RVA: 0xE66710
signed __int64 __fastcall hkXmlStreamParser::_parseBlock(hkXmlStreamParser *this)
{
  hkXmlStreamParser *v1; // rdi
  hkXmlLexAnalyzer::Token v2; // eax
  signed __int64 result; // rax
  hkXmlLexAnalyzer::Token v4; // eax
  unsigned int v5; // ecx
  hkXmlLexAnalyzer::Token v6; // eax
  hkXmlLexAnalyzer::Token v7; // ebx
  unsigned int v8; // ecx

  v1 = this;
  v2 = hkXmlLexAnalyzer::advance(&this->m_lex);
  if ( v2 == 11 )
  {
    if ( hkXmlLexAnalyzer::advance(&v1->m_lex) != 8 )
      return 6i64;
    hkXmlStreamParser::_pushLexeme(v1);
    v4 = hkXmlLexAnalyzer::advance(&v1->m_lex);
    v5 = 6;
    if ( v4 == 6 )
      v5 = 3;
    result = v5;
  }
  else
  {
    if ( v2 != 8 )
      return 6i64;
    hkXmlStreamParser::_pushLexeme(v1);
    v6 = hkXmlLexAnalyzer::advance(&v1->m_lex);
    if ( v6 == 6 )
    {
LABEL_13:
      hkXmlStreamParser::_extractAttributes(v1);
      result = 1i64;
    }
    else
    {
      while ( v6 == 8 )
      {
        hkXmlStreamParser::_pushLexeme(v1);
        if ( hkXmlLexAnalyzer::advance(&v1->m_lex) != 9 || hkXmlLexAnalyzer::advance(&v1->m_lex) != 10 )
          return 6i64;
        hkXmlStreamParser::_pushLexeme(v1);
        v6 = hkXmlLexAnalyzer::advance(&v1->m_lex);
        if ( v6 == 6 )
          goto LABEL_13;
      }
      if ( v6 != 11 )
        return 6i64;
      v7 = hkXmlLexAnalyzer::advance(&v1->m_lex);
      hkXmlStreamParser::_extractAttributes(v1);
      v8 = 6;
      if ( v7 == 6 )
        v8 = 2;
      result = v8;
    }
  }
  return result;
}

// File Line: 96
// RVA: 0xE66830
signed __int64 __fastcall hkXmlStreamParser::_parseQBlock(hkXmlStreamParser *this)
{
  hkXmlStreamParser *v1; // rbx
  __int32 v3; // eax

  v1 = this;
  if ( hkXmlLexAnalyzer::advance(&this->m_lex) != 8 )
    return 6i64;
  while ( 1 )
  {
    hkXmlStreamParser::_pushLexeme(v1);
    v3 = hkXmlLexAnalyzer::advance(&v1->m_lex) - 7;
    if ( !v3 )
      break;
    if ( v3 != 1 )
      return 6i64;
    hkXmlStreamParser::_pushLexeme(v1);
    if ( hkXmlLexAnalyzer::advance(&v1->m_lex) != 9 )
      return 6i64;
    if ( hkXmlLexAnalyzer::advance(&v1->m_lex) != 10 )
      return 6i64;
  }
  hkXmlStreamParser::_extractAttributes(v1);
  return 0i64;
}

// File Line: 144
// RVA: 0xE666A0
void __fastcall hkXmlStreamParser::_pushLexeme(hkXmlStreamParser *this)
{
  signed int *v1; // rbx
  hkXmlStreamParser *v2; // rdi
  __int64 v3; // rdx
  _DWORD *v4; // r8

  v1 = (signed int *)&this->m_lexemes;
  v2 = this;
  if ( this->m_lexemes.m_size == (this->m_lexemes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v1, 8);
  v3 = v1[2];
  v4 = (_DWORD *)(*(_QWORD *)v1 + 8 * v3);
  v1[2] = v3 + 1;
  *v4 = v2->m_lex.m_buffer.m_lexemeStart - v2->m_lex.m_buffer.m_bufferStart;
  v4[1] = LODWORD(v2->m_lex.m_buffer.m_pos)
        - LODWORD(v2->m_lex.m_buffer.m_buffer.m_data)
        - v2->m_lex.m_buffer.m_bufferStart;
}

// File Line: 151
// RVA: 0xE668D0
void __fastcall hkXmlStreamParser::_extractAttributes(hkXmlStreamParser *this)
{
  hkXmlStreamParser *v1; // rdi
  signed int v2; // ecx
  int v3; // ebx
  signed __int64 v4; // rax
  __int64 v5; // rdx
  int v6; // ecx
  signed int v7; // ebp
  int v8; // eax
  int v9; // eax
  int v10; // er9
  char *v11; // rsi
  signed __int64 v12; // r15
  hkXmlStreamParser::SubString *v13; // rax
  __int64 v14; // rcx
  int v15; // er14
  hkResult result; // [rsp+60h] [rbp+8h]

  v1 = this;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&this->m_attribMap.m_map);
  v2 = v1->m_lexemes.m_size;
  v3 = 0;
  v1->m_keys.m_size = 0;
  if ( v2 > 1 )
  {
    v4 = (signed __int64)&v1->m_lexemes.m_data[1];
    v5 = ((unsigned int)(v2 - 2) >> 1) + 1;
    do
    {
      v6 = *(_DWORD *)(v4 + 4);
      v4 += 16i64;
      v3 += v6 - *(_DWORD *)(v4 - 16) + 1;
      --v5;
    }
    while ( v5 );
  }
  v7 = 1;
  v8 = v1->m_keyStorage.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v3 )
  {
    v9 = 2 * v8;
    v10 = v3;
    if ( v3 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->m_keyStorage,
      v10,
      1);
  }
  v1->m_keyStorage.m_size = v3;
  v11 = v1->m_keyStorage.m_data;
  if ( v1->m_lexemes.m_size > 1 )
  {
    v12 = 1i64;
    do
    {
      v13 = v1->m_lexemes.m_data;
      v14 = v13[v12].m_start;
      v15 = v13[v12].m_end - v14;
      hkString::strNcpy(v11, &v1->m_lex.m_buffer.m_buffer.m_data[v14 + v1->m_lex.m_buffer.m_bufferStart], v15);
      v11[v15] = 0;
      if ( v1->m_keys.m_size == (v1->m_keys.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v1->m_keys, 8);
      v1->m_keys.m_data[v1->m_keys.m_size++] = v11;
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(
        &v1->m_attribMap.m_map,
        (unsigned __int64)v11,
        v7 + 1);
      v7 += 2;
      v12 += 2i64;
      v11 += v15 + 1;
    }
    while ( v7 < v1->m_lexemes.m_size );
  }
}

// File Line: 185
// RVA: 0xE66A30
signed __int64 __fastcall hkXmlStreamParser::_advance(hkXmlStreamParser *this)
{
  hkXmlStreamParser *v1; // rbx
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator> *v2; // rcx
  hkXmlLexAnalyzer::Token v3; // eax
  signed __int64 result; // rax

  v1 = this;
  v2 = &this->m_attribMap.m_map;
  v2[1].m_numElems = 0;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(v2);
  hkParserBuffer::bufferCommit(&v1->m_lex.m_buffer);
  v1->m_lexemes.m_size = 0;
  v3 = hkXmlLexAnalyzer::advance(&v1->m_lex);
  while ( 2 )
  {
    switch ( v3 )
    {
      case 0:
        result = hkXmlStreamParser::_parseBlock(v1);
        break;
      case 1:
        result = hkXmlStreamParser::_parseQBlock(v1);
        break;
      case 2:
        result = 4i64;
        break;
      case 3:
        result = 5i64;
        break;
      case 4:
        v3 = hkXmlLexAnalyzer::advance(&v1->m_lex);
        if ( (unsigned int)v3 <= 5 )
          continue;
        goto LABEL_4;
      case 5:
        result = 7i64;
        break;
      default:
LABEL_4:
        result = 6i64;
        break;
    }
    return result;
  }
}

// File Line: 231
// RVA: 0xE65B80
hkXmlStreamParser::Token __fastcall hkXmlStreamParser::advance(hkXmlStreamParser *this)
{
  hkXmlStreamParser *v1; // rbx
  hkXmlStreamParser::Token result; // eax

  v1 = this;
  result = hkXmlStreamParser::_advance(this);
  v1->m_token = result;
  return result;
}

// File Line: 236
// RVA: 0xE65C90
hkResult *__fastcall hkXmlStreamParser::getValue(hkXmlStreamParser *this, hkResult *result, const char *key, hkSubString *valueOut)
{
  hkResult *v4; // rbx
  hkXmlStreamParser *v5; // rdi
  hkSubString *v6; // rsi
  int v7; // eax
  hkResult *v8; // rax
  char *v9; // rdx
  hkXmlStreamParser::SubString *v10; // r8
  const char *v11; // rcx

  v4 = result;
  v5 = this;
  v6 = valueOut;
  v7 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_attribMap,
         (unsigned __int64)key,
         0xFFFFFFFFFFFFFFFFui64);
  if ( v7 >= 0 )
  {
    v9 = &v5->m_lex.m_buffer.m_buffer.m_data[v5->m_lex.m_buffer.m_bufferStart];
    v10 = &v5->m_lexemes.m_data[v7];
    v4->m_enum = 0;
    v11 = &v9[v10->m_start];
    v6->m_end = &v9[v10->m_end];
    v8 = v4;
    v6->m_start = v11;
  }
  else
  {
    v4->m_enum = 1;
    v8 = v4;
  }
  return v8;
}

// File Line: 250
// RVA: 0xE65C40
hkSubString *__fastcall hkXmlStreamParser::getBlockName(hkXmlStreamParser *this, hkSubString *result)
{
  hkXmlStreamParser::SubString *v2; // r9
  char *v3; // r8

  if ( this->m_lexemes.m_size <= 0 )
  {
    result->m_start = 0i64;
    result->m_end = 0i64;
  }
  else
  {
    v2 = this->m_lexemes.m_data;
    v3 = &this->m_lex.m_buffer.m_buffer.m_data[this->m_lex.m_buffer.m_bufferStart];
    result->m_start = &v3[v2->m_start];
    result->m_end = &v3[v2->m_end];
  }
  return result;
}

// File Line: 263
// RVA: 0xE65EA0
hkSubString *__fastcall hkXmlStreamParser::getLexeme(hkXmlStreamParser *this, hkSubString *result)
{
  result->m_start = &this->m_lex.m_buffer.m_buffer.m_data[this->m_lex.m_buffer.m_lexemeStart];
  result->m_end = this->m_lex.m_buffer.m_pos;
  return result;
}

// File Line: 269
// RVA: 0xE66B40
void __fastcall dumpAttributes(hkXmlStreamParser *parser, hkOstream *stream)
{
  hkOstream *v2; // rbp
  hkXmlStreamParser *v3; // rdi
  hkSubString *v4; // rax
  int v5; // er14
  __int64 v6; // rsi
  const char *v7; // rbx
  hkOstream *v8; // rax
  hkOstream *v9; // rax
  hkSubString result; // [rsp+20h] [rbp-28h]
  hkResult v11; // [rsp+50h] [rbp+8h]

  v2 = stream;
  v3 = parser;
  v4 = hkXmlStreamParser::getBlockName(parser, &result);
  operator<<(v2, v4);
  v5 = 0;
  if ( v3->m_keys.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = v3->m_keys.m_data[v6];
      v8 = hkOstream::operator<<(v2, " ");
      v9 = hkOstream::operator<<(v8, v7);
      hkOstream::operator<<(v9, "=");
      result.m_start = 0i64;
      result.m_end = 0i64;
      hkXmlStreamParser::getValue(v3, &v11, v7, &result);
      operator<<(v2, &result);
      ++v5;
      ++v6;
    }
    while ( v5 < v3->m_keys.m_size );
  }
}

// File Line: 286
// RVA: 0xE65EC0
void __fastcall hkXmlStreamParser::dumpParse(hkXmlStreamParser *this, hkOstream *out)
{
  hkOstream *v2; // rdi
  hkXmlStreamParser *v3; // rsi
  hkXmlStreamParser::Token v4; // ebx
  hkSubString *v5; // rbx
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  hkSubString *v8; // rax
  hkSubString result; // [rsp+20h] [rbp-28h]
  hkSubString v10; // [rsp+30h] [rbp-18h]

  v2 = out;
  v3 = this;
  while ( 1 )
  {
    v4 = hkXmlStreamParser::advance(v3);
    switch ( v4 )
    {
      case 0:
        hkOstream::operator<<(v2, "<?");
        dumpAttributes(v3, v2);
        hkOstream::operator<<(v2, "?>\n");
        break;
      case 1:
      case 2:
        hkOstream::operator<<(v2, "<");
        dumpAttributes(v3, v2);
        if ( v4 == 2 )
          hkOstream::operator<<(v2, "/");
        hkOstream::operator<<(v2, ">\n");
        break;
      case 3:
        v5 = hkXmlStreamParser::getBlockName(v3, &result);
        v6 = hkOstream::operator<<(v2, "</");
        v7 = operator<<(v6, v5);
        hkOstream::operator<<(v7, ">\n");
        break;
      case 4:
      case 5:
        v8 = hkXmlStreamParser::getLexeme(v3, &v10);
        operator<<(v2, v8);
        break;
      case 6:
      case 7:
        return;
      default:
        continue;
    }
  }
}

// File Line: 333
// RVA: 0xE663F0
hkResult *__fastcall hkXmlStreamParser::parseInt(hkResult *result, hkSubString *subString, __int64 *valueOut)
{
  __int64 *v3; // r14
  hkResult *v4; // rbx
  const char *v6; // rsi
  const char *v7; // rdi
  const char *v8; // rax
  const char *v9; // rax
  __int64 v10; // rax
  char dst[40]; // [rsp+20h] [rbp-28h]

  v3 = valueOut;
  v4 = result;
  if ( LODWORD(subString->m_end) - LODWORD(subString->m_start) <= 0 )
  {
    result->m_enum = 1;
    return result;
  }
  v6 = subString->m_start;
  v7 = subString->m_end;
  v8 = subString->m_start;
  if ( *subString->m_start == 45 )
    v8 = v6 + 1;
  if ( v8 < v7 )
  {
    if ( (unsigned __int8)(*v8 - 48) <= 9u )
    {
      v9 = v8 + 1;
      if ( v9 >= v7 )
      {
LABEL_12:
        hkString::strNcpy(dst, subString->m_start, (_DWORD)v7 - (_DWORD)v6);
        dst[v7 - v6] = 0;
        v10 = hkString::atoll(dst, 0);
        v4->m_enum = 0;
        *v3 = v10;
        return v4;
      }
      while ( (unsigned __int8)(*v9 - 48) <= 9u )
      {
        if ( ++v9 >= v7 )
          goto LABEL_12;
      }
    }
    result->m_enum = 1;
  }
  else
  {
    result->m_enum = 1;
  }
  return v4;
}

// File Line: 378
// RVA: 0xE662C0
hkResult *__fastcall hkXmlStreamParser::parseInt(hkResult *result, hkSubString *subString, int *signOut, unsigned __int64 *magOut)
{
  unsigned __int64 *v4; // r14
  hkResult *v5; // rdi
  const char *v7; // rbx
  const char *v8; // rsi
  const char *v9; // rax
  const char *v10; // rax
  char v11; // dl
  unsigned __int64 v12; // rax
  char dst[40]; // [rsp+20h] [rbp-28h]

  *signOut = 1;
  v4 = magOut;
  v5 = result;
  if ( LODWORD(subString->m_end) - LODWORD(subString->m_start) <= 0 )
  {
    result->m_enum = 1;
    return result;
  }
  v7 = subString->m_end;
  v8 = subString->m_start;
  v9 = subString->m_start;
  if ( *subString->m_start == 45 )
  {
    ++v8;
    *signOut = -1;
    v9 = v8;
  }
  if ( v9 < v7 )
  {
    if ( v7 - v9 <= 2 || *v9 != 48 || (v9[1] - 88) & 0xDF )
    {
      while ( (unsigned __int8)(*v9 - 48) <= 9u )
      {
        if ( ++v9 >= v7 )
          goto LABEL_18;
      }
    }
    else
    {
      v10 = v9 + 2;
      if ( v10 >= v7 )
      {
LABEL_18:
        hkString::strNcpy(dst, v8, (_DWORD)v7 - (_DWORD)v8);
        dst[v7 - v8] = 0;
        v12 = hkString::atoull(dst, 0);
        v5->m_enum = 0;
        *v4 = v12;
        return v5;
      }
      while ( 1 )
      {
        v11 = *v10;
        if ( (unsigned __int8)(*v10 - 48) > 9u && (unsigned __int8)(v11 - 65) > 5u && (unsigned __int8)(v11 - 97) > 5u )
          break;
        if ( ++v10 >= v7 )
          goto LABEL_18;
      }
    }
    result->m_enum = 1;
    return v5;
  }
  result->m_enum = 1;
  return v5;
}

// File Line: 438
// RVA: 0xE65D30
hkResult *__fastcall hkXmlStreamParser::getIntAttribute(hkXmlStreamParser *this, hkResult *result, const char *key, int *value)
{
  int *v4; // rdi
  hkResult *v5; // rbx
  hkResult *v6; // rax
  hkResult resulta; // [rsp+20h] [rbp-28h]
  __int64 v8; // [rsp+28h] [rbp-20h]
  hkSubString valueOut; // [rsp+30h] [rbp-18h]

  v4 = value;
  v5 = result;
  valueOut.m_start = 0i64;
  valueOut.m_end = 0i64;
  if ( hkXmlStreamParser::getValue(this, &resulta, key, &valueOut)->m_enum
    || *valueOut.m_start != 34
    || *((_BYTE *)valueOut.m_end - 1) != 34 )
  {
    v5->m_enum = 1;
    v6 = v5;
  }
  else
  {
    ++valueOut.m_start;
    --valueOut.m_end;
    v8 = 0i64;
    hkXmlStreamParser::parseInt(&resulta, &valueOut, &v8);
    *v4 = v8;
    v5->m_enum = resulta.m_enum;
    v6 = v5;
  }
  return v6;
}

// File Line: 459
// RVA: 0xE65E70
hkBool *__fastcall hkXmlStreamParser::hasAttribute(hkXmlStreamParser *this, hkBool *result, const char *key)
{
  hkBool *v3; // rbx
  hkSubString valueOut; // [rsp+20h] [rbp-18h]
  hkResult resulta; // [rsp+48h] [rbp+10h]

  v3 = result;
  result->m_bool = hkXmlStreamParser::getValue(this, &resulta, key, &valueOut)->m_enum == 0;
  return v3;
}

// File Line: 465
// RVA: 0xE664D0
hkResult *__fastcall hkXmlStreamParser::parseReal(hkResult *result, hkSubString *subString, float *valueOut)
{
  float *v3; // r9
  hkResult *v4; // rbx
  int v5; // er10
  const char *v6; // r11
  double v7; // rcx
  hkResult *v8; // rax
  signed __int64 v9; // r8
  char v10; // dl
  signed __int64 v11; // rcx
  int v12; // eax
  double v13; // [rsp+38h] [rbp+10h]

  v3 = valueOut;
  v4 = result;
  v5 = LODWORD(subString->m_end) - LODWORD(subString->m_start);
  if ( (unsigned int)(v5 - 1) > 0x1F )
  {
    result->m_enum = 1;
    v8 = result;
  }
  else
  {
    v6 = subString->m_start;
    if ( *subString->m_start == 120 )
    {
      v7 = 0.0;
      v13 = 0.0;
      if ( (v5 - 9) & 0xFFFFFFF7 )
      {
        v4->m_enum = 1;
        return v4;
      }
      v9 = 0i64;
      if ( v5 - 1 > 0 )
      {
        do
        {
          v10 = v6[v9 + 1];
          v11 = 16i64 * *(_QWORD *)&v7;
          if ( (unsigned __int8)(v10 - 48) > 9u )
          {
            if ( (unsigned __int8)(v10 - 65) > 5u )
            {
              if ( (unsigned __int8)(v10 - 97) > 5u )
              {
                v4->m_enum = 1;
                return v4;
              }
              v12 = v10 - 87;
            }
            else
            {
              v12 = v10 - 55;
            }
          }
          else
          {
            v12 = v10 - 48;
          }
          ++v9;
          *(_QWORD *)&v7 = v12 | (unsigned __int64)v11;
          v13 = v7;
        }
        while ( v9 < v5 - 1 );
      }
      if ( v5 == 9 )
      {
        v8 = v4;
        *v3 = *(float *)&v13;
        v4->m_enum = 0;
        return v8;
      }
      if ( v5 == 17 )
      {
        if ( v13 == 1.797e308 )
        {
          *v3 = 3.40282e38;
          v8 = v4;
          v4->m_enum = 0;
          return v8;
        }
        if ( v13 == 2.225073858507201e-308 )
        {
          *v3 = 1.1754944e-38;
          v8 = v4;
          v4->m_enum = 0;
          return v8;
        }
        if ( v13 == 2.220446049250313e-16 )
        {
          *v3 = 0.00000011920929;
          v8 = v4;
          v4->m_enum = 0;
          return v8;
        }
        if ( v13 == 1.8446726e150 )
        {
          *v3 = 1.8446726e19;
          v8 = v4;
          v4->m_enum = 0;
          return v8;
        }
        *v3 = v13;
      }
      v4->m_enum = 0;
      v8 = v4;
    }
    else
    {
      hkFloatParseUtil::parseFloat(result, subString, valueOut);
      v8 = v4;
    }
  }
  return v8;
}

// File Line: 547
// RVA: 0xE65DE0
hkResult *__fastcall hkXmlStreamParser::getRealAttribute(hkXmlStreamParser *this, hkResult *result, const char *key, float *value)
{
  float *v4; // rdi
  hkResult *v5; // rbx
  hkResult *v6; // rax
  hkResult resulta; // [rsp+20h] [rbp-28h]
  hkSubString valueOut; // [rsp+28h] [rbp-20h]

  v4 = value;
  v5 = result;
  valueOut.m_start = 0i64;
  valueOut.m_end = 0i64;
  if ( hkXmlStreamParser::getValue(this, &resulta, key, &valueOut)->m_enum
    || *valueOut.m_start != 34
    || *((_BYTE *)valueOut.m_end - 1) != 34 )
  {
    v5->m_enum = 1;
    v6 = v5;
  }
  else
  {
    ++valueOut.m_start;
    --valueOut.m_end;
    hkXmlStreamParser::parseReal(v5, &valueOut, v4);
    v6 = v5;
  }
  return v6;
}

// File Line: 565
// RVA: 0xE66010
hkBool *__fastcall hkXmlStreamParser::needsDecode(hkBool *result, hkSubString *subString)
{
  const char *v2; // rax
  const char *v3; // r8
  hkBool *v4; // rax

  v2 = subString->m_start;
  v3 = subString->m_end;
  if ( subString->m_start >= v3 )
  {
LABEL_4:
    result->m_bool = 0;
    v4 = result;
  }
  else
  {
    while ( *v2 != 38 )
    {
      if ( ++v2 >= v3 )
        goto LABEL_4;
    }
    result->m_bool = 1;
    v4 = result;
  }
  return v4;
}

// File Line: 580
// RVA: 0xE66050
hkResult *__fastcall hkXmlStreamParser::decodeString(hkResult *result, hkSubString *subString, hkStringBuf *buf)
{
  hkResult *v3; // r15
  hkStringBuf *v4; // r14
  unsigned __int64 *v5; // rbx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // rsi
  signed int v8; // ebx
  const char *v9; // rdx
  _BYTE *v10; // rbx
  unsigned int v11; // eax
  _BYTE *v12; // rbx
  char v14[2]; // [rsp+1Eh] [rbp-2Ah]
  char dst; // [rsp+20h] [rbp-28h]
  char v16; // [rsp+21h] [rbp-27h]

  v3 = result;
  v4 = buf;
  v5 = (unsigned __int64 *)subString;
  hkStringBuf::clear(buf);
  v6 = *v5;
  v7 = v5[1];
  if ( *v5 >= v7 )
  {
LABEL_32:
    v3->m_enum = 0;
    return v3;
  }
  while ( 1 )
  {
    if ( *(_BYTE *)v6 != 38 )
    {
      v12 = (_BYTE *)(v6 + 1);
      if ( v6 + 1 < v7 )
      {
        do
        {
          if ( *v12 == 38 )
            break;
          ++v12;
        }
        while ( (unsigned __int64)v12 < v7 );
      }
      hkStringBuf::append(v4, (const char *)v6, (_DWORD)v12 - v6);
      v6 = (unsigned __int64)v12;
      goto LABEL_31;
    }
    v8 = v7 - v6;
    if ( (signed int)v7 - (signed int)v6 < 5 || hkString::strNcmp((const char *)(v6 + 1), "amp;", 4) )
      break;
    hkStringBuf::append(v4, "&", 1);
    v6 += 5i64;
LABEL_31:
    if ( v6 >= v7 )
      goto LABEL_32;
  }
  if ( v8 < 4 )
    goto LABEL_11;
  if ( !hkString::strNcmp((const char *)(v6 + 1), "lt;", 3) )
  {
    hkStringBuf::append(v4, "<", 1);
    v6 += 4i64;
    goto LABEL_31;
  }
  if ( !hkString::strNcmp((const char *)(v6 + 1), "gt;", 3) )
  {
    hkStringBuf::append(v4, ">", 1);
    v6 += 4i64;
    goto LABEL_31;
  }
LABEL_11:
  if ( v8 < 6 )
    goto LABEL_16;
  if ( !hkString::strNcmp((const char *)(v6 + 1), "quot;", 5) )
  {
    hkStringBuf::append(v4, "\"", 1);
    v6 += 6i64;
    goto LABEL_31;
  }
  if ( !hkString::strNcmp((const char *)(v6 + 1), "apos;", 5) )
  {
    hkStringBuf::append(v4, "'", 1);
    v6 += 6i64;
    goto LABEL_31;
  }
LABEL_16:
  if ( *(_BYTE *)(v6 + 1) == 35 )
  {
    v9 = (const char *)(v6 + 2);
    if ( (unsigned __int8)(*(_BYTE *)(v6 + 2) - 48) <= 9u && v8 >= 4 )
    {
      v10 = (_BYTE *)(v6 + 2);
      if ( (unsigned __int64)v9 < v7 )
      {
        while ( (unsigned __int8)(*v10 - 48) <= 9u )
        {
          if ( (unsigned __int64)++v10 >= v7 )
            goto LABEL_22;
        }
        if ( *v10 == 59 && (signed int)v10 - (signed int)v6 <= 16 )
        {
          hkString::strNcpy(&dst, v9, (_DWORD)v10 - v6 - 2);
          v14[(_QWORD)&v10[-v6]] = 0;
          v11 = hkString::atoi(&dst, 0);
          if ( v11 <= 0xFF )
          {
            dst = v11;
            v16 = 0;
            hkStringBuf::append(v4, &dst, -1);
            v6 = (unsigned __int64)(v10 + 1);
            goto LABEL_31;
          }
        }
      }
    }
  }
LABEL_22:
  v3->m_enum = 1;
  return v3;
}

