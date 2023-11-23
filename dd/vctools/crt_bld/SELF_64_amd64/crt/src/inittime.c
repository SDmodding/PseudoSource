// File Line: 56
// RVA: 0x12D9E1C
__int64 __fastcall _init_time(threadlocaleinfostruct *ploci)
{
  __lc_time_data *v2; // rax
  __lc_time_data *v3; // rbx
  __lc_time_data *lc_time_curr; // rax

  if ( ploci->locale_name[5] )
  {
    v2 = (__lc_time_data *)calloc_crt(1ui64, 0x2C0ui64);
    v3 = v2;
    if ( !v2 )
      return 1i64;
    if ( get_lc_time(v2, ploci) )
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
  lc_time_curr = ploci->lc_time_curr;
  if ( lc_time_curr != &_lc_time_c )
    _InterlockedDecrement(&lc_time_curr->refcount);
  ploci->lc_time_curr = v3;
  return 0i64;
}

// File Line: 94
// RVA: 0x12D9EBC
__int64 __fastcall get_lc_time(__lc_time_data *lc_time, threadlocaleinfostruct *ploci)
{
  const wchar_t *v2; // rsi
  char *v6; // rax
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
  localeinfo_struct plocinfo; // [rsp+30h] [rbp-10h] BYREF

  v2 = ploci->locale_name[5];
  if ( !lc_time )
    return 0xFFFFFFFFi64;
  v6 = _copy_locale_name(ploci->locale_name[5]);
  plocinfo.mbcinfo = 0i64;
  lc_time->_W_ww_locale_name = (wchar_t *)v6;
  plocinfo.locinfo = ploci;
  v7 = _getlocaleinfo(&plocinfo, 1, v2, 0x31u, (void **)&lc_time->wday_abbr[1]);
  v8 = _getlocaleinfo(&plocinfo, 1, v2, 0x32u, (void **)&lc_time->wday_abbr[2]) | v7;
  v9 = _getlocaleinfo(&plocinfo, 1, v2, 0x33u, (void **)&lc_time->wday_abbr[3]) | v8;
  v10 = _getlocaleinfo(&plocinfo, 1, v2, 0x34u, (void **)&lc_time->wday_abbr[4]) | v9;
  v11 = _getlocaleinfo(&plocinfo, 1, v2, 0x35u, (void **)&lc_time->wday_abbr[5]) | v10;
  v12 = _getlocaleinfo(&plocinfo, 1, v2, 0x36u, (void **)&lc_time->wday_abbr[6]) | v11;
  v13 = _getlocaleinfo(&plocinfo, 1, v2, 0x37u, (void **)lc_time->wday_abbr) | v12;
  v14 = _getlocaleinfo(&plocinfo, 1, v2, 0x2Au, (void **)&lc_time->wday[1]) | v13;
  v15 = _getlocaleinfo(&plocinfo, 1, v2, 0x2Bu, (void **)&lc_time->wday[2]) | v14;
  v16 = _getlocaleinfo(&plocinfo, 1, v2, 0x2Cu, (void **)&lc_time->wday[3]) | v15;
  v17 = _getlocaleinfo(&plocinfo, 1, v2, 0x2Du, (void **)&lc_time->wday[4]) | v16;
  v18 = _getlocaleinfo(&plocinfo, 1, v2, 0x2Eu, (void **)&lc_time->wday[5]) | v17;
  v19 = _getlocaleinfo(&plocinfo, 1, v2, 0x2Fu, (void **)&lc_time->wday[6]) | v18;
  v20 = _getlocaleinfo(&plocinfo, 1, v2, 0x30u, (void **)lc_time->wday) | v19;
  v21 = _getlocaleinfo(&plocinfo, 1, v2, 0x44u, (void **)lc_time->month_abbr) | v20;
  v22 = _getlocaleinfo(&plocinfo, 1, v2, 0x45u, (void **)&lc_time->month_abbr[1]) | v21;
  v23 = _getlocaleinfo(&plocinfo, 1, v2, 0x46u, (void **)&lc_time->month_abbr[2]) | v22;
  v24 = _getlocaleinfo(&plocinfo, 1, v2, 0x47u, (void **)&lc_time->month_abbr[3]) | v23;
  v25 = _getlocaleinfo(&plocinfo, 1, v2, 0x48u, (void **)&lc_time->month_abbr[4]) | v24;
  v26 = _getlocaleinfo(&plocinfo, 1, v2, 0x49u, (void **)&lc_time->month_abbr[5]) | v25;
  v27 = _getlocaleinfo(&plocinfo, 1, v2, 0x4Au, (void **)&lc_time->month_abbr[6]) | v26;
  v28 = _getlocaleinfo(&plocinfo, 1, v2, 0x4Bu, (void **)&lc_time->month_abbr[7]) | v27;
  v29 = _getlocaleinfo(&plocinfo, 1, v2, 0x4Cu, (void **)&lc_time->month_abbr[8]) | v28;
  v30 = _getlocaleinfo(&plocinfo, 1, v2, 0x4Du, (void **)&lc_time->month_abbr[9]) | v29;
  v31 = _getlocaleinfo(&plocinfo, 1, v2, 0x4Eu, (void **)&lc_time->month_abbr[10]) | v30;
  v32 = _getlocaleinfo(&plocinfo, 1, v2, 0x4Fu, (void **)&lc_time->month_abbr[11]) | v31;
  v33 = _getlocaleinfo(&plocinfo, 1, v2, 0x38u, (void **)lc_time->month) | v32;
  v34 = _getlocaleinfo(&plocinfo, 1, v2, 0x39u, (void **)&lc_time->month[1]) | v33;
  v35 = _getlocaleinfo(&plocinfo, 1, v2, 0x3Au, (void **)&lc_time->month[2]) | v34;
  v36 = _getlocaleinfo(&plocinfo, 1, v2, 0x3Bu, (void **)&lc_time->month[3]) | v35;
  v37 = _getlocaleinfo(&plocinfo, 1, v2, 0x3Cu, (void **)&lc_time->month[4]) | v36;
  v38 = _getlocaleinfo(&plocinfo, 1, v2, 0x3Du, (void **)&lc_time->month[5]) | v37;
  v39 = _getlocaleinfo(&plocinfo, 1, v2, 0x3Eu, (void **)&lc_time->month[6]) | v38;
  v40 = _getlocaleinfo(&plocinfo, 1, v2, 0x3Fu, (void **)&lc_time->month[7]) | v39;
  v41 = _getlocaleinfo(&plocinfo, 1, v2, 0x40u, (void **)&lc_time->month[8]) | v40;
  v42 = _getlocaleinfo(&plocinfo, 1, v2, 0x41u, (void **)&lc_time->month[9]) | v41;
  v43 = _getlocaleinfo(&plocinfo, 1, v2, 0x42u, (void **)&lc_time->month[10]) | v42;
  v44 = _getlocaleinfo(&plocinfo, 1, v2, 0x43u, (void **)&lc_time->month[11]) | v43;
  v45 = _getlocaleinfo(&plocinfo, 1, v2, 0x28u, (void **)lc_time->ampm) | v44;
  v46 = _getlocaleinfo(&plocinfo, 1, v2, 0x29u, (void **)&lc_time->ampm[1]) | v45;
  v47 = _getlocaleinfo(&plocinfo, 1, v2, 0x1Fu, (void **)&lc_time->ww_sdatefmt) | v46;
  v48 = _getlocaleinfo(&plocinfo, 1, v2, 0x20u, (void **)&lc_time->ww_ldatefmt) | v47;
  v49 = _getlocaleinfo(&plocinfo, 1, v2, 0x1003u, (void **)&lc_time->ww_timefmt) | v48;
  v50 = _getlocaleinfo(&plocinfo, 0, v2, 0x1009u, (void **)&lc_time->ww_caltype) | v49;
  v51 = _getlocaleinfo(&plocinfo, 2, v2, 0x31u, (void **)&lc_time->_W_wday_abbr[1]) | v50;
  v52 = _getlocaleinfo(&plocinfo, 2, v2, 0x32u, (void **)&lc_time->_W_wday_abbr[2]) | v51;
  v53 = _getlocaleinfo(&plocinfo, 2, v2, 0x33u, (void **)&lc_time->_W_wday_abbr[3]) | v52;
  v54 = _getlocaleinfo(&plocinfo, 2, v2, 0x34u, (void **)&lc_time->_W_wday_abbr[4]) | v53;
  v55 = _getlocaleinfo(&plocinfo, 2, v2, 0x35u, (void **)&lc_time->_W_wday_abbr[5]) | v54;
  v56 = _getlocaleinfo(&plocinfo, 2, v2, 0x36u, (void **)&lc_time->_W_wday_abbr[6]) | v55;
  v57 = _getlocaleinfo(&plocinfo, 2, v2, 0x37u, (void **)lc_time->_W_wday_abbr) | v56;
  v58 = _getlocaleinfo(&plocinfo, 2, v2, 0x2Au, (void **)&lc_time->_W_wday[1]) | v57;
  v59 = _getlocaleinfo(&plocinfo, 2, v2, 0x2Bu, (void **)&lc_time->_W_wday[2]) | v58;
  v60 = _getlocaleinfo(&plocinfo, 2, v2, 0x2Cu, (void **)&lc_time->_W_wday[3]) | v59;
  v61 = _getlocaleinfo(&plocinfo, 2, v2, 0x2Du, (void **)&lc_time->_W_wday[4]) | v60;
  v62 = _getlocaleinfo(&plocinfo, 2, v2, 0x2Eu, (void **)&lc_time->_W_wday[5]) | v61;
  v63 = _getlocaleinfo(&plocinfo, 2, v2, 0x2Fu, (void **)&lc_time->_W_wday[6]) | v62;
  v64 = _getlocaleinfo(&plocinfo, 2, v2, 0x30u, (void **)lc_time->_W_wday) | v63;
  v65 = _getlocaleinfo(&plocinfo, 2, v2, 0x44u, (void **)lc_time->_W_month_abbr) | v64;
  v66 = _getlocaleinfo(&plocinfo, 2, v2, 0x45u, (void **)&lc_time->_W_month_abbr[1]) | v65;
  v67 = _getlocaleinfo(&plocinfo, 2, v2, 0x46u, (void **)&lc_time->_W_month_abbr[2]) | v66;
  v68 = _getlocaleinfo(&plocinfo, 2, v2, 0x47u, (void **)&lc_time->_W_month_abbr[3]) | v67;
  v69 = _getlocaleinfo(&plocinfo, 2, v2, 0x48u, (void **)&lc_time->_W_month_abbr[4]) | v68;
  v70 = _getlocaleinfo(&plocinfo, 2, v2, 0x49u, (void **)&lc_time->_W_month_abbr[5]) | v69;
  v71 = _getlocaleinfo(&plocinfo, 2, v2, 0x4Au, (void **)&lc_time->_W_month_abbr[6]) | v70;
  v72 = _getlocaleinfo(&plocinfo, 2, v2, 0x4Bu, (void **)&lc_time->_W_month_abbr[7]) | v71;
  v73 = _getlocaleinfo(&plocinfo, 2, v2, 0x4Cu, (void **)&lc_time->_W_month_abbr[8]) | v72;
  v74 = _getlocaleinfo(&plocinfo, 2, v2, 0x4Du, (void **)&lc_time->_W_month_abbr[9]) | v73;
  v75 = _getlocaleinfo(&plocinfo, 2, v2, 0x4Eu, (void **)&lc_time->_W_month_abbr[10]) | v74;
  v76 = _getlocaleinfo(&plocinfo, 2, v2, 0x4Fu, (void **)&lc_time->_W_month_abbr[11]) | v75;
  v77 = _getlocaleinfo(&plocinfo, 2, v2, 0x38u, (void **)lc_time->_W_month) | v76;
  v78 = _getlocaleinfo(&plocinfo, 2, v2, 0x39u, (void **)&lc_time->_W_month[1]) | v77;
  v79 = _getlocaleinfo(&plocinfo, 2, v2, 0x3Au, (void **)&lc_time->_W_month[2]) | v78;
  v80 = _getlocaleinfo(&plocinfo, 2, v2, 0x3Bu, (void **)&lc_time->_W_month[3]) | v79;
  v81 = _getlocaleinfo(&plocinfo, 2, v2, 0x3Cu, (void **)&lc_time->_W_month[4]) | v80;
  v82 = _getlocaleinfo(&plocinfo, 2, v2, 0x3Du, (void **)&lc_time->_W_month[5]) | v81;
  v83 = _getlocaleinfo(&plocinfo, 2, v2, 0x3Eu, (void **)&lc_time->_W_month[6]) | v82;
  v84 = _getlocaleinfo(&plocinfo, 2, v2, 0x3Fu, (void **)&lc_time->_W_month[7]) | v83;
  v85 = _getlocaleinfo(&plocinfo, 2, v2, 0x40u, (void **)&lc_time->_W_month[8]) | v84;
  v86 = _getlocaleinfo(&plocinfo, 2, v2, 0x41u, (void **)&lc_time->_W_month[9]) | v85;
  v87 = _getlocaleinfo(&plocinfo, 2, v2, 0x42u, (void **)&lc_time->_W_month[10]) | v86;
  v88 = _getlocaleinfo(&plocinfo, 2, v2, 0x43u, (void **)&lc_time->_W_month[11]) | v87;
  v89 = _getlocaleinfo(&plocinfo, 2, v2, 0x28u, (void **)lc_time->_W_ampm) | v88;
  v90 = _getlocaleinfo(&plocinfo, 2, v2, 0x29u, (void **)&lc_time->_W_ampm[1]) | v89;
  v91 = _getlocaleinfo(&plocinfo, 2, v2, 0x1Fu, (void **)&lc_time->_W_ww_sdatefmt) | v90;
  v92 = _getlocaleinfo(&plocinfo, 2, v2, 0x20u, (void **)&lc_time->_W_ww_ldatefmt) | v91;
  return v92 | (unsigned int)_getlocaleinfo(&plocinfo, 2, v2, 0x1003u, (void **)&lc_time->_W_ww_timefmt);
}

// File Line: 230
// RVA: 0x12D9A20
void __fastcall _free_lc_time(__lc_time_data *lc_time)
{
  if ( lc_time )
  {
    free(lc_time->wday_abbr[1]);
    free(lc_time->wday_abbr[2]);
    free(lc_time->wday_abbr[3]);
    free(lc_time->wday_abbr[4]);
    free(lc_time->wday_abbr[5]);
    free(lc_time->wday_abbr[6]);
    free(lc_time->wday_abbr[0]);
    free(lc_time->wday[1]);
    free(lc_time->wday[2]);
    free(lc_time->wday[3]);
    free(lc_time->wday[4]);
    free(lc_time->wday[5]);
    free(lc_time->wday[6]);
    free(lc_time->wday[0]);
    free(lc_time->month_abbr[0]);
    free(lc_time->month_abbr[1]);
    free(lc_time->month_abbr[2]);
    free(lc_time->month_abbr[3]);
    free(lc_time->month_abbr[4]);
    free(lc_time->month_abbr[5]);
    free(lc_time->month_abbr[6]);
    free(lc_time->month_abbr[7]);
    free(lc_time->month_abbr[8]);
    free(lc_time->month_abbr[9]);
    free(lc_time->month_abbr[10]);
    free(lc_time->month_abbr[11]);
    free(lc_time->month[0]);
    free(lc_time->month[1]);
    free(lc_time->month[2]);
    free(lc_time->month[3]);
    free(lc_time->month[4]);
    free(lc_time->month[5]);
    free(lc_time->month[6]);
    free(lc_time->month[7]);
    free(lc_time->month[8]);
    free(lc_time->month[9]);
    free(lc_time->month[10]);
    free(lc_time->month[11]);
    free(lc_time->ampm[0]);
    free(lc_time->ampm[1]);
    free(lc_time->ww_sdatefmt);
    free(lc_time->ww_ldatefmt);
    free(lc_time->ww_timefmt);
    free(lc_time->_W_wday_abbr[1]);
    free(lc_time->_W_wday_abbr[2]);
    free(lc_time->_W_wday_abbr[3]);
    free(lc_time->_W_wday_abbr[4]);
    free(lc_time->_W_wday_abbr[5]);
    free(lc_time->_W_wday_abbr[6]);
    free(lc_time->_W_wday_abbr[0]);
    free(lc_time->_W_wday[1]);
    free(lc_time->_W_wday[2]);
    free(lc_time->_W_wday[3]);
    free(lc_time->_W_wday[4]);
    free(lc_time->_W_wday[5]);
    free(lc_time->_W_wday[6]);
    free(lc_time->_W_wday[0]);
    free(lc_time->_W_month_abbr[0]);
    free(lc_time->_W_month_abbr[1]);
    free(lc_time->_W_month_abbr[2]);
    free(lc_time->_W_month_abbr[3]);
    free(lc_time->_W_month_abbr[4]);
    free(lc_time->_W_month_abbr[5]);
    free(lc_time->_W_month_abbr[6]);
    free(lc_time->_W_month_abbr[7]);
    free(lc_time->_W_month_abbr[8]);
    free(lc_time->_W_month_abbr[9]);
    free(lc_time->_W_month_abbr[10]);
    free(lc_time->_W_month_abbr[11]);
    free(lc_time->_W_month[0]);
    free(lc_time->_W_month[1]);
    free(lc_time->_W_month[2]);
    free(lc_time->_W_month[3]);
    free(lc_time->_W_month[4]);
    free(lc_time->_W_month[5]);
    free(lc_time->_W_month[6]);
    free(lc_time->_W_month[7]);
    free(lc_time->_W_month[8]);
    free(lc_time->_W_month[9]);
    free(lc_time->_W_month[10]);
    free(lc_time->_W_month[11]);
    free(lc_time->_W_ampm[0]);
    free(lc_time->_W_ampm[1]);
    free(lc_time->_W_ww_sdatefmt);
    free(lc_time->_W_ww_ldatefmt);
    free(lc_time->_W_ww_timefmt);
    free(lc_time->_W_ww_locale_name);
  }
}

