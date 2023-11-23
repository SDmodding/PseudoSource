// File Line: 53
// RVA: 0x4D4C60
void UFG::TSPDA::BindAtomics(void)
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
  ASymbol rebindo; // [rsp+20h] [rbp-18h]
  ASymbol rebindp; // [rsp+20h] [rbp-18h]
  ASymbol rebindq; // [rsp+20h] [rbp-18h]
  ASymbol rebindr; // [rsp+20h] [rbp-18h]
  ASymbol rebinds; // [rsp+20h] [rbp-18h]
  ASymbol rebindt; // [rsp+20h] [rbp-18h]
  ASymbol rebindu; // [rsp+20h] [rbp-18h]
  ASymbol rebindv; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("PDA");
  SSClass::register_method_func(v0, "lock", UFG::TSPDA::MthdC_lock, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "unlock", UFG::TSPDA::MthdC_unlock, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "is_idle", UFG::TSPDA::MthdC_is_idle, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "show_incoming_phone_call", UFG::TSPDA::MthdC_show_incoming_phone_call, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "show_outgoing_phone_call", UFG::TSPDA::MthdC_show_outgoing_phone_call, 1, rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "private_answer_phone_call",
    UFG::TSPDA::MthdC_private_answer_phone_call,
    1,
    rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(v0, "end_phone_call", UFG::TSPDA::MthdC_end_phone_call, 1, rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(v0, "is_phone_answered", UFG::TSPDA::MthdC_is_phone_answered, 1, rebindg);
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(v0, "show_text_message", UFG::TSPDA::MthdC_show_text_message, 1, rebindh);
  LOBYTE(rebindi.i_uid) = 0;
  SSClass::register_method_func(v0, "show_outgoing_text", UFG::TSPDA::MthdC_show_outgoing_text, 1, rebindi);
  LOBYTE(rebindj.i_uid) = 0;
  SSClass::register_method_func(v0, "start_reading_text", UFG::TSPDA::MthdC_start_reading_text, 1, rebindj);
  LOBYTE(rebindk.i_uid) = 0;
  SSClass::register_method_func(v0, "start_writing_text", UFG::TSPDA::MthdC_start_writing_text, 1, rebindk);
  LOBYTE(rebindl.i_uid) = 0;
  SSClass::register_method_func(v0, "display_text_message", UFG::TSPDA::MthdC_display_text_message, 1, rebindl);
  LOBYTE(rebindm.i_uid) = 0;
  SSClass::register_method_func(v0, "dismiss_text_message", UFG::TSPDA::MthdC_dismiss_text_message, 1, rebindm);
  LOBYTE(rebindn.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "get_text_message_dismiss_cause",
    UFG::TSPDA::MthdC_get_text_message_dismiss_cause,
    1,
    rebindn);
  LOBYTE(rebindo.i_uid) = 0;
  SSClass::register_method_func(v0, "is_last_msg_read", UFG::TSPDA::MthdC_last_msg_read, 1, rebindo);
  LOBYTE(rebindp.i_uid) = 0;
  SSClass::register_method_func(v0, "clear_text_messages", UFG::TSPDA::MthdC_clear_text_messages, 1, rebindp);
  LOBYTE(rebindq.i_uid) = 0;
  SSClass::register_method_func(v0, "add_contact", UFG::TSPDA::MthdC_add_contact, 1, rebindq);
  LOBYTE(rebindr.i_uid) = 0;
  SSClass::register_method_func(v0, "remove_contact", UFG::TSPDA::MthdC_remove_contact, 1, rebindr);
  LOBYTE(rebinds.i_uid) = 0;
  SSClass::register_method_func(v0, "is_calling_contact", UFG::TSPDA::MthdC_is_calling_contact, 1, rebinds);
  LOBYTE(rebindt.i_uid) = 0;
  SSClass::register_method_func(v0, "is_camera_on", UFG::TSPDA::MthdC_is_camera_on, 1, rebindt);
  LOBYTE(rebindu.i_uid) = 0;
  SSClass::register_method_func(v0, "is_photo_success", UFG::TSPDA::MthdC_is_photo_success, 1, rebindu);
  LOBYTE(rebindv.i_uid) = 0;
  SSClass::register_method_func(v0, "private_start_photo", UFG::TSPDA::MthdC_private_start_photo, 1, rebindv);
  SSClass::register_coroutine_func(
    v0,
    "_private_wait_for_photo_taken",
    (bool (__fastcall *)(SSInvokedCoroutine *))UFG::TSPDA::Coro_private_wait_for_photo_taken,
    SSBindFlag_instance_no_rebind);
}

// File Line: 93
// RVA: 0x4EACE0
// attributes: thunk
void __fastcall UFG::TSPDA::MthdC_lock(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHK_PDAWidget::Lock();
}

// File Line: 99
// RVA: 0x4F2AE0
// attributes: thunk
void __fastcall UFG::TSPDA::MthdC_unlock(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHK_PDAWidget::Unlock();
}

// File Line: 105
// RVA: 0x4E9550
void __fastcall UFG::TSPDA::MthdC_is_idle(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool IsIdle; // di
  UFG::UIHK_PDAWidget *v4; // rax

  IsIdle = 0;
  v4 = UFG::UIHK_PDAWidget::Get();
  if ( v4 )
    IsIdle = UFG::UIHK_PDAWidget::IsIdle(v4);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(IsIdle);
}

// File Line: 120
// RVA: 0x4F04B0
void __fastcall UFG::TSPDA::MthdC_show_incoming_phone_call(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  char v4; // di
  SSInstance *i_data_p; // rsi
  bool v6; // bp
  bool voiceMail; // r14
  UFG::UIHK_PDAWidget *v8; // rcx

  i_array_p = pScope->i_data.i_array_p;
  v4 = 0;
  i_data_p = (*i_array_p)->i_data_p;
  v6 = i_array_p[1]->i_data_p->i_user_data != 0;
  voiceMail = i_array_p[2]->i_data_p->i_user_data != 0;
  UFG::qPrintf(
    "PDAWidget MthdC_show_incoming_phone_call contactName=%s autoAns=%d voiceMail=%d\n",
    *(const char **)i_data_p->i_user_data,
    v6,
    voiceMail);
  v8 = UFG::UIHK_PDAWidget::Get();
  if ( v8 )
    v4 = UFG::UIHK_PDAWidget::QueueIncomingPhoneCall(v8, *(const char **)i_data_p->i_user_data, 0, v6, voiceMail);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(v4);
}

// File Line: 139
// RVA: 0x4F05C0
void __fastcall UFG::TSPDA::MthdC_show_outgoing_phone_call(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  char v4; // di
  SSInstance *i_data_p; // rsi
  bool v6; // bp
  UFG::UIHK_PDAWidget *v7; // rcx

  i_array_p = pScope->i_data.i_array_p;
  v4 = 0;
  i_data_p = (*i_array_p)->i_data_p;
  v6 = i_array_p[1]->i_data_p->i_user_data != 0;
  UFG::qPrintf(
    "PDAWidget MthdC_show_outgoing_phone_call contactName=%s autoCall=%d\n",
    *(const char **)i_data_p->i_user_data,
    v6);
  v7 = UFG::UIHK_PDAWidget::Get();
  if ( v7 )
    v4 = UFG::UIHK_PDAWidget::QueueIncomingPhoneCall(v7, *(const char **)i_data_p->i_user_data, 1, v6, 0);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(v4);
}

// File Line: 155
// RVA: 0x1536340
__int64 UFG::_dynamic_initializer_for__gSymList__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("List", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSymList, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSymList__);
}

