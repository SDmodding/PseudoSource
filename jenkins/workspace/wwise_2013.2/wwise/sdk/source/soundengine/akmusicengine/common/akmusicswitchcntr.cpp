// File Line: 33
// RVA: 0xAB22B0
void __fastcall CAkMusicSwitchCntr::CAkMusicSwitchCntr(CAkMusicSwitchCntr *this, unsigned int in_ulID)
{
  CAkMusicSwitchCntr *v2; // rbx

  v2 = this;
  CAkMusicTransAware::CAkMusicTransAware((CAkMusicTransAware *)&this->vfptr, in_ulID);
  v2->pNextItemPrepare = 0i64;
  v2->m_uPreparationCount = 0;
  v2->vfptr = (CAkIndexableVtbl *)&CAkMusicSwitchCntr::`vftable{for `CAkMusicTransAware};
  v2->vfptr = (CAkPreparationAwareVtbl *)&CAkMusicSwitchCntr::`vftable{for `CAkPreparationAware};
  AkDecisionTree::AkDecisionTree(&v2->m_decisionTree);
  v2->m_bIsContinuePlayback = 1;
  v2->m_pArguments = 0i64;
  v2->m_pGroupTypes = 0i64;
}

// File Line: 37
// RVA: 0xAB2320
void __fastcall CAkMusicSwitchCntr::~CAkMusicSwitchCntr(CAkMusicSwitchCntr *this)
{
  unsigned int *v1; // rdx
  CAkMusicSwitchCntr *v2; // rbx
  char *v3; // rdx

  v1 = this->m_pArguments;
  v2 = this;
  this->vfptr = (CAkIndexableVtbl *)&CAkMusicSwitchCntr::`vftable{for `CAkMusicTransAware};
  this->vfptr = (CAkPreparationAwareVtbl *)&CAkMusicSwitchCntr::`vftable{for `CAkPreparationAware};
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
    v2->m_pArguments = 0i64;
  }
  v3 = v2->m_pGroupTypes;
  if ( v3 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v3);
    v2->m_pGroupTypes = 0i64;
  }
  AkDecisionTree::~AkDecisionTree(&v2->m_decisionTree);
  CAkMusicTransAware::~CAkMusicTransAware((CAkMusicTransAware *)&v2->vfptr);
}

