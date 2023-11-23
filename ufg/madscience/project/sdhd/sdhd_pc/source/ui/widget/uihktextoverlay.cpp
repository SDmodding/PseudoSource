// File Line: 37
// RVA: 0x5CE4E0
void __fastcall UFG::UISubtitleMessageQueue::~UISubtitleMessageQueue(UFG::UISubtitleMessageQueue *this)
{
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *mPrev; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *mNext; // rax

  UFG::UISubtitleMessageQueue::Clear(this);
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&this->mQueue);
  mPrev = this->mQueue.mNode.mPrev;
  mNext = this->mQueue.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mQueue.mNode.mPrev = &this->mQueue.mNode;
  this->mQueue.mNode.mNext = &this->mQueue.mNode;
}

// File Line: 51
// RVA: 0x5D5310
void __fastcall UFG::UISubtitleMessageQueue::Clear(UFG::UISubtitleMessageQueue *this)
{
  UFG::UISubtitleMessage *mCurrent1; // rbx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *mPrev; // rdx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *mNext; // rax
  UFG::UISubtitleMessage *mCurrent2; // rbx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v6; // rdx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v7; // rax

  mCurrent1 = this->mCurrent1;
  if ( mCurrent1 )
  {
    UFG::qString::~qString(&mCurrent1->mText);
    UFG::qString::~qString(&mCurrent1->mIcon);
    UFG::qString::~qString(&mCurrent1->title);
    UFG::qString::~qString(&mCurrent1->color);
    mPrev = mCurrent1->mPrev;
    mNext = mCurrent1->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    mCurrent1->mPrev = mCurrent1;
    mCurrent1->mNext = mCurrent1;
    operator delete[](mCurrent1);
  }
  this->mCurrent1 = 0i64;
  mCurrent2 = this->mCurrent2;
  if ( mCurrent2 )
  {
    UFG::qString::~qString(&mCurrent2->mText);
    UFG::qString::~qString(&mCurrent2->mIcon);
    UFG::qString::~qString(&mCurrent2->title);
    UFG::qString::~qString(&mCurrent2->color);
    v6 = mCurrent2->mPrev;
    v7 = mCurrent2->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    mCurrent2->mPrev = mCurrent2;
    mCurrent2->mNext = mCurrent2;
    operator delete[](mCurrent2);
  }
  this->mCurrent2 = 0i64;
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&this->mQueue);
}

// File Line: 63
// RVA: 0x619B60
void __fastcall UFG::UISubtitleMessageQueue::Update(UFG::UISubtitleMessageQueue *this, float elapsed)
{
  if ( !this->mPauseQueue )
  {
    UFG::UISubtitleMessageQueue::UpdateSubtitle(this, &this->mCurrent1, 1, elapsed);
    if ( this->mUsesSecondSubtitle )
      UFG::UISubtitleMessageQueue::UpdateSubtitle(this, &this->mCurrent2, 2, elapsed);
  }
}

