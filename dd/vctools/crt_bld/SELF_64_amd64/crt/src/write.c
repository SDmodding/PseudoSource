// File Line: 75
// RVA: 0x12BFD4C
__int64 __fastcall write(int fh, const void *buf, unsigned int cnt)
{
  __int64 v5; // rdi
  __int64 v6; // rbx
  unsigned int v7; // ebx

  v5 = fh;
  if ( fh == -2 )
  {
    *_doserrno() = 0;
    *errno() = 9;
    return 0xFFFFFFFFi64;
  }
  if ( (int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  if ( (int)v5 < 0 || (unsigned int)v5 >= nhandle || (v6 = v5 & 0x1F, (_pioinfo[v5 >> 5][v6].osfile & 1) == 0) )
  {
    *_doserrno() = 0;
    *errno() = 9;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  _lock_fhandle(v5);
  if ( (_pioinfo[v5 >> 5][v6].osfile & 1) != 0 )
  {
    v7 = write_nolock(v5, buf, cnt);
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
__int64 __fastcall write_nolock(int fh, _BYTE *buf, unsigned int cnt)
{
  unsigned int v3; // edi
  __int64 v4; // r15
  __int64 v6; // rbx
  ioinfo *v8; // rsi
  __int64 v9; // r13
  ioinfo *v10; // rcx
  __int64 v11; // r12
  char v12; // si
  BOOL v13; // ebx
  const char *v14; // rbx
  char v15; // cl
  ioinfo *v16; // rdx
  char dbcsBuffer; // al
  unsigned __int64 v18; // r8
  char *v19; // rdx
  int v20; // r13d
  unsigned int v21; // r13d
  unsigned int LastError; // ebx
  ioinfo *v23; // rcx
  char *v24; // r13
  int v25; // ebx
  char *v26; // rsi
  unsigned __int64 k; // rcx
  char v28; // al
  void *v29; // rcx
  int v30; // ebx
  char *v31; // rsi
  unsigned __int64 i; // rcx
  wchar_t v33; // ax
  void *osfhnd; // rcx
  wchar_t *v35; // rcx
  unsigned __int64 j; // rdx
  wchar_t v37; // ax
  int v38; // esp
  int v39; // kr00_4
  signed int v40; // eax
  signed int v41; // esi
  wchar_t pwc[2]; // [rsp+40h] [rbp-C0h] BYREF
  unsigned int oserrno; // [rsp+44h] [rbp-BCh]
  int v44; // [rsp+48h] [rbp-B8h]
  unsigned int v45; // [rsp+4Ch] [rbp-B4h] BYREF
  __int64 v46; // [rsp+50h] [rbp-B0h]
  unsigned int NumberOfBytesWritten; // [rsp+58h] [rbp-A8h] BYREF
  unsigned int Mode; // [rsp+5Ch] [rbp-A4h] BYREF
  char MultiByteStr[16]; // [rsp+60h] [rbp-A0h] BYREF
  wchar_t WideCharStr[72]; // [rsp+70h] [rbp-90h] BYREF
  _BYTE v51[1568]; // [rsp+100h] [rbp+0h] BYREF
  char Buffer[5120]; // [rsp+720h] [rbp+620h] BYREF

  v3 = 0;
  v4 = cnt;
  v44 = 0;
  v6 = fh;
  if ( !cnt )
    return 0i64;
  if ( !buf )
    goto LABEL_4;
  if ( (int)ioinit() < 0 )
    return 0xFFFFFFFFi64;
  if ( (unsigned int)(v6 - 1) <= 1 )
  {
    v8 = &_pioinfo[0][v6];
    if ( v8 )
      v8->osfhnd = (__int64)GetStdHandle(-((_DWORD)v6 != 1) - 11);
  }
  v9 = v6 >> 5;
  v10 = _pioinfo[v6 >> 5];
  v46 = v6 >> 5;
  v11 = v6 & 0x1F;
  v12 = (char)(2 * *((_BYTE *)&v10[v11] + 56)) >> 1;
  if ( (unsigned __int8)(v12 - 1) <= 1u && (v4 & 1) != 0 )
  {
LABEL_4:
    *_doserrno() = 0;
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  if ( (v10[v11].osfile & 0x20) != 0 )
    lseeki64_nolock(v6, 0i64, 2);
  if ( !(unsigned int)isatty(v6)
    || _pioinfo[v9][v11].osfile >= 0
    || (v13 = getptd()->ptlocinfo->locale_name[2] == 0i64, !GetConsoleMode((HANDLE)_pioinfo[v9][v11].osfhnd, &Mode))
    || v13 && !v12 )
  {
    v23 = _pioinfo[v9];
    if ( v23[v11].osfile >= 0 )
    {
      if ( WriteFile((HANDLE)v23[v11].osfhnd, buf, v4, &v45, 0i64) )
      {
        v3 = v45;
        LastError = 0;
        goto LABEL_91;
      }
    }
    else
    {
      LastError = 0;
      v24 = buf;
      oserrno = 0;
      if ( v12 )
      {
        if ( v12 == 2 )
        {
          if ( !(_DWORD)v4 )
            goto LABEL_96;
          while ( 1 )
          {
            v30 = v44;
            v31 = Buffer;
            for ( i = 0i64; i < 0x13FE; i += 2i64 )
            {
              if ( (int)v24 - (int)buf >= (unsigned int)v4 )
                break;
              v33 = *(_WORD *)v24;
              v24 += 2;
              if ( v33 == 10 )
              {
                *(_WORD *)v31 = 13;
                v30 += 2;
                v31 += 2;
                i += 2i64;
              }
              *(_WORD *)v31 = v33;
              v31 += 2;
            }
            osfhnd = (void *)_pioinfo[v46][v11].osfhnd;
            v44 = v30;
            LastError = oserrno;
            if ( !WriteFile(osfhnd, Buffer, (_DWORD)v31 - ((unsigned int)v51 + 1568), &v45, 0i64) )
              break;
            v3 += v45;
            if ( (int)v45 < v31 - Buffer || (int)v24 - (int)buf >= (unsigned int)v4 )
              goto LABEL_91;
          }
        }
        else
        {
          if ( !(_DWORD)v4 )
            goto LABEL_96;
          while ( 1 )
          {
            v35 = WideCharStr;
            for ( j = 0i64; j < 0x6A8; j += 2i64 )
            {
              if ( (int)v24 - (int)buf >= (unsigned int)v4 )
                break;
              v37 = *(_WORD *)v24;
              v24 += 2;
              if ( v37 == 10 )
              {
                *v35++ = 13;
                j += 2i64;
              }
              *v35++ = v37;
            }
            v39 = (_DWORD)v35 - (v38 + 112);
            v40 = WideCharToMultiByte(0xFDE9u, 0, WideCharStr, v39 / 2, Buffer, 3413, 0i64, 0i64);
            oserrno = v40;
            if ( !v40 )
              break;
            v41 = 0;
            while ( WriteFile((HANDLE)_pioinfo[v46][v11].osfhnd, &Buffer[v41], v40 - v41, &v45, 0i64) )
            {
              v41 += v45;
              v40 = oserrno;
              if ( (int)oserrno <= v41 )
                goto LABEL_85;
            }
            LastError = GetLastError();
            v40 = oserrno;
LABEL_85:
            if ( v40 <= v41 )
            {
              v3 = (_DWORD)v24 - (_DWORD)buf;
              if ( (int)v24 - (int)buf < (unsigned int)v4 )
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
          v25 = v44;
          v26 = Buffer;
          for ( k = 0i64; k < 0x13FF; ++k )
          {
            if ( (int)v24 - (int)buf >= (unsigned int)v4 )
              break;
            v28 = *v24++;
            if ( v28 == 10 )
            {
              *v26 = 13;
              ++v25;
              ++v26;
              ++k;
            }
            *v26++ = v28;
          }
          v29 = (void *)_pioinfo[v46][v11].osfhnd;
          v44 = v25;
          LastError = oserrno;
          if ( !WriteFile(v29, Buffer, (_DWORD)v26 - ((unsigned int)v51 + 1568), &v45, 0i64) )
            break;
          v3 += v45;
          if ( (int)v45 < v26 - Buffer || (int)v24 - (int)buf >= (unsigned int)v4 )
            goto LABEL_91;
        }
      }
    }
LABEL_90:
    LastError = GetLastError();
    goto LABEL_91;
  }
  NumberOfBytesWritten = 0;
  v14 = buf;
  Mode = GetConsoleCP();
  if ( !(_DWORD)v4 )
  {
    LastError = oserrno;
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
        pwc[0] = *(_WORD *)v14;
        v21 = pwc[0] == 10;
        v14 += 2;
        oserrno = v21;
      }
      if ( (unsigned __int8)(v12 - 1) <= 1u )
      {
        if ( putwch_nolock(pwc[0]) != pwc[0] )
          goto LABEL_90;
        v3 += 2;
        if ( v21 )
        {
          pwc[0] = 13;
          if ( putwch_nolock(0xDu) != 13 )
            goto LABEL_90;
          ++v3;
          ++v44;
        }
      }
      v9 = v46;
      goto LABEL_45;
    }
    v15 = *v14;
    oserrno = *v14 == 10;
    v16 = _pioinfo[v9];
    if ( v16[v11].dbcsBufferUsed )
    {
      dbcsBuffer = v16[v11].dbcsBuffer;
      MultiByteStr[1] = v15;
      v18 = 2i64;
      MultiByteStr[0] = dbcsBuffer;
      v16[v11].dbcsBufferUsed = 0;
      v19 = MultiByteStr;
      goto LABEL_28;
    }
    if ( isleadbyte(v15) )
      break;
    v18 = 1i64;
    v19 = (char *)v14;
LABEL_28:
    if ( mbtowc(pwc, v19, v18) == -1 )
      goto LABEL_48;
LABEL_29:
    ++v14;
    v20 = WideCharToMultiByte(Mode, 0, pwc, 1, MultiByteStr, 5, 0i64, 0i64);
    if ( !v20 )
      goto LABEL_48;
    if ( !WriteFile((HANDLE)_pioinfo[v46][v11].osfhnd, MultiByteStr, v20, &NumberOfBytesWritten, 0i64) )
      goto LABEL_90;
    v3 = v44 + (_DWORD)v14 - (_DWORD)buf;
    if ( (int)NumberOfBytesWritten < v20 )
      goto LABEL_48;
    v9 = v46;
    if ( oserrno )
    {
      MultiByteStr[0] = 13;
      if ( !WriteFile((HANDLE)_pioinfo[v46][v11].osfhnd, MultiByteStr, 1u, &NumberOfBytesWritten, 0i64) )
        goto LABEL_90;
      if ( (int)NumberOfBytesWritten < 1 )
        goto LABEL_48;
      ++v44;
      ++v3;
    }
LABEL_45:
    if ( (int)v14 - (int)buf >= (unsigned int)v4 )
      goto LABEL_48;
  }
  if ( (__int64)&buf[v4 - (_QWORD)v14] > 1 )
  {
    if ( mbtowc(pwc, v14, 2ui64) == -1 )
      goto LABEL_48;
    ++v14;
    goto LABEL_29;
  }
  ++v3;
  _pioinfo[v9][v11].dbcsBuffer = *v14;
  _pioinfo[v9][v11].dbcsBufferUsed = 1;
LABEL_48:
  LastError = oserrno;
LABEL_91:
  if ( v3 )
    return v3 - v44;
LABEL_92:
  if ( !LastError )
  {
LABEL_96:
    if ( (_pioinfo[v46][v11].osfile & 0x40) == 0 || *buf != 26 )
    {
      *errno() = 28;
      *_doserrno() = 0;
      return 0xFFFFFFFFi64;
    }
    return 0i64;
  }
  if ( LastError == 5 )
  {
    *errno() = 9;
    *_doserrno() = 5;
  }
  else
  {
    dosmaperr(LastError);
  }
  return 0xFFFFFFFFi64;
}

