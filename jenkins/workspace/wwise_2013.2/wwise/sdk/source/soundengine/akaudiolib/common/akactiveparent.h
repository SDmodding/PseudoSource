// File Line: 43
// RVA: 0xA883D0
signed __int64 __fastcall CAkActiveParent<CAkParameterNode>::ExecuteAction(CAkActiveParent<CAkParameterNode> *this, ActionParams *in_rAction)
{
  AkActivityChunk *v2; // rax
  ActionParams *v3; // rsi
  CAkActiveParent<CAkParameterNode> *v4; // r14
  unsigned int v5; // ebx
  signed __int64 v6; // rdi
  CAkParameterNodeBase *v7; // rcx

  v2 = this->m_pActivityChunk;
  v3 = in_rAction;
  v4 = this;
  if ( !v2 || !v2->m_PlayCount && (!v2 || !v2->m_uActivityCount) )
    return 1i64;
  if ( in_rAction->bIsMasterCall )
  {
    LOBYTE(in_rAction) = in_rAction->eType == 1;
    ((void (__fastcall *)(CAkActiveParent<CAkParameterNode> *, ActionParams *))this->vfptr[10].Category)(
      this,
      in_rAction);
  }
  v5 = v4->m_mapChildId.m_uLength;
  if ( !v5 )
    return 1i64;
  v6 = v5;
  do
  {
    --v6;
    --v5;
    v7 = v4->m_mapChildId.m_pItems[v6];
    if ( !v3->bIsFromBus || !v7->m_pBusOutputNode )
      v7->vfptr[4].__vecDelDtor((CAkIndexable *)&v7->vfptr, (unsigned int)v3);
  }
  while ( v5 );
  return 1i64;
}

// File Line: 68
// RVA: 0xA884B0
signed __int64 __fastcall CAkActiveParent<CAkParameterNode>::ExecuteActionExcept(CAkActiveParent<CAkParameterNode> *this, ActionParamsExcept *in_rAction)
{
  ActionParamsExcept *v2; // rsi
  CAkActiveParent<CAkParameterNode> *v3; // r15
  unsigned int v4; // edi
  signed __int64 v5; // r14
  CAkParameterNodeBase **v6; // rax
  CAkParameterNodeBase *v7; // rbx

  v2 = in_rAction;
  v3 = this;
  if ( !in_rAction->pGameObj )
  {
    LOBYTE(in_rAction) = in_rAction->eType == 1;
    ((void (__fastcall *)(CAkActiveParent<CAkParameterNode> *, ActionParamsExcept *))this->vfptr[10].Category)(
      this,
      in_rAction);
  }
  v4 = v3->m_mapChildId.m_uLength;
  if ( v4 )
  {
    v5 = v4;
    do
    {
      v6 = v3->m_mapChildId.m_pItems;
      --v5;
      --v4;
      v7 = v6[v5];
      if ( (!v2->bIsFromBus || !v7->m_pBusOutputNode) && !CAkParameterNodeBase::IsException(v6[v5], v2->pExeceptionList) )
        ((void (__fastcall *)(CAkParameterNodeBase *, ActionParamsExcept *))v7->vfptr[4].AddRef)(v7, v2);
    }
    while ( v4 );
  }
  return 1i64;
}

// File Line: 93
// RVA: 0xA88990
__int64 __fastcall CAkActiveParent<CAkParameterNode>::PlayToEnd(CAkActiveParent<CAkParameterNode> *this, CAkRegisteredObj *in_pGameObj, CAkParameterNodeBase *in_NodePtr, unsigned int in_PlayingID)
{
  CAkParameterNodeBase **v4; // rbx
  unsigned int v5; // esi
  CAkParameterNodeBase *v6; // rbp
  CAkRegisteredObj *v7; // r14
  CAkActiveParent<CAkParameterNode> *v8; // rdi
  __int64 result; // rax

  v4 = this->m_mapChildId.m_pItems;
  v5 = in_PlayingID;
  v6 = in_NodePtr;
  v7 = in_pGameObj;
  v8 = this;
  if ( v4 == &v4[this->m_mapChildId.m_uLength] )
    return 1i64;
  while ( 1 )
  {
    result = ((__int64 (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, CAkParameterNodeBase *, _QWORD))(*v4)->vfptr[4].Category)(
               *v4,
               v7,
               v6,
               v5);
    if ( (_DWORD)result != 1 )
      break;
    ++v4;
    if ( v4 == &v8->m_mapChildId.m_pItems[v8->m_mapChildId.m_uLength] )
      return (unsigned int)result;
  }
  return result;
}

