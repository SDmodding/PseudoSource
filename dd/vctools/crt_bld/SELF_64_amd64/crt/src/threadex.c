// File Line: 174
// RVA: 0x12BA140
HANDLE __fastcall beginthreadex(void *security, unsigned int stacksize, unsigned int (__fastcall *initialcode)(void *), void *argument, unsigned int createflag, unsigned int *thrdaddr)
{
  unsigned int v6; // ebx
  void *v7; // rbp
  unsigned int (__fastcall *v8)(void *); // rsi
  SIZE_T v9; // r14
  _SECURITY_ATTRIBUTES *v10; // r15
  _tiddata *v11; // rdi
  _tiddata *v12; // rax
  unsigned int *v13; // rcx
  unsigned int dwCreationFlags; // eax
  unsigned int *lpThreadId; // r8
  HANDLE result; // rax
  char v17; // [rsp+60h] [rbp+18h]

  v6 = 0;
  v7 = argument;
  v8 = initialcode;
  v9 = stacksize;
  v10 = (_SECURITY_ATTRIBUTES *)security;
  if ( !initialcode )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 0i64;
  }
  v11 = (_tiddata *)calloc_crt(1ui64, 0x470ui64);
  if ( !v11 )
  {
$error_return:
    free(v11);
    if ( v6 )
      dosmaperr(v6);
    return 0i64;
  }
  v12 = getptd();
  initptd(v11, v12->ptlocinfo);
  v13 = thrdaddr;
  v11->_thandle = -1i64;
  dwCreationFlags = createflag;
  lpThreadId = (unsigned int *)&v17;
  if ( v13 )
    lpThreadId = v13;
  v11->_initaddr = v8;
  v11->_initarg = v7;
  result = CreateThread(v10, v9, threadstartex, v11, dwCreationFlags, lpThreadId);
  if ( !result )
  {
    v6 = GetLastError();
    goto $error_return;
  }
  return result;
}

// File Line: 277
// RVA: 0x12BA2EC
void __fastcall __noreturn threadstartex(void *ptd)
{
  _QWORD *v1; // rsi
  DWORD v2; // eax
  _QWORD *v3; // rax
  int v4; // ebx
  _QWORD *v5; // rdi
  DWORD v6; // eax
  DWORD v7; // eax
  int v8; // eax
  HMODULE v9; // rax
  FARPROC v10; // rax
  unsigned int (__fastcall *v11)(signed __int64); // rax

  v1 = ptd;
  v2 = _get_flsindex();
  v3 = _crtFlsGetValue(v2);
  v4 = 0;
  v5 = v3;
  if ( v3 )
  {
    v3[18] = v1[18];
    v3[19] = v1[19];
    v3[1] = v1[1];
    freefls(v1);
  }
  else
  {
    v6 = _get_flsindex();
    if ( !_crtFlsSetValue(v6, v1) )
    {
      v7 = GetLastError();
      ExitThread(v7);
    }
    v5 = v1;
    *(_DWORD *)v1 = GetCurrentThreadId();
  }
  v8 = _crtIsPackagedApp();
  *((_DWORD *)v5 + 282) = v8;
  if ( !v8 )
LABEL_12:
    callthreadstartex();
  if ( !dword_1424C52F0 )
  {
    v9 = LoadLibraryExW(L"combase.dll", 0i64, 0x800u);
    v10 = GetProcAddress(v9, "RoInitialize");
    if ( !v10 )
    {
LABEL_11:
      *((_DWORD *)v5 + 282) = v4;
      goto LABEL_12;
    }
    qword_1424C52E8 = EncodePointer(v10);
    dword_1424C52F0 = 1;
  }
  v11 = (unsigned int (__fastcall *)(signed __int64))DecodePointer(qword_1424C52E8);
  LOBYTE(v4) = v11(1i64) == 0;
  goto LABEL_11;
}

// File Line: 341
// RVA: 0x12BA230
void callthreadstartex()
{
  _tiddata *v0; // rax
  unsigned int v1; // eax

  v0 = getptd();
  v1 = ((__int64 (__fastcall *)(void *))v0->_initaddr)(v0->_initarg);
  endthreadex(v1);
}

// File Line: 356
// RVA: 0x1451DF1
__tmainCRTStartup$filt$0

// File Line: 388
// RVA: 0x12BA25C
void __fastcall __noreturn endthreadex(unsigned int retcode)
{
  unsigned int v1; // edi
  _tiddata *v2; // rax
  _tiddata *v3; // rbx
  HMODULE v4; // rax
  FARPROC v5; // rax
  void (*v6)(void); // rax

  v1 = retcode;
  v2 = getptd_noexit();
  v3 = v2;
  if ( !v2 )
LABEL_8:
    ExitThread(v1);
  if ( v2->_initapartment )
  {
    if ( dword_1424C52F4 )
    {
LABEL_6:
      v6 = (void (*)(void))DecodePointer(Ptr);
      v6();
      goto LABEL_7;
    }
    v4 = LoadLibraryExW(L"combase.dll", 0i64, 0x800u);
    v5 = GetProcAddress(v4, "RoUninitialize");
    if ( v5 )
    {
      Ptr = EncodePointer(v5);
      dword_1424C52F4 = 1;
      goto LABEL_6;
    }
  }
LABEL_7:
  freeptd(v3);
  goto LABEL_8;
}

