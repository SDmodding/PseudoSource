// File Line: 120
// RVA: 0x12CAFE8
void __fastcall copytlocinfo_nolock(threadlocaleinfostruct *ptlocid, threadlocaleinfostruct *ptlocis)
{
  threadlocaleinfostruct *v2; // rbx
  threadlocaleinfostruct *v3; // r8
  signed __int64 v4; // rax
  __int128 v5; // xmm1

  if ( ptlocis )
  {
    v2 = ptlocid;
    if ( ptlocid )
    {
      if ( ptlocid != ptlocis )
      {
        v3 = ptlocid;
        if ( ((unsigned __int8)ptlocid | (unsigned __int8)ptlocis) & 0xF )
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
            *(_OWORD *)&v3->lc_category[1].locale = *(_OWORD *)&ptlocis->lc_category[1].locale;
            *(_OWORD *)&v3->lc_category[1].refcount = *(_OWORD *)&ptlocis->lc_category[1].refcount;
            *(_OWORD *)&v3->lc_category[2].locale = *(_OWORD *)&ptlocis->lc_category[2].locale;
            *(_OWORD *)&v3->lc_category[2].refcount = *(_OWORD *)&ptlocis->lc_category[2].refcount;
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
          *(_OWORD *)&v3->lc_category[1].locale = *(_OWORD *)&ptlocis->lc_category[1].locale;
          *(_OWORD *)&v3->lc_category[1].refcount = *(_OWORD *)&ptlocis->lc_category[1].refcount;
          v3->lc_category[2].locale = ptlocis->lc_category[2].locale;
        }
        v2->refcount = 0;
        _addlocaleref(v2);
      }
    }
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
unsigned __int16 *__fastcall wsetlocale(int _category, const wchar_t *_wlocale)
{
  const wchar_t *v2; // r14
  int v3; // er12
  unsigned __int16 *v4; // rsi
  unsigned __int16 *result; // rax
  _tiddata *v6; // rbx
  threadlocaleinfostruct *v7; // rdi
  int v8; // eax
  signed int v9; // ecx

  v2 = _wlocale;
  v3 = _category;
  v4 = 0i64;
  if ( (unsigned int)_category <= 5 )
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
      v4 = wsetlocale_nolock(v7, v3, v2);
      if ( v4 )
      {
        if ( v2 )
        {
          v8 = wcscmp(v2, _wclocalestr);
          v9 = _locale_changed;
          if ( v8 )
            v9 = 1;
          _locale_changed = v9;
        }
        lock(12);
        updatetlocinfoEx_nolock(&v6->ptlocinfo, v7);
        _removelocaleref(v7);
        if ( !(v6->_ownlocale & 2) && !(_globallocalestatus & 1) )
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
    v6->_ownlocale &= 0xFFFFFFEF;
    result = v4;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 0i64;
  }
  return result;
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
  signed int v6; // ebp
  int v7; // esi
  unsigned __int16 *v8; // rax
  unsigned __int16 *v9; // r14
  unsigned __int64 v10; // rbp
  int v11; // er12
  $DE8E99F9213A3D28DF318243291B2EE2 *v12; // r15
  const wchar_t *v13; // r14
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // rbx
  const wchar_t *v16; // rbx
  int v17; // ebx
  const wchar_t **v18; // r14
  unsigned __int16 _Dst[136]; // [rsp+30h] [rbp-208h]
  unsigned __int16 localeNameOutput; // [rsp+140h] [rbp-F8h]

  v3 = _wlocale;
  v4 = ploci;
  if ( _category )
  {
    if ( _wlocale )
      result = wsetlocale_set_cat(ploci, _category, _wlocale);
    else
      result = ploci->lc_category[_category].wlocale;
    return result;
  }
  v6 = 1;
  v7 = 0;
  if ( !_wlocale )
    return wsetlocale_get_all(ploci);
  if ( *(_DWORD *)_wlocale != 4390988 || _wlocale[2] != 95 )
  {
    result = expandlocale(_wlocale, _Dst, 0x83ui64, &localeNameOutput, 0x55ui64, 0i64);
    if ( !result )
      return result;
    v17 = 0;
    v18 = (const wchar_t **)&v4->lc_category[0].wlocale;
    do
    {
      if ( v17 )
      {
        if ( !wcscmp(_Dst, *v18) || wsetlocale_set_cat(v4, v17, _Dst) )
          ++v7;
        else
          v6 = 0;
      }
      ++v17;
      v18 += 4;
    }
    while ( v17 <= 5 );
    if ( !v6 )
    {
LABEL_24:
      if ( !v7 )
        return 0i64;
    }
    ploci = v4;
    return wsetlocale_get_all(ploci);
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
    while ( (signed __int64)v12 <= (signed __int64)&_lc_category[5] );
    v13 = v9 + 1;
    v14 = wcscspn(v13, L";");
    v15 = v14;
    if ( !v14 && *v13 != 59 )
      return 0i64;
    if ( v11 <= 5 )
    {
      if ( (unsigned int)wcsncpy_s(_Dst, 0x83ui64, v13, v14) )
        goto LABEL_41;
      if ( 2 * v15 >= 0x106 )
      {
        _report_rangecheckfailure();
        __debugbreak();
LABEL_41:
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        JUMPOUT(*(_QWORD *)&byte_1412CBAA9);
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
    goto LABEL_24;
  }
}

// File Line: 706
// RVA: 0x12CBAAC
unsigned __int16 *__fastcall wsetlocale_set_cat(threadlocaleinfostruct *ploci, int category, const wchar_t *wlocale)
{
  const wchar_t *v3; // rbx
  signed __int64 v4; // r12
  threadlocaleinfostruct *v5; // rdi
  _is_ctype_compatible *v6; // r14
  signed __int64 v8; // rbx
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // r15
  void *v11; // rax
  _DWORD *v12; // r13
  bool v13; // zf
  int v14; // er8
  signed __int64 v15; // rdx
  _is_ctype_compatible v16; // rcx
  _is_ctype_compatible v17; // rax
  int v18; // edx
  unsigned __int16 *v19; // rcx
  unsigned int cp; // [rsp+40h] [rbp-C0h]
  unsigned int v21; // [rsp+44h] [rbp-BCh]
  wchar_t *v22; // [rsp+48h] [rbp-B8h]
  wchar_t *v23; // [rsp+50h] [rbp-B0h]
  unsigned __int16 output; // [rsp+60h] [rbp-A0h]
  __int16 v25; // [rsp+62h] [rbp-9Eh]
  unsigned __int16 CharType; // [rsp+170h] [rbp+70h]
  unsigned __int16 localeNameOutput; // [rsp+270h] [rbp+170h]

  v3 = wlocale;
  v4 = category;
  v5 = ploci;
  v6 = getptd()->_setloc_data._Loc_c;
  if ( !expandlocale(v3, &output, 0x83ui64, &localeNameOutput, 0x55ui64, &cp) )
    return 0i64;
  v8 = v4;
  if ( wcscmp(&output, v5->lc_category[v4].wlocale) )
  {
    v9 = wcslen(&output);
    v10 = v9;
    v11 = malloc_crt(2 * v9 + 6);
    v12 = v11;
    if ( v11 )
    {
      v22 = v5->lc_category[v8].wlocale;
      v23 = v5->locale_name[v4];
      v21 = v5->lc_codepage;
      if ( (unsigned int)wcscpy_s((unsigned __int16 *)v11 + 2, v10 + 1, &output) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        JUMPOUT(*(_QWORD *)&byte_1412CBDB9);
      }
      v13 = output == 67;
      v5->lc_category[v8].wlocale = (wchar_t *)(v12 + 1);
      if ( !v13 || v25 )
        v5->locale_name[v4] = _copy_locale_name(&localeNameOutput);
      else
        v5->locale_name[v4] = 0i64;
      switch ( (_DWORD)v4 )
      {
        case 2:
          v14 = 0;
          v15 = 0i64;
          v5->lc_codepage = cp;
          v16 = v6[4];
          while ( v5->lc_codepage != v6[v15].id )
          {
            v17 = v6[v15];
            v6[v15++] = v16;
            ++v14;
            v16 = v17;
            if ( v15 >= 5 )
              goto LABEL_19;
          }
          if ( v14 )
          {
            *v6 = v6[v14];
            v6[v14] = v16;
          }
LABEL_19:
          if ( v14 == 5 )
          {
            if ( _crtGetStringTypeA(0i64, 1u, first_127char, 127, &CharType, v5->lc_codepage, 1) )
            {
              v18 = 0;
              v19 = &CharType;
              do
              {
                ++v18;
                *v19 &= 0x1FFu;
                ++v19;
              }
              while ( (unsigned __int64)v18 < 0x7F );
              v6->is_clike = memcmp(&CharType, ctype_loc_style, 0xFEui64) == 0;
            }
            else
            {
              v6->is_clike = 0;
            }
            v6->id = v5->lc_codepage;
          }
          v5->lc_clike = v6->is_clike;
          break;
        case 1:
          v5->lc_collate_cp = cp;
          break;
        case 5:
          v5->lc_time_cp = cp;
          break;
      }
      if ( !_lc_category[v4].init(v5) )
      {
        if ( v22 != _wclocalestr && !_InterlockedDecrement(v5->lc_category[v8].wrefcount) )
        {
          free(v5->lc_category[v8].wrefcount);
          free(v5->lc_category[v8].refcount);
          free(v5->locale_name[v4]);
          v5->lc_category[v8].wlocale = 0i64;
          v5->locale_name[v4] = 0i64;
        }
        *v12 = 1;
        v5->lc_category[v8].wrefcount = v12;
        return v5->lc_category[v8].wlocale;
      }
      v5->lc_category[v8].wlocale = v22;
      free(v5->locale_name[v4]);
      v5->locale_name[v4] = v23;
      free(v12);
      v5->lc_codepage = v21;
    }
    return 0i64;
  }
  return v5->lc_category[v8].wlocale;
}

// File Line: 857
// RVA: 0x12CB66C
unsigned __int16 *__fastcall wsetlocale_get_all(threadlocaleinfostruct *ploci)
{
  threadlocaleinfostruct *v1; // rdi
  signed int v2; // ebp
  unsigned __int16 *result; // rax
  unsigned __int16 *v4; // rsi
  unsigned __int16 *v5; // r14
  $DE8E99F9213A3D28DF318243291B2EE2 *v6; // r15
  const wchar_t **v7; // r12
  int v8; // eax
  volatile signed __int32 *v9; // rcx
  volatile signed __int32 *v10; // rax
  volatile signed __int32 *v11; // rcx
  volatile signed __int32 *v12; // rcx

  v1 = ploci;
  v2 = 1;
  result = (unsigned __int16 *)malloc_crt(0x6A6ui64);
  v4 = result;
  if ( result )
  {
    v5 = result + 2;
    result[2] = 0;
    *(_DWORD *)result = 1;
    wcscats(result + 2, 0x351ui64, 3, _lc_category[1].catname, L"=", v1->lc_category[1].wlocale);
    v6 = &_lc_category[1];
    v7 = (const wchar_t **)&v1->lc_category[1].wlocale;
    do
    {
      if ( (unsigned int)wcscat_s(v5, 0x351ui64, L";") )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
        JUMPOUT(*(_QWORD *)wsetlocale_nolock);
      }
      v8 = wcscmp(*v7, v7[4]);
      v7 += 4;
      if ( v8 )
        v2 = 0;
      ++v6;
      wcscats(v5, 0x351ui64, 3, v6->catname, L"=", *v7);
    }
    while ( (signed __int64)v6 < (signed __int64)&_lc_category[5] );
    if ( v2 )
    {
      free(v4);
      v11 = v1->lc_category[0].wrefcount;
      if ( v11 && _InterlockedExchangeAdd(v11, 0xFFFFFFFF) == 1 )
        free(v1->lc_category[0].wrefcount);
      v12 = v1->lc_category[0].refcount;
      if ( v12 && _InterlockedExchangeAdd(v12, 0xFFFFFFFF) == 1 )
        free(v1->lc_category[0].refcount);
      result = v1->lc_category[2].wlocale;
      v1->lc_category[0].refcount = 0i64;
      v1->lc_category[0].locale = 0i64;
      v1->lc_category[0].wrefcount = 0i64;
      v1->lc_category[0].wlocale = 0i64;
    }
    else
    {
      v9 = v1->lc_category[0].wrefcount;
      if ( v9 && _InterlockedExchangeAdd(v9, 0xFFFFFFFF) == 1 )
        free(v1->lc_category[0].wrefcount);
      v10 = v1->lc_category[0].refcount;
      if ( v10 )
      {
        if ( _InterlockedExchangeAdd(v10, 0xFFFFFFFF) == 1 )
          free(v1->lc_category[0].refcount);
      }
      v1->lc_category[0].refcount = 0i64;
      v1->lc_category[0].locale = 0i64;
      v1->lc_category[0].wrefcount = (int *)v4;
      v1->lc_category[0].wlocale = v5;
      result = v5;
    }
  }
  return result;
}

// File Line: 931
// RVA: 0x12CB0C8
unsigned __int16 *__fastcall expandlocale(const wchar_t *expr, unsigned __int16 *output, unsigned __int64 sizeInChars, unsigned __int16 *localeNameOutput, unsigned __int64 localeNameSizeInChars, unsigned int *cp)
{
  unsigned __int16 *pReserved; // rsi
  unsigned __int64 v7; // r14
  unsigned __int16 *v8; // r15
  const wchar_t *v9; // rbx
  _tiddata *v10; // rax
  unsigned __int16 *v11; // r12
  unsigned __int16 *v12; // rbp
  unsigned __int16 *v14; // r13
  int v15; // eax
  const wchar_t *v16; // rcx
  unsigned __int64 v17; // r14
  unsigned __int64 v18; // rax
  int v19; // eax
  UINT v20; // eax
  int v21; // eax
  const wchar_t *v22; // rcx
  int v23; // eax
  unsigned __int64 v24; // rax
  unsigned __int16 LCData[2]; // [rsp+30h] [rbp-248h]
  unsigned int *lpOutCodePage; // [rsp+38h] [rbp-240h]
  unsigned __int16 *v27; // [rsp+40h] [rbp-238h]
  unsigned __int64 _SizeInWords; // [rsp+48h] [rbp-230h]
  tagLC_STRINGS names; // [rsp+50h] [rbp-228h]

  pReserved = localeNameOutput;
  v7 = sizeInChars;
  _SizeInWords = sizeInChars;
  v8 = output;
  v9 = expr;
  v10 = getptd();
  v11 = v10->_setloc_data._cachein;
  v12 = v10->_setloc_data._cacheout;
  lpOutCodePage = &v10->_setloc_data._cachecp;
  v27 = v10->_setloc_data._cachein;
  *(_DWORD *)LCData = 0;
  if ( !v9 )
    return 0i64;
  v14 = v10->_setloc_data._cacheLocaleName;
  v15 = wcsncpy_s(pReserved, localeNameSizeInChars, v10->_setloc_data._cacheLocaleName, 0x55ui64);
  v16 = 0i64;
  if ( v15 )
  {
LABEL_47:
    invoke_watson(v16, 0i64, 0i64, 0, (unsigned __int64)v16);
    JUMPOUT(*(_QWORD *)&byte_1412CB466);
  }
  if ( *v9 != 67 || v9[1] )
  {
    v17 = wcslen(v9);
    if ( v17 < 0x83 && (!wcscmp(v12, v9) || !wcscmp(v11, v9)) )
    {
      pReserved = 0i64;
    }
    else
    {
      if ( (unsigned int)_lc_wcstolc(&names, v9) || !_get_qualified_locale(&names, lpOutCodePage, &names) )
      {
        v11 = 0i64;
        if ( !_crtIsValidLocaleName(v9) )
        {
          v24 = wcslen(pReserved);
          if ( !(unsigned int)wcsncpy_s(v14, 0x55ui64, pReserved, v24 + 1) )
            return 0i64;
          goto LABEL_46;
        }
        if ( !_crtGetLocaleInfoEx(v9, 0x20001004u, LCData, 2) || (LOWORD(v20) = LCData[0], !*(_DWORD *)LCData) )
        {
          v20 = GetACP();
          *(_DWORD *)LCData = v20;
        }
        v11 = (unsigned __int16 *)(v17 + 1);
        *lpOutCodePage = (unsigned __int16)v20;
        v21 = wcsncpy_s(v12, 0x83ui64, v9, v17 + 1);
        v22 = 0i64;
        if ( v21 )
        {
LABEL_45:
          invoke_watson(v22, 0i64, 0i64, 0, (unsigned __int64)v22);
          __debugbreak();
LABEL_46:
          invoke_watson(0i64, 0i64, 0i64, 0, (unsigned __int64)v11);
          __debugbreak();
          goto LABEL_47;
        }
        v23 = wcsncpy_s(pReserved, localeNameSizeInChars, v9, v17 + 1);
        pReserved = 0i64;
        if ( v23 )
        {
LABEL_44:
          invoke_watson(0i64, 0i64, 0i64, 0, (unsigned __int64)pReserved);
          __debugbreak();
          goto LABEL_45;
        }
        if ( (unsigned int)wcsncpy_s(v14, 0x55ui64, v9, v17 + 1) )
        {
LABEL_43:
          invoke_watson(0i64, 0i64, 0i64, 0, (unsigned __int64)pReserved);
          __debugbreak();
          goto LABEL_44;
        }
        v11 = v27;
      }
      else
      {
        _lc_lctowcs(v12, 0x83ui64, &names);
        if ( pReserved )
        {
          v18 = wcslen(names.szLocaleName);
          v19 = wcsncpy_s(pReserved, localeNameSizeInChars, names.szLocaleName, v18 + 1);
          pReserved = 0i64;
          if ( v19 )
            goto LABEL_40;
        }
      }
      if ( *v9 == (_WORD)pReserved || v17 >= 0x83 )
      {
        *v11 = (unsigned __int16)pReserved;
      }
      else if ( (unsigned int)wcsncpy_s(v11, 0x83ui64, v9, v17 + 1) )
      {
        goto LABEL_41;
      }
    }
    if ( cp )
      memmove(cp, lpOutCodePage, 4ui64);
    if ( !(unsigned int)wcscpy_s(v8, _SizeInWords, v12) )
      return v12;
    goto LABEL_42;
  }
  if ( (unsigned int)wcscpy_s(v8, v7, L"C") )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
LABEL_40:
    invoke_watson(0i64, 0i64, 0i64, 0, (unsigned __int64)pReserved);
    __debugbreak();
LABEL_41:
    invoke_watson(0i64, 0i64, 0i64, 0, (unsigned __int64)pReserved);
    __debugbreak();
LABEL_42:
    invoke_watson(0i64, 0i64, 0i64, 0, (unsigned __int64)pReserved);
    __debugbreak();
    goto LABEL_43;
  }
  if ( cp )
    *cp = 0;
  return v8;
}

// File Line: 1030
// RVA: 0x12CB468
void wcscats(unsigned __int16 *outstr, unsigned __int64 numberOfElements, int n, ...)
{
  int v3; // ebx
  unsigned __int64 v4; // rsi
  const wchar_t **v5; // rdi
  unsigned __int16 *v6; // rbp
  __int64 v7; // [rsp+0h] [rbp-58h]
  int v8; // [rsp+70h] [rbp+18h]

  if ( n > 0 )
  {
    v8 = n;
    v3 = 0;
    v4 = numberOfElements;
    v5 = (const wchar_t **)(&v7 + 14);
    v6 = outstr;
    do
    {
      ++v5;
      if ( (unsigned int)wcscat_s(v6, v4, *v5) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        JUMPOUT(*(_QWORD *)&byte_1412CB4CC);
      }
      ++v3;
    }
    while ( v3 < v8 );
  }
}

// File Line: 1044
// RVA: 0x12CAE30
signed __int64 __fastcall _lc_wcstolc(tagLC_STRINGS *names, const wchar_t *wlocale)
{
  const wchar_t *v2; // rbx
  tagLC_STRINGS *v3; // rsi
  int i; // ebp
  unsigned __int64 v6; // rax
  const wchar_t *v7; // r14
  wchar_t v8; // di

  v2 = wlocale;
  v3 = names;
  memset(names, 0, 0x1CAui64);
  if ( !*v2 )
    return 0i64;
  if ( *v2 == 46 && v2[1] )
  {
    if ( (unsigned int)wcsncpy_s(v3->szCodePage, 0x10ui64, v2 + 1, 0xFui64) )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
LABEL_30:
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
LABEL_31:
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
LABEL_32:
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      JUMPOUT(*(_QWORD *)&byte_1412CAFE4);
    }
    v3->szCodePage[15] = 0;
    return 0i64;
  }
  for ( i = 0; ; ++i )
  {
    v6 = wcscspn(v2, L"_.,");
    if ( !v6 )
      break;
    v7 = &v2[v6];
    v8 = *v7;
    if ( i )
    {
      if ( i == 1 )
      {
        if ( v6 >= 0x40 || v8 == 95 )
          return 0xFFFFFFFFi64;
        if ( (unsigned int)wcsncpy_s(v3->szCountry, 0x40ui64, v2, v6) )
          goto LABEL_31;
      }
      else
      {
        if ( i != 2 || v6 >= 0x10 || v8 && v8 != 44 )
          return 0xFFFFFFFFi64;
        if ( (unsigned int)wcsncpy_s(v3->szCodePage, 0x10ui64, v2, v6) )
          goto LABEL_32;
      }
    }
    else
    {
      if ( v6 >= 0x40 || v8 == 46 )
        return 0xFFFFFFFFi64;
      if ( (unsigned int)wcsncpy_s(v3->szLanguage, 0x40ui64, v2, v6) )
        goto LABEL_30;
    }
    if ( v8 == 44 || !v8 )
      return 0i64;
    v2 = v7 + 1;
  }
  return 0xFFFFFFFFi64;
}

