// File Line: 21
// RVA: 0x62EFA0
char __fastcall UFG::UIItem::handleMessage(UFG::UIItem *this, UFG::UIMessage *msg)
{
  unsigned int v2; // eax
  UFG::UIScreen *v4; // rax
  unsigned int v5; // er8

  v2 = msg->m_messageId;
  if ( v2 != UI_HASH_BUTTON_ACCEPT_PRESSED_30 && v2 != UI_HASH_DIALOG_YES_30 )
    return 0;
  v4 = this->m_owner;
  v5 = -1;
  if ( v4 )
    v5 = v4->mScreenUID;
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    this->m_activationMessage,
    v5);
  return 1;
}

