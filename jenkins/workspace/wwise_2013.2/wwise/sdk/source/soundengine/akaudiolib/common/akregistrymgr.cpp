// File Line: 33
// RVA: 0xA4C930
void __fastcall CAkRegistryMgr::CAkRegistryMgr(CAkRegistryMgr *this)
{
  *(_QWORD *)&this->m_listModifiedNodes.m_ulMinNumListItems = 0i64;
  this->m_listModifiedNodes.m_ulNumListItems = 0;
  this->m_mapRegisteredObj.m_uiSize = 0;
  this->m_mapRegisteredObj.m_MemPoolId = -1;
}

// File Line: 41
// RVA: 0xA4CC40
__int64 __fastcall CAkRegistryMgr::Init(CAkRegistryMgr *this)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item **m_table; // rax
  __int64 v3; // rcx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v4; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v5; // rcx
  unsigned int v6; // edi
  unsigned int v7; // edx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v8; // rax
  CAkRegisteredObj *v9; // rax
  AkSoundPosition in_aPositions; // [rsp+20h] [rbp-28h] BYREF

  this->m_mapRegisteredObj.m_MemPoolId = g_DefaultPoolId;
  m_table = this->m_mapRegisteredObj.m_table;
  this->m_mapRegisteredObj.m_uiSize = 0;
  v3 = 24i64;
  do
  {
    *m_table = 0i64;
    m_table[1] = 0i64;
    m_table[2] = 0i64;
    m_table += 8;
    *(m_table - 5) = 0i64;
    *(m_table - 4) = 0i64;
    *(m_table - 3) = 0i64;
    *(m_table - 2) = 0i64;
    *(m_table - 1) = 0i64;
    --v3;
  }
  while ( v3 );
  *m_table = 0i64;
  this->m_listModifiedNodes.m_ulNumListItems = 0;
  this->m_listModifiedNodes.m_ulMaxNumListItems = -1;
  this->m_listModifiedNodes.m_pFree = 0i64;
  v4 = (CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(
                                                                                             g_DefaultPoolId,
                                                                                             0x80ui64);
  v5 = v4;
  this->m_listModifiedNodes.m_pvMemStart = v4;
  if ( v4 )
  {
    this->m_listModifiedNodes.m_ulMinNumListItems = 8;
    this->m_listModifiedNodes.m_pFree = v4;
    v7 = 0;
    do
    {
      v8 = v5 + 1;
      ++v7;
      v5->pNextListItem = v5 + 1;
      ++v5;
    }
    while ( v7 < this->m_listModifiedNodes.m_ulMinNumListItems );
    v8[-1].pNextListItem = 0i64;
    v6 = 1;
  }
  else
  {
    v6 = 52;
  }
  this->m_listModifiedNodes.m_pFirst = 0i64;
  this->m_listModifiedNodes.m_pLast = 0i64;
  if ( v6 == 1 )
  {
    v9 = CAkRegistryMgr::RegisterObject(this, 0i64, 0xFFu, 0i64);
    if ( v9 )
    {
      memset(&in_aPositions, 0, sizeof(in_aPositions));
      CAkRegisteredObj::SetPosition(v9, &in_aPositions, 1u, MultiPositionType_SingleSource);
    }
  }
  return v6;
}

// File Line: 68
// RVA: 0xA4D4B0
void __fastcall CAkRegistryMgr::Term(CAkRegistryMgr *this)
{
  if ( this->m_mapRegisteredObj.m_MemPoolId != -1 )
    CAkRegistryMgr::UnregisterObject(this, 0i64);
  CAkRegistryMgr::UnregisterAll(this);
  if ( this->m_mapRegisteredObj.m_MemPoolId != -1 )
  {
    AkHashList<AkSwitchKey,unsigned long,193>::RemoveAll((AkHashList<AkSwitchKey,unsigned long,193> *)&this->m_mapRegisteredObj);
    this->m_mapRegisteredObj.m_MemPoolId = -1;
  }
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::Term(&this->m_listModifiedNodes);
}

