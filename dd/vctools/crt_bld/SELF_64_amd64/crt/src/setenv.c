// File Line: 73
// RVA: 0x13347D0
signed __int64 __fastcall _crtwsetenv(unsigned __int16 **poption, const int primary)
{
  int v2; // ebx
  unsigned __int16 **v3; // r15
  unsigned int v4; // edi
  unsigned __int16 *v5; // rbp
  const __m128i *v6; // rax
  const __m128i *v7; // r13
  unsigned __int16 **v8; // rsi
  BOOL v9; // ecx
  const wchar_t **v10; // r14
  int v11; // eax
  unsigned __int16 **v12; // rbx
  const wchar_t *v13; // rax
  signed __int64 v14; // r14
  char **v16; // rax
  unsigned __int16 **v17; // rax
  unsigned __int16 **v18; // r14
  const wchar_t *v19; // rax
  signed __int64 v20; // r13
  signed __int64 v21; // rbx
  __int64 v22; // rsi
  BOOL v23; // er12
  unsigned __int16 **v24; // rcx
  unsigned __int16 *v25; // rax
  unsigned __int16 **v26; // rax
  int v27; // eax
  __int64 v28; // rcx
  signed __int64 v29; // rax
  unsigned __int16 *v30; // rbx
  signed __int64 v31; // rax
  unsigned __int16 *v32; // rdx
  const wchar_t *v33; // rdx
  BOOL v34; // [rsp+70h] [rbp+8h]
  int v35; // [rsp+78h] [rbp+10h]

  v35 = primary;
  v2 = primary;
  v3 = poption;
  v4 = 0;
  if ( !poption )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  v5 = *poption;
  if ( !*poption || (v6 = wcschr(*poption, 0x3Du), (v7 = v6) == 0i64) || v5 == (unsigned __int16 *)v6 )
  {
LABEL_23:
    *errno() = 22;
    return 0xFFFFFFFFi64;
  }
  v8 = wenviron;
  v9 = WORD1(v6->m128i_i64[0]) == 0;
  v34 = WORD1(v6->m128i_i64[0]) == 0;
  if ( wenviron == _winitenv )
  {
    v10 = (const wchar_t **)wenviron;
    v11 = 0;
    if ( wenviron )
    {
      while ( *v8 )
      {
        ++v8;
        ++v11;
      }
      v12 = (unsigned __int16 **)calloc_crt(v11 + 1, 8ui64);
      v8 = v12;
      if ( !v12 )
        amsg_exit(9);
      v13 = *v10;
      if ( *v10 )
      {
        v14 = (char *)v10 - (char *)v12;
        do
        {
          *v12 = wcsdup(v13);
          ++v12;
          v13 = *(unsigned __int16 **)((char *)v12 + v14);
        }
        while ( v13 );
      }
      v9 = v34;
      *v12 = 0i64;
      v2 = v35;
    }
    else
    {
      v8 = 0i64;
    }
    wenviron = v8;
  }
  if ( !v8 )
  {
    if ( v2 && environ )
    {
      wenvptr = (wchar_t *)_crtGetEnvironmentStringsW();
      if ( wsetenvp() < 0 && _mbtow_environ() )
        goto LABEL_23;
    }
    else
    {
      if ( v9 )
        return 0i64;
      if ( !environ )
      {
        v16 = (char **)malloc_crt(8ui64);
        environ = v16;
        if ( !v16 )
          return 0xFFFFFFFFi64;
        *v16 = 0i64;
        v8 = wenviron;
        if ( wenviron )
          goto LABEL_34;
      }
      v17 = (unsigned __int16 **)malloc_crt(8ui64);
      wenviron = v17;
      if ( !v17 )
        return 0xFFFFFFFFi64;
      *v17 = 0i64;
    }
    v8 = wenviron;
  }
LABEL_34:
  v18 = v8;
  if ( !v8 )
    return 0xFFFFFFFFi64;
  v19 = *v8;
  v20 = ((char *)v7 - (char *)v5) >> 1;
  v21 = (signed __int64)v8;
  if ( *v8 )
  {
    while ( wcsnicoll(v5, v19, (signed int)v20)
         || *(_WORD *)(*(_QWORD *)v21 + 2i64 * (signed int)v20) != 61
         && *(_WORD *)(*(_QWORD *)v21 + 2i64 * (signed int)v20) )
    {
      v21 += 8i64;
      v19 = *(const wchar_t **)v21;
      if ( !*(_QWORD *)v21 )
      {
        v8 = wenviron;
        goto LABEL_41;
      }
    }
    v8 = wenviron;
    v21 = (v21 - (signed __int64)wenviron) >> 3;
  }
  else
  {
LABEL_41:
    LODWORD(v21) = -(signed int)((v21 - (signed __int64)v8) >> 3);
  }
  if ( (signed int)v21 < 0 || !*v18 )
  {
    v23 = v34;
    if ( !v34 )
    {
      if ( (signed int)v21 < 0 )
        LODWORD(v21) = -(signed int)v21;
      v27 = v21 + 2;
      if ( (signed int)v21 + 2 <= (signed int)v21 )
        return 0xFFFFFFFFi64;
      if ( (unsigned __int64)v27 >= 0x1FFFFFFFFFFFFFFFi64 )
        return 0xFFFFFFFFi64;
      v26 = (unsigned __int16 **)recalloc_crt(v8, 8ui64, v27);
      if ( !v26 )
        return 0xFFFFFFFFi64;
      v28 = (signed int)v21;
      v26[v28] = v5;
      v26[v28 + 1] = 0i64;
      *v3 = 0i64;
LABEL_50:
      wenviron = v26;
      goto LABEL_60;
    }
    free(v5);
    *v3 = 0i64;
    return 0i64;
  }
  v22 = (signed int)v21;
  free(v18[(signed int)v21]);
  v23 = v34;
  if ( v34 )
  {
    if ( v18[(signed int)v21] )
    {
      v24 = &v18[(signed int)v21 + 1i64];
      do
      {
        v25 = *v24;
        LODWORD(v21) = v21 + 1;
        ++v24;
        v18[v22++] = v25;
      }
      while ( v18[v22] );
    }
    if ( (unsigned __int64)(signed int)v21 >= 0x1FFFFFFFFFFFFFFFi64 )
      goto LABEL_60;
    v26 = (unsigned __int16 **)recalloc_crt(wenviron, (signed int)v21, 8ui64);
    if ( !v26 )
      goto LABEL_60;
    goto LABEL_50;
  }
  v18[(signed int)v21] = v5;
  *v3 = 0i64;
LABEL_60:
  if ( v35 )
  {
    v29 = wcslen(v5);
    v30 = (unsigned __int16 *)calloc_crt(v29 + 2, 2ui64);
    if ( v30 )
    {
      v31 = wcslen(v5);
      if ( (unsigned int)wcscpy_s(v30, v31 + 2, v5) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        JUMPOUT(*(_QWORD *)&byte_141334BA4);
      }
      v32 = &v30[v20];
      *v32 = 0;
      v33 = v32 + 1;
      if ( v23 )
        v33 = 0i64;
      if ( !SetEnvironmentVariableW(v30, v33) )
      {
        v4 = -1;
        *errno() = 42;
      }
      free(v30);
    }
  }
  if ( v23 )
  {
    free(v5);
    *v3 = 0i64;
  }
  return v4;
}

