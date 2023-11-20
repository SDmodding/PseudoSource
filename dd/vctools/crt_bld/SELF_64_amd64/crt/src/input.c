// File Line: 172
// RVA: 0x12D08D4
signed __int64 __fastcall _check_float_string_0(unsigned __int64 nFloatStrUsed, unsigned __int64 *pnFloatStrSz, wchar_t **pFloatStr, wchar_t *floatstring, int *pmalloc_FloatStrFlag)
{
  wchar_t *v5; // rsi
  void **v6; // rdi
  unsigned __int64 *v7; // rbx
  void *v8; // rax
  void *v10; // rax

  v5 = floatstring;
  v6 = (void **)pFloatStr;
  v7 = pnFloatStrSz;
  if ( nFloatStrUsed == *pnFloatStrSz )
  {
    if ( *pFloatStr == floatstring )
    {
      v8 = calloc_crt(*pnFloatStrSz, 4ui64);
      *v6 = v8;
      if ( !v8 )
        return 0i64;
      *pmalloc_FloatStrFlag = 1;
      memmove(*v6, v5, 2 * *v7);
      *v7 *= 2i64;
    }
    else
    {
      v10 = recalloc_crt(*pFloatStr, *pnFloatStrSz, 4ui64);
      if ( !v10 )
        return 0i64;
      *v6 = v10;
      *v7 *= 2i64;
    }
  }
  return 1i64;
}

