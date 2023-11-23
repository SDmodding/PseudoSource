// File Line: 66
// RVA: 0x12DB480
__int64 __fastcall _I10_OUTPUT(_LDOUBLE *ld, int ndigits, char output_flags, _FloatOutStruct *fos)
{
  __int16 v4; // di
  int v5; // r10d
  unsigned int v7; // r9d
  unsigned int v8; // r11d
  __int16 v9; // cx
  unsigned __int16 v10; // di
  char v11; // al
  int v12; // r8d
  int v13; // edx
  int v14; // r12d
  _LDBL12 *v15; // r9
  int v16; // edx
  int v17; // ecx
  int v18; // r10d
  bool v19; // zf
  unsigned int v20; // r8d
  unsigned int v21; // edx
  char v22; // al
  int v23; // eax
  __int64 *ld12; // rsi
  unsigned __int64 v25; // rcx
  int v26; // eax
  __int16 v27; // bx
  unsigned __int16 v28; // cx
  __int16 v29; // bx
  unsigned __int16 v30; // r9
  int v31; // r14d
  __int64 *v32; // rdx
  int i; // edi
  int v34; // r13d
  unsigned __int16 *v35; // r12
  unsigned __int16 *v36; // r15
  int v37; // r10d
  unsigned int v38; // ecx
  unsigned int v39; // r8d
  unsigned int v40; // r10d
  unsigned int v41; // r8d
  __int16 v42; // r9
  int v43; // edx
  unsigned __int64 v44; // kr00_8
  __int64 v45; // rdx
  int v46; // r9d
  unsigned int v47; // eax
  unsigned __int16 v48; // ax
  bool v49; // cf
  __int16 v50; // r13
  unsigned __int16 v51; // r9
  int v52; // edi
  __int64 *v53; // rcx
  int v54; // r15d
  int *v55; // rsi
  unsigned __int16 *v56; // r14
  int v57; // r8d
  unsigned int v58; // edx
  unsigned int v59; // r10d
  unsigned int v60; // r8d
  unsigned int v61; // r10d
  __int16 v62; // r9
  int v63; // edx
  unsigned __int64 v64; // kr08_8
  int v65; // ebx
  __int64 v66; // rdx
  unsigned int v67; // eax
  unsigned __int16 v68; // ax
  int v69; // r14d
  unsigned int v70; // r9d
  unsigned int v71; // esi
  __int64 v72; // r10
  int v73; // r9d
  unsigned int v74; // ecx
  int v75; // r9d
  int v76; // r10d
  unsigned int v77; // eax
  unsigned int v78; // ecx
  int v79; // r12d
  char *man; // rdi
  char *v81; // r10
  unsigned int v82; // eax
  unsigned int v83; // edx
  int v84; // r9d
  unsigned int v85; // ecx
  unsigned int v86; // r8d
  unsigned int v87; // r13d
  int v88; // r9d
  int v89; // ecx
  unsigned int v90; // r14d
  char v91; // al
  char *v92; // r10
  char v93; // al
  char *v94; // r10
  char v95; // r10
  char v97; // al
  __int16 v98; // [rsp+32h] [rbp-67h]
  __int16 v99; // [rsp+38h] [rbp-61h]
  _LDBL12 *v100; // [rsp+40h] [rbp-59h]
  int v101; // [rsp+48h] [rbp-51h]
  int v103; // [rsp+50h] [rbp-49h]
  _FloatOutStruct *v104; // [rsp+58h] [rbp-41h]
  __int64 *v106; // [rsp+68h] [rbp-31h]
  __int64 v107[2]; // [rsp+70h] [rbp-29h] BYREF
  _BYTE v108[12]; // [rsp+80h] [rbp-19h] BYREF
  int v109; // [rsp+90h] [rbp-9h]
  int v110; // [rsp+94h] [rbp-5h]
  int v111; // [rsp+98h] [rbp-1h] BYREF
  unsigned __int64 v112; // [rsp+A0h] [rbp+7h] BYREF
  int v113; // [rsp+A8h] [rbp+Fh]

  v4 = *(_WORD *)&ld->ld[8];
  v5 = *(_DWORD *)ld->ld;
  v7 = *(_DWORD *)&ld->ld[4];
  v8 = 1;
  v9 = v4 & 0x8000;
  v10 = v4 & 0x7FFF;
  v104 = fos;
  v109 = -858993460;
  v110 = -858993460;
  v111 = 1073466572;
  v98 = v9;
  v11 = 32;
  if ( v9 )
    fos->sign = 45;
  else
    fos->sign = 32;
  if ( v10 )
  {
    if ( v10 != 0x7FFF )
      goto LABEL_29;
    fos->exp = 1;
    if ( (v7 != 0x80000000 || v5) && (v7 & 0x40000000) == 0 )
    {
      if ( (unsigned int)strcpy_s(fos->man, 0x16ui64, "1#SNAN") )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
      }
LABEL_27:
      fos->ManLen = 6;
      return 0;
    }
    if ( v9 && v7 == -1073741824 )
    {
      if ( !v5 )
      {
        if ( (unsigned int)strcpy_s(fos->man, 0x16ui64, "1#IND") )
        {
          invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
          __debugbreak();
        }
LABEL_25:
        fos->ManLen = 5;
        return 0;
      }
    }
    else if ( v7 == 0x80000000 && !v5 )
    {
      if ( (unsigned int)strcpy_s(fos->man, 0x16ui64, "1#INF") )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
      }
      goto LABEL_25;
    }
    if ( (unsigned int)strcpy_s(fos->man, 0x16ui64, "1#QNAN") )
    {
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
    }
    goto LABEL_27;
  }
  if ( !v7 && !v5 )
  {
    if ( v9 == (__int16)0x8000 )
      v11 = 45;
    goto LABEL_9;
  }