// File Line: 78
// RVA: 0xA4CAE0
CAkRegisteredObj *__fastcall CAkRegistryMgr::GetObjAndAddref(CAkRegistryMgr *this, unsigned __int64 in_GameObjectID)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v2; // rax
  CAkRegisteredObj *result; // rax
  CAkRegisteredObj **p_item; // rax

  v2 = this->m_mapRegisteredObj.m_table[(unsigned int)in_GameObjectID % 0xC1];
  if ( !v2 )
    return 0i64;
  while ( v2->Assoc.key != in_GameObjectID )
  {
    v2 = v2->pNextItem;
    if ( !v2 )
      return 0i64;
  }
  p_item = &v2->Assoc.item;
  if ( !p_item )
    return 0i64;
  result = *p_item;
  *((_DWORD *)result + 30) ^= (*((_DWORD *)result + 30) ^ (*((_DWORD *)result + 30) + 1)) & 0x3FFFFFFF;
  return result;
}

// File Line: 91
// RVA: 0xA4CDF0
CAkRegisteredObj *__fastcall CAkRegistryMgr::RegisterObject(
        CAkRegistryMgr *this,
        unsigned __int64 in_GameObjectID,
        unsigned int uListenerMask,
        void *in_pMonitorData)
{
  unsigned __int64 v7; // r14
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v8; // rax
  CAkRegisteredObj *v9; // rax
  CAkRegisteredObj *v10; // rax
  CAkRegisteredObj *v11; // rdi
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v12; // rcx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193> *p_m_mapRegisteredObj; // rax
  CAkRegisteredObj **p_item; // rdi
  CAkRegisteredObj **Entry; // rsi
  int v17; // ebx

  v7 = (unsigned int)in_GameObjectID % 0xC1;
  v8 = this->m_mapRegisteredObj.m_table[v7];
  if ( v8 )
  {
    while ( v8->Assoc.key != in_GameObjectID )
    {
      v8 = v8->pNextItem;
      if ( !v8 )
        goto LABEL_4;
    }
    p_item = &v8->Assoc.item;
    if ( v8 != (AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *)-16i64 )
    {
      CAkRegisteredObj::SetActiveListeners(*p_item, uListenerMask);
      return *p_item;
    }
  }
LABEL_4:
  v9 = (CAkRegisteredObj *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x80ui64);
  if ( !v9 )
    return 0i64;
  CAkRegisteredObj::CAkRegisteredObj(v9, in_GameObjectID);
  v11 = v10;
  if ( v10 )
  {
    v12 = this->m_mapRegisteredObj.m_table[v7];
    p_m_mapRegisteredObj = &this->m_mapRegisteredObj;
    if ( v12 )
    {
      while ( v12->Assoc.key != in_GameObjectID )
      {
        v12 = v12->pNextItem;
        if ( !v12 )
          goto LABEL_13;
      }
      Entry = &v12->Assoc.item;
      if ( v12 != (AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *)-16i64 )
        goto LABEL_14;
    }
LABEL_13:
    Entry = AkHashList<unsigned __int64,CAkRegisteredObj *,193>::CreateEntry(p_m_mapRegisteredObj, in_GameObjectID, v7);
    if ( Entry )
    {
LABEL_14:
      CAkRegisteredObj::SetActiveListeners(v11, uListenerMask);
      *Entry = v11;
      return v11;
    }
    v17 = g_DefaultPoolId;
    CAkRegisteredObj::~CAkRegisteredObj(v11);
    AK::MemoryMgr::Free(v17, v11);
    return 0i64;
  }
  return v11;
}

