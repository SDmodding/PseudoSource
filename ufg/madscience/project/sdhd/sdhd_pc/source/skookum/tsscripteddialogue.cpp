// File Line: 68
// RVA: 0x4CB9D0
void __fastcall UFG::TSScriptedDialogue::TSScriptedDialogue(UFG::TSScriptedDialogue *this, UFG::ScriptedConversation *conv, ASymbol *name, SSActorClass *pClass)
{
  UFG::ScriptedConversation *v4; // rbx
  UFG::TSScriptedDialogue *v5; // rdi

  v4 = conv;
  v5 = this;
  SSActor::SSActor((SSActor *)&this->vfptr, name, pClass, 1);
  v5->vfptr = (SSObjectBaseVtbl *)&UFG::TSScriptedDialogue::`vftable';
  v5->m_conversation = v4;
}

// File Line: 92
// RVA: 0x4D59F0
void UFG::TSScriptedDialogue::BindAtomics(void)
{
  UFG::TSScriptedDialogue::mspScriptedDialogueClass = (SSActorClass *)SSBrain::get_class("ScriptedDialogue");
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "add_element",
    UFG::TSScriptedDialogue::Mthd_add_element,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "get_element",
    UFG::TSScriptedDialogue::Mthd_get_element,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "add_element_by_reference",
    UFG::TSScriptedDialogue::Mthd_add_element_by_reference,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "add_interrupt_elements",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "add_resume_elements",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "interrupt",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "is_finished",
    UFG::TSScriptedDialogue::Mthd_is_finished,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "is_interrupted",
    UFG::TSScriptedDialogue::Mthd_is_interrupted,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "is_stopped",
    UFG::TSScriptedDialogue::Mthd_is_stopped,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "is_playing",
    UFG::TSScriptedDialogue::Mthd_is_playing,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "is_inactive",
    UFG::TSScriptedDialogue::Mthd_is_inactive,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "destroy",
    UFG::TSScriptedDialogue::Mthd_destroy,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "stop",
    UFG::TSScriptedDialogue::Mthd_stop,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "stop_after_line",
    UFG::TSScriptedDialogue::Mthd_stop_after_line,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "play",
    UFG::TSScriptedDialogue::Mthd_play,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "next_line",
    UFG::TSScriptedDialogue::Mthd_next_line,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "first_line_of_next_group",
    UFG::TSScriptedDialogue::Mthd_move_to_next_group,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "prev_line",
    UFG::TSScriptedDialogue::Mthd_prev_line,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "reset",
    UFG::TSScriptedDialogue::Mthd_reset,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "restart",
    UFG::TSScriptedDialogue::Mthd_restart,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "auto_delete",
    UFG::TSScriptedDialogue::Mthd_auto_delete,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "is_tag_interruptable",
    UFG::TSScriptedDialogue::Mthd_set_tag_interruptable,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "set_topic",
    UFG::TSScriptedDialogue::Mthd_set_topic,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "disable_distance_cutoff",
    UFG::TSScriptedDialogue::Mthd_disable_distance_cutoff,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "enable_distance_cutoff",
    UFG::TSScriptedDialogue::Mthd_enable_distance_cutoff,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "disable_interrupts",
    UFG::TSScriptedDialogue::Mthd_disable_interrupts,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "enable_interrupts",
    UFG::TSScriptedDialogue::Mthd_enable_interrupts,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "disable_car_exit_interrupts",
    UFG::TSScriptedDialogue::Mthd_disable_car_exit_interrupts,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "enable_car_exit_interrupts",
    UFG::TSScriptedDialogue::Mthd_enable_car_exit_interrupts,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "disable_subtitles",
    UFG::TSScriptedDialogue::Mthd_disable_subtitles,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "enable_subtitles",
    UFG::TSScriptedDialogue::Mthd_enable_subtitles,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "set_cutoff_distance",
    UFG::TSScriptedDialogue::Mthd_set_cutoff_distance,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "get_cutoff_distance",
    UFG::TSScriptedDialogue::Mthd_get_cutoff_distance,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "set_avoid_repeating",
    UFG::TSScriptedDialogue::Mthd_set_avoid_repeating_last,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "set_shuffle",
    UFG::TSScriptedDialogue::Mthd_set_shuffle,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "set_priority",
    UFG::TSScriptedDialogue::Mthd_set_priority,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "get_elements_group_count",
    UFG::TSScriptedDialogue::Mthd_num_element_groups,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "is_playing_last_line_in_group",
    UFG::TSScriptedDialogue::Mthd_is_playing_last_line_in_group,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "is_in_last_group",
    UFG::TSScriptedDialogue::Mthd_is_in_last_group,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "add_animation_bank",
    UFG::TSScriptedDialogue::Mthd_add_animation_bank,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "set_external_source_playback_event",
    UFG::TSScriptedDialogue::Mthd_set_external_source_playback_event,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "force_finish_all_scripted_conversations",
    UFG::TSScriptedDialogue::Mthd_force_finish_all_scripted_conversations,
    1,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "_wait_until_finished",
    UFG::TSScriptedDialogue::Coro_wait_until_finished,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "_wait_until_stopped",
    UFG::TSScriptedDialogue::Coro_wait_until_stopped,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "_play_until_finished",
    UFG::TSScriptedDialogue::Coro_play_finished,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "_play_until_stopped",
    UFG::TSScriptedDialogue::Coro_play_stopped,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "_play_until_stopped_or_finished",
    UFG::TSScriptedDialogue::Coro_play_stopped_or_finished,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "_stop",
    UFG::TSScriptedDialogue::Coro_stop,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "create",
    UFG::TSScriptedDialogue::MthdC_create,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "find_named",
    UFG::TSScriptedDialogue::MthdC_find_named,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "get_named",
    UFG::TSScriptedDialogue::MthdC_get_named,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "query_context",
    UFG::TSScriptedDialogue::MthdC_query_context,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogue::mspScriptedDialogueClass->vfptr,
    "query_context_character",
    UFG::TSScriptedDialogue::MthdC_query_context_character,
    1,
    0);
}

// File Line: 165
// RVA: 0x4F4150
void __fastcall UFG::TSScriptedDialogue::Mthd_add_element_by_reference(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r8
  SSInstance *v3; // rbx
  SSObjectBase *v4; // rcx
  const char *v5; // rax

  v2 = pScope;
  v3 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( v3 && (SSActorClass *)v3->i_class_p == UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass )
  {
    v4 = pScope->i_scope_p.i_obj_p;
    if ( !v4 || v2->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    UFG::Conversation::AddElement((UFG::Conversation *)v4[8].vfptr, (UFG::ConversationElement *)v3[2].i_user_data);
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v5 = UFG::ConversationElement::ToString((UFG::ConversationElement *)v3[2].i_user_data);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "add_element", v5);
    }
  }
}

// File Line: 208
// RVA: 0x4F3E10
void __fastcall UFG::TSScriptedDialogue::Mthd_add_element(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // r14
  SSActor *v3; // rsi
  SSClass *v4; // rbx
  SSActor *v5; // rbp
  SSClass *v6; // rbx
  SSData **v7; // rcx
  SSInstance *v8; // r13
  unsigned __int64 v9; // rax
  unsigned int v10; // er15
  __int64 v11; // rdi
  unsigned int v12; // ebx
  SSObjectBase *v13; // rdi
  UFG::allocator::free_link *v14; // rax
  UFG::allocator::free_link *v15; // rbx
  SSInstance *v16; // r15
  SSClass *v17; // rcx
  UFG::SimObject *v18; // rdx
  SSInstance *v19; // rax
  const char *v20; // rax
  __int64 v21; // rsi
  __int64 v22; // rcx
  UFG::SimObject *v23; // rdx
  __int64 v24; // rax
  const char *v25; // rax
  const char *v26; // rax
  UFG::qString v27; // [rsp+38h] [rbp-50h]

  v2 = pScope;
  v3 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !v3 )
    goto LABEL_6;
  v4 = v3->i_class_p;
  if ( !v4->vfptr->is_actor_class((SSClassDescBase *)v3->i_class_p) )
  {
    if ( v4 == SSBrain::c_symbol_class_p && LODWORD(v3->i_user_data) != -1 )
    {
      v3 = SSActor::find((ASymbol *)&v3->i_user_data);
      goto LABEL_7;
    }
LABEL_6:
    v3 = 0i64;
  }
LABEL_7:
  v5 = *(SSActor **)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64);
  if ( !v5 )
    goto LABEL_48;
  v6 = v5->i_class_p;
  if ( v6->vfptr->is_actor_class((SSClassDescBase *)v5->i_class_p) )
    goto LABEL_13;
  if ( v6 == SSBrain::c_symbol_class_p && LODWORD(v5->i_user_data) != -1 )
    v5 = SSActor::find((ASymbol *)&v5->i_user_data);
  else
LABEL_48:
    v5 = 0i64;
LABEL_13:
  v7 = v2->i_data.i_array_p;
  v8 = v7[2]->i_data_p;
  v9 = v7[3]->i_data_p->i_user_data;
  v10 = *(_DWORD *)v9;
  v11 = *(_QWORD *)(v9 + 8);
  UFG::qString::qString(&v27, &customWorldMapCaption);
  v12 = 0;
  if ( v10 )
  {
    do
    {
      UFG::qString::operator+=(&v27, **(const char ***)(*(_QWORD *)v11 + 32i64));
      if ( v12 < v10 - 1 )
        UFG::qString::operator+=(&v27, ".");
      ++v12;
      v11 += 8i64;
    }
    while ( v12 < v10 );
  }
  v13 = v2->i_scope_p.i_obj_p;
  if ( !v13 || v2->i_scope_p.i_ptr_id != v13->i_ptr_id )
    v13 = 0i64;
  v14 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0xC0ui64, "add_element.ScriptedConversationElement", 0i64, 1u);
  v15 = v14;
  if ( v14 )
  {
    UFG::ConversationElement::ConversationElement((UFG::ConversationElement *)v14, 0);
    v15->mNext = (UFG::allocator::free_link *)&UFG::ScriptedConversationElement::`vftable';
    v15[20].mNext = 0i64;
    v15[21].mNext = 0i64;
    v15[22].mNext = 0i64;
    v15[23].mNext = 0i64;
    UFG::ScriptedConversationElement::SetupScript((UFG::ScriptedConversationElement *)v15, (ASymbol *)&v13[4].i_ptr_id);
  }
  else
  {
    v15 = 0i64;
  }
  v16 = (*v2->i_data.i_array_p)->i_data_p;
  if ( v16
    && (v17 = v16->i_class_p) != 0i64
    && (((unsigned __int8 (*)(void))v17->vfptr->is_actor_class)() || LODWORD(v16->i_user_data) != -1) )
  {
    if ( v3 && (v18 = *(UFG::SimObject **)&v3[1].i_icoroutines_to_update.i_count) != 0i64 )
    {
      UFG::ConversationElement::SetSpeaker((UFG::ConversationElement *)v15, v18);
    }
    else
    {
      v15[22].mNext = (UFG::allocator::free_link *)(*v2->i_data.i_array_p)->i_data_p;
      v19 = (*v2->i_data.i_array_p)->i_data_p;
      ++v19->i_ref_count;
    }
  }
  else
  {
    v20 = UFG::ConversationElement::ToString((UFG::ConversationElement *)v15);
    UFG::qPrintf("TSScriptedDialogue: possible error adding -> %s\n", v20);
  }
  v21 = *(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64);
  if ( v21
    && (v22 = *(_QWORD *)(v21 + 24)) != 0
    && ((*(unsigned __int8 (**)(void))(*(_QWORD *)v22 + 64i64))() || *(_DWORD *)(v21 + 32) != -1) )
  {
    if ( v5 && (v23 = *(UFG::SimObject **)&v5[1].i_icoroutines_to_update.i_count) != 0i64 )
    {
      UFG::ConversationElement::SetTarget((UFG::ConversationElement *)v15, v23);
    }
    else
    {
      v15[23].mNext = *(UFG::allocator::free_link **)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64);
      v24 = *(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 1) + 8i64);
      ++*(_DWORD *)(v24 + 16);
    }
  }
  else
  {
    v25 = UFG::ConversationElement::ToString((UFG::ConversationElement *)v15);
    UFG::qPrintf("TSScriptedDialogue: possible error adding -> %s\n", v25);
  }
  UFG::qString::Set((UFG::qString *)&v15[4], v27.mData, v27.mLength, 0i64, 0);
  LODWORD(v15[9].mNext) = v8->i_user_data;
  if ( v13[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v26 = UFG::ConversationElement::ToString((UFG::ConversationElement *)v15);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "add_element", v26);
    }
    UFG::Conversation::AddElement((UFG::Conversation *)v13[8].vfptr, (UFG::ConversationElement *)v15);
  }
  UFG::qString::~qString(&v27);
}

