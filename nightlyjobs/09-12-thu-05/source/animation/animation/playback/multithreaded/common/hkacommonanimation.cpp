// File Line: 46
// RVA: 0xB45330
void __fastcall executeQuantizedSampleAndCombineJob(hkaQuantizedSampleAndCombineJob *job)
{
  _QWORD *Value; // rdi
  unsigned __int64 v3; // rcx
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rsi
  int m_numBones; // edi
  int v7; // r9d
  int v8; // r9d
  int v9; // r9d
  int v10; // r9d
  int v11; // r10d
  int v12; // eax
  int v13; // r9d
  int v14; // r9d
  hkQsTransformf *v15; // rax
  int m_numFloats; // ecx
  hkQsTransformf *v17; // r15
  hkQsTransformf *bonesOut; // r13
  hkQsTransformf *v19; // rax
  int v20; // ecx
  float *boneWeightsOut; // r12
  __int64 v22; // rdi
  const float *v23; // r14
  hkQsTransformf *v24; // rax
  int v25; // ecx
  float *v26; // rax
  int v27; // ecx
  char *v28; // rax
  int v29; // ecx
  unsigned int v30; // eax
  int *v31; // r8
  __int64 v32; // r10
  char *v33; // r9
  int v34; // edx
  int v35; // edi
  int v36; // eax
  signed int v37; // eax
  float *v38; // rcx
  signed __int64 v39; // rdi
  __int64 v40; // rdx
  int v41; // eax
  float *v42; // rdi
  __int64 i; // rcx
  float *v44; // rdi
  __int64 j; // rcx
  unsigned int m_numAnimations; // eax
  int v47; // r15d
  float v48; // xmm7_4
  _QWORD *v49; // rax
  _QWORD *v50; // rcx
  _QWORD *v51; // rdi
  unsigned __int64 v52; // rax
  _QWORD *v53; // rcx
  int v54; // ecx
  __int64 v55; // r11
  int v56; // edi
  float **p_m_perBoneWeights; // r14
  __int64 v58; // rax
  int v59; // r9d
  int v60; // r8d
  __int64 v61; // rax
  int v62; // r9d
  int v63; // r10d
  __int64 v64; // rax
  int v65; // r9d
  char *v66; // rdi
  __m128 v67; // xmm1
  __m128 v68; // xmm0
  unsigned int v69; // edx
  __m128 v70; // xmm3
  __m128 v71; // xmm0
  __m128 v72; // xmm3
  int v73; // ecx
  float v74; // xmm4_4
  __m128 v75; // xmm0
  __m128 v76; // xmm3
  __m128 v77; // xmm1
  int v78; // ecx
  int v79; // r8d
  int v80; // edi
  __int64 v81; // r10
  int v82; // r8d
  int v83; // r9d
  _QWORD *v84; // rdi
  unsigned __int64 v85; // rcx
  unsigned __int64 v86; // rax
  __int64 v87; // r15
  _QWORD *v88; // rdi
  _QWORD *v89; // rcx
  unsigned __int64 v90; // rax
  _QWORD *v91; // rcx
  float v92; // xmm0_4
  signed int v93; // ecx
  __int64 v94; // r10
  unsigned __int64 *v95; // r8
  signed __int64 v96; // r9
  int v97; // edx
  int v98; // edi
  int v99; // eax
  signed int v100; // eax
  float *v101; // rcx
  __int64 v102; // rdx
  char *v103; // rdi
  int v104; // eax
  __int64 v105; // rcx
  float *v106; // rdi
  int v107; // eax
  float *v108; // r8
  const float *v109; // r15
  int v110; // eax
  int v111; // edi
  __m128 v112; // xmm6
  int v113; // eax
  unsigned int v114; // eax
  _QWORD *v115; // rax
  _QWORD *v116; // rcx
  _QWORD *v117; // rdi
  unsigned __int64 v118; // rax
  _QWORD *v119; // rcx
  hkQsTransformf *v120; // r15
  int v121; // r9d
  _QWORD *v122; // rdi
  _QWORD *v123; // rcx
  unsigned __int64 v124; // rax
  _QWORD *v125; // rcx
  const float *v126; // rcx
  _QWORD *v127; // rax
  _QWORD *v128; // rcx
  _QWORD *v129; // rdi
  unsigned __int64 v130; // rax
  _QWORD *v131; // rcx
  signed int referencePose; // [rsp+48h] [rbp-B8h]
  float useSlerp; // [rsp+80h] [rbp-80h]
  float *frameSteppingTolerance; // [rsp+88h] [rbp-78h]
  float *src; // [rsp+90h] [rbp-70h]
  float *weightsOut; // [rsp+98h] [rbp-68h]
  float *srcL; // [rsp+A0h] [rbp-60h]
  unsigned int n; // [rsp+A8h] [rbp-58h]
  __int64 v139; // [rsp+B0h] [rbp-50h]
  hkaQuantizedSampleAndCombineJob::QuantizedAnimationEntry *v140; // [rsp+B8h] [rbp-48h] BYREF
  hkQsTransformf *transformsInOut; // [rsp+C0h] [rbp-40h]
  int v142; // [rsp+C8h] [rbp-38h]
  __int16 *parentIndices; // [rsp+D0h] [rbp-30h] BYREF
  hkQsTransformf *transformsIn; // [rsp+D8h] [rbp-28h]
  hkQsTransformf *bonesScratch1; // [rsp+E0h] [rbp-20h]
  hkQsTransformf *floatsOut; // [rsp+E8h] [rbp-18h]
  hkQsTransformf *dst; // [rsp+F0h] [rbp-10h] BYREF
  unsigned int v148; // [rsp+F8h] [rbp-8h]
  __int16 *bonePairMap; // [rsp+100h] [rbp+0h] BYREF
  __int64 v150; // [rsp+108h] [rbp+8h]
  float *referenceFloats; // [rsp+110h] [rbp+10h] BYREF
  hkQuaternionf *invariants; // [rsp+118h] [rbp+18h] BYREF
  hkaSkeleton::Partition *partitions; // [rsp+120h] [rbp+20h] BYREF
  float *floatsScratch0[2]; // [rsp+128h] [rbp+28h]
  float v155[2]; // [rsp+138h] [rbp+38h]
  hkSimdFloat32 v156; // [rsp+150h] [rbp+50h] BYREF
  char *headerData[8]; // [rsp+160h] [rbp+60h] BYREF
  hkSimdFloat32 alphaIn; // [rsp+1A0h] [rbp+A0h] BYREF
  __int16 *partitionIndices[18]; // [rsp+1B0h] [rbp+B0h] BYREF
  int vars0; // [rsp+2C0h] [rbp+1C0h]
  void *retaddr; // [rsp+2C8h] [rbp+1C8h]
  int v162; // [rsp+2D0h] [rbp+1D0h]
  signed int v163; // [rsp+2D8h] [rbp+1D8h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v3 = Value[1];
  if ( v3 < Value[3] )
  {
    *(_QWORD *)v3 = "LthkaQuantizedSampleAndCombineJob";
    *(_QWORD *)(v3 + 16) = "StAllocateAndDMASkeleton";
    v4 = __rdtsc();
    *(_DWORD *)(v3 + 8) = v4;
    Value[1] = v3 + 24;
  }
  v5 = 0i64;
  m_numBones = 0;
  if ( job->m_parentIndices )
    m_numBones = job->m_numBones;
  LODWORD(retaddr) = 2;
  allocateAndCopy_hkQsTransformf_(&dst, job->m_referenceBones, job->m_numBones, 2, "Reference Bones");
  allocateAndCopy_float_(
    (const float **)&referenceFloats,
    job->m_referenceFloats,
    job->m_numFloats,
    v7,
    "Reference Floats");
  allocateAndCopy_short_((const __int16 **)&parentIndices, job->m_parentIndices, m_numBones, v8, "Parent Indices");
  allocateAndCopy_hkaQuantizedSampleAndCombineJob::QuantizedAnimationEntry_(
    &v140,
    job->m_animations,
    job->m_numAnimations,
    v9,
    "Entries");
  allocateAndCopy_short_((const __int16 **)&bonePairMap, job->m_mirroredBonePairMap, v11, v10, "Mirrored Bone Pairs");
  allocateAndCopy_hkQuaternionf_(&invariants, job->m_mirroredBoneInvariants, v12, v13, "Mirrored Bone Invariants");
  allocateAndCopy_hkaSkeleton::Partition_(
    &partitions,
    job->m_partitions,
    job->m_numPartitions,
    v14,
    "Skeleton Partitions");
  v15 = allocateFromStack_hkQsTransformf_(job->m_numBones, "AccumulatedBones");
  m_numFloats = job->m_numFloats;
  v17 = v15;
  transformsInOut = v15;
  src = allocateFromStack_float_(m_numFloats, "AccumulatedFloats");
  frameSteppingTolerance = allocateFromStack_float_(job->m_numBones, "AccumBoneWeights");
  weightsOut = allocateFromStack_float_(job->m_numFloats, "AccumFloatWeights");
  bonesOut = allocateFromStack_hkQsTransformf_(job->m_numBones, "SampledBones");
  v19 = (hkQsTransformf *)allocateFromStack_float_(job->m_numFloats, "SampledFloats");
  v20 = job->m_numBones;
  floatsOut = v19;
  boneWeightsOut = allocateFromStack_float_(v20, "SampledBoneWeights");
  v22 = 0i64;
  v23 = allocateFromStack_float_(job->m_numFloats, "SampledFloatWeights");
  srcL = (float *)v23;
  do
  {
    v24 = allocateFromStack_hkQsTransformf_(job->m_numBones, "ScratchBones");
    v25 = job->m_numFloats;
    *(hkQsTransformf **)((char *)&transformsIn + v22 * 8) = v24;
    v26 = allocateFromStack_float_(v25, "ScratchFloats");
    v27 = job->m_numBones;
    floatsScratch0[v22] = v26;
    v28 = (char *)allocateFromStack_float_(v27, "ScratchBoneWeights");
    v29 = job->m_numFloats;
    headerData[v22 + 3] = v28;
    headerData[++v22 + 4] = (char *)allocateFromStack_float_(v29, "ScratchFloatWeights");
  }
  while ( v22 < 2 );
  v30 = job->m_numBones;
  n = (v30 + 3) & 0xFFFFFFFC;
  v142 = (job->m_numFloats + 3) & 0xFFFFFFFC;
  if ( (int)(3 * v30) > 0 )
  {
    v31 = &v17->m_translation.m_quad.m128_i32[2];
    v32 = 3 * v30;
    v33 = (char *)((char *)dst - (char *)v17);
    do
    {
      v34 = *(int *)((char *)v31 + (_QWORD)v33);
      v35 = *(int *)((char *)v31 + (_QWORD)v33 + 4);
      v36 = *(int *)((char *)v31 + (_QWORD)v33 - 8);
      *(v31 - 1) = *(int *)((char *)v31 + (_QWORD)v33 - 4);
      *v31 = v34;
      v31[1] = v35;
      *(v31 - 2) = v36;
      v31 += 4;
      --v32;
    }
    while ( v32 );
  }
  v37 = job->m_numFloats;
  v38 = referenceFloats;
  if ( v37 > 0 )
  {
    v39 = (char *)src - (char *)referenceFloats;
    v40 = (unsigned int)v37;
    do
    {
      v41 = *(_DWORD *)v38++;
      *(_DWORD *)((char *)v38 + v39 - 4) = v41;
      --v40;
    }
    while ( v40 );
  }
  if ( (signed int)(job->m_numBones - 1) >= 0 )
  {
    v42 = frameSteppingTolerance;
    for ( i = job->m_numBones; i; --i )
      *v42++ = 0.0;
  }
  if ( (signed int)(job->m_numFloats - 1) >= 0 )
  {
    v44 = weightsOut;
    for ( j = job->m_numFloats; j; --j )
      *v44++ = 0.0;
  }
  m_numAnimations = job->m_numAnimations;
  vars0 = 1;
  v47 = 0;
  v162 = 0;
  v48 = 0.0;
  v163 = m_numAnimations;
  v49 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v50 = (_QWORD *)v49[1];
  v51 = v49;
  if ( (unsigned __int64)v50 < v49[3] )
  {
    *v50 = "StSampleAndBlendPipeline";
    v52 = __rdtsc();
    v53 = v50 + 2;
    *((_DWORD *)v53 - 2) = v52;
    v51[1] = v53;
  }
  v54 = v163;
  v55 = -2i64;
  v139 = -2i64;
  v150 = v163;
  if ( v163 > -2i64 )
  {
    v56 = -1;
    p_m_perBoneWeights = &v140->m_perBoneWeights;
    do
    {
      LODWORD(v140) = v56 + 1;
      if ( v56 + 1 >= 0 && v56 + 1 < v54 )
      {
        getFromMainMemory_unsigned_char_(
          (const char **)&headerData[v47],
          (const char *)*(p_m_perBoneWeights - 3),
          *((_DWORD *)p_m_perBoneWeights - 4),
          v47 + 7);
        if ( *p_m_perBoneWeights )
          v60 = job->m_numBones;
        else
          v60 = 0;
        getFromMainMemory_float_((const float **)&partitionIndices[v58 + 6], *p_m_perBoneWeights, v60, v59);
        getFromMainMemory_float_((const float **)&partitionIndices[v61 + 3], p_m_perBoneWeights[1], v63, v62);
        getFromMainMemory_short_(
          (const __int16 **)&partitionIndices[v64],
          (const __int16 *)p_m_perBoneWeights[2],
          *((__int16 *)p_m_perBoneWeights + 12),
          v65);
        v54 = v163;
      }
      if ( v56 >= 0 && v56 < v54 )
      {
        v148 = *((_DWORD *)p_m_perBoneWeights - 17);
        v66 = headerData[(int)retaddr];
        v67 = _mm_shuffle_ps((__m128)*((unsigned int *)v66 + 2), (__m128)*((unsigned int *)v66 + 2), 0);
        v68 = _mm_rcp_ps(v67);
        v69 = *((unsigned __int16 *)v66 + 3) - 2;
        v70 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v67, v68)), v68);
        v71 = 0i64;
        v71.m128_f32[0] = (float)(*((unsigned __int16 *)v66 + 3) - 1);
        v72 = _mm_mul_ps(v70, _mm_mul_ps(_mm_shuffle_ps(v71, v71, 0), _mm_shuffle_ps((__m128)v148, (__m128)v148, 0)));
        v73 = _mm_cvtsi128_si32(_mm_cvttps_epi32(v72));
        if ( v73 <= v69 )
        {
          v75 = 0i64;
          v75.m128_f32[0] = (float)v73;
          v69 = v73;
          v76 = _mm_sub_ps(v72, _mm_shuffle_ps(v75, v75, 0));
          v77 = _mm_cmplt_ps(v76, query.m_quad);
          v74 = fmax(
                  0.0,
                  COERCE_FLOAT(v76.m128_i32[0] & v77.m128_i32[0] | _mm_andnot_ps(v77, query.m_quad).m128_u32[0]));
        }
        else
        {
          v74 = *(float *)&FLOAT_1_0;
        }
        v78 = *(unsigned __int16 *)v66;
        v79 = *((unsigned __int16 *)v66 + 14);
        v155[(int)retaddr] = v74;
        v80 = v78 + v79 * (v69 + 1);
        getFromMainMemory_unsigned_char_(
          (const char **)&partitionIndices[2 * (int)retaddr + 9],
          (const char *)*(p_m_perBoneWeights - 10) + (int)(v78 + v69 * v79),
          v79,
          (_DWORD)retaddr + 10);
        getFromMainMemory_unsigned_char_(
          (const char **)((char *)&partitionIndices[10] + v81),
          (const char *)*(p_m_perBoneWeights - 10) + v80,
          v82,
          v83);
      }
      if ( v55 >= 0 && v55 < v150 )
      {
        v84 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v85 = v84[1];
        if ( v85 < v84[3] )
        {
          *(_QWORD *)v85 = "LtSampleAndBlend";
          *(_QWORD *)(v85 + 16) = "StSample";
          v86 = __rdtsc();
          *(_DWORD *)(v85 + 8) = v86;
          v84[1] = v85 + 24;
        }
        v87 = vars0;
        hkaQuantizedAnimation::sampleFullPose(
          headerData[vars0],
          (const char *)partitionIndices[2 * vars0 + 9],
          (const char *)partitionIndices[2 * vars0 + 10],
          job->m_numBones,
          job->m_numFloats,
          bonesOut,
          floatsOut->m_translation.m_quad.m128_f32,
          boneWeightsOut,
          srcL,
          dst,
          referenceFloats,
          transformsIn,
          bonesScratch1,
          floatsScratch0[0],
          floatsScratch0[1],
          v155[vars0],
          job->m_flags & 1,
          job->m_frameSteppingTolerance);
        v88 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v89 = (_QWORD *)v88[1];
        if ( (unsigned __int64)v89 < v88[3] )
        {
          *v89 = "StBlend";
          v90 = __rdtsc();
          v91 = v89 + 2;
          *((_DWORD *)v91 - 2) = v90;
          v88[1] = v91;
        }
        v92 = *((float *)p_m_perBoneWeights - 30);
        v48 = v48 + v92;
        if ( v48 == 0.0 )
          useSlerp = 0.0;
        else
          useSlerp = v92 / v48;
        if ( (*((_BYTE *)p_m_perBoneWeights - 84) & 8) != 0 )
        {
          v93 = 3 * job->m_numBones;
          if ( v93 > 0 )
          {
            v94 = (unsigned int)v93;
            v95 = &transformsIn->m_translation.m_quad.m128_u64[1];
            v96 = (char *)bonesOut - (char *)transformsIn;
            do
            {
              v97 = *(_DWORD *)((char *)v95 + v96);
              v98 = *(_DWORD *)((char *)v95 + v96 + 4);
              v99 = *(_DWORD *)((char *)v95 + v96 - 8);
              *((_DWORD *)v95 - 1) = *(_DWORD *)((char *)v95 + v96 - 4);
              *(_DWORD *)v95 = v97;
              *((_DWORD *)v95 + 1) = v98;
              *((_DWORD *)v95 - 2) = v99;
              v95 += 2;
              --v94;
            }
            while ( v94 );
          }
          v100 = job->m_numBones;
          v101 = boneWeightsOut;
          if ( v100 > 0 )
          {
            v102 = (unsigned int)v100;
            v103 = (char *)((char *)bonesScratch1 - (char *)boneWeightsOut);
            do
            {
              v104 = *(_DWORD *)v101++;
              *(_DWORD *)&v103[(_QWORD)v101 - 4] = v104;
              --v102;
            }
            while ( v102 );
          }
          hkaSampleAndCombineUtils::copyReferencePose(bonesOut, 0i64, dst, job->m_numBones, 0i64, 0);
          if ( (signed int)(job->m_numBones - 1) >= 0 )
          {
            v105 = job->m_numBones;
            v106 = boneWeightsOut;
            while ( v105 )
            {
              *v106++ = 0.0;
              --v105;
            }
          }
          hkaPartitionedAnimationUtility::mapPartitionPoseToFullPoseWithWeights(
            partitions,
            partitionIndices[v87],
            *((__int16 *)p_m_perBoneWeights - 44),
            transformsIn,
            bonesScratch1->m_translation.m_quad.m128_f32,
            job->m_numBones,
            bonesOut,
            boneWeightsOut);
        }
        v107 = *((_DWORD *)p_m_perBoneWeights - 21);
        if ( (v107 & 4) != 0 )
        {
          if ( (v107 & 1) != 0 || (v107 & 2) != 0 )
            hkaMirroredSkeleton::mirrorBonesAdditive(bonesOut, parentIndices, invariants, bonePairMap, job->m_numBones);
          else
            hkaMirroredSkeleton::mirrorBonesNormal(bonesOut, parentIndices, invariants, bonePairMap, job->m_numBones);
        }
        if ( *(p_m_perBoneWeights - 14) )
          hkaBlender::mul(boneWeightsOut, boneWeightsOut, (float *)partitionIndices[v87 + 6], n);
        if ( *(p_m_perBoneWeights - 13) )
        {
          v108 = (float *)partitionIndices[v87 + 3];
          v109 = srcL;
          hkaBlender::mul(srcL, srcL, v108, v142);
        }
        else
        {
          v109 = srcL;
        }
        v110 = *((_DWORD *)p_m_perBoneWeights - 21);
        if ( (v110 & 1) != 0 )
          v111 = 1;
        else
          v111 = -((v110 & 2) != 0);
        v112 = (__m128)LODWORD(useSlerp);
        referencePose = job->m_flags & 1;
        v113 = job->m_numBones;
        alphaIn.m_real = _mm_shuffle_ps(v112, v112, 0);
        hkaBlender::blend(
          transformsInOut,
          frameSteppingTolerance,
          transformsInOut,
          frameSteppingTolerance,
          bonesOut,
          boneWeightsOut,
          &alphaIn,
          v113,
          (hkaBlender::BLEND_MODE)v111,
          (hkaBlender::ROTATION_MODE)referencePose);
        v114 = job->m_numFloats;
        v156.m_real = _mm_shuffle_ps(v112, v112, 0);
        hkaBlender::blend(
          src,
          weightsOut,
          src,
          weightsOut,
          floatsOut->m_translation.m_quad.m128_f32,
          v109,
          &v156,
          v114,
          (hkaBlender::BLEND_MODE)v111);
        v115 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
        v55 = v139;
        v47 = v162;
        v116 = (_QWORD *)v115[1];
        v117 = v115;
        if ( (unsigned __int64)v116 < v115[3] )
        {
          *v116 = "lt";
          v118 = __rdtsc();
          v119 = v116 + 2;
          *((_DWORD *)v119 - 2) = v118;
          v117[1] = v119;
        }
      }
      v56 = (int)v140;
      ++v55;
      p_m_perBoneWeights += 7;
      v139 = v55;
      vars0 = (vars0 + 1) % 3;
      LODWORD(retaddr) = ((int)retaddr + 1) % 3;
      v54 = v163;
      v47 = (v47 + 1) % 3;
      v162 = v47;
    }
    while ( v55 < v150 );
    v23 = srcL;
  }
  v120 = transformsInOut;
  if ( (job->m_flags & 2) != 0 )
    hkaBlender::normalize(transformsInOut, job->m_numBones);
  if ( job->m_parentIndices )
    hkaBlender::modelFromLocal(v120, v120, parentIndices, job->m_numBones, &hkQsTransformf_identityStorage);
  putToMainMemory_hkQsTransformf_(job->m_bonesOut, v120, job->m_numBones, 3);
  putToMainMemory_float_(job->m_floatsOut, src, job->m_numFloats, v121);
  putToMainMemory_float_(job->m_boneWeightsOut, frameSteppingTolerance, job->m_numBones, 3);
  putToMainMemory_float_(job->m_floatWeightsOut, weightsOut, job->m_numFloats, 3);
  v122 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v123 = (_QWORD *)v122[1];
  if ( (unsigned __int64)v123 < v122[3] )
  {
    *v123 = "StDeallocate";
    v124 = __rdtsc();
    v125 = v123 + 2;
    *((_DWORD *)v125 - 2) = v124;
    v122[1] = v125;
  }
  do
  {
    v126 = (const float *)headerData[v5 / 2 + 6];
    v5 -= 2i64;
    deallocateFromStack_float_(v126, job->m_numFloats);
    deallocateFromStack_float_((const float *)headerData[v5 / 2 + 5], job->m_numBones);
    deallocateFromStack_float_(*(const float **)&v155[v5], job->m_numFloats);
    deallocateFromStack_hkQsTransformf_(*(hkQsTransformf **)((char *)&floatsOut + v5 * 4), job->m_numBones);
  }
  while ( v5 != 0x3FFFFFFFFFFFFFFCi64 );
  deallocateFromStack_float_(v23, job->m_numFloats);
  deallocateFromStack_float_(boneWeightsOut, job->m_numBones);
  deallocateFromStack_float_(floatsOut->m_translation.m_quad.m128_f32, job->m_numFloats);
  deallocateFromStack_hkQsTransformf_(bonesOut, job->m_numBones);
  deallocateFromStack_float_(weightsOut, job->m_numFloats);
  deallocateFromStack_float_(frameSteppingTolerance, job->m_numBones);
  deallocateFromStack_float_(src, job->m_numFloats);
  deallocateFromStack_hkQsTransformf_(v120, job->m_numBones);
  v127 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v128 = (_QWORD *)v127[1];
  v129 = v127;
  if ( (unsigned __int64)v128 < v127[3] )
  {
    *v128 = "lt";
    v130 = __rdtsc();
    v131 = v128 + 2;
    *((_DWORD *)v131 - 2) = v130;
    v129[1] = v131;
  }
}  v130 = __rdtsc();
    v131 = v128 + 2;
    *((_DWORD *)v131 - 2) = v130;
    v129[1] = v131;
  }
}

