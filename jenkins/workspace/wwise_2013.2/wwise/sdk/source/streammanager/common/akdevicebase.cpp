// File Line: 50
// RVA: 0xAA27C0
void __fastcall AK::StreamMgr::CAkDeviceBase::CAkDeviceBase(
        AK::StreamMgr::CAkDeviceBase *this,
        AK::StreamMgr::IAkLowLevelIOHook *in_pLowLevelHook)
{
  AK::StreamMgr::CAkIOThread::CAkIOThread(this);
  this->vfptr = (AK::StreamMgr::CAkIOThreadVtbl *)&AK::StreamMgr::CAkDeviceBase::`vftable;
  this->m_listTasks.m_pFirst = 0i64;
  InitializeCriticalSection(&this->m_lockTasksList.m_csLock);
  AK::StreamMgr::CAkIOMemMgr::CAkIOMemMgr(&this->m_mgrMemIO);
  this->m_pLowLevelHook = in_pLowLevelHook;
  this->m_poolStmMemView.m_pFirst = 0i64;
  this->m_pStmMemViewMem = 0i64;
}

// File Line: 54
// RVA: 0xAA2920
void __fastcall AK::StreamMgr::CAkDeviceBase::~CAkDeviceBase(AK::StreamMgr::CAkDeviceBase *this)
{
  AK::StreamMgr::CAkIOMemMgr *p_m_mgrMemIO; // rcx

  p_m_mgrMemIO = &this->m_mgrMemIO;
  *(_QWORD *)&p_m_mgrMemIO[-3].m_bUseCache = &AK::StreamMgr::CAkDeviceBase::`vftable;
  AK::StreamMgr::CAkIOMemMgr::~CAkIOMemMgr(p_m_mgrMemIO);
  DeleteCriticalSection(&this->m_lockTasksList.m_csLock);
  AK::StreamMgr::CAkIOThread::~CAkIOThread(this);
}

// File Line: 62
// RVA: 0xAA3E00
AKRESULT __fastcall AK::StreamMgr::CAkDeviceBase::Init(
        AK::StreamMgr::CAkDeviceBase *this,
        AkDeviceSettings *in_settings,
        unsigned int in_deviceID)
{
  unsigned int uGranularity; // ecx
  unsigned int uMaxConcurrentIO; // eax

  uGranularity = in_settings->uGranularity;
  if ( !uGranularity
    || in_settings->uIOMemorySize && in_settings->fTargetAutoStmBufferLength < 0.0
    || (in_settings->uSchedulerTypeFlags & 2) != 0 && in_settings->uMaxConcurrentIO - 1 > 0x3FF )
  {
    return 31;
  }
  this->m_uGranularity = uGranularity;
  this->m_fTargetAutoStmBufferLength = in_settings->fTargetAutoStmBufferLength;
  uMaxConcurrentIO = in_settings->uMaxConcurrentIO;
  this->m_deviceID = in_deviceID;
  this->m_uMaxConcurrentIO = uMaxConcurrentIO;
  if ( AK::StreamMgr::CAkIOMemMgr::Init(&this->m_mgrMemIO, in_settings) == AK_Success )
    return AK::StreamMgr::CAkIOThread::Init(this, &in_settings->threadProperties);
  else
    return 2;
}

// File Line: 99
// RVA: 0xAA3000
void __fastcall AK::StreamMgr::CAkDeviceBase::Destroy(AK::StreamMgr::CAkDeviceBase *this)
{
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rax
  AK::StreamMgr::CAkStmMemView **v3; // rdx
  AK::StreamMgr::CAkStmMemView *pNextView; // rcx
  int v5; // ebx
  __int128 v6; // [rsp+20h] [rbp-38h]
  __int128 v7; // [rsp+30h] [rbp-28h]
  __int128 v8; // [rsp+40h] [rbp-18h]

  AK::StreamMgr::CAkIOThread::Term(this);
  if ( this->m_pStmMemViewMem )
  {
    if ( this->m_mgrMemIO.m_bUseCache )
    {
      m_pFirst = this->m_poolStmMemView.m_pFirst;
      v3 = 0i64;
      if ( m_pFirst )
      {
        while ( 1 )
        {
          pNextView = m_pFirst->pNextView;
          if ( (*((_DWORD *)m_pFirst + 5) & 8) != 0 )
          {
            *(_QWORD *)&v8 = m_pFirst->pNextView;
            *((_QWORD *)&v8 + 1) = v3;
            if ( m_pFirst == this->m_poolStmMemView.m_pFirst )
              this->m_poolStmMemView.m_pFirst = pNextView;
            else
              *v3 = pNextView;
            v6 = v8;
          }
          else
          {
            *(_QWORD *)&v7 = m_pFirst->pNextView;
            *((_QWORD *)&v7 + 1) = v3;
            if ( m_pFirst == this->m_poolStmMemView.m_pFirst )
              this->m_poolStmMemView.m_pFirst = pNextView;
            else
              *v3 = pNextView;
            v6 = v7;
            if ( m_pFirst )
              AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, m_pFirst);
          }
          m_pFirst = (AK::StreamMgr::CAkStmMemView *)v6;
          if ( !(_QWORD)v6 )
            break;
          v3 = (AK::StreamMgr::CAkStmMemView **)*((_QWORD *)&v6 + 1);
        }
      }
    }
    else
    {
      this->m_poolStmMemView.m_pFirst = 0i64;
    }
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, this->m_pStmMemViewMem);
  }
  this->m_poolStmMemView.m_pFirst = 0i64;
  AK::StreamMgr::CAkIOMemMgr::Term(&this->m_mgrMemIO);
  v5 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
  this->vfptr->__vecDelDtor(this, 0i64);
  AK::MemoryMgr::Free(v5, this);
}

// File Line: 144
// RVA: 0xAA2E70
char __fastcall AK::StreamMgr::CAkDeviceBase::ClearStreams(AK::StreamMgr::CAkDeviceBase *this)
{
  AK::StreamMgr::CAkStmTask *m_pFirst; // rbx
  AK::StreamMgr::CAkStmTask *v2; // rdi
  AK::StreamMgr::CAkClientThreadAwareVtbl *vfptr; // rax
  AK::StreamMgr::CAkStmTask *pNextLightItem; // rax
  int v6; // edi
  AK::StreamMgr::CAkStmTask *v8; // [rsp+20h] [rbp-28h]
  AK::StreamMgr::CAkStmTask *v9; // [rsp+28h] [rbp-20h]

  m_pFirst = this->m_listTasks.m_pFirst;
  v2 = 0i64;
  while ( m_pFirst )
  {
    vfptr = m_pFirst->vfptr;
    if ( (*((_BYTE *)m_pFirst + 117) & 8) != 0 )
    {
      if ( ((unsigned __int8 (__fastcall *)(AK::StreamMgr::CAkStmTask *))vfptr[1].__vecDelDtor)(m_pFirst) )
      {
        pNextLightItem = m_pFirst->pNextLightItem;
        v9 = v2;
        v8 = pNextLightItem;
        if ( m_pFirst == this->m_listTasks.m_pFirst )
          this->m_listTasks.m_pFirst = pNextLightItem;
        else
          v2->pNextLightItem = pNextLightItem;
        v6 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
        m_pFirst->vfptr->__vecDelDtor(m_pFirst, 0);
        AK::MemoryMgr::Free(v6, m_pFirst);
        v2 = v9;
        m_pFirst = v8;
        continue;
      }
    }
    else
    {
      ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *))vfptr[2].__vecDelDtor)(m_pFirst);
    }
    v2 = m_pFirst;
    m_pFirst = m_pFirst->pNextLightItem;
  }
  if ( this->m_listTasks.m_pFirst )
    return 0;
  this->m_listTasks.m_pFirst = 0i64;
  return 1;
}

// File Line: 180
// RVA: 0xAA40A0
void __fastcall AK::StreamMgr::CAkDeviceBase::OnThreadStart(AK::StreamMgr::CAkDeviceBase *this)
{
  QueryPerformanceCounter((LARGE_INTEGER *)&this->m_time);
}

// File Line: 190
// RVA: 0xAA2E10
void __fastcall AK::StreamMgr::CAkDeviceBase::AddTask(
        AK::StreamMgr::CAkDeviceBase *this,
        AK::StreamMgr::CAkStmTask *in_pStmTask)
{
  AK::StreamMgr::CAkStmTask *m_pFirst; // rax

  EnterCriticalSection(&this->m_lockTasksList.m_csLock);
  m_pFirst = this->m_listTasks.m_pFirst;
  if ( m_pFirst )
  {
    in_pStmTask->pNextLightItem = m_pFirst;
    this->m_listTasks.m_pFirst = in_pStmTask;
  }
  else
  {
    this->m_listTasks.m_pFirst = in_pStmTask;
    in_pStmTask->pNextLightItem = 0i64;
  }
  LeaveCriticalSection(&this->m_lockTasksList.m_csLock);
}

// File Line: 216
// RVA: 0xAA4500
AK::StreamMgr::CAkStmTask *__fastcall AK::StreamMgr::CAkDeviceBase::SchedulerFindNextTask(
        AK::StreamMgr::CAkDeviceBase *this,
        float *out_fOpDeadline)
{
  AK::StreamMgr::CAkStmTask *v4; // r12
  __int128 m_pFirst; // rdi
  char v7; // al
  AK::StreamMgr::CAkStmTask *v8; // rax
  double v9; // xmm0_8
  __int64 v10; // rbp
  float v11; // xmm6_4
  bool v12; // r14
  char v13; // al
  AK::StreamMgr::CAkStmTask *v14; // rax
  int v15; // ebp
  double v16; // xmm0_8
  bool v17; // dl
  char v18; // al
  char v19; // cl
  __int128 v20; // [rsp+30h] [rbp-68h]
  AK::StreamMgr::CAkStmTask *v21; // [rsp+30h] [rbp-68h]
  __int64 v22; // [rsp+38h] [rbp-60h]

  EnterCriticalSection(&this->m_lockTasksList.m_csLock);
  QueryPerformanceCounter((LARGE_INTEGER *)&this->m_time);
  if ( !this->m_bDoWaitMemoryChange )
  {
    v4 = 0i64;
    m_pFirst = (unsigned __int64)this->m_listTasks.m_pFirst;
    if ( !(_QWORD)m_pFirst )
      goto LABEL_3;
    while ( 1 )
    {
      v7 = *(_BYTE *)(m_pFirst + 117);
      if ( (v7 & 8) != 0 )
      {
        if ( (*(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)m_pFirst + 8i64))(m_pFirst) )
        {
          v8 = *(AK::StreamMgr::CAkStmTask **)(m_pFirst + 24);
          *((_QWORD *)&v20 + 1) = *((_QWORD *)&m_pFirst + 1);
          *(_QWORD *)&v20 = v8;
          if ( (AK::StreamMgr::CAkStmTask *)m_pFirst == this->m_listTasks.m_pFirst )
            this->m_listTasks.m_pFirst = v8;
          else
            *(_QWORD *)(*((_QWORD *)&m_pFirst + 1) + 24i64) = v8;
          DWORD2(m_pFirst) = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
          (**(void (__fastcall ***)(_QWORD, _QWORD))m_pFirst)(m_pFirst, 0i64);
          AK::MemoryMgr::Free(SDWORD2(m_pFirst), (void *)m_pFirst);
          m_pFirst = v20;
          goto LABEL_15;
        }
      }
      else if ( (v7 & 0x40) != 0 )
      {
        v9 = (*(double (__fastcall **)(_QWORD))(*(_QWORD *)m_pFirst + 48i64))(m_pFirst);
        *((_QWORD *)&m_pFirst + 1) = *(_QWORD *)(m_pFirst + 24);
        v10 = m_pFirst;
        v11 = *(float *)&v9;
        v12 = (*(_BYTE *)(m_pFirst + 117) & 0x20) != 0;
        if ( !*((_QWORD *)&m_pFirst + 1) )
        {
LABEL_40:
          *out_fOpDeadline = v11;
          if ( !v12 )
            goto LABEL_5;
          goto LABEL_4;
        }
        while ( 2 )
        {
          v13 = *(_BYTE *)(*((_QWORD *)&m_pFirst + 1) + 117i64);
          if ( (v13 & 8) != 0 )
          {
            if ( (*(unsigned __int8 (__fastcall **)(_QWORD))(**((_QWORD **)&m_pFirst + 1) + 8i64))(*((_QWORD *)&m_pFirst + 1)) )
            {
              v14 = *(AK::StreamMgr::CAkStmTask **)(*((_QWORD *)&m_pFirst + 1) + 24i64);
              v22 = v10;
              v21 = v14;
              if ( (AK::StreamMgr::CAkStmTask *)*((_QWORD *)&m_pFirst + 1) == this->m_listTasks.m_pFirst )
                this->m_listTasks.m_pFirst = v14;
              else
                *(_QWORD *)(v10 + 24) = v14;
              v15 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
              (***((void (__fastcall ****)(_QWORD, _QWORD))&m_pFirst + 1))(*((_QWORD *)&m_pFirst + 1), 0i64);
              AK::MemoryMgr::Free(v15, *((void **)&m_pFirst + 1));
              v10 = v22;
              *((_QWORD *)&m_pFirst + 1) = v21;
LABEL_39:
              if ( !*((_QWORD *)&m_pFirst + 1) )
                goto LABEL_40;
              continue;
            }
LABEL_38:
            v10 = *((_QWORD *)&m_pFirst + 1);
            *((_QWORD *)&m_pFirst + 1) = *(_QWORD *)(*((_QWORD *)&m_pFirst + 1) + 24i64);
            goto LABEL_39;
          }
          break;
        }
        if ( (v13 & 0x40) == 0 )
          goto LABEL_38;
        v16 = (*(double (__fastcall **)(_QWORD))(**((_QWORD **)&m_pFirst + 1) + 48i64))(*((_QWORD *)&m_pFirst + 1));
        if ( v12 )
        {
          v17 = (*(_BYTE *)(*((_QWORD *)&m_pFirst + 1) + 117i64) & 0x20) != 0;
          if ( (*(_BYTE *)(*((_QWORD *)&m_pFirst + 1) + 117i64) & 0x20) == 0 )
            goto LABEL_38;
        }
        else
        {
          v17 = (*(_BYTE *)(*((_QWORD *)&m_pFirst + 1) + 117i64) & 0x20) != 0;
          if ( (*(_BYTE *)(*((_QWORD *)&m_pFirst + 1) + 117i64) & 0x20) != 0 )
          {
            v12 = 1;
            goto LABEL_37;
          }
        }
        if ( *(float *)&v16 == 0.0 )
        {
          v18 = *(_BYTE *)(*((_QWORD *)&m_pFirst + 1) + 116i64);
          v19 = *(_BYTE *)(m_pFirst + 116);
          if ( v18 <= v19
            && v11 <= 0.0
            && (v18 != v19
             || (float)((float)(int)(this->m_time - *(_DWORD *)(*((_QWORD *)&m_pFirst + 1) + 88i64))
                      * (float)(1.0 / AK::g_fFreqRatio)) <= (float)((float)(int)(this->m_time
                                                                               - *(_DWORD *)(m_pFirst + 88))
                                                                  * (float)(1.0 / AK::g_fFreqRatio))) )
          {
            goto LABEL_38;
          }
        }
        else if ( *(float *)&v16 >= v11 )
        {
          goto LABEL_38;
        }
        v12 = v17;
LABEL_37:
        v11 = *(float *)&v16;
        *(_QWORD *)&m_pFirst = *((_QWORD *)&m_pFirst + 1);
        goto LABEL_38;
      }
      *((_QWORD *)&m_pFirst + 1) = m_pFirst;
      *(_QWORD *)&m_pFirst = *(_QWORD *)(m_pFirst + 24);
LABEL_15:
      if ( !(_QWORD)m_pFirst )
        goto LABEL_3;
    }
  }
  v4 = AK::StreamMgr::CAkDeviceBase::ScheduleStdStmOnly(this, out_fOpDeadline);
