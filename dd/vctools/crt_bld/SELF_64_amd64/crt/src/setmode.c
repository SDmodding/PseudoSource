// File Line: 105
// RVA: 0x12D58F4
signed __int64 __fastcall setmode_nolock(int fh, int mode)
{
  signed __int64 v2; // r10
  unsigned __int64 v3; // r8
  ioinfo *v4; // r9
  char v5; // cl
  int v6; // ebx
  int v7; // er11
  ioinfo *v8; // rax
  ioinfo *v9; // rax
  signed __int64 result; // rax

  v2 = (signed __int64)fh >> 5;
  v3 = fh & 0x1F;
  v4 = _pioinfo[v2];
  v5 = v4[v3].osfile;
  v6 = v4[v3].osfile & 0x80;
  v7 = (char)(2 * *((_BYTE *)&v4[v3] + 56)) >> 1;
  if ( mode == 0x4000 )
  {
    v4[v3].osfile = v5 | 0x80;
    *((_BYTE *)&_pioinfo[v2][v3] + 56) &= 0x80u;
  }
  else if ( mode == 0x8000 )
  {
    v4[v3].osfile = v5 & 0x7F;
  }
  else if ( (mode - 0x10000) & 0xFFFEFFFF )
  {
    if ( mode == 0x40000 )
    {
      v4[v3].osfile = v5 | 0x80;
      v8 = _pioinfo[v2];
      *((_BYTE *)&v8[v3] + 56) &= 0x81u;
      *((_BYTE *)&v8[v3] + 56) |= 1u;
    }
  }
  else
  {
    v4[v3].osfile = v5 | 0x80;
    v9 = _pioinfo[v2];
    *((_BYTE *)&v9[v3] + 56) &= 0x82u;
    *((_BYTE *)&v9[v3] + 56) |= 2u;
  }
  if ( v6 )
    result = v7 != 0 ? 0x10000 : 0x4000;
  else
    result = 0x8000i64;
  return result;
}

// File Line: 159
// RVA: 0x12D58C4
signed __int64 __fastcall get_fmode(int *pMode)
{
  signed __int64 result; // rax

  if ( pMode )
  {
    *pMode = fmode;
    result = 0i64;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    result = 22i64;
  }
  return result;
}

