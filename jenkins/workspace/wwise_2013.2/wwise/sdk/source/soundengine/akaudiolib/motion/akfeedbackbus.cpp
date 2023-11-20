// File Line: 42
// RVA: 0xA8DE40
CAkBus *__fastcall CAkFeedbackBus::Create(unsigned int in_ulID)
{
  unsigned int v1; // edi
  CAkBus *v2; // rax
  CAkBus *v3; // rbx
  CAkParameterNodeBase::AkFeedbackInfo *v4; // rax
  CAkFeedbackBus *v5; // rax

  v1 = in_ulID;
  v2 = (CAkBus *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x138ui64);
  v3 = v2;
  if ( !v2 )
    return 0i64;
  CAkBus::CAkBus(v2, v1);
  v3->vfptr = (CAkIndexableVtbl *)&CAkFeedbackBus::`vftable';
  v4 = (CAkParameterNodeBase::AkFeedbackInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8ui64);
  v3->m_pFeedbackInfo = v4;
  if ( v4 )
    v4->m_pFeedbackBus = 0i64;
  v5 = CAkFeedbackBus::s_pMasterMotionBus;
  if ( !CAkFeedbackBus::s_pMasterMotionBus )
    v5 = (CAkFeedbackBus *)v3;
  CAkFeedbackBus::s_pMasterMotionBus = v5;
  if ( (unsigned int)CAkBus::Init(v3) != 1 )
  {
    v3->vfptr->Release((CAkIndexable *)&v3->vfptr);
    return 0i64;
  }
  return v3;
}

// File Line: 56
// RVA: 0xA8E1B0
CAkFeedbackBus *__fastcall CAkFeedbackBus::GetMasterMotionBusAndAddRef()
{
  CAkAudioLibIndex *v0; // rbx
  CAkFeedbackBus *v1; // rdi

  v0 = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
  EnterCriticalSection(&v0->m_idxAudioNode.m_IndexLock.m_csLock);
  v1 = CAkFeedbackBus::s_pMasterMotionBus;
  if ( CAkFeedbackBus::s_pMasterMotionBus )
  {
    CAkFeedbackBus::s_pMasterMotionBus->vfptr->AddRef((CAkIndexable *)CAkFeedbackBus::s_pMasterMotionBus);
    v1 = CAkFeedbackBus::s_pMasterMotionBus;
  }
  LeaveCriticalSection(&v0->m_idxAudioNode.m_IndexLock.m_csLock);
  return v1;
}

// File Line: 65
// RVA: 0xA8DDE0
CAkFeedbackBus *__fastcall CAkFeedbackBus::ClearTempMasterBus()
{
  CAkAudioLibIndex *v0; // rbx
  CAkFeedbackBus *v1; // rdi

  v0 = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
  EnterCriticalSection(&v0->m_idxAudioNode.m_IndexLock.m_csLock);
  v1 = CAkFeedbackBus::s_pMasterMotionBus;
  CAkFeedbackBus::s_pMasterMotionBus = 0i64;
  if ( v1 )
    v1->vfptr->AddRef((CAkIndexable *)&v1->vfptr);
  LeaveCriticalSection(&v0->m_idxAudioNode.m_IndexLock.m_csLock);
  return v1;
}

// File Line: 76
// RVA: 0xA8E2A0
void __fastcall CAkFeedbackBus::ResetMasterBus(CAkFeedbackBus *in_pBus)
{
  CAkFeedbackBus *v1; // rdi
  CAkAudioLibIndex *v2; // rbx
  CAkFeedbackBus *v3; // rax

  v1 = in_pBus;
  v2 = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
  EnterCriticalSection(&v2->m_idxAudioNode.m_IndexLock.m_csLock);
  v3 = CAkFeedbackBus::s_pMasterMotionBus;
  if ( !CAkFeedbackBus::s_pMasterMotionBus )
  {
    if ( v1 )
      v3 = v1;
    CAkFeedbackBus::s_pMasterMotionBus = v3;
  }
  LeaveCriticalSection(&v2->m_idxAudioNode.m_IndexLock.m_csLock);
}

// File Line: 88
// RVA: 0xA8DCC0
__int64 __fastcall CAkFeedbackBus::AddChildInternal(CAkFeedbackBus *this, CAkParameterNodeBase *pAudioNode)
{
  CAkParameterNodeBase *v2; // rbx
  CAkFeedbackBus *v3; // rdi
  unsigned int v4; // esi
  AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *v5; // rcx
  CAkParameterNodeBase **v6; // rax

  v2 = pAudioNode;
  v3 = this;
  v4 = ((__int64 (*)(void))this->vfptr[20].__vecDelDtor)();
  if ( v4 == 1 )
  {
    v5 = &v3->m_mapBusChildId;
    if ( !(*((_BYTE *)v2 + 83) & 2) )
      v5 = &v3->m_mapChildId;
    v6 = AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::AddNoSetKey<unsigned long>(
           v5,
           v2->key);
    if ( v6 )
    {
      *v6 = v2;
      ((void (__fastcall *)(CAkParameterNodeBase *, CAkFeedbackBus *))v2->vfptr[16].Category)(v2, v3);
      v3->vfptr->AddRef((CAkIndexable *)&v3->vfptr);
    }
    else
    {
      v4 = 2;
    }
  }
  v2->vfptr->Release((CAkIndexable *)&v2->vfptr);
  return v4;
}

// File Line: 119
// RVA: 0xA8E240
void __fastcall CAkFeedbackBus::RemoveChild(CAkFeedbackBus *this, CAkParameterNodeBase *in_pChild)
{
  CAkFeedbackBus *v2; // rdi
  CAkParameterNodeBase *v3; // rbx
  AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *v4; // rcx

  v2 = this;
  v3 = in_pChild;
  if ( (CAkFeedbackBus *)in_pChild->vfptr[16].Release((CAkIndexable *)in_pChild) == this )
  {
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))v3->vfptr[16].Category)(v3, 0i64);
    v4 = &v2->m_mapBusChildId;
    if ( !(*((_BYTE *)v3 + 83) & 2) )
      v4 = &v2->m_mapChildId;
    AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Unset<unsigned long>(
      v4,
      v3->key);
    v2->vfptr->Release((CAkIndexable *)&v2->vfptr);
  }
}

// File Line: 139
// RVA: 0xA8DD40
signed __int64 __fastcall CAkFeedbackBus::CanAddChild(CAkFeedbackBus *this, CAkParameterNodeBase *in_pAudioNode)
{
  unsigned int v2; // ebx
  CAkFeedbackBus *v3; // rdi
  signed __int64 result; // rax
  unsigned int v5; // esi

  v2 = 1;
  v3 = this;
  if ( (*((_BYTE *)in_pAudioNode + 83) >> 1) & 1 )
  {
    v5 = in_pAudioNode->key;
    if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
           &this->m_mapBusChildId,
           in_pAudioNode->key) )
    {
      result = 5i64;
    }
    else
    {
      if ( v3->key == v5 )
        v2 = 23;
      result = v2;
    }
  }
  else if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
              &this->m_mapChildId,
              in_pAudioNode->key) )
  {
    result = 5i64;
  }
  else
  {
    result = 1i64;
  }
  return result;
}

// File Line: 159
// RVA: 0xA8DEE0
signed __int64 __fastcall CAkFeedbackBus::GetFeedbackParameters(CAkFeedbackBus *this, AkFeedbackParams *io_Params, CAkSource *in_pSource, CAkRegisteredObj *in_GameObjPtr)
{
  AkFeedbackParams *v4; // rdi
  CAkRegisteredObj *v5; // rbp
  CAkSource *v6; // r14
  CAkFeedbackBus *v7; // rsi
  int v8; // ebx
  float v9; // xmm1_4
  float v10; // xmm0_4
  char *v11; // r8
  unsigned int v12; // er9
  __int64 v13; // rcx
  __int64 v14; // rdx
  signed __int64 v15; // rdx
  float *v16; // rax
  unsigned __int64 v17; // rax
  char *v18; // r8
  unsigned int v19; // er9
  __int64 v20; // rcx
  __int64 v21; // rdx
  signed __int64 v22; // rdx
  float *v23; // rax
  unsigned __int64 v24; // rax
  CAkSIS *v25; // r8
  char *v26; // r8
  unsigned int v27; // er9
  int v28; // ecx
  __int64 v29; // rdx
  float *v30; // rdx
  char *v31; // rdx
  unsigned int v32; // er8
  __int64 v33; // rcx
  float *v34; // rcx
  __int64 v35; // rax
  AkSoundParams io_Parameters; // [rsp+30h] [rbp-48h]
  float v38; // [rsp+80h] [rbp+8h]

  v4 = io_Params;
  v5 = in_GameObjPtr;
  v6 = in_pSource;
  v7 = this;
  *((_BYTE *)&io_Parameters.normalization + 4) &= 0xFCu;
  *((_BYTE *)&io_Parameters.hdr + 4) &= 0xFCu;
  LODWORD(io_Parameters.fFadeRatio) = (_DWORD)FLOAT_1_0;
  v4->m_NewVolume = CAkBus::GetDuckedVolume((CAkBus *)&this->vfptr, 0) + v4->m_NewVolume;
  io_Parameters.Volume = 0.0;
  *(_QWORD *)&io_Parameters.Pitch = 0i64;
  *(_QWORD *)&io_Parameters.BusVolume = 0i64;
  io_Parameters.hdr.fActiveRange = 0.0;
  CAkParameterNodeBase::GetAudioStateParams((CAkParameterNodeBase *)&v7->vfptr, &io_Parameters, 3u);
  v8 = 0;
  v38 = 0.0;
  v9 = io_Parameters.Volume + v4->m_NewVolume;
  v10 = io_Parameters.Pitch + v4->m_MotionBusPitch;
  v4->m_NewVolume = v9;
  v4->m_MotionBusPitch = v10;
  v11 = v7->m_props.m_pProps;
  if ( v11 )
  {
    v12 = (unsigned __int8)*v11;
    v13 = 0i64;
    while ( 1 )
    {
      v14 = (unsigned int)(v13 + 1);
      if ( !v11[v14] )
        break;
      v13 = (unsigned int)v14;
      if ( (unsigned int)v14 >= v12 )
        goto LABEL_5;
    }
    v15 = (signed __int64)&v11[4 * v13 + ((v12 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v15 = 0i64;
  }
  v16 = &v38;
  if ( v15 )
    v16 = (float *)v15;
  v38 = *v16;
  v4->m_NewVolume = v9 + v38;
  v17 = v7->m_RTPCBitArray.m_iBitArray;
  if ( _bittest64((const signed __int64 *)&v17, (unsigned int)g_AkPropRTPCID[0]) )
    v4->m_NewVolume = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v7, g_AkPropRTPCID[0], 0i64) + v4->m_NewVolume;
  v18 = v7->m_props.m_pProps;
  v38 = 0.0;
  if ( v18 )
  {
    v19 = (unsigned __int8)*v18;
    v20 = 0i64;
    while ( 1 )
    {
      v21 = (unsigned int)(v20 + 1);
      if ( v18[v21] == 2 )
        break;
      v20 = (unsigned int)v21;
      if ( (unsigned int)v21 >= v19 )
        goto LABEL_14;
    }
    v22 = (signed __int64)&v18[4 * v20 + ((v19 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_14:
    v22 = 0i64;
  }
  v23 = &v38;
  if ( v22 )
    v23 = (float *)v22;
  v38 = *v23;
  v4->m_MotionBusPitch = v38 + v4->m_MotionBusPitch;
  v24 = v7->m_RTPCBitArray.m_iBitArray;
  if ( _bittest64((const signed __int64 *)&v24, 2ui64) )
    v4->m_MotionBusPitch = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, v7, 2u, 0i64) + v4->m_MotionBusPitch;
  v25 = v7->m_pGlobalSIS;
  if ( v25 )
  {
    v26 = v25->m_values.m_pProps;
    if ( v26 )
    {
      v27 = (unsigned __int8)*v26;
      v28 = 0;
      while ( 1 )
      {
        v29 = (unsigned int)(v28 + 1);
        if ( !v26[v29] )
          break;
        v28 = v29;
        if ( (unsigned int)v29 >= v27 )
          goto LABEL_29;
      }
      v30 = (float *)&v26[16 * v28 + ((v27 + 4) & 0xFFFFFFFC)];
      if ( v30 )
        v4->m_NewVolume = *v30 + v4->m_NewVolume;
    }
LABEL_29:
    v31 = v7->m_pGlobalSIS->m_values.m_pProps;
    if ( v31 )
    {
      v32 = (unsigned __int8)*v31;
      while ( 1 )
      {
        v33 = (unsigned int)(v8 + 1);
        if ( v31[v33] == 2 )
          break;
        v8 = v33;
        if ( (unsigned int)v33 >= v32 )
          goto LABEL_36;
      }
      v34 = (float *)&v31[16 * v8 + ((v32 + 4) & 0xFFFFFFFC)];
      if ( v34 )
        v4->m_MotionBusPitch = *v34 + v4->m_MotionBusPitch;
    }
  }
LABEL_36:
  v35 = v7->vfptr[16].Release((CAkIndexable *)&v7->vfptr);
  if ( v35 )
    (*(void (__fastcall **)(__int64, AkFeedbackParams *, CAkSource *, CAkRegisteredObj *, _BYTE))(*(_QWORD *)v35 + 512i64))(
      v35,
      v4,
      v6,
      v5,
      0);
  return 1i64;
}

// File Line: 200
// RVA: 0xA8E210
void __fastcall CAkFeedbackBus::Notification(CAkFeedbackBus *this, AkRTPC_ParameterID in_ParamID, float in_fValue, CAkRegisteredObj *in_pGameObj, void *in_pExceptArray)
{
  if ( in_ParamID )
  {
    if ( in_ParamID == 2 )
      in_ParamID = 31;
    CAkParameterNodeBase::Notification(
      (CAkParameterNodeBase *)&this->vfptr,
      in_ParamID,
      in_fValue,
      in_pGameObj,
      in_pExceptArray);
  }
  else
  {
    CAkParameterNodeBase::Notification(
      (CAkParameterNodeBase *)&this->vfptr,
      RTPC_FeedbackVolume,
      in_fValue,
      in_pGameObj,
      in_pExceptArray);
  }
}

// File Line: 210
// RVA: 0xA8E230
void __fastcall CAkFeedbackBus::ParamNotification(CAkFeedbackBus *this, NotifParams *in_rParams)
{
  CAkBus::ParamNotification((CAkBus *)&this->vfptr, in_rParams);
}

