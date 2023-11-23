// File Line: 30
// RVA: 0x613CE0
void __fastcall UFG::UIHKDirectionalDamageWidget::Update(
        UFG::UIHKDirectionalDamageWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  Scaleform::GFx::Movie *pObject; // r15
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r14
  UFG::SimComponent *v7; // rax
  int v8; // esi
  bool *mTweakFakeAttackDir; // rdi
  signed __int64 v10; // r12
  float v11; // xmm0_4
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-48h] BYREF

  if ( UFG::UIHKTweakables::ShowDirectionalDamage )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      if ( LocalPlayer )
      {
        m_Flags = LocalPlayer->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = LocalPlayer->m_Components.p[6].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
             ? UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::HealthComponent::_TypeUID)
             : UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::HealthComponent::_TypeUID);
          m_pComponent = v7;
        }
        else
        {
          m_pComponent = LocalPlayer->m_Components.p[6].m_pComponent;
        }
        if ( m_pComponent )
        {
          pargs.pObjectInterface = 0i64;
          pargs.Type = VT_Undefined;
          v8 = 0;
          mTweakFakeAttackDir = this->mTweakFakeAttackDir;
          v10 = (char *)m_pComponent - (char *)this;
          do
          {
            if ( this->mDDTimers[0].bActive )
            {
              v11 = elapsed + this->mDDTimers[0].fElapsedTime;
              this->mDDTimers[0].fElapsedTime = v11;
              if ( v11 > UFG::UIHKTweakables::DirectionalDamageDuration )
              {
                this->mDDTimers[0].bActive = 0;
                if ( (pargs.Type & 0x40) != 0 )
                {
                  (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
                    pargs.pObjectInterface,
                    &pargs,
                    pargs.mValue);
                  pargs.pObjectInterface = 0i64;
                }
                pargs.Type = VT_Number;
                pargs.mValue.NValue = (double)v8;
                Scaleform::GFx::Movie::Invoke(
                  pObject,
                  "mc_fullscreenFX.ScreenFX_HideDirectionalDamage",
                  0i64,
                  &pargs,
                  1u);
              }
            }
            if ( mTweakFakeAttackDir[v10 + 232] || *mTweakFakeAttackDir )
            {
              *mTweakFakeAttackDir = 0;
              this->mDDTimers[0].bActive = 1;
              this->mDDTimers[0].fElapsedTime = 0.0;
              if ( (pargs.Type & 0x40) != 0 )
              {
                (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
                  pargs.pObjectInterface,
                  &pargs,
                  pargs.mValue);
                pargs.pObjectInterface = 0i64;
              }
              pargs.Type = VT_Number;
              pargs.mValue.NValue = (double)v8;
              Scaleform::GFx::Movie::Invoke(pObject, "mc_fullscreenFX.ScreenFX_ShowDirectionalDamage", 0i64, &pargs, 1u);
            }
            ++v8;
            ++mTweakFakeAttackDir;
            this = (UFG::UIHKDirectionalDamageWidget *)((char *)this + 8);
          }
          while ( (unsigned int)v8 < 4 );
          UFG::qMemSet(&m_pComponent[4].m_SafePointerList, 0, 4u);
          if ( (pargs.Type & 0x40) != 0 )
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
              pargs.pObjectInterface,
              &pargs,
              pargs.mValue);
        }
      }
    }
  }
}ObjectInterface,
              &pargs,
   

