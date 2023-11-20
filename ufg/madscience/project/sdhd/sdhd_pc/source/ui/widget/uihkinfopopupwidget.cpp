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
  UFG::UIHKInfoPopupWidget *v3; // rbx
  UFG::UIScreen *v4; // rdi
  __int32 v5; // ecx
  int v6; // ecx
  int v7; // ecx
  Scaleform::GFx::Movie *v8; // rcx
  bool v9; // zf
  float v10; // xmm0_4
  float v11; // xmm0_4
  const char *v12; // r8
  char *v13; // rax
  Scaleform::GFx::Movie *v14; // rcx
  const char *v15; // rdx
  Scaleform::GFx::Movie *v16; // rcx

  v3 = this;
  v4 = screen;
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
          v3->mState = 5;
          if ( screen )
          {
            v8 = screen->mRenderable->m_movie.pObject;
            if ( v8 )
              Scaleform::GFx::Movie::Invoke(v8, "InfoFlasher_Hide", 0i64, 0i64, 0);
          }
        }
      }
      else
      {
        v9 = v3->mInfinite == 0;
        v10 = v3->mTimeout - elapsed;
        v3->mTimeout = v10;
        if ( v9 && v10 <= 0.0 )
        {
          v3->mState = 4;
        }
        else if ( v3->mShowHintReminder )
        {
          v11 = v3->mHintReminderTimeout - elapsed;
          v3->mHintReminderTimeout = v11;
          if ( v11 <= 0.0 )
            v3->mHintReminderTimeout = UFG::UIHKInfoPopupWidget::gHintReminderPeriod;
        }
      }
    }
    else
    {
      v3->mState = 3;
    }
  }
  else
  {
    v12 = v3->mCaption.mData;
    v3->mState = 2;
    UFG::UIHKInfoPopupWidget::Flash_SetCaption(v3, screen, v12);
    v13 = UFG::UIHKInfoPopupWidget::ConvertTypeToString(v3, &v3->mType);
    UFG::UIHKInfoPopupWidget::Flash_SetType(v3, v4, v13);
    if ( v4 )
    {
      v14 = v4->mRenderable->m_movie.pObject;
      if ( v14 )
      {
        v15 = "InfoFlasher_SetDefaultPos";
        if ( (unsigned int)(v3->mPosition - 1) <= 1 )
          v15 = "InfoFlasher_SetPurchasePos";
        Scaleform::GFx::Movie::Invoke(v14, v15, 0i64, 0i64, 0);
      }
      v16 = v4->mRenderable->m_movie.pObject;
      if ( v16 )
        Scaleform::GFx::Movie::Invoke(v16, "InfoFlasher_Show", 0i64, 0i64, 0);
    }
    if ( v3->mType.mUID == qSymbol_Collectible_HealthShrine_20.mUID && !v3->HealthShrineUpgradeProgress )
      UFG::UIHKInfoPopupWidget::Flash_ShowHealthUpgrade(v3, v4);
  }
}

// File Line: 128
// RVA: 0x5F41F0
void __fastcall UFG::UIHKInfoPopupWidget::PlayWidgetSFX(UFG::UIHKInfoPopupWidget *this, UFG::qSymbol *type)
{
  unsigned int v2; // eax
  unsigned int v3; // edx

  v2 = type->mUID;
  if ( type->mUID != qSymbol_Collectible_HealthShrine_20.mUID )
  {
    if ( v2 == qSymbol_Collectible_LockBox_20.mUID )
    {
      if ( !UFG::HudAudio::m_instance )
        return;
      v3 = 912326249;
    }
    else if ( v2 == qSymbol_Upgrade_Melee_20.mUID )
    {
      if ( !UFG::HudAudio::m_instance )
        return;
      v3 = -1311300124;
    }
    else if ( v2 == qSymbol_Collectible_Jump_20.mUID )
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
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v3, 0i64, 0, 0i64);
  }
}

// File Line: 158
// RVA: 0x60D100
void __fastcall UFG::UIHKInfoPopupWidget::Show(UFG::UIHKInfoPopupWidget *this, const char *caption, UFG::qSymbol *type, float duration, UFG::UIHKInfoPopupWidget::ePosition pos)
{
  const char *v5; // rbx
  UFG::qSymbol *v6; // rdi
  UFG::UIHKInfoPopupWidget *v7; // rsi

  v5 = caption;
  v6 = type;
  v7 = this;
  UFG::UIHKInfoPopupWidget::PlayWidgetSFX(this, type);
  v7->mChanged = 1;
  UFG::qString::Set(&v7->mCaption, v5);
  v7->mType = (UFG::qSymbol)v6->mUID;
  v7->mTimeout = duration;
  v7->mPosition = pos;
  v7->mShowHintReminder = 0;
  v7->mInfinite = duration < 1.0;
  v7->mState = 1;
}

