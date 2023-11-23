// File Line: 28
// RVA: 0xB20B70
void __fastcall hkaSkeletonMapper::hkaSkeletonMapper(hkaSkeletonMapper *this, hkaSkeletonMapperData *mapping)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaSkeletonMapper::`vftable;
  hkaSkeletonMapperData::hkaSkeletonMapperData(&this->m_mapping);
  hkaSkeletonMapperData::operator=(&this->m_mapping, mapping);
}

// File Line: 38
// RVA: 0xB20BD0
void __fastcall hkaSkeletonMapper::~hkaSkeletonMapper(hkaSkeletonMapper *this)
{
  hkaSkeletonMapperData *p_m_mapping; // rcx

  p_m_mapping = &this->m_mapping;
  *(_QWORD *)&p_m_mapping[-1].m_keepUnmappedLocal.m_bool = &hkaSkeletonMapper::`vftable;
  hkaSkeletonMapperData::~hkaSkeletonMapperData(p_m_mapping);
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
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
         _mm_cmple_ps(v5, (__m128)0i64),
         _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v6, v5), v6)), _mm_mul_ps(*(__m128 *)_xmm, v6)));
  A->m_quad = _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), A->m_quad);
  B->m_quad = _mm_mul_ps(_mm_shuffle_ps(v7, v7, 255), B->m_quad);
}

// File Line: 63
// RVA: 0xB24980
__int64 __fastcall getBoneIndexFromPartition(
        bool mapToFullPose,
        unsigned int boneIndex,
        int partitionStartIndex,
        int offset)
{
  if ( mapToFullPose )
    return boneIndex;
  else
    return offset + boneIndex - partitionStartIndex;
}

// File Line: 68
// RVA: 0xB20C10
void __fastcall hkaSkeletonMapper::mapPose(
        hkaSkeletonMapper *this,
        hkQsTransformf *poseAModelSpace,
        hkQsTransformf *originalPoseBLocalSpace,
        hkQsTransformf *poseBModelSpace,
        hkaSkeletonMapper::ConstraintSource source)
{
  _QWORD *Value; // rax
  unsigned __int64 v10; // rcx
  _QWORD *v11; // r8
  unsigned __int64 v12; // rax
  _QWORD *v13; // r8
  _QWORD *v14; // rcx
  unsigned __int64 v15; // rax
  _QWORD *v16; // rcx
  __int64 m_size; // r10
  __int64 v18; // r14
  int v19; // r11d
  __int64 v20; // r9
  hkaSkeletonMapperData::SimpleMapping *m_data; // r8
  __m128 m_quad; // xmm3
  hkQsTransformf *v23; // rdx
  __int64 m_boneB; // rcx
  __m128 v25; // xmm2
  __m128 v26; // xmm1
  __m128 v27; // xmm6
  __m128 v28; // xmm5
  __m128 v29; // xmm4
  __m128 v30; // xmm6
  __m128 v31; // xmm2
  __m128 v32; // xmm4
  __m128 v33; // xmm0
  __m128 v34; // xmm5
  __m128 v35; // xmm3
  __m128 v36; // xmm6
  __m128 v37; // xmm3
  __m128 v38; // xmm3
  _QWORD *v39; // r8
  _QWORD *v40; // rcx
  unsigned __int64 v41; // rax
  _QWORD *v42; // rcx
  unsigned __int64 v43; // rdx
  hkaSkeletonMapperData::ChainMapping *v44; // r9
  char *v45; // r8
  int v46; // r15d
  __m128 v47; // xmm3
  hkQsTransformf *v48; // rcx
  __int64 v49; // r12
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __m128 v52; // xmm6
  __m128 v53; // xmm5
  __m128 v54; // xmm4
  __m128 v55; // xmm6
  __m128 v56; // xmm2
  __m128 v57; // xmm4
  __m128 v58; // xmm0
  __m128 v59; // xmm5
  __m128 v60; // xmm3
  __m128 v61; // xmm6
  __m128 v62; // xmm3
  __m128 v63; // xmm3
  int v64; // ebx
  hkLifoAllocator *v65; // rcx
  __int16 *m_cur; // rax
  int v67; // edx
  hkaSkeleton *m_pntr; // rdx
  int v69; // r9d
  __int16 *v70; // r8
  __int64 v71; // rdx
  hkVector4f v72; // xmm6
  __int64 v73; // rax
  hkQuaternionf v74; // xmm2
  __m128 v75; // xmm4
  __m128 v76; // xmm5
  __m128 v77; // xmm1
  __m128 v78; // xmm3
  __m128 v79; // xmm6
  __m128 v80; // xmm6
  hkQuaternionf v81; // xmm2
  __m128 v82; // xmm1
  __m128 v83; // xmm4
  __m128 v84; // xmm3
  __m128 v85; // xmm7
  __m128 v86; // xmm2
  __m128 v87; // xmm7
  __m128 v88; // xmm5
  __m128 v89; // xmm3
  __m128 v90; // xmm1
  __m128 v91; // xmm4
  __m128 v92; // xmm6
  __m128 v93; // xmm6
  __m128 v94; // xmm1
  __m128 v95; // xmm3
  float v96; // xmm1_4
  __m128 v97; // xmm7
  __m128 v98; // xmm2
  __m128 v99; // xmm6
  __m128 v100; // xmm6
  __m128 v101; // xmm9
  __m128 v102; // xmm2
  __m128 v103; // xmm1
  __m128 v104; // xmm5
  __m128 v105; // xmm3
  __m128 v106; // xmm2
  __m128 v107; // xmm1
  __m128 v108; // xmm6
  int v109; // r11d
  __m128 v110; // xmm4
  hkQuaternionf v111; // xmm2
  __m128 v112; // xmm5
  __m128 v113; // xmm0
  __m128 v114; // xmm1
  __m128 v115; // xmm3
  __m128 v116; // xmm6
  __m128 v117; // xmm3
  __m128 v118; // xmm3
  __int64 v119; // r10
  __int64 v120; // rdx
  hkQsTransformf *v121; // rcx
  hkVector4f v122; // xmm3
  __m128 v123; // xmm2
  __m128 v124; // xmm1
  __m128 v125; // xmm6
  __m128 v126; // xmm5
  __m128 v127; // xmm4
  __m128 v128; // xmm6
  hkQuaternionf v129; // xmm2
  __m128 v130; // xmm4
  __m128 v131; // xmm0
  __m128 v132; // xmm5
  __m128 v133; // xmm3
  __m128 v134; // xmm6
  __m128 v135; // xmm3
  __m128 v136; // xmm3
  char *v137; // r15
  signed int v138; // ebx
  hkLifoAllocator *v139; // rax
  int v140; // r8d
  bool v141; // zf
  _QWORD *v142; // rax
  _QWORD *v143; // rcx
  _QWORD *v144; // r8
  unsigned __int64 v145; // rax
  _QWORD *v146; // rcx
  __int64 v147; // r8
  __int64 v148; // rdx
  __int16 v149; // ax
  __int64 v150; // rdx
  hkQsTransformf *v151; // rcx
  hkVector4f v152; // xmm3
  __m128 v153; // xmm2
  __m128 v154; // xmm1
  __m128 v155; // xmm6
  __m128 v156; // xmm5
  __m128 v157; // xmm4
  __m128 v158; // xmm6
  hkQuaternionf v159; // xmm2
  __m128 v160; // xmm4
  __m128 v161; // xmm0
  __m128 v162; // xmm5
  __m128 v163; // xmm3
  __m128 v164; // xmm6
  __m128 v165; // xmm3
  __m128 v166; // xmm3
  __int64 v167; // rax
  _QWORD *v168; // rax
  _QWORD *v169; // rcx
  _QWORD *v170; // r8
  unsigned __int64 v171; // rax
  _QWORD *v172; // rcx
  _QWORD *v173; // rax
  _QWORD *v174; // rcx
  _QWORD *v175; // r8
  unsigned __int64 v176; // rax
  _QWORD *v177; // rcx
  __int16 v178; // [rsp+30h] [rbp-C8h]
  __int16 v179; // [rsp+32h] [rbp-C6h]
  hkArray<short,hkContainerHeapAllocator> bonesOut; // [rsp+38h] [rbp-C0h] BYREF
  void *p; // [rsp+48h] [rbp-B0h]
  int v182; // [rsp+50h] [rbp-A8h]
  int v183; // [rsp+58h] [rbp-A0h]
  unsigned __int64 v184; // [rsp+60h] [rbp-98h]
  int v185; // [rsp+68h] [rbp-90h]
  __int64 v186; // [rsp+70h] [rbp-88h]
  hkQuaternionf v187; // [rsp+78h] [rbp-80h] BYREF
  hkVector4f A; // [rsp+88h] [rbp-70h] BYREF
  hkaSkeletonMapperData::ChainMapping *v189; // [rsp+98h] [rbp-60h]
  hkVector4f B; // [rsp+A8h] [rbp-50h] BYREF
  void *retaddr; // [rsp+168h] [rbp+70h] BYREF
  hkQsTransformf *v192; // [rsp+170h] [rbp+78h]
  int v193; // [rsp+188h] [rbp+90h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = Value[1];
  v11 = Value;
  if ( v10 < Value[3] )
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
    v16 = v14 + 2;
    *((_DWORD *)v16 - 2) = v15;
    v13[1] = v16;
  }
  m_size = this->m_mapping.m_simpleMappings.m_size;
  v18 = 0i64;
  v19 = 0;
  if ( m_size > 0 )
  {
    v20 = 0i64;
    do
    {
      m_data = this->m_mapping.m_simpleMappings.m_data;
      _mm_prefetch((const char *)&m_data[v19 + 2], 0);
      m_quad = m_data[v20].m_aFromBTransform.m_translation.m_quad;
      v23 = &poseAModelSpace[m_data[v20].m_boneA];
      m_boneB = m_data[v20].m_boneB;
      v25 = v23->m_rotation.m_vec.m_quad;
      v26 = _mm_mul_ps(m_quad, v25);
      v27 = _mm_shuffle_ps(v25, v25, 255);
      v28 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v25),
              _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), m_quad));
      v29 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                    _mm_shuffle_ps(v26, v26, 170)),
                  v25),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v27, v27), (__m128)xmmword_141A711B0), m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v27));
      poseBModelSpace[m_boneB].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v29, v29), v23->m_translation.m_quad);
      v30 = v23->m_rotation.m_vec.m_quad;
      v31 = m_data[v20].m_aFromBTransform.m_rotation.m_vec.m_quad;
      v32 = _mm_shuffle_ps(v30, v30, 255);
      v33 = _mm_mul_ps(_mm_shuffle_ps(v30, v30, 201), v31);
      v34 = _mm_shuffle_ps(v31, v31, 255);
      v35 = _mm_mul_ps(_mm_shuffle_ps(v31, v31, 201), v30);
      v36 = _mm_mul_ps(v30, v31);
      v37 = _mm_sub_ps(v35, v33);
      v38 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v37, v37, 201), _mm_mul_ps(v31, v32)),
              _mm_mul_ps(v23->m_rotation.m_vec.m_quad, v34));
      poseBModelSpace[m_boneB].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                           v38,
                                                           _mm_unpackhi_ps(
                                                             v38,
                                                             _mm_sub_ps(
                                                               _mm_mul_ps(v34, v32),
                                                               _mm_add_ps(
                                                                 _mm_add_ps(
                                                                   _mm_shuffle_ps(v36, v36, 85),
                                                                   _mm_shuffle_ps(v36, v36, 0)),
                                                                 _mm_shuffle_ps(v36, v36, 170)))),
                                                           196);
      poseBModelSpace[m_boneB].m_scale.m_quad = _mm_mul_ps(
                                                  m_data[v20].m_aFromBTransform.m_scale.m_quad,
                                                  v23->m_scale.m_quad);
      _mm_prefetch((const char *)&poseAModelSpace[m_data[v20].m_boneA + 2].m_scale, 0);
      _mm_prefetch((const char *)&poseBModelSpace[m_data[v20].m_boneB + 2].m_scale, 0);
      ++v19;
      ++v20;
      --m_size;
    }
    while ( m_size );
  }
  v39 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v40 = (_QWORD *)v39[1];
  if ( (unsigned __int64)v40 < v39[3] )
  {
    *v40 = "StchainMappings";
    v41 = __rdtsc();
    v42 = v40 + 2;
    *((_DWORD *)v42 - 2) = v41;
    v39[1] = v42;
  }
  v186 = this->m_mapping.m_chainMappings.m_size;
  if ( v186 > 0 )
  {
    v43 = 0i64;
    v184 = 0i64;
    while ( 1 )
    {
      v44 = this->m_mapping.m_chainMappings.m_data;
      v189 = v44;
      v45 = (char *)*(__int16 *)((char *)&v44->m_startBoneB + v43);
      v46 = *(__int16 *)((char *)&v44->m_endBoneB + v43);
      v47 = *(__m128 *)((char *)&v44->m_startAFromBTransform.m_translation.m_quad + v43);
      v178 = *(__int16 *)((char *)&v44->m_endBoneA + v43);
      v179 = *(__int16 *)((char *)&v44->m_startBoneB + v43);
      v48 = &poseAModelSpace[*(__int16 *)((char *)&v44->m_startBoneA + v43)];
      v49 = (__int64)v45;
      v50 = v48->m_rotation.m_vec.m_quad;
      v51 = _mm_mul_ps(v47, v50);
      v52 = _mm_shuffle_ps(v50, v50, 255);
      v53 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v50), _mm_mul_ps(_mm_shuffle_ps(v50, v50, 201), v47));
      v54 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v51, v51, 85), _mm_shuffle_ps(v51, v51, 0)),
                    _mm_shuffle_ps(v51, v51, 170)),
                  v50),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v52, v52), (__m128)xmmword_141A711B0), v47)),
              _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v52));
      poseBModelSpace[v49].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v54, v54), v48->m_translation.m_quad);
      v55 = v48->m_rotation.m_vec.m_quad;
      v56 = *(__m128 *)((char *)&v44->m_startAFromBTransform.m_rotation.m_vec.m_quad + v43);
      v57 = _mm_shuffle_ps(v55, v55, 255);
      v58 = _mm_mul_ps(_mm_shuffle_ps(v55, v55, 201), v56);
      v59 = _mm_shuffle_ps(v56, v56, 255);
      v60 = _mm_mul_ps(_mm_shuffle_ps(v56, v56, 201), v55);
      v61 = _mm_mul_ps(v55, v56);
      v62 = _mm_sub_ps(v60, v58);
      v63 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v62, v62, 201), _mm_mul_ps(v56, v57)),
              _mm_mul_ps(v48->m_rotation.m_vec.m_quad, v59));
      poseBModelSpace[v49].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                       v63,
                                                       _mm_unpackhi_ps(
                                                         v63,
                                                         _mm_sub_ps(
                                                           _mm_mul_ps(v59, v57),
                                                           _mm_add_ps(
                                                             _mm_add_ps(
                                                               _mm_shuffle_ps(v61, v61, 85),
                                                               _mm_shuffle_ps(v61, v61, 0)),
                                                             _mm_shuffle_ps(v61, v61, 170)))),
                                                       196);
      poseBModelSpace[v49].m_scale.m_quad = _mm_mul_ps(
                                              *(__m128 *)((char *)&v44->m_startAFromBTransform.m_scale.m_quad + v43),
                                              v48->m_scale.m_quad);
      bonesOut.m_data = 0i64;
      bonesOut.m_size = 0;
      bonesOut.m_capacityAndFlags = 0x80000000;
      v64 = v46 - (_DWORD)v45 + 1;
      v182 = v64;
      if ( v46 - (_DWORD)v45 == -1 )
      {
        m_cur = 0i64;
      }
      else
      {
        v65 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (__int16 *)v65->m_cur;
        v67 = (2 * v64 + 127) & 0xFFFFFF80;
        v45 = (char *)m_cur + v67;
        if ( v67 > v65->m_slabSize || v45 > v65->m_end )
        {
          m_cur = (__int16 *)hkLifoAllocator::allocateFromNewSlab(v65, v67);
          LOWORD(v45) = v179;
        }
        else
        {
          v65->m_cur = v45;
          LOWORD(v45) = v179;
        }
      }
      m_pntr = this->m_mapping.m_skeletonB.m_pntr;
      bonesOut.m_data = m_cur;
      p = m_cur;
      bonesOut.m_capacityAndFlags = v64 | 0x80000000;
      hkaSkeletonUtils::getBoneChain((hkBool *)&retaddr, m_pntr, (__int16)v45, v46, &bonesOut);
      v69 = bonesOut.m_size;
      v70 = bonesOut.m_data;
      v71 = bonesOut.m_size - 2;
      for ( v72.m_quad = (__m128)originalPoseBLocalSpace[(__int16)v46].m_translation;
            v71 >= 1;
            v72.m_quad = _mm_add_ps(_mm_add_ps(v79, v79), originalPoseBLocalSpace[v73].m_translation.m_quad) )
      {
        v73 = bonesOut.m_data[v71--];
        v74.m_vec.m_quad = (__m128)originalPoseBLocalSpace[v73].m_rotation;
        v75 = _mm_mul_ps(originalPoseBLocalSpace[v73].m_scale.m_quad, v72.m_quad);
        v76 = _mm_shuffle_ps(v74.m_vec.m_quad, v74.m_vec.m_quad, 255);
        v77 = _mm_mul_ps(v75, v74.m_vec.m_quad);
        v78 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v75, v75, 201), v74.m_vec.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v74.m_vec.m_quad, v74.m_vec.m_quad, 201), v75));
        v79 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0)),
                      _mm_shuffle_ps(v77, v77, 170)),
                    v74.m_vec.m_quad),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v76, v76), (__m128)xmmword_141A711B0), v75)),
                _mm_mul_ps(_mm_shuffle_ps(v78, v78, 201), v76));
      }
      v80 = _mm_mul_ps(v72.m_quad, poseBModelSpace[v49].m_scale.m_quad);
      v81.m_vec.m_quad = (__m128)poseBModelSpace[v49].m_rotation;
      v82 = _mm_mul_ps(v80, v81.m_vec.m_quad);
      v83 = _mm_shuffle_ps(v81.m_vec.m_quad, v81.m_vec.m_quad, 255);
      v84 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v80, v80, 201), v81.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v81.m_vec.m_quad, v81.m_vec.m_quad, 201), v80));
      v85 = _mm_mul_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v82, v82, 85), _mm_shuffle_ps(v82, v82, 0)),
                _mm_shuffle_ps(v82, v82, 170)),
              v81.m_vec.m_quad);
      v86 = v192[v178].m_rotation.m_vec.m_quad;
      v87 = _mm_add_ps(
              _mm_add_ps(v85, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v83, v83), (__m128)xmmword_141A711B0), v80)),
              _mm_mul_ps(_mm_shuffle_ps(v84, v84, 201), v83));
      v88 = _mm_shuffle_ps(v86, v86, 255);
      v89 = v189[v184 / 0x70].m_endAFromBTransform.m_translation.m_quad;
      v90 = _mm_mul_ps(v89, v86);
      A.m_quad = _mm_sub_ps(
                   _mm_add_ps(_mm_add_ps(v87, v87), poseBModelSpace[v49].m_translation.m_quad),
                   poseBModelSpace[v49].m_translation.m_quad);
      v91 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v89, v89, 201), v86), _mm_mul_ps(_mm_shuffle_ps(v86, v86, 201), v89));
      v92 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v90, v90, 85), _mm_shuffle_ps(v90, v90, 0)),
                    _mm_shuffle_ps(v90, v90, 170)),
                  v86),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v88, v88), (__m128)xmmword_141A711B0), v89)),
              _mm_mul_ps(_mm_shuffle_ps(v91, v91, 201), v88));
      B.m_quad = _mm_sub_ps(
                   _mm_add_ps(_mm_add_ps(v92, v92), v192[v178].m_translation.m_quad),
                   poseBModelSpace[v49].m_translation.m_quad);
      if ( ((_mm_movemask_ps(_mm_cmpeq_ps(A.m_quad, (__m128)0i64)) & 7) == 7) | ((_mm_movemask_ps(_mm_cmpeq_ps(B.m_quad, (__m128)0i64)) & 7) == 7) )
        break;
      normalize3TwoAtOnce(&A, &B);
      v183 = 1065353048;
      v94 = _mm_mul_ps(B.m_quad, A.m_quad);
      v95 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v94, v94, 85), _mm_shuffle_ps(v94, v94, 0)),
              _mm_shuffle_ps(v94, v94, 170));
      v96 = _mm_shuffle_ps((__m128)0x3F7FFF58u, (__m128)0x3F7FFF58u, 0).m128_f32[0];
      if ( v95.m128_f32[0] > v96 )
      {
        v93 = qi.m_vec.m_quad;
        goto LABEL_29;
      }
      if ( v95.m128_f32[0] >= (float)(0.0 - v96) )
      {
        v185 = -1082147209;
        v97 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v95), (__m128)xmmword_141A711B0);
        v98 = _mm_rsqrt_ps(v97);
        v99 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(B.m_quad, B.m_quad, 201), A.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(A.m_quad, A.m_quad, 201), B.m_quad));
        v100 = _mm_shuffle_ps(v99, v99, 201);
        v101 = _mm_andnot_ps(
                 _mm_cmple_ps(v97, (__m128)0i64),
                 _mm_mul_ps(
                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v97, v98), v98)),
                   _mm_mul_ps(*(__m128 *)_xmm, v98)));
        v102 = _mm_mul_ps(v101, (__m128)xmmword_141A711B0);
        if ( v95.m128_f32[0] < _mm_shuffle_ps((__m128)0xBF7FBE77, (__m128)0xBF7FBE77, 0).m128_f32[0] )
        {
          v103 = _mm_mul_ps(v100, v100);
          v104 = _mm_sub_ps(v97, v95);
          v105 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v103, v103, 85), _mm_shuffle_ps(v103, v103, 0)),
                   _mm_shuffle_ps(v103, v103, 170));
          v106 = _mm_rsqrt_ps(v105);
          v107 = _mm_rsqrt_ps(v104);
          v102 = _mm_mul_ps(
                   _mm_mul_ps(
                     _mm_andnot_ps(
                       _mm_cmple_ps(v104, (__m128)0i64),
                       _mm_mul_ps(
                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v107, v104), v107)),
                         _mm_mul_ps(v107, *(__m128 *)_xmm))),
                     v104),
                   _mm_andnot_ps(
                     _mm_cmple_ps(v105, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v106, v105), v106)),
                       _mm_mul_ps(v106, *(__m128 *)_xmm))));
        }
        v108 = _mm_mul_ps(v100, v102);
        v93 = _mm_shuffle_ps(v108, _mm_unpackhi_ps(v108, _mm_mul_ps(v97, v101)), 196);
        goto LABEL_29;
      }
      hkQuaternionf::setFlippedRotation(&v187, &A);
      v69 = bonesOut.m_size;
      v70 = bonesOut.m_data;
      v93 = v187.m_vec.m_quad;
