// File Line: 33
// RVA: 0xAB22B0
void __fastcall CAkMusicSwitchCntr::CAkMusicSwitchCntr(CAkMusicSwitchCntr *this, unsigned int in_ulID)
{
  CAkMusicTransAware::CAkMusicTransAware(this, in_ulID);
  this->pNextItemPrepare = 0i64;
  this->m_uPreparationCount = 0;
  this->CAkMusicTransAware::CAkMusicNode::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr = (CAkIndexableVtbl *)&CAkMusicSwitchCntr::`vftable{for `CAkMusicTransAware};
  this->CAkPreparationAware::vfptr = (CAkPreparationAwareVtbl *)&CAkMusicSwitchCntr::`vftable{for `CAkPreparationAware};
  AkDecisionTree::AkDecisionTree(&this->m_decisionTree);
  this->m_bIsContinuePlayback = 1;
  this->m_pArguments = 0i64;
  this->m_pGroupTypes = 0i64;
}

// File Line: 37
// RVA: 0xAB2320
void __fastcall CAkMusicSwitchCntr::~CAkMusicSwitchCntr(CAkMusicSwitchCntr *this)
{
  unsigned int *m_pArguments; // rdx
  char *m_pGroupTypes; // rdx

  m_pArguments = this->m_pArguments;
  this->CAkMusicTransAware::CAkMusicNode::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr = (CAkIndexableVtbl *)&CAkMusicSwitchCntr::`vftable{for `CAkMusicTransAware};
  this->CAkPreparationAware::vfptr = (CAkPreparationAwareVtbl *)&CAkMusicSwitchCntr::`vftable{for `CAkPreparationAware};
  if ( m_pArguments )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pArguments);
    this->m_pArguments = 0i64;
  }
  m_pGroupTypes = this->m_pGroupTypes;
  if ( m_pGroupTypes )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pGroupTypes);
    this->m_pGroupTypes = 0i64;
  }
  AkDecisionTree::~AkDecisionTree(&this->m_decisionTree);
  CAkMusicTransAware::~CAkMusicTransAware(this);
}

// File Line: 45
// RVA: 0xAB2480
CAkMusicSwitchCntr *__fastcall CAkMusicSwitchCntr::Create(unsigned int in_ulID)
{
  CAkMusicSwitchCntr *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx
  unsigned int v5; // eax
  int v6; // ecx
  bool v7; // al

  EnterCriticalSection(&g_csMain.m_csLock);
  v2 = (CAkMusicSwitchCntr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x120ui64);
  if ( v2 )
  {
    CAkMusicSwitchCntr::CAkMusicSwitchCntr(v2, in_ulID);
    v4 = v3;
    if ( v3 )
    {
      v5 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v3 + 112i64))(v3);
      v7 = 0;
      if ( v5 <= 0xC )
      {
        v6 = 5121;
        if ( _bittest(&v6, v5) )
          v7 = 1;
      }
      *(_BYTE *)(v4 + 83) &= ~2u;
      *(_BYTE *)(v4 + 83) |= 2 * v7;
      CAkParameterNodeBase::AddToIndex((CAkParameterNodeBase *)v4);
    }
  }
  else
  {
    v4 = 0i64;
  }
  LeaveCriticalSection(&g_csMain.m_csLock);
  return (CAkMusicSwitchCntr *)v4;
}

// File Line: 60
// RVA: 0xAB2A40
unsigned int __fastcall CAkMusicSwitchCntr::SetInitialValues(
        CAkMusicSwitchCntr *this,
        char *in_pData,
        unsigned int in_ulDataSize)
{
  unsigned int result; // eax
  char *v5; // rdx
  char v6; // al
  unsigned int v7; // edi
  unsigned int v8; // r8d
  char *v9; // rdx
  int v10; // eax
  int v11; // ecx
  char *io_rpData; // [rsp+38h] [rbp+10h] BYREF
  unsigned int io_rulDataSize; // [rsp+40h] [rbp+18h] BYREF

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData;
  result = CAkMusicTransAware::SetMusicTransNodeParams(this, &io_rpData, &io_rulDataSize, 0);
  if ( result == 1 )
  {
    v5 = io_rpData;
    v6 = *io_rpData++;
    v5 += 5;
    this->m_bIsContinuePlayback = v6 != 0;
    v7 = *((_DWORD *)v5 - 1);
    io_rpData = v5;
    result = CAkMusicSwitchCntr::SetArguments(this, (unsigned int *)v5, &v5[4 * v7], v7);
    if ( result == 1 )
    {
      io_rpData += 5 * v7;
      v8 = *(_DWORD *)io_rpData;
      io_rpData += 4;
      v9 = io_rpData + 1;
      this->m_decisionTree.m_uMode = *io_rpData;
      io_rpData = v9;
      v10 = AkDecisionTree::SetTree(&this->m_decisionTree, v9, v8, v7);
      v11 = 1;
      if ( v10 != 1 )
        return v10;
      return v11;
    }
  }
  return result;
}