// File Line: 304
// RVA: 0x50A810
void __fastcall UFG::TSScriptedDialogue::Mthd_set_tag_interruptable(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  bool v3; // bl
  SSObjectBaseVtbl *v4; // rcx
  char *v5; // rax
  __int64 v6; // rax
  UFG::qString v7; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  v4 = v2[8].vfptr;
  if ( v4 )
  {
    LOBYTE(v4[2].set_data_by_name) &= 0xFBu;
    LOBYTE(v4[2].set_data_by_name) |= 4 * v3;
  }
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
    UFG::qString::qString(&v7, "%s : %d", v5, v3, -2i64);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "set_tag_interruptable", *(_QWORD *)(v6 + 24));
    UFG::qString::~qString(&v7);
  }
}

// File Line: 317
// RVA: 0x50AFB0
void __fastcall UFG::TSScriptedDialogue::Mthd_set_topic(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdi
  char *v3; // rbx
  char *v4; // rax
  __int64 v5; // rax
  SSObjectBaseVtbl *v6; // rbx
  UFG::qString v7; // [rsp+28h] [rbp-30h]
  UFG::qSymbolUC v8; // [rsp+60h] [rbp+8h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v8.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      v4 = UFG::qSymbol::as_cstr_dbg(&v8);
      UFG::qString::qString(&v7, "%s : %s", v3, v4, -2i64);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "set_topic", *(_QWORD *)(v5 + 24));
      UFG::qString::~qString(&v7);
    }
    v6 = v2[8].vfptr;
    LODWORD(v6[2].is_actor) = UFG::Conversation::LookupTopic((UFG::qSymbol *)&v8);
  }
}

// File Line: 332
// RVA: 0x4FCBE0
void __fastcall UFG::TSScriptedDialogue::Mthd_get_element(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  SSInstance *v4; // rax
  UFG::Conversation *v5; // rcx
  UFG::ConversationElement *v6; // rax
  SSInstance *v7; // rax
  SSInstance *v8; // rax

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v4 = (*pScope->i_data.i_array_p)->i_data_p;
    v5 = (UFG::Conversation *)v2[8].vfptr;
    if ( v5 && (v6 = UFG::Conversation::GetElement(v5, v4->i_user_data)) != 0i64 )
    {
      v7 = (SSInstance *)v6[1].vfptr;
      *v3 = v7;
      ++v7->i_ref_count;
    }
    else
    {
      v8 = SSBrain::c_nil_p;
      *v3 = SSBrain::c_nil_p;
      ++v8->i_ref_count;
    }
  }
}

// File Line: 354
// RVA: 0x502AD0
void __fastcall UFG::TSScriptedDialogue::Mthd_is_playing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSObjectBaseVtbl *v3; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[8].vfptr;
  if ( v3 )
    *ppResult = (SSInstance *)SSBoolean::pool_new(LODWORD(v3->get_scope_context) == 1);
}

// File Line: 367
// RVA: 0x5013D0
void __fastcall UFG::TSScriptedDialogue::Mthd_is_finished(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSObjectBaseVtbl *v3; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[8].vfptr;
  if ( v3 )
    *ppResult = (SSInstance *)SSBoolean::pool_new(LODWORD(v3->get_scope_context) == 7);
}

// File Line: 379
// RVA: 0x502470
void __fastcall UFG::TSScriptedDialogue::Mthd_is_interrupted(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSObjectBaseVtbl *v3; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[8].vfptr;
  if ( v3 )
    *ppResult = (SSInstance *)SSBoolean::pool_new(LODWORD(v3->get_scope_context) == 3);
}

// File Line: 391
// RVA: 0x5032B0
void __fastcall UFG::TSScriptedDialogue::Mthd_is_stopped(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSObjectBaseVtbl *v3; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[8].vfptr;
  if ( v3 )
    *ppResult = (SSInstance *)SSBoolean::pool_new(LODWORD(v3->get_scope_context) == 6);
}

// File Line: 405
// RVA: 0x5023D0
void __fastcall UFG::TSScriptedDialogue::Mthd_is_inactive(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSObjectBaseVtbl *v3; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[8].vfptr;
  if ( v3 )
    *ppResult = (SSInstance *)SSBoolean::pool_new(LODWORD(v3->get_scope_context) == 0);
}

// File Line: 417
// RVA: 0x4F7D10
void __fastcall UFG::TSScriptedDialogue::Mthd_destroy(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::Conversation *v5; // rcx
  UFG::qString v6; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
    UFG::qString::qString(&v6, "%s ", v3);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "destroy", *(_QWORD *)(v4 + 24));
    UFG::qString::~qString(&v6);
  }
  v5 = (UFG::Conversation *)v2[8].vfptr;
  if ( v5 )
    UFG::ConversationManager::RemoveConversation(v5);
}

// File Line: 427
// RVA: 0x50C150
void __fastcall UFG::TSScriptedDialogue::Mthd_stop(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "stop", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    UFG::Conversation::Stop((UFG::Conversation *)v2[8].vfptr, 0);
  }
}