LABEL_30:
      v109 = 1;
      v110 = _mm_shuffle_ps(v93, v93, 255);
      v111.m_vec.m_quad = (__m128)poseBModelSpace[v49].m_rotation;
      v112 = _mm_shuffle_ps(v111.m_vec.m_quad, v111.m_vec.m_quad, 255);
      v113 = _mm_mul_ps(_mm_shuffle_ps(v93, v93, 201), v111.m_vec.m_quad);
      v114 = _mm_mul_ps(v93, v112);
      v115 = _mm_mul_ps(_mm_shuffle_ps(v111.m_vec.m_quad, v111.m_vec.m_quad, 201), v93);
      v116 = _mm_mul_ps(v93, v111.m_vec.m_quad);
      v117 = _mm_sub_ps(v115, v113);
      v118 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v117, v117, 201), _mm_mul_ps(v111.m_vec.m_quad, v110)), v114);
      poseBModelSpace[v49].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                       v118,
                                                       _mm_unpackhi_ps(
                                                         v118,
                                                         _mm_sub_ps(
                                                           _mm_mul_ps(v112, v110),
                                                           _mm_add_ps(
                                                             _mm_add_ps(
                                                               _mm_shuffle_ps(v116, v116, 85),
                                                               _mm_shuffle_ps(v116, v116, 0)),
                                                             _mm_shuffle_ps(v116, v116, 170)))),
                                                       196);
      if ( v69 - 1 > 1 )
      {
        v119 = 1i64;
        do
        {
          ++v109;
          v120 = v70[v119];
          v121 = &poseBModelSpace[v70[v119++ - 1]];
          v122.m_quad = (__m128)originalPoseBLocalSpace[v120].m_translation;
          v123 = v121->m_rotation.m_vec.m_quad;
          v124 = _mm_mul_ps(v122.m_quad, v123);
          v125 = _mm_shuffle_ps(v123, v123, 255);
          v126 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v122.m_quad, v122.m_quad, 201), v123),
                   _mm_mul_ps(_mm_shuffle_ps(v123, v123, 201), v122.m_quad));
          v127 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v124, v124, 85), _mm_shuffle_ps(v124, v124, 0)),
                         _mm_shuffle_ps(v124, v124, 170)),
                       v123),
                     _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v125, v125), (__m128)xmmword_141A711B0), v122.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v126, v126, 201), v125));
          poseBModelSpace[v120].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v127, v127), v121->m_translation.m_quad);
          v128 = v121->m_rotation.m_vec.m_quad;
          v129.m_vec.m_quad = (__m128)originalPoseBLocalSpace[v120].m_rotation;
          v130 = _mm_shuffle_ps(v128, v128, 255);
          v131 = _mm_mul_ps(_mm_shuffle_ps(v128, v128, 201), v129.m_vec.m_quad);
          v132 = _mm_shuffle_ps(v129.m_vec.m_quad, v129.m_vec.m_quad, 255);
          v133 = _mm_mul_ps(_mm_shuffle_ps(v129.m_vec.m_quad, v129.m_vec.m_quad, 201), v128);
          v134 = _mm_mul_ps(v128, v129.m_vec.m_quad);
          v135 = _mm_sub_ps(v133, v131);
          v136 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v135, v135, 201), _mm_mul_ps(v129.m_vec.m_quad, v130)),
                   _mm_mul_ps(v121->m_rotation.m_vec.m_quad, v132));
          poseBModelSpace[v120].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                            v136,
                                                            _mm_unpackhi_ps(
                                                              v136,
                                                              _mm_sub_ps(
                                                                _mm_mul_ps(v132, v130),
                                                                _mm_add_ps(
                                                                  _mm_add_ps(
                                                                    _mm_shuffle_ps(v134, v134, 85),
                                                                    _mm_shuffle_ps(v134, v134, 0)),
                                                                  _mm_shuffle_ps(v134, v134, 170)))),
                                                            196);
          poseBModelSpace[v120].m_scale.m_quad = _mm_mul_ps(
                                                   v121->m_scale.m_quad,
                                                   originalPoseBLocalSpace[v120].m_scale.m_quad);
          v69 = bonesOut.m_size;
          v70 = bonesOut.m_data;
        }
        while ( v109 < bonesOut.m_size - 1 );
      }
      v137 = (char *)p;
      if ( p == v70 )
        v69 = 0;
      v138 = (2 * v182 + 127) & 0xFFFFFF80;
      bonesOut.m_size = v69;
      v139 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v140 = (v138 + 15) & 0xFFFFFFF0;
      if ( v138 > v139->m_slabSize || &v137[v140] != v139->m_cur || v139->m_firstNonLifoEnd == v137 )
        hkLifoAllocator::slowBlockFree(v139, v137, v140);
      else
        v139->m_cur = v137;
      bonesOut.m_size = 0;
      if ( bonesOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          bonesOut.m_data,
          2 * (bonesOut.m_capacityAndFlags & 0x3FFFFFFF));
      poseAModelSpace = v192;
      v43 = v184 + 112;
      v141 = v186-- == 1;
      v184 += 112i64;
      if ( v141 )
        goto LABEL_43;
    }
    v93 = qi.m_vec.m_quad;
LABEL_29:
    v187.m_vec.m_quad = v93;
    goto LABEL_30;
  }
LABEL_43:
  v142 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v143 = (_QWORD *)v142[1];
  v144 = v142;
  if ( (unsigned __int64)v143 < v142[3] )
  {
    *v143 = "StunmappedBones";
    v145 = __rdtsc();
    v146 = v143 + 2;
    *((_DWORD *)v146 - 2) = v145;
    v144[1] = v146;
  }
  if ( this->m_mapping.m_keepUnmappedLocal.m_bool )
  {
    v147 = this->m_mapping.m_unmappedBones.m_size;
    if ( v147 > 0 )
    {
      do
      {
        v148 = this->m_mapping.m_unmappedBones.m_data[v18];
        v149 = this->m_mapping.m_skeletonB.m_pntr->m_parentIndices.m_data[v148];
        if ( v149 == -1 )
        {
          v167 = v148;
          poseBModelSpace[v167].m_translation = originalPoseBLocalSpace[v148].m_translation;
          poseBModelSpace[v167].m_rotation = originalPoseBLocalSpace[v148].m_rotation;
          poseBModelSpace[v167].m_scale = originalPoseBLocalSpace[v148].m_scale;
        }
        else
        {
          v150 = v148;
          v151 = &poseBModelSpace[v149];
          v152.m_quad = (__m128)originalPoseBLocalSpace[v150].m_translation;
          v153 = v151->m_rotation.m_vec.m_quad;
          v154 = _mm_mul_ps(v152.m_quad, v153);
          v155 = _mm_shuffle_ps(v153, v153, 255);
          v156 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v152.m_quad, v152.m_quad, 201), v153),
                   _mm_mul_ps(_mm_shuffle_ps(v153, v153, 201), v152.m_quad));
          v157 = _mm_add_ps(
                   _mm_add_ps(
                     _mm_mul_ps(
                       _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v154, v154, 85), _mm_shuffle_ps(v154, v154, 0)),
                         _mm_shuffle_ps(v154, v154, 170)),
                       v153),
                     _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v155, v155), (__m128)xmmword_141A711B0), v152.m_quad)),
                   _mm_mul_ps(_mm_shuffle_ps(v156, v156, 201), v155));
          poseBModelSpace[v150].m_translation.m_quad = _mm_add_ps(_mm_add_ps(v157, v157), v151->m_translation.m_quad);
          v158 = v151->m_rotation.m_vec.m_quad;
          v159.m_vec.m_quad = (__m128)originalPoseBLocalSpace[v150].m_rotation;
          v160 = _mm_shuffle_ps(v158, v158, 255);
          v161 = _mm_mul_ps(_mm_shuffle_ps(v158, v158, 201), v159.m_vec.m_quad);
          v162 = _mm_shuffle_ps(v159.m_vec.m_quad, v159.m_vec.m_quad, 255);
          v163 = _mm_mul_ps(_mm_shuffle_ps(v159.m_vec.m_quad, v159.m_vec.m_quad, 201), v158);
          v164 = _mm_mul_ps(v158, v159.m_vec.m_quad);
          v165 = _mm_sub_ps(v163, v161);
          v166 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v165, v165, 201), _mm_mul_ps(v159.m_vec.m_quad, v160)),
                   _mm_mul_ps(v151->m_rotation.m_vec.m_quad, v162));
          poseBModelSpace[v150].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                            v166,
                                                            _mm_unpackhi_ps(
                                                              v166,
                                                              _mm_sub_ps(
                                                                _mm_mul_ps(v162, v160),
                                                                _mm_add_ps(
                                                                  _mm_add_ps(
                                                                    _mm_shuffle_ps(v164, v164, 85),
                                                                    _mm_shuffle_ps(v164, v164, 0)),
                                                                  _mm_shuffle_ps(v164, v164, 170)))),
                                                            196);
          poseBModelSpace[v150].m_scale.m_quad = _mm_mul_ps(
                                                   v151->m_scale.m_quad,
                                                   originalPoseBLocalSpace[v150].m_scale.m_quad);
        }
        ++v18;
      }
      while ( v18 < v147 );
    }
  }
  v168 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v169 = (_QWORD *)v168[1];
  v170 = v168;
  if ( (unsigned __int64)v169 < v168[3] )
  {
    *v169 = "StenforceConstraints";
    v171 = __rdtsc();
    v172 = v169 + 2;
    *((_DWORD *)v172 - 2) = v171;
    v170[1] = v172;
  }
  if ( v193 == 1 )
  {
    hkaSkeletonUtils::enforceSkeletonConstraintsModelSpace(this->m_mapping.m_skeletonB.m_pntr, poseBModelSpace);
  }
  else if ( v193 == 2 )
  {
    hkaSkeletonUtils::enforcePoseConstraintsModelSpace(
      this->m_mapping.m_skeletonB.m_pntr,
      originalPoseBLocalSpace,
      poseBModelSpace);
  }
  v173 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v174 = (_QWORD *)v173[1];
  v175 = v173;
  if ( (unsigned __int64)v174 < v173[3] )
  {
    *v174 = "lt";
    v176 = __rdtsc();
    v177 = v174 + 2;
    *((_DWORD *)v177 - 2) = v176;
    v175[1] = v177;
  }
}

