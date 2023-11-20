// File Line: 28
// RVA: 0xB20B70
void __fastcall hkaSkeletonMapper::hkaSkeletonMapper(hkaSkeletonMapper *this, hkaSkeletonMapperData *mapping)
{
  hkaSkeletonMapper *v2; // rsi
  hkaSkeletonMapperData *v3; // rdi

  v2 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaSkeletonMapper::`vftable';
  v3 = mapping;
  hkaSkeletonMapperData::hkaSkeletonMapperData(&this->m_mapping);
  hkaSkeletonMapperData::operator=(&v2->m_mapping, v3);
}

// File Line: 38
// RVA: 0xB20BD0
void __fastcall hkaSkeletonMapper::~hkaSkeletonMapper(hkaSkeletonMapper *this)
{
  hkaSkeletonMapper *v1; // rbx
  hkaSkeletonMapperData *v2; // rcx

  v1 = this;
  v2 = &this->m_mapping;
  *(_QWORD *)&v2[-1].m_keepUnmappedLocal.m_bool = &hkaSkeletonMapper::`vftable';
  hkaSkeletonMapperData::~hkaSkeletonMapperData(v2);
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 46
// RVA: 0xB248E0
void __fastcall normalize3TwoAtOnce(hkVector4f *A, hkVector4f *B)
{
  __m128 v2; // xmm2
  __m128 v3; // xmm1
  __m128 v4; // xmm4
  __m128 v5; // xmm4
  __m128 v6; // xmm2
  __m128 v7; // xmm3

  v2 = _mm_mul_ps(B->m_quad, B->m_quad);
  v3 = _mm_mul_ps(A->m_quad, A->m_quad);
  v4 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v3, v3, 85), _mm_shuffle_ps(v3, v3, 0)), _mm_shuffle_ps(v3, v3, 170));
  v5 = _mm_shuffle_ps(
         v4,
         _mm_unpackhi_ps(
           v4,
           _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v2, v2, 85), _mm_shuffle_ps(v2, v2, 0)), _mm_shuffle_ps(v2, v2, 170))),
         196);
  v6 = _mm_rsqrt_ps(v5);
  v7 = _mm_andnot_ps(
         _mm_cmpleps(v5, (__m128)0i64),
         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v6, v5), v6)), _mm_mul_ps(*(__m128 *)_xmm, v6)));
  A->m_quad = _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), A->m_quad);
  B->m_quad = _mm_mul_ps(_mm_shuffle_ps(v7, v7, 255), B->m_quad);
}

// File Line: 63
// RVA: 0xB24980
__int64 __fastcall getBoneIndexFromPartition(bool mapToFullPose, int boneIndex, int partitionStartIndex, int offset)
{
  __int64 result; // rax

  if ( mapToFullPose )
    result = (unsigned int)boneIndex;
  else
    result = (unsigned int)(offset + boneIndex - partitionStartIndex);
  return result;
}

// File Line: 68
// RVA: 0xB20C10
void __fastcall hkaSkeletonMapper::mapPose(hkaSkeletonMapper *this, hkQsTransformf *poseAModelSpace, hkQsTransformf *originalPoseBLocalSpace, hkQsTransformf *poseBModelSpace, hkaSkeletonMapper::ConstraintSource source)
{
  hkaSkeletonMapper *v5; // r13
  hkQsTransformf *v7; // rdi
  _QWORD *v9; // rax
  unsigned __int64 v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  signed __int64 v16; // rcx
  __int64 v17; // r10
  __int64 v18; // r14
  int v19; // er11
  __int64 v20; // r9
  __m128 v23; // xmm3
  __m128 *v24; // rdx
  signed __int64 v25; // rcx
  __m128 v26; // xmm2
  __m128 v27; // xmm1
  __m128 v28; // xmm6
  __m128 v29; // xmm5
  __m128 v30; // xmm4
  __m128 v31; // xmm6
  __m128 v32; // xmm2
  __m128 v33; // xmm4
  __m128 v34; // xmm0
  __m128 v35; // xmm5
  __m128 v36; // xmm3
  __m128 v37; // xmm6
  __m128 v38; // xmm3
  __m128 v39; // xmm3
  _QWORD *v42; // r8
  _QWORD *v43; // rcx
  unsigned __int64 v44; // rax
  signed __int64 v45; // rcx
  __int64 v46; // rdx
  __int64 v47; // r9
  unsigned __int64 v48; // r8
  int v49; // er15
  __m128 v50; // xmm3
  __m128 *v51; // rcx
  signed __int64 v52; // r12
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  __m128 v55; // xmm6
  __m128 v56; // xmm5
  __m128 v57; // xmm4
  __m128 v58; // xmm6
  __m128 v59; // xmm2
  __m128 v60; // xmm4
  __m128 v61; // xmm0
  __m128 v62; // xmm5
  __m128 v63; // xmm3
  __m128 v64; // xmm6
  __m128 v65; // xmm3
  __m128 v66; // xmm3
  int v67; // ebx
  LPVOID v68; // rax
  hkLifoAllocator *v69; // rcx
  __int16 *v70; // rax
  int v71; // edx
  hkaSkeleton *v72; // rdx
  int v73; // er9
  __int16 *v74; // r8
  signed __int64 v75; // rdx
  __m128 i; // xmm6
  __int64 v77; // rax
  __m128 v78; // xmm2
  __m128 v79; // xmm4
  __m128 v80; // xmm5
  __m128 v81; // xmm1
  __m128 v82; // xmm3
  __m128 v83; // xmm6
  __m128 v84; // xmm6
  __m128 v85; // xmm2
  __m128 v86; // xmm1
  __m128 v87; // xmm4
  __m128 v88; // xmm3
  __m128 v89; // xmm7
  __m128 v90; // xmm2
  __m128 v91; // xmm7
  __m128 v92; // xmm5
  __m128 v93; // xmm3
  __m128 v94; // xmm0
  __m128 v95; // xmm1
  __m128 v96; // xmm4
  __m128 v97; // xmm6
  __m128 v98; // xmm6
  __m128 v99; // xmm1
  __m128 v100; // xmm3
  float v101; // xmm1_4
  __m128 v102; // xmm7
  __m128 v103; // xmm2
  __m128 v104; // xmm6
  __m128 v105; // xmm6
  __m128 v106; // xmm9
  __m128 v107; // xmm2
  __m128 v108; // xmm1
  __m128 v109; // xmm5
  __m128 v110; // xmm3
  __m128 v111; // xmm2
  __m128 v112; // xmm1
  __m128 v113; // xmm6
  __m128 v114; // xmm5
  int v115; // er11
  __m128 v116; // xmm4
  __m128 v117; // xmm2
  __m128 v118; // xmm5
  __m128 v119; // xmm0
  __m128 v120; // xmm1
  __m128 v121; // xmm3
  __m128 v122; // xmm6
  __m128 v123; // xmm3
  __m128 v124; // xmm3
  signed __int64 v125; // r10
  signed __int64 v126; // rdx
  __m128 *v127; // rcx
  __m128 v128; // xmm3
  __m128 v129; // xmm2
  __m128 v130; // xmm1
  __m128 v131; // xmm6
  __m128 v132; // xmm5
  __m128 v133; // xmm4
  __m128 v134; // xmm6
  __m128 v135; // xmm2
  __m128 v136; // xmm4
  __m128 v137; // xmm0
  __m128 v138; // xmm5
  __m128 v139; // xmm3
  __m128 v140; // xmm6
  __m128 v141; // xmm3
  __m128 v142; // xmm3
  char *v143; // r15
  signed int v144; // ebx
  hkLifoAllocator *v145; // rax
  int v146; // er8
  bool v147; // zf
  _QWORD *v148; // rax
  _QWORD *v149; // rcx
  _QWORD *v150; // r8
  unsigned __int64 v151; // rax
  signed __int64 v152; // rcx
  __int64 v153; // r8
  signed __int64 v154; // rdx
  __int16 v155; // ax
  signed __int64 v156; // rdx
  __m128 *v157; // rcx
  __m128 v158; // xmm3
  __m128 v159; // xmm2
  __m128 v160; // xmm1
  __m128 v161; // xmm6
  __m128 v162; // xmm5
  __m128 v163; // xmm4
  __m128 v164; // xmm6
  __m128 v165; // xmm2
  __m128 v166; // xmm4
  __m128 v167; // xmm0
  __m128 v168; // xmm5
  __m128 v169; // xmm3
  __m128 v170; // xmm6
  __m128 v171; // xmm3
  __m128 v172; // xmm3
  signed __int64 v173; // rax
  _QWORD *v174; // rax
  _QWORD *v175; // rcx
  _QWORD *v176; // r8
  unsigned __int64 v177; // rax
  signed __int64 v178; // rcx
  _QWORD *v179; // rax
  _QWORD *v180; // rcx
  _QWORD *v181; // r8
  unsigned __int64 v182; // rax
  signed __int64 v183; // rcx
  __int16 v184; // [rsp+30h] [rbp-C8h]
  __int16 v185; // [rsp+32h] [rbp-C6h]
  hkArray<short,hkContainerHeapAllocator> bonesOut; // [rsp+38h] [rbp-C0h]
  void *p; // [rsp+48h] [rbp-B0h]
  int v188; // [rsp+50h] [rbp-A8h]
  int v189; // [rsp+58h] [rbp-A0h]
  __int64 v190; // [rsp+60h] [rbp-98h]
  int v191; // [rsp+68h] [rbp-90h]
  __int64 v192; // [rsp+70h] [rbp-88h]
  hkQuaternionf v193; // [rsp+78h] [rbp-80h]
  hkVector4f A; // [rsp+88h] [rbp-70h]
  __int64 v195; // [rsp+98h] [rbp-60h]
  hkVector4f B; // [rsp+A8h] [rbp-50h]
  void *retaddr; // [rsp+168h] [rbp+70h]
  hkQsTransformf *v198; // [rsp+170h] [rbp+78h]
  int v199; // [rsp+188h] [rbp+90h]

  v5 = this;
  _RSI = poseBModelSpace;
  v7 = originalPoseBLocalSpace;
  _RBX = poseAModelSpace;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = v9[1];
  v11 = v9;
  if ( v10 < v9[3] )
  {
    *(_QWORD *)v10 = "LtMapPoseModelSpace";
    *(_QWORD *)(v10 + 16) = "Stinit";
    v12 = __rdtsc();
    *(_DWORD *)(v10 + 8) = v12;
    v11[1] = v10 + 24;
  }
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "StsimpleMappings";
    v15 = __rdtsc();
    v16 = (signed __int64)(v14 + 2);
    *(_DWORD *)(v16 - 8) = v15;
    v13[1] = v16;
  }
  v17 = v5->m_mapping.m_simpleMappings.m_size;
  v18 = 0i64;
  v19 = 0;
  if ( v17 > 0 )
  {
    v20 = 0i64;
    do
    {
      _R8 = v5->m_mapping.m_simpleMappings.m_data;
      _RAX = (v19 + 2i64) << 6;
      __asm { prefetchnta byte ptr [rax+r8]; Prefetch to L1 cache }
      v23 = _R8[v20].m_aFromBTransform.m_translation.m_quad;
      v24 = &_RBX[_R8[v20].m_boneA].m_translation.m_quad;
      v25 = _R8[v20].m_boneB;
      v26 = v24[1];
      v27 = _mm_mul_ps(_R8[v20].m_aFromBTransform.m_translation.m_quad, v26);
      v28 = _mm_shuffle_ps(v24[1], v26, 255);
      v29 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v26), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), v23));
      v30 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v27, v27, 85), _mm_shuffle_ps(v27, v27, 0)),
                    _mm_shuffle_ps(v27, v27, 170)),
                  v26),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v28, v28), (__m128)xmmword_141A711B0), v23)),
              _mm_mul_ps(_mm_shuffle_ps(v29, v29, 201), v28));
      _RSI[v25].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v30, v30), *v24);
      v31 = v24[1];
      v32 = _R8[v20].m_aFromBTransform.m_rotation.m_vec.m_quad;
      v33 = _mm_shuffle_ps(v24[1], v24[1], 255);
      v34 = _mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v32);
      v35 = _mm_shuffle_ps(
              _R8[v20].m_aFromBTransform.m_rotation.m_vec.m_quad,
              _R8[v20].m_aFromBTransform.m_rotation.m_vec.m_quad,
              255);
      v36 = _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v31);
      v37 = _mm_mul_ps(v31, v32);
      v38 = _mm_sub_ps(v36, v34);
      v39 = _mm_add_ps(
              _mm_add_ps(
                _mm_shuffle_ps(v38, v38, 201),
                _mm_mul_ps(_R8[v20].m_aFromBTransform.m_rotation.m_vec.m_quad, v33)),
              _mm_mul_ps(v24[1], v35));
      _RSI[v25].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                            v39,
                                            _mm_unpackhi_ps(
                                              v39,
                                              _mm_sub_ps(
                                                _mm_mul_ps(v35, v33),
                                                _mm_add_ps(
                                                  _mm_add_ps(_mm_shuffle_ps(v37, v37, 85), _mm_shuffle_ps(v37, v37, 0)),
                                                  _mm_shuffle_ps(v37, v37, 170)))),
                                            196);
      _RSI[v25].m_scale.m_quad = _mm_mul_ps(_R8[v20].m_aFromBTransform.m_scale.m_quad, v24[2]);
      _RCX = 6i64 * _R8[v20].m_boneA;
      __asm { prefetchnta byte ptr [rbx+rcx*8+80h]; Prefetch to L1 cache }
      _RCX = 6i64 * _R8[v20].m_boneB;
      __asm { prefetchnta byte ptr [rsi+rcx*8+80h]; Prefetch to L1 cache }
      ++v19;
      ++v20;
      --v17;
    }
    while ( v17 );
  }
  v42 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v43 = (_QWORD *)v42[1];
  if ( (unsigned __int64)v43 < v42[3] )
  {
    *v43 = "StchainMappings";
    v44 = __rdtsc();
    v45 = (signed __int64)(v43 + 2);
    *(_DWORD *)(v45 - 8) = v44;
    v42[1] = v45;
  }
  v192 = v5->m_mapping.m_chainMappings.m_size;
  if ( v192 > 0 )
  {
    v46 = 0i64;
    v190 = 0i64;
    while ( 1 )
    {
      v47 = (__int64)v5->m_mapping.m_chainMappings.m_data;
      v195 = v47;
      v48 = *(signed __int16 *)(v46 + v47 + 4);
      v49 = *(signed __int16 *)(v46 + v47 + 6);
      v50 = *(__m128 *)(v46 + v47 + 16);
      v184 = *(_WORD *)(v46 + v47 + 2);
      v185 = *(_WORD *)(v46 + v47 + 4);
      v51 = &_RBX[*(signed __int16 *)(v46 + v47)].m_translation.m_quad;
      v52 = v48;
      v53 = v51[1];
      v54 = _mm_mul_ps(*(__m128 *)(v46 + v47 + 16), v53);
      v55 = _mm_shuffle_ps(v51[1], v53, 255);
      v56 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v50, v50, 201), v53), _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v50));
      v57 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
                    _mm_shuffle_ps(v54, v54, 170)),
                  v53),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v55, v55), (__m128)xmmword_141A711B0), v50)),
              _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v55));
      _RSI[v52].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v57, v57), *v51);
      v58 = v51[1];
      v59 = *(__m128 *)(v46 + v47 + 32);
      v60 = _mm_shuffle_ps(v51[1], v51[1], 255);
      v61 = _mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v59);
      v62 = _mm_shuffle_ps(*(__m128 *)(v46 + v47 + 32), *(__m128 *)(v46 + v47 + 32), 255);
      v63 = _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v58);
      v64 = _mm_mul_ps(v58, v59);
      v65 = _mm_sub_ps(v63, v61);
      v66 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v65, v65, 201), _mm_mul_ps(*(__m128 *)(v46 + v47 + 32), v60)),
              _mm_mul_ps(v51[1], v62));
      _RSI[v52].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                            v66,
                                            _mm_unpackhi_ps(
                                              v66,
                                              _mm_sub_ps(
                                                _mm_mul_ps(v62, v60),
                                                _mm_add_ps(
                                                  _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
                                                  _mm_shuffle_ps(v64, v64, 170)))),
                                            196);
      _RSI[v52].m_scale.m_quad = _mm_mul_ps(*(__m128 *)(v46 + v47 + 48), v51[2]);
      bonesOut.m_data = 0i64;
      bonesOut.m_size = 0;
      bonesOut.m_capacityAndFlags = 2147483648;
      v67 = v49 - v48 + 1;
      v188 = v49 - v48 + 1;
      if ( v49 - (_DWORD)v48 == -1 )
      {
        v70 = 0i64;
      }
      else
      {
        v68 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v69 = (hkLifoAllocator *)v68;
        v70 = (__int16 *)*((_QWORD *)v68 + 3);
        v71 = (2 * v67 + 127) & 0xFFFFFF80;
        v48 = (unsigned __int64)v70 + v71;
        if ( v71 > v69->m_slabSize || (void *)v48 > v69->m_end )
        {
          v70 = (__int16 *)hkLifoAllocator::allocateFromNewSlab(v69, v71);
          LOWORD(v48) = v185;
        }
        else
        {
          v69->m_cur = (void *)v48;
          LOWORD(v48) = v185;
        }
      }
      v72 = v5->m_mapping.m_skeletonB.m_pntr;
      bonesOut.m_data = v70;
      p = v70;
      bonesOut.m_capacityAndFlags = v67 | 0x80000000;
      hkaSkeletonUtils::getBoneChain((hkBool *)&retaddr, v72, v48, v49, &bonesOut);
      v73 = bonesOut.m_size;
      v74 = bonesOut.m_data;
      v75 = bonesOut.m_size - 2;
      for ( i = v7[(signed __int16)v49].m_translation.m_quad;
            v75 >= 1;
            i = _mm_add_ps(_mm_add_ps(v83, v83), v7[v77].m_translation.m_quad) )
      {
        v77 = bonesOut.m_data[v75--];
        v78 = v7[v77].m_rotation.m_vec.m_quad;
        v79 = _mm_mul_ps(v7[v77].m_scale.m_quad, i);
        v80 = _mm_shuffle_ps(v7[v77].m_rotation.m_vec.m_quad, v78, 255);
        v81 = _mm_mul_ps(v79, v78);
        v82 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v79, v79, 201), v78), _mm_mul_ps(_mm_shuffle_ps(v78, v78, 201), v79));
        v83 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v81, v81, 85), _mm_shuffle_ps(v81, v81, 0)),
                      _mm_shuffle_ps(v81, v81, 170)),
                    v78),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v80, v80), (__m128)xmmword_141A711B0), v79)),
                _mm_mul_ps(_mm_shuffle_ps(v82, v82, 201), v80));
      }
      v84 = _mm_mul_ps(i, _RSI[v52].m_scale.m_quad);
      v85 = _RSI[v52].m_rotation.m_vec.m_quad;
      v86 = _mm_mul_ps(v84, v85);
      v87 = _mm_shuffle_ps(_RSI[v52].m_rotation.m_vec.m_quad, v85, 255);
      v88 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v84, v84, 201), v85), _mm_mul_ps(_mm_shuffle_ps(v85, v85, 201), v84));
      v89 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v86, v86, 85), _mm_shuffle_ps(v86, v86, 0)),
                _mm_shuffle_ps(v86, v86, 170)),
              v85);
      v90 = v198[v184].m_rotation.m_vec.m_quad;
      v91 = _mm_add_ps(
              _mm_add_ps(v89, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v87, v87), (__m128)xmmword_141A711B0), v84)),
              _mm_mul_ps(_mm_shuffle_ps(v88, v88, 201), v87));
      v92 = _mm_shuffle_ps(v90, v90, 255);
      v93 = *(__m128 *)(v190 + v195 + 64);
      v94 = _mm_mul_ps(_mm_shuffle_ps(v198[v184].m_rotation.m_vec.m_quad, v90, 201), v93);
      v95 = _mm_mul_ps(*(__m128 *)(v190 + v195 + 64), v90);
      A.m_quad = _mm_sub_ps(
                   _mm_add_ps(_mm_add_ps(v91, v91), _RSI[v52].m_translation.m_quad),
                   _RSI[v52].m_translation.m_quad);
      v96 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v93, v93, 201), v90), v94);
      v97 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v95, v95, 85), _mm_shuffle_ps(v95, v95, 0)),
                    _mm_shuffle_ps(v95, v95, 170)),
                  v90),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v92, v92), (__m128)xmmword_141A711B0), v93)),
              _mm_mul_ps(_mm_shuffle_ps(v96, v96, 201), v92));
      B.m_quad = _mm_sub_ps(
                   _mm_add_ps(_mm_add_ps(v97, v97), v198[v184].m_translation.m_quad),
                   _RSI[v52].m_translation.m_quad);
      if ( ((_mm_movemask_ps(_mm_cmpeqps(A.m_quad, (__m128)0i64)) & 7) == 7) | ((_mm_movemask_ps(_mm_cmpeqps(B.m_quad, (__m128)0i64)) & 7) == 7) )
        break;
      normalize3TwoAtOnce(&A, &B);
      v189 = 1065353048;
      v99 = _mm_mul_ps(B.m_quad, A.m_quad);
      v100 = _mm_add_ps(
               _mm_add_ps(_mm_shuffle_ps(v99, v99, 85), _mm_shuffle_ps(v99, v99, 0)),
               _mm_shuffle_ps(v99, v99, 170));
      LODWORD(v101) = (unsigned __int128)_mm_shuffle_ps((__m128)0x3F7FFF58u, (__m128)0x3F7FFF58u, 0);
      if ( v100.m128_f32[0] > v101 )
      {
        v98 = qi.m_vec.m_quad;
        goto LABEL_29;
      }
      if ( v100.m128_f32[0] >= (float)(0.0 - v101) )
      {
        v191 = -1082147209;
        v102 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v100), (__m128)xmmword_141A711B0);
        v103 = _mm_rsqrt_ps(v102);
        v104 = _mm_sub_ps(
                 _mm_mul_ps(_mm_shuffle_ps(B.m_quad, B.m_quad, 201), A.m_quad),
                 _mm_mul_ps(_mm_shuffle_ps(A.m_quad, A.m_quad, 201), B.m_quad));
        v105 = _mm_shuffle_ps(v104, v104, 201);
        v106 = _mm_andnot_ps(
                 _mm_cmpleps(v102, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v102, v103), v103)),
                   _mm_mul_ps(*(__m128 *)_xmm, v103)));
        v107 = _mm_mul_ps(v106, (__m128)xmmword_141A711B0);
        if ( v100.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)0xBF7FBE77, (__m128)0xBF7FBE77, 0)) )
        {
          v108 = _mm_mul_ps(v105, v105);
          v109 = _mm_sub_ps(v102, v100);
          v110 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v108, v108, 85), _mm_shuffle_ps(v108, v108, 0)),
                   _mm_shuffle_ps(v108, v108, 170));
          v111 = _mm_rsqrt_ps(v110);
          v112 = _mm_rsqrt_ps(v109);
          v107 = _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_andnot_ps(
                       _mm_cmpleps(v109, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v112, v109), v112)),
                         _mm_mul_ps(v112, *(__m128 *)_xmm))),
                     v109),
                   _mm_andnot_ps(
                     _mm_cmpleps(v110, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v111, v110), v111)),
                       _mm_mul_ps(v111, *(__m128 *)_xmm))));
        }
        v113 = _mm_mul_ps(v105, v107);
        v98 = _mm_shuffle_ps(v113, _mm_unpackhi_ps(v113, _mm_mul_ps(v102, v106)), 196);
        goto LABEL_29;
      }
      hkQuaternionf::setFlippedRotation(&v193, &A);
      v73 = bonesOut.m_size;
      v74 = bonesOut.m_data;
      v98 = v193.m_vec.m_quad;
