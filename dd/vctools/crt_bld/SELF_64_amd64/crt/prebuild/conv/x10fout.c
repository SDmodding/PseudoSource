// File Line: 66
// RVA: 0x12DB480
__int64 __fastcall _I10_OUTPUT(_LDOUBLE *ld, int ndigits, unsigned int output_flags, _FloatOutStruct *fos)
{
  __int16 v4; // di
  int v5; // er10
  _FloatOutStruct *v6; // rbx
  unsigned int v7; // er9
  unsigned int v8; // er11
  __int16 v9; // cx
  unsigned __int16 v10; // di
  char v11; // al
  int v12; // er8
  unsigned int v13; // edx
  signed int v14; // er12
  _LDBL12 *v15; // r9
  int v16; // edx
  int v17; // ecx
  int v18; // er10
  bool v19; // zf
  unsigned int v20; // er8
  unsigned int v21; // edx
  char v22; // al
  int v23; // eax
  __int64 *v24; // rsi
  unsigned __int64 v25; // rcx
  int v26; // eax
  __int16 v27; // cx
  __int16 v28; // bx
  unsigned __int16 v29; // cx
  __int16 v30; // bx
  unsigned __int16 v31; // r9
  int v32; // er14
  __int64 *v33; // rdx
  signed int v34; // edi
  signed int v35; // er13
  unsigned __int16 *v36; // r12
  char *v37; // r15
  signed int v38; // er10
  unsigned int v39; // ecx
  unsigned int v40; // er8
  unsigned int v41; // er10
  unsigned int v42; // er8
  unsigned __int16 v43; // r9
  int v44; // edx
  __int64 v45; // rdx
  int v46; // er9
  unsigned int v47; // eax
  unsigned __int16 v48; // ax
  bool v49; // cf
  unsigned __int16 v50; // cx
  __int16 v51; // r13
  unsigned __int16 v52; // r9
  int v53; // edi
  __int64 *v54; // rcx
  signed int v55; // er15
  int *v56; // rsi
  char *v57; // r14
  signed int v58; // er8
  unsigned int v59; // edx
  unsigned int v60; // er10
  unsigned int v61; // er8
  unsigned int v62; // er10
  unsigned __int16 v63; // r9
  int v64; // edx
  int v65; // ebx
  __int64 v66; // rdx
  unsigned int v67; // eax
  unsigned __int16 v68; // ax
  int v69; // er14
  unsigned int v70; // er9
  unsigned int v71; // esi
  signed __int64 v72; // r10
  int v73; // er9
  unsigned int v74; // ecx
  int v75; // er10
  unsigned int v76; // eax
  unsigned int v77; // ecx
  int v78; // er12
  char *v79; // rdi
  char *v80; // r10
  unsigned int v81; // eax
  unsigned int v82; // edx
  int v83; // er9
  unsigned int v84; // ecx
  unsigned int v85; // er8
  unsigned int v86; // er13
  int v87; // er9
  signed int v88; // ecx
  unsigned int v89; // er14
  char *v90; // r10
  char v91; // al
  char *v92; // r10
  char v93; // r10
  char v95; // al
  __int16 v96; // [rsp+32h] [rbp-67h]
  int v97; // [rsp+38h] [rbp-61h]
  _LDBL12 *v98; // [rsp+40h] [rbp-59h]
  int v99; // [rsp+48h] [rbp-51h]
  int v100; // [rsp+4Ch] [rbp-4Dh]
  signed int v101; // [rsp+50h] [rbp-49h]
  _FloatOutStruct *v102; // [rsp+58h] [rbp-41h]
  char v103; // [rsp+60h] [rbp-39h]
  __int64 *v104; // [rsp+68h] [rbp-31h]
  __int64 v105; // [rsp+70h] [rbp-29h]
  unsigned int v106; // [rsp+78h] [rbp-21h]
  char v107[10]; // [rsp+80h] [rbp-19h]
  unsigned __int16 v108; // [rsp+8Ah] [rbp-Fh]
  int v109; // [rsp+90h] [rbp-9h]
  int v110; // [rsp+94h] [rbp-5h]
  int v111; // [rsp+98h] [rbp-1h]
  unsigned __int64 v112; // [rsp+A0h] [rbp+7h]
  int v113; // [rsp+A8h] [rbp+Fh]

  v4 = *(_WORD *)&ld->ld[8];
  v5 = *(_DWORD *)ld->ld;
  v6 = fos;
  v7 = *(_DWORD *)&ld->ld[4];
  v8 = 1;
  v100 = ndigits;
  v9 = v4 & 0x8000;
  v103 = output_flags;
  v10 = v4 & 0x7FFF;
  v102 = v6;
  v109 = -858993460;
  v110 = -858993460;
  v111 = 1073466572;
  v96 = v9;
  v11 = 32;
  if ( v9 )
    v6->sign = 45;
  else
    v6->sign = 32;
  if ( v10 )
  {
    if ( v10 != 0x7FFF )
      goto LABEL_29;
    v6->exp = 1;
    if ( (v7 != 2147483648 || v5) && !_bittest((const signed int *)&v7, 0x1Eu) )
    {
      if ( (unsigned int)strcpy_s(v6->man, 0x16ui64, "1#SNAN") )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
LABEL_190:
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
        goto LABEL_191;
      }
      goto LABEL_27;
    }
    if ( v9 && v7 == -1073741824 )
    {
      if ( !v5 )
      {
        if ( (unsigned int)strcpy_s(v6->man, 0x16ui64, "1#IND") )
          goto LABEL_190;
        goto LABEL_25;
      }
    }
    else if ( v7 == 2147483648 && !v5 )
    {
      if ( (unsigned int)strcpy_s(v6->man, 0x16ui64, "1#INF") )
      {
LABEL_191:
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
        goto LABEL_192;
      }
LABEL_25:
      v6->ManLen = 5;
      return 0;
    }
    if ( (unsigned int)strcpy_s(v6->man, 0x16ui64, "1#QNAN") )
    {
LABEL_192:
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
      JUMPOUT(*(_QWORD *)mbsnbcmp);
    }
LABEL_27:
    v6->ManLen = 6;
    return 0;
  }
  if ( !v7 && !v5 )
  {
    if ( v9 == -32768 )
      v11 = 45;
    goto LABEL_9;
  }
