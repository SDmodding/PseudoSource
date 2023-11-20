// File Line: 53
// RVA: 0x4D4C60
void UFG::TSPDA::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("PDA");
  SSClass::register_method_func(v0, "lock", UFG::TSPDA::MthdC_lock, 1, 0);
  SSClass::register_method_func(v0, "unlock", UFG::TSPDA::MthdC_unlock, 1, 0);
  SSClass::register_method_func(v0, "is_idle", UFG::TSPDA::MthdC_is_idle, 1, 0);
  SSClass::register_method_func(v0, "show_incoming_phone_call", UFG::TSPDA::MthdC_show_incoming_phone_call, 1, 0);
  SSClass::register_method_func(v0, "show_outgoing_phone_call", UFG::TSPDA::MthdC_show_outgoing_phone_call, 1, 0);
  SSClass::register_method_func(v0, "private_answer_phone_call", UFG::TSPDA::MthdC_private_answer_phone_call, 1, 0);
  SSClass::register_method_func(v0, "end_phone_call", UFG::TSPDA::MthdC_end_phone_call, 1, 0);
  SSClass::register_method_func(v0, "is_phone_answered", UFG::TSPDA::MthdC_is_phone_answered, 1, 0);
  SSClass::register_method_func(v0, "show_text_message", UFG::TSPDA::MthdC_show_text_message, 1, 0);
  SSClass::register_method_func(v0, "show_outgoing_text", UFG::TSPDA::MthdC_show_outgoing_text, 1, 0);
  SSClass::register_method_func(v0, "start_reading_text", UFG::TSPDA::MthdC_start_reading_text, 1, 0);
  SSClass::register_method_func(v0, "start_writing_text", UFG::TSPDA::MthdC_start_writing_text, 1, 0);
  SSClass::register_method_func(v0, "display_text_message", UFG::TSPDA::MthdC_display_text_message, 1, 0);
  SSClass::register_method_func(v0, "dismiss_text_message", UFG::TSPDA::MthdC_dismiss_text_message, 1, 0);
  SSClass::register_method_func(
    v0,
    "get_text_message_dismiss_cause",
    UFG::TSPDA::MthdC_get_text_message_dismiss_cause,
    1,
    0);
  SSClass::register_method_func(v0, "is_last_msg_read", UFG::TSPDA::MthdC_last_msg_read, 1, 0);
  SSClass::register_method_func(v0, "clear_text_messages", UFG::TSPDA::MthdC_clear_text_messages, 1, 0);
  SSClass::register_method_func(v0, "add_contact", UFG::TSPDA::MthdC_add_contact, 1, 0);
  SSClass::register_method_func(v0, "remove_contact", UFG::TSPDA::MthdC_remove_contact, 1, 0);
  SSClass::register_method_func(v0, "is_calling_contact", UFG::TSPDA::MthdC_is_calling_contact, 1, 0);
  SSClass::register_method_func(v0, "is_camera_on", UFG::TSPDA::MthdC_is_camera_on, 1, 0);
  SSClass::register_method_func(v0, "is_photo_success", UFG::TSPDA::MthdC_is_photo_success, 1, 0);
  SSClass::register_method_func(v0, "private_start_photo", UFG::TSPDA::MthdC_private_start_photo, 1, 0);
  SSClass::register_coroutine_func(
    v0,
    "_private_wait_for_photo_taken",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSPDA::Coro_private_wait_for_photo_taken,
    0);
}

// File Line: 93
// RVA: 0x4EACE0
void __fastcall UFG::TSPDA::MthdC_lock(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHK_PDAWidget::Lock();
}

// File Line: 99
// RVA: 0x4F2AE0
void __fastcall UFG::TSPDA::MthdC_unlock(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHK_PDAWidget::Unlock();
}

// File Line: 105
// RVA: 0x4E9550
void __fastcall UFG::TSPDA::MthdC_is_idle(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  bool v3; // di
  UFG::UIHK_PDAWidget *v4; // rax

  v2 = ppResult;
  v3 = 0;
  v4 = UFG::UIHK_PDAWidget::Get();
  if ( v4 )
    v3 = UFG::UIHK_PDAWidget::IsIdle(v4);
  if ( v2 )
    *v2 = (SSInstance *)SSBoolean::pool_new(v3);
}

