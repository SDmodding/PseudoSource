// File Line: 75
// RVA: 0x12BFD4C
signed __int64 __fastcall write(int fh, const void *buf, unsigned int cnt)
{
  unsigned int v3; // er14
  const void *v4; // r15
  __int64 v5; // rdi
  __int64 v6; // rbx
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
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  _lock_fhandle(v5);
  if ( _pioinfo[v5 >> 5][v6].osfile & 1 )
  {
    v7 = write_nolock(v5, v4, v3);
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

// File Line: 109
// RVA: 0x12BFE38
signed __int64 __fastcall write_nolock(int fh, const void *buf, unsigned int cnt)
{
  unsigned int v3; // edi
  __int64 v4; // r15
  _BYTE *v5; // r14
  __int64 v6; // rbx
  ioinfo *v8; // rsi
  __int64 v9; // r13
  ioinfo *v10; // rcx
  __int64 v11; // r12
  char v12; // si
  BOOL v13; // ebx
  wchar_t *v14; // rbx
  char v15; // cl
  ioinfo *v16; // rdx
  char v17; // al
  unsigned __int64 v18; // r8
  char *v19; // rdx
  int v20; // er13
  unsigned int v21; // er13
  unsigned __int16 v22; // ax
  unsigned int v23; // ebx
  ioinfo *v24; // rcx
  char *v25; // r13
  int v26; // ebx
  char *v27; // rsi
  unsigned __int64 v28; // rcx
  char v29; // al
  void *v30; // rcx
  int v31; // ebx
  char *v32; // rsi
  unsigned __int64 v33; // rcx
  wchar_t v34; // ax
  void *v35; // rcx
  wchar_t *v36; // rcx
  unsigned __int64 v37; // rdx
  wchar_t v38; // ax
  int v39; // esp
  int v40; // eax
  signed int v41; // eax
  signed int v42; // esi
  wchar_t pwc; // [rsp+40h] [rbp-C0h]
  unsigned int oserrno; // [rsp+44h] [rbp-BCh]
  int v45; // [rsp+48h] [rbp-B8h]
  unsigned int v46; // [rsp+4Ch] [rbp-B4h]
  __int64 v47; // [rsp+50h] [rbp-B0h]
  unsigned int NumberOfBytesWritten; // [rsp+58h] [rbp-A8h]
  unsigned int Mode; // [rsp+5Ch] [rbp-A4h]
  char MultiByteStr; // [rsp+60h] [rbp-A0h]
  char v51; // [rsp+61h] [rbp-9Fh]
  wchar_t WideCharStr; // [rsp+70h] [rbp-90h]
  __int64 v53; // [rsp+100h] [rbp+0h]
  char Buffer[5120]; // [rsp+720h] [rbp+620h]

  v3 = 0;
  v4 = cnt;
  v5 = buf;
  v45 = 0;
  v6 = fh;
  if ( !cnt )
    return 0i64;
  if ( !buf )
    goto LABEL_102;
  if ( (signed int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  if ( (unsigned int)(v6 - 1) <= 1 )
  {
    v8 = &_pioinfo[0][v6];
    if ( v8 )
      v8->osfhnd = (__int64)GetStdHandle(-((_DWORD)v6 != 1) - 11);
  }
  v9 = v6 >> 5;
  v10 = _pioinfo[v6 >> 5];
  v47 = v6 >> 5;
  v11 = v6 & 0x1F;
  v12 = (char)(2 * *((_BYTE *)&v10[v11] + 56)) >> 1;
  if ( (unsigned __int8)(v12 - 1) <= 1u && !(~(_BYTE)v4 & 1) )
  {
LABEL_102:
    *_doserrno() = 0;
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  if ( v10[v11].osfile & 0x20 )
    lseeki64_nolock(v6, 0i64, 2);
  if ( !(unsigned int)isatty(v6)
    || _pioinfo[v9][v11].osfile >= 0
    || (v13 = getptd()->ptlocinfo->locale_name[2] == 0i64, !GetConsoleMode((HANDLE)_pioinfo[v9][v11].osfhnd, &Mode))
    || v13 && !v12 )
  {
    v24 = _pioinfo[v9];
    if ( v24[v11].osfile >= 0 )
    {
      if ( WriteFile((HANDLE)v24[v11].osfhnd, v5, v4, &v46, 0i64) )
      {
        v3 = v46;
        v23 = 0;
        goto LABEL_91;
      }
    }
    else
    {
      v23 = 0;
      v25 = v5;
      oserrno = 0;
      if ( v12 )
      {
        if ( v12 == 2 )
        {
          if ( !(_DWORD)v4 )
            goto LABEL_96;
          while ( 1 )
          {
            v31 = v45;
            v32 = Buffer;
            v33 = 0i64;
            do
            {
              if ( (signed int)v25 - (signed int)v5 >= (unsigned int)v4 )
                break;
              v34 = *(_WORD *)v25;
              v25 += 2;
              if ( v34 == 10 )
              {
                *(_WORD *)v32 = 13;
                v31 += 2;
                v32 += 2;
                v33 += 2i64;
              }
              v33 += 2i64;
              *(_WORD *)v32 = v34;
              v32 += 2;
            }
            while ( v33 < 0x13FE );
            v35 = (void *)_pioinfo[v47][v11].osfhnd;
            v45 = v31;
            v23 = oserrno;
            if ( !WriteFile(v35, Buffer, (_DWORD)v32 - (unsigned __int64)(&v53 + 196), &v46, 0i64) )
              break;
            v3 += v46;
            if ( (signed int)v46 < v32 - Buffer || (signed int)v25 - (signed int)v5 >= (unsigned int)v4 )
              goto LABEL_91;
          }
        }
        else
        {
          if ( !(_DWORD)v4 )
            goto LABEL_96;
          while ( 1 )
          {
            v36 = &WideCharStr;
            v37 = 0i64;
            do
            {
              if ( (signed int)v25 - (signed int)v5 >= (unsigned int)v4 )
                break;
              v38 = *(_WORD *)v25;
              v25 += 2;
              if ( v38 == 10 )
              {
                *v36 = 13;
                ++v36;
                v37 += 2i64;
              }
              v37 += 2i64;
              *v36 = v38;
              ++v36;
            }
            while ( v37 < 0x6A8 );
            v40 = (_DWORD)v36 - (v39 + 112);
            v41 = WideCharToMultiByte(0xFDE9u, 0, &WideCharStr, v40 / 2, Buffer, 3413, 0i64, 0i64);
            oserrno = v41;
            if ( !v41 )
              break;
            v42 = 0;
            while ( WriteFile((HANDLE)_pioinfo[v47][v11].osfhnd, &Buffer[v42], v41 - v42, &v46, 0i64) )
            {
              v42 += v46;
              v41 = oserrno;
              if ( (signed int)oserrno <= v42 )
                goto LABEL_85;
            }
            v23 = GetLastError();
            v41 = oserrno;
LABEL_85:
            if ( v41 <= v42 )
            {
              v3 = (_DWORD)v25 - (_DWORD)v5;
              if ( (signed int)v25 - (signed int)v5 < (unsigned int)v4 )
                continue;
            }
            goto LABEL_91;
          }
        }
      }
      else
      {
        if ( !(_DWORD)v4 )
          goto LABEL_96;
        while ( 1 )
        {
          v26 = v45;
          v27 = Buffer;
          v28 = 0i64;
          do
          {
            if ( (signed int)v25 - (signed int)v5 >= (unsigned int)v4 )
              break;
            v29 = *v25++;
            if ( v29 == 10 )
            {
              *v27 = 13;
              ++v26;
              ++v27;
              ++v28;
            }
            ++v28;
            *v27++ = v29;
          }
          while ( v28 < 0x13FF );
          v30 = (void *)_pioinfo[v47][v11].osfhnd;
          v45 = v26;
          v23 = oserrno;
          if ( !WriteFile(v30, Buffer, (_DWORD)v27 - (unsigned __int64)(&v53 + 196), &v46, 0i64) )
            break;
          v3 += v46;
          if ( (signed int)v46 < v27 - Buffer || (signed int)v25 - (signed int)v5 >= (unsigned int)v4 )
            goto LABEL_91;
        }
      }
    }
LABEL_90:
    v23 = GetLastError();
    goto LABEL_91;
  }
  NumberOfBytesWritten = 0;
  v14 = (wchar_t *)v5;
  Mode = GetConsoleCP();
  if ( !(_DWORD)v4 )
  {
    v23 = oserrno;
    goto LABEL_92;
  }
  while ( 1 )
  {
    if ( v12 )
    {
      if ( (unsigned __int8)(v12 - 1) > 1u )
      {
        v21 = oserrno;
      }
      else
      {
        pwc = *v14;
        v21 = pwc == 10;
        ++v14;
        oserrno = pwc == 10;
      }
      if ( (unsigned __int8)(v12 - 1) <= 1u )
      {
        v22 = putwch_nolock(pwc);
        if ( v22 != pwc )
          goto LABEL_90;
        v3 += 2;
        if ( v21 )
        {
          pwc = 13;
          if ( putwch_nolock(0xDu) != 13 )
            goto LABEL_90;
          ++v3;
          ++v45;
        }
      }
      v9 = v47;
      goto LABEL_45;
    }
    v15 = *(_BYTE *)v14;
    oserrno = *(_BYTE *)v14 == 10;
    v16 = _pioinfo[v9];
    if ( v16[v11].dbcsBufferUsed )
    {
      v17 = v16[v11].dbcsBuffer;
      v51 = v15;
      v18 = 2i64;
      MultiByteStr = v17;
      v16[v11].dbcsBufferUsed = 0;
      v19 = &MultiByteStr;
      goto LABEL_28;
    }
    if ( isleadbyte(v15) )
      break;
    v18 = 1i64;
    v19 = (char *)v14;
LABEL_28:
    if ( mbtowc(&pwc, v19, v18) == -1 )
      goto LABEL_48;
LABEL_29:
    v14 = (wchar_t *)((char *)v14 + 1);
    v20 = WideCharToMultiByte(Mode, 0, &pwc, 1, &MultiByteStr, 5, 0i64, 0i64);
    if ( !v20 )
      goto LABEL_48;
    if ( !WriteFile((HANDLE)_pioinfo[v47][v11].osfhnd, &MultiByteStr, v20, &NumberOfBytesWritten, 0i64) )
      goto LABEL_90;
    v3 = v45 + (_DWORD)v14 - (_DWORD)v5;
    if ( (signed int)NumberOfBytesWritten < v20 )
      goto LABEL_48;
    v9 = v47;
    if ( oserrno )
    {
      MultiByteStr = 13;
      if ( !WriteFile((HANDLE)_pioinfo[v47][v11].osfhnd, &MultiByteStr, 1u, &NumberOfBytesWritten, 0i64) )
        goto LABEL_90;
      if ( (signed int)NumberOfBytesWritten < 1 )
        goto LABEL_48;
      ++v45;
      ++v3;
    }
LABEL_45:
    if ( (signed int)v14 - (signed int)v5 >= (unsigned int)v4 )
      goto LABEL_48;
  }
  if ( (signed __int64)&v5[v4 - (_QWORD)v14] > 1 )
  {
    if ( mbtowc(&pwc, (const char *)v14, 2ui64) == -1 )
      goto LABEL_48;
    v14 = (wchar_t *)((char *)v14 + 1);
    goto LABEL_29;
  }
  ++v3;
  _pioinfo[v9][v11].dbcsBuffer = *(_BYTE *)v14;
  _pioinfo[v9][v11].dbcsBufferUsed = 1;
LABEL_48:
  v23 = oserrno;
LABEL_91:
  if ( v3 )
    return v3 - v45;
LABEL_92:
  if ( !v23 )
  {
LABEL_96:
    if ( !(_pioinfo[v47][v11].osfile & 0x40) || *v5 != 26 )
    {
      *errno() = 28;
      *_doserrno() = 0;
      return 0xFFFFFFFFi64;
    }
    return 0i64;
  }
  if ( v23 == 5 )
  {
    *errno() = 9;
    *_doserrno() = 5;
  }
  else
  {
    dosmaperr(v23);
  }
  return 0xFFFFFFFFi64;
}

