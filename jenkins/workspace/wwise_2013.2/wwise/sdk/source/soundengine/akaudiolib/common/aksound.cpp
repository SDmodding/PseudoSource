// File Line: 42
// RVA: 0xA79620
CAkSound *__fastcall CAkSound::Create(unsigned int in_ulID)
{
  CAkSound *result; // rax
  CAkSound *v3; // rbx
  unsigned int v4; // eax
  int v5; // ecx
  bool v6; // al

  result = (CAkSound *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xC0ui64);
  v3 = result;
  if ( result )
  {
    CAkSoundBase::CAkSoundBase(result, in_ulID);
    v3->vfptr = (CAkIndexableVtbl *)&CAkSound::`vftable;
    CAkSource::CAkSource(&v3->m_Source);
    v4 = v3->vfptr[3].Release(v3);
    v6 = 0;
    if ( v4 <= 0xC )
    {
      v5 = 5121;
      if ( _bittest(&v5, v4) )
        v6 = 1;
    }
    *((_BYTE *)&v3->CAkParameterNodeBase + 83) &= ~2u;
    *((_BYTE *)&v3->CAkParameterNodeBase + 83) |= 2 * v6;
    CAkParameterNodeBase::AddToIndex(v3);
    return v3;
  }
  return result;
}

// File Line: 60
// RVA: 0xA79890
AKRESULT __fastcall CAkSound::PlayInternal(CAkSound *this, AkPBIParams *in_rPBIParams)
{
  return CAkURenderer::Play(this, &this->m_Source, in_rPBIParams);
}

// File Line: 66
// RVA: 0xA796B0
__int64 __fastcall CAkSound::ExecuteAction(CAkSound *this, SeekActionParams *in_rAction)
{
  SeekActionParams *v2; // rbx
  AkActivityChunk *m_pActivityChunk; // rax

  v2 = in_rAction;
  if ( in_rAction->bIsMasterCall )
  {
    LOBYTE(in_rAction) = in_rAction->eType == ActionParamType_Pause;
    ((void (__fastcall *)(CAkSound *, SeekActionParams *))this->vfptr[10].Category)(this, in_rAction);
  }
  m_pActivityChunk = this->m_pActivityChunk;
  if ( !m_pActivityChunk || !m_pActivityChunk->m_PlayCount )
    return 1i64;
  switch ( v2->eType )
  {
    case ActionParamType_Stop:
      return CAkURenderer::Stop(this, v2->pGameObj, &v2->transParams, v2->playingID);
    case ActionParamType_Pause:
      return CAkURenderer::Pause(this, v2->pGameObj, &v2->transParams, v2->playingID);
    case ActionParamType_Resume:
      return CAkURenderer::Resume(this, v2->pGameObj, &v2->transParams, v2->bIsMasterResume, v2->playingID);
  }
  if ( v2->eType != ActionParamType_Break )
  {
    if ( v2->eType == ActionParamType_Seek )
      CAkSound::SeekSound(this, v2->pGameObj, v2);
    return 1i64;
  }
  ((void (__fastcall *)(CAkSound *, CAkRegisteredObj *, CAkParameterNodeBase *, _QWORD))this->vfptr[4].Category)(
    this,
    v2->pGameObj,
    v2->targetNodePtr,
    v2->playingID);
  return 1i64;
}

// File Line: 100
// RVA: 0xA797B0
__int64 __fastcall CAkSound::ExecuteActionExcept(CAkSound *this, SeekActionParamsExcept *in_rAction)
{
  SeekActionParamsExcept *v2; // rbx
  AkActivityChunk *m_pActivityChunk; // rax

  v2 = in_rAction;
  if ( !in_rAction->pGameObj )
  {
    LOBYTE(in_rAction) = in_rAction->eType == ActionParamType_Pause;
    ((void (__fastcall *)(CAkSound *, SeekActionParamsExcept *))this->vfptr[10].Category)(this, in_rAction);
  }
  m_pActivityChunk = this->m_pActivityChunk;
  if ( !m_pActivityChunk || !m_pActivityChunk->m_PlayCount )
    return 1i64;
  if ( v2->eType == ActionParamType_Stop )
    return CAkURenderer::Stop(this, v2->pGameObj, &v2->transParams, v2->playingID);
  if ( v2->eType == ActionParamType_Pause )
    return CAkURenderer::Pause(this, v2->pGameObj, &v2->transParams, v2->playingID);
  if ( v2->eType != ActionParamType_Resume )
  {
    if ( v2->eType == ActionParamType_Seek )
      CAkSound::SeekSound(this, v2->pGameObj, v2);
    return 1i64;
  }
  return CAkURenderer::Resume(this, v2->pGameObj, &v2->transParams, v2->bIsMasterResume, v2->playingID);
}

// File Line: 132
// RVA: 0xA798B0
void __fastcall CAkSound::SeekSound(CAkSound *this, CAkRegisteredObj *in_pGameObj, SeekActionParams *in_rActionParams)
{
  AkActivityChunk *m_pActivityChunk; // rbx
  CAkPBI *i; // rbx
  unsigned int playingID; // eax
  AkActivityChunk *v8; // rbx
  int iSeekTime; // ebp
  CAkPBI *j; // rbx
  unsigned int v11; // eax

  if ( (*((_BYTE *)in_rActionParams + 44) & 1) != 0 )
  {
    m_pActivityChunk = this->m_pActivityChunk;
    if ( m_pActivityChunk )
    {
      for ( i = m_pActivityChunk->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
      {
        playingID = in_rActionParams->playingID;
        if ( (!in_pGameObj || in_pGameObj == i->m_pGameObj) && (!playingID || playingID == i->m_UserParams.m_PlayingID) )
          ((void (__fastcall *)(CAkPBI *, CAkRegisteredObj *, bool))i->CAkTransportAware::vfptr[4].~CAkTransportAware)(
            i,
            in_pGameObj,
            (*((_BYTE *)in_rActionParams + 44) & 2) != 0);
      }
    }
  }
  else
  {
    v8 = this->m_pActivityChunk;
    iSeekTime = in_rActionParams->iSeekTime;
    if ( iSeekTime < 0 )
      iSeekTime = 0;
    if ( v8 )
    {
      for ( j = v8->m_listPBI.m_pFirst; j; j = j->pNextLightItem )
      {
        v11 = in_rActionParams->playingID;
        if ( (!in_pGameObj || in_pGameObj == j->m_pGameObj) && (!v11 || v11 == j->m_UserParams.m_PlayingID) )
          ((void (__fastcall *)(CAkPBI *, _QWORD, bool))j->CAkTransportAware::vfptr[4]._Stop)(
            j,
            (unsigned int)iSeekTime,
            (*((_BYTE *)in_rActionParams + 44) & 2) != 0);
      }
    }
  }
}

// File Line: 182
// RVA: 0xA799D0
void __fastcall CAkSound::SeekSound(
        CAkSound *this,
        CAkRegisteredObj *in_pGameObj,
        SeekActionParamsExcept *in_rActionParams)
{
  AkActivityChunk *m_pActivityChunk; // rbx
  CAkPBI *i; // rbx
  AkActivityChunk *v7; // rbx
  int iSeekTime; // ebp
  CAkPBI *j; // rbx

  if ( (*((_BYTE *)in_rActionParams + 44) & 1) != 0 )
  {
    m_pActivityChunk = this->m_pActivityChunk;
    if ( m_pActivityChunk )
    {
      for ( i = m_pActivityChunk->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
      {
        if ( !in_pGameObj || i->m_pGameObj == in_pGameObj )
          ((void (__fastcall *)(CAkPBI *, CAkRegisteredObj *, bool))i->CAkTransportAware::vfptr[4].~CAkTransportAware)(
            i,
            in_pGameObj,
            (*((_BYTE *)in_rActionParams + 44) & 2) != 0);
      }
    }
  }
  else
  {
    v7 = this->m_pActivityChunk;
    iSeekTime = in_rActionParams->iSeekTime;
    if ( iSeekTime < 0 )
      iSeekTime = 0;
    if ( v7 )
    {
      for ( j = v7->m_listPBI.m_pFirst; j; j = j->pNextLightItem )
      {
        if ( !in_pGameObj || j->m_pGameObj == in_pGameObj )
          ((void (__fastcall *)(CAkPBI *, _QWORD, bool))j->CAkTransportAware::vfptr[4]._Stop)(
            j,
            (unsigned int)iSeekTime,
            (*((_BYTE *)in_rActionParams + 44) & 2) != 0);
      }
    }
  }
}

// File Line: 251
// RVA: 0xA79AD0
__int64 __fastcall CAkSound::SetInitialValues(
        CAkSound *this,
        char *in_pData,
        unsigned int in_ulDataSize,
        CAkUsageSlot *__formal,
        bool in_bIsPartialLoadOnly)
{
  __int64 result; // rax
  CAkSource *p_m_Source; // rcx
  AkMediaInformation m_MediaInfo; // [rsp+20h] [rbp-58h] BYREF
  AkBankSourceData v9; // [rsp+40h] [rbp-38h] BYREF
  char *io_rpData; // [rsp+88h] [rbp+10h] BYREF
  unsigned int io_rulDataSize; // [rsp+90h] [rbp+18h] BYREF

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData + 4;
  result = CAkBankMgr::LoadSource(&io_rpData, &io_rulDataSize, &v9);
  if ( (_DWORD)result == 1 )
  {
    p_m_Source = &this->m_Source;
    if ( v9.m_pParam )
    {
      CAkSource::SetSource(p_m_Source, v9.m_MediaInfo.sourceID);
    }
    else
    {
      m_MediaInfo = v9.m_MediaInfo;
      CAkSource::SetSource(p_m_Source, v9.m_PluginID, &m_MediaInfo);
    }
    return CAkParameterNodeBase::SetNodeBaseParams(this, &io_rpData, &io_rulDataSize, in_bIsPartialLoadOnly);
  }
  return result;
}

// File Line: 293
// RVA: 0xA798A0
signed __int64 __fastcall CAkSound::PrepareData(CAkSound *this)
{
  return CAkSource::PrepareData(&this->m_Source);
}

// File Line: 298
// RVA: 0xA79B60
void __fastcall CAkSound::UnPrepareData(CAkSound *this)
{
  CAkSource::UnPrepareData(&this->m_Source);
}

