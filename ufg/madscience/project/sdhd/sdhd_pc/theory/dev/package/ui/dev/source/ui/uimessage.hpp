// File Line: 293
// RVA: 0xA236C0
void __fastcall UFG::UIMessageScreenPushed::UIMessageScreenPushed(UFG::UIMessageScreenPushed *this, const char *screenName, unsigned int screenID)
{
  unsigned int v3; // ebx
  UFG::UIMessageScreenPushed *v4; // rdi
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v5; // rax

  v3 = screenID;
  v4 = this;
  v5 = (UFG::qNode<UFG::UICommand,UFG::UICommand> *)&this->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UICommand::`vftable;
  this->m_commandType = -1;
  this->m_commandData = 0i64;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessage::`vftable;
  this->m_messageId = UI_HASH_SCREEN_PUSHED_35;
  this->m_resultId = 0;
  *(_QWORD *)&this->m_receiverUID = -1i64;
  this->m_commandType = 5;
  this->vfptr = (UFG::UICommandVtbl *)&UFG::UIMessageScreenPushed::`vftable;
  UFG::qString::qString(&this->m_screenName, screenName);
  v4->m_screenID = v3;
}

