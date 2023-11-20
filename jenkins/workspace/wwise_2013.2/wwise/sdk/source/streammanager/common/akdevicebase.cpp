// File Line: 50
// RVA: 0xAA27C0
void __fastcall AK::StreamMgr::CAkDeviceBase::CAkDeviceBase(AK::StreamMgr::CAkDeviceBase *this, AK::StreamMgr::IAkLowLevelIOHook *in_pLowLevelHook)
{
  AK::StreamMgr::IAkLowLevelIOHook *v2; // rbx
  AK::StreamMgr::CAkDeviceBase *v3; // rdi

  v2 = in_pLowLevelHook;
  v3 = this;
  AK::StreamMgr::CAkIOThread::CAkIOThread((AK::StreamMgr::CAkIOThread *)&this->vfptr);
  v3->vfptr = (AK::StreamMgr::CAkIOThreadVtbl *)&AK::StreamMgr::CAkDeviceBase::`vftable';
  v3->m_listTasks.m_pFirst = 0i64;
  InitializeCriticalSection(&v3->m_lockTasksList.m_csLock);
  AK::StreamMgr::CAkIOMemMgr::CAkIOMemMgr(&v3->m_mgrMemIO);
  v3->m_pLowLevelHook = v2;
  v3->m_poolStmMemView.m_pFirst = 0i64;
  v3->m_pStmMemViewMem = 0i64;
}

// File Line: 54
// RVA: 0xAA2920
void __fastcall AK::StreamMgr::CAkDeviceBase::~CAkDeviceBase(AK::StreamMgr::CAkDeviceBase *this)
{
  AK::StreamMgr::CAkDeviceBase *v1; // rbx
  AK::StreamMgr::CAkIOMemMgr *v2; // rcx

  v1 = this;
  v2 = &this->m_mgrMemIO;
  *(_QWORD *)&v2[-3].m_bUseCache = &AK::StreamMgr::CAkDeviceBase::`vftable';
  AK::StreamMgr::CAkIOMemMgr::~CAkIOMemMgr(v2);
  DeleteCriticalSection(&v1->m_lockTasksList.m_csLock);
  AK::StreamMgr::CAkIOThread::~CAkIOThread((AK::StreamMgr::CAkIOThread *)&v1->vfptr);
}

// File Line: 62
// RVA: 0xAA3E00
AKRESULT __fastcall AK::StreamMgr::CAkDeviceBase::Init(AK::StreamMgr::CAkDeviceBase *this, AkDeviceSettings *in_settings, unsigned int in_deviceID)
{
  AK::StreamMgr::CAkDeviceBase *v3; // rdi
  unsigned int v4; // ecx
  AkDeviceSettings *v5; // rbx
  AKRESULT result; // eax
  unsigned int v7; // eax

  v3 = this;
  v4 = in_settings->uGranularity;
  v5 = in_settings;
  if ( !v4
    || in_settings->uIOMemorySize && in_settings->fTargetAutoStmBufferLength < 0.0
    || in_settings->uSchedulerTypeFlags & 2 && in_settings->uMaxConcurrentIO - 1 > 0x3FF )
  {
    return 31;
  }
  v3->m_uGranularity = v4;
  v3->m_fTargetAutoStmBufferLength = in_settings->fTargetAutoStmBufferLength;
  v7 = in_settings->uMaxConcurrentIO;
  v3->m_deviceID = in_deviceID;
  v3->m_uMaxConcurrentIO = v7;
  if ( AK::StreamMgr::CAkIOMemMgr::Init(&v3->m_mgrMemIO, in_settings) == 1 )
    result = AK::StreamMgr::CAkIOThread::Init((AK::StreamMgr::CAkIOThread *)&v3->vfptr, &v5->threadProperties);
  else
    result = 2;
  return result;
}

// File Line: 99
// RVA: 0xAA3000
void __fastcall AK::StreamMgr::CAkDeviceBase::Destroy(AK::StreamMgr::CAkDeviceBase *this)
{
  AK::StreamMgr::CAkDeviceBase *v1; // rdi
  AK::StreamMgr::CAkStmMemView *v2; // rax
  AK::StreamMgr::CAkStmMemView **v3; // rdx
  AK::StreamMgr::CAkStmMemView *v4; // rcx
  int v5; // ebx
  __int128 v6; // [rsp+20h] [rbp-38h]
  __m128i v7; // [rsp+30h] [rbp-28h]
  __m128i v8; // [rsp+40h] [rbp-18h]

  v1 = this;
  AK::StreamMgr::CAkIOThread::Term((AK::StreamMgr::CAkIOThread *)&this->vfptr);
  if ( v1->m_pStmMemViewMem )
  {
    if ( v1->m_mgrMemIO.m_bUseCache )
    {
      v2 = v1->m_poolStmMemView.m_pFirst;
      v3 = 0i64;
      if ( v2 )
      {
        while ( 1 )
        {
          v4 = v2->pNextView;
          if ( (*((_DWORD *)v2 + 5) >> 3) & 1 )
          {
            v8.m128i_i64[0] = (__int64)v2->pNextView;
            v8.m128i_i64[1] = (__int64)v3;
            if ( v2 == v1->m_poolStmMemView.m_pFirst )
              v1->m_poolStmMemView.m_pFirst = v4;
            else
              *v3 = v4;
            _mm_store_si128((__m128i *)&v6, v8);
          }
          else
          {
            v7.m128i_i64[0] = (__int64)v2->pNextView;
            v7.m128i_i64[1] = (__int64)v3;
            if ( v2 == v1->m_poolStmMemView.m_pFirst )
              v1->m_poolStmMemView.m_pFirst = v4;
            else
              *v3 = v4;
            _mm_store_si128((__m128i *)&v6, v7);
            if ( v2 )
              AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v2);
          }
          v2 = (AK::StreamMgr::CAkStmMemView *)v6;
          if ( !(_QWORD)v6 )
            break;
          v3 = (AK::StreamMgr::CAkStmMemView **)*((_QWORD *)&v6 + 1);
        }
      }
    }
    else
    {
      v1->m_poolStmMemView.m_pFirst = 0i64;
    }
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v1->m_pStmMemViewMem);
  }
  v1->m_poolStmMemView.m_pFirst = 0i64;
  AK::StreamMgr::CAkIOMemMgr::Term(&v1->m_mgrMemIO);
  v5 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
  v1->vfptr->__vecDelDtor((AK::StreamMgr::CAkIOThread *)&v1->vfptr, 0);
  AK::MemoryMgr::Free(v5, v1);
}

// File Line: 144
// RVA: 0xAA2E70
char __fastcall AK::StreamMgr::CAkDeviceBase::ClearStreams(AK::StreamMgr::CAkDeviceBase *this)
{
  AK::StreamMgr::CAkStmTask *v1; // rbx
  AK::StreamMgr::CAkStmTask *v2; // rdi
  AK::StreamMgr::CAkDeviceBase *v3; // rsi
  AK::StreamMgr::CAkClientThreadAwareVtbl *v4; // rax
  AK::StreamMgr::CAkStmTask *v5; // rax
  AK::StreamMgr::CAkClientThreadAwareVtbl *v6; // rax
  int v7; // edi
  __m128i v9; // [rsp+20h] [rbp-28h]
  __m128i v10; // [rsp+30h] [rbp-18h]

  v1 = this->m_listTasks.m_pFirst;
  v2 = 0i64;
  v3 = this;
  while ( v1 )
  {
    v4 = v1->vfptr;
    if ( *((_BYTE *)v1 + 117) & 8 )
    {
      if ( ((unsigned __int8 (__fastcall *)(AK::StreamMgr::CAkStmTask *))v4[1].__vecDelDtor)(v1) )
      {
        v5 = v1->pNextLightItem;
        v9.m128i_i64[1] = (__int64)v2;
        v9.m128i_i64[0] = (__int64)v1->pNextLightItem;
        if ( v1 == v3->m_listTasks.m_pFirst )
          v3->m_listTasks.m_pFirst = v5;
        else
          v2->pNextLightItem = v5;
        v6 = v1->vfptr;
        v7 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
        _mm_store_si128(&v10, v9);
        v6->__vecDelDtor((AK::StreamMgr::CAkClientThreadAware *)&v1->vfptr, 0);
        AK::MemoryMgr::Free(v7, v1);
        v2 = (AK::StreamMgr::CAkStmTask *)v10.m128i_i64[1];
        v1 = (AK::StreamMgr::CAkStmTask *)v10.m128i_i64[0];
        continue;
      }
    }
    else
    {
      ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *))v4[2].__vecDelDtor)(v1);
    }
    v2 = v1;
    v1 = v1->pNextLightItem;
  }
  if ( v3->m_listTasks.m_pFirst )
    return 0;
  v3->m_listTasks.m_pFirst = 0i64;
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
void __fastcall AK::StreamMgr::CAkDeviceBase::AddTask(AK::StreamMgr::CAkDeviceBase *this, AK::StreamMgr::CAkStmTask *in_pStmTask)
{
  AK::StreamMgr::CAkDeviceBase *v2; // rsi
  AK::StreamMgr::CAkStmTask *v3; // rdi
  AK::StreamMgr::CAkStmTask *v4; // rax

  v2 = this;
  v3 = in_pStmTask;
  EnterCriticalSection(&this->m_lockTasksList.m_csLock);
  v4 = v2->m_listTasks.m_pFirst;
  if ( v4 )
  {
    v3->pNextLightItem = v4;
    v2->m_listTasks.m_pFirst = v3;
  }
  else
  {
    v2->m_listTasks.m_pFirst = v3;
    v3->pNextLightItem = 0i64;
  }
  LeaveCriticalSection(&v2->m_lockTasksList.m_csLock);
}

