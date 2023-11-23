// File Line: 33
// RVA: 0xE6BB40
void __fastcall hkXmlLexAnalyzer::hkXmlLexAnalyzer(hkXmlLexAnalyzer *this, hkStreamReader *reader)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkXmlLexAnalyzer::`vftable;
  hkParserBuffer::hkParserBuffer(&this->m_buffer, reader);
  this->m_state = 0;
}

// File Line: 37
// RVA: 0xE6BBC0
hkXmlLexAnalyzer::Token __fastcall hkXmlLexAnalyzer::_lexComment(hkXmlLexAnalyzer *this)
{
  __int64 v2; // rdi
  char *m_pos; // rdx
  char v4; // cl
  int v6; // [rsp+30h] [rbp+8h]

  v6 = 4074797;
LABEL_2:
  v2 = 0i64;
  while ( 1 )
  {
    m_pos = this->m_buffer.m_pos;
    if ( m_pos >= &this->m_buffer.m_buffer.m_data[this->m_buffer.m_buffer.m_size] )
    {
      hkParserBuffer::read(&this->m_buffer, 256);
      m_pos = this->m_buffer.m_pos;
      if ( m_pos >= &this->m_buffer.m_buffer.m_data[this->m_buffer.m_buffer.m_size] )
        break;
    }
    v4 = *m_pos;
    this->m_buffer.m_pos = m_pos + 1;
    if ( !v4 )
      break;
    if ( *((_BYTE *)&v6 + v2) != v4 )
      goto LABEL_2;
    if ( ++v2 == 3 )
      return 4;
  }
  return hkXmlLexAnalyzer::_handleError(this, "Badly formed comment");
}

// File Line: 64
// RVA: 0xE6C0F0
hkXmlLexAnalyzer::Token __fastcall hkXmlLexAnalyzer::_lexQuotedString(hkXmlLexAnalyzer *this)
{
  char v2; // bl
  char *m_pos; // rdx
  char v4; // cl

LABEL_1:
  v2 = 0;
  while ( 1 )
  {
    m_pos = this->m_buffer.m_pos;
    if ( m_pos >= &this->m_buffer.m_buffer.m_data[this->m_buffer.m_buffer.m_size] )
    {
      hkParserBuffer::read(&this->m_buffer, 256);
      m_pos = this->m_buffer.m_pos;
      if ( m_pos >= &this->m_buffer.m_buffer.m_data[this->m_buffer.m_buffer.m_size] )
        break;
    }
    v4 = *m_pos;
    this->m_buffer.m_pos = m_pos + 1;
    if ( !v4 )
      break;
    if ( v2 )
      goto LABEL_1;
    if ( v4 == 92 )
    {
      v2 = 1;
    }
    else if ( v4 == 34 )
    {
      return 10;
    }
  }
  return hkXmlLexAnalyzer::_handleError(this, "Didnt hit terminating \"");
}

// File Line: 96
// RVA: 0xE6C1B0
__int64 __fastcall hkXmlLexAnalyzer::_lexIdentifier(hkXmlLexAnalyzer *this)
{
  hkParserBuffer *p_m_buffer; // rbx
  char *m_pos; // rdx
  char v3; // cl

  p_m_buffer = &this->m_buffer;
  while ( 1 )
  {
    m_pos = p_m_buffer->m_pos;
    v3 = *m_pos;
    if ( !*m_pos )
    {
      hkParserBuffer::read(p_m_buffer, 256);
      m_pos = p_m_buffer->m_pos;
      v3 = *m_pos;
    }
    if ( (unsigned __int8)(v3 - 97) > 0x19u
      && (unsigned __int8)(v3 - 65) > 0x19u
      && (unsigned __int8)(v3 - 48) > 9u
      && v3 != 95
      && v3 != 58 )
    {
      break;
    }
    if ( m_pos >= &p_m_buffer->m_buffer.m_data[p_m_buffer->m_buffer.m_size] )
    {
      hkParserBuffer::read(p_m_buffer, 256);
      if ( p_m_buffer->m_pos >= &p_m_buffer->m_buffer.m_data[p_m_buffer->m_buffer.m_size] )
        continue;
    }
    ++p_m_buffer->m_pos;
  }
  return 8i64;
}

// File Line: 112
// RVA: 0xE6C240
__int64 __fastcall hkXmlLexAnalyzer::_lexWhiteSpace(hkXmlLexAnalyzer *this)
{
  hkParserBuffer *p_m_buffer; // rbx
  __int64 v2; // rdi
  char *m_pos; // rcx
  unsigned __int64 v4; // rax

  p_m_buffer = &this->m_buffer;
  v2 = 0x100002600i64;
  while ( 1 )
  {
    m_pos = p_m_buffer->m_pos;
    v4 = (unsigned __int8)*m_pos;
    if ( !(_BYTE)v4 )
    {
      hkParserBuffer::read(p_m_buffer, 256);
      m_pos = p_m_buffer->m_pos;
      v4 = (unsigned __int8)*m_pos;
    }
    if ( (unsigned __int8)v4 > 0x20u || !_bittest64(&v2, v4) )
      break;
    if ( m_pos >= &p_m_buffer->m_buffer.m_data[p_m_buffer->m_buffer.m_size] )
    {
      hkParserBuffer::read(p_m_buffer, 256);
      if ( p_m_buffer->m_pos >= &p_m_buffer->m_buffer.m_data[p_m_buffer->m_buffer.m_size] )
        continue;
    }
    ++p_m_buffer->m_pos;
  }
  return 3i64;
}

// File Line: 128
// RVA: 0xE6BEE0
__int64 __fastcall hkXmlLexAnalyzer::_lexText(hkXmlLexAnalyzer *this)
{
  hkParserBuffer *p_m_buffer; // rbx
  char *v2; // rax
  char *m_pos; // rcx
  __int64 v4; // rdi
  char *v5; // rcx
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // rcx

  p_m_buffer = &this->m_buffer;
  v2 = &this->m_buffer.m_buffer.m_data[this->m_buffer.m_lexemeStart];
  m_pos = this->m_buffer.m_pos;
  if ( m_pos > v2 )
    p_m_buffer->m_pos = m_pos - 1;
  v4 = 0x100002600i64;
  while ( 1 )
  {
    v5 = p_m_buffer->m_pos;
    if ( v5 >= &p_m_buffer->m_buffer.m_data[p_m_buffer->m_buffer.m_size] )
    {
      hkParserBuffer::read(p_m_buffer, 256);
      v5 = p_m_buffer->m_pos;
      if ( v5 >= &p_m_buffer->m_buffer.m_data[p_m_buffer->m_buffer.m_size] )
        break;
    }
    v6 = (unsigned __int8)*v5;
    v7 = (unsigned __int64)(v5 + 1);
    p_m_buffer->m_pos = (char *)v7;
    if ( !(_BYTE)v6 )
      break;
    if ( (_BYTE)v6 == 60 || (unsigned __int8)v6 <= 0x20u && _bittest64(&v4, v6) )
    {
      if ( (char *)v7 > &p_m_buffer->m_buffer.m_data[p_m_buffer->m_lexemeStart] )
        p_m_buffer->m_pos = (char *)(v7 - 1);
      return 2i64;
    }
  }
  return 2i64;
}

// File Line: 159
// RVA: 0xE6BC70
hkXmlLexAnalyzer::Token __fastcall hkXmlLexAnalyzer::_matchInBrackets(hkXmlLexAnalyzer *this)
{
  char *m_pos; // rdx
  char v3; // r8
  char v4; // cl
  char *v5; // rcx
  int m_state; // eax

  while ( 2 )
  {
    m_pos = this->m_buffer.m_pos;
    if ( m_pos < &this->m_buffer.m_buffer.m_data[this->m_buffer.m_buffer.m_size]
      || (hkParserBuffer::read(&this->m_buffer, 256),
          m_pos = this->m_buffer.m_pos,
          m_pos < &this->m_buffer.m_buffer.m_data[this->m_buffer.m_buffer.m_size]) )
    {
      v3 = *m_pos;
      this->m_buffer.m_pos = m_pos + 1;
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
        hkXmlLexAnalyzer::_lexWhiteSpace(this);
        hkParserBuffer::lexemeCommit(&this->m_buffer);
        continue;
      case 34:
        return hkXmlLexAnalyzer::_lexQuotedString(this);
      case 47:
        return 11;
      case 61:
        return 9;
      case 62:
        m_state = this->m_state;
        if ( (m_state & 2) != 0 )
          return hkXmlLexAnalyzer::_handleError(this, "Expecting ?> to close <? section");
        this->m_state = m_state & 0xFFFFFFFE;
        return 6;
      case 63:
        if ( (this->m_state & 2) == 0 )
          continue;
        if ( this->m_buffer.m_pos >= &this->m_buffer.m_buffer.m_data[this->m_buffer.m_buffer.m_size]
          && (hkParserBuffer::read(&this->m_buffer, 256),
              this->m_buffer.m_pos >= &this->m_buffer.m_buffer.m_data[this->m_buffer.m_buffer.m_size])
          || (v4 = *this->m_buffer.m_pos, ++this->m_buffer.m_pos, v4 != 62) )
        {
          v5 = this->m_buffer.m_pos;
          if ( v5 > &this->m_buffer.m_buffer.m_data[this->m_buffer.m_lexemeStart] )
            this->m_buffer.m_pos = v5 - 1;
          continue;
        }
        this->m_state &= 0xFFFFFFFC;
        return 7;
      default:
        if ( (unsigned __int8)(v3 - 97) <= 0x19u || (unsigned __int8)(v3 - 65) <= 0x19u || v3 == 95 || v3 == 58 )
          return hkXmlLexAnalyzer::_lexIdentifier(this);
        else
          return hkXmlLexAnalyzer::_handleError(this, "Unexpected token");
    }
  }
}

// File Line: 231
// RVA: 0xE6BF90
unsigned int __fastcall hkXmlLexAnalyzer::_matchOutsideBrackets(hkXmlLexAnalyzer *this)
{
  char *m_pos; // rcx
  unsigned __int64 v3; // rax
  char *v4; // rcx
  __int64 v5; // rcx
  char v7; // al
  char *v8; // rcx
  hkBool result; // [rsp+30h] [rbp+8h] BYREF

  m_pos = this->m_buffer.m_pos;
  if ( m_pos >= &this->m_buffer.m_buffer.m_data[this->m_buffer.m_buffer.m_size] )
  {
    hkParserBuffer::read(&this->m_buffer, 256);
    m_pos = this->m_buffer.m_pos;
    if ( m_pos >= &this->m_buffer.m_buffer.m_data[this->m_buffer.m_buffer.m_size] )
      return 5;
  }
  v3 = (unsigned __int8)*m_pos;
  v4 = m_pos + 1;
  this->m_buffer.m_pos = v4;
  if ( !(_BYTE)v3 )
    return 5;
  if ( (_BYTE)v3 == 60 )
  {
    v7 = *v4;
    if ( !*v4 )
    {
      hkParserBuffer::read(&this->m_buffer, 256);
      v7 = *this->m_buffer.m_pos;
    }
    if ( v7 == 63 )
    {
      v8 = this->m_buffer.m_pos;
      if ( v8 < &this->m_buffer.m_buffer.m_data[this->m_buffer.m_buffer.m_size]
        || (hkParserBuffer::read(&this->m_buffer, 256),
            v8 = this->m_buffer.m_pos,
            v8 < &this->m_buffer.m_buffer.m_data[this->m_buffer.m_buffer.m_size]) )
      {
        this->m_buffer.m_pos = v8 + 1;
      }
      this->m_state |= 3u;
      return 1;
    }
    else if ( hkParserBuffer::matchAndConsume(&this->m_buffer, &result, "!--")->m_bool )
    {
      return hkXmlLexAnalyzer::_lexComment(this);
    }
    else
    {
      this->m_state |= 1u;
      return 0;
    }
  }
  else if ( (unsigned __int8)v3 <= 0x20u && (v5 = 0x100002600i64, _bittest64(&v5, v3)) )
  {
    return hkXmlLexAnalyzer::_lexWhiteSpace(this);
  }
  else
  {
    return hkXmlLexAnalyzer::_lexText(this);
  }
}

// File Line: 272
// RVA: 0xE6C1A0
__int64 __fastcall hkXmlLexAnalyzer::_handleError(hkXmlLexAnalyzer *this, const char *desc)
{
  return 12i64;
}

// File Line: 278
// RVA: 0xE6BB80
hkXmlLexAnalyzer::Token __fastcall hkXmlLexAnalyzer::advance(hkXmlLexAnalyzer *this)
{
  hkParserBuffer::lexemeCommit(&this->m_buffer);
  if ( (this->m_state & 1) != 0 )
    return hkXmlLexAnalyzer::_matchInBrackets(this);
  else
    return hkXmlLexAnalyzer::_matchOutsideBrackets(this);
}

