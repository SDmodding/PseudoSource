// File Line: 44
// RVA: 0x5E68F0
UFG::UIHKInfoPopupWidget *__fastcall UFG::UIHKInfoPopupWidget::Get()
{
  return UFG::UIHKScreenHud::InfoPopup;
}

// File Line: 50
// RVA: 0x614990
void __fastcall UFG::UIHKInfoPopupWidget::Update(UFG::UIHKInfoPopupWidget *this, UFG::UIScreen *screen, float elapsed)
{
  __int32 v5; // ecx
  __int32 v6; // ecx
  __int32 v7; // ecx
  Scaleform::GFx::Movie *pObject; // rcx
  bool v9; // zf
  float v10; // xmm0_4
  float v11; // xmm0_4
  char *mData; // r8
  char *v13; // rax
  Scaleform::GFx::Movie *v14; // rcx
  const char *v15; // rdx
  Scaleform::GFx::Movie *v16; // rcx

  v5 = this->mState - 1;
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      v7 = v6 - 1;
      if ( v7 )
      {
        if ( v7 == 1 )
        {
          this->mState = STATE_OUTGOING_CALL;
          if ( screen )
          {
            pObject = screen->mRenderable->m_movie.pObject;
            if ( pObject )
              Scaleform::GFx::Movie::Invoke(pObject, "InfoFlasher_Hide", 0i64, 0i64, 0);
          }
        }
      }
      else
      {
        v9 = !this->mInfinite;
        v10 = this->mTimeout - elapsed;
        this->mTimeout = v10;
        if ( v9 && v10 <= 0.0 )
        {
          this->mState = STATE_INCOMING_CALL;
        }
        else if ( this->mShowHintReminder )
        {
          v11 = this->mHintReminderTimeout - elapsed;
          this->mHintReminderTimeout = v11;
          if ( v11 <= 0.0 )
            this->mHintReminderTimeout = UFG::UIHKInfoPopupWidget::gHintReminderPeriod;
        }
      }
    }
    else
    {
      this->mState = STATE_TEXT_INBOX;
    }
  }
  else
  {
    mData = this->mCaption.mData;
    this->mState = STATE_PHONE_CONTACTS;
    UFG::UIHKInfoPopupWidget::Flash_SetCaption(this, screen, mData);
    v13 = UFG::UIHKInfoPopupWidget::ConvertTypeToString(this, &this->mType);
    UFG::UIHKInfoPopupWidget::Flash_SetType(this, screen, v13);
    if ( screen )
    {
      v14 = screen->mRenderable->m_movie.pObject;
      if ( v14 )
      {
        v15 = "InfoFlasher_SetDefaultPos";
        if ( (unsigned int)(this->mPosition - 1) <= 1 )
          v15 = "InfoFlasher_SetPurchasePos";
        Scaleform::GFx::Movie::Invoke(v14, v15, 0i64, 0i64, 0);
      }
      v16 = screen->mRenderable->m_movie.pObject;
      if ( v16 )
        Scaleform::GFx::Movie::Invoke(v16, "InfoFlasher_Show", 0i64, 0i64, 0);
    }
    if ( this->mType.mUID == qSymbol_Collectible_HealthShrine_20.mUID && !this->HealthShrineUpgradeProgress )
      UFG::UIHKInfoPopupWidget::Flash_ShowHealthUpgrade(this, screen);
  }
}

