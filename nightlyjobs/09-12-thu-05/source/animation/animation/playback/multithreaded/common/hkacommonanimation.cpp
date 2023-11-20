// File Line: 46
// RVA: 0xB45330
void __fastcall executeQuantizedSampleAndCombineJob(hkaQuantizedSampleAndCombineJob *job)
{
  hkaQuantizedSampleAndCombineJob *v1; // rbx
  _QWORD *v2; // rdi
  unsigned __int64 v3; // rcx
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rsi
  __int64 v6; // r10
  int v7; // edi
  int v8; // er9
  int v9; // er9
  int v10; // er9
  int v11; // er9
  int v12; // er10
  int v13; // eax
  int v14; // er9
  int v15; // er9
  hkQsTransformf *v16; // rax
  int v17; // ecx
  hkQsTransformf *v18; // r15
  hkQsTransformf *bonesOut; // r13
  hkQsTransformf *v20; // rax
  int v21; // ecx
  float *boneWeightsOut; // r12
  signed __int64 v23; // rdi
  const float *v24; // r14
  hkQsTransformf *v25; // rax
  int v26; // ecx
  float *v27; // rax
  int v28; // ecx
  float *v29; // rax
  int v30; // ecx
  unsigned int v31; // eax
  int *v32; // r8
  __int64 v33; // r10
  char *v34; // r9
  int v35; // edx
  int v36; // edi
  int v37; // eax
  unsigned int v38; // eax
  float *v39; // rcx
  signed __int64 v40; // rdi
  __int64 v41; // rdx
  int v42; // eax
  float *v43; // rdi
  __int64 i; // rcx
  float *v45; // rdi
  __int64 j; // rcx
  unsigned int v47; // eax
  int v48; // er15
  float v49; // xmm7_4
  _QWORD *v50; // rax
  _QWORD *v51; // rcx
  _QWORD *v52; // rdi
  unsigned __int64 v53; // rax
  signed __int64 v54; // rcx
  int v55; // ecx
  signed __int64 v56; // r11
  signed int v57; // edi
  float **v58; // r14
  __int64 v59; // rax
  int v60; // er9
  int v61; // er8
  __int64 v62; // r10
  __int64 v63; // rax
  int v64; // er9
  int v65; // er10
  __int64 v66; // rax
  int v67; // er9
  char *v68; // rdi
  __m128 v69; // xmm1
  __m128 v70; // xmm0
  unsigned int v71; // edx
  __m128 v72; // xmm3
  __m128 v73; // xmm0
  __m128 v74; // xmm3
  signed int v75; // ecx
  float v76; // xmm4_4
  __m128 v77; // xmm0
  __m128 v78; // xmm3
  __m128 v79; // xmm1
  int v80; // ecx
  int v81; // er8
  int v82; // edi
  __int64 v83; // r10
  int v84; // er8
  int v85; // er9
  _QWORD *v86; // rdi
  unsigned __int64 v87; // rcx
  unsigned __int64 v88; // rax
  __int64 v89; // r15
  _QWORD *v90; // rdi
  _QWORD *v91; // rcx
  unsigned __int64 v92; // rax
  signed __int64 v93; // rcx
  float v94; // xmm0_4
  int v95; // ecx
  __int64 v96; // r10
  int *v97; // r8
  signed __int64 v98; // r9
  int v99; // edx
  int v100; // edi
  int v101; // eax
  unsigned int v102; // eax
  float *v103; // rcx
  __int64 v104; // rdx
  char *v105; // rdi
  int v106; // eax
  __int64 v107; // rcx
  float *v108; // rdi
  int v109; // eax
  const float *v110; // r8
  const float *v111; // r15
  int v112; // eax
  int v113; // edi
  __m128 v114; // xmm6
  int referencePose; // ST48_4
  int v116; // eax
  int v117; // eax
  _QWORD *v118; // rax
  _QWORD *v119; // rcx
  _QWORD *v120; // rdi
  unsigned __int64 v121; // rax
  signed __int64 v122; // rcx
  hkQsTransformf *v123; // r15
  int v124; // er9
  _QWORD *v125; // rdi
  _QWORD *v126; // rcx
  unsigned __int64 v127; // rax
  signed __int64 v128; // rcx
  const float *v129; // rcx
  _QWORD *v130; // rax
  _QWORD *v131; // rcx
  _QWORD *v132; // rdi
  unsigned __int64 v133; // rax
  signed __int64 v134; // rcx
  unsigned int useSlerp[2]; // [rsp+80h] [rbp-80h]
  float *frameSteppingTolerance; // [rsp+88h] [rbp-78h]
  float *src; // [rsp+90h] [rbp-70h]
  float *weightsOut; // [rsp+98h] [rbp-68h]
  float *srcL; // [rsp+A0h] [rbp-60h]
  unsigned int n; // [rsp+A8h] [rbp-58h]
  signed __int64 v141; // [rsp+B0h] [rbp-50h]
  hkaQuantizedSampleAndCombineJob::QuantizedAnimationEntry *v142; // [rsp+B8h] [rbp-48h]
  hkQsTransformf *transformsInOut; // [rsp+C0h] [rbp-40h]
  int v144; // [rsp+C8h] [rbp-38h]
  __int16 *parentIndices; // [rsp+D0h] [rbp-30h]
  hkQsTransformf *transformsIn; // [rsp+D8h] [rbp-28h]
  hkQsTransformf *bonesScratch1; // [rsp+E0h] [rbp-20h]
  hkQsTransformf *floatsOut; // [rsp+E8h] [rbp-18h]
  hkQsTransformf *dst; // [rsp+F0h] [rbp-10h]
  unsigned int v150; // [rsp+F8h] [rbp-8h]
  __int16 *bonePairMap; // [rsp+100h] [rbp+0h]
  __int64 v152; // [rsp+108h] [rbp+8h]
  float *referenceFloats; // [rsp+110h] [rbp+10h]
  hkQuaternionf *invariants; // [rsp+118h] [rbp+18h]
  hkaSkeleton::Partition *partitions; // [rsp+120h] [rbp+20h]
  float *floatsScratch0; // [rsp+128h] [rbp+28h]
  float *floatsScratch1; // [rsp+130h] [rbp+30h]
  float v158[2]; // [rsp+138h] [rbp+38h]
  hkSimdFloat32 v159; // [rsp+150h] [rbp+50h]
  const char *headerData[3]; // [rsp+160h] [rbp+60h]
  __int64 v161; // [rsp+178h] [rbp+78h]
  __int64 v162; // [rsp+180h] [rbp+80h]
  float *v163; // [rsp+188h] [rbp+88h]
  float *p; // [rsp+190h] [rbp+90h]
  hkSimdFloat32 alphaIn; // [rsp+1A0h] [rbp+A0h]
  const __int16 *partitionIndices[3]; // [rsp+1B0h] [rbp+B0h]
  const float *v167[3]; // [rsp+1C8h] [rbp+C8h]
  const float *srcR[3]; // [rsp+1E0h] [rbp+E0h]
  char *frameData0; // [rsp+1F8h] [rbp+F8h]
  char *frameData1[8]; // [rsp+200h] [rbp+100h]
  int vars0; // [rsp+2C0h] [rbp+1C0h]
  int retaddr; // [rsp+2C8h] [rbp+1C8h]
  int v173; // [rsp+2D0h] [rbp+1D0h]
  int v174; // [rsp+2D8h] [rbp+1D8h]

  v1 = job;
  v2 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v3 = v2[1];
  if ( v3 < v2[3] )
  {
    *(_QWORD *)v3 = "LthkaQuantizedSampleAndCombineJob";
    *(_QWORD *)(v3 + 16) = "StAllocateAndDMASkeleton";
    v4 = __rdtsc();
    *(_DWORD *)(v3 + 8) = v4;
    v2[1] = v3 + 24;
  }
  v5 = 0i64;
  if ( v1->m_mirroredBonePairMap )
    v6 = v1->m_numBones;
  v7 = 0;
  if ( v1->m_parentIndices )
    v7 = v1->m_numBones;
  retaddr = 2;
  allocateAndCopy_hkQsTransformf_(&dst, v1->m_referenceBones, v1->m_numBones, 2, "Reference Bones");
  allocateAndCopy_float_(
    (const float **)&referenceFloats,
    v1->m_referenceFloats,
    v1->m_numFloats,
    v8,
    "Reference Floats");
  allocateAndCopy_short_((const __int16 **)&parentIndices, v1->m_parentIndices, v7, v9, "Parent Indices");
  allocateAndCopy_hkaQuantizedSampleAndCombineJob::QuantizedAnimationEntry_(
    &v142,
    v1->m_animations,
    v1->m_numAnimations,
    v10,
    "Entries");
  allocateAndCopy_short_((const __int16 **)&bonePairMap, v1->m_mirroredBonePairMap, v12, v11, "Mirrored Bone Pairs");
  allocateAndCopy_hkQuaternionf_(&invariants, v1->m_mirroredBoneInvariants, v13, v14, "Mirrored Bone Invariants");
  allocateAndCopy_hkaSkeleton::Partition_(
    &partitions,
    v1->m_partitions,
    v1->m_numPartitions,
    v15,
    "Skeleton Partitions");
  v16 = allocateFromStack_hkQsTransformf_(v1->m_numBones, "AccumulatedBones");
  v17 = v1->m_numFloats;
  v18 = v16;
  transformsInOut = v16;
  src = allocateFromStack_float_(v17, "AccumulatedFloats");
  frameSteppingTolerance = allocateFromStack_float_(v1->m_numBones, "AccumBoneWeights");
  weightsOut = allocateFromStack_float_(v1->m_numFloats, "AccumFloatWeights");
  bonesOut = allocateFromStack_hkQsTransformf_(v1->m_numBones, "SampledBones");
  v20 = (hkQsTransformf *)allocateFromStack_float_(v1->m_numFloats, "SampledFloats");
  v21 = v1->m_numBones;
  floatsOut = v20;
  boneWeightsOut = allocateFromStack_float_(v21, "SampledBoneWeights");
  v23 = 0i64;
  v24 = allocateFromStack_float_(v1->m_numFloats, "SampledFloatWeights");
  srcL = (float *)v24;
  do
  {
    v25 = allocateFromStack_hkQsTransformf_(v1->m_numBones, "ScratchBones");
    v26 = v1->m_numFloats;
    *(hkQsTransformf **)((char *)&transformsIn + v23 * 8) = v25;
    v27 = allocateFromStack_float_(v26, "ScratchFloats");
    v28 = v1->m_numBones;
    (&floatsScratch0)[v23] = v27;
    v29 = allocateFromStack_float_(v28, "ScratchBoneWeights");
    v30 = v1->m_numFloats;
    *(__int64 *)((char *)&v161 + v23 * 8) = (__int64)v29;
    ++v23;
    *(__int64 *)((char *)&v162 + v23 * 8) = (__int64)allocateFromStack_float_(v30, "ScratchFloatWeights");
  }
  while ( v23 < 2 );
  v31 = v1->m_numBones;
  n = (v31 + 3) & 0xFFFFFFFC;
  v144 = (v1->m_numFloats + 3) & 0xFFFFFFFC;
  if ( (signed int)(3 * v31) > 0 )
  {
    v32 = &v18->m_translation.m_quad.m128_i32[2];
    v33 = 3 * v31;
    v34 = (char *)((char *)dst - (char *)v18);
    do
    {
      v35 = *(int *)((char *)v32 + (_QWORD)v34);
      v36 = *(int *)((char *)v32 + (_QWORD)v34 + 4);
      v37 = *(int *)((char *)v32 + (_QWORD)v34 - 8);
      *(v32 - 1) = *(int *)((char *)v32 + (_QWORD)v34 - 4);
      *v32 = v35;
      v32[1] = v36;
      *(v32 - 2) = v37;
      v32 += 4;
      --v33;
    }
    while ( v33 );
  }
  v38 = v1->m_numFloats;
  v39 = referenceFloats;
  if ( (signed int)v38 > 0 )
  {
    v40 = (char *)src - (char *)referenceFloats;
    v41 = v38;
    do
    {
      v42 = *(_DWORD *)v39;
      ++v39;
      *(_DWORD *)((char *)v39 + v40 - 4) = v42;
      --v41;
    }
    while ( v41 );
  }
  if ( (signed int)(v1->m_numBones - 1) >= 0 )
  {
    v43 = frameSteppingTolerance;
    for ( i = v1->m_numBones; i; --i )
    {
      *v43 = 0.0;
      ++v43;
    }
  }
  if ( (signed int)(v1->m_numFloats - 1) >= 0 )
  {
    v45 = weightsOut;
    for ( j = v1->m_numFloats; j; --j )
    {
      *v45 = 0.0;
      ++v45;
    }
  }
  v47 = v1->m_numAnimations;
  vars0 = 1;
  v48 = 0;
  v173 = 0;
  v49 = 0.0;
  v174 = v47;
  v50 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v51 = (_QWORD *)v50[1];
  v52 = v50;
  if ( (unsigned __int64)v51 < v50[3] )
  {
    *v51 = "StSampleAndBlendPipeline";
    v53 = __rdtsc();
    v54 = (signed __int64)(v51 + 2);
    *(_DWORD *)(v54 - 8) = v53;
    v52[1] = v54;
  }
  v55 = v174;
  v56 = -2i64;
  v141 = -2i64;
  v152 = v174;
  if ( v174 > -2i64 )
  {
    v57 = -1;
    v58 = &v142->m_perBoneWeights;
    do
    {
      LODWORD(v142) = v57 + 1;
      if ( v57 + 1 >= 0 && v57 + 1 < v55 )
      {
        getFromMainMemory_unsigned_char_(&headerData[v48], (const char *)*(v58 - 3), *((_DWORD *)v58 - 4), v48 + 7);
        if ( *v58 )
          v61 = v1->m_numBones;
        else
          v61 = 0;
        if ( v58[1] )
          v62 = v1->m_numFloats;
        getFromMainMemory_float_(&srcR[v59], *v58, v61, v60);
        getFromMainMemory_float_(&v167[v63], v58[1], v65, v64);
        getFromMainMemory_short_(&partitionIndices[v66], (const __int16 *)v58[2], *((signed __int16 *)v58 + 12), v67);
        v55 = v174;
      }
      if ( v57 >= 0 && v57 < v55 )
      {
        v150 = *((_DWORD *)v58 - 17);
        v68 = (char *)headerData[retaddr];
        v69 = _mm_shuffle_ps((__m128)*((unsigned int *)v68 + 2), (__m128)*((unsigned int *)v68 + 2), 0);
        v70 = _mm_rcp_ps(v69);
        v71 = *((unsigned __int16 *)v68 + 3) - 2;
        v72 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v69, v70)), v70);
        v73 = 0i64;
        v73.m128_f32[0] = (float)(*((unsigned __int16 *)v68 + 3) - 1);
        v74 = _mm_mul_ps(v72, _mm_mul_ps(_mm_shuffle_ps(v73, v73, 0), _mm_shuffle_ps((__m128)v150, (__m128)v150, 0)));
        v75 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v74));
        if ( v75 <= v71 )
        {
          v77 = 0i64;
          v77.m128_f32[0] = (float)v75;
          v71 = v75;
          v78 = _mm_sub_ps(v74, _mm_shuffle_ps(v77, v77, 0));
          v79 = _mm_cmpltps(v78, query.m_quad);
          v76 = fmax(
                  0.0,
                  COERCE_FLOAT(v78.m128_i32[0] & v79.m128_i32[0] | *(unsigned __int128 *)&_mm_andnot_ps(
                                                                                            v79,
                                                                                            query.m_quad)));
        }
        else
        {
          v76 = *(float *)&FLOAT_1_0;
        }
        v80 = *(unsigned __int16 *)v68;
        v81 = *((unsigned __int16 *)v68 + 14);
        v158[retaddr] = v76;
        v82 = v80 + v81 * (v71 + 1);
        getFromMainMemory_unsigned_char_(
          (const char **)&(&frameData0)[2 * retaddr],
          (const char *)*(v58 - 10) + (signed int)(v80 + v71 * v81),
          v81,
          retaddr + 10);
        getFromMainMemory_unsigned_char_(
          (const char **)((char *)frameData1 + v83),
          (const char *)*(v58 - 10) + v82,
          v84,
          v85);
      }
      if ( v56 >= 0 && v56 < v152 )
      {
        v86 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v87 = v86[1];
        if ( v87 < v86[3] )
        {
          *(_QWORD *)v87 = "LtSampleAndBlend";
          *(_QWORD *)(v87 + 16) = "StSample";
          v88 = __rdtsc();
          *(_DWORD *)(v87 + 8) = v88;
          v86[1] = v87 + 24;
        }
        v89 = vars0;
        hkaQuantizedAnimation::sampleFullPose(
          headerData[vars0],
          (&frameData0)[2 * vars0],
          frameData1[2 * vars0],
          v1->m_numBones,
          v1->m_numFloats,
          bonesOut,
          floatsOut->m_translation.m_quad.m128_f32,
          boneWeightsOut,
          srcL,
          dst,
          referenceFloats,
          transformsIn,
          bonesScratch1,
          floatsScratch0,
          floatsScratch1,
          v158[vars0],
          v1->m_flags & 1,
          v1->m_frameSteppingTolerance);
        v90 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v91 = (_QWORD *)v90[1];
        if ( (unsigned __int64)v91 < v90[3] )
        {
          *v91 = "StBlend";
          v92 = __rdtsc();
          v93 = (signed __int64)(v91 + 2);
          *(_DWORD *)(v93 - 8) = v92;
          v90[1] = v93;
        }
        v94 = *((float *)v58 - 30);
        v49 = v49 + v94;
        if ( v49 == 0.0 )
          *(float *)useSlerp = 0.0;
        else
          *(float *)useSlerp = v94 / v49;
        if ( *((_BYTE *)v58 - 84) & 8 )
        {
          v95 = 3 * v1->m_numBones;
          if ( v95 > 0 )
          {
            v96 = (unsigned int)v95;
            v97 = &transformsIn->m_translation.m_quad.m128_i32[2];
            v98 = (char *)bonesOut - (char *)transformsIn;
            do
            {
              v99 = *(int *)((char *)v97 + v98);
              v100 = *(int *)((char *)v97 + v98 + 4);
              v101 = *(int *)((char *)v97 + v98 - 8);
              *(v97 - 1) = *(int *)((char *)v97 + v98 - 4);
              *v97 = v99;
              v97[1] = v100;
              *(v97 - 2) = v101;
              v97 += 4;
              --v96;
            }
            while ( v96 );
          }
          v102 = v1->m_numBones;
          v103 = boneWeightsOut;
          if ( (signed int)v102 > 0 )
          {
            v104 = v102;
            v105 = (char *)((char *)bonesScratch1 - (char *)boneWeightsOut);
            do
            {
              v106 = *(_DWORD *)v103;
              ++v103;
              *(_DWORD *)&v105[(_QWORD)v103 - 4] = v106;
              --v104;
            }
            while ( v104 );
          }
          hkaSampleAndCombineUtils::copyReferencePose(bonesOut, 0i64, dst, v1->m_numBones, 0i64, 0);
          if ( (signed int)(v1->m_numBones - 1) >= 0 )
          {
            v107 = v1->m_numBones;
            v108 = boneWeightsOut;
            while ( v107 )
            {
              *v108 = 0.0;
              ++v108;
              --v107;
            }
          }
          hkaPartitionedAnimationUtility::mapPartitionPoseToFullPoseWithWeights(
            partitions,
            partitionIndices[v89],
            *((signed __int16 *)v58 - 44),
            transformsIn,
            bonesScratch1->m_translation.m_quad.m128_f32,
            v1->m_numBones,
            bonesOut,
            boneWeightsOut);
        }
        v109 = *((_DWORD *)v58 - 21);
        if ( v109 & 4 )
        {
          if ( v109 & 1 || v109 & 2 )
            hkaMirroredSkeleton::mirrorBonesAdditive(bonesOut, parentIndices, invariants, bonePairMap, v1->m_numBones);
          else
            hkaMirroredSkeleton::mirrorBonesNormal(bonesOut, parentIndices, invariants, bonePairMap, v1->m_numBones);
        }
        if ( *(v58 - 14) )
          hkaBlender::mul(boneWeightsOut, boneWeightsOut, srcR[v89], n);
        if ( *(v58 - 13) )
        {
          v110 = v167[v89];
          v111 = srcL;
          hkaBlender::mul(srcL, srcL, v110, v144);
        }
        else
        {
          v111 = srcL;
        }
        v112 = *((_DWORD *)v58 - 21);
        if ( v112 & 1 )
          v113 = 1;
        else
          v113 = -((v112 & 2) != 0);
        v114 = (__m128)useSlerp[0];
        referencePose = v1->m_flags & 1;
        v116 = v1->m_numBones;
        alphaIn.m_real = _mm_shuffle_ps(v114, v114, 0);
        hkaBlender::blend(
          transformsInOut,
          frameSteppingTolerance,
          transformsInOut,
          frameSteppingTolerance,
          bonesOut,
          boneWeightsOut,
          &alphaIn,
          v116,
          (hkaBlender::BLEND_MODE)v113,
          (hkaBlender::ROTATION_MODE)referencePose);
        v117 = v1->m_numFloats;
        v159.m_real = _mm_shuffle_ps(v114, v114, 0);
        hkaBlender::blend(
          src,
          weightsOut,
          src,
          weightsOut,
          floatsOut->m_translation.m_quad.m128_f32,
          v111,
          &v159,
          v117,
          (hkaBlender::BLEND_MODE)v113);
        v118 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v56 = v141;
        v48 = v173;
        v119 = (_QWORD *)v118[1];
        v120 = v118;
        if ( (unsigned __int64)v119 < v118[3] )
        {
          *v119 = "lt";
          v121 = __rdtsc();
          v122 = (signed __int64)(v119 + 2);
          *(_DWORD *)(v122 - 8) = v121;
          v120[1] = v122;
        }
      }
      v57 = (signed int)v142;
      ++v56;
      v58 += 7;
      v141 = v56;
      vars0 = (vars0 + 1) % 3;
      retaddr = (retaddr + 1) % 3;
      v55 = v174;
      v48 = (v48 + 1) % 3;
      v173 = v48;
    }
    while ( v56 < v152 );
    v24 = srcL;
  }
  v123 = transformsInOut;
  if ( v1->m_flags & 2 )
    hkaBlender::normalize(transformsInOut, v1->m_numBones);
  if ( v1->m_parentIndices )
    hkaBlender::modelFromLocal(v123, v123, parentIndices, v1->m_numBones, &hkQsTransformf_identityStorage);
  putToMainMemory_hkQsTransformf_(v1->m_bonesOut, v123, v1->m_numBones, 3);
  putToMainMemory_float_(v1->m_floatsOut, src, v1->m_numFloats, v124);
  putToMainMemory_float_(v1->m_boneWeightsOut, frameSteppingTolerance, v1->m_numBones, 3);
  putToMainMemory_float_(v1->m_floatWeightsOut, weightsOut, v1->m_numFloats, 3);
  v125 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v126 = (_QWORD *)v125[1];
  if ( (unsigned __int64)v126 < v125[3] )
  {
    *v126 = "StDeallocate";
    v127 = __rdtsc();
    v128 = (signed __int64)(v126 + 2);
    *(_DWORD *)(v128 - 8) = v127;
    v125[1] = v128;
  }
  do
  {
    v129 = (&p)[v5 / 2];
    v5 -= 2i64;
    deallocateFromStack_float_(v129, v1->m_numFloats);
    deallocateFromStack_float_((&v163)[v5 / 2], v1->m_numBones);
    deallocateFromStack_float_(*(const float **)&v158[v5], v1->m_numFloats);
    deallocateFromStack_hkQsTransformf_(*(hkQsTransformf **)((char *)&floatsOut + v5 * 4), v1->m_numBones);
  }
  while ( v5 != 4611686018427387900i64 );
  deallocateFromStack_float_(v24, v1->m_numFloats);
  deallocateFromStack_float_(boneWeightsOut, v1->m_numBones);
  deallocateFromStack_float_(floatsOut->m_translation.m_quad.m128_f32, v1->m_numFloats);
  deallocateFromStack_hkQsTransformf_(bonesOut, v1->m_numBones);
  deallocateFromStack_float_(weightsOut, v1->m_numFloats);
  deallocateFromStack_float_(frameSteppingTolerance, v1->m_numBones);
  deallocateFromStack_float_(src, v1->m_numFloats);
  deallocateFromStack_hkQsTransformf_(v123, v1->m_numBones);
  v130 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v131 = (_QWORD *)v130[1];
  v132 = v130;
  if ( (unsigned __int64)v131 < v130[3] )
  {
    *v131 = "lt";
    v133 = __rdtsc();
    v134 = (signed __int64)(v131 + 2);
    *(_DWORD *)(v134 - 8) = v133;
    v132[1] = v134;
  }
}_rdtsc();
    v134 = (signed __int64)(v131 + 2);
    *(_DWORD *)(v134 - 8) = v133;
    v132[1] = v134;
  }
}

