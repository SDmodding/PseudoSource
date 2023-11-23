// File Line: 46
// RVA: 0x1334360
_iobuf *__fastcall fdopen(int filedes, const char *mode)
{
  const char *v2; // rbx
  __int64 v3; // rsi
  int v4; // edi
  int v5; // edx
  int v6; // r8d
  int v7; // r9d
  unsigned int v8; // edi
  char v9; // al
  _iobuf *v10; // rax
  _iobuf *v11; // rbx

  v2 = mode;
  v3 = filedes;
  if ( !mode )
    goto LABEL_2;
  if ( filedes == -2 )
  {
    *errno() = 9;
    return 0i64;
  }
  if ( (int)ioinit() < 0 )
    return 0i64;
  if ( (int)v3 < 0 || (unsigned int)v3 >= nhandle || (_pioinfo[v3 >> 5][v3 & 0x1F].osfile & 1) == 0 )
  {
    *errno() = 9;
    goto LABEL_44;
  }
  while ( *v2 == 32 )
    ++v2;
  if ( *v2 == 97 )
    goto LABEL_17;
  if ( *v2 != 114 )
  {
    if ( *v2 != 119 )
    {
LABEL_2:
      *errno() = 22;
LABEL_44:
      invalid_parameter_noinfo();
      return 0i64;
    }
LABEL_17:
    v4 = 2;
    goto LABEL_18;
  }
  v4 = 1;
LABEL_18:
  v5 = 1;
  v6 = 0;
  v7 = 0;
  v8 = commode | v4;
  while ( 1 )
  {
    v9 = *++v2;
    if ( !*v2 || !v5 )
      break;
    if ( v9 != 32 )
    {
      switch ( v9 )
      {
        case +:
          if ( (v8 & 0x80u) == 0 )
            v8 = v8 & 0xFFFFFF7C | 0x80;
          else
LABEL_35:
            v5 = 0;
          break;
        case b:
          goto LABEL_32;
        case c:
          if ( v6 )
            goto LABEL_35;
          v6 = 1;
          v8 |= 0x4000u;
          break;
        case n:
          if ( v6 )
            goto LABEL_35;
          v6 = 1;
          v8 &= ~0x4000u;
          break;
        case t:
LABEL_32:
          if ( v7 )
            goto LABEL_35;
          v7 = 1;
          break;
        default:
          goto LABEL_2;
      }
    }
  }
  while ( *v2 == 32 )
    ++v2;
  if ( *v2 )
    goto LABEL_2;
  v10 = getstream();
  v11 = v10;
  if ( !v10 )
  {
    *errno() = 24;
    return 0i64;
  }
  ++cflush;
  v10->_flag = v8;
  v10->_file = v3;
  unlock_file(v10);
  return v11;
}

