// File Line: 40
// RVA: 0x93E110
void __fastcall Scaleform::Lock::Lock(Scaleform::Lock *this, unsigned int spinCount)
{
  HMODULE LibraryW; // rax
  int (__fastcall *ProcAddress)(_RTL_CRITICAL_SECTION *, unsigned int); // rax

  if ( initTried )
  {
    ProcAddress = pInitFn;
  }
  else
  {
    LibraryW = LoadLibraryW(L"kernel32.dll");
    ProcAddress = (int (__fastcall *)(_RTL_CRITICAL_SECTION *, unsigned int))GetProcAddress(
                                                                               LibraryW,
                                                                               "InitializeCriticalSectionAndSpinCount");
    initTried = 1;
    pInitFn = ProcAddress;
  }
  if ( ProcAddress )
    ProcAddress(&this->cs, spinCount);
  else
    InitializeCriticalSection(&this->cs);
}

// File Line: 72
// RVA: 0x94B200
// attributes: thunk
void __stdcall Scaleform::Lock::~Lock(LPCRITICAL_SECTION lpCriticalSection)
{
  DeleteCriticalSection(lpCriticalSection);
}

