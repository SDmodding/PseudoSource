// File Line: 35
// RVA: 0x156D550
__int64 UFG::_dynamic_initializer_for__UI_HASH_SNIPER__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SNIPER", 0xFFFFFFFF);
  UI_HASH_SNIPER = result;
  return result;
}

// File Line: 46
// RVA: 0x5CD530
void __fastcall UFG::UIHKSniperWidget::~UIHKSniperWidget(UFG::UIHKSniperWidget *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax

  this->vfptr = (UFG::UIHKSniperWidgetVtbl *)&UFG::UIHKSniperWidget::`vftable;
  v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v1 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Hide(&v1->HelpBar, UI_HASH_SNIPER);
}

// File Line: 52
// RVA: 0x5D7CD0
void __fastcall UFG::UIHKSniperWidget::Exit(UFG::UIHKSniperWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKScreenGlobalOverlay *v4; // rax
  Scaleform::GFx::Movie *pObject; // rcx

  if ( (unsigned int)(this->mState - 1) <= 1 )
  {
    v4 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v4 = &gGlobalOverlaySentinel;
    UFG::UIHKHelpBarWidget::Hide(&v4->HelpBar, UI_HASH_SNIPER);
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
      Scaleform::GFx::Movie::Invoke(pObject, "SniperRifle_Outro", 0i64, 0i64, 0);
    this->mState = STATE_FOUND_SIGNAL;
  }
}

// File Line: 68
// RVA: 0x617570
void __fastcall UFG::UIHKSniperWidget::Update(UFG::UIHKSniperWidget *this, UFG::UIScreen *screen)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimComponentHolder *p; // rax
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimObjectGame *v7; // r8
  __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfType; // rax

  LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer
    && (p = LocalPlayer->m_Components.p, (m_pComponent = p[20].m_pComponent) != 0i64)
    && p[7].m_pComponent
    && (v7 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 25i64)
                                    + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                    + 40)) != 0i64
    && (m_Flags = v7->m_Flags, (m_Flags & 0x4000) == 0)
    && m_Flags >= 0
    && ((m_Flags & 0x2000) == 0
      ? ((m_Flags & 0x1000) == 0
       ? (ComponentOfType = UFG::SimObject::GetComponentOfType(v7, UFG::InventoryItemComponent::_TypeUID))
       : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::InventoryItemComponent::_TypeUID)))
      : (ComponentOfType = v7->m_Components.p[11].m_pComponent),
        ComponentOfType) )
  {
    this->mSniperMode = 0;
  }
  else
  {
    UFG::UIHKSniperWidget::Exit(this, screen);
  }
}

// File Line: 132
// RVA: 0x5EAED0
void __fastcall UFG::UIHKSniperWidget::HandleMessage(
        UFG::UIHKSniperWidget *this,
        UFG::UIScreen *screen,
        unsigned int msgId)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  if ( this->mState == STATE_LOOKING_FOR_SIGNAL )
  {
    this->mState = STATE_SETTING;
  }
  else if ( this->mState == STATE_FOUND_SIGNAL )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      value.pObjectInterface = 0i64;
      value.Type = VT_Boolean;
      value.mValue.BValue = 0;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_SniperRifleOverlay._visible", &value, 1i64);
      this->mState = STATE_HIDE;
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_Undefined;
    }
  }
}

