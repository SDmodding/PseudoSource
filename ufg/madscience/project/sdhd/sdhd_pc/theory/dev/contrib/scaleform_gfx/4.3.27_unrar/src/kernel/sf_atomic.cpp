// File Line: 40
// RVA: 0x93E110
void __fastcall Scaleform::Lock::Lock(Scaleform::Lock *this, unsigned int spinCount)
{
  unsigned int v2; // edi
  Scaleform::Lock *v3; // rbx
  HMODULE v4; // rax
  int (__fastcall *v5)(_RTL_CRITICAL_SECTION *, unsigned int); // rax

  v2 = spinCount;
  v3 = this;
  if ( initTried )
  {
    v5 = pInitFn;
  }
  else
  {
    v4 = LoadLibraryW(L"kernel32.dll");
    v5 = (int (__fastcall *)(_RTL_CRITICAL_SECTION *, unsigned int))GetProcAddress(
                                                                      v4,
                                                                      "InitializeCriticalSectionAndSpinCount");
    initTried = 1;
    pInitFn = v5;
  }
  if ( v5 )
    v5(&v3->cs, v2);
  else
    InitializeCriticalSection(&v3->cs);
}

// File Line: 72
// RVA: 0x94B200
void __stdcall Scaleform::Lock::~Lock(LPCRITICAL_SECTION lpCriticalSection)
{
  DeleteCriticalSection(lpCriticalSection);
}