// File Line: 275
// RVA: 0xB21950
void __fastcall hkaSkeletonMapper::mapPoseLocalSpace(
        hkaSkeletonMapper *this,
        hkQsTransformf *poseALocalSpace,
        hkQsTransformf *poseBLocalSpaceInOut,
        bool additive)
{
  hkaSkeletonMapper::mapPoseLocalSpace(this, poseALocalSpace, poseBLocalSpaceInOut, 0i64, 0i64, additive, 0i64, 0i64);
}

// File Line: 289
// RVA: 0xB22E20
void __fastcall hkaSkeletonMapper::mapPoseLocalSpaceInternal(
        hkaSkeletonMapperData *mapping,
        hkQsTransformf *poseALocalSpaceOriginal,
        hkQsTransformf *poseBLocalSpaceInOut,
        const __int16 *boneToTrackIndicesA,
        __int16 *boneToTrackIndicesB,
        hkArray<short,hkContainerHeapAllocator> *partitionIndicesA,
        bool additive,
        float *mapToFullPose,
        float *weightsA,
        float *weightsBOut)
{
  hkQsTransformf *v10; // rbx
  hkQsTransformf *v12; // rdi
  hkQsTransformf *v13; // rbx
  _QWORD *Value; // r8
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rax
  __int64 v17; // r12
  int v18; // esi
  hkLifoAllocator *v19; // rcx
  hkaSkeleton::Partition *m_cur; // rax
  int v21; // edx
  char *v22; // r8
  hkaSkeleton *m_pntr; // rcx
  int v24; // esi
  int m_size; // edx
  hkLifoAllocator *v26; // rax
  hkaSkeleton::Partition *v27; // r8
  int v28; // edx
  char *v29; // rcx
  hkaSkeleton::Partition *v30; // rax
  int v31; // r14d
  __int64 v32; // r8
  hkaSkeleton::Partition *v33; // rsi
  hkaSkeleton::Partition *v34; // rbx
  _QWORD *v35; // r8
  _QWORD *v36; // rcx
  unsigned __int64 v37; // rax
  _QWORD *v38; // rcx
  __int16 NumberOfBonesInPartitions; // si
  __int16 v40; // r12
  LPVOID v41; // rax
  int v42; // edx
  char *v43; // rcx
  __int16 v44; // cx
  int v45; // r14d
  hkLifoAllocator *v46; // rcx
  const float *v47; // rax
  int v48; // edx
  char *v49; // r8
  float *v50; // r12
  hkQsTransformf *v51; // rcx
  char v52; // r14
  hkQsTransformf *v53; // rsi
  __int64 v54; // rsi
  int v55; // ebx
  hkLifoAllocator *v56; // rax
  int v57; // edi
  char *v58; // rbx
  int v59; // r12d
  char *v60; // rcx
  __int16 *v61; // r14
  int v62; // edi
  hkaSkeleton *v63; // r9
  __int64 v64; // rsi
  int v65; // r10d
  __int64 v66; // rdx
  int v67; // r8d
  __int64 v68; // r11
  char *v69; // rdx
  int v70; // edx
  int v71; // r9d
  __int64 v72; // rcx
  __int16 *v73; // rax
  __int64 v74; // rsi
  __int64 v75; // rcx
  __int64 v76; // rdi
  hkaSkeleton::Partition *v77; // rdx
  hkaSkeleton *v78; // rax
  __int64 v79; // r11
  hkaSkeletonMapperData::PartitionMappingRange *v80; // rax
  __int64 m_numMappings; // r8
  __int64 m_startMappingIndex; // rcx
  __int64 v83; // r12
  __int64 v84; // rsi
  hkaSkeletonMapperData::SimpleMapping *v85; // r11
  __int64 v86; // r11
  bool v87; // cl
  __int64 BoneIndexFromPartition; // rbx
  __int64 v89; // r10
  __int64 v90; // r11
  hkQsTransformf *v91; // r14
  __int64 v92; // rsi
  hkQsTransformf *v93; // rdi
  bool v94; // zf
  hkaSkeletonMapperData::PartitionMappingRange *v95; // rax
  __int64 v96; // r14
  __int64 v97; // r14
  hkaSkeletonMapperData::ChainMapping *v98; // r12
  __m128 v99; // xmm6
  __m128 v100; // xmm7
  int v101; // esi
  int v102; // ecx
  int v103; // eax
  int m_startBoneIndex; // ecx
  int v105; // eax
  __int64 v106; // r10
  __m128 *p_m_quad; // rcx
  __m128 v108; // xmm3
  __m128 v109; // xmm2
  __m128 v110; // xmm5
  __m128 v111; // xmm4
  __m128 v112; // xmm1
  bool v113; // cc
  __m128 v114; // xmm6
  __m128 v115; // xmm1
  __m128 v116; // xmm4
  __m128 v117; // xmm2
  int v118; // eax
  __int64 v119; // r10
  __int16 v120; // r10
  int v121; // esi
  __m128 v122; // xmm8
  __int16 v123; // r10
  hkQsTransformf *v124; // rax
  __m128 v125; // xmm2
  __m128 v126; // xmm1
  __m128 v127; // xmm5
  __m128 v128; // xmm6
  __m128 v129; // xmm4
  __m128 v130; // xmm4
  hkaSkeleton *v131; // rax
  int v132; // edi
  __int64 v133; // r11
  __int64 v134; // rsi
  int v135; // ebx
  bool v136; // cl
  bool v137; // cl
  int v138; // eax
  int v139; // edx
  bool v140; // cl
  int v141; // r11d
  int v142; // eax
  int v143; // ecx
  __int64 v144; // r10
  __m128 v145; // xmm1
  __m128 v146; // xmm4
  float v147; // xmm1_4
  __m128 v148; // xmm7
  __m128 v149; // xmm6
  __m128 v150; // xmm2
  __m128 v151; // xmm11
  __m128 v152; // xmm8
  __m128 v153; // xmm7
  __m128 v154; // xmm7
  __m128 v155; // xmm1
  __m128 v156; // xmm5
  __m128 v157; // xmm2
  __m128 v158; // xmm4
  __m128 v159; // xmm3
  __m128 v160; // xmm7
  __m128 v161; // xmm1
  __int64 v162; // rdx
  hkQuaternionf v163; // xmm2
  __m128 v164; // xmm6
  __m128 v165; // xmm3
  __m128 v166; // xmm6
  __m128 v167; // xmm0
  __m128 v168; // xmm7
  __m128 v169; // xmm6
  __m128 v170; // xmm0
  __m128 v171; // xmm6
  __m128 v172; // xmm4
  __m128 v173; // xmm5
  __m128 v174; // xmm0
  __m128 v175; // xmm6
  __m128 v176; // xmm5
  __m128 v177; // xmm6
  __m128 v178; // xmm2
  __m128 v179; // xmm4
  __m128 v180; // xmm5
  __m128 v181; // xmm3
  __m128 v182; // xmm6
  __m128 v183; // xmm3
  __int16 v184; // r10
  __m128 v185; // xmm1
  __m128 v186; // xmm6
  __m128 v187; // xmm1
  __m128 v188; // xmm2
  __m128 i; // xmm7
  __int16 v190; // r10
  hkLifoAllocator *v191; // rax
  int v192; // r8d
  __int64 v193; // r10
  int v194; // eax
  __int64 v195; // r13
  hkaSkeletonMapperData::SimpleMapping *m_data; // r8
  __int64 m_boneA; // rdx
  __int64 m_boneB; // r9
  __int64 v199; // rsi
  hkQsTransformf *v200; // r14
  __int64 v201; // rbx
  hkQsTransformf *v202; // rdi
  _QWORD *v203; // r8
  _QWORD *v204; // rcx
  unsigned __int64 v205; // rax
  _QWORD *v206; // rcx
  __int64 v207; // rcx
  float *v208; // r13
  hkQsTransformf *v209; // r9
  __int64 v210; // rbx
  hkaSkeletonMapperData::ChainMapping *v211; // rdi
  __m128 v212; // xmm6
  char v213; // r10
  int m_startBoneA; // r11d
  int m_endBoneA; // edx
  __m128 v216; // xmm7
  __int16 v217; // cx
  hkQsTransformf *v218; // rcx
  __m128 m_quad; // xmm3
  __m128 v220; // xmm2
  __m128 v221; // xmm5
  __m128 v222; // xmm4
  __m128 v223; // xmm6
  __m128 v224; // xmm1
  __m128 v225; // xmm4
  __m128 v226; // xmm2
  hkQsTransformf *v227; // r10
  __int16 m_endBoneB; // dx
  int v229; // r9d
  __m128 v230; // xmm8
  __int16 v231; // cx
  hkQsTransformf *v232; // rcx
  __m128 v233; // xmm2
  hkaSkeleton *v234; // rax
  __m128 v235; // xmm1
  __m128 v236; // xmm5
  __m128 v237; // xmm6
  __m128 v238; // xmm4
  __int64 v239; // rcx
  __int64 m_startBoneB; // rdx
  __int64 v241; // r9
  int m_storage; // ecx
  __m128 v243; // xmm1
  __m128 v244; // xmm4
  float v245; // xmm1_4
  __m128 v246; // xmm7
  __m128 v247; // xmm6
  __m128 v248; // xmm2
  __m128 v249; // xmm11
  __m128 v250; // xmm8
  __m128 v251; // xmm7
  __m128 v252; // xmm7
  __m128 v253; // xmm1
  __m128 v254; // xmm5
  __m128 v255; // xmm2
  __m128 v256; // xmm4
  __m128 v257; // xmm3
  __m128 v258; // xmm7
  __m128 v259; // xmm1
  hkQuaternionf v260; // xmm2
  __m128 v261; // xmm6
  __m128 v262; // xmm3
  __m128 v263; // xmm6
  __m128 v264; // xmm0
  __m128 v265; // xmm7
  __m128 v266; // xmm6
  __m128 v267; // xmm0
  __m128 v268; // xmm6
  __m128 v269; // xmm4
  __m128 v270; // xmm5
  __m128 v271; // xmm0
  __m128 v272; // xmm6
  __m128 v273; // xmm5
  __m128 v274; // xmm6
  __m128 v275; // xmm2
  __m128 v276; // xmm4
  __m128 v277; // xmm5
  __m128 v278; // xmm3
  __m128 v279; // xmm6
  __m128 v280; // xmm3
  __int16 v281; // cx
  __m128 v282; // xmm1
  __m128 v283; // xmm2
  __m128 v284; // xmm1
  __m128 v285; // xmm0
  __m128 v286; // xmm3
  __int16 v287; // dx
  signed int v288; // ebx
  hkLifoAllocator *v289; // rax
  int v290; // r8d
  _QWORD *v291; // r8
  _QWORD *v292; // rcx
  unsigned __int64 v293; // rax
  _QWORD *v294; // rcx
  signed int v295; // ebx
  hkLifoAllocator *v296; // rax
  int v297; // r8d
  char *v298; // rsi
  int v299; // edi
  hkaSkeleton::Partition *v300; // rbx
  signed int v301; // ebx
  hkLifoAllocator *v302; // rax
  int v303; // r8d
  int v304; // edi
  hkaSkeleton::Partition *v305; // rbx
  char *v306; // rsi
  int v307; // edi
  hkaSkeleton::Partition *v308; // rbx
  signed int v309; // ebx
  hkLifoAllocator *v310; // rax
  int v311; // r8d
  int v312; // edi
  hkaSkeleton::Partition *v313; // rbx
  bool v314; // [rsp+30h] [rbp-C8h]
  hkaSkeleton::Partition *v315; // [rsp+38h] [rbp-C0h]
  __int64 v316; // [rsp+38h] [rbp-C0h]
  int v317; // [rsp+40h] [rbp-B8h]
  int v318; // [rsp+40h] [rbp-B8h]
  __int16 v319; // [rsp+44h] [rbp-B4h]
  hkQsTransformf *v320; // [rsp+48h] [rbp-B0h]
  __int64 v321; // [rsp+50h] [rbp-A8h]
  int v322; // [rsp+50h] [rbp-A8h]
  int v323; // [rsp+58h] [rbp-A0h]
  __int64 v324; // [rsp+60h] [rbp-98h]
  __int64 v325; // [rsp+60h] [rbp-98h]
  __int64 v326; // [rsp+60h] [rbp-98h]
  int v327; // [rsp+68h] [rbp-90h]
  hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> array; // [rsp+70h] [rbp-88h] BYREF
  int v329; // [rsp+80h] [rbp-78h]
  __int64 v330; // [rsp+88h] [rbp-70h]
  hkVector4f B; // [rsp+98h] [rbp-60h] BYREF
  char *v332; // [rsp+A8h] [rbp-50h]
  float *v333; // [rsp+B0h] [rbp-48h]
  __int64 v334; // [rsp+B8h] [rbp-40h]
  int numBones; // [rsp+C0h] [rbp-38h]
  __int64 v336; // [rsp+C8h] [rbp-30h]
  hkArray<hkaSkeleton::Partition,hkContainerHeapAllocator> partitionsOut; // [rsp+D0h] [rbp-28h] BYREF
  void *v338; // [rsp+E0h] [rbp-18h]
  int v339; // [rsp+E8h] [rbp-10h]
  __int64 v340; // [rsp+F0h] [rbp-8h]
  __int64 v341; // [rsp+F8h] [rbp+0h]
  hkQsTransformf *combinedPoseOut; // [rsp+100h] [rbp+8h]
  hkVector4f A; // [rsp+108h] [rbp+10h] BYREF
  hkQuaternionf v344; // [rsp+118h] [rbp+20h] BYREF
  int v345; // [rsp+128h] [rbp+30h]
  int v346; // [rsp+12Ch] [rbp+34h]
  hkQsTransformf *v347; // [rsp+130h] [rbp+38h]
  void *retaddr; // [rsp+1F8h] [rbp+100h]
  hkQsTransformf *additivePoseOut; // [rsp+208h] [rbp+110h]
  int boneToTrackIndicesa; // [rsp+210h] [rbp+118h]
  int boneToTrackIndicesBa; // [rsp+220h] [rbp+128h]
  int boneToTrackIndicesBb; // [rsp+220h] [rbp+128h]

  additivePoseOut = v10;
  v12 = poseBLocalSpaceInOut;
  v13 = poseALocalSpaceOriginal;
  v320 = poseALocalSpaceOriginal;
  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v15 = Value[1];
  if ( v15 < Value[3] )
  {
    *(_QWORD *)v15 = "LtMapPoseLocalSpace";
    *(_QWORD *)(v15 + 16) = "Stinit";
    v16 = __rdtsc();
    *(_DWORD *)(v15 + 8) = v16;
    Value[1] = v15 + 24;
  }
  v17 = 0i64;
  partitionsOut.m_capacityAndFlags = 0x80000000;
  v18 = *((_DWORD *)boneToTrackIndicesB + 2);
  partitionsOut.m_data = 0i64;
  partitionsOut.m_size = 0;
  v339 = v18;
  if ( v18 )
  {
    v19 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkaSkeleton::Partition *)v19->m_cur;
    v21 = (16 * v18 + 127) & 0xFFFFFF80;
    v22 = (char *)m_cur + v21;
    if ( v21 > v19->m_slabSize || v22 > v19->m_end )
      m_cur = (hkaSkeleton::Partition *)hkLifoAllocator::allocateFromNewSlab(v19, v21);
    else
      v19->m_cur = v22;
  }
  else
  {
    m_cur = 0i64;
  }
  m_pntr = mapping->m_skeletonA.m_pntr;
  partitionsOut.m_data = m_cur;
  partitionsOut.m_capacityAndFlags = v18 | 0x80000000;
  v338 = m_cur;
  hkaPartitionedAnimationUtility::getPartitionsFromIndices(
    m_pntr,
    (hkArray<short,hkContainerHeapAllocator> *)boneToTrackIndicesB,
    &partitionsOut);
  v24 = *((_DWORD *)boneToTrackIndicesB + 2);
  m_size = 0;
  array.m_data = 0i64;
  v329 = v24;
  *(_QWORD *)&array.m_size = 0x8000000000000000ui64;
  if ( v24 )
  {
    v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v27 = (hkaSkeleton::Partition *)v26->m_cur;
    v28 = (16 * v24 + 127) & 0xFFFFFF80;
    v29 = (char *)v27 + v28;
    if ( v28 > v26->m_slabSize || v29 > v26->m_end )
    {
      v30 = (hkaSkeleton::Partition *)hkLifoAllocator::allocateFromNewSlab(v26, v28);
      m_size = array.m_size;
      array.m_data = v30;
    }
    else
    {
      v26->m_cur = v29;
      m_size = array.m_size;
      array.m_data = v27;
    }
  }
  else
  {
    array.m_data = 0i64;
  }
  v31 = 0;
  array.m_size = (int)array.m_data;
  array.m_capacityAndFlags = v24 | 0x80000000;
  if ( *((int *)boneToTrackIndicesB + 2) > 0 )
  {
    do
    {
      v32 = mapping->m_partitionMap.m_data[*(__int16 *)(*(_QWORD *)boneToTrackIndicesB + v17)];
      if ( (int)v32 >= 0 )
      {
        v33 = &mapping->m_skeletonB.m_pntr->m_partitions.m_data[v32];
        if ( m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 16);
          m_size = array.m_size;
        }
        v34 = &array.m_data[m_size];
        if ( v34 )
        {
          hkStringPtr::hkStringPtr(&v34->m_name, &v33->m_name);
          v34->m_startBoneIndex = v33->m_startBoneIndex;
          v34->m_numBones = v33->m_numBones;
          m_size = array.m_size;
        }
        array.m_size = ++m_size;
      }
      ++v31;
      v17 += 2i64;
    }
    while ( v31 < *((_DWORD *)boneToTrackIndicesB + 2) );
    v13 = v320;
  }
  v35 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v36 = (_QWORD *)v35[1];
  if ( (unsigned __int64)v36 < v35[3] )
  {
    *v36 = "StsimpleMappings";
    v37 = __rdtsc();
    v38 = v36 + 2;
    *((_DWORD *)v38 - 2) = v37;
    v35[1] = v38;
  }
  v314 = *((_DWORD *)boneToTrackIndicesB + 2) == 0;
  if ( !*((_DWORD *)boneToTrackIndicesB + 2) || additive )
  {
    NumberOfBonesInPartitions = mapping->m_skeletonA.m_pntr->m_bones.m_size;
    if ( !*((_DWORD *)boneToTrackIndicesB + 2) || additive )
    {
      v40 = mapping->m_skeletonB.m_pntr->m_bones.m_size;
      v319 = v40;
      goto LABEL_33;
    }
  }
  else
  {
    NumberOfBonesInPartitions = hkaPartitionedAnimationUtility::getNumberOfBonesInPartitions(&partitionsOut);
  }
  v40 = hkaPartitionedAnimationUtility::getNumberOfBonesInPartitions(&array);
  v319 = v40;
