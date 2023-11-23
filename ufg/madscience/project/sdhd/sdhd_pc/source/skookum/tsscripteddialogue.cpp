// File Line: 68
// RVA: 0x4CB9D0
void __fastcall UFG::TSScriptedDialogue::TSScriptedDialogue(
        UFG::TSScriptedDialogue *this,
        UFG::ScriptedConversation *conv,
        ASymbol *name,
        SSActorClass *pClass)
{
  SSActor::SSActor(this, name, pClass, 1);
  this->vfptr = (SSObjectBaseVtbl *)&UFG::TSScriptedDialogue::`vftable;
  this->m_conversation = conv;
}

// File Line: 92
// RVA: 0x4D59F0
void UFG::TSScriptedDialogue::BindAtomics(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]

  UFG::TSScriptedDialogue::mspScriptedDialogueClass = (SSActorClass *)SSBrain::get_class("ScriptedDialogue");
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "add_element",
    UFG::TSScriptedDialogue::Mthd_add_element,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "get_element",
    UFG::TSScriptedDialogue::Mthd_get_element,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "add_element_by_reference",
    UFG::TSScriptedDialogue::Mthd_add_element_by_reference,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "add_interrupt_elements",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "add_resume_elements",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "interrupt",
    (void (__fastcall *)(SSInvokedMethod *, SSInstance **))_,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "is_finished",
    UFG::TSScriptedDialogue::Mthd_is_finished,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "is_interrupted",
    UFG::TSScriptedDialogue::Mthd_is_interrupted,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "is_stopped",
    UFG::TSScriptedDialogue::Mthd_is_stopped,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "is_playing",
    UFG::TSScriptedDialogue::Mthd_is_playing,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "is_inactive",
    UFG::TSScriptedDialogue::Mthd_is_inactive,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "destroy",
    UFG::TSScriptedDialogue::Mthd_destroy,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "stop",
    UFG::TSScriptedDialogue::Mthd_stop,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "stop_after_line",
    UFG::TSScriptedDialogue::Mthd_stop_after_line,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "play",
    UFG::TSScriptedDialogue::Mthd_play,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "next_line",
    UFG::TSScriptedDialogue::Mthd_next_line,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "first_line_of_next_group",
    UFG::TSScriptedDialogue::Mthd_move_to_next_group,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "prev_line",
    UFG::TSScriptedDialogue::Mthd_prev_line,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "reset",
    UFG::TSScriptedDialogue::Mthd_reset,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "restart",
    UFG::TSScriptedDialogue::Mthd_restart,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "auto_delete",
    UFG::TSScriptedDialogue::Mthd_auto_delete,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "is_tag_interruptable",
    UFG::TSScriptedDialogue::Mthd_set_tag_interruptable,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "set_topic",
    UFG::TSScriptedDialogue::Mthd_set_topic,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "disable_distance_cutoff",
    UFG::TSScriptedDialogue::Mthd_disable_distance_cutoff,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "enable_distance_cutoff",
    UFG::TSScriptedDialogue::Mthd_enable_distance_cutoff,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "disable_interrupts",
    UFG::TSScriptedDialogue::Mthd_disable_interrupts,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "enable_interrupts",
    UFG::TSScriptedDialogue::Mthd_enable_interrupts,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "disable_car_exit_interrupts",
    UFG::TSScriptedDialogue::Mthd_disable_car_exit_interrupts,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "enable_car_exit_interrupts",
    UFG::TSScriptedDialogue::Mthd_enable_car_exit_interrupts,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "disable_subtitles",
    UFG::TSScriptedDialogue::Mthd_disable_subtitles,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "enable_subtitles",
    UFG::TSScriptedDialogue::Mthd_enable_subtitles,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "set_cutoff_distance",
    UFG::TSScriptedDialogue::Mthd_set_cutoff_distance,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "get_cutoff_distance",
    UFG::TSScriptedDialogue::Mthd_get_cutoff_distance,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "set_avoid_repeating",
    UFG::TSScriptedDialogue::Mthd_set_avoid_repeating_last,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "set_shuffle",
    UFG::TSScriptedDialogue::Mthd_set_shuffle,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "set_priority",
    UFG::TSScriptedDialogue::Mthd_set_priority,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "get_elements_group_count",
    UFG::TSScriptedDialogue::Mthd_num_element_groups,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "is_playing_last_line_in_group",
    UFG::TSScriptedDialogue::Mthd_is_playing_last_line_in_group,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "is_in_last_group",
    UFG::TSScriptedDialogue::Mthd_is_in_last_group,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "add_animation_bank",
    UFG::TSScriptedDialogue::Mthd_add_animation_bank,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "set_external_source_playback_event",
    UFG::TSScriptedDialogue::Mthd_set_external_source_playback_event,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "force_finish_all_scripted_conversations",
    UFG::TSScriptedDialogue::Mthd_force_finish_all_scripted_conversations,
    1,
    rebind);
  SSClass::register_coroutine_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "_wait_until_finished",
    UFG::TSScriptedDialogue::Coro_wait_until_finished,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "_wait_until_stopped",
    UFG::TSScriptedDialogue::Coro_wait_until_stopped,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "_play_until_finished",
    UFG::TSScriptedDialogue::Coro_play_finished,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "_play_until_stopped",
    UFG::TSScriptedDialogue::Coro_play_stopped,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "_play_until_stopped_or_finished",
    UFG::TSScriptedDialogue::Coro_play_stopped_or_finished,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "_stop",
    UFG::TSScriptedDialogue::Coro_stop,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "create",
    UFG::TSScriptedDialogue::MthdC_create,
    1,
    rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "find_named",
    UFG::TSScriptedDialogue::MthdC_find_named,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "get_named",
    UFG::TSScriptedDialogue::MthdC_get_named,
    1,
    rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "query_context",
    UFG::TSScriptedDialogue::MthdC_query_context,
    1,
    rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSScriptedDialogue::mspScriptedDialogueClass,
    "query_context_character",
    UFG::TSScriptedDialogue::MthdC_query_context_character,
    1,
    rebinde);
}

// File Line: 165
// RVA: 0x4F4150
void __fastcall UFG::TSScriptedDialogue::Mthd_add_element_by_reference(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rbx
  SSObjectBase *i_obj_p; // rcx
  const char *v5; // rax

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( i_data_p && i_data_p->i_class_p == UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    UFG::Conversation::AddElement(
      (UFG::Conversation *)i_obj_p[8].vfptr,
      (UFG::ConversationElement *)i_data_p[2].i_user_data);
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v5 = UFG::ConversationElement::ToString((UFG::ConversationElement *)i_data_p[2].i_user_data);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "add_element", v5);
    }
  }
}

// File Line: 208
// RVA: 0x4F3E10
void __fastcall UFG::TSScriptedDialogue::Mthd_add_element(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSActor *i_data_p; // rsi
  SSClass *i_class_p; // rbx
  SSActor *v5; // rbp
  SSClass *v6; // rbx
  SSData **i_array_p; // rcx
  SSInstance *v8; // r13
  unsigned __int64 i_user_data; // rax
  unsigned int v10; // r15d
  __int64 v11; // rdi
  unsigned int i; // ebx
  SSObjectBase *i_obj_p; // rdi
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
  UFG::qString v27; // [rsp+38h] [rbp-50h] BYREF

  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_6;
  i_class_p = i_data_p->i_class_p;
  if ( !i_class_p->vfptr->is_actor_class(i_class_p) )
  {
    if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    {
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
      goto LABEL_7;
    }
LABEL_6:
    i_data_p = 0i64;
  }
LABEL_7:
  v5 = *(SSActor **)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
  if ( !v5 )
    goto LABEL_12;
  v6 = v5->i_class_p;
  if ( v6->vfptr->is_actor_class(v6) )
    goto LABEL_13;
  if ( v6 == SSBrain::c_symbol_class_p && LODWORD(v5->i_user_data) != -1 )
    v5 = SSActor::find((ASymbol *)&v5->i_user_data);
  else
LABEL_12:
    v5 = 0i64;
LABEL_13:
  i_array_p = pScope->i_data.i_array_p;
  v8 = i_array_p[2]->i_data_p;
  i_user_data = i_array_p[3]->i_data_p->i_user_data;
  v10 = *(_DWORD *)i_user_data;
  v11 = *(_QWORD *)(i_user_data + 8);
  UFG::qString::qString(&v27, &customCaption);
  for ( i = 0; i < v10; v11 += 8i64 )
  {
    UFG::qString::operator+=(&v27, **(const char ***)(*(_QWORD *)v11 + 32i64));
    if ( i < v10 - 1 )
      UFG::qString::operator+=(&v27, ".");
    ++i;
  }
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  v14 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0xC0ui64, "add_element.ScriptedConversationElement", 0i64, 1u);
  v15 = v14;
  if ( v14 )
  {
    UFG::ConversationElement::ConversationElement((UFG::ConversationElement *)v14, eConversationElementType_Scripted);
    v15->mNext = (UFG::allocator::free_link *)&UFG::ScriptedConversationElement::`vftable;
    v15[20].mNext = 0i64;
    v15[21].mNext = 0i64;
    v15[22].mNext = 0i64;
    v15[23].mNext = 0i64;
    UFG::ScriptedConversationElement::SetupScript(
      (UFG::ScriptedConversationElement *)v15,
      (ASymbol *)&i_obj_p[4].i_ptr_id);
  }
  else
  {
    v15 = 0i64;
  }
  v16 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( v16 && (v17 = v16->i_class_p) != 0i64 && (v17->vfptr->is_actor_class(v17) || LODWORD(v16->i_user_data) != -1) )
  {
    if ( i_data_p && (v18 = *(UFG::SimObject **)&i_data_p[1].i_icoroutines_to_update.i_count) != 0i64 )
    {
      UFG::ConversationElement::SetSpeaker((UFG::ConversationElement *)v15, v18);
    }
    else
    {
      v15[22].mNext = (UFG::allocator::free_link *)(*pScope->i_data.i_array_p)->i_data_p;
      v19 = (*pScope->i_data.i_array_p)->i_data_p;
      ++v19->i_ref_count;
    }
  }
  else
  {
    v20 = UFG::ConversationElement::ToString((UFG::ConversationElement *)v15);
    UFG::qPrintf("TSScriptedDialogue: possible error adding -> %s\n", v20);
  }
  v21 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
  if ( v21
    && (v22 = *(_QWORD *)(v21 + 24)) != 0
    && ((*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v22 + 64i64))(v22) || *(_DWORD *)(v21 + 32) != -1) )
  {
    if ( v5 && (v23 = *(UFG::SimObject **)&v5[1].i_icoroutines_to_update.i_count) != 0i64 )
    {
      UFG::ConversationElement::SetTarget((UFG::ConversationElement *)v15, v23);
    }
    else
    {
      v15[23].mNext = *(UFG::allocator::free_link **)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
      v24 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 1) + 8i64);
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
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v26 = UFG::ConversationElement::ToString((UFG::ConversationElement *)v15);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "add_element", v26);
    }
    UFG::Conversation::AddElement((UFG::Conversation *)i_obj_p[8].vfptr, (UFG::ConversationElement *)v15);
  }
  UFG::qString::~qString(&v27);
}

