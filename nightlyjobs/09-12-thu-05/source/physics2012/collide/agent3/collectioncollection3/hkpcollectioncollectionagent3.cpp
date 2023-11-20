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
  hkpCollisionDispatcher *v1; // rbx
  hkpCollisionDispatcher::Agent3Funcs f; // [rsp+20h] [rbp-68h]

  v1 = dispatcher;
  *(_WORD *)&f.m_isPredictive.m_bool = 0;
  f.m_reusePreviousEntry.m_bool = 0;
  f.m_updateFilterFunc = 0i64;
  f.m_invalidateTimFunc = 0i64;
  f.m_warpTimeFunc = 0i64;
  f.m_sepNormalFunc = 0i64;
  hkpCollectionCollectionAgent3::initAgentFunc(&f);
  hkpCollisionDispatcher::registerAgent3(v1, &f, BV_TREE, BV_TREE);
  *(_WORD *)&f.m_ignoreSymmetricVersion.m_bool = 257;
  hkpCollisionDispatcher::registerAgent3(v1, &f, COLLECTION, BV_TREE);
  hkpCollisionDispatcher::registerAgent3(v1, &f, BV_TREE, COLLECTION);
  hkpCollisionDispatcher::registerAgent3(v1, &f, COLLECTION, COLLECTION);
  v1->m_midphaseAgent3Registered.m_bool = 1;
  hkpCollectionCollectionAgent3::g_agentRegistered = 1;
}