// File Line: 45
// RVA: 0xAB2480
CAkMusicSwitchCntr *__fastcall CAkMusicSwitchCntr::Create(unsigned int in_ulID)
{
  unsigned int v1; // ebx
  CAkMusicSwitchCntr *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx
  unsigned int v5; // eax
  signed int v6; // ecx
  bool v7; // al

  v1 = in_ulID;
  EnterCriticalSection(&g_csMain.m_csLock);
  v2 = (CAkMusicSwitchCntr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x120ui64);
  if ( v2 )
  {
    CAkMusicSwitchCntr::CAkMusicSwitchCntr(v2, v1);
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
      *(_BYTE *)(v4 + 83) &= 0xFDu;
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
unsigned int __fastcall CAkMusicSwitchCntr::SetInitialValues(CAkMusicSwitchCntr *this, char *in_pData, unsigned int in_ulDataSize)
{
  CAkMusicSwitchCntr *v3; // rbx
  unsigned int result; // eax
  char v5; // al
  char *v6; // rdx
  unsigned int v7; // edi
  unsigned int v8; // er8
  char *v9; // rdx
  AKRESULT v10; // eax
  AKRESULT v11; // ecx
  char *io_rpData; // [rsp+38h] [rbp+10h]
  unsigned int io_rulDataSize; // [rsp+40h] [rbp+18h]

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData;
  v3 = this;
  result = CAkMusicTransAware::SetMusicTransNodeParams(
             (CAkMusicTransAware *)&this->vfptr,
             &io_rpData,
             &io_rulDataSize,
             0);
  if ( result == 1 )
  {
    v5 = *io_rpData;
    v6 = io_rpData + 1;
    io_rpData = v6;
    v6 += 4;
    v3->m_bIsContinuePlayback = v5 != 0;
    v7 = *((_DWORD *)v6 - 1);
    io_rpData = v6;
    result = CAkMusicSwitchCntr::SetArguments(v3, (unsigned int *)v6, &v6[4 * v7], v7);
    if ( result == 1 )
    {
      io_rpData += 5 * v7;
      v8 = *(_DWORD *)io_rpData;
      io_rpData += 4;
      v9 = io_rpData + 1;
      v3->m_decisionTree.m_uMode = *io_rpData;
      io_rpData = v9;
      v10 = (unsigned int)AkDecisionTree::SetTree(&v3->m_decisionTree, v9, v8, v7);
      v11 = 1;
      if ( v10 != 1 )
        v11 = v10;
      result = v11;
    }
  }
  return result;
}

// File Line: 96
// RVA: 0xAB2940
void __fastcall CAkMusicSwitchCntr::SetAkProp(CAkMusicSwitchCntr *this, AkPropID in_eProp, float in_fValue, float in_fMin, float in_fMax)
{
  CAkParameterNode::SetAkProp((CAkParameterNode *)&this->vfptr, in_eProp, in_fValue, in_fMin, in_fMax);
}

// File Line: 101
// RVA: 0xAB2920
void __fastcall CAkMusicSwitchCntr::SetAkProp(CAkMusicSwitchCntr *this, AkPropID in_eProp, int in_iValue, int in_iMin, int in_iMax)
{
  if ( in_eProp == 17 )
    this->m_decisionTree.m_uMode = in_iValue;
  else
    CAkParameterNode::SetAkProp(
      (CAkParameterNode *)&this->vfptr,
      in_eProp,
      (unsigned __int8)in_iValue,
      in_iMin,
      in_iMax);
}

// File Line: 114
// RVA: 0xAB2950
signed __int64 __fastcall CAkMusicSwitchCntr::SetArguments(CAkMusicSwitchCntr *this, unsigned int *in_pArgs, char *in_pGroupTypes, unsigned int in_uNumArgs)
{
  unsigned int *v4; // r15
  unsigned int *v5; // rdx
  unsigned __int64 v6; // rsi
  char *v7; // r14
  CAkMusicSwitchCntr *v8; // rbx
  unsigned int v9; // edi
  char *v10; // rdx
  unsigned int *v11; // rax
  char *v12; // rax

  v4 = in_pArgs;
  v5 = this->m_pArguments;
  v6 = in_uNumArgs;
  v7 = in_pGroupTypes;
  v8 = this;
  v9 = 1;
  if ( v5 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v5);
    v8->m_pArguments = 0i64;
  }
  v10 = v8->m_pGroupTypes;
  if ( v10 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v10);
    v8->m_pGroupTypes = 0i64;
  }
  v11 = (unsigned int *)AK::MemoryMgr::Malloc(g_DefaultPoolId, (unsigned int)(4 * v6));
  v8->m_pArguments = v11;
  if ( v11 )
  {
    memmove(v11, v4, (unsigned int)(4 * v6));
    v12 = (char *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v6);
    v8->m_pGroupTypes = v12;
    if ( !v12 )
      return 52i64;
    memmove(v12, v7, v6);
  }
  else if ( (_DWORD)v6 )
  {
    v9 = 52;
  }
  return v9;
}

// File Line: 174
// RVA: 0xAB25B0
__int64 __fastcall CAkMusicSwitchCntr::ExecuteAction(CAkMusicSwitchCntr *this, ActionParams *in_rAction)
{
  unsigned __int8 v2; // al
  CAkRegisteredObj *v3; // r8

  if ( in_rAction->eType != 4 )
    return CAkMusicNode::ExecuteAction((CAkMusicNode *)&this->vfptr, in_rAction);
  v2 = *((_BYTE *)&in_rAction[1].eType + 4);
  v3 = in_rAction->pGameObj;
  if ( v2 & 1 )
    CAkMusicRenderer::SeekPercent(
      CAkMusicRenderer::m_pMusicRenderer,
      (CAkMusicNode *)&this->vfptr,
      v3,
      *(float *)&in_rAction[1].eType,
      (v2 >> 1) & 1);
  else
    CAkMusicRenderer::SeekTimeAbsolute(
      CAkMusicRenderer::m_pMusicRenderer,
      (CAkMusicNode *)&this->vfptr,
      v3,
      in_rAction[1].eType,
      (v2 >> 1) & 1);
  return 1i64;
}

