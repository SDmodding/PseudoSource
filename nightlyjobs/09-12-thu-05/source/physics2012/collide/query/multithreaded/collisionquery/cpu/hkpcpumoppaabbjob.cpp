// File Line: 41
// RVA: 0xD30290
__int64 __fastcall hkCpuMoppAabbQueryJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  _QWORD *Value; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  _QWORD *v7; // rcx
  char *v8; // rax
  int v9; // edi
  __int64 v10; // r14
  hkAabb *v11; // r8
  hkpMoppPrimitiveInfo *v12; // rax
  int m_capacityAndFlags; // r8d
  int m_size; // ecx
  hkpMoppPrimitiveInfo *m_data; // rdx
  hkpMoppPrimitiveInfo *v16; // rcx
  _QWORD *v17; // rax
  _QWORD *v18; // rcx
  _QWORD *v19; // r8
  unsigned __int64 v20; // rax
  _QWORD *v21; // rcx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> primitives_out; // [rsp+20h] [rbp-C8h] BYREF
  hkpMoppCode v24; // [rsp+30h] [rbp-B8h] BYREF
  hkpMoppObbVirtualMachine v25; // [rsp+80h] [rbp-68h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtCollQueryMoppAabbQuery";
    v6 = __rdtsc();
    v7 = v5 + 2;
    *((_DWORD *)v7 - 2) = v6;
    Value[1] = v7;
  }
  v8 = *(char **)&nextJobOut->m_data[48];
  v9 = 0;
  v24.m_info = *(hkpMoppCode::CodeInfo *)&nextJobOut->m_data[32];
  v24.m_data.m_data = v8;
  v24.m_data.m_size = 512;
  v24.m_data.m_capacityAndFlags = 512;
  v24.m_buildType.m_storage = 2;
  if ( *(int *)&nextJobOut->m_data[72] > 0 )
  {
    v10 = 0i64;
    do
    {
      v11 = (hkAabb *)(v10 + *(_QWORD *)&nextJobOut->m_data[64]);
      primitives_out.m_size = 0;
      v12 = (hkpMoppPrimitiveInfo *)v11[1].m_min.m_quad.m128_u64[0];
      primitives_out.m_capacityAndFlags = -2147481600;
      primitives_out.m_data = v12;
      hkpMoppObbVirtualMachine::queryAabb(&v25, &v24, v11, &primitives_out);
      m_capacityAndFlags = primitives_out.m_capacityAndFlags;
      m_size = primitives_out.m_size;
      if ( primitives_out.m_size == (primitives_out.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&primitives_out.m_data, 4);
        m_capacityAndFlags = primitives_out.m_capacityAndFlags;
        m_size = primitives_out.m_size;
      }
      m_data = primitives_out.m_data;
      v16 = &primitives_out.m_data[m_size];
      if ( v16 )
      {
        v16->ID = -1;
        m_capacityAndFlags = primitives_out.m_capacityAndFlags;
        m_data = primitives_out.m_data;
      }
      primitives_out.m_size = 0;
      if ( m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          m_data,
          4 * m_capacityAndFlags);
      ++v9;
      v10 += 48i64;
      primitives_out.m_data = 0i64;
      primitives_out.m_capacityAndFlags = 0x80000000;
    }
    while ( v9 < *(_DWORD *)&nextJobOut->m_data[72] );
  }
  v17 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v18 = (_QWORD *)v17[1];
  v19 = v17;
  if ( (unsigned __int64)v18 < v17[3] )
  {
    *v18 = "Et";
    v20 = __rdtsc();
    v21 = v18 + 2;
    *((_DWORD *)v21 - 2) = v20;
    v19[1] = v21;
  }
  return hkJobQueue::finishJobAndGetNextJob(jobQueue, nextJobOut, nextJobOut, WAIT_FOR_NEXT_JOB);
}

