// File Line: 24
// RVA: 0x6182D0
void __fastcall UFG::UIHKTimeOfDayWidget::Update(UFG::UIHKTimeOfDayWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rdi
  float m_SecondsSinceMidnight; // xmm0_4
  const char *v6; // rdx

  if ( UFG::TimeOfDayManager::GetInstance() )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      m_SecondsSinceMidnight = UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight;
      if ( m_SecondsSinceMidnight >= 64800.0 || m_SecondsSinceMidnight < 19800.0 )
      {
        if ( this->mLightingConditions == LIGHTING_EVENING )
          return;
        this->mLightingConditions = LIGHTING_EVENING;
        v6 = "setEveningLighting";
      }
      else if ( m_SecondsSinceMidnight >= 43200.0 )
      {
        if ( this->mLightingConditions == LIGHTING_AFTERNOON )
          return;
        this->mLightingConditions = LIGHTING_AFTERNOON;
        v6 = "setAfternoonLighting";
      }
      else
      {
        if ( this->mLightingConditions == LIGHTING_MORNING )
          return;
        this->mLightingConditions = LIGHTING_MORNING;
        v6 = "setMorningLighting";
      }
      Scaleform::GFx::Movie::Invoke(pObject, v6, 0i64, 0i64, 0);
    }
  }
}

