// File Line: 22
// RVA: 0x14834C0
__int64 UFG::_dynamic_initializer_for__UI_HASH_SCREEN_FADE_IN_COMPLETE__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("SCREEN_FADE_IN_COMPLETE", 0xFFFFFFFF);
  UI_HASH_SCREEN_FADE_IN_COMPLETE = result;
  return result;
}

// File Line: 23
// RVA: 0x14834E0
__int64 UFG::_dynamic_initializer_for__UI_HASH_SCREEN_FADE_OUT_COMPLETE__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("SCREEN_FADE_OUT_COMPLETE", 0xFFFFFFFF);
  UI_HASH_SCREEN_FADE_OUT_COMPLETE = result;
  return result;
}

// File Line: 80
// RVA: 0x5D8130
void UFG::UIHK_NISOverlay::FadeToLight(void)
{
  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
  {
    UFG::UIHK_NISOverlay::HideElement(
      &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
      (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
      &UFG::UIHK_NISOverlay::m_curtains,
      0.0,
      0);
  }
  UFG::UIHK_NISOverlay::UpdateAudioMuteState();
}

