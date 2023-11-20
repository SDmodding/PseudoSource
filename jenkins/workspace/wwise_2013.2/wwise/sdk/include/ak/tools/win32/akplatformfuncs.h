// File Line: 178
// RVA: 0xA5CAD0
void __fastcall AKPLATFORM::AkSetThreadName(unsigned int in_dwThreadID, const char *in_szThreadName)
{
  ULONG_PTR Arguments; // [rsp+20h] [rbp-28h]
  const char *v3; // [rsp+28h] [rbp-20h]
  unsigned int v4; // [rsp+30h] [rbp-18h]
  int v5; // [rsp+34h] [rbp-14h]

  LODWORD(Arguments) = 4096;
  v3 = in_szThreadName;
  v4 = in_dwThreadID;
  v5 = 0;
  RaiseException(0x406D1388u, 0, 3u, &Arguments);
}

// File Line: 203
// RVA: 0x141F330
`AKPLATFORM::AkSetThreadName'::`1'::filt$0