// File Line: 86
// RVA: 0xD2E770
__int64 __fastcall hkCollectionBvTreeAgent3_extractCachedAabbsOrRecalculate(hkpCdBody *cdBody, hkpCdBody *overrideCdBody, hkpShapeContainer *collection, hkpProcessCollisionInput *input, hk1AxisSweep::AabbInt *aabbs, int aabbsCapacity, int aabbBufferSize_usedOnSpu)
{
  unsigned int v7; // er15
  hkpShapeContainer *v8; // rdi
  hkpCdBody *v9; // r8
  __m128 *v10; // rbp
  hkpCdBody *v11; // rsi
  unsigned int v12; // er14
  unsigned int *v13; // rbx
  const void **v14; // r10
  unsigned __int16 v15; // ax
  hkpShape *v17; // rsi
  signed int v18; // ebp
  unsigned int *v19; // r11
  char *v20; // r9
  __m128i v21; // xmm4
  unsigned int v22; // eax
  __m128i v23; // xmm3
  __m128i v24; // xmm3
  signed __int64 v25; // rcx
  signed __int64 v26; // rdx
  __int64 v27; // rax
  __m128i v28; // xmm4
  unsigned int v29; // eax
  __m128i v30; // xmm3
  __m128i v31; // xmm3
  hk1AxisSweep::AabbInt *v32; // rcx
  signed __int64 v33; // r10
  signed __int64 v34; // rdi
  __int64 v35; // rax
  hkpCdBody *v36; // rax
  unsigned int v37; // ebx
  hk1AxisSweep::AabbInt *v38; // r12
  _QWORD *v39; // rax
  __int128 v40; // xmm2
  __int64 v41; // rcx
  hkVector4f v42; // xmm7
  __m128 v43; // xmm8
  __m128 v44; // xmm5
  __m128 v45; // xmm4
  __m128 v46; // xmm2
  __m128 v47; // xmm6
  __m128 v48; // xmm5
  __m128 v49; // xmm4
  hkVector4f *v50; // rax
  __m128 v51; // xmm3
  __m128 v52; // xmm1
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  __m128 v55; // xmm3
  __m128 v56; // xmm1
  __m128 v57; // xmm4
  __m128 v58; // xmm4
  __m128 v59; // xmm6
  __m128 v60; // xmm5
  __m128 v61; // xmm6
  __m128 v62; // xmm5
  __m128 v63; // xmm4
  __m128i *v64; // rax
  __m128 v65; // xmm6
  __m128i v66; // xmm2
  __m128 v67; // xmm5
  __m128i v68; // xmm2
  __m128 v69; // [rsp+20h] [rbp-428h]
  __m128 v70; // [rsp+30h] [rbp-418h]
  hkAabbUtil::OffsetAabbInput inputa; // [rsp+40h] [rbp-408h]
  char v72; // [rsp+1E0h] [rbp-268h]

  v7 = input->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage;
  v8 = collection;
  v9 = cdBody->m_parent;
  v10 = (__m128 *)input;
  v11 = cdBody;
  v12 = 0;
  if ( v9 )
  {
LABEL_22:
    if ( v7 )
    {
      if ( v9 )
      {
        v36 = cdBody->m_parent;
        do
        {
          cdBody = v36;
          v36 = v36->m_parent;
        }
        while ( v36 );
      }
      hkAabbUtil::initOffsetAabbInput((hkMotionState *)cdBody->m_motion, &inputa);
    }
    v37 = ((__int64 (__fastcall *)(hkpShapeContainer *, hkpCdBody *))v8->vfptr->getFirstKey)(v8, overrideCdBody);
    if ( v37 != -1 )
    {
      v38 = aabbs;
      do
      {
        v39 = (_QWORD *)v8->vfptr->getChildShape(v8, v37, (char (*)[512])&v72);
        v40 = v10[1].m128_u32[0];
        (*(void (__fastcall **)(_QWORD *, const void *, _QWORD, __m128 *))(*v39 + 32i64))(
          v39,
          v11->m_motion,
          *v39,
          &v69);
        if ( v7 )
        {
          v41 = inputa.m_numTransforms.m_storage;
          v42.m_quad = (__m128)inputa.m_motionState.m_storage->m_sweptTransform.m_centerOfMassLocal;
          v43 = _mm_mul_ps(_mm_sub_ps(v70, v69), (__m128)xmmword_141A711B0);
          v44 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v69, v70), (__m128)xmmword_141A711B0), v70);
          v45 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v44, v44, 85), inputa.m_endTransformInv.m_rotation.m_col1.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v44, v44, 0), inputa.m_endTransformInv.m_rotation.m_col0.m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v44, v44, 170), inputa.m_endTransformInv.m_rotation.m_col2.m_quad)),
                  inputa.m_endTransformInv.m_translation.m_quad);
          v46 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v45, v45, 85), inputa.m_startTransform.m_rotation.m_col1.m_quad),
                      _mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), inputa.m_startTransform.m_rotation.m_col0.m_quad)),
                    _mm_mul_ps(_mm_shuffle_ps(v45, v45, 170), inputa.m_startTransform.m_rotation.m_col2.m_quad)),
                  inputa.m_startTransform.m_translation.m_quad);
          v47 = _mm_min_ps(v44, v46);
          v48 = _mm_max_ps(v44, v46);
          if ( inputa.m_numTransforms.m_storage > 0i64 )
          {
            v49 = _mm_sub_ps(v45, v42.m_quad);
            v50 = &inputa.m_transforms[0].m_rotation.m_col2;
            do
            {
              v51 = v50[1].m_quad;
              v50 += 4;
              v52 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v51, v51, 255), v49), v42.m_quad);
              v53 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v52, v52, 85), v50[-5].m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v52, v52, 0), v50[-6].m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v52, v52, 170), v50[-4].m_quad)),
                      v51);
              v47 = _mm_min_ps(v47, v53);
              v48 = _mm_max_ps(v48, v53);
              --v41;
            }
            while ( v41 );
          }
          v54 = _mm_mul_ps(v43, v43);
          v55 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
                  _mm_shuffle_ps(v54, v54, 170));
          v56 = _mm_rsqrt_ps(v55);
          v57 = _mm_andnot_ps(
                  _mm_cmpleps(v55, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v56, v55), v56)),
                      _mm_mul_ps(*(__m128 *)_xmm, v56)),
                    v55));
          v58 = _mm_min_ps(
                  v57,
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_min_ps(
                        _mm_shuffle_ps(
                          inputa.m_motionState.m_storage->m_deltaAngle.m_quad,
                          inputa.m_motionState.m_storage->m_deltaAngle.m_quad,
                          255),
                        _mm_mul_ps(_mm_shuffle_ps((__m128)0x3F3B67AFu, (__m128)0x3F3B67AFu, 0), v57)),
                      v57),
                    v43));
          v59 = _mm_sub_ps(v47, v58);
          v60 = _mm_add_ps(v48, v58);
          v61 = _mm_min_ps(v59, v59);
          v62 = _mm_max_ps(v60, v60);
        }
        else
        {
          v62 = v70;
          v61 = v69;
        }
        v63 = hkAabbUtil::hkAabbUint32MaxVal;
        v64 = (__m128i *)v38;
        ++v12;
        ++v38;
        v65 = _mm_max_ps(
                _mm_min_ps(_mm_mul_ps(_mm_add_ps(v61, v10[3]), v10[5]), hkAabbUtil::hkAabbUint32MaxVal),
                (__m128)0i64);
        v66 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v65);
        _mm_store_si128(
          v64,
          _mm_or_si128(
            _mm_add_epi32(
              _mm_cvttps_epi32(
                _mm_max_ps(
                  _mm_sub_ps(v65, _mm_and_ps((__m128)v66, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                  (__m128)0i64)),
              _mm_slli_epi32(v66, 0x1Fu)),
            (__m128i)_mm_cmpleps(
                       _mm_add_ps(
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                       v65)));
        v67 = _mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(v62, v10[4]), v10[5]), v63), (__m128)0i64);
        v68 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v67);
        _mm_store_si128(
          v64 + 1,
          _mm_or_si128(
            _mm_add_epi32(
              _mm_cvttps_epi32(
                _mm_max_ps(
                  _mm_sub_ps(v67, _mm_and_ps((__m128)v68, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                  (__m128)0i64)),
              _mm_slli_epi32(v68, 0x1Fu)),
            (__m128i)_mm_cmpleps(
                       _mm_add_ps(
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                       v67)));
        HIDWORD(v64->m128i_i64[1]) = v37;
        v37 = v8->vfptr->getNextKey(v8, v37);
      }
      while ( v37 != -1 );
    }
LABEL_36:
    if ( (signed int)v12 > 1 )
      hkAlgorithm::quickSortRecursive<hk1AxisSweep::AabbInt,hkAlgorithm::less<hk1AxisSweep::AabbInt>>(
        aabbs,
        0,
        v12 - 1,
        0);
    return v12;
  }
  v13 = (unsigned int *)cdBody[2].m_parent;
  v14 = &cdBody[1].m_motion;
  if ( !v13 || *(_DWORD *)v14 > LODWORD(cdBody[2].m_shape) )
  {
    if ( LODWORD(cdBody[1].m_motion) <= LODWORD(cdBody[2].m_shape) && overrideCdBody )
    {
      if ( v7 )
      {
        v12 = 1;
        v28 = _mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)HIDWORD(cdBody[1].m_parent), (__m128i)0i64), (__m128i)0i64);
        v29 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v28, 255));
        v30 = _mm_sub_epi32(
                _mm_unpacklo_epi32(
                  _mm_unpacklo_epi32(
                    _mm_cvtsi32_si128((unsigned int)cdBody[1].m_motion),
                    _mm_cvtsi32_si128((unsigned int)cdBody[1].m_parent)),
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(HIDWORD(cdBody[1].m_motion)), _mm_cvtsi32_si128(0))),
                _mm_slli_epi32(v28, v29));
        _mm_storel_epi64((__m128i *)aabbs, v30);
        aabbs->m_min[2] = (unsigned __int128)_mm_shuffle_epi32(v30, 170);
        v31 = _mm_add_epi32(
                _mm_unpacklo_epi32(
                  _mm_unpacklo_epi32(
                    _mm_cvtsi32_si128((unsigned int)cdBody[2].m_shape),
                    _mm_cvtsi32_si128(cdBody[2].m_shapeKey)),
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(HIDWORD(cdBody[2].m_shape)), _mm_cvtsi32_si128(0))),
                _mm_slli_epi32(
                  _mm_unpacklo_epi16(
                    _mm_unpacklo_epi8((__m128i)*(&cdBody[2].m_shapeKey + 1), (__m128i)0i64),
                    (__m128i)0i64),
                  v29));
        _mm_storel_epi64((__m128i *)aabbs->m_max, v31);
        aabbs->m_max[2] = (unsigned __int128)_mm_shuffle_epi32(v31, 170);
        *(_DWORD *)aabbs->m_expansionMin = 0;
      }
      else
      {
        v32 = aabbs;
        v33 = (char *)v14 - (char *)aabbs;
        v34 = 4i64;
        do
        {
          v35 = *(_QWORD *)((char *)v32->m_min + v33);
          v32 = (hk1AxisSweep::AabbInt *)((char *)v32 + 8);
          *(_QWORD *)&v32[-1].m_max[2] = v35;
          --v34;
        }
        while ( v34 );
        *(_DWORD *)aabbs->m_expansionMin = 0;
        v12 = 1;
      }
      return v12;
    }
    goto LABEL_22;
  }
  v15 = (unsigned __int16)cdBody[2].m_motion;
  if ( !v15 )
    return 0i64;
  v17 = cdBody[3].m_shape;
  v18 = 0;
  if ( v15 > 0u )
  {
    v19 = v13 + 5;
    v20 = aabbs->m_expansionMin;
    do
    {
      if ( v7 )
      {
        v21 = _mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)*(v19 - 2), (__m128i)0i64), (__m128i)0i64);
        v22 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v21, 255));
        v23 = _mm_sub_epi32(
                _mm_unpacklo_epi32(
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(*v13), _mm_cvtsi32_si128(*(v19 - 3))),
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v19 - 4)), _mm_cvtsi32_si128(0))),
                _mm_slli_epi32(v21, v22));
        _mm_storel_epi64((__m128i *)(v20 - 12), v23);
        *((_DWORD *)v20 - 1) = (unsigned __int128)_mm_shuffle_epi32(v23, 170);
        v24 = _mm_add_epi32(
                _mm_unpacklo_epi32(
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v19 - 1)), _mm_cvtsi32_si128(v19[1])),
                  _mm_unpacklo_epi32(_mm_cvtsi32_si128(*v19), _mm_cvtsi32_si128(0))),
                _mm_slli_epi32(
                  _mm_unpacklo_epi16(_mm_unpacklo_epi8((__m128i)v19[2], (__m128i)0i64), (__m128i)0i64),
                  v22));
        _mm_storel_epi64((__m128i *)(v20 + 4), v24);
        *((_DWORD *)v20 + 3) = (unsigned __int128)_mm_shuffle_epi32(v24, 170);
      }
      else
      {
        v25 = (signed __int64)(v20 - 12);
        v26 = 4i64;
        do
        {
          v27 = *(_QWORD *)((char *)v13 - (v20 - 12) + v25);
          v25 += 8i64;
          *(_QWORD *)(v25 - 8) = v27;
          --v26;
        }
        while ( v26 );
      }
      ++v18;
      v13 += 8;
      *(_DWORD *)v20 = v17->vfptr;
      v19 += 8;
      v17 = (hkpShape *)((char *)v17 + 4);
      ++v12;
      v20 += 32;
    }
    while ( v18 < *((unsigned __int16 *)v14 + 16) );
  }
  if ( v7 )
    goto LABEL_36;
  return v12;
}

