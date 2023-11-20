// File Line: 46
// RVA: 0x12C851C
_flt *__fastcall fltin2(_flt *flt, const char *str, localeinfo_struct *_Locale)
{
  signed int v3; // ebx
  int v4; // ebp
  _flt *v5; // rdi
  char v6; // si
  INTRNCVT_STATUS v7; // eax
  int v8; // ecx
  _flt *result; // rax
  _CRT_DOUBLE d; // [rsp+40h] [rbp-48h]
  const char *v11; // [rsp+48h] [rbp-40h]
  _LDBL12 pld12; // [rsp+50h] [rbp-38h]

  v3 = 0;
  v4 = (signed int)str;
  v5 = flt;
  v6 = _strgtold12_l(&pld12, &v11, str, 0, 0, 0, 0, _Locale);
  if ( v6 & 4 )
  {
    *(_CRT_DOUBLE *)&d.x = 0i64;
    v3 = 512;
  }
  else
  {
    v7 = ld12tod(&pld12, &d);
    if ( v6 & 2 || v7 == 1 )
      v3 = 128;
    if ( v6 & 1 || v7 == 2 )
      v3 |= 0x100u;
  }
  v8 = (signed int)v11;
  v5->flags = v3;
  result = v5;
  v5->nbytes = v8 - v4;
  *(_CRT_DOUBLE *)&v5->dval = d;
  return result;
}

