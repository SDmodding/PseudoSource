// File Line: 43
// RVA: 0x13341C4
signed __int64 __fastcall fgetpos(_iobuf *stream, __int64 *pos)
{
  int v2; // ebx
  __int64 *v3; // rdi
  signed __int64 result; // rax
  __int64 v5; // rax

  v2 = 0;
  v3 = pos;
  if ( stream && pos )
  {
    v5 = ftelli64(stream);
    *v3 = v5;
    LOBYTE(v2) = v5 != -1;
    result = (unsigned int)(v2 - 1);
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0xFFFFFFFFi64;
  }
  return result;
}

