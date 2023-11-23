// File Line: 73
// RVA: 0x12CF31C
void *ioinit0()
{
  void *result; // rax

  result = memset(_pioinfo, 0, 0x200ui64);
  nhandle = 3;
  return result;
}

// File Line: 139
// RVA: 0x12CF344
__int64 __fastcall ioinitCallback(_RTL_RUN_ONCE *initOnce, void *param, void **context)
{
  ioinfo *v4; // rax
  unsigned __int64 v5; // rcx
  char *v6; // r14
  HANDLE *v7; // rsi
  int v8; // r15d
  int i; // ebx
  ioinfo *v10; // rax
  unsigned __int64 v11; // rcx
  int v12; // edi
  ioinfo *v13; // rbx
  int v14; // edi
  ioinfo *v15; // rbx
  DWORD v16; // ecx
  HANDLE StdHandle; // rax
  __int64 v18; // rsi
  DWORD FileType; // eax
  char v20; // al
  _BYTE v21[32]; // [rsp+0h] [rbp-D8h] BYREF
  int v22; // [rsp+20h] [rbp-B8h]
  unsigned __int64 v23; // [rsp+28h] [rbp-B0h]
  int v24; // [rsp+30h] [rbp-A8h]
  _BYTE *v25; // [rsp+38h] [rbp-A0h]
  HANDLE *v26; // [rsp+40h] [rbp-98h]
  char *v27; // [rsp+48h] [rbp-90h]
  _STARTUPINFOW StartupInfo; // [rsp+50h] [rbp-88h] BYREF

  v25 = v21;
  lock(11);
  if ( _pioinfo[0] )
  {
    local_unwind(v21, &_LN39_31);
    return 1i64;
  }
  v4 = (ioinfo *)calloc_crt(0x20ui64, 0x58ui64);
  v5 = (unsigned __int64)v4;
  v23 = (unsigned __int64)v4;
  if ( !v4 )
  {
    local_unwind(v25, &_LN40_30);
    return 0i64;
  }
  _pioinfo[0] = v4;
  nhandle = 32;
  while ( v5 < (unsigned __int64)&v4[32] )
  {
    *(_WORD *)(v5 + 8) = 2560;
    *(_QWORD *)v5 = -1i64;
    *(_DWORD *)(v5 + 12) = 0;
    *(_BYTE *)(v5 + 56) &= 0x80u;
    *(_BYTE *)(v5 + 56) &= ~0x80u;
    *(_WORD *)(v5 + 57) = 2570;
    *(_DWORD *)(v5 + 80) = 0;
    *(_BYTE *)(v5 + 76) = 0;
    v5 += 88i64;
    v23 = v5;
    v4 = _pioinfo[0];
  }
  GetStartupInfoW(&StartupInfo);
  if ( StartupInfo.cbReserved2 && StartupInfo.lpReserved2 )
  {
    v6 = StartupInfo.lpReserved2 + 4;
    v27 = StartupInfo.lpReserved2 + 4;
    v7 = (HANDLE *)&StartupInfo.lpReserved2[*(_DWORD *)StartupInfo.lpReserved2 + 4];
    v26 = v7;
    v8 = 2048;
    if ( *(int *)StartupInfo.lpReserved2 < 2048 )
      v8 = *(_DWORD *)StartupInfo.lpReserved2;
    for ( i = 1; ; ++i )
    {
      v24 = i;
      if ( nhandle >= v8 )
        break;
      v10 = (ioinfo *)calloc_crt(0x20ui64, 0x58ui64);
      v11 = (unsigned __int64)v10;
      v23 = (unsigned __int64)v10;
      if ( !v10 )
      {
        v8 = nhandle;
        break;
      }
      _pioinfo[i] = v10;
      nhandle += 32;
      while ( v11 < (unsigned __int64)&_pioinfo[i][32] )
      {
        *(_WORD *)(v11 + 8) = 2560;
        *(_QWORD *)v11 = -1i64;
        *(_DWORD *)(v11 + 12) = 0;
        *(_BYTE *)(v11 + 56) &= 0x80u;
        *(_WORD *)(v11 + 57) = 2570;
        *(_DWORD *)(v11 + 80) = 0;
        *(_BYTE *)(v11 + 76) = 0;
        v11 += 88i64;
        v23 = v11;
      }
    }
    v12 = 0;
    v22 = 0;
    while ( v12 < v8 )
    {
      if ( (unsigned __int64)*v7 + 2 > 1 && (*v6 & 1) != 0 && ((*v6 & 8) != 0 || GetFileType(*v7)) )
      {
        v13 = &_pioinfo[(__int64)v12 >> 5][v12 & 0x1F];
        v23 = (unsigned __int64)v13;
        v13->osfhnd = (__int64)*v7;
        v13->osfile = *v6;
        InitializeCriticalSectionAndSpinCount(&v13->lock, 0xFA0u);
        ++v13->lockinitflag;
      }
      v22 = ++v12;
      v27 = ++v6;
      v26 = ++v7;
    }
  }
  v14 = 0;
  v22 = 0;
  while ( v14 < 3 )
  {
    v15 = &_pioinfo[0][v14];
    v23 = (unsigned __int64)v15;
    if ( v15->osfhnd != -2 && v15->osfhnd != -1 )
    {
      v15->osfile |= 0x80u;
      goto LABEL_44;
    }
    v15->osfile = -127;
    v16 = -(v14 != 1) - 11;
    if ( !v14 )
      v16 = -10;
    StdHandle = GetStdHandle(v16);
    v18 = (__int64)StdHandle;
    if ( (unsigned __int64)StdHandle + 1 > 1 )
    {
      FileType = GetFileType(StdHandle);
      if ( FileType )
      {
        v15->osfhnd = v18;
        if ( (unsigned __int8)FileType == 2 )
        {
          v20 = v15->osfile | 0x40;
          goto LABEL_40;
        }
        if ( (unsigned __int8)FileType == 3 )
        {
          v20 = v15->osfile | 8;
LABEL_40:
          v15->osfile = v20;
        }
        InitializeCriticalSectionAndSpinCount(&v15->lock, 0xFA0u);
        ++v15->lockinitflag;
        goto LABEL_44;
      }
    }
    v15->osfile |= 0x40u;
    v15->osfhnd = -2i64;
    if ( _piob )
      *((_DWORD *)_piob[v14] + 7) = -2;
LABEL_44:
    v22 = ++v14;
  }
  unlock(11);
  return 1i64;
}

// File Line: 346
// RVA: 0x145231F
_ioinitCallback$fin$0

// File Line: 367
// RVA: 0x12CF2F0
__int64 ioinit()
{
  return (unsigned int)InitOnceExecuteOnce(&_ioInitOnce, ioinitCallback, 0i64, 0i64) - 1;
}

