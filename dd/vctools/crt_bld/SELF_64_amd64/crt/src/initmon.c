// File Line: 65
// RVA: 0x12D91A8
signed __int64 __fastcall _init_monetary(threadlocaleinfostruct *ploci)
{
  threadlocaleinfostruct *v1; // rsi
  lconv *v2; // r15
  lconv *v3; // r12
  lconv *v4; // r14
  lconv *v6; // rax
  lconv *v7; // rcx
  lconv *v8; // rax
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
  char *v30; // rdx
  char v31; // cl
  char *v32; // r8
  char v33; // al
  lconv *v34; // rdx
  lconv *v35; // rcx
  signed __int64 v36; // rax
  __int128 v37; // xmm1
  volatile signed __int32 *v38; // rax
  volatile signed __int32 *v39; // rcx
  localeinfo_struct plocinfo; // [rsp+30h] [rbp-10h]

  v1 = ploci;
  plocinfo.locinfo = ploci;
  v2 = 0i64;
  plocinfo.mbcinfo = 0i64;
  if ( *(_OWORD *)&ploci->locale_name[3] != 0i64 )
  {
    v4 = (lconv *)calloc_crt(1ui64, 0x98ui64);
    if ( !v4 )
      return 1i64;
    v6 = (lconv *)malloc_crt(4ui64);
    v3 = v6;
    if ( !v6 )
    {
      v7 = v4;
LABEL_7:
      free(v7);
      return 1i64;
    }
    LODWORD(v6->decimal_point) = 0;
    if ( !v1->locale_name[3] )
    {
      v34 = &_lconv_c;
      v35 = v4;
      if ( ((unsigned __int8)v4 | (unsigned __int8)&_lconv_c) & 0xF )
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
LABEL_28:
      v4->decimal_point = v1->lconv->decimal_point;
      v4->thousands_sep = v1->lconv->thousands_sep;
      v4->grouping = v1->lconv->grouping;
      v4->_W_decimal_point = v1->lconv->_W_decimal_point;
      v4->_W_thousands_sep = v1->lconv->_W_thousands_sep;
      LODWORD(v3->decimal_point) = 1;
      if ( v2 )
        LODWORD(v2->decimal_point) = 1;
      goto LABEL_30;
    }
    v8 = (lconv *)malloc_crt(4ui64);
    v2 = v8;
    if ( !v8 )
    {
      free(v4);
      v7 = v3;
      goto LABEL_7;
    }
    LODWORD(v8->decimal_point) = 0;
    v9 = v1->locale_name[3];
    v10 = _getlocaleinfo(&plocinfo, 1, v1->locale_name[3], 0x15u, &v4->int_curr_symbol);
    v11 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v9, 0x14u, &v4->currency_symbol) | v10;
    v12 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v9, 0x16u, &v4->mon_decimal_point) | v11;
    v13 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v9, 0x17u, &v4->mon_thousands_sep) | v12;
    v14 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v9, 0x18u, &v4->mon_grouping) | v13;
    v15 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v9, 0x50u, &v4->positive_sign) | v14;
    v16 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v9, 0x51u, &v4->negative_sign) | v15;
    v17 = (unsigned __int64)_getlocaleinfo(&plocinfo, 0, v9, 0x1Au, &v4->int_frac_digits) | v16;
    v18 = (unsigned __int64)_getlocaleinfo(&plocinfo, 0, v9, 0x19u, &v4->frac_digits) | v17;
    v19 = (unsigned __int64)_getlocaleinfo(&plocinfo, 0, v9, 0x54u, &v4->p_cs_precedes) | v18;
    v20 = (unsigned __int64)_getlocaleinfo(&plocinfo, 0, v9, 0x55u, &v4->p_sep_by_space) | v19;
    v21 = (unsigned __int64)_getlocaleinfo(&plocinfo, 0, v9, 0x56u, &v4->n_cs_precedes) | v20;
    v22 = (unsigned __int64)_getlocaleinfo(&plocinfo, 0, v9, 0x57u, &v4->n_sep_by_space) | v21;
    v23 = (unsigned __int64)_getlocaleinfo(&plocinfo, 0, v9, 0x52u, &v4->p_sign_posn) | v22;
    v24 = (unsigned __int64)_getlocaleinfo(&plocinfo, 0, v9, 0x53u, &v4->n_sign_posn) | v23;
    v25 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v9, 0x15u, &v4->_W_int_curr_symbol) | v24;
    v26 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v9, 0x14u, &v4->_W_currency_symbol) | v25;
    v27 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v9, 0x16u, &v4->_W_mon_decimal_point) | v26;
    v28 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v9, 0x17u, &v4->_W_mon_thousands_sep) | v27;
    v29 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v9, 0x50u, &v4->_W_positive_sign) | v28;
    if ( v29 | (unsigned int)_getlocaleinfo(&plocinfo, 2, v9, 0x51u, &v4->_W_negative_sign) )
    {
      _free_lconv_mon(v4);
      free(v4);
      free(v3);
      v7 = v2;
      goto LABEL_7;
    }
    v30 = v4->mon_grouping;
    while ( 1 )
    {
      if ( !*v30 )
        goto LABEL_28;
      v31 = *v30;
      if ( (unsigned __int8)(*v30 - 48) <= 9u )
        break;
      if ( v31 == 59 )
      {
        v32 = v30;
        do
        {
          v33 = v32[1];
          *v32++ = v33;
        }
        while ( v33 );
      }
      else
      {
LABEL_16:
        ++v30;
      }
    }
    *v30 = v31 - 48;
    goto LABEL_16;
  }
  v3 = 0i64;
  v4 = &_lconv_c;
