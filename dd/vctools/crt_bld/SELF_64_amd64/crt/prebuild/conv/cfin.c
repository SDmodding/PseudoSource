// File Line: 46
// RVA: 0x12C851C
_flt *__fastcall fltin2(_flt *flt, const char *str, localeinfo_struct *_Locale)
{
  int v3; // ebx
  int v4; // ebp
  char v6; // si
  INTRNCVT_STATUS v7; // eax
  int v8; // ecx
  _flt *result; // rax
  _CRT_DOUBLE d; // [rsp+40h] [rbp-48h] BYREF
  const char *v11; // [rsp+48h] [rbp-40h] BYREF
  _LDBL12 pld12; // [rsp+50h] [rbp-38h] BYREF

  v3 = 0;
  v4 = (int)str;
  v6 = _strgtold12_l(&pld12, &v11, str, 0, 0, 0, 0, _Locale);
  if ( (v6 & 4) != 0 )
  {
    *(_CRT_DOUBLE *)&d.x = 0i64;
    v3 = 512;
  }
  else
  {
    v7 = ld12tod(&pld12, &d);
    if ( (v6 & 2) != 0 || v7 == INTRNCVT_OVERFLOW )
      v3 = 128;
    if ( (v6 & 1) != 0 || v7 == INTRNCVT_UNDERFLOW )
      v3 |= 0x100u;
  }
  v8 = (int)v11;
  flt->flags = v3;
  result = flt;
  flt->nbytes = v8 - v4;
  flt->dval = d.x;
  return result;
}