// File Line: 372
// RVA: 0x12C7528
signed __int64 __fastcall input_l(_iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *arglist)
{
  localeinfo_struct *v4; // rbx
  int v5; // er13
  const char *v6; // r14
  _iobuf *v7; // rsi
  int v8; // edi
  int v10; // eax
  ioinfo *v11; // rdx
  ioinfo *v12; // r8
  unsigned __int8 v13; // al
  unsigned int v14; // ebx
  int v15; // er12
  unsigned int v16; // er15
  int v17; // eax
  int v18; // ebx
  const char *v19; // r12
  char v20; // si
  char v21; // r14
  int v22; // edi
  int v23; // ebx
  __int64 v24; // rax
  char v25; // dl
  unsigned __int8 v26; // r12
  char v27; // al
  signed __int64 v28; // rcx
  char v29; // bl
  int v30; // er13
  int v31; // esi
  int v32; // eax
  signed int v33; // eax
  int v34; // esi
  int v35; // eax
  unsigned __int64 v36; // rbx
  _iobuf *v37; // r13
  int v38; // er12
  int v39; // eax
  int v40; // ecx
  int v41; // eax
  int v42; // er14
  char v43; // si
  int i; // ecx
  int v45; // eax
  signed int v46; // esi
  int v47; // eax
  int v48; // er14
  int v49; // eax
  int v50; // eax
  int j; // ecx
  int v52; // eax
  char *v53; // rsi
  PVOID v54; // rax
  bool v55; // zf
  bool v56; // sf
  const char *v57; // r14
  char v58; // r12
  signed int v59; // eax
  unsigned __int8 v60; // al
  unsigned __int8 v61; // cl
  unsigned __int8 v62; // r9
  _QWORD *v63; // rbx
  int v64; // ecx
  int v65; // eax
  int v66; // eax
  int v67; // ecx
  _QWORD *v68; // rdx
  _iobuf *v69; // r12
  int v70; // er14
  int v71; // er14
  _QWORD *v72; // rax
  __int64 v73; // rsi
  int v74; // er14
  _iobuf *v75; // rbx
  signed __int64 v76; // rsi
  int v77; // ebx
  int v78; // eax
  int v79; // esi
  int v80; // er14
  _iobuf *v81; // rbx
  int v82; // esi
  int v83; // ebx
  int v84; // eax
  signed int v85; // eax
  int v86; // eax
  int v87; // eax
  int v88; // ecx
  _iobuf *v89; // rdx
  char v90; // [rsp+30h] [rbp-D0h]
  int v91; // [rsp+34h] [rbp-CCh]
  char v92; // [rsp+38h] [rbp-C8h]
  char v93; // [rsp+39h] [rbp-C7h]
  int v94; // [rsp+3Ch] [rbp-C4h]
  char v95; // [rsp+40h] [rbp-C0h]
  int v96; // [rsp+44h] [rbp-BCh]
  int v97; // [rsp+44h] [rbp-BCh]
  signed int v98; // [rsp+48h] [rbp-B8h]
  const char *v99; // [rsp+50h] [rbp-B0h]
  const char *v100; // [rsp+50h] [rbp-B0h]
  char v101; // [rsp+58h] [rbp-A8h]
  int v102; // [rsp+5Ch] [rbp-A4h]
  signed int v103; // [rsp+60h] [rbp-A0h]
  _iobuf *fileptr; // [rsp+68h] [rbp-98h]
  int v105; // [rsp+70h] [rbp-90h]
  unsigned int v106; // [rsp+74h] [rbp-8Ch]
  int pmalloc_FloatStrFlag; // [rsp+78h] [rbp-88h]
  wchar_t pwc; // [rsp+7Ch] [rbp-84h]
  char *pFloatStr; // [rsp+80h] [rbp-80h]
  __int64 v110; // [rsp+88h] [rbp-78h]
  char s; // [rsp+90h] [rbp-70h]
  char v112; // [rsp+91h] [rbp-6Fh]
  int v113; // [rsp+94h] [rbp-6Ch]
  _QWORD *v114; // [rsp+98h] [rbp-68h]
  unsigned __int64 pnFloatStrSz; // [rsp+A0h] [rbp-60h]
  int v116; // [rsp+A8h] [rbp-58h]
  char *v117; // [rsp+B0h] [rbp-50h]
  char *v118; // [rsp+B8h] [rbp-48h]
  _LocaleUpdate v119; // [rsp+C0h] [rbp-40h]
  char Dst[11]; // [rsp+E0h] [rbp-20h]
  char v121; // [rsp+EBh] [rbp-15h]
  char floatstring; // [rsp+100h] [rbp+0h]

  v117 = arglist;
  v4 = plocinfo;
  pFloatStr = &floatstring;
  v5 = 0;
  v6 = format;
  v99 = format;
  v7 = stream;
  fileptr = stream;
  pmalloc_FloatStrFlag = 0;
  pwc = 0;
  v8 = 0;
  v94 = 0;
  pnFloatStrSz = 350i64;
  if ( !format )
    goto LABEL_309;
  if ( (signed int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  if ( !v7 )
    goto LABEL_309;
  if ( !(v7->_flag & 0x40) )
  {
    v10 = fileno(v7);
    v11 = &_badioinfo;
    v12 = (unsigned int)(v10 + 2) <= 1 ? &_badioinfo : &_pioinfo[(signed __int64)v10 >> 5][v10 & 0x1F];
    if ( *((_BYTE *)v12 + 56) & 0x7F )
      goto LABEL_309;
    if ( (unsigned int)(v10 + 2) > 1 )
      v11 = &_pioinfo[(signed __int64)v10 >> 5][v10 & 0x1F];
    if ( *((_BYTE *)v11 + 56) < 0 )
    {
LABEL_309:
      *errno() = 22;
      invalid_parameter_noinfo();
      return 0xFFFFFFFFi64;
    }
  }
  _LocaleUpdate::_LocaleUpdate(&v119, v4);
  v13 = *v6;
  v14 = 0;
  v93 = 0;
  v15 = 0;
  v91 = 0;
  v106 = 0;
  if ( !*v6 )
  {
LABEL_303:
    v16 = v14;
    goto LABEL_304;
  }
  v16 = -1;
LABEL_16:
  if ( (unsigned int)isspace(v13) )
  {
    --v15;
    while ( 1 )
    {
      v91 = ++v15;
      v17 = inc(v7);
      v18 = v17;
      if ( v17 == -1 )
        break;
      if ( !(unsigned int)isspace((unsigned __int8)v17) )
      {
        ungetc_nolock(v18, v7);
        goto LABEL_21;
      }
    }
    do
LABEL_21:
      ++v6;
    while ( (unsigned int)isspace(*(unsigned __int8 *)v6) );
    v99 = v6;
    goto LABEL_287;
  }
  if ( *v6 != 37 )
    goto LABEL_281;
  if ( v6[1] == 37 )
  {
    if ( *v6 == 37 && v6[1] == 37 )
      ++v6;
LABEL_281:
    v91 = ++v15;
    v8 = inc(v7);
    v94 = v8;
    v86 = *(unsigned __int8 *)v6++;
    v99 = v6;
    if ( v86 == v8 )
    {
      if ( !(unsigned int)isleadbyte((unsigned __int8)v8) )
        goto LABEL_284;
      v87 = inc(v7);
      v88 = *(unsigned __int8 *)v6++;
      v99 = v6;
      if ( v88 == v87 )
        goto LABEL_284;
      if ( v87 != -1 )
        ungetc_nolock(v87, v7);
    }
    if ( v8 == -1 )
      goto $error_return_1;
    v89 = v7;
    goto LABEL_295;
  }
  v19 = v99;
  v102 = 0;
  v98 = 0;
  v103 = 0;
  v101 = 0;
  v95 = 0;
  v92 = 1;
  v90 = 0;
  v20 = 0;
  LOBYTE(v113) = 0;
  v21 = 0;
  v22 = 0;
  do
  {
    v23 = *(unsigned __int8 *)++v19;
    v24 = isdigit(v23);
    if ( (_DWORD)v24 )
    {
      ++v103;
      v5 = v23 + 2 * (5 * v5 - 24);
      goto LABEL_43;
    }
    if ( v23 != 42 )
    {
      switch ( v23 )
      {
        case 70:
          goto LABEL_43;
        case 73:
          v27 = v19[1];
          if ( v27 != 54 || v19[2] != 52 )
          {
            if ( v27 == 51 && v19[2] == 50 )
            {
              v19 += 2;
              goto LABEL_43;
            }
            LOBYTE(v24) = v27 - 88;
            if ( (unsigned __int8)v24 > 0x20u || (v28 = 4303491073i64, !_bittest64(&v28, v24)) )
            {
              v110 = 0i64;
              ++v22;
$DEFAULT_LABEL:
              ++v20;
              goto LABEL_43;
            }
          }
          else
          {
            v19 += 2;
          }
          break;
        case 76:
          ++v92;
          goto LABEL_43;
        case 78:
LABEL_43:
          v25 = v90;
          continue;
        case 104:
          --v92;
          --v21;
          goto LABEL_43;
        case 108:
          if ( v19[1] != 108 )
          {
            ++v92;
            goto LABEL_41;
          }
          ++v19;
          break;
        case 119:
LABEL_41:
          ++v21;
          goto LABEL_43;
        default:
          goto $DEFAULT_LABEL;
      }
      ++v22;
      v110 = 0i64;
      goto LABEL_43;
    }
    v25 = v90++ + 1;
  }
  while ( !v20 );
  v105 = v22;
  v8 = v94;
  v100 = v19;
  v26 = 0;
  v96 = v5;
  if ( v25 )
  {
    v114 = 0i64;
  }
  else
  {
    v118 = v117;
    v117 += 8;
    v114 = (_QWORD *)*((_QWORD *)v117 - 1);
  }
  v29 = 0;
  if ( !v21 )
    v21 = ((*v100 - 67) & 0xEF) != 0 ? -1 : 1;
  v30 = *(unsigned __int8 *)v100 | 0x20;
  v116 = v30;
  if ( v30 == 110 )
  {
LABEL_73:
    v33 = v103;
    v34 = v96;
    if ( v103 && !v96 )
      goto LABEL_289;
    if ( v30 > 111 )
    {
      switch ( v30 )
      {
        case 112:
          v110 = 0i64;
          ++v105;
          v92 = 1;
          goto LABEL_216;
        case 115:
          v58 = v113;
          v55 = v21 == 0;
          v56 = v21 < 0;
          v57 = v100;
          if ( !v56 && !v55 )
            v58 = 1;
          goto $scanit;
        case 117:
          goto LABEL_216;
        case 120:
          goto LABEL_86;
      }
      if ( v30 != 123 )
        goto LABEL_138;
      v59 = (unsigned __int8)v113;
      if ( v21 > 0 )
        v59 = 1;
      v57 = v100 + 1;
      v55 = v100[1] == 94;
      v113 = v59;
      if ( v55 )
      {
        v57 = v100 + 2;
        v101 = -1;
      }
      memset(Dst, 0, 0x20ui64);
      if ( *v57 == 93 )
      {
        v26 = 93;
        ++v57;
        v121 = 32;
      }
      v60 = *v57;
      if ( *v57 != 93 )
      {
        do
        {
          ++v57;
          if ( v60 == 45 && v26 && (v61 = *v57, *v57 != 93) )
          {
            ++v57;
            if ( v26 >= v61 )
            {
              v62 = v26;
              v26 = v61;
            }
            else
            {
              v62 = v61;
            }
            while ( v26 < (signed int)v62 )
            {
              Dst[(unsigned __int64)v26 >> 3] |= 1 << (v26 & 7);
              ++v26;
            }
            v26 = 0;
            Dst[(unsigned __int64)v62 >> 3] |= 1 << (v62 & 7);
          }
          else
          {
            v26 = v60;
            Dst[(unsigned __int64)v60 >> 3] |= 1 << (v60 & 7);
          }
          v60 = *v57;
        }
        while ( *v57 != 93 );
        v16 = -1;
      }
      if ( !*v57 )
        goto $error_return_1;
    }
    else
    {
      if ( v30 == 111 )
        goto LABEL_216;
      if ( v30 != 99 )
      {
        if ( v30 != 100 )
        {
          if ( v30 <= 100 )
            goto LABEL_138;
          if ( v30 <= 103 )
          {
            v36 = 0i64;
            if ( v8 == 45 )
            {
              v36 = 1i64;
              *pFloatStr = 45;
              goto $f_incwidth;
            }
            if ( v8 == 43 )
            {
$f_incwidth:
              v37 = fileptr;
              v34 = v96 - 1;
              v38 = v91 + 1;
              v39 = inc(fileptr);
              v8 = v39;
              v94 = v39;
              v33 = v103;
            }
            else
            {
              v38 = v91;
              v37 = fileptr;
            }
            v40 = (unsigned __int8)v8;
            if ( !v33 )
              v34 = -1;
            v97 = v34;
            while ( (unsigned int)isdigit(v40) )
            {
              v41 = v34--;
              v97 = v34;
              if ( !v41 )
                break;
              ++v98;
              pFloatStr[v36++] = v8;
              if ( !(unsigned int)_check_float_string(
                                    v36,
                                    &pnFloatStrSz,
                                    &pFloatStr,
                                    &floatstring,
                                    &pmalloc_FloatStrFlag) )
                goto $error_return_1;
              ++v38;
              v8 = inc(v37);
              v94 = v8;
              v40 = (unsigned __int8)v8;
            }
            v42 = v97;
            v43 = *v119.localeinfo.locinfo->lconv->decimal_point;
            if ( v43 == (_BYTE)v8 )
            {
              v42 = v97 - 1;
              if ( v97 )
              {
                ++v38;
                v8 = inc(v37);
                v94 = v8;
                pFloatStr[v36++] = v43;
                if ( !(unsigned int)_check_float_string(
                                      v36,
                                      &pnFloatStrSz,
                                      &pFloatStr,
                                      &floatstring,
                                      &pmalloc_FloatStrFlag) )
                  goto $error_return_1;
                for ( i = (unsigned __int8)v8; (unsigned int)isdigit(i); i = (unsigned __int8)v8 )
                {
                  v45 = v42--;
                  if ( !v45 )
                    break;
                  ++v98;
                  pFloatStr[v36++] = v8;
                  if ( !(unsigned int)_check_float_string(
                                        v36,
                                        &pnFloatStrSz,
                                        &pFloatStr,
                                        &floatstring,
                                        &pmalloc_FloatStrFlag) )
                    goto $error_return_1;
                  ++v38;
                  v8 = inc(v37);
                  v94 = v8;
                }
              }
            }
            v46 = v98;
            if ( v98 )
            {
              if ( !((v8 - 69) & 0xFFFFFFDF) )
              {
                v47 = v42;
                v48 = v42 - 1;
                if ( v47 )
                {
                  pFloatStr[v36++] = 101;
                  if ( !(unsigned int)_check_float_string(
                                        v36,
                                        &pnFloatStrSz,
                                        &pFloatStr,
                                        &floatstring,
                                        &pmalloc_FloatStrFlag) )
                    goto $error_return_1;
                  ++v38;
                  v49 = inc(v37);
                  v8 = v49;
                  v94 = v49;
                  if ( v49 == 45 )
                  {
                    pFloatStr[v36++] = 45;
                    if ( !(unsigned int)_check_float_string(
                                          v36,
                                          &pnFloatStrSz,
                                          &pFloatStr,
                                          &floatstring,
                                          &pmalloc_FloatStrFlag) )
                      goto $error_return_1;
$f_incwidth2:
                    v50 = v48--;
                    if ( v50 )
                    {
                      ++v38;
                      v8 = inc(v37);
                      v94 = v8;
                    }
                    else
                    {
                      v48 = 0;
                    }
                  }
                  else if ( v49 == 43 )
                  {
                    goto $f_incwidth2;
                  }
                  for ( j = (unsigned __int8)v8; (unsigned int)isdigit(j); j = (unsigned __int8)v8 )
                  {
                    v52 = v48--;
                    if ( !v52 )
                      break;
                    ++v46;
                    pFloatStr[v36++] = v8;
                    if ( !(unsigned int)_check_float_string(
                                          v36,
                                          &pnFloatStrSz,
                                          &pFloatStr,
                                          &floatstring,
                                          &pmalloc_FloatStrFlag) )
                      goto $error_return_1;
                    ++v38;
                    v8 = inc(v37);
                    v94 = v8;
                  }
                }
              }
            }
            v15 = v38 - 1;
            v91 = v15;
            if ( v8 != -1 )
              ungetc_nolock(v8, v37);
            v5 = 0;
            if ( !v46 )
              goto $error_return_1;
            if ( !v90 )
            {
              v53 = pFloatStr;
              ++v106;
              pFloatStr[v36] = 0;
              v54 = DecodePointer(off_142125688);
              ((void (__fastcall *)(_QWORD, _QWORD *, char *, _LocaleUpdate *))v54)(
                (unsigned int)(v92 - 1),
                v114,
                v53,
                &v119);
            }
LABEL_272:
            v57 = v100;
            goto LABEL_277;
          }
          if ( v30 != 105 )
          {
            if ( v30 == 110 )
            {
              v15 = v91;
              v5 = 0;
              v35 = v91;
              if ( !v25 )
                goto $assign_num;
              goto LABEL_272;
            }
LABEL_138:
            v57 = v100;
            if ( *(unsigned __int8 *)v100 == v8 )
            {
              --v93;
              v15 = v91;
              v5 = 0;
              if ( !v25 )
                v117 = v118;
              goto LABEL_277;
            }
LABEL_289:
            if ( v8 == -1 )
              goto $error_return_1;
            v89 = fileptr;
LABEL_295:
            ungetc_nolock(v8, v89);
            goto $error_return_1;
          }
          v30 = 100;
LABEL_86:
          if ( v8 == 45 )
          {
            v95 = 1;
          }
          else if ( v8 != 43 )
          {
            goto LABEL_184;
          }
          v34 = v96 - 1;
          v96 = v34;
          if ( v34 || !v103 )
          {
            v69 = fileptr;
            v70 = v91++ + 1;
            v8 = inc(fileptr);
            v94 = v8;
LABEL_185:
            if ( v8 == 48 )
            {
              v71 = v70 + 1;
              v91 = v71;
              v8 = inc(v69);
              v94 = v8;
              if ( ((_BYTE)v8 - 88) & 0xDF )
              {
                v98 = 1;
                if ( v30 == 120 )
                {
                  v91 = --v71;
                  if ( v8 != -1 )
                    ungetc_nolock(v8, v69);
                  v8 = 48;
                  v94 = 48;
                }
                else
                {
                  if ( v103 )
                  {
                    v96 = v34 - 1;
                    if ( v34 == 1 )
                      ++v29;
                  }
                  v30 = 111;
                }
              }
              else
              {
                v91 = ++v71;
                v8 = inc(v69);
                v94 = v8;
                if ( v103 )
                {
                  v96 = v34 - 2;
                  if ( v34 - 2 < 1 )
                    ++v29;
                }
                v30 = 120;
              }
              v15 = v71;
              goto $getnum;
            }
            goto LABEL_222;
          }
          v29 = 1;
LABEL_184:
          v69 = fileptr;
          v70 = v91;
          goto LABEL_185;
        }
LABEL_216:
        if ( v8 == 45 )
        {
          v95 = 1;
        }
        else if ( v8 != 43 )
        {
          goto LABEL_222;
        }
        --v96;
        if ( v34 != 1 || !v103 )
        {
          v15 = v91++ + 1;
          v8 = inc(fileptr);
          v94 = v8;
          goto $getnum;
        }
        v29 = 1;
LABEL_222:
        v15 = v91;
$getnum:
        if ( !v105 )
        {
          v79 = 0;
          if ( !v29 )
          {
            v80 = v96;
            v81 = fileptr;
            while ( 1 )
            {
              if ( (v30 - 112) & 0xFFFFFFF7 )
              {
                if ( !(unsigned int)isdigit((unsigned __int8)v8) )
                  goto LABEL_260;
                if ( v30 == 111 )
                {
                  if ( v8 >= 56 )
                    goto LABEL_260;
                  v82 = 8 * v79;
                }
                else
                {
                  v82 = 10 * v79;
                }
              }
              else
              {
                if ( !(unsigned int)isxdigit((unsigned __int8)v8) )
                {
LABEL_260:
                  v91 = --v15;
                  if ( v8 != -1 )
                    ungetc_nolock(v8, v81);
                  v79 = v102;
                  break;
                }
                v83 = (char)v8;
                v84 = isdigit((unsigned __int8)v8);
                v82 = 16 * v102;
                v8 = ((char)v8 & 0xFFFFFFDF) - 7;
                if ( v84 )
                  v8 = v83;
                v94 = v8;
              }
              ++v98;
              v79 = v8 + v82 - 48;
              v102 = v79;
              if ( v103 )
              {
                if ( !--v80 )
                  break;
              }
              v81 = fileptr;
              v91 = ++v15;
              v8 = inc(fileptr);
              v94 = v8;
            }
          }
          if ( v95 )
            v102 = -v79;
          goto LABEL_265;
        }
        v73 = v110;
        if ( v29 )
          goto LABEL_243;
        v74 = v96;
        v75 = fileptr;
        while ( 1 )
        {
          if ( (v30 - 112) & 0xFFFFFFF7 )
          {
            if ( !(unsigned int)isdigit((unsigned __int8)v8) )
              goto LABEL_240;
            if ( v30 == 111 )
            {
              if ( v8 >= 56 )
                goto LABEL_240;
              v76 = 8 * v73;
            }
            else
            {
              v76 = 10 * v73;
            }
          }
          else
          {
            if ( !(unsigned int)isxdigit((unsigned __int8)v8) )
            {
LABEL_240:
              v91 = --v15;
              if ( v8 != -1 )
                ungetc_nolock(v8, v75);
              v73 = v110;
LABEL_243:
              if ( v95 )
                v110 = -v73;
LABEL_265:
              v85 = v98;
              v55 = v30 == 70;
              v5 = 0;
              if ( v55 )
                v85 = 0;
              if ( !v85 )
                goto $error_return_1;
              if ( v90 )
                goto LABEL_272;
              ++v106;
              v35 = v102;
$assign_num:
              if ( v105 )
              {
                *v114 = v110;
                goto LABEL_272;
              }
              v57 = v100;
              if ( v92 )
                *(_DWORD *)v114 = v35;
              else
                *(_WORD *)v114 = v35;
LABEL_277:
              v7 = fileptr;
              ++v93;
              v6 = v57 + 1;
              v99 = v6;
LABEL_284:
              if ( v8 == -1 && (*v6 != 37 || v6[1] != 110) )
                goto $error_return_1;
LABEL_287:
              v13 = *v6;
              if ( !*v6 )
                goto $error_return_1;
              goto LABEL_16;
            }
            v110 *= 16i64;
            v77 = (char)v8;
            v78 = isdigit((unsigned __int8)v8);
            v76 = v110;
            v8 = ((char)v8 & 0xFFFFFFDF) - 7;
            if ( v78 )
              v8 = v77;
            v94 = v8;
          }
          ++v98;
          v73 = v8 - 48 + v76;
          v110 = v73;
          if ( v103 )
          {
            if ( !--v74 )
              goto LABEL_243;
          }
          v75 = fileptr;
          v91 = ++v15;
          v8 = inc(fileptr);
          v94 = v8;
        }
      }
      if ( !v103 )
      {
        v103 = 1;
        v34 = v96 + 1;
      }
      v55 = v21 == 0;
      v56 = v21 < 0;
      v57 = v100;
      if ( !v56 && !v55 )
      {
        v58 = 1;
$scanit:
        v63 = v114;
        v64 = v91-- - 1;
        if ( v8 != -1 )
        {
          ungetc_nolock(v8, fileptr);
LABEL_165:
          v64 = v91;
          goto LABEL_166;
        }
        while ( 1 )
        {
LABEL_166:
          if ( v103 )
          {
            v65 = v34--;
            if ( !v65 )
              goto LABEL_209;
          }
          v91 = v64 + 1;
          v66 = inc(fileptr);
          v8 = v66;
          v94 = v66;
          if ( v66 == -1 )
            break;
          if ( v30 != 99 )
          {
            if ( v30 != 115 )
              goto LABEL_310;
            if ( (unsigned int)(v66 - 9) <= 4 )
              break;
            if ( v66 == 32 )
            {
LABEL_310:
              if ( v30 != 123 )
                break;
              v67 = v101 ^ Dst[(signed __int64)v66 >> 3];
              if ( !_bittest(&v67, v66 & 7) )
                break;
            }
          }
          if ( v90 )
          {
            v63 = (_QWORD *)((char *)v63 + 1);
          }
          else
          {
            if ( v58 )
            {
              s = v66;
              if ( (unsigned int)isleadbyte((unsigned __int8)v66) )
              {
                ++v91;
                v112 = inc(fileptr);
              }
              pwc = 63;
              mbtowc_l(&pwc, &s, v119.localeinfo.locinfo->mb_cur_max, &v119.localeinfo);
              v68 = v114;
              *(_WORD *)v114 = pwc;
              v114 = (_QWORD *)((char *)v68 + 2);
              goto LABEL_165;
            }
            v72 = v114;
            *(_BYTE *)v114 = v8;
            v114 = (_QWORD *)((char *)v72 + 1);
          }
          v64 = v91;
        }
        --v91;
        if ( v66 != -1 )
          ungetc_nolock(v66, fileptr);
LABEL_209:
        if ( v63 != v114 )
        {
          if ( v90 || (++v106, v30 == 99) )
          {
            v15 = v91;
            v5 = 0;
          }
          else
          {
            v5 = 0;
            v55 = v58 == 0;
            v15 = v91;
            if ( v55 )
              *(_BYTE *)v114 = 0;
            else
              *(_WORD *)v114 = 0;
          }
          goto LABEL_277;
        }
        goto $error_return_1;
      }
    }
    v58 = v113;
    goto $scanit;
  }
  if ( v30 == 99 || v30 == 123 )
  {
    ++v91;
    v8 = inc(fileptr);
    v94 = v8;
  }
  else
  {
    v31 = v91;
    v29 = 0;
    do
    {
      ++v31;
      v32 = inc(fileptr);
      v8 = v32;
      v94 = v32;
    }
    while ( v32 != -1 && (unsigned int)isspace((unsigned __int8)v32) );
    v30 = v116;
    v91 = v31;
  }
  if ( v8 != -1 )
  {
    v25 = v90;
    goto LABEL_73;
  }
$error_return_1:
  if ( pmalloc_FloatStrFlag == 1 )
    free(pFloatStr);
  LOBYTE(v5) = 0;
  if ( v8 != -1 )
  {
    v14 = v106;
    goto LABEL_303;
  }
  if ( v106 || v93 )
    v16 = v106;
LABEL_304:
  if ( v119.updated != (_BYTE)v5 )
    v119.ptd->_ownlocale &= 0xFFFFFFFD;
  return v16;
}

// File Line: 1425
// RVA: 0x12C7500
__int64 __fastcall inc(_iobuf *fileptr)
{
  bool v1; // sf
  unsigned int v2; // edx

  v1 = fileptr->_cnt-- - 1 < 0;
  if ( v1 )
    v2 = filbuf(fileptr);
  else
    v2 = *(unsigned __int8 *)fileptr->_ptr++;
  return v2;
}

// File Line: 1437
// RVA: 0x12D0970
__int64 __fastcall whiteout(int *counter, _iobuf *fileptr)
{
  _iobuf *v2; // rsi
  int *v3; // rdi
  unsigned __int16 v4; // bx

  v2 = fileptr;
  v3 = counter;
  do
  {
    ++*v3;
    v4 = fgetwc_nolock(v2);
  }
  while ( v4 != -1 && iswctype(v4, 8u) );
  return v4;
}

