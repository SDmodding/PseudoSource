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
  CAkRegistryMgr *v1; // rbx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item **v2; // rax
  signed __int64 v3; // rcx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v4; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v5; // rcx
  unsigned int v6; // edi
  unsigned int v7; // edx
  signed __int64 v8; // rax
  CAkRegisteredObj *v9; // rax
  AkSoundPosition in_aPositions; // [rsp+20h] [rbp-28h]

  v1 = this;
  this->m_mapRegisteredObj.m_MemPoolId = g_DefaultPoolId;
  v2 = this->m_mapRegisteredObj.m_table;
  this->m_mapRegisteredObj.m_uiSize = 0;
  v3 = 24i64;
  do
  {
    *v2 = 0i64;
    v2[1] = 0i64;
    v2[2] = 0i64;
    v2 += 8;
    *(v2 - 5) = 0i64;
    *(v2 - 4) = 0i64;
    *(v2 - 3) = 0i64;
    *(v2 - 2) = 0i64;
    *(v2 - 1) = 0i64;
    --v3;
  }
  while ( v3 );
  *v2 = 0i64;
  v1->m_listModifiedNodes.m_ulNumListItems = 0;
  v1->m_listModifiedNodes.m_ulMaxNumListItems = -1;
  v1->m_listModifiedNodes.m_pFree = 0i64;
  v4 = (CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(
                                                                                             g_DefaultPoolId,
                                                                                             0x80ui64);
  v5 = v4;
  v1->m_listModifiedNodes.m_pvMemStart = v4;
  if ( v4 )
  {
    v1->m_listModifiedNodes.m_ulMinNumListItems = 8;
    v1->m_listModifiedNodes.m_pFree = v4;
    v7 = 0;
    do
    {
      v8 = (signed __int64)&v5[1];
      ++v7;
      v5->pNextListItem = v5 + 1;
      ++v5;
    }
    while ( v7 < v1->m_listModifiedNodes.m_ulMinNumListItems );
    *(_QWORD *)(v8 - 16) = 0i64;
    v6 = 1;
  }
  else
  {
    v6 = 52;
  }
  v1->m_listModifiedNodes.m_pFirst = 0i64;
  v1->m_listModifiedNodes.m_pLast = 0i64;
  if ( v6 == 1 )
  {
    v9 = CAkRegistryMgr::RegisterObject(v1, 0i64, 0xFFu, 0i64);
    if ( v9 )
    {
      *(_QWORD *)&in_aPositions.Position.Y = 0i64;
      *(_QWORD *)&in_aPositions.Orientation.X = 0i64;
      in_aPositions.Orientation.Z = 0.0;
      in_aPositions.Position.X = 0.0;
      CAkRegisteredObj::SetPosition(v9, &in_aPositions, 1u, 0);
    }
  }
  return v6;
}

// File Line: 68
// RVA: 0xA4D4B0
void __fastcall CAkRegistryMgr::Term(CAkRegistryMgr *this)
{
  CAkRegistryMgr *v1; // rbx

  v1 = this;
  if ( this->m_mapRegisteredObj.m_MemPoolId != -1 )
    CAkRegistryMgr::UnregisterObject(this, 0i64);
  CAkRegistryMgr::UnregisterAll(v1);
  if ( v1->m_mapRegisteredObj.m_MemPoolId != -1 )
  {
    AkHashList<AkSwitchKey,unsigned long,193>::RemoveAll((AkHashList<AkSwitchKey,unsigned long,193> *)&v1->m_mapRegisteredObj);
    v1->m_mapRegisteredObj.m_MemPoolId = -1;
  }
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::Term(&v1->m_listModifiedNodes);
}

