// File Line: 42
// RVA: 0xA79620
CAkSound *__fastcall CAkSound::Create(unsigned int in_ulID)
{
  unsigned int v1; // edi
  CAkSound *result; // rax
  CAkSound *v3; // rbx
  unsigned int v4; // eax
  signed int v5; // ecx
  bool v6; // al

  v1 = in_ulID;
  result = (CAkSound *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xC0ui64);
  v3 = result;
  if ( result )
  {
    CAkSoundBase::CAkSoundBase((CAkSoundBase *)&result->vfptr, v1);
    v3->vfptr = (CAkIndexableVtbl *)&CAkSound::`vftable';
    CAkSource::CAkSource(&v3->m_Source);
    v4 = v3->vfptr[3].Release((CAkIndexable *)&v3->vfptr);
    v6 = 0;
    if ( v4 <= 0xC )
    {
      v5 = 5121;
      if ( _bittest(&v5, v4) )
        v6 = 1;
    }
    *((_BYTE *)&v3->0 + 83) &= 0xFDu;
    *((_BYTE *)&v3->0 + 83) |= 2 * v6;
    CAkParameterNodeBase::AddToIndex((CAkParameterNodeBase *)&v3->vfptr);
    result = v3;
  }
  return result;
}

// File Line: 60
// RVA: 0xA79890
AKRESULT __fastcall CAkSound::PlayInternal(CAkSound *this, AkPBIParams *in_rPBIParams)
{
  return CAkURenderer::Play((CAkSoundBase *)&this->vfptr, &this->m_Source, in_rPBIParams);
}

// File Line: 66
// RVA: 0xA796B0
signed __int64 __fastcall CAkSound::ExecuteAction(CAkSound *this, ActionParams *in_rAction)
{
  SeekActionParams *v2; // rbx
  CAkSound *v3; // rdi
  AkActivityChunk *v4; // rax

  v2 = (SeekActionParams *)in_rAction;
  v3 = this;
  if ( in_rAction->bIsMasterCall )
  {
    LOBYTE(in_rAction) = in_rAction->eType == 1;
    ((void (__fastcall *)(CAkSound *, ActionParams *))this->vfptr[10].Category)(this, in_rAction);
  }
  v4 = v3->m_pActivityChunk;
  if ( !v4 || !v4->m_PlayCount )
    return 1i64;
  switch ( v2->eType )
  {
    case 0:
      return CAkURenderer::Stop((CAkSoundBase *)&v3->vfptr, v2->pGameObj, &v2->transParams, v2->playingID);
    case 1:
      return CAkURenderer::Pause((CAkSoundBase *)&v3->vfptr, v2->pGameObj, &v2->transParams, v2->playingID);
    case 2:
      return CAkURenderer::Resume(
               (CAkSoundBase *)&v3->vfptr,
               v2->pGameObj,
               &v2->transParams,
               v2->bIsMasterResume,
               v2->playingID);
  }
  if ( v2->eType != 3 )
  {
    if ( v2->eType == 4 )
      CAkSound::SeekSound(v3, v2->pGameObj, v2);
    return 1i64;
  }
  ((void (__fastcall *)(CAkSound *, CAkRegisteredObj *, CAkParameterNodeBase *, _QWORD))v3->vfptr[4].Category)(
    v3,
    v2->pGameObj,
    v2->targetNodePtr,
    v2->playingID);
  return 1i64;
}

// File Line: 100
// RVA: 0xA797B0
signed __int64 __fastcall CAkSound::ExecuteActionExcept(CAkSound *this, ActionParamsExcept *in_rAction)
{
  SeekActionParamsExcept *v2; // rbx
  CAkSound *v3; // rdi
  AkActivityChunk *v4; // rax

  v2 = (SeekActionParamsExcept *)in_rAction;
  v3 = this;
  if ( !in_rAction->pGameObj )
  {
    LOBYTE(in_rAction) = in_rAction->eType == 1;
    ((void (__fastcall *)(CAkSound *, ActionParamsExcept *))this->vfptr[10].Category)(this, in_rAction);
  }
  v4 = v3->m_pActivityChunk;
  if ( !v4 || !v4->m_PlayCount )
    return 1i64;
  if ( v2->eType == ActionParamType_Stop )
    return CAkURenderer::Stop((CAkSoundBase *)&v3->vfptr, v2->pGameObj, &v2->transParams, v2->playingID);
  if ( v2->eType == 1 )
    return CAkURenderer::Pause((CAkSoundBase *)&v3->vfptr, v2->pGameObj, &v2->transParams, v2->playingID);
  if ( v2->eType != 2 )
  {
    if ( v2->eType == 4 )
      CAkSound::SeekSound(v3, v2->pGameObj, v2);
    return 1i64;
  }
  return CAkURenderer::Resume(
           (CAkSoundBase *)&v3->vfptr,
           v2->pGameObj,
           &v2->transParams,
           v2->bIsMasterResume,
           v2->playingID);
}

// File Line: 132
// RVA: 0xA798B0
void __fastcall CAkSound::SeekSound(CAkSound *this, CAkRegisteredObj *in_pGameObj, SeekActionParams *in_rActionParams)
{
  SeekActionParams *v3; // rsi
  CAkRegisteredObj *v4; // rdi
  AkActivityChunk *v5; // rbx
  CAkPBI *i; // rbx
  unsigned int v7; // eax
  AkActivityChunk *v8; // rbx
  int v9; // ebp
  CAkPBI *j; // rbx
  unsigned int v11; // eax

  v3 = in_rActionParams;
  v4 = in_pGameObj;
  if ( *((_BYTE *)in_rActionParams + 44) & 1 )
  {
    in_rActionParams->fSeekPercent;
    v5 = this->m_pActivityChunk;
    if ( v5 )
    {
      for ( i = v5->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
      {
        v7 = v3->playingID;
        if ( (!v4 || v4 == i->m_pGameObj) && (!v7 || v7 == i->m_UserParams.m_PlayingID) )
          ((void (__fastcall *)(CAkPBI *, CAkRegisteredObj *, _QWORD))i->vfptr[4].~CAkTransportAware)(
            i,
            in_pGameObj,
            (*((_BYTE *)v3 + 44) >> 1) & 1);
      }
    }
  }
  else
  {
    v8 = this->m_pActivityChunk;
    v9 = in_rActionParams->iSeekTime;
    if ( v9 < 0 )
      v9 = 0;
    if ( v8 )
    {
      for ( j = v8->m_listPBI.m_pFirst; j; j = j->pNextLightItem )
      {
        v11 = v3->playingID;
        if ( (!v4 || v4 == j->m_pGameObj) && (!v11 || v11 == j->m_UserParams.m_PlayingID) )
          ((void (__fastcall *)(CAkPBI *, _QWORD, _QWORD))j->vfptr[4]._Stop)(
            j,
            (unsigned int)v9,
            (*((_BYTE *)v3 + 44) >> 1) & 1);
      }
    }
  }
}

// File Line: 182
// RVA: 0xA799D0
void __fastcall CAkSound::SeekSound(CAkSound *this, CAkRegisteredObj *in_pGameObj, SeekActionParamsExcept *in_rActionParams)
{
  SeekActionParamsExcept *v3; // rsi
  CAkRegisteredObj *v4; // rdi
  AkActivityChunk *v5; // rbx
  CAkPBI *i; // rbx
  AkActivityChunk *v7; // rbx
  int v8; // ebp
  CAkPBI *j; // rbx

  v3 = in_rActionParams;
  v4 = in_pGameObj;
  if ( *((_BYTE *)in_rActionParams + 44) & 1 )
  {
    in_rActionParams->fSeekPercent;
    v5 = this->m_pActivityChunk;
    if ( v5 )
    {
      for ( i = v5->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
      {
        if ( !v4 || i->m_pGameObj == v4 )
          ((void (__fastcall *)(CAkPBI *, CAkRegisteredObj *, _QWORD))i->vfptr[4].~CAkTransportAware)(
            i,
            in_pGameObj,
            (*((_BYTE *)v3 + 44) >> 1) & 1);
      }
    }
  }
  else
  {
    v7 = this->m_pActivityChunk;
    v8 = in_rActionParams->iSeekTime;
    if ( v8 < 0 )
      v8 = 0;
    if ( v7 )
    {
      for ( j = v7->m_listPBI.m_pFirst; j; j = j->pNextLightItem )
      {
        if ( !v4 || j->m_pGameObj == v4 )
          ((void (__fastcall *)(CAkPBI *, _QWORD, _QWORD))j->vfptr[4]._Stop)(
            j,
            (unsigned int)v8,
            (*((_BYTE *)v3 + 44) >> 1) & 1);
      }
    }
  }
}

// File Line: 251
// RVA: 0xA79AD0
signed __int64 __fastcall CAkSound::SetInitialValues(CAkSound *this, char *in_pData, unsigned int in_ulDataSize, CAkUsageSlot *__formal, bool in_bIsPartialLoadOnly)
{
  CAkSound *v5; // rbx
  signed __int64 result; // rax
  CAkSource *v7; // rcx
  __int128 v8; // [rsp+20h] [rbp-58h]
  int v9; // [rsp+30h] [rbp-48h]
  __int64 v10; // [rsp+40h] [rbp-38h]
  unsigned int in_sourceID[4]; // [rsp+48h] [rbp-30h]
  int v12; // [rsp+58h] [rbp-20h]
  __int64 v13; // [rsp+60h] [rbp-18h]
  char *io_rpData; // [rsp+88h] [rbp+10h]
  unsigned int io_rulDataSize; // [rsp+90h] [rbp+18h]

  io_rulDataSize = in_ulDataSize;
  v5 = this;
  io_rpData = in_pData + 4;
  result = CAkBankMgr::LoadSource(&io_rpData, &io_rulDataSize, (AkBankSourceData *)&v10);
  if ( (_DWORD)result == 1 )
  {
    v7 = &v5->m_Source;
    if ( v13 )
    {
      CAkSource::SetSource(v7, in_sourceID[0]);
    }
    else
    {
      v9 = v12;
      v8 = *(_OWORD *)in_sourceID;
      CAkSource::SetSource(v7, HIDWORD(v10), (AkMediaInformation *)&v8);
    }
    result = CAkParameterNodeBase::SetNodeBaseParams(
               (CAkParameterNodeBase *)&v5->vfptr,
               &io_rpData,
               &io_rulDataSize,
               in_bIsPartialLoadOnly);
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

