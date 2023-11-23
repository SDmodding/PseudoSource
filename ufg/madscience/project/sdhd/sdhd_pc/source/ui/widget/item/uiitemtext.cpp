// File Line: 90
// RVA: 0x62EFF0
char __fastcall UFG::UIItemText::handleMessage(UFG::UIItemText *this, UFG::UIMessage *msg)
{
  unsigned int m_messageId; // eax
  UFG::qString *v4; // rcx
  UFG::qString *mNext; // rcx
  UFG::qString *v7; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> *mPrev; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_m_options; // rcx
  UFG::UIScreen *m_owner; // rax
  unsigned int mScreenUID; // edi
  UFG::qString *m_selectedOption; // rcx
  UFG::UIScreenManager *v13; // rbx
  unsigned int v14; // eax
  unsigned int m_activationMessage; // edx

  m_messageId = msg->m_messageId;
  if ( m_messageId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 || m_messageId == UI_HASH_DIALOG_YES_30 )
  {
    m_owner = this->m_owner;
    mScreenUID = -1;
    if ( m_owner )
      mScreenUID = m_owner->mScreenUID;
    m_selectedOption = this->m_selectedOption;
    if ( m_selectedOption )
    {
      v13 = UFG::UIScreenManager::s_instance;
      v14 = UFG::qStringHashUpper32(m_selectedOption->mData, -1);
      UFG::UIScreenManagerBase::queueMessage(v13, v14, mScreenUID);
      return 1;
    }
    m_activationMessage = this->m_activationMessage;
    if ( m_activationMessage )
    {
      UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, m_activationMessage, mScreenUID);
      return 1;
    }
  }
  else if ( m_messageId == UI_HASH_DPAD_LEFT_PRESSED_30 || m_messageId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
  {
    v7 = this->m_selectedOption;
    if ( v7 )
    {
      mPrev = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v7->mPrev;
      p_m_options = &this->m_options;
      p_m_options[1].mNode.mPrev = &mPrev->mNode;
      if ( mPrev == p_m_options )
        this->m_selectedOption = (UFG::qString *)p_m_options->mNode.mPrev;
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
      return 1;
    }
  }
  else if ( m_messageId == UI_HASH_DPAD_RIGHT_PRESSED_30 || m_messageId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
  {
    v4 = this->m_selectedOption;
    if ( v4 )
    {
      mNext = (UFG::qString *)v4->mNext;
      this->m_selectedOption = mNext;
      if ( mNext == (UFG::qString *)&this->m_options )
        this->m_selectedOption = (UFG::qString *)this->m_options.mNode.mNext;
      if ( UFG::HudAudio::m_instance )
      {
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