// File Line: 258
// RVA: 0xD2EDA0
void __fastcall hkCollectionBvTreeAgent3_calcAabbs(hkpAgent3ProcessInput *input, hkpShapeContainer *container, hkpCdBody *cdBody, const unsigned int *hitList, int numHits, hk1AxisSweep::AabbInt *aabbsOut)
{
  const unsigned int *v6; // r15
  hkpCdBody *v7; // rsi
  hkpShapeContainer *v8; // rbx
  hkpAgent3ProcessInput *v9; // rbp
  unsigned int v10; // er14
  hkpCdBody *v11; // rax
  hkpCdBody *i; // rcx
  hk1AxisSweep::AabbInt *v13; // r13
  char *v14; // r12
  unsigned int v15; // edi
  _QWORD *v16; // rax
  __int128 v17; // xmm2
  __int64 v18; // rcx
  hkVector4f v19; // xmm6
  __m128 v20; // xmm7
  __m128 v21; // xmm9
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  __m128 v24; // xmm5
  __m128 v25; // xmm9
  __m128 v26; // xmm4
  hkVector4f *v27; // rax
  __m128 v28; // xmm3
  __m128 v29; // xmm1
  __m128 v30; // xmm2
  __m128 v31; // xmm1
  __m128 v32; // xmm3
  __m128 v33; // xmm1
  __m128 v34; // xmm4
  __m128 v35; // xmm4
  __m128 v36; // xmm5
  __m128 v37; // xmm9
  __m128 v38; // xmm5
  __m128 v39; // xmm9
  __m128 *v40; // rax
  bool v41; // zf
  __m128 v42; // xmm8
  __m128 v43; // xmm4
  __m128i v44; // xmm3
  __m128i v45; // xmm2
  __m128 v46; // xmm3
  __m128 v47; // xmm3
  __m128i v48; // xmm2
  __m128 v49; // [rsp+20h] [rbp-438h]
  __m128 v50; // [rsp+30h] [rbp-428h]
  hkAabbUtil::OffsetAabbInput inputa; // [rsp+40h] [rbp-418h]
  char v52; // [rsp+1E0h] [rbp-278h]
  __int64 v53; // [rsp+460h] [rbp+8h]

  v6 = hitList;
  v7 = cdBody;
  v8 = container;
  v9 = input;
  v10 = input->m_input.m_storage->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage;
  if ( v10 )
  {
    v11 = cdBody->m_parent;
    for ( i = cdBody; v11; v11 = v11->m_parent )
      i = v11;
    hkAabbUtil::initOffsetAabbInput((hkMotionState *)i->m_motion, &inputa);
  }
  if ( numHits > 0 )
  {
    v13 = aabbsOut;
    v53 = (unsigned int)numHits;
    v14 = aabbsOut->m_expansionMin;
    do
    {
      v15 = *v6;
      v16 = (_QWORD *)v8->vfptr->getChildShape(v8, *v6, (char (*)[512])&v52);
      v17 = LODWORD(v9->m_input.m_storage->m_tolerance.m_storage);
      (*(void (__fastcall **)(_QWORD *, const void *, _QWORD, __m128 *))(*v16 + 32i64))(v16, v7->m_motion, *v16, &v49);
      if ( v10 )
      {
        v18 = inputa.m_numTransforms.m_storage;
        v19.m_quad = (__m128)inputa.m_motionState.m_storage->m_sweptTransform.m_centerOfMassLocal;
        v20 = _mm_mul_ps(_mm_sub_ps(v50, v49), (__m128)xmmword_141A711B0);
        v21 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v49, v50), (__m128)xmmword_141A711B0), v50);
        v22 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v21, v21, 85), inputa.m_endTransformInv.m_rotation.m_col1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), inputa.m_endTransformInv.m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v21, v21, 170), inputa.m_endTransformInv.m_rotation.m_col2.m_quad)),
                inputa.m_endTransformInv.m_translation.m_quad);
        v23 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v22, v22, 85), inputa.m_startTransform.m_rotation.m_col1.m_quad),
                    _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), inputa.m_startTransform.m_rotation.m_col0.m_quad)),
                  _mm_mul_ps(_mm_shuffle_ps(v22, v22, 170), inputa.m_startTransform.m_rotation.m_col2.m_quad)),
                inputa.m_startTransform.m_translation.m_quad);
        v24 = _mm_min_ps(v21, v23);
        v25 = _mm_max_ps(v21, v23);
        if ( inputa.m_numTransforms.m_storage > 0i64 )
        {
          v26 = _mm_sub_ps(v22, v19.m_quad);
          v27 = &inputa.m_transforms[0].m_rotation.m_col2;
          do
          {
            v28 = v27[1].m_quad;
            v27 += 4;
            v29 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v28, 255), v26), v19.m_quad);
            v30 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), v27[-5].m_quad),
                        _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), v27[-6].m_quad)),
                      _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), v27[-4].m_quad)),
                    v28);
            v24 = _mm_min_ps(v24, v30);
            v25 = _mm_max_ps(v25, v30);
            --v18;
          }
          while ( v18 );
        }
        v31 = _mm_mul_ps(v20, v20);
        v32 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v31, v31, 85), _mm_shuffle_ps(v31, v31, 0)),
                _mm_shuffle_ps(v31, v31, 170));
        v33 = _mm_rsqrt_ps(v32);
        v34 = _mm_andnot_ps(
                _mm_cmpleps(v32, (__m128)0i64),
                _mm_mul_ps(
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v33, v32), v33)),
                    _mm_mul_ps(*(__m128 *)_xmm, v33)),
                  v32));
        v35 = _mm_min_ps(
                v34,
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_min_ps(
                      _mm_shuffle_ps(
                        inputa.m_motionState.m_storage->m_deltaAngle.m_quad,
                        inputa.m_motionState.m_storage->m_deltaAngle.m_quad,
                        255),
                      _mm_mul_ps(_mm_shuffle_ps((__m128)0x3F3B67AFu, (__m128)0x3F3B67AFu, 0), v34)),
                    v34),
                  v20));
        v36 = _mm_sub_ps(v24, v35);
        v37 = _mm_add_ps(v25, v35);
        v38 = _mm_min_ps(v36, v36);
        v39 = _mm_max_ps(v37, v37);
        v49 = v38;
        v50 = v39;
      }
      else
      {
        v39 = v50;
        v38 = v49;
      }
      v40 = (__m128 *)v9->m_input.m_storage;
      v14 += 32;
      ++v13;
      ++v6;
      v41 = v53-- == 1;
      v42 = _mm_add_ps(
              *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
              *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31);
      v43 = _mm_max_ps(
              _mm_min_ps(_mm_mul_ps(_mm_add_ps(v40[3], v38), v40[5]), hkAabbUtil::hkAabbUint32MaxVal),
              (__m128)0i64);
      v44 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v43);
      v45 = _mm_or_si128(
              _mm_add_epi32(
                _mm_cvttps_epi32(
                  _mm_max_ps(
                    _mm_sub_ps(v43, _mm_and_ps((__m128)v44, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                    (__m128)0i64)),
                _mm_slli_epi32(v44, 0x1Fu)),
              (__m128i)_mm_cmpleps(v42, v43));
      v46 = _mm_add_ps(v40[4], v39);
      _mm_store_si128((__m128i *)&v13[-1], v45);
      v47 = _mm_max_ps(_mm_min_ps(_mm_mul_ps(v46, v40[5]), hkAabbUtil::hkAabbUint32MaxVal), (__m128)0i64);
      v48 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v47);
      _mm_store_si128(
        (__m128i *)v13[-1].m_max,
        _mm_or_si128(
          _mm_add_epi32(
            _mm_cvttps_epi32(
              _mm_max_ps(
                _mm_sub_ps(v47, _mm_and_ps((__m128)v48, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                (__m128)0i64)),
            _mm_slli_epi32(v48, 0x1Fu)),
          (__m128i)_mm_cmpleps(v42, v47)));
      *((_DWORD *)v14 - 8) = v15;
    }
    while ( !v41 );
  }
}