// File Line: 96
// RVA: 0xAB2940
// attributes: thunk
void __fastcall CAkMusicSwitchCntr::SetAkProp(
        CAkMusicSwitchCntr *this,
        AkPropID in_eProp,
        float in_fValue,
        float in_fMin,
        float in_fMax)
{
  CAkParameterNode::SetAkProp(this, in_eProp, in_fValue, in_fMin, in_fMax);
}

// File Line: 101
// RVA: 0xAB2920
void __fastcall CAkMusicSwitchCntr::SetAkProp(
        CAkMusicSwitchCntr *this,
        __int32 in_eProp,
        int in_iValue,
        unsigned int in_iMin,
        int in_iMax)
{
  if ( in_eProp == 17 )
    this->m_decisionTree.m_uMode = in_iValue;
  else
    CAkParameterNode::SetAkProp(this, in_eProp, (unsigned __int8)in_iValue, in_iMin, in_iMax);
}

// File Line: 114
// RVA: 0xAB2950
__int64 __fastcall CAkMusicSwitchCntr::SetArguments(
        CAkMusicSwitchCntr *this,
        unsigned int *in_pArgs,
        char *in_pGroupTypes,
        unsigned int in_uNumArgs)
{
  unsigned int *m_pArguments; // rdx
  unsigned __int64 v6; // rsi
  unsigned int v9; // edi
  char *m_pGroupTypes; // rdx
  unsigned int *v11; // rax
  char *v12; // rax

  m_pArguments = this->m_pArguments;
  v6 = in_uNumArgs;
  v9 = 1;
  if ( m_pArguments )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pArguments);
    this->m_pArguments = 0i64;
  }
  m_pGroupTypes = this->m_pGroupTypes;
  if ( m_pGroupTypes )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pGroupTypes);
    this->m_pGroupTypes = 0i64;
  }
  v11 = (unsigned int *)AK::MemoryMgr::Malloc(g_DefaultPoolId, (unsigned int)(4 * v6));
  this->m_pArguments = v11;
  if ( v11 )
  {
    memmove(v11, in_pArgs, (unsigned int)(4 * v6));
    v12 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v6);
    this->m_pGroupTypes = v12;
    if ( !v12 )
      return 52i64;
    memmove(v12, in_pGroupTypes, v6);
  }
  else if ( (_DWORD)v6 )
  {
    return 52;
  }
  return v9;
}

// File Line: 174
// RVA: 0xAB25B0
__int64 __fastcall CAkMusicSwitchCntr::ExecuteAction(CAkMusicSwitchCntr *this, ActionParams *in_rAction)
{
  char v2; // al
  CAkRegisteredObj *pGameObj; // r8

  if ( in_rAction->eType != ActionParamType_Seek )
    return CAkMusicNode::ExecuteAction(this, in_rAction);
  v2 = *((_BYTE *)&in_rAction[1].eType + 4);
  pGameObj = in_rAction->pGameObj;
  if ( (v2 & 1) != 0 )
    CAkMusicRenderer::SeekPercent(
      CAkMusicRenderer::m_pMusicRenderer,
      this,
      pGameObj,
      *(float *)&in_rAction[1].eType,
      (v2 & 2) != 0);
  else
    CAkMusicRenderer::SeekTimeAbsolute(
      CAkMusicRenderer::m_pMusicRenderer,
      this,
      pGameObj,
      in_rAction[1].eType,
      (v2 & 2) != 0);
  return 1i64;
}