LABEL_29:
  *(_DWORD *)&v107[6] = v7;
  *(_DWORD *)&v107[2] = v5;
  v12 = 19728 * v10;
  v13 = ((unsigned int)v10 >> 8) + 2 * (v7 >> 24);
  v14 = 5;
  v15 = &pow10pos[-8];
  v108 = v10;
  *(_WORD *)v107 = 0;
  v16 = 77 * v13;
  v101 = 5;
  v17 = (v16 + v12 - 323162868) >> 16;
  v97 = (v16 + v12 - 323162868) >> 16;
  v18 = -(signed __int16)((unsigned int)(v16 + v12 - 323162868) >> 16);
  if ( (unsigned int)(v16 + v12 - 323162868) >> 16 )
  {
    v19 = (signed __int16)((unsigned int)(v16 + v12 - 323162868) >> 16) == 0;
    if ( v18 < 0 )
    {
      v18 = (signed __int16)((unsigned int)(v16 + v12 - 323162868) >> 16);
      v15 = &pow10neg[-8];
      v19 = v18 == 0;
    }
    if ( !v19 )
    {
      v20 = *(_DWORD *)&v107[4];
      v21 = *(_DWORD *)v107;
      while ( 1 )
      {
        v22 = v18;
        v15 += 7;
        v18 >>= 3;
        v99 = v18;
        v98 = v15;
        v23 = v22 & 7;
        if ( v23 )
          break;
LABEL_91:
        if ( !v18 )
        {
          v6 = v102;
          LOWORD(v17) = v97;
          goto LABEL_94;
        }
      }
      v24 = (__int64 *)v15[v23].ld12;
      v104 = v24;
      if ( *(_WORD *)v24 >= 0x8000u )
      {
        v25 = *v24;
        v26 = *((_DWORD *)v24 + 2);
        v24 = (__int64 *)&v112;
        v112 = v25;
        v113 = v26;
        v104 = (__int64 *)&v112;
        *(_DWORD *)((char *)&v112 + 2) = (v25 >> 16) - 1;
      }
      v27 = *((_WORD *)v24 + 5);
      v28 = v27;
      v29 = v27 & 0x7FFF;
      v105 = 0i64;
      v106 = 0;
      v30 = (v108 ^ v28) & 0x8000;
      v31 = (v108 & 0x7FFF) + v29;
      if ( (v108 & 0x7FFFu) >= 0x7FFF || v29 >= 0x7FFFu || v31 > 0xBFFDu )
      {
        v49 = v30 != 0;
      }
      else
      {
        if ( v31 <= 0x3FBFu )
        {
LABEL_41:
          *(_QWORD *)&v107[4] = 0i64;
LABEL_89:
          v21 = 0;
          v20 = 0;
          *(_DWORD *)v107 = 0;
          goto LABEL_90;
        }
        if ( !(v108 & 0x7FFF) )
        {
          ++v31;
          if ( !(*(_DWORD *)&v107[8] & 0x7FFFFFFF) && !v20 && !v21 )
          {
            v108 = 0;
LABEL_90:
            v15 = v98;
            goto LABEL_91;
          }
        }
        if ( !v29 )
        {
          ++v31;
          if ( !(v24[1] & 0x7FFFFFFF) && !*((_DWORD *)v24 + 1) && !*(_DWORD *)v24 )
            goto LABEL_41;
        }
        v32 = 0;
        v33 = &v105;
        v34 = 5;
        do
        {
          v35 = v34;
          if ( v34 > 0 )
          {
            v36 = (unsigned __int16 *)(v24 + 1);
            v37 = &v107[2 * v32];
            do
            {
              v38 = 0;
              v39 = *v36 * *(unsigned __int16 *)v37;
              v40 = *(_DWORD *)v33 + v39;
              if ( v40 < *(_DWORD *)v33 || v40 < v39 )
                v38 = 1;
              *(_DWORD *)v33 = v40;
              if ( v38 )
                ++*((_WORD *)v33 + 2);
              --v35;
              v37 += 2;
              --v36;
            }
            while ( v35 > 0 );
            v24 = v104;
          }
          --v34;
          v33 = (__int64 *)((char *)v33 + 2);
          ++v32;
        }
        while ( v34 > 0 );
        v41 = v106;
        v42 = v105;
        v43 = v31 - 16382;
        if ( (signed __int16)v43 > 0 )
        {
          do
          {
            if ( v41 & 0x80000000 )
              break;
            v44 = (unsigned __int64)v42 >> 31;
            v42 *= 2;
            --v43;
            v41 = (HIDWORD(v105) >> 31) | 2 * v41;
            LODWORD(v105) = v42;
            HIDWORD(v105) = v44 | 2 * HIDWORD(v105);
            v106 = v41;
          }
          while ( (signed __int16)v43 > 0 );
          if ( (signed __int16)v43 > 0 )
            goto LABEL_196;
        }
        if ( (--v43 & 0x8000u) == 0 )
          goto LABEL_196;
        v45 = (unsigned __int16)-v43;
        v46 = 0;
        do
        {
          if ( v105 & 1 )
            ++v46;
          v47 = v41 << 31;
          v41 >>= 1;
          v42 = (HIDWORD(v105) << 31) | (v42 >> 1);
          HIDWORD(v105) = v47 | (HIDWORD(v105) >> 1);
          LODWORD(v105) = v42;
          --v45;
        }
        while ( v45 );
        v19 = v46 == 0;
        v43 = 0;
        v106 = v41;
        if ( v19 )
        {
LABEL_196:
          v48 = v105;
        }
        else
        {
          v48 = v42 | 1;
          LOWORD(v105) = v42 | 1;
          v42 = v105;
        }
        if ( v48 > 0x8000u || (v42 & 0x1FFFF) == 98304 )
        {
          if ( *(_DWORD *)((char *)&v105 + 2) == -1 )
          {
            *(_DWORD *)((char *)&v105 + 2) = 0;
            if ( *(_DWORD *)((char *)&v105 + 6) == -1 )
            {
              *(_DWORD *)((char *)&v105 + 6) = 0;
              if ( HIWORD(v106) == -1 )
              {
                HIWORD(v106) = -32768;
                ++v43;
              }
              else
              {
                ++HIWORD(v106);
              }
            }
            else
            {
              ++*(_DWORD *)((char *)&v105 + 6);
            }
            v41 = v106;
          }
          else
          {
            ++*(_DWORD *)((char *)&v105 + 2);
          }
        }
        v14 = 5;
        if ( v43 < 0x7FFFu )
        {
          *(_DWORD *)&v107[6] = v41;
          v18 = v99;
          *(_WORD *)v107 = WORD1(v105);
          *(_DWORD *)&v107[2] = HIDWORD(v105);
          v20 = *(_DWORD *)&v107[4];
          v21 = *(_DWORD *)v107;
          v108 = v30 | v43;
          goto LABEL_90;
        }
        v18 = v99;
        v49 = v30 != 0;
      }
      *(_DWORD *)&v107[4] = 0;
      *(_DWORD *)&v107[8] = v49 ? -32768 : 2147450880;
      goto LABEL_89;
    }
  }
  v20 = *(_DWORD *)&v107[4];
  v21 = *(_DWORD *)v107;
