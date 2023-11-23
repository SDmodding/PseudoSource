// File Line: 31
// RVA: 0xED2650
__int64 __fastcall OSuite::stringToEdmType(OSuite::ZString *sType)
{
  unsigned int v2; // edi
  const char **v3; // rbx

  v2 = 0;
  v3 = aTypeStrings;
  while ( !OSuite::ZString::EqualsCaseInsensitive(sType, *v3) )
  {
    ++v3;
    ++v2;
    if ( (__int64)v3 >= (__int64)&USAGETRACKER_OVERALL_STATLABEL )
      return 16i64;
  }
  return v2;
}

// File Line: 53
// RVA: 0xED24C8
__int64 __fastcall OSuite::deduceEdmTypeFromName(OSuite::ZString *name)
{
  if ( OSuite::ZString::StartsWith(name, "i8_") )
    return 12i64;
  if ( OSuite::ZString::StartsWith(name, "i16_") )
    return 9i64;
  if ( OSuite::ZString::StartsWith(name, "i32_") )
    return 10i64;
  if ( OSuite::ZString::StartsWith(name, "i64_") )
    return 11i64;
  if ( OSuite::ZString::StartsWith(name, "f_") )
    return 7i64;
  if ( OSuite::ZString::StartsWith(name, "b_") )
    return 2i64;
  if ( OSuite::ZString::StartsWith(name, "bin_") )
    return 1i64;
  if ( OSuite::ZString::StartsWith(name, "t_") )
    return 15i64;
  if ( OSuite::ZString::StartsWith(name, "d_") )
    return 4i64;
  if ( OSuite::ZString::StartsWith(name, "dto_") )
    return 5i64;
  if ( OSuite::ZString::StartsWith(name, "g_") )
    return 8i64;
  if ( OSuite::ZString::StartsWith(name, "s_") || OSuite::ZString::EqualsCaseInsensitive(name, "_id") )
    return 14i64;
  return OSuite::ZString::StartsWith(name, "c_") ? 0x10 : 0;
}

