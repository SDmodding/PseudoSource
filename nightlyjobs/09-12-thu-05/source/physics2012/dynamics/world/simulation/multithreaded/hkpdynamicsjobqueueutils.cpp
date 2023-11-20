// File Line: 118
// RVA: 0xD8BFC0
hkpAgentSectorHeader *__fastcall hkpAgentSectorHeader::allocate(int numTasks, int numAgentNnEntriesPerTask)
{
  __int64 v2; // rdi
  int v3; // esi
  _QWORD **v4; // rax
  hkpAgentSectorHeader *result; // rax
  int v6; // esi
  hkpAgentSectorHeader *v7; // r14
  hkpAgentSectorHeader *v8; // rbx
  _QWORD **v9; // rax
  __int64 v10; // rax
  _DWORD *v11; // rcx

  v2 = (unsigned int)numTasks;
  v3 = numAgentNnEntriesPerTask;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpAgentSectorHeader *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v4[11] + 8i64))(
                                     v4[11],
                                     (unsigned int)(8 * (signed __int16)v2 + 32));
  v6 = 32 * v3;
  v7 = result;
  result->m_openJobs = v2;
  result->m_numTotalTasks = v2;
  v8 = result + 1;
  result->m_sizeOfJobInfo = v6 + 32;
  if ( (signed int)v2 > 0 )
  {
    do
    {
      v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v10 = (*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v9[11] + 8i64))(v9[11], (unsigned int)(v6 + 32));
      *(_QWORD *)&v8->m_numTotalTasks = v10;
      if ( v10 )
      {
        v11 = (_DWORD *)(v10 + 16);
        *v11 = 16;
        v11[1] = 0;
        v11[2] = v6;
      }
      v8 = (hkpAgentSectorHeader *)((char *)v8 + 8);
      --v2;
    }
    while ( v2 );
    result = v7;
  }
  return result;
}

// File Line: 156
// RVA: 0xD8C080
void __fastcall hkpAgentSectorHeader::deallocate(hkpAgentSectorHeader *this)
{
  int v1; // ebp
  hkpAgentSectorHeader *v2; // rsi
  hkpAgentSectorHeader *i; // r14
  unsigned int v4; // ebx
  __int64 v5; // rdi
  _QWORD **v6; // rax
  unsigned int v7; // ebx
  _QWORD **v8; // rax

  v1 = 0;
  v2 = this;
  for ( i = this + 1; v1 < v2->m_numTotalTasks; i = (hkpAgentSectorHeader *)((char *)i + 8) )
  {
    v4 = v2->m_sizeOfJobInfo;
    v5 = *(_QWORD *)&i->m_numTotalTasks;
    v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, __int64, _QWORD))(*v6[11] + 16i64))(v6[11], v5, v4);
    ++v1;
  }
  v7 = 8 * SLOWORD(v2->m_numTotalTasks) + 32;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpAgentSectorHeader *, _QWORD))(*v8[11] + 16i64))(v8[11], v2, v7);
}

