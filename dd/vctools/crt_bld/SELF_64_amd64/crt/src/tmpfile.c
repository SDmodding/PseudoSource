// File Line: 96
// RVA: 0x12C1FA4
__int64 __fastcall tmpnam_helper(char *s, unsigned __int64 sz, int buffer_no, unsigned int tmp_max, char **ret)
{
  _tiddata *v5; // rsi
  size_t v6; // r13
  char *v7; // r14
  unsigned int v8; // ebx
  char *v10; // rdi
  unsigned __int64 v11; // r12
  _tiddata *v12; // rax
  char *v13; // rax
  int *v14; // rax
  int v15; // [rsp+30h] [rbp-28h]
  unsigned int tmp_maxa; // [rsp+78h] [rbp+20h]

  tmp_maxa = tmp_max;
  LODWORD(v5) = buffer_no;
  v6 = sz;
  v7 = s;
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
  if ( !genfname(v10, v11, tmp_maxa) )
  {
LABEL_9:
    while ( !access_s(v10, 0) )
    {
      if ( genfname(v10, v11, tmp_maxa) )
        goto $tmpnam_err;
    }
    if ( v7 )
      goto LABEL_19;
    v12 = getptd_noexit();
    v5 = v12;
    if ( v12 && (v12->_namebuf0 || (v13 = (char *)malloc_crt(0xEui64), (v5->_namebuf0 = v13) != 0i64)) )
    {
      v7 = v5->_namebuf0;
      if ( (unsigned int)strcpy_s(v5->_namebuf0, 0xEui64, v10) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
LABEL_19:
        if ( (_DWORD)v5 && strlen(v10) >= v6 )
        {
          v8 = 34;
          if ( v6 )
            *v7 = 0;
        }
        else if ( (unsigned int)strcpy_s(v7, v6, v10) )
        {
          invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        }
        goto $tmpnam_err;
      }
    }
    else
    {
      v8 = 12;
    }
  }
$tmpnam_err:
  unlock(2);
  *ret = v7;
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
  char *ret; // [rsp+40h] [rbp+8h]

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
  int v2; // ebx
  char *v3; // rsi
  char *v4; // rdi
  char v5; // al
  DWORD v6; // eax
  __int64 v7; // rdi
  __int64 result; // rax
  unsigned int v9; // eax
  char *v10; // [rsp+30h] [rbp-138h]
  char Buffer; // [rsp+40h] [rbp-128h]

  v1 = 0i64;
  v2 = flag;
  if ( flag )
  {
    if ( flag == 1 )
    {
      v3 = tmpfile_buf;
      v1 = 272i64;
      goto LABEL_16;
    }
    if ( flag == 2 )
    {
      v3 = tmpnam_s_buf;
      v1 = 18i64;
LABEL_5:
      if ( (unsigned int)strcpy_s(v3, v1, "\\") )
      {
LABEL_28:
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
        JUMPOUT(*(_QWORD *)tmpnam_s);
      }
      v4 = v3 + 1;
      goto LABEL_7;
    }
    v3 = v10;
  }
  else
  {
    v3 = tmpnam_buf;
    v1 = 14i64;
  }
  if ( flag != 1 )
    goto LABEL_5;
LABEL_16:
  v6 = GetTempPathA(0x104u, &Buffer);
  v7 = v6;
  if ( v6 - 1 > 0x103 )
    return 0xFFFFFFFFi64;
  if ( (unsigned int)strcpy_s(v3, v6 + 1, &Buffer) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
    goto LABEL_26;
  }
  v4 = &v3[v7 - 1];
LABEL_7:
  v5 = *(v4 - 1);
  if ( v5 != 92 && v5 != 47 )
    *v4++ = 92;
  if ( v2 == 1 )
    *v4 = 116;
  else
    *v4 = 115;
  v9 = getpid();
  if ( ultoa_s(v9, v4 + 1, v1 + v3 - (v4 + 1), 32) )
    goto LABEL_27;
  result = strcat_s(v3, v1, ".");
  if ( (_DWORD)result )
  {
LABEL_26:
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
LABEL_27:
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
    goto LABEL_28;
  }
  return result;
}

// File Line: 568
// RVA: 0x12C2160
__int64 __fastcall genfname(char *fname, unsigned __int64 fnameSize, unsigned int tmp_max)
{
  unsigned __int64 v3; // rbx
  unsigned int v4; // ebp
  char *v5; // rsi
  char *v6; // rdi
  unsigned int v7; // eax
  __int64 result; // rax
  char buf; // [rsp+30h] [rbp-28h]

  v3 = fnameSize;
  v4 = tmp_max;
  v5 = fname;
  v6 = (char *)(mbsrchr(fname, 0x2Eu) + 1);
  if ( v6 < v5 || v3 <= v6 - v5 )
  {
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  v7 = (unsigned __int64)strtoul(v6, 0i64, 32) + 1;
  if ( v7 >= v4 )
    return 0xFFFFFFFFi64;
  if ( ultoa_s(v7, &buf, 8ui64, 32) )
  {
LABEL_11:
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
    JUMPOUT(*(_QWORD *)init_namebuf);
  }
  result = strcpy_s(v6, (unsigned __int64)&v5[v3 - (_QWORD)v6], &buf);
  if ( (_DWORD)result )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
    goto LABEL_11;
  }
  return result;
}

