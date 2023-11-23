// File Line: 34
// RVA: 0xD968F0
__int64 __fastcall hkCpuAgentSectorJob(
        hkpMtThreadStructure *tl,
        hkJobQueue *jobQueue,
        hkJobQueue::JobQueueEntry *nextJobOut)
{
  __int128 v3; // xmm1
  __int128 v4; // xmm0
  unsigned int m_storage; // eax
  hkVector4f v6; // xmm1
  hkVector4f v7; // xmm0
  hkpMtThreadStructure *v8; // r13
  float v9; // eax
  hkVector4f v10; // xmm0
  hkpCollisionFilter *v11; // rax
  hkVector4f v12; // xmm1
  hkVector4f v13; // xmm0
  hkpConvexListFilter *v14; // rax
  hkVector4f v16; // xmm1
  hkStepInfo v17; // xmm0
  hkpCollisionQualityInfo *v18; // rax
  bool v19; // zf
  _QWORD *Value; // rax
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  unsigned int v25; // ecx
  hkpAgentNnEntry **v26; // r15
  hkpAgentNnEntry *v27; // rdi
  int v28; // r12d
  int v29; // eax
  int v30; // edx
  __int64 v31; // r14
  hkpAgentNnEntry *v32; // rax
  hkpAgentNnEntry *v33; // r14
  hkpAgentNnEntry *v34; // rbx
  hkpMultiThreadedSimulation *v35; // r13
  unsigned int v36; // ecx
  __int64 v37; // r8
  __int64 m_relativeAddress; // rdx
  char *v39; // rcx
  char *v40; // rcx
  const char *v41; // rax
  __int64 v42; // r9
  int m_maxSizeOfSchema; // ecx
  __int64 v44; // r9
  unsigned int m_size; // r10d
  _OWORD *v46; // r8
  int v47; // edx
  __int64 v48; // rax
  _QWORD *v49; // r8
  const char **v50; // rcx
  const char *v51; // rax
  _QWORD *v52; // r8
  _QWORD *v53; // rcx
  unsigned __int64 v54; // rax
  _QWORD *v55; // rcx
  int v56; // edi
  __int64 v57; // r14
  hkpAgentNnEntry *v58; // rbx
  hkpCollisionQualityInfo *v59; // rcx
  unsigned int v60; // ecx
  __int64 v61; // r8
  __int64 v62; // rdx
  char *v63; // rcx
  char *v64; // rcx
  __int64 v65; // r9
  unsigned int v66; // r10d
  _OWORD *v67; // r8
  int v68; // edx
  __int64 v69; // rax
  unsigned __int64 v70; // rax
  _QWORD *v71; // rcx
  unsigned int NextJob; // ebx
  _QWORD **v73; // rax
  __int64 v75; // [rsp+30h] [rbp-D0h]
  __int64 v76; // [rsp+40h] [rbp-C0h]
  __int64 v77; // [rsp+48h] [rbp-B8h]
  __int64 v78; // [rsp+58h] [rbp-A8h]
  hkpLinkedCollidable *v79; // [rsp+60h] [rbp-A0h]
  hkpSimulationIsland *island; // [rsp+68h] [rbp-98h]
  hkpProcessCollisionInput input; // [rsp+70h] [rbp-90h] BYREF
  void **v82; // [rsp+110h] [rbp+10h] BYREF
  int v83; // [rsp+118h] [rbp+18h]
  __int128 v84; // [rsp+120h] [rbp+20h]
  int v85; // [rsp+130h] [rbp+30h]
  __int64 v86; // [rsp+138h] [rbp+38h]
  int v87; // [rsp+140h] [rbp+40h]
  hkpFixedSizePhysicsCommandQueue<1536> v88; // [rsp+150h] [rbp+50h] BYREF
  hkpProcessCollisionOutput output; // [rsp+760h] [rbp+660h] BYREF
  hkpAgentNnEntry *v92; // [rsp+3870h] [rbp+3770h]
  hkpLinkedCollidable *v93; // [rsp+3878h] [rbp+3778h]

  v3 = *(_OWORD *)&tl->m_collisionInput.m_tolerance.m_storage;
  *(_OWORD *)&input.m_dispatcher.m_storage = *(_OWORD *)&tl->m_collisionInput.m_dispatcher.m_storage;
  v4 = *(_OWORD *)&tl->m_collisionInput.m_convexListFilter.m_storage;
  *(_OWORD *)&input.m_tolerance.m_storage = v3;
  m_storage = tl->m_collisionInput.m_weldClosestPoints.m_storage;
  v6.m_quad = (__m128)tl->m_collisionInput.m_aabb32Info.m_bitOffsetLow;
  *(_OWORD *)&input.m_convexListFilter.m_storage = v4;
  v7.m_quad = (__m128)tl->m_collisionInput.m_aabb32Info.m_bitOffsetHigh;
  input.m_weldClosestPoints.m_storage = m_storage;
  v8 = tl;
  input.m_forceAcceptContactPoints.m_storage = tl->m_collisionInput.m_forceAcceptContactPoints.m_storage;
  v9 = tl->m_collisionInput.m_tolerance.m_storage;
  input.m_aabb32Info.m_bitOffsetHigh = (hkVector4f)v7.m_quad;
  v10.m_quad = (__m128)tl->m_collisionInput.m_aabb32Info.m_bitOffsetLow;
  input.m_aabb32Info.m_bitOffsetLow = (hkVector4f)v6.m_quad;
  input.m_tolerance.m_storage = v9;
  v11 = tl->m_collisionInput.m_filter.m_storage;
  v12.m_quad = (__m128)tl->m_collisionInput.m_aabb32Info.m_bitScale;
  input.m_aabb32Info.m_bitOffsetLow = (hkVector4f)v10.m_quad;
  v13.m_quad = (__m128)tl->m_collisionInput.m_aabb32Info.m_bitScale;
  input.m_filter.m_storage = v11;
  v14 = tl->m_collisionInput.m_convexListFilter.m_storage;
  input.m_aabb32Info.m_bitScale = (hkVector4f)v12.m_quad;
  v16.m_quad = (__m128)tl->m_collisionInput.m_aabb32Info.m_bitOffsetHigh;
  input.m_aabb32Info.m_bitScale = (hkVector4f)v13.m_quad;
  input.m_convexListFilter.m_storage = v14;
  LODWORD(v14) = tl->m_collisionInput.m_createPredictiveAgents.m_storage;
  input.m_spareAgentSector = 0i64;
  v17 = *(hkStepInfo *)&nextJobOut->m_data[64];
  input.m_aabb32Info.m_bitOffsetHigh = (hkVector4f)v16.m_quad;
  input.m_createPredictiveAgents.m_storage = (unsigned int)v14;
  v18 = tl->m_collisionInput.m_collisionQualityInfo.m_storage;
  v83 = 0x1FFFF;
  input.m_stepInfo = v17;
  input.m_collisionQualityInfo.m_storage = v18;
  input.m_dynamicsInfo = tl->m_collisionInput.m_dynamicsInfo;
  input.m_enableDeprecatedWelding.m_bool = tl->m_collisionInput.m_enableDeprecatedWelding.m_bool;
  input.m_allowToSkipConfirmedCallbacks.m_bool = tl->m_collisionInput.m_allowToSkipConfirmedCallbacks.m_bool;
  input.m_config = tl->m_collisionInput.m_config;
  v82 = &hkpDeferredConstraintOwner::`vftable;
  hkpFixedSizePhysicsCommandQueue<1536>::hkpFixedSizePhysicsCommandQueue<1536>(&v88);
  v19 = nextJobOut->m_jobSubType == 13;
  v84 = 0i64;
  v85 = 0;
  output.m_constraintOwner.m_storage = (hkpConstraintOwner *)&v82;
  v87 = 0;
  output.m_toi.m_time.m_storage = 3.40282e38;
  output.m_toi.m_properties.hkpSolverResults = 0i64;
  if ( v19 )
  {
    island = *(hkpSimulationIsland **)&nextJobOut->m_data[8];
    Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v21 = (_QWORD *)Value[1];
    v22 = Value;
    if ( (unsigned __int64)v21 < Value[3] )
    {
      *v21 = "TtNarrowPhase";
      v23 = __rdtsc();
      v24 = v21 + 2;
      *((_DWORD *)v24 - 2) = v23;
      v22[1] = v24;
    }
    v25 = *(unsigned __int16 *)&nextJobOut->m_data[42];
    v26 = *(hkpAgentNnEntry ***)&nextJobOut->m_data[48];
    v27 = *v26;
    v28 = v25 - 1;
    v29 = 960;
    v30 = 2 * (unsigned __int8)(*v26)->m_nnTrackType.m_storage;
    if ( v25 <= 1 )
      v29 = *(unsigned __int16 *)&nextJobOut->m_data[88];
    v31 = v29;
    v32 = &v27[v30];
    v33 = (hkpAgentNnEntry *)((char *)v27 + v31);
    v78 = v30 * 40;
    v34 = &v32[v30];
    v92 = v32;
    if ( v32 < v33 )
    {
      if ( v34 >= v33 )
        v34 = 0i64;
    }
    else
    {
      v92 = 0i64;
      v34 = 0i64;
    }
    do
    {
      v35 = v8->m_simulation.m_storage;
      v79 = v27->m_collidable[0];
      v93 = v27->m_collidable[1];
      input.m_collisionQualityInfo.m_storage = &input.m_dispatcher.m_storage->m_collisionQualityInfo[v27->m_collisionQualityIndex];
      v36 = input.m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage;
      output.m_potentialContacts.m_storage = 0i64;
      input.m_createPredictiveAgents.m_storage = v36;
      output.m_firstFreeContactPoint.m_storage = output.m_contactPoints;
      output.m_toi.m_time.m_storage = 3.40282e38;
      hkAgentNnMachine_ProcessAgent(v27, &input, &output, v27->m_contactMgr);
      if ( output.m_firstFreeContactPoint.m_storage != output.m_contactPoints )
        ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v27->m_contactMgr->vfptr[3].__vecDelDtor)(
          v27->m_contactMgr,
          v79,
          v93,
          &input,
          &output);
      if ( output.m_toi.m_time.m_storage != 3.40282e38 )
        hkpMultiThreadedSimulation::addToiEventWithCriticalSectionLock(
          v35,
          &output,
          v27,
          &v35->m_toiQueueCriticalSection);
      if ( v85 )
      {
        v37 = v86;
        m_relativeAddress = v88.m_start.m_relativeAddress;
        if ( v85 <= 0 )
        {
          LOBYTE(v77) = 1;
          v40 = (char *)&v88 + v88.m_size;
          *(_QWORD *)&v40[v88.m_start.m_relativeAddress] = v77;
          *(_QWORD *)&v40[m_relativeAddress + 8] = v37;
          v88.m_size += 16;
        }
        else
        {
          LOBYTE(v75) = 0;
          LODWORD(v76) = v87;
          v39 = (char *)&v88 + v88.m_size;
          *(_QWORD *)&v39[v88.m_start.m_relativeAddress] = v75;
          *(_QWORD *)&v39[m_relativeAddress + 8] = v37;
          *(_QWORD *)&v39[m_relativeAddress + 16] = v76;
          v88.m_size += 32;
          v87 = 0;
        }
      }
      else
      {
        v87 = 0;
      }
      v27 = v92;
      v85 = 0;
      v92 = v34;
      if ( hkOutOfMemoryState == MEMORY_STATE_OUT_OF_MEMORY )
        break;
      if ( v34 )
      {
        v34 = (hkpAgentNnEntry *)((char *)v34 + v78);
        if ( v34 >= v33 )
        {
          ++v26;
          if ( --v28 < 0 )
          {
            v34 = 0i64;
          }
          else
          {
            v34 = *v26;
            if ( v28 <= 0 )
            {
              v33 = (hkpAgentNnEntry *)((char *)v34 + *(unsigned __int16 *)&nextJobOut->m_data[88]);
            }
            else
            {
              v41 = (const char *)v26[1];
              _mm_prefetch(v41, 0);
              _mm_prefetch(v41 + 64, 0);
              _mm_prefetch(v41 + 128, 0);
              _mm_prefetch(v41 + 192, 0);
              v33 = v34 + 24;
            }
          }
        }
      }
      v8 = tl;
    }
    while ( v27 );
    v42 = *(_QWORD *)&nextJobOut->m_data[32];
    if ( v42 )
    {
      v44 = *(_QWORD *)(v42 + 8i64 * *(__int16 *)&nextJobOut->m_data[40] + 32);
      *(_OWORD *)v44 = v84;
      m_size = v88.m_size;
      if ( v88.m_size )
      {
        v46 = (_OWORD *)((char *)&v88.m_start.m_relativeAddress + v88.m_start.m_relativeAddress);
        v47 = (int)v88.m_size >> 4;
        v48 = v44 + 16 + *(unsigned int *)(v44 + 16);
        do
        {
          --v47;
          v48 += 16i64;
          *(_OWORD *)(v48 - 16) = *v46++;
        }
        while ( v47 > 0 );
        *(_DWORD *)(v44 + 20) = m_size;
      }
    }
    else if ( (unsigned int)v84 | DWORD1(v84) | DWORD2(v84) | HIDWORD(v84) || v88.m_size )
    {
      hkpWorld::lockIslandForConstraintUpdate(tl->m_world, island);
      m_maxSizeOfSchema = v84;
      if ( island->m_constraintInfo.m_maxSizeOfSchema > (int)v84 )
        m_maxSizeOfSchema = island->m_constraintInfo.m_maxSizeOfSchema;
      island->m_constraintInfo.m_maxSizeOfSchema = m_maxSizeOfSchema;
      island->m_constraintInfo.m_sizeOfSchemas += DWORD1(v84);
      island->m_constraintInfo.m_numSolverResults += DWORD2(v84);
      island->m_constraintInfo.m_numSolverElemTemps += HIDWORD(v84);
      if ( v88.m_size )
        hkPhysicsCommandMachineProcess(
          tl->m_world,
          (hkpPhysicsCommand *)&v88 + v88.m_start.m_relativeAddress,
          v88.m_size);
      hkpWorld::unlockIslandForConstraintUpdate(tl->m_world, island);
    }
    v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v50 = (const char **)v49[1];
    if ( (unsigned __int64)v50 < v49[3] )
    {
      v51 = "EtNarrowPhase";
LABEL_71:
      *v50 = v51;
      v70 = __rdtsc();
      v71 = v50 + 2;
      *((_DWORD *)v71 - 2) = v70;
      v49[1] = v71;
      goto LABEL_72;
    }
    goto LABEL_72;
  }
  v52 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v53 = (_QWORD *)v52[1];
  if ( (unsigned __int64)v53 < v52[3] )
  {
    *v53 = "TtNarrowPhaseTOI";
    v54 = __rdtsc();
    v55 = v53 + 2;
    *((_DWORD *)v55 - 2) = v54;
    v52[1] = v55;
  }
  v56 = 0;
  if ( *(_WORD *)&nextJobOut->m_data[42] )
  {
    v57 = 0i64;
    while ( 1 )
    {
      v58 = *(hkpAgentNnEntry **)(v57 + *(_QWORD *)&nextJobOut->m_data[48]);
      if ( nextJobOut->m_data[88] )
      {
        if ( nextJobOut->m_data[88] == 1 )
        {
          v59 = &input.m_dispatcher.m_storage->m_collisionQualityInfo[1];
        }
        else
        {
          if ( nextJobOut->m_data[88] != 2 )
            goto LABEL_54;
          input.m_collisionQualityInfo.m_storage = &input.m_dispatcher.m_storage->m_collisionQualityInfo[7];
          if ( v58->m_collisionQualityIndex != 6 )
            goto LABEL_54;
          v59 = &input.m_dispatcher.m_storage->m_collisionQualityInfo[6];
        }
      }
      else
      {
        v59 = &input.m_dispatcher.m_storage->m_collisionQualityInfo[v58->m_collisionQualityIndex];
      }
      input.m_collisionQualityInfo.m_storage = v59;
LABEL_54:
      v60 = input.m_dispatcher.m_storage->m_collisionQualityInfo[(__int64)v58->m_collisionQualityIndex].m_useContinuousPhysics.m_storage;
      output.m_toi.m_time.m_storage = 3.40282e38;
      input.m_createPredictiveAgents.m_storage = v60;
      output.m_firstFreeContactPoint.m_storage = output.m_contactPoints;
      output.m_potentialContacts.m_storage = 0i64;
      hkAgentNnMachine_ProcessAgent(v58, &input, &output, v58->m_contactMgr);
      if ( output.m_firstFreeContactPoint.m_storage != output.m_contactPoints )
        ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v58->m_contactMgr->vfptr[3].__vecDelDtor)(
          v58->m_contactMgr,
          v58->m_collidable[0],
          v58->m_collidable[1],
          &input,
          &output);
      if ( output.m_toi.m_time.m_storage != 3.40282e38 )
        hkpMultiThreadedSimulation::addToiEventWithCriticalSectionLock(
          v8->m_simulation.m_storage,
          &output,
          v58,
          &v8->m_simulation.m_storage->m_toiQueueCriticalSection);
      if ( v85 )
      {
        v61 = v86;
        v62 = v88.m_start.m_relativeAddress;
        if ( v85 <= 0 )
        {
          LOBYTE(v77) = 1;
          v64 = (char *)&v88 + v88.m_size;
          *(_QWORD *)&v64[v88.m_start.m_relativeAddress] = v77;
          *(_QWORD *)&v64[v62 + 8] = v61;
          v88.m_size += 16;
        }
        else
        {
          LOBYTE(v75) = 0;
          LODWORD(v76) = v87;
          v63 = (char *)&v88 + v88.m_size;
          *(_QWORD *)&v63[v88.m_start.m_relativeAddress] = v75;
          *(_QWORD *)&v63[v62 + 8] = v61;
          *(_QWORD *)&v63[v62 + 16] = v76;
          v88.m_size += 32;
          v87 = 0;
        }
      }
      else
      {
        v87 = 0;
      }
      v85 = 0;
      if ( hkOutOfMemoryState != MEMORY_STATE_OUT_OF_MEMORY )
      {
        ++v56;
        v57 += 8i64;
        if ( v56 < *(unsigned __int16 *)&nextJobOut->m_data[42] )
          continue;
      }
      break;
    }
  }
  v65 = *(_QWORD *)(*(_QWORD *)&nextJobOut->m_data[32] + 8i64 * *(__int16 *)&nextJobOut->m_data[40] + 32);
  *(_OWORD *)v65 = v84;
  v66 = v88.m_size;
  if ( v88.m_size )
  {
    v67 = (_OWORD *)((char *)&v88.m_start.m_relativeAddress + v88.m_start.m_relativeAddress);
    v68 = (int)v88.m_size >> 4;
    v69 = v65 + 16 + *(unsigned int *)(v65 + 16);
    do
    {
      --v68;
      v69 += 16i64;
      *(_OWORD *)(v69 - 16) = *v67++;
    }
    while ( v68 > 0 );
    *(_DWORD *)(v65 + 20) = v66;
  }
  v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v50 = (const char **)v49[1];
  if ( (unsigned __int64)v50 < v49[3] )
  {
    v51 = "EtNarrowPhaseTOI";
    goto LABEL_71;
  }
LABEL_72:
  NextJob = hkJobQueue::finishJobAndGetNextJob(jobQueue, nextJobOut, nextJobOut, WAIT_FOR_NEXT_JOB);
  v82 = &hkBaseObject::`vftable;
  if ( input.m_spareAgentSector )
  {
    v73 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, __int64))(*v73[11] + 16i64))(
      v73[11],
      input.m_spareAgentSector,
      512i64);
  }
  return NextJob;
}