// File Line: 186
// RVA: 0xD8C130
hkJobQueue::JobPopFuncResult __fastcall hkpJobQueueUtils::popIntegrateJob(hkJobQueue *queue, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntry *jobIn, hkJobQueue::JobQueueEntry *jobOut)
{
  hkJobQueue::JobQueueEntry *v4; // r10
  signed int v5; // ecx
  hkJobQueue::JobQueueEntry *v6; // rax
  hkJob v7; // xmm0
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *v8; // rdx
  hkpSimulationIsland *v9; // rcx
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *v10; // rdx
  signed int v11; // eax
  hkJobQueue::JobPopFuncResult result; // eax
  unsigned __int16 v13; // cx
  _QWORD *v14; // rax
  unsigned __int16 v15; // cx
  unsigned __int64 v16; // rax
  __int64 v17; // rax
  int v18; // eax
  __int64 v19; // rcx
  __int64 v20; // rax
  __int128 v21; // xmm1

  v4 = jobIn;
  v5 = 16;
  v6 = jobIn;
  do
  {
    v7 = v6->0;
    --v5;
    v6 = (hkJobQueue::JobQueueEntry *)((char *)v6 + 16);
    *(hkJob *)((char *)v6 + (char *)jobOut - (char *)jobIn - 16) = v7;
  }
  while ( v5 > 0 );
  v8 = **(hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> ***)&jobIn->m_data[24];
  v9 = v8[4].m_data[*(unsigned __int16 *)jobOut->m_data];
  v10 = v8 + 4;
  *(_QWORD *)&jobOut->m_data[8] = v9;
  switch ( jobIn->m_jobSubType )
  {
    case 0:
      v11 = *(_DWORD *)&jobIn->m_data[32];
      if ( v11 <= 1 )
        goto $LN1_61;
      ++*(_WORD *)jobIn->m_data;
      *(_DWORD *)&jobIn->m_data[32] = v11 - 1;
      result = 1;
      *(_DWORD *)&jobOut->m_data[32] = 1;
      break;
    case 1:
      v13 = *(_WORD *)&jobIn->m_data[42];
      if ( v13 <= 0x80u )
        goto $LN1_61;
      *(_WORD *)&jobIn->m_data[40] += 128;
      *(_WORD *)&jobIn->m_data[42] = v13 - 128;
      *(_WORD *)&jobOut->m_data[42] = 128;
      result = 1;
      break;
    case 3:
    case 6:
    case 0xE:
      v18 = ((unsigned __int8)jobOut | (unsigned __int8)jobIn) & 0xF;
      if ( ((unsigned __int8)jobOut | (unsigned __int8)jobIn) & 0xF )
      {
        memmove(jobOut, jobIn, 0x100ui64);
        goto $LN1_61;
      }
      v19 = (unsigned int)(v18 + 2);
      v20 = (unsigned int)(v18 + 128);
      do
      {
        jobOut->0 = v4->0;
        *(_OWORD *)jobOut->m_data = *(_OWORD *)v4->m_data;
        *(_OWORD *)&jobOut->m_data[16] = *(_OWORD *)&v4->m_data[16];
        *(_OWORD *)&jobOut->m_data[32] = *(_OWORD *)&v4->m_data[32];
        *(_OWORD *)&jobOut->m_data[48] = *(_OWORD *)&v4->m_data[48];
        *(_OWORD *)&jobOut->m_data[64] = *(_OWORD *)&v4->m_data[64];
        *(_OWORD *)&jobOut->m_data[80] = *(_OWORD *)&v4->m_data[80];
        v21 = *(_OWORD *)&v4->m_data[96];
        jobOut = (hkJobQueue::JobQueueEntry *)((char *)jobOut + v20);
        v4 = (hkJobQueue::JobQueueEntry *)((char *)v4 + v20);
        *(_OWORD *)&jobOut[-1].m_data[224] = v21;
        --v19;
      }
      while ( v19 );
      result = 0;
      break;
    case 4:
    case 0xA:
      v14 = *(_QWORD **)&jobIn->m_data[32];
      if ( !*v14 )
        goto $LN1_61;
      *(_QWORD *)&jobIn->m_data[32] = *v14;
      result = 1;
      break;
    case 7:
    case 9:
      v16 = *(_QWORD *)&jobIn->m_data[32] + 0x4000i64;
      if ( v16 >= *(_QWORD *)&jobIn->m_data[40] )
        goto $LN1_61;
      *(_QWORD *)&jobIn->m_data[32] = v16;
      *(_QWORD *)&jobOut->m_data[40] = v16;
      result = 1;
      break;
    case 8:
      v17 = *(_QWORD *)&jobIn->m_data[48];
      if ( *(_BYTE *)(v17 + 48) )
        goto $LN1_61;
      *(_QWORD *)&jobIn->m_data[48] = *(_QWORD *)v17;
      result = 1;
      break;
    case 0xB:
      v15 = *(_WORD *)&jobIn->m_data[72];
      if ( v15 <= 0x80u )
      {
        if ( !*(_QWORD *)&jobIn->m_data[32] )
          goto $LN1_61;
        jobIn->m_jobSubType = 10;
        result = 1;
      }
      else
      {
        *(_WORD *)&jobIn->m_data[74] += 128;
        *(_WORD *)&jobIn->m_data[72] = v15 - 128;
        *(_WORD *)&jobOut->m_data[72] = 128;
        result = 1;
      }
      break;
    case 0xC:
      result = hkpBroadPhaseJob::popJobTask((hkpBroadPhaseJob *)jobIn, v10, (hkpBroadPhaseJob *)jobOut);
      break;
    default:
$LN1_61:
      result = 0;
      break;
  }
  return result;
}

