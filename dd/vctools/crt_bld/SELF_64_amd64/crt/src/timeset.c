// File Line: 35
// RVA: 0x12CE420
__int64 __fastcall get_daylight(int *_Daylight)
{
  if ( _Daylight )
  {
    *_Daylight = daylight;
    return 0i64;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22i64;
  }
}

// File Line: 44
// RVA: 0x12CE450
__int64 __fastcall get_dstbias(int *_Daylight_savings_bias)
{
  if ( _Daylight_savings_bias )
  {
    *_Daylight_savings_bias = dstbias;
    return 0i64;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22i64;
  }
}

// File Line: 53
// RVA: 0x12CE480
__int64 __fastcall get_timezone(int *_Timezone)
{
  if ( _Timezone )
  {
    *_Timezone = timezone;
    return 0i64;
  }
  else
  {
    *errno() = 22;
    invalid_parameter_noinfo();
    return 22i64;
  }
}

// File Line: 118
// RVA: 0x12CE400
int *__fastcall _daylight()
{
  return &daylight;
}

// File Line: 123
// RVA: 0x12CE408
int *__fastcall _dstbias()
{
  return &dstbias;
}

// File Line: 128
// RVA: 0x12CE410
int *__fastcall _timezone()
{
  return &timezone;
}

// File Line: 133
// RVA: 0x12CE418
char **__fastcall _tzname()
{
  return tzname;
}