// File Line: 109
// RVA: 0xA888F0
void __fastcall CAkActiveParent<CAkParameterNode>::ParamNotification(CAkActiveParent<CAkParameterNode> *this, NotifParams *in_rParams)
{
  AkActivityChunk *v2; // rsi
  NotifParams *v3; // rdi
  CAkParameterNodeBase **v4; // rbx
  AkActivityChunk *v5; // rax

  v2 = this->m_pActivityChunk;
  v3 = in_rParams;
  if ( v2 )
  {
    v4 = v2->m_ActiveChildren.m_pItems;
    if ( v4 != &v4[v2->m_ActiveChildren.m_uLength] )
    {
      do
      {
        if ( !v3->bIsFromBus || !(*v4)->m_pBusOutputNode )
        {
          v5 = (*v4)->m_pActivityChunk;
          if ( v5
            && v5->m_PlayCount
            && !((unsigned __int8 (__fastcall *)(CAkParameterNodeBase *, _QWORD))(*v4)->vfptr[15].AddRef)(
                  *v4,
                  (unsigned int)v3->eType) )
          {
            (*v4)->vfptr[5].__vecDelDtor((CAkIndexable *)&(*v4)->vfptr, (unsigned int)v3);
          }
        }
        ++v4;
      }
      while ( v4 != &v2->m_ActiveChildren.m_pItems[v2->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 131
// RVA: 0xA88AF0
void __fastcall CAkBus::PriorityNotification(CAkBus *this, NotifParams *in_rParams)
{
  AkActivityChunk *v2; // rdi
  NotifParams *v3; // rsi
  CAkParameterNodeBase **v4; // rbx
  CAkParameterNodeBase *v5; // rcx
  AkActivityChunk *v6; // rax

  v2 = this->m_pActivityChunk;
  v3 = in_rParams;
  if ( v2 )
  {
    v4 = v2->m_ActiveChildren.m_pItems;
    if ( v4 != &v4[v2->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v5 = *v4;
        if ( !(*((_BYTE *)*v4 + 82) & 0x40) )
        {
          v6 = v5->m_pActivityChunk;
          if ( v6 )
          {
            if ( v6->m_PlayCount )
              ((void (__fastcall *)(CAkParameterNodeBase *, NotifParams *))v5->vfptr[5].AddRef)(v5, v3);
          }
        }
        ++v4;
      }
      while ( v4 != &v2->m_ActiveChildren.m_pItems[v2->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 149
// RVA: 0xA886F0
void __usercall CAkActiveParent<CAkParameterNode>::MuteNotification(CAkActiveParent<CAkParameterNode> *this@<rcx>, float in_fMuteRatio@<xmm1>, AkMutedMapItem *in_rMutedItem@<r8>, bool in_bIsFromBus@<r9b>, __int64 a5@<rdx>)
{
  AkActivityChunk *v5; // rdi
  bool v6; // si
  AkMutedMapItem *v7; // rbp
  CAkParameterNodeBase **v8; // rbx
  AkActivityChunk *v9; // rax

  v5 = this->m_pActivityChunk;
  v6 = in_bIsFromBus;
  v7 = in_rMutedItem;
  if ( v5 )
  {
    v8 = v5->m_ActiveChildren.m_pItems;
    if ( v8 != &v8[v5->m_ActiveChildren.m_uLength] )
    {
      do
      {
        if ( !v6 || !(*v8)->m_pBusOutputNode )
        {
          v9 = (*v8)->m_pActivityChunk;
          if ( v9 )
          {
            if ( v9->m_PlayCount )
              ((void (__fastcall *)(CAkParameterNodeBase *, __int64, AkMutedMapItem *, bool))(*v8)->vfptr[6].__vecDelDtor)(
                *v8,
                a5,
                v7,
                v6);
          }
        }
        ++v8;
      }
      while ( v8 != &v5->m_ActiveChildren.m_pItems[v5->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 168
// RVA: 0xA887A0
void __usercall CAkActiveParent<CAkParameterNodeBase>::MuteNotification(CAkActiveParent<CAkParameterNodeBase> *this@<rcx>, float in_fMuteRatio@<xmm1>, CAkRegisteredObj *in_pGameObj@<r8>, AkMutedMapItem *in_rMutedItem@<r9>, __int64 a5@<rdx>, bool in_bPrioritizeGameObjectSpecificItems)
{
  AkActivityChunk *v6; // rdi
  AkMutedMapItem *v7; // rbp
  CAkRegisteredObj *v8; // r14
  CAkParameterNodeBase **v9; // rbx
  AkActivityChunk *v10; // rax
  __int64 v11[2]; // [rsp+20h] [rbp-28h]

  v6 = this->m_pActivityChunk;
  v7 = in_rMutedItem;
  v8 = in_pGameObj;
  if ( v6 )
  {
    v9 = v6->m_ActiveChildren.m_pItems;
    if ( v9 != &v9[v6->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v10 = (*v9)->m_pActivityChunk;
        if ( v10 )
        {
          if ( v10->m_PlayCount )
          {
            LOBYTE(v11[0]) = in_bPrioritizeGameObjectSpecificItems;
            ((void (__fastcall *)(CAkParameterNodeBase *, __int64, CAkRegisteredObj *, AkMutedMapItem *, __int64))(*v9)->vfptr[5].Category)(
              *v9,
              a5,
              v8,
              v7,
              v11[0]);
          }
        }
        ++v9;
      }
      while ( v9 != &v6->m_ActiveChildren.m_pItems[v6->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 186
// RVA: 0xA88570
void __fastcall CAkBus::ForAllPBI(CAkBus *this, void (__fastcall *in_funcForAll)(CAkPBI *, CAkRegisteredObj *, void *), CAkRegisteredObj *in_pGameObj, void *in_pCookie)
{
  AkActivityChunk *v4; // rdi
  void *v5; // rsi
  CAkRegisteredObj *v6; // rbp
  void (__fastcall *v7)(CAkPBI *, CAkRegisteredObj *, void *); // r14
  CAkParameterNodeBase **v8; // rbx
  AkActivityChunk *v9; // rax

  v4 = this->m_pActivityChunk;
  v5 = in_pCookie;
  v6 = in_pGameObj;
  v7 = in_funcForAll;
  if ( v4 )
  {
    v8 = v4->m_ActiveChildren.m_pItems;
    if ( v8 != &v8[v4->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v9 = (*v8)->m_pActivityChunk;
        if ( v9 )
        {
          if ( v9->m_PlayCount )
            ((void (__fastcall *)(CAkParameterNodeBase *, void (__fastcall *)(CAkPBI *, CAkRegisteredObj *, void *), CAkRegisteredObj *, void *))(*v8)->vfptr[6].Release)(
              *v8,
              v7,
              v6,
              v5);
        }
        ++v8;
      }
      while ( v8 != &v4->m_ActiveChildren.m_pItems[v4->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 206
// RVA: 0xA88B70
void __usercall CAkActiveParent<CAkParameterNode>::PropagatePositioningNotification(CAkActiveParent<CAkParameterNode> *this@<rcx>, float in_RTPCValue@<xmm1>, AkRTPC_ParameterID in_ParameterID@<r8d>, CAkRegisteredObj *in_GameObj@<r9>, __int64 a5@<rdx>, void *in_pExceptArray)
{
  AkActivityChunk *v6; // rdi
  CAkRegisteredObj *v7; // rbp
  AkRTPC_ParameterID v8; // er14
  CAkParameterNodeBase **v9; // rbx
  CAkParameterNodeBase *v10; // rcx
  AkActivityChunk *v11; // rax

  v6 = this->m_pActivityChunk;
  v7 = in_GameObj;
  v8 = in_ParameterID;
  if ( v6 )
  {
    v9 = v6->m_ActiveChildren.m_pItems;
    if ( v9 != &v9[v6->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v10 = *v9;
        if ( !(*((_BYTE *)*v9 + 83) & 0x10) )
        {
          v11 = v10->m_pActivityChunk;
          if ( v11 )
          {
            if ( v11->m_PlayCount )
              ((void (__fastcall *)(CAkParameterNodeBase *, __int64, _QWORD, CAkRegisteredObj *, void *))v10->vfptr[6].AddRef)(
                v10,
                a5,
                (unsigned int)v8,
                v7,
                in_pExceptArray);
          }
        }
        ++v9;
      }
      while ( v9 != &v6->m_ActiveChildren.m_pItems[v6->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 221
// RVA: 0xA88C20
void __fastcall CAkActiveParent<CAkParameterNode>::RecalcNotification(CAkActiveParent<CAkParameterNode> *this)
{
  AkActivityChunk *v1; // rdi
  CAkParameterNodeBase **v2; // rbx
  AkActivityChunk *v3; // rax

  v1 = this->m_pActivityChunk;
  if ( v1 )
  {
    v2 = v1->m_ActiveChildren.m_pItems;
    if ( v2 != &v2[v1->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v3 = (*v2)->m_pActivityChunk;
        if ( v3 )
        {
          if ( v3->m_PlayCount )
            ((void (*)(void))(*v2)->vfptr[12].Category)();
        }
        ++v2;
      }
      while ( v2 != &v1->m_ActiveChildren.m_pItems[v1->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 241
// RVA: 0xA88850
void __fastcall CAkActiveParent<CAkParameterNode>::NotifyBypass(CAkActiveParent<CAkParameterNode> *this, unsigned int in_bitsFXBypass, unsigned int in_uTargetMask, CAkRegisteredObj *in_pGameObj, void *in_pExceptArray)
{
  AkActivityChunk *v5; // rdi
  CAkRegisteredObj *v6; // rbp
  unsigned int v7; // er14
  unsigned int v8; // er15
  CAkParameterNodeBase **v9; // rbx
  CAkParameterNodeBase *v10; // rcx
  AkActivityChunk *v11; // rax

  v5 = this->m_pActivityChunk;
  v6 = in_pGameObj;
  v7 = in_uTargetMask;
  v8 = in_bitsFXBypass;
  if ( v5 )
  {
    v9 = v5->m_ActiveChildren.m_pItems;
    if ( v9 != &v9[v5->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v10 = *v9;
        v11 = (*v9)->m_pActivityChunk;
        if ( v11 && v11->m_PlayCount && !(*((_BYTE *)v10 + 83) & 0x40) )
          ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, _QWORD, CAkRegisteredObj *, void *))v10->vfptr[6].Category)(
            v10,
            v8,
            v7,
            v6,
            in_pExceptArray);
        ++v9;
      }
      while ( v9 != &v5->m_ActiveChildren.m_pItems[v5->m_ActiveChildren.m_uLength] );
    }
  }
}

// File Line: 257
// RVA: 0xA88A30
__int64 __fastcall CAkActiveParent<CAkParameterNode>::PrepareData(CAkActiveParent<CAkParameterNode> *this)
{
  CAkParameterNodeBase **v1; // rbx
  CAkActiveParent<CAkParameterNode> *v2; // rdi
  __int64 result; // rax
  unsigned int v4; // esi
  CAkParameterNodeBase **v5; // rdi

  v1 = this->m_mapChildId.m_pItems;
  v2 = this;
  if ( v1 == &v1[this->m_mapChildId.m_uLength] )
    return 1i64;
  while ( 1 )
  {
    result = ((__int64 (*)(void))(*v1)->vfptr[10].__vecDelDtor)();
    v4 = result;
    if ( (_DWORD)result != 1 )
      break;
    ++v1;
    if ( v1 == &v2->m_mapChildId.m_pItems[v2->m_mapChildId.m_uLength] )
      return (unsigned int)result;
  }
  v5 = v2->m_mapChildId.m_pItems;
  if ( v5 != v1 )
  {
    do
    {
      ((void (*)(void))(*v5)->vfptr[10].AddRef)();
      ++v5;
    }
    while ( v5 != v1 );
    result = v4;
  }
  return result;
}

// File Line: 277
// RVA: 0xA7DAC0
void __fastcall CAkActiveParent<CAkParameterNodeBase>::UnPrepareData(CAkActiveParent<CAkParameterNodeBase> *this)
{
  CAkParameterNodeBase **v1; // rbx
  CAkActiveParent<CAkParameterNodeBase> *v2; // rdi

  v1 = this->m_mapChildId.m_pItems;
  v2 = this;
  if ( v1 != &v1[this->m_mapChildId.m_uLength] )
  {
    do
    {
      ((void (*)(void))(*v1)->vfptr[10].AddRef)();
      ++v1;
    }
    while ( v1 != &v2->m_mapChildId.m_pItems[v2->m_mapChildId.m_uLength] );
  }
}

// File Line: 305
// RVA: 0xA88E70
void __fastcall CAkActiveParent<CAkParameterNode>::UpdateFx(CAkActiveParent<CAkParameterNode> *this, unsigned int in_uFXIndex)
{
  AkActivityChunk *v2; // rdi
  unsigned int v3; // esi
  CAkParameterNodeBase **v4; // rbx
  AkActivityChunk *v5; // rax

  v2 = this->m_pActivityChunk;
  v3 = in_uFXIndex;
  if ( v2 )
  {
    v4 = v2->m_ActiveChildren.m_pItems;
    if ( v4 != &v4[v2->m_ActiveChildren.m_uLength] )
    {
      do
      {
        v5 = (*v4)->m_pActivityChunk;
        if ( v5 )
        {
          if ( v5->m_PlayCount )
            ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))(*v4)->vfptr[8].AddRef)(*v4, v3);
        }
        ++v4;
      }
      while ( v4 != &v2->m_ActiveChildren.m_pItems[v2->m_ActiveChildren.m_uLength] );
    }
  }
}

