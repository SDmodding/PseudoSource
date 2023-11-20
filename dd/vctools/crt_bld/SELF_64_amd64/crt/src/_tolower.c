// File Line: 49
// RVA: 0x12DDA9C
__int64 __fastcall Tolower(int c, _Ctypevec *ploc)
{
  _Ctypevec *v2; // rdi
  __int64 v3; // rbx
  wchar_t *v4; // rsi
  int code_page; // ebp
  __int64 result; // rax
  unsigned int v7; // edx
  int cchSrc; // eax
  int v9; // eax
  bool v10; // zf
  char SrcStr; // [rsp+78h] [rbp+10h]
  char v12; // [rsp+79h] [rbp+11h]
  char v13; // [rsp+7Ah] [rbp+12h]
  char DestStr; // [rsp+80h] [rbp+18h]
  unsigned __int8 v15; // [rsp+81h] [rbp+19h]

  v2 = ploc;
  v3 = c;
  if ( ploc )
  {
    v4 = ploc->_LocaleName;
    code_page = ploc->_Page;
  }
  else
  {
    v4 = __lc_locale_name_func()[2];
    code_page = __lc_codepage_func();
  }
  if ( !v4 )
  {
    if ( (unsigned int)(v3 - 65) <= 0x19 )
      LODWORD(v3) = v3 + 32;
    return (unsigned int)v3;
  }
  if ( (unsigned int)v3 < 0x100 )
  {
    if ( !v2 )
    {
      if ( !(unsigned int)isupper(v3) )
        return (unsigned int)v3;
      goto LABEL_14;
    }
    if ( !(v2->_Table[v3] & 1) )
      return (unsigned int)v3;
  }
  if ( !v2 )
  {
LABEL_14:
    v7 = _pctype_func()[BYTE1(v3)] & 0x8000;
    goto LABEL_16;
  }
  v7 = ((unsigned int)(signed __int16)v2->_Table[BYTE1(v3)] >> 15) & 1;
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
  v9 = _crtLCMapStringA(0i64, v4, 0x100u, &SrcStr, cchSrc, &DestStr, 3, code_page, 1);
  if ( !v9 )
    return (unsigned int)v3;
  v10 = v9 == 1;
  result = (unsigned __int8)DestStr;
  if ( !v10 )
    result = v15 | ((unsigned int)(unsigned __int8)DestStr << 8);
  return result;
}

// File Line: 138
// RVA: 0x12DDA20
_Ctypevec *Getctype(_Ctypevec *result, ...)
{
  _Ctypevec *v1; // rbx
  const __int16 *v2; // rax
  const unsigned __int16 *v3; // rax
  const unsigned __int16 *v4; // rax
  const wchar_t *v5; // rcx

  v1 = result;
  result->_Page = __lc_codepage_func();
  v2 = (const __int16 *)calloc_crt(0x100ui64, 2ui64);
  v1->_Table = v2;
  if ( v2 )
  {
    v3 = _pctype_func();
    memmove((void *)v1->_Table, v3, 0x200ui64);
    v1->_Delfl = 1;
  }
  else
  {
    v4 = _pctype_func();
    v1->_Delfl = 0;
    v1->_Table = (const __int16 *)v4;
  }
  v5 = __lc_locale_name_func()[1];
  v1->_LocaleName = (wchar_t *)v5;
  if ( v5 )
    v1->_LocaleName = wcsdup(v5);
  return v1;
}

