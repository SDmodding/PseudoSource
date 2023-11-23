// File Line: 48
// RVA: 0xD2E640
void __fastcall hkpCollectionCollectionAgent3::initAgentFunc(hkpCollisionDispatcher::Agent3Funcs *f)
{
  f->m_createFunc = hkListAgent3::create;
  f->m_processFunc = (void *(__fastcall *)(hkpAgent3ProcessInput *, hkpAgentEntry *, void *, hkVector4f *, hkpProcessCollisionOutput *))hkpCollectionCollectionAgent3::process;
  f->m_sepNormalFunc = 0i64;
  f->m_cleanupFunc = 0i64;
  f->m_removePointFunc = 0i64;
  f->m_commitPotentialFunc = 0i64;
  f->m_createZombieFunc = 0i64;
  f->m_updateFilterFunc = hkpCollectionCollectionAgent3::updateFilter;
  f->m_invalidateTimFunc = hkpCollectionCollectionAgent3::invalidateTim;
  f->m_warpTimeFunc = hkpCollectionCollectionAgent3::warpTime;
  f->m_destroyFunc = hkListAgent3::destroy;
  f->m_isPredictive.m_bool = 1;
}

// File Line: 67
// RVA: 0xD2E580
void __fastcall hkpCollectionCollectionAgent3::registerAgent3(hkpCollisionDispatcher *dispatcher)
{
  hkpCollisionDispatcher::Agent3Funcs f; // [rsp+20h] [rbp-68h] BYREF

  *(_WORD *)&f.m_isPredictive.m_bool = 0;
  f.m_reusePreviousEntry.m_bool = 0;
  memset(&f.m_updateFilterFunc, 0, 32);
  hkpCollectionCollectionAgent3::initAgentFunc(&f);
  hkpCollisionDispatcher::registerAgent3(dispatcher, &f, BV_TREE, BV_TREE);
  *(_WORD *)&f.m_ignoreSymmetricVersion.m_bool = 257;
  hkpCollisionDispatcher::registerAgent3(dispatcher, &f, COLLECTION, BV_TREE);
  hkpCollisionDispatcher::registerAgent3(dispatcher, &f, BV_TREE, COLLECTION);
  hkpCollisionDispatcher::registerAgent3(dispatcher, &f, COLLECTION, COLLECTION);
  dispatcher->m_midphaseAgent3Registered.m_bool = 1;
  hkpCollectionCollectionAgent3::g_agentRegistered = 1;
}