LABEL_94:
  if ( v108 >= 0x3FFFu )
  {
    LOWORD(v97) = v17 + 1;
    v50 = HIWORD(v111) & 0x7FFF;
    v105 = 0i64;
    v106 = 0;
    v51 = (v108 ^ HIWORD(v111)) & 0x8000;
    v52 = (v108 & 0x7FFF) + (HIWORD(v111) & 0x7FFF);
    if ( (v108 & 0x7FFFu) >= 0x7FFF || v50 >= 0x7FFFu || v52 > 0xBFFDu )
    {
      *(_DWORD *)&v107[8] = ((v108 ^ HIWORD(v111)) & 0x8000u) != 0 ? -32768 : 2147450880;
    }
    else
    {
      if ( v52 > 0x3FBFu )
      {
        if ( !(v108 & 0x7FFF) )
        {
          ++v52;
          if ( !(*(_DWORD *)&v107[8] & 0x7FFFFFFF) && !v20 && !v21 )
          {
            v108 = 0;
            goto LABEL_147;
          }
        }
        if ( v50 || (++v52, v111 & 0x7FFFFFFF) || v110 || v109 )
        {
          v53 = 0;
          v54 = &v105;
          do
          {
            v55 = v14;
            if ( v14 > 0 )
            {
              v56 = &v111;
              v57 = &v107[2 * v53];
              do
              {
                v58 = 0;
                v59 = *(unsigned __int16 *)v57 * *(unsigned __int16 *)v56;
                v60 = *(_DWORD *)v54 + v59;
                if ( v60 < *(_DWORD *)v54 || v60 < v59 )
                  v58 = 1;
                *(_DWORD *)v54 = v60;
                if ( v58 )
                  ++*((_WORD *)v54 + 2);
                --v55;
                v57 += 2;
                v56 = (int *)((char *)v56 - 2);
              }
              while ( v55 > 0 );
              v14 = v101;
            }
            --v14;
            v54 = (__int64 *)((char *)v54 + 2);
            ++v53;
            v101 = v14;
          }
          while ( v14 > 0 );
          v6 = v102;
          v61 = v106;
          v62 = v105;
          v63 = v52 - 16382;
          if ( (signed __int16)v63 > 0 )
          {
            do
            {
              if ( v61 & 0x80000000 )
                break;
              v64 = (unsigned __int64)v62 >> 31;
              v62 *= 2;
              --v63;
              v61 = (HIDWORD(v105) >> 31) | 2 * v61;
              LODWORD(v105) = v62;
              HIDWORD(v105) = v64 | 2 * HIDWORD(v105);
              v106 = v61;
            }
            while ( (signed __int16)v63 > 0 );
            if ( (signed __int16)v63 > 0 )
              goto LABEL_197;
          }
          if ( (--v63 & 0x8000u) == 0 )
            goto LABEL_197;
          v65 = 0;
          v66 = (unsigned __int16)-v63;
          v63 = 0;
          do
          {
            if ( v105 & 1 )
              ++v65;
            v67 = v61 << 31;
            v61 >>= 1;
            v62 = (HIDWORD(v105) << 31) | (v62 >> 1);
            HIDWORD(v105) = v67 | (HIDWORD(v105) >> 1);
            LODWORD(v105) = v62;
            --v66;
          }
          while ( v66 );
          v19 = v65 == 0;
          v6 = v102;
          v106 = v61;
          if ( v19 )
          {
LABEL_197:
            v68 = v105;
          }
          else
          {
            v68 = v62 | 1;
            LOWORD(v105) = v62 | 1;
            v62 = v105;
          }
          if ( v68 > 0x8000u || (v62 & 0x1FFFF) == 98304 )
          {
            if ( *(_DWORD *)((char *)&v105 + 2) == -1 )
            {
              *(_DWORD *)((char *)&v105 + 2) = 0;
              if ( *(_DWORD *)((char *)&v105 + 6) == -1 )
              {
                *(_DWORD *)((char *)&v105 + 6) = 0;
                if ( HIWORD(v106) == -1 )
                {
                  HIWORD(v106) = -32768;
                  ++v63;
                }
                else
                {
                  ++HIWORD(v106);
                }
              }
              else
              {
                ++*(_DWORD *)((char *)&v105 + 6);
              }
              v61 = v106;
            }
            else
            {
              ++*(_DWORD *)((char *)&v105 + 2);
            }
          }
          if ( v63 < 0x7FFFu )
          {
            *(_DWORD *)&v107[6] = v61;
            *(_WORD *)v107 = WORD1(v105);
            v108 = v51 | v63;
            *(_DWORD *)&v107[2] = HIDWORD(v105);
            v20 = *(_DWORD *)&v107[4];
            v21 = *(_DWORD *)v107;
          }
          else
          {
            v20 = 0;
            v21 = 0;
            *(_DWORD *)&v107[8] = v51 != 0 ? -32768 : 2147450880;
          }
          goto LABEL_147;
        }
      }
      *(_DWORD *)&v107[8] = 0;
    }
    v21 = 0;
    v20 = 0;
  }
