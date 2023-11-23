// File Line: 36
// RVA: 0x12C8E34
void __fastcall _addlocaleref(threadlocaleinfostruct *ptloci)
{
  int *lconv_intl_refcount; // rax
  int *lconv_mon_refcount; // rax
  int *lconv_num_refcount; // rax
  int *ctype1_refcount; // rax
  int **p_wrefcount; // rax
  __int64 v6; // r8
  volatile signed __int32 *v7; // rdx

  _InterlockedIncrement(&ptloci->refcount);
  lconv_intl_refcount = ptloci->lconv_intl_refcount;
  if ( lconv_intl_refcount )
    _InterlockedIncrement(lconv_intl_refcount);
  lconv_mon_refcount = ptloci->lconv_mon_refcount;
  if ( lconv_mon_refcount )
    _InterlockedIncrement(lconv_mon_refcount);
  lconv_num_refcount = ptloci->lconv_num_refcount;
  if ( lconv_num_refcount )
    _InterlockedIncrement(lconv_num_refcount);
  ctype1_refcount = ptloci->ctype1_refcount;
  if ( ctype1_refcount )
    _InterlockedIncrement(ctype1_refcount);
  p_wrefcount = &ptloci->lc_category[0].wrefcount;
  v6 = 6i64;
  do
  {
    if ( *(p_wrefcount - 2) != (int *)_wclocalestr && *p_wrefcount )
      _InterlockedIncrement(*p_wrefcount);
    if ( *(p_wrefcount - 3) )
    {
      v7 = *(p_wrefcount - 1);
      if ( v7 )
        _InterlockedIncrement(v7);
    }
    p_wrefcount += 4;
    --v6;
  }
  while ( v6 );
  _InterlockedIncrement(&ptloci->lc_time_curr->refcount);
}

// File Line: 74
// RVA: 0x12C9058
threadlocaleinfostruct *__fastcall _removelocaleref(threadlocaleinfostruct *ptloci)
{
  int *lconv_intl_refcount; // rax
  int *lconv_mon_refcount; // rax
  int *lconv_num_refcount; // rax
  int *ctype1_refcount; // rax
  int **p_wrefcount; // rax
  __int64 v6; // r8
  volatile signed __int32 *v7; // rdx

  if ( ptloci )
  {
    _InterlockedAdd(&ptloci->refcount, 0xFFFFFFFF);
    lconv_intl_refcount = ptloci->lconv_intl_refcount;
    if ( lconv_intl_refcount )
      _InterlockedAdd(lconv_intl_refcount, 0xFFFFFFFF);
    lconv_mon_refcount = ptloci->lconv_mon_refcount;
    if ( lconv_mon_refcount )
      _InterlockedAdd(lconv_mon_refcount, 0xFFFFFFFF);
    lconv_num_refcount = ptloci->lconv_num_refcount;
    if ( lconv_num_refcount )
      _InterlockedAdd(lconv_num_refcount, 0xFFFFFFFF);
    ctype1_refcount = ptloci->ctype1_refcount;
    if ( ctype1_refcount )
      _InterlockedAdd(ctype1_refcount, 0xFFFFFFFF);
    p_wrefcount = &ptloci->lc_category[0].wrefcount;
    v6 = 6i64;
    do
    {
      if ( *(p_wrefcount - 2) != (int *)_wclocalestr && *p_wrefcount )
        _InterlockedAdd(*p_wrefcount, 0xFFFFFFFF);
      if ( *(p_wrefcount - 3) )
      {
        v7 = *(p_wrefcount - 1);
        if ( v7 )
          _InterlockedAdd(v7, 0xFFFFFFFF);
      }
      p_wrefcount += 4;
      --v6;
    }
    while ( v6 );
    _InterlockedAdd(&ptloci->lc_time_curr->refcount, 0xFFFFFFFF);
  }
  return ptloci;
}