// File Line: 86
// RVA: 0xD2E770
__int64 __fastcall hkCollectionBvTreeAgent3_extractCachedAabbsOrRecalculate(
        hkpCdBody *cdBody,
        hkpCdBody *overrideCdBody,
        hkpShapeContainer *collection,
        hkpProcessCollisionInput *input,
        hk1AxisSweep::AabbInt *aabbs,
        int aabbsCapacity,
        int aabbBufferSize_usedOnSpu)
{
  unsigned int m_storage; // r15d
  hkpCdBody *m_parent; // r8
  hkpCdBody *v11; // rsi
  unsigned int v12; // r14d
  unsigned int *v13; // rbx
  const void **p_m_motion; // r10
  hkpShape *m_shape; // rsi
  int v17; // ebp
  unsigned int *v18; // r11
  char *m_expansionMin; // r9
  __m128i v20; // xmm4
  unsigned int v21; // eax
  __m128i v22; // xmm3
  __m128i v23; // xmm3
  char *v24; // rcx
  __int64 v25; // rdx
  __int64 v26; // rax
  __m128i v27; // xmm4
  unsigned int v28; // eax
  __m128i v29; // xmm3
  __m128i v30; // xmm3
  hk1AxisSweep::AabbInt *v31; // rcx
  signed __int64 v32; // r10
  __int64 v33; // rdi
  __int64 v34; // rax
  hkpCdBody *v35; // rax
  unsigned int v36; // ebx
  hk1AxisSweep::AabbInt *v37; // r12
  hkpShape *v38; // rax
  __int64 v39; // rcx
  hkVector4f v40; // xmm7
  __m128 v41; // xmm8
  __m128 v42; // xmm5
  __m128 v43; // xmm4
  __m128 v44; // xmm2
  __m128 v45; // xmm6
  __m128 v46; // xmm5
  __m128 v47; // xmm4
  hkVector4f *p_m_col2; // rax
  __m128 m_quad; // xmm3
  __m128 v50; // xmm1
  __m128 v51; // xmm2
  __m128 v52; // xmm1
  __m128 v53; // xmm3
  __m128 v54; // xmm1
  __m128 v55; // xmm4
  __m128 v56; // xmm4
  __m128 v57; // xmm6
  __m128 v58; // xmm5
  __m128 v59; // xmm6
  __m128 v60; // xmm5
  __m128 v61; // xmm4
  __m128i *v62; // rax
  __m128 v63; // xmm6
  __m128i v64; // xmm0
  __m128 v65; // xmm5
  __m128i v66; // xmm0
  __m128 v67; // [rsp+20h] [rbp-428h] BYREF
  __m128 v68; // [rsp+30h] [rbp-418h]
  hkAabbUtil::OffsetAabbInput inputa; // [rsp+40h] [rbp-408h] BYREF
  char v70[512]; // [rsp+1E0h] [rbp-268h] BYREF

  m_storage = input->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage;
  m_parent = cdBody->m_parent;
  v11 = cdBody;
  v12 = 0;
  if ( m_parent )
  {
LABEL_21:
    if ( m_storage )
    {
      if ( m_parent )
      {
        v35 = cdBody->m_parent;
        do
        {
          cdBody = v35;
          v35 = v35->m_parent;
        }
        while ( v35 );
      }
      hkAabbUtil::initOffsetAabbInput((hkMotionState *)cdBody->m_motion, &inputa);
    }
    v36 = ((__int64 (__fastcall *)(hkpShapeContainer *, hkpCdBody *))collection->vfptr->getFirstKey)(
            collection,
            overrideCdBody);
    if ( v36 != -1 )
    {
      v37 = aabbs;
      do
      {
        v38 = collection->vfptr->getChildShape(collection, v36, v70);
        ((void (__fastcall *)(hkpShape *, const void *, hkBaseObjectVtbl *, __m128 *))v38->vfptr[2].__vecDelDtor)(
          v38,
          v11->m_motion,
          v38->vfptr,
          &v67);
        if ( m_storage )
        {
          v39 = inputa.m_numTransforms.m_storage;
          v40.m_quad = (__m128)inputa.m_motionState.m_storage->m_sweptTransform.m_centerOfMassLocal;
          v41 = _mm_mul_ps(_mm_sub_ps(v68, v67), (__m128)xmmword_141A711B0);
          v42 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v67, v68), (__m128)xmmword_141A711B0), v68);
          v43 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), inputa.m_endTransformInv.m_rotation.m_col1.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), inputa.m_endTransformInv.m_rotation.m_col0.m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), inputa.m_endTransformInv.m_rotation.m_col2.m_quad)),
                  inputa.m_endTransformInv.m_translation.m_quad);
          v44 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v43, v43, 85), inputa.m_startTransform.m_rotation.m_col1.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v43, v43, 0), inputa.m_startTransform.m_rotation.m_col0.m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v43, v43, 170), inputa.m_startTransform.m_rotation.m_col2.m_quad)),
                  inputa.m_startTransform.m_translation.m_quad);
          v45 = _mm_min_ps(v42, v44);
          v46 = _mm_max_ps(v42, v44);
          if ( inputa.m_numTransforms.m_storage > 0 )
          {
            v47 = _mm_sub_ps(v43, v40.m_quad);
            p_m_col2 = &inputa.m_transforms[0].m_rotation.m_col2;
            do
            {
              m_quad = p_m_col2[1].m_quad;
              p_m_col2 += 4;
              v50 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 255), v47), v40.m_quad);
              v51 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), p_m_col2[-5].m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), p_m_col2[-6].m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), p_m_col2[-4].m_quad)),
                      m_quad);
              v45 = _mm_min_ps(v45, v51);
              v46 = _mm_max_ps(v46, v51);
              --v39;
            }
            while ( v39 );
          }
          v52 = _mm_mul_ps(v41, v41);
          v53 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v52, v52, 85), _mm_shuffle_ps(v52, v52, 0)),
                  _mm_shuffle_ps(v52, v52, 170));
          v54 = _mm_rsqrt_ps(v53);
          v55 = _mm_andnot_ps(
                  _mm_cmple_ps(v53, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v54, v53), v54)),
                      _mm_mul_ps(*(__m128 *)_xmm, v54)),
                    v53));
          v56 = _mm_min_ps(
                  v55,
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_min_ps(
                        _mm_shuffle_ps(
                          inputa.m_motionState.m_storage->m_deltaAngle.m_quad,
                          inputa.m_motionState.m_storage->m_deltaAngle.m_quad,
                          255),
                        _mm_mul_ps(_mm_shuffle_ps((__m128)0x3F3B67AFu, (__m128)0x3F3B67AFu, 0), v55)),
                      v55),
                    v41));
          v57 = _mm_sub_ps(v45, v56);
          v58 = _mm_add_ps(v46, v56);
          v59 = _mm_min_ps(v57, v57);
          v60 = _mm_max_ps(v58, v58);
        }
        else
        {
          v60 = v68;
          v59 = v67;
        }
        v61 = hkAabbUtil::hkAabbUint32MaxVal;
        v62 = (__m128i *)v37;
        ++v12;
        ++v37;
        v63 = _mm_max_ps(
                _mm_min_ps(
                  _mm_mul_ps(
                    _mm_add_ps(v59, input->m_aabb32Info.m_bitOffsetLow.m_quad),
                    input->m_aabb32Info.m_bitScale.m_quad),
                  hkAabbUtil::hkAabbUint32MaxVal),
                (__m128)0i64);
        v64 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v63);
        *v62 = _mm_or_si128(
                 _mm_add_epi32(
                   _mm_cvttps_epi32(
                     _mm_max_ps(
                       _mm_sub_ps(
                         v63,
                         _mm_and_ps((__m128)v64, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                       (__m128)0i64)),
                   _mm_slli_epi32(v64, 0x1Fu)),
                 (__m128i)_mm_cmple_ps(
                            _mm_add_ps(
                              *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                              *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                            v63));
        v65 = _mm_max_ps(
                _mm_min_ps(
                  _mm_mul_ps(
                    _mm_add_ps(v60, input->m_aabb32Info.m_bitOffsetHigh.m_quad),
                    input->m_aabb32Info.m_bitScale.m_quad),
                  v61),
                (__m128)0i64);
        v66 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v65);
        v62[1] = _mm_or_si128(
                   _mm_add_epi32(
                     _mm_cvttps_epi32(
                       _mm_max_ps(
                         _mm_sub_ps(
                           v65,
                           _mm_and_ps((__m128)v66, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                         (__m128)0i64)),
                     _mm_slli_epi32(v66, 0x1Fu)),
                   (__m128i)_mm_cmple_ps(
                              _mm_add_ps(
                                *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                                *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                              v65));
        v62->m128i_i32[3] = v36;
        v36 = collection->vfptr->getNextKey(collection, v36);
      }
      while ( v36 != -1 );
    }
LABEL_35:
    if ( (int)v12 > 1 )
      hkAlgorithm::quickSortRecursive<hk1AxisSweep::AabbInt,hkAlgorithm::less<hk1AxisSweep::AabbInt>>(
        aabbs,
        0,
        v12 - 1,
        0);
    return v12;
  }
  v13 = (unsigned int *)cdBody[2].m_parent;
  p_m_motion = &cdBody[1].m_motion;
  if ( !v13 || *(_DWORD *)p_m_motion > LODWORD(cdBody[2].m_shape) )
  {
    if ( LODWORD(cdBody[1].m_motion) <= LODWORD(cdBody[2].m_shape) && overrideCdBody )
    {
      if ( m_storage )
      {
        v12 = 1;
        v27 = _mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)HIDWORD(cdBody[1].m_parent), (__m128i)0i64), (__m128i)0i64);
        v28 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v27, 255));
        v29 = _mm_sub_epi32(
                _mm_unpacklo_epi32(
                  _mm_unpacklo_epi32(
                    _mm_cvtsi32_si128((unsigned int)cdBody[1].m_motion),
                    _mm_cvtsi32_si128((unsigned int)cdBody[1].m_parent)),
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(HIDWORD(cdBody[1].m_motion)), _mm_cvtsi32_si128(0))),
                _mm_slli_epi32(v27, v28));
        *(_QWORD *)aabbs->m_min = v29.m128i_i64[0];
        aabbs->m_min[2] = _mm_shuffle_epi32(v29, 170).m128i_u32[0];
        v30 = _mm_add_epi32(
                _mm_unpacklo_epi32(
                  _mm_unpacklo_epi32(
                    _mm_cvtsi32_si128((unsigned int)cdBody[2].m_shape),
                    _mm_cvtsi32_si128(cdBody[2].m_shapeKey)),
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(HIDWORD(cdBody[2].m_shape)), _mm_cvtsi32_si128(0))),
                _mm_slli_epi32(
                  _mm_unpacklo_epi16(
                    _mm_unpacklo_epi8((__m128i)*(&cdBody[2].m_shapeKey + 1), (__m128i)0i64),
                    (__m128i)0i64),
                  v28));
        *(_QWORD *)aabbs->m_max = v30.m128i_i64[0];
        aabbs->m_max[2] = _mm_shuffle_epi32(v30, 170).m128i_u32[0];
        *(_DWORD *)aabbs->m_expansionMin = 0;
      }
      else
      {
        v31 = aabbs;
        v32 = (char *)p_m_motion - (char *)aabbs;
        v33 = 4i64;
        do
        {
          v34 = *(_QWORD *)((char *)v31->m_min + v32);
          v31 = (hk1AxisSweep::AabbInt *)((char *)v31 + 8);
          *(_QWORD *)&v31[-1].m_max[2] = v34;
          --v33;
        }
        while ( v33 );
        *(_DWORD *)aabbs->m_expansionMin = 0;
        return 1;
      }
      return v12;
    }
    goto LABEL_21;
  }
  if ( !LOWORD(cdBody[2].m_motion) )
    return 0i64;
  m_shape = cdBody[3].m_shape;
  v17 = 0;
  v18 = v13 + 5;
  m_expansionMin = aabbs->m_expansionMin;
  do
  {
    if ( m_storage )
    {
      v20 = _mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)*(v18 - 2), (__m128i)0i64), (__m128i)0i64);
      v21 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v20, 255));
      v22 = _mm_sub_epi32(
              _mm_unpacklo_epi32(
                _mm_unpacklo_epi32(_mm_cvtsi32_si128(*v13), _mm_cvtsi32_si128(*(v18 - 3))),
                _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v18 - 4)), _mm_cvtsi32_si128(0))),
              _mm_slli_epi32(v20, v21));
      *(_QWORD *)(m_expansionMin - 12) = v22.m128i_i64[0];
      *((_DWORD *)m_expansionMin - 1) = _mm_shuffle_epi32(v22, 170).m128i_u32[0];
      v23 = _mm_add_epi32(
              _mm_unpacklo_epi32(
                _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v18 - 1)), _mm_cvtsi32_si128(v18[1])),
                _mm_unpacklo_epi32(_mm_cvtsi32_si128(*v18), _mm_cvtsi32_si128(0))),
              _mm_slli_epi32(_mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)v18[2], (__m128i)0i64), (__m128i)0i64), v21));
      *(_QWORD *)(m_expansionMin + 4) = v23.m128i_i64[0];
      *((_DWORD *)m_expansionMin + 3) = _mm_shuffle_epi32(v23, 170).m128i_u32[0];
    }
    else
    {
      v24 = m_expansionMin - 12;
      v25 = 4i64;
      do
      {
        v26 = *(_QWORD *)&v24[(char *)v13 - (m_expansionMin - 12)];
        v24 += 8;
        *((_QWORD *)v24 - 1) = v26;
        --v25;
      }
      while ( v25 );
    }
    ++v17;
    v13 += 8;
    *(_DWORD *)m_expansionMin = m_shape->vfptr;
    v18 += 8;
    m_shape = (hkpShape *)((char *)m_shape + 4);
    ++v12;
    m_expansionMin += 32;
  }
  while ( v17 < *((unsigned __int16 *)p_m_motion + 16) );
  if ( m_storage )
    goto LABEL_35;
  return v12;
}

