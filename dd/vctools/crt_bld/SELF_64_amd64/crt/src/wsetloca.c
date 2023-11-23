// File Line: 120
// RVA: 0x12CAFE8
void __fastcall copytlocinfo_nolock(threadlocaleinfostruct *ptlocid, threadlocaleinfostruct *ptlocis)
{
  threadlocaleinfostruct *v3; // r8
  __int64 v4; // rax
  __int128 v5; // xmm1

  if ( ptlocis && ptlocid && ptlocid != ptlocis )
  {
    v3 = ptlocid;
    if ( (((unsigned __int8)ptlocid | (unsigned __int8)ptlocis) & 0xF) != 0 )
    {
      memmove(ptlocid, ptlocis, 0x158ui64);
    }
    else
    {
      v4 = 2i64;
      do
      {
        *(_OWORD *)&v3->refcount = *(_OWORD *)&ptlocis->refcount;
        *(_OWORD *)&v3->lc_category[0].locale = *(_OWORD *)&ptlocis->lc_category[0].locale;
        *(_OWORD *)&v3->lc_category[0].refcount = *(_OWORD *)&ptlocis->lc_category[0].refcount;
        v3->lc_category[1] = ptlocis->lc_category[1];
        v3->lc_category[2] = ptlocis->lc_category[2];
        v5 = *(_OWORD *)&ptlocis->lc_category[3].locale;
        v3 = (threadlocaleinfostruct *)((char *)v3 + 128);
        ptlocis = (threadlocaleinfostruct *)((char *)ptlocis + 128);
        *(_OWORD *)&v3[-1].locale_name[4] = v5;
        --v4;
      }
      while ( v4 );
      *(_OWORD *)&v3->refcount = *(_OWORD *)&ptlocis->refcount;
      *(_OWORD *)&v3->lc_category[0].locale = *(_OWORD *)&ptlocis->lc_category[0].locale;
      *(_OWORD *)&v3->lc_category[0].refcount = *(_OWORD *)&ptlocis->lc_category[0].refcount;
      v3->lc_category[1] = ptlocis->lc_category[1];
      v3->lc_category[2].locale = ptlocis->lc_category[2].locale;
    }
    ptlocid->refcount = 0;
    _addlocaleref(ptlocid);
  }
}

// File Line: 186
// RVA: 0x12CACC0
void locterm()
{
  if ( _ptlocinfo != &_initiallocinfo )
  {
    lock(12);
    _ptlocinfo = updatetlocinfoEx_nolock(&_ptlocinfo, &_initiallocinfo);
    unlock(12);
  }
}

// File Line: 193
// RVA: 0x14521EF
_locterm$fin$0

// File Line: 518
// RVA: 0x12CB4D0
unsigned __int16 *__fastcall wsetlocale(unsigned int _category, const wchar_t *_wlocale)
{
  unsigned __int16 *v4; // rsi
  _tiddata *v6; // rbx
  threadlocaleinfostruct *v7; // rdi
  int v8; // eax
  int v9; // ecx

  v4 = 0i64;
  if ( _category <= 5 )
  {
    v6 = getptd();
    _updatetlocinfo();
    v6->_ownlocale |= 0x10u;
    v7 = (threadlocaleinfostruct *)calloc_crt(0x158ui64, 1ui64);
    if ( v7 )
    {
      lock(12);
      copytlocinfo_nolock(v7, v6->ptlocinfo);
      unlock(12);
      v4 = wsetlocale_nolock(v7, _category, _wlocale);
      if ( v4 )
      {
        if ( _wlocale )
        {
          v8 = wcscmp(_wlocale, _wclocalestr);
          v9 = _locale_changed;
          if ( v8 )
            v9 = 1;
          _locale_changed = v9;
        }
        lock(12);
        updatetlocinfoEx_nolock(&v6->ptlocinfo, v7);
        _removelocaleref(v7);
        if ( (v6->_ownlocale & 2) == 0 && (_globallocalestatus & 1) == 0 )
        {
          updatetlocinfoEx_nolock(&_ptlocinfo, v6->ptlocinfo);
          _lconv = _ptlocinfo->lconv;
          pctype = _ptlocinfo->pctype;
          _mb_cur_max = _ptlocinfo->mb_cur_max;
        }
        unlock(12);
      }
      else
      {
        _removelocaleref(v7);
        _freetlocinfo(v7);
      }
    }
    v6->_ownlocale &= ~0x10u;
    return v4;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0i64;
  }
}

