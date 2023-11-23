// File Line: 30
// RVA: 0xA8ECA0
void __fastcall CAkSoundBase::CAkSoundBase(CAkSoundBase *this, unsigned int in_ulID)
{
  CAkParameterNode::CAkParameterNode(this, in_ulID);
  this->vfptr = (CAkIndexableVtbl *)&CAkSoundBase::`vftable;
}

// File Line: 34
// RVA: 0xA8ECD0
void __fastcall CAkSoundBase::~CAkSoundBase(CAkSoundBase *this)
{
  this->vfptr = (CAkIndexableVtbl *)&CAkSoundBase::`vftable;
  CAkParameterNode::~CAkParameterNode(this);
}

// File Line: 38
// RVA: 0xA8F0C0
__int64 __fastcall CAkSoundBase::PlayToEnd(
        CAkSoundBase *this,
        CAkRegisteredObj *in_pGameObj,
        CAkParameterNodeBase *in_pNodePtr,
        unsigned int in_PlayingID)
{
  AkActivityChunk *m_pActivityChunk; // rbx
  CAkPBI *i; // rbx

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    for ( i = m_pActivityChunk->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
    {
      if ( (!in_pGameObj || i->m_pGameObj == in_pGameObj)
        && (!in_PlayingID || in_PlayingID == i->m_UserParams.m_PlayingID) )
      {
        ((void (__fastcall *)(CAkPBI *, CAkParameterNodeBase *))i->CAkTransportAware::vfptr[3].~CAkTransportAware)(
          i,
          in_pNodePtr);
      }
    }
  }
  return 1i64;
}

// File Line: 56
// RVA: 0xA8F030
void __fastcall CAkSoundBase::ParamNotification(CAkSoundBase *this, NotifParams *in_rParams)
{
  AkActivityChunk *m_pActivityChunk; // rbx
  CAkPBI *i; // rbx
  unsigned int *pExceptObjects; // rcx
  CAkRegisteredObj *pGameObj; // rax
  CAkRegisteredObj **v7; // rax
  __int64 v8; // rdx

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    for ( i = m_pActivityChunk->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
    {
      pExceptObjects = (unsigned int *)in_rParams->pExceptObjects;
      pGameObj = in_rParams->pGameObj;
      if ( pExceptObjects )
      {
        if ( !pGameObj )
        {
          v7 = *(CAkRegisteredObj ***)pExceptObjects;
          v8 = *(_QWORD *)pExceptObjects + 8i64 * pExceptObjects[2];
          if ( *(_QWORD *)pExceptObjects != v8 )
          {
            while ( *v7 != i->m_pGameObj )
            {
              if ( ++v7 == (CAkRegisteredObj **)v8 )
                goto LABEL_11;
            }
            continue;
          }
LABEL_11:
          CAkPBI::ParamNotification(i, in_rParams);
          continue;
        }
      }
      else if ( !pGameObj )
      {
        goto LABEL_11;
      }
      if ( i->m_pGameObj == pGameObj )
        goto LABEL_11;
    }
  }
}

// File Line: 98
// RVA: 0xA8EE90
void __fastcall CAkSoundBase::MuteNotification(
        CAkSoundBase *this,
        float in_fMuteRatio,
        AkMutedMapItem *in_rMutedItem,
        bool __formal)
{
  AkActivityChunk *m_pActivityChunk; // rbx
  CAkPBI *i; // rbx

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    for ( i = m_pActivityChunk->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
      CAkPBI::MuteNotification(i, in_fMuteRatio, in_rMutedItem, 0);
  }
}

