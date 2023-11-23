// File Line: 52
// RVA: 0x12B22C0
void __fastcall initp_misc_rand_s(int (__fastcall *enull)(void *, unsigned int))
{
  g_pfnRtlGenRandom = enull;
}

