// File Line: 43
// RVA: 0x4D7A20
void UFG::TSUI_HUD_GameplayHelp::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("GameplayHelp");
  SSClass::register_method_func(v0, "show_pickup", UFG::TSUI_HUD_GameplayHelp::MthdC_show_pickup, 1, 0);
  SSClass::register_method_func(
    v0,
    "show_pickup_for_one_frame",
    UFG::TSUI_HUD_GameplayHelp::MthdC_show_pickup_for_one_frame,
    1,
    0);
  SSClass::register_method_func(v0, "show", UFG::TSUI_HUD_GameplayHelp::MthdC_show, 1, 0);
  SSClass::register_method_func(v0, "show_for_one_frame", UFG::TSUI_HUD_GameplayHelp::MthdC_show_for_one_frame, 1, 0);
  SSClass::register_method_func(v0, "play_hold", UFG::TSUI_HUD_GameplayHelp::MthdC_play_hold, 1, 0);
  SSClass::register_method_func(v0, "stop_hold", UFG::TSUI_HUD_GameplayHelp::MthdC_stop_hold, 1, 0);
  SSClass::register_method_func(v0, "hide", UFG::TSUI_HUD_GameplayHelp::MthdC_hide, 1, 0);
}

// File Line: 57
// RVA: 0x4F0780
void __fastcall UFG::TSUI_HUD_GameplayHelp::MthdC_show_pickup(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  SSData **v4; // rcx
  SSInstance *v5; // r8
  SSInstance *v6; // rdx
  SSInstance *v7; // rcx
  UFG::qSymbol icon; // [rsp+50h] [rbp+18h]
  UFG::qSymbol *v9; // [rsp+58h] [rbp+20h]

  v2 = pScope;
  v3 = UFG::GameStatTracker::Instance();
  if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v3, ContextHelp) )
  {
    v4 = v2->i_data.i_array_p;
    v5 = (*v4)->i_data_p;
    v6 = v4[1]->i_data_p;
    v7 = v4[2]->i_data_p;
    v9 = &icon;
    icon.mUID = v7->i_user_data;
    UFG::TSUI_HUD_GameplayHelp::pickup_helper(
      *(const char **)v5->i_user_data,
      *(const char **)v6->i_user_data,
      (__int64)&icon,
      0);
  }
}

// File Line: 69
// RVA: 0x4F0800
void __fastcall UFG::TSUI_HUD_GameplayHelp::MthdC_show_pickup_for_one_frame(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  SSData **v4; // rcx
  SSInstance *v5; // r8
  SSInstance *v6; // rdx
  SSInstance *v7; // rcx
  UFG::qSymbol icon; // [rsp+50h] [rbp+18h]
  UFG::qSymbol *v9; // [rsp+58h] [rbp+20h]

  v2 = pScope;
  v3 = UFG::GameStatTracker::Instance();
  if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v3, ContextHelp) )
  {
    v4 = v2->i_data.i_array_p;
    v5 = (*v4)->i_data_p;
    v6 = v4[1]->i_data_p;
    v7 = v4[2]->i_data_p;
    v9 = &icon;
    icon.mUID = v7->i_user_data;
    UFG::TSUI_HUD_GameplayHelp::pickup_helper(
      *(const char **)v5->i_user_data,
      *(const char **)v6->i_user_data,
      (__int64)&icon,
      1);
  }
}

