// File Line: 42
// RVA: 0xBE7B60
hkaiUserDataUtils *__fastcall hkaiUserDataUtils::restride<unsigned int>(hkaiUserDataUtils *this, hkResult *result, hkArray<unsigned int,hkContainerHeapAllocator> *data, int oldStride, int newStride, int N)
{
  signed __int64 v6; // r13
  int v7; // edi
  hkResult *v8; // r15
  hkaiUserDataUtils *v9; // r14
  int v11; // er9
  int v12; // er8
  __int64 v13; // r12
  int v14; // eax
  hkResultEnum v15; // esi
  int v16; // eax
  int v17; // er9
  int v18; // eax
  int v19; // eax
  int v20; // er9
  int v21; // edx
  int *v22; // rdi
  __int64 v23; // rcx
  int v24; // eax
  __int64 v25; // rdi
  _DWORD *v26; // r8
  __int64 v27; // rcx
  __int64 v28; // rdx
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // er9
  signed __int64 v33; // rax
  int v34; // er11
  signed __int64 v35; // rdx
  __int64 v36; // rcx
  __int64 v37; // r9
  __int64 v38; // r10
  signed __int64 v39; // rbx
  __int64 v40; // rsi
  hkResultEnum v41; // er12
  char *v42; // r8
  char *v43; // rdi
  __int64 v44; // rcx
  signed __int64 v45; // rdi
  __int64 v46; // rdx
  int v47; // eax
  int v48; // eax
  int *v49; // rdi
  __int64 i; // rcx
  hkResult v51; // [rsp+30h] [rbp-38h]
  hkResult v52[2]; // [rsp+38h] [rbp-30h]
  __int64 v53; // [rsp+40h] [rbp-28h]
  char *array; // [rsp+48h] [rbp-20h]
  hkResultEnum v55; // [rsp+50h] [rbp-18h]
  int v56; // [rsp+54h] [rbp-14h]
  hkaiUserDataUtils *v57; // [rsp+A0h] [rbp+38h]
  hkResult v58; // [rsp+B0h] [rbp+48h]
  hkResult resulta; // [rsp+B8h] [rbp+50h]

  v58.m_enum = (signed int)data;
  v57 = this;
  v6 = oldStride;
  v7 = (signed int)data;
  v8 = result;
  v9 = this;
  if ( oldStride == (_DWORD)data )
    goto LABEL_4;
  if ( !oldStride )
  {
    result[2].m_enum = 0;
LABEL_4:
    *(_DWORD *)this = 0;
    return this;
  }
  v11 = result[2].m_enum;
  array = 0i64;
  v55 = 0;
  v56 = 2147483648;
  if ( v11 <= 0 )
  {
    resulta.m_enum = 0;
    goto LABEL_12;
  }
  if ( v11 < 0 )
    v11 = 0;
  hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v11, 4);
  if ( resulta.m_enum == HK_SUCCESS )
  {
LABEL_12:
    v13 = (unsigned int)newStride;
    v14 = v8[3].m_enum & 0x3FFFFFFF;
    v15 = newStride * v6;
    if ( v14 >= newStride * (signed int)v6 )
    {
      v51.m_enum = 0;
    }
    else
    {
      v16 = 2 * v14;
      v17 = newStride * v6;
      if ( v15 < v16 )
        v17 = v16;
      hkArrayUtil::_reserve(&v51, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, v17, 4);
      if ( v51.m_enum )
      {
        *(_DWORD *)v9 = 1;
LABEL_57:
        v55 = 0;
        if ( v56 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            array,
            4 * v56);
        return v9;
      }
    }
    if ( v7 )
    {
      if ( (v56 & 0x3FFFFFFF) < v8[2].m_enum )
      {
        if ( v56 >= 0 )
          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
            array,
            4 * v56);
        v52[0].m_enum = 4 * v8[2].m_enum;
        array = (char *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                          (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                          (int *)v52);
        v56 = v52[0].m_enum / 4;
      }
      v25 = *(_QWORD *)&v8->m_enum;
      v26 = array;
      v55 = v8[2].m_enum;
      v27 = 0i64;
      v28 = v55;
      if ( (signed int)v55 > 0 )
      {
        do
        {
          v29 = *(_DWORD *)(v25 + 4 * v27++);
          v26[v27 - 1] = v29;
        }
        while ( v27 < v28 );
      }
      v30 = v8[3].m_enum & 0x3FFFFFFF;
      if ( v30 < v15 )
      {
        v31 = 2 * v30;
        v32 = v15;
        if ( v15 < v31 )
          v32 = v31;
        hkArrayUtil::_reserve(v52, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, v32, 4);
      }
      v33 = v58.m_enum;
      v34 = v6;
      v8[2].m_enum = v15;
      v35 = v33;
      *(_QWORD *)&v52[0].m_enum = v33;
      if ( (signed int)v33 < (signed int)v6 )
        v34 = v33;
      v36 = v34;
      if ( (signed int)v13 > 0 )
      {
        v37 = 0i64;
        v38 = 0i64;
        v39 = 4 * v33;
        v40 = v13;
        v41 = v58.m_enum;
        v53 = 4 * v6;
        do
        {
          v42 = (char *)(v38 + *(_QWORD *)&v8->m_enum);
          v43 = &array[v37];
          if ( v34 == 1 )
          {
            *(_DWORD *)v42 = *(_DWORD *)v43;
          }
          else if ( v34 && v36 > 0 )
          {
            v44 = v38 + *(_QWORD *)&v8->m_enum;
            v45 = v43 - v42;
            v46 = v34;
            do
            {
              v47 = *(_DWORD *)(v45 + v44);
              v44 += 4i64;
              *(_DWORD *)(v44 - 4) = v47;
              --v46;
            }
            while ( v46 );
            v35 = *(_QWORD *)&v52[0].m_enum;
          }
          if ( (signed int)v6 > v41 && v35 < v6 )
          {
            v48 = N;
            v49 = (int *)&v42[v39];
            for ( i = v6 - v35; i; --i )
            {
              *v49 = v48;
              ++v49;
            }
          }
          v38 += v53;
          v37 += v39;
          v36 = v34;
          --v40;
        }
        while ( v40 );
        v9 = v57;
      }
    }
    else
    {
      v18 = v8[3].m_enum & 0x3FFFFFFF;
      if ( v18 < v15 )
      {
        v19 = 2 * v18;
        v20 = v15;
        if ( v15 < v19 )
          v20 = v19;
        hkArrayUtil::_reserve(&v58, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v8, v20, 4);
      }
      v21 = v15 - v8[2].m_enum;
      v22 = (int *)(*(_QWORD *)&v8->m_enum + 4i64 * (signed int)v8[2].m_enum);
      v23 = v21;
      if ( v21 > 0 )
      {
        v24 = N;
        while ( v23 )
        {
          *v22 = v24;
          ++v22;
          --v23;
        }
      }
      v8[2].m_enum = v15;
    }
    *(_DWORD *)v9 = 0;
    goto LABEL_57;
  }
  v12 = v56;
  *(_DWORD *)v9 = 1;
  v55 = 0;
  if ( v12 >= 0 )
  {
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      4 * v12);
    return v9;
  }
  return v9;
}