LABEL_3:
  *(_QWORD *)&m_pFirst = v4;
LABEL_4:
  v4 = (AK::StreamMgr::CAkStmTask *)m_pFirst;
LABEL_5:
  LeaveCriticalSection(&this->m_lockTasksList.m_csLock);
  return v4;
}

// File Line: 378
// RVA: 0xAA42E0
AK::StreamMgr::CAkStmTask *__fastcall AK::StreamMgr::CAkDeviceBase::ScheduleStdStmOnly(
        AK::StreamMgr::CAkDeviceBase *this,
        float *out_fOpDeadline)
{
  AK::StreamMgr::CAkStmTask *m_pFirst; // rbx
  AK::StreamMgr::CAkStmTask *v3; // rdi
  char v6; // al
  AK::StreamMgr::CAkStmTask *pNextLightItem; // rax
  int v8; // edi
  double v10; // xmm0_8
  __int128 v11; // rdi
  float v12; // xmm6_4
  char v13; // al
  AK::StreamMgr::CAkStmTask *v14; // rax
  double v15; // xmm0_8
  char v16; // al
  char m_priority; // cl
  AK::StreamMgr::CAkStmTask *v18; // [rsp+30h] [rbp-48h]
  __int128 v19; // [rsp+30h] [rbp-48h]
  AK::StreamMgr::CAkStmTask *v20; // [rsp+38h] [rbp-40h]

  m_pFirst = this->m_listTasks.m_pFirst;
  v3 = 0i64;
  if ( !m_pFirst )
    return 0i64;
  while ( 1 )
  {
    v6 = *((_BYTE *)m_pFirst + 117);
    if ( (v6 & 8) == 0 )
      break;
    if ( ((unsigned __int8 (__fastcall *)(AK::StreamMgr::CAkStmTask *))m_pFirst->vfptr[1].__vecDelDtor)(m_pFirst) )
    {
      pNextLightItem = m_pFirst->pNextLightItem;
      v20 = v3;
      v18 = pNextLightItem;
      if ( m_pFirst == this->m_listTasks.m_pFirst )
        this->m_listTasks.m_pFirst = pNextLightItem;
      else
        v3->pNextLightItem = pNextLightItem;
      v8 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
      m_pFirst->vfptr->__vecDelDtor(m_pFirst, 0);
      AK::MemoryMgr::Free(v8, m_pFirst);
      v3 = v20;
      m_pFirst = v18;
      goto LABEL_11;
    }
LABEL_10:
    v3 = m_pFirst;
    m_pFirst = m_pFirst->pNextLightItem;
LABEL_11:
    if ( !m_pFirst )
      return 0i64;
  }
  if ( (v6 & 1) != 0 || (v6 & 0x40) == 0 )
    goto LABEL_10;
  v10 = ((double (__fastcall *)(AK::StreamMgr::CAkStmTask *))m_pFirst->vfptr[6].__vecDelDtor)(m_pFirst);
  *(_QWORD *)&v11 = m_pFirst->pNextLightItem;
  *((_QWORD *)&v11 + 1) = m_pFirst;
  v12 = *(float *)&v10;
  while ( (_QWORD)v11 )
  {
    v13 = *(_BYTE *)(v11 + 117);
    if ( (v13 & 8) != 0 )
    {
      if ( (*(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)v11 + 8i64))(v11) )
      {
        v14 = *(AK::StreamMgr::CAkStmTask **)(v11 + 24);
        *((_QWORD *)&v19 + 1) = *((_QWORD *)&v11 + 1);
        *(_QWORD *)&v19 = v14;
        if ( (AK::StreamMgr::CAkStmTask *)v11 == this->m_listTasks.m_pFirst )
          this->m_listTasks.m_pFirst = v14;
        else
          *(_QWORD *)(*((_QWORD *)&v11 + 1) + 24i64) = v14;
        DWORD2(v11) = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
        (**(void (__fastcall ***)(_QWORD, _QWORD))v11)(v11, 0i64);
        AK::MemoryMgr::Free(SDWORD2(v11), (void *)v11);
        v11 = v19;
        continue;
      }
    }
    else
    {
      if ( (v13 & 1) != 0 || (v13 & 0x40) == 0 )
        goto LABEL_30;
      v15 = (*(double (__fastcall **)(_QWORD))(*(_QWORD *)v11 + 48i64))(v11);
      if ( *(float *)&v15 == 0.0 )
      {
        v16 = *(_BYTE *)(v11 + 116);
        m_priority = m_pFirst->m_priority;
        if ( v16 <= m_priority
          && v12 <= 0.0
          && (v16 != m_priority
           || (float)((float)(int)(this->m_time - *(_DWORD *)(v11 + 88)) * (float)(1.0 / AK::g_fFreqRatio)) <= (float)((float)(int)(this->m_time - LODWORD(m_pFirst->m_iIOStartTime)) * (float)(1.0 / AK::g_fFreqRatio))) )
        {
          goto LABEL_30;
        }
LABEL_29:
        m_pFirst = (AK::StreamMgr::CAkStmTask *)v11;
        v12 = *(float *)&v15;
        goto LABEL_30;
      }
      if ( *(float *)&v15 < v12 )
        goto LABEL_29;
    }
LABEL_30:
    *((_QWORD *)&v11 + 1) = v11;
    *(_QWORD *)&v11 = *(_QWORD *)(v11 + 24);
  }
  *out_fOpDeadline = v12;
  return m_pFirst;
}

// File Line: 498
// RVA: 0xAA3620
void __fastcall AK::StreamMgr::CAkDeviceBase::ForceCleanup(
        AK::StreamMgr::CAkDeviceBase *this,
        bool in_bKillLowestPriorityTask,
        char in_priority)
{
  _BYTE *v6; // r14
  __int128 m_pFirst; // rdi
  char v8; // cl
  AK::StreamMgr::CAkStmTask *v9; // rax
  __int128 v10; // [rsp+30h] [rbp-28h]

  EnterCriticalSection(&this->m_lockTasksList.m_csLock);
  v6 = 0i64;
  m_pFirst = (unsigned __int64)this->m_listTasks.m_pFirst;
  if ( !(_QWORD)m_pFirst )
    goto LABEL_20;
  do
  {
    v8 = *(_BYTE *)(m_pFirst + 117);
    if ( (v8 & 8) == 0 )
    {
      if ( in_bKillLowestPriorityTask
        && (!v6 || *(_BYTE *)(m_pFirst + 116) < v6[116])
        && *(char *)(m_pFirst + 116) < in_priority
        && (v8 & 0x40) != 0 )
      {
        v6 = (_BYTE *)m_pFirst;
      }
LABEL_16:
      *((_QWORD *)&m_pFirst + 1) = m_pFirst;
      *(_QWORD *)&m_pFirst = *(_QWORD *)(m_pFirst + 24);
      continue;
    }
    if ( !(*(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)m_pFirst + 8i64))(m_pFirst) )
      goto LABEL_16;
    v9 = *(AK::StreamMgr::CAkStmTask **)(m_pFirst + 24);
    *((_QWORD *)&v10 + 1) = *((_QWORD *)&m_pFirst + 1);
    *(_QWORD *)&v10 = v9;
    if ( (AK::StreamMgr::CAkStmTask *)m_pFirst == this->m_listTasks.m_pFirst )
      this->m_listTasks.m_pFirst = v9;
    else
      *(_QWORD *)(*((_QWORD *)&m_pFirst + 1) + 24i64) = v9;
    DWORD2(m_pFirst) = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
    (**(void (__fastcall ***)(_QWORD, _QWORD))m_pFirst)(m_pFirst, 0i64);
    AK::MemoryMgr::Free(SDWORD2(m_pFirst), (void *)m_pFirst);
    m_pFirst = v10;
  }
  while ( (_QWORD)m_pFirst );
  if ( v6 )
    (*(void (__fastcall **)(_BYTE *))(*(_QWORD *)v6 + 16i64))(v6);
LABEL_20:
  LeaveCriticalSection(&this->m_lockTasksList.m_csLock);
}

