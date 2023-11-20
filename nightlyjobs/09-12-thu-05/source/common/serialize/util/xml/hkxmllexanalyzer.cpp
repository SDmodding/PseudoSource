// File Line: 33
// RVA: 0xE6BB40
void __fastcall hkXmlLexAnalyzer::hkXmlLexAnalyzer(hkXmlLexAnalyzer *this, hkStreamReader *reader)
{
  hkXmlLexAnalyzer *v2; // rbx

  v2 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkXmlLexAnalyzer::`vftable';
  hkParserBuffer::hkParserBuffer(&this->m_buffer, reader);
  v2->m_state = 0;
}

// File Line: 37
// RVA: 0xE6BBC0
hkXmlLexAnalyzer::Token __fastcall hkXmlLexAnalyzer::_lexComment(hkXmlLexAnalyzer *this)
{
  hkXmlLexAnalyzer *v1; // rsi
  __int64 v2; // rdi
  char *v3; // rdx
  char v4; // cl
  int v6; // [rsp+30h] [rbp+8h]

  v1 = this;
  v6 = 4074797;
LABEL_2:
  v2 = 0i64;
  while ( 1 )
  {
    v3 = v1->m_buffer.m_pos;
    if ( v3 >= &v1->m_buffer.m_buffer.m_data[(signed __int64)v1->m_buffer.m_buffer.m_size] )
    {
      hkParserBuffer::read(&v1->m_buffer, 256);
      v3 = v1->m_buffer.m_pos;
      if ( v3 >= &v1->m_buffer.m_buffer.m_data[(signed __int64)v1->m_buffer.m_buffer.m_size] )
        break;
    }
    v4 = *v3;
    v1->m_buffer.m_pos = v3 + 1;
    if ( !v4 )
      break;
    if ( *((_BYTE *)&v6 + v2) != v4 )
      goto LABEL_2;
    if ( ++v2 == 3 )
      return 4;
  }
  return hkXmlLexAnalyzer::_handleError(v1, "Badly formed comment");
}

// File Line: 64
// RVA: 0xE6C0F0
hkXmlLexAnalyzer::Token __fastcall hkXmlLexAnalyzer::_lexQuotedString(hkXmlLexAnalyzer *this)
{
  hkXmlLexAnalyzer *v1; // rsi
  char v2; // bl
  char *v3; // rdx
  char v4; // cl

  v1 = this;
LABEL_2:
  v2 = 0;
  while ( 1 )
  {
    v3 = v1->m_buffer.m_pos;
    if ( v3 >= &v1->m_buffer.m_buffer.m_data[(signed __int64)v1->m_buffer.m_buffer.m_size] )
    {
      hkParserBuffer::read(&v1->m_buffer, 256);
      v3 = v1->m_buffer.m_pos;
      if ( v3 >= &v1->m_buffer.m_buffer.m_data[(signed __int64)v1->m_buffer.m_buffer.m_size] )
        break;
    }
    v4 = *v3;
    v1->m_buffer.m_pos = v3 + 1;
    if ( !v4 )
      break;
    if ( v2 )
      goto LABEL_2;
    if ( v4 == 92 )
    {
      v2 = 1;
    }
    else if ( v4 == 34 )
    {
      return 10;
    }
  }
  return hkXmlLexAnalyzer::_handleError(v1, "Didn't hit terminating \"");
}

// File Line: 96
// RVA: 0xE6C1B0
signed __int64 __fastcall hkXmlLexAnalyzer::_lexIdentifier(hkXmlLexAnalyzer *this)
{
  hkParserBuffer *v1; // rbx
  char *v2; // rdx
  char v3; // cl

  v1 = &this->m_buffer;
  while ( 1 )
  {
    v2 = v1->m_pos;
    v3 = *v2;
    if ( !*v2 )
    {
      hkParserBuffer::read(v1, 256);
      v2 = v1->m_pos;
      v3 = *v2;
    }
    if ( (unsigned __int8)(v3 - 97) > 0x19u
      && (unsigned __int8)(v3 - 65) > 0x19u
      && (unsigned __int8)(v3 - 48) > 9u
      && v3 != 95
      && v3 != 58 )
    {
      break;
    }
    if ( v2 >= &v1->m_buffer.m_data[(signed __int64)v1->m_buffer.m_size] )
    {
      hkParserBuffer::read(v1, 256);
      if ( v1->m_pos >= &v1->m_buffer.m_data[v1->m_buffer.m_size] )
        continue;
    }
    ++v1->m_pos;
  }
  return 8i64;
}

// File Line: 112
// RVA: 0xE6C240
signed __int64 __fastcall hkXmlLexAnalyzer::_lexWhiteSpace(hkXmlLexAnalyzer *this)
{
  hkParserBuffer *v1; // rbx
  signed __int64 v2; // rdi
  char *v3; // rcx
  unsigned __int64 v4; // rax

  v1 = &this->m_buffer;
  v2 = 4294977024i64;
  while ( 1 )
  {
    v3 = v1->m_pos;
    v4 = (unsigned __int8)*v3;
    if ( !(_BYTE)v4 )
    {
      hkParserBuffer::read(v1, 256);
      v3 = v1->m_pos;
      v4 = (unsigned __int8)*v3;
    }
    if ( (unsigned __int8)v4 > 0x20u || !_bittest64(&v2, v4) )
      break;
    if ( v3 >= &v1->m_buffer.m_data[(signed __int64)v1->m_buffer.m_size] )
    {
      hkParserBuffer::read(v1, 256);
      if ( v1->m_pos >= &v1->m_buffer.m_data[v1->m_buffer.m_size] )
        continue;
    }
    ++v1->m_pos;
  }
  return 3i64;
}

// File Line: 128
// RVA: 0xE6BEE0
signed __int64 __fastcall hkXmlLexAnalyzer::_lexText(hkXmlLexAnalyzer *this)
{
  hkParserBuffer *v1; // rbx
  char *v2; // rax
  char *v3; // rcx
  signed __int64 v4; // rdi
  char *v5; // rcx
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rcx

  v1 = &this->m_buffer;
  v2 = &this->m_buffer.m_buffer.m_data[this->m_buffer.m_lexemeStart];
  v3 = this->m_buffer.m_pos;
  if ( v3 > v2 )
    v1->m_pos = v3 - 1;
  v4 = 4294977024i64;
  while ( 1 )
  {
    v5 = v1->m_pos;
    if ( v5 >= &v1->m_buffer.m_data[(signed __int64)v1->m_buffer.m_size] )
    {
      hkParserBuffer::read(v1, 256);
      v5 = v1->m_pos;
      if ( v5 >= &v1->m_buffer.m_data[(signed __int64)v1->m_buffer.m_size] )
        break;
    }
    v6 = (unsigned __int8)*v5;
    v7 = (unsigned __int64)(v5 + 1);
    v1->m_pos = (char *)v7;
    if ( !(_BYTE)v6 )
      break;
    if ( (_BYTE)v6 == 60 || (unsigned __int8)v6 <= 0x20u && _bittest64(&v4, v6) )
    {
      if ( (char *)v7 > &v1->m_buffer.m_data[(signed __int64)v1->m_lexemeStart] )
        v1->m_pos = (char *)(v7 - 1);
      return 2i64;
    }
  }
  return 2i64;
}

// File Line: 159
// RVA: 0xE6BC70
hkXmlLexAnalyzer::Token __fastcall hkXmlLexAnalyzer::_matchInBrackets(hkXmlLexAnalyzer *this)
{
  hkXmlLexAnalyzer *v1; // rdi
  char *v2; // rdx
  char v3; // r8
  char v4; // cl
  unsigned __int64 v5; // rcx
  hkXmlLexAnalyzer::Token result; // eax
  int v7; // eax

  v1 = this;
  while ( 2 )
  {
    v2 = v1->m_buffer.m_pos;
    if ( v2 < &v1->m_buffer.m_buffer.m_data[(signed __int64)v1->m_buffer.m_buffer.m_size]
      || (hkParserBuffer::read(&v1->m_buffer, 256),
          v2 = v1->m_buffer.m_pos,
          v2 < &v1->m_buffer.m_buffer.m_data[(signed __int64)v1->m_buffer.m_buffer.m_size]) )
    {
      v3 = *v2;
      v1->m_buffer.m_pos = v2 + 1;
    }
    else
    {
      v3 = 0;
    }
    switch ( v3 )
    {
      case 0:
        return 5;
      case 9:
      case 10:
      case 13:
      case 32:
        hkXmlLexAnalyzer::_lexWhiteSpace(v1);
        hkParserBuffer::lexemeCommit(&v1->m_buffer);
        continue;
      case 34:
        return hkXmlLexAnalyzer::_lexQuotedString(v1);
      case 47:
        return 11;
      case 61:
        return 9;
      case 62:
        v7 = v1->m_state;
        if ( v7 & 2 )
          return hkXmlLexAnalyzer::_handleError(v1, "Expecting ?> to close <? section");
        v1->m_state = v7 & 0xFFFFFFFE;
        return 6;
      case 63:
        if ( !(v1->m_state & 2) )
          continue;
        if ( v1->m_buffer.m_pos >= &v1->m_buffer.m_buffer.m_data[v1->m_buffer.m_buffer.m_size]
          && (hkParserBuffer::read(&v1->m_buffer, 256),
              v1->m_buffer.m_pos >= &v1->m_buffer.m_buffer.m_data[v1->m_buffer.m_buffer.m_size])
          || (v4 = *v1->m_buffer.m_pos, ++v1->m_buffer.m_pos, v4 != 62) )
        {
          v5 = (unsigned __int64)v1->m_buffer.m_pos;
          if ( (char *)v5 > &v1->m_buffer.m_buffer.m_data[(signed __int64)v1->m_buffer.m_lexemeStart] )
            v1->m_buffer.m_pos = (char *)(v5 - 1);
          continue;
        }
        v1->m_state &= 0xFFFFFFFC;
        return 7;
      default:
        if ( (unsigned __int8)(v3 - 97) <= 0x19u || (unsigned __int8)(v3 - 65) <= 0x19u || v3 == 95 || v3 == 58 )
          result = hkXmlLexAnalyzer::_lexIdentifier(v1);
        else
          result = hkXmlLexAnalyzer::_handleError(v1, "Unexpected token");
        return result;
    }
  }
}

// File Line: 231
// RVA: 0xE6BF90
unsigned int __fastcall hkXmlLexAnalyzer::_matchOutsideBrackets(hkXmlLexAnalyzer *this)
{
  hkXmlLexAnalyzer *v1; // rdi
  char *v2; // rcx
  unsigned __int64 v3; // rax
  char *v4; // rcx
  signed __int64 v5; // rcx
  unsigned int v6; // eax
  char v7; // al
  unsigned __int64 v8; // rcx
  hkBool result; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = this->m_buffer.m_pos;
  if ( v2 >= &v1->m_buffer.m_buffer.m_data[(signed __int64)v1->m_buffer.m_buffer.m_size] )
  {
    hkParserBuffer::read(&v1->m_buffer, 256);
    v2 = v1->m_buffer.m_pos;
    if ( v2 >= &v1->m_buffer.m_buffer.m_data[(signed __int64)v1->m_buffer.m_buffer.m_size] )
      return 5;
  }
  v3 = (unsigned __int8)*v2;
  v4 = v2 + 1;
  v1->m_buffer.m_pos = v4;
  if ( !(_BYTE)v3 )
    return 5;
  if ( (_BYTE)v3 == 60 )
  {
    v7 = *v4;
    if ( !*v4 )
    {
      hkParserBuffer::read(&v1->m_buffer, 256);
      v7 = *v1->m_buffer.m_pos;
    }
    if ( v7 == 63 )
    {
      v8 = (unsigned __int64)v1->m_buffer.m_pos;
      if ( (char *)v8 < &v1->m_buffer.m_buffer.m_data[(signed __int64)v1->m_buffer.m_buffer.m_size]
        || (hkParserBuffer::read(&v1->m_buffer, 256),
            v8 = (unsigned __int64)v1->m_buffer.m_pos,
            (char *)v8 < &v1->m_buffer.m_buffer.m_data[(signed __int64)v1->m_buffer.m_buffer.m_size]) )
      {
        v1->m_buffer.m_pos = (char *)(v8 + 1);
      }
      v1->m_state |= 3u;
      v6 = 1;
    }
    else if ( hkParserBuffer::matchAndConsume(&v1->m_buffer, &result, "!--")->m_bool )
    {
      v6 = hkXmlLexAnalyzer::_lexComment(v1);
    }
    else
    {
      v1->m_state |= 1u;
      v6 = 0;
    }
  }
  else if ( (unsigned __int8)v3 <= 0x20u && (v5 = 4294977024i64, _bittest64(&v5, v3)) )
  {
    v6 = hkXmlLexAnalyzer::_lexWhiteSpace(v1);
  }
  else
  {
    v6 = hkXmlLexAnalyzer::_lexText(v1);
  }
  return v6;
}

// File Line: 272
// RVA: 0xE6C1A0
signed __int64 __fastcall hkXmlLexAnalyzer::_handleError(hkXmlLexAnalyzer *this, const char *desc)
{
  return 12i64;
}

// File Line: 278
// RVA: 0xE6BB80
hkXmlLexAnalyzer::Token __fastcall hkXmlLexAnalyzer::advance(hkXmlLexAnalyzer *this)
{
  hkXmlLexAnalyzer *v1; // rbx
  hkXmlLexAnalyzer::Token result; // eax

  v1 = this;
  hkParserBuffer::lexemeCommit(&this->m_buffer);
  if ( v1->m_state & 1 )
    result = hkXmlLexAnalyzer::_matchInBrackets(v1);
  else
    result = hkXmlLexAnalyzer::_matchOutsideBrackets(v1);
  return result;
}