LABEL_33:
  numBones = NumberOfBonesInPartitions;
  v41 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  combinedPoseOut = (hkQsTransformf *)*((_QWORD *)v41 + 3);
  v42 = (48 * NumberOfBonesInPartitions + 127) & 0xFFFFFF80;
  v43 = (char *)combinedPoseOut + v42;
  if ( v42 > *((_DWORD *)v41 + 4) || (unsigned __int64)v43 > *((_QWORD *)v41 + 4) )
    combinedPoseOut = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab((hkLifoAllocator *)v41, v42);
  else
    *((_QWORD *)v41 + 3) = v43;
  v323 = 0;
  if ( weightsA )
  {
    v50 = mapToFullPose;
  }
  else
  {
    v44 = v40;
    if ( NumberOfBonesInPartitions > v40 )
      v44 = NumberOfBonesInPartitions;
    v45 = v44;
    v323 = v44;
    v46 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v47 = (const float *)v46->m_cur;
    v48 = (4 * v45 + 127) & 0xFFFFFF80;
    weightsA = (float *)v47;
    v49 = (char *)v47 + v48;
    if ( v48 > v46->m_slabSize || v49 > v46->m_end )
    {
      weightsA = (float *)hkLifoAllocator::allocateFromNewSlab(v46, v48);
      v50 = weightsA;
    }
    else
    {
      v46->m_cur = v49;
      v50 = (float *)v47;
    }
  }
  v51 = poseBLocalSpaceInOut;
  v333 = v50;
  v52 = poseBLocalSpaceInOut && boneToTrackIndicesA;
  LOBYTE(retaddr) = v52;
  if ( (_BYTE)partitionIndicesA )
  {
    v53 = combinedPoseOut;
    hkaSkeletonMapper::combinedPoseFromAdditivePoseAndReferencePose(
      v13,
      mapping->m_skeletonA.m_pntr->m_referencePose.m_data,
      (const __int16 *)poseBLocalSpaceInOut,
      0,
      numBones,
      combinedPoseOut);
    v51 = poseBLocalSpaceInOut;
    v13 = v53;
    v320 = v53;
  }
  v54 = v323;
  v334 = v323;
  if ( v314 )
  {
    v193 = mapping->m_simpleMappings.m_size;
    v194 = 0;
    boneToTrackIndicesBa = 0;
    v325 = v193;
    if ( v193 <= 0 )
      goto LABEL_115;
    v195 = 0i64;
    while ( 1 )
    {
      m_data = mapping->m_simpleMappings.m_data;
      _mm_prefetch((const char *)&m_data[v194 + 2], 0);
      m_boneA = m_data[v195].m_boneA;
      m_boneB = m_data[v195].m_boneB;
      if ( !v52 )
        goto LABEL_112;
      LODWORD(m_boneA) = v51->m_translation.m_quad.m128_i16[m_boneA];
      if ( (int)m_boneA >= 0 )
        break;
LABEL_113:
      ++v195;
      v194 = boneToTrackIndicesBa + 1;
      v325 = --v193;
      ++boneToTrackIndicesBa;
      if ( !v193 )
      {
        v54 = v334;
LABEL_115:
        v203 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v204 = (_QWORD *)v203[1];
        if ( (unsigned __int64)v204 < v203[3] )
        {
          *v204 = "StchainMappings";
          v205 = __rdtsc();
          v206 = v204 + 2;
          *((_DWORD *)v206 - 2) = v205;
          v203[1] = v206;
        }
        v207 = mapping->m_chainMappings.m_size;
        v316 = v207;
        if ( v207 <= 0 )
          goto LABEL_164;
        v208 = weightsA;
        v209 = poseBLocalSpaceInOut;
        v210 = 0i64;
        while ( 2 )
        {
          v211 = mapping->m_chainMappings.m_data;
          B.m_quad = 0i64;
          v212 = 0i64;
          v213 = 1;
          m_startBoneA = v211[v210].m_startBoneA;
          m_endBoneA = v211[v210].m_endBoneA;
          v344.m_vec.m_quad = 0i64;
          v216 = 0i64;
          if ( m_endBoneA > m_startBoneA )
          {
            while ( 1 )
            {
              v217 = v52 ? v209->m_translation.m_quad.m128_i16[(__int16)m_endBoneA] : m_endBoneA;
              if ( v217 < 0 || !v54 && v50[(__int16)m_endBoneA] == 0.0 )
                break;
              v218 = &v320[v217];
              m_quad = v218->m_rotation.m_vec.m_quad;
              v220 = _mm_mul_ps(m_quad, v212);
              v221 = _mm_shuffle_ps(m_quad, m_quad, 255);
              v222 = _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v212, v212, 201), m_quad),
                       _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v212));
              m_endBoneA = mapping->m_skeletonA.m_pntr->m_parentIndices.m_data[(__int16)m_endBoneA];
              v223 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v220, v220, 85), _mm_shuffle_ps(v220, v220, 0)),
                             _mm_shuffle_ps(v220, v220, 170)),
                           m_quad),
                         _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v221, v221), (__m128)xmmword_141A711B0), v212)),
                       _mm_mul_ps(_mm_shuffle_ps(v222, v222, 201), v221));
              v212 = _mm_add_ps(_mm_add_ps(v223, v223), v218->m_translation.m_quad);
              v224 = _mm_mul_ps(v218->m_translation.m_quad, v218->m_translation.m_quad);
              v344.m_vec.m_quad = v212;
              v225 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v224, v224, 85), _mm_shuffle_ps(v224, v224, 0)),
                       _mm_shuffle_ps(v224, v224, 170));
              v226 = _mm_rsqrt_ps(v225);
              v216 = _mm_add_ps(
                       v216,
                       _mm_andnot_ps(
                         _mm_cmple_ps(v225, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v226, v225), v226)),
                             _mm_mul_ps(*(__m128 *)_xmm, v226)),
                           v225)));
              if ( m_endBoneA <= m_startBoneA )
                goto LABEL_129;
            }
            v213 = 0;
LABEL_129:
            v207 = v316;
          }
          if ( v52 )
          {
            if ( v213 )
            {
              v227 = poseBLocalSpaceInOut;
              if ( poseBLocalSpaceInOut->m_translation.m_quad.m128_i16[(__int16)m_startBoneA] >= 0
                && (v54 > 0 || v50[(__int16)m_startBoneA] != 0.0) )
              {
LABEL_138:
                m_endBoneB = v211[v210].m_endBoneB;
                v229 = 1;
                v318 = 1;
                v230 = _mm_mul_ps(v211[v210].m_endAFromBTransform.m_scale.m_quad, v216);
                if ( m_endBoneB > v211[v210].m_startBoneB )
                {
                  do
                  {
                    if ( v52 )
                      v231 = boneToTrackIndicesA[m_endBoneB];
                    else
                      v231 = m_endBoneB;
                    ++v229;
                    v232 = &additivePoseOut[v231];
                    v232->m_translation.m_quad = _mm_mul_ps(v230, v232->m_translation.m_quad);
                    v233 = v232->m_rotation.m_vec.m_quad;
                    v234 = mapping->m_skeletonB.m_pntr;
                    v235 = _mm_mul_ps(v233, B.m_quad);
                    v236 = _mm_sub_ps(
                             _mm_mul_ps(_mm_shuffle_ps(B.m_quad, B.m_quad, 201), v233),
                             _mm_mul_ps(_mm_shuffle_ps(v233, v233, 201), B.m_quad));
                    v237 = _mm_shuffle_ps(v233, v233, 255);
                    v238 = _mm_add_ps(
                             _mm_add_ps(
                               _mm_mul_ps(
                                 _mm_add_ps(
                                   _mm_add_ps(_mm_shuffle_ps(v235, v235, 85), _mm_shuffle_ps(v235, v235, 0)),
                                   _mm_shuffle_ps(v235, v235, 170)),
                                 v233),
                               _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v237, v237), (__m128)xmmword_141A711B0), B.m_quad)),
                             _mm_mul_ps(_mm_shuffle_ps(v236, v236, 201), v237));
                    B.m_quad = _mm_add_ps(v238, v238);
                    B.m_quad = _mm_add_ps(B.m_quad, v232->m_translation.m_quad);
                    m_endBoneB = v234->m_parentIndices.m_data[m_endBoneB];
                  }
                  while ( m_endBoneB > v211[v210].m_startBoneB );
                  v208 = weightsA;
                  v318 = v229;
                }
                v239 = v211[v210].m_startBoneA;
                m_startBoneB = v211[v210].m_startBoneB;
                boneToTrackIndicesBb = v211[v210].m_endBoneA;
                LODWORD(retaddr) = v211[v210].m_endBoneB;
                if ( v52 )
                {
                  LODWORD(v239) = v227->m_translation.m_quad.m128_i16[v239];
                  LODWORD(m_startBoneB) = boneToTrackIndicesA[m_startBoneB];
                  boneToTrackIndicesBb = v227->m_translation.m_quad.m128_i16[v211[v210].m_endBoneA];
                  LODWORD(retaddr) = boneToTrackIndicesA[v211[v210].m_endBoneB];
                }
                v241 = (int)v239;
                m_storage = mapping->m_mappingType.m_storage;
                v326 = v241;
                v347 = &additivePoseOut[(int)m_startBoneB];
                hkaSkeletonMapper::setMulWithScaling(
                  (hkaSkeletonMapperData::MappingType)m_storage,
                  v347,
                  &v211[v210].m_startAFromBTransform,
                  &v320[v241]);
                normalize3TwoAtOnce(&v344.m_vec, &B);
                v243 = _mm_mul_ps(B.m_quad, v344.m_vec.m_quad);
                v244 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v243, v243, 85), _mm_shuffle_ps(v243, v243, 0)),
                         _mm_shuffle_ps(v243, v243, 170));
                v245 = _mm_shuffle_ps((__m128)0x3F7FFF58u, (__m128)0x3F7FFF58u, 0).m128_f32[0];
                if ( v244.m128_f32[0] > v245 )
                {
                  v246 = qi.m_vec.m_quad;
                  goto LABEL_153;
                }
                if ( v244.m128_f32[0] >= (float)(0.0 - v245) )
                {
                  v247 = _mm_add_ps(_mm_mul_ps(v244, (__m128)xmmword_141A711B0), (__m128)xmmword_141A711B0);
                  v248 = _mm_rsqrt_ps(v247);
                  v249 = _mm_andnot_ps(
                           _mm_cmple_ps(v247, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v247, v248), v248)),
                             _mm_mul_ps(*(__m128 *)_xmm, v248)));
                  v250 = _mm_mul_ps(v249, (__m128)xmmword_141A711B0);
                  v251 = _mm_sub_ps(
                           _mm_mul_ps(_mm_shuffle_ps(v344.m_vec.m_quad, v344.m_vec.m_quad, 201), B.m_quad),
                           _mm_mul_ps(_mm_shuffle_ps(B.m_quad, B.m_quad, 201), v344.m_vec.m_quad));
                  v252 = _mm_shuffle_ps(v251, v251, 201);
                  if ( v244.m128_f32[0] < _mm_shuffle_ps((__m128)0xBF7FBE77, (__m128)0xBF7FBE77, 0).m128_f32[0] )
                  {
                    v253 = _mm_mul_ps(v252, v252);
                    v254 = _mm_sub_ps(v247, v244);
                    v255 = _mm_rsqrt_ps(v254);
                    v256 = _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v253, v253, 85), _mm_shuffle_ps(v253, v253, 0)),
                             _mm_shuffle_ps(v253, v253, 170));
                    v257 = _mm_rsqrt_ps(v256);
                    v250 = _mm_mul_ps(
                             _mm_mul_ps(
                               _mm_andnot_ps(
                                 _mm_cmple_ps(v254, (__m128)0i64),
                                 _mm_mul_ps(
                                   _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v255, v254), v255)),
                                   _mm_mul_ps(*(__m128 *)_xmm, v255))),
                               v254),
                             _mm_andnot_ps(
                               _mm_cmple_ps(v256, (__m128)0i64),
                               _mm_mul_ps(
                                 _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v257, v256), v257)),
                                 _mm_mul_ps(*(__m128 *)_xmm, v257))));
                  }
                  v258 = _mm_mul_ps(v252, v250);
                  v246 = _mm_shuffle_ps(v258, _mm_unpackhi_ps(v258, _mm_mul_ps(v247, v249)), 196);
