// File Line: 102
// RVA: 0x12D707C
signed __int64 open(const char *path, int oflag, int pmode, ...)
{
  int v4; // eax
  int v5; // ebx
  ioinfo *v6; // rax
  int pfh; // [rsp+40h] [rbp-18h]
  int punlock_flag; // [rsp+44h] [rbp-14h]
  int v9; // [rsp+48h] [rbp-10h]

  pfh = -1;
  punlock_flag = 0;
  if ( !path )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  v4 = sopen_nolock(&punlock_flag, &pfh, path, oflag, 64, pmode, 0);
  v5 = v4;
  v9 = v4;
  if ( punlock_flag )
  {
    if ( v4 )
    {
      v6 = _pioinfo[(signed __int64)pfh >> 5];
      v6[pfh & 0x1F].osfile &= 0xFEu;
    }
    unlock_fhandle(pfh);
  }
  if ( v5 )
  {
    *errno() = v5;
    return 0xFFFFFFFFi64;
  }
  return (unsigned int)pfh;
}

// File Line: 126
// RVA: 0x145233A
_open$fin$0

// File Line: 154
// RVA: 0x12CFD8C
signed __int64 __fastcall wsopen_helper(const wchar_t *path, int oflag, int shflag, int pmode, int *pfh, int bSecure)
{
  signed __int64 result; // rax
  int v7; // eax
  unsigned int v8; // edi
  ioinfo *v9; // rax
  int punlock_flag; // [rsp+40h] [rbp-18h]
  int v11; // [rsp+44h] [rbp-14h]

  punlock_flag = 0;
  if ( !pfh || (*pfh = -1, !path) || bSecure && pmode & 0xFFFFFE7F )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 22i64;
  }
  else
  {
    v7 = wsopen_nolock(&punlock_flag, pfh, path, oflag, shflag, pmode, bSecure);
    v8 = v7;
    v11 = v7;
    if ( punlock_flag )
    {
      if ( v7 )
      {
        v9 = _pioinfo[(signed __int64)*pfh >> 5];
        v9[*pfh & 0x1F].osfile &= 0xFEu;
      }
      unlock_fhandle(*pfh);
    }
    if ( v8 )
      *pfh = -1;
    result = v8;
  }
  return result;
}

// File Line: 174
// RVA: 0x1452381
_wsopen_helper$fin$0

// File Line: 205
// RVA: 0x12D7228
signed __int64 __fastcall sopen_nolock(int *punlock_flag, int *pfh, const char *path, int oflag)
{
  int *v4; // rdi
  int *v5; // rsi
  int v6; // ebx
  unsigned int v8; // ebx
  wchar_t *patha; // [rsp+40h] [rbp-18h]

  patha = 0i64;
  v4 = pfh;
  v5 = punlock_flag;
  v6 = oflag;
  if ( !(unsigned int)_copy_path_to_wide_string(path, &patha) )
    return 0xFFFFFFFFi64;
  v8 = wsopen_nolock(v5, v4, patha, v6);
  free(patha);
  return v8;
}

// File Line: 231
// RVA: 0x12CFC98
HANDLE __fastcall _LN36_39(const wchar_t *path, unsigned int fileaccess, unsigned int fileshare, _SECURITY_ATTRIBUTES *lpSecurityAttributes, unsigned int filecreate, unsigned int fileattrib, unsigned int fileflags)
{
  _SECURITY_ATTRIBUTES *v7; // rdi
  unsigned int v8; // esi
  unsigned int v9; // ebp
  const wchar_t *v10; // r14
  HMODULE v11; // rax
  FARPROC v12; // rbx
  __int64 (__fastcall *v14)(); // [rsp+40h] [rbp-38h]
  int v15; // [rsp+48h] [rbp-30h]
  unsigned int v16; // [rsp+4Ch] [rbp-2Ch]
  unsigned int v17; // [rsp+50h] [rbp-28h]
  int v18; // [rsp+54h] [rbp-24h]
  _SECURITY_ATTRIBUTES *v19; // [rsp+58h] [rbp-20h]
  __int64 v20; // [rsp+60h] [rbp-18h]

  v7 = lpSecurityAttributes;
  v8 = fileshare;
  v9 = fileaccess;
  v10 = path;
  if ( (unsigned int)_crtIsPackagedApp() )
  {
    v11 = GetModuleHandleW(L"kernel32.dll");
    v12 = GetProcAddress(v11, "CreateFile2");
    if ( !v12 )
      return (HANDLE)-1i64;
  }
  else
  {
    v12 = v14;
  }
  if ( !(unsigned int)_crtIsPackagedApp() )
    return CreateFileW(v10, v9, v8, v7, filecreate, fileflags | fileattrib, 0i64);
  v18 = 0;
  v20 = 0i64;
  v16 = fileattrib;
  v15 = 32;
  v17 = fileflags;
  v19 = v7;
  return (HANDLE)((__int64 (__fastcall *)(const wchar_t *, _QWORD, _QWORD, _QWORD, int *))v12)(
                   v10,
                   v9,
                   v8,
                   filecreate,
                   &v15);
}

