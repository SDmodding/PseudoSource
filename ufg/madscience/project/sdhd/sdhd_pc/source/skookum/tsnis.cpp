// File Line: 54
// RVA: 0x4D4860
void UFG::TSNIS::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("NIS");
  SSClass::register_coroutine_func(v0, "_play_private", UFG::TSNIS::Coro_play_private, 0);
  SSClass::register_coroutine_func(v0, "_show_curtain", UFG::TSNIS::Coro_show_curtain, 0);
  SSClass::register_coroutine_func(v0, "_hide_curtain", UFG::TSNIS::Coro_hide_curtain, 0);
  SSClass::register_coroutine_func(v0, "_show_fastcurtain", UFG::TSNIS::Coro_show_fastcurtain, 0);
  SSClass::register_coroutine_func(v0, "_show_letterbox", UFG::TSNIS::Coro_show_letterbox, 0);
  SSClass::register_coroutine_func(v0, "_hide_letterbox", UFG::TSNIS::Coro_hide_letterbox, 0);
  SSClass::register_coroutine_func(v0, "_wait_for_nis_completition", UFG::TSNIS::Coro_wait_for_nis_completition, 0);
  SSClass::register_method_func(v0, "get_gameslice", UFG::TSNIS::MthdC_get_gameslice, 1, 0);
  SSClass::register_method_func(v0, "flash_subtitles", UFG::TSNIS::MthdC_flash_subtitles, 1, 0);
  SSClass::register_method_func(v0, "kill_subtitles", UFG::TSNIS::MthdC_kill_subtitles, 1, 0);
  SSClass::register_method_func(v0, "set_subtitles_y_offset", UFG::TSNIS::MthdC_set_subtitles_y_offset, 1, 0);
  SSClass::register_method_func(v0, "show_scene_time", UFG::TSNIS::MthdC_show_scene_time, 1, 0);
  SSClass::register_method_func(v0, "show_scene_time_caption", UFG::TSNIS::MthdC_show_scene_time_caption, 1, 0);
  SSClass::register_method_func(v0, "hide_scene_time", UFG::TSNIS::MthdC_hide_scene_time, 1, 0);
  SSClass::register_method_func(v0, "is_nis_playing", UFG::TSNIS::MthdC_is_nis_playing, 1, 0);
  SSClass::register_method_func(v0, "are_curtains_active", UFG::TSNIS::MthdC_are_curtains_active, 1, 0);
  SSClass::register_method_func(v0, "enable_screen_filter", UFG::TSNIS::MthdC_enable_screen_filter, 1, 0);
  SSClass::register_method_func(v0, "enable_fullscreen_filter", UFG::TSNIS::MthdC_enable_fullscreen_filter, 1, 0);
  SSClass::register_method_func(v0, "disable_fullscreen_filter", UFG::TSNIS::MthdC_disable_fullscreen_filter, 1, 0);
  SSClass::register_method_func(
    v0,
    "disable_all_fullscreen_filters",
    UFG::TSNIS::MthdC_disable_all_fullscreen_filters,
    1,
    0);
  SSClass::register_method_func(v0, "skip", UFG::TSNIS::MthdC_skip, 1, 0);
  SSClass::register_method_func(v0, "stop", UFG::TSNIS::MthdC_stop, 1, 0);
}

// File Line: 88
// RVA: 0x4E5110
void __fastcall UFG::TSNIS::MthdC_enable_screen_filter(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  bool v3; // bl
  int v4; // edi
  bool v5; // si
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rax
  int v7; // er10
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v8; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v9; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]
  UFG::qSymbol result; // [rsp+60h] [rbp+10h]

  v2 = pScope->i_data.i_array_p;
  v3 = v2[1]->i_data_p->i_user_data != 0;
  v4 = v2[2]->i_data_p->i_user_data;
  v5 = v2[3]->i_data_p->i_user_data != 0;
  UFG::qSymbol::create_from_string(&result, *(const char **)(*v2)->i_data_p->i_user_data);
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol = result;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( gVisualTreatmentEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gVisualTreatmentEnum, &pTrackEnumBinding);
  }
  else
  {
    v6 = gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v6;
    pTrackEnumBinding.mNext = &gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v7 = pTrackEnumBinding.m_EnumValue;
  v8 = pTrackEnumBinding.mPrev;
  v9 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v9->mPrev = v8;
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  if ( v7 != -1 )
  {
    if ( v3 )
      UFG::RenderWorld::VisualTreatmentPostEffect_StartVisualTreatment(v7, v5, v4);
    else
      UFG::RenderWorld::VisualTreatmentPostEffect_StopAllVisualTreatments();
  }
}