// File Line: 304
// RVA: 0x50A810
void __fastcall UFG::TSScriptedDialogue::Mthd_set_tag_interruptable(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  bool v3; // bl
  SSObjectBaseVtbl *vfptr; // rcx
  char *v5; // rax
  __int64 v6; // rax
  UFG::qString v7; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  vfptr = i_obj_p[8].vfptr;
  if ( vfptr )
  {
    LOBYTE(vfptr[2].set_data_by_name) &= ~4u;
    LOBYTE(vfptr[2].set_data_by_name) |= 4 * v3;
  }
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
    UFG::qString::qString(&v7, "%s : %d", v5, v3);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "set_tag_interruptable", *(const char **)(v6 + 24));
    UFG::qString::~qString(&v7);
  }
}

// File Line: 317
// RVA: 0x50AFB0
void __fastcall UFG::TSScriptedDialogue::Mthd_set_topic(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdi
  char *v3; // rbx
  char *v4; // rax
  __int64 v5; // rax
  SSObjectBaseVtbl *vfptr; // rbx
  UFG::qString v7; // [rsp+28h] [rbp-30h] BYREF
  UFG::qSymbolUC v8; // [rsp+60h] [rbp+8h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  v8.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      v4 = UFG::qSymbol::as_cstr_dbg(&v8);
      UFG::qString::qString(&v7, "%s : %s", v3, v4);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "set_topic", *(const char **)(v5 + 24));
      UFG::qString::~qString(&v7);
    }
    vfptr = i_obj_p[8].vfptr;
    LODWORD(vfptr[2].is_actor) = UFG::Conversation::LookupTopic((UFG::qSymbol *)&v8);
  }
}

// File Line: 332
// RVA: 0x4FCBE0
void __fastcall UFG::TSScriptedDialogue::Mthd_get_element(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSInstance *i_data_p; // rax
  UFG::Conversation *vfptr; // rcx
  UFG::ConversationElement *Element; // rax
  SSInstance *v7; // rax
  SSInstance *v8; // rax

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    vfptr = (UFG::Conversation *)i_obj_p[8].vfptr;
    if ( vfptr && (Element = UFG::Conversation::GetElement(vfptr, i_data_p->i_user_data)) != 0i64 )
    {
      v7 = (SSInstance *)Element[1].vfptr;
      *ppResult = v7;
      ++v7->i_ref_count;
    }
    else
    {
      v8 = SSBrain::c_nil_p;
      *ppResult = SSBrain::c_nil_p;
      ++v8->i_ref_count;
    }
  }
}

// File Line: 354
// RVA: 0x502AD0
void __fastcall UFG::TSScriptedDialogue::Mthd_is_playing(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[8].vfptr;
  if ( vfptr )
    *ppResult = SSBoolean::pool_new(LODWORD(vfptr->get_scope_context) == 1);
}

// File Line: 367
// RVA: 0x5013D0
void __fastcall UFG::TSScriptedDialogue::Mthd_is_finished(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[8].vfptr;
  if ( vfptr )
    *ppResult = SSBoolean::pool_new(LODWORD(vfptr->get_scope_context) == 7);
}

// File Line: 379
// RVA: 0x502470
void __fastcall UFG::TSScriptedDialogue::Mthd_is_interrupted(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[8].vfptr;
  if ( vfptr )
    *ppResult = SSBoolean::pool_new(LODWORD(vfptr->get_scope_context) == 3);
}

// File Line: 391
// RVA: 0x5032B0
void __fastcall UFG::TSScriptedDialogue::Mthd_is_stopped(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[8].vfptr;
  if ( vfptr )
    *ppResult = SSBoolean::pool_new(LODWORD(vfptr->get_scope_context) == 6);
}

// File Line: 405
// RVA: 0x5023D0
void __fastcall UFG::TSScriptedDialogue::Mthd_is_inactive(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[8].vfptr;
  if ( vfptr )
    *ppResult = SSBoolean::pool_new(LODWORD(vfptr->get_scope_context) == 0);
}

// File Line: 417
// RVA: 0x4F7D10
void __fastcall UFG::TSScriptedDialogue::Mthd_destroy(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::Conversation *vfptr; // rcx
  UFG::qString v6; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
    UFG::qString::qString(&v6, "%s ", v3);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "destroy", *(const char **)(v4 + 24));
    UFG::qString::~qString(&v6);
  }
  vfptr = (UFG::Conversation *)i_obj_p[8].vfptr;
  if ( vfptr )
    UFG::ConversationManager::RemoveConversation(vfptr);
}

