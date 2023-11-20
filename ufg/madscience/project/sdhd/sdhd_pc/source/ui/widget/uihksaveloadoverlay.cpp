// File Line: 22
// RVA: 0x63BDE0
void __fastcall UFG::UIHKSaveLoadOverlay::update(UFG::UIHKSaveLoadOverlay *this, UFG::UIScreen *screen, float elapsed)
{
  float v3; // xmm1_4

  if ( screen )
  {
    if ( this->m_bOverlayVisible )
    {
      v3 = this->m_fTimeToHideOverlay - elapsed;
      this->m_fTimeToHideOverlay = v3;
      if ( v3 <= 0.0 )
      {
        if ( this->m_bRecievedStopSaveMsg )
        {
          *(_WORD *)&this->m_bOverlayVisible = 0;
          this->m_fTimeToHideOverlay = 0.0;
          Scaleform::GFx::Movie::Invoke(
            screen->mRenderable->m_movie.pObject,
            "stopSaving",
            0i64,
            &customWorldMapCaption);
        }
      }
    }
  }
}

// File Line: 50
// RVA: 0x621630
char __fastcall UFG::UIHKSaveLoadOverlay::handleMessage(UFG::UIHKSaveLoadOverlay *this, UFG::UIScreen *screen, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIHKSaveLoadOverlay *v4; // rbx

  v4 = this;
  if ( !screen )
    return 0;
  if ( msgId != UI_HASH_SAVELOAD_START_SAVING_9 )
  {
    if ( msgId == UI_HASH_SAVELOAD_STOP_SAVING_9 )
    {
      this->m_bRecievedStopSaveMsg = 1;
      return 1;
    }
    return 0;
  }
  if ( !this->m_bOverlayVisible )
  {
    Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, "startSaving", 0i64, &customWorldMapCaption);
    v4->m_bOverlayVisible = 1;
  }
  v4->m_fTimeToHideOverlay = 1.0;
  return 1;
}

