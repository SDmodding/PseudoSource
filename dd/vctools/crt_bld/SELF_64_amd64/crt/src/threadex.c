// File Line: 174
// RVA: 0x12BA140
HANDLE __fastcall beginthreadex(
        _SECURITY_ATTRIBUTES *security,
        unsigned int stacksize,
        unsigned int (__fastcall *initialcode)(void *),
        void *argument,
        unsigned int createflag,
        unsigned int *thrdaddr)
{
  unsigned int LastError; // ebx
  SIZE_T v9; // r14
  _tiddata *v11; // rdi
  _tiddata *v12; // rax
  unsigned int *v13; // rcx
  DWORD dwCreationFlags; // eax
  unsigned int *lpThreadId; // r8
  HANDLE result; // rax
  char v17; // [rsp+60h] [rbp+18h] BYREF

  LastError = 0;
  v9 = stacksize;
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
    if ( LastError )
      dosmaperr(LastError);
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
  v11->_initaddr = initialcode;
  v11->_initarg = argument;
  result = CreateThread(security, v9, threadstartex, v11, dwCreationFlags, lpThreadId);
  if ( !result )
  {
    LastError = GetLastError();
    goto $error_return;
  }
  return result;
}

// File Line: 277
// RVA: 0x12BA2EC
void __fastcall __noreturn threadstartex(_QWORD *ptd)
{
  DWORD flsindex; // eax
  _QWORD *Value; // rax
  int v4; // ebx
  _QWORD *v5; // rdi
  DWORD v6; // eax
  DWORD LastError; // eax
  int IsPackagedApp; // eax
  HMODULE Library; // rax
  FARPROC ProcAddress; // rax
  unsigned int (__fastcall *v11)(__int64); // rax

  flsindex = _get_flsindex();
  Value = _crtFlsGetValue(flsindex);
  v4 = 0;
  v5 = Value;
  if ( Value )
  {
    Value[18] = ptd[18];
    Value[19] = ptd[19];
    Value[1] = ptd[1];
    freefls(ptd);
  }
  else
  {
    v6 = _get_flsindex();
    if ( !_crtFlsSetValue(v6, ptd) )
    {
      LastError = GetLastError();
      ExitThread(LastError);
    }
    v5 = ptd;
    *(_DWORD *)ptd = GetCurrentThreadId();
  }
  IsPackagedApp = _crtIsPackagedApp();
  *((_DWORD *)v5 + 282) = IsPackagedApp;
  if ( !IsPackagedApp )
LABEL_12:
    callthreadstartex();
  if ( !dword_1424C52F0 )
  {
    Library = LoadLibraryExW(L"combase.dll", 0i64, 0x800u);
    ProcAddress = GetProcAddress(Library, "RoInitialize");
    if ( !ProcAddress )
    {
LABEL_11:
      *((_DWORD *)v5 + 282) = v4;
      goto LABEL_12;
    }
    qword_1424C52E8 = EncodePointer(ProcAddress);
    dword_1424C52F0 = 1;
  }
  v11 = (unsigned int (__fastcall *)(__int64))DecodePointer(qword_1424C52E8);
  LOBYTE(v4) = v11(1i64) == 0;
  goto LABEL_11;
}

// File Line: 341
// RVA: 0x12BA230
void __noreturn callthreadstartex()
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
void __fastcall __noreturn endthreadex(DWORD retcode)
{
  _tiddata *v2; // rax
  _tiddata *v3; // rbx
  HMODULE Library; // rax
  FARPROC ProcAddress; // rax
  void (*v6)(void); // rax

  v2 = getptd_noexit();
  v3 = v2;
  if ( !v2 )
LABEL_8:
    ExitThread(retcode);
  if ( v2->_initapartment )
  {
    if ( dword_1424C52F4 )
    {
LABEL_6:
      v6 = (void (*)(void))DecodePointer(Ptr);
      v6();
      goto LABEL_7;
    }
    Library = LoadLibraryExW(L"combase.dll", 0i64, 0x800u);
    ProcAddress = GetProcAddress(Library, "RoUninitialize");
    if ( ProcAddress )
    {
      Ptr = EncodePointer(ProcAddress);
      dword_1424C52F4 = 1;
      goto LABEL_6;
    }
  }
LABEL_7:
  freeptd(v3);
  goto LABEL_8;
}

