// File Line: 31
// RVA: 0xD7C3F0
void __fastcall hkpEntityAabbUtil::entityBatchRecalcAabb(
        hkpCollisionInput *collisionInput,
        hkpEntity *const *entityBatch,
        __int64 numEntities)
{
  hkpCollisionInput *v3; // rsi
  __int64 v4; // rax
  float v5; // xmm6_4
  __m128 v6; // xmm11
  __m128i v7; // xmm10
  __m128i si128; // xmm12
  __m128i v9; // xmm13
  __m128i v10; // xmm14
  hkpEntity *v11; // r13
  hkpShape *m_shape; // rcx
  __int64 v13; // rsi
  unsigned int v14; // eax
  __int64 v15; // rbx
  hkLifoAllocator *Value; // rax
  char *m_cur; // rdi
  int v18; // r15d
  char *v19; // rcx
  hkLifoAllocator *v20; // rax
  char *v21; // r14
  int v22; // ecx
  char *v23; // rdx
  __m128 v24; // xmm13
  __m128 v25; // xmm7
  __m128 v26; // xmm12
  __m128 v27; // xmm15
  unsigned int v28; // r12d
  __m128 v29; // xmm9
  __m128 *v30; // rbx
  unsigned int *v31; // r14
  char *v32; // rdi
  __m128 v33; // xmm14
  _QWORD *v34; // rax
  __int64 v35; // rcx
  __m128 v36; // xmm10
  __m128 v37; // xmm7
  __m128 v38; // xmm8
  __m128 v39; // xmm5
  __m128 v40; // xmm4
  __m128 v41; // xmm2
  __m128 v42; // xmm6
  __m128 v43; // xmm5
  __m128 v44; // xmm4
  __m128 *p_input_56; // rax
  __m128 v46; // xmm3
  __m128 v47; // xmm1
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  __m128 v50; // xmm3
  __m128 v51; // xmm2
  __m128 v52; // xmm4
  __m128 v53; // xmm4
  __m128 v54; // xmm9
  __m128 v55; // xmm7
  __m128 v56; // xmm5
  __m128 v57; // xmm4
  __m128i v58; // xmm0
  __m128 v59; // xmm10
  __m128i v60; // xmm0
  __m128 v61; // xmm9
  __m128 v62; // xmm3
  __m128i v63; // xmm0
  __m128i v64; // xmm2
  __m128 v65; // xmm1
  __m128 v66; // xmm0
  __m128i v67; // xmm7
  __m128i v68; // xmm0
  __m128i v69; // xmm3
  __m128i v70; // xmm8
  __m128i v71; // xmm0
  __m128i v72; // xmm6
  __m128i v73; // xmm5
  __m128i v74; // xmm7
  __m128i v75; // xmm6
  __m128i v76; // xmm0
  __m128i v77; // xmm1
  int v78; // eax
  unsigned int v79; // eax
  __m128i v80; // xmm1
  __m128i v81; // xmm0
  __m128i v82; // xmm0
  __m128i v83; // xmm1
  unsigned int v84; // eax
  __m128 v85; // xmm7
  __m128i v86; // xmm7
  __m128i v87; // xmm7
  __m128 v88; // xmm6
  __m128i v89; // xmm6
  __m128i v90; // xmm6
  __m128 v91; // xmm1
  __m128 v92; // xmm5
  __m128 v93; // xmm0
  __m128 v94; // xmm12
  __m128 v95; // xmm15
  __m128 v96; // xmm7
  __m128 v97; // xmm4
  __m128i v98; // xmm0
  __m128 v99; // xmm12
  __m128i v100; // xmm0
  __m128 v101; // xmm3
  __m128 v102; // xmm7
  __m128 v103; // xmm3
  __m128i v104; // xmm0
  __m128i v105; // xmm8
  __m128 v106; // xmm15
  __m128i v107; // xmm3
  __m128i v108; // xmm0
  __m128i v109; // xmm6
  __m128i v110; // xmm7
  __m128i v111; // xmm6
  __m128i v112; // xmm0
  __m128i v113; // xmm1
  int v114; // eax
  unsigned int v115; // eax
  __m128i v116; // xmm1
  __m128i v117; // xmm0
  __m128i v118; // xmm0
  __m128i v119; // xmm1
  unsigned int v120; // eax
  __m128 v121; // xmm7
  __m128i v122; // xmm7
  __m128i v123; // xmm7
  __m128 v124; // xmm6
  __m128i v125; // xmm6
  __m128i v126; // xmm6
  hkLifoAllocator *v127; // rax
  hkValueIndexPair *v128; // rsi
  int v129; // r12d
  char *v130; // rcx
  hkValueIndexPair *v131; // rdx
  int v132; // ecx
  char *v133; // r8
  hkAabbUint32 *m_childShapeAabbs; // r11
  unsigned int *m_childShapeKeys; // r10
  unsigned int *p_m_index; // r9
  hkAabbUint32 *v137; // rcx
  __int64 v138; // r8
  char *v139; // rdx
  __int64 v140; // rax
  __int64 v141; // rax
  hkLifoAllocator *v142; // rax
  int v143; // r8d
  hkLifoAllocator *v144; // rax
  int v145; // r8d
  hkLifoAllocator *v146; // rax
  __m128 m_quad; // xmm2
  __m128 v148; // xmm0
  __m128 v149; // xmm1
  __m128 v150; // xmm5
  __m128 v151; // xmm6
  __m128 v152; // xmm9
  __m128 v153; // xmm7
  __m128 v154; // xmm9
  __m128 v155; // xmm4
  __m128 v156; // xmm1
  __m128 v157; // xmm7
  __m128 v158; // xmm9
  __m128i v159; // xmm0
  __m128 v160; // xmm6
  __m128i v161; // xmm0
  __m128 v162; // xmm3
  __m128 v163; // xmm7
  __m128i v164; // xmm0
  __m128 v165; // xmm9
  __m128i v166; // xmm8
  __m128i v167; // xmm0
  __m128i v168; // xmm6
  __m128i v169; // xmm7
  __m128i v170; // xmm6
  __m128i v171; // xmm0
  __m128i v172; // xmm1
  int v173; // eax
  unsigned int v174; // eax
  __m128i v175; // xmm1
  __m128i v176; // xmm0
  __m128i v177; // xmm0
  __m128i v178; // xmm1
  unsigned int v179; // eax
  __m128 v180; // xmm7
  __m128i v181; // xmm7
  __m128i v182; // xmm7
  __m128 v183; // xmm6
  __m128i v184; // xmm6
  __m128i v185; // xmm6
  int v186; // [rsp+20h] [rbp-C8h]
  unsigned int v187; // [rsp+2Ch] [rbp-BCh]
  char *v188; // [rsp+30h] [rbp-B8h]
  char *v189; // [rsp+38h] [rbp-B0h]
  char *v190; // [rsp+40h] [rbp-A8h]
  __int64 v191; // [rsp+48h] [rbp-A0h]
  __m128 v192; // [rsp+50h] [rbp-98h]
  __int64 v193; // [rsp+60h] [rbp-88h]
  _BYTE v194[48]; // [rsp+68h] [rbp-80h] BYREF
  __int64 input_56; // [rsp+A8h] [rbp-40h] BYREF
  int input_280; // [rsp+188h] [rbp+A0h]
  __m128 input_296; // [rsp+198h] [rbp+B0h]
  __m128 input_312; // [rsp+1A8h] [rbp+C0h]
  __m128 input_328; // [rsp+1B8h] [rbp+D0h]
  __m128 input_344; // [rsp+1C8h] [rbp+E0h]
  __m128 input_360; // [rsp+1D8h] [rbp+F0h]
  __m128 input_376; // [rsp+1E8h] [rbp+100h]
  __m128 input_392; // [rsp+1F8h] [rbp+110h]
  __m128 input_408; // [rsp+208h] [rbp+120h]
  char v205[536]; // [rsp+218h] [rbp+130h] BYREF
  __m128 *v206; // [rsp+508h] [rbp+420h]
  hkpEntity *const *vars0; // [rsp+510h] [rbp+428h]
  void *retaddr; // [rsp+518h] [rbp+430h]

  v3 = collisionInput;
  v4 = 0i64;
  v191 = 0i64;
  v193 = (int)numEntities;
  v5 = collisionInput->m_tolerance.m_storage * 0.5;
  *(float *)&retaddr = v5;
  if ( (int)numEntities > 0 )
  {
    v6 = 0i64;
    v7 = 0i64;
    si128 = _mm_load_si128((const __m128i *)&_xmm);
    v9 = _mm_load_si128((const __m128i *)&_xmm);
    v10 = _mm_load_si128((const __m128i *)&_xmm);
    do
    {
      v11 = entityBatch[v4];
      m_shape = v11->m_collidable.m_shape;
      if ( m_shape->m_type.m_storage == 16 || !v11->m_collidable.m_boundingVolumeData.m_capacityChildShapeAabbs )
      {
        ((void (__fastcall *)(hkpShape *, hkMotionState *, __int64, _BYTE *))m_shape->vfptr[2].__vecDelDtor)(
          m_shape,
          &v11->m_motion.m_motionState,
          numEntities,
          &v194[8]);
        m_quad = v11->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad;
        v148 = _mm_shuffle_ps(
                 (__m128)LODWORD(v11->m_motion.m_motionState.m_objectRadius),
                 (__m128)LODWORD(v11->m_motion.m_motionState.m_objectRadius),
                 0);
        v149 = _mm_add_ps(_mm_shuffle_ps((__m128)LODWORD(v5), (__m128)LODWORD(v5), 0), v148);
        v150 = hkAabbUtil::hkAabbUint32MaxVal;
        v151 = *(__m128 *)v194;
        v152 = _mm_mul_ps(
                 _mm_shuffle_ps(
                   v11->m_motion.m_motionState.m_deltaAngle.m_quad,
                   v11->m_motion.m_motionState.m_deltaAngle.m_quad,
                   255),
                 v148);
        v153 = _mm_max_ps(_mm_sub_ps(*(__m128 *)&v194[8], v152), _mm_sub_ps(m_quad, v149));
        v154 = _mm_min_ps(_mm_add_ps(v152, *(__m128 *)v194), _mm_add_ps(v149, m_quad));
        v155 = _mm_max_ps(
                 _mm_min_ps(
                   _mm_mul_ps(
                     _mm_add_ps(v3->m_aabb32Info.m_bitOffsetLow.m_quad, *(__m128 *)&v194[8]),
                     v3->m_aabb32Info.m_bitScale.m_quad),
                   hkAabbUtil::hkAabbUint32MaxVal),
                 v6);
        v156 = _mm_sub_ps(v11->m_motion.m_motionState.m_sweptTransform.m_centerOfMass0.m_quad, m_quad);
        v157 = _mm_add_ps(_mm_min_ps(v153, *(__m128 *)&v194[8]), _mm_min_ps(v6, v156));
        v158 = _mm_add_ps(_mm_max_ps(v154, *(__m128 *)v194), _mm_max_ps(v6, v156));
        v159 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v155);
        *(__m128i *)v11->m_collidable.m_boundingVolumeData.m_min = _mm_or_si128(
                                                                     _mm_add_epi32(
                                                                       _mm_cvttps_epi32(
                                                                         _mm_max_ps(
                                                                           _mm_sub_ps(
                                                                             v155,
                                                                             _mm_and_ps(
                                                                               (__m128)v159,
                                                                               *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                                                                           v6)),
                                                                       _mm_slli_epi32(v159, 0x1Fu)),
                                                                     (__m128i)_mm_cmple_ps(
                                                                                _mm_add_ps(
                                                                                  *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                                                                                  *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                                                                                v155));
        v160 = _mm_max_ps(
                 _mm_min_ps(
                   _mm_mul_ps(
                     _mm_add_ps(v151, v3->m_aabb32Info.m_bitOffsetHigh.m_quad),
                     v3->m_aabb32Info.m_bitScale.m_quad),
                   v150),
                 v6);
        v161 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v160);
        *(__m128i *)v11->m_collidable.m_boundingVolumeData.m_max = _mm_or_si128(
                                                                     _mm_add_epi32(
                                                                       _mm_cvttps_epi32(
                                                                         _mm_max_ps(
                                                                           _mm_sub_ps(
                                                                             v160,
                                                                             _mm_and_ps(
                                                                               (__m128)v161,
                                                                               *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                                                                           v6)),
                                                                       _mm_slli_epi32(v161, 0x1Fu)),
                                                                     (__m128i)_mm_cmple_ps(
                                                                                _mm_add_ps(
                                                                                  *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                                                                                  *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                                                                                v160));
        v162 = _mm_max_ps(
                 _mm_min_ps(
                   _mm_mul_ps(
                     _mm_add_ps(v3->m_aabb32Info.m_bitOffsetLow.m_quad, v157),
                     v3->m_aabb32Info.m_bitScale.m_quad),
                   hkAabbUtil::hkAabbUint32MaxVal),
                 v6);
        v163 = _mm_add_ps(
                 *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                 *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31);
        v164 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v162);
        v165 = _mm_max_ps(
                 _mm_min_ps(
                   _mm_mul_ps(
                     _mm_add_ps(v158, v3->m_aabb32Info.m_bitOffsetHigh.m_quad),
                     v3->m_aabb32Info.m_bitScale.m_quad),
                   hkAabbUtil::hkAabbUint32MaxVal),
                 v6);
        v166 = _mm_or_si128(
                 _mm_add_epi32(
                   _mm_cvttps_epi32(
                     _mm_max_ps(
                       _mm_sub_ps(
                         v162,
                         _mm_and_ps((__m128)v164, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                       v6)),
                   _mm_slli_epi32(v164, 0x1Fu)),
                 (__m128i)_mm_cmple_ps(v163, v162));
        v167 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v165);
        v168 = _mm_or_si128(
                 _mm_add_epi32(
                   _mm_cvttps_epi32(
                     _mm_max_ps(
                       _mm_sub_ps(
                         v165,
                         _mm_and_ps((__m128)v167, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                       v6)),
                   _mm_slli_epi32(v167, 0x1Fu)),
                 (__m128i)_mm_cmple_ps(v163, v165));
        v169 = _mm_sub_epi32(
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_min[0]),
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_min[2])),
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_min[1]),
                     _mm_cvtsi32_si128(0))),
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(v166)),
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v166, 8)))),
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v166, 4))),
                     _mm_cvtsi32_si128(0))));
        v170 = _mm_sub_epi32(
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(v168)),
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v168, 8)))),
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v168, 4))),
                     _mm_cvtsi32_si128(0))),
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_max[0]),
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_max[2])),
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_max[1]),
                     _mm_cvtsi32_si128(0))));
        v171 = _mm_or_si128(v170, v169);
        v172 = _mm_or_si128(_mm_shuffle_epi32(v171, 225), v171);
        v173 = _mm_cvtsi128_si32(_mm_or_si128(_mm_shuffle_epi32(v172, 78), v172));
        v174 = v173 | 0xFF | ((v173 | 0xFFu) >> 1) | ((v173 | 0xFF | ((v173 | 0xFFu) >> 1)) >> 2);
        v175 = _mm_cvtsi32_si128(v174 | (v174 >> 4) | ((v174 | (v174 >> 4)) >> 8) | ((v174 | (v174 >> 4) | ((v174 | (v174 >> 4)) >> 8)) >> 16));
        v176 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v175, 1u), v10), _mm_and_si128(v175, v10));
        v177 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v176, 2u), si128), _mm_and_si128(v176, si128));
        v178 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v177, 4u), v177), v9), v7);
        v179 = _mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v178, 78), v178)) - 8;
        v180 = (__m128)_mm_srli_epi32(v169, v179);
        v181 = (__m128i)_mm_shuffle_ps(
                          v180,
                          _mm_unpackhi_ps(v180, (__m128)_mm_shuffle_epi32(_mm_cvtsi32_si128(v179), 0)),
                          196);
        v182 = _mm_packs_epi32(v181, v181);
        v183 = (__m128)_mm_srli_epi32(v170, v179);
        *(_DWORD *)v11->m_collidable.m_boundingVolumeData.m_expansionMin = _mm_packus_epi16(v182, v182).m128i_u32[0];
        v184 = (__m128i)_mm_shuffle_ps(
                          v183,
                          _mm_unpackhi_ps(
                            v183,
                            (__m128)_mm_shuffle_epi32(
                                      _mm_cvtsi32_si128((unsigned __int8)v11->m_collidable.m_boundingVolumeData.m_padding),
                                      0)),
                          196);
        v185 = _mm_packs_epi32(v184, v184);
        *(_DWORD *)v11->m_collidable.m_boundingVolumeData.m_expansionMax = _mm_packus_epi16(v185, v185).m128i_u32[0];
      }
      else
      {
        v13 = ((__int64 (__fastcall *)(hkpShape *))m_shape->vfptr[7].__vecDelDtor)(m_shape);
        v14 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v13 + 8i64))(v13);
        v15 = v14;
        v187 = v14;
        Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (char *)Value->m_cur;
        v190 = m_cur;
        v18 = (32 * v15 + 127) & 0xFFFFFF80;
        v19 = &m_cur[v18];
        if ( v18 > Value->m_slabSize || v19 > Value->m_end )
        {
          m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v18);
          v190 = m_cur;
        }
        else
        {
          Value->m_cur = v19;
        }
        v20 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v21 = (char *)v20->m_cur;
        v22 = (4 * v15 + 127) & 0xFFFFFF80;
        v186 = v22;
        v189 = v21;
        v23 = &v21[v22];
        if ( v22 > v20->m_slabSize || v23 > v20->m_end )
        {
          v21 = (char *)hkLifoAllocator::allocateFromNewSlab(v20, v22);
          v189 = v21;
        }
        else
        {
          v20->m_cur = v23;
        }
        hkAabbUtil::initOffsetAabbInput(&v11->m_motion.m_motionState, (hkAabbUtil::OffsetAabbInput *)&v194[16]);
        v24 = (__m128)xmmword_141A712A0;
        v25 = (__m128)xmmword_141A712A0;
        v192 = (__m128)xmmword_141A712A0;
        v188 = v21;
        v26 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16(v7, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
        v27 = v26;
        v28 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v13 + 16i64))(v13);
        if ( v28 != -1 )
        {
          v29 = (__m128)_xmm;
          v30 = v206;
          v31 = (unsigned int *)(m_cur + 20);
          v32 = v188;
          v33 = _mm_shuffle_ps((__m128)0x3F3B67AFu, (__m128)0x3F3B67AFu, 0);
          do
          {
            v34 = (_QWORD *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v13 + 40i64))(
                              v13,
                              v28,
                              v205);
            (*(void (__fastcall **)(_QWORD *, hkMotionState *, _QWORD, _BYTE *))(*v34 + 32i64))(
              v34,
              &v11->m_motion.m_motionState,
              *v34,
              &v194[8]);
            v35 = input_280;
            v36 = *(__m128 *)v194;
            v37 = *(__m128 *)(*(_QWORD *)&v194[16] + 128i64);
            v38 = _mm_mul_ps(_mm_sub_ps(*(__m128 *)v194, *(__m128 *)&v194[8]), (__m128)xmmword_141A711B0);
            v39 = _mm_add_ps(
                    _mm_mul_ps(_mm_sub_ps(*(__m128 *)&v194[8], *(__m128 *)v194), (__m128)xmmword_141A711B0),
                    *(__m128 *)v194);
            v40 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v39, v39, 85), input_376),
                        _mm_mul_ps(_mm_shuffle_ps(v39, v39, 0), input_360)),
                      _mm_mul_ps(_mm_shuffle_ps(v39, v39, 170), input_392)),
                    input_408);
            v41 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v40, v40, 85), input_312),
                        _mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), input_296)),
                      _mm_mul_ps(_mm_shuffle_ps(v40, v40, 170), input_328)),
                    input_344);
            v42 = _mm_min_ps(v39, v41);
            v43 = _mm_max_ps(v39, v41);
            if ( input_280 > 0 )
            {
              v44 = _mm_sub_ps(v40, v37);
              p_input_56 = (__m128 *)&input_56;
              do
              {
                v46 = p_input_56[1];
                p_input_56 += 4;
                v47 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v46, v46, 255), v44), v37);
                v48 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v47, v47, 85), p_input_56[-5]),
                            _mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), p_input_56[-6])),
                          _mm_mul_ps(_mm_shuffle_ps(v47, v47, 170), p_input_56[-4])),
                        v46);
                v42 = _mm_min_ps(v42, v48);
                v43 = _mm_max_ps(v43, v48);
                --v35;
              }
              while ( v35 );
            }
            v26 = _mm_max_ps(v26, *(__m128 *)v194);
            v24 = _mm_min_ps(v24, *(__m128 *)&v194[8]);
            v49 = _mm_mul_ps(v38, v38);
            v50 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
                    _mm_shuffle_ps(v49, v49, 170));
            v51 = _mm_rsqrt_ps(v50);
            v52 = _mm_andnot_ps(
                    _mm_cmple_ps(v50, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps(v29, _mm_mul_ps(_mm_mul_ps(v51, v50), v51)),
                        _mm_mul_ps(*(__m128 *)_xmm, v51)),
                      v50));
            v53 = _mm_min_ps(
                    v52,
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_min_ps(
                          _mm_shuffle_ps(
                            *(__m128 *)(*(_QWORD *)&v194[16] + 144i64),
                            *(__m128 *)(*(_QWORD *)&v194[16] + 144i64),
                            255),
                          _mm_mul_ps(v33, v52)),
                        v52),
                      v38));
            v54 = _mm_max_ps(*(__m128 *)v194, _mm_add_ps(v43, v53));
            v55 = _mm_min_ps(*(__m128 *)&v194[8], _mm_sub_ps(v42, v53));
            v56 = hkAabbUtil::hkAabbUint32MaxVal;
            v6 = 0i64;
            v27 = _mm_max_ps(v27, v54);
            v192 = _mm_min_ps(v192, v55);
            v57 = _mm_max_ps(
                    _mm_min_ps(
                      _mm_mul_ps(_mm_add_ps(v30[3], *(__m128 *)&v194[8]), v30[5]),
                      hkAabbUtil::hkAabbUint32MaxVal),
                    (__m128)0i64);
            v58 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v57);
            *(__m128i *)(v31 - 5) = _mm_or_si128(
                                      _mm_add_epi32(
                                        _mm_cvttps_epi32(
                                          _mm_max_ps(
                                            _mm_sub_ps(
                                              v57,
                                              _mm_and_ps(
                                                (__m128)v58,
                                                *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                                            (__m128)0i64)),
                                        _mm_slli_epi32(v58, 0x1Fu)),
                                      (__m128i)_mm_cmple_ps(
                                                 _mm_add_ps(
                                                   *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                                                   *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                                                 v57));
            v59 = _mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(v36, v30[4]), v30[5]), v56), (__m128)0i64);
            v60 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v59);
            *(__m128i *)(v31 - 1) = _mm_or_si128(
                                      _mm_add_epi32(
                                        _mm_cvttps_epi32(
                                          _mm_max_ps(
                                            _mm_sub_ps(
                                              v59,
                                              _mm_and_ps(
                                                (__m128)v60,
                                                *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                                            (__m128)0i64)),
                                        _mm_slli_epi32(v60, 0x1Fu)),
                                      (__m128i)_mm_cmple_ps(
                                                 _mm_add_ps(
                                                   *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                                                   *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                                                 v59));
            v61 = _mm_max_ps(
                    _mm_min_ps(_mm_mul_ps(_mm_add_ps(v54, v30[4]), v30[5]), hkAabbUtil::hkAabbUint32MaxVal),
                    (__m128)0i64);
            v62 = _mm_max_ps(
                    _mm_min_ps(_mm_mul_ps(_mm_add_ps(v30[3], v55), v30[5]), hkAabbUtil::hkAabbUint32MaxVal),
                    (__m128)0i64);
            v63 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v62);
            v64 = _mm_slli_epi32(v63, 0x1Fu);
            v65 = _mm_sub_ps(v62, _mm_and_ps((__m128)v63, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31));
            v66 = _mm_add_ps(
                    *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                    *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31);
            v67 = (__m128i)_mm_cmple_ps(v66, v61);
            v68 = (__m128i)_mm_cmple_ps(v66, v62);
            v69 = _mm_cvtsi32_si128(0);
            v70 = _mm_or_si128(_mm_add_epi32(_mm_cvttps_epi32(_mm_max_ps(v65, (__m128)0i64)), v64), v68);
            v71 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v61);
            v72 = _mm_or_si128(
                    _mm_add_epi32(
                      _mm_cvttps_epi32(
                        _mm_max_ps(
                          _mm_sub_ps(
                            v61,
                            _mm_and_ps((__m128)v71, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                          (__m128)0i64)),
                      _mm_slli_epi32(v71, 0x1Fu)),
                    v67);
            v73 = _mm_unpacklo_epi32(
                    _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v31 - 1)), _mm_cvtsi32_si128(v31[1])),
                    _mm_unpacklo_epi32(_mm_cvtsi32_si128(*v31), v69));
            v74 = _mm_sub_epi32(
                    _mm_unpacklo_epi32(
                      _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v31 - 5)), _mm_cvtsi32_si128(*(v31 - 3))),
                      _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v31 - 4)), v69)),
                    _mm_unpacklo_epi32(
                      _mm_unpacklo_epi32(
                        _mm_cvtsi32_si128(_mm_cvtsi128_si32(v70)),
                        _mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v70, 8)))),
                      _mm_unpacklo_epi32(_mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v70, 4))), v69)));
            v7 = 0i64;
            v31 += 8;
            v32 += 4;
            v75 = _mm_sub_epi32(
                    _mm_unpacklo_epi32(
                      _mm_unpacklo_epi32(
                        _mm_cvtsi32_si128(_mm_cvtsi128_si32(v72)),
                        _mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v72, 8)))),
                      _mm_unpacklo_epi32(_mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v72, 4))), v69)),
                    v73);
            v76 = _mm_or_si128(v75, v74);
            v77 = _mm_or_si128(_mm_shuffle_epi32(v76, 225), v76);
            v78 = _mm_cvtsi128_si32(_mm_or_si128(_mm_shuffle_epi32(v77, 78), v77));
            v79 = v78 | 0xFF | ((v78 | 0xFFu) >> 1) | ((v78 | 0xFF | ((v78 | 0xFFu) >> 1)) >> 2);
            v80 = _mm_cvtsi32_si128(v79 | (v79 >> 4) | ((v79 | (v79 >> 4)) >> 8) | ((v79 | (v79 >> 4) | ((v79 | (v79 >> 4)) >> 8)) >> 16));
            v81 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v80, 1u), (__m128i)_xmm), _mm_and_si128(v80, (__m128i)_xmm));
            v82 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v81, 2u), (__m128i)_xmm), _mm_and_si128(v81, (__m128i)_xmm));
            v83 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v82, 4u), v82), (__m128i)_xmm), (__m128i)0i64);
            v84 = _mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v83, 78), v83)) - 8;
            v85 = (__m128)_mm_srli_epi32(v74, v84);
            v86 = (__m128i)_mm_shuffle_ps(
                             v85,
                             _mm_unpackhi_ps(v85, (__m128)_mm_shuffle_epi32(_mm_cvtsi32_si128(v84), 0)),
                             196);
            v87 = _mm_packs_epi32(v86, v86);
            v88 = (__m128)_mm_srli_epi32(v75, v84);
            *(v31 - 10) = _mm_packus_epi16(v87, v87).m128i_u32[0];
            v89 = (__m128i)_mm_shuffle_ps(
                             v88,
                             _mm_unpackhi_ps(
                               v88,
                               (__m128)_mm_shuffle_epi32(_mm_cvtsi32_si128(*((unsigned __int8 *)v31 - 21)), 0)),
                             196);
            v90 = _mm_packs_epi32(v89, v89);
            *(v31 - 6) = _mm_packus_epi16(v90, v90).m128i_u32[0];
            *((_BYTE *)v31 - 21) = v28;
            *((_DWORD *)v32 - 1) = v28;
            v28 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v13 + 24i64))(v13, v28);
            v29 = (__m128)_xmm;
          }
          while ( v28 != -1 );
          v25 = v192;
          v10 = _mm_load_si128((const __m128i *)&_xmm);
          v15 = v187;
          v21 = v189;
          v188 = v32;
          m_cur = v190;
        }
        v3 = (hkpCollisionInput *)v206;
        v91 = _mm_cmple_ps(v24, v26);
        v11->m_collidable.m_boundingVolumeData.m_numChildShapeAabbs = (v188 - v21) >> 2;
        v92 = hkAabbUtil::hkAabbUint32MaxVal;
        v93 = _mm_andnot_ps(v91, v11->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
        v94 = _mm_or_ps(_mm_and_ps(v26, v91), v93);
        v95 = _mm_or_ps(_mm_and_ps(v27, v91), v93);
        v96 = _mm_or_ps(_mm_and_ps(v25, v91), v93);
        v97 = _mm_max_ps(
                _mm_min_ps(
                  _mm_mul_ps(
                    _mm_add_ps(v3->m_aabb32Info.m_bitOffsetLow.m_quad, _mm_or_ps(_mm_and_ps(v24, v91), v93)),
                    v3->m_aabb32Info.m_bitScale.m_quad),
                  hkAabbUtil::hkAabbUint32MaxVal),
                v6);
        v98 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v97);
        *(__m128i *)v11->m_collidable.m_boundingVolumeData.m_min = _mm_or_si128(
                                                                     _mm_add_epi32(
                                                                       _mm_cvttps_epi32(
                                                                         _mm_max_ps(
                                                                           _mm_sub_ps(
                                                                             v97,
                                                                             _mm_and_ps(
                                                                               (__m128)v98,
                                                                               *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                                                                           v6)),
                                                                       _mm_slli_epi32(v98, 0x1Fu)),
                                                                     (__m128i)_mm_cmple_ps(
                                                                                _mm_add_ps(
                                                                                  *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                                                                                  *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                                                                                v97));
        v99 = _mm_max_ps(
                _mm_min_ps(
                  _mm_mul_ps(
                    _mm_add_ps(v94, v3->m_aabb32Info.m_bitOffsetHigh.m_quad),
                    v3->m_aabb32Info.m_bitScale.m_quad),
                  v92),
                v6);
        v100 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v99);
        *(__m128i *)v11->m_collidable.m_boundingVolumeData.m_max = _mm_or_si128(
                                                                     _mm_add_epi32(
                                                                       _mm_cvttps_epi32(
                                                                         _mm_max_ps(
                                                                           _mm_sub_ps(
                                                                             v99,
                                                                             _mm_and_ps(
                                                                               (__m128)v100,
                                                                               *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                                                                           v6)),
                                                                       _mm_slli_epi32(v100, 0x1Fu)),
                                                                     (__m128i)_mm_cmple_ps(
                                                                                _mm_add_ps(
                                                                                  *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                                                                                  *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                                                                                v99));
        v101 = _mm_mul_ps(_mm_add_ps(v3->m_aabb32Info.m_bitOffsetLow.m_quad, v96), v3->m_aabb32Info.m_bitScale.m_quad);
        v102 = _mm_add_ps(
                 *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                 *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31);
        v103 = _mm_max_ps(_mm_min_ps(v101, hkAabbUtil::hkAabbUint32MaxVal), v6);
        v104 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v103);
        v105 = _mm_or_si128(
                 _mm_add_epi32(
                   _mm_cvttps_epi32(
                     _mm_max_ps(
                       _mm_sub_ps(
                         v103,
                         _mm_and_ps((__m128)v104, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                       v6)),
                   _mm_slli_epi32(v104, 0x1Fu)),
                 (__m128i)_mm_cmple_ps(v102, v103));
        v106 = _mm_max_ps(
                 _mm_min_ps(
                   _mm_mul_ps(
                     _mm_add_ps(v95, v3->m_aabb32Info.m_bitOffsetHigh.m_quad),
                     v3->m_aabb32Info.m_bitScale.m_quad),
                   hkAabbUtil::hkAabbUint32MaxVal),
                 v6);
        v107 = _mm_cvtsi32_si128(0);
        v108 = (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v106);
        v109 = _mm_or_si128(
                 _mm_add_epi32(
                   _mm_cvttps_epi32(
                     _mm_max_ps(
                       _mm_sub_ps(
                         v106,
                         _mm_and_ps((__m128)v108, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                       v6)),
                   _mm_slli_epi32(v108, 0x1Fu)),
                 (__m128i)_mm_cmple_ps(v102, v106));
        v110 = _mm_sub_epi32(
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_min[0]),
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_min[2])),
                   _mm_unpacklo_epi32(_mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_min[1]), v107)),
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(v105)),
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v105, 8)))),
                   _mm_unpacklo_epi32(_mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v105, 4))), v107)));
        v111 = _mm_sub_epi32(
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(v109)),
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v109, 8)))),
                   _mm_unpacklo_epi32(_mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v109, 4))), v107)),
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_max[0]),
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_max[2])),
                   _mm_unpacklo_epi32(_mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_max[1]), v107)));
        v112 = _mm_or_si128(v111, v110);
        v113 = _mm_or_si128(_mm_shuffle_epi32(v112, 225), v112);
        v114 = _mm_cvtsi128_si32(_mm_or_si128(_mm_shuffle_epi32(v113, 78), v113));
        v115 = v114 | 0xFF | ((v114 | 0xFFu) >> 1) | ((v114 | 0xFF | ((v114 | 0xFFu) >> 1)) >> 2);
        si128 = _mm_load_si128((const __m128i *)&_xmm);
        v9 = _mm_load_si128((const __m128i *)&_xmm);
        v116 = _mm_cvtsi32_si128(v115 | (v115 >> 4) | ((v115 | (v115 >> 4)) >> 8) | ((v115 | (v115 >> 4) | ((v115 | (v115 >> 4)) >> 8)) >> 16));
        v117 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v116, 1u), v10), _mm_and_si128(v116, v10));
        v118 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v117, 2u), si128), _mm_and_si128(v117, si128));
        v119 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v118, 4u), v118), v9), v7);
        v120 = _mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v119, 78), v119)) - 8;
        v121 = (__m128)_mm_srli_epi32(v110, v120);
        v122 = (__m128i)_mm_shuffle_ps(
                          v121,
                          _mm_unpackhi_ps(v121, (__m128)_mm_shuffle_epi32(_mm_cvtsi32_si128(v120), 0)),
                          196);
        v123 = _mm_packs_epi32(v122, v122);
        v124 = (__m128)_mm_srli_epi32(v111, v120);
        *(_DWORD *)v11->m_collidable.m_boundingVolumeData.m_expansionMin = _mm_packus_epi16(v123, v123).m128i_u32[0];
        v125 = (__m128i)_mm_shuffle_ps(
                          v124,
                          _mm_unpackhi_ps(
                            v124,
                            (__m128)_mm_shuffle_epi32(
                                      _mm_cvtsi32_si128((unsigned __int8)v11->m_collidable.m_boundingVolumeData.m_padding),
                                      0)),
                          196);
        v126 = _mm_packs_epi32(v125, v125);
        *(_DWORD *)v11->m_collidable.m_boundingVolumeData.m_expansionMax = _mm_packus_epi16(v126, v126).m128i_u32[0];
        if ( (_DWORD)v15 )
        {
          v127 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v128 = (hkValueIndexPair *)v127->m_cur;
          v129 = (8 * v15 + 127) & 0xFFFFFF80;
          v130 = (char *)v128 + v129;
          if ( v129 > v127->m_slabSize || v130 > v127->m_end )
            v128 = (hkValueIndexPair *)hkLifoAllocator::allocateFromNewSlab(v127, v129);
          else
            v127->m_cur = v130;
          v131 = v128;
          if ( (int)v15 <= 1 )
          {
            if ( (_DWORD)v15 == 1 )
              v128->m_index = 0;
          }
          else
          {
            v132 = 0;
            v133 = m_cur;
            do
            {
              v131->m_index = v132++;
              v131->m_value = *(_DWORD *)v133;
              ++v131;
              v133 += 32;
            }
            while ( v132 < (int)v15 );
            hkAlgorithm::quickSortRecursive<hkValueIndexPair,hkAlgorithm::less<hkValueIndexPair>>(v128, 0, v15 - 1, 0);
          }
          m_childShapeAabbs = v11->m_collidable.m_boundingVolumeData.m_childShapeAabbs;
          m_childShapeKeys = v11->m_collidable.m_boundingVolumeData.m_childShapeKeys;
          if ( (int)v15 > 0 )
          {
            p_m_index = &v128->m_index;
            do
            {
              v137 = m_childShapeAabbs++;
              v138 = 4i64;
              v139 = (char *)(&m_cur[32 * *p_m_index] - (char *)v137);
              do
              {
                v140 = *(_QWORD *)((char *)v137->m_min + (_QWORD)v139);
                v137 = (hkAabbUint32 *)((char *)v137 + 8);
                *(_QWORD *)&v137[-1].m_max[2] = v140;
                --v138;
              }
              while ( v138 );
              v141 = *p_m_index;
              ++m_childShapeKeys;
              p_m_index += 2;
              *(m_childShapeKeys - 1) = *(_DWORD *)&v21[4 * v141];
              --v15;
            }
            while ( v15 );
          }
          v142 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v143 = (v129 + 15) & 0xFFFFFFF0;
          if ( v129 > v142->m_slabSize || (char *)v128 + v143 != v142->m_cur || v142->m_firstNonLifoEnd == v128 )
            hkLifoAllocator::slowBlockFree(v142, (char *)v128, v143);
          else
            v142->m_cur = v128;
          v3 = (hkpCollisionInput *)v206;
        }
        v144 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v145 = (v186 + 15) & 0xFFFFFFF0;
        if ( v186 > v144->m_slabSize || &v21[v145] != v144->m_cur || v144->m_firstNonLifoEnd == v21 )
          hkLifoAllocator::slowBlockFree(v144, v21, v145);
        else
          v144->m_cur = v21;
        v146 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        numEntities = (v18 + 15) & 0xFFFFFFF0;
        if ( v18 > v146->m_slabSize || &m_cur[(int)numEntities] != v146->m_cur || v146->m_firstNonLifoEnd == m_cur )
          hkLifoAllocator::slowBlockFree(v146, m_cur, numEntities);
        else
          v146->m_cur = m_cur;
      }
      v5 = *(float *)&retaddr;
      entityBatch = vars0;
      v4 = v191 + 1;
      v191 = v4;
    }
    while ( v4 < v193 );
  }
}

// File Line: 354
// RVA: 0xD7D4D0
void __fastcall hkpEntityAabbUtil::entityBatchInvalidateAabb(hkpEntity *const *entityBatch, int numEntities)
{
  __int64 v2; // r8
  __int64 i; // rax
  hkpEntity *v4; // rdx

  v2 = numEntities;
  for ( i = 0i64; i < v2; v4->m_collidable.m_boundingVolumeData.m_max[0] = 0 )
  {
    v4 = entityBatch[i++];
    v4->m_collidable.m_boundingVolumeData.m_min[0] = 1;
  }
}

