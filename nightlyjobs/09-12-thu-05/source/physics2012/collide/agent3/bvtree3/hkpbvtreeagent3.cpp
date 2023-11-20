// File Line: 63
// RVA: 0xD2D130
void __fastcall hkBvTreeAgent3::initAgentFunc(hkpCollisionDispatcher::Agent3Funcs *f)
{
  f->m_createFunc = hkListAgent3::create;
  f->m_processFunc = (void *(__fastcall *)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))hkBvTreeAgent3::process;
  f->m_sepNormalFunc = 0i64;
  f->m_cleanupFunc = 0i64;
  f->m_removePointFunc = 0i64;
  f->m_commitPotentialFunc = 0i64;
  f->m_createZombieFunc = 0i64;
  f->m_updateFilterFunc = hkBvTreeAgent3::updateFilter;
  f->m_invalidateTimFunc = hkBvTreeAgent3::invalidateTim;
  f->m_warpTimeFunc = hkBvTreeAgent3::warpTime;
  f->m_destroyFunc = hkListAgent3::destroy;
  f->m_isPredictive.m_bool = 1;
}

// File Line: 82
// RVA: 0xD2D0D0
void __fastcall hkBvTreeAgent3::registerAgent3(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::Agent3Funcs f; // [rsp+20h] [rbp-68h]

  v1 = dispatcher;
  *(_WORD *)&f.m_isPredictive.m_bool = 0;
  f.m_reusePreviousEntry.m_bool = 0;
  f.m_updateFilterFunc = 0i64;
  f.m_invalidateTimFunc = 0i64;
  f.m_warpTimeFunc = 0i64;
  f.m_sepNormalFunc = 0i64;
  hkBvTreeAgent3::initAgentFunc(&f);
  hkpCollisionDispatcher::registerAgent3(v1, &f, ALL_SHAPE_TYPES, BV_TREE);
}

// File Line: 91
// RVA: 0xD2CEB0
signed __int64 __fastcall hkBvTreeAgent3::process(hkpAgent3ProcessInput *input, hkpAgentEntry *entry, void *agentData, hkVector4f *separatingNormal, hkpProcessCollisionOutput *output)
{
  hkpAgent3ProcessInput *v5; // rdi
  char *v6; // rbp
  _QWORD *v7; // r10
  unsigned __int64 v8; // r9
  unsigned __int64 v9; // rax
  hkLifoAllocator *v10; // rax
  unsigned int *hitListOut; // rbx
  unsigned __int64 v12; // rcx
  const unsigned int *v13; // r14
  int v14; // esi
  hkpShapeContainer *v15; // r12
  _QWORD *v16; // rax
  unsigned __int64 v17; // r8
  _QWORD *v18; // r10
  unsigned __int64 v19; // rax
  _QWORD *v20; // r8
  _QWORD *v21; // rcx
  unsigned __int64 v22; // rax
  signed __int64 v23; // rcx
  hkLifoAllocator *v24; // rax
  hkTransformf bTa; // [rsp+40h] [rbp-58h]

  v5 = input;
  v6 = (char *)agentData;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = v7[1];
  if ( v8 < v7[3] )
  {
    *(_QWORD *)v8 = "LtBvTree3";
    *(_QWORD *)(v8 + 16) = "StQueryTree";
    v9 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v9;
    v7[1] = v8 + 24;
  }
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hitListOut = (unsigned int *)v10->m_cur;
  v12 = (unsigned __int64)(hitListOut + 2048);
  if ( v10->m_slabSize < 0x2000 || (void *)v12 > v10->m_end )
    hitListOut = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v10, 0x2000);
  else
    v10->m_cur = (void *)v12;
  hkTransformf::setInverse(&bTa, &v5->m_aTb);
  v13 = 0i64;
  v14 = hkBvTreeAgent3::calcAabbAndQueryTree(
          v5->m_bodyA.m_storage,
          v5->m_bodyB.m_storage,
          &bTa,
          &v5->m_linearTimInfo,
          v5->m_input.m_storage,
          0i64,
          hitListOut,
          2048);
  if ( v14 > 1 )
    hkAlgorithm::quickSortRecursive<unsigned int,hkAlgorithm::less<unsigned int>>(hitListOut, 0, v14 - 1, 0);
  v15 = (hkpShapeContainer *)((__int64 (*)(void))v5->m_bodyB.m_storage->m_shape->vfptr[7].__vecDelDtor)();
  v16 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v17 = v16[1];
  v18 = v16;
  if ( v17 < v16[3] )
  {
    *(_QWORD *)v17 = "StNarrow";
    v19 = __rdtsc();
    *(_DWORD *)(v17 + 8) = v19;
    v18[1] = v17 + 16;
  }
  if ( v14 >= 0 )
    v13 = hitListOut;
  hkAgent1nMachine_Process((hkpAgent1nTrack *)(v6 + 8), v5, v15, v13, output);
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "lt";
    v22 = __rdtsc();
    v23 = (signed __int64)(v21 + 2);
    *(_DWORD *)(v23 - 8) = v22;
    v20[1] = v23;
  }
  v24 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v24->m_slabSize < 0x2000 || hitListOut + 2048 != v24->m_cur || v24->m_firstNonLifoEnd == hitListOut )
    hkLifoAllocator::slowBlockFree(v24, hitListOut, 0x2000);
  else
    v24->m_cur = hitListOut;
  return (signed __int64)(v6 + 32);
}

