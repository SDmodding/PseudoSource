// File Line: 20
// RVA: 0xD2FCF0
void __fastcall hkCpuPairGetClosestPointsImplementation(hkpPairGetClosestPointsJob *pairGetClosestPointsJob, hkpProcessCollisionInput *collisionInput, hkpPairGetClosestPointsCommand *commandsBase, int numCommands)
{
  float v4; // xmm1_4
  hkpCollisionDispatcher *v5; // rax
  hkpCollisionFilter *v6; // rax
  hkpProcessCollisionInput *v7; // rsi
  __int64 v8; // rdi
  int *v9; // rbx
  __int64 *v10; // rcx
  __int64 *v11; // rdx
  hkpCollisionDispatcher *v12; // r10
  __int64 v13; // r8
  __int64 v14; // r9
  volatile signed __int32 *v15; // rax
  signed __int64 v16; // rcx
  int v17; // ecx
  signed __int32 v18; // edx
  int v19; // edx
  int v20; // edx
  char *v21; // rax
  signed __int64 v22; // rcx
  __int128 v23; // xmm0
  void **v24; // [rsp+20h] [rbp-488h]
  int v25; // [rsp+28h] [rbp-480h]
  char *v26; // [rsp+30h] [rbp-478h]
  __int64 v27; // [rsp+38h] [rbp-470h]
  hkpCollisionDispatcher *v28; // [rsp+40h] [rbp-468h]
  int v29; // [rsp+4Ch] [rbp-45Ch]
  float v30; // [rsp+50h] [rbp-458h]
  hkpCollisionFilter *v31; // [rsp+58h] [rbp-450h]
  char v32; // [rsp+A0h] [rbp-408h]

  v4 = pairGetClosestPointsJob->m_tolerance;
  v26 = &v32;
  v5 = collisionInput->m_dispatcher.m_storage;
  v30 = v4;
  v28 = v5;
  v6 = collisionInput->m_filter.m_storage;
  v7 = collisionInput;
  v24 = &hkpFixedBufferCdPointCollector::`vftable';
  v27 = 1i64;
  v25 = 2139095022;
  v31 = v6;
  v29 = 0;
  if ( numCommands > 0 )
  {
    v8 = (unsigned int)numCommands;
    v9 = &commandsBase->m_resultsCapacity;
    while ( 1 )
    {
      v10 = (__int64 *)*((_QWORD *)v9 - 3);
      v11 = (__int64 *)*((_QWORD *)v9 - 2);
      v12 = v7->m_dispatcher.m_storage;
      v13 = *v10;
      v14 = *v11;
      v24 = &hkpFixedBufferCdPointCollector::`vftable';
      v25 = 2139095022;
      v26 = &v32;
      (*((void (__fastcall **)(__int64 *, __int64 *, hkpCollisionDispatcher **, void ***, void **, _QWORD, char *, _QWORD, hkpCollisionDispatcher *))&v12->vfptr
       + 5
       * ((unsigned __int8)v12->m_agent2Types[*(unsigned __int8 *)(v13 + 16)][*(unsigned __int8 *)(v14 + 16)] + 79i64)))(
        v10,
        v11,
        &v28,
        &v24,
        &hkpFixedBufferCdPointCollector::`vftable',
        *(_QWORD *)&v25,
        &v32,
        (unsigned int)*v9,
        v28);
      v15 = (volatile signed __int32 *)*((_QWORD *)v9 + 1);
      if ( !v15 )
        break;
      v17 = HIDWORD(v27);
      v18 = _InterlockedExchangeAdd(v15, HIDWORD(v27));
      if ( v18 + v17 <= *v9 )
      {
        v16 = *((_QWORD *)v9 - 1) + ((signed __int64)v18 << 6);
        goto LABEL_7;
      }
      _InterlockedExchangeAdd(*((volatile signed __int32 **)v9 + 1), -v17);
LABEL_13:
      v9 += 12;
      if ( !--v8 )
        return;
    }
    v16 = *((_QWORD *)v9 - 1);
LABEL_7:
    if ( v16 )
    {
      v19 = WORD2(v27);
      v9[1] = WORD2(v27);
      if ( v19 > 0 )
      {
        v20 = 4 * v19;
        v21 = &v32;
        v22 = v16 - (_QWORD)&v32;
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
__int64 __fastcall hkCpuPairGetClosestPointsJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  hkJobQueue *v2; // rdi
  hkpPairGetClosestPointsJob *v3; // rbx
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  _QWORD *v8; // r8
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx

  v2 = jobQueue;
  v3 = (hkpPairGetClosestPointsJob *)nextJobOut;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtCollQueryPairGetClosestPoints";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  hkCpuPairGetClosestPointsImplementation(v3, v3->m_collisionInput, v3->m_commandArray, v3->m_numCommands);
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "Et";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  return hkJobQueue::finishJobAndGetNextJob(v2, (hkJobQueue::JobQueueEntry *)v3, (hkJobQueue::JobQueueEntry *)v3, 0);
}

