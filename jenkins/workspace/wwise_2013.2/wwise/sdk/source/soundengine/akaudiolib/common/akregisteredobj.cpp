// File Line: 41
// RVA: 0xA6A920
void __fastcall CAkRegisteredObj::CAkRegisteredObj(CAkRegisteredObj *this, unsigned __int64 in_GameObjID)
{
  this->m_pListModifiedNodes = 0i64;
  *((_BYTE *)&this->m_PosKeep.AkSoundPositionRef + 11) &= 0xF8u;
  this->m_PosKeep.m_aPos = 0i64;
  this->m_PosKeep.m_uNumPos = 0;
  this->m_PosKeep.m_uListenerMask = 1;
  this->m_SwitchHist.m_pItems = 0i64;
  *(_QWORD *)&this->m_SwitchHist.m_uLength = 0i64;
  this->m_fDryLevelValue = 1.0;
  this->m_fScalingFactor = 1.0;
  this->m_arCachedEmitListPairs.m_pItems = 0i64;
  *(_QWORD *)&this->m_arCachedEmitListPairs.m_uLength = 0i64;
  this->m_GameObjID = in_GameObjID;
  *((_DWORD *)this + 30) = -1073741823;
  this->m_EnvironmentValues[0] = 0i64;
  this->m_EnvironmentValues[1] = 0i64;
  this->m_EnvironmentValues[2] = 0i64;
  this->m_EnvironmentValues[3] = 0i64;
  *(_QWORD *)&this->m_fObstructionValue[0].m_ByteValue = 0i64;
  *(_QWORD *)&this->m_fOcclusionValue[0].m_ByteValue = 0i64;
}

// File Line: 56
// RVA: 0xA6A980
void __fastcall CAkRegisteredObj::~CAkRegisteredObj(CAkRegisteredObj *this)
{
  MapStruct<unsigned long,AkSwitchHistItem> *m_pItems; // rdx
  AkEmitterListenerPairEx *v3; // rdx
  AkSoundPosition *m_aPos; // rdx

  CAkRegisteredObj::FreeModifiedNodes(this);
  if ( this->m_pListModifiedNodes )
  {
    CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::Term(this->m_pListModifiedNodes);
    if ( this->m_pListModifiedNodes )
      AK::MemoryMgr::Free(g_DefaultPoolId, this->m_pListModifiedNodes);
    this->m_pListModifiedNodes = 0i64;
  }
  m_pItems = this->m_SwitchHist.m_pItems;
  if ( m_pItems )
  {
    this->m_SwitchHist.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_SwitchHist.m_pItems = 0i64;
    this->m_SwitchHist.m_ulReserved = 0;
  }
  v3 = this->m_arCachedEmitListPairs.m_pItems;
  if ( v3 )
  {
    this->m_arCachedEmitListPairs.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v3);
    this->m_arCachedEmitListPairs.m_pItems = 0i64;
    this->m_arCachedEmitListPairs.m_ulReserved = 0;
  }
  m_aPos = this->m_PosKeep.m_aPos;
  if ( m_aPos )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_aPos);
    this->m_PosKeep.m_aPos = 0i64;
    this->m_PosKeep.m_uNumPos = 0;
  }
}

// File Line: 98
// RVA: 0xA6AFC0
__int64 __fastcall CAkRegisteredObj::SetNodeAsModified(CAkRegisteredObj *this, CAkParameterNodeBase *in_pNode)
{
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *m_pListModifiedNodes; // rbx
  unsigned int key; // ebp
  bool v5; // di
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *v6; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *v7; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rcx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v10; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *m_pLast; // rcx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *m_pFree; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v13; // rcx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v14; // rcx
  WwiseObjectIDext v15; // [rsp+40h] [rbp+8h]

  m_pListModifiedNodes = this->m_pListModifiedNodes;
  key = in_pNode->key;
  v5 = (*((_BYTE *)in_pNode + 83) & 2) != 0;
  v15.id = key;
  v15.bIsBus = v5;
  if ( !this->m_pListModifiedNodes )
  {
    v6 = (CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *)AK::MemoryMgr::Malloc(
                                                                                     g_DefaultPoolId,
                                                                                     0x30ui64);
    this->m_pListModifiedNodes = v6;
    if ( !v6 )
      return 2i64;
    *(_QWORD *)&v6->m_ulMinNumListItems = 0i64;
    v6->m_ulNumListItems = 0;
    v7 = this->m_pListModifiedNodes;
    if ( !this->m_pListModifiedNodes )
      return 2i64;
    v7->m_ulNumListItems = 0;
    v7->m_ulMaxNumListItems = -1;
    v7->m_pFree = 0i64;
    v7->m_pvMemStart = 0i64;
    v7->m_pFirst = 0i64;
    v7->m_pLast = 0i64;
    m_pListModifiedNodes = this->m_pListModifiedNodes;
    if ( !this->m_pListModifiedNodes )
      return 2i64;
  }
  m_pFirst = m_pListModifiedNodes->m_pFirst;
  if ( !m_pListModifiedNodes->m_pFirst )
    goto LABEL_12;
  while ( key != m_pFirst->Item.id || v5 != m_pFirst->Item.bIsBus )
  {
    m_pFirst = m_pFirst->pNextListItem;
    if ( !m_pFirst )
      goto LABEL_12;
  }
  if ( m_pFirst == (CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *)-8i64 )
  {
LABEL_12:
    if ( !m_pListModifiedNodes->m_pFree )
    {
      if ( m_pListModifiedNodes->m_ulNumListItems >= m_pListModifiedNodes->m_ulMaxNumListItems )
        return 2i64;
      v10 = (CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(
                                                                                                  g_DefaultPoolId,
                                                                                                  0x10ui64);
      if ( !v10 )
        return 2i64;
      v10->pNextListItem = m_pListModifiedNodes->m_pFree;
      m_pListModifiedNodes->m_pFree = v10;
    }
    m_pLast = m_pListModifiedNodes->m_pLast;
    m_pFree = m_pListModifiedNodes->m_pFree;
    if ( m_pLast )
      m_pLast->pNextListItem = m_pFree;
    else
      m_pListModifiedNodes->m_pFirst = m_pFree;
    v13 = m_pListModifiedNodes->m_pFree;
    m_pListModifiedNodes->m_pLast = v13;
    m_pListModifiedNodes->m_pFree = v13->pNextListItem;
    v13->pNextListItem = 0i64;
    v14 = m_pListModifiedNodes->m_pLast;
    ++m_pListModifiedNodes->m_ulNumListItems;
    v14->Item = v15;
  }
  return 1i64;
}

// File Line: 122
// RVA: 0xA6ACB0
void __fastcall CAkRegisteredObj::FreeModifiedNodes(CAkRegisteredObj *this)
{
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *i; // rbx
  CAkParameterNodeBase *NodePtrAndAddRef; // rax
  CAkParameterNodeBase *v4; // rdi

  if ( this->m_pListModifiedNodes )
  {
    for ( i = this->m_pListModifiedNodes->m_pFirst; i; i = i->pNextListItem )
    {
      NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &i->Item);
      v4 = NodePtrAndAddRef;
      if ( NodePtrAndAddRef )
      {
        NodePtrAndAddRef->vfptr[2].__vecDelDtor(NodePtrAndAddRef, (unsigned int)this);
        v4->vfptr->Release(v4);
      }
    }
  }
  CAkRTPCMgr::UnregisterGameObject(g_pRTPCMgr, this);
}

// File Line: 143
// RVA: 0xA6B1E0
void __fastcall CAkRegisteredObj::SetPosition(
        CAkRegisteredObj *this,
        AkSoundPosition *in_aPositions,
        unsigned __int16 in_uNumPositions,
        AK::SoundEngine::MultiPositionType in_eMultiPositionType)
{
  char v5; // si

  v5 = in_eMultiPositionType;
  AkPositionKeeper::SetPosition(&this->m_PosKeep, in_aPositions, in_uNumPositions);
  *((_BYTE *)&this->m_PosKeep.AkSoundPositionRef + 11) &= 0xF8u;
  *((_BYTE *)&this->m_PosKeep.AkSoundPositionRef + 11) |= v5 & 7;
  *((_DWORD *)this + 30) |= 0x40000000u;
}

// File Line: 150
// RVA: 0xA6AE60
void __fastcall CAkRegisteredObj::SetActiveListeners(CAkRegisteredObj *this, char in_uListenerMask)
{
  *((_DWORD *)this + 30) |= 0x40000000u;
  this->m_PosKeep.m_uListenerMask = in_uListenerMask;
}

