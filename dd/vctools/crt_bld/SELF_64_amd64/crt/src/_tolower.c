// File Line: 49
// RVA: 0x12DDA9C
__int64 __fastcall Tolower(int c, _Ctypevec *ploc)
{
  __int64 v3; // rbx
  unsigned __int16 *LocaleName; // rsi
  int code_page; // ebp
  __int64 result; // rax
  unsigned int v7; // edx
  int cchSrc; // eax
  int v9; // eax
  bool v10; // zf
  char SrcStr; // [rsp+78h] [rbp+10h] BYREF
  char v12; // [rsp+79h] [rbp+11h]
  char v13; // [rsp+7Ah] [rbp+12h]
  char DestStr; // [rsp+80h] [rbp+18h] BYREF
  unsigned __int8 v15; // [rsp+81h] [rbp+19h]

  v3 = c;
  if ( ploc )
  {
    LocaleName = ploc->_LocaleName;
    code_page = ploc->_Page;
  }
  else
  {
    LocaleName = __lc_locale_name_func()[2];
    code_page = __lc_codepage_func();
  }
  if ( !LocaleName )
  {
    if ( (unsigned int)(v3 - 65) <= 0x19 )
      LODWORD(v3) = v3 + 32;
    return (unsigned int)v3;
  }
  if ( (unsigned int)v3 < 0x100 )
  {
    if ( !ploc )
    {
      if ( !(unsigned int)isupper(v3) )
        return (unsigned int)v3;
      goto LABEL_14;
    }
    if ( (ploc->_Table[v3] & 1) == 0 )
      return (unsigned int)v3;
  }
  if ( !ploc )
  {
LABEL_14:
    v7 = _pctype_func()[BYTE1(v3)] & 0x8000;
    goto LABEL_16;
  }
  v7 = ((unsigned int)ploc->_Table[BYTE1(v3)] >> 15) & 1;
LABEL_16:
  if ( v7 )
  {
    v12 = v3;
    v13 = 0;
    SrcStr = BYTE1(v3);
    cchSrc = 2;
  }
  else
  {
    SrcStr = v3;
    v12 = 0;
    cchSrc = 1;
  }
  v9 = _crtLCMapStringA(0i64, LocaleName, 0x100u, &SrcStr, cchSrc, &DestStr, 3, code_page, 1);
  if ( !v9 )
    return (unsigned int)v3;
  v10 = v9 == 1;
  result = (unsigned __int8)DestStr;
  if ( !v10 )
    return v15 | ((unsigned __int8)DestStr << 8);
  return result;
}

// File Line: 138
// RVA: 0x12DDA20
_Ctypevec *Getctype(_Ctypevec *result, ...)
{
  const __int16 *v2; // rax
  const unsigned __int16 *v3; // rax
  const __int16 *v4; // rax
  wchar_t *v5; // rcx

  result->_Page = __lc_codepage_func();
  v2 = (const __int16 *)calloc_crt(0x100ui64, 2ui64);
  result->_Table = v2;
  if ( v2 )
  {
    v3 = _pctype_func();
    memmove((void *)result->_Table, v3, 0x200ui64);
    result->_Delfl = 1;
  }
  else
  {
    v4 = (const __int16 *)_pctype_func();
    result->_Delfl = 0;
    result->_Table = v4;
  }
  v5 = __lc_locale_name_func()[1];
  result->_LocaleName = v5;
  if ( v5 )
    result->_LocaleName = wcsdup(v5);
  return result;
}

