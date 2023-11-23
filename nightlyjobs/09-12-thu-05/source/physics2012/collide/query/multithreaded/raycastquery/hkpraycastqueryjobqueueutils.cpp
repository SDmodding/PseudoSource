// File Line: 31
// RVA: 0xD2FB30
__int64 __fastcall hkpRayCastQueryJobQueueUtils::popRayCastQueryJob(
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkJobQueue::JobQueueEntry *jobIn,
        hkJobQueue::JobQueueEntry *jobOut)
{
  int v4; // ecx
  hkJobQueue::JobQueueEntry *v5; // rax
  hkJob v6; // xmm0
  int v7; // eax
  __int64 v8; // rax
  __int64 v9; // rcx
  __int64 result; // rax
  int v11; // eax
  __int64 v12; // rax
  __int64 v13; // rcx

  v4 = 16;
  v5 = jobIn;
  do
  {
    v6 = v5->hkJob;
    --v4;
    v5 = (hkJobQueue::JobQueueEntry *)((char *)v5 + 16);
    *(hkJob *)((char *)v5 + (char *)jobOut - (char *)jobIn - 16) = v6;
  }
  while ( v4 > 0 );
  if ( jobIn->m_jobSubType )
  {
    if ( jobIn->m_jobSubType == 1 )
    {
      v7 = *(_DWORD *)&jobIn->m_data[32];
      if ( *(_DWORD *)&jobIn->m_data[48] > v7 )
      {
        *(_DWORD *)&jobOut->m_data[48] = v7;
        v8 = *(int *)&jobIn->m_data[32];
        *(_DWORD *)&jobIn->m_data[48] -= v8;
        v9 = *(_QWORD *)&jobIn->m_data[40] + 80 * v8;
        *(_DWORD *)&jobIn->m_data[64] = 0;
        *(_QWORD *)&jobIn->m_data[40] = v9;
        return 1i64;
      }
    }
  }
  else
  {
    v11 = *(_DWORD *)&jobIn->m_data[32];
    if ( *(_DWORD *)&jobIn->m_data[48] > v11 )
    {
      *(_DWORD *)&jobOut->m_data[48] = v11;
      v12 = *(int *)&jobIn->m_data[32];
      *(_DWORD *)&jobIn->m_data[48] -= v12;
      v13 = v12;
      result = 1i64;
      *(_QWORD *)&jobIn->m_data[40] += 112 * v13;
      return result;
    }
  }
  return 0i64;
}

// File Line: 90
// RVA: 0xD2FBD0
__int64 __fastcall hkpRayCastQueryJobQueueUtils::finishRayCastQueryJob(
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkJobQueue::JobQueueEntry *jobIn,
        hkJobQueue::JobQueueEntryInput *newJobCreated)
{
  _DWORD *v4; // rcx
  bool v5; // zf
  volatile signed __int32 *v6; // rax
  volatile signed __int32 *v7; // rcx
  hkSemaphore *v8; // rcx

  v4 = *(_DWORD **)&jobIn->m_data[8];
  if ( jobIn->m_jobSubType )
  {
    if ( jobIn->m_jobSubType != 1 )
      return 1i64;
    v5 = (*v4)-- == 1;
    if ( !v5 )
      return 1i64;
    v6 = *(volatile signed __int32 **)&jobIn->m_data[16];
    if ( v6 )
      _InterlockedExchangeAdd(v6, 1u);
  }
  else
  {
    v5 = (*v4)-- == 1;
    if ( !v5 )
      return 1i64;
    v7 = *(volatile signed __int32 **)&jobIn->m_data[16];
    if ( v7 )
      _InterlockedExchangeAdd(v7, 1u);
  }
  v8 = *(hkSemaphore **)jobIn->m_data;
  if ( v8 )
    hkSemaphore::release(v8, 1);
  return 1i64;
}

