// File Line: 52
// RVA: 0xA33560
void __fastcall UFG::UIScreenManagerBase::UIScreenManagerBase(
        UFG::UIScreenManagerBase *this,
        UFG::UIScreenFactory *screenFactory)
{
  this->vfptr = (UFG::UIScreenManagerBaseVtbl *)&UFG::UIScreenManagerBase::`vftable;
  this->m_screenStack.mNode.mPrev = &this->m_screenStack.mNode;
  this->m_screenStack.mNode.mNext = &this->m_screenStack.mNode;
  this->m_overlayStack.mNode.mPrev = &this->m_overlayStack.mNode;
  this->m_overlayStack.mNode.mNext = &this->m_overlayStack.mNode;
  Scaleform::Lock::Lock(&this->mScreenStackLock, 0);
  this->mPendingScreenLoads.mNode.mPrev = &this->mPendingScreenLoads.mNode;
  this->mPendingScreenLoads.mNode.mNext = &this->mPendingScreenLoads.mNode;
  this->mPendingOverlayLoads.mNode.mPrev = &this->mPendingOverlayLoads.mNode;
  this->mPendingOverlayLoads.mNode.mNext = &this->mPendingOverlayLoads.mNode;
  this->mPendingPoppedScreens.mNode.mPrev = &this->mPendingPoppedScreens.mNode;
  this->mPendingPoppedScreens.mNode.mNext = &this->mPendingPoppedScreens.mNode;
  this->m_gfxMovieLoader = 0i64;
  this->mRenderer2D.pObject = 0i64;
  this->mThreadCommandQueue = 0i64;
  this->mTextureManager = 0i64;
  this->mAmpAppControl = 0i64;
  this->mMainThreadId = 0i64;
  *(_DWORD *)&this->m_renderUI = 16842753;
  this->m_maxScreenLimit = -1;
  *(_QWORD *)&this->m_targetWidth = 0i64;
  *(_QWORD *)&this->m_flashWidth = 0i64;
  this->mScaleViewportInCode = 0;
  this->mScreenUIDCounter = 0;
  this->m_defaultControllerMask = -1;
  this->m_inputSuspended = 0;
  this->m_commandQueue.mNode.mPrev = &this->m_commandQueue.mNode;
  this->m_commandQueue.mNode.mNext = &this->m_commandQueue.mNode;
  this->m_screenCommandQueue.mNode.mPrev = &this->m_screenCommandQueue.mNode;
  this->m_screenCommandQueue.mNode.mNext = &this->m_screenCommandQueue.mNode;
  this->m_pendingMessages.mNode.mPrev = &this->m_pendingMessages.mNode;
  this->m_pendingMessages.mNode.mNext = &this->m_pendingMessages.mNode;
  this->m_inputDisabledQueue.mNode.mPrev = &this->m_inputDisabledQueue.mNode;
  this->m_inputDisabledQueue.mNode.mNext = &this->m_inputDisabledQueue.mNode;
  UFG::qMutex::qMutex(&this->m_pendingMessagesMutex, &customCaption);
  this->m_activeTweens.mNode.mPrev = &this->m_activeTweens.mNode;
  this->m_activeTweens.mNode.mNext = &this->m_activeTweens.mNode;
  this->m_inputHandler = 0i64;
  this->m_audioCallback = 0i64;
  this->m_DisplayChangeCallback = 0i64;
  this->m_translator = 0i64;
  this->m_currentNumDrawText = 0;
  this->m_inputEnabled = 0;
  this->m_screenFactory = screenFactory;
  this->mIsMidSwitch = 0;
  UFG::qString::qString(&this->mDebugStackPrint);
}

// File Line: 59
// RVA: 0xA337E0
void __fastcall UFG::UIScreenManagerBase::~UIScreenManagerBase(UFG::UIScreenManagerBase *this)
{
  UFG::qNode<UFG::UITween,UFG::UITween> *mPrev; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *mNext; // rax
  UFG::qNode<UFG::qValueNode<unsigned long>,UFG::qValueNode<unsigned long> > *v4; // rcx
  UFG::qNode<UFG::qValueNode<unsigned long>,UFG::qValueNode<unsigned long> > *v5; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v6; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v7; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v8; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v9; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v10; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v11; // rax
  Scaleform::Render::RenderBuffer *pObject; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v13; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v14; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v15; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v16; // rax
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v17; // rcx
  UFG::qNode<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad> *v18; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v19; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v20; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v21; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v22; // rax

  this->vfptr = (UFG::UIScreenManagerBaseVtbl *)&UFG::UIScreenManagerBase::`vftable;
  UFG::qString::~qString(&this->mDebugStackPrint);
  UFG::qList<UFG::UITween,UFG::UITween,1,0>::DeleteNodes(&this->m_activeTweens);
  mPrev = this->m_activeTweens.mNode.mPrev;
  mNext = this->m_activeTweens.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->m_activeTweens.mNode.mPrev = &this->m_activeTweens.mNode;
  this->m_activeTweens.mNode.mNext = &this->m_activeTweens.mNode;
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&this->m_pendingMessagesMutex);
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&this->m_inputDisabledQueue);
  v4 = this->m_inputDisabledQueue.mNode.mPrev;
  v5 = this->m_inputDisabledQueue.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->m_inputDisabledQueue.mNode.mPrev = &this->m_inputDisabledQueue.mNode;
  this->m_inputDisabledQueue.mNode.mNext = &this->m_inputDisabledQueue.mNode;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_pendingMessages);
  v6 = this->m_pendingMessages.mNode.mPrev;
  v7 = this->m_pendingMessages.mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  this->m_pendingMessages.mNode.mPrev = &this->m_pendingMessages.mNode;
  this->m_pendingMessages.mNode.mNext = &this->m_pendingMessages.mNode;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_screenCommandQueue);
  v8 = this->m_screenCommandQueue.mNode.mPrev;
  v9 = this->m_screenCommandQueue.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->m_screenCommandQueue.mNode.mPrev = &this->m_screenCommandQueue.mNode;
  this->m_screenCommandQueue.mNode.mNext = &this->m_screenCommandQueue.mNode;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_commandQueue);
  v10 = this->m_commandQueue.mNode.mPrev;
  v11 = this->m_commandQueue.mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  this->m_commandQueue.mNode.mPrev = &this->m_commandQueue.mNode;
  this->m_commandQueue.mNode.mNext = &this->m_commandQueue.mNode;
  pObject = (Scaleform::Render::RenderBuffer *)this->mRenderer2D.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->mPendingPoppedScreens);
  v13 = this->mPendingPoppedScreens.mNode.mPrev;
  v14 = this->mPendingPoppedScreens.mNode.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  this->mPendingPoppedScreens.mNode.mPrev = &this->mPendingPoppedScreens.mNode;
  this->mPendingPoppedScreens.mNode.mNext = &this->mPendingPoppedScreens.mNode;
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&this->mPendingOverlayLoads);
  v15 = this->mPendingOverlayLoads.mNode.mPrev;
  v16 = this->mPendingOverlayLoads.mNode.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  this->mPendingOverlayLoads.mNode.mPrev = &this->mPendingOverlayLoads.mNode;
  this->mPendingOverlayLoads.mNode.mNext = &this->mPendingOverlayLoads.mNode;
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&this->mPendingScreenLoads);
  v17 = this->mPendingScreenLoads.mNode.mPrev;
  v18 = this->mPendingScreenLoads.mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  this->mPendingScreenLoads.mNode.mPrev = &this->mPendingScreenLoads.mNode;
  this->mPendingScreenLoads.mNode.mNext = &this->mPendingScreenLoads.mNode;
  Scaleform::Lock::~Lock(&this->mScreenStackLock.cs);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_overlayStack);
  v19 = this->m_overlayStack.mNode.mPrev;
  v20 = this->m_overlayStack.mNode.mNext;
  v19->mNext = v20;
  v20->mPrev = v19;
  this->m_overlayStack.mNode.mPrev = &this->m_overlayStack.mNode;
  this->m_overlayStack.mNode.mNext = &this->m_overlayStack.mNode;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_screenStack);
  v21 = this->m_screenStack.mNode.mPrev;
  v22 = this->m_screenStack.mNode.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  this->m_screenStack.mNode.mPrev = &this->m_screenStack.mNode;
  this->m_screenStack.mNode.mNext = &this->m_screenStack.mNode;
}

