// File Line: 36
// RVA: 0x12BCCA0
signed __int64 __fastcall clearerr_s(_iobuf *stream)
{
  _iobuf *v1; // rdi
  signed __int64 v3; // rbx
  ioinfo *v4; // rcx

  v1 = stream;
  if ( !stream )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22i64;
  }
  if ( (signed int)ioinit() < 0 )
    return 22i64;
  lock_file(v1);
  v1->_flag &= 0xFFFFFFCF;
  if ( (unsigned int)fileno(v1) == -1 || (unsigned int)fileno(v1) == -2 )
  {
    v4 = &_badioinfo;
  }
  else
  {
    v3 = (signed __int64)(signed int)fileno(v1) >> 5;
    v4 = &_pioinfo[v3][fileno(v1) & 0x1F];
  }
  v4->osfile &= 0xFDu;
  unlock_file(v1);
  return 0i64;
}

// File Line: 76
// RVA: 0x12BCC98
void __fastcall clearerr(_iobuf *stream)
{
  clearerr_s(stream);
}

