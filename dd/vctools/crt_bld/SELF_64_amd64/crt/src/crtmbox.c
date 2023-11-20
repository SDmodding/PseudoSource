// File Line: 91
// RVA: 0x12D7AC8
__int64 __fastcall _crtMessageBoxW(const wchar_t *lpText, const wchar_t *lpCaption, unsigned int uType)
{
  const wchar_t *v3; // r15
  unsigned int v4; // ebp
  const wchar_t *v5; // r12
  __int64 v6; // rdi
  PVOID v7; // rsi
  int v8; // er14
  HMODULE v9; // rbx
  FARPROC v10; // rax
  FARPROC v11; // rax
  FARPROC v12; // rax
  FARPROC v13; // rax
  FARPROC v14; // rax
  __int64 (*v16)(void); // rbx
  unsigned int (__fastcall *v17)(__int64, signed __int64, char *); // rax
  unsigned int (__fastcall *v18)(__int64, signed __int64, char *); // r14
  __int64 v19; // rax
  __int64 (*v20)(void); // rax
  __int64 (__fastcall *v21)(__int64); // rax
  __int64 (__fastcall *v22)(__int64, const wchar_t *, const wchar_t *, _QWORD); // rax
  char v23; // [rsp+38h] [rbp-50h]
  char v24; // [rsp+40h] [rbp-48h]

  v3 = lpText;
  v4 = uType;
  v5 = lpCaption;
  v6 = 0i64;
  v7 = EncodePointer(0i64);
  v8 = _crtIsPackagedApp();
  if ( !pfnMessageBox )
  {
    v9 = LoadLibraryExW(L"USER32.DLL", 0i64, 0x800u);
    if ( !v9 )
    {
      if ( GetLastError() != 87 )
        return 0i64;
      v9 = LoadLibraryW(L"USER32.DLL");
      if ( !v9 )
        return 0i64;
    }
    v10 = GetProcAddress(v9, "MessageBoxW");
    if ( !v10 )
      return 0i64;
    pfnMessageBox = EncodePointer(v10);
    v11 = GetProcAddress(v9, "GetActiveWindow");
    pfnGetActiveWindow = EncodePointer(v11);
    v12 = GetProcAddress(v9, "GetLastActivePopup");
    pfnGetLastActivePopup = EncodePointer(v12);
    v13 = GetProcAddress(v9, "GetUserObjectInformationW");
    pfnGetUserObjectInformation = EncodePointer(v13);
    if ( pfnGetUserObjectInformation )
    {
      v14 = GetProcAddress(v9, "GetProcessWindowStation");
      pfnGetProcessWindowStation = EncodePointer(v14);
    }
  }
  if ( IsDebuggerPresent() )
  {
    if ( v3 )
      OutputDebugStringW(v3);
    if ( v8 )
      return 4i64;
  }
  else if ( v8 )
  {
    DecodePointer(pfnMessageBox);
    return 3i64;
  }
  if ( pfnGetProcessWindowStation == v7
    || pfnGetUserObjectInformation == v7
    || (v16 = (__int64 (*)(void))DecodePointer(pfnGetProcessWindowStation),
        v17 = (unsigned int (__fastcall *)(__int64, signed __int64, char *))DecodePointer(pfnGetUserObjectInformation),
        v18 = v17,
        !v16)
    || !v17
    || (v19 = v16()) != 0 && v18(v19, 1i64, &v23) && v24 & 1 )
  {
    if ( pfnGetActiveWindow != v7 )
    {
      v20 = (__int64 (*)(void))DecodePointer(pfnGetActiveWindow);
      if ( v20 )
      {
        v6 = v20();
        if ( v6 )
        {
          if ( pfnGetLastActivePopup != v7 )
          {
            v21 = (__int64 (__fastcall *)(__int64))DecodePointer(pfnGetLastActivePopup);
            if ( v21 )
              v6 = v21(v6);
          }
        }
      }
    }
  }
  else
  {
    v4 |= 0x200000u;
  }
  v22 = (__int64 (__fastcall *)(__int64, const wchar_t *, const wchar_t *, _QWORD))DecodePointer(pfnMessageBox);
  if ( v22 )
    return v22(v6, v3, v5, v4);
  return 0i64;
}

