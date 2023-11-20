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
  UFG::UIScreen *v2; // rdi
  UFG::UIHKSniperWidget *v3; // rbx
  UFG::UIHKScreenGlobalOverlay *v4; // rax
  Scaleform::GFx::Movie *v5; // rcx

  v2 = screen;
  v3 = this;
  if ( (unsigned int)(this->mState - 1) <= 1 )
  {
    v4 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v4 = &gGlobalOverlaySentinel;
    UFG::UIHKHelpBarWidget::Hide(&v4->HelpBar, UI_HASH_SNIPER);
    v5 = v2->mRenderable->m_movie.pObject;
    if ( v5 )
      Scaleform::GFx::Movie::Invoke(v5, "SniperRifle_Outro", 0i64, 0i64, 0);
    v3->mState = 3;
  }
}

// File Line: 68
// RVA: 0x617570
void __fastcall UFG::UIHKSniperWidget::Update(UFG::UIHKSniperWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rdi
  UFG::UIHKSniperWidget *v3; // rbx
  UFG::SimObjectCharacter *v4; // rax
  UFG::SimComponentHolder *v5; // rax
  UFG::SimComponent *v6; // rdx
  UFG::SimObjectGame *v7; // r8
  unsigned __int16 v8; // cx
  UFG::SimComponent *v9; // rax

  v2 = screen;
  v3 = this;
  v4 = UFG::GetLocalPlayer();
  if ( v4
    && (v5 = v4->m_Components.p, (v6 = v5[20].m_pComponent) != 0i64)
    && v5[7].m_pComponent
    && (v7 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + 25i64)
                                    + *(_QWORD *)&v6[1].m_TypeUID
                                    + 40)) != 0i64
    && (v8 = v7->m_Flags, !((v8 >> 14) & 1))
    && (v8 & 0x8000u) == 0
    && (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v9 = UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v7->vfptr,
                                                         UFG::InventoryItemComponent::_TypeUID)) : (v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::InventoryItemComponent::_TypeUID))) : (v9 = v7->m_Components.p[11].m_pComponent),
        v9) )
  {
    v3->mSniperMode = 0;
  }
  else
  {
    UFG::UIHKSniperWidget::Exit(v3, v2);
  }
}

// File Line: 132
// RVA: 0x5EAED0
void __fastcall UFG::UIHKSniperWidget::HandleMessage(UFG::UIHKSniperWidget *this, UFG::UIScreen *screen, unsigned int msgId)
{
  UFG::UIHKSniperWidget *v3; // rbx
  Scaleform::GFx::Movie *v4; // rdi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v3 = this;
  if ( this->mState == 2 )
  {
    this->mState = 1;
  }
  else if ( this->mState == 3 )
  {
    v4 = screen->mRenderable->m_movie.pObject;
    if ( v4 )
    {
      value.pObjectInterface = 0i64;
      value.Type = 0;
      value.Type = 2;
      value.mValue.BValue = 0;
      Scaleform::GFx::Movie::SetVariable(v4, "mc_SniperRifleOverlay._visible", &value, 1i64);
      v3->mState = 0;
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 0;
    }
  }
}