// File Line: 76
// RVA: 0x61D590
void __fastcall UFG::UISubtitleMessageQueue::UpdateSubtitle(
        UFG::UISubtitleMessageQueue *this,
        UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> **ppMsg,
        int subtitleId,
        float elapsed)
{
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v4; // rbx
  float v8; // xmm6_4
  bool v9; // cf
  UFG::UIHKTextOverlay *mParent; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *mNext; // rdx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *mPrev; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v13; // rax

  v4 = *ppMsg;
  if ( *ppMsg )
  {
    if ( LODWORD(v4[7].mNext) == 3 || (float)(*(float *)&v4[1].mNext + 10.0) < *((float *)&v4[1].mNext + 1) )
    {
      UFG::UISubtitleMessage::`scalar deleting destructor((UFG::UISubtitleMessage *)v4, 1);
      *ppMsg = 0i64;
    }
    v8 = elapsed + *((float *)&v4[1].mNext + 1);
    v9 = v8 < *(float *)&v4[1].mNext;
    *((float *)&v4[1].mNext + 1) = v8;
    if ( !v9 && LODWORD(v4[7].mNext) == 1 )
    {
      LODWORD(v4[7].mNext) = 2;
      mParent = this->mParent;
      if ( mParent )
        UFG::UIHKTextOverlay::OnStartFadeOut(mParent, (UFG::UISubtitleMessage *)v4, subtitleId);
    }
  }
  else if ( (UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *)this->mQueue.mNode.mNext != &this->mQueue )
  {
    mNext = this->mQueue.mNode.mNext;
    mPrev = mNext->mPrev;
    v13 = mNext->mNext;
    mPrev->mNext = v13;
    v13->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    *ppMsg = mNext;
    LODWORD(mNext[7].mNext) = 0;
    UFG::UIHKTextOverlay::OnStartFadeIn(this->mParent, (UFG::UISubtitleMessage *)mNext, subtitleId);
  }
}

// File Line: 117
// RVA: 0x611EA0
void __fastcall UFG::UISubtitleMessageQueue::StartFadeOut(UFG::UISubtitleMessageQueue *this)
{
  UFG::UISubtitleMessage *mCurrent1; // rdx
  UFG::UIHKTextOverlay *mParent; // rcx

  mCurrent1 = this->mCurrent1;
  if ( mCurrent1 && mCurrent1->state <= (unsigned int)STATE_QUEUED )
  {
    mCurrent1->state = STATE_WAITING;
    mParent = this->mParent;
    if ( mParent )
      UFG::UIHKTextOverlay::OnStartFadeOut(mParent, mCurrent1, 1);
  }
}

// File Line: 198
// RVA: 0x5F04F0
void __fastcall UFG::UISubtitleMessageQueue::Kill(UFG::UISubtitleMessageQueue *this, unsigned int id)
{
  UFG::UISubtitleMessage *mCurrent1; // rdx
  UFG::UIHKTextOverlay *mParent; // rcx
  UFG::UISubtitleMessage *mCurrent2; // rdx
  UFG::UIHKTextOverlay *v7; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *i; // rbx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *mPrev; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *mNext; // rax
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v11; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v12; // rax

  mCurrent1 = this->mCurrent1;
  if ( mCurrent1 )
  {
    if ( mCurrent1->id == id && mCurrent1->state <= (unsigned int)STATE_QUEUED )
    {
      mCurrent1->state = STATE_WAITING;
      mParent = this->mParent;
      if ( mParent )
        UFG::UIHKTextOverlay::OnStartFadeOut(mParent, mCurrent1, 1);
    }
  }
  mCurrent2 = this->mCurrent2;
  if ( mCurrent2 )
  {
    if ( mCurrent2->id == id && mCurrent2->state <= (unsigned int)STATE_QUEUED )
    {
      mCurrent2->state = STATE_WAITING;
      v7 = this->mParent;
      if ( v7 )
        UFG::UIHKTextOverlay::OnStartFadeOut(v7, mCurrent2, 2);
    }
  }
  for ( i = this->mQueue.mNode.mNext;
        i != (UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *)&this->mQueue;
        i = i->mNext )
  {
    if ( i && LODWORD(i[1].mPrev) == id )
    {
      mPrev = i->mPrev;
      mNext = i->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      i->mPrev = i;
      i->mNext = i;
      UFG::qString::~qString((UFG::qString *)&i[10].mNext);
      UFG::qString::~qString((UFG::qString *)&i[8]);
      UFG::qString::~qString((UFG::qString *)&i[5]);
      UFG::qString::~qString((UFG::qString *)&i[2].mNext);
      v11 = i->mPrev;
      v12 = i->mNext;
      v11->mNext = v12;
      v12->mPrev = v11;
      i->mPrev = i;
      i->mNext = i;
      operator delete[](i);
      return;
    }
  }
}

// File Line: 259
// RVA: 0x5D5EE0
void __fastcall UFG::UISubtitleMessageQueue::CutShort(UFG::UISubtitleMessageQueue *this, bool fadeOut)
{
  UFG::UISubtitleMessage *mCurrent1; // rdx
  UFG::UIHKTextOverlay *mParent; // rcx
  UFG::UISubtitleMessage *mCurrent2; // rdx
  UFG::UIHKTextOverlay *v7; // rcx
  UFG::UIHKTextOverlay *v8; // rcx
  UFG::UISubtitleMessage *v9; // rdx
  UFG::UIHKTextOverlay *v10; // rcx

  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&this->mQueue);
  mCurrent1 = this->mCurrent1;
  if ( fadeOut )
  {
    if ( mCurrent1 )
    {
      if ( mCurrent1->state <= (unsigned int)STATE_QUEUED )
      {
        mCurrent1->state = STATE_WAITING;
        mParent = this->mParent;
        if ( mParent )
          UFG::UIHKTextOverlay::OnStartFadeOut(mParent, mCurrent1, 1);
      }
    }
    mCurrent2 = this->mCurrent2;
    if ( mCurrent2 && mCurrent2->state <= (unsigned int)STATE_QUEUED )
    {
      mCurrent2->state = STATE_WAITING;
      v7 = this->mParent;
      if ( v7 )
        UFG::UIHKTextOverlay::OnStartFadeOut(v7, mCurrent2, 2);
    }
  }
  else
  {
    if ( mCurrent1 )
    {
      mCurrent1->state = STATE_EXECUTING;
      v8 = this->mParent;
      if ( v8 )
        UFG::UIHKTextOverlay::OnHideNow(v8, mCurrent1, 1);
    }
    v9 = this->mCurrent2;
    if ( v9 )
    {
      v9->state = STATE_EXECUTING;
      v10 = this->mParent;
      if ( v10 )
        UFG::UIHKTextOverlay::OnHideNow(v10, v9, 2);
    }
  }
}

// File Line: 275
// RVA: 0x5EE7D0
bool __fastcall UFG::UISubtitleMessageQueue::IsPlaying(UFG::UISubtitleMessageQueue *this)
{
  return this->mCurrent1
      || this->mCurrent2
      || (UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *)this->mQueue.mNode.mNext != &this->mQueue;
}

// File Line: 329
// RVA: 0x5C8110
void __fastcall UFG::UIHKTextOverlay::UIHKTextOverlay(UFG::UIHKTextOverlay *this)
{
  this->vfptr = (UFG::UIHKTextOverlayVtbl *)&UFG::UIHKTextOverlay::`vftable;
  *(_WORD *)&this->mChanged = 256;
  this->mScreen = 0i64;
  *(_WORD *)&this->mSubtitleQueue.mUsesSecondSubtitle = 0;
  this->mSubtitleQueue.mParent = 0i64;
  this->mSubtitleQueue.mCurrent1 = 0i64;
  this->mSubtitleQueue.mCurrent2 = 0i64;
  this->mSubtitleQueue.mQueue.mNode.mPrev = &this->mSubtitleQueue.mQueue.mNode;
  this->mSubtitleQueue.mQueue.mNode.mNext = &this->mSubtitleQueue.mQueue.mNode;
  *(_WORD *)&this->mMissionObjQueue.mUsesSecondSubtitle = 0;
  this->mMissionObjQueue.mParent = 0i64;
  this->mMissionObjQueue.mCurrent1 = 0i64;
  this->mMissionObjQueue.mCurrent2 = 0i64;
  this->mMissionObjQueue.mQueue.mNode.mPrev = &this->mMissionObjQueue.mQueue.mNode;
  this->mMissionObjQueue.mQueue.mNode.mNext = &this->mMissionObjQueue.mQueue.mNode;
  *(_WORD *)&this->mFreeTextQueue.mUsesSecondSubtitle = 0;
  this->mFreeTextQueue.mParent = 0i64;
  this->mFreeTextQueue.mCurrent1 = 0i64;
  this->mFreeTextQueue.mCurrent2 = 0i64;
  this->mFreeTextQueue.mQueue.mNode.mPrev = &this->mFreeTextQueue.mQueue.mNode;
  this->mFreeTextQueue.mQueue.mNode.mNext = &this->mFreeTextQueue.mQueue.mNode;
  *(_WORD *)&this->mUnlockItemQueue.mUsesSecondSubtitle = 0;
  this->mUnlockItemQueue.mParent = 0i64;
  this->mUnlockItemQueue.mCurrent1 = 0i64;
  this->mUnlockItemQueue.mCurrent2 = 0i64;
  this->mUnlockItemQueue.mQueue.mNode.mPrev = &this->mUnlockItemQueue.mQueue.mNode;
  this->mUnlockItemQueue.mQueue.mNode.mNext = &this->mUnlockItemQueue.mQueue.mNode;
  this->mMissionComplete = 0i64;
  this->TimeOfDay.mLightingConditions = LIGHTING_INVALID;
  *(_WORD *)&this->mInTransit = 0;
  this->mVehicle.mPrev = &this->mVehicle;
  this->mVehicle.mNext = &this->mVehicle;
  this->mVehicle.m_pPointer = 0i64;
  *(_WORD *)&this->mShowIt = 0;
  this->mSubtitleYOffset = 0.0;
  this->mSubtitleQueue.mParent = this;
  this->mMissionObjQueue.mParent = this;
  this->mFreeTextQueue.mParent = this;
  this->mUnlockItemQueue.mParent = this;
  this->mSubtitleQueue.mUsesSecondSubtitle = 1;
}

// File Line: 343
// RVA: 0x5CD780
void __fastcall UFG::UIHKTextOverlay::~UIHKTextOverlay(UFG::UIHKTextOverlay *this)
{
  UFG::UISubtitleMessage *mMissionComplete; // rbx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *mPrev; // rdx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *mNext; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *p_mVehicle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v10; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v11; // rax
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v12; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v13; // rax
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v14; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v15; // rax
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v16; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v17; // rax

  this->vfptr = (UFG::UIHKTextOverlayVtbl *)&UFG::UIHKTextOverlay::`vftable;
  mMissionComplete = this->mMissionComplete;
  if ( mMissionComplete )
  {
    UFG::qString::~qString(&mMissionComplete->mText);
    UFG::qString::~qString(&mMissionComplete->mIcon);
    UFG::qString::~qString(&mMissionComplete->title);
    UFG::qString::~qString(&mMissionComplete->color);
    mPrev = mMissionComplete->mPrev;
    mNext = mMissionComplete->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    mMissionComplete->mPrev = mMissionComplete;
    mMissionComplete->mNext = mMissionComplete;
    operator delete[](mMissionComplete);
    this->mMissionComplete = 0i64;
  }
  p_mVehicle = &this->mVehicle;
  if ( this->mVehicle.m_pPointer )
  {
    v6 = p_mVehicle->mPrev;
    v7 = this->mVehicle.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_mVehicle->mPrev = p_mVehicle;
    this->mVehicle.mNext = &this->mVehicle;
  }
  this->mVehicle.m_pPointer = 0i64;
  v8 = p_mVehicle->mPrev;
  v9 = this->mVehicle.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mVehicle->mPrev = p_mVehicle;
  this->mVehicle.mNext = &this->mVehicle;
  UFG::UISubtitleMessageQueue::Clear(&this->mUnlockItemQueue);
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&this->mUnlockItemQueue.mQueue);
  v10 = this->mUnlockItemQueue.mQueue.mNode.mPrev;
  v11 = this->mUnlockItemQueue.mQueue.mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->mUnlockItemQueue.mQueue.mNode.mPrev = &this->mUnlockItemQueue.mQueue.mNode;
  this->mUnlockItemQueue.mQueue.mNode.mNext = &this->mUnlockItemQueue.mQueue.mNode;
  UFG::UISubtitleMessageQueue::Clear(&this->mFreeTextQueue);
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&this->mFreeTextQueue.mQueue);
  v12 = this->mFreeTextQueue.mQueue.mNode.mPrev;
  v13 = this->mFreeTextQueue.mQueue.mNode.mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mFreeTextQueue.mQueue.mNode.mPrev = &this->mFreeTextQueue.mQueue.mNode;
  this->mFreeTextQueue.mQueue.mNode.mNext = &this->mFreeTextQueue.mQueue.mNode;
  UFG::UISubtitleMessageQueue::Clear(&this->mMissionObjQueue);
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&this->mMissionObjQueue.mQueue);
  v14 = this->mMissionObjQueue.mQueue.mNode.mPrev;
  v15 = this->mMissionObjQueue.mQueue.mNode.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  this->mMissionObjQueue.mQueue.mNode.mPrev = &this->mMissionObjQueue.mQueue.mNode;
  this->mMissionObjQueue.mQueue.mNode.mNext = &this->mMissionObjQueue.mQueue.mNode;
  UFG::UISubtitleMessageQueue::Clear(&this->mSubtitleQueue);
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&this->mSubtitleQueue.mQueue);
  v16 = this->mSubtitleQueue.mQueue.mNode.mPrev;
  v17 = this->mSubtitleQueue.mQueue.mNode.mNext;
  v16->mNext = v17;
  v17->mPrev = v16;
  this->mSubtitleQueue.mQueue.mNode.mPrev = &this->mSubtitleQueue.mQueue.mNode;
  this->mSubtitleQueue.mQueue.mNode.mNext = &this->mSubtitleQueue.mQueue.mNode;
}

// File Line: 365
// RVA: 0x620860
UFG::UIHKTextOverlay *__fastcall UFG::UIHKTextOverlay::getInstance()
{
  UFG::UIHKTextOverlay *result; // rax

  result = (UFG::UIHKTextOverlay *)UFG::UIHKScreenGlobalOverlay::mThis;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    return &UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay;
  return result;
}

// File Line: 377
// RVA: 0x640AE0
void __fastcall UFG::UIHKTextOverlay::update(UFG::UIHKTextOverlay *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIScreenRenderable *mRenderable; // rax
  UFG::UISubtitleMessage *mMissionComplete; // rax
  UFG::UISubtitleMessage *v7; // rcx
  UFG::UISubtitleMessage *mCurrent1; // rax
  UFG::UIHKScreenGlobalOverlay *v9; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbp
  unsigned int v11; // ebx
  UFG::UIHKHelpBarWidget *v12; // rbp
  unsigned int v13; // eax
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-268h] BYREF

  if ( screen != this->mScreen )
    this->mScreen = screen;
  if ( screen )
  {
    mRenderable = screen->mRenderable;
    if ( mRenderable )
    {
      if ( mRenderable->m_shouldRender )
      {
        UFG::UISubtitleMessageQueue::Update(&this->mSubtitleQueue, elapsed);
        UFG::UISubtitleMessageQueue::Update(&this->mMissionObjQueue, elapsed);
        UFG::UISubtitleMessageQueue::Update(&this->mFreeTextQueue, elapsed);
        mMissionComplete = this->mMissionComplete;
        if ( mMissionComplete )
        {
          mMissionComplete->age = elapsed + mMissionComplete->age;
          UFG::UISubtitleMessageQueue::Update(&this->mUnlockItemQueue, elapsed);
          v7 = this->mMissionComplete;
          if ( v7->state == STATE_QUEUED )
          {
            mCurrent1 = this->mUnlockItemQueue.mCurrent1;
            if ( (!mCurrent1 || mCurrent1->state == STATE_DONE)
              && (UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *)this->mUnlockItemQueue.mQueue.mNode.mNext == &this->mUnlockItemQueue.mQueue
              && v7->lifetime <= v7->age )
            {
              v7->state = STATE_WAITING;
              UFG::UIHKTextOverlay::OnStartFadeOut(this, this->mMissionComplete, 1);
            }
          }
          else if ( v7->state == STATE_EXECUTING )
          {
            if ( v7 )
              UFG::UISubtitleMessage::`scalar deleting destructor(v7, 1);
            this->mMissionComplete = 0i64;
          }
        }
        if ( this->mShowItChanged )
        {
          this->mShowItChanged = 0;
          v9 = UFG::UIHKScreenGlobalOverlay::mThis;
          if ( this->mShowIt )
          {
            if ( !UFG::UIHKScreenGlobalOverlay::mThis )
              v9 = &gGlobalOverlaySentinel;
            p_HelpBar = &v9->HelpBar;
            v11 = UFG::qStringHash32("TRANSIT", 0xFFFFFFFF);
            UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
            data.id = v11;
            data.priority = PRIORITY_ONE;
            data.alignment = ALIGN_RIGHT;
            *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
            *(_QWORD *)&data.Buttons[4] = 0i64;
            UFG::qString::Set(data.Captions, "$COMMON_WARP");
            UFG::qString::Set(&data.Captions[1], &customCaption);
            UFG::qString::Set(&data.Captions[2], &customCaption);
            UFG::qString::Set(&data.Captions[3], &customCaption);
            UFG::qString::Set(&data.Captions[4], &customCaption);
            UFG::qString::Set(&data.Captions[5], &customCaption);
            memset(data.MessageIds, 0, sizeof(data.MessageIds));
            UFG::UIHKHelpBarWidget::Show(p_HelpBar, &data);
            UFG::qString::~qString(&data.CustomTexturePack);
            `eh vector destructor iterator(
              data.Icons,
              0x28ui64,
              6,
              (void (__fastcall *)(void *))UFG::qString::~qString);
            `eh vector destructor iterator(
              data.Captions,
              0x28ui64,
              6,
              (void (__fastcall *)(void *))UFG::qString::~qString);
          }
          else
          {
            if ( !UFG::UIHKScreenGlobalOverlay::mThis )
              v9 = &gGlobalOverlaySentinel;
            v12 = &v9->HelpBar;
            v13 = UFG::qStringHash32("TRANSIT", 0xFFFFFFFF);
            UFG::UIHKHelpBarWidget::Hide(v12, v13);
          }
        }
        if ( this->mChanged )
        {
          this->mChanged = 0;
          UFG::UIHKTextOverlay::Flash_SetSubtitlesYOffset(this, screen, this->mSubtitleYOffset);
          UFG::UIHKTextOverlay::Flash_SetSubtitlesVisible(this, screen, this->mSubtitlesVisible);
        }
      }
    }
  }
}