// File Line: 197
// RVA: 0xAB23D0
__int64 __fastcall CAkMusicSwitchCntr::CanAddChild(CAkMusicSwitchCntr *this, CAkParameterNodeBase *in_pAudioNode)
{
  unsigned int v4; // ebx
  unsigned int v5; // ebp
  unsigned int key; // edi

  v4 = 1;
  v5 = in_pAudioNode->vfptr[3].Release(in_pAudioNode);
  if ( (unsigned __int16)this->CAkMusicTransAware::CAkMusicNode::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr[20].Release(this) == 0xFFFF )
    return 9i64;
  if ( v5 - 7 > 2 )
    return 4i64;
  if ( in_pAudioNode->m_pParentNode )
    return 21i64;
  key = in_pAudioNode->key;
  if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
         &this->m_mapChildId,
         key) )
  {
    return 5i64;
  }
  if ( this->key == key )
    return 23;
  return v4;
}

// File Line: 233
// RVA: 0xAB2510
void __fastcall CAkMusicSwitchCntr::CreateContext(
        CAkMusicSwitchCntr *this,
        CAkMatrixAwareCtx *in_pParentCtx,
        CAkRegisteredObj *in_GameObject,
        UserParams *in_rUserparams)
{
  CAkMusicSwitchCtx *v8; // rax
  CAkMusicSwitchCtx *v9; // rax
  CAkMusicCtx *v10; // rbx

  v8 = (CAkMusicSwitchCtx *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xC0ui64);
  if ( v8 )
  {
    CAkMusicSwitchCtx::CAkMusicSwitchCtx(v8, this, in_pParentCtx);
    v10 = v9;
    if ( v9 )
    {
      ++v9->m_uRefCount;
      if ( CAkMusicSwitchCtx::Init(v9, in_GameObject, in_rUserparams) != AK_Success )
        UFG::OnUnloadClass<UITest::HandleArrayTest>(v10);
      CAkMusicCtx::Release(v10);
    }
  }
}

// File Line: 258
// RVA: 0xAB2670
__int64 __fastcall CAkMusicSwitchCntr::PlayInternal(CAkMusicSwitchCntr *this, AkPBIParams *in_rPBIParams)
{
  __int64 v3; // rax
  CAkMatrixAwareCtx *v4; // rbx
  TransParams *pTransitionParameters; // rdx
  CAkTransition **v6; // r8
  AkMusicFade in_fadeParams; // [rsp+20h] [rbp-18h] BYREF

  v3 = ((__int64 (__fastcall *)(CAkMusicSwitchCntr *, _QWORD, CAkRegisteredObj *, UserParams *))this->CAkMusicTransAware::CAkMusicNode::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr[21].__vecDelDtor)(
         this,
         0i64,
         in_rPBIParams->pGameObj,
         &in_rPBIParams->userParams);
  v4 = (CAkMatrixAwareCtx *)v3;
  if ( !v3 )
    return 2i64;
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v3 + 72i64))(v3);
  pTransitionParameters = in_rPBIParams->pTransitionParameters;
  in_fadeParams.transitionTime = pTransitionParameters->TransitionTime;
  in_fadeParams.eFadeCurve = pTransitionParameters->eFadeCurve;
  in_fadeParams.iFadeOffset = CAkMatrixAwareCtx::GetSilentDuration(v4);
  CAkMusicCtx::_Play(v4, &in_fadeParams, v6);
  return 1i64;
}

// File Line: 283
// RVA: 0xAB2620
__int64 __fastcall CAkMusicSwitchCntr::ModifyActiveState(
        CAkMusicSwitchCntr *this,
        unsigned int in_stateID,
        bool in_bSupported)
{
  AkListBareLight<AkStateGroupChunk,AkListBareLightNextInNode> *p_m_states; // rcx
  unsigned int AudioNodeForState; // eax

  if ( this->key )
  {
    p_m_states = &this->m_states;
    if ( LODWORD(p_m_states->m_pFirst) == 1 )
    {
      AudioNodeForState = AkDecisionTree::GetAudioNodeForState((AkDecisionTree *)p_m_states, in_stateID);
      if ( AudioNodeForState )
      {
        if ( in_bSupported )
          return CAkParameterNodeBase::PrepareNodeData(AudioNodeForState);
        CAkParameterNodeBase::UnPrepareNodeData(AudioNodeForState);
      }
    }
  }
  return 1i64;
}