// File Line: 78
// RVA: 0xA4CAE0
CAkRegisteredObj *__fastcall CAkRegistryMgr::GetObjAndAddref(CAkRegistryMgr *this, unsigned __int64 in_GameObjectID)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v2; // rax
  CAkRegisteredObj *result; // rax
  CAkRegisteredObj **v4; // rax

  v2 = this->m_mapRegisteredObj.m_table[(unsigned int)in_GameObjectID % 0xC1];
  if ( !v2 )
    return 0i64;
  while ( v2->Assoc.key != in_GameObjectID )
  {
    v2 = v2->pNextItem;
    if ( !v2 )
      return 0i64;
  }
  v4 = &v2->Assoc.item;
  if ( !v4 )
    return 0i64;
  result = *v4;
  *((_DWORD *)result + 30) ^= (*((_DWORD *)result + 30) ^ (*((_DWORD *)result + 30) + 1)) & 0x3FFFFFFF;
  return result;
}

// File Line: 91
// RVA: 0xA4CDF0
CAkRegisteredObj *__fastcall CAkRegistryMgr::RegisterObject(CAkRegistryMgr *this, unsigned __int64 in_GameObjectID, unsigned int uListenerMask, void *in_pMonitorData)
{
  unsigned __int64 v4; // rbx
  unsigned int v5; // ebp
  CAkRegistryMgr *v6; // rsi
  unsigned __int64 v7; // r14
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v8; // rax
  CAkRegisteredObj *v9; // rax
  CAkRegisteredObj *v10; // rax
  CAkRegisteredObj *v11; // rdi
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v12; // rcx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193> *v13; // rax
  CAkRegisteredObj **v14; // rdi
  CAkRegisteredObj **v16; // rsi
  int v17; // ebx

  v4 = in_GameObjectID;
  v5 = uListenerMask;
  v6 = this;
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
    v14 = &v8->Assoc.item;
    if ( v8 != (AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *)-16i64 )
    {
      CAkRegisteredObj::SetActiveListeners(*v14, uListenerMask);
      return *v14;
    }
  }
LABEL_4:
  v9 = (CAkRegisteredObj *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x80ui64);
  if ( !v9 )
    goto LABEL_16;
  CAkRegisteredObj::CAkRegisteredObj(v9, v4);
  v11 = v10;
  if ( v10 )
  {
    v12 = v6->m_mapRegisteredObj.m_table[v7];
    v13 = &v6->m_mapRegisteredObj;
    if ( v12 )
    {
      while ( v12->Assoc.key != v4 )
      {
        v12 = v12->pNextItem;
        if ( !v12 )
          goto LABEL_13;
      }
      v16 = &v12->Assoc.item;
      if ( v12 != (AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *)-16i64 )
        goto LABEL_14;
    }
LABEL_13:
    v16 = AkHashList<unsigned __int64,CAkRegisteredObj *,193>::CreateEntry(v13, v4, v7);
    if ( v16 )
    {
LABEL_14:
      CAkRegisteredObj::SetActiveListeners(v11, v5);
      *v16 = v11;
      return v11;
    }
    v17 = g_DefaultPoolId;
    CAkRegisteredObj::~CAkRegisteredObj(v11);
    AK::MemoryMgr::Free(v17, v11);
LABEL_16:
    v11 = 0i64;
  }
  return v11;
}

