// File Line: 65
// RVA: 0x12D91A8
__int64 __fastcall _init_monetary(threadlocaleinfostruct *ploci)
{
  int *v2; // r15
  _DWORD *v3; // r12
  lconv *v4; // r14
  _DWORD *v6; // rax
  void *v7; // rcx
  int *v8; // rax
  const wchar_t *v9; // rdi
  int v10; // ebx
  int v11; // ebx
  int v12; // ebx
  int v13; // ebx
  int v14; // ebx
  int v15; // ebx
  int v16; // ebx
  int v17; // ebx
  int v18; // ebx
  int v19; // ebx
  int v20; // ebx
  int v21; // ebx
  int v22; // ebx
  int v23; // ebx
  int v24; // ebx
  int v25; // ebx
  int v26; // ebx
  int v27; // ebx
  int v28; // ebx
  int v29; // ebx
  char *mon_grouping; // rdx
  char v31; // cl
  char *v32; // r8
  char v33; // al
  lconv *v34; // rdx
  lconv *v35; // rcx
  __int64 v36; // rax
  __int128 v37; // xmm1
  int *lconv_mon_refcount; // rax
  int *lconv_intl_refcount; // rcx
  localeinfo_struct plocinfo; // [rsp+30h] [rbp-10h] BYREF

  plocinfo.locinfo = ploci;
  v2 = 0i64;
  plocinfo.mbcinfo = 0i64;
  if ( ploci->locale_name[3] || ploci->locale_name[4] )
  {
    v4 = (lconv *)calloc_crt(1ui64, 0x98ui64);
    if ( !v4 )
      return 1i64;
    v6 = malloc_crt(4ui64);
    v3 = v6;
    if ( !v6 )
    {
      v7 = v4;
LABEL_8:
      free(v7);
      return 1i64;
    }
    *v6 = 0;
    if ( !ploci->locale_name[3] )
    {
      v34 = &_lconv_c;
      v35 = v4;
      if ( (((unsigned __int8)v4 | (unsigned __int8)&_lconv_c) & 0xF) != 0 )
      {
        memmove(v4, &_lconv_c, 0x98ui64);
      }
      else
      {
        v36 = 1i64;
        do
        {
          *(_OWORD *)&v35->decimal_point = *(_OWORD *)&v34->decimal_point;
          *(_OWORD *)&v35->grouping = *(_OWORD *)&v34->grouping;
          *(_OWORD *)&v35->currency_symbol = *(_OWORD *)&v34->currency_symbol;
          *(_OWORD *)&v35->mon_thousands_sep = *(_OWORD *)&v34->mon_thousands_sep;
          *(_OWORD *)&v35->positive_sign = *(_OWORD *)&v34->positive_sign;
          *(_OWORD *)&v35->int_frac_digits = *(_OWORD *)&v34->int_frac_digits;
          *(_OWORD *)&v35->_W_thousands_sep = *(_OWORD *)&v34->_W_thousands_sep;
          v37 = *(_OWORD *)&v34->_W_currency_symbol;
          v35 = (lconv *)((char *)v35 + 128);
          v34 = (lconv *)((char *)v34 + 128);
          *(_OWORD *)&v35[-1]._W_positive_sign = v37;
          --v36;
        }
        while ( v36 );
        *(_OWORD *)&v35->decimal_point = *(_OWORD *)&v34->decimal_point;
        v35->grouping = v34->grouping;
      }
LABEL_29:
      v4->decimal_point = ploci->lconv->decimal_point;
      v4->thousands_sep = ploci->lconv->thousands_sep;
      v4->grouping = ploci->lconv->grouping;
      v4->_W_decimal_point = ploci->lconv->_W_decimal_point;
      v4->_W_thousands_sep = ploci->lconv->_W_thousands_sep;
      *v3 = 1;
      if ( v2 )
        *v2 = 1;
      goto LABEL_31;
    }
    v8 = (int *)malloc_crt(4ui64);
    v2 = v8;
    if ( !v8 )
    {
      free(v4);
      v7 = v3;
      goto LABEL_8;
    }
    *v8 = 0;
    v9 = ploci->locale_name[3];
    v10 = _getlocaleinfo(&plocinfo, 1, v9, 0x15u, (void **)&v4->int_curr_symbol);
    v11 = _getlocaleinfo(&plocinfo, 1, v9, 0x14u, (void **)&v4->currency_symbol) | v10;
    v12 = _getlocaleinfo(&plocinfo, 1, v9, 0x16u, (void **)&v4->mon_decimal_point) | v11;
    v13 = _getlocaleinfo(&plocinfo, 1, v9, 0x17u, (void **)&v4->mon_thousands_sep) | v12;
    v14 = _getlocaleinfo(&plocinfo, 1, v9, 0x18u, (void **)&v4->mon_grouping) | v13;
    v15 = _getlocaleinfo(&plocinfo, 1, v9, 0x50u, (void **)&v4->positive_sign) | v14;
    v16 = _getlocaleinfo(&plocinfo, 1, v9, 0x51u, (void **)&v4->negative_sign) | v15;
    v17 = _getlocaleinfo(&plocinfo, 0, v9, 0x1Au, (void **)&v4->int_frac_digits) | v16;
    v18 = _getlocaleinfo(&plocinfo, 0, v9, 0x19u, (void **)&v4->frac_digits) | v17;
    v19 = _getlocaleinfo(&plocinfo, 0, v9, 0x54u, (void **)&v4->p_cs_precedes) | v18;
    v20 = _getlocaleinfo(&plocinfo, 0, v9, 0x55u, (void **)&v4->p_sep_by_space) | v19;
    v21 = _getlocaleinfo(&plocinfo, 0, v9, 0x56u, (void **)&v4->n_cs_precedes) | v20;
    v22 = _getlocaleinfo(&plocinfo, 0, v9, 0x57u, (void **)&v4->n_sep_by_space) | v21;
    v23 = _getlocaleinfo(&plocinfo, 0, v9, 0x52u, (void **)&v4->p_sign_posn) | v22;
    v24 = _getlocaleinfo(&plocinfo, 0, v9, 0x53u, (void **)&v4->n_sign_posn) | v23;
    v25 = _getlocaleinfo(&plocinfo, 2, v9, 0x15u, (void **)&v4->_W_int_curr_symbol) | v24;
    v26 = _getlocaleinfo(&plocinfo, 2, v9, 0x14u, (void **)&v4->_W_currency_symbol) | v25;
    v27 = _getlocaleinfo(&plocinfo, 2, v9, 0x16u, (void **)&v4->_W_mon_decimal_point) | v26;
    v28 = _getlocaleinfo(&plocinfo, 2, v9, 0x17u, (void **)&v4->_W_mon_thousands_sep) | v27;
    v29 = _getlocaleinfo(&plocinfo, 2, v9, 0x50u, (void **)&v4->_W_positive_sign) | v28;
    if ( v29 | (unsigned int)_getlocaleinfo(&plocinfo, 2, v9, 0x51u, (void **)&v4->_W_negative_sign) )
    {
      _free_lconv_mon(v4);
      free(v4);
      free(v3);
      v7 = v2;
      goto LABEL_8;
    }
    mon_grouping = v4->mon_grouping;
    while ( 1 )
    {
      if ( !*mon_grouping )
        goto LABEL_29;
      v31 = *mon_grouping;
      if ( (unsigned __int8)(*mon_grouping - 48) <= 9u )
        break;
      if ( v31 == 59 )
      {
        v32 = mon_grouping;
        do
        {
          v33 = v32[1];
          *v32++ = v33;
        }
        while ( v33 );
      }
      else
      {
LABEL_17:
        ++mon_grouping;
      }
    }
    *mon_grouping = v31 - 48;
    goto LABEL_17;
  }
  v3 = 0i64;
  v4 = &_lconv_c;
LABEL_31:
  lconv_mon_refcount = ploci->lconv_mon_refcount;
  if ( lconv_mon_refcount )
    _InterlockedDecrement(lconv_mon_refcount);
  lconv_intl_refcount = ploci->lconv_intl_refcount;
  if ( lconv_intl_refcount )
  {
    if ( !_InterlockedDecrement(lconv_intl_refcount) )
    {
      free(ploci->lconv);
      free(ploci->lconv_intl_refcount);
    }
  }
  ploci->lconv_mon_refcount = v2;
  ploci->lconv_intl_refcount = v3;
  ploci->lconv = v4;
  return 0i64;
}