// File Line: 258
// RVA: 0xD2EDA0
void __fastcall hkCollectionBvTreeAgent3_calcAabbs(
        hkpAgent3ProcessInput *input,
        hkpShapeContainer *container,
        hkpCdBody *cdBody,
        unsigned int *hitList,
        int numHits,
        hk1AxisSweep::AabbInt *aabbsOut)
{
  unsigned int m_storage; // r14d
  hkpCdBody *m_parent; // rax
  hkpCdBody *i; // rcx
  hk1AxisSweep::AabbInt *v13; // r13
  char *m_expansionMin; // r12
  unsigned int v15; // edi
  hkpShape *v16; // rax
  __int64 v17; // rcx
  hkVector4f v18; // xmm6
  __m128 v19; // xmm7
  __m128 v20; // xmm9
  __m128 v21; // xmm4
  __m128 v22; // xmm2
  __m128 v23; // xmm5
  __m128 v24; // xmm9
  __m128 v25; // xmm4
  hkVector4f *p_m_col2; // rax
  __m128 m_quad; // xmm3
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  __m128 v30; // xmm1
  __m128 v31; // xmm3
  __m128 v32; // xmm1
  __m128 v33; // xmm4
  __m128 v34; // xmm4
  __m128 v35; // xmm5
  __m128 v36; // xmm9
  __m128 v37; // xmm5
  __m128 v38; // xmm9
  hkpProcessCollisionInput *v39; // rax
  bool v40; // zf
  __m128 v41; // xmm8
  __m128 v42; // xmm4
  __m128i v43; // xmm0
  __m128 v44; // xmm3
  __m128 v45; // xmm3
  __m128i v46; // xmm0
  __m128 v47; // [rsp+20h] [rbp-438h] BYREF
  __m128 v48; // [rsp+30h] [rbp-428h]
  hkAabbUtil::OffsetAabbInput inputa; // [rsp+40h] [rbp-418h] BYREF
  char v50[512]; // [rsp+1E0h] [rbp-278h] BYREF
  __int64 v51; // [rsp+460h] [rbp+8h]

  m_storage = input->m_input.m_storage->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage;
  if ( m_storage )
  {
    m_parent = cdBody->m_parent;
    for ( i = cdBody; m_parent; m_parent = m_parent->m_parent )
      i = m_parent;
    hkAabbUtil::initOffsetAabbInput((hkMotionState *)i->m_motion, &inputa);
  }
  if ( numHits > 0 )
  {
    v13 = aabbsOut;
    v51 = (unsigned int)numHits;
    m_expansionMin = aabbsOut->m_expansionMin;
    do
    {
      v15 = *hitList;
      v16 = container->vfptr->getChildShape(container, *hitList, v50);
      ((void (__fastcall *)(hkpShape *, const void *, hkBaseObjectVtbl *, __m128 *))v16->vfptr[2].__vecDelDtor)(
        v16,
        cdBody->m_motion,
        v16->vfptr,
        &v47);
      if ( m_storage )
      {
        v17 = inputa.m_numTransforms.m_storage;
        v18.m_quad = (__m128)inputa.m_motionState.m_storage->m_sweptTransform.m_centerOfMassLocal;
        v19 = _mm_mul_ps(_mm_sub_ps(v48, v47), (__m128)xmmword_141A711B0);
        v20 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v47, v48), (__m128)xmmword_141A711B0), v48);
        v21 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), inputa.m_endTransformInv.m_rotation.m_col1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), inputa.m_endTransformInv.m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), inputa.m_endTransformInv.m_rotation.m_col2.m_quad)),
                inputa.m_endTransformInv.m_translation.m_quad);
        v22 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), inputa.m_startTransform.m_rotation.m_col1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), inputa.m_startTransform.m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), inputa.m_startTransform.m_rotation.m_col2.m_quad)),
                inputa.m_startTransform.m_translation.m_quad);
        v23 = _mm_min_ps(v20, v22);
        v24 = _mm_max_ps(v20, v22);
        if ( inputa.m_numTransforms.m_storage > 0 )
        {
          v25 = _mm_sub_ps(v21, v18.m_quad);
          p_m_col2 = &inputa.m_transforms[0].m_rotation.m_col2;
          do
          {
            m_quad = p_m_col2[1].m_quad;
            p_m_col2 += 4;
            v28 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 255), v25), v18.m_quad);
            v29 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v28, v28, 85), p_m_col2[-5].m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), p_m_col2[-6].m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v28, v28, 170), p_m_col2[-4].m_quad)),
                    m_quad);
            v23 = _mm_min_ps(v23, v29);
            v24 = _mm_max_ps(v24, v29);
            --v17;
          }
          while ( v17 );
        }
        v30 = _mm_mul_ps(v19, v19);
        v31 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)),
                _mm_shuffle_ps(v30, v30, 170));
        v32 = _mm_rsqrt_ps(v31);
        v33 = _mm_andnot_ps(
                _mm_cmple_ps(v31, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
                    _mm_mul_ps(*(__m128 *)_xmm, v32)),
                  v31));
        v34 = _mm_min_ps(
                v33,
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_min_ps(
                      _mm_shuffle_ps(
                        inputa.m_motionState.m_storage->m_deltaAngle.m_quad,
                        inputa.m_motionState.m_storage->m_deltaAngle.m_quad,
                        255),
                      _mm_mul_ps(_mm_shuffle_ps((__m128)0x3F3B67AFu, (__m128)0x3F3B67AFu, 0), v33)),
                    v33),
                  v19));
        v35 = _mm_sub_ps(v23, v34);
        v36 = _mm_add_ps(v24, v34);
        v37 = _mm_min_ps(v35, v35);
        v38 = _mm_max_ps(v36, v36);
        v47 = v37;
        v48 = v38;
      }
      else
      {
        v38 = v48;
        v37 = v47;
      }
      v39 = input->m_input.m_storage;
      m_expansionMin += 32;
      ++v13;
      ++hitList;
      v40 = v51-- == 1;
      v41 = _mm_add_ps(
              *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
              *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31);
      v42 = _mm_max_ps(
              _mm_min_ps(
                _mm_mul_ps(
                  _mm_add_ps(v39->m_aabb32Info.m_bitOffsetLow.m_quad, v37),
                  v39->m_aabb32Info.m_bitScale.m_quad),
                hkAabbUtil::hkAabbUint32MaxVal),
              (__m128)0i64);
      v43 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v42);
      v44 = _mm_add_ps(v39->m_aabb32Info.m_bitOffsetHigh.m_quad, v38);
      *(__m128i *)v13[-1].m_min = _mm_or_si128(
                                    _mm_add_epi32(
                                      _mm_cvttps_epi32(
                                        _mm_max_ps(
                                          _mm_sub_ps(
                                            v42,
                                            _mm_and_ps(
                                              (__m128)v43,
                                              *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                                          (__m128)0i64)),
                                      _mm_slli_epi32(v43, 0x1Fu)),
                                    (__m128i)_mm_cmple_ps(v41, v42));
      v45 = _mm_max_ps(
              _mm_min_ps(_mm_mul_ps(v44, v39->m_aabb32Info.m_bitScale.m_quad), hkAabbUtil::hkAabbUint32MaxVal),
              (__m128)0i64);
      v46 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v45);
      *(__m128i *)v13[-1].m_max = _mm_or_si128(
                                    _mm_add_epi32(
                                      _mm_cvttps_epi32(
                                        _mm_max_ps(
                                          _mm_sub_ps(
                                            v45,
                                            _mm_and_ps(
                                              (__m128)v46,
                                              *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                                          (__m128)0i64)),
                                      _mm_slli_epi32(v46, 0x1Fu)),
                                    (__m128i)_mm_cmple_ps(v41, v45));
      *((_DWORD *)m_expansionMin - 8) = v15;
    }
    while ( !v40 );
  }
}

