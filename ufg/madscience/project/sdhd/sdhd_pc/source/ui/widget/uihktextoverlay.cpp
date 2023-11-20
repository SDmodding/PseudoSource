// File Line: 37
// RVA: 0x5CE4E0
void __fastcall UFG::UISubtitleMessageQueue::~UISubtitleMessageQueue(UFG::UISubtitleMessageQueue *this)
{
  UFG::UISubtitleMessageQueue *v1; // rbx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v2; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v3; // rax
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *v4; // [rsp+40h] [rbp+8h]

  v1 = this;
  UFG::UISubtitleMessageQueue::Clear(this);
  v4 = &v1->mQueue;
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&v1->mQueue);
  v2 = v1->mQueue.mNode.mPrev;
  v3 = v1->mQueue.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
}

// File Line: 51
// RVA: 0x5D5310
void __fastcall UFG::UISubtitleMessageQueue::Clear(UFG::UISubtitleMessageQueue *this)
{
  UFG::UISubtitleMessageQueue *v1; // rdi
  UFG::UISubtitleMessage *v2; // rbx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v3; // rdx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v4; // rax
  UFG::UISubtitleMessage *v5; // rbx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v6; // rdx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v7; // rax

  v1 = this;
  v2 = this->mCurrent1;
  if ( v2 )
  {
    UFG::qString::~qString(&v2->mText);
    UFG::qString::~qString(&v2->mIcon);
    UFG::qString::~qString(&v2->title);
    UFG::qString::~qString(&v2->color);
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *)&v2->mPrev;
    operator delete[](v2);
  }
  v1->mCurrent1 = 0i64;
  v5 = v1->mCurrent2;
  if ( v5 )
  {
    UFG::qString::~qString(&v5->mText);
    UFG::qString::~qString(&v5->mIcon);
    UFG::qString::~qString(&v5->title);
    UFG::qString::~qString(&v5->color);
    v6 = v5->mPrev;
    v7 = v5->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *)&v5->mPrev;
    operator delete[](v5);
  }
  v1->mCurrent2 = 0i64;
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&v1->mQueue);
}

// File Line: 63
// RVA: 0x619B60
void __fastcall UFG::UISubtitleMessageQueue::Update(UFG::UISubtitleMessageQueue *this, float elapsed)
{
  UFG::UISubtitleMessageQueue *v2; // rbx

  v2 = this;
  if ( !this->mPauseQueue )
  {
    UFG::UISubtitleMessageQueue::UpdateSubtitle(this, &this->mCurrent1, 1, elapsed);
    if ( v2->mUsesSecondSubtitle )
      UFG::UISubtitleMessageQueue::UpdateSubtitle(v2, &v2->mCurrent2, 2, elapsed);
  }
}

