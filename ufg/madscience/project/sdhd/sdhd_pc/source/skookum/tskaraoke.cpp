// File Line: 47
// RVA: 0x4D4210
void UFG::TSKaraoke::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("KaraokeMinigame");
  SSClass::register_method_func(v0, "private_is_instrumental", UFG::TSKaraoke::MthdC_is_instrumental, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "get_last_score", UFG::TSKaraoke::MthdC_get_last_score, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "is_successful", UFG::TSKaraoke::MthdC_is_successful, 1, rebindb);
}

// File Line: 64
// RVA: 0x4E9BB0
void __fastcall UFG::TSKaraoke::MthdC_is_successful(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(UFG::UIHKScreenKaraokeMinigame::mbWon);
}

// File Line: 78
// RVA: 0x4E95E0
void __fastcall UFG::TSKaraoke::MthdC_is_instrumental(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(UFG::UIHKScreenKaraokeMinigame::mbInstrumentalSection);
}

// File Line: 91
// RVA: 0x4E7AC0
void __fastcall UFG::TSKaraoke::MthdC_get_last_score(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
  {
    if ( (_DWORD)UFG::UIHKScreenKaraokeMinigame::mScore == 111 )
      *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, 0i64);
    else
      *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, (unsigned int)UFG::UIHKScreenKaraokeMinigame::mScore);
  }
}