LABEL_30:
      v114 = _RSI[v52].m_rotation.m_vec.m_quad;
      v115 = 1;
      v116 = _mm_shuffle_ps(v98, v98, 255);
      v117 = v114;
      v118 = _mm_shuffle_ps(v114, v114, 255);
      v119 = _mm_mul_ps(_mm_shuffle_ps(v98, v98, 201), v117);
      v120 = _mm_mul_ps(v98, v118);
      v121 = _mm_mul_ps(_mm_shuffle_ps(v117, v117, 201), v98);
      v122 = _mm_mul_ps(v98, v117);
      v123 = _mm_sub_ps(v121, v119);
      v124 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v123, v123, 201), _mm_mul_ps(v117, v116)), v120);
      _RSI[v52].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                            v124,
                                            _mm_unpackhi_ps(
                                              v124,
                                              _mm_sub_ps(
                                                _mm_mul_ps(v118, v116),
                                                _mm_add_ps(
                                                  _mm_add_ps(
                                                    _mm_shuffle_ps(v122, v122, 85),
                                                    _mm_shuffle_ps(v122, v122, 0)),
                                                  _mm_shuffle_ps(v122, v122, 170)))),
                                            196);
      if ( v73 - 1 > 1 )
      {
        v125 = 1i64;
        do
        {
          ++v115;
          v126 = v74[v125];
          v127 = &_RSI[v74[v125 - 1]].m_translation.m_quad;
          ++v125;
          v128 = v7[v126].m_translation.m_quad;
          v129 = v127[1];
          v130 = _mm_mul_ps(v7[v126].m_translation.m_quad, v129);
          v131 = _mm_shuffle_ps(v127[1], v129, 255);
          v132 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v128, v128, 201), v129),
                   _mm_mul_ps(_mm_shuffle_ps(v129, v129, 201), v128));
          v133 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v130, v130, 85), _mm_shuffle_ps(v130, v130, 0)),
                         _mm_shuffle_ps(v130, v130, 170)),
                       v129),
                     _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v131, v131), (__m128)xmmword_141A711B0), v128)),
                   _mm_mul_ps(_mm_shuffle_ps(v132, v132, 201), v131));
          _RSI[v126].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v133, v133), *v127);
          v134 = v127[1];
          v135 = v7[v126].m_rotation.m_vec.m_quad;
          v136 = _mm_shuffle_ps(v127[1], v127[1], 255);
          v137 = _mm_mul_ps(_mm_shuffle_ps(v134, v134, 201), v135);
          v138 = _mm_shuffle_ps(v7[v126].m_rotation.m_vec.m_quad, v7[v126].m_rotation.m_vec.m_quad, 255);
          v139 = _mm_mul_ps(_mm_shuffle_ps(v135, v135, 201), v134);
          v140 = _mm_mul_ps(v134, v135);
          v141 = _mm_sub_ps(v139, v137);
          v142 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v141, v141, 201), _mm_mul_ps(v7[v126].m_rotation.m_vec.m_quad, v136)),
                   _mm_mul_ps(v127[1], v138));
          _RSI[v126].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                 v142,
                                                 _mm_unpackhi_ps(
                                                   v142,
                                                   _mm_sub_ps(
                                                     _mm_mul_ps(v138, v136),
                                                     _mm_add_ps(
                                                       _mm_add_ps(
                                                         _mm_shuffle_ps(v140, v140, 85),
                                                         _mm_shuffle_ps(v140, v140, 0)),
                                                       _mm_shuffle_ps(v140, v140, 170)))),
                                                 196);
          _RSI[v126].m_scale.m_quad = _mm_mul_ps(v127[2], v7[v126].m_scale.m_quad);
          v73 = bonesOut.m_size;
          v74 = bonesOut.m_data;
        }
        while ( v115 < bonesOut.m_size - 1 );
      }
      v143 = (char *)p;
      if ( p == v74 )
        v73 = 0;
      v144 = (2 * v188 + 127) & 0xFFFFFF80;
      bonesOut.m_size = v73;
      v145 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v146 = (v144 + 15) & 0xFFFFFFF0;
      if ( v144 > v145->m_slabSize || &v143[v146] != v145->m_cur || v145->m_firstNonLifoEnd == v143 )
        hkLifoAllocator::slowBlockFree(v145, v143, v146);
      else
        v145->m_cur = v143;
      bonesOut.m_size = 0;
      if ( bonesOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          bonesOut.m_data,
          2 * (bonesOut.m_capacityAndFlags & 0x3FFFFFFF));
      _RBX = v198;
      v46 = v190 + 112;
      v147 = v192-- == 1;
      v190 += 112i64;
      if ( v147 )
        goto LABEL_43;
    }
    v98 = qi.m_vec.m_quad;
LABEL_29:
    v193.m_vec.m_quad = v98;
    goto LABEL_30;
  }
LABEL_43:
  v148 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v149 = (_QWORD *)v148[1];
  v150 = v148;
  if ( (unsigned __int64)v149 < v148[3] )
  {
    *v149 = "StunmappedBones";
    v151 = __rdtsc();
    v152 = (signed __int64)(v149 + 2);
    *(_DWORD *)(v152 - 8) = v151;
    v150[1] = v152;
  }
  if ( v5->m_mapping.m_keepUnmappedLocal.m_bool )
  {
    v153 = v5->m_mapping.m_unmappedBones.m_size;
    if ( v153 > 0 )
    {
      do
      {
        v154 = v5->m_mapping.m_unmappedBones.m_data[v18];
        v155 = v5->m_mapping.m_skeletonB.m_pntr->m_parentIndices.m_data[v154];
        if ( v155 == -1 )
        {
          v173 = v154;
          _RSI[v173].m_translation = v7[v154].m_translation;
          _RSI[v173].m_rotation = v7[v154].m_rotation;
          _RSI[v173].m_scale = v7[v154].m_scale;
        }
        else
        {
          v156 = v154;
          v157 = &_RSI[v155].m_translation.m_quad;
          v158 = v7[v156].m_translation.m_quad;
          v159 = v157[1];
          v160 = _mm_mul_ps(v7[v156].m_translation.m_quad, v159);
          v161 = _mm_shuffle_ps(v157[1], v159, 255);
          v162 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v158, v158, 201), v159),
                   _mm_mul_ps(_mm_shuffle_ps(v159, v159, 201), v158));
          v163 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v160, v160, 85), _mm_shuffle_ps(v160, v160, 0)),
                         _mm_shuffle_ps(v160, v160, 170)),
                       v159),
                     _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v161, v161), (__m128)xmmword_141A711B0), v158)),
                   _mm_mul_ps(_mm_shuffle_ps(v162, v162, 201), v161));
          _RSI[v156].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v163, v163), *v157);
          v164 = v157[1];
          v165 = v7[v156].m_rotation.m_vec.m_quad;
          v166 = _mm_shuffle_ps(v157[1], v157[1], 255);
          v167 = _mm_mul_ps(_mm_shuffle_ps(v164, v164, 201), v165);
          v168 = _mm_shuffle_ps(v7[v156].m_rotation.m_vec.m_quad, v7[v156].m_rotation.m_vec.m_quad, 255);
          v169 = _mm_mul_ps(_mm_shuffle_ps(v165, v165, 201), v164);
          v170 = _mm_mul_ps(v164, v165);
          v171 = _mm_sub_ps(v169, v167);
          v172 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v171, v171, 201), _mm_mul_ps(v7[v156].m_rotation.m_vec.m_quad, v166)),
                   _mm_mul_ps(v157[1], v168));
          _RSI[v156].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                 v172,
                                                 _mm_unpackhi_ps(
                                                   v172,
                                                   _mm_sub_ps(
                                                     _mm_mul_ps(v168, v166),
                                                     _mm_add_ps(
                                                       _mm_add_ps(
                                                         _mm_shuffle_ps(v170, v170, 85),
                                                         _mm_shuffle_ps(v170, v170, 0)),
                                                       _mm_shuffle_ps(v170, v170, 170)))),
                                                 196);
          _RSI[v156].m_scale.m_quad = _mm_mul_ps(v157[2], v7[v156].m_scale.m_quad);
        }
        ++v18;
      }
      while ( v18 < v153 );
    }
  }
  v174 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v175 = (_QWORD *)v174[1];
  v176 = v174;
  if ( (unsigned __int64)v175 < v174[3] )
  {
    *v175 = "StenforceConstraints";
    v177 = __rdtsc();
    v178 = (signed __int64)(v175 + 2);
    *(_DWORD *)(v178 - 8) = v177;
    v176[1] = v178;
  }
  if ( v199 == 1 )
  {
    hkaSkeletonUtils::enforceSkeletonConstraintsModelSpace(v5->m_mapping.m_skeletonB.m_pntr, _RSI);
  }
  else if ( v199 == 2 )
  {
    hkaSkeletonUtils::enforcePoseConstraintsModelSpace(v5->m_mapping.m_skeletonB.m_pntr, v7, _RSI);
  }
  v179 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v180 = (_QWORD *)v179[1];
  v181 = v179;
  if ( (unsigned __int64)v180 < v179[3] )
  {
    *v180 = "lt";
    v182 = __rdtsc();
    v183 = (signed __int64)(v180 + 2);
    *(_DWORD *)(v183 - 8) = v182;
    v181[1] = v183;
  }
}d __int64)(v180 + 2);
    *(_DWORD *)(v183 - 8) = v182;
    v181[1] = v183;
  }
}