// File Line: 126
// RVA: 0xA4D680
void __fastcall CAkRegistryMgr::UnregisterObject(CAkRegistryMgr *this, unsigned __int64 in_GameObjectID)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193> *p_m_mapRegisteredObj; // rbx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v4; // r8
  __int64 v5; // rcx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v6; // rdx
  char *v7; // r10
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *pNextItem; // r9
  CAkRegisteredObj *item; // rdi
  int v10; // ecx
  int v11; // ebx

  p_m_mapRegisteredObj = &this->m_mapRegisteredObj;
  v4 = 0i64;
  v5 = (unsigned int)in_GameObjectID % 0xC1;
  v6 = p_m_mapRegisteredObj->m_table[v5];
  v7 = (char *)p_m_mapRegisteredObj + 8 * v5;
  if ( v6 )
  {
    while ( v6->Assoc.key != in_GameObjectID )
    {
      v4 = v6;
      v6 = v6->pNextItem;
      if ( !v6 )
        return;
    }
    pNextItem = v6->pNextItem;
    item = v6->Assoc.item;
    if ( !v6->pNextItem )
    {
      do
        v5 = (unsigned int)(v5 + 1);
      while ( (unsigned int)v5 < 0xC1 && !p_m_mapRegisteredObj->m_table[v5] );
    }
    if ( v4 )
      v4->pNextItem = pNextItem;
    else
      *((_QWORD *)v7 + 1) = pNextItem;
    AK::MemoryMgr::Free(p_m_mapRegisteredObj->m_MemPoolId, v6);
    --p_m_mapRegisteredObj->m_uiSize;
    v10 = *((_DWORD *)item + 30) & 0x7FFFFFFF ^ (*((_DWORD *)item + 30) & 0x7FFFFFFF ^ ((*((_DWORD *)item + 30) & 0x7FFFFFFF)
                                                                                      - 1)) & 0x3FFFFFFF;
    *((_DWORD *)item + 30) = v10;
    if ( (v10 & 0x3FFFFFFF) == 0 )
    {
      v11 = g_DefaultPoolId;
      CAkRegisteredObj::~CAkRegisteredObj(item);
      AK::MemoryMgr::Free(v11, item);
    }
  }
}

// File Line: 156
// RVA: 0xA4D360
__int64 __fastcall CAkRegistryMgr::SetPosition(
        CAkRegistryMgr *this,
        unsigned __int64 in_GameObjectID,
        AkSoundPosition *in_aPositions,
        unsigned __int16 in_uNumPositions,
        AK::SoundEngine::MultiPositionType in_eMultiPositionType)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v5; // rax

  v5 = this->m_mapRegisteredObj.m_table[(unsigned int)in_GameObjectID % 0xC1];
  if ( !v5 )
    return 2i64;
  while ( v5->Assoc.key != in_GameObjectID )
  {
    v5 = v5->pNextItem;
    if ( !v5 )
      return 2i64;
  }
  if ( v5 == (AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *)-16i64 )
    return 2i64;
  CAkRegisteredObj::SetPosition(v5->Assoc.item, in_aPositions, in_uNumPositions, in_eMultiPositionType);
  return 1i64;
}

// File Line: 170
// RVA: 0xA4D0C0
__int64 __fastcall CAkRegistryMgr::SetActiveListeners(
        CAkRegistryMgr *this,
        unsigned __int64 in_GameObjectID,
        unsigned int in_uListenerMask)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v4; // rax
  CAkRegisteredObj **p_item; // rbx

  v4 = this->m_mapRegisteredObj.m_table[(unsigned int)in_GameObjectID % 0xC1];
  if ( !v4 )
    return 2i64;
  while ( v4->Assoc.key != in_GameObjectID )
  {
    v4 = v4->pNextItem;
    if ( !v4 )
      return 2i64;
  }
  p_item = &v4->Assoc.item;
  if ( v4 == (AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *)-16i64 )
    return 2i64;
  CAkLEngine::ReevaluateBussesForGameObject(
    *p_item,
    (unsigned __int8)(*p_item)->m_PosKeep.m_uListenerMask,
    in_uListenerMask);
  CAkRegisteredObj::SetActiveListeners(*p_item, in_uListenerMask);
  return 1i64;
}

