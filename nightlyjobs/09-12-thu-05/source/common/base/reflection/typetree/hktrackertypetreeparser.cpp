// File Line: 15
// RVA: 0x1308400
hkBool *__fastcall hkTrackerTypeTreeParser::_parseTokens(
        hkBool *result,
        hkSubString *str,
        hkTrackerTypeTreeParser::TokenContainer *container)
{
  const char *m_start; // rbx
  const char *m_end; // rdi
  int v7; // edx
  __int64 v8; // rdx
  __int64 v9; // rcx
  __int64 v10; // rdx
  __int64 v11; // rcx
  __int64 v12; // rdx
  __int64 v13; // rcx
  __int64 v14; // rdx
  __int64 v15; // rcx
  __int64 v16; // rdx
  __int64 v17; // rcx
  __int64 v18; // rdx
  __int64 v19; // rcx
  __int64 m_numTokens; // rdx
  __int64 v21; // rcx
  char v22; // al
  __int64 v23; // rdx
  __int64 v24; // rcx
  const char *j; // rdx
  char v27; // cl
  __int64 v28; // rdx
  __int64 v29; // rcx
  __int64 v30; // rdx
  __int64 v31; // rcx
  __int64 v32; // rdx
  __int64 v33; // rcx
  hkTrackerTypeTreeNode::Type v34; // eax
  __int64 v35; // r8
  __int64 v36; // rdx
  __int64 v37; // rdx
  __int64 v38; // rdx
  const char *i; // r8
  __int64 v40; // rdx
  __int64 v41; // rcx
  hkBool v42; // [rsp+20h] [rbp-20h] BYREF
  hkBool v43; // [rsp+21h] [rbp-1Fh] BYREF
  hkBool v44; // [rsp+22h] [rbp-1Eh] BYREF
  hkBool v45; // [rsp+23h] [rbp-1Dh] BYREF
  hkBool v46; // [rsp+24h] [rbp-1Ch] BYREF
  hkSubString subString; // [rsp+28h] [rbp-18h] BYREF
  hkBool resulta; // [rsp+78h] [rbp+38h] BYREF
  hkBool v49; // [rsp+88h] [rbp+48h] BYREF

  m_start = str->m_start;
  m_end = str->m_end;
  if ( str->m_start < m_end )
  {
    while ( 1 )
    {
      v7 = *m_start++;
      switch ( v7 )
      {
        case  :
          goto $LN38_33;
        case &:
          m_numTokens = container->m_numTokens;
          v21 = m_numTokens;
          container->m_numTokens = m_numTokens + 1;
          *(_QWORD *)&container->m_tokens[v21].m_token = 0i64;
          container->m_tokens[v21].m_string.m_start = 0i64;
          container->m_tokens[v21].m_string.m_end = 0i64;
          goto $LN38_33;
        case (:
          v22 = 1;
          if ( m_start >= m_end )
            goto LABEL_17;
          while ( v22 )
          {
            if ( *m_start == 40 )
            {
              ++v22;
            }
            else if ( *m_start == 41 )
            {
              --v22;
            }
            if ( ++m_start >= m_end )
              goto LABEL_17;
          }
          goto $LN38_33;
        case *:
          v18 = container->m_numTokens;
          v19 = v18;
          container->m_numTokens = v18 + 1;
          *(_QWORD *)&container->m_tokens[v19].m_token = 1i64;
          container->m_tokens[v19].m_string.m_start = 0i64;
          container->m_tokens[v19].m_string.m_end = 0i64;
          goto $LN38_33;
        case ,:
          v12 = container->m_numTokens;
          v13 = v12;
          container->m_numTokens = v12 + 1;
          *(_QWORD *)&container->m_tokens[v13].m_token = 10i64;
          container->m_tokens[v13].m_string.m_start = 0i64;
          container->m_tokens[v13].m_string.m_end = 0i64;
          goto $LN38_33;
        case <:
          v14 = container->m_numTokens;
          v15 = v14;
          container->m_numTokens = v14 + 1;
          *(_QWORD *)&container->m_tokens[v15].m_token = 8i64;
          container->m_tokens[v15].m_string.m_start = 0i64;
          container->m_tokens[v15].m_string.m_end = 0i64;
          goto $LN38_33;
        case >:
          v16 = container->m_numTokens;
          v17 = v16;
          container->m_numTokens = v16 + 1;
          *(_QWORD *)&container->m_tokens[v17].m_token = 9i64;
          container->m_tokens[v17].m_string.m_start = 0i64;
          container->m_tokens[v17].m_string.m_end = 0i64;
          goto $LN38_33;
        case [:
          v8 = container->m_numTokens;
          v9 = v8;
          container->m_numTokens = v8 + 1;
          *(_QWORD *)&container->m_tokens[v9].m_token = 12i64;
          container->m_tokens[v9].m_string.m_start = 0i64;
          container->m_tokens[v9].m_string.m_end = 0i64;
          goto $LN38_33;
        case ]:
          v10 = container->m_numTokens;
          v11 = v10;
          container->m_numTokens = v10 + 1;
          *(_QWORD *)&container->m_tokens[v11].m_token = 13i64;
          container->m_tokens[v11].m_string.m_start = 0i64;
          container->m_tokens[v11].m_string.m_end = 0i64;
          goto $LN38_33;
        default:
          if ( (_BYTE)v7 == 45 || (unsigned __int8)(v7 - 48) <= 9u )
          {
            for ( i = m_start - 1; m_start < m_end; ++m_start )
            {
              if ( (unsigned __int8)(*m_start - 48) > 9u )
                break;
            }
            v40 = container->m_numTokens;
            v41 = v40;
            container->m_numTokens = v40 + 1;
            *(_QWORD *)&container->m_tokens[v41].m_token = 14i64;
            container->m_tokens[v41].m_string.m_start = i;
            container->m_tokens[v41].m_string.m_end = m_start;
            goto $LN38_33;
          }
          if ( (_BYTE)v7 == 96 )
          {
            if ( m_start < m_end )
            {
              while ( *m_start != 39 )
              {
                if ( ++m_start >= m_end )
                  goto LABEL_25;
              }
LABEL_26:
              ++m_start;
              goto $LN38_33;
            }
LABEL_25:
            if ( *m_start == 39 )
              goto LABEL_26;
          }
          else
          {
            if ( (unsigned __int8)(v7 - 97) > 0x19u
              && (unsigned __int8)(v7 - 65) > 0x19u
              && (_BYTE)v7 != 95
              && (_BYTE)v7 != 58 )
            {
              result->m_bool = 0;
              return result;
            }
            for ( j = m_start - 1; m_start < m_end; ++m_start )
            {
              v27 = *m_start;
              if ( (unsigned __int8)(*m_start - 97) > 0x19u
                && (unsigned __int8)(v27 - 65) > 0x19u
                && (unsigned __int8)(v27 - 48) > 9u
                && v27 != 58
                && v27 != 95 )
              {
                break;
              }
            }
            if ( m_start - j > 2 && *j == 58 && j[1] == 58 )
              j += 2;
            subString.m_start = j;
            subString.m_end = m_start;
            if ( !hkSubString::operator==(&subString, &resulta, "const")->m_bool
              && !hkSubString::operator==(&subString, &v49, "restrict")->m_bool )
            {
              if ( hkSubString::operator==(&subString, &v42, "enum")->m_bool )
              {
                v28 = container->m_numTokens;
                v29 = v28;
                container->m_numTokens = v28 + 1;
                container->m_tokens[v28].m_token = TOKEN_ENUM;
              }
              else if ( hkSubString::operator==(&subString, &v43, "struct")->m_bool
                     || hkSubString::operator==(&subString, &v44, "class")->m_bool )
              {
                v38 = container->m_numTokens;
                v29 = v38;
                container->m_numTokens = v38 + 1;
                container->m_tokens[v38].m_token = TOKEN_CLASS;
              }
              else
              {
                if ( hkSubString::operator==(&subString, &v45, "unsigned")->m_bool )
                {
                  v30 = container->m_numTokens;
                  v31 = v30;
                  container->m_numTokens = v30 + 1;
                  *(_QWORD *)&container->m_tokens[v31].m_token = 6i64;
                  container->m_tokens[v31].m_string.m_start = 0i64;
                  container->m_tokens[v31].m_string.m_end = 0i64;
                  goto $LN38_33;
                }
                if ( hkSubString::operator==(&subString, &v46, "signed")->m_bool )
                {
                  v32 = container->m_numTokens;
                  v33 = v32;
                  container->m_numTokens = v32 + 1;
                  *(_QWORD *)&container->m_tokens[v33].m_token = 7i64;
                  container->m_tokens[v33].m_string.m_start = 0i64;
                  container->m_tokens[v33].m_string.m_end = 0i64;
                  goto $LN38_33;
                }
                v34 = hkTrackerTypeTreeParser::_calcBuiltInType(&subString);
                if ( v34 )
                {
                  v35 = container->m_numTokens;
                  v36 = v35;
                  container->m_numTokens = v35 + 1;
                  container->m_tokens[v36].m_token = TOKEN_BUILT_IN;
                  container->m_tokens[v36].m_string = subString;
                  container->m_tokens[v36].m_builtInType = v34;
                  goto $LN38_33;
                }
                v37 = container->m_numTokens;
                v29 = v37;
                container->m_numTokens = v37 + 1;
                container->m_tokens[v37].m_token = TOKEN_IDENTIFIER;
              }
              container->m_tokens[v29].m_string = subString;
              container->m_tokens[v29].m_builtInType = TYPE_VOID;
            }
          }
$LN38_33:
          if ( m_start >= m_end )
            goto LABEL_17;
          break;
      }
    }
  }
LABEL_17:
  v23 = container->m_numTokens;
  result->m_bool = 1;
  v24 = v23;
  container->m_numTokens = v23 + 1;
  *(_QWORD *)&container->m_tokens[v24].m_token = 11i64;
  container->m_tokens[v24].m_string.m_start = 0i64;
  container->m_tokens[v24].m_string.m_end = 0i64;
  return result;
}

// File Line: 176
// RVA: 0x1308E80
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeParser::_parseTerminalType(
        hkTrackerTypeTreeParser::TokenRange *range,
        hkTrackerTypeTreeCache *cache,
        hkStringBuf *prefix)
{
  hkTrackerTypeTreeParser::Token *m_start; // rdi
  hkTrackerTypeTreeParser::Token *m_end; // rdx
  hkTrackerTypeTreeParser::TokenType m_token; // r8d
  hkTrackerTypeTreeNode::Type m_builtInType; // ecx
  hkTrackerTypeTreeNode *result; // rax
  hkTrackerTypeTreeNode *v11; // rax
  hkTrackerTypeTreeNode *v12; // rbx
  int v13; // eax
  hkTrackerTypeTreeParser::Token *v14; // rax
  hkTrackerTypeTreeNode *v15; // rax
  char *v16; // rax
  hkTrackerTypeTreeNode *v17; // rax
  hkTrackerTypeTreeNode *v18; // rdi
  __int64 m_type; // rdx
  hkTrackerTypeTreeNode *v20; // rax
  hkTrackerTypeTreeParser::Token *v21; // rax
  hkTrackerTypeTreeParser::Token *v22; // rdx
  hkTrackerTypeTreeParser::Token *v23; // rax
  hkTrackerTypeTreeNode *v24; // rax
  hkArray<char,hkContainerHeapAllocator> buf; // [rsp+20h] [rbp-E0h] BYREF
  hkTrackerTypeTreeNode *n; // [rsp+30h] [rbp-D0h] BYREF
  int v27; // [rsp+38h] [rbp-C8h]
  int v28; // [rsp+3Ch] [rbp-C4h]
  hkOstream stream; // [rsp+40h] [rbp-C0h] BYREF
  hkStringBuf s; // [rsp+60h] [rbp-A0h] BYREF
  hkStringBuf v31; // [rsp+F0h] [rbp-10h] BYREF
  hkStringBuf v32; // [rsp+180h] [rbp+80h] BYREF
  hkTrackerTypeTreeNode::Type type; // [rsp+230h] [rbp+130h]
  hkTrackerTypeTreeNode *typea; // [rsp+230h] [rbp+130h]
  hkTrackerTypeTreeNode **p_m_contains; // [rsp+248h] [rbp+148h]

  m_start = range->m_start;
  m_end = range->m_end;
  if ( range->m_start == m_end )
    return 0i64;
  m_token = m_start->m_token;
  switch ( m_start->m_token )
  {
    case TOKEN_IDENTIFIER:
    case TOKEN_CLASS:
      v13 = 18;
      if ( m_token == TOKEN_IDENTIFIER )
        v13 = 16;
      type = v13;
      if ( m_token == TOKEN_CLASS )
        ++m_start;
      if ( m_start >= m_end || m_start->m_token != TOKEN_IDENTIFIER )
        return 0i64;
      v14 = m_start + 1;
      if ( &m_start[1] < m_end && v14->m_token == TOKEN_LT )
      {
        hkTrackerTypeTreeCache::newNode(cache, TYPE_REAL);
        typea = v15;
        hkStringBuf::hkStringBuf(&v31, prefix);
        hkStringBuf::append(
          &v31,
          m_start->m_string.m_start,
          LODWORD(m_start->m_string.m_end) - LODWORD(m_start->m_string.m_start));
        v16 = hkTrackerTypeTreeCache::newText(cache, v31.m_string.m_data);
        hkSubString::operator=(&typea->m_name, v16);
        v28 = 0x80000000;
        p_m_contains = &typea->m_contains;
        n = 0i64;
        v27 = 0;
        range->m_start = m_start + 2;
        do
        {
          while ( 1 )
          {
            if ( range->m_start < range->m_end && range->m_start->m_token == TOKEN_INT_VALUE )
            {
              hkTrackerTypeTreeCache::newNode(cache, TYPE_ARRAY_VEC_4);
              v18 = v17;
              v17->m_dimension = hkSubString::getInt(&range->m_start->m_string);
              ++range->m_start;
            }
            else
            {
              v18 = hkTrackerTypeTreeParser::_parseType(range, cache);
              if ( !v18 )
                goto LABEL_34;
            }
            m_type = v18->m_type;
            if ( v18 == cache->m_builtInTypes[m_type] )
            {
              hkTrackerTypeTreeCache::newNode(cache, (hkTrackerTypeTreeNode::Type)m_type);
              v18 = v20;
            }
            *p_m_contains = v18;
            p_m_contains = &v18->m_next;
            hkTrackerTypeTreeParser::_parseTerminalType_::_40_::UndoPlaceHolders::addPlaceHolder(&n);
            v21 = range->m_start;
            v22 = range->m_end;
            if ( range->m_start >= v22 )
            {
LABEL_34:
              hkTrackerTypeTreeParser::_parseTerminalType_::_40_::UndoPlaceHolders::_UndoPlaceHolders(&n);
              v31.m_string.m_size = 0;
              if ( v31.m_string.m_capacityAndFlags >= 0 )
                hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                  &hkContainerTempAllocator::s_alloc,
                  v31.m_string.m_data,
                  v31.m_string.m_capacityAndFlags & 0x3FFFFFFF);
              return 0i64;
            }
            if ( v21->m_token != TOKEN_COMMA )
              break;
            v23 = v21 + 1;
            range->m_start = v23;
            if ( v23 >= v22 )
              goto LABEL_34;
          }
        }
        while ( v21->m_token != TOKEN_GT );
        ++range->m_start;
        hkTrackerTypeTreeParser::_parseTerminalType_::_40_::UndoPlaceHolders::_UndoPlaceHolders(&n);
        v31.m_string.m_size = 0;
        if ( v31.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            v31.m_string.m_data,
            v31.m_string.m_capacityAndFlags & 0x3FFFFFFF);
        v31.m_string.m_data = 0i64;
        v31.m_string.m_capacityAndFlags = 0x80000000;
      }
      else
      {
        range->m_start = v14;
        hkStringBuf::hkStringBuf(&v32, prefix);
        hkStringBuf::append(
          &v32,
          m_start->m_string.m_start,
          LODWORD(m_start->m_string.m_end) - LODWORD(m_start->m_string.m_start));
        typea = hkTrackerTypeTreeCache::newNamedNode(cache, type, v32.m_string.m_data, (hkBool)1);
        v32.m_string.m_size = 0;
        if ( v32.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            v32.m_string.m_data,
            v32.m_string.m_capacityAndFlags & 0x3FFFFFFF);
        v32.m_string.m_data = 0i64;
        v32.m_string.m_capacityAndFlags = 0x80000000;
      }
      if ( range->m_start >= range->m_end || (unsigned int)(range->m_start->m_token - 2) > 1 )
      {
        result = typea;
      }
      else
      {
        hkStringBuf::hkStringBuf(&s, prefix);
        buf.m_data = 0i64;
        buf.m_size = 0;
        buf.m_capacityAndFlags = 0x80000000;
        hkOstream::hkOstream(&stream, &buf);
        hkTrackerTypeTreeNode::dumpType(typea, &stream);
        hkStringBuf::append(&s, buf.m_data, buf.m_size);
        hkStringBuf::append(&s, "::", -1);
        hkOstream::~hkOstream(&stream);
        buf.m_size = 0;
        if ( buf.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            buf.m_data,
            buf.m_capacityAndFlags & 0x3FFFFFFF);
        v24 = hkTrackerTypeTreeParser::_parseTerminalType(range, cache, &s);
        s.m_string.m_size = 0;
        v12 = v24;
        if ( s.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            &hkContainerTempAllocator::s_alloc,
            s.m_string.m_data,
            s.m_string.m_capacityAndFlags & 0x3FFFFFFF);
LABEL_51:
        result = v12;
      }
      break;
    case TOKEN_ENUM:
      if ( &m_start[2] > m_end || m_start[1].m_token != TOKEN_IDENTIFIER )
        return 0i64;
      range->m_start = m_start + 2;
      hkStringBuf::hkStringBuf(&s, prefix);
      hkStringBuf::append(
        &s,
        m_start[1].m_string.m_start,
        LODWORD(m_start[1].m_string.m_end) - LODWORD(m_start[1].m_string.m_start));
      v11 = hkTrackerTypeTreeCache::newNamedNode(cache, TYPE_ARRAY_BYTE, s.m_string.m_data, (hkBool)1);
      s.m_string.m_size = 0;
      v12 = v11;
      if ( s.m_string.m_capacityAndFlags < 0 )
        goto LABEL_51;
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        s.m_string.m_data,
        s.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      return v12;
    case TOKEN_BUILT_IN:
      range->m_start = m_start + 1;
      return cache->m_builtInTypes[m_start->m_builtInType];
    case TOKEN_UNSIGNED:
    case TOKEN_SIGNED:
      range->m_start = m_start + 1;
      if ( &m_start[1] >= m_end || m_start[1].m_token != TOKEN_BUILT_IN )
        return 0i64;
      m_builtInType = m_start[1].m_builtInType;
      range->m_start = m_start + 2;
      if ( m_start->m_token == TOKEN_UNSIGNED )
      {
        if ( (unsigned int)(m_builtInType - 4) <= 3 )
          return cache->m_builtInTypes[m_builtInType + 4];
      }
      else if ( (unsigned int)(m_builtInType - 8) <= 3 )
      {
        m_builtInType -= 4;
      }
      return cache->m_builtInTypes[m_builtInType];
    default:
      return 0i64;
  }
  return result;
}

