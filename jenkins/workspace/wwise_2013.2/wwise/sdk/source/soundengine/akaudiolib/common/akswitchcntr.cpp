// File Line: 45
// RVA: 0xA890F0
void __fastcall CAkSwitchCntr::CAkSwitchCntr(CAkSwitchCntr *this, unsigned int in_ulID)
{
  CAkMultiPlayNode::CAkMultiPlayNode(this, in_ulID);
  CAkSwitchAware::CAkSwitchAware(&this->CAkSwitchAware);
  this->pNextItemPrepare = 0i64;
  this->m_uPreparationCount = 0;
  *(_QWORD *)&this->m_eGroupType = 0i64;
  this->m_ulDefaultSwitch = 0;
  this->CAkMultiPlayNode::CAkContainerBase::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr = (CAkIndexableVtbl *)&CAkSwitchCntr::`vftable{for `CAkMultiPlayNode};
  this->CAkSwitchAware::vfptr = (CAkSwitchAwareVtbl *)&CAkSwitchCntr::`vftable{for `CAkSwitchAware};
  this->CAkPreparationAware::vfptr = (CAkPreparationAwareVtbl *)&CAkSwitchCntr::`vftable{for `CAkPreparationAware};
  *(_QWORD *)&this->m_SwitchList.m_ulMinNumListItems = 0i64;
  this->m_SwitchList.m_ulNumListItems = 0;
  *(_QWORD *)&this->m_listParameters.m_ulMinNumListItems = 0i64;
  this->m_listParameters.m_ulNumListItems = 0;
  *(_QWORD *)&this->m_listSwitchContPlayback.m_ulMinNumListItems = 0i64;
  this->m_listSwitchContPlayback.m_ulNumListItems = 0;
}

// File Line: 50
// RVA: 0xA89190
void __fastcall CAkSwitchCntr::~CAkSwitchCntr(CAkSwitchCntr *this)
{
  CAkSwitchAware *v2; // rcx

  v2 = &this->CAkSwitchAware;
  v2[-23].vfptr = (CAkSwitchAwareVtbl *)&CAkSwitchCntr::`vftable{for `CAkMultiPlayNode};
  v2->vfptr = (CAkSwitchAwareVtbl *)&CAkSwitchCntr::`vftable{for `CAkSwitchAware};
  v2[1].vfptr = (CAkSwitchAwareVtbl *)&CAkSwitchCntr::`vftable{for `CAkPreparationAware};
  CAkSwitchAware::UnsubscribeSwitches(v2);
  CAkSwitchCntr::ClearSwitches(this);
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::Term(&this->m_listSwitchContPlayback);
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::Term(&this->m_listParameters);
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::Term(&this->m_SwitchList);
  CAkMultiPlayNode::Term(this);
  CAkSwitchAware::~CAkSwitchAware(&this->CAkSwitchAware);
  CAkMultiPlayNode::~CAkMultiPlayNode(this);
}

// File Line: 55
// RVA: 0xA8A850
int __fastcall CAkSwitchCntr::SetInitialValues(CAkSwitchCntr *this, char *in_pData, unsigned int in_ulDataSize)
{
  int result; // eax
  char *v5; // rax
  AkGroupType v6; // r8d
  unsigned int v7; // edx
  unsigned int v8; // ebx
  char v9; // di
  AKRESULT v10; // edi
  unsigned int v11; // esi
  CAkKeyList<unsigned long,CAkSwitchPackage,2,ArrayPoolDefault> *p_m_SwitchList; // r14
  char *v13; // r10
  int v14; // r12d
  unsigned int v15; // ebx
  unsigned int v16; // edx
  CAkSwitchPackage *v17; // rsi
  unsigned int v18; // r15d
  unsigned int *v19; // rax
  int v20; // r14d
  unsigned int v21; // ebx
  unsigned int *m_pItems; // rax
  __int64 v23; // rcx
  unsigned int *v24; // rdx
  unsigned int *v25; // rax
  __int64 v26; // rbx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v27; // rax
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v28; // rcx
  unsigned int v29; // edx
  char *v30; // r10
  char v31; // di
  unsigned int v32; // r9d
  char v33; // cl
  char v34; // al
  int v35; // r8d
  char *v36; // r10
  int v37; // eax
  unsigned int v38; // [rsp+20h] [rbp-58h]
  AkSwitchNodeParams v39; // [rsp+28h] [rbp-50h]
  AkSwitchNodeParams v40; // [rsp+40h] [rbp-38h] BYREF
  char *io_rpData; // [rsp+98h] [rbp+20h] BYREF
  unsigned int io_rulDataSize; // [rsp+A0h] [rbp+28h] BYREF
  unsigned int v43; // [rsp+A8h] [rbp+30h]

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData + 4;
  result = CAkParameterNodeBase::SetNodeBaseParams(this, &io_rpData, &io_rulDataSize, 0);
  if ( result == 1 )
  {
    v5 = io_rpData;
    v6 = *(_DWORD *)io_rpData;
    io_rpData += 4;
    v7 = *((_DWORD *)v5 + 1);
    io_rpData = v5 + 8;
    v8 = *((_DWORD *)v5 + 2);
    io_rpData = v5 + 12;
    v9 = v5[12];
    io_rpData = v5 + 13;
    result = 1;
    if ( v7 != this->m_ulGroupID || v6 != this->m_eGroupType )
    {
      this->m_ulGroupID = v7;
      this->m_eGroupType = v6;
      result = CAkSwitchAware::SubscribeSwitch(&this->CAkSwitchAware, v7, v6);
    }
    if ( result == 1 )
    {
      *((_BYTE *)&this->CAkParameterNodeBase + 83) &= ~0x80u;
      this->m_ulDefaultSwitch = v8;
      *((_BYTE *)&this->CAkParameterNodeBase + 83) |= (v9 != 0) << 7;
      result = CAkParentNode<CAkParameterNode>::SetChildren(this, &io_rpData, &io_rulDataSize);
      v10 = result;
      if ( result == 1 )
      {
        v11 = *(_DWORD *)io_rpData;
        io_rpData += 4;
        p_m_SwitchList = &this->m_SwitchList;
        v38 = v11;
        CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::Reserve(
          &this->m_SwitchList,
          v11);
        v13 = io_rpData;
        v14 = 0;
        v15 = 0;
        v43 = 0;
        if ( v11 )
        {
          while ( 1 )
          {
            v16 = *(_DWORD *)v13;
            io_rpData = v13 + 4;
            v17 = CAkKeyList<unsigned long,CAkSwitchPackage,2,ArrayPoolDefault>::Set(p_m_SwitchList, v16);
            if ( !v17 )
              return 2;
            v13 = io_rpData + 4;
            v18 = *(_DWORD *)io_rpData;
            io_rpData += 4;
            if ( v18 )
            {
              v19 = (unsigned int *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 4i64 * v18);
              v17->m_list.m_pItems = v19;
              if ( v19 )
                v17->m_list.m_ulReserved = v18;
              v13 = io_rpData;
            }
            v20 = 0;
            if ( v18 )
              break;
LABEL_27:
            v43 = ++v15;
            if ( v15 >= v38 )
              goto LABEL_30;
            p_m_SwitchList = &this->m_SwitchList;
          }
          while ( 1 )
          {
            v21 = *(_DWORD *)v13;
            v13 += 4;
            v10 = AK_InvalidSwitchType;
            io_rpData = v13;
            m_pItems = v17->m_list.m_pItems;
            v23 = (__int64)&v17->m_list.m_pItems[v17->m_list.m_uLength];
            if ( v17->m_list.m_pItems != (unsigned int *)v23 )
            {
              do
              {
                if ( *m_pItems == v21 )
                  break;
                ++m_pItems;
              }
              while ( m_pItems != (unsigned int *)v23 );
            }
            v24 = 0i64;
            if ( m_pItems != (unsigned int *)v23 )
              v24 = m_pItems;
            if ( !v24 )
            {
              v25 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&v17->m_list);
              if ( v25 )
              {
                *v25 = v21;
                v10 = AK_Success;
              }
              else
              {
                v10 = AK_Fail;
              }
              v13 = io_rpData;
            }
            if ( v10 != AK_Success )
              return v10;
            if ( ++v20 >= v18 )
            {
              v15 = v43;
              goto LABEL_27;
            }
          }
        }
LABEL_30:
        v26 = *(unsigned int *)v13;
        io_rpData = v13 + 4;
        if ( !(_DWORD)v26 )
          return v10;
        v27 = (CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * v26);
        v28 = v27;
        this->m_listParameters.m_pvMemStart = v27;
        if ( v27 )
        {
          this->m_listParameters.m_ulMinNumListItems = v26;
          this->m_listParameters.m_pFree = v27;
          v29 = 0;
          do
          {
            ++v29;
            v28->pNextListItem = v28 + 1;
            ++v28;
          }
          while ( v29 < this->m_listParameters.m_ulMinNumListItems );
          v28[-1].pNextListItem = 0i64;
        }
        v30 = io_rpData;
        v31 = *((_BYTE *)&v39 + 8);
        while ( 1 )
        {
          v32 = *(_DWORD *)v30;
          io_rpData = v30 + 4;
          v33 = v30[4];
          io_rpData = v30 + 5;
          v34 = v30[5];
          io_rpData = v30 + 6;
          v35 = *(_DWORD *)(v30 + 6);
          io_rpData = v30 + 10;
          v36 = v30 + 14;
          v31 = v31 & 0xE0 | v35 & 7 | (8 * ((v33 != 0) | (2 * (v34 != 0))));
          v37 = *((_DWORD *)v36 - 1);
          io_rpData = v36;
          v39.FadeOutTime = v37;
          v39.FadeInTime = *(_DWORD *)v36;
          *((_BYTE *)&v39 + 8) = v31;
          v40 = v39;
          io_rpData = v36 + 4;
          result = 2
                 - (CAkKeyList<unsigned long,AkSwitchNodeParams,2,ArrayPoolDefault>::Set(
                      &this->m_listParameters,
                      v32,
                      &v40) != 0i64);
          if ( result != 1 )
            break;
          if ( ++v14 >= (unsigned int)v26 )
            break;
          v30 = io_rpData;
        }
      }
    }
  }
  return result;
}

