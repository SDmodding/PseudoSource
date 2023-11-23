// File Line: 43
// RVA: 0x4D7A20
void UFG::TSUI_HUD_GameplayHelp::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("GameplayHelp");
  SSClass::register_method_func(v0, "show_pickup", UFG::TSUI_HUD_GameplayHelp::MthdC_show_pickup, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "show_pickup_for_one_frame",
    UFG::TSUI_HUD_GameplayHelp::MthdC_show_pickup_for_one_frame,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "show", UFG::TSUI_HUD_GameplayHelp::MthdC_show, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "show_for_one_frame",
    UFG::TSUI_HUD_GameplayHelp::MthdC_show_for_one_frame,
    1,
    rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "play_hold", UFG::TSUI_HUD_GameplayHelp::MthdC_play_hold, 1, rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(v0, "stop_hold", UFG::TSUI_HUD_GameplayHelp::MthdC_stop_hold, 1, rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(v0, "hide", UFG::TSUI_HUD_GameplayHelp::MthdC_hide, 1, rebindf);
}

// File Line: 57
// RVA: 0x4F0780
void __fastcall UFG::TSUI_HUD_GameplayHelp::MthdC_show_pickup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStatTracker *v3; // rax
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // r8
  SSInstance *v6; // rdx
  SSInstance *v7; // rcx
  UFG::qSymbol icon; // [rsp+50h] [rbp+18h] BYREF
  UFG::qSymbol *p_icon; // [rsp+58h] [rbp+20h]

  v3 = UFG::GameStatTracker::Instance();
  if ( UFG::GameStatTracker::GetStat(v3, ContextHelp) )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = (*i_array_p)->i_data_p;
    v6 = i_array_p[1]->i_data_p;
    v7 = i_array_p[2]->i_data_p;
    p_icon = &icon;
    icon.mUID = v7->i_user_data;
    UFG::TSUI_HUD_GameplayHelp::pickup_helper(
      *(const char **)i_data_p->i_user_data,
      *(const char **)v6->i_user_data,
      (__int64)&icon,
      0);
  }
}

// File Line: 69
// RVA: 0x4F0800
void __fastcall UFG::TSUI_HUD_GameplayHelp::MthdC_show_pickup_for_one_frame(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::GameStatTracker *v3; // rax
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // r8
  SSInstance *v6; // rdx
  SSInstance *v7; // rcx
  UFG::qSymbol icon; // [rsp+50h] [rbp+18h] BYREF
  UFG::qSymbol *p_icon; // [rsp+58h] [rbp+20h]

  v3 = UFG::GameStatTracker::Instance();
  if ( UFG::GameStatTracker::GetStat(v3, ContextHelp) )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = (*i_array_p)->i_data_p;
    v6 = i_array_p[1]->i_data_p;
    v7 = i_array_p[2]->i_data_p;
    p_icon = &icon;
    icon.mUID = v7->i_user_data;
    UFG::TSUI_HUD_GameplayHelp::pickup_helper(
      *(const char **)i_data_p->i_user_data,
      *(const char **)v6->i_user_data,
      (__int64)&icon,
      1);
  }
}