// File Line: 175
// RVA: 0x5ECBD0
void __fastcall UFG::UIHKInfoPopupWidget::Hide(UFG::UIHKInfoPopupWidget *this)
{
  UFG::UIHKInfoPopupWidget::eState v1; // eax

  v1 = this->mState;
  if ( v1 )
  {
    if ( v1 != 5 )
      this->mState = 4;
  }
}

// File Line: 182
// RVA: 0x610F20
void __fastcall UFG::UIHKInfoPopupWidget::ShowPurchaseInfo(UFG::UIHKInfoPopupWidget *this, const char *itemName, const char *itemDesc, unsigned int itemPrice, UFG::qSymbol *type)
{
  unsigned int v5; // er12
  const char *v6; // rdi
  const char *v7; // rbx
  UFG::UIHKInfoPopupWidget *v8; // r14
  __int64 v9; // rbp
  unsigned int v10; // eax
  UFG::UIGfxTranslator *v11; // rcx
  __int64 v12; // rsi
  unsigned int v13; // eax
  UFG::UIGfxTranslator *v14; // rcx
  const char *v15; // rbx
  __int64 v16; // rdi
  unsigned int v17; // eax
  UFG::UIGfxTranslator *v18; // rcx
  char *v19; // rax
  char v20; // al
  const char *v21; // r8
  char *v22; // rbx
  __int64 v23; // [rsp+20h] [rbp-58h]
  UFG::qString v24; // [rsp+38h] [rbp-40h]

  v5 = itemPrice;
  v6 = itemDesc;
  v7 = itemName;
  v8 = this;
  if ( itemName )
  {
    if ( *itemName == 36 )
      v7 = itemName + 1;
    v10 = UFG::qStringHashUpper32(v7, 0xFFFFFFFF);
    v11 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v11 || (v9 = (__int64)v11->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, v10)) == 0 )
      v9 = (__int64)v7;
  }
  else
  {
    v9 = 0i64;
  }
  if ( v6 )
  {
    if ( *v6 == 36 )
      ++v6;
    v13 = UFG::qStringHashUpper32(v6, 0xFFFFFFFF);
    v14 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v14 || (v12 = (__int64)v14->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v14->vfptr, v13)) == 0 )
      v12 = (__int64)v6;
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
    v17 = UFG::qStringHashUpper32(v15, 0xFFFFFFFF);
    v18 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v18 || (v16 = (__int64)v18->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, v17)) == 0 )
      v16 = (__int64)v15;
  }
  else
  {
    v16 = 0i64;
  }
  UFG::qString::qString(&v24);
  if ( v5 )
  {
    LODWORD(v23) = v5;
    UFG::qString::Format(
      &v24,
      "%s<br>%s<br><br><img src='Icon_Global_Money' width='26' height='26' vspace='-16'> HK $%d<br>%s",
      v9,
      v12,
      v23,
      v16,
      -2i64);
  }
  else
  {
    UFG::qString::Format(&v24, "%s<br>%s<br><br>%s", v9, v12, v16);
  }
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v19 = &customWorldMapCaption;
    if ( REMAP_ID_ACTION_2 != REMAP_ID_INVALID_2 )
    {
      v20 = UFG::UIHKScreenOptionsButtonMapping::GetKey(REMAP_ID_ACTION_2);
      v19 = (char *)UFG::KeyToTextureName(v20);
    }
    v21 = "BUTTON_E";
    if ( *v19 )
      v21 = v19;
    UFG::qString::ReplaceString(&v24, "BUTTON_BUTTON2", v21, 0);
  }
  v22 = v24.mData;
  UFG::UIHKInfoPopupWidget::PlayWidgetSFX(v8, type);
  v8->mChanged = 1;
  UFG::qString::Set(&v8->mCaption, v22);
  v8->mType = (UFG::qSymbol)type->mUID;
  *(_QWORD *)&v8->mPosition = 1i64;
  *(_WORD *)&v8->mInfinite = 1;
  v8->mState = 1;
  UFG::qString::~qString(&v24);
}

