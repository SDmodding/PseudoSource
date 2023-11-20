// File Line: 32
// RVA: 0xA91F00
void __fastcall CAkVPLFilterNodeBase::VirtualOn(CAkVPLFilterNodeBase *this, AkVirtualQueueBehavior eBehavior)
{
  if ( eBehavior == AkVirtualQueueBehavior_FromBeginning )
    this->m_bLast = 0;
  if ( !this->m_bLast )
    ((void (*)(void))this->m_pInput->vfptr->VirtualOn)();
}

// File Line: 47
// RVA: 0xA91EE0
signed __int64 __fastcall CAkVPLFilterNodeBase::VirtualOff(CAkVPLFilterNodeBase *this, __int64 eBehavior, __int64 in_bUseSourceOffset)
{
  signed __int64 result; // rax

  if ( this->m_bLast )
    result = 1i64;
  else
    result = this->m_pInput->vfptr->VirtualOff(this->m_pInput, (AkVirtualQueueBehavior)eBehavior, in_bUseSourceOffset);
  return result;
}

// File Line: 60
// RVA: 0xA91D90
signed __int64 __fastcall CAkVPLFilterNodeBase::Init(CAkVPLFilterNodeBase *this, AK::IAkPlugin *in_pPlugin, AkFXDesc *in_fxDesc, unsigned int in_uFXIndex, CAkPBI *in_pCtx)
{
  CAkInsertFXContext *v5; // rdi
  CAkVPLFilterNodeBase *v6; // rbx
  unsigned int v7; // ebp
  AkFXDesc *v8; // r14
  AK::IAkPluginParam *v9; // rax
  CAkInsertFXContext *v10; // rax
  CAkInsertFXContext *v11; // rax

  this->m_uFXIndex = in_uFXIndex;
  v5 = 0i64;
  this->m_pInsertFXContext = 0i64;
  *(_WORD *)&this->m_bLast = 0;
  this->m_LastBypassed = 0;
  this->m_pCtx = in_pCtx;
  v6 = this;
  v7 = in_uFXIndex;
  v8 = in_fxDesc;
  v9 = (AK::IAkPluginParam *)in_fxDesc->pFx.m_pT->m_pParam->vfptr[1].__vecDelDtor(
                               (AK::IAkRTPCSubscriber *)in_fxDesc->pFx.m_pT->m_pParam,
                               (unsigned int)&AkFXMemAlloc::m_instanceLower);
  v6->m_pParam = v9;
  if ( !v9 )
    return 2i64;
  v6->m_FXID = v8->pFx.m_pT->m_FXID;
  v10 = (CAkInsertFXContext *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x28ui64);
  if ( v10 )
  {
    CAkInsertFXContext::CAkInsertFXContext(v10, in_pCtx, v7);
    v5 = v11;
  }
  v6->m_pInsertFXContext = v5;
  if ( !v5 )
    return 2i64;
  CAkFxBase::SubscribeRTPC(v8->pFx.m_pT, (AK::IAkRTPCSubscriber *)&v6->m_pParam->vfptr, in_pCtx->m_pGameObj);
  return 1i64;
}

// File Line: 93
// RVA: 0xA91E60
void __fastcall CAkVPLFilterNodeBase::Term(CAkVPLFilterNodeBase *this)
{
  AK::IAkPluginParam *v1; // rdx
  CAkVPLFilterNodeBase *v2; // rdi
  CAkInsertFXContext *v3; // rsi
  int v4; // ebx

  v1 = this->m_pParam;
  v2 = this;
  if ( v1 )
  {
    CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, v1);
    v2->m_pParam->vfptr[2].__vecDelDtor(
      (AK::IAkRTPCSubscriber *)&v2->m_pParam->vfptr,
      (unsigned int)&AkFXMemAlloc::m_instanceLower);
    v2->m_pParam = 0i64;
  }
  v3 = v2->m_pInsertFXContext;
  if ( v3 )
  {
    v4 = g_LEngineDefaultPoolId;
    v3->vfptr->__vecDelDtor((AK::IAkPluginContextBase *)&v2->m_pInsertFXContext->vfptr, 0);
    AK::MemoryMgr::Free(v4, v3);
    v2->m_pInsertFXContext = 0i64;
  }
}