// File Line: 705
// RVA: 0xAA29B0
void __fastcall AK::StreamMgr::CAkStmTask::~CAkStmTask(AK::StreamMgr::CAkStmTask *this)
{
  bool v1; // zf
  AK::StreamMgr::AkDeferredOpenData *m_pDeferredOpenData; // rcx
  wchar_t *m_pszStreamName; // rdx
  AkFileDesc *m_pFileDesc; // rdx

  v1 = (*((_BYTE *)this + 117) & 0x10) == 0;
  this->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkStmTask::`vftable;
  if ( !v1 )
    this->m_pDevice->m_pLowLevelHook->vfptr->Close(this->m_pDevice->m_pLowLevelHook, this->m_pFileDesc);
  m_pDeferredOpenData = this->m_pDeferredOpenData;
  if ( m_pDeferredOpenData )
  {
    AK::StreamMgr::AkDeferredOpenData::Destroy(m_pDeferredOpenData);
    this->m_pDeferredOpenData = 0i64;
  }
  m_pszStreamName = this->m_pszStreamName;
  if ( m_pszStreamName )
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, m_pszStreamName);
  m_pFileDesc = this->m_pFileDesc;
  if ( m_pFileDesc )
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, m_pFileDesc);
  DeleteCriticalSection(&this->m_lockStatus.m_csLock);
  AK::StreamMgr::CAkClientThreadAware::~CAkClientThreadAware(this);
}

// File Line: 729
// RVA: 0xAA48E0
__int64 __fastcall AK::StreamMgr::CAkStmTask::SetDeferredFileOpen(
        AK::StreamMgr::CAkStmTask *this,
        AkFileDesc *in_pFileDesc,
        const wchar_t *in_pszFileName,
        AkFileSystemFlags *in_pFSFlags,
        AkOpenMode in_eOpenMode)
{
  AK::StreamMgr::AkDeferredOpenData *v6; // rax

  *((_BYTE *)this + 117) &= ~0x10u;
  this->m_pFileDesc = in_pFileDesc;
  v6 = AK::StreamMgr::AkDeferredOpenData::Create(in_pszFileName, in_pFSFlags, in_eOpenMode);
  this->m_pDeferredOpenData = v6;
  return 2 - (unsigned int)(v6 != 0i64);
}

// File Line: 746
// RVA: 0xAA48A0
__int64 __fastcall AK::StreamMgr::CAkStmTask::SetDeferredFileOpen(
        AK::StreamMgr::CAkStmTask *this,
        AkFileDesc *in_pFileDesc,
        unsigned int in_fileID,
        AkFileSystemFlags *in_pFSFlags,
        AkOpenMode in_eOpenMode)
{
  AK::StreamMgr::AkDeferredOpenData *v6; // rax

  *((_BYTE *)this + 117) &= ~0x10u;
  this->m_pFileDesc = in_pFileDesc;
  v6 = AK::StreamMgr::AkDeferredOpenData::Create(in_fileID, in_pFSFlags, in_eOpenMode);
  this->m_pDeferredOpenData = v6;
  return 2 - (unsigned int)(v6 != 0i64);
}

// File Line: 767
// RVA: 0xAA32C0
__int64 __fastcall AK::StreamMgr::CAkStmTask::EnsureFileIsOpen(AK::StreamMgr::CAkStmTask *this)
{
  AK::StreamMgr::AkDeferredOpenData *m_pDeferredOpenData; // rdx
  int v3; // eax
  AkFileSystemFlags *p_flags; // r9
  __int64 eOpenMode; // r8
  AK::StreamMgr::IAkFileLocationResolverVtbl *vfptr; // r10
  AKRESULT v7; // eax
  AKRESULT v8; // edi
  AK::StreamMgr::AkDeferredOpenData *v9; // rcx
  AkFileDesc *m_pFileDesc; // [rsp+28h] [rbp-10h]
  char v12; // [rsp+40h] [rbp+8h] BYREF

  m_pDeferredOpenData = this->m_pDeferredOpenData;
  if ( !m_pDeferredOpenData || (*((_BYTE *)this + 117) & 8) != 0 )
    return 1i64;
  v12 = 1;
  v3 = *((_DWORD *)m_pDeferredOpenData + 11);
  if ( (v3 & 2) != 0 )
    p_flags = &m_pDeferredOpenData->flags;
  else
    p_flags = 0i64;
  eOpenMode = (unsigned int)m_pDeferredOpenData->eOpenMode;
  vfptr = AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver->vfptr;
  m_pFileDesc = this->m_pFileDesc;
  if ( (v3 & 1) != 0 )
    v7 = vfptr->Open(
           AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver,
           m_pDeferredOpenData->pszFileName,
           (AkOpenMode)eOpenMode,
           p_flags,
           (bool *)&v12,
           m_pFileDesc);
  else
    v7 = vfptr->Open(
           AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver,
           m_pDeferredOpenData->fileID,
           (AkOpenMode)eOpenMode,
           p_flags,
           (bool *)&v12,
           m_pFileDesc);
  v8 = v7;
  if ( v7 == AK_Success )
    ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *))this->vfptr[3].__vecDelDtor)(this);
  v9 = this->m_pDeferredOpenData;
  if ( v9 )
  {
    AK::StreamMgr::AkDeferredOpenData::Destroy(v9);
    this->m_pDeferredOpenData = 0i64;
  }
  return (unsigned int)v8;
}

// File Line: 861
// RVA: 0xAA2830
void __fastcall AK::StreamMgr::CAkStdStmBase::CAkStdStmBase(AK::StreamMgr::CAkStdStmBase *this)
{
  AK::StreamMgr::CAkClientThreadAware::CAkClientThreadAware(this);
  this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkStmTask::`vftable;
  this->m_pDeferredOpenData = 0i64;
  this->m_pFileDesc = 0i64;
  InitializeCriticalSection(&this->m_lockStatus.m_csLock);
  *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) &= 0x83u;
  this->m_pszStreamName = 0i64;
  this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkStdStmBase::`vftable{for `AK::StreamMgr::CAkStmTask};
  this->AK::IAkStdStream::vfptr = (AK::IAkStdStreamVtbl *)&AK::StreamMgr::CAkStdStmBase::`vftable{for `AK::IAkStdStream};
  this->m_memBlock.uPosition = 0i64;
  this->m_memBlock.pData = 0i64;
  this->m_memBlock.pNextBlock = 0i64;
  this->m_memBlock.uAvailableSize = 0;
  this->m_memBlock.fileID = -1;
  this->m_memBlock.uRefCount = 0;
  *((_DWORD *)this + 44) &= 0xFFFFFFF0;
  *((_DWORD *)this + 44) |= 0x10u;
  *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) &= 0xFCu;
  this->m_uTotalScheduledSize = 0;
}