// File Line: 298
// RVA: 0xD2D670
__int64 __fastcall hkpCollectionCollectionAgent3::process_gatherShapeKeys(hkpAgent3ProcessInput *input, hkpShapeContainer *shapeContainerA, hkpShapeContainer *shapeContainerB, hkpShapeKeyPair *shapeKeyPairs)
{
  hkpAgent3ProcessInput *v4; // rbx
  hkpShapeContainer *v5; // r12
  hkpShapeContainer *v6; // r15
  _QWORD *v7; // rax
  unsigned __int64 v8; // rcx
  _QWORD *v9; // r10
  unsigned __int64 v10; // rax
  hkpCdBody *v11; // r8
  hkpCdBody *v12; // r9
  hkpCollisionDispatcher *v13; // rdx
  unsigned __int8 v14; // si
  unsigned __int8 v15; // r14
  unsigned __int8 v16; // di
  bool v17; // al
  hkpShapeCollection *v18; // r15
  hkpShapeCollection *v19; // rax
  hkpShapeCollection *v20; // rcx
  _QWORD *v21; // r8
  _QWORD *v22; // rcx
  unsigned __int64 v23; // rax
  signed __int64 v24; // rcx
  signed int v25; // eax
  hkpCdBody *v26; // rdi
  signed int v27; // er13
  hkpCdBody *v28; // rax
  hkpCdBody *v29; // rdx
  hkpCdBody *v30; // rcx
  hkpProcessCollisionInput *v31; // ST20_8
  signed int v32; // eax
  hkLifoAllocator *v33; // rax
  hk1AxisSweep::AabbInt *v34; // rsi
  int v35; // er14
  char *v36; // rcx
  _QWORD *v37; // r8
  _QWORD *v38; // rcx
  unsigned __int64 v39; // rax
  signed __int64 v40; // rcx
  hkpCdBody *v41; // rcx
  hkpCdBody *i; // rax
  signed __int64 v43; // rdi
  _QWORD *v44; // rax
  __int128 v45; // xmm2
  __int64 v46; // rcx
  __m128 v47; // xmm5
  __m128 v48; // xmm8
  __m128 v49; // xmm6
  __m128 v50; // xmm4
  __m128 v51; // xmm2
  __m128 v52; // xmm7
  __m128 v53; // xmm6
  __m128 v54; // xmm4
  char *v55; // rax
  __m128 v56; // xmm3
  __m128 v57; // xmm1
  __m128 v58; // xmm2
  __m128 v59; // xmm1
  __m128 v60; // xmm3
  __m128 v61; // xmm1
  __m128 v62; // xmm4
  __m128 v63; // xmm4
  __m128 v64; // xmm7
  __m128 v65; // xmm6
  __m128 v66; // xmm7
  __m128 v67; // xmm6
  hkpProcessCollisionInput *v68; // rax
  __m128 v69; // xmm5
  __m128 v70; // xmm4
  signed __int64 v71; // rcx
  __m128 v72; // xmm4
  __m128i v73; // xmm2
  __m128 v74; // xmm4
  __m128i v75; // xmm2
  unsigned __int64 v76; // rdx
  _QWORD *v77; // r8
  _QWORD *v78; // rcx
  unsigned __int64 v79; // rax
  signed __int64 v80; // rcx
  int v81; // eax
  hkpCdBody *v82; // rdx
  int v83; // edi
  int v84; // ecx
  hkLifoAllocator *v85; // rax
  int v86; // er15
  char *v87; // rcx
  int v88; // eax
  int v89; // eax
  int v90; // er12
  int v91; // ecx
  int v92; // er15
  hkLifoAllocator *v93; // rax
  hk1AxisSweep::AabbInt *v94; // rdi
  int v95; // edx
  char *v96; // rcx
  int v97; // er12
  hkLifoAllocator *v98; // rax
  unsigned __int64 v99; // rcx
  signed __int64 v100; // rcx
  hk1AxisSweep::AabbInt *v101; // rax
  signed __int64 v102; // rcx
  signed __int64 v103; // rcx
  hk1AxisSweep::AabbInt *v104; // rax
  signed __int64 v105; // rcx
  _QWORD *v106; // r8
  _QWORD *v107; // rcx
  unsigned __int64 v108; // rax
  signed __int64 v109; // rcx
  int v110; // er9
  hk1AxisSweep::AabbInt *v111; // r8
  int v112; // edx
  hk1AxisSweep::AabbInt *v113; // rcx
  signed int v114; // ebx
  signed int v115; // er15
  hkLifoAllocator *v116; // rax
  int v117; // er8
  hkLifoAllocator *v118; // rax
  int v119; // er8
  _QWORD *v120; // r8
  _QWORD *v121; // rcx
  unsigned __int64 v122; // rax
  signed __int64 v123; // rcx
  _QWORD *v124; // rax
  unsigned __int64 v125; // rcx
  signed __int64 v126; // rcx
  _QWORD *v127; // r8
  _QWORD *v128; // rcx
  unsigned __int64 v129; // rax
  signed __int64 v130; // rcx
  unsigned int v132; // [rsp+40h] [rbp-C0h]
  hkpCdBody *v133; // [rsp+48h] [rbp-B8h]
  hkpCdBody *cdBody; // [rsp+50h] [rbp-B0h]
  hkpShapeContainer *collection; // [rsp+58h] [rbp-A8h]
  unsigned int v136; // [rsp+68h] [rbp-98h]
  _DWORD *v137; // [rsp+70h] [rbp-90h]
  __m128 v138; // [rsp+80h] [rbp-80h]
  __m128 v139; // [rsp+90h] [rbp-70h]
  hkVector4f linearTimInfo; // [rsp+A0h] [rbp-60h]
  hkTransformf bTa; // [rsp+B0h] [rbp-50h]
  char buffer[512]; // [rsp+F0h] [rbp-10h]
  char v143[512]; // [rsp+2F0h] [rbp+1F0h]
  unsigned int hitListOut[2048]; // [rsp+4F0h] [rbp+3F0h]
  int aabbBufferSize_usedOnSpu; // [rsp+2570h] [rbp+2470h]
  hkpShapeContainer *v146; // [rsp+2580h] [rbp+2480h]
  hkKeyPair *pairsOut; // [rsp+2588h] [rbp+2488h]

  pairsOut = (hkKeyPair *)shapeKeyPairs;
  v146 = shapeContainerB;
  v4 = input;
  v5 = shapeContainerA;
  collection = shapeContainerA;
  v6 = shapeContainerB;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = v7[1];
  v9 = v7;
  if ( v8 < v7[3] )
  {
    *(_QWORD *)v8 = "LtCollColl3";
    *(_QWORD *)(v8 + 16) = "StInit";
    v10 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v10;
    v9[1] = v8 + 24;
  }
  v11 = v4->m_bodyA.m_storage;
  v12 = v4->m_bodyB.m_storage;
  v13 = v4->m_input.m_storage->m_dispatcher.m_storage;
  v14 = ~(unsigned __int8)(v13->m_hasAlternateType[(unsigned __int8)v4->m_bodyA.m_storage->m_shape->m_type.m_storage] >> 22) & 1;
  v15 = ~(unsigned __int8)(v13->m_hasAlternateType[(unsigned __int8)v12->m_shape->m_type.m_storage] >> 22) & 1;
  if ( v14 | v15 )
  {
    v16 = ~(unsigned __int8)(v13->m_hasAlternateType[(unsigned __int8)v4->m_bodyA.m_storage->m_shape->m_type.m_storage] >> 22) & 1;
  }
  else
  {
    v16 = !v11->m_parent && v11[2].m_parent;
    v17 = !v12->m_parent && v12[2].m_parent;
    if ( v16 == v17 )
    {
      v18 = hkBvTreeAgent3::getShapeCollectionIfBvTreeSupportsAabbQueries(v11, (char (*)[512])buffer);
      v19 = hkBvTreeAgent3::getShapeCollectionIfBvTreeSupportsAabbQueries(v4->m_bodyB.m_storage, (char (*)[512])v143);
      v20 = v19;
      if ( v18 )
        v16 = v18->m_type.m_storage == 8;
      else
        v16 = 0;
      if ( v19 )
        LOBYTE(v19) = v19->m_type.m_storage == 8;
      if ( v16 && (_BYTE)v19 )
      {
        v16 = *(_DWORD *)&v18[1].m_memSizeAndFlags - *(unsigned __int16 *)&v18[1].m_bitsPerKey <= *(_DWORD *)&v20[1].m_memSizeAndFlags
                                                                                                - *(unsigned __int16 *)&v20[1].m_bitsPerKey;
      }
      else if ( !(v16 | (unsigned __int8)v19) )
      {
        v16 = *((float *)v4->m_bodyA.m_storage->m_motion + 40) <= *((float *)v4->m_bodyB.m_storage->m_motion + 40);
      }
      v6 = v146;
    }
  }
  if ( v15 & v14 )
  {
    v81 = v5->vfptr->getNumChildShapes(v5);
    v82 = v4->m_bodyA.m_storage;
    v83 = v81;
    if ( !v4->m_bodyA.m_storage->m_parent && v82[2].m_parent && LODWORD(v82[1].m_motion) <= LODWORD(v82[2].m_shape) )
    {
      v84 = LOWORD(v82[2].m_motion);
      if ( v81 > v84 )
        v84 = v81;
      v83 = v84;
    }
    v85 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v86 = 32 * (v83 + 4);
    v34 = (hk1AxisSweep::AabbInt *)v85->m_cur;
    v35 = (v86 + 127) & 0xFFFFFF80;
    v87 = (char *)v34 + v35;
    if ( v35 > v85->m_slabSize || v87 > v85->m_end )
      v34 = (hk1AxisSweep::AabbInt *)hkLifoAllocator::allocateFromNewSlab(v85, v35);
    else
      v85->m_cur = v87;
    v88 = hkCollectionBvTreeAgent3_extractCachedAabbsOrRecalculate(
            v4->m_bodyA.m_storage,
            v4->m_overrideBodyA.m_storage,
            v5,
            v4->m_input.m_storage,
            v34,
            v83,
            v86);
    v26 = v4->m_bodyB.m_storage;
    v5 = v146;
    v27 = v88;
    v133 = v4->m_bodyA.m_storage;
    cdBody = v4->m_bodyB.m_storage;
    collection = v146;
  }
  else
  {
    v21 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v22 = (_QWORD *)v21[1];
    if ( (unsigned __int64)v22 < v21[3] )
    {
      *v22 = "StQueryTree";
      v23 = __rdtsc();
      v24 = (signed __int64)(v22 + 2);
      *(_DWORD *)(v24 - 8) = v23;
      v21[1] = v24;
    }
    if ( v16 )
    {
      hkTransformf::setInverse(&bTa, &v4->m_aTb);
      v25 = hkBvTreeAgent3::calcAabbAndQueryTree(
              v4->m_bodyA.m_storage,
              v4->m_bodyB.m_storage,
              &bTa,
              &v4->m_linearTimInfo,
              v4->m_input.m_storage,
              0i64,
              hitListOut,
              2048);
      v26 = v4->m_bodyA.m_storage;
      v27 = v25;
      v28 = v4->m_bodyB.m_storage;
    }
    else
    {
      v29 = v4->m_bodyA.m_storage;
      v30 = v4->m_bodyB.m_storage;
      v31 = v4->m_input.m_storage;
      linearTimInfo.m_quad = _mm_xor_ps(
                               (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
                               v4->m_linearTimInfo.m_quad);
      v32 = hkBvTreeAgent3::calcAabbAndQueryTree(v30, v29, &v4->m_aTb, &linearTimInfo, v31, 0i64, hitListOut, 2048);
      v26 = v4->m_bodyB.m_storage;
      v6 = v5;
      v5 = v146;
      v27 = v32;
      v28 = v4->m_bodyA.m_storage;
      collection = v146;
    }
    cdBody = v26;
    v133 = v28;
    v33 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v34 = (hk1AxisSweep::AabbInt *)v33->m_cur;
    v35 = (32 * (v27 + 4) + 127) & 0xFFFFFF80;
    v36 = (char *)v34 + v35;
    if ( v35 > v33->m_slabSize || v36 > v33->m_end )
      v34 = (hk1AxisSweep::AabbInt *)hkLifoAllocator::allocateFromNewSlab(v33, v35);
    else
      v33->m_cur = v36;
    v37 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v38 = (_QWORD *)v37[1];
    if ( (unsigned __int64)v38 < v37[3] )
    {
      *v38 = "StCalcAABBs";
      v39 = __rdtsc();
      v40 = (signed __int64)(v38 + 2);
      *(_DWORD *)(v40 - 8) = v39;
      v37[1] = v40;
    }
    v132 = v4->m_input.m_storage->m_collisionQualityInfo.m_storage->m_useContinuousPhysics.m_storage;
    if ( v132 )
    {
      v41 = v133;
      for ( i = v133->m_parent; i; i = i->m_parent )
        v41 = i;
      hkAabbUtil::initOffsetAabbInput((hkMotionState *)v41->m_motion, (hkAabbUtil::OffsetAabbInput *)buffer);
    }
    aabbBufferSize_usedOnSpu = 0;
    if ( v27 > 0 )
    {
      v43 = 0i64;
      v137 = v34->m_expansionMin;
      do
      {
        v136 = hitListOut[v43];
        v44 = (_QWORD *)v6->vfptr->getChildShape(v6, v136, (char (*)[512])v143);
        v45 = LODWORD(v4->m_input.m_storage->m_tolerance.m_storage);
        (*(void (__fastcall **)(_QWORD *, const void *, _QWORD, __m128 *))(*v44 + 32i64))(
          v44,
          v133->m_motion,
          *v44,
          &v138);
        if ( v132 )
        {
          v46 = *(signed int *)&buffer[272];
          v47 = *(__m128 *)(*(_QWORD *)buffer + 128i64);
          v48 = _mm_mul_ps(_mm_sub_ps(v139, v138), (__m128)xmmword_141A711B0);
          v49 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v138, v139), (__m128)xmmword_141A711B0), v139);
          v50 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v49, v49, 85), *(__m128 *)&buffer[368]),
                      _mm_mul_ps(_mm_shuffle_ps(v49, v49, 0), *(__m128 *)&buffer[352])),
                    _mm_mul_ps(_mm_shuffle_ps(v49, v49, 170), *(__m128 *)&buffer[384])),
                  *(__m128 *)&buffer[400]);
          v51 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), *(__m128 *)&buffer[304]),
                      _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), *(__m128 *)&buffer[288])),
                    _mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), *(__m128 *)&buffer[320])),
                  *(__m128 *)&buffer[336]);
          v52 = _mm_min_ps(v49, v51);
          v53 = _mm_max_ps(v49, v51);
          if ( *(signed int *)&buffer[272] > 0i64 )
          {
            v54 = _mm_sub_ps(v50, v47);
            v55 = &buffer[48];
            do
            {
              v56 = *((__m128 *)v55 + 1);
              v55 += 64;
              v57 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v56, v56, 255), v54), v47);
              v58 = _mm_add_ps(
                      _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v57, v57, 85), *((__m128 *)v55 - 5)),
                          _mm_mul_ps(_mm_shuffle_ps(v57, v57, 0), *((__m128 *)v55 - 6))),
                        _mm_mul_ps(_mm_shuffle_ps(v57, v57, 170), *((__m128 *)v55 - 4))),
                      v56);
              v52 = _mm_min_ps(v52, v58);
              v53 = _mm_max_ps(v53, v58);
              --v46;
            }
            while ( v46 );
          }
          v59 = _mm_mul_ps(v48, v48);
          v60 = _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v59, v59, 85), _mm_shuffle_ps(v59, v59, 0)),
                  _mm_shuffle_ps(v59, v59, 170));
          v61 = _mm_rsqrt_ps(v60);
          v62 = _mm_andnot_ps(
                  _mm_cmpleps(v60, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_mul_ps(
                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v61, v60), v61)),
                      _mm_mul_ps(*(__m128 *)_xmm, v61)),
                    v60));
          v63 = _mm_min_ps(
                  v62,
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_min_ps(
                        _mm_shuffle_ps(
                          *(__m128 *)(*(_QWORD *)buffer + 144i64),
                          *(__m128 *)(*(_QWORD *)buffer + 144i64),
                          255),
                        _mm_mul_ps(_mm_shuffle_ps((__m128)0x3F3B67AFu, (__m128)0x3F3B67AFu, 0), v62)),
                      v62),
                    v48));
          v64 = _mm_sub_ps(v52, v63);
          v65 = _mm_add_ps(v53, v63);
          v66 = _mm_min_ps(v64, v64);
          v67 = _mm_max_ps(v65, v65);
          v138 = v66;
          v139 = v67;
        }
        else
        {
          v67 = v139;
          v66 = v138;
        }
        v68 = v4->m_input.m_storage;
        v69 = hkAabbUtil::hkAabbUint32MaxVal;
        ++v43;
        v70 = v68->m_aabb32Info.m_bitOffsetLow.m_quad;
        v71 = aabbBufferSize_usedOnSpu++;
        v72 = _mm_max_ps(
                _mm_min_ps(
                  _mm_mul_ps(_mm_add_ps(v70, v66), v68->m_aabb32Info.m_bitScale.m_quad),
                  hkAabbUtil::hkAabbUint32MaxVal),
                (__m128)0i64);
        v73 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v72);
        _mm_store_si128(
          (__m128i *)&v34[v71],
          _mm_or_si128(
            _mm_add_epi32(
              _mm_cvttps_epi32(
                _mm_max_ps(
                  _mm_sub_ps(v72, _mm_and_ps((__m128)v73, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                  (__m128)0i64)),
              _mm_slli_epi32(v73, 0x1Fu)),
            (__m128i)_mm_cmpleps(
                       _mm_add_ps(
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                       v72)));
        v74 = _mm_max_ps(
                _mm_min_ps(
                  _mm_mul_ps(
                    _mm_add_ps(v68->m_aabb32Info.m_bitOffsetHigh.m_quad, v67),
                    v68->m_aabb32Info.m_bitScale.m_quad),
                  v69),
                (__m128)0i64);
        v75 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v74);
        _mm_store_si128(
          (__m128i *)v34[v71].m_max,
          _mm_or_si128(
            _mm_add_epi32(
              _mm_cvttps_epi32(
                _mm_max_ps(
                  _mm_sub_ps(v74, _mm_and_ps((__m128)v75, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                  (__m128)0i64)),
              _mm_slli_epi32(v75, 0x1Fu)),
            (__m128i)_mm_cmpleps(
                       _mm_add_ps(
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                       v74)));
        *v137 = v136;
        v137 += 8;
      }
      while ( v43 < v27 );
      v5 = collection;
      v26 = cdBody;
    }
    v77 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v78 = (_QWORD *)v77[1];
    if ( (unsigned __int64)v78 < v77[3] )
    {
      *v78 = "StSortAABBs";
      v79 = __rdtsc();
      v76 = (unsigned __int64)HIDWORD(v79) << 32;
      v80 = (signed __int64)(v78 + 2);
      *(_DWORD *)(v80 - 8) = v79;
      v77[1] = v80;
    }
    if ( v27 > 1 )
      hkAlgorithm::quickSortRecursive<hk1AxisSweep::AabbInt,hkAlgorithm::less<hk1AxisSweep::AabbInt>>(
        v34,
        0,
        v27 - 1,
        0);
  }
  if ( v27 )
  {
    v89 = ((__int64 (__fastcall *)(hkpShapeContainer *, unsigned __int64, LPVOID))v5->vfptr->getNumChildShapes)(
            v5,
            v76,
            v77);
    v90 = v89;
    if ( !v26->m_parent && v26[2].m_parent && LODWORD(v26[1].m_motion) <= LODWORD(v26[2].m_shape) )
    {
      v91 = LOWORD(v26[2].m_motion);
      if ( v89 > v91 )
        v91 = v89;
      v90 = v91;
    }
    v92 = v90 + 4;
    v93 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v94 = (hk1AxisSweep::AabbInt *)v93->m_cur;
    aabbBufferSize_usedOnSpu = 32 * (v90 + 4);
    v95 = (32 * (v90 + 4) + 127) & 0xFFFFFF80;
    v96 = (char *)v94 + v95;
    if ( v95 > v93->m_slabSize || v96 > v93->m_end )
      v94 = (hk1AxisSweep::AabbInt *)hkLifoAllocator::allocateFromNewSlab(v93, v95);
    else
      v93->m_cur = v96;
    v97 = hkCollectionBvTreeAgent3_extractCachedAabbsOrRecalculate(
            cdBody,
            0i64,
            collection,
            v4->m_input.m_storage,
            v94,
            v90,
            aabbBufferSize_usedOnSpu);
  }
  else
  {
    v97 = 0;
    v92 = 4;
    v98 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v94 = (hk1AxisSweep::AabbInt *)v98->m_cur;
    v99 = (unsigned __int64)&v94[4];
    if ( v98->m_slabSize < 128 || (void *)v99 > v98->m_end )
      v94 = (hk1AxisSweep::AabbInt *)hkLifoAllocator::allocateFromNewSlab(v98, 128);
    else
      v98->m_cur = (void *)v99;
  }
  v100 = v27 + 4;
  if ( v27 < v100 )
  {
    v101 = &v34[v27];
    v102 = v100 - v27;
    do
    {
      v101->m_min[0] = -1;
      ++v101;
      --v102;
    }
    while ( v102 );
  }
  v103 = v97 + 4;
  if ( v97 < v103 )
  {
    v104 = &v94[v97];
    v105 = v103 - v97;
    do
    {
      v104->m_min[0] = -1;
      ++v104;
      --v105;
    }
    while ( v105 );
  }
  v106 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v107 = (_QWORD *)v106[1];
  if ( (unsigned __int64)v107 < v106[3] )
  {
    *v107 = "St1-Axis";
    v108 = __rdtsc();
    v109 = (signed __int64)(v107 + 2);
    *(_DWORD *)(v109 - 8) = v108;
    v106[1] = v109;
  }
  aabbBufferSize_usedOnSpu = 0;
  if ( v133 == v4->m_bodyA.m_storage )
  {
    v110 = v97;
    v111 = v94;
    v112 = v27;
    v113 = v34;
  }
  else
  {
    v110 = v27;
    v111 = v34;
    v112 = v97;
    v113 = v94;
  }
  v114 = hk1AxisSweep::collide(v113, v112, v111, v110, pairsOut, 2047, (hkPadSpu<int> *)&aabbBufferSize_usedOnSpu);
  v115 = (32 * v92 + 127) & 0xFFFFFF80;
  v116 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v117 = (v115 + 15) & 0xFFFFFFF0;
  if ( v115 > v116->m_slabSize || (char *)v94 + v117 != v116->m_cur || v116->m_firstNonLifoEnd == v94 )
    hkLifoAllocator::slowBlockFree(v116, v94, v117);
  else
    v116->m_cur = v94;
  v118 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v119 = (v35 + 15) & 0xFFFFFFF0;
  if ( v35 > v118->m_slabSize || (char *)v34 + v119 != v118->m_cur || v118->m_firstNonLifoEnd == v34 )
    hkLifoAllocator::slowBlockFree(v118, v34, v119);
  else
    v118->m_cur = v34;
  if ( v114 )
  {
    v120 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v121 = (_QWORD *)v120[1];
    if ( (unsigned __int64)v121 < v120[3] )
    {
      *v121 = "StSortKeyPairs";
      v122 = __rdtsc();
      v123 = (signed __int64)(v121 + 2);
      *(_DWORD *)(v123 - 8) = v122;
      v120[1] = v123;
    }
    v124 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v125 = v124[1];
    if ( v125 < v124[3] )
    {
      v126 = v125 + 16;
      *(_QWORD *)(v126 - 16) = "MiNumKeyPairs";
      *(float *)(v126 - 8) = (float)v114;
      v124[1] = v126;
    }
    if ( v114 > 1 )
      hkAlgorithm::quickSortRecursive<hkpShapeKeyPair,hkAlgorithm::less<hkpShapeKeyPair>>(
        (hkpShapeKeyPair *)pairsOut,
        0,
        v114 - 1,
        0);
  }
  pairsOut[v114] = (hkKeyPair)-1i64;
  v127 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v128 = (_QWORD *)v127[1];
  if ( (unsigned __int64)v128 < v127[3] )
  {
    *v128 = "lt";
    v129 = __rdtsc();
    v130 = (signed __int64)(v128 + 2);
    *(_DWORD *)(v130 - 8) = v129;
    v127[1] = v130;
  }
  return (unsigned int)v114;
}

// File Line: 580
// RVA: 0xD2E200
signed __int64 __fastcall hkpCollectionCollectionAgent3::process(hkpAgent3ProcessInput *input, hkpAgentEntry *entry, void *agentData, hkVector4f *separatingNormal, hkpProcessCollisionOutput *output)
{
  hkpAgent3ProcessInput *v5; // r14
  char *v6; // r13
  _QWORD *v7; // rbx
  unsigned __int64 v8; // r9
  unsigned __int64 v9; // rax
  hkpShapeContainer *v10; // rsi
  hkpShapeContainer *v11; // r12
  hkLifoAllocator *v12; // rax
  hkpShapeKeyPair *newKeys; // rdi
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rax
  int v17; // eax
  __int64 v18; // r15
  unsigned __int64 v19; // r8
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // rcx
  unsigned __int64 v22; // rax
  hkLifoAllocator *v23; // rax
  unsigned int *v24; // rsi
  int v25; // ebp
  char *v26; // rcx
  __int64 v27; // rdx
  unsigned int *v28; // r8
  unsigned int v29; // ecx
  __int128 v30; // xmm1
  unsigned __int64 v31; // rcx
  hkpCdBody *v32; // rax
  __int128 v33; // xmm0
  hkVector4f v34; // xmm1
  hkVector4f v35; // xmm0
  hkVector4f v36; // xmm1
  hkVector4f v37; // xmm0
  __int128 v38; // xmm1
  unsigned __int64 v39; // rax
  hkLifoAllocator *v40; // rax
  int v41; // er8
  hkLifoAllocator *v42; // rax
  unsigned __int64 v43; // rcx
  unsigned __int64 v44; // rax
  hkpAgent3ProcessInput inputIn; // [rsp+30h] [rbp-B8h]

  v5 = input;
  v6 = (char *)agentData;
  v7 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v8 = v7[1];
  if ( v8 < v7[3] )
  {
    *(_QWORD *)v8 = "LtProcessCollColl";
    *(_QWORD *)(v8 + 16) = "StInit";
    v9 = __rdtsc();
    *(_DWORD *)(v8 + 8) = v9;
    v7[1] = v8 + 24;
  }
  v10 = (hkpShapeContainer *)((__int64 (*)(void))v5->m_bodyA.m_storage->m_shape->vfptr[7].__vecDelDtor)();
  v11 = (hkpShapeContainer *)((__int64 (*)(void))v5->m_bodyB.m_storage->m_shape->vfptr[7].__vecDelDtor)();
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  newKeys = (hkpShapeKeyPair *)v12->m_cur;
  v14 = (unsigned __int64)&newKeys[2048];
  if ( v12->m_slabSize < 0x4000 || (void *)v14 > v12->m_end )
    newKeys = (hkpShapeKeyPair *)hkLifoAllocator::allocateFromNewSlab(v12, 0x4000);
  else
    v12->m_cur = (void *)v14;
  v15 = v7[1];
  if ( v15 < v7[3] )
  {
    *(_QWORD *)v15 = "Stquery";
    v16 = __rdtsc();
    *(_DWORD *)(v15 + 8) = v16;
    v7[1] = v15 + 16;
  }
  v17 = hkpCollectionCollectionAgent3::process_gatherShapeKeys(v5, v10, v11, newKeys);
  v18 = v17;
  if ( v17 >= 0 )
  {
    if ( v5->m_overrideBodyA.m_storage )
    {
      v21 = v7[1];
      if ( v21 < v7[3] )
      {
        *(_QWORD *)v21 = "Stshrink";
        v22 = __rdtsc();
        *(_DWORD *)(v21 + 8) = v22;
        v7[1] = v21 + 16;
      }
      v23 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v24 = (unsigned int *)v23->m_cur;
      v25 = (4 * v18 + 131) & 0xFFFFFF80;
      v26 = (char *)v24 + v25;
      if ( v25 > v23->m_slabSize || v26 > v23->m_end )
        v24 = (unsigned int *)hkLifoAllocator::allocateFromNewSlab(v23, v25);
      else
        v23->m_cur = v26;
      v27 = 0i64;
      if ( (signed int)v18 >= 0 )
      {
        v28 = &newKeys->m_shapeKeyB;
        do
        {
          v29 = *v28;
          ++v27;
          v28 += 2;
          v24[v27 - 1] = v29;
        }
        while ( v27 <= v18 );
      }
      v30 = *(_OWORD *)&v5->m_overrideBodyA.m_storage;
      v31 = v7[1];
      v32 = v5->m_overrideBodyA.m_storage;
      *(_OWORD *)&inputIn.m_bodyA.m_storage = *(_OWORD *)&v5->m_bodyA.m_storage;
      v33 = *(_OWORD *)&v5->m_contactMgr.m_storage;
      *(_OWORD *)&inputIn.m_overrideBodyA.m_storage = v30;
      inputIn.m_bodyA.m_storage = v32;
      inputIn.m_overrideBodyA.m_storage = 0i64;
      v34.m_quad = (__m128)v5->m_aTb.m_rotation.m_col0;
      *(_OWORD *)&inputIn.m_contactMgr.m_storage = v33;
      inputIn.m_aTb.m_rotation.m_col1 = v5->m_aTb.m_rotation.m_col1;
      v35.m_quad = (__m128)v5->m_aTb.m_translation;
      inputIn.m_aTb.m_rotation.m_col0 = (hkVector4f)v34.m_quad;
      v36.m_quad = (__m128)v5->m_aTb.m_rotation.m_col2;
      inputIn.m_aTb.m_translation = (hkVector4f)v35.m_quad;
      v37.m_quad = (__m128)v5->m_linearTimInfo;
      inputIn.m_aTb.m_rotation.m_col2 = (hkVector4f)v36.m_quad;
      v38 = *(_OWORD *)&v5->m_distAtT1.m_storage;
      inputIn.m_linearTimInfo = (hkVector4f)v37.m_quad;
      *(_OWORD *)&inputIn.m_distAtT1.m_storage = v38;
      if ( v31 < v7[3] )
      {
        *(_QWORD *)v31 = "Stprocess";
        v39 = __rdtsc();
        *(_DWORD *)(v31 + 8) = v39;
        v7[1] = v31 + 16;
      }
      hkAgent1nMachine_Process((hkpAgent1nTrack *)(v6 + 8), &inputIn, v11, v24, output);
      v40 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v41 = (v25 + 15) & 0xFFFFFFF0;
      if ( v25 > v40->m_slabSize || (char *)v24 + v41 != v40->m_cur || v40->m_firstNonLifoEnd == v24 )
        hkLifoAllocator::slowBlockFree(v40, v24, v41);
      else
        v40->m_cur = v24;
    }
    else
    {
      v19 = v7[1];
      if ( v19 < v7[3] )
      {
        *(_QWORD *)v19 = "Stprocess";
        v20 = __rdtsc();
        *(_DWORD *)(v19 + 8) = v20;
        v7[1] = v19 + 16;
      }
      hkAgentNmMachine_Process((hkpAgent1nTrack *)(v6 + 8), v5, v10, v11, newKeys, output);
    }
  }
  v42 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v42->m_slabSize < 0x4000 || &newKeys[2048] != v42->m_cur || v42->m_firstNonLifoEnd == newKeys )
    hkLifoAllocator::slowBlockFree(v42, newKeys, 0x4000);
  else
    v42->m_cur = newKeys;
  v43 = v7[1];
  if ( v43 < v7[3] )
  {
    *(_QWORD *)v43 = "lt";
    v44 = __rdtsc();
    *(_DWORD *)(v43 + 8) = v44;
    v7[1] = v43 + 16;
  }
  return (signed __int64)(v6 + 32);
}

