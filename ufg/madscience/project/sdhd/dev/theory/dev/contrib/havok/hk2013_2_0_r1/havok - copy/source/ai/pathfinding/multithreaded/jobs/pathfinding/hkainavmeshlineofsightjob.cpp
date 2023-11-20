// File Line: 22
// RVA: 0xC0F940
hkJobQueue::JobStatus __fastcall hkaiProcessNavMeshLineOfSightJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  unsigned int v2; // eax
  __m128i *v3; // r12
  hkJobQueue::JobQueueEntry *v4; // r14
  hkJobQueue *v5; // r13
  __int64 v6; // r15
  _QWORD *v7; // r8
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
  signed __int64 v20; // rcx
  void *v21; // rsi
  bool v22; // bl
  int v23; // edi
  hkLifoAllocator *v24; // rax
  char *v25; // rcx
  int v26; // edx
  char *v27; // r8
  hkaiStreamingCollection::InstanceInfo *v28; // rcx
  int v29; // eax
  int v30; // ecx
  bool v31; // sf
  unsigned __int8 v32; // of
  int v33; // eax
  char *v34; // rsi
  signed int v35; // edi
  hkLifoAllocator *v36; // rax
  int v37; // er8
  _QWORD *v38; // r8
  _QWORD *v39; // rcx
  unsigned __int64 v40; // rax
  signed __int64 v41; // rcx
  _DWORD *array; // [rsp+20h] [rbp-C0h]
  int v44; // [rsp+28h] [rbp-B8h]
  int v45; // [rsp+2Ch] [rbp-B4h]
  void *p; // [rsp+30h] [rbp-B0h]
  int v47; // [rsp+38h] [rbp-A8h]
  hkaiLineOfSightUtil::LineOfSightOutput output; // [rsp+40h] [rbp-A0h]
  int v49; // [rsp+90h] [rbp-50h]
  int v50; // [rsp+94h] [rbp-4Ch]
  __int64 v51; // [rsp+98h] [rbp-48h]
  int v52; // [rsp+A0h] [rbp-40h]
  __int64 v53; // [rsp+B0h] [rbp-30h]
  char v54; // [rsp+B8h] [rbp-28h]
  char v55; // [rsp+BAh] [rbp-26h]
  __int128 v56; // [rsp+C0h] [rbp-20h]
  int v57; // [rsp+D0h] [rbp-10h]
  __m128i v58; // [rsp+100h] [rbp+20h]
  __int128 v59; // [rsp+110h] [rbp+30h]
  void *dst[2]; // [rsp+120h] [rbp+40h]
  hkJobQueue *v61; // [rsp+1A0h] [rbp+C0h]

  v2 = *(_DWORD *)&nextJobOut->m_data[56];
  v3 = *(__m128i **)&nextJobOut->m_data[48];
  v4 = nextJobOut;
  v5 = jobQueue;
  if ( (signed int)v2 > 0 )
  {
    v6 = v2;
    do
    {
      v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v8 = v7[1];
      if ( v8 < v7[3] )
      {
        *(_QWORD *)v8 = "LtMtPathLineOfSight";
        *(_QWORD *)(v8 + 16) = "StInit";
        v9 = __rdtsc();
        *(_DWORD *)(v8 + 8) = v9;
        v7[1] = v8 + 24;
      }
      v11 = (__int128)v3[3];
      v12 = v3[4];
      v13 = *v3;
      v14 = (__int128)v3[1];
      v58 = v3[2];
      v10 = v58;
      v3 += 5;
      v59 = v11;
      *(__m128i *)dst = v12;
      hkaiLineOfSightUtil::LineOfSightInput::LineOfSightInput((hkaiLineOfSightUtil::LineOfSightInput *)&output.m_doNotExceedArrayCapacity);
      v15 = *(_DWORD *)&v4->m_data[60];
      v52 = v11;
      v16.m_quad = *(__m128 *)&v4->m_data[32];
      v49 = _mm_cvtsi128_si32(v10);
      *(__m128i *)&output.m_doNotExceedArrayCapacity.m_bool = v13;
      v50 = v15;
      v51 = v58.m128i_i64[1];
      v56 = v14;
      output.m_finalPoint = (hkVector4f)v16.m_quad;
      v57 = _mm_cvtsi128_si32(_mm_srli_si128(v10, 4));
      v55 = BYTE5(v59);
      v54 = BYTE4(v59);
      v53 = *(_QWORD *)&v4->m_data[64];
      hkaiLineOfSightUtil::LineOfSightOutput::LineOfSightOutput(&output);
      v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v18 = (_QWORD *)v17[1];
      if ( (unsigned __int64)v18 < v17[3] )
      {
        *v18 = "StLineOfSight";
        v19 = __rdtsc();
        v20 = (signed __int64)(v18 + 2);
        *(_DWORD *)(v20 - 8) = v19;
        v17[1] = v20;
      }
      v21 = dst[0];
      if ( dst[0] )
      {
        v23 = (int)dst[1];
        array = 0i64;
        v44 = 0;
        v45 = 2147483648;
        v47 = (int)dst[1];
        if ( LODWORD(dst[1]) )
        {
          v24 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v25 = (char *)v24->m_cur;
          v26 = (4 * v23 + 127) & 0xFFFFFF80;
          v27 = &v25[v26];
          if ( v26 > v24->m_slabSize || v27 > v24->m_end )
            v25 = (char *)hkLifoAllocator::allocateFromNewSlab(v24, v26);
          else
            v24->m_cur = v27;
        }
        else
        {
          v25 = 0i64;
        }
        array = v25;
        p = v25;
        output.m_visitedEdgesOut.m_data = (unsigned int *)v25;
        v28 = *(hkaiStreamingCollection::InstanceInfo **)&v4->m_data[16];
        v45 = v23 | 0x80000000;
        output.m_visitedEdgesOut.m_size = 0;
        output.m_visitedEdgesOut.m_capacityAndFlags = (v23 | 0x80000000) & 0x3FFFFFFF | 0x80000000;
        output.m_doNotExceedArrayCapacity.m_bool = 1;
        v29 = hkaiLineOfSightUtil::checkLineOfSight(
                v28,
                (hkaiLineOfSightUtil::LineOfSightInput *)&output.m_doNotExceedArrayCapacity,
                &output);
        v30 = output.m_visitedEdgesOut.m_size;
        v22 = v29 != 0;
        v44 = output.m_visitedEdgesOut.m_size;
        v32 = __OFSUB__(output.m_visitedEdgesOut.m_size, v23);
        v31 = output.m_visitedEdgesOut.m_size - v23 < 0;
        if ( output.m_visitedEdgesOut.m_size < v23 )
        {
          if ( output.m_visitedEdgesOut.m_size == (v45 & 0x3FFFFFFF) )
          {
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 4);
            v30 = v44;
          }
          array[v30] = -1;
          v30 = v44 + 1;
          v44 = v30;
          v32 = __OFSUB__(v30, v23);
          v31 = v30 - v23 < 0;
        }
        if ( v31 ^ v32 )
          v23 = v30;
        hkString::memCpy(v21, array, 4 * v23);
        v33 = v44;
        v34 = (char *)p;
        if ( p == array )
          v33 = 0;
        v44 = v33;
        v35 = (4 * v47 + 127) & 0xFFFFFF80;
        v36 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v37 = (v35 + 15) & 0xFFFFFFF0;
        if ( v35 > v36->m_slabSize || &v34[v37] != v36->m_cur || v36->m_firstNonLifoEnd == v34 )
          hkLifoAllocator::slowBlockFree(v36, v34, v37);
        else
          v36->m_cur = v34;
        v44 = 0;
        if ( v45 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            array,
            4 * v45);
      }
      else
      {
        v22 = (unsigned int)hkaiLineOfSightUtil::checkLineOfSight(
                              *(hkaiStreamingCollection::InstanceInfo **)&v4->m_data[16],
                              (hkaiLineOfSightUtil::LineOfSightInput *)&output.m_doNotExceedArrayCapacity,
                              &output) != 0;
      }
      **((_BYTE **)&v59 + 1) = v22;
      v38 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
      v39 = (_QWORD *)v38[1];
      if ( (unsigned __int64)v39 < v38[3] )
      {
        *v39 = "lt";
        v40 = __rdtsc();
        v41 = (signed __int64)(v39 + 2);
        *(_DWORD *)(v41 - 8) = v40;
        v38[1] = v41;
      }
      output.m_pointsOut.m_size = 0;
      if ( output.m_pointsOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          output.m_pointsOut.m_data,
          16 * output.m_pointsOut.m_capacityAndFlags);
      output.m_pointsOut.m_data = 0i64;
      output.m_pointsOut.m_capacityAndFlags = 2147483648;
      output.m_distancesOut.m_size = 0;
      if ( output.m_distancesOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          output.m_distancesOut.m_data,
          4 * output.m_distancesOut.m_capacityAndFlags);
      output.m_distancesOut.m_data = 0i64;
      output.m_distancesOut.m_capacityAndFlags = 2147483648;
      output.m_visitedEdgesOut.m_size = 0;
      if ( output.m_visitedEdgesOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          output.m_visitedEdgesOut.m_data,
          4 * output.m_visitedEdgesOut.m_capacityAndFlags);
      --v6;
    }
    while ( v6 );
    v5 = v61;
  }
  return hkJobQueue::finishJobAndGetNextJob(v5, v4, v4, 0);
}s_alloc,
          output.m_visitedEd

