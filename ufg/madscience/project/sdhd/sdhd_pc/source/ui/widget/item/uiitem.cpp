// File Line: 21
// RVA: 0x62EFA0
char __fastcall UFG::UIItem::handleMessage(UFG::UIItem *this, UFG::UIMessage *msg)
{
  unsigned int m_messageId; // eax
  UFG::UIScreen *m_owner; // rax
  unsigned int mScreenUID; // r8d

  m_messageId = msg->m_messageId;
  if ( m_messageId != UI_HASH_BUTTON_ACCEPT_PRESSED_30 && m_messageId != UI_HASH_DIALOG_YES_30 )
    return 0;
  m_owner = this->m_owner;
  mScreenUID = -1;
  if ( m_owner )
    mScreenUID = m_owner->mScreenUID;
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, this->m_activationMessage, mScreenUID);
  return 1;
}

