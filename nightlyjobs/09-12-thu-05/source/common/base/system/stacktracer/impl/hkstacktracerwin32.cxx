// File Line: 90
// RVA: 0xC7CEF0
void __fastcall hkStackTracerImpl::ensureInitialized(hkStackTracerImpl *this)
{
  hkStackTracerImpl *v1; // rbx
  HMODULE v2; // rax
  HMODULE v3; // rax
  FARPROC v4; // rax
  HMODULE v5; // rcx
  FARPROC v6; // rax
  FARPROC v7; // rax
  HMODULE v8; // rcx
  FARPROC v9; // rax
  HMODULE v10; // rcx
  FARPROC v11; // rax
  HMODULE v12; // rcx
  FARPROC v13; // rax
  HMODULE v14; // rcx
  FARPROC v15; // rax
  HMODULE v16; // rcx
  FARPROC v17; // rax
  HMODULE v18; // rcx
  FARPROC v19; // rax
  HMODULE v20; // rcx
  FARPROC v21; // rax
  HMODULE v22; // rcx
  FARPROC v23; // rax
  bool v24; // zf
  unsigned int v25; // eax
  HANDLE v26; // rax

  v1 = this;
  if ( !this->m_initialized )
  {
    EnterCriticalSection(&this->m_lock);
    if ( !v1->m_initialized )
    {
      v2 = LoadLibraryA(hkStackTracerDbghelpPath);
      v1->hDbgHelpDll = v2;
      if ( !v2 )
        OutputDebugStringA("Havok StackTracer: hkStackTracer: Unable to load dbghelp.dll\r\n");
      if ( v1->hDbgHelpDll )
      {
        v3 = LoadLibraryA("kernel32.dll");
        v1->hKernel32Dll = v3;
        if ( !v3 )
          OutputDebugStringA("Havok StackTracer: hkStackTracer: Unable to load kernel32.dll\r\n");
        v4 = GetProcAddress(v1->hDbgHelpDll, "SymInitialize");
        v5 = v1->hDbgHelpDll;
        v1->pSymInitialize = (int (__fastcall *)(void *, char *, int))v4;
        v6 = GetProcAddress(v5, "SymRefreshModuleList");
        v1->pSymRefreshModuleList = (int (__fastcall *)(void *))v6;
        if ( !v6 )
          OutputDebugStringA(
            "Havok StackTracer: Could not load symbol SymRefreshModuleList from dbghelp.dll, version too old, but will co"
            "ntinue without it.\r\n");
        v7 = GetProcAddress(v1->hDbgHelpDll, "SymGetOptions");
        v8 = v1->hDbgHelpDll;
        v1->pSymGetOptions = (unsigned int (__fastcall *)())v7;
        v9 = GetProcAddress(v8, "SymSetOptions");
        v10 = v1->hDbgHelpDll;
        v1->pSymSetOptions = (unsigned int (__fastcall *)(unsigned int))v9;
        v11 = GetProcAddress(v10, "SymFromAddr");
        v12 = v1->hDbgHelpDll;
        v1->pSymFromAddr = (int (__fastcall *)(void *, unsigned __int64, unsigned __int64 *, _SYMBOL_INFO *))v11;
        v13 = GetProcAddress(v12, "StackWalk64");
        v14 = v1->hDbgHelpDll;
        v1->pStackWalk64 = (int (__fastcall *)(unsigned int, void *, void *, _tagSTACKFRAME64 *, void *, int (__fastcall *)(void *, unsigned __int64, void *, unsigned int, unsigned int *), void *(__fastcall *)(void *, unsigned __int64), unsigned __int64 (__fastcall *)(void *, unsigned __int64), unsigned __int64 (__fastcall *)(void *, void *, _tagADDRESS64 *)))v13;
        v15 = GetProcAddress(v14, "SymFunctionTableAccess64");
        v16 = v1->hDbgHelpDll;
        v1->pSymFunctionTableAccess64 = (void *(__fastcall *)(void *, unsigned __int64))v15;
        v17 = GetProcAddress(v16, "SymGetModuleBase64");
        v18 = v1->hDbgHelpDll;
        v1->pSymGetModuleBase64 = (unsigned __int64 (__fastcall *)(void *, unsigned __int64))v17;
        v19 = GetProcAddress(v18, "SymGetLineFromAddr64");
        v20 = v1->hKernel32Dll;
        v1->pSymGetLineFromAddr64 = (int (__fastcall *)(void *, unsigned __int64, unsigned __int64 *, _IMAGEHLP_LINE64 *))v19;
        v21 = GetProcAddress(v20, "RtlCaptureContext");
        v22 = v1->hKernel32Dll;
        v1->pRtlCaptureContext = (void (__fastcall *)(_CONTEXT *))v21;
        v23 = GetProcAddress(v22, "RtlCaptureStackBackTrace");
        v24 = v1->m_needsSymInitialize == 0;
        v1->pRtlCaptureStackBackTrace = (unsigned __int16 (__fastcall *)(unsigned int, unsigned int, void **, unsigned int *))v23;
        if ( !v24 )
        {
          v25 = v1->pSymGetOptions();
          v1->pSymSetOptions(v25 | 0x80000014);
          v26 = GetCurrentProcess();
          v1->pSymInitialize(v26, 0i64, 1);
        }
        v1->m_initialized = 1;
      }
    }
    LeaveCriticalSection(&v1->m_lock);
  }
}

