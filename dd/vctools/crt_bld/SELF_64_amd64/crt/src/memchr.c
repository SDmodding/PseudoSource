// File Line: 44
// RVA: 0x12BBDA8
unsigned __int64 __fastcall memchr(unsigned __int64 buf, char chr, unsigned __int64 cnt)
{
  for ( ; cnt; --cnt )
  {
    if ( *(_BYTE *)buf == chr )
      break;
    ++buf;
  }
  return buf & -(__int64)(cnt != 0);
}