// File Line: 128
// RVA: 0x5F41F0
void __fastcall UFG::UIHKInfoPopupWidget::PlayWidgetSFX(UFG::UIHKInfoPopupWidget *this, UFG::qSymbol *type)
{
  unsigned int mUID; // eax
  unsigned int v3; // edx

  mUID = type->mUID;
  if ( type->mUID != qSymbol_Collectible_HealthShrine_20.mUID )
  {
    if ( mUID == qSymbol_Collectible_LockBox_20.mUID )
    {
      if ( !UFG::HudAudio::m_instance )
        return;
      v3 = 912326249;
    }
    else if ( mUID == qSymbol_Upgrade_Melee_20.mUID )
    {
      if ( !UFG::HudAudio::m_instance )
        return;
      v3 = -1311300124;
    }
    else if ( mUID == qSymbol_Collectible_Jump_20.mUID )
    {
      if ( !UFG::HudAudio::m_instance )
        return;
      v3 = -9771139;
    }
    else
    {
      if ( !UFG::HudAudio::m_instance )
        return;
      v3 = -952868575;
    }
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v3, 0i64, 0, 0i64);
  }
}

// File Line: 158
// RVA: 0x60D100
void __fastcall UFG::UIHKInfoPopupWidget::Show(
        UFG::UIHKInfoPopupWidget *this,
        const char *caption,
        UFG::qSymbol *type,
        float duration,
        UFG::UIHKInfoPopupWidget::ePosition pos)
{
  UFG::UIHKInfoPopupWidget::PlayWidgetSFX(this, type);
  this->mChanged = 1;
  UFG::qString::Set(&this->mCaption, caption);
  this->mType = (UFG::qSymbol)type->mUID;
  this->mTimeout = duration;
  this->mPosition = pos;
  this->mShowHintReminder = 0;
  this->mInfinite = duration < 1.0;
  this->mState = STATE_ROOT_MENU;
}

// File Line: 175
// RVA: 0x5ECBD0
void __fastcall UFG::UIHKInfoPopupWidget::Hide(UFG::UIHKInfoPopupWidget *this)
{
  UFG::UIHKInfoPopupWidget::eState mState; // eax

  mState = this->mState;
  if ( mState )
  {
    if ( mState != STATE_OUTGOING_CALL )
      this->mState = STATE_INCOMING_CALL;
  }
}

// File Line: 182
// RVA: 0x610F20
void __fastcall UFG::UIHKInfoPopupWidget::ShowPurchaseInfo(
        UFG::UIHKInfoPopupWidget *this,
        const char *itemName,
        const char *itemDesc,
        unsigned int itemPrice,
        UFG::qSymbol *type)
{
  const char *v7; // rbx
  const char *v9; // rbp
  unsigned int v10; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v12; // rsi
  unsigned int v13; // eax
  UFG::UIGfxTranslator *v14; // rcx
  const char *v15; // rbx
  const char *v16; // rdi
  unsigned int v17; // eax
  UFG::UIGfxTranslator *v18; // rcx
  char *v19; // rax
  char Key; // al
  const char *v21; // r8
  char *mData; // rbx
  UFG::qString v23; // [rsp+38h] [rbp-40h] BYREF

  v7 = itemName;
  if ( itemName )
  {
    if ( *itemName == 36 )
      v7 = itemName + 1;
    v10 = UFG::qStringHashUpper32(v7, -1);
    m_translator = UFG::UIScreenManager::s_instance->m_translator;
    if ( !m_translator || (v9 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v10)) == 0i64 )
      v9 = v7;
  }
  else
  {
    v9 = 0i64;
  }
  if ( itemDesc )
  {
    if ( *itemDesc == 36 )
      ++itemDesc;
    v13 = UFG::qStringHashUpper32(itemDesc, -1);
    v14 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v14 || (v12 = (const char *)v14->vfptr[5].__vecDelDtor(v14, v13)) == 0i64 )
      v12 = itemDesc;
  }
  else
  {
    v12 = 0i64;
  }
  if ( type->mUID == qSymbol_Extortion_20.mUID )
  {
    v15 = "$COMMON_EXTORT_BUTTON";
  }
  else
  {
    v15 = "$COMMON_BRIBE_BUTTON";
    if ( type->mUID != qSymbol_Bribe_20.mUID )
      v15 = "$COMMON_PURCHASE_BUTTON";
  }
  if ( v15 )
  {
    if ( *v15 == 36 )
      ++v15;
    v17 = UFG::qStringHashUpper32(v15, -1);
    v18 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v18 || (v16 = (const char *)v18->vfptr[5].__vecDelDtor(v18, v17)) == 0i64 )
      v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  UFG::qString::qString(&v23);
  if ( itemPrice )
    UFG::qString::Format(
      &v23,
      "%s<br>%s<br><br><img src=Icon_Global_Money width=26 height=26 vspace=-16> HK $%d<br>%s",
      v9,
      v12,
      itemPrice,
      v16);
  else
    UFG::qString::Format(&v23, "%s<br>%s<br><br>%s", v9, v12, v16);
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v19 = &customCaption;
    if ( REMAP_ID_ACTION_2 != REMAP_ID_INVALID_2 )
    {
      Key = UFG::UIHKScreenOptionsButtonMapping::GetKey(REMAP_ID_ACTION_2);
      v19 = (char *)UFG::KeyToTextureName(Key);
    }
    v21 = "BUTTON_E";
    if ( *v19 )
      v21 = v19;
    UFG::qString::ReplaceString(&v23, "BUTTON_BUTTON2", v21, 0);
  }
  mData = v23.mData;
  UFG::UIHKInfoPopupWidget::PlayWidgetSFX(this, type);
  this->mChanged = 1;
  UFG::qString::Set(&this->mCaption, mData);
  this->mType = (UFG::qSymbol)type->mUID;
  *(_QWORD *)&this->mPosition = 1i64;
  *(_WORD *)&this->mInfinite = 1;
  this->mState = STATE_ROOT_MENU;
  UFG::qString::~qString(&v23);
}

