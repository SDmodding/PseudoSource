// File Line: 118
// RVA: 0xD8BFC0
hkpAgentSectorHeader *__fastcall hkpAgentSectorHeader::allocate(unsigned int numTasks, int numAgentNnEntriesPerTask)
{
  __int64 v2; // rdi
  _QWORD **Value; // rax
  hkpAgentSectorHeader *result; // rax
  int v6; // esi
  hkpAgentSectorHeader *v7; // r14
  hkpAgentSectorHeader *v8; // rbx
  _QWORD **v9; // rax
  _DWORD *v10; // rax

  v2 = numTasks;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkpAgentSectorHeader *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*Value[11] + 8i64))(
                                     Value[11],
                                     (unsigned int)(8 * (__int16)v2 + 32));
  v6 = 32 * numAgentNnEntriesPerTask;
  v7 = result;
  result->m_openJobs = v2;
  result->m_numTotalTasks = v2;
  v8 = result + 1;
  result->m_sizeOfJobInfo = v6 + 32;
  if ( (int)v2 > 0 )
  {
    do
    {
      v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v10 = (_DWORD *)(*(__int64 (__fastcall **)(_QWORD *, _QWORD))(*v9[11] + 8i64))(v9[11], (unsigned int)(v6 + 32));
      *(_QWORD *)&v8->m_numTotalTasks = v10;
      if ( v10 )
      {
        v10[4] = 16;
        v10[5] = 0;
        v10[6] = v6;
      }
      v8 = (hkpAgentSectorHeader *)((char *)v8 + 8);
      --v2;
    }
    while ( v2 );
    return v7;
  }
  return result;
}

// File Line: 156
// RVA: 0xD8C080
void __fastcall hkpAgentSectorHeader::deallocate(hkpAgentSectorHeader *this)
{
  int v1; // ebp
  hkpAgentSectorHeader *i; // r14
  unsigned int m_sizeOfJobInfo; // ebx
  __int64 v5; // rdi
  _QWORD **Value; // rax
  unsigned int v7; // ebx
  _QWORD **v8; // rax

  v1 = 0;
  for ( i = this + 1; v1 < this->m_numTotalTasks; i = (hkpAgentSectorHeader *)((char *)i + 8) )
  {
    m_sizeOfJobInfo = this->m_sizeOfJobInfo;
    v5 = *(_QWORD *)&i->m_numTotalTasks;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, __int64, _QWORD))(*Value[11] + 16i64))(Value[11], v5, m_sizeOfJobInfo);
    ++v1;
  }
  v7 = 8 * SLOWORD(this->m_numTotalTasks) + 32;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  (*(void (__fastcall **)(_QWORD *, hkpAgentSectorHeader *, _QWORD))(*v8[11] + 16i64))(v8[11], this, v7);
}

