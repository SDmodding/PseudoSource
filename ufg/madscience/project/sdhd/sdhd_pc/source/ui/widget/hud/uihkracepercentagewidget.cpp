// File Line: 49
// RVA: 0x616530
void __fastcall UFG::UIHKRacePercentageWidget::Update(UFG::UIHKRacePercentageWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKRacePercentageWidget *v2; // rbx
  UFG::UIScreen *v3; // rdi
  unsigned __int16 v4; // r8
  UFG::CharacterOccupantComponent *v5; // rax
  UFG::SimObjectGame *v6; // rax
  unsigned __int16 v7; // dx
  UFG::RoadSpaceComponent *v8; // rax
  float v9; // xmm0_4
  float v10; // xmm0_4
  bool v11; // al
  bool v12; // zf

  if ( screen )
  {
    v2 = this;
    v3 = screen;
    if ( LocalPlayer )
    {
      v4 = LocalPlayer->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent;
      }
      else if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
          v5 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                    UFG::CharacterOccupantComponent::_TypeUID);
        else
          v5 = (UFG::CharacterOccupantComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                                      UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID));
      }
      else
      {
        v5 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                  UFG::CharacterOccupantComponent::_TypeUID);
      }
      if ( v5 )
      {
        v6 = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v5);
        if ( v6 )
        {
          v7 = v6->m_Flags;
          if ( (v7 >> 14) & 1 )
          {
            v8 = (UFG::RoadSpaceComponent *)v6->m_Components.p[24].m_pComponent;
          }
          else if ( (v7 & 0x8000u) == 0 )
          {
            if ( (v7 >> 13) & 1 )
              v8 = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                v6,
                                                UFG::RoadSpaceComponent::_TypeUID);
            else
              v8 = (UFG::RoadSpaceComponent *)((v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v6,
                                                                  UFG::RoadSpaceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::RoadSpaceComponent::_TypeUID));
          }
          else
          {
            v8 = (UFG::RoadSpaceComponent *)v6->m_Components.p[24].m_pComponent;
          }
          if ( v8 )
          {
            v9 = UFG::RoadSpaceComponent::GetFractionRaceComplete(v8);
            if ( v9 >= 0.0 )
              v10 = v9 * 100.0;
            else
              v10 = 0.0;
            v11 = v2->mPercentageDone != (signed int)v10;
            v12 = (v11 || v2->mChanged) == 0;
            v2->mChanged |= v11;
            if ( !v12 )
            {
              v2->mPercentageDone = (signed int)v10;
              v2->mChanged = 0;
              UFG::UIHKRacePercentageWidget::Flash_SetVisible(v2, v3);
              UFG::UIHKRacePercentageWidget::Flash_SetPercentageDone(v2, v3);
            }
          }
        }
      }
    }
  }
}

// File Line: 96
// RVA: 0x5E1B00
void __fastcall UFG::UIHKRacePercentageWidget::Flash_SetVisible(UFG::UIHKRacePercentageWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // rbx
  bool v3; // di
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v2 = screen->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 0;
    v3 = this->mVisible;
    value.Type = 2;
    value.mValue.BValue = v3;
    Scaleform::GFx::Movie::SetVariable(v2, "_root.mc_RaceHUD.mc_PctDone._visible", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

// File Line: 108
// RVA: 0x5E04D0
void __fastcall UFG::UIHKRacePercentageWidget::Flash_SetPercentageDone(UFG::UIHKRacePercentageWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rdi
  UFG::UIHKRacePercentageWidget *v3; // rbx
  double v4; // xmm6_8
  Scaleform::GFx::Movie *v5; // rcx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h]

  v2 = screen;
  v3 = this;
  `eh vector constructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v4 = (double)(signed int)v3->mPercentageDone;
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 5;
  pargs.mValue.NValue = v4;
  v5 = v2->mRenderable->m_movie.pObject;
  if ( v5 )
    Scaleform::GFx::Movie::Invoke(v5, "Race_SetPercentageDone", 0i64, &pargs, 1u);
  `eh vector destructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

