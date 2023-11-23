// File Line: 54
// RVA: 0x4D4860
void UFG::TSNIS::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]
  ASymbol rebindg; // [rsp+20h] [rbp-18h]
  ASymbol rebindh; // [rsp+20h] [rbp-18h]
  ASymbol rebindi; // [rsp+20h] [rbp-18h]
  ASymbol rebindj; // [rsp+20h] [rbp-18h]
  ASymbol rebindk; // [rsp+20h] [rbp-18h]
  ASymbol rebindl; // [rsp+20h] [rbp-18h]
  ASymbol rebindm; // [rsp+20h] [rbp-18h]
  ASymbol rebindn; // [rsp+20h] [rbp-18h]

  v0 = SSBrain::get_class("NIS");
  SSClass::register_coroutine_func(v0, "_play_private", UFG::TSNIS::Coro_play_private, SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(v0, "_show_curtain", UFG::TSNIS::Coro_show_curtain, SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(v0, "_hide_curtain", UFG::TSNIS::Coro_hide_curtain, SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_show_fastcurtain",
    UFG::TSNIS::Coro_show_fastcurtain,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_show_letterbox",
    UFG::TSNIS::Coro_show_letterbox,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_hide_letterbox",
    UFG::TSNIS::Coro_hide_letterbox,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_wait_for_nis_completition",
    UFG::TSNIS::Coro_wait_for_nis_completition,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(v0, "get_gameslice", UFG::TSNIS::MthdC_get_gameslice, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "flash_subtitles", UFG::TSNIS::MthdC_flash_subtitles, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "kill_subtitles", UFG::TSNIS::MthdC_kill_subtitles, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "set_subtitles_y_offset", UFG::TSNIS::MthdC_set_subtitles_y_offset, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "show_scene_time", UFG::TSNIS::MthdC_show_scene_time, 1, rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(v0, "show_scene_time_caption", UFG::TSNIS::MthdC_show_scene_time_caption, 1, rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(v0, "hide_scene_time", UFG::TSNIS::MthdC_hide_scene_time, 1, rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(v0, "is_nis_playing", UFG::TSNIS::MthdC_is_nis_playing, 1, rebindg);
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(v0, "are_curtains_active", UFG::TSNIS::MthdC_are_curtains_active, 1, rebindh);
  LOBYTE(rebindi.i_uid) = 0;
  SSClass::register_method_func(v0, "enable_screen_filter", UFG::TSNIS::MthdC_enable_screen_filter, 1, rebindi);
  LOBYTE(rebindj.i_uid) = 0;
  SSClass::register_method_func(v0, "enable_fullscreen_filter", UFG::TSNIS::MthdC_enable_fullscreen_filter, 1, rebindj);
  LOBYTE(rebindk.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "disable_fullscreen_filter",
    UFG::TSNIS::MthdC_disable_fullscreen_filter,
    1,
    rebindk);
  LOBYTE(rebindl.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "disable_all_fullscreen_filters",
    UFG::TSNIS::MthdC_disable_all_fullscreen_filters,
    1,
    rebindl);
  LOBYTE(rebindm.i_uid) = 0;
  SSClass::register_method_func(v0, "skip", UFG::TSNIS::MthdC_skip, 1, rebindm);
  LOBYTE(rebindn.i_uid) = 0;
  SSClass::register_method_func(v0, "stop", UFG::TSNIS::MthdC_stop, 1, rebindn);
}

// File Line: 88
// RVA: 0x4E5110
void __fastcall UFG::TSNIS::MthdC_enable_screen_filter(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  bool v3; // bl
  int i_user_data; // edi
  bool v5; // si
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  int m_EnumValue; // r10d
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v8; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+60h] [rbp+10h] BYREF

  i_array_p = pScope->i_data.i_array_p;
  v3 = i_array_p[1]->i_data_p->i_user_data != 0;
  i_user_data = i_array_p[2]->i_data_p->i_user_data;
  v5 = i_array_p[3]->i_data_p->i_user_data != 0;
  UFG::qSymbol::create_from_string(&result, *(const char **)(*i_array_p)->i_data_p->i_user_data);
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol = result;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( gVisualTreatmentEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gVisualTreatmentEnum, &pTrackEnumBinding);
  }
  else
  {
    mPrev = gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
    pTrackEnumBinding.mPrev = mPrev;
    pTrackEnumBinding.mNext = &gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
  }
  m_EnumValue = pTrackEnumBinding.m_EnumValue;
  v8 = pTrackEnumBinding.mPrev;
  mNext = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  mNext->mPrev = v8;
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  if ( m_EnumValue != -1 )
  {
    if ( v3 )
      UFG::RenderWorld::VisualTreatmentPostEffect_StartVisualTreatment(m_EnumValue, v5, i_user_data);
    else
      UFG::RenderWorld::VisualTreatmentPostEffect_StopAllVisualTreatments();
  }
}

// File Line: 109
// RVA: 0x4E4E60
void __fastcall UFG::TSNIS::MthdC_enable_fullscreen_filter(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **i_array_p; // r8
  int i_user_data; // edi
  bool v5; // si
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mPrev; // rax
  int m_EnumValue; // r10d
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *v8; // rcx
  UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *mNext; // rax
  unsigned int started; // eax
  TracksEnumBinding<unsigned long> pTrackEnumBinding; // [rsp+28h] [rbp-28h] BYREF
  UFG::qSymbol resulta; // [rsp+60h] [rbp+10h] BYREF

  i_array_p = scope->i_data.i_array_p;
  i_user_data = i_array_p[1]->i_data_p->i_user_data;
  v5 = i_array_p[2]->i_data_p->i_user_data != 0;
  UFG::qSymbol::create_from_string(&resulta, *(const char **)(*i_array_p)->i_data_p->i_user_data);
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  pTrackEnumBinding.m_EnumSymbol = resulta;
  *(_QWORD *)&pTrackEnumBinding.m_EnumValue = 0i64;
  pTrackEnumBinding.m_uEnumUID = 0;
  if ( gVisualTreatmentEnum.m_enumLists.size )
  {
    TracksEnum<unsigned long>::ResolveBinding(&gVisualTreatmentEnum, &pTrackEnumBinding);
  }
  else
  {
    mPrev = gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
    gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = &pTrackEnumBinding;
    pTrackEnumBinding.mPrev = mPrev;
    pTrackEnumBinding.mNext = &gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode;
    gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = &pTrackEnumBinding;
  }
  m_EnumValue = pTrackEnumBinding.m_EnumValue;
  v8 = pTrackEnumBinding.mPrev;
  mNext = pTrackEnumBinding.mNext;
  pTrackEnumBinding.mPrev->mNext = pTrackEnumBinding.mNext;
  mNext->mPrev = v8;
  pTrackEnumBinding.mPrev = &pTrackEnumBinding;
  pTrackEnumBinding.mNext = &pTrackEnumBinding;
  if ( m_EnumValue != -1 )
  {
    started = UFG::RenderWorld::VisualTreatmentPostEffect_StartVisualTreatment(m_EnumValue, v5, i_user_data);
    *result = SSInstance::pool_new(SSBrain::c_integer_class_p, started);
  }
}

// File Line: 127
// RVA: 0x4E4BD0
void __fastcall UFG::TSNIS::MthdC_disable_fullscreen_filter(SSInvokedMethod *scope, SSInstance **result)
{
  SSData **i_array_p; // rdx
  unsigned int i_user_data; // ecx

  i_array_p = scope->i_data.i_array_p;
  i_user_data = (*i_array_p)->i_data_p->i_user_data;
  if ( i_user_data != -1 )
    UFG::RenderWorld::VisualTreatmentPostEffect_StopVisualTreatment(
      i_user_data,
      *(float *)&i_array_p[1]->i_data_p->i_user_data);
}

// File Line: 140
// RVA: 0x4E4B10
// attributes: thunk
void __fastcall UFG::TSNIS::MthdC_disable_all_fullscreen_filters(SSInvokedMethod *scope, SSInstance **result)
{
  UFG::RenderWorld::VisualTreatmentPostEffect_StopAllVisualTreatments();
}

// File Line: 145
// RVA: 0x4F0F70
void __fastcall UFG::TSNIS::MthdC_skip(SSInvokedMethod *scope, SSInstance **result)
{
  NISManager *Instance; // rax

  Instance = NISManager::GetInstance();
  NISManager::RequestSkip(Instance);
}

// File Line: 150
// RVA: 0x4F26B0
void __fastcall UFG::TSNIS::MthdC_stop(SSInvokedMethod *scope, SSInstance **result)
{
  NISManager *Instance; // rax

  Instance = NISManager::GetInstance();
  NISManager::StopActiveNIS(Instance);
}

// File Line: 158
// RVA: 0x4E7910
void __fastcall UFG::TSNIS::MthdC_get_gameslice(SSInvokedMethod *pScope, SSActor **ppResult)
{
  UFG::SSGameSlice *i_obj_p; // rcx

  if ( ppResult )
  {
    i_obj_p = `anonymous namespace::gpNISGameSlice.i_obj_p;
    if ( `anonymous namespace::gpNISGameSlice.i_obj_p
      && `anonymous namespace::gpNISGameSlice.i_ptr_id == `anonymous namespace::gpNISGameSlice.i_obj_p->i_ptr_id )
    {
      ++`anonymous namespace::gpNISGameSlice.i_obj_p->i_ref_count;
      *ppResult = &i_obj_p->SSActor;
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
  return NISManager::GetInstance()->mState == STATE_INVALID;
}

// File Line: 186
// RVA: 0x4DC880
bool __fastcall UFG::TSNIS::Coro_play_private(SSInvokedCoroutine *pScope)
{
  NISInstance *i_user_data; // rbx
  NISManager *Instance; // rax

  if ( pScope->i_update_count )
    return NISManager::GetInstance()->mState == STATE_INVALID;
  i_user_data = (NISInstance *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  Instance = NISManager::GetInstance();
  if ( !NISManager::Play(Instance, i_user_data) )
    return 1;
  pScope->i_update_interval = 0.30000001;
  return 0;
}

// File Line: 224
// RVA: 0x4E6BD0
void __fastcall UFG::TSNIS::MthdC_flash_subtitles(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  SSInstance *i_data_p; // rbx
  SSInstance *v5; // r14
  unsigned int v6; // edi
  UFG::allocator::free_link *v7; // rcx
  __int64 *v8; // rax
  __int64 *v9; // rbx
  UFG::UIHKTextOverlay *Instance; // rax
  __int64 v11; // rcx
  _QWORD *v12; // rax

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v5 = i_array_p[1]->i_data_p;
  v6 = 0;
  v7 = UFG::qMalloc(0xD0ui64, "UISubtitleMessage", 0i64);
  if ( v7 )
  {
    UFG::UISubtitleMessage::UISubtitleMessage(
      (UFG::UISubtitleMessage *)v7,
      TYPE_SUBTITLE_TEXT,
      *(const char **)i_data_p->i_user_data,
      0i64);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  *((_DWORD *)v9 + 6) = v5->i_user_data;
  Instance = UFG::UIHKTextOverlay::getInstance();
  if ( Instance )
  {
    v6 = UFG::UIHKTextOverlay::QueueMessage(Instance, (UFG::UISubtitleMessage *)v9);
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
  if ( ppResult )
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, v6);
}

// File Line: 251
// RVA: 0x4EA4E0
void __fastcall UFG::TSNIS::MthdC_kill_subtitles(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int i_user_data; // ebx
  UFG::UIHKTextOverlay *Instance; // rax

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  Instance = UFG::UIHKTextOverlay::getInstance();
  if ( Instance )
    UFG::UIHKTextOverlay::KillSubtitles(Instance, i_user_data);
}

// File Line: 263
// RVA: 0x4EF1E0
void __fastcall UFG::TSNIS::MthdC_set_subtitles_y_offset(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rbx
  UFG::UIHKTextOverlay *Instance; // rax

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  Instance = UFG::UIHKTextOverlay::getInstance();
  if ( Instance )
    UFG::UIHKTextOverlay::SetSubtitleYOffset(Instance, *(float *)&i_data_p->i_user_data);
}

// File Line: 276
// RVA: 0x4DD420
bool __fastcall UFG::TSNIS::Coro_show_curtain(SSInvokedCoroutine *pScope)
{
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rbp
  AString *v5; // r15
  AString *v6; // r14
  unsigned int v7; // esi
  bool v8; // di
  unsigned int v9; // eax
  bool v10; // r12
  AStringRef *i_str_ref_p; // rbx
  bool v12; // zf
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v16; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  unsigned int v18; // eax
  bool v19; // di
  AStringRef *v20; // rbx
  AObjReusePool<AStringRef> *v21; // rax
  AObjBlock<AStringRef> *v22; // rcx
  unsigned __int64 v23; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_pool; // rcx
  unsigned int v25; // ebx
  AString str; // [rsp+70h] [rbp+8h] BYREF

  if ( pScope->i_update_count && (!UFG::UIHK_NISOverlay::IsCurtainStable() || UFG::UIHK_NISOverlay::IsCurtainVisible()) )
    return UFG::UIHK_NISOverlay::IsCurtainVisible();
  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v5 = (AString *)i_array_p[1]->i_data_p;
  v6 = (AString *)i_array_p[2]->i_data_p;
  v7 = 0;
  v8 = 1;
  v9 = AMemory::c_req_byte_size_func(1u);
  str.i_str_ref_p = AStringRef::pool_new(&customCaption, 0, v9, 1u, 0, 1);
  v10 = AString::is_equal(v5 + 4, &str) == 0;
  i_str_ref_p = str.i_str_ref_p;
  v12 = str.i_str_ref_p->i_ref_count-- == 1;
  if ( v12 )
  {
    if ( i_str_ref_p->i_deallocate )
      AMemory::c_free_func(i_str_ref_p->i_cstr_p);
    pool = AStringRef::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)i_str_ref_p < i_objects_a
      || (v16 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
          p_i_exp_pool = &pool->i_pool,
          !v16) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
  }
  if ( v10 )
  {
    v7 = UFG::TiDo::CalcWwiseUid(v5[4].i_str_ref_p->i_cstr_p);
    v8 = 0;
  }
  UFG::UIHK_NISOverlay::ShowCurtains(*(float *)&i_data_p->i_user_data, v8);
  if ( !v8 )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, v7, 0i64, 0, 0i64);
  v18 = AMemory::c_req_byte_size_func(1u);
  str.i_str_ref_p = AStringRef::pool_new(&customCaption, 0, v18, 1u, 0, 1);
  v19 = AString::is_equal(v6 + 4, &str) == 0;
  v20 = str.i_str_ref_p;
  v12 = str.i_str_ref_p->i_ref_count-- == 1;
  if ( v12 )
  {
    if ( v20->i_deallocate )
      AMemory::c_free_func(v20->i_cstr_p);
    v21 = AStringRef::get_pool();
    v22 = v21->i_block_p;
    v23 = (unsigned __int64)v22->i_objects_a;
    if ( (unsigned __int64)v20 < v23
      || (v16 = (unsigned __int64)v20 < v23 + 24i64 * v22->i_size, p_i_pool = &v21->i_pool, !v16) )
    {
      p_i_pool = &v21->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_pool, v20);
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
  float v3; // xmm1_4

  if ( pScope->i_update_count && (!UFG::UIHK_NISOverlay::IsCurtainStable() || !UFG::UIHK_NISOverlay::IsCurtainVisible()) )
    return UFG::UIHK_NISOverlay::IsCurtainHidden();
  v3 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
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
  UFG::UIHK_NISOverlay *Instance; // rax
  UFG::UIHK_NISFrameCounterWidget *p_FrameCounter; // rbx

  v2 = *(float *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  Instance = UFG::UIHK_NISOverlay::getInstance();
  if ( Instance )
  {
    p_FrameCounter = &Instance->FrameCounter;
    UFG::UIHK_NISFrameCounterWidget::SetSceneTime(&Instance->FrameCounter, v2);
    UFG::UIHK_NISFrameCounterWidget::SetVisible(p_FrameCounter, 1);
  }
}

// File Line: 380
// RVA: 0x4F0C50
void __fastcall UFG::TSNIS::MthdC_show_scene_time_caption(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rdi
  UFG::UIHK_NISOverlay *Instance; // rax
  UFG::UIHK_NISFrameCounterWidget *p_FrameCounter; // rbx

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  Instance = UFG::UIHK_NISOverlay::getInstance();
  if ( Instance )
  {
    p_FrameCounter = &Instance->FrameCounter;
    UFG::UIHK_NISFrameCounterWidget::SetCaption(&Instance->FrameCounter, *(const char **)i_data_p->i_user_data);
    UFG::UIHK_NISFrameCounterWidget::SetVisible(p_FrameCounter, 1);
  }
}

// File Line: 392
// RVA: 0x4E8F50
void __fastcall UFG::TSNIS::MthdC_hide_scene_time(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHK_NISOverlay *Instance; // rax

  Instance = UFG::UIHK_NISOverlay::getInstance();
  if ( Instance )
    UFG::UIHK_NISFrameCounterWidget::SetVisible(&Instance->FrameCounter, 0);
}

// File Line: 403
// RVA: 0x4E9670
void __fastcall UFG::TSNIS::MthdC_is_nis_playing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  NISManager *Instance; // rax

  if ( ppResult )
  {
    Instance = NISManager::GetInstance();
    *ppResult = SSBoolean::pool_new(Instance->mState != STATE_INVALID);
  }
}

// File Line: 413
// RVA: 0x4E39D0
void __fastcall UFG::TSNIS::MthdC_are_curtains_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool IsCurtainVisible; // al

  if ( ppResult )
  {
    IsCurtainVisible = UFG::UIHK_NISOverlay::IsCurtainVisible();
    *ppResult = SSBoolean::pool_new(IsCurtainVisible);
  }
}

// File Line: 433
// RVA: 0x4F6C30
void __fastcall UFG::TSNISInstance::Mthd_constructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  NISInstance *v3; // r8
  const char *v4; // rbx
  NISManager *Instance; // rax
  SSObjectBase *i_obj_p; // rdx

  v3 = 0i64;
  if ( (*pScope->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
  {
    v4 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    Instance = NISManager::GetInstance();
    v3 = NISManager::CreateInstance(Instance, v4);
  }
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    i_obj_p[2].vfptr = (SSObjectBaseVtbl *)v3;
  else
    *(_QWORD *)&MEMORY[0x20] = v3;
}

// File Line: 457
// RVA: 0x4F7EB0
void __fastcall UFG::TSNISInstance::Mthd_destructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  NISInstance *vfptr; // rbx
  NISManager *Instance; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (NISInstance *)i_obj_p[2].vfptr;
  if ( vfptr )
  {
    Instance = NISManager::GetInstance();
    NISManager::DestroyInstance(Instance, vfptr);
  }
}

// File Line: 475
// RVA: 0x5060E0
void __fastcall UFG::TSNISInstance::Mthd_preload(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  NISInstance *vfptr; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (NISInstance *)i_obj_p[2].vfptr;
  if ( vfptr )
    NISInstance::Preload(vfptr);
}

// File Line: 493
// RVA: 0x50E2A0
void __fastcall UFG::TSNISInstance::Mthd_unload(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  NISInstance *vfptr; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (NISInstance *)i_obj_p[2].vfptr;
  if ( vfptr )
    NISInstance::Unload(vfptr, 0);
}

// File Line: 512
// RVA: 0x509DB0
void __fastcall UFG::TSNISInstance::Mthd_set_post_nis_fade_in(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // r8

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( vfptr )
    BYTE6(vfptr->get_topmost_scope) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
}

// File Line: 531
// RVA: 0x509DF0
void __fastcall UFG::TSNISInstance::Mthd_set_post_nis_scene_settings(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rdi
  SSData **i_array_p; // rax
  const char ***p_i_user_data; // rbx
  UFG::qSymbol *v6; // rbx
  UFG::ProgressionTracker *v7; // rax
  UFG::qSymbol result; // [rsp+30h] [rbp+8h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( vfptr )
  {
    i_array_p = pScope->i_data.i_array_p;
    p_i_user_data = (const char ***)&(*i_array_p)->i_data_p->i_user_data;
    if ( (*i_array_p)->i_data_p != (SSInstance *)-32i64 )
    {
      if ( *((_DWORD *)*p_i_user_data + 2) )
      {
        if ( !stricmp(**p_i_user_data, "Settings_Intermediate_Nis") )
        {
          *(_WORD *)((char *)&vfptr->get_topmost_scope + 5) = 1;
        }
        else
        {
          v6 = UFG::qSymbol::create_from_string(&result, **p_i_user_data);
          v7 = UFG::ProgressionTracker::Instance();
          vfptr[1].__vecDelDtor = (void *(__fastcall *)(SSObjectBase *, unsigned int))UFG::ProgressionTracker::FindSceneSettings(
                                                                                        v7,
                                                                                        v6);
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
  SSClass::register_method_func(v0, &ASymbolX_ctor, UFG::TSNISInstance::Mthd_constructor, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v0, &ASymbolX_dtor, UFG::TSNISInstance::Mthd_destructor, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v0, "preload", UFG::TSNISInstance::Mthd_preload, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v0, "unload", UFG::TSNISInstance::Mthd_unload, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    v0,
    "set_post_nis_fade_in",
    UFG::TSNISInstance::Mthd_set_post_nis_fade_in,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    v0,
    "set_post_nis_scene_settings",
    UFG::TSNISInstance::Mthd_set_post_nis_scene_settings,
    SSBindFlag_instance_no_rebind);
}