// File Line: 219
// RVA: 0xA4D140
AKRESULT __fastcall CAkRegistryMgr::SetGameObjectAuxSendValues(
        CAkRegistryMgr *this,
        unsigned __int64 in_GameObjectID,
        AkAuxSendValue *in_aEnvironmentValues,
        unsigned int in_uNumEnvValues)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v4; // rax

  v4 = this->m_mapRegisteredObj.m_table[(unsigned int)in_GameObjectID % 0xC1];
  if ( !v4 )
    return 2;
  while ( v4->Assoc.key != in_GameObjectID )
  {
    v4 = v4->pNextItem;
    if ( !v4 )
      return 2;
  }
  if ( v4 == (AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *)-16i64 )
    return 2;
  else
    return CAkRegisteredObj::SetGameObjectAuxSendValues(v4->Assoc.item, in_aEnvironmentValues, in_uNumEnvValues);
}

// File Line: 231
// RVA: 0xA4D190
__int64 __fastcall CAkRegistryMgr::SetGameObjectOutputBusVolume(
        CAkRegistryMgr *this,
        unsigned __int64 in_GameObjectID,
        float in_fControlValue)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v3; // r8

  v3 = this->m_mapRegisteredObj.m_table[(unsigned int)in_GameObjectID % 0xC1];
  if ( !v3 )
    return 2i64;
  while ( v3->Assoc.key != in_GameObjectID )
  {
    v3 = v3->pNextItem;
    if ( !v3 )
      return 2i64;
  }
  if ( v3 == (AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *)-16i64 )
    return 2i64;
  v3->Assoc.item->m_fDryLevelValue = in_fControlValue;
  return 1i64;
}

// File Line: 244
// RVA: 0xA4D1E0
__int64 __fastcall CAkRegistryMgr::SetGameObjectScalingFactor(
        CAkRegistryMgr *this,
        unsigned __int64 in_GameObjectID,
        float in_fControlValue)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v3; // r8
  CAkRegisteredObj *item; // rax

  v3 = this->m_mapRegisteredObj.m_table[(unsigned int)in_GameObjectID % 0xC1];
  if ( !v3 )
    return 2i64;
  while ( v3->Assoc.key != in_GameObjectID )
  {
    v3 = v3->pNextItem;
    if ( !v3 )
      return 2i64;
  }
  if ( v3 == (AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *)-16i64 )
    return 2i64;
  item = v3->Assoc.item;
  *((_DWORD *)item + 30) |= 0x40000000u;
  item->m_fScalingFactor = in_fControlValue;
  return 1i64;
}

// File Line: 259
// RVA: 0xA4D300
AKRESULT __fastcall CAkRegistryMgr::SetObjectObstructionAndOcclusion(
        CAkRegistryMgr *this,
        unsigned __int64 in_GameObjectID,
        unsigned int in_uListener,
        float in_fObstructionLevel,
        float in_fOcclusionLevel)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v5; // r9

  v5 = this->m_mapRegisteredObj.m_table[(unsigned int)in_GameObjectID % 0xC1];
  if ( !v5 )
    return 2;
  while ( v5->Assoc.key != in_GameObjectID )
  {
    v5 = v5->pNextItem;
    if ( !v5 )
      return 2;
  }
  if ( v5 == (AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *)-16i64 )
    return 2;
  else
    return CAkRegisteredObj::SetObjectObstructionAndOcclusion(
             v5->Assoc.item,
             in_uListener,
             in_fObstructionLevel,
             in_fOcclusionLevel);
}