// File Line: 216
// RVA: 0xAA4500
AK::StreamMgr::CAkStmTask *__usercall AK::StreamMgr::CAkDeviceBase::SchedulerFindNextTask@<rax>(AK::StreamMgr::CAkDeviceBase *this@<rcx>, float *out_fOpDeadline@<rdx>, float a3@<xmm0>)
{
  AK::StreamMgr::CAkDeviceBase *v3; // r15
  float *v4; // rdi
  AK::StreamMgr::CAkStmTask *v5; // r12
  __int128 v6; // di
  char v8; // al
  AK::StreamMgr::CAkStmTask *v9; // rax
  __int64 v10; // rbp
  float v11; // xmm6_4
  char v12; // r14
  char v13; // al
  AK::StreamMgr::CAkStmTask *v14; // rax
  int v15; // ebp
  char v16; // dl
  float v17; // xmm3_4
  char v18; // dl
  char v19; // al
  char v20; // cl
  __int64 v21; // rcx
  __int128 v22; // [rsp+20h] [rbp-78h]
  __m128i v23; // [rsp+30h] [rbp-68h]
  float *v24; // [rsp+A8h] [rbp+10h]

  v24 = out_fOpDeadline;
  v3 = this;
  v4 = out_fOpDeadline;
  EnterCriticalSection(&this->m_lockTasksList.m_csLock);
  QueryPerformanceCounter((LARGE_INTEGER *)&v3->m_time);
  if ( !v3->m_bDoWaitMemoryChange )
  {
    v5 = 0i64;
    v6 = (unsigned __int64)v3->m_listTasks.m_pFirst;
    if ( !(_QWORD)v6 )
      goto LABEL_3;
    while ( 1 )
    {
      v8 = *(_BYTE *)(v6 + 117);
      if ( v8 & 8 )
      {
        if ( (*(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)v6 + 8i64))(v6) )
        {
          v9 = *(AK::StreamMgr::CAkStmTask **)(v6 + 24);
          v23.m128i_i64[1] = *((_QWORD *)&v6 + 1);
          v23.m128i_i64[0] = (__int64)v9;
          if ( (AK::StreamMgr::CAkStmTask *)v6 == v3->m_listTasks.m_pFirst )
            v3->m_listTasks.m_pFirst = v9;
          else
            *(_QWORD *)(*((_QWORD *)&v6 + 1) + 24i64) = v9;
          a3 = *(float *)v23.m128i_i32;
          DWORD2(v6) = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
          _mm_store_si128((__m128i *)&v22, v23);
          if ( (_QWORD)v6 )
          {
            (**(void (__fastcall ***)(_QWORD, _QWORD))v6)(v6, 0i64);
            AK::MemoryMgr::Free(SDWORD2(v6), (void *)v6);
          }
          v6 = v22;
          goto LABEL_17;
        }
      }
      else if ( v8 & 0x40 )
      {
        (*(void (__fastcall **)(_QWORD))(*(_QWORD *)v6 + 48i64))(v6);
        *((_QWORD *)&v6 + 1) = *(_QWORD *)(v6 + 24);
        v10 = v6;
        v11 = a3;
        v12 = (*(_BYTE *)(v6 + 117) >> 5) & 1;
        if ( !*((_QWORD *)&v6 + 1) )
        {
LABEL_44:
          *v24 = v11;
          if ( !v12 )
            goto LABEL_5;
          goto LABEL_4;
        }
        while ( 2 )
        {
          v13 = *(_BYTE *)(*((_QWORD *)&v6 + 1) + 117i64);
          if ( v13 & 8 )
          {
            if ( (*(unsigned __int8 (__fastcall **)(_QWORD))(**((_QWORD **)&v6 + 1) + 8i64))(*((_QWORD *)&v6 + 1)) )
            {
              v14 = *(AK::StreamMgr::CAkStmTask **)(*((_QWORD *)&v6 + 1) + 24i64);
              v23.m128i_i64[1] = v10;
              v23.m128i_i64[0] = (__int64)v14;
              if ( (AK::StreamMgr::CAkStmTask *)*((_QWORD *)&v6 + 1) == v3->m_listTasks.m_pFirst )
                v3->m_listTasks.m_pFirst = v14;
              else
                *(_QWORD *)(v10 + 24) = v14;
              a3 = *(float *)v23.m128i_i32;
              v15 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
              _mm_store_si128((__m128i *)&v22, v23);
              if ( *((_QWORD *)&v6 + 1) )
              {
                (***((void (__fastcall ****)(_QWORD, _QWORD))&v6 + 1))(*((_QWORD *)&v6 + 1), 0i64);
                AK::MemoryMgr::Free(v15, *((void **)&v6 + 1));
              }
              v10 = *((_QWORD *)&v22 + 1);
              *((_QWORD *)&v6 + 1) = v22;
LABEL_43:
              if ( !*((_QWORD *)&v6 + 1) )
                goto LABEL_44;
              continue;
            }
LABEL_42:
            v10 = *((_QWORD *)&v6 + 1);
            *((_QWORD *)&v6 + 1) = *(_QWORD *)(*((_QWORD *)&v6 + 1) + 24i64);
            goto LABEL_43;
          }
          break;
        }
        if ( !(v13 & 0x40) )
          goto LABEL_42;
        (*(void (__fastcall **)(_QWORD))(**((_QWORD **)&v6 + 1) + 48i64))(*((_QWORD *)&v6 + 1));
        v16 = *(_BYTE *)(*((_QWORD *)&v6 + 1) + 117i64) >> 5;
        v17 = a3;
        if ( v12 )
        {
          v18 = v16 & 1;
          if ( !v18 )
            goto LABEL_42;
        }
        else
        {
          v18 = v16 & 1;
          if ( v18 )
          {
            v12 = 1;
            goto LABEL_41;
          }
        }
        if ( a3 == 0.0 )
        {
          v19 = *(_BYTE *)(*((_QWORD *)&v6 + 1) + 116i64);
          v20 = *(_BYTE *)(v6 + 116);
          if ( v19 <= v20 && v11 <= 0.0 )
          {
            if ( v19 != v20 )
              goto LABEL_42;
            v21 = v3->m_time;
            a3 = (float)(v21 - *(_DWORD *)(v6 + 88)) * (float)(1.0 / AK::g_fFreqRatio);
            if ( (float)((float)(v21 - *(_DWORD *)(*((_QWORD *)&v6 + 1) + 88i64)) * (float)(1.0 / AK::g_fFreqRatio)) <= a3 )
              goto LABEL_42;
          }
        }
        else if ( a3 >= v11 )
        {
          goto LABEL_42;
        }
        v12 = v18;
LABEL_41:
        v11 = v17;
        *(_QWORD *)&v6 = *((_QWORD *)&v6 + 1);
        goto LABEL_42;
      }
      *((_QWORD *)&v6 + 1) = v6;
      *(_QWORD *)&v6 = *(_QWORD *)(v6 + 24);
LABEL_17:
      if ( !(_QWORD)v6 )
        goto LABEL_3;
    }
  }
  v5 = AK::StreamMgr::CAkDeviceBase::ScheduleStdStmOnly(v3, v4, a3);
LABEL_3:
  *(_QWORD *)&v6 = v5;
LABEL_4:
  v5 = (AK::StreamMgr::CAkStmTask *)v6;
LABEL_5:
  LeaveCriticalSection(&v3->m_lockTasksList.m_csLock);
  return v5;
}

// File Line: 378
// RVA: 0xAA42E0
AK::StreamMgr::CAkStmTask *__usercall AK::StreamMgr::CAkDeviceBase::ScheduleStdStmOnly@<rax>(AK::StreamMgr::CAkDeviceBase *this@<rcx>, float *out_fOpDeadline@<rdx>, float a3@<xmm0>)
{
  AK::StreamMgr::CAkStmTask *v3; // rbx
  AK::StreamMgr::CAkStmTask *v4; // rdi
  float *v5; // r14
  AK::StreamMgr::CAkDeviceBase *v6; // rbp
  char v7; // al
  AK::StreamMgr::CAkStmTask *v8; // rax
  int v9; // edi
  __int128 v11; // di
  float v12; // xmm6_4
  char v13; // al
  AK::StreamMgr::CAkStmTask *v14; // rax
  float v15; // xmm3_4
  char v16; // al
  char v17; // cl
  __int64 v18; // rcx
  __int128 v19; // [rsp+20h] [rbp-58h]
  __m128i v20; // [rsp+30h] [rbp-48h]

  v3 = this->m_listTasks.m_pFirst;
  v4 = 0i64;
  v5 = out_fOpDeadline;
  v6 = this;
  if ( !v3 )
    return 0i64;
  while ( 1 )
  {
    v7 = *((_BYTE *)v3 + 117);
    if ( !(v7 & 8) )
      break;
    if ( ((unsigned __int8 (__fastcall *)(AK::StreamMgr::CAkStmTask *))v3->vfptr[1].__vecDelDtor)(v3) )
    {
      v8 = v3->pNextLightItem;
      v20.m128i_i64[1] = (__int64)v4;
      v20.m128i_i64[0] = (__int64)v8;
      if ( v3 == v6->m_listTasks.m_pFirst )
        v6->m_listTasks.m_pFirst = v8;
      else
        v4->pNextLightItem = v8;
      a3 = *(float *)v20.m128i_i32;
      v9 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
      _mm_store_si128((__m128i *)&v19, v20);
      if ( v3 )
      {
        v3->vfptr->__vecDelDtor((AK::StreamMgr::CAkClientThreadAware *)&v3->vfptr, 0);
        AK::MemoryMgr::Free(v9, v3);
      }
      v4 = (AK::StreamMgr::CAkStmTask *)*((_QWORD *)&v19 + 1);
      v3 = (AK::StreamMgr::CAkStmTask *)v19;
      goto LABEL_13;
    }
LABEL_12:
    v4 = v3;
    v3 = v3->pNextLightItem;
LABEL_13:
    if ( !v3 )
      return 0i64;
  }
  if ( v7 & 1 || !(v7 & 0x40) )
    goto LABEL_12;
  ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *))v3->vfptr[6].__vecDelDtor)(v3);
  *(_QWORD *)&v11 = v3->pNextLightItem;
  *((_QWORD *)&v11 + 1) = v3;
  v12 = a3;
  while ( (_QWORD)v11 )
  {
    v13 = *(_BYTE *)(v11 + 117);
    if ( v13 & 8 )
    {
      if ( (*(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)v11 + 8i64))(v11) )
      {
        v14 = *(AK::StreamMgr::CAkStmTask **)(v11 + 24);
        v20.m128i_i64[1] = *((_QWORD *)&v11 + 1);
        v20.m128i_i64[0] = (__int64)v14;
        if ( (AK::StreamMgr::CAkStmTask *)v11 == v6->m_listTasks.m_pFirst )
          v6->m_listTasks.m_pFirst = v14;
        else
          *(_QWORD *)(*((_QWORD *)&v11 + 1) + 24i64) = v14;
        a3 = *(float *)v20.m128i_i32;
        DWORD2(v11) = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
        _mm_store_si128((__m128i *)&v19, v20);
        if ( (_QWORD)v11 )
        {
          (**(void (__fastcall ***)(_QWORD, _QWORD))v11)(v11, 0i64);
          AK::MemoryMgr::Free(SDWORD2(v11), (void *)v11);
        }
        v11 = v19;
        continue;
      }
    }
    else
    {
      if ( v13 & 1 || !(v13 & 0x40) )
        goto LABEL_35;
      (*(void (__fastcall **)(_QWORD))(*(_QWORD *)v11 + 48i64))(v11);
      v15 = a3;
      if ( a3 == 0.0 )
      {
        v16 = *(_BYTE *)(v11 + 116);
        v17 = v3->m_priority;
        if ( v16 <= v17 && v12 <= 0.0 )
        {
          if ( v16 != v17 )
            goto LABEL_35;
          v18 = v6->m_time;
          a3 = (float)(v18 - LODWORD(v3->m_iIOStartTime)) * (float)(1.0 / AK::g_fFreqRatio);
          if ( (float)((float)(v18 - *(_DWORD *)(v11 + 88)) * (float)(1.0 / AK::g_fFreqRatio)) <= a3 )
            goto LABEL_35;
        }
LABEL_34:
        v3 = (AK::StreamMgr::CAkStmTask *)v11;
        v12 = v15;
        goto LABEL_35;
      }
      if ( a3 < v12 )
        goto LABEL_34;
    }
LABEL_35:
    *((_QWORD *)&v11 + 1) = v11;
    *(_QWORD *)&v11 = *(_QWORD *)(v11 + 24);
  }
  *v5 = v12;
  return v3;
}

// File Line: 498
// RVA: 0xAA3620
void __fastcall AK::StreamMgr::CAkDeviceBase::ForceCleanup(AK::StreamMgr::CAkDeviceBase *this, bool in_bKillLowestPriorityTask, char in_priority)
{
  AK::StreamMgr::CAkDeviceBase *v3; // rbp
  char v4; // r15
  bool v5; // r12
  _BYTE *v6; // r14
  __int128 v7; // di
  char v8; // cl
  AK::StreamMgr::CAkStmTask *v9; // rax
  __int128 v10; // [rsp+20h] [rbp-38h]
  __m128i v11; // [rsp+30h] [rbp-28h]

  v3 = this;
  v4 = in_priority;
  v5 = in_bKillLowestPriorityTask;
  EnterCriticalSection(&this->m_lockTasksList.m_csLock);
  v6 = 0i64;
  v7 = (unsigned __int64)v3->m_listTasks.m_pFirst;
  if ( !(_QWORD)v7 )
    goto LABEL_20;
  do
  {
    v8 = *(_BYTE *)(v7 + 117);
    if ( !(v8 & 8) )
    {
      if ( v5 && (!v6 || *(_BYTE *)(v7 + 116) < v6[116]) && *(_BYTE *)(v7 + 116) < v4 && v8 & 0x40 )
        v6 = (_BYTE *)v7;
LABEL_16:
      *((_QWORD *)&v7 + 1) = v7;
      *(_QWORD *)&v7 = *(_QWORD *)(v7 + 24);
      continue;
    }
    if ( !(*(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)v7 + 8i64))(v7) )
      goto LABEL_16;
    v9 = *(AK::StreamMgr::CAkStmTask **)(v7 + 24);
    v11.m128i_i64[1] = *((_QWORD *)&v7 + 1);
    v11.m128i_i64[0] = (__int64)v9;
    if ( (AK::StreamMgr::CAkStmTask *)v7 == v3->m_listTasks.m_pFirst )
      v3->m_listTasks.m_pFirst = v9;
    else
      *(_QWORD *)(*((_QWORD *)&v7 + 1) + 24i64) = v9;
    DWORD2(v7) = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
    _mm_store_si128((__m128i *)&v10, v11);
    if ( (_QWORD)v7 )
    {
      (**(void (__fastcall ***)(_QWORD, _QWORD))v7)(v7, 0i64);
      AK::MemoryMgr::Free(SDWORD2(v7), (void *)v7);
    }
    v7 = v10;
  }
  while ( (_QWORD)v7 );
  if ( v6 )
    (*(void (__fastcall **)(_BYTE *))(*(_QWORD *)v6 + 16i64))(v6);
LABEL_20:
  LeaveCriticalSection(&v3->m_lockTasksList.m_csLock);
}

