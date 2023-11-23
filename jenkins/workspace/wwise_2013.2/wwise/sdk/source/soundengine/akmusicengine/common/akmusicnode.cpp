// File Line: 36
// RVA: 0xAAFBA0
void __fastcall CAkMusicNode::CAkMusicNode(CAkMusicNode *this, unsigned int in_ulID)
{
  CAkParameterNode::CAkParameterNode(this, in_ulID);
  this->m_mapChildId.m_pItems = 0i64;
  *(_QWORD *)&this->m_mapChildId.m_uLength = 0i64;
  this->vfptr = (CAkIndexableVtbl *)&CAkMusicNode::`vftable;
  *(_QWORD *)&this->m_grid.uBeatDuration = 0i64;
  *(_QWORD *)&this->m_grid.uGridDuration = 0i64;
  *((_BYTE *)this + 184) &= ~1u;
  this->m_pStingers = 0i64;
}

// File Line: 40
// RVA: 0xAAFBF0
void __fastcall CAkMusicNode::~CAkMusicNode(CAkMusicNode *this)
{
  CAkParameterNodeBase **m_pItems; // rdx

  this->vfptr = (CAkIndexableVtbl *)&CAkMusicNode::`vftable;
  CAkMusicNode::FlushStingers(this);
  this->vfptr = (CAkIndexableVtbl *)&CAkParentNode<CAkParameterNode>::`vftable;
  m_pItems = this->m_mapChildId.m_pItems;
  if ( m_pItems )
  {
    this->m_mapChildId.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_mapChildId.m_pItems = 0i64;
    this->m_mapChildId.m_ulReserved = 0;
  }
  CAkParameterNode::~CAkParameterNode(this);
}

// File Line: 45
// RVA: 0xAAFEA0
void __fastcall CAkMusicNode::FlushStingers(CAkMusicNode *this)
{
  CAkMusicNode::CAkStingers *m_pStingers; // rbx
  CAkStinger *m_pItems; // rdx
  CAkMusicNode::CAkStingers *v4; // rdx

  m_pStingers = this->m_pStingers;
  if ( m_pStingers )
  {
    m_pItems = m_pStingers->m_StingerArray.m_pItems;
    if ( m_pStingers->m_StingerArray.m_pItems )
    {
      m_pStingers->m_StingerArray.m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
      m_pStingers->m_StingerArray.m_pItems = 0i64;
      m_pStingers->m_StingerArray.m_ulReserved = 0;
    }
    v4 = this->m_pStingers;
    if ( v4 )
      AK::MemoryMgr::Free(g_DefaultPoolId, v4);
    this->m_pStingers = 0i64;
  }
}

// File Line: 55
// RVA: 0xAB0170
__int64 __fastcall CAkMusicNode::PrepareData(CAkMusicNode *this)
{
  __int64 result; // rax
  unsigned int v3; // edi

  result = ((__int64 (__fastcall *)(CAkMusicNode *))this->vfptr[21].AddRef)(this);
  if ( (_DWORD)result == 1 )
  {
    result = CAkActiveParent<CAkParameterNode>::PrepareData(this);
    v3 = result;
    if ( (_DWORD)result != 1 )
    {
      this->vfptr[21].Release(this);
      return v3;
    }
  }
  return result;
}

// File Line: 70
// RVA: 0xAB0550
void __fastcall CAkMusicNode::UnPrepareData(CAkMusicNode *this)
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
  this->vfptr[21].Release(this);
}

// File Line: 76
// RVA: 0xAB01C0
__int64 __fastcall CAkMusicNode::PrepareMusicalDependencies(CAkMusicNode *this)
{
  CAkMusicNode::CAkStingers *m_pStingers; // rbx
  CAkStinger *m_pItems; // rdi
  __int64 result; // rax
  unsigned int v4; // esi
  CAkStinger *v5; // rbx

  m_pStingers = this->m_pStingers;
  if ( !m_pStingers )
    return 1i64;
  m_pItems = m_pStingers->m_StingerArray.m_pItems;
  if ( m_pStingers->m_StingerArray.m_pItems == &m_pStingers->m_StingerArray.m_pItems[m_pStingers->m_StingerArray.m_uLength] )
    return 1i64;
  while ( 1 )
  {
    result = CAkParameterNodeBase::PrepareNodeData(m_pItems->m_SegmentID);
    v4 = result;
    if ( (_DWORD)result != 1 )
      break;
    if ( ++m_pItems == &m_pStingers->m_StingerArray.m_pItems[m_pStingers->m_StingerArray.m_uLength] )
      return 1i64;
  }
  v5 = m_pStingers->m_StingerArray.m_pItems;
  if ( v5 != m_pItems )
  {
    do
    {
      CAkParameterNodeBase::UnPrepareNodeData(v5->m_SegmentID);
      ++v5;
    }
    while ( v5 != m_pItems );
    return v4;
  }
  return result;
}

// File Line: 101
// RVA: 0xAB05B0
void __fastcall CAkMusicNode::UnPrepareMusicalDependencies(CAkMusicNode *this)
{
  CAkMusicNode::CAkStingers *m_pStingers; // rdi
  CAkStinger *i; // rbx

  m_pStingers = this->m_pStingers;
  if ( m_pStingers )
  {
    for ( i = m_pStingers->m_StingerArray.m_pItems;
          i != &m_pStingers->m_StingerArray.m_pItems[m_pStingers->m_StingerArray.m_uLength];
          ++i )
    {
      CAkParameterNodeBase::UnPrepareNodeData(i->m_SegmentID);
    }
  }
}

// File Line: 114
// RVA: 0xAB02E0
__int64 __fastcall CAkMusicNode::SetMusicNodeParams(
        CAkMusicNode *this,
        char **io_rpData,
        unsigned int *io_rulDataSize,
        bool __formal)
{
  __int64 result; // rax
  char *v8; // rcx
  char v9; // al
  char *v10; // rdx
  long double v11; // xmm1_8
  float v12; // xmm0_4
  char v13; // al
  __int64 v14; // rsi
  __int64 v15; // r14
  CAkStinger *v16; // rax
  CAkStinger *v17; // rbp
  AkSyncType *p_m_SyncPlayAt; // rdx
  int v19; // ecx
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  AKRESULT v25; // ebx
  AkMeterInfo in_pMeterInfo; // [rsp+20h] [rbp-28h] BYREF

  *io_rpData += 4;
  result = CAkParameterNodeBase::SetNodeBaseParams(this, io_rpData, io_rulDataSize, 0);
  if ( (_DWORD)result == 1 )
  {
    result = CAkParentNode<CAkParameterNode>::SetChildren(this, io_rpData, io_rulDataSize);
    if ( (_DWORD)result == 1 )
    {
      v8 = *io_rpData + 20;
      *io_rpData = v8++;
      v9 = *(v8 - 1);
      *io_rpData = v8;
      v10 = v8 + 1;
      v11 = *(double *)(v8 - 13);
      in_pMeterInfo.fGridPeriod = *(long double *)(v8 - 21);
      v12 = *(float *)(v8 - 5);
      in_pMeterInfo.fGridOffset = v11;
      in_pMeterInfo.uTimeSigNumBeatsBar = v9;
      v13 = *v8;
      *io_rpData = v8 + 1;
      in_pMeterInfo.fTempo = v12;
      LOBYTE(v8) = v8[1];
      in_pMeterInfo.uTimeSigBeatValue = v13;
      *io_rpData = v10 + 1;
      if ( (_BYTE)v8 )
        CAkMusicNode::MeterInfo(this, &in_pMeterInfo);
      v14 = *(unsigned int *)*io_rpData;
      *io_rpData += 4;
      if ( (_DWORD)v14 )
      {
        v15 = (unsigned int)v14;
        v16 = (CAkStinger *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * v14);
        v17 = v16;
        if ( !v16 )
          return 2i64;
        p_m_SyncPlayAt = &v16->m_SyncPlayAt;
        do
        {
          p_m_SyncPlayAt += 6;
          v19 = *(_DWORD *)*io_rpData;
          *io_rpData += 4;
          *((_DWORD *)p_m_SyncPlayAt - 8) = v19;
          v20 = *(_DWORD *)*io_rpData;
          *io_rpData += 4;
          *((_DWORD *)p_m_SyncPlayAt - 7) = v20;
          v21 = *(_DWORD *)*io_rpData;
          *io_rpData += 4;
          *((_DWORD *)p_m_SyncPlayAt - 6) = v21;
          v22 = *(_DWORD *)*io_rpData;
          *io_rpData += 4;
          *((_DWORD *)p_m_SyncPlayAt - 5) = v22;
          v23 = *(_DWORD *)*io_rpData;
          *io_rpData += 4;
          *((_DWORD *)p_m_SyncPlayAt - 4) = v23;
          v24 = *(_DWORD *)*io_rpData;
          *io_rpData += 4;
          *((_DWORD *)p_m_SyncPlayAt - 3) = v24;
          --v15;
        }
        while ( v15 );
        v25 = CAkMusicNode::SetStingers(this, v16, v14);
        AK::MemoryMgr::Free(g_DefaultPoolId, v17);
      }
      else
      {
        CAkMusicNode::FlushStingers(this);
        return 1;
      }
      return (unsigned int)v25;
    }
  }
  return result;
}

// File Line: 169
// RVA: 0xAB0050
void __fastcall CAkMusicNode::MeterInfo(CAkMusicNode *this, AkMeterInfo *in_pMeterInfo)
{
  double v3; // xmm3_8
  double v4; // xmm0_8
  double v5; // xmm1_8
  unsigned int v6; // ecx
  double v7; // xmm3_8
  double v8; // xmm1_8
  double v9; // xmm1_8

  if ( in_pMeterInfo )
  {
    *((_BYTE *)this + 184) |= 1u;
    v3 = 4.0
       / (double)(unsigned __int8)in_pMeterInfo->uTimeSigBeatValue
       * (60.0
        / in_pMeterInfo->fTempo)
       * (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
    v4 = DOUBLE_0_5;
    if ( v3 <= 0.0 )
      v5 = DOUBLE_N0_5;
    else
      v5 = DOUBLE_0_5;
    v6 = (int)(v5 + v3);
    this->m_grid.uBeatDuration = v6;
    this->m_grid.uBarDuration = v6 * (unsigned __int8)in_pMeterInfo->uTimeSigNumBeatsBar;
    v7 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * in_pMeterInfo->fGridPeriod * 0.001;
    if ( v7 <= 0.0 )
      v8 = DOUBLE_N0_5;
    else
      v8 = DOUBLE_0_5;
    this->m_grid.uGridDuration = (int)(v8 + v7);
    v9 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * in_pMeterInfo->fGridOffset * 0.001;
    if ( v9 <= 0.0 )
      v4 = DOUBLE_N0_5;
    this->m_grid.uGridOffset = (int)(v4 + v9);
  }
  else
  {
    *((_BYTE *)this + 184) &= ~1u;
  }
}

// File Line: 191
// RVA: 0xAAFF10
CAkParameterNodeBase **__fastcall CAkMusicNode::GetMusicGrid(CAkMusicNode *this)
{
  CAkParameterNodeBase *m_pParentNode; // rax

  if ( (*((_BYTE *)this + 184) & 1) == 0 )
  {
    while ( 1 )
    {
      m_pParentNode = this->m_pParentNode;
      if ( !m_pParentNode )
        break;
      this = (CAkMusicNode *)this->m_pParentNode;
      if ( (m_pParentNode[1].m_u16MaxNumInstance & 1) != 0 )
        return &m_pParentNode[1].m_pBusOutputNode;
    }
  }
  return (CAkParameterNodeBase **)&this->m_grid;
}

// File Line: 210
// RVA: 0xAAFD40
__int64 __fastcall CAkMusicNode::ExecuteAction(CAkMusicNode *this, ActionParams *in_rAction)
{
  unsigned int v4; // ebx

  this->vfptr->AddRef(this);
  if ( in_rAction->eType )
  {
    if ( in_rAction->eType == ActionParamType_Pause )
    {
      CAkMusicRenderer::Pause(
        CAkMusicRenderer::m_pMusicRenderer,
        this,
        in_rAction->pGameObj,
        &in_rAction->transParams,
        in_rAction->playingID);
    }
    else if ( in_rAction->eType == ActionParamType_Resume )
    {
      CAkMusicRenderer::Resume(
        CAkMusicRenderer::m_pMusicRenderer,
        this,
        in_rAction->pGameObj,
        &in_rAction->transParams,
        in_rAction->bIsMasterResume,
        in_rAction->playingID);
    }
  }
  else
  {
    CAkMusicRenderer::Stop(
      CAkMusicRenderer::m_pMusicRenderer,
      this,
      in_rAction->pGameObj,
      &in_rAction->transParams,
      in_rAction->playingID);
  }
  v4 = CAkActiveParent<CAkParameterNode>::ExecuteAction(this, in_rAction);
  this->vfptr->Release(this);
  return v4;
}

// File Line: 242
// RVA: 0xAAFDF0
__int64 __fastcall CAkMusicNode::ExecuteActionExcept(CAkMusicNode *this, ActionParamsExcept *in_rAction)
{
  unsigned int v4; // ebx

  this->vfptr->AddRef(this);
  if ( in_rAction->eType )
  {
    if ( in_rAction->eType == ActionParamType_Pause )
    {
      CAkMusicRenderer::Pause(
        CAkMusicRenderer::m_pMusicRenderer,
        this,
        in_rAction->pGameObj,
        &in_rAction->transParams,
        in_rAction->playingID);
    }
    else if ( in_rAction->eType == ActionParamType_Resume )
    {
      CAkMusicRenderer::Resume(
        CAkMusicRenderer::m_pMusicRenderer,
        this,
        in_rAction->pGameObj,
        &in_rAction->transParams,
        in_rAction->bIsMasterResume,
        in_rAction->playingID);
    }
  }
  else
  {
    CAkMusicRenderer::Stop(
      CAkMusicRenderer::m_pMusicRenderer,
      this,
      in_rAction->pGameObj,
      &in_rAction->transParams,
      in_rAction->playingID);
  }
  v4 = CAkActiveParent<CAkParameterNode>::ExecuteActionExcept(this, in_rAction);
  this->vfptr->Release(this);
  return v4;
}

// File Line: 269
// RVA: 0xAB0160
void __fastcall CAkMusicNode::ParamNotification(CAkMusicNode *this, NotifParams *in_rParams)
{
  if ( in_rParams->eType != RTPC_Pitch )
    CAkActiveParent<CAkParameterNode>::ParamNotification(this, in_rParams);
}

// File Line: 275
// RVA: 0xAAFD30
__int64 __fastcall CAkMusicSwitchCntr::NodeCategory(CAkMusicSwitchCntr *this)
{
  return 9i64;
}

// File Line: 280
// RVA: 0xAB0490
__int64 __fastcall CAkMusicNode::SetStingers(CAkMusicNode *this, CAkStinger *in_pStingers, unsigned int in_NumStingers)
{
  CAkMusicNode::CAkStingers *m_pStingers; // rax
  CAkMusicNode::CAkStingers *v7; // rax
  int v8; // ebx

  if ( in_NumStingers )
  {
    m_pStingers = this->m_pStingers;
    if ( m_pStingers )
    {
      v8 = 0;
      m_pStingers->m_StingerArray.m_uLength = 0;
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
      this->m_pStingers = v7;
      if ( !v7
        || (unsigned int)AkArray<CAkStinger,CAkStinger const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::Reserve(
                           &v7->m_StingerArray,
                           in_NumStingers) != 1 )
      {
        return 2i64;
      }
    }
    if ( !in_NumStingers )
      return 1i64;
    while ( AkArray<CAkStinger,CAkStinger const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::AddLast(
              &this->m_pStingers->m_StingerArray,
              in_pStingers++) )
    {
      if ( ++v8 >= in_NumStingers )
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
  CAkMusicNode *m_pParentNode; // rcx
  CAkMusicNode::CAkStingers *m_pStingers; // rsi
  CAkStinger *i; // rbx
  CAkStinger *m_pItems; // rax
  __int64 m_uLength; // rcx
  CAkStinger *v9; // r8

  m_pParentNode = (CAkMusicNode *)this->m_pParentNode;
  if ( m_pParentNode )
    CAkMusicNode::GetStingers(m_pParentNode, io_pStingers);
  m_pStingers = this->m_pStingers;
  if ( m_pStingers )
  {
    for ( i = m_pStingers->m_StingerArray.m_pItems;
          i != &m_pStingers->m_StingerArray.m_pItems[m_pStingers->m_StingerArray.m_uLength];
          ++i )
    {
      m_pItems = io_pStingers->m_StingerArray.m_pItems;
      while ( m_pItems != &io_pStingers->m_StingerArray.m_pItems[io_pStingers->m_StingerArray.m_uLength] )
      {
        if ( m_pItems->m_TriggerID == i->m_TriggerID )
        {
          m_uLength = io_pStingers->m_StingerArray.m_uLength;
          if ( (unsigned int)m_uLength > 1 )
          {
            v9 = &io_pStingers->m_StingerArray.m_pItems[m_uLength];
            m_pItems->m_TriggerID = v9[-1].m_TriggerID;
            m_pItems->m_SegmentID = v9[-1].m_SegmentID;
            m_pItems->m_SyncPlayAt = v9[-1].m_SyncPlayAt;
            m_pItems->m_uCueFilterHash = v9[-1].m_uCueFilterHash;
            m_pItems->m_DontRepeatTime = v9[-1].m_DontRepeatTime;
            m_pItems->m_numSegmentLookAhead = v9[-1].m_numSegmentLookAhead;
          }
          --io_pStingers->m_StingerArray.m_uLength;
        }
        else
        {
          ++m_pItems;
        }
      }
      AkArray<CAkStinger,CAkStinger const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::AddLast(
        &io_pStingers->m_StingerArray,
        i);
    }
  }
}