// File Line: 81
// RVA: 0x4EF970
void __fastcall UFG::TSUI_HUD_GameplayHelp::MthdC_show(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  SSData **v4; // rcx
  SSInstance *v5; // rsi
  SSInstance *v6; // r14
  SSInstance *v7; // rbx
  SSInstance *v8; // r15
  SSInstance *v9; // rbp
  UFG::UI::RemapContext v10; // edi
  UFG::UI::eButtons v11; // er13
  UFG::UI::eButtons v12; // er12
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // rcx
  UFG::Controller *v15; // r8
  char v16; // dl
  UFG::UIHKGameplayHelpWidget *v17; // rax
  UFG::UIHKGameplayHelpData data; // [rsp+30h] [rbp-118h]
  unsigned int v19; // [rsp+160h] [rbp+18h]

  v2 = pScope;
  v3 = UFG::GameStatTracker::Instance();
  if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v3, ContextHelp) )
  {
    v4 = v2->i_data.i_array_p;
    v5 = v4[1]->i_data_p;
    v6 = v4[2]->i_data_p;
    v7 = v4[3]->i_data_p;
    v8 = v4[4]->i_data_p;
    v9 = v4[5]->i_data_p;
    v19 = v4[6]->i_data_p->i_user_data;
    v10 = 0;
    v11 = 0;
    v12 = 0;
    v13 = (*v4)->i_data_p->i_user_data;
    if ( *(_DWORD *)(v13 + 8) )
      v11 = UFG::UI::GetButton(*(const char **)v13);
    v14 = v7->i_user_data;
    if ( *(_DWORD *)(v14 + 8) > 0u )
      v12 = UFG::UI::GetButton(*(const char **)v14);
    v15 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    v16 = 0;
    if ( v15 )
    {
      v16 = 0;
      if ( v15->m_ActiveMapSet - 4 <= 1 )
        v16 = 1;
    }
    LOBYTE(v10) = v16 != 0;
    UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(&data);
    data.id = UI_HASH_TSHUD_15;
    data.priority = v19;
    data.remapContext = v10;
    data.Buttons[0] = v11;
    data.Buttons[1] = v12;
    UFG::qString::Set(data.Captions, *(const char **)v5->i_user_data);
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
  SSInvokedMethod *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  SSData **v4; // rcx
  SSInstance *v5; // r14
  SSInstance *v6; // r15
  SSInstance *v7; // rbx
  SSInstance *v8; // rbp
  SSInstance *v9; // r12
  unsigned int v10; // er13
  UFG::UI::eButtons v11; // edi
  UFG::UI::eButtons v12; // esi
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // rcx
  UFG::UIHKGameplayHelpWidget *v15; // rax
  UFG::UIHKGameplayHelpData data; // [rsp+30h] [rbp-118h]

  v2 = pScope;
  v3 = UFG::GameStatTracker::Instance();
  if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v3, ContextHelp) )
  {
    v4 = v2->i_data.i_array_p;
    v5 = v4[1]->i_data_p;
    v6 = v4[2]->i_data_p;
    v7 = v4[3]->i_data_p;
    v8 = v4[4]->i_data_p;
    v9 = v4[5]->i_data_p;
    v10 = v4[6]->i_data_p->i_user_data;
    v11 = 0;
    v12 = 0;
    v13 = (*v4)->i_data_p->i_user_data;
    if ( *(_DWORD *)(v13 + 8) )
      v11 = UFG::UI::GetButton(*(const char **)v13);
    v14 = v7->i_user_data;
    if ( *(_DWORD *)(v14 + 8) > 0u )
      v12 = UFG::UI::GetButton(*(const char **)v14);
    UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(&data);
    data.id = UI_HASH_TSHUD_15;
    data.priority = v10;
    data.Buttons[0] = v11;
    data.Buttons[1] = v12;
    UFG::qString::Set(data.Captions, *(const char **)v5->i_user_data);
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
  int v2; // ebx
  UFG::UIHKGameplayHelpWidget *v3; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::UIHKGameplayHelpWidget::Get();
  UFG::UIHKGameplayHelpWidget::PlayButtonCharge(v3, UI_HASH_TSHUD_15, v2);
}

// File Line: 172
// RVA: 0x4F2720
void __fastcall UFG::TSUI_HUD_GameplayHelp::MthdC_stop_hold(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int v2; // ebx
  UFG::UIHKGameplayHelpWidget *v3; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::UIHKGameplayHelpWidget::Get();
  UFG::UIHKGameplayHelpWidget::StopButtonCharge(v3, UI_HASH_TSHUD_15, v2);
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
void __fastcall UFG::TSUI_HUD_GameplayHelp::pickup_helper(const char *button, const char *caption, __int64 icon, bool isOneFrame)
{
  bool v4; // r14
  unsigned int *v5; // rsi
  const char *v6; // rdi
  const char *v7; // rbx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v8; // rax
  UFG::UIHKGameplayHelpWidget *v9; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v10; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v11; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+20h] [rbp-C8h]
  char *szTexturePack; // [rsp+40h] [rbp-A8h]
  __int64 v14; // [rsp+48h] [rbp-A0h]
  UFG::UIHKGameplayHelpData data; // [rsp+50h] [rbp-98h]
  const char *retaddr; // [rsp+158h] [rbp+70h]

  v14 = -2i64;
  v4 = isOneFrame;
  v5 = (unsigned int *)icon;
  v6 = caption;
  v7 = button;
  UFG::UIHKGameplayHelpData::UIHKGameplayHelpData(&data);
  data.id = UI_HASH_TSHUD_15;
  data.isWeaponPickup = 1;
  data.Buttons[0] = UFG::UI::GetButton(v7);
  UFG::qString::Set(data.Captions, v6);
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol.mUID = -1;
  pTrackEnumBinding.m_EnumSymbol.mUID = *v5;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( UFG::gInventoryItemTracksEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&UFG::gInventoryItemTracksEnum, &pTrackEnumBinding);
  }
  else
  {
    v8 = UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v8;
    pTrackEnumBinding.mNext = &UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode;
    UFG::gInventoryItemTracksEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  if ( UFG::UIHKWeaponAmmoWidget::GetWeaponImageInfo(
         (UFG::eInventoryItemEnum)pTrackEnumBinding.m_EnumValue,
         (const char **)&szTexturePack,
         &retaddr) )
  {
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 16), retaddr);
    UFG::qString::Set((UFG::qString *)((char *)&data.Icons[1] + 24), szTexturePack);
  }
  v9 = UFG::UIHKGameplayHelpWidget::Get();
  if ( v4 )
    UFG::UIHKGameplayHelpWidget::ShowOneFrame(v9, &data);
  else
    UFG::UIHKGameplayHelpWidget::Show(v9, &data);
  v10 = pTrackEnumBinding.mPrev;
  v11 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v11->mPrev = v10;
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  UFG::qString::~qString((UFG::qString *)((char *)&data.Icons[1] + 24));
  `eh vector destructor iterator(
    &data.Captions[1].mMagic,
    0x28ui64,
    2,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(data.Captions, 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::~qString);
}