// File Line: 197
// RVA: 0xAB23D0
signed __int64 __fastcall CAkMusicSwitchCntr::CanAddChild(CAkMusicSwitchCntr *this, CAkParameterNodeBase *in_pAudioNode)
{
  CAkMusicSwitchCntr *v2; // rsi
  CAkParameterNodeBase *v3; // rdi
  unsigned int v4; // ebx
  unsigned int v5; // ebp
  unsigned int v7; // edi

  v2 = this;
  v3 = in_pAudioNode;
  v4 = 1;
  v5 = in_pAudioNode->vfptr[3].Release((CAkIndexable *)in_pAudioNode);
  if ( (unsigned __int16)v2->vfptr[20].Release((CAkIndexable *)&v2->vfptr) >= 0xFFFFu )
    return 9i64;
  if ( v5 - 7 > 2 )
    return 4i64;
  if ( v3->m_pParentNode )
    return 21i64;
  v7 = v3->key;
  if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
         &v2->m_mapChildId,
         v7) )
  {
    return 5i64;
  }
  if ( v2->key == v7 )
    v4 = 23;
  return v4;
}

// File Line: 233
// RVA: 0xAB2510
void __fastcall CAkMusicSwitchCntr::CreateContext(CAkMusicSwitchCntr *this, CAkMatrixAwareCtx *in_pParentCtx, CAkRegisteredObj *in_GameObject, UserParams *in_rUserparams)
{
  CAkMusicSwitchCntr *v4; // rdi
  CAkMatrixAwareCtx *v5; // rbx
  UserParams *v6; // rsi
  CAkRegisteredObj *v7; // rbp
  CAkMusicSwitchCtx *v8; // rax
  CAkMusicSwitchCtx *v9; // rax
  CAkMusicCtx *v10; // rbx

  v4 = this;
  v5 = in_pParentCtx;
  v6 = in_rUserparams;
  v7 = in_GameObject;
  v8 = (CAkMusicSwitchCtx *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xC0ui64);
  if ( v8 )
  {
    CAkMusicSwitchCtx::CAkMusicSwitchCtx(v8, v4, (CAkMusicCtx *)&v5->vfptr);
    v10 = (CAkMusicCtx *)&v9->vfptr;
    if ( v9 )
    {
      ++v9->m_uRefCount;
      if ( CAkMusicSwitchCtx::Init(v9, v7, v6) != 1 )
        UFG::OnUnloadClass<UITest::HandleArrayTest>(v10);
      CAkMusicCtx::Release(v10);
    }
  }
}

// File Line: 258
// RVA: 0xAB2670
signed __int64 __fastcall CAkMusicSwitchCntr::PlayInternal(CAkMusicSwitchCntr *this, AkPBIParams *in_rPBIParams)
{
  AkPBIParams *v2; // rdi
  __int64 v3; // rax
  CAkMatrixAwareCtx *v4; // rbx
  TransParams *v5; // rdx
  __int64 v6; // r8
  AkMusicFade in_fadeParams; // [rsp+20h] [rbp-18h]

  v2 = in_rPBIParams;
  v3 = ((__int64 (__fastcall *)(CAkMusicSwitchCntr *, _QWORD, CAkRegisteredObj *, UserParams *))this->vfptr[21].__vecDelDtor)(
         this,
         0i64,
         in_rPBIParams->pGameObj,
         &in_rPBIParams->userParams);
  v4 = (CAkMatrixAwareCtx *)v3;
  if ( !v3 )
    return 2i64;
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v3 + 72i64))(v3);
  v5 = v2->pTransitionParameters;
  in_fadeParams.transitionTime = v5->TransitionTime;
  in_fadeParams.eFadeCurve = v5->eFadeCurve;
  in_fadeParams.iFadeOffset = CAkMatrixAwareCtx::GetSilentDuration(v4);
  CAkMusicCtx::_Play((CAkMusicCtx *)&v4->vfptr, &in_fadeParams, v6);
  return 1i64;
}

// File Line: 283
// RVA: 0xAB2620
__int64 __fastcall CAkMusicSwitchCntr::ModifyActiveState(CAkMusicSwitchCntr *this, unsigned int in_stateID, bool in_bSupported)
{
  bool v3; // bl
  AkDecisionTree *v4; // rcx
  unsigned int v5; // eax

  v3 = in_bSupported;
  if ( this->key )
  {
    v4 = (AkDecisionTree *)&this->m_states;
    if ( v4->m_uDepth == 1 )
    {
      v5 = AkDecisionTree::GetAudioNodeForState(v4, in_stateID);
      if ( v5 )
      {
        if ( v3 )
          return CAkParameterNodeBase::PrepareNodeData(v5);
        CAkParameterNodeBase::UnPrepareNodeData(v5);
      }
    }
  }
  return 1i64;
}

