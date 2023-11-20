// File Line: 110
// RVA: 0x12B52C0
void (__fastcall *__fastcall _set_se_translator(void (__fastcall *pNew)(unsigned int, _EXCEPTION_POINTERS *)))(unsigned int, _EXCEPTION_POINTERS *)
{
  void (__fastcall *v1)(unsigned int, _EXCEPTION_POINTERS *); // rdi
  void *v2; // rbx

  v1 = pNew;
  v2 = getptd()->_translator;
  getptd()->_translator = v1;
  return (void (__fastcall *)(unsigned int, _EXCEPTION_POINTERS *))v2;
}

