// File Line: 15
// RVA: 0x1308400
hkBool *__fastcall hkTrackerTypeTreeParser::_parseTokens(hkBool *result, hkSubString *str, hkTrackerTypeTreeParser::TokenContainer *container)
{
  const char *v3; // rbx
  const char *v4; // rdi
  hkTrackerTypeTreeParser::TokenContainer *v5; // rsi
  hkBool *v6; // r14
  int v7; // edx
  signed __int64 v8; // rdx
  signed __int64 v9; // rcx
  signed __int64 v10; // rdx
  signed __int64 v11; // rcx
  signed __int64 v12; // rdx
  signed __int64 v13; // rcx
  signed __int64 v14; // rdx
  signed __int64 v15; // rcx
  signed __int64 v16; // rdx
  signed __int64 v17; // rcx
  signed __int64 v18; // rdx
  signed __int64 v19; // rcx
  signed __int64 v20; // rdx
  signed __int64 v21; // rcx
  char v22; // al
  signed __int64 v23; // rdx
  signed __int64 v24; // rcx
  signed __int64 j; // rdx
  char v27; // cl
  signed __int64 v28; // rdx
  signed __int64 v29; // rcx
  signed __int64 v30; // rdx
  signed __int64 v31; // rcx
  signed __int64 v32; // rdx
  signed __int64 v33; // rcx
  hkTrackerTypeTreeNode::Type v34; // eax
  signed __int64 v35; // r8
  signed __int64 v36; // rdx
  signed __int64 v37; // rdx
  signed __int64 v38; // rdx
  signed __int64 i; // r8
  signed __int64 v40; // rdx
  signed __int64 v41; // rcx
  hkBool v42; // [rsp+20h] [rbp-20h]
  hkBool v43; // [rsp+21h] [rbp-1Fh]
  hkBool v44; // [rsp+22h] [rbp-1Eh]
  hkBool v45; // [rsp+23h] [rbp-1Dh]
  hkBool v46; // [rsp+24h] [rbp-1Ch]
  hkSubString subString; // [rsp+28h] [rbp-18h]
  hkBool resulta; // [rsp+78h] [rbp+38h]
  hkBool v49; // [rsp+88h] [rbp+48h]

  v3 = str->m_start;
  v4 = str->m_end;
  v5 = container;
  v6 = result;
  if ( str->m_start < v4 )
  {
    while ( 1 )
    {
      v7 = *v3++;
      switch ( v7 )
      {
        case 32:
          goto $LN38_33;
        case 38:
          v20 = v5->m_numTokens;
          v21 = v20;
          v5->m_numTokens = v20 + 1;
          *(_QWORD *)&v5->m_tokens[v21].m_token = 0i64;
          v5->m_tokens[v21].m_string.m_start = 0i64;
          v5->m_tokens[v21].m_string.m_end = 0i64;
          goto $LN38_33;
        case 40:
          v22 = 1;
          if ( v3 >= v4 )
            goto LABEL_17;
          while ( v22 )
          {
            if ( *v3 == 40 )
            {
              ++v22;
            }
            else if ( *v3 == 41 )
            {
              --v22;
            }
            if ( ++v3 >= v4 )
              goto LABEL_17;
          }
          goto $LN38_33;
        case 42:
          v18 = v5->m_numTokens;
          v19 = v18;
          v5->m_numTokens = v18 + 1;
          *(_QWORD *)&v5->m_tokens[v19].m_token = 1i64;
          v5->m_tokens[v19].m_string.m_start = 0i64;
          v5->m_tokens[v19].m_string.m_end = 0i64;
          goto $LN38_33;
        case 44:
          v12 = v5->m_numTokens;
          v13 = v12;
          v5->m_numTokens = v12 + 1;
          *(_QWORD *)&v5->m_tokens[v13].m_token = 10i64;
          v5->m_tokens[v13].m_string.m_start = 0i64;
          v5->m_tokens[v13].m_string.m_end = 0i64;
          goto $LN38_33;
        case 60:
          v14 = v5->m_numTokens;
          v15 = v14;
          v5->m_numTokens = v14 + 1;
          *(_QWORD *)&v5->m_tokens[v15].m_token = 8i64;
          v5->m_tokens[v15].m_string.m_start = 0i64;
          v5->m_tokens[v15].m_string.m_end = 0i64;
          goto $LN38_33;
        case 62:
          v16 = v5->m_numTokens;
          v17 = v16;
          v5->m_numTokens = v16 + 1;
          *(_QWORD *)&v5->m_tokens[v17].m_token = 9i64;
          v5->m_tokens[v17].m_string.m_start = 0i64;
          v5->m_tokens[v17].m_string.m_end = 0i64;
          goto $LN38_33;
        case 91:
          v8 = v5->m_numTokens;
          v9 = v8;
          v5->m_numTokens = v8 + 1;
          *(_QWORD *)&v5->m_tokens[v9].m_token = 12i64;
          v5->m_tokens[v9].m_string.m_start = 0i64;
          v5->m_tokens[v9].m_string.m_end = 0i64;
          goto $LN38_33;
        case 93:
          v10 = v5->m_numTokens;
          v11 = v10;
          v5->m_numTokens = v10 + 1;
          *(_QWORD *)&v5->m_tokens[v11].m_token = 13i64;
          v5->m_tokens[v11].m_string.m_start = 0i64;
          v5->m_tokens[v11].m_string.m_end = 0i64;
          goto $LN38_33;
        default:
          if ( (_BYTE)v7 == 45 || (unsigned __int8)(v7 - 48) <= 9u )
          {
            for ( i = (signed __int64)(v3 - 1); v3 < v4; ++v3 )
            {
              if ( (unsigned __int8)(*v3 - 48) > 9u )
                break;
            }
            v40 = v5->m_numTokens;
            v41 = v40;
            v5->m_numTokens = v40 + 1;
            *(_QWORD *)&v5->m_tokens[v41].m_token = 14i64;
            v5->m_tokens[v41].m_string.m_start = (const char *)i;
            v5->m_tokens[v41].m_string.m_end = v3;
            goto $LN38_33;
          }
          if ( (_BYTE)v7 == 96 )
          {
            if ( v3 < v4 )
            {
              while ( *v3 != 39 )
              {
                if ( ++v3 >= v4 )
                  goto LABEL_25;
              }
LABEL_26:
              ++v3;
              goto $LN38_33;
            }
LABEL_25:
            if ( *v3 == 39 )
              goto LABEL_26;
          }
          else
          {
            if ( (unsigned __int8)(v7 - 97) > 0x19u
              && (unsigned __int8)(v7 - 65) > 0x19u
              && (_BYTE)v7 != 95
              && (_BYTE)v7 != 58 )
            {
              v6->m_bool = 0;
              return v6;
            }
            for ( j = (signed __int64)(v3 - 1); v3 < v4; ++v3 )
            {
              v27 = *v3;
              if ( (unsigned __int8)(*v3 - 97) > 0x19u
                && (unsigned __int8)(v27 - 65) > 0x19u
                && (unsigned __int8)(v27 - 48) > 9u
                && v27 != 58
                && v27 != 95 )
              {
                break;
              }
            }
            if ( (signed __int64)&v3[-j] > 2 && *(_BYTE *)j == 58 && *(_BYTE *)(j + 1) == 58 )
              j += 2i64;
            subString.m_start = (const char *)j;
            subString.m_end = v3;
            if ( !hkSubString::operator==(&subString, &resulta, "const")->m_bool
              && !hkSubString::operator==(&subString, &v49, "restrict")->m_bool )
            {
              if ( hkSubString::operator==(&subString, &v42, "enum")->m_bool )
              {
                v28 = v5->m_numTokens;
                v29 = v28;
                v5->m_numTokens = v28 + 1;
                v5->m_tokens[v28].m_token = 4;
              }
              else if ( hkSubString::operator==(&subString, &v43, "struct")->m_bool
                     || hkSubString::operator==(&subString, &v44, "class")->m_bool )
              {
                v38 = v5->m_numTokens;
                v29 = v38;
                v5->m_numTokens = v38 + 1;
                v5->m_tokens[v38].m_token = 3;
              }
              else
              {
                if ( hkSubString::operator==(&subString, &v45, "unsigned")->m_bool )
                {
                  v30 = v5->m_numTokens;
                  v31 = v30;
                  v5->m_numTokens = v30 + 1;
                  *(_QWORD *)&v5->m_tokens[v31].m_token = 6i64;
                  v5->m_tokens[v31].m_string.m_start = 0i64;
                  v5->m_tokens[v31].m_string.m_end = 0i64;
                  goto $LN38_33;
                }
                if ( hkSubString::operator==(&subString, &v46, "signed")->m_bool )
                {
                  v32 = v5->m_numTokens;
                  v33 = v32;
                  v5->m_numTokens = v32 + 1;
                  *(_QWORD *)&v5->m_tokens[v33].m_token = 7i64;
                  v5->m_tokens[v33].m_string.m_start = 0i64;
                  v5->m_tokens[v33].m_string.m_end = 0i64;
                  goto $LN38_33;
                }
                v34 = hkTrackerTypeTreeParser::_calcBuiltInType(&subString);
                if ( v34 )
                {
                  v35 = v5->m_numTokens;
                  v36 = v35;
                  v5->m_numTokens = v35 + 1;
                  v5->m_tokens[v36].m_token = 5;
                  v5->m_tokens[v36].m_string = subString;
                  v5->m_tokens[v36].m_builtInType = v34;
                  goto $LN38_33;
                }
                v37 = v5->m_numTokens;
                v29 = v37;
                v5->m_numTokens = v37 + 1;
                v5->m_tokens[v37].m_token = 2;
              }
              v5->m_tokens[v29].m_string = subString;
              v5->m_tokens[v29].m_builtInType = 0;
            }
          }
$LN38_33:
          if ( v3 >= v4 )
            goto LABEL_17;
          break;
      }
    }
  }
LABEL_17:
  v23 = v5->m_numTokens;
  v6->m_bool = 1;
  v24 = v23;
  v5->m_numTokens = v23 + 1;
  *(_QWORD *)&v5->m_tokens[v24].m_token = 11i64;
  v5->m_tokens[v24].m_string.m_start = 0i64;
  v5->m_tokens[v24].m_string.m_end = 0i64;
  return v6;
}

