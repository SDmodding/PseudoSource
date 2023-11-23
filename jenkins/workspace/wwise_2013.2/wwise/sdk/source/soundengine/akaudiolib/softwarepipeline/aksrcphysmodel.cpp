// File Line: 51
// RVA: 0xA99880
void __fastcall CAkSrcPhysModel::CAkSrcPhysModel(CAkSrcPhysModel *this, CAkPBI *in_pCtx)
{
  CAkVPLSrcNode::CAkVPLSrcNode(this, in_pCtx);
  this->m_FXID = -1;
  this->vfptr = (CAkVPLNodeVtbl *)&CAkSrcPhysModel::`vftable;
  this->m_pParam = 0i64;
  this->m_pEffect = 0i64;
  this->m_pSourceFXContext = 0i64;
  this->m_pluginBuffer.pData = 0i64;
  this->m_pluginBuffer.uNumMarkers = 0;
  this->m_pluginBuffer.pMarkers = 0i64;
  *(_QWORD *)&this->m_pluginBuffer.eState = 43i64;
  this->m_pluginBuffer.posInfo.uStartPos = -1;
  this->m_pluginBuffer.posInfo.fLastRate = 1.0;
  this->m_pluginBuffer.posInfo.uFileEnd = -1;
  this->m_pluginBuffer.posInfo.uSampleRate = 1;
}

// File Line: 75
// RVA: 0xA99C90
__int64 __fastcall CAkSrcPhysModel::StartStream(CAkSrcPhysModel *this)
{
  CAkPBI *m_pCtx; // rax
  CAkSourceFXContext *v3; // rsi
  CAkIndexable *PtrAndAddRef; // rax
  CAkFxBase *v5; // rdi
  unsigned int vfptr; // edx
  AK::IAkPluginParam *m_pParam; // rcx
  AK::IAkPluginParam *v8; // rax
  CAkSourceFXContext *v9; // rax
  CAkSourceFXContext *v10; // rax
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // ecx
  CAkPBI *v17; // rcx
  AK::IAkPlugin *out_pEffect; // [rsp+40h] [rbp+8h] BYREF
  char v20; // [rsp+48h] [rbp+10h] BYREF

  m_pCtx = this->m_pCtx;
  v3 = 0i64;
  out_pEffect = 0i64;
  PtrAndAddRef = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
                   (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxFxCustom,
                   m_pCtx->m_pSource->m_sSrcTypeInfo.mediaInfo.sourceID);
  v5 = (CAkFxBase *)PtrAndAddRef;
  if ( PtrAndAddRef )
  {
    vfptr = (unsigned int)PtrAndAddRef[1].vfptr;
    this->m_FXID = vfptr;
    if ( (unsigned int)CAkEffectsMgr::Alloc(&AkFXMemAlloc::m_instanceLower, vfptr, &out_pEffect) == 1 )
    {
      this->m_pEffect = (AK::IAkSourcePlugin *)out_pEffect;
      m_pParam = v5->m_pParam;
      if ( m_pParam )
      {
        v8 = (AK::IAkPluginParam *)m_pParam->vfptr[1].__vecDelDtor(
                                     m_pParam,
                                     (unsigned int)&AkFXMemAlloc::m_instanceLower);
        this->m_pParam = v8;
        if ( !v8 )
          goto $failure;
        CAkFxBase::SubscribeRTPC(v5, v8, this->m_pCtx->m_pGameObj);
      }
      v9 = (CAkSourceFXContext *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x20ui64);
      if ( v9 )
      {
        CAkSourceFXContext::CAkSourceFXContext(v9, this->m_pCtx);
        v3 = v10;
      }
      this->m_pSourceFXContext = v3;
      if ( !v3 )
        goto $failure;
      if ( *((char *)this->m_pCtx + 374) >= 0 )
        v11 = AkAudioLibSettings::g_pipelineCoreFrequency;
      else
        v11 = (unsigned __int16)(int)(float)((float)((float)(int)AkAudioLibSettings::g_pipelineCoreFrequency
                                                   * 0.0009765625)
                                           * 8.0);
      this->m_AudioFormat.uSampleRate = v11;
      *((_DWORD *)&this->m_AudioFormat + 1) = -1535115260;
      this->m_pEffect->vfptr->GetPluginInfo(this->m_pEffect, (AkPluginInfo *)&v20);
      v12 = ((__int64 (__fastcall *)(AK::IAkSourcePlugin *, AkFXMemAlloc *, CAkSourceFXContext *, AK::IAkPluginParam *, AkAudioFormat *))this->m_pEffect->vfptr[1].__vecDelDtor)(
              this->m_pEffect,
              &AkFXMemAlloc::m_instanceLower,
              this->m_pSourceFXContext,
              this->m_pParam,
              &this->m_AudioFormat);
      v13 = *((_DWORD *)&this->m_AudioFormat + 1) & 0x3FFFF;
      if ( v13 > 0x37 )
      {
        v14 = v13 - 59;
        if ( v14 )
        {
          v15 = v14 - 4;
          if ( v15 )
          {
            v16 = v15 - 1528;
            if ( v16 )
            {
              if ( v16 != 8 )
                goto $failure;
            }
          }
        }
      }
      else if ( v13 != 55 )
      {
        switch ( v13 )
        {
          case 3u:
          case 4u:
          case 7u:
          case 8u:
          case 0xBu:
          case 0xCu:
          case 0xFu:
          case 0x33u:
            break;
          default:
            goto $failure;
        }
      }
      if ( v12 == 1 && this->m_pEffect->vfptr->Reset(this->m_pEffect) == AK_Success )
      {
        v17 = this->m_pCtx;
        v17->m_sMediaFormat = this->m_AudioFormat;
        CAkPBI::InvalidateFeedbackParameters(v17);
        v5->vfptr->Release(v5);
        return 1i64;
      }
    }
  }
$failure:
  (*(void (__fastcall **)(CAkSrcPhysModel *))this->vfptr[1].gap8)(this);
  if ( v5 )
    v5->vfptr->Release(v5);
  return 2i64;
}

// File Line: 202
// RVA: 0xA99F00
void __fastcall CAkSrcPhysModel::StopStream(CAkSrcPhysModel *this)
{
  AK::IAkSourcePlugin *m_pEffect; // rcx
  CAkSourceFXContext *m_pSourceFXContext; // rsi
  int v4; // ebx
  AK::IAkPluginParam *m_pParam; // rdx

  ((void (*)(void))this->vfptr->ReleaseBuffer)();
  m_pEffect = this->m_pEffect;
  if ( m_pEffect )
  {
    m_pEffect->vfptr->Term(m_pEffect, &AkFXMemAlloc::m_instanceLower);
    this->m_pEffect = 0i64;
  }
  m_pSourceFXContext = this->m_pSourceFXContext;
  if ( m_pSourceFXContext )
  {
    v4 = g_LEngineDefaultPoolId;
    m_pSourceFXContext->vfptr->__vecDelDtor(this->m_pSourceFXContext, 0);
    AK::MemoryMgr::Free(v4, m_pSourceFXContext);
    this->m_pSourceFXContext = 0i64;
  }
  m_pParam = this->m_pParam;
  if ( m_pParam )
  {
    CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, m_pParam);
    this->m_pParam->vfptr[2].__vecDelDtor(this->m_pParam, (unsigned int)&AkFXMemAlloc::m_instanceLower);
    this->m_pParam = 0i64;
  }
}

// File Line: 229
// RVA: 0xA99AD0
void __fastcall CAkSrcPhysModel::GetBuffer(CAkSrcPhysModel *this, AkVPLState *io_state)
{
  unsigned __int16 uMaxFrames; // cx
  int v5; // eax
  void *pData; // rdx
  int v7; // esi
  void *CachedAudioBuffer; // rax

  if ( this->m_pEffect )
  {
    uMaxFrames = io_state->uMaxFrames;
    if ( !uMaxFrames )
    {
      io_state->result = AK_NoMoreData;
      return;
    }
    v5 = *((_DWORD *)&this->m_AudioFormat + 1);
    pData = this->m_pluginBuffer.pData;
    v7 = v5 & 0x3FFFF;
    if ( pData )
    {
      io_state->pData = pData;
    }
    else
    {
      if ( v5 < 0 )
      {
        if ( (unsigned int)AkPipelineBufferBase::GetCachedBuffer(io_state, uMaxFrames, v7) != 1 )
        {
LABEL_7:
          io_state->result = AK_Fail;
          return;
        }
        goto LABEL_12;
      }
      CachedAudioBuffer = CAkLEngine::GetCachedAudioBuffer((HIBYTE(v5) & 0x1F) * uMaxFrames);
      if ( !CachedAudioBuffer )
        goto LABEL_7;
      io_state->pData = CachedAudioBuffer;
    }
    io_state->uChannelMask = v7;
    io_state->uValidFrames = 0;
LABEL_12:
    io_state->eState = AK_DataNeeded;
    this->m_pEffect->vfptr[2].__vecDelDtor(this->m_pEffect, (unsigned int)io_state);
    io_state->result = io_state->eState;
    this->m_pluginBuffer.pData = io_state->pData;
    *(_QWORD *)&this->m_pluginBuffer.uChannelMask = *(_QWORD *)&io_state->uChannelMask;
    *(_QWORD *)&this->m_pluginBuffer.uMaxFrames = *(_QWORD *)&io_state->uMaxFrames;
    *(_QWORD *)&this->m_pluginBuffer.uNumMarkers = *(_QWORD *)&io_state->uNumMarkers;
    this->m_pluginBuffer.pMarkers = io_state->pMarkers;
    *(_QWORD *)&this->m_pluginBuffer.posInfo.uStartPos = *(_QWORD *)&io_state->posInfo.uStartPos;
    *(_QWORD *)&this->m_pluginBuffer.posInfo.uFileEnd = *(_QWORD *)&io_state->posInfo.uFileEnd;
    return;
  }
  *(_QWORD *)&io_state->eState = 43i64;
  io_state->pData = 0i64;
  io_state->uNumMarkers = 0;
  io_state->pMarkers = 0i64;
  io_state->posInfo.uStartPos = -1;
  io_state->posInfo.fLastRate = 1.0;
  io_state->posInfo.uFileEnd = -1;
  io_state->posInfo.uSampleRate = 1;
  io_state->result = AK_Fail;
}

// File Line: 331
// RVA: 0xA99C40
void __fastcall CAkSrcPhysModel::ReleaseBuffer(CAkSrcPhysModel *this)
{
  void *pData; // rdx
  AkPipelineBuffer *p_m_pluginBuffer; // rbx
  int v3; // ecx

  pData = this->m_pluginBuffer.pData;
  p_m_pluginBuffer = &this->m_pluginBuffer;
  if ( pData )
  {
    v3 = *((_DWORD *)&this->m_AudioFormat + 1);
    if ( v3 >= 0 )
    {
      CAkLEngine::ReleaseCachedAudioBuffer((HIBYTE(v3) & 0x1F) << 10, pData);
      p_m_pluginBuffer->pData = 0i64;
    }
    else
    {
      AkPipelineBufferBase::ReleaseCachedBuffer(p_m_pluginBuffer);
    }
  }
}

// File Line: 355
// RVA: 0xA99FE0
void __fastcall CAkSrcPhysModel::VirtualOn(CAkSrcPhysModel *this, AkVirtualQueueBehavior eBehavior)
{
  AK::IAkSourcePlugin *m_pEffect; // rcx

  if ( eBehavior == AkVirtualQueueBehavior_FromBeginning )
  {
    m_pEffect = this->m_pEffect;
    if ( m_pEffect )
      m_pEffect->vfptr->Reset(m_pEffect);
  }
}

// File Line: 364
// RVA: 0xA99FA0
__int64 __fastcall CAkSrcPhysModel::TimeSkip(CAkSrcPhysModel *this, unsigned int *io_uFrames)
{
  AK::IAkSourcePlugin *m_pEffect; // rcx
  __int64 result; // rax

  m_pEffect = this->m_pEffect;
  result = 45i64;
  if ( m_pEffect )
  {
    result = ((__int64 (__fastcall *)(AK::IAkSourcePlugin *))m_pEffect->vfptr[1].RelocateMedia)(m_pEffect);
    if ( !(_DWORD)result )
      return CAkVPLSrcNode::TimeSkip(this, io_uFrames);
  }
  return result;
}

// File Line: 398
// RVA: 0xA99C20
float __fastcall CAkSrcPhysModel::GetDuration(CAkSrcPhysModel *this)
{
  AK::IAkSourcePlugin *m_pEffect; // rcx
  float result; // xmm0_4

  m_pEffect = this->m_pEffect;
  if ( !m_pEffect )
    return 0.0;
  ((void (__fastcall *)(AK::IAkSourcePlugin *))m_pEffect->vfptr[1].Term)(m_pEffect);
  return result;
}

// File Line: 407
// RVA: 0xA99A10
float __fastcall CAkSrcPhysModel::GetAnalyzedEnvelope(CAkSrcPhysModel *this, __int64 __formal)
{
  AK::IAkSourcePlugin *m_pEffect; // rcx
  float v3; // xmm2_4
  float v5; // [rsp+30h] [rbp+8h]

  m_pEffect = this->m_pEffect;
  if ( !m_pEffect )
    return 0.0;
  v5 = ((float (__fastcall *)(AK::IAkSourcePlugin *, __int64))m_pEffect->vfptr[1].Reset)(m_pEffect, __formal) + _real;
  v3 = (float)(COERCE_FLOAT((LODWORD(v5) & 0x7FFFFF) + 1065353216) - 1.0)
     / (float)(COERCE_FLOAT((LODWORD(v5) & 0x7FFFFF) + 1065353216) + 1.0);
  return (float)((float)((float)((float)((float)((float)(v3 * v3) * 0.33333334) + 1.0) * (float)(v3 * 2.0))
                       + (float)((float)((float)(unsigned __int8)(LODWORD(v5) >> 23) - 127.0) * 0.69314718))
               * 0.43429449)
       * 20.0;
}

// File Line: 420
// RVA: 0xA99EE0
__int64 __fastcall CAkSrcPhysModel::StopLooping(CAkSrcPhysModel *this)
{
  AK::IAkSourcePlugin *m_pEffect; // rcx

  m_pEffect = this->m_pEffect;
  if ( m_pEffect )
    return ((__int64 (__fastcall *)(AK::IAkSourcePlugin *))m_pEffect->vfptr[1].GetPluginInfo)(m_pEffect);
  else
    return 2i64;
}

// File Line: 432
// RVA: 0xA99940
__int64 __fastcall CAkSrcPhysModel::ChangeSourcePosition(CAkSrcPhysModel *this)
{
  CAkPBI *m_pCtx; // r8
  float v3; // xmm0_4
  __int64 v4; // rdx
  unsigned int v5; // edx

  m_pCtx = this->m_pCtx;
  if ( (*((_BYTE *)m_pCtx + 375) & 4) != 0 )
  {
    v3 = ((float (__fastcall *)(AK::IAkSourcePlugin *))this->m_pEffect->vfptr[1].Term)(this->m_pEffect);
    m_pCtx = this->m_pCtx;
    v4 = (unsigned int)(int)(float)((float)((float)(v3 * m_pCtx->m_fSeekPercent)
                                          * (float)(int)m_pCtx->m_sMediaFormat.uSampleRate)
                                  * 0.001);
  }
  else
  {
    if ( *((char *)m_pCtx + 374) >= 0 )
      v5 = AkAudioLibSettings::g_pipelineCoreFrequency;
    else
      v5 = (unsigned __int16)(int)(float)((float)((float)(int)AkAudioLibSettings::g_pipelineCoreFrequency * 0.0009765625)
                                        * 8.0);
    v4 = (unsigned int)(m_pCtx->m_sMediaFormat.uSampleRate * (unsigned __int64)m_pCtx->m_uSeekPosition / v5);
  }
  *((_BYTE *)m_pCtx + 375) &= 0xF1u;
  m_pCtx->m_uSeekPosition = 0;
  return ((__int64 (__fastcall *)(AK::IAkSourcePlugin *, __int64))this->m_pEffect->vfptr[1].SupportMediaRelocation)(
           this->m_pEffect,
           v4);
}

