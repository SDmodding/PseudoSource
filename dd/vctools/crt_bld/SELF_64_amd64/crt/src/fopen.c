// File Line: 50
// RVA: 0x12B9B1C
_iobuf *__fastcall wfsopen(const wchar_t *file, const wchar_t *mode, int shflag)
{
  _iobuf *v7; // rax
  _iobuf *v8; // rbx
  _iobuf *v9; // rdi
  __int64 v10; // [rsp+0h] [rbp-48h] BYREF
  __int64 *v11; // [rsp+20h] [rbp-28h]

  v11 = &v10;
  if ( !file || !mode || !*mode )
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
  if ( *file )
  {
    v9 = wopenfile(file, mode, shflag, v7);
    unlock_file(v8);
    return v9;
  }
  else
  {
    *errno() = 22;
    local_unwind(v11, &_LN14_121);
    return 0i64;
  }
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
__int64 __fastcall fopen_s(_iobuf **pfile, const char *file, const char *mode)
{
  _iobuf *v5; // rax

  if ( pfile )
  {
    v5 = fsopen(file, mode, 128);
    *pfile = v5;
    if ( v5 )
      return 0i64;
    else
      return (unsigned int)*errno();
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22i64;
  }
}

