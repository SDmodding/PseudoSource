// File Line: 24
// RVA: 0x12BEE40
char *__fastcall setlocale(int _category, const char *_locale)
{
  __int64 v3; // r12
  wchar_t *v4; // rbx
  int v5; // eax
  wchar_t *v6; // rax
  int v8; // eax
  wchar_t *v9; // rcx
  const wchar_t *v10; // rdi
  _tiddata *v11; // r13
  int v12; // eax
  char *v13; // rax
  int *v14; // rsi
  char *v15; // r15
  int v16; // eax
  threadlocaleinfostruct *locinfo; // rdi
  __int64 v18; // rbx
  volatile signed __int32 *refcount; // rcx
  volatile signed __int32 *v20; // rcx
  localeinfo_struct plocinfo; // [rsp+30h] [rbp-28h] BYREF
  unsigned __int64 count; // [rsp+68h] [rbp+10h] BYREF

  v3 = _category;
  count = 0i64;
  v4 = 0i64;
  if ( _locale )
  {
    v5 = mbstowcs_s(&count, 0i64, 0i64, _locale, 0x7FFFFFFFui64);
    if ( v5 == 22 || v5 == 34 )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
    }
    v6 = (wchar_t *)calloc_crt(count, 2ui64);
    v4 = v6;
    if ( !v6 )
      return 0i64;
    v8 = mbstowcs_s(0i64, v6, count, _locale, 0xFFFFFFFFFFFFFFFFui64);
    if ( v8 == 22 || v8 == 34 )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
    }
    if ( v8 )
    {
      v9 = v4;
LABEL_10:
      free(v9);
      return 0i64;
    }
  }
  v10 = wsetlocale(v3, v4);
  free(v4);
  if ( !v10 )
    return 0i64;
  v11 = getptd();
  plocinfo.locinfo = v11->ptlocinfo;
  plocinfo.mbcinfo = v11->ptmbcinfo;
  count = 0i64;
  v12 = wcstombs_s_l(&count, 0i64, 0i64, v10, 0i64, &plocinfo);
  if ( v12 == 22 || v12 == 34 )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
  }
  if ( v12 )
    return 0i64;
  v13 = (char *)malloc_crt(count + 4);
  v14 = (int *)v13;
  if ( !v13 )
    return 0i64;
  v15 = v13 + 4;
  v16 = wcstombs_s_l(0i64, v13 + 4, count, v10, 0xFFFFFFFFFFFFFFFFui64, &plocinfo);
  if ( v16 == 22 || v16 == 34 )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
  }
  if ( v16 )
  {
    v9 = (wchar_t *)v14;
    goto LABEL_10;
  }
  locinfo = plocinfo.locinfo;
  lock(12);
  v18 = v3;
  refcount = locinfo->lc_category[v3].refcount;
  if ( refcount && !_InterlockedDecrement(refcount) )
    free(locinfo->lc_category[v18].refcount);
  if ( (v11->_ownlocale & 2) == 0 && (_globallocalestatus & 1) == 0 )
  {
    v20 = locinfo->lc_category[v18].refcount;
    if ( v20 )
    {
      if ( !_InterlockedDecrement(v20) )
        free(locinfo->lc_category[v18].refcount);
    }
  }
  *v14 = locinfo->refcount;
  locinfo->lc_category[v18].refcount = v14;
  locinfo->lc_category[v18].locale = v15;
  unlock(12);
  return v15;
}

// File Line: 118
// RVA: 0x1451EA5
setlocale$fin$0