// File Line: 549
// RVA: 0x1452208
_wsetlocale$fin$1

// File Line: 577
// RVA: 0x1452223
_wsetlocale$fin$0

// File Line: 585
// RVA: 0x145223E
_wsetlocale$fin$2

// File Line: 598
// RVA: 0x12CB840
unsigned __int16 *__fastcall wsetlocale_nolock(threadlocaleinfostruct *ploci, int _category, const wchar_t *_wlocale)
{
  const wchar_t *v3; // rbx
  threadlocaleinfostruct *v4; // rdi
  unsigned __int16 *result; // rax
  int v6; // ebp
  int v7; // esi
  unsigned __int16 *v8; // rax
  unsigned __int16 *v9; // r14
  __int64 v10; // rbp
  int v11; // r12d
  $DE8E99F9213A3D28DF318243291B2EE2 *v12; // r15
  const wchar_t *v13; // r14
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rbx
  const wchar_t *v16; // rbx
  int v17; // ebx
  const wchar_t **p_wlocale; // r14
  wchar_t _Dst[136]; // [rsp+30h] [rbp-208h] BYREF
  unsigned __int16 localeNameOutput[88]; // [rsp+140h] [rbp-F8h] BYREF

  v3 = _wlocale;
  v4 = ploci;
  if ( _category )
  {
    if ( _wlocale )
      return wsetlocale_set_cat(ploci, _category, _wlocale);
    else
      return ploci->lc_category[_category].wlocale;
  }
  v6 = 1;
  v7 = 0;
  if ( !_wlocale )
    return (unsigned __int16 *)wsetlocale_get_all(ploci);
  if ( *_wlocale != 76 || _wlocale[1] != 67 || _wlocale[2] != 95 )
  {
    result = (unsigned __int16 *)expandlocale(
                                   _wlocale,
                                   (char *)_Dst,
                                   0x83ui64,
                                   (char *)localeNameOutput,
                                   0x55ui64,
                                   0i64);
    if ( !result )
      return result;
    v17 = 0;
    p_wlocale = (const wchar_t **)&v4->lc_category[0].wlocale;
    do
    {
      if ( v17 )
      {
        if ( !wcscmp(_Dst, *p_wlocale) || wsetlocale_set_cat(v4, v17, _Dst) )
          ++v7;
        else
          v6 = 0;
      }
      ++v17;
      p_wlocale += 4;
    }
    while ( v17 <= 5 );
    if ( !v6 )
    {
LABEL_25:
      if ( !v7 )
        return 0i64;
    }
    ploci = v4;
    return (unsigned __int16 *)wsetlocale_get_all(ploci);
  }
  while ( 1 )
  {
    v8 = wcspbrk(v3, L"=;");
    v9 = v8;
    if ( !v8 )
      return 0i64;
    v10 = v8 - v3;
    if ( !v10 || *v8 == 59 )
      return 0i64;
    v11 = 1;
    v12 = &_lc_category[1];
    do
    {
      if ( !(unsigned int)wcsncmp(v12->catname, v3, v10) && v10 == wcslen(v12->catname) )
        break;
      ++v12;
      ++v11;
    }
    while ( (__int64)v12 <= (__int64)&_lc_category[5] );
    v13 = v9 + 1;
    v14 = wcscspn(v13, L";");
    v15 = v14;
    if ( !v14 && *v13 != 59 )
      return 0i64;
    if ( v11 <= 5 )
    {
      if ( (unsigned int)wcsncpy_s((char *)_Dst, 0x83ui64, v13, v14) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        JUMPOUT(0x1412CBAA9i64);
      }
      if ( 2 * v15 >= 0x106 )
      {
        _report_rangecheckfailure();
        __debugbreak();
      }
      _Dst[v15] = 0;
      if ( wsetlocale_set_cat(v4, v11, _Dst) )
        ++v7;
    }
    v16 = &v13[v15];
    if ( *v16 )
    {
      v3 = v16 + 1;
      if ( *v3 )
        continue;
    }
    goto LABEL_25;
  }
}