// File Line: 156
// RVA: 0x1536400
__int64 UFG::_dynamic_initializer_for__gSymSender__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Sender", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSymSender, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSymSender__);
}

// File Line: 157
// RVA: 0x15363C0
__int64 UFG::_dynamic_initializer_for__gSymPortrait__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Portrait", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSymPortrait, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSymPortrait__);
}

// File Line: 158
// RVA: 0x1536380
__int64 UFG::_dynamic_initializer_for__gSymMessage__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Message", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::gSymMessage, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSymMessage__);
}

// File Line: 162
// RVA: 0x4F0CA0
void __fastcall UFG::TSPDA::MthdC_show_text_message(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  char v3; // r13
  SSInstance *i_data_p; // rdi
  char *v5; // rax
  UFG::qSymbol *v6; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v8; // rax
  UFG::qPropertyList *v9; // r15
  unsigned int mNumElements; // r14d
  unsigned int v11; // ebx
  char *ValuePtr; // rax
  UFG::qPropertySet *v13; // rsi
  UFG::GameStatTracker *v14; // rax
  UFG::UIHK_PDAWidget *v15; // rbp
  char *v16; // rdi
  char *v17; // rbx
  char *v18; // rax
  UFG::qSymbol result; // [rsp+60h] [rbp+8h] BYREF

  v3 = 0;
  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  v5 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&i_data_p->i_user_data);
  UFG::qPrintf("PDAWidget MthdC_show_text_message messageSymbol=%s\n", v5);
  v6 = UFG::qSymbol::create_from_string(&result, "default-unlockables-txtmsg-list");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v6);
  if ( PropertySet )
  {
    v8 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           PropertySet,
           (UFG::qArray<unsigned long,0> *)&UFG::gSymList,
           DEPTH_RECURSE);
    v9 = v8;
    if ( v8 )
    {
      mNumElements = v8->mNumElements;
      v11 = 0;
      if ( mNumElements )
      {
        while ( 1 )
        {
          ValuePtr = UFG::qPropertyList::GetValuePtr(v9, 0x1Au, v11);
          if ( ValuePtr && *(_QWORD *)ValuePtr )
            v13 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
          else
            v13 = 0i64;
          if ( v13->mName.mUID == LODWORD(i_data_p->i_user_data) )
          {
            v14 = UFG::GameStatTracker::Instance();
            UFG::GameStatTracker::SetStat(v14, Collectible_TxtMsg, (UFG::qSymbol *)&i_data_p->i_user_data, 2);
            v15 = UFG::UIHK_PDAWidget::Get();
            if ( v15 )
              break;
          }
          if ( ++v11 >= mNumElements )
            goto LABEL_13;
        }
        v16 = PropertyUtils::Get<char const *>(v13, (UFG::qArray<unsigned long,0> *)&UFG::gSymPortrait, DEPTH_RECURSE);
        v17 = PropertyUtils::Get<char const *>(v13, (UFG::qArray<unsigned long,0> *)&UFG::gSymMessage, DEPTH_RECURSE);
        v18 = PropertyUtils::Get<char const *>(v13, (UFG::qArray<unsigned long,0> *)&UFG::gSymSender, DEPTH_RECURSE);
        v3 = UFG::UIHK_PDAWidget::QueueIncomingTextMessage(v15, v18, v17, v16, 0, 0);
      }
    }
  }