// File Line: 461
// RVA: 0xB46010
void __fastcall getFromMainMemory_unsigned_char_(const char **dst, const char *src, int num, int group)
{
  *dst = src;
  if ( src )
    _mm_prefetch(src, 0);
}

// File Line: 488
// RVA: 0xB45EE0
void __fastcall waitForDmaCompletion(int group)
{
  ;
}

// File Line: 498
// RVA: 0xB460C0
void __fastcall putToMainMemory_float_(float *dst, const float *src, int num, int group)
{
  if ( dst )
  {
    if ( num > 0 )
      memmove(dst, src, 4i64 * num);
  }
}

// File Line: 541
// RVA: 0xB45FB0
float *__fastcall allocateFromStack_float_(int num, const char *what)
{
  hkLifoAllocator *Value; // rax
  char *m_cur; // r8
  int v5; // edx
  char *v6; // rcx

  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)Value->m_cur;
  v5 = (4 * ((num + 3) & 0xFFFFFFFC) + 127) & 0xFFFFFF80;
  v6 = &m_cur[v5];
  if ( v5 > Value->m_slabSize || v6 > Value->m_end )
    return (float *)hkLifoAllocator::allocateFromNewSlab(Value, v5);
  Value->m_cur = v6;
  return (float *)m_cur;
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
  signed int v3; // ebx
  hkLifoAllocator *Value; // rax
  int v5; // r8d

  v3 = (48 * ((num + 3) & 0xFFFFFFFC) + 127) & 0xFFFFFF80;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (v3 + 15) & 0xFFFFFFF0;
  if ( v3 > Value->m_slabSize || (char *)p + v5 != Value->m_cur || Value->m_firstNonLifoEnd == p )
    hkLifoAllocator::slowBlockFree(Value, p, v5);
  else
    Value->m_cur = p;
}

// File Line: 582
// RVA: 0xB46220
void __fastcall deallocateACopy_hkaQuantizedSampleAndCombineJob::QuantizedAnimationEntry_(
        hkaQuantizedSampleAndCombineJob::QuantizedAnimationEntry *p,
        int num)
{
  ;
}