// File Line: 463
// RVA: 0x62E5C0
char __fastcall UFG::UIHKTextOverlay::handleMessage(
        UFG::UIHKTextOverlay *this,
        UFG::UIScreen *screen,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UISubtitleMessage *mMissionComplete; // rax
  UFG::UISubtitleMessage *mCurrent1; // rax
  Scaleform::GFx::Movie *pObject; // rcx
  UFG::UISubtitleMessage *mCurrent2; // rax
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::AiDriverComponent *v13; // rax
  UFG::qString v14; // [rsp+30h] [rbp-1h] BYREF
  Scaleform::GFx::Value pargs; // [rsp+58h] [rbp+27h] BYREF

  if ( screen )
  {
    if ( screen != this->mScreen )
      this->mScreen = screen;
    if ( msgId == UI_HASH_FADEOUTCOMPLETE_11 )
    {
      UFG::qString::qString(&v14, (UFG::qString *)&msg[1]);
      if ( (unsigned int)UFG::qStringCompare(v14.mData, "subtitles_1", -1) )
      {
        if ( (unsigned int)UFG::qStringCompare(v14.mData, "subtitles_2", -1) )
        {
          if ( !(unsigned int)UFG::qStringCompare(v14.mData, "mission_obj", -1) )
          {
            mCurrent1 = this->mMissionObjQueue.mCurrent1;
            if ( mCurrent1 )
              mCurrent1->state = STATE_EXECUTING;
            if ( this->mMissionComplete )
            {
              UFG::UISubtitleMessageQueue::Clear(&this->mMissionObjQueue);
              UFG::UIHKTextOverlay::StartMissionComplete(this);
            }
            goto LABEL_23;
          }
          if ( (unsigned int)UFG::qStringCompare(v14.mData, "freetext", -1) )
          {
            if ( (unsigned int)UFG::qStringCompare(v14.mData, "mc_Unlockables", -1) )
            {
              if ( (unsigned int)UFG::qStringCompare(v14.mData, "mc_MissionComplete", -1) )
              {
                UFG::qStringCompare(v14.mData, "mc_SubMissionComplete", -1);
LABEL_23:
                UFG::qString::~qString(&v14);
                return 1;
              }
              mMissionComplete = this->mMissionComplete;
            }
            else
            {
              mMissionComplete = this->mUnlockItemQueue.mCurrent1;
            }
          }
          else
          {
            mMissionComplete = this->mFreeTextQueue.mCurrent1;
          }
        }
        else
        {
          mMissionComplete = this->mSubtitleQueue.mCurrent2;
        }
      }
      else
      {
        mMissionComplete = this->mSubtitleQueue.mCurrent1;
      }
      if ( mMissionComplete )
        mMissionComplete->state = STATE_EXECUTING;
      goto LABEL_23;
    }
    if ( msgId == UI_HASH_FADEINCOMPLETE_11 )
    {
      if ( !msg )
        return 1;
      UFG::qString::qString(&v14, (UFG::qString *)&msg[1]);
      pargs.pObjectInterface = 0i64;
      pargs.Type = VT_String;
      pargs.mValue.pString = v14.mData;
      pObject = screen->mRenderable->m_movie.pObject;
      if ( pObject )
        Scaleform::GFx::Movie::Invoke(pObject, "blinkSubtext", 0i64, &pargs, 1u);
      if ( (unsigned int)UFG::qStringCompare(v14.mData, "subtitles_1", -1) )
      {
        if ( (unsigned int)UFG::qStringCompare(v14.mData, "subtitles_2", -1) )
        {
          if ( (unsigned int)UFG::qStringCompare(v14.mData, "mission_obj", -1) )
          {
            if ( (unsigned int)UFG::qStringCompare(v14.mData, "freetext", -1) )
            {
              if ( (unsigned int)UFG::qStringCompare(v14.mData, "mc_Unlockables", -1) )
              {
                if ( (unsigned int)UFG::qStringCompare(v14.mData, "mc_MissionComplete", -1) )
                {
                  UFG::qStringCompare(v14.mData, "mc_SubMissionComplete", -1);
LABEL_43:
                  if ( (pargs.Type & 0x40) != 0 )
                  {
                    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
                      pargs.pObjectInterface,
                      &pargs,
                      pargs.mValue);
                    pargs.pObjectInterface = 0i64;
                  }
                  pargs.Type = VT_Undefined;
                  UFG::qString::~qString(&v14);
                  return 1;
                }
                mCurrent2 = this->mMissionComplete;
              }
              else
              {
                mCurrent2 = this->mUnlockItemQueue.mCurrent1;
              }
            }
            else
            {
              mCurrent2 = this->mFreeTextQueue.mCurrent1;
            }
          }
          else
          {
            mCurrent2 = this->mMissionObjQueue.mCurrent1;
          }
        }
        else
        {
          mCurrent2 = this->mSubtitleQueue.mCurrent2;
        }
      }
      else
      {
        mCurrent2 = this->mSubtitleQueue.mCurrent1;
      }
      if ( mCurrent2 )
        mCurrent2->state = STATE_QUEUED;
      goto LABEL_43;
    }
    if ( msgId == UI_HASH_GAME_PAUSE_20 )
    {
      if ( this->mSubtitlesVisible )
      {
        *(_WORD *)&this->mChanged = 1;
        this->mSubtitleQueue.mPauseQueue = 1;
      }
    }
    else if ( msgId == UI_HASH_GAME_UNPAUSE_20 && !this->mSubtitlesVisible )
    {
      *(_WORD *)&this->mChanged = 257;
      this->mSubtitleQueue.mPauseQueue = 0;
    }
    if ( this->mInTransit )
    {
      if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
      {
        m_pPointer = (UFG::SimObjectCVBase *)this->mVehicle.m_pPointer;
        if ( m_pPointer )
        {
          v13 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(m_pPointer);
          if ( v13 )
            UFG::AiDriverComponent::WarpToGotoDestination(v13);
        }
        UFG::UIHKTextOverlay::ResetTransitSelectedStopData(this);
      }
      if ( msgId == UI_HASH_EXIT_FROM_TRANSIT_VEHICLE_20 )
        UFG::UIHKTextOverlay::ResetTransitSelectedStopData(this);
    }
  }
  return 0;
}

