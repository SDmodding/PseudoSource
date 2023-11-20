// File Line: 23
// RVA: 0xD2FEF0
float __fastcall hkCpuWorldGetClosestPointsCollector::addBroadPhaseHandle(hkCpuWorldGetClosestPointsCollector *this, hkpBroadPhaseHandle *broadphaseHandle, int castIndex)
{
  hkCpuWorldGetClosestPointsCollector *v3; // rbx
  hkpCollidable *v4; // rdi
  hkpShape *v5; // rsi
  hkpCollidable *v6; // r8
  hkpFixedBufferCdPointCollector *v7; // rax
  char v9; // [rsp+30h] [rbp+8h]

  v3 = this;
  v4 = (hkpCollidable *)((char *)broadphaseHandle + SBYTE1(broadphaseHandle[1].m_id));
  v5 = v4->m_shape;
  if ( v4->m_shape && (v6 = this->m_collidable, v6 != v4) )
  {
    if ( *(_BYTE *)this->m_filter->vfptr->isCollisionEnabled(
                     (hkpCollidableCollidableFilter *)&this->m_filter->vfptr,
                     (hkBool *)&v9,
                     v6,
                     v4) )
      (*((void (__fastcall **)(hkpCollidable *, hkpCollidable *, hkpLinearCastCollisionInput *, hkpFixedBufferCdPointCollector *))&v3->m_input.m_dispatcher.m_storage->vfptr
       + 5
       * ((unsigned __int8)v3->m_input.m_dispatcher.m_storage->m_agent2Types[v3->m_shapeType][(unsigned __int8)v5->m_type.m_storage]
        + 79i64)))(
        v3->m_collidable,
        v4,
        &v3->m_input,
        v3->m_castCollector);
    v7 = v3->m_castCollector;
  }
  else
  {
    v7 = this->m_castCollector;
  }
  return v7->m_earlyOutDistance;
}

// File Line: 42
// RVA: 0xD2FFA0
__int64 __fastcall hkCpuWorldGetClosestPointsJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  hkJobQueue *v2; // r13
  hkJobQueue::JobQueueEntry *v3; // rsi
  _QWORD *v4; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  __int64 v9; // rcx
  __int64 v10; // r12
  int v11; // er15
  __int64 v12; // r14
  __int64 v13; // rdi
  float v14; // xmm2_4
  __int64 v15; // rax
  unsigned int v16; // ecx
  __int64 v17; // rax
  __int64 v18; // rdx
  unsigned __int8 *v19; // rbx
  float v20; // xmm2_4
  int v21; // xmm0_4
  int v22; // eax
  _QWORD *v23; // rax
  _QWORD *v24; // rcx
  _QWORD *v25; // r8
  unsigned __int64 v26; // rax
  signed __int64 v27; // rcx
  void **v29; // [rsp+20h] [rbp-C8h]
  int v30; // [rsp+28h] [rbp-C0h]
  __int64 v31; // [rsp+30h] [rbp-B8h]
  __int64 v32; // [rsp+38h] [rbp-B0h]
  void **v33; // [rsp+40h] [rbp-A8h]
  __int64 v34; // [rsp+48h] [rbp-A0h]
  void ***v35; // [rsp+50h] [rbp-98h]
  __int64 v36; // [rsp+58h] [rbp-90h]
  int v37; // [rsp+60h] [rbp-88h]
  int v38; // [rsp+68h] [rbp-80h]
  __int64 v39; // [rsp+70h] [rbp-78h]
  __int64 v40; // [rsp+78h] [rbp-70h]
  int v41; // [rsp+80h] [rbp-68h]
  __int128 v42; // [rsp+88h] [rbp-60h]
  __int128 v43; // [rsp+98h] [rbp-50h]
  __int128 v44; // [rsp+A8h] [rbp-40h]
  float v45; // [rsp+C8h] [rbp-20h]
  __int64 v46; // [rsp+D0h] [rbp-18h]
  char v47; // [rsp+D8h] [rbp-10h]
  hkJobQueue *v48; // [rsp+138h] [rbp+50h]

  v2 = jobQueue;
  v3 = nextJobOut;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  v6 = v4;
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtCollQueryWorldGetClosestPoints";
    v7 = __rdtsc();
    v8 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v8 - 8) = v7;
    v6[1] = v8;
  }
  v9 = *(_QWORD *)&v3->m_data[16];
  v10 = *(_QWORD *)&v3->m_data[32];
  v32 = 1i64;
  v30 = 2139095022;
  v45 = FLOAT_1_1920929eN7;
  v29 = &hkpFixedBufferCdPointCollector::`vftable';
  v31 = 0i64;
  v11 = 0;
  v33 = &hkCpuWorldGetClosestPointsCollector::`vftable';
  v34 = *(_QWORD *)(v9 + 24);
  v35 = &v29;
  v39 = *(_QWORD *)v9;
  v40 = *(unsigned int *)(v9 + 8);
  HIDWORD(v40) = *(_DWORD *)(v9 + 12);
  v38 = *(_DWORD *)(v9 + 16);
  v39 = *(_QWORD *)(v9 + 24);
  v40 = *(_QWORD *)(v9 + 32);
  v41 = *(_DWORD *)(v9 + 40);
  v42 = *(_OWORD *)(v9 + 48);
  v43 = *(_OWORD *)(v9 + 64);
  v44 = *(_OWORD *)(v9 + 80);
  v46 = *(_QWORD *)(v9 + 144);
  if ( *(_DWORD *)&v3->m_data[56] > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = *(_QWORD *)&v3->m_data[48];
      v14 = *(float *)&v3->m_data[40];
      v15 = *(_QWORD *)(v12 + v13 + 8);
      v16 = *(_DWORD *)(v12 + v13 + 16);
      v29 = &hkpFixedBufferCdPointCollector::`vftable';
      v31 = v15;
      v17 = *(_QWORD *)&v3->m_data[16];
      v32 = v16;
      v30 = 2139095022;
      v18 = *(_QWORD *)(v12 + v13);
      v19 = *(unsigned __int8 **)v18;
      v20 = v14 - (float)(*(float *)(v17 + 16) * 0.5);
      (*(void (__fastcall **)(unsigned __int8 *, _QWORD, _QWORD, char *))(*(_QWORD *)v19 + 32i64))(
        v19,
        *(_QWORD *)(v18 + 16),
        *(_QWORD *)v19,
        &v47);
      v21 = *(_DWORD *)&v3->m_data[40];
      v36 = *(_QWORD *)(v12 + v13);
      v22 = v19[16];
      v38 = v21;
      v37 = v22;
      (*(void (__fastcall **)(__int64, char *, void ***))(*(_QWORD *)v10 + 160i64))(v10, &v47, &v33);
      ++v11;
      *(_DWORD *)(v12 + v13 + 20) = HIDWORD(v32);
      v12 += 24i64;
    }
    while ( v11 < *(_DWORD *)&v3->m_data[56] );
    v2 = v48;
  }
  v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v24 = (_QWORD *)v23[1];
  v25 = v23;
  if ( (unsigned __int64)v24 < v23[3] )
  {
    *v24 = "Et";
    v26 = __rdtsc();
    v27 = (signed __int64)(v24 + 2);
    *(_DWORD *)(v27 - 8) = v26;
    v25[1] = v27;
  }
  return hkJobQueue::finishJobAndGetNextJob(v2, v3, v3, 0);
}