// File Line: 125
// RVA: 0xD2D1A0
void __fastcall hkBvTreeAgent3::updateFilter(hkpAgentEntry *entry, void *agentData, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner)
{
  hkpCdBody *v7; // rdi
  hkpCdBody *v8; // rbx
  char *v9; // rsi
  hkpShapeContainer *v10; // rax
  hkpAgent1nMachine_VisitorInput vin; // [rsp+20h] [rbp-48h]

  v7 = bodyB;
  v8 = bodyA;
  v9 = (char *)agentData;
  v10 = (hkpShapeContainer *)((__int64 (*)(void))bodyB->m_shape->vfptr[7].__vecDelDtor)();
  vin.m_input = input;
  vin.m_bodyA = v8;
  vin.m_contactMgr = mgr;
  vin.m_collectionBodyB = v7;
  vin.m_constraintOwner = constraintOwner;
  vin.m_containerShapeB = v10;
  hkAgent1nMachine_UpdateShapeCollectionFilter((hkpAgent1nTrack *)(v9 + 8), &vin);
}

// File Line: 147
// RVA: 0xD2D220
void __fastcall hkBvTreeAgent3::invalidateTim(hkpAgentEntry *entry, void *agentData, hkpCollisionInput *input)
{
  hkAgent1nMachine_InvalidateTim((hkpAgent1nTrack *)((char *)agentData + 8), input);
}

// File Line: 154
// RVA: 0xD2D240
void __fastcall hkBvTreeAgent3::warpTime(hkpAgentEntry *entry, void *agentData, float oldTime, float newTime, hkpCollisionInput *input)
{
  hkAgent1nMachine_WarpTime((hkpAgent1nTrack *)((char *)agentData + 8), oldTime, newTime, input);
}

