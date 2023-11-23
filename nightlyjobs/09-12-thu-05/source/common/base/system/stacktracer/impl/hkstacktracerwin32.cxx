// File Line: 90
// RVA: 0xC7CEF0
void __fastcall hkStackTracerImpl::ensureInitialized(hkStackTracerImpl *this)
{
  HINSTANCE__ *LibraryA; // rax
  HINSTANCE__ *v3; // rax
  int (__fastcall *ProcAddress)(void *, char *, int); // rax
  HINSTANCE__ *hDbgHelpDll; // rcx
  int (__fastcall *v6)(void *); // rax
  unsigned int (__fastcall *v7)(); // rax
  HINSTANCE__ *v8; // rcx
  unsigned int (__fastcall *v9)(unsigned int); // rax
  HINSTANCE__ *v10; // rcx
  int (__fastcall *v11)(void *, unsigned __int64, unsigned __int64 *, _SYMBOL_INFO *); // rax
  HINSTANCE__ *v12; // rcx
  int (__fastcall *v13)(unsigned int, void *, void *, _tagSTACKFRAME64 *, void *, int (__fastcall *)(void *, unsigned __int64, void *, unsigned int, unsigned int *), void *(__fastcall *)(void *, unsigned __int64), unsigned __int64 (__fastcall *)(void *, unsigned __int64), unsigned __int64 (__fastcall *)(void *, void *, _tagADDRESS64 *)); // rax
  HINSTANCE__ *v14; // rcx
  void *(__fastcall *v15)(void *, unsigned __int64); // rax
  HINSTANCE__ *v16; // rcx
  unsigned __int64 (__fastcall *v17)(void *, unsigned __int64); // rax
  HINSTANCE__ *v18; // rcx
  int (__fastcall *v19)(void *, unsigned __int64, unsigned __int64 *, _IMAGEHLP_LINE64 *); // rax
  HINSTANCE__ *hKernel32Dll; // rcx
  void (__fastcall *v21)(_CONTEXT *); // rax
  HINSTANCE__ *v22; // rcx
  unsigned __int16 (__fastcall *v23)(unsigned int, unsigned int, void **, unsigned int *); // rax
  bool v24; // zf
  unsigned int v25; // eax
  HANDLE CurrentProcess; // rax

  if ( !this->m_initialized )
  {
    EnterCriticalSection(&this->m_lock);
    if ( !this->m_initialized )
    {
      LibraryA = LoadLibraryA(hkStackTracerDbghelpPath);
      this->hDbgHelpDll = LibraryA;
      if ( !LibraryA )
        OutputDebugStringA("Havok StackTracer: hkStackTracer: Unable to load dbghelp.dll\r\n");
      if ( this->hDbgHelpDll )
      {
        v3 = LoadLibraryA("kernel32.dll");
        this->hKernel32Dll = v3;
        if ( !v3 )
          OutputDebugStringA("Havok StackTracer: hkStackTracer: Unable to load kernel32.dll\r\n");
        ProcAddress = (int (__fastcall *)(void *, char *, int))GetProcAddress(this->hDbgHelpDll, "SymInitialize");
        hDbgHelpDll = this->hDbgHelpDll;
        this->pSymInitialize = ProcAddress;
        v6 = (int (__fastcall *)(void *))GetProcAddress(hDbgHelpDll, "SymRefreshModuleList");
        this->pSymRefreshModuleList = v6;
        if ( !v6 )
          OutputDebugStringA(
            "Havok StackTracer: Could not load symbol SymRefreshModuleList from dbghelp.dll, version too old, but will co"
            "ntinue without it.\r\n");
        v7 = (unsigned int (__fastcall *)())GetProcAddress(this->hDbgHelpDll, "SymGetOptions");
        v8 = this->hDbgHelpDll;
        this->pSymGetOptions = v7;
        v9 = (unsigned int (__fastcall *)(unsigned int))GetProcAddress(v8, "SymSetOptions");
        v10 = this->hDbgHelpDll;
        this->pSymSetOptions = v9;
        v11 = (int (__fastcall *)(void *, unsigned __int64, unsigned __int64 *, _SYMBOL_INFO *))GetProcAddress(
                                                                                                  v10,
                                                                                                  "SymFromAddr");
        v12 = this->hDbgHelpDll;
        this->pSymFromAddr = v11;
        v13 = (int (__fastcall *)(unsigned int, void *, void *, _tagSTACKFRAME64 *, void *, int (__fastcall *)(void *, unsigned __int64, void *, unsigned int, unsigned int *), void *(__fastcall *)(void *, unsigned __int64), unsigned __int64 (__fastcall *)(void *, unsigned __int64), unsigned __int64 (__fastcall *)(void *, void *, _tagADDRESS64 *)))GetProcAddress(v12, "StackWalk64");
        v14 = this->hDbgHelpDll;
        this->pStackWalk64 = v13;
        v15 = (void *(__fastcall *)(void *, unsigned __int64))GetProcAddress(v14, "SymFunctionTableAccess64");
        v16 = this->hDbgHelpDll;
        this->pSymFunctionTableAccess64 = v15;
        v17 = (unsigned __int64 (__fastcall *)(void *, unsigned __int64))GetProcAddress(v16, "SymGetModuleBase64");
        v18 = this->hDbgHelpDll;
        this->pSymGetModuleBase64 = v17;
        v19 = (int (__fastcall *)(void *, unsigned __int64, unsigned __int64 *, _IMAGEHLP_LINE64 *))GetProcAddress(v18, "SymGetLineFromAddr64");
        hKernel32Dll = this->hKernel32Dll;
        this->pSymGetLineFromAddr64 = v19;
        v21 = (void (__fastcall *)(_CONTEXT *))GetProcAddress(hKernel32Dll, "RtlCaptureContext");
        v22 = this->hKernel32Dll;
        this->pRtlCaptureContext = v21;
        v23 = (unsigned __int16 (__fastcall *)(unsigned int, unsigned int, void **, unsigned int *))GetProcAddress(v22, "RtlCaptureStackBackTrace");
        v24 = !this->m_needsSymInitialize;
        this->pRtlCaptureStackBackTrace = v23;
        if ( !v24 )
        {
          v25 = this->pSymGetOptions();
          this->pSymSetOptions(v25 | 0x80000014);
          CurrentProcess = GetCurrentProcess();
          this->pSymInitialize(CurrentProcess, 0i64, 1);
        }
        this->m_initialized = 1;
      }
    }
    LeaveCriticalSection(&this->m_lock);
  }
}