// File Line: 439
// RVA: 0x502ED0
void __fastcall UFG::TSScriptedDialogue::Mthd_is_playing_last_line_in_group(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  bool v4; // dl
  SSObjectBaseVtbl *v5; // rcx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    v4 = 0;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v5 = v2[8].vfptr;
    if ( v5 )
    {
      if ( LODWORD(v5->get_scope_context) == 1 )
        v4 = UFG::Conversation::IsLastLineInGroup((UFG::Conversation *)v5);
    }
    *v3 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 458
// RVA: 0x501AA0
void __fastcall UFG::TSScriptedDialogue::Mthd_is_in_last_group(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSInstance **v3; // rbx
  bool v4; // dl
  UFG::Conversation *v5; // rcx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = ppResult;
    v4 = 0;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v5 = (UFG::Conversation *)v2[8].vfptr;
    if ( v5 )
      v4 = UFG::Conversation::CurrentGroupIsLast(v5);
    *v3 = (SSInstance *)SSBoolean::pool_new(v4);
  }
}

// File Line: 474
// RVA: 0x4F3B00
void __fastcall UFG::TSScriptedDialogue::Mthd_add_animation_bank(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rdi
  SSObjectBase *v3; // rbx
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rdx
  int v6; // ecx
  void (__fastcall **v7)(SSObjectBase *, ASymbol *, SSInstance *); // rcx
  UFG::allocator::free_link *v8; // rax

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  if ( v3[8].vfptr )
  {
    v4 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
    v5 = v4;
    if ( v4 )
    {
      v6 = v2->i_user_data;
      v4->mNext = v4;
      v4[1].mNext = v4;
      LODWORD(v4[2].mNext) = -1;
      LODWORD(v4[2].mNext) = v6;
    }
    else
    {
      v5 = 0i64;
    }
    v7 = &v3[8].vfptr[1].set_data_by_name;
    v8 = (UFG::allocator::free_link *)*v7;
    v8[1].mNext = v5;
    v5->mNext = v8;
    v5[1].mNext = (UFG::allocator::free_link *)v7;
    *v7 = (void (__fastcall *)(SSObjectBase *, ASymbol *, SSInstance *))v5;
  }
}

// File Line: 486
// RVA: 0x507E70
void __fastcall UFG::TSScriptedDialogue::Mthd_set_external_source_playback_event(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( (*pScope->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
    {
      UFG::qWiseSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      LODWORD(v2[8].vfptr[1].get_topmost_scope) = result;
      _((AMD_HD3D *)result.mUID);
    }
  }
}

// File Line: 498
// RVA: 0x50C240
void __fastcall UFG::TSScriptedDialogue::Mthd_stop_after_line(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "stop_after_line", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    UFG::Conversation::StopAfterCurrentLine((UFG::Conversation *)v2[8].vfptr);
  }
}

// File Line: 509
// RVA: 0x505CC0
void __fastcall UFG::TSScriptedDialogue::Mthd_play(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "play", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    UFG::Conversation::Start((UFG::Conversation *)v2[8].vfptr);
  }
}

// File Line: 521
// RVA: 0x504EF0
void __fastcall UFG::TSScriptedDialogue::Mthd_next_line(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "next_line", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    UFG::Conversation::NextLine((UFG::Conversation *)v2[8].vfptr);
  }
}

// File Line: 532
// RVA: 0x506110
void __fastcall UFG::TSScriptedDialogue::Mthd_prev_line(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "prev_line", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    UFG::Conversation::PrevLine((UFG::Conversation *)v2[8].vfptr);
  }
}

// File Line: 545
// RVA: 0x506970
void __fastcall UFG::TSScriptedDialogue::Mthd_restart(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "restart", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    UFG::Conversation::Restart((UFG::Conversation *)v2[8].vfptr);
  }
}

// File Line: 555
// RVA: 0x506800
void __fastcall UFG::TSScriptedDialogue::Mthd_reset(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "reset", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    UFG::Conversation::Reset((UFG::Conversation *)v2[8].vfptr);
  }
}

// File Line: 580
// RVA: 0x505020
void __fastcall UFG::TSScriptedDialogue::Mthd_num_element_groups(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  unsigned int v3; // er9
  SSInstance **v4; // rbx
  UFG::Conversation *v5; // rcx

  if ( ppResult )
  {
    v2 = pScope->i_scope_p.i_obj_p;
    v3 = 0;
    v4 = ppResult;
    if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
      v2 = 0i64;
    v5 = (UFG::Conversation *)v2[8].vfptr;
    if ( v5 )
      v3 = UFG::Conversation::GetGroupCount(v5);
    *v4 = SSInstance::pool_new(SSBrain::c_integer_class_p, v3);
  }
}

// File Line: 600
// RVA: 0x504EC0
void __fastcall UFG::TSScriptedDialogue::Mthd_move_to_next_group(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  JUMPOUT(v2[8].vfptr, 0i64, UFG::Conversation::MoveToNextGroup);
}

// File Line: 622
// RVA: 0x4F5F00
void __fastcall UFG::TSScriptedDialogue::Mthd_auto_delete(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // di
  SSObjectBase *v3; // rbx
  char *v4; // rax
  __int64 v5; // rax
  SSObjectBaseVtbl *v6; // rax
  UFG::qString v7; // [rsp+28h] [rbp-30h]

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  if ( v3[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3[4].i_ptr_id);
      UFG::qString::qString(&v7, "%s : %d", v4, v2, -2i64);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "set_auto_delete", *(_QWORD *)(v5 + 24));
      UFG::qString::~qString(&v7);
    }
    v6 = v3[8].vfptr;
    LOBYTE(v6[2].set_data_by_name) &= 0xFDu;
    LOBYTE(v6[2].set_data_by_name) |= 2 * v2;
  }
}

// File Line: 635
// RVA: 0x4F83C0
void __fastcall UFG::TSScriptedDialogue::Mthd_disable_distance_cutoff(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "disable_distance_cutoff", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    LOBYTE(v2[8].vfptr[2].set_data_by_name) |= 8u;
  }
}

// File Line: 646
// RVA: 0x4F8A60
void __fastcall UFG::TSScriptedDialogue::Mthd_enable_distance_cutoff(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "enable_distance_cutoff", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    LOBYTE(v2[8].vfptr[2].set_data_by_name) &= 0xF7u;
  }
}

// File Line: 658
// RVA: 0x4F8580
void __fastcall UFG::TSScriptedDialogue::Mthd_disable_subtitles(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "disable_subtitles", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    LOBYTE(v2[8].vfptr[2].set_data_by_name) &= 0x7Fu;
  }
}

// File Line: 669
// RVA: 0x4F91B0
void __fastcall UFG::TSScriptedDialogue::Mthd_enable_subtitles(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "enable_subtitles", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    LOBYTE(v2[8].vfptr[2].set_data_by_name) |= 0x80u;
  }
}

// File Line: 682
// RVA: 0x4F8470
void __fastcall UFG::TSScriptedDialogue::Mthd_disable_interrupts(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "disable_interrupts", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    BYTE1(v2[8].vfptr[2].set_data_by_name) |= 4u;
  }
}

// File Line: 693
// RVA: 0x4F8C20
void __fastcall UFG::TSScriptedDialogue::Mthd_enable_interrupts(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "enable_interrupts", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    BYTE1(v2[8].vfptr[2].set_data_by_name) &= 0xFBu;
  }
}

// File Line: 705
// RVA: 0x4F8330
void __fastcall UFG::TSScriptedDialogue::Mthd_disable_car_exit_interrupts(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "disable_car_exit_interrupts", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    BYTE1(v2[8].vfptr[2].set_data_by_name) &= 0xF7u;
  }
}

// File Line: 716
// RVA: 0x4F88E0
void __fastcall UFG::TSScriptedDialogue::Mthd_enable_car_exit_interrupts(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v2[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "enable_car_exit_interrupts", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    BYTE1(v2[8].vfptr[2].set_data_by_name) |= 8u;
  }
}

// File Line: 730
// RVA: 0x507D20
void __fastcall UFG::TSScriptedDialogue::Mthd_set_cutoff_distance(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rdi
  SSObjectBase *v3; // rbx
  char *v4; // rax
  __int64 v5; // rax
  UFG::qString v6; // [rsp+28h] [rbp-30h]

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  if ( v3[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3[4].i_ptr_id);
      UFG::qString::qString(&v6, "%s : %d", v4, *(float *)&v2->i_user_data, -2i64);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "set_cutoff_distance", *(_QWORD *)(v5 + 24));
      UFG::qString::~qString(&v6);
    }
    LODWORD(v3[8].vfptr[2].as_instance) = v2->i_user_data;
  }
}

