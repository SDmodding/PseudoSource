// File Line: 39
// RVA: 0x12C739C
void __fastcall initp_misc_invarg(void *enull)
{
  _pInvalidArgHandler = enull;
}

// File Line: 71
// RVA: 0x12C73A4
void __fastcall invalid_parameter(const wchar_t *pszExpression, const wchar_t *pszFunction, const wchar_t *pszFile, unsigned int nLine, unsigned __int64 pReserved)
{
  const wchar_t *v5; // rbp
  unsigned int v6; // ebx
  const wchar_t *v7; // rdi
  const wchar_t *v8; // rsi
  void (__fastcall *v9)(const wchar_t *, const wchar_t *, const wchar_t *, _QWORD); // rax

  v5 = pszExpression;
  v6 = nLine;
  v7 = pszFile;
  v8 = pszFunction;
  v9 = (void (__fastcall *)(const wchar_t *, const wchar_t *, const wchar_t *, _QWORD))DecodePointer(_pInvalidArgHandler);
  if ( !v9 )
  {
    invoke_watson(v5, v8, v7, v6, pReserved);
    JUMPOUT(*(_QWORD *)&byte_1412C7408);
  }
  v9(v5, v8, v7, v6);
}

// File Line: 95
// RVA: 0x12C740C
void __cdecl invalid_parameter_noinfo()
{
  invalid_parameter(0i64, 0i64, 0i64, 0, 0i64);
}

// File Line: 121
// RVA: 0x12C742C
void __fastcall invoke_watson(const wchar_t *pszExpression, const wchar_t *pszFunction, const wchar_t *pszFile, unsigned int nLine, unsigned __int64 pReserved)
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
  unsigned int v3; // edi
  unsigned int v4; // esi
  int v5; // ebx
  BOOL v6; // edi
  _EXCEPTION_POINTERS exceptionInfo; // [rsp+20h] [rbp-D8h]
  unsigned int v8; // [rsp+30h] [rbp-C8h]
  unsigned int Dst; // [rsp+34h] [rbp-C4h]
  unsigned __int64 v10; // [rsp+40h] [rbp-B8h]
  _CONTEXT pContextRecord; // [rsp+C8h] [rbp-30h]
  unsigned __int64 vars0; // [rsp+5B0h] [rbp+4B8h]
  void *retaddr; // [rsp+5B8h] [rbp+4C0h]

  v3 = dwExceptionFlags;
  v4 = dwExceptionCode;
  v5 = nDbgHookCode;
  if ( nDbgHookCode != -1 )
    _crt_debugger_hook(nDbgHookCode);
  v8 = 0;
  memset(&Dst, 0, 0x94ui64);
  exceptionInfo.ExceptionRecord = (_EXCEPTION_RECORD *)&v8;
  exceptionInfo.ContextRecord = &pContextRecord;
  _crtCaptureCurrentContext(&pContextRecord);
  pContextRecord.Rip = vars0;
  v8 = v4;
  Dst = v3;
  pContextRecord.Rsp = (unsigned __int64)&retaddr;
  v10 = vars0;
  v6 = IsDebuggerPresent();
  if ( !_crtUnhandledException(&exceptionInfo) && !v6 && v5 != -1 )
    _crt_debugger_hook(v5);
}