// File Line: 186
// RVA: 0xD8C130
hkJobQueue::JobPopFuncResult __fastcall hkpJobQueueUtils::popIntegrateJob(
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkpBroadPhaseJob *jobIn,
        hkpBroadPhaseJob *jobOut)
{
  hkJobQueue::JobQueueEntry *v4; // r10
  int v5; // ecx
  hkpBroadPhaseJob *v6; // rax
  hkJob v7; // xmm0
  hkpWorld *m_world; // rdx
  hkpSimulationIsland *v9; // rcx
  hkArray<hkpSimulationIsland *,hkContainerHeapAllocator> *p_m_activeSimulationIslands; // rdx
  int v11; // eax
  hkJobQueue::JobPopFuncResult result; // eax
  unsigned __int16 v13; // cx
  _QWORD *v14; // rax
  unsigned __int16 m_island; // cx
  unsigned __int64 v16; // rax
  __int64 v17; // rax
  int v18; // eax
  __int64 v19; // rcx
  __int64 v20; // rax
  __int128 v21; // xmm1

  v4 = (hkJobQueue::JobQueueEntry *)jobIn;
  v5 = 16;
  v6 = jobIn;
  do
  {
    v7 = v6->hkJob;
    --v5;
    v6 = (hkpBroadPhaseJob *)((char *)v6 + 16);
    *(hkJob *)((char *)v6 + (char *)jobOut - (char *)jobIn - 16) = v7;
  }
  while ( v5 > 0 );
  m_world = jobIn->m_mtThreadStructure->m_world;
  v9 = m_world->m_activeSimulationIslands.m_data[jobOut->m_islandIndex];
  p_m_activeSimulationIslands = &m_world->m_activeSimulationIslands;
  jobOut->m_island = v9;
  switch ( jobIn->m_jobSubType )
  {
    case 0:
      v11 = *(_DWORD *)&jobIn->m_numIslands;
      if ( v11 <= 1 )
        goto $LN1_61;
      ++jobIn->m_islandIndex;
      *(_DWORD *)&jobIn->m_numIslands = v11 - 1;
      result = DO_NOT_POP_QUEUE_ENTRY;
      *(_DWORD *)&jobOut->m_numIslands = 1;
      break;
    case 1:
      v13 = *(&jobIn->m_numIslands + 5);
      if ( v13 <= 0x80u )
        goto $LN1_61;
      *(&jobIn->m_numIslands + 4) += 128;
      *(&jobIn->m_numIslands + 5) = v13 - 128;
      *(&jobOut->m_numIslands + 5) = 128;
      result = DO_NOT_POP_QUEUE_ENTRY;
      break;
    case 3:
    case 6:
    case 0xE:
      v18 = ((unsigned __int8)jobOut | (unsigned __int8)jobIn) & 0xF;
      if ( (((unsigned __int8)jobOut | (unsigned __int8)jobIn) & 0xF) != 0 )
      {
        memmove(jobOut, jobIn, 0x100ui64);
        goto $LN1_61;
      }
      v19 = (unsigned int)(v18 + 2);
      v20 = (unsigned int)(v18 + 128);
      do
      {
        jobOut->hkJob = v4->hkJob;
        *(_OWORD *)&jobOut->m_islandIndex = *(_OWORD *)v4->m_data;
        *(_OWORD *)&jobOut->m_taskHeader = *(_OWORD *)&v4->m_data[16];
        *(_OWORD *)&jobOut->m_numIslands = *(_OWORD *)&v4->m_data[32];
        jobOut[1].hkJob = *(hkJob *)&v4->m_data[48];
        *(_OWORD *)&jobOut[1].m_islandIndex = *(_OWORD *)&v4->m_data[64];
        *(_OWORD *)&jobOut[1].m_taskHeader = *(_OWORD *)&v4->m_data[80];
        v21 = *(_OWORD *)&v4->m_data[96];
        jobOut = (hkpBroadPhaseJob *)((char *)jobOut + v20);
        v4 = (hkJobQueue::JobQueueEntry *)((char *)v4 + v20);
        *(_OWORD *)&jobOut[-1].m_numIslands = v21;
        --v19;
      }
      while ( v19 );
      result = POP_QUEUE_ENTRY;
      break;
    case 4:
    case 0xA:
      v14 = *(_QWORD **)&jobIn->m_numIslands;
      if ( !*v14 )
        goto $LN1_61;
      *(_QWORD *)&jobIn->m_numIslands = *v14;
      result = DO_NOT_POP_QUEUE_ENTRY;
      break;
    case 7:
    case 9:
      v16 = *(_QWORD *)&jobIn->m_numIslands + 0x4000i64;
      if ( v16 >= *((_QWORD *)&jobIn->m_numIslands + 1) )
        goto $LN1_61;
      *(_QWORD *)&jobIn->m_numIslands = v16;
      *((_QWORD *)&jobOut->m_numIslands + 1) = v16;
      result = DO_NOT_POP_QUEUE_ENTRY;
      break;
    case 8:
      v17 = *(_QWORD *)&jobIn[1].m_jobSubType;
      if ( *(_BYTE *)(v17 + 48) )
        goto $LN1_61;
      *(_QWORD *)&jobIn[1].m_jobSubType = *(_QWORD *)v17;
      result = DO_NOT_POP_QUEUE_ENTRY;
      break;
    case 0xB:
      m_island = (unsigned __int16)jobIn[1].m_island;
      if ( m_island <= 0x80u )
      {
        if ( !*(_QWORD *)&jobIn->m_numIslands )
          goto $LN1_61;
        jobIn->m_jobSubType = 10;
        result = DO_NOT_POP_QUEUE_ENTRY;
      }
      else
      {
        WORD1(jobIn[1].m_island) += 128;
        LOWORD(jobIn[1].m_island) = m_island - 128;
        LOWORD(jobOut[1].m_island) = 128;
        result = DO_NOT_POP_QUEUE_ENTRY;
      }
      break;
    case 0xC:
      result = hkpBroadPhaseJob::popJobTask(jobIn, p_m_activeSimulationIslands, jobOut);
      break;
    default:
$LN1_61:
      result = POP_QUEUE_ENTRY;
      break;
  }
  return result;
}

