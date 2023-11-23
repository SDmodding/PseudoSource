// File Line: 143
// RVA: 0x12C52D0
void FF_MSGBANNER()
{
  if ( set_error_mode(3) == 1 || !set_error_mode(3) && _app_type == 1 )
  {
    NMSG_WRITE(252);
    NMSG_WRITE(255);
  }
}

// File Line: 174
// RVA: 0x12C5314
const wchar_t *__fastcall GET_RTERRMSG(int rterrnum)
{
  int v1; // edx
  rterrmsgs *i; // r8

  v1 = 0;
  for ( i = rterrs; rterrnum != i->rterrno; ++i )
  {
    if ( (unsigned __int64)++v1 >= 0x17 )
      return 0i64;
  }
  return rterrs[v1].rterrtxt;
}

// File Line: 205
// RVA: 0x12C5344
void __fastcall NMSG_WRITE(int rterrnum)
{
  const wchar_t *v2; // rbx
  unsigned __int64 v3; // rax
  char *StdHandle; // rdi
  int v5; // r8d
  char *v6; // rdx
  DWORD v7; // eax
  unsigned int NumberOfBytesWritten; // [rsp+30h] [rbp-238h] BYREF
  char Str[512]; // [rsp+40h] [rbp-228h] BYREF

  v2 = GET_RTERRMSG(rterrnum);
  if ( v2 )
  {
    if ( set_error_mode(3) == 1 || !set_error_mode(3) && _app_type == 1 )
    {
      StdHandle = (char *)GetStdHandle(0xFFFFFFF4);
      if ( (unsigned __int64)(StdHandle - 1) <= 0xFFFFFFFFFFFFFFFDui64 )
      {
        v5 = 0;
        v6 = Str;
        do
        {
          *v6 = *(_BYTE *)v2;
          if ( !*v2 )
            break;
          ++v5;
          ++v6;
          ++v2;
        }
        while ( (unsigned __int64)v5 < 0x1F4 );
        Str[499] = 0;
        v7 = strlen(Str);
        WriteFile(StdHandle, Str, v7, &NumberOfBytesWritten, 0i64);
      }
    }
    else if ( rterrnum != 252 )
    {
      if ( (unsigned int)wcscpy_s((char *)outmsg, 0x314ui64, L"Runtime Error!\n\nProgram: ") )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        JUMPOUT(0x1412C55B2i64);
      }
      outmsg[285] = 0;
      if ( !GetModuleFileNameW(0i64, &outmsg[25], 0x104u)
        && (unsigned int)wcscpy_s((char *)&outmsg[25], 0x2FBui64, L"<program name unknown>") )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
      }
      if ( wcslen(&outmsg[25]) + 1 > 0x3C )
      {
        v3 = wcslen(&outmsg[25]);
        if ( (unsigned int)wcsncpy_s((char *)&outmsg[v3 - 34], 763 - (&outmsg[v3 - 34] - &outmsg[25]), L"...", 3ui64) )
        {
          invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
          __debugbreak();
        }
      }
      if ( (unsigned int)wcscat_s((char *)outmsg, 0x314ui64, L"\n\n") )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
      }
      if ( (unsigned int)wcscat_s((char *)outmsg, 0x314ui64, v2) )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
      }
      _crtMessageBoxW(outmsg, L"Microsoft Visual C++ Runtime Library", 0x12010u);
    }
  }
}