// File Line: 120
// RVA: 0x4F04B0
void __fastcall UFG::TSPDA::MthdC_show_incoming_phone_call(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSInstance **v3; // rbx
  char v4; // di
  SSInstance *v5; // rsi
  bool v6; // bp
  bool voiceMail; // r14
  UFG::UIHK_PDAWidget *v8; // rcx

  v2 = pScope->i_data.i_array_p;
  v3 = ppResult;
  v4 = 0;
  v5 = (*v2)->i_data_p;
  v6 = v2[1]->i_data_p->i_user_data != 0;
  voiceMail = v2[2]->i_data_p->i_user_data != 0;
  UFG::qPrintf(
    "PDAWidget MthdC_show_incoming_phone_call contactName=%s autoAns=%d voiceMail=%d\n",
    *(_QWORD *)v5->i_user_data,
    v6,
    voiceMail);
  v8 = UFG::UIHK_PDAWidget::Get();
  if ( v8 )
    v4 = UFG::UIHK_PDAWidget::QueueIncomingPhoneCall(v8, *(const char **)v5->i_user_data, 0, v6, voiceMail);
  if ( v3 )
    *v3 = (SSInstance *)SSBoolean::pool_new(v4);
}

// File Line: 139
// RVA: 0x4F05C0
void __fastcall UFG::TSPDA::MthdC_show_outgoing_phone_call(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSInstance **v3; // rbx
  char v4; // di
  SSInstance *v5; // rsi
  bool v6; // bp
  UFG::UIHK_PDAWidget *v7; // rcx

  v2 = pScope->i_data.i_array_p;
  v3 = ppResult;
  v4 = 0;
  v5 = (*v2)->i_data_p;
  v6 = v2[1]->i_data_p->i_user_data != 0;
  UFG::qPrintf("PDAWidget MthdC_show_outgoing_phone_call contactName=%s autoCall=%d\n", *(_QWORD *)v5->i_user_data, v6);
  v7 = UFG::UIHK_PDAWidget::Get();
  if ( v7 )
    v4 = UFG::UIHK_PDAWidget::QueueIncomingPhoneCall(v7, *(const char **)v5->i_user_data, 1, v6, 0);
  if ( v3 )
    *v3 = (SSInstance *)SSBoolean::pool_new(v4);
}

// File Line: 155
// RVA: 0x1536340
__int64 UFG::_dynamic_initializer_for__gSymList__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("List", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSymList, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gSymList__);
}

// File Line: 156
// RVA: 0x1536400
__int64 UFG::_dynamic_initializer_for__gSymSender__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Sender", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSymSender, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gSymSender__);
}

// File Line: 157
// RVA: 0x15363C0
__int64 UFG::_dynamic_initializer_for__gSymPortrait__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Portrait", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSymPortrait, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gSymPortrait__);
}

// File Line: 158
// RVA: 0x1536380
__int64 UFG::_dynamic_initializer_for__gSymMessage__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Message", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSymMessage, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__gSymMessage__);
}

// File Line: 162
// RVA: 0x4F0CA0
void __fastcall UFG::TSPDA::MthdC_show_text_message(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // r12
  char v3; // r13
  SSInstance *v4; // rdi
  char *v5; // rax
  UFG::qSymbol *v6; // rax
  UFG::qPropertySet *v7; // rax
  UFG::qPropertyList *v8; // rax
  UFG::qPropertyList *v9; // r15
  unsigned int v10; // er14
  unsigned int v11; // ebx
  char *v12; // rax
  UFG::qPropertySet *v13; // rsi
  UFG::GameStatTracker *v14; // rax
  UFG::UIHK_PDAWidget *v15; // rbp
  char *v16; // rdi
  char *v17; // rbx
  char *v18; // rax
  UFG::qSymbol result; // [rsp+60h] [rbp+8h]

  v2 = ppResult;
  v3 = 0;
  v4 = (*pScope->i_data.i_array_p)->i_data_p;
  v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v4->i_user_data);
  UFG::qPrintf("PDAWidget MthdC_show_text_message messageSymbol=%s\n", v5);
  v6 = UFG::qSymbol::create_from_string(&result, "default-unlockables-txtmsg-list");
  v7 = UFG::PropertySetManager::GetPropertySet(v6);
  if ( v7 )
  {
    v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(v7, (UFG::qSymbol *)&UFG::gSymList.mUID, DEPTH_RECURSE);
    v9 = v8;
    if ( v8 )
    {
      v10 = v8->mNumElements;
      v11 = 0;
      if ( v10 )
      {
        while ( 1 )
        {
          v12 = UFG::qPropertyList::GetValuePtr(v9, 0x1Au, v11);
          if ( v12 && *(_QWORD *)v12 )
            v13 = (UFG::qPropertySet *)&v12[*(_QWORD *)v12];
          else
            v13 = 0i64;
          if ( v13->mName.mUID == LODWORD(v4->i_user_data) )
          {
            v14 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(v14, Collectible_TxtMsg, (UFG::qSymbol *)&v4->i_user_data, 2);
            v15 = UFG::UIHK_PDAWidget::Get();
            if ( v15 )
              break;
          }
          if ( ++v11 >= v10 )
            goto LABEL_13;
        }
        v16 = PropertyUtils::Get<char const *>(v13, (UFG::qSymbol *)&UFG::gSymPortrait.mUID, DEPTH_RECURSE);
        v17 = PropertyUtils::Get<char const *>(v13, (UFG::qSymbol *)&UFG::gSymMessage.mUID, DEPTH_RECURSE);
        v18 = PropertyUtils::Get<char const *>(v13, (UFG::qSymbol *)&UFG::gSymSender.mUID, DEPTH_RECURSE);
        v3 = UFG::UIHK_PDAWidget::QueueIncomingTextMessage(v15, v18, v17, v16, 0, 0);
      }
    }
  }
