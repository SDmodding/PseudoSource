// File Line: 31
// RVA: 0x12CAA58
void __fastcall initp_heap_handler(void *enull)
{
  _pnhHeap = enull;
}

// File Line: 131
// RVA: 0x12CAA24
_BOOL8 __fastcall callnewh(unsigned __int64 size)
{
  unsigned __int64 v1; // rbx
  unsigned int (__fastcall *v2)(unsigned __int64); // rax

  v1 = size;
  v2 = (unsigned int (__fastcall *)(unsigned __int64))DecodePointer(_pnhHeap);
  return v2 && v2(v1);
}

