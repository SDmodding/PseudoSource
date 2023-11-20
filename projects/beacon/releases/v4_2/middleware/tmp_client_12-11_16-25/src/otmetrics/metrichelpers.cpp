// File Line: 39
// RVA: 0xEC3380
const char *__fastcall OSuitePrivate::GetPlatform()
{
  return "Steam";
}

// File Line: 71
// RVA: 0xEC3508
const char *__fastcall OSuitePrivate::Target()
{
  return "Release";
}

// File Line: 83
// RVA: 0xEC34AC
char *__fastcall OSuitePrivate::MachineId()
{
  unsigned int nSize; // [rsp+20h] [rbp-18h]

  strcpy(szMachineName, "Windows");
  nSize = 100;
  GetComputerNameA(szMachineName, &nSize);
  return szMachineName;
}

// File Line: 123
// RVA: 0xEC33E8
char *__fastcall OSuitePrivate::MacAddress()
{
  __int64 v1; // [rsp+20h] [rbp-78h]
  __int64 v2; // [rsp+28h] [rbp-70h]
  __int64 v3; // [rsp+30h] [rbp-68h]
  __int64 v4; // [rsp+38h] [rbp-60h]
  __int64 v5; // [rsp+40h] [rbp-58h]
  __int64 v6; // [rsp+48h] [rbp-50h]
  OSuite::psock::interface_t dest; // [rsp+50h] [rbp-48h]

  if ( OSuite::psock::getinterfaces(&dest, 1) )
  {
    LODWORD(v6) = (unsigned __int8)dest.mac[5];
    LODWORD(v5) = (unsigned __int8)dest.mac[4];
    LODWORD(v4) = (unsigned __int8)dest.mac[3];
    LODWORD(v3) = (unsigned __int8)dest.mac[2];
    LODWORD(v2) = (unsigned __int8)dest.mac[1];
    LODWORD(v1) = (unsigned __int8)dest.mac[0];
    snprintf_s(macAddress, 0x12ui64, 0xFFFFFFFFFFFFFFFFui64, "%02X-%02X-%02X-%02X-%02X-%02X", v1, v2, v3, v4, v5, v6);
  }
  else
  {
    snprintf_s(
      macAddress,
      0x12ui64,
      0xFFFFFFFFFFFFFFFFui64,
      "%02X-%02X-%02X-%02X-%02X-%02X",
      0i64,
      0i64,
      0i64,
      0i64,
      0i64,
      0i64);
  }
  return macAddress;
}

// File Line: 170
// RVA: 0xEC3388
const char *__fastcall OSuitePrivate::Locale()
{
  GEOID v0; // eax
  const char *result; // rax
  int v2; // eax
  bool v3; // zf
  bool v4; // sf

  if ( OSuitePrivate::g_Locale[0] )
    return OSuitePrivate::g_Locale;
  v0 = GetUserGeoID(0x10u);
  if ( v0 == -1 )
    return "XX";
  v2 = GetGeoInfoA(v0, 4u, OSuitePrivate::g_Locale, 3, 0);
  v3 = v2 == 0;
  v4 = v2 < 0;
  result = "XX";
  if ( !v4 && !v3 )
    return OSuitePrivate::g_Locale;
  return result;
}

