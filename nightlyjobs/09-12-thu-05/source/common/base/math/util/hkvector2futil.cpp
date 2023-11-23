// File Line: 72
// RVA: 0xC6E1A0
void __fastcall hkVector2Util::`anonymous namespace::Deque<int>::get(
        hkVector2Util::Deque<int> *this,
        hkArray<int,hkContainerHeapAllocator> *out)
{
  int v3; // esi
  int *v4; // rbp
  int *m_data; // rax
  __int64 v6; // r9
  signed __int64 v7; // r10
  int v8; // ecx
  int v9; // [rsp+30h] [rbp+8h] BYREF

  v3 = this->m_top - this->m_bot;
  v4 = &this->m_vals.m_data.m_storage[this->m_bot];
  if ( (out->m_capacityAndFlags & 0x3FFFFFFF) < v3 )
  {
    if ( out->m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        out->m_data,
        4 * out->m_capacityAndFlags);
    v9 = 4 * v3;
    out->m_data = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &v9);
    out->m_capacityAndFlags = v9 / 4;
  }
  m_data = out->m_data;
  out->m_size = v3;
  v6 = v3;
  if ( v3 > 0 )
  {
    v7 = (char *)v4 - (char *)m_data;
    do
    {
      v8 = *(int *)((char *)m_data++ + v7);
      *(m_data - 1) = v8;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 86
// RVA: 0xC6CCC0
void __fastcall hkVector2Util::convexHullSimplePolyline(
        hkArrayBase<hkVector2f> *line,
        hkArray<int,hkContainerHeapAllocator> *indicesOut)
{
  __int64 m_size; // rsi
  int v5; // r12d
  hkLifoAllocator *Value; // rax
  int *m_cur; // rdi
  int v8; // edx
  char *v9; // r8
  hkVector2f *m_data; // rcx
  int v11; // r9d
  int v12; // edx
  int v13; // ebx
  int v14; // r14d
  int v15; // r9d
  hkVector2f *v16; // r11
  hkVector2f v17; // rdx
  hkVector2f v18; // rax
  hkVector2f v19; // r8
  hkVector2f v20; // rcx
  __int64 v21; // r10
  float y; // xmm3_4
  float x; // xmm4_4
  float v24; // xmm8_4
  float v25; // xmm9_4
  float v26; // xmm10_4
  float v27; // xmm11_4
  float v28; // xmm6_4
  float v29; // xmm7_4
  hkVector2f *v30; // r11
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  __int64 v35; // rax
  signed int v36; // ebx
  hkLifoAllocator *v37; // rax
  int v38; // r8d
  hkVector2f v39; // [rsp+10h] [rbp-59h]
  hkVector2Util::Deque<int> v40; // [rsp+18h] [rbp-51h] BYREF
  hkVector2f vars0; // [rsp+D0h] [rbp+67h]

  m_size = line->m_size;
  v5 = 2 * m_size - 2;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (int *)Value->m_cur;
  v8 = (4 * v5 + 127) & 0xFFFFFF80;
  v9 = (char *)m_cur + v8;
  if ( v8 > Value->m_slabSize || v9 > Value->m_end )
    m_cur = (int *)hkLifoAllocator::allocateFromNewSlab(Value, v8);
  else
    Value->m_cur = v9;
  m_data = line->m_data;
  v40.m_vals.m_data.m_storage = m_cur;
  v40.m_vals.m_size.m_storage = 2 * m_size - 2;
  v11 = v5 / 2 + 1;
  v12 = v5 / 2;
  if ( (float)((float)((float)(m_data[2].y - m_data->y) * (float)(m_data[1].x - m_data->x))
             - (float)((float)(m_data[1].y - m_data->y) * (float)(m_data[2].x - m_data->x))) <= 0.0 )
  {
    m_cur[v12] = 1;
    m_cur[v11] = 0;
  }
  else
  {
    m_cur[v12] = 0;
    m_cur[v11] = 1;
  }
  v13 = v12 - 1;
  v14 = 3;
  v15 = v5 / 2 + 3;
  m_cur[v13] = 2;
  m_cur[v5 / 2 + 2] = 2;
  v16 = line->m_data;
  v17 = line->m_data[m_cur[v12 - 1]];
  v18 = line->m_data[m_cur[v15 - 2]];
  v19 = line->m_data[m_cur[v13 + 1]];
  v20 = line->m_data[m_cur[v15 - 1]];
  v40.m_bot = v13;
  v40.m_top = v15;
  vars0 = v17;
  v39 = v19;
  v21 = 3i64;
  if ( m_size > 3 )
  {
    y = vars0.y;
    x = vars0.x;
    v24 = v20.y;
    v25 = v18.y;
    v26 = v18.x;
    v27 = v20.x;
    do
    {
      if ( (float)((float)((float)(v16[v21].y - y) * (float)(v39.x - x))
                 - (float)((float)(v16[v21].x - x) * (float)(v39.y - y))) <= 0.0
        || (float)((float)((float)(v16[v21].y - v25) * (float)(v27 - v26))
                 - (float)((float)(v24 - v25) * (float)(v16[v21].x - v26))) <= 0.0 )
      {
        if ( (float)((float)((float)(v16[v21].y - y) * (float)(v39.x - x))
                   - (float)((float)(v16[v21].x - x) * (float)(v39.y - y))) <= 0.0 )
        {
          v28 = v16[v21].y;
          v29 = v16[v21].x;
          do
          {
            v17 = v19;
            ++v13;
            vars0 = v19;
            v19 = v16[m_cur[v13 + 1]];
          }
          while ( (float)((float)((float)(v19.x - vars0.x) * (float)(v28 - vars0.y))
                        - (float)((float)(v19.y - vars0.y) * (float)(v29 - vars0.x))) <= 0.0 );
        }
        v39 = v17;
        m_cur[--v13] = v14;
        v30 = line->m_data;
        v19 = v17;
        v40.m_bot = v13;
        v31 = v30[v21].y;
        v17 = v30[v14];
        v32 = v30[v21].x - v26;
        vars0 = v17;
        if ( (float)((float)((float)(v31 - v25) * (float)(v27 - v26)) - (float)((float)(v24 - v25) * v32)) <= 0.0 )
        {
          do
          {
            v33 = v18.x;
            v34 = v18.y;
            v20 = v18;
            v18 = v30[m_cur[--v15 - 2]];
          }
          while ( (float)((float)((float)(v30[v21].y - v18.y) * (float)(v33 - v18.x))
                        - (float)((float)(v34 - v18.y) * (float)(v30[v21].x - v18.x))) <= 0.0 );
        }
        y = vars0.y;
        x = vars0.x;
        v35 = v15++;
        m_cur[v35] = v14;
        v16 = line->m_data;
        v18 = v20;
        v25 = v20.y;
        v26 = v20.x;
        v40.m_top = v15;
        v20 = v16[m_cur[v15 - 1]];
        v24 = v20.y;
        v27 = v20.x;
      }
      ++v21;
      ++v14;
    }
    while ( v21 < m_size );
  }
  hkVector2Util::`anonymous namespace::Deque<int>::get(&v40, indicesOut);
  v36 = (4 * v5 + 127) & 0xFFFFFF80;
  v37 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v38 = (v36 + 15) & 0xFFFFFFF0;
  if ( v36 > v37->m_slabSize || (char *)m_cur + v38 != v37->m_cur || v37->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v37, (char *)m_cur, v38);
  else
    v37->m_cur = m_cur;
}

