// File Line: 64
// RVA: 0x12BB550
void __fastcall _raise_securityfailure(_EXCEPTION_POINTERS *ExceptionPointers)
{
  _EXCEPTION_POINTERS *v1; // rbx

  v1 = ExceptionPointers;
  DebuggerWasPresent = IsDebuggerPresent();
  _crt_debugger_hook(1);
  _crtUnhandledException(v1);
  if ( !DebuggerWasPresent )
    _crt_debugger_hook(1);
  _crtTerminateProcess(0xC0000409);
}

// File Line: 129
// RVA: 0x12BB59C
void __fastcall __noreturn _report_gsfailure(unsigned __int64 StackCookie)
{
  void *retaddr; // [rsp+38h] [rbp+0h]
  unsigned __int64 v2; // [rsp+40h] [rbp+8h]

  v2 = StackCookie;
  if ( IsProcessorFeaturePresent_0(0x17u) )
    __fastfail(2u);
  _crtCapturePreviousContext(&GS_ContextRecord);
  GS_ContextRecord.Rip = (unsigned __int64)retaddr;
  GS_ContextRecord.Rsp = (unsigned __int64)&v2;
  GS_ExceptionRecord.ExceptionAddress = retaddr;
  GS_ContextRecord.Rcx = v2;
  GS_ExceptionRecord.ExceptionCode = -1073740791;
  GS_ExceptionRecord.ExceptionFlags = 1;
  GS_ExceptionRecord.NumberParameters = 1;
  GS_ExceptionRecord.ExceptionInformation[0] = 2i64;
  _raise_securityfailure(&GS_ExceptionPointers);
}

// File Line: 386
// RVA: 0x12BB684
void __fastcall _report_securityfailure(unsigned int FailureCode)
{
  void *retaddr; // [rsp+28h] [rbp+0h]
  unsigned int v2; // [rsp+30h] [rbp+8h]

  v2 = FailureCode;
  if ( IsProcessorFeaturePresent_0(0x17u) )
    __fastfail(v2);
  _crtCaptureCurrentContext(&GS_ContextRecord);
  GS_ContextRecord.Rip = (unsigned __int64)retaddr;
  GS_ContextRecord.Rsp = (unsigned __int64)&v2;
  GS_ExceptionRecord.ExceptionAddress = retaddr;
  GS_ExceptionRecord.ExceptionCode = -1073740791;
  GS_ExceptionRecord.ExceptionFlags = 1;
  GS_ExceptionRecord.NumberParameters = 1;
  GS_ExceptionRecord.ExceptionInformation[0] = v2;
  _raise_securityfailure(&GS_ExceptionPointers);
}

// File Line: 480
// RVA: 0x12BB670
void _report_rangecheckfailure()
{
  _report_securityfailure(8u);
}

