// File Line: 41
// RVA: 0xA6A920
void __fastcall CAkRegisteredObj::CAkRegisteredObj(CAkRegisteredObj *this, unsigned __int64 in_GameObjID)
{
  this->m_pListModifiedNodes = 0i64;
  *((_BYTE *)&this->m_PosKeep.0 + 11) &= 0xF8u;
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
  CAkRegisteredObj *v1; // rbx
  MapStruct<unsigned long,AkSwitchHistItem> *v2; // rdx
  AkEmitterListenerPairEx *v3; // rdx
  AkSoundPosition *v4; // rdx

  v1 = this;
  CAkRegisteredObj::FreeModifiedNodes(this);
  if ( v1->m_pListModifiedNodes )
  {
    CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::Term(v1->m_pListModifiedNodes);
    if ( v1->m_pListModifiedNodes )
      AK::MemoryMgr::Free(g_DefaultPoolId, v1->m_pListModifiedNodes);
    v1->m_pListModifiedNodes = 0i64;
  }
  v2 = v1->m_SwitchHist.m_pItems;
  if ( v2 )
  {
    v1->m_SwitchHist.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v2);
    v1->m_SwitchHist.m_pItems = 0i64;
    v1->m_SwitchHist.m_ulReserved = 0;
  }
  v3 = v1->m_arCachedEmitListPairs.m_pItems;
  if ( v3 )
  {
    v1->m_arCachedEmitListPairs.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v3);
    v1->m_arCachedEmitListPairs.m_pItems = 0i64;
    v1->m_arCachedEmitListPairs.m_ulReserved = 0;
  }
  v4 = v1->m_PosKeep.m_aPos;
  if ( v4 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v4);
    v1->m_PosKeep.m_aPos = 0i64;
    v1->m_PosKeep.m_uNumPos = 0;
  }
}

// File Line: 98
// RVA: 0xA6AFC0
signed __int64 __fastcall CAkRegisteredObj::SetNodeAsModified(CAkRegisteredObj *this, CAkParameterNodeBase *in_pNode)
{
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *v2; // rbx
  unsigned int v3; // ebp
  CAkRegisteredObj *v4; // rsi
  char v5; // di
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *v6; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *v7; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v9; // rcx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v10; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v11; // rcx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v12; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v13; // rcx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v14; // rcx
  WwiseObjectIDext v15; // [rsp+40h] [rbp+8h]

  v2 = this->m_pListModifiedNodes;
  v3 = in_pNode->key;
  v4 = this;
  v5 = (*((_BYTE *)in_pNode + 83) >> 1) & 1;
  v15.id = in_pNode->key;
  v15.bIsBus = (*((_BYTE *)in_pNode + 83) >> 1) & 1;
  if ( !this->m_pListModifiedNodes )
  {
    v6 = (CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> *)AK::MemoryMgr::Malloc(
                                                                                     g_DefaultPoolId,
                                                                                     0x30ui64);
    v4->m_pListModifiedNodes = v6;
    if ( !v6 )
      return 2i64;
    *(_QWORD *)&v6->m_ulMinNumListItems = 0i64;
    v6->m_ulNumListItems = 0;
    v7 = v4->m_pListModifiedNodes;
    if ( !v4->m_pListModifiedNodes )
      return 2i64;
    v7->m_ulNumListItems = 0;
    v7->m_ulMaxNumListItems = -1;
    v7->m_pFree = 0i64;
    v7->m_pvMemStart = 0i64;
    v7->m_pFirst = 0i64;
    v7->m_pLast = 0i64;
    v2 = v4->m_pListModifiedNodes;
    if ( !v4->m_pListModifiedNodes )
      return 2i64;
  }
  v9 = v2->m_pFirst;
  if ( !v2->m_pFirst )
    goto LABEL_12;
  while ( v3 != v9->Item.id || v5 != v9->Item.bIsBus )
  {
    v9 = v9->pNextListItem;
    if ( !v9 )
      goto LABEL_12;
  }
  if ( v9 == (CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *)-8i64 )
  {
LABEL_12:
    if ( !v2->m_pFree )
    {
      if ( v2->m_ulNumListItems >= v2->m_ulMaxNumListItems )
        return 2i64;
      v10 = (CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(
                                                                                                  g_DefaultPoolId,
                                                                                                  0x10ui64);
      if ( !v10 )
        return 2i64;
      v10->pNextListItem = v2->m_pFree;
      v2->m_pFree = v10;
    }
    v11 = v2->m_pLast;
    v12 = v2->m_pFree;
    if ( v11 )
      v11->pNextListItem = v12;
    else
      v2->m_pFirst = v12;
    v13 = v2->m_pFree;
    v2->m_pLast = v13;
    v2->m_pFree = v13->pNextListItem;
    v13->pNextListItem = 0i64;
    v14 = v2->m_pLast;
    ++v2->m_ulNumListItems;
    v14->Item = v15;
  }
  return 1i64;
}

// File Line: 122
// RVA: 0xA6ACB0
void __fastcall CAkRegisteredObj::FreeModifiedNodes(CAkRegisteredObj *this)
{
  CAkRegisteredObj *v1; // rsi
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *i; // rbx
  CAkIndexable *v3; // rax
  CAkIndexable *v4; // rdi

  v1 = this;
  if ( this->m_pListModifiedNodes )
  {
    for ( i = this->m_pListModifiedNodes->m_pFirst; i; i = i->pNextListItem )
    {
      v3 = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, &i->Item);
      v4 = v3;
      if ( v3 )
      {
        v3->vfptr[2].__vecDelDtor(v3, (unsigned int)v1);
        v4->vfptr->Release(v4);
      }
    }
  }
  CAkRTPCMgr::UnregisterGameObject(g_pRTPCMgr, v1);
}