// File Line: 166
// RVA: 0x15C76D0
__int64 dynamic_initializer_for___stackTracerWin32DataBuf__()
{
  InitializeCriticalSection(&stackTracerWin32DataBuf.m_lock);
  stackTracerWin32DataBuf.m_lockInitialized = 1;
  return atexit(dynamic_atexit_destructor_for___stackTracerWin32DataBuf__);
}

// File Line: 173
// RVA: 0xC7C9B0
void __fastcall hkStackTracer::hkStackTracer(hkStackTracer *this)
{
  this->vfptr = (hkStackTracerVtbl *)&hkStackTracer::`vftable';
}

// File Line: 177
// RVA: 0xC7C9D0
void __fastcall hkStackTracer::~hkStackTracer(hkStackTracer *this)
{
  this->vfptr = (hkStackTracerVtbl *)&hkStackTracer::`vftable';
}

// File Line: 181
// RVA: 0xC7C9F0
void __fastcall hkStackTracer::dumpStackTrace(hkStackTracer *this, const unsigned __int64 *trace, int maxtrace, void (__fastcall *pfunc)(const char *, void *), void *context)
{
  void (__fastcall *v5)(const char *, void *); // r13
  __int64 v6; // rbx
  const unsigned __int64 *v7; // r14
  __int64 v8; // rdi
  __int64 v9; // r15
  HANDLE v10; // rsi
  unsigned __int64 v11; // rbx
  unsigned __int64 v12; // rdx
  __int64 v13; // [rsp+20h] [rbp-E0h]
  __int64 v14; // [rsp+30h] [rbp-D0h]
  __int64 v15; // [rsp+38h] [rbp-C8h]
  __int64 v16; // [rsp+40h] [rbp-C0h]
  __int64 v17; // [rsp+48h] [rbp-B8h]
  __int128 v18; // [rsp+50h] [rbp-B0h]
  int v19; // [rsp+60h] [rbp-A0h]
  int v20; // [rsp+B0h] [rbp-50h]
  int v21; // [rsp+B4h] [rbp-4Ch]
  char string; // [rsp+890h] [rbp+790h]

  v5 = pfunc;
  v6 = maxtrace;
  v7 = trace;
  hkStackTracerImpl::ensureInitialized(s_impl);
  v19 = 88;
  v20 = 2001;
  v8 = 0i64;
  v9 = v6;
  v10 = GetCurrentProcess();
  if ( (signed int)v6 > 0 )
  {
    do
    {
      v11 = v7[v8];
      v12 = v7[v8];
      v14 = 0i64;
      if ( !s_impl->pSymFromAddr(v10, v12, (unsigned __int64 *)&v14, (_SYMBOL_INFO *)&v19) )
      {
        if ( !haveWarned )
        {
          OutputDebugStringA(
            "**************************************************************\n"
            "* Cannot find symbol for an address\n"
            "* Either debug information was not found or your version of\n"
            "* dbghelp.dll may be too old to understand the debug format.\n"
            "* For more information, see comments in hkStackTracerWin32.cxx\n"
            "* Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Common/Base/System/StackTracer/Impl/hkStackTracerWin32.cxx\n"
            "**************************************************************");
          haveWarned = 1;
        }
        strcpy((char *)&v21, "(unknown - see comments in hkStackTracerWin32.cxx)");
      }
      v15 = 0i64;
      v16 = 0i64;
      v17 = 0i64;
      v18 = 0ui64;
      LODWORD(v15) = 40;
      s_impl->pSymGetLineFromAddr64(v10, v11, (unsigned __int64 *)&v14, (_IMAGEHLP_LINE64 *)&v15);
      LODWORD(v13) = v17;
      snprintf(&string, 0x800ui64, "%s(%i):'%s'\n", (_QWORD)v18, v13, &v21);
      v5(&string, context);
      ++v8;
    }
    while ( v8 < v9 );
  }
}

