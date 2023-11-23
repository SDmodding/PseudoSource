// File Line: 49
// RVA: 0x12C1020
char *__fastcall fgets(char *string, int count, _iobuf *str)
{
  int v4; // esi
  char *v6; // r14
  char *v7; // rdi
  int v9; // eax
  ioinfo *v10; // rdx
  ioinfo *v11; // rcx
  int v13; // ecx

  v4 = count;
  v6 = string;
  v7 = string;
  if ( !string && count || count < 0 || !str )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0i64;
  }
  if ( (int)ioinit() < 0 || !v4 )
    return 0i64;
  lock_file(str);
  if ( (str->_flag & 0x40) == 0 )
  {
    v9 = fileno(str);
    if ( (unsigned int)(v9 + 2) <= 1 )
    {
      v11 = &_badioinfo;
      v10 = &_badioinfo;
    }
    else
    {
      v10 = &_pioinfo[(__int64)v9 >> 5][v9 & 0x1F];
      v11 = &_badioinfo;
    }
    if ( (*((_BYTE *)v10 + 56) & 0x7F) != 0 )
      goto LABEL_17;
    if ( (unsigned int)(v9 + 2) > 1 )
      v11 = &_pioinfo[(__int64)v9 >> 5][v9 & 0x1F];
    if ( *((char *)v11 + 56) < 0 )
    {
LABEL_17:
      *errno() = 22;
      invalid_parameter_noinfo();
      v7 = 0i64;
    }
  }
  if ( v7 )
  {
    do
    {
      if ( !--v4 )
        break;
      if ( --str->_cnt < 0 )
        v13 = filbuf(str);
      else
        v13 = *(unsigned __int8 *)str->_ptr++;
      if ( v13 == -1 )
      {
        if ( v6 == string )
        {
          v7 = 0i64;
          goto $done_4;
        }
        break;
      }
      *v6++ = v13;
    }
    while ( (_BYTE)v13 != 10 );
    *v6 = 0;
  }
$done_4:
  unlock_file(str);
  return v7;
}

// File Line: 102
// RVA: 0x1451EC0
fgets$fin$0

