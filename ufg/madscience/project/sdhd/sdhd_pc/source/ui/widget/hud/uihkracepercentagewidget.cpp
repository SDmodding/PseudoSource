// File Line: 49
// RVA: 0x616530
void __fastcall UFG::UIHKRacePercentageWidget::Update(UFG::UIHKRacePercentageWidget *this, UFG::UIScreen *screen)
{
  signed __int16 m_Flags; // r8
  UFG::CharacterOccupantComponent *m_pComponent; // rax
  UFG::SimObjectGame *CurrentVehicle; // rax
  __int16 v7; // dx
  UFG::RoadSpaceComponent *ComponentOfTypeHK; // rax
  float FractionRaceComplete; // xmm0_4
  float v10; // xmm0_4
  bool v11; // al
  bool v12; // zf

  if ( screen && LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent;
    else
      m_pComponent = (UFG::CharacterOccupantComponent *)(m_Flags < 0
                                                      || (m_Flags & 0x2000) != 0
                                                      || (m_Flags & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           LocalPlayer,
                                                           UFG::CharacterOccupantComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           LocalPlayer,
                                                           UFG::CharacterOccupantComponent::_TypeUID));
    if ( m_pComponent )
    {
      CurrentVehicle = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(m_pComponent);
      if ( CurrentVehicle )
      {
        v7 = CurrentVehicle->m_Flags;
        if ( (v7 & 0x4000) != 0 )
        {
          ComponentOfTypeHK = (UFG::RoadSpaceComponent *)CurrentVehicle->m_Components.p[24].m_pComponent;
        }
        else if ( v7 >= 0 )
        {
          if ( (v7 & 0x2000) != 0 || (v7 & 0x1000) != 0 )
            ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             CurrentVehicle,
                                                             UFG::RoadSpaceComponent::_TypeUID);
          else
            ComponentOfTypeHK = (UFG::RoadSpaceComponent *)UFG::SimObject::GetComponentOfType(
                                                             CurrentVehicle,
                                                             UFG::RoadSpaceComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::RoadSpaceComponent *)CurrentVehicle->m_Components.p[24].m_pComponent;
        }
        if ( ComponentOfTypeHK )
        {
          FractionRaceComplete = UFG::RoadSpaceComponent::GetFractionRaceComplete(ComponentOfTypeHK);
          if ( FractionRaceComplete >= 0.0 )
            v10 = FractionRaceComplete * 100.0;
          else
            v10 = 0.0;
          v11 = this->mPercentageDone != (int)v10;
          v12 = !v11 && !this->mChanged;
          this->mChanged |= v11;
          if ( !v12 )
          {
            this->mPercentageDone = (int)v10;
            this->mChanged = 0;
            UFG::UIHKRacePercentageWidget::Flash_SetVisible(this, screen);
            UFG::UIHKRacePercentageWidget::Flash_SetPercentageDone(this, screen);
          }
        }
      }
    }
  }
}

// File Line: 96
// RVA: 0x5E1B00
void __fastcall UFG::UIHKRacePercentageWidget::Flash_SetVisible(
        UFG::UIHKRacePercentageWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  bool mVisible; // di
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_Undefined;
    mVisible = this->mVisible;
    value.Type = VT_Boolean;
    value.mValue.BValue = mVisible;
    Scaleform::GFx::Movie::SetVariable(pObject, "_root.mc_RaceHUD.mc_PctDone._visible", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

// File Line: 108
// RVA: 0x5E04D0
void __fastcall UFG::UIHKRacePercentageWidget::Flash_SetPercentageDone(
        UFG::UIHKRacePercentageWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Value::ValueUnion v4; // xmm6_8
  Scaleform::GFx::Movie *pObject; // rcx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h] BYREF

  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v4.NValue = (double)(int)this->mPercentageDone;
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Number;
  pargs.mValue = v4;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "Race_SetPercentageDone", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

