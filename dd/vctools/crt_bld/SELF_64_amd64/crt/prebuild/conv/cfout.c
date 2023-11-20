// File Line: 32
// RVA: 0x12CCF88
_strflt *__fastcall fltout2(_CRT_DOUBLE x, _strflt *flt, char *resultstr, unsigned __int64 resultsize)
{
  _strflt *v4; // rdi
  unsigned __int64 v5; // rbx
  char *v6; // rsi
  int v7; // eax
  _LDOUBLE px; // [rsp+30h] [rbp-19h]
  _LDOUBLE pld; // [rsp+40h] [rbp-9h]
  __int16 v11; // [rsp+50h] [rbp+7h]
  char v12; // [rsp+52h] [rbp+9h]
  char _Src; // [rsp+54h] [rbp+Bh]

  v4 = flt;
  *(_CRT_DOUBLE *)px.ld = x;
  v5 = resultsize;
  v6 = resultstr;
  _dtold(&pld, (long double *)px.ld);
  px = pld;
  v7 = _I10_OUTPUT(&px, 17, 0, (_FloatOutStruct *)&v11);
  v4->sign = v12;
  v4->decpt = v11;
  v4->flag = v7;
  if ( (unsigned int)strcpy_s(v6, v5, &_Src) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    JUMPOUT(*(_QWORD *)&byte_1412CD03C);
  }
  v4->mantissa = v6;
  return v4;
}

// File Line: 62
// RVA: 0x12CCEB8
void __fastcall _dtold(_LDOUBLE *pld, long double *px)
{
  unsigned __int16 v2; // r11
  _LDOUBLE *v3; // r10
  __int16 v4; // r8
  __int16 v5; // r11
  unsigned int v6; // eax
  __int16 v7; // r8
  int v8; // ecx
  unsigned int v9; // ebx
  signed __int16 v10; // r8
  int v11; // er9

  v2 = *((_WORD *)px + 3);
  v3 = pld;
  v4 = v2 >> 4;
  v5 = v2 & 0x8000;
  v6 = *(_DWORD *)px;
  v7 = v4 & 0x7FF;
  v8 = *((_DWORD *)px + 1) & 0xFFFFF;
  v9 = 2147483648;
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
      *(_DWORD *)&v3->ld[4] = 0;
      *(_DWORD *)v3->ld = 0;
      goto LABEL_13;
    }
    v10 = 15361;
    v9 = 0;
  }
  *(_DWORD *)v3->ld = v6 << 11;
  v11 = v9 | (v8 << 11) | (v6 >> 21);
  *(_DWORD *)&v3->ld[4] = v11;
  if ( v11 >= 0 )
  {
    do
    {
      v11 = 2 * v11 | (*(_DWORD *)v3->ld >> 31);
      *(_DWORD *)v3->ld *= 2;
      --v10;
    }
    while ( v11 >= 0 );
    *(_DWORD *)&v3->ld[4] = v11;
  }
  v5 |= v10;
LABEL_13:
  *(_WORD *)&v3->ld[8] = v5;
}