LABEL_13:
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(v3);
}

// File Line: 198
// RVA: 0x4E4690
// attributes: thunk
void __fastcall UFG::TSPDA::MthdC_clear_text_messages(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHK_PDATextInboxWidget::ClearMessages();
}

// File Line: 205
// RVA: 0x4EB490
void __fastcall UFG::TSPDA::MthdC_private_answer_phone_call(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  char v3; // di
  UFG::UIHK_PDAWidget *v4; // rax

  v3 = 0;
  v4 = UFG::UIHK_PDAWidget::Get();
  if ( v4 )
    v3 = UFG::UIHK_PDAWidget::AnswerPhoneCall(v4);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(v3);
}

// File Line: 221
// RVA: 0x4E55A0
void __fastcall UFG::TSPDA::MthdC_end_phone_call(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  char v3; // di
  UFG::UIHK_PDAWidget *v4; // rax

  v3 = 0;
  v4 = UFG::UIHK_PDAWidget::Get();
  if ( v4 )
    v3 = UFG::UIHK_PDAWidget::EndPhoneCall(v4, 1);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(v3);
}

// File Line: 240
// RVA: 0x4E96F0
void __fastcall UFG::TSPDA::MthdC_is_phone_answered(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool HasAnswered; // di
  UFG::UIHK_PDAWidget *v4; // rax

  HasAnswered = 0;
  v4 = UFG::UIHK_PDAWidget::Get();
  if ( v4 )
    HasAnswered = UFG::UIHK_PDAWidget::HasAnswered(v4);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(HasAnswered);
}

// File Line: 255
// RVA: 0x4F0660
void __fastcall UFG::TSPDA::MthdC_show_outgoing_text(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  char v4; // di
  SSInstance *i_data_p; // rsi
  SSInstance *v6; // r14
  bool autoAnswer; // bp
  UFG::UIHK_PDAWidget *v8; // rcx

  i_array_p = pScope->i_data.i_array_p;
  v4 = 0;
  i_data_p = (*i_array_p)->i_data_p;
  v6 = i_array_p[1]->i_data_p;
  autoAnswer = i_array_p[2]->i_data_p->i_user_data != 0;
  UFG::qPrintf(
    "PDAWidget MthdC_show_outgoing_text contactName=%s messageText=%s autoAnswer=%d\n",
    *(const char **)i_data_p->i_user_data,
    *(const char **)v6->i_user_data,
    autoAnswer);
  v8 = UFG::UIHK_PDAWidget::Get();
  if ( v8 )
    v4 = UFG::UIHK_PDAWidget::QueueIncomingTextMessage(
           v8,
           *(const char **)i_data_p->i_user_data,
           *(const char **)v6->i_user_data,
           "Portrait_Smartphone_Outgoing",
           1,
           autoAnswer);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(v4);
}

