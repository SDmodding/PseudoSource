// File Line: 90
// RVA: 0x62EFF0
char __fastcall UFG::UIItemText::handleMessage(UFG::UIItemText *this, UFG::UIMessage *msg)
{
  unsigned int v2; // eax
  UFG::UIItemText *v3; // r8
  UFG::qString *v4; // rcx
  UFG::qString *v5; // rcx
  UFG::qString *v7; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> *v9; // rcx
  UFG::UIScreen *v10; // rax
  unsigned int v11; // edi
  UFG::qString *v12; // rcx
  UFG::UIScreenManager *v13; // rbx
  unsigned int v14; // eax
  unsigned int v15; // edx

  v2 = msg->m_messageId;
  v3 = this;
  if ( v2 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 || v2 == UI_HASH_DIALOG_YES_30 )
  {
    v10 = this->m_owner;
    v11 = -1;
    if ( v10 )
      v11 = v10->mScreenUID;
    v12 = this->m_selectedOption;
    if ( v12 )
    {
      v13 = UFG::UIScreenManager::s_instance;
      v14 = UFG::qStringHashUpper32(v12->mData, 0xFFFFFFFF);
      UFG::UIScreenManagerBase::queueMessage((UFG::UIScreenManagerBase *)&v13->vfptr, v14, v11);
      return 1;
    }
    v15 = v3->m_activationMessage;
    if ( v15 )
    {
      UFG::UIScreenManagerBase::queueMessage(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        v15,
        v11);
      return 1;
    }
  }
  else if ( v2 == UI_HASH_DPAD_LEFT_PRESSED_30 || v2 == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
  {
    v7 = this->m_selectedOption;
    if ( v7 )
    {
      v8 = v7->mPrev;
      v9 = &this->m_options;
      v9[1].mNode.mPrev = v8;
      if ( v8 == (UFG::qNode<UFG::qString,UFG::qString> *)v9 )
        v3->m_selectedOption = (UFG::qString *)v9->mNode.mPrev;
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x4A3D1F6Cu,
          0i64,
          0,
          0i64);
      return 1;
    }
  }
  else if ( v2 == UI_HASH_DPAD_RIGHT_PRESSED_30 || v2 == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
  {
    v4 = this->m_selectedOption;
    if ( v4 )
    {
      v5 = (UFG::qString *)v4->mNext;
      v3->m_selectedOption = v5;
      if ( v5 == (UFG::qString *)&v3->m_options )
        v3->m_selectedOption = (UFG::qString *)v3->m_options.mNode.mNext;
      if ( UFG::HudAudio::m_instance )
      {
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x4A3D1F6Cu,
          0i64,
          0,
          0i64);
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

