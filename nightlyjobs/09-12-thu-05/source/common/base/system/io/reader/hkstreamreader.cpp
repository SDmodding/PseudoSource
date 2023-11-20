// File Line: 12
// RVA: 0xC6A090
__int64 __fastcall hkStreamReader::skip(hkStreamReader *this, int nbytes)
{
  int v2; // edi
  hkStreamReader *v3; // rsi
  int i; // ebx
  signed __int64 v5; // r8
  int v6; // eax
  char v8; // [rsp+20h] [rbp-208h]

  v2 = nbytes;
  v3 = this;
  for ( i = nbytes; i; i -= v6 )
  {
    v5 = (unsigned int)i;
    if ( i > 512 )
      v5 = 512i64;
    v6 = ((__int64 (__fastcall *)(hkStreamReader *, char *, signed __int64))v3->vfptr[2].__vecDelDtor)(v3, &v8, v5);
    if ( !v6 )
      break;
  }
  return (unsigned int)(v2 - i);
}

// File Line: 29
// RVA: 0xC6A110
__int64 __fastcall hkStreamReader::peek(hkStreamReader *this, void *buf, int nbytes)
{
  return 0i64;
}

