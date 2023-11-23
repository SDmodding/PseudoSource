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
  unsigned int nSize; // [rsp+20h] [rbp-18h] BYREF

  strcpy(szMachineName, "Windows");
  nSize = 100;
  GetComputerNameA(szMachineName, &nSize);
  return szMachineName;
}

// File Line: 123
// RVA: 0xEC33E8
char *__fastcall OSuitePrivate::MacAddress()
{
  int v1; // [rsp+20h] [rbp-78h]
  int v2; // [rsp+28h] [rbp-70h]
  int v3; // [rsp+30h] [rbp-68h]
  int v4; // [rsp+38h] [rbp-60h]
  int v5; // [rsp+40h] [rbp-58h]
  int v6; // [rsp+48h] [rbp-50h]
  OSuite::psock::interface_t dest; // [rsp+50h] [rbp-48h] BYREF

  if ( OSuite::psock::getinterfaces(&dest, 1) )
  {
    v6 = (unsigned __int8)dest.mac[5];
    v5 = (unsigned __int8)dest.mac[4];
    v4 = (unsigned __int8)dest.mac[3];
    v3 = (unsigned __int8)dest.mac[2];
    v2 = (unsigned __int8)dest.mac[1];
    v1 = (unsigned __int8)dest.mac[0];
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
  GEOID UserGeoID; // eax
  const char *result; // rax
  int GeoInfoA; // eax
  bool v3; // zf
  bool v4; // sf

  if ( OSuitePrivate::g_Locale[0] )
    return OSuitePrivate::g_Locale;
  UserGeoID = GetUserGeoID(0x10u);
  if ( UserGeoID == -1 )
    return "XX";
  GeoInfoA = GetGeoInfoA(UserGeoID, 4u, OSuitePrivate::g_Locale, 3, 0);
  v3 = GeoInfoA == 0;
  v4 = GeoInfoA < 0;
  result = "XX";
  if ( !v4 && !v3 )
    return OSuitePrivate::g_Locale;
  return result;
}

