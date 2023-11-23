// File Line: 20
// RVA: 0xD2FCF0
void __fastcall hkCpuPairGetClosestPointsImplementation(
        hkpPairGetClosestPointsJob *pairGetClosestPointsJob,
        hkpProcessCollisionInput *collisionInput,
        hkpPairGetClosestPointsCommand *commandsBase,
        unsigned int numCommands)
{
  float m_tolerance; // xmm1_4
  hkpCollisionDispatcher *m_storage; // rax
  hkpCollisionFilter *v6; // rax
  __int64 v8; // rdi
  int *i; // rbx
  hkpCdBody *v10; // rcx
  hkpCdBody *v11; // rdx
  hkpCollisionDispatcher *v12; // r10
  hkpShape *m_shape; // r8
  hkpShape *v14; // r9
  volatile signed __int32 *v15; // rax
  __int64 v16; // rcx
  int v17; // ecx
  signed __int32 v18; // edx
  int v19; // edx
  int v20; // edx
  char *v21; // rax
  __int64 v22; // rcx
  __int128 v23; // xmm0
  void **v24; // [rsp+20h] [rbp-488h] BYREF
  int v25; // [rsp+28h] [rbp-480h]
  char *v26; // [rsp+30h] [rbp-478h]
  __int64 v27; // [rsp+38h] [rbp-470h]
  hkpCollisionDispatcher *v28; // [rsp+40h] [rbp-468h] BYREF
  int v29; // [rsp+4Ch] [rbp-45Ch]
  float v30; // [rsp+50h] [rbp-458h]
  hkpCollisionFilter *v31; // [rsp+58h] [rbp-450h]
  char v32[1024]; // [rsp+A0h] [rbp-408h] BYREF

  m_tolerance = pairGetClosestPointsJob->m_tolerance;
  v26 = v32;
  m_storage = collisionInput->m_dispatcher.m_storage;
  v30 = m_tolerance;
  v28 = m_storage;
  v6 = collisionInput->m_filter.m_storage;
  v24 = &hkpFixedBufferCdPointCollector::`vftable;
  v27 = 1i64;
  v25 = 2139095022;
  v31 = v6;
  v29 = 0;
  if ( (int)numCommands > 0 )
  {
    v8 = numCommands;
    for ( i = &commandsBase->m_resultsCapacity; ; i += 12 )
    {
      v10 = (hkpCdBody *)*((_QWORD *)i - 3);
      v11 = (hkpCdBody *)*((_QWORD *)i - 2);
      v12 = collisionInput->m_dispatcher.m_storage;
      m_shape = v10->m_shape;
      v14 = v11->m_shape;
      v24 = &hkpFixedBufferCdPointCollector::`vftable;
      v25 = 2139095022;
      v26 = v32;
      v27 = (unsigned int)*i;
      v12->m_agent2Func[(unsigned __int8)v12->m_agent2Types[(unsigned __int8)m_shape->m_type.m_storage][(unsigned __int8)v14->m_type.m_storage]].m_getClosestPointFunc(
        v10,
        v11,
        (hkpCollisionInput *)&v28,
        (hkpCdPointCollector *)&v24);
      v15 = (volatile signed __int32 *)*((_QWORD *)i + 1);
      if ( !v15 )
        break;
      v17 = HIDWORD(v27);
      v18 = _InterlockedExchangeAdd(v15, HIDWORD(v27));
      if ( v18 + v17 <= *i )
      {
        v16 = *((_QWORD *)i - 1) + ((__int64)v18 << 6);
        goto LABEL_7;
      }
      _InterlockedExchangeAdd(*((volatile signed __int32 **)i + 1), -v17);
LABEL_13:
      if ( !--v8 )
        return;
    }
    v16 = *((_QWORD *)i - 1);
LABEL_7:
    if ( v16 )
    {
      v19 = WORD2(v27);
      i[1] = WORD2(v27);
      if ( v19 > 0 )
      {
        v20 = 4 * v19;
        v21 = v32;
        v22 = v16 - (_QWORD)v32;
        do
        {
          v23 = *(_OWORD *)v21;
          --v20;
          v21 += 16;
          *(_OWORD *)&v21[v22 - 16] = v23;
        }
        while ( v20 > 0 );
      }
    }
    goto LABEL_13;
  }
}

// File Line: 117
// RVA: 0xD2FC30
__int64 __fastcall hkCpuPairGetClosestPointsJob(hkJobQueue *jobQueue, hkpPairGetClosestPointsJob *nextJobOut)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtCollQueryPairGetClosestPoints";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  hkCpuPairGetClosestPointsImplementation(
    nextJobOut,
    nextJobOut->m_collisionInput,
    nextJobOut->m_commandArray,
    nextJobOut->m_numCommands);
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "Et";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    v8[1] = v11;
  }
  return hkJobQueue::finishJobAndGetNextJob(
           jobQueue,
           (hkJobQueue::JobQueueEntry *)nextJobOut,
           (hkJobQueue::JobQueueEntry *)nextJobOut,
           WAIT_FOR_NEXT_JOB);
}

