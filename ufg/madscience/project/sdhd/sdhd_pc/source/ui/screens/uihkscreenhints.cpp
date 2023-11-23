// File Line: 26
// RVA: 0x5C5920
void __fastcall UFG::UIHKScreenHints::UIHKScreenHints(UFG::UIHKScreenHints *this)
{
  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = eDIM_INVALID;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenHints::`vftable;
  UFG::UIHKScreenHints::gAlreadyLoaded = 1;
}

// File Line: 41
// RVA: 0x632030
void __fastcall UFG::UIHKScreenHints::init(UFG::UIHKScreenHints *this, UFG::UICommandData *data)
{
  UFG::UIScreenTextureManager *v3; // rax
  Illusion::Target *SharedTarget; // rax

  UFG::UIScreen::init(this, data);
  v3 = UFG::UIScreenTextureManager::Instance();
  SharedTarget = UFG::UIScreenTextureManager::GetSharedTarget(v3, Target_512_256);
  UFG::UIScreenRenderable::setBuffer(this->mRenderable, SharedTarget);
}