// File Line: 158
// RVA: 0xA89790
AKRESULT __fastcall CAkSwitchCntr::Init(CAkSwitchCntr *this)
{
  AKRESULT result; // eax

  result = CAkMultiPlayNode::Init(this);
  if ( result == AK_Success )
  {
    this->m_SwitchList.m_ulMaxNumListItems = -1;
    this->m_SwitchList.m_ulNumListItems = 0;
    this->m_SwitchList.m_pFree = 0i64;
    this->m_SwitchList.m_pvMemStart = 0i64;
    this->m_SwitchList.m_pFirst = 0i64;
    this->m_SwitchList.m_pLast = 0i64;
    this->m_listParameters.m_ulNumListItems = 0;
    this->m_listParameters.m_pFree = 0i64;
    this->m_listParameters.m_pvMemStart = 0i64;
    this->m_listParameters.m_pFirst = 0i64;
    this->m_listParameters.m_pLast = 0i64;
    this->m_listParameters.m_ulMaxNumListItems = -1;
    this->m_listSwitchContPlayback.m_ulNumListItems = 0;
    this->m_listSwitchContPlayback.m_pFree = 0i64;
    this->m_listSwitchContPlayback.m_pvMemStart = 0i64;
    this->m_listSwitchContPlayback.m_pFirst = 0i64;
    this->m_listSwitchContPlayback.m_pLast = 0i64;
    this->m_listSwitchContPlayback.m_ulMaxNumListItems = -1;
    return 1;
  }
  return result;
}

// File Line: 194
// RVA: 0xA898B0
void __fastcall CAkSwitchCntr::OnPreRelease(CAkSwitchCntr *this)
{
  CAkSwitchCntr::CleanSwitchContPlayback(this);
  CAkParameterNodeBase::FlushStateTransitions(this);
}

// File Line: 206
// RVA: 0xA89450
void __fastcall CAkSwitchCntr::CleanSwitchContPlayback(CAkSwitchCntr *this)
{
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *i; // rbx
  CAkRegisteredObj *GameObject; // rdi
  int v4; // ecx
  int v5; // esi

  if ( this->m_listSwitchContPlayback.m_ulMaxNumListItems )
  {
    for ( i = this->m_listSwitchContPlayback.m_pFirst; i; i = i->pNextListItem )
    {
      CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, i->Item.UserParameters.m_PlayingID);
      ((void (__fastcall *)(CAkSwitchCntr *, __int64))this->CAkMultiPlayNode::CAkContainerBase::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr[9].Category)(
        this,
        3i64);
      GameObject = i->Item.GameObject;
      v4 = *((_DWORD *)GameObject + 30) ^ (*((_DWORD *)GameObject + 30) ^ (*((_DWORD *)GameObject + 30) - 1)) & 0x3FFFFFFF;
      *((_DWORD *)GameObject + 30) = v4;
      if ( (v4 & 0x3FFFFFFF) == 0 )
      {
        v5 = g_DefaultPoolId;
        CAkRegisteredObj::~CAkRegisteredObj(GameObject);
        AK::MemoryMgr::Free(v5, GameObject);
      }
    }
  }
}

// File Line: 219
// RVA: 0xA895B0
void __fastcall CAkSwitchCntr::Create(unsigned int in_ulID)
{
  CAkSwitchCntr *v2; // rax
  CAkSwitchCntr *v3; // rax
  CAkSwitchCntr *v4; // rbx

  v2 = (CAkSwitchCntr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x178ui64);
  if ( v2 )
  {
    CAkSwitchCntr::CAkSwitchCntr(v2, in_ulID);
    v4 = v3;
    if ( v3 )
    {
      if ( CAkSwitchCntr::Init(v3) != AK_Success )
        v4->CAkMultiPlayNode::CAkContainerBase::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr->Release(v4);
    }
  }
}

