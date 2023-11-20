// File Line: 71
// RVA: 0x5EAE60
char __fastcall UFG::UIHKShortcutButtonWidget::HandleMessage(UFG::UIHKShortcutButtonWidget *this, UFG::UIScreen *screen, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIHKShortcutButtonWidget *v4; // rbx
  UFG::UIHKInfoPopupWidget::eState v5; // ecx
  char v6; // al
  UFG::UIHKShortcutButtonWidget::eShortcutType v7; // ecx

  v4 = this;
  if ( this->mState != 2 || msgId != this->mTriggerHash )
    return 0;
  v5 = UFG::UIHKScreenHud::InfoPopup->mState;
  if ( v5 && v5 != STATE_OUTGOING_CALL )
    UFG::UIHKScreenHud::InfoPopup->mState = STATE_INCOMING_CALL;
  if ( v4->mType == 1 )
  {
    v6 = UFG::UI::PauseGame("WorldMap");
    v7 = UFG::UIHKScreenWorldMap::mShortcut;
    if ( v6 )
      v7 = 1;
    UFG::UIHKScreenWorldMap::mShortcut = v7;
  }
  v4->mState = 0;
  return 1;
}

// File Line: 81
// RVA: 0x5D1140
void __fastcall UFG::UIHKShortcutButtonWidget::Activate(UFG::UIHKShortcutButtonWidget *this, UFG::UIHKShortcutButtonWidget::eShortcutType type, UFG::UI::eButtons button, const char *caption, float timeout)
{
  unsigned int v5; // eax
  const char *v6; // rsi
  UFG::UIHKShortcutButtonWidget *v7; // rdi
  UFG::UIHKInfoPopupWidget *v8; // rbx
  unsigned int v9; // edx

  v5 = UI_HASH_BUTTON_SELECT_PRESSED_30;
  this->mButton = button;
  v6 = caption;
  v7 = this;
  this->mTimeout = timeout;
  this->mType = type;
  if ( button == 5 )
    v5 = UI_HASH_BUTTON_START_PRESSED_30;
  this->mTriggerHash = v5;
  v8 = UFG::UIHKScreenHud::InfoPopup;
  if ( qSymbol_Default_20.mUID != qSymbol_Collectible_HealthShrine_20.mUID )
  {
    if ( qSymbol_Default_20.mUID == qSymbol_Collectible_LockBox_20.mUID )
    {
      if ( UFG::HudAudio::m_instance )
      {
        v9 = 912326249;
LABEL_15:
        UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v9, 0i64, 0, 0i64);
        goto LABEL_16;
      }
    }
    else if ( qSymbol_Default_20.mUID == qSymbol_Upgrade_Melee_20.mUID )
    {
      if ( UFG::HudAudio::m_instance )
      {
        v9 = -1311300124;
        goto LABEL_15;
      }
    }
    else if ( qSymbol_Default_20.mUID == qSymbol_Collectible_Jump_20.mUID )
    {
      if ( UFG::HudAudio::m_instance )
      {
        v9 = -9771139;
        goto LABEL_15;
      }
    }
    else if ( UFG::HudAudio::m_instance )
    {
      v9 = -952868575;
      goto LABEL_15;
    }
  }
LABEL_16:
  v8->mChanged = 1;
  UFG::qString::Set(&v8->mCaption, v6);
  v8->mType.mUID = qSymbol_Default_20.mUID;
  v8->mPosition = 0;
  v8->mShowHintReminder = 0;
  v8->mTimeout = timeout;
  v8->mState = 1;
  v8->mInfinite = timeout < 1.0;
  v7->mState = 1;
}

