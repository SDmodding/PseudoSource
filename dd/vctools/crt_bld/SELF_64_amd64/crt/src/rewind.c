// File Line: 38
// RVA: 0x12B99F0
void __fastcall rewind(_iobuf *str)
{
  _iobuf *v1; // rbx
  __int64 v2; // rdi
  ioinfo *v3; // rcx
  int v4; // eax

  v1 = str;
  if ( str )
  {
    if ( (signed int)ioinit() >= 0 )
    {
      v2 = fileno(v1);
      lock_file(v1);
      flush(v1);
      v1->_flag &= 0xFFFFFFCF;
      if ( (unsigned int)(v2 + 2) <= 1 )
        v3 = &_badioinfo;
      else
        v3 = &_pioinfo[v2 >> 5][v2 & 0x1F];
      v3->osfile &= 0xFDu;
      v4 = v1->_flag;
      if ( (v4 & 0x80u) != 0 )
        v1->_flag = v4 & 0xFFFFFFFC;
      if ( lseek(v2, 0, 0) == -1 )
        v1->_flag |= 0x20u;
      unlock_file(v1);
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
  }
}

