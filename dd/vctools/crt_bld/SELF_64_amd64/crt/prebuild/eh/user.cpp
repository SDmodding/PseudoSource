// File Line: 110
// RVA: 0x12B52C0
void (__fastcall *__fastcall _set_se_translator(
        void (__fastcall *pNew)(unsigned int, _EXCEPTION_POINTERS *)))(unsigned int, _EXCEPTION_POINTERS *)
{
  void *translator; // rbx

  translator = getptd()->_translator;
  getptd()->_translator = pNew;
  return (void (__fastcall *)(unsigned int, _EXCEPTION_POINTERS *))translator;
}

