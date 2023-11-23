// File Line: 102
// RVA: 0x12D707C
__int64 open(const char *path, int oflag, int pmode, ...)
{
  int v4; // eax
  int v5; // ebx
  ioinfo *v6; // rax
  int pfh; // [rsp+40h] [rbp-18h] BYREF
  int punlock_flag[5]; // [rsp+44h] [rbp-14h] BYREF

  pfh = -1;
  punlock_flag[0] = 0;
  if ( !path )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0xFFFFFFFFi64;
  }
  v4 = sopen_nolock(punlock_flag, &pfh, path, oflag, 64, pmode, 0);
  v5 = v4;
  punlock_flag[1] = v4;
  if ( punlock_flag[0] )
  {
    if ( v4 )
    {
      v6 = _pioinfo[(__int64)pfh >> 5];
      v6[pfh & 0x1F].osfile &= ~1u;
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
__int64 __fastcall wsopen_helper(const wchar_t *path, int oflag, int shflag, int pmode, int *pfh, int bSecure)
{
  int v7; // eax
  unsigned int v8; // edi
  ioinfo *v9; // rax
  int punlock_flag[6]; // [rsp+40h] [rbp-18h] BYREF

  punlock_flag[0] = 0;
  if ( !pfh || (*pfh = -1, !path) || bSecure && (pmode & 0xFFFFFE7F) != 0 )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22i64;
  }
  else
  {
    v7 = wsopen_nolock(punlock_flag, pfh, path, oflag, shflag, pmode, bSecure);
    v8 = v7;
    punlock_flag[1] = v7;
    if ( punlock_flag[0] )
    {
      if ( v7 )
      {
        v9 = _pioinfo[(__int64)*pfh >> 5];
        v9[*pfh & 0x1F].osfile &= ~1u;
      }
      unlock_fhandle(*pfh);
    }
    if ( v8 )
      *pfh = -1;
    return v8;
  }
}

// File Line: 174
// RVA: 0x1452381
_wsopen_helper$fin$0

// File Line: 205
// RVA: 0x12D7228
__int64 __fastcall sopen_nolock(int *punlock_flag, unsigned int *pfh, const char *path, int oflag)
{
  unsigned int v8; // ebx
  wchar_t *patha; // [rsp+40h] [rbp-18h] BYREF

  patha = 0i64;
  if ( !(unsigned int)_copy_path_to_wide_string(path, &patha) )
    return 0xFFFFFFFFi64;
  v8 = wsopen_nolock(punlock_flag, pfh, patha, oflag);
  free(patha);
  return v8;
}

// File Line: 231
// RVA: 0x12CFC98
__int64 __fastcall _LN36_39(
        const wchar_t *path,
        DWORD fileaccess,
        DWORD fileshare,
        _SECURITY_ATTRIBUTES *lpSecurityAttributes,
        unsigned int filecreate,
        unsigned int fileattrib,
        unsigned int fileflags)
{
  HMODULE ModuleHandleW; // rax
  FARPROC ProcAddress; // rbx
  __int64 (__fastcall *v14)(); // [rsp+40h] [rbp-38h]
  int v15[4]; // [rsp+48h] [rbp-30h] BYREF
  _SECURITY_ATTRIBUTES *v16; // [rsp+58h] [rbp-20h]
  __int64 v17; // [rsp+60h] [rbp-18h]

  if ( (unsigned int)_crtIsPackagedApp() )
  {
    ModuleHandleW = GetModuleHandleW(L"kernel32.dll");
    ProcAddress = GetProcAddress(ModuleHandleW, "CreateFile2");
    if ( !ProcAddress )
      return -1i64;
  }
  else
  {
    ProcAddress = v14;
  }
  if ( !(unsigned int)_crtIsPackagedApp() )
    return (__int64)CreateFileW(
                      path,
                      fileaccess,
                      fileshare,
                      lpSecurityAttributes,
                      filecreate,
                      fileflags | fileattrib,
                      0i64);
  v15[3] = 0;
  v17 = 0i64;
  v15[1] = fileattrib;
  v15[0] = 32;
  v15[2] = fileflags;
  v16 = lpSecurityAttributes;
  return ((__int64 (__fastcall *)(const wchar_t *, _QWORD, _QWORD, _QWORD, int *))ProcAddress)(
           path,
           fileaccess,
           fileshare,
           filecreate,
           v15);
}

// File Line: 285
// RVA: 0x12CFE68
__int64 __fastcall wsopen_nolock(int *punlock_flag, unsigned int *pfh, const wchar_t *path, int oflag)
{
  unsigned int v4; // edi
  unsigned int LastError; // eax
  unsigned int v9; // r14d
  char v10; // r12
  DWORD v11; // r13d
  int v12; // r15d
  int v13; // eax
  unsigned int v14; // edx
  int v15; // eax
  wchar_t *v16; // rcx
  void *v17; // rax
  unsigned int v18; // eax
  DWORD FileType; // eax
  unsigned int v20; // ebx
  char v21; // r12
  int v22; // ecx
  bool v23; // zf
  int v24; // r12d
  unsigned int v25; // eax
  int v26; // r14d
  int nolock; // eax
  int v28; // eax
  __int64 v29; // rax
  __int64 v30; // rcx
  ioinfo *v31; // rax
  __int64 v32; // rax
  __int64 v33; // rdx
  ioinfo *v34; // rcx
  __int64 v35; // rax
  unsigned int v36; // eax
  char v37; // [rsp+8h] [rbp-41h]
  int v38; // [rsp+Ch] [rbp-3Dh]
  __int64 fileshare; // [rsp+10h] [rbp-39h]
  __int64 filesharea; // [rsp+10h] [rbp-39h]
  DWORD fileshareb; // [rsp+10h] [rbp-39h]
  unsigned int fileflags; // [rsp+14h] [rbp-35h]
  char v43; // [rsp+18h] [rbp-31h]
  wchar_t inputbuf; // [rsp+1Ch] [rbp-2Dh] BYREF
  unsigned int filecreate[2]; // [rsp+20h] [rbp-29h]
  unsigned int fileattrib[2]; // [rsp+28h] [rbp-21h] BYREF
  int pMode; // [rsp+30h] [rbp-19h] BYREF
  HANDLE hObject; // [rsp+38h] [rbp-11h]
  _SECURITY_ATTRIBUTES SecurityAttributes; // [rsp+40h] [rbp-9h] BYREF
  _DWORD *v50; // [rsp+98h] [rbp+4Fh]
  wchar_t *patha; // [rsp+A8h] [rbp+5Fh]
  int v52; // [rsp+B8h] [rbp+6Fh]
  char vars0; // [rsp+C0h] [rbp+77h]

  v4 = 0;
  pMode = 0;
  SecurityAttributes.lpSecurityDescriptor = 0i64;
  SecurityAttributes.nLength = 24;
  if ( (int)ioinit() < 0 )
  {
    *pfh = -1;
    LastError = GetLastError();
    dosmaperr(LastError);
    return (unsigned int)*errno();
  }
  v9 = 1;
  if ( (oflag & 0x80u) == 0 )
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
    JUMPOUT(0x1412D0642i64);
  }
  if ( (oflag & 0x8000) == 0 && ((oflag & 0x74000) != 0 || pMode != 0x8000) )
    v10 |= 0x80u;
  if ( (oflag & 3) != 0 )
  {
    if ( (oflag & 3) != 1 )
    {
      if ( (oflag & 3) != 2 )
      {
LABEL_15:
        *_doserrno() = 0;
        *pfh = -1;
        *errno() = 22;
        invalid_parameter_noinfo();
        return 22i64;
      }
      goto LABEL_16;
    }
    if ( (oflag & 8) != 0 && (oflag & 0x70000) != 0 )
    {
LABEL_16:
      v11 = -1073741824;
      goto LABEL_21;
    }
    v11 = 0x40000000;
  }
  else
  {
    v11 = 0x80000000;
  }
LABEL_21:
  v12 = 2;
  if ( v52 != 16 && v52 != 32 && v52 != 48 && v52 != 64 && v52 != 128 )
    goto LABEL_15;
  v13 = oflag & 0x700;
  if ( (oflag & 0x700) == 0 )
    goto LABEL_38;
  switch ( v13 )
  {
    case 256:
      v9 = 4;
      goto LABEL_39;
    case 512:
LABEL_36:
      v9 = 5;
      goto LABEL_39;
    case 768:
      v9 = 2;
      goto LABEL_39;
    case 1024:
LABEL_38:
      v9 = 3;
      goto LABEL_39;
    case 1280:
      goto LABEL_39;
    case 1536:
      goto LABEL_36;
  }
  if ( v13 != 1792 )
    goto LABEL_15;
LABEL_39:
  v14 = 128;
  filecreate[0] = 128;
  if ( (oflag & 0x100) != 0 )
  {
    if ( (vars0 & ~(_BYTE)umaskval & 0x80u) == 0 )
      v14 = 1;
    filecreate[0] = v14;
  }
  if ( (oflag & 0x40) != 0 )
    v11 |= 0x10000u;
  if ( (oflag & 0x1000) != 0 )
    filecreate[0] = v14 | 0x100;
  v15 = alloc_osfhnd();
  *pfh = v15;
  if ( v15 == -1 )
  {
    *_doserrno() = 0;
    *pfh = -1;
    *errno() = 24;
    return (unsigned int)*errno();
  }
  v16 = patha;
  *v50 = 1;
  v17 = (void *)_LN36_39(v16, v11, fileshare, &SecurityAttributes, v9, filecreate[0], HIDWORD(fileshare));
  hObject = v17;
  if ( v17 != (void *)-1i64
    || (v11 & 0xC0000000) == -1073741824
    && (oflag & 1) != 0
    && (v17 = (void *)_LN36_39(
                        patha,
                        v11 & 0x7FFFFFFF,
                        filesharea,
                        &SecurityAttributes,
                        v9,
                        filecreate[0],
                        HIDWORD(filesharea)),
        hObject = v17,
        v17 != (void *)-1i64) )
  {
    FileType = GetFileType(v17);
    switch ( FileType )
    {
      case 0u:
        _pioinfo[(__int64)(int)*pfh >> 5][*pfh & 0x1F].osfile &= ~1u;
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
    set_osfhnd(*pfh, hObject);
    v21 = v10 | 1;
    _pioinfo[(__int64)(int)*pfh >> 5][*pfh & 0x1F].osfile = v21;
    *((_BYTE *)&_pioinfo[(__int64)(int)*pfh >> 5][*pfh & 0x1F] + 56) &= 0x80u;
    v43 = v21 & 0x48;
    if ( (v21 & 0x48) == 0 )
    {
      if ( v21 >= 0 )
        goto LABEL_116;
      if ( (oflag & 2) != 0 )
      {
        *(_LARGE_INTEGER *)fileattrib = lseeki64_nolock(*pfh, (LARGE_INTEGER)-1i64, 2u);
        if ( *(_QWORD *)fileattrib == -1i64 )
        {
          if ( *_doserrno() != 131 )
          {
LABEL_67:
            close_nolock(*pfh);
            return (unsigned int)*errno();
          }
        }
        else if ( !(unsigned int)read_nolock(*pfh, &inputbuf, 1u)
               && inputbuf == 26
               && (unsigned int)chsize_nolock(*pfh, *(__int64 *)fileattrib) == -1
               || lseeki64_nolock(*pfh, 0i64, 0) == -1i64 )
        {
          goto LABEL_67;
        }
      }
    }
    if ( v21 >= 0 )
      goto LABEL_116;
    if ( (oflag & 0x74000) == 0 )
    {
      if ( (pMode & 0x74000) != 0 )
        oflag |= pMode & 0x74000;
      else
        oflag |= 0x4000u;
    }
    v22 = oflag & 0x74000;
    if ( (oflag & 0x74000) != 0x4000 )
    {
      if ( ((v22 - 0x10000) & 0xFFFFBFFF) != 0 )
      {
        if ( ((v22 - 0x20000) & 0xFFFFBFFF) != 0 )
        {
          if ( ((v22 - 0x40000) & 0xFFFFBFFF) == 0 )
            v37 = 1;
LABEL_85:
          if ( (oflag & 0x70000) != 0 )
          {
            v23 = (v21 & 0x40) == 0;
            v24 = v38;
            fileattrib[0] = 0;
            if ( !v23 )
              goto LABEL_117;
            v25 = v38 & 0xC0000000;
            if ( (v38 & 0xC0000000) == 0x40000000 )
            {
              if ( v9 > 2 && v9 <= 4 && *(_QWORD *)&lseeki64_nolock(*pfh, 0i64, 2u) )
                goto LABEL_110;
            }
            else
            {
              if ( v25 == 0x80000000 )
              {
LABEL_97:
                nolock = read_nolock(*pfh, (wchar_t *)fileattrib, 3u);
                if ( nolock == -1 )
                  goto LABEL_67;
                if ( nolock != 2 )
                {
                  if ( nolock != 3 )
                    goto LABEL_110;
                  if ( fileattrib[0] == 12565487 )
                  {
                    v37 = 1;
                    goto LABEL_117;
                  }
                }
                if ( LOWORD(fileattrib[0]) == 65534 )
                {
                  close_nolock(*pfh);
                  *errno() = 22;
                  return 22;
                }
                if ( LOWORD(fileattrib[0]) == 65279 )
                {
                  if ( lseeki64_nolock(*pfh, (LARGE_INTEGER)2i64, 0) == -1i64 )
                    goto LABEL_67;
                  v37 = 2;
LABEL_117:
                  v29 = (int)*pfh;
                  v30 = v29 & 0x1F;
                  v31 = _pioinfo[v29 >> 5];
                  *((_BYTE *)&v31[v30] + 56) &= 0x80u;
                  *((_BYTE *)&v31[v30] + 56) |= v37 & 0x7F;
                  v32 = (int)*pfh;
                  v33 = v32 & 0x1F;
                  v34 = _pioinfo[v32 >> 5];
                  *((_BYTE *)&v34[v33] + 56) &= ~0x80u;
                  *((_BYTE *)&v34[v33] + 56) |= BYTE2(oflag) << 7;
                  if ( !v43 && (oflag & 8) != 0 )
                    _pioinfo[(__int64)(int)*pfh >> 5][*pfh & 0x1F].osfile |= 0x20u;
                  if ( (v24 & 0xC0000000) != -1073741824 || (oflag & 1) == 0 )
                    return v4;
                  CloseHandle(hObject);
                  v35 = _LN36_39(patha, v24 & 0x7FFFFFFF, fileshareb, &SecurityAttributes, 3u, filecreate[0], fileflags);
                  if ( v35 != -1 )
                  {
                    _pioinfo[(__int64)(int)*pfh >> 5][*pfh & 0x1F].osfhnd = v35;
                    return v4;
                  }
                  v36 = GetLastError();
                  dosmaperr(v36);
                  _pioinfo[(__int64)(int)*pfh >> 5][*pfh & 0x1F].osfile &= ~1u;
                  free_osfhnd(*pfh);
                  return (unsigned int)*errno();
                }
LABEL_110:
                if ( lseeki64_nolock(*pfh, 0i64, 0) == -1i64 )
                  goto LABEL_67;
                goto LABEL_117;
              }
              if ( v25 != -1073741824 )
                goto LABEL_117;
              if ( v9 > 2 && v9 <= 4 && *(_QWORD *)&lseeki64_nolock(*pfh, 0i64, 2u) )
              {
                if ( lseeki64_nolock(*pfh, 0i64, 0) == -1i64 )
                  goto LABEL_67;
                goto LABEL_97;
              }
            }
            v26 = 0;
            if ( v37 == 1 )
            {
              fileattrib[0] = 12565487;
              v12 = 3;
LABEL_113:
              while ( 1 )
              {
                v28 = write(*pfh, (char *)fileattrib + v26, v12 - v26);
                if ( v28 == -1 )
                  goto LABEL_67;
                v26 += v28;
                if ( v12 <= v26 )
                  goto LABEL_117;
              }
            }
            if ( v37 == 2 )
            {
              fileattrib[0] = 65279;
              goto LABEL_113;
            }
            goto LABEL_117;
          }
LABEL_116:
          v24 = v38;
          goto LABEL_117;
        }
      }
      else if ( (oflag & 0x301) != 769 )
      {
        goto LABEL_85;
      }
      v37 = 2;
      goto LABEL_85;
    }
    v37 = 0;
    goto LABEL_85;
  }
  _pioinfo[(__int64)(int)*pfh >> 5][*pfh & 0x1F].osfile &= ~1u;
  v18 = GetLastError();
  dosmaperr(v18);
  return (unsigned int)*errno();
}

// File Line: 1002
// RVA: 0x12D72B0
__int64 __fastcall sopen_s(int *pfh, const char *path, int oflag, int shflag, int pmode)
{
  return sopen_helper(path, oflag, shflag, pmode, pfh, 1);
}