// File Line: 706
// RVA: 0x12CBAAC
unsigned __int16 *__fastcall wsetlocale_set_cat(threadlocaleinfostruct *ploci, int category, const wchar_t *wlocale)
{
  __int64 v4; // r12
  _is_ctype_compatible *Loc_c; // r14
  __int64 v8; // rbx
  unsigned __int64 v9; // r15
  char *v10; // rax
  char *v11; // r13
  bool v12; // zf
  int v13; // r8d
  __int64 v14; // rdx
  _is_ctype_compatible v15; // rcx
  _is_ctype_compatible v16; // rax
  int v17; // edx
  unsigned __int16 *v18; // rcx
  unsigned int cp; // [rsp+40h] [rbp-C0h] BYREF
  unsigned int lc_codepage; // [rsp+44h] [rbp-BCh]
  wchar_t *v21; // [rsp+48h] [rbp-B8h]
  wchar_t *v22; // [rsp+50h] [rbp-B0h]
  unsigned __int16 output[136]; // [rsp+60h] [rbp-A0h] BYREF
  unsigned __int16 CharType[128]; // [rsp+170h] [rbp+70h] BYREF
  unsigned __int16 localeNameOutput[88]; // [rsp+270h] [rbp+170h] BYREF

  v4 = category;
  Loc_c = getptd()->_setloc_data._Loc_c;
  if ( !expandlocale(wlocale, (char *)output, 0x83ui64, (char *)localeNameOutput, 0x55ui64, &cp) )
    return 0i64;
  v8 = v4;
  if ( wcscmp(output, ploci->lc_category[v4].wlocale) )
  {
    v9 = wcslen(output);
    v10 = (char *)malloc_crt(2 * v9 + 6);
    v11 = v10;
    if ( v10 )
    {
      v21 = ploci->lc_category[v8].wlocale;
      v22 = ploci->locale_name[v4];
      lc_codepage = ploci->lc_codepage;
      if ( (unsigned int)wcscpy_s(v10 + 4, v9 + 1, output) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        JUMPOUT(0x1412CBDB9i64);
      }
      v12 = output[0] == 67;
      ploci->lc_category[v8].wlocale = (wchar_t *)(v11 + 4);
      if ( !v12 || output[1] )
        ploci->locale_name[v4] = (wchar_t *)_copy_locale_name(localeNameOutput);
      else
        ploci->locale_name[v4] = 0i64;
      switch ( (_DWORD)v4 )
      {
        case 2:
          v13 = 0;
          v14 = 0i64;
          ploci->lc_codepage = cp;
          v15 = Loc_c[4];
          while ( ploci->lc_codepage != Loc_c[v14].id )
          {
            v16 = Loc_c[v14];
            Loc_c[v14++] = v15;
            ++v13;
            v15 = v16;
            if ( v14 >= 5 )
              goto LABEL_18;
          }
          if ( v13 )
          {
            *Loc_c = Loc_c[v13];
            Loc_c[v13] = v15;
          }
LABEL_18:
          if ( v13 == 5 )
          {
            if ( _crtGetStringTypeA(0i64, 1u, first_127char, 127, CharType, ploci->lc_codepage, 1) )
            {
              v17 = 0;
              v18 = CharType;
              do
              {
                ++v17;
                *v18++ &= 0x1FFu;
              }
              while ( (unsigned __int64)v17 < 0x7F );
              Loc_c->is_clike = memcmp(CharType, ctype_loc_style, 0xFEui64) == 0;
            }
            else
            {
              Loc_c->is_clike = 0;
            }
            Loc_c->id = ploci->lc_codepage;
          }
          ploci->lc_clike = Loc_c->is_clike;
          break;
        case 1:
          ploci->lc_collate_cp = cp;
          break;
        case 5:
          ploci->lc_time_cp = cp;
          break;
      }
      if ( !_lc_category[v4].init(ploci) )
      {
        if ( v21 != _wclocalestr && !_InterlockedDecrement(ploci->lc_category[v8].wrefcount) )
        {
          free(ploci->lc_category[v8].wrefcount);
          free(ploci->lc_category[v8].refcount);
          free(ploci->locale_name[v4]);
          ploci->lc_category[v8].wlocale = 0i64;
          ploci->locale_name[v4] = 0i64;
        }
        *(_DWORD *)v11 = 1;
        ploci->lc_category[v8].wrefcount = (int *)v11;
        return ploci->lc_category[v8].wlocale;
      }
      ploci->lc_category[v8].wlocale = v21;
      free(ploci->locale_name[v4]);
      ploci->locale_name[v4] = v22;
      free(v11);
      ploci->lc_codepage = lc_codepage;
    }
    return 0i64;
  }
  return ploci->lc_category[v8].wlocale;
}