// File Line: 745
// RVA: 0x5072D0
void __fastcall UFG::TSScriptedDialogue::Mthd_set_avoid_repeating_last(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rdi
  SSObjectBase *v3; // rbx
  char *v4; // rax
  __int64 v5; // rax
  UFG::qString v6; // [rsp+28h] [rbp-30h]

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  if ( v3[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3[4].i_ptr_id);
      UFG::qString::qString(&v6, "%s : %u", v4, LODWORD(v2->i_user_data), -2i64);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "set_avoid_repeating_last", *(_QWORD *)(v5 + 24));
      UFG::qString::~qString(&v6);
    }
    WORD2(v3[8].vfptr[2].get_data_by_name) = v2->i_user_data;
  }
}

// File Line: 760
// RVA: 0x50A460
void __fastcall UFG::TSScriptedDialogue::Mthd_set_shuffle(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // di
  SSObjectBase *v3; // rbx
  char *v4; // rax
  __int64 v5; // rax
  SSObjectBaseVtbl *v6; // rax
  UFG::qString v7; // [rsp+28h] [rbp-30h]

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  if ( v3[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3[4].i_ptr_id);
      UFG::qString::qString(&v7, "%s : %d", v4, v2, -2i64);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "set_shuffle", *(_QWORD *)(v5 + 24));
      UFG::qString::~qString(&v7);
    }
    v6 = v3[8].vfptr;
    LOBYTE(v6[2].set_data_by_name) &= 0xDFu;
    LOBYTE(v6[2].set_data_by_name) |= 32 * v2;
  }
}

// File Line: 774
// RVA: 0x509F30
void __fastcall UFG::TSScriptedDialogue::Mthd_set_priority(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rdi
  SSObjectBase *v3; // rbx
  char *v4; // rax
  __int64 v5; // rax
  UFG::qString v6; // [rsp+28h] [rbp-30h]

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  if ( v3[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3[4].i_ptr_id);
      UFG::qString::qString(&v6, "%s : %d", v4, LODWORD(v2->i_user_data), -2i64);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "set_priority", *(_QWORD *)(v5 + 24));
      UFG::qString::~qString(&v6);
    }
    WORD2(v3[8].vfptr->get_topmost_scope) = v2->i_user_data;
  }
}

// File Line: 790
// RVA: 0x4FC3D0
void __fastcall UFG::TSScriptedDialogue::Mthd_get_cutoff_distance(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // r8
  SSObjectBaseVtbl *v3; // rax

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = v2[8].vfptr;
  if ( v3 )
    *ppResult = SSInstance::pool_new(
                  SSBrain::c_integer_class_p,
                  WORD1(v3->get_topmost_scope) - (unsigned int)LOWORD(v3->get_topmost_scope) - 1);
}

// File Line: 802
// RVA: 0x4E4890
void __fastcall UFG::TSScriptedDialogue::MthdC_create(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  ASymbol *v3; // rbx
  UFG::ScriptedConversation *v4; // rsi
  char *v5; // rax
  __int64 v6; // rax
  SSInstance *v7; // rax
  char *v8; // rax
  __int64 v9; // rax
  UFG::qString v10; // [rsp+28h] [rbp-30h]

  v2 = ppResult;
  v3 = (ASymbol *)&(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = UFG::ConversationManager::AddScriptedConversation(v3);
  if ( v4 )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v3);
      UFG::qString::qString(&v10, "%s ", v5);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "create_conversation", *(_QWORD *)(v6 + 24));
      UFG::qString::~qString(&v10);
    }
    v7 = (SSInstance *)&v4->m_script->vfptr;
    if ( v7 )
      ++v7->i_ref_count;
  }
  else
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v3);
      UFG::qString::qString(&v10, "%s ", v8);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "** FAIL *** create_conversation", *(_QWORD *)(v9 + 24));
      UFG::qString::~qString(&v10);
    }
    v7 = SSBrain::c_nil_p;
  }
  *v2 = v7;
}

// File Line: 831
// RVA: 0x4E65D0
void __fastcall UFG::TSScriptedDialogue::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax
  signed __int64 v5; // rax
  SSInstance *v6; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( v3
      && (v4 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v3)) != 0i64
      && (v5 = (signed __int64)&v4[-1].mCount) != 0 )
    {
      v6 = *(SSInstance **)(v5 + 176);
      if ( v6 )
      {
        ++v6->i_ref_count;
        *v2 = v6;
        return;
      }
    }
    else
    {
      v6 = SSBrain::c_nil_p;
    }
    *v2 = v6;
  }
}

// File Line: 850
// RVA: 0x4E8350
void __fastcall UFG::TSScriptedDialogue::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  unsigned int v3; // edx
  UFG::qBaseTreeRB *v4; // rax
  signed __int64 v5; // rax
  SSInstance *v6; // rcx

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( v3 && (v4 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, v3)) != 0i64 )
      v5 = (signed __int64)&v4[-1].mCount;
    else
      v5 = 0i64;
    v6 = *(SSInstance **)(v5 + 176);
    if ( v6 )
      ++v6->i_ref_count;
    *v2 = v6;
  }
}

// File Line: 876
// RVA: 0x4DEE20
char __fastcall UFG::TSScriptedDialogue::Coro_wait_until_finished(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rdx
  SSObjectBase *v2; // rcx
  char *v3; // rax
  __int64 v4; // rax
  char result; // al
  SSObjectBaseVtbl *v6; // rax
  char v7; // bl
  char *v8; // rax
  __int64 v9; // rax
  UFG::qString v10; // [rsp+28h] [rbp-30h]

  v1 = pScope;
  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || v1->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v1->i_update_count )
  {
    v6 = v2[8].vfptr;
    if ( v6 && LODWORD(v6->get_scope_context) != 7 )
    {
      v7 = 0;
    }
    else
    {
      v7 = 1;
      if ( UFG::ConversationManager::sm_traceScrConversations )
      {
        v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
        UFG::qString::qString(&v10, "%s ", v8);
        UFG::qPrintf("Dlg Trc: %s : %s\n", "_wait_until_finished : finished", *(_QWORD *)(v9 + 24));
        UFG::qString::~qString(&v10);
      }
    }
    result = v7;
  }
  else
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v10, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "_wait_until_finished : start", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v10);
    }
    result = 0;
  }
  return result;
}

// File Line: 903
// RVA: 0x4DC770
char __fastcall UFG::TSScriptedDialogue::Coro_play_finished(SSInvokedCoroutine *pScope)
{
  SSObjectBase *v1; // rbx
  char *v2; // rax
  __int64 v3; // rax
  char result; // al
  SSObjectBaseVtbl *v5; // rax
  char v6; // di
  char *v7; // rax
  __int64 v8; // rax
  UFG::qString v9; // [rsp+28h] [rbp-30h]

  v1 = pScope->i_scope_p.i_obj_p;
  if ( !v1 || pScope->i_scope_p.i_ptr_id != v1->i_ptr_id )
    v1 = 0i64;
  if ( pScope->i_update_count )
  {
    v5 = v1[8].vfptr;
    if ( v5 && LODWORD(v5->get_scope_context) != 7 )
    {
      v6 = 0;
    }
    else
    {
      v6 = 1;
      if ( UFG::ConversationManager::sm_traceScrConversations )
      {
        v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1[4].i_ptr_id);
        UFG::qString::qString(&v9, "%s ", v7);
        UFG::qPrintf("Dlg Trc: %s : %s\n", "_play : finished", *(_QWORD *)(v8 + 24));
        UFG::qString::~qString(&v9);
      }
    }
    result = v6;
  }
  else
  {
    if ( v1[8].vfptr )
    {
      if ( UFG::ConversationManager::sm_traceScrConversations )
      {
        v2 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1[4].i_ptr_id);
        UFG::qString::qString(&v9, "%s ", v2);
        UFG::qPrintf("Dlg Trc: %s : %s\n", "_play : start", *(_QWORD *)(v3 + 24));
        UFG::qString::~qString(&v9);
      }
      UFG::Conversation::Start((UFG::Conversation *)v1[8].vfptr);
    }
    result = 0;
  }
  return result;
}

// File Line: 935
// RVA: 0x4DC8F0
char __fastcall UFG::TSScriptedDialogue::Coro_play_stopped(SSInvokedCoroutine *pScope)
{
  SSObjectBase *v1; // rbx
  char *v2; // rax
  __int64 v3; // rax
  char result; // al
  SSObjectBaseVtbl *v5; // rax
  char v6; // di
  char *v7; // rax
  __int64 v8; // rax
  UFG::qString v9; // [rsp+28h] [rbp-30h]

  v1 = pScope->i_scope_p.i_obj_p;
  if ( !v1 || pScope->i_scope_p.i_ptr_id != v1->i_ptr_id )
    v1 = 0i64;
  if ( pScope->i_update_count )
  {
    v5 = v1[8].vfptr;
    if ( v5 && LODWORD(v5->get_scope_context) != 6 )
    {
      v6 = 0;
    }
    else
    {
      v6 = 1;
      if ( UFG::ConversationManager::sm_traceScrConversations )
      {
        v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1[4].i_ptr_id);
        UFG::qString::qString(&v9, "%s ", v7);
        UFG::qPrintf("Dlg Trc: %s : %s\n", "_play : stopped", *(_QWORD *)(v8 + 24));
        UFG::qString::~qString(&v9);
      }
    }
    result = v6;
  }
  else
  {
    if ( v1[8].vfptr )
    {
      if ( UFG::ConversationManager::sm_traceScrConversations )
      {
        v2 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1[4].i_ptr_id);
        UFG::qString::qString(&v9, "%s ", v2);
        UFG::qPrintf("Dlg Trc: %s : %s\n", "_play : start", *(_QWORD *)(v3 + 24));
        UFG::qString::~qString(&v9);
      }
      UFG::Conversation::Start((UFG::Conversation *)v1[8].vfptr);
    }
    result = 0;
  }
  return result;
}

