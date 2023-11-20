// File Line: 56
// RVA: 0x12B1980
__int64 __fastcall time64(__int64 *timeptr)
{
  __int64 *v1; // rbx
  signed __int64 v2; // rdx
  _FILETIME SystemTimeAsFileTime; // [rsp+30h] [rbp+8h]

  v1 = timeptr;
  GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
  v2 = (unsigned __int64)((unsigned __int64)(*(_QWORD *)&SystemTimeAsFileTime - 116444736000000000i64)
                        * (unsigned __int128)0xD6BF94D5E57A42BDui64 >> 64) >> 23;
  if ( v2 > 32535244799i64 )
    v2 = -1i64;
  if ( v1 )
    *v1 = v2;
  return v2;
}

