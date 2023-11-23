// File Line: 259
// RVA: 0x12B425C
int __fastcall cinit(int initFloatingPrecision)
{
  int result; // eax
  void (**i)(void); // rbx

  if ( FPinit && IsNonwritableInCurrentImage((char *)&FPinit) )
    FPinit(initFloatingPrecision);
  initp_misc_cfltcvt_tab();
  result = initterm_e(_xi_a, _xi_z);
  if ( !result )
  {
    atexit((int (__fastcall *)())RTC_Terminate);
    for ( i = _xc_a; i < _xc_z; ++i )
    {
      if ( *i )
        (*i)();
    }
    if ( _dyn_tls_init_callback )
    {
      if ( IsNonwritableInCurrentImage((char *)&_dyn_tls_init_callback) )
        _dyn_tls_init_callback(0i64, 2u, 0i64);
    }
    return 0;
  }
  return result;
}

// File Line: 393
// RVA: 0x12B4580
void __fastcall __noreturn exit(unsigned int code)
{
  doexit(code, 0, 0);
}

// File Line: 401
// RVA: 0x12B430C
void __fastcall __noreturn exit(int code)
{
  doexit(code, 1, 0);
}

// File Line: 408
// RVA: 0x12B424C
void __cdecl cexit()
{
  doexit(0, 0, 1);
}

// File Line: 415
// RVA: 0x12B423C
void __cdecl c_exit()
{
  doexit(0, 1, 1);
}

// File Line: 440
// RVA: 0x12B4214
void __fastcall __noreturn amsg_exit(int rterrnum)
{
  FF_MSGBANNER();
  NMSG_WRITE(rterrnum);
  doexit(255, 1, 0);
  JUMPOUT(0x1412B4239i64);
}

// File Line: 506
// RVA: 0x12B43E8
void __fastcall doexit(unsigned int code, int quick, int retcaller)
{
  PVOID *v6; // rsi
  PVOID *v7; // rdi
  PVOID *v8; // r12
  PVOID *v9; // r15
  void (__fastcall *v10)(__int64, __int64, __int64, __int64); // rbx
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // r8
  __int64 v14; // r9
  PVOID *v15; // rbx
  PVOID *v16; // rax

  lock(8);
  if ( C_Exit_Done != 1 )
  {
    C_Termination_Done = 1;
    exitflag = retcaller;
    if ( !quick )
    {
      v6 = (PVOID *)DecodePointer(_onexitbegin);
      if ( v6 )
      {
        v7 = (PVOID *)DecodePointer(_onexitend);
        v8 = v6;
        v9 = v7;
        while ( --v7 >= v6 )
        {
          if ( *v7 != EncodePointer(0i64) )
          {
            if ( v7 < v6 )
              break;
            v10 = (void (__fastcall *)(__int64, __int64, __int64, __int64))DecodePointer(*v7);
            *v7 = EncodePointer(0i64);
            v10(v12, v11, v13, v14);
            v15 = (PVOID *)DecodePointer(_onexitbegin);
            v16 = (PVOID *)DecodePointer(_onexitend);
            if ( v8 != v15 || v9 != v16 )
            {
              v8 = v15;
              v6 = v15;
              v9 = v16;
              v7 = v16;
            }
          }
        }
      }
      initterm(_xp_a, _xp_z);
    }
    initterm(_xt_a, _xt_z);
  }
  if ( !retcaller )
  {
    C_Exit_Done = 1;
    unlock(8);
    _crtCorExitProcess(code);
    ExitProcess(code);
  }
  unlock(8);
}

// File Line: 625
// RVA: 0x1451D7B
doexit$fin$0

// File Line: 692
// RVA: 0x12B41B8
void __fastcall _crtCorExitProcess(unsigned int status)
{
  FARPROC ProcAddress; // rax
  HMODULE phModule; // [rsp+38h] [rbp+10h] BYREF

  if ( GetModuleHandleExW(0, L"mscoree.dll", &phModule) )
  {
    ProcAddress = GetProcAddress(phModule, "CorExitProcess");
    if ( ProcAddress )
      ((void (__fastcall *)(_QWORD))ProcAddress)(status);
  }
}

// File Line: 714
// RVA: 0x12B41FC
void __fastcall __noreturn _crtExitProcess(unsigned int status)
{
  _crtCorExitProcess(status);
  ExitProcess(status);
}

// File Line: 774
// RVA: 0x12B43D0
void lockexit()
{
  lock(8);
}

// File Line: 800
// RVA: 0x12B43DC
void unlockexit()
{
  unlock(8);
}

// File Line: 825
// RVA: 0x12B4318
void init_pointers()
{
  PVOID v0; // rbx

  v0 = EncodePointer(0i64);
  initp_heap_handler(v0);
  initp_misc_invarg(v0);
  initp_misc_purevirt(v0);
  initp_misc_rand_s((int (__fastcall *)(void *, unsigned int))v0);
  initp_misc_winsig(v0);
  initp_eh_hooks(v0);
}

// File Line: 875
// RVA: 0x12B4360
void __fastcall initterm(void (__fastcall **pfbegin)(), void (__fastcall **pfend)())
{
  void (**v3)(void); // rbx

  if ( pfbegin < pfend )
  {
    v3 = pfbegin;
    do
    {
      if ( *v3 )
        (*v3)();
      ++v3;
    }
    while ( v3 < pfend );
  }
}

// File Line: 924
// RVA: 0x12B4394
__int64 __fastcall initterm_e(__int64 (**pfbegin)(void), __int64 (**pfend)(void))
{
  __int64 result; // rax
  __int64 (**i)(void); // rbx

  result = 0i64;
  for ( i = pfbegin; i < pfend; ++i )
  {
    if ( (_DWORD)result )
      break;
    if ( *i )
      result = (*i)();
  }
  return result;
}

// File Line: 1026
// RVA: 0x12B40B8
__int64 __fastcall _copy_path_to_wide_string(const char *path, unsigned __int16 **outPath)
{
  UINT v2; // edi
  int v6; // eax
  int cchWideChar; // ebp
  unsigned int LastError; // eax
  unsigned __int16 *lpWideCharStr; // rax
  unsigned int v10; // eax

  v2 = 0;
  if ( !path || !outPath )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22i64;
  }
  if ( !_crtIsPackagedApp() && !AreFileApisANSI() )
    v2 = 1;
  *outPath = 0i64;
  v6 = MultiByteToWideChar(v2, 0, path, -1, 0i64, 0);
  cchWideChar = v6;
  if ( !v6 )
  {
    LastError = GetLastError();
    dosmaperr(LastError);
    return 0i64;
  }
  lpWideCharStr = (unsigned __int16 *)malloc_crt(2i64 * v6);
  *outPath = lpWideCharStr;
  if ( !lpWideCharStr )
    return 0i64;
  if ( !MultiByteToWideChar(v2, 0, path, -1, lpWideCharStr, cchWideChar) )
  {
    v10 = GetLastError();
    dosmaperr(v10);
    free(*outPath);
    *outPath = 0i64;
    return 0i64;
  }
  return 1i64;
}

