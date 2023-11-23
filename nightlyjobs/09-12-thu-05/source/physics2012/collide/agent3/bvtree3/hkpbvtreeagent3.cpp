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
  hkpCollisionDispatcher::Agent3Funcs f; // [rsp+20h] [rbp-68h] BYREF

  *(_WORD *)&f.m_isPredictive.m_bool = 0;
  f.m_reusePreviousEntry.m_bool = 0;
  memset(&f.m_updateFilterFunc, 0, 32);
  hkBvTreeAgent3::initAgentFunc(&f);
  hkpCollisionDispatcher::registerAgent3(dispatcher, &f, ALL_SHAPE_TYPES, BV_TREE);
}

// File Line: 91
// RVA: 0xD2CEB0
char *__fastcall hkBvTreeAgent3::process(
        hkpAgent3ProcessInput *input,
        hkpAgentEntry *entry,
        char *agentData,
        hkVector4f *separatingNormal,
        hkpProcessCollisionOutput *output)
{
  _QWORD *Value; // r10
  unsigned __int64 v8; // r9
  unsigned __int64 v9; // rax
  hkLifoAllocator *v10; // rax
  unsigned int *hitListOut; // rbx
  unsigned int *v12; // rcx
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
  _QWORD *v23; // rcx
  hkLifoAllocator *v24; // rax
  hkTransformf bTa; // [rsp+40h] [rbp-58h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = Value[1];
  if ( v8 < Value[3] )
  {
    *(_QWORD *)v8 = "LtBvTree3";
    *(_QWORD *)(v8 + 16) = "StQueryTree";
    v9 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v9;
    Value[1] = v8 + 24;
  }
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  hitListOut = (unsigned int *)v10->m_cur;
  v12 = hitListOut + 2048;
  if ( v10->m_slabSize < 0x2000 || v12 > v10->m_end )
    hitListOut = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v10, 0x2000);
  else
    v10->m_cur = v12;
  hkTransformf::setInverse(&bTa, &input->m_aTb);
  v13 = 0i64;
  v14 = hkBvTreeAgent3::calcAabbAndQueryTree(
          input->m_bodyA.m_storage,
          input->m_bodyB.m_storage,
          &bTa,
          &input->m_linearTimInfo,
          input->m_input.m_storage,
          0i64,
          hitListOut,
          2048);
  if ( v14 > 1 )
    hkAlgorithm::quickSortRecursive<unsigned int,hkAlgorithm::less<unsigned int>>(hitListOut, 0, v14 - 1, 0);
  v15 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))input->m_bodyB.m_storage->m_shape->vfptr[7].__vecDelDtor)(input->m_bodyB.m_storage->m_shape);
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
  hkAgent1nMachine_Process((hkpAgent1nTrack *)(agentData + 8), input, v15, v13, output);
  v20 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v21 = (_QWORD *)v20[1];
  if ( (unsigned __int64)v21 < v20[3] )
  {
    *v21 = "lt";
    v22 = __rdtsc();
    v23 = v21 + 2;
    *((_DWORD *)v23 - 2) = v22;
    v20[1] = v23;
  }
  v24 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v24->m_slabSize < 0x2000 || hitListOut + 2048 != v24->m_cur || v24->m_firstNonLifoEnd == hitListOut )
    hkLifoAllocator::slowBlockFree(v24, (char *)hitListOut, 0x2000);
  else
    v24->m_cur = hitListOut;
  return agentData + 32;
}

// File Line: 125
// RVA: 0xD2D1A0
void __fastcall hkBvTreeAgent3::updateFilter(
        hkpAgentEntry *entry,
        char *agentData,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner)
{
  hkpShapeContainer *v10; // rax
  hkpAgent1nMachine_VisitorInput vin; // [rsp+20h] [rbp-48h] BYREF

  v10 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))bodyB->m_shape->vfptr[7].__vecDelDtor)(bodyB->m_shape);
  vin.m_input = input;
  vin.m_bodyA = bodyA;
  vin.m_contactMgr = mgr;
  vin.m_collectionBodyB = bodyB;
  vin.m_constraintOwner = constraintOwner;
  vin.m_containerShapeB = v10;
  hkAgent1nMachine_UpdateShapeCollectionFilter((hkpAgent1nTrack *)(agentData + 8), &vin);
}

