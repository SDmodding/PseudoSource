// File Line: 39
// RVA: 0x12C57A4
SIZE_T __fastcall msize(void *pblock)
{
  if ( pblock )
    return HeapSize(crtheap, 0, pblock);
  *errno() = 22;
  invalid_parameter_noinfo();
  return -1i64;
}

