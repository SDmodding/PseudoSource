// File Line: 110
// RVA: 0x12B906C
void __fastcall dosmaperr(unsigned int oserrno)
{
  unsigned int v1; // edi
  _tiddata *v2; // rax
  unsigned int *v3; // rax
  _tiddata *v4; // rax
  int *v5; // rbx

  v1 = oserrno;
  v2 = getptd_noexit();
  if ( v2 )
    v3 = &v2->_tdoserrno;
  else
    v3 = &DoserrorNoMem;
  *v3 = v1;
  v4 = getptd_noexit();
  v5 = &ErrnoNoMem;
  if ( v4 )
    v5 = &v4->_terrno;
  *v5 = get_errno_from_oserr(v1);
}

// File Line: 119
// RVA: 0x12B90DC
signed __int64 __fastcall get_errno_from_oserr(unsigned int oserrno)
{
  int v1; // edx
  errentry *v2; // r8
  signed __int64 result; // rax

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
    result = 8i64;
  return result;
}

// File Line: 279
// RVA: 0x12B90BC
int *__fastcall errno()
{
  _tiddata *v0; // rax
  int *result; // rax

  v0 = getptd_noexit();
  if ( v0 )
    result = &v0->_terrno;
  else
    result = &ErrnoNoMem;
  return result;
}

// File Line: 292
// RVA: 0x12B904C
unsigned int *__fastcall _doserrno()
{
  _tiddata *v0; // rax
  unsigned int *result; // rax

  v0 = getptd_noexit();
  if ( v0 )
    result = &v0->_tdoserrno;
  else
    result = &DoserrorNoMem;
  return result;
}