// File Line: 286
// RVA: 0x13093A0
__int64 __fastcall hkTrackerTypeTreeParser::_parseTerminalType_::_40_::UndoPlaceHolders::_UndoPlaceHolders(_QWORD *a1)
{
  int v2; // ecx
  __int64 v3; // rdx
  __int64 result; // rax
  _QWORD *v5; // r8
  int v6; // r8d

  v2 = 0;
  if ( *((int *)a1 + 2) > 0 )
  {
    v3 = 0i64;
    do
    {
      result = *a1;
      v5 = *(_QWORD **)(v3 + *a1);
      if ( *v5 == 16i64 )
        *v5 = 0i64;
      ++v2;
      v3 += 8i64;
    }
    while ( v2 < *((_DWORD *)a1 + 2) );
  }
  *((_DWORD *)a1 + 2) = 0;
  v6 = *((_DWORD *)a1 + 3);
  if ( v6 >= 0 )
    result = ((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, _QWORD, _QWORD))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
               &hkContainerTempAllocator::s_alloc,
               *a1,
               (unsigned int)(8 * v6));
  *((_DWORD *)a1 + 3) = 0x80000000;
  *a1 = 0i64;
  return result;
}

// File Line: 297
// RVA: 0x1309430
void __fastcall hkTrackerTypeTreeParser::_parseTerminalType_::_40_::UndoPlaceHolders::addPlaceHolder(
        hkTrackerTypeTreeNode **n,
        _QWORD *a2)
{
  *a2 = 16i64;
  if ( *((_DWORD *)n + 2) == (*((_DWORD *)n + 3) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)n, 8);
  *((_QWORD *)&(*n)->m_type + (int)(*((_DWORD *)n + 2))++) = a2;
}

