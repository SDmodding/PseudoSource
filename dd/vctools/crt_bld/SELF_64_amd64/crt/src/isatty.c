// File Line: 37
// RVA: 0x12BB9DC
__int64 __fastcall isatty(int fh)
{
  __int64 v1; // rbx

  v1 = fh;
  if ( fh == -2 )
  {
    *errno() = 9;
  }
  else
  {
    if ( (int)ioinit() < 0 )
      return 0xFFFFFFFFi64;
    if ( (int)v1 >= 0 && (unsigned int)v1 < nhandle )
      return _pioinfo[v1 >> 5][v1 & 0x1F].osfile & 0x40;
    *errno() = 9;
    invalid_parameter_noinfo();
  }
  return 0i64;
}

