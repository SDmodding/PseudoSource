// File Line: 171
// RVA: 0xC67D70
__int64 __fastcall hk1AxisSweep::collide(
        hk1AxisSweep::AabbInt *pa,
        int numA,
        hk1AxisSweep::AabbInt *pb,
        int numB,
        hkKeyPair *pairsOut,
        int maxNumPairs,
        hkPadSpu<int> *numPairsSkipped)
{
  hkKeyPair *v7; // rbx
  int v8; // r11d
  hkKeyPair *v9; // rax
  unsigned int *v10; // rsi
  unsigned int *v11; // r14
  unsigned int v12; // edx
  unsigned int v13; // r8d
  int v14; // ecx
  unsigned int v15; // edi
  _DWORD *v16; // r11
  int v17; // edx
  int v18; // r9d
  unsigned int v19; // ebp
  int v20; // ecx
  unsigned int v21; // r15d
  unsigned int v22; // r13d
  unsigned int v23; // r12d
  int v24; // ecx
  unsigned int v25; // edi
  _DWORD *v26; // r11
  int v27; // edx
  int v28; // r9d
  unsigned int v29; // ebp
  int v30; // ecx
  unsigned int v31; // r15d
  unsigned int v32; // r13d
  unsigned int v33; // r12d
  int v35; // [rsp+40h] [rbp+10h]
  int v36; // [rsp+50h] [rbp+20h]

  v36 = numB;
  v35 = numA;
  v7 = &pairsOut[maxNumPairs];
  v8 = numA;
  numPairsSkipped->m_storage = 0;
  v9 = pairsOut;
  v10 = &pa->m_max[2];
  v11 = &pb->m_max[2];
  while ( 1 )
  {
    while ( 1 )
    {
      v12 = *(v10 - 6);
      v13 = *(v11 - 6);
      if ( v12 <= v13 )
        break;
      v14 = numB--;
      v36 = numB;
      if ( v14 <= 0 )
        return v9 - pairsOut;
      v15 = *(v11 - 2);
      if ( v12 <= v15 )
      {
        v16 = v10 + 3;
        do
        {
          v17 = *(v11 - 5);
          v18 = *(v11 - 4);
          v19 = ((*(v16 - 3) - v18) | (*(v16 - 4) - v17) | (*(v11 - 1) - *(v16 - 8)) | (*v11 - *(v16 - 7))) & 0x80000000;
          v20 = *(v11 - 1);
          v21 = ((v20 - *v16) | (v16[5] - v18) | (v16[4] - v17) | (*v11 - v16[1])) & 0x80000000;
          v22 = ((v16[13] - v18) | (v16[12] - v17) | (v20 - v16[8]) | (*v11 - v16[9])) & 0x80000000;
          v23 = ((v16[21] - v18) | (v16[20] - v17) | (v20 - v16[16]) | (*v11 - v16[17])) & 0x80000000;
          if ( (v21 & v22 & v23 & v19) == 0 )
          {
            if ( !v19 )
            {
              if ( v9 >= v7 )
              {
                ++numPairsSkipped->m_storage;
              }
              else
              {
                ++v9;
                v9[-1].m_keyA = *(v16 - 6);
                v9[-1].m_keyB = *(v11 - 3);
              }
            }
            if ( !v21 && *(v16 - 1) <= v15 )
            {
              if ( v9 >= v7 )
              {
                ++numPairsSkipped->m_storage;
              }
              else
              {
                ++v9;
                v9[-1].m_keyA = v16[2];
                v9[-1].m_keyB = *(v11 - 3);
              }
            }
            if ( !v22 && v16[7] <= v15 )
            {
              if ( v9 >= v7 )
              {
                ++numPairsSkipped->m_storage;
              }
              else
              {
                ++v9;
                v9[-1].m_keyA = v16[10];
                v9[-1].m_keyB = *(v11 - 3);
              }
            }
            if ( !v23 && v16[15] <= v15 )
            {
              if ( v9 >= v7 )
              {
                ++numPairsSkipped->m_storage;
              }
              else
              {
                ++v9;
                v9[-1].m_keyA = v16[18];
                v9[-1].m_keyB = *(v11 - 3);
              }
            }
          }
          v16 += 32;
        }
        while ( *(v16 - 9) <= v15 );
        numB = v36;
        v8 = v35;
      }
      v11 += 8;
    }
    v24 = v8--;
    v35 = v8;
    if ( v24 <= 0 )
      break;
    v25 = *(v10 - 2);
    if ( v13 <= v25 )
    {
      v26 = v11 + 3;
      do
      {
        v27 = *(v10 - 5);
        v28 = *(v10 - 4);
        v29 = ((*(v26 - 3) - v28) | (*(v26 - 4) - v27) | (*(v10 - 1) - *(v26 - 8)) | (*v10 - *(v26 - 7))) & 0x80000000;
        v30 = *(v10 - 1);
        v31 = ((v30 - *v26) | (v26[5] - v28) | (v26[4] - v27) | (*v10 - v26[1])) & 0x80000000;
        v32 = ((v26[13] - v28) | (v26[12] - v27) | (v30 - v26[8]) | (*v10 - v26[9])) & 0x80000000;
        v33 = ((v26[21] - v28) | (v26[20] - v27) | (v30 - v26[16]) | (*v10 - v26[17])) & 0x80000000;
        if ( (v29 & v32 & v33 & v31) == 0 )
        {
          if ( !v29 )
          {
            if ( v9 >= v7 )
            {
              ++numPairsSkipped->m_storage;
            }
            else
            {
              ++v9;
              v9[-1].m_keyA = *(v10 - 3);
              v9[-1].m_keyB = *(v26 - 6);
            }
          }
          if ( !v31 && *(v26 - 1) <= v25 )
          {
            if ( v9 >= v7 )
            {
              ++numPairsSkipped->m_storage;
            }
            else
            {
              ++v9;
              v9[-1].m_keyA = *(v10 - 3);
              v9[-1].m_keyB = v26[2];
            }
          }
          if ( !v32 && v26[7] <= v25 )
          {
            if ( v9 >= v7 )
            {
              ++numPairsSkipped->m_storage;
            }
            else
            {
              ++v9;
              v9[-1].m_keyA = *(v10 - 3);
              v9[-1].m_keyB = v26[10];
            }
          }
          if ( !v33 && v26[15] <= v25 )
          {
            if ( v9 >= v7 )
            {
              ++numPairsSkipped->m_storage;
            }
            else
            {
              ++v9;
              v9[-1].m_keyA = *(v10 - 3);
              v9[-1].m_keyB = v26[18];
            }
          }
        }
        v26 += 32;
      }
      while ( *(v26 - 9) <= v25 );
      numB = v36;
      v8 = v35;
    }
    v10 += 8;
  }
  return v9 - pairsOut;
}

