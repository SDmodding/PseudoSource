// File Line: 23
// RVA: 0x5C4F60
void __fastcall UFG::UIHKScreenDemoHack_SkipGameslice::UIHKScreenDemoHack_SkipGameslice(
        UFG::UIHKScreenDemoHack_SkipGameslice *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDemoHack_SkipGameslice::`vftable;
  this->mState = STATE_INIT;
}

// File Line: 34
// RVA: 0x630730
void __fastcall UFG::UIHKScreenDemoHack_SkipGameslice::init(
        UFG::UIHKScreenDemoHack_SkipGameslice *this,
        UFG::UICommandData *data)
{
  this->mState = STATE_BRIGHTNESS;
}

// File Line: 40
// RVA: 0x63CAC0
void __fastcall UFG::UIHKScreenDemoHack_SkipGameslice::update(
        UFG::UIHKScreenDemoHack_SkipGameslice *this,
        float elapsed)
{
  UFG::GameState *GameStateObj; // rax

  if ( this->mState == STATE_BRIGHTNESS )
  {
    if ( !(unsigned int)UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateLoadGame_13) )
    {
      GameStateObj = UFG::FlowController::GetGameStateObj(&UFG::gFlowController, uidGameStateLoadGame_13);
      if ( GameStateObj )
        UFG::qString::Set(&GameStateObj->mGameStateUserDataStr, UFG::UIHKScreenDemoHack_SkipGameslice::gGameSliceName);
    }
    this->mState = STATE_VOLUME;
  }
  UFG::UIScreen::update(this, elapsed);
}

