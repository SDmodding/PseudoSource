// File Line: 40
// RVA: 0x12B0C60
void __fastcall free(void *pBlock)
{
  int *v1; // rbx
  unsigned int LastError; // eax

  if ( pBlock )
  {
    if ( !HeapFree(crtheap, 0, pBlock) )
    {
      v1 = errno();
      LastError = GetLastError();
      *v1 = get_errno_from_oserr(LastError);
    }
  }
}

