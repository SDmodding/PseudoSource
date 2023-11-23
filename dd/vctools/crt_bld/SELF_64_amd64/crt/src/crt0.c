// File Line: 154
// RVA: 0x12BA934
int __fastcall WinMainCRTStartup()
{
  _security_init_cookie();
  return _tmainCRTStartup();
}

// File Line: 171
// RVA: 0x12BA948
__int64 __fastcall _tmainCRTStartup()
{
  unsigned __int16 ShowWindowMode; // si
  int v1; // ebx
  int v2; // eax
  char *v3; // rax
  int v4; // eax
  unsigned int v5; // edi

  ShowWindowMode = _crtGetShowWindowMode();
  _set_app_type(2);
  if ( LOWORD(MEMORY[0x140000000].unused) == 23117
    && *(_DWORD *)(0x140000000i64 + MEMORY[0x14000003C]) == 17744
    && *(_WORD *)(0x140000018i64 + MEMORY[0x14000003C]) == 523 )
  {
    v1 = 0;
    if ( *(_DWORD *)(0x140000084i64 + MEMORY[0x14000003C]) > 0xEu )
      LOBYTE(v1) = *(_DWORD *)(0x1400000F8i64 + MEMORY[0x14000003C]) != 0;
  }
  else
  {
    v1 = 0;
  }
  if ( !heap_init() )
  {
    if ( _error_mode == 1 )
      FF_MSGBANNER();
    NMSG_WRITE(28);
    _crtExitProcess(0xFFu);
  }
  if ( !mtinit() )
  {
    if ( _error_mode == 1 )
      FF_MSGBANNER();
    NMSG_WRITE(16);
    _crtExitProcess(0xFFu);
  }
  RTC_Initialize();
  ioinit0();
  acmdln = GetCommandLineA();
  aenvptr = (char *)_crtGetEnvironmentStringsA();
  if ( setargv() < 0 )
    amsg_exit(8);
  if ( setenvp() < 0 )
    amsg_exit(9);
  v2 = cinit(1);
  if ( v2 )
    amsg_exit(v2);
  v3 = wincmdln();
  v4 = WinMain((HINSTANCE)0x140000000i64, 0i64, v3, ShowWindowMode);
  v5 = v4;
  if ( !v1 )
    exit(v4);
  cexit();
  return v5;
}

