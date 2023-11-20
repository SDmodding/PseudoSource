// File Line: 24
// RVA: 0x12BEE40
void __fastcall setlocale(int _category, const char *_locale)
{
  const char *v2; // rdi
  signed __int64 v3; // r12
  unsigned __int64 pReserved; // r15
  wchar_t *v5; // rbx
  int v6; // eax
  wchar_t *v7; // rax
  int v8; // eax
  wchar_t *v9; // rcx
  const wchar_t *v10; // rdi
  _tiddata *v11; // rax
  _tiddata *v12; // r13
  int v13; // eax
  char *v14; // rax
  int *v15; // rsi
  int v16; // eax
  threadlocaleinfostruct *v17; // rdi
  signed __int64 v18; // rbx
  volatile signed __int32 *v19; // rcx
  volatile signed __int32 *v20; // rcx
  localeinfo_struct plocinfo; // [rsp+30h] [rbp-28h]
  unsigned __int64 count; // [rsp+68h] [rbp+10h]

  v2 = _locale;
  v3 = _category;
  pReserved = 0i64;
  count = 0i64;
  v5 = 0i64;
  if ( !_locale )
    goto LABEL_13;
  v6 = mbstowcs_s(&count, 0i64, 0i64, _locale, 0x7FFFFFFFui64);
  if ( v6 == 22 || v6 == 34 )
  {
LABEL_12:
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
    goto LABEL_13;
  }
  v7 = (wchar_t *)calloc_crt(count, 2ui64);
  v5 = v7;
  if ( !v7 )
    return;
  v8 = mbstowcs_s(0i64, v7, count, v2, 0xFFFFFFFFFFFFFFFFui64);
  if ( v8 == 22 || v8 == 34 )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
    goto LABEL_12;
  }
  if ( v8 )
  {
    v9 = v5;
LABEL_10:
    free(v9);
    return;
  }
LABEL_13:
  v10 = wsetlocale(v3, v5);
  free(v5);
  if ( !v10 )
    return;
  v11 = getptd();
  v12 = v11;
  plocinfo.locinfo = v11->ptlocinfo;
  plocinfo.mbcinfo = v11->ptmbcinfo;
  count = 0i64;
  v13 = wcstombs_s_l(&count, 0i64, 0i64, v10, 0i64, &plocinfo);
  if ( v13 == 22 || v13 == 34 )
  {
LABEL_33:
    invoke_watson(0i64, 0i64, 0i64, 0, pReserved);
    __debugbreak();
    return;
  }
  if ( v13 )
    return;
  v14 = (char *)malloc_crt(count + 4);
  v15 = (int *)v14;
  if ( !v14 )
    return;
  pReserved = (unsigned __int64)(v14 + 4);
  v16 = wcstombs_s_l(0i64, v14 + 4, count, v10, 0xFFFFFFFFFFFFFFFFui64, &plocinfo);
  if ( v16 == 22 || v16 == 34 )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
    goto LABEL_33;
  }
  if ( v16 )
  {
    v9 = (wchar_t *)v15;
    goto LABEL_10;
  }
  v17 = plocinfo.locinfo;
  lock(12);
  v18 = v3;
  v19 = v17->lc_category[v3].refcount;
  if ( v19 && !_InterlockedDecrement(v19) )
    free(v17->lc_category[v18].refcount);
  if ( !(v12->_ownlocale & 2) && !(_globallocalestatus & 1) )
  {
    v20 = v17->lc_category[v18].refcount;
    if ( v20 )
    {
      if ( !_InterlockedDecrement(v20) )
        free(v17->lc_category[v18].refcount);
    }
  }
  *v15 = v17->refcount;
  v17->lc_category[v18].refcount = v15;
  v17->lc_category[v18].locale = (char *)pReserved;
  unlock(12);
}

// File Line: 118
// RVA: 0x1451EA5
setlocale$fin$0