// File Line: 275
// RVA: 0xB21950
void __fastcall hkaSkeletonMapper::mapPoseLocalSpace(hkaSkeletonMapper *this, hkQsTransformf *poseALocalSpace, hkQsTransformf *poseBLocalSpaceInOut, bool additive)
{
  hkaSkeletonMapper::mapPoseLocalSpace(this, poseALocalSpace, poseBLocalSpaceInOut, 0i64, 0i64, additive, 0i64, 0i64);
}

// File Line: 289
// RVA: 0xB22E20
void __usercall hkaSkeletonMapper::mapPoseLocalSpaceInternal(hkaSkeletonMapperData *mapping@<rcx>, hkQsTransformf *poseALocalSpaceOriginal@<rdx>, hkQsTransformf *poseBLocalSpaceInOut@<r8>, const __int16 *boneToTrackIndicesA@<r9>, hkQsTransformf *a5@<rbx>, const __int16 *boneToTrackIndicesB, hkArray<short,hkContainerHeapAllocator> *partitionIndicesA, bool additive, __int64 mapToFullPose, const float *weightsA, float *weightsBOut)
{
  hkaSkeletonMapperData *v11; // r15
  hkQsTransformf *v12; // rdi
  hkQsTransformf *v13; // rbx
  _QWORD *v14; // r8
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rax
  __int64 v17; // r12
  int v18; // esi
  LPVOID v19; // rax
  hkLifoAllocator *v20; // rcx
  hkaSkeleton::Partition *v21; // rax
  int v22; // edx
  char *v23; // r8
  hkaSkeleton *v24; // rcx
  int v25; // esi
  int v26; // edx
  hkLifoAllocator *v27; // rax
  char *v28; // r8
  int v29; // edx
  char *v30; // rcx
  char *v31; // rax
  int v32; // er14
  __int64 v33; // r8
  signed __int64 v34; // rsi
  __int64 v35; // rbx
  _QWORD *v36; // r8
  _QWORD *v37; // rcx
  unsigned __int64 v38; // rax
  signed __int64 v39; // rcx
  __int16 v40; // si
  __int16 v41; // r12
  hkaSkeleton *v42; // rax
  LPVOID v43; // rax
  int v44; // edx
  char *v45; // rcx
  __int16 v46; // cx
  int v47; // er14
  LPVOID v48; // rax
  hkLifoAllocator *v49; // rcx
  const float *v50; // rax
  int v51; // edx
  char *v52; // r8
  const float *v53; // r12
  hkQsTransformf *v54; // rcx
  bool v55; // r14
  hkQsTransformf *v56; // rsi
  __int64 v57; // rsi
  int v58; // ebx
  hkLifoAllocator *v59; // rax
  int v60; // edi
  char *v61; // rbx
  int v62; // er12
  char *v63; // rcx
  const __int16 *v64; // r14
  int v65; // edi
  hkaSkeleton *v66; // r9
  __int64 v67; // rsi
  int v68; // er10
  signed __int64 v69; // rdx
  int v70; // er8
  signed __int64 v71; // r11
  signed __int64 v72; // rdx
  int v73; // edx
  int v74; // er9
  signed __int64 v75; // rcx
  __int64 v76; // rcx
  __int16 *v77; // rax
  __int64 v78; // rsi
  __int64 v79; // rcx
  __int64 v80; // rdi
  signed __int64 v81; // rdx
  hkaSkeleton *v82; // rax
  signed __int64 v83; // r11
  hkaSkeletonMapperData::PartitionMappingRange *v84; // rax
  __int64 v85; // r8
  __int64 v86; // rcx
  signed __int64 v87; // r12
  signed __int64 v88; // rsi
  __int64 v91; // r11
  bool v92; // cl
  __int64 v93; // rbx
  __int64 v94; // r10
  __int64 v95; // r11
  __int64 v97; // rsi
  bool v99; // zf
  hkaSkeletonMapperData::PartitionMappingRange *v100; // rax
  signed __int64 v101; // r14
  signed __int64 v102; // r14
  hkaSkeletonMapperData::ChainMapping *v103; // r12
  __m128 v104; // xmm6
  __m128 v105; // xmm7
  int v106; // esi
  int v107; // ecx
  int v108; // eax
  int v109; // ecx
  int v110; // eax
  __int64 v111; // r10
  signed __int64 v112; // rcx
  __m128 v113; // xmm3
  __m128 v114; // xmm2
  __m128 v115; // xmm5
  __m128 v116; // xmm4
  __m128 v117; // xmm1
  bool v118; // sf
  unsigned __int8 v119; // of
  __m128 v120; // xmm6
  __m128 v121; // xmm1
  __m128 v122; // xmm4
  __m128 v123; // xmm2
  int v124; // eax
  __int64 v125; // r10
  __int16 v126; // r10
  signed int v127; // esi
  __m128 v128; // xmm8
  __int16 v129; // r10
  __m128 *v130; // rax
  __m128 v131; // xmm2
  __m128 v132; // xmm1
  __m128 v133; // xmm5
  __m128 v134; // xmm6
  __m128 v135; // xmm4
  __m128 v136; // xmm4
  __m128 v137; // xmm4
  hkaSkeleton *v138; // rax
  int v139; // edi
  __int64 v140; // r11
  __int64 v141; // rsi
  int v142; // ebx
  bool v143; // cl
  bool v144; // cl
  int v145; // eax
  int v146; // edx
  bool v147; // cl
  int v148; // er11
  int v149; // eax
  hkaSkeletonMapperData::MappingType v150; // ecx
  __int64 v151; // r10
  __m128 v152; // xmm1
  __m128 v153; // xmm4
  float v154; // xmm1_4
  __m128 v155; // xmm7
  __m128 v156; // xmm6
  __m128 v157; // xmm2
  __m128 v158; // xmm11
  __m128 v159; // xmm8
  __m128 v160; // xmm7
  __m128 v161; // xmm7
  __m128 v162; // xmm1
  __m128 v163; // xmm5
  __m128 v164; // xmm2
  __m128 v165; // xmm4
  __m128 v166; // xmm3
  __m128 v167; // xmm7
  __m128 v168; // xmm1
  __int64 v169; // rdx
  __m128 v170; // xmm2
  __m128 v171; // xmm6
  __m128 v172; // xmm3
  __m128 v173; // xmm6
  __m128 v174; // xmm0
  __m128 v175; // xmm7
  __m128 v176; // xmm6
  __m128 v177; // xmm0
  __m128 v178; // xmm6
  __m128 v179; // xmm4
  __m128 v180; // xmm5
  __m128 v181; // xmm0
  __m128 v182; // xmm6
  __m128 v183; // xmm5
  __m128 v184; // xmm6
  __m128 v185; // xmm2
  __m128 v186; // xmm4
  __m128 v187; // xmm5
  __m128 v188; // xmm3
  __m128 v189; // xmm6
  __m128 v190; // xmm3
  __int16 v191; // r10
  __m128 v192; // xmm1
  __m128 v193; // xmm6
  __m128 v194; // xmm1
  __m128 v195; // xmm2
  __m128 i; // xmm7
  __int16 v197; // r10
  hkLifoAllocator *v198; // rax
  int v199; // er8
  __int64 v200; // r10
  int v201; // eax
  __int64 v202; // r13
  __int64 v205; // rdx
  __int64 v206; // r9
  __int64 v207; // rsi
  __int64 v209; // rbx
  _QWORD *v211; // r8
  _QWORD *v212; // rcx
  unsigned __int64 v213; // rax
  signed __int64 v214; // rcx
  __int64 v215; // rcx
  const float *v216; // r13
  hkQsTransformf *v217; // r9
  __int64 v218; // rbx
  hkaSkeletonMapperData::ChainMapping *v219; // rdi
  __m128 v220; // xmm6
  char v221; // r10
  int v222; // er11
  int v223; // edx
  __m128 v224; // xmm7
  __int16 v225; // cx
  __m128 *v226; // rcx
  __m128 v227; // xmm3
  __m128 v228; // xmm2
  __m128 v229; // xmm5
  __m128 v230; // xmm4
  __m128 v231; // xmm6
  __m128 v232; // xmm1
  __m128 v233; // xmm4
  __m128 v234; // xmm2
  hkQsTransformf *v235; // r10
  __int16 v236; // dx
  signed int v237; // er9
  __m128 v238; // xmm8
  __int16 v239; // cx
  __m128 *v240; // rcx
  __m128 v241; // xmm2
  hkaSkeleton *v242; // rax
  __m128 v243; // xmm1
  __m128 v244; // xmm5
  __m128 v245; // xmm6
  __m128 v246; // xmm4
  __int64 v247; // rcx
  __int64 v248; // rdx
  __int64 v249; // r9
  hkaSkeletonMapperData::MappingType v250; // ecx
  __m128 v251; // xmm1
  __m128 v252; // xmm4
  float v253; // xmm1_4
  __m128 v254; // xmm7
  __m128 v255; // xmm6
  __m128 v256; // xmm2
  __m128 v257; // xmm11
  __m128 v258; // xmm8
  __m128 v259; // xmm7
  __m128 v260; // xmm7
  __m128 v261; // xmm1
  __m128 v262; // xmm5
  __m128 v263; // xmm2
  __m128 v264; // xmm4
  __m128 v265; // xmm3
  __m128 v266; // xmm7
  __m128 v267; // xmm1
  __m128 v268; // xmm2
  __m128 v269; // xmm6
  __m128 v270; // xmm3
  __m128 v271; // xmm6
  __m128 v272; // xmm0
  __m128 v273; // xmm7
  __m128 v274; // xmm6
  __m128 v275; // xmm0
  __m128 v276; // xmm6
  __m128 v277; // xmm4
  __m128 v278; // xmm5
  __m128 v279; // xmm0
  __m128 v280; // xmm6
  __m128 v281; // xmm5
  __m128 v282; // xmm6
  __m128 v283; // xmm2
  __m128 v284; // xmm4
  __m128 v285; // xmm5
  __m128 v286; // xmm3
  __m128 v287; // xmm6
  __m128 v288; // xmm3
  __int16 v289; // cx
  __m128 v290; // xmm1
  __m128 v291; // xmm2
  __m128 v292; // xmm1
  __m128 v293; // xmm0
  __m128 v294; // xmm3
  __int16 v295; // dx
  signed int v296; // ebx
  hkLifoAllocator *v297; // rax
  int v298; // er8
  _QWORD *v299; // r8
  _QWORD *v300; // rcx
  unsigned __int64 v301; // rax
  signed __int64 v302; // rcx
  signed int v303; // ebx
  hkLifoAllocator *v304; // rax
  int v305; // er8
  char *v306; // rsi
  int v307; // edi
  hkStringPtr *v308; // rbx
  signed int v309; // ebx
  hkLifoAllocator *v310; // rax
  int v311; // er8
  int v312; // edi
  hkStringPtr *v313; // rbx
  char *v314; // rsi
  int v315; // edi
  hkaSkeleton::Partition *v316; // rbx
  signed int v317; // ebx
  hkLifoAllocator *v318; // rax
  int v319; // er8
  int v320; // edi
  hkaSkeleton::Partition *v321; // rbx
  bool v322; // [rsp+30h] [rbp-C8h]
  signed __int64 v323; // [rsp+38h] [rbp-C0h]
  __int64 v324; // [rsp+38h] [rbp-C0h]
  int v325; // [rsp+40h] [rbp-B8h]
  signed int v326; // [rsp+40h] [rbp-B8h]
  __int16 v327; // [rsp+44h] [rbp-B4h]
  hkQsTransformf *v328; // [rsp+48h] [rbp-B0h]
  __int64 v329; // [rsp+50h] [rbp-A8h]
  int v330; // [rsp+50h] [rbp-A8h]
  int v331; // [rsp+58h] [rbp-A0h]
  __int64 v332; // [rsp+60h] [rbp-98h]
  __int64 v333; // [rsp+60h] [rbp-98h]
  __int64 v334; // [rsp+60h] [rbp-98h]
  unsigned int v335; // [rsp+68h] [rbp-90h]
  char *array; // [rsp+70h] [rbp-88h]
  void *p; // [rsp+78h] [rbp-80h]
  int v338; // [rsp+80h] [rbp-78h]
  __int64 v339; // [rsp+88h] [rbp-70h]
  hkVector4f B; // [rsp+98h] [rbp-60h]
  char *v341; // [rsp+A8h] [rbp-50h]
  const float *v342; // [rsp+B0h] [rbp-48h]
  __int64 v343; // [rsp+B8h] [rbp-40h]
  int numBones; // [rsp+C0h] [rbp-38h]
  __int64 v345; // [rsp+C8h] [rbp-30h]
  hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> partitionsOut; // [rsp+D0h] [rbp-28h]
  void *v347; // [rsp+E0h] [rbp-18h]
  int v348; // [rsp+E8h] [rbp-10h]
  __int64 v349; // [rsp+F0h] [rbp-8h]
  __int64 v350; // [rsp+F8h] [rbp+0h]
  hkQsTransformf *combinedPoseOut; // [rsp+100h] [rbp+8h]
  hkVector4f A; // [rsp+108h] [rbp+10h]
  hkQuaternionf v353; // [rsp+118h] [rbp+20h]
  int v354; // [rsp+128h] [rbp+30h]
  int v355; // [rsp+12Ch] [rbp+34h]
  hkQsTransformf *v356; // [rsp+130h] [rbp+38h]
  signed int retaddr; // [rsp+1F8h] [rbp+100h]
  hkQsTransformf *additivePoseOut; // [rsp+208h] [rbp+110h]
  hkQsTransformf *boneToTrackIndices; // [rsp+210h] [rbp+118h]
  int boneToTrackIndicesa; // [rsp+210h] [rbp+118h]
  __int16 *v361; // [rsp+218h] [rbp+120h]
  int boneToTrackIndicesBa; // [rsp+220h] [rbp+128h]
  int boneToTrackIndicesBb; // [rsp+220h] [rbp+128h]

  v361 = (__int16 *)boneToTrackIndicesA;
  boneToTrackIndices = poseBLocalSpaceInOut;
  additivePoseOut = a5;
  v11 = mapping;
  v12 = poseBLocalSpaceInOut;
  v13 = poseALocalSpaceOriginal;
  v328 = poseALocalSpaceOriginal;
  v14 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = v14[1];
  if ( v15 < v14[3] )
  {
    *(_QWORD *)v15 = "LtMapPoseLocalSpace";
    *(_QWORD *)(v15 + 16) = "Stinit";
    v16 = __rdtsc();
    *(_DWORD *)(v15 + 8) = v16;
    v14[1] = v15 + 24;
  }
  v17 = 0i64;
  partitionsOut.m_capacityAndFlags = 2147483648;
  v18 = *((_DWORD *)boneToTrackIndicesB + 2);
  partitionsOut.m_data = 0i64;
  partitionsOut.m_size = 0;
  v348 = v18;
  if ( v18 )
  {
    v19 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v20 = (hkLifoAllocator *)v19;
    v21 = (hkaSkeleton::Partition *)*((_QWORD *)v19 + 3);
    v22 = (16 * v18 + 127) & 0xFFFFFF80;
    v23 = (char *)v21 + v22;
    if ( v22 > v20->m_slabSize || v23 > v20->m_end )
      v21 = (hkaSkeleton::Partition *)hkLifoAllocator::allocateFromNewSlab(v20, v22);
    else
      v20->m_cur = v23;
  }
  else
  {
    v21 = 0i64;
  }
  v24 = v11->m_skeletonA.m_pntr;
  partitionsOut.m_data = v21;
  partitionsOut.m_capacityAndFlags = v18 | 0x80000000;
  v347 = v21;
  hkaPartitionedAnimationUtility::getPartitionsFromIndices(
    v24,
    (hkArray<short,hkContainerHeapAllocator> *)boneToTrackIndicesB,
    &partitionsOut);
  v25 = *((_DWORD *)boneToTrackIndicesB + 2);
  v26 = 0;
  array = 0i64;
  v338 = v25;
  p = (void *)0x8000000000000000i64;
  if ( v25 )
  {
    v27 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v28 = (char *)v27->m_cur;
    v29 = (16 * v25 + 127) & 0xFFFFFF80;
    v30 = &v28[v29];
    if ( v29 > v27->m_slabSize || v30 > v27->m_end )
    {
      v31 = (char *)hkLifoAllocator::allocateFromNewSlab(v27, v29);
      v26 = (signed int)p;
      array = v31;
    }
    else
    {
      v27->m_cur = v30;
      v26 = (signed int)p;
      array = v28;
    }
  }
  else
  {
    array = 0i64;
  }
  v32 = 0;
  p = array;
  HIDWORD(p) = v25 | 0x80000000;
  if ( *((_DWORD *)boneToTrackIndicesB + 2) > 0 )
  {
    do
    {
      v33 = v11->m_partitionMap.m_data[*(signed __int16 *)(*(_QWORD *)boneToTrackIndicesB + v17)];
      if ( (signed int)v33 >= 0 )
      {
        v34 = (signed __int64)&v11->m_skeletonB.m_pntr->m_partitions.m_data[v33];
        if ( v26 == (HIDWORD(p) & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
          v26 = (signed int)p;
        }
        v35 = (__int64)&array[16 * v26];
        if ( v35 )
        {
          hkStringPtr::hkStringPtr((hkStringPtr *)v35, (hkStringPtr *)v34);
          *(_WORD *)(v35 + 8) = *(_WORD *)(v34 + 8);
          *(_WORD *)(v35 + 10) = *(_WORD *)(v34 + 10);
          v26 = (signed int)p;
        }
        LODWORD(p) = ++v26;
      }
      ++v32;
      v17 += 2i64;
    }
    while ( v32 < *((_DWORD *)boneToTrackIndicesB + 2) );
    v13 = v328;
  }
  v36 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v37 = (_QWORD *)v36[1];
  if ( (unsigned __int64)v37 < v36[3] )
  {
    *v37 = "StsimpleMappings";
    v38 = __rdtsc();
    v39 = (signed __int64)(v37 + 2);
    *(_DWORD *)(v39 - 8) = v38;
    v36[1] = v39;
  }
  v322 = *((_DWORD *)boneToTrackIndicesB + 2) == 0;
  if ( v322 || additive )
  {
    v40 = v11->m_skeletonA.m_pntr->m_bones.m_size;
    if ( *((_DWORD *)boneToTrackIndicesB + 2) == 0 || additive )
    {
      v42 = v11->m_skeletonB.m_pntr;
      v41 = v42->m_bones.m_size;
      v327 = v42->m_bones.m_size;
      goto LABEL_33;
    }
  }
  else
  {
    v40 = hkaPartitionedAnimationUtility::getNumberOfBonesInPartitions(&partitionsOut);
  }
  v41 = hkaPartitionedAnimationUtility::getNumberOfBonesInPartitions((hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> *)&array);
  v327 = v41;
LABEL_33:
  numBones = v40;
  v43 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  combinedPoseOut = (hkQsTransformf *)*((_QWORD *)v43 + 3);
  v44 = (48 * v40 + 127) & 0xFFFFFF80;
  v45 = (char *)combinedPoseOut + v44;
  if ( v44 > *((_DWORD *)v43 + 4) || (unsigned __int64)v45 > *((_QWORD *)v43 + 4) )
    combinedPoseOut = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab((hkLifoAllocator *)v43, v44);
  else
    *((_QWORD *)v43 + 3) = v45;
  v331 = 0;
  if ( weightsA )
  {
    v53 = (const float *)mapToFullPose;
  }
  else
  {
    v46 = v41;
    if ( v40 > v41 )
      v46 = v40;
    v47 = v46;
    v331 = v46;
    v48 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v49 = (hkLifoAllocator *)v48;
    v50 = (const float *)*((_QWORD *)v48 + 3);
    v51 = (4 * v47 + 127) & 0xFFFFFF80;
    weightsA = v50;
    v52 = (char *)v50 + v51;
    if ( v51 > v49->m_slabSize || v52 > v49->m_end )
    {
      weightsA = (const float *)hkLifoAllocator::allocateFromNewSlab(v49, v51);
      v53 = weightsA;
    }
    else
    {
      v49->m_cur = v52;
      v53 = v50;
    }
  }
  v54 = boneToTrackIndices;
  v342 = v53;
  v55 = boneToTrackIndices && v361;
  LOBYTE(retaddr) = v55;
  if ( (_BYTE)partitionIndicesA )
  {
    v56 = combinedPoseOut;
    hkaSkeletonMapper::combinedPoseFromAdditivePoseAndReferencePose(
      v13,
      v11->m_skeletonA.m_pntr->m_referencePose.m_data,
      (const __int16 *)boneToTrackIndices,
      0,
      numBones,
      combinedPoseOut);
    v54 = boneToTrackIndices;
    v13 = v56;
    v328 = v56;
  }
  v57 = v331;
  v343 = v331;
  if ( v322 )
  {
    v200 = v11->m_simpleMappings.m_size;
    v201 = 0;
    boneToTrackIndicesBa = 0;
    v333 = v200;
    if ( v200 <= 0 )
      goto LABEL_115;
    v202 = 0i64;
    while ( 1 )
    {
      _R8 = v11->m_simpleMappings.m_data;
      _RAX = (v201 + 2i64) << 6;
      __asm { prefetchnta byte ptr [rax+r8]; Prefetch to L1 cache }
      v205 = _R8[v202].m_boneA;
      v206 = _R8[v202].m_boneB;
      if ( !v55 )
        goto LABEL_112;
      LODWORD(v205) = v54->m_translation.m_quad.m128_i16[v205];
      if ( (signed int)v205 >= 0 )
        break;
LABEL_113:
      ++v202;
      v201 = boneToTrackIndicesBa + 1;
      v333 = --v200;
      ++boneToTrackIndicesBa;
      if ( !v200 )
      {
        v57 = v343;
LABEL_115:
        v211 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v212 = (_QWORD *)v211[1];
        if ( (unsigned __int64)v212 < v211[3] )
        {
          *v212 = "StchainMappings";
          v213 = __rdtsc();
          v214 = (signed __int64)(v212 + 2);
          *(_DWORD *)(v214 - 8) = v213;
          v211[1] = v214;
        }
        v215 = v11->m_chainMappings.m_size;
        v324 = v215;
        if ( v215 <= 0 )
          goto LABEL_164;
        v216 = weightsA;
        v217 = boneToTrackIndices;
        v218 = 0i64;
        while ( 2 )
        {
          v219 = v11->m_chainMappings.m_data;
          B.m_quad = 0i64;
          v220 = 0i64;
          v221 = 1;
          v222 = v219[v218].m_startBoneA;
          v223 = v219[v218].m_endBoneA;
          v353.m_vec.m_quad = 0i64;
          v224 = 0i64;
          if ( v223 > v222 )
          {
            while ( 1 )
            {
              v225 = v55 ? v217->m_translation.m_quad.m128_i16[(signed __int16)v223] : (_WORD)v223;
              if ( v225 < 0 || !v57 && 0.0 == v53[(signed __int16)v223] )
                break;
              v226 = &v328[v225].m_translation.m_quad;
              v227 = v226[1];
              v228 = _mm_mul_ps(v226[1], v220);
              v229 = _mm_shuffle_ps(v226[1], v227, 255);
              v230 = _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v220, v220, 201), v227),
                       _mm_mul_ps(_mm_shuffle_ps(v227, v227, 201), v220));
              v223 = v11->m_skeletonA.m_pntr->m_parentIndices.m_data[(signed __int16)v223];
              v231 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v228, v228, 85), _mm_shuffle_ps(v228, v228, 0)),
                             _mm_shuffle_ps(v228, v228, 170)),
                           v227),
                         _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v229, v229), (__m128)xmmword_141A711B0), v220)),
                       _mm_mul_ps(_mm_shuffle_ps(v230, v230, 201), v229));
              v220 = _mm_add_ps(_mm_add_ps(v231, v231), *v226);
              v232 = _mm_mul_ps(*v226, *v226);
              v353.m_vec.m_quad = v220;
              v233 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v232, v232, 85), _mm_shuffle_ps(v232, v232, 0)),
                       _mm_shuffle_ps(v232, v232, 170));
              v234 = _mm_rsqrt_ps(v233);
              v224 = _mm_add_ps(
                       v224,
                       _mm_andnot_ps(
                         _mm_cmpleps(v233, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v234, v233), v234)),
                             _mm_mul_ps(*(__m128 *)_xmm, v234)),
                           v233)));
              if ( v223 <= v222 )
                goto LABEL_129;
            }
            v221 = 0;
