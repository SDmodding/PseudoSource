// File Line: 96
// RVA: 0x12C1FA4
__int64 __fastcall tmpnam_helper(char *s, unsigned __int64 sz, int buffer_no, unsigned int tmp_max, char **ret)
{
  _tiddata *v5; // rsi
  unsigned int v8; // ebx
  char *v10; // rdi
  unsigned __int64 v11; // r12
  _tiddata *v12; // rax
  char *v13; // rax
  int *v14; // rax
  int v15; // [rsp+30h] [rbp-28h]

  LODWORD(v5) = buffer_no;
  v8 = 0;
  v15 = *errno();
  if ( !mtinitlocknum(2) )
  {
    *ret = 0i64;
    return (unsigned int)*errno();
  }
  lock(2);
  if ( (_DWORD)v5 )
  {
    v10 = tmpnam_s_buf;
    v11 = 18i64;
  }
  else
  {
    v10 = tmpnam_buf;
    v11 = 14i64;
  }
  if ( !*v10 )
  {
    init_namebuf((int)v5);
    goto LABEL_9;
  }
  if ( !genfname(v10, v11, tmp_max) )
  {
LABEL_9:
    while ( !access_s(v10, 0) )
    {
      if ( genfname(v10, v11, tmp_max) )
        goto $tmpnam_err;
    }
    if ( s )
      goto LABEL_19;
    v12 = getptd_noexit();
    v5 = v12;
    if ( v12 && (v12->_namebuf0 || (v13 = (char *)malloc_crt(0xEui64), (v5->_namebuf0 = v13) != 0i64)) )
    {
      s = v5->_namebuf0;
      if ( (unsigned int)strcpy_s(s, 0xEui64, v10) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
LABEL_19:
        if ( (_DWORD)v5 && strlen(v10) >= sz )
        {
          v8 = 34;
          if ( sz )
            *s = 0;
        }
        else if ( (unsigned int)strcpy_s(s, sz, v10) )
        {
          invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        }
      }
    }
    else
    {
      v8 = 12;
    }
  }
$tmpnam_err:
  unlock(2);
  *ret = s;
  v14 = errno();
  if ( v8 )
    *v14 = v8;
  else
    *v14 = v15;
  return v8;
}

// File Line: 215
// RVA: 0x1451ED8
_tmpnam_helper$fin$0

// File Line: 232
// RVA: 0x12C23E8
__int64 __fastcall tmpnam_s(char *s, unsigned __int64 sz)
{
  char *ret; // [rsp+40h] [rbp+8h] BYREF

  if ( s )
    return tmpnam_helper(s, sz, 2, 0x7FFFFFFFu, &ret);
  *errno() = 22;
  invalid_parameter_noinfo();
  return 22i64;
}

// File Line: 472
// RVA: 0x12C2238
__int64 __fastcall init_namebuf(int flag)
{
  unsigned __int64 v1; // rbp
  char *v3; // rsi
  char *v4; // rdi
  char v5; // al
  DWORD TempPathA; // eax
  __int64 v7; // rdi
  __int64 result; // rax
  unsigned int v9; // eax
  char *v10; // [rsp+30h] [rbp-138h]
  char Buffer[272]; // [rsp+40h] [rbp-128h] BYREF

  v1 = 0i64;
  if ( !flag )
  {
    v3 = tmpnam_buf;
    v1 = 14i64;
LABEL_5:
    if ( (unsigned int)strcpy_s(v3, v1, "\\") )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
    }
    v4 = v3 + 1;
    goto LABEL_7;
  }
  if ( flag != 1 )
  {
    if ( flag == 2 )
    {
      v3 = tmpnam_s_buf;
      v1 = 18i64;
    }
    else
    {
      v3 = v10;
    }
    goto LABEL_5;
  }
  v3 = tmpfile_buf;
  v1 = 272i64;
  TempPathA = GetTempPathA(0x104u, Buffer);
  v7 = TempPathA;
  if ( TempPathA - 1 > 0x103 )
    return 0xFFFFFFFFi64;
  if ( (unsigned int)strcpy_s(tmpfile_buf, TempPathA + 1, Buffer) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
  }
  v4 = &tmpfile_buf[v7 - 1];
LABEL_7:
  v5 = *(v4 - 1);
  if ( v5 != 92 && v5 != 47 )
    *v4++ = 92;
  if ( flag == 1 )
    *v4 = 116;
  else
    *v4 = 115;
  v9 = getpid();
  if ( ultoa_s(v9, v4 + 1, v1 + v3 - (v4 + 1), 0x20u) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
  }
  result = strcat_s(v3, v1, ".");
  if ( (_DWORD)result )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
  }
  return result;
}

// File Line: 568
// RVA: 0x12C2160
__int64 __fastcall genfname(char *fname, unsigned __int64 fnameSize, unsigned int tmp_max)
{
  char *v6; // rdi
  unsigned int v7; // eax
  __int64 result; // rax
  char buf[8]; // [rsp+30h] [rbp-28h] BYREF

  v6 = (char *)(mbsrchr(fname, 0x2Eu) + 1);
  if ( v6 < fname || fnameSize <= v6 - fname )
  {
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  v7 = strtoul(v6, 0i64, 0x20u) + 1;
  if ( v7 >= tmp_max )
    return 0xFFFFFFFFi64;
  if ( ultoa_s(v7, buf, 8ui64, 0x20u) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
  }
  result = strcpy_s(v6, (unsigned __int64)&fname[fnameSize - (_QWORD)v6], buf);
  if ( (_DWORD)result )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
  }
  return result;
}

