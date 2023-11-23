// File Line: 56
// RVA: 0x12B1980
__int64 __fastcall time64(__int64 *timeptr)
{
  signed __int64 v2; // rdx
  _FILETIME SystemTimeAsFileTime; // [rsp+30h] [rbp+8h] BYREF

  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  v2 = (*(_QWORD *)&SystemTimeAsFileTime - 116444736000000000i64) / 0x989680ui64;
  if ( v2 > 0x793406FFFi64 )
    v2 = -1i64;
  if ( timeptr )
    *timeptr = v2;
  return v2;
}