LABEL_129:
            v215 = v324;
          }
          if ( v55 )
          {
            if ( v221 )
            {
              v235 = boneToTrackIndices;
              if ( boneToTrackIndices->m_translation.m_quad.m128_i16[(signed __int16)v222] >= 0
                && (v57 > 0 || 0.0 != v53[(signed __int16)v222]) )
              {
LABEL_138:
                v236 = v219[v218].m_endBoneB;
                v237 = 1;
                v326 = 1;
                v238 = _mm_mul_ps(v219[v218].m_endAFromBTransform.m_scale.m_quad, v224);
                if ( v236 > v219[v218].m_startBoneB )
                {
                  do
                  {
                    if ( v55 )
                      v239 = v361[v236];
                    else
                      v239 = v236;
                    ++v237;
                    v240 = &additivePoseOut[v239].m_translation.m_quad;
                    *v240 = _mm_mul_ps(v238, *v240);
                    v241 = v240[1];
                    v242 = v11->m_skeletonB.m_pntr;
                    v243 = _mm_mul_ps(v240[1], B.m_quad);
                    v244 = _mm_sub_ps(
                             _mm_mul_ps(_mm_shuffle_ps(B.m_quad, B.m_quad, 201), v241),
                             _mm_mul_ps(_mm_shuffle_ps(v241, v241, 201), B.m_quad));
                    v245 = _mm_shuffle_ps(v240[1], v241, 255);
                    v246 = _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v243, v243, 85), _mm_shuffle_ps(v243, v243, 0)),
                                   _mm_shuffle_ps(v243, v243, 170)),
                                 v241),
                               _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v245, v245), (__m128)xmmword_141A711B0), B.m_quad)),
                             _mm_mul_ps(_mm_shuffle_ps(v244, v244, 201), v245));
                    B.m_quad = _mm_add_ps(v246, v246);
                    B.m_quad = _mm_add_ps(B.m_quad, *v240);
                    v236 = v242->m_parentIndices.m_data[v236];
                  }
                  while ( v236 > v219[v218].m_startBoneB );
                  v216 = weightsA;
                  v326 = v237;
                }
                v247 = v219[v218].m_startBoneA;
                v248 = v219[v218].m_startBoneB;
                boneToTrackIndicesBb = v219[v218].m_endBoneA;
                retaddr = v219[v218].m_endBoneB;
                if ( v55 )
                {
                  LODWORD(v247) = v235->m_translation.m_quad.m128_i16[v247];
                  LODWORD(v248) = v361[v248];
                  boneToTrackIndicesBb = v235->m_translation.m_quad.m128_i16[v219[v218].m_endBoneA];
                  retaddr = v361[v219[v218].m_endBoneB];
                }
                v249 = (signed int)v247;
                v250 = v11->m_mappingType.m_storage;
                v334 = v249;
                v356 = &additivePoseOut[(signed int)v248];
                hkaSkeletonMapper::setMulWithScaling(v250, v356, &v219[v218].m_startAFromBTransform, &v328[v249]);
                normalize3TwoAtOnce(&v353.m_vec, &B);
                v251 = _mm_mul_ps(B.m_quad, v353.m_vec.m_quad);
                v252 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v251, v251, 85), _mm_shuffle_ps(v251, v251, 0)),
                         _mm_shuffle_ps(v251, v251, 170));
                LODWORD(v253) = (unsigned __int128)_mm_shuffle_ps((__m128)0x3F7FFF58u, (__m128)0x3F7FFF58u, 0);
                if ( v252.m128_f32[0] > v253 )
                {
                  v254 = qi.m_vec.m_quad;
                  goto LABEL_153;
                }
                if ( v252.m128_f32[0] >= (float)(0.0 - v253) )
                {
                  v255 = _mm_add_ps(_mm_mul_ps(v252, (__m128)xmmword_141A711B0), (__m128)xmmword_141A711B0);
                  v256 = _mm_rsqrt_ps(v255);
                  v257 = _mm_andnot_ps(
                           _mm_cmpleps(v255, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v255, v256), v256)),
                             _mm_mul_ps(*(__m128 *)_xmm, v256)));
                  v258 = _mm_mul_ps(v257, (__m128)xmmword_141A711B0);
                  v259 = _mm_sub_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v353.m_vec.m_quad, v353.m_vec.m_quad, 201), B.m_quad),
                           _mm_mul_ps(_mm_shuffle_ps(B.m_quad, B.m_quad, 201), v353.m_vec.m_quad));
                  v260 = _mm_shuffle_ps(v259, v259, 201);
                  if ( v252.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)0xBF7FBE77, (__m128)0xBF7FBE77, 0)) )
                  {
                    v261 = _mm_mul_ps(v260, v260);
                    v262 = _mm_sub_ps(v255, v252);
                    v263 = _mm_rsqrt_ps(v262);
                    v264 = _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v261, v261, 85), _mm_shuffle_ps(v261, v261, 0)),
                             _mm_shuffle_ps(v261, v261, 170));
                    v265 = _mm_rsqrt_ps(v264);
                    v258 = _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_andnot_ps(
                                 _mm_cmpleps(v262, (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v263, v262), v263)),
                                   _mm_mul_ps(*(__m128 *)_xmm, v263))),
                               v262),
                             _mm_andnot_ps(
                               _mm_cmpleps(v264, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v265, v264), v265)),
                                 _mm_mul_ps(*(__m128 *)_xmm, v265))));
                  }
                  v266 = _mm_mul_ps(v260, v258);
                  v254 = _mm_shuffle_ps(v266, _mm_unpackhi_ps(v266, _mm_mul_ps(v255, v257)), 196);
LABEL_153:
                  A.m_quad = v254;
                }
                else
                {
                  hkQuaternionf::setFlippedRotation((hkQuaternionf *)&A, &B);
                  v254 = A.m_quad;
                }
                v267 = v219[v218].m_endAFromBTransform.m_translation.m_quad;
                v268 = v356->m_rotation.m_vec.m_quad;
                v269 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v254, v254, 201), v267),
                         _mm_mul_ps(_mm_shuffle_ps(v267, v267, 201), v254));
                v270 = _mm_shuffle_ps(v356->m_rotation.m_vec.m_quad, v356->m_rotation.m_vec.m_quad, 255);
                v271 = _mm_sub_ps(_mm_shuffle_ps(v269, v269, 201), _mm_mul_ps(_mm_shuffle_ps(v254, v254, 255), v267));
                v272 = _mm_mul_ps(_mm_shuffle_ps(v219[v218].m_endAFromBTransform.m_translation.m_quad, v267, 255), v254);
                v273 = _mm_mul_ps(v254, v267);
                v274 = _mm_add_ps(v271, v272);
                v275 = _mm_add_ps(_mm_shuffle_ps(v273, v273, 78), v273);
                v276 = _mm_shuffle_ps(
                         v274,
                         _mm_unpackhi_ps(v274, _mm_add_ps(_mm_shuffle_ps(v275, v275, 177), v275)),
                         196);
                v277 = _mm_shuffle_ps(v276, v276, 255);
                v278 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v276, v276, 201), v268),
                         _mm_mul_ps(_mm_shuffle_ps(v356->m_rotation.m_vec.m_quad, v268, 201), v276));
                v279 = _mm_mul_ps(v276, v270);
                v280 = _mm_mul_ps(v276, v268);
                v281 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v278, v278, 201), v279), _mm_mul_ps(v268, v277));
                v356->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                  v281,
                                                  _mm_unpackhi_ps(
                                                    v281,
                                                    _mm_sub_ps(
                                                      _mm_mul_ps(v277, v270),
                                                      _mm_add_ps(
                                                        _mm_add_ps(
                                                          _mm_shuffle_ps(v280, v280, 85),
                                                          _mm_shuffle_ps(v280, v280, 0)),
                                                        _mm_shuffle_ps(v280, v280, 170)))),
                                                  196);
                v282 = v219[v218].m_endAFromBTransform.m_rotation.m_vec.m_quad;
                v283 = v328[boneToTrackIndicesBb].m_rotation.m_vec.m_quad;
                v284 = _mm_shuffle_ps(
                         v219[v218].m_endAFromBTransform.m_rotation.m_vec.m_quad,
                         v219[v218].m_endAFromBTransform.m_rotation.m_vec.m_quad,
                         255);
                v285 = _mm_shuffle_ps(v283, v283, 255);
                v286 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v283, v283, 201), v282),
                         _mm_mul_ps(_mm_shuffle_ps(v282, v282, 201), v283));
                v287 = _mm_mul_ps(v282, v283);
                v288 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v286, v286, 201), _mm_mul_ps(v283, v284)),
                         _mm_mul_ps(v219[v218].m_endAFromBTransform.m_rotation.m_vec.m_quad, v285));
                additivePoseOut[retaddr].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                                     v288,
                                                                     _mm_unpackhi_ps(
                                                                       v288,
                                                                       _mm_sub_ps(
                                                                         _mm_mul_ps(v285, v284),
                                                                         _mm_add_ps(
                                                                           _mm_add_ps(
                                                                             _mm_shuffle_ps(v287, v287, 85),
                                                                             _mm_shuffle_ps(v287, v287, 0)),
                                                                           _mm_shuffle_ps(v287, v287, 170)))),
                                                                     196);
                if ( !v57 )
                {
                  v289 = v219[v218].m_endBoneB;
                  v290 = 0i64;
                  v291 = _mm_shuffle_ps(
                           (__m128)LODWORD(v53[boneToTrackIndicesBb]),
                           (__m128)LODWORD(v53[boneToTrackIndicesBb]),
                           0);
                  v290.m128_f32[0] = (float)(v326 - 1);
                  v292 = _mm_shuffle_ps(v290, v290, 0);
                  v293 = _mm_rcp_ps(v292);
                  v294 = _mm_mul_ps(
                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v292, v293)), v293),
                           _mm_sub_ps(_mm_shuffle_ps((__m128)LODWORD(v53[v334]), (__m128)LODWORD(v53[v334]), 0), v291));
                  if ( v289 >= v219[v218].m_startBoneB )
                  {
                    do
                    {
                      if ( v55 )
                        v295 = v361[v289];
                      else
                        v295 = v289;
                      v216[v295] = v291.m128_f32[0];
                      v291 = _mm_add_ps(v291, v294);
                      v289 = v11->m_skeletonB.m_pntr->m_parentIndices.m_data[v289];
                    }
                    while ( v289 >= v219[v218].m_startBoneB );
                    v57 = v343;
                  }
                }
                v215 = v324;
              }
              v217 = boneToTrackIndices;
            }
          }
          else if ( v221 )
          {
            v235 = boneToTrackIndices;
            goto LABEL_138;
          }
          ++v218;
          v324 = --v215;
          if ( !v215 )
            goto LABEL_164;
          continue;
        }
      }
    }
    LODWORD(v206) = v361[v206];