// File Line: 612
// RVA: 0x6029C0
void __fastcall UFG::UIHKTextOverlay::ResetTransitSelectedStopData(UFG::UIHKTextOverlay *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *p_mVehicle; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax

  p_mVehicle = &this->mVehicle;
  *(_WORD *)&this->mShowIt = 256;
  this->mInTransit = 0;
  if ( this->mVehicle.m_pPointer )
  {
    mPrev = p_mVehicle->mPrev;
    mNext = p_mVehicle->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mVehicle->mPrev = p_mVehicle;
    p_mVehicle->mNext = p_mVehicle;
  }
  p_mVehicle->m_pPointer = 0i64;
}

// File Line: 620
// RVA: 0x5F3570
void __fastcall UFG::UIHKTextOverlay::OnStartFadeOut(
        UFG::UIHKTextOverlay *this,
        UFG::UISubtitleMessage *msg,
        int subtitleSlotId)
{
  UFG::UIScreen *mScreen; // r9
  UFG::UISubtitleMessage::eSUBTITLE_MESSAGE_TYPE type; // ecx
  Scaleform::GFx::Movie *pObject; // rcx
  const char *v6; // rdi
  __int32 v7; // ecx
  Scaleform::GFx::Movie *v8; // rsi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  if ( msg )
  {
    mScreen = this->mScreen;
    if ( mScreen )
    {
      type = msg->type;
      if ( type == TYPE_MISSION_COMPLETE )
      {
        pObject = mScreen->mRenderable->m_movie.pObject;
        if ( pObject )
          Scaleform::GFx::Movie::Invoke(pObject, "hideMissionComplete", 0i64, 0i64, 0);
      }
      else
      {
        v6 = 0i64;
        if ( type )
        {
          v7 = type - 1;
          if ( v7 )
          {
            if ( v7 == 2 )
              v6 = "mc_Unlockables";
          }
          else
          {
            v6 = "freetext";
          }
        }
        else if ( subtitleSlotId == 1 )
        {
          v6 = "subtitles_1";
        }
        else
        {
          v6 = "subtitles_2";
          if ( subtitleSlotId != 2 )
            v6 = 0i64;
        }
        v8 = mScreen->mRenderable->m_movie.pObject;
        if ( v8 )
        {
          pargs.pObjectInterface = 0i64;
          pargs.Type = VT_String;
          pargs.mValue.pString = v6;
          Scaleform::GFx::Movie::Invoke(v8, "fadeOutSubtext", 0i64, &pargs, 1u);
          if ( (pargs.Type & 0x40) != 0 )
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
              pargs.pObjectInterface,
              &pargs,
              pargs.mValue);
        }
      }
    }
  }
}