// File Line: 867
// RVA: 0xAA2960
void __fastcall AK::StreamMgr::CAkStdStmBase::~CAkStdStmBase(AK::StreamMgr::CAkStdStmBase *this)
{
  bool v1; // zf

  v1 = (*((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 0x20) == 0;
  this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkStdStmBase::`vftable{for `AK::StreamMgr::CAkStmTask};
  this->AK::IAkStdStream::vfptr = (AK::IAkStdStreamVtbl *)&AK::StreamMgr::CAkStdStmBase::`vftable{for `AK::IAkStdStream};
  if ( !v1 )
    AK::StreamMgr::CAkIOThread::StdSemDecr(this->m_pDevice);
  this->AK::IAkStdStream::vfptr = (AK::IAkStdStreamVtbl *)&AK::IAkStdStream::`vftable;
  AK::StreamMgr::CAkStmTask::~CAkStmTask(this);
}

// File Line: 880
// RVA: 0xAA3EA0
__int64 __fastcall AK::StreamMgr::CAkStdStmBase::Init(
        AK::StreamMgr::CAkStdStmBase *this,
        AK::StreamMgr::CAkDeviceBase *in_pDevice,
        AkFileDesc *in_pFileDesc,
        AkOpenMode __formal)
{
  unsigned int v7; // ecx
  unsigned int m_uGranularity; // eax

  this->m_pDevice = in_pDevice;
  if ( in_pFileDesc->iFileSize >= 0 )
  {
    v7 = in_pDevice->m_pLowLevelHook->vfptr->GetBlockSize(in_pDevice->m_pLowLevelHook, in_pFileDesc);
    if ( !v7 || (m_uGranularity = in_pDevice->m_uGranularity, v7 > m_uGranularity) || m_uGranularity % v7 )
    {
      *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 0xB7 | 8;
      return 2i64;
    }
    else
    {
      this->m_uLLBlockSize = v7;
      return 1i64;
    }
  }
  else
  {
    *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 0xB7 | 8;
    return 31i64;
  }
}

// File Line: 966
// RVA: 0xAA3B60
void *__fastcall AK::StreamMgr::CAkStdStmBase::GetPosition(AK::StreamMgr::CAkStdStmBase *this, bool *out_pbEndOfStream)
{
  if ( out_pbEndOfStream )
    *out_pbEndOfStream = (*((_BYTE *)&this[-1] + 181) & 4) != 0;
  return this->m_hBlockEvent;
}

// File Line: 988
// RVA: 0xAA4DA0
__int64 __fastcall AK::StreamMgr::CAkStdStmBase::SetPosition(
        AK::StreamMgr::CAkStdStmBase *this,
        __int64 in_iMoveOffset,
        AkMoveMethod in_eMoveMethod,
        __int64 *out_piRealOffset)
{
  __int64 v4; // r10
  __int64 result; // rax
  __int64 v6; // rdx
  int v7; // r8d

  v4 = in_iMoveOffset;
  if ( out_piRealOffset )
    *out_piRealOffset = 0i64;
  if ( (this->m_lockStatus.m_csLock.LockCount & 0xF) == 2 )
    return 2i64;
  if ( in_eMoveMethod )
  {
    if ( in_eMoveMethod == AK_MoveCurrent )
    {
      v4 = (__int64)this->m_hBlockEvent + in_iMoveOffset;
    }
    else
    {
      if ( in_eMoveMethod != AK_MoveEnd )
        return 31i64;
      v4 = *(_QWORD *)this[-1].m_pszStreamName + in_iMoveOffset;
    }
  }
  if ( v4 < 0 )
    return 31i64;
  v6 = v4 % *((unsigned int *)&this[-1] + 44);
  if ( v6 )
    v4 -= v6;
  if ( !out_piRealOffset )
    goto LABEL_20;
  if ( in_eMoveMethod == AK_MoveBegin )
  {
    *out_piRealOffset = v4;
LABEL_20:
    this->m_hBlockEvent = (void *)v4;
    return 1i64;
  }
  v7 = in_eMoveMethod - 1;
  if ( v7 )
  {
    if ( v7 != 1 )
      return 2i64;
    result = 1i64;
    *out_piRealOffset = v4 - *(_QWORD *)this[-1].m_pszStreamName;
    this->m_hBlockEvent = (void *)v4;
  }
  else
  {
    *out_piRealOffset = v4 - (unsigned __int64)this->m_hBlockEvent;
    this->m_hBlockEvent = (void *)v4;
    return 1i64;
  }
  return result;
}

// File Line: 1071
// RVA: 0xAA4180
__int64 __fastcall AK::StreamMgr::CAkStdStmBase::Read(
        AK::StreamMgr::CAkStdStmBase *this,
        void *in_pBuffer,
        unsigned int in_uReqSize,
        bool in_bWait,
        unsigned __int8 in_priority,
        float in_fDeadline,
        unsigned int *out_uSize)
{
  return AK::StreamMgr::CAkStdStmBase::ExecuteOp(
           (AK::StreamMgr::CAkStdStmBase *)((char *)this - 120),
           0,
           in_pBuffer,
           in_uReqSize,
           in_bWait,
           in_priority,
           in_fDeadline,
           out_uSize);
}

// File Line: 1091
// RVA: 0xAA5240
__int64 __fastcall AK::StreamMgr::CAkStdStmBase::Write(
        AK::StreamMgr::CAkStdStmBase *this,
        void *in_pBuffer,
        unsigned int in_uReqSize,
        bool in_bWait,
        unsigned __int8 in_priority,
        float in_fDeadline,
        unsigned int *out_uSize)
{
  return AK::StreamMgr::CAkStdStmBase::ExecuteOp(
           (AK::StreamMgr::CAkStdStmBase *)((char *)this - 120),
           1,
           in_pBuffer,
           in_uReqSize,
           in_bWait,
           in_priority,
           in_fDeadline,
           out_uSize);
}

// File Line: 1111
// RVA: 0xAA3370
__int64 __fastcall AK::StreamMgr::CAkStdStmBase::ExecuteOp(
        AK::StreamMgr::CAkStdStmBase *this,
        bool in_bWrite,
        void *in_pBuffer,
        unsigned int in_uReqSize,
        bool in_bWait,
        unsigned __int8 in_priority,
        float in_fDeadline,
        unsigned int *out_uSize)
{
  int v9; // ebp
  unsigned int v10; // esi
  int v11; // ecx
  unsigned __int64 uPosition; // rcx
  unsigned __int64 iFileSize; // rdx
  int v15; // eax

  v9 = 0;
  v10 = in_uReqSize;
  *out_uSize = 0;
  *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) &= ~2u;
  *((_DWORD *)this + 44) &= ~0x10u;
  this->m_fDeadline = in_fDeadline;
  this->m_uTotalScheduledSize = 0;
  v11 = *((_DWORD *)this + 44);
  this->m_memBlock.pData = in_pBuffer;
  this->m_memBlock.uAvailableSize = in_uReqSize;
  *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) |= 2 * in_bWrite;
  this->m_priority = in_priority;
  if ( !in_pBuffer || in_priority > 0x64u || in_fDeadline < 0.0 )
    return 31i64;
  if ( (((v11 << 28 >> 28) - 2) & 0xFFFFFFFD) == 0 )
    return 2i64;
  if ( !in_bWrite )
  {
    if ( in_uReqSize % this->m_uLLBlockSize )
      return 2i64;
    if ( (*((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 0x10) != 0 )
    {
      uPosition = this->m_memBlock.uPosition;
      iFileSize = this->m_pFileDesc->iFileSize;
      if ( uPosition + in_uReqSize > iFileSize )
      {
        if ( uPosition >= iFileSize )
        {
LABEL_15:
          EnterCriticalSection(&this->m_lockStatus.m_csLock);
          AK::StreamMgr::CAkStdStmBase::SetStatus(this, AK_StmStatusCompleted);
          *out_uSize = 0;
          LeaveCriticalSection(&this->m_lockStatus.m_csLock);
          return 1i64;
        }
        v10 = iFileSize - uPosition;
      }
    }
  }
  if ( !v10 )
    goto LABEL_15;
  QueryPerformanceCounter((LARGE_INTEGER *)&this->m_iIOStartTime);
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  if ( in_bWait )
  {
    AK::StreamMgr::CAkClientThreadAware::SetBlockedStatus(this);
    AK::StreamMgr::CAkStdStmBase::SetStatus(this, AK_StmStatusPending);
    LeaveCriticalSection(&this->m_lockStatus.m_csLock);
    AK::StreamMgr::CAkIOThread::WaitForIOCompletion(this->m_pDevice, this);
    v15 = *((_DWORD *)this + 44);
    *out_uSize = v10;
    LOBYTE(v9) = (v15 & 0xF) != 1;
    return (unsigned int)(v9 + 1);
  }
  else
  {
    AK::StreamMgr::CAkStdStmBase::SetStatus(this, AK_StmStatusPending);
    LeaveCriticalSection(&this->m_lockStatus.m_csLock);
    *out_uSize = v10;
    return 1i64;
  }
}

// File Line: 1211
// RVA: 0xAA3A50
void *__fastcall AK::StreamMgr::CAkStdStmBase::GetData(
        AK::StreamMgr::CAkStdStmBase *this,
        unsigned int *out_uActualSize)
{
  *out_uActualSize = (unsigned int)this->m_pDeferredOpenData;
  return *(void **)&this->m_bIsBlocked;
}

// File Line: 1220
// RVA: 0xAA3CA0
__int64 __fastcall AK::StreamMgr::CAkStdStmBase::GetStatus(AK::StreamMgr::CAkStdStmBase *this)
{
  return (unsigned int)(this->m_lockStatus.m_csLock.LockCount << 28 >> 28);
}

// File Line: 1231
// RVA: 0xAA3250
float __fastcall AK::StreamMgr::CAkStdStmBase::EffectiveDeadline(AK::StreamMgr::CAkStdStmBase *this)
{
  float result; // xmm0_4

  result = 0.0;
  if ( (float)((float)(this->m_fDeadline
                     / (float)(int)((this->m_pDevice->m_uGranularity
                                   + this->m_memBlock.uAvailableSize
                                   - this->m_uTotalScheduledSize
                                   - 1)
                                  / this->m_pDevice->m_uGranularity))
             - (float)((float)(LODWORD(this->m_pDevice->m_time) - LODWORD(this->m_iIOStartTime)) / AK::g_fFreqRatio)) > 0.0 )
    return (float)(this->m_fDeadline
                 / (float)(int)((this->m_pDevice->m_uGranularity
                               + this->m_memBlock.uAvailableSize
                               - this->m_uTotalScheduledSize
                               - 1)
                              / this->m_pDevice->m_uGranularity))
         - (float)((float)(LODWORD(this->m_pDevice->m_time) - LODWORD(this->m_iIOStartTime)) / AK::g_fFreqRatio);
  return result;
}

// File Line: 1247
// RVA: 0xAA2CE0
void __fastcall AK::StreamMgr::CAkStdStmBase::AddMemView(
        AK::StreamMgr::CAkStdStmBase *this,
        AK::StreamMgr::CAkStmMemView *in_pMemView,
        bool in_bStoreData)
{
  char v5; // dl
  int v6; // ecx
  char v7; // dl
  int v8; // ecx
  unsigned int m_uGranularity; // r8d
  AkFileDesc *m_pFileDesc; // r9
  AK::StreamMgr::CAkDeviceBase *m_pDevice; // rbp
  AK::StreamMgr::AkMemBlock *m_pBlock; // r8
  AK::StreamMgr::CAkDeviceBase *v13; // rsi
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rax

  if ( in_bStoreData )
  {
    v5 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117);
    if ( (v5 & 8) == 0 )
    {
      v6 = *((_DWORD *)this + 44);
      if ( (v6 & 0xF) != 4 )
      {
        v7 = v5 & 0xFB;
        v8 = v6 | 0x10;
        *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = v7;
        *((_DWORD *)this + 44) = v8;
        m_uGranularity = in_pMemView->m_pBlock->uAvailableSize - in_pMemView->m_uOffsetInBlock;
        if ( m_uGranularity > this->m_pDevice->m_uGranularity )
        {
          m_uGranularity = this->m_pDevice->m_uGranularity;
          *((_DWORD *)this + 44) = v8 & 0xFFFFFFEF;
        }
        if ( (v7 & 2) == 0 )
        {
          m_pFileDesc = this->m_pFileDesc;
          if ( m_uGranularity >= m_pFileDesc->iFileSize
                               - in_pMemView->m_uOffsetInBlock
                               - in_pMemView->m_pBlock->uPosition )
          {
            *((_DWORD *)this + 44) |= 0x10u;
            *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = v7 | 4;
            this->m_memBlock.uAvailableSize += LODWORD(m_pFileDesc->iFileSize)
                                             - in_pMemView->m_pBlock->uAvailableSize
                                             - in_pMemView->m_pBlock->uPosition;
          }
        }
      }
    }
  }
  m_pDevice = this->m_pDevice;
  EnterCriticalSection(&m_pDevice->m_lockSems.m_csLock);
  m_pBlock = in_pMemView->m_pBlock;
  v13 = this->m_pDevice;
  in_pMemView->m_pBlock = 0i64;
  if ( m_pBlock )
    AK::StreamMgr::CAkIOMemMgr::DestroyTempBlock(&v13->m_mgrMemIO, &this->m_memBlock, m_pBlock);
  m_pFirst = v13->m_poolStmMemView.m_pFirst;
  if ( m_pFirst )
  {
    in_pMemView->pNextView = m_pFirst;
    v13->m_poolStmMemView.m_pFirst = in_pMemView;
  }
  else
  {
    v13->m_poolStmMemView.m_pFirst = in_pMemView;
    in_pMemView->pNextView = 0i64;
  }
  LeaveCriticalSection(&m_pDevice->m_lockSems.m_csLock);
}

// File Line: 1312
// RVA: 0xAA5180
void __fastcall AK::StreamMgr::CAkStdStmBase::UpdateTaskStatus(
        AK::StreamMgr::CAkStdStmBase *this,
        AKRESULT in_eIOResult)
{
  AK::StreamMgr::CAkClientThreadAwareVtbl *vfptr; // rax
  int v4; // ecx
  bool v5; // zf
  char v6; // al
  AK::StreamMgr::CAkDeviceBase *m_pDevice; // rcx
  char v8; // al
  AK::StreamMgr::CAkDeviceBase *v9; // rcx

  if ( in_eIOResult == AK_Fail )
  {
    *((_DWORD *)this + 44) &= 0xFFFFFFF4;
    *((_DWORD *)this + 44) |= 4u;
    if ( (*((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 8) == 0 )
      goto LABEL_10;
    vfptr = this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr;
  }
  else
  {
    v4 = *((_DWORD *)this + 44);
    if ( (v4 & 0x10) == 0 )
      goto LABEL_12;
    this->m_memBlock.uPosition += this->m_memBlock.uAvailableSize;
    v5 = (*((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 8) == 0;
    *((_DWORD *)this + 44) = v4 & 0xFFFFFFF0 | 1;
    if ( v5 )
      goto LABEL_10;
    vfptr = this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr;
  }
  if ( ((unsigned __int8 (*)(void))vfptr[1].__vecDelDtor)() )
  {
    v6 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117);
    if ( (v6 & 0x20) == 0 )
    {
      m_pDevice = this->m_pDevice;
      *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = v6 | 0x20;
      AK::StreamMgr::CAkIOThread::StdSemIncr(m_pDevice);
    }
    goto LABEL_12;
  }
LABEL_10:
  *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) &= ~0x40u;
  v8 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117);
  if ( (v8 & 0x20) != 0 )
  {
    v9 = this->m_pDevice;
    *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = v8 & 0xDF;
    AK::StreamMgr::CAkIOThread::StdSemDecr(v9);
  }
LABEL_12:
  if ( this->m_bIsBlocked && (((int)(*((_DWORD *)this + 44) << 28) >> 28) & 0xFFFFFFFD) != 0 )
    AK::StreamMgr::CAkIOThread::SignalIOCompleted(this->m_pDevice, this);
}

// File Line: 1344
// RVA: 0xAA3F90
void __fastcall AK::StreamMgr::CAkStdStmBase::Kill(AK::StreamMgr::CAkStdStmBase *this)
{
  char v2; // al
  AK::StreamMgr::CAkDeviceBase *m_pDevice; // rcx
  char v4; // al
  AK::StreamMgr::CAkDeviceBase *v5; // rcx

  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  *((_DWORD *)this + 44) &= 0xFFFFFFF4;
  *((_DWORD *)this + 44) |= 4u;
  if ( (*((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 8) != 0
    && ((unsigned __int8 (__fastcall *)(AK::StreamMgr::CAkStdStmBase *))this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr[1].__vecDelDtor)(this) )
  {
    v2 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117);
    if ( (v2 & 0x20) == 0 )
    {
      m_pDevice = this->m_pDevice;
      *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = v2 | 0x20;
      AK::StreamMgr::CAkIOThread::StdSemIncr(m_pDevice);
    }
  }
  else
  {
    *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) &= ~0x40u;
    v4 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117);
    if ( (v4 & 0x20) != 0 )
    {
      v5 = this->m_pDevice;
      *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = v4 & 0xDF;
      AK::StreamMgr::CAkIOThread::StdSemDecr(v5);
    }
  }
  if ( this->m_bIsBlocked && (((int)(*((_DWORD *)this + 44) << 28) >> 28) & 0xFFFFFFFD) != 0 )
    AK::StreamMgr::CAkIOThread::SignalIOCompleted(this->m_pDevice, this);
  LeaveCriticalSection(&this->m_lockStatus.m_csLock);
}

// File Line: 1395
// RVA: 0xAA4E50
void __fastcall AK::StreamMgr::CAkStdStmBase::SetStatus(AK::StreamMgr::CAkStdStmBase *this, AkStmStatus in_eStatus)
{
  char v4; // al
  AK::StreamMgr::CAkDeviceBase *m_pDevice; // rcx
  char v6; // al
  AK::StreamMgr::CAkDeviceBase *v7; // rcx

  *((_DWORD *)this + 44) &= 0xFFFFFFF0;
  *((_DWORD *)this + 44) |= in_eStatus & 0xF;
  if ( (*((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 8) != 0
    && ((unsigned __int8 (__fastcall *)(AK::StreamMgr::CAkStdStmBase *))this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr[1].__vecDelDtor)(this) )
  {
    goto LABEL_5;
  }
  if ( in_eStatus == AK_StmStatusPending )
  {
    *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) |= 0x40u;
LABEL_5:
    v4 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117);
    if ( (v4 & 0x20) == 0 )
    {
      m_pDevice = this->m_pDevice;
      *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = v4 | 0x20;
      AK::StreamMgr::CAkIOThread::StdSemIncr(m_pDevice);
    }
    return;
  }
  *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) &= ~0x40u;
  v6 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117);
  if ( (v6 & 0x20) != 0 )
  {
    v7 = this->m_pDevice;
    *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = v6 & 0xDF;
    AK::StreamMgr::CAkIOThread::StdSemDecr(v7);
  }
}

// File Line: 1458
// RVA: 0xAA2720
void __fastcall AK::StreamMgr::CAkAutoStmBase::CAkAutoStmBase(AK::StreamMgr::CAkAutoStmBase *this)
{
  char v2; // al

  AK::StreamMgr::CAkClientThreadAware::CAkClientThreadAware(this);
  this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkStmTask::`vftable;
  this->m_pDeferredOpenData = 0i64;
  this->m_pFileDesc = 0i64;
  InitializeCriticalSection(&this->m_lockStatus.m_csLock);
  *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) &= 0x83u;
  this->m_pszStreamName = 0i64;
  this->m_fileID = -1;
  this->m_uVirtualBufferingSize = 0;
  this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkAutoStmBase::`vftable{for `AK::StreamMgr::CAkStmTask};
  this->AK::IAkAutoStream::vfptr = (AK::IAkAutoStreamVtbl *)&AK::StreamMgr::CAkAutoStmBase::`vftable{for `AK::IAkAutoStream};
  this->m_listBuffers.m_ulNumListItems = 0;
  this->m_listBuffers.m_pFirst = 0i64;
  this->m_listBuffers.m_pLast = 0i64;
  v2 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117);
  *((_BYTE *)this + 194) &= 0xFCu;
  this->m_uNextToGrant = 0;
  *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = v2 & 0xFC | 1;
}