// File Line: 307
// RVA: 0xAB26F0
__int64 __fastcall CAkMusicSwitchCntr::PrepareData(CAkMusicSwitchCntr *this)
{
  CAkMusicSwitchCntr *v1; // rsi
  unsigned int v2; // eax
  unsigned int v3; // ebp
  unsigned int *v4; // rcx
  unsigned int v5; // er12
  char *v6; // rax
  AkGroupType v7; // er15
  CAkStateMgr::PreparationStateItem *v8; // r14
  MapStruct<unsigned long,unsigned long> *v9; // rbx
  MapStruct<unsigned long,unsigned long> *i; // rdi
  CAkStateMgr::PreparationStateItem *v11; // rax
  signed __int64 v12; // rcx
  unsigned int v13; // eax
  CAkStateMgr::PreparationStateItem *v14; // rax
  signed __int64 v15; // rcx
  CAkKeyArray<unsigned long,unsigned long,8> out_switchNodeAssoc; // [rsp+20h] [rbp-38h]

  v1 = this;
  if ( unk_14249E980 && this->m_decisionTree.m_uDepth == 1 )
  {
    v2 = this->m_uPreparationCount;
    v3 = 1;
    if ( v2 )
    {
      this->m_uPreparationCount = v2 + 1;
    }
    else
    {
      v3 = ((__int64 (*)(void))this->vfptr[21].AddRef)();
      if ( v3 == 1 )
      {
        v4 = v1->m_pArguments;
        if ( v4 )
          v5 = *v4;
        else
          v5 = 0;
        v6 = v1->m_pGroupTypes;
        if ( v6 )
          v7 = (unsigned __int8)*v6;
        else
          v7 = 0;
        v8 = CAkPreparationAware::GetPreparedContent((CAkPreparationAware *)&v1->vfptr, v5, v7);
        if ( v8 )
        {
          out_switchNodeAssoc = (CAkKeyArray<unsigned long,unsigned long,8>)0i64;
          AkDecisionTree::GetSwitchNodeAssoc(&v1->m_decisionTree, &out_switchNodeAssoc);
          v9 = out_switchNodeAssoc.m_pItems;
          for ( i = out_switchNodeAssoc.m_pItems; i != &v9[out_switchNodeAssoc.m_uLength]; ++i )
          {
            if ( !i->key )
              goto LABEL_41;
            v11 = v8->pNextItem;
            v12 = (signed __int64)v8->pNextItem + 4 * LODWORD(v8->m_PreparedContent.m_PreparableContentList.m_pItems);
            if ( v8->pNextItem != (CAkStateMgr::PreparationStateItem *)v12 )
            {
              do
              {
                if ( LODWORD(v11->pNextItem) == i->key )
                  break;
                v11 = (CAkStateMgr::PreparationStateItem *)((char *)v11 + 4);
              }
              while ( v11 != (CAkStateMgr::PreparationStateItem *)v12 );
              if ( v11 != (CAkStateMgr::PreparationStateItem *)v12 )
              {
LABEL_41:
                v13 = CAkParameterNodeBase::PrepareNodeData(i->item);
                v9 = out_switchNodeAssoc.m_pItems;
                v3 = v13;
              }
            }
            if ( v3 != 1 && v9 != i )
            {
              do
              {
                v14 = v8->pNextItem;
                v15 = (signed __int64)v8->pNextItem
                    + 4 * LODWORD(v8->m_PreparedContent.m_PreparableContentList.m_pItems);
                if ( v8->pNextItem != (CAkStateMgr::PreparationStateItem *)v15 )
                {
                  do
                  {
                    if ( LODWORD(v14->pNextItem) == v9->key )
                      break;
                    v14 = (CAkStateMgr::PreparationStateItem *)((char *)v14 + 4);
                  }
                  while ( v14 != (CAkStateMgr::PreparationStateItem *)v15 );
                  if ( v14 != (CAkStateMgr::PreparationStateItem *)v15 )
                    CAkParameterNodeBase::UnPrepareNodeData(i->item);
                }
                ++v9;
              }
              while ( v9 != i );
              v9 = out_switchNodeAssoc.m_pItems;
            }
          }
          if ( v9 )
          {
            out_switchNodeAssoc.m_uLength = 0;
            AK::MemoryMgr::Free(g_DefaultPoolId, v9);
            out_switchNodeAssoc.m_pItems = 0i64;
            out_switchNodeAssoc.m_ulReserved = 0;
          }
          if ( v3 == 1 )
          {
            ++v1->m_uPreparationCount;
            v3 = CAkPreparationAware::SubscribePrepare((CAkPreparationAware *)&v1->vfptr, v5, v7);
            if ( v3 != 1 )
            {
              v1->vfptr[10].AddRef((CAkIndexable *)&v1->vfptr);
              v1->vfptr[21].Release((CAkIndexable *)&v1->vfptr);
            }
            return v3;
          }
        }
        else
        {
          v3 = 52;
        }
        v1->vfptr[21].Release((CAkIndexable *)&v1->vfptr);
      }
    }
    return v3;
  }
  return CAkMusicNode::PrepareData((CAkMusicNode *)&this->vfptr);
}