LABEL_29:
  *(_DWORD *)&v108[6] = v7;
  *(_DWORD *)&v108[2] = v5;
  v12 = 19728 * v10;
  v13 = HIBYTE(v10) + 2 * HIBYTE(v7);
  v14 = 5;
  v15 = &pow10pos[-8];
  *(_WORD *)&v108[10] = v10;
  *(_WORD *)v108 = 0;
  v16 = 77 * v13;
  v103 = 5;
  v17 = (v16 + v12 - 323162868) >> 16;
  v99 = v17;
  v18 = -(__int16)((unsigned int)(v16 + v12 - 323162868) >> 16);
  if ( (unsigned int)(v16 + v12 - 323162868) >> 16 )
  {
    v19 = (__int16)((unsigned int)(v16 + v12 - 323162868) >> 16) == 0;
    if ( (__int16)((unsigned int)(v16 + v12 - 323162868) >> 16) > 0 )
    {
      v18 = (__int16)((unsigned int)(v16 + v12 - 323162868) >> 16);
      v15 = &pow10neg[-8];
      v19 = v18 == 0;
    }
    if ( !v19 )
    {
      v20 = *(_DWORD *)&v108[4];
      v21 = *(_DWORD *)v108;
      while ( 1 )
      {
        v22 = v18;
        v15 += 7;
        v18 >>= 3;
        v101 = v18;
        v100 = v15;
        v23 = v22 & 7;
        if ( v23 )
          break;
LABEL_89:
        if ( !v18 )
        {
          fos = v104;
          LOWORD(v17) = v99;
          goto LABEL_92;
        }
      }
      ld12 = (__int64 *)v15[v23].ld12;
      v106 = ld12;
      if ( *(_WORD *)ld12 >= 0x8000u )
      {
        v25 = *ld12;
        v26 = *((_DWORD *)ld12 + 2);
        ld12 = (__int64 *)&v112;
        v112 = v25;
        v113 = v26;
        v106 = (__int64 *)&v112;
        *(_DWORD *)((char *)&v112 + 2) = (v25 >> 16) - 1;
      }
      v27 = *((_WORD *)ld12 + 5);
      v28 = v27 & 0x7FFF;
      memset(v107, 0, 12);
      v29 = (*(_WORD *)&v108[10] ^ v27) & 0x8000;
      v30 = (*(_WORD *)&v108[10] & 0x7FFF) + v28;
      if ( (*(_WORD *)&v108[10] & 0x7FFF) == 0x7FFF || v28 >= 0x7FFFu || v30 > 0xBFFDu )
      {
        v49 = v29 != 0;
      }
      else
      {
        if ( v30 <= 0x3FBFu )
        {
LABEL_41:
          *(_QWORD *)&v108[4] = 0i64;
LABEL_87:
          v21 = 0;
          v20 = 0;
          *(_DWORD *)v108 = 0;
          goto LABEL_88;
        }
        if ( (*(_WORD *)&v108[10] & 0x7FFF) == 0 )
        {
          ++v30;
          if ( (*(_DWORD *)&v108[8] & 0x7FFFFFFF) == 0 && !v20 && !v21 )
          {
            *(_WORD *)&v108[10] = 0;
LABEL_88:
            v15 = v100;
            goto LABEL_89;
          }
        }
        if ( !v28 )
        {
          ++v30;
          if ( (ld12[1] & 0x7FFFFFFF) == 0 && !*((_DWORD *)ld12 + 1) && !*(_DWORD *)ld12 )
            goto LABEL_41;
        }
        v31 = 0;
        v32 = v107;
        for ( i = 5; i > 0; --i )
        {
          v34 = i;
          v35 = (unsigned __int16 *)(ld12 + 1);
          v36 = (unsigned __int16 *)&v108[2 * v31];
          do
          {
            v37 = 0;
            v38 = *v35 * *v36;
            v39 = *(_DWORD *)v32 + v38;
            if ( v39 < *(_DWORD *)v32 || v39 < v38 )
              v37 = 1;
            *(_DWORD *)v32 = v39;
            if ( v37 )
              ++*((_WORD *)v32 + 2);
            --v34;
            ++v36;
            --v35;
          }
          while ( v34 > 0 );
          ld12 = v106;
          v32 = (__int64 *)((char *)v32 + 2);
          ++v31;
        }
        v40 = v107[1];
        v41 = v107[0];
        v42 = v30 - 16382;
        if ( v42 > 0 )
        {
          do
          {
            if ( (v40 & 0x80000000) != 0 )
              break;
            v44 = 2i64 * v41;
            v43 = HIDWORD(v44);
            v41 = v44;
            --v42;
            v40 = (HIDWORD(v107[0]) >> 31) | (2 * v40);
            LODWORD(v107[0]) = v41;
            HIDWORD(v107[0]) = v43 | (2 * HIDWORD(v107[0]));
            LODWORD(v107[1]) = v40;
          }
          while ( v42 > 0 );
          if ( v42 > 0 )
            goto LABEL_71;
        }
        if ( --v42 >= 0 )
          goto LABEL_71;
        v45 = (unsigned __int16)-v42;
        v46 = 0;
        do
        {
          if ( (v107[0] & 1) != 0 )
            ++v46;
          v47 = v40 << 31;
          v40 >>= 1;
          v41 = (HIDWORD(v107[0]) << 31) | (v41 >> 1);
          HIDWORD(v107[0]) = v47 | (HIDWORD(v107[0]) >> 1);
          LODWORD(v107[0]) = v41;
          --v45;
        }
        while ( v45 );
        v19 = v46 == 0;
        v42 = 0;
        LODWORD(v107[1]) = v40;
        if ( v19 )
        {
LABEL_71:
          v48 = v107[0];
        }
        else
        {
          v48 = v41 | 1;
          LOWORD(v107[0]) = v41 | 1;
          v41 = v107[0];
        }
        if ( v48 > 0x8000u || (v41 & 0x1FFFF) == 98304 )
        {
          if ( *(_DWORD *)((char *)v107 + 2) == -1 )
          {
            *(_DWORD *)((char *)v107 + 2) = 0;
            if ( *(_DWORD *)((char *)v107 + 6) == -1 )
            {
              *(_DWORD *)((char *)v107 + 6) = 0;
              if ( WORD1(v107[1]) == 0xFFFF )
              {
                WORD1(v107[1]) = 0x8000;
                ++v42;
              }
              else
              {
                ++WORD1(v107[1]);
              }
            }
            else
            {
              ++*(_DWORD *)((char *)v107 + 6);
            }
            v40 = v107[1];
          }
          else
          {
            ++*(_DWORD *)((char *)v107 + 2);
          }
        }
        v14 = 5;
        if ( (unsigned __int16)v42 < 0x7FFFu )
        {
          *(_DWORD *)&v108[6] = v40;
          v18 = v101;
          *(_WORD *)v108 = WORD1(v107[0]);
          *(_DWORD *)&v108[2] = HIDWORD(v107[0]);
          v20 = *(_DWORD *)&v108[4];
          v21 = *(_DWORD *)v108;
          *(_WORD *)&v108[10] = v29 | v42;
          goto LABEL_88;
        }
        v18 = v101;
        v49 = v29 != 0;
      }
      *(_DWORD *)&v108[4] = 0;
      *(_DWORD *)&v108[8] = v49 ? -32768 : 2147450880;
      goto LABEL_87;
    }
  }
  v20 = *(_DWORD *)&v108[4];
  v21 = *(_DWORD *)v108;
