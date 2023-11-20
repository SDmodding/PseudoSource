// File Line: 31
// RVA: 0xED2650
signed __int64 __fastcall OSuite::stringToEdmType(OSuite::ZString *sType)
{
  OSuite::ZString *v1; // rsi
  unsigned int v2; // edi
  const char **v3; // rbx

  v1 = sType;
  v2 = 0;
  v3 = aTypeStrings;
  while ( !OSuite::ZString::EqualsCaseInsensitive(v1, *v3) )
  {
    ++v3;
    ++v2;
    if ( (signed __int64)v3 >= (signed __int64)&USAGETRACKER_OVERALL_STATLABEL )
      return 16i64;
  }
  return v2;
}

// File Line: 53
// RVA: 0xED24C8
signed __int64 __fastcall OSuite::deduceEdmTypeFromName(OSuite::ZString *name)
{
  OSuite::ZString *v1; // rbx

  v1 = name;
  if ( OSuite::ZString::StartsWith(name, "i8_") )
    return 12i64;
  if ( OSuite::ZString::StartsWith(v1, "i16_") )
    return 9i64;
  if ( OSuite::ZString::StartsWith(v1, "i32_") )
    return 10i64;
  if ( OSuite::ZString::StartsWith(v1, "i64_") )
    return 11i64;
  if ( OSuite::ZString::StartsWith(v1, "f_") )
    return 7i64;
  if ( OSuite::ZString::StartsWith(v1, "b_") )
    return 2i64;
  if ( OSuite::ZString::StartsWith(v1, "bin_") )
    return 1i64;
  if ( OSuite::ZString::StartsWith(v1, "t_") )
    return 15i64;
  if ( OSuite::ZString::StartsWith(v1, "d_") )
    return 4i64;
  if ( OSuite::ZString::StartsWith(v1, "dto_") )
    return 5i64;
  if ( OSuite::ZString::StartsWith(v1, "g_") )
    return 8i64;
  if ( OSuite::ZString::StartsWith(v1, "s_") || OSuite::ZString::EqualsCaseInsensitive(v1, "_id") )
    return 14i64;
  return OSuite::ZString::StartsWith(v1, "c_") != 0 ? 0x10 : 0;
}