// File Line: 673
// RVA: 0x5F31A0
void __fastcall UFG::UIHKTextOverlay::OnStartFadeIn(
        UFG::UIHKTextOverlay *this,
        UFG::UISubtitleMessage *msg,
        int subtitleSlotId)
{
  UFG::UIScreen *mScreen; // rax
  Scaleform::GFx::Movie *pObject; // rsi
  unsigned int mTagHash; // edi
  char *mData; // rcx
  UFG::qString *v9; // rax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v11; // rax
  char *v12; // rdi
  double xPos; // xmm6_8
  double yPos; // xmm6_8
  char *v15; // rdi
  char *v16; // rdi
  const char *v17; // rdi
  UFG::UISubtitleMessage::eSUBTITLE_MESSAGE_TYPE type; // ecx
  __int32 v19; // ecx
  __int32 v20; // ecx
  char *v21; // rbx
  const char *v22; // rdx
  Scaleform::GFx::Value result; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qString ptr; // [rsp+60h] [rbp-88h] BYREF
  __int64 v25; // [rsp+88h] [rbp-60h]
  int v26; // [rsp+90h] [rbp-58h]
  char *v27; // [rsp+98h] [rbp-50h]
  char v28[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v29; // [rsp+B8h] [rbp-30h]
  int v30; // [rsp+C0h] [rbp-28h]
  double v31; // [rsp+C8h] [rbp-20h]
  char v32[16]; // [rsp+D8h] [rbp-10h] BYREF
  __int64 v33; // [rsp+E8h] [rbp+0h]
  int v34; // [rsp+F0h] [rbp+8h]
  double v35; // [rsp+F8h] [rbp+10h]
  char v36[16]; // [rsp+108h] [rbp+20h] BYREF
  __int64 v37; // [rsp+118h] [rbp+30h]
  int v38; // [rsp+120h] [rbp+38h]
  char *v39; // [rsp+128h] [rbp+40h]
  char v40[16]; // [rsp+138h] [rbp+50h] BYREF
  __int64 v41; // [rsp+148h] [rbp+60h]
  int v42; // [rsp+150h] [rbp+68h]
  char *v43; // [rsp+158h] [rbp+70h]
  __int64 v44; // [rsp+168h] [rbp+80h]
  UFG::qString v45; // [rsp+170h] [rbp+88h] BYREF

  if ( msg )
  {
    v44 = -2i64;
    mScreen = this->mScreen;
    if ( mScreen )
    {
      pObject = mScreen->mRenderable->m_movie.pObject;
      if ( pObject )
      {
        mTagHash = msg->mTagHash;
        if ( !mTagHash )
        {
          UFG::qString::qString(&ptr, msg->mText.mData);
          mData = ptr.mData;
          if ( *ptr.mData == 36 )
          {
            v9 = UFG::qString::Substring(&ptr, (UFG::qString *)&result, 1, -1);
            UFG::qString::Set(&ptr, v9->mData, v9->mLength, 0i64, 0);
            UFG::qString::~qString((UFG::qString *)&result);
            mData = ptr.mData;
          }
          mTagHash = HIDWORD(ptr.mNext);
          if ( HIDWORD(ptr.mNext) == -1 )
          {
            mTagHash = UFG::qStringHashUpper32(mData, -1);
            HIDWORD(ptr.mNext) = mTagHash;
          }
          UFG::qString::~qString(&ptr);
        }
        UFG::qString::qString(&v45);
        m_translator = UFG::UIScreenManager::s_instance->m_translator;
        if ( m_translator )
        {
          v11 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, mTagHash);
          if ( v11 )
            UFG::qString::Set(&v45, v11);
        }
        `eh vector constructor iterator(
          &ptr.mData,
          0x30ui64,
          5,
          (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        v12 = msg->mText.mData;
        if ( (v26 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char **, char *))(*(_QWORD *)v25 + 16i64))(v25, &ptr.mData, v27);
          v25 = 0i64;
        }
        v26 = 6;
        v27 = v12;
        xPos = msg->xPos;
        if ( (v30 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v29 + 16i64))(
            v29,
            v28,
            COERCE_DOUBLE(*(_QWORD *)&v31));
          v29 = 0i64;
        }
        v30 = 5;
        v31 = xPos;
        yPos = msg->yPos;
        if ( (v34 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v33 + 16i64))(
            v33,
            v32,
            COERCE_DOUBLE(*(_QWORD *)&v35));
          v33 = 0i64;
        }
        v34 = 5;
        v35 = yPos;
        v15 = msg->color.mData;
        if ( (v38 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v37 + 16i64))(v37, v36, v39);
          v37 = 0i64;
        }
        v38 = 6;
        v39 = v15;
        v16 = msg->mIcon.mData;
        if ( (v42 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v41 + 16i64))(v41, v40, v43);
          v41 = 0i64;
        }
        v42 = 6;
        v43 = v16;
        v17 = 0i64;
        type = msg->type;
        if ( type )
        {
          v19 = type - 1;
          if ( v19 )
          {
            v20 = v19 - 1;
            if ( v20 )
            {
              if ( v20 == 1 )
                v17 = "showUnlockable";
            }
            else
            {
              v17 = "showMissionComplete";
              v21 = msg->title.mData;
              if ( (v30 & 0x40) != 0 )
              {
                (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v29 + 16i64))(
                  v29,
                  v28,
                  COERCE_DOUBLE(*(_QWORD *)&v31));
                v29 = 0i64;
              }
              v30 = 6;
              v31 = *(double *)&v21;
            }
          }
          else
          {
            v17 = "showFreeText";
          }
LABEL_40:
          Scaleform::GFx::Movie::Invoke(pObject, v17, 0i64, (Scaleform::GFx::Value *)&ptr.mData, 5u);
          `eh vector destructor iterator(
            &ptr.mData,
            0x30ui64,
            5,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
          UFG::qString::~qString(&v45);
          return;
        }
        result.pObjectInterface = 0i64;
        result.Type = VT_String;
        result.mValue.pString = v45.mData;
        if ( subtitleSlotId == 1 )
        {
          v17 = "showSubtitle_1";
          v22 = "subtitles_1.m_text.dispTxt.htmlText";
        }
        else
        {
          if ( subtitleSlotId != 2 )
          {
LABEL_37:
            if ( (result.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&result.pObjectInterface->vfptr->gap8[8])(
                result.pObjectInterface,
                &result,
                result.mValue);
              result.pObjectInterface = 0i64;
            }
            result.Type = VT_Undefined;
            goto LABEL_40;
          }
          v17 = "showSubtitle_2";
          v22 = "subtitles_2.m_text.dispTxt.htmlText";
        }
        Scaleform::GFx::Movie::SetVariable(pObject, v22, &result, 1i64);
        goto LABEL_37;
      }
    }
  }
}