// File Line: 857
// RVA: 0x12CB66C
char *__fastcall wsetlocale_get_all(threadlocaleinfostruct *ploci)
{
  int v2; // ebp
  char *result; // rax
  unsigned __int16 *v4; // rsi
  char *v5; // r14
  $DE8E99F9213A3D28DF318243291B2EE2 *v6; // r15
  const wchar_t **p_wlocale; // r12
  int v8; // eax
  int *v9; // rcx
  int *v10; // rax
  int *wrefcount; // rcx
  int *refcount; // rcx

  v2 = 1;
  result = (char *)malloc_crt(0x6A6ui64);
  v4 = (unsigned __int16 *)result;
  if ( result )
  {
    v5 = result + 4;
    *((_WORD *)result + 2) = 0;
    *(_DWORD *)result = 1;
    wcscats(result + 4, 0x351ui64, 3, _lc_category[1].catname, L"=", ploci->lc_category[1].wlocale);
    v6 = &_lc_category[1];
    p_wlocale = (const wchar_t **)&ploci->lc_category[1].wlocale;
    do
    {
      if ( (unsigned int)wcscat_s(v5, 0x351ui64, L";") )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
      }
      v8 = wcscmp(*p_wlocale, p_wlocale[4]);
      p_wlocale += 4;
      if ( v8 )
        v2 = 0;
      ++v6;
      wcscats(v5, 0x351ui64, 3, v6->catname, L"=", *p_wlocale);
    }
    while ( (__int64)v6 < (__int64)&_lc_category[5] );
    if ( v2 )
    {
      free(v4);
      wrefcount = ploci->lc_category[0].wrefcount;
      if ( wrefcount && _InterlockedExchangeAdd(wrefcount, 0xFFFFFFFF) == 1 )
        free(ploci->lc_category[0].wrefcount);
      refcount = ploci->lc_category[0].refcount;
      if ( refcount && _InterlockedExchangeAdd(refcount, 0xFFFFFFFF) == 1 )
        free(ploci->lc_category[0].refcount);
      result = (char *)ploci->lc_category[2].wlocale;
      ploci->lc_category[0].refcount = 0i64;
      ploci->lc_category[0].locale = 0i64;
      ploci->lc_category[0].wrefcount = 0i64;
      ploci->lc_category[0].wlocale = 0i64;
    }
    else
    {
      v9 = ploci->lc_category[0].wrefcount;
      if ( v9 && _InterlockedExchangeAdd(v9, 0xFFFFFFFF) == 1 )
        free(ploci->lc_category[0].wrefcount);
      v10 = ploci->lc_category[0].refcount;
      if ( v10 )
      {
        if ( _InterlockedExchangeAdd(v10, 0xFFFFFFFF) == 1 )
          free(ploci->lc_category[0].refcount);
      }
      ploci->lc_category[0].refcount = 0i64;
      ploci->lc_category[0].locale = 0i64;
      ploci->lc_category[0].wrefcount = (int *)v4;
      ploci->lc_category[0].wlocale = (wchar_t *)v5;
      return v5;
    }
  }
  return result;
}