// File Line: 92
// RVA: 0xA33B70
void __fastcall UFG::UIScreenManagerBase::enableInput(UFG::UIScreenManagerBase *this, bool enable)
{
  if ( enable )
    --this->m_inputEnabled;
  else
    ++this->m_inputEnabled;
}

// File Line: 109
// RVA: 0xA33FB0
_BOOL8 __fastcall UFG::UIScreenManagerBase::isInputEnabled(UFG::UIScreenManagerBase *this)
{
  return this->m_inputEnabled == 0;
}

// File Line: 232
// RVA: 0x638820
void __fastcall UFG::UIScreenManagerBase::killTweens(UFG::UIScreenManagerBase *this, Scaleform::GFx::Movie *movie)
{
  UFG::UITween *mNext; // rbx
  UFG::qList<UFG::UITween,UFG::UITween,1,0> *p_m_activeTweens; // rsi
  UFG::qList<UFG::UITween,UFG::UITween,1,0> *v5; // rdi
  UFG::qNode<UFG::UITween,UFG::UITween> *mPrev; // rax

  mNext = (UFG::UITween *)this->m_activeTweens.mNode.mNext;
  p_m_activeTweens = &this->m_activeTweens;
  if ( mNext != (UFG::UITween *)&this->m_activeTweens )
  {
    do
    {
      v5 = (UFG::qList<UFG::UITween,UFG::UITween,1,0> *)mNext->mNext;
      if ( mNext->mMovie == movie )
      {
        mPrev = mNext->mPrev;
        mPrev->mNext = &v5->mNode;
        v5->mNode.mPrev = mPrev;
        mNext->mPrev = mNext;
        mNext->mNext = mNext;
        UFG::UITween::~UITween(mNext);
        operator delete[](mNext);
      }
      mNext = (UFG::UITween *)v5;
    }
    while ( v5 != p_m_activeTweens );
  }
}

