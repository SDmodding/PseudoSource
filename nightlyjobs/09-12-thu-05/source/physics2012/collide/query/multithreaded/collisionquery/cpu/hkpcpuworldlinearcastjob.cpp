// File Line: 30
// RVA: 0xD30B90
float __fastcall hkCpuWorldLinearCastCollector::addBroadPhaseHandle(hkCpuWorldLinearCastCollector *this, hkpBroadPhaseHandle *broadPhaseHandle, int castIndex)
{
  hkCpuWorldLinearCastCollector *v3; // rbx
  hkpCollidable *v4; // rdi
  hkpShape *v5; // rsi
  hkpCollidable *v6; // r8
  hkpFixedBufferCdPointCollector *v7; // rax
  char v9; // [rsp+40h] [rbp+8h]

  v3 = this;
  v4 = (hkpCollidable *)((char *)broadPhaseHandle + SBYTE1(broadPhaseHandle[1].m_id));
  v5 = v4->m_shape;
  if ( v4->m_shape && (v6 = this->m_collidable, v6 != v4) )
  {
    if ( *(_BYTE *)this->m_filter->vfptr->isCollisionEnabled(
                     (hkpCollidableCollidableFilter *)&this->m_filter->vfptr,
                     (hkBool *)&v9,
                     v6,
                     v4) )
      v3->m_input.m_dispatcher.m_storage->m_agent2Func[(unsigned __int8)v3->m_input.m_dispatcher.m_storage->m_agent2Types[v3->m_shapeType][(unsigned __int8)v5->m_type.m_storage]].m_linearCastFunc(
        (hkpCdBody *)&v3->m_collidable->m_shape,
        (hkpCdBody *)&v4->m_shape,
        &v3->m_input,
        (hkpCdPointCollector *)&v3->m_castCollector->vfptr,
        0i64);
    v7 = v3->m_castCollector;
  }
  else
  {
    v7 = this->m_castCollector;
  }
  return v7->m_earlyOutDistance;
}

