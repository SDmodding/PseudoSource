// File Line: 93
// RVA: 0x12DCEEC
__int64 __fastcall xtow_s(
        unsigned int val,
        unsigned __int16 *buf,
        unsigned __int64 sizeInTChars,
        unsigned int radix,
        int is_neg)
{
  int *v9; // rax
  unsigned int v10; // ebx
  unsigned __int64 v12; // rcx
  unsigned __int16 *v13; // r8
  unsigned __int16 *v14; // r9
  unsigned int v15; // eax
  unsigned int v16; // edx
  unsigned __int16 v17; // dx
  unsigned __int16 *v18; // r8
  unsigned __int16 v19; // cx

  if ( !buf || !sizeInTChars )
    goto LABEL_2;
  *buf = 0;
  if ( sizeInTChars <= (unsigned __int64)(is_neg != 0) + 1 )
  {
    v9 = errno();
    v10 = 34;
    goto LABEL_3;
  }
  v10 = 34;
  if ( radix - 2 > 0x22 )
  {
LABEL_2:
    v9 = errno();
    v10 = 22;
LABEL_3:
    *v9 = v10;
    invalid_parameter_noinfo();
    return v10;
  }
  v12 = 0i64;
  v13 = buf;
  if ( is_neg )
  {
    v13 = buf + 1;
    v12 = 1i64;
    *buf = 45;
    val = -val;
  }
  v14 = v13;
  do
  {
    v16 = val % radix;
    v15 = val / radix;
    val /= radix;
    if ( v16 <= 9 )
      v17 = v16 + 48;
    else
      v17 = v16 + 87;
    *v13 = v17;
    ++v12;
    ++v13;
  }
  while ( v15 && v12 < sizeInTChars );
  if ( v12 >= sizeInTChars )
  {
    *buf = 0;
    v9 = errno();
    goto LABEL_3;
  }
  *v13 = 0;
  v18 = v13 - 1;
  do
  {
    v19 = *v18;
    *v18 = *v14;
    *v14++ = v19;
    --v18;
  }
  while ( v14 < v18 );
  return 0i64;
}

// File Line: 172
// RVA: 0x12B218C
int __fastcall itoa_s(int val, char *buf, unsigned __int64 sizeInTChars, unsigned int radix)
{
  if ( radix == 10 && val < 0 )
    return xtoa_s(val, buf, sizeInTChars, 0xAu, 1);
  else
    return xtoa_s(val, buf, sizeInTChars, radix, 0);
}

// File Line: 199
// RVA: 0x12B21B4
int __fastcall ultoa_s(unsigned int val, char *buf, unsigned __int64 sizeInTChars, unsigned int radix)
{
  return xtoa_s(val, buf, sizeInTChars, radix, 0);
}

// File Line: 235
// RVA: 0x12B3644
char *__fastcall itoa(int val, char *buf, unsigned int radix)
{
  int v4; // r9d

  v4 = radix == 10 && val < 0;
  xtoa(val, buf, radix, v4);
  return buf;
}

// File Line: 258
// RVA: 0x12B3670
char *__fastcall ultoa(unsigned int val, char *buf, unsigned int radix)
{
  xtoa(val, buf, radix, 0);
  return buf;
}

