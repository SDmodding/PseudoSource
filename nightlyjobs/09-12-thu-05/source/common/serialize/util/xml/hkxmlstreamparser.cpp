// File Line: 15
// RVA: 0xE65BA0
void __fastcall hkXmlStreamParser::hkXmlStreamParser(hkXmlStreamParser *this, hkStreamReader *reader)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkXmlStreamParser::`vftable;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>(
    &this->m_attribMap.m_map,
    0);
  this->m_keys.m_capacityAndFlags = 0x80000000;
  this->m_keys.m_data = 0i64;
  this->m_keys.m_size = 0;
  this->m_keyStorage.m_data = 0i64;
  this->m_keyStorage.m_size = 0;
  this->m_keyStorage.m_capacityAndFlags = 0x80000000;
  hkXmlLexAnalyzer::hkXmlLexAnalyzer(&this->m_lex, reader);
  this->m_lexemes.m_data = 0i64;
  this->m_lexemes.m_size = 0;
  this->m_lexemes.m_capacityAndFlags = 0x80000000;
  this->m_token = TOKEN_ERROR;
}

// File Line: 20
// RVA: 0xE66710
__int64 __fastcall hkXmlStreamParser::_parseBlock(hkXmlStreamParser *this)
{
  hkXmlLexAnalyzer::Token v2; // eax
  hkXmlLexAnalyzer::Token v4; // eax
  unsigned int v5; // ecx
  hkXmlLexAnalyzer::Token v6; // eax
  hkXmlLexAnalyzer::Token v7; // ebx
  unsigned int v8; // ecx

  v2 = hkXmlLexAnalyzer::advance(&this->m_lex);
  if ( v2 == TOKEN_TERMINATOR )
  {
    if ( hkXmlLexAnalyzer::advance(&this->m_lex) != TOKEN_LT )
      return 6i64;
    hkXmlStreamParser::_pushLexeme(this);
    v4 = hkXmlLexAnalyzer::advance(&this->m_lex);
    v5 = 6;
    if ( v4 == TOKEN_UNSIGNED )
      return 3;
    return v5;
  }
  else
  {
    if ( v2 != TOKEN_LT )
      return 6i64;
    hkXmlStreamParser::_pushLexeme(this);
    v6 = hkXmlLexAnalyzer::advance(&this->m_lex);
    if ( v6 == TOKEN_UNSIGNED )
    {
LABEL_13:
      hkXmlStreamParser::_extractAttributes(this);
      return 1i64;
    }
    else
    {
      while ( v6 == TOKEN_LT )
      {
        hkXmlStreamParser::_pushLexeme(this);
        if ( hkXmlLexAnalyzer::advance(&this->m_lex) != TOKEN_GT
          || hkXmlLexAnalyzer::advance(&this->m_lex) != TOKEN_COMMA )
        {
          return 6i64;
        }
        hkXmlStreamParser::_pushLexeme(this);
        v6 = hkXmlLexAnalyzer::advance(&this->m_lex);
        if ( v6 == TOKEN_UNSIGNED )
          goto LABEL_13;
      }
      if ( v6 != TOKEN_TERMINATOR )
        return 6i64;
      v7 = hkXmlLexAnalyzer::advance(&this->m_lex);
      hkXmlStreamParser::_extractAttributes(this);
      v8 = 6;
      if ( v7 == TOKEN_UNSIGNED )
        return 2;
      return v8;
    }
  }
}

// File Line: 96
// RVA: 0xE66830
__int64 __fastcall hkXmlStreamParser::_parseQBlock(hkXmlStreamParser *this)
{
  __int32 v3; // eax

  if ( hkXmlLexAnalyzer::advance(&this->m_lex) != TOKEN_LT )
    return 6i64;
  while ( 1 )
  {
    hkXmlStreamParser::_pushLexeme(this);
    v3 = hkXmlLexAnalyzer::advance(&this->m_lex) - 7;
    if ( !v3 )
      break;
    if ( v3 != 1 )
      return 6i64;
    hkXmlStreamParser::_pushLexeme(this);
    if ( hkXmlLexAnalyzer::advance(&this->m_lex) != TOKEN_GT )
      return 6i64;
    if ( hkXmlLexAnalyzer::advance(&this->m_lex) != TOKEN_COMMA )
      return 6i64;
  }
  hkXmlStreamParser::_extractAttributes(this);
  return 0i64;
}

// File Line: 144
// RVA: 0xE666A0
void __fastcall hkXmlStreamParser::_pushLexeme(hkXmlStreamParser *this)
{
  hkArray<hkXmlStreamParser::SubString,hkContainerHeapAllocator> *p_m_lexemes; // rbx
  __int64 m_size; // rdx
  hkXmlStreamParser::SubString *v4; // r8

  p_m_lexemes = &this->m_lexemes;
  if ( this->m_lexemes.m_size == (this->m_lexemes.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_lexemes->m_data, 8);
  m_size = p_m_lexemes->m_size;
  v4 = &p_m_lexemes->m_data[m_size];
  p_m_lexemes->m_size = m_size + 1;
  v4->m_start = this->m_lex.m_buffer.m_lexemeStart - this->m_lex.m_buffer.m_bufferStart;
  v4->m_end = LODWORD(this->m_lex.m_buffer.m_pos)
            - LODWORD(this->m_lex.m_buffer.m_buffer.m_data)
            - this->m_lex.m_buffer.m_bufferStart;
}

// File Line: 151
// RVA: 0xE668D0
void __fastcall hkXmlStreamParser::_extractAttributes(hkXmlStreamParser *this)
{
  int m_size; // ecx
  int v3; // ebx
  hkXmlStreamParser::SubString *v4; // rax
  __int64 v5; // rdx
  int m_end; // ecx
  int v7; // ebp
  int v8; // eax
  int v9; // eax
  int v10; // r9d
  char *m_data; // rsi
  __int64 v12; // r15
  hkXmlStreamParser::SubString *v13; // rax
  __int64 m_start; // rcx
  signed int v15; // r14d
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&this->m_attribMap.m_map);
  m_size = this->m_lexemes.m_size;
  v3 = 0;
  this->m_keys.m_size = 0;
  if ( m_size > 1 )
  {
    v4 = this->m_lexemes.m_data + 1;
    v5 = ((unsigned int)(m_size - 2) >> 1) + 1;
    do
    {
      m_end = v4->m_end;
      v4 += 2;
      v3 += m_end - v4[-2].m_start + 1;
      --v5;
    }
    while ( v5 );
  }
  v7 = 1;
  v8 = this->m_keyStorage.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 < v3 )
  {
    v9 = 2 * v8;
    v10 = v3;
    if ( v3 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&this->m_keyStorage.m_data,
      v10,
      1);
  }
  this->m_keyStorage.m_size = v3;
  m_data = this->m_keyStorage.m_data;
  if ( this->m_lexemes.m_size > 1 )
  {
    v12 = 1i64;
    do
    {
      v13 = this->m_lexemes.m_data;
      m_start = v13[v12].m_start;
      v15 = v13[v12].m_end - m_start;
      hkString::strNcpy(
        m_data,
        &this->m_lex.m_buffer.m_buffer.m_data[m_start + this->m_lex.m_buffer.m_bufferStart],
        v15);
      m_data[v15] = 0;
      if ( this->m_keys.m_size == (this->m_keys.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_keys.m_data, 8);
      this->m_keys.m_data[this->m_keys.m_size++] = m_data;
      hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::insert(&this->m_attribMap.m_map, m_data, v7 + 1);
      v7 += 2;
      v12 += 2i64;
      m_data += v15 + 1;
    }
    while ( v7 < this->m_lexemes.m_size );
  }
}

// File Line: 185
// RVA: 0xE66A30
__int64 __fastcall hkXmlStreamParser::_advance(hkXmlStreamParser *this)
{
  hkStringMap<int,hkContainerHeapAllocator> *p_m_attribMap; // rcx
  hkXmlLexAnalyzer::Token v3; // eax
  __int64 result; // rax

  p_m_attribMap = &this->m_attribMap;
  p_m_attribMap[1].m_map.m_numElems = 0;
  hkCachedHashMap<hkStringMapOperations,hkContainerHeapAllocator>::clear(&p_m_attribMap->m_map);
  hkParserBuffer::bufferCommit(&this->m_lex.m_buffer);
  this->m_lexemes.m_size = 0;
  v3 = hkXmlLexAnalyzer::advance(&this->m_lex);
  while ( 2 )
  {
    switch ( v3 )
    {
      case TOKEN_REFERENCE:
        result = hkXmlStreamParser::_parseBlock(this);
        break;
      case TOKEN_POINTER:
        result = hkXmlStreamParser::_parseQBlock(this);
        break;
      case TOKEN_IDENTIFIER:
        result = 4i64;
        break;
      case TOKEN_CLASS:
        result = 5i64;
        break;
      case TOKEN_ENUM:
        v3 = hkXmlLexAnalyzer::advance(&this->m_lex);
        if ( (unsigned int)v3 <= TOKEN_BUILT_IN )
          continue;
        goto LABEL_4;
      case TOKEN_BUILT_IN:
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
  hkXmlStreamParser::Token result; // eax

  result = hkXmlStreamParser::_advance(this);
  this->m_token = result;
  return result;
}

// File Line: 236
// RVA: 0xE65C90
hkResult *__fastcall hkXmlStreamParser::getValue(
        hkXmlStreamParser *this,
        hkResult *result,
        const char *key,
        hkSubString *valueOut)
{
  int v7; // eax
  hkResult *v8; // rax
  char *v9; // rdx
  hkXmlStreamParser::SubString *v10; // r8
  const char *v11; // rcx

  v7 = hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator>::getWithDefault(
         (hkCachedHashMap<hkStringMapOperations,hkDefaultMemoryTrackerAllocator> *)&this->m_attribMap,
         key,
         0xFFFFFFFFFFFFFFFFui64);
  if ( v7 >= 0 )
  {
    v9 = &this->m_lex.m_buffer.m_buffer.m_data[this->m_lex.m_buffer.m_bufferStart];
    v10 = &this->m_lexemes.m_data[v7];
    result->m_enum = HK_SUCCESS;
    v11 = &v9[v10->m_start];
    valueOut->m_end = &v9[v10->m_end];
    v8 = result;
    valueOut->m_start = v11;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  return v8;
}

// File Line: 250
// RVA: 0xE65C40
hkSubString *__fastcall hkXmlStreamParser::getBlockName(hkXmlStreamParser *this, hkSubString *result)
{
  hkXmlStreamParser::SubString *m_data; // r9
  char *v3; // r8

  if ( this->m_lexemes.m_size <= 0 )
  {
    result->m_start = 0i64;
    result->m_end = 0i64;
  }
  else
  {
    m_data = this->m_lexemes.m_data;
    v3 = &this->m_lex.m_buffer.m_buffer.m_data[this->m_lex.m_buffer.m_bufferStart];
    result->m_start = &v3[m_data->m_start];
    result->m_end = &v3[m_data->m_end];
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
  hkSubString *BlockName; // rax
  int v5; // r14d
  __int64 v6; // rsi
  const char *v7; // rbx
  hkOstream *v8; // rax
  hkOstream *v9; // rax
  hkSubString result; // [rsp+20h] [rbp-28h] BYREF
  hkResult v11; // [rsp+50h] [rbp+8h] BYREF

  BlockName = hkXmlStreamParser::getBlockName(parser, &result);
  operator<<(stream, BlockName);
  v5 = 0;
  if ( parser->m_keys.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = parser->m_keys.m_data[v6];
      v8 = hkOstream::operator<<(stream, " ");
      v9 = hkOstream::operator<<(v8, v7);
      hkOstream::operator<<(v9, "=");
      result.m_start = 0i64;
      result.m_end = 0i64;
      hkXmlStreamParser::getValue(parser, &v11, v7, &result);
      operator<<(stream, &result);
      ++v5;
      ++v6;
    }
    while ( v5 < parser->m_keys.m_size );
  }
}

// File Line: 286
// RVA: 0xE65EC0
void __fastcall hkXmlStreamParser::dumpParse(hkXmlStreamParser *this, hkOstream *out)
{
  hkXmlStreamParser::Token v4; // ebx
  hkSubString *BlockName; // rbx
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  hkSubString *Lexeme; // rax
  hkSubString result; // [rsp+20h] [rbp-28h] BYREF
  hkSubString v10; // [rsp+30h] [rbp-18h] BYREF

  while ( 1 )
  {
    v4 = hkXmlStreamParser::advance(this);
    switch ( v4 )
    {
      case TOKEN_QBLOCK:
        hkOstream::operator<<(out, "<?");
        dumpAttributes(this, out);
        hkOstream::operator<<(out, "?>\n");
        break;
      case TOKEN_BLOCK_START:
      case TOKEN_BLOCK_START_END:
        hkOstream::operator<<(out, "<");
        dumpAttributes(this, out);
        if ( v4 == TOKEN_BLOCK_START_END )
          hkOstream::operator<<(out, "/");
        hkOstream::operator<<(out, ">\n");
        break;
      case TOKEN_BLOCK_END:
        BlockName = hkXmlStreamParser::getBlockName(this, &result);
        v6 = hkOstream::operator<<(out, "</");
        v7 = operator<<(v6, BlockName);
        hkOstream::operator<<(v7, ">\n");
        break;
      case TOKEN_TEXT:
      case TOKEN_WHITESPACE:
        Lexeme = hkXmlStreamParser::getLexeme(this, &v10);
        operator<<(out, Lexeme);
        break;
      case TOKEN_ERROR:
      case TOKEN_EOF:
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
  const char *m_start; // rsi
  const char *m_end; // rdi
  const char *v8; // rax
  const char *v9; // rax
  __int64 v10; // rax
  char dst[40]; // [rsp+20h] [rbp-28h] BYREF

  if ( LODWORD(subString->m_end) - LODWORD(subString->m_start) <= 0 )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  m_start = subString->m_start;
  m_end = subString->m_end;
  v8 = subString->m_start;
  if ( *subString->m_start == 45 )
    v8 = m_start + 1;
  if ( v8 < m_end )
  {
    if ( (unsigned __int8)(*v8 - 48) <= 9u )
    {
      v9 = v8 + 1;
      if ( v9 >= m_end )
      {
LABEL_12:
        hkString::strNcpy(dst, subString->m_start, (_DWORD)m_end - (_DWORD)m_start);
        dst[m_end - m_start] = 0;
        v10 = hkString::atoll(dst, 0);
        result->m_enum = HK_SUCCESS;
        *valueOut = v10;
        return result;
      }
      while ( (unsigned __int8)(*v9 - 48) <= 9u )
      {
        if ( ++v9 >= m_end )
          goto LABEL_12;
      }
    }
    result->m_enum = HK_FAILURE;
  }
  else
  {
    result->m_enum = HK_FAILURE;
  }
  return result;
}

// File Line: 378
// RVA: 0xE662C0
hkResult *__fastcall hkXmlStreamParser::parseInt(
        hkResult *result,
        hkSubString *subString,
        int *signOut,
        unsigned __int64 *magOut)
{
  const char *m_end; // rbx
  const char *m_start; // rsi
  const char *v9; // rax
  const char *v10; // rax
  char v11; // dl
  unsigned __int64 v12; // rax
  char dst[40]; // [rsp+20h] [rbp-28h] BYREF

  *signOut = 1;
  if ( LODWORD(subString->m_end) - LODWORD(subString->m_start) <= 0 )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  m_end = subString->m_end;
  m_start = subString->m_start;
  v9 = subString->m_start;
  if ( *subString->m_start == 45 )
  {
    ++m_start;
    *signOut = -1;
    v9 = m_start;
  }
  if ( v9 < m_end )
  {
    if ( m_end - v9 <= 2 || *v9 != 48 || ((v9[1] - 88) & 0xDF) != 0 )
    {
      while ( (unsigned __int8)(*v9 - 48) <= 9u )
      {
        if ( ++v9 >= m_end )
          goto LABEL_18;
      }
    }
    else
    {
      v10 = v9 + 2;
      if ( v10 >= m_end )
      {
LABEL_18:
        hkString::strNcpy(dst, m_start, (_DWORD)m_end - (_DWORD)m_start);
        dst[m_end - m_start] = 0;
        v12 = hkString::atoull(dst, 0);
        result->m_enum = HK_SUCCESS;
        *magOut = v12;
        return result;
      }
      while ( 1 )
      {
        v11 = *v10;
        if ( (unsigned __int8)(*v10 - 48) > 9u && (unsigned __int8)(v11 - 65) > 5u && (unsigned __int8)(v11 - 97) > 5u )
          break;
        if ( ++v10 >= m_end )
          goto LABEL_18;
      }
    }
    result->m_enum = HK_FAILURE;
    return result;
  }
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 438
// RVA: 0xE65D30
hkResult *__fastcall hkXmlStreamParser::getIntAttribute(
        hkXmlStreamParser *this,
        hkResult *result,
        const char *key,
        int *value)
{
  hkResult resulta; // [rsp+20h] [rbp-28h] BYREF
  __int64 v8; // [rsp+28h] [rbp-20h] BYREF
  hkSubString valueOut; // [rsp+30h] [rbp-18h] BYREF

  valueOut.m_start = 0i64;
  valueOut.m_end = 0i64;
  if ( hkXmlStreamParser::getValue(this, &resulta, key, &valueOut)->m_enum == HK_SUCCESS
    && *valueOut.m_start == 34
    && *((_BYTE *)valueOut.m_end - 1) == 34 )
  {
    ++valueOut.m_start;
    --valueOut.m_end;
    v8 = 0i64;
    hkXmlStreamParser::parseInt(&resulta, &valueOut, &v8);
    *value = v8;
    result->m_enum = resulta.m_enum;
    return result;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}

// File Line: 459
// RVA: 0xE65E70
hkBool *__fastcall hkXmlStreamParser::hasAttribute(hkXmlStreamParser *this, hkBool *result, const char *key)
{
  hkSubString valueOut; // [rsp+20h] [rbp-18h] BYREF
  hkResult resulta; // [rsp+48h] [rbp+10h] BYREF

  result->m_bool = hkXmlStreamParser::getValue(this, &resulta, key, &valueOut)->m_enum == HK_SUCCESS;
  return result;
}

// File Line: 465
// RVA: 0xE664D0
hkResult *__fastcall hkXmlStreamParser::parseReal(hkResult *result, hkSubString *subString, float *valueOut)
{
  int v5; // r10d
  const char *m_start; // r11
  double v7; // rcx
  hkResult *v8; // rax
  __int64 i; // r8
  char v10; // dl
  __int64 v11; // rcx
  int v12; // eax
  double v13; // [rsp+38h] [rbp+10h]

  v5 = LODWORD(subString->m_end) - LODWORD(subString->m_start);
  if ( (unsigned int)(v5 - 1) > 0x1F )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    m_start = subString->m_start;
    if ( *subString->m_start == 120 )
    {
      v7 = 0.0;
      v13 = 0.0;
      if ( ((v5 - 9) & 0xFFFFFFF7) != 0 )
      {
        result->m_enum = HK_FAILURE;
        return result;
      }
      for ( i = 0i64; i < v5 - 1; v13 = v7 )
      {
        v10 = m_start[i + 1];
        v11 = 16i64 * *(_QWORD *)&v7;
        if ( (unsigned __int8)(v10 - 48) > 9u )
        {
          if ( (unsigned __int8)(v10 - 65) > 5u )
          {
            if ( (unsigned __int8)(v10 - 97) > 5u )
            {
              result->m_enum = HK_FAILURE;
              return result;
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
        ++i;
        *(_QWORD *)&v7 = v12 | (unsigned __int64)v11;
      }
      if ( v5 == 9 )
      {
        v8 = result;
        *valueOut = *(float *)&v13;
        result->m_enum = HK_SUCCESS;
        return v8;
      }
      if ( v5 == 17 )
      {
        if ( v13 == 1.797e308 )
        {
          *valueOut = 3.40282e38;
          v8 = result;
          result->m_enum = HK_SUCCESS;
          return v8;
        }
        if ( v13 == 2.225073858507201e-308 )
        {
          *valueOut = 1.1754944e-38;
          v8 = result;
          result->m_enum = HK_SUCCESS;
          return v8;
        }
        if ( v13 == 2.220446049250313e-16 )
        {
          *valueOut = 0.00000011920929;
          v8 = result;
          result->m_enum = HK_SUCCESS;
          return v8;
        }
        if ( v13 == 1.8446726e150 )
        {
          *valueOut = 1.8446726e19;
          v8 = result;
          result->m_enum = HK_SUCCESS;
          return v8;
        }
        *valueOut = v13;
      }
      result->m_enum = HK_SUCCESS;
      return result;
    }
    else
    {
      hkFloatParseUtil::parseFloat(result, subString, valueOut);
      return result;
    }
  }
}

// File Line: 547
// RVA: 0xE65DE0
hkResult *__fastcall hkXmlStreamParser::getRealAttribute(
        hkXmlStreamParser *this,
        hkResult *result,
        const char *key,
        float *value)
{
  hkResult resulta; // [rsp+20h] [rbp-28h] BYREF
  hkSubString valueOut; // [rsp+28h] [rbp-20h] BYREF

  valueOut.m_start = 0i64;
  valueOut.m_end = 0i64;
  if ( hkXmlStreamParser::getValue(this, &resulta, key, &valueOut)->m_enum == HK_SUCCESS
    && *valueOut.m_start == 34
    && *((_BYTE *)valueOut.m_end - 1) == 34 )
  {
    ++valueOut.m_start;
    --valueOut.m_end;
    hkXmlStreamParser::parseReal(result, &valueOut, value);
    return result;
  }
  else
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
}

// File Line: 565
// RVA: 0xE66010
hkBool *__fastcall hkXmlStreamParser::needsDecode(hkBool *result, hkSubString *subString)
{
  const char *m_start; // rax
  const char *m_end; // r8

  m_start = subString->m_start;
  m_end = subString->m_end;
  if ( subString->m_start >= m_end )
  {
LABEL_4:
    result->m_bool = 0;
    return result;
  }
  else
  {
    while ( *m_start != 38 )
    {
      if ( ++m_start >= m_end )
        goto LABEL_4;
    }
    result->m_bool = 1;
    return result;
  }
}

// File Line: 580
// RVA: 0xE66050
hkResult *__fastcall hkXmlStreamParser::decodeString(hkResult *result, hkSubString *subString, hkStringBuf *buf)
{
  const char *m_start; // rdi
  const char *m_end; // rsi
  int v8; // ebx
  const char *v9; // rdx
  _BYTE *v10; // rbx
  unsigned int v11; // eax
  const char *i; // rbx
  char v14[2]; // [rsp+1Eh] [rbp-2Ah]
  char dst[40]; // [rsp+20h] [rbp-28h] BYREF

  hkStringBuf::clear(buf);
  m_start = subString->m_start;
  m_end = subString->m_end;
  if ( subString->m_start >= m_end )
  {
LABEL_32:
    result->m_enum = HK_SUCCESS;
    return result;
  }
  while ( 1 )
  {
    if ( *m_start != 38 )
    {
      for ( i = m_start + 1; i < m_end; ++i )
      {
        if ( *i == 38 )
          break;
      }
      hkStringBuf::append(buf, m_start, (_DWORD)i - (_DWORD)m_start);
      m_start = i;
      goto LABEL_31;
    }
    v8 = (_DWORD)m_end - (_DWORD)m_start;
    if ( (int)m_end - (int)m_start < 5 || hkString::strNcmp(m_start + 1, "amp;", 4u) )
      break;
    hkStringBuf::append(buf, "&", 1);
    m_start += 5;
LABEL_31:
    if ( m_start >= m_end )
      goto LABEL_32;
  }
  if ( v8 < 4 )
    goto LABEL_11;
  if ( !hkString::strNcmp(m_start + 1, "lt;", 3u) )
  {
    hkStringBuf::append(buf, "<", 1);
    m_start += 4;
    goto LABEL_31;
  }
  if ( !hkString::strNcmp(m_start + 1, "gt;", 3u) )
  {
    hkStringBuf::append(buf, ">", 1);
    m_start += 4;
    goto LABEL_31;
  }
LABEL_11:
  if ( v8 < 6 )
    goto LABEL_16;
  if ( !hkString::strNcmp(m_start + 1, "quot;", 5u) )
  {
    hkStringBuf::append(buf, "\"", 1);
    m_start += 6;
    goto LABEL_31;
  }
  if ( !hkString::strNcmp(m_start + 1, "apos;", 5u) )
  {
    hkStringBuf::append(buf, "", 1);
    m_start += 6;
    goto LABEL_31;
  }
LABEL_16:
  if ( m_start[1] == 35 )
  {
    v9 = m_start + 2;
    if ( (unsigned __int8)(m_start[2] - 48) <= 9u && v8 >= 4 )
    {
      v10 = m_start + 2;
      if ( v9 < m_end )
      {
        while ( (unsigned __int8)(*v10 - 48) <= 9u )
        {
          if ( ++v10 >= m_end )
            goto LABEL_22;
        }
        if ( *v10 == 59 && (int)v10 - (int)m_start <= 16 )
        {
          hkString::strNcpy(dst, v9, (_DWORD)v10 - (_DWORD)m_start - 2);
          v14[v10 - m_start] = 0;
          v11 = hkString::atoi(dst, 0);
          if ( v11 <= 0xFF )
          {
            dst[0] = v11;
            dst[1] = 0;
            hkStringBuf::append(buf, dst, -1);
            m_start = v10 + 1;
            goto LABEL_31;
          }
        }
      }
    }
  }
LABEL_22:
  result->m_enum = HK_FAILURE;
  return result;
}

