// File Line: 45
// RVA: 0x12CD7BC
_iobuf *__fastcall getstream()
{
  _DWORD *v0; // rbx
  __int64 v1; // rdi
  _BYTE *v2; // rcx
  char *v3; // rcx

  v0 = 0i64;
  lock(1);
  LODWORD(v1) = 0;
  while ( (signed int)v1 < nstream )
  {
    v2 = _piob[(signed int)v1];
    if ( !v2 )
    {
      v3 = (char *)malloc_crt(0x58ui64);
      v1 = (signed int)v1;
      _piob[(signed int)v1] = v3;
      if ( v3 )
      {
        InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(v3 + 48), 0xFA0u);
        EnterCriticalSection((LPCRITICAL_SECTION)((char *)_piob[v1] + 48));
        v0 = _piob[v1];
        v0[6] = 0;
      }
      break;
    }
    if ( !(v2[24] & 0x83) && !(*((_DWORD *)v2 + 6) & 0x8000) )
    {
      if ( (unsigned int)(v1 - 3) <= 0x10 && !(unsigned int)mtinitlocknum((signed int)v1 + 16) )
        break;
      lock_file2(v1, _piob[(signed int)v1]);
      if ( !(*((_BYTE *)_piob[(signed int)v1] + 24) & 0x83) )
      {
        v0 = _piob[(signed int)v1];
        break;
      }
      unlock_file2(v1, _piob[(signed int)v1]);
    }
    LODWORD(v1) = v1 + 1;
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

