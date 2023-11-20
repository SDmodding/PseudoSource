// File Line: 43
// RVA: 0x12BCD64
__int64 __fastcall feof(_iobuf *stream)
{
  if ( stream )
    return stream->_flag & 0x10;
  *errno() = 22;
  invalid_parameter_noinfo();
  return 0i64;
}

// File Line: 70
// RVA: 0x12BCD8C
__int64 __fastcall ferror(_iobuf *stream)
{
  if ( stream )
    return stream->_flag & 0x20;
  *errno() = 22;
  invalid_parameter_noinfo();
  return 0i64;
}