// File Line: 298
// RVA: 0xD2D670
__int64 __fastcall hkpCollectionCollectionAgent3::process_gatherShapeKeys(
        hkpAgent3ProcessInput *input,
        hkpShapeContainer *shapeContainerA,
        hkpShapeContainer *shapeContainerB,
        hkKeyPair *shapeKeyPairs)
{
  hkpShapeContainer *v5; // r12
  hkpShapeContainer *v6; // r15
  _QWORD *Value; // rax
  unsigned __int64 v8; // rcx
  _QWORD *v9; // r10
  unsigned __int64 v10; // rax
  hkpCdBody *m_storage; // r8
  hkpCdBody *v12; // r9
  hkpCollisionDispatcher *v13; // rdx
  bool v14; // si
  bool v15; // r14
  unsigned __int8 v16; // di
  char v17; // al
  hkpShapeCollection *ShapeCollectionIfBvTreeSupportsAabbQueries; // r15
  hkpShapeCollection *v19; // rax
  hkpShapeCollection *v20; // rcx
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  _QWORD *v24; // rcx
  int v25; // eax
  hkpCdBody *v26; // rdi
  int v27; // r13d
  hkpCdBody *v28; // rax
  hkpCdBody *v29; // rdx
  hkpCdBody *v30; // rcx
  int v31; // eax
  hkLifoAllocator *v32; // rax
  hk1AxisSweep::AabbInt *m_cur; // rsi
  int v34; // r14d
  char *v35; // rcx
  _QWORD *v36; // r8
  _QWORD *v37; // rcx
  unsigned __int64 v38; // rax
  _QWORD *v39; // rcx
  hkpCdBody *v40; // rcx
  hkpCdBody *i; // rax
  __int64 v42; // rdi
  hkpShape *v43; // rax
  __int64 v44; // rcx
  __m128 v45; // xmm5
  __m128 v46; // xmm8
  __m128 v47; // xmm6
  __m128 v48; // xmm4
  __m128 v49; // xmm2
  __m128 v50; // xmm7
  __m128 v51; // xmm6
  __m128 v52; // xmm4
  char *v53; // rax
  __m128 v54; // xmm3
  __m128 v55; // xmm1
  __m128 v56; // xmm2
  __m128 v57; // xmm1
  __m128 v58; // xmm3
  __m128 v59; // xmm1
  __m128 v60; // xmm4
  __m128 v61; // xmm4
  __m128 v62; // xmm7
  __m128 v63; // xmm6
  __m128 v64; // xmm7
  __m128 v65; // xmm6
  hkpProcessCollisionInput *v66; // rax
  __m128 v67; // xmm5
  __m128 m_quad; // xmm4
  __int64 v69; // rcx
  __m128 v70; // xmm4
  __m128i v71; // xmm0
  __m128 v72; // xmm4
  __m128i v73; // xmm0
  unsigned __int64 v74; // rdx
  _QWORD *v75; // r8
  _QWORD *v76; // rcx
  unsigned __int64 v77; // rax
  _QWORD *v78; // rcx
  int v79; // eax
  hkpCdBody *v80; // rdx
  int v81; // edi
  int m_motion_low; // ecx
  hkLifoAllocator *v83; // rax
  int v84; // r15d
  char *v85; // rcx
  int CachedAabbsOrRecalculate; // eax
  int v87; // eax
  int v88; // r12d
  int v89; // ecx
  int v90; // r15d
  hkLifoAllocator *v91; // rax
  hk1AxisSweep::AabbInt *v92; // rdi
  int v93; // edx
  char *v94; // rcx
  int v95; // r12d
  hkLifoAllocator *v96; // rax
  hk1AxisSweep::AabbInt *v97; // rcx
  __int64 v98; // rcx
  hk1AxisSweep::AabbInt *v99; // rax
  __int64 v100; // rcx
  __int64 v101; // rcx
  hk1AxisSweep::AabbInt *v102; // rax
  __int64 v103; // rcx
  _QWORD *v104; // r8
  _QWORD *v105; // rcx
  unsigned __int64 v106; // rax
  _QWORD *v107; // rcx
  int v108; // r9d
  hk1AxisSweep::AabbInt *v109; // r8
  int v110; // edx
  hk1AxisSweep::AabbInt *v111; // rcx
  int v112; // ebx
  signed int v113; // r15d
  hkLifoAllocator *v114; // rax
  int v115; // r8d
  hkLifoAllocator *v116; // rax
  int v117; // r8d
  _QWORD *v118; // r8
  _QWORD *v119; // rcx
  unsigned __int64 v120; // rax
  _QWORD *v121; // rcx
  _QWORD *v122; // rax
  unsigned __int64 v123; // rcx
  unsigned __int64 v124; // rcx
  _QWORD *v125; // r8
  _QWORD *v126; // rcx
  unsigned __int64 v127; // rax
  _QWORD *v128; // rcx
  hkpProcessCollisionInput *inputa; // [rsp+20h] [rbp-E0h]
  unsigned int v131; // [rsp+40h] [rbp-C0h]
  hkpCdBody *v132; // [rsp+48h] [rbp-B8h]
  hkpCdBody *cdBody; // [rsp+50h] [rbp-B0h]
  hkpShapeContainer *collection; // [rsp+58h] [rbp-A8h]
  unsigned int v135; // [rsp+68h] [rbp-98h]
  _DWORD *m_expansionMin; // [rsp+70h] [rbp-90h]
  __m128 v137; // [rsp+80h] [rbp-80h] BYREF
  __m128 v138; // [rsp+90h] [rbp-70h]
  hkVector4f linearTimInfo; // [rsp+A0h] [rbp-60h] BYREF
  hkTransformf bTa; // [rsp+B0h] [rbp-50h] BYREF
  char buffer[512]; // [rsp+F0h] [rbp-10h] BYREF
  char v142[512]; // [rsp+2F0h] [rbp+1F0h] BYREF
  unsigned int hitListOut[2048]; // [rsp+4F0h] [rbp+3F0h] BYREF
  int aabbBufferSize_usedOnSpu; // [rsp+2570h] [rbp+2470h] BYREF
  hkpShapeContainer *v145; // [rsp+2580h] [rbp+2480h]
  hkKeyPair *pairsOut; // [rsp+2588h] [rbp+2488h]

  pairsOut = shapeKeyPairs;
  v145 = shapeContainerB;
  v5 = shapeContainerA;
  collection = shapeContainerA;
  v6 = shapeContainerB;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = Value[1];
  v9 = Value;
  if ( v8 < Value[3] )
  {
    *(_QWORD *)v8 = "LtCollColl3";
    *(_QWORD *)(v8 + 16) = "StInit";
    v10 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v10;
    v9[1] = v8 + 24;
  }
  m_storage = input->m_bodyA.m_storage;
  v12 = input->m_bodyB.m_storage;
  v13 = input->m_input.m_storage->m_dispatcher.m_storage;
  v14 = (v13->m_hasAlternateType[(unsigned __int8)input->m_bodyA.m_storage->m_shape->m_type.m_storage] & 0x400000) == 0;
  v15 = (v13->m_hasAlternateType[(unsigned __int8)v12->m_shape->m_type.m_storage] & 0x400000) == 0;
  if ( v14 || v15 )
  {
    v16 = (v13->m_hasAlternateType[(unsigned __int8)input->m_bodyA.m_storage->m_shape->m_type.m_storage] & 0x400000) == 0;
  }
  else
  {
    v16 = !m_storage->m_parent && m_storage[2].m_parent;
    v17 = !v12->m_parent && v12[2].m_parent;
    if ( v16 == v17 )
    {
      ShapeCollectionIfBvTreeSupportsAabbQueries = hkBvTreeAgent3::getShapeCollectionIfBvTreeSupportsAabbQueries(
                                                     m_storage,
                                                     (char (*)[512])buffer);
      v19 = hkBvTreeAgent3::getShapeCollectionIfBvTreeSupportsAabbQueries(input->m_bodyB.m_storage, (char (*)[512])v142);
      v20 = v19;
      if ( ShapeCollectionIfBvTreeSupportsAabbQueries )
        v16 = ShapeCollectionIfBvTreeSupportsAabbQueries->m_type.m_storage == 8;
      else
        v16 = 0;
      if ( v19 )
        LOBYTE(v19) = v19->m_type.m_storage == 8;
      if ( v16 && (_BYTE)v19 )
      {
        v16 = *(_DWORD *)&ShapeCollectionIfBvTreeSupportsAabbQueries[1].m_memSizeAndFlags
            - *(unsigned __int16 *)&ShapeCollectionIfBvTreeSupportsAabbQueries[1].m_bitsPerKey <= *(_DWORD *)&v20[1].m_memSizeAndFlags
                                                                                                - *(unsigned __int16 *)&v20[1].m_bitsPerKey;
      }
      else if ( !(v16 | (unsigned __int8)v19) )
      {
        v16 = *((float *)input->m_bodyA.m_storage->m_motion + 40) <= *((float *)input->m_bodyB.m_storage->m_motion + 40);
      }
      v6 = v145;
    }
  }
  if ( v15 && v14 )
  {
    v79 = v5->vfptr->getNumChildShapes(v5);
    v80 = input->m_bodyA.m_storage;
    v81 = v79;
    if ( !input->m_bodyA.m_storage->m_parent && v80[2].m_parent && LODWORD(v80[1].m_motion) <= LODWORD(v80[2].m_shape) )
    {
      m_motion_low = LOWORD(v80[2].m_motion);
      if ( v79 > m_motion_low )
        m_motion_low = v79;
      v81 = m_motion_low;
    }
    v83 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v84 = 32 * (v81 + 4);
    m_cur = (hk1AxisSweep::AabbInt *)v83->m_cur;
    v34 = (v84 + 127) & 0xFFFFFF80;
    v85 = (char *)m_cur + v34;
    if ( v34 > v83->m_slabSize || v85 > v83->m_end )
      m_cur = (hk1AxisSweep::AabbInt *)hkLifoAllocator::allocateFromNewSlab(v83, v34);
    else
      v83->m_cur = v85;
    CachedAabbsOrRecalculate = hkCollectionBvTreeAgent3_extractCachedAabbsOrRecalculate(
                                 input->m_bodyA.m_storage,
                                 input->m_overrideBodyA.m_storage,
                                 v5,
                                 input->m_input.m_storage,
                                 m_cur,
                                 v81,
                                 v84);
    v26 = input->m_bodyB.m_storage;
    v5 = v145;
    v27 = CachedAabbsOrRecalculate;
    v132 = input->m_bodyA.m_storage;
    cdBody = v26;
    collection = v145;
  }
  else
  {
    v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v22 = (_QWORD *)v21[1];
    if ( (unsigned __int64)v22 < v21[3] )
    {
      *v22 = "StQueryTree";
      v23 = __rdtsc();
      v24 = v22 + 2;
      *((_DWORD *)v24 - 2) = v23;
      v21[1] = v24;
    }
    if ( v16 )
    {
      hkTransformf::setInverse(&bTa, &input->m_aTb);
      v25 = hkBvTreeAgent3::calcAabbAndQueryTree(
              input->m_bodyA.m_storage,
              input->m_bodyB.m_storage,
              &bTa,
              &input->m_linearTimInfo,
              input->m_input.m_storage,
              0i64,
              hitListOut,
              0x800u);
      v26 = input->m_bodyA.m_storage;
      v27 = v25;
      v28 = input->m_bodyB.m_storage;
    }
    else
    {
      v29 = input->m_bodyA.m_storage;
      v30 = input->m_bodyB.m_storage;
      inputa = input->m_input.m_storage;
      linearTimInfo.m_quad = _mm_xor_ps(
                               (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
                               input->m_linearTimInfo.m_quad);
      v31 = hkBvTreeAgent3::calcAabbAndQueryTree(
              v30,
              v29,
              &input->m_aTb,
              &linearTimInfo,
              inputa,
              0i64,
              hitListOut,
              0x800u);
      v26 = input->m_bodyB.m_storage;
      v6 = v5;
      v5 = v145;
      v27 = v31;
      v28 = input->m_bodyA.m_storage;
      collection = v145;
    }
    cdBody = v26;
    v132 = v28;
    v32 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hk1AxisSweep::AabbInt *)v32->m_cur;
    v34 = (32 * (v27 + 4) + 127) & 0xFFFFFF80;
    v35 = (char *)m_cur + v34;
    if ( v34 > v32->m_slabSize || v35 > v32->m_end )
      m_cur = (hk1AxisSweep::AabbInt *)hkLifoAllocator::allocateFromNewSlab(v32, v34);
    else
      v32->m_cur = v35;
    v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v37 = (_QWORD *)v36[1];
    if ( (unsigned __int64)v37 < v36[3] )
    {
      *v37 = "StCalcAABBs";
      v38 = __rdtsc();
      v39 = v37 + 2;
      *((_DWORD *)v39 - 2) = v38;
      v36[1] = v39;
    }
    v131 = input->m_input.m_storage->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage;
    if ( v131 )
    {
      v40 = v132;
      for ( i = v132->m_parent; i; i = i->m_parent )
        v40 = i;
      hkAabbUtil::initOffsetAabbInput((hkMotionState *)v40->m_motion, (hkAabbUtil::OffsetAabbInput *)buffer);
    }
    aabbBufferSize_usedOnSpu = 0;
    if ( v27 > 0 )
    {
      v42 = 0i64;
      m_expansionMin = m_cur->m_expansionMin;
      do
      {
        v135 = hitListOut[v42];
        v43 = v6->vfptr->getChildShape(v6, v135, (char (*)[512])v142);
        ((void (__fastcall *)(hkpShape *, const void *, hkBaseObjectVtbl *, __m128 *))v43->vfptr[2].__vecDelDtor)(
          v43,
          v132->m_motion,
          v43->vfptr,
          &v137);
        if ( v131 )
        {
          v44 = *(int *)&buffer[272];
          v45 = *(__m128 *)(*(_QWORD *)buffer + 128i64);
          v46 = _mm_mul_ps(_mm_sub_ps(v138, v137), (__m128)xmmword_141A711B0);
          v47 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v137, v138), (__m128)xmmword_141A711B0), v138);
          v48 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v47, v47, 85), *(__m128 *)&buffer[368]),
                      _mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), *(__m128 *)&buffer[352])),
                    _mm_mul_ps(_mm_shuffle_ps(v47, v47, 170), *(__m128 *)&buffer[384])),
                  *(__m128 *)&buffer[400]);
          v49 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), *(__m128 *)&buffer[304]),
                      _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), *(__m128 *)&buffer[288])),
                    _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), *(__m128 *)&buffer[320])),
                  *(__m128 *)&buffer[336]);
          v50 = _mm_min_ps(v47, v49);
          v51 = _mm_max_ps(v47, v49);
          if ( *(int *)&buffer[272] > 0 )
          {
            v52 = _mm_sub_ps(v48, v45);
            v53 = &buffer[48];
            do
            {
              v54 = *((__m128 *)v53 + 1);
              v53 += 64;
              v55 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v54, v54, 255), v52), v45);
              v56 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v55, v55, 85), *((__m128 *)v53 - 5)),
                          _mm_mul_ps(_mm_shuffle_ps(v55, v55, 0), *((__m128 *)v53 - 6))),
                        _mm_mul_ps(_mm_shuffle_ps(v55, v55, 170), *((__m128 *)v53 - 4))),
                      v54);
              v50 = _mm_min_ps(v50, v56);
              v51 = _mm_max_ps(v51, v56);
              --v44;
            }
            while ( v44 );
          }
          v57 = _mm_mul_ps(v46, v46);
          v58 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
                  _mm_shuffle_ps(v57, v57, 170));
          v59 = _mm_rsqrt_ps(v58);
          v60 = _mm_andnot_ps(
                  _mm_cmple_ps(v58, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v59, v58), v59)),
                      _mm_mul_ps(*(__m128 *)_xmm, v59)),
                    v58));
          v61 = _mm_min_ps(
                  v60,
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_min_ps(
                        _mm_shuffle_ps(
                          *(__m128 *)(*(_QWORD *)buffer + 144i64),
                          *(__m128 *)(*(_QWORD *)buffer + 144i64),
                          255),
                        _mm_mul_ps(_mm_shuffle_ps((__m128)0x3F3B67AFu, (__m128)0x3F3B67AFu, 0), v60)),
                      v60),
                    v46));
          v62 = _mm_sub_ps(v50, v61);
          v63 = _mm_add_ps(v51, v61);
          v64 = _mm_min_ps(v62, v62);
          v65 = _mm_max_ps(v63, v63);
          v137 = v64;
          v138 = v65;
        }
        else
        {
          v65 = v138;
          v64 = v137;
        }
        v66 = input->m_input.m_storage;
        v67 = hkAabbUtil::hkAabbUint32MaxVal;
        ++v42;
        m_quad = v66->m_aabb32Info.m_bitOffsetLow.m_quad;
        v69 = aabbBufferSize_usedOnSpu++;
        v70 = _mm_max_ps(
                _mm_min_ps(
                  _mm_mul_ps(_mm_add_ps(m_quad, v64), v66->m_aabb32Info.m_bitScale.m_quad),
                  hkAabbUtil::hkAabbUint32MaxVal),
                (__m128)0i64);
        v71 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v70);
        *(__m128i *)m_cur[v69].m_min = _mm_or_si128(
                                         _mm_add_epi32(
                                           _mm_cvttps_epi32(
                                             _mm_max_ps(
                                               _mm_sub_ps(
                                                 v70,
                                                 _mm_and_ps(
                                                   (__m128)v71,
                                                   *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                                               (__m128)0i64)),
                                           _mm_slli_epi32(v71, 0x1Fu)),
                                         (__m128i)_mm_cmple_ps(
                                                    _mm_add_ps(
                                                      *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                                                      *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                                                    v70));
        v72 = _mm_max_ps(
                _mm_min_ps(
                  _mm_mul_ps(
                    _mm_add_ps(v66->m_aabb32Info.m_bitOffsetHigh.m_quad, v65),
                    v66->m_aabb32Info.m_bitScale.m_quad),
                  v67),
                (__m128)0i64);
        v73 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v72);
        *(__m128i *)m_cur[v69].m_max = _mm_or_si128(
                                         _mm_add_epi32(
                                           _mm_cvttps_epi32(
                                             _mm_max_ps(
                                               _mm_sub_ps(
                                                 v72,
                                                 _mm_and_ps(
                                                   (__m128)v73,
                                                   *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                                               (__m128)0i64)),
                                           _mm_slli_epi32(v73, 0x1Fu)),
                                         (__m128i)_mm_cmple_ps(
                                                    _mm_add_ps(
                                                      *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                                                      *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                                                    v72));
        *m_expansionMin = v135;
        m_expansionMin += 8;
      }
      while ( v42 < v27 );
      v5 = collection;
      v26 = cdBody;
    }
    v75 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v76 = (_QWORD *)v75[1];
    if ( (unsigned __int64)v76 < v75[3] )
    {
      *v76 = "StSortAABBs";
      v77 = __rdtsc();
      v74 = (unsigned __int64)HIDWORD(v77) << 32;
      v78 = v76 + 2;
      *((_DWORD *)v78 - 2) = v77;
      v75[1] = v78;
    }
    if ( v27 > 1 )
      hkAlgorithm::quickSortRecursive<hk1AxisSweep::AabbInt,hkAlgorithm::less<hk1AxisSweep::AabbInt>>(
        m_cur,
        0,
        v27 - 1,
        0);
  }
  if ( v27 )
  {
    v87 = ((__int64 (__fastcall *)(hkpShapeContainer *, unsigned __int64, LPVOID))v5->vfptr->getNumChildShapes)(
            v5,
            v74,
            v75);
    v88 = v87;
    if ( !v26->m_parent && v26[2].m_parent && LODWORD(v26[1].m_motion) <= LODWORD(v26[2].m_shape) )
    {
      v89 = LOWORD(v26[2].m_motion);
      if ( v87 > v89 )
        v89 = v87;
      v88 = v89;
    }
    v90 = v88 + 4;
    v91 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v92 = (hk1AxisSweep::AabbInt *)v91->m_cur;
    aabbBufferSize_usedOnSpu = 32 * (v88 + 4);
    v93 = (aabbBufferSize_usedOnSpu + 127) & 0xFFFFFF80;
    v94 = (char *)v92 + v93;
    if ( v93 > v91->m_slabSize || v94 > v91->m_end )
      v92 = (hk1AxisSweep::AabbInt *)hkLifoAllocator::allocateFromNewSlab(v91, v93);
    else
      v91->m_cur = v94;
    v95 = hkCollectionBvTreeAgent3_extractCachedAabbsOrRecalculate(
            cdBody,
            0i64,
            collection,
            input->m_input.m_storage,
            v92,
            v88,
            aabbBufferSize_usedOnSpu);
  }
  else
  {
    v95 = 0;
    v90 = 4;
    v96 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v92 = (hk1AxisSweep::AabbInt *)v96->m_cur;
    v97 = v92 + 4;
    if ( v96->m_slabSize < 128 || v97 > v96->m_end )
      v92 = (hk1AxisSweep::AabbInt *)hkLifoAllocator::allocateFromNewSlab(v96, 128);
    else
      v96->m_cur = v97;
  }
  v98 = v27 + 4;
  if ( v27 < v98 )
  {
    v99 = &m_cur[v27];
    v100 = v98 - v27;
    do
    {
      v99->m_min[0] = -1;
      ++v99;
      --v100;
    }
    while ( v100 );
  }
  v101 = v95 + 4;
  if ( v95 < v101 )
  {
    v102 = &v92[v95];
    v103 = v101 - v95;
    do
    {
      v102->m_min[0] = -1;
      ++v102;
      --v103;
    }
    while ( v103 );
  }
  v104 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v105 = (_QWORD *)v104[1];
  if ( (unsigned __int64)v105 < v104[3] )
  {
    *v105 = "St1-Axis";
    v106 = __rdtsc();
    v107 = v105 + 2;
    *((_DWORD *)v107 - 2) = v106;
    v104[1] = v107;
  }
  aabbBufferSize_usedOnSpu = 0;
  if ( v132 == input->m_bodyA.m_storage )
  {
    v108 = v95;
    v109 = v92;
    v110 = v27;
    v111 = m_cur;
  }
  else
  {
    v108 = v27;
    v109 = m_cur;
    v110 = v95;
    v111 = v92;
  }
  v112 = hk1AxisSweep::collide(v111, v110, v109, v108, pairsOut, 2047, (hkPadSpu<int> *)&aabbBufferSize_usedOnSpu);
  v113 = (32 * v90 + 127) & 0xFFFFFF80;
  v114 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v115 = (v113 + 15) & 0xFFFFFFF0;
  if ( v113 > v114->m_slabSize || (char *)v92 + v115 != v114->m_cur || v114->m_firstNonLifoEnd == v92 )
    hkLifoAllocator::slowBlockFree(v114, (char *)v92, v115);
  else
    v114->m_cur = v92;
  v116 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v117 = (v34 + 15) & 0xFFFFFFF0;
  if ( v34 > v116->m_slabSize || (char *)m_cur + v117 != v116->m_cur || v116->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v116, (char *)m_cur, v117);
  else
    v116->m_cur = m_cur;
  if ( v112 )
  {
    v118 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v119 = (_QWORD *)v118[1];
    if ( (unsigned __int64)v119 < v118[3] )
    {
      *v119 = "StSortKeyPairs";
      v120 = __rdtsc();
      v121 = v119 + 2;
      *((_DWORD *)v121 - 2) = v120;
      v118[1] = v121;
    }
    v122 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v123 = v122[1];
    if ( v123 < v122[3] )
    {
      v124 = v123 + 16;
      *(_QWORD *)(v124 - 16) = "MiNumKeyPairs";
      *(float *)(v124 - 8) = (float)v112;
      v122[1] = v124;
    }
    if ( v112 > 1 )
      hkAlgorithm::quickSortRecursive<hkpShapeKeyPair,hkAlgorithm::less<hkpShapeKeyPair>>(
        (hkpShapeKeyPair *)pairsOut,
        0,
        v112 - 1,
        0);
  }
  pairsOut[v112] = (hkKeyPair)-1i64;
  v125 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v126 = (_QWORD *)v125[1];
  if ( (unsigned __int64)v126 < v125[3] )
  {
    *v126 = "lt";
    v127 = __rdtsc();
    v128 = v126 + 2;
    *((_DWORD *)v128 - 2) = v127;
    v125[1] = v128;
  }
  return (unsigned int)v112;
}

// File Line: 580
// RVA: 0xD2E200
char *__fastcall hkpCollectionCollectionAgent3::process(
        hkpAgent3ProcessInput *input,
        hkpAgentEntry *entry,
        char *agentData,
        hkVector4f *separatingNormal,
        hkpProcessCollisionOutput *output)
{
  _QWORD *Value; // rbx
  unsigned __int64 v8; // r9
  unsigned __int64 v9; // rax
  hkpShapeContainer *v10; // rsi
  hkpShapeContainer *v11; // r12
  hkLifoAllocator *v12; // rax
  hkKeyPair *newKeys; // rdi
  hkKeyPair *v14; // rcx
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rax
  int v17; // eax
  __int64 v18; // r15
  unsigned __int64 v19; // r8
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // rcx
  unsigned __int64 v22; // rax
  hkLifoAllocator *v23; // rax
  unsigned int *m_cur; // rsi
  int v25; // ebp
  char *v26; // rcx
  __int64 v27; // rdx
  unsigned int *p_m_keyB; // r8
  unsigned int v29; // ecx
  __int128 v30; // xmm1
  unsigned __int64 v31; // rcx
  hkpCdBody *m_storage; // rax
  __int128 v33; // xmm0
  hkVector4f v34; // xmm1
  hkVector4f v35; // xmm0
  hkVector4f v36; // xmm1
  hkVector4f v37; // xmm0
  __int128 v38; // xmm1
  unsigned __int64 v39; // rax
  hkLifoAllocator *v40; // rax
  int v41; // r8d
  hkLifoAllocator *v42; // rax
  unsigned __int64 v43; // rcx
  unsigned __int64 v44; // rax
  hkpAgent3ProcessInput inputIn; // [rsp+30h] [rbp-B8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = Value[1];
  if ( v8 < Value[3] )
  {
    *(_QWORD *)v8 = "LtProcessCollColl";
    *(_QWORD *)(v8 + 16) = "StInit";
    v9 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v9;
    Value[1] = v8 + 24;
  }
  v10 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))input->m_bodyA.m_storage->m_shape->vfptr[7].__vecDelDtor)(input->m_bodyA.m_storage->m_shape);
  v11 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))input->m_bodyB.m_storage->m_shape->vfptr[7].__vecDelDtor)(input->m_bodyB.m_storage->m_shape);
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  newKeys = (hkKeyPair *)v12->m_cur;
  v14 = newKeys + 2048;
  if ( v12->m_slabSize < 0x4000 || v14 > v12->m_end )
    newKeys = (hkKeyPair *)hkLifoAllocator::allocateFromNewSlab(v12, 0x4000);
  else
    v12->m_cur = v14;
  v15 = Value[1];
  if ( v15 < Value[3] )
  {
    *(_QWORD *)v15 = "Stquery";
    v16 = __rdtsc();
    *(_DWORD *)(v15 + 8) = v16;
    Value[1] = v15 + 16;
  }
  v17 = hkpCollectionCollectionAgent3::process_gatherShapeKeys(input, v10, v11, newKeys);
  v18 = v17;
  if ( v17 >= 0 )
  {
    if ( input->m_overrideBodyA.m_storage )
    {
      v21 = Value[1];
      if ( v21 < Value[3] )
      {
        *(_QWORD *)v21 = "Stshrink";
        v22 = __rdtsc();
        *(_DWORD *)(v21 + 8) = v22;
        Value[1] = v21 + 16;
      }
      v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      m_cur = (unsigned int *)v23->m_cur;
      v25 = (4 * v18 + 131) & 0xFFFFFF80;
      v26 = (char *)m_cur + v25;
      if ( v25 > v23->m_slabSize || v26 > v23->m_end )
        m_cur = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v23, v25);
      else
        v23->m_cur = v26;
      v27 = 0i64;
      if ( (int)v18 >= 0 )
      {
        p_m_keyB = &newKeys->m_keyB;
        do
        {
          v29 = *p_m_keyB;
          ++v27;
          p_m_keyB += 2;
          m_cur[v27 - 1] = v29;
        }
        while ( v27 <= v18 );
      }
      v30 = *(_OWORD *)&input->m_overrideBodyA.m_storage;
      v31 = Value[1];
      m_storage = input->m_overrideBodyA.m_storage;
      *(_OWORD *)&inputIn.m_bodyA.m_storage = *(_OWORD *)&input->m_bodyA.m_storage;
      v33 = *(_OWORD *)&input->m_contactMgr.m_storage;
      inputIn.m_input.m_storage = (hkpProcessCollisionInput *)*((_QWORD *)&v30 + 1);
      inputIn.m_bodyA.m_storage = m_storage;
      inputIn.m_overrideBodyA.m_storage = 0i64;
      v34.m_quad = (__m128)input->m_aTb.m_rotation.m_col0;
      *(_OWORD *)&inputIn.m_contactMgr.m_storage = v33;
      inputIn.m_aTb.m_rotation.m_col1 = input->m_aTb.m_rotation.m_col1;
      v35.m_quad = (__m128)input->m_aTb.m_translation;
      inputIn.m_aTb.m_rotation.m_col0 = (hkVector4f)v34.m_quad;
      v36.m_quad = (__m128)input->m_aTb.m_rotation.m_col2;
      inputIn.m_aTb.m_translation = (hkVector4f)v35.m_quad;
      v37.m_quad = (__m128)input->m_linearTimInfo;
      inputIn.m_aTb.m_rotation.m_col2 = (hkVector4f)v36.m_quad;
      v38 = *(_OWORD *)&input->m_distAtT1.m_storage;
      inputIn.m_linearTimInfo = (hkVector4f)v37.m_quad;
      *(_OWORD *)&inputIn.m_distAtT1.m_storage = v38;
      if ( v31 < Value[3] )
      {
        *(_QWORD *)v31 = "Stprocess";
        v39 = __rdtsc();
        *(_DWORD *)(v31 + 8) = v39;
        Value[1] = v31 + 16;
      }
      hkAgent1nMachine_Process((hkpAgent1nTrack *)(agentData + 8), &inputIn, v11, m_cur, output);
      v40 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v41 = (v25 + 15) & 0xFFFFFFF0;
      if ( v25 > v40->m_slabSize || (char *)m_cur + v41 != v40->m_cur || v40->m_firstNonLifoEnd == m_cur )
        hkLifoAllocator::slowBlockFree(v40, (char *)m_cur, v41);
      else
        v40->m_cur = m_cur;
    }
    else
    {
      v19 = Value[1];
      if ( v19 < Value[3] )
      {
        *(_QWORD *)v19 = "Stprocess";
        v20 = __rdtsc();
        *(_DWORD *)(v19 + 8) = v20;
        Value[1] = v19 + 16;
      }
      hkAgentNmMachine_Process((hkpAgent1nTrack *)(agentData + 8), input, v10, v11, (hkpShapeKeyPair *)newKeys, output);
    }
  }
  v42 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v42->m_slabSize < 0x4000 || &newKeys[2048] != v42->m_cur || v42->m_firstNonLifoEnd == newKeys )
    hkLifoAllocator::slowBlockFree(v42, (char *)newKeys, 0x4000);
  else
    v42->m_cur = newKeys;
  v43 = Value[1];
  if ( v43 < Value[3] )
  {
    *(_QWORD *)v43 = "lt";
    v44 = __rdtsc();
    *(_DWORD *)(v43 + 8) = v44;
    Value[1] = v43 + 16;
  }
  return agentData + 32;
}