LABEL_92:
  if ( *(_WORD *)&v108[10] >= 0x3FFFu )
  {
    v99 = v17 + 1;
    memset(v107, 0, 12);
    v50 = (*(_WORD *)&v108[10] ^ HIWORD(v111)) & 0x8000;
    v51 = (*(_WORD *)&v108[10] & 0x7FFF) + (HIWORD(v111) & 0x7FFF);
    if ( (*(_WORD *)&v108[10] & 0x7FFF) == 0x7FFF || (HIWORD(v111) & 0x7FFF) == 0x7FFF || v51 > 0xBFFDu )
    {
      *(_DWORD *)&v108[8] = ((*(_WORD *)&v108[10] ^ HIWORD(v111)) & 0x8000u) != 0 ? -32768 : 2147450880;
    }
    else
    {
      if ( v51 > 0x3FBFu )
      {
        if ( (*(_WORD *)&v108[10] & 0x7FFF) == 0 )
        {
          ++v51;
          if ( (*(_DWORD *)&v108[8] & 0x7FFFFFFF) == 0 && !v20 && !v21 )
          {
            *(_WORD *)&v108[10] = 0;
            goto LABEL_143;
          }
        }
        if ( (v111 & 0x7FFF0000) != 0 || (++v51, (v111 & 0x7FFFFFFF) != 0) || v110 || v109 )
        {
          v52 = 0;
          v53 = v107;
          do
          {
            v54 = v14;
            v55 = &v111;
            v56 = (unsigned __int16 *)&v108[2 * v52];
            do
            {
              v57 = 0;
              v58 = *v56 * *(unsigned __int16 *)v55;
              v59 = *(_DWORD *)v53 + v58;
              if ( v59 < *(_DWORD *)v53 || v59 < v58 )
                v57 = 1;
              *(_DWORD *)v53 = v59;
              if ( v57 )
                ++*((_WORD *)v53 + 2);
              --v54;
              ++v56;
              v55 = (int *)((char *)v55 - 2);
            }
            while ( v54 > 0 );
            v14 = v103 - 1;
            v53 = (__int64 *)((char *)v53 + 2);
            ++v52;
            v103 = v14;
          }
          while ( v14 > 0 );
          fos = v104;
          v60 = v107[1];
          v61 = v107[0];
          v62 = v51 - 16382;
          if ( v62 > 0 )
          {
            do
            {
              if ( (v60 & 0x80000000) != 0 )
                break;
              v64 = 2i64 * v61;
              v63 = HIDWORD(v64);
              v61 = v64;
              --v62;
              v60 = (HIDWORD(v107[0]) >> 31) | (2 * v60);
              LODWORD(v107[0]) = v61;
              HIDWORD(v107[0]) = v63 | (2 * HIDWORD(v107[0]));
              LODWORD(v107[1]) = v60;
            }
            while ( v62 > 0 );
            if ( v62 > 0 )
              goto LABEL_127;
          }
          if ( --v62 >= 0 )
            goto LABEL_127;
          v65 = 0;
          v66 = (unsigned __int16)-v62;
          v62 = 0;
          do
          {
            if ( (v107[0] & 1) != 0 )
              ++v65;
            v67 = v60 << 31;
            v60 >>= 1;
            v61 = (HIDWORD(v107[0]) << 31) | (v61 >> 1);
            HIDWORD(v107[0]) = v67 | (HIDWORD(v107[0]) >> 1);
            LODWORD(v107[0]) = v61;
            --v66;
          }
          while ( v66 );
          v19 = v65 == 0;
          fos = v104;
          LODWORD(v107[1]) = v60;
          if ( v19 )
          {
LABEL_127:
            v68 = v107[0];
          }
          else
          {
            v68 = v61 | 1;
            LOWORD(v107[0]) = v61 | 1;
            v61 = v107[0];
          }
          if ( v68 > 0x8000u || (v61 & 0x1FFFF) == 98304 )
          {
            if ( *(_DWORD *)((char *)v107 + 2) == -1 )
            {
              *(_DWORD *)((char *)v107 + 2) = 0;
              if ( *(_DWORD *)((char *)v107 + 6) == -1 )
              {
                *(_DWORD *)((char *)v107 + 6) = 0;
                if ( WORD1(v107[1]) == 0xFFFF )
                {
                  WORD1(v107[1]) = 0x8000;
                  ++v62;
                }
                else
                {
                  ++WORD1(v107[1]);
                }
              }
              else
              {
                ++*(_DWORD *)((char *)v107 + 6);
              }
              v60 = v107[1];
            }
            else
            {
              ++*(_DWORD *)((char *)v107 + 2);
            }
          }
          if ( (unsigned __int16)v62 < 0x7FFFu )
          {
            *(_DWORD *)&v108[6] = v60;
            *(_WORD *)v108 = WORD1(v107[0]);
            *(_WORD *)&v108[10] = v50 | v62;
            *(_DWORD *)&v108[2] = HIDWORD(v107[0]);
            v20 = *(_DWORD *)&v108[4];
            v21 = *(_DWORD *)v108;
          }
          else
          {
            v20 = 0;
            v21 = 0;
            *(_DWORD *)&v108[8] = v50 != 0 ? -32768 : 2147450880;
          }
          goto LABEL_143;
        }
      }
      *(_DWORD *)&v108[8] = 0;
    }
    v21 = 0;
    v20 = 0;
  }
