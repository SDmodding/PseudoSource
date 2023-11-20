// File Line: 59
// RVA: 0x12C15D4
__int64 __fastcall _init_ctype(threadlocaleinfostruct *ploci)
{
  const wchar_t *v1; // r8
  unsigned int v2; // ebx
  threadlocaleinfostruct *v3; // rdi
  _WORD *v4; // r15
  _BYTE *v5; // r12
  _BYTE *v6; // r13
  char *v7; // rbp
  unsigned int *address; // r14
  char *v9; // rcx
  signed int v10; // eax
  char *v11; // rcx
  signed int v12; // edx
  __int64 v13; // rax
  char *v14; // rcx
  signed int v15; // edx
  __int64 v16; // rax
  volatile signed __int32 *v17; // rcx
  __int64 result; // rax
  int *v19; // rax
  signed int v20; // [rsp+50h] [rbp-68h]
  int *pBlock; // [rsp+58h] [rbp-60h]
  threadlocaleinfostruct *v22; // [rsp+60h] [rbp-58h]
  __int64 v23; // [rsp+68h] [rbp-50h]
  _cpinfo CPInfo; // [rsp+70h] [rbp-48h]

  v1 = ploci->locale_name[2];
  v2 = 0;
  v3 = ploci;
  pBlock = 0i64;
  v4 = 0i64;
  v5 = 0i64;
  v6 = 0i64;
  v7 = 0i64;
  v22 = ploci;
  v23 = 0i64;
  if ( v1 )
  {
    address = &ploci->lc_codepage;
    if ( !ploci->lc_codepage && _getlocaleinfo((localeinfo_struct *)&v22, 0, v1, 0x1004u, address) )
      goto LABEL_43;
    pBlock = (int *)malloc_crt(4ui64);
    v4 = calloc_crt(0x180ui64, 2ui64);
    v5 = calloc_crt(0x180ui64, 1ui64);
    v6 = calloc_crt(0x180ui64, 1ui64);
    v7 = (char *)calloc_crt(0x101ui64, 1ui64);
    if ( !pBlock )
      goto LABEL_43;
    if ( !v4 )
      goto LABEL_43;
    if ( !v7 )
      goto LABEL_43;
    if ( !v5 )
      goto LABEL_43;
    if ( !v6 )
      goto LABEL_43;
    *pBlock = 0;
    v9 = v7;
    v10 = 0;
    do
      *v9++ = v10++;
    while ( v10 < 256 );
    if ( !GetCPInfo(*address, &CPInfo) )
      goto LABEL_43;
    if ( CPInfo.MaxCharSize > 5 )
      goto LABEL_43;
    v20 = LOWORD(CPInfo.MaxCharSize);
    if ( !_crtLCMapStringA(0i64, v3->locale_name[2], 0x100u, v7 + 1, 255, v5 + 129, 255, *address, 0)
      || !_crtLCMapStringA(0i64, v3->locale_name[2], 0x200u, v7 + 1, 255, v6 + 129, 255, *address, 0) )
    {
      goto LABEL_43;
    }
    if ( v20 > 1 && CPInfo.LeadByte[0] )
    {
      v11 = &CPInfo.LeadByte[1];
      do
      {
        if ( !*v11 )
          break;
        v12 = (unsigned __int8)*(v11 - 1);
        while ( v12 <= (unsigned __int8)*v11 )
        {
          v13 = v12++;
          v7[v13] = 32;
        }
        v11 += 2;
      }
      while ( *(v11 - 1) );
    }
    if ( _crtGetStringTypeA(0i64, 1u, v7, 256, v4 + 128, *address, 0) )
    {
      v4[127] = 0;
      v5[127] = 0;
      v6[127] = 0;
      v5[128] = 0;
      v6[128] = 0;
      if ( v20 > 1 && CPInfo.LeadByte[0] )
      {
        v14 = &CPInfo.LeadByte[1];
        do
        {
          if ( !*v14 )
            break;
          v15 = (unsigned __int8)*(v14 - 1);
          while ( v15 <= (unsigned __int8)*v14 )
          {
            v16 = v15++;
            v4[v16 + 128] = -32768;
          }
          v14 += 2;
        }
        while ( *(v14 - 1) );
      }
      memmove(v4, v4 + 256, 0xFEui64);
      memmove(v5, v5 + 256, 0x7Fui64);
      memmove(v6, v6 + 256, 0x7Fui64);
      v17 = v3->ctype1_refcount;
      if ( v17 )
      {
        if ( !_InterlockedDecrement(v17) )
        {
          free(v3->ctype1 - 127);
          free((void *)(v3->pclmap - 128));
          free((void *)(v3->pcumap - 128));
          free(v3->ctype1_refcount);
        }
      }
      *pBlock = 1;
      v3->ctype1_refcount = pBlock;
      v3->pctype = v4 + 128;
      v3->ctype1 = v4 + 127;
      v3->pclmap = v5 + 128;
      v3->pcumap = v6 + 128;
      v3->mb_cur_max = v20;
    }
    else
    {
LABEL_43:
      free(pBlock);
      free(v4);
      free(v5);
      free(v6);
      v2 = 1;
    }
    free(v7);
    result = v2;
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
    result = 0i64;
  }
  return result;
}clmap = (const char *)&unk_141C18820;
    ploci->mb_cur_max = 1;
    ploci->pcumap = (const char *)&unk_141C189A0;


// File Line: 248
// RVA: 0x12C1598
__int64 __fastcall __mb_cur_max_func()
{
  _tiddata *v0; // rax
  threadlocaleinfostruct *v1; // rcx

  v0 = getptd();
  v1 = v0->ptlocinfo;
  if ( v1 != _ptlocinfo && !(v0->_ownlocale & _globallocalestatus) )
    v1 = _updatetlocinfo();
  return (unsigned int)v1->mb_cur_max;
}

// File Line: 268
// RVA: 0x12C1524
__int64 __fastcall __lc_codepage_func()
{
  _tiddata *v0; // rax
  threadlocaleinfostruct *v1; // rcx

  v0 = getptd();
  v1 = v0->ptlocinfo;
  if ( v1 != _ptlocinfo && !(v0->_ownlocale & _globallocalestatus) )
    v1 = _updatetlocinfo();
  return v1->lc_codepage;
}

// File Line: 298
// RVA: 0x12C155C
unsigned __int16 **__fastcall __lc_locale_name_func()
{
  _tiddata *v0; // rax
  threadlocaleinfostruct *v1; // rcx

  v0 = getptd();
  v1 = v0->ptlocinfo;
  if ( v1 != _ptlocinfo && !(v0->_ownlocale & _globallocalestatus) )
    v1 = _updatetlocinfo();
  return v1->locale_name;
}

