// File Line: 19
// RVA: 0xC1C170
void __fastcall hkaiSilhouetteMergerUtils::createNonmergedCompoundSilhouettes(
        hkaiSilhouetteGeneratorSectionContext *const *generatorContexts,
        int numGenerators,
        hkaiSilhouetteGenerationParameters *params,
        hkArray<hkArray<hkVector4f,hkContainerTempAllocator>,hkContainerTempAllocator> *compoundSilhouettesOut)
{
  hkaiSilhouetteGeneratorSectionContext *const *v4; // rsi
  hkaiSilhouetteGenerationParameters *v6; // rdi
  __int64 v7; // rbx
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r9
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  __int64 v13; // r12
  hkaiSilhouetteGeneratorSectionContext *v14; // rax
  hkaiSilhouetteGenerator *m_generator; // rcx
  __int64 v16; // rax
  int v17; // r15d
  int v18; // ecx
  __int64 v19; // r13
  __int64 v20; // r14
  __int64 v21; // rdx
  __int64 v22; // rbx
  int v23; // esi
  int v24; // esi
  hkArray<hkVector4f,hkContainerTempAllocator> *v25; // rax
  hkArray<hkVector4f,hkContainerTempAllocator> *v26; // rdi
  hkVector4f *m_data; // rax
  __int64 v28; // rcx
  __int64 v29; // rbx
  hkVector4f v30; // xmm0
  _QWORD *v31; // rax
  _QWORD *v32; // rcx
  _QWORD *v33; // r8
  unsigned __int64 v34; // rax
  _QWORD *v35; // rcx
  __int64 v36; // [rsp+20h] [rbp-68h]
  __int128 v37[2]; // [rsp+30h] [rbp-58h] BYREF
  int v39; // [rsp+98h] [rbp+10h] BYREF
  hkaiSilhouetteGenerationParameters *v40; // [rsp+A0h] [rbp+18h]

  v40 = params;
  v4 = generatorContexts;
  v6 = params;
  v7 = numGenerators;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtcreateNonmergedCompoundSilhouettes";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  v13 = 0i64;
  v36 = v7;
  if ( (int)v7 > 0 )
  {
    do
    {
      v14 = v4[v13];
      m_generator = v14->m_generator;
      v37[0] = (__int128)v14->m_lastRelativeTransform.m_rotation;
      v37[1] = (__int128)v14->m_lastRelativeTransform.m_translation;
      v16 = ((__int64 (__fastcall *)(hkaiSilhouetteGenerator *, __int128 *, hkaiSilhouetteGenerationParameters *, _QWORD *))m_generator->vfptr[1].__first_virtual_table_function__)(
              m_generator,
              v37,
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
          v22 = *(_QWORD *)(v19 + 16) + 16i64 * *(int *)(v20 + v21);
          if ( v17 == v18 - 1 )
            v23 = *(_DWORD *)(v19 + 24);
          else
            v23 = *(_DWORD *)(v20 + v21 + 4);
          v24 = v23 - *(_DWORD *)(v20 + v21);
          if ( compoundSilhouettesOut->m_size == (compoundSilhouettesOut->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, compoundSilhouettesOut, 16);
          v25 = &compoundSilhouettesOut->m_data[compoundSilhouettesOut->m_size];
          if ( v25 )
          {
            v25->m_data = 0i64;
            v25->m_size = 0;
            v25->m_capacityAndFlags = 0x80000000;
          }
          v26 = &compoundSilhouettesOut->m_data[compoundSilhouettesOut->m_size++];
          if ( (v26->m_capacityAndFlags & 0x3FFFFFFF) < v24 )
          {
            if ( v26->m_capacityAndFlags >= 0 )
              hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                &hkContainerTempAllocator::s_alloc,
                v26->m_data,
                16 * v26->m_capacityAndFlags);
            v39 = 16 * v24;
            v26->m_data = (hkVector4f *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                                          &hkContainerTempAllocator::s_alloc,
                                          &v39);
            v26->m_capacityAndFlags = v39 / 16;
          }
          m_data = v26->m_data;
          v26->m_size = v24;
          v28 = v24;
          if ( v24 > 0 )
          {
            v29 = v22 - (_QWORD)m_data;
            do
            {
              v30.m_quad = *(__m128 *)((char *)m_data++ + v29);
              m_data[-1] = (hkVector4f)v30.m_quad;
              --v28;
            }
            while ( v28 );
          }
          v18 = *(_DWORD *)(v19 + 40);
          ++v17;
          v20 += 4i64;
        }
        while ( v17 < v18 );
        v6 = v40;
        v4 = generatorContexts;
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
    v35 = v32 + 2;
    *((_DWORD *)v35 - 2) = v34;
    v33[1] = v35;
  }
}