// File Line: 1464
// RVA: 0xAA28D0
void __fastcall AK::StreamMgr::CAkAutoStmBase::~CAkAutoStmBase(AK::StreamMgr::CAkAutoStmBase *this)
{
  bool v1; // zf

  v1 = (*((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 0x20) == 0;
  this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkAutoStmBase::`vftable{for `AK::StreamMgr::CAkStmTask};
  this->AK::IAkAutoStream::vfptr = (AK::IAkAutoStreamVtbl *)&AK::StreamMgr::CAkAutoStmBase::`vftable{for `AK::IAkAutoStream};
  if ( !v1 )
    AK::StreamMgr::CAkIOThread::AutoSemDecr(this->m_pDevice);
  this->AK::IAkAutoStream::vfptr = (AK::IAkAutoStreamVtbl *)&AK::IAkAutoStream::`vftable;
  AK::StreamMgr::CAkStmTask::~CAkStmTask(this);
}

// File Line: 1479
// RVA: 0xAA3CB0
AKRESULT __fastcall AK::StreamMgr::CAkAutoStmBase::Init(
        AK::StreamMgr::CAkAutoStmBase *this,
        AK::StreamMgr::CAkDeviceBase *in_pDevice,
        AkFileDesc *in_pFileDesc,
        unsigned int in_fileID,
        AkAutoStmHeuristics *in_heuristics,
        AkAutoStmBufSettings *in_pBufferSettings,
        unsigned int in_uGranularity)
{
  AKRESULT result; // eax
  unsigned int v10; // eax
  float fThroughput; // xmm0_4
  __int64 uLoopEnd; // rax
  char uMinNumBuffers; // cl
  char priority; // al

  this->m_pDevice = in_pDevice;
  if ( in_pFileDesc->iFileSize >= 0 )
  {
    this->m_fileID = in_fileID;
    v10 = in_pDevice->m_pLowLevelHook->vfptr->GetBlockSize(in_pDevice->m_pLowLevelHook, in_pFileDesc);
    if ( !v10 || v10 > in_uGranularity || in_uGranularity % v10 )
    {
      *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 0xB7 | 8;
      return 2;
    }
    else
    {
      this->m_uLLBlockSize = v10;
      this->m_uBufferAlignment = v10;
      fThroughput = in_heuristics->fThroughput;
      if ( in_heuristics->fThroughput <= 1.0 )
        fThroughput = *(float *)&FLOAT_1_0;
      this->m_fThroughput = fThroughput;
      this->m_uLoopStart = in_heuristics->uLoopStart - in_heuristics->uLoopStart % v10;
      uLoopEnd = in_heuristics->uLoopEnd;
      if ( uLoopEnd > in_pFileDesc->iFileSize )
        LODWORD(uLoopEnd) = in_pFileDesc->iFileSize;
      this->m_uLoopEnd = uLoopEnd;
      uMinNumBuffers = in_heuristics->uMinNumBuffers;
      if ( !uMinNumBuffers )
        uMinNumBuffers = 1;
      this->m_uMinNumBuffers = uMinNumBuffers;
      priority = in_heuristics->priority;
      this->m_uNextExpectedUserPosition = 0i64;
      this->m_priority = priority;
      if ( !in_pFileDesc->iFileSize )
        *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 0xBB | 4;
      result = AK::StreamMgr::CAkAutoStmBase::SetBufferingSettings(this, in_pBufferSettings, in_uGranularity);
      if ( result != AK_Success )
        *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 0xB7 | 8;
    }
  }
  else
  {
    *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 0xB7 | 8;
    return 31;
  }
  return result;
}

// File Line: 1539
// RVA: 0xAA37E0
__int64 __fastcall Gcd(unsigned int a, unsigned int b)
{
  unsigned int k; // r8d
  unsigned int v3; // edx
  char i; // cl
  bool j; // cf
  unsigned int v6; // eax

  k = b;
  if ( a < b )
  {
    k = a;
    a = b;
  }
  v3 = a % k;
  if ( a % k )
  {
    for ( i = 0; (((unsigned __int8)v3 | (unsigned __int8)k) & 1) == 0; ++i )
    {
      k >>= 1;
      v3 >>= 1;
    }
    for ( ; (k & 1) == 0; k >>= 1 )
      ;
    for ( ; (v3 & 1) == 0; v3 >>= 1 )
      ;
    for ( j = k < v3; k != v3; j = k < v3 )
    {
      if ( j )
      {
        v6 = k;
        k = v3;
        v3 = v6;
      }
      for ( k = (k - v3) >> 1; (k & 1) == 0; k >>= 1 )
        ;
    }
    k <<= i;
  }
  return k;
}

// File Line: 1584
// RVA: 0xAA47A0
__int64 __fastcall AK::StreamMgr::CAkAutoStmBase::SetBufferingSettings(
        AK::StreamMgr::CAkAutoStmBase *this,
        AkAutoStmBufSettings *in_pBufferSettings,
        unsigned int in_uGranularity)
{
  AK::StreamMgr::CAkAutoStmBase *v5; // r11
  unsigned int v6; // eax
  unsigned int m_uBufferAlignment; // ecx
  unsigned int v8; // r9d
  unsigned int uBufferSize; // r8d
  unsigned int uMinBufferSize; // eax
  unsigned int v12; // eax
  unsigned int m_uLLBlockSize; // ecx

  v5 = this;
  if ( in_pBufferSettings )
  {
    if ( in_pBufferSettings->uBlockSize )
    {
      v6 = Gcd(this->m_uLLBlockSize, in_pBufferSettings->uBlockSize);
      v5->m_uBufferAlignment = v5->m_uLLBlockSize * (in_pBufferSettings->uBlockSize / v6);
    }
    m_uBufferAlignment = v5->m_uBufferAlignment;
    v5->m_uMinBufferSize = m_uBufferAlignment;
    v8 = in_uGranularity - in_uGranularity % m_uBufferAlignment;
    v5->m_uBufferSize = v8;
    uBufferSize = in_pBufferSettings->uBufferSize;
    if ( in_pBufferSettings->uBufferSize )
    {
      if ( uBufferSize <= in_uGranularity && !(uBufferSize % m_uBufferAlignment) )
      {
        v5->m_uBufferSize = uBufferSize;
        v5->m_uMinBufferSize = in_pBufferSettings->uBufferSize;
        return 1i64;
      }
      return 2i64;
    }
    uMinBufferSize = in_pBufferSettings->uMinBufferSize;
    if ( uMinBufferSize )
    {
      if ( m_uBufferAlignment < uMinBufferSize )
      {
        v12 = m_uBufferAlignment * ((m_uBufferAlignment + uMinBufferSize - 1) / m_uBufferAlignment);
        v5->m_uMinBufferSize = v12;
        if ( v12 > v8 )
          return 2i64;
      }
    }
  }
  else
  {
    m_uLLBlockSize = this->m_uLLBlockSize;
    v5->m_uMinBufferSize = m_uLLBlockSize;
    v5->m_uBufferSize = in_uGranularity - in_uGranularity % m_uLLBlockSize;
  }
  return 1i64;
}

// File Line: 1655
// RVA: 0xAA2F40
void __fastcall AK::StreamMgr::CAkAutoStmBase::Destroy(AK::StreamMgr::CAkAutoStmBase *this)
{
  char LockSemaphore; // r8
  __int64 **v3; // rax
  int m_pDeferredOpenData_high; // r10d
  __int64 *v5; // r9
  __int64 v6; // r11
  unsigned __int64 pNextLightItem_high; // rcx
  __int64 v8; // rsi
  int v9; // ecx
  bool v10; // zf

  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  *((_BYTE *)&this[-1] + 197) = *((_BYTE *)&this[-1] + 197) & 0xB7 | 8;
  LockSemaphore = (char)this->m_lockStatus.m_csLock.LockSemaphore;
  v3 = *(__int64 ***)&this->m_lockStatus.m_csLock.LockCount;
  if ( LockSemaphore )
  {
    m_pDeferredOpenData_high = HIDWORD(this->m_pDeferredOpenData);
    do
    {
      v5 = v3[1];
      v6 = *((unsigned int *)v3 + 4);
      pNextLightItem_high = HIDWORD(this->pNextLightItem);
      v8 = *v5;
      if ( *v5 + v6 >= pNextLightItem_high || v8 + (unsigned __int64)*((unsigned int *)v5 + 6) <= pNextLightItem_high )
        v9 = *((_DWORD *)v5 + 6);
      else
        v9 = pNextLightItem_high - v8;
      m_pDeferredOpenData_high += v9 - v6;
      v10 = LockSemaphore-- == 1;
      LOBYTE(this->m_lockStatus.m_csLock.LockSemaphore) = LockSemaphore;
      HIDWORD(this->m_pDeferredOpenData) = m_pDeferredOpenData_high;
      v3 = (__int64 **)*v3;
    }
    while ( !v10 );
  }
  AK::StreamMgr::CAkAutoStmBase::Flush((AK::StreamMgr::CAkAutoStmBase *)((char *)this - 120));
  *(_QWORD *)&this->m_lockStatus.m_csLock.LockCount = 0i64;
  this->m_lockStatus.m_csLock.OwningThread = 0i64;
  LODWORD(this->m_lockStatus.m_csLock.DebugInfo) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
}

// File Line: 1683
// RVA: 0xAA3A90
void __fastcall AK::StreamMgr::CAkStdStmBase::GetInfo(AK::StreamMgr::CAkStdStmBase *this, AkStreamInfo *out_info)
{
  out_info->deviceID = *(_DWORD *)(*(_QWORD *)&this[-1].m_memBlock.uRefCount + 264i64);
  out_info->pszName = *(const wchar_t **)&this[-1].m_uTotalScheduledSize;
  out_info->uSize = *(_QWORD *)this[-1].m_pszStreamName;
  out_info->bIsOpen = (*((_BYTE *)&this[-1] + 181) & 0x10) != 0;
}

// File Line: 1696
// RVA: 0xAA3A70
void __fastcall AK::StreamMgr::CAkAutoStmBase::GetHeuristics(
        AK::StreamMgr::CAkAutoStmBase *this,
        AkAutoStmHeuristics *out_heuristics)
{
  out_heuristics->fThroughput = *((float *)&this->m_bIsBlocked + 1);
  *(_QWORD *)&out_heuristics->uLoopStart = this->pNextLightItem;
  out_heuristics->uMinNumBuffers = BYTE1(this->m_lockStatus.m_csLock.LockSemaphore);
  out_heuristics->priority = *((_BYTE *)&this[-1] + 196);
}

// File Line: 1709
// RVA: 0xAA4920
__int64 __fastcall AK::StreamMgr::CAkAutoStmBase::SetHeuristics(
        AK::StreamMgr::CAkAutoStmBase *this,
        AkAutoStmHeuristics *in_heuristics)
{
  char priority; // al
  float fThroughput; // xmm6_4
  AK::IAkAutoStreamVtbl *vfptr; // rax
  __int64 uLoopEnd; // r14
  char uMinNumBuffers; // di
  char v9; // cl
  unsigned __int64 SpinCount; // rax
  unsigned int v11; // r12d
  unsigned __int64 m_hBlockEvent; // rbp
  unsigned int *v13; // rcx
  unsigned int *v14; // rdx
  __int64 LockSemaphore_low; // r8
  __int64 v16; // rax
  AK::StreamMgr::CAkStmMemView *v17; // rbx
  __int64 v18; // r8
  unsigned int *v19; // rax
  AK::StreamMgr::CAkStmMemView *m_pFirst; // r12
  AK::StreamMgr::CAkStmMemView *i; // rdx
  size_t pNextView; // r14
  unsigned int *v24; // [rsp+30h] [rbp-48h]
  AK::StreamMgr::CAkStmMemView *v25; // [rsp+30h] [rbp-48h]

  priority = in_heuristics->priority;
  if ( (unsigned __int8)priority > 0x64u )
    return 31i64;
  *((_BYTE *)&this[-1] + 196) = priority;
  fThroughput = in_heuristics->fThroughput;
  if ( in_heuristics->fThroughput <= 1.0 )
    fThroughput = *(float *)&FLOAT_1_0;
  vfptr = this[-1].AK::IAkAutoStream::vfptr;
  uLoopEnd = in_heuristics->uLoopEnd;
  if ( uLoopEnd > (__int64)vfptr->__vecDelDtor && (*((_BYTE *)&this[-1] + 197) & 0x10) != 0 )
    LODWORD(uLoopEnd) = vfptr->__vecDelDtor;
  if ( HIDWORD(this->pNextLightItem) == (_DWORD)uLoopEnd && LODWORD(this->pNextLightItem) == in_heuristics->uLoopStart )
  {
    uMinNumBuffers = 1;
    if ( in_heuristics->uMinNumBuffers )
      uMinNumBuffers = in_heuristics->uMinNumBuffers;
    if ( fThroughput != *((float *)&this->m_bIsBlocked + 1)
      || BYTE1(this->m_lockStatus.m_csLock.LockSemaphore) != uMinNumBuffers )
    {
      EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
      BYTE1(this->m_lockStatus.m_csLock.LockSemaphore) = uMinNumBuffers;
      *((float *)&this->m_bIsBlocked + 1) = fThroughput;
      AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus((AK::StreamMgr::CAkAutoStmBase *)((char *)this - 120));
      LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
    }
  }
  else
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
    *((float *)&this->m_bIsBlocked + 1) = fThroughput;
    v9 = in_heuristics->uMinNumBuffers;
    if ( !v9 )
      v9 = 1;
    BYTE1(this->m_lockStatus.m_csLock.LockSemaphore) = v9;
    SpinCount = this[-1].m_lockStatus.m_csLock.SpinCount;
    v11 = in_heuristics->uLoopStart - in_heuristics->uLoopStart % *(_DWORD *)&this[-1].m_uNextToGrant;
    LODWORD(this->pNextLightItem) = v11;
    (*(void (__fastcall **)(unsigned __int64 *, _QWORD))(SpinCount + 88))(
      &this[-1].m_lockStatus.m_csLock.SpinCount,
      (unsigned int)uLoopEnd);
    m_hBlockEvent = (unsigned __int64)this->m_hBlockEvent;
    v13 = *(unsigned int **)&this->m_lockStatus.m_csLock.LockCount;
    v14 = 0i64;
    if ( LOBYTE(this->m_lockStatus.m_csLock.LockSemaphore) )
    {
      LockSemaphore_low = LOBYTE(this->m_lockStatus.m_csLock.LockSemaphore);
      do
      {
        v16 = *((_QWORD *)v13 + 1);
        v14 = v13;
        v13 = *(unsigned int **)v13;
        m_hBlockEvent = *(_QWORD *)v16 + *(unsigned int *)(v16 + 24);
        --LockSemaphore_low;
      }
      while ( LockSemaphore_low );
    }
    if ( (_DWORD)uLoopEnd && m_hBlockEvent >= (unsigned int)uLoopEnd )
      m_hBlockEvent = v11;
    v17 = 0i64;
    if ( v13 )
    {
      do
      {
        v18 = *((_QWORD *)v13 + 1);
        if ( *(_QWORD *)v18 + v13[4] == m_hBlockEvent )
        {
          m_hBlockEvent = *(_QWORD *)v18 + *(unsigned int *)(v18 + 24);
          if ( (_DWORD)uLoopEnd && m_hBlockEvent >= (unsigned int)uLoopEnd )
            m_hBlockEvent = v11;
          v14 = v13;
          v13 = *(unsigned int **)v13;
        }
        else
        {
          v19 = *(unsigned int **)v13;
          v24 = *(unsigned int **)v13;
          if ( v13 == *(unsigned int **)&this->m_lockStatus.m_csLock.LockCount )
            *(_QWORD *)&this->m_lockStatus.m_csLock.LockCount = v19;
          else
            *(_QWORD *)v14 = v19;
          if ( v13 == this->m_lockStatus.m_csLock.OwningThread )
            this->m_lockStatus.m_csLock.OwningThread = v14;
          --LODWORD(this->m_lockStatus.m_csLock.DebugInfo);
          if ( v17 )
          {
            *(_QWORD *)v13 = v17;
            v17 = (AK::StreamMgr::CAkStmMemView *)v13;
          }
          else
          {
            v17 = (AK::StreamMgr::CAkStmMemView *)v13;
            *(_QWORD *)v13 = 0i64;
          }
          v13 = v24;
        }
      }
      while ( v13 );
      if ( v17 )
      {
        m_pFirst = this[-1].m_listBuffers.m_pFirst;
        EnterCriticalSection((LPCRITICAL_SECTION)&m_pFirst[1]);
        for ( i = v17; ; i = v25 )
        {
          pNextView = (size_t)i->pNextView;
          v25 = i->pNextView;
          if ( i == v17 )
            v17 = i->pNextView;
          else
            MEMORY[0] = (size_t)i->pNextView;
          AK::StreamMgr::CAkAutoStmBase::DestroyBuffer((AK::StreamMgr::CAkAutoStmBase *)((char *)this - 120), i);
          if ( !pNextView )
            break;
        }
        AK::StreamMgr::CAkIOThread::NotifyMemChange((AK::StreamMgr::CAkIOThread *)this[-1].m_listBuffers.m_pFirst);
        LeaveCriticalSection((LPCRITICAL_SECTION)&m_pFirst[1]);
      }
    }
    (*(void (__fastcall **)(unsigned __int64 *, unsigned __int64))(this[-1].m_lockStatus.m_csLock.SpinCount + 72))(
      &this[-1].m_lockStatus.m_csLock.SpinCount,
      m_hBlockEvent);
    AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus((AK::StreamMgr::CAkAutoStmBase *)((char *)this - 120));
    LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  }
  return 1i64;
}

// File Line: 1840
// RVA: 0xAA4C00
__int64 __fastcall AK::StreamMgr::CAkAutoStmBase::SetMinimalBufferSize(
        AK::StreamMgr::CAkAutoStmBase *this,
        unsigned int in_uMinBufferSize)
{
  unsigned int m_pFileDesc; // r15d
  unsigned int v5; // ebp
  AK::StreamMgr::CAkClientThreadAwareVtbl *vfptr; // rax
  AkAutoStmBufSettings in_pBufferSettings; // [rsp+20h] [rbp-28h] BYREF

  m_pFileDesc = (unsigned int)this->m_pFileDesc;
  in_pBufferSettings.uMinBufferSize = in_uMinBufferSize;
  in_pBufferSettings.uBufferSize = 0;
  in_pBufferSettings.uBlockSize = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  v5 = AK::StreamMgr::CAkAutoStmBase::SetBufferingSettings(
         (AK::StreamMgr::CAkAutoStmBase *)((char *)this - 120),
         &in_pBufferSettings,
         this[-1].m_listBuffers.m_pFirst[10].m_uOffsetInBlock);
  if ( v5 == 1 )
  {
    if ( LODWORD(this->m_pFileDesc) > m_pFileDesc )
      (*(void (__fastcall **)(unsigned __int64 *, _QWORD))(this[-1].m_lockStatus.m_csLock.SpinCount + 80))(
        &this[-1].m_lockStatus.m_csLock.SpinCount,
        in_uMinBufferSize);
  }
  else
  {
    vfptr = this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr;
    BYTE2(this->m_lockStatus.m_csLock.LockSemaphore) |= 2u;
    ((void (__fastcall *)(AK::StreamMgr::CAkAutoStmBase *))vfptr[12].__vecDelDtor)(this);
    AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus((AK::StreamMgr::CAkAutoStmBase *)((char *)this - 120));
    if ( LOBYTE(this[-1].m_pDevice) )
      AK::StreamMgr::CAkIOThread::SignalIOCompleted(
        (AK::StreamMgr::CAkIOThread *)this[-1].m_listBuffers.m_pFirst,
        (AK::StreamMgr::CAkAutoStmBase *)((char *)this - 120));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  return v5;
}

// File Line: 1873
// RVA: 0xAA4ED0
__int64 __fastcall AK::StreamMgr::CAkStdStmBase::SetStreamName(
        AK::StreamMgr::CAkStdStmBase *this,
        const wchar_t *in_pszStreamName)
{
  void *v3; // rdx
  __int64 v5; // rbx
  unsigned __int64 v6; // rbx
  wchar_t *v7; // rax

  v3 = *(void **)&this[-1].m_uTotalScheduledSize;
  if ( v3 )
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v3);
  if ( in_pszStreamName )
  {
    v5 = -1i64;
    do
      ++v5;
    while ( in_pszStreamName[v5] );
    v6 = v5 + 1;
    v7 = (wchar_t *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 2 * v6);
    *(_QWORD *)&this[-1].m_uTotalScheduledSize = v7;
    if ( !v7 )
      return 52i64;
    AKPLATFORM::SafeStrCpy(v7, in_pszStreamName, v6);
  }
  return 1i64;
}

// File Line: 1893
// RVA: 0xAA3870
__int64 __fastcall AK::StreamMgr::CAkStdStmBase::GetBlockSize(AK::StreamMgr::CAkStdStmBase *this)
{
  return *((unsigned int *)&this[-1] + 44);
}

// File Line: 1904
// RVA: 0xAA4F60
__int64 __fastcall AK::StreamMgr::CAkAutoStmBase::Start(AK::StreamMgr::CAkAutoStmBase *this)
{
  char v2; // dl
  unsigned __int64 *p_SpinCount; // rcx
  char v4; // al
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rbx

  if ( (BYTE2(this->m_lockStatus.m_csLock.LockSemaphore) & 1) == 0 )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
    v2 = *((_BYTE *)&this[-1] + 197);
    BYTE2(this->m_lockStatus.m_csLock.LockSemaphore) |= 1u;
    p_SpinCount = &this[-1].m_lockStatus.m_csLock.SpinCount;
    v4 = (v2 & 4) == 0 && (v2 & 8) == 0;
    *((_BYTE *)p_SpinCount + 117) = v2 ^ (v2 ^ (v4 << 6)) & 0x40;
    AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus((AK::StreamMgr::CAkAutoStmBase *)p_SpinCount);
    LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
    m_pFirst = this[-1].m_listBuffers.m_pFirst;
    EnterCriticalSection((LPCRITICAL_SECTION)&m_pFirst[1]);
    AK::StreamMgr::CAkIOThread::NotifyMemChange((AK::StreamMgr::CAkIOThread *)this[-1].m_listBuffers.m_pFirst);
    LeaveCriticalSection((LPCRITICAL_SECTION)&m_pFirst[1]);
    *(_QWORD *)&this[-1].m_listBuffers.m_ulNumListItems = *(_QWORD *)&this[-1].m_listBuffers.m_pFirst[4].m_uOffsetInBlock;
  }
  return (unsigned int)((BYTE2(this->m_lockStatus.m_csLock.LockSemaphore) & 2) != 0) + 1;
}

// File Line: 1929
// RVA: 0xAA5000
__int64 __fastcall AK::StreamMgr::CAkAutoStmBase::Stop(AK::StreamMgr::CAkAutoStmBase *this)
{
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  BYTE2(this->m_lockStatus.m_csLock.LockSemaphore) &= ~1u;
  *((_BYTE *)&this[-1] + 197) &= ~0x40u;
  AK::StreamMgr::CAkAutoStmBase::Flush((AK::StreamMgr::CAkAutoStmBase *)((char *)this - 120));
  LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  return 1i64;
}

// File Line: 1943
// RVA: 0xAA3AE0
void *(__fastcall *__fastcall AK::StreamMgr::CAkAutoStmBase::GetPosition(
        AK::StreamMgr::CAkAutoStmBase *this,
        bool *out_pbEndOfStream))(AK::IAkAutoStream *this, unsigned int)
{
  __int64 v4; // rax
  void *(__fastcall *m_hBlockEvent)(AK::IAkAutoStream *, unsigned int); // rdi

  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  v4 = *(_QWORD *)&this->m_lockStatus.m_csLock.LockCount;
  if ( v4 )
    m_hBlockEvent = (void *(__fastcall *)(AK::IAkAutoStream *, unsigned int))(**(_QWORD **)(v4 + 8)
                                                                            + *(unsigned int *)(v4 + 16));
  else
    m_hBlockEvent = (void *(__fastcall *)(AK::IAkAutoStream *, unsigned int))this->m_hBlockEvent;
  if ( out_pbEndOfStream )
    *out_pbEndOfStream = (char *)m_hBlockEvent >= (char *)this[-1].AK::IAkAutoStream::vfptr->__vecDelDtor;
  LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  return m_hBlockEvent;
}

// File Line: 1966
// RVA: 0xAA4CC0
__int64 __fastcall AK::StreamMgr::CAkAutoStmBase::SetPosition(
        AK::StreamMgr::CAkAutoStmBase *this,
        __int64 in_iMoveOffset,
        AkMoveMethod in_eMoveMethod,
        __int64 *out_piRealOffset)
{
  signed __int64 v6; // rbx
  __int64 v8; // rdx
  int v9; // edi

  v6 = in_iMoveOffset;
  if ( out_piRealOffset )
    *out_piRealOffset = 0i64;
  if ( in_eMoveMethod )
  {
    if ( in_eMoveMethod == AK_MoveCurrent )
    {
      v6 = (signed __int64)this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr[13].__vecDelDtor(
                             this,
                             0i64)
         + in_iMoveOffset;
    }
    else
    {
      if ( in_eMoveMethod != AK_MoveEnd )
        return 31i64;
      v6 = (signed __int64)this[-1].AK::IAkAutoStream::vfptr->__vecDelDtor + in_iMoveOffset;
    }
  }
  if ( v6 < 0 )
    return 31i64;
  v8 = v6 % *(unsigned int *)&this[-1].m_uNextToGrant;
  if ( v8 )
    v6 -= v8;
  if ( out_piRealOffset )
  {
    if ( in_eMoveMethod )
    {
      v9 = in_eMoveMethod - 1;
      if ( v9 )
      {
        if ( v9 == 1 )
          *out_piRealOffset = v6 - (unsigned __int64)this[-1].AK::IAkAutoStream::vfptr->__vecDelDtor;
      }
      else
      {
        *out_piRealOffset = v6
                          - (unsigned __int64)this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr[13].__vecDelDtor(
                                                this,
                                                0i64);
      }
    }
    else
    {
      *out_piRealOffset = v6;
    }
  }
  AK::StreamMgr::CAkAutoStmBase::ForceFilePosition((AK::StreamMgr::CAkAutoStmBase *)((char *)this - 120), v6);
  return 1i64;
}

// File Line: 2037
// RVA: 0xAA39C0
bool __fastcall AK::StreamMgr::CAkAutoStmBase::GetBufferOrReserveCacheBlock(
        AK::StreamMgr::CAkAutoStmBase *this,
        void **out_pBuffer,
        unsigned int *out_uSize)
{
  void *Buffer; // rax

  if ( (*((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 0x10) == 0 )
    return 0;
  Buffer = AK::StreamMgr::CAkAutoStmBase::GetReadBuffer(this, out_uSize);
  *out_pBuffer = Buffer;
  if ( Buffer )
    return 1;
  if ( this->m_pDevice->AK::StreamMgr::CAkStmTask::vfptr[2].__vecDelDtor(this->m_pDevice, this) )
    *out_pBuffer = AK::StreamMgr::CAkAutoStmBase::GetReadBuffer(this, out_uSize);
  return *out_pBuffer != 0i64;
}

// File Line: 2071
// RVA: 0xAA3880
__int64 __fastcall AK::StreamMgr::CAkAutoStmBase::GetBuffer(
        AK::StreamMgr::CAkAutoStmBase *this,
        void **out_pBuffer,
        unsigned int *out_uSize,
        bool in_bWait)
{
  void *Buffer; // rax
  void *v9; // rax
  __int64 result; // rax

  *out_pBuffer = 0i64;
  *out_uSize = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  Buffer = AK::StreamMgr::CAkAutoStmBase::GetReadBuffer(
             (AK::StreamMgr::CAkAutoStmBase *)((char *)this - 120),
             out_uSize);
  *out_pBuffer = Buffer;
  if ( !Buffer
    && (BYTE2(this->m_lockStatus.m_csLock.LockSemaphore) & 2) == 0
    && (AK::StreamMgr::CAkAutoStmBase::GetBufferOrReserveCacheBlock(
          (AK::StreamMgr::CAkAutoStmBase *)((char *)this - 120),
          out_pBuffer,
          out_uSize)
     || in_bWait)
    && !*out_pBuffer )
  {
    do
    {
      if ( (BYTE2(this->m_lockStatus.m_csLock.LockSemaphore) & 2) != 0
        || (*((_BYTE *)&this[-1] + 197) & 0x20) == 0 && !HIDWORD(this->m_pDeferredOpenData) )
      {
        break;
      }
      AK::StreamMgr::CAkClientThreadAware::SetBlockedStatus((AK::StreamMgr::CAkAutoStmBase *)((char *)this - 120));
      LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
      AK::StreamMgr::CAkIOThread::WaitForIOCompletion(
        (AK::StreamMgr::CAkIOThread *)this[-1].m_listBuffers.m_pFirst,
        (AK::StreamMgr::CAkAutoStmBase *)((char *)this - 120));
      EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
      v9 = AK::StreamMgr::CAkAutoStmBase::GetReadBuffer(
             (AK::StreamMgr::CAkAutoStmBase *)((char *)this - 120),
             out_uSize);
      *out_pBuffer = v9;
    }
    while ( !v9 );
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  if ( (BYTE2(this->m_lockStatus.m_csLock.LockSemaphore) & 2) != 0 )
    return 2i64;
  if ( *out_pBuffer )
  {
    if ( (*((_BYTE *)&this[-1] + 197) & 4) == 0 )
      return 45i64;
    result = 17i64;
    if ( this->m_hBlockEvent < (void *)this[-1].AK::IAkAutoStream::vfptr->__vecDelDtor )
      return 45i64;
  }
  else if ( (*((_BYTE *)&this[-1] + 197) & 4) != 0
         && this->m_hBlockEvent >= (void *)this[-1].AK::IAkAutoStream::vfptr->__vecDelDtor )
  {
    return 17i64;
  }
  else
  {
    return 46i64;
  }
  return result;
}

// File Line: 2150
// RVA: 0xAA41D0
__int64 __fastcall AK::StreamMgr::CAkAutoStmBase::ReleaseBuffer(AK::StreamMgr::CAkAutoStmBase *this)
{
  _RTL_CRITICAL_SECTION *p_m_uNextExpectedUserPosition; // rbx
  AK::StreamMgr::AkMemBlock *v3; // rsi
  AK::StreamMgr::CAkStmMemView *m_pFirst; // r14
  _QWORD *v5; // rax
  AK::StreamMgr::AkMemBlock *pData; // rdx
  AK::StreamMgr::CAkStmMemView *v7; // rbp
  AK::StreamMgr::AkMemBlock *m_pBlock; // rax

  p_m_uNextExpectedUserPosition = (_RTL_CRITICAL_SECTION *)&this[-1].m_uNextExpectedUserPosition;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  if ( LOBYTE(this->m_lockStatus.m_csLock.LockSemaphore) )
  {
    v3 = *(AK::StreamMgr::AkMemBlock **)&this->m_lockStatus.m_csLock.LockCount;
    m_pFirst = this[-1].m_listBuffers.m_pFirst;
    EnterCriticalSection((LPCRITICAL_SECTION)&m_pFirst[1]);
    v5 = *(_QWORD **)&this->m_lockStatus.m_csLock.LockCount;
    if ( v5 )
    {
      if ( *v5 )
      {
        *(_QWORD *)&this->m_lockStatus.m_csLock.LockCount = *v5;
      }
      else
      {
        *(_QWORD *)&this->m_lockStatus.m_csLock.LockCount = 0i64;
        this->m_lockStatus.m_csLock.OwningThread = 0i64;
      }
      --LODWORD(this->m_lockStatus.m_csLock.DebugInfo);
    }
    pData = (AK::StreamMgr::AkMemBlock *)v3->pData;
    v7 = this[-1].m_listBuffers.m_pFirst;
    v3->pData = 0i64;
    if ( pData )
      AK::StreamMgr::CAkIOMemMgr::ReleaseBlock((AK::StreamMgr::CAkIOMemMgr *)&v7[7], pData);
    m_pBlock = v7[11].m_pBlock;
    if ( m_pBlock )
    {
      v3->uPosition = (unsigned __int64)m_pBlock;
      v7[11].m_pBlock = v3;
    }
    else
    {
      v7[11].m_pBlock = v3;
      v3->uPosition = 0i64;
    }
    AK::StreamMgr::CAkIOThread::NotifyMemChange((AK::StreamMgr::CAkIOThread *)this[-1].m_listBuffers.m_pFirst);
    LeaveCriticalSection((LPCRITICAL_SECTION)&m_pFirst[1]);
    --LOBYTE(this->m_lockStatus.m_csLock.LockSemaphore);
    AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus((AK::StreamMgr::CAkAutoStmBase *)((char *)this - 120));
    LeaveCriticalSection(p_m_uNextExpectedUserPosition);
    return 1i64;
  }
  else
  {
    LeaveCriticalSection(p_m_uNextExpectedUserPosition);
    return 2i64;
  }
}

// File Line: 2190
// RVA: 0xAA40B0
__int64 __fastcall AK::StreamMgr::CAkAutoStmBase::QueryBufferingStatus(
        AK::StreamMgr::CAkAutoStmBase *this,
        unsigned int *out_uNumBytesAvailable)
{
  __int64 LockSemaphore_low; // rcx
  __int64 *v6; // rax
  unsigned int v7; // ebp

  if ( (BYTE2(this->m_lockStatus.m_csLock.LockSemaphore) & 2) != 0 )
    return 2i64;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  *out_uNumBytesAvailable = 0;
  LockSemaphore_low = LOBYTE(this->m_lockStatus.m_csLock.LockSemaphore);
  if ( (unsigned int)LockSemaphore_low >= LODWORD(this->m_lockStatus.m_csLock.DebugInfo) )
  {
    v7 = 46;
  }
  else
  {
    v6 = *(__int64 **)&this->m_lockStatus.m_csLock.LockCount;
    v7 = 45;
    if ( LOBYTE(this->m_lockStatus.m_csLock.LockSemaphore) )
    {
      do
      {
        v6 = (__int64 *)*v6;
        --LockSemaphore_low;
      }
      while ( LockSemaphore_low );
    }
    for ( ; v6; v6 = (__int64 *)*v6 )
      *out_uNumBytesAvailable += *(_DWORD *)(v6[1] + 24) - *((_DWORD *)v6 + 4);
  }
  if ( (*((_BYTE *)&this[-1] + 197) & 0x20) == 0 && HIDWORD(this->m_pDeferredOpenData) <= *out_uNumBytesAvailable
    || LOBYTE(this[-1].m_listBuffers.m_pFirst[4].m_pBlock) )
  {
    v7 = 17;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  return v7;
}

// File Line: 2237
// RVA: 0xAA3AC0
__int64 __fastcall AK::StreamMgr::CAkAutoStmBase::GetNominalBuffering(AK::StreamMgr::CAkAutoStmBase *this)
{
  return (unsigned int)(int)(float)(*((float *)&this[-1].m_listBuffers.m_pFirst[10] + 5)
                                  * *((float *)&this->m_bIsBlocked + 1));
}

// File Line: 2251
// RVA: 0xAA4040
void __fastcall AK::StreamMgr::CAkAutoStmBase::OnFileDeferredOpen(AK::StreamMgr::CAkAutoStmBase *this)
{
  AK::IAkAutoStreamVtbl *vfptr; // rax
  AkFileDesc *m_pFileDesc; // rcx
  char v4; // [rsp+20h] [rbp-18h] BYREF
  unsigned int iFileSize; // [rsp+28h] [rbp-10h]

  vfptr = this->AK::IAkAutoStream::vfptr;
  *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) |= 0x10u;
  vfptr->GetHeuristics(&this->AK::IAkAutoStream, (AkAutoStmHeuristics *)&v4);
  m_pFileDesc = this->m_pFileDesc;
  if ( iFileSize > m_pFileDesc->iFileSize )
  {
    iFileSize = m_pFileDesc->iFileSize;
    this->AK::IAkAutoStream::vfptr->SetHeuristics(&this->AK::IAkAutoStream, (AkAutoStmHeuristics *)&v4);
  }
}

// File Line: 2271
// RVA: 0xAA2C20
void __fastcall AK::StreamMgr::CAkAutoStmBase::AddMemView(
        AK::StreamMgr::CAkAutoStmBase *this,
        AK::StreamMgr::CAkStmMemView *in_pMemView,
        bool in_bStoreData)
{
  AK::StreamMgr::CAkStmMemView *m_pLast; // rax
  AK::StreamMgr::CAkDeviceBase *m_pDevice; // rbx

  if ( !in_bStoreData
    || (*((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) & 8) != 0
    || (*((_BYTE *)this + 194) & 2) != 0 )
  {
    m_pDevice = this->m_pDevice;
    EnterCriticalSection(&m_pDevice->m_lockSems.m_csLock);
    AK::StreamMgr::CAkAutoStmBase::DestroyBuffer(this, in_pMemView);
    AK::StreamMgr::CAkIOThread::NotifyMemChange(this->m_pDevice);
    LeaveCriticalSection(&m_pDevice->m_lockSems.m_csLock);
  }
  else
  {
    *((_DWORD *)in_pMemView + 5) &= ~4u;
    *((_DWORD *)in_pMemView + 5) |= 3u;
    in_pMemView->pNextView = 0i64;
    m_pLast = this->m_listBuffers.m_pLast;
    if ( m_pLast )
    {
      m_pLast->pNextView = in_pMemView;
      ++this->m_listBuffers.m_ulNumListItems;
    }
    else
    {
      ++this->m_listBuffers.m_ulNumListItems;
      this->m_listBuffers.m_pFirst = in_pMemView;
    }
    this->m_listBuffers.m_pLast = in_pMemView;
  }
}

// File Line: 2319
// RVA: 0xAA5130
void __fastcall AK::StreamMgr::CAkAutoStmBase::UpdateTaskStatus(
        AK::StreamMgr::CAkAutoStmBase *this,
        AKRESULT in_eIOResult)
{
  if ( in_eIOResult == AK_Fail )
  {
    *((_BYTE *)this + 194) |= 2u;
    this->AK::IAkAutoStream::vfptr->Stop(&this->AK::IAkAutoStream);
  }
  AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus(this);
  if ( this->m_bIsBlocked )
    AK::StreamMgr::CAkIOThread::SignalIOCompleted(this->m_pDevice, this);
}

// File Line: 2342
// RVA: 0xAA3F30
void __fastcall AK::StreamMgr::CAkAutoStmBase::Kill(AK::StreamMgr::CAkAutoStmBase *this)
{
  AK::IAkAutoStreamVtbl *vfptr; // rax

  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  vfptr = this->AK::IAkAutoStream::vfptr;
  *((_BYTE *)this + 194) |= 2u;
  vfptr->Stop(&this->AK::IAkAutoStream);
  AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus(this);
  if ( this->m_bIsBlocked )
    AK::StreamMgr::CAkIOThread::SignalIOCompleted(this->m_pDevice, this);
  LeaveCriticalSection(&this->m_lockStatus.m_csLock);
}

// File Line: 2350
// RVA: 0xAA3230
float __fastcall AK::StreamMgr::CAkAutoStmBase::EffectiveDeadline(AK::StreamMgr::CAkAutoStmBase *this)
{
  return (float)(int)this->m_uVirtualBufferingSize / this->m_fThroughput;
}

// File Line: 2406
// RVA: 0xAA3740
void __fastcall AK::StreamMgr::CAkAutoStmBase::ForceFilePosition(
        AK::StreamMgr::CAkAutoStmBase *this,
        unsigned __int64 in_uNewPosition)
{
  unsigned int m_uNextToGrant; // ecx
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rax
  __int64 v6; // rdx
  AK::StreamMgr::CAkAutoStmBase *v7; // rcx

  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  m_uNextToGrant = (unsigned __int8)this->m_uNextToGrant;
  this->m_uNextExpectedUserPosition = in_uNewPosition;
  if ( m_uNextToGrant >= this->m_listBuffers.m_ulNumListItems )
  {
    this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr[9].__vecDelDtor(this, in_uNewPosition);
    v7 = this;
LABEL_8:
    AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus(v7);
    goto LABEL_9;
  }
  m_pFirst = this->m_listBuffers.m_pFirst;
  if ( m_uNextToGrant )
  {
    v6 = m_uNextToGrant;
    do
    {
      m_pFirst = m_pFirst->pNextView;
      --v6;
    }
    while ( v6 );
  }
  v7 = this;
  if ( m_pFirst->m_pBlock->uPosition + m_pFirst->m_uOffsetInBlock == in_uNewPosition )
    goto LABEL_8;
  AK::StreamMgr::CAkAutoStmBase::Flush(this);
LABEL_9:
  LeaveCriticalSection(&this->m_lockStatus.m_csLock);
}

// File Line: 2440
// RVA: 0xAA5050
void __fastcall AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus(AK::StreamMgr::CAkAutoStmBase *this)
{
  unsigned __int64 iFileSize; // rbx
  char v3; // al
  char v4; // al
  char v5; // cl
  char v6; // al
  char v7; // al
  AK::StreamMgr::CAkDeviceBase *m_pDevice; // rcx
  char v9; // al
  AK::StreamMgr::CAkDeviceBase *v10; // rcx

  if ( this->m_uLoopEnd
    || (iFileSize = this->m_pFileDesc->iFileSize,
        ((__int64 (__fastcall *)(AK::StreamMgr::CAkAutoStmBase *))this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr[7].__vecDelDtor)(this) < iFileSize)
    || (v3 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117), (v3 & 0x10) == 0) )
  {
    *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) &= ~4u;
    v5 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117);
    v6 = (*((_BYTE *)this + 194) & 1) != 0 && (v5 & 8) == 0;
    v4 = v5 ^ (v5 ^ (v6 << 6)) & 0x40;
  }
  else
  {
    v4 = v3 & 0xBB | 4;
  }
  *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = v4;
  if ( (v4 & 0x40) != 0
    && (float)(int)this->m_uVirtualBufferingSize < (float)(this->m_pDevice->m_fTargetAutoStmBufferLength
                                                         * this->m_fThroughput)
    || (v4 & 8) != 0
    && ((unsigned __int8 (__fastcall *)(AK::StreamMgr::CAkAutoStmBase *))this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr[1].__vecDelDtor)(this) )
  {
    v7 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117);
    if ( (v7 & 0x20) == 0 )
    {
      m_pDevice = this->m_pDevice;
      *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = v7 | 0x20;
      AK::StreamMgr::CAkIOThread::AutoSemIncr(m_pDevice);
    }
  }
  else
  {
    v9 = *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117);
    if ( (v9 & 0x20) != 0 )
    {
      v10 = this->m_pDevice;
      *((_BYTE *)&this->AK::StreamMgr::CAkStmTask + 117) = v9 & 0xDF;
      AK::StreamMgr::CAkIOThread::AutoSemDecr(v10);
    }
  }
}

// File Line: 2492
// RVA: 0xAA3B80
char *__fastcall AK::StreamMgr::CAkAutoStmBase::GetReadBuffer(
        AK::StreamMgr::CAkAutoStmBase *this,
        unsigned int *out_uSize)
{
  unsigned int m_uNextToGrant; // r8d
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rbx
  __int64 v6; // rax
  AK::StreamMgr::AkMemBlock *m_pBlock; // rdx
  __int64 m_uOffsetInBlock; // r8
  unsigned __int64 uPosition; // r9
  unsigned __int64 m_uLoopEnd; // rcx
  unsigned int uAvailableSize; // ecx

  m_uNextToGrant = (unsigned __int8)this->m_uNextToGrant;
  if ( m_uNextToGrant >= this->m_listBuffers.m_ulNumListItems )
  {
    *out_uSize = 0;
    return 0i64;
  }
  else
  {
    m_pFirst = this->m_listBuffers.m_pFirst;
    if ( this->m_uNextToGrant )
    {
      v6 = (unsigned __int8)this->m_uNextToGrant;
      do
      {
        m_pFirst = m_pFirst->pNextView;
        --v6;
      }
      while ( v6 );
    }
    if ( m_pFirst->m_pBlock->uPosition + m_pFirst->m_uOffsetInBlock == this->m_uNextExpectedUserPosition )
    {
      this->m_uNextToGrant = m_uNextToGrant + 1;
      this->m_uNextExpectedUserPosition = m_pFirst->m_pBlock->uPosition + m_pFirst->m_pBlock->uAvailableSize;
      *out_uSize = m_pFirst->m_pBlock->uAvailableSize - m_pFirst->m_uOffsetInBlock;
      m_pBlock = m_pFirst->m_pBlock;
      m_uOffsetInBlock = m_pFirst->m_uOffsetInBlock;
      uPosition = m_pBlock->uPosition;
      m_uLoopEnd = this->m_uLoopEnd;
      if ( m_pBlock->uPosition + m_uOffsetInBlock >= m_uLoopEnd || uPosition + m_pBlock->uAvailableSize <= m_uLoopEnd )
        uAvailableSize = m_pBlock->uAvailableSize;
      else
        uAvailableSize = m_uLoopEnd - uPosition;
      this->m_uVirtualBufferingSize -= uAvailableSize - m_uOffsetInBlock;
      AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus(this);
      return (char *)m_pFirst->m_pBlock->pData + m_pFirst->m_uOffsetInBlock;
    }
    else
    {
      this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr[11].__vecDelDtor(this, 0);
      AK::StreamMgr::CAkAutoStmBase::Flush(this);
      *out_uSize = 0;
      return 0i64;
    }
  }
}

// File Line: 2535
// RVA: 0xAA3520
void __fastcall AK::StreamMgr::CAkAutoStmBase::Flush(AK::StreamMgr::CAkAutoStmBase *this)
{
  __int64 m_uNextToGrant; // rax
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rbx
  AK::StreamMgr::CAkStmMemView *v4; // rsi
  AK::StreamMgr::CAkDeviceBase *m_pDevice; // r14
  AK::StreamMgr::CAkStmMemView *pNextView; // rbp
  AK::StreamMgr::CAkStmMemView *v7; // [rsp+20h] [rbp-28h]

  ((void (__fastcall *)(AK::StreamMgr::CAkAutoStmBase *))this->AK::StreamMgr::CAkStmTask::AK::StreamMgr::CAkClientThreadAware::vfptr[8].__vecDelDtor)(this);
  m_uNextToGrant = (unsigned __int8)this->m_uNextToGrant;
  if ( this->m_listBuffers.m_ulNumListItems > (unsigned int)m_uNextToGrant )
  {
    m_pFirst = this->m_listBuffers.m_pFirst;
    v4 = 0i64;
    if ( this->m_uNextToGrant )
    {
      do
      {
        v4 = m_pFirst;
        m_pFirst = m_pFirst->pNextView;
        --m_uNextToGrant;
      }
      while ( m_uNextToGrant );
    }
    m_pDevice = this->m_pDevice;
    EnterCriticalSection(&m_pDevice->m_lockSems.m_csLock);
    if ( m_pFirst )
    {
      while ( 1 )
      {
        pNextView = m_pFirst->pNextView;
        v7 = m_pFirst->pNextView;
        if ( m_pFirst == this->m_listBuffers.m_pFirst )
          this->m_listBuffers.m_pFirst = pNextView;
        else
          v4->pNextView = pNextView;
        if ( m_pFirst == this->m_listBuffers.m_pLast )
          this->m_listBuffers.m_pLast = v4;
        --this->m_listBuffers.m_ulNumListItems;
        AK::StreamMgr::CAkAutoStmBase::DestroyBuffer(this, m_pFirst);
        if ( !pNextView )
          break;
        m_pFirst = v7;
      }
    }
    AK::StreamMgr::CAkIOThread::NotifyMemChange(this->m_pDevice);
    LeaveCriticalSection(&m_pDevice->m_lockSems.m_csLock);
  }
  AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus(this);
}

