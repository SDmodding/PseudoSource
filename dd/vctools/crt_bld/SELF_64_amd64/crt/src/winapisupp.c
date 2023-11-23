// File Line: 128
// RVA: 0x12CD488
__int64 __fastcall _crtIsPackagedApp()
{
  unsigned int v0; // ebx
  bool v1; // zf
  bool v2; // sf
  HMODULE ModuleHandleW; // rax
  FARPROC ProcAddress; // rax
  int v5; // eax
  int v7; // [rsp+30h] [rbp+8h] BYREF

  v0 = 0;
  v1 = isPackaged == 0;
  v2 = isPackaged < 0;
  if ( isPackaged < 0 )
  {
    v7 = 0;
    ModuleHandleW = GetModuleHandleW(L"kernel32.dll");
    ProcAddress = GetProcAddress(ModuleHandleW, "GetCurrentPackageId");
    if ( !ProcAddress || (v1 = ((unsigned int (__fastcall *)(int *, _QWORD))ProcAddress)(&v7, 0i64) == 122, v5 = 1, !v1) )
      v5 = 0;
    isPackaged = v5;
    v1 = v5 == 0;
    v2 = v5 < 0;
  }
  LOBYTE(v0) = !v2 && !v1;
  return v0;
}

// File Line: 162
// RVA: 0x12CD45C
__int64 __fastcall _crtGetShowWindowMode()
{
  __int64 result; // rax
  _STARTUPINFOW StartupInfo; // [rsp+20h] [rbp-78h] BYREF

  GetStartupInfoW(&StartupInfo);
  result = 10i64;
  if ( (StartupInfo.dwFlags & 1) != 0 )
    return StartupInfo.wShowWindow;
  return result;
}

// File Line: 191
// RVA: 0x12CD4E8
// attributes: thunk
LPTOP_LEVEL_EXCEPTION_FILTER __stdcall _crtSetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter)
{
  return SetUnhandledExceptionFilter(lpTopLevelExceptionFilter);
}

// File Line: 217
// RVA: 0x12CD4F0
void __fastcall _crtTerminateProcess(UINT uExitCode)
{
  HANDLE CurrentProcess; // rax

  CurrentProcess = GetCurrentProcess();
  TerminateProcess(CurrentProcess, uExitCode);
}

// File Line: 249
// RVA: 0x12CD510
LONG __fastcall _crtUnhandledException(_EXCEPTION_POINTERS *exceptionInfo)
{
  SetUnhandledExceptionFilter(0i64);
  return UnhandledExceptionFilter(exceptionInfo);
}

// File Line: 275
// RVA: 0x12CD3C8
void __fastcall _crtCapturePreviousContext(_CONTEXT *pContextRecord)
{
  unsigned __int64 Rip; // rsi
  int i; // edi
  _IMAGE_RUNTIME_FUNCTION_ENTRY *v4; // rax
  unsigned __int64 ImageBase; // [rsp+60h] [rbp+8h] BYREF
  unsigned __int64 EstablisherFrame; // [rsp+68h] [rbp+10h] BYREF
  PVOID HandlerData; // [rsp+70h] [rbp+18h] BYREF

  RtlCaptureContext(pContextRecord);
  Rip = pContextRecord->Rip;
  for ( i = 0; i < 2; ++i )
  {
    v4 = RtlLookupFunctionEntry(Rip, &ImageBase, 0i64);
    if ( !v4 )
      break;
    RtlVirtualUnwind(0, ImageBase, Rip, v4, pContextRecord, &HandlerData, &EstablisherFrame, 0i64);
  }
}

// File Line: 323
// RVA: 0x12CD358
void __fastcall _crtCaptureCurrentContext(_CONTEXT *pContextRecord)
{
  unsigned __int64 Rip; // rdi
  _IMAGE_RUNTIME_FUNCTION_ENTRY *v3; // rax
  unsigned __int64 ImageBase; // [rsp+50h] [rbp+8h] BYREF
  unsigned __int64 EstablisherFrame; // [rsp+58h] [rbp+10h] BYREF
  PVOID HandlerData; // [rsp+60h] [rbp+18h] BYREF

  RtlCaptureContext(pContextRecord);
  Rip = pContextRecord->Rip;
  v3 = RtlLookupFunctionEntry(Rip, &ImageBase, 0i64);
  if ( v3 )
    RtlVirtualUnwind(0, ImageBase, Rip, v3, pContextRecord, &HandlerData, &EstablisherFrame, 0i64);
}

// File Line: 356
// RVA: 0x12CD43C
// attributes: thunk
DWORD __stdcall _crtFlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback)
{
  return FlsAlloc(lpCallback);
}

// File Line: 362
// RVA: 0x12CD444
// attributes: thunk
BOOL __stdcall _crtFlsFree(DWORD dwFlsIndex)
{
  return FlsFree(dwFlsIndex);
}

// File Line: 368
// RVA: 0x12CD44C
// attributes: thunk
PVOID __stdcall _crtFlsGetValue(DWORD dwFlsIndex)
{
  return FlsGetValue(dwFlsIndex);
}

// File Line: 375
// RVA: 0x12CD454
// attributes: thunk
BOOL __stdcall _crtFlsSetValue(DWORD dwFlsIndex, PVOID lpFlsData)
{
  return FlsSetValue(dwFlsIndex, lpFlsData);
}