// File Line: 109
// RVA: 0x4E4E60
void __fastcall UFG::TSNIS::MthdC_enable_fullscreen_filter(SSInvokedMethod *scope, SSInstance **result)
{
  SSInstance **v2; // rbx
  SSData **v3; // r8
  int v4; // edi
  bool v5; // si
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v6; // rax
  int v7; // er10
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v8; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v9; // rax
  unsigned int v10; // eax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h]
  UFG::qSymbol resulta; // [rsp+60h] [rbp+10h]

  v2 = result;
  v3 = scope->i_data.i_array_p;
  v4 = v3[1]->i_data_p->i_user_data;
  v5 = v3[2]->i_data_p->i_user_data != 0;
  UFG::qSymbol::create_from_string(&resulta, *(const char **)(*v3)->i_data_p->i_user_data);
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol = resulta;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( gVisualTreatmentEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gVisualTreatmentEnum, &pTrackEnumBinding);
  }
  else
  {
    v6 = gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
    pTrackEnumBinding.mPrev = v6;
    pTrackEnumBinding.mNext = &gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  }
  v7 = pTrackEnumBinding.m_EnumValue;
  v8 = pTrackEnumBinding.mPrev;
  v9 = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  v9->mPrev = v8;
  pTrackEnumBinding.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  pTrackEnumBinding.mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&pTrackEnumBinding;
  if ( v7 != -1 )
  {
    v10 = UFG::RenderWorld::VisualTreatmentPostEffect_StartVisualTreatment(v7, v5, v4);
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, v10);
  }
}

// File Line: 127
// RVA: 0x4E4BD0
void __fastcall UFG::TSNIS::MthdC_disable_fullscreen_filter(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **v2; // rdx
  unsigned int v3; // ecx

  v2 = scope->i_data.i_array_p;
  v3 = (*v2)->i_data_p->i_user_data;
  if ( v3 != -1 )
    UFG::RenderWorld::VisualTreatmentPostEffect_StopVisualTreatment(v3, *(float *)&v2[1]->i_data_p->i_user_data);
}

// File Line: 140
// RVA: 0x4E4B10
void __fastcall UFG::TSNIS::MthdC_disable_all_fullscreen_filters(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::RenderWorld::VisualTreatmentPostEffect_StopAllVisualTreatments();
}

// File Line: 145
// RVA: 0x4F0F70
void __fastcall UFG::TSNIS::MthdC_skip(SSInvokedMethod *scope, SSInstance **result)
{
  NISManager *v2; // rax

  v2 = NISManager::GetInstance();
  NISManager::RequestSkip(v2);
}

// File Line: 150
// RVA: 0x4F26B0
void __fastcall UFG::TSNIS::MthdC_stop(SSInvokedMethod *scope, SSInstance **result)
{
  NISManager *v2; // rax

  v2 = NISManager::GetInstance();
  NISManager::StopActiveNIS(v2);
}

