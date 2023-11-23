// File Line: 38
// RVA: 0x12B99F0
void __fastcall rewind(_iobuf *str)
{
  __int64 v2; // rdi
  ioinfo *v3; // rcx
  int flag; // eax

  if ( str )
  {
    if ( (int)ioinit() >= 0 )
    {
      v2 = fileno(str);
      lock_file(str);
      flush(str);
      str->_flag &= 0xFFFFFFCF;
      if ( (unsigned int)(v2 + 2) <= 1 )
        v3 = &_badioinfo;
      else
        v3 = &_pioinfo[v2 >> 5][v2 & 0x1F];
      v3->osfile &= ~2u;
      flag = str->_flag;
      if ( (flag & 0x80u) != 0 )
        str->_flag = flag & 0xFFFFFFFC;
      if ( lseek(v2, 0, 0) == -1 )
        str->_flag |= 0x20u;
      unlock_file(str);
    }
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
  }
}

