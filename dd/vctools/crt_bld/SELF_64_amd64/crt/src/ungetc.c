// File Line: 44
// RVA: 0x12BD4D8
signed __int64 __fastcall ungetc(int ch, _iobuf *stream)
{
  _iobuf *v2; // rbx
  int v3; // edi
  unsigned int v5; // edi

  v2 = stream;
  v3 = ch;
  if ( !stream )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  if ( (signed int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  lock_file(v2);
  v5 = ungetc_nolock(v3, v2);
  unlock_file(v2);
  return v5;
}

// File Line: 55
// RVA: 0x1451E59
ungetc$fin$0

