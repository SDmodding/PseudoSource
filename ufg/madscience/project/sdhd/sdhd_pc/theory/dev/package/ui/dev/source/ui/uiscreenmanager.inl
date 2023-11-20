// File Line: 52
// RVA: 0xA33560
void __fastcall UFG::UIScreenManagerBase::UIScreenManagerBase(UFG::UIScreenManagerBase *this, UFG::UIScreenFactory *screenFactory)
{
  UFG::UIScreenFactory *v2; // rbx
  UFG::UIScreenManagerBase *v3; // rdi
  UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *v4; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *v5; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *v6; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::UIPendingScreenLoad,UFG::UIPendingScreenLoad,1,0> *v7; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::UIScreen,UFG::UIScreen,1,0> *v8; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::UICommand,UFG::UICommand,1,0> *v9; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::UICommand,UFG::UICommand,1,0> *v10; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::UICommand,UFG::UICommand,1,0> *v11; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::qValueNode<unsigned long>,UFG::qValueNode<unsigned long>,1,0> *v12; // [rsp+48h] [rbp+10h]
  UFG::qList<UFG::UITween,UFG::UITween,1,0> *v13; // [rsp+48h] [rbp+10h]

  v2 = screenFactory;
  v3 = this;
  this->vfptr = (UFG::UIScreenManagerBaseVtbl *)&UFG::UIScreenManagerBase::`vftable';
  v4 = &this->m_screenStack;
  v4->mNode.mPrev = &v4->mNode;
  v4->mNode.mNext = &v4->mNode;
  v5 = &this->m_overlayStack;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  Scaleform::Lock::Lock(&this->mScreenStackLock, 0);
  v6 = &v3->mPendingScreenLoads;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  v7 = &v3->mPendingOverlayLoads;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  v8 = &v3->mPendingPoppedScreens;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  v3->m_gfxMovieLoader = 0i64;
  v3->mRenderer2D.pObject = 0i64;
  v3->mThreadCommandQueue = 0i64;
  v3->mTextureManager = 0i64;
  v3->mAmpAppControl = 0i64;
  v3->mMainThreadId = 0i64;
  *(_DWORD *)&v3->m_renderUI = 16842753;
  v3->m_maxScreenLimit = -1;
  *(_QWORD *)&v3->m_targetWidth = 0i64;
  *(_QWORD *)&v3->m_flashWidth = 0i64;
  v3->mScaleViewportInCode = 0;
  v3->mScreenUIDCounter = 0;
  v3->m_defaultControllerMask = -1;
  v3->m_inputSuspended = 0;
  v9 = &v3->m_commandQueue;
  v9->mNode.mPrev = &v9->mNode;
  v9->mNode.mNext = &v9->mNode;
  v10 = &v3->m_screenCommandQueue;
  v10->mNode.mPrev = &v10->mNode;
  v10->mNode.mNext = &v10->mNode;
  v11 = &v3->m_pendingMessages;
  v11->mNode.mPrev = &v11->mNode;
  v11->mNode.mNext = &v11->mNode;
  v12 = &v3->m_inputDisabledQueue;
  v12->mNode.mPrev = &v12->mNode;
  v12->mNode.mNext = &v12->mNode;
  UFG::qMutex::qMutex(&v3->m_pendingMessagesMutex, &customWorldMapCaption);
  v13 = &v3->m_activeTweens;
  v13->mNode.mPrev = &v13->mNode;
  v13->mNode.mNext = &v13->mNode;
  v3->m_inputHandler = 0i64;
  v3->m_audioCallback = 0i64;
  v3->m_DisplayChangeCallback = 0i64;
  v3->m_translator = 0i64;
  v3->m_currentNumDrawText = 0;
  v3->m_inputEnabled = 0;
  v3->m_screenFactory = v2;
  v3->mIsMidSwitch = 0;
  UFG::qString::qString(&v3->mDebugStackPrint);
}

// File Line: 59
// RVA: 0xA337E0
void __fastcall UFG::UIScreenManagerBase::~UIScreenManagerBase(UFG::UIScreenManagerBase *this)
{
  UFG::UIScreenManagerBase *v1; // rdi
  UFG::qNode<UFG::UITween,UFG::UITween> *v2; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *v3; // rax
  UFG::qNode<UFG::qValueNode<unsigned long>,UFG::qValueNode<unsigned long> > *v4; // rcx
  UFG::qNode<UFG::qValueNode<unsigned long>,UFG::qValueNode<unsigned long> > *v5; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v6; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v7; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v8; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v9; // rax
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v10; // rcx
  UFG::qNode<UFG::UICommand,UFG::UICommand> *v11; // rax
  Scaleform::Render::RenderBuffer *v12; // rcx
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

  v1 = this;
  this->vfptr = (UFG::UIScreenManagerBaseVtbl *)&UFG::UIScreenManagerBase::`vftable';
  UFG::qString::~qString(&this->mDebugStackPrint);
  UFG::qList<UFG::UITween,UFG::UITween,1,0>::DeleteNodes(&v1->m_activeTweens);
  v2 = v1->m_activeTweens.mNode.mPrev;
  v3 = v1->m_activeTweens.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->m_activeTweens.mNode.mPrev = &v1->m_activeTweens.mNode;
  v1->m_activeTweens.mNode.mNext = &v1->m_activeTweens.mNode;
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v1->m_pendingMessagesMutex);
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&v1->m_inputDisabledQueue);
  v4 = v1->m_inputDisabledQueue.mNode.mPrev;
  v5 = v1->m_inputDisabledQueue.mNode.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->m_inputDisabledQueue.mNode.mPrev = &v1->m_inputDisabledQueue.mNode;
  v1->m_inputDisabledQueue.mNode.mNext = &v1->m_inputDisabledQueue.mNode;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->m_pendingMessages);
  v6 = v1->m_pendingMessages.mNode.mPrev;
  v7 = v1->m_pendingMessages.mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v1->m_pendingMessages.mNode.mPrev = &v1->m_pendingMessages.mNode;
  v1->m_pendingMessages.mNode.mNext = &v1->m_pendingMessages.mNode;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->m_screenCommandQueue);
  v8 = v1->m_screenCommandQueue.mNode.mPrev;
  v9 = v1->m_screenCommandQueue.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v1->m_screenCommandQueue.mNode.mPrev = &v1->m_screenCommandQueue.mNode;
  v1->m_screenCommandQueue.mNode.mNext = &v1->m_screenCommandQueue.mNode;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->m_commandQueue);
  v10 = v1->m_commandQueue.mNode.mPrev;
  v11 = v1->m_commandQueue.mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v1->m_commandQueue.mNode.mPrev = &v1->m_commandQueue.mNode;
  v1->m_commandQueue.mNode.mNext = &v1->m_commandQueue.mNode;
  v12 = (Scaleform::Render::RenderBuffer *)v1->mRenderer2D.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->mPendingPoppedScreens);
  v13 = v1->mPendingPoppedScreens.mNode.mPrev;
  v14 = v1->mPendingPoppedScreens.mNode.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v1->mPendingPoppedScreens.mNode.mPrev = &v1->mPendingPoppedScreens.mNode;
  v1->mPendingPoppedScreens.mNode.mNext = &v1->mPendingPoppedScreens.mNode;
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&v1->mPendingOverlayLoads);
  v15 = v1->mPendingOverlayLoads.mNode.mPrev;
  v16 = v1->mPendingOverlayLoads.mNode.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v1->mPendingOverlayLoads.mNode.mPrev = &v1->mPendingOverlayLoads.mNode;
  v1->mPendingOverlayLoads.mNode.mNext = &v1->mPendingOverlayLoads.mNode;
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&v1->mPendingScreenLoads);
  v17 = v1->mPendingScreenLoads.mNode.mPrev;
  v18 = v1->mPendingScreenLoads.mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v1->mPendingScreenLoads.mNode.mPrev = &v1->mPendingScreenLoads.mNode;
  v1->mPendingScreenLoads.mNode.mNext = &v1->mPendingScreenLoads.mNode;
  Scaleform::Lock::~Lock(&v1->mScreenStackLock.cs);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->m_overlayStack);
  v19 = v1->m_overlayStack.mNode.mPrev;
  v20 = v1->m_overlayStack.mNode.mNext;
  v19->mNext = v20;
  v20->mPrev = v19;
  v1->m_overlayStack.mNode.mPrev = &v1->m_overlayStack.mNode;
  v1->m_overlayStack.mNode.mNext = &v1->m_overlayStack.mNode;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->m_screenStack);
  v21 = v1->m_screenStack.mNode.mPrev;
  v22 = v1->m_screenStack.mNode.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  v1->m_screenStack.mNode.mPrev = &v1->m_screenStack.mNode;
  v1->m_screenStack.mNode.mNext = &v1->m_screenStack.mNode;
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
  UFG::UITween *v2; // rbx
  UFG::qList<UFG::UITween,UFG::UITween,1,0> *v3; // rsi
  Scaleform::GFx::Movie *v4; // rbp
  UFG::UITween *v5; // rdi
  UFG::qNode<UFG::UITween,UFG::UITween> *v6; // rax

  v2 = (UFG::UITween *)this->m_activeTweens.mNode.mNext;
  v3 = &this->m_activeTweens;
  v4 = movie;
  if ( v2 != (UFG::UITween *)&this->m_activeTweens )
  {
    do
    {
      v5 = (UFG::UITween *)v2->mNext;
      if ( v2->mMovie == v4 )
      {
        v6 = v2->mPrev;
        v6->mNext = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v5->mPrev;
        v5->mPrev = v6;
        v2->mPrev = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v2->mPrev;
        v2->mNext = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v2->mPrev;
        UFG::UITween::~UITween(v2);
        operator delete[](v2);
      }
      v2 = v5;
    }
    while ( v5 != (UFG::UITween *)v3 );
  }
}

