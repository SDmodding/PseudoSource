// File Line: 31
// RVA: 0xD7C3F0
void __fastcall hkpEntityAabbUtil::entityBatchRecalcAabb(hkpCollisionInput *collisionInput, hkpEntity *const *entityBatch, __int64 numEntities)
{
  hkpCollisionInput *v3; // rsi
  signed __int64 v4; // rax
  float v5; // xmm6_4
  __m128 v6; // xmm11
  __m128i v7; // xmm10
  __m128i v8; // xmm12
  __m128i v9; // xmm13
  __m128i v10; // xmm14
  hkpEntity *v11; // r13
  hkpShape *v12; // rcx
  __int64 v13; // rax
  __int64 v14; // rsi
  unsigned int v15; // eax
  __int64 v16; // rbx
  hkLifoAllocator *v17; // rax
  _DWORD *v18; // rdi
  int v19; // er15
  char *v20; // rcx
  hkLifoAllocator *v21; // rax
  _DWORD *v22; // r14
  int v23; // ecx
  char *v24; // rdx
  __m128 v25; // xmm13
  __m128 v26; // xmm7
  __m128 v27; // xmm12
  __m128 v28; // xmm15
  unsigned int v29; // er12
  __m128 v30; // xmm9
  __m128 *v31; // rbx
  unsigned int *v32; // r14
  _DWORD *v33; // rdi
  __m128 v34; // xmm14
  _QWORD *v35; // rax
  __int64 v36; // rcx
  __m128 v37; // xmm10
  __m128 v38; // xmm7
  __m128 v39; // xmm8
  __m128 v40; // xmm5
  __m128 v41; // xmm4
  __m128 v42; // xmm2
  __m128 v43; // xmm6
  __m128 v44; // xmm5
  __m128 v45; // xmm4
  __m128 *v46; // rax
  __m128 v47; // xmm3
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  __m128 v51; // xmm3
  __m128 v52; // xmm2
  __m128 v53; // xmm4
  __m128 v54; // xmm4
  __m128 v55; // xmm9
  __m128 v56; // xmm7
  __m128 v57; // xmm5
  __m128 v58; // xmm4
  __m128i v59; // xmm2
  __m128 v60; // xmm10
  __m128i v61; // xmm2
  __m128 v62; // xmm3
  __m128 v63; // xmm7
  __m128 v64; // xmm9
  __m128 v65; // xmm3
  __m128i v66; // xmm2
  __m128 v67; // xmm1
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
  __m128i v80; // xmm0
  __m128i v81; // xmm1
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
  __m128 v94; // xmm4
  __m128i v95; // xmm2
  __m128 v96; // xmm12
  __m128i v97; // xmm2
  __m128 v98; // xmm3
  __m128 v99; // xmm7
  __m128 v100; // xmm3
  __m128i v101; // xmm2
  __m128i v102; // xmm8
  __m128 v103; // xmm15
  __m128i v104; // xmm2
  __m128i v105; // xmm3
  __m128i v106; // xmm6
  __m128i v107; // xmm7
  __m128i v108; // xmm6
  __m128i v109; // xmm0
  __m128i v110; // xmm1
  int v111; // eax
  unsigned int v112; // eax
  __m128i v113; // xmm0
  __m128i v114; // xmm1
  __m128i v115; // xmm0
  __m128i v116; // xmm1
  unsigned int v117; // eax
  __m128 v118; // xmm7
  __m128i v119; // xmm7
  __m128i v120; // xmm7
  __m128 v121; // xmm6
  __m128i v122; // xmm6
  __m128i v123; // xmm6
  hkLifoAllocator *v124; // rax
  hkValueIndexPair *v125; // rsi
  int v126; // er12
  char *v127; // rcx
  hkValueIndexPair *v128; // rdx
  signed int v129; // ecx
  unsigned int *i; // r8
  hkAabbUint32 *v131; // r11
  unsigned int *v132; // r10
  unsigned int *v133; // r9
  hkAabbUint32 *v134; // rcx
  signed __int64 v135; // r8
  signed __int64 v136; // rdx
  __int64 v137; // rax
  __int64 v138; // rax
  hkLifoAllocator *v139; // rax
  int v140; // er8
  hkLifoAllocator *v141; // rax
  int v142; // er8
  hkLifoAllocator *v143; // rax
  __m128 v144; // xmm2
  __m128 v145; // xmm0
  __m128 v146; // xmm1
  __m128 v147; // xmm5
  __m128 v148; // xmm6
  __m128 v149; // xmm9
  __m128 v150; // xmm7
  __m128 v151; // xmm9
  __m128 v152; // xmm4
  __m128 v153; // xmm1
  __m128i v154; // xmm2
  __m128 v155; // xmm7
  __m128 v156; // xmm9
  __m128 v157; // xmm6
  __m128i v158; // xmm2
  __m128 v159; // xmm3
  __m128i v160; // xmm2
  __m128 v161; // xmm7
  __m128 v162; // xmm9
  __m128i v163; // xmm8
  __m128i v164; // xmm2
  __m128i v165; // xmm6
  __m128i v166; // xmm7
  __m128i v167; // xmm6
  __m128i v168; // xmm0
  __m128i v169; // xmm1
  int v170; // eax
  unsigned int v171; // eax
  __m128i v172; // xmm0
  __m128i v173; // xmm1
  __m128i v174; // xmm0
  __m128i v175; // xmm1
  unsigned int v176; // eax
  __m128 v177; // xmm7
  __m128i v178; // xmm7
  __m128i v179; // xmm7
  __m128 v180; // xmm6
  __m128i v181; // xmm6
  __m128i v182; // xmm6
  int v183; // [rsp+20h] [rbp-C8h]
  unsigned int v184; // [rsp+2Ch] [rbp-BCh]
  _DWORD *v185; // [rsp+30h] [rbp-B8h]
  _DWORD *v186; // [rsp+38h] [rbp-B0h]
  _DWORD *v187; // [rsp+40h] [rbp-A8h]
  signed __int64 v188; // [rsp+48h] [rbp-A0h]
  __m128 v189; // [rsp+50h] [rbp-98h]
  signed __int64 v190; // [rsp+60h] [rbp-88h]
  __m128 v191; // [rsp+68h] [rbp-80h]
  __m128 *v192; // [rsp+78h] [rbp-70h]
  __int64 v193; // [rsp+A8h] [rbp-40h]
  int v194; // [rsp+188h] [rbp+A0h]
  __m128 v195; // [rsp+198h] [rbp+B0h]
  __m128 v196; // [rsp+1A8h] [rbp+C0h]
  __m128 v197; // [rsp+1B8h] [rbp+D0h]
  __m128 v198; // [rsp+1C8h] [rbp+E0h]
  __m128 v199; // [rsp+1D8h] [rbp+F0h]
  __m128 v200; // [rsp+1E8h] [rbp+100h]
  __m128 v201; // [rsp+1F8h] [rbp+110h]
  __m128 v202; // [rsp+208h] [rbp+120h]
  char v203; // [rsp+218h] [rbp+130h]
  __m128 *v204; // [rsp+508h] [rbp+420h]
  hkpEntity *const *vars0; // [rsp+510h] [rbp+428h]
  float retaddr; // [rsp+518h] [rbp+430h]

  v3 = collisionInput;
  v4 = 0i64;
  v188 = 0i64;
  v190 = (signed int)numEntities;
  v5 = collisionInput->m_tolerance.m_storage * 0.5;
  retaddr = collisionInput->m_tolerance.m_storage * 0.5;
  if ( (signed int)numEntities > 0 )
  {
    v6 = 0i64;
    v7 = 0i64;
    v8 = _mm_load_si128((const __m128i *)&_xmm);
    v9 = _mm_load_si128((const __m128i *)&_xmm);
    v10 = _mm_load_si128((const __m128i *)&_xmm);
    do
    {
      v11 = entityBatch[v4];
      v12 = v11->m_collidable.m_shape;
      if ( v12->m_type.m_storage != 16 && v11->m_collidable.m_boundingVolumeData.m_capacityChildShapeAabbs )
      {
        v13 = ((__int64 (*)(void))v12->vfptr[7].__vecDelDtor)();
        v14 = v13;
        v15 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v13 + 8i64))(v13);
        v16 = v15;
        v184 = v15;
        v17 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v18 = v17->m_cur;
        v187 = v18;
        v19 = (32 * v16 + 127) & 0xFFFFFF80;
        v20 = (char *)v18 + v19;
        if ( v19 > v17->m_slabSize || v20 > v17->m_end )
        {
          v18 = hkLifoAllocator::allocateFromNewSlab(v17, v19);
          v187 = v18;
        }
        else
        {
          v17->m_cur = v20;
        }
        v21 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v22 = v21->m_cur;
        v23 = (4 * v16 + 127) & 0xFFFFFF80;
        v183 = (4 * v16 + 127) & 0xFFFFFF80;
        v186 = v22;
        v24 = (char *)v22 + v23;
        if ( v23 > v21->m_slabSize || v24 > v21->m_end )
        {
          v22 = hkLifoAllocator::allocateFromNewSlab(v21, v23);
          v186 = v22;
        }
        else
        {
          v21->m_cur = v24;
        }
        hkAabbUtil::initOffsetAabbInput(&v11->m_motion.m_motionState, (hkAabbUtil::OffsetAabbInput *)&v192);
        v25 = (__m128)xmmword_141A712A0;
        v26 = (__m128)xmmword_141A712A0;
        v189 = (__m128)xmmword_141A712A0;
        v185 = v22;
        v27 = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16(v7, 0x8000u, 1), 0), (__m128)xmmword_141A712A0);
        v28 = v27;
        v29 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 16i64))(v14);
        if ( v29 != -1 )
        {
          v30 = (__m128)_xmm;
          v31 = v204;
          v32 = v18 + 5;
          v33 = v185;
          v34 = _mm_shuffle_ps((__m128)0x3F3B67AFu, (__m128)0x3F3B67AFu, 0);
          do
          {
            v35 = (_QWORD *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v14 + 40i64))(
                              v14,
                              v29,
                              &v203);
            (*(void (__fastcall **)(_QWORD *, hkMotionState *, _QWORD, char *))(*v35 + 32i64))(
              v35,
              &v11->m_motion.m_motionState,
              *v35,
              &v191.m128_i8[8]);
            v36 = v194;
            v37 = v191;
            v38 = v192[8];
            v39 = _mm_mul_ps(_mm_sub_ps(v191, *(__m128 *)((char *)&v191 + 8)), (__m128)xmmword_141A711B0);
            v40 = _mm_add_ps(
                    _mm_mul_ps(_mm_sub_ps(*(__m128 *)((char *)&v191 + 8), v191), (__m128)xmmword_141A711B0),
                    v191);
            v41 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v40, v40, 85), v200),
                        _mm_mul_ps(_mm_shuffle_ps(v40, v40, 0), v199)),
                      _mm_mul_ps(_mm_shuffle_ps(v40, v40, 170), v201)),
                    v202);
            v42 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), v196),
                        _mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), v195)),
                      _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), v197)),
                    v198);
            v43 = _mm_min_ps(v40, v42);
            v44 = _mm_max_ps(v40, v42);
            if ( v194 > 0i64 )
            {
              v45 = _mm_sub_ps(v41, v38);
              v46 = (__m128 *)&v193;
              do
              {
                v47 = v46[1];
                v46 += 4;
                v48 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v47, v47, 255), v45), v38);
                v49 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), v46[-5]),
                            _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), v46[-6])),
                          _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), v46[-4])),
                        v47);
                v43 = _mm_min_ps(v43, v49);
                v44 = _mm_max_ps(v44, v49);
                --v36;
              }
              while ( v36 );
            }
            v27 = _mm_max_ps(v27, v191);
            v25 = _mm_min_ps(v25, *(__m128 *)((char *)&v191 + 8));
            v50 = _mm_mul_ps(v39, v39);
            v51 = _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
                    _mm_shuffle_ps(v50, v50, 170));
            v52 = _mm_rsqrt_ps(v51);
            v53 = _mm_andnot_ps(
                    _mm_cmpleps(v51, (__m128)0i64),
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_sub_ps(v30, _mm_mul_ps(_mm_mul_ps(v52, v51), v52)),
                        _mm_mul_ps(*(__m128 *)_xmm, v52)),
                      v51));
            v54 = _mm_min_ps(
                    v53,
                    _mm_add_ps(
                      _mm_mul_ps(_mm_min_ps(_mm_shuffle_ps(v192[9], v192[9], 255), _mm_mul_ps(v34, v53)), v53),
                      v39));
            v55 = _mm_max_ps(v191, _mm_add_ps(v44, v54));
            v56 = _mm_min_ps(*(__m128 *)((char *)&v191 + 8), _mm_sub_ps(v43, v54));
            v57 = hkAabbUtil::hkAabbUint32MaxVal;
            v6 = 0i64;
            v28 = _mm_max_ps(v28, v55);
            v189 = _mm_min_ps(v189, v56);
            v58 = _mm_max_ps(
                    _mm_min_ps(
                      _mm_mul_ps(_mm_add_ps(v31[3], *(__m128 *)((char *)&v191 + 8)), v31[5]),
                      hkAabbUtil::hkAabbUint32MaxVal),
                    (__m128)0i64);
            v59 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v58);
            _mm_store_si128(
              (__m128i *)(v32 - 5),
              _mm_or_si128(
                _mm_add_epi32(
                  _mm_cvttps_epi32(
                    _mm_max_ps(
                      _mm_sub_ps(v58, _mm_and_ps((__m128)v59, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                      (__m128)0i64)),
                  _mm_slli_epi32(v59, 0x1Fu)),
                (__m128i)_mm_cmpleps(
                           _mm_add_ps(
                             *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                             *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                           v58)));
            v60 = _mm_max_ps(_mm_min_ps(_mm_mul_ps(_mm_add_ps(v37, v31[4]), v31[5]), v57), (__m128)0i64);
            v61 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v60);
            _mm_store_si128(
              (__m128i *)(v32 - 1),
              _mm_or_si128(
                _mm_add_epi32(
                  _mm_cvttps_epi32(
                    _mm_max_ps(
                      _mm_sub_ps(v60, _mm_and_ps((__m128)v61, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                      (__m128)0i64)),
                  _mm_slli_epi32(v61, 0x1Fu)),
                (__m128i)_mm_cmpleps(
                           _mm_add_ps(
                             *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                             *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                           v60)));
            v62 = _mm_mul_ps(_mm_add_ps(v31[3], v56), v31[5]);
            v63 = _mm_add_ps(
                    *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                    *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31);
            v64 = _mm_max_ps(
                    _mm_min_ps(_mm_mul_ps(_mm_add_ps(v55, v31[4]), v31[5]), hkAabbUtil::hkAabbUint32MaxVal),
                    (__m128)0i64);
            v65 = _mm_max_ps(_mm_min_ps(v62, hkAabbUtil::hkAabbUint32MaxVal), (__m128)0i64);
            v66 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v65);
            v67 = _mm_sub_ps(v65, _mm_and_ps((__m128)v66, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31));
            v68 = (__m128i)_mm_cmpleps(v63, v65);
            v69 = _mm_cvtsi32_si128(0);
            v70 = _mm_or_si128(
                    _mm_add_epi32(_mm_cvttps_epi32(_mm_max_ps(v67, (__m128)0i64)), _mm_slli_epi32(v66, 0x1Fu)),
                    v68);
            v71 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v64);
            v72 = _mm_or_si128(
                    _mm_add_epi32(
                      _mm_cvttps_epi32(
                        _mm_max_ps(
                          _mm_sub_ps(
                            v64,
                            _mm_and_ps((__m128)v71, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                          (__m128)0i64)),
                      _mm_slli_epi32(v71, 0x1Fu)),
                    (__m128i)_mm_cmpleps(v63, v64));
            v73 = _mm_unpacklo_epi32(
                    _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v32 - 1)), _mm_cvtsi32_si128(v32[1])),
                    _mm_unpacklo_epi32(_mm_cvtsi32_si128(*v32), v69));
            v74 = _mm_sub_epi32(
                    _mm_unpacklo_epi32(
                      _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v32 - 5)), _mm_cvtsi32_si128(*(v32 - 3))),
                      _mm_unpacklo_epi32(_mm_cvtsi32_si128(*(v32 - 4)), v69)),
                    _mm_unpacklo_epi32(
                      _mm_unpacklo_epi32(
                        _mm_cvtsi32_si128(_mm_cvtsi128_si32(v70)),
                        _mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v70, 8)))),
                      _mm_unpacklo_epi32(_mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v70, 4))), v69)));
            v7 = 0i64;
            v32 += 8;
            ++v33;
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
            *(v32 - 10) = (unsigned __int128)_mm_packus_epi16(v87, v87);
            v89 = (__m128i)_mm_shuffle_ps(
                             v88,
                             _mm_unpackhi_ps(
                               v88,
                               (__m128)_mm_shuffle_epi32(_mm_cvtsi32_si128(*((unsigned __int8 *)v32 - 21)), 0)),
                             196);
            v90 = _mm_packs_epi32(v89, v89);
            *(v32 - 6) = (unsigned __int128)_mm_packus_epi16(v90, v90);
            *((_BYTE *)v32 - 21) = v29;
            *(v33 - 1) = v29;
            v29 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v14 + 24i64))(v14, v29);
            v30 = (__m128)_xmm;
          }
          while ( v29 != -1 );
          v26 = v189;
          v10 = _mm_load_si128((const __m128i *)&_xmm);
          v16 = v184;
          v22 = v186;
          v185 = v33;
          v18 = v187;
        }
        v3 = (hkpCollisionInput *)v204;
        v91 = _mm_cmpleps(v25, v27);
        v11->m_collidable.m_boundingVolumeData.m_numChildShapeAabbs = v185 - v22;
        v92 = hkAabbUtil::hkAabbUint32MaxVal;
        v93 = _mm_andnot_ps(v91, v11->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
        v94 = _mm_max_ps(
                _mm_min_ps(
                  _mm_mul_ps(
                    _mm_add_ps(v3->m_aabb32Info.m_bitOffsetLow.m_quad, _mm_or_ps(_mm_and_ps(v25, v91), v93)),
                    v3->m_aabb32Info.m_bitScale.m_quad),
                  hkAabbUtil::hkAabbUint32MaxVal),
                v6);
        v95 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v94);
        _mm_store_si128(
          (__m128i *)&v11->m_collidable.m_boundingVolumeData,
          _mm_or_si128(
            _mm_add_epi32(
              _mm_cvttps_epi32(
                _mm_max_ps(
                  _mm_sub_ps(v94, _mm_and_ps((__m128)v95, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                  v6)),
              _mm_slli_epi32(v95, 0x1Fu)),
            (__m128i)_mm_cmpleps(
                       _mm_add_ps(
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                       v94)));
        v96 = _mm_max_ps(
                _mm_min_ps(
                  _mm_mul_ps(
                    _mm_add_ps(_mm_or_ps(_mm_and_ps(v27, v91), v93), v3->m_aabb32Info.m_bitOffsetHigh.m_quad),
                    v3->m_aabb32Info.m_bitScale.m_quad),
                  v92),
                v6);
        v97 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v96);
        _mm_store_si128(
          (__m128i *)v11->m_collidable.m_boundingVolumeData.m_max,
          _mm_or_si128(
            _mm_add_epi32(
              _mm_cvttps_epi32(
                _mm_max_ps(
                  _mm_sub_ps(v96, _mm_and_ps((__m128)v97, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                  v6)),
              _mm_slli_epi32(v97, 0x1Fu)),
            (__m128i)_mm_cmpleps(
                       _mm_add_ps(
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                       v96)));
        v98 = _mm_mul_ps(
                _mm_add_ps(v3->m_aabb32Info.m_bitOffsetLow.m_quad, _mm_or_ps(_mm_and_ps(v26, v91), v93)),
                v3->m_aabb32Info.m_bitScale.m_quad);
        v99 = _mm_add_ps(
                *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31);
        v100 = _mm_max_ps(_mm_min_ps(v98, hkAabbUtil::hkAabbUint32MaxVal), v6);
        v101 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v100);
        v102 = _mm_or_si128(
                 _mm_add_epi32(
                   _mm_cvttps_epi32(
                     _mm_max_ps(
                       _mm_sub_ps(
                         v100,
                         _mm_and_ps((__m128)v101, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                       v6)),
                   _mm_slli_epi32(v101, 0x1Fu)),
                 (__m128i)_mm_cmpleps(v99, v100));
        v103 = _mm_max_ps(
                 _mm_min_ps(
                   _mm_mul_ps(
                     _mm_add_ps(_mm_or_ps(_mm_and_ps(v28, v91), v93), v3->m_aabb32Info.m_bitOffsetHigh.m_quad),
                     v3->m_aabb32Info.m_bitScale.m_quad),
                   hkAabbUtil::hkAabbUint32MaxVal),
                 v6);
        v104 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v103);
        v105 = _mm_cvtsi32_si128(0);
        v106 = _mm_or_si128(
                 _mm_add_epi32(
                   _mm_cvttps_epi32(
                     _mm_max_ps(
                       _mm_sub_ps(
                         v103,
                         _mm_and_ps((__m128)v104, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                       v6)),
                   _mm_slli_epi32(v104, 0x1Fu)),
                 (__m128i)_mm_cmpleps(v99, v103));
        v107 = _mm_sub_epi32(
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_min[0]),
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_min[2])),
                   _mm_unpacklo_epi32(_mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_min[1]), v105)),
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(v102)),
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v102, 8)))),
                   _mm_unpacklo_epi32(_mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v102, 4))), v105)));
        v108 = _mm_sub_epi32(
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(v106)),
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v106, 8)))),
                   _mm_unpacklo_epi32(_mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v106, 4))), v105)),
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_max[0]),
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_max[2])),
                   _mm_unpacklo_epi32(_mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_max[1]), v105)));
        v109 = _mm_or_si128(v108, v107);
        v110 = _mm_or_si128(_mm_shuffle_epi32(v109, 225), v109);
        v111 = _mm_cvtsi128_si32(_mm_or_si128(_mm_shuffle_epi32(v110, 78), v110));
        v112 = v111 | 0xFF | ((v111 | 0xFFu) >> 1) | ((v111 | 0xFF | ((v111 | 0xFFu) >> 1)) >> 2);
        v8 = _mm_load_si128((const __m128i *)&_xmm);
        v9 = _mm_load_si128((const __m128i *)&_xmm);
        v113 = _mm_cvtsi32_si128(v112 | (v112 >> 4) | ((v112 | (v112 >> 4)) >> 8) | ((v112 | (v112 >> 4) | ((v112 | (v112 >> 4)) >> 8)) >> 16));
        v114 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v113, 1u), v10), _mm_and_si128(v113, v10));
        v115 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v114, 2u), v8), _mm_and_si128(v114, v8));
        v116 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v115, 4u), v115), v9), v7);
        v117 = _mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v116, 78), v116)) - 8;
        v118 = (__m128)_mm_srli_epi32(v107, v117);
        v119 = (__m128i)_mm_shuffle_ps(
                          v118,
                          _mm_unpackhi_ps(v118, (__m128)_mm_shuffle_epi32(_mm_cvtsi32_si128(v117), 0)),
                          196);
        v120 = _mm_packs_epi32(v119, v119);
        v121 = (__m128)_mm_srli_epi32(v108, v117);
        *(_DWORD *)v11->m_collidable.m_boundingVolumeData.m_expansionMin = (unsigned __int128)_mm_packus_epi16(
                                                                                                v120,
                                                                                                v120);
        v122 = (__m128i)_mm_shuffle_ps(
                          v121,
                          _mm_unpackhi_ps(
                            v121,
                            (__m128)_mm_shuffle_epi32(
                                      _mm_cvtsi32_si128((unsigned __int8)v11->m_collidable.m_boundingVolumeData.m_padding),
                                      0)),
                          196);
        v123 = _mm_packs_epi32(v122, v122);
        *(_DWORD *)v11->m_collidable.m_boundingVolumeData.m_expansionMax = (unsigned __int128)_mm_packus_epi16(
                                                                                                v123,
                                                                                                v123);
        if ( (_DWORD)v16 )
        {
          v124 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v125 = (hkValueIndexPair *)v124->m_cur;
          v126 = (8 * v16 + 127) & 0xFFFFFF80;
          v127 = (char *)v125 + v126;
          if ( v126 > v124->m_slabSize || v127 > v124->m_end )
            v125 = (hkValueIndexPair *)hkLifoAllocator::allocateFromNewSlab(v124, v126);
          else
            v124->m_cur = v127;
          v128 = v125;
          if ( (signed int)v16 <= 1 )
          {
            if ( (_DWORD)v16 == 1 )
              v125->m_index = 0;
          }
          else
          {
            v129 = 0;
            for ( i = v18; v129 < (signed int)v16; i += 8 )
            {
              v128->m_index = v129++;
              v128->m_value = *i;
              ++v128;
            }
            hkAlgorithm::quickSortRecursive<hkValueIndexPair,hkAlgorithm::less<hkValueIndexPair>>(v125, 0, v16 - 1, 0);
          }
          v131 = v11->m_collidable.m_boundingVolumeData.m_childShapeAabbs;
          v132 = v11->m_collidable.m_boundingVolumeData.m_childShapeKeys;
          if ( (signed int)v16 > 0 )
          {
            v133 = &v125->m_index;
            do
            {
              v134 = v131;
              ++v131;
              v135 = 4i64;
              v136 = (char *)&v18[8 * *v133] - (char *)v134;
              do
              {
                v137 = *(_QWORD *)((char *)v134->m_min + v136);
                v134 = (hkAabbUint32 *)((char *)v134 + 8);
                *(_QWORD *)&v134[-1].m_max[2] = v137;
                --v135;
              }
              while ( v135 );
              v138 = *v133;
              ++v132;
              v133 += 2;
              *(v132 - 1) = v22[v138];
              --v16;
            }
            while ( v16 );
          }
          v139 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          v140 = (v126 + 15) & 0xFFFFFFF0;
          if ( v126 > v139->m_slabSize || (char *)v125 + v140 != v139->m_cur || v139->m_firstNonLifoEnd == v125 )
            hkLifoAllocator::slowBlockFree(v139, v125, v140);
          else
            v139->m_cur = v125;
          v3 = (hkpCollisionInput *)v204;
        }
        v141 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v142 = (v183 + 15) & 0xFFFFFFF0;
        if ( v183 > v141->m_slabSize || (char *)v22 + v142 != v141->m_cur || v141->m_firstNonLifoEnd == v22 )
          hkLifoAllocator::slowBlockFree(v141, v22, v142);
        else
          v141->m_cur = v22;
        v143 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        numEntities = (v19 + 15) & 0xFFFFFFF0;
        if ( v19 > v143->m_slabSize
          || (char *)v18 + (signed int)numEntities != v143->m_cur
          || v143->m_firstNonLifoEnd == v18 )
        {
          hkLifoAllocator::slowBlockFree(v143, v18, numEntities);
        }
        else
        {
          v143->m_cur = v18;
        }
      }
      else
      {
        ((void (__fastcall *)(hkpShape *, hkMotionState *, __int64, char *))v12->vfptr[2].__vecDelDtor)(
          v12,
          &v11->m_motion.m_motionState,
          numEntities,
          &v191.m128_i8[8]);
        v144 = v11->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad;
        v145 = _mm_shuffle_ps(
                 (__m128)LODWORD(v11->m_motion.m_motionState.m_objectRadius),
                 (__m128)LODWORD(v11->m_motion.m_motionState.m_objectRadius),
                 0);
        v146 = _mm_add_ps(_mm_shuffle_ps((__m128)LODWORD(v5), (__m128)LODWORD(v5), 0), v145);
        v147 = hkAabbUtil::hkAabbUint32MaxVal;
        v148 = v191;
        v149 = _mm_mul_ps(
                 _mm_shuffle_ps(
                   v11->m_motion.m_motionState.m_deltaAngle.m_quad,
                   v11->m_motion.m_motionState.m_deltaAngle.m_quad,
                   255),
                 v145);
        v150 = _mm_max_ps(_mm_sub_ps(*(__m128 *)((char *)&v191 + 8), v149), _mm_sub_ps(v144, v146));
        v151 = _mm_min_ps(_mm_add_ps(v149, v191), _mm_add_ps(v146, v144));
        v152 = _mm_max_ps(
                 _mm_min_ps(
                   _mm_mul_ps(
                     _mm_add_ps(v3->m_aabb32Info.m_bitOffsetLow.m_quad, *(__m128 *)((char *)&v191 + 8)),
                     v3->m_aabb32Info.m_bitScale.m_quad),
                   hkAabbUtil::hkAabbUint32MaxVal),
                 v6);
        v153 = _mm_sub_ps(v11->m_motion.m_motionState.m_sweptTransform.m_centerOfMass0.m_quad, v144);
        v154 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v152);
        v155 = _mm_add_ps(_mm_min_ps(v150, *(__m128 *)((char *)&v191 + 8)), _mm_min_ps(v6, v153));
        v156 = _mm_add_ps(_mm_max_ps(v151, v191), _mm_max_ps(v6, v153));
        _mm_store_si128(
          (__m128i *)&v11->m_collidable.m_boundingVolumeData,
          _mm_or_si128(
            _mm_add_epi32(
              _mm_cvttps_epi32(
                _mm_max_ps(
                  _mm_sub_ps(v152, _mm_and_ps((__m128)v154, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                  v6)),
              _mm_slli_epi32(v154, 0x1Fu)),
            (__m128i)_mm_cmpleps(
                       _mm_add_ps(
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                       v152)));
        v157 = _mm_max_ps(
                 _mm_min_ps(
                   _mm_mul_ps(
                     _mm_add_ps(v148, v3->m_aabb32Info.m_bitOffsetHigh.m_quad),
                     v3->m_aabb32Info.m_bitScale.m_quad),
                   v147),
                 v6);
        v158 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v157);
        _mm_store_si128(
          (__m128i *)v11->m_collidable.m_boundingVolumeData.m_max,
          _mm_or_si128(
            _mm_add_epi32(
              _mm_cvttps_epi32(
                _mm_max_ps(
                  _mm_sub_ps(v157, _mm_and_ps((__m128)v158, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                  v6)),
              _mm_slli_epi32(v158, 0x1Fu)),
            (__m128i)_mm_cmpleps(
                       _mm_add_ps(
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                         *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31),
                       v157)));
        v159 = _mm_max_ps(
                 _mm_min_ps(
                   _mm_mul_ps(
                     _mm_add_ps(v3->m_aabb32Info.m_bitOffsetLow.m_quad, v155),
                     v3->m_aabb32Info.m_bitScale.m_quad),
                   hkAabbUtil::hkAabbUint32MaxVal),
                 v6);
        v160 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v159);
        v161 = _mm_add_ps(
                 *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31,
                 *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31);
        v162 = _mm_max_ps(
                 _mm_min_ps(
                   _mm_mul_ps(
                     _mm_add_ps(v156, v3->m_aabb32Info.m_bitOffsetHigh.m_quad),
                     v3->m_aabb32Info.m_bitScale.m_quad),
                   hkAabbUtil::hkAabbUint32MaxVal),
                 v6);
        v163 = _mm_or_si128(
                 _mm_add_epi32(
                   _mm_cvttps_epi32(
                     _mm_max_ps(
                       _mm_sub_ps(
                         v159,
                         _mm_and_ps((__m128)v160, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                       v6)),
                   _mm_slli_epi32(v160, 0x1Fu)),
                 (__m128i)_mm_cmpleps(v161, v159));
        v164 = (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v162);
        v165 = _mm_or_si128(
                 _mm_add_epi32(
                   _mm_cvttps_epi32(
                     _mm_max_ps(
                       _mm_sub_ps(
                         v162,
                         _mm_and_ps((__m128)v164, *(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31)),
                       v6)),
                   _mm_slli_epi32(v164, 0x1Fu)),
                 (__m128i)_mm_cmpleps(v161, v162));
        v166 = _mm_sub_epi32(
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_min[0]),
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_min[2])),
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_min[1]),
                     _mm_cvtsi32_si128(0))),
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(v163)),
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v163, 8)))),
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v163, 4))),
                     _mm_cvtsi32_si128(0))));
        v167 = _mm_sub_epi32(
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(v165)),
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v165, 8)))),
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(_mm_cvtsi128_si32(_mm_srli_si128(v165, 4))),
                     _mm_cvtsi32_si128(0))),
                 _mm_unpacklo_epi32(
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_max[0]),
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_max[2])),
                   _mm_unpacklo_epi32(
                     _mm_cvtsi32_si128(v11->m_collidable.m_boundingVolumeData.m_max[1]),
                     _mm_cvtsi32_si128(0))));
        v168 = _mm_or_si128(v167, v166);
        v169 = _mm_or_si128(_mm_shuffle_epi32(v168, 225), v168);
        v170 = _mm_cvtsi128_si32(_mm_or_si128(_mm_shuffle_epi32(v169, 78), v169));
        v171 = v170 | 0xFF | ((v170 | 0xFFu) >> 1) | ((v170 | 0xFF | ((v170 | 0xFFu) >> 1)) >> 2);
        v172 = _mm_cvtsi32_si128(v171 | (v171 >> 4) | ((v171 | (v171 >> 4)) >> 8) | ((v171 | (v171 >> 4) | ((v171 | (v171 >> 4)) >> 8)) >> 16));
        v173 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v172, 1u), v10), _mm_and_si128(v172, v10));
        v174 = _mm_add_epi8(_mm_and_si128(_mm_srli_epi16(v173, 2u), v8), _mm_and_si128(v173, v8));
        v175 = _mm_sad_epu8(_mm_and_si128(_mm_add_epi8(_mm_srli_epi16(v174, 4u), v174), v9), v7);
        v176 = _mm_cvtsi128_si32(_mm_add_epi32(_mm_shuffle_epi32(v175, 78), v175)) - 8;
        v177 = (__m128)_mm_srli_epi32(v166, v176);
        v178 = (__m128i)_mm_shuffle_ps(
                          v177,
                          _mm_unpackhi_ps(v177, (__m128)_mm_shuffle_epi32(_mm_cvtsi32_si128(v176), 0)),
                          196);
        v179 = _mm_packs_epi32(v178, v178);
        v180 = (__m128)_mm_srli_epi32(v167, v176);
        *(_DWORD *)v11->m_collidable.m_boundingVolumeData.m_expansionMin = (unsigned __int128)_mm_packus_epi16(
                                                                                                v179,
                                                                                                v179);
        v181 = (__m128i)_mm_shuffle_ps(
                          v180,
                          _mm_unpackhi_ps(
                            v180,
                            (__m128)_mm_shuffle_epi32(
                                      _mm_cvtsi32_si128((unsigned __int8)v11->m_collidable.m_boundingVolumeData.m_padding),
                                      0)),
                          196);
        v182 = _mm_packs_epi32(v181, v181);
        *(_DWORD *)v11->m_collidable.m_boundingVolumeData.m_expansionMax = (unsigned __int128)_mm_packus_epi16(
                                                                                                v182,
                                                                                                v182);
      }
      v5 = retaddr;
      entityBatch = vars0;
      v4 = v188 + 1;
      v188 = v4;
    }
    while ( v4 < v190 );
  }
}

// File Line: 354
// RVA: 0xD7D4D0
void __fastcall hkpEntityAabbUtil::entityBatchInvalidateAabb(hkpEntity *const *entityBatch, int numEntities)
{
  __int64 v2; // r8
  __int64 v3; // rax
  hkpEntity *v4; // rdx

  v2 = numEntities;
  v3 = 0i64;
  if ( numEntities > 0 )
  {
    do
    {
      v4 = entityBatch[v3++];
      v4->m_collidable.m_boundingVolumeData.m_min[0] = 1;
      v4->m_collidable.m_boundingVolumeData.m_max[0] = 0;
    }
    while ( v3 < v2 );
  }
}

