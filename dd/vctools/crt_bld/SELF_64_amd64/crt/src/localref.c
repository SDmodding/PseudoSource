// File Line: 36
// RVA: 0x12C8E34
void __fastcall _addlocaleref(threadlocaleinfostruct *ptloci)
{
  int *v1; // rax
  int *v2; // rax
  int *v3; // rax
  int *v4; // rax
  volatile signed __int32 **v5; // rax
  signed __int64 v6; // r8
  volatile signed __int32 *v7; // rdx

  _InterlockedIncrement(&ptloci->refcount);
  v1 = ptloci->lconv_intl_refcount;
  if ( v1 )
    _InterlockedIncrement(v1);
  v2 = ptloci->lconv_mon_refcount;
  if ( v2 )
    _InterlockedIncrement(v2);
  v3 = ptloci->lconv_num_refcount;
  if ( v3 )
    _InterlockedIncrement(v3);
  v4 = ptloci->ctype1_refcount;
  if ( v4 )
    _InterlockedIncrement(v4);
  v5 = (volatile signed __int32 **)&ptloci->lc_category[0].wrefcount;
  v6 = 6i64;
  do
  {
    if ( *(v5 - 2) != (volatile signed __int32 *)_wclocalestr && *v5 )
      _InterlockedIncrement(*v5);
    if ( *(v5 - 3) )
    {
      v7 = *(v5 - 1);
      if ( v7 )
        _InterlockedIncrement(v7);
    }
    v5 += 4;
    --v6;
  }
  while ( v6 );
  _InterlockedIncrement(&ptloci->lc_time_curr->refcount);
}

// File Line: 74
// RVA: 0x12C9058
threadlocaleinfostruct *__fastcall _removelocaleref(threadlocaleinfostruct *ptloci)
{
  int *v1; // rax
  int *v2; // rax
  int *v3; // rax
  int *v4; // rax
  volatile signed __int32 **v5; // rax
  signed __int64 v6; // r8
  volatile signed __int32 *v7; // rdx

  if ( ptloci )
  {
    _InterlockedAdd(&ptloci->refcount, 0xFFFFFFFF);
    v1 = ptloci->lconv_intl_refcount;
    if ( v1 )
      _InterlockedAdd(v1, 0xFFFFFFFF);
    v2 = ptloci->lconv_mon_refcount;
    if ( v2 )
      _InterlockedAdd(v2, 0xFFFFFFFF);
    v3 = ptloci->lconv_num_refcount;
    if ( v3 )
      _InterlockedAdd(v3, 0xFFFFFFFF);
    v4 = ptloci->ctype1_refcount;
    if ( v4 )
      _InterlockedAdd(v4, 0xFFFFFFFF);
    v5 = (volatile signed __int32 **)&ptloci->lc_category[0].wrefcount;
    v6 = 6i64;
    do
    {
      if ( *(v5 - 2) != (volatile signed __int32 *)_wclocalestr && *v5 )
        _InterlockedAdd(*v5, 0xFFFFFFFF);
      if ( *(v5 - 3) )
      {
        v7 = *(v5 - 1);
        if ( v7 )
          _InterlockedAdd(v7, 0xFFFFFFFF);
      }
      v5 += 4;
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
  lconv *v1; // rax
  threadlocaleinfostruct *v2; // rbx
  int *v3; // rax
  int *v4; // rcx
  int *v5; // rcx
  int *v6; // rax
  __lc_time_data *v7; // rcx
  void **v8; // rsi
  int **v9; // rdi
  signed __int64 v10; // rbp
  int *v11; // rcx
  _DWORD *v12; // rcx

  v1 = ptloci->lconv;
  v2 = ptloci;
  if ( v1 )
  {
    if ( v1 != &_lconv_c )
    {
      v3 = ptloci->lconv_intl_refcount;
      if ( v3 )
      {
        if ( !*v3 )
        {
          v4 = ptloci->lconv_mon_refcount;
          if ( v4 && !*v4 )
          {
            free(v4);
            _free_lconv_mon(v2->lconv);
          }
          v5 = v2->lconv_num_refcount;
          if ( v5 && !*v5 )
          {
            free(v5);
            _free_lconv_num(v2->lconv);
          }
          free(v2->lconv_intl_refcount);
          free(v2->lconv);
        }
      }
    }
  }
  v6 = v2->ctype1_refcount;
  if ( v6 && !*v6 )
  {
    free(v2->ctype1 - 127);
    free((void *)(v2->pclmap - 128));
    free((void *)(v2->pcumap - 128));
    free(v2->ctype1_refcount);
  }
  v7 = v2->lc_time_curr;
  if ( v7 != &_lc_time_c && !v7->refcount )
  {
    _free_lc_time(v7);
    free(v2->lc_time_curr);
  }
  v8 = (void **)v2->locale_name;
  v9 = &v2->lc_category[0].wrefcount;
  v10 = 6i64;
  do
  {
    if ( *(v9 - 2) != (int *)_wclocalestr )
    {
      v11 = *v9;
      if ( *v9 )
      {
        if ( !*v11 )
        {
          free(v11);
          free(*v8);
        }
      }
    }
    if ( *(v9 - 3) )
    {
      v12 = *(v9 - 1);
      if ( v12 )
      {
        if ( !*v12 )
          free(v12);
      }
    }
    ++v8;
    v9 += 4;
    --v10;
  }
  while ( v10 );
  free(v2);
}

// File Line: 217
// RVA: 0x12C9174
threadlocaleinfostruct *__fastcall updatetlocinfoEx_nolock(threadlocaleinfostruct **pptlocid, threadlocaleinfostruct *ptlocis)
{
  threadlocaleinfostruct *v2; // rdi
  threadlocaleinfostruct *v3; // rbx

  v2 = ptlocis;
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
  return v2;
}

// File Line: 282
// RVA: 0x12C90FC
threadlocaleinfostruct *__fastcall _updatetlocinfo()
{
  _tiddata *v0; // rax
  _tiddata *v1; // rbx
  threadlocaleinfostruct *v2; // rbx

  v0 = getptd();
  v1 = v0;
  if ( _globallocalestatus & v0->_ownlocale && v0->ptlocinfo )
  {
    v2 = getptd()->ptlocinfo;
  }
  else
  {
    lock(12);
    v2 = updatetlocinfoEx_nolock(&v1->ptlocinfo, _ptlocinfo);
    unlock(12);
  }
  if ( !v2 )
    amsg_exit(32);
  return v2;
}