// File Line: 158
// RVA: 0x4E7910
void __fastcall UFG::TSNIS::MthdC_get_gameslice(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SSGameSlice *v2; // rcx

  if ( ppResult )
  {
    v2 = `anonymous namespace::gpNISGameSlice.i_obj_p;
    if ( `anonymous namespace::gpNISGameSlice.i_obj_p
      && `anonymous namespace::gpNISGameSlice.i_ptr_id == `anonymous namespace::gpNISGameSlice.i_obj_p->i_ptr_id )
    {
      ++`anonymous namespace::gpNISGameSlice.i_obj_p->i_ref_count;
      *ppResult = (SSInstance *)&v2->vfptr;
    }
    else
    {
      *ppResult = 0i64;
    }
  }
}

// File Line: 178
// RVA: 0x4DEAF0
bool __fastcall UFG::TSNIS::Coro_wait_for_nis_completition(SSInvokedCoroutine *pScope)
{
  return NISManager::GetInstance()->mState == 0;
}

// File Line: 186
// RVA: 0x4DC880
bool __fastcall UFG::TSNIS::Coro_play_private(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rdi
  NISInstance *v2; // rbx
  NISManager *v3; // rax

  v1 = pScope;
  if ( pScope->i_update_count )
    return NISManager::GetInstance()->mState == 0;
  v2 = (NISInstance *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = NISManager::GetInstance();
  if ( !NISManager::Play(v3, v2) )
    return 1;
  v1->i_update_interval = 0.30000001;
  return 0;
}

// File Line: 224
// RVA: 0x4E6BD0
void __fastcall UFG::TSNIS::MthdC_flash_subtitles(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  SSData **v3; // r8
  SSInstance *v4; // rbx
  SSInstance *v5; // r14
  unsigned int v6; // edi
  UFG::allocator::free_link *v7; // rcx
  __int64 *v8; // rax
  __int64 *v9; // rbx
  UFG::UIHKTextOverlay *v10; // rax
  __int64 v11; // rcx
  _QWORD *v12; // rax

  v2 = ppResult;
  v3 = pScope->i_data.i_array_p;
  v4 = (*v3)->i_data_p;
  v5 = v3[1]->i_data_p;
  v6 = 0;
  v7 = UFG::qMalloc(0xD0ui64, "UISubtitleMessage", 0i64);
  if ( v7 )
  {
    UFG::UISubtitleMessage::UISubtitleMessage((UFG::UISubtitleMessage *)v7, 0, *(const char **)v4->i_user_data, 0i64);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  *((_DWORD *)v9 + 6) = v5->i_user_data;
  v10 = UFG::UIHKTextOverlay::getInstance();
  if ( v10 )
  {
    v6 = UFG::UIHKTextOverlay::QueueMessage(v10, (UFG::UISubtitleMessage *)v9);
  }
  else
  {
    UFG::qString::~qString((UFG::qString *)(v9 + 21));
    UFG::qString::~qString((UFG::qString *)(v9 + 16));
    UFG::qString::~qString((UFG::qString *)v9 + 2);
    UFG::qString::~qString((UFG::qString *)v9 + 1);
    v11 = *v9;
    v12 = (_QWORD *)v9[1];
    *(_QWORD *)(v11 + 8) = v12;
    *v12 = v11;
    *v9 = (__int64)v9;
    v9[1] = (__int64)v9;
    operator delete[](v9);
  }
  if ( v2 )
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, v6);
}

// File Line: 251
// RVA: 0x4EA4E0
void __fastcall UFG::TSNIS::MthdC_kill_subtitles(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int v2; // ebx
  UFG::UIHKTextOverlay *v3; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::UIHKTextOverlay::getInstance();
  if ( v3 )
    UFG::UIHKTextOverlay::KillSubtitles(v3, v2);
}

// File Line: 263
// RVA: 0x4EF1E0
void __fastcall UFG::TSNIS::MthdC_set_subtitles_y_offset(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rbx
  UFG::UIHKTextOverlay *v3; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = UFG::UIHKTextOverlay::getInstance();
  if ( v3 )
    UFG::UIHKTextOverlay::SetSubtitleYOffset(v3, *(float *)&v2->i_user_data);
}

// File Line: 276
// RVA: 0x4DD420
bool __fastcall UFG::TSNIS::Coro_show_curtain(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rbx
  SSData **v3; // rcx
  SSInstance *v4; // rbp
  AString *v5; // r15
  AString *v6; // r14
  unsigned int v7; // esi
  bool v8; // di
  unsigned int v9; // eax
  bool v10; // r12
  AStringRef *v11; // rbx
  bool v12; // zf
  AObjReusePool<AStringRef> *v13; // rax
  AObjBlock<AStringRef> *v14; // rcx
  unsigned __int64 v15; // rdx
  bool v16; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v17; // rcx
  unsigned int v18; // eax
  bool v19; // di
  AStringRef *v20; // rbx
  AObjReusePool<AStringRef> *v21; // rax
  AObjBlock<AStringRef> *v22; // rcx
  unsigned __int64 v23; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v24; // rcx
  unsigned int v25; // ebx
  AString str; // [rsp+70h] [rbp+8h]

  v1 = pScope;
  if ( pScope->i_update_count && (!UFG::UIHK_NISOverlay::IsCurtainStable() || UFG::UIHK_NISOverlay::IsCurtainVisible()) )
    return UFG::UIHK_NISOverlay::IsCurtainVisible();
  v3 = v1->i_data.i_array_p;
  v4 = (*v3)->i_data_p;
  v5 = (AString *)v3[1]->i_data_p;
  v6 = (AString *)v3[2]->i_data_p;
  v7 = 0;
  v8 = 1;
  v9 = AMemory::c_req_byte_size_func(1u);
  str.i_str_ref_p = AStringRef::pool_new(&customWorldMapCaption, 0, v9, 1u, 0, 1);
  v10 = AString::is_equal(v5 + 4, &str) == 0;
  v11 = str.i_str_ref_p;
  v12 = str.i_str_ref_p->i_ref_count == 1;
  --v11->i_ref_count;
  if ( v12 )
  {
    if ( v11->i_deallocate )
      AMemory::c_free_func(v11->i_cstr_p);
    v13 = AStringRef::get_pool();
    v14 = v13->i_block_p;
    v15 = (unsigned __int64)v14->i_objects_a;
    if ( (unsigned __int64)v11 < v15
      || (v16 = (unsigned __int64)v11 < v15 + 24i64 * v14->i_size, v17 = &v13->i_pool, !v16) )
    {
      v17 = &v13->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v17, v11);
  }
  if ( v10 )
  {
    v7 = UFG::TiDo::CalcWwiseUid(v5[4].i_str_ref_p->i_cstr_p);
    v8 = 0;
  }
  UFG::UIHK_NISOverlay::ShowCurtains(*(float *)&v4->i_user_data, v8);
  if ( !v8 )
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr, v7, 0i64, 0, 0i64);
  v18 = AMemory::c_req_byte_size_func(1u);
  str.i_str_ref_p = AStringRef::pool_new(&customWorldMapCaption, 0, v18, 1u, 0, 1);
  v19 = AString::is_equal(v6 + 4, &str) == 0;
  v20 = str.i_str_ref_p;
  v12 = str.i_str_ref_p->i_ref_count == 1;
  --v20->i_ref_count;
  if ( v12 )
  {
    if ( v20->i_deallocate )
      AMemory::c_free_func(v20->i_cstr_p);
    v21 = AStringRef::get_pool();
    v22 = v21->i_block_p;
    v23 = (unsigned __int64)v22->i_objects_a;
    if ( (unsigned __int64)v20 < v23
      || (v16 = (unsigned __int64)v20 < v23 + 24i64 * v22->i_size, v24 = &v21->i_pool, !v16) )
    {
      v24 = &v21->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v24, v20);
  }
  if ( v19 )
  {
    v25 = UFG::TiDo::CalcWwiseUid(v6[4].i_str_ref_p->i_cstr_p);
    UFG::UIHK_NISOverlay::getInstance();
    UFG::UIHK_NISOverlay::SetPostNISHideCurtainsAudioEvent(v25, 0);
  }
  return 0;
}

// File Line: 314
// RVA: 0x4DB490
bool __fastcall UFG::TSNIS::Coro_hide_curtain(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rbx
  float v3; // xmm1_4

  v1 = pScope;
  if ( pScope->i_update_count && (!UFG::UIHK_NISOverlay::IsCurtainStable() || !UFG::UIHK_NISOverlay::IsCurtainVisible()) )
    return UFG::UIHK_NISOverlay::IsCurtainHidden();
  v3 = *(float *)&(*v1->i_data.i_array_p)->i_data_p->i_user_data;
  if ( v3 > 0.0 && v3 < 1.25 )
  {
    v3 = v3 + 0.75;
    if ( v3 <= 1.25 )
      v3 = FLOAT_1_25;
  }
  UFG::UIHK_NISOverlay::HideCurtains(v3, 0);
  return 0;
}

// File Line: 338
// RVA: 0x4DD640
bool __fastcall UFG::TSNIS::Coro_show_fastcurtain(SSInvokedCoroutine *pScope)
{
  if ( pScope->i_update_count && (!UFG::UIHK_NISOverlay::IsCurtainStable() || UFG::UIHK_NISOverlay::IsCurtainVisible()) )
    return UFG::UIHK_NISOverlay::IsCurtainVisible();
  UFG::UIHK_NISOverlay::ShowCurtains(0.33000001, 1);
  return 0;
}

// File Line: 353
// RVA: 0x4DD680
char __fastcall UFG::TSNIS::Coro_show_letterbox(SSInvokedCoroutine *pScope)
{
  UFG::UIHK_NISOverlay::ShowLetterBox();
  return 1;
}

// File Line: 361
// RVA: 0x4DB510
char __fastcall UFG::TSNIS::Coro_hide_letterbox(SSInvokedCoroutine *pScope)
{
  UFG::UIHK_NISOverlay::HideLetterBox();
  return 1;
}

// File Line: 368
// RVA: 0x4F0C00
void __fastcall UFG::TSNIS::MthdC_show_scene_time(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  float v2; // xmm6_4
  UFG::UIHK_NISOverlay *v3; // rax
  UFG::UIHK_NISFrameCounterWidget *v4; // rbx

  v2 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v3 = UFG::UIHK_NISOverlay::getInstance();
  if ( v3 )
  {
    v4 = &v3->FrameCounter;
    UFG::UIHK_NISFrameCounterWidget::SetSceneTime(&v3->FrameCounter, v2);
    UFG::UIHK_NISFrameCounterWidget::SetVisible(v4, 1);
  }
}

// File Line: 380
// RVA: 0x4F0C50
void __fastcall UFG::TSNIS::MthdC_show_scene_time_caption(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rdi
  UFG::UIHK_NISOverlay *v3; // rax
  UFG::UIHK_NISFrameCounterWidget *v4; // rbx

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = UFG::UIHK_NISOverlay::getInstance();
  if ( v3 )
  {
    v4 = &v3->FrameCounter;
    UFG::UIHK_NISFrameCounterWidget::SetCaption(&v3->FrameCounter, *(const char **)v2->i_user_data);
    UFG::UIHK_NISFrameCounterWidget::SetVisible(v4, 1);
  }
}

// File Line: 392
// RVA: 0x4E8F50
void __fastcall UFG::TSNIS::MthdC_hide_scene_time(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHK_NISOverlay *v2; // rax

  v2 = UFG::UIHK_NISOverlay::getInstance();
  if ( v2 )
    UFG::UIHK_NISFrameCounterWidget::SetVisible(&v2->FrameCounter, 0);
}

// File Line: 403
// RVA: 0x4E9670
void __fastcall UFG::TSNIS::MthdC_is_nis_playing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  NISManager *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = NISManager::GetInstance();
    *v2 = (SSInstance *)SSBoolean::pool_new(v3->mState != 0);
  }
}

// File Line: 413
// RVA: 0x4E39D0
void __fastcall UFG::TSNIS::MthdC_are_curtains_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  bool v3; // al

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::UIHK_NISOverlay::IsCurtainVisible();
    *v2 = (SSInstance *)SSBoolean::pool_new(v3);
  }
}

// File Line: 433
// RVA: 0x4F6C30
void __fastcall UFG::TSNISInstance::Mthd_constructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  NISInstance *v3; // r8
  const char *v4; // rbx
  NISManager *v5; // rax
  SSObjectBase *v6; // rdx

  v2 = pScope;
  v3 = 0i64;
  if ( (*pScope->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
  {
    v4 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    v5 = NISManager::GetInstance();
    v3 = NISManager::CreateInstance(v5, v4);
  }
  v6 = v2->i_scope_p.i_obj_p;
  if ( v6 && v2->i_scope_p.i_ptr_id == v6->i_ptr_id )
    v6[2].vfptr = (SSObjectBaseVtbl *)v3;
  else
    *(_QWORD *)&MEMORY[0x20] = v3;
}

// File Line: 457
// RVA: 0x4F7EB0
void __fastcall UFG::TSNISInstance::Mthd_destructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  NISInstance *v3; // rbx
  NISManager *v4; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (NISInstance *)v2[2].vfptr;
  if ( v3 )
  {
    v4 = NISManager::GetInstance();
    NISManager::DestroyInstance(v4, v3);
  }
}

// File Line: 475
// RVA: 0x5060E0
void __fastcall UFG::TSNISInstance::Mthd_preload(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  JUMPOUT(v2[2].vfptr, 0i64, NISInstance::Preload);
}

// File Line: 493
// RVA: 0x50E2A0
void __fastcall UFG::TSNISInstance::Mthd_unload(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  NISInstance *v3; // rcx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (NISInstance *)v2[2].vfptr;
  if ( v3 )
    NISInstance::Unload(v3, 0);
}

// File Line: 512
// RVA: 0x509DB0
void __fastcall UFG::TSNISInstance::Mthd_set_post_nis_fade_in(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // r8

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  if ( v3 )
    BYTE6(v3->get_topmost_scope) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 531
// RVA: 0x509DF0
void __fastcall UFG::TSNISInstance::Mthd_set_post_nis_scene_settings(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSObjectBaseVtbl *v3; // rdi
  SSData **v4; // rax
  const char ***v5; // rbx
  int v6; // eax
  UFG::qSymbol *v7; // rbx
  UFG::ProgressionTracker *v8; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[2].vfptr;
  if ( v3 )
  {
    v4 = pScope->i_data.i_array_p;
    v5 = (const char ***)&(*v4)->i_data_p->i_user_data;
    if ( (*v4)->i_data_p != (SSInstance *)-32i64 )
    {
      if ( *((_DWORD *)*v5 + 2) )
      {
        v6 = stricmp(**v5, "Settings_Intermediate_Nis");
        if ( v6 > 0 || v6 < 0 )
        {
          v7 = UFG::qSymbol::create_from_string(&result, **v5);
          v8 = UFG::ProgressionTracker::Instance();
          v3[1].__vecDelDtor = (void *(__fastcall *)(SSObjectBase *, unsigned int))UFG::ProgressionTracker::FindSceneSettings(
                                                                                     v8,
                                                                                     v7);
        }
        else
        {
          *(_WORD *)((char *)&v3->get_topmost_scope + 5) = 1;
        }
      }
    }
  }
}

// File Line: 569
// RVA: 0x4D4AF0
void UFG::TSNISInstance::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("NISInstance");
  SSClass::register_method_func(v0, &ASymbolX_ctor, UFG::TSNISInstance::Mthd_constructor, 0);
  SSClass::register_method_func(v0, &ASymbolX_dtor, UFG::TSNISInstance::Mthd_destructor, 0);
  SSClass::register_method_func(v0, "preload", UFG::TSNISInstance::Mthd_preload, 0);
  SSClass::register_method_func(v0, "unload", UFG::TSNISInstance::Mthd_unload, 0);
  SSClass::register_method_func(v0, "set_post_nis_fade_in", UFG::TSNISInstance::Mthd_set_post_nis_fade_in, 0);
  SSClass::register_method_func(
    v0,
    "set_post_nis_scene_settings",
    UFG::TSNISInstance::Mthd_set_post_nis_scene_settings,
    0);
}

