// File Line: 45
// RVA: 0xA890F0
void __fastcall CAkSwitchCntr::CAkSwitchCntr(CAkSwitchCntr *this, unsigned int in_ulID)
{
  CAkSwitchCntr *v2; // rdi

  v2 = this;
  CAkMultiPlayNode::CAkMultiPlayNode((CAkMultiPlayNode *)&this->vfptr, in_ulID);
  CAkSwitchAware::CAkSwitchAware((CAkSwitchAware *)&v2->vfptr);
  v2->pNextItemPrepare = 0i64;
  v2->m_uPreparationCount = 0;
  *(_QWORD *)&v2->m_eGroupType = 0i64;
  v2->m_ulDefaultSwitch = 0;
  v2->vfptr = (CAkIndexableVtbl *)&CAkSwitchCntr::`vftable'{for `CAkMultiPlayNode'};
  v2->vfptr = (CAkSwitchAwareVtbl *)&CAkSwitchCntr::`vftable'{for `CAkSwitchAware'};
  v2->vfptr = (CAkPreparationAwareVtbl *)&CAkSwitchCntr::`vftable'{for `CAkPreparationAware'};
  *(_QWORD *)&v2->m_SwitchList.m_ulMinNumListItems = 0i64;
  v2->m_SwitchList.m_ulNumListItems = 0;
  *(_QWORD *)&v2->m_listParameters.m_ulMinNumListItems = 0i64;
  v2->m_listParameters.m_ulNumListItems = 0;
  *(_QWORD *)&v2->m_listSwitchContPlayback.m_ulMinNumListItems = 0i64;
  v2->m_listSwitchContPlayback.m_ulNumListItems = 0;
}

// File Line: 50
// RVA: 0xA89190
void __fastcall CAkSwitchCntr::~CAkSwitchCntr(CAkSwitchCntr *this)
{
  CAkSwitchCntr *v1; // rdi
  CAkSwitchAware *v2; // rcx

  v1 = this;
  v2 = (CAkSwitchAware *)&this->vfptr;
  v2[-23].vfptr = (CAkSwitchAwareVtbl *)&CAkSwitchCntr::`vftable'{for `CAkMultiPlayNode'};
  v2->vfptr = (CAkSwitchAwareVtbl *)&CAkSwitchCntr::`vftable'{for `CAkSwitchAware'};
  v2[1].vfptr = (CAkSwitchAwareVtbl *)&CAkSwitchCntr::`vftable'{for `CAkPreparationAware'};
  CAkSwitchAware::UnsubscribeSwitches(v2);
  CAkSwitchCntr::ClearSwitches(v1);
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::Term(&v1->m_listSwitchContPlayback);
  CAkList2<CAkRTPCMgr::AkSwitchSubscription,CAkRTPCMgr::AkSwitchSubscription const &,2,ArrayPoolDefault>::Term((CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault> *)&v1->m_listParameters.m_pFirst);
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::Term((CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault> *)&v1->m_SwitchList.m_pFirst);
  CAkMultiPlayNode::Term((CAkMultiPlayNode *)&v1->vfptr);
  CAkSwitchAware::~CAkSwitchAware((CAkSwitchAware *)&v1->vfptr);
  CAkMultiPlayNode::~CAkMultiPlayNode((CAkMultiPlayNode *)&v1->vfptr);
}