// File Line: 76
// RVA: 0x61D590
void __fastcall UFG::UISubtitleMessageQueue::UpdateSubtitle(UFG::UISubtitleMessageQueue *this, UFG::UISubtitleMessage **ppMsg, int subtitleId, float elapsed)
{
  UFG::UISubtitleMessage *v4; // rbx
  int v5; // ebp
  UFG::UISubtitleMessage **v6; // rsi
  UFG::UISubtitleMessageQueue *v7; // rdi
  float v8; // xmm6_4
  bool v9; // cf
  UFG::UIHKTextOverlay *v10; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v11; // rdx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v12; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v13; // rax

  v4 = *ppMsg;
  v5 = subtitleId;
  v6 = ppMsg;
  v7 = this;
  if ( *ppMsg )
  {
    if ( v4->state == 3 || (float)(v4->lifetime + 10.0) < v4->age )
    {
      UFG::UISubtitleMessage::`scalar deleting destructor'(v4, 1);
      *v6 = 0i64;
    }
    v8 = elapsed + v4->age;
    v9 = v8 < v4->lifetime;
    v4->age = v8;
    if ( !v9 && v4->state == 1 )
    {
      v4->state = 2;
      v10 = v7->mParent;
      if ( v10 )
        UFG::UIHKTextOverlay::OnStartFadeOut(v10, v4, v5);
    }
  }
  else if ( (UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *)this->mQueue.mNode.mNext != &this->mQueue )
  {
    v11 = this->mQueue.mNode.mNext;
    v12 = v11->mPrev;
    v13 = v11->mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v11->mPrev = v11;
    v11->mNext = v11;
    *v6 = (UFG::UISubtitleMessage *)v11;
    LODWORD(v11[7].mNext) = 0;
    UFG::UIHKTextOverlay::OnStartFadeIn(v7->mParent, (UFG::UISubtitleMessage *)v11, subtitleId);
  }
}

// File Line: 117
// RVA: 0x611EA0
void __fastcall UFG::UISubtitleMessageQueue::StartFadeOut(UFG::UISubtitleMessageQueue *this)
{
  UFG::UISubtitleMessage *v1; // rdx
  UFG::UIHKTextOverlay *v2; // rcx

  v1 = this->mCurrent1;
  if ( v1 && v1->state <= 1u )
  {
    v1->state = 2;
    v2 = this->mParent;
    if ( v2 )
      UFG::UIHKTextOverlay::OnStartFadeOut(v2, v1, 1);
  }
}

// File Line: 198
// RVA: 0x5F04F0
void __fastcall UFG::UISubtitleMessageQueue::Kill(UFG::UISubtitleMessageQueue *this, unsigned int id)
{
  unsigned int v2; // edi
  UFG::UISubtitleMessageQueue *v3; // rsi
  UFG::UISubtitleMessage *v4; // rdx
  UFG::UIHKTextOverlay *v5; // rcx
  UFG::UISubtitleMessage *v6; // rdx
  UFG::UIHKTextOverlay *v7; // rcx
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *i; // rbx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v9; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v10; // rax
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v11; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v12; // rax

  v2 = id;
  v3 = this;
  v4 = this->mCurrent1;
  if ( v4 )
  {
    if ( v4->id == v2 && v4->state <= 1u )
    {
      v4->state = 2;
      v5 = this->mParent;
      if ( v5 )
        UFG::UIHKTextOverlay::OnStartFadeOut(v5, v4, 1);
    }
  }
  v6 = v3->mCurrent2;
  if ( v6 )
  {
    if ( v6->id == v2 && v6->state <= 1u )
    {
      v6->state = 2;
      v7 = v3->mParent;
      if ( v7 )
        UFG::UIHKTextOverlay::OnStartFadeOut(v7, v6, 2);
    }
  }
  for ( i = (UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *)v3->mQueue.mNode.mNext;
        i != &v3->mQueue;
        i = (UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *)i->mNode.mNext )
  {
    if ( i && LODWORD(i[1].mNode.mPrev) == v2 )
    {
      v9 = i->mNode.mPrev;
      v10 = i->mNode.mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      i->mNode.mPrev = &i->mNode;
      i->mNode.mNext = &i->mNode;
      UFG::qString::~qString((UFG::qString *)&i[10].mNode.mNext);
      UFG::qString::~qString((UFG::qString *)&i[8]);
      UFG::qString::~qString((UFG::qString *)&i[5]);
      UFG::qString::~qString((UFG::qString *)&i[2].mNode.mNext);
      v11 = i->mNode.mPrev;
      v12 = i->mNode.mNext;
      v11->mNext = v12;
      v12->mPrev = v11;
      i->mNode.mPrev = &i->mNode;
      i->mNode.mNext = &i->mNode;
      operator delete[](i);
      return;
    }
  }
}

// File Line: 259
// RVA: 0x5D5EE0
void __fastcall UFG::UISubtitleMessageQueue::CutShort(UFG::UISubtitleMessageQueue *this, bool fadeOut)
{
  UFG::UISubtitleMessageQueue *v2; // rdi
  bool v3; // bl
  UFG::UISubtitleMessage *v4; // rdx
  UFG::UIHKTextOverlay *v5; // rcx
  UFG::UISubtitleMessage *v6; // rdx
  UFG::UIHKTextOverlay *v7; // rcx
  UFG::UIHKTextOverlay *v8; // rcx
  UFG::UISubtitleMessage *v9; // rdx
  UFG::UIHKTextOverlay *v10; // rcx

  v2 = this;
  v3 = fadeOut;
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&this->mQueue);
  v4 = v2->mCurrent1;
  if ( v3 )
  {
    if ( v4 )
    {
      if ( v4->state <= 1u )
      {
        v4->state = 2;
        v5 = v2->mParent;
        if ( v5 )
          UFG::UIHKTextOverlay::OnStartFadeOut(v5, v4, 1);
      }
    }
    v6 = v2->mCurrent2;
    if ( v6 && v6->state <= 1u )
    {
      v6->state = 2;
      v7 = v2->mParent;
      if ( v7 )
        UFG::UIHKTextOverlay::OnStartFadeOut(v7, v6, 2);
    }
  }
  else
  {
    if ( v4 )
    {
      v4->state = 3;
      v8 = v2->mParent;
      if ( v8 )
        UFG::UIHKTextOverlay::OnHideNow(v8, v4, 1);
    }
    v9 = v2->mCurrent2;
    if ( v9 )
    {
      v9->state = 3;
      v10 = v2->mParent;
      if ( v10 )
        UFG::UIHKTextOverlay::OnHideNow(v10, v9, 2);
    }
  }
}

// File Line: 275
// RVA: 0x5EE7D0
bool __fastcall UFG::UISubtitleMessageQueue::IsPlaying(UFG::UISubtitleMessageQueue *this)
{
  return *(_OWORD *)&this->mCurrent1 != 0i64
      || (UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *)this->mQueue.mNode.mNext != &this->mQueue;
}

// File Line: 329
// RVA: 0x5C8110
void __fastcall UFG::UIHKTextOverlay::UIHKTextOverlay(UFG::UIHKTextOverlay *this)
{
  UFG::UISubtitleMessageQueue *v1; // rdx
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *v2; // rax
  UFG::UISubtitleMessageQueue *v3; // rax
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *v4; // rax
  UFG::UISubtitleMessageQueue *v5; // rax
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *v6; // rax
  UFG::UISubtitleMessageQueue *v7; // rax
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *v8; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v9; // rax

  this->vfptr = (UFG::UIHKTextOverlayVtbl *)&UFG::UIHKTextOverlay::`vftable';
  *(_WORD *)&this->mChanged = 256;
  this->mScreen = 0i64;
  v1 = &this->mSubtitleQueue;
  *(_WORD *)&v1->mUsesSecondSubtitle = 0;
  v1->mParent = 0i64;
  v1->mCurrent1 = 0i64;
  v1->mCurrent2 = 0i64;
  v2 = &this->mSubtitleQueue.mQueue;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v3 = &this->mMissionObjQueue;
  *(_WORD *)&v3->mUsesSecondSubtitle = 0;
  v3->mParent = 0i64;
  v3->mCurrent1 = 0i64;
  v3->mCurrent2 = 0i64;
  v4 = &this->mMissionObjQueue.mQueue;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v5 = &this->mFreeTextQueue;
  *(_WORD *)&v5->mUsesSecondSubtitle = 0;
  v5->mParent = 0i64;
  v5->mCurrent1 = 0i64;
  v5->mCurrent2 = 0i64;
  v6 = &this->mFreeTextQueue.mQueue;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  v7 = &this->mUnlockItemQueue;
  *(_WORD *)&v7->mUsesSecondSubtitle = 0;
  v7->mParent = 0i64;
  v7->mCurrent1 = 0i64;
  v7->mCurrent2 = 0i64;
  v8 = &this->mUnlockItemQueue.mQueue;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  this->mMissionComplete = 0i64;
  this->TimeOfDay.mLightingConditions = 0;
  *(_WORD *)&this->mInTransit = 0;
  v9 = &this->mVehicle;
  v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v9->mPrev;
  this->mVehicle.m_pPointer = 0i64;
  *(_WORD *)&this->mShowIt = 0;
  this->mSubtitleYOffset = 0.0;
  this->mSubtitleQueue.mParent = this;
  this->mMissionObjQueue.mParent = this;
  this->mFreeTextQueue.mParent = this;
  this->mUnlockItemQueue.mParent = this;
  v1->mUsesSecondSubtitle = 1;
}

// File Line: 343
// RVA: 0x5CD780
void __fastcall UFG::UIHKTextOverlay::~UIHKTextOverlay(UFG::UIHKTextOverlay *this)
{
  UFG::UIHKTextOverlay *v1; // rdi
  UFG::UISubtitleMessage *v2; // rbx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v3; // rdx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v4; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *v10; // rbx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v11; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v12; // rax
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *v13; // rbx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v14; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v15; // rax
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *v16; // rbx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v17; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v18; // rax
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *v19; // rbx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v20; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v21; // rax

  v1 = this;
  this->vfptr = (UFG::UIHKTextOverlayVtbl *)&UFG::UIHKTextOverlay::`vftable';
  v2 = this->mMissionComplete;
  if ( v2 )
  {
    UFG::qString::~qString(&v2->mText);
    UFG::qString::~qString(&v2->mIcon);
    UFG::qString::~qString(&v2->title);
    UFG::qString::~qString(&v2->color);
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *)&v2->mPrev;
    operator delete[](v2);
    v1->mMissionComplete = 0i64;
  }
  v5 = &v1->mVehicle;
  if ( v1->mVehicle.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->mVehicle.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->mVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mVehicle.mPrev;
  }
  v1->mVehicle.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->mVehicle.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->mVehicle.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mVehicle.mPrev;
  UFG::UISubtitleMessageQueue::Clear(&v1->mUnlockItemQueue);
  v10 = &v1->mUnlockItemQueue.mQueue;
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&v1->mUnlockItemQueue.mQueue);
  v11 = v1->mUnlockItemQueue.mQueue.mNode.mPrev;
  v12 = v1->mUnlockItemQueue.mQueue.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v10->mNode.mPrev = &v10->mNode;
  v10->mNode.mNext = &v10->mNode;
  UFG::UISubtitleMessageQueue::Clear(&v1->mFreeTextQueue);
  v13 = &v1->mFreeTextQueue.mQueue;
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&v1->mFreeTextQueue.mQueue);
  v14 = v1->mFreeTextQueue.mQueue.mNode.mPrev;
  v15 = v1->mFreeTextQueue.mQueue.mNode.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v13->mNode.mPrev = &v13->mNode;
  v13->mNode.mNext = &v13->mNode;
  UFG::UISubtitleMessageQueue::Clear(&v1->mMissionObjQueue);
  v16 = &v1->mMissionObjQueue.mQueue;
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&v1->mMissionObjQueue.mQueue);
  v17 = v1->mMissionObjQueue.mQueue.mNode.mPrev;
  v18 = v1->mMissionObjQueue.mQueue.mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v16->mNode.mPrev = &v16->mNode;
  v16->mNode.mNext = &v16->mNode;
  UFG::UISubtitleMessageQueue::Clear(&v1->mSubtitleQueue);
  v19 = &v1->mSubtitleQueue.mQueue;
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&v1->mSubtitleQueue.mQueue);
  v20 = v1->mSubtitleQueue.mQueue.mNode.mPrev;
  v21 = v1->mSubtitleQueue.mQueue.mNode.mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v19->mNode.mPrev = &v19->mNode;
  v19->mNode.mNext = &v19->mNode;
}

// File Line: 365
// RVA: 0x620860
UFG::UIHKTextOverlay *__fastcall UFG::UIHKTextOverlay::getInstance()
{
  UFG::UIHKTextOverlay *result; // rax

  result = (UFG::UIHKTextOverlay *)UFG::UIHKScreenGlobalOverlay::mThis;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    result = &UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay;
  return result;
}

// File Line: 377
// RVA: 0x640AE0
void __fastcall UFG::UIHKTextOverlay::update(UFG::UIHKTextOverlay *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIScreen *v3; // rsi
  UFG::UIHKTextOverlay *v4; // rdi
  UFG::UIScreenRenderable *v5; // rax
  UFG::UISubtitleMessage *v6; // rax
  UFG::UISubtitleMessage *v7; // rcx
  UFG::UISubtitleMessage *v8; // rax
  UFG::UIHKScreenGlobalOverlay *v9; // rax
  UFG::UIHKHelpBarWidget *v10; // rbp
  unsigned int v11; // ebx
  UFG::UIHKHelpBarWidget *v12; // rbp
  unsigned int v13; // eax
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-268h]

  v3 = screen;
  v4 = this;
  if ( screen != this->mScreen )
    this->mScreen = screen;
  if ( screen )
  {
    v5 = screen->mRenderable;
    if ( v5 )
    {
      if ( v5->m_shouldRender )
      {
        UFG::UISubtitleMessageQueue::Update(&this->mSubtitleQueue, elapsed);
        UFG::UISubtitleMessageQueue::Update(&v4->mMissionObjQueue, elapsed);
        UFG::UISubtitleMessageQueue::Update(&v4->mFreeTextQueue, elapsed);
        v6 = v4->mMissionComplete;
        if ( v6 )
        {
          v6->age = elapsed + v6->age;
          UFG::UISubtitleMessageQueue::Update(&v4->mUnlockItemQueue, elapsed);
          v7 = v4->mMissionComplete;
          if ( v7->state == 1 )
          {
            v8 = v4->mUnlockItemQueue.mCurrent1;
            if ( (!v8 || v8->state == 4)
              && (UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *)v4->mUnlockItemQueue.mQueue.mNode.mNext == &v4->mUnlockItemQueue.mQueue
              && v7->lifetime <= v7->age )
            {
              v7->state = 2;
              UFG::UIHKTextOverlay::OnStartFadeOut(v4, v4->mMissionComplete, 1);
            }
          }
          else if ( v7->state == 3 )
          {
            if ( v7 )
              UFG::UISubtitleMessage::`scalar deleting destructor'(v7, 1);
            v4->mMissionComplete = 0i64;
          }
        }
        if ( v4->mShowItChanged )
        {
          v4->mShowItChanged = 0;
          v9 = UFG::UIHKScreenGlobalOverlay::mThis;
          if ( v4->mShowIt )
          {
            if ( !UFG::UIHKScreenGlobalOverlay::mThis )
              v9 = &gGlobalOverlaySentinel;
            v10 = &v9->HelpBar;
            v11 = UFG::qStringHash32("TRANSIT", 0xFFFFFFFF);
            UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
            data.id = v11;
            data.priority = 0;
            data.alignment = 1;
            _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
            *(_QWORD *)&data.Buttons[4] = 0i64;
            UFG::qString::Set(data.Captions, "$COMMON_WARP");
            UFG::qString::Set(&data.Captions[1], &customWorldMapCaption);
            UFG::qString::Set(&data.Captions[2], &customWorldMapCaption);
            UFG::qString::Set(&data.Captions[3], &customWorldMapCaption);
            UFG::qString::Set(&data.Captions[4], &customWorldMapCaption);
            UFG::qString::Set(&data.Captions[5], &customWorldMapCaption);
            *(_QWORD *)data.MessageIds = 0i64;
            *(_QWORD *)&data.MessageIds[2] = 0i64;
            *(_QWORD *)&data.MessageIds[4] = 0i64;
            UFG::UIHKHelpBarWidget::Show(v10, &data);
            UFG::qString::~qString(&data.CustomTexturePack);
            `eh vector destructor iterator'(
              data.Icons,
              0x28ui64,
              6,
              (void (__fastcall *)(void *))UFG::qString::~qString);
            `eh vector destructor iterator'(
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
        if ( v4->mChanged )
        {
          v4->mChanged = 0;
          UFG::UIHKTextOverlay::Flash_SetSubtitlesYOffset(v4, v3, v4->mSubtitleYOffset);
          UFG::UIHKTextOverlay::Flash_SetSubtitlesVisible(v4, v3, v4->mSubtitlesVisible);
        }
      }
    }
  }
}

