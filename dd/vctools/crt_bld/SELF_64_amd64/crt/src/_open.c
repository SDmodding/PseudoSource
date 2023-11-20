// File Line: 58
// RVA: 0x12CD8F0
_iobuf *__fastcall openfile(const char *filename, const char *mode, int shflag, _iobuf *str)
{
  _iobuf *v4; // r14
  signed int v5; // er9
  signed int v6; // er10
  signed int v7; // er11
  int v8; // ebp
  const char *v9; // rbx
  const char *i; // r15
  int v12; // edi
  unsigned int v13; // esi
  const char *v14; // rbx
  signed int v15; // edx
  char v16; // al
  const char *j; // rbx
  int v18; // eax
  int pfh; // [rsp+68h] [rbp+10h]

  v4 = str;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = shflag;
  v9 = mode;
  for ( i = filename; *v9 == 32; ++v9 )
    ;
  switch ( *v9 )
  {
    case 97:
      v12 = 265;
      break;
    case 114:
      v12 = 0;
      v13 = commode | 1;
      goto LABEL_12;
    case 119:
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
  v14 = v9 + 1;
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
        case 84:
          if ( !_bittest(&v12, 0xCu) )
          {
            v12 |= 0x1000u;
            break;
          }
          goto LABEL_46;
        case 98:
          if ( v12 & 0xC000 )
            goto LABEL_46;
          v12 |= 0x8000u;
          break;
        case 99:
          if ( v5 )
            goto LABEL_46;
          v5 = 1;
          v13 |= 0x4000u;
          break;
        case 110:
          if ( v5 )
            goto LABEL_46;
          v5 = 1;
          v13 &= 0xFFFFBFFF;
          break;
        case 116:
          if ( v12 & 0xC000 )
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
        case 43:
          if ( v12 & 2 )
            goto LABEL_46;
          v12 = v12 & 0xFFFFFFFE | 2;
          v13 = v13 & 0xFFFFFFFC | 0x80;
          break;
        case 44:
          v7 = 1;
LABEL_46:
          v15 = 0;
          break;
        case 68:
          if ( v12 & 0x40 )
            goto LABEL_46;
          v12 |= 0x40u;
          break;
        case 78:
          v12 |= 0x80u;
          break;
        case 82:
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
  if ( sopen_s(&pfh, i, v12, v8, 384) )
    return 0i64;
  ++cflush;
  v4->_cnt = 0;
  v18 = pfh;
  v4->_ptr = 0i64;
  v4->_base = 0i64;
  v4->_tmpfname = 0i64;
  v4->_file = v18;
  v4->_flag = v13;
  return v4;
}

