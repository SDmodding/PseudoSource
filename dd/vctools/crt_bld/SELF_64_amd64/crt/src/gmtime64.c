// File Line: 47
// RVA: 0x12C0D4C
__int64 __fastcall gmtime64_s(tm *ptm, __int64 *timp)
{
  int v2; // edi
  __int64 result; // rax
  __int64 v6; // r9
  int v7; // r8d
  int v8; // r10d
  __int64 v9; // r9
  int *v10; // r8
  int tm_yday; // r11d
  int v12; // r9d
  int v13; // edx
  int *i; // rcx
  int v15; // edx
  __int64 v16; // rdx
  int v17; // r9d

  v2 = 0;
  if ( !ptm || (memset(ptm, 255, sizeof(tm)), !timp) )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22i64;
  }
  v6 = *timp;
  if ( *timp < -43200 || v6 > 0x7934126CFi64 )
  {
    *errno() = 22;
    return 22i64;
  }
  v7 = (int)v6 / 31536000 + 70;
  v8 = (int)v6 / 31536000 + 69;
  v9 = 86400 * (-365i64 * ((int)v6 / 31536000) - (v8 / 4 - 17 + ((int)v6 / 31536000 + 369) / 400 - v8 / 100)) + v6;
  if ( v9 >= 0 )
  {
    if ( !(v7 % 4) && v7 != 100 * (v7 / 100) || v7 + 1900 == 400 * ((v7 + 1900) / 400) )
      goto LABEL_16;
  }
  else
  {
    LODWORD(v9) = v9 + 31536000;
    v7 = v8;
    if ( !(v8 % 4) && v8 != 100 * (v8 / 100) || v8 + 1900 == 400 * ((v8 + 1900) / 400) )
    {
      LODWORD(v9) = v9 + 86400;
LABEL_16:
      v2 = 1;
    }
  }
  ptm->tm_year = v7;
  v10 = lpdays;
  ptm->tm_yday = (int)v9 / 86400;
  tm_yday = ptm->tm_yday;
  v12 = (int)v9 % 86400;
  v13 = 1;
  if ( !v2 )
    v10 = days;
  for ( i = v10 + 1; *i < tm_yday; ++i )
    ++v13;
  v15 = v13 - 1;
  ptm->tm_mon = v15;
  ptm->tm_mday = tm_yday - v10[v15];
  v16 = (unsigned __int128)(*timp * (__int128)0x1845C8A0CE512957i64) >> 64;
  ptm->tm_isdst = 0;
  ptm->tm_wday = (int)(((unsigned __int64)v16 >> 63) + (v16 >> 13) + 4) % 7;
  ptm->tm_hour = v12 / 3600;
  v17 = v12 % 3600;
  ptm->tm_min = v17 / 60;
  result = 0i64;
  ptm->tm_sec = v17 % 60;
  return result;
}