// File Line: 61
// RVA: 0xD30850
__int64 __fastcall hkCpuWorldLinearCastJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  hkJobQueue *v2; // r14
  hkJobQueue::JobQueueEntry *v3; // rdi
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  __int64 v8; // rcx
  int v9; // er15
  __int64 v10; // rsi
  __int64 v11; // rbx
  unsigned int v12; // ecx
  __int64 v13; // rax
  __m128 v14; // xmm6
  __m128 v15; // xmm1
  int v16; // xmm5_4
  __m128 v17; // xmm4
  __m128 v18; // xmm1
  __int128 v19; // xmm2
  __int64 v20; // rcx
  _QWORD *v21; // rax
  _QWORD *v22; // rcx
  _QWORD *v23; // r8
  unsigned __int64 v24; // rax
  signed __int64 v25; // rcx
  void **v27; // [rsp+20h] [rbp-C8h]
  int v28; // [rsp+28h] [rbp-C0h]
  __int64 v29; // [rsp+30h] [rbp-B8h]
  __int64 v30; // [rsp+38h] [rbp-B0h]
  void **v31; // [rsp+40h] [rbp-A8h]
  __int64 v32; // [rsp+48h] [rbp-A0h]
  void ***v33; // [rsp+50h] [rbp-98h]
  __int64 v34; // [rsp+58h] [rbp-90h]
  int v35; // [rsp+60h] [rbp-88h]
  int v36; // [rsp+68h] [rbp-80h]
  __int64 v37; // [rsp+70h] [rbp-78h]
  __int64 v38; // [rsp+78h] [rbp-70h]
  int v39; // [rsp+80h] [rbp-68h]
  __int128 v40; // [rsp+88h] [rbp-60h]
  __int128 v41; // [rsp+98h] [rbp-50h]
  __int128 v42; // [rsp+A8h] [rbp-40h]
  __m128 v43; // [rsp+B8h] [rbp-30h]
  float v44; // [rsp+C8h] [rbp-20h]
  int v45; // [rsp+CCh] [rbp-1Ch]
  __int64 v46; // [rsp+D0h] [rbp-18h]
  __m128 v47; // [rsp+D8h] [rbp-10h]
  __m128 v48; // [rsp+E8h] [rbp+0h]
  __m128 v49; // [rsp+F8h] [rbp+10h]
  __m128 v50; // [rsp+108h] [rbp+20h]
  __m128 v51; // [rsp+118h] [rbp+30h]
  __int64 v52; // [rsp+128h] [rbp+40h]

  v2 = jobQueue;
  v3 = nextJobOut;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtCollQueryWorldLinearCast";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  v8 = *(_QWORD *)&v3->m_data[16];
  v30 = 1i64;
  v28 = 2139095022;
  v44 = FLOAT_1_1920929eN7;
  v29 = 0i64;
  v31 = &hkCpuWorldLinearCastCollector::`vftable;
  v9 = 0;
  v27 = &hkpFixedBufferCdPointCollector::`vftable;
  v32 = *(_QWORD *)(v8 + 24);
  v33 = &v27;
  v37 = *(_QWORD *)v8;
  v38 = *(unsigned int *)(v8 + 8);
  HIDWORD(v38) = *(_DWORD *)(v8 + 12);
  v36 = *(_DWORD *)(v8 + 16);
  v37 = *(_QWORD *)(v8 + 24);
  v38 = *(_QWORD *)(v8 + 32);
  v39 = *(_DWORD *)(v8 + 40);
  v40 = *(_OWORD *)(v8 + 48);
  v41 = *(_OWORD *)(v8 + 64);
  v42 = *(_OWORD *)(v8 + 80);
  v46 = *(_QWORD *)(v8 + 144);
  if ( *(_DWORD *)&v3->m_data[48] > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = *(_QWORD *)&v3->m_data[40];
      v52 = 0i64;
      v12 = *(_DWORD *)(v10 + v11 + 48);
      v13 = *(_QWORD *)(v10 + v11 + 40);
      v27 = &hkpFixedBufferCdPointCollector::`vftable;
      v29 = v13;
      v30 = v12;
      v28 = 2139095022;
      v14 = _mm_sub_ps(*(__m128 *)(v10 + v11), *(__m128 *)(*(_QWORD *)(*(_QWORD *)(v10 + v11 + 32) + 16i64) + 48i64));
      v34 = *(_QWORD *)(v10 + v11 + 32);
      v15 = _mm_mul_ps(v14, v14);
      v35 = *(unsigned __int8 *)(**(_QWORD **)(v10 + v11 + 32) + 16i64);
      v44 = *(float *)(v10 + v11 + 16);
      v16 = *(_DWORD *)(v10 + v11 + 20);
      v43 = v14;
      v36 = v16;
      v17 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
              _mm_shuffle_ps(v15, v15, 170));
      v18 = _mm_rsqrt_ps(v17);
      v45 = (unsigned __int128)_mm_andnot_ps(
                                 _mm_cmpleps(v17, (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                                     _mm_mul_ps(*(__m128 *)_xmm, v18)),
                                   v17));
      v19 = *(unsigned int *)(v10 + v11 + 20);
      (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD *, __m128 *))(***(_QWORD ***)(v10 + v11 + 32) + 32i64))(
        **(_QWORD **)(v10 + v11 + 32),
        *(_QWORD *)(*(_QWORD *)(v10 + v11 + 32) + 16i64),
        v4,
        &v47);
      v20 = *(_QWORD *)&v3->m_data[56];
      v52 = 0i64;
      v51 = _mm_mul_ps(_mm_sub_ps(v48, v47), (__m128)xmmword_141A711B0);
      v49 = _mm_add_ps(v51, v47);
      v50 = _mm_add_ps(v49, v14);
      (*(void (__fastcall **)(__int64, __m128 *, void ***))(*(_QWORD *)v20 + 232i64))(v20, &v49, &v31);
      ++v9;
      *(_DWORD *)(v10 + v11 + 52) = HIDWORD(v30);
      v10 += 64i64;
    }
    while ( v9 < *(_DWORD *)&v3->m_data[48] );
  }
  v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v22 = (_QWORD *)v21[1];
  v23 = v21;
  if ( (unsigned __int64)v22 < v21[3] )
  {
    *v22 = "Et";
    v24 = __rdtsc();
    v25 = (signed __int64)(v22 + 2);
    *(_DWORD *)(v25 - 8) = v24;
    v23[1] = v25;
  }
  return hkJobQueue::finishJobAndGetNextJob(v2, v3, v3, 0);
}

