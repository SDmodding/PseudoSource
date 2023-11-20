// File Line: 23
// RVA: 0x5C71D0
void __fastcall UFG::UIHKScreenSandbox::UIHKScreenSandbox(UFG::UIHKScreenSandbox *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = 0;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSandbox::`vftable;
}

// File Line: 54
// RVA: 0x62AB00
bool __fastcall UFG::UIHKScreenSandbox::handleMessage(UFG::UIHKScreenSandbox *this, unsigned int msgId, UFG::UIMessage *msg)
{
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&this->vfptr, msgId, msg);
}