// File Line: 166
// RVA: 0x15C76D0
__int64 dynamic_initializer_for___stackTracerWin32DataBuf__()
{
  InitializeCriticalSection(&stackTracerWin32DataBuf.m_lock);
  stackTracerWin32DataBuf.m_lockInitialized = 1;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for___stackTracerWin32DataBuf__);
}

// File Line: 173
// RVA: 0xC7C9B0
void __fastcall hkStackTracer::hkStackTracer(hkStackTracer *this)
{
  this->vfptr = (hkStackTracerVtbl *)&hkStackTracer::`vftable;
}

// File Line: 177
// RVA: 0xC7C9D0
void __fastcall hkStackTracer::~hkStackTracer(hkStackTracer *this)
{
  this->vfptr = (hkStackTracerVtbl *)&hkStackTracer::`vftable;
}

// File Line: 181
// RVA: 0xC7C9F0
void __fastcall hkStackTracer::dumpStackTrace(
        hkStackTracer *this,
        const unsigned __int64 *trace,
        int maxtrace,
        void (__fastcall *pfunc)(const char *, void *),
        void *context)
{
  __int64 v6; // rbx
  __int64 v8; // rdi
  __int64 v9; // r15
  HANDLE CurrentProcess; // rsi
  unsigned __int64 v11; // rbx
  __int64 v12; // [rsp+20h] [rbp-E0h]
  __int64 v13; // [rsp+30h] [rbp-D0h] BYREF
  __int64 v14[2]; // [rsp+38h] [rbp-C8h] BYREF
  __int64 v15; // [rsp+48h] [rbp-B8h]
  const char *v16; // [rsp+50h] [rbp-B0h]
  __int64 v17; // [rsp+58h] [rbp-A8h]
  int v18[21]; // [rsp+60h] [rbp-A0h] BYREF
  char v19[2012]; // [rsp+B4h] [rbp-4Ch] BYREF
  char string[2048]; // [rsp+890h] [rbp+790h] BYREF

  v6 = maxtrace;
  hkStackTracerImpl::ensureInitialized(s_impl);
  v18[0] = 88;
  v18[20] = 2001;
  v8 = 0i64;
  v9 = v6;
  CurrentProcess = GetCurrentProcess();
  if ( (int)v6 > 0 )
  {
    do
    {
      v11 = trace[v8];
      v13 = 0i64;
      if ( !s_impl->pSymFromAddr(CurrentProcess, v11, (unsigned __int64 *)&v13, (_SYMBOL_INFO *)v18) )
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
        strcpy(v19, "(unknown - see comments in hkStackTracerWin32.cxx)");
      }
      v14[1] = 0i64;
      v15 = 0i64;
      v16 = 0i64;
      v17 = 0i64;
      v14[0] = 40i64;
      s_impl->pSymGetLineFromAddr64(CurrentProcess, v11, (unsigned __int64 *)&v13, (_IMAGEHLP_LINE64 *)v14);
      LODWORD(v12) = v15;
      snprintf(string, 0x800ui64, "%s(%i):%s\n", v16, v12, v19);
      pfunc(string, context);
      ++v8;
    }
    while ( v8 < v9 );
  }
}

