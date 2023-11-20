// File Line: 99
// RVA: 0x9F930
char *__fastcall AMemory::malloc_default(unsigned __int64 size)
{
  return UFG::qMalloc(size, UFG::gGlobalNewName, 0i64);
}

