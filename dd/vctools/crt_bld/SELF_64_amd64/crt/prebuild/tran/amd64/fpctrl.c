// File Line: 41
// RVA: 0x12C6F14
__int64 statfp()
{
  return get_fpsr() & 0x3F;
}

// File Line: 65
// RVA: 0x12C6E58
__int64 clrfp()
{
  __int64 v0; // rbx

  v0 = get_fpsr() & 0x3F;
  fclrf();
  return (unsigned int)v0;
}

// File Line: 91
// RVA: 0x12C6E78
unsigned __int64 __fastcall ctrlfp(unsigned __int64 newctrl, unsigned __int64 _mask)
{
  int v2; // ebx
  int v3; // edi
  unsigned int fpsr; // esi
  __int64 v5; // rcx

  v2 = _mask;
  v3 = newctrl;
  fpsr = get_fpsr();
  v5 = v2 & v3 | fpsr & (~(_WORD)v2 | 0xFFFF807F);
  if ( dazSupported && (((unsigned __int8)(v2 & v3) | fpsr & ((unsigned __int8)~(_BYTE)v2 | 0x7F)) & 0x40) != 0 )
    set_fpsr(v5);
  else
    set_fpsr((unsigned int)v5 & 0xFFFFFFBF);
  return fpsr;
}

// File Line: 105
// RVA: 0x14521AA
_ctrlfp$filt$0

// File Line: 135
// RVA: 0x12C6EF4
void __fastcall set_statfp(unsigned __int64 sw)
{
  char v1; // bl
  unsigned int fpsr; // eax

  v1 = sw;
  fpsr = get_fpsr();
  set_fpsr(v1 & 0x3F | fpsr);
}

