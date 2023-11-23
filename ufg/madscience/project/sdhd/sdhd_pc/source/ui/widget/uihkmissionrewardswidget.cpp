// File Line: 55
// RVA: 0x5C9920
void __fastcall UFG::UIHKMissionRewardsWidget::~UIHKMissionRewardsWidget(UFG::UIHKMissionRewardsWidget *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  char **p_mData; // rdi
  __int64 v4; // rsi
  const char *v5; // rbx
  UFG::UIScreenTextureManager *v6; // rax

  this->vfptr = (UFG::UIHKMissionRewardsWidgetVtbl *)&UFG::UIHKMissionRewardsWidget::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v2, UFG::UIHKMissionRewardsWidget::gTexturePackFilename);
  this->Rewards.vfptr = (UFG::UIHKMissionRewardsFlasherWidgetVtbl *)&UFG::UIHKMissionRewardsFlasherWidget::`vftable;
  p_mData = &UFG::UIHKMissionRewardsFlasherWidget::gTexturePackFilename[0].mData;
  v4 = 4i64;
  do
  {
    v5 = *p_mData;
    v6 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v6, v5);
    p_mData += 5;
    --v4;
  }
  while ( v4 );
  this->Header.vfptr = (UFG::UIHKMissionRewardsHeaderWidgetVtbl *)&UFG::UIHKMissionRewardsHeaderWidget::`vftable;
}

// File Line: 61
// RVA: 0x5EBE40
void __fastcall UFG::UIHKMissionRewardsWidget::HandleScreenInit(
        UFG::UIHKMissionRewardsWidget *this,
        UFG::UIScreen *screen)
{
  UFG::UIScreenTextureManager *v4; // rax

  ((void (__fastcall *)(UFG::UIHKMissionRewardsHeaderWidget *))this->Header.vfptr->HandleScreenInit)(&this->Header);
  this->Rewards.vfptr->HandleScreenInit(&this->Rewards, screen);
  if ( this->mState == (STATE_SYNCED|STATE_WAITING|0x8) )
  {
    this->mRewardsDelay = 0.0;
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v4,
      UFG::UIHKMissionRewardsWidget::gTexturePackFilename,
      DEFAULT_PRIORITY,
      (UFG::qReflectInventoryBase *)UFG::UIHKMissionRewardsWidget::TextureLoadedCallback,
      0i64);
    this->mState = STATE_QUEUED;
    this->mTexturePackTimeout = 5.0;
  }
}

// File Line: 91
// RVA: 0x6150B0
void __fastcall UFG::UIHKMissionRewardsWidget::Update(
        UFG::UIHKMissionRewardsWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  float v5; // xmm1_4
  float v6; // xmm6_4
  float v7; // xmm6_4
  UFG::UIHKMissionRewardsHeaderWidget::eState mState; // eax
  UFG::UIHKMissionRewardsFlasherWidget::eState v9; // eax
  UFG::UIHKMissionRewardsFlasherWidget::eState v10; // eax
  UFG::UIHKMissionRewardsHeaderWidget::eState v11; // eax
  UFG::UIHKMissionRewardsFlasherWidget::eState v12; // eax

  ((void (__fastcall *)(UFG::UIHKMissionRewardsHeaderWidget *))this->Header.vfptr->Update)(&this->Header);
  ((void (__fastcall *)(UFG::UIHKMissionRewardsFlasherWidget *, UFG::UIScreen *))this->Rewards.vfptr->Update)(
    &this->Rewards,
    screen);
  switch ( this->mState )
  {
    case 1:
      v5 = this->mTexturePackTimeout - elapsed;
      this->mTexturePackTimeout = v5;
      if ( v5 <= 0.0 )
        goto $LN21_28;
      break;
    case 2:
      if ( this->mShouldSkipHeader || UFG::UIHKMissionRewardsHeaderWidget::Caption.mLength <= 0 )
      {
        this->mState = 8;
        this->mShouldSkipHeader = 0;
      }
      else
      {
        UFG::UIHKMissionRewardsHeaderWidget::Start(&this->Header, screen);
        this->mState = STATE_EXECUTING;
      }
      break;
    case 5:
      v6 = elapsed + this->mRewardsDelay;
      this->mRewardsDelay = v6;
      if ( v6 > UFG::UIHKMissionRewardsWidget::gRewardsDelay )
        *(_QWORD *)&this->mState = 8i64;
      break;
    case 6:
      v7 = elapsed + this->mRewardsDelay;
      this->mRewardsDelay = v7;
      if ( v7 > UFG::UIHKMissionRewardsWidget::gRewardsDelay )
        *(_QWORD *)&this->mState = 7i64;
      break;
    case 7:
      mState = this->Header.mState;
      if ( mState == (STATE_SYNCED|STATE_WAITING) || mState == STATE_NONE )
      {
        v9 = this->Rewards.mState;
        if ( v9 == (STATE_DONE|STATE_WAITING) || v9 == STATE_NONE )
          this->mState = STATE_DONE|STATE_WAITING|0x8;
      }
      break;
    case 8:
      UFG::UIHKMissionRewardsFlasherWidget::Start(&this->Rewards, screen);
      this->mState = 9;
      break;
    case 9:
      v10 = this->Rewards.mState;
      if ( v10 == (STATE_DONE|STATE_WAITING) || v10 == STATE_NONE )
        this->mState = STATE_EXECUTING|0x8;
      break;
    case 0xB:
      v11 = this->Header.mState;
      if ( v11 == (STATE_SYNCED|STATE_WAITING) || v11 == STATE_NONE )
      {
        v12 = this->Rewards.mState;
        if ( v12 == (STATE_DONE|STATE_WAITING) || v12 == STATE_NONE )
        {
          this->mNeedFaceLevelUp = UFG::UIHKFaceLevelWidget::IsStandingDeltaGonnaCauseLevelUp();
          UFG::UIHKFaceLevelWidget::mShowDelta = 1;
          this->mState = STATE_SYNCED|0x8;
        }
      }
      break;
    case 0xE:
$LN21_28:
      UFG::UIHKMissionRewardsWidget::Exit(this, screen);
      this->mState = STATE_NONE;
      break;
    default:
      return;
  }
}