LABEL_153:
                  A.m_quad = v246;
                }
                else
                {
                  hkQuaternionf::setFlippedRotation((hkQuaternionf *)&A, &B);
                  v246 = A.m_quad;
                }
                v259 = v211[v210].m_endAFromBTransform.m_translation.m_quad;
                v260.m_vec.m_quad = (__m128)v347->m_rotation;
                v261 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v246, v246, 201), v259),
                         _mm_mul_ps(_mm_shuffle_ps(v259, v259, 201), v246));
                v262 = _mm_shuffle_ps(v260.m_vec.m_quad, v260.m_vec.m_quad, 255);
                v263 = _mm_sub_ps(_mm_shuffle_ps(v261, v261, 201), _mm_mul_ps(_mm_shuffle_ps(v246, v246, 255), v259));
                v264 = _mm_mul_ps(_mm_shuffle_ps(v259, v259, 255), v246);
                v265 = _mm_mul_ps(v246, v259);
                v266 = _mm_add_ps(v263, v264);
                v267 = _mm_add_ps(_mm_shuffle_ps(v265, v265, 78), v265);
                v268 = _mm_shuffle_ps(
                         v266,
                         _mm_unpackhi_ps(v266, _mm_add_ps(_mm_shuffle_ps(v267, v267, 177), v267)),
                         196);
                v269 = _mm_shuffle_ps(v268, v268, 255);
                v270 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v268, v268, 201), v260.m_vec.m_quad),
                         _mm_mul_ps(_mm_shuffle_ps(v260.m_vec.m_quad, v260.m_vec.m_quad, 201), v268));
                v271 = _mm_mul_ps(v268, v262);
                v272 = _mm_mul_ps(v268, v260.m_vec.m_quad);
                v273 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v270, v270, 201), v271),
                         _mm_mul_ps(v260.m_vec.m_quad, v269));
                v347->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                  v273,
                                                  _mm_unpackhi_ps(
                                                    v273,
                                                    _mm_sub_ps(
                                                      _mm_mul_ps(v269, v262),
                                                      _mm_add_ps(
                                                        _mm_add_ps(
                                                          _mm_shuffle_ps(v272, v272, 85),
                                                          _mm_shuffle_ps(v272, v272, 0)),
                                                        _mm_shuffle_ps(v272, v272, 170)))),
                                                  196);
                v274 = v211[v210].m_endAFromBTransform.m_rotation.m_vec.m_quad;
                v275 = v320[boneToTrackIndicesBb].m_rotation.m_vec.m_quad;
                v276 = _mm_shuffle_ps(v274, v274, 255);
                v277 = _mm_shuffle_ps(v275, v275, 255);
                v278 = _mm_sub_ps(
                         _mm_mul_ps(_mm_shuffle_ps(v275, v275, 201), v274),
                         _mm_mul_ps(_mm_shuffle_ps(v274, v274, 201), v275));
                v279 = _mm_mul_ps(v274, v275);
                v280 = _mm_add_ps(
                         _mm_add_ps(_mm_shuffle_ps(v278, v278, 201), _mm_mul_ps(v275, v276)),
                         _mm_mul_ps(v211[v210].m_endAFromBTransform.m_rotation.m_vec.m_quad, v277));
                additivePoseOut[(int)retaddr].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                                          v280,
                                                                          _mm_unpackhi_ps(
                                                                            v280,
                                                                            _mm_sub_ps(
                                                                              _mm_mul_ps(v277, v276),
                                                                              _mm_add_ps(
                                                                                _mm_add_ps(
                                                                                  _mm_shuffle_ps(v279, v279, 85),
                                                                                  _mm_shuffle_ps(v279, v279, 0)),
                                                                                _mm_shuffle_ps(v279, v279, 170)))),
                                                                          196);
                if ( !v54 )
                {
                  v281 = v211[v210].m_endBoneB;
                  v282 = 0i64;
                  v283 = _mm_shuffle_ps(
                           (__m128)LODWORD(v50[boneToTrackIndicesBb]),
                           (__m128)LODWORD(v50[boneToTrackIndicesBb]),
                           0);
                  v282.m128_f32[0] = (float)(v318 - 1);
                  v284 = _mm_shuffle_ps(v282, v282, 0);
                  v285 = _mm_rcp_ps(v284);
                  v286 = _mm_mul_ps(
                           _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v284, v285)), v285),
                           _mm_sub_ps(_mm_shuffle_ps((__m128)LODWORD(v50[v326]), (__m128)LODWORD(v50[v326]), 0), v283));
                  if ( v281 >= v211[v210].m_startBoneB )
                  {
                    do
                    {
                      if ( v52 )
                        v287 = boneToTrackIndicesA[v281];
                      else
                        v287 = v281;
                      v208[v287] = v283.m128_f32[0];
                      v283 = _mm_add_ps(v283, v286);
                      v281 = mapping->m_skeletonB.m_pntr->m_parentIndices.m_data[v281];
                    }
                    while ( v281 >= v211[v210].m_startBoneB );
                    v54 = v334;
                  }
                }
                v207 = v316;
              }
              v209 = poseBLocalSpaceInOut;
            }
          }
          else if ( v213 )
          {
            v227 = poseBLocalSpaceInOut;
            goto LABEL_138;
          }
          ++v210;
          v316 = --v207;
          if ( !v207 )
            goto LABEL_164;
          continue;
        }
      }
    }
    LODWORD(m_boneB) = boneToTrackIndicesA[m_boneB];
LABEL_112:
    v199 = (int)m_boneA;
    v200 = &v13[(int)m_boneA];
    v201 = (int)m_boneB;
    v202 = &v12[(int)m_boneB];
    hkaSkeletonMapper::setMulWithScaling(
      (hkaSkeletonMapperData::MappingType)mapping->m_mappingType.m_storage,
      v202,
      &m_data[v195].m_aFromBTransform,
      v200);
    weightsA[v201] = v50[v199];
    _mm_prefetch((const char *)&v200[2].m_scale, 0);
    _mm_prefetch((const char *)&v202[2].m_scale, 0);
    v52 = (char)retaddr;
    v12 = additivePoseOut;
    v13 = v320;
    v51 = poseBLocalSpaceInOut;
    v193 = v325;
    goto LABEL_113;
  }
  v55 = mapping->m_skeletonB.m_pntr->m_partitions.m_size;
  v56 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v57 = 2 * v55;
  v58 = (char *)v56->m_cur;
  v59 = (v57 + 127) & 0xFFFFFF80;
  v332 = v58;
  v327 = v59;
  v60 = &v58[v59];
  if ( v59 > v56->m_slabSize || v60 > v56->m_end )
  {
    v58 = (char *)hkLifoAllocator::allocateFromNewSlab(v56, v59);
    v332 = v58;
  }
  else
  {
    v56->m_cur = v60;
  }
  hkString::memSet(v58, 0, v57);
  v61 = boneToTrackIndicesB;
  v62 = 0;
  if ( *((int *)boneToTrackIndicesB + 2) > 0 )
  {
    v63 = mapping->m_skeletonB.m_pntr;
    v64 = 0i64;
    v65 = v63->m_partitions.m_size;
    do
    {
      v66 = mapping->m_partitionMap.m_data[*(__int16 *)(*(_QWORD *)boneToTrackIndicesB + v64)];
      v67 = v66 + 1;
      if ( (int)v66 + 1 < v65 )
      {
        v68 = v66;
        v69 = &v58[2 * v67];
        do
        {
          ++v67;
          v69 += 2;
          *((_WORD *)v69 - 1) += v63->m_partitions.m_data[v68].m_numBones;
          v63 = mapping->m_skeletonB.m_pntr;
          v65 = v63->m_partitions.m_size;
        }
        while ( v67 < v65 );
      }
      ++v62;
      v64 += 2i64;
    }
    while ( v62 < *((_DWORD *)boneToTrackIndicesB + 2) );
  }
  v70 = 0;
  v71 = 0;
  boneToTrackIndicesa = 0;
  v317 = 0;
  if ( *((int *)boneToTrackIndicesB + 2) > 0 )
  {
    v72 = 0i64;
    v324 = 0i64;
    do
    {
      v73 = mapping->m_partitionMap.m_data;
      v74 = *(__int16 *)(*(_QWORD *)v61 + v72);
      v340 = v74;
      v75 = v73[v74];
      if ( (int)v75 >= 0 )
      {
        v76 = v73[v74];
        v77 = &mapping->m_skeletonA.m_pntr->m_partitions.m_data[v74];
        v78 = mapping->m_skeletonB.m_pntr;
        v330 = v75;
        v79 = (__int64)&v78->m_partitions.m_data[v75];
        v80 = mapping->m_simpleMappingPartitionRanges.m_data;
        v315 = v77;
        m_numMappings = v80[v74].m_numMappings;
        m_startMappingIndex = v80[v74].m_startMappingIndex;
        v336 = v79;
        LODWORD(retaddr) = m_startMappingIndex;
        v341 = m_numMappings;
        if ( m_numMappings > 0 )
        {
          v83 = v79;
          v84 = m_startMappingIndex << 6;
          v321 = m_startMappingIndex << 6;
          do
          {
            v85 = mapping->m_simpleMappings.m_data;
            _mm_prefetch((const char *)&v85[(int)m_startMappingIndex + 2], 0);
            getBoneIndexFromPartition(additive, *(__int16 *)((char *)&v85->m_boneA + v84), v77->m_startBoneIndex, v71);
            BoneIndexFromPartition = getBoneIndexFromPartition(
                                       v87,
                                       *(__int16 *)(v86 + v84 + 2),
                                       *(__int16 *)(v83 + 8),
                                       *(__int16 *)&v58[2 * v76]);
            v91 = &v320[v89];
            v92 = v89;
            v93 = &additivePoseOut[BoneIndexFromPartition];
            hkaSkeletonMapper::setMulWithScaling(
              (hkaSkeletonMapperData::MappingType)mapping->m_mappingType.m_storage,
              v93,
              (hkQsTransformf *)(v90 + v321 + 16),
              v91);
            weightsA[BoneIndexFromPartition] = v333[v92];
            _mm_prefetch((const char *)&v91[2].m_scale, 0);
            _mm_prefetch((const char *)&v93[2].m_scale, 0);
            v58 = v332;
            v76 = v330;
            v71 = boneToTrackIndicesa;
            v77 = v315;
            LODWORD(m_startMappingIndex) = (_DWORD)retaddr + 1;
            v84 = v321 + 64;
            v94 = v341-- == 1;
            LODWORD(retaddr) = (_DWORD)retaddr + 1;
            v321 += 64i64;
          }
          while ( !v94 );
          v74 = v340;
          v79 = v83;
        }
        v95 = mapping->m_chainMappingPartitionRanges.m_data;
        v96 = v95[v74].m_startMappingIndex;
        v340 = v95[v74].m_numMappings;
        if ( v340 > 0 )
        {
          v97 = v96;
          while ( 1 )
          {
            v98 = mapping->m_chainMappings.m_data;
            B.m_quad = 0i64;
            v99 = 0i64;
            A.m_quad = 0i64;
            v100 = 0i64;
            v101 = v98[v97].m_endBoneA;
            v102 = v98[v97].m_startBoneA;
            v103 = v101;
            if ( v101 <= v102 )
              break;
            m_startBoneIndex = v77->m_startBoneIndex;
            LODWORD(retaddr) = m_startBoneIndex;
            while ( 1 )
            {
              v105 = getBoneIndexFromPartition(additive, v103, m_startBoneIndex, v71);
              if ( v105 < 0 || !v334 && *(float *)(v106 + 4i64 * v105) == 0.0 )
                break;
              p_m_quad = &v320[v105].m_translation.m_quad;
              v108 = p_m_quad[1];
              v109 = _mm_mul_ps(v99, v108);
              v110 = _mm_shuffle_ps(v108, v108, 255);
              v111 = _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(v99, v99, 201), v108),
                       _mm_mul_ps(_mm_shuffle_ps(v108, v108, 201), v99));
              v112 = *p_m_quad;
              v101 = mapping->m_skeletonA.m_pntr->m_parentIndices.m_data[(__int16)v101];
              v113 = v101 <= v98[v97].m_startBoneA;
              m_startBoneIndex = (int)retaddr;
              v103 = v101;
              v114 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v109, v109, 85), _mm_shuffle_ps(v109, v109, 0)),
                             _mm_shuffle_ps(v109, v109, 170)),
                           v108),
                         _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v110, v110), (__m128)xmmword_141A711B0), v99)),
                       _mm_mul_ps(_mm_shuffle_ps(v111, v111, 201), v110));
              v99 = _mm_add_ps(_mm_add_ps(v114, v114), v112);
              v115 = _mm_mul_ps(v112, v112);
              A.m_quad = v99;
              v116 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v115, v115, 85), _mm_shuffle_ps(v115, v115, 0)),
                       _mm_shuffle_ps(v115, v115, 170));
              v117 = _mm_rsqrt_ps(v116);
              v100 = _mm_add_ps(
                       v100,
                       _mm_andnot_ps(
                         _mm_cmple_ps(v116, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v117, v116), v117)),
                             _mm_mul_ps(*(__m128 *)_xmm, v117)),
                           v116)));
              if ( v113 )
              {
                v102 = v98[v97].m_startBoneA;
                goto LABEL_79;
              }
            }
LABEL_98:
            ++v97;
            if ( !--v340 )
              goto LABEL_99;
            v77 = v315;
          }
LABEL_79:
          if ( v334 <= 0 )
          {
            v118 = getBoneIndexFromPartition(additive, v102, v315->m_startBoneIndex, v71);
            if ( *(float *)(v119 + 4i64 * v118) == 0.0 )
              goto LABEL_98;
          }
          v120 = v98[v97].m_endBoneB;
          v121 = 1;
          LODWORD(retaddr) = 1;
          v122 = _mm_mul_ps(v98[v97].m_endAFromBTransform.m_scale.m_quad, v100);
          if ( v120 > v98[v97].m_startBoneB )
          {
            do
            {
              ++v121;
              v124 = &additivePoseOut[getBoneIndexFromPartition(
                                        additive,
                                        v120,
                                        *(__int16 *)(v79 + 8),
                                        *(__int16 *)&v58[2 * v76])];
              v124->m_translation.m_quad = _mm_mul_ps(v124->m_translation.m_quad, v122);
              v125 = v124->m_rotation.m_vec.m_quad;
              v126 = _mm_mul_ps(B.m_quad, v125);
              v127 = _mm_sub_ps(
                       _mm_mul_ps(_mm_shuffle_ps(B.m_quad, B.m_quad, 201), v125),
                       _mm_mul_ps(_mm_shuffle_ps(v125, v125, 201), B.m_quad));
              v128 = _mm_shuffle_ps(v125, v125, 255);
              v129 = _mm_add_ps(
                       _mm_add_ps(
                         _mm_mul_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v126, v126, 85), _mm_shuffle_ps(v126, v126, 0)),
                             _mm_shuffle_ps(v126, v126, 170)),
                           v125),
                         _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v128, v128), (__m128)xmmword_141A711B0), B.m_quad)),
                       _mm_mul_ps(_mm_shuffle_ps(v127, v127, 201), v128));
              B.m_quad = _mm_add_ps(v129, v129);
              v130 = _mm_add_ps(B.m_quad, v124->m_translation.m_quad);
              v131 = mapping->m_skeletonB.m_pntr;
              B.m_quad = v130;
              v120 = v131->m_parentIndices.m_data[v123];
            }
            while ( v120 > v98[v97].m_startBoneB );
            LODWORD(retaddr) = v121;
          }
          v132 = v315->m_startBoneIndex;
          v134 = getBoneIndexFromPartition(additive, v98[v97].m_startBoneA, v132, boneToTrackIndicesa);
          v135 = *(__int16 *)&v58[2 * v330];
          getBoneIndexFromPartition(v136, v98[v97].m_startBoneB, *(__int16 *)(v133 + 8), v135);
          v138 = getBoneIndexFromPartition(v137, v98[v97].m_endBoneA, v132, boneToTrackIndicesa);
          v139 = v98[v97].m_endBoneB;
          LODWORD(v341) = v138;
          v142 = getBoneIndexFromPartition(v140, v139, v141, v135);
          v143 = mapping->m_mappingType.m_storage;
          v347 = &additivePoseOut[v144];
          v322 = v142;
          hkaSkeletonMapper::setMulWithScaling(
            (hkaSkeletonMapperData::MappingType)v143,
            v347,
            &v98[v97].m_startAFromBTransform,
            &v320[v134]);
          normalize3TwoAtOnce(&A, &B);
          v346 = 1065353048;
          v145 = _mm_mul_ps(B.m_quad, A.m_quad);
          v146 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v145, v145, 85), _mm_shuffle_ps(v145, v145, 0)),
                   _mm_shuffle_ps(v145, v145, 170));
          v147 = _mm_shuffle_ps((__m128)0x3F7FFF58u, (__m128)0x3F7FFF58u, 0).m128_f32[0];
          if ( v146.m128_f32[0] > v147 )
          {
            v148 = qi.m_vec.m_quad;
            goto LABEL_91;
          }
          if ( v146.m128_f32[0] >= (float)(0.0 - v147) )
          {
            v345 = -1082147209;
            v149 = _mm_add_ps(_mm_mul_ps((__m128)xmmword_141A711B0, v146), (__m128)xmmword_141A711B0);
            v150 = _mm_rsqrt_ps(v149);
            v151 = _mm_andnot_ps(
                     _mm_cmple_ps(v149, (__m128)0i64),
                     _mm_mul_ps(
                       _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v149, v150), v150)),
                       _mm_mul_ps(*(__m128 *)_xmm, v150)));
            v152 = _mm_mul_ps(v151, (__m128)xmmword_141A711B0);
            v153 = _mm_sub_ps(
                     _mm_mul_ps(_mm_shuffle_ps(A.m_quad, A.m_quad, 201), B.m_quad),
                     _mm_mul_ps(_mm_shuffle_ps(B.m_quad, B.m_quad, 201), A.m_quad));
            v154 = _mm_shuffle_ps(v153, v153, 201);
            if ( v146.m128_f32[0] < _mm_shuffle_ps((__m128)0xBF7FBE77, (__m128)0xBF7FBE77, 0).m128_f32[0] )
            {
              v155 = _mm_mul_ps(v154, v154);
              v156 = _mm_sub_ps(v149, v146);
              v157 = _mm_rsqrt_ps(v156);
              v158 = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v155, v155, 85), _mm_shuffle_ps(v155, v155, 0)),
                       _mm_shuffle_ps(v155, v155, 170));
              v159 = _mm_rsqrt_ps(v158);
              v152 = _mm_mul_ps(
                       _mm_mul_ps(
                         _mm_andnot_ps(
                           _mm_cmple_ps(v156, (__m128)0i64),
                           _mm_mul_ps(
                             _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v157, v156), v157)),
                             _mm_mul_ps(*(__m128 *)_xmm, v157))),
                         v156),
                       _mm_andnot_ps(
                         _mm_cmple_ps(v158, (__m128)0i64),
                         _mm_mul_ps(
                           _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v159, v158), v159)),
                           _mm_mul_ps(*(__m128 *)_xmm, v159))));
            }
            v160 = _mm_mul_ps(v154, v152);
            v148 = _mm_shuffle_ps(v160, _mm_unpackhi_ps(v160, _mm_mul_ps(v149, v151)), 196);