// File Line: 463
// RVA: 0x62E5C0
char __fastcall UFG::UIHKTextOverlay::handleMessage(UFG::UIHKTextOverlay *this, UFG::UIScreen *screen, unsigned int msgId, UFG::UIMessage *msg)
{
  unsigned int v4; // edi
  UFG::UIScreen *v5; // rsi
  UFG::UIHKTextOverlay *v6; // rbx
  UFG::UISubtitleMessage *v7; // rax
  UFG::UISubtitleMessage *v8; // rax
  char *v10; // rdi
  Scaleform::GFx::Movie *v11; // rcx
  UFG::UISubtitleMessage *v12; // rax
  UFG::SimObjectCVBase *v13; // rcx
  UFG::AiDriverComponent *v14; // rax
  UFG::qString v15; // [rsp+30h] [rbp-1h]
  Scaleform::GFx::Value pargs; // [rsp+58h] [rbp+27h]

  v4 = msgId;
  v5 = screen;
  v6 = this;
  if ( screen )
  {
    if ( screen != this->mScreen )
      this->mScreen = screen;
    if ( msgId == UI_HASH_FADEOUTCOMPLETE_11 )
    {
      UFG::qString::qString(&v15, (UFG::qString *)&msg[1]);
      if ( (unsigned int)UFG::qStringCompare(v15.mData, "subtitles_1", -1) )
      {
        if ( (unsigned int)UFG::qStringCompare(v15.mData, "subtitles_2", -1) )
        {
          if ( !(unsigned int)UFG::qStringCompare(v15.mData, "mission_obj", -1) )
          {
            v8 = v6->mMissionObjQueue.mCurrent1;
            if ( v8 )
              v8->state = 3;
            if ( v6->mMissionComplete )
            {
              UFG::UISubtitleMessageQueue::Clear(&v6->mMissionObjQueue);
              UFG::UIHKTextOverlay::StartMissionComplete(v6);
            }
            goto LABEL_23;
          }
          if ( (unsigned int)UFG::qStringCompare(v15.mData, "freetext", -1) )
          {
            if ( (unsigned int)UFG::qStringCompare(v15.mData, "mc_Unlockables", -1) )
            {
              if ( (unsigned int)UFG::qStringCompare(v15.mData, "mc_MissionComplete", -1) )
              {
                UFG::qStringCompare(v15.mData, "mc_SubMissionComplete", -1);
LABEL_23:
                UFG::qString::~qString(&v15);
                return 1;
              }
              v7 = v6->mMissionComplete;
            }
            else
            {
              v7 = v6->mUnlockItemQueue.mCurrent1;
            }
          }
          else
          {
            v7 = v6->mFreeTextQueue.mCurrent1;
          }
        }
        else
        {
          v7 = v6->mSubtitleQueue.mCurrent2;
        }
      }
      else
      {
        v7 = v6->mSubtitleQueue.mCurrent1;
      }
      if ( v7 )
        v7->state = 3;
      goto LABEL_23;
    }
    if ( msgId == UI_HASH_FADEINCOMPLETE_11 )
    {
      if ( !msg )
        return 1;
      UFG::qString::qString(&v15, (UFG::qString *)&msg[1]);
      pargs.pObjectInterface = 0i64;
      pargs.Type = 0;
      v10 = v15.mData;
      pargs.Type = 6;
      *(_QWORD *)&pargs.mValue.NValue = v10;
      v11 = v5->mRenderable->m_movie.pObject;
      if ( v11 )
        Scaleform::GFx::Movie::Invoke(v11, "blinkSubtext", 0i64, &pargs, 1u);
      if ( (unsigned int)UFG::qStringCompare(v15.mData, "subtitles_1", -1) )
      {
        if ( (unsigned int)UFG::qStringCompare(v15.mData, "subtitles_2", -1) )
        {
          if ( (unsigned int)UFG::qStringCompare(v15.mData, "mission_obj", -1) )
          {
            if ( (unsigned int)UFG::qStringCompare(v15.mData, "freetext", -1) )
            {
              if ( (unsigned int)UFG::qStringCompare(v15.mData, "mc_Unlockables", -1) )
              {
                if ( (unsigned int)UFG::qStringCompare(v15.mData, "mc_MissionComplete", -1) )
                {
                  UFG::qStringCompare(v15.mData, "mc_SubMissionComplete", -1);
LABEL_45:
                  if ( ((unsigned int)pargs.Type >> 6) & 1 )
                  {
                    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
                      pargs.pObjectInterface,
                      &pargs,
                      *(_QWORD *)&pargs.mValue.NValue);
                    pargs.pObjectInterface = 0i64;
                  }
                  pargs.Type = 0;
                  UFG::qString::~qString(&v15);
                  return 1;
                }
                v12 = v6->mMissionComplete;
              }
              else
              {
                v12 = v6->mUnlockItemQueue.mCurrent1;
              }
            }
            else
            {
              v12 = v6->mFreeTextQueue.mCurrent1;
            }
          }
          else
          {
            v12 = v6->mMissionObjQueue.mCurrent1;
          }
        }
        else
        {
          v12 = v6->mSubtitleQueue.mCurrent2;
        }
      }
      else
      {
        v12 = v6->mSubtitleQueue.mCurrent1;
      }
      if ( v12 )
        v12->state = 1;
      goto LABEL_45;
    }
    if ( msgId == UI_HASH_GAME_PAUSE_20 )
    {
      if ( this->mSubtitlesVisible )
      {
        *(_WORD *)&this->mChanged = 1;
        this->mSubtitleQueue.mPauseQueue = 1;
      }
    }
    else if ( msgId == UI_HASH_GAME_UNPAUSE_20 && this->mSubtitlesVisible != 1 )
    {
      *(_WORD *)&this->mChanged = 257;
      this->mSubtitleQueue.mPauseQueue = 0;
    }
    if ( this->mInTransit )
    {
      if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
      {
        v13 = (UFG::SimObjectCVBase *)this->mVehicle.m_pPointer;
        if ( v13 )
        {
          v14 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v13);
          if ( v14 )
            UFG::AiDriverComponent::WarpToGotoDestination(v14);
        }
        UFG::UIHKTextOverlay::ResetTransitSelectedStopData(v6);
      }
      if ( v4 == UI_HASH_EXIT_FROM_TRANSIT_VEHICLE_20 )
        UFG::UIHKTextOverlay::ResetTransitSelectedStopData(v6);
    }
  }
  return 0;
}

