// File Line: 72
// RVA: 0xC6E1A0
void __fastcall hkVector2Util::`anonymous namespace::Deque<int>::get(hkVector2Util::Deque<int> *this, hkArray<int,hkContainerHeapAllocator> *out)
{
  hkArray<int,hkContainerHeapAllocator> *v2; // rdi
  int v3; // esi
  int *v4; // rbp
  signed int v5; // ebx
  int *v6; // rax
  __int64 v7; // r9
  char *v8; // r10
  int v9; // ecx
  int v10; // [rsp+30h] [rbp+8h]

  v2 = out;
  v3 = this->m_top - this->m_bot;
  v4 = &this->m_vals.m_data.m_storage[this->m_bot];
  v5 = v3 | 0x80000000;
  if ( (out->m_capacityAndFlags & 0x3FFFFFFF) < v3 )
  {
    if ( out->m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        out->m_data,
        4 * out->m_capacityAndFlags);
    v10 = 4 * v3;
    v2->m_data = (int *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                          &v10);
    v2->m_capacityAndFlags = v10 / 4;
  }
  v6 = v2->m_data;
  v2->m_size = v3;
  v7 = v3;
  if ( v3 > 0 )
  {
    v8 = (char *)((char *)v4 - (char *)v6);
    do
    {
      v9 = *(int *)((char *)v6 + (_QWORD)v8);
      ++v6;
      *(v6 - 1) = v9;
      --v7;
    }
    while ( v7 );
  }
  if ( v5 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v4,
      (unsigned int)(4 * v5),
      v7);
}

// File Line: 86
// RVA: 0xC6CCC0
void __fastcall hkVector2Util::convexHullSimplePolyline(hkArrayBase<hkVector2f> *line, hkArray<int,hkContainerHeapAllocator> *indicesOut)
{
  signed __int64 v2; // rsi
  hkArrayBase<hkVector2f> *v3; // r15
  hkArray<int,hkContainerHeapAllocator> *v4; // r13
  int v5; // er12
  hkLifoAllocator *v6; // rax
  int *v7; // rdi
  int v8; // edx
  char *v9; // r8
  float *v10; // rcx
  int v11; // er9
  int v12; // edx
  int v13; // ebx
  signed int v14; // er14
  int v15; // er9
  hkVector2f *v16; // r11
  __int64 v17; // rdx
  hkVector2f v18; // rax
  __int64 v19; // r8
  hkVector2f v20; // rcx
  signed __int64 v21; // r10
  float v22; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm8_4
  float v25; // xmm9_4
  float v26; // xmm10_4
  float v27; // xmm11_4
  float v28; // xmm6_4
  float v29; // xmm7_4
  hkVector2f v30; // ST10_8
  hkVector2f *v31; // r11
  float v32; // xmm1_4
  float v33; // xmm0_4
  hkVector2f v34; // kr08_8
  __int64 v35; // rax
  signed int v36; // ebx
  hkLifoAllocator *v37; // rax
  int v38; // er8
  __int64 v39; // [rsp+10h] [rbp-59h]
  hkVector2Util::Deque<int> v40; // [rsp+18h] [rbp-51h]
  __int64 vars0; // [rsp+D0h] [rbp+67h]
  hkVector2f v42; // [rsp+E8h] [rbp+7Fh]
  hkVector2f v43; // [rsp+E8h] [rbp+7Fh]

  v2 = line->m_size;
  v3 = line;
  v4 = indicesOut;
  v5 = 2 * v2 - 2;
  v6 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (int *)v6->m_cur;
  v8 = (4 * v5 + 127) & 0xFFFFFF80;
  v9 = (char *)v7 + v8;
  if ( v8 > v6->m_slabSize || v9 > v6->m_end )
    v7 = (int *)hkLifoAllocator::allocateFromNewSlab(v6, v8);
  else
    v6->m_cur = v9;
  v10 = (float *)v3->m_data;
  v40.m_vals.m_data.m_storage = v7;
  v40.m_vals.m_size.m_storage = 2 * v2 - 2;
  v11 = v5 / 2 + 1;
  v12 = v5 / 2;
  if ( (float)((float)((float)(v10[5] - v10[1]) * (float)(v10[2] - *v10))
             - (float)((float)(v10[3] - v10[1]) * (float)(v10[4] - *v10))) <= 0.0 )
  {
    v7[v12] = 1;
    v7[v11] = 0;
  }
  else
  {
    v7[v12] = 0;
    v7[v11] = 1;
  }
  v13 = v12 - 1;
  v14 = 3;
  v15 = v5 / 2 + 3;
  v7[v13] = 2;
  v7[v5 / 2 + 2] = 2;
  v16 = v3->m_data;
  v17 = (__int64)v3->m_data[v7[v12 - 1]];
  v18 = v3->m_data[v7[v15 - 2]];
  v19 = (__int64)v3->m_data[v7[v13 + 1]];
  v20 = v3->m_data[v7[v15 - 1]];
  v42 = v3->m_data[v7[v15 - 2]];
  v40.m_bot = v13;
  v40.m_top = v5 / 2 + 3;
  vars0 = v17;
  v39 = v19;
  v21 = 3i64;
  if ( v2 > 3 )
  {
    v22 = *((float *)&vars0 + 1);
    v23 = *(float *)&vars0;
    v24 = v20.y;
    v25 = v42.y;
    v26 = v42.x;
    v27 = v20.x;
    do
    {
      if ( (float)((float)((float)(v16[v21].y - v22) * (float)(*(float *)&v39 - v23))
                 - (float)((float)(v16[v21].x - v23) * (float)(*((float *)&v39 + 1) - v22))) <= 0.0
        || (float)((float)((float)(v16[v21].y - v25) * (float)(v27 - v26))
                 - (float)((float)(v24 - v25) * (float)(v16[v21].x - v26))) <= 0.0 )
      {
        if ( (float)((float)((float)(v16[v21].y - v22) * (float)(*(float *)&v39 - v23))
                   - (float)((float)(v16[v21].x - v23) * (float)(*((float *)&v39 + 1) - v22))) <= 0.0 )
        {
          v28 = v16[v21].y;
          v29 = v16[v21].x;
          do
          {
            v17 = v19;
            ++v13;
            vars0 = v19;
            v19 = (__int64)v16[v7[v13 + 1]];
            v30 = v16[v7[v13 + 1]];
          }
          while ( (float)((float)((float)(v30.x - *(float *)&vars0) * (float)(v28 - *((float *)&vars0 + 1)))
                        - (float)((float)(v30.y - *((float *)&vars0 + 1)) * (float)(v29 - *(float *)&vars0))) <= 0.0 );
        }
        v39 = v17;
        v7[--v13] = v14;
        v31 = v3->m_data;
        v19 = v17;
        v40.m_bot = v13;
        v32 = v31[v21].y;
        v17 = (__int64)v31[v14];
        v33 = v31[v21].x - v26;
        vars0 = (__int64)v31[v14];
        if ( (float)((float)((float)(v32 - v25) * (float)(v27 - v26)) - (float)((float)(v24 - v25) * v33)) <= 0.0 )
        {
          do
          {
            v34 = v18;
            v20 = v18;
            v18 = v31[v7[--v15 - 2]];
            v43 = v31[v7[v15 - 2]];
          }
          while ( (float)((float)((float)(v31[v21].y - v43.y) * (float)(v34.x - v43.x))
                        - (float)((float)(v34.y - v43.y) * (float)(v31[v21].x - v43.x))) <= 0.0 );
        }
        v22 = *((float *)&vars0 + 1);
        v23 = *(float *)&vars0;
        v35 = v15++;
        v7[v35] = v14;
        v16 = v3->m_data;
        v18 = v20;
        v25 = v20.y;
        v26 = v20.x;
        v40.m_top = v15;
        v20 = v16[v7[v15 - 1]];
        LODWORD(v24) = *(_QWORD *)&v16[v7[v15 - 1]] >> 32;
        LODWORD(v27) = v16[v7[v15 - 1]];
      }
      ++v21;
      ++v14;
    }
    while ( v21 < v2 );
  }
  hkVector2Util::`anonymous namespace::Deque<int>::get(&v40, v4);
  v36 = (4 * v5 + 127) & 0xFFFFFF80;
  v37 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v38 = (v36 + 15) & 0xFFFFFFF0;
  if ( v36 > v37->m_slabSize || (char *)v7 + v38 != v37->m_cur || v37->m_firstNonLifoEnd == v7 )
    hkLifoAllocator::slowBlockFree(v37, v7, v38);
  else
    v37->m_cur = v7;
}