// File Line: 705
// RVA: 0xAA29B0
void __fastcall AK::StreamMgr::CAkStmTask::~CAkStmTask(AK::StreamMgr::CAkStmTask *this)
{
  bool v1; // zf
  AK::StreamMgr::CAkStmTask *v2; // rbx
  AK::StreamMgr::AkDeferredOpenData *v3; // rcx
  wchar_t *v4; // rdx
  AkFileDesc *v5; // rdx

  v1 = (*((_BYTE *)this + 117) & 0x10) == 0;
  v2 = this;
  this->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkStmTask::`vftable';
  if ( !v1 )
    this->m_pDevice->m_pLowLevelHook->vfptr->Close(this->m_pDevice->m_pLowLevelHook, this->m_pFileDesc);
  v3 = v2->m_pDeferredOpenData;
  if ( v3 )
  {
    AK::StreamMgr::AkDeferredOpenData::Destroy(v3);
    v2->m_pDeferredOpenData = 0i64;
  }
  v4 = v2->m_pszStreamName;
  if ( v4 )
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v4);
  v5 = v2->m_pFileDesc;
  if ( v5 )
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v5);
  DeleteCriticalSection(&v2->m_lockStatus.m_csLock);
  AK::StreamMgr::CAkClientThreadAware::~CAkClientThreadAware((AK::StreamMgr::CAkClientThreadAware *)&v2->vfptr);
}

// File Line: 729
// RVA: 0xAA48E0
__int64 __fastcall AK::StreamMgr::CAkStmTask::SetDeferredFileOpen(AK::StreamMgr::CAkStmTask *this, AkFileDesc *in_pFileDesc, const wchar_t *in_pszFileName, AkFileSystemFlags *in_pFSFlags, AkOpenMode in_eOpenMode)
{
  AK::StreamMgr::CAkStmTask *v5; // rbx
  AK::StreamMgr::AkDeferredOpenData *v6; // rax

  *((_BYTE *)this + 117) &= 0xEFu;
  this->m_pFileDesc = in_pFileDesc;
  v5 = this;
  v6 = AK::StreamMgr::AkDeferredOpenData::Create(in_pszFileName, in_pFSFlags, in_eOpenMode);
  v5->m_pDeferredOpenData = v6;
  return 2 - (unsigned int)(v6 != 0i64);
}

// File Line: 746
// RVA: 0xAA48A0
__int64 __fastcall AK::StreamMgr::CAkStmTask::SetDeferredFileOpen(AK::StreamMgr::CAkStmTask *this, AkFileDesc *in_pFileDesc, unsigned int in_fileID, AkFileSystemFlags *in_pFSFlags, AkOpenMode in_eOpenMode)
{
  AK::StreamMgr::CAkStmTask *v5; // rbx
  AK::StreamMgr::AkDeferredOpenData *v6; // rax

  *((_BYTE *)this + 117) &= 0xEFu;
  this->m_pFileDesc = in_pFileDesc;
  v5 = this;
  v6 = AK::StreamMgr::AkDeferredOpenData::Create(in_fileID, in_pFSFlags, in_eOpenMode);
  v5->m_pDeferredOpenData = v6;
  return 2 - (unsigned int)(v6 != 0i64);
}

// File Line: 767
// RVA: 0xAA32C0
signed __int64 __fastcall AK::StreamMgr::CAkStmTask::EnsureFileIsOpen(AK::StreamMgr::CAkStmTask *this)
{
  AK::StreamMgr::AkDeferredOpenData *v1; // rdx
  AK::StreamMgr::CAkStmTask *v2; // rbx
  int v3; // eax
  signed __int64 v4; // r9
  __int64 v5; // r8
  AK::StreamMgr::IAkFileLocationResolverVtbl *v6; // r10
  AKRESULT v7; // eax
  AKRESULT v8; // edi
  AK::StreamMgr::AkDeferredOpenData *v9; // rcx
  AkFileDesc *v11; // [rsp+28h] [rbp-10h]
  char v12; // [rsp+40h] [rbp+8h]

  v1 = this->m_pDeferredOpenData;
  v2 = this;
  if ( !v1 || *((_BYTE *)this + 117) & 8 )
    return 1i64;
  v12 = 1;
  v3 = *((_DWORD *)v1 + 11);
  if ( v3 & 2 )
    v4 = (signed __int64)&v1->flags;
  else
    v4 = 0i64;
  v5 = (unsigned int)v1->eOpenMode;
  v6 = AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver->vfptr;
  v11 = this->m_pFileDesc;
  if ( v3 & 1 )
    v7 = (unsigned int)v6->Open(
                         AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver,
                         v1->pszFileName,
                         (AkOpenMode)v5,
                         (AkFileSystemFlags *)v4,
                         (bool *)&v12,
                         v11);
  else
    v7 = (unsigned int)v6->Open(
                         AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver,
                         v1->fileID,
                         (AkOpenMode)v5,
                         (AkFileSystemFlags *)v4,
                         (bool *)&v12,
                         v11);
  v8 = v7;
  if ( v7 == 1 )
    ((void (__fastcall *)(AK::StreamMgr::CAkStmTask *))v2->vfptr[3].__vecDelDtor)(v2);
  v9 = v2->m_pDeferredOpenData;
  if ( v9 )
  {
    AK::StreamMgr::AkDeferredOpenData::Destroy(v9);
    v2->m_pDeferredOpenData = 0i64;
  }
  return (unsigned int)v8;
}

// File Line: 861
// RVA: 0xAA2830
void __fastcall AK::StreamMgr::CAkStdStmBase::CAkStdStmBase(AK::StreamMgr::CAkStdStmBase *this)
{
  AK::StreamMgr::CAkStdStmBase *v1; // rbx

  v1 = this;
  AK::StreamMgr::CAkClientThreadAware::CAkClientThreadAware((AK::StreamMgr::CAkClientThreadAware *)&this->vfptr);
  v1->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkStmTask::`vftable';
  v1->m_pDeferredOpenData = 0i64;
  v1->m_pFileDesc = 0i64;
  InitializeCriticalSection(&v1->m_lockStatus.m_csLock);
  *((_BYTE *)&v1->0 + 117) &= 0x83u;
  v1->m_pszStreamName = 0i64;
  v1->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkStdStmBase::`vftable'{for `AK::StreamMgr::CAkStmTask'};
  v1->vfptr = (AK::IAkStdStreamVtbl *)&AK::StreamMgr::CAkStdStmBase::`vftable'{for `AK::IAkStdStream'};
  v1->m_memBlock.uPosition = 0i64;
  v1->m_memBlock.pData = 0i64;
  v1->m_memBlock.pNextBlock = 0i64;
  v1->m_memBlock.uAvailableSize = 0;
  v1->m_memBlock.fileID = -1;
  v1->m_memBlock.uRefCount = 0;
  *((_DWORD *)v1 + 44) &= 0xFFFFFFF0;
  *((_DWORD *)v1 + 44) |= 0x10u;
  *((_BYTE *)&v1->0 + 117) &= 0xFCu;
  v1->m_uTotalScheduledSize = 0;
}