// File Line: 1098
// RVA: 0x12CAD8C
void __fastcall _lc_lctowcs(unsigned __int16 *locale, unsigned __int64 numberOfElements, tagLC_STRINGS *names)
{
  tagLC_STRINGS *v3; // rbx
  unsigned __int64 v4; // rdi
  unsigned __int16 *v5; // rsi

  v3 = names;
  v4 = numberOfElements;
  v5 = locale;
  if ( (unsigned int)wcscpy_s(locale, numberOfElements, names->szLanguage) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    JUMPOUT(*(_QWORD *)&byte_1412CAE2D);
  }
  if ( v3->szCountry[0] )
    wcscats(v5, v4, 2, L"_", v3->szCountry);
  if ( v3->szCodePage[0] )
    wcscats(v5, v4, 2, L".", v3->szCodePage);
}

// File Line: 1108
// RVA: 0x12CAD08
unsigned __int16 *__fastcall _copy_locale_name(const wchar_t *localeName)
{
  const wchar_t *v1; // rdi
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rsi
  unsigned __int16 *v5; // rax
  unsigned __int16 *v6; // rbx

  v1 = localeName;
  if ( !localeName )
    return 0i64;
  v3 = wcsnlen(localeName, 0x55ui64);
  v4 = v3;
  if ( v3 >= 0x55 )
    return 0i64;
  v5 = (unsigned __int16 *)malloc_crt(2 * v3 + 2);
  v6 = v5;
  if ( !v5 )
    return 0i64;
  if ( (unsigned int)wcsncpy_s(v5, v4 + 1, v1, v4 + 1) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    JUMPOUT(*(_QWORD *)&byte_1412CAD89);
  }
  return v6;
}