// File Line: 197
// RVA: 0xD2D260
signed __int64 __fastcall hkBvTreeAgent3::calcAabbAndQueryTree(hkpCdBody *bodyA, hkpCdBody *bodyB, hkTransformf *bTa, hkVector4f *linearTimInfo, hkpProcessCollisionInput *input, hkAabb *cachedAabb, unsigned int *hitListOut, int hitListCapacity)
{
  __m128 *v8; // rdi
  __m128 *v9; // rsi
  hkpCdBody *v10; // r15
  hkpShape *v11; // rcx
  hkpCdBody *v12; // r14
  __m128 v13; // xmm3
  __m128i v14; // xmm9
  hkBaseObjectVtbl *v15; // rax
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm8
  __m128 v19; // xmm7
  __m128 v20; // xmm1
  __m128 v21; // xmm6
  __m128 *v22; // rax
  __m128 v23; // xmm5
  __m128 v24; // xmm3
  __m128 v25; // xmm1
  __m128 v26; // xmm7
  __m128 v27; // xmm2
  __m128 v28; // xmm1
  __m128 v29; // xmm5
  __m128 v30; // xmm6
  __m128 v31; // xmm2
  __m128 v32; // xmm7
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  __m128 v35; // xmm6
  __m128 v36; // xmm5
  float v37; // xmm2_4
  __m128 v39; // xmm2
  __m128 v40; // xmm3
  __m128 v41; // xmm9
  int v42; // ecx
  int v43; // ST38_4
  int v44; // eax
  hkVector4f v45; // [rsp+40h] [rbp-68h]
  hkVector4f v46; // [rsp+50h] [rbp-58h]

  v8 = (__m128 *)bodyB->m_motion;
  v9 = (__m128 *)bodyA->m_motion;
  v10 = bodyA;
  v11 = bodyA->m_shape;
  v12 = bodyB;
  v13 = v8[2];
  v14 = (__m128i)_mm_mul_ps(
                   _mm_shuffle_ps(
                     (__m128)LODWORD(input->m_tolerance.m_storage),
                     (__m128)LODWORD(input->m_tolerance.m_storage),
                     0),
                   (__m128)xmmword_141A711B0);
  v15 = v11->vfptr;
  v16 = _mm_unpacklo_ps(*v8, v8[1]);
  v17 = _mm_movelh_ps(v16, v13);
  v18 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(linearTimInfo->m_quad, linearTimInfo->m_quad, 85),
              _mm_shuffle_ps(_mm_movehl_ps(v17, v16), v13, 212)),
            _mm_mul_ps(_mm_shuffle_ps(linearTimInfo->m_quad, linearTimInfo->m_quad, 0), v17)),
          _mm_mul_ps(
            _mm_shuffle_ps(_mm_unpackhi_ps(*v8, v8[1]), v13, 228),
            _mm_shuffle_ps(linearTimInfo->m_quad, linearTimInfo->m_quad, 170)));
  if ( input->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage )
  {
    v19 = _mm_shuffle_ps((__m128)v9[10].m128_u32[0], (__m128)v9[10].m128_u32[0], 0);
    v20 = _mm_shuffle_ps(v8[9], v8[9], 255);
    v21 = _mm_mul_ps(_mm_mul_ps(v20, v20), _mm_shuffle_ps((__m128)v8[10].m128_u32[0], (__m128)v8[10].m128_u32[0], 0));
    ((void (__fastcall *)(hkpShape *, hkTransformf *, hkTransformf *, hkVector4f *))v15[2].__vecDelDtor)(
      v11,
      bTa,
      bTa,
      &v45);
    v22 = (__m128 *)v12->m_motion;
    v23 = _mm_sub_ps(v9[5], v22[3]);
    v24 = v22[2];
    v25 = _mm_unpacklo_ps(*v22, v22[1]);
    v26 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_add_ps(_mm_add_ps(v19, (__m128)v14), v21), 4), 4);
    v27 = _mm_movelh_ps(v25, v24);
    v28 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(_mm_movehl_ps(v27, v25), v24, 212)),
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), v27)),
            _mm_mul_ps(_mm_shuffle_ps(v23, v23, 170), _mm_shuffle_ps(_mm_unpackhi_ps(*v22, v22[1]), v24, 228)));
    v29 = _mm_max_ps(v45.m_quad, _mm_sub_ps(v28, v26));
    v45.m_quad = v29;
    v30 = _mm_min_ps(v46.m_quad, _mm_add_ps(v28, v26));
    v46.m_quad = v30;
    v31 = v8[9];
    v32 = _mm_sub_ps(v30, v29);
    if ( COERCE_FLOAT(_mm_shuffle_ps(v31, v31, 255)) > 0.0 )
    {
      v33 = _mm_sub_ps(v28, v8[8]);
      v34 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v33), _mm_mul_ps(_mm_shuffle_ps(v33, v33, 201), v31));
      v18 = _mm_add_ps(
              v18,
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(v8[5], v8[5], 255),
                  _mm_shuffle_ps(
                    (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
                    (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
                    0)),
                _mm_shuffle_ps(v34, v34, 201)));
    }
    v35 = _mm_add_ps(v30, _mm_max_ps((__m128)0i64, v18));
    v36 = _mm_add_ps(v29, _mm_min_ps((__m128)0i64, v18));
    v46.m_quad = v35;
    v45.m_quad = v36;
  }
  else
  {
    v37 = input->m_tolerance.m_storage * 0.5;
    ((void (__fastcall *)(hkpShape *, hkTransformf *, hkTransformf *, hkVector4f *))v15[2].__vecDelDtor)(
      v11,
      bTa,
      bTa,
      &v45);
    v35 = v46.m_quad;
    v36 = v45.m_quad;
    v32 = _mm_sub_ps(v46.m_quad, v45.m_quad);
  }
  if ( cachedAabb )
  {
    if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v35, cachedAabb->m_max.m_quad), _mm_cmpleps(cachedAabb->m_min.m_quad, v36))) & 7) == 7 )
      return 0xFFFFFFFFi64;
    v39 = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A710D0);
    v40 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_40000001), (__m128)LODWORD(FLOAT_0_40000001), 0), v32);
    v41 = (__m128)_mm_srli_si128(_mm_slli_si128(v14, 4), 4);
    v45.m_quad = _mm_add_ps(
                   _mm_sub_ps(v36, v41),
                   _mm_max_ps(
                     _mm_mul_ps(_mm_max_ps((__m128)0i64, v18), v39),
                     _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v40)));
    cachedAabb->m_min = (hkVector4f)v45.m_quad;
    v46.m_quad = _mm_add_ps(_mm_add_ps(v35, v41), _mm_min_ps(_mm_mul_ps(_mm_min_ps((__m128)0i64, v18), v39), v40));
    cachedAabb->m_max = (hkVector4f)v46.m_quad;
  }
  v42 = ((__int64 (__fastcall *)(hkpShape *, hkVector4f *, unsigned int *, _QWORD))v12->m_shape->vfptr[9].__first_virtual_table_function__)(
          v12->m_shape,
          &v45,
          hitListOut,
          (unsigned int)hitListCapacity);
  if ( v42 >= hitListCapacity )
  {
    v43 = hitListCapacity;
    v44 = ((__int64 (__fastcall *)(hkpShapeCollectionFilterVtbl **, hkpProcessCollisionInput *, hkpCdBody *, hkpCdBody *, hkpShape *, hkVector4f *, unsigned int *, int, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64))input->m_filter.m_storage->vfptr->numShapeKeyHitsLimitBreached)(
            &input->m_filter.m_storage->vfptr,
            input,
            v10,
            v12,
            v12->m_shape,
            &v45,
            hitListOut,
            v43,
            v45.m_quad.m128_u64[0],
            v45.m_quad.m128_u64[1],
            v46.m_quad.m128_u64[0],
            v46.m_quad.m128_u64[1]);
    v42 = hitListCapacity - 1;
    if ( v44 < hitListCapacity - 1 )
      v42 = v44;
  }
  hitListOut[v42] = -1;
  return (unsigned int)v42;
}

// File Line: 403
// RVA: 0xD2D5F0
hkpShapeCollection *__fastcall hkBvTreeAgent3::getShapeCollectionIfBvTreeSupportsAabbQueries(hkpCdBody *body, char (*buffer)[512])
{
  hkpShape *v2; // rax
  int v3; // ecx

  v2 = body->m_shape;
  v3 = (unsigned __int8)body->m_shape->m_type.m_storage;
  if ( v3 == 7 )
    return *(hkpShapeCollection **)&v2[1].m_type.m_storage;
  if ( v3 == 9 )
    return (hkpShapeCollection *)v2[2].m_userData;
  return 0i64;
}

