// File Line: 34
// RVA: 0xD968F0
__int64 __usercall hkCpuAgentSectorJob@<rax>(hkpMtThreadStructure *tl@<rcx>, hkJobQueue *jobQueue@<rdx>, hkJobQueue::JobQueueEntry *nextJobOut@<r8>, __int64 a4@<r12>)
{
  __int128 v4; // xmm1
  __int128 v5; // xmm0
  unsigned int v6; // eax
  hkVector4f v7; // xmm1
  hkVector4f v8; // xmm0
  hkpMtThreadStructure *v9; // r13
  float v10; // eax
  hkVector4f v11; // xmm0
  hkpCollisionFilter *v12; // rax
  hkVector4f v13; // xmm1
  hkVector4f v14; // xmm0
  hkpConvexListFilter *v15; // rax
  hkJobQueue::JobQueueEntry *v16; // rsi
  hkVector4f v17; // xmm1
  __m128i v18; // xmm0
  hkpCollisionQualityInfo *v19; // rax
  bool v20; // zf
  hkpSimulationIsland *v21; // rax
  _QWORD *v22; // rax
  _QWORD *v23; // rcx
  _QWORD *v24; // r8
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  unsigned int v27; // ecx
  hkpAgentNnEntry **v28; // r15
  hkpAgentNnEntry *v29; // rdi
  __int64 v30; // r12
  signed int v31; // eax
  int v32; // edx
  __int64 v33; // r14
  hkpAgentNnEntry *v34; // rax
  unsigned __int64 v35; // r14
  hkpAgentNnEntry *v36; // rbx
  hkpMultiThreadedSimulation *v37; // r13
  unsigned int v38; // ecx
  __int64 v39; // r8
  __int64 v40; // rdx
  char *v41; // rcx
  char *v42; // rcx
  __int64 v44; // r9
  int v45; // ecx
  __int64 v46; // r9
  unsigned int v47; // er10
  _OWORD *v48; // r8
  signed int v49; // edx
  signed __int64 v50; // rax
  _QWORD *v51; // r8
  const char **v52; // rcx
  const char *v53; // rax
  _QWORD *v54; // r8
  _QWORD *v55; // rcx
  unsigned __int64 v56; // rax
  signed __int64 v57; // rcx
  signed int v58; // edi
  __int64 v59; // r14
  hkpAgentNnEntry *v60; // rbx
  hkpCollisionQualityInfo *v61; // rcx
  unsigned int v62; // ecx
  __int64 v63; // r8
  __int64 v64; // rdx
  char *v65; // rcx
  char *v66; // rcx
  __int64 v67; // r9
  unsigned int v68; // er10
  _OWORD *v69; // r8
  signed int v70; // edx
  signed __int64 v71; // rax
  unsigned __int64 v72; // rax
  signed __int64 v73; // rcx
  unsigned int v74; // ebx
  _QWORD **v75; // rax
  __int64 v77; // [rsp+30h] [rbp-D0h]
  __int64 v78; // [rsp+40h] [rbp-C0h]
  __int64 v79; // [rsp+48h] [rbp-B8h]
  __int64 v80; // [rsp+58h] [rbp-A8h]
  hkpLinkedCollidable *v81; // [rsp+60h] [rbp-A0h]
  hkpSimulationIsland *island; // [rsp+68h] [rbp-98h]
  hkpProcessCollisionInput input; // [rsp+70h] [rbp-90h]
  void **v84; // [rsp+110h] [rbp+10h]
  int v85; // [rsp+118h] [rbp+18h]
  __int128 v86; // [rsp+120h] [rbp+20h]
  int v87; // [rsp+130h] [rbp+30h]
  __int64 v88; // [rsp+138h] [rbp+38h]
  int v89; // [rsp+140h] [rbp+40h]
  hkpFixedSizePhysicsCommandQueue<1536> v90; // [rsp+150h] [rbp+50h]
  hkpProcessCollisionOutput output; // [rsp+760h] [rbp+660h]
  __int64 v92; // [rsp+3830h] [rbp+3730h]
  hkpMtThreadStructure *v93; // [rsp+3860h] [rbp+3760h]
  hkJobQueue *v94; // [rsp+3868h] [rbp+3768h]
  hkpAgentNnEntry *v95; // [rsp+3870h] [rbp+3770h]
  hkpLinkedCollidable *v96; // [rsp+3878h] [rbp+3778h]

  v94 = jobQueue;
  v93 = tl;
  v4 = *(_OWORD *)&tl->m_collisionInput.m_tolerance.m_storage;
  *(_OWORD *)&input.m_dispatcher.m_storage = *(_OWORD *)&tl->m_collisionInput.m_dispatcher.m_storage;
  v5 = *(_OWORD *)&tl->m_collisionInput.m_convexListFilter.m_storage;
  *(_OWORD *)&input.m_tolerance.m_storage = v4;
  v6 = tl->m_collisionInput.m_weldClosestPoints.m_storage;
  v7.m_quad = (__m128)tl->m_collisionInput.m_aabb32Info.m_bitOffsetLow;
  *(_OWORD *)&input.m_convexListFilter.m_storage = v5;
  v8.m_quad = (__m128)tl->m_collisionInput.m_aabb32Info.m_bitOffsetHigh;
  input.m_weldClosestPoints.m_storage = v6;
  v9 = tl;
  input.m_forceAcceptContactPoints.m_storage = tl->m_collisionInput.m_forceAcceptContactPoints.m_storage;
  v10 = tl->m_collisionInput.m_tolerance.m_storage;
  input.m_aabb32Info.m_bitOffsetHigh = (hkVector4f)v8.m_quad;
  v11.m_quad = (__m128)tl->m_collisionInput.m_aabb32Info.m_bitOffsetLow;
  input.m_aabb32Info.m_bitOffsetLow = (hkVector4f)v7.m_quad;
  input.m_tolerance.m_storage = v10;
  v12 = tl->m_collisionInput.m_filter.m_storage;
  v13.m_quad = (__m128)tl->m_collisionInput.m_aabb32Info.m_bitScale;
  input.m_aabb32Info.m_bitOffsetLow = (hkVector4f)v11.m_quad;
  v14.m_quad = (__m128)tl->m_collisionInput.m_aabb32Info.m_bitScale;
  input.m_filter.m_storage = v12;
  v15 = tl->m_collisionInput.m_convexListFilter.m_storage;
  v16 = nextJobOut;
  input.m_aabb32Info.m_bitScale = (hkVector4f)v13.m_quad;
  v17.m_quad = (__m128)tl->m_collisionInput.m_aabb32Info.m_bitOffsetHigh;
  input.m_aabb32Info.m_bitScale = (hkVector4f)v14.m_quad;
  input.m_convexListFilter.m_storage = v15;
  LODWORD(v15) = tl->m_collisionInput.m_createPredictiveAgents.m_storage;
  input.m_spareAgentSector = 0i64;
  v18 = *(__m128i *)&nextJobOut->m_data[64];
  input.m_aabb32Info.m_bitOffsetHigh = (hkVector4f)v17.m_quad;
  input.m_createPredictiveAgents.m_storage = (unsigned int)v15;
  v19 = tl->m_collisionInput.m_collisionQualityInfo.m_storage;
  v85 = 0x1FFFF;
  _mm_store_si128((__m128i *)&input.m_stepInfo, v18);
  input.m_collisionQualityInfo.m_storage = v19;
  input.m_dynamicsInfo = tl->m_collisionInput.m_dynamicsInfo;
  input.m_enableDeprecatedWelding.m_bool = tl->m_collisionInput.m_enableDeprecatedWelding.m_bool;
  input.m_allowToSkipConfirmedCallbacks.m_bool = tl->m_collisionInput.m_allowToSkipConfirmedCallbacks.m_bool;
  input.m_config = tl->m_collisionInput.m_config;
  v84 = &hkpDeferredConstraintOwner::`vftable;
  hkpFixedSizePhysicsCommandQueue<1536>::hkpFixedSizePhysicsCommandQueue<1536>(&v90);
  v20 = v16->m_jobSubType == 13;
  _mm_store_si128((__m128i *)&v86, (__m128i)0i64);
  v87 = 0;
  output.m_constraintOwner.m_storage = (hkpConstraintOwner *)&v84;
  v89 = 0;
  output.m_toi.m_time.m_storage = 3.40282e38;
  output.m_toi.m_properties.0 = 0i64;
  if ( v20 )
  {
    v21 = *(hkpSimulationIsland **)&v16->m_data[8];
    v92 = a4;
    island = v21;
    v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v23 = (_QWORD *)v22[1];
    v24 = v22;
    if ( (unsigned __int64)v23 < v22[3] )
    {
      *v23 = "TtNarrowPhase";
      v25 = __rdtsc();
      v26 = (signed __int64)(v23 + 2);
      *(_DWORD *)(v26 - 8) = v25;
      v24[1] = v26;
    }
    v27 = *(unsigned __int16 *)&v16->m_data[42];
    v28 = *(hkpAgentNnEntry ***)&v16->m_data[48];
    v29 = *v28;
    v30 = v27 - 1;
    v31 = 960;
    v32 = 2 * (unsigned __int8)(*v28)->m_nnTrackType.m_storage;
    if ( v27 <= 1 )
      v31 = *(unsigned __int16 *)&v16->m_data[88];
    v33 = v31;
    v34 = &v29[v32];
    v35 = (unsigned __int64)v29 + v33;
    v80 = v32 * 40;
    v36 = &v34[v32];
    v95 = &v29[v32];
    if ( (unsigned __int64)v34 < v35 )
    {
      if ( (unsigned __int64)v36 >= v35 )
        v36 = 0i64;
    }
    else
    {
      v95 = 0i64;
      v36 = 0i64;
    }
    do
    {
      v37 = v9->m_simulation.m_storage;
      v81 = v29->m_collidable[0];
      v96 = v29->m_collidable[1];
      input.m_collisionQualityInfo.m_storage = (hkpCollisionQualityInfo *)((char *)input.m_dispatcher.m_storage
                                                                         + 64 * (v29->m_collisionQualityIndex + 161i64));
      v38 = input.m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage;
      output.m_potentialContacts.m_storage = 0i64;
      input.m_createPredictiveAgents.m_storage = v38;
      output.m_firstFreeContactPoint.m_storage = output.m_contactPoints;
      output.m_toi.m_time.m_storage = 3.40282e38;
      hkAgentNnMachine_ProcessAgent(v29, &input, &output, v29->m_contactMgr, v30);
      if ( output.m_firstFreeContactPoint.m_storage != output.m_contactPoints )
        ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v29->m_contactMgr->vfptr[3].__vecDelDtor)(
          v29->m_contactMgr,
          v81,
          v96,
          &input,
          &output);
      if ( output.m_toi.m_time.m_storage != 3.40282e38 )
        hkpMultiThreadedSimulation::addToiEventWithCriticalSectionLock(
          v37,
          &output,
          v29,
          &v37->m_toiQueueCriticalSection);
      if ( v87 )
      {
        v39 = v88;
        v40 = v90.m_start.m_relativeAddress;
        if ( v87 <= 0 )
        {
          LOBYTE(v79) = 1;
          v42 = (char *)&v90 + v90.m_size;
          *(_QWORD *)&v42[v90.m_start.m_relativeAddress] = v79;
          *(_QWORD *)&v42[v40 + 8] = v39;
          v90.m_size += 16;
        }
        else
        {
          LOBYTE(v77) = 0;
          LODWORD(v78) = v89;
          v41 = (char *)&v90 + v90.m_size;
          *(_QWORD *)&v41[v90.m_start.m_relativeAddress] = v77;
          *(_QWORD *)&v41[v40 + 8] = v39;
          *(_QWORD *)&v41[v40 + 16] = v78;
          v90.m_size += 32;
          v89 = 0;
        }
      }
      else
      {
        v89 = 0;
      }
      v29 = v95;
      v87 = 0;
      v95 = v36;
      if ( hkOutOfMemoryState == 1 )
        break;
      if ( v36 )
      {
        v36 = (hkpAgentNnEntry *)((char *)v36 + v80);
        if ( (unsigned __int64)v36 >= v35 )
        {
          ++v28;
          v30 = (unsigned int)(v30 - 1);
          if ( (signed int)v30 < 0 )
          {
            v36 = 0i64;
          }
          else
          {
            v36 = *v28;
            if ( (signed int)v30 <= 0 )
            {
              v35 = (unsigned __int64)v36 + *(unsigned __int16 *)&v16->m_data[88];
            }
            else
            {
              _RAX = v28[1];
              __asm
              {
                prefetchnta byte ptr [rax]; Prefetch to L1 cache
                prefetchnta byte ptr [rax+40h]; Prefetch to L1 cache
                prefetchnta byte ptr [rax+80h]; Prefetch to L1 cache
                prefetchnta byte ptr [rax+0C0h]; Prefetch to L1 cache
              }
              v35 = (unsigned __int64)&v36[24];
            }
          }
        }
      }
      v9 = v93;
    }
    while ( v29 );
    v44 = *(_QWORD *)&v16->m_data[32];
    if ( v44 )
    {
      v46 = *(_QWORD *)(v44 + 8i64 * *(signed __int16 *)&v16->m_data[40] + 32);
      *(_OWORD *)v46 = v86;
      v47 = v90.m_size;
      if ( v90.m_size )
      {
        v48 = (_OWORD *)((char *)&v90.m_start.m_relativeAddress + v90.m_start.m_relativeAddress);
        v49 = (signed int)v90.m_size >> 4;
        v50 = v46 + 16 + *(unsigned int *)(v46 + 16);
        do
        {
          --v49;
          v50 += 16i64;
          *(_OWORD *)(v50 - 16) = *v48;
          ++v48;
        }
        while ( v49 > 0 );
        *(_DWORD *)(v46 + 20) = v47;
      }
    }
    else if ( (unsigned int)v86 | DWORD1(v86) | DWORD2(v86) | HIDWORD(v86) || v90.m_size )
    {
      hkpWorld::lockIslandForConstraintUpdate(v93->m_world, island);
      v45 = v86;
      if ( island->m_constraintInfo.m_maxSizeOfSchema > (signed int)v86 )
        v45 = island->m_constraintInfo.m_maxSizeOfSchema;
      island->m_constraintInfo.m_maxSizeOfSchema = v45;
      island->m_constraintInfo.m_sizeOfSchemas += DWORD1(v86);
      island->m_constraintInfo.m_numSolverResults += DWORD2(v86);
      island->m_constraintInfo.m_numSolverElemTemps += HIDWORD(v86);
      if ( v90.m_size )
        hkPhysicsCommandMachineProcess(
          v93->m_world,
          (hkpPhysicsCommand *)&v90 + v90.m_start.m_relativeAddress,
          v90.m_size);
      hkpWorld::unlockIslandForConstraintUpdate(v93->m_world, island);
    }
    v51 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v52 = (const char **)v51[1];
    if ( (unsigned __int64)v52 < v51[3] )
    {
      v53 = "EtNarrowPhase";
LABEL_71:
      *v52 = v53;
      v72 = __rdtsc();
      v73 = (signed __int64)(v52 + 2);
      *(_DWORD *)(v73 - 8) = v72;
      v51[1] = v73;
      goto LABEL_72;
    }
    goto LABEL_72;
  }
  v54 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v55 = (_QWORD *)v54[1];
  if ( (unsigned __int64)v55 < v54[3] )
  {
    *v55 = "TtNarrowPhaseTOI";
    v56 = __rdtsc();
    v57 = (signed __int64)(v55 + 2);
    *(_DWORD *)(v57 - 8) = v56;
    v54[1] = v57;
  }
  v58 = 0;
  if ( *(_WORD *)&v16->m_data[42] > 0u )
  {
    v59 = 0i64;
    while ( 1 )
    {
      v60 = *(hkpAgentNnEntry **)(v59 + *(_QWORD *)&v16->m_data[48]);
      if ( v16->m_data[88] )
      {
        if ( v16->m_data[88] == 1 )
        {
          v61 = &input.m_dispatcher.m_storage->m_collisionQualityInfo[1];
        }
        else
        {
          if ( v16->m_data[88] != 2 )
            goto LABEL_54;
          input.m_collisionQualityInfo.m_storage = &input.m_dispatcher.m_storage->m_collisionQualityInfo[7];
          if ( v60->m_collisionQualityIndex != 6 )
            goto LABEL_54;
          v61 = &input.m_dispatcher.m_storage->m_collisionQualityInfo[6];
        }
      }
      else
      {
        v61 = (hkpCollisionQualityInfo *)((char *)input.m_dispatcher.m_storage
                                        + 64 * (v60->m_collisionQualityIndex + 161i64));
      }
      input.m_collisionQualityInfo.m_storage = v61;
LABEL_54:
      v62 = input.m_dispatcher.m_storage->m_collisionQualityInfo[(signed __int64)v60->m_collisionQualityIndex].m_useContinuousPhysics.m_storage;
      output.m_toi.m_time.m_storage = 3.40282e38;
      input.m_createPredictiveAgents.m_storage = v62;
      output.m_firstFreeContactPoint.m_storage = output.m_contactPoints;
      output.m_potentialContacts.m_storage = 0i64;
      hkAgentNnMachine_ProcessAgent(v60, &input, &output, v60->m_contactMgr, a4);
      if ( output.m_firstFreeContactPoint.m_storage != output.m_contactPoints )
        ((void (__fastcall *)(hkpContactMgr *, hkpLinkedCollidable *, hkpLinkedCollidable *, hkpProcessCollisionInput *, hkpProcessCollisionOutput *))v60->m_contactMgr->vfptr[3].__vecDelDtor)(
          v60->m_contactMgr,
          v60->m_collidable[0],
          v60->m_collidable[1],
          &input,
          &output);
      if ( output.m_toi.m_time.m_storage != 3.40282e38 )
        hkpMultiThreadedSimulation::addToiEventWithCriticalSectionLock(
          v9->m_simulation.m_storage,
          &output,
          v60,
          &v9->m_simulation.m_storage->m_toiQueueCriticalSection);
      if ( v87 )
      {
        v63 = v88;
        v64 = v90.m_start.m_relativeAddress;
        if ( v87 <= 0 )
        {
          LOBYTE(v79) = 1;
          v66 = (char *)&v90 + v90.m_size;
          *(_QWORD *)&v66[v90.m_start.m_relativeAddress] = v79;
          *(_QWORD *)&v66[v64 + 8] = v63;
          v90.m_size += 16;
        }
        else
        {
          LOBYTE(v77) = 0;
          LODWORD(v78) = v89;
          v65 = (char *)&v90 + v90.m_size;
          *(_QWORD *)&v65[v90.m_start.m_relativeAddress] = v77;
          *(_QWORD *)&v65[v64 + 8] = v63;
          *(_QWORD *)&v65[v64 + 16] = v78;
          v90.m_size += 32;
          v89 = 0;
        }
      }
      else
      {
        v89 = 0;
      }
      v87 = 0;
      if ( hkOutOfMemoryState != 1 )
      {
        ++v58;
        v59 += 8i64;
        if ( v58 < *(unsigned __int16 *)&v16->m_data[42] )
          continue;
      }
      break;
    }
  }
  v67 = *(_QWORD *)(*(_QWORD *)&v16->m_data[32] + 8i64 * *(signed __int16 *)&v16->m_data[40] + 32);
  *(_OWORD *)v67 = v86;
  v68 = v90.m_size;
  if ( v90.m_size )
  {
    v69 = (_OWORD *)((char *)&v90.m_start.m_relativeAddress + v90.m_start.m_relativeAddress);
    v70 = (signed int)v90.m_size >> 4;
    v71 = v67 + 16 + *(unsigned int *)(v67 + 16);
    do
    {
      --v70;
      v71 += 16i64;
      *(_OWORD *)(v71 - 16) = *v69;
      ++v69;
    }
    while ( v70 > 0 );
    *(_DWORD *)(v67 + 20) = v68;
  }
  v51 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v52 = (const char **)v51[1];
  if ( (unsigned __int64)v52 < v51[3] )
  {
    v53 = "EtNarrowPhaseTOI";
    goto LABEL_71;
  }
LABEL_72:
  v74 = hkJobQueue::finishJobAndGetNextJob(v94, v16, v16, 0);
  v84 = &hkBaseObject::`vftable;
  if ( input.m_spareAgentSector )
  {
    v75 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, hkpAgent1nSector *, signed __int64))(*v75[11] + 16i64))(
      v75[11],
      input.m_spareAgentSector,
      512i64);
  }
  return v74;
}
  {
    v53 = "EtNarrowPhaseTOI";
    goto LABEL_71;
  }
LABEL_72:
  v74 = hkJobQueue::finishJobAndGetNextJob(v94, v16, v16, 0);
  v84 = &hkBaseObject::`vftable;
  if ( input.m_spareAgentSector )
  {
    v75 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall *

