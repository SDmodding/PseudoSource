// File Line: 40
// RVA: 0x12BB9B4
__int64 __fastcall fileno(_iobuf *stream)
{
  if ( stream )
    return (unsigned int)stream->_file;
  *errno() = 22;
  invalid_parameter_noinfo();
  return 0xFFFFFFFFi64;
}