// File Line: 110
// RVA: 0xA8EEF0
void __fastcall CAkSoundBase::MuteNotification(
        CAkSoundBase *this,
        float in_fMuteRatio,
        CAkRegisteredObj *in_pGameObj,
        AkMutedMapItem *in_rMutedItem,
        bool in_bPrioritizeGameObjectSpecificItems)
{
  AkActivityChunk *m_pActivityChunk; // rbx
  bool v6; // si
  CAkPBI *i; // rbx

  m_pActivityChunk = this->m_pActivityChunk;
  v6 = in_pGameObj == 0i64;
  if ( m_pActivityChunk )
  {
    for ( i = m_pActivityChunk->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
    {
      if ( v6 || i->m_pGameObj == in_pGameObj )
        CAkPBI::MuteNotification(i, in_fMuteRatio, in_rMutedItem, in_bPrioritizeGameObjectSpecificItems);
    }
  }
}

// File Line: 133
// RVA: 0xA8ED20
void __fastcall CAkSoundBase::ForAllPBI(
        CAkSoundBase *this,
        void (__fastcall *in_funcForAll)(CAkPBI *, CAkRegisteredObj *, void *),
        CAkRegisteredObj *in_pGameObj,
        void *in_pCookie)
{
  AkActivityChunk *m_pActivityChunk; // rbx
  CAkPBI *i; // rbx

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    for ( i = m_pActivityChunk->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
    {
      if ( !in_pGameObj || in_pGameObj == i->m_pGameObj )
        in_funcForAll(i, in_pGameObj, in_pCookie);
    }
  }
}

// File Line: 147
// RVA: 0xA8F140
void __fastcall CAkSoundBase::PropagatePositioningNotification(
        CAkSoundBase *this,
        float in_RTPCValue,
        AkRTPC_ParameterID in_ParameterID,
        CAkRegisteredObj *in_pGameObj,
        unsigned int *in_pExceptArray)
{
  AkActivityChunk *m_pActivityChunk; // rbx
  CAkPBI *i; // rbx
  CAkRegisteredObj **v9; // rax
  __int64 v10; // rdx

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    for ( i = m_pActivityChunk->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
    {
      if ( in_pExceptArray )
      {
        if ( !in_pGameObj )
        {
          v9 = *(CAkRegisteredObj ***)in_pExceptArray;
          v10 = *(_QWORD *)in_pExceptArray + 8i64 * in_pExceptArray[2];
          if ( *(_QWORD *)in_pExceptArray != v10 )
          {
            while ( *v9 != i->m_pGameObj )
            {
              if ( ++v9 == (CAkRegisteredObj **)v10 )
                goto LABEL_11;
            }
            continue;
          }
LABEL_11:
          CAkPBI::PositioningChangeNotification(i, in_RTPCValue, in_ParameterID);
          continue;
        }
      }
      else if ( !in_pGameObj )
      {
        goto LABEL_11;
      }
      if ( i->m_pGameObj == in_pGameObj )
        goto LABEL_11;
    }
  }
}

// File Line: 186
// RVA: 0xA8F1F0
void __fastcall CAkSoundBase::RecalcNotification(CAkSoundBase *this)
{
  AkActivityChunk *m_pActivityChunk; // rbx
  CAkPBI *i; // rbx

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    for ( i = m_pActivityChunk->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
      CAkPBI::RecalcNotification(i);
  }
}

// File Line: 202
// RVA: 0xA8EF80
void __fastcall CAkSoundBase::NotifyBypass(
        CAkSoundBase *this,
        char in_bitsFXBypass,
        unsigned int in_uTargetMask,
        CAkRegisteredObj *in_pGameObj,
        unsigned int *in_pExceptArray)
{
  AkActivityChunk *m_pActivityChunk; // rbx
  CAkPBI *i; // rbx
  CAkRegisteredObj **v10; // rax
  __int64 v11; // rdx

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    for ( i = m_pActivityChunk->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
    {
      if ( in_pExceptArray )
      {
        if ( !in_pGameObj )
        {
          v10 = *(CAkRegisteredObj ***)in_pExceptArray;
          v11 = *(_QWORD *)in_pExceptArray + 8i64 * in_pExceptArray[2];
          if ( *(_QWORD *)in_pExceptArray != v11 )
          {
            while ( *v10 != i->m_pGameObj )
            {
              if ( ++v10 == (CAkRegisteredObj **)v11 )
                goto LABEL_11;
            }
            continue;
          }
LABEL_11:
          CAkPBI::NotifyBypass(i, in_bitsFXBypass, in_uTargetMask);
          continue;
        }
      }
      else if ( !in_pGameObj )
      {
        goto LABEL_11;
      }
      if ( i->m_pGameObj == in_pGameObj )
        goto LABEL_11;
    }
  }
}

// File Line: 243
// RVA: 0xA8F220
void __fastcall CAkSoundBase::UpdateFx(CAkSoundBase *this, unsigned int in_uFXIndex)
{
  AkActivityChunk *m_pActivityChunk; // rbx
  CAkPBI *i; // rbx

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    for ( i = m_pActivityChunk->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
      CAkPBI::UpdateFx(i, in_uFXIndex);
  }
}

// File Line: 271
// RVA: 0xA8ED90
__int64 __fastcall CAkSoundBase::Loop(CAkSoundBase *this)
{
  char *m_pProps; // r8
  int v2; // r10d
  unsigned int v4; // r9d
  int v5; // edx
  __int64 v6; // rcx
  __int64 v7; // rdx
  char *v8; // r9
  int *v9; // rax
  int v10; // ebx
  unsigned int v11; // eax
  int i; // edx
  __int64 v13; // r8
  char *v15; // rdi
  int v16; // esi
  int v17; // [rsp+30h] [rbp+8h] BYREF

  m_pProps = this->m_props.m_pProps;
  v2 = 0;
  v17 = 1;
  if ( m_pProps )
  {
    v4 = (unsigned __int8)*m_pProps;
    v5 = 0;
    while ( 1 )
    {
      v6 = (unsigned int)(v5 + 1);
      if ( m_pProps[v6] == 7 )
        break;
      ++v5;
      if ( (unsigned int)v6 >= v4 )
        goto LABEL_5;
    }
    v7 = (__int64)&m_pProps[4 * v5 + ((v4 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v7 = 0i64;
  }
  v8 = this->m_ranges.m_pProps;
  v9 = &v17;
  if ( v7 )
    v9 = (int *)v7;
  v10 = *v9;
  if ( !v8 )
    return (unsigned __int16)v10;
  v11 = (unsigned __int8)*v8;
  for ( i = 0; ; ++i )
  {
    v13 = (unsigned int)(i + 1);
    if ( v8[v13] == 7 )
      break;
    if ( (unsigned int)v13 >= v11 )
      return (unsigned __int16)v10;
  }
  v15 = &v8[8 * i + ((v11 + 4) & 0xFFFFFFFC)];
  if ( !v15 )
    return (unsigned __int16)v10;
  v16 = *((_DWORD *)v15 + 1) - *(_DWORD *)v15;
  if ( v16 )
    v2 = (int)((double)rand() * 0.00003051850947599719 * (double)v16 + 0.5);
  return (unsigned int)(v10 + v2 + *(_DWORD *)v15);
}

