// File Line: 30
// RVA: 0xD30B90
float __fastcall hkCpuWorldLinearCastCollector::addBroadPhaseHandle(
        hkCpuWorldLinearCastCollector *this,
        hkpBroadPhaseHandle *broadPhaseHandle,
        int castIndex)
{
  hkpCollidable *v4; // rdi
  hkpShape *m_shape; // rsi
  hkpCollidable *m_collidable; // r8
  hkpFixedBufferCdPointCollector *m_castCollector; // rax
  char v9; // [rsp+40h] [rbp+8h] BYREF

  v4 = (hkpCollidable *)((char *)broadPhaseHandle + SBYTE1(broadPhaseHandle[1].m_id));
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
      this->m_input.m_dispatcher.m_storage->m_agent2Func[(unsigned __int8)this->m_input.m_dispatcher.m_storage->m_agent2Types[this->m_shapeType][(unsigned __int8)m_shape->m_type.m_storage]].m_linearCastFunc(
        this->m_collidable,
        v4,
        &this->m_input,
        this->m_castCollector,
        0i64);
    m_castCollector = this->m_castCollector;
  }
  return m_castCollector->m_earlyOutDistance;
}

// File Line: 61
// RVA: 0xD30850
__int64 __fastcall hkCpuWorldLinearCastJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  __int64 v8; // rcx
  int v9; // r15d
  __int64 v10; // rsi
  __int64 v11; // rbx
  unsigned int v12; // ecx
  __int64 v13; // rax
  __m128 v14; // xmm6
  __m128 v15; // xmm1
  int v16; // xmm5_4
  __m128 v17; // xmm4
  __m128 v18; // xmm1
  __int64 v19; // rcx
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
  __m128 v42; // [rsp+B8h] [rbp-30h]
  __int64 v43; // [rsp+C8h] [rbp-20h]
  __int64 v44; // [rsp+D0h] [rbp-18h]
  __m128 v45[2]; // [rsp+D8h] [rbp-10h] BYREF
  __m128 v46[2]; // [rsp+F8h] [rbp+10h] BYREF
  __m128 v47; // [rsp+118h] [rbp+30h]
  __int64 v48; // [rsp+128h] [rbp+40h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtCollQueryWorldLinearCast";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  v8 = *(_QWORD *)&nextJobOut->m_data[16];
  v29 = 1i64;
  v27 = 2139095022;
  *(float *)&v43 = FLOAT_1_1920929eN7;
  v28 = 0i64;
  v30 = &hkCpuWorldLinearCastCollector::`vftable;
  v9 = 0;
  v26 = &hkpFixedBufferCdPointCollector::`vftable;
  v31 = *(_QWORD *)(v8 + 24);
  v32 = &v26;
  v36 = *(_QWORD *)v8;
  v37 = *(unsigned int *)(v8 + 8);
  HIDWORD(v37) = *(_DWORD *)(v8 + 12);
  v35 = *(_DWORD *)(v8 + 16);
  v36 = *(_QWORD *)(v8 + 24);
  v37 = *(_QWORD *)(v8 + 32);
  v38 = *(_DWORD *)(v8 + 40);
  v39 = *(_OWORD *)(v8 + 48);
  v40 = *(_OWORD *)(v8 + 64);
  v41 = *(_OWORD *)(v8 + 80);
  v44 = *(_QWORD *)(v8 + 144);
  if ( *(int *)&nextJobOut->m_data[48] > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = *(_QWORD *)&nextJobOut->m_data[40];
      v48 = 0i64;
      v12 = *(_DWORD *)(v10 + v11 + 48);
      v13 = *(_QWORD *)(v10 + v11 + 40);
      v26 = &hkpFixedBufferCdPointCollector::`vftable;
      v28 = v13;
      v29 = v12;
      v27 = 2139095022;
      v14 = _mm_sub_ps(*(__m128 *)(v10 + v11), *(__m128 *)(*(_QWORD *)(*(_QWORD *)(v10 + v11 + 32) + 16i64) + 48i64));
      v33 = *(_QWORD *)(v10 + v11 + 32);
      v15 = _mm_mul_ps(v14, v14);
      v34 = *(unsigned __int8 *)(**(_QWORD **)(v10 + v11 + 32) + 16i64);
      LODWORD(v43) = *(_DWORD *)(v10 + v11 + 16);
      v16 = *(_DWORD *)(v10 + v11 + 20);
      v42 = v14;
      v35 = v16;
      v17 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
              _mm_shuffle_ps(v15, v15, 170));
      v18 = _mm_rsqrt_ps(v17);
      HIDWORD(v43) = _mm_andnot_ps(
                       _mm_cmple_ps(v17, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v18, v17), v18)),
                           _mm_mul_ps(*(__m128 *)_xmm, v18)),
                         v17)).m128_u32[0];
      (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD *, __m128 *, void **, int, __int64, _QWORD, void **, __int64, void ***, __int64, int, int, __int64, __int64, int, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, unsigned __int64, unsigned __int64, __int64, __int64))(***(_QWORD ***)(v10 + v11 + 32) + 32i64))(
        **(_QWORD **)(v10 + v11 + 32),
        *(_QWORD *)(*(_QWORD *)(v10 + v11 + 32) + 16i64),
        Value,
        v45,
        &hkpFixedBufferCdPointCollector::`vftable,
        2139095022,
        v13,
        v12,
        v30,
        v31,
        v32,
        v33,
        v34,
        v16,
        v36,
        v37,
        v38,
        v39,
        *((_QWORD *)&v39 + 1),
        v40,
        *((_QWORD *)&v40 + 1),
        v41,
        *((_QWORD *)&v41 + 1),
        v14.m128_u64[0],
        v14.m128_u64[1],
        v43,
        v44);
      v19 = *(_QWORD *)&nextJobOut->m_data[56];
      v48 = 0i64;
      v47 = _mm_mul_ps(_mm_sub_ps(v45[1], v45[0]), (__m128)xmmword_141A711B0);
      v46[0] = _mm_add_ps(v47, v45[0]);
      v46[1] = _mm_add_ps(v46[0], v14);
      (*(void (__fastcall **)(__int64, __m128 *, void ***))(*(_QWORD *)v19 + 232i64))(v19, v46, &v30);
      ++v9;
      *(_DWORD *)(v10 + v11 + 52) = HIDWORD(v29);
      v10 += 64i64;
    }
    while ( v9 < *(_DWORD *)&nextJobOut->m_data[48] );
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

