// File Line: 44
// RVA: 0x12BD4D8
__int64 __fastcall ungetc(int ch, _iobuf *stream)
{
  unsigned int v5; // edi

  if ( !stream )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  if ( (int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  lock_file(stream);
  v5 = ungetc_nolock(ch, stream);
  unlock_file(stream);
  return v5;
}

// File Line: 55
// RVA: 0x1451E59
ungetc$fin$0

