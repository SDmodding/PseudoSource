// File Line: 47
// RVA: 0x4D4210
void UFG::TSKaraoke::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("KaraokeMinigame");
  SSClass::register_method_func(v0, "private_is_instrumental", UFG::TSKaraoke::MthdC_is_instrumental, 1, 0);
  SSClass::register_method_func(v0, "get_last_score", UFG::TSKaraoke::MthdC_get_last_score, 1, 0);
  SSClass::register_method_func(v0, "is_successful", UFG::TSKaraoke::MthdC_is_successful, 1, 0);
}

// File Line: 64
// RVA: 0x4E9BB0
void __fastcall UFG::TSKaraoke::MthdC_is_successful(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(UFG::UIHKScreenKaraokeMinigame::mbWon);
}

// File Line: 78
// RVA: 0x4E95E0
void __fastcall UFG::TSKaraoke::MthdC_is_instrumental(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(UFG::UIHKScreenKaraokeMinigame::mbInstrumentalSection);
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

