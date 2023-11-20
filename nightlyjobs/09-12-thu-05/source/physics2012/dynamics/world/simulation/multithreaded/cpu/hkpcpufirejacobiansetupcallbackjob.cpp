// File Line: 31
// RVA: 0xD959D0
__int64 __fastcall hkpSingleThreadedJobsOnIsland::cpuFireJacobianSetupCallbackJob(hkpMtThreadStructure *tl, hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *jobInOut)
{
  __int128 v3; // xmm0
  __int128 v4; // xmm1
  __int64 v5; // rsi
  hkJobQueue::JobQueueEntry *v6; // r15
  hkJobQueue *v7; // r12
  __int128 v8; // xmm0
  __int128 v9; // xmm1
  hkSimdFloat32 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  _QWORD *v14; // rax
  unsigned __int64 v15; // rcx
  _QWORD *v16; // r8
  unsigned __int64 v17; // rax
  int v18; // ebp
  __int64 v19; // rdi
  __int64 v20; // rbx
  __int64 v21; // r8
  __int64 i; // r14
  __int64 v23; // rdx
  __int64 v24; // rcx
  int v25; // edi
  __int64 v26; // rbx
  _QWORD **v27; // rax
  _QWORD *v28; // rax
  _QWORD *v29; // rcx
  _QWORD *v30; // r8
  unsigned __int64 v31; // rax
  signed __int64 v32; // rcx
  __int64 v34; // [rsp+20h] [rbp-C8h]
  __int64 v35; // [rsp+28h] [rbp-C0h]
  hkpConstraintQueryIn in; // [rsp+40h] [rbp-A8h]

  v3 = *(_OWORD *)&tl->m_constraintQueryIn.m_subStepDeltaTime.m_storage;
  v4 = *(_OWORD *)&tl->m_constraintQueryIn.m_frameInvDeltaTime.m_storage;
  v5 = *(_QWORD *)&jobInOut->m_data[16];
  v34 = 0i64;
  v6 = jobInOut;
  v7 = jobQueue;
  *(_OWORD *)&in.m_subStepDeltaTime.m_storage = v3;
  v8 = *(_OWORD *)&tl->m_constraintQueryIn.m_rhsFactor.m_storage;
  *(_OWORD *)&in.m_frameInvDeltaTime.m_storage = v4;
  v9 = *(_OWORD *)&tl->m_constraintQueryIn.m_bodyA.m_storage;
  *(_OWORD *)&in.m_rhsFactor.m_storage = v8;
  *(_OWORD *)&in.m_transformA.m_storage = *(_OWORD *)&tl->m_constraintQueryIn.m_transformA.m_storage;
  v10.m_real = (__m128)tl->m_constraintQueryIn.m_maxConstraintViolationSqrd;
  *(_OWORD *)&in.m_bodyA.m_storage = v9;
  v11 = *(_OWORD *)&tl->m_constraintQueryIn.m_tau.m_storage;
  in.m_maxConstraintViolationSqrd = (hkSimdFloat32)v10.m_real;
  v12 = *(_OWORD *)&tl->m_constraintQueryIn.m_accumulatorAIndex.m_storage;
  *(_OWORD *)&in.m_tau.m_storage = v11;
  v13 = *(_OWORD *)&tl->m_constraintQueryIn.m_constraintInstance.m_storage;
  *(_OWORD *)&in.m_accumulatorAIndex.m_storage = v12;
  *(_OWORD *)&in.m_constraintInstance.m_storage = v13;
  if ( *(_DWORD *)(v5 + 176) > 0 )
  {
    v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v15 = v14[1];
    v16 = v14;
    if ( v15 < v14[3] )
    {
      *(_QWORD *)v15 = "LtIntegrate";
      *(_QWORD *)(v15 + 16) = "StConstraintCallbacks";
      v17 = __rdtsc();
      *(_DWORD *)(v15 + 8) = v17;
      v16[1] = v15 + 24;
    }
    v18 = 0;
    if ( *(_DWORD *)(v5 + 176) > 0 )
    {
      v19 = 0i64;
      do
      {
        v20 = *(_QWORD *)(v19 + *(_QWORD *)(v5 + 168));
        in.m_constraintInstance.m_storage = *(hkpConstraintInstance **)v20;
        v35 = *(_QWORD *)(v20 + 48);
        in.m_bodyA.m_storage = (hkpVelocityAccumulator *)(*(_QWORD *)(v5 + 64)
                                                        + *(unsigned int *)(*(_QWORD *)(v20 + 8) + 240i64));
        in.m_bodyB.m_storage = (hkpVelocityAccumulator *)(*(_QWORD *)(v5 + 64)
                                                        + *(unsigned int *)(*(_QWORD *)(v20 + 16) + 240i64));
        in.m_transformA.m_storage = *(hkTransformf **)(*(_QWORD *)(*(_QWORD *)v20 + 40i64) + 48i64);
        in.m_transformB.m_storage = *(hkTransformf **)(*(_QWORD *)(*(_QWORD *)v20 + 48i64) + 48i64);
        if ( *(_BYTE *)(v20 + 34) & 9 )
        {
          v21 = *(_QWORD *)(v20 + 24);
          for ( i = *(_QWORD *)(*(_QWORD *)v20 + 32i64); *(_WORD *)v21 >= 0x1Eu; v21 = *(_QWORD *)(v21 + 24) )
            ;
          hkSimpleContactConstraintData_fireCallbacks(
            *(hkpSimpleContactConstraintData **)(*(_QWORD *)v20 + 24i64),
            &in,
            (hkpSimpleContactConstraintAtom *)v21,
            (hkpContactPointEvent::Type)2);
          v23 = *(_QWORD *)(*(_QWORD *)v20 + 32i64);
          if ( i != v23 )
          {
            v24 = *(_QWORD *)(v19 + *(_QWORD *)(v5 + 168) + 8);
            *(_QWORD *)v24 = v23;
            *(_WORD *)(v24 + 40) = *(_WORD *)(v23 + 16);
          }
        }
        if ( *(_BYTE *)(v20 + 34) & 4 )
          (*(void (__fastcall **)(_QWORD, hkpConstraintQueryIn *, __int64 *))(**(_QWORD **)(*(_QWORD *)v20 + 24i64)
                                                                            + 176i64))(
            *(_QWORD *)(*(_QWORD *)v20 + 24i64),
            &in,
            &v34);
        ++v18;
        v19 += 16i64;
      }
      while ( v18 < *(_DWORD *)(v5 + 176) );
    }
    v25 = *(_DWORD *)(v5 + 176);
    v26 = *(_QWORD *)(v5 + 168);
    v27 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    (*(void (__fastcall **)(_QWORD *, __int64, _QWORD))(*v27[11] + 16i64))(v27[11], v26, (unsigned int)(16 * v25));
    *(_QWORD *)(v5 + 168) = 0i64;
    *(_DWORD *)(v5 + 176) = 0;
    v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v29 = (_QWORD *)v28[1];
    v30 = v28;
    if ( (unsigned __int64)v29 < v28[3] )
    {
      *v29 = "lt";
      v31 = __rdtsc();
      v32 = (signed __int64)(v29 + 2);
      *(_DWORD *)(v32 - 8) = v31;
      v30[1] = v32;
    }
  }
  return hkJobQueue::finishJobAndGetNextJob(v7, v6, v6, 0);
}