// File Line: 143
// RVA: 0xA6B1E0
void __fastcall CAkRegisteredObj::SetPosition(CAkRegisteredObj *this, AkSoundPosition *in_aPositions, unsigned __int16 in_uNumPositions, AK::SoundEngine::MultiPositionType in_eMultiPositionType)
{
  CAkRegisteredObj *v4; // rdi
  char v5; // si

  v4 = this;
  v5 = in_eMultiPositionType;
  AkPositionKeeper::SetPosition(&this->m_PosKeep, in_aPositions, in_uNumPositions);
  *((_BYTE *)&v4->m_PosKeep.0 + 11) &= 0xF8u;
  *((_BYTE *)&v4->m_PosKeep.0 + 11) |= v5 & 7;
  *((_DWORD *)v4 + 30) |= 0x40000000u;
}

// File Line: 150
// RVA: 0xA6AE60
void __fastcall CAkRegisteredObj::SetActiveListeners(CAkRegisteredObj *this, unsigned int in_uListenerMask)
{
  *((_DWORD *)this + 30) |= 0x40000000u;
  this->m_PosKeep.m_uListenerMask = in_uListenerMask;
}

// File Line: 185
// RVA: 0xA6AE70
signed __int64 __fastcall CAkRegisteredObj::SetGameObjectAuxSendValues(CAkRegisteredObj *this, AkAuxSendValue *in_aEnvironmentValues, unsigned int in_uNumEnvValues)
{
  unsigned int v3; // er11
  AkAuxSendValue *v4; // rbx
  CAkRegisteredObj *v5; // r10
  unsigned int v7; // er8
  unsigned int v8; // edi
  signed __int64 v9; // rsi
  AkAuxSendValue *v10; // rdx
  unsigned int v11; // eax
  __int64 v12; // r9
  __int64 v13; // rcx
  __int64 v14; // rcx
  __int64 v15; // rcx
  __int64 v16; // rcx
  signed __int64 v17; // rdx
  __int64 v18; // r9
  __int64 v19; // rcx
  signed __int64 v20; // rcx
  __int64 v21; // rdx

  v3 = in_uNumEnvValues;
  v4 = in_aEnvironmentValues;
  v5 = this;
  if ( in_uNumEnvValues > 4 )
    return 2i64;
  v7 = 0;
  if ( in_aEnvironmentValues )
  {
    v8 = 0;
    v9 = 0i64;
    if ( (signed int)v3 >= 4 )
    {
      v10 = in_aEnvironmentValues + 1;
      v11 = ((v3 - 4) >> 2) + 1;
      v12 = v11;
      v8 = 4 * v11;
      v9 = 4i64 * v11;
      do
      {
        if ( v10[-1].auxBusID && v10[-1].fControlValue > 0.0 )
        {
          v13 = v7++;
          v5->m_EnvironmentValues[v13] = v10[-1];
        }
        if ( v10->auxBusID && v10->fControlValue > 0.0 )
        {
          v14 = v7++;
          v5->m_EnvironmentValues[v14] = *v10;
        }
        if ( v10[1].auxBusID && v10[1].fControlValue > 0.0 )
        {
          v15 = v7++;
          v5->m_EnvironmentValues[v15] = v10[1];
        }
        if ( v10[2].auxBusID && v10[2].fControlValue > 0.0 )
        {
          v16 = v7++;
          v5->m_EnvironmentValues[v16] = v10[2];
        }
        v10 += 4;
        --v12;
      }
      while ( v12 );
    }
    if ( v8 < v3 )
    {
      v17 = (signed __int64)&v4[v9];
      v18 = v3 - v8;
      do
      {
        if ( *(_DWORD *)v17 && *(float *)(v17 + 4) > 0.0 )
        {
          v19 = v7++;
          v5->m_EnvironmentValues[v19] = *(AkAuxSendValue *)v17;
        }
        v17 += 8i64;
        --v18;
      }
      while ( v18 );
    }
  }
  if ( v7 < 4 )
  {
    v20 = (signed __int64)&v5->m_EnvironmentValues[v7].fControlValue;
    v21 = 4 - v7;
    do
    {
      *(_QWORD *)(v20 - 4) = 0i64;
      v20 += 8i64;
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
  unsigned __int16 v1; // ax
  int v2; // edx
  int v3; // er8
  int v4; // eax

  v1 = 1;
  if ( *((_BYTE *)&this->m_PosKeep.0 + 11) & 7 )
    v1 = this->m_PosKeep.m_uNumPos;
  v2 = (unsigned __int8)this->m_PosKeep.m_uListenerMask;
  v3 = v1;
  v4 = 0;
  if ( this->m_PosKeep.m_uListenerMask )
  {
    do
    {
      ++v4;
      v2 &= v2 - 1;
    }
    while ( v2 );
  }
  return (unsigned int)(v3 * v4);
}

// File Line: 224
// RVA: 0xA6AB50
void __fastcall CAkRegisteredObj::CacheEmitListenPairs(CAkRegisteredObj *this, AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *in_arEmitList)
{
  int v2; // ebx
  AkArray<AkRayVolumeData,AkRayVolumeData const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v3; // r15
  AkArray<AkEmitterListenerPairEx,AkEmitterListenerPairEx const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v4; // rbp
  unsigned int v5; // edx
  unsigned int v6; // eax
  signed __int64 v7; // r14
  unsigned __int64 v8; // rsi
  __int64 v9; // rdx
  signed __int64 v10; // r8
  int v11; // eax

  v2 = 0;
  v3 = in_arEmitList;
  v4 = (AkArray<AkEmitterListenerPairEx,AkEmitterListenerPairEx const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)this;
  this->m_arCachedEmitListPairs.m_uLength = 0;
  *((_DWORD *)this + 30) |= 0x40000000u;
  if ( *((_DWORD *)this + 30) < 0 )
  {
    v5 = in_arEmitList->m_uLength;
    v6 = this->m_arCachedEmitListPairs.m_ulReserved;
    if ( v5 <= v6
      || AkArray<AkEmitterListenerPairEx,AkEmitterListenerPairEx const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
           &this->m_arCachedEmitListPairs,
           v5 - v6) )
    {
      if ( v3->m_pItems != &v3->m_pItems[v3->m_uLength] )
      {
        v7 = (signed __int64)&v3->m_pItems->phi;
        do
        {
          v8 = v4[6].m_uLength;
          if ( (v8 < v4[6].m_ulReserved
             || AkArray<AkEmitterListenerPairEx,AkEmitterListenerPairEx const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
                  v4 + 6,
                  1u))
            && v8 < v4[6].m_ulReserved )
          {
            v9 = v4[6].m_uLength;
            v10 = (signed __int64)&v4[6].m_pItems[v9];
            v4[6].m_uLength = v9 + 1;
            if ( v10 )
            {
              *(_BYTE *)(v10 + 16) &= 0xFCu;
              *(_QWORD *)(v10 + 8) = 0i64;
              *(_QWORD *)v10 = 0i64;
              *(_BYTE *)(v10 + 17) = 0;
            }
          }
          else
          {
            v10 = 0i64;
          }
          v11 = *(_DWORD *)(v7 - 8);
          v7 += 36i64;
          *(_DWORD *)v10 = v11;
          *(_DWORD *)(v10 + 4) = *(_DWORD *)(v7 - 40);
          *(_DWORD *)(v10 + 8) = *(_DWORD *)(v7 - 36);
          *(_DWORD *)(v10 + 12) = *(_DWORD *)(v7 - 32);
          *(_BYTE *)(v10 + 16) ^= (*(_BYTE *)(v10 + 16) ^ *(_BYTE *)(v7 - 28)) & 1;
          *(_BYTE *)(v10 + 16) ^= (*(_BYTE *)(v7 - 28) ^ *(_BYTE *)(v10 + 16)) & 2;
          *(_BYTE *)(v10 + 17) = *(_BYTE *)(v7 - 27);
        }
        while ( (AkRayVolumeData *)(v7 - 8) != &v3->m_pItems[v3->m_uLength] );
      }
      LOBYTE(v2) = v3->m_uLength == 0;
      v4[7].m_uLength ^= (v4[7].m_uLength ^ (v2 << 30)) & 0x40000000;
    }
  }
}

// File Line: 258
// RVA: 0xA6AA90
void __fastcall CAkRegisteredObj::CacheEmitListenPair(CAkRegisteredObj *this, AkEmitterListenerPairEx *in_emitListPair)
{
  AkEmitterListenerPairEx *v2; // rdi
  AkArray<AkEmitterListenerPairEx,AkEmitterListenerPairEx const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v3; // rbx
  unsigned __int16 v4; // ax
  int v5; // ecx
  int i; // edx
  AkEmitterListenerPairEx *v7; // rax

  v2 = in_emitListPair;
  v3 = (AkArray<AkEmitterListenerPairEx,AkEmitterListenerPairEx const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)this;
  v4 = 1;
  if ( *((_BYTE *)&this->m_PosKeep.0 + 11) & 7 )
    v4 = this->m_PosKeep.m_uNumPos;
  v5 = (unsigned __int8)this->m_PosKeep.m_uListenerMask;
  for ( i = 0; v5; v5 &= v5 - 1 )
    ++i;
  if ( v4 * i != 1 || (v3[7].m_uLength & 0x80000000) == 0 )
  {
    v3[7].m_uLength |= 0x40000000u;
  }
  else
  {
    v3[6].m_uLength = 0;
    v7 = AkArray<AkEmitterListenerPairEx,AkEmitterListenerPairEx const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(v3 + 6);
    if ( v7 )
    {
      v7->r = v2->r;
      v7->theta = v2->theta;
      v7->phi = v2->phi;
      v7->fEmitterAngle = v2->fEmitterAngle;
      *((_BYTE *)v7 + 16) ^= (*((_BYTE *)v2 + 16) ^ *((_BYTE *)v7 + 16)) & 1;
      *((_BYTE *)v7 + 16) ^= (*((_BYTE *)v2 + 16) ^ *((_BYTE *)v7 + 16)) & 2;
      v7->m_uListenerMask = v2->m_uListenerMask;
      v3[7].m_uLength &= 0xBFFFFFFF;
    }
  }
}

// File Line: 280
// RVA: 0xA6B0F0
signed __int64 __fastcall CAkRegisteredObj::SetObjectObstructionAndOcclusion(CAkRegisteredObj *this, unsigned int in_uListener, float in_fObstructionValue, float in_fOcclusionValue)
{
  CAkRegisteredObj *v4; // r8
  __int64 v6; // rcx

  v4 = this;
  if ( in_uListener >= 8 )
    return 2i64;
  v6 = in_uListener;
  v4->m_fObstructionValue[v6].m_ByteValue = (signed int)(float)(in_fObstructionValue * 255.0);
  v4->m_fOcclusionValue[v6].m_ByteValue = (signed int)(float)(in_fOcclusionValue * 255.0);
  return 1i64;
}

