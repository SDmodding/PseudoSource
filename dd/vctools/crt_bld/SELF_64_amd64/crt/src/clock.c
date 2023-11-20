// File Line: 60
// RVA: 0x12BB974
__int64 __fastcall clock()
{
  _FILETIME SystemTimeAsFileTime; // [rsp+30h] [rbp+8h]

  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  return (unsigned int)((unsigned __int64)((SystemTimeAsFileTime.dwLowDateTime
                                          + ((unsigned __int64)SystemTimeAsFileTime.dwHighDateTime << 32)
                                          - start_tics)
                                         * (unsigned __int128)0x346DC5D63886594Bui64 >> 64) >> 11);
}

// File Line: 97
// RVA: 0x12BB948
__int64 __fastcall _inittime()
{
  __int64 result; // rax
  _FILETIME SystemTimeAsFileTime; // [rsp+30h] [rbp+8h]

  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  result = 0i64;
  start_tics = SystemTimeAsFileTime.dwLowDateTime + ((unsigned __int64)SystemTimeAsFileTime.dwHighDateTime << 32);
  return result;
}