// File Line: 248
// RVA: 0xA30340
void __fastcall UFG::UIScreenManagerBase::killTweens(UFG::UIScreenManagerBase *this, Scaleform::GFx::Movie *movie, const char *pathToMovie)
{
  UFG::UITween *v3; // rbx
  UFG::qList<UFG::UITween,UFG::UITween,1,0> *v4; // rsi
  const char *v5; // r14
  Scaleform::GFx::Movie *v6; // rbp
  UFG::UITween *v7; // rdi
  UFG::qNode<UFG::UITween,UFG::UITween> *v8; // rcx
  UFG::qNode<UFG::UITween,UFG::UITween> *v9; // rax

  v3 = (UFG::UITween *)this->m_activeTweens.mNode.mNext;
  v4 = &this->m_activeTweens;
  v5 = pathToMovie;
  v6 = movie;
  if ( v3 != (UFG::UITween *)&this->m_activeTweens )
  {
    do
    {
      v7 = (UFG::UITween *)v3->mNext;
      if ( v3->mMovie == v6 )
      {
        if ( UFG::qString::operator==(&v3->mPath, v5) )
        {
          v8 = v3->mPrev;
          v9 = v3->mNext;
          v8->mNext = v9;
          v9->mPrev = v8;
          v3->mPrev = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v3->mPrev;
          v3->mNext = (UFG::qNode<UFG::UITween,UFG::UITween> *)&v3->mPrev;
          UFG::UITween::~UITween(v3);
          operator delete[](v3);
        }
      }
      v3 = v7;
    }
    while ( v7 != (UFG::UITween *)v4 );
  }
}

