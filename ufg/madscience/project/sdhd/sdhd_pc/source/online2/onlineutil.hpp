// File Line: 65
// RVA: 0x42B490
unsigned __int64 __fastcall UFG::OnlineUtil::CurrentTimeMillis()
{
  return (unsigned __int64)((UFG::qGetSystemTimeUTC() - 116444736000000000i64)
                          * (unsigned __int128)0x346DC5D63886594Bui64 >> 64) >> 11;
}

