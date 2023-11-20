// File Line: 93
// RVA: 0x12DCEEC
__int64 __fastcall xtow_s(unsigned int val, unsigned __int16 *buf, unsigned __int64 sizeInTChars, unsigned int radix, int is_neg)
{
  unsigned int v5; // esi
  unsigned __int64 v6; // rdi
  unsigned __int16 *v7; // r10
  unsigned int v8; // er11
  int *v9; // rax
  unsigned int v10; // ebx
  unsigned __int64 v12; // rcx
  unsigned __int16 *v13; // r8
  unsigned __int16 *v14; // r9
  int v15; // eax
  unsigned int v16; // edx
  unsigned __int16 v17; // dx
  unsigned __int16 *v18; // r8
  unsigned __int16 v19; // cx

  v5 = radix;
  v6 = sizeInTChars;
  v7 = buf;
  v8 = val;
  if ( !buf || !sizeInTChars )
    goto LABEL_23;
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
LABEL_23:
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
    v8 = -v8;
  }
  v14 = v13;
  do
  {
    v16 = v8 % v5;
    v15 = v8 / v5;
    v8 /= v5;
    if ( v16 <= 9 )
      v17 = v16 + 48;
    else
      v17 = v16 + 87;
    *v13 = v17;
    ++v12;
    ++v13;
  }
  while ( v15 && v12 < v6 );
  if ( v12 >= v6 )
  {
    *v7 = 0;
    v9 = errno();
    goto LABEL_3;
  }
  *v13 = 0;
  v18 = v13 - 1;
  do
  {
    v19 = *v18;
    *v18 = *v14;
    *v14 = v19;
    ++v14;
    --v18;
  }
  while ( v14 < v18 );
  return 0i64;
}

// File Line: 172
// RVA: 0x12B218C
int __fastcall itoa_s(int val, char *buf, unsigned __int64 sizeInTChars, int radix)
{
  int result; // eax

  if ( radix != 10 || val >= 0 )
    result = xtoa_s(val, buf, sizeInTChars, radix, 0);
  else
    result = xtoa_s(val, buf, sizeInTChars, 0xAu, 1);
  return result;
}

// File Line: 199
// RVA: 0x12B21B4
int __fastcall ultoa_s(unsigned int val, char *buf, unsigned __int64 sizeInTChars, int radix)
{
  return xtoa_s(val, buf, sizeInTChars, radix, 0);
}

// File Line: 235
// RVA: 0x12B3644
char *__fastcall itoa(int val, char *buf, int radix)
{
  char *v3; // rbx
  int v4; // er9

  v3 = buf;
  v4 = radix == 10 && val < 0;
  xtoa(val, buf, radix, v4);
  return v3;
}

// File Line: 258
// RVA: 0x12B3670
char *__fastcall ultoa(unsigned int val, char *buf, int radix)
{
  char *v3; // rbx

  v3 = buf;
  xtoa(val, buf, radix, 0);
  return v3;
}

