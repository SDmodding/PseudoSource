// File Line: 39
// RVA: 0x12C739C
void __fastcall initp_misc_invarg(void *enull)
{
  _pInvalidArgHandler = enull;
}

// File Line: 71
// RVA: 0x12C73A4
void __fastcall invalid_parameter(
        const wchar_t *pszExpression,
        const wchar_t *pszFunction,
        const wchar_t *pszFile,
        unsigned int nLine,
        unsigned __int64 pReserved)
{
  void (__fastcall *v9)(const wchar_t *, const wchar_t *, const wchar_t *, _QWORD); // rax

  v9 = (void (__fastcall *)(const wchar_t *, const wchar_t *, const wchar_t *, _QWORD))DecodePointer(_pInvalidArgHandler);
  if ( !v9 )
  {
    invoke_watson(pszExpression, pszFunction, pszFile, nLine, pReserved);
    JUMPOUT(0x1412C7408i64);
  }
  v9(pszExpression, pszFunction, pszFile, nLine);
}

// File Line: 95
// RVA: 0x12C740C
void __cdecl invalid_parameter_noinfo()
{
  invalid_parameter(0i64, 0i64, 0i64, 0, 0i64);
}

// File Line: 121
// RVA: 0x12C742C
void __fastcall invoke_watson(
        const wchar_t *pszExpression,
        const wchar_t *pszFunction,
        const wchar_t *pszFile,
        unsigned int nLine,
        unsigned __int64 pReserved)
{
  if ( IsProcessorFeaturePresent_0(0x17u) )
    __fastfail(5u);
  call_reportfault(2, 0xC0000417, 1u);
  _crtTerminateProcess(0xC0000417);
}

// File Line: 149
// RVA: 0x12C72A8
void __fastcall call_reportfault(int nDbgHookCode, unsigned int dwExceptionCode, unsigned int dwExceptionFlags)
{
  BOOL v6; // edi
  _EXCEPTION_POINTERS exceptionInfo; // [rsp+20h] [rbp-D8h] BYREF
  _QWORD v8[19]; // [rsp+30h] [rbp-C8h] BYREF
  _CONTEXT pContextRecord; // [rsp+C8h] [rbp-30h] BYREF
  unsigned __int64 vars0; // [rsp+5B0h] [rbp+4B8h]
  void *retaddr; // [rsp+5B8h] [rbp+4C0h] BYREF

  if ( nDbgHookCode != -1 )
    _crt_debugger_hook(nDbgHookCode);
  memset(v8, 0, sizeof(v8));
  exceptionInfo.ExceptionRecord = (_EXCEPTION_RECORD *)v8;
  exceptionInfo.ContextRecord = &pContextRecord;
  _crtCaptureCurrentContext(&pContextRecord);
  pContextRecord.Rip = vars0;
  v8[0] = __PAIR64__(dwExceptionFlags, dwExceptionCode);
  pContextRecord.Rsp = (unsigned __int64)&retaddr;
  v8[2] = vars0;
  v6 = IsDebuggerPresent();
  if ( !_crtUnhandledException(&exceptionInfo) && !v6 && nDbgHookCode != -1 )
    _crt_debugger_hook(nDbgHookCode);
}

