// File Line: 24
// RVA: 0x6182D0
void __fastcall UFG::UIHKTimeOfDayWidget::Update(UFG::UIHKTimeOfDayWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rdi
  UFG::UIHKTimeOfDayWidget *v3; // rbx
  Scaleform::GFx::Movie *v4; // rdi
  __int128 v5; // xmm0
  const char *v6; // rdx

  v2 = screen;
  v3 = this;
  if ( UFG::TimeOfDayManager::GetInstance() )
  {
    v4 = v2->mRenderable->m_movie.pObject;
    if ( v4 )
    {
      v5 = LODWORD(UFG::TimeOfDayManager::GetInstance()->m_SecondsSinceMidnight);
      if ( *(float *)&v5 >= 64800.0 || *(float *)&v5 < 19800.0 )
      {
        if ( v3->mLightingConditions == 3 )
          return;
        v3->mLightingConditions = 3;
        v6 = "setEveningLighting";
      }
      else if ( *(float *)&v5 >= 43200.0 )
      {
        if ( v3->mLightingConditions == 2 )
          return;
        v3->mLightingConditions = 2;
        v6 = "setAfternoonLighting";
      }
      else
      {
        if ( v3->mLightingConditions == 1 )
          return;
        v3->mLightingConditions = 1;
        v6 = "setMorningLighting";
      }
      Scaleform::GFx::Movie::Invoke(v4, v6, 0i64, 0i64, 0);
    }
  }
}