// File Line: 271
// RVA: 0xA4CB30
AkSwitchHistItem __fastcall CAkRegistryMgr::GetSwitchHistItem(
        CAkRegistryMgr *this,
        CAkRegisteredObj *in_pGameObj,
        __int64 in_SwitchContID,
        int a4)
{
  _DWORD *v4; // rax
  _DWORD *v5; // rcx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> **v6; // rax

  if ( !in_SwitchContID )
    goto LABEL_8;
  v4 = *(_DWORD **)(in_SwitchContID + 56);
  v5 = &v4[3 * *(unsigned int *)(in_SwitchContID + 64)];
  if ( v4 == v5 )
    goto LABEL_8;
  do
  {
    if ( *v4 == a4 )
      break;
    v4 += 3;
  }
  while ( v4 != v5 );
  if ( v4 == v5 || (v6 = (CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> **)(v4 + 1)) == 0i64 )
  {
LABEL_8:
    in_pGameObj->m_pListModifiedNodes = 0i64;
    return (AkSwitchHistItem)in_pGameObj;
  }
  else
  {
    in_pGameObj->m_pListModifiedNodes = *v6;
    return (AkSwitchHistItem)in_pGameObj;
  }
}

// File Line: 293
// RVA: 0xA4D3E0
__int64 __fastcall CAkRegistryMgr::SetSwitchHistItem(
        CAkRegistryMgr *this,
        CAkRegisteredObj *in_pGameObj,
        unsigned int in_SwitchContID,
        AkSwitchHistItem *in_SwitchHistItem)
{
  if ( in_pGameObj )
    return 2
         - (unsigned int)(CAkKeyArray<unsigned long,AkSwitchHistItem,5>::Set(
                            &in_pGameObj->m_SwitchHist,
                            in_SwitchContID,
                            *in_SwitchHistItem) != 0i64);
  else
    return 2i64;
}

// File Line: 306
// RVA: 0xA4C950
__int64 __fastcall CAkRegistryMgr::ClearSwitchHist(
        CAkRegistryMgr *this,
        unsigned int in_SwitchContID,
        CAkRegisteredObj *in_pGameObj)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v5; // r10
  __int64 v6; // r9
  CAkRegisteredObj *item; // r8
  MapStruct<unsigned long,AkSwitchHistItem> *m_pItems; // rdi
  MapStruct<unsigned long,AkSwitchHistItem> *v9; // rax
  MapStruct<unsigned long,AkSwitchHistItem> *v10; // rsi
  unsigned __int64 i; // rcx

  if ( in_pGameObj )
  {
    CAkKeyArray<unsigned long,AkSwitchHistItem,5>::Unset(&in_pGameObj->m_SwitchHist, in_SwitchContID);
    return 1i64;
  }
  else
  {
    v5 = this->m_mapRegisteredObj.m_table[0];
    LODWORD(v6) = 0;
    if ( v5 )
    {
      do
      {
LABEL_8:
        item = v5->Assoc.item;
        m_pItems = item->m_SwitchHist.m_pItems;
        v9 = &m_pItems[item->m_SwitchHist.m_uLength];
        if ( m_pItems != v9 )
        {
          do
          {
            if ( m_pItems->key == in_SwitchContID )
              break;
            ++m_pItems;
          }
          while ( m_pItems != v9 );
          if ( m_pItems != v9 )
          {
            if ( m_pItems < &v9[-1] )
            {
              v10 = m_pItems + 1;
              for ( i = (12 * (((char *)&v9[-1] - (char *)m_pItems - 1) / 0xCui64 + 1)) >> 2; i; --i )
              {
                m_pItems->key = v10->key;
                v10 = (MapStruct<unsigned long,AkSwitchHistItem> *)((char *)v10 + 4);
                m_pItems = (MapStruct<unsigned long,AkSwitchHistItem> *)((char *)m_pItems + 4);
              }
            }
            --item->m_SwitchHist.m_uLength;
          }
        }
        v5 = v5->pNextItem;
      }
      while ( v5 );
      while ( 1 )
      {
        v6 = (unsigned int)(v6 + 1);
        if ( (unsigned int)v6 >= 0xC1 )
          break;
        v5 = this->m_mapRegisteredObj.m_table[v6];
        if ( v5 )
          goto LABEL_8;
      }
    }
    else
    {
      while ( 1 )
      {
        v6 = (unsigned int)(v6 + 1);
        if ( (unsigned int)v6 >= 0xC1 )
          break;
        v5 = this->m_mapRegisteredObj.m_table[v6];
        if ( v5 )
          goto LABEL_8;
      }
    }
    return 1i64;
  }
}

