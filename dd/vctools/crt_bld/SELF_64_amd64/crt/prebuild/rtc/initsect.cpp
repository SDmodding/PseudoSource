// File Line: 49
// RVA: 0x12CD2E8
void __cdecl RTC_Initialize()
{
  void (**i)(void); // rbx

  for ( i = (void (**)(void))_rtc_izz; i < (void (**)(void))_rtc_izz; ++i )
  {
    if ( *i )
      (*i)();
  }
}

// File Line: 63
// RVA: 0x12CD320
void __cdecl RTC_Terminate()
{
  void (**i)(void); // rbx

  for ( i = (void (**)(void))_rtc_tzz; i < (void (**)(void))_rtc_tzz; ++i )
  {
    if ( *i )
      (*i)();
  }
}