// File Line: 241
// RVA: 0xA89C70
__int64 __fastcall CAkSwitchCntr::PlayInternal(CAkSwitchCntr *this, AkPBIParams *in_rPBIParams)
{
  bool v4; // bl
  AKRESULT v5; // edi
  unsigned int SwitchToUse; // eax
  int v7; // r12d
  bool v8; // zf
  unsigned int m_ulDefaultSwitch; // esi
  CAkRegisteredObj *pExternalSrcs; // r15
  unsigned int v11; // eax
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *m_pLast; // rcx
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *m_pFree; // rax
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v14; // rcx
  CAkSwitchCntr::SwitchContPlaybackItem *p_Item; // rbx
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rax
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *v17; // rcx
  CAkSwitchPackage *v18; // r15
  unsigned int v19; // eax
  unsigned int key; // r8d
  CAkRegisteredObj *pGameObj; // rdx
  bool v22; // si
  unsigned int *m_pItems; // rbx
  char v24; // r12
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v25; // rax
  unsigned int v26; // edx
  CAkParameterNode *NodePtrAndAddRef; // rax
  CAkParameterNode *v28; // rsi
  AKRESULT v29; // eax
  CAkContinuationList *v30; // rax
  CAkContinuationList *m_pT; // rcx
  AKRESULT v32; // eax
  AKRESULT v33; // eax
  SafeContinuationList in_rSafeContList; // [rsp+20h] [rbp-E0h] BYREF
  int FadeOutTime; // [rsp+28h] [rbp-D8h]
  int FadeInTime; // [rsp+2Ch] [rbp-D4h]
  int v38; // [rsp+30h] [rbp-D0h]
  AkPBIParams __that; // [rsp+40h] [rbp-C0h] BYREF
  AkContParamsAndPath in_rContParams; // [rsp+E0h] [rbp-20h] BYREF
  bool v41; // [rsp+160h] [rbp+60h]
  bool v42; // [rsp+168h] [rbp+68h]
  AkSwitchHistItem v43; // [rsp+170h] [rbp+70h] BYREF
  __int64 v44; // [rsp+178h] [rbp+78h]

  v4 = in_rPBIParams->eType != PBI;
  v5 = AK_Fail;
  v41 = v4;
  SwitchToUse = CAkSwitchAware::GetSwitchToUse(
                  &this->CAkSwitchAware,
                  in_rPBIParams->pGameObj,
                  this->m_ulGroupID,
                  this->m_eGroupType);
  v7 = 0;
  v8 = *((_BYTE *)&this->CAkParameterNodeBase + 83) >= 0;
  v44 = 0i64;
  m_ulDefaultSwitch = SwitchToUse;
  if ( !v8 )
  {
    pExternalSrcs = (CAkRegisteredObj *)in_rPBIParams->userParams.m_CustomParam.pExternalSrcs;
    *(_DWORD *)&__that.playHistory.HistArray.aCntrHist[22] = in_rPBIParams->ePlaybackState;
    __that.userParams.m_CustomParam.customParam = (__int64)in_rPBIParams->pGameObj;
    LODWORD(__that.pTransitionParameters) = in_rPBIParams->userParams.m_PlayingID;
    *(_QWORD *)&__that.eType = in_rPBIParams->userParams.m_CustomParam.customParam;
    LODWORD(__that.pInstigator) = in_rPBIParams->userParams.m_CustomParam.ui32Reserved;
    if ( pExternalSrcs )
      ++LODWORD(pExternalSrcs->m_pListModifiedNodes);
    __that.userParams.m_CustomParam.ui32Reserved = in_rPBIParams->playHistory.HistArray.uiArraySize;
    v11 = *(_DWORD *)in_rPBIParams->playHistory.HistArray.aCntrHist;
    __that.pGameObj = pExternalSrcs;
    *(&__that.userParams.m_CustomParam.ui32Reserved + 1) = v11;
    __that.userParams.m_CustomParam.pExternalSrcs = *(AkExternalSourceArray **)&in_rPBIParams->playHistory.HistArray.aCntrHist[2];
    __that.userParams.m_PlayingID = *(_DWORD *)&in_rPBIParams->playHistory.HistArray.aCntrHist[6];
    *(&__that.userParams.m_PlayingID + 1) = *(_DWORD *)&in_rPBIParams->playHistory.HistArray.aCntrHist[8];
    __that.playHistory.HistArray.uiArraySize = *(_DWORD *)&in_rPBIParams->playHistory.HistArray.aCntrHist[10];
    *(_DWORD *)__that.playHistory.HistArray.aCntrHist = *(_DWORD *)&in_rPBIParams->playHistory.HistArray.aCntrHist[12];
    *(_DWORD *)&__that.playHistory.HistArray.aCntrHist[2] = *(_DWORD *)&in_rPBIParams->playHistory.HistArray.aCntrHist[14];
    *(_DWORD *)&__that.playHistory.HistArray.aCntrHist[4] = *(_DWORD *)&in_rPBIParams->playHistory.HistArray.aCntrHist[16];
    *(_DWORD *)&__that.playHistory.HistArray.aCntrHist[6] = *(_DWORD *)&in_rPBIParams->playHistory.HistArray.aCntrHist[18];
    *(_DWORD *)&__that.playHistory.HistArray.aCntrHist[8] = *(_DWORD *)&in_rPBIParams->playHistory.HistArray.aCntrHist[20];
    *(_DWORD *)&__that.playHistory.HistArray.aCntrHist[10] = *(_DWORD *)&in_rPBIParams->playHistory.HistArray.aCntrHist[22];
    *(_DWORD *)&__that.playHistory.HistArray.aCntrHist[12] = *(_DWORD *)&in_rPBIParams->playHistory.HistArray.aCntrHist[24];
    *(_DWORD *)&__that.playHistory.HistArray.aCntrHist[14] = *(_DWORD *)&in_rPBIParams->playHistory.HistArray.aCntrHist[26];
    *(_DWORD *)&__that.playHistory.HistArray.aCntrHist[16] = *(_DWORD *)&in_rPBIParams->playHistory.HistArray.aCntrHist[28];
    *(_DWORD *)&__that.playHistory.HistArray.aCntrHist[18] = *(_DWORD *)&in_rPBIParams->playHistory.HistArray.aCntrHist[30];
    *(_DWORD *)&__that.playHistory.HistArray.aCntrHist[20] = in_rPBIParams->playHistory.arrayIsContinuous.m_iBitArray;
    if ( !((unsigned __int8 (__fastcall *)(CAkSwitchCntr *, __int64))this->CAkMultiPlayNode::CAkContainerBase::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr[9].Release)(
            this,
            3i64)
      || !CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::CanAddOne(&this->m_listSwitchContPlayback) )
    {
      goto LABEL_11;
    }
    m_pLast = this->m_listSwitchContPlayback.m_pLast;
    m_pFree = this->m_listSwitchContPlayback.m_pFree;
    if ( m_pLast )
      m_pLast->pNextListItem = m_pFree;
    else
      this->m_listSwitchContPlayback.m_pFirst = m_pFree;
    v14 = this->m_listSwitchContPlayback.m_pFree;
    this->m_listSwitchContPlayback.m_pLast = v14;
    this->m_listSwitchContPlayback.m_pFree = v14->pNextListItem;
    v14->pNextListItem = 0i64;
    ++this->m_listSwitchContPlayback.m_ulNumListItems;
    p_Item = &this->m_listSwitchContPlayback.m_pLast->Item;
    CAkSwitchCntr::SwitchContPlaybackItem::operator=(p_Item, (CAkSwitchCntr::SwitchContPlaybackItem *)&__that);
    if ( !p_Item )
    {
      pExternalSrcs = __that.pGameObj;
LABEL_11:
      ((void (__fastcall *)(CAkSwitchCntr *, __int64))this->CAkMultiPlayNode::CAkContainerBase::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr[9].Category)(
        this,
        3i64);
      if ( pExternalSrcs )
        AkExternalSourceArray::Release((AkExternalSourceArray *)pExternalSrcs);
      return (unsigned int)v5;
    }
    *(_DWORD *)(__that.userParams.m_CustomParam.customParam + 120) ^= (*(_DWORD *)(__that.userParams.m_CustomParam.customParam
                                                                                 + 120) ^ (*(_DWORD *)(__that.userParams.m_CustomParam.customParam + 120)
                                                                                         + 1)) & 0x3FFFFFFF;
    CAkPlayingMgr::AddItemActiveCount(g_pPlayingMgr, in_rPBIParams->userParams.m_PlayingID);
    if ( __that.pGameObj )
      AkExternalSourceArray::Release((AkExternalSourceArray *)__that.pGameObj);
    v4 = v41;
  }
  SafeContinuationList::SafeContinuationList(&in_rSafeContList, in_rPBIParams, this);
  m_pFirst = this->m_SwitchList.m_pFirst;
  v17 = m_pFirst;
  if ( !m_pFirst )
    goto LABEL_21;
  while ( v17->Item.key != m_ulDefaultSwitch )
  {
    v17 = v17->pNextListItem;
    if ( !v17 )
      goto LABEL_21;
  }
  v18 = &v17->Item.item;
  if ( v17 == (CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *)-16i64 )
  {
LABEL_21:
    m_ulDefaultSwitch = this->m_ulDefaultSwitch;
    if ( !m_pFirst )
      goto LABEL_24;
    while ( m_pFirst->Item.key != m_ulDefaultSwitch )
    {
      m_pFirst = m_pFirst->pNextListItem;
      if ( !m_pFirst )
        goto LABEL_24;
    }
    v18 = &m_pFirst->Item.item;
    if ( m_pFirst == (CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *)-16i64 )
    {
LABEL_24:
      if ( v4 )
        goto LABEL_79;
      v5 = AK_Success;
      goto LABEL_76;
    }
  }
  CAkRegistryMgr::GetSwitchHistItem(
    g_pRegistryMgr,
    (CAkRegisteredObj *)&v43,
    (__int64)in_rPBIParams->pGameObj,
    this->key);
  if ( v43.LastSwitch == m_ulDefaultSwitch )
  {
    v19 = v43.NumPlayBack + 1;
  }
  else
  {
    v43.LastSwitch = m_ulDefaultSwitch;
    v19 = 1;
  }
  key = this->key;
  pGameObj = in_rPBIParams->pGameObj;
  v43.NumPlayBack = v19;
  v22 = v19 == 1;
  v42 = v19 == 1;
  CAkRegistryMgr::SetSwitchHistItem(g_pRegistryMgr, pGameObj, key, &v43);
  if ( !v4 && !v18->m_list.m_uLength )
  {
    v5 = AK_Success;
    goto LABEL_76;
  }
  m_pItems = v18->m_list.m_pItems;
  if ( v18->m_list.m_pItems == &v18->m_list.m_pItems[v18->m_list.m_uLength] )
    goto LABEL_71;
  v24 = v38;
  do
  {
    AkPBIParams::AkPBIParams(&__that, in_rPBIParams);
    v25 = this->m_listParameters.m_pFirst;
    v26 = *m_pItems;
    if ( !v25 )
      goto LABEL_38;
    while ( v25->Item.key != v26 )
    {
      v25 = v25->pNextListItem;
      if ( !v25 )
        goto LABEL_38;
    }
    if ( v25 == (CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *)-12i64 )
    {
LABEL_38:
      v24 &= 0xE0u;
    }
    else
    {
      FadeOutTime = v25->Item.item.FadeOutTime;
      FadeInTime = v25->Item.item.FadeInTime;
      v38 = *((_DWORD *)&v25->Item.item + 2);
      v24 = v38;
    }
    if ( (v22 || (v24 & 8) == 0) && (!__that.sequenceID || !(_DWORD)v44) )
    {
      NodePtrAndAddRef = (CAkParameterNode *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v26, AkNodeType_Default);
      v28 = NodePtrAndAddRef;
      if ( !NodePtrAndAddRef )
      {
LABEL_66:
        v22 = v42;
        goto LABEL_67;
      }
      if ( !v41 )
      {
        v29 = (unsigned int)CAkParameterNode::HandleInitialDelay(NodePtrAndAddRef, &__that);
        v5 = v29;
        if ( v29 == AK_PartialSuccess )
        {
          v5 = AK_Success;
          goto LABEL_64;
        }
        if ( v29 == AK_Success )
          v5 = ((unsigned int (__fastcall *)(CAkParameterNode *, AkPBIParams *))v28->vfptr[19].Category)(v28, &__that);
LABEL_63:
        if ( v5 != AK_Success )
        {
LABEL_65:
          v28->vfptr->Release(v28);
          goto LABEL_66;
        }
LABEL_64:
        LODWORD(v44) = v44 + 1;
        goto LABEL_65;
      }
      AkContParamsAndPath::AkContParamsAndPath(&in_rContParams, __that.pContinuousParams);
      if ( v18->m_list.m_uLength == 1 )
      {
        CAkMultiPlayNode::ContGetList(
          this,
          __that.pContinuousParams->spContList.m_pT,
          &in_rContParams.m_continuousParams.spContList);
        goto LABEL_57;
      }
      v30 = CAkContinuationList::Create();
      m_pT = in_rContParams.m_continuousParams.spContList.m_pT;
      in_rContParams.m_continuousParams.spContList.m_pT = v30;
      if ( m_pT )
      {
        CAkContinuationList::Release(m_pT);
        v30 = in_rContParams.m_continuousParams.spContList.m_pT;
      }
      if ( v30 )
      {
        v5 = CAkMultiPlayNode::AddMultiplayItem(this, &in_rContParams, &__that, &in_rSafeContList);
        if ( v5 == AK_Success )
        {
LABEL_57:
          __that.pContinuousParams = (ContParams *)&in_rContParams;
          v32 = (unsigned int)CAkParameterNode::HandleInitialDelay(v28, &__that);
          v5 = v32;
          if ( v32 == AK_PartialSuccess )
          {
            v5 = AK_Success;
          }
          else if ( v32 == AK_Success )
          {
            v5 = ((unsigned int (__fastcall *)(CAkParameterNode *, AkPBIParams *))v28->vfptr[19].Category)(v28, &__that);
          }
        }
      }
      else
      {
        v5 = AK_InsufficientMemory;
      }
      AkContParamsAndPath::~AkContParamsAndPath(&in_rContParams);
      goto LABEL_63;
    }
LABEL_67:
    if ( __that.userParams.m_CustomParam.pExternalSrcs )
      AkExternalSourceArray::Release(__that.userParams.m_CustomParam.pExternalSrcs);
    ++m_pItems;
  }
  while ( m_pItems != &v18->m_list.m_pItems[v18->m_list.m_uLength] );
  v7 = v44;
LABEL_71:
  if ( !v41 )
    goto LABEL_76;
  if ( v7 )
    goto LABEL_73;
LABEL_79:
  if ( *((char *)&this->CAkParameterNodeBase + 83) < 0 )
  {
LABEL_73:
    if ( in_rSafeContList.m_spBackupContinuationList.m_pT )
    {
      v33 = CAkMultiPlayNode::ContUnrefList(this, in_rSafeContList.m_spBackupContinuationList.m_pT);
      goto LABEL_75;
    }
  }
  else
  {
    v33 = CAkMultiPlayNode::PlayAndContinueAlternateMultiPlay(this, in_rPBIParams);
LABEL_75:
    v5 = v33;
LABEL_76:
    if ( in_rSafeContList.m_spBackupContinuationList.m_pT )
      CAkContinuationList::Release(in_rSafeContList.m_spBackupContinuationList.m_pT);
  }
  return (unsigned int)v5;
}