// File Line: 931
// RVA: 0x12CB0C8
char *__fastcall expandlocale(
        const wchar_t *expr,
        char *output,
        unsigned __int64 sizeInChars,
        char *localeNameOutput,
        unsigned __int64 localeNameSizeInChars,
        unsigned int *cp)
{
  _tiddata *v10; // rax
  char *cachein; // r12
  char *cacheout; // rbp
  char *cacheLocaleName; // r13
  unsigned __int64 v15; // r14
  unsigned __int64 v16; // rax
  int v17; // eax
  UINT ACP; // eax
  int v19; // eax
  unsigned __int64 v20; // rax
  unsigned __int16 LCData[2]; // [rsp+30h] [rbp-248h] BYREF
  unsigned int *lpOutCodePage; // [rsp+38h] [rbp-240h]
  char *v23; // [rsp+40h] [rbp-238h]
  unsigned __int64 _SizeInWords; // [rsp+48h] [rbp-230h]
  tagLC_STRINGS names; // [rsp+50h] [rbp-228h] BYREF

  _SizeInWords = sizeInChars;
  v10 = getptd();
  cachein = (char *)v10->_setloc_data._cachein;
  cacheout = (char *)v10->_setloc_data._cacheout;
  lpOutCodePage = &v10->_setloc_data._cachecp;
  v23 = (char *)v10->_setloc_data._cachein;
  *(_DWORD *)LCData = 0;
  if ( !expr )
    return 0i64;
  cacheLocaleName = (char *)v10->_setloc_data._cacheLocaleName;
  if ( (unsigned int)wcsncpy_s(localeNameOutput, localeNameSizeInChars, v10->_setloc_data._cacheLocaleName, 0x55ui64) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    JUMPOUT(0x1412CB466i64);
  }
  if ( *expr != 67 || expr[1] )
  {
    v15 = wcslen(expr);
    if ( v15 < 0x83 && (!wcscmp((const wchar_t *)cacheout, expr) || !wcscmp((const wchar_t *)cachein, expr)) )
    {
      localeNameOutput = 0i64;
    }
    else
    {
      if ( (unsigned int)_lc_wcstolc(&names, expr) || !_get_qualified_locale(&names, lpOutCodePage, &names) )
      {
        if ( !_crtIsValidLocaleName(expr) )
        {
          v20 = wcslen((const wchar_t *)localeNameOutput);
          if ( (unsigned int)wcsncpy_s(cacheLocaleName, 0x55ui64, (const wchar_t *)localeNameOutput, v20 + 1) )
          {
            invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
            __debugbreak();
          }
          return 0i64;
        }
        if ( !_crtGetLocaleInfoEx(expr, 0x20001004u, LCData, 2) || (LOWORD(ACP) = LCData[0], !*(_DWORD *)LCData) )
        {
          ACP = GetACP();
          *(_DWORD *)LCData = ACP;
        }
        *lpOutCodePage = (unsigned __int16)ACP;
        if ( (unsigned int)wcsncpy_s(cacheout, 0x83ui64, expr, v15 + 1) )
        {
          invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
          __debugbreak();
        }
        v19 = wcsncpy_s(localeNameOutput, localeNameSizeInChars, expr, v15 + 1);
        localeNameOutput = 0i64;
        if ( v19 )
        {
          invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
          __debugbreak();
        }
        if ( (unsigned int)wcsncpy_s(cacheLocaleName, 0x55ui64, expr, v15 + 1) )
        {
          invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
          __debugbreak();
        }
        cachein = v23;
      }
      else
      {
        _lc_lctowcs(cacheout, 0x83ui64, &names);
        if ( localeNameOutput )
        {
          v16 = wcslen(names.szLocaleName);
          v17 = wcsncpy_s(localeNameOutput, localeNameSizeInChars, names.szLocaleName, v16 + 1);
          localeNameOutput = 0i64;
          if ( v17 )
          {
            invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
            __debugbreak();
          }
        }
      }
      if ( *expr == (_WORD)localeNameOutput || v15 >= 0x83 )
      {
        *(_WORD *)cachein = (_WORD)localeNameOutput;
      }
      else if ( (unsigned int)wcsncpy_s(cachein, 0x83ui64, expr, v15 + 1) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, (unsigned __int64)localeNameOutput);
        __debugbreak();
      }
    }
    if ( cp )
      memmove(cp, lpOutCodePage, 4ui64);
    if ( (unsigned int)wcscpy_s(output, _SizeInWords, (const wchar_t *)cacheout) )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, (unsigned __int64)localeNameOutput);
      __debugbreak();
    }
    return cacheout;
  }
  else
  {
    if ( (unsigned int)wcscpy_s(output, sizeInChars, L"C") )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
    }
    if ( cp )
      *cp = 0;
    return output;
  }
}