// File Line: 140
// RVA: 0xC6D290
hkResult *__fastcall hkVector2Util::convexHullIndices(hkResult *result, hkArrayBase<hkVector2f> *originalPoints, hkArrayBase<int> *indicesOut)
{
  signed __int64 v3; // rbp
  hkResult *v4; // r12
  hkArrayBase<int> *v5; // rbx
  hkArrayBase<hkVector2f> *v6; // r14
  hkLifoAllocator *v7; // rax
  float *v8; // rdi
  int v9; // er13
  char *v10; // rdx
  hkLifoAllocator *v11; // rax
  int *v12; // rsi
  int v13; // er15
  char *v14; // rcx
  int v15; // ecx
  signed __int64 v16; // rax
  signed __int64 v17; // r15
  signed int v18; // ebp
  int v19; // er9
  signed __int64 v20; // r10
  __int64 v21; // rcx
  float *v22; // rdx
  int *v23; // r8
  unsigned __int64 v24; // r12
  __int64 v25; // rax
  hkVector2f *v26; // r11
  __int64 v27; // rax
  hkVector2f *v28; // r11
  __int64 v29; // rax
  hkVector2f *v30; // r11
  __int64 v31; // rax
  hkVector2f *v32; // r11
  __int64 v33; // rax
  hkVector2f *v34; // rdx
  int v35; // er13
  hkLifoAllocator *v36; // rax
  _QWORD *v37; // r14
  int v38; // edx
  char *v39; // rcx
  signed int v40; // er12
  hkResult *v41; // r15
  unsigned int v42; // ecx
  signed int v43; // ebx
  hkLifoAllocator *v44; // rax
  int v45; // er8
  int v46; // ebp
  signed int v47; // ebx
  hkLifoAllocator *v48; // rax
  int v49; // er8
  signed int v50; // ebx
  hkLifoAllocator *v51; // rax
  int v52; // er8
  hkResult *v53; // rax
  float v54; // xmm0_4
  signed __int64 v55; // rcx
  __int64 v56; // r15
  signed int v57; // er11
  float *v58; // rdx
  int v59; // ebx
  unsigned int v60; // ecx
  signed int v61; // ebx
  hkLifoAllocator *v62; // rax
  int v63; // er8
  signed int v64; // ebx
  float v65; // xmm0_4
  int v66; // edx
  int v67; // er11
  signed __int64 v68; // rcx
  float *v69; // rax
  signed __int64 v70; // r13
  signed int v71; // er9
  signed __int64 v72; // r10
  __int64 v73; // kr00_8
  float v74; // xmm8_4
  float v75; // xmm9_4
  __int64 v76; // rax
  float v77; // xmm5_4
  int v78; // er8
  signed __int64 v79; // r9
  float v80; // xmm8_4
  float v81; // xmm9_4
  __int64 v82; // rax
  float v83; // xmm5_4
  int v84; // er8
  unsigned int v85; // ecx
  hkLifoAllocator *v86; // rax
  int v87; // er8
  hkLifoAllocator *v88; // rax
  int v89; // er8
  int v90; // [rsp+20h] [rbp-B8h]
  int v91; // [rsp+24h] [rbp-B4h]
  __int64 v92; // [rsp+28h] [rbp-B0h]
  __int64 v93; // [rsp+30h] [rbp-A8h]
  __int64 v94; // [rsp+30h] [rbp-A8h]
  __int64 v95; // [rsp+30h] [rbp-A8h]
  hkResult *v96; // [rsp+E0h] [rbp+8h]
  int v97; // [rsp+E8h] [rbp+10h]
  __int64 v98; // [rsp+F8h] [rbp+20h]
  __int64 v99; // [rsp+F8h] [rbp+20h]

  v96 = result;
  v3 = originalPoints->m_size;
  v4 = result;
  v5 = indicesOut;
  v6 = originalPoints;
  v97 = originalPoints->m_size;
  v7 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (float *)v7->m_cur;
  v9 = (8 * v3 + 127) & 0xFFFFFF80;
  v10 = (char *)v8 + v9;
  if ( v9 > v7->m_slabSize || v10 > v7->m_end )
    v8 = (float *)hkLifoAllocator::allocateFromNewSlab(v7, v9);
  else
    v7->m_cur = v10;
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (int *)v11->m_cur;
  v13 = (4 * v3 + 127) & 0xFFFFFF80;
  v14 = (char *)v12 + v13;
  if ( v13 > v11->m_slabSize || v14 > v11->m_end )
    v12 = (int *)hkLifoAllocator::allocateFromNewSlab(v11, v13);
  else
    v11->m_cur = v14;
  if ( v8 && v12 )
  {
    v15 = 0;
    v16 = 0i64;
    v17 = v3;
    if ( (signed int)v3 > 0 )
    {
      do
        v12[v16++] = v15++;
      while ( v16 < v3 );
    }
    if ( (signed int)v3 > 1 )
      hkAlgorithm::quickSortRecursive<int,hkVector2Util::`anonymous namespace::IndexedLess>(
        v12,
        0,
        v3 - 1,
        (hkVector2Util::IndexedLess)v6);
    v18 = 1;
    v19 = 0;
    v20 = 1i64;
    *(hkVector2f *)v8 = v6->m_data[*v12];
    v21 = 0i64;
    if ( v17 > 1 )
    {
      if ( v17 - 1 >= 4 )
      {
        v22 = v8;
        v23 = v12 + 3;
        v24 = ((unsigned __int64)(v17 - 5) >> 2) + 1;
        v20 = 4 * v24 + 1;
        do
        {
          v25 = *(v23 - 2);
          v26 = v6->m_data;
          if ( v6->m_data[v25].x != *v22 || v26[v25].y != v22[1] )
          {
            ++v19;
            *(hkVector2f *)&v8[2 * ++v21] = v26[v25];
            v22 = &v8[2 * v21];
            v12[v21] = *(v23 - 2);
          }
          v27 = *(v23 - 1);
          v28 = v6->m_data;
          if ( v6->m_data[v27].x != *v22 || v28[v27].y != v22[1] )
          {
            ++v19;
            *(hkVector2f *)&v8[2 * ++v21] = v28[v27];
            v22 = &v8[2 * v21];
            v12[v21] = *(v23 - 1);
          }
          v29 = *v23;
          v30 = v6->m_data;
          if ( v6->m_data[v29].x != *v22 || v30[v29].y != v22[1] )
          {
            ++v19;
            *(hkVector2f *)&v8[2 * ++v21] = v30[v29];
            v22 = &v8[2 * v21];
            v12[v21] = *v23;
          }
          v31 = v23[1];
          v32 = v6->m_data;
          if ( v6->m_data[v31].x != *v22 || v32[v31].y != v22[1] )
          {
            ++v19;
            *(hkVector2f *)&v8[2 * ++v21] = v32[v31];
            v22 = &v8[2 * v21];
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
        v34 = v6->m_data;
        if ( v6->m_data[v33].x != v8[2 * v21] || v34[v33].y != v8[2 * v21 + 1] )
        {
          ++v19;
          *(hkVector2f *)&v8[2 * ++v21] = v34[v33];
          v12[v21] = v12[v20];
        }
      }
    }
    v35 = v19 + 1;
    v91 = v19 + 1;
    if ( v19 == -1 )
    {
      v37 = 0i64;
    }
    else
    {
      v36 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v37 = v36->m_cur;
      v38 = (8 * v35 + 127) & 0xFFFFFF80;
      v39 = (char *)v37 + v38;
      if ( v38 > v36->m_slabSize || v39 > v36->m_end )
        v37 = hkLifoAllocator::allocateFromNewSlab(v36, v38);
      else
        v36->m_cur = v39;
    }
    v40 = v35 | 0x80000000;
    if ( v37 )
    {
      v54 = *v8;
      v55 = 1i64;
      v56 = v35;
      v57 = 1;
      v90 = v35 - 1;
      if ( v35 > 1i64 )
      {
        if ( v35 - 1i64 < 4 )
        {
LABEL_68:
          while ( v55 < v35 )
          {
            if ( v54 != v8[2 * v55] )
              break;
            ++v55;
            ++v57;
          }
        }
        else
        {
          v58 = v8 + 6;
          while ( v54 == *(v58 - 4) )
          {
            if ( v54 != *(v58 - 2) )
            {
              ++v57;
              break;
            }
            if ( v54 != *v58 )
            {
              v57 += 2;
              break;
            }
            if ( v54 != v58[2] )
            {
              v57 += 3;
              break;
            }
            v55 += 4i64;
            v57 += 4;
            v58 += 8;
            if ( v55 >= v35 - 3i64 )
              goto LABEL_68;
          }
        }
      }
      if ( v57 == v35 )
      {
        v5->m_data[v5->m_size++] = 0;
        if ( v8[1] != v8[2 * v35 - 1] )
        {
          v5->m_data[v5->m_size++] = v35 - 1;
          v5->m_data[v5->m_size++] = 0;
        }
        v59 = 8 * v35 + 127;
      }
      else
      {
        v65 = v8[2 * v35 - 2];
        v66 = v35 - 2;
        v67 = v57 - 1;
        v68 = v35 - 2;
        if ( v35 - 2 >= 0 )
        {
          if ( v66 + 1i64 < 4 )
          {
LABEL_97:
            while ( v68 >= 0 )
            {
              if ( v65 != v8[2 * v68] )
                break;
              --v66;
              --v68;
            }
          }
          else
          {
            v69 = &v8[2 * (v66 - 2i64)];
            while ( v65 == v69[4] )
            {
              if ( v65 != v69[2] )
              {
                --v66;
                break;
              }
              if ( v65 != *v69 )
              {
                v66 -= 2;
                break;
              }
              if ( v65 != *(v69 - 2) )
              {
                v66 -= 3;
                break;
              }
              v68 -= 4i64;
              v66 -= 4;
              v69 -= 8;
              if ( v68 < 3 )
                goto LABEL_97;
            }
          }
        }
        v70 = v66 + 1;
        v93 = *(_QWORD *)v8;
        v71 = 1;
        v92 = *(_QWORD *)&v8[2 * v70];
        v5->m_data[v5->m_size++] = *v12;
        *v37 = v93;
        v72 = v67;
        if ( v67 <= v70 )
        {
          v73 = v93;
          v74 = *(float *)&v92 - *(float *)&v93;
          v75 = *((float *)&v92 + 1) - *((float *)&v93 + 1);
          do
          {
            v76 = *(_QWORD *)&v8[2 * v72];
            v94 = *(_QWORD *)&v8[2 * v72];
            LODWORD(v77) = *(_QWORD *)&v8[2 * v72] >> 32;
            if ( (float)((float)((float)(*((float *)&v94 + 1) - *((float *)&v73 + 1)) * v74)
                       - (float)((float)(*(float *)&v94 - *(float *)&v73) * v75)) < 0.0
              || v72 >= v70 )
            {
              if ( v71 >= 2 )
              {
                v78 = v71 - 2;
                do
                {
                  if ( (float)((float)((float)(*(float *)&v37[v78 + 1] - *(float *)&v37[v78])
                                     * (float)(v77 - *((float *)&v37[v78] + 1)))
                             - (float)((float)(*((float *)&v37[v78 + 1] + 1) - *((float *)&v37[v78] + 1))
                                     * (float)(*(float *)&v94 - *(float *)&v37[v78]))) > 0.0 )
                    break;
                  --v5->m_size;
                  --v71;
                  --v78;
                }
                while ( v71 >= 2 );
              }
              v5->m_data[v5->m_size++] = v12[v72];
              v37[v71++] = v76;
            }
            ++v72;
          }
          while ( v72 <= v70 );
        }
        if ( v90 != v66 + 1 )
          v5->m_data[v5->m_size++] = v12[v90];
        *v37 = *(_QWORD *)&v8[2 * v56 - 2];
        v95 = *(_QWORD *)&v8[2 * v56 - 2];
        v98 = *(_QWORD *)&v8[2 * v67];
        v79 = v66;
        if ( v66 >= (signed __int64)v67 )
        {
          v80 = *(float *)&v98 - *(float *)&v95;
          v81 = *((float *)&v98 + 1) - *((float *)&v95 + 1);
          do
          {
            v82 = *(_QWORD *)&v8[2 * v79];
            v99 = *(_QWORD *)&v8[2 * v79];
            LODWORD(v83) = *(_QWORD *)&v8[2 * v79] >> 32;
            if ( (float)((float)((float)(*((float *)&v99 + 1) - *((float *)&v95 + 1)) * v80)
                       - (float)((float)(*(float *)&v99 - *(float *)&v95) * v81)) < 0.0
              || v79 <= v67 )
            {
              if ( v18 >= 2 )
              {
                v84 = v18 - 2;
                do
                {
                  if ( (float)((float)((float)(*(float *)&v37[v84 + 1] - *(float *)&v37[v84])
                                     * (float)(v83 - *((float *)&v37[v84] + 1)))
                             - (float)((float)(*((float *)&v37[v84 + 1] + 1) - *((float *)&v37[v84] + 1))
                                     * (float)(*(float *)&v99 - *(float *)&v37[v84]))) > 0.0 )
                    break;
                  --v5->m_size;
                  --v18;
                  --v84;
                }
                while ( v18 >= 2 );
              }
              v5->m_data[v5->m_size++] = v12[v79];
              v37[v18++] = v82;
            }
            --v79;
          }
          while ( v79 >= v67 );
        }
        if ( v67 )
          v5->m_data[v5->m_size++] = *v12;
        v59 = 8 * v91 + 127;
      }
      v41 = v96;
      v60 = hkMemoryRouter::s_memoryRouter.m_slotID;
      v61 = v59 & 0xFFFFFF80;
      v96->m_enum = 0;
      v62 = (hkLifoAllocator *)TlsGetValue(v60);
      v63 = (v61 + 15) & 0xFFFFFFF0;
      if ( v61 > v62->m_slabSize || (char *)v37 + v63 != v62->m_cur || v62->m_firstNonLifoEnd == v37 )
        hkLifoAllocator::slowBlockFree(v62, v37, v63);
      else
        v62->m_cur = v37;
      if ( v40 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v37,
          8 * v40);
      v46 = v97;
      v64 = (4 * v97 + 127) & 0xFFFFFF80;
      v48 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v49 = (v64 + 15) & 0xFFFFFFF0;
      if ( v64 <= v48->m_slabSize && (char *)v12 + v49 == v48->m_cur && v48->m_firstNonLifoEnd != v12 )
      {
        v48->m_cur = v12;
        goto LABEL_55;
      }
    }
    else
    {
      v41 = v96;
      v42 = hkMemoryRouter::s_memoryRouter.m_slotID;
      v96->m_enum = 1;
      v43 = (8 * v35 + 127) & 0xFFFFFF80;
      v44 = (hkLifoAllocator *)TlsGetValue(v42);
      v45 = (v43 + 15) & 0xFFFFFFF0;
      if ( v43 <= v44->m_slabSize && (void *)v45 == v44->m_cur && v44->m_firstNonLifoEnd )
        v44->m_cur = 0i64;
      else
        hkLifoAllocator::slowBlockFree(v44, 0i64, v45);
      if ( v40 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          0i64,
          8 * v40);
      v46 = v97;
      v47 = (4 * v97 + 127) & 0xFFFFFF80;
      v48 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v49 = (v47 + 15) & 0xFFFFFFF0;
      if ( v47 <= v48->m_slabSize && (char *)v12 + v49 == v48->m_cur && v48->m_firstNonLifoEnd != v12 )
      {
        v48->m_cur = v12;
LABEL_55:
        v50 = (8 * v46 + 127) & 0xFFFFFF80;
        v51 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v52 = (v50 + 15) & 0xFFFFFFF0;
        if ( v50 > v51->m_slabSize || (char *)v8 + v52 != v51->m_cur || v51->m_firstNonLifoEnd == v8 )
        {
          hkLifoAllocator::slowBlockFree(v51, v8, v52);
          v53 = v41;
        }
        else
        {
          v51->m_cur = v8;
          v53 = v41;
        }
        return v53;
      }
    }
    hkLifoAllocator::slowBlockFree(v48, v12, v49);
    goto LABEL_55;
  }
  v85 = hkMemoryRouter::s_memoryRouter.m_slotID;
  v4->m_enum = 1;
  v86 = (hkLifoAllocator *)TlsGetValue(v85);
  v87 = (v13 + 15) & 0xFFFFFFF0;
  if ( v13 > v86->m_slabSize || (char *)v12 + v87 != v86->m_cur || v86->m_firstNonLifoEnd == v12 )
    hkLifoAllocator::slowBlockFree(v86, v12, v87);
  else
    v86->m_cur = v12;
  v88 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v89 = (v9 + 15) & 0xFFFFFFF0;
  if ( v9 > v88->m_slabSize || (char *)v8 + v89 != v88->m_cur || v88->m_firstNonLifoEnd == v8 )
    hkLifoAllocator::slowBlockFree(v88, v8, v89);
  else
    v88->m_cur = v8;
  return v4;
}

// File Line: 288
// RVA: 0xC6D160
void __fastcall hkVector2Util::convexHullVertices(hkArrayBase<hkVector2f> *points, hkArray<hkVector2f,hkContainerHeapAllocator> *hullOut)
{
  int v2; // edi
  hkArray<hkVector2f,hkContainerHeapAllocator> *v3; // rbx
  hkArrayBase<hkVector2f> *v4; // rsi
  int v5; // er9
  int v6; // ecx
  int v7; // er10
  __int64 v8; // r9
  hkArrayBase<int> indicesOut; // [rsp+30h] [rbp-18h]
  hkResult result; // [rsp+50h] [rbp+8h]

  v2 = points->m_size;
  v3 = hullOut;
  v4 = points;
  indicesOut.m_capacityAndFlags = 2147483648;
  indicesOut.m_data = 0i64;
  indicesOut.m_size = 0;
  if ( v2 > 0 )
  {
    v5 = v2;
    if ( v2 < 0 )
      v5 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &indicesOut, v5, 4);
  }
  indicesOut.m_size = v2;
  hkVector2Util::convexHullIndices(&result, v4, &indicesOut);
  v6 = indicesOut.m_size;
  if ( (v3->m_capacityAndFlags & 0x3FFFFFFF) < indicesOut.m_size )
  {
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v3,
      indicesOut.m_size,
      8);
    v6 = indicesOut.m_size;
  }
  v7 = 0;
  if ( v6 > 0 )
  {
    v8 = 0i64;
    do
    {
      ++v7;
      ++v8;
      v3->m_data[v3->m_size++] = v4->m_data[indicesOut.m_data[v8 - 1]];
    }
    while ( v7 < indicesOut.m_size );
  }
  indicesOut.m_size = 0;
  if ( indicesOut.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      indicesOut.m_data,
      4 * indicesOut.m_capacityAndFlags);
}

// File Line: 300
// RVA: 0xC6CBD0
hkBool *__fastcall hkVector2Util::edgesIntersect(hkBool *result, hkVector2f *a, hkVector2f *b, hkVector2f *c, hkVector2f *d)
{
  float v5; // xmm8_4
  float v6; // xmm2_4
  float v7; // xmm5_4
  float v8; // xmm4_4
  float v9; // xmm8_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm9_4
  float v13; // xmm3_4
  float v14; // xmm8_4

  v5 = a->y;
  v6 = d->x - c->x;
  v7 = d->y - c->y;
  v8 = b->y - v5;
  v9 = v5 - c->y;
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
float __fastcall hkVector2Util::computeObb(hkArrayBase<hkVector2f> *points, hkVector2f *centerOut, hkVector2f *e0Out, hkVector2f *e1Out, hkResult *resOut)
{
  hkVector2f *v5; // rbp
  int v6; // er9
  hkVector2f *v7; // r14
  hkVector2f *v8; // r15
  hkArrayBase<hkVector2f> *v9; // rsi
  char *v10; // rbx
  float v11; // xmm14_4
  unsigned int v12; // ecx
  __m128 v13; // xmm6
  signed __int64 v14; // rax
  signed __int64 v15; // r9
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
  float v29; // xmm11_4
  float v30; // xmm7_4
  float v31; // xmm6_4
  float v32; // xmm4_4
  signed int *v33; // rcx
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
  hkResult result[2]; // [rsp+30h] [rbp-E8h]
  char *array; // [rsp+38h] [rbp-E0h]
  unsigned int v52; // [rsp+40h] [rbp-D8h]
  int v53; // [rsp+44h] [rbp-D4h]
  int v54; // [rsp+120h] [rbp+8h]

  v5 = e1Out;
  v6 = points->m_size + 1;
  v7 = e0Out;
  v8 = centerOut;
  v9 = points;
  array = 0i64;
  v52 = 0;
  v53 = 2147483648;
  if ( v6 <= 0 )
  {
    v54 = 0;
  }
  else
  {
    if ( v6 < 0 )
      v6 = 0;
    hkArrayUtil::_reserve(
      (hkResult *)&v54,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array,
      v6,
      4);
    if ( v54 )
      goto LABEL_8;
  }
  hkVector2Util::convexHullIndices(result, v9, (hkArrayBase<int> *)&array);
  if ( result[0].m_enum )
  {
LABEL_8:
    v10 = array;
    v11 = 0.0;
    resOut->m_enum = 1;
    goto LABEL_27;
  }
  v11 = FLOAT_3_40282e38;
  v10 = array;
  v12 = v52 - 1;
  v52 = v12;
  if ( (signed int)v12 > 0 )
  {
    v13 = 0i64;
    v14 = 4i64 * (signed int)(v12 - 1);
    v15 = 0i64;
    v16 = v12;
    v17 = v12;
    v18 = (__m128)_xmm;
    v19 = *(__m128 *)_xmm;
    do
    {
      v20 = v9->m_data;
      v21 = *(signed int *)&v10[v14];
      v22 = *(signed int *)&v10[v15];
      *(float *)&v23.m_enum = v9->m_data[v22].y - v9->m_data[v21].y;
      *(float *)&result[0].m_enum = v9->m_data[v22].x - v9->m_data[v21].x;
      result[1] = v23;
      v24 = _mm_mul_ps((__m128)*(unsigned __int64 *)&result[0].m_enum, (__m128)*(unsigned __int64 *)&result[0].m_enum);
      v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0));
      v26 = _mm_rsqrt_ps(v25);
      v27 = _mm_andnot_ps(
              _mm_cmpleps(v25, v13),
              _mm_mul_ps(_mm_sub_ps(v18, _mm_mul_ps(_mm_mul_ps(v26, v25), v26)), _mm_mul_ps(v19, v26)));
      *(_QWORD *)&result[0].m_enum = (unsigned __int128)_mm_mul_ps((__m128)*(unsigned __int64 *)&result[0].m_enum, v27);
      if ( (float)(v27.m128_f32[0] * v25.m128_f32[0]) != 0.0 )
      {
        v28 = *(float *)&result[1].m_enum;
        v29 = v20[v21].x;
        v30 = 0.0;
        v31 = 0.0;
        v32 = 0.0;
        v33 = (signed int *)v10;
        v34 = v16;
        v35 = 0.0;
        v36 = *(float *)&result[0].m_enum;
        v37 = result[1].m_enum ^ _xmm[0];
        do
        {
          v38 = *v33;
          v39 = v20[v38].x - v29;
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
          v8->x = (float)((float)((float)(v45 * *(float *)&result[0].m_enum) + (float)(v46 * *(float *)&v37)) * 0.5)
                + v29;
          v8->y = (float)((float)((float)(v45 * v28) + (float)(v46 * v36)) * 0.5) + v20[v21].y;
          v7->x = v47 * v36;
          v7->y = v47 * v28;
          v5->y = v48 * v36;
          v5->x = v48 * *(float *)&v37;
        }
        v19 = *(__m128 *)_xmm;
        v18 = (__m128)_xmm;
        v13 = 0i64;
      }
      v14 = v15;
      v15 += 4i64;
      --v17;
    }
    while ( v17 );
  }
  resOut->m_enum = 0;
LABEL_27:
  v52 = 0;
  if ( v53 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v10,
      4 * v53);
  return v11;
}

// File Line: 385
// RVA: 0xC6E080
signed __int64 __fastcall hkVector2Util::getStackSizeInBytesRequiredForConvexHullIndices(int inputPointsSize)
{
  return 20i64 * (unsigned int)inputPointsSize;
}