// File Line: 379
// RVA: 0xAB2B20
void __fastcall CAkMusicSwitchCntr::UnPrepareData(CAkMusicSwitchCntr *this)
{
  CAkMusicSwitchCntr *v1; // rdi
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int *v4; // rax
  unsigned int v5; // ebp
  char *v6; // rax
  AkGroupType v7; // er14
  CAkStateMgr::PreparationStateItem *v8; // rsi
  MapStruct<unsigned long,unsigned long> *v9; // r8
  unsigned int v10; // er9
  MapStruct<unsigned long,unsigned long> *v11; // rbx
  CAkStateMgr::PreparationStateItem *v12; // rax
  signed __int64 v13; // rcx
  CAkKeyArray<unsigned long,unsigned long,8> out_switchNodeAssoc; // [rsp+20h] [rbp-28h]

  v1 = this;
  if ( unk_14249E980 && this->m_decisionTree.m_uDepth == 1 )
  {
    v2 = this->m_uPreparationCount;
    if ( v2 )
    {
      v3 = v2 - 1;
      this->m_uPreparationCount = v3;
      if ( !v3 )
      {
        v4 = this->m_pArguments;
        if ( v4 )
          v5 = *v4;
        else
          v5 = 0;
        v6 = this->m_pGroupTypes;
        if ( v6 )
          v7 = (unsigned __int8)*v6;
        else
          v7 = 0;
        v8 = CAkPreparationAware::GetPreparedContent((CAkPreparationAware *)&this->vfptr, v5, v7);
        if ( v8 )
        {
          out_switchNodeAssoc = (CAkKeyArray<unsigned long,unsigned long,8>)0i64;
          AkDecisionTree::GetSwitchNodeAssoc(&v1->m_decisionTree, &out_switchNodeAssoc);
          v9 = out_switchNodeAssoc.m_pItems;
          v10 = out_switchNodeAssoc.m_uLength;
          v11 = out_switchNodeAssoc.m_pItems;
          if ( out_switchNodeAssoc.m_pItems != &out_switchNodeAssoc.m_pItems[out_switchNodeAssoc.m_uLength] )
          {
            do
            {
              if ( !v11->key )
                goto LABEL_26;
              v12 = v8->pNextItem;
              v13 = (signed __int64)v8->pNextItem + 4 * LODWORD(v8->m_PreparedContent.m_PreparableContentList.m_pItems);
              if ( v8->pNextItem != (CAkStateMgr::PreparationStateItem *)v13 )
              {
                do
                {
                  if ( LODWORD(v12->pNextItem) == v11->key )
                    break;
                  v12 = (CAkStateMgr::PreparationStateItem *)((char *)v12 + 4);
                }
                while ( v12 != (CAkStateMgr::PreparationStateItem *)v13 );
                if ( v12 != (CAkStateMgr::PreparationStateItem *)v13 )
                {
LABEL_26:
                  CAkParameterNodeBase::UnPrepareNodeData(v11->item);
                  v10 = out_switchNodeAssoc.m_uLength;
                  v9 = out_switchNodeAssoc.m_pItems;
                }
              }
              ++v11;
            }
            while ( v11 != &v9[v10] );
          }
          if ( v9 )
          {
            out_switchNodeAssoc.m_uLength = 0;
            AK::MemoryMgr::Free(g_DefaultPoolId, v9);
          }
        }
        CAkPreparationAware::UnsubscribePrepare((CAkPreparationAware *)&v1->vfptr, v5, v7);
        v1->vfptr[21].Release((CAkIndexable *)&v1->vfptr);
      }
    }
  }
  else
  {
    CAkMusicNode::UnPrepareData((CAkMusicNode *)&this->vfptr);
  }
}