// File Line: 55
// RVA: 0xA8A850
int __fastcall CAkSwitchCntr::SetInitialValues(CAkSwitchCntr *this, char *in_pData, unsigned int in_ulDataSize)
{
  CAkSwitchCntr *v3; // r13
  int result; // eax
  AkGroupType v5; // er8
  char *v6; // rax
  unsigned int v7; // edx
  unsigned int v8; // ebx
  char v9; // di
  AKRESULT v10; // edi
  unsigned int v11; // esi
  CAkKeyList<unsigned long,CAkSwitchPackage,2,ArrayPoolDefault> *v12; // r14
  char *v13; // r10
  int v14; // er12
  unsigned int v15; // ebx
  unsigned int v16; // edx
  CAkSwitchPackage *v17; // rsi
  unsigned int v18; // er15
  unsigned int *v19; // rax
  int v20; // er14
  unsigned int v21; // ebx
  unsigned int *v22; // rax
  signed __int64 v23; // rcx
  unsigned int *v24; // rdx
  unsigned int *v25; // rax
  __int64 v26; // rbx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v27; // rax
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v28; // rcx
  unsigned int v29; // edx
  char *v30; // r10
  char v31; // di
  unsigned int v32; // er9
  char v33; // cl
  char v34; // al
  int v35; // er8
  char *v36; // r10
  int v37; // eax
  __int64 v38; // ST28_8
  unsigned int v39; // [rsp+20h] [rbp-58h]
  int v40; // [rsp+30h] [rbp-48h]
  __int64 v41; // [rsp+40h] [rbp-38h]
  int v42; // [rsp+48h] [rbp-30h]
  char *io_rpData; // [rsp+98h] [rbp+20h]
  unsigned int io_rulDataSize; // [rsp+A0h] [rbp+28h]
  unsigned int v45; // [rsp+A8h] [rbp+30h]

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData + 4;
  v3 = this;
  result = CAkParameterNodeBase::SetNodeBaseParams((CAkParameterNodeBase *)&this->vfptr, &io_rpData, &io_rulDataSize, 0);
  if ( result == 1 )
  {
    v5 = *(_DWORD *)io_rpData;
    v6 = io_rpData + 4;
    io_rpData = v6;
    v7 = *(_DWORD *)v6;
    v6 += 4;
    io_rpData = v6;
    v8 = *(_DWORD *)v6;
    v6 += 4;
    io_rpData = v6;
    v9 = *v6;
    io_rpData = v6 + 1;
    result = 1;
    if ( v7 != v3->m_ulGroupID || v5 != v3->m_eGroupType )
    {
      v3->m_ulGroupID = v7;
      v3->m_eGroupType = v5;
      result = CAkSwitchAware::SubscribeSwitch((CAkSwitchAware *)&v3->vfptr, v7, v5);
    }
    if ( result == 1 )
    {
      *((_BYTE *)&v3->0 + 83) &= 0x7Fu;
      v3->m_ulDefaultSwitch = v8;
      *((_BYTE *)&v3->0 + 83) |= (v9 != 0) << 7;
      result = CAkParentNode<CAkParameterNode>::SetChildren(
                 (CAkParentNode<CAkParameterNode> *)&v3->vfptr,
                 &io_rpData,
                 &io_rulDataSize);
      v10 = result;
      if ( result == 1 )
      {
        v11 = *(_DWORD *)io_rpData;
        io_rpData += 4;
        v12 = &v3->m_SwitchList;
        v39 = v11;
        CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::Reserve(
          (CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault> *)&v3->m_SwitchList.m_pFirst,
          v11);
        v13 = io_rpData;
        v14 = 0;
        v15 = 0;
        v45 = 0;
        if ( v11 )
        {
          while ( 1 )
          {
            v16 = *(_DWORD *)v13;
            io_rpData = v13 + 4;
            v17 = CAkKeyList<unsigned long,CAkSwitchPackage,2,ArrayPoolDefault>::Set(v12, v16);
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
            v45 = ++v15;
            if ( v15 >= v39 )
              goto LABEL_30;
            v12 = &v3->m_SwitchList;
          }
          while ( 1 )
          {
            v21 = *(_DWORD *)v13;
            v13 += 4;
            v10 = 57;
            io_rpData = v13;
            v22 = v17->m_list.m_pItems;
            v23 = (signed __int64)&v17->m_list.m_pItems[v17->m_list.m_uLength];
            if ( v17->m_list.m_pItems != (unsigned int *)v23 )
            {
              do
              {
                if ( *v22 == v21 )
                  break;
                ++v22;
              }
              while ( v22 != (unsigned int *)v23 );
            }
            v24 = 0i64;
            if ( v22 != (unsigned int *)v23 )
              v24 = v22;
            if ( !v24 )
            {
              v25 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&v17->m_list);
              if ( v25 )
              {
                *v25 = v21;
                v10 = 1;
              }
              else
              {
                v10 = 2;
              }
              v13 = io_rpData;
            }
            if ( v10 != 1 )
              return v10;
            if ( ++v20 >= v18 )
            {
              v15 = v45;
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
        v3->m_listParameters.m_pvMemStart = v27;
        if ( v27 )
        {
          v3->m_listParameters.m_ulMinNumListItems = v26;
          v3->m_listParameters.m_pFree = v27;
          v29 = 0;
          if ( (_DWORD)v26 )
          {
            do
            {
              ++v29;
              v28->pNextListItem = v28 + 1;
              ++v28;
            }
            while ( v29 < v3->m_listParameters.m_ulMinNumListItems );
          }
          v28[-1].pNextListItem = 0i64;
        }
        v30 = io_rpData;
        if ( !(_DWORD)v26 )
          return v10;
        v31 = v40;
        while ( 1 )
        {
          v32 = *(_DWORD *)v30;
          io_rpData = v30 + 4;
          v33 = v30[4];
          io_rpData = v30 + 5;
          v34 = v30[5];
          io_rpData = v30 + 6;
          v35 = *(_DWORD *)(v30 + 6);
          v36 = v30 + 10;
          io_rpData = v36;
          v36 += 4;
          v31 = v31 & 0xE0 | v35 & 7 | 8 * ((v33 != 0) | 2 * (v34 != 0));
          v37 = *((_DWORD *)v36 - 1);
          io_rpData = v36;
          LODWORD(v38) = v37;
          HIDWORD(v38) = *(_DWORD *)v36;
          LOBYTE(v40) = v31;
          v41 = v38;
          io_rpData = v36 + 4;
          v42 = v40;
          result = 2
                 - (CAkKeyList<unsigned long,AkSwitchNodeParams,2,ArrayPoolDefault>::Set(
                      &v3->m_listParameters,
                      v32,
                      (AkSwitchNodeParams *)&v41) != 0i64);
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
  CAkSwitchCntr *v1; // rbx
  AKRESULT result; // eax

  v1 = this;
  result = CAkMultiPlayNode::Init((CAkMultiPlayNode *)&this->vfptr);
  if ( result == 1 )
  {
    v1->m_SwitchList.m_ulMaxNumListItems = -1;
    v1->m_SwitchList.m_ulNumListItems = 0;
    v1->m_SwitchList.m_pFree = 0i64;
    v1->m_SwitchList.m_pvMemStart = 0i64;
    v1->m_SwitchList.m_pFirst = 0i64;
    v1->m_SwitchList.m_pLast = 0i64;
    v1->m_listParameters.m_ulNumListItems = 0;
    v1->m_listParameters.m_pFree = 0i64;
    v1->m_listParameters.m_pvMemStart = 0i64;
    v1->m_listParameters.m_pFirst = 0i64;
    v1->m_listParameters.m_pLast = 0i64;
    v1->m_listParameters.m_ulMaxNumListItems = -1;
    v1->m_listSwitchContPlayback.m_ulNumListItems = 0;
    v1->m_listSwitchContPlayback.m_pFree = 0i64;
    v1->m_listSwitchContPlayback.m_pvMemStart = 0i64;
    v1->m_listSwitchContPlayback.m_pFirst = 0i64;
    v1->m_listSwitchContPlayback.m_pLast = 0i64;
    v1->m_listSwitchContPlayback.m_ulMaxNumListItems = -1;
    result = 1;
  }
  return result;
}

// File Line: 194
// RVA: 0xA898B0
void __fastcall CAkSwitchCntr::OnPreRelease(CAkSwitchCntr *this)
{
  CAkSwitchCntr *v1; // rbx

  v1 = this;
  CAkSwitchCntr::CleanSwitchContPlayback(this);
  CAkParameterNodeBase::FlushStateTransitions((CAkParameterNodeBase *)&v1->vfptr);
}

// File Line: 206
// RVA: 0xA89450
void __fastcall CAkSwitchCntr::CleanSwitchContPlayback(CAkSwitchCntr *this)
{
  CAkSwitchCntr *v1; // r14
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *i; // rbx
  CAkRegisteredObj *v3; // rdi
  int v4; // ecx
  int v5; // esi

  v1 = this;
  if ( this->m_listSwitchContPlayback.m_ulMaxNumListItems )
  {
    for ( i = this->m_listSwitchContPlayback.m_pFirst; i; i = i->pNextListItem )
    {
      CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, i->Item.UserParameters.m_PlayingID);
      ((void (__fastcall *)(CAkSwitchCntr *, signed __int64))v1->vfptr[9].Category)(v1, 3i64);
      v3 = i->Item.GameObject;
      v4 = *((_DWORD *)v3 + 30) ^ (*((_DWORD *)v3 + 30) ^ (*((_DWORD *)v3 + 30) - 1)) & 0x3FFFFFFF;
      *((_DWORD *)v3 + 30) = v4;
      if ( !(v4 & 0x3FFFFFFF) )
      {
        v5 = g_DefaultPoolId;
        CAkRegisteredObj::~CAkRegisteredObj(v3);
        AK::MemoryMgr::Free(v5, v3);
      }
    }
  }
}

// File Line: 219
// RVA: 0xA895B0
void __fastcall CAkSwitchCntr::Create(unsigned int in_ulID)
{
  unsigned int v1; // ebx
  CAkSwitchCntr *v2; // rax
  CAkSwitchCntr *v3; // rax
  CAkSwitchCntr *v4; // rbx

  v1 = in_ulID;
  v2 = (CAkSwitchCntr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x178ui64);
  if ( v2 )
  {
    CAkSwitchCntr::CAkSwitchCntr(v2, v1);
    v4 = v3;
    if ( v3 )
    {
      if ( CAkSwitchCntr::Init(v3) != 1 )
        v4->vfptr->Release((CAkIndexable *)&v4->vfptr);
    }
  }
}

// File Line: 241
// RVA: 0xA89C70
__int64 __fastcall CAkSwitchCntr::PlayInternal(CAkSwitchCntr *this, AkPBIParams *in_rPBIParams)
{
  CAkSwitchCntr *v2; // r14
  AkPBIParams *v3; // r13
  bool v4; // bl
  AKRESULT v5; // edi
  unsigned int v6; // eax
  int v7; // er12
  bool v8; // zf
  unsigned int v9; // esi
  AkExternalSourceArray *v10; // r15
  int v11; // eax
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v12; // rcx
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v13; // rax
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v14; // rcx
  CAkSwitchCntr::SwitchContPlaybackItem *v15; // rbx
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *v16; // rax
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *v17; // rcx
  signed __int64 v18; // r15
  int v19; // eax
  unsigned int v20; // er8
  CAkRegisteredObj *v21; // rdx
  bool v22; // si
  unsigned int *v23; // rbx
  char v24; // r12
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v25; // rax
  unsigned int v26; // edx
  CAkParameterNode *v27; // rax
  CAkParameterNode *v28; // rsi
  AKRESULT v29; // eax
  CAkContinuationList *v30; // rax
  CAkContinuationList *v31; // rcx
  AKRESULT v32; // eax
  AKRESULT v33; // eax
  SafeContinuationList in_rSafeContList; // [rsp+20h] [rbp-E0h]
  int v36; // [rsp+28h] [rbp-D8h]
  int v37; // [rsp+2Ch] [rbp-D4h]
  int v38; // [rsp+30h] [rbp-D0h]
  CAkSwitchCntr::SwitchContPlaybackItem __that; // [rsp+40h] [rbp-C0h]
  ContParams *in_pFrom; // [rsp+D0h] [rbp-30h]
  int v41; // [rsp+D8h] [rbp-28h]
  AkContParamsAndPath in_rContParams; // [rsp+E0h] [rbp-20h]
  bool v43; // [rsp+160h] [rbp+60h]
  bool v44; // [rsp+168h] [rbp+68h]
  __int64 v45; // [rsp+170h] [rbp+70h]
  __int64 v46; // [rsp+178h] [rbp+78h]

  v2 = this;
  v3 = in_rPBIParams;
  v4 = in_rPBIParams->eType != 0;
  v5 = 2;
  v43 = in_rPBIParams->eType != 0;
  v6 = CAkSwitchAware::GetSwitchToUse(
         (CAkSwitchAware *)&this->vfptr,
         in_rPBIParams->pGameObj,
         this->m_ulGroupID,
         this->m_eGroupType);
  v7 = 0;
  v8 = *((_BYTE *)&v2->0 + 83) >= 0;
  v46 = 0i64;
  v9 = v6;
  if ( !v8 )
  {
    v10 = v3->userParams.m_CustomParam.pExternalSrcs;
    __that.ePlaybackState = v3->ePlaybackState;
    __that.GameObject = v3->pGameObj;
    __that.UserParameters.m_PlayingID = v3->userParams.m_PlayingID;
    __that.UserParameters.m_CustomParam.customParam = v3->userParams.m_CustomParam.customParam;
    __that.UserParameters.m_CustomParam.ui32Reserved = v3->userParams.m_CustomParam.ui32Reserved;
    if ( v10 )
      ++v10->m_cRefCount;
    __that.PlayHist.HistArray.uiArraySize = v3->playHistory.HistArray.uiArraySize;
    v11 = *(_DWORD *)v3->playHistory.HistArray.aCntrHist;
    __that.UserParameters.m_CustomParam.pExternalSrcs = v10;
    *(_DWORD *)__that.PlayHist.HistArray.aCntrHist = v11;
    *(_DWORD *)&__that.PlayHist.HistArray.aCntrHist[2] = *(_DWORD *)&v3->playHistory.HistArray.aCntrHist[2];
    *(_DWORD *)&__that.PlayHist.HistArray.aCntrHist[4] = *(_DWORD *)&v3->playHistory.HistArray.aCntrHist[4];
    *(_DWORD *)&__that.PlayHist.HistArray.aCntrHist[6] = *(_DWORD *)&v3->playHistory.HistArray.aCntrHist[6];
    *(_DWORD *)&__that.PlayHist.HistArray.aCntrHist[8] = *(_DWORD *)&v3->playHistory.HistArray.aCntrHist[8];
    *(_DWORD *)&__that.PlayHist.HistArray.aCntrHist[10] = *(_DWORD *)&v3->playHistory.HistArray.aCntrHist[10];
    *(_DWORD *)&__that.PlayHist.HistArray.aCntrHist[12] = *(_DWORD *)&v3->playHistory.HistArray.aCntrHist[12];
    *(_DWORD *)&__that.PlayHist.HistArray.aCntrHist[14] = *(_DWORD *)&v3->playHistory.HistArray.aCntrHist[14];
    *(_DWORD *)&__that.PlayHist.HistArray.aCntrHist[16] = *(_DWORD *)&v3->playHistory.HistArray.aCntrHist[16];
    *(_DWORD *)&__that.PlayHist.HistArray.aCntrHist[18] = *(_DWORD *)&v3->playHistory.HistArray.aCntrHist[18];
    *(_DWORD *)&__that.PlayHist.HistArray.aCntrHist[20] = *(_DWORD *)&v3->playHistory.HistArray.aCntrHist[20];
    *(_DWORD *)&__that.PlayHist.HistArray.aCntrHist[22] = *(_DWORD *)&v3->playHistory.HistArray.aCntrHist[22];
    *(_DWORD *)&__that.PlayHist.HistArray.aCntrHist[24] = *(_DWORD *)&v3->playHistory.HistArray.aCntrHist[24];
    *(_DWORD *)&__that.PlayHist.HistArray.aCntrHist[26] = *(_DWORD *)&v3->playHistory.HistArray.aCntrHist[26];
    *(_DWORD *)&__that.PlayHist.HistArray.aCntrHist[28] = *(_DWORD *)&v3->playHistory.HistArray.aCntrHist[28];
    *(_DWORD *)&__that.PlayHist.HistArray.aCntrHist[30] = *(_DWORD *)&v3->playHistory.HistArray.aCntrHist[30];
    __that.PlayHist.arrayIsContinuous.m_iBitArray = v3->playHistory.arrayIsContinuous.m_iBitArray;
    if ( !((unsigned __int8 (__fastcall *)(CAkSwitchCntr *, signed __int64))v2->vfptr[9].Release)(v2, 3i64)
      || !CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::CanAddOne(&v2->m_listSwitchContPlayback) )
    {
      goto LABEL_11;
    }
    v12 = v2->m_listSwitchContPlayback.m_pLast;
    v13 = v2->m_listSwitchContPlayback.m_pFree;
    if ( v12 )
      v12->pNextListItem = v13;
    else
      v2->m_listSwitchContPlayback.m_pFirst = v13;
    v14 = v2->m_listSwitchContPlayback.m_pFree;
    v2->m_listSwitchContPlayback.m_pLast = v14;
    v2->m_listSwitchContPlayback.m_pFree = v14->pNextListItem;
    v14->pNextListItem = 0i64;
    ++v2->m_listSwitchContPlayback.m_ulNumListItems;
    v15 = &v2->m_listSwitchContPlayback.m_pLast->Item;
    CAkSwitchCntr::SwitchContPlaybackItem::operator=(v15, &__that);
    if ( !v15 )
    {
      v10 = __that.UserParameters.m_CustomParam.pExternalSrcs;
LABEL_11:
      ((void (__fastcall *)(CAkSwitchCntr *, signed __int64))v2->vfptr[9].Category)(v2, 3i64);
      if ( v10 )
        AkExternalSourceArray::Release(v10);
      return (unsigned int)v5;
    }
    *((_DWORD *)__that.GameObject + 30) ^= (*((_DWORD *)__that.GameObject + 30) ^ (*((_DWORD *)__that.GameObject + 30)
                                                                                 + 1)) & 0x3FFFFFFF;
    CAkPlayingMgr::AddItemActiveCount(g_pPlayingMgr, v3->userParams.m_PlayingID);
    if ( __that.UserParameters.m_CustomParam.pExternalSrcs )
      AkExternalSourceArray::Release(__that.UserParameters.m_CustomParam.pExternalSrcs);
    v4 = v43;
  }
  SafeContinuationList::SafeContinuationList(&in_rSafeContList, v3, (CAkMultiPlayNode *)&v2->vfptr);
  v16 = v2->m_SwitchList.m_pFirst;
  v17 = v16;
  if ( !v16 )
    goto LABEL_21;
  while ( v17->Item.key != v9 )
  {
    v17 = v17->pNextListItem;
    if ( !v17 )
      goto LABEL_21;
  }
  v18 = (signed __int64)&v17->Item.item;
  if ( v17 == (CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *)-16i64 )
  {
LABEL_21:
    v9 = v2->m_ulDefaultSwitch;
    if ( !v16 )
      goto LABEL_24;
    while ( v16->Item.key != v9 )
    {
      v16 = v16->pNextListItem;
      if ( !v16 )
        goto LABEL_24;
    }
    v18 = (signed __int64)&v16->Item.item;
    if ( v16 == (CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *)-16i64 )
    {
LABEL_24:
      if ( v4 )
        goto LABEL_79;
      v5 = 1;
      goto LABEL_76;
    }
  }
  CAkRegistryMgr::GetSwitchHistItem(g_pRegistryMgr, (CAkRegisteredObj *)&v45, (__int64)v3->pGameObj, v2->key);
  if ( (_DWORD)v45 == v9 )
  {
    v19 = HIDWORD(v45) + 1;
  }
  else
  {
    LODWORD(v45) = v9;
    v19 = 1;
  }
  v20 = v2->key;
  v21 = v3->pGameObj;
  HIDWORD(v45) = v19;
  v22 = v19 == 1;
  v44 = v19 == 1;
  CAkRegistryMgr::SetSwitchHistItem(g_pRegistryMgr, v21, v20, (AkSwitchHistItem *)&v45);
  if ( !v4 && !*(_DWORD *)(v18 + 8) )
  {
    v5 = 1;
    goto LABEL_76;
  }
  v23 = *(unsigned int **)v18;
  if ( *(_QWORD *)v18 == *(_QWORD *)v18 + 4i64 * *(unsigned int *)(v18 + 8) )
    goto LABEL_71;
  v24 = v38;
  do
  {
    AkPBIParams::AkPBIParams((AkPBIParams *)&__that, v3);
    v25 = v2->m_listParameters.m_pFirst;
    v26 = *v23;
    if ( !v25 )
      goto LABEL_38;
    while ( v25->Item.key != v26 )
    {
      v25 = v25->pNextListItem;
      if ( !v25 )
        goto LABEL_38;
    }
    if ( v25 != (CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *)-12i64 )
    {
      v36 = v25->Item.item.FadeOutTime;
      v37 = v25->Item.item.FadeInTime;
      v38 = *((_DWORD *)&v25->Item.item + 2);
      v24 = v38;
    }
    else
    {
LABEL_38:
      v24 &= 0xE0u;
    }
    if ( (v22 || !(v24 & 8)) && (!v41 || !(_DWORD)v46) )
    {
      v27 = (CAkParameterNode *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, v26, 0);
      v28 = v27;
      if ( !v27 )
      {
LABEL_66:
        v22 = v44;
        goto LABEL_67;
      }
      if ( !v43 )
      {
        v29 = (unsigned int)CAkParameterNode::HandleInitialDelay(v27, (AkPBIParams *)&__that);
        v5 = v29;
        if ( v29 == 3 )
        {
          v5 = 1;
          goto LABEL_64;
        }
        if ( v29 == 1 )
          v5 = ((unsigned int (__fastcall *)(CAkParameterNode *, CAkSwitchCntr::SwitchContPlaybackItem *))v28->vfptr[19].Category)(
                 v28,
                 &__that);
LABEL_63:
        if ( v5 != 1 )
        {
LABEL_65:
          v28->vfptr->Release((CAkIndexable *)&v28->vfptr);
          goto LABEL_66;
        }
LABEL_64:
        LODWORD(v46) = v46 + 1;
        goto LABEL_65;
      }
      AkContParamsAndPath::AkContParamsAndPath(&in_rContParams, in_pFrom);
      if ( *(_DWORD *)(v18 + 8) == 1 )
      {
        CAkMultiPlayNode::ContGetList(
          (CAkMultiPlayNode *)&v2->vfptr,
          in_pFrom->spContList.m_pT,
          &in_rContParams.m_continuousParams.spContList);
        goto LABEL_57;
      }
      v30 = CAkContinuationList::Create();
      v31 = in_rContParams.m_continuousParams.spContList.m_pT;
      in_rContParams.m_continuousParams.spContList.m_pT = v30;
      if ( v31 )
      {
        CAkContinuationList::Release(v31);
        v30 = in_rContParams.m_continuousParams.spContList.m_pT;
      }
      if ( v30 )
      {
        v5 = CAkMultiPlayNode::AddMultiplayItem(
               (CAkMultiPlayNode *)&v2->vfptr,
               &in_rContParams,
               (AkPBIParams *)&__that,
               &in_rSafeContList);
        if ( v5 == 1 )
        {
LABEL_57:
          in_pFrom = (ContParams *)&in_rContParams;
          v32 = (unsigned int)CAkParameterNode::HandleInitialDelay(v28, (AkPBIParams *)&__that);
          v5 = v32;
          if ( v32 == 3 )
          {
            v5 = 1;
          }
          else if ( v32 == 1 )
          {
            v5 = ((unsigned int (__fastcall *)(CAkParameterNode *, CAkSwitchCntr::SwitchContPlaybackItem *))v28->vfptr[19].Category)(
                   v28,
                   &__that);
          }
          goto LABEL_62;
        }
      }
      else
      {
        v5 = 52;
      }
LABEL_62:
      AkContParamsAndPath::~AkContParamsAndPath(&in_rContParams);
      goto LABEL_63;
    }
LABEL_67:
    if ( *(_QWORD *)&__that.PlayHist.HistArray.aCntrHist[2] )
      AkExternalSourceArray::Release(*(AkExternalSourceArray **)&__that.PlayHist.HistArray.aCntrHist[2]);
    ++v23;
  }
  while ( v23 != (unsigned int *)(*(_QWORD *)v18 + 4i64 * *(unsigned int *)(v18 + 8)) );
  v7 = v46;
LABEL_71:
  if ( !v43 )
    goto LABEL_76;
  if ( v7 )
    goto LABEL_73;
LABEL_79:
  if ( *((_BYTE *)&v2->0 + 83) < 0 )
  {
LABEL_73:
    if ( in_rSafeContList.m_spBackupContinuationList.m_pT )
    {
      v33 = CAkMultiPlayNode::ContUnrefList(
              (CAkMultiPlayNode *)&v2->vfptr,
              in_rSafeContList.m_spBackupContinuationList.m_pT);
      goto LABEL_75;
    }
  }
  else
  {
    v33 = CAkMultiPlayNode::PlayAndContinueAlternateMultiPlay((CAkMultiPlayNode *)&v2->vfptr, v3);
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
signed __int64 __fastcall CAkSwitchCntr::ExecuteAction(CAkSwitchCntr *this, ActionParams *in_rAction)
{
  ActionParams *v2; // rbx
  CAkSwitchCntr *v3; // rdi
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v5; // rax
  unsigned int v6; // ecx
  CAkRegisteredObj *j; // rdx
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v8; // rax
  unsigned int v9; // ecx
  CAkRegisteredObj *i; // rdx

  v2 = in_rAction;
  v3 = this;
  switch ( in_rAction->eType )
  {
    case 0:
      goto LABEL_5;
    case 1:
      v8 = this->m_listSwitchContPlayback.m_pFirst;
      v9 = in_rAction->playingID;
      for ( i = in_rAction->pGameObj; v8; v8 = v8->pNextListItem )
      {
        if ( (!i || i == v8->Item.GameObject)
          && (!v9 || v8->Item.UserParameters.m_PlayingID == v9)
          && v8->Item.ePlaybackState != 1 )
        {
          v8->Item.ePlaybackState = 1;
        }
      }
      break;
    case 2:
      v5 = this->m_listSwitchContPlayback.m_pFirst;
      v6 = in_rAction->playingID;
      for ( j = in_rAction->pGameObj; v5; v5 = v5->pNextListItem )
      {
        if ( (!j || j == v5->Item.GameObject) && (!v6 || v5->Item.UserParameters.m_PlayingID == v6) )
        {
          if ( v5->Item.ePlaybackState )
            v5->Item.ePlaybackState = 0;
        }
      }
      break;
    case 3:
LABEL_5:
      CAkSwitchCntr::StopContSwitchInst(this, in_rAction->pGameObj, in_rAction->playingID);
      return CAkActiveParent<CAkParameterNode>::ExecuteAction((CAkActiveParent<CAkParameterNode> *)&v3->vfptr, v2);
  }
  return CAkActiveParent<CAkParameterNode>::ExecuteAction((CAkActiveParent<CAkParameterNode> *)&v3->vfptr, v2);
}

// File Line: 421
// RVA: 0xA896E0
signed __int64 __fastcall CAkSwitchCntr::ExecuteActionExcept(CAkSwitchCntr *this, ActionParamsExcept *in_rAction)
{
  ActionParamsExcept *v2; // rbx
  CAkSwitchCntr *v3; // rdi
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v4; // rax
  CAkRegisteredObj *j; // r8
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v6; // rax
  CAkRegisteredObj *i; // rcx

  v2 = in_rAction;
  v3 = this;
  if ( in_rAction->eType )
  {
    if ( in_rAction->eType == 1 )
    {
      v6 = this->m_listSwitchContPlayback.m_pFirst;
      for ( i = in_rAction->pGameObj; v6; v6 = v6->pNextListItem )
      {
        if ( (!i || i == v6->Item.GameObject) && v6->Item.ePlaybackState != 1 )
          v6->Item.ePlaybackState = 1;
      }
    }
    else if ( in_rAction->eType == 2 )
    {
      v4 = this->m_listSwitchContPlayback.m_pFirst;
      for ( j = in_rAction->pGameObj; v4; v4 = v4->pNextListItem )
      {
        if ( !j || j == v4->Item.GameObject )
        {
          if ( v4->Item.ePlaybackState )
            v4->Item.ePlaybackState = 0;
        }
      }
    }
  }
  else
  {
    CAkSwitchCntr::StopContSwitchInst(this, in_rAction->pGameObj, 0);
  }
  return CAkActiveParent<CAkParameterNode>::ExecuteActionExcept((CAkActiveParent<CAkParameterNode> *)&v3->vfptr, v2);
}

// File Line: 440
// RVA: 0xA8ABF0
void __fastcall CAkSwitchCntr::StopContSwitchInst(CAkSwitchCntr *this, CAkRegisteredObj *in_pGameObj, unsigned int in_PlayingID)
{
  CAkSwitchCntr *v3; // rbx
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v4; // rax
  char v5; // cl
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v6; // rdi
  unsigned int v7; // er14
  CAkRegisteredObj *v8; // rbp
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v9; // rcx
  CAkRegisteredObj *v10; // rsi
  int v11; // ecx
  int v12; // edi
  __m128i v13; // [rsp+20h] [rbp-28h]
  __m128i v14; // [rsp+30h] [rbp-18h]

  v3 = this;
  v4 = 0i64;
  v5 = 0;
  v6 = v3->m_listSwitchContPlayback.m_pFirst;
  v7 = in_PlayingID;
  v8 = in_pGameObj;
  if ( v6 )
  {
    do
    {
      if ( v8 && v8 != v6->Item.GameObject || v7 && v6->Item.UserParameters.m_PlayingID != v7 )
      {
        v4 = v6;
        v6 = v6->pNextListItem;
      }
      else
      {
        v9 = v6->pNextListItem;
        v13.m128i_i64[1] = (__int64)v4;
        v13.m128i_i64[0] = (__int64)v6->pNextListItem;
        if ( v6 == v3->m_listSwitchContPlayback.m_pFirst )
          v3->m_listSwitchContPlayback.m_pFirst = v9;
        else
          v4->pNextListItem = v9;
        if ( v6 == v3->m_listSwitchContPlayback.m_pLast )
          v3->m_listSwitchContPlayback.m_pLast = v4;
        v6->pNextListItem = v3->m_listSwitchContPlayback.m_pFree;
        --v3->m_listSwitchContPlayback.m_ulNumListItems;
        v3->m_listSwitchContPlayback.m_pFree = v6;
        _mm_store_si128(&v14, v13);
        CAkPlayingMgr::RemoveItemActiveCount(g_pPlayingMgr, v6->Item.UserParameters.m_PlayingID);
        ((void (__fastcall *)(CAkSwitchCntr *, signed __int64))v3->vfptr[9].Category)(v3, 3i64);
        v10 = v6->Item.GameObject;
        v11 = *((_DWORD *)v10 + 30) ^ (*((_DWORD *)v10 + 30) ^ (*((_DWORD *)v10 + 30) - 1)) & 0x3FFFFFFF;
        *((_DWORD *)v10 + 30) = v11;
        if ( !(v11 & 0x3FFFFFFF) )
        {
          v12 = g_DefaultPoolId;
          CAkRegisteredObj::~CAkRegisteredObj(v10);
          AK::MemoryMgr::Free(v12, v10);
        }
        v4 = (CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *)v14.m128i_i64[1];
        v6 = (CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *)v14.m128i_i64[0];
        v5 = 1;
      }
    }
    while ( v6 );
    if ( v5 )
      CAkRegistryMgr::ClearSwitchHist(g_pRegistryMgr, v3->key, v8);
  }
}

// File Line: 537
// RVA: 0xA8A540
void __fastcall CAkSwitchCntr::RemoveChild(CAkSwitchCntr *this, CAkParameterNodeBase *in_pChild, __int64 a3, __int64 a4)
{
  unsigned int v4; // edi
  CAkParameterNodeBase *v5; // r8
  CAkSwitchCntr *v6; // rbx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v7; // rcx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v8; // rdx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v9; // rax
  bool v10; // zf
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v11; // rcx

  v4 = in_pChild->key;
  LOBYTE(a4) = 0;
  v5 = in_pChild;
  v6 = this;
  if ( (CAkSwitchCntr *)in_pChild->m_pParentNode == this )
  {
    ((void (__fastcall *)(CAkParameterNodeBase *, _QWORD, CAkParameterNodeBase *, __int64))in_pChild->vfptr[1].Release)(
      in_pChild,
      0i64,
      in_pChild,
      a4);
    AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Unset<unsigned long>(
      &v6->m_mapChildId,
      v4);
    LOBYTE(a4) = 1;
  }
  v7 = v6->m_listParameters.m_pFirst;
  v8 = 0i64;
  v9 = v7;
  if ( v7 )
  {
    while ( v9->Item.key != v4 )
    {
      v8 = v9;
      v9 = v9->pNextListItem;
      if ( !v9 )
        goto LABEL_13;
    }
    v10 = v9 == v7;
    v11 = v9->pNextListItem;
    if ( v10 )
      v6->m_listParameters.m_pFirst = v11;
    else
      v8->pNextListItem = v11;
    if ( v9 == v6->m_listParameters.m_pLast )
      v6->m_listParameters.m_pLast = v8;
    v9->pNextListItem = v6->m_listParameters.m_pFree;
    --v6->m_listParameters.m_ulNumListItems;
    v6->m_listParameters.m_pFree = v9;
  }
LABEL_13:
  if ( (_BYTE)a4 )
    ((void (__fastcall *)(CAkSwitchCntr *, CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *, CAkParameterNodeBase *))v6->vfptr->Release)(
      v6,
      v8,
      v5);
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
signed __int64 __fastcall CAkSwitchCntr::PrepareNodeList(CAkSwitchCntr *this, AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *in_rNodeList)
{
  unsigned int *v2; // rdi
  AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v3; // rsi
  unsigned int v4; // ebp
  unsigned int *i; // rbx

  v2 = in_rNodeList->m_pItems;
  v3 = in_rNodeList;
  if ( in_rNodeList->m_pItems == &in_rNodeList->m_pItems[in_rNodeList->m_uLength] )
    return 1i64;
  do
  {
    v4 = CAkParameterNodeBase::PrepareNodeData(*v2);
    if ( v4 != 1 )
    {
      for ( i = v3->m_pItems; i != v2; ++i )
        CAkParameterNodeBase::UnPrepareNodeData(*i);
    }
    ++v2;
  }
  while ( v2 != &v3->m_pItems[v3->m_uLength] );
  return v4;
}

// File Line: 588
// RVA: 0xA8B290
void __fastcall CAkSwitchCntr::UnPrepareNodeList(CAkSwitchCntr *this, AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *in_rNodeList)
{
  unsigned int *v2; // rbx
  AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *i; // rdi

  v2 = in_rNodeList->m_pItems;
  for ( i = in_rNodeList; v2 != &i->m_pItems[i->m_uLength]; ++v2 )
    CAkParameterNodeBase::UnPrepareNodeData(*v2);
}

// File Line: 596
// RVA: 0xA89850
AKRESULT __fastcall CAkSwitchCntr::ModifyActiveState(CAkSwitchCntr *this, unsigned int in_stateID, bool in_bSupported)
{
  CAkParameterNodeBase::FXChunk *v3; // r9
  CAkSwitchCntr *v5; // rcx
  AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v6; // rdx

  if ( this->key )
  {
    v3 = this->m_pFXChunk;
    if ( v3 )
    {
      while ( *(_DWORD *)&v3->aFX[1].bRendered != in_stateID )
      {
        v3 = (CAkParameterNodeBase::FXChunk *)v3->aFX[0];
        if ( !v3 )
          return 1;
      }
      if ( v3 )
      {
        v5 = (CAkSwitchCntr *)((char *)this - 192);
        v6 = (AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)&v3->aFX[2];
        if ( in_bSupported )
          return CAkSwitchCntr::PrepareNodeList(v5, v6);
        CAkSwitchCntr::UnPrepareNodeList(v5, v6);
      }
    }
  }
  return 1;
}

// File Line: 628
// RVA: 0xA8A2F0
__int64 __fastcall CAkSwitchCntr::PrepareData(CAkSwitchCntr *this)
{
  CAkSwitchCntr *v1; // r14
  unsigned int v3; // eax
  AKRESULT v4; // ebp
  CAkPreparedContent *v5; // r15
  AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v6; // rsi
  unsigned int *v7; // rcx
  signed __int64 v8; // rax
  AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *i; // rdi
  unsigned int *v10; // rcx
  signed __int64 v11; // rax
  unsigned int *v12; // rbx
  AkGroupType v13; // er8
  unsigned int v14; // edx

  v1 = this;
  if ( !unk_14249E980 )
    return CAkActiveParent<CAkParameterNode>::PrepareData((CAkActiveParent<CAkParameterNode> *)&this->vfptr);
  v3 = this->m_uPreparationCount;
  v4 = 1;
  if ( v3 )
  {
    this->m_uPreparationCount = v3 + 1;
  }
  else
  {
    v5 = CAkPreparationAware::GetPreparedContent(
           (CAkPreparationAware *)&this->vfptr,
           this->m_ulGroupID,
           this->m_eGroupType);
    if ( v5 )
    {
      v6 = (AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)v1->m_SwitchList.m_pFirst;
      if ( !v6 )
        goto LABEL_29;
      do
      {
        v7 = v5->m_PreparableContentList.m_pItems;
        v8 = (signed __int64)&v5->m_PreparableContentList.m_pItems[v5->m_PreparableContentList.m_uLength];
        if ( v5->m_PreparableContentList.m_pItems != (unsigned int *)v8 )
        {
          do
          {
            if ( *v7 == v6->m_uLength )
              break;
            ++v7;
          }
          while ( v7 != (unsigned int *)v8 );
          if ( v7 != (unsigned int *)v8 )
            v4 = CAkSwitchCntr::PrepareNodeList(v1, v6 + 1);
        }
        if ( v4 != 1 )
        {
          for ( i = (AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)v1->m_SwitchList.m_pFirst;
                i != v6;
                i = (AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)i->m_pItems )
          {
            v10 = v5->m_PreparableContentList.m_pItems;
            v11 = (signed __int64)&v5->m_PreparableContentList.m_pItems[v5->m_PreparableContentList.m_uLength];
            if ( v5->m_PreparableContentList.m_pItems != (unsigned int *)v11 )
            {
              do
              {
                if ( *v10 == i->m_uLength )
                  break;
                ++v10;
              }
              while ( v10 != (unsigned int *)v11 );
              if ( v10 != (unsigned int *)v11 )
              {
                v12 = i[1].m_pItems;
                if ( v12 != &v12[i[1].m_uLength] )
                {
                  do
                  {
                    CAkParameterNodeBase::UnPrepareNodeData(*v12);
                    ++v12;
                  }
                  while ( v12 != &i[1].m_pItems[i[1].m_uLength] );
                }
              }
            }
          }
        }
        v6 = (AkArray<unsigned long,unsigned long,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)v6->m_pItems;
      }
      while ( v6 );
      if ( v4 == 1 )
      {
LABEL_29:
        v13 = v1->m_eGroupType;
        v14 = v1->m_ulGroupID;
        ++v1->m_uPreparationCount;
        v4 = CAkPreparationAware::SubscribePrepare((CAkPreparationAware *)&v1->vfptr, v14, v13);
        if ( v4 != 1 )
          v1->vfptr[10].AddRef((CAkIndexable *)&v1->vfptr);
      }
    }
    else
    {
      v4 = 52;
    }
  }
  return (unsigned int)v4;
}

// File Line: 681
// RVA: 0xA8B140
void __fastcall CAkSwitchCntr::UnPrepareData(CAkSwitchCntr *this)
{
  CAkSwitchCntr *v1; // rsi
  CAkParameterNodeBase **v2; // rbx
  unsigned int v3; // eax
  unsigned int v4; // eax
  CAkPreparedContent *v5; // r14
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *i; // rdi
  unsigned int *v7; // rcx
  signed __int64 v8; // rax
  unsigned int *v9; // rbx

  v1 = this;
  if ( unk_14249E980 )
  {
    v3 = this->m_uPreparationCount;
    if ( v3 )
    {
      v4 = v3 - 1;
      this->m_uPreparationCount = v4;
      if ( !v4 )
      {
        v5 = CAkPreparationAware::GetPreparedContent(
               (CAkPreparationAware *)&this->vfptr,
               this->m_ulGroupID,
               this->m_eGroupType);
        if ( v5 )
        {
          for ( i = v1->m_SwitchList.m_pFirst; i; i = i->pNextListItem )
          {
            v7 = v5->m_PreparableContentList.m_pItems;
            v8 = (signed __int64)&v5->m_PreparableContentList.m_pItems[v5->m_PreparableContentList.m_uLength];
            if ( v5->m_PreparableContentList.m_pItems != (unsigned int *)v8 )
            {
              do
              {
                if ( *v7 == i->Item.key )
                  break;
                ++v7;
              }
              while ( v7 != (unsigned int *)v8 );
              if ( v7 != (unsigned int *)v8 )
              {
                v9 = i->Item.item.m_list.m_pItems;
                if ( v9 != &v9[i->Item.item.m_list.m_uLength] )
                {
                  do
                  {
                    CAkParameterNodeBase::UnPrepareNodeData(*v9);
                    ++v9;
                  }
                  while ( v9 != &i->Item.item.m_list.m_pItems[i->Item.item.m_list.m_uLength] );
                }
              }
            }
          }
        }
        CAkPreparationAware::UnsubscribePrepare((CAkPreparationAware *)&v1->vfptr, v1->m_ulGroupID, v1->m_eGroupType);
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
        ((void (*)(void))(*v2)->vfptr[10].AddRef)();
        ++v2;
      }
      while ( v2 != &v1->m_mapChildId.m_pItems[v1->m_mapChildId.m_uLength] );
    }
  }
}

// File Line: 749
// RVA: 0xA898D0
signed __int64 __fastcall CAkSwitchCntr::PerformSwitchChange(CAkSwitchCntr *this, unsigned int in_SwitchTo, CAkRegisteredObj *in_GameObj)
{
  unsigned int v3; // ebp
  CAkSwitchCntr *v4; // rdi
  __int64 v5; // rsi
  CAkRegisteredObj **v6; // r14
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v7; // rax
  __int64 i; // r8
  CAkRegisteredObj **v9; // rbx
  signed __int64 result; // rax

  v3 = in_SwitchTo;
  v4 = this;
  if ( in_GameObj )
  {
    CAkSwitchCntr::PerformSwitchChangeContPerObject(this, in_SwitchTo, in_GameObj);
    result = 1i64;
  }
  else
  {
    v5 = this->m_listSwitchContPlayback.m_ulNumListItems;
    if ( (_DWORD)v5 )
    {
      v6 = (CAkRegisteredObj **)AK::MemoryMgr::Malloc(g_DefaultPoolId, (unsigned int)(8 * v5));
      if ( v6 )
      {
        v7 = v4->m_listSwitchContPlayback.m_pFirst;
        for ( i = 0i64; v7; i = (unsigned int)(i + 1) )
        {
          v6[i] = v7->Item.GameObject;
          v7 = v7->pNextListItem;
        }
        if ( (_DWORD)v5 )
        {
          v9 = v6;
          do
          {
            CAkSwitchCntr::PerformSwitchChangeContPerObject(v4, v3, *v9);
            ++v9;
            --v5;
          }
          while ( v5 );
        }
        AK::MemoryMgr::Free(g_DefaultPoolId, v6);
        result = 1i64;
      }
      else
      {
        result = 2i64;
      }
    }
    else
    {
      CAkRegistryMgr::ClearSwitchHist(g_pRegistryMgr, this->key, 0i64);
      result = 1i64;
    }
  }
  return result;
}

// File Line: 796
// RVA: 0xA899E0
signed __int64 __fastcall CAkSwitchCntr::PerformSwitchChangeContPerObject(CAkSwitchCntr *this, unsigned int in_SwitchTo, CAkRegisteredObj *in_GameObj)
{
  CAkSwitchCntr *v3; // r13
  unsigned int v4; // ebx
  CAkRegisteredObj *v5; // rdi
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *v6; // rax
  signed int v7; // esi
  CAkSwitchPackage *v8; // rcx
  CAkSwitchPackage *v9; // r15
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *v10; // rcx
  CAkSwitchPackage *v11; // r14
  AKRESULT v12; // ebp
  CAkList2<CAkSwitchCntr::SwitchContPlaybackItem,CAkSwitchCntr::SwitchContPlaybackItem const &,2,ArrayPoolDefault>::ListItem *v13; // rdi
  unsigned int v14; // edx
  char v15; // bp
  CAkRegisteredObj *v16; // rax
  unsigned int *v17; // rbx
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v18; // rax
  unsigned int v19; // edx
  unsigned int *v20; // rax
  signed __int64 v21; // r8
  int v23; // ST20_4
  int v24; // ST24_4
  char v25; // [rsp+28h] [rbp-50h]
  AKRESULT v26; // [rsp+80h] [rbp+8h]
  unsigned int v27; // [rsp+88h] [rbp+10h]
  CAkRegisteredObj *v28; // [rsp+90h] [rbp+18h]
  __int64 v29; // [rsp+98h] [rbp+20h]

  v28 = in_GameObj;
  v27 = in_SwitchTo;
  v3 = this;
  v4 = in_SwitchTo;
  v5 = in_GameObj;
  CAkRegistryMgr::GetSwitchHistItem(g_pRegistryMgr, (CAkRegisteredObj *)&v29, (__int64)in_GameObj, this->key);
  if ( v4 == (_DWORD)v29 )
    return 1i64;
  v6 = v3->m_SwitchList.m_pFirst;
  v7 = 0;
  v8 = (CAkSwitchPackage *)v6;
  if ( v6 )
  {
    while ( v8->m_list.m_uLength != (_DWORD)v29 )
    {
      v8 = (CAkSwitchPackage *)v8->m_list.m_pItems;
      if ( !v8 )
        goto LABEL_5;
    }
    v9 = v8 + 1;
  }
  else
  {
LABEL_5:
    v9 = 0i64;
  }
  v10 = v3->m_SwitchList.m_pFirst;
  if ( !v6 )
    goto LABEL_12;
  while ( v10->Item.key != v4 )
  {
    v10 = v10->pNextListItem;
    if ( !v10 )
      goto LABEL_12;
  }
  v11 = &v10->Item.item;
  if ( v10 == (CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *)-16i64 )
  {
LABEL_12:
    v4 = v3->m_ulDefaultSwitch;
    v27 = v3->m_ulDefaultSwitch;
    if ( v6 )
    {
      while ( v6->Item.key != v4 )
      {
        v6 = v6->pNextListItem;
        if ( !v6 )
          goto LABEL_15;
      }
      v11 = &v6->Item.item;
    }
    else
    {
LABEL_15:
      v11 = 0i64;
    }
  }
  v12 = CAkSwitchCntr::StopPrevious(v3, v9, v11, v5);
  v26 = v12;
  CAkRegistryMgr::ClearSwitchHist(g_pRegistryMgr, v3->key, v5);
  v13 = v3->m_listSwitchContPlayback.m_pFirst;
  v14 = 0;
  v29 = 0i64;
  if ( v13 )
  {
    v15 = v25;
    v16 = v28;
    do
    {
      if ( v13->Item.GameObject == v16 )
      {
        if ( v14 == v4 )
        {
          ++v7;
        }
        else
        {
          v14 = v4;
          LODWORD(v29) = v4;
          v7 = 1;
        }
        HIDWORD(v29) = v7;
        if ( v11 )
        {
          v17 = v11->m_list.m_pItems;
          if ( v11->m_list.m_pItems != &v11->m_list.m_pItems[v11->m_list.m_uLength] )
          {
            do
            {
              v18 = v3->m_listParameters.m_pFirst;
              v19 = *v17;
              if ( !v18 )
                goto LABEL_28;
              while ( v18->Item.key != v19 )
              {
                v18 = v18->pNextListItem;
                if ( !v18 )
                  goto LABEL_28;
              }
              if ( v18 != (CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *)-12i64 )
              {
                v23 = v18->Item.item.FadeOutTime;
                v24 = v18->Item.item.FadeInTime;
                v15 = *((_DWORD *)&v18->Item.item + 2);
              }
              else
              {
LABEL_28:
                v15 &= 0xE0u;
              }
              if ( v15 & 0x10
                && v9
                && (v20 = v9->m_list.m_pItems,
                    v21 = (signed __int64)&v9->m_list.m_pItems[v9->m_list.m_uLength],
                    v9->m_list.m_pItems != (unsigned int *)v21) )
              {
                while ( *v20 != v19 )
                {
                  ++v20;
                  if ( v20 == (unsigned int *)v21 )
                    goto LABEL_34;
                }
              }
              else
              {
LABEL_34:
                v26 = CAkSwitchCntr::PlayOnSwitch(v3, v19, &v13->Item);
              }
              ++v17;
            }
            while ( v17 != &v11->m_list.m_pItems[v11->m_list.m_uLength] );
            v7 = HIDWORD(v29);
            v14 = v29;
          }
          v16 = v28;
        }
      }
      v13 = v13->pNextListItem;
      v4 = v27;
    }
    while ( v13 );
    v12 = v26;
  }
  CAkRegistryMgr::SetSwitchHistItem(g_pRegistryMgr, v28, v3->key, (AkSwitchHistItem *)&v29);
  return (unsigned int)v12;
}

// File Line: 861
// RVA: 0xA8A180
signed __int64 __fastcall CAkSwitchCntr::PlayOnSwitch(CAkSwitchCntr *this, unsigned int in_ID, CAkSwitchCntr::SwitchContPlaybackItem *in_rContItem)
{
  CAkSwitchCntr *v3; // r14
  CAkSwitchCntr::SwitchContPlaybackItem *v4; // rsi
  unsigned int v5; // ebx
  CAkParameterNode *v6; // rdi
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v7; // rcx
  int v8; // eax
  __int128 v9; // xmm0
  __int128 v10; // xmm1
  CAkRegisteredObj *v11; // rax
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  __int64 v14; // rax
  AkExternalSourceArray *v15; // rax
  AkPlaybackState v16; // eax
  unsigned int v17; // eax
  unsigned int v18; // ebx
  signed __int64 v19; // rcx
  AkPBIParams in_rPBIParams; // [rsp+20h] [rbp-59h]
  int v22; // [rsp+F8h] [rbp+7Fh]
  int v23; // [rsp+FCh] [rbp+83h]

  v3 = this;
  v4 = in_rContItem;
  v5 = in_ID;
  v6 = (CAkParameterNode *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_ID, 0);
  if ( !v6 )
    return 2i64;
  v7 = v3->m_listParameters.m_pFirst;
  v23 = 4;
  if ( !v7 )
    goto LABEL_5;
  while ( v7->Item.key != v5 )
  {
    v7 = v7->pNextListItem;
    if ( !v7 )
      goto LABEL_5;
  }
  v19 = (signed __int64)&v7->Item.item;
  if ( v19 )
    v8 = *(_DWORD *)(v19 + 4);
  else
LABEL_5:
    v8 = 0;
  v9 = *(_OWORD *)&v4->PlayHist.HistArray.uiArraySize;
  v10 = *(_OWORD *)&v4->PlayHist.HistArray.aCntrHist[6];
  v22 = v8;
  v11 = v4->GameObject;
  in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = 0i64;
  *(_WORD *)&in_rPBIParams.bIsFirst = 1;
  in_rPBIParams.pGameObj = v11;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.uiArraySize = v9;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[6] = v10;
  v12 = *(_OWORD *)&v4->PlayHist.HistArray.aCntrHist[14];
  v13 = *(_OWORD *)&v4->PlayHist.HistArray.aCntrHist[22];
  in_rPBIParams.pTransitionParameters = (TransParams *)&v22;
  LODWORD(v11) = v4->UserParameters.m_PlayingID;
  in_rPBIParams.bTargetFeedback = 0;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[14] = v12;
  *(_OWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[22] = v13;
  *(_QWORD *)&v12 = *(_QWORD *)&v4->PlayHist.HistArray.aCntrHist[30];
  in_rPBIParams.userParams.m_PlayingID = (unsigned int)v11;
  v14 = v4->UserParameters.m_CustomParam.customParam;
  in_rPBIParams.eType = 0;
  *(_QWORD *)&in_rPBIParams.playHistory.HistArray.aCntrHist[30] = v12;
  in_rPBIParams.userParams.m_CustomParam.customParam = v14;
  LODWORD(v14) = v4->UserParameters.m_CustomParam.ui32Reserved;
  in_rPBIParams.pInstigator = (CAkPBIAware *)&v6->vfptr;
  in_rPBIParams.userParams.m_CustomParam.ui32Reserved = v14;
  v15 = v4->UserParameters.m_CustomParam.pExternalSrcs;
  if ( v15 )
    ++v15->m_cRefCount;
  in_rPBIParams.userParams.m_CustomParam.pExternalSrcs = v15;
  v16 = v4->ePlaybackState;
  in_rPBIParams.uFrameOffset = 0;
  in_rPBIParams.pContinuousParams = 0i64;
  in_rPBIParams.sequenceID = 0;
  in_rPBIParams.ePlaybackState = v16;
  v17 = CAkParameterNode::HandleInitialDelay(v6, &in_rPBIParams);
  v18 = v17;
  if ( v17 == 3 )
  {
    v18 = 1;
  }
  else if ( v17 == 1 )
  {
    v18 = ((__int64 (__fastcall *)(CAkParameterNode *, AkPBIParams *))v6->vfptr[19].Category)(v6, &in_rPBIParams);
  }
  v6->vfptr->Release((CAkIndexable *)&v6->vfptr);
  if ( in_rPBIParams.userParams.m_CustomParam.pExternalSrcs )
    AkExternalSourceArray::Release(in_rPBIParams.userParams.m_CustomParam.pExternalSrcs);
  return v18;
}

// File Line: 904
// RVA: 0xA8AD40
__int64 __fastcall CAkSwitchCntr::StopOnSwitch(CAkSwitchCntr *this, unsigned int in_ID, AkSwitchNodeParams *in_rSwitchNodeParams, CAkRegisteredObj *in_GameObj)
{
  CAkSwitchCntr *v4; // rbp
  AkSwitchNodeParams *v5; // r14
  CAkRegisteredObj *v6; // rsi
  unsigned int v7; // edi
  CAkParameterNodeBase *v8; // rax
  CAkParameterNodeBase *v9; // rbx
  CAkIndexableVtbl *v10; // rax
  int v12; // [rsp+20h] [rbp-38h]
  CAkRegisteredObj *v13; // [rsp+28h] [rbp-30h]
  int v14; // [rsp+30h] [rbp-28h]
  int v15; // [rsp+34h] [rbp-24h]
  int v16; // [rsp+38h] [rbp-20h]
  __int16 v17; // [rsp+3Ch] [rbp-1Ch]
  char v18; // [rsp+3Eh] [rbp-1Ah]

  v4 = this;
  v5 = in_rSwitchNodeParams;
  v6 = in_GameObj;
  v7 = 1;
  v8 = (CAkParameterNodeBase *)CAkAudioLibIndex::GetNodePtrAndAddRef(g_pIndex, in_ID, 0);
  v9 = v8;
  if ( v8 )
  {
    CAkAudioMgr::StopPendingAction(g_pAudioMgr, v8, v6, 0);
    if ( (*((_BYTE *)v5 + 8) & 7) == 1 )
    {
      v17 = 0;
      v12 = 0;
      v14 = 0;
      v15 = v5->FadeOutTime;
      v10 = v9->vfptr;
      v18 = 0;
      v16 = 4;
      v13 = v6;
      v7 = (__int64)v10[4].__vecDelDtor((CAkIndexable *)&v9->vfptr, (unsigned int)&v12);
    }
    else
    {
      ((void (__fastcall *)(CAkParameterNodeBase *, CAkRegisteredObj *, CAkSwitchCntr *, _QWORD))v9->vfptr[4].Category)(
        v9,
        v6,
        v4,
        0i64);
    }
    v9->vfptr->Release((CAkIndexable *)&v9->vfptr);
  }
  return v7;
}

// File Line: 940
// RVA: 0xA8AE20
__int64 __fastcall CAkSwitchCntr::StopPrevious(CAkSwitchCntr *this, CAkSwitchPackage *in_pPreviousSwitchPack, CAkSwitchPackage *in_pNextSwitchPack, CAkRegisteredObj *in_GameObj)
{
  CAkRegisteredObj *v4; // rbp
  CAkSwitchPackage *v5; // r15
  CAkSwitchPackage *v6; // r14
  CAkSwitchCntr *v7; // rsi
  unsigned int v8; // er11
  unsigned int *v9; // rbx
  char v10; // di
  CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *v11; // rax
  unsigned int v12; // edx
  unsigned int *v13; // rax
  signed __int64 v14; // r8
  __int64 result; // rax
  AkSwitchNodeParams in_rSwitchNodeParams; // [rsp+20h] [rbp-28h]

  v4 = in_GameObj;
  v5 = in_pNextSwitchPack;
  v6 = in_pPreviousSwitchPack;
  v7 = this;
  v8 = 1;
  if ( !in_pPreviousSwitchPack )
    return 1i64;
  v9 = in_pPreviousSwitchPack->m_list.m_pItems;
  if ( in_pPreviousSwitchPack->m_list.m_pItems == &in_pPreviousSwitchPack->m_list.m_pItems[in_pPreviousSwitchPack->m_list.m_uLength] )
    return 1i64;
  v10 = *((_BYTE *)&in_rSwitchNodeParams + 8);
  do
  {
    v11 = v7->m_listParameters.m_pFirst;
    v12 = *v9;
    if ( !v11 )
      goto LABEL_7;
    while ( v11->Item.key != v12 )
    {
      v11 = v11->pNextListItem;
      if ( !v11 )
        goto LABEL_7;
    }
    if ( v11 != (CAkList2<MapStruct<unsigned long,AkSwitchNodeParams>,MapStruct<unsigned long,AkSwitchNodeParams> const &,2,ArrayPoolDefault>::ListItem *)-12i64 )
    {
      in_rSwitchNodeParams.FadeOutTime = v11->Item.item.FadeOutTime;
      in_rSwitchNodeParams.FadeInTime = v11->Item.item.FadeInTime;
      *((_DWORD *)&in_rSwitchNodeParams + 2) = *((_DWORD *)&v11->Item.item + 2);
      v10 = *((_BYTE *)&in_rSwitchNodeParams + 8);
    }
    else
    {
LABEL_7:
      v10 &= 0xE0u;
      *(_QWORD *)&in_rSwitchNodeParams.FadeOutTime = 0i64;
      *((_BYTE *)&in_rSwitchNodeParams + 8) = v10;
    }
    if ( *((_BYTE *)&v7->0 + 83) < 0
      && v10 & 0x10
      && v5
      && (v13 = v5->m_list.m_pItems,
          v14 = (signed __int64)&v5->m_list.m_pItems[v5->m_list.m_uLength],
          v5->m_list.m_pItems != (unsigned int *)v14) )
    {
      while ( *v13 != v12 )
      {
        ++v13;
        if ( v13 == (unsigned int *)v14 )
          goto LABEL_14;
      }
    }
    else
    {
LABEL_14:
      result = CAkSwitchCntr::StopOnSwitch(v7, v12, &in_rSwitchNodeParams, v4);
      v8 = result;
      if ( (_DWORD)result != 1 )
        return result;
    }
    ++v9;
  }
  while ( v9 != &v6->m_list.m_pItems[v6->m_list.m_uLength] );
  return v8;
}

// File Line: 971
// RVA: 0xA89500
void __fastcall CAkSwitchCntr::ClearSwitches(CAkSwitchCntr *this)
{
  CAkSwitchCntr *v1; // rdi
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *i; // rbx
  unsigned int *v3; // rdx
  CAkList2<MapStruct<unsigned long,CAkSwitchPackage>,MapStruct<unsigned long,CAkSwitchPackage> const &,2,ArrayPoolDefault>::ListItem *v4; // rcx

  v1 = this;
  if ( this->m_SwitchList.m_ulMaxNumListItems )
  {
    for ( i = this->m_SwitchList.m_pFirst; i; i = i->pNextListItem )
    {
      v3 = i->Item.item.m_list.m_pItems;
      if ( v3 )
      {
        i->Item.item.m_list.m_uLength = 0;
        AK::MemoryMgr::Free(g_DefaultPoolId, v3);
        i->Item.item.m_list.m_pItems = 0i64;
        i->Item.item.m_list.m_ulReserved = 0;
      }
    }
    while ( 1 )
    {
      v4 = v1->m_SwitchList.m_pFirst;
      if ( !v4 )
        break;
      v1->m_SwitchList.m_pFirst = v4->pNextListItem;
      if ( v4 == v1->m_SwitchList.m_pLast )
        v1->m_SwitchList.m_pLast = 0i64;
      v4->pNextListItem = v1->m_SwitchList.m_pFree;
      --v1->m_SwitchList.m_ulNumListItems;
      v1->m_SwitchList.m_pFree = v4;
    }
  }
}

// File Line: 1309
// RVA: 0xA89840
__int64 __fastcall CAkSwitchCntr::IsContinuousPlayback(CAkSwitchCntr *this)
{
  return (unsigned __int8)(*((_BYTE *)&this->0 + 83) >> 7);
}

