// File Line: 15
// RVA: 0xC0E220
__int64 __fastcall hkaiProcessBehaviorCalcVelocitiesJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  hkJobQueue::JobQueueEntry *v2; // r14
  _QWORD *v3; // rax
  unsigned __int64 v4; // rdx
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  __int64 v9; // r15
  __int64 v10; // r12
  unsigned int v11; // er13
  __int64 i; // rbp
  unsigned int v13; // ebx
  hkaiWorld **v14; // rdi
  int v15; // esi
  hkaiCharacter *v16; // rax
  signed __int64 v17; // rdx
  _QWORD *v18; // r8
  unsigned __int64 v19; // rcx
  unsigned __int64 v20; // rax
  __int128 v21; // xmm1
  int v22; // eax
  _QWORD *v23; // rax
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  hkJobQueue::JobStatus v27; // ebx
  _QWORD *v28; // rax
  _QWORD *v29; // rcx
  _QWORD *v30; // r8
  unsigned __int64 v31; // rax
  signed __int64 v32; // rcx
  hkJobQueue *v34; // [rsp+50h] [rbp+8h]

  v34 = jobQueue;
  v2 = nextJobOut;
  v3 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v3[1];
  v6 = v3;
  if ( (unsigned __int64)v5 < v3[3] )
  {
    *v5 = "TtCalcVelocities Job";
    v7 = __rdtsc();
    v4 = (unsigned __int64)HIDWORD(v7) << 32;
    v8 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v8 - 8) = v7;
    v6[1] = v8;
  }
  v9 = *(signed int *)&v2->m_data[24];
  v10 = *(_QWORD *)&v2->m_data[32];
  v11 = *(_DWORD *)&v2->m_data[40];
  for ( i = 0i64; i < v9; ++i )
  {
    v13 = 0;
    v14 = *(hkaiWorld ***)(*(_QWORD *)&v2->m_data[16] + 8 * i);
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
                                 v13);
        if ( v16->m_state.m_storage != 7 )
          hkaiWorld::updateMeshFaceForCharacter(v14[3], v16);
        ++v13;
      }
      while ( (signed int)v13 < v15 );
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
    v21 = *(unsigned int *)&v2->m_data[44];
    v22 = ((__int64 (__fastcall *)(hkaiWorld **, signed __int64, __int64, _QWORD))(*v14)->m_up.m_quad.m128_u64[1])(
            v14,
            v17,
            v10,
            v11);
    v11 -= v22;
    v10 += 160i64 * v22;
    v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v24 = (_QWORD *)v23[1];
    v6 = v23;
    if ( (unsigned __int64)v24 < v23[3] )
    {
      *v24 = "Et";
      v25 = __rdtsc();
      v4 = (unsigned __int64)HIDWORD(v25) << 32;
      v26 = (signed __int64)(v24 + 2);
      *(_DWORD *)(v26 - 8) = v25;
      v6[1] = v26;
    }
  }
  v27 = hkJobQueue::finishJobAndGetNextJob(v34, v2, v2, 0);
  v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v29 = (_QWORD *)v28[1];
  v30 = v28;
  if ( (unsigned __int64)v29 < v28[3] )
  {
    *v29 = "Et";
    v31 = __rdtsc();
    v32 = (signed __int64)(v29 + 2);
    *(_DWORD *)(v32 - 8) = v31;
    v30[1] = v32;
  }
  return v27;
}

