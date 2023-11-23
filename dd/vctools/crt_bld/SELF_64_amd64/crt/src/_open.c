// File Line: 58
// RVA: 0x12CD8F0
_iobuf *__fastcall openfile(const char *filename, const char *mode, int shflag, _iobuf *str)
{
  int v5; // r9d
  int v6; // r10d
  int v7; // r11d
  const char *i; // rbx
  int v12; // edi
  int v13; // esi
  const char *v14; // rbx
  int v15; // edx
  char v16; // al
  const char *j; // rbx
  int v18; // eax
  int pfh; // [rsp+68h] [rbp+10h] BYREF

  v5 = 0;
  v6 = 0;
  v7 = 0;
  for ( i = mode; *i == 32; ++i )
    ;
  switch ( *i )
  {
    case a:
      v12 = 265;
      break;
    case r:
      v12 = 0;
      v13 = commode | 1;
      goto LABEL_12;
    case w:
      v12 = 769;
      break;
    default:
LABEL_6:
      *errno() = 22;
      invalid_parameter_noinfo();
      return 0i64;
  }
  v13 = commode | 2;
LABEL_12:
  v14 = i + 1;
  v15 = 1;
  v16 = *v14;
  if ( !*v14 )
    goto LABEL_66;
  while ( v15 )
  {
    if ( v16 > 83 )
    {
      switch ( v16 )
      {
        case T:
          if ( (v12 & 0x1000) == 0 )
          {
            v12 |= 0x1000u;
            break;
          }
          goto LABEL_46;
        case b:
          if ( (v12 & 0xC000) != 0 )
            goto LABEL_46;
          v12 |= 0x8000u;
          break;
        case c:
          if ( v5 )
            goto LABEL_46;
          v5 = 1;
          v13 |= 0x4000u;
          break;
        case n:
          if ( v5 )
            goto LABEL_46;
          v5 = 1;
          v13 &= ~0x4000u;
          break;
        case t:
          if ( (v12 & 0xC000) != 0 )
            goto LABEL_46;
          v12 |= 0x4000u;
          break;
        default:
          goto LABEL_6;
      }
    }
    else if ( v16 == 83 )
    {
      if ( v6 )
        goto LABEL_46;
      v6 = 1;
      v12 |= 0x20u;
    }
    else if ( v16 != 32 )
    {
      switch ( v16 )
      {
        case +:
          if ( (v12 & 2) != 0 )
            goto LABEL_46;
          v12 = v12 & 0xFFFFFFFC | 2;
          v13 = v13 & 0xFFFFFF7C | 0x80;
          break;
        case ,:
          v7 = 1;
LABEL_46:
          v15 = 0;
          break;
        case D:
          if ( (v12 & 0x40) != 0 )
            goto LABEL_46;
          v12 |= 0x40u;
          break;
        case N:
          v12 |= 0x80u;
          break;
        case R:
          if ( v6 )
            goto LABEL_46;
          v6 = 1;
          v12 |= 0x10u;
          break;
        default:
          goto LABEL_6;
      }
    }
    v16 = *++v14;
    if ( !*v14 )
      break;
  }
  if ( !v7 )
    goto LABEL_66;
  while ( *v14 == 32 )
    ++v14;
  if ( mbsnbcmp("ccs", v14, 3ui64) )
    goto LABEL_6;
  for ( j = v14 + 3; *j == 32; ++j )
    ;
  if ( *j != 61 )
    goto LABEL_6;
  do
    ++j;
  while ( *j == 32 );
  if ( !mbsnbicmp(j, "UTF-8", 5ui64) )
  {
    v14 = j + 5;
    v12 |= 0x40000u;
    goto LABEL_66;
  }
  if ( !mbsnbicmp(j, "UTF-16LE", 8ui64) )
  {
    v14 = j + 8;
    v12 |= 0x20000u;
    goto LABEL_66;
  }
  if ( mbsnbicmp(j, "UNICODE", 7ui64) )
    goto LABEL_6;
  v14 = j + 7;
  v12 |= 0x10000u;
LABEL_66:
  while ( *v14 == 32 )
    ++v14;
  if ( *v14 )
    goto LABEL_6;
  if ( sopen_s(&pfh, filename, v12, shflag, 384) )
    return 0i64;
  ++cflush;
  str->_cnt = 0;
  v18 = pfh;
  str->_ptr = 0i64;
  str->_base = 0i64;
  str->_tmpfname = 0i64;
  str->_file = v18;
  str->_flag = v13;
  return str;
}