// File Line: 126
// RVA: 0xA4D680
void __fastcall CAkRegistryMgr::UnregisterObject(CAkRegistryMgr *this, unsigned __int64 in_GameObjectID)
{
  unsigned __int64 v2; // r9
  int *v3; // rbx
  _QWORD *v4; // r8
  __int64 v5; // rcx
  _QWORD *v6; // rdx
  signed __int64 v7; // r10
  __int64 v8; // r9
  __int64 v9; // rdi
  int v10; // ecx
  int v11; // ebx

  v2 = in_GameObjectID;
  v3 = &this->m_mapRegisteredObj.m_MemPoolId;
  v4 = 0i64;
  v5 = (unsigned int)in_GameObjectID % 0xC1;
  v6 = *(_QWORD **)&v3[2 * v5 + 2];
  v7 = (signed __int64)&v3[2 * v5];
  if ( v6 )
  {
    while ( v6[1] != v2 )
    {
      v4 = v6;
      v6 = (_QWORD *)*v6;
      if ( !v6 )
        return;
    }
    v8 = *v6;
    v9 = v6[2];
    if ( !*v6 )
    {
      do
        v5 = (unsigned int)(v5 + 1);
      while ( (unsigned int)v5 < 0xC1 && !*(_QWORD *)&v3[2 * v5 + 2] );
    }
    if ( v4 )
      *v4 = v8;
    else
      *(_QWORD *)(v7 + 8) = v8;
    AK::MemoryMgr::Free(*v3, v6);
    --v3[388];
    v10 = *(_DWORD *)(v9 + 120) & 0x7FFFFFFF ^ (*(_DWORD *)(v9 + 120) & 0x7FFFFFFF ^ ((*(_DWORD *)(v9 + 120) & 0x7FFFFFFF)
                                                                                    - 1)) & 0x3FFFFFFF;
    *(_DWORD *)(v9 + 120) = v10;
    if ( !(v10 & 0x3FFFFFFF) )
    {
      v11 = g_DefaultPoolId;
      CAkRegisteredObj::~CAkRegisteredObj((CAkRegisteredObj *)v9);
      AK::MemoryMgr::Free(v11, (void *)v9);
    }
  }
}

// File Line: 156
// RVA: 0xA4D360
signed __int64 __fastcall CAkRegistryMgr::SetPosition(CAkRegistryMgr *this, unsigned __int64 in_GameObjectID, AkSoundPosition *in_aPositions, unsigned __int16 in_uNumPositions, AK::SoundEngine::MultiPositionType in_eMultiPositionType)
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
signed __int64 __fastcall CAkRegistryMgr::SetActiveListeners(CAkRegistryMgr *this, unsigned __int64 in_GameObjectID, unsigned int in_uListenerMask)
{
  unsigned int v3; // edi
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v4; // rax
  CAkRegisteredObj **v6; // rbx

  v3 = in_uListenerMask;
  v4 = this->m_mapRegisteredObj.m_table[(unsigned int)in_GameObjectID % 0xC1];
  if ( !v4 )
    return 2i64;
  while ( v4->Assoc.key != in_GameObjectID )
  {
    v4 = v4->pNextItem;
    if ( !v4 )
      return 2i64;
  }
  v6 = &v4->Assoc.item;
  if ( v4 == (AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *)-16i64 )
    return 2i64;
  CAkLEngine::ReevaluateBussesForGameObject(*v6, (unsigned __int8)(*v6)->m_PosKeep.m_uListenerMask, in_uListenerMask);
  CAkRegisteredObj::SetActiveListeners(*v6, v3);
  return 1i64;
}

// File Line: 219
// RVA: 0xA4D140
AKRESULT __fastcall CAkRegistryMgr::SetGameObjectAuxSendValues(CAkRegistryMgr *this, unsigned __int64 in_GameObjectID, AkAuxSendValue *in_aEnvironmentValues, unsigned int in_uNumEnvValues)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v4; // rax
  AKRESULT result; // eax

  v4 = this->m_mapRegisteredObj.m_table[(unsigned int)in_GameObjectID % 0xC1];
  if ( !v4 )
    goto LABEL_4;
  while ( v4->Assoc.key != in_GameObjectID )
  {
    v4 = v4->pNextItem;
    if ( !v4 )
      goto LABEL_4;
  }
  if ( v4 != (AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *)-16i64 )
    result = CAkRegisteredObj::SetGameObjectAuxSendValues(v4->Assoc.item, in_aEnvironmentValues, in_uNumEnvValues);
  else
LABEL_4:
    result = 2;
  return result;
}

// File Line: 231
// RVA: 0xA4D190
signed __int64 __fastcall CAkRegistryMgr::SetGameObjectOutputBusVolume(CAkRegistryMgr *this, unsigned __int64 in_GameObjectID, float in_fControlValue)
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
signed __int64 __fastcall CAkRegistryMgr::SetGameObjectScalingFactor(CAkRegistryMgr *this, unsigned __int64 in_GameObjectID, float in_fControlValue)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v3; // r8
  CAkRegisteredObj *v5; // rax

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
  v5 = v3->Assoc.item;
  *((_DWORD *)v5 + 30) |= 0x40000000u;
  v5->m_fScalingFactor = in_fControlValue;
  return 1i64;
}

