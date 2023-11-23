// File Line: 105
// RVA: 0x12D58F4
__int64 __fastcall setmode_nolock(int fh, int mode)
{
  __int64 v2; // r10
  unsigned __int64 v3; // r8
  ioinfo *v4; // r9
  char osfile; // cl
  int v6; // r11d
  ioinfo *v7; // rax
  ioinfo *v8; // rax

  v2 = (__int64)fh >> 5;
  v3 = fh & 0x1F;
  v4 = _pioinfo[v2];
  osfile = v4[v3].osfile;
  v6 = (char)(2 * *((_BYTE *)&v4[v3] + 56)) >> 1;
  if ( mode == 0x4000 )
  {
    v4[v3].osfile = osfile | 0x80;
    *((_BYTE *)&_pioinfo[v2][v3] + 56) &= 0x80u;
  }
  else if ( mode == 0x8000 )
  {
    v4[v3].osfile = osfile & 0x7F;
  }
  else if ( ((mode - 0x10000) & 0xFFFEFFFF) != 0 )
  {
    if ( mode == 0x40000 )
    {
      v4[v3].osfile = osfile | 0x80;
      v7 = _pioinfo[v2];
      *((_BYTE *)&v7[v3] + 56) &= 0x81u;
      *((_BYTE *)&v7[v3] + 56) |= 1u;
    }
  }
  else
  {
    v4[v3].osfile = osfile | 0x80;
    v8 = _pioinfo[v2];
    *((_BYTE *)&v8[v3] + 56) &= 0x82u;
    *((_BYTE *)&v8[v3] + 56) |= 2u;
  }
  if ( (osfile & 0x80) != 0 )
    return v6 != 0 ? 0x10000 : 0x4000;
  else
    return 0x8000i64;
}

// File Line: 159
// RVA: 0x12D58C4
__int64 __fastcall get_fmode(int *pMode)
{
  if ( pMode )
  {
    *pMode = fmode;
    return 0i64;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22i64;
  }
}

