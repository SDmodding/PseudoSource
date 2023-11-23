// File Line: 293
// RVA: 0xA236C0
void __fastcall UFG::UIMessageScreenPushed::UIMessageScreenPushed(
        UFG::UIMessageScreenPushed *this,
        const char *screenName,
        unsigned int screenID)
{
  this->mPrev = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->mNext = &this->UFG::qNode<UFG::UICommand,UFG::UICommand>;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable;
  this->m_commandType = UICOMMAND_UNKNOWN;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessage::`vftable;
  this->m_messageId = UI_HASH_SCREEN_PUSHED_35;
  this->m_resultId = 0;
  *(_QWORD *)&this->m_receiverUID = -1i64;
  this->m_commandType = UICOMMAND_MESSAGE;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessageScreenPushed::`vftable;
  UFG::qString::qString(&this->m_screenName, screenName);
  this->m_screenID = screenID;
}

