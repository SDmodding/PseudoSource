// File Line: 22
// RVA: 0xC0F940
hkJobQueue::JobStatus __fastcall hkaiProcessNavMeshLineOfSightJob(
        hkJobQueue *jobQueue,
        hkJobQueue::JobQueueEntry *nextJobOut)
{
  int v2; // eax
  __m128i *v3; // r12
  __int64 v6; // r15
  _QWORD *Value; // r8
  unsigned __int64 v8; // rcx
  unsigned __int64 v9; // rax
  __m128i v10; // xmm8
  __int128 v11; // xmm9
  __m128i v12; // xmm0
  __m128i v13; // xmm7
  __int128 v14; // xmm6
  int v15; // eax
  hkVector4f v16; // xmm0
  _QWORD *v17; // r8
  _QWORD *v18; // rcx
  unsigned __int64 v19; // rax
  _QWORD *v20; // rcx
  void *v21; // rsi
  bool v22; // bl
  int v23; // edi
  hkLifoAllocator *v24; // rax
  _DWORD *m_cur; // rcx
  int v26; // edx
  char *v27; // r8
  hkaiStreamingCollection::InstanceInfo *v28; // rcx
  BOOL v29; // eax
  int m_size; // ecx
  bool v31; // cc
  int v32; // eax
  char *v33; // rsi
  signed int v34; // edi
  hkLifoAllocator *v35; // rax
  int v36; // r8d
  _QWORD *v37; // r8
  _QWORD *v38; // rcx
  unsigned __int64 v39; // rax
  _QWORD *v40; // rcx
  _DWORD *array; // [rsp+20h] [rbp-C0h] BYREF
  int v43; // [rsp+28h] [rbp-B8h]
  int v44; // [rsp+2Ch] [rbp-B4h]
  void *p; // [rsp+30h] [rbp-B0h]
  int v46; // [rsp+38h] [rbp-A8h]
  hkaiLineOfSightUtil::LineOfSightOutput output; // [rsp+40h] [rbp-A0h] BYREF
  int v48; // [rsp+90h] [rbp-50h]
  int v49; // [rsp+94h] [rbp-4Ch]
  __int64 v50; // [rsp+98h] [rbp-48h]
  int v51; // [rsp+A0h] [rbp-40h]
  __int64 v52; // [rsp+B0h] [rbp-30h]
  char v53; // [rsp+B8h] [rbp-28h]
  char v54; // [rsp+BAh] [rbp-26h]
  __int128 v55; // [rsp+C0h] [rbp-20h]
  int v56; // [rsp+D0h] [rbp-10h]
  __m128i v57; // [rsp+100h] [rbp+20h]
  __int128 v58; // [rsp+110h] [rbp+30h]
  void *dst[2]; // [rsp+120h] [rbp+40h]
  hkJobQueue *v60; // [rsp+1A0h] [rbp+C0h]

  v2 = *(_DWORD *)&nextJobOut->m_data[56];
  v3 = *(__m128i **)&nextJobOut->m_data[48];
  if ( v2 > 0 )
  {
    v6 = (unsigned int)v2;
    do
    {
      Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v8 = Value[1];
      if ( v8 < Value[3] )
      {
        *(_QWORD *)v8 = "LtMtPathLineOfSight";
        *(_QWORD *)(v8 + 16) = "StInit";
        v9 = __rdtsc();
        *(_DWORD *)(v8 + 8) = v9;
        Value[1] = v8 + 24;
      }
      v11 = (__int128)v3[3];
      v12 = v3[4];
      v13 = *v3;
      v14 = (__int128)v3[1];
      v57 = v3[2];
      v10 = v57;
      v3 += 5;
      v58 = v11;
      *(__m128i *)dst = v12;
      hkaiLineOfSightUtil::LineOfSightInput::LineOfSightInput((hkaiLineOfSightUtil::LineOfSightInput *)&output.m_doNotExceedArrayCapacity);
      v15 = *(_DWORD *)&nextJobOut->m_data[60];
      v51 = v11;
      v16.m_quad = *(__m128 *)&nextJobOut->m_data[32];
      v48 = _mm_cvtsi128_si32(v10);
      *(__m128i *)&output.m_doNotExceedArrayCapacity.m_bool = v13;
      v49 = v15;
      v50 = v57.m128i_i64[1];
      v55 = v14;
      output.m_finalPoint = (hkVector4f)v16.m_quad;
      v56 = _mm_cvtsi128_si32(_mm_srli_si128(v10, 4));
      v54 = BYTE5(v58);
      v53 = BYTE4(v58);
      v52 = *(_QWORD *)&nextJobOut->m_data[64];
      hkaiLineOfSightUtil::LineOfSightOutput::LineOfSightOutput(&output);
      v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v18 = (_QWORD *)v17[1];
      if ( (unsigned __int64)v18 < v17[3] )
      {
        *v18 = "StLineOfSight";
        v19 = __rdtsc();
        v20 = v18 + 2;
        *((_DWORD *)v20 - 2) = v19;
        v17[1] = v20;
      }
      v21 = dst[0];
      if ( dst[0] )
      {
        v23 = (int)dst[1];
        array = 0i64;
        v43 = 0;
        v44 = 0x80000000;
        v46 = (int)dst[1];
        if ( LODWORD(dst[1]) )
        {
          v24 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          m_cur = v24->m_cur;
          v26 = (4 * v23 + 127) & 0xFFFFFF80;
          v27 = (char *)m_cur + v26;
          if ( v26 > v24->m_slabSize || v27 > v24->m_end )
            m_cur = hkLifoAllocator::allocateFromNewSlab(v24, v26);
          else
            v24->m_cur = v27;
        }
        else
        {
          m_cur = 0i64;
        }
        array = m_cur;
        p = m_cur;
        output.m_visitedEdgesOut.m_data = m_cur;
        v28 = *(hkaiStreamingCollection::InstanceInfo **)&nextJobOut->m_data[16];
        v44 = v23 | 0x80000000;
        output.m_visitedEdgesOut.m_size = 0;
        output.m_visitedEdgesOut.m_capacityAndFlags = v23 & 0x3FFFFFFF | 0x80000000;
        output.m_doNotExceedArrayCapacity.m_bool = 1;
        v29 = hkaiLineOfSightUtil::checkLineOfSight(
                v28,
                (hkaiLineOfSightUtil::LineOfSightInput *)&output.m_doNotExceedArrayCapacity,
                &output);
        m_size = output.m_visitedEdgesOut.m_size;
        v22 = v29;
        v43 = output.m_visitedEdgesOut.m_size;
        v31 = output.m_visitedEdgesOut.m_size < v23;
        if ( output.m_visitedEdgesOut.m_size < v23 )
        {
          if ( output.m_visitedEdgesOut.m_size == (v44 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 4);
            m_size = v43;
          }
          array[m_size] = -1;
          m_size = v43 + 1;
          v43 = m_size;
          v31 = m_size < v23;
        }
        if ( v31 )
          v23 = m_size;
        hkString::memCpy(v21, array, 4 * v23);
        v32 = v43;
        v33 = (char *)p;
        if ( p == array )
          v32 = 0;
        v43 = v32;
        v34 = (4 * v46 + 127) & 0xFFFFFF80;
        v35 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v36 = (v34 + 15) & 0xFFFFFFF0;
        if ( v34 > v35->m_slabSize || &v33[v36] != v35->m_cur || v35->m_firstNonLifoEnd == v33 )
          hkLifoAllocator::slowBlockFree(v35, v33, v36);
        else
          v35->m_cur = v33;
        v43 = 0;
        if ( v44 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v44);
      }
      else
      {
        v22 = hkaiLineOfSightUtil::checkLineOfSight(
                *(hkaiStreamingCollection::InstanceInfo **)&nextJobOut->m_data[16],
                (hkaiLineOfSightUtil::LineOfSightInput *)&output.m_doNotExceedArrayCapacity,
                &output);
      }
      **((_BYTE **)&v58 + 1) = v22;
      v37 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v38 = (_QWORD *)v37[1];
      if ( (unsigned __int64)v38 < v37[3] )
      {
        *v38 = "lt";
        v39 = __rdtsc();
        v40 = v38 + 2;
        *((_DWORD *)v40 - 2) = v39;
        v37[1] = v40;
      }
      output.m_pointsOut.m_size = 0;
      if ( output.m_pointsOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          output.m_pointsOut.m_data,
          16 * output.m_pointsOut.m_capacityAndFlags);
      output.m_pointsOut.m_data = 0i64;
      output.m_pointsOut.m_capacityAndFlags = 0x80000000;
      output.m_distancesOut.m_size = 0;
      if ( output.m_distancesOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          output.m_distancesOut.m_data,
          4 * output.m_distancesOut.m_capacityAndFlags);
      output.m_distancesOut.m_data = 0i64;
      output.m_distancesOut.m_capacityAndFlags = 0x80000000;
      output.m_visitedEdgesOut.m_size = 0;
      if ( output.m_visitedEdgesOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          output.m_visitedEdgesOut.m_data,
          4 * output.m_visitedEdgesOut.m_capacityAndFlags);
      --v6;
    }
    while ( v6 );
    jobQueue = v60;
  }
  return hkJobQueue::finishJobAndGetNextJob(jobQueue, nextJobOut, nextJobOut, WAIT_FOR_NEXT_JOB);
}