// File Line: 221
// RVA: 0x611540
void __fastcall UFG::UIHKInfoPopupWidget::ShowTutorialPrompt(UFG::UIHKInfoPopupWidget *this, const char *caption)
{
  const char *v2; // rdi
  UFG::UIHKInfoPopupWidget *v3; // rbx
  unsigned int v4; // edx

  v2 = caption;
  v3 = this;
  if ( qSymbol_none_20.mUID != qSymbol_Collectible_HealthShrine_20.mUID )
  {
    if ( qSymbol_none_20.mUID == qSymbol_Collectible_LockBox_20.mUID )
    {
      if ( UFG::HudAudio::m_instance )
      {
        v4 = 912326249;
LABEL_13:
        UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v4, 0i64, 0, 0i64);
        goto LABEL_14;
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
LABEL_14:
  v3->mChanged = 1;
  UFG::qString::Set(&v3->mCaption, v2);
  v3->mType.mUID = qSymbol_none_20.mUID;
  *(_QWORD *)&v3->mPosition = 2i64;
  *(_WORD *)&v3->mInfinite = 1;
  v3->mState = 1;
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
void __fastcall UFG::UIHKInfoPopupWidget::Flash_SetCaption(UFG::UIHKInfoPopupWidget *this, UFG::UIScreen *screen, const char *caption)
{
  Scaleform::GFx::Movie *v3; // rbx
  const char *v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-60h]
  Scaleform::GFx::Value value; // [rsp+50h] [rbp-38h]

  if ( screen )
  {
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      v4 = UFG::UI::LocalizeText(caption);
      UFG::qString::qString(&v5, v4);
      value.pObjectInterface = 0i64;
      value.Type = 6;
      *(_QWORD *)&value.mValue.NValue = v5.mData;
      Scaleform::GFx::Movie::SetVariable(v3, "mc_infoFlasher.mc_inner.mc_text.tf_text.htmlText", &value, 1i64);
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 0;
      UFG::qString::~qString(&v5);
    }
  }
}

// File Line: 287
// RVA: 0x5E1890
void __fastcall UFG::UIHKInfoPopupWidget::Flash_SetType(UFG::UIHKInfoPopupWidget *this, UFG::UIScreen *screen, const char *type)
{
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  if ( screen )
  {
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = 6;
      *(_QWORD *)&pargs.mValue.NValue = type;
      Scaleform::GFx::Movie::Invoke(v3, "InfoFlasher_SetType", 0i64, &pargs, 1u);
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
    }
  }
}

// File Line: 328
// RVA: 0x5E49B0
void __fastcall UFG::UIHKInfoPopupWidget::Flash_ShowHealthUpgrade(UFG::UIHKInfoPopupWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // rcx

  if ( screen )
  {
    v2 = screen->mRenderable->m_movie.pObject;
    if ( v2 )
      Scaleform::GFx::Movie::Invoke(v2, "healthupgrade_Show", 0i64, 0i64, 0);
  }
}

// File Line: 338
// RVA: 0x5D5C70
char *__fastcall UFG::UIHKInfoPopupWidget::ConvertTypeToString(UFG::UIHKInfoPopupWidget *this, UFG::qSymbol *type)
{
  unsigned int v2; // eax
  char *result; // rax
  bool v4; // zf

  v2 = type->mUID;
  if ( type->mUID == qSymbol_Default_20.mUID )
    return &customWorldMapCaption;
  if ( v2 == qSymbol_Hint_20.mUID )
    return "Hint";
  if ( v2 == qSymbol_Collectible_HealthShrine_20.mUID )
    return "Icon_Collectible_HealthShrine";
  if ( v2 == qSymbol_Collectible_LockBox_20.mUID )
    return "Icon_Collectible_LockBox";
  if ( v2 == qSymbol_Collectible_SecurityCamera_20.mUID )
    return "Icon_Collectible_SecurityCamera";
  if ( v2 == qSymbol_Collectible_Jump_20.mUID )
    return "Icon_Collectible_Jump";
  if ( v2 == qSymbol_Upgrade_Melee_20.mUID )
    return "Icon_HUD_UpgradeMelee";
  if ( v2 == qSymbol_Upgrade_Gun_20.mUID )
    return "Icon_HUD_UpgradeShooting";
  if ( v2 == qSymbol_Case_20.mUID )
    return "Icon_HUD_Cases";
  if ( v2 == qSymbol_Favour_20.mUID )
    return "Icon_Favour";
  if ( v2 == qSymbol_Chat_20.mUID )
    return "Icon_Social_Chat";
  if ( v2 == qSymbol_Food_20.mUID )
    return "Icon_SocialPurchase_Food";
  if ( v2 == qSymbol_Tea_20.mUID )
    return "Icon_SocialPurchase_Tea";
  if ( v2 == qSymbol_Massage_20.mUID )
    return "Icon_SocialPurchase_Massage";
  if ( v2 == qSymbol_Clothing_20.mUID )
    return "Icon_SocialPurchase_Outfit";
  if ( v2 == qSymbol_Weapon_20.mUID )
    return "Icon_SocialPurchase_Weapon";
  if ( v2 == qSymbol_Extortion_20.mUID )
    return "Icon_Social_Intimidate";
  if ( v2 == qSymbol_Purchase_20.mUID )
    return "Icon_Social_Purchase";
  if ( v2 == qSymbol_Bribe_20.mUID )
    return "Icon_Social_Bribe";
  v4 = v2 == qSymbol_Drink_20.mUID;
  result = "Icon_SocialPurchase_Food";
  if ( !v4 )
    result = "Default";
  return result;
}