// File Line: 427
// RVA: 0x50C150
void __fastcall UFG::TSScriptedDialogue::Mthd_stop(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "stop", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    UFG::Conversation::Stop((UFG::Conversation *)i_obj_p[8].vfptr, 0);
  }
}

// File Line: 439
// RVA: 0x502ED0
void __fastcall UFG::TSScriptedDialogue::Mthd_is_playing_last_line_in_group(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  bool IsLastLineInGroup; // dl
  SSObjectBaseVtbl *vfptr; // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    IsLastLineInGroup = 0;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[8].vfptr;
    if ( vfptr )
    {
      if ( LODWORD(vfptr->get_scope_context) == 1 )
        IsLastLineInGroup = UFG::Conversation::IsLastLineInGroup((UFG::Conversation *)vfptr);
    }
    *ppResult = SSBoolean::pool_new(IsLastLineInGroup);
  }
}

// File Line: 458
// RVA: 0x501AA0
void __fastcall UFG::TSScriptedDialogue::Mthd_is_in_last_group(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  bool IsLast; // dl
  UFG::Conversation *vfptr; // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    IsLast = 0;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (UFG::Conversation *)i_obj_p[8].vfptr;
    if ( vfptr )
      IsLast = UFG::Conversation::CurrentGroupIsLast(vfptr);
    *ppResult = SSBoolean::pool_new(IsLast);
  }
}

// File Line: 474
// RVA: 0x4F3B00
void __fastcall UFG::TSScriptedDialogue::Mthd_add_animation_bank(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rdi
  SSObjectBase *i_obj_p; // rbx
  UFG::allocator::free_link *v4; // rax
  UFG::allocator::free_link *v5; // rdx
  int i_user_data; // ecx
  void (__fastcall **p_set_data_by_name)(SSObjectBase *, ASymbol *, SSInstance *); // rcx
  UFG::allocator::free_link *v8; // rax

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    v4 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
    v5 = v4;
    if ( v4 )
    {
      i_user_data = i_data_p->i_user_data;
      v4->mNext = v4;
      v4[1].mNext = v4;
      LODWORD(v4[2].mNext) = -1;
      LODWORD(v4[2].mNext) = i_user_data;
    }
    else
    {
      v5 = 0i64;
    }
    p_set_data_by_name = &i_obj_p[8].vfptr[1].set_data_by_name;
    v8 = (UFG::allocator::free_link *)*p_set_data_by_name;
    v8[1].mNext = v5;
    v5->mNext = v8;
    v5[1].mNext = (UFG::allocator::free_link *)p_set_data_by_name;
    *p_set_data_by_name = (void (__fastcall *)(SSObjectBase *, ASymbol *, SSInstance *))v5;
  }
}

// File Line: 486
// RVA: 0x507E70
void __fastcall UFG::TSScriptedDialogue::Mthd_set_external_source_playback_event(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( (*pScope->i_data.i_array_p)->i_data_p != (SSInstance *)-32i64 )
    {
      UFG::qWiseSymbol::create_from_string(&result, *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
      LODWORD(i_obj_p[8].vfptr[1].get_topmost_scope) = result;
      _((AMD_HD3D *)result.mUID);
    }
  }
}

// File Line: 498
// RVA: 0x50C240
void __fastcall UFG::TSScriptedDialogue::Mthd_stop_after_line(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "stop_after_line", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    UFG::Conversation::StopAfterCurrentLine((UFG::Conversation *)i_obj_p[8].vfptr);
  }
}

// File Line: 509
// RVA: 0x505CC0
void __fastcall UFG::TSScriptedDialogue::Mthd_play(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "play", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    UFG::Conversation::Start((UFG::Conversation *)i_obj_p[8].vfptr);
  }
}

// File Line: 521
// RVA: 0x504EF0
void __fastcall UFG::TSScriptedDialogue::Mthd_next_line(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "next_line", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    UFG::Conversation::NextLine((UFG::Conversation *)i_obj_p[8].vfptr);
  }
}

// File Line: 532
// RVA: 0x506110
void __fastcall UFG::TSScriptedDialogue::Mthd_prev_line(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "prev_line", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    UFG::Conversation::PrevLine((UFG::Conversation *)i_obj_p[8].vfptr);
  }
}

// File Line: 545
// RVA: 0x506970
void __fastcall UFG::TSScriptedDialogue::Mthd_restart(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "restart", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    UFG::Conversation::Restart((UFG::Conversation *)i_obj_p[8].vfptr);
  }
}

// File Line: 555
// RVA: 0x506800
void __fastcall UFG::TSScriptedDialogue::Mthd_reset(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "reset", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    UFG::Conversation::Reset((UFG::Conversation *)i_obj_p[8].vfptr);
  }
}

// File Line: 580
// RVA: 0x505020
void __fastcall UFG::TSScriptedDialogue::Mthd_num_element_groups(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  unsigned int GroupCount; // r9d
  UFG::Conversation *vfptr; // rcx

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    GroupCount = 0;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (UFG::Conversation *)i_obj_p[8].vfptr;
    if ( vfptr )
      GroupCount = UFG::Conversation::GetGroupCount(vfptr);
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, GroupCount);
  }
}

// File Line: 600
// RVA: 0x504EC0
void __fastcall UFG::TSScriptedDialogue::Mthd_move_to_next_group(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  UFG::Conversation *vfptr; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = (UFG::Conversation *)i_obj_p[8].vfptr;
  if ( vfptr )
    UFG::Conversation::MoveToNextGroup(vfptr);
}

// File Line: 622
// RVA: 0x4F5F00
void __fastcall UFG::TSScriptedDialogue::Mthd_auto_delete(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // di
  SSObjectBase *i_obj_p; // rbx
  char *v4; // rax
  __int64 v5; // rax
  SSObjectBaseVtbl *vfptr; // rax
  UFG::qString v7; // [rsp+28h] [rbp-30h] BYREF

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v7, "%s : %d", v4, v2);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "set_auto_delete", *(const char **)(v5 + 24));
      UFG::qString::~qString(&v7);
    }
    vfptr = i_obj_p[8].vfptr;
    LOBYTE(vfptr[2].set_data_by_name) &= ~2u;
    LOBYTE(vfptr[2].set_data_by_name) |= 2 * v2;
  }
}

// File Line: 635
// RVA: 0x4F83C0
void __fastcall UFG::TSScriptedDialogue::Mthd_disable_distance_cutoff(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "disable_distance_cutoff", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    LOBYTE(i_obj_p[8].vfptr[2].set_data_by_name) |= 8u;
  }
}

// File Line: 646
// RVA: 0x4F8A60
void __fastcall UFG::TSScriptedDialogue::Mthd_enable_distance_cutoff(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "enable_distance_cutoff", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    LOBYTE(i_obj_p[8].vfptr[2].set_data_by_name) &= ~8u;
  }
}

// File Line: 658
// RVA: 0x4F8580
void __fastcall UFG::TSScriptedDialogue::Mthd_disable_subtitles(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "disable_subtitles", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    LOBYTE(i_obj_p[8].vfptr[2].set_data_by_name) &= ~0x80u;
  }
}

// File Line: 669
// RVA: 0x4F91B0
void __fastcall UFG::TSScriptedDialogue::Mthd_enable_subtitles(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "enable_subtitles", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    LOBYTE(i_obj_p[8].vfptr[2].set_data_by_name) |= 0x80u;
  }
}

// File Line: 682
// RVA: 0x4F8470
void __fastcall UFG::TSScriptedDialogue::Mthd_disable_interrupts(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "disable_interrupts", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    BYTE1(i_obj_p[8].vfptr[2].set_data_by_name) |= 4u;
  }
}