// File Line: 270
// RVA: 0x12D909C
void __fastcall _free_lconv_mon(lconv *l)
{
  char *int_curr_symbol; // rcx
  char *currency_symbol; // rcx
  char *mon_decimal_point; // rcx
  char *mon_thousands_sep; // rcx
  char *mon_grouping; // rcx
  char *positive_sign; // rcx
  char *negative_sign; // rcx
  wchar_t *W_int_curr_symbol; // rcx
  wchar_t *W_currency_symbol; // rcx
  wchar_t *W_mon_decimal_point; // rcx
  wchar_t *W_mon_thousands_sep; // rcx
  wchar_t *W_positive_sign; // rcx
  wchar_t *W_negative_sign; // rcx

  if ( l )
  {
    int_curr_symbol = l->int_curr_symbol;
    if ( int_curr_symbol != _lconv_c.int_curr_symbol )
      free(int_curr_symbol);
    currency_symbol = l->currency_symbol;
    if ( currency_symbol != _lconv_c.currency_symbol )
      free(currency_symbol);
    mon_decimal_point = l->mon_decimal_point;
    if ( mon_decimal_point != _lconv_c.mon_decimal_point )
      free(mon_decimal_point);
    mon_thousands_sep = l->mon_thousands_sep;
    if ( mon_thousands_sep != _lconv_c.mon_thousands_sep )
      free(mon_thousands_sep);
    mon_grouping = l->mon_grouping;
    if ( mon_grouping != _lconv_c.mon_grouping )
      free(mon_grouping);
    positive_sign = l->positive_sign;
    if ( positive_sign != _lconv_c.positive_sign )
      free(positive_sign);
    negative_sign = l->negative_sign;
    if ( negative_sign != _lconv_c.negative_sign )
      free(negative_sign);
    W_int_curr_symbol = l->_W_int_curr_symbol;
    if ( W_int_curr_symbol != _lconv_c._W_int_curr_symbol )
      free(W_int_curr_symbol);
    W_currency_symbol = l->_W_currency_symbol;
    if ( W_currency_symbol != _lconv_c._W_currency_symbol )
      free(W_currency_symbol);
    W_mon_decimal_point = l->_W_mon_decimal_point;
    if ( W_mon_decimal_point != _lconv_c._W_mon_decimal_point )
      free(W_mon_decimal_point);
    W_mon_thousands_sep = l->_W_mon_thousands_sep;
    if ( W_mon_thousands_sep != _lconv_c._W_mon_thousands_sep )
      free(W_mon_thousands_sep);
    W_positive_sign = l->_W_positive_sign;
    if ( W_positive_sign != _lconv_c._W_positive_sign )
      free(W_positive_sign);
    W_negative_sign = l->_W_negative_sign;
    if ( W_negative_sign != _lconv_c._W_negative_sign )
      free(W_negative_sign);
  }
}