// File Line: 185
// RVA: 0xA6AE70
__int64 __fastcall CAkRegisteredObj::SetGameObjectAuxSendValues(
        CAkRegisteredObj *this,
        AkAuxSendValue *in_aEnvironmentValues,
        int in_uNumEnvValues)
{
  unsigned int v7; // r8d
  unsigned int v8; // edi
  __int64 v9; // rsi
  AkAuxSendValue *v10; // rdx
  unsigned int v11; // eax
  __int64 v12; // r9
  __int64 v13; // rcx
  __int64 v14; // rcx
  __int64 v15; // rcx
  __int64 v16; // rcx
  AkAuxSendValue *v17; // rdx
  __int64 v18; // r9
  __int64 v19; // rcx
  float *p_fControlValue; // rcx
  __int64 v21; // rdx

  if ( (unsigned int)in_uNumEnvValues > 4 )
    return 2i64;
  v7 = 0;
  if ( in_aEnvironmentValues )
  {
    v8 = 0;
    v9 = 0i64;
    if ( in_uNumEnvValues >= 4 )
    {
      v10 = in_aEnvironmentValues + 1;
      v11 = ((unsigned int)(in_uNumEnvValues - 4) >> 2) + 1;
      v12 = v11;
      v8 = 4 * v11;
      v9 = 4i64 * v11;
      do
      {
        if ( v10[-1].auxBusID && v10[-1].fControlValue > 0.0 )
        {
          v13 = v7++;
          this->m_EnvironmentValues[v13] = v10[-1];
        }
        if ( v10->auxBusID && v10->fControlValue > 0.0 )
        {
          v14 = v7++;
          this->m_EnvironmentValues[v14] = *v10;
        }
        if ( v10[1].auxBusID && v10[1].fControlValue > 0.0 )
        {
          v15 = v7++;
          this->m_EnvironmentValues[v15] = v10[1];
        }
        if ( v10[2].auxBusID && v10[2].fControlValue > 0.0 )
        {
          v16 = v7++;
          this->m_EnvironmentValues[v16] = v10[2];
        }
        v10 += 4;
        --v12;
      }
      while ( v12 );
    }
    if ( v8 < in_uNumEnvValues )
    {
      v17 = &in_aEnvironmentValues[v9];
      v18 = in_uNumEnvValues - v8;
      do
      {
        if ( v17->auxBusID && v17->fControlValue > 0.0 )
        {
          v19 = v7++;
          this->m_EnvironmentValues[v19] = *v17;
        }
        ++v17;
        --v18;
      }
      while ( v18 );
    }
  }
  if ( v7 < 4 )
  {
    p_fControlValue = &this->m_EnvironmentValues[v7].fControlValue;
    v21 = 4 - v7;
    do
    {
      *(_QWORD *)(p_fControlValue - 1) = 0i64;
      p_fControlValue += 2;
      --v21;
    }
    while ( v21 );
  }
  return 1i64;
}

// File Line: 216
// RVA: 0xA6AD40
__int64 __fastcall CAkRegisteredObj::GetNumEmitterListenerPairs(CAkRegisteredObj *this)
{
  unsigned __int16 m_uNumPos; // ax
  int m_uListenerMask; // edx
  int v3; // r8d
  int v4; // eax

  m_uNumPos = 1;
  if ( (*((_BYTE *)&this->m_PosKeep.AkSoundPositionRef + 11) & 7) != 0 )
    m_uNumPos = this->m_PosKeep.m_uNumPos;
  m_uListenerMask = (unsigned __int8)this->m_PosKeep.m_uListenerMask;
  v3 = m_uNumPos;
  v4 = 0;
  if ( this->m_PosKeep.m_uListenerMask )
  {
    do
    {
      ++v4;
      m_uListenerMask &= m_uListenerMask - 1;
    }
    while ( m_uListenerMask );
  }
  return (unsigned int)(v3 * v4);
}