// File Line: 129
// RVA: 0x12C8EC0
void __fastcall _freetlocinfo(threadlocaleinfostruct *ptloci)
{
  lconv *lconv; // rax
  int *lconv_intl_refcount; // rax
  int *lconv_mon_refcount; // rcx
  int *lconv_num_refcount; // rcx
  int *ctype1_refcount; // rax
  __lc_time_data *lc_time_curr; // rcx
  void **locale_name; // rsi
  int **p_wrefcount; // rdi
  __int64 v10; // rbp
  int *v11; // rcx
  _DWORD *v12; // rcx

  lconv = ptloci->lconv;
  if ( lconv )
  {
    if ( lconv != &_lconv_c )
    {
      lconv_intl_refcount = ptloci->lconv_intl_refcount;
      if ( lconv_intl_refcount )
      {
        if ( !*lconv_intl_refcount )
        {
          lconv_mon_refcount = ptloci->lconv_mon_refcount;
          if ( lconv_mon_refcount && !*lconv_mon_refcount )
          {
            free(lconv_mon_refcount);
            _free_lconv_mon(ptloci->lconv);
          }
          lconv_num_refcount = ptloci->lconv_num_refcount;
          if ( lconv_num_refcount && !*lconv_num_refcount )
          {
            free(lconv_num_refcount);
            _free_lconv_num(ptloci->lconv);
          }
          free(ptloci->lconv_intl_refcount);
          free(ptloci->lconv);
        }
      }
    }
  }
  ctype1_refcount = ptloci->ctype1_refcount;
  if ( ctype1_refcount && !*ctype1_refcount )
  {
    free(ptloci->ctype1 - 127);
    free((void *)(ptloci->pclmap - 128));
    free((void *)(ptloci->pcumap - 128));
    free(ptloci->ctype1_refcount);
  }
  lc_time_curr = ptloci->lc_time_curr;
  if ( lc_time_curr != &_lc_time_c && !lc_time_curr->refcount )
  {
    _free_lc_time(lc_time_curr);
    free(ptloci->lc_time_curr);
  }
  locale_name = (void **)ptloci->locale_name;
  p_wrefcount = &ptloci->lc_category[0].wrefcount;
  v10 = 6i64;
  do
  {
    if ( *(p_wrefcount - 2) != (int *)_wclocalestr )
    {
      v11 = *p_wrefcount;
      if ( *p_wrefcount )
      {
        if ( !*v11 )
        {
          free(v11);
          free(*locale_name);
        }
      }
    }
    if ( *(p_wrefcount - 3) )
    {
      v12 = *(p_wrefcount - 1);
      if ( v12 )
      {
        if ( !*v12 )
          free(v12);
      }
    }
    ++locale_name;
    p_wrefcount += 4;
    --v10;
  }
  while ( v10 );
  free(ptloci);
}

// File Line: 217
// RVA: 0x12C9174
threadlocaleinfostruct *__fastcall updatetlocinfoEx_nolock(
        threadlocaleinfostruct **pptlocid,
        threadlocaleinfostruct *ptlocis)
{
  threadlocaleinfostruct *v3; // rbx

  if ( !ptlocis || !pptlocid )
    return 0i64;
  v3 = *pptlocid;
  if ( *pptlocid != ptlocis )
  {
    *pptlocid = ptlocis;
    _addlocaleref(ptlocis);
    if ( v3 )
    {
      _removelocaleref(v3);
      if ( !v3->refcount && v3 != &_initiallocinfo )
        _freetlocinfo(v3);
    }
  }
  return ptlocis;
}

// File Line: 282
// RVA: 0x12C90FC
threadlocaleinfostruct *__fastcall _updatetlocinfo()
{
  _tiddata *v0; // rax
  _tiddata *v1; // rbx
  threadlocaleinfostruct *ptlocinfo; // rbx

  v0 = getptd();
  v1 = v0;
  if ( (_globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo )
  {
    ptlocinfo = getptd()->ptlocinfo;
  }
  else
  {
    lock(12);
    ptlocinfo = updatetlocinfoEx_nolock(&v1->ptlocinfo, _ptlocinfo);
    unlock(12);
  }
  if ( !ptlocinfo )
    amsg_exit(32);
  return ptlocinfo;
}