// File Line: 867
// RVA: 0xAA2960
void __fastcall AK::StreamMgr::CAkStdStmBase::~CAkStdStmBase(AK::StreamMgr::CAkStdStmBase *this)
{
  bool v1; // zf
  AK::StreamMgr::CAkStdStmBase *v2; // rbx

  v1 = (*((_BYTE *)&this->0 + 117) & 0x20) == 0;
  v2 = this;
  this->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkStdStmBase::`vftable'{for `AK::StreamMgr::CAkStmTask'};
  this->vfptr = (AK::IAkStdStreamVtbl *)&AK::StreamMgr::CAkStdStmBase::`vftable'{for `AK::IAkStdStream'};
  if ( !v1 )
    AK::StreamMgr::CAkIOThread::StdSemDecr((AK::StreamMgr::CAkIOThread *)&this->m_pDevice->vfptr);
  v2->vfptr = (AK::IAkStdStreamVtbl *)&AK::IAkStdStream::`vftable';
  AK::StreamMgr::CAkStmTask::~CAkStmTask((AK::StreamMgr::CAkStmTask *)&v2->vfptr);
}

// File Line: 880
// RVA: 0xAA3EA0
signed __int64 __fastcall AK::StreamMgr::CAkStdStmBase::Init(AK::StreamMgr::CAkStdStmBase *this, AK::StreamMgr::CAkDeviceBase *in_pDevice, AkFileDesc *in_pFileDesc, __int64 __formal)
{
  AK::StreamMgr::CAkDeviceBase *v4; // rdi
  AK::StreamMgr::CAkStdStmBase *v5; // rbx
  signed __int64 result; // rax
  unsigned int v7; // ecx
  unsigned int v8; // eax

  this->m_pDevice = in_pDevice;
  v4 = in_pDevice;
  v5 = this;
  if ( in_pFileDesc->iFileSize >= 0 )
  {
    v7 = ((__int64 (__fastcall *)(AK::StreamMgr::IAkLowLevelIOHook *, AkFileDesc *, AkFileDesc *, __int64))in_pDevice->m_pLowLevelHook->vfptr->GetBlockSize)(
           in_pDevice->m_pLowLevelHook,
           in_pFileDesc,
           in_pFileDesc,
           __formal);
    if ( !v7 || (v8 = v4->m_uGranularity, v7 > v8) || v8 % v7 )
    {
      *((_BYTE *)&v5->0 + 117) = *((_BYTE *)&v5->0 + 117) & 0xBF | 8;
      result = 2i64;
    }
    else
    {
      v5->m_uLLBlockSize = v7;
      result = 1i64;
    }
  }
  else
  {
    *((_BYTE *)&this->0 + 117) = *((_BYTE *)&this->0 + 117) & 0xBF | 8;
    result = 31i64;
  }
  return result;
}

// File Line: 966
// RVA: 0xAA3B60
void *__fastcall AK::StreamMgr::CAkStdStmBase::GetPosition(AK::StreamMgr::CAkStdStmBase *this, bool *out_pbEndOfStream)
{
  if ( out_pbEndOfStream )
    *out_pbEndOfStream = (*((_BYTE *)&this[-1] + 181) >> 2) & 1;
  return this->m_hBlockEvent;
}

// File Line: 988
// RVA: 0xAA4DA0
signed __int64 __fastcall AK::StreamMgr::CAkStdStmBase::SetPosition(AK::StreamMgr::CAkStdStmBase *this, __int64 in_iMoveOffset, AkMoveMethod in_eMoveMethod, __int64 *out_piRealOffset)
{
  __int64 v4; // r10
  signed __int64 result; // rax
  signed __int64 v6; // rdx
  __int32 v7; // er8

  v4 = in_iMoveOffset;
  if ( out_piRealOffset )
    *out_piRealOffset = 0i64;
  if ( (this->m_lockStatus.m_csLock.LockCount & 0xF) == 2 )
    return 2i64;
  if ( in_eMoveMethod )
  {
    if ( in_eMoveMethod == 1 )
    {
      v4 = (__int64)this->m_hBlockEvent + in_iMoveOffset;
    }
    else
    {
      if ( in_eMoveMethod != 2 )
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
    result = 1i64;
  }
  return result;
}

// File Line: 1071
// RVA: 0xAA4180
signed __int64 __fastcall AK::StreamMgr::CAkStdStmBase::Read(AK::StreamMgr::CAkStdStmBase *this, void *in_pBuffer, unsigned int in_uReqSize, bool in_bWait, char in_priority, float in_fDeadline, unsigned int *out_uSize)
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
signed __int64 __fastcall AK::StreamMgr::CAkStdStmBase::Write(AK::StreamMgr::CAkStdStmBase *this, void *in_pBuffer, unsigned int in_uReqSize, bool in_bWait, char in_priority, float in_fDeadline, unsigned int *out_uSize)
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
signed __int64 __fastcall AK::StreamMgr::CAkStdStmBase::ExecuteOp(AK::StreamMgr::CAkStdStmBase *this, bool in_bWrite, void *in_pBuffer, unsigned int in_uReqSize, bool in_bWait, char in_priority, float in_fDeadline, unsigned int *out_uSize)
{
  AK::StreamMgr::CAkStdStmBase *v8; // rdi
  int v9; // ebp
  unsigned int v10; // esi
  int v11; // ecx
  signed __int64 result; // rax
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // rdx
  int v15; // eax

  v8 = this;
  v9 = 0;
  v10 = in_uReqSize;
  *out_uSize = 0;
  *((_BYTE *)&v8->0 + 117) &= 0xFDu;
  *((_DWORD *)this + 44) &= 0xFFFFFFEF;
  this->m_fDeadline = in_fDeadline;
  this->m_uTotalScheduledSize = 0;
  v11 = *((_DWORD *)this + 44);
  v8->m_memBlock.pData = in_pBuffer;
  v8->m_memBlock.uAvailableSize = in_uReqSize;
  *((_BYTE *)&v8->0 + 117) |= 2 * in_bWrite;
  v8->m_priority = in_priority;
  if ( !in_pBuffer || (unsigned __int8)in_priority > 0x64u || in_fDeadline < 0.0 )
    return 31i64;
  if ( !(((v11 << 28 >> 28) - 2) & 0xFFFFFFFD) )
    return 2i64;
  if ( !in_bWrite )
  {
    if ( in_uReqSize % v8->m_uLLBlockSize )
      return 2i64;
    if ( *((_BYTE *)&v8->0 + 117) & 0x10 )
    {
      v13 = v8->m_memBlock.uPosition;
      v14 = v8->m_pFileDesc->iFileSize;
      if ( v13 + in_uReqSize > v14 )
      {
        if ( v13 >= v14 )
        {
LABEL_15:
          EnterCriticalSection(&v8->m_lockStatus.m_csLock);
          AK::StreamMgr::CAkStdStmBase::SetStatus(v8, AK_StmStatusCompleted);
          *out_uSize = 0;
          LeaveCriticalSection(&v8->m_lockStatus.m_csLock);
          return 1i64;
        }
        v10 = v14 - v13;
      }
    }
  }
  if ( !v10 )
    goto LABEL_15;
  QueryPerformanceCounter((LARGE_INTEGER *)&v8->m_iIOStartTime);
  EnterCriticalSection(&v8->m_lockStatus.m_csLock);
  if ( in_bWait )
  {
    AK::StreamMgr::CAkClientThreadAware::SetBlockedStatus((AK::StreamMgr::CAkClientThreadAware *)&v8->vfptr);
    AK::StreamMgr::CAkStdStmBase::SetStatus(v8, AK_StmStatusPending);
    LeaveCriticalSection(&v8->m_lockStatus.m_csLock);
    AK::StreamMgr::CAkIOThread::WaitForIOCompletion(
      (AK::StreamMgr::CAkIOThread *)&v8->m_pDevice->vfptr,
      (AK::StreamMgr::CAkClientThreadAware *)&v8->vfptr);
    v15 = *((_DWORD *)v8 + 44);
    *out_uSize = v10;
    LOBYTE(v9) = (v15 & 0xF) != 1;
    result = (unsigned int)(v9 + 1);
  }
  else
  {
    AK::StreamMgr::CAkStdStmBase::SetStatus(v8, AK_StmStatusPending);
    LeaveCriticalSection(&v8->m_lockStatus.m_csLock);
    *out_uSize = v10;
    result = 1i64;
  }
  return result;
}

// File Line: 1211
// RVA: 0xAA3A50
void *__fastcall AK::StreamMgr::CAkStdStmBase::GetData(AK::StreamMgr::CAkStdStmBase *this, unsigned int *out_uActualSize)
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
                     / (float)(signed int)((this->m_pDevice->m_uGranularity
                                          + this->m_memBlock.uAvailableSize
                                          - this->m_uTotalScheduledSize
                                          - 1)
                                         / this->m_pDevice->m_uGranularity))
             - (float)((float)(LODWORD(this->m_pDevice->m_time) - LODWORD(this->m_iIOStartTime)) / AK::g_fFreqRatio)) > 0.0 )
    result = (float)(this->m_fDeadline
                   / (float)(signed int)((this->m_pDevice->m_uGranularity
                                        + this->m_memBlock.uAvailableSize
                                        - this->m_uTotalScheduledSize
                                        - 1)
                                       / this->m_pDevice->m_uGranularity))
           - (float)((float)(LODWORD(this->m_pDevice->m_time) - LODWORD(this->m_iIOStartTime)) / AK::g_fFreqRatio);
  return result;
}

// File Line: 1247
// RVA: 0xAA2CE0
void __fastcall AK::StreamMgr::CAkStdStmBase::AddMemView(AK::StreamMgr::CAkStdStmBase *this, AK::StreamMgr::CAkStmMemView *in_pMemView, bool in_bStoreData)
{
  AK::StreamMgr::CAkStmMemView *v3; // rdi
  AK::StreamMgr::CAkStdStmBase *v4; // rbx
  char v5; // dl
  int v6; // ecx
  char v7; // dl
  int v8; // ecx
  unsigned int v9; // er8
  AkFileDesc *v10; // r9
  AK::StreamMgr::CAkDeviceBase *v11; // rbp
  AK::StreamMgr::AkMemBlock *v12; // r8
  AK::StreamMgr::CAkDeviceBase *v13; // rsi
  AK::StreamMgr::CAkStmMemView *v14; // rax

  v3 = in_pMemView;
  v4 = this;
  if ( in_bStoreData )
  {
    v5 = *((_BYTE *)&this->0 + 117);
    if ( !(v5 & 8) )
    {
      v6 = *((_DWORD *)this + 44);
      if ( (v6 & 0xF) != 4 )
      {
        v7 = v5 & 0xFB;
        v8 = v6 | 0x10;
        *((_BYTE *)&v4->0 + 117) = v7;
        *((_DWORD *)v4 + 44) = v8;
        v9 = v3->m_pBlock->uAvailableSize - v3->m_uOffsetInBlock;
        if ( v9 > v4->m_pDevice->m_uGranularity )
        {
          v9 = v4->m_pDevice->m_uGranularity;
          *((_DWORD *)v4 + 44) = v8 & 0xFFFFFFEF;
        }
        if ( !(v7 & 2) )
        {
          v10 = v4->m_pFileDesc;
          if ( v9 >= v10->iFileSize - v3->m_uOffsetInBlock - v3->m_pBlock->uPosition )
          {
            *((_DWORD *)v4 + 44) |= 0x10u;
            *((_BYTE *)&v4->0 + 117) = v7 | 4;
            v4->m_memBlock.uAvailableSize += LODWORD(v10->iFileSize)
                                           - v3->m_pBlock->uAvailableSize
                                           - v3->m_pBlock->uPosition;
          }
        }
      }
    }
  }
  v11 = v4->m_pDevice;
  EnterCriticalSection(&v11->m_lockSems.m_csLock);
  v12 = v3->m_pBlock;
  v13 = v4->m_pDevice;
  v3->m_pBlock = 0i64;
  if ( v12 )
    AK::StreamMgr::CAkIOMemMgr::DestroyTempBlock(&v13->m_mgrMemIO, &v4->m_memBlock, v12);
  v14 = v13->m_poolStmMemView.m_pFirst;
  if ( v14 )
  {
    v3->pNextView = v14;
    v13->m_poolStmMemView.m_pFirst = v3;
  }
  else
  {
    v13->m_poolStmMemView.m_pFirst = v3;
    v3->pNextView = 0i64;
  }
  LeaveCriticalSection(&v11->m_lockSems.m_csLock);
}

// File Line: 1312
// RVA: 0xAA5180
void __fastcall AK::StreamMgr::CAkStdStmBase::UpdateTaskStatus(AK::StreamMgr::CAkStdStmBase *this, AKRESULT in_eIOResult)
{
  AK::StreamMgr::CAkStdStmBase *v2; // rbx
  AK::StreamMgr::CAkClientThreadAwareVtbl *v3; // rax
  int v4; // ecx
  bool v5; // zf
  char v6; // al
  AK::StreamMgr::CAkIOThread *v7; // rcx
  char v8; // al
  AK::StreamMgr::CAkIOThread *v9; // rcx

  v2 = this;
  if ( in_eIOResult == 2 )
  {
    *((_DWORD *)this + 44) &= 0xFFFFFFF4;
    *((_DWORD *)this + 44) |= 4u;
    if ( !(*((_BYTE *)&this->0 + 117) & 8) )
      goto LABEL_10;
    v3 = this->vfptr;
  }
  else
  {
    v4 = *((_DWORD *)this + 44);
    if ( !(v4 & 0x10) )
      goto LABEL_12;
    v2->m_memBlock.uPosition += v2->m_memBlock.uAvailableSize;
    v5 = (*((_BYTE *)&v2->0 + 117) & 8) == 0;
    *((_DWORD *)v2 + 44) = v4 & 0xFFFFFFF1 | 1;
    if ( v5 )
      goto LABEL_10;
    v3 = v2->vfptr;
    this = v2;
  }
  if ( ((unsigned __int8 (__fastcall *)(AK::StreamMgr::CAkStdStmBase *))v3[1].__vecDelDtor)(this) )
  {
    v6 = *((_BYTE *)&v2->0 + 117);
    if ( !(v6 & 0x20) )
    {
      v7 = (AK::StreamMgr::CAkIOThread *)&v2->m_pDevice->vfptr;
      *((_BYTE *)&v2->0 + 117) = v6 | 0x20;
      AK::StreamMgr::CAkIOThread::StdSemIncr(v7);
    }
    goto LABEL_12;
  }
LABEL_10:
  *((_BYTE *)&v2->0 + 117) &= 0xBFu;
  v8 = *((_BYTE *)&v2->0 + 117);
  if ( v8 & 0x20 )
  {
    v9 = (AK::StreamMgr::CAkIOThread *)&v2->m_pDevice->vfptr;
    *((_BYTE *)&v2->0 + 117) = v8 & 0xDF;
    AK::StreamMgr::CAkIOThread::StdSemDecr(v9);
  }
LABEL_12:
  if ( v2->m_bIsBlocked )
  {
    if ( (*((_DWORD *)v2 + 44) << 28 >> 28) & 0xFFFFFFFD )
      AK::StreamMgr::CAkIOThread::SignalIOCompleted(
        (AK::StreamMgr::CAkIOThread *)&v2->m_pDevice->vfptr,
        (AK::StreamMgr::CAkClientThreadAware *)&v2->vfptr);
  }
}

// File Line: 1344
// RVA: 0xAA3F90
void __fastcall AK::StreamMgr::CAkStdStmBase::Kill(AK::StreamMgr::CAkStdStmBase *this)
{
  AK::StreamMgr::CAkStdStmBase *v1; // rdi
  char v2; // al
  AK::StreamMgr::CAkIOThread *v3; // rcx
  char v4; // al
  AK::StreamMgr::CAkIOThread *v5; // rcx

  v1 = this;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  *((_DWORD *)v1 + 44) &= 0xFFFFFFF4;
  *((_DWORD *)v1 + 44) |= 4u;
  if ( *((_BYTE *)&v1->0 + 117) & 8
    && ((unsigned __int8 (__fastcall *)(AK::StreamMgr::CAkStdStmBase *))v1->vfptr[1].__vecDelDtor)(v1) )
  {
    v2 = *((_BYTE *)&v1->0 + 117);
    if ( !(v2 & 0x20) )
    {
      v3 = (AK::StreamMgr::CAkIOThread *)&v1->m_pDevice->vfptr;
      *((_BYTE *)&v1->0 + 117) = v2 | 0x20;
      AK::StreamMgr::CAkIOThread::StdSemIncr(v3);
    }
  }
  else
  {
    *((_BYTE *)&v1->0 + 117) &= 0xBFu;
    v4 = *((_BYTE *)&v1->0 + 117);
    if ( v4 & 0x20 )
    {
      v5 = (AK::StreamMgr::CAkIOThread *)&v1->m_pDevice->vfptr;
      *((_BYTE *)&v1->0 + 117) = v4 & 0xDF;
      AK::StreamMgr::CAkIOThread::StdSemDecr(v5);
    }
  }
  if ( v1->m_bIsBlocked && (*((_DWORD *)v1 + 44) << 28 >> 28) & 0xFFFFFFFD )
    AK::StreamMgr::CAkIOThread::SignalIOCompleted(
      (AK::StreamMgr::CAkIOThread *)&v1->m_pDevice->vfptr,
      (AK::StreamMgr::CAkClientThreadAware *)&v1->vfptr);
  LeaveCriticalSection(&v1->m_lockStatus.m_csLock);
}

// File Line: 1395
// RVA: 0xAA4E50
void __fastcall AK::StreamMgr::CAkStdStmBase::SetStatus(AK::StreamMgr::CAkStdStmBase *this, AkStmStatus in_eStatus)
{
  AkStmStatus v2; // edi
  AK::StreamMgr::CAkStdStmBase *v3; // rbx
  char v4; // al
  AK::StreamMgr::CAkIOThread *v5; // rcx
  char v6; // al
  AK::StreamMgr::CAkIOThread *v7; // rcx

  *((_DWORD *)this + 44) &= 0xFFFFFFF0;
  v2 = in_eStatus;
  v3 = this;
  *((_DWORD *)this + 44) |= in_eStatus & 0xF;
  if ( *((_BYTE *)&this->0 + 117) & 8 && ((unsigned __int8 (*)(void))this->vfptr[1].__vecDelDtor)() )
    goto LABEL_5;
  if ( v2 == 2 )
  {
    *((_BYTE *)&v3->0 + 117) |= 0x40u;
LABEL_5:
    v4 = *((_BYTE *)&v3->0 + 117);
    if ( !(v4 & 0x20) )
    {
      v5 = (AK::StreamMgr::CAkIOThread *)&v3->m_pDevice->vfptr;
      *((_BYTE *)&v3->0 + 117) = v4 | 0x20;
      AK::StreamMgr::CAkIOThread::StdSemIncr(v5);
    }
    return;
  }
  *((_BYTE *)&v3->0 + 117) &= 0xBFu;
  v6 = *((_BYTE *)&v3->0 + 117);
  if ( v6 & 0x20 )
  {
    v7 = (AK::StreamMgr::CAkIOThread *)&v3->m_pDevice->vfptr;
    *((_BYTE *)&v3->0 + 117) = v6 & 0xDF;
    AK::StreamMgr::CAkIOThread::StdSemDecr(v7);
  }
}

// File Line: 1458
// RVA: 0xAA2720
void __fastcall AK::StreamMgr::CAkAutoStmBase::CAkAutoStmBase(AK::StreamMgr::CAkAutoStmBase *this)
{
  AK::StreamMgr::CAkAutoStmBase *v1; // rbx
  char v2; // al

  v1 = this;
  AK::StreamMgr::CAkClientThreadAware::CAkClientThreadAware((AK::StreamMgr::CAkClientThreadAware *)&this->vfptr);
  v1->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkStmTask::`vftable';
  v1->m_pDeferredOpenData = 0i64;
  v1->m_pFileDesc = 0i64;
  InitializeCriticalSection(&v1->m_lockStatus.m_csLock);
  *((_BYTE *)&v1->0 + 117) &= 0x83u;
  v1->m_pszStreamName = 0i64;
  v1->m_fileID = -1;
  v1->m_uVirtualBufferingSize = 0;
  v1->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkAutoStmBase::`vftable'{for `AK::StreamMgr::CAkStmTask'};
  v1->vfptr = (AK::IAkAutoStreamVtbl *)&AK::StreamMgr::CAkAutoStmBase::`vftable'{for `AK::IAkAutoStream'};
  v1->m_listBuffers.m_ulNumListItems = 0;
  v1->m_listBuffers.m_pFirst = 0i64;
  v1->m_listBuffers.m_pLast = 0i64;
  v2 = *((_BYTE *)&v1->0 + 117);
  *((_BYTE *)v1 + 194) &= 0xFCu;
  v1->m_uNextToGrant = 0;
  *((_BYTE *)&v1->0 + 117) = v2 & 0xFD | 1;
}