// File Line: 321
// RVA: 0xA4D500
void __fastcall CAkRegistryMgr::UnregisterAll(CAkRegistryMgr *this)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193> *p_m_mapRegisteredObj; // r12
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v2; // rsi
  __int64 v3; // rdi
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v4; // r14
  CAkRegisteredObj *item; // rbp
  int v6; // ecx
  int v7; // ebx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *pNextItem; // rdx
  __int64 v9; // rcx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v10; // rbp
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v11; // rbx
  int v12; // [rsp+28h] [rbp-50h]

  p_m_mapRegisteredObj = &this->m_mapRegisteredObj;
  if ( this->m_mapRegisteredObj.m_MemPoolId != -1 )
  {
    v2 = this->m_mapRegisteredObj.m_table[0];
    LODWORD(v3) = 0;
    v4 = 0i64;
    if ( v2 )
      goto LABEL_7;
    while ( 1 )
    {
      v3 = (unsigned int)(v3 + 1);
      if ( (unsigned int)v3 >= 0xC1 )
        break;
      v2 = p_m_mapRegisteredObj->m_table[v3];
      if ( v2 )
      {
        while ( 1 )
        {
LABEL_7:
          while ( v2->Assoc.key )
          {
            item = v2->Assoc.item;
            v6 = *((_DWORD *)item + 30) ^ (*((_DWORD *)item + 30) ^ (*((_DWORD *)item + 30) - 1)) & 0x3FFFFFFF;
            *((_DWORD *)item + 30) = v6;
            if ( (v6 & 0x3FFFFFFF) == 0 )
            {
              v7 = g_DefaultPoolId;
              CAkRegisteredObj::~CAkRegisteredObj(item);
              AK::MemoryMgr::Free(v7, item);
            }
            pNextItem = v2->pNextItem;
            LODWORD(v9) = v3;
            v10 = v4;
            v12 = v3;
            v11 = v2->pNextItem;
            if ( !v2->pNextItem )
            {
              do
              {
                v9 = (unsigned int)(v9 + 1);
                if ( (unsigned int)v9 >= 0xC1 )
                  break;
                v11 = p_m_mapRegisteredObj->m_table[v9];
                v10 = 0i64;
              }
              while ( !v11 );
              v12 = v9;
            }
            if ( v4 )
              v4->pNextItem = pNextItem;
            else
              p_m_mapRegisteredObj->m_table[(unsigned int)v3] = pNextItem;
            AK::MemoryMgr::Free(p_m_mapRegisteredObj->m_MemPoolId, v2);
            --p_m_mapRegisteredObj->m_uiSize;
            LODWORD(v3) = v12;
            v2 = v11;
            v4 = v10;
LABEL_18:
            if ( !v2 )
              return;
          }
          v4 = v2;
          v2 = v2->pNextItem;
          if ( !v2 )
          {
            while ( 1 )
            {
              v3 = (unsigned int)(v3 + 1);
              if ( (unsigned int)v3 >= 0xC1 )
                goto LABEL_18;
              v2 = p_m_mapRegisteredObj->m_table[v3];
              v4 = 0i64;
              if ( v2 )
                goto LABEL_7;
            }
          }
        }
      }
    }
  }
}