// File Line: 461
// RVA: 0xB46010
void __fastcall getFromMainMemory_unsigned_char_(const char **dst, const char *src, int num, int group)
{
  *dst = src;
  if ( src )
    __asm { prefetchnta byte ptr [rdx]; Prefetch to L1 cache }
}

// File Line: 488
// RVA: 0xB45EE0
void __fastcall waitForDmaCompletion(int group)
{
  ;
}

// File Line: 498
// RVA: 0xB460C0
void __fastcall putToMainMemory_float_(float *dst, const float *src, __int64 num, int group)
{
  if ( dst )
  {
    num = (signed int)num;
    if ( (signed int)num > 0i64 )
      memmove(dst, src, 4 * num);
  }
}

// File Line: 541
// RVA: 0xB45FB0
float *__fastcall allocateFromStack_float_(int num, const char *what)
{
  int v2; // ebx
  hkLifoAllocator *v3; // rax
  char *v4; // r8
  int v5; // edx
  char *v6; // rcx

  v2 = num;
  v3 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (char *)v3->m_cur;
  v5 = (4 * ((v2 + 3) & 0xFFFFFFFC) + 127) & 0xFFFFFF80;
  v6 = &v4[v5];
  if ( v5 > v3->m_slabSize || v6 > v3->m_end )
    return (float *)hkLifoAllocator::allocateFromNewSlab(v3, v5);
  v3->m_cur = v6;
  return (float *)v4;
}

// File Line: 553
// RVA: 0xB45F10
void __fastcall allocateAndCopy_short_(const __int16 **dst, const __int16 *src, int num, int group)
{
  *dst = src;
}

// File Line: 570
// RVA: 0xB46170
void __fastcall deallocateFromStack_hkQsTransformf_(hkQsTransformf *p, int num)
{
  hkQsTransformf *v2; // rdi
  signed int v3; // ebx
  hkLifoAllocator *v4; // rax
  int v5; // er8

  v2 = p;
  v3 = (48 * ((num + 3) & 0xFFFFFFFC) + 127) & 0xFFFFFF80;
  v4 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (v3 + 15) & 0xFFFFFFF0;
  if ( v3 > v4->m_slabSize || (char *)v2 + v5 != v4->m_cur || v4->m_firstNonLifoEnd == v2 )
    hkLifoAllocator::slowBlockFree(v4, v2, v5);
  else
    v4->m_cur = v2;
}

// File Line: 582
// RVA: 0xB46220
void __fastcall deallocateACopy_hkaQuantizedSampleAndCombineJob::QuantizedAnimationEntry_(hkaQuantizedSampleAndCombineJob::QuantizedAnimationEntry *p, int num)
{
  ;
}

