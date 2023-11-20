// File Line: 47
// RVA: 0x12C0D4C
signed __int64 __fastcall gmtime64_s(tm *ptm, const __int64 *timp)
{
  signed int v2; // edi
  const __int64 *v3; // rsi
  tm *v4; // rbx
  signed __int64 result; // rax
  signed __int64 v6; // r9
  int v7; // er8
  int v8; // er10
  signed __int64 v9; // r9
  int *v10; // r8
  int v11; // edx
  int v12; // er11
  signed __int64 v13; // r9
  signed int v14; // edx
  int *i; // rcx
  int v16; // edx
  unsigned __int64 v17; // rdx
  signed __int64 v18; // r9

  v2 = 0;
  v3 = timp;
  v4 = ptm;
  if ( !ptm || (memset(ptm, 255, 0x24ui64), !v3) )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22i64;
  }
  v6 = *v3;
  if ( *v3 < -43200 || v6 > 32535291599i64 )
  {
    *errno() = 22;
    return 22i64;
  }
  v7 = ((unsigned __int64)(v6 + ((unsigned __int128)(v6 * (signed __int128)-8633038790181359431i64) >> 64)) >> 63)
     + ((signed __int64)(v6 + ((unsigned __int128)(v6 * (signed __int128)-8633038790181359431i64) >> 64)) >> 24)
     + 70;
  v8 = ((unsigned __int64)(v6 + ((unsigned __int128)(v6 * (signed __int128)-8633038790181359431i64) >> 64)) >> 63)
     + ((signed __int64)(v6 + ((unsigned __int128)(v6 * (signed __int128)-8633038790181359431i64) >> 64)) >> 24)
     + 69;
  v9 = 86400
     * (-365i64
      * (signed int)(((unsigned __int64)(v6 + ((unsigned __int128)(v6 * (signed __int128)-8633038790181359431i64) >> 64)) >> 63)
                   + ((signed __int64)(v6 + ((unsigned __int128)(v6 * (signed __int128)-8633038790181359431i64) >> 64)) >> 24))
      - (v8 / 4
       - 17
       + (signed int)(((unsigned __int64)(v6 + ((unsigned __int128)(v6 * (signed __int128)-8633038790181359431i64) >> 64)) >> 63)
                    + ((signed __int64)(v6 + ((unsigned __int128)(v6 * (signed __int128)-8633038790181359431i64) >> 64)) >> 24)
                    + 369)
       / 400
       - v8 / 100))
     + v6;
  if ( v9 >= 0 )
  {
    if ( !(v7 % 4) && v7 != 100 * (v7 / 100) || v7 + 1900 == 400 * ((v7 + 1900) / 400) )
      goto LABEL_16;
  }
  else
  {
    v9 += 31536000i64;
    v7 = v8;
    if ( !(v8 % 4) && v8 != 100 * (v8 / 100) || v8 + 1900 == 400 * ((v8 + 1900) / 400) )
    {
      v9 += 86400i64;
LABEL_16:
      v2 = 1;
      goto LABEL_17;
    }
  }
LABEL_17:
  v4->tm_year = v7;
  v10 = lpdays;
  v11 = ((unsigned __int64)((unsigned __int128)(v9 * (signed __int128)1749024623285053783i64) >> 64) >> 63)
      + ((signed __int64)((unsigned __int128)(v9 * (signed __int128)1749024623285053783i64) >> 64) >> 13);
  v4->tm_yday = v11;
  v12 = v4->tm_yday;
  v13 = -86400i64 * v11 + v9;
  v14 = 1;
  if ( !v2 )
    v10 = days;
  for ( i = v10 + 1; *i < v12; ++i )
    ++v14;
  v16 = v14 - 1;
  v4->tm_mon = v16;
  v4->tm_mday = v12 - v10[v16];
  v17 = (unsigned __int128)(*v3 * (signed __int128)1749024623285053783i64) >> 64;
  v4->tm_isdst = 0;
  v4->tm_wday = (signed int)((v17 >> 63) + ((signed __int64)v17 >> 13) + 4) % 7;
  LODWORD(v17) = ((unsigned __int64)((unsigned __int128)(v13 * (signed __int128)5247073869855161349i64) >> 64) >> 63)
               + ((signed __int64)((unsigned __int128)(v13 * (signed __int128)5247073869855161349i64) >> 64) >> 10);
  v4->tm_hour = v17;
  v18 = -3600i64 * (signed int)v17 + v13;
  LODWORD(v17) = ((unsigned __int64)(v18 + ((unsigned __int128)(v18 * (signed __int128)-8608480567731124087i64) >> 64)) >> 63)
               + ((signed __int64)(v18 + ((unsigned __int128)(v18 * (signed __int128)-8608480567731124087i64) >> 64)) >> 5);
  v4->tm_min = v17;
  result = 0i64;
  v4->tm_sec = v18 - 60 * v17;
  return result;
}