// File Line: 693
// RVA: 0x4F8C20
void __fastcall UFG::TSScriptedDialogue::Mthd_enable_interrupts(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "enable_interrupts", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    BYTE1(i_obj_p[8].vfptr[2].set_data_by_name) &= ~4u;
  }
}

// File Line: 705
// RVA: 0x4F8330
void __fastcall UFG::TSScriptedDialogue::Mthd_disable_car_exit_interrupts(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "disable_car_exit_interrupts", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    BYTE1(i_obj_p[8].vfptr[2].set_data_by_name) &= ~8u;
  }
}

// File Line: 716
// RVA: 0x4F88E0
void __fastcall UFG::TSScriptedDialogue::Mthd_enable_car_exit_interrupts(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  char *v3; // rax
  __int64 v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v5, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "enable_car_exit_interrupts", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v5);
    }
    BYTE1(i_obj_p[8].vfptr[2].set_data_by_name) |= 8u;
  }
}

// File Line: 730
// RVA: 0x507D20
void __fastcall UFG::TSScriptedDialogue::Mthd_set_cutoff_distance(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rdi
  SSObjectBase *i_obj_p; // rbx
  char *v4; // rax
  __int64 v5; // rax
  UFG::qString v6; // [rsp+28h] [rbp-30h] BYREF

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v6, "%s : %d", v4, *(float *)&i_data_p->i_user_data);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "set_cutoff_distance", *(const char **)(v5 + 24));
      UFG::qString::~qString(&v6);
    }
    LODWORD(i_obj_p[8].vfptr[2].as_instance) = i_data_p->i_user_data;
  }
}

// File Line: 745
// RVA: 0x5072D0
void __fastcall UFG::TSScriptedDialogue::Mthd_set_avoid_repeating_last(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rdi
  SSObjectBase *i_obj_p; // rbx
  char *v4; // rax
  __int64 v5; // rax
  UFG::qString v6; // [rsp+28h] [rbp-30h] BYREF

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v6, "%s : %u", v4, LODWORD(i_data_p->i_user_data));
      UFG::qPrintf("Dlg Trc: %s : %s\n", "set_avoid_repeating_last", *(const char **)(v5 + 24));
      UFG::qString::~qString(&v6);
    }
    WORD2(i_obj_p[8].vfptr[2].get_data_by_name) = i_data_p->i_user_data;
  }
}

// File Line: 760
// RVA: 0x50A460
void __fastcall UFG::TSScriptedDialogue::Mthd_set_shuffle(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v2; // di
  SSObjectBase *i_obj_p; // rbx
  char *v4; // rax
  __int64 v5; // rax
  SSObjectBaseVtbl *vfptr; // rax
  UFG::qString v7; // [rsp+28h] [rbp-30h] BYREF

  v2 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v7, "%s : %d", v4, v2);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "set_shuffle", *(const char **)(v5 + 24));
      UFG::qString::~qString(&v7);
    }
    vfptr = i_obj_p[8].vfptr;
    LOBYTE(vfptr[2].set_data_by_name) &= ~0x20u;
    LOBYTE(vfptr[2].set_data_by_name) |= 32 * v2;
  }
}

// File Line: 774
// RVA: 0x509F30
void __fastcall UFG::TSScriptedDialogue::Mthd_set_priority(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rdi
  SSObjectBase *i_obj_p; // rbx
  char *v4; // rax
  __int64 v5; // rax
  UFG::qString v6; // [rsp+28h] [rbp-30h] BYREF

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( i_obj_p[8].vfptr )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v6, "%s : %d", v4, LODWORD(i_data_p->i_user_data));
      UFG::qPrintf("Dlg Trc: %s : %s\n", "set_priority", *(const char **)(v5 + 24));
      UFG::qString::~qString(&v6);
    }
    WORD2(i_obj_p[8].vfptr->get_topmost_scope) = i_data_p->i_user_data;
  }
}

// File Line: 790
// RVA: 0x4FC3D0
void __fastcall UFG::TSScriptedDialogue::Mthd_get_cutoff_distance(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rax

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[8].vfptr;
  if ( vfptr )
    *ppResult = SSInstance::pool_new(
                  SSBrain::c_integer_class_p,
                  WORD1(vfptr->get_topmost_scope) - (unsigned int)LOWORD(vfptr->get_topmost_scope) - 1);
}

// File Line: 802
// RVA: 0x4E4890
void __fastcall UFG::TSScriptedDialogue::MthdC_create(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned __int64 *p_i_user_data; // rbx
  UFG::ScriptedConversation *v4; // rsi
  char *v5; // rax
  __int64 v6; // rax
  SSInstance *m_script; // rax
  char *v8; // rax
  __int64 v9; // rax
  UFG::qString v10; // [rsp+28h] [rbp-30h] BYREF

  p_i_user_data = &(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = UFG::ConversationManager::AddScriptedConversation((ASymbol *)p_i_user_data);
  if ( v4 )
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)p_i_user_data);
      UFG::qString::qString(&v10, "%s ", v5);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "create_conversation", *(const char **)(v6 + 24));
      UFG::qString::~qString(&v10);
    }
    m_script = v4->m_script;
    if ( m_script )
      ++m_script->i_ref_count;
  }
  else
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)p_i_user_data);
      UFG::qString::qString(&v10, "%s ", v8);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "** FAIL *** create_conversation", *(const char **)(v9 + 24));
      UFG::qString::~qString(&v10);
    }
    m_script = SSBrain::c_nil_p;
  }
  *ppResult = m_script;
}

// File Line: 831
// RVA: 0x4E65D0
void __fastcall UFG::TSScriptedDialogue::MthdC_find_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int i_user_data; // edx
  UFG::qBaseTreeRB *v4; // rax
  int *p_mCount; // rax
  SSInstance *v6; // rax

  if ( ppResult )
  {
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( i_user_data
      && (v4 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, i_user_data)) != 0i64
      && (p_mCount = &v4[-1].mCount) != 0i64 )
    {
      v6 = (SSInstance *)*((_QWORD *)p_mCount + 22);
      if ( v6 )
      {
        ++v6->i_ref_count;
        *ppResult = v6;
        return;
      }
    }
    else
    {
      v6 = SSBrain::c_nil_p;
    }
    *ppResult = v6;
  }
}

// File Line: 850
// RVA: 0x4E8350
void __fastcall UFG::TSScriptedDialogue::MthdC_get_named(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  unsigned int i_user_data; // edx
  UFG::qBaseTreeRB *v4; // rax
  int *p_mCount; // rax
  SSInstance *v6; // rcx

  if ( ppResult )
  {
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    if ( i_user_data
      && (v4 = UFG::qBaseTreeRB::Get(&UFG::ConversationManager::sm_conversationDb.mTree, i_user_data)) != 0i64 )
    {
      p_mCount = &v4[-1].mCount;
    }
    else
    {
      p_mCount = 0i64;
    }
    v6 = (SSInstance *)*((_QWORD *)p_mCount + 22);
    if ( v6 )
      ++v6->i_ref_count;
    *ppResult = v6;
  }
}

// File Line: 876
// RVA: 0x4DEE20
char __fastcall UFG::TSScriptedDialogue::Coro_wait_until_finished(SSInvokedCoroutine *pScope)
{
  SSObjectBase *i_obj_p; // rcx
  char *v3; // rax
  __int64 v4; // rax
  SSObjectBaseVtbl *vfptr; // rax
  char v7; // bl
  char *v8; // rax
  __int64 v9; // rax
  UFG::qString v10; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( pScope->i_update_count )
  {
    vfptr = i_obj_p[8].vfptr;
    if ( vfptr && LODWORD(vfptr->get_scope_context) != 7 )
      return 0;
    v7 = 1;
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v10, "%s ", v8);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "_wait_until_finished : finished", *(const char **)(v9 + 24));
      UFG::qString::~qString(&v10);
    }
    return v7;
  }
  else
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v10, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "_wait_until_finished : start", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v10);
    }
    return 0;
  }
}

