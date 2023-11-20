// File Line: 56
// RVA: 0x12B3C88
int __fastcall fflush(_iobuf *stream)
{
  _iobuf *v1; // rbx
  int v3; // edi

  v1 = stream;
  if ( !stream )
    return flsall(0);
  lock_file(stream);
  v3 = fflush_nolock(v1);
  unlock_file(v1);
  return v3;
}

// File Line: 97
// RVA: 0x12B3BB4
int __fastcall fflush_nolock(_iobuf *str)
{
  _iobuf *v1; // rbx
  int v3; // eax

  v1 = str;
  if ( !str )
    return flsall(0);
  if ( flush(str) )
    return -1;
  if ( !(v1->_flag & 0x4000) )
    return 0;
  v3 = fileno(v1);
  return -(commit(v3) != 0);
}

// File Line: 142
// RVA: 0x12B3C00
__int64 __fastcall flush(_iobuf *str)
{
  unsigned int v1; // esi
  _iobuf *v2; // rbx
  signed int v3; // edi
  int v4; // eax
  int v5; // eax
  char *v6; // rcx
  __int64 result; // rax

  v1 = 0;
  v2 = str;
  if ( (str->_flag & 3) == 2 )
  {
    if ( str->_flag & 0x108 )
    {
      v3 = LODWORD(str->_ptr) - LODWORD(str->_base);
      if ( v3 > 0 )
      {
        v4 = fileno(str);
        if ( write(v4, v2->_base, v3) == v3 )
        {
          v5 = v2->_flag;
          if ( (v5 & 0x80u) != 0 )
            v2->_flag = v5 & 0xFFFFFFFD;
        }
        else
        {
          v2->_flag |= 0x20u;
          v1 = -1;
        }
      }
    }
  }
  v6 = v2->_base;
  v2->_cnt = 0;
  result = v1;
  v2->_ptr = v6;
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
  int v1; // er14
  unsigned int v2; // esi
  unsigned int v3; // edi
  int i; // ebx
  _BYTE *v5; // rdx
  _iobuf *v6; // rcx

  v1 = flushflag;
  v2 = 0;
  v3 = 0;
  lock(1);
  for ( i = 0; i < nstream; ++i )
  {
    v5 = _piob[i];
    if ( v5 && v5[24] & 0x83 )
    {
      lock_file2(i, v5);
      v6 = (_iobuf *)_piob[i];
      if ( v6->_flag & 0x83 )
      {
        if ( v1 == 1 )
        {
          if ( fflush_nolock(v6) != -1 )
            ++v2;
        }
        else if ( !v1 && v6->_flag & 2 && fflush_nolock(v6) == -1 )
        {
          v3 = -1;
        }
      }
      unlock_file2(i, _piob[i]);
    }
  }
  unlock(1);
  if ( v1 == 1 )
    v3 = v2;
  return v3;
}

// File Line: 276
// RVA: 0x1451D3A
flsall$fin$0

// File Line: 282
// RVA: 0x1451D62
flsall$fin$1