// File Line: 967
// RVA: 0x4DCA00
char __fastcall UFG::TSScriptedDialogue::Coro_play_stopped_or_finished(SSInvokedCoroutine *pScope)
{
  SSObjectBase *v1; // rbx
  char *v2; // rax
  __int64 v3; // rax
  char result; // al
  SSObjectBaseVtbl *v5; // rax
  char v6; // di
  char *v7; // rax
  __int64 v8; // rax
  UFG::qString v9; // [rsp+28h] [rbp-30h]

  v1 = pScope->i_scope_p.i_obj_p;
  if ( !v1 || pScope->i_scope_p.i_ptr_id != v1->i_ptr_id )
    v1 = 0i64;
  if ( pScope->i_update_count )
  {
    v5 = v1[8].vfptr;
    if ( v5 && (unsigned int)(LODWORD(v5->get_scope_context) - 6) > 1 )
    {
      v6 = 0;
    }
    else
    {
      v6 = 1;
      if ( UFG::ConversationManager::sm_traceScrConversations )
      {
        v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1[4].i_ptr_id);
        UFG::qString::qString(&v9, "%s ", v7);
        UFG::qPrintf("Dlg Trc: %s : %s\n", "_play : stopped or finished", *(_QWORD *)(v8 + 24));
        UFG::qString::~qString(&v9);
      }
    }
    result = v6;
  }
  else
  {
    if ( v1[8].vfptr )
    {
      if ( UFG::ConversationManager::sm_traceScrConversations )
      {
        v2 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1[4].i_ptr_id);
        UFG::qString::qString(&v9, "%s ", v2);
        UFG::qPrintf("Dlg Trc: %s : %s\n", "_play : start", *(_QWORD *)(v3 + 24));
        UFG::qString::~qString(&v9);
      }
      UFG::Conversation::Start((UFG::Conversation *)v1[8].vfptr);
    }
    result = 0;
  }
  return result;
}

// File Line: 1000
// RVA: 0x4DE000
char __fastcall UFG::TSScriptedDialogue::Coro_stop(SSInvokedCoroutine *pScope)
{
  SSObjectBase *v1; // rbx
  UFG::Conversation *v2; // rcx
  char *v3; // rax
  __int64 v4; // rax
  char result; // al
  SSObjectBaseVtbl *v6; // rax
  char v7; // di
  char *v8; // rax
  __int64 v9; // rax
  UFG::qString v10; // [rsp+28h] [rbp-30h]

  v1 = pScope->i_scope_p.i_obj_p;
  if ( !v1 || pScope->i_scope_p.i_ptr_id != v1->i_ptr_id )
    v1 = 0i64;
  if ( pScope->i_update_count )
  {
    v6 = v1[8].vfptr;
    if ( v6 && LODWORD(v6->get_scope_context) != 6 )
    {
      v7 = 0;
    }
    else
    {
      v7 = 1;
      if ( UFG::ConversationManager::sm_traceScrConversations )
      {
        v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1[4].i_ptr_id);
        UFG::qString::qString(&v10, "%s ", v8);
        UFG::qPrintf("Dlg Trc: %s : %s\n", "_stop : finished", *(_QWORD *)(v9 + 24));
        UFG::qString::~qString(&v10);
      }
    }
    result = v7;
  }
  else
  {
    v2 = (UFG::Conversation *)v1[8].vfptr;
    if ( v2 )
      UFG::Conversation::Stop(v2, 0);
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1[4].i_ptr_id);
      UFG::qString::qString(&v10, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "_stop : start", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v10);
    }
    result = 0;
  }
  return result;
}

// File Line: 1069
// RVA: 0x4DF220
char __fastcall UFG::TSScriptedDialogue::Coro_wait_until_stopped(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rdx
  SSObjectBase *v2; // rcx
  char *v3; // rax
  __int64 v4; // rax
  char result; // al
  SSObjectBaseVtbl *v6; // rax
  char v7; // bl
  char *v8; // rax
  __int64 v9; // rax
  UFG::qString v10; // [rsp+28h] [rbp-30h]

  v1 = pScope;
  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || v1->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  if ( v1->i_update_count )
  {
    v6 = v2[8].vfptr;
    if ( v6 && LODWORD(v6->get_scope_context) != 6 )
    {
      v7 = 0;
    }
    else
    {
      v7 = 1;
      if ( UFG::ConversationManager::sm_traceScrConversations )
      {
        v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
        UFG::qString::qString(&v10, "%s ", v8);
        UFG::qPrintf("Dlg Trc: %s : %s\n", "_wait_until_stopped : finished", *(_QWORD *)(v9 + 24));
        UFG::qString::~qString(&v10);
      }
    }
    result = v7;
  }
  else
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
      UFG::qString::qString(&v10, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "_wait_until_stopped : start", *(_QWORD *)(v4 + 24));
      UFG::qString::~qString(&v10);
    }
    result = 0;
  }
  return result;
}

// File Line: 1098
// RVA: 0x5125A0
void __fastcall UFG::TSScriptedDialogue::on_no_references(UFG::TSScriptedDialogueElement *this)
{
  UFG::TSScriptedDialogueElement *v1; // rbx

  v1 = this;
  SSInstance::call_destructor((SSInstance *)&this->vfptr);
  if ( v1 )
    v1->vfptr->__vecDelDtor((SSObjectBase *)&v1->vfptr, 1u);
}

// File Line: 1157
// RVA: 0x4FA1C0
void __fastcall UFG::TSScriptedDialogue::Mthd_force_finish_all_scripted_conversations(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ConversationManager::StopAllScriptedConversations();
}

// File Line: 1170
// RVA: 0x4EB9D0
void __fastcall UFG::TSScriptedDialogue::MthdC_query_context(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  SSData **v3; // rdx
  unsigned __int64 v4; // rax
  int v5; // ecx
  _QWORD *v6; // rsi
  int v7; // eax
  __int64 v8; // rbp
  int v9; // ebx
  int v10; // edi
  UFG::allocator::free_link *v11; // rax
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *v12; // rcx
  UFG::Query query; // [rsp+28h] [rbp-30h]

  v2 = pScope;
  UFG::Query::Query(&query);
  v3 = v2->i_data.i_array_p;
  query.m_concept.mUID = (*v3)->i_data_p->i_user_data;
  v4 = v3[1]->i_data_p->i_user_data;
  v5 = *(_DWORD *)v4;
  v6 = *(_QWORD **)(v4 + 8);
  v7 = *(_DWORD *)v4 - 1;
  if ( v5 != 1 )
  {
    v8 = ((unsigned int)(v7 - 1) >> 1) + 1;
    do
    {
      v9 = *(_DWORD *)(*v6 + 32i64);
      v10 = *(_DWORD *)(v6[1] + 32i64);
      v11 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
      if ( v11 )
      {
        v11->mNext = v11;
        v11[1].mNext = v11;
        v11[2].mNext = (UFG::allocator::free_link *)-1i64;
      }
      LODWORD(v11[2].mNext) = v9;
      HIDWORD(v11[2].mNext) = v10;
      v12 = query.m_facts.mNode.mPrev;
      query.m_facts.mNode.mPrev->mNext = (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)v11;
      v11->mNext = (UFG::allocator::free_link *)v12;
      v11[1].mNext = (UFG::allocator::free_link *)&query.m_facts;
      query.m_facts.mNode.mPrev = (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)v11;
      v6 += 2;
      --v8;
    }
    while ( v8 );
  }
  UFG::ContextualDialogueManager::ExecuteQuery(&query);
  UFG::Query::~Query(&query);
}

