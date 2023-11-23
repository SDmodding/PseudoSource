// File Line: 60
// RVA: 0x12BB974
__int64 __fastcall clock()
{
  _FILETIME SystemTimeAsFileTime; // [rsp+30h] [rbp+8h] BYREF

  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  return (unsigned int)((SystemTimeAsFileTime.dwLowDateTime
                       + ((unsigned __int64)SystemTimeAsFileTime.dwHighDateTime << 32)
                       - start_tics)
                      / 0x2710);
}

// File Line: 97
// RVA: 0x12BB948
__int64 __fastcall _inittime()
{
  __int64 result; // rax
  _FILETIME SystemTimeAsFileTime; // [rsp+30h] [rbp+8h] BYREF

  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  result = 0i64;
  start_tics = SystemTimeAsFileTime.dwLowDateTime + ((unsigned __int64)SystemTimeAsFileTime.dwHighDateTime << 32);
  return result;
}