// File Line: 238
// RVA: 0xC7CBE0
__int64 __fastcall hkStackTracer::getStackTrace(
        hkStackTracer *this,
        void **trace,
        unsigned int maxtrace,
        unsigned int framesToSkip)
{
  unsigned __int16 (__fastcall *pRtlCaptureStackBackTrace)(unsigned int, unsigned int, void **, unsigned int *); // r10

  hkStackTracerImpl::ensureInitialized(s_impl);
  pRtlCaptureStackBackTrace = s_impl->pRtlCaptureStackBackTrace;
  if ( pRtlCaptureStackBackTrace )
    return pRtlCaptureStackBackTrace(framesToSkip, maxtrace, trace, 0i64);
  else
    return 0i64;
}

// File Line: 254
// RVA: 0xC7CC50
void __fastcall hkStackTracer::refreshSymbols(hkStackTracer *this)
{
  hkStackTracerImpl *v1; // rbx
  HANDLE CurrentProcess; // rax

  hkStackTracerImpl::ensureInitialized(s_impl);
  v1 = s_impl;
  if ( s_impl->pSymRefreshModuleList )
  {
    CurrentProcess = GetCurrentProcess();
    v1->pSymRefreshModuleList(CurrentProcess);
  }
}

// File Line: 264
// RVA: 0xC7CCA0
void __fastcall hkStackTracer::getModuleInfo(
        hkStackTracer *this,
        void (__fastcall *pfunc)(const char *, void *),
        void *context)
{
  char Filename[1024]; // [rsp+20h] [rbp-808h] BYREF
  char buf[1032]; // [rsp+420h] [rbp-408h] BYREF

  hkStackTracerImpl::ensureInitialized(s_impl);
  if ( GetModuleFileNameA(0i64, Filename, 0x400u) )
  {
    hkString::snprintf(buf, 1024, "Win32 \"%s\"", Filename);
    pfunc(buf, context);
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
void __fastcall hkStackTracer::replaceImplementation(hkStackTracerImpl *newImpl)
{
  s_impl = newImpl;
}

// File Line: 294
// RVA: 0xC7CD40
void __fastcall hkStackTracer::setNeedsSymInitialize(bool enabled)
{
  s_impl->m_needsSymInitialize = enabled;
}

