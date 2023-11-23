// File Line: 23
// RVA: 0xD2FEF0
float __fastcall hkCpuWorldGetClosestPointsCollector::addBroadPhaseHandle(
        hkCpuWorldGetClosestPointsCollector *this,
        hkpBroadPhaseHandle *broadphaseHandle,
        int castIndex)
{
  hkpCollidable *v4; // rdi
  hkpShape *m_shape; // rsi
  hkpCollidable *m_collidable; // r8
  hkpFixedBufferCdPointCollector *m_castCollector; // rax
  char v9; // [rsp+30h] [rbp+8h] BYREF

  v4 = (hkpCollidable *)((char *)broadphaseHandle + SBYTE1(broadphaseHandle[1].m_id));
  m_shape = v4->m_shape;
  if ( !v4->m_shape || (m_collidable = this->m_collidable, m_collidable == v4) )
  {
    m_castCollector = this->m_castCollector;
  }
  else
  {
    if ( this->m_filter->vfptr->isCollisionEnabled(
           &this->m_filter->hkpCollidableCollidableFilter,
           &v9,
           m_collidable,
           v4)->m_bool )
      this->m_input.m_dispatcher.m_storage->m_agent2Func[(unsigned __int8)this->m_input.m_dispatcher.m_storage->m_agent2Types[this->m_shapeType][(unsigned __int8)m_shape->m_type.m_storage]].m_getClosestPointFunc(
        this->m_collidable,
        v4,
        &this->m_input,
        this->m_castCollector);
    m_castCollector = this->m_castCollector;
  }
  return m_castCollector->m_earlyOutDistance;
}

// File Line: 42
// RVA: 0xD2FFA0
__int64 __fastcall hkCpuWorldGetClosestPointsJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  _QWORD *Value; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  __int64 v9; // rcx
  __int64 v10; // r12
  int v11; // r15d
  __int64 v12; // r14
  __int64 v13; // rdi
  __int64 v14; // rax
  unsigned int v15; // ecx
  __int64 v16; // rdx
  unsigned __int8 *v17; // rbx
  int v18; // xmm0_4
  int v19; // eax
  _QWORD *v20; // rax
  _QWORD *v21; // rcx
  _QWORD *v22; // r8
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  void **v26; // [rsp+20h] [rbp-C8h] BYREF
  int v27; // [rsp+28h] [rbp-C0h]
  __int64 v28; // [rsp+30h] [rbp-B8h]
  __int64 v29; // [rsp+38h] [rbp-B0h]
  void **v30; // [rsp+40h] [rbp-A8h] BYREF
  __int64 v31; // [rsp+48h] [rbp-A0h]
  void ***v32; // [rsp+50h] [rbp-98h]
  __int64 v33; // [rsp+58h] [rbp-90h]
  int v34; // [rsp+60h] [rbp-88h]
  int v35; // [rsp+68h] [rbp-80h]
  __int64 v36; // [rsp+70h] [rbp-78h]
  __int64 v37; // [rsp+78h] [rbp-70h]
  int v38; // [rsp+80h] [rbp-68h]
  __int128 v39; // [rsp+88h] [rbp-60h]
  __int128 v40; // [rsp+98h] [rbp-50h]
  __int128 v41; // [rsp+A8h] [rbp-40h]
  float v42; // [rsp+C8h] [rbp-20h]
  __int64 v43; // [rsp+D0h] [rbp-18h]
  char v44[56]; // [rsp+D8h] [rbp-10h] BYREF
  hkJobQueue *v45; // [rsp+138h] [rbp+50h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  v6 = Value;
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtCollQueryWorldGetClosestPoints";
    v7 = __rdtsc();
    v8 = v5 + 2;
    *((_DWORD *)v8 - 2) = v7;
    v6[1] = v8;
  }
  v9 = *(_QWORD *)&nextJobOut->m_data[16];
  v10 = *(_QWORD *)&nextJobOut->m_data[32];
  v29 = 1i64;
  v27 = 2139095022;
  v42 = FLOAT_1_1920929eN7;
  v26 = &hkpFixedBufferCdPointCollector::`vftable;
  v28 = 0i64;
  v11 = 0;
  v30 = &hkCpuWorldGetClosestPointsCollector::`vftable;
  v31 = *(_QWORD *)(v9 + 24);
  v32 = &v26;
  v36 = *(_QWORD *)v9;
  v37 = *(unsigned int *)(v9 + 8);
  HIDWORD(v37) = *(_DWORD *)(v9 + 12);
  v35 = *(_DWORD *)(v9 + 16);
  v36 = *(_QWORD *)(v9 + 24);
  v37 = *(_QWORD *)(v9 + 32);
  v38 = *(_DWORD *)(v9 + 40);
  v39 = *(_OWORD *)(v9 + 48);
  v40 = *(_OWORD *)(v9 + 64);
  v41 = *(_OWORD *)(v9 + 80);
  v43 = *(_QWORD *)(v9 + 144);
  if ( *(int *)&nextJobOut->m_data[56] > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = *(_QWORD *)&nextJobOut->m_data[48];
      v14 = *(_QWORD *)(v12 + v13 + 8);
      v15 = *(_DWORD *)(v12 + v13 + 16);
      v26 = &hkpFixedBufferCdPointCollector::`vftable;
      v28 = v14;
      v29 = v15;
      v27 = 2139095022;
      v16 = *(_QWORD *)(v12 + v13);
      v17 = *(unsigned __int8 **)v16;
      (*(void (__fastcall **)(unsigned __int8 *, _QWORD, _QWORD, char *, void **, int, __int64, _QWORD, void **, __int64, void ***))(*(_QWORD *)v17 + 32i64))(
        v17,
        *(_QWORD *)(v16 + 16),
        *(_QWORD *)v17,
        v44,
        &hkpFixedBufferCdPointCollector::`vftable,
        2139095022,
        v14,
        v15,
        v30,
        v31,
        v32);
      v18 = *(_DWORD *)&nextJobOut->m_data[40];
      v33 = *(_QWORD *)(v12 + v13);
      v19 = v17[16];
      v35 = v18;
      v34 = v19;
      (*(void (__fastcall **)(__int64, char *, void ***))(*(_QWORD *)v10 + 160i64))(v10, v44, &v30);
      ++v11;
      *(_DWORD *)(v12 + v13 + 20) = HIDWORD(v29);
      v12 += 24i64;
    }
    while ( v11 < *(_DWORD *)&nextJobOut->m_data[56] );
    jobQueue = v45;
  }
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  v22 = v20;
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "Et";
    v23 = __rdtsc();
    v24 = v21 + 2;
    *((_DWORD *)v24 - 2) = v23;
    v22[1] = v24;
  }
  return hkJobQueue::finishJobAndGetNextJob(jobQueue, nextJobOut, nextJobOut, WAIT_FOR_NEXT_JOB);
}

