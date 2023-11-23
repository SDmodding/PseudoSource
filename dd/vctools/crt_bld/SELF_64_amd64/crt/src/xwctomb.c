// File Line: 134
// RVA: 0x12DE110
_Cvtvec *Getcvt(_Cvtvec *result, ...)
{
  int v2; // ecx
  int v3; // ebx
  __int64 v4; // rsi

  result->_Page = 0;
  memset(&result->_Mbcurmax, 0, 0x28ui64);
  result->_Page = __lc_codepage_func();
  result->_Mbcurmax = __mb_cur_max_func();
  v2 = __lc_locale_name_func()[2] == 0i64;
  result->_Isclocale = v2;
  if ( !v2 )
  {
    v3 = 0;
    v4 = 0i64;
    do
    {
      if ( (unsigned int)ismbblead(v3) )
        result->_Isleadbyte[v4 >> 3] |= 1 << (v3 & 7);
      ++v3;
      ++v4;
    }
    while ( v3 < 256 );
  }
  return result;
}