// File Line: 259
// RVA: 0xA4D300
AKRESULT __fastcall CAkRegistryMgr::SetObjectObstructionAndOcclusion(CAkRegistryMgr *this, unsigned __int64 in_GameObjectID, unsigned int in_uListener, float in_fObstructionLevel, float in_fOcclusionLevel)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v5; // r9
  AKRESULT result; // eax

  v5 = this->m_mapRegisteredObj.m_table[(unsigned int)in_GameObjectID % 0xC1];
  if ( !v5 )
    goto LABEL_4;
  while ( v5->Assoc.key != in_GameObjectID )
  {
    v5 = v5->pNextItem;
    if ( !v5 )
      goto LABEL_4;
  }
  if ( v5 != (AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *)-16i64 )
    result = CAkRegisteredObj::SetObjectObstructionAndOcclusion(
               v5->Assoc.item,
               in_uListener,
               in_fObstructionLevel,
               in_fOcclusionLevel);
  else
LABEL_4:
    result = 2;
  return result;
}

// File Line: 271
// RVA: 0xA4CB30
CAkRegisteredObj *__fastcall CAkRegistryMgr::GetSwitchHistItem(CAkRegistryMgr *this, CAkRegisteredObj *in_pGameObj, __int64 in_SwitchContID, int a4)
{
  _DWORD *v4; // rax
  signed __int64 v5; // rcx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> **v6; // rax
  CAkRegisteredObj *result; // rax

  if ( !in_SwitchContID )
    goto LABEL_11;
  v4 = *(_DWORD **)(in_SwitchContID + 56);
  v5 = (signed __int64)&v4[3 * *(unsigned int *)(in_SwitchContID + 64)];
  if ( v4 == (_DWORD *)v5 )
    goto LABEL_11;
  do
  {
    if ( *v4 == a4 )
      break;
    v4 += 3;
  }
  while ( v4 != (_DWORD *)v5 );
  if ( v4 != (_DWORD *)v5
    && (v6 = (CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault> **)(v4 + 1)) != 0i64 )
  {
    in_pGameObj->m_pListModifiedNodes = *v6;
    result = in_pGameObj;
  }
  else
  {
LABEL_11:
    in_pGameObj->m_pListModifiedNodes = 0i64;
    result = in_pGameObj;
  }
  return result;
}

// File Line: 293
// RVA: 0xA4D3E0
signed __int64 __fastcall CAkRegistryMgr::SetSwitchHistItem(CAkRegistryMgr *this, CAkRegisteredObj *in_pGameObj, unsigned int in_SwitchContID, AkSwitchHistItem *in_SwitchHistItem)
{
  signed __int64 result; // rax

  if ( in_pGameObj )
    result = 2
           - (unsigned int)(CAkKeyArray<unsigned long,AkSwitchHistItem,5>::Set(
                              &in_pGameObj->m_SwitchHist,
                              in_SwitchContID,
                              *in_SwitchHistItem) != 0i64);
  else
    result = 2i64;
  return result;
}