// File Line: 207
// RVA: 0xC68140
void __fastcall hk1AxisSweep::collide(
        hk1AxisSweep::AabbInt *pa,
        int numA,
        hk1AxisSweep::AabbInt *pb,
        int numB,
        hkArray<hkKeyPair,hkContainerHeapAllocator> *pairsOut)
{
  int v5; // r10d
  unsigned int *v6; // r14
  unsigned int *v7; // r15
  unsigned int v8; // ecx
  unsigned int v9; // edx
  int v10; // eax
  unsigned int v11; // esi
  _DWORD *v12; // rdi
  int v13; // ecx
  int v14; // r8d
  unsigned int v15; // r9d
  int v16; // eax
  unsigned int v17; // ebp
  unsigned int v18; // r13d
  unsigned int v19; // r12d
  __int64 m_size; // rdx
  hkKeyPair *v21; // r8
  __int64 v22; // rdx
  hkKeyPair *v23; // r8
  __int64 v24; // rdx
  hkKeyPair *v25; // r8
  __int64 v26; // rdx
  hkKeyPair *v27; // r8
  int v28; // eax
  unsigned int v29; // esi
  _DWORD *v30; // rdi
  unsigned int v31; // r12d
  int v32; // r8d
  unsigned int v33; // r9d
  unsigned int v34; // eax
  unsigned int v35; // ebp
  unsigned int v36; // r13d
  unsigned int v37; // r12d
  __int64 v38; // rdx
  hkKeyPair *v39; // r8
  __int64 v40; // rdx
  hkKeyPair *v41; // r8
  __int64 v42; // rdx
  hkKeyPair *v43; // r8
  __int64 v44; // rdx
  hkKeyPair *v45; // r8
  int v46; // [rsp+68h] [rbp+10h]
  int v47; // [rsp+78h] [rbp+20h]

  v47 = numB;
  v46 = numA;
  v5 = numA;
  v6 = &pa->m_min[2];
  v7 = &pb->m_max[2];
  while ( 1 )
  {
    while ( 1 )
    {
      v8 = *(v6 - 2);
      v9 = *(v7 - 6);
      if ( v8 <= v9 )
        break;
      v10 = numB--;
      v47 = numB;
      if ( v10 <= 0 )
        return;
      v11 = *(v7 - 2);
      if ( v8 <= v11 )
      {
        v12 = v6 + 7;
        do
        {
          v13 = *(v7 - 5);
          v14 = *(v7 - 4);
          v15 = ((*(v12 - 3) - v14) | (*(v12 - 4) - v13) | (*(v7 - 1) - *(v12 - 8)) | (*v7 - *(v12 - 7))) & 0x80000000;
          v16 = *(v7 - 1);
          v17 = ((v16 - *v12) | (v12[5] - v14) | (v12[4] - v13) | (*v7 - v12[1])) & 0x80000000;
          v18 = ((v12[13] - v14) | (v12[12] - v13) | (v16 - v12[8]) | (*v7 - v12[9])) & 0x80000000;
          v19 = ((v12[21] - v14) | (v12[20] - v13) | (v16 - v12[16]) | (*v7 - v12[17])) & 0x80000000;
          if ( (v17 & v18 & v19 & v15) == 0 )
          {
            if ( !v15 )
            {
              if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 8);
              m_size = pairsOut->m_size;
              v21 = &pairsOut->m_data[m_size];
              pairsOut->m_size = m_size + 1;
              v21->m_keyA = *(v12 - 6);
              v21->m_keyB = *(v7 - 3);
            }
            if ( !v17 && *(v12 - 1) <= v11 )
            {
              if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 8);
              v22 = pairsOut->m_size;
              v23 = &pairsOut->m_data[v22];
              pairsOut->m_size = v22 + 1;
              v23->m_keyA = v12[2];
              v23->m_keyB = *(v7 - 3);
            }
            if ( !v18 && v12[7] <= v11 )
            {
              if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 8);
              v24 = pairsOut->m_size;
              v25 = &pairsOut->m_data[v24];
              pairsOut->m_size = v24 + 1;
              v25->m_keyA = v12[10];
              v25->m_keyB = *(v7 - 3);
            }
            if ( !v19 && v12[15] <= v11 )
            {
              if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 8);
              v26 = pairsOut->m_size;
              v27 = &pairsOut->m_data[v26];
              pairsOut->m_size = v26 + 1;
              v27->m_keyA = v12[18];
              v27->m_keyB = *(v7 - 3);
            }
          }
          v12 += 32;
        }
        while ( *(v12 - 9) <= v11 );
        numB = v47;
        v5 = v46;
      }
      v7 += 8;
    }
    v28 = v5--;
    v46 = v5;
    if ( v28 <= 0 )
      break;
    v29 = v6[2];
    if ( v9 <= v29 )
    {
      v30 = v7 + 3;
      do
      {
        v31 = v6[3];
        v32 = *(v6 - 1);
        v33 = ((*(v30 - 4) - v32) | (*(v30 - 3) - *v6) | (v6[4] - *(v30 - 7)) | (v31 - *(v30 - 8))) & 0x80000000;
        v34 = v6[4];
        v35 = ((v31 - *v30) | (v30[4] - v32) | (v30[5] - *v6) | (v34 - v30[1])) & 0x80000000;
        v36 = ((v30[12] - v32) | (v30[13] - *v6) | (v34 - v30[9]) | (v31 - v30[8])) & 0x80000000;
        v37 = ((v30[20] - v32) | (v30[21] - *v6) | (v34 - v30[17]) | (v31 - v30[16])) & 0x80000000;
        if ( (v35 & v36 & v37 & v33) == 0 )
        {
          if ( !v33 )
          {
            if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 8);
            v38 = pairsOut->m_size;
            v39 = &pairsOut->m_data[v38];
            pairsOut->m_size = v38 + 1;
            v39->m_keyA = v6[1];
            v39->m_keyB = *(v30 - 6);
          }
          if ( !v35 && *(v30 - 1) <= v29 )
          {
            if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 8);
            v40 = pairsOut->m_size;
            v41 = &pairsOut->m_data[v40];
            pairsOut->m_size = v40 + 1;
            v41->m_keyA = v6[1];
            v41->m_keyB = v30[2];
          }
          if ( !v36 && v30[7] <= v29 )
          {
            if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 8);
            v42 = pairsOut->m_size;
            v43 = &pairsOut->m_data[v42];
            pairsOut->m_size = v42 + 1;
            v43->m_keyA = v6[1];
            v43->m_keyB = v30[10];
          }
          if ( !v37 && v30[15] <= v29 )
          {
            if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 8);
            v44 = pairsOut->m_size;
            v45 = &pairsOut->m_data[v44];
            pairsOut->m_size = v44 + 1;
            v45->m_keyA = v6[1];
            v45->m_keyB = v30[18];
          }
        }
        v30 += 32;
      }
      while ( *(v30 - 9) <= v29 );
      numB = v47;
      v5 = v46;
    }
    v6 += 8;
  }
}

