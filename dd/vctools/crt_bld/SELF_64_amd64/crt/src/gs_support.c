// File Line: 82
// RVA: 0x12D1FE4
void __cdecl _security_init_cookie()
{
  uintptr_t v0; // rax
  unsigned __int64 v1; // [rsp+30h] [rbp+10h]
  _FILETIME SystemTimeAsFileTime; // [rsp+38h] [rbp+18h]
  LARGE_INTEGER PerformanceCount; // [rsp+40h] [rbp+20h]

  v0 = _security_cookie;
  SystemTimeAsFileTime = 0i64;
  if ( _security_cookie == 47936899621426i64 )
  {
    GetSystemTimeAsFileTime(&SystemTimeAsFileTime);
    v1 = (unsigned __int64)SystemTimeAsFileTime;
    v1 ^= GetCurrentThreadId();
    v1 ^= GetTickCount64() << 24;
    v1 ^= GetTickCount64();
    QueryPerformanceCounter(&PerformanceCount);
    v0 = ((unsigned __int64)&v1 ^ v1 ^ PerformanceCount.QuadPart ^ ((unsigned __int64)PerformanceCount.LowPart << 32)) & 0xFFFFFFFFFFFFi64;
    if ( v0 == 47936899621426i64 )
      v0 = 47936899621427i64;
    _security_cookie = v0;
  }
  _security_cookie_complement = ~v0;
}