// File Line: 903
// RVA: 0x4DC770
char __fastcall UFG::TSScriptedDialogue::Coro_play_finished(SSInvokedCoroutine *pScope)
{
  SSObjectBase *i_obj_p; // rbx
  char *v2; // rax
  __int64 v3; // rax
  SSObjectBaseVtbl *vfptr; // rax
  char v6; // di
  char *v7; // rax
  __int64 v8; // rax
  UFG::qString v9; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( pScope->i_update_count )
  {
    vfptr = i_obj_p[8].vfptr;
    if ( vfptr && LODWORD(vfptr->get_scope_context) != 7 )
      return 0;
    v6 = 1;
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v9, "%s ", v7);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "_play : finished", *(const char **)(v8 + 24));
      UFG::qString::~qString(&v9);
    }
    return v6;
  }
  else
  {
    if ( i_obj_p[8].vfptr )
    {
      if ( UFG::ConversationManager::sm_traceScrConversations )
      {
        v2 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
        UFG::qString::qString(&v9, "%s ", v2);
        UFG::qPrintf("Dlg Trc: %s : %s\n", "_play : start", *(const char **)(v3 + 24));
        UFG::qString::~qString(&v9);
      }
      UFG::Conversation::Start((UFG::Conversation *)i_obj_p[8].vfptr);
    }
    return 0;
  }
}

// File Line: 935
// RVA: 0x4DC8F0
char __fastcall UFG::TSScriptedDialogue::Coro_play_stopped(SSInvokedCoroutine *pScope)
{
  SSObjectBase *i_obj_p; // rbx
  char *v2; // rax
  __int64 v3; // rax
  SSObjectBaseVtbl *vfptr; // rax
  char v6; // di
  char *v7; // rax
  __int64 v8; // rax
  UFG::qString v9; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( pScope->i_update_count )
  {
    vfptr = i_obj_p[8].vfptr;
    if ( vfptr && LODWORD(vfptr->get_scope_context) != 6 )
      return 0;
    v6 = 1;
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v9, "%s ", v7);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "_play : stopped", *(const char **)(v8 + 24));
      UFG::qString::~qString(&v9);
    }
    return v6;
  }
  else
  {
    if ( i_obj_p[8].vfptr )
    {
      if ( UFG::ConversationManager::sm_traceScrConversations )
      {
        v2 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
        UFG::qString::qString(&v9, "%s ", v2);
        UFG::qPrintf("Dlg Trc: %s : %s\n", "_play : start", *(const char **)(v3 + 24));
        UFG::qString::~qString(&v9);
      }
      UFG::Conversation::Start((UFG::Conversation *)i_obj_p[8].vfptr);
    }
    return 0;
  }
}

// File Line: 967
// RVA: 0x4DCA00
char __fastcall UFG::TSScriptedDialogue::Coro_play_stopped_or_finished(SSInvokedCoroutine *pScope)
{
  SSObjectBase *i_obj_p; // rbx
  char *v2; // rax
  __int64 v3; // rax
  SSObjectBaseVtbl *vfptr; // rax
  char v6; // di
  char *v7; // rax
  __int64 v8; // rax
  UFG::qString v9; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( pScope->i_update_count )
  {
    vfptr = i_obj_p[8].vfptr;
    if ( vfptr && (unsigned int)(LODWORD(vfptr->get_scope_context) - 6) > 1 )
      return 0;
    v6 = 1;
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v9, "%s ", v7);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "_play : stopped or finished", *(const char **)(v8 + 24));
      UFG::qString::~qString(&v9);
    }
    return v6;
  }
  else
  {
    if ( i_obj_p[8].vfptr )
    {
      if ( UFG::ConversationManager::sm_traceScrConversations )
      {
        v2 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
        UFG::qString::qString(&v9, "%s ", v2);
        UFG::qPrintf("Dlg Trc: %s : %s\n", "_play : start", *(const char **)(v3 + 24));
        UFG::qString::~qString(&v9);
      }
      UFG::Conversation::Start((UFG::Conversation *)i_obj_p[8].vfptr);
    }
    return 0;
  }
}

// File Line: 1000
// RVA: 0x4DE000
char __fastcall UFG::TSScriptedDialogue::Coro_stop(SSInvokedCoroutine *pScope)
{
  SSObjectBase *i_obj_p; // rbx
  UFG::Conversation *v2; // rcx
  char *v3; // rax
  __int64 v4; // rax
  SSObjectBaseVtbl *vfptr; // rax
  char v7; // di
  char *v8; // rax
  __int64 v9; // rax
  UFG::qString v10; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( pScope->i_update_count )
  {
    vfptr = i_obj_p[8].vfptr;
    if ( vfptr && LODWORD(vfptr->get_scope_context) != 6 )
      return 0;
    v7 = 1;
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v10, "%s ", v8);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "_stop : finished", *(const char **)(v9 + 24));
      UFG::qString::~qString(&v10);
    }
    return v7;
  }
  else
  {
    v2 = (UFG::Conversation *)i_obj_p[8].vfptr;
    if ( v2 )
      UFG::Conversation::Stop(v2, 0);
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v10, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "_stop : start", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v10);
    }
    return 0;
  }
}

// File Line: 1069
// RVA: 0x4DF220
char __fastcall UFG::TSScriptedDialogue::Coro_wait_until_stopped(SSInvokedCoroutine *pScope)
{
  SSObjectBase *i_obj_p; // rcx
  char *v3; // rax
  __int64 v4; // rax
  SSObjectBaseVtbl *vfptr; // rax
  char v7; // bl
  char *v8; // rax
  __int64 v9; // rax
  UFG::qString v10; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( pScope->i_update_count )
  {
    vfptr = i_obj_p[8].vfptr;
    if ( vfptr && LODWORD(vfptr->get_scope_context) != 6 )
      return 0;
    v7 = 1;
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v10, "%s ", v8);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "_wait_until_stopped : finished", *(const char **)(v9 + 24));
      UFG::qString::~qString(&v10);
    }
    return v7;
  }
  else
  {
    if ( UFG::ConversationManager::sm_traceScrConversations )
    {
      v3 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
      UFG::qString::qString(&v10, "%s ", v3);
      UFG::qPrintf("Dlg Trc: %s : %s\n", "_wait_until_stopped : start", *(const char **)(v4 + 24));
      UFG::qString::~qString(&v10);
    }
    return 0;
  }
}