// File Line: 307
// RVA: 0xAB26F0
__int64 __fastcall CAkMusicSwitchCntr::PrepareData(CAkMusicSwitchCntr *this)
{
  unsigned int m_uPreparationCount; // eax
  unsigned int v3; // ebp
  unsigned int *m_pArguments; // rcx
  unsigned int v5; // r12d
  char *m_pGroupTypes; // rax
  AkGroupType v7; // r15d
  CAkStateMgr::PreparationStateItem *PreparedContent; // r14
  MapStruct<unsigned long,unsigned long> *m_pItems; // rbx
  MapStruct<unsigned long,unsigned long> *i; // rdi
  CAkStateMgr::PreparationStateItem *pNextItem; // rax
  __int64 v12; // rcx
  unsigned int v13; // eax
  CAkStateMgr::PreparationStateItem *v14; // rax
  __int64 v15; // rcx
  CAkKeyArray<unsigned long,unsigned long,8> out_switchNodeAssoc; // [rsp+20h] [rbp-38h] BYREF

  if ( g_settings.bEnableGameSyncPreparation && this->m_decisionTree.m_uDepth == 1 )
  {
    m_uPreparationCount = this->m_uPreparationCount;
    v3 = 1;
    if ( m_uPreparationCount )
    {
      this->m_uPreparationCount = m_uPreparationCount + 1;
    }
    else
    {
      v3 = this->CAkMusicTransAware::CAkMusicNode::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr[21].AddRef(this);
      if ( v3 == 1 )
      {
        m_pArguments = this->m_pArguments;
        if ( m_pArguments )
          v5 = *m_pArguments;
        else
          v5 = 0;
        m_pGroupTypes = this->m_pGroupTypes;
        if ( m_pGroupTypes )
          v7 = (unsigned __int8)*m_pGroupTypes;
        else
          v7 = AkGroupType_Switch;
        PreparedContent = CAkPreparationAware::GetPreparedContent(&this->CAkPreparationAware, v5, v7);
        if ( PreparedContent )
        {
          out_switchNodeAssoc.m_pItems = 0i64;
          *(_QWORD *)&out_switchNodeAssoc.m_uLength = 0i64;
          AkDecisionTree::GetSwitchNodeAssoc(&this->m_decisionTree, &out_switchNodeAssoc);
          m_pItems = out_switchNodeAssoc.m_pItems;
          for ( i = out_switchNodeAssoc.m_pItems; i != &m_pItems[out_switchNodeAssoc.m_uLength]; ++i )
          {
            if ( !i->key )
              goto LABEL_18;
            pNextItem = PreparedContent->pNextItem;
            v12 = (__int64)PreparedContent->pNextItem
                + 4 * LODWORD(PreparedContent->m_PreparedContent.m_PreparableContentList.m_pItems);
            if ( PreparedContent->pNextItem != (CAkStateMgr::PreparationStateItem *)v12 )
            {
              do
              {
                if ( LODWORD(pNextItem->pNextItem) == i->key )
                  break;
                pNextItem = (CAkStateMgr::PreparationStateItem *)((char *)pNextItem + 4);
              }
              while ( pNextItem != (CAkStateMgr::PreparationStateItem *)v12 );
              if ( pNextItem != (CAkStateMgr::PreparationStateItem *)v12 )
              {
LABEL_18:
                v13 = CAkParameterNodeBase::PrepareNodeData(i->item);
                m_pItems = out_switchNodeAssoc.m_pItems;
                v3 = v13;
              }
            }
            if ( v3 != 1 && m_pItems != i )
            {
              do
              {
                v14 = PreparedContent->pNextItem;
                v15 = (__int64)PreparedContent->pNextItem
                    + 4 * LODWORD(PreparedContent->m_PreparedContent.m_PreparableContentList.m_pItems);
                if ( PreparedContent->pNextItem != (CAkStateMgr::PreparationStateItem *)v15 )
                {
                  do
                  {
                    if ( LODWORD(v14->pNextItem) == m_pItems->key )
                      break;
                    v14 = (CAkStateMgr::PreparationStateItem *)((char *)v14 + 4);
                  }
                  while ( v14 != (CAkStateMgr::PreparationStateItem *)v15 );
                  if ( v14 != (CAkStateMgr::PreparationStateItem *)v15 )
                    CAkParameterNodeBase::UnPrepareNodeData(i->item);
                }
                ++m_pItems;
              }
              while ( m_pItems != i );
              m_pItems = out_switchNodeAssoc.m_pItems;
            }
          }
          if ( m_pItems )
          {
            out_switchNodeAssoc.m_uLength = 0;
            AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
            out_switchNodeAssoc.m_pItems = 0i64;
            out_switchNodeAssoc.m_ulReserved = 0;
          }
          if ( v3 == 1 )
          {
            ++this->m_uPreparationCount;
            v3 = CAkPreparationAware::SubscribePrepare(&this->CAkPreparationAware, v5, v7);
            if ( v3 != 1 )
            {
              this->CAkMusicTransAware::CAkMusicNode::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr[10].AddRef(this);
              this->CAkMusicTransAware::CAkMusicNode::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr[21].Release(this);
            }
            return v3;
          }
        }
        else
        {
          v3 = 52;
        }
        this->CAkMusicTransAware::CAkMusicNode::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr[21].Release(this);
      }
    }
    return v3;
  }
  return CAkMusicNode::PrepareData(this);
}