// File Line: 285
// RVA: 0x12CFE68
signed __int64 __fastcall wsopen_nolock(int *punlock_flag, int *pfh, const wchar_t *path, int oflag)
{
  unsigned int v4; // edi
  int v5; // esi
  int *v6; // rbx
  unsigned int v7; // eax
  unsigned int v9; // er14
  char v10; // r12
  unsigned int v11; // er13
  signed int v12; // er15
  int v13; // eax
  unsigned int v14; // edx
  int v15; // eax
  wchar_t *v16; // rcx
  HANDLE v17; // rax
  unsigned int v18; // eax
  DWORD v19; // eax
  unsigned int v20; // ebx
  char v21; // r12
  int v22; // ecx
  bool v23; // zf
  int v24; // er12
  unsigned int v25; // eax
  int v26; // er14
  int v27; // eax
  int v28; // eax
  __int64 v29; // rcx
  __int64 v30; // rax
  signed __int64 v31; // rcx
  ioinfo *v32; // rax
  __int64 v33; // rdx
  __int64 v34; // rax
  signed __int64 v35; // rdx
  ioinfo *v36; // rcx
  unsigned int v37; // ST10_4
  unsigned int fileflags; // ST14_4
  HANDLE v39; // rax
  unsigned int v40; // eax
  char v41; // [rsp+8h] [rbp-41h]
  int v42; // [rsp+Ch] [rbp-3Dh]
  __int64 fileshare; // [rsp+10h] [rbp-39h]
  __int64 filesharea; // [rsp+10h] [rbp-39h]
  char v45; // [rsp+18h] [rbp-31h]
  __int16 inputbuf; // [rsp+1Ch] [rbp-2Dh]
  unsigned int filecreate[2]; // [rsp+20h] [rbp-29h]
  unsigned int fileattrib[2]; // [rsp+28h] [rbp-21h]
  int pMode; // [rsp+30h] [rbp-19h]
  HANDLE hObject; // [rsp+38h] [rbp-11h]
  _SECURITY_ATTRIBUTES SecurityAttributes; // [rsp+40h] [rbp-9h]
  _DWORD *v52; // [rsp+98h] [rbp+4Fh]
  wchar_t *patha; // [rsp+A8h] [rbp+5Fh]
  int v54; // [rsp+B8h] [rbp+6Fh]
  char vars0; // [rsp+C0h] [rbp+77h]

  v4 = 0;
  v5 = oflag;
  v6 = pfh;
  pMode = 0;
  SecurityAttributes.lpSecurityDescriptor = 0i64;
  SecurityAttributes.nLength = 24;
  if ( (signed int)ioinit() < 0 )
  {
    *v6 = -1;
    v7 = GetLastError();
    dosmaperr(v7);
    return (unsigned int)*errno();
  }
  v9 = 1;
  if ( (v5 & 0x80u) == 0 )
  {
    SecurityAttributes.bInheritHandle = 1;
    v10 = 0;
  }
  else
  {
    SecurityAttributes.bInheritHandle = 0;
    v10 = 16;
  }
  if ( get_fmode(&pMode) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    JUMPOUT(*(_QWORD *)&byte_1412D0642);
  }
  if ( !(v5 & 0x8000) && (v5 & 0x74000 || pMode != 0x8000) )
    v10 |= 0x80u;
  if ( v5 & 3 )
  {
    if ( (v5 & 3) != 1 )
    {
      if ( (v5 & 3) != 2 )
      {
LABEL_16:
        *_doserrno() = 0;
        *v6 = -1;
        *errno() = 22;
        invalid_parameter_noinfo();
        return 22i64;
      }
      goto LABEL_17;
    }
    if ( v5 & 8 && v5 & 0x70000 )
    {
LABEL_17:
      v11 = -1073741824;
      goto LABEL_22;
    }
    v11 = 0x40000000;
  }
  else
  {
    v11 = 2147483648;
  }
LABEL_22:
  v12 = 2;
  if ( v54 != 16 && v54 != 32 && v54 != 48 && v54 != 64 && v54 != 128 )
    goto LABEL_16;
  v13 = v5 & 0x700;
  if ( !(v5 & 0x700) )
    goto LABEL_134;
  switch ( v13 )
  {
    case 256:
      v9 = 4;
      goto LABEL_40;
    case 512:
LABEL_37:
      v9 = 5;
      goto LABEL_40;
    case 768:
      v9 = 2;
      goto LABEL_40;
    case 1024:
LABEL_134:
      v9 = 3;
      goto LABEL_40;
    case 1280:
      goto LABEL_40;
    case 1536:
      goto LABEL_37;
  }
  if ( v13 != 1792 )
    goto LABEL_16;
LABEL_40:
  v14 = 128;
  filecreate[0] = 128;
  if ( v5 & 0x100 )
  {
    if ( (vars0 & ~(_BYTE)umaskval & 0x80u) == 0 )
      v14 = 1;
    filecreate[0] = v14;
  }
  if ( v5 & 0x40 )
    v11 |= 0x10000u;
  if ( _bittest(&v5, 0xCu) )
    filecreate[0] = v14 | 0x100;
  v15 = alloc_osfhnd();
  *v6 = v15;
  if ( v15 == -1 )
  {
    *_doserrno() = 0;
    *v6 = -1;
    *errno() = 24;
    return (unsigned int)*errno();
  }
  v16 = patha;
  *v52 = 1;
  v17 = _LN36_39(v16, v11, fileshare, &SecurityAttributes, v9, filecreate[0], HIDWORD(fileshare));
  hObject = v17;
  if ( v17 != (HANDLE)-1i64
    || (v11 & 0xC0000000) == -1073741824
    && v5 & 1
    && (v17 = _LN36_39(patha, v11 & 0x7FFFFFFF, filesharea, &SecurityAttributes, v9, filecreate[0], HIDWORD(filesharea)),
        hObject = v17,
        v17 != (HANDLE)-1i64) )
  {
    v19 = GetFileType(v17);
    switch ( v19 )
    {
      case 0u:
        _pioinfo[(signed __int64)*v6 >> 5][*v6 & 0x1F].osfile &= 0xFEu;
        v20 = GetLastError();
        dosmaperr(v20);
        CloseHandle(hObject);
        if ( !v20 )
          *errno() = 13;
        return (unsigned int)*errno();
      case 2u:
        v10 |= 0x40u;
        break;
      case 3u:
        v10 |= 8u;
        break;
    }
    set_osfhnd(*v6, (__int64)hObject);
    v21 = v10 | 1;
    _pioinfo[(signed __int64)*v6 >> 5][*v6 & 0x1F].osfile = v21;
    *((_BYTE *)&_pioinfo[(signed __int64)*v6 >> 5][*v6 & 0x1F] + 56) &= 0x80u;
    v45 = v21 & 0x48;
    if ( !(v21 & 0x48) )
    {
      if ( v21 >= 0 )
        goto LABEL_120;
      if ( v5 & 2 )
      {
        *(_LARGE_INTEGER *)fileattrib = lseeki64_nolock(*v6, -1i64, 2);
        if ( *(_QWORD *)fileattrib == -1i64 )
        {
          if ( *_doserrno() != 131 )
          {
LABEL_68:
            close_nolock(*v6);
            return (unsigned int)*errno();
          }
        }
        else if ( !(unsigned int)read_nolock(*v6, &inputbuf, 1u)
               && inputbuf == 26
               && (unsigned int)chsize_nolock(*v6, *(__int64 *)fileattrib) == -1
               || lseeki64_nolock(*v6, 0i64, 0) == -1i64 )
        {
          goto LABEL_68;
        }
      }
    }
    if ( v21 >= 0 )
      goto LABEL_120;
    if ( !(v5 & 0x74000) )
    {
      if ( pMode & 0x74000 )
        v5 |= pMode & 0x74000;
      else
        v5 |= 0x4000u;
    }
    v22 = v5 & 0x74000;
    if ( (v5 & 0x74000) != 0x4000 )
    {
      if ( (v22 - 0x10000) & 0xFFFFBFFF )
      {
        if ( (v22 - 0x20000) & 0xFFFFBFFF )
        {
          if ( !((v22 - 0x40000) & 0xFFFFBFFF) )
            v41 = 1;
LABEL_86:
          if ( v5 & 0x70000 )
          {
            v23 = (v21 & 0x40) == 0;
            v24 = v42;
            fileattrib[0] = 0;
            if ( !v23 )
              goto LABEL_121;
            v25 = v42 & 0xC0000000;
            if ( (v42 & 0xC0000000) == 0x40000000 )
            {
              if ( !v9 )
                goto LABEL_121;
              if ( v9 <= 2 )
                goto LABEL_95;
              if ( v9 > 4 )
                goto LABEL_94;
              if ( lseeki64_nolock(*v6, 0i64, 2) )
                goto LABEL_114;
            }
            else
            {
              if ( v25 == 0x80000000 )
                goto LABEL_100;
              if ( v25 != -1073741824 || !v9 )
                goto LABEL_121;
              if ( v9 > 2 )
              {
                if ( v9 > 4 )
                {
LABEL_94:
                  if ( v9 != 5 )
                    goto LABEL_121;
                  goto LABEL_95;
                }
                if ( lseeki64_nolock(*v6, 0i64, 2) )
                {
                  if ( lseeki64_nolock(*v6, 0i64, 0) == -1i64 )
                    goto LABEL_68;
LABEL_100:
                  v27 = read_nolock(*v6, fileattrib, 3u);
                  if ( v27 == -1 )
                    goto LABEL_68;
                  if ( v27 != 2 )
                  {
                    if ( v27 != 3 )
                      goto LABEL_114;
                    if ( fileattrib[0] == 12565487 )
                    {
                      v41 = 1;
                      goto LABEL_121;
                    }
                  }
                  if ( LOWORD(fileattrib[0]) == 65534 )
                  {
                    close_nolock(*v6);
                    *errno() = 22;
                    return 22;
                  }
                  if ( LOWORD(fileattrib[0]) == 65279 )
                  {
                    if ( lseeki64_nolock(*v6, 2i64, 0) == -1i64 )
                      goto LABEL_68;
                    v41 = 2;
LABEL_121:
                    v29 = *v6;
                    v30 = v29;
                    v31 = v29 & 0x1F;
                    v32 = _pioinfo[v30 >> 5];
                    *((_BYTE *)&v32[v31] + 56) &= 0x80u;
                    *((_BYTE *)&v32[v31] + 56) |= v41 & 0x7F;
                    v33 = *v6;
                    v34 = v33;
                    v35 = v33 & 0x1F;
                    v36 = _pioinfo[v34 >> 5];
                    *((_BYTE *)&v36[v35] + 56) &= 0x7Fu;
                    *((_BYTE *)&v36[v35] + 56) |= BYTE2(v5) << 7;
                    if ( !v45 && v5 & 8 )
                      _pioinfo[(signed __int64)*v6 >> 5][*v6 & 0x1F].osfile |= 0x20u;
                    if ( (v24 & 0xC0000000) != -1073741824 || !(v5 & 1) )
                      return v4;
                    CloseHandle(hObject);
                    v39 = _LN36_39(patha, v24 & 0x7FFFFFFF, v37, &SecurityAttributes, 3u, filecreate[0], fileflags);
                    if ( v39 != (HANDLE)-1i64 )
                    {
                      _pioinfo[(signed __int64)*v6 >> 5][*v6 & 0x1F].osfhnd = (__int64)v39;
                      return v4;
                    }
                    v40 = GetLastError();
                    dosmaperr(v40);
                    _pioinfo[(signed __int64)*v6 >> 5][*v6 & 0x1F].osfile &= 0xFEu;
                    free_osfhnd(*v6);
                    return (unsigned int)*errno();
                  }
LABEL_114:
                  if ( lseeki64_nolock(*v6, 0i64, 0) == -1i64 )
                    goto LABEL_68;
                  goto LABEL_121;
                }
              }
            }
LABEL_95:
            v26 = 0;
            if ( v41 == 1 )
            {
              fileattrib[0] = 12565487;
              v12 = 3;
LABEL_117:
              while ( 1 )
              {
                v28 = write(*v6, (char *)fileattrib + v26, v12 - v26);
                if ( v28 == -1 )
                  goto LABEL_68;
                v26 += v28;
                if ( v12 <= v26 )
                  goto LABEL_121;
              }
            }
            if ( v41 == 2 )
            {
              fileattrib[0] = 65279;
              goto LABEL_117;
            }
            goto LABEL_121;
          }
LABEL_120:
          v24 = v42;
          goto LABEL_121;
        }
      }
      else if ( (v5 & 0x301) != 769 )
      {
        goto LABEL_86;
      }
      v41 = 2;
      goto LABEL_86;
    }
    v41 = 0;
    goto LABEL_86;
  }
  _pioinfo[(signed __int64)*v6 >> 5][*v6 & 0x1F].osfile &= 0xFEu;
  v18 = GetLastError();
  dosmaperr(v18);
  return (unsigned int)*errno();
}

// File Line: 1002
// RVA: 0x12D72B0
signed __int64 __fastcall sopen_s(int *pfh, const char *path, int oflag, int shflag, int pmode)
{
  return sopen_helper(path, oflag, shflag, pmode, pfh, 1);
}