LABEL_112:
    v207 = (signed int)v205;
    _R14 = &v13[(signed int)v205];
    v209 = (signed int)v206;
    _RDI = &v12[(signed int)v206];
    hkaSkeletonMapper::setMulWithScaling(
      (hkaSkeletonMapperData::MappingType)v11->m_mappingType.m_storage,
      _RDI,
      &_R8[v202].m_aFromBTransform,
      _R14);
    weightsA[v209] = v53[v207];
    __asm
    {
      prefetchnta byte ptr [r14+80h]; Prefetch to L1 cache
      prefetchnta byte ptr [rdi+80h]; Prefetch to L1 cache
    }
    v55 = retaddr;
    v12 = additivePoseOut;
    v13 = v328;
    v54 = boneToTrackIndices;
    v200 = v333;
    goto LABEL_113;
  }
  v58 = v11->m_skeletonB.m_pntr->m_partitions.m_size;
  v59 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v60 = 2 * v58;
  v61 = (char *)v59->m_cur;
  v62 = (v60 + 127) & 0xFFFFFF80;
  v341 = v61;
  v335 = (v60 + 127) & 0xFFFFFF80;
  v63 = &v61[v62];
  if ( v62 > v59->m_slabSize || v63 > v59->m_end )
  {
    v61 = (char *)hkLifoAllocator::allocateFromNewSlab(v59, v62);
    v341 = v61;
  }
  else
  {
    v59->m_cur = v63;
  }
  hkString::memSet(v61, 0, v60);
  v64 = boneToTrackIndicesB;
  v65 = 0;
  if ( *((_DWORD *)boneToTrackIndicesB + 2) > 0 )
  {
    v66 = v11->m_skeletonB.m_pntr;
    v67 = 0i64;
    v68 = v66->m_partitions.m_size;
    do
    {
      v69 = v11->m_partitionMap.m_data[*(signed __int16 *)(*(_QWORD *)boneToTrackIndicesB + v67)];
      v70 = v69 + 1;
      if ( (signed int)v69 + 1 < v68 )
      {
        v71 = v69;
        v72 = (signed __int64)&v61[2 * v70];
        do
        {
          ++v70;
          v72 += 2i64;
          *(_WORD *)(v72 - 2) += v66->m_partitions.m_data[v71].m_numBones;
          v66 = v11->m_skeletonB.m_pntr;
          v68 = v66->m_partitions.m_size;
        }
        while ( v70 < v68 );
      }
      ++v65;
      v67 += 2i64;
    }
    while ( v65 < *((_DWORD *)boneToTrackIndicesB + 2) );
  }
  v73 = 0;
  v74 = 0;
  boneToTrackIndicesa = 0;
  v325 = 0;
  if ( *((_DWORD *)boneToTrackIndicesB + 2) > 0 )
  {
    v75 = 0i64;
    v332 = 0i64;
    do
    {
      v76 = *(signed __int16 *)(*(_QWORD *)v64 + v75);
      v77 = v11->m_partitionMap.m_data;
      v78 = v76;
      v349 = v76;
      v79 = v77[v76];
      if ( (signed int)v79 >= 0 )
      {
        v80 = v79;
        v81 = (signed __int64)&v11->m_skeletonA.m_pntr->m_partitions.m_data[v78];
        v82 = v11->m_skeletonB.m_pntr;
        v339 = v79;
        v83 = (signed __int64)&v82->m_partitions.m_data[v79];
        v84 = v11->m_simpleMappingPartitionRanges.m_data;
        v323 = v81;
        v85 = v84[v78].m_numMappings;
        v86 = v84[v78].m_startMappingIndex;
        v345 = v83;
        retaddr = v86;
        v350 = v85;
        if ( v85 > 0 )
        {
          v87 = v83;
          v88 = v86 << 6;
          v329 = v86 << 6;
          do
          {
            _R11 = v11->m_simpleMappings.m_data;
            _RAX = ((signed int)v86 + 2i64) << 6;
            __asm { prefetchnta byte ptr [rax+r11]; Prefetch to L1 cache }
            getBoneIndexFromPartition(
              additive,
              *(__int16 *)((char *)&_R11->m_boneA + v88),
              *(signed __int16 *)(v81 + 8),
              v74);
            v93 = getBoneIndexFromPartition(
                    v92,
                    *(signed __int16 *)(v91 + v88 + 2),
                    *(signed __int16 *)(v87 + 8),
                    *(signed __int16 *)&v61[2 * v80]);
            _R14 = (signed __int64)&v328[v94];
            v97 = v94;
            _RDI = (signed __int64)&additivePoseOut[v93];
            hkaSkeletonMapper::setMulWithScaling(
              (hkaSkeletonMapperData::MappingType)v11->m_mappingType.m_storage,
              &additivePoseOut[v93],
              (hkQsTransformf *)(v95 + v329 + 16),
              &v328[v94]);
            weightsA[v93] = v342[v97];
            __asm
            {
              prefetchnta byte ptr [r14+80h]; Prefetch to L1 cache
              prefetchnta byte ptr [rdi+80h]; Prefetch to L1 cache
            }
            v61 = v341;
            v80 = v339;
            v74 = boneToTrackIndicesa;
            v81 = v323;
            LODWORD(v86) = retaddr + 1;
            v88 = v329 + 64;
            v99 = v350-- == 1;
            ++retaddr;
            v329 += 64i64;
          }
          while ( !v99 );
          v78 = v349;
          v83 = v87;
        }
        v100 = v11->m_chainMappingPartitionRanges.m_data;
        v101 = v100[v78].m_startMappingIndex;
        v349 = v100[v78].m_numMappings;
        if ( v349 > 0 )
        {
          v102 = v101;
          while ( 1 )
          {
            v103 = v11->m_chainMappings.m_data;
            B.m_quad = 0i64;
            v104 = 0i64;
            A.m_quad = 0i64;
            v105 = 0i64;
            v106 = v103[v102].m_endBoneA;
            v107 = v103[v102].m_startBoneA;
            v108 = v106;
            if ( v106 <= v107 )
              break;
            v109 = *(signed __int16 *)(v81 + 8);
            retaddr = *(signed __int16 *)(v81 + 8);
            while ( 1 )
            {
              v110 = getBoneIndexFromPartition(additive, v108, v109, v74);
              if ( v110 < 0 || !v343 && 0.0 == *(float *)(v111 + 4i64 * v110) )
                break;
              v112 = (signed __int64)&v328[v110];
              v113 = *(__m128 *)(v112 + 16);
              v114 = _mm_mul_ps(v104, v113);
              v115 = _mm_shuffle_ps(*(__m128 *)(v112 + 16), v113, 255);
              v116 = _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v104, v104, 201), v113),
                       _mm_mul_ps(_mm_shuffle_ps(v113, v113, 201), v104));
              v117 = *(__m128 *)v112;
              v106 = v11->m_skeletonA.m_pntr->m_parentIndices.m_data[(signed __int16)v106];
              LODWORD(v112) = v103[v102].m_startBoneA;
              v119 = __OFSUB__(v106, (_DWORD)v112);
              v99 = v106 == (_DWORD)v112;
              v118 = v106 - (signed int)v112 < 0;
              v109 = retaddr;
              v108 = v106;
              v120 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v114, v114, 85), _mm_shuffle_ps(v114, v114, 0)),
                             _mm_shuffle_ps(v114, v114, 170)),
                           v113),
                         _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v115, v115), (__m128)xmmword_141A711B0), v104)),
                       _mm_mul_ps(_mm_shuffle_ps(v116, v116, 201), v115));
              v104 = _mm_add_ps(_mm_add_ps(v120, v120), v117);
              v121 = _mm_mul_ps(v117, v117);
              A.m_quad = v104;
              v122 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v121, v121, 85), _mm_shuffle_ps(v121, v121, 0)),
                       _mm_shuffle_ps(v121, v121, 170));
              v123 = _mm_rsqrt_ps(v122);
              v105 = _mm_add_ps(
                       v105,
                       _mm_andnot_ps(
                         _mm_cmpleps(v122, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v123, v122), v123)),
                             _mm_mul_ps(*(__m128 *)_xmm, v123)),
                           v122)));
              if ( (unsigned __int8)(v118 ^ v119) | v99 )
              {
                v107 = v103[v102].m_startBoneA;
                goto LABEL_79;
              }
            }
LABEL_98:
            ++v102;
            if ( !--v349 )
              goto LABEL_99;
            v81 = v323;
          }
LABEL_79:
          if ( v343 <= 0 )
          {
            v124 = getBoneIndexFromPartition(additive, v107, *(signed __int16 *)(v323 + 8), v74);
            if ( 0.0 == *(float *)(v125 + 4i64 * v124) )
              goto LABEL_98;
          }
          v126 = v103[v102].m_endBoneB;
          v127 = 1;
          retaddr = 1;
          v128 = _mm_mul_ps(v103[v102].m_endAFromBTransform.m_scale.m_quad, v105);
          if ( v126 > v103[v102].m_startBoneB )
          {
            do
            {
              ++v127;
              v130 = &additivePoseOut[getBoneIndexFromPartition(
                                        additive,
                                        v126,
                                        *(signed __int16 *)(v83 + 8),
                                        *(signed __int16 *)&v61[2 * v80])].m_translation.m_quad;
              *v130 = _mm_mul_ps(*v130, v128);
              v131 = v130[1];
              v132 = _mm_mul_ps(B.m_quad, v131);
              v133 = _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(B.m_quad, B.m_quad, 201), v131),
                       _mm_mul_ps(_mm_shuffle_ps(v131, v131, 201), B.m_quad));
              v134 = _mm_shuffle_ps(v130[1], v131, 255);
              v135 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v132, v132, 85), _mm_shuffle_ps(v132, v132, 0)),
                             _mm_shuffle_ps(v132, v132, 170)),
                           v131),
                         _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v134, v134), (__m128)xmmword_141A711B0), B.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v133, v133, 201), v134));
              v136 = _mm_add_ps(v135, v135);
              B.m_quad = v136;
              v137 = _mm_add_ps(v136, *v130);
              v138 = v11->m_skeletonB.m_pntr;
              B.m_quad = v137;
              v126 = v138->m_parentIndices.m_data[v129];
            }
            while ( v126 > v103[v102].m_startBoneB );
            retaddr = v127;
          }
          v139 = *(signed __int16 *)(v323 + 8);
          v141 = getBoneIndexFromPartition(additive, v103[v102].m_startBoneA, v139, boneToTrackIndicesa);
          v142 = *(signed __int16 *)&v61[2 * v339];
          getBoneIndexFromPartition(v143, v103[v102].m_startBoneB, *(signed __int16 *)(v140 + 8), v142);
          v145 = getBoneIndexFromPartition(v144, v103[v102].m_endBoneA, v139, boneToTrackIndicesa);
          v146 = v103[v102].m_endBoneB;
          LODWORD(v350) = v145;
          v149 = getBoneIndexFromPartition(v147, v146, v148, v142);
          v150 = v11->m_mappingType.m_storage;
          v356 = &additivePoseOut[v151];
          v330 = v149;
          hkaSkeletonMapper::setMulWithScaling(
            v150,
            &additivePoseOut[v151],
            &v103[v102].m_startAFromBTransform,
            &v328[v141]);
          normalize3TwoAtOnce(&A, &B);
          v355 = 1065353048;
          v152 = _mm_mul_ps(B.m_quad, A.m_quad);
          v153 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v152, v152, 85), _mm_shuffle_ps(v152, v152, 0)),
                   _mm_shuffle_ps(v152, v152, 170));
          LODWORD(v154) = (unsigned __int128)_mm_shuffle_ps((__m128)0x3F7FFF58u, (__m128)0x3F7FFF58u, 0);
          if ( v153.m128_f32[0] > v154 )
          {
            v155 = qi.m_vec.m_quad;
            goto LABEL_91;
          }
          if ( v153.m128_f32[0] >= (float)(0.0 - v154) )
          {
            v354 = -1082147209;
            v156 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v153), (__m128)xmmword_141A711B0);
            v157 = _mm_rsqrt_ps(v156);
            v158 = _mm_andnot_ps(
                     _mm_cmpleps(v156, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v156, v157), v157)),
                       _mm_mul_ps(*(__m128 *)_xmm, v157)));
            v159 = _mm_mul_ps(v158, (__m128)xmmword_141A711B0);
            v160 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(A.m_quad, A.m_quad, 201), B.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(B.m_quad, B.m_quad, 201), A.m_quad));
            v161 = _mm_shuffle_ps(v160, v160, 201);
            if ( v153.m128_f32[0] < COERCE_FLOAT(_mm_shuffle_ps((__m128)0xBF7FBE77, (__m128)0xBF7FBE77, 0)) )
            {
              v162 = _mm_mul_ps(v161, v161);
              v163 = _mm_sub_ps(v156, v153);
              v164 = _mm_rsqrt_ps(v163);
              v165 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v162, v162, 85), _mm_shuffle_ps(v162, v162, 0)),
                       _mm_shuffle_ps(v162, v162, 170));
              v166 = _mm_rsqrt_ps(v165);
              v159 = _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmpleps(v163, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v164, v163), v164)),
                             _mm_mul_ps(*(__m128 *)_xmm, v164))),
                         v163),
                       _mm_andnot_ps(
                         _mm_cmpleps(v165, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v166, v165), v166)),
                           _mm_mul_ps(*(__m128 *)_xmm, v166))));
            }
            v167 = _mm_mul_ps(v161, v159);
            v155 = _mm_shuffle_ps(v167, _mm_unpackhi_ps(v167, _mm_mul_ps(v156, v158)), 196);
