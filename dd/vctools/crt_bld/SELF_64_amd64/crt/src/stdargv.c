// File Line: 88
// RVA: 0x12D1BAC
__int64 __fastcall setargv()
{
  char *v0; // rbx
  __int64 v1; // rsi
  char **v2; // rax
  char **v3; // rdi
  int numargs; // [rsp+40h] [rbp+8h] BYREF
  int numchars; // [rsp+48h] [rbp+10h] BYREF

  if ( !_mbctype_initialized )
    _initmbctable();
  pgmname[260] = 0;
  GetModuleFileNameA(0i64, pgmname, 0x104u);
  v0 = acmdln;
  pgmptr = pgmname;
  if ( !acmdln || !*acmdln )
    v0 = pgmname;
  parse_cmdline(v0, 0i64, 0i64, &numargs, &numchars);
  v1 = numargs;
  if ( (unsigned __int64)numargs >= 0x1FFFFFFFFFFFFFFFi64 )
    return 0xFFFFFFFFi64;
  if ( numchars == -1i64 )
    return 0xFFFFFFFFi64;
  if ( numchars + 8i64 * numargs < (unsigned __int64)numchars )
    return 0xFFFFFFFFi64;
  v2 = (char **)malloc_crt(numchars + 8i64 * numargs);
  v3 = v2;
  if ( !v2 )
    return 0xFFFFFFFFi64;
  parse_cmdline(v0, v2, (char *)&v2[v1], &numargs, &numchars);
  _argv = v3;
  _argc = numargs - 1;
  return 0i64;
}

// File Line: 221
// RVA: 0x12D1CA0
void __fastcall parse_cmdline(char *cmdstart, char **argv, char *args, int *numargs, int *numchars)
{
  char *v6; // rdi
  char **v7; // r15
  BOOL v9; // ebp
  unsigned __int8 v10; // si
  BOOL v11; // esi
  int v12; // edx
  unsigned int v13; // ecx
  unsigned __int8 v14; // al
  int v15; // eax
  char v16; // al

  v6 = args;
  *numchars = 0;
  v7 = argv;
  *numargs = 1;
  if ( argv )
  {
    *argv = args;
    v7 = argv + 1;
  }
  v9 = 0;
  do
  {
    if ( *cmdstart == 34 )
    {
      v10 = 34;
      ++cmdstart;
      v9 = !v9;
    }
    else
    {
      ++*numchars;
      if ( v6 )
        *v6++ = *cmdstart;
      v10 = *cmdstart++;
      if ( (unsigned int)ismbblead(v10) )
      {
        ++*numchars;
        if ( v6 )
          *v6++ = *cmdstart;
        ++cmdstart;
      }
      if ( !v10 )
      {
        --cmdstart;
        goto LABEL_19;
      }
    }
  }
  while ( v9 || v10 != 32 && v10 != 9 );
  if ( v6 )
    *(v6 - 1) = 0;
LABEL_19:
  v11 = 0;
  while ( *cmdstart )
  {
    while ( *cmdstart == 32 || *cmdstart == 9 )
      ++cmdstart;
    if ( !*cmdstart )
      break;
    if ( v7 )
      *v7++ = v6;
    ++*numargs;
    while ( 1 )
    {
      v12 = 1;
      v13 = 0;
      while ( *cmdstart == 92 )
      {
        ++cmdstart;
        ++v13;
      }
      if ( *cmdstart == 34 )
      {
        if ( (v13 & 1) == 0 )
        {
          if ( v11 && cmdstart[1] == 34 )
          {
            ++cmdstart;
          }
          else
          {
            v12 = 0;
            v11 = !v11;
          }
        }
        v13 >>= 1;
      }
      while ( v13 )
      {
        --v13;
        if ( v6 )
          *v6++ = 92;
        ++*numchars;
      }
      v14 = *cmdstart;
      if ( !*cmdstart || !v11 && (v14 == 32 || v14 == 9) )
        break;
      if ( v12 )
      {
        v15 = ismbblead(v14);
        if ( v6 )
        {
          if ( v15 )
          {
            v16 = *cmdstart++;
            *v6++ = v16;
            ++*numchars;
          }
          *v6++ = *cmdstart;
        }
        else if ( v15 )
        {
          ++cmdstart;
          ++*numchars;
        }
        ++*numchars;
      }
      ++cmdstart;
    }
    if ( v6 )
      *v6++ = 0;
    ++*numchars;
  }
  if ( v7 )
    *v7 = 0i64;
  ++*numargs;
}

