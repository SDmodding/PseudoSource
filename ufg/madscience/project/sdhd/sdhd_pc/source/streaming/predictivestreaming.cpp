// File Line: 36
// RVA: 0x3E8FE0
void UFG::PredictiveStreaming::CreateInstance(void)
{
  UFG::allocator::free_link *v0; // rax
  UFG::PredictiveStreaming *v1; // rax

  v0 = UFG::qMalloc(0x120ui64, "PredictiveStreaming", 0i64);
  if ( v0 )
  {
    UFG::PredictiveStreaming::PredictiveStreaming((UFG::PredictiveStreaming *)v0);
    UFG::PredictiveStreaming::ms_pInstance = v1;
  }
  else
  {
    UFG::PredictiveStreaming::ms_pInstance = 0i64;
  }
}

// File Line: 49
// RVA: 0x3E9090
void UFG::PredictiveStreaming::DeleteInstance(void)
{
  UFG::PredictiveStreaming *v0; // rbx

  v0 = UFG::PredictiveStreaming::ms_pInstance;
  if ( UFG::PredictiveStreaming::ms_pInstance )
  {
    ActionController::~ActionController(&UFG::PredictiveStreaming::ms_pInstance->m_ActionController);
    operator delete[](v0);
  }
  UFG::PredictiveStreaming::ms_pInstance = 0i64;
}

// File Line: 57
// RVA: 0x3E8AB0
void __fastcall UFG::PredictiveStreaming::PredictiveStreaming(UFG::PredictiveStreaming *this)
{
  ActionController *p_m_ActionController; // rdi
  ActionContext *v3; // rax

  p_m_ActionController = &this->m_ActionController;
  ActionController::ActionController(&this->m_ActionController);
  v3 = (ActionContext *)UFG::qMalloc(0xD8ui64, "ActionTreeComponent::ActionContext.PredictiveStreaming", 0i64);
  if ( v3 )
    ActionContext::ActionContext(v3);
  this->m_pActionContext = v3;
  this->m_ActionController.m_Context = v3;
  v3->mActionController = p_m_ActionController;
  UFG::PredictiveStreaming::InitActionTree(this);
}

// File Line: 77
// RVA: 0x3EABD0
void __fastcall UFG::PredictiveStreaming::Update(UFG::PredictiveStreaming *this, float fTimeDeltaS)
{
  ActionController *p_m_ActionController; // rsi
  int v3; // edi
  bool v4; // bl
  char *mBuffer; // rbx
  char *v6; // rax
  Render::DebugDrawContext *Context; // rax
  UFG::qStringBuilder debugStringBuilder; // [rsp+38h] [rbp-20h] BYREF

  p_m_ActionController = &this->m_ActionController;
  ActionController::Update(&this->m_ActionController, fTimeDeltaS);
  if ( UFG::PredictiveStreaming::ms_bDrawActionController )
  {
    UFG::qStringBuilder::qStringBuilder(&debugStringBuilder);
    v3 = 0;
    if ( UFG::PredictiveStreaming::ms_bShowTracksActionController )
    {
      v4 = gReflectOnlyOpportunities;
      gReflectOnlyOpportunities = 0;
      ActionController::GetDebugString(p_m_ActionController, &debugStringBuilder, 1, 0i64, 0i64);
      gReflectOnlyOpportunities = v4;
    }
    else
    {
      ActionController::GetDebugString(p_m_ActionController, &debugStringBuilder, 0, 0i64, 0i64);
    }
    mBuffer = debugStringBuilder.mBuffer;
    if ( UFG::PredictiveStreaming::ms_iScrollActionController <= 0 )
    {
LABEL_8:
      if ( mBuffer )
      {
        Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                Render::DebugDrawManager::mInstance,
                                                1u);
        Render::DebugDrawContext::DrawTextA(Context, 80, 100, &UFG::qColour::White, mBuffer);
      }
    }
    else
    {
      while ( 1 )
      {
        v6 = UFG::qStringFind(mBuffer, "\n");
        if ( !v6 )
          break;
        mBuffer = v6 + 1;
        if ( ++v3 >= UFG::PredictiveStreaming::ms_iScrollActionController )
          goto LABEL_8;
      }
    }
    UFG::qStringBuilder::~qStringBuilder(&debugStringBuilder);
  }
}

// File Line: 160
// RVA: 0x3E9390
void __fastcall UFG::PredictiveStreaming::InitActionTree(UFG::PredictiveStreaming *this)
{
  ActionPath absolutePath; // [rsp+28h] [rbp-20h] BYREF

  absolutePath.mPath.mCount = 0;
  absolutePath.mPath.mData.mOffset = 0i64;
  ActionPath::Append(&absolutePath, "\\Global\\Streaming");
  this->m_pActionContext->m_OpeningBranch = ActionNode::Find(&absolutePath, 0i64);
  if ( absolutePath.mPath.mCount >= 0 && absolutePath.mPath.mData.mOffset )
  {
    if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
      operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
  }
}