// File Line: 765
// RVA: 0x5F2DA0
void __fastcall UFG::UIHKTextOverlay::OnHideNow(
        UFG::UIHKTextOverlay *this,
        UFG::UISubtitleMessage *msg,
        int subtitleSlotId)
{
  UFG::UIScreen *mScreen; // rax
  Scaleform::GFx::Movie *pObject; // rbx
  const char *v5; // rdx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  mScreen = this->mScreen;
  if ( mScreen )
  {
    pObject = mScreen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      value.pObjectInterface = 0i64;
      value.Type = VT_String;
      value.mValue.pString = &customCaption;
      v5 = "subtitles_1.m_text.dispTxt.htmlText";
      if ( subtitleSlotId != 1 )
        v5 = "subtitles_2.m_text.dispTxt.htmlText";
      Scaleform::GFx::Movie::SetVariable(pObject, v5, &value, 1i64);
      if ( (value.Type & 0x40) != 0 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
    }
  }
}

// File Line: 791
// RVA: 0x5FEDD0
__int64 __fastcall UFG::UIHKTextOverlay::QueueMessage(UFG::UIHKTextOverlay *this, UFG::UISubtitleMessage *msg)
{
  UFG::UISubtitleMessage::eSUBTITLE_MESSAGE_TYPE type; // ecx
  __int32 v6; // ecx
  __int32 v7; // ecx
  Scaleform::GFx::Movie *pObject; // rdi
  char *mData; // rsi
  char *v10; // rsi
  UFG::UISubtitleMessage *mMissionComplete; // rcx
  UFG::UISubtitleMessageQueue *p_mMissionObjQueue; // rcx
  UFG::UISubtitleMessage *mCurrent1; // rax
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *p_mQueue; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *mPrev; // rax
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-68h] BYREF
  char v17[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v18; // [rsp+80h] [rbp-28h]
  int v19; // [rsp+88h] [rbp-20h]
  char *v20; // [rsp+90h] [rbp-18h]

  if ( !msg || !(unsigned int)UFG::qStringLength(msg->mText.mData) && !msg->mTagHash )
    return 0i64;
  msg->id = UFG::UIHKTextOverlay::gMessageIDCount++;
  type = msg->type;
  if ( type == TYPE_SUBTITLE_TEXT )
  {
    if ( !this->mSubtitlesVisible )
      return msg->id;
    p_mQueue = &this->mSubtitleQueue.mQueue;
LABEL_24:
    mPrev = p_mQueue->mNode.mPrev;
    mPrev->mNext = msg;
    msg->mPrev = mPrev;
    msg->mNext = &p_mQueue->mNode;
    p_mQueue->mNode.mPrev = msg;
    return msg->id;
  }
  v6 = type - 1;
  if ( !v6 )
  {
    p_mQueue = &this->mFreeTextQueue.mQueue;
    goto LABEL_24;
  }
  v7 = v6 - 1;
  if ( !v7 )
  {
    mMissionComplete = this->mMissionComplete;
    if ( mMissionComplete )
      UFG::UISubtitleMessage::`scalar deleting destructor(mMissionComplete, 1);
    this->mMissionComplete = msg;
    msg->state = STATE_DONE;
    p_mMissionObjQueue = &this->mMissionObjQueue;
    mCurrent1 = this->mMissionObjQueue.mCurrent1;
    if ( !mCurrent1 || mCurrent1->state == STATE_DONE )
    {
      UFG::UISubtitleMessageQueue::Clear(p_mMissionObjQueue);
      UFG::UIHKTextOverlay::StartMissionComplete(this);
    }
    else
    {
      UFG::UISubtitleMessageQueue::StartFadeOut(p_mMissionObjQueue);
    }
    return msg->id;
  }
  if ( v7 == 1 )
  {
    pObject = this->mScreen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      mData = msg->mText.mData;
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_String;
      ptr.mValue.pString = mData;
      v10 = msg->mIcon.mData;
      if ( (v19 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v18 + 16i64))(v18, v17, v20);
        v18 = 0i64;
      }
      v19 = 6;
      v20 = v10;
      Scaleform::GFx::Movie::Invoke(pObject, "Rewards_Add", 0i64, &ptr, 2u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      return msg->id;
    }
    return 0i64;
  }
  return msg->id;
}

// File Line: 860
// RVA: 0x610BA0
void __fastcall UFG::UIHKTextOverlay::ShowMessageOnScreen(
        const char *msg,
        float lifetime,
        float x,
        float y,
        UFG::qString *color)
{
  UFG::allocator::free_link *v6; // rax
  UFG::UIHKTextOverlay *p_TextOverlay; // rdi
  UFG::UISubtitleMessage *v8; // rax
  UFG::UISubtitleMessage *v9; // rbx

  v6 = UFG::qMalloc(0xD0ui64, "UISubtitleMessage", 0i64);
  p_TextOverlay = 0i64;
  if ( v6 )
  {
    UFG::UISubtitleMessage::UISubtitleMessage((UFG::UISubtitleMessage *)v6, TYPE_SUBTITLE_TEXT, msg, 0i64);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v9->xPos = x;
  v9->yPos = y;
  v9->lifetime = lifetime;
  UFG::qString::Set(&v9->color, color->mData, color->mLength, 0i64, 0);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    p_TextOverlay = &UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay;
  UFG::UIHKTextOverlay::QueueMessage(p_TextOverlay, v9);
  UFG::qString::~qString(color);
}

// File Line: 872
// RVA: 0x611ED0
void __fastcall UFG::UIHKTextOverlay::StartMissionComplete(UFG::UIHKTextOverlay *this)
{
  UFG::UIScreen *mScreen; // rax
  Scaleform::GFx::Movie *pObject; // rdi
  char *mData; // rsi
  char *v5; // rsi
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h] BYREF
  char v7[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v8; // [rsp+80h] [rbp-28h]
  int v9; // [rsp+88h] [rbp-20h]
  char *v10; // [rsp+90h] [rbp-18h]

  if ( this->mMissionComplete )
  {
    mScreen = this->mScreen;
    if ( mScreen )
    {
      pObject = mScreen->mRenderable->m_movie.pObject;
      if ( pObject )
      {
        `eh vector constructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        mData = this->mMissionComplete->mText.mData;
        if ( (pargs.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            pargs.mValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = VT_String;
        pargs.mValue.pString = mData;
        v5 = this->mMissionComplete->title.mData;
        if ( (v9 & 0x40) != 0 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v8 + 16i64))(v8, v7, v10);
          v8 = 0i64;
        }
        v9 = 6;
        v10 = v5;
        Scaleform::GFx::Movie::Invoke(pObject, "showMissionComplete", 0i64, &pargs, 2u);
        this->mMissionComplete->state = STATE_NONE;
        `eh vector destructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
    }
  }
}

// File Line: 894
// RVA: 0x5ED0F0
void __fastcall UFG::UIHKTextOverlay::HideMissionObjectives(UFG::UIHKTextOverlay *this)
{
  UFG::UISubtitleMessage *mCurrent1; // rdx
  UFG::UIHKTextOverlay *mParent; // rcx
  UFG::UISubtitleMessage *mCurrent2; // rdx
  UFG::UIHKTextOverlay *v5; // rcx

  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&this->mMissionObjQueue.mQueue);
  mCurrent1 = this->mMissionObjQueue.mCurrent1;
  if ( mCurrent1 )
  {
    if ( mCurrent1->state <= (unsigned int)STATE_QUEUED )
    {
      mCurrent1->state = STATE_WAITING;
      mParent = this->mMissionObjQueue.mParent;
      if ( mParent )
        UFG::UIHKTextOverlay::OnStartFadeOut(mParent, mCurrent1, 1);
    }
  }
  mCurrent2 = this->mMissionObjQueue.mCurrent2;
  if ( mCurrent2 && mCurrent2->state <= (unsigned int)STATE_QUEUED )
  {
    mCurrent2->state = STATE_WAITING;
    v5 = this->mMissionObjQueue.mParent;
    if ( v5 )
      UFG::UIHKTextOverlay::OnStartFadeOut(v5, mCurrent2, 2);
  }
}

// File Line: 900
// RVA: 0x6124C0
void __fastcall UFG::UIHKTextOverlay::StopAllSubtitles(UFG::UIHKTextOverlay *this, bool fadeOut)
{
  UFG::UISubtitleMessageQueue::CutShort(&this->mSubtitleQueue, fadeOut);
}

// File Line: 906
// RVA: 0x5F0600
void __fastcall UFG::UIHKTextOverlay::KillSubtitles(UFG::UIHKTextOverlay *this, unsigned int id)
{
  UFG::UISubtitleMessageQueue::Kill(&this->mSubtitleQueue, id);
}

// File Line: 922
// RVA: 0x5D4CA0
void __fastcall UFG::UIHKTextOverlay::ChangeSubtitleLifetime(
        UFG::UIHKTextOverlay *this,
        unsigned int id,
        float newLifetime)
{
  UFG::UISubtitleMessage *mCurrent1; // rax
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *p_mQueue; // rcx

  mCurrent1 = this->mSubtitleQueue.mCurrent1;
  if ( mCurrent1 && mCurrent1->id == id || (mCurrent1 = this->mSubtitleQueue.mCurrent2) != 0i64 && mCurrent1->id == id )
  {
LABEL_10:
    mCurrent1->lifetime = newLifetime;
  }
  else
  {
    mCurrent1 = (UFG::UISubtitleMessage *)this->mSubtitleQueue.mQueue.mNode.mNext;
    p_mQueue = &this->mSubtitleQueue.mQueue;
    while ( mCurrent1 != (UFG::UISubtitleMessage *)p_mQueue )
    {
      if ( mCurrent1 && mCurrent1->id == id )
        goto LABEL_10;
      mCurrent1 = (UFG::UISubtitleMessage *)mCurrent1->mNext;
    }
  }
}

// File Line: 934
// RVA: 0x5E95D0
float __fastcall UFG::UIHKTextOverlay::GetSubtitleAge(UFG::UIHKTextOverlay *this, unsigned int id)
{
  UFG::UISubtitleMessage *mCurrent1; // rax
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *p_mQueue; // rcx

  mCurrent1 = this->mSubtitleQueue.mCurrent1;
  if ( mCurrent1 && mCurrent1->id == id )
    return mCurrent1->age;
  mCurrent1 = this->mSubtitleQueue.mCurrent2;
  if ( mCurrent1 )
  {
    if ( mCurrent1->id == id )
      return mCurrent1->age;
  }
  mCurrent1 = (UFG::UISubtitleMessage *)this->mSubtitleQueue.mQueue.mNode.mNext;
  p_mQueue = &this->mSubtitleQueue.mQueue;
  while ( mCurrent1 != (UFG::UISubtitleMessage *)p_mQueue )
  {
    if ( mCurrent1 && mCurrent1->id == id )
      return mCurrent1->age;
    mCurrent1 = (UFG::UISubtitleMessage *)mCurrent1->mNext;
  }
  return 0.0;
}

// File Line: 954
// RVA: 0x609F70
void __fastcall UFG::UIHKTextOverlay::SetSubtitleYOffset(UFG::UIHKTextOverlay *this, float y_offset)
{
  this->mSubtitleYOffset = y_offset;
  this->mChanged = 1;
}

// File Line: 961
// RVA: 0x5E1040
void __fastcall UFG::UIHKTextOverlay::Flash_SetSubtitlesYOffset(
        UFG::UIHKTextOverlay *this,
        UFG::UIScreen *screen,
        float y_offset)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-50h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_Number;
    value.mValue.NValue = y_offset;
    Scaleform::GFx::Movie::SetVariable(pObject, "subtitles_y_offset", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

// File Line: 974
// RVA: 0x5E0F60
void __fastcall UFG::UIHKTextOverlay::Flash_SetSubtitlesVisible(
        UFG::UIHKTextOverlay *this,
        UFG::UIScreen *screen,
        bool visible)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = visible;
    Scaleform::GFx::Movie::SetVariable(pObject, "subtitles_1._visible", &value, 1i64);
    Scaleform::GFx::Movie::SetVariable(pObject, "subtitles_2._visible", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