// File Line: 612
// RVA: 0x6029C0
void __fastcall UFG::UIHKTextOverlay::ResetTransitSelectedStopData(UFG::UIHKTextOverlay *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObjectVehicle> *v1; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v2; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rax

  v1 = &this->mVehicle;
  *(_WORD *)&this->mShowIt = 256;
  this->mInTransit = 0;
  if ( this->mVehicle.m_pPointer )
  {
    v2 = v1->mPrev;
    v3 = v1->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    v1->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
    v1->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mPrev;
  }
  v1->m_pPointer = 0i64;
}

// File Line: 620
// RVA: 0x5F3570
void __fastcall UFG::UIHKTextOverlay::OnStartFadeOut(UFG::UIHKTextOverlay *this, UFG::UISubtitleMessage *msg, int subtitleSlotId)
{
  UFG::UIScreen *v3; // r9
  UFG::UISubtitleMessage::eSUBTITLE_MESSAGE_TYPE v4; // ecx
  Scaleform::GFx::Movie *v5; // rcx
  const char *v6; // rdi
  int v7; // ecx
  Scaleform::GFx::Movie *v8; // rsi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  if ( msg )
  {
    v3 = this->mScreen;
    if ( v3 )
    {
      v4 = msg->type;
      if ( v4 == 2 )
      {
        v5 = v3->mRenderable->m_movie.pObject;
        if ( v5 )
          Scaleform::GFx::Movie::Invoke(v5, "hideMissionComplete", 0i64, 0i64, 0);
      }
      else
      {
        v6 = 0i64;
        if ( v4 )
        {
          v7 = v4 - 1;
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
        v8 = v3->mRenderable->m_movie.pObject;
        if ( v8 )
        {
          pargs.pObjectInterface = 0i64;
          pargs.Type = 6;
          *(_QWORD *)&pargs.mValue.NValue = v6;
          Scaleform::GFx::Movie::Invoke(v8, "fadeOutSubtext", 0i64, &pargs, 1u);
          if ( ((unsigned int)pargs.Type >> 6) & 1 )
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
              pargs.pObjectInterface,
              &pargs,
              *(_QWORD *)&pargs.mValue.NValue);
        }
      }
    }
  }
}

