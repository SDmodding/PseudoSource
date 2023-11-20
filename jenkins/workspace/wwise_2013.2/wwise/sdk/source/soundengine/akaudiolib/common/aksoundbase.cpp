// File Line: 30
// RVA: 0xA8ECA0
void __fastcall CAkSoundBase::CAkSoundBase(CAkSoundBase *this, unsigned int in_ulID)
{
  CAkSoundBase *v2; // rbx

  v2 = this;
  CAkParameterNode::CAkParameterNode((CAkParameterNode *)&this->vfptr, in_ulID);
  v2->vfptr = (CAkIndexableVtbl *)&CAkSoundBase::`vftable;
}

// File Line: 34
// RVA: 0xA8ECD0
void __fastcall CAkSoundBase::~CAkSoundBase(CAkSoundBase *this)
{
  this->vfptr = (CAkIndexableVtbl *)&CAkSoundBase::`vftable;
  CAkParameterNode::~CAkParameterNode((CAkParameterNode *)&this->vfptr);
}

// File Line: 38
// RVA: 0xA8F0C0
signed __int64 __fastcall CAkSoundBase::PlayToEnd(CAkSoundBase *this, CAkRegisteredObj *in_pGameObj, CAkParameterNodeBase *in_pNodePtr, unsigned int in_PlayingID)
{
  AkActivityChunk *v4; // rbx
  unsigned int v5; // edi
  CAkParameterNodeBase *v6; // rbp
  CAkRegisteredObj *v7; // rsi
  CAkPBI *i; // rbx

  v4 = this->m_pActivityChunk;
  v5 = in_PlayingID;
  v6 = in_pNodePtr;
  v7 = in_pGameObj;
  if ( v4 )
  {
    for ( i = v4->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
    {
      if ( (!v7 || i->m_pGameObj == v7) && (!v5 || v5 == i->m_UserParams.m_PlayingID) )
        ((void (__fastcall *)(CAkPBI *, CAkParameterNodeBase *))i->vfptr[3].~CAkTransportAware)(i, v6);
    }
  }
  return 1i64;
}

// File Line: 56
// RVA: 0xA8F030
void __fastcall CAkSoundBase::ParamNotification(CAkSoundBase *this, NotifParams *in_rParams)
{
  AkActivityChunk *v2; // rbx
  NotifParams *v3; // rdi
  CAkPBI *i; // rbx
  CAkRegisteredObj ***v5; // rcx
  CAkRegisteredObj *v6; // rax
  CAkRegisteredObj **v7; // rax
  signed __int64 v8; // rdx

  v2 = this->m_pActivityChunk;
  v3 = in_rParams;
  if ( v2 )
  {
    for ( i = v2->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
    {
      v5 = (CAkRegisteredObj ***)v3->pExceptObjects;
      v6 = v3->pGameObj;
      if ( v5 )
      {
        if ( !v6 )
        {
          v7 = *v5;
          v8 = (signed __int64)&(*v5)[*((unsigned int *)v5 + 2)];
          if ( *v5 != (CAkRegisteredObj **)v8 )
          {
            while ( *v7 != i->m_pGameObj )
            {
              ++v7;
              if ( v7 == (CAkRegisteredObj **)v8 )
                goto LABEL_11;
            }
            continue;
          }
LABEL_11:
          CAkPBI::ParamNotification(i, v3);
          continue;
        }
      }
      else if ( !v6 )
      {
        goto LABEL_11;
      }
      if ( i->m_pGameObj == v6 )
        goto LABEL_11;
    }
  }
}

// File Line: 98
// RVA: 0xA8EE90
void __fastcall CAkSoundBase::MuteNotification(CAkSoundBase *this, float in_fMuteRatio, AkMutedMapItem *in_rMutedItem, bool __formal)
{
  AkActivityChunk *v4; // rbx
  AkMutedMapItem *v5; // rdi
  CAkPBI *i; // rbx

  v4 = this->m_pActivityChunk;
  v5 = in_rMutedItem;
  if ( v4 )
  {
    for ( i = v4->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
      CAkPBI::MuteNotification(i, in_fMuteRatio, v5, 0);
  }
}

// File Line: 110
// RVA: 0xA8EEF0
void __fastcall CAkSoundBase::MuteNotification(CAkSoundBase *this, float in_fMuteRatio, CAkRegisteredObj *in_pGameObj, AkMutedMapItem *in_rMutedItem, bool in_bPrioritizeGameObjectSpecificItems)
{
  AkActivityChunk *v5; // rbx
  bool v6; // si
  AkMutedMapItem *v7; // r14
  CAkRegisteredObj *v8; // rdi
  CAkPBI *i; // rbx

  v5 = this->m_pActivityChunk;
  v6 = in_pGameObj == 0i64;
  v7 = in_rMutedItem;
  v8 = in_pGameObj;
  if ( v5 )
  {
    for ( i = v5->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
    {
      if ( v6 || i->m_pGameObj == v8 )
        CAkPBI::MuteNotification(i, in_fMuteRatio, v7, in_bPrioritizeGameObjectSpecificItems);
    }
  }
}

// File Line: 133
// RVA: 0xA8ED20
void __fastcall CAkSoundBase::ForAllPBI(CAkSoundBase *this, void (__fastcall *in_funcForAll)(CAkPBI *, CAkRegisteredObj *, void *), CAkRegisteredObj *in_pGameObj, void *in_pCookie)
{
  AkActivityChunk *v4; // rbx
  void *v5; // rsi
  CAkRegisteredObj *v6; // rdi
  void (__fastcall *v7)(CAkPBI *, CAkRegisteredObj *, void *); // rbp
  CAkPBI *i; // rbx

  v4 = this->m_pActivityChunk;
  v5 = in_pCookie;
  v6 = in_pGameObj;
  v7 = in_funcForAll;
  if ( v4 )
  {
    for ( i = v4->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
    {
      if ( !v6 || v6 == i->m_pGameObj )
        v7(i, v6, v5);
    }
  }
}

// File Line: 147
// RVA: 0xA8F140
void __fastcall CAkSoundBase::PropagatePositioningNotification(CAkSoundBase *this, float in_RTPCValue, AkRTPC_ParameterID in_ParameterID, CAkRegisteredObj *in_pGameObj, void *in_pExceptArray)
{
  AkActivityChunk *v5; // rbx
  CAkRegisteredObj *v6; // rdi
  AkRTPC_ParameterID v7; // ebp
  CAkPBI *i; // rbx
  CAkRegisteredObj **v9; // rax
  signed __int64 v10; // rdx

  v5 = this->m_pActivityChunk;
  v6 = in_pGameObj;
  v7 = in_ParameterID;
  if ( v5 )
  {
    for ( i = v5->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
    {
      if ( in_pExceptArray )
      {
        if ( !v6 )
        {
          v9 = *(CAkRegisteredObj ***)in_pExceptArray;
          v10 = *(_QWORD *)in_pExceptArray + 8i64 * *((unsigned int *)in_pExceptArray + 2);
          if ( *(_QWORD *)in_pExceptArray != v10 )
          {
            while ( *v9 != i->m_pGameObj )
            {
              ++v9;
              if ( v9 == (CAkRegisteredObj **)v10 )
                goto LABEL_11;
            }
            continue;
          }
LABEL_11:
          CAkPBI::PositioningChangeNotification(i, in_RTPCValue, v7);
          continue;
        }
      }
      else if ( !v6 )
      {
        goto LABEL_11;
      }
      if ( i->m_pGameObj == v6 )
        goto LABEL_11;
    }
  }
}

// File Line: 186
// RVA: 0xA8F1F0
void __fastcall CAkSoundBase::RecalcNotification(CAkSoundBase *this)
{
  AkActivityChunk *v1; // rbx
  CAkPBI *i; // rbx

  v1 = this->m_pActivityChunk;
  if ( v1 )
  {
    for ( i = v1->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
      CAkPBI::RecalcNotification(i);
  }
}

// File Line: 202
// RVA: 0xA8EF80
void __fastcall CAkSoundBase::NotifyBypass(CAkSoundBase *this, unsigned int in_bitsFXBypass, unsigned int in_uTargetMask, CAkRegisteredObj *in_pGameObj, void *in_pExceptArray)
{
  AkActivityChunk *v5; // rbx
  CAkRegisteredObj *v6; // rdi
  unsigned int v7; // ebp
  unsigned int v8; // er14
  CAkPBI *i; // rbx
  CAkRegisteredObj **v10; // rax
  signed __int64 v11; // rdx

  v5 = this->m_pActivityChunk;
  v6 = in_pGameObj;
  v7 = in_uTargetMask;
  v8 = in_bitsFXBypass;
  if ( v5 )
  {
    for ( i = v5->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
    {
      if ( in_pExceptArray )
      {
        if ( !v6 )
        {
          v10 = *(CAkRegisteredObj ***)in_pExceptArray;
          v11 = *(_QWORD *)in_pExceptArray + 8i64 * *((unsigned int *)in_pExceptArray + 2);
          if ( *(_QWORD *)in_pExceptArray != v11 )
          {
            while ( *v10 != i->m_pGameObj )
            {
              ++v10;
              if ( v10 == (CAkRegisteredObj **)v11 )
                goto LABEL_11;
            }
            continue;
          }
LABEL_11:
          CAkPBI::NotifyBypass(i, v8, v7);
          continue;
        }
      }
      else if ( !v6 )
      {
        goto LABEL_11;
      }
      if ( i->m_pGameObj == v6 )
        goto LABEL_11;
    }
  }
}

// File Line: 243
// RVA: 0xA8F220
void __fastcall CAkSoundBase::UpdateFx(CAkSoundBase *this, unsigned int in_uFXIndex)
{
  AkActivityChunk *v2; // rbx
  unsigned int v3; // edi
  CAkPBI *i; // rbx

  v2 = this->m_pActivityChunk;
  v3 = in_uFXIndex;
  if ( v2 )
  {
    for ( i = v2->m_listPBI.m_pFirst; i; i = i->pNextLightItem )
      CAkPBI::UpdateFx(i, v3);
  }
}

// File Line: 271
// RVA: 0xA8ED90
__int64 __fastcall CAkSoundBase::Loop(CAkSoundBase *this)
{
  char *v1; // r8
  signed int v2; // er10
  CAkSoundBase *v3; // r11
  unsigned int v4; // er9
  int v5; // edx
  __int64 v6; // rcx
  signed __int64 v7; // rdx
  char *v8; // r9
  int *v9; // rax
  int v10; // ebx
  unsigned int v11; // eax
  int v12; // edx
  __int64 v13; // r8
  unsigned __int8 *v15; // rdi
  int v16; // esi
  int v17; // [rsp+30h] [rbp+8h]

  v1 = this->m_props.m_pProps;
  v2 = 0;
  v3 = this;
  v17 = 1;
  if ( v1 )
  {
    v4 = (unsigned __int8)*v1;
    v5 = 0;
    while ( 1 )
    {
      v6 = (unsigned int)(v5 + 1);
      if ( v1[v6] == 7 )
        break;
      ++v5;
      if ( (unsigned int)v6 >= v4 )
        goto LABEL_5;
    }
    v7 = (signed __int64)&v1[4 * v5 + ((v4 + 4) & 0xFFFFFFFC)];
  }
  else
  {
LABEL_5:
    v7 = 0i64;
  }
  v8 = v3->m_ranges.m_pProps;
  v9 = &v17;
  if ( v7 )
    v9 = (int *)v7;
  v10 = *v9;
  if ( !v8 )
    return (unsigned __int16)v10;
  v11 = (unsigned __int8)*v8;
  v12 = 0;
  while ( 1 )
  {
    v13 = (unsigned int)(v12 + 1);
    if ( v8[v13] == 7 )
      break;
    ++v12;
    if ( (unsigned int)v13 >= v11 )
      return (unsigned __int16)v10;
  }
  v15 = (unsigned __int8 *)&v8[8 * v12 + ((v11 + 4) & 0xFFFFFFFC)];
  if ( !v15 )
    return (unsigned __int16)v10;
  if ( *((_DWORD *)v15 + 1) != *(_DWORD *)v15 )
  {
    v16 = *((_DWORD *)v15 + 1) - *(_DWORD *)v15;
    v2 = (signed int)((double)rand() * 0.00003051850947599719 * (double)v16 + 0.5);
  }
  return (unsigned int)(v10 + v2 + *(_DWORD *)v15);
}

