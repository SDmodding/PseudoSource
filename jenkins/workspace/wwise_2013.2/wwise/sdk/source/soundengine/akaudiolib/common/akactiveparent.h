// File Line: 43
// RVA: 0xA883D0
__int64 __fastcall CAkActiveParent<CAkParameterNode>::ExecuteAction(
        CAkActiveParent<CAkParameterNode> *this,
        ActionParams *in_rAction)
{
  AkActivityChunk *m_pActivityChunk; // rax
  ActionParams *v3; // rsi
  unsigned int m_uLength; // ebx
  __int64 v6; // rdi
  CAkParameterNodeBase *v7; // rcx

  m_pActivityChunk = this->m_pActivityChunk;
  v3 = in_rAction;
  if ( !m_pActivityChunk || !m_pActivityChunk->m_PlayCount && !m_pActivityChunk->m_uActivityCount )
    return 1i64;
  if ( in_rAction->bIsMasterCall )
  {
    LOBYTE(in_rAction) = in_rAction->eType == ActionParamType_Pause;
    ((void (__fastcall *)(CAkActiveParent<CAkParameterNode> *, ActionParams *))this->vfptr[10].Category)(
      this,
      in_rAction);
  }
  m_uLength = this->m_mapChildId.m_uLength;
  if ( !m_uLength )
    return 1i64;
  v6 = m_uLength;
  do
  {
    --v6;
    --m_uLength;
    v7 = this->m_mapChildId.m_pItems[v6];
    if ( !v3->bIsFromBus || !v7->m_pBusOutputNode )
      v7->vfptr[4].__vecDelDtor(v7, (unsigned int)v3);
  }
  while ( m_uLength );
  return 1i64;
}

// File Line: 68
// RVA: 0xA884B0
__int64 __fastcall CAkActiveParent<CAkParameterNode>::ExecuteActionExcept(
        CAkActiveParent<CAkParameterNode> *this,
        ActionParamsExcept *in_rAction)
{
  ActionParamsExcept *v2; // rsi
  unsigned int m_uLength; // edi
  __int64 v5; // r14
  CAkParameterNodeBase **m_pItems; // rax
  CAkParameterNodeBase *v7; // rbx

  v2 = in_rAction;
  if ( !in_rAction->pGameObj )
  {
    LOBYTE(in_rAction) = in_rAction->eType == ActionParamType_Pause;
    ((void (__fastcall *)(CAkActiveParent<CAkParameterNode> *, ActionParamsExcept *))this->vfptr[10].Category)(
      this,
      in_rAction);
  }
  m_uLength = this->m_mapChildId.m_uLength;
  if ( m_uLength )
  {
    v5 = m_uLength;
    do
    {
      m_pItems = this->m_mapChildId.m_pItems;
      --v5;
      --m_uLength;
      v7 = m_pItems[v5];
      if ( (!v2->bIsFromBus || !v7->m_pBusOutputNode)
        && !CAkParameterNodeBase::IsException(m_pItems[v5], v2->pExeceptionList) )
      {
        ((void (__fastcall *)(CAkParameterNodeBase *, ActionParamsExcept *))v7->vfptr[4].AddRef)(v7, v2);
      }
    }
    while ( m_uLength );
  }
  return 1i64;
}

// File Line: 93
// RVA: 0xA88990
__int64 __fastcall CAkActiveParent<CAkParameterNode>::PlayToEnd(
        CAkActiveParent<CAkParameterNode> *this,
        CAkRegisteredObj *in_pGameObj,
        CAkParameterNodeBase *in_NodePtr,
        unsigned int in_PlayingID)
{
  CAkParameterNodeBase **m_pItems; // rbx
  __int64 result; // rax

  m_pItems = this->m_mapChildId.m_pItems;
  if ( m_pItems == &m_pItems[this->m_mapChildId.m_uLength] )
    return 1i64;
  while ( 1 )
  {
    result = ((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, CAkParameterNodeBase *, _QWORD))(*m_pItems)->vfptr[4].Category)(
               *m_pItems,
               in_pGameObj,
               in_NodePtr,
               in_PlayingID);
    if ( (_DWORD)result != 1 )
      break;
    if ( ++m_pItems == &this->m_mapChildId.m_pItems[this->m_mapChildId.m_uLength] )
      return 1i64;
  }
  return result;
}

