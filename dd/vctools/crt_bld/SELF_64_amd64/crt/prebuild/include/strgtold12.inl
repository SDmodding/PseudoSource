// File Line: 100
// RVA: 0x12C85E0
__int64 __fastcall _strgtold12_l(_LDBL12 *pld12, const char **p_end_ptr, const char *str, int mult12, int scale, int decpt, int implicit_E, localeinfo_struct *_Locale)
{
  unsigned int v8; // ebx
  char *v9; // r10
  unsigned int v10; // er11
  signed int v11; // er15
  signed int v12; // er12
  int v13; // er13
  int v14; // esi
  signed int v15; // ecx
  __int64 result; // rax
  const char *v17; // rdi
  signed __int64 v18; // rdx
  char v19; // dl
  __int16 v20; // dx
  signed __int16 v21; // ax
  unsigned int v22; // edi
  int v23; // ecx
  int v24; // er13
  _LDBL12 *v25; // r14
  char v26; // al
  int v27; // eax
  __int64 *v28; // rdx
  unsigned __int64 v29; // rcx
  int v30; // eax
  __int16 v31; // ax
  __int16 v32; // r12
  unsigned __int16 v33; // ax
  __int16 v34; // r12
  unsigned __int16 v35; // r8
  int v36; // er15
  __int64 *v37; // rcx
  signed int v38; // er10
  unsigned __int16 *v39; // r14
  unsigned __int16 *v40; // rdi
  signed int v41; // er11
  unsigned int v42; // er9
  unsigned int v43; // esi
  unsigned int v44; // er10
  unsigned int v45; // er9
  unsigned __int16 v46; // r8
  int v47; // edx
  int v48; // edi
  __int64 v49; // rdx
  unsigned int v50; // eax
  unsigned __int16 v51; // ax
  signed int v52; // [rsp+20h] [rbp-79h]
  signed int v53; // [rsp+20h] [rbp-79h]
  signed int v54; // [rsp+24h] [rbp-75h]
  signed __int16 v55; // [rsp+28h] [rbp-71h]
  int v56; // [rsp+2Ch] [rbp-6Dh]
  const char **v57; // [rsp+30h] [rbp-69h]
  __int64 *v58; // [rsp+30h] [rbp-69h]
  _LDBL12 *v59; // [rsp+38h] [rbp-61h]
  _LDBL12 *v60; // [rsp+40h] [rbp-59h]
  __int64 v61; // [rsp+48h] [rbp-51h]
  unsigned int v62; // [rsp+50h] [rbp-49h]
  _LDBL12 ld12; // [rsp+58h] [rbp-41h]
  unsigned __int64 v64; // [rsp+68h] [rbp-31h]
  int v65; // [rsp+70h] [rbp-29h]
  char manptr; // [rsp+78h] [rbp-21h]
  char v67; // [rsp+8Fh] [rbp-Ah]

  v8 = 0;
  v56 = mult12;
  v60 = pld12;
  v57 = p_end_ptr;
  v9 = &manptr;
  v55 = 0;
  v10 = 0;
  v54 = 1;
  v11 = 0;
  v52 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  if ( !_Locale )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0i64;
  }
  v17 = str;
  while ( *str <= 0x20u )
  {
    v18 = 4294977024i64;
    if ( !_bittest64(&v18, *str) )
      break;
    ++str;
  }
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v19 = *str++;
          if ( v15 > 5 )
            break;
          if ( v15 == 5 )
          {
            v52 = 1;
            if ( (unsigned __int8)(v19 - 48) > 9u )
            {
              str = v17;
              goto LABEL_102;
            }
            v15 = 4;
LABEL_41:
            --str;
          }
          else if ( v15 )
          {
            switch ( v15 )
            {
              case 1:
                v11 = 1;
                if ( (unsigned __int8)(v19 - 49) <= 8u )
                {
                  v15 = 3;
                  goto LABEL_41;
                }
                if ( v19 == *_Locale->locinfo->lconv->decimal_point )
                  goto LABEL_38;
                if ( (v19 - 43) & 0xFD )
                {
                  if ( v19 != 48 )
                    goto LABEL_25;
                  goto LABEL_46;
                }
LABEL_29:
                --str;
                v15 = 11;
                break;
              case 2:
                if ( (unsigned __int8)(v19 - 49) <= 8u )
                  goto LABEL_40;
                if ( v19 == *_Locale->locinfo->lconv->decimal_point )
                  goto LABEL_43;
                if ( v19 != 48 )
                  goto LABEL_101;
LABEL_46:
                v15 = 1;
                break;
              case 3:
                v11 = 1;
                while ( v19 >= 48 && v19 <= 57 )
                {
                  if ( v10 >= 0x19 )
                  {
                    ++v14;
                  }
                  else
                  {
                    ++v10;
                    *v9++ = v19 - 48;
                  }
                  v19 = *str++;
                }
                if ( v19 != *_Locale->locinfo->lconv->decimal_point )
                  goto LABEL_24;
LABEL_38:
                v15 = 4;
                break;
              case 4:
                v11 = 1;
                v52 = 1;
                if ( !v10 )
                {
                  while ( v19 == 48 )
                  {
                    v19 = *str;
                    --v14;
                    ++str;
                  }
                }
                while ( v19 >= 48 && v19 <= 57 )
                {
                  if ( v10 < 0x19 )
                  {
                    ++v10;
                    *v9++ = v19 - 48;
                    --v14;
                  }
                  v19 = *str++;
                }
LABEL_24:
                if ( !((v19 - 43) & 0xFD) )
                  goto LABEL_29;
LABEL_25:
                if ( v19 <= 67 || v19 > 69 && (unsigned __int8)(v19 - 100) > 1u )
                  goto LABEL_58;
                v15 = 6;
                break;
              default:
                goto LABEL_87;
            }
          }
          else
          {
            if ( (unsigned __int8)(v19 - 49) <= 8u )
            {
LABEL_40:
              v15 = 3;
              goto LABEL_41;
            }
            if ( v19 == *_Locale->locinfo->lconv->decimal_point )
            {
LABEL_43:
              v15 = 5;
            }
            else
            {
              switch ( v19 )
              {
                case 43:
                  v15 = 2;
                  v55 = 0;
                  break;
                case 45:
                  v15 = 2;
                  v55 = -32768;
                  break;
                case 48:
                  goto LABEL_46;
                default:
                  goto LABEL_58;
              }
            }
          }
        }
        if ( v15 == 6 )
          break;
        switch ( v15 )
        {
          case 7:
            if ( (unsigned __int8)(v19 - 49) <= 8u )
              goto LABEL_79;
            goto LABEL_80;
          case 8:
            v12 = 1;
            while ( v19 == 48 )
              v19 = *str++;
            if ( (unsigned __int8)(v19 - 49) > 8u )
              goto LABEL_58;
            v15 = 9;
            goto LABEL_41;
          case 9:
            v12 = 1;
            while ( v19 >= 48 && v19 <= 57 )
            {
              v13 = v19 + 2 * (5 * v13 - 24);
              if ( v13 > 5200 )
              {
                v13 = 5201;
                break;
              }
              v19 = *str++;
            }
            while ( v19 >= 48 && v19 <= 57 )
              v19 = *str++;
LABEL_58:
            --str;
            goto LABEL_102;
          case 11:
            if ( !implicit_E )
              goto LABEL_58;
            v17 = str - 1;
            if ( v19 != 43 )
            {
              if ( v19 != 45 )
                goto LABEL_101;
              goto LABEL_71;
            }
            v15 = 7;
            break;
          default:
LABEL_87:
            if ( v15 == 10 )
              goto LABEL_102;
            break;
        }
      }
      v17 = str - 2;
      if ( (unsigned __int8)(v19 - 49) <= 8u )
      {
LABEL_79:
        v15 = 9;
        goto LABEL_41;
      }
      if ( v19 == 43 )
      {
        v15 = 7;
        goto LABEL_87;
      }
      if ( v19 != 45 )
        break;
