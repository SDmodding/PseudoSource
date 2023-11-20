// File Line: 133
// RVA: 0xEEC0D4
void OSuite::psock::platform::GetDefaultProxyServer()
{
  char *v0; // rax
  char *v1; // rbx
  OSuite::psock::proxy_t v2; // edi
  char *v3; // rax
  char *v4; // rax
  char *i; // rax
  char *v6; // rax
  char *v7; // rsi
  int v8; // er8
  unsigned __int64 v9; // rdx
  size_t v10; // rax
  DWORD pcbData; // [rsp+40h] [rbp-B8h]
  int pvData; // [rsp+44h] [rbp-B4h]
  DWORD pdwType; // [rsp+48h] [rbp-B0h]
  char str1; // [rsp+50h] [rbp-A8h]

  pcbData = 4;
  if ( !SHRegGetUSValueA_0(
          "Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings",
          "ProxyEnable",
          &pdwType,
          &pvData,
          &pcbData,
          0,
          0i64,
          0)
    && pvData == 1 )
  {
    pcbData = 256;
    if ( !SHRegGetUSValueA_0(
            "Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings",
            "ProxyServer",
            &pdwType,
            &str1,
            &pcbData,
            0,
            0i64,
            0) )
    {
      v0 = strstr(&str1, "socks=");
      if ( v0 )
      {
        v1 = v0 + 6;
        v2 = 2;
      }
      else
      {
        v3 = strstr(&str1, "https=");
        if ( v3 )
        {
          v1 = v3 + 6;
          v2 = 1;
        }
        else
        {
          v4 = strstr(&str1, "http=");
          v2 = 3;
          if ( v4 )
            v1 = v4 + 5;
          else
            v1 = &str1;
        }
      }
      for ( i = v1; *i != 59; ++i )
      {
        if ( !*i )
          break;
      }
      *i = 0;
      v6 = strchr(v1, 58);
      v7 = v6;
      if ( v6 )
      {
        v8 = atol(v6 + 1);
        v9 = v7 - v1;
      }
      else
      {
        v10 = strlen(v1);
        v8 = 80;
        v9 = v10;
      }
      OSuite::psock::SetProxyInfo(v1, v9, v8, v2);
      if ( v2 == 3 )
        OSuite::psock::ProbeHttpProxy();
    }
  }
}

// File Line: 217
// RVA: 0xEEC294
char __fastcall OSuite::psock::platform::InitializePlatform()
{
  HMODULE v0; // rax

  v0 = LoadLibraryA("iphlpapi.dll");
  g_hIphlpapi = v0;
  if ( v0 )
  {
    g_fpGetAdaptersInfo = (unsigned int (__fastcall *)(_IP_ADAPTER_INFO *, unsigned int *))GetProcAddress(
                                                                                             v0,
                                                                                             "GetAdaptersInfo");
    g_fpGetIpAddrTable = (unsigned int (__fastcall *)(_MIB_IPADDRTABLE *, unsigned int *, int))GetProcAddress(
                                                                                                 g_hIphlpapi,
                                                                                                 "GetIpAddrTable");
  }
  return 1;
}

// File Line: 239
// RVA: 0xEEC4C4
bool __fastcall OSuite::psock::platform::SetAsync(unsigned __int64 socket, bool async)
{
  u_long argp; // [rsp+20h] [rbp-18h]

  argp = async != 0;
  return ioctlsocket(socket, -2147195266, &argp) == 0;
}

