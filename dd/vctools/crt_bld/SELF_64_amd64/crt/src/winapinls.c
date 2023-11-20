// File Line: 25
// RVA: 0x12D7EFC
__int64 __fastcall _crtCompareStringEx(const wchar_t *lpLocaleName, __int64 dwCmpFlags, const wchar_t *lpString1, __int64 cchCount1, const wchar_t *lpString2, int cchCount2)
{
  int v6; // ST28_4

  v6 = cchCount2;
  return CompareStringEx(lpLocaleName, dwCmpFlags, lpString1, cchCount1, lpString2, v6, 0i64, 0i64, 0i64);
}

// File Line: 46
// RVA: 0x12D7F34
__int64 __fastcall _crtEnumSystemLocalesEx(int (__fastcall *lpLocaleEnumProcEx)(unsigned __int16 *, unsigned int, __int64), __int64 dwFlags, __int64 lParam)
{
  return EnumSystemLocalesEx(lpLocaleEnumProcEx, dwFlags, lParam, 0i64);
}

// File Line: 65
// RVA: 0x12D7F40
__int64 __fastcall _crtGetDateFormatEx(const wchar_t *lpLocaleName, __int64 dwFlags, _SYSTEMTIME *lpDate, const wchar_t *lpFormat, unsigned __int16 *lpDateStr, int cchDate)
{
  int v6; // ST28_4

  v6 = cchDate;
  return GetDateFormatEx(lpLocaleName, dwFlags, lpDate, lpFormat, lpDateStr, v6, 0i64);
}

// File Line: 85
// RVA: 0x12D7F68
int __fastcall _crtGetLocaleInfoEx(const wchar_t *lpLocaleName, unsigned int LCType, unsigned __int16 *lpLCData, int cchData)
{
  return GetLocaleInfoEx(lpLocaleName, LCType, lpLCData, cchData);
}

// File Line: 104
// RVA: 0x12D7F70
int __fastcall _crtGetTimeFormatEx(const wchar_t *lpLocaleName, unsigned int dwFlags, _SYSTEMTIME *lpTime, const wchar_t *lpFormat, unsigned __int16 *lpTimeStr, int cchTime)
{
  return GetTimeFormatEx(lpLocaleName, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime);
}

// File Line: 121
// RVA: 0x12D7F78
__int64 __fastcall _crtGetUserDefaultLocaleName(unsigned __int16 *lpLocaleName, __int64 cchLocaleName)
{
  return GetUserDefaultLocaleName(lpLocaleName, cchLocaleName);
}

// File Line: 133
// RVA: 0x12D7F80
int __fastcall _crtIsValidLocaleName(const wchar_t *lpLocaleName)
{
  return IsValidLocaleName(lpLocaleName);
}

// File Line: 149
// RVA: 0x12D7F88
__int64 __fastcall _crtLCMapStringEx(const wchar_t *lpLocaleName, __int64 dwMapFlags, const wchar_t *lpSrcStr, __int64 cchSrc, unsigned __int16 *lpDestStr, int cchDest)
{
  int v6; // ST28_4

  v6 = cchDest;
  return LCMapStringEx(lpLocaleName, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, v6, 0i64, 0i64, 0i64);
}

