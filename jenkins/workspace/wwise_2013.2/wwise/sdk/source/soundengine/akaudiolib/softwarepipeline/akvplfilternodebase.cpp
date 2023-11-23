// File Line: 32
// RVA: 0xA91F00
void __fastcall CAkVPLFilterNodeBase::VirtualOn(CAkVPLFilterNodeBase *this, AkVirtualQueueBehavior eBehavior)
{
  if ( eBehavior == AkVirtualQueueBehavior_FromBeginning )
    this->m_bLast = 0;
  if ( !this->m_bLast )
    ((void (__fastcall *)(CAkVPLNode *))this->m_pInput->CAkVPLNode::vfptr->VirtualOn)(this->m_pInput);
}

// File Line: 47
// RVA: 0xA91EE0
__int64 __fastcall CAkVPLFilterNodeBase::VirtualOff(
        CAkVPLFilterNodeBase *this,
        __int64 eBehavior,
        __int64 in_bUseSourceOffset)
{
  if ( this->m_bLast )
    return 1i64;
  else
    return ((__int64 (__fastcall *)(CAkVPLNode *, __int64, __int64))this->m_pInput->CAkVPLNode::vfptr->VirtualOff)(
             this->m_pInput,
             eBehavior,
             in_bUseSourceOffset);
}

// File Line: 60
// RVA: 0xA91D90
__int64 __fastcall CAkVPLFilterNodeBase::Init(
        CAkVPLFilterNodeBase *this,
        AK::IAkPlugin *in_pPlugin,
        AkFXDesc *in_fxDesc,
        unsigned int in_uFXIndex,
        CAkPBI *in_pCtx)
{
  CAkInsertFXContext *v5; // rdi
  AK::IAkPluginParam *v9; // rax
  CAkInsertFXContext *v10; // rax
  CAkInsertFXContext *v11; // rax

  this->m_uFXIndex = in_uFXIndex;
  v5 = 0i64;
  this->m_pInsertFXContext = 0i64;
  *(_WORD *)&this->m_bLast = 0;
  this->m_LastBypassed = 0;
  this->m_pCtx = in_pCtx;
  v9 = (AK::IAkPluginParam *)in_fxDesc->pFx.m_pT->m_pParam->vfptr[1].__vecDelDtor(
                               in_fxDesc->pFx.m_pT->m_pParam,
                               &AkFXMemAlloc::m_instanceLower);
  this->m_pParam = v9;
  if ( !v9 )
    return 2i64;
  this->m_FXID = in_fxDesc->pFx.m_pT->m_FXID;
  v10 = (CAkInsertFXContext *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x28ui64);
  if ( v10 )
  {
    CAkInsertFXContext::CAkInsertFXContext(v10, in_pCtx, in_uFXIndex);
    v5 = v11;
  }
  this->m_pInsertFXContext = v5;
  if ( !v5 )
    return 2i64;
  CAkFxBase::SubscribeRTPC(in_fxDesc->pFx.m_pT, this->m_pParam, in_pCtx->m_pGameObj);
  return 1i64;
}

// File Line: 93
// RVA: 0xA91E60
void __fastcall CAkVPLFilterNodeBase::Term(CAkVPLFilterNodeBase *this)
{
  AK::IAkPluginParam *m_pParam; // rdx
  CAkInsertFXContext *m_pInsertFXContext; // rsi
  int v4; // ebx

  m_pParam = this->m_pParam;
  if ( m_pParam )
  {
    CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, m_pParam);
    this->m_pParam->vfptr[2].__vecDelDtor(this->m_pParam, (unsigned int)&AkFXMemAlloc::m_instanceLower);
    this->m_pParam = 0i64;
  }
  m_pInsertFXContext = this->m_pInsertFXContext;
  if ( m_pInsertFXContext )
  {
    v4 = g_LEngineDefaultPoolId;
    m_pInsertFXContext->vfptr->__vecDelDtor(this->m_pInsertFXContext, 0);
    AK::MemoryMgr::Free(v4, m_pInsertFXContext);
    this->m_pInsertFXContext = 0i64;
  }
}

