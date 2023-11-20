// File Line: 24
// RVA: 0xB94E70
hkResult *__fastcall hkaiArrayUtil::reserveForNonPodType<hkArray<int,hkContainerHeapAllocator>,hkContainerHeapAllocator>(hkaiArrayUtil *this, hkResult *result, hkArray<hkArray<int,hkContainerHeapAllocator>,hkContainerHeapAllocator> *array, __int64 size)
{
  hkResult *v4; // r15
  hkResultEnum v5; // ecx
  hkResult *v6; // rdi
  __int32 v7; // er14
  hkResultEnum v8; // esi
  __int64 v9; // r8
  int v10; // er14
  void *v11; // rax
  void *v12; // r12
  int v13; // er8
  int v14; // eax
  __int64 v15; // rbp
  int *v16; // rbx
  int v17; // er8
  hkResultEnum v18; // er8
  void *v19; // rax
  void *v20; // rbx
  hkResult *v21; // rax
  int v22; // [rsp+60h] [rbp+18h]

  v4 = (hkResult *)this;
  v5 = result[3].m_enum;
  v6 = result;
  v7 = result[3].m_enum & 0x3FFFFFFF;
  if ( v7 >= (signed int)array )
  {
    v21 = v4;
    v4->m_enum = 0;
  }
  else
  {
    if ( (signed int)array < 2 * v7 )
      LODWORD(array) = 2 * v7;
    v8 = 0;
    v9 = (unsigned int)(16 * (_DWORD)array);
    v22 = v9;
    if ( (signed int)v5 < 0 )
    {
      v19 = (void *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                      &hkContainerHeapAllocator::s_alloc,
                      &v22,
                      v9,
                      size);
      v20 = v19;
      if ( v19 )
        hkMemUtil::memCpy(v19, *(const void **)&v6->m_enum, 16 * v6[2].m_enum);
      *(_QWORD *)&v6->m_enum = v20;
    }
    else
    {
      v10 = 16 * v7;
      v11 = (void *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                      &hkContainerHeapAllocator::s_alloc,
                      &v22,
                      v9,
                      size);
      v12 = v11;
      if ( v11 )
      {
        v13 = v22;
        if ( v10 < v22 )
          v13 = v10;
        hkMemUtil::memCpy(v11, *(const void **)&v6->m_enum, v13);
      }
      else
      {
        v14 = v6[2].m_enum - 1;
        v15 = v14;
        if ( v14 >= 0 )
        {
          v16 = (int *)(16i64 * v14 + *(_QWORD *)&v6->m_enum + 12i64);
          do
          {
            v17 = *v16;
            *(v16 - 1) = 0;
            if ( v17 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                *(void **)(v16 - 3),
                4 * v17);
            *(_QWORD *)(v16 - 3) = 0i64;
            *v16 = 2147483648;
            v16 -= 4;
            --v15;
          }
          while ( v15 >= 0 );
        }
        v18 = v6[3].m_enum;
        v6[2].m_enum = 0;
        if ( (signed int)v18 >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            *(void **)&v6->m_enum,
            16 * v18);
        *(_QWORD *)&v6->m_enum = 0i64;
        v6[3].m_enum = 2147483648;
      }
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)&v6->m_enum,
        v10);
      *(_QWORD *)&v6->m_enum = v12;
    }
    LOBYTE(v8) = *(_QWORD *)&v6->m_enum == 0i64;
    v6[3].m_enum = v22 / 16;
    v21 = v4;
    v4->m_enum = v8;
  }
  return v21;
}

// File Line: 86
// RVA: 0xB79CF0
hkResult *__fastcall hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(hkaiArrayUtil *this, hkResult *result, hkArray<unsigned int,hkContainerHeapAllocator> *array, int n)
{
  hkResult *v4; // rbx
  __int32 v5; // ecx
  signed int v6; // eax
  hkResult *v7; // rax

  v4 = (hkResult *)this;
  v5 = result[3].m_enum & 0x3FFFFFFF;
  if ( v5 >= (signed int)array )
    goto LABEL_16;
  if ( v5 >= 1024 )
    v6 = 3 * (v5 / 2 + 5) & 0xFFFFFFF0;
  else
    v6 = 2 * v5;
  if ( v5 < n )
  {
    if ( v6 < n )
      n = v6;
    v6 = n;
  }
  if ( (signed int)array < v6 )
    LODWORD(array) = v6;
  if ( v5 >= (signed int)array )
  {
LABEL_16:
    v4->m_enum = 0;
    v7 = v4;
  }
  else
  {
    hkArrayUtil::_reserve(v4, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, result, (int)array, 4);
    v7 = v4;
  }
  return v7;
}