// File Line: 238
// RVA: 0xC7CBE0
__int64 __fastcall hkStackTracer::getStackTrace(hkStackTracer *this, unsigned __int64 *trace, int maxtrace, int framesToSkip)
{
  unsigned int v4; // ebx
  unsigned int v5; // edi
  unsigned __int64 *v6; // rsi
  unsigned __int16 (__fastcall *v7)(unsigned int, unsigned int, void **, unsigned int *); // r10
  __int64 result; // rax

  v4 = framesToSkip;
  v5 = maxtrace;
  v6 = trace;
  hkStackTracerImpl::ensureInitialized(s_impl);
  v7 = s_impl->pRtlCaptureStackBackTrace;
  if ( v7 )
    result = v7(v4, v5, (void **)v6, 0i64);
  else
    result = 0i64;
  return result;
}

// File Line: 254
// RVA: 0xC7CC50
void __fastcall hkStackTracer::refreshSymbols(hkStackTracer *this)
{
  hkStackTracerImpl *v1; // rbx
  HANDLE v2; // rax

  hkStackTracerImpl::ensureInitialized(s_impl);
  v1 = s_impl;
  if ( s_impl->pSymRefreshModuleList )
  {
    v2 = GetCurrentProcess();
    v1->pSymRefreshModuleList(v2);
  }
}

// File Line: 264
// RVA: 0xC7CCA0
void __fastcall hkStackTracer::getModuleInfo(hkStackTracer *this, void (__fastcall *pfunc)(const char *, void *), void *context)
{
  void *v3; // rbx
  void (__fastcall *v4)(const char *, void *); // rdi
  char Filename; // [rsp+20h] [rbp-808h]
  char buf; // [rsp+420h] [rbp-408h]

  v3 = context;
  v4 = pfunc;
  hkStackTracerImpl::ensureInitialized(s_impl);
  if ( GetModuleFileNameA(0i64, &Filename, 0x400u) )
  {
    hkString::snprintf(&buf, 1024, "Win32 \"%s\"", &Filename);
    v4(&buf, v3);
  }
}

// File Line: 278
// RVA: 0xC7CD20
hkStackTracerImpl *__fastcall hkStackTracer::getImplementation()
{
  return s_impl;
}

// File Line: 283
// RVA: 0xC7CD30
void __fastcall hkStackTracer::replaceImplementation(void *newImpl)
{
  s_impl = (hkStackTracerImpl *)newImpl;
}

// File Line: 294
// RVA: 0xC7CD40
void __fastcall hkStackTracer::setNeedsSymInitialize(bool enabled)
{
  s_impl->m_needsSymInitialize = enabled;
}

