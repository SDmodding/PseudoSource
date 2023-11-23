// File Line: 205
// RVA: 0x512270
SkookumVals *__fastcall Skookum::get_lib_vals()
{
  SkookumVals *result; // rax

  if ( (_S5_11 & 1) == 0 )
  {
    _S5_11 |= 1u;
    SkookumVals::SkookumVals(&sValues);
  }
  result = &sValues;
  if ( sValues.i_using_defaults )
  {
    sValues.i_using_defaults = 0;
    sValues.i_pool_init_instance = 2048;
    sValues.i_pool_init_boolean = 768;
    sValues.i_pool_init_data = 4000;
    sValues.i_pool_init_iexpr = 512;
    sValues.i_pool_init_imethod = 16;
    sValues.i_pool_init_icoroutine = 512;
  }
  return result;
}

// File Line: 418
// RVA: 0x5103F0
UFG::allocator::free_link *__fastcall UFG::SkookumMgr_Malloc(unsigned __int64 size, const char *pAllocName)
{
  UFG::allocator::free_link *result; // rax
  unsigned int v3; // eax

  if ( `anonymous namespace::gSkookumMgrMemoryModeLinear )
  {
    if ( `anonymous namespace::gSkookumMgrMemoryLinearUsed + (unsigned int)size <= `anonymous namespace::gSkookumMgrMemoryLinearBytes )
    {
      result = (UFG::allocator::free_link *)((char *)`anonymous namespace::gpSkookumMgrMemoryLinear
                                           + `anonymous namespace::gSkookumMgrMemoryLinearUsed);
      `anonymous namespace::gSkookumMgrMemoryLinearUsed += size;
      return result;
    }
    `anonymous namespace::gSkookumMgrMemoryModeLinear = 0;
    v3 = 0;
  }
  else
  {
    v3 = `anonymous namespace::gSkookumMgrMemoryPostLinearBytes;
  }
  `anonymous namespace::gSkookumMgrMemoryPostLinearBytes = size + v3;
  return UFG::qMemoryPool::Allocate(&gSkookumMemoryPool, size, pAllocName, 0i64, 1u);
}

// File Line: 464
// RVA: 0x510350
void __fastcall UFG::SkookumMgr_Free(char *pMemory)
{
  if ( pMemory
    && (!`anonymous namespace::gpSkookumMgrMemoryLinear
     || pMemory < `anonymous namespace::gpSkookumMgrMemoryLinear
     || pMemory >= (char *)`anonymous namespace::gpSkookumMgrMemoryLinear
                 + `anonymous namespace::gSkookumMgrMemoryLinearBytes) )
  {
    UFG::qMemoryPool::Free(&gSkookumMemoryPool, pMemory);
  }
}

// File Line: 491
// RVA: 0x510460
__int64 __fastcall UFG::SkookumMgr_SizeReq2Actual(unsigned int sizeRequested)
{
  if ( `anonymous namespace::gSkookumMgrMemoryModeLinear )
    return sizeRequested;
  if ( sizeRequested )
    return ((sizeRequested - 1) & 0xFFFFFFF0) + 16;
  return 0i64;
}

