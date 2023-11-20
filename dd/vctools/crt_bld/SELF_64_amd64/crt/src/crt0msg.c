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
  rterrmsgs *v2; // r8

  v1 = 0;
  v2 = rterrs;
  while ( rterrnum != v2->rterrno )
  {
    ++v1;
    ++v2;
    if ( (unsigned __int64)v1 >= 0x17 )
      return 0i64;
  }
  return rterrs[v1].rterrtxt;
}

// File Line: 205
// RVA: 0x12C5344
void __fastcall NMSG_WRITE(int rterrnum)
{
  int v1; // edi
  const wchar_t *v2; // rbx
  int v3; // eax
  const wchar_t *v4; // rcx
  unsigned __int64 v5; // rax
  char *v6; // rdi
  int v7; // er8
  char *v8; // rdx
  DWORD v9; // eax
  unsigned int NumberOfBytesWritten; // [rsp+30h] [rbp-238h]
  char Str; // [rsp+40h] [rbp-228h]
  char v12; // [rsp+233h] [rbp-35h]

  v1 = rterrnum;
  v2 = GET_RTERRMSG(rterrnum);
  if ( v2 )
  {
    if ( set_error_mode(3) != 1 && (set_error_mode(3) || _app_type != 1) )
    {
      if ( v1 == 252 )
        return;
      v3 = wcscpy_s(outmsg, 0x314ui64, L"Runtime Error!\n\nProgram: ");
      v4 = 0i64;
      if ( v3 )
      {
LABEL_24:
        invoke_watson(v4, 0i64, 0i64, 0, 0i64);
        JUMPOUT(*(_QWORD *)&byte_1412C55B2);
      }
      outmsg[285] = 0;
      if ( !GetModuleFileNameW(0i64, &outmsg[25], 0x104u)
        && (unsigned int)wcscpy_s(&outmsg[25], 0x2FBui64, L"<program name unknown>") )
      {
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
      }
      else if ( wcslen(&outmsg[25]) + 1 <= 0x3C
             || (v5 = wcslen(&outmsg[25]),
                 !(unsigned int)wcsncpy_s(&outmsg[v5 - 34], 763 - (&outmsg[v5 - 34] - &outmsg[25]), L"...", 3ui64)) )
      {
        if ( (unsigned int)wcscat_s(outmsg, 0x314ui64, L"\n\n") )
        {
LABEL_23:
          invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
          __debugbreak();
          goto LABEL_24;
        }
        if ( !(unsigned int)wcscat_s(outmsg, 0x314ui64, v2) )
        {
          _crtMessageBoxW(outmsg, L"Microsoft Visual C++ Runtime Library", 0x12010u);
          return;
        }
LABEL_22:
        invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
        __debugbreak();
        goto LABEL_23;
      }
      invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
      __debugbreak();
      goto LABEL_22;
    }
    v6 = (char *)GetStdHandle(0xFFFFFFF4);
    if ( (unsigned __int64)(v6 - 1) <= 0xFFFFFFFFFFFFFFFDui64 )
    {
      v7 = 0;
      v8 = &Str;
      do
      {
        *v8 = *(_BYTE *)v2;
        if ( !*v2 )
          break;
        ++v7;
        ++v8;
        ++v2;
      }
      while ( (unsigned __int64)v7 < 0x1F4 );
      v12 = 0;
      v9 = strlen(&Str);
      WriteFile(v6, &Str, v9, &NumberOfBytesWritten, 0i64);
    }
  }
}