// File Line: 221
// RVA: 0x611540
void __fastcall UFG::UIHKInfoPopupWidget::ShowTutorialPrompt(UFG::UIHKInfoPopupWidget *this, const char *caption)
{
  unsigned int v4; // edx

  if ( qSymbol_none_20.mUID != qSymbol_Collectible_HealthShrine_20.mUID )
  {
    if ( qSymbol_none_20.mUID == qSymbol_Collectible_LockBox_20.mUID )
    {
      if ( UFG::HudAudio::m_instance )
      {
        v4 = 912326249;
LABEL_13:
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v4, 0i64, 0, 0i64);
      }
    }
    else if ( qSymbol_none_20.mUID == qSymbol_Upgrade_Melee_20.mUID )
    {
      if ( UFG::HudAudio::m_instance )
      {
        v4 = -1311300124;
        goto LABEL_13;
      }
    }
    else if ( qSymbol_none_20.mUID == qSymbol_Collectible_Jump_20.mUID )
    {
      if ( UFG::HudAudio::m_instance )
      {
        v4 = -9771139;
        goto LABEL_13;
      }
    }
    else if ( UFG::HudAudio::m_instance )
    {
      v4 = -952868575;
      goto LABEL_13;
    }
  }
  this->mChanged = 1;
  UFG::qString::Set(&this->mCaption, caption);
  this->mType.mUID = qSymbol_none_20.mUID;
  *(_QWORD *)&this->mPosition = 2i64;
  *(_WORD *)&this->mInfinite = 1;
  this->mState = STATE_ROOT_MENU;
}

// File Line: 227
// RVA: 0x610880
void __fastcall UFG::UIHKInfoPopupWidget::ShowHintReminder(UFG::UIHKInfoPopupWidget *this)
{
  this->mShowHintReminder = 1;
  this->mHintReminderTimeout = 0.0;
}

// File Line: 254
// RVA: 0x5DFA10
void __fastcall UFG::UIHKInfoPopupWidget::Flash_SetCaption(
        UFG::UIHKInfoPopupWidget *this,
        UFG::UIScreen *screen,
        const char *caption)
{
  Scaleform::GFx::Movie *pObject; // rbx
  const char *v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-60h] BYREF
  Scaleform::GFx::Value value; // [rsp+50h] [rbp-38h] BYREF

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      v4 = UFG::UI::LocalizeText(caption);
      UFG::qString::qString(&v5, v4);
      value.pObjectInterface = 0i64;
      value.Type = VT_String;
      value.mValue.pString = v5.mData;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_infoFlasher.mc_inner.mc_text.tf_text.htmlText", &value, 1i64);
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_Undefined;
      UFG::qString::~qString(&v5);
    }
  }
}