// File Line: 1098
// RVA: 0x5125A0
void __fastcall UFG::TSScriptedDialogue::on_no_references(UFG::TSScriptedDialogueElement *this)
{
  SSInstance::call_destructor(this);
  if ( this )
    this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 1157
// RVA: 0x4FA1C0
// attributes: thunk
void __fastcall UFG::TSScriptedDialogue::Mthd_force_finish_all_scripted_conversations(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  UFG::ConversationManager::StopAllScriptedConversations();
}

// File Line: 1170
// RVA: 0x4EB9D0
void __fastcall UFG::TSScriptedDialogue::MthdC_query_context(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  unsigned __int64 i_user_data; // rax
  int v5; // ecx
  _QWORD *v6; // rsi
  int v7; // eax
  __int64 v8; // rbp
  int v9; // ebx
  int v10; // edi
  UFG::allocator::free_link *v11; // rax
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *mPrev; // rcx
  UFG::Query query; // [rsp+28h] [rbp-30h] BYREF

  UFG::Query::Query(&query);
  i_array_p = pScope->i_data.i_array_p;
  query.m_concept.mUID = (*i_array_p)->i_data_p->i_user_data;
  i_user_data = i_array_p[1]->i_data_p->i_user_data;
  v5 = *(_DWORD *)i_user_data;
  v6 = *(_QWORD **)(i_user_data + 8);
  v7 = *(_DWORD *)i_user_data - 1;
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
      mPrev = query.m_facts.mNode.mPrev;
      query.m_facts.mNode.mPrev->mNext = (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)v11;
      v11->mNext = (UFG::allocator::free_link *)mPrev;
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
  SSData **i_array_p; // r8
  SSInstance *i_data_p; // rcx
  unsigned __int64 i_user_data; // rax
  _QWORD *v6; // rsi
  int v7; // eax
  __int64 v8; // rbp
  int v9; // ebx
  int v10; // edi
  UFG::allocator::free_link *v11; // rax
  UFG::qNode<UFG::KeyValue,UFG::KeyValue> *mPrev; // rcx
  UFG::Query query; // [rsp+28h] [rbp-30h] BYREF

  UFG::Query::Query(&query);
  i_array_p = pScope->i_data.i_array_p;
  i_data_p = i_array_p[1]->i_data_p;
  query.m_concept.mUID = (*i_array_p)->i_data_p->i_user_data;
  query.m_character.mUID = i_data_p->i_user_data;
  i_user_data = i_array_p[1]->i_data_p->i_user_data;
  LODWORD(i_data_p) = *(_DWORD *)i_user_data;
  v6 = *(_QWORD **)(i_user_data + 8);
  v7 = *(_DWORD *)i_user_data - 1;
  if ( (_DWORD)i_data_p != 1 )
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
      mPrev = query.m_facts.mNode.mPrev;
      query.m_facts.mNode.mPrev->mNext = (UFG::qNode<UFG::KeyValue,UFG::KeyValue> *)v11;
      v11->mNext = (UFG::allocator::free_link *)mPrev;
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
void __fastcall UFG::TSScriptedDialogueElement::TSScriptedDialogueElement(
        UFG::TSScriptedDialogueElement *this,
        UFG::ScriptedConversationElement *conv,
        ASymbol *name,
        SSActorClass *pClass)
{
  SSActor::SSActor(this, name, pClass, 1);
  this->vfptr = (SSObjectBaseVtbl *)&UFG::TSScriptedDialogueElement::`vftable;
  this->m_element = conv;
}

// File Line: 1294
// RVA: 0x4D6030
void UFG::TSScriptedDialogueElement::BindAtomics(void)
{
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]

  UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass = (SSActorClass *)SSBrain::get_class("ScriptedDialogueElement");
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "set_speaker",
    UFG::TSScriptedDialogueElement::Mthd_set_speaker,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "set_target",
    UFG::TSScriptedDialogueElement::Mthd_set_target,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "set_args",
    UFG::TSScriptedDialogueElement::Mthd_set_args,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "set_pre_delay",
    UFG::TSScriptedDialogueElement::Mthd_set_pre_delay,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "add_interruption_point",
    UFG::TSScriptedDialogueElement::Mthd_add_interruption_point,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "remove_interruption_point",
    UFG::TSScriptedDialogueElement::Mthd_remove_interruption_point,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "set_interjection_point",
    UFG::TSScriptedDialogueElement::Mthd_set_interjection_point,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "stop_after_play",
    UFG::TSScriptedDialogueElement::Mthd_stop_after_play,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "set_resume_checkpoint",
    UFG::TSScriptedDialogueElement::Mthd_set_resume_checkpoint,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "set_playback_event",
    UFG::TSScriptedDialogueElement::Mthd_set_playback_event,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "kill_on_interruption_point",
    UFG::TSScriptedDialogueElement::Mthd_kill_on_interrupt,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "set_is_highest_priority",
    UFG::TSScriptedDialogueElement::Mthd_set_is_highest_priority,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "play_from_position",
    UFG::TSScriptedDialogueElement::Mthd_play_from_position,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "speaker_emotion",
    UFG::TSScriptedDialogueElement::Mthd_speaker_emotion,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "listener_emotion",
    UFG::TSScriptedDialogueElement::Mthd_listener_emotion,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "speaker_action_request",
    UFG::TSScriptedDialogueElement::Mthd_speaker_action_request,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "listener_action_request",
    UFG::TSScriptedDialogueElement::Mthd_listener_action_request,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "_wait_on_interruption_point",
    UFG::TSScriptedDialogueElement::Coro_wait_on_interruption_point,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "create",
    UFG::TSScriptedDialogueElement::MthdC_create,
    1,
    rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(
    UFG::TSScriptedDialogueElement::mspScriptedDialogueElementClass,
    "get_named",
    UFG::TSAudio::MthdC_get_named,
    1,
    rebinda);
}

// File Line: 1332
// RVA: 0x4E4990
void __fastcall UFG::TSScriptedDialogueElement::MthdC_create(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rsi
  UFG::allocator::free_link *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  char *v7; // rax
  __int64 v8; // rax
  SSInstance *v9; // rax
  UFG::qString v10; // [rsp+38h] [rbp-30h] BYREF

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  v4 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0xC0ui64, "create.ScriptedConversationElement", 0i64, 1u);
  if ( v4 )
  {
    UFG::ScriptedConversationElement::ScriptedConversationElement(
      (UFG::ScriptedConversationElement *)v4,
      (ASymbol *)&i_data_p->i_user_data);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_data_p->i_user_data);
    UFG::qString::qString(&v10, "%s ", v7);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "create element", *(const char **)(v8 + 24));
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
  *ppResult = v9;
}

// File Line: 1372
// RVA: 0x50A520
void __fastcall UFG::TSScriptedDialogueElement::Mthd_set_speaker(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rsi
  SSActor *i_data_p; // rbx
  SSClass *i_class_p; // r14
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
  UFG::qString v16; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_9;
  i_class_p = i_data_p->i_class_p;
  if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSInstance **))i_class_p->vfptr->is_actor_class)(
          i_class_p,
          ppResult) )
  {
    if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    {
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
      goto LABEL_10;
    }
LABEL_9:
    i_data_p = 0i64;
  }
LABEL_10:
  v6 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( v6 )
  {
    v7 = v6->i_class_p;
    if ( v7 )
    {
      if ( v7->vfptr->is_actor_class(v7) || LODWORD(v6->i_user_data) != -1 )
      {
        if ( i_data_p && (v8 = *(UFG::SimObject **)&i_data_p[1].i_icoroutines_to_update.i_count) != 0i64 )
        {
          UFG::ConversationElement::SetSpeaker((UFG::ConversationElement *)i_obj_p[8].vfptr, v8);
          if ( !UFG::ConversationManager::sm_traceScrConversations )
            return;
          v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_data_p->ANamed);
          v10 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
          UFG::qString::qString(&v16, "%s : %s ", v10, v9);
          UFG::qPrintf("Dlg Trc: %s : %s\n", "set_speaker", *(const char **)(v11 + 24));
        }
        else
        {
          i_obj_p[8].vfptr[2].get_scope_context = (SSInvokedContextBase *(__fastcall *)(SSObjectBase *))(*pScope->i_data.i_array_p)->i_data_p;
          v12 = (*pScope->i_data.i_array_p)->i_data_p;
          ++v12->i_ref_count;
          if ( !UFG::ConversationManager::sm_traceScrConversations )
            return;
          v13 = (*pScope->i_data.i_array_p)->i_data_p;
          v14 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
          UFG::qString::qString(&v16, "%s : %s ", v14, (const char *)&v13->i_user_data);
          UFG::qPrintf("Dlg Trc: %s : %s\n", "set_speaker", *(const char **)(v15 + 24));
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
  SSObjectBase *i_obj_p; // rbp
  SSActor *i_data_p; // rdi
  SSClass *i_class_p; // rbx
  char *v6; // rbx
  char *v7; // rax
  __int64 v8; // rax
  SSInstance *v9; // rbx
  SSClass *v10; // rcx
  UFG::SimObject *v11; // rdx
  SSInstance *v12; // rax
  UFG::qString v13; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_data_p = (SSActor *)(*pScope->i_data.i_array_p)->i_data_p;
  if ( !i_data_p )
    goto LABEL_12;
  i_class_p = i_data_p->i_class_p;
  if ( !((unsigned __int8 (__fastcall *)(SSClass *, SSInstance **))i_class_p->vfptr->is_actor_class)(
          i_class_p,
          ppResult) )
  {
    if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(i_data_p->i_user_data) != -1 )
    {
      i_data_p = SSActor::find((ASymbol *)&i_data_p->i_user_data);
      goto LABEL_9;
    }
LABEL_12:
    i_data_p = 0i64;
    goto LABEL_13;
  }
LABEL_9:
  if ( i_data_p && UFG::ConversationManager::sm_traceScrConversations )
  {
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_data_p->ANamed);
    v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
    UFG::qString::qString(&v13, "%s : %s ", v7, v6);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "set_target", *(const char **)(v8 + 24));
    UFG::qString::~qString(&v13);
  }
LABEL_13:
  v9 = (*pScope->i_data.i_array_p)->i_data_p;
  if ( v9 )
  {
    v10 = v9->i_class_p;
    if ( v10 )
    {
      if ( v10->vfptr->is_actor_class(v10) || LODWORD(v9->i_user_data) != -1 )
      {
        if ( i_data_p && (v11 = *(UFG::SimObject **)&i_data_p[1].i_icoroutines_to_update.i_count) != 0i64 )
        {
          UFG::ConversationElement::SetTarget((UFG::ConversationElement *)i_obj_p[8].vfptr, v11);
        }
        else
        {
          i_obj_p[8].vfptr[2].get_topmost_scope = (SSInstance *(__fastcall *)(SSObjectBase *))(*pScope->i_data.i_array_p)->i_data_p;
          v12 = (*pScope->i_data.i_array_p)->i_data_p;
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
  unsigned __int64 i_user_data; // rdx
  unsigned int v4; // esi
  __int64 v5; // rdi
  unsigned int i; // ebx
  SSObjectBase *i_obj_p; // rcx
  UFG::qString v8; // [rsp+38h] [rbp-30h] BYREF

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v4 = *(_DWORD *)i_user_data;
  v5 = *(_QWORD *)(i_user_data + 8);
  UFG::qString::qString(&v8, &customCaption);
  for ( i = 0; i < v4; v5 += 8i64 )
  {
    UFG::qString::operator+=(&v8, **(const char ***)(*(_QWORD *)v5 + 32i64));
    if ( i < v4 - 1 )
      UFG::qString::operator+=(&v8, ".");
    ++i;
  }
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::qString::Set((UFG::qString *)&i_obj_p[8].vfptr->get_data_by_name, v8.mData, v8.mLength, 0i64, 0);
  UFG::qString::~qString(&v8);
}

// File Line: 1465
// RVA: 0x509E90
void __fastcall UFG::TSScriptedDialogueElement::Mthd_set_pre_delay(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSInstance *i_data_p; // rbx
  char *v4; // rax
  __int64 v5; // rax
  UFG::qString v6; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  LODWORD(i_obj_p[8].vfptr[1].get_obj_type) = i_data_p->i_user_data;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
    UFG::qString::qString(&v6, "%s : %d ", v4, *(float *)&i_data_p->i_user_data);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "set_pre_delay", *(const char **)(v5 + 24));
    UFG::qString::~qString(&v6);
  }
}

// File Line: 1479
// RVA: 0x4F4280
void __fastcall UFG::TSScriptedDialogueElement::Mthd_add_interruption_point(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rdi
  SSInstance *v5; // rsi
  char *v6; // rax
  __int64 v7; // rax
  UFG::qString v8; // [rsp+38h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v5 = i_array_p[1]->i_data_p;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
    UFG::qString::qString(&v8, "%s : %u %d ", v6, LODWORD(i_data_p->i_user_data), *(float *)&v5->i_user_data);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "add_interruption_point", *(const char **)(v7 + 24));
    UFG::qString::~qString(&v8);
  }
  UFG::ConversationElement::AddInterruptPoint(
    (UFG::ConversationElement *)i_obj_p[8].vfptr,
    i_data_p->i_user_data,
    *(float *)&v5->i_user_data);
}

// File Line: 1493
// RVA: 0x50B870
void __fastcall UFG::TSScriptedDialogueElement::Mthd_speaker_emotion(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdi
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // r15
  SSInstance *v5; // rsi
  SSInstance *v6; // r14
  __int64 v7; // rbx
  char *v8; // rax
  __int64 v9; // rax
  UFG::qString v10; // [rsp+38h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v5 = i_array_p[1]->i_data_p;
  v6 = i_array_p[2]->i_data_p;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v7 = *(_QWORD *)v6->i_user_data;
    v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
    UFG::qString::qString(&v10, "%s : %f %s", v8, *(float *)&v5->i_user_data, v7);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "add_speaker_emotion", *(const char **)(v9 + 24));
    UFG::qString::~qString(&v10);
  }
  UFG::ConversationElement::AddEmotionRequest(
    (UFG::ConversationElement *)i_obj_p[8].vfptr,
    i_data_p->i_user_data,
    *(float *)&v5->i_user_data,
    *(const char **)v6->i_user_data,
    0);
}

// File Line: 1510
// RVA: 0x504950
void __fastcall UFG::TSScriptedDialogueElement::Mthd_listener_emotion(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdi
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // r15
  SSInstance *v5; // rsi
  SSInstance *v6; // r14
  __int64 v7; // rbx
  char *v8; // rax
  __int64 v9; // rax
  UFG::qString v10; // [rsp+38h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v5 = i_array_p[1]->i_data_p;
  v6 = i_array_p[2]->i_data_p;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v7 = *(_QWORD *)v6->i_user_data;
    v8 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
    UFG::qString::qString(&v10, "%s : %f %s", v8, *(float *)&v5->i_user_data, v7);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "add_listener_emotion", *(const char **)(v9 + 24));
    UFG::qString::~qString(&v10);
  }
  UFG::ConversationElement::AddEmotionRequest(
    (UFG::ConversationElement *)i_obj_p[8].vfptr,
    i_data_p->i_user_data,
    *(float *)&v5->i_user_data,
    *(const char **)v6->i_user_data,
    1);
}

// File Line: 1527
// RVA: 0x50B6D0
void __fastcall UFG::TSScriptedDialogueElement::Mthd_speaker_action_request(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rsi
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // r15
  SSInstance *v6; // rbp
  SSInstance *v7; // r14
  __int64 v8; // rbx
  char *v9; // rax
  __int64 v10; // rax
  UFG::ConversationElementActionRequest *v11; // rbp
  SSActor *v12; // rbx
  SSClass *i_class_p; // rsi
  __int64 v14; // rsi
  __int64 v15; // rcx
  UFG::SimObject *v16; // rax
  __int64 v17; // rax
  UFG::qString v18; // [rsp+38h] [rbp-40h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v6 = i_array_p[1]->i_data_p;
  v7 = i_array_p[2]->i_data_p;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v8 = *(_QWORD *)v7->i_user_data;
    v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
    UFG::qString::qString(&v18, "%s : %f %s", v9, *(float *)&v6->i_user_data, v8);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "add_action_request", *(const char **)(v10 + 24));
    UFG::qString::~qString(&v18);
  }
  v11 = UFG::ConversationElement::AddActionRequest(
          (UFG::ConversationElement *)i_obj_p[8].vfptr,
          i_data_p->i_user_data,
          *(float *)&v6->i_user_data,
          *(const char **)v7->i_user_data,
          0);
  v12 = *(SSActor **)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64);
  if ( !v12 )
    goto LABEL_11;
  i_class_p = v12->i_class_p;
  if ( !i_class_p->vfptr->is_actor_class(i_class_p) )
  {
    if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(v12->i_user_data) != -1 )
    {
      v12 = SSActor::find((ASymbol *)&v12->i_user_data);
      goto LABEL_12;
    }
LABEL_11:
    v12 = 0i64;
  }
LABEL_12:
  v14 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64);
  if ( v14 )
  {
    v15 = *(_QWORD *)(v14 + 24);
    if ( v15 )
    {
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v15 + 64i64))(v15) || *(_DWORD *)(v14 + 32) != -1 )
      {
        if ( v12 && (v16 = *(UFG::SimObject **)&v12[1].i_icoroutines_to_update.i_count) != 0i64 )
        {
          v11->m_target = v16;
        }
        else
        {
          v11->m_targetInst = *(SSInstance **)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64);
          v17 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64);
          ++*(_DWORD *)(v17 + 16);
        }
      }
    }
  }
}

// File Line: 1560
// RVA: 0x5047B0
void __fastcall UFG::TSScriptedDialogueElement::Mthd_listener_action_request(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rsi
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // r15
  SSInstance *v6; // rbp
  SSInstance *v7; // r14
  __int64 v8; // rbx
  char *v9; // rax
  __int64 v10; // rax
  UFG::ConversationElementActionRequest *v11; // rbp
  SSActor *v12; // rbx
  SSClass *i_class_p; // rsi
  __int64 v14; // rsi
  __int64 v15; // rcx
  UFG::SimObject *v16; // rax
  __int64 v17; // rax
  UFG::qString v18; // [rsp+38h] [rbp-40h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v6 = i_array_p[1]->i_data_p;
  v7 = i_array_p[2]->i_data_p;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v8 = *(_QWORD *)v7->i_user_data;
    v9 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
    UFG::qString::qString(&v18, "%s : %f %s ", v9, *(float *)&v6->i_user_data, v8);
    UFG::qPrintf("Dlg Trc: %s : %s\n", "add_action_request", *(const char **)(v10 + 24));
    UFG::qString::~qString(&v18);
  }
  v11 = UFG::ConversationElement::AddActionRequest(
          (UFG::ConversationElement *)i_obj_p[8].vfptr,
          i_data_p->i_user_data,
          *(float *)&v6->i_user_data,
          *(const char **)v7->i_user_data,
          1);
  v12 = *(SSActor **)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64);
  if ( !v12 )
    goto LABEL_11;
  i_class_p = v12->i_class_p;
  if ( !i_class_p->vfptr->is_actor_class(i_class_p) )
  {
    if ( i_class_p == SSBrain::c_symbol_class_p && LODWORD(v12->i_user_data) != -1 )
    {
      v12 = SSActor::find((ASymbol *)&v12->i_user_data);
      goto LABEL_12;
    }
LABEL_11:
    v12 = 0i64;
  }
LABEL_12:
  v14 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64);
  if ( v14 )
  {
    v15 = *(_QWORD *)(v14 + 24);
    if ( v15 )
    {
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v15 + 64i64))(v15) || *(_DWORD *)(v14 + 32) != -1 )
      {
        if ( v12 && (v16 = *(UFG::SimObject **)&v12[1].i_icoroutines_to_update.i_count) != 0i64 )
        {
          v11->m_target = v16;
        }
        else
        {
          v11->m_targetInst = *(SSInstance **)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64);
          v17 = *(_QWORD *)(*((_QWORD *)pScope->i_data.i_array_p + 3) + 8i64);
          ++*(_DWORD *)(v17 + 16);
        }
      }
    }
  }
}

// File Line: 1593
// RVA: 0x506650
void __fastcall UFG::TSScriptedDialogueElement::Mthd_remove_interruption_point(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rbx
  SSInstance *i_data_p; // rdi
  char *v4; // rax
  __int64 v5; // rax
  UFG::qString v6; // [rsp+28h] [rbp-30h] BYREF

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  if ( UFG::ConversationManager::sm_traceScrConversations )
  {
    v4 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_obj_p[4].i_ptr_id);
    UFG::qString::qString(&v6, "%s : %u ", v4, LODWORD(i_data_p->i_user_data));
    UFG::qPrintf("Dlg Trc: %s : %s\n", "remove_interruption_point", *(const char **)(v5 + 24));
    UFG::qString::~qString(&v6);
  }
  UFG::ConversationElement::RemoveInterruptPoint((UFG::ConversationElement *)i_obj_p[8].vfptr, i_data_p->i_user_data);
}

// File Line: 1606
// RVA: 0x508990
void __fastcall UFG::TSScriptedDialogueElement::Mthd_set_interjection_point(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  HIDWORD(i_obj_p[8].vfptr[1].get_obj_type) = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 1617
// RVA: 0x50C2D0
void __fastcall UFG::TSScriptedDialogueElement::Mthd_stop_after_play(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  BYTE4(i_obj_p[8].vfptr[2].as_instance) ^= (BYTE4(i_obj_p[8].vfptr[2].as_instance) ^ ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0)) & 1;
}

// File Line: 1628
// RVA: 0x50A320
void __fastcall UFG::TSScriptedDialogueElement::Mthd_set_resume_checkpoint(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  BYTE4(i_obj_p[8].vfptr[2].as_instance) ^= (BYTE4(i_obj_p[8].vfptr[2].as_instance) ^ (16
                                                                                     * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0))) & 0x10;
}

// File Line: 1639
// RVA: 0x509370
void __fastcall UFG::TSScriptedDialogueElement::Mthd_set_playback_event(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::ScriptedConversationElement::SetPlaybackEvent(
    (UFG::ScriptedConversationElement *)i_obj_p[8].vfptr,
    *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1649
// RVA: 0x503F40
void __fastcall UFG::TSScriptedDialogueElement::Mthd_kill_on_interrupt(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  BYTE4(i_obj_p[8].vfptr[2].as_instance) ^= (BYTE4(i_obj_p[8].vfptr[2].as_instance) ^ (2
                                                                                     * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0))) & 2;
}

// File Line: 1660
// RVA: 0x508A60
void __fastcall UFG::TSScriptedDialogueElement::Mthd_set_is_highest_priority(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  BYTE4(i_obj_p[8].vfptr[2].as_instance) ^= (BYTE4(i_obj_p[8].vfptr[2].as_instance) ^ (8
                                                                                     * ((*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0))) & 8;
}

// File Line: 1670
// RVA: 0x505E10
void __fastcall UFG::TSScriptedDialogueElement::Mthd_play_from_position(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  UFG::ScriptedConversationElement::CreateNonCharacterContainer(
    (UFG::ScriptedConversationElement *)i_obj_p[8].vfptr,
    (UFG::qVector3 *)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1680
// RVA: 0x4DEB50
bool __fastcall UFG::TSScriptedDialogueElement::Coro_wait_on_interruption_point(SSInvokedCoroutine *pScope)
{
  SSObjectBase *i_obj_p; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  return UFG::ConversationElement::InterruptPointReached(
           (UFG::ConversationElement *)i_obj_p[8].vfptr,
           (*pScope->i_data.i_array_p)->i_data_p->i_user_data);
}

// File Line: 1691
// RVA: 0x4E16F0
UFG::qBaseNodeRB *__fastcall UFG::TSScriptedDialogueElement::GetSimObjectFromSymbol(SSInstance *instance)
{
  SSActor *v3; // rax

  if ( instance->vfptr->is_actor(instance) )
    return *(UFG::qBaseNodeRB **)&instance[4].i_ref_count;
  if ( instance->i_class_p != SSBrain::c_symbol_class_p )
    return 0i64;
  v3 = SSActor::find((ASymbol *)&instance->i_user_data);
  if ( v3 )
    return *(UFG::qBaseNodeRB **)&v3[1].i_icoroutines_to_update.i_count;
  else
    return UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)&instance->i_user_data);
}