// File Line: 671
// RVA: 0xD2E6B0
void __fastcall hkpCollectionCollectionAgent3::updateFilter(hkpAgentEntry *entry, void *agentData, hkpCdBody *bodyA, hkpCdBody *bodyB, hkpCollisionInput *input, hkpContactMgr *mgr, hkpConstraintOwner *constraintOwner)
{
  hkpShape *v7; // rcx
  hkpShape *v8; // rbx
  char *v9; // rdi
  hkpAgent1nMachine_VisitorInput vin; // [rsp+20h] [rbp-48h]

  v7 = bodyA->m_shape;
  v8 = bodyB->m_shape;
  vin.m_input = input;
  vin.m_bodyA = bodyA;
  vin.m_contactMgr = mgr;
  vin.m_collectionBodyB = bodyB;
  vin.m_constraintOwner = constraintOwner;
  v9 = (char *)agentData;
  vin.m_containerShapeA = (hkpShapeContainer *)((__int64 (__cdecl *)(hkpShape *, void *))v7->vfptr[7].__vecDelDtor)(
                                                 v7,
                                                 agentData);
  vin.m_containerShapeB = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))v8->vfptr[7].__vecDelDtor)(v8);
  hkAgentNmMachine_UpdateShapeCollectionFilter((hkpAgent1nTrack *)(v9 + 8), &vin);
}

// File Line: 691
// RVA: 0xD2E730
void __fastcall hkpCollectionCollectionAgent3::invalidateTim(hkpAgentEntry *entry, void *agentData, hkpCollisionInput *input)
{
  hkAgent1nMachine_InvalidateTim((hkpAgent1nTrack *)((char *)agentData + 8), input);
}

// File Line: 698
// RVA: 0xD2E750
void __fastcall hkpCollectionCollectionAgent3::warpTime(hkpAgentEntry *entry, void *agentData, float oldTime, float newTime, hkpCollisionInput *input)
{
  hkAgent1nMachine_WarpTime((hkpAgent1nTrack *)((char *)agentData + 8), oldTime, newTime, input);
}