// File Line: 323
// RVA: 0xD8CA80
__int64 __fastcall hkpJobQueueUtils::popCollideJob(
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkJobQueue::JobQueueEntry *jobIn,
        hkJobQueue::JobQueueEntry *jobOut)
{
  hkJobQueue::JobQueueEntry *v4; // r10
  int v5; // ecx
  hkJobQueue::JobQueueEntry *v6; // rax
  hkJob v7; // xmm0
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // cx
  __int64 result; // rax
  __int64 v11; // rax
  hkJob v12; // xmm0
  unsigned __int16 v13; // ax
  unsigned __int16 v14; // cx

  v4 = jobIn;
  v5 = 16;
  v6 = jobIn;
  do
  {
    v7 = v6->hkJob;
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
    return 1i64;
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
    if ( (((unsigned __int8)jobOut | (unsigned __int8)jobIn) & 0xF) == 0 )
    {
      v11 = 2i64;
      do
      {
        v12 = v4->hkJob;
        jobOut = (hkJobQueue::JobQueueEntry *)((char *)jobOut + 128);
        v4 = (hkJobQueue::JobQueueEntry *)((char *)v4 + 128);
        *((hkJob *)jobOut - 8) = v12;
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
    return 0i64;
  }
}

// File Line: 387
// RVA: 0xD8CC90
void __fastcall uploadOpenJobsVariable(
        hkpBuildJacobianTaskHeader *localTaskHeader,
        hkpBuildJacobianTaskHeader *taskHeaderInMainMemory)
{
  ;
}

// File Line: 396
// RVA: 0xD8CCA0
void __fastcall spawnSplitSimulationIslandJob(
        hkpDynamicsJob *dynamicsJob,
        hkpBuildJacobianTaskHeader *localTaskHeader,
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data)
{
  unsigned __int16 m_islandIndex; // ax
  hkpSimulationIsland *m_island; // rax
  __int16 v6; // [rsp+20h] [rbp-38h] BYREF
  char v7; // [rsp+22h] [rbp-36h]
  __int16 v8; // [rsp+24h] [rbp-34h]
  __int16 v9; // [rsp+26h] [rbp-32h]
  unsigned __int16 v10; // [rsp+30h] [rbp-28h]
  hkpSimulationIsland *v11; // [rsp+38h] [rbp-20h]
  hkpBuildJacobianTaskHeader *m_taskHeader; // [rsp+40h] [rbp-18h]
  hkpMtThreadStructure *m_mtThreadStructure; // [rsp+48h] [rbp-10h]

  if ( localTaskHeader->m_splitCheckRequested )
  {
    v8 = 48;
    v9 = -1;
    m_islandIndex = dynamicsJob->m_islandIndex;
    v6 = 5;
    v10 = m_islandIndex;
    m_island = dynamicsJob->m_island;
    v7 = 2;
    v11 = m_island;
    m_taskHeader = dynamicsJob->m_taskHeader;
    m_mtThreadStructure = dynamicsJob->m_mtThreadStructure;
    hkJobQueue::addJobQueueLocked(queue, data, (hkJobQueue::JobQueueEntry *)&v6, JOB_HIGH_PRIORITY);
  }
}

// File Line: 405
// RVA: 0xD8CD10
void __fastcall spawnBuildJacobiansJobs(
        hkpDynamicsJob *dynamicsJob,
        hkpBuildJacobianTaskHeader *taskHeader,
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkJobQueue::JobQueueEntryInput *newJobCreated)
{
  hkpBuildJacobianTask *m_buildJacobianTasks; // r8
  char m_bool; // al

  if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
  {
    m_buildJacobianTasks = taskHeader->m_tasks.m_buildJacobianTasks;
    *(_WORD *)&newJobCreated->m_job.m_jobSubType = 4;
    newJobCreated->m_job.m_jobSpuType.m_storage = 1;
    newJobCreated->m_job.m_size = 80;
    newJobCreated->m_job.m_threadAffinity = -1;
    *(_WORD *)newJobCreated->m_job.m_data = dynamicsJob->m_islandIndex;
    *(_QWORD *)&newJobCreated->m_job.m_data[8] = dynamicsJob->m_island;
    *(_QWORD *)&newJobCreated->m_job.m_data[16] = dynamicsJob->m_taskHeader;
    *(_QWORD *)&newJobCreated->m_job.m_data[24] = dynamicsJob->m_mtThreadStructure;
    *(_QWORD *)&newJobCreated->m_job.m_data[40] = taskHeader->m_constraintQueryIn;
    m_bool = taskHeader->m_solveInSingleThread.m_bool;
    *(_QWORD *)&newJobCreated->m_job.m_data[32] = m_buildJacobianTasks;
    newJobCreated->m_job.m_data[48] = m_bool;
  }
  taskHeader->m_openJobs = taskHeader->m_tasks.m_numBuildJacobianTasks;
  newJobCreated->m_jobPriority.m_storage = 0;
  newJobCreated->m_job.m_jobSpuType.m_storage = 1;
}

// File Line: 448
// RVA: 0xD8C380
__int64 __fastcall hkpJobQueueUtils::finishIntegrateJob(
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkpDynamicsJob *jobIn,
        hkJobQueue::JobQueueEntryInput *newJobCreated)
{
  hkpBuildJacobianTaskHeader *m_taskHeader; // r10
  unsigned int v5; // ebx
  unsigned int v7; // edi
  bool v8; // zf
  __int64 result; // rax
  hkJobQueue::JobQueueEntry *p_m_job; // rdx
  void *m_buffer; // rax
  __int64 v12; // rax
  __int64 v13; // rax
  hkpSolveConstraintBatchTask *m_firstSolveJacobiansTask; // rax
  __int64 v15; // rax
  int m_numIntegrateVelocitiesJobs; // ebx
  hkJobQueue::JobQueueEntry *v17; // rdx
  hkJobQueue::JobQueueEntry *v18; // rdx
  hkJobQueue::JobQueueEntry *v19; // rcx
  int v20; // eax
  int m_firstBatchSize; // eax
  hkpSolveConstraintBatchTask *v22; // rax
  int m_numBuildJacobianTasks; // eax
  hkpImpulseLimitBreachedHeader *v24; // rcx
  hkpBuildJacobianTaskHeader *v25; // rcx
  hkpBuildJacobianTaskHeader *v26; // rcx
  hkpMtThreadStructure *m_mtThreadStructure; // rax
  __int64 v28; // rcx
  __int16 v29; // [rsp+30h] [rbp-38h] BYREF
  char v30; // [rsp+32h] [rbp-36h]
  __int16 v31; // [rsp+34h] [rbp-34h]
  __int16 v32; // [rsp+36h] [rbp-32h]
  __int16 v33; // [rsp+40h] [rbp-28h]
  __int64 v34; // [rsp+48h] [rbp-20h]
  __int64 v35; // [rsp+50h] [rbp-18h]
  __int64 v36; // [rsp+58h] [rbp-10h]

  m_taskHeader = jobIn->m_taskHeader;
  v5 = 1;
  v7 = 1;
  switch ( jobIn->m_jobSubType )
  {
    case 1:
    case 2:
      v8 = m_taskHeader->m_openJobs-- == 1;
      if ( !v8 )
        goto $noJobCreated;
      if ( m_taskHeader->m_tasks.m_numCallbackConstraints <= 0 )
        goto LABEL_7;
      if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
      {
        *(_WORD *)&newJobCreated->m_job.m_jobSubType = 3;
        newJobCreated->m_job.m_jobSpuType.m_storage = 2;
        newJobCreated->m_job.m_size = 48;
        newJobCreated->m_job.m_threadAffinity = -1;
        *(_WORD *)newJobCreated->m_job.m_data = jobIn->m_islandIndex;
        *(_QWORD *)&newJobCreated->m_job.m_data[8] = jobIn->m_island;
        *(_QWORD *)&newJobCreated->m_job.m_data[16] = jobIn->m_taskHeader;
        *(_QWORD *)&newJobCreated->m_job.m_data[24] = jobIn->m_mtThreadStructure;
      }
      newJobCreated->m_jobPriority.m_storage = 0;
      return 0i64;
    case 3:
LABEL_7:
      spawnBuildJacobiansJobs(jobIn, m_taskHeader, queue, data, newJobCreated);
      return 0i64;
    case 4:
      v8 = m_taskHeader->m_openJobs-- == 1;
      if ( !v8 )
        goto $noJobCreated;
      p_m_job = &newJobCreated->m_job;
      if ( m_taskHeader->m_solveInSingleThread.m_bool )
      {
        if ( newJobCreated == (hkJobQueue::JobQueueEntryInput *)-16i64 )
        {
          p_m_job = 0i64;
        }
        else
        {
          *(_WORD *)&p_m_job->m_jobSubType = 6;
          newJobCreated->m_job.m_jobSpuType.m_storage = 1;
          newJobCreated->m_job.m_threadAffinity = -1;
          newJobCreated->m_job.m_size = 80;
          *(_WORD *)newJobCreated->m_job.m_data = jobIn->m_islandIndex;
          *(_QWORD *)&newJobCreated->m_job.m_data[8] = jobIn->m_island;
          *(_QWORD *)&newJobCreated->m_job.m_data[16] = jobIn->m_taskHeader;
          *(_QWORD *)&newJobCreated->m_job.m_data[24] = jobIn->m_mtThreadStructure;
          m_buffer = m_taskHeader->m_buffer;
          *(_QWORD *)&newJobCreated->m_job.m_data[32] = m_buffer;
          *(_DWORD *)&newJobCreated->m_job.m_data[44] = LODWORD(m_taskHeader->m_accumulatorsBase) - (_DWORD)m_buffer;
          *(_DWORD *)&newJobCreated->m_job.m_data[48] = LODWORD(m_taskHeader->m_schemasBase) - (_DWORD)m_buffer;
          *(_DWORD *)&newJobCreated->m_job.m_data[52] = LODWORD(m_taskHeader->m_solverTempBase) - (_DWORD)m_buffer;
          *(_DWORD *)&newJobCreated->m_job.m_data[40] = m_taskHeader->m_bufferSize;
          *(_DWORD *)&newJobCreated->m_job.m_data[56] = m_taskHeader->m_numSolverResults;
          *(_DWORD *)&newJobCreated->m_job.m_data[60] = m_taskHeader->m_numSolverElemTemps;
        }
        newJobCreated->m_jobPriority.m_storage = 0;
        newJobCreated->m_job.m_jobSpuType.m_storage = (m_taskHeader->m_solveInSingleThreadOnPpuOnly.m_bool != 0) + 1;
      }
      else
      {
        if ( newJobCreated == (hkJobQueue::JobQueueEntryInput *)-16i64 )
        {
          p_m_job = 0i64;
        }
        else
        {
          *(_WORD *)&p_m_job->m_jobSubType = 7;
          newJobCreated->m_job.m_jobSpuType.m_storage = 1;
          newJobCreated->m_job.m_threadAffinity = -1;
          newJobCreated->m_job.m_size = 64;
          *(_WORD *)newJobCreated->m_job.m_data = jobIn->m_islandIndex;
          *(_QWORD *)&newJobCreated->m_job.m_data[8] = jobIn->m_island;
          *(_QWORD *)&newJobCreated->m_job.m_data[16] = jobIn->m_taskHeader;
          *(_QWORD *)&newJobCreated->m_job.m_data[24] = jobIn->m_mtThreadStructure;
          *(_QWORD *)&newJobCreated->m_job.m_data[32] = m_taskHeader->m_accumulatorsBase;
          *(_QWORD *)&newJobCreated->m_job.m_data[40] = m_taskHeader->m_accumulatorsEnd;
        }
        newJobCreated->m_jobPriority.m_storage = 0;
        newJobCreated->m_job.m_jobSpuType.m_storage = 1;
        m_taskHeader->m_openJobs = m_taskHeader->m_numApplyGravityJobs;
      }
      if ( !m_taskHeader->m_splitCheckRequested )
        return 0i64;
      v31 = 48;
      v33 = *(_WORD *)p_m_job->m_data;
      v12 = *(_QWORD *)&p_m_job->m_data[8];
      v29 = 5;
      v34 = v12;
      v13 = *(_QWORD *)&p_m_job->m_data[16];
      v30 = 2;
      v35 = v13;
      v36 = *(_QWORD *)&p_m_job->m_data[24];
      v32 = -1;
      hkJobQueue::addJobQueueLocked(queue, data, (hkJobQueue::JobQueueEntry *)&v29, JOB_HIGH_PRIORITY);
      return 0i64;
    case 5:
      goto $commonForIntegrateMotinoAndSplitIsland;
    case 6:
      goto $LN33_31;
    case 7:
      v8 = m_taskHeader->m_openJobs-- == 1;
      if ( !v8 )
        goto $noJobCreated;
      if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
      {
        *(_WORD *)&newJobCreated->m_job.m_jobSubType = 8;
        newJobCreated->m_job.m_jobSpuType.m_storage = 1;
        newJobCreated->m_job.m_size = 80;
        newJobCreated->m_job.m_threadAffinity = -1;
        *(_WORD *)newJobCreated->m_job.m_data = jobIn->m_islandIndex;
        *(_QWORD *)&newJobCreated->m_job.m_data[8] = jobIn->m_island;
        *(_QWORD *)&newJobCreated->m_job.m_data[16] = jobIn->m_taskHeader;
        *(_QWORD *)&newJobCreated->m_job.m_data[24] = jobIn->m_mtThreadStructure;
        m_firstSolveJacobiansTask = m_taskHeader->m_solveTasks.m_firstSolveJacobiansTask;
        *(_DWORD *)&newJobCreated->m_job.m_data[32] = 0;
        *(_QWORD *)&newJobCreated->m_job.m_data[48] = m_firstSolveJacobiansTask;
        *(_DWORD *)&newJobCreated->m_job.m_data[40] = 0;
      }
      newJobCreated->m_jobPriority.m_storage = 0;
      newJobCreated->m_job.m_jobSpuType.m_storage = 1;
      m_taskHeader->m_openJobs = m_taskHeader->m_solveTasks.m_firstBatchSize;
      return 0i64;
    case 8:
      v8 = m_taskHeader->m_openJobs-- == 1;
      if ( v8 )
      {
        v15 = *(_QWORD *)&jobIn[1].m_islandIndex;
        m_numIntegrateVelocitiesJobs = *(unsigned __int16 *)(v15 + 50);
        if ( *(_WORD *)(v15 + 50) )
        {
          v17 = &newJobCreated->m_job;
          if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
          {
            *(_WORD *)&v17->m_jobSubType = 8;
            newJobCreated->m_job.m_jobSpuType.m_storage = 1;
            newJobCreated->m_job.m_size = 80;
            newJobCreated->m_job.m_threadAffinity = -1;
            *(_WORD *)newJobCreated->m_job.m_data = jobIn->m_islandIndex;
            *(_QWORD *)&newJobCreated->m_job.m_data[8] = jobIn->m_island;
            *(_QWORD *)&newJobCreated->m_job.m_data[16] = jobIn->m_taskHeader;
            *(_QWORD *)&newJobCreated->m_job.m_data[24] = jobIn->m_mtThreadStructure;
            v17->hkJob = jobIn->hkJob;
            *(_OWORD *)newJobCreated->m_job.m_data = *(_OWORD *)&jobIn->m_islandIndex;
            *(_OWORD *)&newJobCreated->m_job.m_data[16] = *(_OWORD *)&jobIn->m_taskHeader;
            *(hkJob *)&newJobCreated->m_job.m_data[32] = jobIn[1].hkJob;
            *(_OWORD *)&newJobCreated->m_job.m_data[48] = *(_OWORD *)&jobIn[1].m_islandIndex;
            *(_QWORD *)&newJobCreated->m_job.m_data[48] = *(_QWORD *)(*(_QWORD *)&jobIn[1].m_islandIndex + 56i64);
          }
        }
        else if ( (unsigned int)(*(_DWORD *)(&jobIn[1].m_threadAffinity + 1) + 1) >= *(_DWORD *)&jobIn[1].m_size )
        {
          if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
          {
            *(_WORD *)&newJobCreated->m_job.m_jobSubType = 9;
            newJobCreated->m_job.m_jobSpuType.m_storage = 1;
            newJobCreated->m_job.m_size = 80;
            newJobCreated->m_job.m_threadAffinity = -1;
            *(_WORD *)newJobCreated->m_job.m_data = jobIn->m_islandIndex;
            *(_QWORD *)&newJobCreated->m_job.m_data[8] = jobIn->m_island;
            *(_QWORD *)&newJobCreated->m_job.m_data[16] = jobIn->m_taskHeader;
            *(_QWORD *)&newJobCreated->m_job.m_data[24] = jobIn->m_mtThreadStructure;
            *(_QWORD *)&newJobCreated->m_job.m_data[32] = m_taskHeader->m_accumulatorsBase;
            *(_QWORD *)&newJobCreated->m_job.m_data[40] = m_taskHeader->m_accumulatorsEnd;
            *(_DWORD *)&newJobCreated->m_job.m_data[48] = *(_DWORD *)&jobIn[1].m_jobSubType;
            newJobCreated->m_job.m_data[52] = 0;
          }
          m_numIntegrateVelocitiesJobs = m_taskHeader->m_numIntegrateVelocitiesJobs;
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
            *(_WORD *)newJobCreated->m_job.m_data = jobIn->m_islandIndex;
            *(_QWORD *)&newJobCreated->m_job.m_data[8] = jobIn->m_island;
            *(_QWORD *)&newJobCreated->m_job.m_data[16] = jobIn->m_taskHeader;
            *(_QWORD *)&newJobCreated->m_job.m_data[24] = jobIn->m_mtThreadStructure;
            v18->hkJob = jobIn->hkJob;
            *(_OWORD *)newJobCreated->m_job.m_data = *(_OWORD *)&jobIn->m_islandIndex;
            *(_OWORD *)&newJobCreated->m_job.m_data[16] = *(_OWORD *)&jobIn->m_taskHeader;
            *(hkJob *)&newJobCreated->m_job.m_data[32] = jobIn[1].hkJob;
            *(_OWORD *)&newJobCreated->m_job.m_data[48] = *(_OWORD *)&jobIn[1].m_islandIndex;
            *(_QWORD *)&newJobCreated->m_job.m_data[48] = *(_QWORD *)(*(_QWORD *)&jobIn[1].m_islandIndex + 56i64);
          }
          ++*(_DWORD *)&v18->m_data[40];
          *(_QWORD *)&v18->m_data[48] = m_taskHeader->m_solveTasks.m_firstSolveJacobiansTask;
          m_numIntegrateVelocitiesJobs = m_taskHeader->m_solveTasks.m_firstBatchSize;
        }
        newJobCreated->m_jobPriority.m_storage = 0;
        newJobCreated->m_job.m_jobSpuType.m_storage = 1;
        m_taskHeader->m_openJobs = m_numIntegrateVelocitiesJobs;
        v5 = 0;
      }
      goto $noJobCreated;
    case 9:
      v8 = m_taskHeader->m_openJobs-- == 1;
      if ( !v8 )
        goto $noJobCreated;
      v19 = &newJobCreated->m_job;
      if ( *((_BYTE *)&jobIn[1].m_islandIndex + 4) )
      {
        if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
        {
          *(_WORD *)&v19->m_jobSubType = 11;
          newJobCreated->m_job.m_jobSpuType.m_storage = 2;
          newJobCreated->m_job.m_size = 112;
          newJobCreated->m_job.m_threadAffinity = -1;
          *(_WORD *)newJobCreated->m_job.m_data = jobIn->m_islandIndex;
          *(_QWORD *)&newJobCreated->m_job.m_data[8] = jobIn->m_island;
          *(_QWORD *)&newJobCreated->m_job.m_data[16] = jobIn->m_taskHeader;
          *(_QWORD *)&newJobCreated->m_job.m_data[24] = jobIn->m_mtThreadStructure;
          v22 = m_taskHeader->m_solveTasks.m_firstSolveJacobiansTask;
          *(_WORD *)&newJobCreated->m_job.m_data[74] = 0;
          *(_QWORD *)&newJobCreated->m_job.m_data[32] = v22;
          *(_WORD *)&newJobCreated->m_job.m_data[72] = m_taskHeader->m_numAllEntities;
          *(_QWORD *)&newJobCreated->m_job.m_data[64] = m_taskHeader->m_buffer;
          newJobCreated->m_job.m_data[80] = 0;
        }
        m_numBuildJacobianTasks = m_taskHeader->m_tasks.m_numBuildJacobianTasks;
        newJobCreated->m_jobPriority.m_storage = 0;
        newJobCreated->m_job.m_jobSpuType.m_storage = 1;
        m_taskHeader->m_openJobs = m_numBuildJacobianTasks;
        return 0i64;
      }
      else
      {
        if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
        {
          *(_WORD *)&v19->m_jobSubType = 8;
          newJobCreated->m_job.m_jobSpuType.m_storage = 1;
          newJobCreated->m_job.m_size = 80;
          newJobCreated->m_job.m_threadAffinity = -1;
          *(_WORD *)newJobCreated->m_job.m_data = jobIn->m_islandIndex;
          *(_QWORD *)&newJobCreated->m_job.m_data[8] = jobIn->m_island;
          *(_QWORD *)&newJobCreated->m_job.m_data[16] = jobIn->m_taskHeader;
          *(_QWORD *)&newJobCreated->m_job.m_data[24] = jobIn->m_mtThreadStructure;
          *(_QWORD *)&newJobCreated->m_job.m_data[48] = m_taskHeader->m_solveTasks.m_firstSolveJacobiansTask;
          v20 = *(_DWORD *)&jobIn[1].m_islandIndex;
          *(_DWORD *)&newJobCreated->m_job.m_data[40] = 0;
          *(_DWORD *)&newJobCreated->m_job.m_data[32] = v20 + 1;
        }
        m_firstBatchSize = m_taskHeader->m_solveTasks.m_firstBatchSize;
        newJobCreated->m_jobPriority.m_storage = 0;
        newJobCreated->m_job.m_jobSpuType.m_storage = 1;
        m_taskHeader->m_openJobs = m_firstBatchSize;
        return 0i64;
      }
    case 0xA:
      --m_taskHeader->m_openJobs;
      v24 = *(hkpImpulseLimitBreachedHeader **)(*(_QWORD *)&jobIn[1].m_jobSubType + 24i64);
      if ( v24->m_numBreached )
      {
        v24->m_next = m_taskHeader->m_impulseLimitsBreached;
        m_taskHeader->m_impulseLimitsBreached = v24;
      }
      if ( !m_taskHeader->m_openJobs )
$LN33_31:
        m_taskHeader->m_exportFinished = 1;
      goto $noJobCreated;
    case 0xB:
      if ( SHIDWORD(jobIn[1].m_mtThreadStructure) <= 5 )
        m_taskHeader->m_islandShouldBeDeactivated = 0;
      v7 = (((unsigned int)LOWORD(jobIn[1].m_mtThreadStructure) - 1) >> 7) + 1;
$commonForIntegrateMotinoAndSplitIsland:
      v25 = jobIn->m_taskHeader;
      v8 = v25->m_numUnfinishedJobsForBroadphase == v7;
      v25->m_numUnfinishedJobsForBroadphase -= v7;
      if ( !v8 )
        goto $noJobCreated;
      if ( newJobCreated != (hkJobQueue::JobQueueEntryInput *)-16i64 )
      {
        v26 = jobIn->m_taskHeader;
        *(_WORD *)&newJobCreated->m_job.m_jobSubType = 12;
        newJobCreated->m_job.m_jobSpuType.m_storage = 2;
        newJobCreated->m_job.m_size = 64;
        newJobCreated->m_job.m_threadAffinity = -1;
        *(_WORD *)newJobCreated->m_job.m_data = jobIn->m_islandIndex;
        *(_QWORD *)&newJobCreated->m_job.m_data[8] = jobIn->m_island;
        *(_QWORD *)&newJobCreated->m_job.m_data[16] = jobIn->m_taskHeader;
        m_mtThreadStructure = jobIn->m_mtThreadStructure;
        *(_QWORD *)&newJobCreated->m_job.m_data[16] = v26;
        *(_QWORD *)&newJobCreated->m_job.m_data[24] = m_mtThreadStructure;
        *(_WORD *)&newJobCreated->m_job.m_data[32] = 1;
      }
      newJobCreated->m_jobPriority.m_storage = 0;
      result = 0i64;
      break;
    case 0xD:
      v28 = *(_QWORD *)&jobIn[1].m_jobSubType;
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
        *(_WORD *)newJobCreated->m_job.m_data = jobIn->m_islandIndex;
        *(_QWORD *)&newJobCreated->m_job.m_data[8] = jobIn->m_island;
        *(_QWORD *)&newJobCreated->m_job.m_data[16] = jobIn->m_taskHeader;
        *(_QWORD *)&newJobCreated->m_job.m_data[24] = jobIn->m_mtThreadStructure;
        *(_WORD *)newJobCreated->m_job.m_data = jobIn->m_islandIndex;
        *(_QWORD *)&newJobCreated->m_job.m_data[32] = *(_QWORD *)&jobIn[1].m_jobSubType;
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
}

// File Line: 847
// RVA: 0xD8CC00
__int64 __fastcall hkpJobQueueUtils::finishCollideJob(
        hkJobQueue *queue,
        hkJobQueue::DynamicData *data,
        hkJobQueue::JobQueueEntry *jobIn,
        hkJobQueue::JobQueueEntryInput *newJobCreated)
{
  __int64 v5; // rcx

  if ( jobIn->m_jobSubType != 13 )
    return 1i64;
  v5 = *(_QWORD *)&jobIn->m_data[32];
  if ( !v5 )
    return 1i64;
  if ( (*(_DWORD *)(v5 + 4))-- != 1 )
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