LABEL_91:
            v353.m_vec.m_quad = v155;
          }
          else
          {
            hkQuaternionf::setFlippedRotation(&v353, &B);
            v155 = v353.m_vec.m_quad;
          }
          v168 = v103[v102].m_endAFromBTransform.m_translation.m_quad;
          v169 = (signed int)v350;
          v170 = v356->m_rotation.m_vec.m_quad;
          v171 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v155, v155, 201), v168),
                   _mm_mul_ps(_mm_shuffle_ps(v168, v168, 201), v155));
          v172 = _mm_shuffle_ps(v356->m_rotation.m_vec.m_quad, v356->m_rotation.m_vec.m_quad, 255);
          v173 = _mm_sub_ps(_mm_shuffle_ps(v171, v171, 201), _mm_mul_ps(_mm_shuffle_ps(v155, v155, 255), v168));
          v174 = _mm_mul_ps(_mm_shuffle_ps(v103[v102].m_endAFromBTransform.m_translation.m_quad, v168, 255), v155);
          v175 = _mm_mul_ps(v155, v168);
          v176 = _mm_add_ps(v173, v174);
          v177 = _mm_add_ps(_mm_shuffle_ps(v175, v175, 78), v175);
          v178 = _mm_shuffle_ps(v176, _mm_unpackhi_ps(v176, _mm_add_ps(_mm_shuffle_ps(v177, v177, 177), v177)), 196);
          v179 = _mm_shuffle_ps(v178, v178, 255);
          v180 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v178, v178, 201), v170),
                   _mm_mul_ps(_mm_shuffle_ps(v356->m_rotation.m_vec.m_quad, v170, 201), v178));
          v181 = _mm_mul_ps(v178, v172);
          v182 = _mm_mul_ps(v178, v170);
          v183 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v180, v180, 201), v181), _mm_mul_ps(v170, v179));
          v356->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                            v183,
                                            _mm_unpackhi_ps(
                                              v183,
                                              _mm_sub_ps(
                                                _mm_mul_ps(v179, v172),
                                                _mm_add_ps(
                                                  _mm_add_ps(
                                                    _mm_shuffle_ps(v182, v182, 85),
                                                    _mm_shuffle_ps(v182, v182, 0)),
                                                  _mm_shuffle_ps(v182, v182, 170)))),
                                            196);
          v184 = v103[v102].m_endAFromBTransform.m_rotation.m_vec.m_quad;
          v185 = v328[v169].m_rotation.m_vec.m_quad;
          v186 = _mm_shuffle_ps(
                   v103[v102].m_endAFromBTransform.m_rotation.m_vec.m_quad,
                   v103[v102].m_endAFromBTransform.m_rotation.m_vec.m_quad,
                   255);
          v187 = _mm_shuffle_ps(v328[v169].m_rotation.m_vec.m_quad, v328[v169].m_rotation.m_vec.m_quad, 255);
          v188 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v185, v185, 201), v184),
                   _mm_mul_ps(_mm_shuffle_ps(v184, v184, 201), v185));
          v83 = v345;
          v189 = _mm_mul_ps(v184, v185);
          v99 = v343 == 0;
          v190 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v188, v188, 201), _mm_mul_ps(v328[v169].m_rotation.m_vec.m_quad, v186)),
                   _mm_mul_ps(v103[v102].m_endAFromBTransform.m_rotation.m_vec.m_quad, v187));
          additivePoseOut[v330].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                            v190,
                                                            _mm_unpackhi_ps(
                                                              v190,
                                                              _mm_sub_ps(
                                                                _mm_mul_ps(v187, v186),
                                                                _mm_add_ps(
                                                                  _mm_add_ps(
                                                                    _mm_shuffle_ps(v189, v189, 85),
                                                                    _mm_shuffle_ps(v189, v189, 0)),
                                                                  _mm_shuffle_ps(v189, v189, 170)))),
                                                            196);
          v61 = v341;
          if ( v99 )
          {
            v191 = v103[v102].m_endBoneB;
            v192 = 0i64;
            v193 = _mm_shuffle_ps((__m128)LODWORD(v342[v169]), (__m128)LODWORD(v342[v169]), 0);
            v192.m128_f32[0] = (float)(retaddr - 1);
            v194 = _mm_shuffle_ps(v192, v192, 0);
            v195 = _mm_rcp_ps(v194);
            v80 = v339;
            for ( i = _mm_mul_ps(
                        _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v195, v194)), v195),
                        _mm_sub_ps(_mm_shuffle_ps((__m128)LODWORD(v342[v141]), (__m128)LODWORD(v342[v141]), 0), v193));
                  v191 >= v103[v102].m_startBoneB;
                  v191 = v11->m_skeletonB.m_pntr->m_parentIndices.m_data[v197] )
            {
              weightsA[getBoneIndexFromPartition(
                         additive,
                         v191,
                         *(signed __int16 *)(v83 + 8),
                         *(signed __int16 *)&v61[2 * v80])] = v193.m128_f32[0];
              v193 = _mm_add_ps(v193, i);
            }
          }
          else
          {
            v80 = v339;
          }
          v74 = boneToTrackIndicesa;
          goto LABEL_98;
        }
LABEL_99:
        v64 = boneToTrackIndicesB;
        v73 = v325;
        v74 += *(signed __int16 *)(v323 + 10);
        boneToTrackIndicesa = v74;
      }
      ++v73;
      v75 = v332 + 2;
      v325 = v73;
      v332 += 2i64;
    }
    while ( v73 < *((_DWORD *)v64 + 2) );
    v62 = v335;
  }
  v198 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v199 = (v62 + 15) & 0xFFFFFFF0;
  if ( v62 > v198->m_slabSize || &v61[v199] != v198->m_cur || v198->m_firstNonLifoEnd == v61 )
    hkLifoAllocator::slowBlockFree(v198, v61, v199);
  else
    v198->m_cur = v61;
LABEL_164:
  if ( (_BYTE)partitionIndicesA )
    hkaSkeletonMapper::additivePoseFromCombinedPoseAndReferencePose(
      additivePoseOut,
      v11->m_skeletonB.m_pntr->m_referencePose.m_data,
      v361,
      0,
      v327,
      additivePoseOut);
  if ( v331 > 0 )
  {
    v296 = (4 * v331 + 127) & 0xFFFFFF80;
    v297 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v298 = (v296 + 15) & 0xFFFFFFF0;
    if ( v296 > v297->m_slabSize || (char *)weightsA + v298 != v297->m_cur || v297->m_firstNonLifoEnd == weightsA )
      hkLifoAllocator::slowBlockFree(v297, (void *)weightsA, v298);
    else
      v297->m_cur = (void *)weightsA;
  }
  v299 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v300 = (_QWORD *)v299[1];
  if ( (unsigned __int64)v300 < v299[3] )
  {
    *v300 = "lt";
    v301 = __rdtsc();
    v302 = (signed __int64)(v300 + 2);
    *(_DWORD *)(v302 - 8) = v301;
    v299[1] = v302;
  }
  v303 = (48 * numBones + 127) & 0xFFFFFF80;
  v304 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v305 = (v303 + 15) & 0xFFFFFFF0;
  if ( v303 > v304->m_slabSize
    || (char *)combinedPoseOut + v305 != v304->m_cur
    || v304->m_firstNonLifoEnd == combinedPoseOut )
  {
    hkLifoAllocator::slowBlockFree(v304, combinedPoseOut, v305);
  }
  else
  {
    v304->m_cur = combinedPoseOut;
  }
  v306 = (char *)p;
  if ( p == array )
  {
    v307 = (_DWORD)p - 1;
    if ( (signed int)p - 1 >= 0 )
    {
      v308 = (hkStringPtr *)&array[16 * v307];
      do
      {
        hkStringPtr::~hkStringPtr(v308);
        v308 -= 2;
        --v307;
      }
      while ( v307 >= 0 );
      v306 = (char *)p;
    }
    LODWORD(p) = 0;
  }
  v309 = (16 * v338 + 127) & 0xFFFFFF80;
  v310 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v311 = (v309 + 15) & 0xFFFFFFF0;
  if ( v309 > v310->m_slabSize || &v306[v311] != v310->m_cur || v310->m_firstNonLifoEnd == v306 )
    hkLifoAllocator::slowBlockFree(v310, v306, v311);
  else
    v310->m_cur = v306;
  v312 = (_DWORD)p - 1;
  if ( (signed int)p - 1 >= 0 )
  {
    v313 = (hkStringPtr *)&array[16 * v312];
    do
    {
      hkStringPtr::~hkStringPtr(v313);
      v313 -= 2;
      --v312;
    }
    while ( v312 >= 0 );
  }
  LODWORD(p) = 0;
  if ( SHIDWORD(p) >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      16 * HIDWORD(p));
  v314 = (char *)v347;
  array = 0i64;
  HIDWORD(p) = 2147483648;
  if ( v347 == partitionsOut.m_data )
  {
    v315 = partitionsOut.m_size - 1;
    if ( partitionsOut.m_size - 1 >= 0 )
    {
      v316 = &partitionsOut.m_data[v315];
      do
      {
        hkStringPtr::~hkStringPtr(&v316->m_name);
        --v316;
        --v315;
      }
      while ( v315 >= 0 );
      v314 = (char *)v347;
    }
    partitionsOut.m_size = 0;
  }
  v317 = (16 * v348 + 127) & 0xFFFFFF80;
  v318 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v319 = (v317 + 15) & 0xFFFFFFF0;
  if ( v317 > v318->m_slabSize || &v314[v319] != v318->m_cur || v318->m_firstNonLifoEnd == v314 )
    hkLifoAllocator::slowBlockFree(v318, v314, v319);
  else
    v318->m_cur = v314;
  v320 = partitionsOut.m_size - 1;
  if ( partitionsOut.m_size - 1 >= 0 )
  {
    v321 = &partitionsOut.m_data[v320];
    do
    {
      hkStringPtr::~hkStringPtr(&v321->m_name);
      --v321;
      --v320;
    }
    while ( v320 >= 0 );
  }
  partitionsOut.m_size = 0;
  if ( partitionsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      partitionsOut.m_data,
      16 * partitionsOut.m_capacityAndFlags);
}

// File Line: 774
// RVA: 0xB21980
void __fastcall hkaSkeletonMapper::mapPoseLocalSpace(hkaSkeletonMapper *this, hkQsTransformf *poseALocalSpaceOriginal, hkQsTransformf *poseBLocalSpaceInOut, const __int16 *boneToTrackIndicesA, const __int16 *boneToTrackIndicesB, bool additive, const float *weightsA, float *weightsBOut)
{
  int v8; // eax
  char *v9; // rdi
  signed int v10; // ebx
  hkLifoAllocator *v11; // rax
  int v12; // er8
  void *v13; // [rsp+50h] [rbp-28h]
  int v14; // [rsp+58h] [rbp-20h]
  int v15; // [rsp+5Ch] [rbp-1Ch]
  void *p; // [rsp+60h] [rbp-18h]
  int v17; // [rsp+68h] [rbp-10h]

  v14 = 0;
  v17 = 0;
  v13 = 0i64;
  v15 = 2147483648;
  p = 0i64;
  hkaSkeletonMapper::mapPoseLocalSpaceInternal(
    &this->m_mapping,
    poseALocalSpaceOriginal,
    poseBLocalSpaceInOut,
    boneToTrackIndicesA,
    boneToTrackIndicesB,
    (hkArray<short,hkContainerHeapAllocator> *)&v13,
    additive,
    1,
    weightsA,
    weightsBOut);
  v8 = v14;
  v9 = (char *)p;
  if ( p == v13 )
    v8 = 0;
  v14 = v8;
  v10 = (2 * v17 + 127) & 0xFFFFFF80;
  v11 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (v10 + 15) & 0xFFFFFFF0;
  if ( v10 > v11->m_slabSize || &v9[v12] != v11->m_cur || v11->m_firstNonLifoEnd == v9 )
    hkLifoAllocator::slowBlockFree(v11, v9, v12);
  else
    v11->m_cur = v9;
  v14 = 0;
  if ( v15 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v13,
      2 * (v15 & 0x3FFFFFFF));
}

// File Line: 786
// RVA: 0xB21AA0
void __fastcall hkaSkeletonMapper::mapPoseLocalSpace(hkaSkeletonMapper *this, hkQsTransformf *poseALocalSpaceOriginal, hkQsTransformf *poseBLocalSpaceInOut, hkArray<short,hkContainerHeapAllocator> *partitionIndicesA, bool additive, bool mapToFullPose, const float *weightsA, float *weightsBOut)
{
  hkaSkeletonMapper::mapPoseLocalSpaceInternal(
    &this->m_mapping,
    poseALocalSpaceOriginal,
    poseBLocalSpaceInOut,
    0i64,
    0i64,
    partitionIndicesA,
    additive,
    mapToFullPose,
    weightsA,
    weightsBOut);
}

// File Line: 799
// RVA: 0xB21B00
void __fastcall hkaSkeletonMapper::mapPoseLocalSpace(hkaSkeletonMapper *this, hkQsTransformf *poseALocalSpaceOriginal, hkQsTransformf *poseBLocalSpaceInOut, const __int16 *boneToTrackIndicesA, const __int16 *boneToTrackIndicesB, hkArray<short,hkContainerHeapAllocator> *partitionIndicesA, bool additive, bool mapToFullPose, const float *weightsA, float *weightsBOut)
{
  hkaSkeletonMapper::mapPoseLocalSpaceInternal(
    &this->m_mapping,
    poseALocalSpaceOriginal,
    poseBLocalSpaceInOut,
    boneToTrackIndicesA,
    boneToTrackIndicesB,
    partitionIndicesA,
    additive,
    mapToFullPose,
    weightsA,
    weightsBOut);
}

// File Line: 807
// RVA: 0xB21B30
void __fastcall hkaSkeletonMapper::mapPose(hkaSkeletonMapper *this, hkaPose *poseAIn, hkaPose *poseBInOut, hkaSkeletonMapper::ConstraintSource source)
{
  int v4; // eax
  hkaSkeletonMapper::ConstraintSource v5; // er14
  hkaPose *v6; // rbp
  hkaSkeletonMapper *v7; // rsi
  hkQsTransformf *v8; // rdi
  hkQsTransformf *v9; // rbx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v10; // rax
  hkQsTransformf *v11; // rbx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v12; // rax

  v4 = this->m_mapping.m_mappingType.m_storage;
  v5 = source;
  v6 = poseBInOut;
  v7 = this;
  if ( v4 )
  {
    if ( v4 == 1 )
    {
      v11 = hkaPose::getSyncedPoseLocalSpace(poseAIn)->m_data;
      v12 = hkaPose::accessSyncedPoseLocalSpace(v6);
      hkaSkeletonMapper::mapPoseLocalSpace(v7, v11, v12->m_data, 0);
    }
  }
  else
  {
    v8 = hkaPose::getSyncedPoseModelSpace(poseAIn)->m_data;
    v9 = hkaPose::getSyncedPoseLocalSpace(v6)->m_data;
    v10 = hkaPose::accessSyncedPoseModelSpace(v6);
    hkaSkeletonMapper::mapPose(v7, v8, v9, v10->m_data, v5);
  }
}

// File Line: 837
// RVA: 0xB21BE0
void __fastcall hkaSkeletonMapper::mapExtractedMotion(hkaSkeletonMapper *this, hkQsTransformf *deltaMotionIn, hkQsTransformf *deltaMotionOut)
{
  hkaSkeletonMapper::setMulWithScaling(
    (hkaSkeletonMapperData::MappingType)this->m_mapping.m_mappingType.m_storage,
    deltaMotionOut,
    &this->m_mapping.m_extractedMotionMapping,
    deltaMotionIn);
}

