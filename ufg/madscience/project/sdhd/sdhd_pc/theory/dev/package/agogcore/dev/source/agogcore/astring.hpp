// File Line: 289
// RVA: 0x1079F0
void __fastcall SSMethodCall::operator delete(void *mem_p, const char *name_p)
{
  AMemory::c_free_func(mem_p);
}

