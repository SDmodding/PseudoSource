// File Line: 49
// RVA: 0x5A4DB0
char __fastcall UFG::AmbienceAudio::PlayAmbience(UFG::AmbienceAudio *this, unsigned int eventId)
{
  if ( UFG::AudioEntity::IsPlayingId(this, eventId) )
    return 1;
  else
    return UFG::AudioEntity::CreateAndPlayEvent(this, eventId, 0i64, 0, 0i64);
}

// File Line: 86
// RVA: 0x3C7FD0
void __fastcall UFG::HudAudio::PlayHudSound(unsigned int eventId, UFG::AudioEventInitParams *params)
{
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, eventId, params, 0, 0i64);
}

