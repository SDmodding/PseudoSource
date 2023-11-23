// File Line: 112
// RVA: 0x12ADA88
void __fastcall __ArrayUnwind(char *ptr, unsigned __int64 size, int count, void (__fastcall *pDtor)(void *))
{
  while ( --count >= 0 )
  {
    ptr -= size;
    pDtor(ptr);
  }
}

// File Line: 123
// RVA: 0x1451C92
`__ArrayUnwind'::`1'::filt$0

