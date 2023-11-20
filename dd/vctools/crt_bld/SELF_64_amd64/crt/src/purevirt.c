// File Line: 43
// RVA: 0x12ADAD4
void __noreturn purecall()
{
  void (*v0)(void); // rax

  v0 = (void (*)(void))DecodePointer(_pPurecall);
  if ( v0 )
    v0();
  NMSG_WRITE(25);
  set_abort_behavior(0, 1u);
  abort();
}

