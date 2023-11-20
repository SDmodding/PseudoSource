// File Line: 88
// RVA: 0x12D1BAC
signed __int64 __fastcall setargv()
{
  char *v0; // rbx
  __int64 v1; // rsi
  char **v2; // rax
  char **v3; // rdi
  int numargs; // [rsp+40h] [rbp+8h]
  int numchars; // [rsp+48h] [rbp+10h]

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
  if ( (unsigned __int64)numchars >= 0xFFFFFFFFFFFFFFFFui64 )
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
  int *v5; // r12
  char *v6; // rdi
  char **v7; // r15
  char *v8; // rbx
  BOOL v9; // ebp
  unsigned int v10; // esi
  BOOL v11; // esi
  signed int v12; // edx
  unsigned int v13; // ecx
  char v14; // al
  int v15; // eax
  char v16; // al

  v5 = numargs;
  v6 = args;
  *numchars = 0;
  v7 = argv;
  v8 = cmdstart;
  *numargs = 1;
  if ( argv )
  {
    *argv = args;
    v7 = argv + 1;
  }
  v9 = 0;
  do
  {
    if ( *v8 == 34 )
    {
      LOBYTE(v10) = 34;
      ++v8;
      v9 = v9 == 0;
    }
    else
    {
      ++*numchars;
      if ( v6 )
        *v6++ = *v8;
      v10 = (unsigned __int8)*v8++;
      if ( (unsigned int)ismbblead(v10) )
      {
        ++*numchars;
        if ( v6 )
          *v6++ = *v8;
        ++v8;
      }
      if ( !(_BYTE)v10 )
      {
        --v8;
        goto LABEL_19;
      }
    }
  }
  while ( v9 || (_BYTE)v10 != 32 && (_BYTE)v10 != 9 );
  if ( v6 )
    *(v6 - 1) = 0;
LABEL_19:
  v11 = 0;
  while ( *v8 )
  {
    while ( *v8 == 32 || *v8 == 9 )
      ++v8;
    if ( !*v8 )
      break;
    if ( v7 )
    {
      *v7 = v6;
      ++v7;
    }
    ++*v5;
    while ( 1 )
    {
      v12 = 1;
      v13 = 0;
      while ( *v8 == 92 )
      {
        ++v8;
        ++v13;
      }
      if ( *v8 == 34 )
      {
        if ( !(v13 & 1) )
        {
          if ( v11 && v8[1] == 34 )
          {
            ++v8;
          }
          else
          {
            v12 = 0;
            v11 = v11 == 0;
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
      v14 = *v8;
      if ( !*v8 || !v11 && (v14 == 32 || v14 == 9) )
        break;
      if ( v12 )
      {
        v15 = ismbblead(v14);
        if ( v6 )
        {
          if ( v15 )
          {
            v16 = *v8++;
            *v6++ = v16;
            ++*numchars;
          }
          *v6++ = *v8;
        }
        else if ( v15 )
        {
          ++v8;
          ++*numchars;
        }
        ++*numchars;
      }
      ++v8;
    }
    if ( v6 )
      *v6++ = 0;
    ++*numchars;
  }
  if ( v7 )
    *v7 = 0i64;
  ++*v5;
}