// File Line: 342
// RVA: 0xA4D240
void __fastcall CAkRegistryMgr::SetNodeIDAsModified(CAkRegistryMgr *this, CAkParameterNodeBase *in_pNode)
{
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *m_pFirst; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v4; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *m_pLast; // rcx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *m_pFree; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v7; // rcx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v8; // rcx
  WwiseObjectIDext v9; // [rsp+30h] [rbp+8h]

  m_pFirst = this->m_listModifiedNodes.m_pFirst;
  v9.id = in_pNode->key;
  v9.bIsBus = (*((_BYTE *)in_pNode + 83) & 2) != 0;
  if ( !this->m_listModifiedNodes.m_pFirst )
    goto LABEL_7;
  while ( in_pNode->key != m_pFirst->Item.id || ((*((_BYTE *)in_pNode + 83) & 2) != 0) != m_pFirst->Item.bIsBus )
  {
    m_pFirst = m_pFirst->pNextListItem;
    if ( !m_pFirst )
      goto LABEL_7;
  }
  if ( m_pFirst == (CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *)-8i64 )
  {
LABEL_7:
    if ( !this->m_listModifiedNodes.m_pFree )
    {
      if ( this->m_listModifiedNodes.m_ulNumListItems >= this->m_listModifiedNodes.m_ulMaxNumListItems )
        return;
      v4 = (CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(
                                                                                                 g_DefaultPoolId,
                                                                                                 0x10ui64);
      if ( !v4 )
        return;
      v4->pNextListItem = this->m_listModifiedNodes.m_pFree;
      this->m_listModifiedNodes.m_pFree = v4;
    }
    m_pLast = this->m_listModifiedNodes.m_pLast;
    m_pFree = this->m_listModifiedNodes.m_pFree;
    if ( m_pLast )
      m_pLast->pNextListItem = m_pFree;
    else
      this->m_listModifiedNodes.m_pFirst = m_pFree;
    v7 = this->m_listModifiedNodes.m_pFree;
    this->m_listModifiedNodes.m_pLast = v7;
    this->m_listModifiedNodes.m_pFree = v7->pNextListItem;
    v7->pNextListItem = 0i64;
    v8 = this->m_listModifiedNodes.m_pLast;
    ++this->m_listModifiedNodes.m_ulNumListItems;
    v8->Item = v9;
  }
}

// File Line: 356
// RVA: 0xA4CD60
void __fastcall CAkRegistryMgr::NotifyListenerPosChanged(CAkRegistryMgr *this, unsigned __int8 in_uListenerMask)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v2; // r8
  AkHashList<unsigned __int64,CAkRegisteredObj *,193> *p_m_mapRegisteredObj; // r10
  CAkRegisteredObj *item; // rdx
  int v6; // r9d
  int v7; // eax

  v2 = this->m_mapRegisteredObj.m_table[0];
  p_m_mapRegisteredObj = &this->m_mapRegisteredObj;
  LODWORD(this) = 0;
  if ( v2 )
  {
    do
    {
LABEL_6:
      item = v2->Assoc.item;
      v6 = *((_DWORD *)item + 30);
      v7 = (v6 & 0x40000000) != 0 || (item->m_PosKeep.m_uListenerMask & in_uListenerMask) != 0;
      *((_DWORD *)item + 30) = v6 ^ (v6 ^ (v7 << 30)) & 0x40000000;
      v2 = v2->pNextItem;
    }
    while ( v2 );
    while ( 1 )
    {
      this = (CAkRegistryMgr *)(unsigned int)((_DWORD)this + 1);
      if ( (unsigned int)this >= 0xC1 )
        break;
      v2 = p_m_mapRegisteredObj->m_table[(_QWORD)this];
      if ( v2 )
        goto LABEL_6;
    }
  }
  else
  {
    while ( 1 )
    {
      this = (CAkRegistryMgr *)(unsigned int)((_DWORD)this + 1);
      if ( (unsigned int)this >= 0xC1 )
        break;
      v2 = p_m_mapRegisteredObj->m_table[(_QWORD)this];
      if ( v2 )
        goto LABEL_6;
    }
  }
}

