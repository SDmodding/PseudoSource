// File Line: 30
// RVA: 0x613CE0
void __fastcall UFG::UIHKDirectionalDamageWidget::Update(UFG::UIHKDirectionalDamageWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIHKDirectionalDamageWidget *v3; // rbx
  Scaleform::GFx::Movie *v4; // r15
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // r14
  UFG::SimComponent *v7; // rax
  signed int v8; // esi
  bool *v9; // rdi
  signed __int64 v10; // r12
  float v11; // xmm0_4
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-48h]

  v3 = this;
  if ( UFG::UIHKTweakables::ShowDirectionalDamage )
  {
    v4 = screen->mRenderable->m_movie.pObject;
    if ( v4 )
    {
      if ( LocalPlayer )
      {
        v5 = LocalPlayer->m_Flags;
        if ( (v5 >> 14) & 1 )
        {
          v6 = LocalPlayer->m_Components.p[6].m_pComponent;
        }
        else if ( (v5 & 0x8000u) == 0 )
        {
          if ( (v5 >> 13) & 1 )
            v7 = UFG::SimObjectGame::GetComponentOfTypeHK(
                   (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                   UFG::HealthComponent::_TypeUID);
          else
            v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                    UFG::HealthComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                        (UFG::SimObject *)&LocalPlayer->vfptr,
                                                                        UFG::HealthComponent::_TypeUID);
          v6 = v7;
        }
        else
        {
          v6 = LocalPlayer->m_Components.p[6].m_pComponent;
        }
        if ( v6 )
        {
          pargs.pObjectInterface = 0i64;
          pargs.Type = 0;
          v8 = 0;
          v9 = v3->mTweakFakeAttackDir;
          v10 = (char *)v6 - (char *)v3;
          do
          {
            if ( v3->mDDTimers[0].bActive )
            {
              v11 = elapsed + v3->mDDTimers[0].fElapsedTime;
              v3->mDDTimers[0].fElapsedTime = v11;
              if ( v11 > UFG::UIHKTweakables::DirectionalDamageDuration )
              {
                v3->mDDTimers[0].bActive = 0;
                if ( ((unsigned int)pargs.Type >> 6) & 1 )
                {
                  (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
                    pargs.pObjectInterface,
                    &pargs,
                    *(_QWORD *)&pargs.mValue.NValue);
                  pargs.pObjectInterface = 0i64;
                }
                pargs.Type = 5;
                pargs.mValue.NValue = (double)v8;
                Scaleform::GFx::Movie::Invoke(v4, "mc_fullscreenFX.ScreenFX_HideDirectionalDamage", 0i64, &pargs, 1u);
              }
            }
            if ( v9[v10 + 232] || *v9 )
            {
              *v9 = 0;
              v3->mDDTimers[0].bActive = 1;
              v3->mDDTimers[0].fElapsedTime = 0.0;
              if ( ((unsigned int)pargs.Type >> 6) & 1 )
              {
                (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
                  pargs.pObjectInterface,
                  &pargs,
                  *(_QWORD *)&pargs.mValue.NValue);
                pargs.pObjectInterface = 0i64;
              }
              pargs.Type = 5;
              pargs.mValue.NValue = (double)v8;
              Scaleform::GFx::Movie::Invoke(v4, "mc_fullscreenFX.ScreenFX_ShowDirectionalDamage", 0i64, &pargs, 1u);
            }
            ++v8;
            ++v9;
            v3 = (UFG::UIHKDirectionalDamageWidget *)((char *)v3 + 8);
          }
          while ( (unsigned int)v8 < 4 );
          UFG::qMemSet(&v6[4].m_SafePointerList, 0, 4u);
          if ( ((unsigned int)pargs.Type >> 6) & 1 )
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
              pargs.pObjectInterface,
              &pargs,
              *(_QWORD *)&pargs.mValue.NValue);
        }
      }
    }
  }
}