// File Line: 507
// RVA: 0x510390
void __fastcall UFG::SkookumMgr_LinearAllocCallback(unsigned int bytesNeeded)
{
  UFG::allocator::free_link *v2; // rax

  if ( bytesNeeded )
  {
    v2 = UFG::qMemoryPool::Allocate(&gSkookumMemoryPool, bytesNeeded, "Skookum.static_code", 0i64, 1u);
    `anonymous namespace::gSkookumMgrMemoryLinearBytes = bytesNeeded;
    `anonymous namespace::gSkookumMgrMemoryLinearUsed = 0;
    `anonymous namespace::gpSkookumMgrMemoryLinear = v2;
    `anonymous namespace::gSkookumMgrMemoryModeLinear = 1;
  }
  else
  {
    `anonymous namespace::gSkookumMgrMemoryModeLinear = 0;
  }
}

// File Line: 586
// RVA: 0x4E2C00
void UFG::SkookumMgr::MemoryInit(void)
{
  AMemory::override_functions(UFG::SkookumMgr_Malloc, UFG::SkookumMgr_Free, UFG::SkookumMgr_SizeReq2Actual);
  SkookumScript::c_on_script_linear_bytes_f = UFG::SkookumMgr_LinearAllocCallback;
}

// File Line: 642
// RVA: 0x4E2180
void __fastcall UFG::SkookumMgr::InvokeWorldCoroutine(ASymbol *coroutineName, SSInstance *pArg)
{
  SSInstance *args_pp; // [rsp+60h] [rbp+18h] BYREF

  if ( SkookumScript::c_world_p )
  {
    args_pp = pArg;
    SSInstance::coroutine_call(SkookumScript::c_world_p, coroutineName, &args_pp, pArg != 0i64, 1, 0.0, 0i64, 0i64);
  }
}

// File Line: 690
// RVA: 0x4E22D0
char __fastcall UFG::SkookumMgr::IsReferencedByScripts(UFG::SimObject *pSimObject)
{
  signed __int16 m_Flags; // dx
  UFG::TSActorComponent *m_pComponent; // rax
  char v3; // dl
  UFG::TSActor *i_obj_p; // rcx

  if ( !pSimObject )
    return 0;
  m_Flags = pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = (UFG::TSActorComponent *)pSimObject->m_Components.p[4].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      m_pComponent = (UFG::TSActorComponent *)pSimObject->m_Components.p[3].m_pComponent;
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::TSActorComponent *)pSimObject->m_Components.p[2].m_pComponent;
    }
    else
    {
      m_pComponent = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                pSimObject,
                                                UFG::TSActorComponent::_TypeUID);
    }
  }
  else
  {
    m_pComponent = (UFG::TSActorComponent *)pSimObject->m_Components.p[4].m_pComponent;
  }
  v3 = 0;
  if ( m_pComponent )
  {
    i_obj_p = m_pComponent->mpActor.i_obj_p;
    if ( i_obj_p )
    {
      if ( m_pComponent->mpActor.i_ptr_id == i_obj_p->i_ptr_id && (i_obj_p->i_ref_count & 0x7FFFFFFF) > 1 )
        return 1;
    }
  }
  return v3;
}

// File Line: 755
// RVA: 0x4E1770
void UFG::SkookumMgr::Init(void)
{
  SSDebug::c_engine_present_b = 1;
  if ( !bBindRegistered )
  {
    SSBrain::register_bind_atomics_func(UFG::SkookumMgr::BindAtomics);
    bBindRegistered = 1;
  }
  UFG::SkookumMgr::LoadCompiledBinary();
}

// File Line: 865
// RVA: 0x4E2730
void UFG::SkookumMgr::LoadCompiledBinary(void)
{
  unsigned int *v0; // rax
  char *v1; // rbx
  ADatum::Reference *i_dref_p; // rbx
  ADatum datum; // [rsp+50h] [rbp+8h] BYREF
  __int64 loaded_size; // [rsp+58h] [rbp+10h] BYREF

  if ( UFG::StreamFileWrapper::FileExists("Data\\Scripts\\Classes.skoo-bin") )
  {
    loaded_size = 0i64;
    v0 = (unsigned int *)UFG::StreamFileWrapper::ReadEntireFile(
                           "Data\\Scripts\\Classes.skoo-bin",
                           &loaded_size,
                           0i64,
                           0,
                           "StreamFileWrapper::ReadEntireFile");
    v1 = (char *)v0;
    if ( v0 )
    {
      ADatum::ADatum(&datum, v0, 0xFFFFFFFF, loaded_size, 0);
      if ( (unsigned int)SSBrain::is_datum_valid(&datum) )
      {
        UFG::qFreeEntireFile(v1, 0i64);
      }
      else
      {
        SkookumScript::initialize_pre_load();
        SSBrain::assign_datum(&datum);
        UFG::qFreeEntireFile(v1, 0i64);
        SkookumScript::initialize_post_load();
        SkookumScript::initialize_session(1);
        SkookumScript::enable_flag(1, 1);
      }
      i_dref_p = datum.i_dref_p;
      if ( datum.i_dref_p->i_references-- == 1 )
      {
        if ( i_dref_p->i_deallocate )
          operator delete[](i_dref_p->i_buffer_p);
        operator delete[](i_dref_p);
      }
    }
  }
}

// File Line: 1038
// RVA: 0x4CC8A0
void __fastcall UFG::SkookumMgr::BindAtomics()
{
  UFG::TSMatrix44 *v0; // rcx
  SSClass *v1; // rbx
  SSClass *v2; // rbx
  SSClass *v3; // rbx
  SSClass *v4; // rax
  SSClass *v5; // rbx
  SSClass *v6; // rax
  SSClass *v7; // rbx
  SSClass *v8; // rax
  UFG::Editor::TSDAGPath *v9; // rcx
  UFG::Editor::TSEditor *v10; // rcx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]
  ASymbol rebindg; // [rsp+20h] [rbp-18h]
  ASymbol rebindh; // [rsp+20h] [rbp-18h]

  UFG::TSVector3::BindAtomics();
  UFG::TSMatrix44::BindAtomics(v0);
  UFG::TSTransform::BindAtomics();
  UFG::TSActor::BindAtomics();
  LOBYTE(rebind.i_uid) = 0;
  v1 = SSBrain::get_class("Debug");
  SSClass::register_method_func(
    v1,
    "progression_recompile",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    v1,
    "tweaker_section_remove",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    1,
    rebinda);
  UFG::TSAIPathMarker::mspClass = SSBrain::get_class("AIPathMarker");
  SSClass::register_method_func(
    UFG::TSAIPathMarker::mspClass,
    "get_arrival_tolerance",
    UFG::TSAIPathMarker::Mthd_get_arrival_tolerance,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSAIPathMarker::mspClass,
    "get_speed",
    UFG::TSAIPathMarker::Mthd_get_speed,
    SSBindFlag_instance_no_rebind);
  UFG::TSDoor::BindAtomics();
  UFG::TSDynamicEncounter::BindAtomics();
  v2 = SSBrain::get_class("Prop");
  SSClass::register_method_func(v2, "get_damage", UFG::TSProp::Mthd_get_damage, SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(v2, "is_collected", UFG::TSProp::Mthd_is_collected, SSBindFlag_instance_no_rebind);
  UFG::TSEffect::BindAtomics();
  UFG::TSPropertySet::BindAtomics();
  UFG::TSMarker::BindAtomics();
  UFG::TSSpawnPoint::BindAtomics();
  UFG::TSInterestPoint::BindAtomics();
  UFG::TSCollectible::BindAtomics();
  UFG::TSTriggerRegion::BindAtomics();
  UFG::TSCombatRegion::BindAtomics();
  v3 = SSBrain::get_class("NISScriptSystem");
  SSClass::register_method_func(
    v3,
    "get_nis_path",
    UFG::TSNISScriptSystem::Mthd_get_nis_path,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    v3,
    "get_active_gameslices",
    UFG::TSNISScriptSystem::Mthd_get_active_gameslices,
    SSBindFlag_instance_no_rebind);
  UFG::TSMeleeScriptSystem::BindAtomics();
  UFG::TSTimer::BindAtomics();
  UFG::TSWorld::BindAtomics();
  UFG::TSSceneLayer::BindAtomics();
  UFG::TSSimObject::BindAtomics();
  UFG::TSAnimation::BindAtomics();
  UFG::TSAnimationResource::BindAtomics();
  UFG::TSNIS::BindAtomics();
  UFG::TSNISInstance::BindAtomics();
  UFG::TSSmoketest::BindAtomics();
  UFG::TSHKMetrics::BindAtomics();
  UFG::TSCamera::BindAtomics();
  UFG::TSCharacter::BindAtomics();
  UFG::TSCharacterSearch::BindAtomics();
  UFG::TSPlayer::BindAtomics();
  UFG::TSOnline::BindAtomics();
  v4 = SSBrain::get_class("Telemetry");
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    v4,
    "send_new_game_telemetry",
    UFG::TSTelemetry::MthdC_send_new_game_telemetry,
    1,
    rebindb);
  UFG::TSGameSlice::BindAtomics();
  UFG::TSAudioEmitter::BindAtomics();
  UFG::TSSnapshotData::BindAtomics();
  UFG::TSScriptedDialogue::BindAtomics();
  UFG::TSScriptedDialogueElement::BindAtomics();
  UFG::TSUI::BindAtomics();
  UFG::TSMinimap::BindAtomics();
  UFG::TSPDA::BindAtomics();
  UFG::TSDialog::BindAtomics();
  UFG::SkookumMgr::mspObjectiveHintClass = (SSActorClass *)SSBrain::get_class("ObjectiveHint");
  SSClass::register_method_func(
    UFG::SkookumMgr::mspObjectiveHintClass,
    "get_caption",
    UFG::TSObjectiveHint::Mthd_get_caption,
    SSBindFlag_instance_no_rebind);
  UFG::TSUI_ListMenu::BindAtomics();
  UFG::TSUI_Garage::BindAtomics();
  UFG::TSUI_Helpbar::BindAtomics();
  UFG::TSUI_MissionComplete::BindAtomics();
  LOBYTE(rebindc.i_uid) = 0;
  v5 = SSBrain::get_class("GameLog");
  SSClass::register_method_func(v5, "add", UFG::TSUI_GameLog::MthdC_add, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v5, "clear", UFG::TSUI_GameLog::MthdC_clear, 1, rebindd);
  UFG::TSUI_FightClubUI::BindAtomics();
  UFG::TSUI_FightTutorial::BindAtomics();
  UFG::TSUI_MartialArts::BindAtomics();
  UFG::TSMinigame::BindAtomics();
  UFG::TSBugplanting::BindAtomics();
  UFG::TSCockfighting::BindAtomics();
  v6 = SSBrain::get_class("Hacking");
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(v6, "is_successful", UFG::TSHacking::MthdC_is_successful, 1, rebinde);
  UFG::TSKaraoke::BindAtomics();
  LOBYTE(rebindf.i_uid) = 0;
  v7 = SSBrain::get_class("Lockpicking");
  SSClass::register_method_func(v7, "set_difficulty", UFG::TSLockpicking::MthdC_set_difficulty, 1, rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(v7, "is_successful", UFG::TSLockpicking::MthdC_is_successful, 1, rebindg);
  UFG::TSPhonetrace::BindAtomics();
  UFG::TSPokerDice::BindAtomics();
  v8 = SSBrain::get_class("SafeCracking");
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(v8, "is_successful", UFG::TSSafeCracking::MthdC_is_successful, 1, rebindh);
  UFG::TSSpyPC::BindAtomics();
  UFG::TSHUD::BindAtomics();
  UFG::TSUI_HUD_ActionButton::BindAtomics();
  UFG::TSUI_HUD_GameplayHelp::BindAtomics();
  UFG::TSUI_HUD_HintText::BindAtomics();
  UFG::TSUI_HUD_PerkObjective::BindAtomics();
  UFG::TSUI_HUD_MissionHealth::BindAtomics();
  UFG::TSUI_HUD_Race::BindAtomics();
  UFG::TSGameplayUtil::BindAtomics();
  UFG::WheeledVehicleManagerScriptInterface::BindAtomics();
  UFG::PhotoManager::BindAtomics();
  UFG::RaceManager::BindAtomics();
  UFG::TSVehicle::BindAtomics();
  UFG::TSAudio::BindAtomics();
  UFG::Editor::TSDAGPath::BindAtomics(v9);
  UFG::Editor::TSEditor::BindAtomics(v10);
}

// File Line: 1156
// RVA: 0x4E2120
void UFG::SkookumMgr::InvokeOnProjectInit(void)
{
  SSInstance *args_pp; // [rsp+50h] [rbp+8h] BYREF

  if ( SkookumScript::c_world_p )
  {
    args_pp = 0i64;
    SSInstance::coroutine_call(
      SkookumScript::c_world_p,
      (ASymbol *)&qSymbol__on_init_project,
      &args_pp,
      0,
      1,
      0.0,
      0i64,
      0i64);
  }
}

// File Line: 1167
// RVA: 0x4E20D0
void UFG::SkookumMgr::InvokeOnLocationChange(void)
{
  SSInstance *args_pp; // [rsp+50h] [rbp+8h] BYREF

  if ( SkookumScript::c_world_p )
  {
    args_pp = 0i64;
    SSInstance::coroutine_call(
      SkookumScript::c_world_p,
      (ASymbol *)&qSymbol__on_change_location,
      &args_pp,
      0,
      1,
      0.0,
      0i64,
      0i64);
  }
}

// File Line: 1214
// RVA: 0x5117A0
// attributes: thunk
void __fastcall UFG::SkookumMgr::Update(float simDelta)
{
  SkookumScript::update_delta(simDelta);
}

// File Line: 1229
// RVA: 0x4E08A0
void UFG::SkookumMgr::EndScene(void)
{
  SSInstance *args_pp; // [rsp+50h] [rbp+8h] BYREF

  if ( SkookumScript::c_world_p )
  {
    args_pp = 0i64;
    SSInstance::coroutine_call(
      SkookumScript::c_world_p,
      (ASymbol *)&qSymbol__on_end_scene,
      &args_pp,
      0,
      1,
      0.0,
      0i64,
      0i64);
  }
  SkookumScript::enable_behavior(0);
}

// File Line: 1243
// RVA: 0x510530
void __fastcall UFG::SkookumMgr::StartScene(bool initialPass)
{
  if ( !SkookumScript::c_world_p || (SkookumScript::c_world_p->i_actor_flags & 1) == 0 )
    SkookumScript::enable_behavior(1);
}

// File Line: 1261
// RVA: 0x4DF3C0
void UFG::SkookumMgr::Deinit(void)
{
  SkookumScript::deinitialize_session();
  SkookumScript::deinitialize();
}

// File Line: 1290
// RVA: 0x4D9930
void __fastcall UFG::SkookumMgr::ConstructCodeBlockFromScript(AString *destText, char *scriptText)
{
  __int64 v4; // rbx
  unsigned int v5; // eax
  bool v6; // bp
  unsigned int v7; // edx
  __int64 v8; // rbx
  unsigned int v9; // r8d
  const char *v10; // rdx
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v16; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString v18; // [rsp+50h] [rbp+8h] BYREF

  v4 = -1i64;
  do
    ++v4;
  while ( scriptText[v4] );
  v5 = AMemory::c_req_byte_size_func(v4 + 1);
  v18.i_str_ref_p = AStringRef::pool_new(scriptText, v4, v5, 1u, 0, 1);
  v6 = AString::find_reverse(&v18, 41, 1u, 0i64, 0, 0xFFFFFFFF) == 0;
  v7 = v18.i_str_ref_p->i_length + 3 + 2 * v6;
  if ( v7 >= destText->i_str_ref_p->i_size
    || destText->i_str_ref_p->i_ref_count + destText->i_str_ref_p->i_read_only != 1 )
  {
    AString::set_size_buffer(destText, v7);
  }
  destText->i_str_ref_p->i_length = 0;
  *destText->i_str_ref_p->i_cstr_p = 0;
  v8 = destText->i_str_ref_p->i_length + 1;
  if ( (unsigned int)v8 >= destText->i_str_ref_p->i_size
    || destText->i_str_ref_p->i_ref_count + destText->i_str_ref_p->i_read_only != 1 )
  {
    AString::set_size(destText, v8);
  }
  destText->i_str_ref_p->i_cstr_p[(unsigned int)(v8 - 1)] = 91;
  destText->i_str_ref_p->i_cstr_p[v8] = 0;
  destText->i_str_ref_p->i_length = v8;
  AString::append(destText, scriptText, 0xFFFFFFFF);
  if ( v6 )
  {
    v9 = 4;
    v10 = "()\n]";
  }
  else
  {
    v9 = 2;
    v10 = "\n]";
  }
  AString::append(destText, v10, v9);
  i_str_ref_p = v18.i_str_ref_p;
  if ( v18.i_str_ref_p->i_ref_count-- == 1 )
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
}

// File Line: 1356
// RVA: 0x50F670
SSInvokedDeferrableMethod *__fastcall UFG::SkookumMgr::RunExternalCodeBlock(
        SSCode *pCode,
        SSClass *pClass,
        SSInstance *pScope,
        SSObjectBaseVtbl *pFinished,
        SSInstance **ppResult)
{
  UFG::qStaticSymbol *v9; // rdi
  SSParameters *v10; // rax
  SSInvokedDeferrableMethod *v11; // rax
  SSInvokedDeferrableMethod *v12; // rbx
  SSInvokedBase *v13; // rax
  bool v14; // zf
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rcx
  SSParameters params_p; // [rsp+28h] [rbp-50h] BYREF

  SSParameters::SSParameters(&params_p);
  v9 = (UFG::qStaticSymbol *)AMemory::c_malloc_func(0x28ui64, "SSMethod");
  if ( v9 )
  {
    v10 = SSParameters::get_or_create(&params_p);
    v9[2].mUID = qSymbol_External_Method_Call.mUID;
    *(_QWORD *)&v9[4].mUID = pClass;
    *(_QWORD *)&v9->mUID = &SSInvokableBase::`vftable;
    *(_QWORD *)&v9[6].mUID = v10;
    if ( v10 )
      ++v10->i_ref_count;
    *(_QWORD *)&v9->mUID = &SSMethodBase::`vftable;
    *(_QWORD *)&v9->mUID = &SSMethod::`vftable;
    *(_QWORD *)&v9[8].mUID = pCode;
  }
  else
  {
    v9 = 0i64;
  }
  v11 = (SSInvokedDeferrableMethod *)AMemory::c_malloc_func(0x80ui64, "SSIExternalMethodCallWrapper");
  v12 = v11;
  if ( v11 )
  {
    SSInvokedDeferrableMethod::SSInvokedDeferrableMethod(v11, pScope, (SSMethodBase *)v9);
    v12->vfptr = (SSObjectBaseVtbl *)&SSIExternalMethodCallWrapper::`vftable;
    v12[1].vfptr = 0i64;
  }
  else
  {
    v12 = 0i64;
  }
  v12[1].vfptr = pFinished;
  v13 = SSMethod::invoke_deferred((SSMethod *)v12->i_method_p, v12, v12, ppResult);
  v14 = v13 == 0i64;
  if ( v13 )
  {
    i_prev_p = v12->i_calls.i_sentinel.i_prev_p;
    v12->i_calls.i_sentinel.i_prev_p = &v13->AListNode<SSInvokedBase,SSInvokedBase>;
    i_prev_p->i_next_p = &v13->AListNode<SSInvokedBase,SSInvokedBase>;
    v13->i_prev_p = i_prev_p;
    v13->i_next_p = &v12->i_calls.i_sentinel;
    ++v12->i_pending_count;
    v14 = v13 == 0i64;
  }
  if ( v14 )
  {
    if ( pFinished )
      LOBYTE(pFinished->__vecDelDtor) = 1;
    v12->vfptr->__vecDelDtor(v12, 1u);
    v12 = 0i64;
  }
  else if ( pFinished )
  {
    LOBYTE(pFinished->__vecDelDtor) = 0;
  }
  SSParameters::~SSParameters(&params_p);
  return v12;
}