// File Line: 224
// RVA: 0xA6AB50
void __fastcall CAkRegisteredObj::CacheEmitListenPairs(
        CAkRegisteredObj *this,
        AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *in_arEmitList)
{
  int v2; // ebx
  unsigned int m_uLength; // edx
  unsigned int m_ulReserved; // eax
  float *p_phi; // r14
  unsigned __int64 v8; // rsi
  __int64 v9; // rdx
  AkEmitterListenerPairEx *v10; // r8
  float v11; // eax

  v2 = 0;
  this->m_arCachedEmitListPairs.m_uLength = 0;
  *((_DWORD *)this + 30) |= 0x40000000u;
  if ( *((int *)this + 30) < 0 )
  {
    m_uLength = in_arEmitList->m_uLength;
    m_ulReserved = this->m_arCachedEmitListPairs.m_ulReserved;
    if ( m_uLength <= m_ulReserved
      || AkArray<AkEmitterListenerPairEx,AkEmitterListenerPairEx const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
           &this->m_arCachedEmitListPairs,
           m_uLength - m_ulReserved) )
    {
      if ( in_arEmitList->m_pItems != &in_arEmitList->m_pItems[in_arEmitList->m_uLength] )
      {
        p_phi = &in_arEmitList->m_pItems->phi;
        do
        {
          v8 = this->m_arCachedEmitListPairs.m_uLength;
          if ( (v8 < this->m_arCachedEmitListPairs.m_ulReserved
             || AkArray<AkEmitterListenerPairEx,AkEmitterListenerPairEx const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
                  &this->m_arCachedEmitListPairs,
                  1u))
            && v8 < this->m_arCachedEmitListPairs.m_ulReserved )
          {
            v9 = this->m_arCachedEmitListPairs.m_uLength;
            v10 = &this->m_arCachedEmitListPairs.m_pItems[v9];
            this->m_arCachedEmitListPairs.m_uLength = v9 + 1;
            if ( v10 )
            {
              *((_BYTE *)v10 + 16) &= 0xFCu;
              *(_QWORD *)&v10->phi = 0i64;
              v10->AkPolarCoord = 0i64;
              v10->m_uListenerMask = 0;
            }
          }
          else
          {
            v10 = 0i64;
          }
          v11 = *(p_phi - 2);
          p_phi += 9;
          v10->r = v11;
          v10->theta = *(p_phi - 10);
          v10->phi = *(p_phi - 9);
          v10->fEmitterAngle = *(p_phi - 8);
          *((_BYTE *)v10 + 16) ^= (*((_BYTE *)v10 + 16) ^ *((_BYTE *)p_phi - 28)) & 1;
          *((_BYTE *)v10 + 16) ^= (*((_BYTE *)p_phi - 28) ^ *((_BYTE *)v10 + 16)) & 2;
          v10->m_uListenerMask = *((_BYTE *)p_phi - 27);
        }
        while ( p_phi - 2 != (float *)&in_arEmitList->m_pItems[in_arEmitList->m_uLength].AkPolarCoord );
      }
      LOBYTE(v2) = in_arEmitList->m_uLength == 0;
      *((_DWORD *)this + 30) ^= (*((_DWORD *)this + 30) ^ (v2 << 30)) & 0x40000000;
    }
  }
}

// File Line: 258
// RVA: 0xA6AA90
void __fastcall CAkRegisteredObj::CacheEmitListenPair(CAkRegisteredObj *this, AkEmitterListenerPairEx *in_emitListPair)
{
  unsigned __int16 m_uNumPos; // ax
  int m_uListenerMask; // ecx
  int i; // edx
  AkEmitterListenerPairEx *v7; // rax

  m_uNumPos = 1;
  if ( (*((_BYTE *)&this->m_PosKeep.AkSoundPositionRef + 11) & 7) != 0 )
    m_uNumPos = this->m_PosKeep.m_uNumPos;
  m_uListenerMask = (unsigned __int8)this->m_PosKeep.m_uListenerMask;
  for ( i = 0; m_uListenerMask; m_uListenerMask &= m_uListenerMask - 1 )
    ++i;
  if ( m_uNumPos * i == 1 && *((int *)this + 30) < 0 )
  {
    this->m_arCachedEmitListPairs.m_uLength = 0;
    v7 = AkArray<AkEmitterListenerPairEx,AkEmitterListenerPairEx const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&this->m_arCachedEmitListPairs);
    if ( v7 )
    {
      v7->r = in_emitListPair->r;
      v7->theta = in_emitListPair->theta;
      v7->phi = in_emitListPair->phi;
      v7->fEmitterAngle = in_emitListPair->fEmitterAngle;
      *((_BYTE *)v7 + 16) ^= (*((_BYTE *)in_emitListPair + 16) ^ *((_BYTE *)v7 + 16)) & 1;
      *((_BYTE *)v7 + 16) ^= (*((_BYTE *)in_emitListPair + 16) ^ *((_BYTE *)v7 + 16)) & 2;
      v7->m_uListenerMask = in_emitListPair->m_uListenerMask;
      *((_DWORD *)this + 30) &= ~0x40000000u;
    }
  }
  else
  {
    *((_DWORD *)this + 30) |= 0x40000000u;
  }
}

// File Line: 280
// RVA: 0xA6B0F0
__int64 __fastcall CAkRegisteredObj::SetObjectObstructionAndOcclusion(
        CAkRegisteredObj *this,
        unsigned int in_uListener,
        float in_fObstructionValue,
        float in_fOcclusionValue)
{
  if ( in_uListener >= 8 )
    return 2i64;
  this->m_fObstructionValue[in_uListener].m_ByteValue = (int)(float)(in_fObstructionValue * 255.0);
  this->m_fOcclusionValue[in_uListener].m_ByteValue = (int)(float)(in_fOcclusionValue * 255.0);
  return 1i64;
}