// File Line: 221
// RVA: 0x5EAC90
bool __fastcall UFG::UIHKMissionRewardsWidget::HandleMessage(
        UFG::UIHKMissionRewardsWidget *this,
        UFG::UIScreen *screen,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  if ( msgId == UI_HASH_REWARDS_COMPLETE_MSG_INTRO_DONE_20
    || msgId == UI_HASH_REWARDS_REWARDS_INTRO_DONE_20
    || msgId == UI_HASH_REWARDS_COMPLETE_MSG_OUTRO_DONE_20
    || msgId == UI_HASH_REWARDS_REWARDS_OUTRO_DONE_20
    || msgId == UI_HASH_FACE_LEVELUP_MSG_INTRO_DONE_20
    || msgId == UI_HASH_FACE_LEVELUP_MSG_OUTRO_DONE_20 )
  {
    ((void (__fastcall *)(UFG::UIHKMissionRewardsHeaderWidget *))this->Header.vfptr->HandleMessage)(&this->Header);
    this->Rewards.vfptr->HandleMessage(&this->Rewards, screen, msgId, msg);
  }
  switch ( this->mState )
  {
    case 3:
      if ( msgId == UI_HASH_WIDGET_LOADED_20 )
      {
        this->Header.vfptr->HandleMessage(&this->Header, screen, msgId, msg);
        this->mState = STATE_SYNCED;
      }
      break;
    case 4:
      if ( msgId == UI_HASH_WIDGET_LOADED_20 )
      {
        this->Header.vfptr->HandleMessage(&this->Header, screen, msgId, msg);
        this->mState = STATE_DONE|STATE_WAITING;
      }
      break;
    case 9:
      if ( msgId == UI_HASH_WIDGET_LOADED_20 )
      {
        this->Rewards.vfptr->HandleMessage(&this->Rewards, screen, msgId, msg);
        this->mState = STATE_EXECUTING|0x8;
      }
      break;
    default:
      if ( this->mState == (STATE_SYNCED|0x8) && msgId == UI_HASH_FACE_BAR_FINISHED_ANIMATING_20 )
      {
        if ( this->mNeedFaceLevelUp )
        {
          this->mNeedFaceLevelUp = 0;
          UFG::UIHKMissionRewardsHeaderWidget::StartFaceLevelUp(&this->Header, screen);
          this->mState = STATE_DONE;
        }
        else
        {
          this->mState = STATE_DONE|STATE_WAITING|0x8;
        }
      }
      break;
  }
  return 0;
}

// File Line: 351
// RVA: 0x5D7790
void __fastcall UFG::UIHKMissionRewardsWidget::Exit(UFG::UIHKMissionRewardsWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx
  UFG::UIScreenTextureManager *v4; // rax

  UFG::UIHKMissionRewardsFlasherWidget::Clear(&this->Rewards);
  UFG::qString::Set(&UFG::UIHKMissionRewardsHeaderWidget::Title, &customCaption);
  UFG::qString::Set(&UFG::UIHKMissionRewardsHeaderWidget::Caption, &customCaption);
  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    Scaleform::GFx::Movie::Invoke(pObject, "MissionRewards_Unload", 0i64, 0i64, 0);
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v4, UFG::UIHKMissionRewardsWidget::gTexturePackFilename);
    UFG::UIHKMissionRewardsWidget::mShowHudXP = 0;
  }
}

// File Line: 378
// RVA: 0x612850
void __fastcall UFG::UIHKMissionRewardsWidget::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHKScreenHud::MissionRewards->mState = STATE_WAITING;
}