// File Line: 671
// RVA: 0xD2E6B0
void __fastcall hkpCollectionCollectionAgent3::updateFilter(
        hkpAgentEntry *entry,
        char *agentData,
        hkpCdBody *bodyA,
        hkpCdBody *bodyB,
        hkpCollisionInput *input,
        hkpContactMgr *mgr,
        hkpConstraintOwner *constraintOwner)
{
  hkpShape *m_shape; // rcx
  hkpShape *v8; // rbx
  hkpAgent1nMachine_VisitorInput vin; // [rsp+20h] [rbp-48h] BYREF

  m_shape = bodyA->m_shape;
  v8 = bodyB->m_shape;
  vin.m_input = input;
  vin.m_bodyA = bodyA;
  vin.m_contactMgr = mgr;
  vin.m_collectionBodyB = bodyB;
  vin.m_constraintOwner = constraintOwner;
  vin.m_containerShapeA = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))m_shape->vfptr[7].__vecDelDtor)(m_shape);
  vin.m_containerShapeB = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))v8->vfptr[7].__vecDelDtor)(v8);
  hkAgentNmMachine_UpdateShapeCollectionFilter((hkpAgent1nTrack *)(agentData + 8), &vin);
}

// File Line: 691
// RVA: 0xD2E730
void __fastcall hkpCollectionCollectionAgent3::invalidateTim(
        hkpAgentEntry *entry,
        char *agentData,
        hkpCollisionInput *input)
{
  hkAgent1nMachine_InvalidateTim((hkpAgent1nTrack *)(agentData + 8), input);
}

// File Line: 698
// RVA: 0xD2E750
void __fastcall hkpCollectionCollectionAgent3::warpTime(
        hkpAgentEntry *entry,
        char *agentData,
        float oldTime,
        float newTime,
        hkpCollisionInput *input)
{
  hkAgent1nMachine_WarpTime((hkpAgent1nTrack *)(agentData + 8), oldTime, newTime, input);
}