// File Line: 323
// RVA: 0xD8CA80
signed __int64 __fastcall hkpJobQueueUtils::popCollideJob(hkJobQueue *queue, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntry *jobIn, hkJobQueue::JobQueueEntry *jobOut)
{
  hkJobQueue::JobQueueEntry *v4; // r10
  signed int v5; // ecx
  hkJobQueue::JobQueueEntry *v6; // rax
  hkJob v7; // xmm0
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // cx
  signed __int64 result; // rax
  signed __int64 v11; // rax
  hkJob v12; // xmm0
  unsigned __int16 v13; // ax
  unsigned __int16 v14; // cx

  v4 = jobIn;
  v5 = 16;
  v6 = jobIn;
  do
  {
    v7 = v6->0;
    --v5;
    v6 = (hkJobQueue::JobQueueEntry *)((char *)v6 + 16);
    *(hkJob *)((char *)v6 + (char *)jobOut - (char *)jobIn - 16) = v7;
  }
  while ( v5 > 0 );
  *(_QWORD *)&jobOut->m_data[8] = *(_QWORD *)(*(_QWORD *)(**(_QWORD **)&jobIn->m_data[24] + 64i64)
                                            + 8i64 * *(unsigned __int16 *)jobOut->m_data);
  if ( jobIn->m_jobSubType == 13 )
  {
    v13 = *(_WORD *)&jobIn->m_data[42];
    v14 = *(_WORD *)&jobIn->m_data[44];
    if ( v13 <= v14 )
      return 0i64;
    ++*(_WORD *)&jobIn->m_data[40];
    *(_WORD *)&jobIn->m_data[42] = v13 - v14;
    *(_QWORD *)&jobIn->m_data[48] += 8i64 * v14;
    *(_WORD *)&jobOut->m_data[42] = v14;
    *(_WORD *)&jobOut->m_data[88] = 960;
    result = 1i64;
  }
  else
  {
    if ( jobIn->m_jobSubType != 14 )
    {
      if ( jobIn->m_jobSubType == 15 )
      {
        v8 = *(_WORD *)&jobIn->m_data[42];
        v9 = *(_WORD *)&jobIn->m_data[44];
        if ( v8 > v9 )
        {
          ++*(_WORD *)&jobIn->m_data[40];
          *(_WORD *)&jobIn->m_data[42] = v8 - v9;
          *(_QWORD *)&jobIn->m_data[48] += 8i64 * v9;
          result = 1i64;
          *(_WORD *)&jobOut->m_data[42] = v9;
          return result;
        }
      }
      return 0i64;
    }
    if ( !(((unsigned __int8)jobOut | (unsigned __int8)jobIn) & 0xF) )
    {
      v11 = 2i64;
      do
      {
        v12 = v4->0;
        jobOut = (hkJobQueue::JobQueueEntry *)((char *)jobOut + 128);
        v4 = (hkJobQueue::JobQueueEntry *)((char *)v4 + 128);
        *(hkJob *)&jobOut[-1].m_data[112] = v12;
        *(_OWORD *)&jobOut[-1].m_data[128] = *(_OWORD *)&v4[-1].m_data[128];
        *(_OWORD *)&jobOut[-1].m_data[144] = *(_OWORD *)&v4[-1].m_data[144];
        *(_OWORD *)&jobOut[-1].m_data[160] = *(_OWORD *)&v4[-1].m_data[160];
        *(_OWORD *)&jobOut[-1].m_data[176] = *(_OWORD *)&v4[-1].m_data[176];
        *(_OWORD *)&jobOut[-1].m_data[192] = *(_OWORD *)&v4[-1].m_data[192];
        *(_OWORD *)&jobOut[-1].m_data[208] = *(_OWORD *)&v4[-1].m_data[208];
        *(_OWORD *)&jobOut[-1].m_data[224] = *(_OWORD *)&v4[-1].m_data[224];
        --v11;
      }
      while ( v11 );
      return 0i64;
    }
    memmove(jobOut, jobIn, 0x100ui64);
    result = 0i64;
  }
  return result;
}

// File Line: 387
// RVA: 0xD8CC90
void __fastcall uploadOpenJobsVariable(hkpBuildJacobianTaskHeader *localTaskHeader, hkpBuildJacobianTaskHeader *taskHeaderInMainMemory)
{
  ;
}

// File Line: 396
// RVA: 0xD8CCA0
void __fastcall spawnSplitSimulationIslandJob(hkpDynamicsJob *dynamicsJob, hkpBuildJacobianTaskHeader *localTaskHeader, hkJobQueue *queue, hkJobQueue::DynamicData *data)
{
  unsigned __int16 v4; // ax
  hkpSimulationIsland *v5; // rax
  __int16 v6; // [rsp+20h] [rbp-38h]
  char v7; // [rsp+22h] [rbp-36h]
  __int16 v8; // [rsp+24h] [rbp-34h]
  __int16 v9; // [rsp+26h] [rbp-32h]
  unsigned __int16 v10; // [rsp+30h] [rbp-28h]
  hkpSimulationIsland *v11; // [rsp+38h] [rbp-20h]
  hkpBuildJacobianTaskHeader *v12; // [rsp+40h] [rbp-18h]
  hkpMtThreadStructure *v13; // [rsp+48h] [rbp-10h]

  if ( localTaskHeader->m_splitCheckRequested )
  {
    v8 = 48;
    v9 = -1;
    v4 = dynamicsJob->m_islandIndex;
    v6 = 5;
    v10 = v4;
    v5 = dynamicsJob->m_island;
    v7 = 2;
    v11 = v5;
    v12 = dynamicsJob->m_taskHeader;
    v13 = dynamicsJob->m_mtThreadStructure;
    hkJobQueue::addJobQueueLocked(queue, data, (hkJobQueue::JobQueueEntry *)&v6, 0);
  }
}