// File Line: 274
// RVA: 0x4F25E0
void __fastcall UFG::TSPDA::MthdC_start_reading_text(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool started; // di
  UFG::UIHK_PDAWidget *v4; // rax

  started = 0;
  v4 = UFG::UIHK_PDAWidget::Get();
  if ( v4 )
    started = UFG::UIHK_PDAWidget::StartReadingText(v4);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(started);
}

// File Line: 290
// RVA: 0x4F2660
void __fastcall UFG::TSPDA::MthdC_start_writing_text(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  char started; // di
  UFG::UIHK_PDAWidget *v4; // rax

  started = 0;
  v4 = UFG::UIHK_PDAWidget::Get();
  if ( v4 )
    started = UFG::UIHK_PDAWidget::StartWritingText(v4);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(started);
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
  UFG::UIHK_PDAWidget *v3; // rax

  v3 = UFG::UIHK_PDAWidget::Get();
  if ( v3 )
    UFG::UIHK_PDAWidget::DismissTextMessage(v3, DISMISS_CAUSE_SCRIPT);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(0);
}

// File Line: 333
// RVA: 0x4E89D0
void __fastcall UFG::TSPDA::MthdC_get_text_message_dismiss_cause(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHK_PDAIncomingTextWidget::eDismissCause DismissCause; // edi
  UFG::UIHK_PDAWidget *v4; // rax

  DismissCause = DISMISS_CAUSE_NONE;
  v4 = UFG::UIHK_PDAWidget::Get();
  if ( v4 )
    DismissCause = UFG::UIHK_PDAWidget::GetDismissCause(v4);
  if ( ppResult )
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, (unsigned int)DismissCause);
}

// File Line: 348
// RVA: 0x4E2E50
void __fastcall UFG::TSPDA::MthdC_add_contact(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v3; // rax
  UFG::qSymbol identifier; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_identifier; // [rsp+50h] [rbp+18h]

  v3 = UFG::ProgressionTracker::Instance();
  p_identifier = &identifier;
  identifier.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::PDATriggerTracker::Add(&v3->mPDATriggerTracker, &identifier.mUID, 0i64);
}

// File Line: 355
// RVA: 0x4EC1E0
void __fastcall UFG::TSPDA::MthdC_remove_contact(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v3; // rax
  UFG::qSymbol identifier; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_identifier; // [rsp+50h] [rbp+18h]

  v3 = UFG::ProgressionTracker::Instance();
  p_identifier = &identifier;
  identifier.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  UFG::PDATriggerTracker::Remove(&v3->mPDATriggerTracker, &identifier.mUID);
}

// File Line: 362
// RVA: 0x4E9340
void __fastcall UFG::TSPDA::MthdC_is_calling_contact(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::ProgressionTracker *v4; // rax
  char IsTriggered; // al
  UFG::qSymbol identifier; // [rsp+48h] [rbp+10h] BYREF
  UFG::qSymbol *p_identifier; // [rsp+50h] [rbp+18h]

  if ( ppResult )
  {
    v4 = UFG::ProgressionTracker::Instance();
    p_identifier = &identifier;
    identifier.mUID = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    IsTriggered = UFG::PDATriggerTracker::IsTriggered(&v4->mPDATriggerTracker, &identifier.mUID);
    *ppResult = SSBoolean::pool_new(IsTriggered);
  }
}

// File Line: 374
// RVA: 0x4E93B0
void __fastcall UFG::TSPDA::MthdC_is_camera_on(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreen *Overlay; // rax

  if ( ppResult )
  {
    Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "Camera");
    *ppResult = SSBoolean::pool_new(Overlay != 0i64);
  }
}

// File Line: 386
// RVA: 0x4E9740
void __fastcall UFG::TSPDA::MthdC_is_photo_success(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(1);
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
  UFG::UIHK_PDAWidget *v3; // rcx
  bool TextMessage; // al

  v3 = UFG::UIHK_PDAWidget::Get();
  TextMessage = 0;
  if ( v3 )
    TextMessage = UFG::UIHK_PDAWidget::HasReadTextMessage(v3);
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(TextMessage);
}