// File Line: 673
// RVA: 0x5F31A0
void __fastcall UFG::UIHKTextOverlay::OnStartFadeIn(UFG::UIHKTextOverlay *this, UFG::UISubtitleMessage *msg, int subtitleSlotId)
{
  int v3; // er14
  UFG::UISubtitleMessage *v4; // rbx
  UFG::UIScreen *v5; // rax
  Scaleform::GFx::Movie *v6; // rsi
  unsigned int v7; // edi
  unsigned int v8; // edx
  char *v9; // rcx
  UFG::qString *v10; // rax
  UFG::UIGfxTranslator *v11; // rcx
  const char *v12; // rax
  __int64 v13; // rdi
  double v14; // xmm6_8
  double v15; // xmm6_8
  __int64 v16; // rdi
  __int64 v17; // rdi
  const char *v18; // rdi
  UFG::UISubtitleMessage::eSUBTITLE_MESSAGE_TYPE v19; // ecx
  int v20; // ecx
  int v21; // ecx
  __int64 v22; // rbx
  const char *v23; // rdx
  Scaleform::GFx::Value result; // [rsp+30h] [rbp-B8h]
  UFG::qString ptr; // [rsp+60h] [rbp-88h]
  __int64 v26; // [rsp+88h] [rbp-60h]
  unsigned int v27; // [rsp+90h] [rbp-58h]
  __int64 v28; // [rsp+98h] [rbp-50h]
  char v29; // [rsp+A8h] [rbp-40h]
  __int64 v30; // [rsp+B8h] [rbp-30h]
  unsigned int v31; // [rsp+C0h] [rbp-28h]
  double v32; // [rsp+C8h] [rbp-20h]
  char v33; // [rsp+D8h] [rbp-10h]
  __int64 v34; // [rsp+E8h] [rbp+0h]
  unsigned int v35; // [rsp+F0h] [rbp+8h]
  double v36; // [rsp+F8h] [rbp+10h]
  char v37; // [rsp+108h] [rbp+20h]
  __int64 v38; // [rsp+118h] [rbp+30h]
  unsigned int v39; // [rsp+120h] [rbp+38h]
  __int64 v40; // [rsp+128h] [rbp+40h]
  char v41; // [rsp+138h] [rbp+50h]
  __int64 v42; // [rsp+148h] [rbp+60h]
  unsigned int v43; // [rsp+150h] [rbp+68h]
  __int64 v44; // [rsp+158h] [rbp+70h]
  __int64 v45; // [rsp+168h] [rbp+80h]
  UFG::qString v46; // [rsp+170h] [rbp+88h]

  if ( msg )
  {
    v45 = -2i64;
    v3 = subtitleSlotId;
    v4 = msg;
    v5 = this->mScreen;
    if ( v5 )
    {
      v6 = v5->mRenderable->m_movie.pObject;
      if ( v6 )
      {
        v7 = msg->mTagHash;
        if ( !v7 )
        {
          UFG::qString::qString(&ptr, msg->mText.mData);
          v9 = ptr.mData;
          if ( *ptr.mData == 36 )
          {
            v10 = UFG::qString::Substring(&ptr, (UFG::qString *)&result, 1, -1);
            UFG::qString::Set(&ptr, v10->mData, v10->mLength, 0i64, 0);
            UFG::qString::~qString((UFG::qString *)&result);
            v9 = ptr.mData;
          }
          v7 = HIDWORD(ptr.mNext);
          if ( HIDWORD(ptr.mNext) == -1 )
          {
            v7 = UFG::qStringHashUpper32(v9, HIDWORD(ptr.mNext) | v8);
            HIDWORD(ptr.mNext) = v7;
          }
          UFG::qString::~qString(&ptr);
        }
        UFG::qString::qString(&v46);
        v11 = UFG::UIScreenManager::s_instance->m_translator;
        if ( v11 )
        {
          v12 = (const char *)v11->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, v7);
          if ( v12 )
            UFG::qString::Set(&v46, v12);
        }
        `eh vector constructor iterator'(
          &ptr.mData,
          0x30ui64,
          5,
          (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        v13 = (__int64)v4->mText.mData;
        if ( (v27 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char **, __int64))(*(_QWORD *)v26 + 16i64))(v26, &ptr.mData, v28);
          v26 = 0i64;
        }
        v27 = 6;
        v28 = v13;
        v14 = v4->xPos;
        if ( (v31 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v30 + 16i64))(
            v30,
            &v29,
            COERCE_DOUBLE(*(_QWORD *)&v32));
          v30 = 0i64;
        }
        v31 = 5;
        v32 = v14;
        v15 = v4->yPos;
        if ( (v35 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v34 + 16i64))(
            v34,
            &v33,
            COERCE_DOUBLE(*(_QWORD *)&v36));
          v34 = 0i64;
        }
        v35 = 5;
        v36 = v15;
        v16 = (__int64)v4->color.mData;
        if ( (v39 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v38 + 16i64))(v38, &v37, v40);
          v38 = 0i64;
        }
        v39 = 6;
        v40 = v16;
        v17 = (__int64)v4->mIcon.mData;
        if ( (v43 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v42 + 16i64))(v42, &v41, v44);
          v42 = 0i64;
        }
        v43 = 6;
        v44 = v17;
        v18 = 0i64;
        v19 = v4->type;
        if ( v19 )
        {
          v20 = v19 - 1;
          if ( v20 )
          {
            v21 = v20 - 1;
            if ( v21 )
            {
              if ( v21 == 1 )
                v18 = "showUnlockable";
            }
            else
            {
              v18 = "showMissionComplete";
              v22 = (__int64)v4->title.mData;
              if ( (v31 >> 6) & 1 )
              {
                (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v30 + 16i64))(
                  v30,
                  &v29,
                  COERCE_DOUBLE(*(_QWORD *)&v32));
                v30 = 0i64;
              }
              v31 = 6;
              v32 = *(double *)&v22;
            }
          }
          else
          {
            v18 = "showFreeText";
          }
LABEL_40:
          Scaleform::GFx::Movie::Invoke(v6, v18, 0i64, (Scaleform::GFx::Value *)&ptr.mData, 5u);
          `eh vector destructor iterator'(
            &ptr.mData,
            0x30ui64,
            5,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
          UFG::qString::~qString(&v46);
          return;
        }
        result.pObjectInterface = 0i64;
        result.Type = 6;
        *(_QWORD *)&result.mValue.NValue = v46.mData;
        if ( v3 == 1 )
        {
          v18 = "showSubtitle_1";
          v23 = "subtitles_1.m_text.dispTxt.htmlText";
        }
        else
        {
          if ( v3 != 2 )
          {
LABEL_37:
            if ( ((unsigned int)result.Type >> 6) & 1 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&result.pObjectInterface->vfptr->gap8[8])(
                result.pObjectInterface,
                &result,
                *(_QWORD *)&result.mValue.NValue);
              result.pObjectInterface = 0i64;
            }
            result.Type = 0;
            goto LABEL_40;
          }
          v18 = "showSubtitle_2";
          v23 = "subtitles_2.m_text.dispTxt.htmlText";
        }
        Scaleform::GFx::Movie::SetVariable(v6, v23, &result, 1i64);
        goto LABEL_37;
      }
    }
  }
}

