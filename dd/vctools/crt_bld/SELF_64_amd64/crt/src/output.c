// File Line: 974
// RVA: 0x12D64AC
signed __int64 __fastcall woutput_l(_iobuf *stream, const wchar_t *format, localeinfo_struct *plocinfo, char *argptr)
{
  _iobuf *v4; // rbx
  char *v5; // r12
  int v6; // er14
  int v7; // edi
  bool v8; // zf
  const wchar_t *v10; // r8
  wchar_t v11; // r15
  int v12; // esi
  int v13; // er13
  int v14; // edx
  wchar_t *v15; // rbx
  int v16; // ecx
  signed __int16 *v17; // rax
  int v18; // eax
  wchar_t *v19; // rsi
  int v20; // esi
  __int16 v21; // ax
  signed int v22; // esi
  signed int v23; // er13
  signed int v24; // eax
  wchar_t *i; // rax
  signed int v26; // er9
  signed int v27; // edx
  _WORD *v28; // rdi
  unsigned __int64 v29; // r8
  char v30; // si
  char *v31; // rbx
  int v32; // ecx
  unsigned __int64 v33; // rdx
  char v34; // al
  int v35; // eax
  int v36; // edi
  void *v37; // rax
  __int64 v38; // rax
  PVOID v39; // rax
  void (__fastcall *v40)(wchar_t *, _LocaleUpdate *); // rax
  void (__fastcall *v41)(wchar_t *, _LocaleUpdate *); // rax
  int v42; // eax
  _iobuf *v43; // rdi
  int v44; // er15
  const char *v45; // rdi
  int v46; // esi
  int v47; // eax
  __int64 v48; // r12
  unsigned __int64 v49; // rax
  signed __int64 v50; // rcx
  int v51; // eax
  int v52; // eax
  int *perrno; // [rsp+20h] [rbp-E0h]
  __int64 v54; // [rsp+28h] [rbp-D8h]
  int pnumwritten; // [rsp+40h] [rbp-C0h]
  int v56; // [rsp+44h] [rbp-BCh]
  int v57; // [rsp+48h] [rbp-B8h]
  int v58; // [rsp+4Ch] [rbp-B4h]
  char *v59; // [rsp+50h] [rbp-B0h]
  int v60; // [rsp+58h] [rbp-A8h]
  wchar_t string; // [rsp+5Ch] [rbp-A4h]
  __int16 v62; // [rsp+5Eh] [rbp-A2h]
  wchar_t v63; // [rsp+60h] [rbp-A0h]
  char s; // [rsp+64h] [rbp-9Ch]
  char v65; // [rsp+65h] [rbp-9Bh]
  int v66; // [rsp+68h] [rbp-98h]
  int v67; // [rsp+6Ch] [rbp-94h]
  int v68; // [rsp+70h] [rbp-90h]
  _iobuf *f; // [rsp+78h] [rbp-88h]
  const wchar_t *v70; // [rsp+80h] [rbp-80h]
  int v71; // [rsp+88h] [rbp-78h]
  _LocaleUpdate v72; // [rsp+90h] [rbp-70h]
  void *pBlock; // [rsp+B0h] [rbp-50h]
  int *v74; // [rsp+B8h] [rbp-48h]
  wchar_t *v75; // [rsp+C0h] [rbp-40h]
  wchar_t pwc; // [rsp+D0h] [rbp-30h]
  __int64 v77; // [rsp+100h] [rbp+0h]
  char v78; // [rsp+2CFh] [rbp+1CFh]

  v4 = stream;
  f = stream;
  v70 = format;
  v5 = argptr;
  v59 = argptr;
  v68 = 0;
  v6 = 0;
  v60 = 0;
  v7 = 0;
  v56 = 0;
  v57 = 0;
  v67 = 0;
  v58 = 0;
  _LocaleUpdate::_LocaleUpdate(&v72, plocinfo);
  v74 = errno();
  if ( (signed int)ioinit() < 0 )
  {
    v8 = v72.updated == 0;
LABEL_3:
    if ( !v8 )
      v72.ptd->_ownlocale &= 0xFFFFFFFD;
    return 0xFFFFFFFFi64;
  }
  if ( !v4 || (v10 = v70) == 0i64 )
  {
LABEL_7:
    *errno() = 22;
    invalid_parameter_noinfo();
    v8 = v72.updated == 0;
    goto LABEL_3;
  }
  v11 = *v70;
  v12 = 0;
  pnumwritten = 0;
  v13 = 0;
  v14 = 0;
  pBlock = 0i64;
  if ( v11 )
  {
    v15 = v75;
    do
    {
      ++v10;
      v70 = v10;
      if ( v12 < 0 )
        break;
      if ( (unsigned __int16)(v11 - 32) > 0x58u )
        v16 = 0;
      else
        v16 = _lookuptable[v11 - 32] & 0xF;
      v14 = _lookuptable[8 * v16 + v14] >> 4;
      v66 = v14;
      switch ( v14 )
      {
        case 0:
          goto $NORMAL_STATE_1;
        case 1:
          v7 = -1;
          v71 = 0;
          v67 = 0;
          v60 = 0;
          v57 = 0;
          v6 = 0;
          v56 = -1;
          v58 = 0;
          break;
        case 2:
          switch ( v11 )
          {
            case 0x20u:
              v6 |= 2u;
              break;
            case 0x23u:
              v6 |= 0x80u;
              break;
            case 0x2Bu:
              v6 |= 1u;
              break;
            case 0x2Du:
              v6 |= 4u;
              break;
            case 0x30u:
              v6 |= 8u;
              break;
          }
          break;
        case 3:
          if ( v11 != 42 )
          {
            v52 = v11 + 10 * v60 - 48;
            goto LABEL_210;
          }
          v51 = *(_DWORD *)v5;
          v5 += 8;
          v59 = v5;
          v60 = v51;
          if ( v51 < 0 )
          {
            v6 |= 4u;
            v52 = -v51;
LABEL_210:
            v60 = v52;
            break;
          }
          break;
        case 4:
          v7 = 0;
          v56 = 0;
          break;
        case 5:
          if ( v11 != 42 )
          {
            v7 = v11 + 2 * (5 * v7 - 24);
            goto LABEL_204;
          }
          v7 = *(_DWORD *)v5;
          v5 += 8;
          v59 = v5;
          v56 = v7;
          if ( v7 < 0 )
          {
            v7 = -1;
LABEL_204:
            v56 = v7;
            break;
          }
          break;
        case 6:
          if ( v11 != 73 )
          {
            switch ( v11 )
            {
              case 0x68u:
                v6 |= 0x20u;
                break;
              case 0x6Cu:
                if ( *v10 == 108 )
                {
                  ++v10;
                  v6 |= 0x1000u;
                }
                else
                {
                  v6 |= 0x10u;
                }
                break;
              case 0x77u:
                v6 |= 0x800u;
                break;
            }
            break;
          }
          v49 = *v10;
          v6 |= 0x8000u;
          if ( (_WORD)v49 == 54 && v10[1] == 52 )
          {
            v10 += 2;
            v6 |= 0x8000u;
            break;
          }
          if ( (_WORD)v49 == 51 && v10[1] == 50 )
          {
            v10 += 2;
            v6 &= 0xFFFF7FFF;
            break;
          }
          LOWORD(v49) = v49 - 88;
          if ( (unsigned __int16)v49 <= 0x20u )
          {
            v50 = 4840361985i64;
            if ( _bittest64(&v50, v49) )
              break;
          }
          v66 = 0;
$NORMAL_STATE_1:
          v58 = 1;
          write_char_0(v11, f, &pnumwritten);
          v12 = pnumwritten;
          goto LABEL_175;
        case 7:
          if ( (signed int)v11 > 100 )
          {
            if ( (signed int)v11 < 101 )
              goto LABEL_53;
            if ( (signed int)v11 <= 103 )
              goto LABEL_66;
            switch ( v11 )
            {
              case 0x69u:
                goto LABEL_97;
              case 0x6Eu:
                v28 = *(_WORD **)v5;
                v5 += 8;
                v59 = v5;
                if ( !(unsigned int)get_printf_count_output() )
                  goto LABEL_7;
                if ( v6 & 0x20 )
                  *v28 = v12;
                else
                  *(_DWORD *)v28 = v12;
                v67 = 1;
                goto LABEL_172;
              case 0x6Fu:
                v26 = 8;
                if ( (v6 & 0x80u) != 0 )
                  v6 |= 0x200u;
                goto LABEL_99;
              case 0x70u:
                v7 = 16;
                v6 |= 0x8000u;
                goto LABEL_87;
              case 0x73u:
                goto LABEL_42;
            }
            if ( v11 != 117 )
            {
              if ( v11 != 120 )
                goto LABEL_53;
              v24 = 39;
              goto LABEL_88;
            }
          }
          else
          {
            if ( v11 != 100 )
            {
              if ( v11 == 65 )
                goto LABEL_224;
              if ( v11 == 67 )
              {
                if ( !(v6 & 0x830) )
                  v6 |= 0x20u;
                goto LABEL_60;
              }
              if ( !((v11 - 69) & 0xFFFFFFFD) )
              {
LABEL_224:
                v71 = 1;
                v11 += 32;
                goto LABEL_66;
              }
              if ( v11 != 83 )
              {
                if ( v11 != 88 )
                {
                  if ( v11 == 90 )
                  {
                    v17 = *(signed __int16 **)v5;
                    v5 += 8;
                    v59 = v5;
                    if ( v17 && (v15 = (wchar_t *)*((_QWORD *)v17 + 1)) != 0i64 )
                    {
                      if ( _bittest(&v6, 0xBu) )
                      {
                        v18 = *v17;
                        v58 = 1;
                        v13 = v18 / 2;
                      }
                      else
                      {
                        v13 = *v17;
                        v58 = 0;
                      }
                    }
                    else
                    {
                      v15 = (wchar_t *)_nullstring;
                      v13 = strlen(_nullstring);
                    }
                    goto LABEL_53;
                  }
                  if ( v11 != 97 )
                  {
                    if ( v11 != 99 )
                      goto LABEL_53;
LABEL_60:
                    v21 = *(_WORD *)v5;
                    v5 += 8;
                    v58 = 1;
                    v59 = v5;
                    v63 = v21;
                    if ( v6 & 0x20 )
                    {
                      s = v21;
                      v65 = 0;
                      if ( (signed int)mbtowc_l(&pwc, &s, v72.localeinfo.locinfo->mb_cur_max, &v72.localeinfo) < 0 )
                        v67 = 1;
                    }
                    else
                    {
                      pwc = v21;
                    }
                    v15 = &pwc;
                    v13 = 1;
LABEL_53:
                    if ( v67 )
                      goto LABEL_172;
                    if ( v6 & 0x40 )
                    {
                      if ( _bittest(&v6, 8u) )
                      {
                        string = 45;
                        goto LABEL_57;
                      }
                      if ( v6 & 1 )
                      {
                        string = 43;
LABEL_57:
                        v20 = 1;
                        v57 = 1;
LABEL_155:
                        v43 = f;
                        v44 = v60 - v13 - v20;
                        if ( !(v6 & 0xC) )
                          write_multi_char_0(0x20u, v44, f, &pnumwritten);
                        write_string_0(&string, v20, v43, &pnumwritten, v74);
                        if ( v6 & 8 && !(v6 & 4) )
                          write_multi_char_0(0x30u, v44, v43, &pnumwritten);
                        if ( v58 || v13 <= 0 )
                        {
                          write_string_0(v15, v13, v43, &pnumwritten, v74);
LABEL_168:
                          v12 = pnumwritten;
                        }
                        else
                        {
                          v45 = (const char *)v15;
                          v46 = v13;
                          while ( 1 )
                          {
                            --v46;
                            v47 = mbtowc_l(&v63, v45, v72.localeinfo.locinfo->mb_cur_max, &v72.localeinfo);
                            v48 = v47;
                            if ( v47 <= 0 )
                              break;
                            write_char_0(v63, f, &pnumwritten);
                            v45 += v48;
                            if ( v46 <= 0 )
                            {
                              v5 = v59;
                              v43 = f;
                              goto LABEL_168;
                            }
                          }
                          v5 = v59;
                          v43 = f;
                          v12 = -1;
                          pnumwritten = -1;
                        }
                        if ( v12 >= 0 && v6 & 4 )
                        {
                          write_multi_char_0(0x20u, v44, v43, &pnumwritten);
                          v12 = pnumwritten;
                        }
LABEL_172:
                        if ( pBlock )
                        {
                          free(pBlock);
                          pBlock = 0i64;
                        }
                        v7 = v56;
LABEL_175:
                        v10 = v70;
                        v14 = v66;
                        break;
                      }
                      if ( v6 & 2 )
                      {
                        string = 32;
                        v20 = 1;
                        v57 = 1;
                        goto LABEL_155;
                      }
                    }
                    v20 = v57;
                    goto LABEL_155;
                  }
LABEL_66:
                  v6 |= 0x40u;
                  v15 = &pwc;
                  v22 = 512;
                  if ( v7 < 0 )
                  {
                    v23 = 6;
                    goto LABEL_68;
                  }
                  if ( v7 )
                  {
                    v23 = 163;
                    if ( v7 > 512 )
                      v7 = 512;
                    v56 = v7;
                    if ( v7 <= 163 )
                    {
                      v23 = v7;
                    }
                    else
                    {
                      v36 = v7 + 349;
                      v37 = malloc_crt(v36);
                      pBlock = v37;
                      if ( v37 )
                      {
                        v15 = (wchar_t *)v37;
                        v22 = v36;
                        goto LABEL_139;
                      }
LABEL_68:
                      v56 = v23;
                    }
                  }
                  else
                  {
                    if ( v11 == 103 )
                    {
                      v23 = 1;
                      goto LABEL_68;
                    }
LABEL_139:
                    v23 = v56;
                  }
                  v38 = *(_QWORD *)v5;
                  v5 += 8;
                  v59 = v5;
                  v75 = (wchar_t *)v38;
                  v39 = DecodePointer(off_142125680);
                  LODWORD(v54) = v71;
                  LODWORD(perrno) = v23;
                  ((void (__fastcall *)(wchar_t **, wchar_t *, _QWORD, _QWORD, int *, __int64, _LocaleUpdate *))v39)(
                    &v75,
                    v15,
                    v22,
                    (unsigned int)(char)v11,
                    perrno,
                    v54,
                    &v72);
                  if ( v6 & 0x80 && !v23 )
                  {
                    v40 = (void (__fastcall *)(wchar_t *, _LocaleUpdate *))DecodePointer(off_142125698);
                    v40(v15, &v72);
                  }
                  if ( v11 == 103 && !(v6 & 0x80) )
                  {
                    v41 = (void (__fastcall *)(wchar_t *, _LocaleUpdate *))DecodePointer(off_142125690);
                    v41(v15, &v72);
                  }
                  if ( *(_BYTE *)v15 == 45 )
                  {
                    v6 |= 0x100u;
                    v15 = (wchar_t *)((char *)v15 + 1);
                  }
                  v42 = strlen((const char *)v15);
                  v12 = pnumwritten;
                  v13 = v42;
                  goto LABEL_53;
                }
LABEL_87:
                v24 = 7;
LABEL_88:
                v68 = v24;
                v26 = 16;
                if ( (v6 & 0x80u) != 0 )
                {
                  v27 = 2;
                  string = 48;
                  v62 = v24 + 81;
$COMMON_INT_1:
                  if ( v6 & 0x8000 || _bittest(&v6, 0xCu) )
                  {
                    v29 = *(_QWORD *)v5;
                    v5 += 8;
                  }
                  else
                  {
                    v5 += 8;
                    if ( v6 & 0x20 )
                    {
                      v59 = v5;
                      if ( v6 & 0x40 )
                        v29 = *((signed __int16 *)v5 - 4);
                      else
                        v29 = *((unsigned __int16 *)v5 - 4);
                      goto LABEL_111;
                    }
                    if ( v6 & 0x40 )
                      v29 = *((signed int *)v5 - 2);
                    else
                      v29 = *((unsigned int *)v5 - 2);
                  }
                  v59 = v5;
LABEL_111:
                  if ( v6 & 0x40 && (v29 & 0x8000000000000000ui64) != 0i64 )
                  {
                    v29 = -(signed __int64)v29;
                    v6 |= 0x100u;
                  }
                  if ( !(v6 & 0x8000) && !_bittest(&v6, 0xCu) )
                    v29 = (unsigned int)v29;
                  if ( v7 >= 0 )
                  {
                    v6 &= 0xFFFFFFF7;
                    if ( v7 > 512 )
                      v7 = 512;
                  }
                  else
                  {
                    v7 = 1;
                  }
                  v30 = v68;
                  v31 = &v78;
                  v57 = v29 != 0 ? v27 : 0;
                  while ( 1 )
                  {
                    v32 = v7--;
                    if ( v32 <= 0 && !v29 )
                      break;
                    v33 = v29 % v26;
                    v29 /= (unsigned __int64)v26;
                    v34 = v33 + 48;
                    if ( (signed int)v33 + 48 > 57 )
                      v34 += v30;
                    *v31-- = v34;
                  }
                  v12 = pnumwritten;
                  v56 = v7;
                  v35 = (char *)&v77 - v31 + 463;
                  v15 = (wchar_t *)(v31 + 1);
                  v13 = v35;
                  if ( v6 & 0x200 && (!v35 || *(_BYTE *)v15 != 48) )
                  {
                    v15 = (wchar_t *)((char *)v15 - 1);
                    v13 = v35 + 1;
                    *(_BYTE *)v15 = 48;
                  }
                  goto LABEL_53;
                }
LABEL_99:
                v27 = v57;
                goto $COMMON_INT_1;
              }
              if ( !(v6 & 0x830) )
                v6 |= 0x20u;
LABEL_42:
              v15 = *(wchar_t **)v5;
              if ( v56 == -1 )
                v7 = 0x7FFFFFFF;
              v5 += 8;
              v59 = v5;
              if ( v6 & 0x20 )
              {
                v13 = 0;
                if ( !v15 )
                  v15 = (wchar_t *)_nullstring;
                v19 = v15;
                if ( v7 > 0 )
                {
                  do
                  {
                    if ( !*(_BYTE *)v19 )
                      break;
                    if ( (unsigned int)isleadbyte_l(*(unsigned __int8 *)v19, &v72.localeinfo) )
                      v19 = (wchar_t *)((char *)v19 + 1);
                    ++v13;
                    v19 = (wchar_t *)((char *)v19 + 1);
                  }
                  while ( v13 < v7 );
                }
                v12 = pnumwritten;
              }
              else
              {
                v58 = 1;
                if ( !v15 )
                  v15 = _wnullstring;
                for ( i = v15; v7; ++i )
                {
                  --v7;
                  if ( !*i )
                    break;
                }
                v13 = i - v15;
              }
              goto LABEL_53;
            }
LABEL_97:
            v6 |= 0x40u;
          }
          v26 = 10;
          goto LABEL_99;
      }
      v11 = *v10;
    }
    while ( *v10 );
  }
  if ( v72.updated )
    v72.ptd->_ownlocale &= 0xFFFFFFFD;
  return (unsigned int)v12;
}