// File Line: 403
// RVA: 0xA89610
__int64 __fastcall CAkSwitchCntr::ExecuteAction(CAkSwitchCntr *this, ActionParams *in_rAction)
{
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v5; // rax
  unsigned int v6; // ecx
  CAkRegisteredObj *j; // rdx
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rax
  unsigned int playingID; // ecx
  CAkRegisteredObj *i; // rdx

  switch ( in_rAction->eType )
  {
    case ActionParamType_Stop:
      goto LABEL_5;
    case ActionParamType_Pause:
      m_pFirst = this->m_listSwitchContPlayback.m_pFirst;
      playingID = in_rAction->playingID;
      for ( i = in_rAction->pGameObj; m_pFirst; m_pFirst = m_pFirst->pNextListItem )
      {
        if ( (!i || i == m_pFirst->Item.GameObject)
          && (!playingID || m_pFirst->Item.UserParameters.m_PlayingID == playingID)
          && m_pFirst->Item.ePlaybackState != PB_Paused )
        {
          m_pFirst->Item.ePlaybackState = PB_Paused;
        }
      }
      break;
    case ActionParamType_Resume:
      v5 = this->m_listSwitchContPlayback.m_pFirst;
      v6 = in_rAction->playingID;
      for ( j = in_rAction->pGameObj; v5; v5 = v5->pNextListItem )
      {
        if ( (!j || j == v5->Item.GameObject) && (!v6 || v5->Item.UserParameters.m_PlayingID == v6) )
        {
          if ( v5->Item.ePlaybackState )
            v5->Item.ePlaybackState = PB_Playing;
        }
      }
      break;
    case ActionParamType_Break:
LABEL_5:
      CAkSwitchCntr::StopContSwitchInst(this, in_rAction->pGameObj, in_rAction->playingID);
      break;
  }
  return CAkActiveParent<CAkParameterNode>::ExecuteAction(this, in_rAction);
}

// File Line: 421
// RVA: 0xA896E0
__int64 __fastcall CAkSwitchCntr::ExecuteActionExcept(CAkSwitchCntr *this, ActionParamsExcept *in_rAction)
{
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v4; // rax
  CAkRegisteredObj *j; // r8
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rax
  CAkRegisteredObj *i; // rcx

  if ( in_rAction->eType )
  {
    if ( in_rAction->eType == ActionParamType_Pause )
    {
      m_pFirst = this->m_listSwitchContPlayback.m_pFirst;
      for ( i = in_rAction->pGameObj; m_pFirst; m_pFirst = m_pFirst->pNextListItem )
      {
        if ( (!i || i == m_pFirst->Item.GameObject) && m_pFirst->Item.ePlaybackState != PB_Paused )
          m_pFirst->Item.ePlaybackState = PB_Paused;
      }
    }
    else if ( in_rAction->eType == ActionParamType_Resume )
    {
      v4 = this->m_listSwitchContPlayback.m_pFirst;
      for ( j = in_rAction->pGameObj; v4; v4 = v4->pNextListItem )
      {
        if ( !j || j == v4->Item.GameObject )
        {
          if ( v4->Item.ePlaybackState )
            v4->Item.ePlaybackState = PB_Playing;
        }
      }
    }
  }
  else
  {
    CAkSwitchCntr::StopContSwitchInst(this, in_rAction->pGameObj, 0);
  }
  return CAkActiveParent<CAkParameterNode>::ExecuteActionExcept(this, in_rAction);
}