// File Line: 405
// RVA: 0xD8CD10
void __fastcall spawnBuildJacobiansJobs(hkpDynamicsJob *dynamicsJob, hkpBuildJacobianTaskHeader *taskHeader, hkJobQueue *queue, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntryInput *newJobCreated)
{
  hkpBuildJacobianTask *v5; // r8
  char v6; // al

  if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
  {
    v5 = taskHeader->m_tasks.m_buildJacobianTasks;
    *(_WORD *)&newJobCreated->m_job.m_jobSubType = 4;
    newJobCreated->m_job.m_jobSpuType.m_storage = 1;
    newJobCreated->m_job.m_size = 80;
    newJobCreated->m_job.m_threadAffinity = -1;
    *(_WORD *)newJobCreated->m_job.m_data = dynamicsJob->m_islandIndex;
    *(_QWORD *)&newJobCreated->m_job.m_data[8] = dynamicsJob->m_island;
    *(_QWORD *)&newJobCreated->m_job.m_data[16] = dynamicsJob->m_taskHeader;
    *(_QWORD *)&newJobCreated->m_job.m_data[24] = dynamicsJob->m_mtThreadStructure;
    *(_QWORD *)&newJobCreated->m_job.m_data[40] = taskHeader->m_constraintQueryIn;
    v6 = taskHeader->m_solveInSingleThread.m_bool;
    *(_QWORD *)&newJobCreated->m_job.m_data[32] = v5;
    newJobCreated->m_job.m_data[48] = v6;
  }
  taskHeader->m_openJobs = taskHeader->m_tasks.m_numBuildJacobianTasks;
  newJobCreated->m_jobPriority.m_storage = 0;
  newJobCreated->m_job.m_jobSpuType.m_storage = 1;
}

