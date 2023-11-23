// File Line: 42
// RVA: 0xA8DE40
CAkFeedbackBus *__fastcall CAkFeedbackBus::Create(unsigned int in_ulID)
{
  CAkBus *v2; // rax
  CAkBus *v3; // rbx
  CAkParameterNodeBase::AkFeedbackInfo *v4; // rax
  CAkFeedbackBus *v5; // rax

  v2 = (CAkBus *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x138ui64);
  v3 = v2;
  if ( !v2 )
    return 0i64;
  CAkBus::CAkBus(v2, in_ulID);
  v3->vfptr = (CAkIndexableVtbl *)&CAkFeedbackBus::`vftable;
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
    v3->vfptr->Release(v3);
    return 0i64;
  }
  return (CAkFeedbackBus *)v3;
}

// File Line: 56
// RVA: 0xA8E1B0
CAkFeedbackBus *__fastcall CAkFeedbackBus::GetMasterMotionBusAndAddRef()
{
  CAkAudioLibIndex *NodeLock; // rbx
  CAkFeedbackBus *v1; // rdi

  NodeLock = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
  EnterCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  v1 = CAkFeedbackBus::s_pMasterMotionBus;
  if ( CAkFeedbackBus::s_pMasterMotionBus )
  {
    CAkFeedbackBus::s_pMasterMotionBus->vfptr->AddRef(CAkFeedbackBus::s_pMasterMotionBus);
    v1 = CAkFeedbackBus::s_pMasterMotionBus;
  }
  LeaveCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  return v1;
}

// File Line: 65
// RVA: 0xA8DDE0
CAkFeedbackBus *__fastcall CAkFeedbackBus::ClearTempMasterBus()
{
  CAkAudioLibIndex *NodeLock; // rbx
  CAkFeedbackBus *v1; // rdi

  NodeLock = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
  EnterCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  v1 = CAkFeedbackBus::s_pMasterMotionBus;
  CAkFeedbackBus::s_pMasterMotionBus = 0i64;
  if ( v1 )
    v1->vfptr->AddRef(v1);
  LeaveCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  return v1;
}

// File Line: 76
// RVA: 0xA8E2A0
void __fastcall CAkFeedbackBus::ResetMasterBus(CAkFeedbackBus *in_pBus)
{
  CAkAudioLibIndex *NodeLock; // rbx
  CAkFeedbackBus *v3; // rax

  NodeLock = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Bus);
  EnterCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  v3 = CAkFeedbackBus::s_pMasterMotionBus;
  if ( !CAkFeedbackBus::s_pMasterMotionBus )
  {
    if ( in_pBus )
      v3 = in_pBus;
    CAkFeedbackBus::s_pMasterMotionBus = v3;
  }
  LeaveCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
}

// File Line: 88
// RVA: 0xA8DCC0
__int64 __fastcall CAkFeedbackBus::AddChildInternal(CAkFeedbackBus *this, CAkParameterNodeBase *pAudioNode)
{
  unsigned int v4; // esi
  AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *p_m_mapBusChildId; // rcx
  CAkParameterNodeBase **v6; // rax

  v4 = ((__int64 (__fastcall *)(CAkFeedbackBus *))this->vfptr[20].__vecDelDtor)(this);
  if ( v4 == 1 )
  {
    p_m_mapBusChildId = &this->m_mapBusChildId;
    if ( (*((_BYTE *)pAudioNode + 83) & 2) == 0 )
      p_m_mapBusChildId = &this->m_mapChildId;
    v6 = AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::AddNoSetKey<unsigned long>(
           p_m_mapBusChildId,
           pAudioNode->key);
    if ( v6 )
    {
      *v6 = pAudioNode;
      ((void (__fastcall *)(CAkParameterNodeBase *, CAkFeedbackBus *))pAudioNode->vfptr[16].Category)(pAudioNode, this);
      this->vfptr->AddRef(this);
    }
    else
    {
      v4 = 2;
    }
  }
  pAudioNode->vfptr->Release(pAudioNode);
  return v4;
}

// File Line: 119
// RVA: 0xA8E240
void __fastcall CAkFeedbackBus::RemoveChild(CAkFeedbackBus *this, CAkParameterNodeBase *in_pChild)
{
  AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1> *p_m_mapBusChildId; // rcx

  if ( (CAkFeedbackBus *)((__int64 (__fastcall *)(CAkParameterNodeBase *))in_pChild->vfptr[16].Release)(in_pChild) == this )
  {
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))in_pChild->vfptr[16].Category)(in_pChild, 0i64);
    p_m_mapBusChildId = &this->m_mapBusChildId;
    if ( (*((_BYTE *)in_pChild + 83) & 2) == 0 )
      p_m_mapBusChildId = &this->m_mapChildId;
    AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Unset<unsigned long>(
      p_m_mapBusChildId,
      in_pChild->key);
    this->vfptr->Release(this);
  }
}

// File Line: 139
// RVA: 0xA8DD40
__int64 __fastcall CAkFeedbackBus::CanAddChild(CAkFeedbackBus *this, CAkParameterNodeBase *in_pAudioNode)
{
  unsigned int v2; // ebx
  unsigned int key; // esi

  v2 = 1;
  if ( (*((_BYTE *)in_pAudioNode + 83) & 2) != 0 )
  {
    key = in_pAudioNode->key;
    if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
           &this->m_mapBusChildId,
           key) )
    {
      return 5i64;
    }
    else
    {
      if ( this->key == key )
        return 23;
      return v2;
    }
  }
  else if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
              &this->m_mapChildId,
              in_pAudioNode->key) )
  {
    return 5i64;
  }
  else
  {
    return 1i64;
  }
}

// File Line: 159
// RVA: 0xA8DEE0
__int64 __fastcall CAkFeedbackBus::GetFeedbackParameters(
        CAkFeedbackBus *this,
        AkFeedbackParams *io_Params,
        CAkSource *in_pSource,
        CAkRegisteredObj *in_GameObjPtr)
{
  int v8; // ebx
  float v9; // xmm1_4
  float v10; // xmm0_4
  char *m_pProps; // r8
  unsigned int v12; // r9d
  __int64 v13; // rcx
  __int64 v14; // rdx
  __int64 v15; // rdx
  float *v16; // rax
  unsigned __int64 m_iBitArray; // rax
  char *v18; // r8
  unsigned int v19; // r9d
  __int64 v20; // rcx
  __int64 v21; // rdx
  __int64 v22; // rdx
  float *v23; // rax
  CAkSIS *m_pGlobalSIS; // r8
  char *v25; // r8
  unsigned int v26; // r9d
  int v27; // ecx
  __int64 v28; // rdx
  float *v29; // rdx
  char *v30; // rdx
  unsigned int v31; // r8d
  __int64 v32; // rcx
  float *v33; // rcx
  __int64 v34; // rax
  AkSoundParams io_Parameters; // [rsp+30h] [rbp-48h] BYREF
  float v37; // [rsp+80h] [rbp+8h] BYREF

  *((_BYTE *)&io_Parameters.normalization + 4) &= 0xFCu;
  *((_BYTE *)&io_Parameters.hdr + 4) &= 0xFCu;
  LODWORD(io_Parameters.fFadeRatio) = (_DWORD)FLOAT_1_0;
  io_Params->m_NewVolume = CAkBus::GetDuckedVolume(this, AkPropID_Volume) + io_Params->m_NewVolume;
  io_Parameters.Volume = 0.0;
  *(_QWORD *)&io_Parameters.Pitch = 0i64;
  *(_QWORD *)&io_Parameters.BusVolume = 0i64;
  io_Parameters.hdr.fActiveRange = 0.0;
  CAkParameterNodeBase::GetAudioStateParams(this, &io_Parameters, 3);
  v8 = 0;
  v37 = 0.0;
  v9 = io_Parameters.Volume + io_Params->m_NewVolume;
  v10 = io_Parameters.Pitch + io_Params->m_MotionBusPitch;
  io_Params->m_NewVolume = v9;
  io_Params->m_MotionBusPitch = v10;
  m_pProps = this->m_props.m_pProps;
  if ( m_pProps )
  {
    v12 = (unsigned __int8)*m_pProps;
    v13 = 0i64;
    while ( 1 )
    {
      v14 = (unsigned int)(v13 + 1);
      if ( !m_pProps[v14] )
        break;
      v13 = (unsigned int)v14;
      if ( (unsigned int)v14 >= v12 )
        goto LABEL_5;
    }
    v15 = (__int64)&m_pProps[4 * v13 + ((v12 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v15 = 0i64;
  }
  v16 = &v37;
  if ( v15 )
    v16 = (float *)v15;
  v37 = *v16;
  io_Params->m_NewVolume = v9 + v37;
  m_iBitArray = this->m_RTPCBitArray.m_iBitArray;
  if ( _bittest64((const __int64 *)&m_iBitArray, (unsigned int)g_AkPropRTPCID[0]) )
    io_Params->m_NewVolume = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, g_AkPropRTPCID[0], 0i64)
                           + io_Params->m_NewVolume;
  v18 = this->m_props.m_pProps;
  v37 = 0.0;
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
    v22 = (__int64)&v18[4 * v20 + ((v19 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_14:
    v22 = 0i64;
  }
  v23 = &v37;
  if ( v22 )
    v23 = (float *)v22;
  v37 = *v23;
  io_Params->m_MotionBusPitch = v37 + io_Params->m_MotionBusPitch;
  if ( (this->m_RTPCBitArray.m_iBitArray & 4) != 0 )
    io_Params->m_MotionBusPitch = CAkRTPCMgr::GetRTPCConvertedValue(g_pRTPCMgr, this, 2u, 0i64)
                                + io_Params->m_MotionBusPitch;
  m_pGlobalSIS = this->m_pGlobalSIS;
  if ( m_pGlobalSIS )
  {
    v25 = m_pGlobalSIS->m_values.m_pProps;
    if ( v25 )
    {
      v26 = (unsigned __int8)*v25;
      v27 = 0;
      while ( 1 )
      {
        v28 = (unsigned int)(v27 + 1);
        if ( !v25[v28] )
          break;
        ++v27;
        if ( (unsigned int)v28 >= v26 )
          goto LABEL_29;
      }
      v29 = (float *)&v25[16 * v27 + ((v26 + 4) & 0xFFFFFFFC)];
      if ( v29 )
        io_Params->m_NewVolume = *v29 + io_Params->m_NewVolume;
    }
LABEL_29:
    v30 = this->m_pGlobalSIS->m_values.m_pProps;
    if ( v30 )
    {
      v31 = (unsigned __int8)*v30;
      while ( 1 )
      {
        v32 = (unsigned int)(v8 + 1);
        if ( v30[v32] == 2 )
          break;
        ++v8;
        if ( (unsigned int)v32 >= v31 )
          goto LABEL_36;
      }
      v33 = (float *)&v30[16 * v8 + ((v31 + 4) & 0xFFFFFFFC)];
      if ( v33 )
        io_Params->m_MotionBusPitch = *v33 + io_Params->m_MotionBusPitch;
    }
  }
LABEL_36:
  v34 = ((__int64 (__fastcall *)(CAkFeedbackBus *))this->vfptr[16].Release)(this);
  if ( v34 )
    (*(void (__fastcall **)(__int64, AkFeedbackParams *, CAkSource *, CAkRegisteredObj *, _BYTE))(*(_QWORD *)v34 + 512i64))(
      v34,
      io_Params,
      in_pSource,
      in_GameObjPtr,
      0);
  return 1i64;
}

// File Line: 200
// RVA: 0xA8E210
void __fastcall CAkFeedbackBus::Notification(
        CAkFeedbackBus *this,
        AkRTPC_ParameterID in_ParamID,
        float in_fValue,
        CAkRegisteredObj *in_pGameObj,
        void *in_pExceptArray)
{
  if ( in_ParamID )
  {
    if ( in_ParamID == RTPC_Pitch )
      in_ParamID = RTPC_FeedbackPitch;
    CAkParameterNodeBase::Notification(this, in_ParamID, in_fValue, in_pGameObj, in_pExceptArray);
  }
  else
  {
    CAkParameterNodeBase::Notification(this, RTPC_FeedbackVolume, in_fValue, in_pGameObj, in_pExceptArray);
  }
}

// File Line: 210
// RVA: 0xA8E230
// attributes: thunk
void __fastcall CAkFeedbackBus::ParamNotification(CAkFeedbackBus *this, NotifParams *in_rParams)
{
  CAkBus::ParamNotification(this, in_rParams);
}