// File Line: 2422
// RVA: 0x12D6F54
void __fastcall write_char_0(wchar_t ch, _iobuf *f, int *pnumwritten)
{
  int *v3; // rbx

  v3 = pnumwritten;
  if ( !(f->_flag & 0x40) || f->_base )
  {
    if ( fputwc_nolock(ch, f) == -1 )
      *v3 = -1;
    else
      ++*v3;
  }
  else
  {
    ++*pnumwritten;
  }
}

// File Line: 2487
// RVA: 0x12D6F8C
void __fastcall write_multi_char_0(wchar_t ch, int num, _iobuf *f, int *pnumwritten)
{
  int *v4; // rdi
  _iobuf *v5; // rsi
  int v6; // ebx
  wchar_t v7; // bp

  if ( num > 0 )
  {
    v4 = pnumwritten;
    v5 = f;
    v6 = num;
    v7 = ch;
    do
    {
      --v6;
      write_char_0(v7, v5, v4);
    }
    while ( *v4 != -1 && v6 > 0 );
  }
}

// File Line: 2561
// RVA: 0x12D6FE0
void __fastcall write_string_0(wchar_t *string, int len, _iobuf *f, int *pnumwritten, int *perrno)
{
  int *v5; // rdi
  int v6; // er15
  _iobuf *v7; // rbp
  int v8; // esi
  wchar_t *v9; // r14

  v5 = pnumwritten;
  v6 = *perrno;
  v7 = f;
  v8 = len;
  v9 = string;
  if ( !(f->_flag & 0x40) || f->_base )
  {
    *perrno = 0;
    if ( len <= 0 )
      goto LABEL_13;
    do
    {
      --v8;
      write_char_0(*v9, v7, v5);
      ++v9;
      if ( *v5 == -1 )
      {
        if ( *perrno != 42 )
          break;
        write_char_0(0x3Fu, v7, v5);
      }
    }
    while ( v8 > 0 );
    if ( !*perrno )
LABEL_13:
      *perrno = v6;
  }
  else
  {
    *pnumwritten += len;
  }
}