// File Line: 306
// RVA: 0xA4C950
signed __int64 __fastcall CAkRegistryMgr::ClearSwitchHist(CAkRegistryMgr *this, unsigned int in_SwitchContID, CAkRegisteredObj *in_pGameObj)
{
  CAkRegistryMgr *v3; // rbx
  signed __int64 result; // rax
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v5; // r10
  __int64 v6; // r9
  CAkRegisteredObj *v7; // r8
  MapStruct<unsigned long,AkSwitchHistItem> *v8; // rdi
  signed __int64 v9; // rax
  MapStruct<unsigned long,AkSwitchHistItem> *v10; // rsi
  unsigned __int64 i; // rcx

  v3 = this;
  if ( in_pGameObj )
  {
    CAkKeyArray<unsigned long,AkSwitchHistItem,5>::Unset(&in_pGameObj->m_SwitchHist, in_SwitchContID);
    result = 1i64;
  }
  else
  {
    v5 = this->m_mapRegisteredObj.m_table[0];
    LODWORD(v6) = 0;
    if ( v5 )
      goto LABEL_25;
    while ( 1 )
    {
      v6 = (unsigned int)(v6 + 1);
      if ( (unsigned int)v6 >= 0xC1 )
        break;
      v5 = this->m_mapRegisteredObj.m_table[v6];
      if ( v5 )
        goto LABEL_8;
    }
    if ( v5 )
    {
LABEL_25:
      do
      {
        do
        {
LABEL_8:
          v7 = v5->Assoc.item;
          v8 = v7->m_SwitchHist.m_pItems;
          v9 = (signed __int64)&v8[v7->m_SwitchHist.m_uLength];
          if ( v8 != (MapStruct<unsigned long,AkSwitchHistItem> *)v9 )
          {
            do
            {
              if ( v8->key == in_SwitchContID )
                break;
              ++v8;
            }
            while ( v8 != (MapStruct<unsigned long,AkSwitchHistItem> *)v9 );
            if ( v8 != (MapStruct<unsigned long,AkSwitchHistItem> *)v9 )
            {
              if ( (unsigned __int64)v8 < v9 - 12 )
              {
                v10 = v8 + 1;
                for ( i = 12
                        * (((unsigned __int64)((unsigned __int64)(v9 - 12 - (_QWORD)v8 - 1)
                                             * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 3)
                         + 1) >> 2; i; --i )
                {
                  v8->key = v10->key;
                  v10 = (MapStruct<unsigned long,AkSwitchHistItem> *)((char *)v10 + 4);
                  v8 = (MapStruct<unsigned long,AkSwitchHistItem> *)((char *)v8 + 4);
                }
              }
              --v7->m_SwitchHist.m_uLength;
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
          v5 = v3->m_mapRegisteredObj.m_table[v6];
          if ( v5 )
            goto LABEL_8;
        }
      }
      while ( v5 );
    }
    result = 1i64;
  }
  return result;
}

// File Line: 321
// RVA: 0xA4D500
void __fastcall CAkRegistryMgr::UnregisterAll(CAkRegistryMgr *this)
{
  int *v1; // r12
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v2; // rsi
  __int64 v3; // rdi
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v4; // r14
  CAkRegisteredObj *v5; // rbp
  int v6; // ecx
  int v7; // ebx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v8; // rdx
  __int64 v9; // rcx
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v10; // rbp
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v11; // rbx
  int v12; // [rsp+28h] [rbp-50h]

  v1 = &this->m_mapRegisteredObj.m_MemPoolId;
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
      v2 = *(AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item **)&v1[2 * v3 + 2];
      if ( v2 )
      {
        while ( 1 )
        {
LABEL_7:
          while ( v2->Assoc.key )
          {
            v5 = v2->Assoc.item;
            v6 = *((_DWORD *)v5 + 30) ^ (*((_DWORD *)v5 + 30) ^ (*((_DWORD *)v5 + 30) - 1)) & 0x3FFFFFFF;
            *((_DWORD *)v5 + 30) = v6;
            if ( !(v6 & 0x3FFFFFFF) )
            {
              v7 = g_DefaultPoolId;
              CAkRegisteredObj::~CAkRegisteredObj(v5);
              AK::MemoryMgr::Free(v7, v5);
            }
            v8 = v2->pNextItem;
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
                v11 = *(AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item **)&v1[2 * v9 + 2];
                v10 = 0i64;
              }
              while ( !v11 );
              v12 = v9;
            }
            if ( v4 )
              v4->pNextItem = v8;
            else
              *(_QWORD *)&v1[2 * (unsigned int)v3 + 2] = v8;
            AK::MemoryMgr::Free(*v1, v2);
            --v1[388];
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
              v2 = *(AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item **)&v1[2 * v3 + 2];
              v4 = 0i64;
              if ( v2 )
                goto LABEL_7;
            }
          }
        }
      }
    }
    if ( v2 )
      goto LABEL_7;
  }
}

