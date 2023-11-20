// File Line: 112
// RVA: 0x12ADA88
void __fastcall __ArrayUnwind(void *ptr, unsigned __int64 size, int count, void (__fastcall *pDtor)(void *))
{
  void (__fastcall *v4)(void *); // rsi
  int v5; // edi
  unsigned __int64 v6; // r14
  char *i; // rbx

  v4 = pDtor;
  v5 = count;
  v6 = size;
  for ( i = (char *)ptr; --v5 >= 0; v4(i) )
    i -= v6;
}

// File Line: 123
// RVA: 0x1451C92
`__ArrayUnwind'::`1'::filt$0