// File Line: 176
// RVA: 0x1308E80
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeParser::_parseTerminalType(hkTrackerTypeTreeParser::TokenRange *range, hkTrackerTypeTreeCache *cache, hkStringBuf *prefix)
{
  hkTrackerTypeTreeParser::Token *v3; // rdi
  hkTrackerTypeTreeCache *v4; // rsi
  hkTrackerTypeTreeParser::Token *v5; // rdx
  hkStringBuf *v6; // r9
  hkTrackerTypeTreeParser::TokenRange *v7; // rbx
  hkTrackerTypeTreeParser::TokenType v8; // er8
  hkTrackerTypeTreeNode::Type v9; // ecx
  hkTrackerTypeTreeNode *result; // rax
  hkTrackerTypeTreeNode *v11; // rax
  hkTrackerTypeTreeNode *v12; // rbx
  signed int v13; // eax
  hkTrackerTypeTreeParser::Token *v14; // rax
  hkTrackerTypeTreeNode *v15; // rax
  char *v16; // rax
  hkTrackerTypeTreeNode *v17; // rax
  hkTrackerTypeTreeNode *v18; // rdi
  __int64 v19; // rdx
  hkTrackerTypeTreeNode *v20; // rax
  hkTrackerTypeTreeParser::Token *v21; // rax
  hkTrackerTypeTreeParser::Token *v22; // rdx
  unsigned __int64 v23; // rax
  hkTrackerTypeTreeNode *v24; // rax
  hkArray<char,hkContainerHeapAllocator> buf; // [rsp+20h] [rbp-E0h]
  hkTrackerTypeTreeNode *n; // [rsp+30h] [rbp-D0h]
  int v27; // [rsp+38h] [rbp-C8h]
  int v28; // [rsp+3Ch] [rbp-C4h]
  hkOstream stream; // [rsp+40h] [rbp-C0h]
  hkStringBuf s; // [rsp+60h] [rbp-A0h]
  hkStringBuf v31; // [rsp+F0h] [rbp-10h]
  hkStringBuf v32; // [rsp+180h] [rbp+80h]
  hkTrackerTypeTreeNode::Type type; // [rsp+230h] [rbp+130h]
  hkTrackerTypeTreeNode *typea; // [rsp+230h] [rbp+130h]
  hkStringBuf *v35; // [rsp+240h] [rbp+140h]
  hkTrackerTypeTreeNode **v36; // [rsp+248h] [rbp+148h]

  v35 = prefix;
  v3 = range->m_start;
  v4 = cache;
  v5 = range->m_end;
  v6 = prefix;
  v7 = range;
  if ( range->m_start == v5 )
    return 0i64;
  v8 = v3->m_token;
  switch ( v3->m_token )
  {
    case 2:
    case 3:
      v13 = 18;
      if ( v8 == 2 )
        v13 = 16;
      type = v13;
      if ( v8 == 3 )
        ++v3;
      if ( v3 >= v5 || v3->m_token != 2 )
        return 0i64;
      v14 = v3 + 1;
      if ( &v3[1] >= v5 || v14->m_token != 8 )
      {
        range->m_start = v14;
        hkStringBuf::hkStringBuf(&v32, v6);
        hkStringBuf::append(&v32, v3->m_string.m_start, LODWORD(v3->m_string.m_end) - LODWORD(v3->m_string.m_start));
        typea = hkTrackerTypeTreeCache::newNamedNode(v4, type, v32.m_string.m_data, (hkBool)1);
        v32.m_string.m_size = 0;
        if ( v32.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v32.m_string.m_data,
            v32.m_string.m_capacityAndFlags & 0x3FFFFFFF);
        v32.m_string.m_data = 0i64;
        v32.m_string.m_capacityAndFlags = 2147483648;
      }
      else
      {
        hkTrackerTypeTreeCache::newNode(v4, TYPE_REAL);
        typea = v15;
        hkStringBuf::hkStringBuf(&v31, v35);
        hkStringBuf::append(&v31, v3->m_string.m_start, LODWORD(v3->m_string.m_end) - LODWORD(v3->m_string.m_start));
        v16 = hkTrackerTypeTreeCache::newText(v4, v31.m_string.m_data);
        hkSubString::operator=(&typea->m_name, v16);
        v28 = 2147483648;
        v36 = &typea->m_contains;
        n = 0i64;
        v27 = 0;
        v7->m_start = v3 + 2;
        do
        {
          while ( 1 )
          {
            if ( v7->m_start >= v7->m_end || v7->m_start->m_token != 14 )
            {
              v18 = hkTrackerTypeTreeParser::_parseType(v7, v4);
              if ( !v18 )
                goto LABEL_34;
            }
            else
            {
              hkTrackerTypeTreeCache::newNode(v4, TYPE_ARRAY_VEC_4);
              v18 = v17;
              v17->m_dimension = hkSubString::getInt(&v7->m_start->m_string);
              ++v7->m_start;
            }
            v19 = v18->m_type;
            if ( v18 == v4->m_builtInTypes[v19] )
            {
              hkTrackerTypeTreeCache::newNode(v4, (hkTrackerTypeTreeNode::Type)v19);
              v18 = v20;
            }
            *v36 = v18;
            v36 = &v18->m_next;
            hkTrackerTypeTreeParser::_parseTerminalType_::_40_::UndoPlaceHolders::addPlaceHolder(&n);
            v21 = v7->m_start;
            v22 = v7->m_end;
            if ( v7->m_start >= v22 )
            {
LABEL_34:
              hkTrackerTypeTreeParser::_parseTerminalType_::_40_::UndoPlaceHolders::_UndoPlaceHolders(&n);
              v31.m_string.m_size = 0;
              if ( v31.m_string.m_capacityAndFlags >= 0 )
                hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                  (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                  v31.m_string.m_data,
                  v31.m_string.m_capacityAndFlags & 0x3FFFFFFF);
              return 0i64;
            }
            if ( v21->m_token != 10 )
              break;
            v23 = (unsigned __int64)&v21[1];
            v7->m_start = (hkTrackerTypeTreeParser::Token *)v23;
            if ( v23 >= (unsigned __int64)v22 )
              goto LABEL_34;
          }
        }
        while ( v21->m_token != 9 );
        ++v7->m_start;
        hkTrackerTypeTreeParser::_parseTerminalType_::_40_::UndoPlaceHolders::_UndoPlaceHolders(&n);
        v31.m_string.m_size = 0;
        if ( v31.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            v31.m_string.m_data,
            v31.m_string.m_capacityAndFlags & 0x3FFFFFFF);
        v31.m_string.m_data = 0i64;
        v31.m_string.m_capacityAndFlags = 2147483648;
      }
      if ( v7->m_start >= v7->m_end || (unsigned int)(v7->m_start->m_token - 2) > 1 )
      {
        result = typea;
      }
      else
      {
        hkStringBuf::hkStringBuf(&s, v35);
        buf.m_data = 0i64;
        buf.m_size = 0;
        buf.m_capacityAndFlags = 2147483648;
        hkOstream::hkOstream(&stream, &buf);
        hkTrackerTypeTreeNode::dumpType(typea, &stream);
        hkStringBuf::append(&s, buf.m_data, buf.m_size);
        hkStringBuf::append(&s, "::", -1);
        hkOstream::~hkOstream(&stream);
        buf.m_size = 0;
        if ( buf.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            buf.m_data,
            buf.m_capacityAndFlags & 0x3FFFFFFF);
        v24 = hkTrackerTypeTreeParser::_parseTerminalType(v7, v4, &s);
        s.m_string.m_size = 0;
        v12 = v24;
        if ( s.m_string.m_capacityAndFlags >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            s.m_string.m_data,
            s.m_string.m_capacityAndFlags & 0x3FFFFFFF);
LABEL_51:
        result = v12;
      }
      break;
    case 4:
      if ( &v3[2] > v5 || v3[1].m_token != 2 )
        return 0i64;
      range->m_start = v3 + 2;
      hkStringBuf::hkStringBuf(&s, v6);
      hkStringBuf::append(&s, v3[1].m_string.m_start, LODWORD(v3[1].m_string.m_end) - LODWORD(v3[1].m_string.m_start));
      v11 = hkTrackerTypeTreeCache::newNamedNode(v4, TYPE_ARRAY_BYTE, s.m_string.m_data, (hkBool)1);
      s.m_string.m_size = 0;
      v12 = v11;
      if ( s.m_string.m_capacityAndFlags < 0 )
        goto LABEL_51;
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        s.m_string.m_data,
        s.m_string.m_capacityAndFlags & 0x3FFFFFFF);
      return v12;
    case 5:
      range->m_start = v3 + 1;
      return v4->m_builtInTypes[v3->m_builtInType];
    case 6:
    case 7:
      range->m_start = v3 + 1;
      if ( &v3[1] >= v5 || v3[1].m_token != 5 )
        return 0i64;
      v9 = v3[1].m_builtInType;
      v7->m_start = v3 + 2;
      if ( v3->m_token == 6 )
      {
        if ( (unsigned int)(v9 - 4) <= 3 )
          return v4->m_builtInTypes[v9 + 4];
      }
      else if ( (unsigned int)(v9 - 8) <= 3 )
      {
        v9 -= 4;
      }
      return v4->m_builtInTypes[v9];
    default:
      return 0i64;
  }
  return result;
}rn v4->m_builtInTypes[v9 + 4];
      }
      else if ( (unsigned int

// File Line: 286
// RVA: 0x13093A0
__int64 __fastcall hkTrackerTypeTreeParser::_parseTerminalType_::_40_::UndoPlaceHolders::_UndoPlaceHolders(__int64 *a1)
{
  __int64 *v1; // rbx
  int v2; // ecx
  __int64 v3; // rdx
  __int64 result; // rax
  _QWORD *v5; // r8
  int v6; // er8

  v1 = a1;
  v2 = 0;
  if ( *((_DWORD *)v1 + 2) > 0 )
  {
    v3 = 0i64;
    do
    {
      result = *v1;
      v5 = *(_QWORD **)(v3 + *v1);
      if ( *v5 == 16i64 )
        *v5 = 0i64;
      ++v2;
      v3 += 8i64;
    }
    while ( v2 < *((_DWORD *)v1 + 2) );
  }
  *((_DWORD *)v1 + 2) = 0;
  v6 = *((_DWORD *)v1 + 3);
  if ( v6 >= 0 )
    result = ((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, __int64, _QWORD))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
               &hkContainerTempAllocator::s_alloc,
               *v1,
               (unsigned int)(8 * v6));
  *((_DWORD *)v1 + 3) = 2147483648;
  *v1 = 0i64;
  return result;
}

// File Line: 297
// RVA: 0x1309430
void __fastcall hkTrackerTypeTreeParser::_parseTerminalType_::_40_::UndoPlaceHolders::addPlaceHolder(hkTrackerTypeTreeNode **n, _QWORD *a2)
{
  _QWORD *v2; // rdi
  hkTrackerTypeTreeNode **v3; // rbx

  *a2 = 16i64;
  v2 = a2;
  v3 = n;
  if ( *((_DWORD *)n + 2) == (*((_DWORD *)n + 3) & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, n, 8);
  *((_QWORD *)&(*v3)->m_type + (signed int)(*((_DWORD *)v3 + 2))++) = v2;
}

// File Line: 397
// RVA: 0x1308D40
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeParser::_parseType(hkTrackerTypeTreeParser::TokenRange *range, hkTrackerTypeTreeCache *cache)
{
  hkTrackerTypeTreeCache *v2; // rbp
  hkTrackerTypeTreeParser::TokenRange *v3; // rdi
  hkTrackerTypeTreeNode *v4; // rsi
  hkSubString *v5; // rax
  hkTrackerTypeTreeNode *v6; // rax
  hkTrackerTypeTreeNode::Type v7; // edx
  hkTrackerTypeTreeNode *v8; // rax
  hkStringBuf prefix; // [rsp+20h] [rbp-98h]

  v2 = cache;
  v3 = range;
  prefix.m_string.m_capacityAndFlags = -2147483520;
  prefix.m_string.m_size = 1;
  prefix.m_string.m_data = prefix.m_string.m_storage;
  prefix.m_string.m_storage[0] = 0;
  v4 = hkTrackerTypeTreeParser::_parseTerminalType(range, cache, &prefix);
  if ( v4 )
  {
    v5 = (hkSubString *)v3->m_start;
    if ( v3->m_start < v3->m_end )
    {
      while ( LODWORD(v5->m_start) )
      {
        if ( LODWORD(v5->m_start) == 1 )
        {
          v7 = 1;
LABEL_12:
          hkTrackerTypeTreeCache::newNode(v2, v7);
          v8->m_contains = v4;
          ++v3->m_start;
          v4 = v8;
          goto LABEL_13;
        }
        if ( LODWORD(v5->m_start) != 12 )
          goto LABEL_16;
        if ( (hkTrackerTypeTreeParser::Token *)&v5[4].m_end > v3->m_end
          || LODWORD(v5[1].m_end) != 14
          || LODWORD(v5[3].m_start) != 13 )
        {
          goto LABEL_15;
        }
        hkTrackerTypeTreeCache::newNode(v2, TYPE_ARRAY_REAL);
        v6->m_contains = v4;
        v4 = v6;
        v6->m_dimension = hkSubString::getInt(&v3->m_start[1].m_string);
        v3->m_start += 3;
LABEL_13:
        v5 = (hkSubString *)v3->m_start;
        if ( v3->m_start >= v3->m_end )
          goto LABEL_16;
      }
      v7 = 2;
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
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      prefix.m_string.m_data,
      prefix.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v4;
}

// File Line: 463
// RVA: 0x13088F0
signed __int64 __fastcall hkTrackerTypeTreeParser::_calcBuiltInType(hkSubString *subString)
{
  hkSubString *v1; // rbx
  const char *v3; // r8
  hkBool *v4; // rdx
  const char *v5; // r8
  hkBool *v6; // rdx
  hkBool v7; // [rsp+20h] [rbp-28h]
  char v8; // [rsp+21h] [rbp-27h]
  char v9; // [rsp+22h] [rbp-26h]
  hkBool v10; // [rsp+23h] [rbp-25h]
  hkBool v11; // [rsp+24h] [rbp-24h]
  hkBool v12; // [rsp+25h] [rbp-23h]
  hkBool v13; // [rsp+26h] [rbp-22h]
  hkBool v14; // [rsp+27h] [rbp-21h]
  hkBool v15; // [rsp+28h] [rbp-20h]
  hkBool v16; // [rsp+29h] [rbp-1Fh]
  hkBool v17; // [rsp+2Ah] [rbp-1Eh]
  hkBool v18; // [rsp+2Bh] [rbp-1Dh]
  hkBool v19; // [rsp+2Ch] [rbp-1Ch]
  hkBool v20; // [rsp+2Dh] [rbp-1Bh]
  hkBool v21; // [rsp+2Eh] [rbp-1Ah]
  hkBool v22; // [rsp+2Fh] [rbp-19h]
  hkBool v23; // [rsp+30h] [rbp-18h]
  hkBool v24; // [rsp+31h] [rbp-17h]
  hkBool v25; // [rsp+32h] [rbp-16h]
  hkBool v26; // [rsp+33h] [rbp-15h]
  hkBool v27; // [rsp+34h] [rbp-14h]
  hkBool v28; // [rsp+35h] [rbp-13h]
  hkBool v29; // [rsp+36h] [rbp-12h]
  hkBool v30; // [rsp+37h] [rbp-11h]
  hkBool v31; // [rsp+38h] [rbp-10h]
  hkBool result; // [rsp+60h] [rbp+18h]
  hkBool v33; // [rsp+68h] [rbp+20h]
  hkBool v34; // [rsp+70h] [rbp+28h]
  hkBool v35; // [rsp+78h] [rbp+30h]

  v1 = subString;
  if ( LODWORD(subString->m_end) - LODWORD(subString->m_start) > 0 )
  {
    switch ( *subString->m_start )
    {
      case 95:
        if ( hkSubString::operator==(subString, &v11, "__int8")->m_bool )
          return 4i64;
        if ( hkSubString::operator==(v1, &v13, "__int16")->m_bool )
          return 5i64;
        if ( hkSubString::operator==(v1, &v15, "__int32")->m_bool )
          return 6i64;
        if ( hkSubString::operator==(v1, &v17, "__int64")->m_bool )
          return 7i64;
        if ( hkSubString::operator==(v1, &v19, "__uint8")->m_bool )
          return 8i64;
        if ( hkSubString::operator==(v1, &v21, "__uint16")->m_bool )
          return 9i64;
        if ( hkSubString::operator==(v1, &v23, "__uint32")->m_bool )
          return 10i64;
        if ( hkSubString::operator==(v1, &v25, "__uint64")->m_bool )
          return 11i64;
        return 0i64;
      case 98:
        if ( !hkSubString::operator==(subString, &v31, "bool")->m_bool )
          return 0i64;
        return 14i64;
      case 99:
        if ( !hkSubString::operator==(subString, &v27, "char")->m_bool )
          return 0i64;
        return 4i64;
      case 100:
        v3 = "double";
        v4 = &v33;
        goto LABEL_6;
      case 102:
        if ( !hkSubString::operator==(subString, &result, "float")->m_bool )
          return 0i64;
        return 12i64;
      case 104:
        if ( LODWORD(subString->m_end) - LODWORD(subString->m_start) < 2 || *((_BYTE *)subString->m_start + 1) != 107 )
          return 0i64;
        if ( hkSubString::operator==(subString, &v20, "hkUint8")->m_bool )
          return 8i64;
        if ( hkSubString::operator==(v1, &v10, "hkInt8")->m_bool )
          return 4i64;
        if ( hkSubString::operator==(v1, &v26, "hkUint16")->m_bool )
          return 9i64;
        if ( hkSubString::operator==(v1, &v12, "hkInt16")->m_bool )
          return 5i64;
        if ( hkSubString::operator==(v1, &v22, "hkUint32")->m_bool )
          return 10i64;
        if ( hkSubString::operator==(v1, &v14, "hkInt32")->m_bool )
          return 6i64;
        if ( hkSubString::operator==(v1, &v30, "hkUint64")->m_bool )
          return 11i64;
        if ( hkSubString::operator==(v1, &v16, "hkInt64")->m_bool )
          return 7i64;
        if ( hkSubString::operator==(v1, &v24, "hkUlong")->m_bool )
          return 11i64;
        if ( hkSubString::operator==(v1, &v18, "hkLong")->m_bool )
          return 7i64;
        if ( hkSubString::operator==(v1, &v28, "hkReal")->m_bool
          || hkSubString::operator==(v1, &v7, "hkFloat32")->m_bool )
        {
          return 12i64;
        }
        v3 = "hkDouble64";
        v4 = (hkBool *)&v9;
LABEL_6:
        if ( hkSubString::operator==(v1, v4, v3)->m_bool )
          return 13i64;
        break;
      case 105:
        v5 = "int";
        v6 = &v35;
        goto LABEL_11;
      case 108:
        v5 = "long";
        v6 = (hkBool *)&v8;
LABEL_11:
        if ( hkSubString::operator==(subString, v6, v5)->m_bool )
          return 6i64;
        return 0i64;
      case 115:
        if ( !hkSubString::operator==(subString, &v34, "short")->m_bool )
          return 0i64;
        return 5i64;
      case 118:
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
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeParser::parseNewType(hkSubString *subString, hkTrackerTypeTreeCache *cache)
{
  hkTrackerTypeTreeNode *v2; // rbx
  hkTrackerTypeTreeCache *v3; // rdi
  hkSubString *v4; // rax
  signed int v5; // er8
  hkTrackerTypeTreeNode *v7; // rax
  hkTrackerTypeTreeParser::TokenRange range; // [rsp+20h] [rbp-628h]
  hkTrackerTypeTreeParser::TokenContainer container; // [rsp+30h] [rbp-618h]
  hkBool result; // [rsp+660h] [rbp+18h]

  v2 = 0i64;
  v3 = cache;
  v4 = &container.m_tokens[0].m_string;
  v5 = 63;
  container.m_numTokens = 0;
  do
  {
    --v5;
    v4->m_start = 0i64;
    v4->m_end = 0i64;
    v4 = (hkSubString *)((char *)v4 + 24);
  }
  while ( v5 >= 0 );
  hkTrackerTypeTreeParser::_parseTokens(&result, subString, &container);
  if ( !result.m_bool )
    return 0i64;
  range.m_start = container.m_tokens;
  range.m_end = (hkTrackerTypeTreeParser::Token *)((char *)&range + 24 * container.m_numTokens);
  v7 = hkTrackerTypeTreeParser::_parseType(&range, v3);
  if ( range.m_start == range.m_end )
    v2 = v7;
  return v2;
}

// File Line: 673
// RVA: 0x13081E0
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeParser::parseType(const char *typeName, hkTrackerTypeTreeCache *cache)
{
  hkTrackerTypeTreeCache *v2; // rdi
  const char *v3; // rbx
  hkSubString subString; // [rsp+20h] [rbp-18h]
  hkBool result; // [rsp+50h] [rbp+18h]
  hkTrackerTypeTreeNode *nodeOut; // [rsp+58h] [rbp+20h]

  v2 = cache;
  v3 = typeName;
  if ( !hkTrackerTypeTreeCache::getTypeExpressionTree(cache, &result, typeName, &nodeOut)->m_bool )
  {
    subString.m_start = v3;
    subString.m_end = &v3[(signed int)hkString::strLen(v3)];
    nodeOut = hkTrackerTypeTreeParser::parseNewType(&subString, v2);
    hkTrackerTypeTreeCache::setTypeExpressionTree(v2, v3, nodeOut);
  }
  return nodeOut;
}

// File Line: 689
// RVA: 0x1308260
hkTrackerTypeTreeNode *__fastcall hkTrackerTypeTreeParser::parseType(hkSubString *typeName, hkTrackerTypeTreeCache *cache)
{
  hkSubString *v2; // rsi
  hkTrackerTypeTreeCache *v3; // rbp
  int v4; // edi
  hkLifoAllocator *v5; // rax
  char *v6; // rbx
  int v7; // edi
  char *v8; // rcx
  hkTrackerTypeTreeNode *v9; // rsi
  hkLifoAllocator *v10; // rax
  int v11; // er8

  v2 = typeName;
  v3 = cache;
  v4 = LODWORD(typeName->m_end) - LODWORD(typeName->m_start);
  v5 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (char *)v5->m_cur;
  v7 = (v4 + 128) & 0xFFFFFF80;
  v8 = &v6[v7];
  if ( v7 > v5->m_slabSize || v8 > v5->m_end )
    v6 = (char *)hkLifoAllocator::allocateFromNewSlab(v5, v7);
  else
    v5->m_cur = v8;
  hkString::strNcpy(v6, v2->m_start, LODWORD(v2->m_end) - LODWORD(v2->m_start));
  v6[LODWORD(v2->m_end) - LODWORD(v2->m_start)] = 0;
  v9 = hkTrackerTypeTreeParser::parseType(v6, v3);
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (v7 + 15) & 0xFFFFFFF0;
  if ( v7 > v10->m_slabSize || &v6[v11] != v10->m_cur || v10->m_firstNonLifoEnd == v6 )
    hkLifoAllocator::slowBlockFree(v10, v6, v11);
  else
    v10->m_cur = v6;
  return v9;
}

