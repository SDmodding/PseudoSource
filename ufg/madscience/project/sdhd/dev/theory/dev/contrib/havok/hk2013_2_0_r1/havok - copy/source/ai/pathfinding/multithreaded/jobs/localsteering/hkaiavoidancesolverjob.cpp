// File Line: 37
// RVA: 0xC0DDF0
hkJobQueue::JobStatus __usercall hkaiProcessAvoidanceSolverJob@<eax>(hkJobQueue *jobQueue@<rcx>, hkJobQueue::JobQueueEntry *nextJobOut@<rdx>, __m128 *a3@<xmm14>)
{
  hkJobQueue *v3; // r14
  hkJobQueue::JobQueueEntry *v4; // rbx
  _QWORD *v5; // r8
  _QWORD *v6; // rcx
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  hkaiAvoidancePairProperties::PairData *v9; // rax
  __int128 *v10; // rsi
  int v11; // edi
  char *v12; // rcx
  __int128 *v13; // rdx
  signed __int64 v14; // rax
  __int128 v15; // xmm0
  __int128 v16; // xmm1
  __int128 v17; // xmm0
  __int128 v18; // xmm1
  __int128 v19; // xmm0
  __int128 v20; // xmm1
  __int128 v21; // xmm0
  __int128 v22; // xmm1
  __int128 v23; // xmm1
  __int128 v24; // xmm0
  __int128 v25; // xmm1
  __int128 v26; // xmm0
  hkaiCharacter **v27; // rax
  int v28; // edx
  hkVector4f *v29; // r8
  hkResultEnum v30; // eax
  hkVector4f *v31; // rax
  _QWORD *v32; // r8
  _QWORD *v33; // rcx
  unsigned __int64 v34; // rax
  signed __int64 v35; // rcx
  hkJobQueue::JobStatus v36; // eax
  hkJobQueue::JobStatus v37; // ebx
  hkArrayBase<hkaiObstacleGenerator const *> v38; // [rsp+50h] [rbp-B0h]
  hkArrayBase<hkaiCharacter const *> v39; // [rsp+60h] [rbp-A0h]
  hkaiAvoidancePairProperties v40; // [rsp+70h] [rbp-90h]
  hkVector4f up; // [rsp+90h] [rbp-70h]
  __m128 v42; // [rsp+A0h] [rbp-60h]
  hkVector4f steerVelocityOut; // [rsp+B0h] [rbp-50h]
  hkaiObstacleCollector v44; // [rsp+C0h] [rbp-40h]
  hkVector4f steerForwardOut; // [rsp+120h] [rbp+20h]
  char Dst; // [rsp+130h] [rbp+30h]
  __m128i v47; // [rsp+150h] [rbp+50h]
  hkVector4f *v48; // [rsp+1A8h] [rbp+A8h]
  hkaiCharacter **v49; // [rsp+1D0h] [rbp+D0h]
  hkaiObstacleGenerator **v50; // [rsp+1D8h] [rbp+D8h]
  int numAgents; // [rsp+1E0h] [rbp+E0h]
  int v52; // [rsp+1E4h] [rbp+E4h]
  unsigned int navMeshFaceKey; // [rsp+1E8h] [rbp+E8h]
  hkVector4f *v54; // [rsp+1F0h] [rbp+F0h]
  hkaiAvoidanceSolver::SteeringAgent agentIn; // [rsp+200h] [rbp+100h]
  hkResult result; // [rsp+358h] [rbp+258h]

  v3 = jobQueue;
  v4 = nextJobOut;
  v5 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v6 = (_QWORD *)v5[1];
  if ( (unsigned __int64)v6 < v5[3] )
  {
    *v6 = "TtAvoidanceJob";
    v7 = __rdtsc();
    v8 = (signed __int64)(v6 + 2);
    *(_DWORD *)(v8 - 8) = v7;
    v5[1] = v8;
  }
  v9 = *(hkaiAvoidancePairProperties::PairData **)&v4->m_data[32];
  v10 = *(__int128 **)&v4->m_data[48];
  v40.m_avoidancePairDataMap.m_size = *(_DWORD *)&v4->m_data[40];
  *(_DWORD *)&v40.m_memSizeAndFlags = 0x1FFFF;
  v40.vfptr = (hkBaseObjectVtbl *)&hkaiAvoidancePairProperties::`vftable';
  v40.m_avoidancePairDataMap.m_data = v9;
  v11 = 0;
  for ( v40.m_avoidancePairDataMap.m_capacityAndFlags = v40.m_avoidancePairDataMap.m_size | 0x80000000;
        v11 < *(_DWORD *)&v4->m_data[56];
        v39.m_capacityAndFlags = 2147483648 )
  {
    v12 = &Dst;
    v13 = v10;
    if ( ((unsigned __int8)&Dst | (unsigned __int8)v10) & 0xF )
    {
      memmove(&Dst, v10, 0xD0ui64);
    }
    else
    {
      v14 = 1i64;
      do
      {
        v15 = *v13;
        v16 = v13[1];
        v12 += 128;
        v13 += 8;
        *((_OWORD *)v12 - 8) = v15;
        v17 = *(v13 - 6);
        *((_OWORD *)v12 - 7) = v16;
        v18 = *(v13 - 5);
        *((_OWORD *)v12 - 6) = v17;
        v19 = *(v13 - 4);
        *((_OWORD *)v12 - 5) = v18;
        v20 = *(v13 - 3);
        *((_OWORD *)v12 - 4) = v19;
        v21 = *(v13 - 2);
        *((_OWORD *)v12 - 3) = v20;
        v22 = *(v13 - 1);
        *((_OWORD *)v12 - 2) = v21;
        *((_OWORD *)v12 - 1) = v22;
        --v14;
      }
      while ( v14 );
      v23 = v13[1];
      *(_OWORD *)v12 = *v13;
      v24 = v13[2];
      *((_OWORD *)v12 + 1) = v23;
      v25 = v13[3];
      *((_OWORD *)v12 + 2) = v24;
      v26 = v13[4];
      *((_OWORD *)v12 + 3) = v25;
      *((_OWORD *)v12 + 4) = v26;
    }
    v27 = v49;
    v28 = numAgents;
    v29 = v48;
    _mm_store_si128((__m128i *)&up, v47);
    v39.m_data = v27;
    v39.m_capacityAndFlags = v28 | 0x80000000;
    v10 += 13;
    v38.m_data = v50;
    v39.m_size = v28;
    v38.m_size = v52;
    v38.m_capacityAndFlags = v52 | 0x80000000;
    hkaiObstacleCollector::hkaiObstacleCollector(&v44, v28, v29 + 2, &up);
    hkaiAvoidanceSolverUtils::setupAgent(
      (hkaiLocalSteeringInput *)&Dst,
      *(hkaiStreamingCollection::InstanceInfo **)&v4->m_data[24],
      navMeshFaceKey,
      *(float *)&v4->m_data[20]);
    v30 = hkaiAvoidanceSolverUtils::calcSteeringVelocity(
            &result,
            *(float *)&v4->m_data[16],
            &up,
            &agentIn,
            a3,
            &steerVelocityOut,
            &steerForwardOut)->m_enum;
    v42 = steerForwardOut.m_quad;
    v44.m_neighborAgents.m_size = 0;
    v42.m128_i32[3] = v30 | 0x3F000000;
    if ( v44.m_neighborAgents.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v44.m_neighborAgents.m_data,
        80 * (v44.m_neighborAgents.m_capacityAndFlags & 0x3FFFFFFF));
    v44.m_neighborAgents.m_data = 0i64;
    v44.m_neighborAgents.m_capacityAndFlags = 2147483648;
    v44.m_boundaries.m_size = 0;
    if ( v44.m_boundaries.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v44.m_boundaries.m_data,
        32 * v44.m_boundaries.m_capacityAndFlags);
    v44.m_boundaries.m_data = 0i64;
    v44.m_boundaries.m_capacityAndFlags = 2147483648;
    v44.m_spheres.m_size = 0;
    if ( v44.m_spheres.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v44.m_spheres.m_data,
        32 * v44.m_spheres.m_capacityAndFlags);
    v31 = v54;
    *v54 = (hkVector4f)v42;
    v31[1] = (hkVector4f)steerVelocityOut.m_quad;
    v38.m_size = 0;
    if ( v38.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v38.m_data,
        8 * v38.m_capacityAndFlags);
    v38.m_data = 0i64;
    v38.m_capacityAndFlags = 2147483648;
    v39.m_size = 0;
    if ( v39.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v39.m_data,
        8 * v39.m_capacityAndFlags);
    ++v11;
    v39.m_data = 0i64;
  }
  v32 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v33 = (_QWORD *)v32[1];
  if ( (unsigned __int64)v33 < v32[3] )
  {
    *v33 = "Et";
    v34 = __rdtsc();
    v35 = (signed __int64)(v33 + 2);
    *(_DWORD *)(v35 - 8) = v34;
    v32[1] = v35;
  }
  v36 = hkJobQueue::finishJobAndGetNextJob(v3, v4, v4, 0);
  v40.vfptr = (hkBaseObjectVtbl *)&hkaiAvoidancePairProperties::`vftable';
  v37 = v36;
  v40.m_avoidancePairDataMap.m_size = 0;
  if ( v40.m_avoidancePairDataMap.m_capacityAndFlags >= 0 )
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v40.m_avoidancePairDataMap.m_data,
      12 * (v40.m_avoidancePairDataMap.m_capacityAndFlags & 0x3FFFFFFF));
    v36 = v37;
  }
  return v36;
}

