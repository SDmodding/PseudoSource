// File Line: 50
// RVA: 0x12B9B1C
_iobuf *__fastcall wfsopen(const wchar_t *file, const wchar_t *mode, int shflag)
{
  int v3; // er14
  const wchar_t *v4; // rdi
  const wchar_t *v5; // rsi
  _iobuf *result; // rax
  _iobuf *v7; // rax
  _iobuf *v8; // rbx
  _iobuf *v9; // rdi
  __int64 v10; // [rsp+0h] [rbp-48h]
  __int64 *v11; // [rsp+20h] [rbp-28h]

  v11 = &v10;
  v3 = shflag;
  v4 = mode;
  v5 = file;
  if ( !file || mode == 0i64 || *mode == 0 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0i64;
  }
  v7 = getstream();
  v8 = v7;
  if ( !v7 )
  {
    *errno() = 24;
    return 0i64;
  }
  if ( *v5 )
  {
    v9 = wopenfile(v5, v4, v3, v7);
    unlock_file(v8);
    result = v9;
  }
  else
  {
    *errno() = 22;
    local_unwind(v11, &_LN14_121);
    result = 0i64;
  }
  return result;
}

// File Line: 90
// RVA: 0x1451D9F
_fsopen$fin$0

// File Line: 124
// RVA: 0x12B4748
_iobuf *__fastcall fopen(const char *file, const char *mode)
{
  return fsopen(file, mode, 64);
}

// File Line: 158
// RVA: 0x12B4754
signed __int64 __fastcall fopen_s(_iobuf **pfile, const char *file, const char *mode)
{
  _iobuf **v3; // rbx
  signed __int64 result; // rax
  _iobuf *v5; // rax

  v3 = pfile;
  if ( pfile )
  {
    v5 = fsopen(file, mode, 128);
    *v3 = v5;
    if ( v5 )
      result = 0i64;
    else
      result = (unsigned int)*errno();
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 22i64;
  }
  return result;
}

