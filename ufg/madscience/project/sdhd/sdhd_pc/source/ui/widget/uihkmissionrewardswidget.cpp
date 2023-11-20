// File Line: 55
// RVA: 0x5C9920
void __fastcall UFG::UIHKMissionRewardsWidget::~UIHKMissionRewardsWidget(UFG::UIHKMissionRewardsWidget *this)
{
  UFG::UIHKMissionRewardsWidget *v1; // r14
  UFG::UIScreenTextureManager *v2; // rax
  const char **v3; // rdi
  signed __int64 v4; // rsi
  const char *v5; // rbx
  UFG::UIScreenTextureManager *v6; // rax

  v1 = this;
  this->vfptr = (UFG::UIHKMissionRewardsWidgetVtbl *)&UFG::UIHKMissionRewardsWidget::`vftable';
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v2, UFG::UIHKMissionRewardsWidget::gTexturePackFilename);
  v1->Rewards.vfptr = (UFG::UIHKMissionRewardsFlasherWidgetVtbl *)&UFG::UIHKMissionRewardsFlasherWidget::`vftable';
  v3 = (const char **)&UFG::UIHKMissionRewardsFlasherWidget::gTexturePackFilename[0].mData;
  v4 = 4i64;
  do
  {
    v5 = *v3;
    v6 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v6, v5);
    v3 += 5;
    --v4;
  }
  while ( v4 );
  v1->Header.vfptr = (UFG::UIHKMissionRewardsHeaderWidgetVtbl *)&UFG::UIHKMissionRewardsHeaderWidget::`vftable';
}

// File Line: 61
// RVA: 0x5EBE40
void __fastcall UFG::UIHKMissionRewardsWidget::HandleScreenInit(UFG::UIHKMissionRewardsWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHKMissionRewardsWidget *v2; // rdi
  UFG::UIScreen *v3; // rbx
  UFG::UIScreenTextureManager *v4; // rax

  v2 = this;
  v3 = screen;
  ((void (__fastcall *)(UFG::UIHKMissionRewardsHeaderWidget *))this->Header.vfptr->HandleScreenInit)(&this->Header);
  v2->Rewards.vfptr->HandleScreenInit(&v2->Rewards, v3);
  if ( v2->mState == 15 )
  {
    v2->mRewardsDelay = 0.0;
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v4,
      UFG::UIHKMissionRewardsWidget::gTexturePackFilename,
      DEFAULT_PRIORITY,
      UFG::UIHKMissionRewardsWidget::TextureLoadedCallback,
      0i64);
    v2->mState = 1;
    v2->mTexturePackTimeout = 5.0;
  }
}

// File Line: 91
// RVA: 0x6150B0
void __fastcall UFG::UIHKMissionRewardsWidget::Update(UFG::UIHKMissionRewardsWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIHKMissionRewardsWidget *v3; // rbx
  UFG::UIScreen *v4; // rsi
  float v5; // xmm1_4
  float v6; // xmm6_4
  float v7; // xmm6_4
  UFG::UIHKMissionRewardsHeaderWidget::eState v8; // eax
  UFG::UIHKMissionRewardsFlasherWidget::eState v9; // eax
  UFG::UIHKMissionRewardsFlasherWidget::eState v10; // eax
  UFG::UIHKMissionRewardsHeaderWidget::eState v11; // eax
  UFG::UIHKMissionRewardsFlasherWidget::eState v12; // eax

  v3 = this;
  v4 = screen;
  ((void (__fastcall *)(UFG::UIHKMissionRewardsHeaderWidget *))this->Header.vfptr->Update)(&this->Header);
  ((void (__fastcall *)(UFG::UIHKMissionRewardsFlasherWidget *, UFG::UIScreen *))v3->Rewards.vfptr->Update)(
    &v3->Rewards,
    v4);
  switch ( v3->mState )
  {
    case 1:
      v5 = v3->mTexturePackTimeout - elapsed;
      v3->mTexturePackTimeout = v5;
      if ( v5 <= 0.0 )
        goto $LN21_28;
      break;
    case 2:
      if ( v3->mShouldSkipHeader || UFG::UIHKMissionRewardsHeaderWidget::Caption.mLength <= 0 )
      {
        v3->mState = 8;
        v3->mShouldSkipHeader = 0;
      }
      else
      {
        UFG::UIHKMissionRewardsHeaderWidget::Start(&v3->Header, v4);
        v3->mState = 3;
      }
      break;
    case 5:
      v6 = elapsed + v3->mRewardsDelay;
      v3->mRewardsDelay = v6;
      if ( v6 > UFG::UIHKMissionRewardsWidget::gRewardsDelay )
        *(_QWORD *)&v3->mState = 8i64;
      break;
    case 6:
      v7 = elapsed + v3->mRewardsDelay;
      v3->mRewardsDelay = v7;
      if ( v7 > UFG::UIHKMissionRewardsWidget::gRewardsDelay )
        *(_QWORD *)&v3->mState = 7i64;
      break;
    case 7:
      v8 = v3->Header.mState;
      if ( v8 == 7 || v8 == STATE_NONE )
      {
        v9 = v3->Rewards.mState;
        if ( v9 == 6 || v9 == STATE_NONE )
          v3->mState = 14;
      }
      break;
    case 8:
      UFG::UIHKMissionRewardsFlasherWidget::Start(&v3->Rewards, v4);
      v3->mState = 9;
      break;
    case 9:
      v10 = v3->Rewards.mState;
      if ( v10 == 6 || v10 == STATE_NONE )
        v3->mState = 11;
      break;
    case 0xB:
      v11 = v3->Header.mState;
      if ( v11 == 7 || v11 == STATE_NONE )
      {
        v12 = v3->Rewards.mState;
        if ( v12 == 6 || v12 == STATE_NONE )
        {
          v3->mNeedFaceLevelUp = UFG::UIHKFaceLevelWidget::IsStandingDeltaGonnaCauseLevelUp() != 0;
          UFG::UIHKFaceLevelWidget::mShowDelta = 1;
          v3->mState = 13;
        }
      }
      break;
    case 0xE:
$LN21_28:
      UFG::UIHKMissionRewardsWidget::Exit(v3, v4);
      v3->mState = 0;
      break;
    default:
      return;
  }
}

// File Line: 221
// RVA: 0x5EAC90
bool __fastcall UFG::UIHKMissionRewardsWidget::HandleMessage(UFG::UIHKMissionRewardsWidget *this, UFG::UIScreen *screen, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v4; // rbp
  unsigned int v5; // ebx
  UFG::UIScreen *v6; // rsi
  UFG::UIHKMissionRewardsWidget *v7; // rdi

  v4 = msg;
  v5 = msgId;
  v6 = screen;
  v7 = this;
  if ( msgId == UI_HASH_REWARDS_COMPLETE_MSG_INTRO_DONE_20
    || msgId == UI_HASH_REWARDS_REWARDS_INTRO_DONE_20
    || msgId == UI_HASH_REWARDS_COMPLETE_MSG_OUTRO_DONE_20
    || msgId == UI_HASH_REWARDS_REWARDS_OUTRO_DONE_20
    || msgId == UI_HASH_FACE_LEVELUP_MSG_INTRO_DONE_20
    || msgId == UI_HASH_FACE_LEVELUP_MSG_OUTRO_DONE_20 )
  {
    ((void (__fastcall *)(UFG::UIHKMissionRewardsHeaderWidget *))this->Header.vfptr->HandleMessage)(&this->Header);
    v7->Rewards.vfptr->HandleMessage(&v7->Rewards, v6, v5, v4);
  }
  switch ( v7->mState )
  {
    case 3:
      if ( v5 == UI_HASH_WIDGET_LOADED_20 )
      {
        v7->Header.vfptr->HandleMessage(&v7->Header, v6, v5, v4);
        v7->mState = 5;
      }
      break;
    case 4:
      if ( v5 == UI_HASH_WIDGET_LOADED_20 )
      {
        v7->Header.vfptr->HandleMessage(&v7->Header, v6, v5, v4);
        v7->mState = 6;
      }
      break;
    case 9:
      if ( v5 == UI_HASH_WIDGET_LOADED_20 )
      {
        v7->Rewards.vfptr->HandleMessage(&v7->Rewards, v6, v5, v4);
        v7->mState = 11;
      }
      break;
    default:
      if ( v7->mState == 13 && v5 == UI_HASH_FACE_BAR_FINISHED_ANIMATING_20 )
      {
        if ( v7->mNeedFaceLevelUp )
        {
          v7->mNeedFaceLevelUp = 0;
          UFG::UIHKMissionRewardsHeaderWidget::StartFaceLevelUp(&v7->Header, v6);
          v7->mState = 4;
        }
        else
        {
          v7->mState = 14;
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
  UFG::UIScreen *v2; // rbx
  Scaleform::GFx::Movie *v3; // rcx
  UFG::UIScreenTextureManager *v4; // rax

  v2 = screen;
  UFG::UIHKMissionRewardsFlasherWidget::Clear(&this->Rewards);
  UFG::qString::Set(&UFG::UIHKMissionRewardsHeaderWidget::Title, &customWorldMapCaption);
  UFG::qString::Set(&UFG::UIHKMissionRewardsHeaderWidget::Caption, &customWorldMapCaption);
  v3 = v2->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    Scaleform::GFx::Movie::Invoke(v3, "MissionRewards_Unload", 0i64, 0i64, 0);
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v4, UFG::UIHKMissionRewardsWidget::gTexturePackFilename);
    UFG::UIHKMissionRewardsWidget::mShowHudXP = 0;
  }
}

// File Line: 378
// RVA: 0x612850
void __fastcall UFG::UIHKMissionRewardsWidget::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHKScreenHud::MissionRewards->mState = 2;
}

