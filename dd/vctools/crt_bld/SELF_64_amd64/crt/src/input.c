// File Line: 172
// RVA: 0x12D08D4
__int64 __fastcall _check_float_string_0(
        unsigned __int64 nFloatStrUsed,
        unsigned __int64 *pnFloatStrSz,
        wchar_t **pFloatStr,
        wchar_t *floatstring,
        int *pmalloc_FloatStrFlag)
{
  wchar_t *v8; // rax
  wchar_t *v10; // rax

  if ( nFloatStrUsed == *pnFloatStrSz )
  {
    if ( *pFloatStr == floatstring )
    {
      v8 = (wchar_t *)calloc_crt(*pnFloatStrSz, 4ui64);
      *pFloatStr = v8;
      if ( !v8 )
        return 0i64;
      *pmalloc_FloatStrFlag = 1;
      memmove(*pFloatStr, floatstring, 2 * *pnFloatStrSz);
      *pnFloatStrSz *= 2i64;
    }
    else
    {
      v10 = (wchar_t *)recalloc_crt(*pFloatStr, *pnFloatStrSz, 4ui64);
      if ( !v10 )
        return 0i64;
      *pFloatStr = v10;
      *pnFloatStrSz *= 2i64;
    }
  }
  return 1i64;
}

// File Line: 372
// RVA: 0x12C7528
__int64 __fastcall input_l(_iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *arglist)
{
  int v5; // r13d
  const char *v6; // r14
  _iobuf *v7; // rsi
  signed int v8; // edi
  int v10; // eax
  ioinfo *v11; // rdx
  ioinfo *v12; // r8
  unsigned __int8 v13; // al
  unsigned int v14; // ebx
  int v15; // r12d
  unsigned int v16; // r15d
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
  __int64 v28; // rcx
  char v29; // bl
  int v30; // r13d
  int v31; // esi
  signed int v32; // eax
  int v33; // eax
  int v34; // esi
  int v35; // eax
  __int64 v36; // rbx
  _iobuf *v37; // r13
  int v38; // r12d
  int v39; // ecx
  int v40; // eax
  int v41; // r14d
  char v42; // si
  int i; // ecx
  int v45; // esi
  int v46; // eax
  int v47; // r14d
  signed int v48; // eax
  int j; // ecx
  char *v52; // rsi
  PVOID v53; // rax
  bool v54; // cc
  const char *v55; // r14
  char v56; // r12
  int v57; // eax
  bool v58; // zf
  unsigned __int8 v59; // al
  unsigned __int8 v60; // cl
  unsigned __int8 v61; // r9
  _QWORD *v62; // rbx
  int v63; // ecx
  int v65; // eax
  int v66; // ecx
  _QWORD *v67; // rdx
  _iobuf *v68; // r12
  int v69; // r14d
  int v70; // r14d
  _QWORD *v71; // rax
  __int64 v72; // rsi
  int v73; // r14d
  _iobuf *v74; // rbx
  __int64 v75; // rsi
  signed int v76; // ebx
  int v77; // eax
  int v78; // esi
  int v79; // r14d
  _iobuf *v80; // rbx
  int v81; // esi
  signed int v82; // ebx
  int v83; // eax
  int v84; // eax
  int v85; // eax
  int v86; // eax
  int v87; // ecx
  _iobuf *v88; // rdx
  char v89; // [rsp+30h] [rbp-D0h]
  int v90; // [rsp+34h] [rbp-CCh]
  char v91; // [rsp+38h] [rbp-C8h]
  char v92; // [rsp+39h] [rbp-C7h]
  int v93; // [rsp+3Ch] [rbp-C4h]
  char v94; // [rsp+40h] [rbp-C0h]
  int v95; // [rsp+44h] [rbp-BCh]
  int v96; // [rsp+44h] [rbp-BCh]
  int v97; // [rsp+48h] [rbp-B8h]
  const char *v98; // [rsp+50h] [rbp-B0h]
  const char *v99; // [rsp+50h] [rbp-B0h]
  char v100; // [rsp+58h] [rbp-A8h]
  int v101; // [rsp+5Ch] [rbp-A4h]
  int v102; // [rsp+60h] [rbp-A0h]
  int v104; // [rsp+70h] [rbp-90h]
  unsigned int v105; // [rsp+74h] [rbp-8Ch]
  int pmalloc_FloatStrFlag; // [rsp+78h] [rbp-88h] BYREF
  wchar_t pwc; // [rsp+7Ch] [rbp-84h] BYREF
  char *pFloatStr; // [rsp+80h] [rbp-80h] BYREF
  __int64 v109; // [rsp+88h] [rbp-78h]
  char s[4]; // [rsp+90h] [rbp-70h] BYREF
  int v111; // [rsp+94h] [rbp-6Ch]
  _QWORD *v112; // [rsp+98h] [rbp-68h]
  unsigned __int64 pnFloatStrSz; // [rsp+A0h] [rbp-60h] BYREF
  int v114; // [rsp+A8h] [rbp-58h]
  char *v115; // [rsp+B0h] [rbp-50h]
  char *v116; // [rsp+B8h] [rbp-48h]
  _LocaleUpdate v117; // [rsp+C0h] [rbp-40h] BYREF
  char Dst[32]; // [rsp+E0h] [rbp-20h] BYREF
  char floatstring[352]; // [rsp+100h] [rbp+0h] BYREF

  v115 = arglist;
  pFloatStr = floatstring;
  v5 = 0;
  v6 = format;
  v98 = format;
  v7 = stream;
  pmalloc_FloatStrFlag = 0;
  pwc = 0;
  v8 = 0;
  v93 = 0;
  pnFloatStrSz = 350i64;
  if ( !format )
    goto LABEL_2;
  if ( (int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  if ( !v7 )
    goto LABEL_2;
  if ( (v7->_flag & 0x40) == 0 )
  {
    v10 = fileno(v7);
    v11 = &_badioinfo;
    v12 = (unsigned int)(v10 + 2) <= 1 ? &_badioinfo : &_pioinfo[(__int64)v10 >> 5][v10 & 0x1F];
    if ( (*((_BYTE *)v12 + 56) & 0x7F) != 0 )
      goto LABEL_2;
    if ( (unsigned int)(v10 + 2) > 1 )
      v11 = &_pioinfo[(__int64)v10 >> 5][v10 & 0x1F];
    if ( *((char *)v11 + 56) < 0 )
    {
LABEL_2:
      *errno() = 22;
      invalid_parameter_noinfo();
      return 0xFFFFFFFFi64;
    }
  }
  _LocaleUpdate::_LocaleUpdate(&v117, plocinfo);
  v13 = *v6;
  v14 = 0;
  v92 = 0;
  v15 = 0;
  v90 = 0;
  v105 = 0;
  if ( !*v6 )
  {
LABEL_302:
    v16 = v14;
    goto LABEL_303;
  }
  v16 = -1;
LABEL_16:
  if ( (unsigned int)isspace(v13) )
  {
    --v15;
    while ( 1 )
    {
      v90 = ++v15;
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
    v98 = v6;
    goto LABEL_286;
  }
  if ( *v6 != 37 )
    goto LABEL_280;
  if ( v6[1] == 37 )
  {
    if ( *v6 == 37 && v6[1] == 37 )
      ++v6;
LABEL_280:
    v90 = ++v15;
    v8 = inc(v7);
    v93 = v8;
    v85 = *(unsigned __int8 *)v6++;
    v98 = v6;
    if ( v85 == v8 )
    {
      if ( !(unsigned int)isleadbyte(v8) )
        goto LABEL_283;
      v86 = inc(v7);
      v87 = *(unsigned __int8 *)v6++;
      v98 = v6;
      if ( v87 == v86 )
        goto LABEL_283;
      if ( v86 != -1 )
        ungetc_nolock(v86, v7);
    }
    if ( v8 == -1 )
      goto $error_return_1;
    v88 = v7;
    goto LABEL_294;
  }
  v19 = v98;
  v101 = 0;
  v97 = 0;
  v102 = 0;
  v100 = 0;
  v94 = 0;
  v91 = 1;
  v89 = 0;
  v20 = 0;
  LOBYTE(v111) = 0;
  v21 = 0;
  v22 = 0;
  do
  {
    v23 = *(unsigned __int8 *)++v19;
    v24 = isdigit(v23);
    if ( (_DWORD)v24 )
    {
      ++v102;
      v5 = v23 + 2 * (5 * v5 - 24);
      goto LABEL_43;
    }
    if ( v23 != 42 )
    {
      switch ( v23 )
      {
        case F:
          goto LABEL_43;
        case I:
          v27 = v19[1];
          if ( v27 == 54 && v19[2] == 52 )
          {
            v19 += 2;
          }
          else
          {
            if ( v27 == 51 && v19[2] == 50 )
            {
              v19 += 2;
              goto LABEL_43;
            }
            LOBYTE(v24) = v27 - 88;
            if ( (unsigned __int8)v24 > 0x20u || (v28 = 0x100821001i64, !_bittest64(&v28, v24)) )
            {
              v109 = 0i64;
              ++v22;
$DEFAULT_LABEL:
              ++v20;
              goto LABEL_43;
            }
          }
          break;
        case L:
          ++v91;
          goto LABEL_43;
        case N:
LABEL_43:
          v25 = v89;
          continue;
        case h:
          --v91;
          --v21;
          goto LABEL_43;
        case l:
          if ( v19[1] != 108 )
          {
            ++v91;
            goto LABEL_41;
          }
          ++v19;
          break;
        case w:
LABEL_41:
          ++v21;
          goto LABEL_43;
        default:
          goto $DEFAULT_LABEL;
      }
      ++v22;
      v109 = 0i64;
      goto LABEL_43;
    }
    v25 = ++v89;
  }
  while ( !v20 );
  v104 = v22;
  v8 = v93;
  v99 = v19;
  v26 = 0;
  v95 = v5;
  if ( v25 )
  {
    v112 = 0i64;
  }
  else
  {
    v116 = v115;
    v115 += 8;
    v112 = (_QWORD *)*((_QWORD *)v115 - 1);
  }
  v29 = 0;
  if ( !v21 )
    v21 = ((*v99 - 67) & 0xEF) != 0 ? -1 : 1;
  v30 = *(unsigned __int8 *)v99 | 0x20;
  v114 = v30;
  if ( v30 == 110 )
  {
LABEL_73:
    v33 = v102;
    v34 = v95;
    if ( v102 && !v95 )
      goto LABEL_288;
    if ( v30 > 111 )
    {
      switch ( v30 )
      {
        case p:
          v109 = 0i64;
          ++v104;
          v91 = 1;
          goto LABEL_215;
        case s:
          v56 = v111;
          v54 = v21 <= 0;
          v55 = v99;
          if ( !v54 )
            v56 = 1;
          goto $scanit;
        case u:
          goto LABEL_215;
        case x:
          goto LABEL_86;
      }
      if ( v30 != 123 )
        goto LABEL_138;
      v57 = (unsigned __int8)v111;
      if ( v21 > 0 )
        v57 = 1;
      v55 = v99 + 1;
      v58 = v99[1] == 94;
      v111 = v57;
      if ( v58 )
      {
        v55 = v99 + 2;
        v100 = -1;
      }
      memset(Dst, 0, sizeof(Dst));
      if ( *v55 == 93 )
      {
        v26 = 93;
        ++v55;
        Dst[11] = 32;
      }
      v59 = *v55;
      if ( *v55 != 93 )
      {
        do
        {
          ++v55;
          if ( v59 == 45 && v26 && (v60 = *v55, *v55 != 93) )
          {
            ++v55;
            if ( v26 >= v60 )
            {
              v61 = v26;
              v26 = v60;
            }
            else
            {
              v61 = v60;
            }
            while ( v26 < (int)v61 )
            {
              Dst[(unsigned __int64)v26 >> 3] |= 1 << (v26 & 7);
              ++v26;
            }
            v26 = 0;
            Dst[(unsigned __int64)v61 >> 3] |= 1 << (v61 & 7);
          }
          else
          {
            v26 = v59;
            Dst[(unsigned __int64)v59 >> 3] |= 1 << (v59 & 7);
          }
          v59 = *v55;
        }
        while ( *v55 != 93 );
        v16 = -1;
      }
      if ( !*v55 )
        goto $error_return_1;
    }
    else
    {
      if ( v30 == 111 )
        goto LABEL_215;
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
              v37 = stream;
              v34 = v95 - 1;
              v38 = v90 + 1;
              v8 = inc(stream);
              v93 = v8;
              v33 = v102;
            }
            else
            {
              v38 = v90;
              v37 = stream;
            }
            v39 = (unsigned __int8)v8;
            if ( !v33 )
              v34 = -1;
            v96 = v34;
            while ( (unsigned int)isdigit(v39) )
            {
              v40 = v34--;
              v96 = v34;
              if ( !v40 )
                break;
              ++v97;
              pFloatStr[v36] = v8;
              if ( !(unsigned int)_check_float_string(
                                    ++v36,
                                    &pnFloatStrSz,
                                    &pFloatStr,
                                    floatstring,
                                    &pmalloc_FloatStrFlag) )
                goto $error_return_1;
              ++v38;
              v8 = inc(v37);
              v93 = v8;
              v39 = (unsigned __int8)v8;
            }
            v41 = v96;
            v42 = *v117.localeinfo.locinfo->lconv->decimal_point;
            if ( v42 == (_BYTE)v8 )
            {
              v41 = v96 - 1;
              if ( v96 )
              {
                ++v38;
                v8 = inc(v37);
                v93 = v8;
                pFloatStr[v36] = v42;
                if ( !(unsigned int)_check_float_string(
                                      ++v36,
                                      &pnFloatStrSz,
                                      &pFloatStr,
                                      floatstring,
                                      &pmalloc_FloatStrFlag) )
                  goto $error_return_1;
                for ( i = (unsigned __int8)v8; (unsigned int)isdigit(i); i = (unsigned __int8)v8 )
                {
                  if ( !v41-- )
                    break;
                  ++v97;
                  pFloatStr[v36] = v8;
                  if ( !(unsigned int)_check_float_string(
                                        ++v36,
                                        &pnFloatStrSz,
                                        &pFloatStr,
                                        floatstring,
                                        &pmalloc_FloatStrFlag) )
                    goto $error_return_1;
                  ++v38;
                  v8 = inc(v37);
                  v93 = v8;
                }
              }
            }
            v45 = v97;
            if ( v97 )
            {
              if ( ((v8 - 69) & 0xFFFFFFDF) == 0 )
              {
                v46 = v41;
                v47 = v41 - 1;
                if ( v46 )
                {
                  pFloatStr[v36] = 101;
                  if ( !(unsigned int)_check_float_string(
                                        ++v36,
                                        &pnFloatStrSz,
                                        &pFloatStr,
                                        floatstring,
                                        &pmalloc_FloatStrFlag) )
                    goto $error_return_1;
                  ++v38;
                  v48 = inc(v37);
                  v8 = v48;
                  v93 = v48;
                  if ( v48 == 45 )
                  {
                    pFloatStr[v36] = 45;
                    if ( !(unsigned int)_check_float_string(
                                          ++v36,
                                          &pnFloatStrSz,
                                          &pFloatStr,
                                          floatstring,
                                          &pmalloc_FloatStrFlag) )
                      goto $error_return_1;
$f_incwidth2:
                    if ( v47-- )
                    {
                      ++v38;
                      v8 = inc(v37);
                      v93 = v8;
                    }
                    else
                    {
                      v47 = 0;
                    }
                  }
                  else if ( v48 == 43 )
                  {
                    goto $f_incwidth2;
                  }
                  for ( j = (unsigned __int8)v8; (unsigned int)isdigit(j); j = (unsigned __int8)v8 )
                  {
                    if ( !v47-- )
                      break;
                    ++v45;
                    pFloatStr[v36] = v8;
                    if ( !(unsigned int)_check_float_string(
                                          ++v36,
                                          &pnFloatStrSz,
                                          &pFloatStr,
                                          floatstring,
                                          &pmalloc_FloatStrFlag) )
                      goto $error_return_1;
                    ++v38;
                    v8 = inc(v37);
                    v93 = v8;
                  }
                }
              }
            }
            v15 = v38 - 1;
            v90 = v15;
            if ( v8 != -1 )
              ungetc_nolock(v8, v37);
            v5 = 0;
            if ( !v45 )
              goto $error_return_1;
            if ( !v89 )
            {
              v52 = pFloatStr;
              ++v105;
              pFloatStr[v36] = 0;
              v53 = DecodePointer(off_142125688);
              ((void (__fastcall *)(_QWORD, _QWORD *, char *, _LocaleUpdate *))v53)(
                (unsigned int)(v91 - 1),
                v112,
                v52,
                &v117);
            }
LABEL_271:
            v55 = v99;
            goto LABEL_276;
          }
          if ( v30 != 105 )
          {
            if ( v30 == 110 )
            {
              v15 = v90;
              v5 = 0;
              v35 = v90;
              if ( !v25 )
                goto $assign_num;
              goto LABEL_271;
            }
LABEL_138:
            v55 = v99;
            if ( *(unsigned __int8 *)v99 == v8 )
            {
              --v92;
              v15 = v90;
              v5 = 0;
              if ( !v25 )
                v115 = v116;
              goto LABEL_276;
            }
LABEL_288:
            if ( v8 == -1 )
              goto $error_return_1;
            v88 = stream;
LABEL_294:
            ungetc_nolock(v8, v88);
            goto $error_return_1;
          }
          v30 = 100;
LABEL_86:
          if ( v8 == 45 )
          {
            v94 = 1;
          }
          else if ( v8 != 43 )
          {
            goto LABEL_183;
          }
          v34 = v95 - 1;
          v95 = v34;
          if ( v34 || !v102 )
          {
            v68 = stream;
            v69 = ++v90;
            v8 = inc(stream);
            v93 = v8;
LABEL_184:
            if ( v8 == 48 )
            {
              v70 = v69 + 1;
              v90 = v70;
              v8 = inc(v68);
              v93 = v8;
              if ( (((_BYTE)v8 - 88) & 0xDF) != 0 )
              {
                v97 = 1;
                if ( v30 == 120 )
                {
                  v90 = --v70;
                  if ( v8 != -1 )
                    ungetc_nolock(v8, v68);
                  v8 = 48;
                  v93 = 48;
                }
                else
                {
                  if ( v102 )
                  {
                    v95 = v34 - 1;
                    if ( v34 == 1 )
                      ++v29;
                  }
                  v30 = 111;
                }
              }
              else
              {
                v90 = ++v70;
                v8 = inc(v68);
                v93 = v8;
                if ( v102 )
                {
                  v95 = v34 - 2;
                  if ( v34 - 2 < 1 )
                    ++v29;
                }
                v30 = 120;
              }
              v15 = v70;
              goto $getnum;
            }
            goto LABEL_221;
          }
          v29 = 1;
LABEL_183:
          v68 = stream;
          v69 = v90;
          goto LABEL_184;
        }
LABEL_215:
        if ( v8 == 45 )
        {
          v94 = 1;
        }
        else if ( v8 != 43 )
        {
          goto LABEL_221;
        }
        --v95;
        if ( v34 != 1 || !v102 )
        {
          v15 = ++v90;
          v8 = inc(stream);
          v93 = v8;
          goto $getnum;
        }
        v29 = 1;
LABEL_221:
        v15 = v90;
$getnum:
        if ( !v104 )
        {
          v78 = 0;
          if ( !v29 )
          {
            v79 = v95;
            v80 = stream;
            while ( 1 )
            {
              if ( ((v30 - 112) & 0xFFFFFFF7) != 0 )
              {
                if ( !(unsigned int)isdigit((unsigned __int8)v8) )
                  goto LABEL_259;
                if ( v30 == 111 )
                {
                  if ( v8 >= 56 )
                    goto LABEL_259;
                  v81 = 8 * v78;
                }
                else
                {
                  v81 = 10 * v78;
                }
              }
              else
              {
                if ( !(unsigned int)isxdigit((unsigned __int8)v8) )
                {
LABEL_259:
                  v90 = --v15;
                  if ( v8 != -1 )
                    ungetc_nolock(v8, v80);
                  v78 = v101;
                  break;
                }
                v82 = (char)v8;
                v83 = isdigit((unsigned __int8)v8);
                v81 = 16 * v101;
                v8 = ((char)v8 & 0xFFFFFFDF) - 7;
                if ( v83 )
                  v8 = v82;
                v93 = v8;
              }
              ++v97;
              v78 = v8 + v81 - 48;
              v101 = v78;
              if ( v102 )
              {
                if ( !--v79 )
                  break;
              }
              v80 = stream;
              v90 = ++v15;
              v8 = inc(stream);
              v93 = v8;
            }
          }
          if ( v94 )
            v101 = -v78;
          goto LABEL_264;
        }
        v72 = v109;
        if ( v29 )
          goto LABEL_242;
        v73 = v95;
        v74 = stream;
        while ( 1 )
        {
          if ( ((v30 - 112) & 0xFFFFFFF7) != 0 )
          {
            if ( !(unsigned int)isdigit((unsigned __int8)v8) )
              goto LABEL_239;
            if ( v30 == 111 )
            {
              if ( v8 >= 56 )
                goto LABEL_239;
              v75 = 8 * v72;
            }
            else
            {
              v75 = 10 * v72;
            }
          }
          else
          {
            if ( !(unsigned int)isxdigit((unsigned __int8)v8) )
            {
LABEL_239:
              v90 = --v15;
              if ( v8 != -1 )
                ungetc_nolock(v8, v74);
              v72 = v109;
LABEL_242:
              if ( v94 )
                v109 = -v72;
LABEL_264:
              v84 = v97;
              v58 = v30 == 70;
              v5 = 0;
              if ( v58 )
                v84 = 0;
              if ( !v84 )
                goto $error_return_1;
              if ( v89 )
                goto LABEL_271;
              ++v105;
              v35 = v101;
$assign_num:
              if ( v104 )
              {
                *v112 = v109;
                goto LABEL_271;
              }
              v55 = v99;
              if ( v91 )
                *(_DWORD *)v112 = v35;
              else
                *(_WORD *)v112 = v35;
LABEL_276:
              v7 = stream;
              ++v92;
              v6 = v55 + 1;
              v98 = v6;
LABEL_283:
              if ( v8 == -1 && (*v6 != 37 || v6[1] != 110) )
                goto $error_return_1;
LABEL_286:
              v13 = *v6;
              if ( !*v6 )
                goto $error_return_1;
              goto LABEL_16;
            }
            v109 *= 16i64;
            v76 = (char)v8;
            v77 = isdigit((unsigned __int8)v8);
            v75 = v109;
            v8 = ((char)v8 & 0xFFFFFFDF) - 7;
            if ( v77 )
              v8 = v76;
            v93 = v8;
          }
          ++v97;
          v72 = v8 - 48 + v75;
          v109 = v72;
          if ( v102 )
          {
            if ( !--v73 )
              goto LABEL_242;
          }
          v74 = stream;
          v90 = ++v15;
          v8 = inc(stream);
          v93 = v8;
        }
      }
      if ( !v102 )
      {
        v102 = 1;
        v34 = v95 + 1;
      }
      v54 = v21 <= 0;
      v55 = v99;
      if ( !v54 )
      {
        v56 = 1;
$scanit:
        v62 = v112;
        v63 = --v90;
        if ( v8 != -1 )
        {
          ungetc_nolock(v8, stream);
LABEL_164:
          v63 = v90;
          goto LABEL_165;
        }
        while ( 1 )
        {
LABEL_165:
          if ( v102 )
          {
            if ( !v34-- )
              goto LABEL_208;
          }
          v90 = v63 + 1;
          v65 = inc(stream);
          v8 = v65;
          v93 = v65;
          if ( v65 == -1 )
            break;
          if ( v30 != 99 )
          {
            if ( v30 != 115 )
              goto LABEL_308;
            if ( (unsigned int)(v65 - 9) <= 4 )
              break;
            if ( v65 == 32 )
            {
LABEL_308:
              if ( v30 != 123 )
                break;
              v66 = v100 ^ Dst[(__int64)v65 >> 3];
              if ( !_bittest(&v66, v65 & 7) )
                break;
            }
          }
          if ( v89 )
          {
            v62 = (_QWORD *)((char *)v62 + 1);
          }
          else
          {
            if ( v56 )
            {
              s[0] = v65;
              if ( (unsigned int)isleadbyte(v65) )
              {
                ++v90;
                s[1] = inc(stream);
              }
              pwc = 63;
              mbtowc_l(&pwc, s, v117.localeinfo.locinfo->mb_cur_max, &v117.localeinfo);
              v67 = v112;
              *(_WORD *)v112 = pwc;
              v112 = (_QWORD *)((char *)v67 + 2);
              goto LABEL_164;
            }
            v71 = v112;
            *(_BYTE *)v112 = v8;
            v112 = (_QWORD *)((char *)v71 + 1);
          }
          v63 = v90;
        }
        --v90;
        if ( v65 != -1 )
          ungetc_nolock(v65, stream);
LABEL_208:
        if ( v62 != v112 )
        {
          if ( v89 || (++v105, v30 == 99) )
          {
            v15 = v90;
            v5 = 0;
          }
          else
          {
            v5 = 0;
            v58 = v56 == 0;
            v15 = v90;
            if ( v58 )
              *(_BYTE *)v112 = 0;
            else
              *(_WORD *)v112 = 0;
          }
          goto LABEL_276;
        }
        goto $error_return_1;
      }
    }
    v56 = v111;
    goto $scanit;
  }
  if ( v30 == 99 || v30 == 123 )
  {
    ++v90;
    v8 = inc(stream);
    v93 = v8;
  }
  else
  {
    v31 = v90;
    v29 = 0;
    do
    {
      ++v31;
      v32 = inc(stream);
      v8 = v32;
      v93 = v32;
    }
    while ( v32 != -1 && (unsigned int)isspace((unsigned __int8)v32) );
    v30 = v114;
    v90 = v31;
  }
  if ( v8 != -1 )
  {
    v25 = v89;
    goto LABEL_73;
  }
$error_return_1:
  if ( pmalloc_FloatStrFlag == 1 )
    free(pFloatStr);
  if ( v8 != -1 )
  {
    v14 = v105;
    goto LABEL_302;
  }
  if ( v105 || v92 )
    v16 = v105;
LABEL_303:
  if ( v117.updated )
    v117.ptd->_ownlocale &= ~2u;
  return v16;
}        {
            v5 = 0;
            v58 = v56 == 0;
            v15 = v90;
            if ( v58 )
              *(_BYTE *)v112 = 0

// File Line: 1425
// RVA: 0x12C7500
__int64 __fastcall inc(_iobuf *fileptr)
{
  if ( --fileptr->_cnt < 0 )
    return (unsigned int)filbuf(fileptr);
  else
    return *(unsigned __int8 *)fileptr->_ptr++;
}

// File Line: 1437
// RVA: 0x12D0970
__int64 __fastcall whiteout(int *counter, _iobuf *fileptr)
{
  unsigned __int16 v4; // bx

  do
  {
    ++*counter;
    v4 = fgetwc_nolock(fileptr);
  }
  while ( v4 != 0xFFFF && iswctype(v4, 8u) );
  return v4;
}

