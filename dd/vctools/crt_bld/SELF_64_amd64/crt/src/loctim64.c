// File Line: 62
// RVA: 0x12BC704
int __fastcall localtime64_s(tm *ptm, const __int64 *ptime)
{
  const __int64 *v2; // rdi
  tm *v3; // rbx
  int result; // eax
  int v5; // eax
  __int64 v6; // rax
  __int64 v7; // rcx
  int v8; // eax
  signed __int64 v9; // r9
  int v10; // ecx
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // r8
  int v13; // edx
  unsigned __int64 v14; // r8
  signed __int64 v15; // r8
  int v16; // ecx
  int v17; // ecx
  int v18; // eax
  __int64 timp; // [rsp+30h] [rbp-10h]
  int _Timezone; // [rsp+60h] [rbp+20h]
  int _Daylight; // [rsp+70h] [rbp+30h]
  int _Daylight_savings_bias; // [rsp+78h] [rbp+38h]

  _Daylight = 0;
  _Daylight_savings_bias = 0;
  _Timezone = 0;
  v2 = ptime;
  v3 = ptm;
  if ( !ptm || (memset(ptm, 255, 0x24ui64), !v2) )
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22;
  }
  if ( *v2 < 0 || *v2 > 32535244799i64 )
  {
    *errno() = 22;
    return 22;
  }
  _tzset();
  if ( get_daylight(&_Daylight) )
  {
LABEL_38:
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
    JUMPOUT(*(_QWORD *)fprintf);
  }
  if ( get_dstbias(&_Daylight_savings_bias) )
  {
LABEL_37:
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
    goto LABEL_38;
  }
  if ( get_timezone(&_Timezone) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
    goto LABEL_37;
  }
  if ( *v2 > 259200 )
  {
    timp = *v2 - _Timezone;
    result = gmtime64_s(v3, &timp);
    if ( result )
      return result;
    if ( _Daylight && isindst(v3) )
    {
      timp -= _Daylight_savings_bias;
      result = gmtime64_s(v3, &timp);
      if ( result )
        return result;
      v3->tm_isdst = 1;
    }
    return 0;
  }
  result = gmtime64_s(v3, v2);
  if ( result )
    return result;
  if ( _Daylight && isindst(v3) )
  {
    v5 = _Timezone;
    v3->tm_isdst = 1;
    v6 = _Daylight_savings_bias + v5;
  }
  else
  {
    v6 = _Timezone;
  }
  v7 = v3->tm_sec - v6;
  v8 = v3->tm_sec
     - v6
     - 60
     * (((unsigned __int64)(v7 + ((unsigned __int128)(v7 * (signed __int128)-8608480567731124087i64) >> 64)) >> 63)
      + ((signed __int64)(v7 + ((unsigned __int128)(v7 * (signed __int128)-8608480567731124087i64) >> 64)) >> 5));
  v3->tm_sec = v8;
  if ( v8 < 0 )
  {
    v7 -= 60i64;
    v3->tm_sec = v8 + 60;
  }
  v9 = v3->tm_min
     + ((unsigned __int64)(v7 + ((unsigned __int128)(v7 * (signed __int128)-8608480567731124087i64) >> 64)) >> 63)
     + ((signed __int64)(v7 + ((unsigned __int128)(v7 * (signed __int128)-8608480567731124087i64) >> 64)) >> 5);
  v10 = v3->tm_min
      + ((unsigned __int64)(v7 + ((unsigned __int128)(v7 * (signed __int128)-8608480567731124087i64) >> 64)) >> 63)
      + ((signed __int64)(v7 + ((unsigned __int128)(v7 * (signed __int128)-8608480567731124087i64) >> 64)) >> 5)
      - 60
      * (((unsigned __int64)(v9 + ((unsigned __int128)(v9 * (signed __int128)-8608480567731124087i64) >> 64)) >> 63)
       + ((signed __int64)(v9 + ((unsigned __int128)(v9 * (signed __int128)-8608480567731124087i64) >> 64)) >> 5));
  v3->tm_min = v10;
  if ( v10 < 0 )
  {
    v9 -= 60i64;
    v3->tm_min = v10 + 60;
  }
  v11 = v9 + ((unsigned __int128)(v9 * (signed __int128)-8608480567731124087i64) >> 64);
  v12 = v3->tm_hour + (v11 >> 63) + ((signed __int64)v11 >> 5);
  v13 = v12
      - 24
      * (((unsigned __int64)((unsigned __int128)((signed __int64)v12 * (signed __int128)3074457345618258603i64) >> 64) >> 63)
       + ((signed __int64)((unsigned __int128)((signed __int64)v12 * (signed __int128)3074457345618258603i64) >> 64) >> 2));
  v3->tm_hour = v13;
  if ( v13 < 0 )
  {
    v12 -= 24i64;
    v3->tm_hour = v13 + 24;
  }
  v14 = (signed __int64)((unsigned __int128)((signed __int64)v12 * (signed __int128)3074457345618258603i64) >> 64) >> 2;
  v15 = (v14 >> 63) + v14;
  if ( v15 <= 0 )
  {
    if ( v15 >= 0 )
      return 0;
    v17 = v3->tm_wday;
    v3->tm_mday += v15;
    v18 = v3->tm_mday;
    v3->tm_wday = ((signed int)v15 + v17 + 7) % 7;
    if ( v18 <= 0 )
    {
      v3->tm_mon = 11;
      v3->tm_mday = v18 + 31;
      v3->tm_yday += v15 + 365;
      --v3->tm_year;
      return 0;
    }
  }
  else
  {
    v16 = v15 + v3->tm_wday;
    v3->tm_mday += v15;
    v3->tm_wday = v16 % 7;
  }
  v3->tm_yday += v15;
  return 0;
}

// File Line: 234
// RVA: 0x12BC6BC
tm *__fastcall localtime64(const __int64 *ptime)
{
  const __int64 *v1; // rdi
  tm *result; // rax
  tm *v3; // rbx

  v1 = ptime;
  result = (tm *)_getgmtimebuf();
  v3 = result;
  if ( result )
  {
    if ( localtime64_s(result, v1) )
      v3 = 0i64;
    result = v3;
  }
  return result;
}