// File Line: 236
// RVA: 0xC68620
__int64 __fastcall hk1AxisSweep::collide(
        hk1AxisSweep::AabbInt *pa,
        int numA,
        hkKeyPair *pairsOut,
        int maxNumPairs,
        hkPadSpu<int> *numPairsSkipped)
{
  int v5; // r13d
  hkKeyPair *v6; // rsi
  hkKeyPair *v7; // rax
  unsigned int *v8; // rbx
  unsigned int v9; // edi
  _DWORD *v10; // r10
  int v11; // r15d
  int v12; // edx
  int v13; // r9d
  unsigned int v14; // ebp
  unsigned int v15; // r14d
  unsigned int v16; // r12d
  unsigned int v17; // r15d

  v5 = numA - 1;
  v6 = &pairsOut[maxNumPairs];
  numPairsSkipped->m_storage = 0;
  v7 = pairsOut;
  if ( numA - 1 > 0 )
  {
    v8 = &pa->m_max[2];
    do
    {
      v9 = *(v8 - 2);
      if ( v8[2] <= v9 )
      {
        v10 = v8 + 11;
        do
        {
          v11 = *(v8 - 1);
          v12 = *(v8 - 4);
          v13 = *(v8 - 5);
          v14 = ((*(v10 - 4) - v13) | (*(v10 - 3) - v12) | (*v8 - *(v10 - 7)) | (v11 - *(v10 - 8))) & 0x80000000;
          v15 = ((v11 - *v10) | (v10[4] - v13) | (v10[5] - v12) | (*v8 - v10[1])) & 0x80000000;
          v16 = ((v10[12] - v13) | (v10[13] - v12) | (*v8 - v10[9]) | (v11 - v10[8])) & 0x80000000;
          v17 = ((v10[20] - v13) | (v10[21] - v12) | (*v8 - v10[17]) | (v11 - v10[16])) & 0x80000000;
          if ( (v15 & v16 & v17 & v14) == 0 )
          {
            if ( !v14 )
            {
              if ( v7 >= v6 )
              {
                ++numPairsSkipped->m_storage;
              }
              else
              {
                ++v7;
                v7[-1].m_keyA = *(v8 - 3);
                v7[-1].m_keyB = *(v10 - 6);
              }
            }
            if ( !v15 && *(v10 - 1) <= v9 )
            {
              if ( v7 >= v6 )
              {
                ++numPairsSkipped->m_storage;
              }
              else
              {
                ++v7;
                v7[-1].m_keyA = *(v8 - 3);
                v7[-1].m_keyB = v10[2];
              }
            }
            if ( !v16 && v10[7] <= v9 )
            {
              if ( v7 >= v6 )
              {
                ++numPairsSkipped->m_storage;
              }
              else
              {
                ++v7;
                v7[-1].m_keyA = *(v8 - 3);
                v7[-1].m_keyB = v10[10];
              }
            }
            if ( !v17 && v10[15] <= v9 )
            {
              if ( v7 >= v6 )
              {
                ++numPairsSkipped->m_storage;
              }
              else
              {
                ++v7;
                v7[-1].m_keyA = *(v8 - 3);
                v7[-1].m_keyB = v10[18];
              }
            }
          }
          v10 += 32;
        }
        while ( *(v10 - 9) <= v9 );
      }
      --v5;
      v8 += 8;
    }
    while ( v5 > 0 );
  }
  return v7 - pairsOut;
}

