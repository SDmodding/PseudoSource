// File Line: 51
// RVA: 0xA99880
void __fastcall CAkSrcPhysModel::CAkSrcPhysModel(CAkSrcPhysModel *this, CAkPBI *in_pCtx)
{
  CAkSrcPhysModel *v2; // rbx

  v2 = this;
  CAkVPLSrcNode::CAkVPLSrcNode((CAkVPLSrcNode *)&this->vfptr, in_pCtx);
  v2->m_FXID = -1;
  v2->vfptr = (CAkVPLNodeVtbl *)&CAkSrcPhysModel::`vftable;
  v2->m_pParam = 0i64;
  v2->m_pEffect = 0i64;
  v2->m_pSourceFXContext = 0i64;
  v2->m_pluginBuffer.pData = 0i64;
  v2->m_pluginBuffer.uNumMarkers = 0;
  v2->m_pluginBuffer.pMarkers = 0i64;
  *(_QWORD *)&v2->m_pluginBuffer.eState = 43i64;
  v2->m_pluginBuffer.posInfo.uStartPos = -1;
  v2->m_pluginBuffer.posInfo.fLastRate = 1.0;
  v2->m_pluginBuffer.posInfo.uFileEnd = -1;
  v2->m_pluginBuffer.posInfo.uSampleRate = 1;
}

// File Line: 75
// RVA: 0xA99C90
signed __int64 __fastcall CAkSrcPhysModel::StartStream(CAkSrcPhysModel *this)
{
  CAkPBI *v1; // rax
  CAkSrcPhysModel *v2; // rbx
  CAkSourceFXContext *v3; // rsi
  CAkIndexable *v4; // rax
  CAkFxBase *v5; // rdi
  unsigned int v6; // edx
  AK::IAkPluginParam *v7; // rcx
  AK::IAkRTPCSubscriber *v8; // rax
  CAkSourceFXContext *v9; // rax
  CAkSourceFXContext *v10; // rax
  unsigned int v11; // ecx
  AkAudioFormat *v12; // rsi
  int v13; // eax
  unsigned int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  CAkPBI *v18; // rcx
  AK::IAkPlugin *out_pEffect; // [rsp+40h] [rbp+8h]
  char v21; // [rsp+48h] [rbp+10h]

  v1 = this->m_pCtx;
  v2 = this;
  v3 = 0i64;
  out_pEffect = 0i64;
  v4 = CAkIndexItem<CAkFxShareSet *>::GetPtrAndAddRef(
         (CAkIndexItem<CAkFxShareSet *> *)&g_pIndex->m_idxFxCustom,
         v1->m_pSource->m_sSrcTypeInfo.mediaInfo.sourceID);
  v5 = (CAkFxBase *)v4;
  if ( v4 )
  {
    v6 = (unsigned int)v4[1].vfptr;
    v2->m_FXID = v6;
    if ( (unsigned int)CAkEffectsMgr::Alloc(
                         (AK::IAkPluginMemAlloc *)&AkFXMemAlloc::m_instanceLower.vfptr,
                         v6,
                         &out_pEffect) == 1 )
    {
      v2->m_pEffect = (AK::IAkSourcePlugin *)out_pEffect;
      v7 = v5->m_pParam;
      if ( v7 )
      {
        v8 = (AK::IAkRTPCSubscriber *)v7->vfptr[1].__vecDelDtor(
                                        (AK::IAkRTPCSubscriber *)&v7->vfptr,
                                        (unsigned int)&AkFXMemAlloc::m_instanceLower);
        v2->m_pParam = (AK::IAkPluginParam *)v8;
        if ( !v8 )
          goto $failure;
        CAkFxBase::SubscribeRTPC(v5, v8, v2->m_pCtx->m_pGameObj);
      }
      v9 = (CAkSourceFXContext *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x20ui64);
      if ( v9 )
      {
        CAkSourceFXContext::CAkSourceFXContext(v9, v2->m_pCtx);
        v3 = v10;
      }
      v2->m_pSourceFXContext = v3;
      if ( !v3 )
        goto $failure;
      if ( *((_BYTE *)v2->m_pCtx + 374) >= 0 )
        v11 = AkAudioLibSettings::g_pipelineCoreFrequency;
      else
        v11 = (unsigned __int16)(signed int)(float)((float)((float)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency
                                                          * 0.0009765625)
                                                  * 8.0);
      v12 = &v2->m_AudioFormat;
      v12->uSampleRate = v11;
      *((_DWORD *)v12 + 1) = -1535115260;
      v2->m_pEffect->vfptr->GetPluginInfo((AK::IAkPlugin *)&v2->m_pEffect->vfptr, (AkPluginInfo *)&v21);
      v13 = ((__int64 (__fastcall *)(AK::IAkSourcePlugin *, AkFXMemAlloc *, CAkSourceFXContext *, AK::IAkPluginParam *, AkAudioFormat *))v2->m_pEffect->vfptr[1].__vecDelDtor)(
              v2->m_pEffect,
              &AkFXMemAlloc::m_instanceLower,
              v2->m_pSourceFXContext,
              v2->m_pParam,
              &v2->m_AudioFormat);
      v14 = *((_DWORD *)&v2->m_AudioFormat + 1) & 0x3FFFF;
      if ( v14 > 0x37 )
      {
        v15 = v14 - 59;
        if ( v15 )
        {
          v16 = v15 - 4;
          if ( v16 )
          {
            v17 = v16 - 1528;
            if ( v17 )
            {
              if ( v17 != 8 )
                goto $failure;
            }
          }
        }
      }
      else if ( v14 != 55 )
      {
        switch ( v14 )
        {
          case 3u:
          case 4u:
          case 7u:
          case 8u:
          case 0xBu:
          case 0xCu:
          case 0xFu:
          case 0x33u:
            goto $LN56_12;
          default:
            goto $failure;
        }
        goto $failure;
      }
$LN56_12:
      if ( v13 == 1 && ((unsigned int (*)(void))v2->m_pEffect->vfptr->Reset)() == 1 )
      {
        v18 = v2->m_pCtx;
        v18->m_sMediaFormat = *v12;
        CAkPBI::InvalidateFeedbackParameters(v18);
        v5->vfptr->Release((CAkIndexable *)&v5->vfptr);
        return 1i64;
      }
    }
  }
$failure:
  (*(void (__fastcall **)(CAkSrcPhysModel *))v2->vfptr[1].gap8)(v2);
  if ( v5 )
    v5->vfptr->Release((CAkIndexable *)&v5->vfptr);
  return 2i64;
}

// File Line: 202
// RVA: 0xA99F00
void __fastcall CAkSrcPhysModel::StopStream(CAkSrcPhysModel *this)
{
  CAkSrcPhysModel *v1; // rdi
  AK::IAkSourcePlugin *v2; // rcx
  CAkSourceFXContext *v3; // rsi
  int v4; // ebx
  AK::IAkPluginParam *v5; // rdx

  v1 = this;
  ((void (*)(void))this->vfptr->ReleaseBuffer)();
  v2 = v1->m_pEffect;
  if ( v2 )
  {
    v2->vfptr->Term((AK::IAkPlugin *)&v2->vfptr, (AK::IAkPluginMemAlloc *)&AkFXMemAlloc::m_instanceLower.vfptr);
    v1->m_pEffect = 0i64;
  }
  v3 = v1->m_pSourceFXContext;
  if ( v3 )
  {
    v4 = g_LEngineDefaultPoolId;
    v3->vfptr->__vecDelDtor((AK::IAkPluginContextBase *)&v1->m_pSourceFXContext->vfptr, 0);
    AK::MemoryMgr::Free(v4, v3);
    v1->m_pSourceFXContext = 0i64;
  }
  v5 = v1->m_pParam;
  if ( v5 )
  {
    CAkRTPCMgr::UnSubscribeRTPC(g_pRTPCMgr, v5);
    v1->m_pParam->vfptr[2].__vecDelDtor(
      (AK::IAkRTPCSubscriber *)&v1->m_pParam->vfptr,
      (unsigned int)&AkFXMemAlloc::m_instanceLower);
    v1->m_pParam = 0i64;
  }
}

// File Line: 229
// RVA: 0xA99AD0
void __fastcall CAkSrcPhysModel::GetBuffer(CAkSrcPhysModel *this, AkVPLState *io_state)
{
  AkVPLState *v2; // rbx
  CAkSrcPhysModel *v3; // rdi
  unsigned __int16 v4; // cx
  unsigned int v5; // eax
  void *v6; // rdx
  int v7; // esi
  void *v8; // rax

  v2 = io_state;
  v3 = this;
  if ( this->m_pEffect )
  {
    v4 = io_state->uMaxFrames;
    if ( !v4 )
    {
      io_state->result = 17;
      return;
    }
    v5 = *((_DWORD *)&v3->m_AudioFormat + 1);
    v6 = v3->m_pluginBuffer.pData;
    v7 = v5 & 0x3FFFF;
    if ( v6 )
    {
      v2->pData = v6;
    }
    else
    {
      if ( (v5 & 0x80000000) != 0 )
      {
        if ( (unsigned int)AkPipelineBufferBase::GetCachedBuffer((AkPipelineBufferBase *)&v2->pData, v4, v7) != 1 )
        {
LABEL_7:
          v2->result = 2;
          return;
        }
        goto LABEL_12;
      }
      v8 = CAkLEngine::GetCachedAudioBuffer(((v5 >> 24) & 0x1F) * v4);
      if ( !v8 )
        goto LABEL_7;
      v2->pData = v8;
    }
    v2->uChannelMask = v7;
    v2->uValidFrames = 0;
LABEL_12:
    v2->eState = 43;
    v3->m_pEffect->vfptr[2].__vecDelDtor((AK::IAkPlugin *)&v3->m_pEffect->vfptr, (unsigned int)v2);
    v2->result = v2->eState;
    v3->m_pluginBuffer.pData = v2->pData;
    *(_QWORD *)&v3->m_pluginBuffer.uChannelMask = *(_QWORD *)&v2->uChannelMask;
    *(_QWORD *)&v3->m_pluginBuffer.uMaxFrames = *(_QWORD *)&v2->uMaxFrames;
    *(_QWORD *)&v3->m_pluginBuffer.uNumMarkers = *(_QWORD *)&v2->uNumMarkers;
    v3->m_pluginBuffer.pMarkers = v2->pMarkers;
    *(_QWORD *)&v3->m_pluginBuffer.posInfo.uStartPos = *(_QWORD *)&v2->posInfo.uStartPos;
    *(_QWORD *)&v3->m_pluginBuffer.posInfo.uFileEnd = *(_QWORD *)&v2->posInfo.uFileEnd;
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
  io_state->result = 2;
}

// File Line: 331
// RVA: 0xA99C40
void __fastcall CAkSrcPhysModel::ReleaseBuffer(CAkSrcPhysModel *this)
{
  void *v1; // rdx
  AkPipelineBufferBase *v2; // rbx
  unsigned int v3; // ecx

  v1 = this->m_pluginBuffer.pData;
  v2 = (AkPipelineBufferBase *)&this->m_pluginBuffer.pData;
  if ( v1 )
  {
    v3 = *((_DWORD *)&this->m_AudioFormat + 1);
    if ( (v3 & 0x80000000) == 0 )
    {
      CAkLEngine::ReleaseCachedAudioBuffer(((v3 >> 24) & 0x1F) << 10, v1);
      v2->pData = 0i64;
    }
    else
    {
      AkPipelineBufferBase::ReleaseCachedBuffer(v2);
    }
  }
}

// File Line: 355
// RVA: 0xA99FE0
void __fastcall CAkSrcPhysModel::VirtualOn(CAkSrcPhysModel *this, AkVirtualQueueBehavior eBehavior)
{
  AK::IAkSourcePlugin *v2; // rcx

  if ( eBehavior == AkVirtualQueueBehavior_FromBeginning )
  {
    v2 = this->m_pEffect;
    if ( v2 )
      ((void (*)(void))v2->vfptr->Reset)();
  }
}

// File Line: 364
// RVA: 0xA99FA0
__int64 __fastcall CAkSrcPhysModel::TimeSkip(CAkSrcPhysModel *this, unsigned int *io_uFrames)
{
  CAkSrcPhysModel *v2; // rbx
  AK::IAkSourcePlugin *v3; // rcx
  unsigned int *v4; // rdi
  __int64 result; // rax

  v2 = this;
  v3 = this->m_pEffect;
  v4 = io_uFrames;
  result = 45i64;
  if ( v3 )
  {
    result = ((__int64 (*)(void))v3->vfptr[1].RelocateMedia)();
    if ( !(_DWORD)result )
      result = CAkVPLSrcNode::TimeSkip((CAkVPLSrcNode *)&v2->vfptr, v4);
  }
  return result;
}

// File Line: 398
// RVA: 0xA99C20
float __fastcall CAkSrcPhysModel::GetDuration(CAkSrcPhysModel *this)
{
  AK::IAkSourcePlugin *v1; // rcx
  float result; // xmm0_4

  v1 = this->m_pEffect;
  if ( !v1 )
    return 0.0;
  ((void (*)(void))v1->vfptr[1].Term)();
  return result;
}

// File Line: 407
// RVA: 0xA99A10
float __usercall CAkSrcPhysModel::GetAnalyzedEnvelope@<xmm0>(CAkSrcPhysModel *this@<rcx>, __int64 __formal@<rdx>, float a3@<xmm0>)
{
  AK::IAkSourcePlugin *v3; // rcx
  float v4; // xmm0_4
  float v5; // xmm2_4

  v3 = this->m_pEffect;
  if ( !v3 )
    return 0.0;
  ((void (__fastcall *)(AK::IAkSourcePlugin *, __int64))v3->vfptr[1].Reset)(v3, __formal);
  v4 = a3 + _real;
  v5 = (float)(COERCE_FLOAT((LODWORD(v4) & 0x7FFFFF) + 1065353216) - 1.0)
     / (float)(COERCE_FLOAT((LODWORD(v4) & 0x7FFFFF) + 1065353216) + 1.0);
  return (float)((float)((float)((float)((float)((float)(v5 * v5) * 0.33333334) + 1.0) * (float)(v5 * 2.0))
                       + (float)((float)((float)(unsigned __int8)(LODWORD(v4) >> 23) - 127.0) * 0.69314718))
               * 0.43429449)
       * 20.0;
}

// File Line: 420
// RVA: 0xA99EE0
__int64 __fastcall CAkSrcPhysModel::StopLooping(CAkSrcPhysModel *this)
{
  AK::IAkSourcePlugin *v1; // rcx
  __int64 result; // rax

  v1 = this->m_pEffect;
  if ( v1 )
    result = ((__int64 (*)(void))v1->vfptr[1].GetPluginInfo)();
  else
    result = 2i64;
  return result;
}

// File Line: 432
// RVA: 0xA99940
__int64 __usercall CAkSrcPhysModel::ChangeSourcePosition@<rax>(CAkSrcPhysModel *this@<rcx>, float a2@<xmm0>)
{
  CAkPBI *v2; // r8
  CAkSrcPhysModel *v3; // rbx
  __int64 v4; // rdx
  unsigned int v5; // edx

  v2 = this->m_pCtx;
  v3 = this;
  if ( *((_BYTE *)v2 + 375) & 4 )
  {
    ((void (*)(void))this->m_pEffect->vfptr[1].Term)();
    v2 = v3->m_pCtx;
    v4 = (unsigned int)(signed int)(float)((float)((float)(a2 * v2->m_fSeekPercent)
                                                 * (float)(signed int)v2->m_sMediaFormat.uSampleRate)
                                         * 0.001);
  }
  else
  {
    if ( *((_BYTE *)v2 + 374) >= 0 )
      v5 = AkAudioLibSettings::g_pipelineCoreFrequency;
    else
      v5 = (unsigned __int16)(signed int)(float)((float)((float)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency
                                                       * 0.0009765625)
                                               * 8.0);
    v4 = (unsigned int)(v2->m_sMediaFormat.uSampleRate * (unsigned __int64)v2->m_uSeekPosition / v5);
  }
  *((_BYTE *)v2 + 375) &= 0xF1u;
  v2->m_uSeekPosition = 0;
  return ((__int64 (__fastcall *)(AK::IAkSourcePlugin *, __int64))v3->m_pEffect->vfptr[1].SupportMediaRelocation)(
           v3->m_pEffect,
           v4);
}