// File Line: 842
// RVA: 0xB224E0
void __fastcall hkaSkeletonMapper::checkMapping(hkaSkeletonMapperData *m_mapping)
{
  __int64 v1; // rdi
  hkaSkeletonMapperData *v2; // rbx
  int v3; // er15
  __int64 v4; // rbp
  hkaSkeletonMapperData::SimpleMapping *v5; // rcx
  hkStringPtr *v6; // r14
  signed __int64 v7; // rsi
  __m128 v8; // xmm1
  hkOstream *v9; // rax
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkaSkeleton *v15; // rax
  __int64 v16; // rcx
  hkBool *v17; // rax
  hkErrStream v18; // [rsp+20h] [rbp-248h]
  hkSimdFloat32 f; // [rsp+40h] [rbp-228h]
  char buf; // [rsp+50h] [rbp-218h]

  v1 = 0i64;
  v2 = m_mapping;
  if ( !m_mapping->m_mappingType.m_storage )
  {
    v3 = 0;
    if ( m_mapping->m_simpleMappings.m_size > 0 )
    {
      v4 = 0i64;
      do
      {
        v5 = v2->m_simpleMappings.m_data;
        v6 = &v2->m_skeletonA.m_pntr->m_bones.m_data[v5[v4].m_boneA].m_name;
        v7 = (signed __int64)&v2->m_skeletonB.m_pntr->m_bones.m_data[v5[v4].m_boneB];
        if ( *(_BYTE *)(v7 + 8) )
        {
          v8 = _mm_mul_ps(v5[v4].m_aFromBTransform.m_translation.m_quad, v5[v4].m_aFromBTransform.m_translation.m_quad);
          f.m_real = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                       _mm_shuffle_ps(v8, v8, 170));
          if ( f.m_real.m128_f32[0] > COERCE_FLOAT(_mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0)) )
          {
            hkErrStream::hkErrStream(&v18, &buf, 512);
            v9 = hkOstream::operator<<((hkOstream *)&v18.vfptr, "Bones A:");
            v10 = hkOstream::operator<<(v9, v6);
            v11 = hkOstream::operator<<(v10, " and B:");
            v12 = hkOstream::operator<<(v11, (hkStringPtr *)v7);
            v13 = hkOstream::operator<<(v12, " are not fully aligned (error :");
            v14 = hkOstream::operator<<(v13, &f);
            hkOstream::operator<<(v14, ").");
            hkError::messageWarning(-1413812289, &buf, "Mapper\\hkaSkeletonMapper.cpp", 862);
            hkOstream::~hkOstream((hkOstream *)&v18.vfptr);
          }
        }
        ++v3;
        ++v4;
      }
      while ( v3 < v2->m_simpleMappings.m_size );
    }
  }
  if ( !v2->m_mappingType.m_storage )
  {
    v15 = v2->m_skeletonB.m_pntr;
    v16 = v15->m_bones.m_size;
    if ( v16 <= 0 )
    {
LABEL_13:
      hkErrStream::hkErrStream(&v18, &buf, 512);
      hkOstream::operator<<(
        (hkOstream *)&v18.vfptr,
        "None of the bones in skeleton have translations locked - did you forget to lock translations ?.");
      hkError::messageWarning(-1413843035, &buf, "Mapper\\hkaSkeletonMapper.cpp", 885);
      hkOstream::~hkOstream((hkOstream *)&v18.vfptr);
    }
    else
    {
      v17 = &v15->m_bones.m_data->m_lockTranslation;
      while ( !v17->m_bool )
      {
        ++v1;
        v17 += 16;
        if ( v1 >= v16 )
          goto LABEL_13;
      }
    }
  }
}

// File Line: 891
// RVA: 0xB226F0
void __fastcall hkaSkeletonMapper::checkMappingLocalSpace(hkaSkeletonMapperData *m_mapping)
{
  int v1; // er12
  __int64 v2; // rdi
  hkaSkeletonMapperData *v3; // rbx
  hkLifoAllocator *v4; // rax
  _DWORD *v5; // r15
  int v6; // edx
  char *v7; // rcx
  __int64 v8; // rcx
  int v9; // er13
  _DWORD *v10; // rdi
  int v11; // esi
  __int64 v12; // r14
  hkaSkeletonMapperData::SimpleMapping *v13; // rdi
  signed __int16 v14; // ax
  __int64 v15; // r13
  hkaSkeletonMapperData::ChainMapping *v16; // r14
  signed __int16 v17; // ax
  signed __int16 v18; // ax
  signed __int16 v19; // ax
  signed int i; // ecx
  __int64 v21; // rsi
  hkStringPtr *v22; // rdi
  hkOstream *v23; // rax
  hkOstream *v24; // rax
  signed int v25; // edi
  hkLifoAllocator *v26; // rax
  int v27; // er8
  hkErrStream v28; // [rsp+20h] [rbp-C8h]
  char buf; // [rsp+40h] [rbp-A8h]
  int v30; // [rsp+268h] [rbp+180h]
  int vars0; // [rsp+270h] [rbp+188h]

  v1 = 0;
  v2 = m_mapping->m_skeletonB.m_pntr->m_bones.m_size;
  v3 = m_mapping;
  vars0 = v2;
  if ( (_DWORD)v2 )
  {
    v4 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v5 = v4->m_cur;
    v6 = (4 * v2 + 127) & 0xFFFFFF80;
    v7 = (char *)v5 + v6;
    if ( v6 > v4->m_slabSize || v7 > v4->m_end )
      v5 = hkLifoAllocator::allocateFromNewSlab(v4, v6);
    else
      v4->m_cur = v7;
  }
  else
  {
    v5 = 0i64;
  }
  v8 = v2;
  v9 = v2 | 0x80000000;
  v30 = v2 | 0x80000000;
  if ( (signed int)v2 > 0 )
  {
    v10 = v5;
    while ( v8 )
    {
      *v10 = 0;
      ++v10;
      --v8;
    }
  }
  v11 = 0;
  if ( v3->m_simpleMappings.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = &v3->m_simpleMappings.m_data[v12];
      if ( !hkaSkeletonMapper::checkTransform(
              (hkaSkeletonMapperData::MappingType)v3->m_mappingType.m_storage,
              &v13->m_aFromBTransform) )
      {
        hkErrStream::hkErrStream(&v28, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v28.vfptr, "Improper mapping transform found");
        hkError::messageWarning(-1413825855, &buf, "Mapper\\hkaSkeletonMapper.cpp", 915);
        hkOstream::~hkOstream((hkOstream *)&v28.vfptr);
      }
      if ( v13->m_boneA < 0 || v13->m_boneA >= v3->m_skeletonA.m_pntr->m_bones.m_size )
      {
        hkErrStream::hkErrStream(&v28, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v28.vfptr, "Invalid mapped bone found");
        hkError::messageWarning(-1413857535, &buf, "Mapper\\hkaSkeletonMapper.cpp", 920);
        hkOstream::~hkOstream((hkOstream *)&v28.vfptr);
      }
      v14 = v13->m_boneB;
      if ( v14 < 0 || v14 >= v3->m_skeletonB.m_pntr->m_bones.m_size )
      {
        hkErrStream::hkErrStream(&v28, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v28.vfptr, "Invalid mapped bone found");
        hkError::messageWarning(-1413813582, &buf, "Mapper\\hkaSkeletonMapper.cpp", 925);
        hkOstream::~hkOstream((hkOstream *)&v28.vfptr);
      }
      if ( ++v5[v13->m_boneB] > 1 )
      {
        hkErrStream::hkErrStream(&v28, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v28.vfptr, "Improperly mapped bone found");
        hkError::messageWarning(-1413840481, &buf, "Mapper\\hkaSkeletonMapper.cpp", 933);
        hkOstream::~hkOstream((hkOstream *)&v28.vfptr);
      }
      ++v11;
      ++v12;
    }
    while ( v11 < v3->m_simpleMappings.m_size );
  }
  if ( v3->m_chainMappings.m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      v16 = &v3->m_chainMappings.m_data[v15];
      if ( !hkaSkeletonMapper::checkTransform(
              (hkaSkeletonMapperData::MappingType)v3->m_mappingType.m_storage,
              &v16->m_startAFromBTransform) )
      {
        hkErrStream::hkErrStream(&v28, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v28.vfptr, "Improper mapping transform found");
        hkError::messageWarning(-1413825855, &buf, "Mapper\\hkaSkeletonMapper.cpp", 946);
        hkOstream::~hkOstream((hkOstream *)&v28.vfptr);
      }
      if ( !hkaSkeletonMapper::checkTransform(
              (hkaSkeletonMapperData::MappingType)v3->m_mappingType.m_storage,
              &v16->m_endAFromBTransform) )
      {
        hkErrStream::hkErrStream(&v28, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v28.vfptr, "Improper mapping transform found");
        hkError::messageWarning(-1413825855, &buf, "Mapper\\hkaSkeletonMapper.cpp", 951);
        hkOstream::~hkOstream((hkOstream *)&v28.vfptr);
      }
      if ( v16->m_endBoneA <= v16->m_startBoneA )
      {
        hkErrStream::hkErrStream(&v28, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v28.vfptr, "Invalid chain found");
        hkError::messageWarning(-1413840481, &buf, "Mapper\\hkaSkeletonMapper.cpp", 956);
        hkOstream::~hkOstream((hkOstream *)&v28.vfptr);
      }
      if ( v16->m_endBoneB <= v16->m_startBoneB )
      {
        hkErrStream::hkErrStream(&v28, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v28.vfptr, "Invalid chain found");
        hkError::messageWarning(-1413840481, &buf, "Mapper\\hkaSkeletonMapper.cpp", 961);
        hkOstream::~hkOstream((hkOstream *)&v28.vfptr);
      }
      v17 = v16->m_endBoneA;
      if ( v17 < 0 || v17 >= v3->m_skeletonA.m_pntr->m_bones.m_size )
      {
        hkErrStream::hkErrStream(&v28, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v28.vfptr, "Invalid bone found");
        hkError::messageWarning(392326881, &buf, "Mapper\\hkaSkeletonMapper.cpp", 966);
        hkOstream::~hkOstream((hkOstream *)&v28.vfptr);
      }
      if ( v16->m_startBoneA < 0 || v16->m_startBoneA >= v3->m_skeletonA.m_pntr->m_bones.m_size )
      {
        hkErrStream::hkErrStream(&v28, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v28.vfptr, "Invalid bone found");
        hkError::messageWarning(101138396, &buf, "Mapper\\hkaSkeletonMapper.cpp", 971);
        hkOstream::~hkOstream((hkOstream *)&v28.vfptr);
      }
      v18 = v16->m_endBoneB;
      if ( v18 < 0 || v18 >= v3->m_skeletonB.m_pntr->m_bones.m_size )
      {
        hkErrStream::hkErrStream(&v28, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v28.vfptr, "Invalid bone found");
        hkError::messageWarning(430017533, &buf, "Mapper\\hkaSkeletonMapper.cpp", 976);
        hkOstream::~hkOstream((hkOstream *)&v28.vfptr);
      }
      v19 = v16->m_startBoneB;
      if ( v19 < 0 || v19 >= v3->m_skeletonB.m_pntr->m_bones.m_size )
      {
        hkErrStream::hkErrStream(&v28, &buf, 512);
        hkOstream::operator<<((hkOstream *)&v28.vfptr, "Invalid bone found");
        hkError::messageWarning(263624113, &buf, "Mapper\\hkaSkeletonMapper.cpp", 981);
        hkOstream::~hkOstream((hkOstream *)&v28.vfptr);
      }
      for ( i = v16->m_endBoneB; i >= v16->m_startBoneB; i = v3->m_skeletonB.m_pntr->m_parentIndices.m_data[v21] )
      {
        v21 = i;
        ++v5[v21];
        if ( v5[i] > 1 )
        {
          hkErrStream::hkErrStream(&v28, &buf, 512);
          v22 = &v3->m_skeletonB.m_pntr->m_bones.m_data[v21].m_name;
          v23 = hkOstream::operator<<((hkOstream *)&v28.vfptr, "Improperly mapped bone found. Bone \"");
          v24 = hkOstream::operator<<(v23, v22);
          hkOstream::operator<<(v24, "\" has been mapped more than once.");
          hkError::messageWarning(-1413840481, &buf, "Mapper\\hkaSkeletonMapper.cpp", 993);
          hkOstream::~hkOstream((hkOstream *)&v28.vfptr);
        }
      }
      ++v1;
      ++v15;
    }
    while ( v1 < v3->m_chainMappings.m_size );
    v9 = v30;
  }
  v25 = (4 * vars0 + 127) & 0xFFFFFF80;
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (v25 + 15) & 0xFFFFFFF0;
  if ( v25 > v26->m_slabSize || (char *)v5 + v27 != v26->m_cur || v26->m_firstNonLifoEnd == v5 )
    hkLifoAllocator::slowBlockFree(v26, v5, v27);
  else
    v26->m_cur = v5;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v5,
      4 * v9);
}v26, v5, v27);
  else
    v26->m_cur = v5;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v5,
      

// File Line: 1014
// RVA: 0xB22DD0
bool __fastcall hkaSkeletonMapper::checkTransform(hkaSkeletonMapperData::MappingType type, hkQsTransformf *q)
{
  hkQsTransformf *v2; // rbx
  bool result; // al

  v2 = q;
  if ( !hkQuaternionf::isOk(&q->m_rotation, 0.001)
    || _mm_movemask_ps(_mm_cmpunordps(v2->m_translation.m_quad, v2->m_translation.m_quad)) & 7 )
  {
    result = 0;
  }
  else
  {
    result = (_mm_movemask_ps(_mm_cmpunordps(v2->m_scale.m_quad, v2->m_scale.m_quad)) & 7) == 0;
  }
  return result;
}

// File Line: 1040
// RVA: 0xB24830
void __fastcall hkaSkeletonMapper::setMulWithScaling(hkaSkeletonMapperData::MappingType type, hkQsTransformf *dst, hkQsTransformf *map, hkQsTransformf *src)
{
  hkQuaternionf v4; // xmm2
  hkQuaternionf v5; // xmm3
  __m128 v6; // xmm5
  __m128 v7; // xmm6
  __m128 v8; // xmm4
  __m128 v9; // xmm0
  __m128 v10; // xmm3
  __m128 v11; // xmm6

  dst->m_translation.m_quad = _mm_add_ps(
                                _mm_mul_ps(map->m_scale.m_quad, src->m_translation.m_quad),
                                map->m_translation.m_quad);
  v4.m_vec.m_quad = (__m128)map->m_rotation;
  v5.m_vec.m_quad = (__m128)src->m_rotation;
  v6 = _mm_shuffle_ps(src->m_rotation.m_vec.m_quad, src->m_rotation.m_vec.m_quad, 255);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v5.m_vec.m_quad, v5.m_vec.m_quad, 201), v4.m_vec.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(v4.m_vec.m_quad, v4.m_vec.m_quad, 201), v5.m_vec.m_quad));
  v8 = _mm_shuffle_ps(map->m_rotation.m_vec.m_quad, map->m_rotation.m_vec.m_quad, 255);
  v9 = _mm_mul_ps(v8, v5.m_vec.m_quad);
  v10 = _mm_mul_ps(v5.m_vec.m_quad, v4.m_vec.m_quad);
  v11 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 201), v9), _mm_mul_ps(v6, v4.m_vec.m_quad));
  dst->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                   v11,
                                   _mm_unpackhi_ps(
                                     v11,
                                     _mm_sub_ps(
                                       _mm_mul_ps(v6, v8),
                                       _mm_add_ps(
                                         _mm_add_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(v10, v10, 0)),
                                         _mm_shuffle_ps(v10, v10, 170)))),
                                   196);
  dst->m_scale = src->m_scale;
}

