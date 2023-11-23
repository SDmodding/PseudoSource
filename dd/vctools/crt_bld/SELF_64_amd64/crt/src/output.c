// File Line: 974
// RVA: 0x12D64AC
__int64 __fastcall woutput_l(_iobuf *stream, wchar_t *format, localeinfo_struct *plocinfo, char *argptr)
{
  char *v5; // r12
  int v6; // r14d
  int v7; // edi
  bool v8; // zf
  wchar_t *v10; // r8
  wchar_t v11; // r15
  int v12; // esi
  int v13; // r13d
  int v14; // edx
  wchar_t *v15; // rbx
  int v16; // ecx
  __int16 *v17; // rax
  int v18; // eax
  unsigned __int8 *v19; // rsi
  int v20; // esi
  wchar_t v21; // ax
  int v22; // esi
  int v23; // r13d
  int v24; // eax
  wchar_t *i; // rax
  int v26; // r9d
  int v27; // edx
  _WORD *v28; // rdi
  __int64 v29; // r8
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
  _iobuf *v42; // rdi
  int v43; // r15d
  const char *v44; // rdi
  int v45; // esi
  int v46; // eax
  __int64 v47; // r12
  unsigned __int64 v48; // rax
  __int64 v49; // rcx
  int v50; // eax
  int v51; // eax
  int pnumwritten; // [rsp+40h] [rbp-C0h] BYREF
  int v53; // [rsp+44h] [rbp-BCh]
  int v54; // [rsp+48h] [rbp-B8h]
  int v55; // [rsp+4Ch] [rbp-B4h]
  char *v56; // [rsp+50h] [rbp-B0h]
  int v57; // [rsp+58h] [rbp-A8h]
  wchar_t string[2]; // [rsp+5Ch] [rbp-A4h] BYREF
  wchar_t v59[2]; // [rsp+60h] [rbp-A0h] BYREF
  char s[4]; // [rsp+64h] [rbp-9Ch] BYREF
  int v61; // [rsp+68h] [rbp-98h]
  int v62; // [rsp+6Ch] [rbp-94h]
  int v63; // [rsp+70h] [rbp-90h]
  _iobuf *f; // [rsp+78h] [rbp-88h]
  wchar_t *v65; // [rsp+80h] [rbp-80h]
  int v66; // [rsp+88h] [rbp-78h]
  _LocaleUpdate v67; // [rsp+90h] [rbp-70h] BYREF
  void *pBlock; // [rsp+B0h] [rbp-50h]
  int *perrno; // [rsp+B8h] [rbp-48h]
  wchar_t *v70; // [rsp+C0h] [rbp-40h] BYREF
  wchar_t pwc[24]; // [rsp+D0h] [rbp-30h] BYREF
  __int64 v72; // [rsp+100h] [rbp+0h] BYREF
  char v73; // [rsp+2CFh] [rbp+1CFh] BYREF

  f = stream;
  v65 = format;
  v5 = argptr;
  v56 = argptr;
  v63 = 0;
  v6 = 0;
  v57 = 0;
  v7 = 0;
  v53 = 0;
  v54 = 0;
  v62 = 0;
  v55 = 0;
  _LocaleUpdate::_LocaleUpdate(&v67, plocinfo);
  perrno = errno();
  if ( (int)ioinit() < 0 )
  {
    v8 = !v67.updated;
LABEL_3:
    if ( !v8 )
      v67.ptd->_ownlocale &= ~2u;
    return 0xFFFFFFFFi64;
  }
  if ( !stream || (v10 = v65) == 0i64 )
  {
LABEL_7:
    *errno() = 22;
    invalid_parameter_noinfo();
    v8 = !v67.updated;
    goto LABEL_3;
  }
  v11 = *v65;
  v12 = 0;
  pnumwritten = 0;
  v13 = 0;
  v14 = 0;
  pBlock = 0i64;
  if ( v11 )
  {
    v15 = v70;
    do
    {
      v65 = ++v10;
      if ( v12 < 0 )
        break;
      if ( (unsigned __int16)(v11 - 32) > 0x58u )
        v16 = 0;
      else
        v16 = _lookuptable[v11 - 32] & 0xF;
      v14 = _lookuptable[8 * v16 + v14] >> 4;
      v61 = v14;
      switch ( v14 )
      {
        case 0:
          goto $NORMAL_STATE_1;
        case 1:
          v7 = -1;
          v66 = 0;
          v62 = 0;
          v57 = 0;
          v54 = 0;
          v6 = 0;
          v53 = -1;
          v55 = 0;
          break;
        case 2:
          switch ( v11 )
          {
            case  :
              v6 |= 2u;
              break;
            case #:
              v6 |= 0x80u;
              break;
            case +:
              v6 |= 1u;
              break;
            case -:
              v6 |= 4u;
              break;
            case 0:
              v6 |= 8u;
              break;
          }
          break;
        case 3:
          if ( v11 != 42 )
          {
            v51 = v11 + 10 * v57 - 48;
            goto LABEL_208;
          }
          v50 = *(_DWORD *)v5;
          v5 += 8;
          v56 = v5;
          v57 = v50;
          if ( v50 < 0 )
          {
            v6 |= 4u;
            v51 = -v50;
LABEL_208:
            v57 = v51;
          }
          break;
        case 4:
          v7 = 0;
          v53 = 0;
          break;
        case 5:
          if ( v11 != 42 )
          {
            v7 = v11 + 2 * (5 * v7 - 24);
            goto LABEL_202;
          }
          v7 = *(_DWORD *)v5;
          v5 += 8;
          v56 = v5;
          v53 = v7;
          if ( v7 < 0 )
          {
            v7 = -1;
LABEL_202:
            v53 = v7;
          }
          break;
        case 6:
          if ( v11 != 73 )
          {
            switch ( v11 )
            {
              case h:
                v6 |= 0x20u;
                break;
              case l:
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
              case w:
                v6 |= 0x800u;
                break;
            }
            break;
          }
          v48 = *v10;
          v6 |= 0x8000u;
          if ( *(_DWORD *)v10 == 3407926 )
          {
            v10 += 2;
            v6 |= 0x8000u;
            break;
          }
          if ( (_WORD)v48 == 51 && v10[1] == 50 )
          {
            v10 += 2;
            v6 &= ~0x8000u;
            break;
          }
          LOWORD(v48) = v48 - 88;
          if ( (unsigned __int16)v48 <= 0x20u )
          {
            v49 = 0x120821001i64;
            if ( _bittest64(&v49, v48) )
              break;
          }
          v61 = 0;
$NORMAL_STATE_1:
          v55 = 1;
          write_char_0(v11, f, &pnumwritten);
          v12 = pnumwritten;
          goto LABEL_175;
        case 7:
          if ( v11 > 0x64u )
          {
            if ( v11 < 0x65u )
              goto LABEL_53;
            if ( v11 <= 0x67u )
              goto LABEL_66;
            switch ( v11 )
            {
              case i:
                goto LABEL_97;
              case n:
                v28 = *(_WORD **)v5;
                v5 += 8;
                v56 = v5;
                if ( !get_printf_count_output() )
                  goto LABEL_7;
                if ( (v6 & 0x20) != 0 )
                  *v28 = v12;
                else
                  *(_DWORD *)v28 = v12;
                v62 = 1;
                goto LABEL_172;
              case o:
                v26 = 8;
                if ( (v6 & 0x80u) != 0 )
                  v6 |= 0x200u;
                goto LABEL_99;
              case p:
                v7 = 16;
                v6 |= 0x8000u;
                goto LABEL_87;
              case s:
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
                goto LABEL_65;
              if ( v11 == 67 )
              {
                if ( (v6 & 0x830) == 0 )
                  v6 |= 0x20u;
                goto LABEL_60;
              }
              if ( ((v11 - 69) & 0xFFFFFFFD) == 0 )
              {
LABEL_65:
                v66 = 1;
                v11 += 32;
                goto LABEL_66;
              }
              if ( v11 != 83 )
              {
                if ( v11 != 88 )
                {
                  if ( v11 == 90 )
                  {
                    v17 = *(__int16 **)v5;
                    v5 += 8;
                    v56 = v5;
                    if ( v17 && (v15 = (wchar_t *)*((_QWORD *)v17 + 1)) != 0i64 )
                    {
                      if ( (v6 & 0x800) != 0 )
                      {
                        v18 = *v17;
                        v55 = 1;
                        v13 = v18 / 2;
                      }
                      else
                      {
                        v13 = *v17;
                        v55 = 0;
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
                    v55 = 1;
                    v56 = v5;
                    v59[0] = v21;
                    if ( (v6 & 0x20) != 0 )
                    {
                      s[0] = v21;
                      s[1] = 0;
                      if ( (int)mbtowc_l(pwc, s, v67.localeinfo.locinfo->mb_cur_max, &v67.localeinfo) < 0 )
                        v62 = 1;
                    }
                    else
                    {
                      pwc[0] = v21;
                    }
                    v15 = pwc;
                    v13 = 1;
LABEL_53:
                    if ( v62 )
                      goto LABEL_172;
                    if ( (v6 & 0x40) != 0 )
                    {
                      if ( (v6 & 0x100) != 0 )
                      {
                        string[0] = 45;
                        goto LABEL_57;
                      }
                      if ( (v6 & 1) != 0 )
                      {
                        string[0] = 43;
LABEL_57:
                        v20 = 1;
                        v54 = 1;
LABEL_155:
                        v42 = f;
                        v43 = v57 - v13 - v20;
                        if ( (v6 & 0xC) == 0 )
                          write_multi_char_0(0x20u, v43, f, &pnumwritten);
                        write_string_0(string, v20, v42, &pnumwritten, perrno);
                        if ( (v6 & 8) != 0 && (v6 & 4) == 0 )
                          write_multi_char_0(0x30u, v43, v42, &pnumwritten);
                        if ( v55 || v13 <= 0 )
                        {
                          write_string_0(v15, v13, v42, &pnumwritten, perrno);
LABEL_168:
                          v12 = pnumwritten;
                        }
                        else
                        {
                          v44 = (const char *)v15;
                          v45 = v13;
                          while ( 1 )
                          {
                            --v45;
                            v46 = mbtowc_l(v59, v44, v67.localeinfo.locinfo->mb_cur_max, &v67.localeinfo);
                            v47 = v46;
                            if ( v46 <= 0 )
                              break;
                            write_char_0(v59[0], f, &pnumwritten);
                            v44 += v47;
                            if ( v45 <= 0 )
                            {
                              v5 = v56;
                              v42 = f;
                              goto LABEL_168;
                            }
                          }
                          v5 = v56;
                          v42 = f;
                          v12 = -1;
                          pnumwritten = -1;
                        }
                        if ( v12 >= 0 && (v6 & 4) != 0 )
                        {
                          write_multi_char_0(0x20u, v43, v42, &pnumwritten);
                          v12 = pnumwritten;
                        }
LABEL_172:
                        if ( pBlock )
                        {
                          free(pBlock);
                          pBlock = 0i64;
                        }
                        v7 = v53;
LABEL_175:
                        v10 = v65;
                        v14 = v61;
                        break;
                      }
                      if ( (v6 & 2) != 0 )
                      {
                        string[0] = 32;
                        v20 = 1;
                        v54 = 1;
                        goto LABEL_155;
                      }
                    }
                    v20 = v54;
                    goto LABEL_155;
                  }
LABEL_66:
                  v6 |= 0x40u;
                  v15 = pwc;
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
                    v53 = v7;
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
                      v53 = v23;
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
                    v23 = v53;
                  }
                  v38 = *(_QWORD *)v5;
                  v5 += 8;
                  v56 = v5;
                  v70 = (wchar_t *)v38;
                  v39 = DecodePointer(off_142125680);
                  ((void (__fastcall *)(wchar_t **, wchar_t *, _QWORD, _QWORD, int, int, _LocaleUpdate *))v39)(
                    &v70,
                    v15,
                    v22,
                    (unsigned int)(char)v11,
                    v23,
                    v66,
                    &v67);
                  if ( (v6 & 0x80) != 0 && !v23 )
                  {
                    v40 = (void (__fastcall *)(wchar_t *, _LocaleUpdate *))DecodePointer(off_142125698);
                    v40(v15, &v67);
                  }
                  if ( v11 == 103 && (v6 & 0x80) == 0 )
                  {
                    v41 = (void (__fastcall *)(wchar_t *, _LocaleUpdate *))DecodePointer(off_142125690);
                    v41(v15, &v67);
                  }
                  if ( *(_BYTE *)v15 == 45 )
                  {
                    v6 |= 0x100u;
                    v15 = (wchar_t *)((char *)v15 + 1);
                  }
                  v12 = pnumwritten;
                  v13 = strlen((const char *)v15);
                  goto LABEL_53;
                }
LABEL_87:
                v24 = 7;
LABEL_88:
                v63 = v24;
                v26 = 16;
                if ( (v6 & 0x80u) != 0 )
                {
                  v27 = 2;
                  string[0] = 48;
                  string[1] = v24 + 81;
$COMMON_INT_1:
                  if ( (v6 & 0x8000) != 0 || (v6 & 0x1000) != 0 )
                  {
                    v29 = *(_QWORD *)v5;
                    v5 += 8;
                  }
                  else
                  {
                    v5 += 8;
                    if ( (v6 & 0x20) != 0 )
                    {
                      v56 = v5;
                      if ( (v6 & 0x40) != 0 )
                        v29 = *((__int16 *)v5 - 4);
                      else
                        v29 = *((unsigned __int16 *)v5 - 4);
                      goto LABEL_111;
                    }
                    if ( (v6 & 0x40) != 0 )
                      v29 = *((int *)v5 - 2);
                    else
                      v29 = *((unsigned int *)v5 - 2);
                  }
                  v56 = v5;
LABEL_111:
                  if ( (v6 & 0x40) != 0 && v29 < 0 )
                  {
                    v29 = -v29;
                    v6 |= 0x100u;
                  }
                  if ( (v6 & 0x8000) == 0 && (v6 & 0x1000) == 0 )
                    v29 = (unsigned int)v29;
                  if ( v7 >= 0 )
                  {
                    v6 &= ~8u;
                    if ( v7 > 512 )
                      v7 = 512;
                  }
                  else
                  {
                    v7 = 1;
                  }
                  v30 = v63;
                  v31 = &v73;
                  v54 = v29 != 0 ? v27 : 0;
                  while ( 1 )
                  {
                    v32 = v7--;
                    if ( v32 <= 0 && !v29 )
                      break;
                    v33 = v29 % (unsigned __int64)v26;
                    v29 /= (unsigned __int64)v26;
                    v34 = v33 + 48;
                    if ( (int)v33 + 48 > 57 )
                      v34 += v30;
                    *v31-- = v34;
                  }
                  v12 = pnumwritten;
                  v53 = v7;
                  v35 = (unsigned int)&v72 + 463 - (_DWORD)v31;
                  v15 = (wchar_t *)(v31 + 1);
                  v13 = v35;
                  if ( (v6 & 0x200) != 0 && (!v35 || *(_BYTE *)v15 != 48) )
                  {
                    v15 = (wchar_t *)((char *)v15 - 1);
                    v13 = v35 + 1;
                    *(_BYTE *)v15 = 48;
                  }
                  goto LABEL_53;
                }
LABEL_99:
                v27 = v54;
                goto $COMMON_INT_1;
              }
              if ( (v6 & 0x830) == 0 )
                v6 |= 0x20u;
LABEL_42:
              v15 = *(wchar_t **)v5;
              if ( v53 == -1 )
                v7 = 0x7FFFFFFF;
              v5 += 8;
              v56 = v5;
              if ( (v6 & 0x20) != 0 )
              {
                v13 = 0;
                if ( !v15 )
                  v15 = (wchar_t *)_nullstring;
                v19 = (unsigned __int8 *)v15;
                if ( v7 > 0 )
                {
                  do
                  {
                    if ( !*v19 )
                      break;
                    if ( (unsigned int)isleadbyte_l(*v19, &v67.localeinfo) )
                      ++v19;
                    ++v13;
                    ++v19;
                  }
                  while ( v13 < v7 );
                }
                v12 = pnumwritten;
              }
              else
              {
                v55 = 1;
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
  if ( v67.updated )
    v67.ptd->_ownlocale &= ~2u;
  return (unsigned int)v12;
}

// File Line: 2422
// RVA: 0x12D6F54
void __fastcall write_char_0(wchar_t ch, _iobuf *f, int *pnumwritten)
{
  if ( (f->_flag & 0x40) == 0 || f->_base )
  {
    if ( fputwc_nolock(ch, f) == 0xFFFF )
      *pnumwritten = -1;
    else
      ++*pnumwritten;
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
  int v6; // ebx

  if ( num > 0 )
  {
    v6 = num;
    do
    {
      --v6;
      write_char_0(ch, f, pnumwritten);
    }
    while ( *pnumwritten != -1 && v6 > 0 );
  }
}

// File Line: 2561
// RVA: 0x12D6FE0
void __fastcall write_string_0(wchar_t *string, int len, _iobuf *f, int *pnumwritten, int *perrno)
{
  int v6; // r15d
  int v8; // esi

  v6 = *perrno;
  v8 = len;
  if ( (f->_flag & 0x40) == 0 || f->_base )
  {
    *perrno = 0;
    if ( len <= 0 )
      goto LABEL_10;
    do
    {
      --v8;
      write_char_0(*string++, f, pnumwritten);
      if ( *pnumwritten == -1 )
      {
        if ( *perrno != 42 )
          break;
        write_char_0(0x3Fu, f, pnumwritten);
      }
    }
    while ( v8 > 0 );
    if ( !*perrno )
LABEL_10:
      *perrno = v6;
  }
  else
  {
    *pnumwritten += len;
  }
}