// File Line: 379
// RVA: 0xAB2B20
void __fastcall CAkMusicSwitchCntr::UnPrepareData(CAkMusicSwitchCntr *this)
{
  unsigned int m_uPreparationCount; // eax
  unsigned int v3; // eax
  unsigned int *m_pArguments; // rax
  unsigned int v5; // ebp
  char *m_pGroupTypes; // rax
  AkGroupType v7; // r14d
  CAkStateMgr::PreparationStateItem *PreparedContent; // rsi
  MapStruct<unsigned long,unsigned long> *m_pItems; // r8
  unsigned int m_uLength; // r9d
  MapStruct<unsigned long,unsigned long> *v11; // rbx
  CAkStateMgr::PreparationStateItem *pNextItem; // rax
  __int64 v13; // rcx
  CAkKeyArray<unsigned long,unsigned long,8> out_switchNodeAssoc; // [rsp+20h] [rbp-28h] BYREF

  if ( g_settings.bEnableGameSyncPreparation && this->m_decisionTree.m_uDepth == 1 )
  {
    m_uPreparationCount = this->m_uPreparationCount;
    if ( m_uPreparationCount )
    {
      v3 = m_uPreparationCount - 1;
      this->m_uPreparationCount = v3;
      if ( !v3 )
      {
        m_pArguments = this->m_pArguments;
        if ( m_pArguments )
          v5 = *m_pArguments;
        else
          v5 = 0;
        m_pGroupTypes = this->m_pGroupTypes;
        if ( m_pGroupTypes )
          v7 = (unsigned __int8)*m_pGroupTypes;
        else
          v7 = AkGroupType_Switch;
        PreparedContent = CAkPreparationAware::GetPreparedContent(&this->CAkPreparationAware, v5, v7);
        if ( PreparedContent )
        {
          out_switchNodeAssoc.m_pItems = 0i64;
          *(_QWORD *)&out_switchNodeAssoc.m_uLength = 0i64;
          AkDecisionTree::GetSwitchNodeAssoc(&this->m_decisionTree, &out_switchNodeAssoc);
          m_pItems = out_switchNodeAssoc.m_pItems;
          m_uLength = out_switchNodeAssoc.m_uLength;
          v11 = out_switchNodeAssoc.m_pItems;
          if ( out_switchNodeAssoc.m_pItems != &out_switchNodeAssoc.m_pItems[out_switchNodeAssoc.m_uLength] )
          {
            do
            {
              if ( !v11->key )
                goto LABEL_18;
              pNextItem = PreparedContent->pNextItem;
              v13 = (__int64)PreparedContent->pNextItem
                  + 4 * LODWORD(PreparedContent->m_PreparedContent.m_PreparableContentList.m_pItems);
              if ( PreparedContent->pNextItem != (CAkStateMgr::PreparationStateItem *)v13 )
              {
                do
                {
                  if ( LODWORD(pNextItem->pNextItem) == v11->key )
                    break;
                  pNextItem = (CAkStateMgr::PreparationStateItem *)((char *)pNextItem + 4);
                }
                while ( pNextItem != (CAkStateMgr::PreparationStateItem *)v13 );
                if ( pNextItem != (CAkStateMgr::PreparationStateItem *)v13 )
                {
LABEL_18:
                  CAkParameterNodeBase::UnPrepareNodeData(v11->item);
                  m_uLength = out_switchNodeAssoc.m_uLength;
                  m_pItems = out_switchNodeAssoc.m_pItems;
                }
              }
              ++v11;
            }
            while ( v11 != &m_pItems[m_uLength] );
          }
          if ( m_pItems )
          {
            out_switchNodeAssoc.m_uLength = 0;
            AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
          }
        }
        CAkPreparationAware::UnsubscribePrepare(&this->CAkPreparationAware, v5, v7);
        this->CAkMusicTransAware::CAkMusicNode::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr[21].Release(this);
      }
    }
  }
  else
  {
    CAkMusicNode::UnPrepareData(this);
  }
}

