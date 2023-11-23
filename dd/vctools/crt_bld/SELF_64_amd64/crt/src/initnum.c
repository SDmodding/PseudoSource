// File Line: 84
// RVA: 0x12D9734
__int64 __fastcall _init_numeric(threadlocaleinfostruct *ploci)
{
  int *v2; // r15
  int *v3; // r12
  lconv *address; // rsi
  unsigned int v5; // r14d
  lconv *v6; // rax
  lconv *lconv; // rdx
  lconv *v9; // rcx
  __int64 v10; // rax
  __int128 v11; // xmm1
  int *v12; // rax
  void *v13; // rcx
  int *v14; // rax
  const wchar_t *v15; // rdi
  int v16; // ebx
  int v17; // ebx
  int v18; // ebx
  int v19; // ebx
  char *grouping; // rdx
  char v21; // cl
  char *v22; // r8
  char v23; // al
  int *lconv_num_refcount; // rax
  int *lconv_intl_refcount; // rcx
  localeinfo_struct plocinfo; // [rsp+30h] [rbp-38h] BYREF

  plocinfo.locinfo = ploci;
  plocinfo.mbcinfo = 0i64;
  if ( ploci->locale_name[4] || ploci->locale_name[3] )
  {
    v5 = 1;
    v6 = (lconv *)calloc_crt(1ui64, 0x98ui64);
    address = v6;
    if ( !v6 )
      return v5;
    lconv = ploci->lconv;
    v9 = v6;
    if ( (((unsigned __int8)v6 | (unsigned __int8)lconv) & 0xF) != 0 )
    {
      memmove(v6, lconv, 0x98ui64);
    }
    else
    {
      v10 = 1i64;
      do
      {
        *(_OWORD *)&v9->decimal_point = *(_OWORD *)&lconv->decimal_point;
        *(_OWORD *)&v9->grouping = *(_OWORD *)&lconv->grouping;
        *(_OWORD *)&v9->currency_symbol = *(_OWORD *)&lconv->currency_symbol;
        *(_OWORD *)&v9->mon_thousands_sep = *(_OWORD *)&lconv->mon_thousands_sep;
        *(_OWORD *)&v9->positive_sign = *(_OWORD *)&lconv->positive_sign;
        *(_OWORD *)&v9->int_frac_digits = *(_OWORD *)&lconv->int_frac_digits;
        *(_OWORD *)&v9->_W_thousands_sep = *(_OWORD *)&lconv->_W_thousands_sep;
        v11 = *(_OWORD *)&lconv->_W_currency_symbol;
        v9 = (lconv *)((char *)v9 + 128);
        lconv = (lconv *)((char *)lconv + 128);
        *(_OWORD *)&v9[-1]._W_positive_sign = v11;
        --v10;
      }
      while ( v10 );
      *(_OWORD *)&v9->decimal_point = *(_OWORD *)&lconv->decimal_point;
      v9->grouping = lconv->grouping;
    }
    v12 = (int *)malloc_crt(4ui64);
    v3 = v12;
    if ( !v12 )
    {
      v13 = address;
LABEL_13:
      free(v13);
      return v5;
    }
    *v12 = 0;
    if ( !ploci->locale_name[4] )
    {
      v2 = 0i64;
      address->decimal_point = _lconv_c.decimal_point;
      address->thousands_sep = _lconv_c.thousands_sep;
      address->grouping = _lconv_c.grouping;
      address->_W_decimal_point = _lconv_c._W_decimal_point;
      address->_W_thousands_sep = _lconv_c._W_thousands_sep;
LABEL_30:
      *v3 = 1;
      if ( v2 )
        *v2 = 1;
      goto LABEL_32;
    }
    v14 = (int *)malloc_crt(4ui64);
    v2 = v14;
    if ( !v14 )
    {
LABEL_18:
      free(address);
      v13 = v3;
      goto LABEL_13;
    }
    *v14 = 0;
    v15 = ploci->locale_name[4];
    v16 = _getlocaleinfo(&plocinfo, 1, v15, 0xEu, (void **)&address->decimal_point);
    v17 = _getlocaleinfo(&plocinfo, 1, v15, 0xFu, (void **)&address->thousands_sep) | v16;
    v18 = _getlocaleinfo(&plocinfo, 1, v15, 0x10u, (void **)&address->grouping) | v17;
    v19 = _getlocaleinfo(&plocinfo, 2, v15, 0xEu, (void **)&address->_W_decimal_point) | v18;
    if ( v19 | (unsigned int)_getlocaleinfo(&plocinfo, 2, v15, 0xFu, (void **)&address->_W_thousands_sep) )
    {
      _free_lconv_num(address);
      v5 = -1;
      goto LABEL_18;
    }
    grouping = address->grouping;
    while ( 1 )
    {
      if ( !*grouping )
        goto LABEL_30;
      v21 = *grouping;
      if ( (unsigned __int8)(*grouping - 48) <= 9u )
        break;
      if ( v21 == 59 )
      {
        v22 = grouping;
        do
        {
          v23 = v22[1];
          *v22++ = v23;
        }
        while ( v23 );
      }
      else
      {
LABEL_22:
        ++grouping;
      }
    }
    *grouping = v21 - 48;
    goto LABEL_22;
  }
  v2 = 0i64;
  v3 = 0i64;
  address = &_lconv_c;
LABEL_32:
  lconv_num_refcount = ploci->lconv_num_refcount;
  if ( lconv_num_refcount )
    _InterlockedDecrement(lconv_num_refcount);
  lconv_intl_refcount = ploci->lconv_intl_refcount;
  if ( lconv_intl_refcount )
  {
    if ( !_InterlockedDecrement(lconv_intl_refcount) )
    {
      free(ploci->lconv_intl_refcount);
      free(ploci->lconv);
    }
  }
  ploci->lconv_num_refcount = v2;
  ploci->lconv_intl_refcount = v3;
  ploci->lconv = address;
  return 0i64;
}

// File Line: 217
// RVA: 0x12D96C8
void __fastcall _free_lconv_num(lconv *l)
{
  char *decimal_point; // rcx
  char *thousands_sep; // rcx
  char *grouping; // rcx
  wchar_t *W_decimal_point; // rcx
  wchar_t *W_thousands_sep; // rcx

  if ( l )
  {
    decimal_point = l->decimal_point;
    if ( decimal_point != _lconv_c.decimal_point )
      free(decimal_point);
    thousands_sep = l->thousands_sep;
    if ( thousands_sep != _lconv_c.thousands_sep )
      free(thousands_sep);
    grouping = l->grouping;
    if ( grouping != _lconv_c.grouping )
      free(grouping);
    W_decimal_point = l->_W_decimal_point;
    if ( W_decimal_point != _lconv_c._W_decimal_point )
      free(W_decimal_point);
    W_thousands_sep = l->_W_thousands_sep;
    if ( W_thousands_sep != _lconv_c._W_thousands_sep )
      free(W_thousands_sep);
  }
}

