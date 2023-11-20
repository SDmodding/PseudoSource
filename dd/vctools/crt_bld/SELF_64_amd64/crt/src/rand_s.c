// File Line: 52
// RVA: 0x12B22C0
void __fastcall initp_misc_rand_s(void *enull)
{
  g_pfnRtlGenRandom = (int (__fastcall *)(void *, unsigned int))enull;
}