// File Line: 260
// RVA: 0xC68830
void __fastcall hk1AxisSweep::collide(
        hk1AxisSweep::AabbInt *pa,
        int numA,
        hkArray<hkKeyPair,hkContainerHeapAllocator> *pairsOut)
{
  int v3; // r13d
  unsigned int *v5; // rsi
  unsigned int v6; // ebp
  _DWORD *v7; // rdi
  int v8; // ecx
  int v9; // r8d
  unsigned int v10; // r9d
  int v11; // eax
  unsigned int v12; // r14d
  unsigned int v13; // r12d
  unsigned int v14; // r15d
  __int64 m_size; // rdx
  hkKeyPair *v16; // r8
  __int64 v17; // rdx
  hkKeyPair *v18; // r8
  __int64 v19; // rdx
  hkKeyPair *v20; // r8
  __int64 v21; // rdx
  hkKeyPair *v22; // r8

  v3 = numA - 1;
  if ( numA - 1 > 0 )
  {
    v5 = &pa->m_max[2];
    do
    {
      v6 = *(v5 - 2);
      if ( v5[2] <= v6 )
      {
        v7 = v5 + 11;
        do
        {
          v8 = *(v5 - 5);
          v9 = *(v5 - 4);
          v10 = ((*(v7 - 3) - v9) | (*(v7 - 4) - v8) | (*(v5 - 1) - *(v7 - 8)) | (*v5 - *(v7 - 7))) & 0x80000000;
          v11 = *(v5 - 1);
          v12 = ((v11 - *v7) | (v7[5] - v9) | (v7[4] - v8) | (*v5 - v7[1])) & 0x80000000;
          v13 = ((v7[13] - v9) | (v7[12] - v8) | (v11 - v7[8]) | (*v5 - v7[9])) & 0x80000000;
          v14 = ((v7[21] - v9) | (v7[20] - v8) | (v11 - v7[16]) | (*v5 - v7[17])) & 0x80000000;
          if ( (v12 & v13 & v14 & v10) == 0 )
          {
            if ( !v10 )
            {
              if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 8);
              m_size = pairsOut->m_size;
              v16 = &pairsOut->m_data[m_size];
              pairsOut->m_size = m_size + 1;
              v16->m_keyA = *(v5 - 3);
              v16->m_keyB = *(v7 - 6);
            }
            if ( !v12 && *(v7 - 1) <= v6 )
            {
              if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 8);
              v17 = pairsOut->m_size;
              v18 = &pairsOut->m_data[v17];
              pairsOut->m_size = v17 + 1;
              v18->m_keyA = *(v5 - 3);
              v18->m_keyB = v7[2];
            }
            if ( !v13 && v7[7] <= v6 )
            {
              if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 8);
              v19 = pairsOut->m_size;
              v20 = &pairsOut->m_data[v19];
              pairsOut->m_size = v19 + 1;
              v20->m_keyA = *(v5 - 3);
              v20->m_keyB = v7[10];
            }
            if ( !v14 && v7[15] <= v6 )
            {
              if ( pairsOut->m_size == (pairsOut->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&pairsOut->m_data, 8);
              v21 = pairsOut->m_size;
              v22 = &pairsOut->m_data[v21];
              pairsOut->m_size = v21 + 1;
              v22->m_keyA = *(v5 - 3);
              v22->m_keyB = v7[18];
            }
          }
          v7 += 32;
        }
        while ( *(v7 - 9) <= v6 );
      }
      --v3;
      v5 += 8;
    }
    while ( v3 > 0 );
  }
}