// File Line: 81
// RVA: 0x4EF970
void __fastcall UFG::TSUI_HUD_GameplayHelp::MthdC_show(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStatTracker *v3; // rax
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rsi
  SSInstance *v6; // r14
  SSInstance *v7; // rbx
  SSInstance *v8; // r15
  SSInstance *v9; // rbp
  UFG::UI::RemapContext v10; // edi
  UFG::UI::eButtons Button; // r13d
  UFG::UI::eButtons v12; // r12d
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // rcx
  UFG::Controller *v15; // r8
  bool v16; // dl
  UFG::UIHKGameplayHelpWidget *v17; // rax
  UFG::UIHKGameplayHelpData data; // [rsp+30h] [rbp-118h] BYREF
  unsigned int i_user_data; // [rsp+160h] [rbp+18h]

  v3 = UFG::GameStatTracker::Instance();
  if ( UFG::GameStatTracker::GetStat(v3, ContextHelp) )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = i_array_p[1]->i_data_p;
    v6 = i_array_p[2]->i_data_p;
    v7 = i_array_p[3]->i_data_p;
    v8 = i_array_p[4]->i_data_p;
    v9 = i_array_p[5]->i_data_p;
    i_user_data = i_array_p[6]->i_data_p->i_user_data;
    v10 = RemapContext_OnFoot;
    Button = INVALID_BUTTON;
    v12 = INVALID_BUTTON;
    v13 = (*i_array_p)->i_data_p->i_user_data;
    if ( *(_DWORD *)(v13 + 8) )
      Button = UFG::UI::GetButton(*(const char **)v13);
    v14 = v7->i_user_data;
    if ( *(_DWORD *)(v14 + 8) )
      v12 = UFG::UI::GetButton(*(const char **)v14);
    v15 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    v16 = 0;
    if ( v15 )
      v16 = v15->m_ActiveMapSet - 4 <= 1;
    LOBYTE(v10) = v16;
    UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(&data);
    data.id = UI_HASH_TSHUD_15;
    data.priority = i_user_data;
    data.remapContext = v10;
    data.Buttons[0] = Button;
    data.Buttons[1] = v12;
    UFG::qString::Set(data.Captions, *(const char **)i_data_p->i_user_data);
    UFG::qString::Set(&data.Captions[1], *(const char **)v8->i_user_data);
    UFG::qString::Set(data.Icons, *(const char **)v6->i_user_data);
    UFG::qString::Set(&data.Icons[1], *(const char **)v9->i_user_data);
    v17 = UFG::UIHKGameplayHelpWidget::Get();
    UFG::UIHKGameplayHelpWidget::Show(v17, &data);
    UFG::qString::~qString(&data.CustomTexturePack);
    `eh vector destructor iterator(data.Icons, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(data.Captions, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
  }
}

// File Line: 132
// RVA: 0x4F00B0
void __fastcall UFG::TSUI_HUD_GameplayHelp::MthdC_show_for_one_frame(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStatTracker *v3; // rax
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // r14
  SSInstance *v6; // r15
  SSInstance *v7; // rbx
  SSInstance *v8; // rbp
  SSInstance *v9; // r12
  unsigned int i_user_data; // r13d
  UFG::UI::eButtons Button; // edi
  UFG::UI::eButtons v12; // esi
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // rcx
  UFG::UIHKGameplayHelpWidget *v15; // rax
  UFG::UIHKGameplayHelpData data; // [rsp+30h] [rbp-118h] BYREF

  v3 = UFG::GameStatTracker::Instance();
  if ( UFG::GameStatTracker::GetStat(v3, ContextHelp) )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = i_array_p[1]->i_data_p;
    v6 = i_array_p[2]->i_data_p;
    v7 = i_array_p[3]->i_data_p;
    v8 = i_array_p[4]->i_data_p;
    v9 = i_array_p[5]->i_data_p;
    i_user_data = i_array_p[6]->i_data_p->i_user_data;
    Button = INVALID_BUTTON;
    v12 = INVALID_BUTTON;
    v13 = (*i_array_p)->i_data_p->i_user_data;
    if ( *(_DWORD *)(v13 + 8) )
      Button = UFG::UI::GetButton(*(const char **)v13);
    v14 = v7->i_user_data;
    if ( *(_DWORD *)(v14 + 8) )
      v12 = UFG::UI::GetButton(*(const char **)v14);
    UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(&data);
    data.id = UI_HASH_TSHUD_15;
    data.priority = i_user_data;
    data.Buttons[0] = Button;
    data.Buttons[1] = v12;
    UFG::qString::Set(data.Captions, *(const char **)i_data_p->i_user_data);
    UFG::qString::Set(&data.Captions[1], *(const char **)v8->i_user_data);
    UFG::qString::Set(data.Icons, *(const char **)v6->i_user_data);
    UFG::qString::Set(&data.Icons[1], *(const char **)v9->i_user_data);
    v15 = UFG::UIHKGameplayHelpWidget::Get();
    UFG::UIHKGameplayHelpWidget::ShowOneFrame(v15, &data);
    UFG::qString::~qString(&data.CustomTexturePack);
    `eh vector destructor iterator(data.Icons, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(data.Captions, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
  }
}

// File Line: 164
// RVA: 0x4EB2F0
void __fastcall UFG::TSUI_HUD_GameplayHelp::MthdC_play_hold(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int i_user_data; // ebx
  UFG::UIHKGameplayHelpWidget *v3; // rax

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::UIHKGameplayHelpWidget::Get();
  UFG::UIHKGameplayHelpWidget::PlayButtonCharge(v3, UI_HASH_TSHUD_15, i_user_data);
}

// File Line: 172
// RVA: 0x4F2720
void __fastcall UFG::TSUI_HUD_GameplayHelp::MthdC_stop_hold(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int i_user_data; // ebx
  UFG::UIHKGameplayHelpWidget *v3; // rax

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::UIHKGameplayHelpWidget::Get();
  UFG::UIHKGameplayHelpWidget::StopButtonCharge(v3, UI_HASH_TSHUD_15, i_user_data);
}

// File Line: 180
// RVA: 0x4E8E10
void __fastcall UFG::TSUI_HUD_GameplayHelp::MthdC_hide(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKGameplayHelpWidget *v2; // rax

  v2 = UFG::UIHKGameplayHelpWidget::Get();
  UFG::UIHKGameplayHelpWidget::Hide(v2, UI_HASH_TSHUD_15);
}

// File Line: 186
// RVA: 0x5125D0
void __fastcall UFG::TSUI_HUD_GameplayHelp::pickup_helper(
        const char *button,
        const char *caption,
        unsigned int *icon,
        bool isOneFrame)
{
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  UFG::UIHKGameplayHelpWidget *v9; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+20h] [rbp-C8h] BYREF
  char *szTexturePack[2]; // [rsp+40h] [rbp-A8h] BYREF
  UFG::UIHKGameplayHelpData data; // [rsp+50h] [rbp-98h] BYREF
  const char *retaddr; // [rsp+158h] [rbp+70h] BYREF

  szTexturePack[1] = (char *)-2i64;
  UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(&data);
  data.id = UI_HASH_TSHUD_15;
  data.isWeaponPickup = 1;
  data.Buttons[0] = UFG::UI::GetButton(button);
  UFG::qString::Set(data.Captions, caption);
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
  pTrackEnumBinding.m_EnumSymbol.mUID = *icon;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gInventoryItemTracksEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gInventoryItemTracksEnum, &pTrackEnumBinding);
  }
  else
  {
    mPrev = UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
    pTrackEnumBinding.mPrev = mPrev;
    pTrackEnumBinding.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
  }
  if ( UFG::UIHKWeaponAmmoWidget::GetWeaponImageInfo(
         (UFG::eInventoryItemEnum)pTrackEnumBinding.m_EnumValue,
         (const char **)szTexturePack,
         &retaddr) )
  {
    UFG::qString::Set((UFG::qString *)&data.Captions[1].mMagic, retaddr);
    UFG::qString::Set((UFG::qString *)&data.Icons[1].mData, szTexturePack[0]);
  }
  v9 = UFG::UIHKGameplayHelpWidget::Get();
  if ( isOneFrame )
    UFG::UIHKGameplayHelpWidget::ShowOneFrame(v9, &data);
  else
    UFG::UIHKGameplayHelpWidget::Show(v9, &data);
  v10 = pTrackEnumBinding.mPrev;
  mNext = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  mNext->mPrev = v10;
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  UFG::qString::~qString((UFG::qString *)&data.Icons[1].mData);
  `eh vector destructor iterator(
    &data.Captions[1].mMagic,
    0x28ui64,
    2,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(data.Captions, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
}