LABEL_91:
            v344.m_vec.m_quad = v148;
          }
          else
          {
            hkQuaternionf::setFlippedRotation(&v344, &B);
            v148 = v344.m_vec.m_quad;
          }
          v161 = v98[v97].m_endAFromBTransform.m_translation.m_quad;
          v162 = (int)v341;
          v163.m_vec.m_quad = (__m128)v347->m_rotation;
          v164 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v148, v148, 201), v161),
                   _mm_mul_ps(_mm_shuffle_ps(v161, v161, 201), v148));
          v165 = _mm_shuffle_ps(v163.m_vec.m_quad, v163.m_vec.m_quad, 255);
          v166 = _mm_sub_ps(_mm_shuffle_ps(v164, v164, 201), _mm_mul_ps(_mm_shuffle_ps(v148, v148, 255), v161));
          v167 = _mm_mul_ps(_mm_shuffle_ps(v161, v161, 255), v148);
          v168 = _mm_mul_ps(v148, v161);
          v169 = _mm_add_ps(v166, v167);
          v170 = _mm_add_ps(_mm_shuffle_ps(v168, v168, 78), v168);
          v171 = _mm_shuffle_ps(v169, _mm_unpackhi_ps(v169, _mm_add_ps(_mm_shuffle_ps(v170, v170, 177), v170)), 196);
          v172 = _mm_shuffle_ps(v171, v171, 255);
          v173 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v171, v171, 201), v163.m_vec.m_quad),
                   _mm_mul_ps(_mm_shuffle_ps(v163.m_vec.m_quad, v163.m_vec.m_quad, 201), v171));
          v174 = _mm_mul_ps(v171, v165);
          v175 = _mm_mul_ps(v171, v163.m_vec.m_quad);
          v176 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v173, v173, 201), v174), _mm_mul_ps(v163.m_vec.m_quad, v172));
          v347->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                            v176,
                                            _mm_unpackhi_ps(
                                              v176,
                                              _mm_sub_ps(
                                                _mm_mul_ps(v172, v165),
                                                _mm_add_ps(
                                                  _mm_add_ps(
                                                    _mm_shuffle_ps(v175, v175, 85),
                                                    _mm_shuffle_ps(v175, v175, 0)),
                                                  _mm_shuffle_ps(v175, v175, 170)))),
                                            196);
          v177 = v98[v97].m_endAFromBTransform.m_rotation.m_vec.m_quad;
          v178 = v320[v162].m_rotation.m_vec.m_quad;
          v179 = _mm_shuffle_ps(v177, v177, 255);
          v180 = _mm_shuffle_ps(v178, v178, 255);
          v181 = _mm_sub_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v178, v178, 201), v177),
                   _mm_mul_ps(_mm_shuffle_ps(v177, v177, 201), v178));
          v79 = v336;
          v182 = _mm_mul_ps(v177, v178);
          v94 = v334 == 0;
          v183 = _mm_add_ps(
                   _mm_add_ps(_mm_shuffle_ps(v181, v181, 201), _mm_mul_ps(v178, v179)),
                   _mm_mul_ps(v98[v97].m_endAFromBTransform.m_rotation.m_vec.m_quad, v180));
          additivePoseOut[v322].m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                            v183,
                                                            _mm_unpackhi_ps(
                                                              v183,
                                                              _mm_sub_ps(
                                                                _mm_mul_ps(v180, v179),
                                                                _mm_add_ps(
                                                                  _mm_add_ps(
                                                                    _mm_shuffle_ps(v182, v182, 85),
                                                                    _mm_shuffle_ps(v182, v182, 0)),
                                                                  _mm_shuffle_ps(v182, v182, 170)))),
                                                            196);
          v58 = v332;
          if ( v94 )
          {
            v184 = v98[v97].m_endBoneB;
            v185 = 0i64;
            v186 = _mm_shuffle_ps((__m128)LODWORD(v333[v162]), (__m128)LODWORD(v333[v162]), 0);
            v185.m128_f32[0] = (float)((int)retaddr - 1);
            v187 = _mm_shuffle_ps(v185, v185, 0);
            v188 = _mm_rcp_ps(v187);
            v76 = v330;
            for ( i = _mm_mul_ps(
                        _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v188, v187)), v188),
                        _mm_sub_ps(_mm_shuffle_ps((__m128)LODWORD(v333[v134]), (__m128)LODWORD(v333[v134]), 0), v186));
                  v184 >= v98[v97].m_startBoneB;
                  v184 = mapping->m_skeletonB.m_pntr->m_parentIndices.m_data[v190] )
            {
              weightsA[getBoneIndexFromPartition(additive, v184, *(__int16 *)(v79 + 8), *(__int16 *)&v58[2 * v76])] = v186.m128_f32[0];
              v186 = _mm_add_ps(v186, i);
            }
          }
          else
          {
            v76 = v330;
          }
          v71 = boneToTrackIndicesa;
          goto LABEL_98;
        }
LABEL_99:
        v61 = boneToTrackIndicesB;
        v70 = v317;
        v71 += v315->m_numBones;
        boneToTrackIndicesa = v71;
      }
      ++v70;
      v72 = v324 + 2;
      v317 = v70;
      v324 += 2i64;
    }
    while ( v70 < *((_DWORD *)v61 + 2) );
    v59 = v327;
  }
  v191 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v192 = (v59 + 15) & 0xFFFFFFF0;
  if ( v59 > v191->m_slabSize || &v58[v192] != v191->m_cur || v191->m_firstNonLifoEnd == v58 )
    hkLifoAllocator::slowBlockFree(v191, v58, v192);
  else
    v191->m_cur = v58;
LABEL_164:
  if ( (_BYTE)partitionIndicesA )
    hkaSkeletonMapper::additivePoseFromCombinedPoseAndReferencePose(
      additivePoseOut,
      mapping->m_skeletonB.m_pntr->m_referencePose.m_data,
      boneToTrackIndicesA,
      0,
      v319,
      additivePoseOut);
  if ( v323 > 0 )
  {
    v288 = (4 * v323 + 127) & 0xFFFFFF80;
    v289 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v290 = (v288 + 15) & 0xFFFFFFF0;
    if ( v288 > v289->m_slabSize || (char *)weightsA + v290 != v289->m_cur || v289->m_firstNonLifoEnd == weightsA )
      hkLifoAllocator::slowBlockFree(v289, weightsA, v290);
    else
      v289->m_cur = weightsA;
  }
  v291 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v292 = (_QWORD *)v291[1];
  if ( (unsigned __int64)v292 < v291[3] )
  {
    *v292 = "lt";
    v293 = __rdtsc();
    v294 = v292 + 2;
    *((_DWORD *)v294 - 2) = v293;
    v291[1] = v294;
  }
  v295 = (48 * numBones + 127) & 0xFFFFFF80;
  v296 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v297 = (v295 + 15) & 0xFFFFFFF0;
  if ( v295 > v296->m_slabSize
    || (char *)combinedPoseOut + v297 != v296->m_cur
    || v296->m_firstNonLifoEnd == combinedPoseOut )
  {
    hkLifoAllocator::slowBlockFree(v296, combinedPoseOut, v297);
  }
  else
  {
    v296->m_cur = combinedPoseOut;
  }
  v298 = *(char **)&array.m_size;
  if ( *(hkaSkeleton::Partition **)&array.m_size == array.m_data )
  {
    v299 = array.m_size - 1;
    if ( array.m_size - 1 >= 0 )
    {
      v300 = &array.m_data[v299];
      do
      {
        hkStringPtr::~hkStringPtr(&v300->m_name);
        --v300;
        --v299;
      }
      while ( v299 >= 0 );
      v298 = *(char **)&array.m_size;
    }
    array.m_size = 0;
  }
  v301 = (16 * v329 + 127) & 0xFFFFFF80;
  v302 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v303 = (v301 + 15) & 0xFFFFFFF0;
  if ( v301 > v302->m_slabSize || &v298[v303] != v302->m_cur || v302->m_firstNonLifoEnd == v298 )
    hkLifoAllocator::slowBlockFree(v302, v298, v303);
  else
    v302->m_cur = v298;
  v304 = array.m_size - 1;
  if ( array.m_size - 1 >= 0 )
  {
    v305 = &array.m_data[v304];
    do
    {
      hkStringPtr::~hkStringPtr(&v305->m_name);
      --v305;
      --v304;
    }
    while ( v304 >= 0 );
  }
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      16 * array.m_capacityAndFlags);
  v306 = (char *)v338;
  array.m_data = 0i64;
  array.m_capacityAndFlags = 0x80000000;
  if ( v338 == partitionsOut.m_data )
  {
    v307 = partitionsOut.m_size - 1;
    if ( partitionsOut.m_size - 1 >= 0 )
    {
      v308 = &partitionsOut.m_data[v307];
      do
      {
        hkStringPtr::~hkStringPtr(&v308->m_name);
        --v308;
        --v307;
      }
      while ( v307 >= 0 );
      v306 = (char *)v338;
    }
    partitionsOut.m_size = 0;
  }
  v309 = (16 * v339 + 127) & 0xFFFFFF80;
  v310 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v311 = (v309 + 15) & 0xFFFFFFF0;
  if ( v309 > v310->m_slabSize || &v306[v311] != v310->m_cur || v310->m_firstNonLifoEnd == v306 )
    hkLifoAllocator::slowBlockFree(v310, v306, v311);
  else
    v310->m_cur = v306;
  v312 = partitionsOut.m_size - 1;
  if ( partitionsOut.m_size - 1 >= 0 )
  {
    v313 = &partitionsOut.m_data[v312];
    do
    {
      hkStringPtr::~hkStringPtr(&v313->m_name);
      --v313;
      --v312;
    }
    while ( v312 >= 0 );
  }
  partitionsOut.m_size = 0;
  if ( partitionsOut.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      partitionsOut.m_data,
      16 * partitionsOut.m_capacityAndFlags);
}

// File Line: 774
// RVA: 0xB21980
void __fastcall hkaSkeletonMapper::mapPoseLocalSpace(
        hkaSkeletonMapper *this,
        hkQsTransformf *poseALocalSpaceOriginal,
        hkQsTransformf *poseBLocalSpaceInOut,
        const __int16 *boneToTrackIndicesA,
        const __int16 *boneToTrackIndicesB,
        bool additive,
        const float *weightsA,
        float *weightsBOut)
{
  int m_size; // eax
  char *v9; // rdi
  signed int v10; // ebx
  hkLifoAllocator *Value; // rax
  int v12; // r8d
  hkArray<short,hkContainerHeapAllocator> v13; // [rsp+50h] [rbp-28h] BYREF
  void *p; // [rsp+60h] [rbp-18h]
  int v15; // [rsp+68h] [rbp-10h]

  v13.m_size = 0;
  v15 = 0;
  v13.m_data = 0i64;
  v13.m_capacityAndFlags = 0x80000000;
  p = 0i64;
  hkaSkeletonMapper::mapPoseLocalSpaceInternal(
    &this->m_mapping,
    poseALocalSpaceOriginal,
    poseBLocalSpaceInOut,
    boneToTrackIndicesA,
    boneToTrackIndicesB,
    &v13,
    additive,
    1,
    weightsA,
    weightsBOut);
  m_size = v13.m_size;
  v9 = (char *)p;
  if ( p == v13.m_data )
    m_size = 0;
  v13.m_size = m_size;
  v10 = (2 * v15 + 127) & 0xFFFFFF80;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (v10 + 15) & 0xFFFFFFF0;
  if ( v10 > Value->m_slabSize || &v9[v12] != Value->m_cur || Value->m_firstNonLifoEnd == v9 )
    hkLifoAllocator::slowBlockFree(Value, v9, v12);
  else
    Value->m_cur = v9;
  v13.m_size = 0;
  if ( v13.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v13.m_data,
      2 * (v13.m_capacityAndFlags & 0x3FFFFFFF));
}

// File Line: 786
// RVA: 0xB21AA0
void __fastcall hkaSkeletonMapper::mapPoseLocalSpace(
        hkaSkeletonMapper *this,
        hkQsTransformf *poseALocalSpaceOriginal,
        hkQsTransformf *poseBLocalSpaceInOut,
        hkArray<short,hkContainerHeapAllocator> *partitionIndicesA,
        bool additive,
        bool mapToFullPose,
        const float *weightsA,
        float *weightsBOut)
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
void __fastcall hkaSkeletonMapper::mapPoseLocalSpace(
        hkaSkeletonMapper *this,
        hkQsTransformf *poseALocalSpaceOriginal,
        hkQsTransformf *poseBLocalSpaceInOut,
        const __int16 *boneToTrackIndicesA,
        const __int16 *boneToTrackIndicesB,
        hkArray<short,hkContainerHeapAllocator> *partitionIndicesA,
        bool additive,
        bool mapToFullPose,
        const float *weightsA,
        float *weightsBOut)
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
void __fastcall hkaSkeletonMapper::mapPose(
        hkaSkeletonMapper *this,
        hkaPose *poseAIn,
        hkaPose *poseBInOut,
        hkaSkeletonMapper::ConstraintSource source)
{
  int m_storage; // eax
  hkQsTransformf *v8; // rdi
  hkQsTransformf *v9; // rbx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v10; // rax
  hkQsTransformf *m_data; // rbx
  hkArray<hkQsTransformf,hkContainerHeapAllocator> *v12; // rax

  m_storage = this->m_mapping.m_mappingType.m_storage;
  if ( m_storage )
  {
    if ( m_storage == 1 )
    {
      m_data = hkaPose::getSyncedPoseLocalSpace(poseAIn)->m_data;
      v12 = hkaPose::accessSyncedPoseLocalSpace(poseBInOut);
      hkaSkeletonMapper::mapPoseLocalSpace(this, m_data, v12->m_data, 0);
    }
  }
  else
  {
    v8 = hkaPose::getSyncedPoseModelSpace(poseAIn)->m_data;
    v9 = hkaPose::getSyncedPoseLocalSpace(poseBInOut)->m_data;
    v10 = hkaPose::accessSyncedPoseModelSpace(poseBInOut);
    hkaSkeletonMapper::mapPose(this, v8, v9, v10->m_data, source);
  }
}

