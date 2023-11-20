// File Line: 56
// RVA: 0x12D9E1C
signed __int64 __fastcall _init_time(threadlocaleinfostruct *ploci)
{
  threadlocaleinfostruct *v1; // rdi
  __lc_time_data *v2; // rax
  __lc_time_data *v3; // rbx
  __lc_time_data *v5; // rax

  v1 = ploci;
  if ( ploci->locale_name[5] )
  {
    v2 = (__lc_time_data *)calloc_crt(1ui64, 0x2C0ui64);
    v3 = v2;
    if ( !v2 )
      return 1i64;
    if ( get_lc_time(v2, v1) )
    {
      _free_lc_time(v3);
      free(v3);
      return 1i64;
    }
    v3->refcount = 1;
  }
  else
  {
    v3 = &_lc_time_c;
  }
  v5 = v1->lc_time_curr;
  if ( v5 != &_lc_time_c )
    _InterlockedDecrement(&v5->refcount);
  v1->lc_time_curr = v3;
  return 0i64;
}

// File Line: 94
// RVA: 0x12D9EBC
signed __int64 __fastcall get_lc_time(__lc_time_data *lc_time, threadlocaleinfostruct *ploci)
{
  const wchar_t *v2; // rsi
  threadlocaleinfostruct *v3; // rbx
  __lc_time_data *address; // rdi
  unsigned __int16 *v6; // rax
  int v7; // ebx
  int v8; // ebx
  int v9; // ebx
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
  int v30; // ebx
  int v31; // ebx
  int v32; // ebx
  int v33; // ebx
  int v34; // ebx
  int v35; // ebx
  int v36; // ebx
  int v37; // ebx
  int v38; // ebx
  int v39; // ebx
  int v40; // ebx
  int v41; // ebx
  int v42; // ebx
  int v43; // ebx
  int v44; // ebx
  int v45; // ebx
  int v46; // ebx
  int v47; // ebx
  int v48; // ebx
  int v49; // ebx
  int v50; // ebx
  int v51; // ebx
  int v52; // ebx
  int v53; // ebx
  int v54; // ebx
  int v55; // ebx
  int v56; // ebx
  int v57; // ebx
  int v58; // ebx
  int v59; // ebx
  int v60; // ebx
  int v61; // ebx
  int v62; // ebx
  int v63; // ebx
  int v64; // ebx
  int v65; // ebx
  int v66; // ebx
  int v67; // ebx
  int v68; // ebx
  int v69; // ebx
  int v70; // ebx
  int v71; // ebx
  int v72; // ebx
  int v73; // ebx
  int v74; // ebx
  int v75; // ebx
  int v76; // ebx
  int v77; // ebx
  int v78; // ebx
  int v79; // ebx
  int v80; // ebx
  int v81; // ebx
  int v82; // ebx
  int v83; // ebx
  int v84; // ebx
  int v85; // ebx
  int v86; // ebx
  int v87; // ebx
  int v88; // ebx
  int v89; // ebx
  int v90; // ebx
  int v91; // ebx
  int v92; // ebx
  localeinfo_struct plocinfo; // [rsp+30h] [rbp-10h]

  v2 = ploci->locale_name[5];
  v3 = ploci;
  address = lc_time;
  if ( !lc_time )
    return 0xFFFFFFFFi64;
  v6 = _copy_locale_name(ploci->locale_name[5]);
  plocinfo.mbcinfo = 0i64;
  address->_W_ww_locale_name = v6;
  plocinfo.locinfo = v3;
  v7 = _getlocaleinfo(&plocinfo, 1, v2, 0x31u, &address->wday_abbr[1]);
  v8 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x32u, &address->wday_abbr[2]) | v7;
  v9 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x33u, &address->wday_abbr[3]) | v8;
  v10 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x34u, &address->wday_abbr[4]) | v9;
  v11 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x35u, &address->wday_abbr[5]) | v10;
  v12 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x36u, &address->wday_abbr[6]) | v11;
  v13 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x37u, address) | v12;
  v14 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x2Au, &address->wday[1]) | v13;
  v15 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x2Bu, &address->wday[2]) | v14;
  v16 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x2Cu, &address->wday[3]) | v15;
  v17 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x2Du, &address->wday[4]) | v16;
  v18 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x2Eu, &address->wday[5]) | v17;
  v19 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x2Fu, &address->wday[6]) | v18;
  v20 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x30u, address->wday) | v19;
  v21 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x44u, address->month_abbr) | v20;
  v22 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x45u, &address->month_abbr[1]) | v21;
  v23 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x46u, &address->month_abbr[2]) | v22;
  v24 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x47u, &address->month_abbr[3]) | v23;
  v25 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x48u, &address->month_abbr[4]) | v24;
  v26 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x49u, &address->month_abbr[5]) | v25;
  v27 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x4Au, &address->month_abbr[6]) | v26;
  v28 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x4Bu, &address->month_abbr[7]) | v27;
  v29 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x4Cu, &address->month_abbr[8]) | v28;
  v30 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x4Du, &address->month_abbr[9]) | v29;
  v31 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x4Eu, &address->month_abbr[10]) | v30;
  v32 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x4Fu, &address->month_abbr[11]) | v31;
  v33 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x38u, address->month) | v32;
  v34 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x39u, &address->month[1]) | v33;
  v35 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x3Au, &address->month[2]) | v34;
  v36 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x3Bu, &address->month[3]) | v35;
  v37 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x3Cu, &address->month[4]) | v36;
  v38 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x3Du, &address->month[5]) | v37;
  v39 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x3Eu, &address->month[6]) | v38;
  v40 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x3Fu, &address->month[7]) | v39;
  v41 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x40u, &address->month[8]) | v40;
  v42 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x41u, &address->month[9]) | v41;
  v43 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x42u, &address->month[10]) | v42;
  v44 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x43u, &address->month[11]) | v43;
  v45 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x28u, address->ampm) | v44;
  v46 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x29u, &address->ampm[1]) | v45;
  v47 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x1Fu, &address->ww_sdatefmt) | v46;
  v48 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x20u, &address->ww_ldatefmt) | v47;
  v49 = (unsigned __int64)_getlocaleinfo(&plocinfo, 1, v2, 0x1003u, &address->ww_timefmt) | v48;
  v50 = (unsigned __int64)_getlocaleinfo(&plocinfo, 0, v2, 0x1009u, &address->ww_caltype) | v49;
  v51 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x31u, &address->_W_wday_abbr[1]) | v50;
  v52 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x32u, &address->_W_wday_abbr[2]) | v51;
  v53 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x33u, &address->_W_wday_abbr[3]) | v52;
  v54 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x34u, &address->_W_wday_abbr[4]) | v53;
  v55 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x35u, &address->_W_wday_abbr[5]) | v54;
  v56 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x36u, &address->_W_wday_abbr[6]) | v55;
  v57 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x37u, address->_W_wday_abbr) | v56;
  v58 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x2Au, &address->_W_wday[1]) | v57;
  v59 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x2Bu, &address->_W_wday[2]) | v58;
  v60 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x2Cu, &address->_W_wday[3]) | v59;
  v61 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x2Du, &address->_W_wday[4]) | v60;
  v62 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x2Eu, &address->_W_wday[5]) | v61;
  v63 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x2Fu, &address->_W_wday[6]) | v62;
  v64 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x30u, address->_W_wday) | v63;
  v65 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x44u, address->_W_month_abbr) | v64;
  v66 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x45u, &address->_W_month_abbr[1]) | v65;
  v67 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x46u, &address->_W_month_abbr[2]) | v66;
  v68 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x47u, &address->_W_month_abbr[3]) | v67;
  v69 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x48u, &address->_W_month_abbr[4]) | v68;
  v70 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x49u, &address->_W_month_abbr[5]) | v69;
  v71 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x4Au, &address->_W_month_abbr[6]) | v70;
  v72 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x4Bu, &address->_W_month_abbr[7]) | v71;
  v73 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x4Cu, &address->_W_month_abbr[8]) | v72;
  v74 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x4Du, &address->_W_month_abbr[9]) | v73;
  v75 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x4Eu, &address->_W_month_abbr[10]) | v74;
  v76 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x4Fu, &address->_W_month_abbr[11]) | v75;
  v77 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x38u, address->_W_month) | v76;
  v78 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x39u, &address->_W_month[1]) | v77;
  v79 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x3Au, &address->_W_month[2]) | v78;
  v80 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x3Bu, &address->_W_month[3]) | v79;
  v81 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x3Cu, &address->_W_month[4]) | v80;
  v82 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x3Du, &address->_W_month[5]) | v81;
  v83 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x3Eu, &address->_W_month[6]) | v82;
  v84 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x3Fu, &address->_W_month[7]) | v83;
  v85 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x40u, &address->_W_month[8]) | v84;
  v86 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x41u, &address->_W_month[9]) | v85;
  v87 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x42u, &address->_W_month[10]) | v86;
  v88 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x43u, &address->_W_month[11]) | v87;
  v89 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x28u, address->_W_ampm) | v88;
  v90 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x29u, &address->_W_ampm[1]) | v89;
  v91 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x1Fu, &address->_W_ww_sdatefmt) | v90;
  v92 = (unsigned __int64)_getlocaleinfo(&plocinfo, 2, v2, 0x20u, &address->_W_ww_ldatefmt) | v91;
  return v92 | (unsigned int)_getlocaleinfo(&plocinfo, 2, v2, 0x1003u, &address->_W_ww_timefmt);
}

