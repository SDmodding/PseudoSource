// File Line: 36
// RVA: 0xAAFBA0
void __fastcall CAkMusicNode::CAkMusicNode(CAkMusicNode *this, unsigned int in_ulID)
{
  CAkMusicNode *v2; // rbx

  v2 = this;
  CAkParameterNode::CAkParameterNode((CAkParameterNode *)&this->vfptr, in_ulID);
  v2->m_mapChildId.m_pItems = 0i64;
  *(_QWORD *)&v2->m_mapChildId.m_uLength = 0i64;
  v2->vfptr = (CAkIndexableVtbl *)&CAkMusicNode::`vftable';
  *(_QWORD *)&v2->m_grid.uBeatDuration = 0i64;
  *(_QWORD *)&v2->m_grid.uGridDuration = 0i64;
  *((_BYTE *)v2 + 184) &= 0xFEu;
  v2->m_pStingers = 0i64;
}

// File Line: 40
// RVA: 0xAAFBF0
void __fastcall CAkMusicNode::~CAkMusicNode(CAkMusicNode *this)
{
  CAkMusicNode *v1; // rbx
  CAkParameterNodeBase **v2; // rdx

  v1 = this;
  this->vfptr = (CAkIndexableVtbl *)&CAkMusicNode::`vftable';
  CAkMusicNode::FlushStingers(this);
  v1->vfptr = (CAkIndexableVtbl *)&CAkParentNode<CAkParameterNode>::`vftable';
  v2 = v1->m_mapChildId.m_pItems;
  if ( v2 )
  {
    v1->m_mapChildId.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v2);
    v1->m_mapChildId.m_pItems = 0i64;
    v1->m_mapChildId.m_ulReserved = 0;
  }
  CAkParameterNode::~CAkParameterNode((CAkParameterNode *)&v1->vfptr);
}

// File Line: 45
// RVA: 0xAAFEA0
void __fastcall CAkMusicNode::FlushStingers(CAkMusicNode *this)
{
  CAkMusicNode::CAkStingers *v1; // rbx
  CAkMusicNode *v2; // rdi
  CAkStinger *v3; // rdx
  CAkMusicNode::CAkStingers *v4; // rdx

  v1 = this->m_pStingers;
  v2 = this;
  if ( v1 )
  {
    v3 = v1->m_StingerArray.m_pItems;
    if ( v1->m_StingerArray.m_pItems )
    {
      v1->m_StingerArray.m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, v3);
      v1->m_StingerArray.m_pItems = 0i64;
      v1->m_StingerArray.m_ulReserved = 0;
    }
    v4 = v2->m_pStingers;
    if ( v4 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v4);
    v2->m_pStingers = 0i64;
  }
}

// File Line: 55
// RVA: 0xAB0170
__int64 __fastcall CAkMusicNode::PrepareData(CAkMusicNode *this)
{
  CAkMusicNode *v1; // rbx
  __int64 result; // rax
  unsigned int v3; // edi

  v1 = this;
  result = ((__int64 (*)(void))this->vfptr[21].AddRef)();
  if ( (_DWORD)result == 1 )
  {
    result = CAkActiveParent<CAkParameterNode>::PrepareData((CAkActiveParent<CAkParameterNode> *)&v1->vfptr);
    v3 = result;
    if ( (_DWORD)result != 1 )
    {
      v1->vfptr[21].Release((CAkIndexable *)&v1->vfptr);
      result = v3;
    }
  }
  return result;
}

// File Line: 70
// RVA: 0xAB0550
void __fastcall CAkMusicNode::UnPrepareData(CAkMusicNode *this)
{
  CAkParameterNodeBase **v1; // rbx
  CAkMusicNode *v2; // rdi

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
  v2->vfptr[21].Release((CAkIndexable *)&v2->vfptr);
}

// File Line: 76
// RVA: 0xAB01C0
__int64 __fastcall CAkMusicNode::PrepareMusicalDependencies(CAkMusicNode *this)
{
  CAkMusicNode::CAkStingers *v1; // rbx
  CAkStinger *v2; // rdi
  __int64 result; // rax
  unsigned int v4; // esi
  CAkStinger *v5; // rbx

  v1 = this->m_pStingers;
  if ( !v1 )
    return 1i64;
  v2 = v1->m_StingerArray.m_pItems;
  if ( v1->m_StingerArray.m_pItems == &v1->m_StingerArray.m_pItems[v1->m_StingerArray.m_uLength] )
    return 1i64;
  while ( 1 )
  {
    result = CAkParameterNodeBase::PrepareNodeData(v2->m_SegmentID);
    v4 = result;
    if ( (_DWORD)result != 1 )
      break;
    ++v2;
    if ( v2 == &v1->m_StingerArray.m_pItems[v1->m_StingerArray.m_uLength] )
      return (unsigned int)result;
  }
  v5 = v1->m_StingerArray.m_pItems;
  if ( v5 != v2 )
  {
    do
    {
      CAkParameterNodeBase::UnPrepareNodeData(v5->m_SegmentID);
      ++v5;
    }
    while ( v5 != v2 );
    result = v4;
  }
  return result;
}

// File Line: 101
// RVA: 0xAB05B0
void __fastcall CAkMusicNode::UnPrepareMusicalDependencies(CAkMusicNode *this)
{
  CAkMusicNode::CAkStingers *v1; // rdi
  CAkStinger *i; // rbx

  v1 = this->m_pStingers;
  if ( v1 )
  {
    for ( i = v1->m_StingerArray.m_pItems; i != &v1->m_StingerArray.m_pItems[v1->m_StingerArray.m_uLength]; ++i )
      CAkParameterNodeBase::UnPrepareNodeData(i->m_SegmentID);
  }
}

// File Line: 114
// RVA: 0xAB02E0
__int64 __fastcall CAkMusicNode::SetMusicNodeParams(CAkMusicNode *this, char **io_rpData, unsigned int *io_rulDataSize, bool __formal)
{
  unsigned int *v4; // rsi
  char **v5; // rbx
  CAkMusicNode *v6; // rdi
  __int64 result; // rax
  char *v8; // rcx
  char v9; // al
  signed __int64 v10; // rdx
  long double v11; // xmm1_8
  float v12; // xmm0_4
  char v13; // al
  __int64 v14; // rsi
  __int64 v15; // r14
  CAkStinger *v16; // rax
  CAkStinger *v17; // rbp
  signed __int64 v18; // rdx
  int v19; // ecx
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  AKRESULT v25; // ebx
  AkMeterInfo in_pMeterInfo; // [rsp+20h] [rbp-28h]

  *io_rpData += 4;
  v4 = io_rulDataSize;
  v5 = io_rpData;
  v6 = this;
  result = CAkParameterNodeBase::SetNodeBaseParams((CAkParameterNodeBase *)&this->vfptr, io_rpData, io_rulDataSize, 0);
  if ( (_DWORD)result == 1 )
  {
    result = CAkParentNode<CAkParameterNode>::SetChildren((CAkParentNode<CAkParameterNode> *)&v6->vfptr, v5, v4);
    if ( (_DWORD)result == 1 )
    {
      v8 = *v5 + 20;
      *v5 = v8++;
      v9 = *(v8 - 1);
      *v5 = v8;
      v10 = (signed __int64)(v8 + 1);
      v11 = *(double *)(v8 - 13);
      in_pMeterInfo.fGridPeriod = *(long double *)(v8 - 21);
      v12 = *(float *)(v8 - 5);
      in_pMeterInfo.fGridOffset = v11;
      in_pMeterInfo.uTimeSigNumBeatsBar = v9;
      v13 = *v8;
      *v5 = v8 + 1;
      in_pMeterInfo.fTempo = v12;
      LOBYTE(v8) = v8[1];
      in_pMeterInfo.uTimeSigBeatValue = v13;
      *v5 = (char *)(v10 + 1);
      if ( (_BYTE)v8 )
        CAkMusicNode::MeterInfo(v6, &in_pMeterInfo);
      v14 = *(unsigned int *)*v5;
      *v5 += 4;
      if ( (_DWORD)v14 )
      {
        v15 = (unsigned int)v14;
        v16 = (CAkStinger *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * v14);
        v17 = v16;
        if ( !v16 )
          return 2i64;
        if ( (_DWORD)v14 )
        {
          v18 = (signed __int64)&v16->m_SyncPlayAt;
          do
          {
            v18 += 24i64;
            v19 = *(_DWORD *)*v5;
            *v5 += 4;
            *(_DWORD *)(v18 - 32) = v19;
            v20 = *(_DWORD *)*v5;
            *v5 += 4;
            *(_DWORD *)(v18 - 28) = v20;
            v21 = *(_DWORD *)*v5;
            *v5 += 4;
            *(_DWORD *)(v18 - 24) = v21;
            v22 = *(_DWORD *)*v5;
            *v5 += 4;
            *(_DWORD *)(v18 - 20) = v22;
            v23 = *(_DWORD *)*v5;
            *v5 += 4;
            *(_DWORD *)(v18 - 16) = v23;
            v24 = *(_DWORD *)*v5;
            *v5 += 4;
            *(_DWORD *)(v18 - 12) = v24;
            --v15;
          }
          while ( v15 );
        }
        v25 = CAkMusicNode::SetStingers(v6, v16, v14);
        AK::MemoryMgr::Free(g_DefaultPoolId, v17);
      }
      else
      {
        CAkMusicNode::FlushStingers(v6);
        v25 = 1;
      }
      result = (unsigned int)v25;
    }
  }
  return result;
}

// File Line: 169
// RVA: 0xAB0050
void __fastcall CAkMusicNode::MeterInfo(CAkMusicNode *this, AkMeterInfo *in_pMeterInfo)
{
  CAkMusicNode *v2; // r8
  double v3; // xmm3_8
  double v4; // xmm0_8
  double v5; // xmm1_8
  signed int v6; // ecx
  double v7; // xmm3_8
  double v8; // xmm1_8
  double v9; // xmm1_8

  v2 = this;
  if ( in_pMeterInfo )
  {
    *((_BYTE *)this + 184) |= 1u;
    v3 = 4.0
       / (double)(unsigned __int8)in_pMeterInfo->uTimeSigBeatValue
       * (60.0
        / in_pMeterInfo->fTempo)
       * (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
    v4 = DOUBLE_0_5;
    if ( v3 <= 0.0 )
      v5 = DOUBLE_N0_5;
    else
      v5 = DOUBLE_0_5;
    v6 = (signed int)(v5 + v3);
    v2->m_grid.uBeatDuration = v6;
    v2->m_grid.uBarDuration = v6 * (unsigned __int8)in_pMeterInfo->uTimeSigNumBeatsBar;
    v7 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * in_pMeterInfo->fGridPeriod * 0.001;
    if ( v7 <= 0.0 )
      v8 = DOUBLE_N0_5;
    else
      v8 = DOUBLE_0_5;
    v2->m_grid.uGridDuration = (signed int)(v8 + v7);
    v9 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * in_pMeterInfo->fGridOffset * 0.001;
    if ( v9 <= 0.0 )
      v4 = DOUBLE_N0_5;
    v2->m_grid.uGridOffset = (signed int)(v4 + v9);
  }
  else
  {
    *((_BYTE *)this + 184) &= 0xFEu;
  }
}

// File Line: 191
// RVA: 0xAAFF10
CAkParameterNodeBase **__fastcall CAkMusicNode::GetMusicGrid(CAkMusicNode *this)
{
  CAkParameterNodeBase *v1; // rax

  if ( !(*((_BYTE *)this + 184) & 1) )
  {
    while ( 1 )
    {
      v1 = this->m_pParentNode;
      if ( !v1 )
        break;
      this = (CAkMusicNode *)this->m_pParentNode;
      if ( v1[1].m_u16MaxNumInstance & 1 )
        return &v1[1].m_pBusOutputNode;
    }
  }
  return (CAkParameterNodeBase **)&this->m_grid;
}

// File Line: 210
// RVA: 0xAAFD40
__int64 __fastcall CAkMusicNode::ExecuteAction(CAkMusicNode *this, ActionParams *in_rAction)
{
  ActionParams *v2; // rbx
  CAkMusicNode *v3; // rdi
  unsigned int v4; // ebx

  v2 = in_rAction;
  v3 = this;
  ((void (*)(void))this->vfptr->AddRef)();
  if ( v2->eType )
  {
    if ( v2->eType == 1 )
    {
      CAkMusicRenderer::Pause(CAkMusicRenderer::m_pMusicRenderer, v3, v2->pGameObj, &v2->transParams, v2->playingID);
    }
    else if ( v2->eType == 2 )
    {
      CAkMusicRenderer::Resume(
        CAkMusicRenderer::m_pMusicRenderer,
        v3,
        v2->pGameObj,
        &v2->transParams,
        v2->bIsMasterResume,
        v2->playingID);
    }
  }
  else
  {
    CAkMusicRenderer::Stop(CAkMusicRenderer::m_pMusicRenderer, v3, v2->pGameObj, &v2->transParams, v2->playingID);
  }
  v4 = CAkActiveParent<CAkParameterNode>::ExecuteAction((CAkActiveParent<CAkParameterNode> *)&v3->vfptr, v2);
  v3->vfptr->Release((CAkIndexable *)&v3->vfptr);
  return v4;
}

// File Line: 242
// RVA: 0xAAFDF0
__int64 __fastcall CAkMusicNode::ExecuteActionExcept(CAkMusicNode *this, ActionParamsExcept *in_rAction)
{
  ActionParamsExcept *v2; // rbx
  CAkMusicNode *v3; // rdi
  unsigned int v4; // ebx

  v2 = in_rAction;
  v3 = this;
  ((void (*)(void))this->vfptr->AddRef)();
  if ( v2->eType )
  {
    if ( v2->eType == 1 )
    {
      CAkMusicRenderer::Pause(CAkMusicRenderer::m_pMusicRenderer, v3, v2->pGameObj, &v2->transParams, v2->playingID);
    }
    else if ( v2->eType == 2 )
    {
      CAkMusicRenderer::Resume(
        CAkMusicRenderer::m_pMusicRenderer,
        v3,
        v2->pGameObj,
        &v2->transParams,
        v2->bIsMasterResume,
        v2->playingID);
    }
  }
  else
  {
    CAkMusicRenderer::Stop(CAkMusicRenderer::m_pMusicRenderer, v3, v2->pGameObj, &v2->transParams, v2->playingID);
  }
  v4 = CAkActiveParent<CAkParameterNode>::ExecuteActionExcept((CAkActiveParent<CAkParameterNode> *)&v3->vfptr, v2);
  v3->vfptr->Release((CAkIndexable *)&v3->vfptr);
  return v4;
}

// File Line: 269
// RVA: 0xAB0160
void __fastcall CAkMusicNode::ParamNotification(CAkMusicNode *this, NotifParams *in_rParams)
{
  JUMPOUT(in_rParams->eType, 2, CAkActiveParent<CAkParameterNode>::ParamNotification);
}

// File Line: 275
// RVA: 0xAAFD30
signed __int64 __fastcall CAkMusicSwitchCntr::NodeCategory(CAkMusicSwitchCntr *this)
{
  return 9i64;
}

// File Line: 280
// RVA: 0xAB0490
signed __int64 __fastcall CAkMusicNode::SetStingers(CAkMusicNode *this, CAkStinger *in_pStingers, unsigned int in_NumStingers)
{
  unsigned int v3; // edi
  CAkStinger *v4; // rsi
  CAkMusicNode *v5; // rbp
  CAkMusicNode::CAkStingers *v6; // rax
  CAkMusicNode::CAkStingers *v7; // rax
  int v8; // ebx
  CAkStinger *v10; // rax

  v3 = in_NumStingers;
  v4 = in_pStingers;
  v5 = this;
  if ( in_NumStingers )
  {
    v6 = this->m_pStingers;
    if ( v6 )
    {
      v8 = 0;
      v6->m_StingerArray.m_uLength = 0;
    }
    else
    {
      v7 = (CAkMusicNode::CAkStingers *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x10ui64);
      v8 = 0;
      if ( v7 )
      {
        v7->m_StingerArray.m_pItems = 0i64;
        *(_QWORD *)&v7->m_StingerArray.m_uLength = 0i64;
      }
      else
      {
        v7 = 0i64;
      }
      v5->m_pStingers = v7;
      if ( !v7
        || (unsigned int)AkArray<CAkStinger,CAkStinger const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::Reserve(
                           &v7->m_StingerArray,
                           v3) != 1 )
      {
        return 2i64;
      }
    }
    if ( !v3 )
      return 1i64;
    while ( 1 )
    {
      v10 = AkArray<CAkStinger,CAkStinger const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::AddLast(
              &v5->m_pStingers->m_StingerArray,
              v4);
      ++v4;
      if ( !v10 )
        break;
      if ( ++v8 >= v3 )
        return 1i64;
    }
    return 2i64;
  }
  CAkMusicNode::FlushStingers(this);
  return 1i64;
}

// File Line: 309
// RVA: 0xAAFF50
void __fastcall CAkMusicNode::GetStingers(CAkMusicNode *this, CAkMusicNode::CAkStingers *io_pStingers)
{
  CAkMusicNode *v2; // rbx
  CAkMusicNode *v3; // rcx
  CAkMusicNode::CAkStingers *v4; // rdi
  CAkMusicNode::CAkStingers *v5; // rsi
  CAkStinger *i; // rbx
  CAkStinger *v7; // rax
  __int64 v8; // rcx
  signed __int64 v9; // r8

  v2 = this;
  v3 = (CAkMusicNode *)this->m_pParentNode;
  v4 = io_pStingers;
  if ( v3 )
    CAkMusicNode::GetStingers(v3, io_pStingers);
  v5 = v2->m_pStingers;
  if ( v5 )
  {
    for ( i = v5->m_StingerArray.m_pItems; i != &v5->m_StingerArray.m_pItems[v5->m_StingerArray.m_uLength]; ++i )
    {
      v7 = v4->m_StingerArray.m_pItems;
      while ( v7 != &v4->m_StingerArray.m_pItems[v4->m_StingerArray.m_uLength] )
      {
        if ( v7->m_TriggerID == i->m_TriggerID )
        {
          v8 = v4->m_StingerArray.m_uLength;
          if ( (unsigned int)v8 > 1 )
          {
            v9 = (signed __int64)&v4->m_StingerArray.m_pItems[v8];
            v7->m_TriggerID = *(_DWORD *)(v9 - 24);
            v7->m_SegmentID = *(_DWORD *)(v9 - 20);
            v7->m_SyncPlayAt = *(_DWORD *)(v9 - 16);
            v7->m_uCueFilterHash = *(_DWORD *)(v9 - 12);
            v7->m_DontRepeatTime = *(_DWORD *)(v9 - 8);
            v7->m_numSegmentLookAhead = *(_DWORD *)(v9 - 4);
          }
          --v4->m_StingerArray.m_uLength;
        }
        else
        {
          ++v7;
        }
      }
      AkArray<CAkStinger,CAkStinger const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::AddLast(&v4->m_StingerArray, i);
    }
  }
}

