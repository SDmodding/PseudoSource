// File Line: 128
// RVA: 0x12CD488
__int64 __fastcall _crtIsPackagedApp()
{
  unsigned int v0; // ebx
  bool v1; // zf
  bool v2; // sf
  HMODULE v3; // rax
  FARPROC v4; // rax
  signed int v5; // eax
  int v7; // [rsp+30h] [rbp+8h]

  v0 = 0;
  v1 = isPackaged == 0;
  v2 = isPackaged < 0;
  if ( isPackaged < 0 )
  {
    v7 = 0;
    v3 = GetModuleHandleW(L"kernel32.dll");
    v4 = GetProcAddress(v3, "GetCurrentPackageId");
    if ( !v4 || (v1 = ((unsigned int (__fastcall *)(int *, _QWORD))v4)(&v7, 0i64) == 122, v5 = 1, !v1) )
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
signed __int64 __fastcall _crtGetShowWindowMode()
{
  signed __int64 result; // rax
  _STARTUPINFOW StartupInfo; // [rsp+20h] [rbp-78h]

  GetStartupInfoW(&StartupInfo);
  result = 10i64;
  if ( StartupInfo.dwFlags & 1 )
    result = StartupInfo.wShowWindow;
  return result;
}

// File Line: 191
// RVA: 0x12CD4E8
LPTOP_LEVEL_EXCEPTION_FILTER __stdcall _crtSetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter)
{
  return SetUnhandledExceptionFilter(lpTopLevelExceptionFilter);
}

// File Line: 217
// RVA: 0x12CD4F0
void __fastcall _crtTerminateProcess(unsigned int uExitCode)
{
  unsigned int v1; // ebx
  HANDLE v2; // rax

  v1 = uExitCode;
  v2 = GetCurrentProcess();
  TerminateProcess(v2, v1);
}

// File Line: 249
// RVA: 0x12CD510
LONG __fastcall _crtUnhandledException(_EXCEPTION_POINTERS *exceptionInfo)
{
  _EXCEPTION_POINTERS *v1; // rbx

  v1 = exceptionInfo;
  SetUnhandledExceptionFilter(0i64);
  return UnhandledExceptionFilter(v1);
}

// File Line: 275
// RVA: 0x12CD3C8
void __fastcall _crtCapturePreviousContext(_CONTEXT *pContextRecord)
{
  _CONTEXT *ContextRecord; // rbx
  DWORD64 v2; // rsi
  signed int v3; // edi
  _IMAGE_RUNTIME_FUNCTION_ENTRY *v4; // rax
  unsigned __int64 ImageBase; // [rsp+60h] [rbp+8h]
  unsigned __int64 EstablisherFrame; // [rsp+68h] [rbp+10h]
  PVOID HandlerData; // [rsp+70h] [rbp+18h]

  ContextRecord = pContextRecord;
  RtlCaptureContext(pContextRecord);
  v2 = ContextRecord->Rip;
  v3 = 0;
  do
  {
    v4 = RtlLookupFunctionEntry(v2, &ImageBase, 0i64);
    if ( !v4 )
      break;
    RtlVirtualUnwind(0, ImageBase, v2, v4, ContextRecord, &HandlerData, &EstablisherFrame, 0i64);
    ++v3;
  }
  while ( v3 < 2 );
}

// File Line: 323
// RVA: 0x12CD358
void __fastcall _crtCaptureCurrentContext(_CONTEXT *pContextRecord)
{
  _CONTEXT *ContextRecord; // rbx
  DWORD64 v2; // rdi
  _IMAGE_RUNTIME_FUNCTION_ENTRY *v3; // rax
  unsigned __int64 ImageBase; // [rsp+50h] [rbp+8h]
  unsigned __int64 EstablisherFrame; // [rsp+58h] [rbp+10h]
  PVOID HandlerData; // [rsp+60h] [rbp+18h]

  ContextRecord = pContextRecord;
  RtlCaptureContext(pContextRecord);
  v2 = ContextRecord->Rip;
  v3 = RtlLookupFunctionEntry(ContextRecord->Rip, &ImageBase, 0i64);
  if ( v3 )
    RtlVirtualUnwind(0, ImageBase, v2, v3, ContextRecord, &HandlerData, &EstablisherFrame, 0i64);
}

// File Line: 356
// RVA: 0x12CD43C
DWORD __stdcall _crtFlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback)
{
  return FlsAlloc(lpCallback);
}

// File Line: 362
// RVA: 0x12CD444
BOOL __stdcall _crtFlsFree(DWORD dwFlsIndex)
{
  return FlsFree(dwFlsIndex);
}

// File Line: 368
// RVA: 0x12CD44C
PVOID __stdcall _crtFlsGetValue(DWORD dwFlsIndex)
{
  return FlsGetValue(dwFlsIndex);
}

// File Line: 375
// RVA: 0x12CD454
BOOL __stdcall _crtFlsSetValue(DWORD dwFlsIndex, PVOID lpFlsData)
{
  return FlsSetValue(dwFlsIndex, lpFlsData);
}