// File Line: 448
// RVA: 0xD8C380
__int64 __fastcall hkpJobQueueUtils::finishIntegrateJob(hkJobQueue *queue, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntry *jobIn, hkJobQueue::JobQueueEntryInput *newJobCreated)
{
  __int64 v4; // r10
  unsigned int v5; // ebx
  hkJobQueue::DynamicData *v6; // rsi
  unsigned int v7; // edi
  bool v8; // zf
  __int64 result; // rax
  hkJobQueue::JobQueueEntry *v10; // rdx
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rax
  int v16; // ebx
  hkJobQueue::JobQueueEntry *v17; // rdx
  hkJobQueue::JobQueueEntry *v18; // rdx
  hkJobQueue::JobQueueEntry *v19; // rcx
  int v20; // eax
  int v21; // eax
  __int64 v22; // rax
  int v23; // eax
  __int64 v24; // rcx
  __int64 v25; // rcx
  __int64 v26; // rcx
  __int64 v27; // rax
  __int64 v28; // rcx
  __int16 v29; // [rsp+30h] [rbp-38h]
  char v30; // [rsp+32h] [rbp-36h]
  __int16 v31; // [rsp+34h] [rbp-34h]
  __int16 v32; // [rsp+36h] [rbp-32h]
  __int16 v33; // [rsp+40h] [rbp-28h]
  __int64 v34; // [rsp+48h] [rbp-20h]
  __int64 v35; // [rsp+50h] [rbp-18h]
  __int64 v36; // [rsp+58h] [rbp-10h]

  v4 = *(_QWORD *)&jobIn->m_data[16];
  v5 = 1;
  v6 = data;
  v7 = 1;
  switch ( jobIn->m_jobSubType )
  {
    case 1:
    case 2:
      v8 = (*(_DWORD *)v4)-- == 1;
      if ( !v8 )
        goto $noJobCreated;
      if ( *(_DWORD *)(v4 + 176) <= 0 )
      {
        spawnBuildJacobiansJobs((hkpDynamicsJob *)jobIn, (hkpBuildJacobianTaskHeader *)v4, queue, data, newJobCreated);
        result = 0i64;
      }
      else
      {
        if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
        {
          *(_WORD *)&newJobCreated->m_job.m_jobSubType = 3;
          newJobCreated->m_job.m_jobSpuType.m_storage = 2;
          newJobCreated->m_job.m_size = 48;
          newJobCreated->m_job.m_threadAffinity = -1;
          *(_WORD *)newJobCreated->m_job.m_data = *(_WORD *)jobIn->m_data;
          *(_QWORD *)&newJobCreated->m_job.m_data[8] = *(_QWORD *)&jobIn->m_data[8];
          *(_QWORD *)&newJobCreated->m_job.m_data[16] = *(_QWORD *)&jobIn->m_data[16];
          *(_QWORD *)&newJobCreated->m_job.m_data[24] = *(_QWORD *)&jobIn->m_data[24];
        }
        newJobCreated->m_jobPriority.m_storage = 0;
        result = 0i64;
      }
      return result;
    case 3:
      spawnBuildJacobiansJobs((hkpDynamicsJob *)jobIn, (hkpBuildJacobianTaskHeader *)v4, queue, data, newJobCreated);
      return 0i64;
    case 4:
      v8 = (*(_DWORD *)v4)-- == 1;
      if ( !v8 )
        goto $noJobCreated;
      v10 = &newJobCreated->m_job;
      if ( *(_BYTE *)(v4 + 132) )
      {
        if ( newJobCreated == (hkJobQueue::JobQueueEntryInput *)-16i64 )
        {
          v10 = 0i64;
        }
        else
        {
          *(_WORD *)&v10->m_jobSubType = 6;
          newJobCreated->m_job.m_jobSpuType.m_storage = 1;
          newJobCreated->m_job.m_threadAffinity = -1;
          newJobCreated->m_job.m_size = 80;
          *(_WORD *)newJobCreated->m_job.m_data = *(_WORD *)jobIn->m_data;
          *(_QWORD *)&newJobCreated->m_job.m_data[8] = *(_QWORD *)&jobIn->m_data[8];
          *(_QWORD *)&newJobCreated->m_job.m_data[16] = *(_QWORD *)&jobIn->m_data[16];
          *(_QWORD *)&newJobCreated->m_job.m_data[24] = *(_QWORD *)&jobIn->m_data[24];
          v11 = *(_QWORD *)(v4 + 24);
          *(_QWORD *)&newJobCreated->m_job.m_data[32] = v11;
          *(_DWORD *)&newJobCreated->m_job.m_data[44] = *(_DWORD *)(v4 + 64) - v11;
          *(_DWORD *)&newJobCreated->m_job.m_data[48] = *(_DWORD *)(v4 + 88) - v11;
          *(_DWORD *)&newJobCreated->m_job.m_data[52] = *(_DWORD *)(v4 + 96) - v11;
          *(_DWORD *)&newJobCreated->m_job.m_data[40] = *(_DWORD *)(v4 + 32);
          *(_DWORD *)&newJobCreated->m_job.m_data[56] = *(_DWORD *)(v4 + 104);
          *(_DWORD *)&newJobCreated->m_job.m_data[60] = *(_DWORD *)(v4 + 108);
        }
        newJobCreated->m_jobPriority.m_storage = 0;
        newJobCreated->m_job.m_jobSpuType.m_storage = (*(_BYTE *)(v4 + 133) != 0) + 1;
      }
      else
      {
        if ( newJobCreated == (hkJobQueue::JobQueueEntryInput *)-16i64 )
        {
          v10 = 0i64;
        }
        else
        {
          *(_WORD *)&v10->m_jobSubType = 7;
          newJobCreated->m_job.m_jobSpuType.m_storage = 1;
          newJobCreated->m_job.m_threadAffinity = -1;
          newJobCreated->m_job.m_size = 64;
          *(_WORD *)newJobCreated->m_job.m_data = *(_WORD *)jobIn->m_data;
          *(_QWORD *)&newJobCreated->m_job.m_data[8] = *(_QWORD *)&jobIn->m_data[8];
          *(_QWORD *)&newJobCreated->m_job.m_data[16] = *(_QWORD *)&jobIn->m_data[16];
          *(_QWORD *)&newJobCreated->m_job.m_data[24] = *(_QWORD *)&jobIn->m_data[24];
          *(_QWORD *)&newJobCreated->m_job.m_data[32] = *(_QWORD *)(v4 + 64);
          *(_QWORD *)&newJobCreated->m_job.m_data[40] = *(_QWORD *)(v4 + 72);
        }
        newJobCreated->m_jobPriority.m_storage = 0;
        newJobCreated->m_job.m_jobSpuType.m_storage = 1;
        *(_DWORD *)v4 = *(unsigned __int16 *)(v4 + 80);
      }
      if ( !*(_BYTE *)(v4 + 41) )
        goto $yesJobCreated;
      v31 = 48;
      v33 = *(_WORD *)v10->m_data;
      v12 = *(_QWORD *)&v10->m_data[8];
      v29 = 5;
      v34 = v12;
      v13 = *(_QWORD *)&v10->m_data[16];
      v30 = 2;
      v35 = v13;
      v36 = *(_QWORD *)&v10->m_data[24];
      v32 = -1;
      hkJobQueue::addJobQueueLocked(queue, v6, (hkJobQueue::JobQueueEntry *)&v29, 0);
      return 0i64;
    case 5:
      goto $commonForIntegrateMotinoAndSplitIsland;
    case 6:
      goto $LN33_31;
    case 7:
      v8 = (*(_DWORD *)v4)-- == 1;
      if ( !v8 )
        goto $noJobCreated;
      if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
      {
        *(_WORD *)&newJobCreated->m_job.m_jobSubType = 8;
        newJobCreated->m_job.m_jobSpuType.m_storage = 1;
        newJobCreated->m_job.m_size = 80;
        newJobCreated->m_job.m_threadAffinity = -1;
        *(_WORD *)newJobCreated->m_job.m_data = *(_WORD *)jobIn->m_data;
        *(_QWORD *)&newJobCreated->m_job.m_data[8] = *(_QWORD *)&jobIn->m_data[8];
        *(_QWORD *)&newJobCreated->m_job.m_data[16] = *(_QWORD *)&jobIn->m_data[16];
        *(_QWORD *)&newJobCreated->m_job.m_data[24] = *(_QWORD *)&jobIn->m_data[24];
        v14 = *(_QWORD *)(v4 + 184);
        *(_DWORD *)&newJobCreated->m_job.m_data[32] = 0;
        *(_QWORD *)&newJobCreated->m_job.m_data[48] = v14;
        *(_DWORD *)&newJobCreated->m_job.m_data[40] = 0;
      }
      newJobCreated->m_jobPriority.m_storage = 0;
      newJobCreated->m_job.m_jobSpuType.m_storage = 1;
      *(_DWORD *)v4 = *(unsigned __int16 *)(v4 + 192);
      return 0i64;
    case 8:
      v8 = (*(_DWORD *)v4)-- == 1;
      if ( v8 )
      {
        v15 = *(_QWORD *)&jobIn->m_data[48];
        v16 = *(unsigned __int16 *)(v15 + 50);
        if ( *(_WORD *)(v15 + 50) )
        {
          v17 = &newJobCreated->m_job;
          if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
          {
            *(_WORD *)&v17->m_jobSubType = 8;
            newJobCreated->m_job.m_jobSpuType.m_storage = 1;
            newJobCreated->m_job.m_size = 80;
            newJobCreated->m_job.m_threadAffinity = -1;
            *(_WORD *)newJobCreated->m_job.m_data = *(_WORD *)jobIn->m_data;
            *(_QWORD *)&newJobCreated->m_job.m_data[8] = *(_QWORD *)&jobIn->m_data[8];
            *(_QWORD *)&newJobCreated->m_job.m_data[16] = *(_QWORD *)&jobIn->m_data[16];
            *(_QWORD *)&newJobCreated->m_job.m_data[24] = *(_QWORD *)&jobIn->m_data[24];
            v17->0 = jobIn->0;
            *(_OWORD *)newJobCreated->m_job.m_data = *(_OWORD *)jobIn->m_data;
            *(_OWORD *)&newJobCreated->m_job.m_data[16] = *(_OWORD *)&jobIn->m_data[16];
            *(_OWORD *)&newJobCreated->m_job.m_data[32] = *(_OWORD *)&jobIn->m_data[32];
            *(_OWORD *)&newJobCreated->m_job.m_data[48] = *(_OWORD *)&jobIn->m_data[48];
            *(_QWORD *)&newJobCreated->m_job.m_data[48] = *(_QWORD *)(*(_QWORD *)&jobIn->m_data[48] + 56i64);
          }
        }
        else if ( (unsigned int)(*(_DWORD *)&jobIn->m_data[40] + 1) >= *(_DWORD *)&jobIn->m_data[36] )
        {
          if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
          {
            *(_WORD *)&newJobCreated->m_job.m_jobSubType = 9;
            newJobCreated->m_job.m_jobSpuType.m_storage = 1;
            newJobCreated->m_job.m_size = 80;
            newJobCreated->m_job.m_threadAffinity = -1;
            *(_WORD *)newJobCreated->m_job.m_data = *(_WORD *)jobIn->m_data;
            *(_QWORD *)&newJobCreated->m_job.m_data[8] = *(_QWORD *)&jobIn->m_data[8];
            *(_QWORD *)&newJobCreated->m_job.m_data[16] = *(_QWORD *)&jobIn->m_data[16];
            *(_QWORD *)&newJobCreated->m_job.m_data[24] = *(_QWORD *)&jobIn->m_data[24];
            *(_QWORD *)&newJobCreated->m_job.m_data[32] = *(_QWORD *)(v4 + 64);
            *(_QWORD *)&newJobCreated->m_job.m_data[40] = *(_QWORD *)(v4 + 72);
            *(_DWORD *)&newJobCreated->m_job.m_data[48] = *(_DWORD *)&jobIn->m_data[32];
            newJobCreated->m_job.m_data[52] = 0;
          }
          v16 = *(unsigned __int16 *)(v4 + 82);
        }
        else
        {
          v18 = &newJobCreated->m_job;
          if ( newJobCreated == (hkJobQueue::JobQueueEntryInput *)-16i64 )
          {
            v18 = 0i64;
          }
          else
          {
            *(_WORD *)&v18->m_jobSubType = 8;
            newJobCreated->m_job.m_jobSpuType.m_storage = 1;
            newJobCreated->m_job.m_size = 80;
            newJobCreated->m_job.m_threadAffinity = -1;
            *(_WORD *)newJobCreated->m_job.m_data = *(_WORD *)jobIn->m_data;
            *(_QWORD *)&newJobCreated->m_job.m_data[8] = *(_QWORD *)&jobIn->m_data[8];
            *(_QWORD *)&newJobCreated->m_job.m_data[16] = *(_QWORD *)&jobIn->m_data[16];
            *(_QWORD *)&newJobCreated->m_job.m_data[24] = *(_QWORD *)&jobIn->m_data[24];
            v18->0 = jobIn->0;
            *(_OWORD *)newJobCreated->m_job.m_data = *(_OWORD *)jobIn->m_data;
            *(_OWORD *)&newJobCreated->m_job.m_data[16] = *(_OWORD *)&jobIn->m_data[16];
            *(_OWORD *)&newJobCreated->m_job.m_data[32] = *(_OWORD *)&jobIn->m_data[32];
            *(_OWORD *)&newJobCreated->m_job.m_data[48] = *(_OWORD *)&jobIn->m_data[48];
            *(_QWORD *)&newJobCreated->m_job.m_data[48] = *(_QWORD *)(*(_QWORD *)&jobIn->m_data[48] + 56i64);
          }
          ++*(_DWORD *)&v18->m_data[40];
          *(_QWORD *)&v18->m_data[48] = *(_QWORD *)(v4 + 184);
          v16 = *(unsigned __int16 *)(v4 + 192);
        }
        newJobCreated->m_jobPriority.m_storage = 0;
        newJobCreated->m_job.m_jobSpuType.m_storage = 1;
        *(_DWORD *)v4 = v16;
        v5 = 0;
      }
      goto $noJobCreated;
    case 9:
      v8 = (*(_DWORD *)v4)-- == 1;
      if ( !v8 )
        goto $noJobCreated;
      v19 = &newJobCreated->m_job;
      if ( jobIn->m_data[52] )
      {
        if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
        {
          *(_WORD *)&v19->m_jobSubType = 11;
          newJobCreated->m_job.m_jobSpuType.m_storage = 2;
          newJobCreated->m_job.m_size = 112;
          newJobCreated->m_job.m_threadAffinity = -1;
          *(_WORD *)newJobCreated->m_job.m_data = *(_WORD *)jobIn->m_data;
          *(_QWORD *)&newJobCreated->m_job.m_data[8] = *(_QWORD *)&jobIn->m_data[8];
          *(_QWORD *)&newJobCreated->m_job.m_data[16] = *(_QWORD *)&jobIn->m_data[16];
          *(_QWORD *)&newJobCreated->m_job.m_data[24] = *(_QWORD *)&jobIn->m_data[24];
          v22 = *(_QWORD *)(v4 + 184);
          *(_WORD *)&newJobCreated->m_job.m_data[74] = 0;
          *(_QWORD *)&newJobCreated->m_job.m_data[32] = v22;
          *(_WORD *)&newJobCreated->m_job.m_data[72] = *(_WORD *)(v4 + 128);
          *(_QWORD *)&newJobCreated->m_job.m_data[64] = *(_QWORD *)(v4 + 24);
          newJobCreated->m_job.m_data[80] = 0;
        }
        v23 = *(_DWORD *)(v4 + 160);
        newJobCreated->m_jobPriority.m_storage = 0;
        newJobCreated->m_job.m_jobSpuType.m_storage = 1;
        *(_DWORD *)v4 = v23;
$yesJobCreated:
        result = 0i64;
      }
      else
      {
        if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
        {
          *(_WORD *)&v19->m_jobSubType = 8;
          newJobCreated->m_job.m_jobSpuType.m_storage = 1;
          newJobCreated->m_job.m_size = 80;
          newJobCreated->m_job.m_threadAffinity = -1;
          *(_WORD *)newJobCreated->m_job.m_data = *(_WORD *)jobIn->m_data;
          *(_QWORD *)&newJobCreated->m_job.m_data[8] = *(_QWORD *)&jobIn->m_data[8];
          *(_QWORD *)&newJobCreated->m_job.m_data[16] = *(_QWORD *)&jobIn->m_data[16];
          *(_QWORD *)&newJobCreated->m_job.m_data[24] = *(_QWORD *)&jobIn->m_data[24];
          *(_QWORD *)&newJobCreated->m_job.m_data[48] = *(_QWORD *)(v4 + 184);
          v20 = *(_DWORD *)&jobIn->m_data[48];
          *(_DWORD *)&newJobCreated->m_job.m_data[40] = 0;
          *(_DWORD *)&newJobCreated->m_job.m_data[32] = v20 + 1;
        }
        v21 = *(unsigned __int16 *)(v4 + 192);
        newJobCreated->m_jobPriority.m_storage = 0;
        newJobCreated->m_job.m_jobSpuType.m_storage = 1;
        *(_DWORD *)v4 = v21;
        result = 0i64;
      }
      return result;
    case 0xA:
      --*(_DWORD *)v4;
      v24 = *(_QWORD *)(*(_QWORD *)&jobIn->m_data[32] + 24i64);
      if ( *(_DWORD *)v24 )
      {
        *(_QWORD *)(v24 + 8) = *(_QWORD *)(v4 + 48);
        *(_QWORD *)(v4 + 48) = v24;
      }
      if ( !*(_DWORD *)v4 )
$LN33_31:
        *(_BYTE *)(v4 + 40) = 1;
      goto $noJobCreated;
    case 0xB:
      if ( *(_DWORD *)&jobIn->m_data[76] <= 5 )
        *(_DWORD *)(v4 + 8) = 0;
      v7 = (((unsigned int)*(unsigned __int16 *)&jobIn->m_data[72] - 1) >> 7) + 1;
$commonForIntegrateMotinoAndSplitIsland:
      v25 = *(_QWORD *)&jobIn->m_data[16];
      v8 = *(_DWORD *)(v25 + 4) == v7;
      *(_DWORD *)(v25 + 4) -= v7;
      if ( !v8 )
        goto $noJobCreated;
      if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
      {
        v26 = *(_QWORD *)&jobIn->m_data[16];
        *(_WORD *)&newJobCreated->m_job.m_jobSubType = 12;
        newJobCreated->m_job.m_jobSpuType.m_storage = 2;
        newJobCreated->m_job.m_size = 64;
        newJobCreated->m_job.m_threadAffinity = -1;
        *(_WORD *)newJobCreated->m_job.m_data = *(_WORD *)jobIn->m_data;
        *(_QWORD *)&newJobCreated->m_job.m_data[8] = *(_QWORD *)&jobIn->m_data[8];
        *(_QWORD *)&newJobCreated->m_job.m_data[16] = *(_QWORD *)&jobIn->m_data[16];
        v27 = *(_QWORD *)&jobIn->m_data[24];
        *(_QWORD *)&newJobCreated->m_job.m_data[16] = v26;
        *(_QWORD *)&newJobCreated->m_job.m_data[24] = v27;
        *(_WORD *)&newJobCreated->m_job.m_data[32] = 1;
      }
      newJobCreated->m_jobPriority.m_storage = 0;
      return 0i64;
    case 0xD:
      v28 = *(_QWORD *)&jobIn->m_data[32];
      if ( !v28 )
        goto $noJobCreated;
      v8 = (*(_DWORD *)(v28 + 4))-- == 1;
      if ( !v8 )
        goto $noJobCreated;
      if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
      {
        *(_WORD *)&newJobCreated->m_job.m_jobSubType = 14;
        newJobCreated->m_job.m_jobSpuType.m_storage = 2;
        newJobCreated->m_job.m_size = 64;
        newJobCreated->m_job.m_threadAffinity = -1;
        *(_WORD *)newJobCreated->m_job.m_data = *(_WORD *)jobIn->m_data;
        *(_QWORD *)&newJobCreated->m_job.m_data[8] = *(_QWORD *)&jobIn->m_data[8];
        *(_QWORD *)&newJobCreated->m_job.m_data[16] = *(_QWORD *)&jobIn->m_data[16];
        *(_QWORD *)&newJobCreated->m_job.m_data[24] = *(_QWORD *)&jobIn->m_data[24];
        *(_WORD *)newJobCreated->m_job.m_data = *(_WORD *)jobIn->m_data;
        *(_QWORD *)&newJobCreated->m_job.m_data[32] = *(_QWORD *)&jobIn->m_data[32];
      }
      newJobCreated->m_jobPriority.m_storage = 0;
      result = 0i64;
      break;
    default:
$noJobCreated:
      result = v5;
      break;
  }
  return result;
}WORD *)&jobIn->m_data[24];
        *(_WORD *)newJobCreated->m_job.m_data = *(_WORD *)jobIn->m_data;
        *(_QWORD *)&newJobCreated->m_job.m_data[32] = *(_QWORD *)&jobIn->m_data[32];
      }
      newJobCreated->m_jobPriority.m_storage = 0;
      result = 0i64;
      break;
    default:
$noJobCreated:
      res

// File Line: 847
// RVA: 0xD8CC00
signed __int64 __fastcall hkpJobQueueUtils::finishCollideJob(hkJobQueue *queue, hkJobQueue::DynamicData *data, hkJobQueue::JobQueueEntry *jobIn, hkJobQueue::JobQueueEntryInput *newJobCreated)
{
  __int64 v5; // rcx
  bool v6; // zf

  if ( jobIn->m_jobSubType != 13 )
    return 1i64;
  v5 = *(_QWORD *)&jobIn->m_data[32];
  if ( !v5 )
    return 1i64;
  v6 = (*(_DWORD *)(v5 + 4))-- == 1;
  if ( !v6 )
    return 1i64;
  if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
  {
    *(_WORD *)&newJobCreated->m_job.m_jobSubType = 14;
    newJobCreated->m_job.m_jobSpuType.m_storage = 2;
    newJobCreated->m_job.m_size = 64;
    newJobCreated->m_job.m_threadAffinity = -1;
    *(_WORD *)newJobCreated->m_job.m_data = *(_WORD *)jobIn->m_data;
    *(_QWORD *)&newJobCreated->m_job.m_data[8] = *(_QWORD *)&jobIn->m_data[8];
    *(_QWORD *)&newJobCreated->m_job.m_data[16] = *(_QWORD *)&jobIn->m_data[16];
    *(_QWORD *)&newJobCreated->m_job.m_data[24] = *(_QWORD *)&jobIn->m_data[24];
    *(_WORD *)newJobCreated->m_job.m_data = *(_WORD *)jobIn->m_data;
    *(_QWORD *)&newJobCreated->m_job.m_data[32] = *(_QWORD *)&jobIn->m_data[32];
  }
  newJobCreated->m_jobPriority.m_storage = 0;
  return 0i64;
}

