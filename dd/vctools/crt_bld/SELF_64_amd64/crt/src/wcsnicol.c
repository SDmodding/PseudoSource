// File Line: 58
// RVA: 0x1334C3C
__int64 __fastcall wcsnicoll_l(
        const wchar_t *_string1,
        const wchar_t *_string2,
        unsigned __int64 count,
        localeinfo_struct *plocinfo)
{
  unsigned __int64 cchCount2; // rsi
  const wchar_t *lpString2; // rdi
  unsigned int v8; // ebx
  const wchar_t *v9; // rcx
  char *v10; // r14
  unsigned __int16 v11; // cx
  wchar_t v12; // dx
  int v13; // eax
  _LocaleUpdate v14; // [rsp+30h] [rbp-28h] BYREF

  cchCount2 = count;
  lpString2 = _string2;
  if ( !count )
    return 0i64;
  if ( _string1 && _string2 )
  {
    v8 = 0x7FFFFFFF;
    if ( count <= 0x7FFFFFFF )
    {
      _LocaleUpdate::_LocaleUpdate(&v14, plocinfo);
      v9 = v14.localeinfo.locinfo->locale_name[1];
      if ( v9 )
      {
        v13 = _crtCompareStringW(v9, 0x1001u, _string1, cchCount2, lpString2, cchCount2);
        if ( v13 )
          v8 = v13 - 2;
        else
          *errno() = 22;
      }
      else
      {
        v10 = (char *)((char *)_string1 - (char *)lpString2);
        do
        {
          v11 = *(const wchar_t *)((char *)lpString2 + (_QWORD)v10);
          if ( (unsigned __int16)(v11 - 65) <= 0x19u )
            v11 += 32;
          v12 = *lpString2;
          if ( (unsigned __int16)(*lpString2 - 65) <= 0x19u )
            v12 += 32;
          ++lpString2;
          --cchCount2;
        }
        while ( cchCount2 && v11 && v11 == v12 );
        v8 = v11 - v12;
      }
      if ( v14.updated )
        v14.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *errno() = 22;
      invalid_parameter_noinfo();
    }
    return v8;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0x7FFFFFFFi64;
  }
}

// File Line: 109
// RVA: 0x1334BA8
int __fastcall wcsnicoll(const wchar_t *_string1, const wchar_t *_string2, unsigned __int64 count)
{
  const wchar_t *v3; // r10
  signed __int64 v5; // r11
  unsigned __int16 v6; // dx
  wchar_t v7; // cx

  v3 = _string2;
  if ( _locale_changed )
    return wcsnicoll_l(_string1, _string2, count, 0i64);
  if ( _string1 && _string2 && count <= 0x7FFFFFFF )
  {
    v5 = (char *)_string1 - (char *)_string2;
    do
    {
      v6 = *(const wchar_t *)((char *)v3 + v5);
      if ( (unsigned __int16)(v6 - 65) <= 0x19u )
        v6 += 32;
      v7 = *v3;
      if ( (unsigned __int16)(*v3 - 65) <= 0x19u )
        v7 += 32;
      ++v3;
      --count;
    }
    while ( count && v6 && v6 == v7 );
    return v6 - v7;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
}