LABEL_143:
  v69 = ndigits;
  fos->exp = v99;
  if ( (output_flags & 1) == 0 || (v69 = v99 + ndigits, v69 > 0) )
  {
    v70 = *(_DWORD *)&v108[8];
    *(_WORD *)&v108[10] = 0;
    v71 = *(unsigned __int16 *)&v108[8];
    v72 = 8i64;
    if ( v69 > 21 )
      v69 = 21;
    v73 = HIWORD(v70) - 16382;
    do
    {
      v74 = v20 >> 31;
      v20 = (v21 >> 31) | (2 * v20);
      v71 = v74 | (2 * v71);
      v21 *= 2;
      --v72;
    }
    while ( v72 );
    *(_DWORD *)&v108[4] = v20;
    *(_DWORD *)v108 = v21;
    if ( v73 < 0 )
    {
      v75 = -v73;
      v76 = (unsigned __int8)v75;
      if ( (_BYTE)v75 )
      {
        do
        {
          v77 = v71 << 31;
          v78 = v20 << 31;
          --v76;
          v71 >>= 1;
          v20 = v77 | (v20 >> 1);
          v21 = v78 | (v21 >> 1);
        }
        while ( v76 > 0 );
        *(_DWORD *)&v108[4] = v20;
        *(_DWORD *)v108 = v21;
      }
    }
    v79 = v69 + 1;
    man = fos->man;
    v81 = fos->man;
    if ( v69 + 1 > 0 )
    {
      while ( 1 )
      {
        v82 = v21;
        v83 = 2 * v21;
        v112 = *(_QWORD *)v108;
        v84 = (v20 >> 31) | (2 * v71);
        v85 = (v82 >> 31) | (2 * v20);
        v86 = (v83 >> 31) | (2 * v85);
        v83 *= 2;
        v87 = *(_DWORD *)v108 + v83;
        v88 = (v85 >> 31) | (2 * v84);
        if ( *(_DWORD *)v108 + v83 < v83 || v87 < *(_DWORD *)v108 )
        {
          v89 = 0;
          if ( v86 + 1 < v86 || v86 == -1 )
            v89 = 1;
          ++v86;
          if ( v89 )
            ++v88;
        }
        v90 = v86 + *(_DWORD *)&v108[4];
        if ( v86 + *(_DWORD *)&v108[4] < v86 || v90 < *(_DWORD *)&v108[4] )
          ++v88;
        v20 = (v87 >> 31) | (2 * v90);
        v21 = 2 * v87;
        --v79;
        *(_DWORD *)&v108[8] = (v90 >> 31) | (2 * (v71 + v88));
        *(_DWORD *)v108 = 2 * v87;
        v91 = v108[11] + 48;
        *(_DWORD *)&v108[4] = v20;
        v108[11] = 0;
        *v81++ = v91;
        if ( v79 <= 0 )
          break;
        v71 = *(_DWORD *)&v108[8];
      }
    }
    v92 = v81 - 1;
    v93 = *v92;
    v94 = v92 - 1;
    if ( v93 < 53 )
    {
      while ( v94 >= man && *v94 == 48 )
        --v94;
      if ( v94 < man )
      {
        v97 = 32;
        fos->exp = 0;
        fos->ManLen = 1;
        if ( v98 == (__int16)0x8000 )
          v97 = 45;
        fos->sign = v97;
        *man = 48;
        goto LABEL_10;
      }
    }
    else
    {
      while ( v94 >= man && *v94 == 57 )
        *v94-- = 48;
      if ( v94 < man )
      {
        ++v94;
        ++fos->exp;
      }
      ++*v94;
    }
    v95 = (_BYTE)v94 - (_BYTE)fos - 3;
    fos->ManLen = v95;
    fos->man[v95] = 0;
    return v8;
  }
  v11 = 32;
  if ( v98 == (__int16)0x8000 )
    v11 = 45;
LABEL_9:
  fos->exp = 0;
  fos->sign = v11;
  *(_WORD *)&fos->ManLen = 12289;
LABEL_10:
  fos->man[1] = 0;
  return v8;
}

