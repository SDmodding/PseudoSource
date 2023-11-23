// File Line: 56
// RVA: 0x12B3C88
int __fastcall fflush(_iobuf *stream)
{
  int v3; // edi

  if ( !stream )
    return flsall(0);
  lock_file(stream);
  v3 = fflush_nolock(stream);
  unlock_file(stream);
  return v3;
}

// File Line: 97
// RVA: 0x12B3BB4
int __fastcall fflush_nolock(_iobuf *str)
{
  int v3; // eax

  if ( !str )
    return flsall(0);
  if ( flush(str) )
    return -1;
  if ( (str->_flag & 0x4000) == 0 )
    return 0;
  v3 = fileno(str);
  return -(commit(v3) != 0);
}

// File Line: 142
// RVA: 0x12B3C00
__int64 __fastcall flush(_iobuf *str)
{
  unsigned int v1; // esi
  signed int v3; // edi
  int v4; // eax
  int flag; // eax
  char *base; // rcx
  __int64 result; // rax

  v1 = 0;
  if ( (str->_flag & 3) == 2 && (str->_flag & 0x108) != 0 )
  {
    v3 = LODWORD(str->_ptr) - LODWORD(str->_base);
    if ( v3 > 0 )
    {
      v4 = fileno(str);
      if ( write(v4, str->_base, v3) == v3 )
      {
        flag = str->_flag;
        if ( (flag & 0x80u) != 0 )
          str->_flag = flag & 0xFFFFFFFD;
      }
      else
      {
        str->_flag |= 0x20u;
        v1 = -1;
      }
    }
  }
  base = str->_base;
  str->_cnt = 0;
  result = v1;
  str->_ptr = base;
  return result;
}

// File Line: 193
// RVA: 0x12B3C7C
int __fastcall flushall()
{
  return flsall(1);
}

// File Line: 228
// RVA: 0x12B3CCC
__int64 __fastcall flsall(int flushflag)
{
  unsigned int v2; // esi
  unsigned int v3; // edi
  int i; // ebx
  char *v5; // rdx
  _iobuf *v6; // rcx

  v2 = 0;
  v3 = 0;
  lock(1);
  for ( i = 0; i < nstream; ++i )
  {
    v5 = (char *)_piob[i];
    if ( v5 && (v5[24] & 0x83) != 0 )
    {
      lock_file2(i, v5);
      v6 = (_iobuf *)_piob[i];
      if ( (v6->_flag & 0x83) != 0 )
      {
        if ( flushflag == 1 )
        {
          if ( fflush_nolock(v6) != -1 )
            ++v2;
        }
        else if ( !flushflag && (v6->_flag & 2) != 0 && fflush_nolock(v6) == -1 )
        {
          v3 = -1;
        }
      }
      unlock_file2(i, (char *)_piob[i]);
    }
  }
  unlock(1);
  if ( flushflag == 1 )
    return v2;
  return v3;
}

// File Line: 276
// RVA: 0x1451D3A
flsall$fin$0

// File Line: 282
// RVA: 0x1451D62
flsall$fin$1

