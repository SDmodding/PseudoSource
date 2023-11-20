// File Line: 26
// RVA: 0x5C5920
void __fastcall UFG::UIHKScreenHints::UIHKScreenHints(UFG::UIHKScreenHints *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable';
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenHints::`vftable';
  UFG::UIHKScreenHints::gAlreadyLoaded = 1;
}

// File Line: 41
// RVA: 0x632030
void __fastcall UFG::UIHKScreenHints::init(UFG::UIHKScreenHints *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenHints *v2; // rbx
  UFG::UIScreenTextureManager *v3; // rax
  Illusion::Target *v4; // rax

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v3 = UFG::UIScreenTextureManager::Instance();
  v4 = UFG::UIScreenTextureManager::GetSharedTarget(v3, 0);
  UFG::UIScreenRenderable::setBuffer(v2->mRenderable, v4);
}