// File Line: 342
// RVA: 0xA4D240
void __fastcall CAkRegistryMgr::SetNodeIDAsModified(CAkRegistryMgr *this, CAkParameterNodeBase *in_pNode)
{
  CAkRegistryMgr *v2; // rbx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v3; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v4; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v5; // rcx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v6; // rax
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v7; // rcx
  CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *v8; // rcx
  WwiseObjectIDext v9; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = this->m_listModifiedNodes.m_pFirst;
  v9.id = in_pNode->key;
  v9.bIsBus = (*((_BYTE *)in_pNode + 83) >> 1) & 1;
  if ( !this->m_listModifiedNodes.m_pFirst )
    goto LABEL_7;
  while ( in_pNode->key != v3->Item.id || ((*((_BYTE *)in_pNode + 83) >> 1) & 1) != v3->Item.bIsBus )
  {
    v3 = v3->pNextListItem;
    if ( !v3 )
      goto LABEL_7;
  }
  if ( v3 == (CAkList2<WwiseObjectIDext,WwiseObjectIDext const &,1,ArrayPoolDefault>::ListItem *)-8i64 )
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
      v4->pNextListItem = v2->m_listModifiedNodes.m_pFree;
      v2->m_listModifiedNodes.m_pFree = v4;
    }
    v5 = v2->m_listModifiedNodes.m_pLast;
    v6 = v2->m_listModifiedNodes.m_pFree;
    if ( v5 )
      v5->pNextListItem = v6;
    else
      v2->m_listModifiedNodes.m_pFirst = v6;
    v7 = v2->m_listModifiedNodes.m_pFree;
    v2->m_listModifiedNodes.m_pLast = v7;
    v2->m_listModifiedNodes.m_pFree = v7->pNextListItem;
    v7->pNextListItem = 0i64;
    v8 = v2->m_listModifiedNodes.m_pLast;
    ++v2->m_listModifiedNodes.m_ulNumListItems;
    v8->Item = v9;
  }
}

// File Line: 356
// RVA: 0xA4CD60
void __fastcall CAkRegistryMgr::NotifyListenerPosChanged(CAkRegistryMgr *this, unsigned int in_uListenerMask)
{
  AkHashList<unsigned __int64,CAkRegisteredObj *,193>::Item *v2; // r8
  AkHashList<unsigned __int64,CAkRegisteredObj *,193> *v3; // r10
  unsigned __int8 v4; // r11
  CAkRegisteredObj *v5; // rdx
  int v6; // er9
  int v7; // eax

  v2 = this->m_mapRegisteredObj.m_table[0];
  v3 = &this->m_mapRegisteredObj;
  LODWORD(this) = 0;
  v4 = in_uListenerMask;
  if ( v2 )
    goto LABEL_17;
  while ( 1 )
  {
    this = (CAkRegistryMgr *)(unsigned int)((_DWORD)this + 1);
    if ( (unsigned int)this >= 0xC1 )
      break;
    v2 = v3->m_table[(_QWORD)this];
    if ( v2 )
      goto LABEL_6;
  }
  if ( v2 )
  {
LABEL_17:
    do
    {
      do
      {
LABEL_6:
        v5 = v2->Assoc.item;
        v6 = *((_DWORD *)v5 + 30);
        v7 = _bittest(&v6, 0x1Eu) || v5->m_PosKeep.m_uListenerMask & v4;
        *((_DWORD *)v2->Assoc.item + 30) = v6 ^ (v6 ^ (v7 << 30)) & 0x40000000;
        v2 = v2->pNextItem;
      }
      while ( v2 );
      while ( 1 )
      {
        this = (CAkRegistryMgr *)(unsigned int)((_DWORD)this + 1);
        if ( (unsigned int)this >= 0xC1 )
          break;
        v2 = v3->m_table[(_QWORD)this];
        if ( v2 )
          goto LABEL_6;
      }
    }
    while ( v2 );
  }
}