LABEL_30:
  v38 = v1->lconv_mon_refcount;
  if ( v38 )
    _InterlockedDecrement(v38);
  v39 = v1->lconv_intl_refcount;
  if ( v39 )
  {
    if ( !_InterlockedDecrement(v39) )
    {
      free(v1->lconv);
      free(v1->lconv_intl_refcount);
    }
  }
  v1->lconv_mon_refcount = (int *)v2;
  v1->lconv_intl_refcount = (int *)v3;
  v1->lconv = v4;
  return 0i64;
}

// File Line: 270
// RVA: 0x12D909C
void __fastcall _free_lconv_mon(lconv *l)
{
  lconv *v1; // rbx
  char *v2; // rcx
  char *v3; // rcx
  char *v4; // rcx
  char *v5; // rcx
  char *v6; // rcx
  char *v7; // rcx
  char *v8; // rcx
  wchar_t *v9; // rcx
  wchar_t *v10; // rcx
  wchar_t *v11; // rcx
  wchar_t *v12; // rcx
  wchar_t *v13; // rcx
  wchar_t *v14; // rcx

  if ( l )
  {
    v1 = l;
    v2 = l->int_curr_symbol;
    if ( v2 != _lconv_c.int_curr_symbol )
      free(v2);
    v3 = v1->currency_symbol;
    if ( v3 != _lconv_c.currency_symbol )
      free(v3);
    v4 = v1->mon_decimal_point;
    if ( v4 != _lconv_c.mon_decimal_point )
      free(v4);
    v5 = v1->mon_thousands_sep;
    if ( v5 != _lconv_c.mon_thousands_sep )
      free(v5);
    v6 = v1->mon_grouping;
    if ( v6 != _lconv_c.mon_grouping )
      free(v6);
    v7 = v1->positive_sign;
    if ( v7 != _lconv_c.positive_sign )
      free(v7);
    v8 = v1->negative_sign;
    if ( v8 != _lconv_c.negative_sign )
      free(v8);
    v9 = v1->_W_int_curr_symbol;
    if ( v9 != _lconv_c._W_int_curr_symbol )
      free(v9);
    v10 = v1->_W_currency_symbol;
    if ( v10 != _lconv_c._W_currency_symbol )
      free(v10);
    v11 = v1->_W_mon_decimal_point;
    if ( v11 != _lconv_c._W_mon_decimal_point )
      free(v11);
    v12 = v1->_W_mon_thousands_sep;
    if ( v12 != _lconv_c._W_mon_thousands_sep )
      free(v12);
    v13 = v1->_W_positive_sign;
    if ( v13 != _lconv_c._W_positive_sign )
      free(v13);
    v14 = v1->_W_negative_sign;
    if ( v14 != _lconv_c._W_negative_sign )
      free(v14);
  }
}