// File Line: 837
// RVA: 0xB21BE0
void __fastcall hkaSkeletonMapper::mapExtractedMotion(
        hkaSkeletonMapper *this,
        hkQsTransformf *deltaMotionIn,
        hkQsTransformf *deltaMotionOut)
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
  int v3; // r15d
  __int64 v4; // rbp
  hkaSkeletonMapperData::SimpleMapping *m_data; // rcx
  hkaBone *v6; // r14
  hkaBone *v7; // rsi
  __m128 v8; // xmm1
  hkOstream *v9; // rax
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkOstream *v14; // rax
  hkaSkeleton *m_pntr; // rax
  __int64 m_size; // rcx
  hkBool *p_m_lockTranslation; // rax
  hkErrStream v18; // [rsp+20h] [rbp-248h] BYREF
  hkSimdFloat32 f; // [rsp+40h] [rbp-228h] BYREF
  char buf[512]; // [rsp+50h] [rbp-218h] BYREF

  v1 = 0i64;
  if ( !m_mapping->m_mappingType.m_storage )
  {
    v3 = 0;
    if ( m_mapping->m_simpleMappings.m_size > 0 )
    {
      v4 = 0i64;
      do
      {
        m_data = m_mapping->m_simpleMappings.m_data;
        v6 = &m_mapping->m_skeletonA.m_pntr->m_bones.m_data[m_data[v4].m_boneA];
        v7 = &m_mapping->m_skeletonB.m_pntr->m_bones.m_data[m_data[v4].m_boneB];
        if ( v7->m_lockTranslation.m_bool )
        {
          v8 = _mm_mul_ps(
                 m_data[v4].m_aFromBTransform.m_translation.m_quad,
                 m_data[v4].m_aFromBTransform.m_translation.m_quad);
          f.m_real = _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                       _mm_shuffle_ps(v8, v8, 170));
          if ( f.m_real.m128_f32[0] > _mm_shuffle_ps((__m128)0x38D1B717u, (__m128)0x38D1B717u, 0).m128_f32[0] )
          {
            hkErrStream::hkErrStream(&v18, buf, 512);
            v9 = hkOstream::operator<<(&v18, "Bones A:");
            v10 = hkOstream::operator<<(v9, &v6->m_name);
            v11 = hkOstream::operator<<(v10, " and B:");
            v12 = hkOstream::operator<<(v11, &v7->m_name);
            v13 = hkOstream::operator<<(v12, " are not fully aligned (error :");
            v14 = hkOstream::operator<<(v13, &f);
            hkOstream::operator<<(v14, ").");
            hkError::messageWarning(-1413812289, buf, "Mapper\\hkaSkeletonMapper.cpp", 862);
            hkOstream::~hkOstream(&v18);
          }
        }
        ++v3;
        ++v4;
      }
      while ( v3 < m_mapping->m_simpleMappings.m_size );
    }
  }
  if ( !m_mapping->m_mappingType.m_storage )
  {
    m_pntr = m_mapping->m_skeletonB.m_pntr;
    m_size = m_pntr->m_bones.m_size;
    if ( m_size <= 0 )
    {
LABEL_13:
      hkErrStream::hkErrStream(&v18, buf, 512);
      hkOstream::operator<<(
        &v18,
        "None of the bones in skeleton have translations locked - did you forget to lock translations ?.");
      hkError::messageWarning(-1413843035, buf, "Mapper\\hkaSkeletonMapper.cpp", 885);
      hkOstream::~hkOstream(&v18);
    }
    else
    {
      p_m_lockTranslation = &m_pntr->m_bones.m_data->m_lockTranslation;
      while ( !p_m_lockTranslation->m_bool )
      {
        ++v1;
        p_m_lockTranslation += 16;
        if ( v1 >= m_size )
          goto LABEL_13;
      }
    }
  }
}

// File Line: 891
// RVA: 0xB226F0
void __fastcall hkaSkeletonMapper::checkMappingLocalSpace(hkaSkeletonMapperData *m_mapping)
{
  int v1; // r12d
  __int64 m_size; // rdi
  hkLifoAllocator *Value; // rax
  _DWORD *m_cur; // r15
  int v6; // edx
  char *v7; // rcx
  __int64 v8; // rcx
  int v9; // r13d
  _DWORD *v10; // rdi
  int v11; // esi
  __int64 v12; // r14
  hkaSkeletonMapperData::SimpleMapping *v13; // rdi
  __int16 m_boneB; // ax
  __int64 v15; // r13
  hkaSkeletonMapperData::ChainMapping *v16; // r14
  __int16 m_endBoneA; // ax
  __int16 m_endBoneB; // ax
  __int16 m_startBoneB; // ax
  int i; // ecx
  __int64 v21; // rsi
  hkaBone *v22; // rdi
  hkOstream *v23; // rax
  hkOstream *v24; // rax
  signed int v25; // edi
  hkLifoAllocator *v26; // rax
  int v27; // r8d
  hkErrStream v28; // [rsp+20h] [rbp-C8h] BYREF
  char buf[512]; // [rsp+40h] [rbp-A8h] BYREF
  int v30; // [rsp+268h] [rbp+180h]
  int vars0; // [rsp+270h] [rbp+188h]

  v1 = 0;
  m_size = m_mapping->m_skeletonB.m_pntr->m_bones.m_size;
  vars0 = m_size;
  if ( (_DWORD)m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = Value->m_cur;
    v6 = (4 * m_size + 127) & 0xFFFFFF80;
    v7 = (char *)m_cur + v6;
    if ( v6 > Value->m_slabSize || v7 > Value->m_end )
      m_cur = hkLifoAllocator::allocateFromNewSlab(Value, v6);
    else
      Value->m_cur = v7;
  }
  else
  {
    m_cur = 0i64;
  }
  v8 = m_size;
  v9 = m_size | 0x80000000;
  v30 = m_size | 0x80000000;
  if ( (int)m_size > 0 )
  {
    v10 = m_cur;
    while ( v8 )
    {
      *v10++ = 0;
      --v8;
    }
  }
  v11 = 0;
  if ( m_mapping->m_simpleMappings.m_size > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = &m_mapping->m_simpleMappings.m_data[v12];
      if ( !hkaSkeletonMapper::checkTransform(
              (hkaSkeletonMapperData::MappingType)m_mapping->m_mappingType.m_storage,
              &v13->m_aFromBTransform) )
      {
        hkErrStream::hkErrStream(&v28, buf, 512);
        hkOstream::operator<<(&v28, "Improper mapping transform found");
        hkError::messageWarning(-1413825855, buf, "Mapper\\hkaSkeletonMapper.cpp", 915);
        hkOstream::~hkOstream(&v28);
      }
      if ( v13->m_boneA < 0 || v13->m_boneA >= m_mapping->m_skeletonA.m_pntr->m_bones.m_size )
      {
        hkErrStream::hkErrStream(&v28, buf, 512);
        hkOstream::operator<<(&v28, "Invalid mapped bone found");
        hkError::messageWarning(-1413857535, buf, "Mapper\\hkaSkeletonMapper.cpp", 920);
        hkOstream::~hkOstream(&v28);
      }
      m_boneB = v13->m_boneB;
      if ( m_boneB < 0 || m_boneB >= m_mapping->m_skeletonB.m_pntr->m_bones.m_size )
      {
        hkErrStream::hkErrStream(&v28, buf, 512);
        hkOstream::operator<<(&v28, "Invalid mapped bone found");
        hkError::messageWarning(-1413813582, buf, "Mapper\\hkaSkeletonMapper.cpp", 925);
        hkOstream::~hkOstream(&v28);
      }
      if ( (int)++m_cur[v13->m_boneB] > 1 )
      {
        hkErrStream::hkErrStream(&v28, buf, 512);
        hkOstream::operator<<(&v28, "Improperly mapped bone found");
        hkError::messageWarning(-1413840481, buf, "Mapper\\hkaSkeletonMapper.cpp", 933);
        hkOstream::~hkOstream(&v28);
      }
      ++v11;
      ++v12;
    }
    while ( v11 < m_mapping->m_simpleMappings.m_size );
  }
  if ( m_mapping->m_chainMappings.m_size > 0 )
  {
    v15 = 0i64;
    do
    {
      v16 = &m_mapping->m_chainMappings.m_data[v15];
      if ( !hkaSkeletonMapper::checkTransform(
              (hkaSkeletonMapperData::MappingType)m_mapping->m_mappingType.m_storage,
              &v16->m_startAFromBTransform) )
      {
        hkErrStream::hkErrStream(&v28, buf, 512);
        hkOstream::operator<<(&v28, "Improper mapping transform found");
        hkError::messageWarning(-1413825855, buf, "Mapper\\hkaSkeletonMapper.cpp", 946);
        hkOstream::~hkOstream(&v28);
      }
      if ( !hkaSkeletonMapper::checkTransform(
              (hkaSkeletonMapperData::MappingType)m_mapping->m_mappingType.m_storage,
              &v16->m_endAFromBTransform) )
      {
        hkErrStream::hkErrStream(&v28, buf, 512);
        hkOstream::operator<<(&v28, "Improper mapping transform found");
        hkError::messageWarning(-1413825855, buf, "Mapper\\hkaSkeletonMapper.cpp", 951);
        hkOstream::~hkOstream(&v28);
      }
      if ( v16->m_endBoneA <= v16->m_startBoneA )
      {
        hkErrStream::hkErrStream(&v28, buf, 512);
        hkOstream::operator<<(&v28, "Invalid chain found");
        hkError::messageWarning(-1413840481, buf, "Mapper\\hkaSkeletonMapper.cpp", 956);
        hkOstream::~hkOstream(&v28);
      }
      if ( v16->m_endBoneB <= v16->m_startBoneB )
      {
        hkErrStream::hkErrStream(&v28, buf, 512);
        hkOstream::operator<<(&v28, "Invalid chain found");
        hkError::messageWarning(-1413840481, buf, "Mapper\\hkaSkeletonMapper.cpp", 961);
        hkOstream::~hkOstream(&v28);
      }
      m_endBoneA = v16->m_endBoneA;
      if ( m_endBoneA < 0 || m_endBoneA >= m_mapping->m_skeletonA.m_pntr->m_bones.m_size )
      {
        hkErrStream::hkErrStream(&v28, buf, 512);
        hkOstream::operator<<(&v28, "Invalid bone found");
        hkError::messageWarning(392326881, buf, "Mapper\\hkaSkeletonMapper.cpp", 966);
        hkOstream::~hkOstream(&v28);
      }
      if ( v16->m_startBoneA < 0 || v16->m_startBoneA >= m_mapping->m_skeletonA.m_pntr->m_bones.m_size )
      {
        hkErrStream::hkErrStream(&v28, buf, 512);
        hkOstream::operator<<(&v28, "Invalid bone found");
        hkError::messageWarning(101138396, buf, "Mapper\\hkaSkeletonMapper.cpp", 971);
        hkOstream::~hkOstream(&v28);
      }
      m_endBoneB = v16->m_endBoneB;
      if ( m_endBoneB < 0 || m_endBoneB >= m_mapping->m_skeletonB.m_pntr->m_bones.m_size )
      {
        hkErrStream::hkErrStream(&v28, buf, 512);
        hkOstream::operator<<(&v28, "Invalid bone found");
        hkError::messageWarning(430017533, buf, "Mapper\\hkaSkeletonMapper.cpp", 976);
        hkOstream::~hkOstream(&v28);
      }
      m_startBoneB = v16->m_startBoneB;
      if ( m_startBoneB < 0 || m_startBoneB >= m_mapping->m_skeletonB.m_pntr->m_bones.m_size )
      {
        hkErrStream::hkErrStream(&v28, buf, 512);
        hkOstream::operator<<(&v28, "Invalid bone found");
        hkError::messageWarning(263624113, buf, "Mapper\\hkaSkeletonMapper.cpp", 981);
        hkOstream::~hkOstream(&v28);
      }
      for ( i = v16->m_endBoneB; i >= v16->m_startBoneB; i = m_mapping->m_skeletonB.m_pntr->m_parentIndices.m_data[v21] )
      {
        v21 = i;
        if ( (int)++m_cur[i] > 1 )
        {
          hkErrStream::hkErrStream(&v28, buf, 512);
          v22 = &m_mapping->m_skeletonB.m_pntr->m_bones.m_data[v21];
          v23 = hkOstream::operator<<(&v28, "Improperly mapped bone found. Bone \"");
          v24 = hkOstream::operator<<(v23, &v22->m_name);
          hkOstream::operator<<(v24, "\" has been mapped more than once.");
          hkError::messageWarning(-1413840481, buf, "Mapper\\hkaSkeletonMapper.cpp", 993);
          hkOstream::~hkOstream(&v28);
        }
      }
      ++v1;
      ++v15;
    }
    while ( v1 < m_mapping->m_chainMappings.m_size );
    v9 = v30;
  }
  v25 = (4 * vars0 + 127) & 0xFFFFFF80;
  v26 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v27 = (v25 + 15) & 0xFFFFFFF0;
  if ( v25 > v26->m_slabSize || (char *)m_cur + v27 != v26->m_cur || v26->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v26, m_cur, v27);
  else
    v26->m_cur = m_cur;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, m_cur, 4 * v9);
}

// File Line: 1014
// RVA: 0xB22DD0
bool __fastcall hkaSkeletonMapper::checkTransform(hkaSkeletonMapperData::MappingType type, hkQsTransformf *q)
{
  return hkQuaternionf::isOk(&q->m_rotation, 0.001)
      && (_mm_movemask_ps(_mm_cmpunord_ps(q->m_translation.m_quad, q->m_translation.m_quad)) & 7) == 0
      && (_mm_movemask_ps(_mm_cmpunord_ps(q->m_scale.m_quad, q->m_scale.m_quad)) & 7) == 0;
}

