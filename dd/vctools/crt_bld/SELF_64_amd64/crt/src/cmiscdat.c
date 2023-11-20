// File Line: 54
// RVA: 0x12C66BC
__int64 initp_misc_cfltcvt_tab()
{
  int v0; // edi
  PVOID *v1; // rbx
  __int64 result; // rax

  v0 = 0;
  v1 = (PVOID *)cfltcvt_tab;
  do
  {
    ++v0;
    *v1 = EncodePointer(*v1);
    result = v0;
    ++v1;
  }
  while ( (unsigned __int64)v0 < 0xA );
  return result;
}

