// File Line: 59
// RVA: 0x12C15D4
__int64 __fastcall _init_ctype(threadlocaleinfostruct *ploci)
{
  const wchar_t *v1; // r8
  unsigned int v2; // ebx
  char *v4; // r15
  char *v5; // r12
  char *v6; // r13
  char *v7; // rbp
  unsigned int *address; // r14
  char *v9; // rcx
  int i; // eax
  char *v11; // rcx
  int j; // edx
  __int64 v13; // rax
  char *v14; // rcx
  int k; // edx
  __int64 v16; // rax
  int *ctype1_refcount; // rcx
  int *v19; // rax
  int MaxCharSize_low; // [rsp+50h] [rbp-68h]
  int *pBlock; // [rsp+58h] [rbp-60h]
  localeinfo_struct v22; // [rsp+60h] [rbp-58h] BYREF
  _cpinfo CPInfo; // [rsp+70h] [rbp-48h] BYREF

  v1 = ploci->locale_name[2];
  v2 = 0;
  pBlock = 0i64;
  v4 = 0i64;
  v5 = 0i64;
  v6 = 0i64;
  v7 = 0i64;
  v22.locinfo = ploci;
  v22.mbcinfo = 0i64;
  if ( v1 )
  {
    address = &ploci->lc_codepage;
    if ( !ploci->lc_codepage && _getlocaleinfo(&v22, 0, v1, 0x1004u, address) )
      goto $error_cleanup_0;
    pBlock = (int *)malloc_crt(4ui64);
    v4 = (char *)calloc_crt(0x180ui64, 2ui64);
    v5 = (char *)calloc_crt(0x180ui64, 1ui64);
    v6 = (char *)calloc_crt(0x180ui64, 1ui64);
    v7 = (char *)calloc_crt(0x101ui64, 1ui64);
    if ( !pBlock )
      goto $error_cleanup_0;
    if ( !v4 )
      goto $error_cleanup_0;
    if ( !v7 )
      goto $error_cleanup_0;
    if ( !v5 )
      goto $error_cleanup_0;
    if ( !v6 )
      goto $error_cleanup_0;
    *pBlock = 0;
    v9 = v7;
    for ( i = 0; i < 256; *v9++ = i++ )
      ;
    if ( !GetCPInfo(*address, &CPInfo) )
      goto $error_cleanup_0;
    if ( CPInfo.MaxCharSize > 5 )
      goto $error_cleanup_0;
    MaxCharSize_low = LOWORD(CPInfo.MaxCharSize);
    if ( !_crtLCMapStringA(0i64, ploci->locale_name[2], 0x100u, v7 + 1, 255, v5 + 129, 255, *address, 0)
      || !_crtLCMapStringA(0i64, ploci->locale_name[2], 0x200u, v7 + 1, 255, v6 + 129, 255, *address, 0) )
    {
      goto $error_cleanup_0;
    }
    if ( MaxCharSize_low > 1 && CPInfo.LeadByte[0] )
    {
      v11 = &CPInfo.LeadByte[1];
      do
      {
        if ( !*v11 )
          break;
        for ( j = (unsigned __int8)*(v11 - 1); j <= (unsigned __int8)*v11; ++j )
        {
          v13 = j;
          v7[v13] = 32;
        }
        v11 += 2;
      }
      while ( *(v11 - 1) );
    }
    if ( _crtGetStringTypeA(0i64, 1u, v7, 256, (unsigned __int16 *)v4 + 128, *address, 0) )
    {
      *((_WORD *)v4 + 127) = 0;
      v5[127] = 0;
      v6[127] = 0;
      v5[128] = 0;
      v6[128] = 0;
      if ( MaxCharSize_low > 1 && CPInfo.LeadByte[0] )
      {
        v14 = &CPInfo.LeadByte[1];
        do
        {
          if ( !*v14 )
            break;
          for ( k = (unsigned __int8)*(v14 - 1); k <= (unsigned __int8)*v14; ++k )
          {
            v16 = k;
            *(_WORD *)&v4[2 * v16 + 256] = 0x8000;
          }
          v14 += 2;
        }
        while ( *(v14 - 1) );
      }
      memmove(v4, v4 + 512, 0xFEui64);
      memmove(v5, v5 + 256, 0x7Fui64);
      memmove(v6, v6 + 256, 0x7Fui64);
      ctype1_refcount = ploci->ctype1_refcount;
      if ( ctype1_refcount )
      {
        if ( !_InterlockedDecrement(ctype1_refcount) )
        {
          free(ploci->ctype1 - 127);
          free((void *)(ploci->pclmap - 128));
          free((void *)(ploci->pcumap - 128));
          free(ploci->ctype1_refcount);
        }
      }
      *pBlock = 1;
      ploci->ctype1_refcount = pBlock;
      ploci->pctype = (const unsigned __int16 *)(v4 + 256);
      ploci->ctype1 = (unsigned __int16 *)(v4 + 254);
      ploci->pclmap = v5 + 128;
      ploci->pcumap = v6 + 128;
      ploci->mb_cur_max = MaxCharSize_low;
    }
    else
    {
$error_cleanup_0:
      free(pBlock);
      free(v4);
      free(v5);
      free(v6);
      v2 = 1;
    }
    free(v7);
    return v2;
  }
  else
  {
    v19 = ploci->ctype1_refcount;
    if ( v19 )
      _InterlockedDecrement(v19);
    ploci->ctype1_refcount = 0i64;
    ploci->pctype = asc_141C18390;
    ploci->ctype1 = 0i64;
    ploci->pclmap = (const char *)&unk_141C18820;
    ploci->mb_cur_max = 1;
    ploci->pcumap = (const char *)&unk_141C189A0;
    return 0i64;
  }
}   plo

// File Line: 248
// RVA: 0x12C1598
__int64 __fastcall __mb_cur_max_func()
{
  _tiddata *v0; // rax
  threadlocaleinfostruct *ptlocinfo; // rcx

  v0 = getptd();
  ptlocinfo = v0->ptlocinfo;
  if ( ptlocinfo != _ptlocinfo && (v0->_ownlocale & _globallocalestatus) == 0 )
    ptlocinfo = _updatetlocinfo();
  return (unsigned int)ptlocinfo->mb_cur_max;
}

// File Line: 268
// RVA: 0x12C1524
__int64 __fastcall __lc_codepage_func()
{
  _tiddata *v0; // rax
  threadlocaleinfostruct *ptlocinfo; // rcx

  v0 = getptd();
  ptlocinfo = v0->ptlocinfo;
  if ( ptlocinfo != _ptlocinfo && (v0->_ownlocale & _globallocalestatus) == 0 )
    ptlocinfo = _updatetlocinfo();
  return ptlocinfo->lc_codepage;
}

// File Line: 298
// RVA: 0x12C155C
unsigned __int16 **__fastcall __lc_locale_name_func()
{
  _tiddata *v0; // rax
  threadlocaleinfostruct *ptlocinfo; // rcx

  v0 = getptd();
  ptlocinfo = v0->ptlocinfo;
  if ( ptlocinfo != _ptlocinfo && (v0->_ownlocale & _globallocalestatus) == 0 )
    ptlocinfo = _updatetlocinfo();
  return ptlocinfo->locale_name;
}