// File Line: 440
// RVA: 0xA8ABF0
void __fastcall CAkSwitchCntr::StopContSwitchInst(
        CAkSwitchCntr *this,
        CAkRegisteredObj *in_pGameObj,
        unsigned int in_PlayingID)
{
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v4; // rax
  char v5; // cl
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rdi
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rcx
  CAkRegisteredObj *GameObject; // rsi
  int v11; // ecx
  int v12; // edi
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v13; // [rsp+20h] [rbp-28h]
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v14; // [rsp+28h] [rbp-20h]

  v4 = 0i64;
  v5 = 0;
  m_pFirst = this->m_listSwitchContPlayback.m_pFirst;
  if ( m_pFirst )
  {
    do
    {
      if ( (!in_pGameObj || in_pGameObj == m_pFirst->Item.GameObject)
        && (!in_PlayingID || m_pFirst->Item.UserParameters.m_PlayingID == in_PlayingID) )
      {
        pNextListItem = m_pFirst->pNextListItem;
        v14 = v4;
        v13 = m_pFirst->pNextListItem;
        if ( m_pFirst == this->m_listSwitchContPlayback.m_pFirst )
          this->m_listSwitchContPlayback.m_pFirst = pNextListItem;
        else
          v4->pNextListItem = pNextListItem;
        if ( m_pFirst == this->m_listSwitchContPlayback.m_pLast )
          this->m_listSwitchContPlayback.m_pLast = v4;
        m_pFirst->pNextListItem = this->m_listSwitchContPlayback.m_pFree;
        --this->m_listSwitchContPlayback.m_ulNumListItems;
        this->m_listSwitchContPlayback.m_pFree = m_pFirst;
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, m_pFirst->Item.UserParameters.m_PlayingID);
        ((void (__fastcall *)(CAkSwitchCntr *, __int64))this->CAkMultiPlayNode::CAkContainerBase::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr[9].Category)(
          this,
          3i64);
        GameObject = m_pFirst->Item.GameObject;
        v11 = *((_DWORD *)GameObject + 30) ^ (*((_DWORD *)GameObject + 30) ^ (*((_DWORD *)GameObject + 30) - 1)) & 0x3FFFFFFF;
        *((_DWORD *)GameObject + 30) = v11;
        if ( (v11 & 0x3FFFFFFF) == 0 )
        {
          v12 = g_DefaultPoolId;
          CAkRegisteredObj::~CAkRegisteredObj(GameObject);
          AK::MemoryMgr::Free(v12, GameObject);
        }
        v4 = v14;
        m_pFirst = v13;
        v5 = 1;
      }
      else
      {
        v4 = m_pFirst;
        m_pFirst = m_pFirst->pNextListItem;
      }
    }
    while ( m_pFirst );
    if ( v5 )
      CAkRegistryMgr::ClearSwitchHist(g_pRegistryMgr, this->key, in_pGameObj);
  }
}

// File Line: 537
// RVA: 0xA8A540
void __fastcall CAkSwitchCntr::RemoveChild(CAkSwitchCntr *this, CAkParameterNodeBase *in_pChild)
{
  unsigned int key; // edi
  char v3; // r9
  CAkParameterNodeBase *v4; // r8
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rcx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v7; // rdx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v8; // rax
  bool v9; // zf
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *pNextListItem; // rcx

  key = in_pChild->key;
  v3 = 0;
  v4 = in_pChild;
  if ( in_pChild->m_pParentNode == this )
  {
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD))in_pChild->vfptr[1].Release)(in_pChild, 0i64);
    AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Unset<unsigned long>(
      &this->m_mapChildId,
      key);
    v3 = 1;
  }
  m_pFirst = this->m_listParameters.m_pFirst;
  v7 = 0i64;
  v8 = m_pFirst;
  if ( m_pFirst )
  {
    while ( v8->Item.key != key )
    {
      v7 = v8;
      v8 = v8->pNextListItem;
      if ( !v8 )
        goto LABEL_13;
    }
    v9 = v8 == m_pFirst;
    pNextListItem = v8->pNextListItem;
    if ( v9 )
      this->m_listParameters.m_pFirst = pNextListItem;
    else
      v7->pNextListItem = pNextListItem;
    if ( v8 == this->m_listParameters.m_pLast )
      this->m_listParameters.m_pLast = v7;
    v8->pNextListItem = this->m_listParameters.m_pFree;
    --this->m_listParameters.m_ulNumListItems;
    this->m_listParameters.m_pFree = v8;
  }
LABEL_13:
  if ( v3 )
    ((void (__fastcall *)(CAkSwitchCntr *, CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *, CAkParameterNodeBase *))this->CAkMultiPlayNode::CAkContainerBase::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr->Release)(
      this,
      v7,
      v4);
}

// File Line: 561
// RVA: 0xA8ABD0
void __fastcall CAkSwitchCntr::SetSwitch(CAkSwitchCntr *this, unsigned int in_Switch, CAkRegisteredObj *in_GameObj)
{
  if ( SBYTE3(this[-1].m_SwitchList.m_pvMemStart) < 0 )
    CAkSwitchCntr::PerformSwitchChange((CAkSwitchCntr *)((char *)this - 184), in_Switch, in_GameObj);
}

// File Line: 569
// RVA: 0xA8A4B0
__int64 __fastcall CAkSwitchCntr::PrepareNodeList(
        CAkSwitchCntr *this,
        AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *in_rNodeList)
{
  unsigned int *m_pItems; // rdi
  unsigned int v4; // ebp
  unsigned int *i; // rbx

  m_pItems = in_rNodeList->m_pItems;
  if ( in_rNodeList->m_pItems == &in_rNodeList->m_pItems[in_rNodeList->m_uLength] )
    return 1i64;
  do
  {
    v4 = CAkParameterNodeBase::PrepareNodeData(*m_pItems);
    if ( v4 != 1 )
    {
      for ( i = in_rNodeList->m_pItems; i != m_pItems; ++i )
        CAkParameterNodeBase::UnPrepareNodeData(*i);
    }
    ++m_pItems;
  }
  while ( m_pItems != &in_rNodeList->m_pItems[in_rNodeList->m_uLength] );
  return v4;
}

// File Line: 588
// RVA: 0xA8B290
void __fastcall CAkSwitchCntr::UnPrepareNodeList(
        CAkSwitchCntr *this,
        AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *in_rNodeList)
{
  unsigned int *i; // rbx

  for ( i = in_rNodeList->m_pItems; i != &in_rNodeList->m_pItems[in_rNodeList->m_uLength]; ++i )
    CAkParameterNodeBase::UnPrepareNodeData(*i);
}

// File Line: 596
// RVA: 0xA89850
AKRESULT __fastcall CAkSwitchCntr::ModifyActiveState(CAkSwitchCntr *this, unsigned int in_stateID, bool in_bSupported)
{
  CAkParameterNodeBase::FXChunk *m_pFXChunk; // r9
  CAkSwitchCntr *v5; // rcx
  AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v6; // rdx

  if ( this->key )
  {
    m_pFXChunk = this->m_pFXChunk;
    if ( m_pFXChunk )
    {
      while ( *(_DWORD *)&m_pFXChunk->aFX[1].bRendered != in_stateID )
      {
        m_pFXChunk = (CAkParameterNodeBase::FXChunk *)m_pFXChunk->aFX[0];
        if ( !m_pFXChunk )
          return 1;
      }
      v5 = (CAkSwitchCntr *)((char *)this - 192);
      v6 = (AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)&m_pFXChunk->aFX[2];
      if ( in_bSupported )
        return CAkSwitchCntr::PrepareNodeList(v5, v6);
      CAkSwitchCntr::UnPrepareNodeList(v5, v6);
    }
  }
  return 1;
}

