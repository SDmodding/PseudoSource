// File Line: 79
// RVA: 0x12BF3B8
signed __int64 __fastcall read(int fh, void *buf, unsigned int cnt)
{
  unsigned int v3; // er14
  void *v4; // r12
  __int64 v5; // rdi
  __int64 v6; // rsi
  unsigned int v7; // ebx

  v3 = cnt;
  v4 = buf;
  v5 = fh;
  if ( fh == -2 )
  {
    *_doserrno() = 0;
    *errno() = 9;
    return 0xFFFFFFFFi64;
  }
  if ( (signed int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  if ( (signed int)v5 < 0 || (unsigned int)v5 >= nhandle || (v6 = v5 & 0x1F, !(_pioinfo[v5 >> 5][v6].osfile & 1)) )
  {
    *_doserrno() = 0;
    *errno() = 9;
    goto LABEL_14;
  }
  if ( v3 > 0x7FFFFFFF )
  {
    *_doserrno() = 0;
    *errno() = 22;
LABEL_14:
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  _lock_fhandle(v5);
  if ( _pioinfo[v5 >> 5][v6].osfile & 1 )
  {
    v7 = read_nolock(v5, v4, v3);
  }
  else
  {
    *errno() = 9;
    *_doserrno() = 0;
    v7 = -1;
  }
  unlock_fhandle(v5);
  return v7;
}

// File Line: 114
// RVA: 0x12BF4E0
signed __int64 __fastcall read_nolock(int fh, void *inputbuf, unsigned int cnt)
{
  int v3; // edi
  __int64 v4; // r12
  unsigned int v5; // ebx
  char *v6; // r15
  __int64 v7; // r13
  ioinfo *v8; // rcx
  __int64 v9; // rsi
  char v10; // al
  int v11; // er14
  char v12; // dl
  __int64 v13; // rax
  ioinfo *v14; // rax
  char *v15; // r12
  char v16; // cl
  char v17; // cl
  char v18; // cl
  ioinfo *v19; // rcx
  unsigned int v20; // eax
  unsigned int v21; // ebx
  unsigned int v22; // edx
  ioinfo *v23; // rcx
  char v24; // al
  char v25; // al
  char *v26; // rbx
  char *v27; // r12
  char v28; // al
  ioinfo *v29; // rcx
  char v30; // al
  char *v31; // rbx
  signed int i; // edx
  char v33; // cl
  ioinfo *v34; // rax
  char v35; // al
  char v36; // al
  char *v37; // r12
  int v38; // ebx
  int v39; // eax
  unsigned int v40; // eax
  bool v41; // zf
  char *v42; // r8
  char *v43; // r9
  unsigned __int64 v44; // rdx
  __int16 v45; // ax
  char v47; // al
  char *v48; // rbx
  char *v49; // r12
  __int16 v50; // ax
  ioinfo *v51; // rcx
  char v52; // al
  __int16 v53; // [rsp+30h] [rbp-28h]
  unsigned int NumberOfCharsRead; // [rsp+34h] [rbp-24h]
  unsigned int v55; // [rsp+38h] [rbp-20h]
  unsigned int Mode[2]; // [rsp+40h] [rbp-18h]
  unsigned int v57; // [rsp+48h] [rbp-10h]
  int fha; // [rsp+A0h] [rbp+48h]
  wchar_t *lpWideCharStr; // [rsp+A8h] [rbp+50h]
  char Buffer; // [rsp+B0h] [rbp+58h]
  unsigned __int64 v61; // [rsp+B8h] [rbp+60h]

  lpWideCharStr = (wchar_t *)inputbuf;
  fha = fh;
  v3 = 0;
  v4 = fh;
  v5 = cnt;
  v6 = (char *)inputbuf;
  v55 = -2;
  Mode[0] = 0;
  v57 = cnt;
  if ( fh == -2 )
  {
    *_doserrno() = 0;
    *errno() = 9;
    return 0xFFFFFFFFi64;
  }
  if ( (signed int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  if ( (signed int)v4 < 0
    || (unsigned int)v4 >= nhandle
    || (v7 = v4 >> 5, v8 = _pioinfo[v4 >> 5], v9 = v4 & 0x1F, v10 = v8[v9].osfile, !(v10 & 1)) )
  {
    *_doserrno() = 0;
    *errno() = 9;
    goto LABEL_155;
  }
  if ( v5 > 0x7FFFFFFF )
    goto LABEL_8;
  v11 = 0;
  if ( !v5 || v10 & 2 )
    return 0i64;
  if ( !v6 )
    goto LABEL_8;
  v12 = (char)(2 * *((_BYTE *)&v8[v9] + 56)) >> 1;
  LOBYTE(v61) = v12;
  if ( v12 == 1 )
  {
    if ( ~(_BYTE)v5 & 1 )
    {
      v5 >>= 1;
      if ( v5 < 4 )
        v5 = 4;
      v6 = (char *)malloc_crt(v5);
      if ( !v6 )
      {
        *errno() = 12;
        *_doserrno() = 8;
        return 0xFFFFFFFFi64;
      }
      v13 = lseeki64_nolock(v4, 0i64, 1);
      v12 = v61;
      _pioinfo[v7][v9].startpos = v13;
      goto LABEL_22;
    }
LABEL_8:
    *_doserrno() = 0;
    *errno() = 22;
LABEL_155:
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  if ( v12 == 2 )
  {
    if ( ~(_BYTE)v5 & 1 )
    {
      v5 &= 0xFFFFFFFE;
      goto LABEL_22;
    }
    goto LABEL_8;
  }
LABEL_22:
  v14 = _pioinfo[v7];
  v15 = v6;
  if ( v14[v9].osfile & 0x48 )
  {
    v16 = v14[v9].pipech;
    if ( v16 != 10 )
    {
      if ( v5 )
      {
        *v6 = v16;
        --v5;
        v15 = v6 + 1;
        v11 = 1;
        _pioinfo[v7][v9].pipech = 10;
        if ( v12 )
        {
          v17 = _pioinfo[v7][v9].pipech2[0];
          if ( v17 != 10 )
          {
            if ( v5 )
            {
              *v15 = v17;
              --v5;
              v15 = v6 + 2;
              v11 = 2;
              _pioinfo[v7][v9].pipech2[0] = 10;
              if ( v12 == 1 )
              {
                v18 = _pioinfo[v7][v9].pipech2[1];
                if ( v18 != 10 )
                {
                  if ( v5 )
                  {
                    *v15 = v18;
                    v15 = v6 + 3;
                    v11 = 3;
                    --v5;
                    _pioinfo[v7][v9].pipech2[1] = 10;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( !(unsigned int)isatty(fha)
    || (v19 = _pioinfo[v7], v19[v9].osfile >= 0)
    || (Mode[0] = GetConsoleMode((HANDLE)v19[v9].osfhnd, Mode)) == 0
    || (_BYTE)v61 != 2 )
  {
    if ( !ReadFile((HANDLE)_pioinfo[v7][v9].osfhnd, v15, v5, &NumberOfCharsRead, 0i64)
      || (v22 = NumberOfCharsRead, (NumberOfCharsRead & 0x80000000) != 0)
      || (signed int)NumberOfCharsRead > (unsigned __int64)v5 )
    {
      v20 = GetLastError();
      if ( v20 == 5 )
      {
        *errno() = 9;
        *_doserrno() = 5;
        goto LABEL_39;
      }
      if ( v20 == 109 )
      {
        v21 = 0;
        goto LABEL_113;
      }
      goto LABEL_38;
    }
    goto LABEL_44;
  }
  if ( ReadConsoleW((HANDLE)_pioinfo[v7][v9].osfhnd, v15, v5 >> 1, &NumberOfCharsRead, 0i64) )
  {
    v22 = 2 * NumberOfCharsRead;
    NumberOfCharsRead *= 2;
LABEL_44:
    v11 += v22;
    v23 = _pioinfo[v7];
    v24 = v23[v9].osfile;
    if ( v24 >= 0 )
      goto LABEL_112;
    if ( (_BYTE)v61 != 2 )
    {
      if ( v22 && *v6 == 10 )
        v25 = v24 | 4;
      else
        v25 = v24 & 0xFB;
      v23[v9].osfile = v25;
      v26 = v6;
      v27 = v6;
      *(_QWORD *)Mode = &v6[v11];
      if ( (unsigned __int64)v6 < *(_QWORD *)Mode )
      {
        do
        {
          v28 = *v27;
          if ( *v27 == 26 )
          {
            v29 = _pioinfo[v7];
            v30 = v29[v9].osfile;
            if ( v30 & 0x40 )
              *v26++ = *v27;
            else
              v29[v9].osfile = v30 | 2;
            break;
          }
          if ( v28 == 13 )
          {
            if ( (unsigned __int64)v27 < *(_QWORD *)Mode - 1i64 )
            {
              if ( v27[1] != 10 )
              {
                ++v27;
LABEL_68:
                *v26 = 13;
LABEL_69:
                ++v26;
                continue;
              }
              v27 += 2;
              goto LABEL_66;
            }
            ++v27;
            if ( !ReadFile((HANDLE)_pioinfo[v7][v9].osfhnd, &Buffer, 1u, &NumberOfCharsRead, 0i64) && GetLastError()
              || !NumberOfCharsRead )
            {
              goto LABEL_68;
            }
            if ( _pioinfo[v7][v9].osfile & 0x48 )
            {
              if ( Buffer != 10 )
              {
                *v26 = 13;
                _pioinfo[v7][v9].pipech = Buffer;
                goto LABEL_69;
              }
LABEL_66:
              *v26 = 10;
              goto LABEL_69;
            }
            if ( v26 == v6 && Buffer == 10 )
              goto LABEL_66;
            lseeki64_nolock(fha, -1i64, 1);
            if ( Buffer != 10 )
              goto LABEL_68;
          }
          else
          {
            *v26++ = v28;
            ++v27;
          }
        }
        while ( (unsigned __int64)v27 < *(_QWORD *)Mode );
      }
      v11 = (_DWORD)v26 - (_DWORD)v6;
      if ( (_BYTE)v61 == 1 && (_DWORD)v26 != (_DWORD)v6 )
      {
        v31 = v26 - 1;
        if ( *v31 < 0 )
        {
          for ( i = 1; !lookuptrailbytes[(unsigned __int8)*v31] && i <= 4 && v31 >= v6; ++i )
            --v31;
          v33 = *v31;
          if ( !lookuptrailbytes[(unsigned __int8)*v31] )
          {
            *errno() = 42;
            goto LABEL_39;
          }
          if ( lookuptrailbytes[(unsigned __int8)*v31] + 1 == i )
          {
            LODWORD(v31) = i + (_DWORD)v31;
          }
          else
          {
            v34 = _pioinfo[v7];
            if ( v34[v9].osfile & 0x48 )
            {
              ++v31;
              v34[v9].pipech = v33;
              if ( i >= 2 )
              {
                v35 = *v31++;
                _pioinfo[v7][v9].pipech2[0] = v35;
              }
              if ( i == 3 )
              {
                v36 = *v31;
                LODWORD(v31) = (_DWORD)v31 + 1;
                _pioinfo[v7][v9].pipech2[1] = v36;
              }
              LODWORD(v31) = (_DWORD)v31 - i;
            }
            else
            {
              lseeki64_nolock(fha, -i, 1);
            }
          }
        }
        else
        {
          LODWORD(v31) = (_DWORD)v31 + 1;
        }
        v37 = (char *)lpWideCharStr;
        v38 = (_DWORD)v31 - (_DWORD)v6;
        v39 = MultiByteToWideChar(0xFDE9u, 0, v6, v38, lpWideCharStr, v57 >> 1);
        v11 = v39;
        if ( v39 )
        {
          v41 = v39 == v38;
          v21 = v55;
          LOBYTE(v3) = !v41;
          v11 = 2 * v39;
          _pioinfo[v7][v9].utf8translations = v3;
        }
        else
        {
          v40 = GetLastError();
          dosmaperr(v40);
          v21 = -1;
        }
        goto $error_return_0;
      }
LABEL_112:
      v21 = v55;
      goto LABEL_113;
    }
    if ( Mode[0] )
    {
      v42 = v6;
      v43 = v6;
      v44 = (unsigned __int64)&v6[2 * (v11 / 2)];
      if ( (unsigned __int64)v6 < v44 )
      {
        while ( 1 )
        {
          v45 = *(_WORD *)v43;
          if ( *(_WORD *)v43 == 26 )
            break;
          if ( v45 == 13 )
          {
            if ( (unsigned __int64)v43 < v44 - 2 )
            {
              v43 += 2;
              if ( *(_WORD *)v43 == 10 )
                *(_WORD *)v42 = 10;
              else
                *(_WORD *)v42 = 13;
              v42 += 2;
            }
          }
          else
          {
            *(_WORD *)v42 = v45;
            v42 += 2;
            v43 += 2;
          }
          if ( (unsigned __int64)v43 >= v44 )
            goto LABEL_111;
        }
        _pioinfo[v7][v9].osfile |= 2u;
      }
LABEL_111:
      v11 = 2 * (unsigned __int64)((v42 - v6) >> 1);
      goto LABEL_112;
    }
    if ( v22 && *(_WORD *)v6 == 10 )
      v47 = v24 | 4;
    else
      v47 = v24 & 0xFB;
    v23[v9].osfile = v47;
    v48 = v6;
    v49 = v6;
    v61 = (unsigned __int64)&v6[v11];
    if ( (unsigned __int64)v6 >= v61 )
    {
LABEL_148:
      v11 = (_DWORD)v48 - (_DWORD)v6;
      goto LABEL_112;
    }
    while ( 1 )
    {
      v50 = *(_WORD *)v49;
      if ( *(_WORD *)v49 == 26 )
      {
        v51 = _pioinfo[v7];
        v52 = v51[v9].osfile;
        if ( v52 & 0x40 )
        {
          *(_WORD *)v48 = *(_WORD *)v49;
          LODWORD(v48) = (_DWORD)v48 + 2;
        }
        else
        {
          v51[v9].osfile = v52 | 2;
        }
        goto LABEL_148;
      }
      if ( v50 == 13 )
      {
        if ( (unsigned __int64)v49 < v61 - 2 )
        {
          if ( *((_WORD *)v49 + 1) != 10 )
          {
            v49 += 2;
LABEL_141:
            *(_WORD *)v48 = 13;
LABEL_142:
            v48 += 2;
            goto LABEL_143;
          }
          v49 += 4;
          goto LABEL_139;
        }
        v49 += 2;
        if ( !ReadFile((HANDLE)_pioinfo[v7][v9].osfhnd, &v53, 2u, &NumberOfCharsRead, 0i64) && GetLastError()
          || !NumberOfCharsRead )
        {
          goto LABEL_141;
        }
        if ( _pioinfo[v7][v9].osfile & 0x48 )
        {
          if ( v53 != 10 )
          {
            *(_WORD *)v48 = 13;
            _pioinfo[v7][v9].pipech = v53;
            _pioinfo[v7][v9].pipech2[0] = HIBYTE(v53);
            _pioinfo[v7][v9].pipech2[1] = 10;
            goto LABEL_142;
          }
LABEL_139:
          *(_WORD *)v48 = 10;
          goto LABEL_142;
        }
        if ( v48 == v6 && v53 == 10 )
          goto LABEL_139;
        lseeki64_nolock(fha, -2i64, 1);
        if ( v53 != 10 )
          goto LABEL_141;
      }
      else
      {
        *(_WORD *)v48 = v50;
        v48 += 2;
        v49 += 2;
      }
LABEL_143:
      if ( (unsigned __int64)v49 >= v61 )
        goto LABEL_148;
    }
  }
  v20 = GetLastError();
LABEL_38:
  dosmaperr(v20);
LABEL_39:
  v21 = -1;
LABEL_113:
  v37 = (char *)lpWideCharStr;
$error_return_0:
  if ( v6 != v37 )
    free(v6);
  if ( v21 == -2 )
    v21 = v11;
  return v21;
}L_39:
  v21 = -1;
LABEL_113:
  v37 = (char *)lpWideCharStr;
$error_return_0:
  if ( v6 != v37 )
    free(v6);
  if ( v21 == -2 )
    v21 = v11;
  return v21;
}