// File Line: 287
// RVA: 0x5E1890
void __fastcall UFG::UIHKInfoPopupWidget::Flash_SetType(
        UFG::UIHKInfoPopupWidget *this,
        UFG::UIScreen *screen,
        const char *type)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = VT_String;
      pargs.mValue.pString = type;
      Scaleform::GFx::Movie::Invoke(pObject, "InfoFlasher_SetType", 0i64, &pargs, 1u);
      if ( (pargs.Type & 0x40) != 0 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
    }
  }
}

// File Line: 328
// RVA: 0x5E49B0
void __fastcall UFG::UIHKInfoPopupWidget::Flash_ShowHealthUpgrade(
        UFG::UIHKInfoPopupWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
      Scaleform::GFx::Movie::Invoke(pObject, "healthupgrade_Show", 0i64, 0i64, 0);
  }
}

// File Line: 338
// RVA: 0x5D5C70
char *__fastcall UFG::UIHKInfoPopupWidget::ConvertTypeToString(UFG::UIHKInfoPopupWidget *this, UFG::qSymbol *type)
{
  unsigned int mUID; // eax
  char *result; // rax
  bool v4; // zf

  mUID = type->mUID;
  if ( type->mUID == qSymbol_Default_20.mUID )
    return &customCaption;
  if ( mUID == qSymbol_Hint_20.mUID )
    return "Hint";
  if ( mUID == qSymbol_Collectible_HealthShrine_20.mUID )
    return "Icon_Collectible_HealthShrine";
  if ( mUID == qSymbol_Collectible_LockBox_20.mUID )
    return "Icon_Collectible_LockBox";
  if ( mUID == qSymbol_Collectible_SecurityCamera_20.mUID )
    return "Icon_Collectible_SecurityCamera";
  if ( mUID == qSymbol_Collectible_Jump_20.mUID )
    return "Icon_Collectible_Jump";
  if ( mUID == qSymbol_Upgrade_Melee_20.mUID )
    return "Icon_HUD_UpgradeMelee";
  if ( mUID == qSymbol_Upgrade_Gun_20.mUID )
    return "Icon_HUD_UpgradeShooting";
  if ( mUID == qSymbol_Case_20.mUID )
    return "Icon_HUD_Cases";
  if ( mUID == qSymbol_Favour_20.mUID )
    return "Icon_Favour";
  if ( mUID == qSymbol_Chat_20.mUID )
    return "Icon_Social_Chat";
  if ( mUID == qSymbol_Food_20.mUID )
    return "Icon_SocialPurchase_Food";
  if ( mUID == qSymbol_Tea_20.mUID )
    return "Icon_SocialPurchase_Tea";
  if ( mUID == qSymbol_Massage_20.mUID )
    return "Icon_SocialPurchase_Massage";
  if ( mUID == qSymbol_Clothing_20.mUID )
    return "Icon_SocialPurchase_Outfit";
  if ( mUID == qSymbol_Weapon_20.mUID )
    return "Icon_SocialPurchase_Weapon";
  if ( mUID == qSymbol_Extortion_20.mUID )
    return "Icon_Social_Intimidate";
  if ( mUID == qSymbol_Purchase_20.mUID )
    return "Icon_Social_Purchase";
  if ( mUID == qSymbol_Bribe_20.mUID )
    return "Icon_Social_Bribe";
  v4 = mUID == qSymbol_Drink_20.mUID;
  result = "Icon_SocialPurchase_Food";
  if ( !v4 )
    return "Default";
  return result;
}