// File Line: 1056
// RVA: 0xB21C10
void __fastcall hkaSkeletonMapper::initializeBindingMaps(hkaSkeletonMapper *this, hkaAnimationBinding *binding, hkArray<short,hkContainerHeapAllocator> *srcBoneToTrackIndicesOut, hkArray<short,hkContainerHeapAllocator> *dstBoneToTrackIndicesOut, hkArray<short,hkContainerHeapAllocator> *dstTrackToBoneIndicesOut)
{
  hkArray<short,hkContainerHeapAllocator> *v5; // rsi
  __int16 v6; // bx
  hkArray<short,hkContainerHeapAllocator> *v7; // r12
  hkaSkeleton *v8; // r8
  hkaAnimationBinding *v9; // r14
  int v10; // er15
  int v11; // eax
  hkaSkeletonMapper *v12; // r13
  int v13; // eax
  int v14; // er9
  int v15; // edx
  __int16 *v16; // rdi
  __int64 v17; // rcx
  __int16 v18; // di
  _DWORD *v19; // r15
  int v20; // er14
  int v21; // eax
  int v22; // eax
  int v23; // er9
  int v24; // edx
  _WORD *v25; // rdi
  __int64 v26; // rcx
  __int16 v27; // di
  hkaSkeletonMapperData::SimpleMapping *v28; // rdx
  __int16 v29; // r14
  __int16 v30; // r12
  hkaSkeletonMapperData::ChainMapping *v31; // rax
  signed __int64 v32; // rdi
  int v33; // edx
  __int16 *v34; // rcx
  int v35; // er14
  __int64 v36; // rdi
  __int16 v37; // r15
  int v38; // er14
  int v39; // eax
  int v40; // eax
  int v41; // er9
  int v42; // edx
  _WORD *v43; // rdi
  __int64 v44; // rcx
  hkaSkeleton *skeleton; // [rsp+30h] [rbp-38h]
  hkArray<short,hkContainerHeapAllocator> v46; // [rsp+38h] [rbp-30h]
  hkArray<short,hkContainerHeapAllocator> bonesOut; // [rsp+48h] [rbp-20h]
  hkBool result; // [rsp+B0h] [rbp+48h]
  hkaSkeleton *v49; // [rsp+B8h] [rbp+50h]
  hkArray<short,hkContainerHeapAllocator> *v50; // [rsp+C0h] [rbp+58h]
  void *array; // [rsp+C8h] [rbp+60h]

  array = dstBoneToTrackIndicesOut;
  v50 = srcBoneToTrackIndicesOut;
  v5 = dstTrackToBoneIndicesOut;
  v6 = 0;
  v7 = srcBoneToTrackIndicesOut;
  srcBoneToTrackIndicesOut->m_size = 0;
  v5->m_size = 0;
  dstBoneToTrackIndicesOut->m_size = 0;
  v8 = this->m_mapping.m_skeletonB.m_pntr;
  v9 = binding;
  v10 = this->m_mapping.m_skeletonA.m_pntr->m_bones.m_size;
  skeleton = this->m_mapping.m_skeletonA.m_pntr;
  v11 = v7->m_capacityAndFlags & 0x3FFFFFFF;
  v12 = this;
  v49 = this->m_mapping.m_skeletonB.m_pntr;
  if ( v11 < v10 )
  {
    v13 = 2 * v11;
    v14 = v10;
    if ( v10 < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(
      (hkResult *)&dstTrackToBoneIndicesOut,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v7,
      v14,
      2);
    v8 = v49;
  }
  v15 = v10 - v7->m_size;
  v16 = &v7->m_data[v7->m_size];
  v17 = v15;
  if ( v15 > 0 )
  {
    while ( v17 )
    {
      *v16 = -1;
      ++v16;
      --v17;
    }
  }
  v7->m_size = v10;
  v18 = 0;
  if ( v9->m_transformTrackToBoneIndices.m_size > 0 )
  {
    do
    {
      v7->m_data[v9->m_transformTrackToBoneIndices.m_data[v18]] = v18;
      ++v18;
    }
    while ( v18 < v9->m_transformTrackToBoneIndices.m_size );
  }
  v19 = array;
  v20 = v8->m_bones.m_size;
  v21 = *((_DWORD *)array + 3) & 0x3FFFFFFF;
  if ( v21 < v20 )
  {
    v22 = 2 * v21;
    v23 = v8->m_bones.m_size;
    if ( v20 < v22 )
      v23 = v22;
    hkArrayUtil::_reserve(
      (hkResult *)&dstTrackToBoneIndicesOut,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      array,
      v23,
      2);
  }
  v24 = v20 - v19[2];
  v25 = (_WORD *)(*(_QWORD *)v19 + 2i64 * (signed int)v19[2]);
  v26 = v24;
  if ( v24 > 0 )
  {
    while ( v26 )
    {
      *v25 = -1;
      ++v25;
      --v26;
    }
  }
  v19[2] = v20;
  v27 = 0;
  if ( v12->m_mapping.m_simpleMappings.m_size > 0 )
  {
    do
    {
      v28 = &v12->m_mapping.m_simpleMappings.m_data[(signed __int64)v27];
      if ( v7->m_data[v28->m_boneA] >= 0 )
      {
        v29 = v28->m_boneB;
        if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 2);
        v5->m_data[v5->m_size++] = v29;
      }
      ++v27;
    }
    while ( v27 < v12->m_mapping.m_simpleMappings.m_size );
  }
  v30 = 0;
  if ( v12->m_mapping.m_chainMappings.m_size > 0 )
  {
    do
    {
      v31 = v12->m_mapping.m_chainMappings.m_data;
      bonesOut.m_data = 0i64;
      bonesOut.m_size = 0;
      bonesOut.m_capacityAndFlags = 2147483648;
      v46.m_data = 0i64;
      v46.m_size = 0;
      v46.m_capacityAndFlags = 2147483648;
      v32 = v30;
      if ( hkaSkeletonUtils::getBoneChain(
             (hkBool *)&dstTrackToBoneIndicesOut,
             skeleton,
             v31[v32].m_startBoneA,
             v31[v32].m_endBoneA,
             &bonesOut)->m_bool
        && hkaSkeletonUtils::getBoneChain(
             &result,
             v49,
             v12->m_mapping.m_chainMappings.m_data[v32].m_startBoneB,
             v12->m_mapping.m_chainMappings.m_data[v32].m_endBoneB,
             &v46)->m_bool )
      {
        v33 = 0;
        if ( bonesOut.m_size <= 0 )
        {
LABEL_30:
          v35 = 0;
          if ( v46.m_size > 0 )
          {
            v36 = 0i64;
            do
            {
              v37 = v46.m_data[v36];
              if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 2);
              ++v35;
              v5->m_data[v5->m_size++] = v37;
              ++v36;
            }
            while ( v35 < v46.m_size );
          }
        }
        else
        {
          v34 = bonesOut.m_data;
          while ( v50->m_data[*v34] >= 0 )
          {
            ++v33;
            ++v34;
            if ( v33 >= bonesOut.m_size )
              goto LABEL_30;
          }
        }
      }
      v46.m_size = 0;
      if ( v46.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v46.m_data,
          2 * (v46.m_capacityAndFlags & 0x3FFFFFFF));
      bonesOut.m_size = 0;
      v46.m_capacityAndFlags = 2147483648;
      v46.m_data = 0i64;
      if ( bonesOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          bonesOut.m_data,
          2 * (bonesOut.m_capacityAndFlags & 0x3FFFFFFF));
      ++v30;
      bonesOut.m_capacityAndFlags = 2147483648;
      bonesOut.m_data = 0i64;
    }
    while ( v30 < v12->m_mapping.m_chainMappings.m_size );
    v19 = array;
  }
  v38 = v49->m_bones.m_size;
  v39 = v19[3] & 0x3FFFFFFF;
  if ( v39 < v38 )
  {
    v40 = 2 * v39;
    v41 = v49->m_bones.m_size;
    if ( v38 < v40 )
      v41 = v40;
    hkArrayUtil::_reserve(
      (hkResult *)&array,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      v19,
      v41,
      2);
  }
  v42 = v38 - v19[2];
  v43 = (_WORD *)(*(_QWORD *)v19 + 2i64 * (signed int)v19[2]);
  v44 = v42;
  if ( v42 > 0 )
  {
    while ( v44 )
    {
      *v43 = -1;
      ++v43;
      --v44;
    }
  }
  v19[2] = v38;
  if ( v5->m_size > 0 )
  {
    do
    {
      *(_WORD *)(*(_QWORD *)v19 + 2i64 * v5->m_data[v6]) = v6;
      ++v6;
    }
    while ( v6 < v5->m_size );
  }
}

// File Line: 1186
// RVA: 0xB22220
void __fastcall hkaSkeletonMapper::combineSparsePoseWithFullPose(hkQsTransformf *sparsePose, hkQsTransformf *fullPose, const __int16 *sparsePoseBoneToTrackIndices, int startBoneIndex, int numBones, hkQsTransformf *sparseMulFull_sparseOut)
{
  hkQsTransformf *v6; // r10
  hkQsTransformf *v7; // rbx
  __m128 *v8; // rdx
  __int64 v9; // r8
  signed __int64 v10; // r9
  signed __int64 v11; // rax
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm6
  __m128 v17; // xmm4
  __m128 v18; // xmm6
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  __m128 v21; // xmm0
  __m128 v22; // xmm5
  __m128 v23; // xmm3
  __m128 v24; // xmm6
  __m128 v25; // xmm3
  __m128 v26; // xmm3
  signed __int64 i; // rax
  __int16 v28; // cx
  __int64 v29; // rdx
  __m128 v30; // xmm7
  __m128 v31; // xmm8
  __m128 v32; // xmm1
  __m128 v33; // xmm6
  __m128 v34; // xmm5
  __m128 v35; // xmm4
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 v39; // xmm2
  __m128 v40; // xmm3
  __m128 v41; // xmm4
  __m128 v42; // xmm7
  __m128 v43; // xmm4
  __m128 v44; // xmm4

  v6 = fullPose;
  v7 = sparsePose;
  if ( sparsePoseBoneToTrackIndices )
  {
    for ( i = 0i64; i < numBones; ++v6 )
    {
      v28 = sparsePoseBoneToTrackIndices[i];
      if ( v28 >= 0 )
      {
        v29 = v28;
        v30 = v7[v28].m_rotation.m_vec.m_quad;
        v31 = v7[v28].m_scale.m_quad;
        v32 = _mm_mul_ps(v6->m_translation.m_quad, v30);
        v33 = _mm_shuffle_ps(v7[v28].m_rotation.m_vec.m_quad, v30, 255);
        v34 = _mm_shuffle_ps(v7[v28].m_rotation.m_vec.m_quad, v30, 201);
        v35 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v6->m_translation.m_quad, v6->m_translation.m_quad, 201), v30),
                _mm_mul_ps(v6->m_translation.m_quad, v34));
        v36 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                _mm_shuffle_ps(v32, v32, 170));
        v37 = v7[v28].m_rotation.m_vec.m_quad;
        v38 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(v36, v30),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v33, v33), (__m128)xmmword_141A711B0), v6->m_translation.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v33));
        sparseMulFull_sparseOut[v29].m_translation.m_quad = _mm_add_ps(
                                                              _mm_add_ps(v38, v38),
                                                              v7[v28].m_translation.m_quad);
        v39 = v6->m_rotation.m_vec.m_quad;
        v40 = _mm_shuffle_ps(v6->m_rotation.m_vec.m_quad, v6->m_rotation.m_vec.m_quad, 255);
        v41 = _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v30);
        v42 = _mm_mul_ps(v30, v39);
        v43 = _mm_sub_ps(v41, _mm_mul_ps(v6->m_rotation.m_vec.m_quad, v34));
        v44 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v43, v43, 201), _mm_mul_ps(v6->m_rotation.m_vec.m_quad, v33)),
                _mm_mul_ps(v37, v40));
        sparseMulFull_sparseOut[v29].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                                 v44,
                                                                 _mm_unpackhi_ps(
                                                                   v44,
                                                                   _mm_sub_ps(
                                                                     _mm_mul_ps(v40, v33),
                                                                     _mm_add_ps(
                                                                       _mm_add_ps(
                                                                         _mm_shuffle_ps(v42, v42, 85),
                                                                         _mm_shuffle_ps(v42, v42, 0)),
                                                                       _mm_shuffle_ps(v42, v42, 170)))),
                                                                 196);
        sparseMulFull_sparseOut[v29].m_scale.m_quad = _mm_mul_ps(v6->m_scale.m_quad, v31);
      }
      ++i;
    }
  }
  else if ( numBones > 0 )
  {
    v8 = &sparsePose->m_rotation.m_vec.m_quad;
    v9 = (unsigned int)numBones;
    v10 = (signed __int64)v6 + 48i64 * startBoneIndex - (_QWORD)sparsePose;
    v11 = (char *)sparseMulFull_sparseOut - (char *)sparsePose;
    do
    {
      v12 = *v8;
      v13 = *(__m128 *)((char *)v8 + v10 - 16);
      v8 += 3;
      v14 = _mm_mul_ps(v13, v12);
      v15 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 201), v12), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 201), v13));
      v16 = _mm_shuffle_ps(v12, v12, 255);
      v17 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                    _mm_shuffle_ps(v14, v14, 170)),
                  v12),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v16, v16), (__m128)xmmword_141A711B0), v13)),
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v16));
      *(__m128 *)((char *)v8 + v11 - 64) = _mm_add_ps(_mm_add_ps(v17, v17), v8[-4]);
      v18 = v8[-3];
      v19 = *(__m128 *)((char *)v8 + v10 - 48);
      v20 = _mm_shuffle_ps(v8[-3], v8[-3], 255);
      v21 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v19);
      v22 = _mm_shuffle_ps(*(__m128 *)((char *)v8 + v10 - 48), *(__m128 *)((char *)v8 + v10 - 48), 255);
      v23 = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v18);
      v24 = _mm_mul_ps(v18, v19);
      v25 = _mm_sub_ps(v23, v21);
      v26 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v25, v25, 201), _mm_mul_ps(*(__m128 *)((char *)v8 + v10 - 48), v20)),
              _mm_mul_ps(v8[-3], v22));
      *(__m128 *)((char *)v8 + v11 - 48) = _mm_shuffle_ps(
                                             v26,
                                             _mm_unpackhi_ps(
                                               v26,
                                               _mm_sub_ps(
                                                 _mm_mul_ps(v22, v20),
                                                 _mm_add_ps(
                                                   _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                                                   _mm_shuffle_ps(v24, v24, 170)))),
                                             196);
      *(__m128 *)((char *)v8 + v11 - 32) = _mm_mul_ps(*(__m128 *)((char *)v8 + v10 - 32), v8[-2]);
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 1237
// RVA: 0xB22000
void __fastcall hkaSkeletonMapper::combinedPoseFromAdditivePoseAndReferencePose(hkQsTransformf *additivePose, hkQsTransformf *referencePose, const __int16 *boneToTrackIndices, int startBoneIndex, int numBones, hkQsTransformf *combinedPoseOut)
{
  hkaSkeletonMapper::combineSparsePoseWithFullPose(
    additivePose,
    referencePose,
    boneToTrackIndices,
    startBoneIndex,
    numBones,
    combinedPoseOut);
}

// File Line: 1242
// RVA: 0xB22010
void __fastcall hkaSkeletonMapper::additivePoseFromCombinedPoseAndReferencePose(hkQsTransformf *combinedPose, hkQsTransformf *referencePose, const __int16 *boneToTrackIndices, int startBoneIndex, int numBones, hkQsTransformf *additivePoseOut)
{
  __int64 v6; // rbx
  hkQsTransformf *v7; // rdi
  hkLifoAllocator *v8; // rax
  hkQsTransformf *v9; // rsi
  int v10; // ebp
  char *v11; // rcx
  __int64 v12; // r12
  __m128i v13; // xmm0
  __m128 v14; // xmm6
  __m128 v15; // xmm7
  signed __int64 v16; // r14
  signed __int64 v17; // r15
  signed __int64 v18; // rbx
  __m128 v19; // xmm2
  __m128 v20; // xmm3
  __m128i v21; // xmm0
  hkLifoAllocator *v22; // rax
  int v23; // er8
  hkQsTransformf *sparsePose; // [rsp+A0h] [rbp+8h]
  __int16 *sparsePoseBoneToTrackIndices; // [rsp+B0h] [rbp+18h]

  sparsePoseBoneToTrackIndices = (__int16 *)boneToTrackIndices;
  sparsePose = combinedPose;
  v6 = startBoneIndex;
  v7 = referencePose;
  v8 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkQsTransformf *)v8->m_cur;
  v10 = (48 * numBones + 127) & 0xFFFFFF80;
  v11 = (char *)v9 + v10;
  if ( v10 > v8->m_slabSize || v11 > v8->m_end )
    v9 = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(v8, v10);
  else
    v8->m_cur = v11;
  v12 = numBones;
  if ( numBones > 0 )
  {
    v13 = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    v14 = (__m128)_mm_shuffle_epi32(v13, 0);
    v15 = (__m128)_mm_shuffle_epi32(v13, 64);
    v16 = (signed __int64)&v7[v6].m_scale;
    v17 = (char *)&v9[-v6] - (char *)v7;
    do
    {
      v18 = v17 + v16;
      hkVector4f::setRotatedInverseDir(
        (hkVector4f *)(v17 + v16 - 32),
        (hkQuaternionf *)(v16 - 16),
        (hkVector4f *)(v16 - 32));
      v16 += 48i64;
      *(__m128 *)(v18 - 32) = _mm_xor_ps(v14, *(__m128 *)(v18 - 32));
      *(__m128 *)(v17 + v16 - 64) = _mm_xor_ps(*(__m128 *)(v16 - 64), v15);
      v19 = *(__m128 *)(v16 - 48);
      v20 = _mm_rcp_ps(v19);
      v21 = (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v19, v20)), v20);
      *(__m128i *)(v17 + v16 - 48) = v21;
      _mm_store_si128((__m128i *)(v17 + v16 - 48), _mm_srli_si128(_mm_slli_si128(v21, 4), 4));
      --v12;
    }
    while ( v12 );
  }
  hkaSkeletonMapper::combineSparsePoseWithFullPose(
    sparsePose,
    v9,
    sparsePoseBoneToTrackIndices,
    0,
    numBones,
    additivePoseOut);
  v22 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v23 = (v10 + 15) & 0xFFFFFFF0;
  if ( v10 > v22->m_slabSize || (char *)v9 + v23 != v22->m_cur || v22->m_firstNonLifoEnd == v9 )
    hkLifoAllocator::slowBlockFree(v22, v9, v23);
  else
    v22->m_cur = v9;
}