// File Line: 276
// RVA: 0xC68AC0
void __fastcall hk1AxisSweep::sortAabbs(hk1AxisSweep::AabbInt *aabbs, unsigned int size)
{
  int v3; // esi
  int v5; // ebx
  int v6; // eax
  hkRadixSort::SortData32 *v7; // r14
  int v8; // r15d
  __int64 v9; // r8
  __int64 v10; // rcx
  hk1AxisSweep::AabbInt *v11; // rdx
  unsigned int v12; // eax
  int v13; // eax
  hkRadixSort::SortData32 *v14; // rbp
  int v15; // edi
  unsigned int *p_m_userData; // r9
  int v17; // eax
  _BYTE *v18; // rdi
  int v19; // ebx
  _BYTE *v20; // r8
  __int64 v21; // r10
  int v22; // ecx
  _BYTE *v23; // rdx
  hk1AxisSweep::AabbInt *v24; // rax
  signed __int64 v25; // r11
  unsigned int v26; // edx
  unsigned int v27; // r8d
  unsigned int v28; // eax
  int v29; // [rsp+60h] [rbp+8h] BYREF
  int v30; // [rsp+68h] [rbp+10h] BYREF

  v3 = 0;
  v5 = (size + 3) & 0xFFFFFFFC;
  v6 = v5;
  if ( v5 )
  {
    v30 = 8 * v5;
    v7 = (hkRadixSort::SortData32 *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                      &hkContainerTempAllocator::s_alloc,
                                      &v30);
    v6 = v30 / 8;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = 0x80000000;
  v9 = 0i64;
  if ( v6 )
    v8 = v6;
  v10 = 0i64;
  if ( v5 > 0 )
  {
    v11 = aabbs;
    do
    {
      v12 = v11->m_min[0];
      v7[v10++].m_userData = v9;
      v7[v10 - 1].m_key = v12;
      v9 = (unsigned int)(v9 + 1);
      ++v11;
    }
    while ( v10 < v5 );
  }
  v13 = v5;
  if ( v5 )
  {
    v29 = 8 * v5;
    v14 = (hkRadixSort::SortData32 *)((__int64 (__fastcall *)(hkContainerTempAllocator::Allocator *, int *, __int64, _QWORD))hkContainerTempAllocator::s_alloc.vfptr->bufAlloc)(
                                       &hkContainerTempAllocator::s_alloc,
                                       &v29,
                                       v9,
                                       v5);
    v13 = v29 / 8;
  }
  else
  {
    v14 = 0i64;
  }
  v15 = 0x80000000;
  if ( v13 )
    v15 = v13;
  hkRadixSort::sort32(v7, v5, v14);
  if ( v15 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v14, 8 * v15);
  v17 = size;
  if ( size )
  {
    v29 = 32 * size;
    v18 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v29);
    v17 = v29 / 32;
  }
  else
  {
    v18 = 0i64;
  }
  v19 = 0x80000000;
  if ( v17 )
    v19 = v17;
  if ( (int)size > 0 )
  {
    v20 = v18;
    p_m_userData = &v7->m_userData;
    v21 = size;
    do
    {
      v22 = 2;
      v23 = v20;
      v24 = &aabbs[*p_m_userData];
      do
      {
        --v22;
        v23 += 16;
        *((_OWORD *)v23 - 1) = *(_OWORD *)v24->m_min;
        v24 = (hk1AxisSweep::AabbInt *)((char *)v24 + 16);
      }
      while ( v22 > 0 );
      v20 += 32;
      p_m_userData += 2;
      --v21;
    }
    while ( v21 );
  }
  if ( (int)(2 * size) > 0 )
  {
    p_m_userData = &aabbs->m_min[2];
    v25 = v18 - (_BYTE *)aabbs;
    do
    {
      v26 = *(unsigned int *)((char *)p_m_userData + v25);
      v27 = *(unsigned int *)((char *)p_m_userData + v25 + 4);
      v28 = *(unsigned int *)((char *)p_m_userData + v25 - 8);
      ++v3;
      *(p_m_userData - 1) = *(unsigned int *)((char *)p_m_userData + v25 - 4);
      *p_m_userData = v26;
      p_m_userData[1] = v27;
      *(p_m_userData - 2) = v28;
      p_m_userData += 4;
    }
    while ( v3 < (int)(2 * size) );
  }
  if ( v19 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, _BYTE *, _QWORD, unsigned int *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v18,
      (unsigned int)(32 * v19),
      p_m_userData);
  if ( v8 >= 0 )
    ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, hkRadixSort::SortData32 *, _QWORD, unsigned int *))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerTempAllocator::s_alloc,
      v7,
      (unsigned int)(8 * v8),
      p_m_userData);
}