LABEL_13:
  if ( v2 )
    *v2 = (SSInstance *)SSBoolean::pool_new(v3);
}

// File Line: 198
// RVA: 0x4E4690
void __fastcall UFG::TSPDA::MthdC_clear_text_messages(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHK_PDATextInboxWidget::ClearMessages();
}

// File Line: 205
// RVA: 0x4EB490
void __fastcall UFG::TSPDA::MthdC_private_answer_phone_call(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  char v3; // di
  UFG::UIHK_PDAWidget *v4; // rax

  v2 = ppResult;
  v3 = 0;
  v4 = UFG::UIHK_PDAWidget::Get();
  if ( v4 )
    v3 = UFG::UIHK_PDAWidget::AnswerPhoneCall(v4);
  if ( v2 )
    *v2 = (SSInstance *)SSBoolean::pool_new(v3);
}

// File Line: 221
// RVA: 0x4E55A0
void __fastcall UFG::TSPDA::MthdC_end_phone_call(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  char v3; // di
  UFG::UIHK_PDAWidget *v4; // rax

  v2 = ppResult;
  v3 = 0;
  v4 = UFG::UIHK_PDAWidget::Get();
  if ( v4 )
    v3 = UFG::UIHK_PDAWidget::EndPhoneCall(v4, 1);
  if ( v2 )
    *v2 = (SSInstance *)SSBoolean::pool_new(v3);
}

// File Line: 240
// RVA: 0x4E96F0
void __fastcall UFG::TSPDA::MthdC_is_phone_answered(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  bool v3; // di
  UFG::UIHK_PDAWidget *v4; // rax

  v2 = ppResult;
  v3 = 0;
  v4 = UFG::UIHK_PDAWidget::Get();
  if ( v4 )
    v3 = UFG::UIHK_PDAWidget::HasAnswered(v4);
  if ( v2 )
    *v2 = (SSInstance *)SSBoolean::pool_new(v3);
}

// File Line: 255
// RVA: 0x4F0660
void __fastcall UFG::TSPDA::MthdC_show_outgoing_text(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  SSInstance **v3; // rbx
  char v4; // di
  SSInstance *v5; // rsi
  SSInstance *v6; // r14
  bool autoAnswer; // bp
  UFG::UIHK_PDAWidget *v8; // rcx

  v2 = pScope->i_data.i_array_p;
  v3 = ppResult;
  v4 = 0;
  v5 = (*v2)->i_data_p;
  v6 = v2[1]->i_data_p;
  autoAnswer = v2[2]->i_data_p->i_user_data != 0;
  UFG::qPrintf(
    "PDAWidget MthdC_show_outgoing_text contactName=%s messageText=%s autoAnswer=%d\n",
    *(_QWORD *)v5->i_user_data,
    *(_QWORD *)v6->i_user_data,
    autoAnswer);
  v8 = UFG::UIHK_PDAWidget::Get();
  if ( v8 )
    v4 = UFG::UIHK_PDAWidget::QueueIncomingTextMessage(
           v8,
           *(const char **)v5->i_user_data,
           *(const char **)v6->i_user_data,
           "Portrait_Smartphone_Outgoing",
           1,
           autoAnswer);
  if ( v3 )
    *v3 = (SSInstance *)SSBoolean::pool_new(v4);
}

// File Line: 274
// RVA: 0x4F25E0
void __fastcall UFG::TSPDA::MthdC_start_reading_text(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  bool v3; // di
  UFG::UIHK_PDAWidget *v4; // rax

  v2 = ppResult;
  v3 = 0;
  v4 = UFG::UIHK_PDAWidget::Get();
  if ( v4 )
    v3 = UFG::UIHK_PDAWidget::StartReadingText(v4);
  if ( v2 )
    *v2 = (SSInstance *)SSBoolean::pool_new(v3);
}

// File Line: 290
// RVA: 0x4F2660
void __fastcall UFG::TSPDA::MthdC_start_writing_text(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  char v3; // di
  UFG::UIHK_PDAWidget *v4; // rax

  v2 = ppResult;
  v3 = 0;
  v4 = UFG::UIHK_PDAWidget::Get();
  if ( v4 )
    v3 = UFG::UIHK_PDAWidget::StartWritingText(v4);
  if ( v2 )
    *v2 = (SSInstance *)SSBoolean::pool_new(v3);
}

