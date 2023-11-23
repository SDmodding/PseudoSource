// File Line: 24
// RVA: 0xB94E70
hkaiArrayUtil *__fastcall hkaiArrayUtil::reserveForNonPodType<hkArray<int,hkContainerHeapAllocator>,hkContainerHeapAllocator>(
        hkaiArrayUtil *this,
        hkResult *result,
        hkArray<hkArray<int,hkContainerHeapAllocator>,hkContainerHeapAllocator> *array,
        __int64 size)
{
  hkResultEnum m_enum; // ecx
  int v7; // r14d
  int v8; // esi
  __int64 v9; // r8
  int v10; // r14d
  void *v11; // rax
  void *v12; // r12
  int v13; // r8d
  __int32 v14; // eax
  __int64 v15; // rbp
  int *v16; // rbx
  int v17; // r8d
  hkResultEnum v18; // r8d
  void *v19; // rax
  void *v20; // rbx
  hkaiArrayUtil *v21; // rax
  int v22; // [rsp+60h] [rbp+18h] BYREF

  m_enum = result[3].m_enum;
  v7 = m_enum & 0x3FFFFFFF;
  if ( (m_enum & 0x3FFFFFFF) >= (int)array )
  {
    v21 = this;
    *(_DWORD *)this = 0;
  }
  else
  {
    if ( (int)array < 2 * v7 )
      LODWORD(array) = 2 * v7;
    v8 = 0;
    v9 = (unsigned int)(16 * (_DWORD)array);
    v22 = v9;
    if ( m_enum < HK_SUCCESS )
    {
      v19 = (void *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                      &hkContainerHeapAllocator::s_alloc,
                      &v22,
                      v9,
                      size);
      v20 = v19;
      if ( v19 )
        hkMemUtil::memCpy(v19, *(const void **)&result->m_enum, 16 * result[2].m_enum);
      *(_QWORD *)&result->m_enum = v20;
    }
    else
    {
      v10 = 16 * m_enum;
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
        hkMemUtil::memCpy(v11, *(const void **)&result->m_enum, v13);
      }
      else
      {
        v14 = result[2].m_enum - 1;
        v15 = v14;
        if ( v14 >= 0 )
        {
          v16 = (int *)(16i64 * v14 + *(_QWORD *)&result->m_enum + 12i64);
          do
          {
            v17 = *v16;
            *(v16 - 1) = 0;
            if ( v17 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                *(void **)(v16 - 3),
                4 * v17);
            *(_QWORD *)(v16 - 3) = 0i64;
            *v16 = 0x80000000;
            v16 -= 4;
            --v15;
          }
          while ( v15 >= 0 );
        }
        v18 = result[3].m_enum;
        result[2].m_enum = HK_SUCCESS;
        if ( v18 >= HK_SUCCESS )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            *(void **)&result->m_enum,
            16 * v18);
        *(_QWORD *)&result->m_enum = 0i64;
        result[3].m_enum = 0x80000000;
      }
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)&result->m_enum,
        v10);
      *(_QWORD *)&result->m_enum = v12;
    }
    LOBYTE(v8) = *(_QWORD *)&result->m_enum == 0i64;
    result[3].m_enum = v22 / 16;
    v21 = this;
    *(_DWORD *)this = v8;
  }
  return v21;
}

// File Line: 86
// RVA: 0xB79CF0
hkaiArrayUtil *__fastcall hkaiArrayUtil::reserveSmall<int,hkContainerHeapAllocator>(
        hkaiArrayUtil *this,
        hkResult *result,
        hkArray<unsigned int,hkContainerHeapAllocator> *array,
        int n)
{
  __int32 v5; // ecx
  signed int v6; // eax

  v5 = result[3].m_enum & 0x3FFFFFFF;
  if ( v5 >= (int)array )
    goto LABEL_13;
  if ( (result[3].m_enum & 0x3FFFFFFFu) >= 0x400 )
    v6 = (3 * (v5 / 2 + 5)) & 0xFFFFFFF0;
  else
    v6 = 2 * v5;
  if ( v5 < n )
  {
    if ( v6 < n )
      n = v6;
    v6 = n;
  }
  if ( (int)array < v6 )
    LODWORD(array) = v6;
  if ( v5 >= (int)array )
  {
LABEL_13:
    *(_DWORD *)this = 0;
    return this;
  }
  else
  {
    hkArrayUtil::_reserve((hkResult *)this, &hkContainerHeapAllocator::s_alloc, result, (int)array, 4);
    return this;
  }
}