// File Line: 140
// RVA: 0xC6D290
hkResult *__fastcall hkVector2Util::convexHullIndices(
        hkResult *result,
        hkArrayBase<hkVector2f> *originalPoints,
        hkArrayBase<int> *indicesOut)
{
  __int64 m_size; // rbp
  hkLifoAllocator *Value; // rax
  __int64 m_cur; // rdi
  int v9; // r13d
  void *v10; // rdx
  hkLifoAllocator *v11; // rax
  int *v12; // rsi
  int v13; // r15d
  char *v14; // rcx
  int v15; // ecx
  __int64 v16; // rax
  __int64 v17; // r15
  int v18; // ebp
  int v19; // r9d
  __int64 v20; // r10
  __int64 v21; // rcx
  float *v22; // rdx
  int *v23; // r8
  unsigned __int64 v24; // r12
  __int64 v25; // rax
  hkVector2f *m_data; // r11
  __int64 v27; // rax
  hkVector2f *v28; // r11
  __int64 v29; // rax
  hkVector2f *v30; // r11
  __int64 v31; // rax
  hkVector2f *v32; // r11
  __int64 v33; // rax
  hkVector2f *v34; // rdx
  int v35; // r13d
  hkLifoAllocator *v36; // rax
  char *v37; // r14
  int v38; // edx
  char *v39; // rcx
  hkResult *v40; // r15
  unsigned int v41; // ecx
  signed int v42; // ebx
  hkLifoAllocator *v43; // rax
  int v44; // r8d
  int v45; // ebp
  signed int v46; // ebx
  hkLifoAllocator *v47; // rax
  int v48; // r8d
  signed int v49; // ebx
  hkLifoAllocator *v50; // rax
  int v51; // r8d
  float v53; // xmm0_4
  __int64 v54; // rcx
  __int64 v55; // r15
  int v56; // r11d
  float *v57; // rdx
  int v58; // ebx
  unsigned int m_slotID; // ecx
  signed int v60; // ebx
  hkLifoAllocator *v61; // rax
  int v62; // r8d
  signed int v63; // ebx
  float v64; // xmm0_4
  int v65; // edx
  int v66; // r11d
  __int64 v67; // rcx
  float *v68; // rax
  __int64 v69; // r13
  int v70; // r9d
  __int64 i; // r10
  __int64 v72; // rax
  int v73; // r8d
  __int64 v74; // r9
  __int64 v75; // rax
  int v76; // r8d
  unsigned int v77; // ecx
  hkLifoAllocator *v78; // rax
  int v79; // r8d
  hkLifoAllocator *v80; // rax
  int v81; // r8d
  int v82; // [rsp+20h] [rbp-B8h]
  int v83; // [rsp+24h] [rbp-B4h]
  __int64 v84; // [rsp+28h] [rbp-B0h]
  hkVector2f v85; // [rsp+30h] [rbp-A8h]
  hkVector2f v86; // [rsp+30h] [rbp-A8h]
  int v88; // [rsp+E8h] [rbp+10h]
  __int64 v89; // [rsp+F8h] [rbp+20h]

  m_size = originalPoints->m_size;
  v88 = originalPoints->m_size;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (__int64)Value->m_cur;
  v9 = (8 * m_size + 127) & 0xFFFFFF80;
  v10 = (void *)(m_cur + v9);
  if ( v9 > Value->m_slabSize || v10 > Value->m_end )
    m_cur = hkLifoAllocator::allocateFromNewSlab(Value, v9);
  else
    Value->m_cur = v10;
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (int *)v11->m_cur;
  v13 = (4 * m_size + 127) & 0xFFFFFF80;
  v14 = (char *)v12 + v13;
  if ( v13 > v11->m_slabSize || v14 > v11->m_end )
    v12 = (int *)hkLifoAllocator::allocateFromNewSlab(v11, v13);
  else
    v11->m_cur = v14;
  if ( m_cur && v12 )
  {
    v15 = 0;
    v16 = 0i64;
    v17 = m_size;
    if ( (int)m_size > 0 )
    {
      do
        v12[v16++] = v15++;
      while ( v16 < m_size );
    }
    if ( (int)m_size > 1 )
      hkAlgorithm::quickSortRecursive<int,hkVector2Util::`anonymous namespace::IndexedLess>(
        v12,
        0,
        m_size - 1,
        (hkVector2Util::IndexedLess)originalPoints);
    v18 = 1;
    v19 = 0;
    v20 = 1i64;
    *(hkVector2f *)m_cur = originalPoints->m_data[*v12];
    v21 = 0i64;
    if ( v17 > 1 )
    {
      if ( v17 - 1 >= 4 )
      {
        v22 = (float *)m_cur;
        v23 = v12 + 3;
        v24 = ((unsigned __int64)(v17 - 5) >> 2) + 1;
        v20 = 4 * v24 + 1;
        do
        {
          v25 = *(v23 - 2);
          m_data = originalPoints->m_data;
          if ( originalPoints->m_data[v25].x != *v22 || m_data[v25].y != v22[1] )
          {
            ++v19;
            ++v21;
            *(hkVector2f *)(m_cur + 8 * v21) = m_data[v25];
            v22 = (float *)(m_cur + 8 * v21);
            v12[v21] = *(v23 - 2);
          }
          v27 = *(v23 - 1);
          v28 = originalPoints->m_data;
          if ( originalPoints->m_data[v27].x != *v22 || v28[v27].y != v22[1] )
          {
            ++v19;
            ++v21;
            *(hkVector2f *)(m_cur + 8 * v21) = v28[v27];
            v22 = (float *)(m_cur + 8 * v21);
            v12[v21] = *(v23 - 1);
          }
          v29 = *v23;
          v30 = originalPoints->m_data;
          if ( originalPoints->m_data[v29].x != *v22 || v30[v29].y != v22[1] )
          {
            ++v19;
            ++v21;
            *(hkVector2f *)(m_cur + 8 * v21) = v30[v29];
            v22 = (float *)(m_cur + 8 * v21);
            v12[v21] = *v23;
          }
          v31 = v23[1];
          v32 = originalPoints->m_data;
          if ( originalPoints->m_data[v31].x != *v22 || v32[v31].y != v22[1] )
          {
            ++v19;
            ++v21;
            *(hkVector2f *)(m_cur + 8 * v21) = v32[v31];
            v22 = (float *)(m_cur + 8 * v21);
            v12[v21] = v23[1];
          }
          v23 += 4;
          --v24;
        }
        while ( v24 );
      }
      for ( ; v20 < v17; ++v20 )
      {
        v33 = v12[v20];
        v34 = originalPoints->m_data;
        if ( originalPoints->m_data[v33].x != *(float *)(m_cur + 8 * v21)
          || v34[v33].y != *(float *)(m_cur + 8 * v21 + 4) )
        {
          ++v19;
          ++v21;
          *(hkVector2f *)(m_cur + 8 * v21) = v34[v33];
          v12[v21] = v12[v20];
        }
      }
    }
    v35 = v19 + 1;
    v83 = v19 + 1;
    if ( v19 == -1 )
    {
      v37 = 0i64;
    }
    else
    {
      v36 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v37 = (char *)v36->m_cur;
      v38 = (8 * v35 + 127) & 0xFFFFFF80;
      v39 = &v37[v38];
      if ( v38 > v36->m_slabSize || v39 > v36->m_end )
        v37 = (char *)hkLifoAllocator::allocateFromNewSlab(v36, v38);
      else
        v36->m_cur = v39;
    }
    if ( v37 )
    {
      v53 = *(float *)m_cur;
      v54 = 1i64;
      v55 = v35;
      v56 = 1;
      v82 = v35 - 1;
      if ( v35 > 1i64 )
      {
        if ( v35 - 1i64 < 4 )
        {
LABEL_66:
          while ( v54 < v35 )
          {
            if ( v53 != *(float *)(m_cur + 8 * v54) )
              break;
            ++v54;
            ++v56;
          }
        }
        else
        {
          v57 = (float *)(m_cur + 24);
          while ( v53 == *(v57 - 4) )
          {
            if ( v53 != *(v57 - 2) )
            {
              ++v56;
              break;
            }
            if ( v53 != *v57 )
            {
              v56 += 2;
              break;
            }
            if ( v53 != v57[2] )
            {
              v56 += 3;
              break;
            }
            v54 += 4i64;
            v56 += 4;
            v57 += 8;
            if ( v54 >= v35 - 3i64 )
              goto LABEL_66;
          }
        }
      }
      if ( v56 == v35 )
      {
        indicesOut->m_data[indicesOut->m_size++] = 0;
        if ( *(float *)(m_cur + 4) != *(float *)(m_cur + 8i64 * v35 - 4) )
        {
          indicesOut->m_data[indicesOut->m_size++] = v35 - 1;
          indicesOut->m_data[indicesOut->m_size++] = 0;
        }
        v58 = 8 * v35 + 127;
      }
      else
      {
        v64 = *(float *)(m_cur + 8i64 * v35 - 8);
        v65 = v35 - 2;
        v66 = v56 - 1;
        v67 = v35 - 2;
        if ( v35 - 2 >= 0 )
        {
          if ( v65 + 1i64 < 4 )
          {
LABEL_93:
            while ( v67 >= 0 )
            {
              if ( v64 != *(float *)(m_cur + 8 * v67) )
                break;
              --v65;
              --v67;
            }
          }
          else
          {
            v68 = (float *)(m_cur + 8 * (v65 - 2i64));
            while ( v64 == v68[4] )
            {
              if ( v64 != v68[2] )
              {
                --v65;
                break;
              }
              if ( v64 != *v68 )
              {
                v65 -= 2;
                break;
              }
              if ( v64 != *(v68 - 2) )
              {
                v65 -= 3;
                break;
              }
              v67 -= 4i64;
              v65 -= 4;
              v68 -= 8;
              if ( v67 < 3 )
                goto LABEL_93;
            }
          }
        }
        v69 = v65 + 1;
        v85 = *(hkVector2f *)m_cur;
        v70 = 1;
        v84 = *(_QWORD *)(m_cur + 8 * v69);
        indicesOut->m_data[indicesOut->m_size++] = *v12;
        *(hkVector2f *)v37 = v85;
        for ( i = v66; i <= v69; ++i )
        {
          v72 = *(_QWORD *)(m_cur + 8 * i);
          if ( (float)((float)((float)(*((float *)&v72 + 1) - v85.y) * (float)(*(float *)&v84 - v85.x))
                     - (float)((float)(*(float *)&v72 - v85.x) * (float)(*((float *)&v84 + 1) - v85.y))) < 0.0
            || i >= v69 )
          {
            if ( v70 >= 2 )
            {
              v73 = v70 - 2;
              do
              {
                if ( (float)((float)((float)(*(float *)&v37[8 * v73 + 8] - *(float *)&v37[8 * v73])
                                   * (float)(*((float *)&v72 + 1) - *(float *)&v37[8 * v73 + 4]))
                           - (float)((float)(*(float *)&v37[8 * v73 + 12] - *(float *)&v37[8 * v73 + 4])
                                   * (float)(*(float *)&v72 - *(float *)&v37[8 * v73]))) > 0.0 )
                  break;
                --indicesOut->m_size;
                --v70;
                --v73;
              }
              while ( v70 >= 2 );
            }
            indicesOut->m_data[indicesOut->m_size++] = v12[i];
            *(_QWORD *)&v37[8 * v70++] = v72;
          }
        }
        if ( v82 != v65 + 1 )
          indicesOut->m_data[indicesOut->m_size++] = v12[v82];
        *(_QWORD *)v37 = *(_QWORD *)(m_cur + 8 * v55 - 8);
        v86 = *(hkVector2f *)(m_cur + 8 * v55 - 8);
        v89 = *(_QWORD *)(m_cur + 8i64 * v66);
        v74 = v65;
        if ( v65 >= (__int64)v66 )
        {
          do
          {
            v75 = *(_QWORD *)(m_cur + 8 * v74);
            if ( (float)((float)((float)(*((float *)&v75 + 1) - v86.y) * (float)(*(float *)&v89 - v86.x))
                       - (float)((float)(*(float *)&v75 - v86.x) * (float)(*((float *)&v89 + 1) - v86.y))) < 0.0
              || v74 <= v66 )
            {
              if ( v18 >= 2 )
              {
                v76 = v18 - 2;
                do
                {
                  if ( (float)((float)((float)(*(float *)&v37[8 * v76 + 8] - *(float *)&v37[8 * v76])
                                     * (float)(*((float *)&v75 + 1) - *(float *)&v37[8 * v76 + 4]))
                             - (float)((float)(*(float *)&v37[8 * v76 + 12] - *(float *)&v37[8 * v76 + 4])
                                     * (float)(*(float *)&v75 - *(float *)&v37[8 * v76]))) > 0.0 )
                    break;
                  --indicesOut->m_size;
                  --v18;
                  --v76;
                }
                while ( v18 >= 2 );
              }
              indicesOut->m_data[indicesOut->m_size++] = v12[v74];
              *(_QWORD *)&v37[8 * v18++] = v75;
            }
            --v74;
          }
          while ( v74 >= v66 );
        }
        if ( v66 )
          indicesOut->m_data[indicesOut->m_size++] = *v12;
        v58 = 8 * v83 + 127;
      }
      v40 = result;
      m_slotID = hkMemoryRouter::s_memoryRouter.m_slotID;
      v60 = v58 & 0xFFFFFF80;
      result->m_enum = HK_SUCCESS;
      v61 = (hkLifoAllocator *)TlsGetValue(m_slotID);
      v62 = (v60 + 15) & 0xFFFFFFF0;
      if ( v60 > v61->m_slabSize || &v37[v62] != v61->m_cur || v61->m_firstNonLifoEnd == v37 )
        hkLifoAllocator::slowBlockFree(v61, v37, v62);
      else
        v61->m_cur = v37;
      v45 = v88;
      v63 = (4 * v88 + 127) & 0xFFFFFF80;
      v47 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v48 = (v63 + 15) & 0xFFFFFFF0;
      if ( v63 <= v47->m_slabSize && (char *)v12 + v48 == v47->m_cur && v47->m_firstNonLifoEnd != v12 )
      {
        v47->m_cur = v12;
        goto LABEL_53;
      }
    }
    else
    {
      v40 = result;
      v41 = hkMemoryRouter::s_memoryRouter.m_slotID;
      result->m_enum = HK_FAILURE;
      v42 = (8 * v35 + 127) & 0xFFFFFF80;
      v43 = (hkLifoAllocator *)TlsGetValue(v41);
      v44 = (v42 + 15) & 0xFFFFFFF0;
      if ( v42 <= v43->m_slabSize && (void *)v44 == v43->m_cur && v43->m_firstNonLifoEnd )
        v43->m_cur = 0i64;
      else
        hkLifoAllocator::slowBlockFree(v43, 0i64, v44);
      v45 = v88;
      v46 = (4 * v88 + 127) & 0xFFFFFF80;
      v47 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v48 = (v46 + 15) & 0xFFFFFFF0;
      if ( v46 <= v47->m_slabSize && (char *)v12 + v48 == v47->m_cur && v47->m_firstNonLifoEnd != v12 )
      {
        v47->m_cur = v12;
LABEL_53:
        v49 = (8 * v45 + 127) & 0xFFFFFF80;
        v50 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v51 = (v49 + 15) & 0xFFFFFFF0;
        if ( v49 > v50->m_slabSize || (void *)(m_cur + v51) != v50->m_cur || v50->m_firstNonLifoEnd == (void *)m_cur )
        {
          hkLifoAllocator::slowBlockFree(v50, (char *)m_cur, v51);
          return v40;
        }
        else
        {
          v50->m_cur = (void *)m_cur;
          return v40;
        }
      }
    }
    hkLifoAllocator::slowBlockFree(v47, (char *)v12, v48);
    goto LABEL_53;
  }
  v77 = hkMemoryRouter::s_memoryRouter.m_slotID;
  result->m_enum = HK_FAILURE;
  v78 = (hkLifoAllocator *)TlsGetValue(v77);
  v79 = (v13 + 15) & 0xFFFFFFF0;
  if ( v13 > v78->m_slabSize || (char *)v12 + v79 != v78->m_cur || v78->m_firstNonLifoEnd == v12 )
    hkLifoAllocator::slowBlockFree(v78, (char *)v12, v79);
  else
    v78->m_cur = v12;
  v80 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v81 = (v9 + 15) & 0xFFFFFFF0;
  if ( v9 > v80->m_slabSize || (void *)(m_cur + v81) != v80->m_cur || v80->m_firstNonLifoEnd == (void *)m_cur )
    hkLifoAllocator::slowBlockFree(v80, (char *)m_cur, v81);
  else
    v80->m_cur = (void *)m_cur;
  return result;
}

// File Line: 288
// RVA: 0xC6D160
void __fastcall hkVector2Util::convexHullVertices(
        hkArrayBase<hkVector2f> *points,
        hkArray<hkVector2f,hkContainerHeapAllocator> *hullOut)
{
  int m_size; // edi
  int v5; // ecx
  int v6; // r10d
  __int64 v7; // r9
  hkArrayBase<int> indicesOut; // [rsp+30h] [rbp-18h] BYREF
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_size = points->m_size;
  indicesOut.m_capacityAndFlags = 0x80000000;
  indicesOut.m_data = 0i64;
  indicesOut.m_size = 0;
  if ( m_size > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, (const void **)&indicesOut.m_data, m_size, 4);
  indicesOut.m_size = m_size;
  hkVector2Util::convexHullIndices(&result, points, &indicesOut);
  v5 = indicesOut.m_size;
  if ( (hullOut->m_capacityAndFlags & 0x3FFFFFFF) < indicesOut.m_size )
  {
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&hullOut->m_data,
      indicesOut.m_size,
      8);
    v5 = indicesOut.m_size;
  }
  v6 = 0;
  if ( v5 > 0 )
  {
    v7 = 0i64;
    do
    {
      ++v6;
      hullOut->m_data[hullOut->m_size++] = points->m_data[indicesOut.m_data[v7++]];
    }
    while ( v6 < indicesOut.m_size );
  }
  indicesOut.m_size = 0;
  if ( indicesOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      indicesOut.m_data,
      4 * indicesOut.m_capacityAndFlags);
}

// File Line: 300
// RVA: 0xC6CBD0
hkBool *__fastcall hkVector2Util::edgesIntersect(
        hkBool *result,
        hkVector2f *a,
        hkVector2f *b,
        hkVector2f *c,
        hkVector2f *d)
{
  float y; // xmm8_4
  float v6; // xmm2_4
  float v7; // xmm5_4
  float v8; // xmm4_4
  float v9; // xmm8_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm9_4
  float v13; // xmm3_4
  float v14; // xmm8_4

  y = a->y;
  v6 = d->x - c->x;
  v7 = d->y - c->y;
  v8 = b->y - y;
  v9 = y - c->y;
  v10 = b->x - a->x;
  v11 = a->x - c->x;
  v12 = (float)(v10 * v7) - (float)(v6 * v8);
  v13 = (float)(v9 * v6) - (float)(v11 * v7);
  v14 = (float)(v9 * v10) - (float)(v11 * v8);
  if ( v12 < 0.0 )
  {
    LODWORD(v12) ^= _xmm[0];
    LODWORD(v13) ^= _xmm[0];
    LODWORD(v14) ^= _xmm[0];
  }
  result->m_bool = v13 > 0.0 && v14 > 0.0 && v13 < v12 && v14 < v12;
  return result;
}

// File Line: 323
// RVA: 0xC6DC50
float __fastcall hkVector2Util::computeObb(
        hkArrayBase<hkVector2f> *points,
        hkVector2f *centerOut,
        hkVector2f *e0Out,
        hkVector2f *e1Out,
        hkResult *resOut)
{
  int v6; // r9d
  int *m_data; // rbx
  float v11; // xmm14_4
  int v12; // ecx
  __m128 v13; // xmm6
  __int64 v14; // rax
  __int64 v15; // r9
  __int64 v16; // rdi
  __int64 v17; // r11
  __m128 v18; // xmm7
  __m128 v19; // xmm8
  hkVector2f *v20; // rdx
  __int64 v21; // r10
  __int64 v22; // rax
  hkResult v23; // xmm1_4
  __m128 v24; // xmm0
  __m128 v25; // xmm4
  __m128 v26; // xmm2
  __m128 v27; // xmm3
  float v28; // xmm10_4
  float x; // xmm11_4
  float v30; // xmm7_4
  float v31; // xmm6_4
  float v32; // xmm4_4
  int *v33; // rcx
  __int64 v34; // r8
  float v35; // xmm5_4
  float v36; // xmm8_4
  __int32 v37; // xmm9_4
  __int64 v38; // rax
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm3_4
  float v45; // xmm4_4
  float v46; // xmm5_4
  float v47; // xmm2_4
  float v48; // xmm3_4
  hkResult result[2]; // [rsp+30h] [rbp-E8h] BYREF
  hkArrayBase<int> array; // [rsp+38h] [rbp-E0h] BYREF
  hkResult v52; // [rsp+120h] [rbp+8h] BYREF

  v6 = points->m_size + 1;
  array.m_data = 0i64;
  array.m_size = 0;
  array.m_capacityAndFlags = 0x80000000;
  if ( v6 <= 0 )
  {
    v52.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&v52, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, v6, 4);
    if ( v52.m_enum )
      goto LABEL_6;
  }
  hkVector2Util::convexHullIndices(result, points, &array);
  if ( result[0].m_enum )
  {
LABEL_6:
    m_data = array.m_data;
    v11 = 0.0;
    resOut->m_enum = HK_FAILURE;
    goto LABEL_25;
  }
  v11 = FLOAT_3_40282e38;
  m_data = array.m_data;
  v12 = array.m_size - 1;
  array.m_size = v12;
  if ( v12 > 0 )
  {
    v13 = 0i64;
    v14 = 4i64 * (v12 - 1);
    v15 = 0i64;
    v16 = (unsigned int)v12;
    v17 = (unsigned int)v12;
    v18 = (__m128)_xmm;
    v19 = *(__m128 *)_xmm;
    do
    {
      v20 = points->m_data;
      v21 = *(int *)((char *)m_data + v14);
      v22 = m_data[v15];
      *(float *)&v23.m_enum = points->m_data[v22].y - points->m_data[v21].y;
      *(float *)&result[0].m_enum = points->m_data[v22].x - points->m_data[v21].x;
      result[1] = v23;
      v24 = _mm_mul_ps((__m128)*(unsigned __int64 *)&result[0].m_enum, (__m128)*(unsigned __int64 *)&result[0].m_enum);
      v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0));
      v26 = _mm_rsqrt_ps(v25);
      v27 = _mm_andnot_ps(
              _mm_cmple_ps(v25, v13),
              _mm_mul_ps(_mm_sub_ps(v18, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)), _mm_mul_ps(v19, v26)));
      *(_QWORD *)&result[0].m_enum = _mm_mul_ps((__m128)*(unsigned __int64 *)&result[0].m_enum, v27).m128_u64[0];
      if ( (float)(v27.m128_f32[0] * v25.m128_f32[0]) != 0.0 )
      {
        v28 = *(float *)&result[1].m_enum;
        x = v20[v21].x;
        v30 = 0.0;
        v31 = 0.0;
        v32 = 0.0;
        v33 = m_data;
        v34 = v16;
        v35 = 0.0;
        v36 = *(float *)&result[0].m_enum;
        v37 = result[1].m_enum ^ _xmm[0];
        do
        {
          v38 = *v33;
          v39 = v20[v38].x - x;
          v40 = v20[v38].y - v20[v21].y;
          v41 = (float)(v40 * *(float *)&result[1].m_enum) + (float)(v39 * *(float *)&result[0].m_enum);
          if ( v41 < v30 )
            v30 = (float)(v40 * *(float *)&result[1].m_enum) + (float)(v39 * *(float *)&result[0].m_enum);
          if ( v41 > v32 )
            v32 = (float)(v40 * *(float *)&result[1].m_enum) + (float)(v39 * *(float *)&result[0].m_enum);
          v42 = (float)(v40 * *(float *)&result[0].m_enum) + (float)(v39 * *(float *)&v37);
          if ( v42 < v31 )
            v31 = v42;
          if ( v42 > v35 )
            v35 = v42;
          ++v33;
          --v34;
        }
        while ( v34 );
        v43 = v32 - v30;
        v44 = v35 - v31;
        if ( (float)((float)(v32 - v30) * (float)(v35 - v31)) < v11 )
        {
          v11 = (float)(v32 - v30) * (float)(v35 - v31);
          v45 = v32 + v30;
          v46 = v35 + v31;
          v47 = v43 * 0.5;
          v48 = v44 * 0.5;
          centerOut->x = (float)((float)((float)(v45 * *(float *)&result[0].m_enum) + (float)(v46 * *(float *)&v37))
                               * 0.5)
                       + x;
          centerOut->y = (float)((float)((float)(v45 * v28) + (float)(v46 * v36)) * 0.5) + v20[v21].y;
          e0Out->x = v47 * v36;
          e0Out->y = v47 * v28;
          e1Out->y = v48 * v36;
          e1Out->x = v48 * *(float *)&v37;
        }
        v19 = *(__m128 *)_xmm;
        v18 = (__m128)_xmm;
        v13 = 0i64;
      }
      v14 = v15 * 4;
      ++v15;
      --v17;
    }
    while ( v17 );
  }
  resOut->m_enum = HK_SUCCESS;
LABEL_25:
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      m_data,
      4 * array.m_capacityAndFlags);
  return v11;
}

// File Line: 385
// RVA: 0xC6E080
__int64 __fastcall hkVector2Util::getStackSizeInBytesRequiredForConvexHullIndices(unsigned int inputPointsSize)
{
  return 20i64 * inputPointsSize;
}