LABEL_147:
  v69 = v100;
  v6->exp = v97;
  if ( !(v103 & 1) || (v69 = (signed __int16)v97 + v100, v69 > 0) )
  {
    v70 = *(_DWORD *)&v107[8];
    v108 = 0;
    v71 = *(_DWORD *)&v107[8];
    v72 = 8i64;
    if ( v69 > 21 )
      v69 = 21;
    v73 = (v70 >> 16) - 16382;
    do
    {
      v74 = v20 >> 31;
      v20 = (v21 >> 31) | 2 * v20;
      v71 = v74 | 2 * v71;
      v21 *= 2;
      --v72;
    }
    while ( v72 );
    *(_DWORD *)&v107[4] = v20;
    *(_DWORD *)v107 = v21;
    if ( v73 < 0 )
    {
      v75 = (unsigned __int8)-(char)v73;
      if ( v75 > 0 )
      {
        do
        {
          v76 = v71 << 31;
          v77 = v20 << 31;
          --v75;
          v71 >>= 1;
          v20 = v76 | (v20 >> 1);
          v21 = v77 | (v21 >> 1);
        }
        while ( v75 > 0 );
        *(_DWORD *)&v107[4] = v20;
        *(_DWORD *)v107 = v21;
      }
    }
    v78 = v69 + 1;
    v79 = v6->man;
    v80 = v6->man;
    if ( v69 + 1 > 0 )
    {
      while ( 1 )
      {
        v81 = v21;
        v82 = 2 * v21;
        v112 = *(_QWORD *)v107;
        v83 = (v20 >> 31) | 2 * v71;
        v84 = (v81 >> 31) | 2 * v20;
        v85 = (v82 >> 31) | 2 * v84;
        v82 *= 2;
        v86 = *(_DWORD *)v107 + v82;
        v87 = (v84 >> 31) | 2 * v83;
        if ( *(_DWORD *)v107 + v82 < v82 || v86 < *(_DWORD *)v107 )
        {
          v88 = 0;
          if ( v85 + 1 < v85 || v85 + 1 < 1 )
            v88 = 1;
          ++v85;
          if ( v88 )
            ++v87;
        }
        v89 = v85 + *(_DWORD *)&v107[4];
        if ( v85 + *(_DWORD *)&v107[4] < v85 || v89 < *(_DWORD *)&v107[4] )
          ++v87;
        v20 = (v86 >> 31) | 2 * v89;
        v21 = 2 * v86;
        --v78;
        *(_DWORD *)&v107[8] = (v89 >> 31) | 2 * (v71 + v87);
        *(_DWORD *)v107 = 2 * v86;
        *(_DWORD *)&v107[4] = (v86 >> 31) | 2 * v89;
        HIBYTE(v108) = 0;
        *v80++ = (((v89 >> 31) | 2 * (v71 + v87)) >> 24) + 48;
        if ( v78 <= 0 )
          break;
        v71 = *(_DWORD *)&v107[8];
      }
    }
    v90 = v80 - 1;
    v91 = *v90;
    v92 = v90 - 1;
    if ( v91 < 53 )
    {
      while ( v92 >= v79 && *v92 == 48 )
        --v92;
      if ( v92 < v79 )
      {
        v95 = 32;
        v6->exp = 0;
        v6->ManLen = 1;
        if ( v96 == -32768 )
          v95 = 45;
        v6->sign = v95;
        *v79 = 48;
        goto LABEL_10;
      }
    }
    else
    {
      while ( v92 >= v79 && *v92 == 57 )
        *v92-- = 48;
      if ( v92 < v79 )
      {
        ++v92;
        ++v6->exp;
      }
      ++*v92;
    }
    v93 = (_BYTE)v92 - (_BYTE)v6 - 3;
    v6->ManLen = v93;
    v6->man[v93] = 0;
    return v8;
  }
  v11 = 32;
  if ( v96 == -32768 )
    v11 = 45;
LABEL_9:
  v6->exp = 0;
  v6->sign = v11;
  *(_WORD *)&v6->ManLen = 12289;
LABEL_10:
  v6->man[1] = 0;
  return v8;
}

