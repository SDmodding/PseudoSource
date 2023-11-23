// File Line: 32
// RVA: 0x12CCF88
_strflt *__fastcall fltout2(_CRT_DOUBLE x, _strflt *flt, char *resultstr, unsigned __int64 resultsize)
{
  int v7; // eax
  _LDOUBLE px; // [rsp+30h] [rbp-19h] BYREF
  _LDOUBLE pld; // [rsp+40h] [rbp-9h] BYREF
  _FloatOutStruct v11; // [rsp+50h] [rbp+7h] BYREF

  *(_CRT_DOUBLE *)px.ld = x;
  _dtold(&pld, (long double *)px.ld);
  px = pld;
  v7 = _I10_OUTPUT(&px, 17, 0, &v11);
  flt->sign = v11.sign;
  flt->decpt = v11.exp;
  flt->flag = v7;
  if ( (unsigned int)strcpy_s(resultstr, resultsize, v11.man) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    JUMPOUT(0x1412CD03Ci64);
  }
  flt->mantissa = resultstr;
  return flt;
}

// File Line: 62
// RVA: 0x12CCEB8
void __fastcall _dtold(_LDOUBLE *pld, long double *px)
{
  unsigned __int16 v2; // r11
  __int16 v4; // r8
  __int16 v5; // r11
  unsigned int v6; // eax
  __int16 v7; // r8
  int v8; // ecx
  unsigned int v9; // ebx
  __int16 v10; // r8
  int v11; // r9d

  v2 = *((_WORD *)px + 3);
  v4 = v2 >> 4;
  v5 = v2 & 0x8000;
  v6 = *(_DWORD *)px;
  v7 = v4 & 0x7FF;
  v8 = *((_DWORD *)px + 1) & 0xFFFFF;
  v9 = 0x80000000;
  if ( v7 )
  {
    if ( v7 == 2047 )
      v10 = 0x7FFF;
    else
      v10 = v7 + 15360;
  }
  else
  {
    if ( !v8 && !v6 )
    {
      *(_DWORD *)&pld->ld[4] = 0;
      *(_DWORD *)pld->ld = 0;
      goto LABEL_13;
    }
    v10 = 15361;
    v9 = 0;
  }
  *(_DWORD *)pld->ld = v6 << 11;
  v11 = v9 | (v8 << 11) | (v6 >> 21);
  *(_DWORD *)&pld->ld[4] = v11;
  if ( v11 >= 0 )
  {
    do
    {
      v11 = (2 * v11) | (*(_DWORD *)pld->ld >> 31);
      *(_DWORD *)pld->ld *= 2;
      --v10;
    }
    while ( v11 >= 0 );
    *(_DWORD *)&pld->ld[4] = v11;
  }
  v5 |= v10;
LABEL_13:
  *(_WORD *)&pld->ld[8] = v5;
}