// File Line: 1040
// RVA: 0xB24830
void __fastcall hkaSkeletonMapper::setMulWithScaling(
        hkaSkeletonMapperData::MappingType type,
        hkQsTransformf *dst,
        hkQsTransformf *map,
        hkQsTransformf *src)
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
  v6 = _mm_shuffle_ps(v5.m_vec.m_quad, v5.m_vec.m_quad, 255);
  v7 = _mm_sub_ps(
         _mm_mul_ps(_mm_shuffle_ps(v5.m_vec.m_quad, v5.m_vec.m_quad, 201), v4.m_vec.m_quad),
         _mm_mul_ps(_mm_shuffle_ps(v4.m_vec.m_quad, v4.m_vec.m_quad, 201), v5.m_vec.m_quad));
  v8 = _mm_shuffle_ps(v4.m_vec.m_quad, v4.m_vec.m_quad, 255);
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
void __fastcall hkaSkeletonMapper::initializeBindingMaps(
        hkaSkeletonMapper *this,
        hkaAnimationBinding *binding,
        __int64 srcBoneToTrackIndicesOut,
        hkArray<short,hkContainerHeapAllocator> *dstBoneToTrackIndicesOut,
        hkArray<short,hkContainerHeapAllocator> *dstTrackToBoneIndicesOut)
{
  hkArray<short,hkContainerHeapAllocator> *v5; // rsi
  __int16 v6; // bx
  hkaSkeleton *m_pntr; // r8
  int m_size; // r15d
  int v11; // eax
  int v13; // eax
  int v14; // r9d
  int v15; // edx
  __int16 *v16; // rdi
  __int64 v17; // rcx
  __int16 i; // di
  _DWORD *v19; // r15
  int v20; // r14d
  int v21; // eax
  int v22; // eax
  int v23; // r9d
  int v24; // edx
  _WORD *v25; // rdi
  __int64 v26; // rcx
  __int16 j; // di
  hkaSkeletonMapperData::SimpleMapping *v28; // rdx
  __int16 m_boneB; // r14
  __int16 v30; // r12
  hkaSkeletonMapperData::ChainMapping *m_data; // rax
  __int64 v32; // rdi
  int v33; // edx
  __int16 *v34; // rcx
  int v35; // r14d
  __int64 v36; // rdi
  __int16 v37; // r15
  int v38; // r14d
  int v39; // eax
  int v40; // eax
  int v41; // r9d
  int v42; // edx
  _WORD *v43; // rdi
  __int64 v44; // rcx
  hkaSkeleton *skeleton; // [rsp+30h] [rbp-38h]
  hkArray<short,hkContainerHeapAllocator> v46; // [rsp+38h] [rbp-30h] BYREF
  hkArray<short,hkContainerHeapAllocator> bonesOut; // [rsp+48h] [rbp-20h] BYREF
  hkBool result; // [rsp+B0h] [rbp+48h] BYREF
  hkaSkeleton *v49; // [rsp+B8h] [rbp+50h]
  _QWORD *v50; // [rsp+C0h] [rbp+58h]
  void *array; // [rsp+C8h] [rbp+60h] BYREF

  array = dstBoneToTrackIndicesOut;
  v50 = (_QWORD *)srcBoneToTrackIndicesOut;
  v5 = dstTrackToBoneIndicesOut;
  v6 = 0;
  *(_DWORD *)(srcBoneToTrackIndicesOut + 8) = 0;
  v5->m_size = 0;
  dstBoneToTrackIndicesOut->m_size = 0;
  m_pntr = this->m_mapping.m_skeletonB.m_pntr;
  m_size = this->m_mapping.m_skeletonA.m_pntr->m_bones.m_size;
  skeleton = this->m_mapping.m_skeletonA.m_pntr;
  v11 = *(_DWORD *)(srcBoneToTrackIndicesOut + 12) & 0x3FFFFFFF;
  v49 = m_pntr;
  if ( v11 < m_size )
  {
    v13 = 2 * v11;
    v14 = m_size;
    if ( m_size < v13 )
      v14 = v13;
    hkArrayUtil::_reserve(
      (hkResult *)&dstTrackToBoneIndicesOut,
      &hkContainerHeapAllocator::s_alloc,
      (void *)srcBoneToTrackIndicesOut,
      v14,
      2);
    m_pntr = v49;
  }
  v15 = m_size - *(_DWORD *)(srcBoneToTrackIndicesOut + 8);
  v16 = (__int16 *)(*(_QWORD *)srcBoneToTrackIndicesOut + 2i64 * *(int *)(srcBoneToTrackIndicesOut + 8));
  v17 = v15;
  if ( v15 > 0 )
  {
    while ( v17 )
    {
      *v16++ = -1;
      --v17;
    }
  }
  *(_DWORD *)(srcBoneToTrackIndicesOut + 8) = m_size;
  for ( i = 0; i < binding->m_transformTrackToBoneIndices.m_size; ++i )
    *(_WORD *)(*(_QWORD *)srcBoneToTrackIndicesOut + 2i64 * binding->m_transformTrackToBoneIndices.m_data[i]) = i;
  v19 = array;
  v20 = m_pntr->m_bones.m_size;
  v21 = *((_DWORD *)array + 3) & 0x3FFFFFFF;
  if ( v21 < v20 )
  {
    v22 = 2 * v21;
    v23 = m_pntr->m_bones.m_size;
    if ( v20 < v22 )
      v23 = v22;
    hkArrayUtil::_reserve((hkResult *)&dstTrackToBoneIndicesOut, &hkContainerHeapAllocator::s_alloc, array, v23, 2);
  }
  v24 = v20 - v19[2];
  v25 = (_WORD *)(*(_QWORD *)v19 + 2i64 * (int)v19[2]);
  v26 = v24;
  if ( v24 > 0 )
  {
    while ( v26 )
    {
      *v25++ = -1;
      --v26;
    }
  }
  v19[2] = v20;
  for ( j = 0; j < this->m_mapping.m_simpleMappings.m_size; ++j )
  {
    v28 = &this->m_mapping.m_simpleMappings.m_data[(__int64)j];
    if ( *(__int16 *)(*(_QWORD *)srcBoneToTrackIndicesOut + 2i64 * v28->m_boneA) >= 0 )
    {
      m_boneB = v28->m_boneB;
      if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v5, 2);
      v5->m_data[v5->m_size++] = m_boneB;
    }
  }
  v30 = 0;
  if ( this->m_mapping.m_chainMappings.m_size > 0 )
  {
    do
    {
      m_data = this->m_mapping.m_chainMappings.m_data;
      bonesOut.m_data = 0i64;
      bonesOut.m_size = 0;
      bonesOut.m_capacityAndFlags = 0x80000000;
      v46.m_data = 0i64;
      v46.m_size = 0;
      v46.m_capacityAndFlags = 0x80000000;
      v32 = v30;
      if ( hkaSkeletonUtils::getBoneChain(
             (hkBool *)&dstTrackToBoneIndicesOut,
             skeleton,
             m_data[v32].m_startBoneA,
             m_data[v32].m_endBoneA,
             &bonesOut)->m_bool
        && hkaSkeletonUtils::getBoneChain(
             &result,
             v49,
             this->m_mapping.m_chainMappings.m_data[v32].m_startBoneB,
             this->m_mapping.m_chainMappings.m_data[v32].m_endBoneB,
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
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v5, 2);
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
          while ( *(__int16 *)(*v50 + 2i64 * *v34) >= 0 )
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
          &hkContainerHeapAllocator::s_alloc,
          v46.m_data,
          2 * (v46.m_capacityAndFlags & 0x3FFFFFFF));
      bonesOut.m_size = 0;
      v46.m_capacityAndFlags = 0x80000000;
      v46.m_data = 0i64;
      if ( bonesOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          bonesOut.m_data,
          2 * (bonesOut.m_capacityAndFlags & 0x3FFFFFFF));
      ++v30;
      bonesOut.m_capacityAndFlags = 0x80000000;
      bonesOut.m_data = 0i64;
    }
    while ( v30 < this->m_mapping.m_chainMappings.m_size );
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
    hkArrayUtil::_reserve((hkResult *)&array, &hkContainerHeapAllocator::s_alloc, v19, v41, 2);
  }
  v42 = v38 - v19[2];
  v43 = (_WORD *)(*(_QWORD *)v19 + 2i64 * (int)v19[2]);
  v44 = v42;
  if ( v42 > 0 )
  {
    while ( v44 )
    {
      *v43++ = -1;
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
void __fastcall hkaSkeletonMapper::combineSparsePoseWithFullPose(
        hkQsTransformf *sparsePose,
        hkQsTransformf *fullPose,
        const __int16 *sparsePoseBoneToTrackIndices,
        int startBoneIndex,
        int numBones,
        hkQsTransformf *sparseMulFull_sparseOut)
{
  hkQuaternionf *p_m_rotation; // rdx
  __int64 v9; // r8
  char *v10; // r9
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
  __int64 i; // rax
  __int16 v28; // cx
  __int64 v29; // rdx
  hkQuaternionf v30; // xmm7
  hkVector4f v31; // xmm8
  __m128 v32; // xmm1
  __m128 v33; // xmm6
  __m128 v34; // xmm5
  __m128 v35; // xmm4
  __m128 v36; // xmm2
  __m128 m_quad; // xmm1
  __m128 v38; // xmm2
  hkQuaternionf v39; // xmm2
  __m128 v40; // xmm3
  __m128 v41; // xmm4
  __m128 v42; // xmm7
  __m128 v43; // xmm4
  __m128 v44; // xmm4

  if ( sparsePoseBoneToTrackIndices )
  {
    for ( i = 0i64; i < numBones; ++fullPose )
    {
      v28 = sparsePoseBoneToTrackIndices[i];
      if ( v28 >= 0 )
      {
        v29 = v28;
        v30.m_vec.m_quad = (__m128)sparsePose[v28].m_rotation;
        v31.m_quad = (__m128)sparsePose[v28].m_scale;
        v32 = _mm_mul_ps(fullPose->m_translation.m_quad, v30.m_vec.m_quad);
        v33 = _mm_shuffle_ps(v30.m_vec.m_quad, v30.m_vec.m_quad, 255);
        v34 = _mm_shuffle_ps(v30.m_vec.m_quad, v30.m_vec.m_quad, 201);
        v35 = _mm_sub_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(fullPose->m_translation.m_quad, fullPose->m_translation.m_quad, 201),
                  v30.m_vec.m_quad),
                _mm_mul_ps(fullPose->m_translation.m_quad, v34));
        v36 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v32, v32, 85), _mm_shuffle_ps(v32, v32, 0)),
                _mm_shuffle_ps(v32, v32, 170));
        m_quad = v30.m_vec.m_quad;
        v38 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(v36, v30.m_vec.m_quad),
                  _mm_mul_ps(
                    _mm_sub_ps(_mm_mul_ps(v33, v33), (__m128)xmmword_141A711B0),
                    fullPose->m_translation.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v33));
        sparseMulFull_sparseOut[v29].m_translation.m_quad = _mm_add_ps(
                                                              _mm_add_ps(v38, v38),
                                                              sparsePose[v28].m_translation.m_quad);
        v39.m_vec.m_quad = (__m128)fullPose->m_rotation;
        v40 = _mm_shuffle_ps(v39.m_vec.m_quad, v39.m_vec.m_quad, 255);
        v41 = _mm_mul_ps(_mm_shuffle_ps(v39.m_vec.m_quad, v39.m_vec.m_quad, 201), v30.m_vec.m_quad);
        v42 = _mm_mul_ps(v30.m_vec.m_quad, v39.m_vec.m_quad);
        v43 = _mm_sub_ps(v41, _mm_mul_ps(v39.m_vec.m_quad, v34));
        v44 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v43, v43, 201), _mm_mul_ps(v39.m_vec.m_quad, v33)),
                _mm_mul_ps(m_quad, v40));
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
        sparseMulFull_sparseOut[v29].m_scale.m_quad = _mm_mul_ps(fullPose->m_scale.m_quad, v31.m_quad);
      }
      ++i;
    }
  }
  else if ( numBones > 0 )
  {
    p_m_rotation = &sparsePose->m_rotation;
    v9 = (unsigned int)numBones;
    v10 = (char *)fullPose + 48i64 * startBoneIndex - (_QWORD)sparsePose;
    v11 = (char *)sparseMulFull_sparseOut - (char *)sparsePose;
    do
    {
      v12 = p_m_rotation->m_vec.m_quad;
      v13 = *(__m128 *)((char *)&p_m_rotation[-1].m_vec.m_quad + (_QWORD)v10);
      p_m_rotation += 3;
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
      *(__m128 *)((char *)&p_m_rotation[-4].m_vec.m_quad + v11) = _mm_add_ps(
                                                                    _mm_add_ps(v17, v17),
                                                                    p_m_rotation[-4].m_vec.m_quad);
      v18 = p_m_rotation[-3].m_vec.m_quad;
      v19 = *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + (_QWORD)v10);
      v20 = _mm_shuffle_ps(v18, v18, 255);
      v21 = _mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v19);
      v22 = _mm_shuffle_ps(v19, v19, 255);
      v23 = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 201), v18);
      v24 = _mm_mul_ps(v18, v19);
      v25 = _mm_sub_ps(v23, v21);
      v26 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v25, v25, 201), _mm_mul_ps(v19, v20)),
              _mm_mul_ps(p_m_rotation[-3].m_vec.m_quad, v22));
      *(__m128 *)((char *)&p_m_rotation[-3].m_vec.m_quad + v11) = _mm_shuffle_ps(
                                                                    v26,
                                                                    _mm_unpackhi_ps(
                                                                      v26,
                                                                      _mm_sub_ps(
                                                                        _mm_mul_ps(v22, v20),
                                                                        _mm_add_ps(
                                                                          _mm_add_ps(
                                                                            _mm_shuffle_ps(v24, v24, 85),
                                                                            _mm_shuffle_ps(v24, v24, 0)),
                                                                          _mm_shuffle_ps(v24, v24, 170)))),
                                                                    196);
      *(__m128 *)((char *)&p_m_rotation[-2].m_vec.m_quad + v11) = _mm_mul_ps(
                                                                    *(__m128 *)((char *)&p_m_rotation[-2].m_vec.m_quad
                                                                              + (_QWORD)v10),
                                                                    p_m_rotation[-2].m_vec.m_quad);
      --v9;
    }
    while ( v9 );
  }
}

// File Line: 1237
// RVA: 0xB22000
// attributes: thunk
void __fastcall hkaSkeletonMapper::combinedPoseFromAdditivePoseAndReferencePose(
        hkQsTransformf *additivePose,
        hkQsTransformf *referencePose,
        const __int16 *boneToTrackIndices,
        int startBoneIndex,
        int numBones,
        hkQsTransformf *combinedPoseOut)
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
void __fastcall hkaSkeletonMapper::additivePoseFromCombinedPoseAndReferencePose(
        hkQsTransformf *combinedPose,
        hkQsTransformf *referencePose,
        const __int16 *boneToTrackIndices,
        int startBoneIndex,
        int numBones,
        hkQsTransformf *additivePoseOut)
{
  __int64 v6; // rbx
  hkLifoAllocator *Value; // rax
  hkQsTransformf *m_cur; // rsi
  int v10; // ebp
  char *v11; // rcx
  __int64 v12; // r12
  __m128i inserted; // xmm0
  __m128 v14; // xmm6
  __m128 v15; // xmm7
  hkVector4f *p_m_scale; // r14
  __int64 v17; // r15
  __m128 *v18; // rbx
  __m128 m_quad; // xmm2
  __m128 v20; // xmm3
  __m128i v21; // xmm0
  hkLifoAllocator *v22; // rax
  int v23; // r8d

  v6 = startBoneIndex;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkQsTransformf *)Value->m_cur;
  v10 = (48 * numBones + 127) & 0xFFFFFF80;
  v11 = (char *)m_cur + v10;
  if ( v10 > Value->m_slabSize || v11 > Value->m_end )
    m_cur = (hkQsTransformf *)hkLifoAllocator::allocateFromNewSlab(Value, v10);
  else
    Value->m_cur = v11;
  v12 = numBones;
  if ( numBones > 0 )
  {
    inserted = _mm_insert_epi16((__m128i)0i64, 0x8000u, 1);
    v14 = (__m128)_mm_shuffle_epi32(inserted, 0);
    v15 = (__m128)_mm_shuffle_epi32(inserted, 64);
    p_m_scale = &referencePose[v6].m_scale;
    v17 = (char *)&m_cur[-v6] - (char *)referencePose;
    do
    {
      v18 = (__m128 *)((char *)&p_m_scale->m_quad + v17);
      hkVector4f::setRotatedInverseDir(
        (hkVector4f *)((char *)p_m_scale + v17 - 32),
        (hkQuaternionf *)&p_m_scale[-1],
        p_m_scale - 2);
      p_m_scale += 3;
      v18[-2] = _mm_xor_ps(v14, v18[-2]);
      *(__m128 *)((char *)&p_m_scale[-4].m_quad + v17) = _mm_xor_ps(p_m_scale[-4].m_quad, v15);
      m_quad = p_m_scale[-3].m_quad;
      v20 = _mm_rcp_ps(m_quad);
      v21 = (__m128i)_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(m_quad, v20)), v20);
      *(__m128i *)((char *)p_m_scale + v17 - 48) = v21;
      *(__m128i *)((char *)&p_m_scale[-3] + v17) = _mm_srli_si128(_mm_slli_si128(v21, 4), 4);
      --v12;
    }
    while ( v12 );
  }
  hkaSkeletonMapper::combineSparsePoseWithFullPose(
    combinedPose,
    m_cur,
    boneToTrackIndices,
    0,
    numBones,
    additivePoseOut);
  v22 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v23 = (v10 + 15) & 0xFFFFFFF0;
  if ( v10 > v22->m_slabSize || (char *)m_cur + v23 != v22->m_cur || v22->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v22, m_cur, v23);
  else
    v22->m_cur = m_cur;
}

