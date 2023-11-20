// File Line: 53
// RVA: 0x12D2190
char *__fastcall wincmdln()
{
  BOOL v0; // edi
  char *v1; // rbx

  v0 = 0;
  if ( !_mbctype_initialized )
    _initmbctable();
  v1 = acmdln;
  if ( !acmdln )
    v1 = &customWorldMapCaption;
  while ( 1 )
  {
    if ( (unsigned __int8)*v1 <= 0x20u )
    {
      if ( !*v1 )
        return v1;
      if ( !v0 )
        break;
    }
    if ( *v1 == 34 )
      v0 = v0 == 0;
    if ( (unsigned int)ismbblead((unsigned __int8)*v1) )
      ++v1;
    ++v1;
  }
  while ( *v1 && (unsigned __int8)*v1 <= 0x20u )
    ++v1;
  return v1;
}

