// File Line: 23
// RVA: 0xEE22CC
void __fastcall OSuite::ZHttpParser::ParseCacheControl(OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *pDest, OSuite::ZString *sHeader)
{
  OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString> > *v2; // r12
  OSuite::ZString *v3; // rdi
  unsigned __int64 v4; // rbx
  unsigned __int8 v5; // al
  bool v6; // r14
  unsigned __int64 i; // rsi
  int v8; // eax
  int v9; // er14
  unsigned __int64 v10; // rbx
  unsigned __int8 v11; // al
  int v12; // er15
  int j; // ebx
  unsigned __int8 v14; // al
  OSuite::ZString *v15; // rax
  OSuite::ZString *v16; // rax
  OSuite::ZString v17; // [rsp+20h] [rbp-50h]
  OSuite::ZString result; // [rsp+38h] [rbp-38h]
  OSuite::ZString value; // [rsp+50h] [rbp-20h]

  v2 = pDest;
  v3 = sHeader;
  v4 = 0i64;
  if ( OSuite::ZString::Count(sHeader) )
  {
    do
    {
      while ( v4 < OSuite::ZString::Count(v3) )
      {
        v5 = OSuite::ZString::CharAt(v3, v4);
        if ( !isspace(v5) )
          break;
        ++v4;
      }
      v6 = 0;
      for ( i = v4; i < OSuite::ZString::Count(v3); ++i )
      {
        if ( OSuite::ZString::CharAt(v3, i) == 44 && !v6 )
          break;
        if ( OSuite::ZString::CharAt(v3, i) == 34 )
          v6 = v6 == 0;
      }
      result.m_pString = 0i64;
      OSuite::ZString::Slice(v3, &result, v4, i - v4);
      value.m_pString = 0i64;
      OSuite::ZString::ZString(&value);
      v8 = OSuite::ZString::IndexOf(&result, 61, 0i64);
      v9 = v8;
      if ( v8 < 0 )
      {
        OSuite::ZString::operator=(&value, &result);
      }
      else
      {
        v10 = v8;
        if ( v8 < OSuite::ZString::Count(&result) )
        {
          do
          {
            v11 = OSuite::ZString::CharAt(&result, v10);
            if ( !isspace(v11) )
              break;
            v10 = ++v9;
          }
          while ( v9 < OSuite::ZString::Count(&result) );
        }
        v12 = v9 + 1;
        if ( OSuite::ZString::CharAt(&result, v9 + 1) == 34 )
          v12 = v9 + 2;
        for ( j = OSuite::ZString::Count(&result) - 1; ; --j )
        {
          v14 = OSuite::ZString::CharAt(&result, j);
          if ( !isspace(v14) )
            break;
        }
        if ( OSuite::ZString::CharAt(&result, j) == 34 )
          --j;
        v15 = OSuite::ZString::Slice(&result, &v17, v12, j - v12 + 1);
        OSuite::ZString::operator=(&value, v15);
        OSuite::ZString::~ZString(&v17);
        v16 = OSuite::ZString::Slice(&result, &v17, 0i64, v9);
        OSuite::ZString::operator=(&result, v16);
        OSuite::ZString::~ZString(&v17);
      }
      OSuite::TOrderedMap<OSuite::ZString,OSuite::ZString,OSuite::TOperatorComparer<OSuite::ZString>>::Insert(
        v2,
        &result,
        &value);
      v4 = i + 1;
      OSuite::ZString::~ZString(&value);
      OSuite::ZString::~ZString(&result);
    }
    while ( i + 1 < OSuite::ZString::Count(v3) );
  }
}

// File Line: 82
// RVA: 0xEE2514
void __fastcall OSuite::ZHttpParser::ParseContentType(OSuite::ZString *sContentType, bool *bContentIsText, OSuite::ZTextDecoder **pDecoder)
{
  int v3; // er14
  OSuite::ZTextDecoder **v4; // r12
  bool *v5; // r15
  OSuite::ZHttpParser *v6; // rdi
  int v7; // er8
  int v8; // ebx
  int v9; // er8
  int v10; // ebp
  __int64 v11; // rsi
  char v12; // al
  _BYTE *i; // rcx
  unsigned __int64 v14; // rcx
  char v15; // r8
  char *v16; // rdx
  char v17; // al
  OSuite::ZTextDecoder *v18; // rax
  OSuite::ZTextDecoder *v19; // rsi
  OSuite::ZString sEncoding; // [rsp+28h] [rbp-160h]
  char pszString[256]; // [rsp+40h] [rbp-148h]

  v3 = 0;
  v4 = pDecoder;
  v5 = bContentIsText;
  v6 = (OSuite::ZHttpParser *)OSuite::ZString::c_str(sContentType);
  v8 = OSuite::ZHttpParser::skipwhitespace<char>(v6, 0i64, v7);
  if ( !strncmp((const char *)v6 + v8, "application/", 0xCui64) )
  {
    v10 = v8 + 12;
    v11 = v8 + 12;
    while ( *((_BYTE *)&v6->vfptr + v11) && *((_BYTE *)&v6->vfptr + v11) != 59 )
    {
      if ( !strncmp((const char *)v6 + v10, "xml", 3ui64) )
      {
        *v5 = 1;
        break;
      }
      do
      {
        v12 = *((_BYTE *)&v6->vfptr + v11);
        if ( !v12 )
          break;
        if ( v12 == 59 )
          break;
        ++v10;
        ++v11;
      }
      while ( v12 != 43 );
    }
  }
  else
  {
    *v5 = strncmp((const char *)v6 + v8, "text/", 5ui64) == 0;
  }
  if ( *v5 )
  {
    while ( 1 )
    {
      for ( i = (char *)v6 + v8; *i && *i != 59; ++i )
        ++v8;
      if ( !*((_BYTE *)&v6->vfptr + v8) )
        break;
      v8 = OSuite::ZHttpParser::skipwhitespace<char>(v6, (const char *)(unsigned int)(v8 + 1), v9);
      if ( !strncmp((const char *)v6 + v8, "charset=", 8ui64) )
      {
        v8 += 8;
        v14 = 0i64;
        v15 = 32;
        if ( *((_BYTE *)&v6->vfptr + v8) == 34 || *((_BYTE *)&v6->vfptr + v8) == 39 )
          v15 = *((_BYTE *)&v6->vfptr + v8++);
        v16 = (char *)v6 + v8;
        v17 = *v16;
        if ( *v16 )
        {
          do
          {
            if ( v17 == v15 )
              break;
            if ( v17 == 10 )
              break;
            if ( v17 == 13 )
              break;
            ++v16;
            pszString[v14++] = v17;
            v17 = *v16;
            ++v8;
          }
          while ( *v16 );
          if ( v14 >= 0x100 )
          {
            _report_rangecheckfailure(v14);
            JUMPOUT(*(_QWORD *)&byte_140EE2714);
          }
        }
        pszString[v14] = 0;
        v18 = (OSuite::ZTextDecoder *)OSuite::ZObject::operator new(0x30ui64);
        v19 = v18;
        if ( v18 )
        {
          v18->m_pFeeder = 0i64;
          v18->m_sEncoding.m_pString = 0i64;
          OSuite::ZString::ZString(&sEncoding, pszString);
          v3 |= 1u;
          OSuite::ZTextDecoder::ZTextDecoder(v19, &sEncoding);
        }
        *v4 = v18;
        if ( v3 & 1 )
        {
          v3 &= 0xFFFFFFFE;
          OSuite::ZString::~ZString(&sEncoding);
        }
      }
    }
  }
}

