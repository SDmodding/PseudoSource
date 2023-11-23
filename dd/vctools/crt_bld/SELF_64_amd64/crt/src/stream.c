// File Line: 45
// RVA: 0x12CD7BC
_iobuf *__fastcall getstream()
{
  _DWORD *v0; // rbx
  int i; // edi
  _BYTE *v2; // rcx
  char *v3; // rcx

  v0 = 0i64;
  lock(1);
  for ( i = 0; i < nstream; ++i )
  {
    v2 = _piob[i];
    if ( !v2 )
    {
      v3 = (char *)malloc_crt(0x58ui64);
      _piob[i] = v3;
      if ( v3 )
      {
        InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(v3 + 48), 0xFA0u);
        EnterCriticalSection((LPCRITICAL_SECTION)((char *)_piob[i] + 48));
        v0 = _piob[i];
        v0[6] = 0;
      }
      break;
    }
    if ( (v2[24] & 0x83) == 0 && (*((_DWORD *)v2 + 6) & 0x8000) == 0 )
    {
      if ( (unsigned int)(i - 3) <= 0x10 && !(unsigned int)mtinitlocknum(i + 16) )
        break;
      lock_file2(i, (char *)_piob[i]);
      if ( (*((_BYTE *)_piob[i] + 24) & 0x83) == 0 )
      {
        v0 = _piob[i];
        break;
      }
      unlock_file2(i, (char *)_piob[i]);
    }
  }
  if ( v0 )
  {
    v0[6] &= 0x8000u;
    v0[2] = 0;
    *((_QWORD *)v0 + 2) = 0i64;
    *(_QWORD *)v0 = 0i64;
    *((_QWORD *)v0 + 5) = 0i64;
    v0[7] = -1;
  }
  unlock(1);
  return (_iobuf *)v0;
}

