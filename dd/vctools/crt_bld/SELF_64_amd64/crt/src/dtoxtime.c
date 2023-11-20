// File Line: 48
// RVA: 0x12D77A4
signed __int64 __fastcall _loctotime32_t(int yr, int mo, int dy, int hr, int mn, int sc, int dstflag)
{
  int v7; // ebx
  int v8; // er13
  int v9; // edi
  int v10; // er9
  int v11; // er14
  unsigned int v12; // esi
  int _Daylight; // [rsp+30h] [rbp-48h]
  int _Daylight_savings_bias; // [rsp+34h] [rbp-44h]
  int _Timezone; // [rsp+38h] [rbp-40h]
  tm tb; // [rsp+40h] [rbp-38h]

  v7 = yr - 1900;
  v8 = hr;
  v9 = mo;
  _Daylight = 0;
  _Daylight_savings_bias = 0;
  _Timezone = 0;
  if ( (unsigned int)(yr - 1970) > 0x406
    || (unsigned int)(mo - 1) > 0xB
    || (unsigned int)hr > 0x17
    || (unsigned int)mn > 0x3B
    || (unsigned int)sc > 0x3B
    || dy < 1
    || (v10 = days[mo - 1], days[mo] - v10 < dy)
    && ((v7 % 4 || v7 == 100 * (v7 / 100)) && yr != 400 * (yr / 400) || mo != 2 || dy > 29) )
  {
    *errno() = 22;
    return 0xFFFFFFFFi64;
  }
  v11 = v10 + dy;
  if ( (!(v7 % 4) && v7 != 100 * (v7 / 100) || yr == 400 * (yr / 400)) && mo > 2 )
    ++v11;
  _tzset();
  if ( (unsigned int)get_daylight(&_Daylight) )
  {
LABEL_31:
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
    JUMPOUT(*(_QWORD *)_ValidateWrite);
  }
  if ( (unsigned int)get_dstbias(&_Daylight_savings_bias) )
  {
LABEL_30:
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
    goto LABEL_31;
  }
  if ( (unsigned int)get_timezone(&_Timezone) )
  {
    invoke_watson(0i64, 0i64, 0i64, 0, 0i64);
    __debugbreak();
    goto LABEL_30;
  }
  tb.tm_yday = v11;
  tb.tm_year = v7;
  tb.tm_hour = v8;
  tb.tm_min = mn;
  tb.tm_sec = sc;
  tb.tm_mon = v9 - 1;
  v12 = _Timezone
      + 60 * (mn + 60 * (v8 + 24 * ((v7 + 299) / 400 - (v7 - 1) / 100 + v11 + (v7 - 1) / 4 + 365 * v7)))
      + sc
      + 2085978496;
  if ( dstflag == 1 || dstflag == -1 && _Daylight && (unsigned int)isindst(&tb) )
    v12 += _Daylight_savings_bias;
  return v12;
}