// File Line: 628
// RVA: 0xA8A2F0
__int64 __fastcall CAkSwitchCntr::PrepareData(CAkSwitchCntr *this)
{
  unsigned int m_uPreparationCount; // eax
  AKRESULT v4; // ebp
  CAkPreparedContent *PreparedContent; // r15
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rsi
  unsigned int *m_pItems; // rcx
  __int64 v8; // rax
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *i; // rdi
  unsigned int *v10; // rcx
  __int64 v11; // rax
  unsigned int *v12; // rbx
  AkGroupType m_eGroupType; // r8d
  unsigned int m_ulGroupID; // edx

  if ( !g_settings.bEnableGameSyncPreparation )
    return CAkActiveParent<CAkParameterNode>::PrepareData(this);
  m_uPreparationCount = this->m_uPreparationCount;
  v4 = AK_Success;
  if ( m_uPreparationCount )
  {
    this->m_uPreparationCount = m_uPreparationCount + 1;
  }
  else
  {
    PreparedContent = CAkPreparationAware::GetPreparedContent(
                        &this->CAkPreparationAware,
                        this->m_ulGroupID,
                        this->m_eGroupType);
    if ( PreparedContent )
    {
      m_pFirst = this->m_SwitchList.m_pFirst;
      if ( !m_pFirst )
        goto LABEL_22;
      do
      {
        m_pItems = PreparedContent->m_PreparableContentList.m_pItems;
        v8 = (__int64)&PreparedContent->m_PreparableContentList.m_pItems[PreparedContent->m_PreparableContentList.m_uLength];
        if ( PreparedContent->m_PreparableContentList.m_pItems != (unsigned int *)v8 )
        {
          do
          {
            if ( *m_pItems == m_pFirst->Item.key )
              break;
            ++m_pItems;
          }
          while ( m_pItems != (unsigned int *)v8 );
          if ( m_pItems != (unsigned int *)v8 )
            v4 = CAkSwitchCntr::PrepareNodeList(this, &m_pFirst->Item.item.m_list);
        }
        if ( v4 != AK_Success )
        {
          for ( i = this->m_SwitchList.m_pFirst; i != m_pFirst; i = i->pNextListItem )
          {
            v10 = PreparedContent->m_PreparableContentList.m_pItems;
            v11 = (__int64)&PreparedContent->m_PreparableContentList.m_pItems[PreparedContent->m_PreparableContentList.m_uLength];
            if ( PreparedContent->m_PreparableContentList.m_pItems != (unsigned int *)v11 )
            {
              do
              {
                if ( *v10 == i->Item.key )
                  break;
                ++v10;
              }
              while ( v10 != (unsigned int *)v11 );
              if ( v10 != (unsigned int *)v11 )
              {
                v12 = i->Item.item.m_list.m_pItems;
                if ( v12 != &v12[i->Item.item.m_list.m_uLength] )
                {
                  do
                    CAkParameterNodeBase::UnPrepareNodeData(*v12++);
                  while ( v12 != &i->Item.item.m_list.m_pItems[i->Item.item.m_list.m_uLength] );
                }
              }
            }
          }
        }
        m_pFirst = m_pFirst->pNextListItem;
      }
      while ( m_pFirst );
      if ( v4 == AK_Success )
      {
LABEL_22:
        m_eGroupType = this->m_eGroupType;
        m_ulGroupID = this->m_ulGroupID;
        ++this->m_uPreparationCount;
        v4 = CAkPreparationAware::SubscribePrepare(&this->CAkPreparationAware, m_ulGroupID, m_eGroupType);
        if ( v4 != AK_Success )
          this->CAkMultiPlayNode::CAkContainerBase::CAkActiveParent<CAkParameterNode>::CAkParentNode<CAkParameterNode>::CAkParameterNode::CAkParameterNodeBase::CAkPBIAware::CAkIndexable::vfptr[10].AddRef(this);
      }
    }
    else
    {
      return 52;
    }
  }
  return (unsigned int)v4;
}

// File Line: 681
// RVA: 0xA8B140
void __fastcall CAkSwitchCntr::UnPrepareData(CAkSwitchCntr *this)
{
  CAkParameterNodeBase **v2; // rbx
  unsigned int m_uPreparationCount; // eax
  unsigned int v4; // eax
  CAkPreparedContent *PreparedContent; // r14
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *i; // rdi
  unsigned int *m_pItems; // rcx
  __int64 v8; // rax
  unsigned int *v9; // rbx

  if ( g_settings.bEnableGameSyncPreparation )
  {
    m_uPreparationCount = this->m_uPreparationCount;
    if ( m_uPreparationCount )
    {
      v4 = m_uPreparationCount - 1;
      this->m_uPreparationCount = v4;
      if ( !v4 )
      {
        PreparedContent = CAkPreparationAware::GetPreparedContent(
                            &this->CAkPreparationAware,
                            this->m_ulGroupID,
                            this->m_eGroupType);
        if ( PreparedContent )
        {
          for ( i = this->m_SwitchList.m_pFirst; i; i = i->pNextListItem )
          {
            m_pItems = PreparedContent->m_PreparableContentList.m_pItems;
            v8 = (__int64)&PreparedContent->m_PreparableContentList.m_pItems[PreparedContent->m_PreparableContentList.m_uLength];
            if ( PreparedContent->m_PreparableContentList.m_pItems != (unsigned int *)v8 )
            {
              do
              {
                if ( *m_pItems == i->Item.key )
                  break;
                ++m_pItems;
              }
              while ( m_pItems != (unsigned int *)v8 );
              if ( m_pItems != (unsigned int *)v8 )
              {
                v9 = i->Item.item.m_list.m_pItems;
                if ( v9 != &v9[i->Item.item.m_list.m_uLength] )
                {
                  do
                    CAkParameterNodeBase::UnPrepareNodeData(*v9++);
                  while ( v9 != &i->Item.item.m_list.m_pItems[i->Item.item.m_list.m_uLength] );
                }
              }
            }
          }
        }
        CAkPreparationAware::UnsubscribePrepare(&this->CAkPreparationAware, this->m_ulGroupID, this->m_eGroupType);
      }
    }
  }
  else
  {
    v2 = this->m_mapChildId.m_pItems;
    if ( v2 != &v2[this->m_mapChildId.m_uLength] )
    {
      do
      {
        (*v2)->vfptr[10].AddRef(*v2);
        ++v2;
      }
      while ( v2 != &this->m_mapChildId.m_pItems[this->m_mapChildId.m_uLength] );
    }
  }
}

// File Line: 749
// RVA: 0xA898D0
__int64 __fastcall CAkSwitchCntr::PerformSwitchChange(
        CAkSwitchCntr *this,
        unsigned int in_SwitchTo,
        CAkRegisteredObj *in_GameObj)
{
  __int64 m_ulNumListItems; // rsi
  CAkRegisteredObj **v6; // r14
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rax
  __int64 i; // r8
  CAkRegisteredObj **v9; // rbx

  if ( in_GameObj )
  {
    CAkSwitchCntr::PerformSwitchChangeContPerObject(this, in_SwitchTo, in_GameObj);
    return 1i64;
  }
  else
  {
    m_ulNumListItems = this->m_listSwitchContPlayback.m_ulNumListItems;
    if ( (_DWORD)m_ulNumListItems )
    {
      v6 = (CAkRegisteredObj **)AK::MemoryMgr::Malloc(g_DefaultPoolId, (unsigned int)(8 * m_ulNumListItems));
      if ( v6 )
      {
        m_pFirst = this->m_listSwitchContPlayback.m_pFirst;
        for ( i = 0i64; m_pFirst; i = (unsigned int)(i + 1) )
        {
          v6[i] = m_pFirst->Item.GameObject;
          m_pFirst = m_pFirst->pNextListItem;
        }
        v9 = v6;
        do
        {
          CAkSwitchCntr::PerformSwitchChangeContPerObject(this, in_SwitchTo, *v9++);
          --m_ulNumListItems;
        }
        while ( m_ulNumListItems );
        AK::MemoryMgr::Free(g_DefaultPoolId, v6);
        return 1i64;
      }
      else
      {
        return 2i64;
      }
    }
    else
    {
      CAkRegistryMgr::ClearSwitchHist(g_pRegistryMgr, this->key, 0i64);
      return 1i64;
    }
  }
}

