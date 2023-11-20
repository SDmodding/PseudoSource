// File Line: 44
// RVA: 0x12BBDA8
unsigned __int64 __fastcall memchr(const void *buf, int chr, unsigned __int64 cnt)
{
  for ( ; cnt; --cnt )
  {
    if ( *(_BYTE *)buf == (_BYTE)chr )
      break;
    buf = (char *)buf + 1;
  }
  return (unsigned __int64)buf & -(signed __int64)(cnt != 0);
}