// File Line: 1464
// RVA: 0xAA28D0
void __fastcall AK::StreamMgr::CAkAutoStmBase::~CAkAutoStmBase(AK::StreamMgr::CAkAutoStmBase *this)
{
  bool v1; // zf
  AK::StreamMgr::CAkAutoStmBase *v2; // rbx

  v1 = (*((_BYTE *)&this->0 + 117) & 0x20) == 0;
  v2 = this;
  this->vfptr = (AK::StreamMgr::CAkClientThreadAwareVtbl *)&AK::StreamMgr::CAkAutoStmBase::`vftable'{for `AK::StreamMgr::CAkStmTask'};
  this->vfptr = (AK::IAkAutoStreamVtbl *)&AK::StreamMgr::CAkAutoStmBase::`vftable'{for `AK::IAkAutoStream'};
  if ( !v1 )
    AK::StreamMgr::CAkIOThread::AutoSemDecr((AK::StreamMgr::CAkIOThread *)&this->m_pDevice->vfptr);
  v2->vfptr = (AK::IAkAutoStreamVtbl *)&AK::IAkAutoStream::`vftable';
  AK::StreamMgr::CAkStmTask::~CAkStmTask((AK::StreamMgr::CAkStmTask *)&v2->vfptr);
}

// File Line: 1479
// RVA: 0xAA3CB0
AKRESULT __fastcall AK::StreamMgr::CAkAutoStmBase::Init(AK::StreamMgr::CAkAutoStmBase *this, AK::StreamMgr::CAkDeviceBase *in_pDevice, AkFileDesc *in_pFileDesc, unsigned int in_fileID, AkAutoStmHeuristics *in_heuristics, AkAutoStmBufSettings *in_pBufferSettings, unsigned int in_uGranularity)
{
  AkFileDesc *v7; // rdi
  AK::StreamMgr::CAkAutoStmBase *v8; // rbx
  AKRESULT result; // eax
  unsigned int v10; // eax
  float v11; // xmm0_4
  __int64 v12; // rax
  char v13; // cl
  char v14; // al

  this->m_pDevice = in_pDevice;
  v7 = in_pFileDesc;
  v8 = this;
  if ( in_pFileDesc->iFileSize >= 0 )
  {
    this->m_fileID = in_fileID;
    v10 = in_pDevice->m_pLowLevelHook->vfptr->GetBlockSize(in_pDevice->m_pLowLevelHook, in_pFileDesc);
    if ( !v10 || v10 > in_uGranularity || in_uGranularity % v10 )
    {
      *((_BYTE *)&v8->0 + 117) = *((_BYTE *)&v8->0 + 117) & 0xBF | 8;
      result = 2;
    }
    else
    {
      v8->m_uLLBlockSize = v10;
      v8->m_uBufferAlignment = v10;
      v11 = in_heuristics->fThroughput;
      if ( in_heuristics->fThroughput <= 1.0 )
        v11 = *(float *)&FLOAT_1_0;
      v8->m_fThroughput = v11;
      v8->m_uLoopStart = in_heuristics->uLoopStart - in_heuristics->uLoopStart % v10;
      v12 = in_heuristics->uLoopEnd;
      if ( v12 > v7->iFileSize )
        LODWORD(v12) = v7->iFileSize;
      v8->m_uLoopEnd = v12;
      v13 = in_heuristics->uMinNumBuffers;
      if ( !v13 )
        v13 = 1;
      v8->m_uMinNumBuffers = v13;
      v14 = in_heuristics->priority;
      v8->m_uNextExpectedUserPosition = 0i64;
      v8->m_priority = v14;
      if ( !v7->iFileSize )
        *((_BYTE *)&v8->0 + 117) = *((_BYTE *)&v8->0 + 117) & 0xBF | 4;
      result = AK::StreamMgr::CAkAutoStmBase::SetBufferingSettings(v8, in_pBufferSettings, in_uGranularity);
      if ( result != 1 )
        *((_BYTE *)&v8->0 + 117) = *((_BYTE *)&v8->0 + 117) & 0xBF | 8;
    }
  }
  else
  {
    *((_BYTE *)&this->0 + 117) = *((_BYTE *)&this->0 + 117) & 0xBF | 8;
    result = 31;
  }
  return result;
}

// File Line: 1539
// RVA: 0xAA37E0
__int64 __fastcall Gcd(unsigned int a, unsigned int b)
{
  unsigned int k; // er8
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
    for ( i = 0; !(((unsigned __int8)v3 | (unsigned __int8)k) & 1); ++i )
    {
      k >>= 1;
      v3 >>= 1;
    }
    for ( ; !(k & 1); k >>= 1 )
      ;
    for ( ; !(v3 & 1); v3 >>= 1 )
      ;
    for ( j = k < v3; k != v3; j = k < v3 )
    {
      if ( j )
      {
        v6 = k;
        k = v3;
        v3 = v6;
      }
      for ( k = (k - v3) >> 1; !(k & 1); k >>= 1 )
        ;
    }
    k <<= i;
  }
  return k;
}

// File Line: 1584
// RVA: 0xAA47A0
signed __int64 __fastcall AK::StreamMgr::CAkAutoStmBase::SetBufferingSettings(AK::StreamMgr::CAkAutoStmBase *this, AkAutoStmBufSettings *in_pBufferSettings, unsigned int in_uGranularity)
{
  unsigned int v3; // ebx
  AkAutoStmBufSettings *v4; // rdi
  AK::StreamMgr::CAkAutoStmBase *v5; // r11
  unsigned int v6; // eax
  unsigned int v7; // ecx
  unsigned int v8; // er9
  unsigned int v9; // er8
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // ecx

  v3 = in_uGranularity;
  v4 = in_pBufferSettings;
  v5 = this;
  if ( in_pBufferSettings )
  {
    if ( in_pBufferSettings->uBlockSize )
    {
      v6 = Gcd(this->m_uLLBlockSize, in_pBufferSettings->uBlockSize);
      v5->m_uBufferAlignment = v5->m_uLLBlockSize * (v4->uBlockSize / v6);
    }
    v7 = v5->m_uBufferAlignment;
    v5->m_uMinBufferSize = v7;
    v8 = v3 - v3 % v7;
    v5->m_uBufferSize = v8;
    v9 = v4->uBufferSize;
    if ( v4->uBufferSize )
    {
      if ( v9 <= v3 && !(v9 % v7) )
      {
        v5->m_uBufferSize = v9;
        v5->m_uMinBufferSize = v4->uBufferSize;
        return 1i64;
      }
      return 2i64;
    }
    v11 = v4->uMinBufferSize;
    if ( v11 )
    {
      if ( v7 < v11 )
      {
        v12 = v7 * ((v7 + v11 - 1) / v7);
        v5->m_uMinBufferSize = v12;
        if ( v12 > v8 )
          return 2i64;
      }
    }
  }
  else
  {
    v13 = this->m_uLLBlockSize;
    v5->m_uMinBufferSize = v13;
    v5->m_uBufferSize = in_uGranularity - in_uGranularity % v13;
  }
  return 1i64;
}

// File Line: 1655
// RVA: 0xAA2F40
void __fastcall AK::StreamMgr::CAkAutoStmBase::Destroy(AK::StreamMgr::CAkAutoStmBase *this)
{
  AK::StreamMgr::CAkAutoStmBase *v1; // rdi
  char v2; // r8
  __int64 **v3; // rax
  int v4; // er10
  __int64 *v5; // r9
  __int64 v6; // r11
  unsigned __int64 v7; // rcx
  __int64 v8; // rsi
  int v9; // ecx
  bool v10; // zf

  v1 = this;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  *((_BYTE *)&v1[-1] + 197) = *((_BYTE *)&v1[-1] + 197) & 0xBF | 8;
  v2 = (char)v1->m_lockStatus.m_csLock.LockSemaphore;
  v3 = *(__int64 ***)&v1->m_lockStatus.m_csLock.LockCount;
  if ( v2 )
  {
    v4 = HIDWORD(v1->m_pDeferredOpenData);
    do
    {
      v5 = v3[1];
      v6 = *((unsigned int *)v3 + 4);
      v7 = HIDWORD(v1->pNextLightItem);
      v8 = *v5;
      if ( *v5 + v6 >= v7 || v8 + (unsigned __int64)*((unsigned int *)v5 + 6) <= v7 )
        v9 = *((_DWORD *)v5 + 6);
      else
        v9 = v7 - v8;
      v4 += v9 - v6;
      v10 = v2-- == 1;
      LOBYTE(v1->m_lockStatus.m_csLock.LockSemaphore) = v2;
      HIDWORD(v1->m_pDeferredOpenData) = v4;
      v3 = (__int64 **)*v3;
    }
    while ( !v10 );
  }
  AK::StreamMgr::CAkAutoStmBase::Flush((AK::StreamMgr::CAkAutoStmBase *)((char *)v1 - 120));
  *(_QWORD *)&v1->m_lockStatus.m_csLock.LockCount = 0i64;
  v1->m_lockStatus.m_csLock.OwningThread = 0i64;
  LODWORD(v1->m_lockStatus.m_csLock.DebugInfo) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&v1[-1].m_uNextExpectedUserPosition);
}

// File Line: 1683
// RVA: 0xAA3A90
void __fastcall AK::StreamMgr::CAkStdStmBase::GetInfo(AK::StreamMgr::CAkStdStmBase *this, AkStreamInfo *out_info)
{
  out_info->deviceID = *(_DWORD *)(*(_QWORD *)&this[-1].m_memBlock.uRefCount + 264i64);
  out_info->pszName = *(const wchar_t **)&this[-1].m_uTotalScheduledSize;
  out_info->uSize = *(_QWORD *)this[-1].m_pszStreamName;
  out_info->bIsOpen = (*((_BYTE *)&this[-1] + 181) >> 4) & 1;
}

// File Line: 1696
// RVA: 0xAA3A70
void __fastcall AK::StreamMgr::CAkAutoStmBase::GetHeuristics(AK::StreamMgr::CAkAutoStmBase *this, AkAutoStmHeuristics *out_heuristics)
{
  out_heuristics->fThroughput = *((float *)&this->m_bIsBlocked + 1);
  out_heuristics->uLoopStart = (unsigned int)this->pNextLightItem;
  out_heuristics->uLoopEnd = HIDWORD(this->pNextLightItem);
  out_heuristics->uMinNumBuffers = BYTE1(this->m_lockStatus.m_csLock.LockSemaphore);
  out_heuristics->priority = *((_BYTE *)&this[-1] + 196);
}

// File Line: 1709
// RVA: 0xAA4920
signed __int64 __fastcall AK::StreamMgr::CAkAutoStmBase::SetHeuristics(AK::StreamMgr::CAkAutoStmBase *this, AkAutoStmHeuristics *in_heuristics)
{
  char v2; // al
  AkAutoStmHeuristics *v3; // rbx
  AK::StreamMgr::CAkAutoStmBase *v4; // rsi
  float v5; // xmm6_4
  AK::IAkAutoStreamVtbl *v6; // rax
  __int64 v7; // r14
  char v8; // di
  char v9; // cl
  unsigned __int64 v10; // rax
  unsigned int v11; // er12
  unsigned __int64 v12; // rbp
  unsigned int *v13; // rcx
  AK::StreamMgr::CAkStmMemView **v14; // r15
  __int128 v15; // ax
  __int64 v16; // r8
  AK::StreamMgr::CAkStmMemView *v17; // rbx
  __int64 v18; // r8
  __m128i v19; // xmm0
  AK::StreamMgr::CAkStmMemView *v20; // r12
  AK::StreamMgr::CAkStmMemView *i; // rdx
  AK::StreamMgr::CAkStmMemView *v22; // r14
  __int128 v24; // [rsp+20h] [rbp-58h]
  __m128i v25; // [rsp+30h] [rbp-48h]

  v2 = in_heuristics->priority;
  v3 = in_heuristics;
  v4 = this;
  if ( (unsigned __int8)v2 > 0x64u )
    return 31i64;
  *((_BYTE *)&this[-1] + 196) = v2;
  v5 = in_heuristics->fThroughput;
  if ( in_heuristics->fThroughput <= 1.0 )
    v5 = *(float *)&FLOAT_1_0;
  v6 = this[-1].vfptr;
  v7 = in_heuristics->uLoopEnd;
  if ( v7 > (_QWORD)v6->__vecDelDtor && *((_BYTE *)&this[-1] + 197) & 0x10 )
    LODWORD(v7) = v6->__vecDelDtor;
  if ( this->pNextLightItem == (AK::StreamMgr::CAkStmTask *)__PAIR__(v7, in_heuristics->uLoopStart) )
  {
    v8 = 1;
    if ( in_heuristics->uMinNumBuffers )
      v8 = in_heuristics->uMinNumBuffers;
    if ( v5 != *((float *)&this->m_bIsBlocked + 1) || BYTE1(this->m_lockStatus.m_csLock.LockSemaphore) != v8 )
    {
      EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
      BYTE1(v4->m_lockStatus.m_csLock.LockSemaphore) = v8;
      *((float *)&v4->m_bIsBlocked + 1) = v5;
      AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus((AK::StreamMgr::CAkAutoStmBase *)((char *)v4 - 120));
      LeaveCriticalSection((LPCRITICAL_SECTION)&v4[-1].m_uNextExpectedUserPosition);
    }
  }
  else
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
    *((float *)&v4->m_bIsBlocked + 1) = v5;
    v9 = v3->uMinNumBuffers;
    if ( !v9 )
      v9 = 1;
    BYTE1(v4->m_lockStatus.m_csLock.LockSemaphore) = v9;
    v10 = v4[-1].m_lockStatus.m_csLock.SpinCount;
    v11 = v3->uLoopStart - v3->uLoopStart % *(_DWORD *)&v4[-1].m_uNextToGrant;
    LODWORD(v4->pNextLightItem) = v11;
    (*(void (__fastcall **)(unsigned __int64 *, _QWORD))(v10 + 88))(
      &v4[-1].m_lockStatus.m_csLock.SpinCount,
      (unsigned int)v7);
    v12 = (unsigned __int64)v4->m_hBlockEvent;
    v13 = *(unsigned int **)&v4->m_lockStatus.m_csLock.LockCount;
    v14 = 0i64;
    *((_QWORD *)&v15 + 1) = 0i64;
    if ( LOBYTE(v4->m_lockStatus.m_csLock.LockSemaphore) )
    {
      v16 = LOBYTE(v4->m_lockStatus.m_csLock.LockSemaphore);
      do
      {
        *(_QWORD *)&v15 = *((_QWORD *)v13 + 1);
        *((_QWORD *)&v15 + 1) = v13;
        v13 = *(unsigned int **)v13;
        v12 = *(_QWORD *)v15 + *(unsigned int *)(v15 + 24);
        --v16;
      }
      while ( v16 );
    }
    if ( (_DWORD)v7 && v12 >= (unsigned int)v7 )
      v12 = v11;
    v17 = 0i64;
    if ( v13 )
    {
      do
      {
        v18 = *((_QWORD *)v13 + 1);
        if ( *(_QWORD *)v18 + v13[4] == v12 )
        {
          v12 = *(_QWORD *)v18 + *(unsigned int *)(v18 + 24);
          if ( (_DWORD)v7 && v12 >= (unsigned int)v7 )
            v12 = v11;
          *((_QWORD *)&v15 + 1) = v13;
          v13 = *(unsigned int **)v13;
        }
        else
        {
          *(_QWORD *)&v15 = *(_QWORD *)v13;
          v25 = (__m128i)v15;
          if ( v13 == *(unsigned int **)&v4->m_lockStatus.m_csLock.LockCount )
            *(_QWORD *)&v4->m_lockStatus.m_csLock.LockCount = v15;
          else
            **((_QWORD **)&v15 + 1) = v15;
          if ( v13 == v4->m_lockStatus.m_csLock.OwningThread )
            v4->m_lockStatus.m_csLock.OwningThread = (void *)*((_QWORD *)&v15 + 1);
          v19 = v25;
          --LODWORD(v4->m_lockStatus.m_csLock.DebugInfo);
          _mm_store_si128((__m128i *)&v24, v19);
          *((_QWORD *)&v15 + 1) = *((_QWORD *)&v24 + 1);
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
          v13 = (unsigned int *)v24;
        }
      }
      while ( v13 );
      if ( v17 )
      {
        v20 = v4[-1].m_listBuffers.m_pFirst;
        EnterCriticalSection((LPCRITICAL_SECTION)&v20[1]);
        for ( i = v17; ; i = (AK::StreamMgr::CAkStmMemView *)v24 )
        {
          v22 = i->pNextView;
          v25.m128i_i64[1] = (__int64)v14;
          v25.m128i_i64[0] = (__int64)v22;
          if ( i == v17 )
            v17 = v22;
          else
            *v14 = v22;
          _mm_store_si128((__m128i *)&v24, v25);
          AK::StreamMgr::CAkAutoStmBase::DestroyBuffer((AK::StreamMgr::CAkAutoStmBase *)((char *)v4 - 120), i);
          if ( !v22 )
            break;
          v14 = (AK::StreamMgr::CAkStmMemView **)*((_QWORD *)&v24 + 1);
        }
        AK::StreamMgr::CAkIOThread::NotifyMemChange((AK::StreamMgr::CAkIOThread *)v4[-1].m_listBuffers.m_pFirst);
        LeaveCriticalSection((LPCRITICAL_SECTION)&v20[1]);
      }
    }
    (*(void (__fastcall **)(unsigned __int64 *, unsigned __int64))(v4[-1].m_lockStatus.m_csLock.SpinCount + 72))(
      &v4[-1].m_lockStatus.m_csLock.SpinCount,
      v12);
    AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus((AK::StreamMgr::CAkAutoStmBase *)((char *)v4 - 120));
    LeaveCriticalSection((LPCRITICAL_SECTION)&v4[-1].m_uNextExpectedUserPosition);
  }
  return 1i64;
}

// File Line: 1840
// RVA: 0xAA4C00
__int64 __fastcall AK::StreamMgr::CAkAutoStmBase::SetMinimalBufferSize(AK::StreamMgr::CAkAutoStmBase *this, unsigned int in_uMinBufferSize)
{
  unsigned int v2; // er15
  AK::StreamMgr::CAkAutoStmBase *v3; // rsi
  unsigned int v4; // er14
  unsigned int v5; // ebp
  AK::StreamMgr::CAkClientThreadAwareVtbl *v6; // rax
  AkAutoStmBufSettings in_pBufferSettings; // [rsp+20h] [rbp-28h]

  v2 = (unsigned int)this->m_pFileDesc;
  v3 = this;
  v4 = in_uMinBufferSize;
  in_pBufferSettings.uMinBufferSize = in_uMinBufferSize;
  in_pBufferSettings.uBufferSize = 0;
  in_pBufferSettings.uBlockSize = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  v5 = AK::StreamMgr::CAkAutoStmBase::SetBufferingSettings(
         (AK::StreamMgr::CAkAutoStmBase *)((char *)v3 - 120),
         &in_pBufferSettings,
         v3[-1].m_listBuffers.m_pFirst[10].m_uOffsetInBlock);
  if ( v5 == 1 )
  {
    if ( LODWORD(v3->m_pFileDesc) > v2 )
      (*(void (__fastcall **)(unsigned __int64 *, _QWORD))(v3[-1].m_lockStatus.m_csLock.SpinCount + 80))(
        &v3[-1].m_lockStatus.m_csLock.SpinCount,
        v4);
  }
  else
  {
    v6 = v3->vfptr;
    BYTE2(v3->m_lockStatus.m_csLock.LockSemaphore) |= 2u;
    ((void (__fastcall *)(AK::StreamMgr::CAkAutoStmBase *))v6[12].__vecDelDtor)(v3);
    AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus((AK::StreamMgr::CAkAutoStmBase *)((char *)v3 - 120));
    if ( LOBYTE(v3[-1].m_pDevice) )
      AK::StreamMgr::CAkIOThread::SignalIOCompleted(
        (AK::StreamMgr::CAkIOThread *)v3[-1].m_listBuffers.m_pFirst,
        (AK::StreamMgr::CAkClientThreadAware *)&v3[-1].m_lockStatus.m_csLock.SpinCount);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&v3[-1].m_uNextExpectedUserPosition);
  return v5;
}

// File Line: 1873
// RVA: 0xAA4ED0
signed __int64 __fastcall AK::StreamMgr::CAkStdStmBase::SetStreamName(AK::StreamMgr::CAkStdStmBase *this, const wchar_t *in_pszStreamName)
{
  const wchar_t *v2; // rdi
  void *v3; // rdx
  AK::StreamMgr::CAkStdStmBase *v4; // rsi
  signed __int64 v5; // rbx
  unsigned __int64 v6; // rbx
  wchar_t *v7; // rax

  v2 = in_pszStreamName;
  v3 = *(void **)&this[-1].m_uTotalScheduledSize;
  v4 = this;
  if ( v3 )
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v3);
  if ( v2 )
  {
    v5 = -1i64;
    do
      ++v5;
    while ( v2[v5] );
    v6 = v5 + 1;
    v7 = (wchar_t *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 2 * v6);
    *(_QWORD *)&v4[-1].m_uTotalScheduledSize = v7;
    if ( !v7 )
      return 52i64;
    AKPLATFORM::SafeStrCpy(v7, v2, v6);
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
  AK::StreamMgr::CAkAutoStmBase *v1; // rdi
  char v2; // dl
  signed __int64 v3; // rcx
  char v4; // al
  AK::StreamMgr::CAkStmMemView *v5; // rbx

  v1 = this;
  if ( !(BYTE2(this->m_lockStatus.m_csLock.LockSemaphore) & 1) )
  {
    EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
    v2 = *((_BYTE *)&v1[-1] + 197);
    BYTE2(v1->m_lockStatus.m_csLock.LockSemaphore) |= 1u;
    v3 = (signed __int64)&v1[-1].m_lockStatus.m_csLock.SpinCount;
    v4 = !(v2 & 4) && !(v2 & 8);
    *(_BYTE *)(v3 + 117) = v2 ^ (v2 ^ (v4 << 6)) & 0x40;
    AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus((AK::StreamMgr::CAkAutoStmBase *)v3);
    LeaveCriticalSection((LPCRITICAL_SECTION)&v1[-1].m_uNextExpectedUserPosition);
    v5 = v1[-1].m_listBuffers.m_pFirst;
    EnterCriticalSection((LPCRITICAL_SECTION)&v5[1]);
    AK::StreamMgr::CAkIOThread::NotifyMemChange((AK::StreamMgr::CAkIOThread *)v1[-1].m_listBuffers.m_pFirst);
    LeaveCriticalSection((LPCRITICAL_SECTION)&v5[1]);
    *(_QWORD *)&v1[-1].m_listBuffers.m_ulNumListItems = *(_QWORD *)&v1[-1].m_listBuffers.m_pFirst[4].m_uOffsetInBlock;
  }
  return (unsigned int)((BYTE2(v1->m_lockStatus.m_csLock.LockSemaphore) & 2) != 0) + 1;
}

// File Line: 1929
// RVA: 0xAA5000
signed __int64 __fastcall AK::StreamMgr::CAkAutoStmBase::Stop(AK::StreamMgr::CAkAutoStmBase *this)
{
  AK::StreamMgr::CAkAutoStmBase *v1; // rdi

  v1 = this;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  BYTE2(v1->m_lockStatus.m_csLock.LockSemaphore) &= 0xFEu;
  *((_BYTE *)&v1[-1] + 197) &= 0xBFu;
  AK::StreamMgr::CAkAutoStmBase::Flush((AK::StreamMgr::CAkAutoStmBase *)((char *)v1 - 120));
  LeaveCriticalSection((LPCRITICAL_SECTION)&v1[-1].m_uNextExpectedUserPosition);
  return 1i64;
}

// File Line: 1943
// RVA: 0xAA3AE0
void *(__fastcall *__fastcall AK::StreamMgr::CAkAutoStmBase::GetPosition(AK::StreamMgr::CAkAutoStmBase *this, bool *out_pbEndOfStream))(AK::IAkAutoStream *this, unsigned int)
{
  AK::StreamMgr::CAkAutoStmBase *v2; // rsi
  bool *v3; // r14
  __int64 v4; // rax
  void *(__fastcall *v5)(AK::IAkAutoStream *, unsigned int); // rdi

  v2 = this;
  v3 = out_pbEndOfStream;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  v4 = *(_QWORD *)&v2->m_lockStatus.m_csLock.LockCount;
  if ( v4 )
    v5 = (void *(__fastcall *)(AK::IAkAutoStream *, unsigned int))(**(_QWORD **)(v4 + 8) + *(unsigned int *)(v4 + 16));
  else
    v5 = (void *(__fastcall *)(AK::IAkAutoStream *, unsigned int))v2->m_hBlockEvent;
  if ( v3 )
    *v3 = (char *)v5 >= (char *)v2[-1].vfptr->__vecDelDtor;
  LeaveCriticalSection((LPCRITICAL_SECTION)&v2[-1].m_uNextExpectedUserPosition);
  return v5;
}

// File Line: 1966
// RVA: 0xAA4CC0
signed __int64 __fastcall AK::StreamMgr::CAkAutoStmBase::SetPosition(AK::StreamMgr::CAkAutoStmBase *this, __int64 in_iMoveOffset, AkMoveMethod in_eMoveMethod, __int64 *out_piRealOffset)
{
  __int64 *v4; // rsi
  AkMoveMethod v5; // edi
  __int64 v6; // rbx
  AK::StreamMgr::CAkAutoStmBase *v7; // r14
  signed __int64 v8; // rdx
  int v9; // edi

  v4 = out_piRealOffset;
  v5 = in_eMoveMethod;
  v6 = in_iMoveOffset;
  v7 = this;
  if ( out_piRealOffset )
    *out_piRealOffset = 0i64;
  if ( in_eMoveMethod )
  {
    if ( in_eMoveMethod == 1 )
    {
      v6 = (__int64)this->vfptr[13].__vecDelDtor((AK::StreamMgr::CAkClientThreadAware *)this, 0) + in_iMoveOffset;
    }
    else
    {
      if ( in_eMoveMethod != 2 )
        return 31i64;
      v6 = (__int64)this[-1].vfptr->__vecDelDtor + in_iMoveOffset;
    }
  }
  if ( v6 < 0 )
    return 31i64;
  v8 = v6 % *(unsigned int *)&v7[-1].m_uNextToGrant;
  if ( v8 )
    v6 -= v8;
  if ( v4 )
  {
    if ( v5 )
    {
      v9 = v5 - 1;
      if ( v9 )
      {
        if ( v9 == 1 )
          *v4 = v6 - (unsigned __int64)v7[-1].vfptr->__vecDelDtor;
      }
      else
      {
        *v4 = v6 - (__int64)v7->vfptr[13].__vecDelDtor((AK::StreamMgr::CAkClientThreadAware *)&v7->vfptr, 0);
      }
    }
    else
    {
      *v4 = v6;
    }
  }
  AK::StreamMgr::CAkAutoStmBase::ForceFilePosition((AK::StreamMgr::CAkAutoStmBase *)((char *)v7 - 120), v6);
  return 1i64;
}

// File Line: 2037
// RVA: 0xAA39C0
bool __fastcall AK::StreamMgr::CAkAutoStmBase::GetBufferOrReserveCacheBlock(AK::StreamMgr::CAkAutoStmBase *this, void **out_pBuffer, unsigned int *out_uSize)
{
  unsigned int *v3; // rsi
  void **v4; // rdi
  AK::StreamMgr::CAkAutoStmBase *v5; // rbx
  void *v7; // rax

  v3 = out_uSize;
  v4 = out_pBuffer;
  v5 = this;
  if ( !(*((_BYTE *)&this->0 + 117) & 0x10) )
    return 0;
  v7 = AK::StreamMgr::CAkAutoStmBase::GetReadBuffer(this, out_uSize);
  *v4 = v7;
  if ( v7 )
    return 1;
  if ( v5->m_pDevice->vfptr[2].__vecDelDtor((AK::StreamMgr::CAkIOThread *)&v5->m_pDevice->vfptr, (unsigned int)v5) )
    *v4 = AK::StreamMgr::CAkAutoStmBase::GetReadBuffer(v5, v3);
  return *v4 != 0i64;
}

// File Line: 2071
// RVA: 0xAA3880
signed __int64 __fastcall AK::StreamMgr::CAkAutoStmBase::GetBuffer(AK::StreamMgr::CAkAutoStmBase *this, void **out_pBuffer, unsigned int *out_uSize, bool in_bWait)
{
  AK::StreamMgr::CAkAutoStmBase *v4; // rbx
  bool v5; // r15
  unsigned int *v6; // r14
  void **v7; // rsi
  void *v8; // rax
  void *v9; // rax
  signed __int64 result; // rax

  v4 = this;
  *out_pBuffer = 0i64;
  v5 = in_bWait;
  v6 = out_uSize;
  *out_uSize = 0;
  v7 = out_pBuffer;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  v8 = AK::StreamMgr::CAkAutoStmBase::GetReadBuffer((AK::StreamMgr::CAkAutoStmBase *)((char *)v4 - 120), v6);
  *v7 = v8;
  if ( !v8
    && !(BYTE2(v4->m_lockStatus.m_csLock.LockSemaphore) & 2)
    && (AK::StreamMgr::CAkAutoStmBase::GetBufferOrReserveCacheBlock(
          (AK::StreamMgr::CAkAutoStmBase *)((char *)v4 - 120),
          v7,
          v6)
     || v5)
    && !*v7 )
  {
    do
    {
      if ( BYTE2(v4->m_lockStatus.m_csLock.LockSemaphore) & 2
        || !(*((_BYTE *)&v4[-1] + 197) & 0x20) && !HIDWORD(v4->m_pDeferredOpenData) )
      {
        break;
      }
      AK::StreamMgr::CAkClientThreadAware::SetBlockedStatus((AK::StreamMgr::CAkClientThreadAware *)&v4[-1].m_lockStatus.m_csLock.SpinCount);
      LeaveCriticalSection((LPCRITICAL_SECTION)&v4[-1].m_uNextExpectedUserPosition);
      AK::StreamMgr::CAkIOThread::WaitForIOCompletion(
        (AK::StreamMgr::CAkIOThread *)v4[-1].m_listBuffers.m_pFirst,
        (AK::StreamMgr::CAkClientThreadAware *)&v4[-1].m_lockStatus.m_csLock.SpinCount);
      EnterCriticalSection((LPCRITICAL_SECTION)&v4[-1].m_uNextExpectedUserPosition);
      v9 = AK::StreamMgr::CAkAutoStmBase::GetReadBuffer((AK::StreamMgr::CAkAutoStmBase *)((char *)v4 - 120), v6);
      *v7 = v9;
    }
    while ( !v9 );
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&v4[-1].m_uNextExpectedUserPosition);
  if ( BYTE2(v4->m_lockStatus.m_csLock.LockSemaphore) & 2 )
    return 2i64;
  if ( *v7 )
  {
    if ( !(*((_BYTE *)&v4[-1] + 197) & 4) || (result = 17i64, v4->m_hBlockEvent < (void *)v4[-1].vfptr->__vecDelDtor) )
      result = 45i64;
  }
  else if ( *((_BYTE *)&v4[-1] + 197) & 4 && v4->m_hBlockEvent >= (void *)v4[-1].vfptr->__vecDelDtor )
  {
    result = 17i64;
  }
  else
  {
    result = 46i64;
  }
  return result;
}

// File Line: 2150
// RVA: 0xAA41D0
signed __int64 __fastcall AK::StreamMgr::CAkAutoStmBase::ReleaseBuffer(AK::StreamMgr::CAkAutoStmBase *this)
{
  _RTL_CRITICAL_SECTION *v1; // rbx
  AK::StreamMgr::CAkAutoStmBase *v2; // rdi
  AK::StreamMgr::AkMemBlock *v3; // rsi
  AK::StreamMgr::CAkStmMemView *v4; // r14
  _QWORD *v5; // rax
  AK::StreamMgr::AkMemBlock *v6; // rdx
  AK::StreamMgr::CAkStmMemView *v7; // rbp
  AK::StreamMgr::AkMemBlock *v8; // rax
  signed __int64 result; // rax

  v1 = (_RTL_CRITICAL_SECTION *)&this[-1].m_uNextExpectedUserPosition;
  v2 = this;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  if ( LOBYTE(v2->m_lockStatus.m_csLock.LockSemaphore) )
  {
    v3 = *(AK::StreamMgr::AkMemBlock **)&v2->m_lockStatus.m_csLock.LockCount;
    v4 = v2[-1].m_listBuffers.m_pFirst;
    EnterCriticalSection((LPCRITICAL_SECTION)&v4[1]);
    v5 = *(_QWORD **)&v2->m_lockStatus.m_csLock.LockCount;
    if ( v5 )
    {
      if ( *v5 )
      {
        *(_QWORD *)&v2->m_lockStatus.m_csLock.LockCount = *v5;
      }
      else
      {
        *(_QWORD *)&v2->m_lockStatus.m_csLock.LockCount = 0i64;
        v2->m_lockStatus.m_csLock.OwningThread = 0i64;
      }
      --LODWORD(v2->m_lockStatus.m_csLock.DebugInfo);
    }
    v6 = (AK::StreamMgr::AkMemBlock *)v3->pData;
    v7 = v2[-1].m_listBuffers.m_pFirst;
    v3->pData = 0i64;
    if ( v6 )
      AK::StreamMgr::CAkIOMemMgr::ReleaseBlock((AK::StreamMgr::CAkIOMemMgr *)&v7[7], v6);
    v8 = v7[11].m_pBlock;
    if ( v8 )
    {
      v3->uPosition = (unsigned __int64)v8;
      v7[11].m_pBlock = v3;
    }
    else
    {
      v7[11].m_pBlock = v3;
      v3->uPosition = 0i64;
    }
    AK::StreamMgr::CAkIOThread::NotifyMemChange((AK::StreamMgr::CAkIOThread *)v2[-1].m_listBuffers.m_pFirst);
    LeaveCriticalSection((LPCRITICAL_SECTION)&v4[1]);
    --LOBYTE(v2->m_lockStatus.m_csLock.LockSemaphore);
    AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus((AK::StreamMgr::CAkAutoStmBase *)((char *)v2 - 120));
    LeaveCriticalSection(v1);
    result = 1i64;
  }
  else
  {
    LeaveCriticalSection(v1);
    result = 2i64;
  }
  return result;
}

// File Line: 2190
// RVA: 0xAA40B0
signed __int64 __fastcall AK::StreamMgr::CAkAutoStmBase::QueryBufferingStatus(AK::StreamMgr::CAkAutoStmBase *this, unsigned int *out_uNumBytesAvailable)
{
  unsigned int *v2; // rsi
  AK::StreamMgr::CAkAutoStmBase *v3; // rdi
  __int64 v5; // rcx
  __int64 *v6; // rax
  unsigned int v7; // ebp

  v2 = out_uNumBytesAvailable;
  v3 = this;
  if ( BYTE2(this->m_lockStatus.m_csLock.LockSemaphore) & 2 )
    return 2i64;
  EnterCriticalSection((LPCRITICAL_SECTION)&this[-1].m_uNextExpectedUserPosition);
  *v2 = 0;
  v5 = LOBYTE(v3->m_lockStatus.m_csLock.LockSemaphore);
  if ( (unsigned int)v5 >= LODWORD(v3->m_lockStatus.m_csLock.DebugInfo) )
  {
    v7 = 46;
  }
  else
  {
    v6 = *(__int64 **)&v3->m_lockStatus.m_csLock.LockCount;
    v7 = 45;
    if ( LOBYTE(v3->m_lockStatus.m_csLock.LockSemaphore) )
    {
      do
      {
        v6 = (__int64 *)*v6;
        --v5;
      }
      while ( v5 );
    }
    for ( ; v6; v6 = (__int64 *)*v6 )
      *v2 += *(_DWORD *)(v6[1] + 24) - *((_DWORD *)v6 + 4);
  }
  if ( !(*((_BYTE *)&v3[-1] + 197) & 0x20) && HIDWORD(v3->m_pDeferredOpenData) <= *v2
    || LOBYTE(v3[-1].m_listBuffers.m_pFirst[4].m_pBlock) )
  {
    v7 = 17;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&v3[-1].m_uNextExpectedUserPosition);
  return v7;
}

// File Line: 2237
// RVA: 0xAA3AC0
__int64 __fastcall AK::StreamMgr::CAkAutoStmBase::GetNominalBuffering(AK::StreamMgr::CAkAutoStmBase *this)
{
  return (unsigned int)(signed int)(float)(*((float *)&this[-1].m_listBuffers.m_pFirst[10] + 5)
                                         * *((float *)&this->m_bIsBlocked + 1));
}

// File Line: 2251
// RVA: 0xAA4040
void __fastcall AK::StreamMgr::CAkAutoStmBase::OnFileDeferredOpen(AK::StreamMgr::CAkAutoStmBase *this)
{
  AK::IAkAutoStreamVtbl *v1; // rax
  AK::StreamMgr::CAkAutoStmBase *v2; // rbx
  int *v3; // rcx
  char v4; // [rsp+20h] [rbp-18h]
  unsigned int v5; // [rsp+28h] [rbp-10h]

  v1 = this->vfptr;
  *((_BYTE *)&this->0 + 117) |= 0x10u;
  v2 = this;
  v1->GetHeuristics((AK::IAkAutoStream *)&this->vfptr, (AkAutoStmHeuristics *)&v4);
  v3 = (int *)v2->m_pFileDesc;
  if ( (signed __int64)v5 > *(_QWORD *)v3 )
  {
    v5 = *v3;
    v2->vfptr->SetHeuristics((AK::IAkAutoStream *)&v2->vfptr, (AkAutoStmHeuristics *)&v4);
  }
}

// File Line: 2271
// RVA: 0xAA2C20
void __fastcall AK::StreamMgr::CAkAutoStmBase::AddMemView(AK::StreamMgr::CAkAutoStmBase *this, AK::StreamMgr::CAkStmMemView *in_pMemView, bool in_bStoreData)
{
  AK::StreamMgr::CAkStmMemView *v3; // rsi
  AK::StreamMgr::CAkAutoStmBase *v4; // rdi
  AK::StreamMgr::CAkStmMemView *v5; // rax
  AK::StreamMgr::CAkDeviceBase *v6; // rbx

  v3 = in_pMemView;
  v4 = this;
  if ( !in_bStoreData || *((_BYTE *)&this->0 + 117) & 8 || *((_BYTE *)this + 194) & 2 )
  {
    v6 = this->m_pDevice;
    EnterCriticalSection(&v6->m_lockSems.m_csLock);
    AK::StreamMgr::CAkAutoStmBase::DestroyBuffer(v4, v3);
    AK::StreamMgr::CAkIOThread::NotifyMemChange((AK::StreamMgr::CAkIOThread *)&v4->m_pDevice->vfptr);
    LeaveCriticalSection(&v6->m_lockSems.m_csLock);
  }
  else
  {
    *((_DWORD *)in_pMemView + 5) &= 0xFFFFFFFB;
    *((_DWORD *)in_pMemView + 5) |= 3u;
    in_pMemView->pNextView = 0i64;
    v5 = this->m_listBuffers.m_pLast;
    if ( v5 )
    {
      v5->pNextView = in_pMemView;
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
void __fastcall AK::StreamMgr::CAkAutoStmBase::UpdateTaskStatus(AK::StreamMgr::CAkAutoStmBase *this, AKRESULT in_eIOResult)
{
  AK::StreamMgr::CAkAutoStmBase *v2; // rbx

  v2 = this;
  if ( in_eIOResult == 2 )
  {
    *((_BYTE *)this + 194) |= 2u;
    this->vfptr->Stop((AK::IAkAutoStream *)&this->vfptr);
  }
  AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus(v2);
  if ( v2->m_bIsBlocked )
    AK::StreamMgr::CAkIOThread::SignalIOCompleted(
      (AK::StreamMgr::CAkIOThread *)&v2->m_pDevice->vfptr,
      (AK::StreamMgr::CAkClientThreadAware *)&v2->vfptr);
}

// File Line: 2342
// RVA: 0xAA3F30
void __fastcall AK::StreamMgr::CAkAutoStmBase::Kill(AK::StreamMgr::CAkAutoStmBase *this)
{
  AK::StreamMgr::CAkAutoStmBase *v1; // rdi
  AK::IAkAutoStreamVtbl *v2; // rax

  v1 = this;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  v2 = v1->vfptr;
  *((_BYTE *)v1 + 194) |= 2u;
  v2->Stop((AK::IAkAutoStream *)&v1->vfptr);
  AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus(v1);
  if ( v1->m_bIsBlocked )
    AK::StreamMgr::CAkIOThread::SignalIOCompleted(
      (AK::StreamMgr::CAkIOThread *)&v1->m_pDevice->vfptr,
      (AK::StreamMgr::CAkClientThreadAware *)&v1->vfptr);
  LeaveCriticalSection(&v1->m_lockStatus.m_csLock);
}

// File Line: 2350
// RVA: 0xAA3230
float __fastcall AK::StreamMgr::CAkAutoStmBase::EffectiveDeadline(AK::StreamMgr::CAkAutoStmBase *this)
{
  return (float)(signed int)this->m_uVirtualBufferingSize / this->m_fThroughput;
}

// File Line: 2406
// RVA: 0xAA3740
void __fastcall AK::StreamMgr::CAkAutoStmBase::ForceFilePosition(AK::StreamMgr::CAkAutoStmBase *this, const unsigned __int64 in_uNewPosition)
{
  AK::StreamMgr::CAkAutoStmBase *v2; // rdi
  unsigned __int64 v3; // rsi
  unsigned int v4; // ecx
  AK::StreamMgr::CAkStmMemView *v5; // rax
  __int64 v6; // rdx
  AK::StreamMgr::CAkAutoStmBase *v7; // rcx

  v2 = this;
  v3 = in_uNewPosition;
  EnterCriticalSection(&this->m_lockStatus.m_csLock);
  v4 = (unsigned __int8)v2->m_uNextToGrant;
  v2->m_uNextExpectedUserPosition = v3;
  if ( v4 >= v2->m_listBuffers.m_ulNumListItems )
  {
    v2->vfptr[9].__vecDelDtor((AK::StreamMgr::CAkClientThreadAware *)&v2->vfptr, v3);
    v7 = v2;
LABEL_8:
    AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus(v7);
    goto LABEL_9;
  }
  v5 = v2->m_listBuffers.m_pFirst;
  if ( v4 )
  {
    v6 = v4;
    do
    {
      v5 = v5->pNextView;
      --v6;
    }
    while ( v6 );
  }
  v7 = v2;
  if ( v5->m_pBlock->uPosition + v5->m_uOffsetInBlock == v3 )
    goto LABEL_8;
  AK::StreamMgr::CAkAutoStmBase::Flush(v2);
LABEL_9:
  LeaveCriticalSection(&v2->m_lockStatus.m_csLock);
}

// File Line: 2440
// RVA: 0xAA5050
void __fastcall AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus(AK::StreamMgr::CAkAutoStmBase *this)
{
  AK::StreamMgr::CAkAutoStmBase *v1; // rdi
  unsigned __int64 v2; // rbx
  char v3; // al
  char v4; // al
  char v5; // cl
  char v6; // al
  char v7; // al
  AK::StreamMgr::CAkIOThread *v8; // rcx
  char v9; // al
  AK::StreamMgr::CAkIOThread *v10; // rcx

  v1 = this;
  if ( this->m_uLoopEnd
    || (v2 = this->m_pFileDesc->iFileSize, ((__int64 (*)(void))this->vfptr[7].__vecDelDtor)() < v2)
    || (v3 = *((_BYTE *)&v1->0 + 117), !(v3 & 0x10)) )
  {
    *((_BYTE *)&v1->0 + 117) &= 0xFBu;
    v5 = *((_BYTE *)&v1->0 + 117);
    v6 = *((_BYTE *)v1 + 194) & 1 && !(v5 & 8);
    v4 = v5 ^ (v5 ^ (v6 << 6)) & 0x40;
  }
  else
  {
    v4 = v3 & 0xBF | 4;
  }
  *((_BYTE *)&v1->0 + 117) = v4;
  if ( v4 & 0x40
    && (float)(signed int)v1->m_uVirtualBufferingSize < (float)(v1->m_pDevice->m_fTargetAutoStmBufferLength
                                                              * v1->m_fThroughput)
    || v4 & 8 && ((unsigned __int8 (__fastcall *)(AK::StreamMgr::CAkAutoStmBase *))v1->vfptr[1].__vecDelDtor)(v1) )
  {
    v7 = *((_BYTE *)&v1->0 + 117);
    if ( !(v7 & 0x20) )
    {
      v8 = (AK::StreamMgr::CAkIOThread *)&v1->m_pDevice->vfptr;
      *((_BYTE *)&v1->0 + 117) = v7 | 0x20;
      AK::StreamMgr::CAkIOThread::AutoSemIncr(v8);
    }
  }
  else
  {
    v9 = *((_BYTE *)&v1->0 + 117);
    if ( v9 & 0x20 )
    {
      v10 = (AK::StreamMgr::CAkIOThread *)&v1->m_pDevice->vfptr;
      *((_BYTE *)&v1->0 + 117) = v9 & 0xDF;
      AK::StreamMgr::CAkIOThread::AutoSemDecr(v10);
    }
  }
}

// File Line: 2492
// RVA: 0xAA3B80
char *__fastcall AK::StreamMgr::CAkAutoStmBase::GetReadBuffer(AK::StreamMgr::CAkAutoStmBase *this, unsigned int *out_uSize)
{
  unsigned int v2; // er8
  unsigned int *v3; // rsi
  AK::StreamMgr::CAkAutoStmBase *v4; // rdi
  AK::StreamMgr::CAkStmMemView *v5; // rbx
  __int64 v6; // rax
  char *result; // rax
  AK::StreamMgr::AkMemBlock *v8; // rdx
  __int64 v9; // r8
  unsigned __int64 v10; // r9
  unsigned __int64 v11; // rcx
  unsigned int v12; // ecx

  v2 = (unsigned __int8)this->m_uNextToGrant;
  v3 = out_uSize;
  v4 = this;
  if ( v2 >= this->m_listBuffers.m_ulNumListItems )
  {
    *out_uSize = 0;
    result = 0i64;
  }
  else
  {
    v5 = this->m_listBuffers.m_pFirst;
    if ( this->m_uNextToGrant )
    {
      v6 = (unsigned __int8)this->m_uNextToGrant;
      do
      {
        v5 = v5->pNextView;
        --v6;
      }
      while ( v6 );
    }
    if ( v5->m_pBlock->uPosition + v5->m_uOffsetInBlock == this->m_uNextExpectedUserPosition )
    {
      this->m_uNextToGrant = v2 + 1;
      this->m_uNextExpectedUserPosition = v5->m_pBlock->uPosition + v5->m_pBlock->uAvailableSize;
      *out_uSize = v5->m_pBlock->uAvailableSize - v5->m_uOffsetInBlock;
      v8 = v5->m_pBlock;
      v9 = v5->m_uOffsetInBlock;
      v10 = v8->uPosition;
      v11 = this->m_uLoopEnd;
      if ( v8->uPosition + v9 >= v11 || v10 + v8->uAvailableSize <= v11 )
        v12 = v8->uAvailableSize;
      else
        v12 = v11 - v10;
      v4->m_uVirtualBufferingSize -= v12 - v9;
      AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus(v4);
      result = (char *)v5->m_pBlock->pData + v5->m_uOffsetInBlock;
    }
    else
    {
      this->vfptr[11].__vecDelDtor((AK::StreamMgr::CAkClientThreadAware *)this, 0);
      AK::StreamMgr::CAkAutoStmBase::Flush(v4);
      *v3 = 0;
      result = 0i64;
    }
  }
  return result;
}

// File Line: 2535
// RVA: 0xAA3520
void __fastcall AK::StreamMgr::CAkAutoStmBase::Flush(AK::StreamMgr::CAkAutoStmBase *this)
{
  AK::StreamMgr::CAkAutoStmBase *v1; // rdi
  __int64 v2; // rax
  AK::StreamMgr::CAkStmMemView *v3; // rbx
  AK::StreamMgr::CAkStmMemView *v4; // rsi
  AK::StreamMgr::CAkDeviceBase *v5; // r14
  AK::StreamMgr::CAkStmMemView *v6; // rbp
  __m128i v7; // [rsp+20h] [rbp-28h]
  __m128i v8; // [rsp+30h] [rbp-18h]

  v1 = this;
  ((void (*)(void))this->vfptr[8].__vecDelDtor)();
  v2 = (unsigned __int8)v1->m_uNextToGrant;
  if ( v1->m_listBuffers.m_ulNumListItems > (unsigned int)v2 )
  {
    v3 = v1->m_listBuffers.m_pFirst;
    v4 = 0i64;
    if ( (_DWORD)v2 )
    {
      do
      {
        v4 = v3;
        v3 = v3->pNextView;
        --v2;
      }
      while ( v2 );
    }
    v5 = v1->m_pDevice;
    EnterCriticalSection(&v5->m_lockSems.m_csLock);
    if ( v3 )
    {
      while ( 1 )
      {
        v6 = v3->pNextView;
        v7.m128i_i64[1] = (__int64)v4;
        v7.m128i_i64[0] = (__int64)v3->pNextView;
        if ( v3 == v1->m_listBuffers.m_pFirst )
          v1->m_listBuffers.m_pFirst = v6;
        else
          v4->pNextView = v6;
        if ( v3 == v1->m_listBuffers.m_pLast )
          v1->m_listBuffers.m_pLast = v4;
        --v1->m_listBuffers.m_ulNumListItems;
        _mm_store_si128(&v8, v7);
        AK::StreamMgr::CAkAutoStmBase::DestroyBuffer(v1, v3);
        if ( !v6 )
          break;
        v4 = (AK::StreamMgr::CAkStmMemView *)v8.m128i_i64[1];
        v3 = (AK::StreamMgr::CAkStmMemView *)v8.m128i_i64[0];
      }
    }
    AK::StreamMgr::CAkIOThread::NotifyMemChange((AK::StreamMgr::CAkIOThread *)&v1->m_pDevice->vfptr);
    LeaveCriticalSection(&v5->m_lockSems.m_csLock);
  }
  AK::StreamMgr::CAkAutoStmBase::UpdateSchedulingStatus(v1);
}