// File Line: 306
// RVA: 0x4E4C60
void __fastcall UFG::TSPDA::MthdC_display_text_message(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHK_PDAWidget *v2; // rax

  v2 = UFG::UIHK_PDAWidget::Get();
  if ( v2 )
    UFG::UIHK_PDAWidget::DisplayTextMessage(v2);
}

// File Line: 317
// RVA: 0x4E4C20
void __fastcall UFG::TSPDA::MthdC_dismiss_text_message(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIHK_PDAWidget *v3; // rax

  v2 = ppResult;
  v3 = UFG::UIHK_PDAWidget::Get();
  if ( v3 )
    UFG::UIHK_PDAWidget::DismissTextMessage(v3, DISMISS_CAUSE_SCRIPT);
  if ( v2 )
    *v2 = (SSInstance *)SSBoolean::pool_new(0);
}

// File Line: 333
// RVA: 0x4E89D0
void __fastcall UFG::TSPDA::MthdC_get_text_message_dismiss_cause(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIHK_PDAIncomingTextWidget::eDismissCause v3; // edi
  UFG::UIHK_PDAWidget *v4; // rax

  v2 = ppResult;
  v3 = 0;
  v4 = UFG::UIHK_PDAWidget::Get();
  if ( v4 )
    v3 = UFG::UIHK_PDAWidget::GetDismissCause(v4);
  if ( v2 )
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, (unsigned int)v3);
}

// File Line: 348
// RVA: 0x4E2E50
void __fastcall UFG::TSPDA::MthdC_add_contact(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::ProgressionTracker *v3; // rax
  UFG::qSymbol identifier; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v5; // [rsp+50h] [rbp+18h]

  v2 = pScope;
  v3 = UFG::ProgressionTracker::Instance();
  v5 = &identifier;
  identifier.mUID = (*v2->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::PDATriggerTracker::Add(&v3->mPDATriggerTracker, (__int64)&identifier, 0i64);
}

// File Line: 355
// RVA: 0x4EC1E0
void __fastcall UFG::TSPDA::MthdC_remove_contact(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::ProgressionTracker *v3; // rax
  UFG::qSymbol identifier; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v5; // [rsp+50h] [rbp+18h]

  v2 = pScope;
  v3 = UFG::ProgressionTracker::Instance();
  v5 = &identifier;
  identifier.mUID = (*v2->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::PDATriggerTracker::Remove(&v3->mPDATriggerTracker, (__int64)&identifier);
}

// File Line: 362
// RVA: 0x4E9340
void __fastcall UFG::TSPDA::MthdC_is_calling_contact(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  SSInvokedMethod *v3; // rdi
  UFG::ProgressionTracker *v4; // rax
  bool v5; // al
  UFG::qSymbol identifier; // [rsp+48h] [rbp+10h]
  UFG::qSymbol *v7; // [rsp+50h] [rbp+18h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope;
    v4 = UFG::ProgressionTracker::Instance();
    v7 = &identifier;
    identifier.mUID = (*v3->i_data.i_array_p)->i_data_p->i_user_data;
    v5 = UFG::PDATriggerTracker::IsTriggered(&v4->mPDATriggerTracker, (__int64)&identifier);
    *v2 = (SSInstance *)SSBoolean::pool_new(v5);
  }
}

// File Line: 374
// RVA: 0x4E93B0
void __fastcall UFG::TSPDA::MthdC_is_camera_on(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIScreen *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::UIScreenManagerBase::getOverlay(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "Camera");
    *v2 = (SSInstance *)SSBoolean::pool_new(v3 != 0i64);
  }
}

// File Line: 386
// RVA: 0x4E9740
void __fastcall UFG::TSPDA::MthdC_is_photo_success(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(1);
}

// File Line: 396
// RVA: 0x4EB5E0
void __fastcall UFG::TSPDA::MthdC_private_start_photo(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::TSPDA::gPhotoTaken = 0;
}

// File Line: 402
// RVA: 0x4DCC70
_BOOL8 __fastcall UFG::TSPDA::Coro_private_wait_for_photo_taken(SSInvokedCoroutine *pScope)
{
  return UFG::TSPDA::gPhotoTaken;
}

// File Line: 408
// RVA: 0x4EA520
void __fastcall UFG::TSPDA::MthdC_last_msg_read(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIHK_PDAWidget *v3; // rcx
  bool v4; // al

  v2 = ppResult;
  v3 = UFG::UIHK_PDAWidget::Get();
  v4 = 0;
  if ( v3 )
    v4 = UFG::UIHK_PDAWidget::HasReadTextMessage(v3);
  if ( v2 )
    *v2 = (SSInstance *)SSBoolean::pool_new(v4);
}