// File Line: 109
// RVA: 0xA888F0
void __fastcall CAkActiveParent<CAkParameterNode>::ParamNotification(
        CAkActiveParent<CAkParameterNode> *this,
        NotifParams *in_rParams)
{
  AkActivityChunk *m_pActivityChunk; // rsi
  CAkParameterNodeBase **m_pItems; // rbx
  AkActivityChunk *v5; // rax

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    m_pItems = m_pActivityChunk->m_ActiveChildren.m_pItems;
    if ( m_pItems != &m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] )
    {
      do
      {
        if ( !in_rParams->bIsFromBus || !(*m_pItems)->m_pBusOutputNode )
        {
          v5 = (*m_pItems)->m_pActivityChunk;
          if ( v5
            && v5->m_PlayCount
            && !((unsigned __int8 (__fastcall *)(CAkParameterNodeBase *, _QWORD))(*m_pItems)->vfptr[15].AddRef)(
                  *m_pItems,
                  (unsigned int)in_rParams->eType) )
          {
            (*m_pItems)->vfptr[5].__vecDelDtor(*m_pItems, (unsigned int)in_rParams);
          }
        }
        ++m_pItems;
      }
      while ( m_pItems != &m_pActivityChunk->m_ActiveChildren.m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 131
// RVA: 0xA88AF0
void __fastcall CAkBus::PriorityNotification(CAkBus *this, NotifParams *in_rParams)
{
  AkActivityChunk *m_pActivityChunk; // rdi
  CAkParameterNodeBase **m_pItems; // rbx
  CAkParameterNodeBase *v5; // rcx
  AkActivityChunk *v6; // rax

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    m_pItems = m_pActivityChunk->m_ActiveChildren.m_pItems;
    if ( m_pItems != &m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v5 = *m_pItems;
        if ( (*((_BYTE *)*m_pItems + 82) & 0x40) == 0 )
        {
          v6 = v5->m_pActivityChunk;
          if ( v6 )
          {
            if ( v6->m_PlayCount )
              ((void (__fastcall *)(CAkParameterNodeBase *, NotifParams *))v5->vfptr[5].AddRef)(v5, in_rParams);
          }
        }
        ++m_pItems;
      }
      while ( m_pItems != &m_pActivityChunk->m_ActiveChildren.m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 149
// RVA: 0xA886F0
void __fastcall CAkActiveParent<CAkParameterNode>::MuteNotification(
        CAkActiveParent<CAkParameterNode> *this,
        float in_fMuteRatio,
        AkMutedMapItem *in_rMutedItem,
        bool in_bIsFromBus)
{
  __int64 v4; // rdx
  AkActivityChunk *m_pActivityChunk; // rdi
  CAkParameterNodeBase **m_pItems; // rbx
  AkActivityChunk *v9; // rax

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    m_pItems = m_pActivityChunk->m_ActiveChildren.m_pItems;
    if ( m_pItems != &m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] )
    {
      do
      {
        if ( !in_bIsFromBus || !(*m_pItems)->m_pBusOutputNode )
        {
          v9 = (*m_pItems)->m_pActivityChunk;
          if ( v9 )
          {
            if ( v9->m_PlayCount )
              ((void (__fastcall *)(CAkParameterNodeBase *, __int64, AkMutedMapItem *, bool))(*m_pItems)->vfptr[6].__vecDelDtor)(
                *m_pItems,
                v4,
                in_rMutedItem,
                in_bIsFromBus);
          }
        }
        ++m_pItems;
      }
      while ( m_pItems != &m_pActivityChunk->m_ActiveChildren.m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 168
// RVA: 0xA887A0
void __fastcall CAkActiveParent<CAkParameterNodeBase>::MuteNotification(
        CAkActiveParent<CAkParameterNodeBase> *this,
        float in_fMuteRatio,
        CAkRegisteredObj *in_pGameObj,
        AkMutedMapItem *in_rMutedItem,
        bool in_bPrioritizeGameObjectSpecificItems)
{
  __int64 v5; // rdx
  AkActivityChunk *m_pActivityChunk; // rdi
  CAkParameterNodeBase **m_pItems; // rbx
  AkActivityChunk *v10; // rax
  int v11; // [rsp+20h] [rbp-28h]

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    m_pItems = m_pActivityChunk->m_ActiveChildren.m_pItems;
    if ( m_pItems != &m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v10 = (*m_pItems)->m_pActivityChunk;
        if ( v10 )
        {
          if ( v10->m_PlayCount )
          {
            LOBYTE(v11) = in_bPrioritizeGameObjectSpecificItems;
            ((void (__fastcall *)(CAkParameterNodeBase *, __int64, CAkRegisteredObj *, AkMutedMapItem *, int))(*m_pItems)->vfptr[5].Category)(
              *m_pItems,
              v5,
              in_pGameObj,
              in_rMutedItem,
              v11);
          }
        }
        ++m_pItems;
      }
      while ( m_pItems != &m_pActivityChunk->m_ActiveChildren.m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 186
// RVA: 0xA88570
void __fastcall CAkBus::ForAllPBI(
        CAkBus *this,
        void (__fastcall *in_funcForAll)(CAkPBI *, CAkRegisteredObj *, void *),
        CAkRegisteredObj *in_pGameObj,
        void *in_pCookie)
{
  AkActivityChunk *m_pActivityChunk; // rdi
  CAkParameterNodeBase **m_pItems; // rbx
  AkActivityChunk *v9; // rax

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    m_pItems = m_pActivityChunk->m_ActiveChildren.m_pItems;
    if ( m_pItems != &m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v9 = (*m_pItems)->m_pActivityChunk;
        if ( v9 )
        {
          if ( v9->m_PlayCount )
            ((void (__fastcall *)(CAkParameterNodeBase *, void (__fastcall *)(CAkPBI *, CAkRegisteredObj *, void *), CAkRegisteredObj *, void *))(*m_pItems)->vfptr[6].Release)(
              *m_pItems,
              in_funcForAll,
              in_pGameObj,
              in_pCookie);
        }
        ++m_pItems;
      }
      while ( m_pItems != &m_pActivityChunk->m_ActiveChildren.m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 206
// RVA: 0xA88B70
void __fastcall CAkActiveParent<CAkParameterNode>::PropagatePositioningNotification(
        CAkActiveParent<CAkParameterNode> *this,
        float in_RTPCValue,
        unsigned int in_ParameterID,
        CAkRegisteredObj *in_GameObj,
        void *in_pExceptArray)
{
  __int64 v5; // rdx
  AkActivityChunk *m_pActivityChunk; // rdi
  CAkParameterNodeBase **m_pItems; // rbx
  CAkParameterNodeBase *v10; // rcx
  AkActivityChunk *v11; // rax

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    m_pItems = m_pActivityChunk->m_ActiveChildren.m_pItems;
    if ( m_pItems != &m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v10 = *m_pItems;
        if ( (*((_BYTE *)*m_pItems + 83) & 0x10) == 0 )
        {
          v11 = v10->m_pActivityChunk;
          if ( v11 )
          {
            if ( v11->m_PlayCount )
              ((void (__fastcall *)(CAkParameterNodeBase *, __int64, _QWORD, CAkRegisteredObj *, void *))v10->vfptr[6].AddRef)(
                v10,
                v5,
                in_ParameterID,
                in_GameObj,
                in_pExceptArray);
          }
        }
        ++m_pItems;
      }
      while ( m_pItems != &m_pActivityChunk->m_ActiveChildren.m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 221
// RVA: 0xA88C20
void __fastcall CAkActiveParent<CAkParameterNode>::RecalcNotification(CAkActiveParent<CAkParameterNode> *this)
{
  AkActivityChunk *m_pActivityChunk; // rdi
  CAkParameterNodeBase **m_pItems; // rbx
  AkActivityChunk *v3; // rax

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    m_pItems = m_pActivityChunk->m_ActiveChildren.m_pItems;
    if ( m_pItems != &m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v3 = (*m_pItems)->m_pActivityChunk;
        if ( v3 )
        {
          if ( v3->m_PlayCount )
            (*m_pItems)->vfptr[12].Category(*m_pItems);
        }
        ++m_pItems;
      }
      while ( m_pItems != &m_pActivityChunk->m_ActiveChildren.m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 241
// RVA: 0xA88850
void __fastcall CAkActiveParent<CAkParameterNode>::NotifyBypass(
        CAkActiveParent<CAkParameterNode> *this,
        unsigned int in_bitsFXBypass,
        unsigned int in_uTargetMask,
        CAkRegisteredObj *in_pGameObj,
        void *in_pExceptArray)
{
  AkActivityChunk *m_pActivityChunk; // rdi
  CAkParameterNodeBase **m_pItems; // rbx
  CAkParameterNodeBase *v10; // rcx
  AkActivityChunk *v11; // rax

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    m_pItems = m_pActivityChunk->m_ActiveChildren.m_pItems;
    if ( m_pItems != &m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v10 = *m_pItems;
        v11 = (*m_pItems)->m_pActivityChunk;
        if ( v11 && v11->m_PlayCount && (*((_BYTE *)v10 + 83) & 0x40) == 0 )
          ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD, CAkRegisteredObj *, void *))v10->vfptr[6].Category)(
            v10,
            in_bitsFXBypass,
            in_uTargetMask,
            in_pGameObj,
            in_pExceptArray);
        ++m_pItems;
      }
      while ( m_pItems != &m_pActivityChunk->m_ActiveChildren.m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 257
// RVA: 0xA88A30
__int64 __fastcall CAkActiveParent<CAkParameterNode>::PrepareData(CAkActiveParent<CAkParameterNode> *this)
{
  CAkParameterNodeBase **m_pItems; // rbx
  __int64 result; // rax
  unsigned int v4; // esi
  CAkParameterNodeBase **v5; // rdi

  m_pItems = this->m_mapChildId.m_pItems;
  if ( m_pItems == &m_pItems[this->m_mapChildId.m_uLength] )
    return 1i64;
  while ( 1 )
  {
    result = ((__int64 (__fastcall *)(CAkParameterNodeBase *))(*m_pItems)->vfptr[10].__vecDelDtor)(*m_pItems);
    v4 = result;
    if ( (_DWORD)result != 1 )
      break;
    if ( ++m_pItems == &this->m_mapChildId.m_pItems[this->m_mapChildId.m_uLength] )
      return (unsigned int)result;
  }
  v5 = this->m_mapChildId.m_pItems;
  if ( v5 != m_pItems )
  {
    do
    {
      (*v5)->vfptr[10].AddRef(*v5);
      ++v5;
    }
    while ( v5 != m_pItems );
    return v4;
  }
  return result;
}

// File Line: 277
// RVA: 0xA7DAC0
void __fastcall CAkActiveParent<CAkParameterNodeBase>::UnPrepareData(CAkActiveParent<CAkParameterNodeBase> *this)
{
  CAkParameterNodeBase **m_pItems; // rbx

  m_pItems = this->m_mapChildId.m_pItems;
  if ( m_pItems != &m_pItems[this->m_mapChildId.m_uLength] )
  {
    do
    {
      (*m_pItems)->vfptr[10].AddRef(*m_pItems);
      ++m_pItems;
    }
    while ( m_pItems != &this->m_mapChildId.m_pItems[this->m_mapChildId.m_uLength] );
  }
}

// File Line: 305
// RVA: 0xA88E70
void __fastcall CAkActiveParent<CAkParameterNode>::UpdateFx(
        CAkActiveParent<CAkParameterNode> *this,
        unsigned int in_uFXIndex)
{
  AkActivityChunk *m_pActivityChunk; // rdi
  CAkParameterNodeBase **m_pItems; // rbx
  AkActivityChunk *v5; // rax

  m_pActivityChunk = this->m_pActivityChunk;
  if ( m_pActivityChunk )
  {
    m_pItems = m_pActivityChunk->m_ActiveChildren.m_pItems;
    if ( m_pItems != &m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v5 = (*m_pItems)->m_pActivityChunk;
        if ( v5 )
        {
          if ( v5->m_PlayCount )
            ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))(*m_pItems)->vfptr[8].AddRef)(*m_pItems, in_uFXIndex);
        }
        ++m_pItems;
      }
      while ( m_pItems != &m_pActivityChunk->m_ActiveChildren.m_pItems[m_pActivityChunk->m_ActiveChildren.m_uLength] );
    }
  }
}

