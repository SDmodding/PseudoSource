// File Line: 41
// RVA: 0xD30290
__int64 __fastcall hkCpuMoppAabbQueryJob(hkJobQueue *jobQueue, hkJobQueue::JobQueueEntry *nextJobOut)
{
  hkJobQueue *v2; // rbp
  hkJobQueue::JobQueueEntry *v3; // rbx
  _QWORD *v4; // r8
  _QWORD *v5; // rcx
  unsigned __int64 v6; // rax
  signed __int64 v7; // rcx
  __int64 v8; // rax
  int v9; // edi
  unsigned __int64 v10; // rsi
  __int64 v11; // r14
  hkAabb *v12; // r8
  hkpMoppPrimitiveInfo *v13; // rax
  int v14; // er8
  int v15; // ecx
  hkpMoppPrimitiveInfo *v16; // rdx
  hkpMoppPrimitiveInfo *v17; // rcx
  _QWORD *v18; // rax
  _QWORD *v19; // rcx
  _QWORD *v20; // r8
  unsigned __int64 v21; // rax
  signed __int64 v22; // rcx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> primitives_out; // [rsp+20h] [rbp-C8h]
  char v25; // [rsp+3Fh] [rbp-A9h]
  hkpMoppObbVirtualMachine v26; // [rsp+80h] [rbp-68h]

  v2 = jobQueue;
  v3 = nextJobOut;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtCollQueryMoppAabbQuery";
    v6 = __rdtsc();
    v7 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v7 - 8) = v6;
    v4[1] = v7;
  }
  v8 = *(_QWORD *)&v3->m_data[48];
  v9 = 0;
  v10 = (unsigned __int64)&v25 & 0xFFFFFFFFFFFFFFF0ui64;
  *(_OWORD *)(v10 + 16) = *(_OWORD *)&v3->m_data[32];
  *(_QWORD *)(v10 + 32) = v8;
  *(_DWORD *)(v10 + 40) = 512;
  *(_DWORD *)(v10 + 44) = 512;
  *(_BYTE *)(v10 + 48) = 2;
  if ( *(_DWORD *)&v3->m_data[72] > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = (hkAabb *)(v11 + *(_QWORD *)&v3->m_data[64]);
      primitives_out.m_size = 0;
      v13 = (hkpMoppPrimitiveInfo *)v12[1].m_min.m_quad.m128_u64[0];
      primitives_out.m_capacityAndFlags = -2147481600;
      primitives_out.m_data = v13;
      hkpMoppObbVirtualMachine::queryAabb(
        &v26,
        (hkpMoppCode *)((unsigned __int64)&v25 & 0xFFFFFFFFFFFFFFF0ui64),
        v12,
        &primitives_out);
      v14 = primitives_out.m_capacityAndFlags;
      v15 = primitives_out.m_size;
      if ( primitives_out.m_size == (primitives_out.m_capacityAndFlags & 0x3FFFFFFF) )
      {
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &primitives_out, 4);
        v14 = primitives_out.m_capacityAndFlags;
        v15 = primitives_out.m_size;
      }
      v16 = primitives_out.m_data;
      v17 = &primitives_out.m_data[v15];
      if ( v17 )
      {
        v17->ID = -1;
        v14 = primitives_out.m_capacityAndFlags;
        v16 = primitives_out.m_data;
      }
      primitives_out.m_size = 0;
      if ( v14 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v16,
          4 * v14);
      ++v9;
      v11 += 48i64;
      primitives_out.m_data = 0i64;
      primitives_out.m_capacityAndFlags = 2147483648;
    }
    while ( v9 < *(_DWORD *)&v3->m_data[72] );
  }
  v18 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v19 = (_QWORD *)v18[1];
  v20 = v18;
  if ( (unsigned __int64)v19 < v18[3] )
  {
    *v19 = "Et";
    v21 = __rdtsc();
    v22 = (signed __int64)(v19 + 2);
    *(_DWORD *)(v22 - 8) = v21;
    v20[1] = v22;
  }
  return hkJobQueue::finishJobAndGetNextJob(v2, v3, v3, 0);
}