// File Line: 312
// RVA: 0xC68D20
void __fastcall hk1AxisSweep::sortAabbs(
        hk1AxisSweep::AabbInt *aabbs,
        unsigned int size,
        hkArrayBase<hkRadixSort::SortData32> *sortArray,
        hkArrayBase<hk1AxisSweep::AabbInt> *sortedAabbs)
{
  int v4; // ebx
  int v9; // edx
  unsigned int v10; // r11d
  __int64 v11; // r10
  hk1AxisSweep::AabbInt *v12; // r9
  hkRadixSort::SortData32 *v13; // rcx
  unsigned int v14; // eax
  __int64 v15; // r9
  __int64 v16; // r10
  __int64 v17; // r11
  int v18; // edx
  hk1AxisSweep::AabbInt *v19; // rax
  hk1AxisSweep::AabbInt *v20; // r8
  hk1AxisSweep::AabbInt *m_data; // r10
  unsigned int *v22; // r9
  unsigned int v23; // edx
  unsigned int v24; // r8d
  unsigned int v25; // eax

  v4 = 0;
  v9 = (size + 3) & 0xFFFFFFFC;
  v10 = 0;
  v11 = 0i64;
  if ( v9 > 0 )
  {
    v12 = aabbs;
    do
    {
      ++v12;
      v13 = &sortArray->m_data[v11];
      v14 = v12[-1].m_min[0];
      ++v11;
      v13->m_userData = v10++;
      v13->m_key = v14;
    }
    while ( v11 < v9 );
  }
  hkRadixSort::sort32(sortArray->m_data, v9, (hkRadixSort::SortData32 *)sortedAabbs->m_data);
  if ( (int)size > 0 )
  {
    v15 = 0i64;
    v16 = 0i64;
    v17 = size;
    do
    {
      v18 = 2;
      v19 = &aabbs[sortArray->m_data[v15].m_userData];
      v20 = &sortedAabbs->m_data[v16];
      do
      {
        --v18;
        v20 = (hk1AxisSweep::AabbInt *)((char *)v20 + 16);
        *(_OWORD *)v20[-1].m_max = *(_OWORD *)v19->m_min;
        v19 = (hk1AxisSweep::AabbInt *)((char *)v19 + 16);
      }
      while ( v18 > 0 );
      ++v16;
      ++v15;
      --v17;
    }
    while ( v17 );
  }
  m_data = sortedAabbs->m_data;
  if ( (int)(2 * size) > 0 )
  {
    v22 = &aabbs->m_min[2];
    do
    {
      v23 = m_data->m_min[2];
      v24 = *(_DWORD *)m_data->m_expansionMin;
      v25 = m_data->m_min[0];
      ++v4;
      *(v22 - 1) = m_data->m_min[1];
      *v22 = v23;
      v22[1] = v24;
      *(v22 - 2) = v25;
      v22 += 4;
      m_data = (hk1AxisSweep::AabbInt *)((char *)m_data + 16);
    }
    while ( v4 < (int)(2 * size) );
  }
}

// File Line: 368
// RVA: 0xC67D10
void __fastcall hk1AxisSweep::AabbInt::set(hk1AxisSweep::AabbInt *this, const __m128i *aabbIn, unsigned int key)
{
  __m128i v3; // xmm3

  v3 = _mm_add_epi32(
         _mm_srli_epi32(
           _mm_xor_si128(
             _mm_or_si128(_mm_srai_epi32(_mm_load_si128(aabbIn + 1), 0x1Fu), *(__m128i *)simdSignBit),
             aabbIn[1]),
           1u),
         *(__m128i *)simdOne);
  *(__m128i *)this->m_min = _mm_insert_epi16(
                              _mm_insert_epi16(
                                _mm_srli_epi32(
                                  _mm_xor_si128(
                                    _mm_or_si128(_mm_srai_epi32(_mm_load_si128(aabbIn), 0x1Fu), *(__m128i *)simdSignBit),
                                    *aabbIn),
                                  1u),
                                key,
                                6),
                              HIWORD(key),
                              7);
  *(__m128i *)this->m_max = v3;
}

