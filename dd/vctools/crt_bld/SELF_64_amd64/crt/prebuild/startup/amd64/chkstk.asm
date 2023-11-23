// File Line: 75
// RVA: 0x12AE2D0
unsigned __int64 __fastcall alloca_probe()
{
  unsigned __int64 result; // rax
  char *v1; // r10
  char *v2; // r11
  char v3; // [rsp+18h] [rbp+8h] BYREF

  v1 = &v3 - result;
  if ( (unsigned __int64)&v3 < result )
    v1 = 0i64;
  v2 = (char *)NtCurrentTeb()->Reserved1[2];
  if ( v1 < v2 )
  {
    LOWORD(v1) = (unsigned __int16)v1 & 0xF000;
    do
    {
      v2 -= 4096;
      *v2 = 0;
    }
    while ( v1 != v2 );
  }
  return result;
}

