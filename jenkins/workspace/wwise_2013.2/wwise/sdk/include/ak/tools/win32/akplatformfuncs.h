// File Line: 178
// RVA: 0xA5CAD0
void __fastcall AKPLATFORM::AkSetThreadName(unsigned int in_dwThreadID, const char *in_szThreadName)
{
  ULONG_PTR Arguments[2]; // [rsp+20h] [rbp-28h] BYREF
  unsigned int v3; // [rsp+30h] [rbp-18h]
  int v4; // [rsp+34h] [rbp-14h]

  LODWORD(Arguments[0]) = 4096;
  Arguments[1] = (ULONG_PTR)in_szThreadName;
  v3 = in_dwThreadID;
  v4 = 0;
  RaiseException(0x406D1388u, 0, 3u, Arguments);
}

// File Line: 203
// RVA: 0x141F330
`AKPLATFORM::AkSetThreadName'::`1'::filt$0

