// File Line: 51
// RVA: 0x12C52B0
void __fastcall initp_eh_hooks(void *enull)
{
  __pInconsistency = EncodePointer(terminate);
}

// File Line: 66
// RVA: 0x12C5290
void __noreturn terminate(void)
{
  void (*v0)(void); // rcx

  v0 = (void (*)(void))getptd()->_terminate;
  if ( v0 )
    v0();
  abort();
}

// File Line: 140
// RVA: 0x12C5270
void __noreturn _inconsistency(void)
{
  void (*v0)(void); // rax

  v0 = (void (*)(void))DecodePointer(__pInconsistency);
  if ( v0 )
    v0();
  terminate();
}

