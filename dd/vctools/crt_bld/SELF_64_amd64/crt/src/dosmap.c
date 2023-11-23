// File Line: 110
// RVA: 0x12B906C
void __fastcall dosmaperr(unsigned int oserrno)
{
  _tiddata *v2; // rax
  unsigned int *p_tdoserrno; // rax
  _tiddata *v4; // rax
  int *p_terrno; // rbx

  v2 = getptd_noexit();
  if ( v2 )
    p_tdoserrno = &v2->_tdoserrno;
  else
    p_tdoserrno = &DoserrorNoMem;
  *p_tdoserrno = oserrno;
  v4 = getptd_noexit();
  p_terrno = &ErrnoNoMem;
  if ( v4 )
    p_terrno = &v4->_terrno;
  *p_terrno = get_errno_from_oserr(oserrno);
}

// File Line: 119
// RVA: 0x12B90DC
__int64 __fastcall get_errno_from_oserr(unsigned int oserrno)
{
  int v1; // edx
  errentry *v2; // r8
  __int64 result; // rax

  v1 = 0;
  v2 = errtable;
  do
  {
    if ( oserrno == v2->oscode )
      return (unsigned int)errtable[v1].errnocode;
    ++v1;
    ++v2;
  }
  while ( (unsigned __int64)v1 < 0x2D );
  if ( oserrno - 19 <= 0x11 )
    return 13i64;
  result = 22i64;
  if ( oserrno - 188 <= 0xE )
    return 8i64;
  return result;
}

// File Line: 279
// RVA: 0x12B90BC
int *__fastcall errno()
{
  _tiddata *v0; // rax

  v0 = getptd_noexit();
  if ( v0 )
    return &v0->_terrno;
  else
    return &ErrnoNoMem;
}

// File Line: 292
// RVA: 0x12B904C
unsigned int *__fastcall _doserrno()
{
  _tiddata *v0; // rax

  v0 = getptd_noexit();
  if ( v0 )
    return &v0->_tdoserrno;
  else
    return &DoserrorNoMem;
}