// File Line: 1210
// RVA: 0x4EBAC0
void __fastcall UFG::TSScriptedDialogue::MthdC_query_context_character(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  SSData **v3; // r8
  SSInstance *v4; // rcx
  unsigned __int64 v5; // rax
  _QWORD *v6; // rsi
  int v7; // eax
  __int64 v8; // rbp
  int v9; // ebx
  int v10; // edi
  UFG::allocator::free_link *v11; // rax
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *v12; // rcx
  UFG::Query query; // [rsp+28h] [rbp-30h]

  v2 = pScope;
  UFG::Query::Query(&query);
  v3 = v2->i_data.i_array_p;
  v4 = v3[1]->i_data_p;
  query.m_concept.mUID = (*v3)->i_data_p->i_user_data;
  query.m_character.mUID = v4->i_user_data;
  v5 = v3[1]->i_data_p->i_user_data;
  LODWORD(v4) = *(_DWORD *)v5;
  v6 = *(_QWORD **)(v5 + 8);
  v7 = *(_DWORD *)v5 - 1;
  if ( (_DWORD)v4 != 1 )
  {
    v8 = ((unsigned int)(v7 - 1) >> 1) + 1;
    do
    {
      v9 = *(_DWORD *)(*v6 + 32i64);
      v10 = *(_DWORD *)(v6[1] + 32i64);
      v11 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
      if ( v11 )
      {
        v11->mNext = v11;
        v11[1].mNext = v11;
        v11[2].mNext = (UFG::allocator::free_link *)-1i64;
      }
      LODWORD(v11[2].mNext) = v9;
      HIDWORD(v11[2].mNext) = v10;
      v12 = query.m_facts.mNode.mPrev;
      query.m_facts.mNode.mPrev->mNext = (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)v11;
      v11->mNext = (UFG::allocator::free_link *)v12;
      v11[1].mNext = (UFG::allocator::free_link *)&query.m_facts;
      query.m_facts.mNode.mPrev = (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)v11;
      v6 += 2;
      --v8;
    }
    while ( v8 );
  }
  UFG::ContextualDialogueManager::ExecuteQuery(&query);
  UFG::Query::~Query(&query);
}

