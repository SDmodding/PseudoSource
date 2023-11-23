// File Line: 43
// RVA: 0x13341C4
__int64 __fastcall fgetpos(_iobuf *stream, __int64 *pos)
{
  int v2; // ebx
  __int64 v5; // rax

  v2 = 0;
  if ( stream && pos )
  {
    v5 = ftelli64(stream);
    *pos = v5;
    LOBYTE(v2) = v5 != -1;
    return (unsigned int)(v2 - 1);
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
}

