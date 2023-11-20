// File Line: 134
// RVA: 0x12DE110
_Cvtvec *Getcvt(_Cvtvec *result, ...)
{
  _Cvtvec *v1; // rdi
  BOOL v2; // ecx
  signed int v3; // ebx
  __int64 v4; // rsi

  result->_Page = 0;
  v1 = result;
  memset(&result->_Mbcurmax, 0, 0x28ui64);
  v1->_Page = __lc_codepage_func();
  v1->_Mbcurmax = __mb_cur_max_func();
  v2 = __lc_locale_name_func()[2] == 0i64;
  v1->_Isclocale = v2;
  if ( !v2 )
  {
    v3 = 0;
    v4 = 0i64;
    do
    {
      if ( (unsigned int)ismbblead(v3) )
        v1->_Isleadbyte[v4 >> 3] |= 1 << (v3 & 7);
      ++v3;
      ++v4;
    }
    while ( v3 < 256 );
  }
  return v1;
}