// File Line: 1257
// RVA: 0x4CBA30
void __fastcall UFG::TSScriptedDialogueElement::TSScriptedDialogueElement(UFG::TSScriptedDialogueElement *this, UFG::ScriptedConversationElement *conv, ASymbol *name, SSActorClass *pClass)
{
  UFG::ScriptedConversationElement *v4; // rbx
  UFG::TSScriptedDialogueElement *v5; // rdi

  v4 = conv;
  v5 = this;
  SSActor::SSActor((SSActor *)&this->vfptr, name, pClass, 1);
  v5->vfptr = (SSObjectBaseVtbl *)&UFG::TSScriptedDialogueElement::`vftable';
  v5->m_element = v4;
}

// File Line: 1294
// RVA: 0x4D6030
void UFG::TSScriptedDialogueElement::BindAtomics(void)
{
  UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass = (SSActorClass *)SSBrain::get_class("ScriptedDialogueElement");
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "set_speaker",
    UFG::TSScriptedDialogueElement::Mthd_set_speaker,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "set_target",
    UFG::TSScriptedDialogueElement::Mthd_set_target,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "set_args",
    UFG::TSScriptedDialogueElement::Mthd_set_args,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "set_pre_delay",
    UFG::TSScriptedDialogueElement::Mthd_set_pre_delay,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "add_interruption_point",
    UFG::TSScriptedDialogueElement::Mthd_add_interruption_point,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "remove_interruption_point",
    UFG::TSScriptedDialogueElement::Mthd_remove_interruption_point,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "set_interjection_point",
    UFG::TSScriptedDialogueElement::Mthd_set_interjection_point,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "stop_after_play",
    UFG::TSScriptedDialogueElement::Mthd_stop_after_play,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "set_resume_checkpoint",
    UFG::TSScriptedDialogueElement::Mthd_set_resume_checkpoint,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "set_playback_event",
    UFG::TSScriptedDialogueElement::Mthd_set_playback_event,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "kill_on_interruption_point",
    UFG::TSScriptedDialogueElement::Mthd_kill_on_interrupt,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "set_is_highest_priority",
    UFG::TSScriptedDialogueElement::Mthd_set_is_highest_priority,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "play_from_position",
    UFG::TSScriptedDialogueElement::Mthd_play_from_position,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "speaker_emotion",
    UFG::TSScriptedDialogueElement::Mthd_speaker_emotion,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "listener_emotion",
    UFG::TSScriptedDialogueElement::Mthd_listener_emotion,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "speaker_action_request",
    UFG::TSScriptedDialogueElement::Mthd_speaker_action_request,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "listener_action_request",
    UFG::TSScriptedDialogueElement::Mthd_listener_action_request,
    0);
  SSClass::register_coroutine_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "_wait_on_interruption_point",
    UFG::TSScriptedDialogueElement::Coro_wait_on_interruption_point,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "create",
    UFG::TSScriptedDialogueElement::MthdC_create,
    1,
    0);
  SSClass::register_method_func(
    (SSClass *)&UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass->vfptr,
    "get_named",
    UFG::TSAudio::MthdC_get_named,
    1,
    0);
}

// File Line: 1332
// RVA: 0x4E4990
void __fastcall UFG::TSScriptedDialogueElement::MthdC_create(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rdi
  SSInstance *v3; // rsi
  UFG::allocator::free_link *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  char *v7; // rax
  __int64 v8; // rax
  SSInstance *v9; // rax
  UFG::qString v10; // [rsp+38h] [rbp-30h]

  v2 = ppResult;
  v3 = (*pScope->i_data.i_array_p)->i_data_p;
  v4 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0xC0ui64, "create.ScriptedConversationElement", 0i64, 1u);
  if ( v4 )
  {
    UFG::ScriptedConversationElement::ScriptedConversationElement(
      (UFG::ScriptedConversationElement *)v4,
      (ASymbol *)&v3->i_user_data);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3->i_user_data);
    UFG::qString::qString(&v10, "%s ", v7);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "create element", *(_QWORD *)(v8 + 24));
    UFG::qString::~qString(&v10);
  }
  if ( v6 )
  {
    v9 = *(SSInstance **)(v6 + 160);
    if ( v9 )
      ++v9->i_ref_count;
  }
  else
  {
    v9 = SSBrain::c_nil_p;
  }
  *v2 = v9;
}

// File Line: 1372
// RVA: 0x50A520
void __fastcall UFG::TSScriptedDialogueElement::Mthd_set_speaker(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  SSObjectBase *v3; // rsi
  SSActor *v4; // rbx
  SSClass *v5; // r14
  SSInstance *v6; // rbp
  SSClass *v7; // rcx
  UFG::SimObject *v8; // rdx
  char *v9; // rbx
  char *v10; // rax
  __int64 v11; // rax
  SSInstance *v12; // rax
  SSInstance *v13; // rbx
  char *v14; // rax
  __int64 v15; // rax
  UFG::qString v16; // [rsp+28h] [rbp-30h]

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !v4 )
    goto LABEL_9;
  v5 = v4->i_class_p;
  if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSInstance **))v5->vfptr->is_actor_class)(v4->i_class_p, ppResult) )
  {
    if ( v5 == SSBrain::c_symbol_class_p && LODWORD(v4->i_user_data) != -1 )
    {
      v4 = SSActor::find((ASymbol *)&v4->i_user_data);
      goto LABEL_10;
    }
LABEL_9:
    v4 = 0i64;
  }
LABEL_10:
  v6 = (*v2->i_data.i_array_p)->i_data_p;
  if ( v6 )
  {
    v7 = v6->i_class_p;
    if ( v7 )
    {
      if ( ((unsigned __int8 (__cdecl *)(SSClass *))v7->vfptr->is_actor_class)(v7) || LODWORD(v6->i_user_data) != -1 )
      {
        if ( v4 && (v8 = *(UFG::SimObject **)&v4[1].i_icoroutines_to_update.i_count) != 0i64 )
        {
          UFG::ConversationElement::SetSpeaker((UFG::ConversationElement *)v3[8].vfptr, v8);
          if ( !UFG::ConversationManager::sm_traceScrConversations )
            return;
          v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->i_name);
          v10 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3[4].i_ptr_id);
          UFG::qString::qString(&v16, "%s : %s ", v10, v9, -2i64);
          UFG::qPrintf("Dlg Trc: %s : %s\n", "set_speaker", *(_QWORD *)(v11 + 24));
        }
        else
        {
          v3[8].vfptr[2].get_scope_context = (SSInvokedContextBase *(__fastcall *)(SSObjectBase *))(*v2->i_data.i_array_p)->i_data_p;
          v12 = (*v2->i_data.i_array_p)->i_data_p;
          ++v12->i_ref_count;
          if ( !UFG::ConversationManager::sm_traceScrConversations )
            return;
          v13 = (*v2->i_data.i_array_p)->i_data_p;
          v14 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3[4].i_ptr_id);
          UFG::qString::qString(&v16, "%s : %s ", v14, &v13->i_user_data, -2i64);
          UFG::qPrintf("Dlg Trc: %s : %s\n", "set_speaker", *(_QWORD *)(v15 + 24));
        }
        UFG::qString::~qString(&v16);
      }
    }
  }
}

// File Line: 1399
// RVA: 0x50AA80
void __fastcall UFG::TSScriptedDialogueElement::Mthd_set_target(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rsi
  SSObjectBase *v3; // rbp
  SSActor *v4; // rdi
  SSClass *v5; // rbx
  char *v6; // rbx
  char *v7; // rax
  __int64 v8; // rax
  SSInstance *v9; // rbx
  SSClass *v10; // rcx
  UFG::SimObject *v11; // rdx
  SSInstance *v12; // rax
  UFG::qString v13; // [rsp+28h] [rbp-30h]

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !v4 )
    goto LABEL_12;
  v5 = v4->i_class_p;
  if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSInstance **))v5->vfptr->is_actor_class)(v4->i_class_p, ppResult) )
  {
    if ( v5 == SSBrain::c_symbol_class_p && LODWORD(v4->i_user_data) != -1 )
    {
      v4 = SSActor::find((ASymbol *)&v4->i_user_data);
      goto LABEL_9;
    }
LABEL_12:
    v4 = 0i64;
    goto LABEL_13;
  }
LABEL_9:
  if ( v4 && UFG::ConversationManager::sm_traceScrConversations )
  {
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->i_name);
    v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3[4].i_ptr_id);
    UFG::qString::qString(&v13, "%s : %s ", v7, v6, -2i64);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "set_target", *(_QWORD *)(v8 + 24));
    UFG::qString::~qString(&v13);
  }
LABEL_13:
  v9 = (*v2->i_data.i_array_p)->i_data_p;
  if ( v9 )
  {
    v10 = v9->i_class_p;
    if ( v10 )
    {
      if ( ((unsigned __int8 (__cdecl *)(SSClass *))v10->vfptr->is_actor_class)(v10) || LODWORD(v9->i_user_data) != -1 )
      {
        if ( v4 && (v11 = *(UFG::SimObject **)&v4[1].i_icoroutines_to_update.i_count) != 0i64 )
        {
          UFG::ConversationElement::SetTarget((UFG::ConversationElement *)v3[8].vfptr, v11);
        }
        else
        {
          v3[8].vfptr[2].get_topmost_scope = (SSInstance *(__fastcall *)(SSObjectBase *))(*v2->i_data.i_array_p)->i_data_p;
          v12 = (*v2->i_data.i_array_p)->i_data_p;
          ++v12->i_ref_count;
        }
      }
    }
  }
}

// File Line: 1427
// RVA: 0x507010
void __fastcall UFG::TSScriptedDialogueElement::Mthd_set_args(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbp
  unsigned __int64 v3; // rdx
  unsigned int v4; // esi
  __int64 v5; // rdi
  unsigned int v6; // ebx
  SSObjectBase *v7; // rcx
  UFG::qString v8; // [rsp+38h] [rbp-30h]

  v2 = pScope;
  v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = *(_DWORD *)v3;
  v5 = *(_QWORD *)(v3 + 8);
  UFG::qString::qString(&v8, &customWorldMapCaption);
  v6 = 0;
  if ( v4 )
  {
    do
    {
      UFG::qString::operator+=(&v8, **(const char ***)(*(_QWORD *)v5 + 32i64));
      if ( v6 < v4 - 1 )
        UFG::qString::operator+=(&v8, ".");
      ++v6;
      v5 += 8i64;
    }
    while ( v6 < v4 );
  }
  v7 = v2->i_scope_p.i_obj_p;
  if ( !v7 || v2->i_scope_p.i_ptr_id != v7->i_ptr_id )
    v7 = 0i64;
  UFG::qString::Set((UFG::qString *)&v7[8].vfptr->get_data_by_name, v8.mData, v8.mLength, 0i64, 0);
  UFG::qString::~qString(&v8);
}

// File Line: 1465
// RVA: 0x509E90
void __fastcall UFG::TSScriptedDialogueElement::Mthd_set_pre_delay(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx
  SSInstance *v3; // rbx
  char *v4; // rax
  __int64 v5; // rax
  UFG::qString v6; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (*pScope->i_data.i_array_p)->i_data_p;
  LODWORD(v2[8].vfptr[1].get_obj_type) = v3->i_user_data;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
    UFG::qString::qString(&v6, "%s : %d ", v4, *(float *)&v3->i_user_data, -2i64);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "set_pre_delay", *(_QWORD *)(v5 + 24));
    UFG::qString::~qString(&v6);
  }
}

// File Line: 1479
// RVA: 0x4F4280
void __fastcall UFG::TSScriptedDialogueElement::Mthd_add_interruption_point(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  SSData **v3; // rcx
  SSInstance *v4; // rdi
  SSInstance *v5; // rsi
  char *v6; // rax
  __int64 v7; // rax
  UFG::qString v8; // [rsp+38h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = pScope->i_data.i_array_p;
  v4 = (*v3)->i_data_p;
  v5 = v3[1]->i_data_p;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
    UFG::qString::qString(&v8, "%s : %u %d ", v6, LODWORD(v4->i_user_data), *(float *)&v5->i_user_data);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "add_interruption_point", *(_QWORD *)(v7 + 24));
    UFG::qString::~qString(&v8);
  }
  UFG::ConversationElement::AddInterruptPoint(
    (UFG::ConversationElement *)v2[8].vfptr,
    v4->i_user_data,
    *(float *)&v5->i_user_data);
}

// File Line: 1493
// RVA: 0x50B870
void __fastcall UFG::TSScriptedDialogueElement::Mthd_speaker_emotion(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdi
  SSData **v3; // rcx
  SSInstance *v4; // r15
  SSInstance *v5; // rsi
  SSInstance *v6; // r14
  __int64 v7; // rbx
  char *v8; // rax
  __int64 v9; // rax
  UFG::qString v10; // [rsp+38h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = pScope->i_data.i_array_p;
  v4 = (*v3)->i_data_p;
  v5 = v3[1]->i_data_p;
  v6 = v3[2]->i_data_p;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v7 = *(_QWORD *)v6->i_user_data;
    v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
    UFG::qString::qString(&v10, "%s : %f %s", v8, *(float *)&v5->i_user_data, v7);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "add_speaker_emotion", *(_QWORD *)(v9 + 24));
    UFG::qString::~qString(&v10);
  }
  UFG::ConversationElement::AddEmotionRequest(
    (UFG::ConversationElement *)v2[8].vfptr,
    v4->i_user_data,
    *(float *)&v5->i_user_data,
    *(const char **)v6->i_user_data,
    0);
}

// File Line: 1510
// RVA: 0x504950
void __fastcall UFG::TSScriptedDialogueElement::Mthd_listener_emotion(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdi
  SSData **v3; // rcx
  SSInstance *v4; // r15
  SSInstance *v5; // rsi
  SSInstance *v6; // r14
  __int64 v7; // rbx
  char *v8; // rax
  __int64 v9; // rax
  UFG::qString v10; // [rsp+38h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = pScope->i_data.i_array_p;
  v4 = (*v3)->i_data_p;
  v5 = v3[1]->i_data_p;
  v6 = v3[2]->i_data_p;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v7 = *(_QWORD *)v6->i_user_data;
    v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
    UFG::qString::qString(&v10, "%s : %f %s", v8, *(float *)&v5->i_user_data, v7);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "add_listener_emotion", *(_QWORD *)(v9 + 24));
    UFG::qString::~qString(&v10);
  }
  UFG::ConversationElement::AddEmotionRequest(
    (UFG::ConversationElement *)v2[8].vfptr,
    v4->i_user_data,
    *(float *)&v5->i_user_data,
    *(const char **)v6->i_user_data,
    1);
}

// File Line: 1527
// RVA: 0x50B6D0
void __fastcall UFG::TSScriptedDialogueElement::Mthd_speaker_action_request(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  SSObjectBase *v3; // rsi
  SSData **v4; // rcx
  SSInstance *v5; // r15
  SSInstance *v6; // rbp
  SSInstance *v7; // r14
  __int64 v8; // rbx
  char *v9; // rax
  __int64 v10; // rax
  UFG::ConversationElementActionRequest *v11; // rbp
  SSActor *v12; // rbx
  SSClass *v13; // rsi
  __int64 v14; // rsi
  __int64 v15; // rcx
  UFG::SimObject *v16; // rax
  __int64 v17; // rax
  UFG::qString v18; // [rsp+38h] [rbp-40h]

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = pScope->i_data.i_array_p;
  v5 = (*v4)->i_data_p;
  v6 = v4[1]->i_data_p;
  v7 = v4[2]->i_data_p;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v8 = *(_QWORD *)v7->i_user_data;
    v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3[4].i_ptr_id);
    UFG::qString::qString(&v18, "%s : %f '%s'", v9, *(float *)&v6->i_user_data, v8);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "add_action_request", *(_QWORD *)(v10 + 24));
    UFG::qString::~qString(&v18);
  }
  v11 = UFG::ConversationElement::AddActionRequest(
          (UFG::ConversationElement *)v3[8].vfptr,
          v5->i_user_data,
          *(float *)&v6->i_user_data,
          *(const char **)v7->i_user_data,
          0);
  v12 = *(SSActor **)(*((_QWORD *)v2->i_data.i_array_p + 3) + 8i64);
  if ( !v12 )
    goto LABEL_11;
  v13 = v12->i_class_p;
  if ( !v13->vfptr->is_actor_class((SSClassDescBase *)v12->i_class_p) )
  {
    if ( v13 == SSBrain::c_symbol_class_p && LODWORD(v12->i_user_data) != -1 )
    {
      v12 = SSActor::find((ASymbol *)&v12->i_user_data);
      goto LABEL_12;
    }
LABEL_11:
    v12 = 0i64;
  }
LABEL_12:
  v14 = *(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 3) + 8i64);
  if ( v14 )
  {
    v15 = *(_QWORD *)(v14 + 24);
    if ( v15 )
    {
      if ( (*(unsigned __int8 (**)(void))(*(_QWORD *)v15 + 64i64))() || *(_DWORD *)(v14 + 32) != -1 )
      {
        if ( v12 && (v16 = *(UFG::SimObject **)&v12[1].i_icoroutines_to_update.i_count) != 0i64 )
        {
          v11->m_target = v16;
        }
        else
        {
          v11->m_targetInst = *(SSInstance **)(*((_QWORD *)v2->i_data.i_array_p + 3) + 8i64);
          v17 = *(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 3) + 8i64);
          ++*(_DWORD *)(v17 + 16);
        }
      }
    }
  }
}

// File Line: 1560
// RVA: 0x5047B0
void __fastcall UFG::TSScriptedDialogueElement::Mthd_listener_action_request(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdi
  SSObjectBase *v3; // rsi
  SSData **v4; // rcx
  SSInstance *v5; // r15
  SSInstance *v6; // rbp
  SSInstance *v7; // r14
  __int64 v8; // rbx
  char *v9; // rax
  __int64 v10; // rax
  UFG::ConversationElementActionRequest *v11; // rbp
  SSActor *v12; // rbx
  SSClass *v13; // rsi
  __int64 v14; // rsi
  __int64 v15; // rcx
  UFG::SimObject *v16; // rax
  __int64 v17; // rax
  UFG::qString v18; // [rsp+38h] [rbp-40h]

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || pScope->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  v4 = pScope->i_data.i_array_p;
  v5 = (*v4)->i_data_p;
  v6 = v4[1]->i_data_p;
  v7 = v4[2]->i_data_p;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v8 = *(_QWORD *)v7->i_user_data;
    v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v3[4].i_ptr_id);
    UFG::qString::qString(&v18, "%s : %f '%s' ", v9, *(float *)&v6->i_user_data, v8);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "add_action_request", *(_QWORD *)(v10 + 24));
    UFG::qString::~qString(&v18);
  }
  v11 = UFG::ConversationElement::AddActionRequest(
          (UFG::ConversationElement *)v3[8].vfptr,
          v5->i_user_data,
          *(float *)&v6->i_user_data,
          *(const char **)v7->i_user_data,
          1);
  v12 = *(SSActor **)(*((_QWORD *)v2->i_data.i_array_p + 3) + 8i64);
  if ( !v12 )
    goto LABEL_11;
  v13 = v12->i_class_p;
  if ( !v13->vfptr->is_actor_class((SSClassDescBase *)v12->i_class_p) )
  {
    if ( v13 == SSBrain::c_symbol_class_p && LODWORD(v12->i_user_data) != -1 )
    {
      v12 = SSActor::find((ASymbol *)&v12->i_user_data);
      goto LABEL_12;
    }
LABEL_11:
    v12 = 0i64;
  }
LABEL_12:
  v14 = *(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 3) + 8i64);
  if ( v14 )
  {
    v15 = *(_QWORD *)(v14 + 24);
    if ( v15 )
    {
      if ( (*(unsigned __int8 (**)(void))(*(_QWORD *)v15 + 64i64))() || *(_DWORD *)(v14 + 32) != -1 )
      {
        if ( v12 && (v16 = *(UFG::SimObject **)&v12[1].i_icoroutines_to_update.i_count) != 0i64 )
        {
          v11->m_target = v16;
        }
        else
        {
          v11->m_targetInst = *(SSInstance **)(*((_QWORD *)v2->i_data.i_array_p + 3) + 8i64);
          v17 = *(_QWORD *)(*((_QWORD *)v2->i_data.i_array_p + 3) + 8i64);
          ++*(_DWORD *)(v17 + 16);
        }
      }
    }
  }
}

// File Line: 1593
// RVA: 0x506650
void __fastcall UFG::TSScriptedDialogueElement::Mthd_remove_interruption_point(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rbx
  SSInstance *v3; // rdi
  char *v4; // rax
  __int64 v5; // rax
  UFG::qString v6; // [rsp+28h] [rbp-30h]

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  v3 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v2[4].i_ptr_id);
    UFG::qString::qString(&v6, "%s : %u ", v4, LODWORD(v3->i_user_data), -2i64);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "remove_interruption_point", *(_QWORD *)(v5 + 24));
    UFG::qString::~qString(&v6);
  }
  UFG::ConversationElement::RemoveInterruptPoint((UFG::ConversationElement *)v2[8].vfptr, v3->i_user_data);
}

// File Line: 1606
// RVA: 0x508990
void __fastcall UFG::TSScriptedDialogueElement::Mthd_set_interjection_point(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  HIDWORD(v2[8].vfptr[1].get_obj_type) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 1617
// RVA: 0x50C2D0
void __fastcall UFG::TSScriptedDialogueElement::Mthd_stop_after_play(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  BYTE4(v2[8].vfptr[2].as_instance) ^= (BYTE4(v2[8].vfptr[2].as_instance) ^ ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 1;
}

// File Line: 1628
// RVA: 0x50A320
void __fastcall UFG::TSScriptedDialogueElement::Mthd_set_resume_checkpoint(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  BYTE4(v2[8].vfptr[2].as_instance) ^= (BYTE4(v2[8].vfptr[2].as_instance) ^ 16
                                                                          * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 0x10;
}

// File Line: 1639
// RVA: 0x509370
void __fastcall UFG::TSScriptedDialogueElement::Mthd_set_playback_event(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  UFG::ScriptedConversationElement::SetPlaybackEvent(
    (UFG::ScriptedConversationElement *)v3[8].vfptr,
    *(const char **)(*v2->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1649
// RVA: 0x503F40
void __fastcall UFG::TSScriptedDialogueElement::Mthd_kill_on_interrupt(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  BYTE4(v2[8].vfptr[2].as_instance) ^= (BYTE4(v2[8].vfptr[2].as_instance) ^ 2
                                                                          * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 2;
}

// File Line: 1660
// RVA: 0x508A60
void __fastcall UFG::TSScriptedDialogueElement::Mthd_set_is_highest_priority(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *v2; // rdx

  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || pScope->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  BYTE4(v2[8].vfptr[2].as_instance) ^= (BYTE4(v2[8].vfptr[2].as_instance) ^ 8
                                                                          * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 8;
}

// File Line: 1670
// RVA: 0x505E10
void __fastcall UFG::TSScriptedDialogueElement::Mthd_play_from_position(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rdx
  SSObjectBase *v3; // rcx

  v2 = pScope;
  v3 = pScope->i_scope_p.i_obj_p;
  if ( !v3 || v2->i_scope_p.i_ptr_id != v3->i_ptr_id )
    v3 = 0i64;
  UFG::ScriptedConversationElement::CreateNonCharacterContainer(
    (UFG::ScriptedConversationElement *)v3[8].vfptr,
    (UFG::qVector3 *)(*v2->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1680
// RVA: 0x4DEB50
bool __fastcall UFG::TSScriptedDialogueElement::Coro_wait_on_interruption_point(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rdx
  SSObjectBase *v2; // rcx

  v1 = pScope;
  v2 = pScope->i_scope_p.i_obj_p;
  if ( !v2 || v1->i_scope_p.i_ptr_id != v2->i_ptr_id )
    v2 = 0i64;
  return UFG::ConversationElement::InterruptPointReached(
           (UFG::ConversationElement *)v2[8].vfptr,
           (*v1->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1691
// RVA: 0x4E16F0
UFG::qBaseNodeRB *__fastcall UFG::TSScriptedDialogueElement::GetSimObjectFromSymbol(SSInstance *instance)
{
  SSInstance *v1; // rbx
  UFG::qBaseNodeRB *result; // rax
  SSActor *v3; // rax

  v1 = instance;
  if ( ((unsigned __int8 (*)(void))instance->vfptr->is_actor)() )
    return *(UFG::qBaseNodeRB **)&v1[4].i_ref_count;
  if ( v1->i_class_p != SSBrain::c_symbol_class_p )
    return 0i64;
  v3 = SSActor::find((ASymbol *)&v1->i_user_data);
  if ( v3 )
    result = *(UFG::qBaseNodeRB **)&v3[1].i_icoroutines_to_update.i_count;
  else
    result = UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)&v1->i_user_data);
  return result;
}

