// File Line: 43
// RVA: 0x12CD040
__int64 __fastcall fcloseall()
{
  unsigned int v0; // edi
  int i; // ebx
  _iobuf *v2; // rcx

  v0 = 0;
  lock(1);
  for ( i = 3; i < nstream; ++i )
  {
    v2 = (_iobuf *)_piob[i];
    if ( v2 )
    {
      if ( (v2->_flag & 0x83) != 0 && (unsigned int)fclose(v2) != -1 )
        ++v0;
      if ( i >= 20 )
      {
        DeleteCriticalSection((LPCRITICAL_SECTION)((char *)_piob[i] + 48));
        free(_piob[i]);
        _piob[i] = 0i64;
      }
    }
  }
  unlock(1);
  return v0;
}

// File Line: 69
// RVA: 0x1452280
_fcloseall$fin$0

