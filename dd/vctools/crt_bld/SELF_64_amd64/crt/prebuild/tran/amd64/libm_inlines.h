// File Line: 1898
// RVA: 0x12AF1D0
void __fastcall _remainder_piby2f_inline(unsigned __int64 ux, long double *r, int *region)
{
  long double *v3; // rdi
  int v4; // er11
  int *v5; // rbx
  unsigned __int64 v6; // r10
  int v7; // er9
  int v8; // er11
  __int64 v9; // r8
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rdx
  unsigned __int64 v12; // rcx
  unsigned __int64 v13; // rcx
  signed __int64 v14; // r8
  __int64 v15; // rax
  signed int v16; // er9
  unsigned __int64 v17; // rdx
  unsigned __int64 v18; // rdx
  int v19; // esi
  unsigned __int64 v20; // rdx
  __int64 *v21; // r10
  unsigned __int64 v22; // r8
  __int64 *v23; // rax
  int v24; // er10
  unsigned __int64 v25; // rax
  unsigned __int64 v26; // [rsp+18h] [rbp-80h]
  unsigned __int64 v27; // [rsp+20h] [rbp-78h]
  unsigned __int64 v28; // [rsp+28h] [rbp-70h]
  __int64 v29; // [rsp+30h] [rbp-68h]

  v29 = 0i64;
  v3 = r;
  v4 = ((ux >> 52) & 0x7FF) - 1023;
  v5 = region;
  v6 = (ux & 0xFFFFFE0000000i64 | 0x10000000000000i64) >> 29;
  v7 = v4 / 36;
  v8 = v4 % 36;
  v9 = v7 + 3;
  v10 = v6 * pibits[v9];
  v11 = (v10 >> 36) + v6 * pibits[v9 - 1];
  v12 = pibits[v9 - 2];
  v28 = v10 & 0xFFFFFFFFFi64;
  v13 = (v11 >> 36) + v6 * v12;
  v27 = v11 & 0xFFFFFFFFFi64;
  v14 = v13 & 0xFFFFFFFFFi64;
  v15 = v7;
  v16 = 1;
  v17 = pibits[v15];
  v26 = v13 & 0xFFFFFFFFFi64;
  v18 = ((v13 & 0xFFFFFFFFFi64 | (((v13 >> 36) + v6 * v17) << 36)) >> (35 - (unsigned __int8)v8)) & 7;
  v19 = v18 & 1;
  if ( v18 & 1 )
  {
    *v5 = ((unsigned __int8)((signed int)v18 >> 1) + 1) & 3;
    v20 = ~v14 & ((1i64 << (36 - (unsigned __int8)v8)) - 1);
    if ( v20 < 0x10000 )
    {
      v21 = (__int64 *)&v26;
      do
      {
        ++v21;
        ++v16;
        v20 = (v20 << 36) | ~*v21 & 0xFFFFFFFFFi64;
      }
      while ( v20 < 0x10000 );
    }
    v22 = ~*(&v26 + v16) & 0xFFFFFFFFFi64;
  }
  else
  {
    *v5 = (signed int)v18 >> 1;
    v20 = v14 & ((1i64 << (36 - (unsigned __int8)v8)) - 1);
    if ( v20 < 0x10000 )
    {
      v23 = (__int64 *)&v26;
      do
      {
        ++v23;
        ++v16;
        v20 = *v23 | (v20 << 36);
      }
      while ( v20 < 0x10000 );
    }
    v22 = *(&v26 + v16);
  }
  v24 = 0;
  while ( v20 < 0x400000000000i64 )
  {
    v24 += 6;
    v20 <<= 6;
  }
  while ( v20 < 0x10000000000000i64 )
  {
    ++v24;
    v20 *= 2i64;
  }
  v25 = (v20 | (v22 >> (36 - (unsigned __int8)v24))) & 0xFFFFFFFFFFFFFi64 | ((v8 - 36 * v16 - v24 + 52 + 1023i64) << 52);
  if ( v19 )
    v25 = (v20 | (v22 >> (36 - (unsigned __int8)v24))) & 0xFFFFFFFFFFFFFi64 | ((v8 - 36 * v16 - v24 + 52 + 1023i64) << 52) | 0x8000000000000000ui64;
  *v3 = *(double *)&v25 * 1.570796326794897;
}

