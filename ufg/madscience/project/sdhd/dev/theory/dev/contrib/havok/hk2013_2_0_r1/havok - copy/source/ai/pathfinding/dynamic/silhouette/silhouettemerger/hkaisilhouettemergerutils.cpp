// File Line: 19
// RVA: 0xC1C170
void __fastcall hkaiSilhouetteMergerUtils::createNonmergedCompoundSilhouettes(hkaiSilhouetteGeneratorSectionContext *const *generatorContexts, int numGenerators, hkaiSilhouetteGenerationParameters *params, hkArray<hkArray<hkVector4f,hkContainerTempAllocator>,hkContainerTempAllocator> *compoundSilhouettesOut)
{
  hkaiSilhouetteGeneratorSectionContext *const *v4; // rsi
  hkArray<hkArray<hkVector4f,hkContainerTempAllocator>,hkContainerTempAllocator> *v5; // rbp
  hkaiSilhouetteGenerationParameters *v6; // rdi
  __int64 v7; // rbx
  _QWORD *v8; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __int64 v13; // r12
  __m128i *v14; // rax
  __int64 v15; // rcx
  __int64 v16; // rax
  int v17; // er15
  int v18; // ecx
  __int64 v19; // r13
  __int64 v20; // r14
  __int64 v21; // rdx
  signed __int64 v22; // rbx
  int v23; // esi
  int v24; // esi
  signed __int64 v25; // rax
  signed __int64 v26; // rdi
  _OWORD *v27; // rax
  __int64 v28; // rcx
  signed __int64 v29; // rbx
  __int128 v30; // xmm0
  _QWORD *v31; // rax
  _QWORD *v32; // rcx
  _QWORD *v33; // r8
  unsigned __int64 v34; // rax
  signed __int64 v35; // rcx
  __int64 v36; // [rsp+20h] [rbp-68h]
  __int128 v37; // [rsp+30h] [rbp-58h]
  __int128 v38; // [rsp+40h] [rbp-48h]
  hkaiSilhouetteGeneratorSectionContext *const *v39; // [rsp+90h] [rbp+8h]
  int v40; // [rsp+98h] [rbp+10h]
  hkaiSilhouetteGenerationParameters *v41; // [rsp+A0h] [rbp+18h]

  v41 = params;
  v39 = generatorContexts;
  v4 = generatorContexts;
  v5 = compoundSilhouettesOut;
  v6 = params;
  v7 = numGenerators;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  v10 = v8;
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtcreateNonmergedCompoundSilhouettes";
    v11 = __rdtsc();
    v12 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v10[1] = v12;
  }
  v13 = 0i64;
  v36 = v7;
  if ( (signed int)v7 > 0 )
  {
    do
    {
      v14 = (__m128i *)v4[v13];
      v15 = v14[2].m128i_i64[0];
      _mm_store_si128((__m128i *)&v37, *v14);
      _mm_store_si128((__m128i *)&v38, v14[1]);
      v16 = (*(__int64 (__fastcall **)(__int64, __int128 *, hkaiSilhouetteGenerationParameters *, _QWORD *))(*(_QWORD *)v15 + 24i64))(
              v15,
              &v37,
              v6,
              v10);
      v17 = 0;
      v18 = *(_DWORD *)(v16 + 40);
      v19 = v16;
      if ( v18 > 0 )
      {
        v20 = 0i64;
        do
        {
          v21 = *(_QWORD *)(v19 + 32);
          v22 = *(_QWORD *)(v19 + 16) + 16i64 * *(signed int *)(v20 + v21);
          if ( v17 == v18 - 1 )
            v23 = *(_DWORD *)(v19 + 24);
          else
            v23 = *(_DWORD *)(v20 + v21 + 4);
          v24 = v23 - *(_DWORD *)(v20 + v21);
          if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v5, 16);
          v25 = (signed __int64)&v5->m_data[v5->m_size];
          if ( v25 )
          {
            *(_QWORD *)v25 = 0i64;
            *(_DWORD *)(v25 + 8) = 0;
            *(_DWORD *)(v25 + 12) = 2147483648;
          }
          v26 = (signed __int64)&v5->m_data[v5->m_size++];
          if ( (*(_DWORD *)(v26 + 12) & 0x3FFFFFFF) < v24 )
          {
            if ( *(_DWORD *)(v26 + 12) >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                *(void **)v26,
                16 * *(_DWORD *)(v26 + 12));
            v40 = 16 * v24;
            *(_QWORD *)v26 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                               (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                               &v40);
            *(_DWORD *)(v26 + 12) = v40 / 16;
          }
          v27 = *(_OWORD **)v26;
          *(_DWORD *)(v26 + 8) = v24;
          v28 = v24;
          if ( v24 > 0 )
          {
            v29 = v22 - (_QWORD)v27;
            do
            {
              v30 = *(_OWORD *)((char *)v27 + v29);
              ++v27;
              *(v27 - 1) = v30;
              --v28;
            }
            while ( v28 );
          }
          v18 = *(_DWORD *)(v19 + 40);
          ++v17;
          v20 += 4i64;
        }
        while ( v17 < v18 );
        v6 = v41;
        v4 = v39;
      }
      ++v13;
    }
    while ( v13 < v36 );
  }
  v31 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v32 = (_QWORD *)v31[1];
  v33 = v31;
  if ( (unsigned __int64)v32 < v31[3] )
  {
    *v32 = "Et";
    v34 = __rdtsc();
    v35 = (signed __int64)(v32 + 2);
    *(_DWORD *)(v35 - 8) = v34;
    v33[1] = v35;
  }
}