// File Line: 765
// RVA: 0x5F2DA0
void __fastcall UFG::UIHKTextOverlay::OnHideNow(UFG::UIHKTextOverlay *this, UFG::UISubtitleMessage *msg, int subtitleSlotId)
{
  UFG::UIScreen *v3; // rax
  Scaleform::GFx::Movie *v4; // rbx
  const char *v5; // rdx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v3 = this->mScreen;
  if ( v3 )
  {
    v4 = v3->mRenderable->m_movie.pObject;
    if ( v4 )
    {
      value.pObjectInterface = 0i64;
      value.Type = 6;
      *(_QWORD *)&value.mValue.NValue = &customWorldMapCaption;
      v5 = "subtitles_1.m_text.dispTxt.htmlText";
      if ( subtitleSlotId != 1 )
        v5 = "subtitles_2.m_text.dispTxt.htmlText";
      Scaleform::GFx::Movie::SetVariable(v4, v5, &value, 1i64);
      if ( ((unsigned int)value.Type >> 6) & 1 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
    }
  }
}

// File Line: 791
// RVA: 0x5FEDD0
__int64 __fastcall UFG::UIHKTextOverlay::QueueMessage(UFG::UIHKTextOverlay *this, UFG::UISubtitleMessage *msg)
{
  UFG::UISubtitleMessage *v2; // rbx
  UFG::UIHKTextOverlay *v3; // rdi
  UFG::UISubtitleMessage::eSUBTITLE_MESSAGE_TYPE v5; // ecx
  int v6; // ecx
  int v7; // ecx
  Scaleform::GFx::Movie *v8; // rdi
  __int64 v9; // rsi
  __int64 v10; // rsi
  UFG::UISubtitleMessage *v11; // rcx
  UFG::UISubtitleMessageQueue *v12; // rcx
  UFG::UISubtitleMessage *v13; // rax
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v14; // rcx
  UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *v15; // rax
  char ptr; // [rsp+40h] [rbp-68h]
  __int64 v17; // [rsp+50h] [rbp-58h]
  unsigned int v18; // [rsp+58h] [rbp-50h]
  __int64 v19; // [rsp+60h] [rbp-48h]
  char v20; // [rsp+70h] [rbp-38h]
  __int64 v21; // [rsp+80h] [rbp-28h]
  unsigned int v22; // [rsp+88h] [rbp-20h]
  __int64 v23; // [rsp+90h] [rbp-18h]

  v2 = msg;
  v3 = this;
  if ( !msg || !(unsigned int)UFG::qStringLength(msg->mText.mData) && !v2->mTagHash )
    return 0i64;
  v2->id = UFG::UIHKTextOverlay::gMessageIDCount++;
  v5 = v2->type;
  if ( v5 == TYPE_SUBTITLE_TEXT )
  {
    if ( !v3->mSubtitlesVisible )
      return v2->id;
    v14 = &v3->mSubtitleQueue.mQueue.mNode;
LABEL_24:
    v15 = v14->mPrev;
    v15->mNext = (UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *)&v2->mPrev;
    v2->mPrev = v15;
    v2->mNext = v14;
    v14->mPrev = (UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *)&v2->mPrev;
    return v2->id;
  }
  v6 = v5 - 1;
  if ( !v6 )
  {
    v14 = &v3->mFreeTextQueue.mQueue.mNode;
    goto LABEL_24;
  }
  v7 = v6 - 1;
  if ( !v7 )
  {
    v11 = v3->mMissionComplete;
    if ( v11 )
      UFG::UISubtitleMessage::`scalar deleting destructor'(v11, 1);
    v3->mMissionComplete = v2;
    v2->state = 4;
    v12 = &v3->mMissionObjQueue;
    v13 = v3->mMissionObjQueue.mCurrent1;
    if ( v13 && v13->state != 4 )
    {
      UFG::UISubtitleMessageQueue::StartFadeOut(v12);
    }
    else
    {
      UFG::UISubtitleMessageQueue::Clear(v12);
      UFG::UIHKTextOverlay::StartMissionComplete(v3);
    }
    return v2->id;
  }
  if ( v7 == 1 )
  {
    v8 = v3->mScreen->mRenderable->m_movie.pObject;
    if ( v8 )
    {
      `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v9 = (__int64)v2->mText.mData;
      if ( (v18 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v17 + 16i64))(v17, &ptr, v19);
        v17 = 0i64;
      }
      v18 = 6;
      v19 = v9;
      v10 = (__int64)v2->mIcon.mData;
      if ( (v22 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v21 + 16i64))(v21, &v20, v23);
        v21 = 0i64;
      }
      v22 = 6;
      v23 = v10;
      Scaleform::GFx::Movie::Invoke(v8, "Rewards_Add", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
      `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      return v2->id;
    }
    return 0i64;
  }
  return v2->id;
}

// File Line: 860
// RVA: 0x610BA0
void __fastcall UFG::UIHKTextOverlay::ShowMessageOnScreen(const char *msg, float lifetime, float x, float y, UFG::qString *color)
{
  const char *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::UIHKTextOverlay *v7; // rdi
  UFG::UISubtitleMessage *v8; // rax
  UFG::UISubtitleMessage *v9; // rbx

  v5 = msg;
  v6 = UFG::qMalloc(0xD0ui64, "UISubtitleMessage", 0i64);
  v7 = 0i64;
  if ( v6 )
  {
    UFG::UISubtitleMessage::UISubtitleMessage((UFG::UISubtitleMessage *)v6, 0, v5, 0i64);
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
    v7 = &UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay;
  UFG::UIHKTextOverlay::QueueMessage(v7, v9);
  UFG::qString::~qString(color);
}

// File Line: 872
// RVA: 0x611ED0
void __fastcall UFG::UIHKTextOverlay::StartMissionComplete(UFG::UIHKTextOverlay *this)
{
  UFG::UIHKTextOverlay *v1; // rbx
  UFG::UIScreen *v2; // rax
  Scaleform::GFx::Movie *v3; // rdi
  long double v4; // rsi
  __int64 v5; // rsi
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h]
  char v7; // [rsp+70h] [rbp-38h]
  __int64 v8; // [rsp+80h] [rbp-28h]
  unsigned int v9; // [rsp+88h] [rbp-20h]
  __int64 v10; // [rsp+90h] [rbp-18h]

  v1 = this;
  if ( this->mMissionComplete )
  {
    v2 = this->mScreen;
    if ( v2 )
    {
      v3 = v2->mRenderable->m_movie.pObject;
      if ( v3 )
      {
        `eh vector constructor iterator'(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        v4 = *(double *)&v1->mMissionComplete->mText.mData;
        if ( ((unsigned int)pargs.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
            pargs.pObjectInterface,
            &pargs,
            *(_QWORD *)&pargs.mValue.NValue);
          pargs.pObjectInterface = 0i64;
        }
        pargs.Type = 6;
        pargs.mValue.NValue = v4;
        v5 = (__int64)v1->mMissionComplete->title.mData;
        if ( (v9 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v8 + 16i64))(v8, &v7, v10);
          v8 = 0i64;
        }
        v9 = 6;
        v10 = v5;
        Scaleform::GFx::Movie::Invoke(v3, "showMissionComplete", 0i64, &pargs, 2u);
        v1->mMissionComplete->state = 0;
        `eh vector destructor iterator'(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
    }
  }
}

// File Line: 894
// RVA: 0x5ED0F0
void __fastcall UFG::UIHKTextOverlay::HideMissionObjectives(UFG::UIHKTextOverlay *this)
{
  UFG::UIHKTextOverlay *v1; // rbx
  UFG::UISubtitleMessage *v2; // rdx
  UFG::UIHKTextOverlay *v3; // rcx
  UFG::UISubtitleMessage *v4; // rdx
  UFG::UIHKTextOverlay *v5; // rcx

  v1 = this;
  UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&this->mMissionObjQueue.mQueue);
  v2 = v1->mMissionObjQueue.mCurrent1;
  if ( v2 )
  {
    if ( v2->state <= 1u )
    {
      v2->state = 2;
      v3 = v1->mMissionObjQueue.mParent;
      if ( v3 )
        UFG::UIHKTextOverlay::OnStartFadeOut(v3, v2, 1);
    }
  }
  v4 = v1->mMissionObjQueue.mCurrent2;
  if ( v4 && v4->state <= 1u )
  {
    v4->state = 2;
    v5 = v1->mMissionObjQueue.mParent;
    if ( v5 )
      UFG::UIHKTextOverlay::OnStartFadeOut(v5, v4, 2);
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
void __fastcall UFG::UIHKTextOverlay::ChangeSubtitleLifetime(UFG::UIHKTextOverlay *this, unsigned int id, float newLifetime)
{
  UFG::UISubtitleMessage *v3; // rax
  UFG::UISubtitleMessage *v4; // rcx

  v3 = this->mSubtitleQueue.mCurrent1;
  if ( v3 && v3->id == id || (v3 = this->mSubtitleQueue.mCurrent2) != 0i64 && v3->id == id )
  {
LABEL_10:
    if ( v3 )
      v3->lifetime = newLifetime;
  }
  else
  {
    v3 = (UFG::UISubtitleMessage *)this->mSubtitleQueue.mQueue.mNode.mNext;
    v4 = (UFG::UISubtitleMessage *)&this->mSubtitleQueue.mQueue;
    while ( v3 != v4 )
    {
      if ( v3 && v3->id == id )
        goto LABEL_10;
      v3 = (UFG::UISubtitleMessage *)v3->mNext;
    }
  }
}

// File Line: 934
// RVA: 0x5E95D0
float __fastcall UFG::UIHKTextOverlay::GetSubtitleAge(UFG::UIHKTextOverlay *this, unsigned int id)
{
  UFG::UISubtitleMessage *v2; // rax
  UFG::UISubtitleMessage *v3; // rcx

  v2 = this->mSubtitleQueue.mCurrent1;
  if ( v2 && v2->id == id || (v2 = this->mSubtitleQueue.mCurrent2) != 0i64 && v2->id == id )
  {
LABEL_10:
    if ( v2 )
      return v2->age;
  }
  else
  {
    v2 = (UFG::UISubtitleMessage *)this->mSubtitleQueue.mQueue.mNode.mNext;
    v3 = (UFG::UISubtitleMessage *)&this->mSubtitleQueue.mQueue;
    while ( v2 != v3 )
    {
      if ( v2 && v2->id == id )
        goto LABEL_10;
      v2 = (UFG::UISubtitleMessage *)v2->mNext;
    }
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
void __fastcall UFG::UIHKTextOverlay::Flash_SetSubtitlesYOffset(UFG::UIHKTextOverlay *this, UFG::UIScreen *screen, float y_offset)
{
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-50h]

  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 5;
    value.mValue.NValue = y_offset;
    Scaleform::GFx::Movie::SetVariable(v3, "subtitles_y_offset", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

// File Line: 974
// RVA: 0x5E0F60
void __fastcall UFG::UIHKTextOverlay::Flash_SetSubtitlesVisible(UFG::UIHKTextOverlay *this, UFG::UIScreen *screen, bool visible)
{
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 2;
    value.mValue.BValue = visible;
    Scaleform::GFx::Movie::SetVariable(v3, "subtitles_1._visible", &value, 1i64);
    Scaleform::GFx::Movie::SetVariable(v3, "subtitles_2._visible", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