// File Line: 230
// RVA: 0x12D9A20
void __fastcall _free_lc_time(__lc_time_data *lc_time)
{
  __lc_time_data *v1; // rbx

  if ( lc_time )
  {
    v1 = lc_time;
    free(lc_time->wday_abbr[1]);
    free(v1->wday_abbr[2]);
    free(v1->wday_abbr[3]);
    free(v1->wday_abbr[4]);
    free(v1->wday_abbr[5]);
    free(v1->wday_abbr[6]);
    free(v1->wday_abbr[0]);
    free(v1->wday[1]);
    free(v1->wday[2]);
    free(v1->wday[3]);
    free(v1->wday[4]);
    free(v1->wday[5]);
    free(v1->wday[6]);
    free(v1->wday[0]);
    free(v1->month_abbr[0]);
    free(v1->month_abbr[1]);
    free(v1->month_abbr[2]);
    free(v1->month_abbr[3]);
    free(v1->month_abbr[4]);
    free(v1->month_abbr[5]);
    free(v1->month_abbr[6]);
    free(v1->month_abbr[7]);
    free(v1->month_abbr[8]);
    free(v1->month_abbr[9]);
    free(v1->month_abbr[10]);
    free(v1->month_abbr[11]);
    free(v1->month[0]);
    free(v1->month[1]);
    free(v1->month[2]);
    free(v1->month[3]);
    free(v1->month[4]);
    free(v1->month[5]);
    free(v1->month[6]);
    free(v1->month[7]);
    free(v1->month[8]);
    free(v1->month[9]);
    free(v1->month[10]);
    free(v1->month[11]);
    free(v1->ampm[0]);
    free(v1->ampm[1]);
    free(v1->ww_sdatefmt);
    free(v1->ww_ldatefmt);
    free(v1->ww_timefmt);
    free(v1->_W_wday_abbr[1]);
    free(v1->_W_wday_abbr[2]);
    free(v1->_W_wday_abbr[3]);
    free(v1->_W_wday_abbr[4]);
    free(v1->_W_wday_abbr[5]);
    free(v1->_W_wday_abbr[6]);
    free(v1->_W_wday_abbr[0]);
    free(v1->_W_wday[1]);
    free(v1->_W_wday[2]);
    free(v1->_W_wday[3]);
    free(v1->_W_wday[4]);
    free(v1->_W_wday[5]);
    free(v1->_W_wday[6]);
    free(v1->_W_wday[0]);
    free(v1->_W_month_abbr[0]);
    free(v1->_W_month_abbr[1]);
    free(v1->_W_month_abbr[2]);
    free(v1->_W_month_abbr[3]);
    free(v1->_W_month_abbr[4]);
    free(v1->_W_month_abbr[5]);
    free(v1->_W_month_abbr[6]);
    free(v1->_W_month_abbr[7]);
    free(v1->_W_month_abbr[8]);
    free(v1->_W_month_abbr[9]);
    free(v1->_W_month_abbr[10]);
    free(v1->_W_month_abbr[11]);
    free(v1->_W_month[0]);
    free(v1->_W_month[1]);
    free(v1->_W_month[2]);
    free(v1->_W_month[3]);
    free(v1->_W_month[4]);
    free(v1->_W_month[5]);
    free(v1->_W_month[6]);
    free(v1->_W_month[7]);
    free(v1->_W_month[8]);
    free(v1->_W_month[9]);
    free(v1->_W_month[10]);
    free(v1->_W_month[11]);
    free(v1->_W_ampm[0]);
    free(v1->_W_ampm[1]);
    free(v1->_W_ww_sdatefmt);
    free(v1->_W_ww_ldatefmt);
    free(v1->_W_ww_timefmt);
    free(v1->_W_ww_locale_name);
  }
}

