// File Line: 84
// RVA: 0x12D9734
__int64 __fastcall _init_numeric(threadlocaleinfostruct *ploci)
{
  threadlocaleinfostruct *v1; // rbp
  int *v2; // r15
  lconv *v3; // r12
  lconv *address; // rsi
  unsigned int v5; // er14
  lconv *v6; // rax
  lconv *v8; // rdx
  lconv *v9; // rcx
  signed __int64 v10; // rax
  __int128 v11; // xmm1
  lconv *v12; // rax
  lconv *v13; // rcx
  int *v14; // rax
  const wchar_t *v15; // rdi
  int v16; // ebx
  int v17; // ebx
  int v18; // ebx
  int v19; // ebx
  char *v20; // rdx
  char v21; // cl
  char *v22; // r8
  char v23; // al
  volatile signed __int32 *v24; // rax
  volatile signed __int32 *v25; // rcx
  localeinfo_struct plocinfo; // [rsp+30h] [rbp-38h]

  v1 = ploci;
  plocinfo.locinfo = ploci;
  plocinfo.mbcinfo = 0i64;
  if ( *(_OWORD *)&ploci->locale_name[3] != 0i64 )
  {
    v5 = 1;
    v6 = (lconv *)calloc_crt(1ui64, 0x98ui64);
    address = v6;
    if ( !v6 )
      return v5;
    v8 = v1->lconv;
    v9 = v6;
    if ( ((unsigned __int8)v6 | (unsigned __int8)v1->lconv) & 0xF )
    {
      memmove(v6, v8, 0x98ui64);
    }
    else
    {
      v10 = 1i64;
      do
      {
        *(_OWORD *)&v9->decimal_point = *(_OWORD *)&v8->decimal_point;
        *(_OWORD *)&v9->grouping = *(_OWORD *)&v8->grouping;
        *(_OWORD *)&v9->currency_symbol = *(_OWORD *)&v8->currency_symbol;
        *(_OWORD *)&v9->mon_thousands_sep = *(_OWORD *)&v8->mon_thousands_sep;
        *(_OWORD *)&v9->positive_sign = *(_OWORD *)&v8->positive_sign;
        *(_OWORD *)&v9->int_frac_digits = *(_OWORD *)&v8->int_frac_digits;
        *(_OWORD *)&v9->_W_thousands_sep = *(_OWORD *)&v8->_W_thousands_sep;
        v11 = *(_OWORD *)&v8->_W_currency_symbol;
        v9 = (lconv *)((char *)v9 + 128);
        v8 = (lconv *)((char *)v8 + 128);
        *(_OWORD *)&v9[-1]._W_positive_sign = v11;
        --v10;
      }
      while ( v10 );
      *(_OWORD *)&v9->decimal_point = *(_OWORD *)&v8->decimal_point;
      v9->grouping = v8->grouping;
    }
    v12 = (lconv *)malloc_crt(4ui64);
    v3 = v12;
    if ( !v12 )
    {
      v13 = address;
LABEL_12:
      free(v13);
      return v5;
    }
    LODWORD(v12->decimal_point) = 0;
    if ( !v1->locale_name[4] )
    {
      v2 = 0i64;
      address->decimal_point = _lconv_c.decimal_point;
      address->thousands_sep = _lconv_c.thousands_sep;
      address->grouping = _lconv_c.grouping;
      address->_W_decimal_point = _lconv_c._W_decimal_point;
      address->_W_thousands_sep = _lconv_c._W_thousands_sep;
LABEL_29:
      LODWORD(v3->decimal_point) = 1;
      if ( v2 )
        *v2 = 1;
      goto LABEL_31;
    }
    v14 = (int *)malloc_crt(4ui64);
    v2 = v14;
    if ( !v14 )
    {
LABEL_17:
      free(address);
      v13 = v3;
      goto LABEL_12;
    }
    *v14 = 0;
    v15 = v1->locale_name[4];
    v16 = _getlocaleinfo(&plocinfo, 1, v1->locale_name[4], 0xEu, address);
    v17 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v15, 0xFu, &address->thousands_sep) | v16;
    v18 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v15, 0x10u, &address->grouping) | v17;
    v19 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v15, 0xEu, &address->_W_decimal_point) | v18;
    if ( v19 | (unsigned int)_getlocaleinfo(&plocinfo, 2, v15, 0xFu, &address->_W_thousands_sep) )
    {
      _free_lconv_num(address);
      v5 = -1;
      goto LABEL_17;
    }
    v20 = address->grouping;
    while ( 1 )
    {
      if ( !*v20 )
        goto LABEL_29;
      v21 = *v20;
      if ( (unsigned __int8)(*v20 - 48) <= 9u )
        break;
      if ( v21 == 59 )
      {
        v22 = v20;
        do
        {
          v23 = v22[1];
          *v22++ = v23;
        }
        while ( v23 );
      }
      else
      {
LABEL_21:
        ++v20;
      }
    }
    *v20 = v21 - 48;
    goto LABEL_21;
  }
  v2 = 0i64;
  v3 = 0i64;
  address = &_lconv_c;
LABEL_31:
  v24 = v1->lconv_num_refcount;
  if ( v24 )
    _InterlockedDecrement(v24);
  v25 = v1->lconv_intl_refcount;
  if ( v25 )
  {
    if ( !_InterlockedDecrement(v25) )
    {
      free(v1->lconv_intl_refcount);
      free(v1->lconv);
    }
  }
  v1->lconv_num_refcount = v2;
  v1->lconv_intl_refcount = (int *)v3;
  v1->lconv = address;
  return 0i64;
}

// File Line: 217
// RVA: 0x12D96C8
void __fastcall _free_lconv_num(lconv *l)
{
  lconv *v1; // rbx
  char *v2; // rcx
  char *v3; // rcx
  char *v4; // rcx
  wchar_t *v5; // rcx
  wchar_t *v6; // rcx

  if ( l )
  {
    v1 = l;
    v2 = l->decimal_point;
    if ( v2 != _lconv_c.decimal_point )
      free(v2);
    v3 = v1->thousands_sep;
    if ( v3 != _lconv_c.thousands_sep )
      free(v3);
    v4 = v1->grouping;
    if ( v4 != _lconv_c.grouping )
      free(v4);
    v5 = v1->_W_decimal_point;
    if ( v5 != _lconv_c._W_decimal_point )
      free(v5);
    v6 = v1->_W_thousands_sep;
    if ( v6 != _lconv_c._W_thousands_sep )
      free(v6);
  }
}

