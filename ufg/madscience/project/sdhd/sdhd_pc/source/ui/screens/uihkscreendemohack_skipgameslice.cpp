// File Line: 23
// RVA: 0x5C4F60
void __fastcall UFG::UIHKScreenDemoHack_SkipGameslice::UIHKScreenDemoHack_SkipGameslice(UFG::UIHKScreenDemoHack_SkipGameslice *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDemoHack_SkipGameslice::`vftable;
  this->mState = 0;
}

// File Line: 34
// RVA: 0x630730
void __fastcall UFG::UIHKScreenDemoHack_SkipGameslice::init(UFG::UIHKScreenDemoHack_SkipGameslice *this, UFG::UICommandData *data)
{
  this->mState = 1;
}

// File Line: 40
// RVA: 0x63CAC0
void __fastcall UFG::UIHKScreenDemoHack_SkipGameslice::update(UFG::UIHKScreenDemoHack_SkipGameslice *this, float elapsed)
{
  UFG::UIHKScreenDemoHack_SkipGameslice *v2; // rbx
  UFG::GameState *v3; // rax

  v2 = this;
  if ( this->mState == 1 )
  {
    if ( !(unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateLoadGame_13) )
    {
      v3 = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, uidGameStateLoadGame_13);
      if ( v3 )
        UFG::qString::Set(&v3->mGameStateUserDataStr, UFG::UIHKScreenDemoHack_SkipGameslice::gGameSliceName);
    }
    v2->mState = 2;
  }
  UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
}

