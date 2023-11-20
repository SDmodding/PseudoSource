// File Line: 49
// RVA: 0x5A4DB0
char __fastcall UFG::AmbienceAudio::PlayAmbience(UFG::AmbienceAudio *this, unsigned int eventId)
{
  unsigned int v2; // ebx
  UFG::AmbienceAudio *v3; // rdi
  char result; // al

  v2 = eventId;
  v3 = this;
  if ( UFG::AudioEntity::IsPlayingId((UFG::AudioEntity *)&this->vfptr, eventId) )
    result = 1;
  else
    result = UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v3->vfptr, v2, 0i64, 0, 0i64);
  return result;
}

// File Line: 86
// RVA: 0x3C7FD0
void __fastcall UFG::HudAudio::PlayHudSound(unsigned int eventId, UFG::AudioEventInitParams *params)
{
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      eventId,
      params,
      0,
      0i64);
}

