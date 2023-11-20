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
  UFG::PredictiveStreaming *v1; // rbx
  ActionController *v2; // rdi
  ActionContext *v3; // rax

  v1 = this;
  v2 = &this->m_ActionController;
  ActionController::ActionController(&this->m_ActionController);
  v3 = (ActionContext *)UFG::qMalloc(0xD8ui64, "ActionTreeComponent::ActionContext.PredictiveStreaming", 0i64);
  if ( v3 )
    ActionContext::ActionContext(v3);
  v1->m_pActionContext = v3;
  v1->m_ActionController.m_Context = v3;
  v3->mActionController = v2;
  UFG::PredictiveStreaming::InitActionTree(v1);
}

// File Line: 77
// RVA: 0x3EABD0
void __fastcall UFG::PredictiveStreaming::Update(UFG::PredictiveStreaming *this, const float fTimeDeltaS)
{
  ActionController *v2; // rsi
  int v3; // edi
  bool v4; // bl
  char *v5; // rbx
  char *v6; // rax
  Render::DebugDrawContext *v7; // rax
  UFG::qStringBuilder debugStringBuilder; // [rsp+38h] [rbp-20h]

  v2 = &this->m_ActionController;
  ActionController::Update(&this->m_ActionController, fTimeDeltaS);
  if ( UFG::PredictiveStreaming::ms_bDrawActionController )
  {
    UFG::qStringBuilder::qStringBuilder(&debugStringBuilder);
    v3 = 0;
    if ( UFG::PredictiveStreaming::ms_bShowTracksActionController )
    {
      v4 = gReflectOnlyOpportunities;
      gReflectOnlyOpportunities = 0;
      ActionController::GetDebugString(v2, &debugStringBuilder, 1, 0i64, 0i64);
      gReflectOnlyOpportunities = v4;
    }
    else
    {
      ActionController::GetDebugString(v2, &debugStringBuilder, 0, 0i64, 0i64);
    }
    v5 = debugStringBuilder.mBuffer;
    if ( UFG::PredictiveStreaming::ms_iScrollActionController <= 0 )
    {
LABEL_8:
      if ( v5 )
      {
        v7 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
        Render::DebugDrawContext::DrawTextA(v7, 80, 100, &UFG::qColour::White, v5);
      }
    }
    else
    {
      while ( 1 )
      {
        v6 = UFG::qStringFind(v5, "\n");
        if ( !v6 )
          break;
        v5 = v6 + 1;
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
  UFG::PredictiveStreaming *v1; // rbx
  ActionPath absolutePath; // [rsp+28h] [rbp-20h]

  v1 = this;
  absolutePath.mPath.mCount = 0;
  absolutePath.mPath.mData.mOffset = 0i64;
  ActionPath::Append(&absolutePath, "\\Global\\Streaming");
  v1->m_pActionContext->m_OpeningBranch = ActionNode::Find(&absolutePath, 0i64);
  if ( absolutePath.mPath.mCount >= 0 && absolutePath.mPath.mData.mOffset )
  {
    if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
      operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
  }
}

