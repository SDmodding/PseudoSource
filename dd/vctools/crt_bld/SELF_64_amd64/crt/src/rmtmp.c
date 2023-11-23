// File Line: 50
// RVA: 0x12D5D08
__int64 __fastcall rmtmp()
{
  unsigned int v0; // edi
  int i; // ebx
  char *v2; // rdx
  void **v3; // rdx
  _iobuf *v4; // rcx

  v0 = 0;
  lock(1);
  for ( i = 0; i < nstream; ++i )
  {
    v2 = (char *)_piob[i];
    if ( v2 && (v2[24] & 0x83) != 0 )
    {
      lock_file2(i, v2);
      v3 = _piob;
      v4 = (_iobuf *)_piob[i];
      if ( (v4->_flag & 0x83) != 0 )
      {
        if ( v4->_tmpfname )
        {
          fclose_nolock(v4);
          ++v0;
          v3 = _piob;
        }
      }
      unlock_file2(i, (char *)v3[i]);
    }
  }
  unlock(1);
  return v0;
}

