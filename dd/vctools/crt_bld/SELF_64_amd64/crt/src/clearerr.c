// File Line: 36
// RVA: 0x12BCCA0
__int64 __fastcall clearerr_s(_iobuf *stream)
{
  __int64 v3; // rbx
  ioinfo *v4; // rcx

  if ( !stream )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22i64;
  }
  if ( (int)ioinit() < 0 )
    return 22i64;
  lock_file(stream);
  stream->_flag &= 0xFFFFFFCF;
  if ( (unsigned int)fileno(stream) == -1 || (unsigned int)fileno(stream) == -2 )
  {
    v4 = &_badioinfo;
  }
  else
  {
    v3 = (__int64)(int)fileno(stream) >> 5;
    v4 = &_pioinfo[v3][fileno(stream) & 0x1F];
  }
  v4->osfile &= ~2u;
  unlock_file(stream);
  return 0i64;
}

// File Line: 76
// RVA: 0x12BCC98
// attributes: thunk
void __fastcall clearerr(_iobuf *stream)
{
  clearerr_s(stream);
}