// File Line: 397
// RVA: 0x1308D40
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeParser::_parseType(
        hkTrackerTypeTreeParser::TokenRange *range,
        hkTrackerTypeTreeCache *cache)
{
  hkTrackerTypeTreeNode *v4; // rsi
  hkTrackerTypeTreeParser::Token *m_start; // rax
  hkTrackerTypeTreeNode *v6; // rax
  hkTrackerTypeTreeNode::Type v7; // edx
  hkTrackerTypeTreeNode *v8; // rax
  hkStringBuf prefix; // [rsp+20h] [rbp-98h] BYREF

  prefix.m_string.m_capacityAndFlags = -2147483520;
  prefix.m_string.m_size = 1;
  prefix.m_string.m_data = prefix.m_string.m_storage;
  prefix.m_string.m_storage[0] = 0;
  v4 = hkTrackerTypeTreeParser::_parseTerminalType(range, cache, &prefix);
  if ( v4 )
  {
    m_start = range->m_start;
    if ( range->m_start < range->m_end )
    {
      while ( m_start->m_token )
      {
        if ( m_start->m_token == TOKEN_POINTER )
        {
          v7 = TYPE_BYTE;
LABEL_12:
          hkTrackerTypeTreeCache::newNode(cache, v7);
          v8->m_contains = v4;
          ++range->m_start;
          v4 = v8;
          goto LABEL_13;
        }
        if ( m_start->m_token != TOKEN_OPEN_SQUARE )
          goto LABEL_16;
        if ( &m_start[3] > range->m_end
          || m_start[1].m_token != TOKEN_INT_VALUE
          || m_start[2].m_token != TOKEN_CLOSE_SQUARE )
        {
          goto LABEL_15;
        }
        hkTrackerTypeTreeCache::newNode(cache, TYPE_ARRAY_REAL);
        v6->m_contains = v4;
        v4 = v6;
        v6->m_dimension = hkSubString::getInt(&range->m_start[1].m_string);
        range->m_start += 3;
LABEL_13:
        m_start = range->m_start;
        if ( range->m_start >= range->m_end )
          goto LABEL_16;
      }
      v7 = TYPE_INT;
      goto LABEL_12;
    }
  }
  else
  {
LABEL_15:
    v4 = 0i64;
  }
LABEL_16:
  prefix.m_string.m_size = 0;
  if ( prefix.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      prefix.m_string.m_data,
      prefix.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v4;
}

// File Line: 463
// RVA: 0x13088F0
__int64 __fastcall hkTrackerTypeTreeParser::_calcBuiltInType(hkSubString *subString)
{
  const char *v3; // r8
  hkBool *v4; // rdx
  const char *v5; // r8
  hkBool *v6; // rdx
  hkBool v7; // [rsp+20h] [rbp-28h] BYREF
  char v8; // [rsp+21h] [rbp-27h] BYREF
  char v9; // [rsp+22h] [rbp-26h] BYREF
  hkBool v10; // [rsp+23h] [rbp-25h] BYREF
  hkBool v11; // [rsp+24h] [rbp-24h] BYREF
  hkBool v12; // [rsp+25h] [rbp-23h] BYREF
  hkBool v13; // [rsp+26h] [rbp-22h] BYREF
  hkBool v14; // [rsp+27h] [rbp-21h] BYREF
  hkBool v15; // [rsp+28h] [rbp-20h] BYREF
  hkBool v16; // [rsp+29h] [rbp-1Fh] BYREF
  hkBool v17; // [rsp+2Ah] [rbp-1Eh] BYREF
  hkBool v18; // [rsp+2Bh] [rbp-1Dh] BYREF
  hkBool v19; // [rsp+2Ch] [rbp-1Ch] BYREF
  hkBool v20; // [rsp+2Dh] [rbp-1Bh] BYREF
  hkBool v21; // [rsp+2Eh] [rbp-1Ah] BYREF
  hkBool v22; // [rsp+2Fh] [rbp-19h] BYREF
  hkBool v23; // [rsp+30h] [rbp-18h] BYREF
  hkBool v24; // [rsp+31h] [rbp-17h] BYREF
  hkBool v25; // [rsp+32h] [rbp-16h] BYREF
  hkBool v26; // [rsp+33h] [rbp-15h] BYREF
  hkBool v27; // [rsp+34h] [rbp-14h] BYREF
  hkBool v28; // [rsp+35h] [rbp-13h] BYREF
  hkBool v29; // [rsp+36h] [rbp-12h] BYREF
  hkBool v30; // [rsp+37h] [rbp-11h] BYREF
  hkBool v31; // [rsp+38h] [rbp-10h] BYREF
  hkBool result; // [rsp+60h] [rbp+18h] BYREF
  hkBool v33; // [rsp+68h] [rbp+20h] BYREF
  hkBool v34; // [rsp+70h] [rbp+28h] BYREF
  hkBool v35; // [rsp+78h] [rbp+30h] BYREF

  if ( LODWORD(subString->m_end) - LODWORD(subString->m_start) > 0 )
  {
    switch ( *subString->m_start )
    {
      case _:
        if ( hkSubString::operator==(subString, &v11, "__int8")->m_bool )
          return 4i64;
        if ( hkSubString::operator==(subString, &v13, "__int16")->m_bool )
          return 5i64;
        if ( hkSubString::operator==(subString, &v15, "__int32")->m_bool )
          return 6i64;
        if ( hkSubString::operator==(subString, &v17, "__int64")->m_bool )
          return 7i64;
        if ( hkSubString::operator==(subString, &v19, "__uint8")->m_bool )
          return 8i64;
        if ( hkSubString::operator==(subString, &v21, "__uint16")->m_bool )
          return 9i64;
        if ( hkSubString::operator==(subString, &v23, "__uint32")->m_bool )
          return 10i64;
        if ( hkSubString::operator==(subString, &v25, "__uint64")->m_bool )
          return 11i64;
        return 0i64;
      case b:
        if ( !hkSubString::operator==(subString, &v31, "bool")->m_bool )
          return 0i64;
        return 14i64;
      case c:
        if ( !hkSubString::operator==(subString, &v27, "char")->m_bool )
          return 0i64;
        return 4i64;
      case d:
        v3 = "double";
        v4 = &v33;
        goto LABEL_6;
      case f:
        if ( !hkSubString::operator==(subString, &result, "float")->m_bool )
          return 0i64;
        return 12i64;
      case h:
        if ( LODWORD(subString->m_end) - LODWORD(subString->m_start) < 2 || *((_BYTE *)subString->m_start + 1) != 107 )
          return 0i64;
        if ( hkSubString::operator==(subString, &v20, "hkUint8")->m_bool )
          return 8i64;
        if ( hkSubString::operator==(subString, &v10, "hkInt8")->m_bool )
          return 4i64;
        if ( hkSubString::operator==(subString, &v26, "hkUint16")->m_bool )
          return 9i64;
        if ( hkSubString::operator==(subString, &v12, "hkInt16")->m_bool )
          return 5i64;
        if ( hkSubString::operator==(subString, &v22, "hkUint32")->m_bool )
          return 10i64;
        if ( hkSubString::operator==(subString, &v14, "hkInt32")->m_bool )
          return 6i64;
        if ( hkSubString::operator==(subString, &v30, "hkUint64")->m_bool )
          return 11i64;
        if ( hkSubString::operator==(subString, &v16, "hkInt64")->m_bool )
          return 7i64;
        if ( hkSubString::operator==(subString, &v24, "hkUlong")->m_bool )
          return 11i64;
        if ( hkSubString::operator==(subString, &v18, "hkLong")->m_bool )
          return 7i64;
        if ( hkSubString::operator==(subString, &v28, "hkReal")->m_bool
          || hkSubString::operator==(subString, &v7, "hkFloat32")->m_bool )
        {
          return 12i64;
        }
        v3 = "hkDouble64";
        v4 = (hkBool *)&v9;
LABEL_6:
        if ( hkSubString::operator==(subString, v4, v3)->m_bool )
          return 13i64;
        break;
      case i:
        v5 = "int";
        v6 = &v35;
        goto LABEL_11;
      case l:
        v5 = "long";
        v6 = (hkBool *)&v8;
LABEL_11:
        if ( hkSubString::operator==(subString, v6, v5)->m_bool )
          return 6i64;
        return 0i64;
      case s:
        if ( !hkSubString::operator==(subString, &v34, "short")->m_bool )
          return 0i64;
        return 5i64;
      case v:
        if ( !hkSubString::operator==(subString, &v29, "void")->m_bool )
          return 0i64;
        return 15i64;
      default:
        return 0i64;
    }
  }
  return 0i64;
}

// File Line: 650
// RVA: 0x1308340
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeParser::parseNewType(
        hkSubString *subString,
        hkTrackerTypeTreeCache *cache)
{
  __int64 v2; // rbx
  hkSubString *p_m_string; // rax
  int v5; // r8d
  hkTrackerTypeTreeNode *v7; // rax
  hkTrackerTypeTreeParser::TokenRange range; // [rsp+20h] [rbp-628h] BYREF
  hkTrackerTypeTreeParser::TokenContainer container; // [rsp+30h] [rbp-618h] BYREF
  hkBool result; // [rsp+660h] [rbp+18h] BYREF

  v2 = 0i64;
  p_m_string = &container.m_tokens[0].m_string;
  v5 = 63;
  container.m_numTokens = 0;
  do
  {
    --v5;
    p_m_string->m_start = 0i64;
    p_m_string->m_end = 0i64;
    p_m_string = (hkSubString *)((char *)p_m_string + 24);
  }
  while ( v5 >= 0 );
  hkTrackerTypeTreeParser::_parseTokens(&result, subString, &container);
  if ( result.m_bool )
  {
    range.m_start = container.m_tokens;
    range.m_end = (hkTrackerTypeTreeParser::Token *)((char *)&range + 24 * container.m_numTokens);
    v7 = hkTrackerTypeTreeParser::_parseType(&range, cache);
    if ( range.m_start == range.m_end )
      return v7;
    return (hkTrackerTypeTreeNode *)v2;
  }
  else
  {
    return 0i64;
  }
}

// File Line: 673
// RVA: 0x13081E0
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeParser::parseType(
        const char *typeName,
        hkTrackerTypeTreeCache *cache)
{
  hkSubString subString; // [rsp+20h] [rbp-18h] BYREF
  hkBool result; // [rsp+50h] [rbp+18h] BYREF
  hkTrackerTypeTreeNode *nodeOut; // [rsp+58h] [rbp+20h] BYREF

  if ( !hkTrackerTypeTreeCache::getTypeExpressionTree(cache, &result, typeName, &nodeOut)->m_bool )
  {
    subString.m_start = typeName;
    subString.m_end = &typeName[(int)hkString::strLen(typeName)];
    nodeOut = hkTrackerTypeTreeParser::parseNewType(&subString, cache);
    hkTrackerTypeTreeCache::setTypeExpressionTree(cache, typeName, nodeOut);
  }
  return nodeOut;
}

// File Line: 689
// RVA: 0x1308260
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeParser::parseType(
        hkSubString *typeName,
        hkTrackerTypeTreeCache *cache)
{
  int v4; // edi
  hkLifoAllocator *Value; // rax
  char *m_cur; // rbx
  int v7; // edi
  char *v8; // rcx
  hkTrackerTypeTreeNode *v9; // rsi
  hkLifoAllocator *v10; // rax
  int v11; // r8d

  v4 = LODWORD(typeName->m_end) - LODWORD(typeName->m_start);
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)Value->m_cur;
  v7 = (v4 + 128) & 0xFFFFFF80;
  v8 = &m_cur[v7];
  if ( v7 > Value->m_slabSize || v8 > Value->m_end )
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v7);
  else
    Value->m_cur = v8;
  hkString::strNcpy(m_cur, typeName->m_start, LODWORD(typeName->m_end) - LODWORD(typeName->m_start));
  m_cur[LODWORD(typeName->m_end) - LODWORD(typeName->m_start)] = 0;
  v9 = hkTrackerTypeTreeParser::parseType(m_cur, cache);
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (v7 + 15) & 0xFFFFFFF0;
  if ( v7 > v10->m_slabSize || &m_cur[v11] != v10->m_cur || v10->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v10, m_cur, v11);
  else
    v10->m_cur = m_cur;
  return v9;
}