// File Line: 147
// RVA: 0xD2D220
void __fastcall hkBvTreeAgent3::invalidateTim(hkpAgentEntry *entry, char *agentData, hkpCollisionInput *input)
{
  hkAgent1nMachine_InvalidateTim((hkpAgent1nTrack *)(agentData + 8), input);
}

// File Line: 154
// RVA: 0xD2D240
void __fastcall hkBvTreeAgent3::warpTime(
        hkpAgentEntry *entry,
        char *agentData,
        float oldTime,
        float newTime,
        hkpCollisionInput *input)
{
  hkAgent1nMachine_WarpTime((hkpAgent1nTrack *)(agentData + 8), oldTime, newTime, input);
}

// File Line: 197
// RVA: 0xD2D260
__int64 __fastcall hkBvTreeAgent3::calcAabbAndQueryTree(
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkTransformf *bTa,
        hkVector4f *linearTimInfo,
        hkpProcessCollisionInput *input,
        hkAabb *cachedAabb,
        unsigned int *hitListOut,
        unsigned int hitListCapacity)
{
  __m128 *m_motion; // rdi
  __m128 *v9; // rsi
  hkpShape *m_shape; // rcx
  __m128 v13; // xmm3
  __m128i v14; // xmm9
  hkBaseObjectVtbl *vfptr; // rax
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
  __m128 v38; // xmm2
  __m128 v39; // xmm3
  __m128 v40; // xmm9
  unsigned int v41; // ecx
  int v42; // eax
  __m128 v43; // [rsp+40h] [rbp-68h] BYREF
  __m128 v44; // [rsp+50h] [rbp-58h]

  m_motion = (__m128 *)bodyB->m_motion;
  v9 = (__m128 *)bodyA->m_motion;
  m_shape = bodyA->m_shape;
  v13 = m_motion[2];
  v14 = (__m128i)_mm_mul_ps(
                   _mm_shuffle_ps(
                     (__m128)LODWORD(input->m_tolerance.m_storage),
                     (__m128)LODWORD(input->m_tolerance.m_storage),
                     0),
                   (__m128)xmmword_141A711B0);
  vfptr = m_shape->vfptr;
  v16 = _mm_unpacklo_ps(*m_motion, m_motion[1]);
  v17 = _mm_movelh_ps(v16, v13);
  v18 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(linearTimInfo->m_quad, linearTimInfo->m_quad, 85),
              _mm_shuffle_ps(_mm_movehl_ps(v17, v16), v13, 212)),
            _mm_mul_ps(_mm_shuffle_ps(linearTimInfo->m_quad, linearTimInfo->m_quad, 0), v17)),
          _mm_mul_ps(
            _mm_shuffle_ps(_mm_unpackhi_ps(*m_motion, m_motion[1]), v13, 228),
            _mm_shuffle_ps(linearTimInfo->m_quad, linearTimInfo->m_quad, 170)));
  if ( input->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage )
  {
    v19 = _mm_shuffle_ps((__m128)v9[10].m128_u32[0], (__m128)v9[10].m128_u32[0], 0);
    v20 = _mm_shuffle_ps(m_motion[9], m_motion[9], 255);
    v21 = _mm_mul_ps(
            _mm_mul_ps(v20, v20),
            _mm_shuffle_ps((__m128)m_motion[10].m128_u32[0], (__m128)m_motion[10].m128_u32[0], 0));
    ((void (__fastcall *)(hkpShape *, hkTransformf *, hkTransformf *, __m128 *))vfptr[2].__vecDelDtor)(
      m_shape,
      bTa,
      bTa,
      &v43);
    v22 = (__m128 *)bodyB->m_motion;
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
    v29 = _mm_max_ps(v43, _mm_sub_ps(v28, v26));
    v43 = v29;
    v30 = _mm_min_ps(v44, _mm_add_ps(v28, v26));
    v44 = v30;
    v31 = m_motion[9];
    v32 = _mm_sub_ps(v30, v29);
    if ( _mm_shuffle_ps(v31, v31, 255).m128_f32[0] > 0.0 )
    {
      v33 = _mm_sub_ps(v28, m_motion[8]);
      v34 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v33), _mm_mul_ps(_mm_shuffle_ps(v33, v33, 201), v31));
      v18 = _mm_add_ps(
              v18,
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(m_motion[5], m_motion[5], 255),
                  _mm_shuffle_ps(
                    (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
                    (__m128)LODWORD(input->m_stepInfo.m_deltaTime.m_storage),
                    0)),
                _mm_shuffle_ps(v34, v34, 201)));
    }
    v35 = _mm_add_ps(v30, _mm_max_ps((__m128)0i64, v18));
    v36 = _mm_add_ps(v29, _mm_min_ps((__m128)0i64, v18));
    v44 = v35;
    v43 = v36;
  }
  else
  {
    ((void (__fastcall *)(hkpShape *, hkTransformf *, hkTransformf *, __m128 *))vfptr[2].__vecDelDtor)(
      m_shape,
      bTa,
      bTa,
      &v43);
    v35 = v44;
    v36 = v43;
    v32 = _mm_sub_ps(v44, v43);
  }
  if ( cachedAabb )
  {
    if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v35, cachedAabb->m_max.m_quad), _mm_cmple_ps(cachedAabb->m_min.m_quad, v36))) & 7) == 7 )
      return 0xFFFFFFFFi64;
    v38 = _mm_sub_ps((__m128)0i64, (__m128)xmmword_141A710D0);
    v39 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(FLOAT_0_40000001), (__m128)LODWORD(FLOAT_0_40000001), 0), v32);
    v40 = (__m128)_mm_srli_si128(_mm_slli_si128(v14, 4), 4);
    v43 = _mm_add_ps(
            _mm_sub_ps(v36, v40),
            _mm_max_ps(
              _mm_mul_ps(_mm_max_ps((__m128)0i64, v18), v38),
              _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v39)));
    cachedAabb->m_min.m_quad = v43;
    v44 = _mm_add_ps(_mm_add_ps(v35, v40), _mm_min_ps(_mm_mul_ps(_mm_min_ps((__m128)0i64, v18), v38), v39));
    cachedAabb->m_max.m_quad = v44;
  }
  v41 = ((__int64 (__fastcall *)(hkpShape *, __m128 *, unsigned int *, _QWORD))bodyB->m_shape->vfptr[9].__first_virtual_table_function__)(
          bodyB->m_shape,
          &v43,
          hitListOut,
          hitListCapacity);
  if ( (int)v41 >= (int)hitListCapacity )
  {
    v42 = input->m_filter.m_storage->vfptr->numShapeKeyHitsLimitBreached(
            &input->m_filter.m_storage->hkpShapeCollectionFilter,
            input,
            bodyA,
            bodyB,
            (hkpBvTreeShape *)bodyB->m_shape,
            (hkAabb *)&v43,
            hitListOut,
            hitListCapacity);
    v41 = hitListCapacity - 1;
    if ( v42 < (int)(hitListCapacity - 1) )
      v41 = v42;
  }
  hitListOut[v41] = -1;
  return v41;
}

// File Line: 403
// RVA: 0xD2D5F0
hkpShapeCollection *__fastcall hkBvTreeAgent3::getShapeCollectionIfBvTreeSupportsAabbQueries(
        hkpCdBody *body,
        char (*buffer)[512])
{
  hkpShape *m_shape; // rax
  int m_storage; // ecx

  m_shape = body->m_shape;
  m_storage = (unsigned __int8)body->m_shape->m_type.m_storage;
  if ( m_storage == 7 )
    return *(hkpShapeCollection **)&m_shape[1].m_type.m_storage;
  if ( m_storage == 9 )
    return (hkpShapeCollection *)m_shape[2].m_userData;
  return 0i64;
}

