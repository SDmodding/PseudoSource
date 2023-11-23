// File Line: 29
// RVA: 0xD2F980
__int64 __fastcall hkpCollisionQueryJobQueueUtils::popCollisionJob(
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
  int v14; // eax
  __int64 v15; // rax
  __int64 v16; // rcx
  int v17; // eax
  __int64 v18; // rax
  __int64 v19; // rcx
  int v20; // eax
  __int64 v21; // rax
  __int64 v22; // rcx

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
    switch ( jobIn->m_jobSubType )
    {
      case 1:
        v17 = *(_DWORD *)&jobIn->m_data[36];
        if ( *(_DWORD *)&jobIn->m_data[48] > v17 )
        {
          *(_DWORD *)&jobOut->m_data[48] = v17;
          v18 = *(int *)&jobIn->m_data[36];
          *(_DWORD *)&jobIn->m_data[48] -= v18;
          v19 = 3 * v18;
          result = 1i64;
          *(_QWORD *)&jobIn->m_data[40] += 16 * v19;
          return result;
        }
        break;
      case 2:
        v14 = *(_DWORD *)&jobIn->m_data[44];
        if ( *(_DWORD *)&jobIn->m_data[56] > v14 )
        {
          *(_DWORD *)&jobOut->m_data[56] = v14;
          v15 = *(int *)&jobIn->m_data[44];
          *(_DWORD *)&jobIn->m_data[56] -= v15;
          v16 = *(_QWORD *)&jobIn->m_data[48] + 24 * v15;
          result = 1i64;
          *(_QWORD *)&jobIn->m_data[48] = v16;
          return result;
        }
        break;
      case 3:
        v11 = *(_DWORD *)&jobIn->m_data[48];
        if ( *(_DWORD *)&jobIn->m_data[64] > v11 )
        {
          *(_DWORD *)&jobOut->m_data[64] = v11;
          v12 = *(int *)&jobIn->m_data[48];
          *(_DWORD *)&jobIn->m_data[64] -= v12;
          v13 = 5 * v12;
          result = 1i64;
          *(_QWORD *)&jobIn->m_data[56] += 16 * v13;
          return result;
        }
        break;
      case 4:
        v7 = *(_DWORD *)&jobIn->m_data[32];
        if ( *(_DWORD *)&jobIn->m_data[48] > v7 )
        {
          *(_DWORD *)&jobOut->m_data[48] = v7;
          v8 = *(int *)&jobIn->m_data[32];
          *(_DWORD *)&jobIn->m_data[48] -= v8;
          v9 = v8;
          result = 1i64;
          *(_QWORD *)&jobIn->m_data[40] += v9 << 6;
          return result;
        }
        break;
    }
  }
  else
  {
    v20 = *(_DWORD *)&jobIn->m_data[56];
    if ( *(_DWORD *)&jobIn->m_data[72] > v20 )
    {
      *(_DWORD *)&jobOut->m_data[72] = v20;
      v21 = *(int *)&jobIn->m_data[56];
      *(_DWORD *)&jobIn->m_data[72] -= v21;
      v22 = 3 * v21;
      result = 1i64;
      *(_QWORD *)&jobIn->m_data[64] += 16 * v22;
      return result;
    }
  }
  return 0i64;
}

// File Line: 110
// RVA: 0xD2FAC0
__int64 __fastcall hkpCollisionQueryJobQueueUtils::finishCollisionJob(
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkJobQueue::JobQueueEntry *jobIn,
        hkJobQueue::JobQueueEntryInput *newJobCreated)
{
  _DWORD *v4; // rcx
  bool v5; // zf
  volatile signed __int32 *v6; // rcx
  volatile signed __int32 *v7; // rdx
  hkSemaphore *v8; // rcx

  v4 = *(_DWORD **)&jobIn->m_data[8];
  if ( !jobIn->m_jobSubType )
  {
    v5 = (*v4)-- == 1;
    if ( !v5 )
      return 1i64;
    v7 = *(volatile signed __int32 **)&jobIn->m_data[24];
    if ( v7 )
      _InterlockedExchangeAdd(v7, 1u);
    goto LABEL_11;
  }
  if ( jobIn->m_jobSubType == 1
    || jobIn->m_jobSubType == 2
    || (unsigned int)(unsigned __int8)jobIn->m_jobSubType - 3 <= 1 )
  {
    v5 = (*v4)-- == 1;
    if ( v5 )
    {
      v6 = *(volatile signed __int32 **)&jobIn->m_data[24];
      if ( v6 )
        _InterlockedExchangeAdd(v6, 1u);
LABEL_11:
      v8 = *(hkSemaphore **)jobIn->m_data;
      if ( v8 )
        hkSemaphore::release(v8, 1);
    }
  }
  return 1i64;
}

