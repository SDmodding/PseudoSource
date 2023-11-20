// File Line: 103
// RVA: 0xA79880
_BOOL8 __fastcall CAkSound::IsPlayable(CAkSound *this)
{
  return this->m_Source.m_sSrcTypeInfo.mediaInfo.sourceID != 0;
}