// File Line: 248
// RVA: 0xA30340
void __fastcall UFG::UIScreenManagerBase::killTweens(
        UFG::UIScreenManagerBase *this,
        Scaleform::GFx::Movie *movie,
        const char *pathToMovie)
{
  UFG::UITween *mNext; // rbx
  UFG::qList<UFG::UITween,UFG::UITween,1,0> *p_m_activeTweens; // rsi
  UFG::UITween *v7; // rdi
  UFG::qNode<UFG::UITween,UFG::UITween> *mPrev; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *v9; // rax

  mNext = (UFG::UITween *)this->m_activeTweens.mNode.mNext;
  p_m_activeTweens = &this->m_activeTweens;
  if ( mNext != (UFG::UITween *)&this->m_activeTweens )
  {
    do
    {
      v7 = (UFG::UITween *)mNext->mNext;
      if ( mNext->mMovie == movie && UFG::qString::operator==(&mNext->mPath, pathToMovie) )
      {
        mPrev = mNext->mPrev;
        v9 = mNext->mNext;
        mPrev->mNext = v9;
        v9->mPrev = mPrev;
        mNext->mPrev = mNext;
        mNext->mNext = mNext;
        UFG::UITween::~UITween(mNext);
        operator delete[](mNext);
      }
      mNext = v7;
    }
    while ( v7 != (UFG::UITween *)p_m_activeTweens );
  }
}

