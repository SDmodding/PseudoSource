// File Line: 15
// RVA: 0xC0E220
__int64 __fastcall hkaiProcessBehaviorCalcVelocitiesJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  _QWORD *Value; // rax
  unsigned __int64 v4; // rdx
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  __int64 v9; // r15
  __int64 v10; // r12
  unsigned int v11; // r13d
  __int64 i; // rbp
  int v13; // ebx
  hkaiWorld **v14; // rdi
  int v15; // esi
  hkaiCharacter *v16; // rax
  unsigned __int64 v17; // rdx
  _QWORD *v18; // r8
  unsigned __int64 v19; // rcx
  unsigned __int64 v20; // rax
  int v21; // eax
  _QWORD *v22; // rax
  _QWORD *v23; // rcx
  unsigned __int64 v24; // rax
  _QWORD *v25; // rcx
  hkJobQueue::JobStatus NextJob; // ebx
  _QWORD *v27; // rax
  _QWORD *v28; // rcx
  _QWORD *v29; // r8
  unsigned __int64 v30; // rax
  _QWORD *v31; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  v6 = Value;
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtCalcVelocities Job";
    v7 = __rdtsc();
    v4 = (unsigned __int64)HIDWORD(v7) << 32;
    v8 = v5 + 2;
    *((_DWORD *)v8 - 2) = v7;
    v6[1] = v8;
  }
  v9 = *(int *)&nextJobOut->m_data[24];
  v10 = *(_QWORD *)&nextJobOut->m_data[32];
  v11 = *(_DWORD *)&nextJobOut->m_data[40];
  for ( i = 0i64; i < v9; ++i )
  {
    v13 = 0;
    v14 = *(hkaiWorld ***)(*(_QWORD *)&nextJobOut->m_data[16] + 8 * i);
    v15 = ((__int64 (__fastcall *)(hkaiWorld **, unsigned __int64, _QWORD *))(*v14)->m_silhouetteGenerationParameters.m_referenceFrame.m_up.m_quad.m128_u64[0])(
            v14,
            v4,
            v6);
    if ( v15 > 0 )
    {
      do
      {
        v16 = (hkaiCharacter *)((__int64 (__fastcall *)(hkaiWorld **, _QWORD))(*v14)->m_silhouetteGenerationParameters.m_referenceFrame.m_up.m_quad.m128_u64[1])(
                                 v14,
                                 (unsigned int)v13);
        if ( v16->m_state.m_storage != 7 )
          hkaiWorld::updateMeshFaceForCharacter(v14[3], v16);
        ++v13;
      }
      while ( v13 < v15 );
    }
    v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v19 = v18[1];
    if ( v19 < v18[3] )
    {
      *(_QWORD *)v19 = "TtcalcVelocities";
      v20 = __rdtsc();
      v17 = v19 + 16;
      *(_DWORD *)(v19 + 8) = v20;
      v18[1] = v19 + 16;
    }
    v21 = ((__int64 (__fastcall *)(hkaiWorld **, unsigned __int64, __int64, _QWORD))(*v14)->m_up.m_quad.m128_u64[1])(
            v14,
            v17,
            v10,
            v11);
    v11 -= v21;
    v10 += 160i64 * v21;
    v22 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v23 = (_QWORD *)v22[1];
    v6 = v22;
    if ( (unsigned __int64)v23 < v22[3] )
    {
      *v23 = "Et";
      v24 = __rdtsc();
      v4 = (unsigned __int64)HIDWORD(v24) << 32;
      v25 = v23 + 2;
      *((_DWORD *)v25 - 2) = v24;
      v6[1] = v25;
    }
  }
  NextJob = hkJobQueue::finishJobAndGetNextJob(jobQueue, nextJobOut, nextJobOut, WAIT_FOR_NEXT_JOB);
  v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v28 = (_QWORD *)v27[1];
  v29 = v27;
  if ( (unsigned __int64)v28 < v27[3] )
  {
    *v28 = "Et";
    v30 = __rdtsc();
    v31 = v28 + 2;
    *((_DWORD *)v31 - 2) = v30;
    v29[1] = v31;
  }
  return (unsigned int)NextJob;
}