// File Line: 796
// RVA: 0xA899E0
__int64 __fastcall CAkSwitchCntr::PerformSwitchChangeContPerObject(
        CAkSwitchCntr *this,
        unsigned int in_SwitchTo,
        CAkRegisteredObj *in_GameObj)
{
  unsigned int m_ulDefaultSwitch; // ebx
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rax
  unsigned int NumPlayBack; // esi
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *v8; // rcx
  CAkSwitchPackage *p_item; // r15
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *v10; // rcx
  CAkSwitchPackage *v11; // r14
  AKRESULT v12; // ebp
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v13; // rdi
  unsigned int LastSwitch; // edx
  char v15; // bp
  CAkRegisteredObj *v16; // rax
  unsigned int *m_pItems; // rbx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v18; // rax
  unsigned int v19; // edx
  unsigned int *v20; // rax
  __int64 v21; // r8
  char v23; // [rsp+28h] [rbp-50h]
  AKRESULT v24; // [rsp+80h] [rbp+8h]
  unsigned int v25; // [rsp+88h] [rbp+10h]
  AkSwitchHistItem v27; // [rsp+98h] [rbp+20h] BYREF

  v25 = in_SwitchTo;
  m_ulDefaultSwitch = in_SwitchTo;
  CAkRegistryMgr::GetSwitchHistItem(g_pRegistryMgr, (CAkRegisteredObj *)&v27, (__int64)in_GameObj, this->key);
  if ( m_ulDefaultSwitch == v27.LastSwitch )
    return 1i64;
  m_pFirst = this->m_SwitchList.m_pFirst;
  NumPlayBack = 0;
  v8 = m_pFirst;
  if ( m_pFirst )
  {
    while ( v8->Item.key != v27.LastSwitch )
    {
      v8 = v8->pNextListItem;
      if ( !v8 )
        goto LABEL_5;
    }
    p_item = &v8->Item.item;
  }
  else
  {
LABEL_5:
    p_item = 0i64;
  }
  v10 = this->m_SwitchList.m_pFirst;
  if ( !m_pFirst )
    goto LABEL_12;
  while ( v10->Item.key != m_ulDefaultSwitch )
  {
    v10 = v10->pNextListItem;
    if ( !v10 )
      goto LABEL_12;
  }
  v11 = &v10->Item.item;
  if ( v10 == (CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *)-16i64 )
  {
LABEL_12:
    m_ulDefaultSwitch = this->m_ulDefaultSwitch;
    v25 = m_ulDefaultSwitch;
    if ( m_pFirst )
    {
      while ( m_pFirst->Item.key != m_ulDefaultSwitch )
      {
        m_pFirst = m_pFirst->pNextListItem;
        if ( !m_pFirst )
          goto LABEL_15;
      }
      v11 = &m_pFirst->Item.item;
    }
    else
    {
LABEL_15:
      v11 = 0i64;
    }
  }
  v12 = CAkSwitchCntr::StopPrevious(this, p_item, v11, in_GameObj);
  v24 = v12;
  CAkRegistryMgr::ClearSwitchHist(g_pRegistryMgr, this->key, in_GameObj);
  v13 = this->m_listSwitchContPlayback.m_pFirst;
  LastSwitch = 0;
  v27 = 0i64;
  if ( v13 )
  {
    v15 = v23;
    v16 = in_GameObj;
    do
    {
      if ( v13->Item.GameObject == v16 )
      {
        if ( LastSwitch == m_ulDefaultSwitch )
        {
          ++NumPlayBack;
        }
        else
        {
          LastSwitch = m_ulDefaultSwitch;
          v27.LastSwitch = m_ulDefaultSwitch;
          NumPlayBack = 1;
        }
        v27.NumPlayBack = NumPlayBack;
        if ( v11 )
        {
          m_pItems = v11->m_list.m_pItems;
          if ( v11->m_list.m_pItems != &v11->m_list.m_pItems[v11->m_list.m_uLength] )
          {
            do
            {
              v18 = this->m_listParameters.m_pFirst;
              v19 = *m_pItems;
              if ( !v18 )
                goto LABEL_28;
              while ( v18->Item.key != v19 )
              {
                v18 = v18->pNextListItem;
                if ( !v18 )
                  goto LABEL_28;
              }
              if ( v18 == (CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *)-12i64 )
LABEL_28:
                v15 &= 0xE0u;
              else
                v15 = *((_DWORD *)&v18->Item.item + 2);
              if ( (v15 & 0x10) != 0
                && p_item
                && (v20 = p_item->m_list.m_pItems,
                    v21 = (__int64)&p_item->m_list.m_pItems[p_item->m_list.m_uLength],
                    p_item->m_list.m_pItems != (unsigned int *)v21) )
              {
                while ( *v20 != v19 )
                {
                  if ( ++v20 == (unsigned int *)v21 )
                    goto LABEL_34;
                }
              }
              else
              {
LABEL_34:
                v24 = CAkSwitchCntr::PlayOnSwitch(this, v19, &v13->Item);
              }
              ++m_pItems;
            }
            while ( m_pItems != &v11->m_list.m_pItems[v11->m_list.m_uLength] );
            NumPlayBack = v27.NumPlayBack;
            LastSwitch = v27.LastSwitch;
          }
          v16 = in_GameObj;
        }
      }
      v13 = v13->pNextListItem;
      m_ulDefaultSwitch = v25;
    }
    while ( v13 );
    v12 = v24;
  }
  CAkRegistryMgr::SetSwitchHistItem(g_pRegistryMgr, in_GameObj, this->key, &v27);
  return (unsigned int)v12;
}

// File Line: 861
// RVA: 0xA8A180
__int64 __fastcall CAkSwitchCntr::PlayOnSwitch(
        CAkSwitchCntr *this,
        unsigned int in_ID,
        CAkSwitchCntr::SwitchContPlaybackItem *in_rContItem)
{
  CAkParameterNode *NodePtrAndAddRef; // rdi
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rcx
  int FadeInTime; // eax
  __int128 v9; // xmm0
  __int128 v10; // xmm1
  CAkRegisteredObj *GameObject; // rax
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  __int64 customParam; // rax
  AkExternalSourceArray *pExternalSrcs; // rax
  AkPlaybackState ePlaybackState; // eax
  unsigned int v17; // eax
  unsigned int v18; // ebx
  AkSwitchNodeParams *p_item; // rcx
  AkPBIParams in_rPBIParams; // [rsp+20h] [rbp-59h] BYREF
  int v22; // [rsp+F8h] [rbp+7Fh] BYREF
  int v23; // [rsp+FCh] [rbp+83h]

  NodePtrAndAddRef = (CAkParameterNode *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_ID, AkNodeType_Default);
  if ( !NodePtrAndAddRef )
    return 2i64;
  m_pFirst = this->m_listParameters.m_pFirst;
  v23 = 4;
  if ( !m_pFirst )
    goto LABEL_5;
  while ( m_pFirst->Item.key != in_ID )
  {
    m_pFirst = m_pFirst->pNextListItem;
    if ( !m_pFirst )
      goto LABEL_5;
  }
  p_item = &m_pFirst->Item.item;
  if ( p_item )
    FadeInTime = p_item->FadeInTime;
  else
LABEL_5:
    FadeInTime = 0;
  v9 = *(_OWORD *)&in_rContItem->PlayHist.HistArray.uiArraySize;
  v10 = *(_OWORD *)&in_rContItem->PlayHist.HistArray.aCntrHist[6];
  v22 = FadeInTime;
  GameObject = in_rContItem->GameObject;
  in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = 0i64;
  *(_WORD *)&in_rPBIParams.bIsFirst = 1;
  in_rPBIParams.pGameObj = GameObject;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.uiArraySize = v9;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[6] = v10;
  v12 = *(_OWORD *)&in_rContItem->PlayHist.HistArray.aCntrHist[14];
  v13 = *(_OWORD *)&in_rContItem->PlayHist.HistArray.aCntrHist[22];
  in_rPBIParams.pTransitionParameters = (TransParams *)&v22;
  LODWORD(GameObject) = in_rContItem->UserParameters.m_PlayingID;
  in_rPBIParams.bTargetFeedback = 0;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[14] = v12;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[22] = v13;
  *(_QWORD *)&v12 = *(_QWORD *)&in_rContItem->PlayHist.HistArray.aCntrHist[30];
  in_rPBIParams.userParams.m_PlayingID = (unsigned int)GameObject;
  customParam = in_rContItem->UserParameters.m_CustomParam.customParam;
  in_rPBIParams.eType = PBI;
  *(_QWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[30] = v12;
  in_rPBIParams.userParams.m_CustomParam.customParam = customParam;
  LODWORD(customParam) = in_rContItem->UserParameters.m_CustomParam.ui32Reserved;
  in_rPBIParams.pInstigator = NodePtrAndAddRef;
  in_rPBIParams.userParams.m_CustomParam.ui32Reserved = customParam;
  pExternalSrcs = in_rContItem->UserParameters.m_CustomParam.pExternalSrcs;
  if ( pExternalSrcs )
    ++pExternalSrcs->m_cRefCount;
  in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = pExternalSrcs;
  ePlaybackState = in_rContItem->ePlaybackState;
  in_rPBIParams.uFrameOffset = 0;
  in_rPBIParams.pContinuousParams = 0i64;
  in_rPBIParams.sequenceID = 0;
  in_rPBIParams.ePlaybackState = ePlaybackState;
  v17 = CAkParameterNode::HandleInitialDelay(NodePtrAndAddRef, &in_rPBIParams);
  v18 = v17;
  if ( v17 == 3 )
  {
    v18 = 1;
  }
  else if ( v17 == 1 )
  {
    v18 = ((__int64 (__fastcall *)(CAkParameterNode *, AkPBIParams *))NodePtrAndAddRef->vfptr[19].Category)(
            NodePtrAndAddRef,
            &in_rPBIParams);
  }
  NodePtrAndAddRef->vfptr->Release(NodePtrAndAddRef);
  if ( in_rPBIParams.userParams.m_CustomParam.pExternalSrcs )
    AkExternalSourceArray::Release(in_rPBIParams.userParams.m_CustomParam.pExternalSrcs);
  return v18;
}

// File Line: 904
// RVA: 0xA8AD40
__int64 __fastcall CAkSwitchCntr::StopOnSwitch(
        CAkSwitchCntr *this,
        unsigned int in_ID,
        AkSwitchNodeParams *in_rSwitchNodeParams,
        CAkRegisteredObj *in_GameObj)
{
  unsigned int v7; // edi
  CAkParameterNodeBase *NodePtrAndAddRef; // rax
  CAkParameterNodeBase *v9; // rbx
  CAkIndexableVtbl *vfptr; // rax
  int v12; // [rsp+20h] [rbp-38h] BYREF
  CAkRegisteredObj *v13; // [rsp+28h] [rbp-30h]
  int v14; // [rsp+30h] [rbp-28h]
  int FadeOutTime; // [rsp+34h] [rbp-24h]
  int v16; // [rsp+38h] [rbp-20h]
  __int16 v17; // [rsp+3Ch] [rbp-1Ch]
  char v18; // [rsp+3Eh] [rbp-1Ah]

  v7 = 1;
  NodePtrAndAddRef = CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_ID, AkNodeType_Default);
  v9 = NodePtrAndAddRef;
  if ( NodePtrAndAddRef )
  {
    CAkAudioMgr::StopPendingAction(g_pAudioMgr, NodePtrAndAddRef, in_GameObj, 0);
    if ( (*((_BYTE *)in_rSwitchNodeParams + 8) & 7) == 1 )
    {
      v17 = 0;
      v12 = 0;
      v14 = 0;
      FadeOutTime = in_rSwitchNodeParams->FadeOutTime;
      vfptr = v9->vfptr;
      v18 = 0;
      v16 = 4;
      v13 = in_GameObj;
      v7 = (unsigned int)vfptr[4].__vecDelDtor(v9, (unsigned int)&v12);
    }
    else
    {
      ((void (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, CAkSwitchCntr *, _QWORD))v9->vfptr[4].Category)(
        v9,
        in_GameObj,
        this,
        0i64);
    }
    v9->vfptr->Release(v9);
  }
  return v7;
}

// File Line: 940
// RVA: 0xA8AE20
__int64 __fastcall CAkSwitchCntr::StopPrevious(
        CAkSwitchCntr *this,
        CAkSwitchPackage *in_pPreviousSwitchPack,
        CAkSwitchPackage *in_pNextSwitchPack,
        CAkRegisteredObj *in_GameObj)
{
  unsigned int v8; // r11d
  unsigned int *m_pItems; // rbx
  char v10; // di
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rax
  unsigned int v12; // edx
  unsigned int *v13; // rax
  unsigned int *v14; // r8
  __int64 result; // rax
  AkSwitchNodeParams in_rSwitchNodeParams; // [rsp+20h] [rbp-28h] BYREF

  v8 = 1;
  if ( !in_pPreviousSwitchPack )
    return 1i64;
  m_pItems = in_pPreviousSwitchPack->m_list.m_pItems;
  if ( in_pPreviousSwitchPack->m_list.m_pItems == &in_pPreviousSwitchPack->m_list.m_pItems[in_pPreviousSwitchPack->m_list.m_uLength] )
    return 1i64;
  v10 = *((_BYTE *)&in_rSwitchNodeParams + 8);
  do
  {
    m_pFirst = this->m_listParameters.m_pFirst;
    v12 = *m_pItems;
    if ( !m_pFirst )
      goto LABEL_7;
    while ( m_pFirst->Item.key != v12 )
    {
      m_pFirst = m_pFirst->pNextListItem;
      if ( !m_pFirst )
        goto LABEL_7;
    }
    if ( m_pFirst == (CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *)-12i64 )
    {
LABEL_7:
      v10 &= 0xE0u;
      *(_QWORD *)&in_rSwitchNodeParams.FadeOutTime = 0i64;
      *((_BYTE *)&in_rSwitchNodeParams + 8) = v10;
    }
    else
    {
      in_rSwitchNodeParams = m_pFirst->Item.item;
      v10 = *((_BYTE *)&in_rSwitchNodeParams + 8);
    }
    if ( *((char *)&this->CAkParameterNodeBase + 83) < 0
      && (v10 & 0x10) != 0
      && in_pNextSwitchPack
      && (v13 = in_pNextSwitchPack->m_list.m_pItems,
          v14 = &in_pNextSwitchPack->m_list.m_pItems[in_pNextSwitchPack->m_list.m_uLength],
          in_pNextSwitchPack->m_list.m_pItems != v14) )
    {
      while ( *v13 != v12 )
      {
        if ( ++v13 == v14 )
          goto LABEL_14;
      }
    }
    else
    {
LABEL_14:
      result = CAkSwitchCntr::StopOnSwitch(this, v12, &in_rSwitchNodeParams, in_GameObj);
      v8 = result;
      if ( (_DWORD)result != 1 )
        return result;
    }
    ++m_pItems;
  }
  while ( m_pItems != &in_pPreviousSwitchPack->m_list.m_pItems[in_pPreviousSwitchPack->m_list.m_uLength] );
  return v8;
}

// File Line: 971
// RVA: 0xA89500
void __fastcall CAkSwitchCntr::ClearSwitches(CAkSwitchCntr *this)
{
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *i; // rbx
  unsigned int *m_pItems; // rdx
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *m_pFirst; // rcx

  if ( this->m_SwitchList.m_ulMaxNumListItems )
  {
    for ( i = this->m_SwitchList.m_pFirst; i; i = i->pNextListItem )
    {
      m_pItems = i->Item.item.m_list.m_pItems;
      if ( m_pItems )
      {
        i->Item.item.m_list.m_uLength = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
        i->Item.item.m_list.m_pItems = 0i64;
        i->Item.item.m_list.m_ulReserved = 0;
      }
    }
    while ( 1 )
    {
      m_pFirst = this->m_SwitchList.m_pFirst;
      if ( !m_pFirst )
        break;
      this->m_SwitchList.m_pFirst = m_pFirst->pNextListItem;
      if ( m_pFirst == this->m_SwitchList.m_pLast )
        this->m_SwitchList.m_pLast = 0i64;
      m_pFirst->pNextListItem = this->m_SwitchList.m_pFree;
      --this->m_SwitchList.m_ulNumListItems;
      this->m_SwitchList.m_pFree = m_pFirst;
    }
  }
}

// File Line: 1309
// RVA: 0xA89840
__int64 __fastcall CAkSwitchCntr::IsContinuousPlayback(CAkSwitchCntr *this)
{
  return *((_BYTE *)&this->CAkParameterNodeBase + 83) >> 7;
}

