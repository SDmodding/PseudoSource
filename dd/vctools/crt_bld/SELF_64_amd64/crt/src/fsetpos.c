// File Line: 41
// RVA: 0x1334210
signed __int64 __fastcall fsetpos(_iobuf *stream, const __int64 *pos)
{
  if ( stream && pos )
    return fseeki64(stream, *pos, 0);
  *errno() = 22;
  invalid_parameter_noinfo();
  return 0xFFFFFFFFi64;
}