LABEL_71:
      v54 = -1;
      v15 = 7;
    }
LABEL_80:
    if ( v19 != 48 )
      break;
    v15 = 8;
  }
LABEL_101:
  str = v17;
LABEL_102:
  *v57 = str;
  if ( v11 )
  {
    if ( v10 > 0x18 )
    {
      if ( v67 >= 5 )
        ++v67;
      --v9;
      v10 = 24;
      ++v14;
    }
    if ( !v10 )
    {
      v20 = 0;
      v21 = 0;
      v22 = 0;
      v23 = 0;
      goto LABEL_183;
    }
    while ( !*--v9 )
    {
      --v10;
      ++v14;
    }
    _mtold12(&manptr, v10, &ld12);
    if ( v54 < 0 )
      v13 = -v13;
    v24 = v14 + v13;
    if ( !v12 )
      v24 += scale;
    if ( !v52 )
      v24 -= decpt;
    if ( v24 > 5200 )
    {
      v23 = 0;
      v20 = 0;
      v21 = 0x7FFF;
      v8 = 2;
      v22 = 2147483648;
    }
    else if ( v24 < -5200 )
    {
      v20 = 0;
      v21 = 0;
      v22 = 0;
      v23 = 0;
      v8 = 1;
    }
    else
    {
      v25 = &pow10pos[-8];
      if ( v24 )
      {
        if ( v24 < 0 )
        {
          v24 = -v24;
          v25 = &pow10neg[-8];
        }
        if ( !v56 )
          *(_WORD *)ld12.ld12 = 0;
        while ( v24 )
        {
          v26 = v24;
          v25 += 7;
          v24 >>= 3;
          v59 = v25;
          v27 = v26 & 7;
          if ( v27 )
          {
            v28 = (__int64 *)v25[v27].ld12;
            v58 = v28;
            if ( *(_WORD *)v28 >= 0x8000u )
            {
              v29 = *v28;
              v30 = *((_DWORD *)v28 + 2);
              v28 = (__int64 *)&v64;
              v64 = v29;
              v65 = v30;
              v58 = (__int64 *)&v64;
              *(_DWORD *)((char *)&v64 + 2) = (v29 >> 16) - 1;
            }
            v31 = *((_WORD *)v28 + 5);
            v61 = 0i64;
            v32 = v31;
            v33 = v31 & 0x7FFF;
            v62 = 0;
            v34 = (*(_WORD *)&ld12.ld12[10] ^ v32) & 0x8000;
            v35 = (*(_WORD *)&ld12.ld12[10] & 0x7FFF) + v33;
            if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFFu) >= 0x7FFF || v33 >= 0x7FFFu || v35 > 0xBFFDu )
            {
LABEL_177:
              *(_QWORD *)ld12.ld12 = 0i64;
              *(_DWORD *)&ld12.ld12[8] = v34 != 0 ? -32768 : 2147450880;
              continue;
            }
            if ( v35 <= 0x3FBFu )
              goto LABEL_186;
            if ( !(*(_WORD *)&ld12.ld12[10] & 0x7FFF) )
            {
              ++v35;
              if ( !(*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) && !*(_DWORD *)&ld12.ld12[4] && !*(_DWORD *)ld12.ld12 )
              {
                *(_WORD *)&ld12.ld12[10] = 0;
                continue;
              }
            }
            if ( v33 || (++v35, v28[1] & 0x7FFFFFFF) || *((_DWORD *)v28 + 1) || *(_DWORD *)v28 )
            {
              v36 = 0;
              v37 = &v61;
              v38 = 5;
              do
              {
                v53 = v38;
                if ( v38 > 0 )
                {
                  v39 = (unsigned __int16 *)(v28 + 1);
                  v40 = (unsigned __int16 *)((char *)&ld12 + 2 * v36);
                  do
                  {
                    v41 = 0;
                    v42 = *v39 * *v40;
                    v43 = *(_DWORD *)v37 + v42;
                    if ( v43 < *(_DWORD *)v37 || v43 < v42 )
                      v41 = 1;
                    *(_DWORD *)v37 = v43;
                    if ( v41 )
                      ++*((_WORD *)v37 + 2);
                    ++v40;
                    --v39;
                    --v53;
                  }
                  while ( v53 > 0 );
                  v28 = v58;
                }
                --v38;
                v37 = (__int64 *)((char *)v37 + 2);
                ++v36;
              }
              while ( v38 > 0 );
              v44 = v62;
              v45 = v61;
              v46 = v35 - 16382;
              if ( (signed __int16)v46 > 0 )
              {
                do
                {
                  if ( v44 & 0x80000000 )
                    break;
                  v47 = (unsigned __int64)v45 >> 31;
                  v45 *= 2;
                  --v46;
                  v44 = (HIDWORD(v61) >> 31) | 2 * v44;
                  LODWORD(v61) = v45;
                  HIDWORD(v61) = v47 | 2 * HIDWORD(v61);
                  v62 = v44;
                }
                while ( (signed __int16)v46 > 0 );
                if ( (signed __int16)v46 > 0 )
                  goto LABEL_187;
              }
              if ( (--v46 & 0x8000u) == 0 )
                goto LABEL_187;
              v48 = 0;
              v49 = (unsigned __int16)-v46;
              v46 = 0;
              do
              {
                if ( v61 & 1 )
                  ++v48;
                v50 = v44 << 31;
                v44 >>= 1;
                v45 = (HIDWORD(v61) << 31) | (v45 >> 1);
                HIDWORD(v61) = v50 | (HIDWORD(v61) >> 1);
                LODWORD(v61) = v45;
                --v49;
              }
              while ( v49 );
              v62 = v44;
              if ( v48 )
              {
                v51 = v45 | 1;
                LOWORD(v61) = v45 | 1;
                v45 = v61;
              }
              else
              {
LABEL_187:
                v51 = v61;
              }
              v25 = v59;
              if ( v51 > 0x8000u || (v45 & 0x1FFFF) == 98304 )
              {
                if ( *(_DWORD *)((char *)&v61 + 2) == -1 )
                {
                  *(_DWORD *)((char *)&v61 + 2) = 0;
                  if ( *(_DWORD *)((char *)&v61 + 6) == -1 )
                  {
                    *(_DWORD *)((char *)&v61 + 6) = 0;
                    if ( HIWORD(v62) == -1 )
                    {
                      HIWORD(v62) = -32768;
                      ++v46;
                    }
                    else
                    {
                      ++HIWORD(v62);
                    }
                  }
                  else
                  {
                    ++*(_DWORD *)((char *)&v61 + 6);
                  }
                  v44 = v62;
                }
                else
                {
                  ++*(_DWORD *)((char *)&v61 + 2);
                }
              }
              if ( v46 >= 0x7FFFu )
                goto LABEL_177;
              *(_DWORD *)&ld12.ld12[6] = v44;
              *(_WORD *)ld12.ld12 = WORD1(v61);
              *(_WORD *)&ld12.ld12[10] = v34 | v46;
              *(_DWORD *)&ld12.ld12[2] = HIDWORD(v61);
            }
            else
            {
LABEL_186:
              *(_QWORD *)&ld12.ld12[4] = 0i64;
              *(_DWORD *)ld12.ld12 = 0;
            }
          }
        }
      }
      v20 = *(_WORD *)ld12.ld12;
      v23 = *(_DWORD *)&ld12.ld12[2];
      v22 = *(_DWORD *)&ld12.ld12[6];
      v21 = *(_WORD *)&ld12.ld12[10];
    }
  }
  else
  {
    v20 = 0;
    v21 = 0;
    v22 = 0;
    v23 = 0;
    v8 = 4;
  }
LABEL_183:
  *(_WORD *)&v60->ld12[10] = v55 | v21;
  result = v8;
  *(_WORD *)v60->ld12 = v20;
  *(_DWORD *)&v60->ld12[2] = v23;
  *(_DWORD *)&v60->ld12[6] = v22;
  return result;
}