// File Line: 1030
// RVA: 0x12CB468
void wcscats(char *outstr, unsigned __int64 numberOfElements, int n, ...)
{
  int v3; // ebx
  const wchar_t **v5; // rdi
  __int64 v7; // [rsp+0h] [rbp-58h] BYREF

  if ( n > 0 )
  {
    v3 = 0;
    v5 = (const wchar_t **)(&v7 + 14);
    do
    {
      if ( (unsigned int)wcscat_s(outstr, numberOfElements, *++v5) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        JUMPOUT(0x1412CB4CCi64);
      }
      ++v3;
    }
    while ( v3 < n );
  }
}

// File Line: 1044
// RVA: 0x12CAE30
__int64 __fastcall _lc_wcstolc(tagLC_STRINGS *names, const wchar_t *wlocale)
{
  int i; // ebp
  unsigned __int64 v6; // rax
  const wchar_t *v7; // r14
  wchar_t v8; // di

  memset(names, 0, sizeof(tagLC_STRINGS));
  if ( !*wlocale )
    return 0i64;
  if ( *wlocale == 46 && wlocale[1] )
  {
    if ( (unsigned int)wcsncpy_s((char *)names->szCodePage, 0x10ui64, wlocale + 1, 0xFui64) )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
    }
    names->szCodePage[15] = 0;
    return 0i64;
  }
  for ( i = 0; ; ++i )
  {
    v6 = wcscspn(wlocale, L"_.,");
    if ( !v6 )
      break;
    v7 = &wlocale[v6];
    v8 = *v7;
    if ( i )
    {
      if ( i == 1 )
      {
        if ( v6 >= 0x40 || v8 == 95 )
          return 0xFFFFFFFFi64;
        if ( (unsigned int)wcsncpy_s((char *)names->szCountry, 0x40ui64, wlocale, v6) )
        {
          invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
          __debugbreak();
        }
      }
      else
      {
        if ( i != 2 || v6 >= 0x10 || v8 && v8 != 44 )
          return 0xFFFFFFFFi64;
        if ( (unsigned int)wcsncpy_s((char *)names->szCodePage, 0x10ui64, wlocale, v6) )
        {
          invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
          JUMPOUT(0x1412CAFE4i64);
        }
      }
    }
    else
    {
      if ( v6 >= 0x40 || v8 == 46 )
        return 0xFFFFFFFFi64;
      if ( (unsigned int)wcsncpy_s((char *)names, 0x40ui64, wlocale, v6) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
      }
    }
    if ( v8 == 44 || !v8 )
      return 0i64;
    wlocale = v7 + 1;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 1098
// RVA: 0x12CAD8C
void __fastcall _lc_lctowcs(char *locale, unsigned __int64 numberOfElements, tagLC_STRINGS *names)
{
  if ( (unsigned int)wcscpy_s(locale, numberOfElements, names->szLanguage) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    JUMPOUT(0x1412CAE2Di64);
  }
  if ( names->szCountry[0] )
    wcscats((unsigned __int16 *)locale, numberOfElements, 2, L"_", names->szCountry);
  if ( names->szCodePage[0] )
    wcscats((unsigned __int16 *)locale, numberOfElements, 2, L".", names->szCodePage);
}

// File Line: 1108
// RVA: 0x12CAD08
char *__fastcall _copy_locale_name(const wchar_t *localeName)
{
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rsi
  char *v5; // rax
  char *v6; // rbx

  if ( !localeName )
    return 0i64;
  v3 = wcsnlen(localeName, 0x55ui64);
  v4 = v3;
  if ( v3 >= 0x55 )
    return 0i64;
  v5 = (char *)malloc_crt(2 * v3 + 2);
  v6 = v5;
  if ( !v5 )
    return 0i64;
  if ( (unsigned int)wcsncpy_s(v5, v4 + 1, localeName, v4 + 1) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    JUMPOUT(0x1412CAD89i64);
  }
  return v6;
}

